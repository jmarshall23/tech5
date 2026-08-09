#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\renderdestination.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18485; PDB kind: class.
class idRenderDestination
{
public:
  bool isDefault;
  int targetWidth;
  int targetHeight;
  idImage *targetImage[4];
  idImage *depthImage;
  idImage *stencilImage;
  D3DSurface *targetSurface[4];
  D3DSurface *depthSurface;
};
