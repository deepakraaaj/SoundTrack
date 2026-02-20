cmake_minimum_required(VERSION 3.20)
project(SoundCraftStudio VERSION 1.0.0)

# Fetch JUCE automatically so no local installation is required
include(FetchContent)
FetchContent_Declare(
    juce
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG        8.0.0
)
FetchContent_MakeAvailable(juce)

# Fetch nlohmann_json for purely local, header-only JSON parsing
FetchContent_Declare(json
  URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

# Create the GUI executable
juce_add_gui_app(SoundCraftStudio
    PRODUCT_NAME "SoundCraft Studio"
    VERSION 1.0.0
)

# Generate the JuceHeader.h file
juce_generate_juce_header(SoundCraftStudio)

# Add source files
target_sources(SoundCraftStudio PRIVATE
    Source/Application/Main.cpp
    Source/Application/MainComponent.cpp
    Source/Application/MainComponent.h
    Source/Engines/DataStructures.h
    Source/Engines/Harmony.h
    Source/Engines/Harmony.cpp
    Source/Engines/Rhythm.h
    Source/Engines/Rhythm.cpp
    Source/Engines/Theory.h
    Source/Engines/Theory.cpp
    Source/Engines/Analyzer.h
    Source/Engines/Analyzer.cpp
    Source/Engines/Arrangement.h
    Source/Engines/Arrangement.cpp
    Source/Engines/LearningOrchestrator.h
    Source/Engines/LearningOrchestrator.cpp
    Source/Engines/InstrumentEngine.h
    Source/UI/Views/Instrument/InstrumentView.cpp
    Source/UI/Views/Instrument/InstrumentView.h
    Source/UI/Views/Instrument/MusiccaKeyboardComponent.h
    Source/UI/Views/Instrument/MusiccaKeyboardComponent.cpp
    Source/UI/Views/Mastery/MasteryView.cpp
    Source/UI/Views/Mastery/MasteryView.h
    Source/UI/Views/Composition/CompositionView.cpp
    Source/UI/Views/Composition/CompositionView.h
    Source/UI/Views/Import/ImportView.cpp
    Source/UI/Views/Import/ImportView.h
)

# Add compiler flags and disable juce web browser to bypass webkit/gtk issues on linux
target_compile_definitions(SoundCraftStudio PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)
target_compile_features(SoundCraftStudio PRIVATE cxx_std_20)

# Link against JUCE modules needed for UI and audio
target_link_libraries(SoundCraftStudio PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_devices
    juce::juce_audio_formats
    juce::juce_audio_processors
    juce::juce_gui_extra
    juce::juce_gui_basics
    juce::juce_graphics
    juce::juce_events
    juce::juce_core
    juce::juce_data_structures
    nlohmann_json::nlohmann_json
)
