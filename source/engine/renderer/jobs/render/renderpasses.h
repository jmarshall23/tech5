#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\renderpasses.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1721; PDB kind: enum.
enum renderPass_t : __int32
{
  RENDERPASS_CLEAR = 0x0,
  RENDERPASS_EMISSIVE = 0x1,
  RENDERPASS_EMISSIVE_ONLY = 0x2,
  RENDERPASS_BLEND = 0x3,
  RENDERPASS_DISTORTION = 0x4,
  NUM_RENDER_PASSES = 0x5,
};

// IDA Local Type ordinal 22825; PDB kind: struct.
struct renderPassSurfaces_t
{
  int firstSurface;
  int lastSurface;
};

// IDA Local Type ordinal 22830; PDB kind: struct.
struct renderPassParms_t
{
  renderPass_t pass;
  const renderSettings_t *settings;
  const idRenderView *renderView;
  renderDrawSurfParms_t drawSurfParms;
  const idRenderDestination *renderDestDefault;
  const idRenderDestination *renderDestDistortion;
  const idDeclRenderParm *rpViewColor;
  const renderPassSurfaces_t *renderPasses;
  drawSurf_t **sortedDrawSurfs;
  const bool *binaryModelState;
};
