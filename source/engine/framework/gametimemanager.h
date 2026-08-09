#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\gametimemanager.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14287; PDB kind: class.
class idGameTimeManager
{
public:
  int framenum;
  int hz[2];
  int ticks[2];
  float timeDelta[2];
  int time[2];
  int previousTime[2];
  float scale[2];
  idInterpolate<float> timeScaleExtrapolation[2];
  slowmoParms_t slowmoParms;
  unsigned __int8 : 7;
  __int8 inSlowMotion : 1;
  bool useInterpolator;
  float slowmoDuration;
};

// IDA Local Type ordinal 14290; PDB kind: class.
class idGameTimeManagerPtr
{
public:
  idGameTimeManager *gameTimeManager;
};
