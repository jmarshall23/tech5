#pragma once

#include "render_types.h"

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\renderdepth.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22918; PDB kind: struct.
struct renderDepthParms_t
{
  const renderSettings_t *settings;
  const idRenderView *renderView;
  const viewWorldArea_t *viewWorldAreas;
  int numViewWorldAreas;
  const idRenderModelSurface **viewWorldSurfaces;
  int numViewWorldSurfaces;
  const idRenderModelCommitted **viewModels;
  int numViewModels;
  const idRenderModelCommitted **sceneModels;
  int numSceneModels;
  const bool *binaryModelState;
  const idRenderDestination *renderDestDefault;
  const idTriangles *occlusionBaseTriangles;
  const idDeclRenderProg *progOccluderDepthOnly;
  const idDeclRenderProg *progOutside;
  const idDeclRenderProg *progRadiosityPreview;
  const idImage *imgBlack;
  int extraClears;
  occlusionState_t *occlusionState;
  drawSurf_t *drawSurfs;
  int *numDrawSurfs;
};

void RenderDepth( const renderDepthParms_t * parms );
