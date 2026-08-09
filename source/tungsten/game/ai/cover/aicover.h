#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\cover\aicover.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2391; PDB kind: enum.
enum aiCoverFlags_t : __int32
{
  COVER_NONE = 0x0,
  COVER_POPIN_HURT = 0x1,
  COVER_POPIN_AIM = 0x2,
  COVER_POPIN_RELOAD = 0x4,
  COVER_POPOUT_NO_AIM = 0x8,
  COVER_POPOUT_HURT = 0x10,
  COVER_STAYOUT_SAFE = 0x20,
};

// IDA Local Type ordinal 14722; PDB kind: class.
class __declspec(align(4)) idAICover
{
public:
  const idAAS2 *aas;
  idSpawnId spawnId;
  __int16 coverIndex;
};
