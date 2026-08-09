#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\view.h
// Recovered logical types: 8
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1175; PDB kind: unknown.
enum idView::<unnamed_tag> : __int32
{
  DAMAGE_BORDER_EFFECT_TOP = 0x0,
  DAMAGE_BORDER_EFFECT_BOTTOM = 0x1,
  DAMAGE_BORDER_EFFECT_LEFT = 0x2,
  DAMAGE_BORDER_EFFECT_RIGHT = 0x3,
  MAX_DAMAGE_BORDER_EFFECTS = 0x4,
  DAMAGE_MATERIAL_FILTER = 0x0,
  DAMAGE_MATERIAL_SCREEN = 0x1,
  MAX_DAMAGE_MATERIALS = 0x2,
  DAMAGE_BORDER_SMALL = 0x0,
  DAMAGE_BORDER_BIG = 0x1,
  MAX_DAMAGE_BORDER_MATERIALS = 0x2,
};

// IDA Local Type ordinal 15316; PDB kind: struct.
struct idView::radialBlurParms_t
{
  idInterpolate<float> radialBlurInterpolate;
  idVec3 centerPos;
  int handle;
  float scaleVal;
  float blurVal;
  bool enabled;
  bool ramp;
  bool screenSpaceCenter;
  bool interpolate;
};

// IDA Local Type ordinal 15317; PDB kind: struct.
struct idView::screenEffectGen_t
{
  float x;
  float y;
  float w;
  float h;
  float s1;
  float t1;
  float s2;
  float t2;
  float driftAmount;
  int delay;
};

// IDA Local Type ordinal 15318; PDB kind: struct.
struct idView::screenEffect_t
{
  const idMaterial *material;
  int endTime;
  int fadeStartTime;
  int startTime;
  idView::screenEffectGen_t genParms[10];
  int numGenParms;
};

// IDA Local Type ordinal 15319; PDB kind: struct.
struct idView::damageEffectMaterial_t
{
  const idMaterial *materials[2];
};

// IDA Local Type ordinal 15320; PDB kind: struct.
struct idView::damageEffect_t
{
  idView::damageEffectMaterial_t effectMaterial;
  idInterpolate<float> amount;
};

// IDA Local Type ordinal 15321; PDB kind: class.
class idView
{
public:
  idRenderModelGui *guiModel;
  renderView_t gameview;
  float baseFovX;
  const idMaterial *whiteMaterial;
  bool allowViewIDOnly;
  bool forceVirtualMaterialLoad;
  bool useHQViewColorMipsGeneration;
  idVec3 viewVelocity;
  bool skipViewEffects;
  idInterpolate<float> damageScaleTracker;
  const idDeclEnv *overrideEnv;
  float overrideEnvBlendDuration;
  int overrideEnvModelIndex;
  bool envOverrideEnabled;
  idStaticParmBlock<32> envParms;
  float controllerShakeHighMag;
  float controllerShakeLowMag;
  int controllerShakeHighTime;
  int controllerShakeLowTime;
  int kickFinishTime;
  idAngles kickAngles;
  bool isBobEnabled;
  idVec3 viewBob;
  idAngles viewBobAngles;
  idVec4 fadeColor;
  idVec4 fadeToColor;
  idVec4 fadeFromColor;
  float fadeRate;
  int fadeTime;
  float shakeVolume;
  float cameraShake;
  float playerMaxShakeScale;
  idAngles maxShakeAngles;
  idVec3 maxShakeOffset;
  idAngles whiplashGoal;
  idAngles whiplashVel;
  idAngles whiplashCur;
  idInterpolate<float> blur;
  const idDeclRenderParm *blurParm;
  idInterpolate<float> dbl;
  const idDeclRenderParm *dblVParm;
  idView::radialBlurParms_t radialBlur[4];
  const idDeclRenderParm *rpRadialBlurEnable;
  const idDeclRenderParm *rpRadialBlurVal;
  const idDeclRenderParm *rpRadialBlurScaleVal;
  const idDeclRenderParm *rpRadialBlurCenter;
  bool godRaysEnabled;
  bool godRaysRelativeToCamera;
  idVec3 godRaysPosition;
  int godRaysSize;
  int godRaysSourceSize;
  idVec3 godRaysColor;
  const idMaterial *godRaysMaterial;
  idView::screenEffect_t screenEffects[8];
  float whiplashUpdateFrac;
  float whiplashVelocityFrac;
  float whiplashFrictionFrac;
  float whiplashMinVelocityLen;
  idView::damageEffectMaterial_t borderDamageMaterials[2];
  idView::damageEffect_t borderDamageEffects[4];
  idRenderMatrix worldSpaceMVPMatrix;
  int lastMatrixUpdateFrame;
};

// IDA Local Type ordinal 17663; PDB kind: struct.
struct idView::damageOverlayData_t
{
  idVec4 topLeft;
  idVec4 topRight;
  idVec4 bottomLeft;
  idVec4 bottomRight;
  const idView::damageEffectMaterial_t *effectMaterial;
  int alpha;
};
