#pragma once
#include <JuceHeader.h>

enum class WaveformType {
    Sine = 1,
    Square = 2,
    Sawtooth = 3,
    Triangle = 4
};

class BasicSynthSound : public juce::SynthesiserSound
{
public:
    BasicSynthSound() {}

    bool appliesToNote(int) override { return true; }
    bool appliesToChannel(int) override { return true; }
};

class BasicSynthVoice : public juce::SynthesiserVoice
{
public:
    BasicSynthVoice() {}

    bool canPlaySound(juce::SynthesiserSound* sound) override
    {
        return dynamic_cast<BasicSynthSound*>(sound) != nullptr;
    }

    void setWaveform(WaveformType newWaveform)
    {
        currentWaveform = newWaveform;
    }

    void startNote(int midiNoteNumber, float velocity,
                   juce::SynthesiserSound*, int /*currentPitchWheelPosition*/) override
    {
        currentAngle = 0.0;
        level = velocity * 0.15;
        tailOff = 0.0;

        auto cyclesPerSecond = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        auto cyclesPerSample = cyclesPerSecond / getSampleRate();

        angleDelta = cyclesPerSample * juce::MathConstants<double>::twoPi;
    }

    void stopNote(float /*velocity*/, bool allowTailOff) override
    {
        if (allowTailOff)
        {
            if (tailOff == 0.0)
                tailOff = 1.0;
        }
        else
        {
            clearCurrentNote();
            angleDelta = 0.0;
        }
    }

    void pitchWheelMoved(int) override {}
    void controllerMoved(int, int) override {}

    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer,
                         int startSample, int numSamples) override
    {
        if (angleDelta != 0.0)
        {
            while (--numSamples >= 0)
            {
                float currentSample = 0.0f;
                // Generate waveform
                switch (currentWaveform) {
                    case WaveformType::Sine:
                        currentSample = (float)std::sin(currentAngle);
                        break;
                    case WaveformType::Square:
                        currentSample = (currentAngle < juce::MathConstants<double>::pi) ? 0.8f : -0.8f;
                        break;
                    case WaveformType::Sawtooth:
                        currentSample = (float)(currentAngle / juce::MathConstants<double>::pi) - 1.0f;
                        break;
                    case WaveformType::Triangle:
                        currentSample = (float)(1.0f - std::abs((currentAngle / juce::MathConstants<double>::pi) - 1.0f) * 2.0f);
                        break;
                }
                
                // Attack / Decay (TailOff) Processing
                float amp = level;
                if (tailOff > 0.0) {
                    amp *= tailOff;
                    tailOff *= 0.99; // roughly equivalent to a fast fade
                    if (tailOff <= 0.005) {
                        clearCurrentNote();
                        angleDelta = 0.0;
                        break;
                    }
                }

                currentSample *= amp;

                for (auto i = outputBuffer.getNumChannels(); --i >= 0;)
                    outputBuffer.addSample(i, startSample, currentSample);

                currentAngle += angleDelta;
                if (currentAngle >= juce::MathConstants<double>::twoPi) {
                    currentAngle -= juce::MathConstants<double>::twoPi;
                }
                
                ++startSample;
            }
        }
    }

private:
    double currentAngle = 0.0, angleDelta = 0.0, level = 0.0, tailOff = 0.0;
    WaveformType currentWaveform = WaveformType::Sine;
};
