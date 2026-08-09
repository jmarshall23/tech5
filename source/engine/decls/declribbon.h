#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\declribbon.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13763; PDB kind: struct.
struct idDeclRibbon::helix_t
{
  float rotationScale;
  float radius;
  float velocity;
  idVec2 distortion0;
  idVec2 distortion1;
};

// IDA Local Type ordinal 13764; PDB kind: struct.
struct idDeclRibbon::turbulence_t
{
  float frequency;
  float magnitude;
  float velocity;
  idVec4 magic;
};

// IDA Local Type ordinal 13765; PDB kind: class.
class idDeclRibbon : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13766.
  virtual ~idDeclRibbon();
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
  int duration;
  float maxLength;
  float fadeInFraction;
  float fadeOutFraction;
  idVec3 gravity;
  idVec3 velocity;
  float startWidth;
  float endWidth;
  idVec4 color;
  bool viewOriented;
  bool reorientNodes;
  bool textureRepeat;
  bool textureRepeatStretch;
  float textureTMin;
  float textureTMax;
  float nodeSubdivision;
  float minNodeDistance;
  idDeclRibbon::helix_t helix;
  idDeclRibbon::turbulence_t turbulence;
};
