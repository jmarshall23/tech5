#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sound\soundworld.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13516; PDB kind: class.
class idSoundWorld
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13690.
  virtual ~idSoundWorld();
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

};
