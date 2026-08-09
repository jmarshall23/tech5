#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\physics\clipmodel.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1525; PDB kind: enum.
enum idClipModelInfo::clipModelType_t : __int32
{
  CLIPMODEL_NONE = 0x0,
  CLIPMODEL_RENDERMODEL = 0x1,
  CLIPMODEL_CUSTOM = 0x2,
  CLIPMODEL_BOX = 0x3,
  CLIPMODEL_CYLINDER = 0x4,
  CLIPMODEL_CONE = 0x5,
  CLIPMODEL_BOUNDINGBOX = 0x6,
};

// IDA Local Type ordinal 1973; PDB kind: enum.
enum clipMode_t : __int32
{
  CLIPMODE_INTERSECT = 0x0,
  CLIPMODE_UNION = 0x1,
  CLIPMODE_DIFFERENCE = 0x2,
  CLIPMODE_XOR = 0x3,
};

// IDA Local Type ordinal 14041; PDB kind: class.
class idClipModel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14042.
  virtual ~idClipModel();

  __declspec(align(8)) bool enabled;
  bool deleted;
  int entityNumber;
  int ownerNumber;
  int physicsId;
  int bodyId;
  int bodyMask;
  idVec3 origin;
  idMat3 axis;
  idBounds bounds;
  idBounds absBounds;
  int contents;
  idCollisionModel *collisionModel;
  idList<int,13> traceModels;
  idTreeAnimator *animatedModel;
  idClip *clip;
  clipLink_t *clipLinks;
  idCollisionQuery collisionQuery;
  int touchCount;
  idClipModel *nextDeleted;
  idAASClipLink *aasLinks[8];
};

// IDA Local Type ordinal 15173; PDB kind: class.
class idStrClipModel : public idAtomicString
{
public:
};

// IDA Local Type ordinal 15174; PDB kind: class.
class idClipModelInfo
{
public:
  idClipModelInfo::clipModelType_t type;
  idVec3 size;
  idVec3 offset;
  int numSides;
  idStrClipModel clipModelName;
  bool clipShrink;
  bool allowInline;
  bool softObstacle;
  const idMaterial *overrideClipMaterial;
};

// IDA Local Type ordinal 22949; PDB kind: struct.
struct cbp_model_s
{
  int state[16];
  int count0[16];
  int count1[16];
};
