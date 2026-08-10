#pragma once

#include "render_types.h"

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\rendercull.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22914; PDB kind: struct.
struct renderCullParms_t
{
  const renderSettings_t *settings;
  const idRenderView *renderView;
  const idBounds *areaNodeBounds;
  const idBounds *worldAreaSubspaceBounds;
  const idBounds *worldAreaGeometryBounds;
  int numAreaNodes;
  int numWorldAreas;
  unsigned __int8 *areaNodeBoundsCulled;
  unsigned __int8 *worldAreaSubspaceBoundsCulled;
  unsigned __int8 *worldAreaGeometryBoundsCulled;
};

void RenderCull( const renderCullParms_t * parms );
