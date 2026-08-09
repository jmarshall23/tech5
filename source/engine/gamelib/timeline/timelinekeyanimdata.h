#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\timeline\timelinekeyanimdata.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 19106; PDB kind: class.
class mgTimelineKeyAnimData
{
public:
  tlKeyType_t type;
  int keySize;
  idList<float,5> times;
  idList<char,5> data;
};
