#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\jobs\md6blend.h
// Recovered logical types: 15
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1040; PDB kind: enum.
enum idMD6Blend::blendOp_t : __int32
{
  BOP_NO = 0x0,
  BOP_LERP = 0x1,
  BOP_REF_LERP = 0x2,
  BOP_ADD_LEFT = 0x3,
  BOP_ADD_RIGHT = 0x4,
  BOP_SUB_LEFT = 0x5,
  BOP_SUB_RIGHT = 0x6,
  BOP_BLEND = 0x7,
  BOP_BLENDA = 0x8,
  BOP_FUSION = 0x9,
  BOP_MAX = 0xA,
};

// IDA Local Type ordinal 1041; PDB kind: enum.
enum idMD6Blend::originBlend_t : __int32
{
  ORIGINBLEND_BRANCH = 0x0,
  ORIGINBLEND_LEFT = 0x1,
  ORIGINBLEND_RIGHT = 0x2,
  ORIGINBLEND_DEFAULT = 0x0,
  ORIGINBLEND_SOURCE = 0x1,
  ORIGINBLEND_DEST = 0x2,
  ORIGINBLEND_MAX = 0x3,
};

// IDA Local Type ordinal 2538; PDB kind: unknown.
enum idMD6Blend::jointMod_t::<unnamed_tag> : __int32
{
  DRIVER_MODEL = 0x1,
  DRIVER_ROTATION = 0x2,
  DRIVER_SCALE = 0x4,
  DRIVER_TRANSLATION = 0x8,
  DRIVER_USERCHANNEL = 0x10,
  DRIVER_OVERRIDE = 0x20,
  POSE_REFERENCE = 0x40,
  POSE_FINAL = 0x80,
};

// IDA Local Type ordinal 13314; PDB kind: struct.
struct idMD6Blend::configInfo_t
{
  float visualOffset[4];
};

// IDA Local Type ordinal 14048; PDB kind: struct.
const struct idMD6Blend::jointMod_t
{
  float mat[12];
  float s[3];
  idIndex<short,enum invalidJointIndex_t> joint;
  unsigned __int16 flags;
};

// IDA Local Type ordinal 14050; PDB kind: struct.
struct md6BlendInfo_t
{
  unsigned __int8 op;
  unsigned __int8 filterGroup;
  unsigned __int8 originBlend;
  unsigned __int8 pad;
  float currentAlpha;
};

// IDA Local Type ordinal 14054; PDB kind: struct.
struct idMD6Blend::blendParms_t
{
  const idMD6SkelData *skeleton;
  const idMD6Blend::configInfo_t *config;
  const md6AnimCommand_t *cmds;
  const idMD6Blend::jointMod_t *mods;
  const float *invertedBasePose;
  const float *invertedBasePoseQuat;
  const unsigned __int8 *jointRemap;
  unsigned int numCmds;
  unsigned int numMods;
  unsigned int clearOriginTransform;
  unsigned int flags;
  idIndex<short,enum invalidJointIndex_t> boundsSkipJoint;
  float *referencePose;
  float *finalPose;
  float *renderPose;
  float *userChannels;
  md6OriginDelta_t *originDelta;
};

// IDA Local Type ordinal 14249; PDB kind: class.
class __declspec(align(4)) idMD6BlendBranch : public idMD6BlendBranch_Base
{
public:
  idList<float,30> currentCoordinate;
  idList<idIndex<short,enum invalidUserChannelIndex_t>,30> userChannelIndices;
  idList<float,30> activeCoordinate;
  idList<int,30> activeIndices;
  idList<idMD6Branch,30> branchList;
  unsigned __int8 numDimensions;
  bool isAngleWrapped;
};

// IDA Local Type ordinal 21622; PDB kind: class.
class idMD6BlendBranch::idSearch_AlphaNodePair : public idSearch_Binary<idPair<float,idMD6Node *>,idMD6BlendBranch::idSearch_AlphaNodePair>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21623.
  virtual ~idSearch_AlphaNodePair();
  virtual int Search(const idPair<float,idMD6Node *> *, unsigned int, const idPair<float,idMD6Node *> *);
  virtual int Search_FirstGreater(const idPair<float,idMD6Node *> *, const int, const idPair<float,idMD6Node *> *);
  virtual int Search_FirstGreaterEqual(const idPair<float,idMD6Node *> *, const int, const idPair<float,idMD6Node *> *);
  virtual int Search_LastLess(const idPair<float,idMD6Node *> *, const int, const idPair<float,idMD6Node *> *);
  virtual int Search_LastLessEqual(const idPair<float,idMD6Node *> *, const int, const idPair<float,idMD6Node *> *);

};

// IDA Local Type ordinal 21643; PDB kind: class.
class idMD6Blend
{
public:
};

// IDA Local Type ordinal 21644; PDB kind: struct.
struct idMD6Blend::frameOffsets_t
{
  unsigned __int8 leftFrameOffset[256];
  unsigned __int8 rightFrameOffset[256];
  unsigned __int16 leftKeyOffset[256];
  unsigned __int16 rightKeyOffset[256];
};

// IDA Local Type ordinal 21645; PDB kind: struct.
struct idMD6Blend::doubleStack_t
{
  char *start;
  char *end;
  char *top;
  char *bot;
};

// IDA Local Type ordinal 23291; PDB kind: struct.
struct idMD6Blend::ExecuteCommandsInternal::__l2::local_t
{
};

// IDA Local Type ordinal 23292; PDB kind: struct.
struct idMD6Blend::TransformLocalJointsToModelMatrices::__l30::local_t
{
};

// IDA Local Type ordinal 23293; PDB kind: struct.
struct idMD6Blend::ApplyAnimMods::__l2::jointQuat_t
{
  float r[4];
  float s[4];
  float t[4];
};
