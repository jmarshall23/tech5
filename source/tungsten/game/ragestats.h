#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ragestats.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18486; PDB kind: struct.
struct pageStats_t
{
  unsigned __int16 numPages;
  unsigned __int16 numVisPages;
  unsigned __int16 numTopPages;
  unsigned __int16 pad;
};

// IDA Local Type ordinal 23028; PDB kind: struct.
struct imageStats_t
{
  float ME;
  float MSE;
  float PSNR;
  int Max;
};

// IDA Local Type ordinal 26004; PDB kind: typedef.
typedef EP_STATUS regEP_STATUS;
