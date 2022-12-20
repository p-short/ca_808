/*
  ==============================================================================

    Cell.h
    Created: 17 Dec 2022 2:57:56pm
    Author:  Phillip Short

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
struct CellLookAndFeel : public juce::LookAndFeel_V4
{
    void drawButtonBackground (juce::Graphics &g, juce::Button &button, const juce::Colour &backgroundColour, bool isMouseOverButton, bool isButtonDown) override
    {
        //fill background colour
        auto buttonArea = button.getLocalBounds();
        g.setColour (backgroundColour);
        g.fillRect (buttonArea);
        //cell outline
        g.setColour (isMouseOverButton ? juce::Colours::darkgrey : juce::Colours::black);
        g.drawRect (buttonArea, 2);
    }
    
};

class Cell  : public juce::Component
{
public:
    Cell()
    {
        myCell.setLookAndFeel (&cellLookAndFeel);
        //change the default background colour to white
        cellLookAndFeel.setColour (juce::TextButton::ColourIds::buttonColourId, juce::Colours::white);
        addAndMakeVisible (myCell);
    }

    ~Cell() override
    {
    }

    void paint (juce::Graphics& g) override
    {

    }

    void resized() override
    {
        myCell.setBounds(getLocalBounds());
    }
    
    //use method to change indervidual instances of cells background colours
    void changeCellBackgroundColour (int colourID, juce::Colour colour)
    {
        cellLookAndFeel.setColour (colourID, colour);
    }

private:
    CellLookAndFeel cellLookAndFeel;
    juce::TextButton myCell;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Cell)
};
