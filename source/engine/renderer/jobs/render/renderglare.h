#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\renderglare.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22928; PDB kind: struct.
struct renderGlareParms_t
{
  const renderSettings_t *settings;
  const idRenderView *renderView;
  float xScale;
  float yScale;
  const idRenderDestination *renderDestDefault;
  const idRenderDestination *renderDestViewColor;
  const idRenderDestination *renderDestMip3;
  const idRenderDestination *renderDestMip3Alt;
  const idImage *imgBlack;
  const idDeclRenderParm *rpGlareMap;
  const idDeclRenderParm *rpGlareStep;
  const idDeclRenderProg *progGauss;
  const idDeclRenderProg *progGlareScale;
  const idTriangles *unitSquareTris;
};
