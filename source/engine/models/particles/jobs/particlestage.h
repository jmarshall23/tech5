#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\particles\jobs\particlestage.h
// Recovered logical types: 20
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13434; PDB kind: struct.
struct __declspec(align(4)) idParticleStage::prtStageProperties_t
{
  const idMaterial *material;
  __int16 totalParticles;
  __int16 cycles;
  int diversity;
  idParticleParm particleLife;
  float timeOffset;
  idParticleParm deadTime;
  float useSysTime;
  float spawnBunching;
  float emissionTime;
  prtTextureFlipMode_t textureFlipS;
  prtTextureFlipMode_t textureFlipT;
  idParticleParm windBias;
  prtSortType_t sortType;
  float boundsExpansion;
  bool randomOnCycle;
};

// IDA Local Type ordinal 13435; PDB kind: struct.
struct __declspec(align(4)) idParticleStage::prtDistribution_t
{
  prtDistributionType_t type;
  idParticleParm size[3];
  bool random;
};

// IDA Local Type ordinal 13436; PDB kind: struct.
struct idParticleStage::prtOrientation_t
{
  prtOrientationType_t type;
  __int16 numTrails;
  float segmentLength;
  float viewFade;
  bool orientToVelOnly;
  bool world;
  bool aimedSafeQuad;
  float aimedSafeQuadAlign;
  float depthOffset;
};

// IDA Local Type ordinal 13437; PDB kind: struct.
struct idParticleStage::prtDirection_t
{
  prtDirectionType_t type;
  float parms[4];
  float angleOffsetStart[2];
  float angleOffsetRange[2];
  idMat3 coneAxis;
};

// IDA Local Type ordinal 13438; PDB kind: struct.
struct idParticleStage::prtSpeed_t
{
  idParticleParm speed[3];
};

// IDA Local Type ordinal 13439; PDB kind: struct.
struct __declspec(align(4)) idParticleStage::prtAcceleration_t
{
  idParticleParm acceleration[3];
  bool world;
};

// IDA Local Type ordinal 13440; PDB kind: struct.
struct __declspec(align(4)) idParticleStage::prtGravity_t
{
  idParticleParm gravity;
  bool world;
};

// IDA Local Type ordinal 13441; PDB kind: struct.
struct idParticleStage::prtFriction_t
{
  idParticleParm friction[3];
};

// IDA Local Type ordinal 13442; PDB kind: struct.
struct idParticleStage::prtOffset_t
{
  idParticleParm offset[3];
};

// IDA Local Type ordinal 13443; PDB kind: struct.
struct idParticleStage::prtSpawnLocation_t
{
  idParticleParm spawnLocation[3];
};

// IDA Local Type ordinal 13444; PDB kind: struct.
struct idParticleStage::prtColorAttributes_t
{
  idParticleParm baseColor[4];
  idVec4 fadeColor;
  float fadeInFraction;
  float fadeOutFraction;
  float fadeIndexFraction;
  float softParticleAlphaScale;
  idParticleParm brightness;
  bool useGlobalShadows;
  float minShadowVal;
  float entityColorBlendVal;
};

// IDA Local Type ordinal 13445; PDB kind: struct.
struct __declspec(align(4)) idParticleStage::prtRotation_t
{
  idParticleParm rotation[3];
  bool allowRotDirOverride;
};

// IDA Local Type ordinal 13446; PDB kind: struct.
struct idParticleStage::prtInitialRotation_t
{
  idParticleParm initialAngle[3];
};

// IDA Local Type ordinal 13447; PDB kind: struct.
struct idParticleStage::prtPivot_t
{
  idVec2 pivotOffset;
};

// IDA Local Type ordinal 13448; PDB kind: struct.
struct idParticleStage::prtSize_t
{
  idParticleParm size[3];
  idParticleParm aspectRatio;
};

// IDA Local Type ordinal 13449; PDB kind: struct.
struct idParticleStage::prtTexAnimation_t
{
  prtAnimationType_t type;
  unsigned __int16 numColumns;
  unsigned __int16 numRows;
  idParticleParm rate;
  __int16 startFrame;
  bool useRandomRow;
  bool useFrameBlending;
};

// IDA Local Type ordinal 13450; PDB kind: struct.
struct idParticleStage::prtCustomPath_t
{
  prtCustomPthType_t type;
  idParticleParm parms[5];
};

// IDA Local Type ordinal 13451; PDB kind: struct.
struct idParticleStage::prtGenericParms_t
{
  idParticleParm genericParm[4];
};

// IDA Local Type ordinal 13452; PDB kind: struct.
struct idParticleStage::prtLODParms_t
{
  float sizeScale;
  float lerpAmount;
  __int16 radius;
  __int16 totalParticles;
};

// IDA Local Type ordinal 13453; PDB kind: class.
class idParticleStage
{
public:
  const idStaticParticleModelData *staticData;
  const idDrawVert *staticVerts;
  int numStaticVerts;
  int cycleMsec;
  float maxParticleLife;
  float maxDeadTime;
  float bunchTime;
  idBounds bounds;
  idVec4 atlasScaleBias;
  unsigned __int8 : 3;
  __int8 hidden : 1;
  __int8 hasEmissivePass : 1;
  __int8 usesTransSortAtlas : 1;
  __int8 isTransparencySorted : 1;
  __int8 alphaBlended : 1;
  idParticleStage::prtStageProperties_t systemProperties;
  idParticleStage::prtDistribution_t distribution;
  idParticleStage::prtOrientation_t orientation;
  idParticleStage::prtDirection_t direction;
  idParticleStage::prtSpeed_t speed;
  idParticleStage::prtAcceleration_t acceleration;
  idParticleStage::prtGravity_t gravity;
  idParticleStage::prtFriction_t friction;
  idParticleStage::prtOffset_t offset;
  idParticleStage::prtSpawnLocation_t spawnLocation;
  idParticleStage::prtColorAttributes_t colorAttributes;
  idParticleStage::prtRotation_t rotation;
  idParticleStage::prtInitialRotation_t initialRotation;
  idParticleStage::prtPivot_t pivot;
  idParticleStage::prtSize_t size;
  idParticleStage::prtTexAnimation_t texAnimation;
  idParticleStage::prtCustomPath_t customPath;
  idParticleStage::prtGenericParms_t genericParm;
  idParticleStage::prtLODParms_t lodParms;
};
