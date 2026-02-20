# SoundCraft Studio (C++ Core)

SoundCraft Studio is a music theory intelligence, mastery, and arrangement engine built natively in C++ using the **JUCE Framework**. 

This `master` branch contains the heavyweight standalone Desktop C++ Architecture. It features decoupled internal engines (`HarmonyEngine`, `RhythmEngine`, `TheoryEngine`, `AnalyzerEngine`, `ArrangementEngine`) managed by a central `LearningOrchestrator` State Manager, which drives purely native JUCE UI `Component` views, including a custom multi-waveform `juce::Synthesiser` and a fully interactive Piano layout derived directly from the application's C++ DSP graph.

## 🚀 Native Compilation & Installation

Because this application relies on low-level Audio DSP processors via JUCE, it must be compiled locally on your machine using CMake. 

### 1. Prerequisites (Linux / Ubuntu)

You will need modern CMake (3.20+) and standard C++ compilation toolchains. Additionally, the JUCE GUI and Audio frameworks require native Linux windowing and soundcar headers.

Run the following command to install all necessary dependencies:
```bash
sudo apt update
sudo apt install build-essential cmake pkg-config \
                 libfreetype6-dev libx11-dev libasound2-dev libcurl4-openssl-dev \
                 libfontconfig1-dev libwebkit2gtk-4.1-dev libgtk-3-dev
```

*(Note: On macOS and Windows, standard XCode / Visual Studio installations cover these requirements automatically).*

### 2. Fetching & Building

The `CMakeLists.txt` is configured via `FetchContent` to automatically download the entire JUCE 8.0 Framework and `nlohmann_json` (for ChatGPT payload parsing) straight from GitHub. You do **not** need a separate local Projucer installation.

Clone the repository and build:

```bash
# Clone the Repository
git clone https://github.com/Username/SoundCraftStudio.git
cd SoundCraftStudio

# Generate Build headers
cmake -B build

# Compile the Binary using 4 CPU cores (This will take a few minutes as JUCE compiles)
cmake --build build -j 4
```

### 3. Running the Application

Once compilation is complete, the executable will be located in your `build/` directory under standard JUCE Artefacts.

Launch the graphical interface:
```bash
./build/SoundCraftStudio_artefacts/SoundCraft\ Studio
```

---

## 🎵 Features Overview

- **Instrument Engine**: Embedded Sine, Square, Sawtooth, and Triangle wave synthesisers mapped to an interactive `MusiccaKeyboardComponent`.
- **JSON Payload Import**: Direct ChatGPT/AI prompt processing. Feed the system song metadata and it mathematically tracks and renders progression motifs.
- **Mastery & Composition Views**: Scalable tabs designed to act as future UI interfaces mapped to the `LearningOrchestrator`.

*(Note: This repository serves as the initial low-level C++ Architecture. A lightweight, client-side Web Application version is maintained on a separate branch for instantaneous browser portfolio demos).*
