/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Cell.h"

//==============================================================================
/**
*/
union Grid
{
    int rows, cols;
};

class Ca808AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Ca808AudioProcessorEditor (Ca808AudioProcessor&);
    ~Ca808AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    Grid grid;
    int cellIndex { 0 };
    const int numCells { 64 };
    const int cellArea { 40 };
    std::vector <std::unique_ptr<Cell>> cellVec;
    
    Ca808AudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Ca808AudioProcessorEditor)
};
