#pragma once
#include <JuceHeader.h>
#include "../../../Engines/LearningOrchestrator.h"
#include "MusiccaKeyboardComponent.h"

class InstrumentView  : public juce::Component
{
public:
    InstrumentView(LearningOrchestrator& orchestrator);
    ~InstrumentView() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    juce::MidiKeyboardState& getKeyboardState() { return keyboardState; }
    
    std::function<void(int)> onInstrumentChanged;

private:
    LearningOrchestrator& orchestrator;

    juce::ComboBox instrumentSelector;

    juce::MidiKeyboardState keyboardState;
    MusiccaKeyboardComponent keyboardComponent;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InstrumentView)
};
