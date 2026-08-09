#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\render.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22827; PDB kind: class.
class idRender
{
public:
  unsigned __int8 temp[1024];
  unsigned __int8 areaNodeBoundsCulled[8192];
  unsigned __int8 worldAreaSubspaceBoundsCulled[8192];
  unsigned __int8 worldAreaGeometryBoundsCulled[8192];
  nodeWorldArea_t nodeWorldAreas[8192];
  viewWorldArea_t viewWorldAreas[8192];
  const idRenderModelSurface *viewWorldSurfaces[8192];
  const idRenderModelCommitted *viewModels[4096];
  const idRenderModelCommitted *sceneModels[64];
  const idRenderModelCommitted *viewAugmentModels[32];
  const idRenderLightCommitted *viewLights[4096];
  int occlusionTestNodes[64];
  int occlusionTestWorldAreas[4096];
  const idRenderModelCommitted *occlusionTestModels[4096];
  const idRenderLightCommitted *occlusionTestLights[512];
  drawSurf_t drawSurfs[4096];
  drawSurf_t *sortedDrawSurfs[4096];
  __int16 dimShadowModelSlaves[4096];
  unsigned __int8 modelConsideredAsOccluder[512];
  unsigned __int8 modelDimShadowState[4096];
  int numNodeWorldAreas;
  int numViewWorldAreas;
  int numViewWorldSurfaces;
  int numViewModels;
  int numSceneModels;
  int numViewAugmentModels;
  int numViewLights;
  int numOcclusionTestNodes;
  int numOcclusionTestWorldAreas;
  int numOcclusionTestModels;
  int numOcclusionTestLights;
  int numDrawSurfs;
  int numShadows;
  int numDimShadows;
  renderPassSurfaces_t renderPasses[5];
  renderSettings_t settings;
  idRenderView *renderViewObject;
  const idRenderWorldLocal *world;
  const idScreenView *screenView;
  idRenderModelCommitted worldSpace;
  idRenderModelCommitted viewSpace;
};
