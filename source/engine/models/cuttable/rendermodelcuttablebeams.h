#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\cuttable\rendermodelcuttablebeams.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2743; PDB kind: unknown.
enum idRenderModelCuttableBeams::<unnamed_tag> : __int32
{
  MAX_BEAM_QUADS = 0x1000,
  MAX_BEAM_VERTICES = 0x4000,
  MAX_BEAM_INDICES = 0x6000,
  NUM_VERTEX_BUFFERS = 0x3,
  SURFACE_INCISIONS = 0x0,
  SURFACE_INCISIONCROSSINGS = 0x1,
  SURFACE_INCISIONENDPOINTS = 0x2,
  SURFACE_MAX = 0x3,
};

// IDA Local Type ordinal 15932; PDB kind: class.
class idRenderModelCuttableBeams : public idRenderModel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15933.
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
  virtual ~idRenderModelCuttableBeams();

  const idMaterial *materialIncision;
  const idMaterial *materialIncisionCross;
  idCutterGraphManager *graphManager;
  int graphHandle;
};
