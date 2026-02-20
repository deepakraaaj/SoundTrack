#pragma once
#include <JuceHeader.h>

#include "../UI/Views/Instrument/InstrumentView.h"
#include "../UI/Views/Mastery/MasteryView.h"
#include "../UI/Views/Composition/CompositionView.h"
#include "../UI/Views/Import/ImportView.h"
#include "../Engines/InstrumentEngine.h"

class MainComponent  : public juce::AudioAppComponent
{
public:
    MainComponent();
    ~MainComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

private:
    juce::TabbedComponent tabs;
    
    LearningOrchestrator orchestrator;

    InstrumentView instrumentView;
    MasteryView masteryView;
    CompositionView compositionView;
    ImportView importView;

    juce::Synthesiser synth;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
