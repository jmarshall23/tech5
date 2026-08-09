#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\renderwalkbsp.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22915; PDB kind: struct.
struct renderWalkBSPParms_t
{
  const renderSettings_t *settings;
  const idRenderView *renderView;
  const unsigned __int8 *areaNodeBoundsCulled;
  const int *areaNodeOcclusionIndex;
  const __int64 *areaNodeOcclusionQuery;
  const idBounds *areaNodeBounds;
  const areaNode_t *areaNodes;
  int numAreaNodes;
  int numWorldAreas;
  int *occlusionTestNodes;
  int *numOcclusionTestNodes;
  nodeWorldArea_t *nodeWorldAreas;
  int *numNodeWorldAreas;
};
