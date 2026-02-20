#pragma once
#include <JuceHeader.h>
#include <string>

class TheoryEngine
{
public:
    TheoryEngine();
    ~TheoryEngine();

    // The explanatory text generator
    juce::String getChordExplanation(const std::string& chordName, const std::string& localKey);
    juce::String getTensionResolutionExplanation(const std::string& tensionType);

private:
};
