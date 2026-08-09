#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\declaf.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14650; PDB kind: class.
class idDeclAF : public idDecl
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14658.
  virtual ~idDeclAF();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();
  virtual void Finish(bool (__fastcall *const)(void *, const idJointMat *, const char *, idVec3 *, idMat3 *), const idJointMat *, void *);

  bool modified;
  const idDeclMD6 *modelDef;
  idAtomicString skin;
  float defaultBouncyness;
  float defaultLinearFriction;
  float defaultAngularFriction;
  float defaultContactFriction;
  float defaultConstraintFriction;
  idVec2 suspendVelocity;
  idVec2 suspendAcceleration;
  float noMoveTime;
  float noMoveTranslation;
  float noMoveRotation;
  float minMoveTime;
  float maxMoveTime;
  int contents;
  int clipMask;
  idDeclAF::solverConstants_t solverConstants;
  idDeclAF::solverConstants_t syncSolverConstants;
  bool selfCollision;
  idAtomicString base;
  const idMaterial *clipMaterial;
  idList<idDeclAF_Body *,71> bodies;
  idList<idDeclAF_Constraint *,71> constraints;
};

// IDA Local Type ordinal 14651; PDB kind: struct.
struct idDeclAF::solverConstants_t
{
  float errorReduction;
  float errorReductionMax;
  float lcpEpsilon;
  float limitErrorReduction;
  float limitErrorReductionMax;
  float limitLcpEpsilon;
  float contactErrorReduction;
  float contactErrorReductionMax;
  float contactLcpEpsilon;
  float universalErrorReduction;
  float universalErrorReductionMax;
  float universalTorsionLcpEpsilon;
};

// IDA Local Type ordinal 14654; PDB kind: class.
class idDeclAF_Body
{
public:
  idAtomicString name;
  idAtomicString jointName;
  declAFJointMod_t jointMod;
  int modelType;
  idAtomicString modelName;
  idAFVector v1;
  idAFVector v2;
  int numSides;
  float width;
  float density;
  idAFVector origin;
  idAngles angles;
  int contents;
  int clipMask;
  bool selfCollision;
  bool noSyncCollide;
  bool clearClipMaskInSolid;
  float bouncyness;
  idMat3 inertiaScale;
  float linearFriction;
  float angularFriction;
  float contactFriction;
  idAtomicString containedJoints;
  idAFVector frictionDirection;
  idAFVector contactMotorDirection;
  idList<idIndex<short,enum invalidJointIndex_t>,71> containedJointIndices;
};
