
// ========================================================================
// ?SetViewID@idView@@QAAXH@Z
// EA  : 0x82E85CA8
// RVA : 0x00E85CA8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::SetViewID(idView *this, int id)
{
  this->gameview.viewID = id;
}


// ========================================================================
// ?GetFOV@idView@@QBAXAAM0@Z
// EA  : 0x82E85CB0
// RVA : 0x00E85CB0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::GetFOV(idView *this, float *fov_x, float *fov_y)
{
  *fov_x = this->gameview.fov_x;
  *fov_y = this->gameview.fov_y;
}


// ========================================================================
// ?ResetControllerShake@idView@@QAAXXZ
// EA  : 0x82E85CC8
// RVA : 0x00E85CC8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::ResetControllerShake(idView *this)
{
  this->controllerShakeHighTime = 0;
  this->controllerShakeLowTime = 0;
  this->controllerShakeHighMag = 0.0;
  this->controllerShakeLowMag = 0.0;
}


// ========================================================================
// ?SetEnvironmentOverride@idView@@QAAXPBVidDeclEnv@@MH@Z
// EA  : 0x82E85CE8
// RVA : 0x00E85CE8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::SetEnvironmentOverride(
        idView *this,
        const idDeclEnv *env,
        double blendDuration,
        int modelIndex,
        int a5)
{
  this->overrideEnvBlendDuration = blendDuration;
  this->overrideEnv = env;
  this->overrideEnvModelIndex = a5;
  this->envOverrideEnabled = true;
}


// ========================================================================
// ?ClearEnvironmentParm@idView@@QAAXPBVidDeclRenderParm@@M@Z
// EA  : 0x82E85D00
// RVA : 0x00E85D00
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::ClearEnvironmentParm(idView *this, const idDeclRenderParm *parm, double blendDuration)
{
  idParmBlock::ClearParm(this: &this->envParms, parm);
  this->overrideEnvBlendDuration = blendDuration;
}


// ========================================================================
// ?RemoveRadialBlur@idView@@QAAXAAH@Z
// EA  : 0x82E85D40
// RVA : 0x00E85D40
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::RemoveRadialBlur(idView *this, int *handle)
{
  int v2; // r11
  int *i; // r10

  if ( *handle != -1 )
  {
    v2 = 0;
    for ( i = &this->radialBlur[0].handle; *i != *handle; i += 13 )
    {
      if ( ++v2 >= 4 )
        return;
    }
    this->radialBlur[v2].enabled = false;
    *handle = -1;
  }
}


// ========================================================================
// ?GetOldestScreenEffect@idView@@AAAPAUscreenEffect_t@1@XZ
// EA  : 0x82E85D90
// RVA : 0x00E85D90
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

idView::screenEffect_t *__fastcall idView::GetOldestScreenEffect(idView *this)
{
  idView::screenEffect_t *screenEffects; // r10
  int endTime; // r9
  idView::screenEffect_t *result; // r3

  screenEffects = this->screenEffects;
  if ( this->screenEffects[1].endTime < this->screenEffects[0].endTime )
    screenEffects = &this->screenEffects[1];
  if ( this->screenEffects[2].endTime < screenEffects->endTime )
    screenEffects = &this->screenEffects[2];
  if ( this->screenEffects[3].endTime < screenEffects->endTime )
    screenEffects = &this->screenEffects[3];
  if ( this->screenEffects[4].endTime < screenEffects->endTime )
    screenEffects = &this->screenEffects[4];
  if ( this->screenEffects[5].endTime < screenEffects->endTime )
    screenEffects = &this->screenEffects[5];
  if ( this->screenEffects[6].endTime < screenEffects->endTime )
    screenEffects = &this->screenEffects[6];
  endTime = this->screenEffects[7].endTime;
  result = &this->screenEffects[7];
  if ( endTime >= screenEffects->endTime )
    return screenEffects;
  return result;
}


// ========================================================================
// ??1idView@@QAA@XZ
// EA  : 0x82E85E38
// RVA : 0x00E85E38
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::~idView(idView *this)
{
  idRenderModelGui *guiModel; // r3

  guiModel = this->guiModel;
  if ( guiModel != nullptr )
  {
    guiModel->unlinked = true;
    guiModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: guiModel);
    this->guiModel = nullptr;
  }
  this->godRaysEnabled = false;
  idParmBlock::~idParmBlock(this: &this->envParms);
  renderView_t::~renderView_t(this: &this->gameview);
}


// ========================================================================
// __unwind$490205_0
// EA  : 0x82E85E94
// RVA : 0x00E85E94
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void _unwind_490205_0()
{
  int v0; // r12

  renderView_t::~renderView_t(this: (renderView_t *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$490206_0
// EA  : 0x82E85EC0
// RVA : 0x00E85EC0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void _unwind_490206_0()
{
  int v0; // r12

  idStaticParmBlock<32>::~idStaticParmBlock<32>(this: (idStaticParmBlock<32> *)(*(_DWORD *)(v0 - 128 + 148) + 1968));
}


// ========================================================================
// ?SetViewPos@idView@@QAAXABVidVec3@@ABVidAngles@@@Z
// EA  : 0x82E85EF0
// RVA : 0x00E85EF0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::SetViewPos(idView *this, const idVec3 *origin, idMat3 *angles)
{
  idAngles v3[4]; // [sp+50h] [-40h] BYREF

  this->gameview.vieworg = *origin;
  this->gameview.viewaxis = *idAngles::ToMat3(this: v3, result: angles);
}


// ========================================================================
// ?SetViewPos@idView@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82E85F90
// RVA : 0x00E85F90
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::SetViewPos(idView *this, const idVec3 *origin, const idMat3 *axis)
{
  this->gameview.vieworg = *origin;
  this->gameview.viewaxis = *axis;
}


// ========================================================================
// ?GetViewPos@idView@@QBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82E85FF8
// RVA : 0x00E85FF8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::GetViewPos(idView *this, idVec3 *origin, idMat3 *axis)
{
  *origin = this->gameview.vieworg;
  *axis = this->gameview.viewaxis;
}


// ========================================================================
// ?ForceBlurValues@idView@@QAAXMMM@Z
// EA  : 0x82E86060
// RVA : 0x00E86060
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::ForceBlurValues(idView *this, double blurBegin, double blurEnd, double blurTime)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->blur.duration = blurTime;
  this->blur.startValue = blurBegin;
  this->blur.startTime = (float)__SPAIR64__(0x82000000, GameMs);
  this->blur.endValue = blurEnd;
  this->blur.currentValue = blurBegin;
  this->blur.currentTime = (float)__SPAIR64__(0x82000000, GameMs) - (float)1.0;
}


// ========================================================================
// ?ForceDoubleVisionValues@idView@@QAAXMMM@Z
// EA  : 0x82E86100
// RVA : 0x00E86100
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::ForceDoubleVisionValues(idView *this, double dblDuration, double dblStart, double dblEnd)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->dbl.duration = dblDuration;
  this->dbl.startValue = dblStart;
  this->dbl.startTime = (float)__SPAIR64__(0x82000000, GameMs);
  this->dbl.endValue = dblEnd;
  this->dbl.currentValue = dblStart;
  this->dbl.currentTime = (float)__SPAIR64__(0x82000000, GameMs) - (float)1.0;
}


// ========================================================================
// ?SetControllerShake@idView@@QAAXMHMH@Z
// EA  : 0x82E861A0
// RVA : 0x00E861A0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::SetControllerShake(
        idView *this,
        double highMagnitude,
        int highDuration,
        double lowMagnitude,
        int lowDuration,
        int a6,
        int a7)
{
  int controllerShakeHighTime; // r11
  int GameMs; // r3
  int v18; // r3
  int controllerShakeLowTime; // r11

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) <= this->controllerShakeHighTime )
  {
    _FP13 = (float)((float)highMagnitude - this->controllerShakeHighMag);
    __asm { fsel      f12, f13, f31, f0 }
    this->controllerShakeHighMag = _FP12;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    controllerShakeHighTime = this->controllerShakeHighTime;
    if ( GameMs + lowDuration > controllerShakeHighTime )
      controllerShakeHighTime = GameMs + lowDuration;
  }
  else
  {
    this->controllerShakeHighMag = highMagnitude;
    controllerShakeHighTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                            + lowDuration;
  }
  this->controllerShakeHighTime = controllerShakeHighTime;
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) <= this->controllerShakeLowTime )
  {
    _FP13 = (float)((float)lowMagnitude - this->controllerShakeLowMag);
    __asm { fsel      f12, f13, f30, f0 }
    this->controllerShakeLowMag = _FP12;
    v18 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    controllerShakeLowTime = this->controllerShakeLowTime;
    if ( v18 + a7 > controllerShakeLowTime )
      controllerShakeLowTime = v18 + a7;
    this->controllerShakeLowTime = controllerShakeLowTime;
  }
  else
  {
    this->controllerShakeLowMag = lowMagnitude;
    this->controllerShakeLowTime = idGameTimeManager::GetGameMs(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED)
                                 + a7;
  }
}


// ========================================================================
// ?AngleOffset@idView@@ABA?AVidAngles@@XZ
// EA  : 0x82E862D0
// RVA : 0x00E862D0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

idView *__fastcall idView::AngleOffset(idView *this, idAngles *result)
{
  idClientGame *v4; // r11
  int GameMs; // r3
  double pitch; // fp12
  double yaw; // fp10
  __int64 v8; // r7
  double v9; // fp0
  double v10; // fp12
  double v11; // fp10

  *(float *)&this->guiModel = 0.0;
  v4 = clientGame;
  *((float *)&this->guiModel + 2) = 0.0;
  *((float *)&this->guiModel + 1) = 0.0;
  if ( idGameTimeManager::GetGameMs(this: &v4->gameTimeManager, type: GAMETIME_SCALED) < SLODWORD(result[233].yaw) )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    pitch = result[234].pitch;
    yaw = result[234].yaw;
    LODWORD(v8) = LODWORD(result[233].yaw) - GameMs;
    v9 = (float)(result[233].roll * (float)((float)v8 * (float)v8));
    *(float *)&this->guiModel = result[233].roll * (float)((float)v8 * (float)v8);
    v10 = (float)((float)pitch * (float)((float)v8 * (float)v8));
    *((float *)&this->guiModel + 1) = v10;
    v11 = (float)((float)yaw * (float)((float)v8 * (float)v8));
    *((float *)&this->guiModel + 2) = v11;
    if ( v9 >= -70.0 )
    {
      if ( v9 > 70.0 )
        *(float *)&this->guiModel = 70.0;
    }
    else
    {
      *(float *)&this->guiModel = -70.0;
    }
    if ( v10 >= -70.0 )
    {
      if ( v10 > 70.0 )
        *((float *)&this->guiModel + 1) = 70.0;
    }
    else
    {
      *((float *)&this->guiModel + 1) = -70.0;
    }
    if ( v11 < -70.0 )
    {
      *((float *)&this->guiModel + 2) = -70.0;
      return this;
    }
    if ( v11 > 70.0 )
      *((float *)&this->guiModel + 2) = 70.0;
  }
  return this;
}


// ========================================================================
// ?Fade@idView@@QAAXABVidVec4@@H@Z
// EA  : 0x82E863F0
// RVA : 0x00E863F0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::Fade(idView *this, const idVec4 *color, int time)
{
  __int64 v3; // r11
  int v5; // r29
  double v6; // fp11

  HIDWORD(v3) = this->fadeTime;
  v5 = time;
  if ( HIDWORD(v3) != 0 )
  {
    this->fadeFromColor = this->fadeColor;
  }
  else
  {
    v6 = (float)((float)1.0 - color->w);
    this->fadeFromColor.x = 0.0;
    this->fadeFromColor.y = 0.0;
    this->fadeFromColor.z = 0.0;
    this->fadeFromColor.w = v6;
  }
  this->fadeToColor = *color;
  if ( time > 0 )
  {
    LODWORD(v3) = time;
    this->fadeRate = (float)1.0 / (float)v3;
  }
  else
  {
    this->fadeRate = 0.0;
    v5 = 0;
    this->fadeColor = this->fadeToColor;
  }
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) != 0 || v5 != 0 )
    this->fadeTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + v5;
  else
    this->fadeTime = 1;
}


// ========================================================================
// ?CalcFOV@idView@@QAAXMM@Z
// EA  : 0x82E86530
// RVA : 0x00E86530
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::CalcFOV(float *a1, long double targetAspectRatio)
{
  double v2; // fp31
  long double v4; // fp2
  long double v5; // fp2
  idRenderSystem *v6; // r3
  int (__fastcall *GetWidth)(idRenderSystem *); // r8
  __int64 v8; // r7
  double v9; // fp31
  __int64 v10; // r10
  long double v11; // fp2
  double v12; // fp31
  long double v13; // fp2
  long double v14; // fp2

  v2 = *((double *)&targetAspectRatio + 1);
  if ( *(double *)&targetAspectRatio < 1.0 )
  {
    idLib::Warning(fmt: "idView::CalcFOV: bad FOV value: %f", *(double *)&targetAspectRatio);
    *(double *)&targetAspectRatio = 90.0;
  }
  a1[472] = *(double *)&targetAspectRatio;
  *(double *)&targetAspectRatio = (float)((float)(idMath::M_DEG2RAD * (float)*(double *)&targetAspectRatio) * (float)0.5);
  v4 = tan(x: targetAspectRatio);
  *(double *)&v4 = (float)((float)*(double *)&v4 / (float)v2);
  v5 = atan(x: v4);
  v6 = renderSystem;
  GetWidth = renderSystem->GetWidth;
  a1[9] = (float)(idMath::M_RAD2DEG * (float)*(double *)&v5) * (float)2.0;
  LODWORD(v8) = GetWidth(this: v6);
  v9 = (float)(renderSystem->GetPixelAspect(this: renderSystem) * (float)v8);
  LODWORD(v10) = renderSystem->GetHeight(this: renderSystem);
  v12 = (float)((float)v9 / (float)v10);
  if ( v12 >= 1.0 )
  {
    if ( v12 > 3.0 )
      v12 = 3.0;
  }
  else
  {
    v12 = 1.0;
  }
  *(double *)&v11 = (float)((float)(a1[9] * idMath::M_DEG2RAD) * (float)0.5);
  v13 = tan(x: v11);
  *(double *)&v13 = (float)((float)*(double *)&v13 * (float)v12);
  v14 = atan(x: v13);
  a1[8] = (float)(idMath::M_RAD2DEG * (float)*(double *)&v14) * (float)2.0;
}


// ========================================================================
// ?SetEnvironmentParm@idView@@QAAXPBVidDeclRenderParm@@ABVidVec4@@M@Z
// EA  : 0x82E866B8
// RVA : 0x00E866B8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::SetEnvironmentParm(
        idView *this,
        const idDeclRenderParm *parm,
        const idVec4 *val,
        double blendDuration)
{
  double z; // fp12
  double w; // fp11
  parmValue_t v8; // [sp+50h] [-30h] BYREF

  v8.value[0] = val->x;
  z = val->z;
  w = val->w;
  v8.value[1] = val->y;
  v8.value[2] = z;
  v8.value[3] = w;
  idParmBlock::SetParm(this: &this->envParms, parm, parmValue: &v8);
  this->overrideEnvBlendDuration = blendDuration;
}


// ========================================================================
// ?AddRadialBlur@idView@@QAA_NABVidVec3@@MMMMM@Z
// EA  : 0x82E86720
// RVA : 0x00E86720
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

int __fastcall idView::AddRadialBlur(
        idView *this,
        const idVec3 *centerPos,
        double startTime,
        double duration,
        double minBlur,
        double maxBlur,
        double maxScale)
{
  bool *p_enabled; // r11
  int i; // r9
  char *v9; // r11

  p_enabled = &this->radialBlur[0].enabled;
  for ( i = 0; i < 4; ++i )
  {
    if ( !*p_enabled )
      break;
    p_enabled += 52;
  }
  if ( i == 4
    || (float)((float)(this->gameview.viewaxis.mat[0].x * (float)(centerPos->x - this->gameview.vieworg.x))
             + (float)((float)(this->gameview.viewaxis.mat[0].z * (float)(centerPos->z - this->gameview.vieworg.z))
                     + (float)(this->gameview.viewaxis.mat[0].y * (float)(centerPos->y - this->gameview.vieworg.y)))) <= 0.0 )
  {
    return 0;
  }
  v9 = (char *)this + 52 * i;
  *((_DWORD *)v9 + 766) = -1;
  v9[3076] = 1;
  v9[3077] = 0;
  v9[3078] = 0;
  *(idVec3 *)(v9 + 3052) = *centerPos;
  *((float *)v9 + 757) = startTime;
  *((float *)v9 + 758) = duration;
  *((float *)v9 + 759) = minBlur;
  *((float *)v9 + 760) = maxBlur;
  *((float *)v9 + 761) = (float)startTime - (float)1.0;
  *((float *)v9 + 762) = minBlur;
  v9[3079] = 1;
  this->radialBlur[i].scaleVal = maxScale;
  return 1;
}


