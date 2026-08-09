#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\binaryimage.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 19092; PDB kind: class.
class idBinaryImage::idBinaryImageData
{
public:
  int level;
  int destZ;
  int width;
  int height;
  int dataSize;
  idList<unsigned char,34> data;
};

// IDA Local Type ordinal 19094; PDB kind: class.
class idBinaryImage
{
public:
  idStr imgName;
  unsigned int sourceFileTime;
  unsigned int binaryFileTime;
  idImageOpts opts;
  idList<idBinaryImage::idBinaryImageData,34> images;
};
