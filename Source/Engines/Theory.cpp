#include "Theory.h"

TheoryEngine::TheoryEngine()
{
}

TheoryEngine::~TheoryEngine()
{
}

juce::String TheoryEngine::getChordExplanation(const std::string& chordName, const std::string& localKey)
{
    // E.g., If chordName == "G7" and localKey == "C Major", return "Dominant 7th pulling to tonic"
    return "This chord serves a specific function in your current key.";
}

juce::String TheoryEngine::getTensionResolutionExplanation(const std::string& tensionType)
{
    if (tensionType == "High") {
        return "This harmony creates a strong dissonance expecting a resolution.";
    }
    return "A stable anchor point.";
}
