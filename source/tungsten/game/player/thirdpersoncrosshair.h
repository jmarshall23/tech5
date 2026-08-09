#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\thirdpersoncrosshair.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1176; PDB kind: unknown.
enum idThirdPersonCrosshair::<unnamed_tag> : __int32
{
  FL_NONE = 0x0,
  FL_AUTOCENTER = 0x1,
  FL_TARGETLOCK = 0x2,
  FL_SHOOTTOLOCK = 0x4,
  FL_CHASEGOAL = 0x8,
  FL_DELTAANGLES = 0x10,
  FL_ROTATABLE = 0x20,
  FL_IGNOREPITCH = 0x40,
  FL_ALIGNTOTARGET = 0x80,
  FL_ALL = 0xFF,
};

// IDA Local Type ordinal 14741; PDB kind: class.
class idThirdPersonCrosshair
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14742.
  virtual ~idThirdPersonCrosshair();

  idThirdPersonCrosshair::targetTrace_t deferredTargetTrace[10];
  idClipQuery deferredLosingTargetTrace;
  idPresentablePtr<idPresentable> presentable;
  idVec3 baseForward;
  idTreeAnimator *treeAnimator;
  tagData_t tagData;
  idAngles minAngles;
  idAngles maxAngles;
  idAngles angleSpeed;
  idVec3 origin;
  idMat3 axis;
  idVec3 forward;
  trace_t trace;
  idAngles angles;
  idAngles absAngles;
  idAngles deltaAngles;
  idAngles goalAngles;
  float goalSpeed;
  idAngles lastGoalAngles;
  bool skipTargetHighlight;
  idPresentablePtr<idPresentable> target;
  idPresentablePtr<idPresentable> prevTarget;
  int visualType;
  int flags;
  bool autoAcquire;
  int timeToRetainLostTarget;
  int lostTargetTime;
  int flashTime;
  bool firing;
  float joy_extent;
  bool targetLocked;
  bool targetCanLock;
  int targetId;
  int targetAcquiringTime;
  idPresentablePtr<idPresentable> acquiringTarget;
  idColor visColor;
  float visRadius;
  float visRadiusDir;
  bool weaponCanFire;
  const idDeclWeapon *declWeapon;
  const idDeclAmmo *declAmmo;
  bool playedLockSound;
  int lastAcquireSoundTime;
  idRenderModelStatic *crosshairModel;
  idStaticList<idPresentablePtr<idPresentable>,16> validTargets;
  bool crosshairEnabled;
  float crosshairPredictionRadius;
  idClipQuery deferredTrace1;
  idClipQuery deferredTrace2;
  idGatherQuery lockableBoundsQuery;
};

// IDA Local Type ordinal 14743; PDB kind: struct.
struct idThirdPersonCrosshair::targetTrace_t
{
  idClipQuery trace;
  idPresentablePtr<idPresentable> presentable;
  float dot;
};
