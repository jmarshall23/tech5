#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\focusinfo.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16729; PDB kind: class.
class __declspec(align(4)) idFocusInfo
{
public:
  idWanderingAim wanderingAim;
  idEntityPtr<idEntity const > focusEntity;
  aimPoint_t aimPoint;
  const idDeclTrackingParms *declTrackingParms;
  int trackingParmsIndex;
  int focusTimeout;
  idVec3 idealFocusPoint;
  idVec3 curFocusPoint;
  idVec3 offset;
  idVec3 explicitOffset;
  idAngles explicitOffsetAngles;
  idAimTracker aimTracker;
  aiFoci_t fociType;
  aiFocus_t focusType;
  int defaultHeadTrackGroup;
  idAnimator_TrackerBase *animators[2];
  int curAnimatorIndex;
  idMat3 wsReferenceAxis;
  bool enableTracking;
  bool suppressTracking;
  bool keepFocusInView;
  bool hasExplicitFocusPoint;
  bool lockTracking;
};