// ========================================================================
// ?AddRadialBlur@idView@@QAA_NAAHABVidVec3@@MM@Z
// EA  : 0x82E86820
// RVA : 0x00E86820
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

int __fastcall idView::AddRadialBlur(
        idView *this,
        int *handle,
        const idVec3 *centerPos,
        double blurVal,
        double maxScale)
{
  int v5; // r10
  bool *p_enabled; // r11
  int *p_handle; // r11
  char *v8; // r11
  unsigned int v10; // r8
  int v11; // r7

  v5 = 0;
  if ( *handle == -1 )
  {
    p_enabled = &this->radialBlur[0].enabled;
    do
    {
      if ( !*p_enabled )
        break;
      ++v5;
      p_enabled += 52;
    }
    while ( v5 < 4 );
  }
  else
  {
    p_handle = &this->radialBlur[0].handle;
    do
    {
      if ( *p_handle == *handle )
        break;
      ++v5;
      p_handle += 13;
    }
    while ( v5 < 4 );
  }
  if ( v5 == 4
    || (float)((float)(this->gameview.viewaxis.mat[0].x * (float)(centerPos->x - this->gameview.vieworg.x))
             + (float)((float)(this->gameview.viewaxis.mat[0].z * (float)(centerPos->z - this->gameview.vieworg.z))
                     + (float)(this->gameview.viewaxis.mat[0].y * (float)(centerPos->y - this->gameview.vieworg.y)))) <= 0.0 )
  {
    return 0;
  }
  v8 = (char *)this + 52 * v5;
  v8[3076] = 1;
  v8[3077] = 0;
  v8[3078] = 0;
  v8[3079] = 0;
  *(idVec3 *)(v8 + 3052) = *centerPos;
  this->radialBlur[v5].scaleVal = maxScale;
  *((float *)v8 + 768) = blurVal;
  v10 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v10;
  v11 = (v10 >> 10) & 0x7FFF;
  *handle = v11;
  *((_DWORD *)v8 + 766) = v11;
  return 1;
}


