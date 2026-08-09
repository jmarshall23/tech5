#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\demo.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 4864; PDB kind: struct.
struct _LD_DEMO
{
  unsigned int dwID;
  unsigned int dwRunmode;
  unsigned int dwTimeout;
  char szLauncherXEX[128];
  char szLaunchedXEX[128];
};

// IDA Local Type ordinal 27359; PDB kind: typedef.
typedef _LD_DEMO LD_DEMO;
