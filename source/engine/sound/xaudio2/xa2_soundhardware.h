#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sound\xaudio2\xa2_soundhardware.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22677; PDB kind: class.
class idSoundHardware_XAudio2
{
public:
  IXAudio2 *pXAudio2;
  IXAudio2MasteringVoice *pMasterVoice;
  IXAudio2SubmixVoice *pSubmixVoice;
  idSoundEngineCallback soundEngineCallback;
  float dryGain;
  int outputChannels;
  int channelMask;
  idDebugGraph *vuMeterRMS;
  idDebugGraph *vuMeterPeak;
  int vuMeterPeakTimes[8];
  idStaticList<idSoundVoice_XAudio2,96> voices;
  idStaticList<idSoundVoice_XAudio2 *,96> zombieVoices;
  idStaticList<idSoundVoice_XAudio2 *,96> freeVoices;
};

// IDA Local Type ordinal 22684; PDB kind: class.
class idSoundHardware : public idSoundHardware_XAudio2
{
public:
};
