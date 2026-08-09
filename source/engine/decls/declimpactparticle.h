#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\declimpactparticle.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14535; PDB kind: class.
class idDeclImpactParticle : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14536.
  virtual ~idDeclImpactParticle();
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

  const idDeclParticle *defaultPrt;
  const idDeclParticle *metalPrt;
  const idDeclParticle *stonePrt;
  const idDeclParticle *fleshPrt;
  const idDeclParticle *woodPrt;
  const idDeclParticle *cardboardPrt;
  const idDeclParticle *liquidPrt;
  const idDeclParticle *glassPrt;
  const idDeclParticle *plasticPrt;
  const idDeclParticle *asphaltPrt;
  const idDeclParticle *dirtPrt;
  const idDeclParticle *concretePrt;
  const idDeclParticle *foliagePrt;
  const idDeclParticle *linoleumPrt;
  const idDeclParticle *fabricPrt;
  const idDeclParticle *rubberPrt;
  const idDeclParticle *rockPrt;
  const idDeclParticle *steamPipePrt;
  const idDeclParticle *waterPipePrt;
  const idDeclParticle *armorPrt;
  const idDeclParticle *sludgePrt;
  const idDeclParticle *shieldPrt;
  const idDeclParticle *bloodPoolPrt;
  const idDeclParticle *ashPrt;
  const idDeclParticle *mutantFleshPrt;
  const idDeclParticle *thickPaddingPrt;
};