// ========================================================================
// ?ApplyRadialBlur@idView@@AAAXAAUrenderView_t@@@Z
// EA  : 0x82E86960
// RVA : 0x00E86960
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::ApplyRadialBlur(idView *this, renderView_t *view)
{
  __int64 v4; // r7
  bool *p_enabled; // r27
  int v6; // r30
  bool *v7; // r31
  double v8; // fp30
  BOOL v9; // r10
  double v10; // fp0
  double y; // fp0
  double x; // fp13
  const idDeclRenderParm *rpRadialBlurCenter; // r4
  const idDeclRenderParm *rpRadialBlurEnable; // r4
  const idDeclRenderParm *rpRadialBlurVal; // r4
  const idDeclRenderParm *rpRadialBlurScaleVal; // r4
  parmValue_t v19; // [sp+50h] [-90h] BYREF
  parmValue_t v20; // [sp+60h] [-80h] BYREF
  parmValue_t v21; // [sp+70h] [-70h] BYREF
  float v22; // [sp+80h] [-60h] BYREF
  float v23; // [sp+84h] [-5Ch]
  float v24; // [sp+88h] [-58h]
  float v25; // [sp+8Ch] [-54h]

  p_enabled = &this->radialBlur[0].enabled;
  v20.value[3] = 0.0;
  v6 = 0;
  v20.value[2] = 0.0;
  v7 = &this->radialBlur[0].enabled;
  *(_QWORD *)v19.value = __PAIR64__(
                           &unk_82390000,
                           idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
  v20.value[1] = 0.0;
  v20.value[0] = 0.0;
  v25 = 0.0;
  v24 = 0.0;
  v23 = 0.0;
  v8 = (float)((float)*(__int64 *)v19.value * (float)0.001);
  v22 = 0.0;
  v21.value[3] = 0.0;
  v21.value[2] = 0.0;
  v21.value[1] = 0.0;
  v21.value[0] = 0.0;
  do
  {
    v9 = v7[3];
    if ( v7[3] && v8 >= (float)(*((float *)v7 - 12) + *((float *)v7 - 11)) )
      *v7 = false;
    LODWORD(v4) = *v7;
    v10 = *((float *)v7 - 2);
    *(_QWORD *)v19.value = v4;
    *(float *)((char *)&v22 + v6 * 4) = v10;
    v20.value[v6] = (float)v4;
    if ( v9 )
      _FP1 = idInterpolate<float>::GetCurrentValue(this: (idInterpolate<float> *)v7 - 2, time: v8);
    else
      _FP1 = *((float *)v7 - 1);
    if ( v7[1] && v8 > (float)((float)(*((float *)v7 - 11) * (float)0.5) + *((float *)v7 - 12)) )
    {
      _FP11 = (float)((float)(*((float *)v7 - 9) - (float)_FP1) - *((float *)v7 - 10));
      __asm { fsel      f1, f11, f12, f0 }
    }
    v7 += 52;
    v21.value[v6++] = _FP1;
  }
  while ( v6 < 4 );
  if ( *p_enabled )
  {
    if ( this->radialBlur[0].screenSpaceCenter )
    {
      y = this->radialBlur[0].centerPos.y;
      x = this->radialBlur[0].centerPos.x;
      v19.value[2] = 0.0;
      rpRadialBlurCenter = this->rpRadialBlurCenter;
      v19.value[3] = 0.0;
      v19.value[1] = y;
      v19.value[0] = x;
      idParmBlock::SetParm(this: &view->parmBlock, parm: rpRadialBlurCenter, parmValue: &v19);
    }
    else
    {
      view->radialBlurEnabled = true;
      view->radialBlurCenterPos.x = this->radialBlur[0].centerPos.x;
      view->radialBlurCenterPos.y = this->radialBlur[0].centerPos.y;
      view->radialBlurCenterPos.z = this->radialBlur[0].centerPos.z;
    }
  }
  rpRadialBlurEnable = this->rpRadialBlurEnable;
  v19.value[0] = v20.value[0];
  v19.value[1] = v20.value[1];
  v19.value[2] = v20.value[2];
  v19.value[3] = v20.value[3];
  idParmBlock::SetParm(this: &view->parmBlock, parm: rpRadialBlurEnable, parmValue: &v19);
  rpRadialBlurVal = this->rpRadialBlurVal;
  v20.value[0] = v21.value[0];
  v20.value[1] = v21.value[1];
  v20.value[2] = v21.value[2];
  v20.value[3] = v21.value[3];
  idParmBlock::SetParm(this: &view->parmBlock, parm: rpRadialBlurVal, parmValue: &v20);
  rpRadialBlurScaleVal = this->rpRadialBlurScaleVal;
  v21.value[0] = v22;
  v21.value[1] = v23;
  v21.value[2] = v24;
  v21.value[3] = v25;
  idParmBlock::SetParm(this: &view->parmBlock, parm: rpRadialBlurScaleVal, parmValue: &v21);
}


// ========================================================================
// ?ApplyDoubleVision@idView@@AAAXAAUrenderView_t@@@Z
// EA  : 0x82E86BE0
// RVA : 0x00E86BE0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::ApplyDoubleVision(idView *this, renderView_t *view)
{
  __int64 v4; // r9
  double CurrentValue; // fp31
  signed int valueInteger; // r28
  int v7; // r3
  __int64 v8; // r9
  __int64 v9; // r6
  long double v10; // fp2
  long double v11; // fp2
  double pitch; // fp3
  const idDeclRenderParm *doubleVision; // r4
  parmValue_t v14; // [sp+50h] [-40h] BYREF

  LODWORD(v4) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  *(_QWORD *)v14.value = v4;
  CurrentValue = idInterpolate<float>::GetCurrentValue(this: &this->dbl, time: (float)v4);
  valueInteger = view_doubleVisionPeriod.valueInteger;
  v7 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  HIDWORD(v8) = v7 / valueInteger * valueInteger;
  LODWORD(v8) = view_doubleVisionPeriod.valueInteger;
  LODWORD(v9) = v7 % valueInteger;
  *(_QWORD *)v14.value = v9;
  __twllei(valueInteger, 0);
  __twlgei(valueInteger & ~(__ROL4__(v7, 1) - 1), 0xFFFFFFFF);
  *(double *)&v10 = (float)((float)((float)((float)v9 / (float)v8) * (float)3.1415927) * (float)2.0);
  v11 = sin(x: v10);
  pitch = this->kickAngles.pitch;
  v14.value[2] = 0.0;
  v14.value[3] = 0.0;
  doubleVision = rp->doubleVision;
  v14.value[0] = (float)((float)(view_doubleVisionPeriodEffect.valueFloat * (float)*(double *)&v11) + (float)1.0)
               * (float)CurrentValue;
  v14.value[1] = (float)((float)pitch * (float)CurrentValue) + (float)(v14.value[0] * (float)0.2);
  idParmBlock::SetParm(this: &view->parmBlock, parm: doubleVision, parmValue: &v14);
}


// ========================================================================
// ?AddScreenDamageEffect@idView@@QAAXABUdamageScreenEffectParms_t@idDeclDamage@@@Z
// EA  : 0x82E86D38
// RVA : 0x00E86D38
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idView::AddScreenDamageEffect(idView *this, const idDeclDamage::damageScreenEffectParms_t *parms)
{
  idClientGame *v3; // r7
  double x; // fp0
  idClientGame *v5; // r6
  double v6; // fp12
  __int128 v7; // r6 OVERLAPPED
  double v8; // fp11
  unsigned int seed; // r6
  double v10; // fp9
  unsigned int v11; // r7
  __int64 v12; // fp8
  double v13; // fp7
  double v14; // fp4
  idClientGame *v15; // r10
  int v16; // r7
  double v17; // fp3
  idClientGame *v18; // r10
  double v19; // fp6
  double v20; // fp1
  double v21; // fp13
  __int64 v22; // r9
  double v23; // fp27
  double v24; // fp22
  double v25; // fp28
  double v26; // fp29
  double v27; // fp26
  double v28; // fp19
  idView::screenEffect_t *OldestScreenEffect; // r3
  int numQuads; // r11
  idView::screenEffect_t *v31; // r26
  int GameMs; // r3
  double v33; // fp23
  __int64 v34; // r4 OVERLAPPED
  __int64 v35; // r9
  __int64 v36; // r7
  double v37; // fp29
  int v38; // r23
  double v39; // fp28
  double v40; // fp30
  double v41; // fp27
  double v42; // fp20
  double v43; // fp26
  float *p_driftAmount; // r27
  double v45; // fp0
  __int64 v46; // r7
  idClientGame *v47; // r11
  int v48; // r5
  __int128 v49; // r10
  double v50; // fp11
  double v51; // fp10
  double v52; // fp12
  double v53; // fp13
  idClientGame *v54; // r11
  BOOL v55; // r10
  bool v56; // cr58
  double v57; // fp0
  double v58; // fp9
  double v59; // fp8

  if ( parms->screenDamageTime > 0.0
    && parms->screenDamageMtr != nullptr
    && g_skipViewEffects.valueInteger == 0
    && view_skipDamageEffect.valueInteger == 0 )
  {
    v3 = clientGame;
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    x = parms->screenDamageSize.x;
    v5 = clientGame;
    v6 = (float)(parms->screenDamageSize.y - parms->screenDamageSize.x);
    DWORD2(v7) = (v3->random.seed >> 10) & 0x7FFF;
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    v8 = parms->offsetPctX.x;
    seed = v5->random.seed;
    v10 = (float)(parms->offsetPctX.y - parms->offsetPctX.x);
    DWORD1(v7) = clientGame->random.seed;
    v11 = 1664525 * clientGame->random.seed + 1013904223;
    v12 = *(_QWORD *)((char *)&v7 + 4);
    clientGame->random.seed = v11;
    DWORD1(v7) = (v11 >> 10) & 0x7FFF;
    v13 = parms->offsetPctY.x;
    v14 = (float)(parms->offsetPctY.y - parms->offsetPctY.x);
    v15 = clientGame;
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    v16 = (seed >> 10) & 0x7FFF;
    LODWORD(v7) = DWORD1(v7);
    DWORD2(v7) = clientGame->random.seed;
    v17 = parms->distribPctX.x;
    v19 = (float)(parms->distribPctX.y - parms->distribPctX.x);
    DWORD1(v7) = (v15->random.seed >> 10) & 0x7FFF;
    v18 = clientGame;
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    v20 = parms->distribPctY.x;
    v21 = (float)(parms->distribPctY.y - parms->distribPctY.x);
    LODWORD(v22) = (v18->random.seed >> 10) & 0x7FFF;
    v23 = (float)((float)((float)((float)((float)(__int64)v7 * (float)0.000061037019) - (float)1.0) * (float)v14)
                + (float)v13);
    DWORD2(v7) = 1664525 * clientGame->random.seed;
    HIDWORD(v22) = DWORD2(v7) + 1013904223;
    v24 = (float)((float)((float)((float)((float)v12 * (float)0.000061037019) - (float)1.0) * (float)v6) + (float)x);
    clientGame->random.seed = DWORD2(v7) + 1013904223;
    v25 = (float)((float)((float)((float)((float)*(__int64 *)&v7 * (float)0.000061037019) - (float)1.0) * (float)v19)
                + (float)v17);
    v26 = (float)((float)((float)((float)((float)*(__int64 *)((char *)&v7 - 4) * (float)0.000061037019) - (float)1.0)
                        * (float)v10)
                + (float)v8);
    LODWORD(v7) = ((unsigned int)(DWORD2(v7) + 1013904223) >> 10) & 0x7FFF;
    v27 = (float)((float)((float)((float)((float)v22 * (float)0.000061037019) - (float)1.0) * (float)v21) + (float)v20);
    v28 = (float)((float)((float)((float)(parms->driftYAmount.y - parms->driftYAmount.x) * (float)(__int64)v7)
                        * (float)0.000030518509)
                + parms->driftYAmount.x);
    OldestScreenEffect = idView::GetOldestScreenEffect(this: (idView *)HIDWORD(v7));
    numQuads = parms->numQuads;
    v31 = OldestScreenEffect;
    if ( numQuads >= 10 )
      numQuads = 10;
    OldestScreenEffect->numGenParms = numQuads;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v31->startTime = GameMs;
    v31->fadeStartTime = (int)(float)(parms->fadeOutTime * (float)1000.0) + GameMs;
    v31->endTime = (int)(float)(parms->screenDamageTime * (float)1000.0) + GameMs;
    v31->material = parms->screenDamageMtr;
    v33 = (float)((float)__SPAIR64__(0x82000000, renderSystem->GetWidth(this: renderSystem)) * 0.5);
    HIDWORD(v34) = ((int (*)(void))renderSystem->GetHeight)();
    LODWORD(v35) = HIDWORD(v34);
    HIDWORD(v35) = v31->numGenParms;
    LODWORD(v36) = parms->screenDamageFrames;
    v37 = (float)((float)v33 * (float)v26);
    v38 = 0;
    v39 = (float)((float)v33 * (float)v25);
    v40 = (float)((float)v35 * (float)0.5);
    v41 = (float)((float)((float)v35 * (float)0.5) * (float)v23);
    v42 = (float)((float)1.0 / (float)v36);
    v43 = (float)((float)((float)v35 * (float)0.5) * (float)v27);
    if ( SHIDWORD(v35) > 0 )
    {
      p_driftAmount = &v31->genParms[0].driftAmount;
      do
      {
        *(p_driftAmount - 6) = v24;
        *p_driftAmount = v28;
        v45 = 0.0;
        *(p_driftAmount - 5) = v24;
        HIDWORD(v46) = 1664525 * clientGame->random.seed + 1013904223;
        clientGame->random.seed = HIDWORD(v46);
        LODWORD(v34) = (HIDWORD(v46) >> 10) & 0x7FFF;
        *((_DWORD *)p_driftAmount + 1) = (int)(float)((float)((float)((float)((float)v34
                                                                            * (float)(parms->delay.y - parms->delay.x))
                                                                    * (float)0.000030518509)
                                                            + parms->delay.x)
                                                    * 1000.0);
        v47 = clientGame;
        clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
        v48 = (v47->random.seed >> 10) & 0x7FFF;
        HIDWORD(v34) = 1664525 * clientGame->random.seed;
        clientGame->random.seed = HIDWORD(v34) + 1013904223;
        LODWORD(v46) = ((unsigned int)(HIDWORD(v34) + 1013904223) >> 10) & 0x7FFF;
        *(p_driftAmount - 8) = (float)((float)((float)((float)((float)*(__int64 *)((char *)&v34 - 4)
                                                             * (float)0.000061037019)
                                                     - (float)1.0)
                                             * (float)v39)
                                     + (float)v33)
                             + (float)v37;
        *(p_driftAmount - 7) = (float)((float)((float)((float)((float)v46 * (float)0.000061037019) - (float)1.0)
                                             * (float)v43)
                                     + (float)v40)
                             + (float)v41;
        LODWORD(v34) = parms->screenDamageFrames;
        if ( (int)v34 > 1 )
        {
          HIDWORD(v34) = idRandom2::RandomInt(this: &clientGame->random, max: v34);
          LODWORD(v49) = HIDWORD(v34);
          DWORD2(v49) = parms->screenDamageFrames;
          v45 = (float)((float)(__int64)v49 / (float)*(__int64 *)((char *)&v49 + 4));
        }
        v50 = (float)((float)v45 + (float)v42);
        v51 = v45;
        v52 = 0.0;
        v53 = 1.0;
        if ( view_damageEffectRandomTextureFlip.valueInteger != 0 )
        {
          v54 = clientGame;
          clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
          v55 = (v54->random.seed & 0x400) != 0;
          v56 = (v54->random.seed & 0x400) == 0;
          LODWORD(v34) = 1664525 * clientGame->random.seed;
          HIDWORD(v34) = v34 + 1013904223;
          clientGame->random.seed = v34 + 1013904223;
          if ( v56 )
            v51 = v45;
          else
            v51 = (float)((float)v45 + (float)v42);
          if ( v55 )
            v50 = v45;
          if ( (((_WORD)v34 - 3233) & 0x400) != 0 )
            v52 = 1.0;
          else
            v52 = 0.0;
          if ( (((_WORD)v34 - 3233) & 0x400) != 0 )
            v53 = 0.0;
          else
            v53 = 1.0;
        }
        v57 = *p_driftAmount;
        v58 = v51;
        v59 = v52;
        if ( v57 > 0.0 )
        {
          if ( v57 < 0.60000002 )
            goto LABEL_29;
          if ( v57 >= 0.75 )
          {
            if ( v57 < 0.85000002 )
            {
              v59 = v53;
              v53 = v52;
LABEL_29:
              v58 = v50;
              v50 = v51;
            }
          }
          else
          {
            v59 = v53;
            v53 = v52;
          }
        }
        *(p_driftAmount - 3) = v59;
        ++v38;
        *(p_driftAmount - 2) = v50;
        *(p_driftAmount - 1) = v53;
        *(p_driftAmount - 4) = v58;
        p_driftAmount += 10;
      }
      while ( v38 < v31->numGenParms );
    }
  }
}


// ========================================================================
// ?ClearDamageEffects@idView@@QAAXXZ
// EA  : 0x82E872F8
// RVA : 0x00E872F8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::ClearDamageEffects(idView *this)
{
  this->borderDamageEffects[0].amount.startTime = 0.0;
  this->borderDamageEffects[1].amount.startTime = 0.0;
  this->borderDamageEffects[0].amount.duration = 0.0;
  this->borderDamageEffects[0].amount.startValue = 0.0;
  this->borderDamageEffects[0].amount.endValue = 0.0;
  this->borderDamageEffects[0].amount.currentTime = -1.0;
  this->borderDamageEffects[0].amount.currentValue = 0.0;
  this->borderDamageEffects[1].amount.duration = 0.0;
  this->borderDamageEffects[1].amount.startValue = 0.0;
  this->borderDamageEffects[1].amount.endValue = 0.0;
  this->borderDamageEffects[1].amount.currentTime = -1.0;
  this->borderDamageEffects[1].amount.currentValue = 0.0;
  this->borderDamageEffects[2].amount.startTime = 0.0;
  this->borderDamageEffects[2].amount.duration = 0.0;
  this->borderDamageEffects[2].amount.startValue = 0.0;
  this->borderDamageEffects[2].amount.endValue = 0.0;
  this->borderDamageEffects[2].amount.currentTime = -1.0;
  this->borderDamageEffects[2].amount.currentValue = 0.0;
  this->borderDamageEffects[3].amount.startTime = 0.0;
  this->borderDamageEffects[3].amount.duration = 0.0;
  this->borderDamageEffects[3].amount.startValue = 0.0;
  this->borderDamageEffects[3].amount.endValue = 0.0;
  this->borderDamageEffects[3].amount.currentTime = -1.0;
  this->borderDamageEffects[3].amount.currentValue = 0.0;
}


// ========================================================================
// ?ApplyScreenEffect@idView@@AAAXAAUrenderView_t@@@Z
// EA  : 0x82E87370
// RVA : 0x00E87370
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::ApplyScreenEffect(idView *this, renderView_t *view)
{
  int *p_numGenParms; // r29
  int i; // r23
  int v5; // r26
  float *v6; // r31
  int v7; // r28
  int v8; // r28
  __int64 v9; // r9
  double v10; // fp28
  int v11; // r28
  __int64 v12; // r7
  int v15; // r11
  int v16; // r11
  unsigned __int64 v17; // r10
  double v18; // fp7
  double v19; // fp12
  idRenderModelGui *guiModel; // r3
  double v21; // fp11
  const idMaterial *v22; // r8
  double v23; // fp10
  double v24; // fp9
  double v25; // fp8
  double v26; // fp6
  idVec4 v27; // [sp+70h] [-B0h] BYREF
  idVec4 v28; // [sp+80h] [-A0h] BYREF
  idVec4 v29; // [sp+90h] [-90h] BYREF
  idVec4 v30; // [sp+A0h] [-80h] BYREF

  p_numGenParms = &this->screenEffects[0].numGenParms;
  for ( i = 8; i != 0; --i )
  {
    v5 = 0;
    if ( *p_numGenParms > 0 )
    {
      v6 = (float *)(p_numGenParms - 91);
      do
      {
        v7 = *(p_numGenParms - 101) + *(_DWORD *)v6;
        if ( v7 <= idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
        {
          v8 = *(p_numGenParms - 103) + *(_DWORD *)v6;
          if ( v8 > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
          {
            LODWORD(v9) = v8;
            v10 = (float)v9;
            v11 = *(p_numGenParms - 102) + *(_DWORD *)v6;
            LODWORD(v12) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            _FP3 = (float)((float)((float)((float)v10 - (float)v12) / (float)((float)v10 - (float)__SPAIR64__(v12, v11)))
                         - (float)1.0);
            __asm { fsel      f0, f3, f31, f4 }
            if ( _FP0 > 0.0 )
            {
              *(v6 - 8) = *(v6 - 8) + *(v6 - 1);
              v15 = (int)(float)((float)_FP0 * (float)255.0);
              if ( v15 >= 0 )
              {
                if ( v15 <= 255 )
                  v16 = (unsigned __int8)(int)(float)((float)_FP0 * (float)255.0);
                else
                  v16 = 255;
              }
              else
              {
                v16 = 0;
              }
              LODWORD(v17) = this->guiModel;
              HIDWORD(v17) = (v16 << 24) | 0xFFFFFF;
              *(_DWORD *)(v17 + 2036) = HIDWORD(v17);
              v18 = *(v6 - 9);
              v19 = *(v6 - 7);
              guiModel = this->guiModel;
              v21 = *(v6 - 2);
              v22 = (const idMaterial *)*(p_numGenParms - 104);
              v23 = *(v6 - 3);
              v24 = *(v6 - 5);
              v25 = *(v6 - 4);
              v30.y = *(v6 - 8);
              v26 = (float)(v30.y + *(v6 - 6));
              v27.x = v18;
              v27.w = v21;
              v29.z = v23;
              v27.z = v24;
              v29.w = v21;
              v30.z = v23;
              v28.x = v18;
              v28.y = v30.y;
              v28.z = v24;
              v27.y = v26;
              v29.y = v26;
              v30.w = v25;
              v28.w = v25;
              v29.x = (float)v18 + (float)v19;
              v30.x = v29.x;
              idRenderModelGui::DrawStretchPic(
                this: guiModel,
                topLeft: &v28,
                topRight: &v30,
                bottomRight: &v29,
                bottomLeft: &v27,
                material: v22,
                a7: v17);
            }
          }
        }
        ++v5;
        v6 += 10;
      }
      while ( v5 < *p_numGenParms );
    }
    p_numGenParms += 105;
  }
}


// ========================================================================
// ?ApplyShake@idView@@ABAXAAUrenderView_t@@@Z
// EA  : 0x82E87598
// RVA : 0x00E87598
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idView::ApplyShake(idView *this, renderView_t *view)
{
  double v3; // fp31
  __int128 v5; // r11
  unsigned int v6; // r6
  unsigned int v7; // r7
  const idMat3 *v8; // r3
  __int64 v9; // r6
  int v10; // r2 OVERLAPPED
  idClientGame *v11; // r10
  double x; // fp0
  int v13; // r3
  double playerMaxShakeScale; // fp13
  unsigned int v15; // r10
  double y; // fp11
  double v17; // fp10
  unsigned int v18; // r4
  double v19; // fp7
  __int64 v20; // r9
  double v21; // fp0
  double z; // fp2
  double v23; // fp5
  double v24; // fp1
  double v25; // fp12
  double v26; // fp10
  idMat3 v27[2]; // [sp+58h] [-98h] BYREF

  v3 = (float)(this->shakeVolume + this->cameraShake);
  if ( v3 >= 0.0 )
  {
    if ( v3 <= 1.0 )
    {
      if ( v3 <= 0.0 )
        return;
    }
    else
    {
      v3 = 1.0;
    }
    if ( player_debugShake.valueInteger != 0 )
      idLib::Printf(
        fmt: "sound shake: %f, camera shake: %f shake: %f max shake: %f\n",
        this->shakeVolume,
        this->cameraShake,
        v3,
        this->playerMaxShakeScale);
    DWORD1(v5) = byte_821B0000;
    v6 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v6;
    DWORD2(v5) = (v6 >> 10) & 0x7FFF;
    v27[0].mat[0].x = (float)((float)((float)((float)((float)*(__int64 *)((char *)&v5 + 4) * (float)0.000061037019)
                                            - (float)1.0)
                                    * this->maxShakeAngles.pitch)
                            * this->playerMaxShakeScale)
                    * (float)v3;
    DWORD1(v5) = clientGame->random.seed;
    v7 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v7;
    DWORD2(v5) = (v7 >> 10) & 0x7FFF;
    v27[0].mat[0].y = (float)((float)((float)((float)((float)*(__int64 *)((char *)&v5 + 4) * (float)0.000061037019)
                                            - (float)1.0)
                                    * this->maxShakeAngles.yaw)
                            * this->playerMaxShakeScale)
                    * (float)v3;
    HIDWORD(v5) = 1664525 * clientGame->random.seed;
    clientGame->random.seed = HIDWORD(v5) + 1013904223;
    LODWORD(v5) = ((unsigned int)(HIDWORD(v5) + 1013904223) >> 10) & 0x7FFF;
    v27[0].mat[0].z = (float)((float)((float)((float)((float)(__int64)v5 * (float)0.000061037019) - (float)1.0)
                                    * this->maxShakeAngles.roll)
                            * this->playerMaxShakeScale)
                    * (float)v3;
    v8 = idAngles::ToMat3(this: (idAngles *)&v27[0].mat[2], result: v27);
    idMat3::operator*=(this: &view->viewaxis, a: v8);
    if ( player_debugShake.valueInteger != 0 && (this->shakeVolume > 0.0 || this->cameraShake > 0.0) )
      idLib::Printf(
        fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v27[0].mat[0].y)),
        (unsigned int)COERCE_UNSIGNED_INT64(v27[0].mat[0].y),
        (unsigned int)COERCE_UNSIGNED_INT64(v27[0].mat[0].x),
        (unsigned int)COERCE_UNSIGNED_INT64(v27[0].mat[0].z));
    v11 = clientGame;
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    x = this->maxShakeOffset.x;
    v13 = (v11->random.seed >> 10) & 0x7FFF;
    playerMaxShakeScale = this->playerMaxShakeScale;
    v15 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v15 + 1013904223;
    y = this->maxShakeOffset.y;
    v17 = this->playerMaxShakeScale;
    HIDWORD(v20) = v15 + 1013904223;
    LODWORD(v9) = ((v15 + 1013904223) >> 10) & 0x7FFF;
    v18 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v18 + 1013904223;
    v19 = view->vieworg.y;
    LODWORD(v20) = ((v18 + 1013904223) >> 10) & 0x7FFF;
    z = this->maxShakeOffset.z;
    v24 = (float)((float)((float)((float)((float)((float)*(__int64 *)(&v10 - 1) * (float)0.000061037019) - (float)1.0)
                                * (float)x)
                        * (float)playerMaxShakeScale)
                * (float)v3);
    v25 = (float)(view->vieworg.x
                + (float)((float)((float)((float)((float)((float)*(__int64 *)(&v10 - 1) * (float)0.000061037019)
                                                - (float)1.0)
                                        * (float)x)
                                * (float)playerMaxShakeScale)
                        * (float)v3));
    v21 = this->playerMaxShakeScale;
    v23 = view->vieworg.z;
    view->vieworg.x = v25;
    v26 = (float)((float)((float)((float)((float)v9 * (float)0.000061037019) - (float)1.0) * (float)y) * (float)v17);
    view->vieworg.y = (float)v19 + (float)((float)v26 * (float)v3);
    view->vieworg.z = (float)v23
                    + (float)((float)((float)((float)((float)((float)v20 * (float)0.000061037019) - (float)1.0)
                                            * (float)z)
                                    * (float)v21)
                            * (float)v3);
    if ( player_debugShake.valueInteger != 0 && (this->shakeVolume > 0.0 || this->cameraShake > 0.0) )
      idLib::Printf(
        fmt: (const char *)HIDWORD(v24),
        (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v26 * (float)v3))),
        (unsigned int)COERCE_UNSIGNED_INT64((float)((float)v26 * (float)v3)),
        (unsigned int)COERCE_UNSIGNED_INT64((float)((float)((float)((float)((float)((float)v20 * (float)0.000061037019)
                                                                          - (float)1.0)
                                                                  * (float)z)
                                                          * (float)v21)
                                                  * (float)v3)));
  }
}


// ========================================================================
// ?ApplyBob@idView@@ABAXAAUrenderView_t@@@Z
// EA  : 0x82E878E8
// RVA : 0x00E878E8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::ApplyBob(idView *this, renderView_t *view)
{
  double y; // fp11
  double z; // fp8
  idAngles *v6; // r3
  double v7; // fp0
  double v8; // fp12
  idMat3 v9[2]; // [sp+50h] [-60h] BYREF

  y = view->vieworg.y;
  view->vieworg.x = this->viewBob.x + view->vieworg.x;
  z = view->vieworg.z;
  view->vieworg.y = this->viewBob.y + (float)y;
  view->vieworg.z = this->viewBob.z + (float)z;
  v6 = idMat3::ToAngles(this: (idMat3 *)&v9[0].mat[1].y, result: (idAngles *)&view->viewaxis);
  v7 = (float)(v6->roll + this->viewBobAngles.roll);
  v8 = (float)(v6->yaw + this->viewBobAngles.yaw);
  v9[0].mat[0].x = v6->pitch + this->viewBobAngles.pitch;
  v9[0].mat[0].z = v7;
  v9[0].mat[0].y = v8;
  view->viewaxis = *idAngles::ToMat3(this: (idAngles *)&v9[0].mat[2].z, result: v9);
}


