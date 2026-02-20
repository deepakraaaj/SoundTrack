#pragma once
#include <JuceHeader.h>
#include "../../../Engines/LearningOrchestrator.h"

class CompositionView  : public juce::Component
{
public:
    CompositionView(LearningOrchestrator& orchestrator);
    ~CompositionView() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    LearningOrchestrator& orchestrator;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CompositionView)
};
