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
	treeState(*this, nullptr, "CasioState", 
		{ 
		  std::make_unique<AudioParameterChoice>("keyboard", "keyboard",
			StringArray("mt-40", "rapman", "sa-10", "sk-1"), 1),
		  std::make_unique<AudioParameterInt>("tone", "tone", 0, 23, 1)
		}),
	localKeyboard(0),
	localTone(0),
	midiState()
#endif
{
	setVoice();
}

TnpCasioMt40AudioProcessor::~TnpCasioMt40AudioProcessor()
{
}


void TnpCasioMt40AudioProcessor::setVoice()
{
	synth.clearVoices();
	for (auto i = 0; i < 10; ++i)
	{
		synth.addVoice(new SamplerVoice());
	}
	WavAudioFormat wavFormat;
	ScopedPointer<AudioFormatReader> audioReader;
	localKeyboard = (int)*treeState.getRawParameterValue("keyboard");
	localTone = (int)*treeState.getRawParameterValue("tone");

	if (localKeyboard == 0)
	{
		switch (localTone)
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
	}
	else if (localKeyboard == 1)
	{
		// also 24 sounds so no index mapping is needed
		switch (localTone)
		{
		case 0:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_agogo_wav, BinaryData::RPMN_agogo_wavSize, false), true);
			break;
		case 1:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_ambulance_wav, BinaryData::RPMN_ambulance_wavSize, false), true);
			break;
		case 2:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_bandhitbrass_wav, BinaryData::RPMN_bandhitbrass_wavSize, false), true);
			break;
		case 3:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_bells_wav, BinaryData::RPMN_bells_wavSize, false), true);
			break;
		case 4:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_brassens_wav, BinaryData::RPMN_brassens_wavSize, false), true);
			break;
		case 5:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_carhorn_wav, BinaryData::RPMN_carhorn_wavSize, false), true);
			break;
		case 6:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_churchbells_wav, BinaryData::RPMN_churchbells_wavSize, false), true);
			break;
		case 7:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_ebass_wav, BinaryData::RPMN_ebass_wavSize, false), true);
			break;
		case 8:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_echobrass_wav, BinaryData::RPMN_echobrass_wavSize, false), true);
			break;
		case 9:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_emergencyalarm_wav, BinaryData::RPMN_emergencyalarm_wavSize, false), true);
			break;
		case 10:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_eorgan_wav, BinaryData::RPMN_eorgan_wavSize, false), true);
			break;
		case 11:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_flute_wav, BinaryData::RPMN_flute_wavSize, false), true);
			break;
		case 12:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_gamelan_wav, BinaryData::RPMN_gamelan_wavSize, false), true);
			break;
		case 13:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_metalguitar_wav, BinaryData::RPMN_metalguitar_wavSize, false), true);
			break;
		case 14:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_orchestrahit_wav, BinaryData::RPMN_orchestrahit_wavSize, false), true);
			break;
		case 15:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_piano_wav, BinaryData::RPMN_piano_wavSize, false), true);
			break;
		case 16:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_sitar_wav, BinaryData::RPMN_sitar_wavSize, false), true);
			break;
		case 17:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_synthlead_wav, BinaryData::RPMN_synthlead_wavSize, false), true);
			break;
		case 18:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_synthreed_wav, BinaryData::RPMN_synthreed_wavSize, false), true);
			break;
		case 19:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_twinkleecho_wav, BinaryData::RPMN_twinkleecho_wavSize, false), true);
			break;
		case 20:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_vibraphone_wav, BinaryData::RPMN_vibraphone_wavSize, false), true);
			break;
		case 21:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_vocoder_wav, BinaryData::RPMN_vocoder_wavSize, false), true);
			break;
		case 22:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_warmstrings_wav, BinaryData::RPMN_warmstrings_wavSize, false), true);
			break;
		case 23:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::RPMN_wawvoice_wav, BinaryData::RPMN_warmstrings_wavSize, false), true);
			break;
		}
	}
	else if(localKeyboard == 2)
	{
		// accomodate the combo attachment linear distribution of values by converting the range intervals
		// to map [A, B] --> [a, b] use: (val - A)*(b-a)/(B-A) + a
		int convertedLocalTone = localTone * 12 / 24;
		switch (convertedLocalTone)
		{
		case 0:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SA10_accordion_wav, BinaryData::SA10_accordion_wavSize, false), true);
			break;
		case 1:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SA10_bassoon_wav, BinaryData::SA10_bassoon_wavSize, false), true);
			break;
		case 2:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SA10_cello_wav, BinaryData::SA10_cello_wavSize, false), true);
			break;
		case 3:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SA10_epiano_wav, BinaryData::SA10_epiano_wavSize, false), true);
			break;
		case 4:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SA10_flute_wav, BinaryData::SA10_flute_wavSize, false), true);
			break;
		case 5:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SA10_honkypiano_wav, BinaryData::SA10_honkypiano_wavSize, false), true);
			break;
		case 6:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SA10_metalguitar_wav, BinaryData::SA10_metalguitar_wavSize, false), true);
			break;
		case 7:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SA10_piano_wav, BinaryData::SA10_piano_wavSize, false), true);
			break;
		case 8:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SA10_poplead_wav, BinaryData::SA10_poplead_wavSize, false), true);
			break;
		case 9:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SA10_synthaccordion_wav, BinaryData::SA10_synthaccordion_wavSize, false), true);
			break;
		case 10:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SA10_synthbrass_wav, BinaryData::SA10_synthbrass_wavSize, false), true);
			break;
		case 11:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SA10_synthlead_wav, BinaryData::SA10_synthlead_wavSize, false), true);
		}
	}
	else if(localKeyboard == 3)
	{
		// accomodate the combo attachment linear distribution of values by converting the range intervals
		// to map [A, B] --> [a, b] use: (val - A)*(b-a)/(B-A) + a
		int convertedLocalTone = localTone * 8 / 24;
		switch (convertedLocalTone)
		{
		case 0:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SK1_brass_wav, BinaryData::SK1_brass_wavSize, false), true);
			break;
		case 1:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SK1_flute_wav, BinaryData::SK1_flute_wavSize, false), true);
			break;
		case 2:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SK1_organ_wav, BinaryData::SK1_organ_wavSize, false), true);
			break;
		case 3:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SK1_piano_wav, BinaryData::SK1_piano_wavSize, false), true);
			break;
		case 4:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SK1_pipeorgan_wav, BinaryData::SK1_pipeorgan_wavSize, false), true);
			break;
		case 5:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SK1_synthdrum_wav, BinaryData::SK1_synthdrum_wavSize, false), true);
			break;
		case 6:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SK1_trumpet_wav, BinaryData::SK1_trumpet_wavSize, false), true);
			break;
		case 7:
			audioReader = (AudioFormatReader*)wavFormat.createReaderFor(new MemoryInputStream(BinaryData::SK1_voice_wav, BinaryData::SK1_voice_wavSize, false), true);
			break;
		}
	} 

	BigInteger allNotes;
	allNotes.setRange(0, 128, true);

	synth.clearSounds();
	synth.addSound(new SamplerSound("demo sound",
		*audioReader,
		allNotes,
		60,   // root midi note
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

	if (localTone != (int)*treeState.getRawParameterValue("tone") ||
		localKeyboard != (int)*treeState.getRawParameterValue("keyboard"))
		setVoice();

	midiState.processNextMidiBuffer(midiMessages, 0, buffer.getNumSamples(), true);

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
    return new TnpCasioMt40AudioProcessorEditor (*this, treeState, midiState);
}

//==============================================================================
void TnpCasioMt40AudioProcessor::getStateInformation (MemoryBlock& destData)
{
	auto state = treeState.copyState();
	std::unique_ptr<XmlElement> xml(state.createXml());
	copyXmlToBinary(*xml, destData);
}

void TnpCasioMt40AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
	if (xmlState.get() != nullptr)
		if (xmlState->hasTagName(treeState.state.getType()))
			treeState.replaceState(ValueTree::fromXml(*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TnpCasioMt40AudioProcessor();
}
