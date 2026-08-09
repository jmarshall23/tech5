#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\focustracker.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15379; PDB kind: class.
class idFocusTracker
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15380.
  virtual ~idFocusTracker();
  virtual float GetTraceDistance();
  virtual bool UpdateCursor(idActor *, idEntity *, const idFocusTrace *);
  virtual void UpdateCursorFlash(idActor *);
  virtual float GetFocusDistance(const idPresentablePlayer *, const idEntity *);
  virtual float GetFocusDistance_2(const idActor *, const idEntity *);
  virtual float GetUsableDistance(const idActor *, const idEntity *);

  __declspec(align(8)) float traceDistance;
  usercmd_t usercmd;
  idEntityPtr<idEntity> focusUsable;
  idEntityPtr<idEntity> focusEntity;
  idEntityPtr<idEntity> gatherPointEntity;
  idEntityPtr<idEntity> focusEntityOverride;
  idPresentablePtr<idPresentable> focusPresentable;
  int cursorId;
  int clearFocusTime;
  int focusedEntityFlags;
  int traceModelIndex;
  int useButtonOverride;
  idFocusTrace focusTrace;
  idCrosshairInfo crosshairInfo;
  usableState_t usableState;
  bool overFriendly;
  takedownMode_t overTakedownTarget;
  idVec3 gatherPointEndPos;
  trace_t pointTraceResult;
  bool validGatherPointResult;
  bool validPointResult;
};

// IDA Local Type ordinal 15381; PDB kind: class.
class idFocusTracker_Player : public idFocusTracker
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15382.
  virtual ~idFocusTracker_Player();
  virtual float GetTraceDistance();
  virtual bool UpdateCursor(idActor *, idEntity *, const idFocusTrace *);
  virtual void UpdateCursorFlash(idActor *);
  virtual float GetFocusDistance(const idPresentablePlayer *, const idEntity *);
  virtual float GetFocusDistance_2(const idActor *, const idEntity *);
  virtual float GetUsableDistance(const idActor *, const idEntity *);

};

// IDA Local Type ordinal 22165; PDB kind: class.
class idFocusTracker_AI : public idFocusTracker
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22166.
  virtual ~idFocusTracker_AI();
  virtual float GetTraceDistance();
  virtual bool UpdateCursor(idActor *, idEntity *, const idFocusTrace *);
  virtual void UpdateCursorFlash(idActor *);
  virtual float GetFocusDistance(const idPresentablePlayer *, const idEntity *);
  virtual float GetFocusDistance_2(const idActor *, const idEntity *);
  virtual float GetUsableDistance(const idActor *, const idEntity *);

};
