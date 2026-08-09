#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\declflare.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13307; PDB kind: class.
class idDeclFile
{
public:
  bool hadRedefinition;
  idAtomicString fileName;
  idDeclInfo *defaultType;
  unsigned int timestamp;
  unsigned int checksum;
  int fileSize;
  int numLines;
  bool everReloaded;
  idDeclSource *firstDeclSourceInFile;
  idList<int,46> dependencies;
  int dependenciesDynamicStartIndex;
  idList<idStr,5> includeFiles;
};

// IDA Local Type ordinal 13758; PDB kind: struct.
struct __declspec(align(4)) idDeclFlare::subFlare_t
{
  float width;
  float height;
  float minScaleX;
  float minScaleY;
  float viewScaleX;
  float viewScaleY;
  float coneAngle;
  float maxDistScaleX;
  float maxDistScaleY;
  float scaleDistance;
  float position;
  idVec4 color;
  const idMaterial *mtr;
  bool reflectX;
  bool reflectY;
};

// IDA Local Type ordinal 13760; PDB kind: class.
class idDeclFlare : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13761.
  virtual ~idDeclFlare();
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

  idList<idDeclFlare::subFlare_t,79> subflares;
  unsigned __int8 : 7;
  __int8 useAltViewVecCalc : 1;
  float viewAngleFade;
  float invViewAngleFade;
  float brightness;
};
