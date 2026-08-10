#pragma once

#include "idlib/geometry/screenrect.h"
#include "idlib/math/matrix.h"
#include "idlib/math/vector.h"

class idMaterial;
class idRenderModel;
enum dimShadow_t : int;
enum highlightColor_t : int;

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\rendermodelparms.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13664; PDB kind: class.
class idRenderModelParms
{
public:
  idVec3 origin;
  idMat3 axis;
  idVec3 scale;
  const idMaterial *customMaterial;
  int customSkin;
  int groupMasterIndex;
  int allowSurfaceOnlyInViewID;
  int suppressSurfaceInViewID;
  int suppressShadowInViewID;
  int suppressShadowInLightIndex;
  int firstVisibleFrameCount;
  float fovScale;
  float modelDepthHack;
  dimShadow_t castDimShadows;
  __int8 augmentShowOnlyWhenOccluded : 1;
  __int8 isAugment : 1;
  __int8 isSceneModel : 1;
  __int8 isSky : 1;
  __int8 isWorld : 1;
  __int8 isStatic : 1;
  __int8 allowUpShadows : 1;
  __int8 allowHighQualityDimShadows : 1;
  __int8 mvpIsIdentity : 1;
  __int8 viewOriented : 1;
  __int8 addAlways : 1;
  __int8 megatexturedModel : 1;
  __int8 acceptDimShadows : 1;
  __int8 staticShadowsFromDynamicModel : 1;
  __int8 noInteractions : 1;
  __int8 noShadow : 1;
  __int8 privateLightOnly : 1;
  __int8 addAlwaysForceOcclusionQuery : 1;
  __int8 alwaysOcclusionCullBounds : 1;
  __int8 neverOcclusionCullBounds : 1;
  __int8 noGPUocclusionTest : 1;
  __int8 woundsActive : 1;
  __int8 mvpIsSunFlare : 1;
  __int8 mvpIsOrthographic : 1;
  unsigned __int8 : 2;
  __int8 enableStaticSpecular : 1;
  __int8 forceApproximatedLighting : 1;
  __int8 noAmbient : 1;
  __int8 boostLightingPoint : 1;
  __int8 moveLightingPoint : 1;
  __int8 noLocalLighting : 1;
  unsigned __int32 : 24;
  __int32 traceGroup : 8;
  float radiosityScale;
  unsigned __int8 : 5;
  __int8 noStippleFade : 1;
  __int8 rebakeModel : 1;
  __int8 radiosityPreview : 1;
  float staticReflectionStrength;
  highlightColor_t highlightColor;
  float dimShadowClipZ;
  float maxTexelDensity;
  float modelFade;
  float maxVisibleRange;
  float fadeVisibilityOver;
  idRenderModel *referenceModel;
  idScreenRect viewport;
};
