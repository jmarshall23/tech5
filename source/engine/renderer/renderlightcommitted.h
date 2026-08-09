#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\renderlightcommitted.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13576; PDB kind: class.
class __declspec(align(4)) idRenderLightCommitted
{
public:
  idRenderWorldLocal *world;
  idRenderIndex index;
  idRenderLightParms r;
  idStaticParmBlock<32> renderParmBlock;
  idRenderLightCommitted *nextOnPostCommitList;
  idList<worldArea_t *,62> references;
  bool needsReferences;
  idBounds globalReferenceBounds;
  idVec3 globalLightOrigin;
  idVec3 currentColor;
  idVec4 maxVisibleRange;
  idRenderMatrix baseLightProject;
  idRenderMatrix inverseBaseLightProject;
  const idMaterial *lightMtr;
  bool castsShadows;
};
