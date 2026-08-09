#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\discreteanimation\discreteanimationmodeldata.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14584; PDB kind: class.
class idDiscreteAnimationModelSurface
{
public:
  int jointOffset;
  int numJoints;
  idTriangles *triangles;
};

// IDA Local Type ordinal 14587; PDB kind: class.
class idDiscreteAnimationModelData : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14588.
  virtual ~idDiscreteAnimationModelData();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  unsigned int timestamp;
  float maxRadius;
  idBounds bounds;
  const idMaterial *material;
  idList<idTraceModel,59> traceModels;
  idList<idJointMat,59> transforms;
  idList<idDiscreteAnimationModelSurface *,59> surfaces;
  idList<sourceSurface_t,59> sourceSurfaces;
  idCollisionModel *baseModel;
};
