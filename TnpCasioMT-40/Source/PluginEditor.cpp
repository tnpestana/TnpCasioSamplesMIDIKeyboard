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
    setSize (200, 200);

	addAndMakeVisible(comboKeyboard);
	addAndMakeVisible(comboTone);

	// populate casioMT-40_tones list with numbers while we dont have sound names
	for (int i = 1; i < 25; i++)
		casioMT40_tones.add((String)i);

	comboKeyboard.addItem("casio MT-40", 1);
	comboKeyboard.addItem("casio Rapman", 2);
	comboKeyboard.addItem("casio SA-10", 3);
	comboKeyboard.addItem("casio SK-1", 4);

	attachmentKeyboard = new AudioProcessorValueTreeState::ComboBoxAttachment(p.treeState, "keyboard", comboKeyboard);
	attachmentTone = new AudioProcessorValueTreeState::ComboBoxAttachment(p.treeState, "tone", comboTone);

	manageComboBoxes();

	comboKeyboard.addListener(this);
	comboTone.addListener(this);
}

TnpCasioMt40AudioProcessorEditor::~TnpCasioMt40AudioProcessorEditor()
{
}

StringArray TnpCasioMt40AudioProcessorEditor::casioMT40_tones{};

StringArray TnpCasioMt40AudioProcessorEditor::casioRPMN_tones{
	"agogo", "ambulance", "band hit-brass", "bells", 
	"brass ens", "car horn", "church bells", "e bass",
	"echo brass", "emergency alarm", "e organ", "flute",
	"gamelan", "metal guitar", "orchestra hit", "piano",
	"sitar", "synth lead", "synth reed", "twinkle echo",
	"vibraphone", "vocoder", "warm strings", "waw voice"
};

StringArray TnpCasioMt40AudioProcessorEditor::casioSA10_tones{
	"accordion", "basson", "cello", "e piano", "flute",
	"honkypiano", "metalguitar", "piano", "poplead",
	"synthaccordion", "synthbrass", "synthlead"
};

StringArray TnpCasioMt40AudioProcessorEditor::casioSK1_tones{
	"brass", "flute", "organ", "piano", "pipeorgan", 
	"synthdrum", "trumpet", "voice"
};

//==============================================================================
void TnpCasioMt40AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void TnpCasioMt40AudioProcessorEditor::resized()
{
	Rectangle<int> area(getLocalBounds());
	comboTone.setBounds(area.removeFromBottom(area.getHeight() / 2).reduced(40));
	comboKeyboard.setBounds(area.reduced(40));
}

void TnpCasioMt40AudioProcessorEditor::comboBoxChanged(ComboBox * comboBoxThatHasChanged)
{
	if(&comboKeyboard == comboBoxThatHasChanged)
		manageComboBoxes();
}

void TnpCasioMt40AudioProcessorEditor::manageComboBoxes() 
{
	int keyboardParam = comboKeyboard.getSelectedId();
	if (keyboardParam == 1)
	{
		comboTone.clear();
		comboTone.addItemList(casioMT40_tones, 1);
		comboTone.setSelectedItemIndex(0);
	}
	else if (keyboardParam == 2)
	{
		comboTone.clear();
		comboTone.addItemList(casioRPMN_tones, 1);
		comboTone.setSelectedItemIndex(0);
	}
	else if(keyboardParam == 3)
	{
		comboTone.clear();
		comboTone.addItemList(casioSA10_tones, 1);
		comboTone.setSelectedItemIndex(0);
	}
	else if (keyboardParam == 4)
	{
		comboTone.clear();
		comboTone.addItemList(casioSK1_tones, 1);
		comboTone.setSelectedItemIndex(0);
	}
}
