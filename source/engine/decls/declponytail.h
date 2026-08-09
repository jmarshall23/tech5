#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\declponytail.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16478; PDB kind: class.
class idDeclPonytail::idPonytailJointInfo
{
public:
  idJointName jointName;
  idTypesafeNumber<float,enum DegreesUnique_t> limitAngle;
  float lerpRate;
  int targetSpringIndex;
};

// IDA Local Type ordinal 16480; PDB kind: class.
class idDeclPonytail::idPonytailSpringInfo
{
public:
  int ptJointIndex;
  float mass;
  float tightness;
  float damping;
  float maxLength;
  float maxSpeed;
  float gravityMag;
};

// IDA Local Type ordinal 16482; PDB kind: class.
class idDeclPonytail : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16483.
  virtual ~idDeclPonytail();
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

  const idDeclMD6 *modelDef;
  idAtomicString tagName;
  idList<idDeclPonytail::idPonytailJointInfo,30> jointInfo;
  idList<idDeclPonytail::idPonytailSpringInfo,30> springInfo;
};
