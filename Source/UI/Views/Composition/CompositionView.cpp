#include "CompositionView.h"

CompositionView::CompositionView(LearningOrchestrator& orch) : orchestrator(orch)
{
}

CompositionView::~CompositionView()
{
}

void CompositionView::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(0xff1f1221)); // Purple tinted dark

    g.setFont (24.0f);
    g.setColour (juce::Colour(0xffce93d8)); 
    g.drawText ("Composition Studio", getLocalBounds().withSizeKeepingCentre(400, 50).translated(0, -50), juce::Justification::centred, true);

    g.setFont (16.0f);
    g.setColour (juce::Colours::grey);
    g.drawText ("Arrangement Engine Logic Goes Here", getLocalBounds().withSizeKeepingCentre(400, 50).translated(0, 0), juce::Justification::centred, true);
}

void CompositionView::resized()
{
}
