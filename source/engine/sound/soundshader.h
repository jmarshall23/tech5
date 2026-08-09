#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sound\soundshader.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1085; PDB kind: enum.
enum __bitmask soundShaderFlags_t : __int32
{
  SSF_PRIVATE_SOUND = 0x1,
  SSF_ANTI_PRIVATE_SOUND = 0x2,
  SSF_NO_OCCLUSION = 0x4,
  SSF_GLOBAL = 0x8,
  SSF_OMNIDIRECTIONAL = 0x10,
  SSF_FRONTDIRECTIONAL = 0x20,
  SSF_REARDIRECTIONAL = 0x40,
  SSF_ENVIRONMENTAL = 0x80,
  SSF_CONEATTENUATION = 0x100,
  SSF_LOOPING = 0x200,
  SSF_PLAY_ONCE = 0x400,
  SSF_SEQUENTIAL = 0x800,
  SSF_NO_RANDOM_OFFSET = 0x1000,
  SSF_AUTO_RESTART = 0x2000,
  SSF_FLICKER = 0x4000,
  SSF_NO_EFFECTS = 0x8000,
  SSF_FINITE_SPEED_OF_SOUND = 0x10000,
  SSF_DISTANCE_LOW_PASS = 0x20000,
  SSF_LFE = 0x40000,
  SSF_DISTANCE_BASED_STEREO = 0x80000,
  SSF_RANDOM_LOOPING = 0x100000,
  SSF_PASS_HDR = 0x200000,
  SSF_BLOCK_ON_LOAD = 0x400000,
  SSF_DOPPLER = 0x800000,
  SSF_LOOP_FADE_IN = 0x1000000,
  SSF_LOOP_FADE_OUT = 0x2000000,
};

// IDA Local Type ordinal 1087; PDB kind: enum.
enum soundShaderGroups_t : __int32
{
  SSG_MASTER = 0x0,
  SSG_UI = 0x1,
  SSG_MUSIC_MENU = 0x2,
  SSG_MUSIC_INGAME = 0x4,
  SSG_SFX_GENERAL = 0x8,
  SSG_AMB_CORE = 0x10,
  SSG_AMB_SPOT = 0x20,
  SSG_EXPLOSIONS = 0x40,
  SSG_KEY_EVENTS = 0x80,
  SSG_IMPACTS = 0x100,
  SSG_RICO_BYS = 0x200,
  SSG_MOVEMENT_AI = 0x400,
  SSG_MOVEMENT_PL = 0x800,
  SSG_VEH_AI = 0x1000,
  SSG_VEH_PL = 0x2000,
  SSG_VEH_COLLISIONS_AI = 0x4000,
  SSG_VEH_COLLISIONS_PL = 0x8000,
  SSG_WEAPONS_AI = 0x10000,
  SSG_WEAPONS_PL = 0x20000,
  SSG_SPECIAL_ENEMY_MOVEMENT = 0x40000,
  SSG_SPECIAL_ENEMY_VOICE = 0x80000,
  SSG_VO_PLAYER = 0x100000,
  SSG_VO_EVENT = 0x200000,
  SSG_VO_INGAME = 0x400000,
  SSG_VO_RADIO = 0x800000,
  SSG_VO_BATTLE = 0x1000000,
};

// IDA Local Type ordinal 13490; PDB kind: struct.
struct soundShaderParms_t::coneAttenuationVars_t
{
  float innerAngle;
  float outerAngle;
  float outerVolume;
};

// IDA Local Type ordinal 13491; PDB kind: struct.
struct soundShaderParms_t::distancesBasedVars_t
{
  float nearMinRange;
  float farMaxRange;
};

// IDA Local Type ordinal 13493; PDB kind: struct.
struct soundShaderParms_t::maxPlayerVars_t
{
  int maxShaders;
  soundMaxPlaybackType_t playbackType;
};

// IDA Local Type ordinal 13494; PDB kind: struct.
struct soundShaderParms_t
{
  float minDistance;
  float maxDistance;
  float distanceFactor;
  float wetMinDistanceOffset;
  float wetMaxDistanceOffset;
  soundShaderParms_t::coneAttenuationVars_t coneAttenuation;
  soundShaderParms_t::distancesBasedVars_t distanceBasedRanges;
  randomValue_t volume;
  float wetVolume;
  randomValue_t pitch;
  float loopFadeInDuration;
  float loopFadeOutDuration;
  float dopplerMultiplier;
  float shakes;
  float minShakeDistance;
  float maxShakeDistance;
  const idDeclTable *shakeFalloff;
  soundShaderGroups_t groups;
  soundChannel_t soundChannel;
  soundShaderFlags_t soundShaderFlags;
  float lowPassMinDistance;
  float lowPassStrength;
  float lfeVolume;
  float centerChannel;
  const idDeclTable *falloff;
  const idDeclTable *wetFalloff;
  float headroom;
  soundShaderParms_t::maxPlayerVars_t maxPlay;
  soundPriority_t priority;
};

// IDA Local Type ordinal 13510; PDB kind: class.
class idSoundShader : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13734.
  virtual ~idSoundShader();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  soundShaderParms_t parms;
  idList<idStrSound,38> soundFiles;
  idList<idSoundSample *,38> entries;
  const idSoundShader *preSound;
  const idSoundShader *postSound;
  const idSoundShader *remoteSound;
  idSoundSample *nextSample;
  idLinkList<idSoundChannel> playingChannels;
};
