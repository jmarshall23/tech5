#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\cloth\declcloth.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15201; PDB kind: class.
class idDeclCloth::ropeInfo
{
public:
  idList<idVec3,5> positions;
  idList<idMat3,5> inverseAxis;
  idList<idIndex<short,enum invalidJointIndex_t>,5> indexOfJointToAttachTo;
};

// IDA Local Type ordinal 15203; PDB kind: struct.
struct __declspec(align(4)) idDeclCloth::particleInfo_t
{
  idVec3 position;
  idIndex<short,enum invalidJointIndex_t> jointIndex;
  int forwardIndex;
  int rightIndex;
  bool anchored;
};

// IDA Local Type ordinal 15205; PDB kind: struct.
struct idDeclCloth::springInfo_t
{
  unsigned __int8 index1;
  unsigned __int8 index2;
};

// IDA Local Type ordinal 15207; PDB kind: class.
class idDeclCloth : public idDecl
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15208.
  virtual ~idDeclCloth();
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

  int width;
  int height;
  float vSpacing;
  float hSpacing;
  float gravity;
  float mass;
  float friction;
  float collisionFriction;
  float springLength;
  float springFriction;
  float springMaxLengthMultiplier;
  clothType_t type;
  clothSprings_t springType;
  const idMaterial *material;
  const idDeclMD6 *clothMD6;
  const idDeclFX *clothDeclFX;
  bool md6IsBound;
  idList<idDeclCloth::ropeInfo,5> ropeData;
  idList<idDeclCloth::particleInfo_t,5> particleData;
  idList<idDeclCloth::springInfo_t,5> springData;
};
