#pragma once
#include <JuceHeader.h>

class MusiccaKeyboardComponent : public juce::MidiKeyboardComponent
{
public:
    MusiccaKeyboardComponent(juce::MidiKeyboardState& state, juce::MidiKeyboardComponent::Orientation orientation);
    ~MusiccaKeyboardComponent() override;

    void drawWhiteNote (int midiNoteNumber, juce::Graphics& g, juce::Rectangle<float> area,
                        bool isDown, bool isOver, juce::Colour lineColour, juce::Colour textColour) override;

    void drawBlackNote (int midiNoteNumber, juce::Graphics& g, juce::Rectangle<float> area,
                        bool isDown, bool isOver, juce::Colour noteFillColour) override;

private:
    juce::String getNoteName(int midiNoteNumber);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MusiccaKeyboardComponent)
};
