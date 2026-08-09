#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\imageatlas.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3016; PDB kind: enum.
enum imageFlags_t : __int32
{
  IMAGE_SPECULAR = 0x1,
  IMAGE_DIFFUSE = 0x2,
  IMAGE_NORMAL = 0x4,
  IMAGE_TEST_FBR = 0x8,
  IMAGE_TEST_VBR = 0x10,
};

// IDA Local Type ordinal 22768; PDB kind: class.
class idImageAtlas
{
public:
  int ATLAS_WIDTH_BITS;
  int ATLAS_HEIGHT_BITS;
  int ATLAS_MIP_LEVELS;
  int ATLAS_TILE_WIDTH_BITS;
  int ATLAS_TILE_HEIGHT_BITS;
  int ATLAS_WIDTH;
  int ATLAS_HEIGHT;
  int ATLAS_TILE_WIDTH;
  int ATLAS_TILE_HEIGHT;
  int ATLAS_TILES_WIDE;
  int ATLAS_TILES_HIGH;
  int ATLAS_TILES;
  idBitArray tileAlloc;
  idImage *atlas;
};
