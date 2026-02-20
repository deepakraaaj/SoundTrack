#include "ImportView.h"
#include <nlohmann/json.hpp>

ImportView::ImportView(LearningOrchestrator& orch) : orchestrator(orch)
{
    instructionsLabel.setText ("1. Click 'Copy Prompt' to get the AI template.\n2. Ask ChatGPT or Claude to generate the song.\n3. Paste the returned JSON below and click 'Load'.", juce::dontSendNotification);
    instructionsLabel.setColour(juce::Label::textColourId, juce::Colours::lightgrey);
    addAndMakeVisible (instructionsLabel);

    copyPromptButton.setButtonText ("Copy ChatGPT Prompt");
    copyPromptButton.onClick = [this] { copyPromptToClipboard(); };
    addAndMakeVisible (copyPromptButton);

    jsonEditor.setMultiLine (true);
    jsonEditor.setReturnKeyStartsNewLine (true);
    jsonEditor.setColour(juce::TextEditor::backgroundColourId, juce::Colour(0xff222222));
    jsonEditor.setColour(juce::TextEditor::textColourId, juce::Colours::white);
    addAndMakeVisible (jsonEditor);

    loadJsonButton.setButtonText ("Load JSON");
    loadJsonButton.onClick = [this] { parseJsonInput(); };
    addAndMakeVisible (loadJsonButton);

    loadDemo1Button.setButtonText ("Load Demo: Beethoven");
    loadDemo1Button.onClick = [this] { loadDemoFile("/home/deepakrajb/Desktop/SoundTrack/Demos/Beethoven5.json"); };
    addAndMakeVisible (loadDemo1Button);

    loadDemo2Button.setButtonText ("Load Demo: Kathal Enum");
    loadDemo2Button.onClick = [this] { loadDemoFile("/home/deepakrajb/Desktop/SoundTrack/Demos/KathalEnum.json"); };
    addAndMakeVisible (loadDemo2Button);
}

ImportView::~ImportView()
{
}

void ImportView::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(0xff181818));
}

void ImportView::resized()
{
    auto area = getLocalBounds().reduced(20);
    instructionsLabel.setBounds(area.removeFromTop(60));
    area.removeFromTop(10);
    copyPromptButton.setBounds(area.removeFromTop(40).withWidth(200));
    area.removeFromTop(20);
    auto bottomArea = area.removeFromBottom(40);
    loadJsonButton.setBounds(bottomArea.removeFromLeft(150));
    bottomArea.removeFromLeft(10);
    loadDemo1Button.setBounds(bottomArea.removeFromLeft(200));
    bottomArea.removeFromLeft(10);
    loadDemo2Button.setBounds(bottomArea.removeFromLeft(200));
    
    area.removeFromBottom(10);
    jsonEditor.setBounds(area);
}

void ImportView::copyPromptToClipboard()
{
    juce::String prompt = 
        "Act as a music theory engine. I want to practice Beethoven's 5th Symphony or Kathal Enum Therveludhi. "
        "Please provide the MIDI structure of the main section of this song in the exact JSON format below. Return ONLY the raw JSON, no markdown formatting.\n\n"
        "{\n"
        "  \"name\": \"Beethoven's 5th Symphony (Motif)\",\n"
        "  \"key\": \"C Minor\",\n"
        "  \"tempo\": 108,\n"
        "  \"chordProgression\": [ {\"name\": \"Cm\", \"midiNotes\": [48, 51, 55]} ],\n"
        "  \"melodyTrack\": [ {\"note\": 55, \"startTicks\": 0, \"durationTicks\": 120} ]\n"
        "}\n";
    juce::SystemClipboard::copyTextToClipboard(prompt);
}

void ImportView::parseJsonInput()
{
    juce::String input = jsonEditor.getText();
    juce::Logger::writeToLog("parseJsonInput called. Input length: " + juce::String(input.length()));

    if (input.isEmpty()) {
        juce::Logger::writeToLog("Input was empty.");
        return;
    }

    try {
        auto parsedData = nlohmann::json::parse(input.toStdString());
        
        // Map to global Song Data Structure
        Song newSong;
        newSong.name = parsedData["name"].get<std::string>();
        newSong.key = parsedData["key"].get<std::string>();
        // Using get<double> on an integer can sometimes be strict in nlohmann, switching to get<float> or letting it coerce.
        if (parsedData["tempo"].is_number()) {
            newSong.tempo = parsedData["tempo"].get<double>();
        }
        
        // Load the parsed map into the Global Orchestrator State Manager
        orchestrator.loadSong(newSong);

        juce::Logger::writeToLog("JSON parsed successfully. Name: " + newSong.name);
        instructionsLabel.setText("Success! Loaded: " + juce::String(newSong.name), juce::dontSendNotification);
        instructionsLabel.setColour(juce::Label::textColourId, juce::Colours::lightgreen);
    } catch (const std::exception& e) {
        juce::Logger::writeToLog("JSON error: " + juce::String(e.what()));
        instructionsLabel.setText("Error: " + juce::String(e.what()), juce::dontSendNotification);
        instructionsLabel.setColour(juce::Label::textColourId, juce::Colours::red);
    } catch (...) {
        juce::Logger::writeToLog("Unknown error in JSON parsing.");
        instructionsLabel.setText("Unknown Error parsing JSON.", juce::dontSendNotification);
        instructionsLabel.setColour(juce::Label::textColourId, juce::Colours::red);
    }
}

void ImportView::loadDemoFile(const juce::String& filePath)
{
    juce::File f(filePath);
    if (f.existsAsFile()) {
        jsonEditor.setText(f.loadFileAsString());
        parseJsonInput();
    } else {
        juce::Logger::writeToLog("Demo file not found at: " + filePath);
        instructionsLabel.setText("Error: Demo file not found.", juce::dontSendNotification);
        instructionsLabel.setColour(juce::Label::textColourId, juce::Colours::red);
    }
}
