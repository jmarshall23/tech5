#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\declelectricbolt.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15612; PDB kind: struct.
struct idDeclElectricBolt::branchOverride_t
{
  const idMaterial *material;
  int frames;
  int width;
};

// IDA Local Type ordinal 15613; PDB kind: class.
class idDeclElectricBolt : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15614.
  virtual ~idDeclElectricBolt();
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

  const idMaterial *material;
  bool applyGradient;
  int revealTime;
  float startWidth;
  float endWidth;
  float maxDeviation;
  idVec4 color;
  float brightness;
  int subdivisions;
  float branchProbability;
  int maxBranchLevels;
  float branchStartWidth;
  float branchEndWidth;
  idVec2 branchLength;
  float maxBranchAngle;
  int branchSubdivisions;
  float maxBranchDeviation;
  const idDeclTable *jitterTable;
  const idDeclTable *jitterFalloffTable;
  float jitterDecay;
  float jitterSpeed;
  idVec2 jitterLeftMag;
  idVec2 jitterUpMag;
  bool useBranchOverride;
  idDeclElectricBolt::branchOverride_t branchOverride;
};
