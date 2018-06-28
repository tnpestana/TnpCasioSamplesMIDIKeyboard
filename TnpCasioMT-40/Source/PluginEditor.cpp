/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TnpCasioMt40AudioProcessorEditor::TnpCasioMt40AudioProcessorEditor (TnpCasioMt40AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 200);

	addAndMakeVisible(sampleToneComboBox);
	for (int i = 1; i < 25; i++)
	{
		sampleToneComboBox.addItem((String)i, i);
	}

	sampleToneAttachment = new AudioProcessorValueTreeState::ComboBoxAttachment(p.treeState, "sampleTone", sampleToneComboBox);

	sampleToneComboBox.addListener(this);
}

TnpCasioMt40AudioProcessorEditor::~TnpCasioMt40AudioProcessorEditor()
{
}

//==============================================================================
void TnpCasioMt40AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void TnpCasioMt40AudioProcessorEditor::resized()
{
	Rectangle<int> area(getLocalBounds());
	sampleToneComboBox.setBounds(area.reduced(90));
}

void TnpCasioMt40AudioProcessorEditor::comboBoxChanged(ComboBox * comboBoxThatHasChanged)
{
	processor.setVoice();
}
