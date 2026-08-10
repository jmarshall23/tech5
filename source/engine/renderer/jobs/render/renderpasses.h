#pragma once

#include "render_types.h"
#include "renderdrawsurf.h"

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

void RenderClearPass( const renderPassParms_t * parms );
void RenderEmissivePass( const renderPassParms_t * parms );
void RenderEmissiveOnlyPass( const renderPassParms_t * parms );
void RenderBlendPass( const renderPassParms_t * parms );
void RenderDistortionPass( const renderPassParms_t * parms );
void RenderPass( const renderPassParms_t * parms );