// ========================================================================
// ?AddCustomWhiplash@idView@@QAAXABVidAngles@@MMMM@Z
// EA  : 0x82E879E8
// RVA : 0x00E879E8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::AddCustomWhiplash(
        idView *this,
        const idAngles *angles,
        double updateFrac,
        double velocityFrac,
        double frictionFrac,
        double minVelocityLen)
{
  double pitch; // fp10
  double roll; // fp7
  double v8; // fp8
  double v9; // fp5

  pitch = this->whiplashVel.pitch;
  roll = this->whiplashVel.roll;
  v8 = (float)(angles->pitch * (float)0.1);
  v9 = (float)(angles->roll * (float)0.1);
  this->whiplashVel.yaw = this->whiplashVel.yaw + (float)(angles->yaw * (float)0.1);
  this->whiplashVel.pitch = (float)pitch + (float)v8;
  this->whiplashVel.roll = (float)roll + (float)v9;
  this->whiplashUpdateFrac = updateFrac;
  this->whiplashVelocityFrac = velocityFrac;
  this->whiplashFrictionFrac = frictionFrac;
  this->whiplashMinVelocityLen = minVelocityLen;
}


// ========================================================================
// ?AddDefaultWhiplash@idView@@QAAXABVidAngles@@@Z
// EA  : 0x82E87A48
// RVA : 0x00E87A48
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::AddDefaultWhiplash(idView *this, const idAngles *angles)
{
  double yaw; // fp9
  double v3; // fp7
  double v4; // fp6
  double roll; // fp5
  double valueFloat; // fp0
  double v7; // fp13
  double v8; // fp12
  double v9; // fp11

  yaw = this->whiplashVel.yaw;
  v3 = (float)(angles->yaw * (float)0.1);
  v4 = (float)(angles->roll * (float)0.1);
  roll = this->whiplashVel.roll;
  valueFloat = player_whiplash_min_velocity_len.valueFloat;
  v7 = player_whiplash_friction_frac.valueFloat;
  v8 = player_whiplash_velocity_frac.valueFloat;
  v9 = player_whiplash_update_frac.valueFloat;
  this->whiplashVel.pitch = this->whiplashVel.pitch + (float)(angles->pitch * (float)0.1);
  this->whiplashVel.yaw = (float)yaw + (float)v3;
  this->whiplashVel.roll = (float)roll + (float)v4;
  this->whiplashUpdateFrac = v9;
  this->whiplashVelocityFrac = v8;
  this->whiplashFrictionFrac = v7;
  this->whiplashMinVelocityLen = valueFloat;
}


// ========================================================================
// ?ApplyWhiplash@idView@@AAAXAAUrenderView_t@@MMMM@Z
// EA  : 0x82E87AD8
// RVA : 0x00E87AD8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::ApplyWhiplash(
        idView *this,
        renderView_t *view,
        double updateFrac,
        double velocityFrac,
        double frictionFrac,
        double minVelLen)
{
  idAngles *p_whiplashVel; // r11
  double v8; // fp10
  double v9; // fp9
  idAngles *p_whiplashCur; // r31
  double v11; // fp8
  double yaw; // fp6
  double roll; // fp5
  double v14; // fp4
  double v15; // fp0
  double v16; // fp10
  double pitch; // fp9
  double v18; // fp5
  double v19; // fp3
  double v20; // fp1
  double v21; // fp13
  double v22; // fp11
  double v23; // fp10
  idMat3 v24; // [sp+50h] [-50h] BYREF

  p_whiplashVel = &this->whiplashVel;
  if ( (float)((float)(this->whiplashVel.roll * this->whiplashVel.roll)
             + (float)((float)(this->whiplashVel.pitch * this->whiplashVel.pitch)
                     + (float)(this->whiplashVel.yaw * this->whiplashVel.yaw))) <= (double)(float)((float)minVelLen
                                                                                                 * (float)minVelLen) )
  {
    this->whiplashCur = ang_zero;
    p_whiplashVel->pitch = ang_zero.pitch;
    this->whiplashVel.yaw = ang_zero.yaw;
    this->whiplashVel.roll = ang_zero.roll;
  }
  else
  {
    v8 = (float)(this->whiplashVel.yaw * (float)updateFrac);
    v9 = (float)((float)updateFrac * this->whiplashVel.roll);
    p_whiplashCur = &this->whiplashCur;
    v11 = (float)((float)updateFrac * (float)frictionFrac);
    yaw = this->whiplashCur.yaw;
    roll = this->whiplashCur.roll;
    v14 = (float)((float)(this->whiplashVel.pitch * (float)updateFrac) + this->whiplashCur.pitch);
    this->whiplashCur.pitch = (float)(this->whiplashVel.pitch * (float)updateFrac) + this->whiplashCur.pitch;
    this->whiplashCur.yaw = (float)yaw + (float)v8;
    v15 = (float)((float)roll + (float)v9);
    this->whiplashCur.roll = (float)roll + (float)v9;
    pitch = p_whiplashVel->pitch;
    v18 = (float)((float)((float)yaw + (float)v8) * (float)velocityFrac);
    v19 = (float)((float)((float)v15 * (float)velocityFrac) * (float)updateFrac);
    v21 = (float)(this->whiplashVel.yaw
                - (float)((float)((float)((float)yaw + (float)v8) * (float)velocityFrac) * (float)updateFrac));
    v16 = this->whiplashVel.roll;
    this->whiplashVel.yaw = this->whiplashVel.yaw - (float)((float)v18 * (float)updateFrac);
    this->whiplashVel.roll = (float)v16 - (float)((float)((float)v15 * (float)velocityFrac) * (float)updateFrac);
    v20 = (float)((float)((float)velocityFrac * (float)v14) * (float)updateFrac);
    p_whiplashVel->pitch = (float)pitch - (float)v20;
    this->whiplashVel.yaw = (float)v21 * (float)v11;
    this->whiplashVel.roll = (float)v11 * (float)((float)v16 - (float)v19);
    p_whiplashVel->pitch = (float)v11 * (float)((float)pitch - (float)v20);
    idMat3::ToAngles(this: &v24, result: (idAngles *)&view->viewaxis);
    v22 = (float)(p_whiplashCur->yaw + v24.mat[0].y);
    v23 = (float)(p_whiplashCur->roll + v24.mat[0].z);
    v24.mat[0].x = v24.mat[0].x + p_whiplashCur->pitch;
    v24.mat[0].y = v22;
    v24.mat[0].z = v23;
    view->viewaxis = *idAngles::ToMat3(this: (idAngles *)&v24.mat[1].y, result: &v24);
  }
}


// ========================================================================
// ?ApplyGodRays@idView@@AAAXAAUrenderView_t@@@Z
// EA  : 0x82E87CA8
// RVA : 0x00E87CA8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::ApplyGodRays(idView *this, renderView_t *view, __int64 a3, __int64 a4)
{
  if ( this->godRaysEnabled )
  {
    view->godRaysEnabled = true;
    view->godRaysRelativeToCamera = this->godRaysRelativeToCamera;
    view->godRaysPosition = this->godRaysPosition;
    LODWORD(a4) = this->godRaysSize;
    view->godRaysSize = (float)a4;
    LODWORD(a3) = this->godRaysSourceSize;
    view->godRaysSourceSize = (float)a3;
    view->godRaysColor = this->godRaysColor;
    view->godRaysMaterial = this->godRaysMaterial;
  }
  else
  {
    view->godRaysEnabled = false;
  }
}


// ========================================================================
// ?ClearEffects@idView@@QAAXXZ
// EA  : 0x82E87E48
// RVA : 0x00E87E48
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::ClearEffects(idView *this)
{
  idVec4 *p_fadeFromColor; // r28
  int v3; // r30

  this->kickFinishTime = -1;
  p_fadeFromColor = &this->fadeFromColor;
  this->kickAngles.roll = 0.0;
  v3 = 8;
  this->kickAngles.yaw = 0.0;
  this->kickAngles.pitch = 0.0;
  this->viewBob.z = 0.0;
  this->viewBob.y = 0.0;
  this->viewBob.x = 0.0;
  this->viewBobAngles.roll = 0.0;
  this->viewBobAngles.yaw = 0.0;
  this->viewBobAngles.pitch = 0.0;
  this->fadeTime = 0;
  this->fadeRate = 0.0;
  this->fadeFromColor.w = 0.0;
  this->fadeFromColor.z = 0.0;
  this->fadeFromColor.y = 0.0;
  this->fadeFromColor.x = 0.0;
  this->fadeToColor.w = 0.0;
  this->fadeToColor.z = 0.0;
  this->fadeToColor.y = 0.0;
  this->fadeToColor.x = 0.0;
  this->fadeColor.w = 0.0;
  this->fadeColor.z = 0.0;
  this->fadeColor.y = 0.0;
  this->fadeColor.x = 0.0;
  this->controllerShakeHighTime = -1;
  this->shakeVolume = 0.0;
  this->controllerShakeLowTime = -1;
  this->controllerShakeHighMag = 0.0;
  this->controllerShakeLowMag = 0.0;
  this->damageScaleTracker.startTime = 0.0;
  this->damageScaleTracker.duration = 0.0;
  this->damageScaleTracker.startValue = 0.0;
  this->damageScaleTracker.endValue = 0.0;
  this->damageScaleTracker.currentTime = -1.0;
  this->damageScaleTracker.currentValue = 0.0;
  this->blur.startTime = 0.0;
  this->blur.duration = 0.0;
  this->blur.startValue = 0.0;
  this->blur.endValue = 0.0;
  this->blur.currentTime = -1.0;
  this->blur.currentValue = 0.0;
  this->blurParm = nullptr;
  this->dbl.startTime = 0.0;
  this->dbl.duration = 0.0;
  this->dbl.startValue = 0.0;
  this->dbl.endValue = 0.0;
  this->dbl.currentTime = -1.0;
  this->dbl.currentValue = 0.0;
  this->dblVParm = nullptr;
  this->radialBlur[0].scaleVal = 0.0;
  this->radialBlur[0].enabled = false;
  this->radialBlur[0].centerPos.x = 0.0;
  this->radialBlur[0].centerPos.z = 0.0;
  this->radialBlur[0].centerPos.y = 0.0;
  this->radialBlur[0].radialBlurInterpolate.startTime = 0.0;
  this->radialBlur[0].radialBlurInterpolate.duration = 0.0;
  this->radialBlur[0].radialBlurInterpolate.startValue = -1.0;
  this->radialBlur[0].radialBlurInterpolate.endValue = -1.0;
  this->radialBlur[0].radialBlurInterpolate.currentTime = -1.0;
  this->radialBlur[0].radialBlurInterpolate.currentValue = -1.0;
  this->radialBlur[1].enabled = false;
  this->radialBlur[1].scaleVal = 0.0;
  this->radialBlur[1].centerPos.z = 0.0;
  this->radialBlur[1].centerPos.y = 0.0;
  this->radialBlur[1].centerPos.x = 0.0;
  this->radialBlur[1].radialBlurInterpolate.startTime = 0.0;
  this->radialBlur[1].radialBlurInterpolate.duration = 0.0;
  this->radialBlur[1].radialBlurInterpolate.startValue = -1.0;
  this->radialBlur[1].radialBlurInterpolate.endValue = -1.0;
  this->radialBlur[1].radialBlurInterpolate.currentTime = -1.0;
  this->radialBlur[1].radialBlurInterpolate.currentValue = -1.0;
  this->radialBlur[2].enabled = false;
  this->radialBlur[2].scaleVal = 0.0;
  this->radialBlur[2].centerPos.z = 0.0;
  this->radialBlur[2].centerPos.y = 0.0;
  this->radialBlur[2].centerPos.x = 0.0;
  this->radialBlur[2].radialBlurInterpolate.startTime = 0.0;
  this->radialBlur[2].radialBlurInterpolate.duration = 0.0;
  this->radialBlur[2].radialBlurInterpolate.startValue = -1.0;
  this->radialBlur[2].radialBlurInterpolate.endValue = -1.0;
  this->radialBlur[2].radialBlurInterpolate.currentTime = -1.0;
  this->radialBlur[2].radialBlurInterpolate.currentValue = -1.0;
  this->radialBlur[3].enabled = false;
  this->radialBlur[3].scaleVal = 0.0;
  this->radialBlur[3].centerPos.z = 0.0;
  this->radialBlur[3].centerPos.y = 0.0;
  this->radialBlur[3].centerPos.x = 0.0;
  this->radialBlur[3].radialBlurInterpolate.startTime = 0.0;
  this->radialBlur[3].radialBlurInterpolate.duration = 0.0;
  this->radialBlur[3].radialBlurInterpolate.startValue = -1.0;
  this->radialBlur[3].radialBlurInterpolate.endValue = -1.0;
  this->radialBlur[3].radialBlurInterpolate.currentTime = -1.0;
  this->radialBlur[3].radialBlurInterpolate.currentValue = -1.0;
  do
  {
    --v3;
    p_fadeFromColor = (idVec4 *)((char *)p_fadeFromColor + 420);
    LODWORD(p_fadeFromColor->x) = idGameTimeManager::GetGameMs(
                                    this: &clientGame->gameTimeManager,
                                    type: GAMETIME_SCALED);
  }
  while ( v3 != 0 );
  this->godRaysEnabled = false;
  idStaticParmBlock<32>::Clear(this: &this->envParms);
  idStaticParmBlock<32>::Clear(this: &this->gameview.parmBlock);
  idStaticParmBlock<32>::Clear(this: &this->gameview.envOverrideParmBlock);
}


