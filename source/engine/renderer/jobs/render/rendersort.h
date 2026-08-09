#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\rendersort.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22920; PDB kind: struct.
struct renderSortParms_t
{
  const renderSettings_t *settings;
  const idRenderView *renderView;
  drawSurf_t *drawSurfs;
  int numDrawSurfs;
  drawSurf_t **sortedDrawSurfs;
  renderPassSurfaces_t *renderPasses;
};
