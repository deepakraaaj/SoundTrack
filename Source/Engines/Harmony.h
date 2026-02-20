#pragma once
#include <JuceHeader.h>
#include "DataStructures.h"

class HarmonyEngine
{
public:
    HarmonyEngine();
    ~HarmonyEngine();

    // Pure math logic functions
    std::vector<int> getScaleNotes(const std::string& keyName) const;
    std::vector<int> buildChord(const std::string& rootNote, const std::string& chordType) const;
    std::string analyzeTension(const Chord& previous, const Chord& current) const;

private:
    std::map<std::string, std::vector<int>> scaleIntervalsTemplate;
    std::map<std::string, std::vector<int>> chordIntervalsTemplate;
};
