#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\cuttable\rendermodelcuttableresource.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15902; PDB kind: class.
class __declspec(align(16)) idRenderModelCuttableResource : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15903.
  virtual ~idRenderModelCuttableResource();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  const idMaterial *sourceMaterial;
  const idMaterial *material;
  idTriangles *triangles;
  idVec2 *stData;
  idVertexBuffer *stMap;
  idList<idVec3,5> contourBound;
  idTriangleInterpolator triangleInterpolator;
  unsigned int timestamp;
};
