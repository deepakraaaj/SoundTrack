#include "LearningOrchestrator.h"

LearningOrchestrator::LearningOrchestrator()
{
}

LearningOrchestrator::~LearningOrchestrator()
{
}

void LearningOrchestrator::loadSong(const Song& newSong)
{
    currentSong = newSong;
    bHasSong = true;
    
    // Automatically trigger initial analysis
    analyzer.simplifyProgression(currentSong.chordProgression);
    // Further pre-computations can happen here safely off the audio thread.
}

const Song& LearningOrchestrator::getCurrentSong() const
{
    return currentSong;
}

bool LearningOrchestrator::hasLoadedSong() const
{
    return bHasSong;
}
