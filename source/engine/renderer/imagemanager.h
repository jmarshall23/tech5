#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\imagemanager.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22769; PDB kind: class.
class idImageManager
{
public:
  idImage *defaultImage;
  idImage *whiteImage;
  idImage *borderedPointWhiteImage;
  idImage *blackImage;
  idImage *ps3ReplacementImage;
  idImageAtlas *transSortImageAtlas;
  textureFilter_t textureMinFilter;
  textureFilter_t textureMaxFilter;
  textureFilter_t textureMipFilter;
  float textureAnisotropy;
  float textureLODBias;
  idImageOpts newImageOpts;
};

// IDA Local Type ordinal 23016; PDB kind: struct.
struct idImageManager::ChangeTextureFilter::__l2::filterName_t
{
  char *name;
  textureFilter_t minimize;
  textureFilter_t maximize;
  textureFilter_t mipimize;
};
