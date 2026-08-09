#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\treeanimator.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1527; PDB kind: unknown.
enum idTreeAnimator::<unnamed_tag> : __int32
{
  JOINTS_GAME_REFERENCE = 0x0,
  JOINTS_GAME_FINAL = 0x1,
  JOINTS_DEFERRED_REFERENCE = 0x2,
  JOINTS_DEFERRED_FINAL = 0x3,
  NUM_JOINT_ARRAYS = 0x4,
};

// IDA Local Type ordinal 14058; PDB kind: struct.
struct idTreeAnimator::morphMap_t
{
  unsigned __int8 *map;
  idArray<idVertexBuffer *,2> buffers;
};

// IDA Local Type ordinal 14066; PDB kind: class.
class idTreeAnimator : public idRenderModel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14067.
  virtual void Save(idFile *);
  virtual bool Load(idFile *);
  virtual void SerializeSnapshot(idSerializer *, bool);
  virtual const idDeclSkins *GetSkins();
  virtual idHandle<int,enum invalidDecalHandle_t,-1> *AddDecalFromPoint(idHandle<int,enum invalidDecalHandle_t,-1> *result, const decalParams_t *, const int, const idVec3 *, const idVec3 *, idIndex<short,enum invalidJointIndex_t>);
  virtual bool RemoveDecal(const idHandle<int,enum invalidDecalHandle_t,-1>);
  virtual void RemoveDecals();
  virtual void FreeSurfaces();
  virtual bool CommitSubclass();
  virtual bool UpdateInView(const idRenderView *, const idRenderView *, idRenderModelUpdateTools *);
  virtual const idList<sourceSurface_t,5> *GetSourceSurfaces();
  virtual ~idTreeAnimator();

  const idDeclMD6 *decl;
  idList<bool,17> meshVisibility;
  __int16 morphSkin;
  idIndex<short,enum invalidJointIndex_t> skipJointForBounds;
  float initialMorphValue;
  int currentDeferred;
  md6AnimCommand_t *commands;
  idList<idMD6Blend::jointMod_t,17> jointMods[2];
  idMD6Blend::blendParms_t *blendParms;
  idJointMat *joints[4];
  idList<float,17> userChannels[2];
  md6OriginDelta_t *originDelta[2];
  int lastBlendTime;
  unsigned __int8 : 1;
  __int8 useDualQuatSkinning : 1;
  __int8 skipSerialization : 1;
  __int8 updateMorphBuffers : 1;
  __int8 calcRefBoundsFromJoints : 1;
  __int8 originDeltaLookAhead : 1;
  __int8 clearOriginTransform : 1;
  __int8 hasDeferredJoints : 1;
  idBounds frameBounds;
  idBounds normalizedBounds;
  idBounds translatedBounds;
  idArray<idJointBuffer,4> jointBuffers;
  idList<float,5> userChannelBuffers[4];
  int deferredJobJointBuffer;
  int nextRenderThreadJointBuffer;
  int renderThreadJointBuffer;
  idList<idTreeAnimator::morphMap_t,16> morphMaps;
  int currentMorphBuffer;
  idList<idUserChannelExpression,5> wrinkleMapExpressions;
};

// IDA Local Type ordinal 21901; PDB kind: struct.
struct idTreeAnimator::meshHandle_t
{
  idList<int,5> indices;
  idStr name;
};
