#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\rendermodeldecal.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13546; PDB kind: struct.
struct idRenderModelDecal::decalInfo_t
{
  int startTime;
  int lifeTime;
  const idMaterial *decalMtr;
  int fadeOutTime;
  int fadeInTime;
  float scaleBiasX;
  float scaleBiasY;
  float depth;
  idVec3 pos;
  idMat3 axis;
  idVec2 size;
  float sizeScale;
  bool quad;
  idHandle<int,enum invalidDecalHandle_t,-1> handle;
};

// IDA Local Type ordinal 13547; PDB kind: struct.
struct __declspec(align(4)) idRenderModelDecal::tireDecalInfo_t
{
  int startTime;
  int lifeTime;
  const idMaterial *decalMtr;
  int fadeTime;
  float scaleBiasX;
  float scaleBiasY;
  idVec3 pos;
  idVec3 dir;
  float depth;
  idVec3 corners[4];
  idVec3 left;
  float halfWidth;
  float halfHeight;
  bool markStart;
  bool markEnd;
};

// IDA Local Type ordinal 13550; PDB kind: class.
class __declspec(align(8)) idRenderModelDecal : public idRenderModel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34034.
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
  virtual ~idRenderModelDecal();

  idRenderModelDecal::decalInfo_t *decals;
  int decalRange[2];
  idRenderModelDecal::tireDecalInfo_t *tireDecals;
  int tireDecalRange[2];
  int gameTime;
  idRandom2 random;
  int latchedTime;
  int latchedDecalRange[2];
  int latchedTireDecalRange[2];
  idVertexBuffer vertexBuffer[2];
  idIndexBuffer indexBufferBoxes;
  idIndexBuffer indexBufferQuads;
  bool usesPreAllocatedBuffer;
  idTriangles *triangles;
  const idDeclRenderParm *parmPositionToLocalBoxSpace[4];
};
