#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\transcode\image\dxt\dxtcodec.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22779; PDB kind: class.
class idDxtEncoder
{
public:
  int width;
  int height;
  unsigned __int8 *outData;
  int srcPadding;
  int dstPadding;
};

// IDA Local Type ordinal 22780; PDB kind: class.
class idDxtDecoder
{
public:
  int width;
  int height;
  const unsigned __int8 *inData;
};
