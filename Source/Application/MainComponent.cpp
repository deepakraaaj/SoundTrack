#include <JuceHeader.h>
#include <nlohmann/json.hpp>
#include "MainComponent.h"

using json = nlohmann::json;

MainComponent::MainComponent()
    : tabs(juce::TabbedButtonBar::Orientation::TabsAtTop),
      instrumentView(orchestrator),
      masteryView(orchestrator),
      compositionView(orchestrator),
      importView(orchestrator)
{
    setSize (1024, 768);

    // Initialise UI tabs
    tabs.addTab("Instrument", juce::Colours::transparentBlack, &instrumentView, false);
    tabs.addTab("Mastery", juce::Colours::transparentBlack, &masteryView, false);
    tabs.addTab("Composition", juce::Colours::transparentBlack, &compositionView, false);
    tabs.addTab("Import", juce::Colours::transparentBlack, &importView, false);

    addAndMakeVisible(tabs);

    // Initialise audio engine
    for (int i = 0; i < 4; ++i)
        synth.addVoice (new BasicSynthVoice());
        
    synth.addSound (new BasicSynthSound());

    instrumentView.onInstrumentChanged = [this](int newlySelectedId) {
        for (int i = 0; i < synth.getNumVoices(); ++i) {
            if (auto* voice = dynamic_cast<BasicSynthVoice*>(synth.getVoice(i))) {
                voice->setWaveform(static_cast<WaveformType>(newlySelectedId));
            }
        }
    };

    // Some platforms require permissions to open input channels so don't ask for them if not needed
    setAudioChannels (0, 2);

    // Test JSON parsing for our ChatGPT format
    try {
        const char* jsonString = "{\"name\": \"Beethoven's 5th Symphony (Motif)\",\"key\": \"C Minor\",\"tempo\": 108,\"chordProgression\": [ {\"name\": \"Cm\", \"midiNotes\": [48, 51, 55]} ],\"melodyTrack\": [ {\"note\": 55, \"startTicks\": 0, \"durationTicks\": 120} ]}";
        auto dummyJson = json::parse(jsonString);
        
        juce::Logger::writeToLog("JSON Parsed Successfully. Song: " + std::string(dummyJson["name"]));
    } catch (...) {
        juce::Logger::writeToLog("JSON Parsing Failed.");
    }
}

MainComponent::~MainComponent()
{
    shutdownAudio();
}

void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    synth.setCurrentPlaybackSampleRate (sampleRate);
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();

    juce::MidiBuffer incomingMidi;
    instrumentView.getKeyboardState().processNextMidiBuffer (incomingMidi, bufferToFill.startSample,
                                                             bufferToFill.numSamples, true);

    synth.renderNextBlock (*bufferToFill.buffer, incomingMidi,
                           bufferToFill.startSample, bufferToFill.numSamples);
}

void MainComponent::releaseResources()
{
}

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(0xff121212)); // Premium dark background
}

void MainComponent::resized()
{
    tabs.setBounds(getLocalBounds());
}
