#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\md6model.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2180; PDB kind: enum.
enum idMD6Node::nodeType_t : __int32
{
  NODE_BRANCH = 0x0,
  NODE_LEAF_PAUSE = 0x1,
  NODE_LEAF_PLAY = 0x2,
  NODE_BLEND_BRANCH = 0x3,
  NODE_BLENDA_BRANCH = 0x4,
  NODE_FUSION_BRANCH = 0x5,
  NODE_BEST_LEAF = 0x6,
  NODE_TAG_FILTER = 0x7,
  NODE_NONE = 0xFF,
};

// IDA Local Type ordinal 13362; PDB kind: class.
class idMD6Model : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13363.
  virtual ~idMD6Model();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  idStr filename;
  unsigned int timestamp;
  unsigned int skelTimestamp;
  idBounds defaultBounds;
  bool remapForSkinning;
  unsigned int skinChecksum;
  idStr morphSkinName;
  int morphSkin;
  int numMeshesBeforeSplitting;
  idList<idMD6Mesh *,19> meshes;
  idList<unsigned char,19> jointRemap;
  idList<sourceSurface_t,5> sourceSurfaces;
  idList<idMaterial const *,5> materials;
  const idMD6Skel *skeleton;
  idVec3 minBoundsExpansion;
  idVec3 maxBoundsExpansion;
};

// IDA Local Type ordinal 13595; PDB kind: struct.
struct fm_model_t
{
  int numTreeNodes;
  int numSubTrees;
  fm_treeNode_t *treeNodes;
  fm_subTree_t *subTrees;
};

// IDA Local Type ordinal 13617; PDB kind: struct.
struct dm_model_t
{
  int numTreeNodes;
  int numSubTrees;
  dm_treeNode_t *treeNodes;
  dm_subTree_t *subTrees;
};

// IDA Local Type ordinal 14228; PDB kind: class.
class idMD6Node
{
public:
  unsigned __int8 type;
};
