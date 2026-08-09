#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\transcode\image\barehdp\barehdp.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22812; PDB kind: class.
class idBareHDP
{
public:
  int quality;
  void *tempBuffer;
  int tempBufferSize;
  int tempBufferUsed;
  int imageROILeftX;
  int imageROITopY;
  int imageROIWidth;
  int imageROIHeight;
  int imageByteStride;
  hdpCodec_t *codec;
  unsigned __int8 streamTemp[128];
};
