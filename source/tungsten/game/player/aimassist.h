#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\aimassist.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15391; PDB kind: class.
class idAimAssist : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15392.
  virtual idTypeInfo *GetType();
  virtual ~idAimAssist();

  idPresentablePtr<idPresentablePlayer> player;
  idAngles angleCorrection;
  float frictionScalar;
  float desiredFrictionScalar;
  float weaponTraceDistance;
  bool lastZoomSnap;
  bool allowZoomSnap;
  bool zoomSnapThisFrame;
  idVec3 zoomSnapAimPoint;
  idPresentablePtr<idPresentableAnimatedEntity> thisFrameEntity;
  idPresentablePtr<idPresentableAnimatedEntity> lastFrameEntity;
  idVec3 thisFrameHitLoc;
  idVec3 lastFrameHitLoc;
  __int16 savedAngle[3];
  __int16 currentAngle[3];
  __int16 savedYaw;
  __int16 savedPitch;
  __int16 currentYaw;
  __int16 currentPitch;
  idClipQuery deferredAimPoint;
  idClipQuery deferredHeadPoint;
};

// IDA Local Type ordinal 20211; PDB kind: struct.
struct aimAssistData_t
{
  bool targetAdhesionEnable;
  bool targetFrictionEnable;
  bool targetAdhesionEnableWhileMoving;
  bool targetZoomSnapEnable;
  float targetValidFovDot;
  float targetMaxDistance;
  float targetSelectionRadius;
  float targetZoomSelectionRadius;
  float targetCoverZoomSelectionRadius;
  float targetHeadShotZoomSelectionRadius;
  float targetAdhesionRadius;
  float targetAdhesionYawSpeedMax;
  float targetAdhesionPitchSpeedMax;
  float targetAdhesionContributionPctMax;
  float targetAdhesionContributionPctMaxZoom;
  float targetAdhesionZoomYawSpeedMax;
  float targetAdhesionZoomPitchSpeedMax;
  float targetFrictionMaxDistance;
  float targetFrictionOptimalDistance;
  float targetFrictionOptimalRadius;
  float targetFrictionRadius;
  float targetFrictionMultiplierMin;
  float targetFrictionMultiplierMax;
  float targetFrictionMultiplierMinZoom;
  float targetFrictionMultiplierMaxZoom;
  bool meleeSnapEnable;
  bool meleeLeftHandEnable;
  int meleeEquipWindow;
  bool meleeLungeEnable;
  float meleeLungeMinDist;
  float meleeLungeMaxDist;
  float meleeLungeMinSpeed;
  float meleeLungeMaxSpeed;
};
