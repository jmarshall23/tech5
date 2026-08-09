#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\resource.h
// Recovered logical types: 12
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2777; PDB kind: enum.
enum idResource::referenceType_t : __int32
{
  REF_UNKNOWN = 0x0,
  REF_FREED = 0x1,
  REF_WEAK = 0x2,
  REF_STRONG = 0x3,
};

// IDA Local Type ordinal 2778; PDB kind: enum.
enum idResource::resourceError_t : __int32
{
  RESOURCE_ERROR_NONE = 0x0,
  RESOURCE_ERROR_FILE_NOT_FOUND = 0x1,
  RESOURCE_ERROR_WRONG_TYPE = 0x2,
  RESOURCE_ERROR_INVALID_NAME = 0x3,
  RESOURCE_ERROR_HEADER_VERSION_MISMATCH = 0x4,
  RESOURCE_ERROR_RESOURCE_VERSION_MISMATCH = 0x5,
  RESOURCE_ERROR_FATAL = 0x6,
  RESOURCE_ERROR_TRUNCATED = 0x7,
  RESOURCE_ERROR_MAX = 0x8,
};

// IDA Local Type ordinal 2779; PDB kind: enum.
enum idResource::resourceHeader_t::resourcePlatform_t : __int32
{
  RESOURCEPLATFORM_WINDOWS = 0x0,
  RESOURCEPLATFORM_360 = 0x1,
  RESOURCEPLATFORM_PS3 = 0x2,
  RESOURCEPLATFORM_MAC = 0x3,
  RESOURCEPLATFORM_MAX = 0x4,
};

// IDA Local Type ordinal 13299; PDB kind: class.
class __declspec(align(4)) idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13302.
  virtual ~idResource();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  int trackedMemory;
  idAtomicString name;
  idResource *nextOnHashChain;
  idResourceList *resourceListPtr;
  const char *resourceError;
  int networkID;
  int staleCount;
  unsigned __int8 : 3;
  __int8 loadDeferred : 1;
  __int8 forceLoad : 1;
  __int8 insideRecursiveLoad : 1;
  __int8 staticResource : 1;
  __int8 loadedResource : 1;
};

// IDA Local Type ordinal 13653; PDB kind: class.
class idCodeResource<idDeclRenderParm> : public idBaseCodeResource
{
public:
};

// IDA Local Type ordinal 17567; PDB kind: class.
class idCodeResource<idFont> : public idBaseCodeResource
{
public:
};

// IDA Local Type ordinal 19095; PDB kind: class.
class idAtlasResource : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19096.
  virtual ~idAtlasResource();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  unsigned int binaryTimestamp;
  idVec4 scaleBias;
  int img_tiles_wide;
  int img_tiles_high;
  int img_x;
  int img_y;
  int img_w;
  int img_h;
};

// IDA Local Type ordinal 21416; PDB kind: class.
class idCodeResource<idMaterial> : public idBaseCodeResource
{
public:
};

// IDA Local Type ordinal 22063; PDB kind: struct.
struct idResource::resourceHeader_t
{
  unsigned __int16 headerVersionHi;
  unsigned __int16 headerVersionLo;
  unsigned int resourceId;
  unsigned __int16 versionHi;
  unsigned __int16 versionLo;
  unsigned int sourceTimestamp;
  unsigned __int16 sourceFileNameLen;
  unsigned __int16 uniqueIdNameLen;
  unsigned __int8 platform;
  unsigned __int8 pad[3];
  unsigned __int64 uniqueId;
  unsigned __int64 hash;
  unsigned __int64 dataOffset;
  unsigned __int64 totalSize;
};

// IDA Local Type ordinal 22703; PDB kind: class.
class idCodeResource<idSoundShader> : public idBaseCodeResource
{
public:
};

// IDA Local Type ordinal 22770; PDB kind: class.
class idCodeResource<idDeclRenderProg> : public idBaseCodeResource
{
public:
};

// IDA Local Type ordinal 23337; PDB kind: class.
class idJointResource : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23338.
  virtual ~idJointResource();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

};
