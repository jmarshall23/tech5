#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\renderview.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13534; PDB kind: struct.
struct __declspec(align(16)) renderView_t
{
  int renderTime;
  int viewID;
  bool forceFullVirtualTextureLoad;
  bool discontinuousViewPosition;
  bool skipDimShadows;
  bool skipPostProcess;
  bool skipDynamicEnvironment;
  bool forceFullResolution;
  bool useHQViewColorMipsGeneration;
  float fov_x;
  float fov_y;
  bool cramZNear;
  idRenderMatrix explicitProjectionMatrix;
  bool useExplicitProjectionMatrix;
  idVec3 vieworg;
  idMat3 viewaxis;
  bool forceIdentityViewMatrix;
  idStaticParmBlock<32> parmBlock;
  const idDeclEnv *dynEnvOverride;
  float dynEnvOverrideDuration;
  int dynEnvOverrideModelIndex;
  bool applyDynEnvOverride;
  idStaticParmBlock<32> envOverrideParmBlock;
  bool radialBlurEnabled;
  idVec3 radialBlurCenterPos;
  bool godRaysEnabled;
  bool godRaysRelativeToCamera;
  idVec3 godRaysPosition;
  idVec3 godRaysColor;
  float godRaysSize;
  float godRaysSourceSize;
  const idMaterial *godRaysMaterial;
};

// IDA Local Type ordinal 13537; PDB kind: class.
class __declspec(align(16)) idRenderView
{
public:
  renderView_t g;
  idImage *imgViewColor;
  int viewIndex;
  envBlend_t envBlend;
  idParmBlock blendedEnvironmentParms;
  renderView_t r;
  idRenderMatrix projectionMatrix;
  idRenderMatrix inverseProjectionMatrix;
  idRenderMatrix viewMatrix;
  idRenderMatrix inverseViewMatrix;
  idRenderMatrix worldSpaceMVPMatrix;
  idRenderMatrix worldSpaceInverseMVPMatrix;
  idRenderMatrix viewSpaceModelMatrix;
  idRenderMatrix viewSpaceInverseModelMatrix;
  idRenderMatrix viewSpaceMVPMatrix;
  int windowWidth;
  int windowHeight;
  int renderWidth;
  int renderHeight;
  int feedbackWidth;
  int feedbackHeight;
  idScreenRect viewport;
  idScreenRect scissorRect;
  idScreenRect testScissor;
  __int64 firstOcclusionQueryInPreviousFrame;
  occlusionState_t *occlusionState;
};

// IDA Local Type ordinal 13602; PDB kind: struct.
const struct foliageRenderView_t
{
  float time;
  float nearDist;
  float farDist;
  float fov[2];
  idVec3 viewOrg;
  idVec3 viewFwd;
  idVec3 viewLeft;
  idVec3 viewUp;
  idRenderMatrix mvpMatrix;
  unsigned __int16 atlasWidth;
  unsigned __int16 atlasHeight;
  int pad[2];
};

// IDA Local Type ordinal 13624; PDB kind: struct.
const struct detailRenderView_t
{
  float time;
  float nearDist;
  float farDist;
  float fov[2];
  idVec3 viewOrg;
  idVec3 viewFwd;
  idVec3 viewLeft;
  idVec3 viewUp;
  int pad[3];
  idRenderMatrix mvpMatrix;
};

// IDA Local Type ordinal 14014; PDB kind: struct.
struct particleRenderView_t
{
  idVec3 viewOrg;
  idVec3 viewFwd;
  idVec3 viewLeft;
  idVec3 viewUp;
  int renderTime;
  int deltaTime;
  unsigned __int16 atlasWidth;
  unsigned __int16 atlasHeight;
  int pad;
};
