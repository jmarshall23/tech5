#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\transparency\rendermodeltransparency.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13545; PDB kind: class.
class __declspec(align(16)) idRenderModelTransparency : public idRenderModel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34035.
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
  virtual ~idRenderModelTransparency();

  transSortParms_t *sortParms;
  transSortResult_t *sortResult;
  influenceSphere_t *influenceSpheres[2];
  int numInfluenceSpheres[2];
  int currentSphereIndex;
  visibleInfluenceSpheres_t *visibleInfluenceSpheres;
  influenceSphereCullParms_t *influenceSphereCullParms;
};
