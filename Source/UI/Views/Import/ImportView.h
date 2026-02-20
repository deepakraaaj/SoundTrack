#pragma once
#include <JuceHeader.h>
#include "../../../Engines/LearningOrchestrator.h"

class ImportView  : public juce::Component
{
public:
    ImportView(LearningOrchestrator& orchestrator);
    ~ImportView() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    LearningOrchestrator& orchestrator;

    juce::TextEditor jsonEditor;
    juce::TextButton copyPromptButton;
    juce::TextButton loadJsonButton;
    juce::Label instructionsLabel;

    juce::TextButton loadDemo1Button;
    juce::TextButton loadDemo2Button;
    
    void copyPromptToClipboard();
    void parseJsonInput();
    void loadDemoFile(const juce::String& filePath);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ImportView)
};
