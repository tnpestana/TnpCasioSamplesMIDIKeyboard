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
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
	formatManager.registerBasicFormats();

	synth.clearVoices();
	// Add some voices to our synth, to play the sounds..
	for (auto i = 0; i < 4; ++i)
	{
		synth.addVoice(new SamplerVoice());    // and these ones play the sampled sounds
	}

	File* file = new File("C:/Users/tnpes/Documents/Code/JUCE/Samples/CasioMT-40/9.wav");
	std::unique_ptr<AudioFormatReader> audioReader = (std::unique_ptr<AudioFormatReader>) formatManager.createReaderFor(*file);

	BigInteger allNotes;
	allNotes.setRange(0, 128, true);

	synth.clearSounds();
	synth.addSound(new SamplerSound("demo sound",
		*audioReader,
		allNotes,
		74,   // root midi note
		0.1,  // attack time
		0.1,  // release time
		10.0  // maximum sample length
	));
}

TnpCasioMt40AudioProcessor::~TnpCasioMt40AudioProcessor()
{
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

	// fill a midi buffer with incoming messages from the midi input.
	midiCollector.removeNextBlockOfMessages(midiMessages, buffer.getNumSamples());

	// and now get the synth to process the midi events and generate its output.
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
