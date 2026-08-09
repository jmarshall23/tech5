#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\declwalkik.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15253; PDB kind: class.
class idDeclWalkIK : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15254.
  virtual ~idDeclWalkIK();
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

  idList<idIKLeg,83> legJoints;
  idAtomicString waistJoint;
  idVec3 kneeDir;
  float smoothing;
  float waistSmoothing;
  float stairSmoothing;
  float stairWaistSmoothing;
  float footSmoothing;
  float footShift;
  float waistShift;
  float minWaistFloorDist;
  float minWaistAnkleDist;
  float footSize;
  float footUpTrace;
  float footDownTrace;
  float footDownTraceDead;
  float restrictToBoundsTolerance;
  bool usePivot;
  bool restrictToBounds;
  bool dirsFromBasePose;
  bool checkFeetForSolids;
};
