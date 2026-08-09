#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\renderocclusion.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22919; PDB kind: struct.
struct renderOcclusionParms_t
{
  const renderSettings_t *settings;
  const idRenderView *renderView;
  int *occlusionTestNodes;
  int numOcclusionTestNodes;
  int *occlusionTestWorldAreas;
  int numOcclusionTestWorldAreas;
  const idRenderModelCommitted **occlusionTestModels;
  int numOcclusionTestModels;
  const idRenderLightCommitted **occlusionTestLights;
  int numOcclusionTestLights;
  const int *areaNodeOcclusionIndex;
  const idBounds *areaNodeBounds;
  const idBounds *worldAreaGeometryBounds;
  int numWorldAreas;
  const idRenderDestination *renderDestDefault;
  const idDeclRenderProg *progDepthOnly;
  const idTriangles *unitCubeTris;
  const idTriangles *zeroOneCubeTris;
  occlusionState_t *occlusionState;
};
