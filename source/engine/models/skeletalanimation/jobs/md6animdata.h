#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\jobs\md6animdata.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1998; PDB kind: enum.
enum idMD6AnimData::animFlag_t : __int32
{
  ANIM_FLAG_ADDITIVE = 0x1,
  ANIM_FLAG_USE_FORWARD_TRANSLATION = 0x2,
  ANIM_FLAG_USE_LEFT_TRANSLATION = 0x4,
  ANIM_FLAG_USE_UP_TRANSLATION = 0x8,
  ANIM_FLAG_USE_ROTATION = 0x10,
  ANIM_FLAG_IGNORE_BOUNDS = 0x20,
  ANIM_FLAG_DEFAULTED = 0x40,
  ANIM_FLAG_PROXY = 0x80,
  ANIM_FLAG_RETARGET_ADDITIVE = 0x100,
  ANIM_FLAG_FRAME_ZERO_DELTA = 0x200,
  ANIM_FLAG_HAS_JOINT_DATA = 0x400,
  ANIM_FLAG_HAS_USER_CHANNEL_DATA = 0x800,
  ANIM_FLAG_HAS_ORIGIN_DELTA = 0x1000,
  ANIM_FLAG_INJURED = 0x2000,
  ANIM_FLAG_SCRAMBLE = 0x4000,
  ANIM_FLAG_FACETRACKS_COMPOSITE = 0x8000,
};

// IDA Local Type ordinal 13352; PDB kind: class.
class idMD6AnimData
{
public:
  unsigned int totalSize;
  unsigned __int16 size;
  unsigned __int16 flags;
  unsigned __int16 numFrames;
  unsigned __int16 frameRate;
  unsigned __int16 numFrameSets;
  unsigned __int16 frameSetTblOffset;
  unsigned __int16 frameSetOffsetTblOffset;
  unsigned __int16 numAnimMaps;
  unsigned __int16 constROffset;
  unsigned __int16 constSOffset;
  unsigned __int16 constTOffset;
  unsigned __int16 constUOffset;
  unsigned __int16 nextSize;
  unsigned __int16 jointWeightsOffset;
  float startDelta[12];
  float endDelta[12];
};
