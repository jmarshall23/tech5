#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sound\occlusion\soundrouting.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13711; PDB kind: struct.
struct soundRoutingParms_t
{
  int *route;
  flatSoundBSP_t flatBSP;
  int numAreas;
  int listenerAreaNum;
  idVec3 listenerOrigin;
  unsigned __int8 *temp;
  int tempSize;
};