// ========================================================================
// ?DamageImpulse@idView@@QAAXABVidVec3@@0PBVidDeclDamage@@M@Z
// EA  : 0x82E88038
// RVA : 0x00E88038
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::DamageImpulse(
        idView *this,
        const idVec3 *localKickDir,
        const idVec3 *inflictorOrg,
        const idDeclDamage *damageDef,
        double impulseDamageScale)
{
  __int64 v10; // r10
  idInterpolate<float> *p_damageScaleTracker; // r25
  double valueFloat; // fp13
  double v13; // fp31
  double v14; // fp22
  double v15; // fp29
  double v16; // fp26
  double v17; // fp28
  double v18; // fp24
  double v19; // fp27
  int v20; // r11
  double v21; // fp3
  double v22; // fp2
  double v23; // fp1
  double x; // fp0
  double v25; // fp13
  double v26; // fp10
  double v27; // fp6
  double v28; // fp5
  double v29; // fp4
  double v30; // fp13
  double v31; // fp12
  double v32; // fp10
  __int64 v33; // r9
  double CurrentValue; // fp1
  __int64 v35; // r11
  __int64 v36; // r9
  double v37; // fp1
  __int64 v38; // r11
  double v39; // fp12
  double v40; // fp9
  double v41; // fp6
  double v44; // fp1
  double v45; // fp13
  double v46; // fp1
  double v47; // fp0
  double v48; // fp13
  int v49; // r30
  int v50; // r3
  double v51; // fp12
  idView::damageEffectMaterial_t *borderDamageMaterials; // r10
  char *v53; // r11
  idDeclDamage::playerDamageScreenEffects_t *p_damageMedium; // r4
  int GameMs; // r3
  __int64 v56; // [sp+50h] [-C0h]

  p_damageScaleTracker = &this->damageScaleTracker;
  LODWORD(v10) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  valueFloat = (float)(idInterpolate<float>::GetCurrentValue(this: &this->damageScaleTracker, time: (float)v10)
                     + (float)impulseDamageScale);
  if ( valueFloat >= view_damage_minScale.valueFloat )
  {
    if ( valueFloat > view_damage_maxScale.valueFloat )
      valueFloat = view_damage_maxScale.valueFloat;
  }
  else
  {
    valueFloat = view_damage_minScale.valueFloat;
  }
  v13 = (float)((float)((float)valueFloat - view_damage_minScale.valueFloat)
              / (float)(view_damage_maxScale.valueFloat - view_damage_minScale.valueFloat));
  v14 = (float)((float)((float)(view_kickTime_max.valueFloat - view_kickTime_min.valueFloat)
                      * (float)((float)((float)valueFloat - view_damage_minScale.valueFloat)
                              / (float)(view_damage_maxScale.valueFloat - view_damage_minScale.valueFloat)))
              + view_kickTime_min.valueFloat);
  v15 = (float)((float)((float)(view_kickAmplitude_max.valueFloat - view_kickAmplitude_min.valueFloat)
                      * (float)((float)((float)valueFloat - view_damage_minScale.valueFloat)
                              / (float)(view_damage_maxScale.valueFloat - view_damage_minScale.valueFloat)))
              + view_kickAmplitude_min.valueFloat);
  v16 = (float)((float)((float)(view_blurTime_max.valueFloat - view_blurTime_min.valueFloat)
                      * (float)((float)((float)valueFloat - view_damage_minScale.valueFloat)
                              / (float)(view_damage_maxScale.valueFloat - view_damage_minScale.valueFloat)))
              + view_blurTime_min.valueFloat);
  v17 = (float)((float)((float)(view_blur_max.valueFloat - view_blur_min.valueFloat)
                      * (float)((float)((float)valueFloat - view_damage_minScale.valueFloat)
                              / (float)(view_damage_maxScale.valueFloat - view_damage_minScale.valueFloat)))
              + view_blur_min.valueFloat);
  v18 = (float)((float)((float)(view_doubleVisionTime_max.valueFloat - view_doubleVisionTime_min.valueFloat)
                      * (float)((float)((float)valueFloat - view_damage_minScale.valueFloat)
                              / (float)(view_damage_maxScale.valueFloat - view_damage_minScale.valueFloat)))
              + view_doubleVisionTime_min.valueFloat);
  v19 = (float)((float)((float)(view_doubleVision_max.valueFloat - view_doubleVision_min.valueFloat)
                      * (float)((float)((float)valueFloat - view_damage_minScale.valueFloat)
                              / (float)(view_damage_maxScale.valueFloat - view_damage_minScale.valueFloat)))
              + view_doubleVision_min.valueFloat);
  v20 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + (int)v14;
  if ( v14 > 0.0 && v20 > this->kickFinishTime )
  {
    x = localKickDir->x;
    if ( localKickDir->z <= 0.0 )
      v25 = __fabs(x);
    else
      v25 = __fnabs(x);
    this->kickAngles.pitch = v25;
    this->kickAngles.pitch = (float)v25 * (float)0.69999999;
    v26 = (float)(localKickDir->y * (float)0.5);
    this->kickAngles.yaw = localKickDir->y * (float)0.5;
    v27 = (float)((float)v26 * (float)v15);
    v28 = (float)(this->kickAngles.roll * (float)v15);
    v29 = (float)((float)((float)v25 * (float)0.69999999) * (float)v15);
    this->kickAngles.yaw = (float)v26 * (float)v15;
    this->kickAngles.pitch = (float)((float)v25 * (float)0.69999999) * (float)v15;
    this->kickAngles.roll = v28;
    v30 = g_kickAmplitude.valueFloat;
    v31 = (float)((float)((float)v26 * (float)v15) * g_kickAmplitude.valueFloat);
    v32 = (float)((float)v28 * g_kickAmplitude.valueFloat);
    this->kickAngles.yaw = v31;
    this->kickAngles.pitch = (float)v29 * (float)v30;
    v21 = v28;
    this->kickAngles.roll = v32;
    v22 = v29;
    v23 = v27;
    this->kickAngles.yaw = (float)v31 * (float)0.000099999997;
    this->kickAngles.roll = (float)v32 * (float)0.000099999997;
    this->kickAngles.pitch = (float)((float)v29 * (float)v30) * (float)0.000099999997;
    this->kickFinishTime = v20;
  }
  LODWORD(v33) = ((int (__fastcall *)(idGameLocal *, int, double, double, double))gameLocal->GetGameMs)(
                   a1: gameLocal,
                   a2: 1,
                   a3: v23,
                   a4: v22,
                   a5: v21);
  CurrentValue = idInterpolate<float>::GetCurrentValue(this: &this->blur, time: (float)v33);
  if ( v17 > 0.0 && v17 > CurrentValue && view_damageBlur.valueInteger != 0 )
  {
    LODWORD(v35) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->blur.duration = v16;
    this->blur.startValue = v17;
    this->blur.endValue = 0.0;
    this->blur.currentValue = v17;
    this->blur.startTime = (float)v35;
    this->blur.currentTime = (float)v35 - (float)1.0;
  }
  LODWORD(v36) = ((int (__fastcall *)(idGameLocal *, int, double))gameLocal->GetGameMs)(
                   a1: gameLocal,
                   a2: 1,
                   a3: CurrentValue);
  v37 = idInterpolate<float>::GetCurrentValue(this: &this->dbl, time: (float)v36);
  if ( v19 > 0.0 && v19 > v37 && view_doubleVision.valueInteger != 0 )
  {
    LODWORD(v38) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->dbl.duration = v18;
    this->dbl.startValue = v19;
    this->dbl.endValue = 0.0;
    this->dbl.currentValue = v19;
    this->dbl.startTime = (float)v38;
    this->dbl.currentTime = (float)v38 - (float)1.0;
  }
  v39 = (float)(inflictorOrg->y - this->gameview.vieworg.y);
  v40 = (float)(inflictorOrg->z - this->gameview.vieworg.z);
  v41 = (float)(inflictorOrg->x - this->gameview.vieworg.x);
  _FP1 = (float)((float)((float)((float)v41 * (float)v41)
                       + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f7, f1, f7, f13 }
  v44 = __frsqrte(_FP7);
  v45 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44
                                                                                      * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)))
                                                                                              * (float)0.5))
                                                                              * (float)v44)
                                                                      - (float)1.5)
                                                      * (float)v44)
                                              * (float)((float)((float)((float)v41 * (float)v41)
                                                              + (float)((float)((float)v40 * (float)v40)
                                                                      + (float)((float)v39 * (float)v39)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v44
                                                                              * (float)((float)((float)((float)v41 * (float)v41)
                                                                                              + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)))
                                                                                      * (float)0.5))
                                                                      * (float)v44)
                                                              - (float)1.5)
                                              * (float)v44))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v44
                                                      * (float)((float)((float)((float)v41 * (float)v41)
                                                                      + (float)((float)((float)v40 * (float)v40)
                                                                              + (float)((float)v39 * (float)v39)))
                                                              * (float)0.5))
                                              * (float)v44)
                                      - (float)1.5)
                      * (float)v44));
  v46 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                              * (float)v44)
                                                                                      * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                      * (float)v44))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v44
                                                                                              * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5))
                                                                                      * (float)v44)
                                                                              - (float)1.5)
                                                              * (float)v44))
                                              * (float)((float)((float)((float)v41 * (float)v41)
                                                              + (float)((float)((float)v40 * (float)v40)
                                                                      + (float)((float)v39 * (float)v39)))
                                                      * (float)0.5))
                                      * (float)v45)
                              - (float)1.5)
              * (float)v45);
  v47 = (float)((float)(this->gameview.viewaxis.mat[0].x
                      * (float)((float)(inflictorOrg->x - this->gameview.vieworg.x) * (float)v46))
              + (float)((float)(this->gameview.viewaxis.mat[0].z
                              * (float)((float)(inflictorOrg->z - this->gameview.vieworg.z) * (float)v46))
                      + (float)(this->gameview.viewaxis.mat[0].y
                              * (float)((float)(inflictorOrg->y - this->gameview.vieworg.y) * (float)v46))));
  v48 = (float)((float)(this->gameview.viewaxis.mat[1].x
                      * (float)((float)(inflictorOrg->x - this->gameview.vieworg.x) * (float)v46))
              + (float)((float)(this->gameview.viewaxis.mat[1].z
                              * (float)((float)(inflictorOrg->z - this->gameview.vieworg.z) * (float)v46))
                      + (float)(this->gameview.viewaxis.mat[1].y
                              * (float)((float)(inflictorOrg->y - this->gameview.vieworg.y) * (float)v46))));
  if ( __fabs(v47) <= __fabs(v48) )
  {
    v49 = 2;
    if ( v48 < 0.0 )
      v49 = 3;
  }
  else
  {
    v49 = v47 < 0.0;
  }
  v50 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v51 = 1.0;
  borderDamageMaterials = this->borderDamageMaterials;
  if ( impulseDamageScale > 0.33333299 )
  {
    borderDamageMaterials = &this->borderDamageMaterials[1];
    v51 = 2.0;
  }
  v53 = (char *)this + 32 * v49;
  if ( borderDamageMaterials != nullptr )
  {
    *((_DWORD *)v53 + 1671) = borderDamageMaterials->materials[0];
    *((_DWORD *)v53 + 1672) = borderDamageMaterials->materials[1];
  }
  else
  {
    *((_DWORD *)v53 + 1671) = 0;
    *((_DWORD *)v53 + 1672) = 0;
  }
  *((float *)v53 + 1673) = (float)__SPAIR64__(&unk_82360000, v50) * (float)0.001;
  *((float *)v53 + 1674) = v51;
  *((float *)v53 + 1675) = 1.0;
  *((float *)v53 + 1676) = 0.0;
  *((float *)v53 + 1677) = (float)((float)__SPAIR64__(&unk_82360000, v50) * (float)0.001) - (float)1.0;
  *((float *)v53 + 1678) = 1.0;
  if ( damageDef != nullptr && view_showPlayerDamageViewEffect.valueInteger != 0 )
  {
    if ( v13 <= damageDef->playerDamageScreenEffects.damageLarge.damagePct )
    {
      p_damageMedium = (idDeclDamage::playerDamageScreenEffects_t *)&damageDef->playerDamageScreenEffects.damageMedium;
      if ( v13 <= damageDef->playerDamageScreenEffects.damageMedium.damagePct )
        p_damageMedium = &damageDef->playerDamageScreenEffects;
    }
    else
    {
      p_damageMedium = (idDeclDamage::playerDamageScreenEffects_t *)&damageDef->playerDamageScreenEffects.damageLarge;
    }
    if ( p_damageMedium != nullptr )
    {
      v56 = *(_QWORD *)&this->gameview.vieworg.x;
      if ( (float)((float)((float)(*(float *)&v56 - inflictorOrg->x) * (float)(*(float *)&v56 - inflictorOrg->x))
                 + (float)((float)((float)(this->gameview.vieworg.z - inflictorOrg->z)
                                 * (float)(this->gameview.vieworg.z - inflictorOrg->z))
                         + (float)((float)(*((float *)&v56 + 1) - inflictorOrg->y)
                                 * (float)(*((float *)&v56 + 1) - inflictorOrg->y)))) < (double)(float)(p_damageMedium->damageSmall.radius * p_damageMedium->damageSmall.radius) )
        idView::AddScreenDamageEffect(this, parms: &p_damageMedium->damageSmall.parms);
    }
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->damageScaleTracker.startValue = v13;
  this->damageScaleTracker.endValue = 0.0;
  this->damageScaleTracker.currentValue = v13;
  this->damageScaleTracker.duration = 350.0;
  p_damageScaleTracker->startTime = (float)__SPAIR64__(&unk_821F0000, GameMs);
  this->damageScaleTracker.currentTime = (float)__SPAIR64__(&unk_821F0000, GameMs) - (float)1.0;
}


// ========================================================================
// ?DamageFeedback@idView@@QAAXPBVidDeclDamage@@MABVidVec3@@_N@Z
// EA  : 0x82E88688
// RVA : 0x00E88688
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::DamageFeedback(
        idView *this,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *victimOrg,
        float *isGibbed,
        char a6)
{
  idDeclDamage::damageFeedbackScreenEffects_t *p_feedbackGib; // r4

  if ( damageDef != nullptr && (view_damageFeedbackMeleeOnly.valueInteger == 0 || damageDef->isMelee) )
  {
    if ( a6 != 0 )
    {
      p_feedbackGib = (idDeclDamage::damageFeedbackScreenEffects_t *)&damageDef->feedbackScreenEffects.feedbackGib;
    }
    else if ( damageScale <= damageDef->feedbackScreenEffects.feedbackLarge.damagePct )
    {
      if ( damageScale <= damageDef->feedbackScreenEffects.feedbackMedium.damagePct )
        p_feedbackGib = &damageDef->feedbackScreenEffects;
      else
        p_feedbackGib = (idDeclDamage::damageFeedbackScreenEffects_t *)&damageDef->feedbackScreenEffects.feedbackMedium;
    }
    else
    {
      p_feedbackGib = (idDeclDamage::damageFeedbackScreenEffects_t *)&damageDef->feedbackScreenEffects.feedbackLarge;
    }
    if ( p_feedbackGib != nullptr
      && (float)((float)((float)(this->gameview.vieworg.y - isGibbed[1])
                       * (float)(this->gameview.vieworg.y - isGibbed[1]))
               + (float)((float)((float)(this->gameview.vieworg.z - isGibbed[2])
                               * (float)(this->gameview.vieworg.z - isGibbed[2]))
                       + (float)((float)(this->gameview.vieworg.x - *isGibbed)
                               * (float)(this->gameview.vieworg.x - *isGibbed)))) < (double)(float)(p_feedbackGib->feedbackSmall.radius
                                                                                                  * p_feedbackGib->feedbackSmall.radius) )
    {
      idView::AddScreenDamageEffect(this, parms: &p_feedbackGib->feedbackSmall.parms);
    }
  }
}


// ========================================================================
// ?GetControllerShake@idView@@QBAXAAH0@Z
// EA  : 0x82E88770
// RVA : 0x00E88770
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::GetControllerShake(idView *this, int *highMagnitude, int *lowMagnitude)
{
  double v6; // fp13
  double v7; // fp0
  int v8; // [sp+54h] [-4Ch]

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->controllerShakeLowTime )
    *lowMagnitude = 0;
  else
    *lowMagnitude = (int)(float)(this->controllerShakeLowMag * (float)65535.0);
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->controllerShakeHighTime )
    *highMagnitude = 0;
  else
    *highMagnitude = (int)(float)(this->controllerShakeHighMag * (float)65535.0);
  v6 = (float)(this->cameraShake + this->shakeVolume);
  v7 = 0.0;
  if ( v6 >= 0.0 )
  {
    v7 = 1.0;
    if ( v6 <= 1.0 )
      v7 = (float)(this->cameraShake + this->shakeVolume);
  }
  v8 = (int)(float)((float)v7 * (float)327675.0);
  *lowMagnitude += v8;
  *highMagnitude += v8;
}


// ========================================================================
// ?Flash@idView@@QAAXABVidVec4@@H@Z
// EA  : 0x82E88878
// RVA : 0x00E88878
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::Flash(idView *this, const idVec4 *color, int time)
{
  idVec4 v5; // [sp+50h] [-30h] BYREF

  v5.x = 0.0;
  v5.y = 0.0;
  v5.z = 0.0;
  v5.w = 0.0;
  idView::Fade(this, color: &v5, time);
  this->fadeFromColor = *color;
}


