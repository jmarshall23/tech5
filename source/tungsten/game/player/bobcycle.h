#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\bobcycle.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1185; PDB kind: enum.
enum idBobCycle::footStep_t : __int32
{
  FOOTSTEP_NONE = 0x0,
  FOOTSTEP_RIGHT = 0x1,
  FOOTSTEP_LEFT = 0x2,
};

// IDA Local Type ordinal 15376; PDB kind: class.
class idBobCycle
{
public:
  int stepUpTime;
  float stepUpDelta;
  int landChange;
  int landTime;
  int lastUpdateTime;
  idAngles viewBobAngles;
  idVec3 viewBob;
  idAngles surfaceTiltTargetAngles;
  idAngles handsAngles;
  idVec3 handsOffset;
  int currentStep;
  float cycle;
  float offset_base[2];
  idParametricDecay offset_decay[2];
  bool moving;
  idInterpolate<float> idleBlend;
  int sideMove;
  int bobFoot;
  float bobFrac;
  float bobfracsin;
  int bobCycle;
  float lagretain;
  idVec3 swayOffset;
  int tzero[2];
  float decay[2];
  bool crouching;
  bool instantCrouchChange;
  bool decay_active;
  idParametricDecay crouch_decay;
  float accelRotValue;
  float strafeRotValue;
  float crouchWeaponDip;
  float currentScale;
  float baseScale;
  float targetScale;
  float scaleRate;
  int scaleStartTime;
  int scaleEndTime;
  idBobCycle::footStep_t footStep;
  float coverIndicationBlender;
  float zoomBlendOut;
  idVec2 currentLeanScale;
};
