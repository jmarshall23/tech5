#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\voiceovers\voicetrack.h
// Recovered logical types: 8
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2628; PDB kind: enum.
enum idVoiceTrack::eventOffset_t : __int32
{
  EVENTOFFSET_FORWARDS = 0x1,
  EVENTOFFSET_BACKWARDS = 0xFFFFFFFF,
};

// IDA Local Type ordinal 13893; PDB kind: class.
class idVoiceTrack : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13926.
  virtual ~idVoiceTrack();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  idList<vtrEventHandle_t,66> events;
  idVoiceEventManager voiceEventManager;
  idVoiceTrack::idFrameRef *frameRefs;
  __int16 numFrameRefs;
  idVoiceTrack::idFrameRefIndexBuffer indexBuffer;
  bool rebuildFrameRefs;
  char visemeOffsetState;
  char offsetState;
  idAtomicString textLangKey;
  idStrId textId;
  unsigned int textCRC;
  unsigned int lipsyncTextCRC;
  idAtomicString subtitleLangKey;
  idStrId subtitleId;
  const idSoundShader *soundShader;
  unsigned int sampleTimestamp;
  unsigned int sampleCRC;
  idStr animName;
  faceChannel_t faceChannel;
  __int16 blendInMS;
  __int16 blendOutMS;
  unsigned int soundOffsetMS;
  unsigned int visemeOffsetMS;
  unsigned int animEventOffsetMS;
  unsigned int moodEventOffsetMS;
  unsigned int gameEventOffsetMS;
  unsigned int textEventOffsetMS;
  idVoiceTrack::flags_t flags;
  float weightScale;
  mood_t defaultMood;
  const idDeclVisemeSet *declVisemeSet;
  unsigned int timestamp;
  idTypesafeNumber<int,enum millisecondUnique_t> approximateDuration;
};

// IDA Local Type ordinal 13917; PDB kind: class.
class idVoiceTrack::idFrameRef
{
public:
  unsigned __int16 offset;
  unsigned __int16 numIndices;
};

// IDA Local Type ordinal 13918; PDB kind: class.
class idVoiceTrack::idFrameRefIndexBuffer
{
public:
  unsigned __int16 curOffset;
  unsigned __int16 size;
  unsigned __int16 *indices;
};

// IDA Local Type ordinal 13919; PDB kind: struct.
struct idVoiceTrack::flags_t
{
  __int8 useExactDuration : 1;
  __int8 useRealTime : 1;
  __int8 edited : 1;
  __int8 compressed : 1;
  __int8 suppressBlinking : 1;
  __int8 noLipSync : 1;
  __int8 clearAnimAfter : 1;
  __int8 cycleAnim : 1;
};

// IDA Local Type ordinal 20446; PDB kind: class.
class idVoiceTrack::idSubtitleText
{
public:
  idStr word;
  idTypesafeNumber<int,enum millisecondUnique_t> time;
};

// IDA Local Type ordinal 21828; PDB kind: struct.
struct idVoiceTrack::frameInfo_t
{
  int frame;
  int loop;
};

// IDA Local Type ordinal 21829; PDB kind: struct.
struct idVoiceTrack::localizedVTROnDisc
{
  char name[256];
  char lang[16];
  int offset;
  int size;
  void *data;
};
