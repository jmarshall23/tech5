#pragma once

class idDeclRenderParm;

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\autorenderparms.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17440; PDB kind: class.
class idAutoRenderParms
{
public:
	idAutoRenderParms();

  const idDeclRenderParm *If;
  const idDeclRenderParm *Time;
  const idDeclRenderParm *Color;
  const idDeclRenderParm *coverage;
  const idDeclRenderParm *modelFade;
  const idDeclRenderParm *useSkinBlending;
  const idDeclRenderParm *exposure;
  const idDeclRenderParm *TimeScale;
  const idDeclRenderParm *TimeOffset;
  const idDeclRenderParm *TimeStop;
  const idDeclRenderParm *Diversity;
  const idDeclRenderParm *Wind;
  const idDeclRenderParm *NoShadows;
  const idDeclRenderParm *polygonOffset;
  const idDeclRenderParm *lightColor;
  const idDeclRenderParm *lightScale;
  const idDeclRenderParm *lightProjectMap;
  const idDeclRenderParm *lightFalloffMap;
  const idDeclRenderParm *globalViewOrigin;
  const idDeclRenderParm *globalViewFwd;
  const idDeclRenderParm *globalViewLeft;
  const idDeclRenderParm *globalViewUp;
  const idDeclRenderParm *stageProgram;
  const idDeclRenderParm *interactionProgram;
  const idDeclRenderParm *shadowProgram;
  const idDeclRenderParm *depthFillProgram;
  const idDeclRenderParm *addProgram;
  const idDeclRenderParm *blendProgram;
  const idDeclRenderParm *stageSort;
  const idDeclRenderParm *sortCoverage;
  const idDeclRenderParm *sortSkybox;
  const idDeclRenderParm *sortBackground;
  const idDeclRenderParm *sortEmit;
  const idDeclRenderParm *sortEmitOnly;
  const idDeclRenderParm *sortLight;
  const idDeclRenderParm *sortDecal;
  const idDeclRenderParm *sortTransSort;
  const idDeclRenderParm *sortTrans;
  const idDeclRenderParm *sortWater;
  const idDeclRenderParm *sortPerturber;
  const idDeclRenderParm *surfaceFlags;
  const idDeclRenderParm *contentFlags;
  const idDeclRenderParm *toolsFlags;
  const idDeclRenderParm *surfaceType;
  const idDeclRenderParm *skipSurfaceInfo;
  const idDeclRenderParm *discrete;
  const idDeclRenderParm *noFragment;
  const idDeclRenderParm *editorImage;
  const idDeclRenderParm *editorDraw;
  const idDeclRenderParm *editorAlpha;
  const idDeclRenderParm *viewMatrix[4];
  const idDeclRenderParm *inverseViewMatrix[4];
  const idDeclRenderParm *modelMatrix[4];
  const idDeclRenderParm *inverseModelMatrix[4];
  const idDeclRenderParm *projectionMatrix[4];
  const idDeclRenderParm *inverseProjectionMatrix[4];
  const idDeclRenderParm *mvpMatrix[4];
  const idDeclRenderParm *worldSpaceInverseMVPMatrix[4];
  const idDeclRenderParm *powerMip;
  const idDeclRenderParm *diffuseMap;
  const idDeclRenderParm *specularMap;
  const idDeclRenderParm *bumpMap;
  const idDeclRenderParm *powerMap;
  const idDeclRenderParm *coverMap;
  const idDeclRenderParm *virtualTransMap;
  const idDeclRenderParm *transMap;
  const idDeclRenderParm *textureMap;
  const idDeclRenderParm *sMatrix;
  const idDeclRenderParm *tMatrix;
  const idDeclRenderParm *rMatrix;
  const idDeclRenderParm *qMatrix;
  const idDeclRenderParm *select;
  const idDeclRenderParm *virtualMapping;
  const idDeclRenderParm *positionToViewTexture;
  const idDeclRenderParm *renderPositionToViewTexture;
  const idDeclRenderParm *positionToFeedback;
  const idDeclRenderParm *ambientLightColor;
  const idDeclRenderParm *channelLight[6];
  const idDeclRenderParm *primeLightDir;
  const idDeclRenderParm *primeLightColor;
  const idDeclRenderParm *highlightColor;
  const idDeclRenderParm *landPageFile;
  const idDeclRenderParm *renderBump;
  const idDeclRenderParm *stampCovers;
  const idDeclRenderParm *stampScales;
  const idDeclRenderParm *stampBlendMode;
  const idDeclRenderParm *stampBlendModeNone;
  const idDeclRenderParm *depthOfField;
  const idDeclRenderParm *radialBlurCenter;
  const idDeclRenderParm *globalBlur;
  const idDeclRenderParm *doubleVision;
};
