#include "Analyzer.h"

AnalyzerEngine::AnalyzerEngine()
{
}

AnalyzerEngine::~AnalyzerEngine()
{
}

void AnalyzerEngine::simplifyProgression(std::vector<Chord>& progression) const
{
    // E.g., strips 7ths and 9ths, returning only triad roots for "Attempt 1" learning.
}

void AnalyzerEngine::mapGroove(juce::MidiMessageSequence& sequence) const
{
}

std::string AnalyzerEngine::extractPatternContour(const juce::MidiMessageSequence& sequence) const
{
    return "AABA";
}
