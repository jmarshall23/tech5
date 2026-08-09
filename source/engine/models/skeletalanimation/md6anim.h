#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\md6anim.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3121; PDB kind: enum.
enum idMD6Anim::CompressAnim::__l2::local_t::channel_t : __int32
{
  ROTATION_CHANNEL = 0x0,
  SCALE_CHANNEL = 0x1,
  TRANSLATION_CHANNEL = 0x2,
  USER_CHANNEL = 0x3,
};

// IDA Local Type ordinal 13357; PDB kind: class.
class idMD6Anim : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13358.
  virtual ~idMD6Anim();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  idAtomicString skelName;
  idMD6AnimData *animData;
  idMD6PhaseTrack phaseTrack;
  idBoundsShort translatedBounds;
  idBoundsShort normalizedBounds;
  idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> jointConversionHandle;
  idHandle<unsigned short,enum invalidCrc_t,65535> jointConversionChecksum;
  unsigned int timestamp;
  unsigned int phaseTrackTimestamp;
  unsigned int settingsTimestamp;
  int timeCode;
  idVec3 origWorldPos;
  idAngles origWorldRot;
  idVec3 origWorldScale;
  __int16 startFrameOffset;
  __int16 endFrameOffset;
};

// IDA Local Type ordinal 21929; PDB kind: struct.
struct idMD6Anim::animationSettings_t
{
  float errorTolerance;
  int startFrameOffset;
  int endFrameOffset;
  bool removeOrigin;
  bool useForwardTranslation;
  bool useLeftTranslation;
  bool useUpTranslation;
  bool useRotation;
  bool retargetAdditive;
  bool facetracksComposite;
  bool frameZeroDelta;
};

// IDA Local Type ordinal 23287; PDB kind: struct.
struct idMD6Anim::CompressAnim::__l2::local_t
{
};

// IDA Local Type ordinal 23288; PDB kind: struct.
struct idMD6Anim::RewriteText::__l166::helper_t
{
};
