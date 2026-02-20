#include "InstrumentView.h"

InstrumentView::InstrumentView(LearningOrchestrator& orch) : orchestrator(orch),
    keyboardComponent(keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard)
{
    addAndMakeVisible(keyboardComponent);
    keyboardComponent.setAvailableRange(36, 96);
    keyboardComponent.setKeyWidth(48.0f); // Wider keys closely resembling musicca

    // Instrument selector dropdown setup
    instrumentSelector.addItem("Sine Wave", 1);
    instrumentSelector.addItem("Square Wave", 2);
    instrumentSelector.addItem("Sawtooth Wave", 3);
    instrumentSelector.addItem("Triangle Wave", 4);
    instrumentSelector.setSelectedId(1);
    instrumentSelector.onChange = [this] { if (onInstrumentChanged) onInstrumentChanged(instrumentSelector.getSelectedId()); };
    addAndMakeVisible(instrumentSelector);
}

InstrumentView::~InstrumentView()
{
}

void InstrumentView::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(0xff151515));

    g.setColour (juce::Colours::white);
    g.setFont (24.0f);
    
    juce::String title = "Instrument Layer: Piano";
    if (orchestrator.hasLoadedSong()) {
        title = "Loaded: " + orchestrator.getCurrentSong().name;
        g.setColour(juce::Colours::lightgreen);
    }
    
    g.drawText (title, getLocalBounds().removeFromTop(100), juce::Justification::centred, true);
}

void InstrumentView::resized()
{
    auto area = getLocalBounds().reduced(20);
    instrumentSelector.setBounds(area.removeFromTop(30).withWidth(200).withX(area.getWidth() / 2 - 100));
    
    keyboardComponent.setBounds(getLocalBounds().removeFromBottom(200).reduced(20));
}
