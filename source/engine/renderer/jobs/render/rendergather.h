#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\rendergather.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22916; PDB kind: struct.
struct renderGatherParms_t
{
  unsigned __int8 *temp;
  int tempSize;
  const renderSettings_t *settings;
  const idRenderView *renderView;
  const idRenderModelCommitted *const *linkedRenderModels;
  int numLinkedRenderModels;
  const idRenderLightCommitted *const *linkedRenderLights;
  int numLinkedRenderLights;
  const nodeWorldArea_t *nodeWorldAreas;
  const unsigned __int8 *worldAreaSubspaceBoundsCulled;
  const unsigned __int8 *worldAreaGeometryBoundsCulled;
  int numNodeWorldAreas;
  const worldArea_t *worldAreas;
  int numWorldAreas;
  const idRenderModelCommitted *addAlwaysModels;
  occlusionState_t *occlusionState;
  int *occlusionTestNodes;
  int *numOcclusionTestNodes;
  viewWorldArea_t *viewWorldAreas;
  int *numViewWorldAreas;
  const idRenderModelSurface **viewWorldSurfaces;
  int *numViewWorldSurfaces;
  const idRenderModelCommitted **viewModels;
  int *numViewModels;
  const idRenderModelCommitted **sceneModels;
  int *numSceneModels;
  const idRenderModelCommitted **viewAugmentModels;
  int *numViewAugmentModels;
  const idRenderLightCommitted **viewLights;
  int *numViewLights;
  int *occlusionTestWorldAreas;
  int *numOcclusionTestWorldAreas;
  const idRenderModelCommitted **occlusionTestModels;
  int *numOcclusionTestModels;
  const idRenderLightCommitted **occlusionTestLights;
  int *numOcclusionTestLights;
};
