#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\rendermodelcommitted.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13636; PDB kind: class.
class __declspec(align(8)) idRenderModelCommitted
{
public:
  const char *name;
  idRenderWorldLocal *world;
  idRenderIndex index;
  idBounds referenceBounds;
  idRenderModelParms r;
  idStaticParmBlock<32> renderParmBlock;
  idList<idRenderModelSurface,62> surfaces;
  idRenderModelCommitted *nextOnPostCommitList;
  idList<worldArea_t *,62> references;
  idRenderModelCommitted *nextAddAlwaysModel;
  idRenderModelCommitted *nextDimShadowModel;
  idRenderModelCommitted *referenceModel;
  int guiFrameCount;
  idVec4 maxVisibleRange;
  idBounds globalReferenceBounds;
  idVec3 localLightingPoint;
  idRenderMatrix modelMatrix;
  idRenderMatrix inverseModelMatrix;
  approximateLighting_t approximateLighting;
  idVec4 highlightColor;
  __int8 isLitTransSort : 1;
  __int8 hasUniqueVirtualTexture : 1;
  __int8 mayMakeInteractions : 1;
  __int8 mayCastShadows : 1;
  __int8 mayBeDrawn : 1;
  __int8 needsApproximatedLighting : 1;
  __int8 needsReferences : 1;
  __int8 lightCenterInitialized : 1;
  idRenderMatrix mvpMatrix;
};
