#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effects\viewcallbacks.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15149; PDB kind: class.
class idViewCallbacks
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15150.
  virtual const char *GetName();
  virtual int GetViewID();
  virtual void GetPosition(idVec3 *, idMat3 *);
  virtual void GetViewPosition(idVec3 *, idMat3 *);
  virtual void ApplyScreenShake(const float, const idAngles *, const idVec3 *);
  virtual void ApplyControllerShake(const float, const float, const float, const float);
  virtual void ApplyDynEnvOverride(const idDeclEnv *, const float);
  virtual void ApplyDynEnvParmOverride(const idDeclRenderParm *, const idVec4 *, const bool, const float);
  virtual void ApplyRadialBlur(const idVec3 *, const float, const float, const float, const float, const float);
  virtual int AddScreenParticle(idRenderModel *, const float);
  virtual void RemoveScreenParticle(const int, const int);

};

// IDA Local Type ordinal 15330; PDB kind: class.
class idPlayerViewCallbacks : public idViewCallbacks
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15329.
  virtual const char *GetName();
  virtual int GetViewID();
  virtual void GetPosition(idVec3 *, idMat3 *);
  virtual void GetViewPosition(idVec3 *, idMat3 *);
  virtual void ApplyScreenShake(const float, const idAngles *, const idVec3 *);
  virtual void ApplyControllerShake(const float, const float, const float, const float);
  virtual void ApplyDynEnvOverride(const idDeclEnv *, const float);
  virtual void ApplyDynEnvParmOverride(const idDeclRenderParm *, const idVec4 *, const bool, const float);
  virtual void ApplyRadialBlur(const idVec3 *, const float, const float, const float, const float, const float);
  virtual int AddScreenParticle(idRenderModel *, const float);
  virtual void RemoveScreenParticle(const int, const int);

  idPresentablePlayer *self;
};
