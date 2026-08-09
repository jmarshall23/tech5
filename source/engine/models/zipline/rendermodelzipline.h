#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\zipline\rendermodelzipline.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18808; PDB kind: class.
class __declspec(align(16)) idRenderModelZipline : public idRenderModel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18809.
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
  virtual ~idRenderModelZipline();

  const idMaterial *material;
  int splineMaxSubdivisions;
  int splineTessellationDistance;
  float cableDiameter;
  int cableSubdivisions;
  float time;
  float fractionBeforeLerp;
  bool downDirection;
  int dirty;
  sweptPoint_t *sweptPoints;
  idNonUniformBSpline<idVec3> *sourceSpline[2];
  int currentSourceSpline;
  zipLineGenParms_t *parms;
  int currentBuffer;
  idVertexBuffer vertexBuffer[3];
  idIndexBuffer indexBuffer[3];
  int numVertices;
  int numIndices;
};
