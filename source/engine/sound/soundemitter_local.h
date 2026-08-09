#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sound\soundemitter_local.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13714; PDB kind: class.
class __declspec(align(4)) idSoundEmitterLocal : public idSoundEmitter
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13729.
  virtual int Index();
  virtual void Free(bool);
  virtual void Reset();
  virtual void UpdateEmitter(const idVec3 *, const idMat3 *, const idVec3 *, int);
  virtual int StartSound(soundChannel_t, const idSoundShader *, const soundShaderParms_t *);
  virtual void ModifySound(soundChannel_t, const idSoundShader *, const soundShaderParms_t *);
  virtual void StopSound(soundChannel_t);
  virtual void SetVolume(soundChannel_t, float);
  virtual void SetPitch(soundChannel_t, float);
  virtual void FadeSound(soundChannel_t, float, float, float, bool);
  virtual void FadePitch(soundChannel_t, float, float, float);
  virtual bool IsCurrentlyPlaying(soundChannel_t);
  virtual void SetVolumeAdjustment(float);
  virtual void ClearVolumeAdjustment();
  virtual float GetVolumeAdjustment();
  virtual const idSoundShader *GetCurrentSoundShader(soundChannel_t);
  virtual idSoundSample *GetCurrentSample(soundChannel_t);
  virtual idTypesafeNumber<int,enum millisecondUnique_t> *GetCurrentSampleTime(idTypesafeNumber<int,enum millisecondUnique_t> *result, soundChannel_t);
  virtual idTypesafeNumber<int,enum millisecondUnique_t> *GetRemainingSampleTime(idTypesafeNumber<int,enum millisecondUnique_t> *result, soundChannel_t);
  virtual bool GetDebugInfo(int, soundDebugInfo_t *);
  virtual void SetDebugName(const char *);
  virtual const char *GetDebugName();
  virtual const idVec3 *GetPosition();
  virtual ~idSoundEmitterLocal();

  idSoundWorldLocal *soundWorld;
  int index;
  bool canFree;
  float volumeAdjustment;
  idStaticList<idSoundChannel *,16> channels;
  int areaNum;
  idVec3 origin;
  idMat3 axis;
  idVec3 velocity;
  int emitterId;
  float distance;
  float occludedDistance;
  idVec3 occludedDirection;
  float occlusion;
  soundOcclusionParms_t *occlusionParms;
  const char *debugName;
  bool occlusionValidLastUpdate;
};
