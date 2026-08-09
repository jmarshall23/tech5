#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\particles\rendermodelparticle.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14030; PDB kind: struct.
struct idRenderModelParticle::stageCounts_t
{
  int vertCount;
  int indexOffset;
};

// IDA Local Type ordinal 14032; PDB kind: class.
class __declspec(align(8)) idRenderModelParticle : public idRenderModel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14033.
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
  virtual ~idRenderModelParticle();

  idList<deferredParticleGenParms_t,5> genParms;
  particleRenderView_t *particleRenderView;
  modelParticleParms_t *modelParms;
  idList<idRenderModelParticle::stageCounts_t,5> stageCounts[3];
  const idDeclParticle *particleDecl;
};
