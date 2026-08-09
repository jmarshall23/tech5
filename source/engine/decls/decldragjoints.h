#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\decldragjoints.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16700; PDB kind: class.
class idDeclDragJoints : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16701.
  virtual ~idDeclDragJoints();
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

  float ghostJointDistance;
  idJointName baseJoint;
  idList<idJointName,5> joints;
  idList<idStr,5> subWebs;
};
