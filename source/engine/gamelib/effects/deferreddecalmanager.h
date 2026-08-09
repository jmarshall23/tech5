#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effects\deferreddecalmanager.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14039; PDB kind: struct.
struct deferredDecalParams_t
{
  const idMaterial *decalMat;
  float depth;
  idVec2 size;
  float angle;
  int lifetime;
  int fadetime;
  int fadeInEndTime;
};

// IDA Local Type ordinal 14040; PDB kind: class.
class idDeferredDecalQuery
{
public:
  idClipQuery theQuery;
  deferredDecalParams_t decalParams;
  idVec3 origin;
  idVec3 normal;
};

// IDA Local Type ordinal 14135; PDB kind: class.
class __declspec(align(8)) idDeferredDecalManager
{
public:
  idDeferredDecalQuery lineQueries[16];
  int numLineQueries;
  idClip *clip;
  idRenderModelDecal *decalModel;
};

// IDA Local Type ordinal 15595; PDB kind: struct.
struct __declspec(align(8)) idDeferredFireManager::deferredFire_t
{
  idFireParms fireParms;
  idClipQuery queryHandles[16];
  idTestFireResults fireResults;
  unsigned int handle;
  int numTraces;
};

// IDA Local Type ordinal 15596; PDB kind: class.
class idDeferredFireManager
{
public:
  idDeferredFireManager::deferredFire_t deferredFireBuffers[2][32];
  unsigned int shotCount;
  unsigned int activeBuffer;
};
