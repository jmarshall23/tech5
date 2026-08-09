#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\water\rendermodelwatersurface.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18865; PDB kind: struct.
struct idRenderModelWaterSurface::waterSimParms_t
{
  float spacing;
  float damping;
  float speed;
  float timeStep;
  idBounds waterBounds;
};

// IDA Local Type ordinal 18866; PDB kind: class.
class __declspec(align(8)) idRenderModelWaterSurface : public idRenderModel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18867.
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
  virtual ~idRenderModelWaterSurface();

  idWaterSurfaceSim *waterSim;
  idVertexBuffer vertexBuffer[3];
  idIndexBuffer indexBuffer;
  idDrawVert *deferredVerts;
  int currentIndex;
  deferredWaterBlockGenParms_t *waterGenBlockParms;
  idRenderModelWaterSurface::waterSimParms_t waterSimParms;
  const idMaterial *material;
};
