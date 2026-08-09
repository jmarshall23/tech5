#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\particles\rendermodeleffects.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14013; PDB kind: struct.
struct idRenderModelEffects::sortedParticleStage_t
{
  const idParticleStage *stage;
  int first;
  int num;
};

// IDA Local Type ordinal 14017; PDB kind: struct.
struct idRenderModelEffects::deferredStage_t
{
  const idMaterial *mtr;
  int vertCount;
  int indexOffset;
};

// IDA Local Type ordinal 14019; PDB kind: class.
class idRenderModelEffects : public idRenderModel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14020.
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
  virtual ~idRenderModelEffects();

  effectParticleParms_t *particles;
  int particleRange[2];
  particleTrailParms_t *particleTrails;
  int particleTrailRange[2];
  tracerParms_t *tracers;
  int tracerRange[2];
  decalParms_t *decals;
  decalVerts_t *decalVerts;
  int decalRange[2];
  int gameTime;
  int deltaTime;
  int latchedTime;
  int lastLatchedParticleRange[2];
  int latchedParticleRange[2];
  int latchedTracerRange[2];
  int latchedDecalRange[2];
  idRenderModelEffects::sortedParticleStage_t sortedParticleStages[1024];
  int numSortedParticleStages;
  particleRenderView_t *particleRenderView;
  deferredParticleGenParms_t *particleGenParms;
  idList<idRenderModelEffects::deferredStage_t,5> deferredStages[3];
  idTriangles *triangles;
};
