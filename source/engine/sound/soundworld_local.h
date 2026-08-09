#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sound\soundworld_local.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13694; PDB kind: struct.
struct idSoundWorldLocal::idDuckLayer
{
  idArray<float,25> fromVolumes;
  const idDeclDuck *decl;
  int startFadeStart;
  int startFadeEnd;
  int endFadeStart;
  int endFadeEnd;
  float blendAlpha;
};

// IDA Local Type ordinal 13723; PDB kind: class.
class __declspec(align(4)) idSoundWorldLocal : public idSoundWorld
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13724.
  virtual ~idSoundWorldLocal();
  virtual void StopAllSounds();
  virtual idSoundEmitter *AllocSoundEmitter();
  virtual int NumEmitters();
  virtual idSoundEmitter *EmitterForIndex(int);
  virtual void PlaceListener(const idVec3 *, const idMat3 *, const idVec3 *, const int);
  virtual void SetNumListeners(int);
  virtual int FindEnvironment(const idVec3 *);
  virtual bool SetEnvironmentParams(int, const soundEnvironment_t *);
  virtual bool GetEnvironmentParams(int, soundEnvironment_t *);
  virtual void OverrideEnvironmentParams(const soundEnvironment_t *, int);
  virtual void BlendEnvironmentParams(const soundEnvironment_t *, float, int);
  virtual int FindDoor(const idVec3 *);
  virtual void SetDoor(int, float);
  virtual float CurrentShakeAmplitude(int);
  virtual int PlayPositionedShaderDirectly(const idSoundShader *, const idVec3 *, const idMat3 *, float);
  virtual int PlayGlobalShaderDirectly(const idSoundShader *, soundChannel_t, float);
  virtual void Fade(soundShaderGroups_t, float, int);
  virtual void Duck(const idDeclDuck *, int, int, int);
  virtual void DuckBlend(const idDeclDuck *, float);
  virtual void DrawDebug(idRenderWorld *);
  virtual void SaveGame(idFile *);
  virtual bool LoadGame(idFile *);
  virtual void WriteToSnapshot(idSnapShot *, const idSnapShot *);
  virtual void ReadFromSnapshot(idSnapShot *, const idSnapShot *);
  virtual bool Trace(const idVec3 *, const idVec3 *);
  virtual void Pause();
  virtual void UnPause();
  virtual int GetSoundTime();

  idSoundFade volumeFade;
  idArray<idSoundFade,25> groupFade;
  idStaticList<idSoundWorldLocal::idDuckLayer,4> ducks;
  idRenderWorld *renderWorld;
  idSoundBSPFile sbspFile;
  idList<soundEnvironment_t,38> environments;
  idList<float,38> doors;
  idArray<listener_t,2> listeners;
  int listenerIndex;
  int numListeners;
  float currentCushionDB;
  idList<idSoundEmitterLocal *,38> emitters;
  idSoundEmitter *localSound;
  idSoundEmitter *tinnitusEmitter;
  idSoundEmitter *positionedEmitters[32];
  idBlockAlloc<idSoundEmitterLocal,16,38> emitterAllocator;
  idBlockAlloc<idSoundChannel,16,38> channelAllocator;
  idSoundFade pauseFade;
  int pausedTime;
  int accumulatedPauseTime;
  bool isPaused;
};
