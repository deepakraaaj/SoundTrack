#pragma once
#include <JuceHeader.h>
#include "DataStructures.h"

class RhythmEngine
{
public:
    RhythmEngine();
    ~RhythmEngine();

    // Pure logic
    float getBeatStrength(int tickPosition, TimeSignature signature) const;
    juce::MidiMessageSequence generateGrooveTemplate(const std::string& genreStyle);

private:
};
