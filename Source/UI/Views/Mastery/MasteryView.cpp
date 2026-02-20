#include "MasteryView.h"

MasteryView::MasteryView(LearningOrchestrator& orch) : orchestrator(orch)
{
}

MasteryView::~MasteryView()
{
}

void MasteryView::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(0xff121921));

    g.setFont (24.0f);
    g.setColour (juce::Colour(0xff8bc34a)); // Accent colour
    g.drawText ("Song Mastery: X-Ray Mode", getLocalBounds().withSizeKeepingCentre(400, 50).translated(0, -50), juce::Justification::centred, true);

    g.setFont (16.0f);
    g.setColour (juce::Colours::grey);
    g.drawText ("Pattern Analyzer Logic Goes Here", getLocalBounds().withSizeKeepingCentre(400, 50).translated(0, 0), juce::Justification::centred, true);
}

void MasteryView::resized()
{
}
