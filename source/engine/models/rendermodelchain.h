#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\rendermodelchain.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 21864; PDB kind: struct.
struct idRenderModelChain::splinePoint_t
{
  idVec3 value;
  float time;
};

// IDA Local Type ordinal 21866; PDB kind: class.
class __declspec(align(16)) idRenderModelChain : public idRenderModel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21867.
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
  virtual ~idRenderModelChain();

  idJointBuffer jointBuffers[2];
  idVertexBuffer morphBuffers[2];
  int currentJointBuffer;
  int currentMorphBuffer;
  int numMorphVertices;
  int numMorphLinkVertices;
  int numLinks;
  float linkSize;
  idList<idJointMat,85> transforms;
  idList<unsigned char,85> morphMap;
  idList<idRenderModelChain::splinePoint_t,85> splineSettings;
  idStr chainLinkModel;
  const idMaterial *morphMaterial;
  unsigned __int8 : 6;
  __int8 updateJointBuffers : 1;
  __int8 updateMorphBuffers : 1;
  chainGenerateInfo_t genInfo;
};
