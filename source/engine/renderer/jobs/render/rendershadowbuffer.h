#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\rendershadowbuffer.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22922; PDB kind: struct.
struct renderShadowBufferParms_t
{
  const renderSettings_t *settings;
  const idRenderView *renderView;
  const idBounds *worldAreaSubspaceBounds;
  const idBounds *worldAreaGeometryBounds;
  const unsigned __int8 *worldAreaSubspaceBoundsCulled;
  const idRenderModelCommitted *worldModel;
  const idRenderModelCommitted *const *linkedRenderModels;
  int numLinkedRenderModels;
  const idDeclRenderParm *rpShadowBufferResolution;
  const idRenderDestination *renderDestDefault;
  const idRenderDestination *renderDestShadow;
  shadowBufferOptions_t options;
  unsigned __int8 *modelConsideredAsOccluder;
};
