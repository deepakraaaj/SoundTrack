#pragma once
#include <JuceHeader.h>
#include "../../../Engines/LearningOrchestrator.h"

class MasteryView  : public juce::Component
{
public:
    MasteryView(LearningOrchestrator& orchestrator);
    ~MasteryView() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    LearningOrchestrator& orchestrator;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasteryView)
};
