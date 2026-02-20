#include "MusiccaKeyboardComponent.h"

MusiccaKeyboardComponent::MusiccaKeyboardComponent(juce::MidiKeyboardState& state, juce::MidiKeyboardComponent::Orientation orientation)
    : juce::MidiKeyboardComponent(state, orientation)
{
}

MusiccaKeyboardComponent::~MusiccaKeyboardComponent()
{
}

juce::String MusiccaKeyboardComponent::getNoteName(int midiNoteNumber)
{
    static const char* noteNames[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
    return juce::String(noteNames[midiNoteNumber % 12]);
}

void MusiccaKeyboardComponent::drawWhiteNote (int midiNoteNumber, juce::Graphics& g, juce::Rectangle<float> area,
                                             bool isDown, bool isOver, juce::Colour /*lineColour*/, juce::Colour /*textColour*/)
{
    auto baseColour = juce::Colours::white;
    if (isDown)  baseColour = juce::Colour(0xffe0e0e0); // Light grey when pressed
    else if (isOver) baseColour = juce::Colour(0xfff5f5f5); // Very light grey when hovered

    g.setColour(baseColour);
    g.fillRoundedRectangle(area.reduced(1.0f, 0.0f).withTrimmedBottom(2.0f), 4.0f);

    // Draw bottom border to simulate 3D depth
    if (!isDown) {
        g.setColour(juce::Colour(0xffcccccc));
        g.fillRect(area.getX() + 1.0f, area.getBottom() - 4.0f, area.getWidth() - 2.0f, 4.0f);
    }

    // Draw Note Name
    g.setColour(juce::Colour(0xff666666));
    g.setFont(juce::FontOptions(14.0f).withStyle("bold"));
    g.drawText(getNoteName(midiNoteNumber), area.withTrimmedBottom(10.0f).withHeight(20.0f).withY(area.getBottom() - 30.0f), juce::Justification::centredBottom, false);
}

void MusiccaKeyboardComponent::drawBlackNote (int midiNoteNumber, juce::Graphics& g, juce::Rectangle<float> area,
                                             bool isDown, bool isOver, juce::Colour /*noteFillColour*/)
{
    auto baseColour = juce::Colour(0xff222222); // Dark grey/black
    if (isDown)  baseColour = juce::Colour(0xff444444); // Lighter grey when pressed
    else if (isOver) baseColour = juce::Colour(0xff333333); 

    g.setColour(baseColour);
    g.fillRoundedRectangle(area.reduced(2.0f, 0.0f).withTrimmedBottom(4.0f), 4.0f);

    // Draw Note Name
    if (!getNoteName(midiNoteNumber).contains("#")) return; // Just in case

    g.setColour(juce::Colour(0xffaaaaaa));
    g.setFont(juce::FontOptions(12.0f));
    g.drawText(getNoteName(midiNoteNumber), area.withTrimmedBottom(10.0f).withHeight(20.0f).withY(area.getBottom() - 30.0f), juce::Justification::centredBottom, false);
}
