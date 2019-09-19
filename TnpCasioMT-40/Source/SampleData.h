/*
  ==============================================================================

    SampleData.h
    Created: 19 Sep 2019 7:02:18pm
    Author:  Tiago Pestana

  ==============================================================================
*/

#pragma once

static class SampleData
{
public:
    std::array<void*, size_t> CasioMt40 = {
        (BinaryData::_1_wav, BinaryData::_1_wavSize),
        (BinaryData::_2_wav, BinaryData::_2_wavSize),
        (BinaryData::_3_wav, BinaryData::_3_wavSize),
        (BinaryData::_4_wav, BinaryData::_4_wavSize),
        (BinaryData::_5_wav, BinaryData::_5_wavSize),
        (BinaryData::_6_wav, BinaryData::_6_wavSize),
        (BinaryData::_7_wav, BinaryData::_7_wavSize),
        (BinaryData::_8_wav, BinaryData::_8_wavSize),
        (BinaryData::_9_wav, BinaryData::_9_wavSize),
        (BinaryData::_10_wav, BinaryData::_10_wavSize),
        (BinaryData::_11_wav, BinaryData::_11_wavSize),
        (BinaryData::_12_wav, BinaryData::_12_wavSize),
        (BinaryData::_13_wav, BinaryData::_13_wavSize),
        (BinaryData::_14_wav, BinaryData::_14_wavSize),
        (BinaryData::_15_wav, BinaryData::_15_wavSize),
        (BinaryData::_16_wav, BinaryData::_16_wavSize),
        (BinaryData::_17_wav, BinaryData::_17_wavSize),
        (BinaryData::_18_wav, BinaryData::_18_wavSize),
        (BinaryData::_19_wav, BinaryData::_19_wavSize),
        (BinaryData::_20_wav, BinaryData::_20_wavSize),
        (BinaryData::_21_wav, BinaryData::_21_wavSize),
        (BinaryData::_22_wav, BinaryData::_22_wavSize),
        (BinaryData::_23_wav, BinaryData::_23_wavSize),
        (BinaryData::_24_wav, BinaryData::_24_wavSize)
    }
    
    std::array<void*, size_t> CasioRapman = {
        (BinaryData::RPMN_agogo_wav, BinaryData::RPMN_agogo_wavSize),
        (BinaryData::RPMN_ambulance_wav, BinaryData::RPMN_ambulance_wavSize),
        (BinaryData::RPMN_bandhitbrass_wav, BinaryData::RPMN_bandhitbrass_wavSize),
        (BinaryData::RPMN_bells_wav, BinaryData::RPMN_bells_wavSize),
        (BinaryData::RPMN_brassens_wav, BinaryData::RPMN_brassens_wavSize),
        (BinaryData::RPMN_carhorn_wav, BinaryData::RPMN_carhorn_wavSize),
        (BinaryData::RPMN_churchbells_wav, BinaryData::RPMN_churchbells_wavSize),
        (BinaryData::RPMN_ebass_wav, BinaryData::RPMN_ebass_wavSize),
        (BinaryData::RPMN_echobrass_wav, BinaryData::RPMN_echobrass_wavSize),
        (BinaryData::RPMN_emergencyalarm_wav, BinaryData::RPMN_emergencyalarm_wavSize),
        (BinaryData::RPMN_eorgan_wav, BinaryData::RPMN_eorgan_wavSize),
        (BinaryData::RPMN_flute_wav, BinaryData::RPMN_flute_wavSize),
        (BinaryData::RPMN_gamelan_wav, BinaryData::RPMN_gamelan_wavSize),
        (BinaryData::RPMN_metalguitar_wav, BinaryData::RPMN_metalguitar_wavSize),
        (BinaryData::RPMN_orchestrahit_wav, BinaryData::RPMN_orchestrahit_wavSize),
        (BinaryData::RPMN_piano_wav, BinaryData::RPMN_piano_wavSize),
        (BinaryData::RPMN_sitar_wav, BinaryData::RPMN_sitar_wavSize),
        (BinaryData::RPMN_synthlead_wav, BinaryData::RPMN_synthlead_wavSize),
        (BinaryData::RPMN_synthreed_wav, BinaryData::RPMN_synthreed_wavSize),
        (BinaryData::RPMN_twinkleecho_wav, BinaryData::RPMN_twinkleecho_wavSize),
        (BinaryData::RPMN_vibraphone_wav, BinaryData::RPMN_vibraphone_wavSize),
        (BinaryData::RPMN_vocoder_wav, BinaryData::RPMN_vocoder_wavSize),
        (BinaryData::RPMN_warmstrings_wav, BinaryData::RPMN_warmstrings_wavSize),
        (BinaryData::RPMN_wawvoice_wav, BinaryData::RPMN_warmstrings_wavSize)
    }
    
    std::array<void*, size_t> CasioSa10 {
        (BinaryData::SA10_accordion_wav, BinaryData::SA10_accordion_wavSize),
        (BinaryData::SA10_bassoon_wav, BinaryData::SA10_bassoon_wavSize),
        (BinaryData::SA10_cello_wav, BinaryData::SA10_cello_wavSize),
        (BinaryData::SA10_epiano_wav, BinaryData::SA10_epiano_wavSize),
        (BinaryData::SA10_flute_wav, BinaryData::SA10_flute_wavSize),
        (BinaryData::SA10_honkypiano_wav, BinaryData::SA10_honkypiano_wavSize),
        (BinaryData::SA10_metalguitar_wav, BinaryData::SA10_metalguitar_wavSize),
        (BinaryData::SA10_piano_wav, BinaryData::SA10_piano_wavSize),
        (BinaryData::SA10_poplead_wav, BinaryData::SA10_poplead_wavSize),
        (BinaryData::SA10_synthaccordion_wav, BinaryData::SA10_synthaccordion_wavSize),
        (BinaryData::SA10_synthbrass_wav, BinaryData::SA10_synthbrass_wavSize),
        (BinaryData::SA10_synthlead_wav, BinaryData::SA10_synthlead_wavSize)
    }
    
    std::array<void*, size_t> CasioSk1 {
        (BinaryData::SK1_brass_wav, BinaryData::SK1_brass_wavSize),
        (BinaryData::SK1_flute_wav, BinaryData::SK1_flute_wavSize),
        (BinaryData::SK1_organ_wav, BinaryData::SK1_organ_wavSize),
        (BinaryData::SK1_piano_wav, BinaryData::SK1_piano_wavSize),
        (BinaryData::SK1_pipeorgan_wav, BinaryData::SK1_pipeorgan_wavSize),
        (BinaryData::SK1_synthdrum_wav, BinaryData::SK1_synthdrum_wavSize),
        (BinaryData::SK1_trumpet_wav, BinaryData::SK1_trumpet_wavSize),
        (BinaryData::SK1_voice_wav, BinaryData::SK1_voice_wavSize)
    }
}
