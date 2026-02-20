#pragma once
#include <JuceHeader.h>
#include "DataStructures.h"
#include "Analyzer.h"
#include "Harmony.h"
#include "Rhythm.h"
#include "Theory.h"
#include "Arrangement.h"

// The Global State Manager resolving the dependency tree
class LearningOrchestrator
{
public:
    LearningOrchestrator();
    ~LearningOrchestrator();

    void loadSong(const Song& newSong);
    const Song& getCurrentSong() const;
    bool hasLoadedSong() const;

    // Direct access to core engines
    AnalyzerEngine analyzer;
    HarmonyEngine harmony;
    RhythmEngine rhythm;
    TheoryEngine theory;
    ArrangementEngine arrangement;

private:
    Song currentSong;
    bool bHasSong{false};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LearningOrchestrator)
};
