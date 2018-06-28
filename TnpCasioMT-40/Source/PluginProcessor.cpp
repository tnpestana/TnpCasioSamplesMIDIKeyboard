/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TnpCasioMt40AudioProcessor::TnpCasioMt40AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
	: AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
		.withInput("Input", AudioChannelSet::stereo(), true)
#endif
		.withOutput("Output", AudioChannelSet::stereo(), true)
#endif
	),
	treeState(*this, nullptr)
#endif
{
	NormalisableRange<float> sampleToneRange(0, 23, 1);
	treeState.createAndAddParameter("sampleTone", "SampleTone", String(), sampleToneRange, 0, nullptr, nullptr);

	treeState.state = ValueTree(Identifier("CasioState"));

	setVoice();
}

TnpCasioMt40AudioProcessor::~TnpCasioMt40AudioProcessor()
{
}


void TnpCasioMt40AudioProcessor::setVoice()
{
	synth.clearVoices();
	// Add some voices to our synth, to play the sounds..
	for (auto i = 0; i < 5; ++i)
	{
		synth.addVoice(new SamplerVoice());
	}

	WavAudioFormat wavFormat;
	ScopedPointer<AudioFormatReader> audioReader;
	switch ((int)*treeState.getRawParameterValue("sampleTone"))
	{
	case 0:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_1_wav, BinaryData::_1_wavSize, false), true);
		break;
	case 1:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_2_wav, BinaryData::_2_wavSize, false), true);
		break;
	case 2:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_3_wav, BinaryData::_3_wavSize, false), true);
		break;
	case 3:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_4_wav, BinaryData::_4_wavSize, false), true);
		break;
	case 4:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_5_wav, BinaryData::_5_wavSize, false), true);
		break;
	case 5:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_6_wav, BinaryData::_6_wavSize, false), true);
		break;
	case 6:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_7_wav, BinaryData::_7_wavSize, false), true);
		break;
	case 7:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_8_wav, BinaryData::_8_wavSize, false), true);
		break;
	case 8:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_9_wav, BinaryData::_9_wavSize, false), true);
		break;
	case 9:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_10_wav, BinaryData::_10_wavSize, false), true);
		break;
	case 10:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_11_wav, BinaryData::_11_wavSize, false), true);
		break;
	case 11:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_12_wav, BinaryData::_12_wavSize, false), true);
		break;
	case 12:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_13_wav, BinaryData::_13_wavSize, false), true);
		break;
	case 13:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_14_wav, BinaryData::_14_wavSize, false), true);
		break;
	case 14:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_15_wav, BinaryData::_15_wavSize, false), true);
		break;
	case 15:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_16_wav, BinaryData::_16_wavSize, false), true);
		break;
	case 16:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_17_wav, BinaryData::_17_wavSize, false), true);
		break;
	case 17:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_18_wav, BinaryData::_18_wavSize, false), true);
		break;
	case 18:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_19_wav, BinaryData::_19_wavSize, false), true);
		break;
	case 19:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_20_wav, BinaryData::_20_wavSize, false), true);
		break;
	case 20:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_21_wav, BinaryData::_21_wavSize, false), true);
		break;
	case 21:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_22_wav, BinaryData::_22_wavSize, false), true);
		break;
	case 22:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_23_wav, BinaryData::_23_wavSize, false), true);
		break;
	case 23:
		audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::_24_wav, BinaryData::_24_wavSize, false), true);
		break;
	}

	BigInteger allNotes;
	allNotes.setRange(0, 128, true);

	synth.clearSounds();
	synth.addSound(new SamplerSound("demo sound",
		*audioReader,
		allNotes,
		74,   // root midi note
		0.01,  // attack time
		0.1,  // release time
		10.0  // maximum sample length
	));

}

//==============================================================================
const String TnpCasioMt40AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TnpCasioMt40AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TnpCasioMt40AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TnpCasioMt40AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double TnpCasioMt40AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TnpCasioMt40AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TnpCasioMt40AudioProcessor::getCurrentProgram()
{
    return 0;
}

void TnpCasioMt40AudioProcessor::setCurrentProgram (int index)
{
}

const String TnpCasioMt40AudioProcessor::getProgramName (int index)
{
    return {};
}

void TnpCasioMt40AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TnpCasioMt40AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	midiCollector.reset(sampleRate);
	synth.setCurrentPlaybackSampleRate(sampleRate);
}

void TnpCasioMt40AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TnpCasioMt40AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void TnpCasioMt40AudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	// the synth always adds its output to the audio buffer, so we have to clear it
	// first..
	buffer.clear();

	midiCollector.removeNextBlockOfMessages(midiMessages, buffer.getNumSamples());

	// get the synth to process the midi events and generate its output.
	synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool TnpCasioMt40AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* TnpCasioMt40AudioProcessor::createEditor()
{
    return new TnpCasioMt40AudioProcessorEditor (*this);
}

//==============================================================================
void TnpCasioMt40AudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void TnpCasioMt40AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TnpCasioMt40AudioProcessor();
}
