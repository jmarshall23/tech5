#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\md6util.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1870; PDB kind: unknown.
enum idMD6Util::<unnamed_tag> : __int32
{
  FRAME_FIRST = 0x0,
  FRAME_LAST = 0xFFFFFFFF,
};

// IDA Local Type ordinal 19708; PDB kind: class.
class __declspec(align(16)) idMD6Util::idJointCache
{
public:
  idJointMat jointMatrices[256];
  const idDeclAnimWeb *webRef;
  const idDeclMD6 *md6Decl;
  const idMD6Anim *md6anim;
  int frameNum;
  bool validJointCache;
};

// IDA Local Type ordinal 19709; PDB kind: struct.
struct idMD6Util::animDelta_t
{
  idVec3 deltaTranslation;
  idMat3 deltaAxis;
};

// IDA Local Type ordinal 21890; PDB kind: struct.
struct idMD6Util::idAnimWebBlendInfo
{
  __int16 startBlendFrame;
  __int16 endBlendFrame;
};

// IDA Local Type ordinal 21891; PDB kind: class.
class idMD6Util
{
public:
};
