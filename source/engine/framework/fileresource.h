#pragma once

#include "framework/resourcelist.h"

class idFile_Memory;
struct HINSTANCE__;


// IDA Local Type ordinal 5027; PDB kind: struct.
struct _DXFILELOADRESOURCE
{
  HINSTANCE__ *hModule;
  const char *lpName;
  const char *lpType;
};

// IDA Local Type ordinal 22454; PDB kind: class.
class idFileResource : public idResource {
public:
  idFileResource();
  ~idFileResource() override;
  void LoadResource() override;
  idResourceList* GetResourceList() override;

  void FreeData();
  idFile_Memory* GetFileReadOnly();
  static bool FileExists(const char* fileName);
  static idTypedResourceList<idFileResource> resourceList;

  unsigned int timestamp;
  unsigned int length;
  void *data;
};

// IDA Local Type ordinal 29898; PDB kind: typedef.
typedef _DXFILELOADRESOURCE DXFILELOADRESOURCE;

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idFileResource) == 48,
    "Recovered idFileResource ABI changed");
#endif
