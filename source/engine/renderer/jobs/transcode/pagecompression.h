#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\transcode\pagecompression.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1492; PDB kind: enum.
enum pageCompression_t : __int32
{
  COMP_NONE = 0x1,
  COMP_DXT = 0x2,
  COMP_LZW = 0x3,
  COMP_DCT = 0x4,
  COMP_HDP = 0x5,
  COMP_JXR = 0x6,
  COMP_MAX_COMPRESSIONS = 0x7,
};
