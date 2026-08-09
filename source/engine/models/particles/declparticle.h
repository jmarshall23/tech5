#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\particles\declparticle.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13460; PDB kind: class.
class idDeclParticle : public idDecl
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13461.
  virtual ~idDeclParticle();
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

  idList<idParticleStage *,79> stages;
  idList<idAtomicString,79> stageNames;
  idList<idAtomicString,79> stageInheritNames;
  idList<idDeclTable const *,79> tableDecls;
  idList<idLookupTable,79> tables;
  idBounds bounds;
  int maxSystemDuration;
  int lodRadius;
};

// IDA Local Type ordinal 15209; PDB kind: class.
class idClothParticle
{
public:
  idVec3 origin;
  idVec3 lastOrigin;
  idVec3 velocity;
  idVec3 force;
  idMat3 axis;
  float mass;
  unsigned __int8 neighbors[4];
  unsigned __int8 anchored;
  unsigned __int16 state;
};
