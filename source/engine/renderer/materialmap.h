#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\materialmap.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13328; PDB kind: class.
class idMaterialMapping
{
public:
  idAtomicString materialName;
  unsigned int materialChecksum;
  unsigned int materialTimestamp;
  int x;
  int y;
  int width;
  int height;
  idVec4 scaleBias;
  idVirtualImageFile specularFile;
  idVirtualImageFile coverFile;
  idVirtualImageFile diffuseFile;
  idVirtualImageFile bumpFile;
  idVirtualImageFile powerFile;
};

// IDA Local Type ordinal 13330; PDB kind: class.
class idMaterialMap
{
public:
  idStr name;
  int width;
  int height;
  unsigned int skinFileTimeStamp;
  idList<idMaterialMapping,46> mappings;
};
