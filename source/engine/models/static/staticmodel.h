#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\static\staticmodel.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2909; PDB kind: enum.
enum idStaticModel::modelLoadFlags_t : __int32
{
  MODELLOADFLAGS_RESIDE_ON_CPU = 0x1,
  MODELLOADFLAGS_RESIDE_ON_GPU = 0x2,
  MODELLOADFLAGS_DEFAULT = 0x2,
};

// IDA Local Type ordinal 13428; PDB kind: class.
class idStaticModel : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13429.
  virtual ~idStaticModel();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  bool pristine;
  bool isReloadable;
  char binaryFileName[256];
  unsigned int binaryTimeStamp;
  unsigned int sourceTimeStamp;
  int reloadCount;
  bool modelIsAutosprite;
  bool usesTransparencySort;
  idBounds referenceBounds;
  idVec3 referencePosition;
  bool sharedSurfaces;
  int modelLoadFlags;
  idList<idStaticModelSurface,84> surfaces;
  idList<sourceSurface_t,5> sourceSurfaces;
  idList<idMaterial const *,5> materials;
};
