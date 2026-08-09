#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\discreteanimation\rendermodelmanyboxes.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16034; PDB kind: struct.
struct idRenderModelManyBoxes::box_t
{
  idVec3 position;
  idMat3 orientation;
  float radius;
};

// IDA Local Type ordinal 16036; PDB kind: class.
class __declspec(align(8)) idRenderModelManyBoxes : public idRenderModel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16037.
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
  virtual ~idRenderModelManyBoxes();

  int gameTime;
  const idMaterial *material;
  idList<idRenderModelManyBoxes::box_t,5> boxes;
  idVertexBuffer vertexBuffers[2];
  idTriangles triangles;
  idIndexBuffer indexBuffer;
};
