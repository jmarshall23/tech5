#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\renderlight.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13578; PDB kind: class.
class __declspec(align(8)) idRenderLight
{
public:
  idRenderLightParms g;
  idStaticParmBlock<32> gameParmBlock;
  bool deleteOnSync;
  bool unlinked;
  bool needWriteToSnapshot;
  bool skipAutoReplication;
  int serializedChangeCount;
  idRenderLightCommitted *committed;
};
