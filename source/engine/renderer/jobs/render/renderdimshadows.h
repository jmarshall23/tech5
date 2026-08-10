#pragma once

#include "render_types.h"

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\renderdimshadows.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22921; PDB kind: struct.
struct renderDimShadowsParms_t
{
  __int16 *dimShadowModelSlaves;
  const renderSettings_t *settings;
  const idRenderView *renderView;
  const idRenderModelCommitted *const *linkedRenderModels;
  int numLinkedRenderModels;
  const idRenderModelCommitted *dimShadowModels;
  const idTriangles *extrudeBox;
  const idRenderDestination *renderDestDimShadow;
  const idRenderDestination *renderDestDefault;
  const idImage *imgViewColor;
  const idDeclRenderParm *rpViewColor;
  const idDeclRenderParm *rpDimShadowFade;
  const idDeclRenderParm *rpDimShadowExtrude;
  const idDeclRenderParm *rpDimShadowClipPlane;
  const idDeclRenderParm *rpWindowPosToDimShadowBlurS;
  const idDeclRenderParm *rpWindowPosToDimShadowBlurT;
  const idDeclRenderParm *rpWindowPosToDimShadowBlurR;
  const idDeclRenderParm *rpWindowPosToDimShadowBlurQ;
  const idDeclRenderParm *rpVertexMorphScale;
  const idDeclRenderProg *progDimShadowCreate;
  const idDeclRenderProg *progDimShadowCreateWound;
  const idDeclRenderProg *progDimShadowCreateAlpha;
  const idDeclRenderProg *progDimShadowDraw;
  const idDeclRenderProg *progDimShadowDrawHighQuality;
  const idDeclRenderProg *progDimShadowStencil;
  const idDeclRenderProg *progDimShadowDebugDraw;
  occlusionState_t *occlusionState;
  int *numDimShadows;
  unsigned __int8 *modelDimShadowState;
};

void RenderDimShadows( const renderDimShadowsParms_t * parms );
