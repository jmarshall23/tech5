#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effects\impactmanager.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14157; PDB kind: struct.
struct idImpactManager::impactState_t
{
  idRenderModelParticle *pmodel;
  int startTime;
  int endTime;
};

// IDA Local Type ordinal 14159; PDB kind: struct.
struct idImpactManager::impactBindState_t
{
  bool bindToParent;
  idVec3 relOrg;
  idMat3 relRot;
};

// IDA Local Type ordinal 14161; PDB kind: struct.
struct idImpactManager::impactBufferItem_t
{
  idVec3 pos;
  idMat3 axis;
  const idDeclParticle *prt;
  bool bindToParent;
  int playerIndex;
  int serverTime;
};

// IDA Local Type ordinal 14162; PDB kind: class.
class idImpactManager
{
public:
  idList<idImpactManager::impactState_t,5> impacts;
  idList<idImpactManager::impactBindState_t,5> impactBinds;
  int next;
  idRandom2 random;
  bool initialized;
  idEffectsModelManager *effectsModelManager;
  idImpactManager::impactBufferItem_t impactBuffer[16];
  int impactBufferPos;
  int serializeImpactCount;
  int localPlayerIndex;
};
