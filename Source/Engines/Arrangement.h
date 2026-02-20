#pragma once
#include <JuceHeader.h>
#include "DataStructures.h"

class ArrangementEngine
{
public:
    ArrangementEngine();
    ~ArrangementEngine();

    // Composing from scratch logic
    void buildSection(CompositionProject& project, const std::string& sectionType);
    void applyEnergyCurve(CompositionProject& project, float intensity);

private:
};