// ========================================================================
// ?ApplyScreenFade@idView@@QAAXXZ
// EA  : 0x82E888F0
// RVA : 0x00E888F0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::ApplyScreenFade(idView *this)
{
  int GameMs; // r3
  __int64 v3; // r11
  double w; // fp10
  double v5; // fp13
  double v6; // fp12
  double v7; // fp7
  double v8; // fp5
  double v9; // fp4
  double v10; // fp3
  idRenderModelGui *guiModel; // r30
  const idMaterial *whiteMaterial; // r30
  __int64 v13; // r8
  int v14; // r5
  int v15; // r4
  double VirtualHeight; // fp29
  __int64 v17; // r8
  int v18; // r5
  int v19; // r4
  double VirtualWidth; // fp1
  int v21; // r10
  int v22; // r9
  int v23; // r8
  int v24; // r7
  int v25; // r6
  int v26; // r5
  const idMaterial *v27; // r4
  int v28; // [sp+8h] [-98h]
  int v29; // [sp+Ch] [-94h]
  int v30; // [sp+10h] [-90h]
  int v31; // [sp+14h] [-8Ch]
  int v32; // [sp+18h] [-88h]
  int v33; // [sp+1Ch] [-84h]
  int v34; // [sp+20h] [-80h]
  int v35; // [sp+24h] [-7Ch]
  int v36; // [sp+28h] [-78h]
  int v37; // [sp+2Ch] [-74h]
  int v38; // [sp+30h] [-70h]
  int v39; // [sp+34h] [-6Ch]
  int v40; // [sp+38h] [-68h]
  int v41; // [sp+3Ch] [-64h]
  int v42; // [sp+40h] [-60h]
  int v43; // [sp+44h] [-5Ch]
  int v44; // [sp+48h] [-58h]
  int v45; // [sp+4Ch] [-54h]
  int v46; // [sp+50h] [-50h]
  int v47; // [sp+54h] [-4Ch]
  int v48; // [sp+58h] [-48h]

  if ( this->fadeTime != 0 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    HIDWORD(v3) = this->fadeTime;
    LODWORD(v3) = HIDWORD(v3) - GameMs;
    if ( HIDWORD(v3) - GameMs > 0 )
    {
      v5 = (float)(this->fadeFromColor.y * (float)(this->fadeRate * (float)v3));
      v6 = (float)(this->fadeFromColor.z * (float)(this->fadeRate * (float)v3));
      v7 = (float)(this->fadeFromColor.w * (float)(this->fadeRate * (float)v3));
      v8 = (float)(this->fadeToColor.y * (float)((float)1.0 - (float)(this->fadeRate * (float)v3)));
      v9 = (float)(this->fadeToColor.z * (float)((float)1.0 - (float)(this->fadeRate * (float)v3)));
      v10 = (float)(this->fadeToColor.w * (float)((float)1.0 - (float)(this->fadeRate * (float)v3)));
      this->fadeColor.x = (float)(this->fadeFromColor.x * (float)(this->fadeRate * (float)v3))
                        + (float)(this->fadeToColor.x * (float)((float)1.0 - (float)(this->fadeRate * (float)v3)));
      this->fadeColor.y = (float)v5 + (float)v8;
      this->fadeColor.z = (float)v6 + (float)v9;
      this->fadeColor.w = (float)v7 + (float)v10;
    }
    else
    {
      this->fadeColor.x = this->fadeToColor.x;
      this->fadeColor.y = this->fadeToColor.y;
      this->fadeColor.z = this->fadeToColor.z;
      w = this->fadeToColor.w;
      this->fadeColor.w = this->fadeToColor.w;
      if ( w == 0.0 )
        this->fadeTime = 0;
    }
    if ( this->fadeColor.w != 0.0 )
    {
      guiModel = this->guiModel;
      guiModel->currentVertexColor = idColor::PackColor(color: &this->fadeColor);
      whiteMaterial = this->whiteMaterial;
      VirtualHeight = idRenderModelGui::GetVirtualHeight(this: this->guiModel, a2: v15, a3: v14, a4: v13);
      VirtualWidth = idRenderModelGui::GetVirtualWidth(this: this->guiModel, a2: v19, a3: v18, a4: v17);
      idRenderModelGui::DrawStretchPic(
        this: this->guiModel,
        x: 0.0,
        y: 0.0,
        w: VirtualWidth,
        h: VirtualHeight,
        s1: 0.0,
        t1: 0.0,
        s2: 1.0,
        t2: 1.0,
        material: v27,
        a11: v26,
        a12: v25,
        a13: v24,
        a14: v23,
        a15: v22,
        a16: v21,
        a17: v28,
        a18: v29,
        a19: v30,
        a20: v31,
        a21: v32,
        a22: v33,
        a23: v34,
        a24: v35,
        a25: v36,
        a26: v37,
        a27: v38,
        a28: v39,
        a29: v40,
        a30: v41,
        a31: v42,
        a32: v43,
        a33: v44,
        a34: v45,
        a35: v46,
        a36: v47,
        a37: v48,
        a38: whiteMaterial);
    }
  }
}


// ========================================================================
// ?CalcFOV@idView@@QAAXM@Z
// EA  : 0x82E88A90
// RVA : 0x00E88A90
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::CalcFOV(idView *this, long double base_fov)
{
  *((double *)&base_fov + 1) = 1.7777778;
  idView::CalcFOV(a1: (float *)this, targetAspectRatio: base_fov);
}


// ========================================================================
// ??0idView@@QAA@XZ
// EA  : 0x82E88E90
// RVA : 0x00E88E90
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

idView *__fastcall idView::idView(idView *this)
{
  double currentValue; // fp0
  float *p_y; // r11
  int v4; // r10
  float *p_duration; // r9
  double v6; // fp13
  double v7; // fp12
  double v8; // fp0
  int v9; // r10
  float *p_currentValue; // r11
  double v11; // fp0
  idRenderModel *v12; // r3
  long double v13; // fp2

  renderView_t::renderView_t(this: &this->gameview, threadId: THREAD_MAIN);
  this->allowViewIDOnly = false;
  this->forceVirtualMaterialLoad = false;
  this->baseFovX = 90.0;
  this->useHQViewColorMipsGeneration = false;
  this->viewVelocity.x = 0.0;
  this->viewVelocity.y = 0.0;
  this->viewVelocity.z = 0.0;
  this->skipViewEffects = false;
  this->damageScaleTracker.duration = 0.0;
  this->damageScaleTracker.startTime = 0.0;
  this->damageScaleTracker.currentTime = 0.0;
  this->damageScaleTracker.currentValue = 0.0;
  currentValue = this->damageScaleTracker.currentValue;
  this->damageScaleTracker.endValue = this->damageScaleTracker.currentValue;
  this->damageScaleTracker.startValue = currentValue;
  this->overrideEnv = nullptr;
  this->overrideEnvBlendDuration = 0.0;
  this->overrideEnvModelIndex = -1;
  this->envOverrideEnabled = false;
  idStaticParmBlock<32>::idStaticParmBlock<32>(this: &this->envParms, threadId: THREAD_MAIN);
  this->controllerShakeHighMag = 0.0;
  this->controllerShakeLowMag = 0.0;
  this->controllerShakeHighTime = -1;
  this->controllerShakeLowTime = -1;
  this->kickFinishTime = -1;
  this->kickAngles.pitch = 0.0;
  this->kickAngles.yaw = 0.0;
  this->kickAngles.roll = 0.0;
  this->isBobEnabled = true;
  this->fadeColor.x = 0.0;
  this->fadeColor.y = 0.0;
  this->fadeColor.z = 0.0;
  this->fadeColor.w = 0.0;
  this->fadeToColor.x = 0.0;
  this->fadeToColor.y = 0.0;
  this->fadeToColor.z = 0.0;
  this->fadeToColor.w = 0.0;
  this->fadeFromColor.x = 0.0;
  this->fadeFromColor.y = 0.0;
  this->fadeFromColor.z = 0.0;
  this->fadeFromColor.w = 0.0;
  this->fadeTime = -1;
  this->fadeRate = 0.0;
  this->shakeVolume = 0.0;
  this->cameraShake = 0.0;
  this->playerMaxShakeScale = 1.0;
  p_y = &this->radialBlur[0].centerPos.y;
  this->maxShakeAngles.pitch = 10.0;
  this->maxShakeAngles.yaw = 10.0;
  v4 = 3;
  this->maxShakeAngles.roll = 10.0;
  p_duration = &this->blur.duration;
  this->maxShakeOffset.x = 6.0;
  this->maxShakeOffset.y = 6.0;
  this->maxShakeOffset.z = 6.0;
  this->blur.duration = 0.0;
  this->blur.startTime = 0.0;
  this->blur.currentTime = 0.0;
  this->blur.currentValue = 0.0;
  v6 = this->blur.currentValue;
  this->blur.endValue = this->blur.currentValue;
  this->blur.startValue = v6;
  this->blurParm = nullptr;
  this->dbl.duration = 0.0;
  this->dbl.startTime = 0.0;
  this->dbl.currentTime = 0.0;
  this->dbl.currentValue = 0.0;
  v7 = this->dbl.currentValue;
  this->dbl.endValue = this->dbl.currentValue;
  this->dbl.startValue = v7;
  this->dblVParm = nullptr;
  do
  {
    *(p_y - 6) = 0.0;
    *(p_y - 3) = 0.0;
    --v4;
    p_duration += 13;
    *p_duration = 0.0;
    *(p_y - 2) = 0.0;
    v8 = *(p_y - 2);
    *(p_y - 4) = *(p_y - 2);
    *(p_y - 5) = v8;
    p_y[1] = 0.0;
    *p_y = 0.0;
    *(p_y - 1) = 0.0;
    p_y[2] = NAN;
    p_y[3] = 0.0;
    *((_BYTE *)p_y + 20) = 0;
    p_y[4] = 0.0;
    *((_BYTE *)p_y + 21) = 0;
    *((_WORD *)p_y + 11) = 1;
    p_y += 13;
  }
  while ( v4 >= 0 );
  *(_WORD *)&this->godRaysEnabled = 1;
  this->godRaysPosition.x = 1.0;
  this->godRaysPosition.y = 0.0;
  this->godRaysPosition.z = 1.0;
  this->whiplashUpdateFrac = 1.0;
  this->godRaysSize = 768;
  this->whiplashVelocityFrac = 0.1;
  this->godRaysSourceSize = 256;
  this->whiplashFrictionFrac = 0.80000001;
  this->godRaysMaterial = nullptr;
  this->whiplashMinVelocityLen = 0.0099999998;
  v9 = 3;
  p_currentValue = &this->borderDamageEffects[0].amount.currentValue;
  do
  {
    *(p_currentValue - 4) = 0.0;
    --v9;
    *(p_currentValue - 5) = 0.0;
    *(p_currentValue - 1) = 0.0;
    *p_currentValue = 0.0;
    v11 = *p_currentValue;
    *(p_currentValue - 2) = *p_currentValue;
    *(p_currentValue - 3) = v11;
    p_currentValue += 8;
  }
  while ( v9 >= 0 );
  this->gameview.viewID = 1;
  this->gameview.vieworg.z = 0.0;
  this->gameview.vieworg.y = 0.0;
  this->gameview.vieworg.x = 0.0;
  this->gameview.viewaxis.mat[2].z = 1.0;
  this->gameview.viewaxis.mat[1].y = 1.0;
  this->gameview.viewaxis.mat[0].x = 1.0;
  this->gameview.viewaxis.mat[1].z = 0.0;
  this->gameview.viewaxis.mat[0].z = 0.0;
  this->gameview.viewaxis.mat[0].y = 0.0;
  this->gameview.viewaxis.mat[2].y = 0.0;
  this->gameview.viewaxis.mat[2].x = 0.0;
  this->gameview.viewaxis.mat[1].x = 0.0;
  this->viewVelocity.z = 0.0;
  this->viewVelocity.y = 0.0;
  this->viewVelocity.x = 0.0;
  this->viewBob.z = 0.0;
  this->viewBob.y = 0.0;
  this->viewBob.x = 0.0;
  this->viewBobAngles.roll = 0.0;
  this->viewBobAngles.yaw = 0.0;
  this->viewBobAngles.pitch = 0.0;
  this->whiplashGoal.roll = 0.0;
  this->whiplashGoal.yaw = 0.0;
  this->whiplashGoal.pitch = 0.0;
  this->whiplashVel.roll = 0.0;
  this->whiplashVel.yaw = 0.0;
  this->whiplashVel.pitch = 0.0;
  this->whiplashCur.roll = 0.0;
  this->whiplashCur.yaw = 0.0;
  this->whiplashCur.pitch = 0.0;
  this->radialBlur[0].enabled = false;
  this->radialBlur[0].scaleVal = 0.0;
  this->radialBlur[0].centerPos.x = 0.0;
  this->radialBlur[0].centerPos.z = 0.0;
  this->radialBlur[0].centerPos.y = 0.0;
  this->radialBlur[1].enabled = false;
  this->radialBlur[1].scaleVal = 0.0;
  this->radialBlur[1].centerPos.z = 0.0;
  this->radialBlur[1].centerPos.y = 0.0;
  this->radialBlur[1].centerPos.x = 0.0;
  this->radialBlur[2].enabled = false;
  this->radialBlur[2].scaleVal = 0.0;
  this->radialBlur[2].centerPos.z = 0.0;
  this->radialBlur[2].centerPos.y = 0.0;
  this->radialBlur[2].centerPos.x = 0.0;
  this->radialBlur[3].enabled = false;
  this->radialBlur[3].scaleVal = 0.0;
  this->radialBlur[3].centerPos.z = 0.0;
  this->radialBlur[3].centerPos.y = 0.0;
  this->radialBlur[3].centerPos.x = 0.0;
  this->rpRadialBlurEnable = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                         this: &idDeclRenderParm::resourceList,
                                                         name: "radialBlurEnable",
                                                         makeDefault: true);
  this->rpRadialBlurVal = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                      this: &idDeclRenderParm::resourceList,
                                                      name: "radialBlurScale",
                                                      makeDefault: true);
  this->rpRadialBlurScaleVal = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                           this: &idDeclRenderParm::resourceList,
                                                           name: "radialBlurMaxScale",
                                                           makeDefault: true);
  this->rpRadialBlurCenter = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                         this: &idDeclRenderParm::resourceList,
                                                         name: "radialBlurCenter",
                                                         makeDefault: true);
  memset(Dst: this->screenEffects, Val: 0, Size: sizeof(this->screenEffects));
  this->borderDamageMaterials[0].materials[0] = nullptr;
  this->borderDamageMaterials[0].materials[1] = nullptr;
  this->borderDamageMaterials[1].materials[0] = nullptr;
  this->borderDamageMaterials[1].materials[1] = nullptr;
  this->borderDamageMaterials[0].materials[0] = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                                      this: &idMaterial::resourceList,
                                                                      name: "viewEffect/damage_overlay/damage_small_filter",
                                                                      makeDefault: true);
  this->borderDamageMaterials[0].materials[1] = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                                      this: &idMaterial::resourceList,
                                                                      name: "viewEffect/damage_overlay/damage_small_screen",
                                                                      makeDefault: true);
  this->borderDamageMaterials[1].materials[0] = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                                      this: &idMaterial::resourceList,
                                                                      name: "viewEffect/damage_overlay/damage_big_filter",
                                                                      makeDefault: true);
  this->borderDamageMaterials[1].materials[0] = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                                      this: &idMaterial::resourceList,
                                                                      name: "viewEffect/damage_overlay/damage_big_screen",
                                                                      makeDefault: true);
  memset(Dst: this->borderDamageEffects, Val: 0, Size: sizeof(this->borderDamageEffects));
  this->borderDamageEffects[0].effectMaterial.materials[0] = this->borderDamageMaterials[0].materials[0];
  this->borderDamageEffects[0].effectMaterial.materials[1] = this->borderDamageMaterials[0].materials[1];
  this->borderDamageEffects[1].effectMaterial.materials[0] = this->borderDamageMaterials[0].materials[0];
  this->borderDamageEffects[1].effectMaterial.materials[1] = this->borderDamageMaterials[0].materials[1];
  this->borderDamageEffects[2].effectMaterial.materials[0] = this->borderDamageMaterials[0].materials[0];
  this->borderDamageEffects[2].effectMaterial.materials[1] = this->borderDamageMaterials[0].materials[1];
  this->borderDamageEffects[3].effectMaterial.materials[0] = this->borderDamageMaterials[0].materials[0];
  this->borderDamageEffects[3].effectMaterial.materials[1] = this->borderDamageMaterials[0].materials[1];
  this->worldSpaceMVPMatrix.m[0] = 1.0;
  this->worldSpaceMVPMatrix.m[1] = 0.0;
  this->worldSpaceMVPMatrix.m[2] = 0.0;
  this->worldSpaceMVPMatrix.m[3] = 0.0;
  this->worldSpaceMVPMatrix.m[4] = 0.0;
  this->worldSpaceMVPMatrix.m[5] = 1.0;
  this->worldSpaceMVPMatrix.m[6] = 0.0;
  this->worldSpaceMVPMatrix.m[7] = 0.0;
  this->worldSpaceMVPMatrix.m[8] = 0.0;
  this->worldSpaceMVPMatrix.m[9] = 0.0;
  this->worldSpaceMVPMatrix.m[10] = 1.0;
  this->worldSpaceMVPMatrix.m[11] = 0.0;
  this->worldSpaceMVPMatrix.m[12] = 0.0;
  this->worldSpaceMVPMatrix.m[13] = 0.0;
  this->worldSpaceMVPMatrix.m[14] = 0.0;
  this->worldSpaceMVPMatrix.m[15] = 1.0;
  this->lastMatrixUpdateFrame = -1;
  this->whiteMaterial = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                              this: &idMaterial::resourceList,
                                              name: "_white",
                                              makeDefault: true);
  v12 = clientGame->renderWorld->AllocRenderModel(this: clientGame->renderWorld, a2: "_gui", a3: 0, a4: -1);
  this->guiModel = (idRenderModelGui *)_RTDynamicCast(
                                         inptr: v12,
                                         VfDelta: 0,
                                         SrcType: &idRenderModel `RTTI Type Descriptor',
                                         TargetType: &idRenderModelGui `RTTI Type Descriptor',
                                         isReference: 0);
  this->allowViewIDOnly = false;
  *(double *)&v13 = 90.0;
  *((double *)&v13 + 1) = 1.7777778;
  idView::CalcFOV(a1: (float *)this, targetAspectRatio: v13);
  idView::ClearEffects(this);
  return this;
}


