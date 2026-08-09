#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effects\fxmanager.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2791; PDB kind: enum.
enum idFXManager::fxActionCallType_t : __int32
{
  FXACTION_START = 0x0,
  FXACTION_STOP = 0x1,
  FXACTION_STOP_ALL = 0x2,
  FXACTION_MAX = 0x3,
};

// IDA Local Type ordinal 14217; PDB kind: struct.
struct idFXManager::fxActionCall_t
{
  idVec3 org;
  idMat3 axis;
  fxCondition_t condition;
  int time;
  fxExtraCondition_t extraCondition;
  int tagIdx;
  idFXManager::fxActionCallType_t actionType;
  bool immediate;
  int viewCallbacksID;
};

// IDA Local Type ordinal 14218; PDB kind: class.
class idFXManager
{
public:
  bool initialized;
  const idDeclFX *fxDecl;
  idGameLibEffects *gameLibEffects;
  idTreeAnimator *ta;
  idRenderWorld *rw;
  idVec4 systemColor;
  idRandom2 random;
  fxEmitterSound_t soundInfo;
  idList<idFXAction,109> actions;
  idList<fxActionState_t,109> actionState;
  bool remote;
  int allowSurfaceOnlyInViewID;
  int suppressSurfaceInViewID;
  int viewCallbacksID;
  int declChangeId;
  idMat3 externalRotation;
  idVec3 externalPosition;
  bool hasExternalPositionAndRotation;
  idFXManager::fxActionCall_t actionBuffer[8];
  int actionBufferPos;
  int serializeActionCount;
};

// IDA Local Type ordinal 23462; PDB kind: struct.
struct __declspec(align(4)) idFXManager::UpdateActions::__l79::viewcallbackInfo_t
{
  idVec3 viewOrg;
  idMat3 viewAxis;
  float distSQ;
  bool inRange;
};
