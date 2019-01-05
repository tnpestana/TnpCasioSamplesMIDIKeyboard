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
    : AudioProcessorEditor (&p),
	processor (p), 
	treeState (p.getTreeState()), 
	keyboard (p.getMidiState(), MidiKeyboardComponent::horizontalKeyboard)
{
	addAndMakeVisible(comboKeyboard);
	addAndMakeVisible(comboTone);
	addAndMakeVisible(keyboard);

	// populate keyboard choice combo box with strings stored as choices in keyboard parameter
	if (auto* choiceParameter = dynamic_cast<AudioParameterChoice*>(treeState.getParameter("keyboard")))
		comboKeyboard.addItemList(choiceParameter->choices, 1);

	// populate casioMT-40_tones list with numbers while we dont have sound names
	for (int i = 1; i < 25; i++)
		casioMT40_tones.add((String)i);

	attachmentKeyboard = new AudioProcessorValueTreeState::ComboBoxAttachment(treeState, "keyboard", comboKeyboard);
	attachmentTone = new AudioProcessorValueTreeState::ComboBoxAttachment(treeState, "tone", comboTone);

	if (comboKeyboard.getSelectedId() == 0)
		comboKeyboard.setSelectedId(1);

	keyboardChanged();

	comboKeyboard.addListener(this);
	comboTone.addListener(this);

	setSize(400, 200);
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
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
	g.fillAll(juce::Colours::darkgrey);

	getLookAndFeel().setColour(ComboBox::backgroundColourId, Colours::white);
	getLookAndFeel().setColour(ComboBox::textColourId, Colours::black);
	getLookAndFeel().setColour(ComboBox::arrowColourId, Colours::black);
	getLookAndFeel().setColour(PopupMenu::backgroundColourId, Colours::white);
	getLookAndFeel().setColour(PopupMenu::textColourId, Colours::black);
}

void TnpCasioMt40AudioProcessorEditor::resized()
{
	Rectangle<int> area(getLocalBounds());

	Rectangle<int> combosArea(area.removeFromTop(area.getHeight() / 2));
	comboKeyboard.setBounds(combosArea.removeFromLeft(area.getWidth() / 2).reduced(40));
	comboTone.setBounds(combosArea.reduced(40));

	keyboard.setBounds(area.reduced(5));
}

void TnpCasioMt40AudioProcessorEditor::comboBoxChanged(ComboBox * comboBoxThatHasChanged)
{
	if (&comboKeyboard == comboBoxThatHasChanged)
		keyboardChanged();
}

void TnpCasioMt40AudioProcessorEditor::keyboardChanged() 
{
	int keyboardParam = comboKeyboard.getSelectedId();
	int toneParam = *treeState.getRawParameterValue("tone");
	int convertedToneParam = 0;
	
	switch(keyboardParam)
	{
	// MT-40
	case 1:
		comboTone.clear();
		comboTone.addItemList(casioMT40_tones, 1);
		comboTone.setSelectedItemIndex(toneParam);
		break;
	// RPMN
	case 2:
		comboTone.clear();
		comboTone.addItemList(casioRPMN_tones, 1);
		comboTone.setSelectedItemIndex(toneParam);
		break;
	// SA-10
	case 3:
		comboTone.clear();
		comboTone.addItemList(casioSA10_tones, 1);
		// accomodate the combo attachment linear distribution of values by converting the range intervals
		// to map [A, B] --> [a, b] use: (val - A)*(b-a)/(B-A) + a
		convertedToneParam = toneParam * 12 / 24;
		comboTone.setSelectedItemIndex(convertedToneParam);
		break;
	// SK-1
	case 4:
		comboTone.clear();
		comboTone.addItemList(casioSK1_tones, 1);
		// accomodate the combo attachment linear distribution of values by converting the range intervals
		// to map [A, B] --> [a, b] use: (val - A)*(b-a)/(B-A) + a
		convertedToneParam = toneParam * 8 / 24;
		comboTone.setSelectedItemIndex(convertedToneParam);
		break;
	}
}