// ========================================================================
// __unwind$493131
// EA  : 0x82E894A4
// RVA : 0x00E894A4
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void _unwind_493131()
{
  int v0; // r12

  renderView_t::~renderView_t(this: (renderView_t *)(*(_DWORD *)(v0 - 224 + 244) + 16));
}


// ========================================================================
// __unwind$493132
// EA  : 0x82E894D0
// RVA : 0x00E894D0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void _unwind_493132()
{
  int v0; // r12

  idStaticParmBlock<32>::~idStaticParmBlock<32>(this: (idStaticParmBlock<32> *)(*(_DWORD *)(v0 - 224 + 244) + 1968));
}


// ========================================================================
// ?UpdateDamageEffect@idView@@QAAXXZ
// EA  : 0x82E89748
// RVA : 0x00E89748
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::UpdateDamageEffect(idView *this, int a2, int a3, int a4, __int64 a5)
{
  double VirtualWidth; // fp29
  __int64 v7; // r8
  int v8; // r5
  int v9; // r4
  double VirtualHeight; // fp28
  int valueInteger; // r24
  int GameMs; // r3
  double v15; // fp31
  double v16; // fp30
  int v17; // r25
  float *v18; // r30
  idView::damageEffect_t *borderDamageEffects; // r26
  int v20; // r29
  idView::damageEffectMaterial_t *p_effectMaterial; // r27
  int v22; // r7
  unsigned __int64 v23; // r6
  int v24; // r11
  int v25; // r11
  double v26; // fp0
  double v27; // fp8
  double v28; // fp7
  double v29; // fp6
  double v30; // fp12
  double v31; // fp4
  double v32; // fp5
  double v33; // fp3
  double v34; // fp2
  double v35; // fp1
  int v36; // r7
  unsigned __int64 v37; // r6
  int num; // r11
  int i; // r27
  int v40; // r29
  int v41; // r30
  idView::damageOverlayData_t *v42; // r4
  const idMaterial *v43; // r8
  unsigned __int64 v44; // r10
  parmValue_t v45; // [sp+50h] [-2C0h] BYREF
  float v46; // [sp+60h] [-2B0h] BYREF
  float v47[7]; // [sp+64h] [-2ACh] BYREF
  float v48[5]; // [sp+80h] [-290h] BYREF
  float v49; // [sp+94h] [-27Ch]
  float v50; // [sp+98h] [-278h]
  float v51; // [sp+9Ch] [-274h]
  idView::damageOverlayData_t v52; // [sp+A0h] [-270h] BYREF
  float v53[32]; // [sp+F0h] [-220h] BYREF
  idList<idView::damageOverlayData_t,5> v54; // [sp+170h] [-1A0h] BYREF
  int v55; // [sp+180h] [-190h] BYREF

  if ( view_drawDMG.valueInteger == 0 )
    return;
  VirtualWidth = idRenderModelGui::GetVirtualWidth(this: this->guiModel, a2, a3, a4: a5);
  VirtualHeight = idRenderModelGui::GetVirtualHeight(this: this->guiModel, a2: v9, a3: v8, a4: v7);
  valueInteger = view_debugDMG.valueInteger;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  _FP0 = (float)((float)VirtualWidth - (float)VirtualHeight);
  __asm { fsel      f9, f0, f28, f29 }
  v53[0] = 1.0;
  v53[2] = 1.0;
  v53[3] = 1.0;
  v53[5] = 1.0;
  v53[1] = 0.0;
  v54.size = 4;
  v53[4] = 0.0;
  v54.num = 0;
  v53[6] = 0.0;
  v54.granularity = 1;
  v15 = (float)((float)_FP9 * (float)0.88999999);
  v53[7] = 0.0;
  v53[8] = 0.0;
  v54.list = (idView::damageOverlayData_t *)&v55;
  v53[9] = 1.0;
  v54.memTag = 5;
  v53[10] = 0.0;
  v54.listStatic = 1;
  v53[11] = 0.0;
  v53[12] = 1.0;
  v53[13] = 0.0;
  v53[14] = 1.0;
  v53[15] = 1.0;
  v53[16] = 1.0;
  v53[17] = 0.0;
  v53[18] = 0.0;
  v53[19] = 0.0;
  v53[20] = 0.0;
  v53[21] = 1.0;
  v53[22] = 1.0;
  v53[23] = 1.0;
  v53[24] = 0.0;
  v53[25] = 0.0;
  v53[26] = 1.0;
  v53[27] = 0.0;
  v53[28] = 1.0;
  v53[29] = 1.0;
  v53[30] = 0.0;
  v53[31] = 1.0;
  v46 = 1.0;
  v16 = (float)((float)__SPAIR64__(0x82000000, GameMs) * (float)0.001);
  v47[0] = 0.5;
  v47[1] = 1.0;
  v47[2] = 0.5;
  v47[3] = 0.5;
  v47[4] = 1.0;
  v47[5] = 0.5;
  v47[6] = 1.0;
  v48[0] = (float)((float)VirtualWidth - (float)((float)_FP9 * (float)0.88999999)) * (float)0.5;
  v48[1] = 0.0;
  v48[2] = v48[0];
  v48[3] = (float)VirtualHeight - (float)((float)((float)_FP9 * (float)0.88999999) * (float)0.5);
  v48[4] = 0.0;
  v49 = (float)((float)VirtualHeight - (float)((float)_FP9 * (float)0.88999999)) * (float)0.5;
  v50 = (float)VirtualWidth - (float)((float)((float)_FP9 * (float)0.88999999) * (float)0.5);
  v51 = v49;
  v45.value[3] = (float)VirtualHeight / (float)VirtualWidth;
  v45.value[2] = v45.value[3];
  v45.value[1] = v45.value[3];
  v45.value[0] = v45.value[3];
  idParmBlock::SetParm(
    this: &this->gameview.parmBlock,
    parm: (const idDeclRenderParm *)screenSizeRatio.r,
    parmValue: &v45);
  v17 = 0;
  v18 = v53;
  borderDamageEffects = this->borderDamageEffects;
  v20 = 0;
  do
  {
    p_effectMaterial = &borderDamageEffects->effectMaterial;
    v45.swizzle[1] = (int)(float)(idInterpolate<float>::GetCurrentValue(this: &borderDamageEffects->amount, time: v16)
                                * (float)255.89999);
    v24 = v45.swizzle[1];
    if ( v45.swizzle[1] >= 0 )
    {
      if ( v45.swizzle[1] > 255 )
        v24 = 255;
    }
    else
    {
      v24 = 0;
    }
    if ( valueInteger == 0 )
    {
      if ( v24 <= 0 )
        goto LABEL_15;
      goto LABEL_14;
    }
    p_effectMaterial = this->borderDamageMaterials;
    if ( valueInteger <= 0 )
      p_effectMaterial = &this->borderDamageMaterials[1];
    v25 = abs32(valueInteger);
    if ( v25 <= 1 || v25 - 2 == v17 )
    {
      v24 = 255;
LABEL_14:
      v52.alpha = v24;
      v26 = v18[1];
      v52.topLeft.z = *v18;
      v52.effectMaterial = p_effectMaterial;
      v52.topLeft.w = v26;
      v27 = (float)(v47[v20 - 1] * (float)v15);
      v28 = (float)(v47[v20] * (float)v15);
      v29 = v48[v20];
      v30 = v18[3];
      v31 = v48[v20 + 1];
      v32 = v18[5];
      v33 = v18[4];
      v34 = v18[7];
      v35 = v18[6];
      v52.topRight.z = v18[2];
      v52.topLeft.y = v31;
      v52.topRight.y = v31;
      v52.topRight.w = v30;
      v52.bottomLeft.z = v35;
      v52.bottomLeft.w = v34;
      v52.bottomRight.z = v33;
      v52.bottomRight.w = v32;
      v52.bottomLeft.y = (float)v28 + (float)v31;
      v52.topLeft.x = v29;
      v52.bottomLeft.x = v29;
      v52.bottomRight.y = v52.bottomLeft.y;
      v52.topRight.x = (float)v29 + (float)v27;
      v52.bottomRight.x = v52.topRight.x;
      v45.value[0] = v52.bottomLeft.y;
      idList<idView::damageOverlayData_t,5>::Append(this: &v54, obj: &v52);
    }
LABEL_15:
    v20 += 2;
    ++v17;
    ++borderDamageEffects;
    v18 += 8;
  }
  while ( v20 < 8 );
  if ( v54.num > 0 )
  {
    idRenderModelGui::SetGLState(this: this->guiModel, a2: 0, bits: v23, a4: v22);
    num = v54.num;
    for ( i = 0; i < 2; ++i )
    {
      v40 = 0;
      if ( num > 0 )
      {
        v41 = 0;
        do
        {
          v42 = &v54.list[v41];
          v43 = v54.list[v41].effectMaterial->materials[i];
          if ( v43 != nullptr )
          {
            HIDWORD(v44) = this->guiModel;
            LODWORD(v44) = ((unsigned __int8)v42->alpha << 24) | 0xFFFFFF;
            *(_DWORD *)(HIDWORD(v44) + 2036) = v44;
            idRenderModelGui::DrawStretchPic(
              this: this->guiModel,
              topLeft: &v42->topLeft,
              topRight: &v42->topRight,
              bottomRight: &v42->bottomRight,
              bottomLeft: &v42->bottomLeft,
              material: v43,
              a7: v44);
            num = v54.num;
          }
          ++v40;
          ++v41;
        }
        while ( v40 < num );
      }
    }
    idRenderModelGui::SetGLState(
      this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
      a2: defaultExtraGLState,
      bits: v37,
      a4: v36);
  }
  if ( (v54.listStatic == 0 || v54.listStatic == 2) && v54.list != nullptr )
    idMem::Free(this: &mem, ptr: v54.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$493589_1
// EA  : 0x82E89B84
// RVA : 0x00E89B84
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void _unwind_493589_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 784 + 368));
}


// ========================================================================
// ?Render@idView@@QAAXXZ
// EA  : 0x82E89BB0
// RVA : 0x00E89BB0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __fastcall idView::Render(idView *this)
{
  double v2; // fp1
  bool forceVirtualMaterialLoad; // r9
  const idDecl *v4; // r28
  bool useHQViewColorMipsGeneration; // r8
  BOOL envOverrideEnabled; // r6
  const idDeclEnv *overrideEnv; // r11
  int overrideEnvModelIndex; // r5
  idAngles *v9; // r3
  double v10; // fp9
  double v11; // fp7
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r8
  int v16; // r6
  int v17; // r5
  int v18; // r4
  idView *v19; // r3
  const idMaterial *v20; // r29
  int v21; // r3
  __int64 v22; // r7
  __int64 v23; // r4
  double v24; // fp13
  int v25; // r9
  int v26; // r8
  int v27; // r7
  int v28; // r6
  int v29; // r5
  int v30; // r27
  const idDeclDamage::damageScreenEffectParms_t *p_name; // r30
  int v32; // [sp+8h] [-108h]
  int v33; // [sp+Ch] [-104h]
  int v34; // [sp+10h] [-100h]
  int v35; // [sp+14h] [-FCh]
  int v36; // [sp+18h] [-F8h]
  int v37; // [sp+1Ch] [-F4h]
  int v38; // [sp+20h] [-F0h]
  int v39; // [sp+24h] [-ECh]
  int v40; // [sp+28h] [-E8h]
  int v41; // [sp+2Ch] [-E4h]
  int v42; // [sp+30h] [-E0h]
  int v43; // [sp+34h] [-DCh]
  int v44; // [sp+38h] [-D8h]
  int v45; // [sp+3Ch] [-D4h]
  int v46; // [sp+40h] [-D0h]
  int v47; // [sp+44h] [-CCh]
  int v48; // [sp+48h] [-C8h]
  int v49; // [sp+4Ch] [-C4h]
  int v50; // [sp+50h] [-C0h]
  int v51; // [sp+54h] [-BCh]
  int v52; // [sp+58h] [-B8h]
  __int64 v53; // [sp+60h] [-B0h] BYREF
  float v54; // [sp+68h] [-A8h]
  idMat3 v55; // [sp+70h] [-A0h] BYREF
  float v56; // [sp+94h] [-7Ch]
  float v57; // [sp+98h] [-78h]
  float CurrentValue; // [sp+9Ch] [-74h]
  idAngles v59[9]; // [sp+A0h] [-70h] BYREF

  v2 = ((double (__fastcall *)(idSoundWorld *, int))clientGame->soundWorld->CurrentShakeAmplitude)(
         a1: clientGame->soundWorld,
         a2: this->gameview.viewID);
  forceVirtualMaterialLoad = this->forceVirtualMaterialLoad;
  v4 = nullptr;
  useHQViewColorMipsGeneration = this->useHQViewColorMipsGeneration;
  this->shakeVolume = v2;
  this->gameview.radialBlurEnabled = false;
  this->gameview.forceFullVirtualTextureLoad = forceVirtualMaterialLoad;
  this->gameview.useHQViewColorMipsGeneration = useHQViewColorMipsGeneration;
  idParmBlock::Append(this: &this->gameview.parmBlock, block: &gameLocal->renderParmBlock);
  idStaticParmBlock<32>::operator=(this: &this->gameview.envOverrideParmBlock, __that: &this->envParms);
  envOverrideEnabled = this->envOverrideEnabled;
  overrideEnv = this->overrideEnv;
  overrideEnvModelIndex = this->overrideEnvModelIndex;
  this->gameview.dynEnvOverrideDuration = this->overrideEnvBlendDuration;
  this->gameview.applyDynEnvOverride = envOverrideEnabled;
  this->gameview.dynEnvOverride = overrideEnv;
  this->gameview.dynEnvOverrideModelIndex = overrideEnvModelIndex;
  if ( envOverrideEnabled && overrideEnv == nullptr )
    this->envOverrideEnabled = false;
  idView::AngleOffset(this: (idView *)&v53, result: (idAngles *)this);
  if ( (((unsigned int)v53 | LODWORD(v54) | HIDWORD(v53)) & 0x7FFFFFFF) != 0 )
  {
    v9 = idMat3::ToAngles(this: (idMat3 *)&v55.mat[2].z, result: (idAngles *)&this->gameview.viewaxis);
    v10 = (float)(v9->roll + v54);
    v11 = (float)(v9->yaw + *((float *)&v53 + 1));
    v55.mat[0].x = v9->pitch + *(float *)&v53;
    v55.mat[0].z = v10;
    v55.mat[0].y = v11;
    this->gameview.viewaxis = *idAngles::ToMat3(this: v59, result: &v55);
  }
  if ( g_skipViewEffects.valueInteger == 0 && !this->skipViewEffects )
  {
    LODWORD(v12) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v53 = v12;
    CurrentValue = idInterpolate<float>::GetCurrentValue(this: &this->blur, time: (float)v12);
    v57 = CurrentValue;
    v56 = CurrentValue;
    v55.mat[2].z = CurrentValue;
    idParmBlock::SetParm(
      this: &this->gameview.parmBlock,
      parm: rp->globalBlur,
      parmValue: (const parmValue_t *)&v55.mat[2].z);
    idView::ApplyDoubleVision(this, view: &this->gameview);
    if ( this->isBobEnabled )
      idView::ApplyBob(this, view: &this->gameview);
    if ( !common->IsGamePaused(this: common) )
      idView::ApplyShake(this, view: &this->gameview);
    idView::ApplyWhiplash(
      this,
      view: &this->gameview,
      updateFrac: this->whiplashUpdateFrac,
      velocityFrac: this->whiplashVelocityFrac,
      frictionFrac: this->whiplashFrictionFrac,
      minVelLen: this->whiplashMinVelocityLen);
    idView::ApplyWhiplash(
      this,
      view: &this->gameview,
      updateFrac: this->whiplashUpdateFrac,
      velocityFrac: this->whiplashVelocityFrac,
      frictionFrac: this->whiplashFrictionFrac,
      minVelLen: this->whiplashMinVelocityLen);
    idView::ApplyRadialBlur(this, view: &this->gameview);
    idView::ApplyScreenEffect(this, view: &this->gameview);
    idView::ApplyScreenFade(this);
    idView::ApplyGodRays(this, view: &this->gameview, a3: v14, a4: v13);
    idView::UpdateDamageEffect(this: v19, a2: v18, a3: v17, a4: v16, a5: v15);
    if ( *g_testPostProcess.valueString.data != 0 )
    {
      v20 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                  this: &idMaterial::resourceList,
                                  name: g_testPostProcess.valueString.data,
                                  makeDefault: false);
      if ( v20 != nullptr )
      {
        this->guiModel->currentVertexColor = -1;
        v21 = renderSystem->GetHeight(this: renderSystem);
        HIDWORD(v22) = (idRenderSystem)renderSystem->__vftable;
        LODWORD(v22) = v21;
        v53 = v22;
        HIDWORD(v23) = (*(int (__fastcall **)(idRenderSystem *))(HIDWORD(v22) + 156))(a1: renderSystem);
        LODWORD(v23) = HIDWORD(v23);
        v24 = (double)v53;
        v53 = v23;
        idRenderModelGui::DrawStretchPic(
          this: this->guiModel,
          x: 0.0,
          y: 0.0,
          w: (float)v23,
          h: (float)v24,
          s1: 0.0,
          t1: 0.0,
          s2: 1.0,
          t2: 1.0,
          material: (const idMaterial *)HIDWORD(v23),
          a11: v29,
          a12: v28,
          a13: v27,
          a14: v26,
          a15: v25,
          a16: 0x82000000,
          a17: v32,
          a18: v33,
          a19: v34,
          a20: v35,
          a21: v36,
          a22: v37,
          a23: v38,
          a24: v39,
          a25: v40,
          a26: v41,
          a27: v42,
          a28: v43,
          a29: v44,
          a30: v45,
          a31: v46,
          a32: v47,
          a33: v48,
          a34: v49,
          a35: v50,
          a36: v51,
          a37: v52,
          a38: v20);
      }
      else
      {
        idLib::Printf(fmt: "Material not found.\n");
        idCVar::SetString(this: &g_testPostProcess, newValue: &byte_8200D768, force: true);
      }
    }
    if ( *player_testScreenDamageDef.valueString.data != 0 )
    {
      v30 = cvarSystem->GetCVarInteger(this: cvarSystem, a2: "resource_errorInGame", a3: 0);
      cvarSystem->SetCVarInteger(this: cvarSystem, a2: "resource_errorInGame", a3: 0, a4: 0);
      if ( player_testScreenDamageDef.valueString.data != nullptr )
        v4 = idDeclInfo::FindWithInheritance(
               this: &idDeclDamage::resourceList,
               name: player_testScreenDamageDef.valueString.data,
               makeDefault: false);
      cvarSystem->SetCVarInteger(this: cvarSystem, a2: "resource_errorInGame", a3: v30, a4: 0);
      if ( v4 != nullptr )
      {
        if ( player_testScreenDamageEffectScale.valueFloat <= (double)*(float *)&v4[9].__vftable )
        {
          p_name = (const idDeclDamage::damageScreenEffectParms_t *)&v4[6].name;
          if ( player_testScreenDamageEffectScale.valueFloat <= (double)*(float *)&v4[7].staleCount )
            p_name = (const idDeclDamage::damageScreenEffectParms_t *)&v4[4].textSource;
        }
        else
        {
          p_name = (const idDeclDamage::damageScreenEffectParms_t *)&v4[7].textSource;
        }
        if ( p_name != nullptr )
        {
          ignoredReturnValue = sscanf(
                                 string: player_testScreenDamagePos.valueString.data,
                                 format: "%f %f %f",
                                 &v55.mat[1].y,
                                 &v55.mat[1].z,
                                 &v55.mat[2]);
          idView::AddScreenDamageEffect(this, parms: p_name);
        }
      }
      else
      {
        idLib::Printf(fmt: "Damage def %s not found.\n", player_testScreenDamageDef.valueString.data);
      }
      idCVar::SetString(this: &player_testScreenDamageDef, newValue: &byte_8200D768, force: true);
    }
  }
}


