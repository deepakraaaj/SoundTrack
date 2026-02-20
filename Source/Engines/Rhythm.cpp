#include "Rhythm.h"

RhythmEngine::RhythmEngine()
{
}

RhythmEngine::~RhythmEngine()
{
}

float RhythmEngine::getBeatStrength(int tickPosition, TimeSignature signature) const
{
    // A placeholder that will eventually do modulo math to determine downbeat strength vs offbeat syncopation.
    return 1.0f;
}

juce::MidiMessageSequence RhythmEngine::generateGrooveTemplate(const std::string& genreStyle)
{
    juce::MidiMessageSequence seq;
    return seq;
}
