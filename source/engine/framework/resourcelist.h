#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\resourcelist.h
// Recovered logical types: 31
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13300; PDB kind: class.
class idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13301.
  virtual ~idResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

  const char *resourceTypeName;
  idResourceList *nextResourceList;
  int num;
  int staticID;
  idResource *hashTable[256];
};

// IDA Local Type ordinal 18047; PDB kind: class.
class idTypedResourceList<idVoiceTrack> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18048.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 18119; PDB kind: class.
class idTypedResourceList<idNavigationMesh> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18120.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 18306; PDB kind: class.
class idTypedResourceList<idCoverPoints> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18307.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 18732; PDB kind: class.
class idTypedResourceList<idInGameVideoFile> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18733.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 18735; PDB kind: class.
class idTypedResourceList<idMD6Anim> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18736.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 18739; PDB kind: class.
class idTypedResourceList<idIESfile> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18740.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 19089; PDB kind: class.
class idTypedResourceList<idImage> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19090.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 19097; PDB kind: class.
class idTypedResourceList<idAtlasResource> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19098.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 20001; PDB kind: class.
class idTypedResourceList<idCollisionModelLocal> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20002.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 20076; PDB kind: class.
class idTypedResourceList<idFont> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20077.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 21602; PDB kind: class.
class idTypedResourceList<idStaticModel> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21603.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 21604; PDB kind: class.
class idTypedResourceList<idSoundSample> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21605.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 21607; PDB kind: class.
class idTypedResourceList<idStaticParticleModelData> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21608.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 21627; PDB kind: class.
class idTypedResourceList<idMD6Skel> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21628.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 21701; PDB kind: class.
class idTypedResourceList<idMD6Model> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21702.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 21755; PDB kind: class.
class idTypedResourceList<idDiscreteAnimationModelData> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21756.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 21903; PDB kind: class.
class idTypedResourceList<idMD6SkeletonConfig> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21904.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 21984; PDB kind: class.
class idTypedResourceList<idAAS2File> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21985.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 22175; PDB kind: class.
class idTypedResourceList<idRenderModelCuttableResource> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22176.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 22333; PDB kind: class.
class idTypedResourceList<idMorphVertices> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22334.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 22456; PDB kind: class.
class idTypedResourceList<idFileResource> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22457.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 22869; PDB kind: class.
class idTypedResourceList<idFoliageModel> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22870.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 22873; PDB kind: class.
class idTypedResourceList<idDetailModel> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22874.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 23020; PDB kind: class.
class idTypedResourceList<idImageCPU> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23021.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 23026; PDB kind: class.
class idTypedResourceList<idImageCubeCPU> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23027.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 23308; PDB kind: class.
class idTypedResourceList<idJointConversion> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23309.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 23335; PDB kind: class.
class idTypedResourceList<idJointResource> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23336.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 23364; PDB kind: class.
class idTypedResourceList<idDetailModelData> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23365.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 23512; PDB kind: class.
class idTypedResourceList<idAAS2DebugAreaModel> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23513.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};

// IDA Local Type ordinal 23769; PDB kind: class.
class idTypedResourceList<idCollisionGridLocal> : public idResourceList
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23770.
  virtual ~idTypedResourceList();
  virtual idResource *Alloc(const char *);
  virtual int AllocSize();

};
