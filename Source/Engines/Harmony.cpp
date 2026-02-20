#include "Harmony.h"

HarmonyEngine::HarmonyEngine()
{
    // Define intervals relative to a root (0)
    scaleIntervalsTemplate["Major"] = {0, 2, 4, 5, 7, 9, 11};
    scaleIntervalsTemplate["Minor"] = {0, 2, 3, 5, 7, 8, 10};
    
    chordIntervalsTemplate["Major"] = {0, 4, 7};
    chordIntervalsTemplate["Minor"] = {0, 3, 7};
    chordIntervalsTemplate["Diminished"] = {0, 3, 6};
    chordIntervalsTemplate["Dominant7"] = {0, 4, 7, 10};
    chordIntervalsTemplate["Major7"] = {0, 4, 7, 11};
    chordIntervalsTemplate["Minor7"] = {0, 3, 7, 10};
}

HarmonyEngine::~HarmonyEngine()
{
}

std::vector<int> HarmonyEngine::getScaleNotes(const std::string& keyName) const
{
    // Placeholder logic for extracting "C" and "Major" from "C Major"
    return {};
}

std::vector<int> HarmonyEngine::buildChord(const std::string& rootNote, const std::string& chordType) const
{
    return {};
}

std::string HarmonyEngine::analyzeTension(const Chord& previous, const Chord& current) const
{
    return "Stable";
}
