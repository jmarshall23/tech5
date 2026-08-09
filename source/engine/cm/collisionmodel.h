#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\cm\collisionmodel.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14043; PDB kind: class.
class idCollisionModel : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14044.
  virtual ~idCollisionModel();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual cmType_t GetModelType();
  virtual bool GetBounds(idBounds *);
  virtual bool GetBox(idBox *);
  virtual bool GetContents(int *);
  virtual bool GetVertex(int, idVec3 *);
  virtual bool GetEdge(int, idVec3 *, idVec3 *);
  virtual bool GetPolygon(int, idFixedWinding *);
  virtual int GetPolytope(int, idPlane *, int);
  virtual int GetPolytopes(int *, int, idPlane *, int);
  virtual idIndex<short,enum invalidJointIndex_t> *GetJoint(idIndex<short,enum invalidJointIndex_t> *result, int);

};

// IDA Local Type ordinal 18656; PDB kind: class.
class idPositionedCollisionModel
{
public:
  idCollisionModel *model;
  const idJointMat *modelJoints;
  idVec3 modelOrigin;
  idMat3 modelAxis;
  int modelEntityNum;
  int modelPhysicsId;
  int modelBodyId;
  int modelContentsOverride;
  idCollisionQuery modelQuery;
};
