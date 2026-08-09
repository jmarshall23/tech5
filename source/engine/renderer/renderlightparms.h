#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\renderlightparms.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13575; PDB kind: class.
class idRenderLightParms
{
public:
  idMat3 axis;
  idVec3 origin;
  int allowLightOnlyInViewID;
  int suppressLightInViewID;
  lightType_t lightType;
  lightClass_t lightClass;
  lightFallOff_t lightFalloff;
  bool noShadows;
  bool slowLight;
  const idMaterial *shader;
  idVec3 lightRadius;
  idVec3 lightCenter;
  idVec3 target;
  idVec3 right;
  idVec3 up;
  idVec3 start;
  idVec3 end;
  idVec3 dynamicModelLightingScale;
  float dimShadowStretch;
  float maxVisibleRange;
  float fadeVisibilityOver;
  float staticSpecularScale;
  idVec3 staticSpecularVector;
  bool bakedParallelShadows;
  const idIESfile *iesFile;
  float iesPowerScale;
  float iesAreaScale;
  float areaLightSize;
  float shadowSampleScale;
  int slowMultiPass;
};

// IDA Local Type ordinal 22923; PDB kind: struct.
struct renderLightsParms_t
{
  const renderSettings_t *settings;
  const idRenderView *renderView;
  renderDrawSurfParms_t drawSurfParms;
  renderShadowBufferParms_t shadowBufferParms;
  const idRenderLightCommitted **viewLights;
  int numViewLights;
  const idRenderModelCommitted **viewModels;
  int numViewModels;
  const idRenderModelSurface **viewWorldSurfaces;
  int numViewWorldSurfaces;
  const idDeclRenderParm *rpLightRotation;
  const idDeclRenderParm *rpLightTranslation;
  const idDeclRenderParm *rpLightScale;
  const idDeclRenderParm *rpLightOscillationAmp;
  const idDeclRenderParm *rpLightOscillationFreq;
  const idDeclRenderParm *rpLightOscillationPhase;
  const idDeclRenderParm *rpWindowPosToProjectedTexS;
  const idDeclRenderParm *rpWindowPosToProjectedTexT;
  const idDeclRenderParm *rpWindowPosToProjectedTexR;
  const idDeclRenderParm *rpWindowPosToProjectedTexQ;
  const idDeclRenderParm *rpWindowPosToProjectedShadowS;
  const idDeclRenderParm *rpWindowPosToProjectedShadowT;
  const idDeclRenderParm *rpWindowPosToProjectedShadowR;
  const idDeclRenderParm *rpWindowPosToProjectedShadowQ;
  const idDeclRenderParm *rpShadowProjectionS;
  const idDeclRenderParm *rpShadowProjectionT;
  const idDeclRenderParm *rpShadowProjectionR;
  const idDeclRenderParm *rpShadowProjectionQ;
  const idDeclRenderParm *rpGlobalLightOrigin;
  const idDeclRenderParm *rpStaticSpecularScale;
  const idDeclRenderParm *rpStaticSpecularVector;
  const idDeclRenderParm *rpLightProjectionS;
  const idDeclRenderParm *rpLightProjectionT;
  const idDeclRenderParm *rpLightProjectionR;
  const idDeclRenderParm *rpLightProjectionQ;
  const idDeclRenderParm *rpLocalToLightS;
  const idDeclRenderParm *rpLocalToLightT;
  const idDeclRenderParm *rpLocalToLightR;
  const idDeclRenderParm *rpLocalToLightQ;
  const idDeclRenderParm *rpLightFade;
  const idDeclRenderProg *progDepthOnly;
  const idDeclRenderProg *progBlendedLightDebugDraw;
  const idDeclRenderProg *progDeferredPointLight;
  const idDeclRenderProg *progDeferredSpotLight;
  const idDeclRenderProg *progDeferredParallelLight;
  const idRenderDestination *renderDestDefault;
  const idTriangles *zeroOneCubeTris;
  const bool *binaryModelState;
  int *numShadows;
};
