#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sound\soundvoice.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13731; PDB kind: class.
class idSoundVoice_Base
{
public:
  idMat3 invListenerAxis;
  idMat3 axis;
  idVec3 position;
  idVec3 velocity;
  float gain;
  float dryGain;
  float wetGain;
  float gainLFE;
  float centerChannel;
  float pitch;
  float innerRadius;
  float occlusion;
  unsigned int channelMask;
  float innerSampleRangeSqr;
  float outerSampleRangeSqr;
  idList<idSoundSample *,5> samples;
};

// IDA Local Type ordinal 13732; PDB kind: class.
class idSoundVoice_XAudio2 : public idSoundVoice_Base
{
public:
  IXAudio2SourceVoice *pSourceVoice;
  idSoundSample_XAudio2 *sample;
  pinnedCacheLines_t pins[3];
  int readPin;
  bool paused;
  unsigned __int16 formatTag;
  unsigned __int16 numChannels;
  unsigned int sourceVoiceRate;
  unsigned int sampleRate;
  unsigned __int16 bitsPerSample;
  int currentStreamBlock;
  volatile int currentStreamRemaining;
  bool hasVUMeter;
  bool hasReverb;
  int startFlags;
};

// IDA Local Type ordinal 13733; PDB kind: class.
class idSoundVoice : public idSoundVoice_XAudio2
{
public:
};
