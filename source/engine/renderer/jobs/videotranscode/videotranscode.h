#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\videotranscode\videotranscode.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22939; PDB kind: struct.
struct __declspec(align(4)) videoTranscodeParms_t
{
  unsigned __int8 dctQualityLuma;
  unsigned __int8 dctQualityChroma;
  unsigned __int8 *dctBuffer;
  int dctBufferSize;
  idImage *image;
  unsigned __int8 *dxtBuffer;
  int targetBytePitch;
  bool needSubImageUpload;
};