// ========================================================================
// `dynamic initializer for 'player_debugShake''
// EA  : 0x83391030
// RVA : 0x01391030
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_debugShake__()
{
  idCVar::idCVar(
    this: &player_debugShake,
    name: "player_debugShake",
    value: "0",
    flags: 1,
    description: "1 = display debugging info for camera shakes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_debugShake__);
}


// ========================================================================
// `dynamic initializer for 'player_testScreenDamageEffectScale''
// EA  : 0x83391088
// RVA : 0x01391088
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_testScreenDamageEffectScale__()
{
  idCVar::idCVar(
    this: &player_testScreenDamageEffectScale,
    name: "player_testScreenDamageEffectScale",
    value: "0.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_testScreenDamageEffectScale__);
}


// ========================================================================
// `dynamic initializer for 'player_whiplash_velocity_frac''
// EA  : 0x833910E0
// RVA : 0x013910E0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_whiplash_velocity_frac__()
{
  idCVar::idCVar(
    this: &player_whiplash_velocity_frac,
    name: "player_whiplash_velocity_frac",
    value: ".1",
    flags: 4,
    description: "frac speed that whiplash cycles back and forth",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_whiplash_velocity_frac__);
}


// ========================================================================
// `dynamic initializer for 'player_whiplash_friction_frac''
// EA  : 0x83391138
// RVA : 0x01391138
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_whiplash_friction_frac__()
{
  idCVar::idCVar(
    this: &player_whiplash_friction_frac,
    name: "player_whiplash_friction_frac",
    value: ".8",
    flags: 4,
    description: "frac speed that slows overall whiplash",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_whiplash_friction_frac__);
}


// ========================================================================
// `dynamic initializer for 'player_whiplash_min_velocity_len''
// EA  : 0x83391190
// RVA : 0x01391190
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_whiplash_min_velocity_len__()
{
  idCVar::idCVar(
    this: &player_whiplash_min_velocity_len,
    name: "player_whiplash_min_velocity_len",
    value: ".01",
    flags: 4,
    description: "min velocity required to activate whiplash",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_whiplash_min_velocity_len__);
}


// ========================================================================
// `dynamic initializer for 'player_whiplash_update_frac''
// EA  : 0x833911E8
// RVA : 0x013911E8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_whiplash_update_frac__()
{
  idCVar::idCVar(
    this: &player_whiplash_update_frac,
    name: "player_whiplash_update_frac",
    value: "1",
    flags: 4,
    description: "update frac per frame (partial updates)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_whiplash_update_frac__);
}


// ========================================================================
// `dynamic initializer for 'screenSizeRatio''
// EA  : 0x83391240
// RVA : 0x01391240
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void _dynamic_initializer_for__screenSizeRatio__()
{
  screenSizeRatio.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&screenSizeRatio;
}


// ========================================================================
// `dynamic initializer for 'view_damage_minScale''
// EA  : 0x83391260
// RVA : 0x01391260
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_damage_minScale__()
{
  idCVar::idCVar(
    this: &view_damage_minScale,
    name: "view_damage_minScale",
    value: "0.05",
    flags: 4,
    description: "lowest visual effect",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_damage_minScale__);
}


// ========================================================================
// `dynamic initializer for 'view_damage_maxScale''
// EA  : 0x833912B8
// RVA : 0x013912B8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_damage_maxScale__()
{
  idCVar::idCVar(
    this: &view_damage_maxScale,
    name: "view_damage_maxScale",
    value: "0.5",
    flags: 4,
    description: "highest visual effect.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_damage_maxScale__);
}


// ========================================================================
// `dynamic initializer for 'view_kickTime_min''
// EA  : 0x83391310
// RVA : 0x01391310
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_kickTime_min__()
{
  idCVar::idCVar(
    this: &view_kickTime_min,
    name: "view_kickTime_min",
    value: "150",
    flags: 4,
    description: "view kick time from damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_kickTime_min__);
}


// ========================================================================
// `dynamic initializer for 'view_kickTime_max''
// EA  : 0x83391368
// RVA : 0x01391368
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_kickTime_max__()
{
  idCVar::idCVar(
    this: &view_kickTime_max,
    name: "view_kickTime_max",
    value: "300",
    flags: 4,
    description: "view kick time from damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_kickTime_max__);
}


// ========================================================================
// `dynamic initializer for 'view_kickAmplitude_min''
// EA  : 0x833913C0
// RVA : 0x013913C0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_kickAmplitude_min__()
{
  idCVar::idCVar(
    this: &view_kickAmplitude_min,
    name: "view_kickAmplitude_min",
    value: "0.5",
    flags: 4,
    description: "view kick amplitude from damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_kickAmplitude_min__);
}


// ========================================================================
// `dynamic initializer for 'view_kickAmplitude_max''
// EA  : 0x83391418
// RVA : 0x01391418
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_kickAmplitude_max__()
{
  idCVar::idCVar(
    this: &view_kickAmplitude_max,
    name: "view_kickAmplitude_max",
    value: "2",
    flags: 4,
    description: "view kick amplitude from damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_kickAmplitude_max__);
}


// ========================================================================
// `dynamic initializer for 'view_blur_min''
// EA  : 0x83391470
// RVA : 0x01391470
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_blur_min__()
{
  idCVar::idCVar(
    this: &view_blur_min,
    name: "view_blur_min",
    value: "1.5",
    flags: 4,
    description: "view blur from damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_blur_min__);
}


// ========================================================================
// `dynamic initializer for 'view_blur_max''
// EA  : 0x833914C8
// RVA : 0x013914C8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_blur_max__()
{
  idCVar::idCVar(
    this: &view_blur_max,
    name: "view_blur_max",
    value: "3",
    flags: 4,
    description: "view blur from damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_blur_max__);
}


// ========================================================================
// `dynamic initializer for 'view_blurTime_min''
// EA  : 0x83391520
// RVA : 0x01391520
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_blurTime_min__()
{
  idCVar::idCVar(
    this: &view_blurTime_min,
    name: "view_blurTime_min",
    value: "350",
    flags: 4,
    description: "view blur time from damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_blurTime_min__);
}


// ========================================================================
// `dynamic initializer for 'view_blurTime_max''
// EA  : 0x83391578
// RVA : 0x01391578
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_blurTime_max__()
{
  idCVar::idCVar(
    this: &view_blurTime_max,
    name: "view_blurTime_max",
    value: "2000",
    flags: 4,
    description: "view blur time from damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_blurTime_max__);
}


// ========================================================================
// `dynamic initializer for 'view_doubleVision_min''
// EA  : 0x833915D0
// RVA : 0x013915D0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_doubleVision_min__()
{
  idCVar::idCVar(
    this: &view_doubleVision_min,
    name: "view_doubleVision_min",
    value: "0.004",
    flags: 4,
    description: "view double vision amount from damage (rage default 0.02)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_doubleVision_min__);
}


// ========================================================================
// `dynamic initializer for 'view_doubleVision_max''
// EA  : 0x83391628
// RVA : 0x01391628
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_doubleVision_max__()
{
  idCVar::idCVar(
    this: &view_doubleVision_max,
    name: "view_doubleVision_max",
    value: "0.02",
    flags: 4,
    description: "view double vision amount from damage (rage default 0.05)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_doubleVision_max__);
}


// ========================================================================
// `dynamic initializer for 'view_doubleVisionTime_min''
// EA  : 0x83391680
// RVA : 0x01391680
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_doubleVisionTime_min__()
{
  idCVar::idCVar(
    this: &view_doubleVisionTime_min,
    name: "view_doubleVisionTime_min",
    value: "250",
    flags: 4,
    description: "view double vision amount from damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_doubleVisionTime_min__);
}


// ========================================================================
// `dynamic initializer for 'view_doubleVisionTime_max''
// EA  : 0x833916D8
// RVA : 0x013916D8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_doubleVisionTime_max__()
{
  idCVar::idCVar(
    this: &view_doubleVisionTime_max,
    name: "view_doubleVisionTime_max",
    value: "2000",
    flags: 4,
    description: "view double vision amount from damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_doubleVisionTime_max__);
}


// ========================================================================
// `dynamic initializer for 'view_doubleVisionPeriod''
// EA  : 0x83391730
// RVA : 0x01391730
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_doubleVisionPeriod__()
{
  idCVar::idCVar(
    this: &view_doubleVisionPeriod,
    name: "view_doubleVisionPeriod",
    value: "500",
    flags: 2,
    description: "how many ms for a full period",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_doubleVisionPeriod__);
}


// ========================================================================
// `dynamic initializer for 'view_doubleVisionPeriodEffect''
// EA  : 0x83391788
// RVA : 0x01391788
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_doubleVisionPeriodEffect__()
{
  idCVar::idCVar(
    this: &view_doubleVisionPeriodEffect,
    name: "view_doubleVisionPeriodEffect",
    value: "0.025",
    flags: 4,
    description: "how big an effect the period has on the double vision",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_doubleVisionPeriodEffect__);
}


// ========================================================================
// `dynamic initializer for 'view_damageFeedbackMeleeOnly''
// EA  : 0x833917E0
// RVA : 0x013917E0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_damageFeedbackMeleeOnly__()
{
  idCVar::idCVar(
    this: &view_damageFeedbackMeleeOnly,
    name: "view_damageFeedbackMeleeOnly",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_damageFeedbackMeleeOnly__);
}


// ========================================================================
// `dynamic initializer for 'view_showPlayerDamageViewEffect''
// EA  : 0x83391838
// RVA : 0x01391838
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_showPlayerDamageViewEffect__()
{
  idCVar::idCVar(
    this: &view_showPlayerDamageViewEffect,
    name: "view_showPlayerDamageViewEffect",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_showPlayerDamageViewEffect__);
}


// ========================================================================
// `dynamic initializer for 'player_testScreenDamageDef''
// EA  : 0x83391890
// RVA : 0x01391890
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_testScreenDamageDef__()
{
  idCVar::idCVar(
    this: &player_testScreenDamageDef,
    name: "player_testScreenDamageDef",
    value: &byte_8200D768,
    flags: 0,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_testScreenDamageDef__);
}


// ========================================================================
// `dynamic initializer for 'player_testScreenDamagePos''
// EA  : 0x833918E0
// RVA : 0x013918E0
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_testScreenDamagePos__()
{
  idCVar::idCVar(
    this: &player_testScreenDamagePos,
    name: "player_testScreenDamagePos",
    value: "0 0 85",
    flags: 0,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_testScreenDamagePos__);
}


// ========================================================================
// `dynamic initializer for 'view_skipDamageEffect''
// EA  : 0x83391938
// RVA : 0x01391938
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_skipDamageEffect__()
{
  idCVar::idCVar(
    this: &view_skipDamageEffect,
    name: "view_skipDamageEffect",
    value: "0",
    flags: 1,
    description: "skip the screen damage effects",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_skipDamageEffect__);
}


// ========================================================================
// `dynamic initializer for 'view_damageEffectRandomTextureFlip''
// EA  : 0x83391990
// RVA : 0x01391990
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_damageEffectRandomTextureFlip__()
{
  idCVar::idCVar(
    this: &view_damageEffectRandomTextureFlip,
    name: "view_damageEffectRandomTextureFlip",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_damageEffectRandomTextureFlip__);
}


// ========================================================================
// `dynamic initializer for 'view_damageScale''
// EA  : 0x833919E8
// RVA : 0x013919E8
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_damageScale__()
{
  idCVar::idCVar(
    this: &view_damageScale,
    name: "view_damageScale",
    value: "0.6",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_damageScale__);
}


// ========================================================================
// `dynamic initializer for 'view_debugDMG''
// EA  : 0x83391A40
// RVA : 0x01391A40
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_debugDMG__()
{
  idCVar::idCVar(
    this: &view_debugDMG,
    name: "view_debugDMG",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_debugDMG__);
}


// ========================================================================
// `dynamic initializer for 'view_drawDMG''
// EA  : 0x83391A98
// RVA : 0x01391A98
// PDB : w:\tech5\tungsten\game\player\view.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__view_drawDMG__()
{
  idCVar::idCVar(
    this: &view_drawDMG,
    name: "view_drawDMG",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__view_drawDMG__);
}

