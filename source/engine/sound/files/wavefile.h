#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sound\files\wavefile.h
// Recovered logical types: 17
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2937; PDB kind: unknown.
enum idWaveFile::<unnamed_tag> : __int32
{
  CHANNEL_INDEX_FRONT_LEFT = 0x0,
  CHANNEL_INDEX_FRONT_RIGHT = 0x1,
  CHANNEL_INDEX_FRONT_CENTER = 0x2,
  CHANNEL_INDEX_LOW_FREQUENCY = 0x3,
  CHANNEL_INDEX_BACK_LEFT = 0x4,
  CHANNEL_INDEX_BACK_RIGHT = 0x5,
  CHANNEL_INDEX_FRONT_LEFT_CENTER = 0x6,
  CHANNEL_INDEX_FRONT_RIGHT_CENTER = 0x7,
  CHANNEL_INDEX_BACK_CENTER = 0x8,
  CHANNEL_INDEX_SIDE_LEFT = 0x9,
  CHANNEL_INDEX_SIDE_RIGHT = 0xA,
  CHANNEL_INDEX_MAX = 0xB,
};

// IDA Local Type ordinal 13497; PDB kind: struct.
struct idWaveFile::waveFmt_t::basic_t
{
  unsigned __int16 formatTag;
  unsigned __int16 numChannels;
  unsigned int samplesPerSec;
  unsigned int avgBytesPerSec;
  unsigned __int16 blockSize;
  unsigned __int16 bitsPerSample;
};

// IDA Local Type ordinal 13498; PDB kind: struct.
struct idWaveFile::waveFmt_t::extra_t::extensible_t::guid_t
{
  unsigned int data1;
  unsigned __int16 data2;
  unsigned __int16 data3;
  unsigned __int16 data4;
  unsigned __int8 data5[6];
};

// IDA Local Type ordinal 13499; PDB kind: struct.
struct __unaligned __declspec(align(2)) idWaveFile::waveFmt_t::extra_t::extensible_t
{
  unsigned __int16 validBitsPerSample;
  unsigned int channelMask;
  idWaveFile::waveFmt_t::extra_t::extensible_t::guid_t subFormat;
};

// IDA Local Type ordinal 13500; PDB kind: struct.
struct idWaveFile::waveFmt_t::extra_t::adpcm_t::adpcmcoef_t
{
  __int16 coef1;
  __int16 coef2;
};

// IDA Local Type ordinal 13501; PDB kind: struct.
struct idWaveFile::waveFmt_t::extra_t::adpcm_t
{
  unsigned __int16 samplesPerBlock;
  unsigned __int16 numCoef;
  idWaveFile::waveFmt_t::extra_t::adpcm_t::adpcmcoef_t aCoef[7];
};

// IDA Local Type ordinal 13502; PDB kind: struct.
struct __unaligned __declspec(align(2)) idWaveFile::waveFmt_t::extra_t::xma2_t
{
  unsigned __int16 numStreams;
  unsigned int channelMask;
  unsigned int samplesEncoded;
  unsigned int bytesPerBlock;
  unsigned int playBegin;
  unsigned int playLength;
  unsigned int loopBegin;
  unsigned int loopLength;
  unsigned __int8 loopCount;
  unsigned __int8 encoderVersion;
  unsigned __int16 blockCount;
};

// IDA Local Type ordinal 13503; PDB kind: union.
union idWaveFile::waveFmt_t::extra_t
{
  idWaveFile::waveFmt_t::extra_t::extensible_t extensible;
  idWaveFile::waveFmt_t::extra_t::adpcm_t adpcm;
  idWaveFile::waveFmt_t::extra_t::xma2_t xma2;
};

// IDA Local Type ordinal 13504; PDB kind: struct.
struct idWaveFile::waveFmt_t
{
  idWaveFile::waveFmt_t::basic_t basic;
  unsigned __int16 extraSize;
  idWaveFile::waveFmt_t::extra_t extra;
};

// IDA Local Type ordinal 21716; PDB kind: struct.
struct idWaveFile::chunk_t
{
  unsigned int id;
  unsigned int size;
  unsigned int offset;
};

// IDA Local Type ordinal 22471; PDB kind: class.
class idWaveFile
{
public:
  idFile *file;
  idStaticList<idWaveFile::chunk_t,32> chunks;
};

// IDA Local Type ordinal 22472; PDB kind: struct.
struct idWaveFile::dataChunk_t
{
  unsigned int size;
  void *data;
};

// IDA Local Type ordinal 22473; PDB kind: struct.
struct __declspec(align(4)) idWaveFile::formatChunk_t
{
  unsigned int size;
  unsigned __int16 compressionCode;
  unsigned __int16 numChannels;
  unsigned int sampleRate;
  unsigned int averageBytesPerSecond;
  unsigned __int16 blockAlign;
  unsigned __int16 bitsPerSample;
  unsigned __int16 numExtraFormatByte;
};

// IDA Local Type ordinal 22474; PDB kind: struct.
struct idWaveFile::samplerChunk_t
{
  unsigned int manufacturer;
  unsigned int product;
  unsigned int samplePeriod;
  unsigned int MIDIUnityNote;
  unsigned int MIDIPitchFraction;
  unsigned int SMPTEFormat;
  unsigned int SMPTEOffset;
  unsigned int numSampleLoops;
  unsigned int extraSamplerData;
};

// IDA Local Type ordinal 22475; PDB kind: struct.
struct idWaveFile::sampleData_t
{
  unsigned int identifier;
  unsigned int type;
  unsigned int start;
  unsigned int end;
  unsigned int fraction;
  unsigned int playCount;
};

// IDA Local Type ordinal 22766; PDB kind: struct.
struct idWaveFile::Open::__l23::header_t
{
  unsigned int id;
  unsigned int size;
  unsigned int format;
};

// IDA Local Type ordinal 22767; PDB kind: struct.
struct idWaveFile::Open::__l28::chuckHeader_t
{
  unsigned int id;
  unsigned int size;
};
