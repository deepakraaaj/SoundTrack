#pragma once
#include <JuceHeader.h>
#include <vector>
#include <string>
#include <map>

// Represents a musical chord in the system
struct Chord {
    std::string name;
    std::vector<int> midiNotes;
};

// Represents a basic Time Signature
struct TimeSignature {
    int numerator{4};
    int denominator{4};
};

// Represents the summary of a pattern found by the Analyzer
struct PatternSummary {
    int loopStartTicks;
    int loopLengthTicks;
    std::string tensionProfile;
};

// Represents a complete Song payload (Target format for ChatGPT to generate)
struct Song {
    std::string id;
    std::string name;
    std::string key;
    double tempo;
    std::vector<Chord> chordProgression;
    juce::MidiMessageSequence melodyTrack;
    juce::MidiMessageSequence drumTrack;
    std::map<std::string, PatternSummary> repetitionMap;
};

// Represents the composition parameters
struct CompositionProject {
    std::string id;
    std::string emotion; // Maps to theory engine
    std::string scale;
    std::vector<Chord> chordStructure;
    juce::MidiMessageSequence melodyNotes;
    juce::MidiMessageSequence drumPattern;
    // Arrangement metadata...
};
