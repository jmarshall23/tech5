#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\animation\facemgr.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2182; PDB kind: enum.
enum idFaceMgr::facialAnimFlags_t : __int32
{
  FACEFLAG_ANIMATE_MOODS = 0x1,
  FACEFLAG_ANIMATE_LIPSYNC = 0x2,
  FACEFLAG_ANIMATE_GESTURES = 0x4,
  FACEFLAG_EYE_TRACK = 0x8,
  FACEFLAG_ANIMATE_BLINK = 0x10,
  FACEFLAG_LID_DEFORMATION = 0x20,
  FACEFLAG_DOUBLE_BLINK = 0x40,
  FACEFLAG_SUPPRESS_BLINK = 0x80,
  FACEFLAG_SUPPRESS_LID_DEFORM = 0x100,
  FACEFLAG_ENABLE = 0x200,
  FACEFLAG_ANIMATE_GLANCE = 0x400,
  FACEFLAG_SUPPRESS_GLANCE = 0x800,
  FACEFLAG_ANIMATE_CYCLE = 0x1000,
  FACEFLAG_SUPPRESS_CYCLE = 0x2000,
  FACEFLAG_ANIMATE_FIDGET = 0x4000,
  FACEFLAG_SUPPRESS_FIDGET = 0x8000,
};

// IDA Local Type ordinal 2183; PDB kind: enum.
enum idFaceMgr::lidDeformation_t : __int32
{
  LID_DEFORM_NONE = 0x0,
  LID_DEFORM_FIRST = 0x1,
  LID_DEFORM_UP = 0x1,
  LID_DEFORM_DOWN = 0x2,
  LID_DEFORM_RIGHT = 0x3,
  LID_DEFORM_LEFT = 0x4,
  LID_DEFORM_MAX = 0x5,
};

// IDA Local Type ordinal 2184; PDB kind: enum.
enum idFaceMgr::eyeFaceChannels_t : __int32
{
  EYEFACECHANNEL_LEFT = 0x0,
  EYEFACECHANNEL_RIGHT = 0x1,
  EYEFACECHANNEL_UP = 0x2,
  EYEFACECHANNEL_DOWN = 0x3,
  EYEFACECHANNEL_NUM = 0x4,
};

// IDA Local Type ordinal 2185; PDB kind: enum.
enum idFaceMgr::attentionLevel_t : __int32
{
  ATTENTION_LOW = 0x0,
  ATTENTION_MODERATE = 0x1,
  ATTENTION_HIGH = 0x2,
  ATTENTION_MAX = 0x3,
};

// IDA Local Type ordinal 2591; PDB kind: enum.
enum idFaceMgr::soundSampleState_t : __int32
{
  SOUNDSAMPLE_LEAD_IN = 0x0,
  SOUNDSAMPLE_PLAYING = 0x1,
  SOUNDSAMPLE_DONE = 0x2,
  SOUNDSAMPLE_MAX = 0x3,
};

// IDA Local Type ordinal 14647; PDB kind: class.
class idFaceMgr : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14648.
  virtual idTypeInfo *GetType();
  virtual ~idFaceMgr();

  mood_t mood;
  mood_t lastMood;
  mood_t defaultMood;
  soundChannel_t voiceChannel;
  faceChannel_t clearChannel;
  unsigned __int16 flags;
  unsigned __int16 lastFlags;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> moodTable[9];
  idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> visemeTable;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> blinkAlias;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> lidDeformationAliases[5];
  __int16 eyeFaceChannels[4];
  idIndex<short,enum invalidUserChannelIndex_t> eyeLidUserChannels[2];
  const idDeclVoiceOver *voiceOver;
  int voiceTrackIndex;
  const idSoundShader *lastSoundShader;
  const idDeclVisemeSet *curVisemeSet;
  idTypesafeNumber<int,enum millisecondUnique_t> vtrackDuration;
  idTypesafeNumber<int,enum millisecondUnique_t> realStartTime;
  idTypesafeNumber<int,enum millisecondUnique_t> realEndTime;
  idTypesafeNumber<int,enum gameTimeUnique_t> vtrackStartTime;
  idTypesafeNumber<int,enum millisecondUnique_t> startSoundTime;
  idTypesafeNumber<int,enum millisecondUnique_t> lastSampleTime;
  idTypesafeNumber<int,enum gameTimeUnique_t> endLipsyncTime;
  idFaceAnimator faceAnimator;
  idIndex<short,enum invalidJointIndex_t> eyeJointIndex[2];
  idIndex<short,enum invalidJointIndex_t> headJointIndex;
  int nextBlinkTime;
  int nextJitterTime;
  idVec3 eyeJitterOffset;
  idAngles eyeAngles[2];
  float eyeWander[2];
  bool initEyeTracking;
  bool useFaceSetupEyeTracking;
  bool useFaceSetupBlinking;
  bool startedVO;
  idFaceMgr::attentionLevel_t focusAttentionLevel;
  int lastGlanceTime;
  int currentGlanceInterval;
  bool glancingPreviousFrame;
  int lastFidgetTime;
  int currentFidgetInterval;
  bool fidgetingPreviousFrame;
  int nextCycleSelectTime;
  int currentFluffInterval;
};
