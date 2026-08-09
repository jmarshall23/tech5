#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\declimpactsound.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14321; PDB kind: class.
class idDeclImpactSound : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14322.
  virtual ~idDeclImpactSound();
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

  const idSoundShader *defaultSound;
  const idSoundShader *metalSound;
  const idSoundShader *stoneSound;
  const idSoundShader *fleshSound;
  const idSoundShader *woodSound;
  const idSoundShader *cardboardSound;
  const idSoundShader *liquidSound;
  const idSoundShader *glassSound;
  const idSoundShader *plasticSound;
  const idSoundShader *asphaltSound;
  const idSoundShader *dirtSound;
  const idSoundShader *concreteSound;
  const idSoundShader *foliageSound;
  const idSoundShader *linoleumSound;
  const idSoundShader *fabricSound;
  const idSoundShader *rubberSound;
  const idSoundShader *rockSound;
  const idSoundShader *steamPipeSound;
  const idSoundShader *waterPipeSound;
  const idSoundShader *armorSound;
  const idSoundShader *sludgeSound;
  const idSoundShader *impNestSound;
  const idSoundShader *hollowMetalSound;
  const idSoundShader *sheetMetalSound;
  const idSoundShader *fleshPlayerSound;
  const idSoundShader *bloodPoolSound;
  const idSoundShader *ashSound;
  const idSoundShader *mutantFleshSound;
  const idSoundShader *thickPaddingSound;
  const idSoundShader *playerAPCMetalSound;
  const idSoundShader *ricketyMetalSound;
  const idSoundShader *ricketyWoodSound;
  int soundInterval;
};
