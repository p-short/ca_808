/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Ca808AudioProcessorEditor::Ca808AudioProcessorEditor (Ca808AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    for (auto i = 0; i < 64; ++i)
    {
        cellVec.push_back (std::make_unique<Cell>());
        addAndMakeVisible (*cellVec.back());
    }
    
    grid.rows = 8;
    setSize (400, 400);
}

Ca808AudioProcessorEditor::~Ca808AudioProcessorEditor()
{
}

//==============================================================================
void Ca808AudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::lightblue);
}

void Ca808AudioProcessorEditor::resized()
{
    const int gap = 40;
    for (int i = 0; i < grid.rows; i ++)
    {
        for (int j = 0; j < grid.cols; j++)
        {
            cellVec[index]->setBounds(40 + i * gap, 40 + j * gap, gap, gap);
            index++;
        }
    }
}
