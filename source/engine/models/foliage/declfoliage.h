#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\foliage\declfoliage.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13596; PDB kind: class.
class __declspec(align(4)) idDeclFoliage : public idDecl
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13597.
  virtual ~idDeclFoliage();
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

  unsigned __int16 quadWidth;
  unsigned __int16 quadHeight;
  float widthVariance;
  float heightVariance;
  idVec3 colorVariance;
  bool rndFlipHoriz;
  float swayMagnitude;
  const idMaterial *material;
  unsigned int shape;
  idList<idMaterial const *,5> stampMaterials;
  float stampScale;
  float stampParms[4];
  float stampCovers[4];
  idAtomicString stampBlendMode;
  bool isReferenceType;
  bool isSinglePlacement;
};
