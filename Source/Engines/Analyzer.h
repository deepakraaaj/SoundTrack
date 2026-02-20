#pragma once
#include <JuceHeader.h>
#include "DataStructures.h"

class AnalyzerEngine
{
public:
    AnalyzerEngine();
    ~AnalyzerEngine();

    // 2-Attempt logic: Breaks down complexity
    void simplifyProgression(std::vector<Chord>& progression) const;
    void mapGroove(juce::MidiMessageSequence& sequence) const;
    std::string extractPatternContour(const juce::MidiMessageSequence& sequence) const;

private:
};
