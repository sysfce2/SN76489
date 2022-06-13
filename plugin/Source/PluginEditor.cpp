/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "BinaryData.h"

using namespace gin;

//==============================================================================
SN76489AudioProcessorEditor::SN76489AudioProcessorEditor (SN76489AudioProcessor& p)
  : gin::ProcessorEditor (p), proc (p)
{
    additionalProgramming = "Shay Green";
    
    for (auto pp : p.getPluginParameters())
    {
        ParamComponent* c = pp->isOnOff() ? (ParamComponent*)new Switch (pp) : (ParamComponent*)new Knob (pp);
        
        addAndMakeVisible (c);
        controls.add (c);
    }
    
    addAndMakeVisible (&scope);
    
    setGridSize (6, 2);
    
    scope.setNumSamplesPerPixel (2);
    scope.setVerticalZoomFactor (3.0f);
    scope.setColour (gin::TriggeredScope::lineColourId, findColour (gin::PluginLookAndFeel::grey45ColourId));
    scope.setColour (gin::TriggeredScope::traceColourId + 0, findColour (gin::PluginLookAndFeel::accentColourId));
    scope.setColour (gin::TriggeredScope::envelopeColourId + 0, juce::Colours::transparentBlack);
    scope.setColour (gin::TriggeredScope::traceColourId + 1, findColour (gin::PluginLookAndFeel::accentColourId));
    scope.setColour (gin::TriggeredScope::envelopeColourId + 1, juce::Colours::transparentBlack);
}

SN76489AudioProcessorEditor::~SN76489AudioProcessorEditor()
{
}

//==============================================================================
void SN76489AudioProcessorEditor::paint (Graphics& g)
{
    gin::ProcessorEditor::paint (g);
}

void SN76489AudioProcessorEditor::resized()
{
    using AP = SN76489AudioProcessor;
    
    gin::ProcessorEditor::resized();
    
    componentForId (AP::paramPulse1Level)->setBounds (getGridArea (0, 0));
    componentForId (AP::paramPulse2Level)->setBounds (getGridArea (1, 0));
    componentForId (AP::paramPulse3Level)->setBounds (getGridArea (0, 1));
    componentForId (AP::paramNoiseLevel)->setBounds (getGridArea (1, 1));
    componentForId (AP::paramNoiseWhite)->setBounds (getGridArea (5, 0));
    componentForId (AP::paramNoiseShift)->setBounds (getGridArea (5, 1));

    scope.setBounds (getGridArea (2, 0, 3, 2).reduced (5));
}
