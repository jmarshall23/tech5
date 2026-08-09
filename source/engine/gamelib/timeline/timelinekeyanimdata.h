#pragma once

#include "gamelib/timeline/timelinekeytypes.h"
#include "idlib/containers/list.h"

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.h
// Recovered logical types: 1
// IDA Local Type ordinal 19106; PDB kind: class. Method declarations are from
// the decorated functions in timelinekeyanimdata.cpp.
class mgTimelineKeyAnimData
{
public:
  mgTimelineKeyAnimData();

  void PostLoadInit();
  bool GetData(float time, bool *value) const;
  bool GetData(float time, int *value) const;
  bool GetData(float time, float *value) const;
  bool GetData(float time, idVec3 *value) const;
  bool GetData(float time, idVec4 *value) const;

  tlKeyType_t type;
  int keySize;
  idList<float,5> times;
  idList<char,5> data;

private:
  bool FindLerpKeys(float time, int *key0, int *key1, float *fraction) const;

  template<typename type_t>
  bool GetLerped(float time, type_t *value) const;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(mgTimelineKeyAnimData) == 40,
    "Recovered mgTimelineKeyAnimData ABI changed");
#endif
