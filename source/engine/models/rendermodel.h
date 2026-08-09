#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\rendermodel.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1725; PDB kind: enum.
enum renderMode_t : __int32
{
  RENDER_MODE_MANUAL = 0x0,
  RENDER_MODE_AUTOMATIC = 0x1,
  RENDER_MODE_BINK = 0x2,
};

// IDA Local Type ordinal 13523; PDB kind: class.
class idRenderModel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13552.
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
  virtual ~idRenderModel();

  __declspec(align(16)) idAtomicString name;
  const char *debugName;
  idVec3 deferredOrigin;
  idMat3 deferredAxis;
  bool useDeferredPosition;
  bool deferredPositionInitialized;
  bool deleteOnSync;
  bool unlinked;
  bool needWriteToSnapshot;
  idRenderModel *nextOnCommitList;
  int needCommitFrameNum;
  idRenderModelCommitted *committed;
  idBounds referenceBounds;
  idRenderModelParms g;
  idStaticParmBlock<32> gameParmBlock;
  idList<idRenderModelSurface,85> surfaces;
  idStaticList<idRenderModel::decalData_t,16> decalData;
};

// IDA Local Type ordinal 13666; PDB kind: struct.
struct __declspec(align(4)) idRenderModel::decalData_t
{
  idHandle<int,enum invalidDecalHandle_t,-1> handle;
  idVec3 relativePos;
  idMat3 relativeAxis;
  idIndex<short,enum invalidJointIndex_t> jointId;
};

// IDA Local Type ordinal 15019; PDB kind: class.
class idStrRenderModel : public idStr
{
public:
};

// IDA Local Type ordinal 15020; PDB kind: class.
class idRenderModelInfo
{
public:
  idRenderModel *model;
  __int8 staticShadowsFromDynamicModel : 1;
  __int8 forceAcceptDimShadows : 1;
  __int8 allowUpShadows : 1;
  __int8 allowHighQualityDimShadows : 1;
  __int8 forceDimShadows : 1;
  __int8 noShadows : 1;
  __int8 noAmbient : 1;
  __int8 allowInline : 1;
  unsigned __int8 : 3;
  __int8 rebakeModel : 1;
  __int8 megatexturedModel : 1;
  __int8 occluder : 1;
  __int8 noLocalLighting : 1;
  __int8 privateLightOnly : 1;
  float maxTexelDensity;
  float maxVisibleRange;
  float fadeVisibilityOver;
  float dimShadowClipZ;
  const idMaterial *customMaterial;
  idVec3 scale;
  idColor color;
  idList<idRenderParm,5> renderParms;
  const idMaterial *parmBlock;
  idStrRenderModel editorModel;
  int traceGroup;
  float radiosityScale;
  float staticReflectionStrength;
  bool ownedByPresentable;
  idRenderModelInfo *next;
};
