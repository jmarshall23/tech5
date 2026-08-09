#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\cloth\rendermodelcloth.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1881; PDB kind: enum.
enum idRenderModelCloth::idClothType_t : __int32
{
  CLOTH_INVALID = 0x0,
  CLOTH_GENERATED = 0x1,
  CLOTH_FLAG_SQUARE = 0x2,
  CLOTH_FLAG_TRIANGLE = 0x3,
  CLOTH_TARP_SQUARE = 0x4,
  CLOTH_TARP_TRIANGLE = 0x5,
  MAX_CLOTH_TYPE = 0x6,
};

// IDA Local Type ordinal 2519; PDB kind: enum.
enum idRenderModelCloth::clothAttachInfo_t::idClothAnchorType_t : __int32
{
  ANCHOR_INVALID = 0x0,
  ANCHOR_CORNER1 = 0x1,
  ANCHOR_CORNER2 = 0x2,
  ANCHOR_CORNER3 = 0x3,
  ANCHOR_CORNER4 = 0x4,
  ANCHOR_MID1 = 0x5,
  ANCHOR_MID2 = 0x6,
  ANCHOR_MID3 = 0x7,
  ANCHOR_MID4 = 0x8,
  ANCHOR_CENTER = 0x9,
  ANCHOR_DEFINED = 0xA,
  MAX_ANCHOR_TYPE = 0xB,
};

// IDA Local Type ordinal 19771; PDB kind: struct.
struct __declspec(align(4)) idRenderModelCloth::clothAttachInfo_t
{
  idVec3 point;
  idRenderModelCloth::clothAttachInfo_t::idClothAnchorType_t clothAnchorType;
  int row;
  int col;
  bool tempAnchor;
};

// IDA Local Type ordinal 19773; PDB kind: class.
class __declspec(align(16)) idRenderModelCloth : public idRenderModel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19774.
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
  virtual ~idRenderModelCloth();

  idClothSim *clothSimulation;
  idVertexBuffer vertexBuffer[3];
  idIndexBuffer indexBuffer;
  idDrawVert *deferredVerts;
  int numVerts;
  int currentIndex;
  idBounds *clothBounds;
  clothParms_t *clothParms;
  bool rect;
  const idDeclCloth *clothSystem;
  idRenderModelCloth::idClothType_t clothType;
  idList<idRenderModelCloth::clothAttachInfo_t,5> attachPoints;
  idList<idVec4,5> collisionSpheres;
  int width;
  int height;
  float vSpacing;
  float hSpacing;
};
