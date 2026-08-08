
// ========================================================================
// ??1idEntityCamera@@UAA@XZ
// EA  : 0x82D031E0
// RVA : 0x00D031E0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idEntityCamera::~idEntityCamera(idEntityCamera *this)
{
  this->__vftable = (idEntityCamera_vtbl *)&idCamera::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// ?Spawn@idCameraView@@QAAXXZ
// EA  : 0x82D031F0
// RVA : 0x00D031F0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idCameraView::Spawn(idCameraView *this)
{
  this->currentAngle = this->startingAngle;
}


// ========================================================================
// ?InternalDeactivate@idOnlineVehicleDeathCamera@@UAA_NXZ
// EA  : 0x82D03200
// RVA : 0x00D03200
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idOnlineVehicleDeathCamera::InternalDeactivate(idSpectatorCamera *this)
{
  idEntity::BecomeInactive(this, flags: 1);
  return 1;
}


// ========================================================================
// ?GoToTrophy@idTownGarageCamera@@QAAXXZ
// EA  : 0x82D03228
// RVA : 0x00D03228
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idTownGarageCamera::GoToTrophy(idTownGarageCamera *this)
{
  idTownGarageCamera::garageCameraState_t currentState; // r11
  int v3; // r30

  currentState = this->currentState;
  if ( currentState != GARAGECAMERASTATE_CAR )
  {
    if ( currentState == GARAGECAMERASTATE_FROMTROPHY )
    {
      v3 = this->zoomTime - (gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->zoomStartTime);
      this->zoomStartTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - v3;
      this->currentState = GARAGECAMERASTATE_TOTROPHY;
    }
  }
  else
  {
    this->zoomStartTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    this->currentState = GARAGECAMERASTATE_TOTROPHY;
  }
}


// ========================================================================
// ?GoToCar@idTownGarageCamera@@QAAXXZ
// EA  : 0x82D032F0
// RVA : 0x00D032F0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idTownGarageCamera::GoToCar(idTownGarageCamera *this)
{
  idTownGarageCamera::garageCameraState_t currentState; // r11
  int v3; // r30

  currentState = this->currentState;
  if ( currentState == GARAGECAMERASTATE_TROPHY )
  {
    this->zoomStartTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    this->currentState = GARAGECAMERASTATE_FROMTROPHY;
  }
  else if ( currentState == GARAGECAMERASTATE_TOTROPHY )
  {
    v3 = this->zoomTime - (gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->zoomStartTime);
    this->zoomStartTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - v3;
    this->currentState = GARAGECAMERASTATE_FROMTROPHY;
  }
}


// ========================================================================
// ?ToggleCarTrophyView@idTownGarageCamera@@QAAXXZ
// EA  : 0x82D033B8
// RVA : 0x00D033B8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idTownGarageCamera::ToggleCarTrophyView(idTownGarageCamera *this)
{
  idTownGarageCamera::garageCameraState_t currentState; // r11

  currentState = this->currentState;
  if ( currentState == GARAGECAMERASTATE_TROPHY || currentState == GARAGECAMERASTATE_TOTROPHY )
    idTownGarageCamera::GoToCar(this);
  else
    idTownGarageCamera::GoToTrophy(this);
}


// ========================================================================
// ?Think@idTownGarageCamera@@UAAXXZ
// EA  : 0x82D033D8
// RVA : 0x00D033D8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idTownGarageCamera::Think(idTownGarageCamera *this)
{
  idTownGarageManager *garageManager; // r3
  idTownGarageCamera::garageCameraState_t currentState; // r11

  garageManager = this->garageManager;
  if ( garageManager != nullptr )
  {
    idTownGarageManager::Update(this: garageManager);
    currentState = this->currentState;
    if ( (currentState == GARAGECAMERASTATE_TOTROPHY || currentState == GARAGECAMERASTATE_FROMTROPHY)
      && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->zoomStartTime >= this->zoomTime )
    {
      this->currentState = this->currentState != GARAGECAMERASTATE_TOTROPHY
                         ? GARAGECAMERASTATE_CAR
                         : GARAGECAMERASTATE_TROPHY;
    }
  }
}


// ========================================================================
// ?HandleGuiEvent@idTownGarageCamera@@UAA_NPBUsysEvent_t@@@Z
// EA  : 0x82D03470
// RVA : 0x00D03470
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idTownGarageCamera::HandleGuiEvent(idTownGarageCamera *this, const sysEvent_t *ev)
{
  idSWF *gui; // r3
  int result; // r3
  bool v4; // zf

  gui = this->gui;
  if ( gui == nullptr )
    return 0;
  v4 = (unsigned __int8)idSWF::HandleEvent(this: gui, event: ev) != 0;
  result = 1;
  if ( !v4 )
    return 0;
  return result;
}


// ========================================================================
// ?PreviousTarget@idTownGarageCamera@@QAA_NXZ
// EA  : 0x82D034B0
// RVA : 0x00D034B0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idTownGarageCamera::PreviousTarget(idTownGarageCamera *this)
{
  idTownGarageManager *garageManager; // r3

  garageManager = this->garageManager;
  if ( garageManager != nullptr )
    return idTownGarageManager::GotoPreviousTarget(this: garageManager);
  else
    return 0;
}


// ========================================================================
// ?NextTarget@idTownGarageCamera@@QAA_NXZ
// EA  : 0x82D034C8
// RVA : 0x00D034C8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idTownGarageCamera::NextTarget(idTownGarageCamera *this)
{
  idTownGarageManager *garageManager; // r3

  garageManager = this->garageManager;
  if ( garageManager != nullptr )
    return idTownGarageManager::GotoNextTarget(this: garageManager);
  else
    return 0;
}


// ========================================================================
// ?GetCurrentKey@idTownGarageCamera@@QBAPAVidVehicleKey@@XZ
// EA  : 0x82D034E0
// RVA : 0x00D034E0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idVehicleKey *__fastcall idTownGarageCamera::GetCurrentKey(idTownGarageCamera *this)
{
  idTownGarageManager *garageManager; // r3

  garageManager = this->garageManager;
  if ( garageManager != nullptr )
    return idTownGarageManager::GetCurrentKey(this: garageManager);
  else
    return nullptr;
}


// ========================================================================
// ?HandleGuiEvent@idCinematicCamera@@UAA_NPBUsysEvent_t@@@Z
// EA  : 0x82D034F8
// RVA : 0x00D034F8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idCinematicCamera::HandleGuiEvent(idCinematicCamera *this, const sysEvent_t *event)
{
  idSWF *gui; // r3

  gui = this->gui;
  if ( gui != nullptr )
    return idSWF::HandleEvent(this: gui, event);
  else
    return 0;
}


// ========================================================================
// ?HandleGuiEvent@idSlowMotionCamera@@MAA_NPBUsysEvent_t@@@Z
// EA  : 0x82D03510
// RVA : 0x00D03510
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idSlowMotionCamera::HandleGuiEvent(idSlowMotionCamera *this, const sysEvent_t *event)
{
  idSWF *gui; // r3

  gui = this->gui;
  if ( gui != nullptr )
    return idSWF::HandleEvent(this: gui, event);
  else
    return 0;
}


// ========================================================================
// ?HandleGuiEvent@idRaceCamera@@UAA_NPBUsysEvent_t@@@Z
// EA  : 0x82D03528
// RVA : 0x00D03528
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idRaceCamera::HandleGuiEvent(idRaceCamera *this, const sysEvent_t *event)
{
  idSWF *gui; // r3

  gui = this->gui;
  if ( gui != nullptr )
    idSWF::HandleEvent(this: gui, event);
  return 0;
}


// ========================================================================
// ?Interpolate@idPresentableAnimatedEntity@@UAAXHM@Z
// EA  : 0x82D03558
// RVA : 0x00D03558
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// attributes: thunk
void __fastcall idPresentableAnimatedEntity::Interpolate(
        idPresentableAnimatedEntity *this,
        int curTime,
        double fraction)
{
  idPresentable::Interpolate(this, curTime, fraction);
}


// ========================================================================
// ?GetCurTransform@idInteractionCamera@@QBAMAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82D035B8
// RVA : 0x00D035B8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idInteractionCamera::GetCurTransform(idInteractionCamera *this, idVec3 *pos, idMat3 *axis)
{
  int v6; // r3
  int startTime; // r8 OVERLAPPED
  __int64 v8; // r10 OVERLAPPED
  int lerpTime; // r11
  double x; // fp0
  double y; // fp13
  double z; // fp9
  double v13; // fp31
  double v14; // fp10
  double v15; // fp8
  const idQuat *v16; // r31
  const idQuat *v17; // r3
  idMat3 *v18; // r3
  double v19; // fp1
  idMat3 v21; // [sp+50h] [-E0h] BYREF
  idQuat v22[3]; // [sp+80h] [-B0h] BYREF
  idQuat v23[3]; // [sp+B0h] [-80h] BYREF
  idQuat v24; // [sp+E0h] [-50h] BYREF

  v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  startTime = this->startTime;
  LODWORD(v8) = this->lerpTime;
  lerpTime = v6 - startTime;
  if ( v6 - startTime >= 0 )
  {
    if ( lerpTime > (int)v8 )
      lerpTime = this->lerpTime;
  }
  else
  {
    lerpTime = 0;
  }
  x = this->startPos.x;
  HIDWORD(v8) = lerpTime;
  y = this->startPos.y;
  *(_QWORD *)&v21.mat[0].x = *(__int64 *)((char *)&v8 + 4);
  z = this->startPos.z;
  v13 = (float)((float)*(__int64 *)((char *)&v8 + 4) / (float)v8);
  v14 = (float)((float)(this->destPos.y - (float)y) * (float)((float)*(__int64 *)((char *)&v8 + 4) / (float)v8));
  v15 = (float)((float)(this->destPos.z - this->startPos.z) * (float)((float)*(__int64 *)((char *)&v8 + 4) / (float)v8));
  pos->x = (float)x
         + (float)((float)(this->destPos.x - (float)x) * (float)((float)*(__int64 *)((char *)&v8 + 4) / (float)v8));
  pos->y = (float)y + (float)v14;
  pos->z = (float)z + (float)v15;
  idAngles::ToMat3(this: (idAngles *)v23, result: (idMat3 *)&this->startAngles);
  idAngles::ToMat3(this: (idAngles *)v22, result: (idMat3 *)&this->destAngles);
  v16 = idMat3::ToQuat(this: &v21, result: v22);
  v17 = idMat3::ToQuat(this: (idMat3 *)&v21.mat[2].z, result: v23);
  v18 = (idMat3 *)idQuat::Lerp(this: (idQuat *)&v21.mat[1].y, from: v17, to: v16, t: v13);
  *axis = *idQuat::ToMat3(this: &v24, result: v18);
  v19 = v13;
  return *((float *)&v19 + 1);
}


// ========================================================================
// ?GetAimPoint@idInteractionCamera@@UBAXW4aimPoint_t@@AAVidVec3@@@Z
// EA  : 0x82D03738
// RVA : 0x00D03738
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idInteractionCamera::GetAimPoint(idInteractionCamera *this, const aimPoint_t type, idVec3 *pos)
{
  idMat3 v3; // [sp+50h] [-30h] BYREF

  idInteractionCamera::GetCurTransform(this, pos, axis: &v3);
}


// ========================================================================
// ?HandleUserCmds@idUtilityCamera@@UAAXABVusercmd_t@@0@Z
// EA  : 0x82D03760
// RVA : 0x00D03760
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idUtilityCamera::HandleUserCmds(
        idUtilityCamera *this,
        const usercmd_t *prevcmd,
        const usercmd_t *usercmd)
{
  __int64 v3; // r10
  __int64 v4; // r4
  double v5; // fp11
  double v6; // fp0
  double v7; // fp10
  double v8; // fp13
  double v9; // fp12
  int v10; // r3
  int forwardmove; // r11
  double v12; // fp0
  int v13; // r3
  int v14; // r3
  double v15; // fp0
  double valueFloat; // fp13
  int v17; // r3

  HIDWORD(v3) = prevcmd->angles[0];
  v5 = *(float *)(HIDWORD(v4) + 836);
  v6 = idMath::M_DEG2RAD;
  v7 = *(float *)(HIDWORD(v4) + 840);
  LODWORD(v4) = usercmd->angles[1] - prevcmd->angles[1];
  LODWORD(v3) = usercmd->angles[0] - HIDWORD(v3);
  *(float *)(HIDWORD(v4) + 844) = *(float *)(HIDWORD(v4) + 844);
  v8 = 85.0;
  v9 = (float)((float)((float)((float)v3 * (float)-1.0) * (float)v6) + (float)v5);
  *(float *)(HIDWORD(v4) + 836) = (float)((float)((float)v3 * (float)-1.0) * (float)v6) + (float)v5;
  *(float *)(HIDWORD(v4) + 840) = (float)v7 + (float)((float)v4 * (float)v6);
  if ( v9 > 85.0 || (v8 = -85.0, v9 < -85.0) )
    *(float *)(v10 + 836) = v8;
  forwardmove = usercmd->forwardmove;
  if ( forwardmove > 0 )
  {
    v12 = 0.89999998;
LABEL_8:
    *(float *)(v13 + 820) = *(float *)(v13 + 820) * (float)v12;
    goto LABEL_9;
  }
  if ( forwardmove < 0 )
  {
    v12 = 1.1;
    goto LABEL_8;
  }
LABEL_9:
  v15 = *(float *)(v14 + 820);
  valueFloat = cam_maxDist.valueFloat;
  if ( v15 > cam_maxDist.valueFloat || (valueFloat = 8.0, v15 < 8.0) )
    *(float *)(v17 + 820) = valueFloat;
}


// ========================================================================
// ?HandleUserCmds@idRotatableCamera@@UAAXABVusercmd_t@@0@Z
// EA  : 0x82D03878
// RVA : 0x00D03878
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idRotatableCamera::HandleUserCmds(
        idRotatableCamera *this,
        const usercmd_t *prevcmd,
        const usercmd_t *usercmd)
{
  __int64 v4; // r9
  __int64 v5; // r7
  double v6; // fp0
  double v7; // fp13
  int v8; // r10
  double v9; // fp9
  idAngles *p_currentUserAngles; // r30
  long double v11; // fp4
  long double v12; // fp2
  double x; // fp26
  double z; // fp27
  double pitch; // fp0
  double v16; // fp29
  double yaw; // fp31
  long double v18; // fp2
  double v19; // fp13
  double v20; // fp31
  long double v21; // fp2
  double v22; // fp30
  long double v23; // fp2
  double v24; // fp29
  long double v25; // fp2
  long double v26; // fp2
  double v27; // fp0
  double v28; // fp31
  long double v29; // fp2
  double v30; // fp0
  double v31; // fp31
  long double v32; // fp2
  double v33; // fp31
  long double v34; // fp2
  char *v35; // r10
  float *p_y; // r11
  int i; // ctr
  float *v38; // r3
  idVec3 v39; // [sp+50h] [-C0h] BYREF
  idMat3 v40; // [sp+60h] [-B0h] BYREF
  float v41; // [sp+84h] [-8Ch]
  float v42; // [sp+88h] [-88h]
  float v43; // [sp+8Ch] [-84h]
  float v44; // [sp+90h] [-80h]
  char v45; // [sp+9Ch] [-74h] BYREF
  idMat3 v46[2]; // [sp+A0h] [-70h] BYREF

  HIDWORD(v5) = usercmd->angles[1];
  LODWORD(v4) = HIDWORD(v5) - prevcmd->angles[1];
  HIDWORD(v4) = usercmd->angles[0] - prevcmd->angles[0];
  LODWORD(v5) = HIDWORD(v4);
  *(_QWORD *)&v39.x = v5;
  v6 = (float)((float)v5 * (float)0.003);
  v7 = (float)((float)v4 * (float)0.003);
  if ( v6 > -10.0 && v6 < 10.0 && v7 > -10.0 && v7 < 10.0 )
  {
    v8 = *((_BYTE *)this + 1028) & 0x10;
    v9 = (float)(this->currentUserAngles.yaw + (float)((float)v4 * (float)0.003));
    this->currentUserAngles.pitch = this->currentUserAngles.pitch + (float)((float)v5 * (float)0.003);
    this->currentUserAngles.yaw = v9;
    if ( v8 != 0 )
    {
      p_currentUserAngles = &this->currentUserAngles;
      idAngles::ToMat3(this: (idAngles *)&v40.mat[1].y, result: (idMat3 *)&this->currentUserAngles);
      *(double *)&v12 = v40.mat[2].x;
      *((double *)&v12 + 1) = v40.mat[1].z;
      x = v40.mat[2].x;
      z = v40.mat[1].z;
      if ( v40.mat[2].x != 0.0 || *((double *)&v12 + 1) != 0.0 )
      {
        if ( *(double *)&v12 >= 0.0 )
          pitch = this->clampedMinAngles.pitch;
        else
          pitch = this->clampedMaxAngles.pitch;
        v16 = __fabs(pitch);
        if ( *((double *)&v12 + 1) >= 0.0 )
          yaw = this->clampedMaxAngles.yaw;
        else
          yaw = this->clampedMinAngles.yaw;
        v18 = atan2(v: v12, u: v11);
        v19 = __fabs(yaw);
        v20 = (float)*(double *)&v18;
        *(double *)&v18 = (float)((float)v19 * idMath::M_DEG2RAD);
        v21 = sin(x: v18);
        v22 = (float)*(double *)&v21;
        *(double *)&v21 = (float)(idMath::M_DEG2RAD * (float)v16);
        v23 = sin(x: v21);
        v24 = (float)*(double *)&v23;
        if ( __fabs(v20) == idMath::HALF_PI )
          v20 = (float)((float)v20 - (float)0.000099999997);
        *(double *)&v23 = v20;
        v25 = tan(x: v23);
        *(double *)&v25 = (float)((float)((float)v22 / (float)v24) * (float)*(double *)&v25);
        v26 = atan(x: v25);
        v27 = (float)*(double *)&v26;
        if ( z < 0.0 )
        {
          if ( x >= 0.0 )
            v27 = (float)((float)3.1415927 + (float)*(double *)&v26);
          else
            v27 = (float)((float)*(double *)&v26 - (float)3.1415927);
        }
        v28 = v27;
        *(double *)&v26 = v27;
        v29 = cos(x: v26);
        v30 = (float)*(double *)&v29;
        *(double *)&v29 = v28;
        v31 = (float)((float)v30 * (float)v22);
        v32 = sin(x: v29);
        *(double *)&v32 = __fsqrts((float)((float)((float)((float)*(double *)&v32 * (float)v24)
                                                 * (float)((float)*(double *)&v32 * (float)v24))
                                         + (float)((float)v31 * (float)v31)));
        v33 = idMath::ASin(a: v32);
        *(double *)&v34 = v40.mat[1].y;
        if ( idMath::ACos(a: v34) > v33 )
        {
          v39.y = (float)(v40.mat[1].y * mat3_identity.mat[0].z) - (float)(v40.mat[2].x * mat3_identity.mat[0].x);
          v39.x = (float)(v40.mat[2].x * mat3_identity.mat[0].y) - (float)(v40.mat[1].z * mat3_identity.mat[0].z);
          v39.z = (float)(v40.mat[1].z * mat3_identity.mat[0].x) - (float)(v40.mat[1].y * mat3_identity.mat[0].y);
          idVec3::NormalizeFast(this: &v39);
          v35 = &v45;
          p_y = &mat2_identity.mat[1].y;
          for ( i = 9; i != 0; --i )
          {
            ++p_y;
            v35 += 4;
            *(float *)v35 = *p_y;
          }
          v38 = (float *)idMat3::RotateSelf(this: v46, axis: &v39, angle: v33);
          v40.mat[1].y = *v38;
          v40.mat[1].z = v38[1];
          v40.mat[2].x = v38[2];
          v40.mat[2].y = v38[3];
          v40.mat[2].z = v38[4];
          v41 = v38[5];
          v42 = v38[6];
          v43 = v38[7];
          v44 = v38[8];
          v41 = 0.0;
          idVec3::NormalizeFast(this: (idVec3 *)&v40.mat[2].y);
          v42 = (float)(v41 * v40.mat[1].z) - (float)(v40.mat[2].z * v40.mat[2].x);
          v43 = (float)(v40.mat[2].y * v40.mat[2].x) - (float)(v41 * v40.mat[1].y);
          v44 = (float)(v40.mat[2].z * v40.mat[1].y) - (float)(v40.mat[2].y * v40.mat[1].z);
          *p_currentUserAngles = *idMat3::ToAngles(this: &v40, result: (idAngles *)&v40.mat[1].y);
        }
      }
    }
    else
    {
      idAngles::Clamp(this: &this->currentUserAngles, min: &this->clampedMinAngles, max: &this->clampedMaxAngles);
    }
  }
}


// ========================================================================
// ?Draw@idRotatableCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D03BF0
// RVA : 0x00D03BF0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idRotatableCamera::Draw(idRotatableCamera *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v4; // r31
  char v5; // r30

  presentable = player->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = 0;
  idView::SetViewPos(this: (idView *)(v4 + 16224), origin: &this->cachedViewOrg, axis: &this->cachedViewAxis);
  *(float *)(v4 + 18124) = 0.0;
  *(float *)(v4 + 18128) = 0.0;
  *(float *)(v4 + 18132) = 0.0;
  idView::CalcFOV(this: (idView *)(v4 + 16224), base_fov: g_fov.valueFloat);
  idView::SetViewID(this: (idView *)(v4 + 16224), id: this->entityNumber + 1);
  v5 = *(_BYTE *)(v4 + 19040);
  *(_BYTE *)(v4 + 19040) = 0;
  idView::Render(this: (idView *)(v4 + 16224));
  *(_BYTE *)(v4 + 19040) = v5;
  return 1;
}


// ========================================================================
// ?Draw@idTrailerCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D03C98
// RVA : 0x00D03C98
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idTrailerCamera::Draw(idTrailerCamera *this, idPlayer *player)
{
  int v4; // r29
  idPresentable *presentable; // r3
  idPhysics *Physics; // r3
  float *v7; // r3
  bool v8; // r31
  char v10; // [sp+50h] [-A0h] BYREF
  float v11[6]; // [sp+60h] [-90h] BYREF
  char v12; // [sp+78h] [-78h]
  bool v13; // [sp+79h] [-77h]
  _BYTE v14[112]; // [sp+80h] [-70h] BYREF

  v4 = 0;
  v11[0] = 0.0;
  v12 = 0;
  v11[1] = 1.0;
  v13 = in_invertLook.valueInteger != 0;
  v11[2] = 1.0;
  v11[3] = joy_pitchSpeed.valueFloat;
  v11[4] = joy_yawSpeed.valueFloat;
  v11[5] = m_sensitivity.valueFloat;
  usercmdGen->GetUsercmd(
    this: (idUsercmdGen *)v14,
    result: (usercmd_t *)usercmdGen,
    a3: 1,
    a4: (const inputSettings_t *)v11,
    a5: false,
    a6: 0);
  this->HandleUserCmds(this, a2: &this->prevCmd, a3: (const usercmd_t *)v14);
  this->CalculateViewParms(this);
  memcpy(Dst: &this->prevCmd, Src: v14, Size: sizeof(this->prevCmd));
  presentable = player->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
  idView::SetViewPos(this: (idView *)(v4 + 16224), origin: &this->cachedViewOrg, axis: &this->cachedViewAxis);
  Physics = idEntity::GetPhysics(this);
  v7 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v10, result: (idVec3 *)Physics, a3: 0);
  *(float *)(v4 + 18124) = *v7;
  *(float *)(v4 + 18128) = v7[1];
  *(float *)(v4 + 18132) = v7[2];
  idView::CalcFOV(this: (idView *)(v4 + 16224), base_fov: g_fov.valueFloat);
  idView::SetEnvironmentParm(this: (idView *)(v4 + 16224), parm: rp->depthOfField, val: &this->dof, blendDuration: 0.0);
  idView::SetViewID(this: (idView *)(v4 + 16224), id: this->entityNumber + 1);
  v8 = g_skipViewEffects.valueInteger != 0;
  idCVar::SetBool(this: &g_skipViewEffects, newValue: true, force: true);
  idView::Render(this: (idView *)(v4 + 16224));
  idCVar::SetBool(this: &g_skipViewEffects, newValue: v8, force: true);
  return 1;
}


// ========================================================================
// ?CalculateViewParms@idTrailerCamera@@UAAXXZ
// EA  : 0x82D03E88
// RVA : 0x00D03E88
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idTrailerCamera::CalculateViewParms(idTrailerCamera *this)
{
  double v2; // fp9
  double v3; // fp7
  double v4; // fp6
  double v5; // fp4
  double v6; // fp3
  double v7; // fp1
  double y; // fp24
  double z; // fp23
  double x; // fp22
  float v11; // r9
  float v12; // r8
  idEntity *(__fastcall *GetTargetEntity)(idUtilityCamera *); // r7
  double v14; // fp1
  double v15; // fp31
  double v16; // fp30
  double v17; // fp29
  __int64 v18; // r11
  double v20; // fp3
  double v22; // fp1
  double v23; // fp5
  double v24; // fp3
  __int64 v25; // r9
  double v26; // fp11
  double v27; // fp8
  double v28; // fp5
  double v31; // fp13
  double v32; // fp3
  idVec3 *v33; // r3
  double v34; // fp2
  double v35; // fp1
  double v36; // fp12
  double v37; // fp6
  const idMat3 *v38; // r3
  idPhysics *Physics; // r3
  idPhysics *v40; // r3
  idMat3 v41; // [sp+50h] [-170h] BYREF
  float v42; // [sp+74h] [-14Ch]
  float v43; // [sp+78h] [-148h]
  idVec3 v44; // [sp+80h] [-140h] BYREF
  __int64 v45; // [sp+90h] [-130h]
  idAngles v46; // [sp+98h] [-128h] BYREF
  float v47[6]; // [sp+A8h] [-118h] BYREF
  idRotation v48; // [sp+C0h] [-100h] BYREF
  idVec3 v49[10]; // [sp+110h] [-B0h] BYREF

  this->GetTargetPos(this, a2: (idVec3 *)&v41.mat[1].y);
  this->GetOffset(this, a2: (idVec3 *)v47);
  v41.mat[1].y = v47[0] + v41.mat[1].y;
  v41.mat[1].z = v41.mat[1].z + v47[1];
  v41.mat[2].x = v47[2] + v41.mat[2].x;
  idAngles::ToForward(this: (idAngles *)&v41, result: (idVec3 *)&this->angles);
  idAngles::ToForward(this: &v46, result: (idVec3 *)&this->lastAngles);
  if ( this->numFrames <= 0 )
  {
    y = v41.mat[1].y;
    z = v41.mat[1].z;
    x = v41.mat[2].x;
  }
  else
  {
    v2 = this->lastTargetPos.x;
    v3 = this->lastTargetPos.y;
    v4 = this->lastTargetPos.z;
    v5 = (float)((float)(v41.mat[1].y - this->lastTargetPos.x) * (float)0.1);
    v6 = (float)((float)(v41.mat[1].z - this->lastTargetPos.y) * (float)0.1);
    v7 = (float)((float)(v41.mat[2].x - this->lastTargetPos.z) * (float)0.1);
    v41.mat[0].x = (float)((float)(v41.mat[0].x - v46.pitch) * (float)0.1) + v41.mat[0].x;
    v41.mat[0].y = (float)((float)(v41.mat[0].y - v46.yaw) * (float)0.1) + v41.mat[0].y;
    y = (float)((float)v2 + (float)v5);
    z = (float)((float)v6 + (float)v3);
    x = (float)((float)v7 + (float)v4);
    v41.mat[0].z = (float)((float)(v41.mat[0].z - v46.roll) * (float)0.1) + v41.mat[0].z;
  }
  v11 = this->cachedViewOrg.y;
  v12 = this->cachedViewOrg.z;
  GetTargetEntity = this->GetTargetEntity;
  v41.mat[2].z = this->cachedViewOrg.x;
  v42 = v11;
  v43 = v12;
  if ( (int)GetTargetEntity(this) != 0 )
  {
    v14 = ((double (__fastcall *)(idTrailerCamera *))this->GetDistance)(a1: this);
    v15 = (float)((float)(v41.mat[0].x * (float)v14) + (float)y);
    v16 = (float)((float)(v41.mat[0].y * (float)v14) + (float)z);
    v17 = (float)((float)(v41.mat[0].z * (float)v14) + (float)x);
  }
  else
  {
    HIDWORD(v18) = &off_82230000;
    LODWORD(v18) = this->prevCmd.forwardmove;
    _FP4 = (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0))
                         + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0))
                                 + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v20 = (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0))
                        + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0))
                                + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0))))
                * (float)0.5);
    __asm { fsel      f2, f4, f5, f0 }
    v22 = __frsqrte(_FP2);
    v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0))))
                                                                                                * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22)
                                                * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0)
                                                                        * (float)(v41.mat[0].y * (float)-1.0))
                                                                + (float)((float)((float)(v41.mat[0].x * (float)-1.0)
                                                                                * (float)(v41.mat[0].x * (float)-1.0))
                                                                        + (float)((float)(v41.mat[0].z * (float)-1.0)
                                                                                * (float)(v41.mat[0].z * (float)-1.0))))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v22
                                                                                * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0))
                                                                                                + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0))))
                                                                                        * (float)0.5))
                                                                        * (float)v22)
                                                                - (float)1.5)
                                                * (float)v22))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v22
                                                        * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0)
                                                                                * (float)(v41.mat[0].y * (float)-1.0))
                                                                        + (float)((float)((float)(v41.mat[0].x
                                                                                                * (float)-1.0)
                                                                                        * (float)(v41.mat[0].x
                                                                                                * (float)-1.0))
                                                                                + (float)((float)(v41.mat[0].z
                                                                                                * (float)-1.0)
                                                                                        * (float)(v41.mat[0].z
                                                                                                * (float)-1.0))))
                                                                * (float)0.5))
                                                * (float)v22)
                                        - (float)1.5)
                        * (float)v22));
    v24 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                        * (float)v22)
                                                                                * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0))
                                                                                                + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0))))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5)) * (float)v22)
                                                                                                - (float)1.5)
                                                                                * (float)v22))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0))))
                                                                                                * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22))
                                        * (float)v20)
                                * (float)v23)
                        - (float)1.5);
    v44.x = (float)(v41.mat[0].x * (float)-1.0)
          * (float)((float)v24
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                                  * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5))
                                                                                          * (float)v22)
                                                                                  - (float)1.5)
                                                                  * (float)v22)
                                                          * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0)
                                                                                  * (float)(v41.mat[0].y * (float)-1.0))
                                                                          + (float)((float)((float)(v41.mat[0].x
                                                                                                  * (float)-1.0)
                                                                                          * (float)(v41.mat[0].x
                                                                                                  * (float)-1.0))
                                                                                  + (float)((float)(v41.mat[0].z
                                                                                                  * (float)-1.0)
                                                                                          * (float)(v41.mat[0].z
                                                                                                  * (float)-1.0))))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v22
                                                                                          * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0))))
                                                                                                  * (float)0.5))
                                                                                  * (float)v22)
                                                                          - (float)1.5)
                                                          * (float)v22))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v22
                                                                  * (float)((float)((float)((float)(v41.mat[0].y
                                                                                                  * (float)-1.0)
                                                                                          * (float)(v41.mat[0].y
                                                                                                  * (float)-1.0))
                                                                                  + (float)((float)((float)(v41.mat[0].x * (float)-1.0)
                                                                                                  * (float)(v41.mat[0].x * (float)-1.0))
                                                                                          + (float)((float)(v41.mat[0].z * (float)-1.0)
                                                                                                  * (float)(v41.mat[0].z * (float)-1.0))))
                                                                          * (float)0.5))
                                                          * (float)v22)
                                                  - (float)1.5)
                                  * (float)v22)));
    v44.y = (float)(v41.mat[0].y * (float)-1.0)
          * (float)((float)v24
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                                  * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5))
                                                                                          * (float)v22)
                                                                                  - (float)1.5)
                                                                  * (float)v22)
                                                          * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0)
                                                                                  * (float)(v41.mat[0].y * (float)-1.0))
                                                                          + (float)((float)((float)(v41.mat[0].x
                                                                                                  * (float)-1.0)
                                                                                          * (float)(v41.mat[0].x
                                                                                                  * (float)-1.0))
                                                                                  + (float)((float)(v41.mat[0].z
                                                                                                  * (float)-1.0)
                                                                                          * (float)(v41.mat[0].z
                                                                                                  * (float)-1.0))))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v22
                                                                                          * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0))))
                                                                                                  * (float)0.5))
                                                                                  * (float)v22)
                                                                          - (float)1.5)
                                                          * (float)v22))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v22
                                                                  * (float)((float)((float)((float)(v41.mat[0].y
                                                                                                  * (float)-1.0)
                                                                                          * (float)(v41.mat[0].y
                                                                                                  * (float)-1.0))
                                                                                  + (float)((float)((float)(v41.mat[0].x * (float)-1.0)
                                                                                                  * (float)(v41.mat[0].x * (float)-1.0))
                                                                                          + (float)((float)(v41.mat[0].z * (float)-1.0)
                                                                                                  * (float)(v41.mat[0].z * (float)-1.0))))
                                                                          * (float)0.5))
                                                          * (float)v22)
                                                  - (float)1.5)
                                  * (float)v22)));
    v44.z = (float)(v41.mat[0].z * (float)-1.0)
          * (float)((float)v24
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                                  * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5))
                                                                                          * (float)v22)
                                                                                  - (float)1.5)
                                                                  * (float)v22)
                                                          * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0)
                                                                                  * (float)(v41.mat[0].y * (float)-1.0))
                                                                          + (float)((float)((float)(v41.mat[0].x
                                                                                                  * (float)-1.0)
                                                                                          * (float)(v41.mat[0].x
                                                                                                  * (float)-1.0))
                                                                                  + (float)((float)(v41.mat[0].z
                                                                                                  * (float)-1.0)
                                                                                          * (float)(v41.mat[0].z
                                                                                                  * (float)-1.0))))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v22
                                                                                          * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0))))
                                                                                                  * (float)0.5))
                                                                                  * (float)v22)
                                                                          - (float)1.5)
                                                          * (float)v22))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v22
                                                                  * (float)((float)((float)((float)(v41.mat[0].y
                                                                                                  * (float)-1.0)
                                                                                          * (float)(v41.mat[0].y
                                                                                                  * (float)-1.0))
                                                                                  + (float)((float)((float)(v41.mat[0].x * (float)-1.0)
                                                                                                  * (float)(v41.mat[0].x * (float)-1.0))
                                                                                          + (float)((float)(v41.mat[0].z * (float)-1.0)
                                                                                                  * (float)(v41.mat[0].z * (float)-1.0))))
                                                                          * (float)0.5))
                                                          * (float)v22)
                                                  - (float)1.5)
                                  * (float)v22)));
    if ( (_DWORD)v18 != 0 )
    {
      v15 = (float)((float)((float)((float)((float)((float)(v41.mat[0].x * (float)-1.0)
                                                  * (float)((float)v24
                                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22)
                                                                                                  * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                  * (float)v22))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5))
                                                                                                  * (float)v22)
                                                                                          - (float)1.5)
                                                                          * (float)v22))))
                                          * (float)((float)v18 * (float)0.0078740157))
                                  * (float)16.0)
                          * this->xyzSpeed)
                  + v41.mat[2].z);
      v16 = (float)((float)((float)((float)((float)((float)(v41.mat[0].y * (float)-1.0)
                                                  * (float)((float)v24
                                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22)
                                                                                                  * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                  * (float)v22))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5))
                                                                                                  * (float)v22)
                                                                                          - (float)1.5)
                                                                          * (float)v22))))
                                          * (float)((float)v18 * (float)0.0078740157))
                                  * (float)16.0)
                          * this->xyzSpeed)
                  + v42);
      v17 = (float)((float)((float)((float)((float)((float)(v41.mat[0].z * (float)-1.0)
                                                  * (float)((float)v24
                                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22)
                                                                                                  * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                  * (float)v22))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)(v41.mat[0].y * (float)-1.0) * (float)(v41.mat[0].y * (float)-1.0)) + (float)((float)((float)(v41.mat[0].x * (float)-1.0) * (float)(v41.mat[0].x * (float)-1.0)) + (float)((float)(v41.mat[0].z * (float)-1.0) * (float)(v41.mat[0].z * (float)-1.0)))) * (float)0.5))
                                                                                                  * (float)v22)
                                                                                          - (float)1.5)
                                                                          * (float)v22))))
                                          * (float)((float)v18 * (float)0.0078740157))
                                  * (float)16.0)
                          * this->xyzSpeed)
                  + v43);
      v45 = v18;
    }
    else
    {
      v17 = v43;
      v16 = v42;
      v15 = v41.mat[2].z;
    }
    if ( this->prevCmd.rightmove != 0 )
    {
      idAngles::ToVectors(this: &this->angles, forward: nullptr, right: &v44, up: nullptr);
      LODWORD(v25) = this->prevCmd.rightmove;
      v45 = v25;
      v15 = (float)((float)v15
                  - (float)((float)((float)((float)((float)v25 * (float)0.0078740157) * v44.x) * (float)16.0)
                          * this->xyzSpeed));
      v16 = (float)((float)v16
                  - (float)((float)((float)(v44.y * (float)((float)v25 * (float)0.0078740157)) * (float)16.0)
                          * this->xyzSpeed));
      v17 = (float)((float)v17
                  - (float)((float)((float)(v44.z * (float)((float)v25 * (float)0.0078740157)) * (float)16.0)
                          * this->xyzSpeed));
    }
  }
  this->cachedViewOrg.x = v15;
  this->cachedViewOrg.y = v16;
  this->cachedViewOrg.z = v17;
  this->lastPos.x = v15;
  this->lastPos.y = v16;
  this->lastPos.z = v17;
  this->lastTargetPos.x = y;
  this->lastTargetPos.y = z;
  this->lastTargetPos.z = x;
  this->lastAngles.pitch = this->angles.pitch;
  v26 = (float)(v41.mat[0].y * (float)-1.0);
  this->lastAngles.yaw = this->angles.yaw;
  v27 = (float)(v41.mat[0].x * (float)-1.0);
  v28 = (float)(v41.mat[0].z * (float)-1.0);
  this->lastAngles.roll = this->angles.roll;
  _FP2 = (float)((float)((float)((float)v28 * (float)v28)
                       + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f2, f3, f0 }
  v31 = __frsqrte(_FP1);
  v32 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31
                                                                                      * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26)))
                                                                                              * (float)0.5))
                                                                              * (float)v31)
                                                                      - (float)1.5)
                                                      * (float)v31)
                                              * (float)((float)((float)((float)v28 * (float)v28)
                                                              + (float)((float)((float)v27 * (float)v27)
                                                                      + (float)((float)v26 * (float)v26)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v31
                                                                              * (float)((float)((float)((float)v28 * (float)v28)
                                                                                              + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26)))
                                                                                      * (float)0.5))
                                                                      * (float)v31)
                                                              - (float)1.5)
                                              * (float)v31))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v31
                                                      * (float)((float)((float)((float)v28 * (float)v28)
                                                                      + (float)((float)((float)v27 * (float)v27)
                                                                              + (float)((float)v26 * (float)v26)))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31));
  v41.mat[0].y = (float)v26
               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))) * (float)0.5)) * (float)v31) - (float)1.5) * (float)v31)
                                                                                               * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))) * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))) * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                               * (float)v31))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))) * (float)0.5))
                                                                                               * (float)v31)
                                                                                       - (float)1.5)
                                                                       * (float)v31))
                                                       * (float)((float)((float)((float)v28 * (float)v28)
                                                                       + (float)((float)((float)v27 * (float)v27)
                                                                               + (float)((float)v26 * (float)v26)))
                                                               * (float)0.5))
                                               * (float)v32)
                                       - (float)1.5)
                       * (float)v32);
  v41.mat[0].x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))) * (float)0.5)) * (float)v31) - (float)1.5) * (float)v31)
                                                                                               * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))) * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))) * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                               * (float)v31))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))) * (float)0.5))
                                                                                               * (float)v31)
                                                                                       - (float)1.5)
                                                                       * (float)v31))
                                                       * (float)((float)((float)((float)v28 * (float)v28)
                                                                       + (float)((float)((float)v27 * (float)v27)
                                                                               + (float)((float)v26 * (float)v26)))
                                                               * (float)0.5))
                                               * (float)v32)
                                       - (float)1.5)
                       * (float)v32)
               * (float)v27;
  v41.mat[0].z = (float)v28
               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))) * (float)0.5)) * (float)v31) - (float)1.5) * (float)v31)
                                                                                               * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))) * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))) * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                               * (float)v31))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))) * (float)0.5))
                                                                                               * (float)v31)
                                                                                       - (float)1.5)
                                                                       * (float)v31))
                                                       * (float)((float)((float)((float)v28 * (float)v28)
                                                                       + (float)((float)((float)v27 * (float)v27)
                                                                               + (float)((float)v26 * (float)v26)))
                                                               * (float)0.5))
                                               * (float)v32)
                                       - (float)1.5)
                       * (float)v32);
  v33 = (idVec3 *)idVec3::ToMat3(this: v49, result: &v41);
  this->cachedViewAxis.mat[0] = *v33;
  this->cachedViewAxis.mat[1] = v33[1];
  this->cachedViewAxis.mat[2].x = v33[2].x;
  this->cachedViewAxis.mat[2].y = v33[2].y;
  v34 = v33[2].z;
  v48.axisValid = false;
  this->cachedViewAxis.mat[2].z = v34;
  v35 = this->cachedViewAxis.mat[0].x;
  v48.origin.x = vec3_origin.x;
  v36 = this->cachedViewAxis.mat[0].y;
  v37 = this->cachedViewAxis.mat[0].z;
  v48.vec.x = v35;
  v48.origin.z = vec3_origin.z;
  v48.origin.y = vec3_origin.y;
  v48.vec.y = v36;
  v48.axis.mat[0].x = mat3_identity.mat[0].x;
  v48.angle = this->dutchAngle;
  v48.vec.z = v37;
  v48.axis.mat[0].y = mat3_identity.mat[0].y;
  v48.axis.mat[0].z = mat3_identity.mat[0].z;
  v48.axis.mat[1].x = mat3_identity.mat[1].x;
  v48.axis.mat[1].y = mat3_identity.mat[1].y;
  v48.axis.mat[1].z = mat3_identity.mat[1].z;
  v48.axis.mat[2].x = mat3_identity.mat[2].x;
  v48.axis.mat[2].y = mat3_identity.mat[2].y;
  v48.axis.mat[2].z = mat3_identity.mat[2].z;
  v38 = idRotation::ToMat3(this: &v48);
  idMat3::operator*=(this: &this->cachedViewAxis, a: v38);
  Physics = idEntity::GetPhysics(this);
  Physics->SetOrigin(this: Physics, a2: &this->cachedViewOrg, a3: -1);
  v40 = idEntity::GetPhysics(this);
  v40->SetAxis(this: v40, a2: &this->cachedViewAxis, a3: -1);
  ++this->numFrames;
}


// ========================================================================
// ?HandleUserCmds@idAIDebugCamera@@UAAXABVusercmd_t@@0@Z
// EA  : 0x82D043E8
// RVA : 0x00D043E8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// attributes: thunk
void __fastcall idAIDebugCamera::HandleUserCmds(
        idAIDebugCamera *this,
        const usercmd_t *prevcmd,
        const usercmd_t *usercmd)
{
  idUtilityCamera::HandleUserCmds(this, prevcmd, usercmd);
}


// ========================================================================
// ?Draw@idEntityCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D043F0
// RVA : 0x00D043F0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idEntityCamera::Draw(idAIDebugCamera *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v4; // r30
  idPhysics *Physics; // r3
  float *v6; // r3
  char v8; // [sp+50h] [-30h] BYREF

  presentable = player->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = 0;
  idView::SetViewPos(this: (idView *)(v4 + 16224), origin: &this->cachedViewOrg, axis: &this->cachedViewAxis);
  Physics = idEntity::GetPhysics(this);
  v6 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v8, result: (idVec3 *)Physics, a3: 0);
  *(float *)(v4 + 18124) = *v6;
  *(float *)(v4 + 18128) = v6[1];
  *(float *)(v4 + 18132) = v6[2];
  idView::CalcFOV(this: (idView *)(v4 + 16224), base_fov: g_fov.valueFloat);
  idView::SetViewID(this: (idView *)(v4 + 16224), id: this->entityNumber + 1);
  idView::Render(this: (idView *)(v4 + 16224));
  return 1;
}


// ========================================================================
// ?Draw@idTownGarageCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D044B8
// RVA : 0x00D044B8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idTownGarageCamera::Draw(idTownGarageCamera *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r3
  idView *v6; // r31
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v10; // fp10
  double v11; // fp9
  double v12; // fp8
  double v13; // fp7
  double v14; // fp6
  double v15; // fp5
  double v16; // fp4
  double v17; // fp3
  int v18; // r3
  const char *v19; // r7
  int v20; // r3
  const char *v21; // r7
  int v22; // r3
  const char *v23; // r7
  idVec3 v24; // [sp+50h] [-60h] BYREF
  idMat3 v25; // [sp+60h] [-50h] BYREF

  if ( this->garageManager == nullptr )
    return 0;
  presentable = player->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  v6 = (idView *)(v5 + 16224);
  if ( this->currentState == GARAGECAMERASTATE_CAR )
  {
    y = this->spawnPosition.y;
    z = this->spawnPosition.z;
    x = this->spawnOrientation.mat[0].x;
    v10 = this->spawnOrientation.mat[0].y;
    v11 = this->spawnOrientation.mat[0].z;
    v12 = this->spawnOrientation.mat[1].x;
    v13 = this->spawnOrientation.mat[1].y;
    v14 = this->spawnOrientation.mat[1].z;
    v15 = this->spawnOrientation.mat[2].x;
    v16 = this->spawnOrientation.mat[2].y;
    v17 = this->spawnOrientation.mat[2].z;
    v24.x = this->spawnPosition.x;
    v24.y = y;
    v24.z = z;
    v25.mat[0].x = x;
    v25.mat[0].y = v10;
    v25.mat[0].z = v11;
    v25.mat[1].x = v12;
    v25.mat[1].y = v13;
    v25.mat[1].z = v14;
    v25.mat[2].x = v15;
    v25.mat[2].y = v16;
    v25.mat[2].z = v17;
  }
  idView::SetViewPos(this: (idView *)(v5 + 16224), origin: &v24, axis: &v25);
  v6->viewVelocity = vec3_origin;
  idView::CalcFOV(this: v6, base_fov: this->cameraFov);
  idView::SetViewID(this: v6, id: this->entityNumber + 1);
  v18 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idSWF::Render(this: this->gui, gui: v6->guiModel, time: v18, isSplitscreen: false, a5: v19);
  if ( this->tunerGui != nullptr )
  {
    v20 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idSWF::Render(this: this->tunerGui, gui: v6->guiModel, time: v20, isSplitscreen: false, a5: v21);
  }
  if ( this->tunerVehicleGui != nullptr )
  {
    v22 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idSWF::Render(this: this->tunerVehicleGui, gui: v6->guiModel, time: v22, isSplitscreen: false, a5: v23);
  }
  idView::Render(this: v6);
  return 1;
}


// ========================================================================
// ?GetExitTownImage@idTownGarageCamera@@QAAPBDXZ
// EA  : 0x82D04678
// RVA : 0x00D04678
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

char *__fastcall idTownGarageCamera::GetExitTownImage(idTownGarageCamera *this)
{
  const idMaterial *exitTownImage; // r11

  exitTownImage = this->exitTownImage;
  if ( exitTownImage != nullptr )
    return (char *)exitTownImage->name.str;
  else
    return &byte_8200D768;
}


// ========================================================================
// ?GetVehicleMGAmmo@idTownGarageCamera@@QBAPBVidDeclInventory@@XZ
// EA  : 0x82D04698
// RVA : 0x00D04698
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

const idDeclInventory *__fastcall idTownGarageCamera::GetVehicleMGAmmo(idTownGarageCamera *this)
{
  return this->garageManager->vehicleMGAmmo;
}


// ========================================================================
// ?GetVehicleRocketAmmo@idTownGarageCamera@@QBAPBVidDeclInventory@@XZ
// EA  : 0x82D046A8
// RVA : 0x00D046A8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

const idDeclInventory *__fastcall idTownGarageCamera::GetVehicleRocketAmmo(idTownGarageCamera *this)
{
  return this->garageManager->vehicleRocketAmmo;
}


// ========================================================================
// ?GetVehicleEnergyAmmo@idTownGarageCamera@@QBAPBVidDeclInventory@@XZ
// EA  : 0x82D046B8
// RVA : 0x00D046B8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

const idDeclInventory *__fastcall idTownGarageCamera::GetVehicleEnergyAmmo(idTownGarageCamera *this)
{
  return this->garageManager->vehicleEnergyAmmo;
}


// ========================================================================
// ?DetermineTotalTime@idCinematicCamera@@QAAMXZ
// EA  : 0x82D046C8
// RVA : 0x00D046C8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

float __fastcall idCinematicCamera::DetermineTotalTime(idCinematicCamera *this)
{
  int v1; // r9
  double v2; // fp31
  int v3; // r10
  double transTime; // fp0
  idCinematicCamera::trigger_t *v5; // r11
  double v6; // fp0
  double v7; // fp1

  v1 = 0;
  v2 = 0.0;
  if ( this->triggers.num > 0 )
  {
    v3 = 0;
    do
    {
      transTime = 0.0;
      v5 = &this->triggers.list[v3];
      if ( v5->movement.moveType != CAM_MOVE_NONE )
      {
        if ( v5->movement.moveTime > 0.0 )
        {
          transTime = (float)((float)(v5->movement.easeOutTime + v5->movement.easeInTime) + v5->movement.moveTime);
          v5->movement.totalMoveTime = (float)(v5->movement.easeOutTime + v5->movement.easeInTime)
                                     + v5->movement.moveTime;
        }
        if ( transTime < v5->movement.transTime )
          transTime = v5->movement.transTime;
      }
      if ( v5->focus.focusType != 0 )
      {
        if ( transTime < v5->focus.transTime )
        {
          transTime = (float)((float)(v5->focus.easeOutTime + v5->focus.easeInTime) + v5->focus.transTime);
          v5->focus.totalFocusTime = (float)(v5->focus.easeOutTime + v5->focus.easeInTime) + v5->focus.transTime;
        }
        if ( transTime < v5->focus.splineTime )
          transTime = v5->focus.splineTime;
      }
      if ( transTime < v5->fade.transTime )
        transTime = v5->fade.transTime;
      if ( transTime < v5->fovZoom.transTime )
        transTime = v5->fovZoom.transTime;
      v6 = (float)(v5->time + (float)transTime);
      if ( v2 < v6 )
        v2 = v6;
      ++v1;
      ++v3;
    }
    while ( v1 < this->triggers.num );
  }
  idLib::Printf(fmt: "total time: %f\n", v2);
  v7 = v2;
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?AdjustTiming@idCinematicCamera@@QAAXXZ
// EA  : 0x82D047F8
// RVA : 0x00D047F8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCinematicCamera::AdjustTiming(idCinematicCamera *this, __int64 a2)
{
  __int64 v3; // r8
  int currentTime; // r6
  __int64 v5; // fp9
  double v6; // fp0
  double timeScale; // fp0
  __int64 v8; // r8

  if ( this->current.timeScale.transTime <= 0.0 )
  {
    this->timeScale = this->current.timeScale.scale;
    goto LABEL_10;
  }
  LODWORD(v3) = this->startTime;
  HIDWORD(v3) = this->current.timeScale.startTimeOfs;
  currentTime = this->currentTime;
  v5 = *(__int64 *)((char *)&a2 - 4);
  LODWORD(a2) = HIDWORD(v3);
  v6 = (float)((float)((float)v5 - (float)((float)a2 + (float)v3))
             / (float)(this->current.timeScale.transTime * (float)1000.0));
  if ( v6 >= 0.0 )
  {
    if ( v6 <= 1.0 )
    {
      if ( v6 != 1.0 )
        goto LABEL_8;
    }
    else
    {
      v6 = 1.0;
    }
    this->current.timeScale.transTime = 0.0;
    goto LABEL_8;
  }
  v6 = 0.0;
LABEL_8:
  this->timeScale = (float)((float)(this->current.timeScale.scale - this->previous.timeScale.scale) * (float)v6)
                  + this->previous.timeScale.scale;
LABEL_10:
  timeScale = this->timeScale;
  if ( timeScale < 1.0 || timeScale > 1.0 )
  {
    LODWORD(v8) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    this->startTime += (int)(float)((float)v8 * this->timeScale);
  }
}


// ========================================================================
// ?Trigger_DepthOfField@idCinematicCamera@@QAAXAAUtrigDof_t@1@H@Z
// EA  : 0x82D04950
// RVA : 0x00D04950
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idCinematicCamera::Trigger_DepthOfField(
        idCinematicCamera *this,
        idCinematicCamera::trigDof_t *dof,
        int startTimeOfs)
{
  __int64 v3; // r11
  double blurStart; // fp11

  if ( dof->transTime >= 0.0 )
  {
    LODWORD(v3) = startTimeOfs;
    this->previous.depthOfField = this->current.depthOfField;
    this->current.depthOfField = *dof;
    blurStart = this->current.depthOfField.blurStart;
    this->current.depthOfField.vec.y = this->current.depthOfField.blurScale;
    this->current.depthOfField.vec.x = blurStart;
    this->current.depthOfField.startTimeOfs = (float)v3;
  }
}


// ========================================================================
// ?Trigger_RenderParms@idCinematicCamera@@QAAXAAUtrigRenderParms_t@1@H@Z
// EA  : 0x82D04A10
// RVA : 0x00D04A10
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idCinematicCamera::Trigger_RenderParms(
        idCinematicCamera *this,
        idCinematicCamera::trigRenderParms_t *renderParms,
        int startTimeOfs)
{
  char v3; // r9
  __int64 v4; // r11
  float g; // r7
  float b; // r6

  v3 = 0;
  if ( renderParms->fogScale != -1.0 )
  {
    v3 = 1;
    this->previous.renderParms.fogScale = this->current.renderParms.fogScale;
    this->current.renderParms.fogScale = renderParms->fogScale;
  }
  if ( renderParms->fogColor.r != idColor::colorDefault.r
    || renderParms->fogColor.g != idColor::colorDefault.g
    || renderParms->fogColor.b != idColor::colorDefault.b
    || (BYTE3(v4) = 1, renderParms->fogColor.a != idColor::colorDefault.a) )
  {
    BYTE3(v4) = 0;
  }
  HIDWORD(v4) = BYTE3(v4);
  if ( BYTE3(v4) == 0 )
  {
    g = this->current.renderParms.fogColor.g;
    v3 = 1;
    b = this->current.renderParms.fogColor.b;
    *(float *)&v4 = this->current.renderParms.fogColor.a;
    this->previous.renderParms.fogColor.r = this->current.renderParms.fogColor.r;
    this->previous.renderParms.fogColor.g = g;
    this->previous.renderParms.fogColor.b = b;
    this->previous.renderParms.fogColor.a = *(float *)&v4;
    this->current.renderParms.fogColor = renderParms->fogColor;
  }
  if ( v3 != 0 )
  {
    LODWORD(v4) = startTimeOfs;
    this->current.renderParms.transTime = renderParms->transTime;
    this->current.renderParms.startTimeOfs = (float)v4;
  }
}


// ========================================================================
// ?DetermineTotalTime@idSlowMotionCamera@@IAAMXZ
// EA  : 0x82D04B18
// RVA : 0x00D04B18
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

float __fastcall idSlowMotionCamera::DetermineTotalTime(idSlowMotionCamera *this)
{
  int num; // r6
  int v2; // r7
  double v3; // fp1
  idDeclCameraTrigger::idCameraTriggerParms *list; // r8
  int v5; // r9
  idDeclCameraTrigger::idCameraTriggerParms *v6; // r11
  double duration; // fp0
  double v8; // fp0
  double transTime; // fp0
  double v10; // fp0
  int v11; // r10
  double v12; // fp0
  idDeclCameraTrigger::idCameraTriggerParms *v13; // r11
  double v14; // fp0
  float *v15; // r11
  double v16; // fp0
  double v17; // fp0
  idDeclCameraTrigger::idCameraTriggerParms *v18; // r9
  int v19; // r10
  int v20; // ctr
  idDeclCameraTrigger::idCameraTriggerParms *v21; // r11
  double v22; // fp0
  double v23; // fp0

  num = this->triggers.num;
  v2 = 0;
  v3 = 0.0;
  if ( num >= 4 )
  {
    list = this->triggers.list;
    v5 = 0;
    do
    {
      v6 = &list[v5];
      duration = 0.0;
      if ( list[v5].movement.moveType != CAM_MOVE_NONE && v6->movement.timing.duration > 0.0 )
        duration = v6->movement.timing.duration;
      if ( v6->focus.focusType != CAM_FOCUS_NONE && duration < v6->focus.frameLerp.duration )
        duration = v6->focus.frameLerp.duration;
      if ( duration < v6->timeScale.timing.duration )
        duration = v6->timeScale.timing.duration;
      if ( duration < v6->fade.transTime )
        duration = v6->fade.transTime;
      if ( duration < v6->fovZoom.timing.duration )
        duration = v6->fovZoom.timing.duration;
      v8 = (float)(v6->offsetTime + (float)duration);
      if ( v3 < v8 )
        v3 = v8;
      transTime = 0.0;
      if ( v6[1].movement.moveType != CAM_MOVE_NONE && v6[1].movement.timing.duration > 0.0 )
        transTime = v6[1].movement.timing.duration;
      if ( v6[1].focus.focusType != CAM_FOCUS_NONE && transTime < v6[1].focus.frameLerp.duration )
        transTime = v6[1].focus.frameLerp.duration;
      if ( transTime < v6[1].timeScale.timing.duration )
        transTime = v6[1].timeScale.timing.duration;
      if ( transTime < v6[1].fade.transTime )
        transTime = v6[1].fade.transTime;
      if ( transTime < v6[1].fovZoom.timing.duration )
        transTime = v6[1].fovZoom.timing.duration;
      v10 = (float)(v6[1].offsetTime + (float)transTime);
      if ( v3 < v10 )
        v3 = v10;
      v11 = v5 * 484 + 1452;
      v12 = 0.0;
      v13 = &list[v5 + 3];
      if ( v13[-1].movement.moveType != CAM_MOVE_NONE && v13[-1].movement.timing.duration > 0.0 )
        v12 = v13[-1].movement.timing.duration;
      if ( v13[-1].focus.focusType != CAM_FOCUS_NONE && v12 < v13[-1].focus.frameLerp.duration )
        v12 = v13[-1].focus.frameLerp.duration;
      if ( v12 < v13[-1].timeScale.timing.duration )
        v12 = v13[-1].timeScale.timing.duration;
      if ( v12 < v13[-1].fade.transTime )
        v12 = v13[-1].fade.transTime;
      if ( v12 < v13[-1].fovZoom.timing.duration )
        v12 = v13[-1].fovZoom.timing.duration;
      v14 = (float)(v13[-1].offsetTime + (float)v12);
      if ( v3 < v14 )
        v3 = v14;
      v15 = (float *)((char *)&list->title.len + v11);
      v16 = 0.0;
      if ( *(idDeclCameraTrigger::cam_move_t *)((char *)&list->movement.moveType + v11) != CAM_MOVE_NONE
        && v15[21] > 0.0 )
      {
        v16 = v15[21];
      }
      if ( *((_DWORD *)v15 + 37) != 0 && v16 < v15[52] )
        v16 = v15[52];
      if ( v16 < v15[76] )
        v16 = v15[76];
      if ( v16 < v15[73] )
        v16 = v15[73];
      if ( v16 < v15[83] )
        v16 = v15[83];
      v17 = (float)(v15[8] + (float)v16);
      if ( v3 < v17 )
        v3 = v17;
      v2 += 4;
      v5 += 4;
    }
    while ( v2 < num - 3 );
  }
  if ( v2 < num )
  {
    v18 = this->triggers.list;
    v19 = v2;
    v20 = num - v2;
    do
    {
      v21 = &v18[v19];
      v22 = 0.0;
      if ( v18[v19].movement.moveType != CAM_MOVE_NONE && v21->movement.timing.duration > 0.0 )
        v22 = v21->movement.timing.duration;
      if ( v21->focus.focusType != CAM_FOCUS_NONE && v22 < v21->focus.frameLerp.duration )
        v22 = v21->focus.frameLerp.duration;
      if ( v22 < v21->timeScale.timing.duration )
        v22 = v21->timeScale.timing.duration;
      if ( v22 < v21->fade.transTime )
        v22 = v21->fade.transTime;
      if ( v22 < v21->fovZoom.timing.duration )
        v22 = v21->fovZoom.timing.duration;
      v23 = (float)(v21->offsetTime + (float)v22);
      if ( v3 < v23 )
        v3 = v23;
      ++v19;
      --v20;
    }
    while ( v20 != 0 );
  }
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?GetTimeLerpFraction@idSlowMotionCamera@@IAAMAAVidTimeLerpHelper@idDeclCameraTrigger@@@Z
// EA  : 0x82D04E08
// RVA : 0x00D04E08
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

float __fastcall idSlowMotionCamera::GetTimeLerpFraction(
        idSlowMotionCamera *this,
        __int64 timeLerpHelper,
        long double a3)
{
  double v3; // fp0
  double v4; // fp31
  double v5; // fp12
  double v6; // fp11
  double v7; // fp13
  double v8; // fp1
  double v9; // fp13
  double v10; // fp13
  long double v11; // fp2

  v3 = *(float *)HIDWORD(timeLerpHelper);
  v4 = 1.0;
  if ( v3 <= 0.0 )
  {
LABEL_16:
    v8 = v4;
    return *((float *)&v8 + 1);
  }
  v5 = *(float *)(HIDWORD(timeLerpHelper) + 8);
  v6 = *(float *)(HIDWORD(timeLerpHelper) + 4);
  LODWORD(timeLerpHelper) = this->currentTime - this->startTime - *(_DWORD *)(HIDWORD(timeLerpHelper) + 16);
  v7 = (float)((float)timeLerpHelper * (float)0.001);
  if ( v7 <= v3 )
  {
    if ( *(_BYTE *)(HIDWORD(timeLerpHelper) + 12) != 0 )
    {
      v3 = (float)(*(float *)HIDWORD(timeLerpHelper) * (float)0.5);
      v6 = (float)(*(float *)(HIDWORD(timeLerpHelper) + 4) * (float)0.5);
      v5 = (float)(*(float *)(HIDWORD(timeLerpHelper) + 8) * (float)0.5);
    }
    if ( v7 >= *(float *)(HIDWORD(timeLerpHelper) + 4) )
    {
      if ( v5 == 0.0 || v7 <= (float)((float)v3 - (float)v5) || v7 >= v3 )
      {
        v4 = (float)((float)((float)timeLerpHelper * (float)0.001) / (float)v3);
      }
      else
      {
        v10 = (float)((float)v3 - (float)((float)timeLerpHelper * (float)0.001));
        v4 = (float)((float)((float)-(float)((float)((float)((float)v10 / (float)v5) * (float)((float)v10 / (float)v5))
                                           - (float)1.0)
                           * (float)((float)v5 / (float)v3))
                   + (float)((float)1.0 - (float)((float)v5 / (float)v3)));
      }
    }
    else
    {
      v9 = (float)((float)((float)timeLerpHelper * (float)0.001) / (float)v6);
      v4 = (float)((float)((float)v9 * (float)v9) * (float)((float)v6 / (float)v3));
    }
    if ( *(_BYTE *)(HIDWORD(timeLerpHelper) + 12) != 0 && v4 > 1.0 )
    {
      *(double *)&a3 = v4;
      v11 = floor(x: a3);
      v4 = (float)((float)1.0 - (float)((float)v4 - (float)*(double *)&v11));
    }
    goto LABEL_16;
  }
  v8 = 1.0;
  return *((float *)&v8 + 1);
}


// ========================================================================
// ?Trigger_Sounds@idSlowMotionCamera@@IAAXAAVidTrigSounds@idDeclCameraTrigger@@H@Z
// EA  : 0x82D04F48
// RVA : 0x00D04F48
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idSlowMotionCamera::Trigger_Sounds(
        idSlowMotionCamera *this,
        idDeclCameraTrigger::idTrigSounds *sounds,
        int startTimeOfs)
{
  int num; // r11
  int v6; // r30
  int v7; // r31

  num = sounds->sound.num;
  if ( num != 0 )
  {
    v6 = 0;
    if ( num > 0 )
    {
      v7 = 0;
      do
      {
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_ANY,
          shader: sounds->sound.list[v7],
          soundShaderFlags: (soundShaderFlags_t)0,
          peerMask: 0xFFu);
        ++v6;
        ++v7;
      }
      while ( v6 < sounds->sound.num );
    }
  }
}


// ========================================================================
// ?Trigger_DepthOfField@idSlowMotionCamera@@IAAXAAVidTrigDof@idDeclCameraTrigger@@H@Z
// EA  : 0x82D04FB0
// RVA : 0x00D04FB0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idSlowMotionCamera::Trigger_DepthOfField(
        idSlowMotionCamera *this,
        idDeclCameraTrigger::idTrigDof *dof,
        int startTimeOfs)
{
  idDeclCameraTrigger::idTrigDof *p_depthOfField; // r9
  int v4; // ctr
  float *p_blurScale; // r7
  float *v6; // r11
  float *v7; // r6
  float *v8; // r8
  int v9; // ctr
  double blurScale; // fp10

  if ( dof->timing.duration >= 0.0 )
  {
    p_depthOfField = &this->current.depthOfField;
    this->previous.depthOfField.blurStart = this->current.depthOfField.blurStart;
    this->previous.depthOfField.blurScale = this->current.depthOfField.blurScale;
    v4 = 5;
    p_blurScale = &this->previous.depthOfField.blurScale;
    v6 = &this->current.depthOfField.blurScale;
    do
    {
      *++p_blurScale = *++v6;
      --v4;
    }
    while ( v4 != 0 );
    this->previous.depthOfField.vec = this->current.depthOfField.vec;
    v7 = &dof->blurScale;
    v8 = &this->current.depthOfField.blurScale;
    v9 = 5;
    p_depthOfField->blurStart = dof->blurStart;
    this->current.depthOfField.blurScale = dof->blurScale;
    do
    {
      *++v8 = *++v7;
      --v9;
    }
    while ( v9 != 0 );
    this->current.depthOfField.vec = dof->vec;
    this->current.depthOfField.timing.startTimeOfs = startTimeOfs;
    blurScale = this->current.depthOfField.blurScale;
    this->current.depthOfField.vec.x = p_depthOfField->blurStart;
    this->current.depthOfField.vec.y = blurScale;
  }
}


// ========================================================================
// ?Trigger_RenderParms@idSlowMotionCamera@@IAAXAAVidTrigRenderParms@idDeclCameraTrigger@@H@Z
// EA  : 0x82D05080
// RVA : 0x00D05080
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idSlowMotionCamera::Trigger_RenderParms(
        idSlowMotionCamera *this,
        idDeclCameraTrigger::idTrigRenderParms *renderParms,
        int startTimeOfs)
{
  char v3; // r9
  char v4; // r10
  float g; // r7
  float b; // r6
  float a; // r10
  double duration; // fp0

  v3 = 0;
  if ( renderParms->fogScale != -1.0 )
  {
    v3 = 1;
    this->previous.renderParms.fogScale = this->current.renderParms.fogScale;
    this->current.renderParms.fogScale = renderParms->fogScale;
  }
  if ( renderParms->fogColor.r != idColor::colorDefault.r
    || renderParms->fogColor.g != idColor::colorDefault.g
    || renderParms->fogColor.b != idColor::colorDefault.b
    || (v4 = 1, renderParms->fogColor.a != idColor::colorDefault.a) )
  {
    v4 = 0;
  }
  if ( v4 == 0 )
  {
    g = this->current.renderParms.fogColor.g;
    v3 = 1;
    b = this->current.renderParms.fogColor.b;
    a = this->current.renderParms.fogColor.a;
    this->previous.renderParms.fogColor.r = this->current.renderParms.fogColor.r;
    this->previous.renderParms.fogColor.g = g;
    this->previous.renderParms.fogColor.b = b;
    this->previous.renderParms.fogColor.a = a;
    this->current.renderParms.fogColor = renderParms->fogColor;
  }
  if ( v3 != 0 )
  {
    duration = renderParms->timing.duration;
    this->current.renderParms.timing.startTimeOfs = startTimeOfs;
    this->current.renderParms.timing.duration = duration;
  }
}


// ========================================================================
// ??1idRaceCamera@@UAA@XZ
// EA  : 0x82D05178
// RVA : 0x00D05178
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idRaceCamera::~idRaceCamera(idRaceCamera *this)
{
  idSWF *gui; // r29

  this->__vftable = (idRaceCamera_vtbl *)&idRaceCamera::`vftable';
  gui = this->gui;
  if ( gui != nullptr )
  {
    idSWF::~idSWF(this: this->gui);
    idMem::Free(this: &mem, ptr: gui, align: ALIGN_16);
    this->gui = nullptr;
  }
  this->__vftable = (idRaceCamera_vtbl *)&idCamera::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$500045
// EA  : 0x82D051EC
// RVA : 0x00D051EC
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_500045()
{
  int v0; // r12

  idCameraView::~idCameraView(this: *(idCameraView **)(v0 - 128 + 148));
}


// ========================================================================
// ?Draw_2@idRaceCamera@@QAA_NPAVidPlayer@@@Z
// EA  : 0x82D05218
// RVA : 0x00D05218
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idRaceCamera::Draw_2(idRaceCamera *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r31
  idPhysics *Physics; // r3
  float *v7; // r3
  idPresentable *v8; // r3
  int v9; // r30
  int v10; // r3
  const char *v11; // r7
  char v13; // [sp+50h] [-40h] BYREF

  presentable = player->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  *(_BYTE *)(v5 + 18136) = 1;
  idView::SetViewPos(this: (idView *)(v5 + 16224), origin: &this->cameraPos, axis: &this->cameraAxis);
  Physics = idEntity::GetPhysics(this);
  v7 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v13, result: (idVec3 *)Physics, a3: 0);
  *(float *)(v5 + 18124) = *v7;
  *(float *)(v5 + 18128) = v7[1];
  *(float *)(v5 + 18132) = v7[2];
  idView::SetViewID(this: (idView *)(v5 + 16224), id: player->entityNumber + 1);
  idView::ApplyScreenFade(this: (idView *)(v5 + 16224));
  idView::Render(this: (idView *)(v5 + 16224));
  if ( !gameLocal->MainMenu_IsActive(this: gameLocal) && this->gui != nullptr )
  {
    v8 = player->presentable;
    if ( v8 != nullptr )
      v9 = (int)v8->GetPlayerInterface_2(this: v8);
    else
      v9 = 0;
    v10 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idSWF::Render(this: this->gui, gui: *(idRenderModelGui **)(v9 + 16224), time: v10, isSplitscreen: false, a5: v11);
  }
  return 1;
}


// ========================================================================
// ?Draw_3@idRaceCamera@@QAA_NPAVidPlayer@@@Z
// EA  : 0x82D05368
// RVA : 0x00D05368
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idRaceCamera::Draw_3(idRaceCamera *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r31
  int v6; // r3
  const char *v7; // r7
  idPresentable *v8; // r3
  int v9; // r31
  idPhysics *Physics; // r3
  float *v11; // r3
  char v13; // [sp+50h] [-40h] BYREF

  if ( !gameLocal->MainMenu_IsActive(this: gameLocal) && this->gui != nullptr )
  {
    presentable = player->presentable;
    if ( presentable != nullptr )
      v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = 0;
    v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idSWF::Render(this: this->gui, gui: *(idRenderModelGui **)(v5 + 16224), time: v6, isSplitscreen: false, a5: v7);
  }
  v8 = player->presentable;
  if ( v8 != nullptr )
    v9 = (int)v8->GetPlayerInterface_2(this: v8);
  else
    v9 = 0;
  *(_BYTE *)(v9 + 18136) = 1;
  idView::SetViewPos(this: (idView *)(v9 + 16224), origin: &this->cameraPos, axis: &this->cameraAxis);
  Physics = idEntity::GetPhysics(this);
  v11 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v13, result: (idVec3 *)Physics, a3: 0);
  *(float *)(v9 + 18124) = *v11;
  *(float *)(v9 + 18128) = v11[1];
  *(float *)(v9 + 18132) = v11[2];
  idView::SetViewID(this: (idView *)(v9 + 16224), id: player->entityNumber + 1);
  idView::Render(this: (idView *)(v9 + 16224));
  return 1;
}


// ========================================================================
// ?Draw@idDeathCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D054B0
// RVA : 0x00D054B0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idDeathCamera::Draw(idDeathCamera *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r30
  idPhysics *Physics; // r3
  float *v7; // r3
  char v9; // [sp+50h] [-40h] BYREF

  presentable = player->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  idView::SetViewPos(this: (idView *)(v5 + 16224), origin: &this->cameraPos, axis: &this->camersAxis);
  Physics = idEntity::GetPhysics(this);
  v7 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v9, result: (idVec3 *)Physics, a3: 0);
  *(float *)(v5 + 18124) = *v7;
  *(float *)(v5 + 18128) = v7[1];
  *(float *)(v5 + 18132) = v7[2];
  idView::SetViewID(this: (idView *)(v5 + 16224), id: player->entityNumber + 1);
  idView::ApplyScreenFade(this: (idView *)(v5 + 16224));
  idView::Render(this: (idView *)(v5 + 16224));
  return 1;
}


// ========================================================================
// ?Draw@idReviveCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D05570
// RVA : 0x00D05570
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

BOOL __fastcall idReviveCamera::Draw(idOnlineVehicleDeathCamera *this, idPlayer *player)
{
  idPresentable *presentable; // r31
  idPresentable *v5; // r3
  int v6; // r4

  if ( this->presentable != nullptr )
  {
    presentable = this->presentable;
  }
  else
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v5 = player->presentable;
  if ( v5 != nullptr )
    v6 = (int)v5->GetPlayerInterface_2(this: v5);
  else
    v6 = 0;
  return presentable->Draw(this: presentable, a2: (idPresentablePlayer *)v6);
}


// ========================================================================
// ?Draw@idPresentableReviveCamera@@UAA_NPAVidPresentablePlayer@@@Z
// EA  : 0x82D05668
// RVA : 0x00D05668
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idPresentableReviveCamera::Draw(idPresentableReviveCamera *this, idPresentablePlayer *player)
{
  if ( player == nullptr )
    return 0;
  idPresentablePlayer::DrawGuis(this: player, id: player->entityNumber + 1);
  idView::SetViewPos(this: &player->view, origin: &this->viewOrigin, axis: &this->viewAxis);
  idView::CalcFOV(this: &player->view, base_fov: g_fov.valueFloat);
  idView::SetViewID(this: &player->view, id: player->entityNumber + 1);
  idView::Render(this: &player->view);
  return 1;
}


// ========================================================================
// ?Think@idOnlineVehicleDeathCamera@@UAAXXZ
// EA  : 0x82D056F0
// RVA : 0x00D056F0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idOnlineVehicleDeathCamera::Think(idOnlineVehicleDeathCamera *this)
{
  idPresentable *presentable; // r31
  idPresentable_vtbl *v3; // r30
  int v4; // r3

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v3 = presentable->__vftable;
  v4 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  ((void (__fastcall *)(idPresentable *, int, double))v3->ClientThink)(a1: presentable, a2: v4, a3: 1.0);
}


// ========================================================================
// ?Draw@idOnlineVehicleDeathCameraPresentable@@UAA_NPAVidPresentablePlayer@@@Z
// EA  : 0x82D057E0
// RVA : 0x00D057E0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idOnlineVehicleDeathCameraPresentable::Draw(
        idOnlineVehicleDeathCameraPresentable *this,
        idPresentablePlayer *player)
{
  idView *p_view; // r31

  p_view = &player->view;
  idView::SetViewPos(this: &player->view, origin: &this->viewOrigin, axis: &this->viewAxis);
  idView::CalcFOV(this: p_view, base_fov: vehicle_baseFOV.valueFloat);
  idView::SetViewID(this: p_view, id: this->entityNumber + 1);
  idView::Render(this: p_view);
  return 1;
}


// ========================================================================
// ?Draw@idRCBombDeathCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D05858
// RVA : 0x00D05858
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idRCBombDeathCamera::Draw(idRCBombDeathCamera *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v4; // r31
  idPhysics *Physics; // r3
  float *v6; // r3
  char v8; // [sp+50h] [-30h] BYREF

  presentable = player->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = 0;
  idView::SetViewPos(this: (idView *)(v4 + 16224), origin: &this->cameraPos, angles: &this->cameraAngle);
  Physics = idEntity::GetPhysics(this);
  v6 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v8, result: (idVec3 *)Physics, a3: 0);
  *(float *)(v4 + 18124) = *v6;
  *(float *)(v4 + 18128) = v6[1];
  *(float *)(v4 + 18132) = v6[2];
  idView::SetViewID(this: (idView *)(v4 + 16224), id: this->entityNumber + 1);
  idView::Render(this: (idView *)(v4 + 16224));
  return 1;
}


// ========================================================================
// ?Event_BetweenCameraInit@idCaptureController@@AAA?AVeventVoid@@XZ
// EA  : 0x82D05910
// RVA : 0x00D05910
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idCaptureController *__fastcall idCaptureController::Event_BetweenCameraInit(
        idCaptureController *this,
        idEventReceiver *result)
{
  idList<idEventReceiver *,5> *listeningToList; // r9
  idList<idEventReceiver *,5> *v5; // r11
  int v6; // r10
  idEventReceiver_vtbl *v8; // r10
  int v9; // r11

  if ( HIBYTE(result[73].listenerList) == 0 )
    return this;
  listeningToList = result[69].listeningToList;
  v5 = result[72].listeningToList;
  v6 = (int)&result[72].listenerList->list + 1;
  result[72].listenerList = (idList<idEventReceiver *,5> *)v6;
  if ( (int)v5 < (int)listeningToList )
  {
    if ( v6 >= *(&result[69].listenerList->size + 5 * (_DWORD)v5) )
    {
      result[72].listeningToList = (idList<idEventReceiver *,5> *)((char *)&v5->list + 1);
      result[72].listenerList = nullptr;
    }
  }
  else if ( v6 >= (int)result[68].listenerList )
  {
    v8 = result[67].__vftable;
    v9 = (int)&result[73].GetType + 1;
    result[73].__vftable = (idEventReceiver_vtbl *)v9;
    if ( v9 < (int)v8 )
    {
      result[72].listeningToList = nullptr;
      result[72].listenerList = nullptr;
      goto LABEL_6;
    }
    HIBYTE(result[73].listenerList) = 0;
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_captureFrames", a3: 0, a4: 0);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "vehicle_cam", a3: false, a4: 0);
    idCVar::SetString(this: &com_capturePath, newValue: &byte_8200D768, force: true);
    if ( cine_captureFrames.valueInteger == 0 )
      return this;
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "com_fixedtic", a3: false, a4: 0);
    return this;
  }
  idCVar::SetBool(this: &vai_reset, newValue: true, force: true);
LABEL_6:
  idEventReceiver::PostEventMS(this: result, ev: &EV_NextCamera, time: 250);
  return this;
}


// ========================================================================
// ?Draw@idPresentableSpectatorCamera@@UAA_NPAVidPresentablePlayer@@@Z
// EA  : 0x82D05B00
// RVA : 0x00D05B00
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idPresentableSpectatorCamera::Draw(idPresentableSpectatorCamera *this, idPresentablePlayer *player)
{
  idView *p_view; // r29
  int entityNumber; // r11

  p_view = &player->view;
  idView::SetViewPos(this: &player->view, origin: &this->viewOrigin, angles: &this->viewAngles);
  if ( pm_thirdPerson.valueInteger != 0 || player->IsDead(this: player) && (*((_BYTE *)player + 47033) & 0x20) != 0 )
    entityNumber = this->entityNumber;
  else
    entityNumber = player->entityNumber;
  idView::SetViewID(this: p_view, id: entityNumber + 1);
  idView::Render(this: p_view);
  return 1;
}


// ========================================================================
// ?HandleUserCmds@idFreeCamera@@QAAXABVusercmd_t@@@Z
// EA  : 0x82D05BA0
// RVA : 0x00D05BA0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idFreeCamera::HandleUserCmds(
        idFreeCamera *this,
        const usercmd_t *usercmd,
        int a3,
        int a4,
        int a5,
        __int64 a6)
{
  double pitch; // fp12
  __int64 v9; // r6
  double yaw; // fp11
  double v11; // fp0
  int v12; // r11
  int v13; // r7
  double v14; // fp13
  idMat3 *p_curAngles; // r4
  double v16; // fp1
  double v17; // fp0
  int forwardmove; // r11
  double v19; // fp4
  double v20; // fp3
  double v21; // fp2
  int rightmove; // r11
  double v23; // fp4
  double v24; // fp3
  double v25; // fp2
  int upmove; // r11
  double v27; // fp4
  double v28; // fp3
  double v29; // fp2
  idAngles v30; // [sp+60h] [-40h] BYREF
  float v31; // [sp+6Ch] [-34h]
  float v32; // [sp+70h] [-30h]
  float v33; // [sp+74h] [-2Ch]
  float v34; // [sp+78h] [-28h]
  float v35; // [sp+7Ch] [-24h]
  float v36; // [sp+80h] [-20h]

  if ( this->bFirstActive )
  {
    this->bFirstActive = false;
    memcpy(Dst: &this->prevcmd, Src: usercmd, Size: sizeof(this->prevcmd));
  }
  pitch = this->curAngles.pitch;
  HIDWORD(v9) = usercmd->angles[1];
  yaw = this->curAngles.yaw;
  v11 = idMath::M_DEG2RAD;
  v12 = HIDWORD(v9) - this->prevcmd.angles[1];
  v13 = usercmd->angles[0] - this->prevcmd.angles[0];
  this->curAngles.roll = this->curAngles.roll;
  LODWORD(a6) = v12;
  LODWORD(v9) = v13;
  v14 = 85.0;
  p_curAngles = (idMat3 *)&this->curAngles;
  this->curAngles.yaw = (float)((float)a6 * (float)v11) + (float)yaw;
  v16 = (float)((float)pitch + (float)((float)v9 * (float)v11));
  this->curAngles.pitch = (float)pitch + (float)((float)v9 * (float)v11);
  if ( v16 > 85.0 || (v14 = -85.0, v16 < -85.0) )
    p_curAngles->mat[0].x = v14;
  idAngles::ToMat3(this: &v30, result: p_curAngles);
  if ( (usercmd->buttons & 0x10) != 0 )
    v17 = 10.0;
  else
    v17 = 2.0;
  forwardmove = usercmd->forwardmove;
  if ( forwardmove <= 0 )
  {
    if ( forwardmove >= 0 )
      goto LABEL_14;
    v19 = (float)(this->curPos.x - (float)(v30.pitch * (float)v17));
    v20 = (float)(this->curPos.y - (float)(v30.yaw * (float)v17));
    v21 = (float)(this->curPos.z - (float)(v30.roll * (float)v17));
  }
  else
  {
    v19 = (float)(this->curPos.x + (float)(v30.pitch * (float)v17));
    v20 = (float)((float)(v30.yaw * (float)v17) + this->curPos.y);
    v21 = (float)((float)(v30.roll * (float)v17) + this->curPos.z);
  }
  this->curPos.z = v21;
  this->curPos.y = v20;
  this->curPos.x = v19;
LABEL_14:
  rightmove = usercmd->rightmove;
  if ( rightmove <= 0 )
  {
    if ( rightmove >= 0 )
      goto LABEL_19;
    v23 = (float)(this->curPos.x + (float)(v31 * (float)v17));
    v24 = (float)((float)(v32 * (float)v17) + this->curPos.y);
    v25 = (float)((float)(v33 * (float)v17) + this->curPos.z);
  }
  else
  {
    v23 = (float)(this->curPos.x - (float)(v31 * (float)v17));
    v24 = (float)(this->curPos.y - (float)(v32 * (float)v17));
    v25 = (float)(this->curPos.z - (float)(v33 * (float)v17));
  }
  this->curPos.z = v25;
  this->curPos.y = v24;
  this->curPos.x = v23;
LABEL_19:
  upmove = usercmd->upmove;
  if ( upmove > 0 )
  {
    v27 = (float)(this->curPos.x + (float)(v34 * (float)v17));
    v28 = (float)((float)(v35 * (float)v17) + this->curPos.y);
    v29 = (float)((float)(v36 * (float)v17) + this->curPos.z);
LABEL_23:
    this->curPos.z = v29;
    this->curPos.y = v28;
    this->curPos.x = v27;
    goto LABEL_24;
  }
  if ( upmove < 0 )
  {
    v27 = (float)(this->curPos.x - (float)(v34 * (float)v17));
    v28 = (float)(this->curPos.y - (float)(v35 * (float)v17));
    v29 = (float)(this->curPos.z - (float)(v36 * (float)v17));
    goto LABEL_23;
  }
LABEL_24:
  memcpy(Dst: &this->prevcmd, Src: usercmd, Size: sizeof(this->prevcmd));
}


// ========================================================================
// ?Draw@idFreeCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D05E78
// RVA : 0x00D05E78
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idFreeCamera::Draw(idFreeCamera *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r11
  idView *v6; // r31
  idPhysics *Physics; // r3
  float *v8; // r3
  int entityNumber; // r11
  char v11; // [sp+50h] [-60h] BYREF
  idMat3 v12[2]; // [sp+60h] [-50h] BYREF

  presentable = player->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  v6 = (idView *)(v5 + 16224);
  idAngles::ToMat3(this: (idAngles *)v12, result: (idMat3 *)&this->curAngles);
  idView::SetViewPos(this: v6, origin: &this->curPos, axis: v12);
  Physics = idEntity::GetPhysics(this);
  v8 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v11, result: (idVec3 *)Physics, a3: 0);
  v6->viewVelocity.x = *v8;
  v6->viewVelocity.y = v8[1];
  v6->viewVelocity.z = v8[2];
  if ( pm_thirdPerson.valueInteger != 0 || player->IsDead(this: player) && idPlayer::GetShowDeadBody(this: player) )
    entityNumber = this->entityNumber;
  else
    entityNumber = player->entityNumber;
  idView::SetViewID(this: v6, id: entityNumber + 1);
  idView::Render(this: v6);
  return 1;
}


// ========================================================================
// ?IsPlayerActivator@idCamera@@QBA_NXZ
// EA  : 0x82D06030
// RVA : 0x00D06030
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idCamera::IsPlayerActivator(idCamera *this)
{
  int value; // r10
  idEntity *v2; // r3
  idEntity *v3; // r3

  value = this->activator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return idPlayer::IsTypeOf(c: nullptr);
  v2 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v2 == nullptr )
    return idPlayer::IsTypeOf(c: nullptr);
  v3 = idEntity::CastTo(c: v2);
  return idPlayer::IsTypeOf(c: v3);
}


// ========================================================================
// ?GetPlayerActivator@idCamera@@QBAPAVidPlayer@@XZ
// EA  : 0x82D060A8
// RVA : 0x00D060A8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idPlayer *__fastcall idCamera::GetPlayerActivator(idCamera *this)
{
  int value; // r10
  idEntity *v2; // r3
  idPlayer *v3; // r3

  value = this->activator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return idPlayer::CastTo(c: nullptr);
  v2 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v2 == nullptr )
    return idPlayer::CastTo(c: nullptr);
  v3 = (idPlayer *)idEntity::CastTo(c: v2);
  return idPlayer::CastTo(c: v3);
}


// ========================================================================
// ?GetViewPos@idCameraView@@QAAXAAVidVec3@@AAVidAngles@@@Z
// EA  : 0x82D06120
// RVA : 0x00D06120
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idCameraView::GetViewPos(idCameraView *this, idVec3 *org, idAngles *angles)
{
  idPhysics *Physics; // r3
  float *v7; // r3
  idEntityPtr<idEntity> *p_target; // r29
  idGameLocal *v9; // r11
  idEntity *v10; // r3
  idPhysics *v11; // r3
  float *v12; // r3
  float v13; // r5
  float v14; // r7
  double y; // fp12
  double orbitRadius; // fp31
  idVec3 *v17; // r3
  double v18; // fp9
  double z; // fp8
  double v20; // fp3
  double v21; // fp2
  idEntity *v22; // r3
  idEntity *v23; // r3
  idPhysics *v24; // r3
  float *v25; // r3
  double v26; // fp9
  double v27; // fp7
  idPhysics *v28; // r3
  idAngles *v29; // r3
  idMat3 v30; // [sp+50h] [-70h] BYREF
  float v31; // [sp+74h] [-4Ch]
  float v32; // [sp+78h] [-48h]

  Physics = idEntity::GetPhysics(this);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  org->x = *v7;
  p_target = &this->target;
  org->y = v7[1];
  v9 = gameLocal;
  org->z = v7[2];
  if ( v9->spawnIds.ptr[this->target.spawnId.value & 0x1FFF] != this->target.spawnId.value >> 13
    || this->usePhysicsToGetAngles )
  {
    v28 = idEntity::GetPhysics(this);
    v29 = (idAngles *)v28->GetAxis(this: v28, a2: 0);
    *angles = *idMat3::ToAngles(this: &v30, result: v29);
  }
  else
  {
    if ( this->orbit )
    {
      v30.mat[1].z = this->currentAngle;
      v30.mat[1].y = 0.0;
      v30.mat[2].x = 0.0;
      v10 = idEntityPtr<idEntity const>::operator->(this: &this->target);
      v11 = idEntity::GetPhysics(this: v10);
      v12 = (float *)v11->GetOrigin(this: v11, a2: 0);
      v13 = v12[2];
      v14 = *v12;
      v30.mat[0].y = v12[1];
      y = v30.mat[0].y;
      v30.mat[0].z = v13;
      v30.mat[0].x = v14;
      org->x = v14;
      org->z = v13;
      org->y = y;
      orbitRadius = this->orbitRadius;
      v17 = idAngles::ToForward(this: (idAngles *)&v30, result: (idVec3 *)&v30.mat[1].y);
      v18 = org->y;
      z = org->z;
      v20 = (float)(v17->y * (float)orbitRadius);
      v21 = (float)(v17->z * (float)orbitRadius);
      org->x = org->x + (float)((float)orbitRadius * v17->x);
      org->y = (float)v18 + (float)v20;
      org->z = (float)z + (float)v21;
      idAngles::Normalize360(this: (idAngles *)&v30.mat[1].y);
      this->currentAngle = this->orbitAdjust + this->currentAngle;
      v9 = gameLocal;
    }
    if ( v9->spawnIds.ptr[p_target->spawnId.value & 0x1FFF] == p_target->spawnId.value >> 13
      && (v22 = v9->entities.ptr[p_target->spawnId.value & 0x1FFF]) != nullptr )
    {
      v23 = idEntity::CastTo(c: v22);
    }
    else
    {
      v23 = nullptr;
    }
    v24 = idEntity::GetPhysics(this: v23);
    v25 = (float *)v24->GetOrigin(this: v24, a2: 0);
    v26 = (float)(v25[2] - org->z);
    v27 = (float)(v25[1] - org->y);
    v30.mat[2].z = *v25 - org->x;
    v32 = v26;
    v31 = v27;
    *angles = *idVec3::ToAngles(this: v30.mat, result: (idAngles *)&v30.mat[2].z);
  }
}


// ========================================================================
// ?InternalDeactivate@idCameraView@@UAA_NXZ
// EA  : 0x82D06390
// RVA : 0x00D06390
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idCameraView::InternalDeactivate(idCameraView *this)
{
  idPlayer *PlayerActivator; // r3
  idPresentable *presentable; // r3
  int v4; // r3
  idVec4 v6; // [sp+50h] [-20h] BYREF

  PlayerActivator = idCamera::GetPlayerActivator(this);
  if ( PlayerActivator != nullptr && this->forcePlayerNoFade )
  {
    v6.x = 0.0;
    v6.y = 0.0;
    v6.z = 0.0;
    v6.w = 0.0;
    presentable = PlayerActivator->presentable;
    if ( presentable != nullptr )
      v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v4 = 0;
    idView::Fade(this: (idView *)(v4 + 16224), color: &v6, time: 0);
  }
  idEntity::BecomeInactive(this, flags: 1);
  return 1;
}


// ========================================================================
// ?FadeIn@idCameraView@@IAAXVidColor@@H@Z
// EA  : 0x82D06430
// RVA : 0x00D06430
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCameraView::FadeIn(
        idCameraView *this,
        __int64 timeMs,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  idPlayer *PlayerActivator; // r3
  idPlayer *v15; // r31
  idPresentable *presentable; // r3
  int v17; // r3
  idPresentable *v18; // r3
  int v19; // r3

  a11 = *(__int64 *)((char *)&timeMs + 4);
  a12 = timeMs;
  PlayerActivator = idCamera::GetPlayerActivator(this);
  v15 = PlayerActivator;
  if ( PlayerActivator != nullptr )
  {
    presentable = PlayerActivator->presentable;
    if ( presentable != nullptr )
      v17 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v17 = 0;
    *(_QWORD *)(v17 + 19068) = a11;
    *(_QWORD *)(v17 + 19076) = a12;
    *((float *)&a12 + 1) = 0.0;
    v18 = v15->presentable;
    if ( v18 != nullptr )
      v19 = (int)v18->GetPlayerInterface_2(this: v18);
    else
      v19 = 0;
    idView::Fade(this: (idView *)(v19 + 16224), color: (const idVec4 *)&a11, time: a3);
    this->fading = false;
  }
}


// ========================================================================
// ?FadeOut@idCameraView@@IAAXVidColor@@H@Z
// EA  : 0x82D064F0
// RVA : 0x00D064F0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCameraView::FadeOut(
        idCameraView *this,
        __int64 timeMs,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  idPlayer *PlayerActivator; // r3
  idPlayer *v15; // r31
  idPresentable *presentable; // r3
  int v17; // r3
  idPresentable *v18; // r3
  int v19; // r3

  a11 = *(__int64 *)((char *)&timeMs + 4);
  a12 = timeMs;
  PlayerActivator = idCamera::GetPlayerActivator(this);
  v15 = PlayerActivator;
  if ( PlayerActivator != nullptr && !this->fading )
  {
    presentable = PlayerActivator->presentable;
    if ( presentable != nullptr )
      v17 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v17 = 0;
    *(_QWORD *)(v17 + 19068) = a11;
    *(_QWORD *)(v17 + 19076) = a12;
    v18 = v15->presentable;
    if ( v18 != nullptr )
      v19 = (int)v18->GetPlayerInterface_2(this: v18);
    else
      v19 = 0;
    idView::Fade(this: (idView *)(v19 + 16224), color: (const idVec4 *)&a11, time: a3);
    this->fading = true;
  }
}


// ========================================================================
// ?Think@idInteractionCamera@@UAAXXZ
// EA  : 0x82D065B0
// RVA : 0x00D065B0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idInteractionCamera::Think(idInteractionCamera *this)
{
  idPlayer *PlayerActivator; // r3
  idPlayer *v3; // r30
  idPresentable *presentable; // r3
  const idPresentablePlayer *v5; // r31
  double CurTransform; // fp1
  BOOL returningToPlayer; // r11
  idPhysics_Player *Physics; // r3
  idVec3 v9; // [sp+50h] [-60h] BYREF
  idMat3 v10[2]; // [sp+60h] [-50h] BYREF

  PlayerActivator = idCamera::GetPlayerActivator(this);
  v3 = PlayerActivator;
  if ( PlayerActivator != nullptr )
  {
    presentable = PlayerActivator->presentable;
    if ( presentable != nullptr )
    {
      v5 = presentable->GetPlayerInterface_2(this: presentable);
      if ( v5 != nullptr )
      {
        CurTransform = idInteractionCamera::GetCurTransform(this, pos: &v9, axis: v10);
        returningToPlayer = this->returningToPlayer;
        this->currentInterpFraction = CurTransform;
        if ( returningToPlayer && CurTransform >= 1.0 )
          idEventReceiver::PostEventMS(this, ev: &EV_ReallyDeactivate, time: 0);
        *(_BYTE *)(idPlayer::GetBobCycle(this: v3) + 216) = 0;
        Physics = (idPhysics_Player *)idEntity::GetPhysics(this: v3);
        idPhysics_Player::ClearCrouch(this: Physics);
        idBobCycle::Update(this: &v5->bobCycle, player: v5);
      }
    }
  }
}


// ========================================================================
// ?HandleGuiEvent@idInteractionCamera@@UAA_NPBUsysEvent_t@@@Z
// EA  : 0x82D06670
// RVA : 0x00D06670
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

BOOL __fastcall idInteractionCamera::HandleGuiEvent(idDeathCamera *this, const sysEvent_t *event)
{
  idPlayer *PlayerActivator; // r3

  PlayerActivator = idCamera::GetPlayerActivator(this);
  return PlayerActivator != nullptr && idPlayer::ReallyHandleGuiEvent(this: PlayerActivator, ev: event);
}


// ========================================================================
// ?CalculateViewParms@idUtilityCamera@@UAAXXZ
// EA  : 0x82D066C8
// RVA : 0x00D066C8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idUtilityCamera::CalculateViewParms(idUtilityCamera *this)
{
  double x; // fp10
  double y; // fp9
  double z; // fp8
  double v5; // fp1
  double v6; // fp7
  double v7; // fp4
  double v8; // fp1
  idEntity *(__fastcall *GetTargetEntity)(idUtilityCamera *); // ctr
  int v10; // r3
  int v11; // r9
  double v12; // fp1
  double v13; // fp31
  double v14; // fp30
  double v15; // fp29
  double v16; // fp7
  double v17; // fp13
  double v18; // fp12
  double v19; // fp8
  double v20; // fp5
  double v21; // fp2
  double v24; // fp6
  double v25; // fp10
  double v26; // fp6
  idPhysics *Physics; // r3
  idPhysics *v28; // r3
  idMat3 v29; // [sp+50h] [-150h] BYREF
  float v30; // [sp+74h] [-12Ch]
  float v31; // [sp+78h] [-128h]
  idVec3 v32; // [sp+80h] [-120h] BYREF
  idAngles v33; // [sp+90h] [-110h] BYREF
  float v34[4]; // [sp+A0h] [-100h] BYREF
  idVec3 v35[4]; // [sp+B0h] [-F0h] BYREF
  trace_t v36; // [sp+E0h] [-C0h] BYREF

  this->GetTargetPos(this, a2: (idVec3 *)&v29.mat[2].z);
  this->GetOffset(this, a2: (idVec3 *)v34);
  v29.mat[2].z = v34[0] + v29.mat[2].z;
  v30 = v34[1] + v30;
  v31 = v34[2] + v31;
  idAngles::ToForward(this: (idAngles *)&v29, result: (idVec3 *)&this->angles);
  idAngles::ToForward(this: &v33, result: (idVec3 *)&this->lastAngles);
  if ( this->numFrames != 0 )
  {
    x = this->lastTargetPos.x;
    y = this->lastTargetPos.y;
    z = this->lastTargetPos.z;
    v5 = (float)((float)(v29.mat[2].z - this->lastTargetPos.x) * (float)0.1);
    v6 = (float)((float)(v30 - this->lastTargetPos.y) * (float)0.1);
    v7 = (float)((float)(v31 - this->lastTargetPos.z) * (float)0.1);
    v29.mat[0].x = (float)((float)(v29.mat[0].x - v33.pitch) * (float)0.1) + v29.mat[0].x;
    v29.mat[0].y = (float)((float)(v29.mat[0].y - v33.yaw) * (float)0.1) + v29.mat[0].y;
    v29.mat[0].z = (float)((float)(v29.mat[0].z - v33.roll) * (float)0.1) + v29.mat[0].z;
    v29.mat[1].y = (float)x + (float)v5;
    v29.mat[1].z = (float)y + (float)v6;
    v29.mat[2].x = (float)z + (float)v7;
  }
  else
  {
    v29.mat[1].y = v29.mat[2].z;
    v29.mat[1].z = v30;
    v29.mat[2].x = v31;
  }
  v8 = ((double (__fastcall *)(idUtilityCamera *))this->GetDistance)(a1: this);
  GetTargetEntity = this->GetTargetEntity;
  v32.x = (float)(v29.mat[0].x * (float)v8) + v29.mat[1].y;
  v32.y = (float)(v29.mat[0].y * (float)v8) + v29.mat[1].z;
  v32.z = (float)(v29.mat[0].z * (float)v8) + v29.mat[2].x;
  v10 = (int)GetTargetEntity(this);
  if ( v10 != 0 )
    v11 = *(_DWORD *)(v10 + 492);
  else
    v11 = 0x1FFF;
  idClip::TraceBounds(
    this: &clientGame->clip,
    result: &v36,
    start: (const idVec3 *)&v29.mat[1].y,
    end: &v32,
    trm: clientGame->clip.clip16x16,
    clipMask: 3,
    passEntityNumber: v11);
  if ( v36.fraction == 1.0 )
  {
    if ( this->numFrames != 0 )
    {
      v13 = (float)(this->lastPos.x + (float)((float)(v32.x - this->lastPos.x) * (float)0.25));
      v14 = (float)((float)((float)(v32.y - this->lastPos.y) * (float)0.25) + this->lastPos.y);
      v15 = (float)((float)((float)(v32.z - this->lastPos.z) * (float)0.25) + this->lastPos.z);
      v16 = (float)((float)((float)((float)(v32.y - this->lastPos.y) * (float)0.25) + this->lastPos.y) - v29.mat[1].z);
      v29.mat[0].x = (float)(this->lastPos.x + (float)((float)(v32.x - this->lastPos.x) * (float)0.25)) - v29.mat[1].y;
      v29.mat[0].y = v16;
      v29.mat[0].z = (float)v15 - v29.mat[2].x;
      idVec3::NormalizeFast(this: v29.mat);
    }
    else
    {
      v13 = v32.x;
      v14 = v32.y;
      v15 = v32.z;
    }
  }
  else
  {
    v12 = ((double (__fastcall *)(idUtilityCamera *))this->GetDistance)(a1: this);
    v13 = (float)((float)((float)((float)v12 * v29.mat[0].x) * v36.fraction) + v29.mat[1].y);
    v14 = (float)((float)((float)(v29.mat[0].y * (float)v12) * v36.fraction) + v29.mat[1].z);
    v15 = (float)((float)((float)(v29.mat[0].z * (float)v12) * v36.fraction) + v29.mat[2].x);
  }
  this->cachedViewOrg.x = v13;
  this->cachedViewOrg.y = v14;
  this->cachedViewOrg.z = v15;
  this->lastPos.x = v13;
  this->lastPos.y = v14;
  this->lastPos.z = v15;
  v17 = v29.mat[1].z;
  v18 = v29.mat[2].x;
  this->lastTargetPos.x = v29.mat[1].y;
  this->lastTargetPos.z = v18;
  this->lastTargetPos.y = v17;
  this->lastAngles.pitch = this->angles.pitch;
  v19 = (float)(v29.mat[0].z * (float)-1.0);
  this->lastAngles.yaw = this->angles.yaw;
  v20 = (float)(v29.mat[0].y * (float)-1.0);
  v21 = (float)(v29.mat[0].x * (float)-1.0);
  this->lastAngles.roll = this->angles.roll;
  _FP10 = (float)((float)((float)((float)v21 * (float)v21)
                        + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f9, f10, f11, f13 }
  v24 = __frsqrte(_FP9);
  v25 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24
                                                                                      * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                                                                                              * (float)0.5))
                                                                              * (float)v24)
                                                                      - (float)1.5)
                                                      * (float)v24)
                                              * (float)((float)((float)((float)v21 * (float)v21)
                                                              + (float)((float)((float)v20 * (float)v20)
                                                                      + (float)((float)v19 * (float)v19)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v24
                                                                              * (float)((float)((float)((float)v21 * (float)v21)
                                                                                              + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                                                                                      * (float)0.5))
                                                                      * (float)v24)
                                                              - (float)1.5)
                                              * (float)v24))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v24
                                                      * (float)((float)((float)((float)v21 * (float)v21)
                                                                      + (float)((float)((float)v20 * (float)v20)
                                                                              + (float)((float)v19 * (float)v19)))
                                                              * (float)0.5))
                                              * (float)v24)
                                      - (float)1.5)
                      * (float)v24));
  v26 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                              * (float)v24)
                                                                                      * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                      * (float)v24))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v24
                                                                                              * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5))
                                                                                      * (float)v24)
                                                                              - (float)1.5)
                                                              * (float)v24))
                                              * (float)((float)((float)((float)v21 * (float)v21)
                                                              + (float)((float)((float)v20 * (float)v20)
                                                                      + (float)((float)v19 * (float)v19)))
                                                      * (float)0.5))
                                      * (float)v25)
                              - (float)1.5)
              * (float)v25);
  v29.mat[0].x = (float)v26 * (float)v21;
  v29.mat[0].y = (float)v20 * (float)v26;
  v29.mat[0].z = (float)v19 * (float)v26;
  this->cachedViewAxis = *idVec3::ToMat3(this: v35, result: &v29);
  Physics = idEntity::GetPhysics(this);
  Physics->SetOrigin(this: Physics, a2: &this->cachedViewOrg, a3: -1);
  v28 = idEntity::GetPhysics(this);
  v28->SetAxis(this: v28, a2: &this->cachedViewAxis, a3: -1);
  ++this->numFrames;
}


// ========================================================================
// ?InternalDeactivate@idRotatableCamera@@UAA_NXZ
// EA  : 0x82D06B50
// RVA : 0x00D06B50
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idRotatableCamera::InternalDeactivate(idRotatableCamera *this)
{
  idPlayer *PlayerActivator; // r3
  idEntity *v3; // r31
  idPhysics *Physics; // r3

  if ( this->isActive )
  {
    idEntity::BecomeInactive(this, flags: 1);
    PlayerActivator = idCamera::GetPlayerActivator(this);
    v3 = PlayerActivator;
    if ( PlayerActivator != nullptr && (*((_BYTE *)this + 1028) & 0x80) != 0 )
    {
      Physics = idEntity::GetPhysics(this: PlayerActivator);
      Physics->SetOrigin(this: Physics, a2: &this->playerStartPos, a3: -1);
      idEntity::Unbind(this: v3);
      v3->Show(this: v3);
      v3[16].name.baseBuffer[0] = (8 * this->playerWasNoTarget) & 8 | v3[16].name.baseBuffer[0] & 0xF7;
    }
    this->isActive = false;
  }
  return 1;
}


// ========================================================================
// ?GetTargetPos@idEntityCamera@@UBAXAAVidVec3@@@Z
// EA  : 0x82D06C10
// RVA : 0x00D06C10
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idEntityCamera::GetTargetPos(idEntityCamera *this, idVec3 *pos)
{
  int value; // r10
  idEntity *v5; // r3
  int v6; // r9
  idEntity *v7; // r3
  idEntity *v8; // r3
  idPhysics *Physics; // r3
  float *v10; // r3

  value = this->targetEnt.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr && idEntity::CastTo(c: v5) != nullptr )
    {
      v6 = this->targetEnt.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13 && (v7 = gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
        v8 = idEntity::CastTo(c: v7);
      else
        v8 = nullptr;
      Physics = idEntity::GetPhysics(this: v8);
      v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      this->lastEntityOrigin.x = *v10;
      this->lastEntityOrigin.y = v10[1];
      this->lastEntityOrigin.z = v10[2];
    }
  }
  pos->x = this->lastEntityOrigin.x;
  pos->y = this->lastEntityOrigin.y;
  pos->z = this->lastEntityOrigin.z;
}


// ========================================================================
// ?GetOffset@idEntityCamera@@UBAXAAVidVec3@@@Z
// EA  : 0x82D06D00
// RVA : 0x00D06D00
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idEntityCamera::GetOffset(idEntityCamera *this, idVec3 *_offset)
{
  int value; // r10
  idEntityPtr<idEntity> *p_targetEnt; // r30
  idEntity *v6; // r3
  idEntity *v7; // r3
  idEntity *v8; // r3
  idPhysics *Physics; // r3
  float *v10; // r3
  idEntity *v11; // r3
  idEntity *v12; // r3
  idEntity *v13; // r3
  double v14; // fp12
  double v15; // fp13
  double v16; // fp0
  idEntity *v17; // r3
  idPresentable *presentable; // r3
  float *v19; // r3
  double v20; // fp0
  double x; // fp0
  double y; // fp8
  double z; // fp5
  float v24; // [sp+50h] [-90h]
  float v25; // [sp+54h] [-8Ch]
  float v26; // [sp+58h] [-88h]
  float v27; // [sp+60h] [-80h] BYREF
  float v28; // [sp+64h] [-7Ch]
  float v29; // [sp+68h] [-78h]
  _BYTE v30[48]; // [sp+70h] [-70h] BYREF

  if ( !this->useViewOffset )
  {
    v20 = 0.0;
    this->viewOffset.y = 0.0;
    this->viewOffset.z = 0.0;
LABEL_23:
    this->viewOffset.x = v20;
    goto LABEL_24;
  }
  value = this->targetEnt.spawnId.value;
  p_targetEnt = &this->targetEnt;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v6 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v6 != nullptr && idEntity::CastTo(c: v6) != nullptr )
    {
      if ( gameLocal->spawnIds.ptr[p_targetEnt->spawnId.value & 0x1FFF] == p_targetEnt->spawnId.value >> 13
        && (v7 = gameLocal->entities.ptr[p_targetEnt->spawnId.value & 0x1FFF]) != nullptr )
      {
        v8 = idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      Physics = idEntity::GetPhysics(this: v8);
      v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v24 = *v10;
      v25 = v10[1];
      v26 = v10[2];
      if ( gameLocal->spawnIds.ptr[p_targetEnt->spawnId.value & 0x1FFF] == p_targetEnt->spawnId.value >> 13
        && (v11 = gameLocal->entities.ptr[p_targetEnt->spawnId.value & 0x1FFF]) != nullptr )
      {
        v12 = idEntity::CastTo(c: v11);
      }
      else
      {
        v12 = nullptr;
      }
      if ( (unsigned __int8)idClass::IsType(this: v12, superclass: &idActor::Type) != 0 )
      {
        v13 = idEntityPtr<idEntity const>::operator->(this: p_targetEnt);
        ((void (__fastcall *)(idEntity *, float *, _BYTE *))v13->__vftable[1].PauseThink)(a1: v13, a2: &v27, a3: v30);
        v14 = v29;
        v15 = v28;
        v16 = v27;
      }
      else
      {
        v17 = idEntityPtr<idEntity const>::operator->(this: p_targetEnt);
        if ( (unsigned __int8)idClass::IsType(this: v17, superclass: &idPlayer::Type) != 0 )
        {
          presentable = idEntityPtr<idEntity const>::operator->(this: p_targetEnt)->presentable;
          if ( presentable != nullptr )
            v19 = (float *)presentable->GetPlayerInterface_2(this: presentable);
          else
            v19 = nullptr;
          v16 = v19[11633];
          v27 = v19[11633];
          v15 = v19[11634];
          v28 = v19[11634];
          v14 = v19[11635];
        }
        else
        {
          v16 = v24;
          v15 = v25;
          v14 = v26;
        }
      }
      this->viewOffset.y = (float)v15 - v25;
      this->viewOffset.z = (float)v14 - v26;
      v20 = (float)((float)v16 - v24);
      goto LABEL_23;
    }
  }
LABEL_24:
  x = this->offset.x;
  _offset->x = this->offset.x;
  y = this->offset.y;
  _offset->y = this->offset.y;
  z = this->offset.z;
  _offset->z = this->offset.z;
  _offset->x = this->viewOffset.x + (float)x;
  _offset->y = this->viewOffset.y + (float)y;
  _offset->z = this->viewOffset.z + (float)z;
}


// ========================================================================
// ?GetExitLocation@idTownGarageCamera@@QBAPAVidPlayerStart@@XZ
// EA  : 0x82D06F80
// RVA : 0x00D06F80
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idPlayerStart *__fastcall idTownGarageCamera::GetExitLocation(idTownGarageCamera *this)
{
  int value; // r10
  idPlayerStart *v2; // r3

  value = this->exitLocation.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idPlayerStart *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idPlayerStart::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetExitTarget@idTownGarageCamera@@QBAPAVidEntity@@XZ
// EA  : 0x82D07008
// RVA : 0x00D07008
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idEntity *__fastcall idTownGarageCamera::GetExitTarget(idTownGarageCamera *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->exitTarget.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetNumVehicles@idTownGarageCamera@@QBAHXZ
// EA  : 0x82D07090
// RVA : 0x00D07090
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idTownGarageCamera::GetNumVehicles(idTownGarageCamera *this)
{
  idTownGarageManager *garageManager; // r11

  garageManager = this->garageManager;
  if ( garageManager != nullptr )
    return garageManager->vehicles.num;
  else
    return 0;
}


// ========================================================================
// ?Draw@idCinematicCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D070B0
// RVA : 0x00D070B0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idCinematicCamera::Draw(idCinematicCamera *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  idParmBlock *v5; // r3
  double y; // fp13
  double z; // fp12
  idView *p_size; // r30
  idParmBlock *v9; // r25
  double v10; // fp31
  __int64 v11; // r9
  int fadeTime; // r11
  idPresentable *v13; // r3
  idPresentablePlayer *v14; // r3
  idSWF *PlayerGui; // r28
  idPresentable *v16; // r3
  int v17; // r29
  int v18; // r3
  const char *v19; // r7
  idPhysics *Physics; // r3
  float *v21; // r3
  idPresentable *v22; // r3
  int v23; // r3
  idPlayerHud::hudState_t v24; // r4
  idPresentable *v25; // r3
  int v26; // r29
  idPresentable *v27; // r3
  int v28; // r3
  __int64 v29; // r8 OVERLAPPED
  idPresentable *v30; // r3
  int v31; // r30
  int v32; // r3
  const char *v33; // r7
  int currentTime; // r9
  double v35; // fp0
  char v36; // r11
  double v37; // fp29
  double v38; // fp28
  double v39; // fp27
  double v40; // fp26
  const idDeclRenderParm *v41; // r3
  double v42; // fp31
  const idDeclRenderParm *v43; // r3
  parmValue_t v45[4]; // [sp+50h] [-80h] BYREF

  presentable = player->presentable;
  if ( presentable != nullptr )
    v5 = (idParmBlock *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = nullptr;
  y = this->cameraDOF.y;
  z = this->cameraDOF.z;
  p_size = (idView *)&v5[405].constants.size;
  v45[0].value[0] = this->cameraDOF.x;
  v45[0].value[1] = y;
  v9 = v5 + 410;
  v10 = 0.0;
  v45[0].value[3] = 0.0;
  v45[0].value[2] = z;
  idParmBlock::SetParm(this: v5 + 410, parm: rp->depthOfField, parmValue: v45);
  if ( this->current.fade.activate )
  {
    v45[0].swizzle[1] = (int)(float)(this->current.fade.transTime * (float)1000.0);
    idView::Fade(this: p_size, color: (const idVec4 *)&this->current.fade, time: v45[0].swizzle[1]);
    this->current.fade.activate = false;
  }
  if ( this->current.fade.timeScaleFade && p_size->fadeTime != 0 && this->timeScale != 1.0 )
  {
    LODWORD(v11) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    fadeTime = p_size->fadeTime;
    v45[0].swizzle[1] = (int)(float)((float)v11 * this->timeScale);
    p_size->fadeTime = v45[0].swizzle[1] + fadeTime;
  }
  if ( this->playerGui != (GUI_TUTORIAL|GUI_JOBOFFER) )
  {
    v13 = player->presentable;
    v14 = v13 != nullptr ? v13->GetPlayerInterface_2(this: v13) : nullptr;
    PlayerGui = idPresentablePlayer::GetPlayerGui(this: v14, g: this->playerGui);
    if ( PlayerGui != nullptr )
    {
      v16 = player->presentable;
      if ( v16 != nullptr )
        v17 = (int)v16->GetPlayerInterface_2(this: v16);
      else
        v17 = 0;
      v18 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idSWF::Render(this: PlayerGui, gui: *(idRenderModelGui **)(v17 + 16224), time: v18, isSplitscreen: false, a5: v19);
    }
  }
  Physics = idEntity::GetPhysics(this);
  v21 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)v45, result: (idVec3 *)Physics, a3: 0);
  p_size->viewVelocity.x = *v21;
  p_size->viewVelocity.y = v21[1];
  p_size->viewVelocity.z = v21[2];
  idView::SetViewPos(this: p_size, origin: &this->cameraPos, axis: &this->cameraAxis);
  idView::SetViewID(this: p_size, id: this->entityNumber + 1);
  idView::Render(this: p_size);
  v22 = player->presentable;
  if ( this->showPlayerHud )
  {
    if ( v22 != nullptr )
      v23 = (int)v22->GetPlayerInterface_2(this: v22);
    else
      v23 = 0;
    v24 = HUDSTATE_ALL;
  }
  else
  {
    if ( v22 != nullptr )
      v23 = (int)v22->GetPlayerInterface_2(this: v22);
    else
      v23 = 0;
    v24 = HUDSTATE_NONE;
  }
  idPlayerHud::SetHudState(this: (idPlayerHud *)(v23 + 35096), state: v24);
  v25 = player->presentable;
  if ( v25 != nullptr )
    v26 = (int)v25->GetPlayerInterface_2(this: v25);
  else
    v26 = 0;
  v27 = player->presentable;
  if ( v27 != nullptr )
    v28 = (int)v27->GetPlayerInterface_2(this: v27);
  else
    v28 = 0;
  idPlayerHud::Update(this: (idPlayerHud *)(v28 + 35096), hudInfo: (idHudInfo *)(v26 + 35368));
  if ( this->gui != nullptr && !gameLocal->MainMenu_IsActive(this: gameLocal) )
  {
    v30 = player->presentable;
    if ( v30 != nullptr )
      v31 = (int)v30->GetPlayerInterface_2(this: v30);
    else
      v31 = 0;
    v32 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idSWF::Render(this: this->gui, gui: *(idRenderModelGui **)(v31 + 16224), time: v32, isSplitscreen: false, a5: v33);
  }
  if ( this->current.renderParms.transTime >= 0.0 )
  {
    currentTime = this->currentTime;
    LODWORD(v29) = this->startTime;
    v35 = (float)((float)((float)*(__int64 *)((char *)&v29 - 4)
                        - (float)((float)v29 + this->current.renderParms.startTimeOfs))
                / (float)(this->current.renderParms.transTime * (float)1000.0));
    *(_QWORD *)v45[0].value = v29;
    if ( v35 >= 0.0 )
    {
      if ( v35 <= 1.0 )
      {
        v10 = v35;
        if ( v35 != 1.0 )
          goto LABEL_46;
      }
      else
      {
        v10 = 1.0;
      }
      this->current.renderParms.transTime = -1.0;
    }
LABEL_46:
    if ( this->current.renderParms.fogColor.r != idColor::colorDefault.r
      || this->current.renderParms.fogColor.g != idColor::colorDefault.g
      || this->current.renderParms.fogColor.b != idColor::colorDefault.b
      || (v36 = 1, this->current.renderParms.fogColor.a != idColor::colorDefault.a) )
    {
      v36 = 0;
    }
    if ( v36 == 0 )
    {
      v37 = (float)((float)((float)(this->current.renderParms.fogColor.r - this->previous.renderParms.fogColor.r)
                          * (float)v10)
                  + this->previous.renderParms.fogColor.r);
      v38 = (float)((float)((float)(this->current.renderParms.fogColor.g - this->previous.renderParms.fogColor.g)
                          * (float)v10)
                  + this->previous.renderParms.fogColor.g);
      v39 = (float)((float)((float)(this->current.renderParms.fogColor.b - this->previous.renderParms.fogColor.b)
                          * (float)v10)
                  + this->previous.renderParms.fogColor.b);
      v40 = (float)((float)((float)(this->current.renderParms.fogColor.a - this->previous.renderParms.fogColor.a)
                          * (float)v10)
                  + this->previous.renderParms.fogColor.a);
      v41 = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                        this: &idDeclRenderParm::resourceList,
                                        name: "fogColor",
                                        makeDefault: true);
      v45[0].value[0] = v37;
      v45[0].value[1] = v38;
      v45[0].value[2] = v39;
      v45[0].value[3] = v40;
      idParmBlock::SetParm(this: v9, parm: v41, parmValue: v45);
    }
    if ( this->current.renderParms.fogScale != -1.0 )
    {
      v42 = (float)((float)((float)(this->current.renderParms.fogScale - this->previous.renderParms.fogScale)
                          * (float)v10)
                  + this->previous.renderParms.fogScale);
      v43 = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                        this: &idDeclRenderParm::resourceList,
                                        name: "fogScale",
                                        makeDefault: true);
      v45[0].value[3] = v42;
      v45[0].value[2] = v42;
      v45[0].value[1] = v42;
      v45[0].value[0] = v42;
      idParmBlock::SetParm(this: v9, parm: v43, parmValue: v45);
    }
  }
  return 1;
}


// ========================================================================
// ?Trigger_Sounds@idCinematicCamera@@QAAXAAUtrigSounds_t@1@H@Z
// EA  : 0x82D07608
// RVA : 0x00D07608
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idCinematicCamera::Trigger_Sounds(
        idCinematicCamera *this,
        idCinematicCamera::trigSounds_t *sounds,
        int startTimeOfs)
{
  int v5; // r31
  int v6; // r30
  const idDeclVoiceOver *voiceOver; // r11
  idPlayer *PlayerActivator; // r30
  int v9; // r31
  signed int num; // r11
  unsigned int seed; // r8
  unsigned int v12; // r4
  int v13; // r3
  const idDeclVoiceOver *v14; // r11
  const idVoiceTrack *v15; // r11
  idPresentable *presentable; // r11
  idPresentable *v17; // r30
  idPresentable *v18; // r4
  idStrId v19; // [sp+50h] [-30h] BYREF

  v5 = 0;
  if ( sounds->sound.num > 0 )
  {
    v6 = 0;
    do
    {
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_ANY,
        shader: sounds->sound.list[v6],
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
      ++v5;
      ++v6;
    }
    while ( v5 < sounds->sound.num );
  }
  voiceOver = sounds->voiceOver;
  if ( voiceOver != nullptr && voiceOver->tracks.num > 0 )
  {
    PlayerActivator = idCamera::GetPlayerActivator(this);
    if ( PlayerActivator != nullptr )
    {
      v9 = 0;
      num = sounds->voiceOver->tracks.num;
      if ( num > 1 )
      {
        seed = clientGame->random.seed;
        __twllei(num, 0);
        v12 = 1664525 * seed + 1013904223;
        clientGame->random.seed = v12;
        v13 = (v12 >> 10) & 0x7FFF;
        v9 = v13 % num;
        __twlgei(num & ~(__ROL4__(v13, 1) - 1), 0xFFFFFFFF);
      }
      v14 = sounds->voiceOver;
      if ( v9 < 0 || v9 >= v14->tracks.num )
        v15 = nullptr;
      else
        v15 = v14->tracks.list[v9];
      idEntity::StartSoundShader(
        this: PlayerActivator,
        channel: SND_CHANNEL_MUSIC2,
        shader: v15->soundShader,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
      presentable = PlayerActivator->presentable;
      v19.index = -1;
      if ( presentable != nullptr )
      {
        v17 = presentable;
      }
      else
      {
        idEntity::InitPresentableInternal(this: PlayerActivator);
        v17 = PlayerActivator->presentable;
      }
      v18 = this->presentable;
      if ( v18 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v18 = this->presentable;
      }
      idGameLocal::PlayedVoiceOver(
        this: gameLocal,
        whoStartedMe: v18,
        target: v17,
        vo: sounds->voiceOver,
        voiceTrackIndex: v9,
        whoStartedMeText: &v19);
    }
    else
    {
      idLib::Warning(fmt: "no player found for play voice over on idCinematic Camera");
    }
  }
}


// ========================================================================
// ?InternalDeactivate@idCinematicCamera@@MAA_NXZ
// EA  : 0x82D077B0
// RVA : 0x00D077B0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idCinematicCamera::InternalDeactivate(idCinematicCamera *this)
{
  idPlayer *PlayerActivator; // r3
  idPlayer *v3; // r30
  idPresentable *presentable; // r3
  int v5; // r3
  idPresentable *v6; // r3
  int v7; // r3
  idPlayerHud *PlayerHud; // r3
  idPresentable *v9; // r3
  idPresentable *v10; // r3
  idPresentablePlayer *v11; // r3
  idPresentable *v12; // r3
  int v13; // r3
  idPresentable *v14; // r3
  int v15; // r3
  idPresentable *v16; // r3
  int v17; // r3
  const idAngles *v18; // r3
  idPhysics *Physics; // r31
  idPhysics *v20; // r28
  double v21; // fp31
  float *v22; // r3
  double v23; // fp6
  double v24; // fp5
  double y; // fp12
  double z; // fp11
  float v28[4]; // [sp+50h] [-60h] BYREF
  idMat3 v29[2]; // [sp+60h] [-50h] BYREF

  PlayerActivator = idCamera::GetPlayerActivator(this);
  v3 = PlayerActivator;
  if ( PlayerActivator != nullptr )
  {
    if ( this->hidePlayer )
      PlayerActivator->Show(this: PlayerActivator);
    if ( this->hidePlayerHands )
    {
      presentable = v3->presentable;
      v5 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
      if ( v5 != -37616 )
      {
        v6 = v3->presentable;
        if ( v6 != nullptr )
          v7 = (int)v6->GetPlayerInterface_2(this: v6);
        else
          v7 = 0;
        idHands::Show(this: (idHands *)(v7 + 37616), hideReason: HAND_HIDE_GENERIC);
      }
    }
    if ( !this->showPlayerHud )
    {
      PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: v3);
      idPlayerHud::SetHudState(this: PlayerHud, state: HUDSTATE_ALL);
    }
    v9 = v3->presentable;
    if ( v9 != nullptr && v9->GetPlayerInterface_2(this: v9) != nullptr )
    {
      v10 = v3->presentable;
      v11 = v10 != nullptr ? v10->GetPlayerInterface_2(this: v10) : nullptr;
      if ( idPresentablePlayer::GuiIsActive(this: v11, g: GUI_INVENTORY) )
      {
        v12 = v3->presentable;
        if ( v12 != nullptr )
          v13 = (int)v12->GetPlayerInterface_2(this: v12);
        else
          v13 = 0;
        idView::ForceBlurValues(this: (idView *)(v13 + 16224), blurBegin: 0.0, blurEnd: 2.5, blurTime: 250.0);
      }
    }
    if ( this->fadeInOnReturn )
    {
      v14 = v3->presentable;
      if ( v14 != nullptr )
        v15 = (int)v14->GetPlayerInterface_2(this: v14);
      else
        v15 = 0;
      *(idColor *)(v15 + 19068) = idColor::colorBlack;
      v29[0].mat[1].y = 0.0;
      v29[0].mat[1].z = 0.0;
      v29[0].mat[2].x = 0.0;
      v29[0].mat[2].y = 0.0;
      v16 = v3->presentable;
      if ( v16 != nullptr )
        v17 = (int)v16->GetPlayerInterface_2(this: v16);
      else
        v17 = 0;
      idView::Fade(this: (idView *)(v17 + 16224), color: (const idVec4 *)&v29[0].mat[1].y, time: 1000);
    }
    if ( this->setPlayerAnglesOnReturn )
    {
      v18 = idMat3::ToAngles(this: v29, result: (idAngles *)&this->current.focus.viewAxis);
      idPlayer::SetViewAngles(this: v3, angles: v18, force: true);
    }
    if ( this->setPlayerPositionOnReturn )
    {
      Physics = idEntity::GetPhysics(this: v3);
      v20 = idEntity::GetPhysics(this: v3);
      v21 = -v3->GetEyeOffset(this: (idActor *)v29, result: (const idVec3 *)v3)->z;
      v22 = (float *)Physics->GetGravityNormal(this: Physics);
      v23 = (float)(v22[1] * (float)v21);
      v24 = (float)(v22[2] * (float)v21);
      y = this->current.movement.viewOrigin.y;
      z = this->current.movement.viewOrigin.z;
      v28[0] = this->current.movement.viewOrigin.x - (float)((float)v21 * *v22);
      v28[1] = (float)y - (float)v23;
      v28[2] = (float)z - (float)v24;
      v20->SetOrigin(this: v20, a2: (const idVec3 *)v28, a3: -1);
    }
    idPlayer::CalculateView(this: v3);
  }
  idEntity::BecomeInactive(this, flags: 1);
  return 1;
}


// ========================================================================
// ?AdjustTiming@idSlowMotionCamera@@IAAXXZ
// EA  : 0x82D07BE0
// RVA : 0x00D07BE0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idSlowMotionCamera::AdjustTiming(idSlowMotionCamera *this, long double a2, int a3, __int64 a4)
{
  double TimeLerpFraction; // fp1
  double v6; // fp31
  __int64 v7; // r4

  TimeLerpFraction = idSlowMotionCamera::GetTimeLerpFraction(this, timeLerpHelper: a4, a3: a2);
  v6 = (float)((float)((float)(this->current.timeScale.scale - this->current.timeScale.initScale)
                     * (float)TimeLerpFraction)
             + this->current.timeScale.initScale);
  this->timeScale = (float)((float)(this->current.timeScale.scale - this->current.timeScale.initScale)
                          * (float)TimeLerpFraction)
                  + this->current.timeScale.initScale;
  v7 = ((__int64 (__fastcall *)(idGameLocal *))gameLocal->GetGameTimeManager)(a1: gameLocal);
  idGameTimeManager::SetTimeScale(
    this: (idGameTimeManager *)HIDWORD(v7),
    scale: v6,
    type: (const gameTimeType_t)v7,
    a4: 1);
}


// ========================================================================
// ?SetDefaults@idPresentableReviveCamera@@QAAXXZ
// EA  : 0x82D07CB0
// RVA : 0x00D07CB0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idPresentableReviveCamera::SetDefaults(idPresentableReviveCamera *this)
{
  this->initializedState = 0;
  this->prevInitializedState = 0;
  this->startTime = 0;
  this->viewAxis = mat3_identity;
  this->viewOrigin = vec3_origin;
  this->playerPresentable.spawnId = 0;
  this->currentPitch = 0.0;
  this->prevCmdPitch = 0.0;
  this->currentYaw = 0.0;
  this->prevCmdYaw = 0.0;
}


// ========================================================================
// ?InitSerializedState@idPresentableReviveCamera@@QAAXPBVidPresentablePlayer@@@Z
// EA  : 0x82D07D58
// RVA : 0x00D07D58
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idPresentableReviveCamera::InitSerializedState(
        idPresentableReviveCamera *this,
        const idPresentablePlayer *player)
{
  int v2; // r4
  _DWORD *v3; // r3
  int v4; // r11

  idPresentableReviveCamera::SetDefaults(this);
  v4 = 0;
  if ( v2 != 0 )
    v4 = *(_DWORD *)(v2 + 1100);
  v3[321] = v4;
  ++v3[312];
  v3[319] = (v3[319] + 1) % 7;
}


// ========================================================================
// ?ControlReleased@idPresentableReviveCamera@@UAAXXZ
// EA  : 0x82D07DD0
// RVA : 0x00D07DD0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// attributes: thunk
void __fastcall idPresentableReviveCamera::ControlReleased(idPresentableReviveCamera *this)
{
  idPresentableReviveCamera::SetDefaults(this);
}


// ========================================================================
// ?SetDefaults@idOnlineVehicleDeathCameraPresentable@@QAAXXZ
// EA  : 0x82D07DD8
// RVA : 0x00D07DD8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idOnlineVehicleDeathCameraPresentable::SetDefaults(idOnlineVehicleDeathCameraPresentable *this)
{
  this->attackerPresentable.spawnId = 0;
  this->playerVehiclePresentable.spawnId = 0;
  this->initializedState = 0;
  this->prevInitializedState = 0;
  this->prevAxis = mat3_zero;
  this->prevOrigin = vec3_origin;
  this->startTime = 0;
  this->isOverPit = false;
  *(_WORD *)&this->firstTraceDone = 1;
  this->targetPosPrev = vec3_origin;
  this->viewAxis = mat3_zero;
  this->viewOrigin = vec3_origin;
  this->goalPos = vec3_origin;
  this->distToTarget = 0.0;
  this->startingOrigin = vec3_origin;
}


// ========================================================================
// ?InternalDeactivate@idRCBombDeathCamera@@UAA_NXZ
// EA  : 0x82D07F30
// RVA : 0x00D07F30
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idRCBombDeathCamera::InternalDeactivate(idRCBombDeathCamera *this)
{
  int v2; // r31

  v2 = idCameraView::InternalDeactivate(this);
  if ( (_BYTE)v2 != 0 )
    idEntity::BecomeInactive(this, flags: 1);
  return v2;
}


// ========================================================================
// ?OnActivate@idCaptureController@@UAAXPAVidEntity@@@Z
// EA  : 0x82D07F88
// RVA : 0x00D07F88
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idCaptureController::OnActivate(idCaptureController *this, idEntity *activator_)
{
  int value; // r9
  idEntity *v4; // r3
  idEntity *v5; // r3
  int v6; // r10
  int v7; // r11
  idCaptureController::shotInfo_t *v8; // r9

  if ( this->continous )
  {
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "vehicle_cam_resetOfs", a3: true, a4: 0);
    if ( this->startTriggers.num > 0 )
    {
      value = this->startTriggers.list->trig.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v4 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v4 != nullptr && idEntity::CastTo(c: v4) != nullptr )
        {
          v5 = idEntityPtr<idEntity const>::operator->(this: &this->startTriggers.list->trig);
          idEntity::Activate(this: v5, activator: this);
        }
      }
    }
    this->currentShot = 0;
    this->shotStartTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "vehicle_cam", a3: true, a4: 0);
    if ( cine_captureFrames.valueInteger != 0 )
    {
      cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_captureFrames", a3: 2, a4: 0);
      cvarSystem->SetCVarBool(this: cvarSystem, a2: "com_fixedTic", a3: true, a4: 0);
    }
    v6 = 0;
    if ( this->shots.num > 0 )
    {
      v7 = 0;
      do
      {
        ++v6;
        v8 = &this->shots.list[v7++];
        v8->fired = false;
      }
      while ( v6 < this->shots.num );
    }
    idCVar::SetString(this: &com_capturePath, newValue: this->name.data, force: true);
  }
  else if ( this->startTriggers.num > 0 && (this->cameras.num > 0 || this->vehicles.num > 0) )
  {
    this->currentTrigger = 0;
    this->currentCamera = 0;
    this->currentVehicle = 0;
    this->capturing = true;
    idEventReceiver::PostEventMS(this, ev: &EV_NextCamera, time: 0);
  }
}


// ========================================================================
// ?Event_NextShot@idCaptureController@@AAA?AVeventVoid@@XZ
// EA  : 0x82D08180
// RVA : 0x00D08180
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idCaptureController *__fastcall idCaptureController::Event_NextShot(idCaptureController *this, idEntity *result)
{
  idCaptureController *v2; // r29
  int z_low; // r10
  int v5; // r11
  int *v6; // r9
  idEntity *v7; // r3
  int v8; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3

  v2 = this;
  z_low = LODWORD(result[1].spawnPosition.z);
  v5 = LODWORD(result[1].spawnOrientation.mat[2].y) + 1;
  LODWORD(result[1].spawnOrientation.mat[2].y) = v5;
  if ( v5 < z_low )
  {
    LODWORD(result[1].spawnOrientation.mat[2].z) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v6 = (int *)(72 * LODWORD(result[1].spawnOrientation.mat[2].y) + LODWORD(result[1].spawnPosition.y) + 56);
    if ( gameLocal->spawnIds.ptr[*v6 & 0x1FFF] == *v6 >> 13 )
    {
      v7 = gameLocal->entities.ptr[*v6 & 0x1FFF];
      if ( v7 != nullptr && idEntity::CastTo(c: v7) != nullptr )
      {
        v8 = *(_DWORD *)(72 * LODWORD(result[1].spawnOrientation.mat[2].y) + LODWORD(result[1].spawnPosition.y) + 56);
        if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13 )
        {
          v9 = gameLocal->entities.ptr[*(_DWORD *)(72 * LODWORD(result[1].spawnOrientation.mat[2].y)
                                                 + LODWORD(result[1].spawnPosition.y)
                                                 + 56)
                                     & 0x1FFF];
          if ( v9 != nullptr )
          {
            v10 = idEntity::CastTo(c: v9);
            idEntity::Activate(this: v10, activator: result);
            return v2;
          }
        }
        idEntity::Activate(this: nullptr, activator: result);
      }
    }
    return v2;
  }
  LODWORD(result[1].spawnOrientation.mat[2].y) = v5 - 1;
  return this;
}


// ========================================================================
// ?AllocPresentable@idSpectatorCamera@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82D082C8
// RVA : 0x00D082C8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idPresentable *__fastcall idSpectatorCamera::AllocPresentable(idSpectatorCamera *this, idRenderModel *renderModel)
{
  idPresentable *v3; // r3
  idPresentable *v4; // r30

  v3 = (idPresentable *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x4C8u,
                          tag: TAG_PRESENTABLE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  idPresentable::idPresentable(
    this: v3,
    e: this,
    renderModel_: nullptr,
    entityNumber_: this->entityNumber,
    fxDecl_: nullptr);
  v4->__vftable = (idPresentable_vtbl *)&idPresentableSpectatorCamera::`vftable';
  return v4;
}


// ========================================================================
// __unwind$505565
// EA  : 0x82D08348
// RVA : 0x00D08348
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_505565()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Serialize@idPresentableSpectatorCamera@@UAAXAAVidSerializer@@@Z
// EA  : 0x82D08378
// RVA : 0x00D08378
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idPresentableSpectatorCamera::Serialize(idPresentableSpectatorCamera *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  idBitMsg *v5; // r3
  idBitMsg *v6; // r3

  idSerializer::Serialize(this: ser, value: &this->viewOrigin);
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: COERCE_INT(this->viewAngles.pitch), numBits: 32);
  else
    LODWORD(this->viewAngles.pitch) = idBitMsg::ReadBits(this: msg, numBits: 32);
  v5 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v5, value: COERCE_INT(this->viewAngles.yaw), numBits: 32);
  else
    LODWORD(this->viewAngles.yaw) = idBitMsg::ReadBits(this: v5, numBits: 32);
  v6 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v6, value: COERCE_INT(this->viewAngles.roll), numBits: 32);
  else
    LODWORD(this->viewAngles.roll) = idBitMsg::ReadBits(this: v6, numBits: 32);
  idPresentable::Serialize(this, ser);
}


// ========================================================================
// ?InternalDeactivate@idFreeCamera@@MAA_NXZ
// EA  : 0x82D08460
// RVA : 0x00D08460
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idFreeCamera::InternalDeactivate(idFreeCamera *this)
{
  idPlayer *PlayerActivator; // r3

  PlayerActivator = idCamera::GetPlayerActivator(this);
  if ( PlayerActivator != nullptr )
    idPlayer::SetViewAngles(this: PlayerActivator, angles: &this->curAngles, force: false);
  idCameraView::InternalDeactivate(this);
  return 1;
}


// ========================================================================
// ?Activate@idCamera@@QAAXPAVidEntity@@@Z
// EA  : 0x82D088C0
// RVA : 0x00D088C0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idCamera::Activate(idCamera *this, idEntity *activator_)
{
  idPlayer *PlayerActivator; // r3
  idPlayer *v4; // r30
  bool v5; // r31

  if ( this->InternalActivate(this, a2: activator_) )
  {
    PlayerActivator = idCamera::GetPlayerActivator(this);
    v4 = PlayerActivator;
    if ( PlayerActivator != nullptr )
    {
      idPlayer::AddControl(this: PlayerActivator, entity: this);
      v5 = this->CanShowCrosshair(this);
      *(_BYTE *)(idPlayer::GetPlayerHud(this: v4) + 8) = v5;
    }
  }
}


// ========================================================================
// ?OnActivate@idCamera@@UAAXPAVidEntity@@@Z
// EA  : 0x82D08950
// RVA : 0x00D08950
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// attributes: thunk
void __fastcall idCamera::OnActivate(idCamera *this, idEntity *activator_)
{
  idCamera::Activate(this, activator_);
}


// ========================================================================
// ?Draw@idCameraView@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D08958
// RVA : 0x00D08958
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idCameraView::Draw(idCameraView *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r11
  idView *v6; // r31
  idPhysics *Physics; // r3
  float *v8; // r3
  int entityNumber; // r11
  char v11; // [sp+50h] [-40h] BYREF

  presentable = player->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  v6 = (idView *)(v5 + 16224);
  idCameraView::GetViewPos(this, org: &this->viewOrigin, angles: &this->viewAngles);
  idView::SetViewPos(this: v6, origin: &this->viewOrigin, angles: &this->viewAngles);
  Physics = idEntity::GetPhysics(this);
  v8 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v11, result: (idVec3 *)Physics, a3: 0);
  v6->viewVelocity.x = *v8;
  v6->viewVelocity.y = v8[1];
  v6->viewVelocity.z = v8[2];
  if ( pm_thirdPerson.valueInteger != 0 || player->IsDead(this: player) && idPlayer::GetShowDeadBody(this: player) )
    entityNumber = this->entityNumber;
  else
    entityNumber = player->entityNumber;
  idView::SetViewID(this: v6, id: entityNumber + 1);
  idView::Render(this: v6);
  return 1;
}


// ========================================================================
// ??0idInteractionCamera@@QAA@XZ
// EA  : 0x82D08A78
// RVA : 0x00D08A78
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idInteractionCamera *__fastcall idInteractionCamera::idInteractionCamera(idInteractionCamera *this)
{
  float roll; // r6

  idEntity::idEntity(this);
  this->activator.spawnId.value = 0x1FFF;
  this->__vftable = (idInteractionCamera_vtbl *)&idInteractionCamera::`vftable';
  this->startAngles = ang_zero;
  this->startPos = vec3_origin;
  this->returnToPos = vec3_origin;
  this->destAngles = ang_zero;
  this->destPos = vec3_origin;
  *(_WORD *)&this->returningToPlayer = 1;
  this->targetOffset = vec3_origin;
  this->targetAnglesOffset.pitch = ang_zero.pitch;
  this->targetAnglesOffset.yaw = ang_zero.yaw;
  roll = ang_zero.roll;
  this->cameraFov = 80.0;
  this->startFov = 80.0;
  this->lerpTime = 400;
  this->currentInterpFraction = 1.0;
  this->lerpInTime = 400;
  this->lerpSwitchTime = 150;
  this->lerpOutTime = 400;
  this->envSettings = nullptr;
  this->tryToTeleportPlayer = false;
  this->forceTeleportPlayer = false;
  this->tryToKeepPitch = false;
  this->startTime = 0;
  this->targetAnglesOffset.roll = roll;
  this->deactivateCallbackAI.spawnId.value = 0x1FFF;
  this->activatingAI.spawnId.value = 0x1FFF;
  this->dynamicallySetup = false;
  return this;
}


// ========================================================================
// ?InternalDeactivate@idInteractionCamera@@MAA_NXZ
// EA  : 0x82D08BE0
// RVA : 0x00D08BE0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idInteractionCamera::InternalDeactivate(idInteractionCamera *this)
{
  idPlayer *PlayerActivator; // r3
  idPlayer *v3; // r30
  idPresentable *presentable; // r3
  int v5; // r25
  char *v6; // r10
  float *p_y; // r11
  int v8; // ctr
  double y; // fp13
  double z; // fp12
  char v11; // r24
  bool forceTeleportPlayer; // r26
  BOOL v13; // r28
  idPhysics *Physics; // r3
  double valueFloat; // fp31
  float *v16; // r3
  double v17; // fp3
  double v18; // fp2
  idPhysics *v19; // r3
  double v20; // fp31
  float *v21; // r3
  double v22; // fp2
  double v23; // fp1
  idPhysics *v24; // r28
  idPhysics *v25; // r24
  int entityNumber; // r23
  idMat3 *v27; // r22
  idClipModel *v28; // r3
  idPhysics *v29; // r3
  float *v30; // r3
  double v31; // fp6
  double v32; // fp5
  idPhysics *v33; // r3
  double v34; // fp30
  float *v35; // r3
  double v36; // fp4
  double v37; // fp3
  idPhysics *v38; // r29
  idPhysics *v39; // r24
  int v40; // r23
  idMat3 *v41; // r29
  idClipModel *v42; // r3
  idPhysics *v43; // r3
  float *v44; // r3
  idPhysics *v45; // r29
  idPhysics *v46; // r24
  int v47; // r23
  idMat3 *v48; // r29
  idClipModel *v49; // r3
  idPlayer_vtbl *v50; // r29
  idAngles *v51; // r3
  int v52; // r3
  int lerpOutTime; // r9
  double x; // fp12
  double v55; // fp13
  idPhysics *v56; // r3
  int value; // r9
  idPhysics *v58; // r29
  idAI2 *v59; // r3
  idAI2 *v60; // r3
  idPhysics *v61; // r27
  float *v62; // r29
  float *v63; // r3
  double v64; // fp9
  double v65; // fp7
  idAngles *p_destAngles; // r29
  idAI2 *Target; // r3
  idAI2 *v68; // r3
  double v69; // fp7
  double v70; // fp6
  idAngles *v71; // r3
  int v73; // [sp+8h] [-248h]
  int v74; // [sp+8h] [-248h]
  int v75; // [sp+8h] [-248h]
  bool v76; // [sp+Fh] [-241h]
  bool v77; // [sp+Fh] [-241h]
  bool v78; // [sp+Fh] [-241h]
  const char *v79; // [sp+10h] [-240h]
  const char *v80; // [sp+10h] [-240h]
  const char *v81; // [sp+10h] [-240h]
  int v82; // [sp+14h] [-23Ch]
  int v83; // [sp+14h] [-23Ch]
  int v84; // [sp+14h] [-23Ch]
  int v85; // [sp+18h] [-238h]
  int v86; // [sp+18h] [-238h]
  int v87; // [sp+18h] [-238h]
  int v88; // [sp+1Ch] [-234h]
  int v89; // [sp+1Ch] [-234h]
  int v90; // [sp+1Ch] [-234h]
  int v91; // [sp+20h] [-230h]
  int v92; // [sp+20h] [-230h]
  int v93; // [sp+20h] [-230h]
  int v94; // [sp+24h] [-22Ch]
  int v95; // [sp+24h] [-22Ch]
  int v96; // [sp+24h] [-22Ch]
  int v97; // [sp+28h] [-228h]
  int v98; // [sp+28h] [-228h]
  int v99; // [sp+28h] [-228h]
  int v100; // [sp+2Ch] [-224h]
  int v101; // [sp+2Ch] [-224h]
  int v102; // [sp+2Ch] [-224h]
  int v103; // [sp+30h] [-220h]
  int v104; // [sp+30h] [-220h]
  int v105; // [sp+30h] [-220h]
  int v106; // [sp+34h] [-21Ch]
  int v107; // [sp+34h] [-21Ch]
  int v108; // [sp+34h] [-21Ch]
  int v109; // [sp+38h] [-218h]
  int v110; // [sp+38h] [-218h]
  int v111; // [sp+38h] [-218h]
  int v112; // [sp+3Ch] [-214h]
  int v113; // [sp+3Ch] [-214h]
  int v114; // [sp+3Ch] [-214h]
  int v115; // [sp+40h] [-210h]
  int v116; // [sp+40h] [-210h]
  int v117; // [sp+40h] [-210h]
  int v118; // [sp+44h] [-20Ch]
  int v119; // [sp+44h] [-20Ch]
  int v120; // [sp+44h] [-20Ch]
  int v121; // [sp+48h] [-208h]
  int v122; // [sp+48h] [-208h]
  int v123; // [sp+48h] [-208h]
  int v124; // [sp+4Ch] [-204h]
  int v125; // [sp+4Ch] [-204h]
  int v126; // [sp+4Ch] [-204h]
  int v127; // [sp+50h] [-200h]
  int v128; // [sp+50h] [-200h]
  int v129; // [sp+50h] [-200h]
  int v130; // [sp+58h] [-1F8h]
  int v131; // [sp+58h] [-1F8h]
  int v132; // [sp+58h] [-1F8h]
  int v133; // [sp+60h] [-1F0h]
  int v134; // [sp+60h] [-1F0h]
  int v135; // [sp+60h] [-1F0h]
  idVec3 v136; // [sp+70h] [-1E0h] BYREF
  idVec3 v137; // [sp+80h] [-1D0h] BYREF
  idVec3 v138; // [sp+90h] [-1C0h] BYREF
  idVec3 v139; // [sp+A0h] [-1B0h] BYREF
  idVec3 v140; // [sp+B0h] [-1A0h] BYREF
  idMat3 v141; // [sp+C0h] [-190h] BYREF
  float v142; // [sp+E4h] [-16Ch]
  float v143; // [sp+E8h] [-168h]
  float v144[3]; // [sp+F0h] [-160h] BYREF
  char v145; // [sp+FCh] [-154h] BYREF
  idMat3 v146; // [sp+100h] [-150h] BYREF
  idMat3 v147; // [sp+130h] [-120h] BYREF
  trace_t v148; // [sp+160h] [-F0h] BYREF

  PlayerActivator = idCamera::GetPlayerActivator(this);
  v3 = PlayerActivator;
  if ( PlayerActivator != nullptr )
  {
    presentable = PlayerActivator->presentable;
    if ( presentable != nullptr )
      v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = 0;
    v6 = &v145;
    p_y = &mat2_identity.mat[1].y;
    v8 = 9;
    v137 = vec3_origin;
    do
    {
      ++p_y;
      v6 += 4;
      *(float *)v6 = *p_y;
      --v8;
    }
    while ( v8 != 0 );
    idInteractionCamera::GetCurTransform(this, pos: &v137, axis: &v146);
    y = v137.y;
    z = v137.z;
    this->startPos.x = v137.x;
    this->startPos.y = y;
    this->startPos.z = z;
    this->startAngles = *idMat3::ToAngles(this: &v141, result: (idAngles *)&v146);
    v11 = 0;
    forceTeleportPlayer = this->forceTeleportPlayer;
    if ( this->tryToTeleportPlayer || (v13 = this->forceTeleportPlayer) )
    {
      v136 = v137;
      Physics = idEntity::GetPhysics(this: v3);
      valueFloat = pm_normalviewheight.valueFloat;
      v16 = (float *)Physics->GetGravityNormal(this: Physics);
      v17 = (float)((float)(v16[1] * (float)valueFloat) * (float)0.75);
      v18 = (float)((float)(v16[2] * (float)valueFloat) * (float)0.75);
      v139.x = (float)((float)((float)valueFloat * *v16) * (float)0.75) + v136.x;
      v139.y = v136.y + (float)v17;
      v139.z = (float)v18 + v136.z;
      v19 = idEntity::GetPhysics(this: v3);
      v20 = pm_normalviewheight.valueFloat;
      v21 = (float *)v19->GetGravityNormal(this: v19);
      v22 = (float)((float)(v21[1] * (float)v20) * (float)1.25);
      v23 = (float)((float)(v21[2] * (float)v20) * (float)1.25);
      v138.x = (float)((float)(*v21 * (float)v20) * (float)1.25) + v136.x;
      v138.y = (float)v22 + v136.y;
      v138.z = (float)v23 + v136.z;
      v24 = idEntity::GetPhysics(this: v3);
      v25 = idEntity::GetPhysics(this: v3);
      entityNumber = v3->entityNumber;
      v27 = (idMat3 *)v24->GetAxis(this: v24, a2: 0);
      v28 = v25->GetClipModel(this: v25, a2: 0);
      idClip::Translation(
        this: (idClip *)&v137,
        result: &clientGame->clip,
        a3: &v148,
        start: &v139,
        end: &v138,
        clipModel: v28,
        startAxis: v27,
        clipMask: 265,
        passEntityNumber: v73,
        moveClipModel: v76,
        userName: v79,
        a12: v82,
        a13: v85,
        a14: v88,
        a15: v91,
        a16: v94,
        a17: v97,
        a18: v100,
        a19: v103,
        a20: v106,
        a21: v109,
        a22: v112,
        a23: v115,
        a24: v118,
        a25: v121,
        a26: v124,
        a27: v127,
        a28: entityNumber,
        a29: v130,
        a30: false,
        a31: v133,
        a32: 0);
      if ( v148.fraction < 1.0 )
      {
        v136.z = v148.c.point.z;
        if ( !forceTeleportPlayer )
        {
          v29 = idEntity::GetPhysics(this: v3);
          v30 = (float *)v29->GetGravityNormal(this: v29);
          v31 = (float)(v30[1] * (float)0.25);
          v32 = (float)(v30[2] * (float)0.25);
          v139.x = v136.x - (float)(*v30 * (float)0.25);
          v139.y = v136.y - (float)v31;
          v139.z = v136.z - (float)v32;
          v33 = idEntity::GetPhysics(this: v3);
          v34 = pm_normalviewheight.valueFloat;
          v35 = (float *)v33->GetGravityNormal(this: v33);
          v36 = (float)((float)(v35[1] * (float)v34) * (float)0.1);
          v37 = (float)((float)(v35[2] * (float)v34) * (float)0.1);
          v138.x = v136.x - (float)((float)((float)v34 * *v35) * (float)0.1);
          v138.y = v136.y - (float)v36;
          v138.z = v136.z - (float)v37;
          v38 = idEntity::GetPhysics(this: v3);
          v39 = idEntity::GetPhysics(this: v3);
          v40 = v3->entityNumber;
          v41 = (idMat3 *)v38->GetAxis(this: v38, a2: 0);
          v42 = v39->GetClipModel(this: v39, a2: 0);
          idClip::Translation(
            this: (idClip *)&v137,
            result: &clientGame->clip,
            a3: &v148,
            start: &v139,
            end: &v138,
            clipModel: v42,
            startAxis: v41,
            clipMask: 265,
            passEntityNumber: v74,
            moveClipModel: v77,
            userName: v80,
            a12: v83,
            a13: v86,
            a14: v89,
            a15: v92,
            a16: v95,
            a17: v98,
            a18: v101,
            a19: v104,
            a20: v107,
            a21: v110,
            a22: v113,
            a23: v116,
            a24: v119,
            a25: v122,
            a26: v125,
            a27: v128,
            a28: v40,
            a29: v131,
            a30: false,
            a31: v134,
            a32: 0);
          if ( v148.fraction >= 1.0 )
          {
            v43 = idEntity::GetPhysics(this: v3);
            v44 = (float *)v43->GetOrigin(this: v43, a2: 0);
            v139.x = *v44;
            v139.y = v44[1];
            v139.z = v44[2];
            v138.x = v136.x;
            v138.y = v136.y;
            v138.z = v136.z;
            v45 = idEntity::GetPhysics(this: v3);
            v46 = idEntity::GetPhysics(this: v3);
            v47 = v3->entityNumber;
            v48 = (idMat3 *)v45->GetAxis(this: v45, a2: 0);
            v49 = v46->GetClipModel(this: v46, a2: 0);
            idClip::Translation(
              this: (idClip *)&v137,
              result: &clientGame->clip,
              a3: &v148,
              start: &v139,
              end: &v138,
              clipModel: v49,
              startAxis: v48,
              clipMask: 265,
              passEntityNumber: v75,
              moveClipModel: v78,
              userName: v81,
              a12: v84,
              a13: v87,
              a14: v90,
              a15: v93,
              a16: v96,
              a17: v99,
              a18: v102,
              a19: v105,
              a20: v108,
              a21: v111,
              a22: v114,
              a23: v117,
              a24: v120,
              a25: v123,
              a26: v126,
              a27: v129,
              a28: v47,
              a29: v132,
              a30: false,
              a31: v135,
              a32: 0);
            if ( v148.fraction >= 1.0 )
              forceTeleportPlayer = true;
          }
        }
      }
      v13 = forceTeleportPlayer;
      if ( forceTeleportPlayer )
      {
        v50 = v3->__vftable;
        v51 = idMat3::ToAngles(this: &v141, result: (idAngles *)&v146);
        v50->Teleport(this: v3, a2: &v136, a3: v51);
        *(_BYTE *)(idPlayer::GetBobCycle(this: v3) + 216) = 0;
        idPlayer::CalculateView(this: v3);
      }
      v11 = 1;
    }
    else
    {
      *(_BYTE *)(idPlayer::GetBobCycle(this: v3) + 216) = 0;
      idUCmdTracker::ClearAngles(this: (idUCmdTracker *)(v5 + 45960));
      idUCmdTracker::ClearAngles(this: (idUCmdTracker *)(v5 + 46244));
    }
    v52 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    lerpOutTime = this->lerpOutTime;
    this->startTime = v52;
    this->returningToPlayer = true;
    this->movingToAI = false;
    this->lerpTime = lerpOutTime;
    if ( v13 )
    {
      v3->GetViewTransform(this: v3, a2: (idVec3 *)&v141.mat[1].y, a3: &v147);
      v55 = v141.mat[1].z;
      x = v141.mat[2].x;
      this->destPos.x = v141.mat[1].y;
      this->destPos.y = v55;
    }
    else
    {
      idView::GetViewPos(this: (idView *)(v5 + 16224), origin: (idVec3 *)&v141.mat[1].y, axis: &v147);
      this->destPos.x = this->returnToPos.x;
      this->destPos.y = this->returnToPos.y;
      x = this->returnToPos.z;
    }
    this->destPos.z = x;
    if ( gameLocal->spawnIds.ptr[this->deactivateCallbackAI.spawnId.value & 0x1FFF] == this->deactivateCallbackAI.spawnId.value >> 13 )
    {
      v56 = idEntity::GetPhysics(this: v3);
      value = this->deactivateCallbackAI.spawnId.value;
      v58 = v56;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v59 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v60 = idAI2::CastTo(c: v59);
      }
      else
      {
        v60 = nullptr;
      }
      v61 = idEntity::GetPhysics(this: v60);
      v62 = (float *)v58->GetOrigin(this: v58, a2: 0);
      v63 = (float *)v61->GetOrigin(this: v61, a2: 0);
      v64 = (float)(v63[2] - v62[2]);
      v65 = (float)(v63[1] - v62[1]);
      v140.x = *v63 - *v62;
      v140.z = v64;
      v140.y = v65;
      idVec3::NormalizeFast(this: &v140);
      this->destAngles = *idVec3::ToAngles(this: v141.mat, result: (idAngles *)&v140);
    }
    else
    {
      this->destAngles = *idMat3::ToAngles(this: &v141, result: (idAngles *)&v147);
    }
    p_destAngles = &this->destAngles;
    this->destAngles.roll = 0.0;
    if ( (ai_interactionView_keepPitch.valueInteger != 0 || this->tryToKeepPitch) && v11 != 0 )
    {
      p_destAngles->pitch = this->startAngles.pitch;
    }
    else
    {
      Target = (idAI2 *)idEntity::GetTarget(this, i: 0);
      v68 = idAI2::CastTo(c: Target);
      if ( v68 != nullptr )
      {
        v68->GetEyePos(this: v68, a2: (idVec3 *)v144);
        v69 = (float)(v144[1] - this->destPos.y);
        v70 = (float)(v144[2] - this->destPos.z);
        v141.mat[2].z = v144[0] - this->destPos.x;
        v142 = v69;
        v143 = v70;
        idVec3::NormalizeFast(this: (idVec3 *)&v141.mat[2].z);
        v71 = idVec3::ToAngles(this: v141.mat, result: (idAngles *)&v141.mat[2].z);
        p_destAngles->pitch = v71->pitch;
        this->destAngles.yaw = v71->yaw;
        this->destAngles.roll = v71->roll;
      }
    }
    this->destAngles.roll = 0.0;
    idPlayer::SetViewAngles(this: v3, angles: &this->destAngles, force: true);
    idPlayer::CalculateView(this: v3);
  }
  return 0;
}


// ========================================================================
// ?Event_ReallyDeactivate@idInteractionCamera@@QAA?AVeventVoid@@XZ
// EA  : 0x82D09420
// RVA : 0x00D09420
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idInteractionCamera *__fastcall idInteractionCamera::Event_ReallyDeactivate(
        idInteractionCamera *this,
        idCamera *result)
{
  idPlayer *PlayerActivator; // r3
  idPlayer *v5; // r30
  int v6; // r5
  idPresentable *presentable; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r3
  idPresentable *v11; // r3
  int v12; // r3
  idPresentable *v13; // r3
  idPresentable *v14; // r3
  int v15; // r3
  int fadeVisibilityOver_low; // r10
  idAI2 *v17; // r3
  int v18; // r9
  idAI2 *v19; // r3
  idAI2 *v20; // r3

  PlayerActivator = idCamera::GetPlayerActivator(this: result);
  v5 = PlayerActivator;
  if ( PlayerActivator != nullptr )
  {
    HIBYTE(result[1].spawnOrientation.mat[0].y) = 0;
    BYTE1(result[1].spawnOrientation.mat[0].y) = 1;
    idPlayer::RemoveControl(this: PlayerActivator, entity: result);
    v5->Show(this: v5);
    if ( *(_DWORD *)&result[1].targets.granularity != 0 )
    {
      presentable = v5->presentable;
      if ( presentable != nullptr )
        v8 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v8 = 0;
      idView::SetEnvironmentOverride(this: (idView *)(v8 + 16224), env: nullptr, blendDuration: -1.0, modelIndex: v6);
    }
    v9 = v5->presentable;
    if ( v9 != nullptr )
      v10 = (int)v9->GetPlayerInterface_2(this: v9);
    else
      v10 = 0;
    if ( v10 != -37616 )
    {
      v11 = v5->presentable;
      if ( v11 != nullptr )
        v12 = (int)v11->GetPlayerInterface_2(this: v11);
      else
        v12 = 0;
      idHands::Reset(this: (idHands *)(v12 + 37616), doIntro: false);
    }
    v13 = v5->presentable;
    if ( v13 != nullptr && v13->GetPlayerInterface_2(this: v13) != nullptr )
    {
      v14 = v5->presentable;
      v15 = v14 != nullptr ? (int)v14->GetPlayerInterface_2(this: v14) : 0;
      if ( v15 != -16224 )
        *(_BYTE *)(v15 + 19040) = 1;
    }
    fadeVisibilityOver_low = LODWORD(result[1].renderModelInfo.fadeVisibilityOver);
    if ( gameLocal->spawnIds.ptr[fadeVisibilityOver_low & 0x1FFF] == fadeVisibilityOver_low >> 13 )
    {
      v17 = (idAI2 *)gameLocal->entities.ptr[fadeVisibilityOver_low & 0x1FFF];
      if ( v17 != nullptr && idAI2::CastTo(c: v17) != nullptr )
      {
        v18 = LODWORD(result[1].renderModelInfo.fadeVisibilityOver);
        if ( gameLocal->spawnIds.ptr[v18 & 0x1FFF] == v18 >> 13
          && (v19 = (idAI2 *)gameLocal->entities.ptr[v18 & 0x1FFF]) != nullptr )
        {
          v20 = idAI2::CastTo(c: v19);
        }
        else
        {
          v20 = nullptr;
        }
        idAI2::InteractionCameraDeactivateCallback(this: v20, player: v5);
      }
    }
  }
  idEntity::BecomeInactive(this: result, flags: 1);
  return this;
}


// ========================================================================
// ?DynamicSetup@idInteractionCamera@@QAAXPAVidAI2@@PAVidPlayer@@@Z
// EA  : 0x82D09628
// RVA : 0x00D09628
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idInteractionCamera::DynamicSetup(idInteractionCamera *this, idAI2 *ai, idPlayer *player)
{
  double valueFloat; // fp0
  bool v7; // r8
  char *v8; // r9
  __int16 *p_granularity; // r10
  int i; // ctr
  _DWORD *v11; // r9
  double v12; // fp13
  double v13; // fp12
  __int16 *v14; // r10
  int j; // ctr
  char *v16; // r9
  double v17; // fp13
  double v18; // fp12
  __int16 *v19; // r10
  int k; // ctr
  _DWORD *v21; // r10
  __int16 *v22; // r11
  int m; // ctr
  idPhysics *Physics; // r30
  idPhysics *v25; // r29
  float *v26; // r30
  float *v27; // r3
  double x; // fp12
  double y; // fp11
  idPresentable *presentable; // r11
  double v31; // fp7
  double v32; // fp6
  double z; // fp5
  double v34; // fp4
  double v35; // fp3
  double v36; // fp1
  double v37; // fp10
  double v38; // fp13
  double v41; // fp2
  void (__fastcall *Teleport)(idEntity *, const idVec3 *, const idAngles *); // ctr
  double v43; // fp10
  float v44[4]; // [sp+50h] [-B0h] BYREF
  float v45[3]; // [sp+60h] [-A0h] BYREF
  char v46; // [sp+6Ch] [-94h] BYREF
  float v47; // [sp+70h] [-90h]
  float v48; // [sp+74h] [-8Ch]
  float v49; // [sp+78h] [-88h]
  bool v50; // [sp+90h] [-70h]
  _BYTE v51[16]; // [sp+9Ch] [-64h] BYREF
  float v52; // [sp+ACh] [-54h]
  float v53; // [sp+B0h] [-50h]
  float v54; // [sp+B4h] [-4Ch]
  float v55; // [sp+BCh] [-44h]

  this->dynamicallySetup = true;
  if ( ai != nullptr )
    this->activatingAI.spawnId.value = (gameLocal->spawnIds.ptr[ai->entityNumber] << 13) | ai->entityNumber;
  else
    this->activatingAI.spawnId.value = 0x1FFF;
  ai->GetEyePos(this: ai, a2: (idVec3 *)v44);
  idEntity::ClearTargets(this);
  idEntity::AddTarget(this, target: ai);
  this->tryToTeleportPlayer = true;
  if ( ai_interactionView_UseCvars.valueInteger != 0 )
  {
    this->targetOffset.x = ai_interactionView_xoffset.valueFloat;
    this->targetOffset.y = ai_interactionView_yoffset.valueFloat;
    this->targetOffset.z = ai_interactionView_zoffset.valueFloat;
    this->targetAnglesOffset.pitch = ai_interactionView_PitchOffset.valueFloat;
    this->targetAnglesOffset.yaw = ai_interactionView_YawOffset.valueFloat;
    this->targetAnglesOffset.roll = ai_interactionView_RollOffset.valueFloat;
    valueFloat = ai_interactionView_FOV.valueFloat;
    v7 = ai_interactionView_OffsetToPlayer.valueInteger != 0;
  }
  else
  {
    v8 = &v46;
    p_granularity = &ai->aiEditable.interactions.interactionCameras.granularity;
    for ( i = 9; i != 0; --i )
    {
      p_granularity += 2;
      v8 += 4;
      *(_DWORD *)v8 = *(_DWORD *)p_granularity;
    }
    v11 = v51;
    v12 = v48;
    v13 = v49;
    v14 = &ai->aiEditable.interactions.interactionCameras.granularity;
    this->targetOffset.x = v47;
    this->targetOffset.y = v12;
    this->targetOffset.z = v13;
    for ( j = 9; j != 0; --j )
    {
      v14 += 2;
      *++v11 = *(_DWORD *)v14;
    }
    v16 = &v46;
    v17 = v53;
    v18 = v54;
    v19 = &ai->aiEditable.interactions.interactionCameras.granularity;
    this->targetAnglesOffset.pitch = v52;
    this->targetAnglesOffset.yaw = v17;
    this->targetAnglesOffset.roll = v18;
    for ( k = 9; k != 0; --k )
    {
      v19 += 2;
      v16 += 4;
      *(_DWORD *)v16 = *(_DWORD *)v19;
    }
    v7 = v50;
    v21 = v51;
    v22 = &ai->aiEditable.interactions.interactionCameras.granularity;
    for ( m = 9; m != 0; --m )
    {
      v22 += 2;
      *++v21 = *(_DWORD *)v22;
    }
    valueFloat = v55;
  }
  this->cameraFov = valueFloat;
  if ( v7 )
  {
    Physics = idEntity::GetPhysics(this: ai);
    v25 = idEntity::GetPhysics(this: player);
    v26 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v27 = (float *)v25->GetOrigin(this: v25, a2: 0);
    x = (float)(*v27 - *v26);
    y = (float)(v27[1] - v26[1]);
  }
  else
  {
    presentable = ai->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: ai);
      presentable = ai->presentable;
    }
    x = presentable->axis.mat[0].x;
    y = presentable->axis.mat[0].y;
  }
  v31 = this->targetOffset.x;
  v32 = this->targetOffset.y;
  z = this->targetOffset.z;
  v34 = v44[0];
  v35 = v44[1];
  v36 = v44[2];
  v37 = idMath::FLT_SMALLEST_NON_DENORMAL;
  v38 = ai_interactionView_Distance.valueFloat;
  this->targetOffset = vec3_origin;
  _FP31 = (float)((float)((float)((float)y * (float)y) + (float)((float)x * (float)x)) - (float)v37);
  __asm { fsel      f2, f31, f2, f10 }
  v41 = __frsqrte(_FP2);
  Teleport = this->Teleport;
  v43 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41
                                                                                      * (float)((float)((float)((float)y * (float)y) + (float)((float)x * (float)x))
                                                                                              * (float)0.5))
                                                                              * (float)v41)
                                                                      - (float)1.5)
                                                      * (float)v41)
                                              * (float)((float)((float)((float)y * (float)y)
                                                              + (float)((float)x * (float)x))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v41
                                                                              * (float)((float)((float)((float)y * (float)y)
                                                                                              + (float)((float)x * (float)x))
                                                                                      * (float)0.5))
                                                                      * (float)v41)
                                                              - (float)1.5)
                                              * (float)v41))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v41
                                                      * (float)((float)((float)((float)y * (float)y)
                                                                      + (float)((float)x * (float)x))
                                                              * (float)0.5))
                                              * (float)v41)
                                      - (float)1.5)
                      * (float)v41));
  v45[2] = (float)((float)v36
                 + (float)((float)v38
                         * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)y * (float)y) + (float)((float)x * (float)x)) * (float)0.5)) * (float)v41) - (float)1.5) * (float)v41) * (float)((float)((float)((float)y * (float)y) + (float)((float)x * (float)x)) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)y * (float)y) + (float)((float)x * (float)x)) * (float)0.5)) * (float)v41) - (float)1.5) * (float)v41))
                                                                                                 - (float)1.5)
                                                                                 * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)y * (float)y) + (float)((float)x * (float)x)) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                         * (float)v41))
                                                                         * (float)((float)((float)((float)y * (float)y)
                                                                                         + (float)((float)x * (float)x))
                                                                                 * (float)0.5))
                                                                 * (float)v43)
                                                         - (float)1.5)
                                         * (float)v43)
                                 * (float)0.0)))
         + (float)z;
  v45[0] = (float)v31
         + (float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)y * (float)y) + (float)((float)x * (float)x)) * (float)0.5)) * (float)v41) - (float)1.5) * (float)v41) * (float)((float)((float)((float)y * (float)y) + (float)((float)x * (float)x)) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)y * (float)y) + (float)((float)x * (float)x)) * (float)0.5)) * (float)v41) - (float)1.5) * (float)v41))
                                                                                                 - (float)1.5)
                                                                                 * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)y * (float)y) + (float)((float)x * (float)x)) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                         * (float)v41))
                                                                         * (float)((float)((float)((float)y * (float)y)
                                                                                         + (float)((float)x * (float)x))
                                                                                 * (float)0.5))
                                                                 * (float)v43)
                                                         - (float)1.5)
                                         * (float)v43)
                                 * (float)x)
                         * (float)v38)
                 + (float)v34);
  v45[1] = (float)((float)v35
                 + (float)((float)((float)y
                                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)y * (float)y) + (float)((float)x * (float)x)) * (float)0.5)) * (float)v41) - (float)1.5) * (float)v41) * (float)((float)((float)((float)y * (float)y) + (float)((float)x * (float)x)) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)y * (float)y) + (float)((float)x * (float)x)) * (float)0.5)) * (float)v41) - (float)1.5) * (float)v41))
                                                                                                 - (float)1.5)
                                                                                 * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)y * (float)y) + (float)((float)x * (float)x)) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                         * (float)v41))
                                                                         * (float)((float)((float)((float)y * (float)y)
                                                                                         + (float)((float)x * (float)x))
                                                                                 * (float)0.5))
                                                                 * (float)v43)
                                                         - (float)1.5)
                                         * (float)v43))
                         * (float)v38))
         + (float)v32;
  Teleport(this, a2: (const idVec3 *)v45, a3: &ang_zero);
}


// ========================================================================
// ?RecalcualteDynamicSetupIfNecessary@idInteractionCamera@@IAAXXZ
// EA  : 0x82D099A0
// RVA : 0x00D099A0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idInteractionCamera::RecalcualteDynamicSetupIfNecessary(idInteractionCamera *this)
{
  idAI2 *v2; // r3
  double z; // fp30
  double y; // fp31
  double x; // fp29
  char z_high; // r11
  idAI2 *v7; // r3
  char *v8; // r10
  __int16 *p_granularity; // r11
  int i; // ctr
  idAI2 *v11; // r3
  char *v12; // r10
  __int16 *v13; // r11
  int j; // ctr
  idEntityPtr<idAI2> *p_activatingAI; // r3
  idAI2 *v16; // r3
  idPhysics *Physics; // r30
  idPlayer *PlayerActivator; // r3
  idPhysics *v19; // r29
  float *v20; // r30
  float *v21; // r3
  double v22; // fp9
  idAI2 *v23; // r3
  idPresentable *presentable; // r11
  idAI2 *v25; // r30
  double v26; // fp13
  idVec3 *p_destPos; // r29
  double v28; // fp31
  double v29; // fp30
  double v30; // fp29
  double v31; // fp10
  double v32; // fp9
  double v33; // fp8
  char *v34; // r10
  float *p_y; // r11
  int k; // ctr
  double CurTransform; // fp1
  bool v38; // r30
  __int64 v39; // r8
  int v40; // r3
  int lerpTime; // r10
  int v42; // r11
  int v43; // r3
  double v44; // fp0
  double v45; // fp13
  double v46; // fp12
  idEntity *Target; // r3
  idActor *v48; // r30
  idPhysics *v49; // r3
  int v50; // r3
  float v51; // r7
  float v52; // r6
  idActor *v53; // r3
  double v54; // fp6
  double v55; // fp3
  double v56; // fp1
  idAngles *v57; // r3
  idPhysics *v58; // r3
  idAngles *v59; // r3
  double v60; // fp7
  double v61; // fp6
  idVec3 v62; // [sp+50h] [-C0h] BYREF
  idMat3 v63; // [sp+60h] [-B0h] BYREF
  float v64; // [sp+84h] [-8Ch]
  float v65; // [sp+88h] [-88h]
  float v66[3]; // [sp+90h] [-80h] BYREF
  char v67; // [sp+9Ch] [-74h] BYREF
  idMat3 v68; // [sp+A0h] [-70h] BYREF

  if ( this->dynamicallySetup
    && this->movingToAI
    && idCamera::GetPlayerActivator(this) != nullptr
    && gameLocal->spawnIds.ptr[this->activatingAI.spawnId.value & 0x1FFF] == this->activatingAI.spawnId.value >> 13 )
  {
    v2 = idEntityPtr<idAI2>::operator->(this: &this->activatingAI);
    v2->GetEyePos(this: v2, a2: (idVec3 *)v66);
    v63.mat[0] = vec3_origin;
    if ( ai_interactionView_UseCvars.valueInteger != 0 )
    {
      z = v63.mat[0].z;
      y = v63.mat[0].y;
      x = v63.mat[0].x;
      this->targetOffset.x = ai_interactionView_xoffset.valueFloat;
      this->targetOffset.y = ai_interactionView_yoffset.valueFloat;
      this->targetOffset.z = ai_interactionView_zoffset.valueFloat;
      z_high = ai_interactionView_OffsetToPlayer.valueInteger != 0;
    }
    else
    {
      v7 = idEntityPtr<idAI2>::operator->(this: &this->activatingAI);
      v8 = &v67;
      p_granularity = &v7->aiEditable.interactions.interactionCameras.granularity;
      for ( i = 9; i != 0; --i )
      {
        p_granularity += 2;
        v8 += 4;
        *(_DWORD *)v8 = *(_DWORD *)p_granularity;
      }
      x = v68.mat[0].x;
      y = v68.mat[0].y;
      z = v68.mat[0].z;
      idEntityPtr<idAI2>::operator->(this: &this->activatingAI);
      v11 = idEntityPtr<idAI2>::operator->(this: &this->activatingAI);
      v12 = &v67;
      v13 = &v11->aiEditable.interactions.interactionCameras.granularity;
      for ( j = 9; j != 0; --j )
      {
        v13 += 2;
        v12 += 4;
        *(_DWORD *)v12 = *(_DWORD *)v13;
      }
      z_high = HIBYTE(v68.mat[2].z);
    }
    p_activatingAI = &this->activatingAI;
    if ( z_high != 0 )
    {
      v16 = idEntityPtr<idAI2>::operator->(this: p_activatingAI);
      Physics = idEntity::GetPhysics(this: v16);
      PlayerActivator = idCamera::GetPlayerActivator(this);
      v19 = idEntity::GetPhysics(this: PlayerActivator);
      v20 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v21 = (float *)v19->GetOrigin(this: v19, a2: 0);
      v22 = (float)(v21[1] - v20[1]);
      v62.x = *v21 - *v20;
      v62.y = v22;
    }
    else
    {
      v23 = idEntityPtr<idAI2>::operator->(this: p_activatingAI);
      presentable = v23->presentable;
      v25 = v23;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: v23);
        presentable = v25->presentable;
      }
      v26 = presentable->axis.mat[0].y;
      v62.x = presentable->axis.mat[0].x;
      v62.y = v26;
    }
    v62.z = 0.0;
    idVec3::NormalizeFast(this: &v62);
    p_destPos = &this->destPos;
    v28 = (float)((float)(v66[1] + (float)(v62.y * ai_interactionView_Distance.valueFloat)) + (float)y);
    v29 = (float)((float)(v66[2] + (float)(ai_interactionView_Distance.valueFloat * v62.z)) + (float)z);
    v30 = (float)((float)((float)(v62.x * ai_interactionView_Distance.valueFloat) + v66[0]) + (float)x);
    v31 = (float)(this->destPos.y - (float)v28);
    v32 = (float)(this->destPos.z - (float)v29);
    v33 = (float)(this->destPos.x - (float)v30);
    if ( ai_interactionView_CorrectionDistance.valueFloat < (double)(float)((float)((float)v33 * (float)v33)
                                                                          + (float)((float)((float)v32 * (float)v32)
                                                                                  + (float)((float)v31 * (float)v31))) )
    {
      v34 = &v67;
      p_y = &mat2_identity.mat[1].y;
      v63.mat[0] = vec3_origin;
      for ( k = 9; k != 0; --k )
      {
        ++p_y;
        v34 += 4;
        *(float *)v34 = *p_y;
      }
      CurTransform = idInteractionCamera::GetCurTransform(this, pos: v63.mat, axis: &v68);
      v38 = this->lerpTime <= 250;
      if ( this->lerpTime > 250 )
      {
        v40 = ((int (__fastcall *)(idGameLocal *, int, double))gameLocal->GetGameMs)(
                a1: gameLocal,
                a2: 1,
                a3: CurTransform);
        lerpTime = this->lerpTime;
        v42 = v40 - this->startTime;
        if ( v42 >= 0 )
        {
          if ( v42 > lerpTime )
            v42 = this->lerpTime;
        }
        else
        {
          v42 = 0;
        }
        LODWORD(v39) = v42;
        *(_QWORD *)&v62.x = v39;
        if ( (float)((float)v39 / (float)__SPAIR64__(v42, lerpTime)) < 0.75 )
          this->lerpTime = lerpTime - v42;
        else
          v38 = true;
      }
      if ( v38 )
        this->lerpTime = 250;
      v43 = ((int (__fastcall *)(idGameLocal *, int, double))gameLocal->GetGameMs)(
              a1: gameLocal,
              a2: 1,
              a3: CurTransform);
      v44 = v63.mat[0].x;
      this->startTime = v43;
      v45 = v63.mat[0].y;
      v46 = v63.mat[0].z;
      this->startPos.x = v44;
      this->startPos.y = v45;
      this->startPos.z = v46;
      this->startAngles = *idMat3::ToAngles(this: &v63, result: (idAngles *)&v68);
      p_destPos->x = v30;
      this->destPos.y = v28;
      this->destPos.z = v29;
      Target = idEntity::GetTarget(this, i: 0);
      v48 = (idActor *)Target;
      if ( Target != nullptr )
      {
        v49 = idEntity::GetPhysics(this: Target);
        v50 = (int)v49->GetOrigin(this: v49, a2: 0);
        v51 = *(float *)(v50 + 4);
        v52 = *(float *)(v50 + 8);
        v63.mat[1].y = *(float *)v50;
        v63.mat[1].z = v51;
        v63.mat[2].x = v52;
        if ( (unsigned __int8)idActor::IsTypeOf(c: v48) != 0 )
        {
          v53 = idActor::CastTo(c: v48);
          v53->GetLastEyePos(this: v53, a2: (idVec3 *)&v63.mat[1].y);
        }
        v54 = (float)(this->targetOffset.z + v63.mat[2].x);
        v55 = this->destPos.z;
        v56 = (float)((float)(this->targetOffset.y + v63.mat[1].z) - this->destPos.y);
        v63.mat[2].z = (float)(v63.mat[1].y + this->targetOffset.x) - p_destPos->x;
        v64 = v56;
        v65 = (float)v54 - (float)v55;
        idVec3::NormalizeFast(this: (idVec3 *)&v63.mat[2].z);
        v57 = idVec3::ToAngles(this: v63.mat, result: (idAngles *)&v63.mat[2].z);
      }
      else
      {
        idLib::Warning(fmt: "Missing camera target for '%s'", this->name.data);
        v58 = idEntity::GetPhysics(this);
        v59 = (idAngles *)v58->GetAxis(this: v58, a2: 0);
        v57 = idMat3::ToAngles(this: &v63, result: v59);
      }
      v60 = (float)(this->targetAnglesOffset.yaw + v57->yaw);
      v61 = (float)(this->targetAnglesOffset.roll + v57->roll);
      this->destAngles.pitch = v57->pitch + this->targetAnglesOffset.pitch;
      this->destAngles.yaw = v60;
      this->destAngles.roll = v61;
    }
  }
}


// ========================================================================
// ?SwitchToSell@idInteractionCamera@@QAAXXZ
// EA  : 0x82D09F28
// RVA : 0x00D09F28
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idInteractionCamera::SwitchToSell(idInteractionCamera *this)
{
  int num; // r11
  int value; // r9
  idEntity *v4; // r3
  idAI2 *v5; // r3
  idAI2 *v6; // r30
  idVec3 *v7; // r10
  float *p_y; // r11
  int v9; // ctr
  double y; // fp13
  double z; // fp12
  double v12; // fp0
  double valueFloat; // fp13
  _DWORD *v14; // r9
  __int16 *p_granularity; // r10
  int i; // ctr
  _DWORD *v17; // r9
  __int16 *v18; // r10
  int j; // ctr
  _DWORD *v20; // r10
  __int16 *v21; // r11
  int k; // ctr
  idPhysics *Physics; // r3
  int v24; // r3
  float v25; // r7
  float v26; // r6
  idPhysics *v27; // r3
  double v28; // fp31
  double v29; // fp30
  double v30; // fp29
  float *v31; // r3
  double v32; // fp7
  double v33; // fp3
  double v36; // fp6
  double v37; // fp10
  double v38; // fp8
  double v39; // fp6
  idPhysics *v40; // r3
  float *v41; // r3
  idAngles *v42; // r3
  idGameLocal *v43; // r3
  double v44; // fp8
  double v45; // fp6
  double v46; // fp5
  idGameLocal_vtbl *v47; // r7
  idVec3 v48; // [sp+50h] [-D0h] BYREF
  float v49; // [sp+60h] [-C0h] BYREF
  float v50; // [sp+64h] [-BCh]
  float v51; // [sp+68h] [-B8h]
  idAngles v52; // [sp+70h] [-B0h] BYREF
  idMat3 v53; // [sp+80h] [-A0h] BYREF
  _BYTE v54[16]; // [sp+BCh] [-64h] BYREF
  float v55; // [sp+CCh] [-54h]
  float v56; // [sp+D0h] [-50h]
  float v57; // [sp+D4h] [-4Ch]

  num = this->targets.num;
  this->movingToAI = false;
  if ( num > 0
    && (value = this->targets.list->spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v4 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v5 = (idAI2 *)idEntity::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  v6 = idAI2::CastTo(c: v5);
  if ( v6 != nullptr )
  {
    v7 = &v53.mat[1];
    p_y = &mat2_identity.mat[1].y;
    v9 = 9;
    v48 = vec3_origin;
    do
    {
      ++p_y;
      v7 = (idVec3 *)((char *)v7 + 4);
      v7->x = *p_y;
      --v9;
    }
    while ( v9 != 0 );
    idInteractionCamera::GetCurTransform(this, pos: &v48, axis: (idMat3 *)&v53.mat[1].y);
    y = v48.y;
    z = v48.z;
    this->startPos.x = v48.x;
    this->startPos.y = y;
    this->startPos.z = z;
    this->startAngles = *idMat3::ToAngles(this: &v53, result: (idAngles *)&v53.mat[1].y);
    if ( ai_interactionView_UseCvars.valueInteger != 0 )
    {
      this->targetAnglesOffset.pitch = ai_interactionView_PitchOffset.valueFloat;
      v12 = -1.0;
      this->targetAnglesOffset.yaw = ai_interactionView_YawOffset.valueFloat * (float)-1.0;
      valueFloat = ai_interactionView_RollOffset.valueFloat;
    }
    else
    {
      v14 = v54;
      p_granularity = &v6->aiEditable.interactions.interactionCameras.granularity;
      for ( i = 9; i != 0; --i )
      {
        p_granularity += 2;
        *++v14 = *(_DWORD *)p_granularity;
      }
      v17 = v54;
      this->targetAnglesOffset.pitch = v55;
      v18 = &v6->aiEditable.interactions.interactionCameras.granularity;
      for ( j = 9; j != 0; --j )
      {
        v18 += 2;
        *++v17 = *(_DWORD *)v18;
      }
      v20 = v54;
      v21 = &v6->aiEditable.interactions.interactionCameras.granularity;
      v12 = -1.0;
      this->targetAnglesOffset.yaw = v56 * (float)-1.0;
      for ( k = 9; k != 0; --k )
      {
        v21 += 2;
        *++v20 = *(_DWORD *)v21;
      }
      valueFloat = v57;
    }
    this->targetAnglesOffset.roll = (float)valueFloat * (float)v12;
    Physics = idEntity::GetPhysics(this: v6);
    v24 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v25 = *(float *)v24;
    v26 = *(float *)(v24 + 8);
    v50 = *(float *)(v24 + 4);
    v49 = v25;
    v51 = v26;
    v6->GetLastEyePos(this: v6, a2: (idVec3 *)&v49);
    v27 = idEntity::GetPhysics(this);
    v28 = (float)(this->targetOffset.x + v49);
    v29 = (float)(this->targetOffset.y + v50);
    v30 = (float)(this->targetOffset.z + v51);
    v31 = (float *)v27->GetOrigin(this: v27, a2: 0);
    v32 = (float)((float)v29 - v31[1]);
    v33 = (float)((float)v30 - v31[2]);
    _FP10 = (float)((float)((float)((float)v33 * (float)v33)
                          + (float)((float)((float)((float)v28 - *v31) * (float)((float)v28 - *v31))
                                  + (float)((float)v32 * (float)v32)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f8, f10, f11, f13 }
    v36 = __frsqrte(_FP8);
    v37 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v36
                                                                                        * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)((float)((float)v28 - *v31) * (float)((float)v28 - *v31)) + (float)((float)v32 * (float)v32)))
                                                                                                * (float)0.5))
                                                                                * (float)v36)
                                                                        - (float)1.5)
                                                        * (float)v36)
                                                * (float)((float)((float)((float)v33 * (float)v33)
                                                                + (float)((float)((float)((float)v28 - *v31)
                                                                                * (float)((float)v28 - *v31))
                                                                        + (float)((float)v32 * (float)v32)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v36
                                                                                * (float)((float)((float)((float)v33 * (float)v33)
                                                                                                + (float)((float)((float)((float)v28 - *v31) * (float)((float)v28 - *v31)) + (float)((float)v32 * (float)v32)))
                                                                                        * (float)0.5))
                                                                        * (float)v36)
                                                                - (float)1.5)
                                                * (float)v36))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v36
                                                        * (float)((float)((float)((float)v33 * (float)v33)
                                                                        + (float)((float)((float)((float)v28 - *v31)
                                                                                        * (float)((float)v28 - *v31))
                                                                                + (float)((float)v32 * (float)v32)))
                                                                * (float)0.5))
                                                * (float)v36)
                                        - (float)1.5)
                        * (float)v36));
    v38 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)((float)((float)v28 - *v31) * (float)((float)v28 - *v31)) + (float)((float)v32 * (float)v32))) * (float)0.5)) * (float)v36) - (float)1.5)
                                                                                        * (float)v36)
                                                                                * (float)((float)((float)((float)v33 * (float)v33)
                                                                                                + (float)((float)((float)((float)v28 - *v31) * (float)((float)v28 - *v31)) + (float)((float)v32 * (float)v32)))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)((float)((float)v28 - *v31) * (float)((float)v28 - *v31)) + (float)((float)v32 * (float)v32))) * (float)0.5)) * (float)v36)
                                                                                                - (float)1.5)
                                                                                * (float)v36))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v36
                                                                                        * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)((float)((float)v28 - *v31) * (float)((float)v28 - *v31)) + (float)((float)v32 * (float)v32)))
                                                                                                * (float)0.5))
                                                                                * (float)v36)
                                                                        - (float)1.5)
                                                        * (float)v36))
                                        * (float)((float)((float)((float)v33 * (float)v33)
                                                        + (float)((float)((float)((float)v28 - *v31)
                                                                        * (float)((float)v28 - *v31))
                                                                + (float)((float)v32 * (float)v32)))
                                                * (float)0.5))
                                * (float)v37)
                        - (float)1.5);
    v39 = (float)((float)v38
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v36
                                                                                                * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)((float)((float)v28 - *v31) * (float)((float)v28 - *v31)) + (float)((float)v32 * (float)v32))) * (float)0.5))
                                                                                        * (float)v36)
                                                                                - (float)1.5)
                                                                * (float)v36)
                                                        * (float)((float)((float)((float)v33 * (float)v33)
                                                                        + (float)((float)((float)((float)v28 - *v31)
                                                                                        * (float)((float)v28 - *v31))
                                                                                + (float)((float)v32 * (float)v32)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v36
                                                                                        * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)((float)((float)v28 - *v31) * (float)((float)v28 - *v31)) + (float)((float)v32 * (float)v32)))
                                                                                                * (float)0.5))
                                                                                * (float)v36)
                                                                        - (float)1.5)
                                                        * (float)v36))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v36
                                                                * (float)((float)((float)((float)v33 * (float)v33)
                                                                                + (float)((float)((float)((float)v28 - *v31)
                                                                                                * (float)((float)v28 - *v31))
                                                                                        + (float)((float)v32 * (float)v32)))
                                                                        * (float)0.5))
                                                        * (float)v36)
                                                - (float)1.5)
                                * (float)v36)));
    v52.pitch = (float)((float)v28 - *v31) * (float)v39;
    v52.yaw = (float)v32 * (float)v39;
    v52.roll = (float)v33 * (float)v39;
    v40 = idEntity::GetPhysics(this);
    v41 = (float *)v40->GetOrigin(this: v40, a2: 0);
    this->destPos.x = *v41;
    this->destPos.y = v41[1];
    this->destPos.z = v41[2];
    v42 = idVec3::ToAngles(this: v53.mat, result: &v52);
    v44 = (float)(this->targetAnglesOffset.pitch + v42->pitch);
    v45 = (float)(this->targetAnglesOffset.yaw + v42->yaw);
    v46 = (float)(this->targetAnglesOffset.roll + v42->roll);
    v43 = gameLocal;
    this->destAngles.pitch = v44;
    this->destAngles.yaw = v45;
    v47 = v43->__vftable;
    this->destAngles.roll = v46;
    this->startTime = v47->GetGameMs(this: v43, a2: GAMETIME_SCALED);
    this->lerpTime = ai_interactionView_merchantswitch.valueInteger;
  }
  else
  {
    idLib::Warning(fmt: "could not find ai target in idInteractionCamera::SwitchToSell");
  }
}


// ========================================================================
// ?SwitchToBuy@idInteractionCamera@@QAAXXZ
// EA  : 0x82D0A310
// RVA : 0x00D0A310
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idInteractionCamera::SwitchToBuy(idInteractionCamera *this)
{
  int num; // r11
  int value; // r9
  idEntity *v4; // r3
  idAI2 *v5; // r3
  idAI2 *v6; // r30
  idVec3 *v7; // r10
  float *p_y; // r11
  int v9; // ctr
  double y; // fp13
  double z; // fp12
  double valueFloat; // fp0
  _DWORD *v13; // r9
  __int16 *p_granularity; // r10
  int i; // ctr
  _DWORD *v16; // r9
  __int16 *v17; // r10
  int j; // ctr
  _DWORD *v19; // r10
  __int16 *v20; // r11
  int k; // ctr
  idPhysics *Physics; // r3
  int v23; // r3
  float v24; // r8
  float v25; // r6
  idPhysics *v26; // r3
  double v27; // fp31
  double v28; // fp30
  double v29; // fp29
  float *v30; // r3
  double v31; // fp7
  double v32; // fp3
  double v35; // fp6
  double v36; // fp10
  double v37; // fp8
  double v38; // fp6
  idPhysics *v39; // r3
  float *v40; // r3
  idAngles *v41; // r3
  idGameLocal *v42; // r3
  double v43; // fp8
  double v44; // fp6
  double v45; // fp5
  idGameLocal_vtbl *v46; // r7
  idVec3 v47; // [sp+50h] [-D0h] BYREF
  float v48; // [sp+60h] [-C0h] BYREF
  float v49; // [sp+64h] [-BCh]
  float v50; // [sp+68h] [-B8h]
  idAngles v51; // [sp+70h] [-B0h] BYREF
  idMat3 v52; // [sp+80h] [-A0h] BYREF
  _BYTE v53[16]; // [sp+BCh] [-64h] BYREF
  float v54; // [sp+CCh] [-54h]
  float v55; // [sp+D0h] [-50h]
  float v56; // [sp+D4h] [-4Ch]

  num = this->targets.num;
  this->movingToAI = false;
  if ( num > 0
    && (value = this->targets.list->spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v4 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v5 = (idAI2 *)idEntity::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  v6 = idAI2::CastTo(c: v5);
  if ( v6 != nullptr )
  {
    v7 = &v52.mat[1];
    p_y = &mat2_identity.mat[1].y;
    v9 = 9;
    v47 = vec3_origin;
    do
    {
      ++p_y;
      v7 = (idVec3 *)((char *)v7 + 4);
      v7->x = *p_y;
      --v9;
    }
    while ( v9 != 0 );
    idInteractionCamera::GetCurTransform(this, pos: &v47, axis: (idMat3 *)&v52.mat[1].y);
    y = v47.y;
    z = v47.z;
    this->startPos.x = v47.x;
    this->startPos.y = y;
    this->startPos.z = z;
    this->startAngles = *idMat3::ToAngles(this: &v52, result: (idAngles *)&v52.mat[1].y);
    if ( ai_interactionView_UseCvars.valueInteger != 0 )
    {
      this->targetAnglesOffset.pitch = ai_interactionView_PitchOffset.valueFloat;
      this->targetAnglesOffset.yaw = ai_interactionView_YawOffset.valueFloat;
      valueFloat = ai_interactionView_RollOffset.valueFloat;
    }
    else
    {
      v13 = v53;
      p_granularity = &v6->aiEditable.interactions.interactionCameras.granularity;
      for ( i = 9; i != 0; --i )
      {
        p_granularity += 2;
        *++v13 = *(_DWORD *)p_granularity;
      }
      v16 = v53;
      this->targetAnglesOffset.pitch = v54;
      v17 = &v6->aiEditable.interactions.interactionCameras.granularity;
      for ( j = 9; j != 0; --j )
      {
        v17 += 2;
        *++v16 = *(_DWORD *)v17;
      }
      v19 = v53;
      this->targetAnglesOffset.yaw = v55;
      v20 = &v6->aiEditable.interactions.interactionCameras.granularity;
      for ( k = 9; k != 0; --k )
      {
        v20 += 2;
        *++v19 = *(_DWORD *)v20;
      }
      valueFloat = v56;
    }
    this->targetAnglesOffset.roll = valueFloat;
    Physics = idEntity::GetPhysics(this: v6);
    v23 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v24 = *(float *)(v23 + 4);
    v25 = *(float *)(v23 + 8);
    v48 = *(float *)v23;
    v49 = v24;
    v50 = v25;
    v6->GetLastEyePos(this: v6, a2: (idVec3 *)&v48);
    v26 = idEntity::GetPhysics(this);
    v27 = (float)(this->targetOffset.x + v48);
    v28 = (float)(this->targetOffset.y + v49);
    v29 = (float)(this->targetOffset.z + v50);
    v30 = (float *)v26->GetOrigin(this: v26, a2: 0);
    v31 = (float)((float)v28 - v30[1]);
    v32 = (float)((float)v29 - v30[2]);
    _FP10 = (float)((float)((float)((float)v32 * (float)v32)
                          + (float)((float)((float)((float)v27 - *v30) * (float)((float)v27 - *v30))
                                  + (float)((float)v31 * (float)v31)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f8, f10, f11, f13 }
    v35 = __frsqrte(_FP8);
    v36 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35
                                                                                        * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)((float)v27 - *v30) * (float)((float)v27 - *v30)) + (float)((float)v31 * (float)v31)))
                                                                                                * (float)0.5))
                                                                                * (float)v35)
                                                                        - (float)1.5)
                                                        * (float)v35)
                                                * (float)((float)((float)((float)v32 * (float)v32)
                                                                + (float)((float)((float)((float)v27 - *v30)
                                                                                * (float)((float)v27 - *v30))
                                                                        + (float)((float)v31 * (float)v31)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v35
                                                                                * (float)((float)((float)((float)v32 * (float)v32)
                                                                                                + (float)((float)((float)((float)v27 - *v30) * (float)((float)v27 - *v30)) + (float)((float)v31 * (float)v31)))
                                                                                        * (float)0.5))
                                                                        * (float)v35)
                                                                - (float)1.5)
                                                * (float)v35))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v35
                                                        * (float)((float)((float)((float)v32 * (float)v32)
                                                                        + (float)((float)((float)((float)v27 - *v30)
                                                                                        * (float)((float)v27 - *v30))
                                                                                + (float)((float)v31 * (float)v31)))
                                                                * (float)0.5))
                                                * (float)v35)
                                        - (float)1.5)
                        * (float)v35));
    v37 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)((float)v27 - *v30) * (float)((float)v27 - *v30)) + (float)((float)v31 * (float)v31))) * (float)0.5)) * (float)v35) - (float)1.5)
                                                                                        * (float)v35)
                                                                                * (float)((float)((float)((float)v32 * (float)v32)
                                                                                                + (float)((float)((float)((float)v27 - *v30) * (float)((float)v27 - *v30)) + (float)((float)v31 * (float)v31)))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)((float)v27 - *v30) * (float)((float)v27 - *v30)) + (float)((float)v31 * (float)v31))) * (float)0.5)) * (float)v35)
                                                                                                - (float)1.5)
                                                                                * (float)v35))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v35
                                                                                        * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)((float)v27 - *v30) * (float)((float)v27 - *v30)) + (float)((float)v31 * (float)v31)))
                                                                                                * (float)0.5))
                                                                                * (float)v35)
                                                                        - (float)1.5)
                                                        * (float)v35))
                                        * (float)((float)((float)((float)v32 * (float)v32)
                                                        + (float)((float)((float)((float)v27 - *v30)
                                                                        * (float)((float)v27 - *v30))
                                                                + (float)((float)v31 * (float)v31)))
                                                * (float)0.5))
                                * (float)v36)
                        - (float)1.5);
    v38 = (float)((float)v37
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35
                                                                                                * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)((float)v27 - *v30) * (float)((float)v27 - *v30)) + (float)((float)v31 * (float)v31))) * (float)0.5))
                                                                                        * (float)v35)
                                                                                - (float)1.5)
                                                                * (float)v35)
                                                        * (float)((float)((float)((float)v32 * (float)v32)
                                                                        + (float)((float)((float)((float)v27 - *v30)
                                                                                        * (float)((float)v27 - *v30))
                                                                                + (float)((float)v31 * (float)v31)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v35
                                                                                        * (float)((float)((float)((float)v32 * (float)v32) + (float)((float)((float)((float)v27 - *v30) * (float)((float)v27 - *v30)) + (float)((float)v31 * (float)v31)))
                                                                                                * (float)0.5))
                                                                                * (float)v35)
                                                                        - (float)1.5)
                                                        * (float)v35))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v35
                                                                * (float)((float)((float)((float)v32 * (float)v32)
                                                                                + (float)((float)((float)((float)v27 - *v30)
                                                                                                * (float)((float)v27 - *v30))
                                                                                        + (float)((float)v31 * (float)v31)))
                                                                        * (float)0.5))
                                                        * (float)v35)
                                                - (float)1.5)
                                * (float)v35)));
    v51.pitch = (float)((float)v27 - *v30) * (float)v38;
    v51.yaw = (float)v31 * (float)v38;
    v51.roll = (float)v32 * (float)v38;
    v39 = idEntity::GetPhysics(this);
    v40 = (float *)v39->GetOrigin(this: v39, a2: 0);
    this->destPos.x = *v40;
    this->destPos.y = v40[1];
    this->destPos.z = v40[2];
    v41 = idVec3::ToAngles(this: v52.mat, result: &v51);
    v43 = (float)(this->targetAnglesOffset.pitch + v41->pitch);
    v44 = (float)(this->targetAnglesOffset.yaw + v41->yaw);
    v45 = (float)(this->targetAnglesOffset.roll + v41->roll);
    v42 = gameLocal;
    this->destAngles.pitch = v43;
    this->destAngles.yaw = v44;
    v46 = v42->__vftable;
    this->destAngles.roll = v45;
    this->startTime = v46->GetGameMs(this: v42, a2: GAMETIME_SCALED);
    this->lerpTime = ai_interactionView_merchantswitch.valueInteger;
  }
  else
  {
    idLib::Warning(fmt: "could not find ai target in idInteractionCamera::SwitchToBuy");
  }
}


// ========================================================================
// ??0idUtilityCamera@@QAA@XZ
// EA  : 0x82D0A6D8
// RVA : 0x00D0A6D8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idUtilityCamera *__fastcall idUtilityCamera::idUtilityCamera(idUtilityCamera *this)
{
  int v2; // ctr
  float *p_z; // r10
  float *p_y; // r11

  idEntity::idEntity(this);
  this->activator.spawnId.value = 0x1FFF;
  this->__vftable = (idUtilityCamera_vtbl *)&idUtilityCamera::`vftable';
  this->targetPos.x = 0.0;
  this->targetPos.y = 0.0;
  this->targetPos.z = 0.0;
  v2 = 9;
  this->distance = 128.0;
  this->offset.x = 0.0;
  this->offset.y = 0.0;
  p_z = &this->cachedViewOrg.z;
  this->offset.z = 0.0;
  this->angles.pitch = -20.0;
  p_y = &mat2_identity.mat[1].y;
  this->angles.yaw = 0.0;
  this->angles.roll = 0.0;
  this->lastAngles = ang_zero;
  this->oldBindSet = 0;
  this->numFrames = 0;
  this->lastPos.x = 0.0;
  this->lastPos.y = 0.0;
  this->lastPos.z = 0.0;
  this->lastTargetPos = vec3_origin;
  this->cachedViewOrg.x = 0.0;
  this->cachedViewOrg.y = 0.0;
  this->cachedViewOrg.z = 0.0;
  do
  {
    *++p_z = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  return this;
}


// ========================================================================
// ??0idRotatableCamera@@QAA@XZ
// EA  : 0x82D0A828
// RVA : 0x00D0A828
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idRotatableCamera *__fastcall idRotatableCamera::idRotatableCamera(idRotatableCamera *this)
{
  int v2; // ctr
  float *p_w; // r10
  float *p_y; // r11
  float z; // r7

  idUtilityCamera::idUtilityCamera(this);
  this->__vftable = (idRotatableCamera_vtbl *)&idRotatableCamera::`vftable';
  this->startingAngles.pitch = 0.0;
  this->startingAngles.yaw = 0.0;
  this->startingAngles.roll = 0.0;
  this->goalAngles.pitch = 0.0;
  this->goalAngles.yaw = 0.0;
  this->goalAngles.roll = 0.0;
  this->clampedMinAngles.pitch = -75.0;
  this->clampedMinAngles.yaw = -110.0;
  this->clampedMinAngles.roll = -45.0;
  this->clampedMaxAngles.pitch = 75.0;
  this->clampedMaxAngles.yaw = 110.0;
  this->clampedMaxAngles.roll = 45.0;
  this->doesCameraReactToMovement = true;
  v2 = 9;
  this->reactionToMovement.pitch = -1.0;
  this->reactionToMovement.yaw = -1.0;
  this->reactionToMovement.roll = -1.5;
  this->reactionToMovementSpeed = 0.2;
  this->goalForTurning.pitch = 1.0;
  this->goalForTurning.yaw = 1.0;
  this->goalForTurning.roll = 1.0;
  this->isActive = false;
  this->playerWasNoTarget = false;
  this->turnToGoalSpeed = 0.015;
  *((_BYTE *)this + 1028) = *((_BYTE *)this + 1028) & 0xF | 0x40;
  this->currentUserAngles.pitch = 0.0;
  this->currentUserAngles.yaw = 0.0;
  p_w = &this->averageAxis.w;
  this->currentUserAngles.roll = 0.0;
  this->currentReactionAngles.pitch = 0.0;
  this->currentReactionAngles.yaw = 0.0;
  this->currentReactionAngles.roll = 0.0;
  this->currentTurningAngles.pitch = 0.0;
  this->currentTurningAngles.yaw = 0.0;
  this->currentTurningAngles.roll = 0.0;
  this->previousThinkTime = 0;
  this->lastPosition.x = 0.0;
  this->lastPosition.y = 0.0;
  this->lastPosition.z = 0.0;
  p_y = &mat2_identity.mat[1].y;
  this->lastMoveAxis = quat_identity;
  this->averageAxis = quat_identity;
  do
  {
    *++p_w = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->playerStartPos.x = vec3_origin.x;
  this->playerStartPos.y = vec3_origin.y;
  z = vec3_origin.z;
  this->suppressMovement = 1.0;
  this->playerStartPos.z = z;
  return this;
}


// ========================================================================
// ?OnActivate@idRotatableCamera@@UAAXPAVidEntity@@@Z
// EA  : 0x82D0AA20
// RVA : 0x00D0AA20
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idRotatableCamera::OnActivate(idRotatableCamera *this, idEntity *activator_)
{
  idEventReceiver v2[2]; // [sp+50h] [-20h] BYREF

  if ( this->isActive )
    idEventReceiver::ProcessEvent(this: v2, result: (idEventArg *)this, ev: &EV_Deactivate);
  else
    idCamera::Activate(this, activator_);
}


// ========================================================================
// ??0idEntityCamera@@QAA@XZ
// EA  : 0x82D0AA78
// RVA : 0x00D0AA78
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idEntityCamera *__fastcall idEntityCamera::idEntityCamera(idEntityCamera *this)
{
  idUtilityCamera::idUtilityCamera(this);
  this->__vftable = (idEntityCamera_vtbl *)&idEntityCamera::`vftable';
  this->targetEnt.spawnId.value = 0x1FFF;
  this->useViewOffset = true;
  this->viewOffset.x = 0.0;
  this->viewOffset.y = 0.0;
  this->viewOffset.z = 0.0;
  this->lastEntityOrigin.x = 0.0;
  this->lastEntityOrigin.y = 0.0;
  this->lastEntityOrigin.z = 0.0;
  idEntity::SetName(this, newName: idEntityCamera::DEFAULT_ENTITY_CAM_NAME);
  return this;
}


// ========================================================================
// __unwind$509420
// EA  : 0x82D0AB1C
// RVA : 0x00D0AB1C
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_509420()
{
  int v0; // r12

  idEntityCamera::~idEntityCamera(this: *(idEntityCamera **)(v0 - 112 + 132));
}


// ========================================================================
// ?SetTargetEntity@idEntityCamera@@UAAXPAVidEntity@@@Z
// EA  : 0x82D0AB48
// RVA : 0x00D0AB48
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idEntityCamera::SetTargetEntity(idEntityCamera *this, idEntity *ent)
{
  idGameLocal *v3; // r11
  idEntity *v5; // r3
  idEntity *v6; // r3

  v3 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->targetEnt.spawnId.value & 0x1FFF] == this->targetEnt.spawnId.value >> 13
    && (v5 = gameLocal->entities.ptr[this->targetEnt.spawnId.value & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
    v3 = gameLocal;
  }
  else
  {
    v6 = nullptr;
  }
  if ( ent != v6 )
  {
    this->numFrames = 0;
    v3 = gameLocal;
  }
  if ( ent != nullptr )
    this->targetEnt.spawnId.value = (v3->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  else
    this->targetEnt.spawnId.value = 0x1FFF;
}


// ========================================================================
// ?Think@idEntityCamera@@UAAXXZ
// EA  : 0x82D0ABF8
// RVA : 0x00D0ABF8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idEntityCamera::Think(idEntityCamera *this)
{
  int value; // r10
  idEntity *v3; // r3
  idPlayer *v4; // r3
  idPlayer *v5; // r3
  idPlayer *v6; // r31
  idPresentable *presentable; // r3
  int v8; // r3
  int UCmdTracker2; // r30
  int v10; // r3

  value = this->activator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v4 = (idPlayer *)idEntity::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = idPlayer::CastTo(c: v4);
  v6 = v5;
  if ( v5 != nullptr )
  {
    presentable = v5->presentable;
    if ( presentable != nullptr )
      v8 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v8 = 0;
    if ( (*(_BYTE *)(v8 + 46321) & 0x80) == 0 )
    {
      UCmdTracker2 = idPlayer::GetUCmdTracker2(this: v6);
      v10 = idPlayer::GetUCmdTracker2(this: v6);
      this->HandleUserCmds(this, a2: (const usercmd_t *)(v10 + 8), a3: (const usercmd_t *)(UCmdTracker2 + 68));
    }
  }
  this->CalculateViewParms(this);
}


// ========================================================================
// ??0idTrailerCamera@@QAA@XZ
// EA  : 0x82D0ACE8
// RVA : 0x00D0ACE8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idTrailerCamera *__fastcall idTrailerCamera::idTrailerCamera(idTrailerCamera *this)
{
  char v2; // r3
  float w; // r6

  idEntityCamera::idEntityCamera(this);
  this->__vftable = (idTrailerCamera_vtbl *)&idTrailerCamera::`vftable';
  this->prevCmd.buttons = 0;
  this->prevCmd.buttons2 = 0;
  this->prevCmd.forwardmove = 0;
  this->prevCmd.pos[2] = 0.0;
  this->prevCmd.rightmove = 0;
  this->prevCmd.pos[1] = 0.0;
  this->prevCmd.upmove = 0;
  this->prevCmd.pos[0] = 0.0;
  this->prevCmd.angles[2] = 0;
  this->prevCmd.angles[1] = 0;
  this->prevCmd.angles[0] = 0;
  this->prevCmd.clientGameFrame = 0;
  this->prevCmd.yaw = 0;
  this->prevCmd.pitch = 0;
  this->prevCmd.roll = 0;
  this->prevCmd.predictionStateBits = 0;
  this->prevCmd.vehicleThrottle = 0;
  this->prevCmd.serverGameTime = 0;
  this->prevCmd.fireCount = 0;
  this->prevCmd.fireAngles[1] = 0;
  this->prevCmd.fireAngles[0] = 0;
  this->prevCmd.firePos[2] = 0;
  v2 = *((_BYTE *)&this->prevCmd + 9);
  this->prevCmd.firePos[1] = 0;
  this->prevCmd.firePos[0] = 0;
  this->prevCmd.speed = 0;
  *((_BYTE *)&this->prevCmd + 9) = v2 & 0x3F;
  this->fov = g_fov.valueFloat;
  this->dof.x = vec4_origin.x;
  this->dof.y = vec4_origin.y;
  this->dof.z = vec4_origin.z;
  w = vec4_origin.w;
  this->xyzSpeed = 1.0;
  this->rotationSpeed = 1.0;
  this->dof.w = w;
  this->dutchAngle = 0.0;
  return this;
}


// ========================================================================
// ?HandleUserCmds@idTrailerCamera@@UAAXABVusercmd_t@@0@Z
// EA  : 0x82D0AE58
// RVA : 0x00D0AE58
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idTrailerCamera::HandleUserCmds(
        idTrailerCamera *this,
        const usercmd_t *prevcmd,
        const usercmd_t *usercmd)
{
  int v4; // r6
  __int64 v6; // r9
  __int64 v7; // r7
  double v8; // fp0
  double v9; // fp12
  double v10; // fp12
  double pitch; // fp11
  double v12; // fp10
  double yaw; // fp9
  idAngles *p_angles; // r30
  double v15; // fp13
  double v16; // fp7
  double v17; // fp11
  double distance; // fp0
  double valueFloat; // fp13
  int value; // r9
  idEntity *v21; // r3
  idEntity *v22; // r4
  double z; // fp7
  double v24; // fp5
  double v25; // fp3
  int EntitiesTouchingLine; // r3
  int v27; // r28
  double v28; // fp30
  int *v29; // r29
  idPhysics *Physics; // r3
  float *v31; // r3
  double v32; // fp10
  double v33; // fp8
  double v34; // fp0
  int buttons; // r11
  double v36; // fp0
  double v37; // fp12
  double v38; // fp12
  idVec3 v39; // [sp+58h] [-F8h] BYREF
  int v40[34]; // [sp+70h] [-E0h] BYREF

  v4 = (unsigned __int16)prevcmd->angles[0];
  HIDWORD(v6) = usercmd->angles[0] - (__int16)v4;
  LODWORD(v6) = usercmd->angles[1] - prevcmd->angles[1];
  LODWORD(v7) = HIDWORD(v6);
  v8 = (float)((float)v6 * idMath::M_DEG2RAD);
  v9 = (float)((float)((float)v7 * (float)-1.0) * idMath::M_DEG2RAD);
  HIDWORD(v7) = 0x82000000;
  if ( v8 >= -1.0 )
  {
    if ( v8 > 1.0 )
      v8 = 1.0;
  }
  else
  {
    v8 = -1.0;
  }
  v10 = (float)(this->rotationSpeed * (float)v9);
  pitch = this->angles.pitch;
  v12 = (float)(this->rotationSpeed * (float)v8);
  yaw = this->angles.yaw;
  p_angles = &this->angles;
  this->angles.roll = this->angles.roll;
  v15 = 85.0;
  v16 = (float)((float)pitch + (float)v10);
  this->angles.pitch = (float)pitch + (float)v10;
  this->angles.yaw = (float)yaw + (float)v12;
  if ( v16 > 85.0 || (v15 = -85.0, v16 < -85.0) )
    p_angles->pitch = v15;
  if ( usercmd->forwardmove > 0 && this->GetTargetEntity(this) != nullptr )
  {
    v17 = (float)-(float)((float)(this->xyzSpeed * (float)0.025) - (float)1.0);
LABEL_14:
    this->distance = (float)v17 * this->distance;
    goto LABEL_15;
  }
  if ( (unsigned __int8)usercmd->forwardmove >= 0x80u && this->GetTargetEntity(this) != nullptr )
  {
    v17 = (float)((float)(this->xyzSpeed * (float)0.025) + (float)1.0);
    goto LABEL_14;
  }
LABEL_15:
  distance = this->distance;
  valueFloat = cam_maxDist.valueFloat;
  if ( distance > cam_maxDist.valueFloat || (valueFloat = 8.0, distance < 8.0) )
    this->distance = valueFloat;
  if ( (this->prevCmd.buttons & 0x200000) != 0 && (usercmd->buttons & 0x200000) == 0 )
  {
    this->SetTargetEntity(this, a2: nullptr);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "g_showHud", a3: true, a4: 0);
    idLib::Printf(fmt: "TCAM: Free movement\n");
  }
  if ( (this->prevCmd.buttons & 0x8000000) != 0 && (usercmd->buttons & 0x8000000) == 0 )
  {
    value = this->activator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v21 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v22 = idEntity::CastTo(c: v21);
    }
    else
    {
      v22 = nullptr;
    }
    this->SetTargetEntity(this, a2: v22);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "g_showHud", a3: false, a4: 0);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "hands_show", a3: false, a4: 0);
    this->distance = 128.0;
    this->offset.z = 0.0;
    this->offset.y = 0.0;
    this->offset.x = 0.0;
    p_angles->pitch = -20.0;
    this->angles.yaw = 0.0;
    this->angles.roll = 0.0;
    this->lastAngles.roll = 0.0;
    this->lastAngles.yaw = 0.0;
    this->lastAngles.pitch = 0.0;
    this->dutchAngle = 0.0;
    this->fov = 80.0;
    this->rotationSpeed = 1.0;
    this->xyzSpeed = 1.0;
    this->viewOffset.z = 0.0;
    this->viewOffset.y = 0.0;
    this->viewOffset.x = 0.0;
    idLib::Printf(fmt: "TCAM: Reset\n");
  }
  if ( (this->prevCmd.buttons & 0x40) != 0 && (usercmd->buttons & 0x40) == 0 && this->GetTargetEntity(this) == nullptr )
  {
    z = this->cachedViewOrg.z;
    v24 = (float)(this->cachedViewAxis.mat[0].z * (float)512.0);
    v25 = (float)(this->cachedViewOrg.y + (float)(this->cachedViewAxis.mat[0].y * (float)512.0));
    v39.x = (float)(this->cachedViewAxis.mat[0].x * (float)512.0) + this->cachedViewOrg.x;
    v39.y = v25;
    v39.z = (float)z + (float)v24;
    EntitiesTouchingLine = idClip::GetEntitiesTouchingLine(
                             this: &clientGame->clip,
                             start: &this->cachedViewOrg,
                             end: &v39,
                             clipMask: 110080,
                             entityList: v40,
                             maxCount: 32);
    if ( EntitiesTouchingLine <= 0 )
    {
      idLib::Printf(fmt: "TCAM: didn't trace to anything interesting\n");
    }
    else
    {
      v27 = EntitiesTouchingLine - 1;
      v28 = 9999.0;
      if ( EntitiesTouchingLine - 1 > 0 )
      {
        v29 = &v40[v27];
        do
        {
          Physics = idEntity::GetPhysics(this: gameLocal->entities.ptr[*v29]);
          v31 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v32 = (float)(v31[1] - this->cachedViewOrg.y);
          v33 = (float)(v31[2] - this->cachedViewOrg.z);
          v34 = __fsqrts((float)((float)((float)(*v31 - this->cachedViewOrg.x) * (float)(*v31 - this->cachedViewOrg.x))
                               + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))));
          if ( v34 < v28 )
            v28 = v34;
          --v27;
          --v29;
        }
        while ( v27 > 0 );
      }
      cvarSystem->SetCVarBool(this: cvarSystem, a2: "g_showHud", a3: false, a4: 0);
      this->SetTargetEntity(this, a2: gameLocal->entities.ptr[v40[v27]]);
      idLib::Printf(fmt: "TCAM: targeting %s\n", gameLocal->entities.ptr[v40[v27]]->name.data);
    }
  }
  buttons = usercmd->buttons;
  if ( (usercmd->buttons & 4) != 0 )
  {
    this->offset.z = -(float)((float)(this->xyzSpeed * (float)2.0) - this->offset.z);
    return;
  }
  LODWORD(v7) = usercmd->upmove;
  v36 = (float)v7;
  if ( v36 == 127.0 )
  {
    this->offset.z = (float)(this->xyzSpeed * (float)2.0) + this->offset.z;
    return;
  }
  if ( (buttons & 0x80) != 0 )
  {
    v37 = (float)(this->xyzSpeed - (float)0.0099999998);
    this->xyzSpeed = this->xyzSpeed - (float)0.0099999998;
    if ( v37 <= 0.0 )
      this->xyzSpeed = 0.001;
LABEL_46:
    idLib::Printf(fmt: "TCAM: xyz speed set to %2.4f\n", this->xyzSpeed);
    return;
  }
  if ( v36 == -127.0 )
  {
    v38 = (float)(this->xyzSpeed + (float)0.0099999998);
    this->xyzSpeed = this->xyzSpeed + (float)0.0099999998;
    if ( v38 > 4.0 )
      this->xyzSpeed = 4.0;
    goto LABEL_46;
  }
  if ( (buttons & 8) != 0 )
  {
    this->dutchAngle = this->xyzSpeed + this->dutchAngle;
  }
  else if ( (buttons & 1) != 0 )
  {
    this->dutchAngle = this->dutchAngle - this->xyzSpeed;
  }
}


// ========================================================================
// ??0idTownGarageCamera@@QAA@XZ
// EA  : 0x82D0B520
// RVA : 0x00D0B520
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idTownGarageCamera *__fastcall idTownGarageCamera::idTownGarageCamera(idTownGarageCamera *this)
{
  idEntityCamera::idEntityCamera(this);
  this->gui = nullptr;
  this->__vftable = (idTownGarageCamera_vtbl *)&idTownGarageCamera::`vftable';
  this->tunerGui = nullptr;
  this->tunerVehicleGui = nullptr;
  this->renderSchematic = false;
  this->garageManager = nullptr;
  this->exitTownName.allocedAndFlag = 20;
  this->exitTownName.data = this->exitTownName.baseBuffer;
  this->exitTownName.len = 0;
  this->exitTownName.baseBuffer[0] = 0;
  this->exitTownImage = nullptr;
  this->zoomTime = 500;
  this->cameraFov = 60.0;
  this->exitLocation.spawnId.value = 0x1FFF;
  this->exitTarget.spawnId.value = 0x1FFF;
  this->wastelandExitMap.allocedAndFlag = 20;
  this->wastelandExitMap.data = this->wastelandExitMap.baseBuffer;
  this->wastelandExitMap.len = 0;
  this->wastelandExitMap.baseBuffer[0] = 0;
  this->wastelandExitLocation.allocedAndFlag = 20;
  this->wastelandExitLocation.len = 0;
  this->wastelandExitLocation.data = this->wastelandExitLocation.baseBuffer;
  this->wastelandExitLocation.baseBuffer[0] = 0;
  this->currentState = GARAGECAMERASTATE_CAR;
  this->zoomStartTime = -1;
  this->activatedTime = 0;
  this->tiresAnim = nullptr;
  this->superchargerAnim = nullptr;
  this->suspensionAnim = nullptr;
  this->boosterAnim = nullptr;
  this->grillAnim = nullptr;
  this->weaponsAnim = nullptr;
  this->flagAnim = nullptr;
  this->themeAnim = nullptr;
  this->transmissionAnim = nullptr;
  this->engineAnim = nullptr;
  this->armorAnim = nullptr;
  this->rippersAnim = nullptr;
  this->magnetAnim = nullptr;
  this->useViewOffset = false;
  idStr::operator=(this: &this->exitTownName, text: &byte_8200D768);
  return this;
}


// ========================================================================
// __unwind$510073
// EA  : 0x82D0B65C
// RVA : 0x00D0B65C
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_510073()
{
  int v0; // r12

  idEntityCamera::~idEntityCamera(this: *(idEntityCamera **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$510074
// EA  : 0x82D0B684
// RVA : 0x00D0B684
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_510074()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 996));
}


// ========================================================================
// __unwind$510075
// EA  : 0x82D0B6B0
// RVA : 0x00D0B6B0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_510075()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 1048));
}


// ========================================================================
// __unwind$510076
// EA  : 0x82D0B6DC
// RVA : 0x00D0B6DC
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_510076()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 1080));
}


// ========================================================================
// ?InternalDeactivate@idTownGarageCamera@@MAA_NXZ
// EA  : 0x82D0B880
// RVA : 0x00D0B880
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idTownGarageCamera::InternalDeactivate(idTownGarageCamera *this)
{
  int value; // r9
  idEntity *v3; // r3
  idTownGarageManager *v4; // r3
  idTownGarageManager *v5; // r3

  if ( this->targets.num > 0
    && (value = this->targets.list->spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v4 = (idTownGarageManager *)idEntity::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = idTownGarageManager::CastTo(c: v4);
  this->garageManager = v5;
  if ( v5 != nullptr )
    idTownGarageManager::DeactivateCars(this: v5);
  return 1;
}


// ========================================================================
// ?CinematicDone@idCinematicCamera@@QAAXVidColor@@@Z
// EA  : 0x82D0BAC8
// RVA : 0x00D0BAC8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCinematicCamera::CinematicDone(
        idCinematicCamera *this,
        __int64 color,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  idPlayer *PlayerActivator; // r3
  idPlayer *v14; // r28
  idPresentable *presentable; // r3
  int v16; // r3
  int value; // r9
  idEntity *v18; // r3
  idEntity *v19; // r4
  BOOL hidePlayerHands; // r11
  idPresentable *v21; // r3
  int v22; // r3
  idPresentable *v23; // r3
  int v24; // r3
  idPresentable *v25; // r3
  int v26; // r3
  idPresentable *v27; // r3
  int v28; // r3
  const idAngles *v29; // r3
  idPhysics *Physics; // r31
  idPhysics *v31; // r29
  double v32; // fp31
  float *v33; // r3
  double v34; // fp5
  double v35; // fp4
  double y; // fp11
  double z; // fp10
  idPlayerHud::hudState_t prevHudState; // r31
  idPlayerHud *PlayerHud; // r3
  int v40; // r9
  idEntity *v41; // r3
  idEntity *v42; // r3
  idSWF *gui; // r3
  float v44[4]; // [sp+50h] [-70h] BYREF
  idMat3 v45[2]; // [sp+60h] [-60h] BYREF

  a11 = *(__int64 *)((char *)&color + 4);
  a12 = color;
  PlayerActivator = idCamera::GetPlayerActivator(this);
  v14 = PlayerActivator;
  if ( PlayerActivator != nullptr )
  {
    *(_BYTE *)&PlayerActivator->flags = (2 * this->playerTakesDamageState) & 2
                                      | *(_BYTE *)&PlayerActivator->flags & 0xFD;
    if ( cine_captureFrames.valueInteger != 0 )
    {
      cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_fixedtic", a3: 0, a4: 0);
      cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_captureFrames", a3: 0, a4: 0);
    }
    presentable = v14->presentable;
    if ( presentable != nullptr )
      v16 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v16 = 0;
    idHands::ClearPendingAction(this: (idHands *)(v16 + 37616));
    value = this->activator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v18 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v19 = idEntity::CastTo(c: v18);
    }
    else
    {
      v19 = nullptr;
    }
    this->ActivateTargets(this, a2: v19);
    if ( this->doTimeScale )
      ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
        a1: cvarSystem,
        a2: "timescale",
        a3: 1.0);
    hidePlayerHands = this->hidePlayerHands;
    this->active = false;
    this->suspended = false;
    this->guiNotificationPending = false;
    if ( hidePlayerHands )
    {
      v21 = v14->presentable;
      v22 = v21 != nullptr ? (int)v21->GetPlayerInterface_2(this: v21) : 0;
      if ( v22 != -37616 )
      {
        v23 = v14->presentable;
        if ( v23 != nullptr )
          v24 = (int)v23->GetPlayerInterface_2(this: v23);
        else
          v24 = 0;
        idHands::Show(this: (idHands *)(v24 + 37616), hideReason: HAND_HIDE_GENERIC);
      }
    }
    if ( this->fadeInOnReturn )
    {
      v25 = v14->presentable;
      if ( v25 != nullptr )
        v26 = (int)v25->GetPlayerInterface_2(this: v25);
      else
        v26 = 0;
      *(_QWORD *)(v26 + 19068) = a11;
      *(_QWORD *)(v26 + 19076) = a12;
      *((float *)&a12 + 1) = 0.0;
      v27 = v14->presentable;
      if ( v27 != nullptr )
        v28 = (int)v27->GetPlayerInterface_2(this: v27);
      else
        v28 = 0;
      idView::Fade(this: (idView *)(v28 + 16224), color: (const idVec4 *)&a11, time: 1000);
    }
    if ( this->setPlayerAnglesOnReturn )
    {
      v29 = idMat3::ToAngles(this: v45, result: (idAngles *)&this->current.focus.viewAxis);
      idPlayer::SetViewAngles(this: v14, angles: v29, force: false);
    }
    if ( this->setPlayerPositionOnReturn )
    {
      Physics = idEntity::GetPhysics(this: v14);
      v31 = idEntity::GetPhysics(this: v14);
      v32 = (float)((float)0.1 - v14->GetEyeOffset(this: (idActor *)v45, result: (const idVec3 *)v14)->z);
      v33 = (float *)Physics->GetGravityNormal(this: Physics);
      v34 = (float)(v33[1] * (float)v32);
      v35 = (float)(v33[2] * (float)v32);
      y = this->current.movement.viewOrigin.y;
      z = this->current.movement.viewOrigin.z;
      v44[0] = this->current.movement.viewOrigin.x - (float)(*v33 * (float)v32);
      v44[1] = (float)y - (float)v34;
      v44[2] = (float)z - (float)v35;
      v31->SetOrigin(this: v31, a2: (const idVec3 *)v44, a3: -1);
    }
    if ( !this->showPlayerHud )
    {
      prevHudState = this->prevHudState;
      PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: v14);
      idPlayerHud::SetHudState(this: PlayerHud, state: prevHudState);
    }
    v40 = this->activator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v40 & 0x1FFF] == v40 >> 13 && (v41 = gameLocal->entities.ptr[v40 & 0x1FFF]) != nullptr )
      v42 = idEntity::CastTo(c: v41);
    else
      v42 = nullptr;
    v42->Show(this: v42);
    idEventReceiver::ProcessEvent(this: (idEventReceiver *)v45, result: (idEventArg *)this, ev: &EV_Deactivate);
  }
  gui = this->gui;
  if ( gui != nullptr )
    idSWF::Activate(this: gui, b: false);
}


// ========================================================================
// ?Unsuspend@idCinematicCamera@@QAA_NXZ
// EA  : 0x82D0BEC0
// RVA : 0x00D0BEC0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idCinematicCamera::Unsuspend(idCinematicCamera *this)
{
  if ( !this->active
    || !this->suspended
    || gameLocal->spawnIds.ptr[this->activator.spawnId.value & 0x1FFF] != this->activator.spawnId.value >> 13 )
  {
    return 0;
  }
  this->suspended = false;
  return 1;
}


// ========================================================================
// ?InitStates@idSlowMotionCamera@@IAAXXZ
// EA  : 0x82D0BF20
// RVA : 0x00D0BF20
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idSlowMotionCamera::InitStates(idSlowMotionCamera *this)
{
  int v2; // r30
  double v3; // fp1
  idEntity *v4; // r3
  idPhysics *Physics; // r3
  idPhysics *v6; // r3
  int v7; // [sp+54h] [-2Ch]

  v2 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_NORMAL);
  this->startTime = v2;
  v3 = idSlowMotionCamera::DetermineTotalTime(this);
  this->currentTime = v2;
  v7 = (int)(float)((float)v3 * (float)1000.0);
  this->endTime = v7 + v2;
  this->totalTime = v7;
  Physics = idEntity::GetPhysics(this: v4);
  this->current.movement.viewOrigin = *Physics->GetOrigin(this: Physics, a2: 0);
  this->current.movement.frameLerp.duration = 0.0;
  this->current.movement.frameLerp.easeInTime = 0.0;
  this->current.movement.frameLerp.easeOutTime = 0.0;
  *(_DWORD *)&this->current.movement.frameLerp.looping = 0;
  this->current.movement.frameLerp.startTimeOfs = 0;
  this->current.movement.timing.duration = 0.0;
  this->current.movement.timing.easeInTime = 0.0;
  this->current.movement.timing.easeOutTime = 0.0;
  *(_DWORD *)&this->current.movement.timing.looping = 0;
  this->current.movement.timing.startTimeOfs = 0;
  v6 = idEntity::GetPhysics(this);
  this->current.focus.viewAxis = *v6->GetAxis(this: v6, a2: 0);
  this->current.focus.lastKnownPosition.z = 0.0;
  this->current.focus.lastKnownPosition.y = 0.0;
  this->current.focus.lastKnownPosition.x = 0.0;
  this->current.focus.frameLerp.duration = 0.0;
  this->current.focus.frameLerp.easeInTime = 0.0;
  this->current.focus.frameLerp.easeOutTime = 0.0;
  *(_DWORD *)&this->current.focus.frameLerp.looping = 0;
  this->current.focus.frameLerp.startTimeOfs = 0;
  this->current.timeScale.scale = 1.0;
  this->current.timeScale.timing.duration = 0.0;
  this->current.timeScale.timing.easeInTime = 0.0;
  this->current.timeScale.timing.easeOutTime = 0.0;
  *(_DWORD *)&this->current.timeScale.timing.looping = 0;
  this->current.timeScale.timing.startTimeOfs = 0;
  this->current.fovZoom.angle = 80.0;
  this->current.fovZoom.timing.duration = 0.0;
  this->current.fovZoom.timing.easeInTime = 0.0;
  this->current.fovZoom.timing.easeOutTime = 0.0;
  *(_DWORD *)&this->current.fovZoom.timing.looping = 0;
  this->current.fovZoom.timing.startTimeOfs = 0;
  this->current.depthOfField.blurStart = -1.0;
  this->current.depthOfField.timing.duration = 0.0;
  this->current.depthOfField.timing.easeInTime = 0.0;
  this->current.depthOfField.timing.easeOutTime = 0.0;
  *(_DWORD *)&this->current.depthOfField.timing.looping = 0;
  this->current.depthOfField.timing.startTimeOfs = 0;
  this->current.renderParms.fogScale = 0.000049999999;
  this->current.renderParms.fogColor.g = 0.43000001;
  this->current.renderParms.fogColor.r = 0.2;
  this->current.renderParms.fogColor.b = 0.5;
  this->current.renderParms.fogColor.a = 0.0;
  this->current.renderParms.timing.duration = 0.0;
  this->current.renderParms.timing.easeInTime = 0.0;
  this->current.renderParms.timing.easeOutTime = 0.0;
  *(_DWORD *)&this->current.renderParms.timing.looping = 0;
  this->current.renderParms.timing.startTimeOfs = 0;
  idDeclCameraTrigger::idCameraTriggerState::operator=(this: &this->previous, __that: &this->current);
}


// ========================================================================
// ?CinematicDone@idSlowMotionCamera@@QAAXVidColor@@@Z
// EA  : 0x82D0C170
// RVA : 0x00D0C170
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSlowMotionCamera::CinematicDone(
        idSlowMotionCamera *this,
        __int64 color,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  idPlayer *activatingPlayer; // r11
  idPresentable *presentable; // r3
  int v15; // r3
  int value; // r9
  idEntity *v17; // r3
  idEntity *v18; // r4
  __int64 v19; // r4
  BOOL hidePlayerHands; // r6
  idPresentable *v21; // r3
  int v22; // r3
  idPresentable *v23; // r3
  int v24; // r3
  idPresentable *v25; // r3
  int v26; // r3
  idPlayer *v27; // r11
  idPresentable *v28; // r3
  int v29; // r3
  const idAngles *v30; // r3
  idPhysics *Physics; // r30
  idPhysics *v32; // r27
  double v33; // fp30
  float *v34; // r3
  double v35; // fp5
  double v36; // fp4
  double y; // fp11
  double z; // fp10
  idPlayerHud::hudState_t prevHudState; // r30
  idPlayerHud *PlayerHud; // r3
  int v41; // r9
  char v42; // r30
  idEntity *v43; // r3
  idVehicle_Car *v44; // r3
  idVehicle_Car *v45; // r3
  idEntity *Activator; // r3
  idSWF *gui; // r3
  float v48[4]; // [sp+50h] [-70h] BYREF
  idMat3 v49; // [sp+60h] [-60h] BYREF

  activatingPlayer = this->activatingPlayer;
  a11 = *(__int64 *)((char *)&color + 4);
  a12 = color;
  if ( activatingPlayer != nullptr )
  {
    if ( cine_captureFrames.valueInteger != 0 )
    {
      cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_fixedtic", a3: 0, a4: 0);
      cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_captureFrames", a3: 0, a4: 0);
    }
    presentable = this->activatingPlayer->presentable;
    if ( presentable != nullptr )
      v15 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v15 = 0;
    idHands::ClearPendingAction(this: (idHands *)(v15 + 37616));
    value = this->activator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v17 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v18 = idEntity::CastTo(c: v17);
    }
    else
    {
      v18 = nullptr;
    }
    this->ActivateTargets(this, a2: v18);
    v19 = ((__int64 (__fastcall *)(idGameLocal *))gameLocal->GetGameTimeManager)(a1: gameLocal);
    idGameTimeManager::SetTimeScale(
      this: (idGameTimeManager *)HIDWORD(v19),
      scale: 1.0,
      type: (const gameTimeType_t)v19,
      a4: 1);
    hidePlayerHands = this->hidePlayerHands;
    this->active = false;
    this->suspended = false;
    this->guiNotificationPending = false;
    if ( hidePlayerHands )
    {
      v21 = this->activatingPlayer->presentable;
      v22 = v21 != nullptr ? (int)v21->GetPlayerInterface_2(this: v21) : 0;
      if ( v22 != -37616 )
      {
        v23 = this->activatingPlayer->presentable;
        if ( v23 != nullptr )
          v24 = (int)v23->GetPlayerInterface_2(this: v23);
        else
          v24 = 0;
        idHands::Show(this: (idHands *)(v24 + 37616), hideReason: HAND_HIDE_GENERIC);
      }
    }
    if ( this->fadeInOnReturn )
    {
      v25 = this->activatingPlayer->presentable;
      if ( v25 != nullptr )
        v26 = (int)v25->GetPlayerInterface_2(this: v25);
      else
        v26 = 0;
      *(_QWORD *)(v26 + 19068) = a11;
      *(_QWORD *)(v26 + 19076) = a12;
      v27 = this->activatingPlayer;
      *((float *)&a12 + 1) = 0.0;
      v28 = v27->presentable;
      if ( v28 != nullptr )
        v29 = (int)v28->GetPlayerInterface_2(this: v28);
      else
        v29 = 0;
      idView::Fade(this: (idView *)(v29 + 16224), color: (const idVec4 *)&a11, time: 1000);
    }
    if ( this->setPlayerAnglesOnReturn )
    {
      v30 = idMat3::ToAngles(this: &v49, result: (idAngles *)&this->current.focus.viewAxis);
      idPlayer::SetViewAngles(this: this->activatingPlayer, angles: v30, force: false);
    }
    if ( this->setPlayerPositionOnReturn )
    {
      Physics = idEntity::GetPhysics(this: this->activatingPlayer);
      v32 = idEntity::GetPhysics(this: this->activatingPlayer);
      v33 = (float)((float)0.1
                  - *(float *)(((int (__fastcall *)(idMat3 *))this->activatingPlayer->GetEyeOffset)(a1: &v49) + 8));
      v34 = (float *)Physics->GetGravityNormal(this: Physics);
      v35 = (float)(v34[1] * (float)v33);
      v36 = (float)(v34[2] * (float)v33);
      y = this->current.movement.viewOrigin.y;
      z = this->current.movement.viewOrigin.z;
      v48[0] = this->current.movement.viewOrigin.x - (float)(*v34 * (float)v33);
      v48[1] = (float)y - (float)v35;
      v48[2] = (float)z - (float)v36;
      v32->SetOrigin(this: v32, a2: (const idVec3 *)v48, a3: -1);
    }
    if ( !this->showPlayerHud )
    {
      prevHudState = this->prevHudState;
      PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: this->activatingPlayer);
      idPlayerHud::SetHudState(this: PlayerHud, state: prevHudState);
    }
    v41 = this->activator.spawnId.value;
    v42 = 1;
    if ( gameLocal->spawnIds.ptr[v41 & 0x1FFF] == v41 >> 13 && (v43 = gameLocal->entities.ptr[v41 & 0x1FFF]) != nullptr )
      v44 = (idVehicle_Car *)idEntity::CastTo(c: v43);
    else
      v44 = nullptr;
    v45 = idVehicle_Car::CastTo(c: v44);
    if ( v45 != nullptr && ((double (__fastcall *)(idVehicle_Car *))v45->GetHealth)(a1: v45) <= 0.0 )
      v42 = 0;
    if ( v42 != 0
      && gameLocal->spawnIds.ptr[this->activator.spawnId.value & 0x1FFF] == this->activator.spawnId.value >> 13 )
    {
      Activator = idCamera::GetActivator(this);
      Activator->Show(this: Activator);
    }
    idEventReceiver::ProcessEvent(this: (idEventReceiver *)&v49, result: (idEventArg *)this, ev: &EV_Deactivate);
  }
  gui = this->gui;
  if ( gui != nullptr )
    idSWF::Activate(this: gui, b: false);
}


// ========================================================================
// ?GetInputSettings@idSlowMotionCamera@@UAA?AUinputSettings_t@@PAVidPlayer@@@Z
// EA  : 0x82D0C5C0
// RVA : 0x00D0C5C0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idSlowMotionCamera *__fastcall idSlowMotionCamera::GetInputSettings(
        idSlowMotionCamera *this,
        inputSettings_t *result,
        idPlayer *player)
{
  float joyYawSpeed; // r10
  idEntity *v5; // r3
  idEntity *v6; // r4

  joyYawSpeed = result[28].joyYawSpeed;
  if ( gameLocal->spawnIds.ptr[LOWORD(joyYawSpeed) & 0x1FFF] == SLODWORD(joyYawSpeed) >> 13
    && (v5 = gameLocal->entities.ptr[LOWORD(joyYawSpeed) & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  ((void (__fastcall *)(idSlowMotionCamera *))v6->GetInputSettings)(a1: this);
  return this;
}


// ========================================================================
// ?Trigger_ActivateEnt@idCinematicCamera@@QAAXAAUtrigActivateEnt_t@1@H@Z
// EA  : 0x82D0C660
// RVA : 0x00D0C660
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idCinematicCamera::Trigger_ActivateEnt(
        idSlowMotionCamera *this,
        idDeclCameraTrigger::idTrigActivateEnt *activateEnt,
        int startTimeOfs)
{
  int num; // r11
  int v6; // r27
  int v7; // r30
  idGameLocal *v8; // r11
  int value; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3
  idEntity *v12; // r31
  int v13; // r9
  idEntity *v14; // r3
  idEntity *v15; // r3

  num = activateEnt->entity.num;
  if ( num != 0 )
  {
    v6 = 0;
    if ( num > 0 )
    {
      v7 = 0;
      v8 = gameLocal;
      do
      {
        if ( v8->spawnIds.ptr[activateEnt->entity.list[v7].spawnId.value & 0x1FFF] == activateEnt->entity.list[v7].spawnId.value >> 13 )
        {
          value = this->activator.spawnId.value;
          if ( v8->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v10 = v8->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v11 = idEntity::CastTo(c: v10);
            v8 = gameLocal;
            v12 = v11;
          }
          else
          {
            v12 = nullptr;
          }
          v13 = activateEnt->entity.list[v7].spawnId.value;
          if ( v8->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13 && (v14 = v8->entities.ptr[v13 & 0x1FFF]) != nullptr )
            v15 = idEntity::CastTo(c: v14);
          else
            v15 = nullptr;
          idEntity::Activate(this: v15, activator: v12);
          v8 = gameLocal;
        }
        ++v6;
        ++v7;
      }
      while ( v6 < activateEnt->entity.num );
    }
  }
}


// ========================================================================
// ?Unsuspend@idSlowMotionCamera@@QAA_NXZ
// EA  : 0x82D0C770
// RVA : 0x00D0C770
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idSlowMotionCamera::Unsuspend(idSlowMotionCamera *this)
{
  if ( !this->active
    || !this->suspended
    || gameLocal->spawnIds.ptr[this->activator.spawnId.value & 0x1FFF] != this->activator.spawnId.value >> 13 )
  {
    return 0;
  }
  this->suspended = false;
  return 1;
}


// ========================================================================
// ?InternalDeactivate@idSlowMotionCamera@@MAA_NXZ
// EA  : 0x82D0C7D0
// RVA : 0x00D0C7D0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idSlowMotionCamera::InternalDeactivate(idSlowMotionCamera *this)
{
  int value; // r10
  idEntity *v3; // r3
  idPlayer *v4; // r3
  idPresentable *presentable; // r3
  int v6; // r3
  idPresentable *v7; // r3
  int v8; // r3
  const idAngles *v9; // r3
  idPhysics *Physics; // r30
  idPhysics *v11; // r29
  double v12; // fp31
  float *v13; // r3
  double v14; // fp6
  double v15; // fp5
  double y; // fp12
  double z; // fp11
  idPlayerHud *PlayerHud; // r3
  idPresentable *v19; // r3
  int v20; // r3
  idPlayer *activatingPlayer; // r8
  idPresentable *v22; // r3
  int v23; // r3
  float v25[4]; // [sp+50h] [-60h] BYREF
  idMat3 v26; // [sp+60h] [-50h] BYREF

  if ( this->activatingPlayer != nullptr )
  {
    value = this->activator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v4 = (idPlayer *)idEntity::CastTo(c: v3);
    }
    else
    {
      v4 = nullptr;
    }
    if ( this->activatingPlayer != v4 )
    {
      if ( this->hidePlayer )
        this->activatingPlayer->Show(this: this->activatingPlayer);
      if ( this->hidePlayerHands )
      {
        presentable = this->activatingPlayer->presentable;
        v6 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
        if ( v6 != -37616 )
        {
          v7 = this->activatingPlayer->presentable;
          if ( v7 != nullptr )
            v8 = (int)v7->GetPlayerInterface_2(this: v7);
          else
            v8 = 0;
          idHands::Show(this: (idHands *)(v8 + 37616), hideReason: HAND_HIDE_GENERIC);
        }
      }
      if ( this->setPlayerAnglesOnReturn )
      {
        v9 = idMat3::ToAngles(this: &v26, result: (idAngles *)&this->current.focus.viewAxis);
        idPlayer::SetViewAngles(this: this->activatingPlayer, angles: v9, force: false);
      }
      if ( this->setPlayerPositionOnReturn )
      {
        Physics = idEntity::GetPhysics(this: this->activatingPlayer);
        v11 = idEntity::GetPhysics(this: this->activatingPlayer);
        v12 = -*(float *)(((int (__fastcall *)(idMat3 *))this->activatingPlayer->GetEyeOffset)(a1: &v26) + 8);
        v13 = (float *)Physics->GetGravityNormal(this: Physics);
        v14 = (float)(v13[1] * (float)v12);
        v15 = (float)(v13[2] * (float)v12);
        y = this->current.movement.viewOrigin.y;
        z = this->current.movement.viewOrigin.z;
        v25[0] = this->current.movement.viewOrigin.x - (float)(*v13 * (float)v12);
        v25[1] = (float)y - (float)v14;
        v25[2] = (float)z - (float)v15;
        v11->SetOrigin(this: v11, a2: (const idVec3 *)v25, a3: -1);
      }
      if ( !this->showPlayerHud )
      {
        PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: this->activatingPlayer);
        idPlayerHud::SetHudState(this: PlayerHud, state: HUDSTATE_ALL);
      }
      if ( this->fadeInOnReturn )
      {
        v19 = this->activatingPlayer->presentable;
        if ( v19 != nullptr )
          v20 = (int)v19->GetPlayerInterface_2(this: v19);
        else
          v20 = 0;
        *(idColor *)(v20 + 19068) = idColor::colorBlack;
        activatingPlayer = this->activatingPlayer;
        v26.mat[1].y = 0.0;
        v26.mat[1].z = 0.0;
        v26.mat[2].x = 0.0;
        v26.mat[2].y = 0.0;
        v22 = activatingPlayer->presentable;
        if ( v22 != nullptr )
          v23 = (int)v22->GetPlayerInterface_2(this: v22);
        else
          v23 = 0;
        idView::Fade(this: (idView *)(v23 + 16224), color: (const idVec4 *)&v26.mat[1].y, time: 1000);
      }
    }
  }
  idEntity::BecomeInactive(this, flags: 1);
  return 1;
}


// ========================================================================
// ?MoveOrigin@idSlowMotionCamera@@IAAXAAVidVec3@@@Z
// EA  : 0x82D0CAA0
// RVA : 0x00D0CAA0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idSlowMotionCamera::MoveOrigin(
        idSlowMotionCamera *this,
        idVec3 *viewOrigin,
        __int64 a3,
        long double a4)
{
  idDeclCameraTrigger::idSplineCurve *v6; // r11
  float *v7; // r3
  double v8; // fp7
  double v9; // fp6
  double x; // fp0
  double y; // fp13
  double z; // fp12
  idVehicle_Car *v13; // r3
  idEntity *v14; // r29
  idVehicle_Car *v15; // r3
  idPhysics *Physics; // r27
  idPhysics *v17; // r3
  float *v18; // r26
  float *v19; // r3
  double v20; // fp7
  double v21; // fp6
  idPhysics *v22; // r27
  idPhysics *v23; // r29
  double v24; // fp31
  double v25; // fp30
  double v26; // fp29
  float *v27; // r3
  double v28; // fp28
  double v29; // fp27
  double v30; // fp26
  float *v31; // r3
  double v32; // fp12
  double v33; // fp11
  double TimeLerpFraction; // fp31
  idEntity *v35; // r29
  double v36; // fp8
  double v37; // fp5
  idPhysics *v38; // r3
  float *v39; // r3
  double v40; // fp11
  double v41; // fp10
  idVehicle *v42; // r3
  idVehicle *v43; // r3
  double v44; // fp0
  double v45; // fp13
  double v46; // fp12
  long double v47; // fp2
  long double v48; // fp2
  double v49; // fp0
  long double v50; // fp2
  double v51; // fp12
  double v52; // fp11
  double v53; // fp3
  double v54; // fp2
  double v55; // fp13
  double v56; // fp12
  idVec3 v57; // [sp+50h] [-1BD0h] BYREF
  idVec3 v58; // [sp+60h] [-1BC0h] BYREF
  idVec3 v59; // [sp+70h] [-1BB0h] BYREF
  idTypesafeNumber<float,enum RadiansUnique_t> v60; // [sp+7Ch] [-1BA4h] BYREF
  idVec3 *p_viewOrigin; // [sp+80h] [-1BA0h] BYREF
  int v62; // [sp+88h] [-1B98h] BYREF
  idMat3 v63; // [sp+A0h] [-1B80h] BYREF
  idView v64; // [sp+D0h] [-1B50h] BYREF

  switch ( this->current.movement.moveType )
  {
    case CAM_MOVE_SPLINE:
      v6 = &this->splines.list[this->current.movement.spline.sc];
      if ( v6 != nullptr )
      {
        v7 = (float *)((int (__fastcall *)(int *, double))v6->curve->GetCurrentValue)(
                        a1: &v62,
                        a2: this->current.movement.spline.dist);
        v8 = (float)(this->current.movement.additionalOffset.y + v7[1]);
        v9 = (float)(this->current.movement.additionalOffset.z + v7[2]);
        this->current.movement.position.x = this->current.movement.additionalOffset.x + *v7;
        this->current.movement.position.y = v8;
        this->current.movement.position.z = v9;
      }
      goto LABEL_4;
    case CAM_MOVE_POSITION:
      x = (float)(this->current.movement.additionalOffset.x + this->current.movement.position.x);
      y = (float)(this->current.movement.position.y + this->current.movement.additionalOffset.y);
      z = (float)(this->current.movement.position.z + this->current.movement.additionalOffset.z);
      goto LABEL_20;
    case CAM_MOVE_ENTITY:
      v13 = (idVehicle_Car *)idEntityPtr<idEntity const>::operator->(this: &this->current.movement.entity);
      v14 = v13;
      if ( v13 != nullptr )
      {
        v15 = idVehicle_Car::CastTo(c: v13);
        if ( v15 != nullptr && v15->destroyed )
        {
          this->current.movement.moveType = CAM_MOVE_POSITION;
          this->current.movement.additionalOffset = vec3_origin;
        }
        if ( this->current.movement.moveType != CAM_MOVE_POSITION )
        {
          Physics = idEntity::GetPhysics(this);
          v17 = idEntity::GetPhysics(this: v14);
          v18 = (float *)v17->GetOrigin(this: v17, a2: 0);
          v19 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v20 = (float)(v18[1] - v19[1]);
          v21 = (float)(v18[2] - v19[2]);
          v58.x = *v18 - *v19;
          v58.y = v20;
          v58.z = v21;
          idVec3::NormalizeFast(this: &v58);
          v22 = idEntity::GetPhysics(this: v14);
          v23 = idEntity::GetPhysics(this: v14);
          v24 = (float)(v58.x * this->current.movement.scalarOffset);
          v25 = (float)(v58.y * this->current.movement.scalarOffset);
          v26 = (float)(v58.z * this->current.movement.scalarOffset);
          v27 = (float *)v22->GetAxis(this: v22, a2: 0);
          v28 = (float)((float)(*v27 * this->current.movement.entityOffset.x)
                      + (float)((float)(v27[3] * this->current.movement.entityOffset.y)
                              + (float)(v27[6] * this->current.movement.entityOffset.z)));
          v29 = (float)((float)(v27[7] * this->current.movement.entityOffset.z)
                      + (float)((float)(v27[1] * this->current.movement.entityOffset.x)
                              + (float)(v27[4] * this->current.movement.entityOffset.y)));
          v30 = (float)((float)(v27[8] * this->current.movement.entityOffset.z)
                      + (float)((float)(v27[2] * this->current.movement.entityOffset.x)
                              + (float)(v27[5] * this->current.movement.entityOffset.y)));
          v31 = (float *)v23->GetOrigin(this: v23, a2: 0);
          *((double *)&a4 + 1) = v31[2];
          *(double *)&a4 = (float)(v31[1] + (float)v29);
          v32 = (float)(this->current.movement.additionalOffset.y + (float)(v31[1] + (float)v29));
          v33 = (float)(this->current.movement.additionalOffset.z + (float)(v31[2] + (float)v30));
          this->current.movement.position.x = (float)(this->current.movement.additionalOffset.x
                                                    + (float)(*v31 + (float)v28))
                                            + (float)v24;
          this->current.movement.position.y = (float)v32 + (float)v25;
          this->current.movement.position.z = (float)v33 + (float)v26;
        }
        x = this->current.movement.position.x;
        y = this->current.movement.position.y;
        z = this->current.movement.position.z;
      }
      else
      {
LABEL_4:
        x = this->current.movement.position.x;
        y = this->current.movement.position.y;
        z = this->current.movement.position.z;
      }
      goto LABEL_20;
    case CAM_MOVE_VEHICLE_DEFAULT:
      idView::idView(this: &v64);
      v42 = (idVehicle *)idEntityPtr<idEntity const>::operator->(this: &this->current.movement.entity);
      v43 = idVehicle::CastTo(c: v42);
      if ( v43 != nullptr )
      {
        idVehicle::GetDriverView(this: v43, origin: &v57, axis: &v63, fov_x: (float *)&p_viewOrigin, view: &v64);
        idView::~idView(this: &v64);
LABEL_21:
        if ( this->current.movement.frameLerp.duration <= 0.0 )
        {
          v55 = v57.y;
          v56 = v57.z;
          viewOrigin->x = v57.x;
          viewOrigin->y = v55;
          viewOrigin->z = v56;
        }
        else
        {
          *(double *)&v47 = idSlowMotionCamera::GetTimeLerpFraction(this, timeLerpHelper: a3, a3: a4);
          if ( *(double *)&v47 > 0.5 )
          {
            *(double *)&v47 = (float)((float)((float)((float)1.0 - (float)*(double *)&v47) * (float)120.0)
                                    * idMath::M_DEG2RAD);
            v50 = cos(x: v47);
            v49 = (float)*(double *)&v50;
          }
          else
          {
            *(double *)&v47 = (float)((float)((float)*(double *)&v47 * (float)120.0) * idMath::M_DEG2RAD);
            v48 = cos(x: v47);
            v49 = (float)((float)1.0 - (float)*(double *)&v48);
          }
          v51 = this->previous.movement.viewOrigin.y;
          v52 = this->previous.movement.viewOrigin.z;
          v53 = (float)((float)(v57.y - this->previous.movement.viewOrigin.y) * (float)v49);
          v54 = (float)((float)(v57.z - this->previous.movement.viewOrigin.z) * (float)v49);
          viewOrigin->x = this->previous.movement.viewOrigin.x
                        + (float)((float)(v57.x - this->previous.movement.viewOrigin.x) * (float)v49);
          viewOrigin->y = (float)v51 + (float)v53;
          viewOrigin->z = (float)v52 + (float)v54;
        }
      }
      else
      {
        idView::~idView(this: &v64);
      }
      return;
    case CAM_MOVE_CIRCLE_ENTITY:
      TimeLerpFraction = idSlowMotionCamera::GetTimeLerpFraction(this, timeLerpHelper: a3, a3: a4);
      v35 = idEntityPtr<idEntity const>::operator->(this: &this->current.movement.entity);
      if ( v35 != nullptr )
      {
        v36 = (float)(this->current.movement.entityOffset.y + this->current.movement.additionalOffset.y);
        v37 = (float)(this->current.movement.entityOffset.z + this->current.movement.additionalOffset.z);
        v59.x = this->current.movement.entityOffset.x + this->current.movement.additionalOffset.x;
        v60.value = idMath::TWO_PI * (float)TimeLerpFraction;
        v59.y = v36;
        v59.z = v37;
        idVec3::RotateSelf(this: &v59, axis: &vec3_up, angle: &v60);
        v38 = idEntity::GetPhysics(this: v35);
        v39 = (float *)v38->GetOrigin(this: v38, a2: 0);
        *(double *)&a4 = *v39;
        *((double *)&a4 + 1) = v59.z;
        v40 = (float)(v39[1] + v59.y);
        v41 = (float)(v39[2] + v59.z);
        this->current.movement.position.x = *v39 + v59.x;
        this->current.movement.position.y = v40;
        this->current.movement.position.z = v41;
      }
      x = this->current.movement.position.x;
      y = this->current.movement.position.y;
      z = this->current.movement.position.z;
      goto LABEL_20;
    default:
      v44 = this->current.movement.viewOrigin.x;
      v45 = this->current.movement.viewOrigin.y;
      v46 = this->current.movement.viewOrigin.z;
      p_viewOrigin = &this->current.movement.viewOrigin;
      x = (float)((float)v44 + this->current.movement.additionalOffset.x);
      y = (float)(this->current.movement.additionalOffset.y + (float)v45);
      z = (float)(this->current.movement.additionalOffset.z + (float)v46);
LABEL_20:
      v57.z = z;
      v57.y = y;
      v57.x = x;
      goto LABEL_21;
  }
}


// ========================================================================
// __unwind$511614
// EA  : 0x82D0D004
// RVA : 0x00D0D004
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_511614()
{
  int v0; // r12

  idView::~idView(this: (idView *)(v0 - 7200 + 208));
}


// ========================================================================
// ?MoveAxis@idSlowMotionCamera@@IAAXABVidVec3@@AAVidMat3@@@Z
// EA  : 0x82D0D038
// RVA : 0x00D0D038
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idSlowMotionCamera::MoveAxis(
        idSlowMotionCamera *this,
        const idVec3 *viewOrigin,
        __int64 viewAxis,
        long double a4)
{
  idDeclCameraTrigger::cam_focus_t focusType; // r11
  float *v7; // r28
  double x; // fp31
  double y; // fp29
  double z; // fp28
  double v11; // fp10
  double v12; // fp9
  float *v13; // r3
  double v14; // fp12
  int value; // r10
  idEntity *v16; // r3
  idAI2 *v17; // r3
  idVehicle_Car *v18; // r29
  idVehicle_Car *v19; // r3
  idPhysics *Physics; // r3
  float *v21; // r3
  double v22; // fp12
  double v23; // fp13
  double v24; // fp13
  double v25; // fp12
  double v26; // fp10
  double v27; // fp9
  double v28; // fp0
  double v29; // fp13
  idVehicle *v30; // r3
  idVehicle *v31; // r3
  double v32; // fp0
  double v33; // fp13
  double v34; // fp12
  double v35; // fp12
  double v36; // fp9
  double v37; // fp11
  double v38; // fp6
  double v39; // fp10
  double v40; // fp5
  double v41; // fp4
  double v42; // fp3
  double v43; // fp2
  double v44; // fp11
  double v46; // fp9
  double v48; // fp7
  double v49; // fp13
  double v50; // fp11
  double v51; // fp9
  idMat3 *v52; // r3
  idDeclCameraTrigger::cam_focus_t v53; // r8
  const idMat3 *v54; // r3
  long double v55; // fp2
  long double v56; // fp2
  double v57; // fp31
  long double v58; // fp2
  const idQuat *v59; // r29
  const idQuat *v60; // r3
  float *v61; // r3
  double v62; // fp12
  double v63; // fp10
  double v64; // fp6
  double v65; // fp12
  double v66; // fp11
  double v67; // fp10
  double v68; // fp9
  double v69; // fp8
  double v70; // fp7
  idVec3 v71; // [sp+50h] [-1BF0h] BYREF
  idMat3 *p_viewAxis; // [sp+5Ch] [-1BE4h]
  idMat3 v73; // [sp+60h] [-1BE0h] BYREF
  idMat3 v74; // [sp+88h] [-1BB8h] BYREF
  idMat3 v75[2]; // [sp+B0h] [-1B90h] BYREF
  idMat3 v76[80]; // [sp+100h] [-1B40h] BYREF

  focusType = this->current.focus.focusType;
  v7 = (float *)HIDWORD(viewAxis);
  if ( focusType == CAM_FOCUS_MOVEPATH && !this->suspended )
  {
    x = viewOrigin->x;
    y = viewOrigin->y;
    z = viewOrigin->z;
    v11 = (float)(viewOrigin->y - this->current.movement.viewOrigin.y);
    v12 = (float)(viewOrigin->z - this->current.movement.viewOrigin.z);
    v71.x = viewOrigin->x - this->current.movement.viewOrigin.x;
    v71.y = v11;
    v71.z = v12;
    *(double *)&a4 = idVec3::NormalizeFast(this: &v71);
    v71.x = (float)x + v71.x;
    v71.y = (float)y + v71.y;
    v71.z = (float)z + v71.z;
    goto LABEL_33;
  }
  if ( focusType == CAM_FOCUS_SPLINE )
  {
    *(double *)&a4 = this->current.focus.spline.dist;
    if ( *(double *)&a4 > 0.0 )
    {
      v13 = (float *)((int (__fastcall *)(idVec3 *))this->splines.list[this->current.focus.spline.sc].curve->GetCurrentValue)(a1: &v74.mat[2]);
      v71.x = *v13;
      v71.y = v13[1];
      v14 = v13[2];
LABEL_32:
      v71.z = v14;
      goto LABEL_33;
    }
  }
  switch ( focusType )
  {
    case CAM_FOCUS_ENTITY:
      value = this->current.focus.entity.spawnId.value;
      LODWORD(viewAxis) = 4 * ((value & 0x1FFF) + 29755);
      HIDWORD(viewAxis) = *(idGameLocal_vtbl **)((char *)&gameLocal->__vftable + viewAxis);
      if ( HIDWORD(viewAxis) == value >> 13
        && (v16 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
        && (v17 = (idAI2 *)idEntity::CastTo(c: v16), v18 = (idVehicle_Car *)v17, v17 != nullptr) )
      {
        if ( idAI2::CastTo(c: v17) != nullptr )
        {
          v18->GetAimPoint(this: v18, a2: AIMPOINT_HEAD, a3: &v71);
        }
        else
        {
          v19 = idVehicle_Car::CastTo(c: v18);
          if ( v19 != nullptr && v19->destroyed )
            this->current.focus.focusType = CAM_FOCUS_POSITION;
          if ( this->current.focus.focusType == CAM_FOCUS_POSITION )
          {
            v23 = this->current.focus.lastKnownPosition.y;
            v22 = this->current.focus.lastKnownPosition.z;
            v71.x = this->current.focus.lastKnownPosition.x;
            v71.y = v23;
          }
          else
          {
            Physics = idEntity::GetPhysics(this: v18);
            v21 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
            v71.x = *v21;
            v71.y = v21[1];
            v22 = v21[2];
          }
          v71.z = v22;
        }
        v24 = v71.y;
        v25 = v71.z;
        this->current.focus.lastKnownPosition.x = v71.x;
        this->current.focus.lastKnownPosition.y = v24;
        this->current.focus.lastKnownPosition.z = v25;
      }
      else
      {
        this->current.focus.focusType = CAM_FOCUS_POSITION;
        this->current.focus.position.x = this->current.focus.lastKnownPosition.x;
        this->current.focus.position.y = this->current.focus.lastKnownPosition.y;
        this->current.focus.position.z = this->current.focus.lastKnownPosition.z;
        v26 = this->current.focus.lastKnownPosition.z;
        v27 = this->current.focus.lastKnownPosition.x;
        v71.y = this->current.focus.lastKnownPosition.y;
        v71.x = v27;
        v71.z = v26;
      }
      goto LABEL_33;
    case CAM_FOCUS_POSITION:
      v28 = this->current.focus.position.x;
      v29 = this->current.focus.position.y;
      v14 = this->current.focus.position.z;
LABEL_31:
      v71.x = v28;
      v71.y = v29;
      goto LABEL_32;
    case CAM_FOCUS_POSITION_LERP:
      v28 = this->current.focus.position.x;
      v29 = this->current.focus.position.y;
      v14 = this->current.focus.position.z;
      goto LABEL_31;
    default:
      break;
  }
  if ( focusType != CAM_FOCUS_VEHICLE_DEFAULT )
  {
    v32 = this->current.focus.viewAxis.mat[0].x;
    v33 = this->current.focus.viewAxis.mat[0].y;
    v34 = this->current.focus.viewAxis.mat[0].z;
    p_viewAxis = &this->current.focus.viewAxis;
    v28 = (float)(this->current.movement.viewOrigin.x + (float)v32);
    v29 = (float)(this->current.movement.viewOrigin.y + (float)v33);
    v14 = (float)(this->current.movement.viewOrigin.z + (float)v34);
    goto LABEL_31;
  }
  idView::idView(this: (idView *)&v76[0].mat[1].y);
  v30 = (idVehicle *)idEntityPtr<idEntity const>::operator->(this: &this->current.focus.entity);
  v31 = idVehicle::CastTo(c: v30);
  if ( v31 == nullptr )
  {
    idView::~idView(this: (idView *)&v76[0].mat[1].y);
    return;
  }
  idVehicle::GetDriverView(
    this: v31,
    origin: (idVec3 *)&v75[0].mat[1].y,
    axis: &v73,
    fov_x: &this->current.fovZoom.angle,
    view: (idView *)&v76[0].mat[1].y);
  idView::~idView(this: (idView *)&v76[0].mat[1].y);
LABEL_33:
  if ( this->current.focus.focusType != CAM_FOCUS_VEHICLE_DEFAULT )
  {
    v35 = (float)(this->current.focus.focusOffset.y + v71.y);
    v36 = viewOrigin->y;
    v37 = (float)(this->current.focus.focusOffset.z + v71.z);
    v38 = viewOrigin->z;
    v39 = (float)(this->current.focus.focusOffset.x + v71.x);
    v40 = viewOrigin->x;
    v71.y = this->current.focus.focusOffset.y + v71.y;
    p_viewAxis = (idMat3 *)&this->current.focus.focusOffset;
    v71.z = v37;
    v41 = (float)((float)v35 - (float)v36);
    v71.x = v39;
    v42 = (float)((float)v37 - (float)v38);
    v43 = (float)((float)v39 - (float)v40);
    v44 = (float)((float)((float)((float)v39 - (float)v40) * (float)((float)v39 - (float)v40))
                + (float)((float)((float)((float)v37 - (float)v38) * (float)((float)v37 - (float)v38))
                        + (float)((float)((float)v35 - (float)v36) * (float)((float)v35 - (float)v36))));
    _FP10 = (float)((float)v44 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v46 = (float)((float)v44 * (float)0.5);
    __asm { fsel      f8, f10, f11, f13 }
    v48 = __frsqrte(_FP8);
    v49 = (float)((float)-(float)((float)((float)((float)v48 * (float)((float)v44 * (float)0.5)) * (float)v48)
                                - (float)1.5)
                * (float)v48);
    v50 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v48
                                                                                * (float)((float)v44 * (float)0.5))
                                                                        * (float)v48)
                                                                - (float)1.5)
                                                * (float)v48)
                                        * (float)((float)v44 * (float)0.5))
                                * (float)((float)-(float)((float)((float)((float)v48 * (float)((float)v44 * (float)0.5))
                                                                * (float)v48)
                                                        - (float)1.5)
                                        * (float)v48))
                        - (float)1.5);
    v51 = (float)((float)((float)v50 * (float)v49) * (float)v46);
    v74.mat[0].y = (float)v41
                 * (float)((float)-(float)((float)((float)v51 * (float)((float)v50 * (float)v49)) - (float)1.5)
                         * (float)((float)v50 * (float)v49));
    v74.mat[0].x = (float)v43
                 * (float)((float)-(float)((float)((float)v51 * (float)((float)v50 * (float)v49)) - (float)1.5)
                         * (float)((float)v50 * (float)v49));
    v74.mat[0].z = (float)v42
                 * (float)((float)-(float)((float)((float)v51 * (float)((float)v50 * (float)v49)) - (float)1.5)
                         * (float)((float)v50 * (float)v49));
    v52 = idVec3::ToMat3(this: (idVec3 *)&v75[0].mat[2].z, result: &v74);
    v73.mat[0].x = v52->mat[0].x;
    *((double *)&a4 + 1) = v52->mat[0].y;
    v53 = this->current.focus.focusType;
    v73.mat[0].y = v52->mat[0].y;
    LODWORD(viewAxis) = &v52->mat[2];
    *(double *)&a4 = v52->mat[0].z;
    v73.mat[0].z = v52->mat[0].z;
    p_viewAxis = (idMat3 *)&v52->mat[1];
    v73.mat[1].x = v52->mat[1].x;
    p_viewAxis = (idMat3 *)&v52->mat[2];
    v73.mat[1].y = v52->mat[1].y;
    v73.mat[1].z = v52->mat[1].z;
    v73.mat[2] = v52->mat[2];
    if ( v53 == CAM_FOCUS_MOVEPATH )
    {
      v54 = idAngles::ToMat3(this: (idAngles *)&v75[0].mat[2].z, result: (idMat3 *)&this->current.focus.pathAdjust);
      idMat3::operator*=(this: &v73, a: v54);
    }
  }
  if ( this->current.focus.frameLerp.duration <= 0.0 )
  {
    *v7 = v73.mat[0].x;
    v65 = v73.mat[0].y;
    p_viewAxis = (idMat3 *)(v7 + 6);
    v66 = v73.mat[0].z;
    v67 = v73.mat[1].y;
    v7[3] = v73.mat[1].x;
    v7[1] = v65;
    v7[2] = v66;
    v68 = v73.mat[1].z;
    v7[4] = v67;
    v69 = v73.mat[2].x;
    v7[5] = v68;
    v70 = v73.mat[2].y;
    v7[6] = v69;
    v64 = v73.mat[2].z;
    v7[7] = v70;
  }
  else
  {
    *(double *)&v55 = idSlowMotionCamera::GetTimeLerpFraction(this, timeLerpHelper: viewAxis, a3: a4);
    if ( *(double *)&v55 > 0.5 )
    {
      *(double *)&v55 = (float)((float)((float)((float)1.0 - (float)*(double *)&v55) * (float)120.0) * idMath::M_DEG2RAD);
      v58 = cos(x: v55);
      v57 = (float)*(double *)&v58;
    }
    else
    {
      *(double *)&v55 = (float)((float)((float)*(double *)&v55 * (float)120.0) * idMath::M_DEG2RAD);
      v56 = cos(x: v55);
      v57 = (float)((float)1.0 - (float)*(double *)&v56);
    }
    v59 = idMat3::ToQuat(this: (idMat3 *)&v74.mat[2], result: (idQuat *)&v73);
    v60 = idMat3::ToQuat(this: v76, result: (idQuat *)&this->previous.focus.viewAxis);
    idQuat::Lerp(this: (idQuat *)v75, from: v60, to: v59, t: v57);
    v61 = (float *)idQuat::ToMat3(this: (idQuat *)&v75[0].mat[2].z, result: v75);
    *v7 = *v61;
    v7[1] = v61[1];
    v62 = v61[2];
    p_viewAxis = (idMat3 *)(v7 + 3);
    v7[2] = v62;
    v7[3] = v61[3];
    p_viewAxis = (idMat3 *)(v61 + 6);
    v63 = v61[4];
    p_viewAxis = (idMat3 *)(v7 + 6);
    v7[4] = v63;
    v7[5] = v61[5];
    v7[6] = v61[6];
    v7[7] = v61[7];
    v64 = v61[8];
  }
  v7[8] = v64;
}


// ========================================================================
// __unwind$511917
// EA  : 0x82D0D62C
// RVA : 0x00D0D62C
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_511917()
{
  int v0; // r12

  idView::~idView(this: (idView *)(v0 - 7232 + 272));
}


// ========================================================================
// ??0idRaceCamera@@QAA@XZ
// EA  : 0x82D0D658
// RVA : 0x00D0D658
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idRaceCamera *__fastcall idRaceCamera::idRaceCamera(idRaceCamera *this)
{
  int v2; // ctr
  float *p_roll; // r9
  float *p_y; // r10

  idCameraView::idCameraView(this);
  this->__vftable = (idRaceCamera_vtbl *)&idRaceCamera::`vftable';
  this->owner.spawnId.value = 0x1FFF;
  this->vehicle.spawnId.value = 0x1FFF;
  this->yaw = 0.0;
  v2 = 9;
  p_roll = &this->cameraAngles.roll;
  p_y = &mat2_identity.mat[1].y;
  this->posPrev = vec3_origin;
  this->cameraBreath = ang_zero;
  this->cameraBreathPrev = ang_zero;
  this->cameraPos = vec3_origin;
  this->cameraAngles.pitch = 0.0;
  this->cameraAngles.yaw = 0.0;
  this->cameraAngles.roll = 0.0;
  do
  {
    *++p_roll = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->cameraNoObstructionTime = 0;
  this->repositionTime = 0;
  this->fadeInTime = 0;
  this->fadeOutTime = 0;
  this->cameraBreathNextUpdate = 0;
  this->navSplinePos.rightDistance = 0.0;
  this->navSplinePos.distance = 0.0;
  this->navSplinePos.navSpline = nullptr;
  this->goalPos = vec3_origin;
  this->gui = nullptr;
  return this;
}


// ========================================================================
// ?Think@idRaceCamera@@UAAXXZ
// EA  : 0x82D0D798
// RVA : 0x00D0D798
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idRaceCamera::Think(idRaceCamera *this)
{
  idEntityPtr<idEntity> *p_vehicle; // r30
  idEntity *v3; // r3
  idEntity *v4; // r3
  idPhysics *v5; // r3
  int v6; // r3
  float v7; // r6
  int v8; // r11
  float v9; // r5
  float v10; // r3
  int v11; // r8
  idEntity *v12; // r3
  idEntity *v13; // r3
  idPhysics *v14; // r3
  idAngles *v15; // r3
  idVec3 *v16; // r3
  int v17; // r11
  int v18; // r6
  double v19; // fp2
  double v20; // fp13
  idEntity *v21; // r3
  idEntity *v22; // r3
  idPhysics *v23; // r3
  int v24; // r28
  idClipModel *v25; // r27
  const idVec3 *v26; // r3
  idEntity *v27; // r3
  idPhysics *v28; // r3
  int v29; // r30
  idClipModel *v30; // r28
  const idVec3 *v31; // r3
  idPhysics *v32; // r3
  double v33; // fp0
  idPlayer *v34; // r3
  idPlayer *v35; // r28
  idPresentable *v36; // r3
  int v37; // r3
  idPresentable *v38; // r3
  int v39; // r3
  int GameMs; // r30
  __int64 v41; // r9
  double valueFloat; // fp13
  __int64 v43; // r7
  unsigned int v44; // r11
  double v45; // fp13
  unsigned int v46; // r3
  float yaw; // r9
  float roll; // r8
  float v49; // r6
  float pitch; // r5
  double v51; // fp3
  double v52; // fp1
  idPresentable *v53; // r3
  idVec3 *v54; // r3
  idPhysics *v55; // r3
  float *v56; // r3
  idGameLocal *v57; // r10
  idEntityPtr<idEntity> *p_target; // r30
  int v59; // r9
  idEntity *v60; // r3
  idEntity *v61; // r3
  idEntity *v62; // r3
  idPhysics *v63; // r3
  int v64; // r3
  float v65; // r6
  float v66; // r5
  bool v67; // mr_fpscr50
  double v68; // fp0
  char v69; // r11
  double v70; // fp30
  double x; // fp29
  double v72; // fp31
  idRenderWorld *v73; // r3
  idPhysics *v74; // r3
  float *v75; // r3
  double v76; // fp12
  double v77; // fp10
  idPhysics *v78; // r3
  idAngles *v79; // r3
  int value; // r11
  int v81; // r10
  idVehicle_Car *v82; // r3
  idVehicle_Car *v83; // r26
  idPhysics *Physics; // r3
  int v85; // r3
  float v86; // r7
  float v87; // r6
  int v88; // r9
  char v89; // r30
  idEntity *v90; // r3
  idPhysics *v91; // r3
  float *v92; // r3
  int v93; // r10
  int v94; // r9
  int v95; // r8
  int v96; // r7
  __int64 v97; // r6
  idEntity *v98; // r3
  idPhysics *v99; // r3
  int v100; // r3
  int *p_num; // r30
  float v102; // r7
  float v103; // r6
  idEntity *v104; // r3
  idNavPathPosTracker *Tracker; // r3
  float rightDistance; // r9
  float v107; // r8
  float *Forward; // r3
  double v109; // fp0
  float *SplineWorldPos; // r3
  double SplineWidth; // fp1
  idClientGame *v112; // r9
  __int64 v113; // r3
  __int64 v114; // r6
  unsigned int v115; // r8
  double v116; // fp31
  float *v117; // r3
  double v118; // fp5
  double v119; // fp4
  double v120; // fp0
  float *Right; // r3
  double v122; // fp31
  double v123; // fp0
  idEntity *v124; // r3
  idPhysics *v125; // r3
  float *v126; // r3
  double v127; // fp3
  int v128; // r30
  int v129; // r9
  idClipModel *clip8x8; // r7
  idPhysics *v131; // r3
  idEntity *v132; // r3
  idPhysics *v133; // r3
  float *v134; // r3
  double v135; // fp9
  double v136; // fp7
  idPhysics *v137; // r30
  idPhysics_vtbl *v138; // r24
  idMat3 *v139; // r3
  int v140; // r10
  int v141; // r9
  int v142; // r8
  int v143; // r7
  __int64 v144; // r6
  idEntity *v145; // r3
  idPhysics *v146; // r3
  float *v147; // r3
  idEntity *v148; // r3
  idPhysics *v149; // r3
  int v150; // r30
  idClipModel *v151; // r26
  const idVec3 *v152; // r3
  idPhysics *v153; // r3
  idQuat *v154; // r3
  idEntity *v155; // r3
  idPhysics *v156; // r3
  float *v157; // r3
  double v158; // fp9
  double v159; // fp7
  idQuat *v160; // r3
  idPhysics *v161; // r30
  idPhysics_vtbl *v162; // r29
  idMat3 *v163; // r3
  idPlayer *PlayerActivator; // r3
  idPlayer *v165; // r30
  idPresentable *presentable; // r3
  int v167; // r3
  idPresentable *v168; // r3
  idPhysics *v169; // r3
  int v170; // r3
  float v171; // r7
  float v172; // r6
  idEntity *v173; // r3
  idPhysics *v174; // r3
  int v175; // r3
  idAISplinePathMgr *p_aiSplinePathMgr; // r30
  float v177; // r7
  float v178; // r6
  idEntity *v179; // r3
  idNavPathPosTracker *v180; // r3
  navSplinePath_t *ShortestPath; // r3
  idNavSplinePosition *v182; // r29
  navSplinePath_t *StartPathPos; // r3
  float *v184; // r3
  double v185; // fp11
  double v186; // fp10
  idEntity *v187; // r3
  idPhysics *v188; // r3
  float *v189; // r3
  double v190; // fp10
  double v191; // fp5
  double v192; // fp3
  double v193; // fp1
  double v194; // fp9
  double v195; // fp8
  double v196; // fp12
  idEntity *v197; // r3
  idPhysics *v198; // r3
  float *v199; // r3
  double v200; // fp10
  double v201; // fp8
  double v202; // fp7
  double v203; // fp0
  double v204; // fp6
  double v205; // fp3
  double v206; // fp3
  double v207; // fp1
  idPhysics *v208; // r3
  idPhysics *v209; // r3
  idQuat *v210; // r3
  idEntity *v211; // r3
  idPhysics *v212; // r3
  float *v213; // r3
  double v214; // fp8
  double v215; // fp6
  idQuat *v216; // r3
  idPhysics *v217; // r30
  idPhysics_vtbl *v218; // r29
  idMat3 *v219; // r3
  idPlayer *v220; // r3
  idPlayer *v221; // r30
  idPresentable *v222; // r3
  int v223; // r3
  idPresentable *v224; // r3
  int v225; // r3
  idPhysics *v226; // r3
  float *v227; // r3
  idPhysics *v228; // r3
  float *v229; // r3
  int v230; // [sp+8h] [-268h]
  __int64 v231; // [sp+10h] [-260h]
  __int64 v232; // [sp+18h] [-258h]
  __int64 v233; // [sp+20h] [-250h]
  __int64 v234; // [sp+28h] [-248h]
  __int64 v235; // [sp+30h] [-240h]
  idVec3 v236; // [sp+50h] [-220h] BYREF
  idAngles v237; // [sp+60h] [-210h] BYREF
  idMat3 v238; // [sp+70h] [-200h] BYREF
  float v239; // [sp+94h] [-1DCh]
  float v240; // [sp+98h] [-1D8h]
  idVec3 v241; // [sp+A0h] [-1D0h] BYREF
  idMat3 v242; // [sp+B0h] [-1C0h] BYREF
  float y; // [sp+D4h] [-19Ch]
  float v244; // [sp+D8h] [-198h]
  idMat3 v245; // [sp+E0h] [-190h] BYREF
  float v246; // [sp+104h] [-16Ch]
  float v247; // [sp+108h] [-168h]
  float v248; // [sp+10Ch] [-164h]
  idMat3 v249[2]; // [sp+110h] [-160h] BYREF
  idMat3 v250; // [sp+160h] [-110h] BYREF
  float v251; // [sp+184h] [-ECh]
  float v252; // [sp+188h] [-E8h]
  float v253; // [sp+18Ch] [-E4h]

  if ( racecam_version.valueInteger != 3 )
  {
    value = this->vehicle.spawnId.value;
    v81 = value & 0x1FFF;
    if ( racecam_version.valueInteger == 2 )
    {
      if ( gameLocal->spawnIds.ptr[v81] == value >> 13 )
      {
        v82 = (idVehicle_Car *)idEntityPtr<idEntity const>::operator->(this: &this->vehicle);
        v83 = idVehicle_Car::CastTo(c: v82);
        Physics = idEntity::GetPhysics(this);
        v85 = (int)Physics->GetOrigin(this: Physics, a2: 0);
        v86 = *(float *)(v85 + 4);
        v87 = *(float *)v85;
        v236.z = *(float *)(v85 + 8);
        v236.y = v86;
        v236.x = v87;
        v88 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->cameraNoObstructionTime;
        v89 = ((v88 >= 0) + ((unsigned int)v88 <= 0x1F4)) & 1;
        if ( v89 == 0 )
        {
          v90 = idEntityPtr<idEntity const>::operator->(this: &this->vehicle);
          v91 = idEntity::GetPhysics(this: v90);
          v92 = (float *)v91->GetOrigin(this: v91, a2: 0);
          v89 = (float)((float)((float)(v92[1] - v236.y) * (float)(v92[1] - v236.y))
                      + (float)((float)((float)(*v92 - v236.x) * (float)(*v92 - v236.x))
                              + (float)((float)(v92[2] - v236.z) * (float)(v92[2] - v236.z)))) > 15210000.0;
        }
        if ( v89 != 0 && this->fadeOutTime == 0 && this->fadeInTime == 0 )
        {
          if ( v83 != nullptr && idVehicle::GetCollisionDamage(this: v83) == nullptr )
          {
            LODWORD(v97) = 500;
            *(float *)&v97 = idColor::colorBlack.a;
            idCameraView::FadeOut(
              this,
              timeMs: v97,
              a3: v96,
              a4: v95,
              a5: v94,
              a6: v93,
              a7: v230,
              a8: v231,
              a9: v232,
              a10: v233,
              a11: v234,
              a12: v235);
          }
          this->fadeOutTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + 500;
        }
        if ( this->fadeInTime > 0 && this->fadeInTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
          this->fadeInTime = 0;
        if ( this->fadeOutTime > 0 && this->fadeOutTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
        {
          v89 = 1;
          this->fadeOutTime = 0;
        }
        if ( v89 != 0
          && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->repositionTime > 1000
          && this->fadeOutTime == 0
          && this->fadeInTime == 0 )
        {
          v98 = idEntityPtr<idEntity const>::operator->(this: &this->vehicle);
          v99 = idEntity::GetPhysics(this: v98);
          v100 = (int)v99->GetAxis(this: v99, a2: 0);
          p_num = &gameLocal->aiSplinePathMgr.trackerPool.trackers[-1].userPath[0].path.num;
          v102 = *(float *)(v100 + 4);
          v103 = *(float *)(v100 + 8);
          v237.pitch = *(float *)v100;
          v237.yaw = v102;
          v237.roll = v103;
          v104 = idEntityPtr<idEntity const>::operator->(this: &this->vehicle);
          Tracker = idNavSplinePathMgr::FindTracker(
                      this: (idNavSplinePathMgr *)p_num,
                      owner: v104,
                      createTrackerIfNotFound: false);
          if ( Tracker != nullptr )
          {
            rightDistance = Tracker->pathPosition.rightDistance;
            v107 = *(float *)&Tracker->pathPosition.navSpline;
            v241.x = Tracker->pathPosition.distance;
            v241.y = rightDistance;
            v241.z = v107;
            Forward = (float *)idNavSplinePosition::GetForward(this: (idNavSplinePosition *)&v238, result: &v241);
            if ( (float)((float)(v237.pitch * *Forward)
                       + (float)((float)(Forward[1] * v237.yaw) + (float)(Forward[2] * v237.roll))) <= 0.0 )
              v109 = -2000.0;
            else
              v109 = 2000.0;
            v241.x = v241.x + (float)v109;
            idNavSplinePosition::Validate(this: (idNavSplinePosition *)&v241, nextSpline: nullptr, prevSpline: nullptr);
            SplineWorldPos = (float *)idNavSplinePosition::GetSplineWorldPos(
                                        this: (idNavSplinePosition *)&v238,
                                        result: &v241);
            v236.x = *SplineWorldPos;
            v236.y = SplineWorldPos[1];
            v236.z = SplineWorldPos[2];
            SplineWidth = idNavSplinePosition::GetSplineWidth(this: (idNavSplinePosition *)&v241, dist: -1.0);
            v112 = clientGame;
            clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
            LODWORD(v113) = (v112->random.seed >> 10) & 0x7FFF;
            *(_QWORD *)&v237.pitch = v113;
            HIDWORD(v114) = clientGame->random.seed;
            v115 = 1664525 * clientGame->random.seed + 1013904223;
            clientGame->random.seed = v115;
            LODWORD(v114) = (v115 >> 10) & 0x7FFF;
            *(_QWORD *)&v237.pitch = v114;
            v116 = (float)((float)((float)((float)v113 * (float)0.000030518509) + (float)1.0)
                         * (float)((float)SplineWidth * (float)0.5));
            if ( (float)((float)v114 * (float)0.000030518509) < 0.5 )
            {
              Right = (float *)idNavSplinePosition::GetRight(this: (idNavSplinePosition *)&v238, result: &v241);
              v118 = (float)(v236.x - (float)(*Right * (float)v116));
              v119 = (float)(v236.y - (float)(Right[1] * (float)v116));
              v120 = (float)(v236.z - (float)(Right[2] * (float)v116));
            }
            else
            {
              v117 = (float *)idNavSplinePosition::GetRight(this: (idNavSplinePosition *)&v238, result: &v241);
              v118 = (float)((float)(*v117 * (float)v116) + v236.x);
              v119 = (float)((float)(v117[1] * (float)v116) + v236.y);
              v120 = (float)(v236.z + (float)(v117[2] * (float)v116));
            }
            v236.y = v119;
            v236.x = v118;
            v122 = 250.0;
            v123 = (float)((float)v120 + (float)250.0);
          }
          else
          {
            v124 = idEntityPtr<idEntity const>::operator->(this: &this->vehicle);
            v125 = idEntity::GetPhysics(this: v124);
            v126 = (float *)v125->GetOrigin(this: v125, a2: 0);
            v122 = 250.0;
            v127 = (float)(*v126 - (float)(v237.pitch * (float)500.0));
            v236.x = *v126;
            v236.y = v126[1];
            v123 = (float)((float)(v126[2] - (float)(v237.roll * (float)500.0)) + (float)250.0);
            v236.x = v127;
            v236.y = v236.y - (float)(v237.yaw * (float)500.0);
          }
          v236.z = v123;
          v128 = 3;
          do
          {
            v129 = this->owner.spawnId.value & 0x1FFF;
            clip8x8 = clientGame->clip.clip8x8;
            v242.mat[2].z = v236.x;
            y = v236.y;
            v244 = (float)v123 - (float)2000.0;
            --v128;
            idClip::TraceBounds(
              this: &clientGame->clip,
              result: (trace_t *)&v250.mat[2].z,
              start: &v236,
              end: (const idVec3 *)&v242.mat[2].z,
              trm: clip8x8,
              clipMask: 1,
              passEntityNumber: v129);
            if ( v250.mat[2].z != 1.0 )
              break;
            v123 = (float)(v236.z + (float)v122);
            v236.z = v236.z + (float)v122;
          }
          while ( v128 > 0 );
          v131 = idEntity::GetPhysics(this);
          v131->SetOrigin(this: v131, a2: &v236, a3: -1);
          v132 = idEntityPtr<idEntity const>::operator->(this: &this->vehicle);
          v133 = idEntity::GetPhysics(this: v132);
          v134 = (float *)v133->GetOrigin(this: v133, a2: 0);
          v135 = (float)(v134[2] - v236.z);
          v136 = (float)(v134[1] - v236.y);
          v242.mat[0].x = *v134 - v236.x;
          v242.mat[0].z = v135;
          v242.mat[0].y = v136;
          v137 = idEntity::GetPhysics(this);
          v138 = v137->__vftable;
          v139 = idVec3::ToMat3(this: (idVec3 *)&v249[0].mat[2].z, result: &v242);
          v138->SetAxis(this: v137, a2: v139, a3: -1);
          this->repositionTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          if ( v83 != nullptr && idVehicle::GetCollisionDamage(this: v83) == nullptr )
          {
            LODWORD(v144) = 1000;
            *(float *)&v144 = idColor::colorBlack.a;
            idCameraView::FadeIn(
              this,
              timeMs: v144,
              a3: v143,
              a4: v142,
              a5: v141,
              a6: v140,
              a7: v230,
              a8: v231,
              a9: v232,
              a10: v233,
              a11: v234,
              a12: v235);
          }
          this->fadeInTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + 1000;
        }
        if ( this->fadeOutTime == 0 )
        {
          v145 = idEntityPtr<idEntity const>::operator->(this: &this->vehicle);
          v146 = idEntity::GetPhysics(this: v145);
          v147 = (float *)v146->GetOrigin(this: v146, a2: 0);
          if ( (float)((float)((float)(v147[1] - v236.y) * (float)(v147[1] - v236.y))
                     + (float)((float)((float)(*v147 - v236.x) * (float)(*v147 - v236.x))
                             + (float)((float)(v147[2] - v236.z) * (float)(v147[2] - v236.z)))) < 16000000.0 )
          {
            v148 = idEntityPtr<idEntity const>::operator->(this: &this->vehicle);
            v149 = idEntity::GetPhysics(this: v148);
            v150 = this->owner.spawnId.value & 0x1FFF;
            v151 = clientGame->clip.clip8x8;
            v152 = v149->GetOrigin(this: v149, a2: 0);
            idClip::TraceBounds(
              this: &clientGame->clip,
              result: (trace_t *)&v250.mat[2].z,
              start: v152,
              end: &v236,
              trm: v151,
              clipMask: 1,
              passEntityNumber: v150);
            if ( v250.mat[2].z == 1.0 )
              this->cameraNoObstructionTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          }
        }
        v153 = idEntity::GetPhysics(this);
        v154 = (idQuat *)v153->GetAxis(this: v153, a2: 0);
        idMat3::ToQuat(this: (idMat3 *)&v249[0].mat[1].y, result: v154);
        v155 = idEntityPtr<idEntity const>::operator->(this: &this->vehicle);
        v156 = idEntity::GetPhysics(this: v155);
        v157 = (float *)v156->GetOrigin(this: v156, a2: 0);
        v158 = (float)(v157[2] - v236.z);
        v159 = (float)(v157[1] - v236.y);
        v242.mat[1].y = *v157 - v236.x;
        v242.mat[2].x = v158;
        v242.mat[1].z = v159;
        v160 = (idQuat *)idVec3::ToMat3(this: (idVec3 *)&v249[0].mat[2].z, result: (idMat3 *)&v242.mat[1].y);
        idMat3::ToQuat(this: v249, result: v160);
        idQuat::Lerp(
          this: (idQuat *)&v250.mat[1].y,
          from: (const idQuat *)&v249[0].mat[1].y,
          to: (const idQuat *)v249,
          t: racecam_focusLerpRate.valueFloat);
        v161 = idEntity::GetPhysics(this);
        v162 = v161->__vftable;
        v163 = idQuat::ToMat3(this: (idQuat *)&v249[0].mat[2].z, result: (idMat3 *)&v250.mat[1].y);
        v162->SetAxis(this: v161, a2: v163, a3: -1);
      }
      PlayerActivator = idCamera::GetPlayerActivator(this);
      v165 = PlayerActivator;
      if ( PlayerActivator != nullptr )
      {
        presentable = PlayerActivator->presentable;
        if ( presentable != nullptr )
          v167 = (int)presentable->GetPlayerInterface_2(this: presentable);
        else
          v167 = 0;
        idView::ResetControllerShake(this: (idView *)(v167 + 16224));
        v168 = v165->presentable;
        if ( v168 != nullptr )
          v168->GetPlayerInterface_2(this: v168)->view.cameraShake = 0.0;
        else
          MEMORY[0x4AB8] = 0.0;
      }
LABEL_117:
      v226 = idEntity::GetPhysics(this);
      v227 = (float *)v226->GetAxis(this: v226, a2: 0);
      this->cameraAxis.mat[0].x = *v227;
      this->cameraAxis.mat[0].y = v227[1];
      this->cameraAxis.mat[0].z = v227[2];
      this->cameraAxis.mat[1].x = v227[3];
      this->cameraAxis.mat[1].y = v227[4];
      this->cameraAxis.mat[1].z = v227[5];
      this->cameraAxis.mat[2].x = v227[6];
      this->cameraAxis.mat[2].y = v227[7];
      this->cameraAxis.mat[2].z = v227[8];
      v228 = idEntity::GetPhysics(this);
      v229 = (float *)v228->GetOrigin(this: v228, a2: 0);
      this->cameraPos.x = *v229;
      this->cameraPos.y = v229[1];
      this->cameraPos.z = v229[2];
      return;
    }
    if ( gameLocal->spawnIds.ptr[v81] != value >> 13 )
    {
LABEL_109:
      v220 = idCamera::GetPlayerActivator(this);
      v221 = v220;
      if ( v220 != nullptr )
      {
        v222 = v220->presentable;
        if ( v222 != nullptr )
          v223 = (int)v222->GetPlayerInterface_2(this: v222);
        else
          v223 = 0;
        idView::ResetControllerShake(this: (idView *)(v223 + 16224));
        v224 = v221->presentable;
        if ( v224 != nullptr )
          v225 = (int)v224->GetPlayerInterface_2(this: v224);
        else
          v225 = 0;
        *(float *)(v225 + 19128) = 0.0;
      }
      goto LABEL_117;
    }
    v169 = idEntity::GetPhysics(this);
    v170 = (int)v169->GetOrigin(this: v169, a2: 0);
    v171 = *(float *)(v170 + 4);
    v172 = *(float *)(v170 + 8);
    v238.mat[2].z = *(float *)v170;
    v239 = v171;
    v240 = v172;
    v173 = idEntityPtr<idEntity const>::operator->(this: &this->vehicle);
    v174 = idEntity::GetPhysics(this: v173);
    v175 = (int)v174->GetAxis(this: v174, a2: 0);
    p_aiSplinePathMgr = &gameLocal->aiSplinePathMgr;
    v177 = *(float *)(v175 + 4);
    v178 = *(float *)(v175 + 8);
    v237.pitch = *(float *)v175;
    v237.yaw = v177;
    v237.roll = v178;
    v179 = idEntityPtr<idEntity const>::operator->(this: &this->vehicle);
    v180 = idNavSplinePathMgr::FindTracker(this: p_aiSplinePathMgr, owner: v179, createTrackerIfNotFound: false);
    if ( v180 != nullptr )
    {
      ShortestPath = idNavSplinePathMgr::GetShortestPath(
                       this: (idNavSplinePathMgr *)LODWORD(this->navSplinePos.distance),
                       start: (idNavSpline *)LODWORD(this->navSplinePos.rightDistance),
                       end: (idNavSplinePosition *)__ROL4__(this->navSplinePos.navSpline, 32),
                       path: (idNavSplinePosition *)LODWORD(v180->pathPosition.rightDistance),
                       a5: __ROL4__(v180->pathPosition.navSpline, 32),
                       a6: nullptr);
      v182 = (idNavSplinePosition *)ShortestPath;
      if ( ShortestPath != nullptr )
      {
        if ( ShortestPath->distance > (double)racecam_pathMinDist.valueFloat )
          navSplinePath_t::Step(
            this: ShortestPath,
            stepdist: (float)((float)(ShortestPath->distance - racecam_pathMinDist.valueFloat) / racecam_pathStepUnits.valueFloat));
        StartPathPos = navSplinePath_t::GetStartPathPos(this: (navSplinePath_t *)&v238, result: v182);
        this->navSplinePos.distance = StartPathPos->startDistance;
        this->navSplinePos.rightDistance = StartPathPos->endDistance;
        this->navSplinePos.navSpline = (idNavSpline *)LODWORD(StartPathPos->distance);
        v184 = (float *)idNavSplinePosition::GetSplineWorldPos(
                          this: (idNavSplinePosition *)&v237,
                          result: (idVec3 *)&this->navSplinePos);
        this->goalPos.x = *v184;
        this->goalPos.y = v184[1];
        v185 = v184[2];
        this->goalPos.z = v184[2];
        v186 = (float)((float)v185 + (float)250.0);
        goto LABEL_108;
      }
      v187 = idEntityPtr<idEntity const>::operator->(this: &this->vehicle);
      v188 = idEntity::GetPhysics(this: v187);
      v189 = (float *)v188->GetOrigin(this: v188, a2: 0);
      v190 = *v189;
      this->goalPos.x = *v189;
      v191 = (float)(v237.yaw * (float)500.0);
      v192 = (float)(v237.roll * (float)500.0);
      v193 = (float)((float)v190 - (float)(v237.pitch * (float)500.0));
      v194 = v189[1];
      this->goalPos.y = v189[1];
      v195 = v189[2];
      this->goalPos.z = v189[2];
      this->goalPos.x = v193;
      v196 = (float)((float)v195 - (float)v192);
      this->goalPos.y = (float)v194 - (float)v191;
    }
    else
    {
      v197 = idEntityPtr<idEntity const>::operator->(this: &this->vehicle);
      v198 = idEntity::GetPhysics(this: v197);
      v199 = (float *)v198->GetOrigin(this: v198, a2: 0);
      v200 = *v199;
      this->goalPos.x = *v199;
      v201 = (float)(v237.yaw * (float)500.0);
      v202 = (float)(v237.roll * (float)500.0);
      v203 = (float)((float)v200 - (float)(v237.pitch * (float)500.0));
      v204 = v199[1];
      this->goalPos.y = v199[1];
      v205 = v199[2];
      this->goalPos.z = v199[2];
      v196 = (float)((float)v205 - (float)v202);
      this->goalPos.x = v203;
      this->goalPos.y = (float)v204 - (float)v201;
    }
    this->goalPos.z = v196;
    v186 = (float)((float)v196 + (float)250.0);
LABEL_108:
    this->goalPos.z = v186;
    v206 = (float)(racecam_goalLerpRate_3.valueFloat * (float)(this->goalPos.z - v240));
    v207 = (float)((float)(racecam_goalLerpRate_3.valueFloat * (float)(this->goalPos.y - v239)) + v239);
    v238.mat[2].z = (float)((float)(this->goalPos.x - v238.mat[2].z) * racecam_goalLerpRate_3.valueFloat)
                  + v238.mat[2].z;
    v239 = v207;
    v240 = (float)v206 + v240;
    v208 = idEntity::GetPhysics(this);
    v208->SetOrigin(this: v208, a2: (const idVec3 *)&v238.mat[2].z, a3: -1);
    this->repositionTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v209 = idEntity::GetPhysics(this);
    v210 = (idQuat *)v209->GetAxis(this: v209, a2: 0);
    idMat3::ToQuat(this: v249, result: v210);
    v211 = idEntityPtr<idEntity const>::operator->(this: &this->vehicle);
    v212 = idEntity::GetPhysics(this: v211);
    v213 = (float *)v212->GetOrigin(this: v212, a2: 0);
    v214 = (float)(v213[2] - v240);
    v215 = (float)(v213[1] - v239);
    v245.mat[0].x = *v213 - v238.mat[2].z;
    v245.mat[0].z = v214;
    v245.mat[0].y = v215;
    v216 = (idQuat *)idVec3::ToMat3(this: (idVec3 *)&v249[0].mat[2].z, result: &v245);
    idMat3::ToQuat(this: (idMat3 *)&v249[0].mat[1].y, result: v216);
    idQuat::Lerp(
      this: (idQuat *)&v250,
      from: (const idQuat *)v249,
      to: (const idQuat *)&v249[0].mat[1].y,
      t: racecam_focusLerpRate.valueFloat);
    v217 = idEntity::GetPhysics(this);
    v218 = v217->__vftable;
    v219 = idQuat::ToMat3(this: (idQuat *)&v249[0].mat[2].z, result: &v250);
    v218->SetAxis(this: v217, a2: v219, a3: -1);
    goto LABEL_109;
  }
  p_vehicle = &this->vehicle;
  if ( gameLocal->spawnIds.ptr[this->vehicle.spawnId.value & 0x1FFF] == this->vehicle.spawnId.value >> 13 )
  {
    v3 = gameLocal->entities.ptr[p_vehicle->spawnId.value & 0x1FFF];
    if ( v3 != nullptr )
      v4 = idEntity::CastTo(c: v3);
    else
      v4 = nullptr;
    v5 = idEntity::GetPhysics(this: v4);
    v6 = (int)v5->GetOrigin(this: v5, a2: 0);
    v7 = *(float *)v6;
    v8 = p_vehicle->spawnId.value & 0x1FFF;
    v9 = *(float *)(v6 + 4);
    v10 = *(float *)(v6 + 8);
    v11 = p_vehicle->spawnId.value >> 13;
    v238.mat[1].y = v7;
    v238.mat[1].z = v9;
    v238.mat[2].x = v10;
    if ( gameLocal->spawnIds.ptr[v8] == v11 && (v12 = gameLocal->entities.ptr[v8]) != nullptr )
      v13 = idEntity::CastTo(c: v12);
    else
      v13 = nullptr;
    v14 = idEntity::GetPhysics(this: v13);
    v15 = (idAngles *)v14->GetAxis(this: v14, a2: 0);
    idMat3::ToAngles(this: &v238, result: v15);
    v238.mat[0].y = this->yaw + v238.mat[0].y;
    v16 = idAngles::ToForward(this: &v237, result: v238.mat);
    v17 = p_vehicle->spawnId.value & 0x1FFF;
    v18 = p_vehicle->spawnId.value >> 13;
    v19 = (float)(v238.mat[2].x - (float)(v16->z * (float)500.0));
    v20 = (float)(v238.mat[1].z - (float)(v16->y * (float)500.0));
    v238.mat[1].y = v238.mat[1].y - (float)(v16->x * (float)500.0);
    v238.mat[1].z = v20;
    v238.mat[2].x = (float)v19 + (float)150.0;
    if ( gameLocal->spawnIds.ptr[v17] == v18 && (v21 = gameLocal->entities.ptr[v17]) != nullptr )
      v22 = idEntity::CastTo(c: v21);
    else
      v22 = nullptr;
    v23 = idEntity::GetPhysics(this: v22);
    v24 = this->owner.spawnId.value & 0x1FFF;
    v25 = clientGame->clip.clip8x8;
    v26 = v23->GetOrigin(this: v23, a2: 0);
    idClip::TraceBounds(
      this: &clientGame->clip,
      result: (trace_t *)&v250.mat[2].z,
      start: v26,
      end: (const idVec3 *)&v238.mat[1].y,
      trm: v25,
      clipMask: 107553,
      passEntityNumber: v24);
    if ( v250.mat[2].z != 1.0 )
    {
      v238.mat[1].y = v251;
      v238.mat[1].z = v252;
      v238.mat[2].x = (float)((float)((float)1.0 - v250.mat[2].z) * (float)32.0) + v253;
      v27 = idEntityPtr<idEntity const>::operator->(this: p_vehicle);
      v28 = idEntity::GetPhysics(this: v27);
      v29 = this->owner.spawnId.value & 0x1FFF;
      v30 = clientGame->clip.clip8x8;
      v31 = v28->GetOrigin(this: v28, a2: 0);
      idClip::TraceBounds(
        this: &clientGame->clip,
        result: (trace_t *)&v250.mat[2].z,
        start: v31,
        end: (const idVec3 *)&v238.mat[1].y,
        trm: v30,
        clipMask: 107553,
        passEntityNumber: v29);
      v238.mat[1].y = v251;
      v238.mat[1].z = v252;
      v238.mat[2].x = v253;
    }
    v32 = idEntity::GetPhysics(this);
    v32->SetOrigin(this: v32, a2: (const idVec3 *)&v238.mat[1].y, a3: -1);
    v33 = (float)(this->yaw + (float)0.1);
    this->yaw = this->yaw + (float)0.1;
    if ( v33 >= 360.0 )
      this->yaw = (float)v33 - (float)360.0;
  }
  v34 = idCamera::GetPlayerActivator(this);
  v35 = v34;
  if ( v34 != nullptr )
  {
    v36 = v34->presentable;
    if ( v36 != nullptr )
      v37 = (int)v36->GetPlayerInterface_2(this: v36);
    else
      v37 = 0;
    idView::ResetControllerShake(this: (idView *)(v37 + 16224));
    v38 = v35->presentable;
    if ( v38 != nullptr )
      v39 = (int)v38->GetPlayerInterface_2(this: v38);
    else
      v39 = 0;
    *(float *)(v39 + 19128) = 0.0;
  }
  if ( racecam_BreathEnable.valueInteger != 0 )
  {
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->cameraBreathNextUpdate )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      this->cameraBreathNextUpdate = idRandom2::RandomInt(
                                       this: &clientGame->random,
                                       min: racecam_BreathMinFreq.valueInteger,
                                       max: racecam_BreathMaxFreq.valueInteger)
                                   + GameMs;
      HIDWORD(v41) = &racecam_BreathAng;
      valueFloat = racecam_BreathAng.valueFloat;
      HIDWORD(v43) = 1013904223;
      v44 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v44;
      LODWORD(v43) = (v44 >> 10) & 0x7FFF;
      *(_QWORD *)&v237.pitch = v43;
      this->cameraBreath.pitch = (float)((float)v43 * (float)valueFloat) * (float)0.000030518509;
      v45 = racecam_BreathAng.valueFloat;
      v46 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v46;
      this->cameraBreath.roll = 0.0;
      LODWORD(v41) = (v46 >> 10) & 0x7FFF;
      *(_QWORD *)&v237.pitch = v41;
      this->cameraBreath.yaw = (float)((float)v41 * (float)v45) * (float)0.000030518509;
    }
    yaw = this->cameraBreathPrev.yaw;
    roll = this->cameraBreath.roll;
    v49 = this->cameraBreathPrev.roll;
    pitch = this->cameraBreath.pitch;
    v237.yaw = this->cameraBreath.yaw;
    v238.mat[0].y = yaw;
    v237.roll = roll;
    v238.mat[0].z = v49;
    v238.mat[0].x = this->cameraBreathPrev.pitch;
    v237.pitch = pitch;
    v51 = (float)((float)(v237.yaw - yaw) * racecam_BreathLerp.valueFloat);
    v52 = (float)((float)(roll - v49) * racecam_BreathLerp.valueFloat);
    this->cameraBreathPrev.pitch = (float)((float)(pitch - v238.mat[0].x) * racecam_BreathLerp.valueFloat)
                                 + v238.mat[0].x;
    this->cameraBreathPrev.yaw = (float)v51 + yaw;
    this->cameraBreathPrev.roll = (float)v52 + v49;
    v53 = v35->presentable;
    if ( v53 != nullptr )
      v54 = (idVec3 *)v53->GetPlayerInterface_2(this: v53);
    else
      v54 = nullptr;
    v54[1587] = vec3_origin;
    v54[1588].x = this->cameraBreathPrev.pitch;
    v54[1588].y = this->cameraBreathPrev.yaw;
    v54[1588].z = this->cameraBreathPrev.roll;
  }
  v55 = idEntity::GetPhysics(this);
  v56 = (float *)v55->GetOrigin(this: v55, a2: 0);
  v57 = gameLocal;
  this->cameraPos.x = *v56;
  p_target = &this->target;
  this->cameraPos.y = v56[1];
  this->cameraPos.z = v56[2];
  v59 = this->target.spawnId.value;
  if ( v57->spawnIds.ptr[v59 & 0x1FFF] == v59 >> 13
    && (v60 = v57->entities.ptr[v59 & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v60) != nullptr )
  {
    if ( gameLocal->spawnIds.ptr[p_target->spawnId.value & 0x1FFF] == p_target->spawnId.value >> 13
      && (v61 = gameLocal->entities.ptr[p_target->spawnId.value & 0x1FFF]) != nullptr )
    {
      v62 = idEntity::CastTo(c: v61);
    }
    else
    {
      v62 = nullptr;
    }
    v63 = idEntity::GetPhysics(this: v62);
    v64 = (int)v63->GetOrigin(this: v63, a2: 0);
    v65 = *(float *)v64;
    v66 = *(float *)(v64 + 4);
    v67 = this->posPrev.x == vec3_origin.x;
    v238.mat[0].z = *(float *)(v64 + 8);
    v238.mat[0].x = v65;
    v238.mat[0].y = v66;
    v68 = (float)(racecam_PosUp.valueFloat + v238.mat[0].z);
    if ( !v67 || this->posPrev.y != vec3_origin.y || (v69 = 1, this->posPrev.z != vec3_origin.z) )
      v69 = 0;
    v70 = v238.mat[0].y;
    x = v238.mat[0].x;
    if ( v69 != 0 )
    {
      this->posPrev.x = v238.mat[0].x;
      this->posPrev.y = v70;
      this->posPrev.z = v68;
    }
    v72 = (float)((float)((float)((float)v68 - this->posPrev.z) * racecam_PosLerp.valueFloat) + this->posPrev.z);
    if ( racecam_BreathDebug.valueInteger != 0 )
    {
      v73 = gameLocal->GetRenderWorld(this: gameLocal);
      v247 = v72;
      v245.mat[2].z = x;
      v246 = v70;
      v248 = 25.0;
      v73->DebugSphere(
        this: v73,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idSphere *)&v245.mat[2].z,
        a4: 12,
        a5: 500,
        a6: false);
    }
    v74 = idEntity::GetPhysics(this);
    v75 = (float *)v74->GetOrigin(this: v74, a2: 0);
    v76 = (float)((float)v72 - v75[2]);
    v77 = (float)((float)v70 - v75[1]);
    v245.mat[1].y = (float)x - *v75;
    v245.mat[2].x = v76;
    v245.mat[1].z = v77;
    this->cameraAngles = *idVec3::ToAngles(this: v238.mat, result: (idAngles *)&v245.mat[1].y);
    this->cameraAngles.roll = 0.0;
  }
  else
  {
    v78 = idEntity::GetPhysics(this);
    v79 = (idAngles *)v78->GetAxis(this: v78, a2: 0);
    this->cameraAngles = *idMat3::ToAngles(this: &v238, result: v79);
    this->cameraAngles.roll = 0.0;
  }
}


// ========================================================================
// ?Draw_1@idRaceCamera@@QAA_NPAVidPlayer@@@Z
// EA  : 0x82D0EE08
// RVA : 0x00D0EE08
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idRaceCamera::Draw_1(idRaceCamera *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r31
  int v6; // r3
  const char *v7; // r7
  idPresentable *v8; // r3
  int v9; // r31
  idPhysics *Physics; // r3
  float *v11; // r3
  char v13; // [sp+50h] [-40h] BYREF

  if ( !gameLocal->MainMenu_IsActive(this: gameLocal) && this->gui != nullptr )
  {
    presentable = player->presentable;
    if ( presentable != nullptr )
      v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = 0;
    v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idSWF::Render(this: this->gui, gui: *(idRenderModelGui **)(v5 + 16224), time: v6, isSplitscreen: false, a5: v7);
  }
  if ( racecam_New.valueInteger == 0 )
    return idCameraView::Draw(this, player);
  v8 = player->presentable;
  if ( v8 != nullptr )
    v9 = (int)v8->GetPlayerInterface_2(this: v8);
  else
    v9 = 0;
  idView::SetViewPos(this: (idView *)(v9 + 16224), origin: &this->cameraPos, angles: &this->cameraAngles);
  Physics = idEntity::GetPhysics(this);
  v11 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v13, result: (idVec3 *)Physics, a3: 0);
  *(float *)(v9 + 18124) = *v11;
  *(float *)(v9 + 18128) = v11[1];
  *(float *)(v9 + 18132) = v11[2];
  idView::SetViewID(this: (idView *)(v9 + 16224), id: player->entityNumber + 1);
  idView::Render(this: (idView *)(v9 + 16224));
  return 1;
}


// ========================================================================
// ??0idDeathCamera@@QAA@XZ
// EA  : 0x82D0EF70
// RVA : 0x00D0EF70
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idDeathCamera *__fastcall idDeathCamera::idDeathCamera(idDeathCamera *this)
{
  int v2; // ctr
  idEntityPtr<idVehicle_Car> *p_vehicle; // r9
  float *p_y; // r10

  idCameraView::idCameraView(this);
  this->__vftable = (idDeathCamera_vtbl *)&idDeathCamera::`vftable';
  v2 = 9;
  p_vehicle = &this->vehicle;
  p_y = &mat2_identity.mat[1].y;
  this->startPos = vec3_origin;
  this->focusPos = vec3_origin;
  this->goalPos = vec3_origin;
  this->findValidGoalPos = true;
  this->focusAngles = ang_zero;
  this->vehicle.spawnId.value = 0x1FFF;
  do
  {
    ++p_y;
    ++p_vehicle;
    p_vehicle->spawnId.value = *(int *)p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->cameraPos = vec3_origin;
  return this;
}


// ========================================================================
// ?Think@idDeathCamera@@UAAXXZ
// EA  : 0x82D0F068
// RVA : 0x00D0F068
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idDeathCamera::Think(idDeathCamera *this)
{
  idPhysics *Physics; // r3
  int v3; // r3
  float v4; // r7
  float v5; // r6
  BOOL findValidGoalPos; // r9
  double v7; // fp0
  double v8; // fp13
  __int64 v9; // r9
  unsigned int v10; // r6
  double v11; // fp30
  idVec3 *v12; // r3
  double v13; // fp1
  double v14; // fp0
  int entityNumber; // r9
  double y; // fp13
  double z; // fp12
  int value; // r10
  idVehicle_Car *v19; // r3
  idVehicle_Car *v20; // r3
  int v21; // r9
  idEntity *v22; // r3
  idEntity *v23; // r3
  idPhysics *v24; // r3
  float *v25; // r3
  double v26; // fp12
  double v27; // fp13
  double v28; // fp3
  double v29; // fp1
  idPhysics *v30; // r3
  idPhysics *v31; // r3
  idQuat *v32; // r3
  double v33; // fp6
  double v34; // fp5
  idQuat *v35; // r3
  idPhysics *v36; // r30
  idPhysics_vtbl *v37; // r29
  idMat3 *v38; // r3
  idPlayer *PlayerActivator; // r3
  idPlayer *v40; // r30
  idPresentable *presentable; // r3
  int v42; // r3
  idPresentable *v43; // r3
  int v44; // r3
  idPhysics *v45; // r3
  float *v46; // r3
  idPhysics *v47; // r3
  float *v48; // r3
  float v49; // [sp+50h] [-170h] BYREF
  float v50; // [sp+54h] [-16Ch]
  float v51; // [sp+58h] [-168h]
  idVec3 v52; // [sp+60h] [-160h] BYREF
  idMat3 v53; // [sp+70h] [-150h] BYREF
  idMat3 v54; // [sp+A0h] [-120h] BYREF
  idQuat v55[3]; // [sp+D0h] [-F0h] BYREF
  trace_t v56; // [sp+100h] [-C0h] BYREF

  Physics = idEntity::GetPhysics(this);
  v3 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v4 = *(float *)(v3 + 4);
  v5 = *(float *)(v3 + 8);
  findValidGoalPos = this->findValidGoalPos;
  v49 = *(float *)v3;
  v50 = v4;
  v51 = v5;
  if ( findValidGoalPos )
  {
    v7 = (float)(this->focusAngles.pitch + (float)0.5);
    v8 = -90.0;
    this->focusAngles.yaw = this->focusAngles.yaw + (float)12.0;
    if ( v7 < -90.0 || (v8 = 10.0, v7 > 10.0) )
      v7 = v8;
    this->focusAngles.pitch = v7;
    idAngles::Normalize180(this: &this->focusAngles);
    HIDWORD(v9) = &unk_82150000;
    v10 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v10 + 1013904223;
    LODWORD(v9) = ((v10 + 1013904223) >> 10) & 0x7FFF;
    *(_QWORD *)&v53.mat[1].y = v9;
    v11 = (float)((float)((float)((float)v9 * (float)0.000030518509) + (float)1.0) * (float)1000.0);
    v12 = idAngles::ToForward(this: (idAngles *)&v54.mat[2].z, result: (idVec3 *)&this->focusAngles);
    v13 = (float)(v12->y * (float)v11);
    v14 = (float)(v12->z * (float)v11);
    entityNumber = this->entityNumber;
    v52.x = v49 + (float)((float)v11 * v12->x);
    v52.y = v50 + (float)v13;
    v52.z = v51 + (float)v14;
    idClip::TraceBounds(
      this: &clientGame->clip,
      result: &v56,
      start: &this->focusPos,
      end: &v52,
      trm: clientGame->clip.clip8x8,
      clipMask: 107553,
      passEntityNumber: entityNumber);
    if ( v56.fraction == 1.0 )
    {
      y = v52.y;
      z = v52.z;
      this->goalPos.x = v52.x;
      this->goalPos.y = y;
      this->goalPos.z = z;
      this->findValidGoalPos = false;
    }
  }
  if ( !this->findValidGoalPos )
  {
    value = this->vehicle.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v19 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v19 != nullptr )
      {
        v20 = idVehicle_Car::CastTo(c: v19);
        if ( v20 != nullptr )
        {
          v21 = v20->lastDamage.attacker.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v21 & 0x1FFF] == v21 >> 13
            && (v22 = gameLocal->entities.ptr[v21 & 0x1FFF]) != nullptr
            && (v23 = idEntity::CastTo(c: v22)) != nullptr )
          {
            v24 = idEntity::GetPhysics(this: v23);
            v25 = (float *)v24->GetOrigin(this: v24, a2: 0);
            this->focusPos.x = *v25;
            this->focusPos.y = v25[1];
            v26 = v25[2];
          }
          else
          {
            v27 = v50;
            v26 = v51;
            this->focusPos.x = v49;
            this->focusPos.y = v27;
          }
          this->focusPos.z = v26;
        }
      }
    }
  }
  v28 = (float)((float)(this->goalPos.z - v51) * deathcam_goalLerpRate.valueFloat);
  v29 = (float)((float)((float)(this->goalPos.y - v50) * deathcam_goalLerpRate.valueFloat) + v50);
  v49 = (float)((float)(this->goalPos.x - v49) * deathcam_goalLerpRate.valueFloat) + v49;
  v50 = v29;
  v51 = (float)v28 + v51;
  v30 = idEntity::GetPhysics(this);
  v30->SetOrigin(this: v30, a2: (const idVec3 *)&v49, a3: -1);
  v31 = idEntity::GetPhysics(this);
  v32 = (idQuat *)v31->GetAxis(this: v31, a2: 0);
  idMat3::ToQuat(this: (idMat3 *)&v54.mat[1].y, result: v32);
  v33 = (float)(this->focusPos.y - v50);
  v34 = (float)(this->focusPos.z - v51);
  v53.mat[0].x = this->focusPos.x - v49;
  v53.mat[0].y = v33;
  v53.mat[0].z = v34;
  v35 = (idQuat *)idVec3::ToMat3(this: (idVec3 *)v55, result: &v53);
  idMat3::ToQuat(this: (idMat3 *)&v53.mat[2].z, result: v35);
  idQuat::Lerp(
    this: (idQuat *)&v54,
    from: (const idQuat *)&v54.mat[1].y,
    to: (const idQuat *)&v53.mat[2].z,
    t: deathcam_focusLerpRate.valueFloat);
  v36 = idEntity::GetPhysics(this);
  v37 = v36->__vftable;
  v38 = idQuat::ToMat3(this: v55, result: &v54);
  v37->SetAxis(this: v36, a2: v38, a3: -1);
  PlayerActivator = idCamera::GetPlayerActivator(this);
  v40 = PlayerActivator;
  if ( PlayerActivator != nullptr )
  {
    presentable = PlayerActivator->presentable;
    if ( presentable != nullptr )
      v42 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v42 = 0;
    idView::ResetControllerShake(this: (idView *)(v42 + 16224));
    v43 = v40->presentable;
    if ( v43 != nullptr )
      v44 = (int)v43->GetPlayerInterface_2(this: v43);
    else
      v44 = 0;
    *(float *)(v44 + 19128) = 0.0;
  }
  v45 = idEntity::GetPhysics(this);
  v46 = (float *)v45->GetAxis(this: v45, a2: 0);
  this->camersAxis.mat[0].x = *v46;
  this->camersAxis.mat[0].y = v46[1];
  this->camersAxis.mat[0].z = v46[2];
  this->camersAxis.mat[1].x = v46[3];
  this->camersAxis.mat[1].y = v46[4];
  this->camersAxis.mat[1].z = v46[5];
  this->camersAxis.mat[2].x = v46[6];
  this->camersAxis.mat[2].y = v46[7];
  this->camersAxis.mat[2].z = v46[8];
  v47 = idEntity::GetPhysics(this);
  v48 = (float *)v47->GetOrigin(this: v47, a2: 0);
  this->cameraPos.x = *v48;
  this->cameraPos.y = v48[1];
  this->cameraPos.z = v48[2];
}


// ========================================================================
// ??0idReviveCamera@@QAA@XZ
// EA  : 0x82D0F540
// RVA : 0x00D0F540
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idReviveCamera *__fastcall idReviveCamera::idReviveCamera(idReviveCamera *this)
{
  idCameraView::idCameraView(this);
  this->__vftable = (idReviveCamera_vtbl *)&idReviveCamera::`vftable';
  return this;
}


// ========================================================================
// ?Init@idReviveCamera@@UAAXVidVec3@@VidMat3@@PAVidPresentablePlayer@@@Z
// EA  : 0x82D0F580
// RVA : 0x00D0F580
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idReviveCamera::Init(
        idReviveCamera *this,
        idVec3 *origin,
        __int64 _activator,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        int a16,
        const idPresentablePlayer *a17)
{
  idEntity *v17; // r3
  idEntity *v18; // r31
  idPhysics *Physics; // r3
  idPhysics *v20; // r3
  idPresentable *presentable; // r3
  idPresentableReviveCamera *v22; // r3

  a9 = *(_QWORD *)&origin;
  v18 = v17;
  a10 = *(__int64 *)((char *)&_activator + 4);
  a11 = _activator;
  a12 = *(__int64 *)((char *)&a4 + 4);
  a13 = a4;
  a14 = *(__int64 *)((char *)&a5 + 4);
  a15 = a5;
  Physics = idEntity::GetPhysics(this: v17);
  Physics->SetOrigin(this: Physics, a2: (const idVec3 *)&a9, a3: -1);
  v20 = idEntity::GetPhysics(this: v18);
  v20->SetAxis(this: v20, a2: (const idMat3 *)&a11, a3: -1);
  presentable = v18->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: v18);
    presentable = v18->presentable;
  }
  v22 = presentable->GetReviveCameraInterface(this: presentable);
  idPresentableReviveCamera::InitSerializedState(this: v22, player: a17);
}


// ========================================================================
// ?Init@idPresentableReviveCamera@@QAAXH@Z
// EA  : 0x82D0F630
// RVA : 0x00D0F630
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idPresentableReviveCamera::Init(idPresentableReviveCamera *this, int curTime)
{
  int initializedState; // r11
  unsigned int spawnId; // r10
  int v5; // r30
  idPresentable *PresentableByIndex; // r3
  unsigned int v7; // r7
  int v8; // r30
  idPresentable *v9; // r11
  double y; // fp13
  float v11; // [sp+50h] [-40h]
  idMat3 v12; // [sp+60h] [-30h] BYREF

  initializedState = this->initializedState;
  this->startTime = curTime;
  this->prevInitializedState = initializedState;
  spawnId = this->playerPresentable.spawnId;
  v5 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v5))->spawnId != this->playerPresentable.spawnId )
  {
    PresentableByIndex = nullptr;
  }
  v11 = *(float *)&PresentableByIndex[38].fxManager.actionBuffer[5].time;
  this->prevCmdYaw = *(float *)&PresentableByIndex[38].fxManager.actionBuffer[5].extraCondition;
  this->prevCmdPitch = v11;
  v7 = this->playerPresentable.spawnId;
  v8 = v7 & 0x3FFF;
  if ( v7 == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v7 & 0x3FFF)
    || (v9 = idClientGame::GetPresentableByIndex(this: clientGame, index: v8))->spawnId != this->playerPresentable.spawnId )
  {
    v9 = nullptr;
  }
  idMat3::ToAngles(this: &v12, result: (idAngles *)&v9[38].fxManager.actionBuffer[6].condition);
  y = v12.mat[0].y;
  this->currentPitch = v12.mat[0].x;
  this->currentYaw = y;
}


// ========================================================================
// ?ClientThink@idPresentableReviveCamera@@UAAXHM_N@Z
// EA  : 0x82D0F740
// RVA : 0x00D0F740
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idPresentableReviveCamera::ClientThink(
        idPresentableReviveCamera *this,
        unsigned int curTime,
        double fraction,
        bool predict)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentablePlayer> *p_playerPresentable; // r30
  int v8; // r29
  float v9; // r7
  __int64 v10; // r4
  double v11; // fp0
  double v12; // fp13
  idPresentable *v13; // r3
  float v14; // r5
  double v15; // fp0
  double v16; // fp0
  double v17; // fp13
  double v18; // fp0
  double v19; // fp10
  double v22; // fp2
  double v23; // fp5
  double v24; // fp2
  float v25; // [sp+54h] [-8Ch]
  float v26; // [sp+58h] [-88h]
  idMat3 v27[2]; // [sp+60h] [-80h] BYREF

  spawnId = this->playerPresentable.spawnId;
  p_playerPresentable = &this->playerPresentable;
  v8 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v8)->spawnId == p_playerPresentable->spawnId )
  {
    if ( this->prevInitializedState != this->initializedState )
      idPresentableReviveCamera::Init(this, curTime);
    HIDWORD(v10) = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)p_playerPresentable);
    v9 = *(float *)(HIDWORD(v10) + 120);
    v26 = *(float *)(HIDWORD(v10) + 128);
    this->viewOrigin.y = *(float *)(HIDWORD(v10) + 124);
    this->viewOrigin.x = v9;
    this->viewOrigin.z = v26;
    LODWORD(v10) = this->startTime;
    v11 = (float)((float)((float)__SPAIR64__("DistToTarget: %f dist: %f \n", curTime) - (float)v10)
                * (float)0.00055555557);
    if ( v11 >= 0.0 )
    {
      v12 = 1.0;
      if ( v11 <= 1.0 )
        v12 = (float)((float)((float)__SPAIR64__("DistToTarget: %f dist: %f \n", curTime) - (float)v10)
                    * (float)0.00055555557);
    }
    else
    {
      v12 = 0.0;
    }
    this->viewOrigin.z = (float)(revivecam_HeightEnd.valueFloat * (float)v12)
                       + (float)(revivecam_HeightStart.valueFloat + v26);
    v13 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)p_playerPresentable);
    v14 = *(float *)&v13[38].fxManager.actionBuffer[5].time;
    v15 = (float)(v14 - this->prevCmdPitch);
    v25 = *(float *)&v13[38].fxManager.actionBuffer[5].extraCondition;
    if ( v15 > 45.0 || v15 < -45.0 )
      v15 = 0.0;
    v16 = (float)(this->currentPitch + (float)v15);
    this->prevCmdPitch = v14;
    v17 = -85.0;
    if ( v16 >= -85.0 )
    {
      v17 = 85.0;
      if ( v16 <= 85.0 )
        v17 = v16;
    }
    v18 = (float)(v25 - this->prevCmdYaw);
    this->currentPitch = v17;
    if ( v18 > 45.0 || v18 < -45.0 )
      v18 = 0.0;
    v19 = (float)(this->currentYaw + (float)v18);
    v27[0].mat[1].y = v17;
    this->prevCmdYaw = v25;
    this->currentYaw = v19;
    v27[0].mat[2].x = 0.0;
    v27[0].mat[1].z = v19;
    idAngles::ToForward(this: (idAngles *)v27, result: (idVec3 *)&v27[0].mat[1].y);
    _FP5 = (float)((float)((float)(v27[0].mat[0].x * v27[0].mat[0].x)
                         + (float)((float)(v27[0].mat[0].z * v27[0].mat[0].z)
                                 + (float)(v27[0].mat[0].y * v27[0].mat[0].y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f5, f6, f12 }
    v22 = __frsqrte(_FP3);
    v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)((float)(v27[0].mat[0].x * v27[0].mat[0].x) + (float)((float)(v27[0].mat[0].z * v27[0].mat[0].z) + (float)(v27[0].mat[0].y * v27[0].mat[0].y)))
                                                                                                * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22)
                                                * (float)((float)((float)(v27[0].mat[0].x * v27[0].mat[0].x)
                                                                + (float)((float)(v27[0].mat[0].z * v27[0].mat[0].z)
                                                                        + (float)(v27[0].mat[0].y * v27[0].mat[0].y)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v22
                                                                                * (float)((float)((float)(v27[0].mat[0].x * v27[0].mat[0].x)
                                                                                                + (float)((float)(v27[0].mat[0].z * v27[0].mat[0].z) + (float)(v27[0].mat[0].y * v27[0].mat[0].y)))
                                                                                        * (float)0.5))
                                                                        * (float)v22)
                                                                - (float)1.5)
                                                * (float)v22))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v22
                                                        * (float)((float)((float)(v27[0].mat[0].x * v27[0].mat[0].x)
                                                                        + (float)((float)(v27[0].mat[0].z
                                                                                        * v27[0].mat[0].z)
                                                                                + (float)(v27[0].mat[0].y
                                                                                        * v27[0].mat[0].y)))
                                                                * (float)0.5))
                                                * (float)v22)
                                        - (float)1.5)
                        * (float)v22));
    v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v27[0].mat[0].x * v27[0].mat[0].x) + (float)((float)(v27[0].mat[0].z * v27[0].mat[0].z) + (float)(v27[0].mat[0].y * v27[0].mat[0].y))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                * (float)v22)
                                                                                        * (float)((float)((float)(v27[0].mat[0].x * v27[0].mat[0].x) + (float)((float)(v27[0].mat[0].z * v27[0].mat[0].z) + (float)(v27[0].mat[0].y * v27[0].mat[0].y)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(v27[0].mat[0].x * v27[0].mat[0].x) + (float)((float)(v27[0].mat[0].z * v27[0].mat[0].z) + (float)(v27[0].mat[0].y * v27[0].mat[0].y))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                        * (float)v22))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v22
                                                                                                * (float)((float)((float)(v27[0].mat[0].x * v27[0].mat[0].x) + (float)((float)(v27[0].mat[0].z * v27[0].mat[0].z) + (float)(v27[0].mat[0].y * v27[0].mat[0].y))) * (float)0.5))
                                                                                        * (float)v22)
                                                                                - (float)1.5)
                                                                * (float)v22))
                                                * (float)((float)((float)(v27[0].mat[0].x * v27[0].mat[0].x)
                                                                + (float)((float)(v27[0].mat[0].z * v27[0].mat[0].z)
                                                                        + (float)(v27[0].mat[0].y * v27[0].mat[0].y)))
                                                        * (float)0.5))
                                        * (float)v23)
                                - (float)1.5)
                * (float)v23);
    v27[0].mat[0].y = v27[0].mat[0].y * (float)v24;
    v27[0].mat[0].x = v27[0].mat[0].x * (float)v24;
    v27[0].mat[0].z = v27[0].mat[0].z * (float)v24;
    this->viewAxis = *idVec3::ToMat3(this: (idVec3 *)&v27[0].mat[2].z, result: v27);
  }
}


// ========================================================================
// ?Serialize@idPresentableReviveCamera@@UAAXAAVidSerializer@@@Z
// EA  : 0x82D0FA40
// RVA : 0x00D0FA40
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idPresentableReviveCamera::Serialize(idPresentableReviveCamera *this, idSerializer *ser)
{
  idBitMsg *msg; // r3

  idPresentable::Serialize(this, ser);
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->playerPresentable.spawnId, numBits: 32);
  else
    this->playerPresentable.spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
  netBoolEvent_t::Serialize(this: &this->reset, ser);
}


// ========================================================================
// ?PostSerializeRead@idPresentableReviveCamera@@UAAX_N@Z
// EA  : 0x82D0FAB0
// RVA : 0x00D0FAB0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idPresentableReviveCamera::PostSerializeRead(idPresentableReviveCamera *this, bool firstClientFrame)
{
  unsigned int spawnId; // r11
  int v4; // r30
  int count; // r10
  char v6; // r11
  int GameMs; // r3

  spawnId = this->playerPresentable.spawnId;
  v4 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v4)->spawnId == this->playerPresentable.spawnId )
  {
    count = this->reset.count;
    if ( count == this->reset.lastCount )
    {
      v6 = 0;
    }
    else
    {
      this->reset.lastCount = count;
      v6 = 1;
    }
    if ( v6 != 0 )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idPresentableReviveCamera::Init(this, curTime: GameMs);
    }
  }
}


// ========================================================================
// ??0idOnlineVehicleDeathCamera@@QAA@XZ
// EA  : 0x82D0FB60
// RVA : 0x00D0FB60
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idOnlineVehicleDeathCamera *__fastcall idOnlineVehicleDeathCamera::idOnlineVehicleDeathCamera(
        idOnlineVehicleDeathCamera *this)
{
  idDeathCamera::idDeathCamera(this);
  this->__vftable = (idOnlineVehicleDeathCamera_vtbl *)&idOnlineVehicleDeathCamera::`vftable';
  return this;
}


// ========================================================================
// ?Init@idOnlineVehicleDeathCamera@@UAAXPBVidPresentableVehicle@@0PBVidPresentablePlayer@@@Z
// EA  : 0x82D0FBA0
// RVA : 0x00D0FBA0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idOnlineVehicleDeathCamera::Init(
        idOnlineVehicleDeathCamera *this,
        const idPresentableVehicle *attacker,
        const idPresentableVehicle *playerVehicle,
        const idPresentablePlayer *playerPresentable)
{
  idPresentable *presentable; // r3
  idOnlineVehicleDeathCameraPresentable *v9; // r3
  unsigned int spawnId; // r11

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v9 = presentable->GetVehicleCameraInterface(this: presentable);
  spawnId = 0;
  if ( attacker != nullptr )
    v9->attackerPresentable.spawnId = attacker->spawnId;
  else
    v9->attackerPresentable.spawnId = 0;
  if ( playerVehicle != nullptr )
    v9->playerVehiclePresentable.spawnId = playerVehicle->spawnId;
  else
    v9->playerVehiclePresentable.spawnId = 0;
  if ( playerPresentable != nullptr )
    spawnId = playerPresentable->spawnId;
  v9->playerPresentable.spawnId = spawnId;
  ++v9->initializedState;
}


// ========================================================================
// ??0idOnlineVehicleDeathCameraPresentable@@QAA@PAVidEntity@@@Z
// EA  : 0x82D0FC40
// RVA : 0x00D0FC40
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idOnlineVehicleDeathCameraPresentable::idOnlineVehicleDeathCameraPresentable(
        idOnlineVehicleDeathCameraPresentable *this,
        idEntity *ent)
{
  unsigned __int64 v3; // r11

  idPresentable::idPresentable(this, e: ent, renderModel_: nullptr, entityNumber_: ent->entityNumber, fxDecl_: nullptr);
  HIDWORD(v3) = "DistToTarget: %f dist: %f \n";
  LODWORD(v3) = 0;
  this->__vftable = (idOnlineVehicleDeathCameraPresentable_vtbl *)&idOnlineVehicleDeathCameraPresentable::`vftable';
  this->attackerPresentable.spawnId = 0;
  this->playerVehiclePresentable.spawnId = 0;
  this->playerPresentable.spawnId = 0;
  this->traceResult.index = v3;
  this->hitCamResult.index = v3;
  idOnlineVehicleDeathCameraPresentable::SetDefaults(this);
}


// ========================================================================
// ?Init@idOnlineVehicleDeathCameraPresentable@@QAAXH@Z
// EA  : 0x82D0FCA8
// RVA : 0x00D0FCA8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idOnlineVehicleDeathCameraPresentable::Init(idOnlineVehicleDeathCameraPresentable *this, int curTime)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_playerVehiclePresentable; // r26
  int v6; // r30
  idPresentable *PresentableByIndex; // r3
  float v8; // r5
  char *v9; // r9
  float v10; // r7
  int *p_time; // r11
  double x; // fp13
  int v13; // ctr
  double v14; // fp13
  double v15; // fp11
  double v16; // fp12
  double v17; // fp11
  double v18; // fp9
  double v19; // fp7
  double v22; // fp4
  double v23; // fp3
  double v24; // fp12
  idVec3 *p_targetPosPrev; // r30
  int valueInteger; // r11
  idRenderWorld *v27; // r3
  idRenderWorld *v28; // r3
  double valueFloat; // fp31
  int v30; // r28
  idPresentable *v31; // r3
  double v32; // fp31
  double v33; // fp30
  int v34; // r30
  idPresentable *v35; // r3
  __int64 v36; // r7
  idPresentable *v37; // r3
  idClientGame *v38; // r11
  idPresentable *v39; // r3
  double v40; // fp7
  double v41; // fp6
  double y; // fp1
  double z; // fp13
  double v44; // fp8
  double v45; // fp7
  idPresentable *v46; // r3
  int v47; // [sp+8h] [-F8h]
  bool v48; // [sp+Fh] [-F1h]
  const char *v49; // [sp+10h] [-F0h]
  int v50; // [sp+14h] [-ECh]
  int v51; // [sp+18h] [-E8h]
  int v52; // [sp+1Ch] [-E4h]
  int v53; // [sp+20h] [-E0h]
  int v54; // [sp+24h] [-DCh]
  int v55; // [sp+28h] [-D8h]
  int v56; // [sp+2Ch] [-D4h]
  int v57; // [sp+30h] [-D0h]
  int v58; // [sp+34h] [-CCh]
  int v59; // [sp+38h] [-C8h]
  int v60; // [sp+3Ch] [-C4h]
  int v61; // [sp+40h] [-C0h]
  int v62; // [sp+44h] [-BCh]
  int v63; // [sp+48h] [-B8h]
  int v64; // [sp+4Ch] [-B4h]
  int v65; // [sp+50h] [-B0h]
  int v66; // [sp+58h] [-A8h]
  int v67; // [sp+60h] [-A0h]
  idVec3 v68; // [sp+70h] [-90h] BYREF
  char v69; // [sp+7Ch] [-84h] BYREF
  float v70; // [sp+80h] [-80h]
  float v71; // [sp+84h] [-7Ch]
  float v72; // [sp+88h] [-78h]
  float v73; // [sp+8Ch] [-74h]
  float v74; // [sp+90h] [-70h]
  float v75; // [sp+94h] [-6Ch]
  float v76; // [sp+98h] [-68h]
  float v77; // [sp+9Ch] [-64h]
  float v78; // [sp+A0h] [-60h]

  spawnId = this->playerVehiclePresentable.spawnId;
  p_playerVehiclePresentable = (idPresentablePtr<idPresentable> *)&this->playerVehiclePresentable;
  v6 = spawnId & 0x3FFF;
  if ( spawnId != 0 && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF) )
  {
    PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v6);
    if ( PresentableByIndex->spawnId == p_playerVehiclePresentable->spawnId )
    {
      v8 = *(float *)&PresentableByIndex[15].fxManager.actionBuffer[5].condition;
      v9 = &v69;
      v10 = *(float *)&PresentableByIndex[15].fxManager.actionBuffer[5].time;
      p_time = &PresentableByIndex[15].fxManager.actionBuffer[5].time;
      v68.x = PresentableByIndex[15].fxManager.actionBuffer[5].axis.mat[2].z;
      x = v68.x;
      v68.y = v8;
      v68.z = v10;
      this->prevOrigin.z = v10;
      v13 = 9;
      this->prevOrigin.y = v8;
      this->prevOrigin.x = x;
      do
      {
        ++p_time;
        v9 += 4;
        *(_DWORD *)v9 = *p_time;
        --v13;
      }
      while ( v13 != 0 );
      this->prevAxis.mat[0].x = v70;
      v14 = v73;
      v15 = v72;
      this->prevAxis.mat[0].y = v71;
      this->prevAxis.mat[1].x = v14;
      this->prevAxis.mat[0].z = v15;
      this->prevAxis.mat[1].y = v74;
      this->prevAxis.mat[1].z = v75;
      this->prevAxis.mat[2].x = v76;
      this->prevAxis.mat[2].y = v77;
      this->prevAxis.mat[2].z = v78;
      v16 = (float)(PresentableByIndex->origin.y - this->prevOrigin.y);
      v17 = (float)(PresentableByIndex->origin.z - this->prevOrigin.z);
      v18 = (float)(PresentableByIndex->origin.x - this->prevOrigin.x);
      v19 = (float)((float)((float)v18 * (float)v18)
                  + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)));
      _FP6 = (float)((float)((float)((float)v18 * (float)v18)
                           + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f5, f6, f7, f13 }
      v22 = (float)((float)((float)((float)v18 * (float)v18)
                          + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                  * (float)0.5);
      v23 = __frsqrte(_FP5);
      v24 = (float)((float)-(float)((float)((float)((float)v23
                                                  * (float)((float)((float)((float)v18 * (float)v18)
                                                                  + (float)((float)((float)v17 * (float)v17)
                                                                          + (float)((float)v16 * (float)v16)))
                                                          * (float)0.5))
                                          * (float)v23)
                                  - (float)1.5)
                  * (float)v23);
      this->distToTarget = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)v22)
                                                                                                 * (float)v24)
                                                                                         - (float)1.5)
                                                                         * (float)v24)
                                                                 * (float)v22)
                                                         * (float)((float)-(float)((float)((float)((float)v24
                                                                                                 * (float)v22)
                                                                                         * (float)v24)
                                                                                 - (float)1.5)
                                                                 * (float)v24))
                                                 - (float)1.5)
                                 * (float)((float)-(float)((float)((float)((float)v24 * (float)v22) * (float)v24)
                                                         - (float)1.5)
                                         * (float)v24))
                         * (float)v19;
    }
  }
  p_targetPosPrev = &this->targetPosPrev;
  this->targetPosPrev = vec3_origin;
  valueInteger = cam_onlineDeathDebug.valueInteger;
  if ( cam_onlineDeathDebug.valueInteger != 0 )
  {
    v27 = gameLocal->GetRenderWorld(this: gameLocal);
    v27->DebugAxis_2(this: v27, a2: &this->prevOrigin, a3: &this->prevAxis, a4: 60000, a5: false);
    v28 = gameLocal->GetRenderWorld(this: gameLocal);
    v28->DebugPoint(this: v28, a2: (const idVec4 *)&idColor::colorRed, a3: &this->prevOrigin, a4: 60000, a5: false);
    valueInteger = cam_onlineDeathDebug.valueInteger;
  }
  if ( cam_onlineDeathCamSpecial.valueInteger != 0 )
  {
    if ( valueInteger != 0 )
      idLib::Printf(fmt: "^4DistToTarget: %f\n", this->distToTarget);
  }
  else if ( cam_onlineDeathCamStatic.valueInteger != 0 )
  {
    if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->playerPresentable) )
    {
      valueFloat = cam_deathCamblurAmount.valueFloat;
      v30 = (int)(float)(cam_deathCamblurTime.valueFloat * (float)1000.0);
      v31 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->playerPresentable);
      idView::ForceBlurValues(
        this: (idView *)&v31[13].fxManager.actionBuffer[2].axis.mat[1].z,
        blurBegin: 0.0,
        blurEnd: valueFloat,
        blurTime: (float)__SPAIR64__(0x82000000, v30));
      v32 = cam_onlineDeathCamDblStop.valueFloat;
      v33 = cam_onlineDeathCamDblStart.valueFloat;
      v34 = (int)(float)(cam_onlineDeathCamDblDuration.valueFloat * 1000.0);
      v35 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->playerPresentable);
      LODWORD(v36) = v34;
      *(_QWORD *)&v68.x = v36;
      idView::ForceDoubleVisionValues(
        this: (idView *)&v35[13].fxManager.actionBuffer[2].axis.mat[1].z,
        dblDuration: (float)v36,
        dblStart: v33,
        dblEnd: v32);
    }
  }
  else if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->attackerPresentable) )
  {
    v37 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->attackerPresentable);
    v38 = clientGame;
    p_targetPosPrev->x = v37->origin.x;
    this->targetPosPrev.y = v37->origin.y;
    this->targetPosPrev.z = v37->origin.z;
    this->traceResult.index = *(_QWORD *)&idClip::Translation(
                                            this: (idClip *)&v68,
                                            result: &v38->clip,
                                            a3: nullptr,
                                            start: &this->targetPosPrev,
                                            end: &this->prevOrigin,
                                            clipModel: v38->clip.clip8x8,
                                            startAxis: &mat3_identity,
                                            clipMask: 1,
                                            passEntityNumber: v47,
                                            moveClipModel: v48,
                                            userName: v49,
                                            a12: v50,
                                            a13: v51,
                                            a14: v52,
                                            a15: v53,
                                            a16: v54,
                                            a17: v55,
                                            a18: v56,
                                            a19: v57,
                                            a20: v58,
                                            a21: v59,
                                            a22: v60,
                                            a23: v61,
                                            a24: v62,
                                            a25: v63,
                                            a26: v64,
                                            a27: v65,
                                            a28: this->entityNumber,
                                            a29: v66,
                                            a30: false,
                                            a31: v67,
                                            a32: (int)"w:\\tech5\\tungsten\\game\\entities\\UtilityCamera.cpp(6185) : Translation")->world;
    v39 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->attackerPresentable);
    v40 = (float)(v39->axis.mat[0].y * (float)-1.0);
    v41 = (float)(v39->axis.mat[0].z * (float)-1.0);
    v68.x = (float)(v39->axis.mat[0].x * (float)-1.0) + vec3_up.x;
    v68.y = vec3_up.y + (float)v40;
    v68.z = (float)v41 + vec3_up.z;
    idVec3::NormalizeFast(this: &v68);
    y = this->targetPosPrev.y;
    z = this->targetPosPrev.z;
    v44 = (float)(cam_onlineDeathCamCircleOffset.valueFloat * v68.y);
    v45 = (float)(cam_onlineDeathCamCircleOffset.valueFloat * v68.z);
    this->goalPos.x = p_targetPosPrev->x + (float)(cam_onlineDeathCamCircleOffset.valueFloat * v68.x);
    this->goalPos.y = (float)v44 + (float)y;
    this->goalPos.z = (float)v45 + (float)z;
  }
  else
  {
    v46 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_playerVehiclePresentable);
    p_targetPosPrev->x = v46->origin.x;
    this->targetPosPrev.y = v46->origin.y;
    this->targetPosPrev.z = v46->origin.z;
  }
  this->startingOrigin.x = this->prevOrigin.x;
  this->startingOrigin.y = this->prevOrigin.y;
  this->startingOrigin.z = this->prevOrigin.z;
  this->viewAxis.mat[0].x = this->prevAxis.mat[0].x;
  this->viewAxis.mat[0].y = this->prevAxis.mat[0].y;
  this->viewAxis.mat[0].z = this->prevAxis.mat[0].z;
  this->viewAxis.mat[1].x = this->prevAxis.mat[1].x;
  this->viewAxis.mat[1].y = this->prevAxis.mat[1].y;
  this->viewAxis.mat[1].z = this->prevAxis.mat[1].z;
  this->viewAxis.mat[2].x = this->prevAxis.mat[2].x;
  this->viewAxis.mat[2].y = this->prevAxis.mat[2].y;
  this->viewAxis.mat[2].z = this->prevAxis.mat[2].z;
  this->viewOrigin.x = this->prevOrigin.x;
  this->viewOrigin.y = this->prevOrigin.y;
  this->viewOrigin.z = this->prevOrigin.z;
  this->startTime = curTime;
  this->prevInitializedState = this->initializedState;
}


// ========================================================================
// ?Serialize@idOnlineVehicleDeathCameraPresentable@@UAAXAAVidSerializer@@@Z
// EA  : 0x82D10210
// RVA : 0x00D10210
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idOnlineVehicleDeathCameraPresentable::Serialize(
        idOnlineVehicleDeathCameraPresentable *this,
        idSerializer *ser)
{
  idBitMsg *msg; // r3
  idBitMsg *v5; // r3
  idBitMsg *v6; // r3
  idBitMsg *v7; // r3

  idPresentable::Serialize(this, ser);
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->attackerPresentable.spawnId, numBits: 32);
  else
    this->attackerPresentable.spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
  v5 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v5, value: this->playerVehiclePresentable.spawnId, numBits: 32);
  else
    this->playerVehiclePresentable.spawnId = idBitMsg::ReadBits(this: v5, numBits: 32);
  v6 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v6, value: this->playerPresentable.spawnId, numBits: 32);
  else
    this->playerPresentable.spawnId = idBitMsg::ReadBits(this: v6, numBits: 32);
  v7 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v7, value: this->initializedState, numBits: 32);
  else
    this->initializedState = idBitMsg::ReadBits(this: v7, numBits: 32);
}


// ========================================================================
// ?ClientThink@idOnlineVehicleDeathCameraPresentable@@UAAXHM_N@Z
// EA  : 0x82D102F8
// RVA : 0x00D102F8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idOnlineVehicleDeathCameraPresentable::ClientThink(
        idOnlineVehicleDeathCameraPresentable *this,
        unsigned int curTime,
        double fraction,
        bool predict)
{
  unsigned __int64 v5; // r28
  bool v6; // r30
  int v7; // r3
  unsigned int spawnId; // r6
  int v9; // r29
  idPresentable *v10; // r3
  float y; // r10
  float z; // r9
  __int64 v13; // r5
  __int64 v14; // r3
  double v15; // fp0
  idVec3 *p_origin; // r11
  float v17; // r10
  float x; // r9
  float v19; // r8
  double distToTarget; // fp31
  double v21; // fp28
  double v22; // fp29
  double v25; // fp4
  double v26; // fp10
  double v27; // fp30
  int entityNumber; // r9
  double v29; // fp12
  double v30; // fp13
  double v31; // fp0
  double v32; // fp9
  double v33; // fp7
  double v34; // fp6
  double valueFloat; // fp31
  idQuat *v36; // r3
  const idQuat *v37; // r29
  const idQuat *v38; // r3
  idPresentable *v39; // r3
  float *v40; // r3
  idVec3 *p_goalPos; // r26
  double v42; // fp8
  double v43; // fp6
  idPresentable *v44; // r3
  float *v45; // r3
  double v46; // fp9
  double v47; // fp8
  double v48; // fp3
  double v49; // fp2
  double v50; // fp10
  double v51; // fp9
  idClientGame *v52; // r29
  idClipQuery *p_traceResult; // r30
  unsigned __int64 index; // r11
  double v55; // fp13
  double v56; // fp12
  double v57; // fp9
  double v58; // fp8
  double v59; // fp5
  double v60; // fp4
  double v61; // fp3
  idPresentable *v62; // r3
  idClientGame *v63; // r11
  idClipModel *clip16x16; // r8
  unsigned __int64 v65; // r11
  void *v66; // r7 OVERLAPPED
  double v67; // fp31
  __int64 v68; // r9 OVERLAPPED
  double v69; // fp0
  float v70; // r10
  float v71; // r9
  idPresentableVehicle *v72; // r3
  bool IsDead; // r3
  idClientGame *v74; // r29
  unsigned __int64 v75; // r28
  idClipQuery *v76; // r30
  unsigned __int64 v77; // r11
  idClientGame *v78; // r29
  idClipQuery *p_hitCamResult; // r30
  unsigned __int64 v80; // r11
  double v81; // fp13
  float v82; // r11
  float v83; // r9
  float v84; // r6
  float v85; // r11
  float v86; // r3
  float v87; // r4
  idPresentable *v88; // r3
  unsigned __int64 v89; // r6
  int v90; // r29
  unsigned __int64 *v91; // r3
  double v92; // fp13
  double v93; // fp11
  double v94; // fp12
  double v95; // fp3
  double v96; // fp5
  double v97; // fp31
  const idQuat *v98; // r30
  const idQuat *v99; // r3
  idPresentable *v100; // r3
  float *v101; // r3
  double v102; // fp7
  double v103; // fp6
  double v104; // fp1
  double v105; // fp13
  double v106; // fp9
  double v107; // fp7
  float v108; // r8
  float v109; // r6
  float v110; // r9
  double v111; // fp11
  double v112; // fp13
  double v113; // fp6
  double v114; // fp7
  double v115; // fp5
  bool v116; // r29
  const char *v117; // r3
  double v118; // fp7
  double v119; // fp5
  double v120; // fp31
  const idQuat *v121; // r30
  const idQuat *v122; // r3
  idRenderWorld *v123; // r3
  idMat3 *p_viewAxis; // r5
  idVec3 *p_viewOrigin; // r31
  idRenderWorld *v126; // r3
  int v127; // [sp+8h] [-3D8h]
  int v128; // [sp+8h] [-3D8h]
  bool v129; // [sp+Fh] [-3D1h]
  bool v130; // [sp+Fh] [-3D1h]
  const char *v131; // [sp+10h] [-3D0h]
  const char *v132; // [sp+10h] [-3D0h]
  int v133; // [sp+14h] [-3CCh]
  int v134; // [sp+14h] [-3CCh]
  int v135; // [sp+18h] [-3C8h]
  int v136; // [sp+18h] [-3C8h]
  int v137; // [sp+1Ch] [-3C4h]
  int v138; // [sp+1Ch] [-3C4h]
  int v139; // [sp+20h] [-3C0h]
  int v140; // [sp+20h] [-3C0h]
  int v141; // [sp+24h] [-3BCh]
  int v142; // [sp+24h] [-3BCh]
  int v143; // [sp+28h] [-3B8h]
  int v144; // [sp+28h] [-3B8h]
  int v145; // [sp+2Ch] [-3B4h]
  int v146; // [sp+2Ch] [-3B4h]
  int v147; // [sp+30h] [-3B0h]
  int v148; // [sp+30h] [-3B0h]
  int v149; // [sp+34h] [-3ACh]
  int v150; // [sp+34h] [-3ACh]
  int v151; // [sp+38h] [-3A8h]
  int v152; // [sp+38h] [-3A8h]
  int v153; // [sp+3Ch] [-3A4h]
  int v154; // [sp+3Ch] [-3A4h]
  int v155; // [sp+40h] [-3A0h]
  int v156; // [sp+40h] [-3A0h]
  int v157; // [sp+44h] [-39Ch]
  int v158; // [sp+44h] [-39Ch]
  int v159; // [sp+48h] [-398h]
  int v160; // [sp+48h] [-398h]
  int v161; // [sp+4Ch] [-394h]
  int v162; // [sp+4Ch] [-394h]
  int v163; // [sp+50h] [-390h]
  int v164; // [sp+50h] [-390h]
  int v165; // [sp+58h] [-388h]
  int v166; // [sp+58h] [-388h]
  int v167; // [sp+60h] [-380h]
  int v168; // [sp+60h] [-380h]
  idMat3 v169; // [sp+70h] [-370h] BYREF
  float v170; // [sp+94h] [-34Ch]
  float v171; // [sp+98h] [-348h]
  idMat3 v172; // [sp+A0h] [-340h] BYREF
  float v173; // [sp+C4h] [-31Ch]
  float v174; // [sp+C8h] [-318h]
  idMat3 v175; // [sp+D0h] [-310h] BYREF
  idQuat v176[3]; // [sp+100h] [-2E0h] BYREF
  idMat3 v177; // [sp+130h] [-2B0h] BYREF
  trace_t v178; // [sp+160h] [-280h] BYREF
  trace_t v179; // [sp+1E0h] [-200h] BYREF
  trace_t v180; // [sp+260h] [-180h] BYREF
  trace_t v181; // [sp+2E0h] [-100h] BYREF

  v5 = __PAIR64__(&cam_onlineDeathCamDebug, curTime);
  v6 = cam_onlineDeathCamDebug.valueInteger != 0;
  v7 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idLib::PrintfIf(condition: v6, fmt: "----------------\ntime: %d\n", v7);
  spawnId = this->playerPresentable.spawnId;
  v9 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || idClientGame::GetPresentableByIndex(this: clientGame, index: v9)->spawnId != this->playerPresentable.spawnId
    || !common->IsClient(this: common)
    || (v10 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->playerPresentable),
        v10->IsLocallyControlled(this: v10)) )
  {
    if ( this->initializedState != this->prevInitializedState )
      idOnlineVehicleDeathCameraPresentable::Init(this, curTime: v5);
    if ( cam_onlineDeathCamSpecial.valueInteger != 0 )
    {
      if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->playerVehiclePresentable) )
      {
        y = this->viewOrigin.y;
        z = this->viewOrigin.z;
        v169.mat[1].y = this->viewOrigin.x;
        v169.mat[1].z = y;
        v169.mat[2].x = z;
        idMat3::ToAngles(this: &v172, result: (idAngles *)&this->viewAxis);
        v13 = __PAIR64__(&unk_82380000, gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED));
        LODWORD(v14) = this->startTime;
        *(_QWORD *)&v169.mat[0].x = v14;
        v15 = (float)((float)((float)v13 - (float)v14) * *(float *)(HIDWORD(v13) + 29476));
        if ( v15 >= 0.0 )
        {
          if ( v15 > 1.0 )
            v15 = 1.0;
        }
        else
        {
          v15 = 0.0;
        }
        v169.mat[2].x = (float)((float)-(float)((float)((float)((float)1.0 - (float)v15)
                                                      * (float)((float)1.0 - (float)v15))
                                              - (float)1.0)
                              * (float)1000.0)
                      + this->startingOrigin.z;
        if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->playerVehiclePresentable) )
          p_origin = &idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->playerVehiclePresentable)->origin;
        else
          p_origin = &this->goalPos;
        v17 = p_origin->y;
        x = p_origin->x;
        v19 = p_origin->z;
        v169.mat[0].z = 0.0;
        distToTarget = this->distToTarget;
        v172.mat[1].z = v17;
        v21 = v17;
        v172.mat[1].y = x;
        v22 = x;
        v169.mat[0].x = x - v169.mat[1].y;
        v172.mat[2].x = v19;
        v169.mat[0].y = v17 - v169.mat[1].z;
        _FP7 = (float)((float)((float)(v169.mat[0].y * v169.mat[0].y) + (float)(v169.mat[0].x * v169.mat[0].x))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f5, f7, f8, f13 }
        v25 = __frsqrte(_FP5);
        v26 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25
                                                                                            * (float)((float)((float)(v169.mat[0].y * v169.mat[0].y) + (float)(v169.mat[0].x * v169.mat[0].x)) * (float)0.5))
                                                                                    * (float)v25)
                                                                            - (float)1.5)
                                                            * (float)v25)
                                                    * (float)((float)((float)(v169.mat[0].y * v169.mat[0].y)
                                                                    + (float)(v169.mat[0].x * v169.mat[0].x))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v25
                                                                                    * (float)((float)((float)(v169.mat[0].y * v169.mat[0].y) + (float)(v169.mat[0].x * v169.mat[0].x))
                                                                                            * (float)0.5))
                                                                            * (float)v25)
                                                                    - (float)1.5)
                                                    * (float)v25))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v25
                                                            * (float)((float)((float)(v169.mat[0].y * v169.mat[0].y)
                                                                            + (float)(v169.mat[0].x * v169.mat[0].x))
                                                                    * (float)0.5))
                                                    * (float)v25)
                                            - (float)1.5)
                            * (float)v25));
        v27 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)(v169.mat[0].y * v169.mat[0].y) + (float)(v169.mat[0].x * v169.mat[0].x)) * (float)0.5)) * (float)v25) - (float)1.5) * (float)v25) * (float)((float)((float)(v169.mat[0].y * v169.mat[0].y) + (float)(v169.mat[0].x * v169.mat[0].x)) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)(v169.mat[0].y * v169.mat[0].y) + (float)(v169.mat[0].x * v169.mat[0].x)) * (float)0.5)) * (float)v25) - (float)1.5) * (float)v25))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)(v169.mat[0].y * v169.mat[0].y) + (float)(v169.mat[0].x * v169.mat[0].x)) * (float)0.5)) * (float)v25)
                                                                                            - (float)1.5)
                                                                            * (float)v25))
                                                            * (float)((float)((float)(v169.mat[0].y * v169.mat[0].y)
                                                                            + (float)(v169.mat[0].x * v169.mat[0].x))
                                                                    * (float)0.5))
                                                    * (float)v26)
                                            - (float)1.5)
                            * (float)v26)
                    * (float)((float)(v169.mat[0].y * v169.mat[0].y) + (float)(v169.mat[0].x * v169.mat[0].x)));
        if ( v27 > distToTarget )
        {
          idVec3::NormalizeFast(this: v169.mat);
          v169.mat[1].y = (float)v22
                        - (float)(v169.mat[0].x
                                * (float)((float)((float)((float)v27 - (float)distToTarget) * (float)0.98000002)
                                        + (float)distToTarget));
          v169.mat[1].z = (float)v21
                        - (float)(v169.mat[0].y
                                * (float)((float)((float)((float)v27 - (float)distToTarget) * (float)0.98000002)
                                        + (float)distToTarget));
          if ( cam_onlineDeathDebug.valueInteger != 0 )
            idLib::Printf(fmt: "DistToTarget: %f dist: %f \n", distToTarget, v27);
        }
        idClip::TraceBounds(
          this: &clientGame->clip,
          result: &v179,
          start: (const idVec3 *)&v172.mat[1].y,
          end: (const idVec3 *)&v169.mat[1].y,
          trm: clientGame->clip.clip8x8,
          clipMask: 1,
          passEntityNumber: this->entityNumber);
        if ( v179.fraction == 1.0 )
        {
          v31 = v169.mat[2].x;
          v30 = v169.mat[1].z;
          v29 = v169.mat[1].y;
        }
        else
        {
          v169.mat[1].y = v179.endpos.x;
          v169.mat[1].z = v179.endpos.y;
          entityNumber = this->entityNumber;
          v169.mat[2].x = (float)((float)((float)1.0 - v179.fraction) * (float)32.0) + v179.endpos.z;
          idClip::TraceBounds(
            this: &clientGame->clip,
            result: &v179,
            start: (const idVec3 *)&v172.mat[1].y,
            end: (const idVec3 *)&v169.mat[1].y,
            trm: clientGame->clip.clip8x8,
            clipMask: 1,
            passEntityNumber: entityNumber);
          v29 = v179.endpos.x;
          v30 = v179.endpos.y;
          v31 = v179.endpos.z;
          v169.mat[1].y = v179.endpos.x;
          v169.mat[1].z = v179.endpos.y;
          v169.mat[2].x = v179.endpos.z;
        }
        v32 = (float)(v172.mat[1].y - (float)v29);
        v33 = (float)(v172.mat[1].z - (float)v30);
        v34 = (float)(v172.mat[2].x - (float)v31);
        this->viewOrigin.x = v29;
        v175.mat[1].y = v32;
        this->viewOrigin.y = v30;
        v175.mat[1].z = v33;
        this->viewOrigin.z = v31;
        v175.mat[2].x = v34;
        idVec3::NormalizeFast(this: (idVec3 *)&v175.mat[1].y);
        valueFloat = cam_onlineDeathCamSuicideViewSpeed.valueFloat;
        v36 = (idQuat *)idVec3::ToMat3(this: (idVec3 *)v176, result: (idMat3 *)&v175.mat[1].y);
        v37 = idMat3::ToQuat(this: &v169, result: v36);
        v38 = idMat3::ToQuat(this: (idMat3 *)&v175.mat[2].z, result: (idQuat *)&this->viewAxis);
        idQuat::Lerp(this: (idQuat *)&v177, from: v38, to: v37, t: valueFloat);
        this->viewAxis = *idQuat::ToMat3(this: v176, result: &v177);
      }
      goto LABEL_50;
    }
    if ( cam_onlineDeathCamStatic.valueInteger != 0 )
    {
LABEL_50:
      if ( cam_onlineDeathDebug.valueInteger != 0 )
      {
        v123 = gameLocal->GetRenderWorld(this: gameLocal);
        p_viewAxis = &this->viewAxis;
        p_viewOrigin = &this->viewOrigin;
        v123->DebugAxis_2(this: v123, a2: p_viewOrigin, a3: p_viewAxis, a4: 30000, a5: false);
        v126 = gameLocal->GetRenderWorld(this: gameLocal);
        v126->DebugPoint(this: v126, a2: (const idVec4 *)&idColor::colorGreen, a3: p_viewOrigin, a4: 60000, a5: false);
      }
      return;
    }
    if ( !idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->attackerPresentable) )
    {
      if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->playerVehiclePresentable) )
      {
        this->goalPos = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->playerVehiclePresentable)->origin;
        v100 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->playerVehiclePresentable);
        v101 = (float *)(*(int (__fastcall **)(float *, _DWORD))(LODWORD(v100[13].fxManager.actionBuffer[6].axis.mat[0].y)
                                                               + 68))(
                          a1: &v100[13].fxManager.actionBuffer[6].axis.mat[0].y,
                          a2: 0);
        v102 = (float)(v101[1] * (float)-1.0);
        v103 = (float)(v101[2] * (float)-1.0);
        v169.mat[0].x = (float)(*v101 * (float)-1.0) + vec3_up.x;
        v169.mat[0].y = (float)v102 + vec3_up.y;
        v169.mat[0].z = (float)v103 + vec3_up.z;
        idVec3::NormalizeFast(this: v169.mat);
        v104 = this->goalPos.x;
        v105 = this->goalPos.y;
        v106 = (float)(mp_vdm_deathCamGoalDist.valueFloat * v169.mat[0].x);
        v107 = (float)(v169.mat[0].y * mp_vdm_deathCamGoalDist.valueFloat);
        this->goalPos.z = (float)(v169.mat[0].z * mp_vdm_deathCamGoalDist.valueFloat) + this->goalPos.z;
        this->goalPos.x = (float)v106 + (float)v104;
        this->goalPos.y = (float)v107 + (float)v105;
        v108 = this->prevOrigin.x;
        v109 = this->goalPos.y;
        v172.mat[0].z = this->prevOrigin.z;
        v110 = this->goalPos.z;
        v111 = v172.mat[0].z;
        v169.mat[0].x = this->goalPos.x;
        v172.mat[0].x = v108;
        v172.mat[0].y = this->prevOrigin.y;
        v169.mat[0].y = v109;
        v112 = v172.mat[0].y;
        v169.mat[0].z = v110;
        v113 = (float)((float)(v109 - v172.mat[0].y) * cam_onlineDeathCamMoveMinLerpSpeed.valueFloat);
        v114 = (float)((float)(v110 - v172.mat[0].z) * cam_onlineDeathCamMoveMinLerpSpeed.valueFloat);
        v115 = (float)((float)(cam_onlineDeathCamMoveMinLerpSpeed.valueFloat * (float)(v169.mat[0].x - v108)) + v108);
        this->viewOrigin.x = (float)(cam_onlineDeathCamMoveMinLerpSpeed.valueFloat * (float)(v169.mat[0].x - v108))
                           + v108;
        this->viewOrigin.y = (float)v113 + (float)v112;
        this->viewOrigin.z = (float)v114 + (float)v111;
        this->prevOrigin.x = v115;
        this->prevOrigin.y = this->viewOrigin.y;
        this->prevOrigin.z = this->viewOrigin.z;
        v116 = *(_DWORD *)(HIDWORD(v5) + offsetof(idCVar, valueInteger)) != 0;
        v117 = idVec3::ToString(this: (idAngles *)&this->viewOrigin, precision: 2);
        idLib::PrintfIf(condition: v116, fmt: "player pos: %s\n", v117);
        v118 = (float)(this->viewOrigin.y - this->prevOrigin.y);
        v119 = (float)(this->viewOrigin.z - this->prevOrigin.z);
        v175.mat[0].x = this->viewOrigin.x - this->prevOrigin.x;
        v175.mat[0].y = v118;
        v175.mat[0].z = v119;
        idVec3::NormalizeFast(this: v175.mat);
        this->viewAxis = *idVec3::ToMat3(this: (idVec3 *)v176, result: &v175);
        v120 = cam_onlineDeathCamSuicideViewSpeed.valueFloat;
        v121 = idMat3::ToQuat(this: (idMat3 *)&v175.mat[2].z, result: (idQuat *)&this->viewAxis);
        v122 = idMat3::ToQuat(this: &v172, result: (idQuat *)&this->prevAxis);
        idQuat::Lerp(this: (idQuat *)&v177.mat[2].z, from: v122, to: v121, t: v120);
        this->viewAxis = *idQuat::ToMat3(this: v176, result: (idMat3 *)&v177.mat[2].z);
        this->viewOrigin.x = this->prevOrigin.x;
        this->viewOrigin.y = this->prevOrigin.y;
        this->viewOrigin.z = this->prevOrigin.z;
        this->prevAxis.mat[0].x = this->viewAxis.mat[0].x;
        this->prevAxis.mat[0].y = this->viewAxis.mat[0].y;
        this->prevAxis.mat[0].z = this->viewAxis.mat[0].z;
        this->prevAxis.mat[1].x = this->viewAxis.mat[1].x;
        this->prevAxis.mat[1].y = this->viewAxis.mat[1].y;
        this->prevAxis.mat[1].z = this->viewAxis.mat[1].z;
        this->prevAxis.mat[2].x = this->viewAxis.mat[2].x;
        this->prevAxis.mat[2].y = this->viewAxis.mat[2].y;
        this->prevAxis.mat[2].z = this->viewAxis.mat[2].z;
      }
      goto LABEL_50;
    }
    v39 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->attackerPresentable);
    v40 = (float *)(*(int (__fastcall **)(float *, int))(LODWORD(v39[13].fxManager.actionBuffer[6].axis.mat[0].y) + 44))(
                     a1: &v39[13].fxManager.actionBuffer[6].axis.mat[0].y,
                     a2: -1);
    p_goalPos = &this->goalPos;
    v42 = (float)(v40[4] + v40[1]);
    v43 = (float)(v40[5] + v40[2]);
    this->goalPos.x = (float)(v40[3] + *v40) * (float)0.5;
    this->goalPos.y = (float)v42 * (float)0.5;
    this->goalPos.z = (float)v43 * (float)0.5;
    v44 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->attackerPresentable);
    v45 = (float *)(*(int (__fastcall **)(float *, _DWORD))(LODWORD(v44[13].fxManager.actionBuffer[6].axis.mat[0].y) + 68))(
                     a1: &v44[13].fxManager.actionBuffer[6].axis.mat[0].y,
                     a2: 0);
    v46 = (float)(v45[1] * (float)-1.0);
    v47 = (float)(v45[2] * (float)-1.0);
    v169.mat[0].x = (float)(*v45 * (float)-1.0) + vec3_up.x;
    v169.mat[0].y = vec3_up.y + (float)v46;
    v169.mat[0].z = vec3_up.z + (float)v47;
    idVec3::NormalizeFast(this: v169.mat);
    v48 = this->goalPos.y;
    v49 = this->goalPos.z;
    v50 = (float)(mp_vdm_deathCamGoalDist.valueFloat * v169.mat[0].y);
    v51 = (float)(mp_vdm_deathCamGoalDist.valueFloat * v169.mat[0].z);
    this->goalPos.x = (float)(mp_vdm_deathCamGoalDist.valueFloat * v169.mat[0].x) + this->goalPos.x;
    this->goalPos.y = (float)v48 + (float)v50;
    this->goalPos.z = (float)v49 + (float)v51;
    if ( !this->firstTraceDone )
    {
      v52 = clientGame;
      p_traceResult = &this->traceResult;
      if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->traceResult) != 0 )
      {
        LODWORD(v5) = 0;
        index = p_traceResult->index;
        p_traceResult->index = v5;
        idCollisionModelManager::GetContentsResult(
          this: collisionModelManager,
          result: &v178,
          query: &v52->clip.collisionQueries[index & 0xFFF].query,
          peek: false);
        if ( v178.fraction < 1.0 )
        {
          v55 = v178.endpos.y;
          v56 = v178.endpos.z;
          this->prevOrigin.x = v178.endpos.x;
          this->prevOrigin.y = v55;
          this->prevOrigin.z = v56;
          this->prevAxis.mat[0].x = v178.endAxis.mat[0].x;
          v57 = v178.endAxis.mat[0].y;
          v58 = v178.endAxis.mat[0].z;
          this->prevAxis.mat[1].x = v178.endAxis.mat[1].x;
          this->prevAxis.mat[0].y = v57;
          this->prevAxis.mat[0].z = v58;
          this->prevAxis.mat[1].y = v178.endAxis.mat[1].y;
          v59 = v178.endAxis.mat[2].x;
          this->prevAxis.mat[1].z = v178.endAxis.mat[1].z;
          v60 = v178.endAxis.mat[2].y;
          this->prevAxis.mat[2].x = v59;
          v61 = v178.endAxis.mat[2].z;
          this->prevAxis.mat[2].y = v60;
          this->prevAxis.mat[2].z = v61;
          this->hitSolid = true;
        }
        v62 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->attackerPresentable);
        v63 = clientGame;
        this->targetPosPrev.x = v62->origin.x;
        this->targetPosPrev.y = v62->origin.y;
        clip16x16 = v63->clip.clip16x16;
        this->targetPosPrev.z = v62->origin.z;
        v65 = *(_QWORD *)&idClip::Translation(
                            this: (idClip *)&v169,
                            result: &v63->clip,
                            a3: nullptr,
                            start: &this->targetPosPrev,
                            end: &this->prevOrigin,
                            clipModel: clip16x16,
                            startAxis: &mat3_identity,
                            clipMask: 1,
                            passEntityNumber: v127,
                            moveClipModel: v129,
                            userName: v131,
                            a12: v133,
                            a13: v135,
                            a14: v137,
                            a15: v139,
                            a16: v141,
                            a17: v143,
                            a18: v145,
                            a19: v147,
                            a20: v149,
                            a21: v151,
                            a22: v153,
                            a23: v155,
                            a24: v157,
                            a25: v159,
                            a26: v161,
                            a27: v163,
                            a28: this->entityNumber,
                            a29: v165,
                            a30: false,
                            a31: v167,
                            a32: (int)"w:\\tech5\\tungsten\\game\\entities\\UtilityCamera.cpp(6352) : Translation")->world;
        this->firstTraceDone = true;
        p_traceResult->index = v65;
      }
      else
      {
        p_traceResult->index = *(unsigned __int64 *)&idClip::Translation(
                                                       this: (idClip *)&v169,
                                                       result: &v52->clip,
                                                       a3: nullptr,
                                                       start: &this->targetPosPrev,
                                                       end: &this->prevOrigin,
                                                       clipModel: v52->clip.clip16x16,
                                                       startAxis: &mat3_identity,
                                                       clipMask: 1,
                                                       passEntityNumber: v127,
                                                       moveClipModel: v129,
                                                       userName: v131,
                                                       a12: v133,
                                                       a13: v135,
                                                       a14: v137,
                                                       a15: v139,
                                                       a16: v141,
                                                       a17: v143,
                                                       a18: v145,
                                                       a19: v147,
                                                       a20: v149,
                                                       a21: v151,
                                                       a22: v153,
                                                       a23: v155,
                                                       a24: v157,
                                                       a25: v159,
                                                       a26: v161,
                                                       a27: v163,
                                                       a28: this->entityNumber,
                                                       a29: v165,
                                                       a30: false,
                                                       a31: v167,
                                                       a32: (int)"w:\\tech5\\tungsten\\game\\entities\\UtilityCamera.cpp(6356) : Translation")->world;
      }
      goto LABEL_50;
    }
    v66 = &unk_82390000;
    HIDWORD(v68) = this->startTime;
    v67 = 0.1;
    LODWORD(v68) = (int)(float)(cam_onlineDeathCamLerpDuration.valueFloat * (float)1000.0);
    *(_QWORD *)&v169.mat[0].x = v68;
    v69 = (float)((float)((float)((float)__SPAIR64__(
                                           (idDeclInfoTemplate<idDeclAiEvent> *)&idDeclAiEvent::resourceList.staticID,
                                           v5)
                                - (float)*(__int64 *)((char *)&v68 + 4))
                        - cam_onlineDeathCamCircleDuration.valueFloat)
                / (float)v68);
    if ( v69 >= 0.1 )
    {
      if ( v69 <= 1.0 )
        v67 = (float)((float)((float)((float)__SPAIR64__(
                                               (idDeclInfoTemplate<idDeclAiEvent> *)&idDeclAiEvent::resourceList.staticID,
                                               v5)
                                    - (float)*(__int64 *)((char *)&v68 + 4))
                            - cam_onlineDeathCamCircleDuration.valueFloat)
                    / (float)v68);
      else
        v67 = 1.0;
    }
    v70 = this->goalPos.y;
    v71 = this->goalPos.z;
    v169.mat[2].z = p_goalPos->x;
    v170 = v70;
    v171 = v71;
    v72 = (idPresentableVehicle *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->attackerPresentable);
    IsDead = idPresentableVehicle::IsDead(this: v72);
    v74 = clientGame;
    LODWORD(v75) = 0;
    if ( IsDead
      || (v76 = &this->traceResult,
          (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->traceResult) == 0) )
    {
LABEL_47:
      v89 = *(_QWORD *)&idClip::Translation(
                          this: (idClip *)&v169,
                          result: &v74->clip,
                          a3: nullptr,
                          start: &this->targetPosPrev,
                          end: &this->goalPos,
                          clipModel: v74->clip.clip16x16,
                          startAxis: &mat3_identity,
                          clipMask: 1,
                          passEntityNumber: v127,
                          moveClipModel: v129,
                          userName: v131,
                          a12: v133,
                          a13: v135,
                          a14: v137,
                          a15: v139,
                          a16: v141,
                          a17: v143,
                          a18: v145,
                          a19: v147,
                          a20: v149,
                          a21: v151,
                          a22: v153,
                          a23: v155,
                          a24: v157,
                          a25: v159,
                          a26: v161,
                          a27: v163,
                          a28: this->entityNumber,
                          a29: v165,
                          a30: false,
                          a31: v167,
                          a32: (int)"w:\\tech5\\tungsten\\game\\entities\\UtilityCamera.cpp(6387) : Translation")->world;
      HIDWORD(v89) = "DistToTarget: %f dist: %f \n";
      v90 = this->entityNumber;
      this->traceResult.index = v89;
      v91 = (unsigned __int64 *)idClip::Translation(
                                  this: (idClip *)&v169,
                                  result: &clientGame->clip,
                                  a3: nullptr,
                                  start: &this->targetPosPrev,
                                  end: (const idVec3 *)&v169.mat[2].z,
                                  clipModel: clientGame->clip.clip16x16,
                                  startAxis: &mat3_identity,
                                  clipMask: 1,
                                  passEntityNumber: v128,
                                  moveClipModel: v130,
                                  userName: v132,
                                  a12: v134,
                                  a13: v136,
                                  a14: v138,
                                  a15: v140,
                                  a16: v142,
                                  a17: v144,
                                  a18: v146,
                                  a19: v148,
                                  a20: v150,
                                  a21: v152,
                                  a22: v154,
                                  a23: v156,
                                  a24: v158,
                                  a25: v160,
                                  a26: v162,
                                  a27: v164,
                                  a28: v90,
                                  a29: v166,
                                  a30: false,
                                  a31: v168,
                                  a32: (int)"w:\\tech5\\tungsten\\game\\entities\\UtilityCamera.cpp(6388) : Translation");
      v92 = v170;
      v93 = v169.mat[2].z;
      this->hitCamResult.index = *v91;
      v94 = v171;
      this->prevOrigin.x = v93;
      this->prevOrigin.y = v92;
      this->prevOrigin.z = v94;
      v95 = (float)(this->targetPosPrev.x - (float)v93);
      v96 = (float)(this->targetPosPrev.z - (float)v94);
      v173 = this->targetPosPrev.y - (float)v92;
      v172.mat[2].z = v95;
      v174 = v96;
      idVec3::NormalizeFast(this: (idVec3 *)&v172.mat[2].z);
      this->viewAxis = *idVec3::ToMat3(this: (idVec3 *)v176, result: (idMat3 *)&v172.mat[2].z);
      v97 = cam_onlineDeathCamSuicideViewSpeed.valueFloat;
      v98 = idMat3::ToQuat(this: (idMat3 *)&v175.mat[2].z, result: (idQuat *)&this->viewAxis);
      v99 = idMat3::ToQuat(this: &v172, result: (idQuat *)&this->prevAxis);
      idQuat::Lerp(this: (idQuat *)&v177.mat[1].y, from: v99, to: v98, t: v97);
      this->viewAxis = *idQuat::ToMat3(this: v176, result: (idMat3 *)&v177.mat[1].y);
      this->viewOrigin.x = this->prevOrigin.x;
      this->viewOrigin.y = this->prevOrigin.y;
      this->viewOrigin.z = this->prevOrigin.z;
      this->prevAxis.mat[0].x = this->viewAxis.mat[0].x;
      this->prevAxis.mat[0].y = this->viewAxis.mat[0].y;
      this->prevAxis.mat[0].z = this->viewAxis.mat[0].z;
      this->prevAxis.mat[1].x = this->viewAxis.mat[1].x;
      this->prevAxis.mat[1].y = this->viewAxis.mat[1].y;
      this->prevAxis.mat[1].z = this->viewAxis.mat[1].z;
      this->prevAxis.mat[2].x = this->viewAxis.mat[2].x;
      this->prevAxis.mat[2].y = this->viewAxis.mat[2].y;
      this->prevAxis.mat[2].z = this->viewAxis.mat[2].z;
      goto LABEL_50;
    }
    v77 = v76->index;
    HIDWORD(v75) = &consoleFont[21088];
    v76->index = v75;
    idCollisionModelManager::GetContentsResult(
      this: collisionModelManager,
      result: &v180,
      query: &v74->clip.collisionQueries[v77 & 0xFFF].query,
      peek: false);
    if ( v180.fraction >= 1.0 )
    {
      v84 = this->prevOrigin.x;
      v85 = this->goalPos.y;
      v86 = this->prevOrigin.z;
      v87 = this->prevOrigin.y;
      v169.mat[0].z = this->goalPos.z;
      v172.mat[0].x = v84;
      v169.mat[0].y = v85;
      v172.mat[0].z = v86;
      v172.mat[0].y = v87;
      v169.mat[0].x = p_goalPos->x;
      v169.mat[2].z = (float)((float)(v169.mat[0].x - v84)
                            * (float)((float)((float)(cam_onlineDeathCamMoveMaxLerpSpeed.valueFloat
                                                    - cam_onlineDeathCamMoveMinLerpSpeed.valueFloat)
                                            * (float)v67)
                                    + cam_onlineDeathCamMoveMinLerpSpeed.valueFloat))
                    + v84;
      v171 = (float)((float)(v169.mat[0].z - v86)
                   * (float)((float)((float)(cam_onlineDeathCamMoveMaxLerpSpeed.valueFloat
                                           - cam_onlineDeathCamMoveMinLerpSpeed.valueFloat)
                                   * (float)v67)
                           + cam_onlineDeathCamMoveMinLerpSpeed.valueFloat))
           + v86;
      v81 = (float)((float)((float)(v85 - v87)
                          * (float)((float)((float)(cam_onlineDeathCamMoveMaxLerpSpeed.valueFloat
                                                  - cam_onlineDeathCamMoveMinLerpSpeed.valueFloat)
                                          * (float)v67)
                                  + cam_onlineDeathCamMoveMinLerpSpeed.valueFloat))
                  + v87);
    }
    else
    {
      v78 = clientGame;
      p_hitCamResult = &this->hitCamResult;
      if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->hitCamResult) != 0 )
      {
        v80 = p_hitCamResult->index;
        p_hitCamResult->index = v75;
        idCollisionModelManager::GetContentsResult(
          this: collisionModelManager,
          result: &v181,
          query: &v78->clip.collisionQueries[v80 & 0xFFF].query,
          peek: false);
        if ( v181.fraction >= 1.0 )
        {
          v82 = this->prevOrigin.x;
          v83 = this->prevOrigin.y;
          v169.mat[0].z = this->prevOrigin.z;
          v169.mat[0].x = v82;
          v169.mat[0].y = v83;
          v171 = (float)((float)(v180.endpos.z - v169.mat[0].z)
                       * (float)((float)((float)(cam_onlineDeathCamMoveMaxLerpSpeed.valueFloat
                                               - cam_onlineDeathCamMoveMinLerpSpeed.valueFloat)
                                       * (float)v67)
                               + cam_onlineDeathCamMoveMinLerpSpeed.valueFloat))
               + v169.mat[0].z;
          v169.mat[2].z = (float)((float)(v180.endpos.x - v82)
                                * (float)((float)((float)(cam_onlineDeathCamMoveMaxLerpSpeed.valueFloat
                                                        - cam_onlineDeathCamMoveMinLerpSpeed.valueFloat)
                                                * (float)v67)
                                        + cam_onlineDeathCamMoveMinLerpSpeed.valueFloat))
                        + v82;
          v170 = (float)((float)(v180.endpos.y - v83)
                       * (float)((float)((float)(cam_onlineDeathCamMoveMaxLerpSpeed.valueFloat
                                               - cam_onlineDeathCamMoveMinLerpSpeed.valueFloat)
                                       * (float)v67)
                               + cam_onlineDeathCamMoveMinLerpSpeed.valueFloat))
               + v83;
LABEL_46:
          v88 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->attackerPresentable);
          v74 = clientGame;
          this->targetPosPrev = v88->origin;
          goto LABEL_47;
        }
        v81 = v181.endpos.y;
        v169.mat[2].z = v181.endpos.x;
        v171 = v181.endpos.z;
      }
      else
      {
        v81 = v180.endpos.y;
        v169.mat[2].z = v180.endpos.x;
        v171 = v180.endpos.z;
      }
    }
    v170 = v81;
    goto LABEL_46;
  }
}


// ========================================================================
// ??0idRaceDeathCamera@@QAA@XZ
// EA  : 0x82D11400
// RVA : 0x00D11400
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idRaceDeathCamera *__fastcall idRaceDeathCamera::idRaceDeathCamera(idRaceDeathCamera *this)
{
  float *p_z; // r10
  int v3; // ctr
  float *p_y; // r11
  float z; // r8

  idCameraView::idCameraView(this);
  this->__vftable = (idRaceDeathCamera_vtbl *)&idRaceDeathCamera::`vftable';
  this->startTime = 0;
  this->startingOrigin = vec3_origin;
  p_z = &this->startingOrigin.z;
  v3 = 9;
  p_y = &mat2_identity.mat[1].y;
  do
  {
    *++p_z = *++p_y;
    --v3;
  }
  while ( v3 != 0 );
  this->targetPos.x = vec3_origin.x;
  this->targetPos.y = vec3_origin.y;
  z = vec3_origin.z;
  this->distToTarget = 0.0;
  this->targetPos.z = z;
  return this;
}


// ========================================================================
// ?Think@idRaceDeathCamera@@UAAXXZ
// EA  : 0x82D114B0
// RVA : 0x00D114B0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idRaceDeathCamera::Think(idRaceDeathCamera *this)
{
  idPhysics *Physics; // r3
  int v3; // r3
  float v4; // r7
  float v5; // r6
  idPhysics *v6; // r3
  idAngles *v7; // r3
  __int128 v8; // r5
  double v9; // fp0
  int value; // r9
  idEntity *v11; // r3
  int v12; // r9
  idEntity *v13; // r3
  idEntity *v14; // r3
  idPhysics *v15; // r3
  idVec3 *p_targetPos; // r3
  float x; // r10
  float z; // r9
  double distToTarget; // fp10
  double v21; // fp6
  double v23; // fp9
  double v24; // fp4
  double v25; // fp9
  double v27; // fp4
  double v29; // fp0
  double v30; // fp0
  double v31; // fp4
  int entityNumber; // r9
  idPhysics *v33; // r3
  double v36; // fp10
  double v37; // fp1
  idPhysics *v38; // r3
  idVec3 v39; // [sp+50h] [-130h] BYREF
  idVec3 v40; // [sp+60h] [-120h] BYREF
  __int64 v41; // [sp+70h] [-110h]
  idMat3 v42; // [sp+78h] [-108h] BYREF
  trace_t v43; // [sp+A0h] [-E0h] BYREF
  idMat3 v44; // [sp+120h] [-60h] BYREF

  Physics = idEntity::GetPhysics(this);
  v3 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v4 = *(float *)(v3 + 4);
  v5 = *(float *)(v3 + 8);
  v39.x = *(float *)v3;
  v39.y = v4;
  v39.z = v5;
  v6 = idEntity::GetPhysics(this);
  v7 = (idAngles *)v6->GetAxis(this: v6, a2: 0);
  idMat3::ToAngles(this: (idMat3 *)&v42.mat[1].y, result: v7);
  *(_QWORD *)((char *)&v8 + 4) = ((__int64 (__fastcall *)(idGameLocal *, int))gameLocal->GetGameMs)(
                                   a1: gameLocal,
                                   a2: 1);
  LODWORD(v8) = this->startTime;
  v41 = v8;
  v9 = (float)((float)((float)__SPAIR64__(&unk_82380000, DWORD1(v8)) - (float)(__int64)v8) * (float)0.000099999997);
  if ( v9 >= 0.0 )
  {
    if ( v9 > 1.0 )
      v9 = 1.0;
  }
  else
  {
    v9 = 0.0;
  }
  value = this->target.spawnId.value;
  v39.z = (float)((float)-(float)((float)((float)((float)1.0 - (float)v9) * (float)((float)1.0 - (float)v9)) - (float)1.0)
                * (float)1000.0)
        + this->startingOrigin.z;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v11 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v11) != nullptr )
  {
    v12 = this->target.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13 && (v13 = gameLocal->entities.ptr[v12 & 0x1FFF]) != nullptr )
      v14 = idEntity::CastTo(c: v13);
    else
      v14 = nullptr;
    v15 = idEntity::GetPhysics(this: v14);
    p_targetPos = (idVec3 *)v15->GetOrigin(this: v15, a2: 0);
  }
  else
  {
    p_targetPos = &this->targetPos;
  }
  x = p_targetPos->x;
  z = p_targetPos->z;
  distToTarget = this->distToTarget;
  v40.y = p_targetPos->y;
  v40.x = x;
  v40.z = z;
  _FP3 = (float)((float)((float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y))
                       + (float)((float)(x - v39.x) * (float)(x - v39.x)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v21 = (float)((float)((float)(z - v39.z) * (float)(z - v39.z))
              + (float)((float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y))
                      + (float)((float)(x - v39.x) * (float)(x - v39.x))));
  __asm { fsel      f1, f3, f0, f13 }
  v23 = __frsqrte(_FP1);
  v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23
                                                                                      * (float)((float)((float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)) + (float)((float)(x - v39.x) * (float)(x - v39.x)))
                                                                                              * (float)0.5))
                                                                              * (float)v23)
                                                                      - (float)1.5)
                                                      * (float)v23)
                                              * (float)((float)((float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y))
                                                              + (float)((float)(x - v39.x) * (float)(x - v39.x)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v23
                                                                              * (float)((float)((float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y))
                                                                                              + (float)((float)(x - v39.x) * (float)(x - v39.x)))
                                                                                      * (float)0.5))
                                                                      * (float)v23)
                                                              - (float)1.5)
                                              * (float)v23))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v23
                                                      * (float)((float)((float)((float)(v40.y - v39.y)
                                                                              * (float)(v40.y - v39.y))
                                                                      + (float)((float)(x - v39.x) * (float)(x - v39.x)))
                                                              * (float)0.5))
                                              * (float)v23)
                                      - (float)1.5)
                      * (float)v23));
  v25 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)((float)((float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)) + (float)((float)(x - v39.x) * (float)(x - v39.x))) * (float)0.5)) * (float)v23) - (float)1.5) * (float)v23)
                                                                                              * (float)((float)((float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)) + (float)((float)(x - v39.x) * (float)(x - v39.x))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)((float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)) + (float)((float)(x - v39.x) * (float)(x - v39.x))) * (float)0.5)) * (float)v23) - (float)1.5)
                                                                                              * (float)v23))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v23 * (float)((float)((float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)) + (float)((float)(x - v39.x) * (float)(x - v39.x))) * (float)0.5))
                                                                                              * (float)v23)
                                                                                      - (float)1.5)
                                                                      * (float)v23))
                                                      * (float)((float)((float)((float)(v40.y - v39.y)
                                                                              * (float)(v40.y - v39.y))
                                                                      + (float)((float)(x - v39.x) * (float)(x - v39.x)))
                                                              * (float)0.5))
                                              * (float)v24)
                                      - (float)1.5)
                      * (float)v24)
              * (float)((float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y))
                      + (float)((float)(x - v39.x) * (float)(x - v39.x))));
  if ( v25 > distToTarget )
  {
    _FP5 = (float)((float)((float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y))
                         + (float)((float)(x - v39.x) * (float)(x - v39.x)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v27 = (float)((float)((float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y))
                        + (float)((float)(x - v39.x) * (float)(x - v39.x)))
                * (float)0.5);
    __asm { fsel      f2, f5, f0, f13 }
    v29 = __frsqrte(_FP2);
    v30 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29 * (float)v27)
                                                                                * (float)v29)
                                                                        - (float)1.5)
                                                        * (float)v29)
                                                * (float)v27)
                                        * (float)((float)-(float)((float)((float)((float)v29 * (float)v27) * (float)v29)
                                                                - (float)1.5)
                                                * (float)v29))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v29 * (float)v27) * (float)v29) - (float)1.5)
                        * (float)v29));
    v31 = (float)((float)(v40.y - v39.y)
                * (float)((float)-(float)((float)((float)((float)v30
                                                        * (float)((float)((float)((float)(v40.y - v39.y)
                                                                                * (float)(v40.y - v39.y))
                                                                        + (float)((float)(x - v39.x) * (float)(x - v39.x)))
                                                                * (float)0.5))
                                                * (float)v30)
                                        - (float)1.5)
                        * (float)v30));
    v39.x = x
          - (float)((float)((float)((float)((float)v25 - (float)distToTarget) * (float)0.98000002) + (float)distToTarget)
                  * (float)((float)((float)-(float)((float)((float)((float)v30
                                                                  * (float)((float)((float)((float)(v40.y - v39.y)
                                                                                          * (float)(v40.y - v39.y))
                                                                                  + (float)((float)(x - v39.x)
                                                                                          * (float)(x - v39.x)))
                                                                          * (float)0.5))
                                                          * (float)v30)
                                                  - (float)1.5)
                                  * (float)v30)
                          * (float)(x - v39.x)));
    v39.y = v40.y
          - (float)((float)v31
                  * (float)((float)((float)((float)v25 - (float)distToTarget) * (float)0.98000002) + (float)distToTarget));
  }
  if ( v21 < 16777216.0 )
  {
    idClip::TraceBounds(
      this: &clientGame->clip,
      result: &v43,
      start: &v40,
      end: &v39,
      trm: clientGame->clip.clip8x8,
      clipMask: 1,
      passEntityNumber: this->entityNumber);
    if ( v43.fraction != 1.0 )
    {
      v39.y = v43.endpos.y;
      v39.x = v43.endpos.x;
      entityNumber = this->entityNumber;
      v39.z = (float)((float)((float)1.0 - v43.fraction) * (float)32.0) + v43.endpos.z;
      idClip::TraceBounds(
        this: &clientGame->clip,
        result: &v43,
        start: &v40,
        end: &v39,
        trm: clientGame->clip.clip8x8,
        clipMask: 1,
        passEntityNumber: entityNumber);
      v39.x = v43.endpos.x;
      v39.y = v43.endpos.y;
      v39.z = v43.endpos.z;
    }
  }
  v33 = idEntity::GetPhysics(this);
  v33->SetOrigin(this: v33, a2: &v39, a3: -1);
  _FP1 = (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x))
                       + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z))
                               + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f12, f1, f2, f0 }
  v36 = __frsqrte(_FP12);
  v37 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v36
                                                                                      * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x)) + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z)) + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y))))
                                                                                              * (float)0.5))
                                                                              * (float)v36)
                                                                      - (float)1.5)
                                                      * (float)v36)
                                              * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x))
                                                              + (float)((float)((float)(v40.z - v39.z)
                                                                              * (float)(v40.z - v39.z))
                                                                      + (float)((float)(v40.y - v39.y)
                                                                              * (float)(v40.y - v39.y))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v36
                                                                              * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x))
                                                                                              + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z)) + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y))))
                                                                                      * (float)0.5))
                                                                      * (float)v36)
                                                              - (float)1.5)
                                              * (float)v36))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v36
                                                      * (float)((float)((float)((float)(v40.x - v39.x)
                                                                              * (float)(v40.x - v39.x))
                                                                      + (float)((float)((float)(v40.z - v39.z)
                                                                                      * (float)(v40.z - v39.z))
                                                                              + (float)((float)(v40.y - v39.y)
                                                                                      * (float)(v40.y - v39.y))))
                                                              * (float)0.5))
                                              * (float)v36)
                                      - (float)1.5)
                      * (float)v36));
  v42.mat[0].x = (float)(v40.x - v39.x)
               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x)) + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z)) + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)))) * (float)0.5)) * (float)v36) - (float)1.5) * (float)v36)
                                                                                               * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x)) + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z)) + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)))) * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x)) + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z)) + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)))) * (float)0.5)) * (float)v36) - (float)1.5)
                                                                                               * (float)v36))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x)) + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z)) + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)))) * (float)0.5))
                                                                                               * (float)v36)
                                                                                       - (float)1.5)
                                                                       * (float)v36))
                                                       * (float)((float)((float)((float)(v40.x - v39.x)
                                                                               * (float)(v40.x - v39.x))
                                                                       + (float)((float)((float)(v40.z - v39.z)
                                                                                       * (float)(v40.z - v39.z))
                                                                               + (float)((float)(v40.y - v39.y)
                                                                                       * (float)(v40.y - v39.y))))
                                                               * (float)0.5))
                                               * (float)v37)
                                       - (float)1.5)
                       * (float)v37);
  v42.mat[0].y = (float)(v40.y - v39.y)
               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x)) + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z)) + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)))) * (float)0.5)) * (float)v36) - (float)1.5) * (float)v36)
                                                                                               * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x)) + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z)) + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)))) * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x)) + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z)) + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)))) * (float)0.5)) * (float)v36) - (float)1.5)
                                                                                               * (float)v36))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x)) + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z)) + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)))) * (float)0.5))
                                                                                               * (float)v36)
                                                                                       - (float)1.5)
                                                                       * (float)v36))
                                                       * (float)((float)((float)((float)(v40.x - v39.x)
                                                                               * (float)(v40.x - v39.x))
                                                                       + (float)((float)((float)(v40.z - v39.z)
                                                                                       * (float)(v40.z - v39.z))
                                                                               + (float)((float)(v40.y - v39.y)
                                                                                       * (float)(v40.y - v39.y))))
                                                               * (float)0.5))
                                               * (float)v37)
                                       - (float)1.5)
                       * (float)v37);
  v42.mat[0].z = (float)(v40.z - v39.z)
               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x)) + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z)) + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)))) * (float)0.5)) * (float)v36) - (float)1.5) * (float)v36)
                                                                                               * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x)) + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z)) + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)))) * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x)) + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z)) + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)))) * (float)0.5)) * (float)v36) - (float)1.5)
                                                                                               * (float)v36))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v36 * (float)((float)((float)((float)(v40.x - v39.x) * (float)(v40.x - v39.x)) + (float)((float)((float)(v40.z - v39.z) * (float)(v40.z - v39.z)) + (float)((float)(v40.y - v39.y) * (float)(v40.y - v39.y)))) * (float)0.5))
                                                                                               * (float)v36)
                                                                                       - (float)1.5)
                                                                       * (float)v36))
                                                       * (float)((float)((float)((float)(v40.x - v39.x)
                                                                               * (float)(v40.x - v39.x))
                                                                       + (float)((float)((float)(v40.z - v39.z)
                                                                                       * (float)(v40.z - v39.z))
                                                                               + (float)((float)(v40.y - v39.y)
                                                                                       * (float)(v40.y - v39.y))))
                                                               * (float)0.5))
                                               * (float)v37)
                                       - (float)1.5)
                       * (float)v37);
  idVec3::ToMat3(this: v44.mat, result: &v42);
  v38 = idEntity::GetPhysics(this);
  v38->SetAxis(this: v38, a2: &v44, a3: -1);
}


// ========================================================================
// ??0idRaceCountdownCamera@@QAA@XZ
// EA  : 0x82D11918
// RVA : 0x00D11918
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idRaceCountdownCamera *__fastcall idRaceCountdownCamera::idRaceCountdownCamera(idRaceCountdownCamera *this)
{
  idSplinePath *v2; // r3
  idSplinePath *v3; // r3

  idCameraView::idCameraView(this);
  this->splinePath = nullptr;
  this->__vftable = (idRaceCountdownCamera_vtbl *)&idRaceCountdownCamera::`vftable';
  this->length = 0.0;
  this->curve = nullptr;
  this->startTime = 0;
  this->timeMS = 0;
  v2 = (idSplinePath *)idGameLocal::SpawnEntityType(
                         this: gameLocal,
                         typeInfo: &idSplinePath::Type,
                         forceEntityNumber: -1,
                         _model: nullptr);
  v3 = idSplinePath::CastTo(c: v2);
  this->splinePath = v3;
  if ( v3 != nullptr )
    this->curve = idSplinePath::AllocSpline(this: v3);
  return this;
}


// ========================================================================
// __unwind$516283
// EA  : 0x82D119BC
// RVA : 0x00D119BC
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_516283()
{
  int v0; // r12

  idCameraView::~idCameraView(this: *(idCameraView **)(v0 - 112 + 132));
}


// ========================================================================
// ?Draw@idRaceCountdownCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D119E8
// RVA : 0x00D119E8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idRaceCountdownCamera::Draw(idRaceCountdownCamera *this, idPlayer *player)
{
  int value; // r10
  idEntity *v5; // r3
  int v7; // r3 OVERLAPPED
  __int64 v8; // r8
  __int64 v9; // r5 OVERLAPPED
  double v10; // fp0
  double v11; // fp13
  idPhysics *Physics; // r3
  int v13; // r7
  idEntity *v14; // r3
  idEntity *v15; // r3
  idPhysics *v16; // r3
  float *v17; // r3
  double v18; // fp8
  double v19; // fp6
  double v22; // fp12
  double v23; // fp2
  double v24; // fp13
  idPhysics *v25; // r3
  idPresentable *presentable; // r3
  int entityNumber; // r30
  idPresentablePlayer *v28; // r3
  float v29; // [sp+58h] [-78h] BYREF
  float v30; // [sp+5Ch] [-74h]
  float v31; // [sp+60h] [-70h]
  idMat3 v32[2]; // [sp+68h] [-68h] BYREF

  value = this->target.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v5 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v5 == nullptr || idEntity::CastTo(c: v5) == nullptr )
    return 0;
  if ( this->timeMS <= 0 )
  {
    v10 = 1.0;
  }
  else
  {
    v7 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    LODWORD(v8) = v7;
    HIDWORD(v8) = this->timeMS;
    LODWORD(v9) = this->startTime;
    HIDWORD(v9) = HIDWORD(v8);
    v10 = 0.0;
    v11 = (float)((float)((float)v8 - (float)v9) / (float)*(__int64 *)((char *)&v9 + 4));
    if ( v11 >= 0.0 )
    {
      v10 = 1.0;
      if ( v11 <= 1.0 )
        v10 = (float)((float)((float)v8 - (float)v9) / (float)*(__int64 *)((char *)&v9 + 4));
    }
  }
  ((void (__fastcall *)(float *, double))this->curve->GetCurrentValue)(a1: &v29, a2: (float)(this->length * (float)v10));
  Physics = idEntity::GetPhysics(this);
  Physics->SetOrigin(this: Physics, a2: (const idVec3 *)&v29, a3: -1);
  v13 = this->target.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13 && (v14 = gameLocal->entities.ptr[v13 & 0x1FFF]) != nullptr )
    v15 = idEntity::CastTo(c: v14);
  else
    v15 = nullptr;
  v16 = idEntity::GetPhysics(this: v15);
  v17 = (float *)v16->GetOrigin(this: v16, a2: 0);
  v18 = (float)(*v17 - v29);
  v19 = (float)(v17[2] - v31);
  _FP2 = (float)((float)((float)((float)(v17[2] - v31) * (float)(v17[2] - v31))
                       + (float)((float)((float)(*v17 - v29) * (float)(*v17 - v29))
                               + (float)((float)(v17[1] - v30) * (float)(v17[1] - v30))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f2, f3, f13 }
  v22 = __frsqrte(_FP13);
  v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                      * (float)((float)((float)((float)(v17[2] - v31) * (float)(v17[2] - v31)) + (float)((float)((float)(*v17 - v29) * (float)(*v17 - v29)) + (float)((float)(v17[1] - v30) * (float)(v17[1] - v30))))
                                                                                              * (float)0.5))
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22)
                                              * (float)((float)((float)((float)(v17[2] - v31) * (float)(v17[2] - v31))
                                                              + (float)((float)((float)(*v17 - v29) * (float)(*v17 - v29))
                                                                      + (float)((float)(v17[1] - v30)
                                                                              * (float)(v17[1] - v30))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v22
                                                                              * (float)((float)((float)((float)(v17[2] - v31) * (float)(v17[2] - v31))
                                                                                              + (float)((float)((float)(*v17 - v29) * (float)(*v17 - v29)) + (float)((float)(v17[1] - v30) * (float)(v17[1] - v30))))
                                                                                      * (float)0.5))
                                                                      * (float)v22)
                                                              - (float)1.5)
                                              * (float)v22))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v22
                                                      * (float)((float)((float)((float)(v17[2] - v31)
                                                                              * (float)(v17[2] - v31))
                                                                      + (float)((float)((float)(*v17 - v29)
                                                                                      * (float)(*v17 - v29))
                                                                              + (float)((float)(v17[1] - v30)
                                                                                      * (float)(v17[1] - v30))))
                                                              * (float)0.5))
                                              * (float)v22)
                                      - (float)1.5)
                      * (float)v22));
  v24 = (float)((float)-(float)((float)((float)((float)v23
                                              * (float)((float)((float)((float)(v17[2] - v31) * (float)(v17[2] - v31))
                                                              + (float)((float)((float)(*v17 - v29) * (float)(*v17 - v29))
                                                                      + (float)((float)(v17[1] - v30)
                                                                              * (float)(v17[1] - v30))))
                                                      * (float)0.5))
                                      * (float)v23)
                              - (float)1.5)
              * (float)v23);
  v32[0].mat[0].y = (float)(v17[1] - v30)
                  * (float)((float)-(float)((float)((float)((float)v23
                                                          * (float)((float)((float)((float)(v17[2] - v31)
                                                                                  * (float)(v17[2] - v31))
                                                                          + (float)((float)((float)(*v17 - v29)
                                                                                          * (float)(*v17 - v29))
                                                                                  + (float)((float)(v17[1] - v30)
                                                                                          * (float)(v17[1] - v30))))
                                                                  * (float)0.5))
                                                  * (float)v23)
                                          - (float)1.5)
                          * (float)v23);
  v32[0].mat[0].x = (float)v18 * (float)v24;
  v32[0].mat[0].z = (float)v19 * (float)v24;
  idVec3::ToMat3(this: &v32[0].mat[2], result: v32);
  v25 = idEntity::GetPhysics(this);
  v25->SetAxis(this: v25, a2: (const idMat3 *)&v32[0].mat[2], a3: -1);
  presentable = player->presentable;
  entityNumber = player->entityNumber;
  if ( presentable != nullptr )
    v28 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v28 = nullptr;
  idPresentablePlayer::DrawGuis(this: v28, id: entityNumber + 1);
  return idCameraView::Draw(this, player);
}


// ========================================================================
// ??0idThrownCamera@@QAA@XZ
// EA  : 0x82D11C98
// RVA : 0x00D11C98
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idThrownCamera *__fastcall idThrownCamera::idThrownCamera(idThrownCamera *this)
{
  float z; // r9

  idCameraView::idCameraView(this);
  this->startTime = 0;
  this->__vftable = (idThrownCamera_vtbl *)&idThrownCamera::`vftable';
  this->startingOrigin.x = vec3_origin.x;
  this->startingOrigin.y = vec3_origin.y;
  z = vec3_origin.z;
  this->distToTarget = 0.0;
  this->cameraEndTime = 0;
  this->usePhysicsToGetAngles = true;
  this->startingOrigin.z = z;
  return this;
}


// ========================================================================
// ?InternalDeactivate@idThrownCamera@@UAA_NXZ
// EA  : 0x82D11D18
// RVA : 0x00D11D18
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idThrownCamera::InternalDeactivate(idThrownCamera *this)
{
  idPlayer *PlayerActivator; // r3
  idPlayer *v3; // r30
  idPhysics *Physics; // r3
  int v5; // r3
  float v6; // r7
  float v7; // r6
  idPhysics *v8; // r3
  idPresentable *presentable; // r3
  int v10; // r3
  idPresentable *v11; // r3
  int v12; // r3
  idPresentable *v13; // r3
  int v14; // r3
  int value; // r10
  int v16; // r7
  idVehicle *v17; // r3
  idVehicle *v18; // r3
  idPhysics *v19; // r3
  float *v20; // r3
  double v21; // fp9
  double v22; // fp7
  const idAngles *v23; // r3
  int v25; // [sp+8h] [-98h]
  __int64 v26; // [sp+10h] [-90h]
  __int64 v27; // [sp+18h] [-88h]
  __int64 v28; // [sp+20h] [-80h]
  __int64 v29; // [sp+28h] [-78h]
  __int64 v30; // [sp+30h] [-70h]
  float v31; // [sp+50h] [-50h] BYREF
  float v32; // [sp+54h] [-4Ch]
  float v33; // [sp+58h] [-48h]
  idVec3 v34; // [sp+60h] [-40h] BYREF
  idVec3 v35[4]; // [sp+70h] [-30h] BYREF

  PlayerActivator = idCamera::GetPlayerActivator(this);
  v3 = PlayerActivator;
  if ( PlayerActivator != nullptr )
  {
    Physics = idEntity::GetPhysics(this: PlayerActivator);
    v5 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v6 = *(float *)(v5 + 4);
    v7 = *(float *)(v5 + 8);
    v31 = *(float *)v5;
    v32 = v6;
    v33 = v7;
    v8 = idEntity::GetPhysics(this: v3);
    v8->SetOrigin(this: v8, a2: (const idVec3 *)&v31, a3: -1);
    presentable = v3->presentable;
    if ( presentable != nullptr )
      v10 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v10 = 0;
    if ( v10 != -37616 )
    {
      v11 = v3->presentable;
      if ( v11 != nullptr )
        v12 = (int)v11->GetPlayerInterface_2(this: v11);
      else
        v12 = 0;
      idHands::ClearPendingAction(this: (idHands *)(v12 + 37616));
      v13 = v3->presentable;
      if ( v13 != nullptr )
        v14 = (int)v13->GetPlayerInterface_2(this: v13);
      else
        v14 = 0;
      idHands::Show(this: (idHands *)(v14 + 37616), hideReason: HAND_HIDE_VEHICLE);
    }
    value = v3->lastVehicle.spawnId.value;
    v16 = (value & 0x1FFF) + 29755;
    if ( *((_DWORD *)&gameLocal->__vftable + v16) == value >> 13 )
    {
      v17 = (idVehicle *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v17 != nullptr )
      {
        v18 = idVehicle::CastTo(c: v17);
        if ( v18 != nullptr )
        {
          v19 = idEntity::GetPhysics(this: v18);
          v20 = (float *)v19->GetOrigin(this: v19, a2: 0);
          v21 = (float)(v20[2] - v33);
          v22 = (float)(v20[1] - v32);
          v34.x = *v20 - v31;
          v34.z = v21;
          v34.y = v22;
          idVec3::NormalizeFast(this: &v34);
          v23 = idVec3::ToAngles(this: v35, result: (idAngles *)&v34);
          idPlayer::SetViewAngles(this: v3, angles: v23, force: false);
        }
      }
    }
    idCameraView::FadeIn(
      this: (idCameraView *)LODWORD(idColor::colorBlack.r),
      timeMs: __SPAIR64__(LODWORD(idColor::colorBlack.a), throwCamera_fadeDelay.valueInteger),
      a3: v16,
      a4: (int)&idColor::colorBlack,
      a5: (int)&throwCamera_fadeDelay,
      a6: (int)&aAvSsobjectVCom[20],
      a7: v25,
      a8: v26,
      a9: v27,
      a10: v28,
      a11: v29,
      a12: v30);
  }
  idEntity::BecomeInactive(this, flags: 1);
  return 1;
}


// ========================================================================
// ?Init@idThrownCamera@@QAAXVidVec3@@VidMat3@@M@Z
// EA  : 0x82D11F10
// RVA : 0x00D11F10
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idThrownCamera::Init(
        idThrownCamera *this,
        idVec3 *origin,
        __int64 axis,
        double inCameraFollowTime,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16)
{
  idEntity *v16; // r3
  idEntity *v17; // r31
  idPhysics *Physics; // r3
  idPhysics *v20; // r3
  double v21; // fp13
  double v22; // fp12
  float *p_y; // r30
  int v24; // r5
  idEntity *v25; // r3
  int v26; // r9
  idEntity *v27; // r3
  idEntity *v28; // r3
  idPhysics *v29; // r3
  float *v30; // r3
  double v31; // fp8
  double v32; // fp11
  double v35; // fp7
  double v36; // fp13

  a10 = *(_QWORD *)&origin;
  v17 = v16;
  a11 = *(__int64 *)((char *)&axis + 4);
  a12 = axis;
  a13 = *(__int64 *)((char *)&a5 + 4);
  a14 = a5;
  a15 = *(__int64 *)((char *)&a6 + 4);
  a16 = a6;
  Physics = idEntity::GetPhysics(this: v16);
  Physics->SetOrigin(this: Physics, a2: (const idVec3 *)&a10, a3: -1);
  v20 = idEntity::GetPhysics(this: v17);
  v20->SetAxis(this: v20, a2: (const idMat3 *)&a12, a3: -1);
  v21 = *((float *)&a10 + 1);
  v22 = *(float *)&a11;
  p_y = &v17[1].spawnOrientation.mat[2].y;
  v17[1].spawnOrientation.mat[2].y = *(float *)&a10;
  v17[1].spawnOrientation.mat[2].z = v21;
  *(float *)&v17[1].flags = v22;
  LODWORD(v17[1].spawnOrientation.mat[2].x) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v24 = *(_DWORD *)&v17[1].name.baseBuffer[8];
  if ( gameLocal->spawnIds.ptr[v24 & 0x1FFF] == v24 >> 13 )
  {
    v25 = gameLocal->entities.ptr[v24 & 0x1FFF];
    if ( v25 != nullptr && idEntity::CastTo(c: v25) != nullptr )
    {
      v26 = *(_DWORD *)&v17[1].name.baseBuffer[8];
      if ( gameLocal->spawnIds.ptr[v26 & 0x1FFF] == v26 >> 13
        && (v27 = gameLocal->entities.ptr[v26 & 0x1FFF]) != nullptr )
      {
        v28 = idEntity::CastTo(c: v27);
      }
      else
      {
        v28 = nullptr;
      }
      v29 = idEntity::GetPhysics(this: v28);
      v30 = (float *)v29->GetOrigin(this: v29, a2: 0);
      v31 = (float)(*(float *)&v17[1].flags - *(float *)&v17[1].flags);
      v32 = (float)((float)((float)(*v30 - *p_y) * (float)(*v30 - *p_y))
                  + (float)((float)((float)v31 * (float)v31)
                          + (float)((float)(v30[1] - v17[1].spawnOrientation.mat[2].z)
                                  * (float)(v30[1] - v17[1].spawnOrientation.mat[2].z))));
      _FP10 = (float)((float)((float)((float)(*v30 - *p_y) * (float)(*v30 - *p_y))
                            + (float)((float)((float)v31 * (float)v31)
                                    + (float)((float)(v30[1] - v17[1].spawnOrientation.mat[2].z)
                                            * (float)(v30[1] - v17[1].spawnOrientation.mat[2].z))))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f8, f10, f11, f13 }
      v35 = __frsqrte(_FP8);
      v36 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35
                                                                                          * (float)((float)v32
                                                                                                  * (float)0.5))
                                                                                  * (float)v35)
                                                                          - (float)1.5)
                                                          * (float)v35)
                                                  * (float)((float)v32 * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v35
                                                                                  * (float)((float)v32 * (float)0.5))
                                                                          * (float)v35)
                                                                  - (float)1.5)
                                                  * (float)v35))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)v32 * (float)0.5)) * (float)v35)
                                          - (float)1.5)
                          * (float)v35));
      *(float *)&v17[1].targets.list = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35 * (float)((float)v32 * (float)0.5)) * (float)v35) - (float)1.5) * (float)v35) * (float)((float)v32 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)v32 * (float)0.5)) * (float)v35) - (float)1.5) * (float)v35)) - (float)1.5)
                                                                                     * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)v32 * (float)0.5)) * (float)v35) - (float)1.5)
                                                                                             * (float)v35))
                                                                             * (float)((float)v32 * (float)0.5))
                                                                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35 * (float)((float)v32 * (float)0.5)) * (float)v35) - (float)1.5) * (float)v35) * (float)((float)v32 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)v32 * (float)0.5)) * (float)v35) - (float)1.5) * (float)v35))
                                                                                             - (float)1.5)
                                                                             * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)v32 * (float)0.5)) * (float)v35) - (float)1.5)
                                                                                     * (float)v35)))
                                                             - (float)1.5)
                                             * (float)v36)
                                     * (float)v32;
      v17[1].targets.num = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
                         + (int)(float)((float)1000.0 * (float)inCameraFollowTime);
    }
  }
}


// ========================================================================
// ?Think@idThrownCamera@@UAAXXZ
// EA  : 0x82D12140
// RVA : 0x00D12140
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idThrownCamera::Think(idThrownCamera *this)
{
  int value; // r10
  idEntity *v3; // r3
  idVehicleOccupant *v4; // r3
  idVehicleOccupant *v5; // r27
  int cameraEndTime; // r9
  idGameLocal *v7; // r8
  int v8; // r7
  idEntity *v9; // r3
  int valueInteger; // r31
  int v11; // r3
  char v12; // r11
  char v13; // r31
  int v14; // r3
  int v15; // r31
  int v16; // r10
  idEntity *v17; // r3
  idPhysics *Physics; // r3
  int v19; // r3
  float v20; // r7
  float v21; // r6
  __int64 v22; // r9
  __int64 v23; // r7
  double v24; // fp0
  int v25; // r9
  idEntity *v26; // r3
  idVehicleOccupant *v27; // r3
  idVehicleOccupant *v28; // r3
  int (*GetOrigin)(void); // ctr
  int v30; // r9
  idEntity *v31; // r3
  idEntity *v32; // r3
  float *v33; // r3
  int v34; // r9
  idEntity *v35; // r3
  idVehicleOccupant *v36; // r3
  int v37; // r9
  idEntity *v38; // r3
  idEntity *v39; // r3
  int v40; // r3
  float *v41; // r3
  double x; // fp8
  double y; // fp9
  double z; // fp4
  double v45; // fp5
  double v46; // fp6
  double v49; // fp1
  double v50; // fp7
  double v51; // fp1
  double v53; // fp5
  double v55; // fp1
  double v56; // fp0
  double v57; // fp5
  double v58; // fp11
  double v59; // fp7
  double v60; // fp5
  double v61; // fp0
  double v64; // fp2
  double v65; // fp1
  idPhysics *v66; // r3
  double v69; // fp13
  double v70; // fp3
  idPhysics *v71; // r3
  int v72; // [sp+8h] [-1B8h]
  __int64 v73; // [sp+10h] [-1B0h]
  __int64 v74; // [sp+18h] [-1A8h]
  __int64 v75; // [sp+20h] [-1A0h]
  __int64 v76; // [sp+28h] [-198h]
  __int64 v77; // [sp+30h] [-190h]
  idVec3 v78; // [sp+50h] [-170h] BYREF
  idVec3 v79; // [sp+60h] [-160h] BYREF
  idVec3 v80; // [sp+70h] [-150h] BYREF
  __int64 v81; // [sp+80h] [-140h]
  idMat3 v82[2]; // [sp+88h] [-138h] BYREF
  idEventReceiver v83[2]; // [sp+D0h] [-F0h] BYREF
  trace_t v84; // [sp+F0h] [-D0h] BYREF

  value = this->target.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v4 = (idVehicleOccupant *)idEntity::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = idVehicleOccupant::CastTo(c: v4);
  if ( !this->fading )
  {
    cameraEndTime = this->target.spawnId.value;
    v7 = gameLocal;
    v8 = cameraEndTime >> 13;
    if ( gameLocal->spawnIds.ptr[cameraEndTime & 0x1FFF] != cameraEndTime >> 13
      || (cameraEndTime = 4 * ((cameraEndTime & 0x1FFF) + 21563),
          (v9 = *(idEntity **)((char *)&gameLocal->__vftable + cameraEndTime)) == nullptr)
      || idEntity::CastTo(c: v9) == nullptr
      || (valueInteger = throwCamera_fadeDelay.valueInteger,
          v11 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED),
          cameraEndTime = this->cameraEndTime,
          v12 = 0,
          v7 = (idGameLocal *)(cameraEndTime - valueInteger),
          v11 > cameraEndTime - valueInteger) )
    {
      v12 = 1;
    }
    v13 = v12;
    if ( v12 == 0 && v5 != nullptr && v5->GetAF_2(this: v5) != nullptr )
    {
      v14 = (int)v5->GetAF_2(this: v5);
      v8 = (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)(v14 + 288) + 160))(a1: v14 + 288);
      if ( v8 != 0 )
      {
        v15 = throwCamera_fadeDelay.valueInteger;
        cameraEndTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + v15;
        this->cameraEndTime = cameraEndTime;
        v13 = 1;
      }
    }
    if ( v13 != 0 )
      idCameraView::FadeOut(
        this: (idCameraView *)LODWORD(idColor::colorBlack.r),
        timeMs: __SPAIR64__(LODWORD(idColor::colorBlack.a), throwCamera_fadeDelay.valueInteger),
        a3: v8,
        a4: (int)v7,
        a5: cameraEndTime,
        a6: (int)&idColor::colorBlack,
        a7: v72,
        a8: v73,
        a9: v74,
        a10: v75,
        a11: v76,
        a12: v77);
  }
  v16 = this->target.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v16 & 0x1FFF] != v16 >> 13
    || (v17 = gameLocal->entities.ptr[v16 & 0x1FFF]) == nullptr
    || idEntity::CastTo(c: v17) == nullptr
    || gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) > this->cameraEndTime )
  {
    if ( v5 != nullptr )
      idVehicleOccupant::StopThrow(this: v5);
    idEventReceiver::ProcessEvent(this: v83, result: (idEventArg *)this, ev: &EV_Deactivate);
  }
  Physics = idEntity::GetPhysics(this);
  v19 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v20 = *(float *)(v19 + 4);
  v21 = *(float *)(v19 + 8);
  v79.x = *(float *)v19;
  v79.y = v20;
  v79.z = v21;
  LODWORD(v22) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  LODWORD(v23) = this->startTime;
  v81 = v23;
  v24 = (float)((float)((float)v22 - (float)v23) * (float)0.000099999997);
  if ( v24 >= 0.0 )
  {
    if ( v24 > 1.0 )
      v24 = 1.0;
  }
  else
  {
    v24 = 0.0;
  }
  v25 = this->target.spawnId.value;
  v79.z = (float)((float)v24 * (float)600.0) + this->startingOrigin.z;
  if ( gameLocal->spawnIds.ptr[v25 & 0x1FFF] == v25 >> 13 && (v26 = gameLocal->entities.ptr[v25 & 0x1FFF]) != nullptr )
    v27 = (idVehicleOccupant *)idEntity::CastTo(c: v26);
  else
    v27 = nullptr;
  v28 = idVehicleOccupant::CastTo(c: v27);
  if ( v28 != nullptr )
  {
    GetOrigin = (int (*)(void))v28->GetAF_2(this: v28)->physicsObj.GetOrigin;
  }
  else
  {
    v30 = this->target.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v30 & 0x1FFF] == v30 >> 13 && (v31 = gameLocal->entities.ptr[v30 & 0x1FFF]) != nullptr )
      v32 = idEntity::CastTo(c: v31);
    else
      v32 = nullptr;
    GetOrigin = (int (*)(void))idEntity::GetPhysics(this: v32)->GetOrigin;
  }
  v33 = (float *)GetOrigin();
  v78.x = *v33;
  v34 = this->target.spawnId.value;
  v78.y = v33[1];
  v78.z = v33[2];
  if ( gameLocal->spawnIds.ptr[v34 & 0x1FFF] == v34 >> 13 && (v35 = gameLocal->entities.ptr[v34 & 0x1FFF]) != nullptr )
    v36 = (idVehicleOccupant *)idEntity::CastTo(c: v35);
  else
    v36 = nullptr;
  if ( idVehicleOccupant::CastTo(c: v36) != nullptr )
  {
    v37 = this->target.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v37 & 0x1FFF] == v37 >> 13 && (v38 = gameLocal->entities.ptr[v37 & 0x1FFF]) != nullptr )
      v39 = idEntity::CastTo(c: v38);
    else
      v39 = nullptr;
    v40 = (int)v39->GetAF_2(this: v39);
    v41 = (float *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v40 + 288) + 64))(a1: v40 + 288, a2: 0);
    x = *v41;
    v78.x = *v41;
    y = v41[1];
    v78.y = v41[1];
    z = v41[2];
    v78.z = v41[2];
  }
  else
  {
    z = v78.z;
    y = v78.y;
    x = v78.x;
  }
  v45 = v79.y;
  v46 = v79.x;
  _FP7 = (float)((float)((float)((float)((float)x - v79.x) * (float)((float)x - v79.x))
                       + (float)((float)((float)y - v79.y) * (float)((float)y - v79.y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f7, f0, f13 }
  v49 = __frsqrte(_FP2);
  v50 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v49
                                                                                      * (float)((float)((float)((float)((float)x - v79.x) * (float)((float)x - v79.x)) + (float)((float)((float)y - v79.y) * (float)((float)y - v79.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v49)
                                                                      - (float)1.5)
                                                      * (float)v49)
                                              * (float)((float)((float)((float)((float)x - v79.x)
                                                                      * (float)((float)x - v79.x))
                                                              + (float)((float)((float)y - v79.y)
                                                                      * (float)((float)y - v79.y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v49
                                                                              * (float)((float)((float)((float)((float)x - v79.x) * (float)((float)x - v79.x))
                                                                                              + (float)((float)((float)y - v79.y) * (float)((float)y - v79.y)))
                                                                                      * (float)0.5))
                                                                      * (float)v49)
                                                              - (float)1.5)
                                              * (float)v49))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v49
                                                      * (float)((float)((float)((float)((float)x - v79.x)
                                                                              * (float)((float)x - v79.x))
                                                                      + (float)((float)((float)y - v79.y)
                                                                              * (float)((float)y - v79.y)))
                                                              * (float)0.5))
                                              * (float)v49)
                                      - (float)1.5)
                      * (float)v49));
  v51 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)((float)x - v79.x) * (float)((float)x - v79.x)) + (float)((float)((float)y - v79.y) * (float)((float)y - v79.y))) * (float)0.5)) * (float)v49) - (float)1.5)
                                                                                              * (float)v49)
                                                                                      * (float)((float)((float)((float)((float)x - v79.x) * (float)((float)x - v79.x)) + (float)((float)((float)y - v79.y) * (float)((float)y - v79.y)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v49 * (float)((float)((float)((float)((float)x - v79.x) * (float)((float)x - v79.x)) + (float)((float)((float)y - v79.y) * (float)((float)y - v79.y))) * (float)0.5)) * (float)v49) - (float)1.5)
                                                                                      * (float)v49))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v49
                                                                                              * (float)((float)((float)((float)((float)x - v79.x) * (float)((float)x - v79.x)) + (float)((float)((float)y - v79.y) * (float)((float)y - v79.y))) * (float)0.5))
                                                                                      * (float)v49)
                                                                              - (float)1.5)
                                                              * (float)v49))
                                              * (float)((float)((float)((float)((float)x - v79.x)
                                                                      * (float)((float)x - v79.x))
                                                              + (float)((float)((float)y - v79.y)
                                                                      * (float)((float)y - v79.y)))
                                                      * (float)0.5))
                                      * (float)v50)
                              - (float)1.5)
              * (float)v50);
  if ( (float)((float)v51
             * (float)((float)((float)((float)x - v79.x) * (float)((float)x - v79.x))
                     + (float)((float)((float)y - v79.y) * (float)((float)y - v79.y)))) > (double)this->distToTarget )
  {
    _FP6 = (float)((float)((float)((float)((float)x - v79.x) * (float)((float)x - v79.x))
                         + (float)((float)((float)y - v79.y) * (float)((float)y - v79.y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v53 = (float)((float)((float)((float)((float)x - v79.x) * (float)((float)x - v79.x))
                        + (float)((float)((float)y - v79.y) * (float)((float)y - v79.y)))
                * (float)0.5);
    __asm { fsel      f2, f6, f0, f13 }
    v55 = (float)((float)((float)((float)((float)v51
                                        * (float)((float)((float)((float)x - v79.x) * (float)((float)x - v79.x))
                                                + (float)((float)((float)y - v79.y) * (float)((float)y - v79.y))))
                                - this->distToTarget)
                        * (float)0.98000002)
                + this->distToTarget);
    v56 = __frsqrte(_FP2);
    v57 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                                * (float)v56)
                                                                                        * (float)v53)
                                                                                * (float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                        * (float)v56))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                        * (float)v56)
                                                                                - (float)1.5)
                                                                * (float)v56))
                                                * (float)v53)
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                        * (float)v56)
                                                                                * (float)v53)
                                                                        * (float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56)
                                                                                                - (float)1.5)
                                                                                * (float)v56))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                * (float)v56)
                                                                        - (float)1.5)
                                                        * (float)v56)))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                        * (float)v56)
                                                                                - (float)1.5)
                                                                * (float)v56)
                                                        * (float)v53)
                                                * (float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                * (float)v56)
                                                                        - (float)1.5)
                                                        * (float)v56))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                * (float)v56)));
    v46 = (float)((float)x - (float)((float)v55 * (float)((float)v57 * (float)((float)x - v79.x))));
    v79.x = (float)x - (float)((float)v55 * (float)((float)v57 * (float)((float)x - v79.x)));
    v45 = (float)((float)y - (float)((float)((float)((float)y - v79.y) * (float)v57) * (float)v55));
    v79.y = v45;
  }
  v58 = (float)((float)v45 - (float)y);
  v59 = (float)((float)v46 - (float)x);
  v80 = v79;
  v60 = (float)((float)((float)(v79.z - (float)z) * (float)(v79.z - (float)z))
              + (float)((float)((float)v45 - (float)y) * (float)((float)v45 - (float)y)));
  v61 = (float)((float)((float)((float)v46 - (float)x) * (float)((float)v46 - (float)x)) + (float)v60);
  if ( v61 > 16777216.0 )
  {
    _FP6 = (float)((float)((float)((float)((float)v46 - (float)x) * (float)((float)v46 - (float)x)) + (float)v60)
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f6, f0, f13 }
    v64 = __frsqrte(_FP3);
    v65 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v64
                                                                                        * (float)((float)v61 * (float)0.5))
                                                                                * (float)v64)
                                                                        - (float)1.5)
                                                        * (float)v64)
                                                * (float)((float)v61 * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v64
                                                                                * (float)((float)v61 * (float)0.5))
                                                                        * (float)v64)
                                                                - (float)1.5)
                                                * (float)v64))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64)
                                        - (float)1.5)
                        * (float)v64));
    v80.y = (float)((float)((float)v58
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64) - (float)1.5) * (float)v64) * (float)((float)v61 * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64) - (float)1.5) * (float)v64))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64)
                                                                                                  - (float)1.5)
                                                                                  * (float)v64))
                                                                  * (float)((float)v61 * (float)0.5))
                                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64) - (float)1.5) * (float)v64)
                                                                                                  * (float)((float)v61 * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64) - (float)1.5)
                                                                                                  * (float)v64))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5))
                                                                                                  * (float)v64)
                                                                                          - (float)1.5)
                                                                          * (float)v64)))
                                                  - (float)1.5)
                                  * (float)v65))
                  * (float)4095.0)
          + (float)y;
    v80.z = (float)((float)((float)(v79.z - (float)z)
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64) - (float)1.5) * (float)v64) * (float)((float)v61 * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64) - (float)1.5) * (float)v64))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64)
                                                                                                  - (float)1.5)
                                                                                  * (float)v64))
                                                                  * (float)((float)v61 * (float)0.5))
                                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64) - (float)1.5) * (float)v64)
                                                                                                  * (float)((float)v61 * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64) - (float)1.5)
                                                                                                  * (float)v64))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5))
                                                                                                  * (float)v64)
                                                                                          - (float)1.5)
                                                                          * (float)v64)))
                                                  - (float)1.5)
                                  * (float)v65))
                  * (float)4095.0)
          + (float)z;
    v80.x = (float)((float)((float)v59
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64) - (float)1.5) * (float)v64) * (float)((float)v61 * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64) - (float)1.5) * (float)v64))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64)
                                                                                                  - (float)1.5)
                                                                                  * (float)v64))
                                                                  * (float)((float)v61 * (float)0.5))
                                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64) - (float)1.5) * (float)v64)
                                                                                                  * (float)((float)v61 * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5)) * (float)v64) - (float)1.5)
                                                                                                  * (float)v64))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)v61 * (float)0.5))
                                                                                                  * (float)v64)
                                                                                          - (float)1.5)
                                                                          * (float)v64)))
                                                  - (float)1.5)
                                  * (float)v65))
                  * (float)4095.0)
          + (float)x;
  }
  idClip::TraceBounds(
    this: &clientGame->clip,
    result: &v84,
    start: &v78,
    end: &v80,
    trm: clientGame->clip.clip8x8,
    clipMask: 1,
    passEntityNumber: this->entityNumber);
  if ( v84.fraction >= 1.0 )
  {
    v66 = idEntity::GetPhysics(this);
    v66->SetOrigin(this: v66, a2: &v79, a3: -1);
  }
  _FP2 = (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x))
                       + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z))
                               + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f0, f2, f3, f0 }
  v69 = __frsqrte(_FP0);
  v70 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v69
                                                                                      * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x)) + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z)) + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y))))
                                                                                              * (float)0.5))
                                                                              * (float)v69)
                                                                      - (float)1.5)
                                                      * (float)v69)
                                              * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x))
                                                              + (float)((float)((float)(v78.z - v79.z)
                                                                              * (float)(v78.z - v79.z))
                                                                      + (float)((float)(v78.y - v79.y)
                                                                              * (float)(v78.y - v79.y))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v69
                                                                              * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x))
                                                                                              + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z)) + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y))))
                                                                                      * (float)0.5))
                                                                      * (float)v69)
                                                              - (float)1.5)
                                              * (float)v69))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v69
                                                      * (float)((float)((float)((float)(v78.x - v79.x)
                                                                              * (float)(v78.x - v79.x))
                                                                      + (float)((float)((float)(v78.z - v79.z)
                                                                                      * (float)(v78.z - v79.z))
                                                                              + (float)((float)(v78.y - v79.y)
                                                                                      * (float)(v78.y - v79.y))))
                                                              * (float)0.5))
                                              * (float)v69)
                                      - (float)1.5)
                      * (float)v69));
  v82[0].mat[0].x = (float)(v78.x - v79.x)
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x)) + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z)) + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y)))) * (float)0.5)) * (float)v69) - (float)1.5) * (float)v69)
                                                                                                  * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x)) + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z)) + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y)))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x)) + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z)) + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y)))) * (float)0.5)) * (float)v69) - (float)1.5)
                                                                                                  * (float)v69))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x)) + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z)) + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y)))) * (float)0.5))
                                                                                                  * (float)v69)
                                                                                          - (float)1.5)
                                                                          * (float)v69))
                                                          * (float)((float)((float)((float)(v78.x - v79.x)
                                                                                  * (float)(v78.x - v79.x))
                                                                          + (float)((float)((float)(v78.z - v79.z)
                                                                                          * (float)(v78.z - v79.z))
                                                                                  + (float)((float)(v78.y - v79.y)
                                                                                          * (float)(v78.y - v79.y))))
                                                                  * (float)0.5))
                                                  * (float)v70)
                                          - (float)1.5)
                          * (float)v70);
  v82[0].mat[0].y = (float)(v78.y - v79.y)
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x)) + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z)) + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y)))) * (float)0.5)) * (float)v69) - (float)1.5) * (float)v69)
                                                                                                  * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x)) + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z)) + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y)))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x)) + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z)) + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y)))) * (float)0.5)) * (float)v69) - (float)1.5)
                                                                                                  * (float)v69))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x)) + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z)) + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y)))) * (float)0.5))
                                                                                                  * (float)v69)
                                                                                          - (float)1.5)
                                                                          * (float)v69))
                                                          * (float)((float)((float)((float)(v78.x - v79.x)
                                                                                  * (float)(v78.x - v79.x))
                                                                          + (float)((float)((float)(v78.z - v79.z)
                                                                                          * (float)(v78.z - v79.z))
                                                                                  + (float)((float)(v78.y - v79.y)
                                                                                          * (float)(v78.y - v79.y))))
                                                                  * (float)0.5))
                                                  * (float)v70)
                                          - (float)1.5)
                          * (float)v70);
  v82[0].mat[0].z = (float)(v78.z - v79.z)
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x)) + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z)) + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y)))) * (float)0.5)) * (float)v69) - (float)1.5) * (float)v69)
                                                                                                  * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x)) + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z)) + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y)))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x)) + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z)) + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y)))) * (float)0.5)) * (float)v69) - (float)1.5)
                                                                                                  * (float)v69))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)(v78.x - v79.x) * (float)(v78.x - v79.x)) + (float)((float)((float)(v78.z - v79.z) * (float)(v78.z - v79.z)) + (float)((float)(v78.y - v79.y) * (float)(v78.y - v79.y)))) * (float)0.5))
                                                                                                  * (float)v69)
                                                                                          - (float)1.5)
                                                                          * (float)v69))
                                                          * (float)((float)((float)((float)(v78.x - v79.x)
                                                                                  * (float)(v78.x - v79.x))
                                                                          + (float)((float)((float)(v78.z - v79.z)
                                                                                          * (float)(v78.z - v79.z))
                                                                                  + (float)((float)(v78.y - v79.y)
                                                                                          * (float)(v78.y - v79.y))))
                                                                  * (float)0.5))
                                                  * (float)v70)
                                          - (float)1.5)
                          * (float)v70);
  idVec3::ToMat3(this: &v82[0].mat[2], result: v82);
  v71 = idEntity::GetPhysics(this);
  v71->SetAxis(this: v71, a2: (const idMat3 *)&v82[0].mat[2], a3: -1);
}


// ========================================================================
// ?Draw@idThrownCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D128C8
// RVA : 0x00D128C8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idThrownCamera::Draw(idThrownCamera *this, idPlayer *player)
{
  int value; // r10
  idEntity *v5; // r3

  value = this->target.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v5) != nullptr )
  {
    return idCameraView::Draw(this, player);
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ??0idRCBombDeathCamera@@QAA@XZ
// EA  : 0x82D12958
// RVA : 0x00D12958
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idRCBombDeathCamera *__fastcall idRCBombDeathCamera::idRCBombDeathCamera(idRCBombDeathCamera *this)
{
  int v2; // ctr
  float *p_y; // r9
  float *p_z; // r8

  idCameraView::idCameraView(this);
  this->__vftable = (idRCBombDeathCamera_vtbl *)&idRCBombDeathCamera::`vftable';
  this->startTime = 0;
  v2 = 9;
  this->startingOrigin = vec3_origin;
  p_y = &mat2_identity.mat[1].y;
  p_z = &this->startingOrigin.z;
  do
  {
    *++p_z = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->targetPos = vec3_origin;
  this->cameraPos = vec3_origin;
  this->cameraAngle.pitch = 0.0;
  this->cameraAngle.yaw = 0.0;
  this->cameraAngle.roll = 0.0;
  this->cinimaticViewPoint.spawnId.value = 0x1FFF;
  this->pullBack = true;
  this->focusAxis.mat[0].x = this->startingAxis.mat[0].x;
  this->focusAxis.mat[0].y = this->startingAxis.mat[0].y;
  this->focusAxis.mat[0].z = this->startingAxis.mat[0].z;
  this->focusAxis.mat[1].x = this->startingAxis.mat[1].x;
  this->focusAxis.mat[1].y = this->startingAxis.mat[1].y;
  this->focusAxis.mat[1].z = this->startingAxis.mat[1].z;
  this->focusAxis.mat[2].x = this->startingAxis.mat[2].x;
  this->focusAxis.mat[2].y = this->startingAxis.mat[2].y;
  this->focusAxis.mat[2].z = this->startingAxis.mat[2].z;
  this->focusPos.x = this->startingOrigin.x;
  this->focusPos.y = this->startingOrigin.y;
  this->focusPos.z = this->startingOrigin.z;
  return this;
}


// ========================================================================
// ?Think@idRCBombDeathCamera@@UAAXXZ
// EA  : 0x82D12AB0
// RVA : 0x00D12AB0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idRCBombDeathCamera::Think(idRCBombDeathCamera *this)
{
  int value; // r10
  idEntity *v3; // r3
  int v4; // r9
  idEntity *v5; // r3
  idEntity *v6; // r3
  idPhysics *Physics; // r3
  float *v8; // r3
  idGameLocal *v9; // r3
  idGameLocal_vtbl *v10; // r9
  double valueFloat; // fp30
  idVec3 *p_cameraPos; // r31
  __int64 v13; // r4
  double v14; // fp0
  double y; // fp6
  double z; // fp5
  double v17; // fp11
  double v18; // fp10
  double v19; // fp9
  double v20; // fp2
  double v21; // fp8
  double v22; // fp6
  double v23; // fp4
  double v24; // fp1
  double v25; // fp0
  double v26; // fp13
  double v27; // fp12
  double v28; // fp2
  double v29; // fp3
  idClipModel *clip8x8; // r7
  idClip *p_clip; // r3
  double v32; // fp0
  double v33; // fp13
  double fraction; // fp0
  double x; // fp11
  int entityNumber; // r9
  double v37; // fp6
  double v38; // fp5
  idPhysics *v39; // r3
  double v40; // fp8
  double v41; // fp6
  idVec3 v42; // [sp+50h] [-E0h] BYREF
  idAngles v43; // [sp+60h] [-D0h] BYREF
  trace_t v44; // [sp+70h] [-C0h] BYREF

  value = this->target.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v3 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v3 != nullptr && idEntity::CastTo(c: v3) != nullptr )
    {
      v4 = this->target.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v4 & 0x1FFF] == v4 >> 13 && (v5 = gameLocal->entities.ptr[v4 & 0x1FFF]) != nullptr )
        v6 = idEntity::CastTo(c: v5);
      else
        v6 = nullptr;
      Physics = idEntity::GetPhysics(this: v6);
      v8 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      this->targetPos.x = *v8;
      this->targetPos.y = v8[1];
      this->targetPos.z = v8[2];
    }
  }
  if ( this->pullBack )
  {
    v9 = gameLocal;
    this->cameraPos.x = this->focusPos.x;
    this->cameraPos.y = this->focusPos.y;
    v10 = v9->__vftable;
    this->cameraPos.z = this->focusPos.z;
    valueFloat = rcbomb_pulloutTime.valueFloat;
    p_cameraPos = &this->cameraPos;
    HIDWORD(v13) = v10->GetGameMs(this: v9, a2: GAMETIME_SCALED);
    LODWORD(v13) = this->startTime;
    *(_QWORD *)&v42.x = v13;
    v14 = (float)((float)((float)__SPAIR64__(0x82000000, HIDWORD(v13)) - (float)v13) / (float)valueFloat);
    if ( v14 >= 0.0 )
    {
      if ( v14 > 1.0 )
        v14 = 1.0;
    }
    else
    {
      v14 = 0.0;
    }
    y = this->cameraPos.y;
    z = this->cameraPos.z;
    v17 = (float)((float)((float)(this->focusAxis.mat[0].y * (float)v14)
                        * (float)((float)1.0 - rcbomb_updownRatio.valueFloat))
                * rcbomb_pulloutDistance.valueFloat);
    v18 = (float)((float)((float)(this->focusAxis.mat[0].z * (float)v14)
                        * (float)((float)1.0 - rcbomb_updownRatio.valueFloat))
                * rcbomb_pulloutDistance.valueFloat);
    v19 = (float)(p_cameraPos->x
                - (float)((float)((float)(this->focusAxis.mat[0].x * (float)v14)
                                * (float)((float)1.0 - rcbomb_updownRatio.valueFloat))
                        * rcbomb_pulloutDistance.valueFloat));
    p_cameraPos->x = p_cameraPos->x
                   - (float)((float)((float)(this->focusAxis.mat[0].x * (float)v14)
                                   * (float)((float)1.0 - rcbomb_updownRatio.valueFloat))
                           * rcbomb_pulloutDistance.valueFloat);
    this->cameraPos.y = (float)y - (float)v17;
    this->cameraPos.z = (float)z - (float)v18;
    v20 = (float)((float)y - (float)v17);
    v21 = (float)((float)(this->focusAxis.mat[0].y * (float)((float)1.0 - rcbomb_updownRatio.valueFloat))
                * rcbomb_initialOffset.valueFloat);
    v22 = (float)((float)(this->focusAxis.mat[0].z * (float)((float)1.0 - rcbomb_updownRatio.valueFloat))
                * rcbomb_initialOffset.valueFloat);
    v23 = (float)((float)v19
                - (float)((float)(this->focusAxis.mat[0].x * (float)((float)1.0 - rcbomb_updownRatio.valueFloat))
                        * rcbomb_initialOffset.valueFloat));
    p_cameraPos->x = (float)v19
                   - (float)((float)(this->focusAxis.mat[0].x * (float)((float)1.0 - rcbomb_updownRatio.valueFloat))
                           * rcbomb_initialOffset.valueFloat);
    this->cameraPos.y = (float)v20 - (float)v21;
    this->cameraPos.z = (float)((float)z - (float)v18) - (float)v22;
    v24 = (float)((float)((float)(this->focusAxis.mat[2].y * (float)v14) * rcbomb_updownRatio.valueFloat)
                * rcbomb_pulloutDistance.valueFloat);
    v26 = (float)((float)((float)((float)(this->focusAxis.mat[2].z * (float)v14) * rcbomb_updownRatio.valueFloat)
                        * rcbomb_pulloutDistance.valueFloat)
                + (float)((float)((float)z - (float)v18) - (float)v22));
    v25 = (float)((float)((float)(this->focusAxis.mat[2].x * (float)v14) * rcbomb_updownRatio.valueFloat)
                * rcbomb_pulloutDistance.valueFloat);
    this->cameraPos.z = v26;
    v27 = (float)((float)((float)v20 - (float)v21) + (float)v24);
    this->cameraPos.y = (float)((float)v20 - (float)v21) + (float)v24;
    p_cameraPos->x = (float)v23 + (float)v25;
    v28 = this->cameraPos.z;
    v29 = (float)((float)v23 + (float)v25);
    clip8x8 = clientGame->clip.clip8x8;
    p_clip = &clientGame->clip;
    v32 = (float)((float)(this->focusAxis.mat[2].x * rcbomb_updownRatio.valueFloat) * rcbomb_initialOffset.valueFloat);
    v33 = (float)((float)(this->focusAxis.mat[2].z * rcbomb_updownRatio.valueFloat) * rcbomb_initialOffset.valueFloat);
    this->cameraPos.y = (float)v27
                      + (float)((float)(this->focusAxis.mat[2].y * rcbomb_updownRatio.valueFloat)
                              * rcbomb_initialOffset.valueFloat);
    p_cameraPos->x = (float)v29 + (float)v32;
    this->cameraPos.z = (float)v33 + (float)v28;
    idClip::TraceBounds(
      this: p_clip,
      result: &v44,
      start: &this->focusPos,
      end: &this->cameraPos,
      trm: clip8x8,
      clipMask: 107553,
      passEntityNumber: this->entityNumber);
    fraction = v44.fraction;
    if ( v44.fraction != 1.0 )
    {
      x = v44.endpos.x;
      this->cameraPos.y = v44.endpos.y;
      p_cameraPos->x = x;
      this->cameraPos.z = v44.endpos.z;
      entityNumber = this->entityNumber;
      this->cameraPos.z = (float)((float)((float)1.0 - (float)fraction) * (float)32.0) + this->cameraPos.z;
      idClip::TraceBounds(
        this: &clientGame->clip,
        result: &v44,
        start: &this->focusPos,
        end: &this->cameraPos,
        trm: clientGame->clip.clip8x8,
        clipMask: 107553,
        passEntityNumber: entityNumber);
      v37 = v44.endpos.y;
      v38 = v44.endpos.z;
      p_cameraPos->x = v44.endpos.x;
      this->cameraPos.y = v37;
      this->cameraPos.z = v38;
    }
    v39 = idEntity::GetPhysics(this);
    v39->SetOrigin(this: v39, a2: &this->cameraPos, a3: -1);
    v40 = (float)(this->targetPos.y - this->cameraPos.y);
    v41 = (float)(this->targetPos.z - this->cameraPos.z);
    v43.pitch = this->targetPos.x - p_cameraPos->x;
    v43.yaw = v40;
    v43.roll = v41;
    this->cameraAngle = *idVec3::ToAngles(this: &v42, result: &v43);
  }
}


// ========================================================================
// ?Event_NextCamera@idCaptureController@@AAA?AVeventVoid@@XZ
// EA  : 0x82D12EE8
// RVA : 0x00D12EE8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idCaptureController *__fastcall idCaptureController::Event_NextCamera(idCaptureController *this, idEntity *result)
{
  int v4; // r9
  idEntity *v5; // r3
  idEntity *v6; // r3
  idEntity *v7; // r3
  float y; // r11
  idGameLocal *v9; // r10
  int v10; // r8
  idVehicle *v11; // r3
  int v12; // r9
  int v13; // r11
  idVehicle *Entity; // r3
  idVehicle *v15; // r26
  char *CameraTagName; // r4
  int x_low; // r11
  int v18; // r9
  idEntity *v19; // r3
  idEntity *v20; // r3
  idStr v22[3]; // [sp+60h] [-60h] BYREF

  if ( HIBYTE(result[1].spawnOrientation.mat[2].x) == 0 )
    return this;
  v22[0].len = 0;
  v22[0].allocedAndFlag = 20;
  v22[0].data = v22[0].baseBuffer;
  v22[0].baseBuffer[0] = 0;
  if ( (int)result[1].listenerList > 0 )
  {
    v4 = *((_DWORD *)&result[1].GetType + 2 * LODWORD(result[1].spawnOrientation.mat[1].z));
    if ( gameLocal->spawnIds.ptr[v4 & 0x1FFF] == v4 >> 13 )
    {
      v5 = gameLocal->entities.ptr[(int)*(&result[1].GetType + 2 * LODWORD(result[1].spawnOrientation.mat[1].z))
                                 & 0x1FFF];
      if ( v5 != nullptr && idEntity::CastTo(c: v5) != nullptr )
      {
        v6 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)result[1].__vftable + 2 * LODWORD(result[1].spawnOrientation.mat[1].z));
        idEntity::Activate(this: v6, activator: result);
        v7 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)result[1].__vftable + 2 * LODWORD(result[1].spawnOrientation.mat[1].z));
        idStr::operator=(this: v22, text: v7->name.data);
      }
    }
  }
  cvarSystem->SetCVarBool(this: cvarSystem, a2: "vehicle_cam", a3: false, a4: 0);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "resetBreakables");
  idStr::Append(this: v22, text: "/");
  y = result[1].spawnOrientation.mat[1].y;
  if ( SLODWORD(y) < *(_DWORD *)&result[1].name.baseBuffer[12] )
  {
    v9 = gameLocal;
    v10 = *(_DWORD *)(20 * LODWORD(y) + *(_DWORD *)&result[1].name.baseBuffer[8]);
    if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] != v10 >> 13 )
      goto LABEL_16;
    v11 = (idVehicle *)gameLocal->entities.ptr[*(_DWORD *)(20 * LODWORD(y) + *(_DWORD *)&result[1].name.baseBuffer[8])
                                             & 0x1FFF];
    if ( v11 == nullptr )
      goto LABEL_16;
    if ( idVehicle::CastTo(c: v11) != nullptr )
    {
      v12 = *(_DWORD *)&result[1].name.baseBuffer[8];
      v13 = 20 * LODWORD(result[1].spawnOrientation.mat[1].y);
      if ( SLODWORD(result[1].spawnOrientation.mat[1].x) < *(_DWORD *)(v13 + v12 + 8) )
      {
        Entity = idEntityPtr<idVehicle>::GetEntity(this: (idEntityPtr<idVehicle> *)(v13 + v12));
        v15 = idVehicle::CastTo(c: Entity);
        cvarSystem->SetCVarString(this: cvarSystem, a2: "vehicle_follow", a3: v15->name.data, a4: 0);
        idStr::Append(this: v22, text: v15->name.data);
        idStr::Append(this: v22, text: "/");
        cvarSystem->SetCVarBool(this: cvarSystem, a2: "vehicle_cam", a3: true, a4: 0);
        if ( cine_ignoreCameraOffsets.valueInteger == 0 )
        {
          ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
            a1: cvarSystem,
            a2: "vehicle_cam_fwd",
            a3: *(float *)(*(_DWORD *)(20 * LODWORD(result[1].spawnOrientation.mat[1].y)
                                 + *(_DWORD *)&result[1].name.baseBuffer[8]
                                 + 4)
                     + 16 * LODWORD(result[1].spawnOrientation.mat[1].x)
                     + 4));
          ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
            a1: cvarSystem,
            a2: "vehicle_cam_rt",
            a3: *(float *)(*(_DWORD *)(20 * LODWORD(result[1].spawnOrientation.mat[1].y)
                                 + *(_DWORD *)&result[1].name.baseBuffer[8]
                                 + 4)
                     + 16 * LODWORD(result[1].spawnOrientation.mat[1].x)
                     + 8));
          ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
            a1: cvarSystem,
            a2: "vehicle_cam_up",
            a3: *(float *)(*(_DWORD *)(20 * LODWORD(result[1].spawnOrientation.mat[1].y)
                                 + *(_DWORD *)&result[1].name.baseBuffer[8]
                                 + 4)
                     + 16 * LODWORD(result[1].spawnOrientation.mat[1].x)
                     + 12));
        }
        idVehicle::SetCurrentCameraTag(num: *(_DWORD *)(*(_DWORD *)(20 * LODWORD(result[1].spawnOrientation.mat[1].y)
                                                                  + *(_DWORD *)&result[1].name.baseBuffer[8]
                                                                  + 4)
                                                      + 16 * LODWORD(result[1].spawnOrientation.mat[1].x)));
        CameraTagName = (char *)idVehicle::GetCameraTagName(num: *(_DWORD *)(*(_DWORD *)(20
                                                                                       * LODWORD(result[1].spawnOrientation.mat[1].y)
                                                                                       + *(_DWORD *)&result[1].name.baseBuffer[8]
                                                                                       + 4)
                                                                           + 16
                                                                           * LODWORD(result[1].spawnOrientation.mat[1].x)));
        goto LABEL_21;
      }
    }
  }
  v9 = gameLocal;
LABEL_16:
  x_low = LODWORD(result[1].spawnOrientation.mat[1].x);
  if ( x_low < result[1].name.allocedAndFlag )
  {
    v18 = *(_DWORD *)&result[1].name.data[4 * x_low];
    if ( v9->spawnIds.ptr[v18 & 0x1FFF] != v18 >> 13 )
      goto LABEL_22;
    v19 = v9->entities.ptr[*(_DWORD *)&result[1].name.data[4 * x_low] & 0x1FFF];
    if ( v19 == nullptr || idEntity::CastTo(c: v19) == nullptr )
      goto LABEL_22;
    v20 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&result[1].name.data[4 * LODWORD(result[1].spawnOrientation.mat[1].x)]);
    idEntity::Activate(this: v20, activator: result);
    CameraTagName = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&result[1].name.data[4 * LODWORD(result[1].spawnOrientation.mat[1].x)])->name.data;
LABEL_21:
    idStr::Append(this: v22, text: CameraTagName);
  }
LABEL_22:
  idCVar::SetString(this: &com_capturePath, newValue: v22[0].data, force: true);
  if ( cine_captureFrames.valueInteger != 0 )
  {
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_captureFrames", a3: 2, a4: 0);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "com_fixedTic", a3: true, a4: 0);
  }
  idEventReceiver::PostEventSec(
    this: result,
    ev: &EV_BetweenCameraInit,
    time: (float)(*((float *)&result[1].dtr_idClass + 2 * LODWORD(result[1].spawnOrientation.mat[1].z)) + (float)0.25));
  idStr::FreeData(this: v22);
  return this;
}


// ========================================================================
// __unwind$517902
// EA  : 0x82D133CC
// RVA : 0x00D133CC
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_517902()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ??0idSpectatorCamera@@QAA@XZ
// EA  : 0x82D133F8
// RVA : 0x00D133F8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idSpectatorCamera *__fastcall idSpectatorCamera::idSpectatorCamera(idSpectatorCamera *this)
{
  int v2; // ctr
  float *p_z; // r10
  float *p_y; // r11
  float z; // r5

  idCameraView::idCameraView(this);
  this->__vftable = (idSpectatorCamera_vtbl *)&idSpectatorCamera::`vftable';
  this->startTime = 0;
  v2 = 9;
  this->startingOrigin = vec3_origin;
  p_z = &this->startingOrigin.z;
  p_y = &mat2_identity.mat[1].y;
  do
  {
    *++p_z = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->targetPos.x = vec3_origin.x;
  this->targetPos.y = vec3_origin.y;
  z = vec3_origin.z;
  this->distToTarget = 0.0;
  this->targetPos.z = z;
  this->followVehicle.spawnId.value = 0x1FFF;
  this->playerVehicle.spawnId.value = 0x1FFF;
  this->lostVehicle = false;
  return this;
}


// ========================================================================
// ?Draw@idSpectatorCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D134F8
// RVA : 0x00D134F8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idSpectatorCamera::Draw(idSpectatorCamera *this, idPlayer *player)
{
  int v3; // r30
  idPresentable *presentable; // r3
  float *v5; // r3
  idPresentable *v6; // r3
  float *v7; // r3

  v3 = idCameraView::Draw(this, player);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v5 = (float *)presentable->GetSpectatorCameraInterface(this: presentable);
  v5[303] = this->viewAngles.pitch;
  v5[304] = this->viewAngles.yaw;
  v5[305] = this->viewAngles.roll;
  v6 = this->presentable;
  if ( v6 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v6 = this->presentable;
  }
  v7 = (float *)v6->GetSpectatorCameraInterface(this: v6);
  v7[300] = this->viewOrigin.x;
  v7[301] = this->viewOrigin.y;
  v7[302] = this->viewOrigin.z;
  return v3;
}


// ========================================================================
// ?Think@idSpectatorCamera@@UAAXXZ
// EA  : 0x82D135C0
// RVA : 0x00D135C0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idSpectatorCamera::Think(idSpectatorCamera *this)
{
  int value; // r10
  idEntityPtr<idVehicle> *p_followVehicle; // r28
  idVehicle *v4; // r3
  idVehicle *v5; // r3
  idVehicle *v6; // r3
  int v7; // r9
  idEntity *v8; // r3
  idPlayer *v9; // r3
  idPlayer *v10; // r3
  idPlayer *v11; // r31
  idPresentable *presentable; // r3
  int v13; // r3
  int UCmdTracker2; // r30
  int v15; // r3
  idVehicle *v16; // r3
  idVehicle *v17; // r3
  idVehicle *v18; // r3
  idPhysics *Physics; // r3
  int v20; // r3
  float v21; // r6
  int v22; // r11
  float v23; // r5
  float v24; // r3
  int v25; // r8
  idVehicle *v26; // r3
  idVehicle *v27; // r3
  idPhysics *v28; // r3
  idAngles *v29; // r3
  double valueFloat; // fp31
  idVec3 *v31; // r3
  int v32; // r11
  int v33; // r9
  double v34; // fp4
  double v35; // fp2
  idVehicle *v36; // r3
  idVehicle *v37; // r3
  idPhysics *v38; // r3
  int entityNumber; // r30
  idClipModel *clip8x8; // r29
  const idVec3 *v41; // r3
  idVehicle *Entity; // r3
  idPhysics *v43; // r3
  int v44; // r30
  idClipModel *v45; // r29
  const idVec3 *v46; // r3
  idPhysics *v47; // r3
  idVec3 v48; // [sp+50h] [-F0h] BYREF
  idMat3 v49; // [sp+60h] [-E0h] BYREF
  float v50; // [sp+84h] [-BCh]
  float v51; // [sp+88h] [-B8h]
  float v52; // [sp+8Ch] [-B4h]

  value = this->followVehicle.spawnId.value;
  p_followVehicle = &this->followVehicle;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v4 = (idVehicle *)gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || idVehicle::CastTo(c: v4) == nullptr
    || (gameLocal->spawnIds.ptr[p_followVehicle->spawnId.value & 0x1FFF] != p_followVehicle->spawnId.value >> 13
     || (v5 = (idVehicle *)gameLocal->entities.ptr[p_followVehicle->spawnId.value & 0x1FFF]) == nullptr
      ? (v6 = nullptr)
      : (v6 = idVehicle::CastTo(c: v5)),
        idVehicle::GetDriver(this: v6) == nullptr) )
  {
    this->lostVehicle = true;
    p_followVehicle->spawnId.value = 0x1FFF;
  }
  v7 = this->activator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13 && (v8 = gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
    v9 = (idPlayer *)idEntity::CastTo(c: v8);
  else
    v9 = nullptr;
  v10 = idPlayer::CastTo(c: v9);
  v11 = v10;
  if ( v10 != nullptr )
  {
    presentable = v10->presentable;
    v13 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
    if ( (*(_BYTE *)(v13 + 46321) & 0x80) == 0 )
    {
      UCmdTracker2 = idPlayer::GetUCmdTracker2(this: v11);
      v15 = idPlayer::GetUCmdTracker2(this: v11);
      this->HandleUserCmds(this, a2: (const usercmd_t *)(v15 + 8), a3: (const usercmd_t *)(UCmdTracker2 + 68));
    }
  }
  if ( !this->lostVehicle
    && gameLocal->spawnIds.ptr[p_followVehicle->spawnId.value & 0x1FFF] == p_followVehicle->spawnId.value >> 13 )
  {
    v16 = (idVehicle *)gameLocal->entities.ptr[p_followVehicle->spawnId.value & 0x1FFF];
    if ( v16 != nullptr && idVehicle::CastTo(c: v16) != nullptr )
    {
      if ( gameLocal->spawnIds.ptr[p_followVehicle->spawnId.value & 0x1FFF] == p_followVehicle->spawnId.value >> 13
        && (v17 = (idVehicle *)gameLocal->entities.ptr[p_followVehicle->spawnId.value & 0x1FFF]) != nullptr )
      {
        v18 = idVehicle::CastTo(c: v17);
      }
      else
      {
        v18 = nullptr;
      }
      Physics = idEntity::GetPhysics(this: v18);
      v20 = (int)Physics->GetOrigin(this: Physics, a2: 0);
      v21 = *(float *)v20;
      v22 = p_followVehicle->spawnId.value & 0x1FFF;
      v23 = *(float *)(v20 + 4);
      v24 = *(float *)(v20 + 8);
      v25 = p_followVehicle->spawnId.value >> 13;
      v48.x = v21;
      v48.y = v23;
      v48.z = v24;
      if ( gameLocal->spawnIds.ptr[v22] == v25 && (v26 = (idVehicle *)gameLocal->entities.ptr[v22]) != nullptr )
        v27 = idVehicle::CastTo(c: v26);
      else
        v27 = nullptr;
      v28 = idEntity::GetPhysics(this: v27);
      v29 = (idAngles *)v28->GetAxis(this: v28, a2: 0);
      idMat3::ToAngles(this: &v49, result: v29);
      valueFloat = spectator_cam_distance.valueFloat;
      v31 = idAngles::ToForward(this: (idAngles *)&v49.mat[1].y, result: v49.mat);
      v32 = p_followVehicle->spawnId.value & 0x1FFF;
      v33 = p_followVehicle->spawnId.value >> 13;
      v34 = (float)(v48.z - (float)(v31->z * (float)valueFloat));
      v35 = (float)(v48.y - (float)(v31->y * (float)valueFloat));
      v48.x = v48.x - (float)(v31->x * (float)valueFloat);
      v48.y = v35;
      v48.z = (float)v34 + spectator_cam_height.valueFloat;
      if ( gameLocal->spawnIds.ptr[v32] == v33 && (v36 = (idVehicle *)gameLocal->entities.ptr[v32]) != nullptr )
        v37 = idVehicle::CastTo(c: v36);
      else
        v37 = nullptr;
      v38 = idEntity::GetPhysics(this: v37);
      entityNumber = this->entityNumber;
      clip8x8 = clientGame->clip.clip8x8;
      v41 = v38->GetOrigin(this: v38, a2: 0);
      idClip::TraceBounds(
        this: &clientGame->clip,
        result: (trace_t *)&v49.mat[2].z,
        start: v41,
        end: &v48,
        trm: clip8x8,
        clipMask: 1,
        passEntityNumber: entityNumber);
      if ( v49.mat[2].z != 1.0 )
      {
        v48.x = v50;
        v48.y = v51;
        v48.z = (float)((float)((float)1.0 - v49.mat[2].z) * (float)32.0) + v52;
        Entity = idEntityPtr<idVehicle>::GetEntity(this: p_followVehicle);
        v43 = idEntity::GetPhysics(this: Entity);
        v44 = this->entityNumber;
        v45 = clientGame->clip.clip8x8;
        v46 = v43->GetOrigin(this: v43, a2: 0);
        idClip::TraceBounds(
          this: &clientGame->clip,
          result: (trace_t *)&v49.mat[2].z,
          start: v46,
          end: &v48,
          trm: v45,
          clipMask: 1,
          passEntityNumber: v44);
        v48.x = v50;
        v48.y = v51;
        v48.z = v52;
      }
      v47 = idEntity::GetPhysics(this);
      v47->SetOrigin(this: v47, a2: &v48, a3: -1);
    }
  }
}


// ========================================================================
// ??0idFreeCamera@@QAA@XZ
// EA  : 0x82D13A30
// RVA : 0x00D13A30
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idFreeCamera *__fastcall idFreeCamera::idFreeCamera(idFreeCamera *this)
{
  char v3; // r6

  idCameraView::idCameraView(this);
  this->__vftable = (idFreeCamera_vtbl *)&idFreeCamera::`vftable';
  this->prevcmd.buttons = 0;
  this->prevcmd.buttons2 = 0;
  this->prevcmd.pos[2] = 0.0;
  this->prevcmd.forwardmove = 0;
  this->prevcmd.pos[1] = 0.0;
  this->prevcmd.rightmove = 0;
  this->prevcmd.pos[0] = 0.0;
  this->prevcmd.upmove = 0;
  this->prevcmd.angles[2] = 0;
  this->prevcmd.angles[1] = 0;
  this->prevcmd.angles[0] = 0;
  this->prevcmd.clientGameFrame = 0;
  this->prevcmd.yaw = 0;
  this->prevcmd.pitch = 0;
  this->prevcmd.roll = 0;
  this->prevcmd.predictionStateBits = 0;
  this->prevcmd.vehicleThrottle = 0;
  this->prevcmd.serverGameTime = 0;
  this->prevcmd.fireCount = 0;
  this->prevcmd.fireAngles[1] = 0;
  this->prevcmd.fireAngles[0] = 0;
  this->prevcmd.firePos[2] = 0;
  v3 = *((_BYTE *)&this->prevcmd + 9);
  this->prevcmd.firePos[1] = 0;
  this->prevcmd.firePos[0] = 0;
  this->prevcmd.speed = 0;
  *((_BYTE *)&this->prevcmd + 9) = v3 & 0x3F;
  this->curAngles.pitch = 0.0;
  this->curAngles.yaw = 0.0;
  this->curAngles.roll = 0.0;
  this->curPos.x = 0.0;
  this->curPos.y = 0.0;
  this->curPos.z = 0.0;
  this->bFirstActive = true;
  return this;
}


// ========================================================================
// ?Deactivate@idCamera@@QAAXXZ
// EA  : 0x82D13BD0
// RVA : 0x00D13BD0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idCamera::Deactivate(idCamera *this)
{
  int value; // r10
  idEntity *v3; // r3
  idPlayer *v4; // r3
  idPlayer *v5; // r3
  idPlayer *v6; // r31

  if ( this->InternalDeactivate(this) )
  {
    value = this->activator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v4 = (idPlayer *)idEntity::CastTo(c: v3);
    }
    else
    {
      v4 = nullptr;
    }
    v5 = idPlayer::CastTo(c: v4);
    v6 = v5;
    if ( v5 != nullptr )
    {
      idPlayer::RemoveControl(this: v5, entity: this);
      *(_BYTE *)(idPlayer::GetPlayerHud(this: v6) + 8) = 1;
    }
    this->activator.spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?Event_Deactivate@idCamera@@QAA?AVeventVoid@@XZ
// EA  : 0x82D13C98
// RVA : 0x00D13C98
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idCamera *__fastcall idCamera::Event_Deactivate(idCamera *this, idCamera *result)
{
  idCamera::Deactivate(this: result);
  return this;
}


// ========================================================================
// ?InternalActivate@idCameraView@@UAA_NPAVidEntity@@@Z
// EA  : 0x82D13CD0
// RVA : 0x00D13CD0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idPlayer *__fastcall idCameraView::InternalActivate(idCameraView *this, idPlayer *activator_)
{
  idPlayer *result; // r3

  result = idPlayer::CastTo(c: activator_);
  if ( result != nullptr )
  {
    if ( activator_ != nullptr )
      this->activator.spawnId.value = (gameLocal->spawnIds.ptr[activator_->entityNumber] << 13)
                                    | activator_->entityNumber;
    else
      this->activator.spawnId.value = 0x1FFF;
    this->currentAngle = this->startingAngle;
    idEntity::BecomeActive(this, flags: 1);
    return (idPlayer *)1;
  }
  else
  {
    this->activator.spawnId.value = 0x1FFF;
  }
  return result;
}


// ========================================================================
// ?Draw@idInteractionCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D13D70
// RVA : 0x00D13D70
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idInteractionCamera::Draw(idInteractionCamera *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v5; // r3
  idPresentablePlayer *v6; // r31
  idView *p_view; // r31
  double CurTransform; // fp30
  double cameraFov; // fp31
  idPhysics *Physics; // r3
  float *v11; // r3
  int v12; // r5
  const idDeclEnv *envSettings; // r4
  idVec3 v15; // [sp+50h] [-80h] BYREF
  char v16; // [sp+60h] [-70h] BYREF
  idMat3 v17; // [sp+70h] [-60h] BYREF

  presentable = player->presentable;
  if ( presentable != nullptr )
  {
    v5 = presentable->GetPlayerInterface_2(this: presentable);
    v6 = v5;
    if ( v5 != nullptr )
    {
      idPresentablePlayer::DrawGuis(this: v5, id: player->entityNumber + 1);
      p_view = &v6->view;
      idInteractionCamera::RecalcualteDynamicSetupIfNecessary(this);
      CurTransform = idInteractionCamera::GetCurTransform(this, pos: &v15, axis: &v17);
      idView::SetViewPos(this: p_view, origin: &v15, axis: &v17);
      cameraFov = this->cameraFov;
      if ( this->returningToPlayer )
      {
        cameraFov = (float)((float)((float)(this->startFov - this->cameraFov) * (float)CurTransform) + this->cameraFov);
      }
      else if ( this->movingToAI )
      {
        cameraFov = (float)((float)((float)(this->cameraFov - this->startFov) * (float)CurTransform) + this->startFov);
      }
      Physics = idEntity::GetPhysics(this);
      v11 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v16, result: (idVec3 *)Physics, a3: 0);
      p_view->viewVelocity.x = *v11;
      p_view->viewVelocity.y = v11[1];
      p_view->viewVelocity.z = v11[2];
      idView::CalcFOV(this: p_view, base_fov: cameraFov);
      idView::SetViewID(this: p_view, id: player->entityNumber + 1);
      envSettings = this->envSettings;
      if ( envSettings != nullptr )
        idView::SetEnvironmentOverride(this: p_view, env: envSettings, blendDuration: -1.0, modelIndex: v12);
      idView::Render(this: p_view);
    }
  }
  return 1;
}


// ========================================================================
// ?InternalActivate@idInteractionCamera@@MAA_NPAVidEntity@@@Z
// EA  : 0x82D13EC8
// RVA : 0x00D13EC8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idInteractionCamera::InternalActivate(idInteractionCamera *this, idPlayer *activator_)
{
  idPlayer *v4; // r3
  idPlayer *v5; // r28
  idPresentable *presentable; // r3
  idActor *v7; // r30
  idPresentablePlayer *v8; // r3
  idPresentable *v9; // r3
  int v10; // r3
  int v11; // r27
  idView *v12; // r29
  int value; // r9
  idEntity *v14; // r3
  idPhysics *Physics; // r3
  int v16; // r3
  float v17; // r7
  float v18; // r6
  idActor *v19; // r3
  idPhysics *v20; // r3
  double v21; // fp31
  double v22; // fp30
  double v23; // fp29
  float *v24; // r3
  double v25; // fp6
  double v26; // fp4
  idAngles *v27; // r3
  idPhysics *v28; // r3
  idAngles *v29; // r3
  double roll; // fp29
  double yaw; // fp30
  double pitch; // fp31
  double v33; // fp0
  double v34; // fp13
  double v35; // fp12
  idPhysics_Player *v36; // r3
  __int64 v37; // r6
  idPhysics *v38; // r3
  float *v39; // r3
  double v40; // fp7
  double v41; // fp5
  idMat3 v43; // [sp+50h] [-100h] BYREF
  float y; // [sp+74h] [-DCh]
  float z; // [sp+78h] [-D8h]
  idVec3 v46; // [sp+80h] [-D0h] BYREF
  idVec3 v47; // [sp+90h] [-C0h] BYREF
  idAngles v48; // [sp+A0h] [-B0h] BYREF
  float x; // [sp+ACh] [-A4h]
  float v50; // [sp+B0h] [-A0h]
  float v51; // [sp+B4h] [-9Ch]
  float v52; // [sp+B8h] [-98h]
  float v53; // [sp+BCh] [-94h]
  float v54; // [sp+C0h] [-90h]
  idMat3 v55; // [sp+D0h] [-80h] BYREF

  v4 = idPlayer::CastTo(c: activator_);
  v5 = v4;
  if ( v4 == nullptr )
  {
    idLib::Warning(fmt: "Invalid activator '%s' for '%s'", activator_->name.data, this->name.data);
    this->activator.spawnId.value = 0x1FFF;
    return 0;
  }
  if ( activator_ != nullptr )
    this->activator.spawnId.value = (gameLocal->spawnIds.ptr[activator_->entityNumber] << 13) | activator_->entityNumber;
  else
    this->activator.spawnId.value = 0x1FFF;
  presentable = v4->presentable;
  v7 = nullptr;
  if ( presentable != nullptr )
    v8 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v8 = nullptr;
  if ( idPresentablePlayer::IsZoomedIn(ptr: v8) )
    idPlayer::SetupZoom(this: v5, handsZoomIn: false);
  v9 = v5->presentable;
  if ( v9 != nullptr )
  {
    v10 = (int)v9->GetPlayerInterface_2(this: v9);
    v11 = v10;
    if ( v10 != 0 )
    {
      v12 = (idView *)(v10 + 16224);
      if ( v10 != -16224 )
        *(_BYTE *)(v10 + 19040) = 0;
      goto LABEL_14;
    }
  }
  else
  {
    v11 = 0;
  }
  v12 = nullptr;
LABEL_14:
  this->returningToPlayer = false;
  this->movingToAI = true;
  idPlayer::AddControl(this: v5, entity: this);
  v5->Hide_2(this: v5);
  if ( this->targets.num > 0 )
  {
    value = this->targets.list->spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v14 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v14 != nullptr )
        v7 = (idActor *)idEntity::CastTo(c: v14);
    }
  }
  if ( v7 != nullptr )
  {
    Physics = idEntity::GetPhysics(this: v7);
    v16 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v17 = *(float *)(v16 + 4);
    v18 = *(float *)(v16 + 8);
    v43.mat[1].y = *(float *)v16;
    v43.mat[1].z = v17;
    v43.mat[2].x = v18;
    if ( (unsigned __int8)idActor::IsTypeOf(c: v7) != 0 )
    {
      v19 = idActor::CastTo(c: v7);
      v19->GetLastEyePos(this: v19, a2: (idVec3 *)&v43.mat[1].y);
    }
    v20 = idEntity::GetPhysics(this);
    v21 = (float)(this->targetOffset.x + v43.mat[1].y);
    v22 = (float)(this->targetOffset.y + v43.mat[1].z);
    v23 = (float)(this->targetOffset.z + v43.mat[2].x);
    v24 = (float *)v20->GetOrigin(this: v20, a2: 0);
    v25 = (float)((float)v23 - v24[2]);
    v26 = (float)((float)v22 - v24[1]);
    v46.x = (float)v21 - *v24;
    v46.z = v25;
    v46.y = v26;
    idVec3::NormalizeFast(this: &v46);
    v27 = idVec3::ToAngles(this: v43.mat, result: (idAngles *)&v46);
  }
  else
  {
    idLib::Warning(fmt: "Missing camera target for '%s'", this->name.data);
    v28 = idEntity::GetPhysics(this);
    v29 = (idAngles *)v28->GetAxis(this: v28, a2: 0);
    v27 = idMat3::ToAngles(this: &v43, result: v29);
  }
  roll = v27->roll;
  yaw = v27->yaw;
  pitch = v27->pitch;
  if ( this->lerpInTime <= 0 )
  {
    idLib::Warning(fmt: "Invalid lerpInTime on '%s'", this->name.data);
    this->lerpInTime = 1000;
  }
  if ( this->lerpOutTime <= 0 )
  {
    idLib::Warning(fmt: "Invalid lerpOutTime on '%s'", this->name.data);
    this->lerpOutTime = 100;
  }
  if ( this->lerpSwitchTime <= 0 )
  {
    idLib::Warning(fmt: "Invalid lerpSwitchTime on '%s'", this->name.data);
    this->lerpSwitchTime = 100;
  }
  this->lerpTime = this->lerpInTime;
  this->startTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  this->startFov = g_fov.valueFloat;
  v5->GetViewTransform(this: v5, a2: (idVec3 *)&v43.mat[2].z, a3: (idMat3 *)&v48);
  if ( v12 != nullptr )
  {
    idView::GetViewPos(this: v12, origin: &v47, axis: &v55);
    v43.mat[2].z = v47.x;
    y = v47.y;
    z = v47.z;
    v48.pitch = v55.mat[0].x;
    v48.yaw = v55.mat[0].y;
    v48.roll = v55.mat[0].z;
    x = v55.mat[1].x;
    v50 = v55.mat[1].y;
    v51 = v55.mat[1].z;
    v52 = v55.mat[2].x;
    v53 = v55.mat[2].y;
    v54 = v55.mat[2].z;
  }
  v33 = v43.mat[2].z;
  v34 = y;
  v35 = z;
  this->startPos.x = v43.mat[2].z;
  this->startPos.y = v34;
  this->startPos.z = v35;
  this->returnToPos.x = v33;
  this->returnToPos.y = this->startPos.y;
  this->returnToPos.z = this->startPos.z;
  v36 = (idPhysics_Player *)idEntity::GetPhysics(this: v5);
  if ( v36 != nullptr && (unsigned __int8)idPhysics_Player::IsCrouching(this: v36) != 0 && v11 != 0 )
  {
    LODWORD(v37) = pm_normalviewheight.valueInteger - pm_crouchviewheight.valueInteger;
    *(_QWORD *)&v43.mat[0].x = v37;
    this->returnToPos.z = (float)((float)v37 - idBobCycle::GetCrouchDecay(this: (idBobCycle *)(v11 + 45664)))
                        + this->returnToPos.z;
  }
  this->startAngles = *idMat3::ToAngles(this: &v43, result: &v48);
  v38 = idEntity::GetPhysics(this);
  v39 = (float *)v38->GetOrigin(this: v38, a2: 0);
  this->destPos.x = *v39;
  this->destPos.y = v39[1];
  this->destPos.z = v39[2];
  v40 = this->targetAnglesOffset.yaw;
  v41 = (float)(this->targetAnglesOffset.roll + (float)roll);
  this->destAngles.pitch = this->targetAnglesOffset.pitch + (float)pitch;
  this->destAngles.yaw = (float)v40 + (float)yaw;
  this->destAngles.roll = v41;
  idEntity::BecomeActive(this, flags: 1);
  return 1;
}


// ========================================================================
// ?Event_InteractActivate@idInteractionCamera@@QAA?AVeventVoid@@PAVidEntity@@0@Z
// EA  : 0x82D14418
// RVA : 0x00D14418
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idInteractionCamera *__fastcall idInteractionCamera::Event_InteractActivate(
        idInteractionCamera *this,
        eventVoid *result,
        idEntity *activator_,
        idAI2 *aitarget)
{
  idAI2 *v8; // r3
  idEntityPtr<idInteractionCamera> *p_interactionCamera; // r9

  v8 = idAI2::CastTo(c: aitarget);
  if ( aitarget != nullptr )
  {
    if ( v8 != nullptr )
      *(_DWORD *)&result[936] = (gameLocal->spawnIds.ptr[v8->entityNumber] << 13) | v8->entityNumber;
    else
      *(_DWORD *)&result[936] = 0x1FFF;
    p_interactionCamera = &v8->aiVolatile.memory.interactionCamera;
    if ( result != nullptr )
      p_interactionCamera->spawnId.value = (gameLocal->spawnIds.ptr[*(_DWORD *)&result[492]] << 13)
                                         | *(_DWORD *)&result[492];
    else
      p_interactionCamera->spawnId.value = 0x1FFF;
    (*(void (__fastcall **)(eventVoid *, idEntity *))(*(_DWORD *)result + 616))(a1: result, a2: activator_);
    return this;
  }
  else
  {
    idLib::Warning(
      fmt: "non ai target to idInteractionCamera::Event_InteractActivate on %s",
      *(const char **)&result[16]);
    return this;
  }
}


// ========================================================================
// ?InternalActivate@idUtilityCamera@@UAA_NPAVidEntity@@@Z
// EA  : 0x82D144F8
// RVA : 0x00D144F8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idUtilityCamera::InternalActivate(idUtilityCamera *this, idEntity *activator_)
{
  if ( activator_ != nullptr )
    this->activator.spawnId.value = (gameLocal->spawnIds.ptr[activator_->entityNumber] << 13) | activator_->entityNumber;
  else
    this->activator.spawnId.value = 0x1FFF;
  this->numFrames = 0;
  idEntity::BecomeActive(this, flags: 1);
  return 1;
}


// ========================================================================
// ?Think@idRotatableCamera@@UAAXXZ
// EA  : 0x82D14560
// RVA : 0x00D14560
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idRotatableCamera::Think(idRotatableCamera *this)
{
  idPlayer *PlayerActivator; // r3
  idPlayer *v3; // r29
  idPresentable *presentable; // r3
  int v5; // r3
  int value; // r9
  int v7; // r30
  idCamera *v8; // r3
  idCamera *v9; // r3
  int UCmdTracker2; // r30
  int v11; // r3
  int GameMs; // r27
  int v13; // r28
  idPhysics *Physics; // r3
  float *v15; // r3
  double x; // fp0
  float v17; // r8
  float v18; // r7
  double v19; // fp31
  double v20; // fp29
  double v21; // fp30
  char v22; // r11
  double v23; // fp9
  idPhysics *v24; // r3
  idQuat *v25; // r3
  idQuat *v26; // r3
  idPhysics *v27; // r3
  idQuat *v28; // r3
  float y; // r9
  float z; // r8
  float w; // r7
  double suppressMovement; // fp13
  double v33; // fp10
  double v34; // fp3
  double v35; // fp4
  double v36; // fp2
  double v37; // fp13
  double v38; // fp10
  double v39; // fp12
  double v40; // fp9
  double v41; // fp11
  double v42; // fp8
  double reactionToMovementSpeed; // fp0
  double v44; // fp7
  idAngles *p_currentReactionAngles; // r11
  double v46; // fp1
  double v47; // fp8
  double v48; // fp4
  double v49; // fp3
  double turnToGoalSpeed; // fp11
  double v51; // fp12
  double v52; // fp10
  double v53; // fp0
  idAngles *p_currentTurningAngles; // r10
  double v55; // fp7
  double v56; // fp4
  double v57; // fp2
  double v58; // fp1
  double v59; // fp0
  double roll; // fp11
  double pitch; // fp10
  double v62; // fp3
  double v63; // fp2
  double v64; // fp13
  double v65; // fp0
  double v66; // fp6
  double v67; // fp3
  double v68; // fp1
  const idMat3 *v69; // r3
  idPhysics *v70; // r3
  float *v71; // r3
  idQuat v72; // [sp+50h] [-100h] BYREF
  idMat3 v73; // [sp+60h] [-F0h] BYREF
  float v74; // [sp+84h] [-CCh]
  float v75; // [sp+88h] [-C8h]
  idAngles v76; // [sp+90h] [-C0h] BYREF
  float v77; // [sp+9Ch] [-B4h]
  idVec3 v78[4]; // [sp+A0h] [-B0h] BYREF
  idQuat v79; // [sp+D0h] [-80h] BYREF

  PlayerActivator = idCamera::GetPlayerActivator(this);
  v3 = PlayerActivator;
  if ( PlayerActivator != nullptr )
  {
    presentable = PlayerActivator->presentable;
    v5 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
    value = v3->controlledCameraEntity.spawnId.value;
    v7 = *(unsigned __int8 *)(v5 + 46321) >> 7;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v8 = (idCamera *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v9 = idCamera::CastTo(c: v8);
    }
    else
    {
      v9 = nullptr;
    }
    if ( __PAIR64__(v9 != nullptr, (unsigned __int8)v7) == 0 )
    {
      UCmdTracker2 = idPlayer::GetUCmdTracker2(this: v3);
      v11 = idPlayer::GetUCmdTracker2(this: v3);
      this->HandleUserCmds(this, a2: (const usercmd_t *)(v11 + 8), a3: (const usercmd_t *)(UCmdTracker2 + 68));
    }
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v13 = GameMs - this->previousThinkTime;
  if ( v13 > 0 )
  {
    Physics = idEntity::GetPhysics(this);
    v15 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    x = this->lastPosition.x;
    v17 = v15[1];
    v18 = v15[2];
    v72.x = *v15;
    v19 = v72.x;
    v72.y = v17;
    v20 = v17;
    v72.z = v18;
    v21 = v18;
    if ( v72.x != x || v20 != this->lastPosition.y || (v22 = 1, v21 != this->lastPosition.z) )
      v22 = 0;
    if ( v22 == 0 )
    {
      v23 = (float)(v18 - this->lastPosition.z);
      v73.mat[1].z = v17 - this->lastPosition.y;
      v73.mat[1].y = v72.x - (float)x;
      v73.mat[2].x = v23;
      if ( idVec3::NormalizeFast(this: (idVec3 *)&v73.mat[1].y) <= 128.0 )
      {
        v26 = (idQuat *)idVec3::ToMat3(this: v78, result: (idMat3 *)&v73.mat[1].y);
        this->lastMoveAxis = *idMat3::ToQuat(this: &v73, result: v26);
        if ( this->suppressMovement != 0.0 )
        {
          v27 = idEntity::GetPhysics(this);
          v28 = (idQuat *)v27->GetAxis(this: v27, a2: 0);
          idMat3::ToQuat(this: &v73, result: v28);
          idQuat::Slerp(
            this: &this->lastMoveAxis,
            from: &this->lastMoveAxis,
            to: (const idQuat *)&v73,
            t: (float)((this->suppressMovement - 0.25) * 2.0));
        }
      }
      else
      {
        this->suppressMovement = 1.0;
        v24 = idEntity::GetPhysics(this);
        v25 = (idQuat *)v24->GetAxis(this: v24, a2: 0);
        this->lastMoveAxis = *idMat3::ToQuat(this: &v73, result: v25);
      }
      this->lastPosition.x = v19;
      this->lastPosition.y = v20;
      this->lastPosition.z = v21;
    }
    y = this->averageAxis.y;
    z = this->averageAxis.z;
    w = this->averageAxis.w;
    suppressMovement = this->suppressMovement;
    v72.x = this->averageAxis.x;
    v72.y = y;
    v72.z = z;
    v72.w = w;
    idQuat::Slerp(
      this: &this->averageAxis,
      from: &this->averageAxis,
      to: &this->lastMoveAxis,
      t: (float)((float)suppressMovement + (float)0.025));
    if ( this->doesCameraReactToMovement && v13 <= 100 )
    {
      idQuat::Inverse(this: (idQuat *)&v73, result: &v72);
      v33 = this->averageAxis.y;
      v34 = this->averageAxis.z;
      v35 = (float)((float)(this->averageAxis.w * v73.mat[0].z)
                  + (float)((float)(this->averageAxis.z * v73.mat[1].x) + (float)(this->averageAxis.x * v73.mat[0].y)));
      v36 = (float)-(float)((float)(this->averageAxis.y * v73.mat[0].y)
                          - (float)((float)(this->averageAxis.w * v73.mat[1].x)
                                  - (float)(this->averageAxis.x * v73.mat[0].x)));
      v37 = (float)-(float)((float)(this->averageAxis.x * v73.mat[0].z)
                          - (float)((float)(this->averageAxis.z * v73.mat[0].x)
                                  + (float)((float)(this->averageAxis.w * v73.mat[0].y)
                                          + (float)(this->averageAxis.y * v73.mat[1].x))));
      v76.pitch = -(float)((float)(this->averageAxis.z * v73.mat[0].y)
                         - (float)((float)(this->averageAxis.w * v73.mat[0].x)
                                 + (float)((float)(this->averageAxis.x * v73.mat[1].x)
                                         + (float)(this->averageAxis.y * v73.mat[0].z))));
      v76.yaw = v37;
      v76.roll = -(float)((float)((float)v33 * v73.mat[0].x) - (float)v35);
      v77 = -(float)((float)((float)v34 * v73.mat[0].z) - (float)v36);
      idQuat::ToAngles(this: &v72, result: &v76);
      v38 = v72.x;
      v39 = (float)(this->currentReactionAngles.yaw * (float)0.022);
      v40 = v72.y;
      v41 = (float)((float)(this->reactionToMovement.pitch * (float)45.0) * v72.x);
      v42 = (float)((float)(this->reactionToMovement.yaw * (float)45.0) * v72.y);
      reactionToMovementSpeed = this->reactionToMovementSpeed;
      v44 = (float)((float)(this->reactionToMovement.roll * (float)45.0)
                  * (float)(this->currentReactionAngles.yaw * (float)0.022));
      if ( reactionToMovementSpeed >= 0.000099999997 )
      {
        if ( reactionToMovementSpeed > 0.99989998 )
          this->reactionToMovementSpeed = 0.99989998;
      }
      else
      {
        this->reactionToMovementSpeed = 0.000099999997;
      }
      p_currentReactionAngles = &this->currentReactionAngles;
      v46 = (float)(this->reactionToMovementSpeed * (float)v42);
      v47 = (float)(this->reactionToMovementSpeed * (float)v44);
      v48 = (float)((float)((float)1.0 - this->reactionToMovementSpeed) * this->currentReactionAngles.yaw);
      v49 = (float)((float)((float)1.0 - this->reactionToMovementSpeed) * this->currentReactionAngles.roll);
      this->currentReactionAngles.pitch = (float)((float)((float)1.0 - this->reactionToMovementSpeed)
                                                * this->currentReactionAngles.pitch)
                                        + (float)(this->reactionToMovementSpeed * (float)v41);
      this->currentReactionAngles.yaw = (float)v48 + (float)v46;
      this->currentReactionAngles.roll = (float)v49 + (float)v47;
      turnToGoalSpeed = this->turnToGoalSpeed;
      v51 = (float)((float)(this->goalForTurning.roll * (float)95.0) * (float)v39);
      v52 = (float)((float)(this->goalForTurning.pitch * (float)95.0) * (float)v38);
      v53 = (float)((float)(this->goalForTurning.yaw * (float)95.0) * (float)v40);
      if ( turnToGoalSpeed >= 0.000099999997 )
      {
        if ( turnToGoalSpeed > 0.99989998 )
          this->turnToGoalSpeed = 0.99989998;
      }
      else
      {
        this->turnToGoalSpeed = 0.000099999997;
      }
      p_currentTurningAngles = &this->currentTurningAngles;
      v55 = (float)(this->turnToGoalSpeed * (float)v53);
      v56 = (float)(this->turnToGoalSpeed * (float)v51);
      v57 = (float)(this->currentTurningAngles.yaw * (float)((float)1.0 - this->turnToGoalSpeed));
      v58 = (float)(this->currentTurningAngles.roll * (float)((float)1.0 - this->turnToGoalSpeed));
      this->currentTurningAngles.pitch = (float)((float)((float)1.0 - this->turnToGoalSpeed)
                                               * this->currentTurningAngles.pitch)
                                       + (float)(this->turnToGoalSpeed * (float)v52);
      this->currentTurningAngles.yaw = (float)v57 + (float)v55;
      this->currentTurningAngles.roll = (float)v58 + (float)v56;
      v59 = this->suppressMovement;
      if ( v59 != 0.0 )
      {
        if ( v59 <= 0.75 )
        {
          roll = this->currentReactionAngles.roll;
          pitch = p_currentReactionAngles->pitch;
          this->currentReactionAngles.yaw = (float)-(float)((float)(this->suppressMovement * (float)1.3333334)
                                                          - (float)1.0)
                                          * this->currentReactionAngles.yaw;
          this->currentReactionAngles.roll = (float)-(float)((float)((float)v59 * (float)1.3333334) - (float)1.0)
                                           * (float)roll;
          p_currentReactionAngles->pitch = (float)-(float)((float)((float)v59 * (float)1.3333334) - (float)1.0)
                                         * (float)pitch;
          v62 = (float)-(float)((float)(this->suppressMovement * (float)1.3333334) - (float)1.0);
          v63 = this->currentTurningAngles.roll;
          v64 = (float)(this->currentTurningAngles.yaw
                      * (float)-(float)((float)(this->suppressMovement * (float)1.3333334) - (float)1.0));
          p_currentTurningAngles->pitch = (float)-(float)((float)(this->suppressMovement * (float)1.3333334) - (float)1.0)
                                        * p_currentTurningAngles->pitch;
          this->currentTurningAngles.yaw = v64;
          this->currentTurningAngles.roll = (float)v63 * (float)v62;
        }
        else
        {
          this->currentReactionAngles.roll = 0.0;
          this->currentReactionAngles.yaw = 0.0;
          p_currentReactionAngles->pitch = 0.0;
          this->currentTurningAngles.roll = 0.0;
          this->currentTurningAngles.yaw = 0.0;
          p_currentTurningAngles->pitch = 0.0;
        }
      }
      v65 = this->suppressMovement;
      if ( v65 != 0.0 )
      {
        if ( v65 <= 0.025 )
          this->suppressMovement = 0.0;
        else
          this->suppressMovement = this->suppressMovement - 0.025;
      }
    }
    this->previousThinkTime = GameMs;
  }
  v66 = (float)(this->currentUserAngles.roll + this->currentReactionAngles.roll);
  v67 = this->currentTurningAngles.roll;
  v68 = (float)(this->currentTurningAngles.yaw + (float)(this->currentUserAngles.yaw + this->currentReactionAngles.yaw));
  v73.mat[2].z = (float)(this->currentUserAngles.pitch + this->currentReactionAngles.pitch)
               + this->currentTurningAngles.pitch;
  v74 = v68;
  v75 = (float)v67 + (float)v66;
  this->cameraAxis = *idAngles::ToMat3(this: (idAngles *)v78, result: (idMat3 *)&v73.mat[2].z);
  v69 = idQuat::ToMat3(this: &v79, result: (idMat3 *)&this->averageAxis);
  idMat3::operator*=(this: &this->cameraAxis, a: v69);
  v70 = idEntity::GetPhysics(this);
  v71 = (float *)v70->GetOrigin(this: v70, a2: 0);
  this->cachedViewOrg.x = *v71;
  this->cachedViewOrg.y = v71[1];
  this->cachedViewOrg.z = v71[2];
  this->cachedViewAxis.mat[0].x = this->cameraAxis.mat[0].x;
  this->cachedViewAxis.mat[0].y = this->cameraAxis.mat[0].y;
  this->cachedViewAxis.mat[0].z = this->cameraAxis.mat[0].z;
  this->cachedViewAxis.mat[1].x = this->cameraAxis.mat[1].x;
  this->cachedViewAxis.mat[1].y = this->cameraAxis.mat[1].y;
  this->cachedViewAxis.mat[1].z = this->cameraAxis.mat[1].z;
  this->cachedViewAxis.mat[2].x = this->cameraAxis.mat[2].x;
  this->cachedViewAxis.mat[2].y = this->cameraAxis.mat[2].y;
  this->cachedViewAxis.mat[2].z = this->cameraAxis.mat[2].z;
}


// ========================================================================
// ?InternalActivate@idRotatableCamera@@UAA_NPAVidEntity@@@Z
// EA  : 0x82D14C78
// RVA : 0x00D14C78
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idRotatableCamera::InternalActivate(idRotatableCamera *this, idPlayer *activator_)
{
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  idPlayer *Player; // r3
  idEntity *v8; // r30
  idClientGame *v9; // r11
  idPhysics *Physics; // r3
  float *v11; // r3
  idPhysics *v12; // r3
  idQuat *v13; // r3
  idQuat *v14; // r3
  double x; // fp8
  int v16; // r8
  idPhysics *v17; // r3
  float *v18; // r3
  idPhysics *v19; // r28
  idPhysics *v20; // r3
  int v21; // r3
  va *v23; // r3
  __int64 v24; // r6
  va *v25; // r3
  int v26; // [sp+8h] [-1088h]
  int v27; // [sp+Ch] [-1084h]
  int v28; // [sp+10h] [-1080h]
  int v29; // [sp+14h] [-107Ch]
  int v30; // [sp+18h] [-1078h]
  int v31; // [sp+1Ch] [-1074h]
  idMat3 v32; // [sp+50h] [-1040h] BYREF

  if ( this->isActive )
    return 1;
  if ( (*((_BYTE *)this + 1028) & 0x20) != 0 )
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  else
    Player = idPlayer::CastTo(c: activator_);
  v8 = Player;
  if ( Player != nullptr )
  {
    this->currentUserAngles.pitch = this->startingAngles.pitch;
    this->currentUserAngles.yaw = this->startingAngles.yaw;
    v9 = clientGame;
    this->currentUserAngles.roll = this->startingAngles.roll;
    this->currentReactionAngles.roll = 0.0;
    this->currentReactionAngles.yaw = 0.0;
    this->currentReactionAngles.pitch = 0.0;
    this->currentTurningAngles.roll = 0.0;
    this->currentTurningAngles.yaw = 0.0;
    this->currentTurningAngles.pitch = 0.0;
    this->previousThinkTime = idGameTimeManager::GetGameMs(this: &v9->gameTimeManager, type: GAMETIME_SCALED);
    Physics = idEntity::GetPhysics(this);
    v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    this->lastPosition.x = *v11;
    this->lastPosition.y = v11[1];
    this->lastPosition.z = v11[2];
    v12 = idEntity::GetPhysics(this);
    v13 = (idQuat *)v12->GetAxis(this: v12, a2: 0);
    v14 = idMat3::ToQuat(this: &v32, result: v13);
    x = v14->x;
    this->averageAxis = *v14;
    this->lastMoveAxis.x = x;
    this->lastMoveAxis.y = this->averageAxis.y;
    this->lastMoveAxis.z = this->averageAxis.z;
    this->lastMoveAxis.w = this->averageAxis.w;
    v16 = *((_BYTE *)this + 1028) & 0x80;
    this->suppressMovement = 1.0;
    if ( v16 != 0 )
    {
      v17 = idEntity::GetPhysics(this: v8);
      v18 = (float *)v17->GetOrigin(this: v17, a2: 0);
      this->playerStartPos.x = *v18;
      this->playerStartPos.y = v18[1];
      this->playerStartPos.z = v18[2];
      v19 = idEntity::GetPhysics(this: v8);
      v20 = idEntity::GetPhysics(this);
      v21 = (int)v20->GetOrigin(this: v20, a2: 0);
      v19->SetOrigin(this: v19, a2: (const idVec3 *)v21, a3: -1);
      idEntity::Bind(this: v8, master: (idWorldspawn *)this, orientated: false);
      v8->Hide_2(this: v8);
      this->playerWasNoTarget = (v8[16].name.baseBuffer[0] & 8) != 0;
      v8[16].name.baseBuffer[0] |= 8u;
    }
    idEntity::BecomeActive(this, flags: 1);
    this->isActive = true;
    this->activator.spawnId.value = (gameLocal->spawnIds.ptr[v8->entityNumber] << 13) | v8->entityNumber;
    return 1;
  }
  LODWORD(v4) = *((_BYTE *)this + 1028) & 0x20;
  if ( (*((_BYTE *)this + 1028) & 0x20) != 0 )
  {
    HIDWORD(v6) = this->name.data;
    v23 = va::va(
            this: (va *)&v32.mat[1].y,
            fmt: "idRotatableCamera '%s' couldn't find any player to bind from local player list",
            a3: v6,
            a4: v5,
            a5: v4,
            a6: v26,
            a7: v27,
            a8: v28,
            a9: v29,
            a10: v30,
            a11: v31);
    idLib::Warning(fmt: v23->buffer);
    this->activator.spawnId.value = 0x1FFF;
    return 0;
  }
  else
  {
    if ( activator_ != nullptr )
      LODWORD(v24) = activator_->name.data;
    else
      LODWORD(v24) = "<NULL>";
    HIDWORD(v24) = this->name.data;
    v25 = va::va(
            this: (va *)&v32.mat[1].y,
            fmt: "idRotatableCamera '%s' couldn't bind entity '%s' because it was not a player",
            a3: v24,
            a4: v5,
            a5: v4,
            a6: v26,
            a7: v27,
            a8: v28,
            a9: v29,
            a10: v30,
            a11: v31);
    idLib::Warning(fmt: v25->buffer);
    this->activator.spawnId.value = 0x1FFF;
    return 0;
  }
}


// ========================================================================
// ?trailerCameraSpawn_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D14F60
// RVA : 0x00D14F60
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall trailerCameraSpawn_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idEntity *v2; // r30
  idCamera *Control; // r3
  idCamera *v4; // r3
  idCamera *v5; // r31
  idCamera *v6; // r3
  idCamera *v7; // r31
  idVec3 v8; // [sp+50h] [-60h] BYREF
  _BYTE v9[80]; // [sp+60h] [-50h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v2 = DebugPlayer;
  if ( DebugPlayer != nullptr )
  {
    Control = (idCamera *)idPlayer::GetControl(this: DebugPlayer);
    v4 = idCamera::CastTo(c: Control);
    v5 = v4;
    if ( v4 != nullptr )
    {
      idCamera::Deactivate(this: v4);
      ((void (__fastcall *)(idCamera *, int))v5->dtr_idClass)(a1: v5, a2: 1);
    }
    else
    {
      v6 = (idCamera *)idGameLocal::SpawnEntityType(
                         this: gameLocal,
                         typeInfo: &idTrailerCamera::Type,
                         forceEntityNumber: -1,
                         _model: nullptr);
      v7 = idCamera::CastTo(c: v6);
      if ( v7 != nullptr )
      {
        ((void (__fastcall *)(idEntity *, idVec3 *, _BYTE *))v2->__vftable[1].PauseThink)(a1: v2, a2: &v8, a3: v9);
        idEntity::SetOrigin(this: v7, org: &v8);
        v7->SetAxis(this: v7, a2: (const idMat3 *)v9);
        idCamera::Activate(this: v7, activator_: v2);
      }
    }
  }
}


// ========================================================================
// ?InternalActivate@idTrailerCamera@@UAA_NPAVidEntity@@@Z
// EA  : 0x82D15038
// RVA : 0x00D15038
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idTrailerCamera::InternalActivate(idTrailerCamera *this, idEntity *activator_)
{
  idPlayer *PlayerActivator; // r29
  int UCmdTracker2; // r3

  if ( gameLocal->spawnIds.ptr[this->activator.spawnId.value & 0x1FFF] != this->activator.spawnId.value >> 13 )
    return 0;
  if ( activator_ != nullptr )
    this->activator.spawnId.value = (gameLocal->spawnIds.ptr[activator_->entityNumber] << 13) | activator_->entityNumber;
  else
    this->activator.spawnId.value = 0x1FFF;
  PlayerActivator = idCamera::GetPlayerActivator(this);
  if ( PlayerActivator != nullptr )
  {
    this->SetTargetEntity(this, a2: activator_);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "hands_show", a3: false, a4: 0);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "g_showHud", a3: false, a4: 0);
    UCmdTracker2 = idPlayer::GetUCmdTracker2(this: PlayerActivator);
    memcpy(Dst: &this->prevCmd, Src: (const void *)(UCmdTracker2 + 8), Size: sizeof(this->prevCmd));
  }
  this->numFrames = 0;
  return 1;
}


// ========================================================================
// ?InternalDeactivate@idTrailerCamera@@UAA_NXZ
// EA  : 0x82D15158
// RVA : 0x00D15158
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idTrailerCamera::InternalDeactivate(idTrailerCamera *this)
{
  this->activator.spawnId.value = 0x1FFF;
  cvarSystem->SetCVarBool(this: cvarSystem, a2: "hands_show", a3: true, a4: 0);
  cvarSystem->SetCVarBool(this: cvarSystem, a2: "g_showHud", a3: true, a4: 0);
  return 1;
}


// ========================================================================
// ?InternalActivate@idTownGarageCamera@@MAA_NPAVidEntity@@@Z
// EA  : 0x82D151D8
// RVA : 0x00D151D8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idTownGarageCamera::InternalActivate(idTownGarageCamera *this, idPlayer *activator_)
{
  idPlayer *v4; // r28
  char *data; // r4
  int value; // r9
  idEntity *v8; // r3
  idTownGarageManager *v9; // r3
  idTownGarageManager *v10; // r3
  idTownGarageManager *garageManager; // r3
  idEventArg *v12; // r3
  idPresentable *presentable; // r3
  int v14; // r3
  idPresentable *v15; // r3
  int v16; // r3
  idTownGarageManager *v17; // r3
  const idSoundShader *cantEnterSound; // r5
  idVec4 v19; // [sp+50h] [-50h] BYREF
  idEventArg v20[3]; // [sp+60h] [-40h] BYREF

  v4 = idPlayer::CastTo(c: activator_);
  if ( v4 != nullptr )
  {
    if ( this->targets.num > 0
      && (value = this->targets.list->spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
      && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v9 = (idTownGarageManager *)idEntity::CastTo(c: v8);
    }
    else
    {
      v9 = nullptr;
    }
    v10 = idTownGarageManager::CastTo(c: v9);
    this->garageManager = v10;
    if ( v10 == nullptr )
    {
      idLib::Warning(fmt: "NO GARAGEMANAGER TARGET IN idTownGarageCamera");
      this->activator.spawnId.value = 0x1FFF;
      return 0;
    }
    if ( !idTownGarageManager::ProperSetup(this: v10) )
    {
      idLib::Warning(fmt: "NO GARAGEMANAGER has invalid data");
      this->activator.spawnId.value = 0x1FFF;
      return 0;
    }
    garageManager = this->garageManager;
    if ( !garageManager->spawnCalled )
    {
      v12 = idEventArg::idEventArg(this: v20, data: activator_);
      idEventReceiver::PostEventMS(
        this,
        ev: &EV_Activate,
        time: *(_DWORD *)&v12->type,
        arg1: (const idEventArg *)LODWORD(v12->value.v[1]));
      this->activator.spawnId.value = 0x1FFF;
      return 0;
    }
    if ( (unsigned __int8)idTownGarageManager::SetUpVehiclesForView(this: garageManager) != 0 )
    {
      if ( activator_ != nullptr )
        this->activator.spawnId.value = (gameLocal->spawnIds.ptr[activator_->entityNumber] << 13)
                                      | activator_->entityNumber;
      else
        this->activator.spawnId.value = 0x1FFF;
      idPlayer::AddControl(this: v4, entity: this);
      this->gui = idPlayer::EnterPersonalGarage(this: v4, camera: this);
      this->activatedTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      presentable = v4->presentable;
      if ( presentable != nullptr )
        v14 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v14 = 0;
      *(idColor *)(v14 + 19068) = idColor::colorBlack;
      v19.x = 0.0;
      v19.y = 0.0;
      v19.z = 0.0;
      v19.w = 0.0;
      v15 = v4->presentable;
      if ( v15 != nullptr )
        v16 = (int)v15->GetPlayerInterface_2(this: v15);
      else
        v16 = 0;
      idView::Fade(this: (idView *)(v16 + 16224), color: &v19, time: 1000);
      return 1;
    }
    else
    {
      v17 = this->garageManager;
      if ( v17->vehicles.num != 0 )
      {
        idLib::Warning(fmt: "error in activating garage camera");
      }
      else
      {
        cantEnterSound = v17->cantEnterSound;
        if ( cantEnterSound != nullptr )
        {
          idEntity::StartSoundShader(
            this: v17,
            channel: SND_CHANNEL_ANY,
            shader: cantEnterSound,
            soundShaderFlags: (soundShaderFlags_t)0,
            peerMask: 0xFFu);
          this->activator.spawnId.value = 0x1FFF;
          return 0;
        }
      }
      this->activator.spawnId.value = 0x1FFF;
      return 0;
    }
  }
  else
  {
    if ( activator_ != nullptr )
      data = activator_->name.data;
    else
      data = "null";
    idLib::Warning(fmt: "Invalid activator '%s' for '%s'", data, this->name.data);
    this->activator.spawnId.value = 0x1FFF;
    return 0;
  }
}


// ========================================================================
// ?InitStates@idCinematicCamera@@QAAXXZ
// EA  : 0x82D15670
// RVA : 0x00D15670
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idCinematicCamera::InitStates(idCinematicCamera *this)
{
  double v2; // fp1
  int startTime; // r11
  idPhysics *Physics; // r3
  idPhysics *v5; // r3
  int v6; // [sp+54h] [-2Ch]

  this->startTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_NORMAL);
  v2 = idCinematicCamera::DetermineTotalTime(this);
  startTime = this->startTime;
  this->currentTime = startTime;
  this->lastThinkTime = startTime;
  v6 = (int)(float)((float)v2 * (float)1000.0);
  this->endTime = startTime + v6;
  this->totalTime = v6;
  Physics = idEntity::GetPhysics(this);
  this->current.movement.viewOrigin = *Physics->GetOrigin(this: Physics, a2: 0);
  v5 = idEntity::GetPhysics(this);
  this->current.focus.viewAxis = *v5->GetAxis(this: v5, a2: 0);
  this->current.renderParms.fogColor.r = 0.2;
  this->current.renderParms.fogColor.g = 0.43000001;
  this->current.renderParms.fogColor.b = 0.5;
  this->current.renderParms.fogColor.a = 0.0;
  this->current.timeScale.scale = 1.0;
  this->current.fovZoom.angle = 80.0;
  this->current.fovZoom.transTime = 0.0;
  this->current.depthOfField.blurStart = -1.0;
  this->current.renderParms.fogScale = 0.000049999999;
  idCinematicCamera::state_t::operator=(this: &this->previous, __that: &this->current);
  this->lastTrigTime = 0;
}


// ========================================================================
// ?InternalActivate@idCinematicCamera@@MAA_NPAVidEntity@@@Z
// EA  : 0x82D15840
// RVA : 0x00D15840
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idCinematicCamera::InternalActivate(idCinematicCamera *this, idEntity *activator_)
{
  idPlayer *PlayerActivator; // r28
  idPlayer *Player; // r3
  bool v7; // r3
  BOOL playerInvulnerableDuringCine; // r9
  idPresentable *presentable; // r3
  int v10; // r11
  idPhysics *Physics; // r3
  idPresentable *v12; // r3
  idPresentable *v13; // r3
  idPresentablePlayer *v14; // r3
  idPresentable *v15; // r3
  int v16; // r3
  int value; // r9
  idEntity *v18; // r3
  idEntity *v19; // r3
  idPresentable *v20; // r3
  int v21; // r3
  idPresentable *v22; // r3
  int v23; // r3
  idPresentable *v24; // r3
  int v25; // r3
  idSWFScriptFunction *v26; // r3
  idSWFScriptFunction *v27; // r4
  idSWFScriptFunction *v28; // r3
  idSWFScriptFunction *v29; // r4
  idSWFScriptFunction *v30; // r3
  idSWFScriptFunction *v31; // r4
  idSWFScriptFunction *v32; // r3
  idSWFScriptFunction *v33; // r4
  idSWFScriptVar v34; // [sp+58h] [-68h] BYREF
  idSWFScriptVar v35; // [sp+60h] [-60h] BYREF
  idSWFScriptVar v36; // [sp+68h] [-58h] BYREF
  idSWFScriptVar v37[10]; // [sp+70h] [-50h] BYREF

  if ( activator_ != nullptr )
    this->activator.spawnId.value = (gameLocal->spawnIds.ptr[activator_->entityNumber] << 13) | activator_->entityNumber;
  else
    this->activator.spawnId.value = 0x1FFF;
  if ( this->active && this->suspended && (unsigned __int8)idCamera::IsPlayerActivator(this) == 0 )
  {
    idCinematicCamera::Unsuspend(this);
    return 0;
  }
  this->active = true;
  if ( cine_captureFrames.valueInteger != 0 )
  {
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_fixedtic", a3: 1, a4: 0);
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_captureFrames", a3: 2, a4: 0);
  }
  idCinematicCamera::InitStates(this);
  PlayerActivator = idCamera::GetPlayerActivator(this);
  if ( PlayerActivator == nullptr )
  {
    if ( g_cameraPlayerHack.valueInteger == 0 )
    {
LABEL_14:
      idLib::Warning(fmt: "Could not find a valid player for camera activation");
      this->activator.spawnId.value = 0x1FFF;
      return 0;
    }
    if ( gameLocal == nullptr )
    {
      idLib::Warning(fmt: "no gamelocal for player hack");
      goto LABEL_14;
    }
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    PlayerActivator = Player;
    if ( Player == nullptr )
    {
      this->activator.spawnId.value = 0x1FFF;
      goto LABEL_14;
    }
    this->activator.spawnId.value = (gameLocal->spawnIds.ptr[Player->entityNumber] << 13) | Player->entityNumber;
  }
  v7 = PlayerActivator->TakesDamage(this: PlayerActivator);
  playerInvulnerableDuringCine = this->playerInvulnerableDuringCine;
  this->playerTakesDamageState = v7;
  if ( playerInvulnerableDuringCine )
    *(_BYTE *)&PlayerActivator->flags &= ~2u;
  presentable = PlayerActivator->presentable;
  if ( presentable != nullptr )
    v10 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v10 = 0;
  this->prevHudState = *(_DWORD *)(v10 + 35180);
  Physics = idEntity::GetPhysics(this: PlayerActivator);
  Physics->SetLinearVelocity(this: Physics, a2: &vec3_origin, a3: 0);
  v12 = PlayerActivator->presentable;
  if ( v12 != nullptr && v12->GetPlayerInterface_2(this: v12) != nullptr )
  {
    v13 = PlayerActivator->presentable;
    v14 = v13 != nullptr ? v13->GetPlayerInterface_2(this: v13) : nullptr;
    if ( idPresentablePlayer::GuiIsActive(this: v14, g: GUI_INVENTORY) )
    {
      v15 = PlayerActivator->presentable;
      if ( v15 != nullptr )
        v16 = (int)v15->GetPlayerInterface_2(this: v15);
      else
        v16 = 0;
      idView::ForceBlurValues(this: (idView *)(v16 + 16224), blurBegin: 2.5, blurEnd: 0.0, blurTime: 250.0);
    }
  }
  if ( activator_ != nullptr )
    this->activator.spawnId.value = (gameLocal->spawnIds.ptr[activator_->entityNumber] << 13) | activator_->entityNumber;
  else
    this->activator.spawnId.value = 0x1FFF;
  if ( this->hidePlayer )
  {
    value = this->activator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v18 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v19 = idEntity::CastTo(c: v18);
    }
    else
    {
      v19 = nullptr;
    }
    v19->Hide_2(this: v19);
  }
  v20 = PlayerActivator->presentable;
  if ( v20 != nullptr )
    v21 = (int)v20->GetPlayerInterface_2(this: v20);
  else
    v21 = 0;
  if ( v21 != -37616 && this->hidePlayerHands )
  {
    v22 = PlayerActivator->presentable;
    if ( v22 != nullptr )
      v23 = (int)v22->GetPlayerInterface_2(this: v22);
    else
      v23 = 0;
    idHands::Hide(this: (idHands *)(v23 + 37616), hideReason: HAND_HIDE_GENERIC);
    v24 = PlayerActivator->presentable;
    if ( v24 != nullptr )
      v25 = (int)v24->GetPlayerInterface_2(this: v24);
    else
      v25 = 0;
    idHands::UpdateHidden(this: (idHands *)(v25 + 37616));
  }
  if ( this->gui != nullptr )
  {
    v26 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0xCu,
                                   tag: TAG_SWF,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
    if ( v26 != nullptr )
    {
      v26[2].__vftable = (idSWFScriptFunction_vtbl *)this;
      v26[1].__vftable = nullptr;
      v27 = v26;
      v26->__vftable = (idSWFScriptFunction_vtbl *)&`idCinematicCamera::InternalActivate'::`37'::idSWFScriptFunction_UnsuspendCamera::`vftable';
    }
    else
    {
      v27 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: &v34, nf: v27);
    idSWFScriptObject::Set(this: this->gui->globals, name: "UnsuspendCamera", value: &v34);
    idSWFScriptVar::Free(this: &v34);
    v28 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0xCu,
                                   tag: TAG_SWF,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
    if ( v28 != nullptr )
    {
      v28[2].__vftable = (idSWFScriptFunction_vtbl *)this;
      v28[1].__vftable = nullptr;
      v29 = v28;
      v28->__vftable = (idSWFScriptFunction_vtbl *)&`idCinematicCamera::InternalActivate'::`38'::idSWFScriptFunction_QuitCamera::`vftable';
    }
    else
    {
      v29 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: &v35, nf: v29);
    idSWFScriptObject::Set(this: this->gui->globals, name: "QuitCamera", value: &v35);
    idSWFScriptVar::Free(this: &v35);
    v30 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0xCu,
                                   tag: TAG_SWF,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
    if ( v30 != nullptr )
    {
      v30[2].__vftable = (idSWFScriptFunction_vtbl *)this;
      v30[1].__vftable = nullptr;
      v31 = v30;
      v30->__vftable = (idSWFScriptFunction_vtbl *)&`idCinematicCamera::InternalActivate'::`39'::idSWFScriptFunction_GetNotificationFromCamera::`vftable';
    }
    else
    {
      v31 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: &v36, nf: v31);
    idSWFScriptObject::Set(this: this->gui->globals, name: "GetCameraNotification", value: &v36);
    idSWFScriptVar::Free(this: &v36);
    v32 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0xCu,
                                   tag: TAG_SWF,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
    if ( v32 != nullptr )
    {
      v32[2].__vftable = (idSWFScriptFunction_vtbl *)this;
      v32[1].__vftable = nullptr;
      v33 = v32;
      v32->__vftable = (idSWFScriptFunction_vtbl *)&`idCinematicCamera::InternalActivate'::`40'::idSWFScriptFunction_ClearCameraNotificaiton::`vftable';
    }
    else
    {
      v33 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: v37, nf: v33);
    idSWFScriptObject::Set(this: this->gui->globals, name: "ClearCameraNotification", value: v37);
    idSWFScriptVar::Free(this: v37);
    idSWF::Activate(this: this->gui, b: true);
  }
  return 1;
}


// ========================================================================
// __unwind$523060
// EA  : 0x82D15E3C
// RVA : 0x00D15E3C
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_523060()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$523062
// EA  : 0x82D15E64
// RVA : 0x00D15E64
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_523062()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$523064
// EA  : 0x82D15E8C
// RVA : 0x00D15E8C
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_523064()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 192 + 104));
}


// ========================================================================
// __unwind$523066
// EA  : 0x82D15EB4
// RVA : 0x00D15EB4
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_523066()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 192 + 112));
}


// ========================================================================
// `idCinematicCamera::InternalActivate'::`38'::idSWFScriptFunction_QuitCamera::Call
// EA  : 0x82D15EE0
// RVA : 0x00D15EE0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idCinematicCamera::InternalActivate_::_38_::idSWFScriptFunction_QuitCamera::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        __int64 parms,
        int a4,
        int a5,
        int a6)
{
  int v8; // [sp+8h] [-58h]
  __int64 v9; // [sp+10h] [-50h]
  __int64 v10; // [sp+18h] [-48h]
  __int64 v11; // [sp+20h] [-40h]
  __int64 v12; // [sp+28h] [-38h]
  __int64 v13; // [sp+30h] [-30h]

  *(float *)&parms = idColor::colorBlack.a;
  idCinematicCamera::CinematicDone(
    this: (idCinematicCamera *)LODWORD(idColor::colorBlack.r),
    color: parms,
    a3: a4,
    a4: a5,
    a5: a6,
    a6: (int)&idColor::colorBlack,
    a7: v8,
    a8: v9,
    a9: v10,
    a10: v11,
    a11: v12,
    a12: v13);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idCinematicCamera::InternalActivate'::`40'::idSWFScriptFunction_ClearCameraNotificaiton::Call
// EA  : 0x82D15F30
// RVA : 0x00D15F30
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idCinematicCamera::InternalActivate_::_40_::idSWFScriptFunction_ClearCameraNotificaiton::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int num; // r11

  num = thisObject->variables.num;
  result->type = SWF_VAR_UNDEF;
  *(_BYTE *)(num + 1031) = 0;
  return result;
}


// ========================================================================
// ?Draw@idSlowMotionCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D160B8
// RVA : 0x00D160B8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idSlowMotionCamera::Draw(idSlowMotionCamera *this, idPlayer *player, __int64 a3, long double a4)
{
  idPresentable *presentable; // r3
  int v7; // r3
  idDeclCameraTrigger::idTrigFovZoom *p_fovZoom; // r30
  idView *v9; // r28
  double TimeLerpFraction; // fp1
  double v11; // fp0
  double angle; // fp1
  __int64 v13; // r6
  long double v14; // fp2
  double v15; // fp13
  double v16; // fp12
  float *p_blurScale; // r10
  float *v18; // r11
  int i; // ctr
  double v20; // fp1
  double v21; // fp0
  double x; // fp13
  double y; // fp12
  double v24; // fp8
  double z; // fp11
  double v26; // fp6
  double v27; // fp5
  const idDeclRenderParm *depthOfField; // r4
  __int64 v29; // r9
  int fadeTime; // r11
  float v31; // r7
  __int16 *p_granularity; // r10
  int *p_startTimeOfs; // r11
  int v34; // ctr
  __int64 v35; // r6
  long double v36; // fp2
  double v37; // fp12
  idPhysics *Physics; // r3
  float *v39; // r3
  idPresentable *v40; // r3
  int v41; // r3
  idPlayerHud::hudState_t v42; // r4
  idPresentable *v43; // r3
  int v44; // r29
  idPresentable *v45; // r3
  int v46; // r3
  __int64 v47; // r6
  long double v48; // fp2
  idPresentable *v49; // r3
  int v50; // r30
  int v51; // r3
  const char *v52; // r7
  double v53; // fp31
  char v54; // r11
  double v55; // fp30
  double v56; // fp29
  double v57; // fp28
  double v58; // fp27
  const idDeclRenderParm *v59; // r3
  double v60; // fp31
  const idDeclRenderParm *v61; // r3
  double v63; // fp13
  double v64; // fp12
  double v65; // fp9
  double v66; // fp8
  double v67; // fp7
  double v68; // fp6
  double v69; // fp5
  double v70; // fp4
  double v71; // fp3
  parmValue_t v72; // [sp+50h] [-C0h] BYREF
  idVec3 v73; // [sp+60h] [-B0h] BYREF
  idParmBlock v74; // [sp+70h] [-A0h] BYREF
  float v75; // [sp+98h] [-78h]
  float v76; // [sp+9Ch] [-74h]
  float v77; // [sp+A0h] [-70h]

  presentable = player->presentable;
  if ( presentable != nullptr )
    v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v7 = 0;
  p_fovZoom = &this->current.fovZoom;
  v9 = (idView *)(v7 + 16224);
  if ( this->current.fovZoom.angle < 0.0 )
    idView::GetFOV(this: (idView *)(v7 + 16224), fov_x: &this->current.fovZoom.angle, fov_y: v72.value);
  if ( this->current.fovZoom.timing.duration == 0.0 )
  {
    angle = p_fovZoom->angle;
  }
  else
  {
    TimeLerpFraction = idSlowMotionCamera::GetTimeLerpFraction(this, timeLerpHelper: a3, a3: a4);
    v11 = TimeLerpFraction;
    if ( TimeLerpFraction >= 0.0 )
    {
      if ( TimeLerpFraction > 1.0 )
        v11 = 1.0;
      angle = (float)((float)((float)(p_fovZoom->angle - this->previous.fovZoom.angle) * (float)v11)
                    + this->previous.fovZoom.angle);
    }
    else
    {
      angle = (float)((float)((float)(p_fovZoom->angle - this->previous.fovZoom.angle) * (float)0.0)
                    + this->previous.fovZoom.angle);
    }
  }
  idView::CalcFOV(this: v9, base_fov: angle);
  if ( this->current.depthOfField.blurStart < 0.0 )
  {
    idParmBlock::GetVector(this: &v74, result: &v9->gameview.parmBlock, parm: rp->depthOfField);
    v15 = *(float *)&v74.ops.num;
    v16 = *(float *)&v74.ops.size;
    this->previous.depthOfField.vec.x = *(float *)&v74.ops.list;
    this->previous.depthOfField.vec.y = v15;
    this->previous.depthOfField.vec.z = v16;
    if ( this->current.depthOfField.timing.duration < 0.0 )
    {
      this->current.depthOfField.blurStart = this->previous.depthOfField.blurStart;
      p_blurScale = &this->current.depthOfField.blurScale;
      this->current.depthOfField.blurScale = this->previous.depthOfField.blurScale;
      v18 = &this->previous.depthOfField.blurScale;
      for ( i = 5; i != 0; --i )
        *++p_blurScale = *++v18;
      this->current.depthOfField.vec.x = this->previous.depthOfField.vec.x;
      this->current.depthOfField.vec.y = this->previous.depthOfField.vec.y;
      this->current.depthOfField.vec.z = this->previous.depthOfField.vec.z;
    }
  }
  if ( this->current.depthOfField.timing.duration >= 0.0 )
  {
    v20 = idSlowMotionCamera::GetTimeLerpFraction(this, timeLerpHelper: v13, a3: v14);
    v21 = v20;
    if ( v20 >= 0.0 )
    {
      if ( v20 > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    x = this->previous.depthOfField.vec.x;
    y = this->previous.depthOfField.vec.y;
    v24 = (float)(this->current.depthOfField.vec.x - this->previous.depthOfField.vec.x);
    z = this->previous.depthOfField.vec.z;
    v26 = (float)(this->current.depthOfField.vec.y - this->previous.depthOfField.vec.y);
    v27 = (float)(this->current.depthOfField.vec.z - this->previous.depthOfField.vec.z);
    v72.value[3] = 0.0;
    depthOfField = rp->depthOfField;
    v72.value[0] = (float)x + (float)((float)v24 * (float)v21);
    v72.value[1] = (float)y + (float)((float)v26 * (float)v21);
    v72.value[2] = (float)z + (float)((float)v27 * (float)v21);
    idParmBlock::SetParm(this: &v9->gameview.parmBlock, parm: depthOfField, parmValue: &v72);
  }
  if ( this->current.fade.activate )
  {
    v72.swizzle[1] = (int)(float)(this->current.fade.transTime * (float)1000.0);
    idView::Fade(this: v9, color: (const idVec4 *)&this->current.fade, time: v72.swizzle[1]);
    this->current.fade.activate = false;
  }
  if ( this->current.fade.timeScaleFade && v9->fadeTime != 0 && this->timeScale != 1.0 )
  {
    LODWORD(v29) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    fadeTime = v9->fadeTime;
    v72.swizzle[1] = (int)(float)((float)v29 * this->timeScale);
    v9->fadeTime = v72.swizzle[1] + fadeTime;
  }
  v31 = this->current.movement.viewOrigin.y;
  LODWORD(v13) = LODWORD(this->current.movement.viewOrigin.z);
  p_granularity = &v74.ops.granularity;
  p_startTimeOfs = &this->current.focus.frameLerp.startTimeOfs;
  v34 = 9;
  v73.x = this->current.movement.viewOrigin.x;
  v73.y = v31;
  LODWORD(v73.z) = v13;
  do
  {
    ++p_startTimeOfs;
    p_granularity += 2;
    *(_DWORD *)p_granularity = *p_startTimeOfs;
    --v34;
  }
  while ( v34 != 0 );
  idSlowMotionCamera::MoveOrigin(this, viewOrigin: &v73, a3: v13, a4: v14);
  HIDWORD(v35) = &v74.constants;
  idSlowMotionCamera::MoveAxis(this, viewOrigin: &v73, viewAxis: v35, a4: v36);
  if ( this->current.shakeView.shakeVolume >= 0.0 )
  {
    v9->cameraShake = this->current.shakeView.shakeVolume;
    v37 = (float)(this->current.shakeView.shakeVolume * (float)0.94999999);
    this->current.shakeView.shakeVolume = this->current.shakeView.shakeVolume * (float)0.94999999;
    if ( v37 <= 0.0 )
      this->current.shakeView.shakeVolume = 0.0;
  }
  Physics = idEntity::GetPhysics(this);
  v39 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v72, result: (idVec3 *)Physics, a3: 0);
  v9->viewVelocity.x = *v39;
  v9->viewVelocity.y = v39[1];
  v9->viewVelocity.z = v39[2];
  idView::SetViewPos(this: v9, origin: &v73, axis: (const idMat3 *)&v74.constants);
  idView::SetViewID(this: v9, id: this->entityNumber + 1);
  idView::Render(this: v9);
  v40 = player->presentable;
  if ( this->showPlayerHud )
  {
    if ( v40 != nullptr )
      v41 = (int)v40->GetPlayerInterface_2(this: v40);
    else
      v41 = 0;
    v42 = HUDSTATE_ALL;
  }
  else
  {
    if ( v40 != nullptr )
      v41 = (int)v40->GetPlayerInterface_2(this: v40);
    else
      v41 = 0;
    v42 = HUDSTATE_NONE;
  }
  idPlayerHud::SetHudState(this: (idPlayerHud *)(v41 + 35096), state: v42);
  v43 = player->presentable;
  if ( v43 != nullptr )
    v44 = (int)v43->GetPlayerInterface_2(this: v43);
  else
    v44 = 0;
  v45 = player->presentable;
  if ( v45 != nullptr )
    v46 = (int)v45->GetPlayerInterface_2(this: v45);
  else
    v46 = 0;
  idPlayerHud::Update(this: (idPlayerHud *)(v46 + 35096), hudInfo: (idHudInfo *)(v44 + 35368));
  if ( this->gui != nullptr )
  {
    v49 = player->presentable;
    if ( v49 != nullptr )
      v50 = (int)v49->GetPlayerInterface_2(this: v49);
    else
      v50 = 0;
    v51 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idSWF::Render(this: this->gui, gui: *(idRenderModelGui **)(v50 + 16224), time: v51, isSplitscreen: false, a5: v52);
  }
  if ( this->current.renderParms.timing.duration >= 0.0 )
  {
    v53 = idSlowMotionCamera::GetTimeLerpFraction(this, timeLerpHelper: v47, a3: v48);
    if ( this->current.renderParms.fogColor.r != idColor::colorDefault.r
      || this->current.renderParms.fogColor.g != idColor::colorDefault.g
      || this->current.renderParms.fogColor.b != idColor::colorDefault.b
      || (v54 = 1, this->current.renderParms.fogColor.a != idColor::colorDefault.a) )
    {
      v54 = 0;
    }
    if ( v54 == 0 )
    {
      v55 = (float)((float)((float)(this->current.renderParms.fogColor.r - this->previous.renderParms.fogColor.r)
                          * (float)v53)
                  + this->previous.renderParms.fogColor.r);
      v56 = (float)((float)((float)(this->current.renderParms.fogColor.g - this->previous.renderParms.fogColor.g)
                          * (float)v53)
                  + this->previous.renderParms.fogColor.g);
      v57 = (float)((float)((float)(this->current.renderParms.fogColor.b - this->previous.renderParms.fogColor.b)
                          * (float)v53)
                  + this->previous.renderParms.fogColor.b);
      v58 = (float)((float)((float)(this->current.renderParms.fogColor.a - this->previous.renderParms.fogColor.a)
                          * (float)v53)
                  + this->previous.renderParms.fogColor.a);
      v59 = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                        this: &idDeclRenderParm::resourceList,
                                        name: "fogColor",
                                        makeDefault: true);
      v72.value[0] = v55;
      v72.value[1] = v56;
      v72.value[2] = v57;
      v72.value[3] = v58;
      idParmBlock::SetParm(this: &v9->gameview.parmBlock, parm: v59, parmValue: &v72);
    }
    if ( this->current.renderParms.fogScale != -1.0 )
    {
      v60 = (float)((float)((float)(this->current.renderParms.fogScale - this->previous.renderParms.fogScale)
                          * (float)v53)
                  + this->previous.renderParms.fogScale);
      v61 = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                        this: &idDeclRenderParm::resourceList,
                                        name: "fogScale",
                                        makeDefault: true);
      v72.value[3] = v60;
      v72.value[2] = v60;
      v72.value[1] = v60;
      v72.value[0] = v60;
      idParmBlock::SetParm(this: &v9->gameview.parmBlock, parm: v61, parmValue: &v72);
    }
  }
  v63 = v73.y;
  v64 = v73.z;
  this->current.movement.viewOrigin.x = v73.x;
  this->current.movement.viewOrigin.y = v63;
  this->current.movement.viewOrigin.z = v64;
  this->current.focus.viewAxis.mat[0].x = *(float *)&v74.constants.list;
  v65 = *(float *)&v74.constants.num;
  v66 = *(float *)&v74.constants.size;
  this->current.focus.viewAxis.mat[1].x = *(float *)&v74.constants.granularity;
  v67 = *(float *)&v74.thread;
  this->current.focus.viewAxis.mat[0].y = v65;
  this->current.focus.viewAxis.mat[0].z = v66;
  v68 = *(float *)&v74.usingTempOps;
  this->current.focus.viewAxis.mat[1].y = v67;
  v69 = v75;
  this->current.focus.viewAxis.mat[1].z = v68;
  v70 = v76;
  this->current.focus.viewAxis.mat[2].x = v69;
  v71 = v77;
  this->current.focus.viewAxis.mat[2].y = v70;
  this->current.focus.viewAxis.mat[2].z = v71;
  return 1;
}


// ========================================================================
// ?InternalActivate@idSlowMotionCamera@@MAA_NPAVidEntity@@@Z
// EA  : 0x82D16760
// RVA : 0x00D16760
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idSlowMotionCamera::InternalActivate(idSlowMotionCamera *this, idVehicle_Car *activator_)
{
  idVehicle_Car *v4; // r3
  idPlayer *Driver; // r3
  idPlayer *v6; // r3
  idPhysics *Physics; // r3
  int value; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3
  idPlayer *activatingPlayer; // r3
  idPlayer *v13; // r11
  idPresentable *presentable; // r3
  int v15; // r3
  idPresentable *v16; // r3
  int v17; // r3
  idPresentable *v18; // r3
  int v19; // r3
  idSWFScriptFunction *v20; // r3
  idSWFScriptFunction *v21; // r4
  idSWFScriptFunction *v22; // r3
  idSWFScriptFunction *v23; // r4
  idSWFScriptFunction *v24; // r3
  idSWFScriptFunction *v25; // r4
  idSWFScriptFunction *v26; // r3
  idSWFScriptFunction *v27; // r4
  idSWFScriptVar v28; // [sp+58h] [-58h] BYREF
  idSWFScriptVar v29; // [sp+60h] [-50h] BYREF
  idSWFScriptVar v30; // [sp+68h] [-48h] BYREF
  idSWFScriptVar v31[8]; // [sp+70h] [-40h] BYREF

  v4 = idVehicle_Car::CastTo(c: activator_);
  this->activatingPlayer = nullptr;
  if ( v4 != nullptr )
  {
    Driver = (idPlayer *)idVehicle::GetDriver(this: v4);
    this->activatingPlayer = idPlayer::CastTo(c: Driver);
  }
  else
  {
    v6 = idPlayer::CastTo(c: (idPlayer *)activator_);
    this->activatingPlayer = v6;
    if ( v6 != nullptr )
    {
      Physics = idEntity::GetPhysics(this: v6);
      Physics->SetLinearVelocity(this: Physics, a2: &vec3_origin, a3: 0);
    }
  }
  if ( this->active
    && this->suspended
    && ((value = this->activator.spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13)
     || (v9 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
      ? (v10 = nullptr)
      : (v10 = idEntity::CastTo(c: v9)),
        activator_ == v10 || this->activatingPlayer == nullptr) )
  {
    idSlowMotionCamera::Unsuspend(this);
    return 0;
  }
  else
  {
    this->active = true;
    if ( cine_captureFrames.valueInteger != 0 )
    {
      cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_fixedtic", a3: 1, a4: 0);
      cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_captureFrames", a3: 2, a4: 0);
    }
    idSlowMotionCamera::InitStates(this);
    activatingPlayer = this->activatingPlayer;
    if ( activatingPlayer != nullptr )
    {
      this->prevHudState = *(_DWORD *)(idPlayer::GetPlayerHud(this: activatingPlayer) + 84);
      if ( activator_ != nullptr )
        this->activator.spawnId.value = (gameLocal->spawnIds.ptr[activator_->entityNumber] << 13)
                                      | activator_->entityNumber;
      else
        this->activator.spawnId.value = 0x1FFF;
      if ( this->hidePlayer )
        activator_->Hide_2(this: activator_);
      if ( this->hidePlayerHands )
      {
        v13 = this->activatingPlayer;
        if ( v13 != nullptr )
        {
          presentable = v13->presentable;
          v15 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
          if ( v15 != -37616 )
          {
            v16 = this->activatingPlayer->presentable;
            if ( v16 != nullptr )
              v17 = (int)v16->GetPlayerInterface_2(this: v16);
            else
              v17 = 0;
            idHands::Hide(this: (idHands *)(v17 + 37616), hideReason: HAND_HIDE_GENERIC);
            v18 = this->activatingPlayer->presentable;
            if ( v18 != nullptr )
              v19 = (int)v18->GetPlayerInterface_2(this: v18);
            else
              v19 = 0;
            idHands::UpdateHidden(this: (idHands *)(v19 + 37616));
          }
        }
      }
      if ( this->gui != nullptr )
      {
        v20 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0xCu,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        if ( v20 != nullptr )
        {
          v20[2].__vftable = (idSWFScriptFunction_vtbl *)this;
          v20[1].__vftable = nullptr;
          v21 = v20;
          v20->__vftable = (idSWFScriptFunction_vtbl *)&`idSlowMotionCamera::InternalActivate'::`28'::idSWFScriptFunction_UnsuspendCamera::`vftable';
        }
        else
        {
          v21 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v28, nf: v21);
        idSWFScriptObject::Set(this: this->gui->globals, name: "UnsuspendCamera", value: &v28);
        idSWFScriptVar::Free(this: &v28);
        v22 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0xCu,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        if ( v22 != nullptr )
        {
          v22[2].__vftable = (idSWFScriptFunction_vtbl *)this;
          v22[1].__vftable = nullptr;
          v23 = v22;
          v22->__vftable = (idSWFScriptFunction_vtbl *)&`idSlowMotionCamera::InternalActivate'::`29'::idSWFScriptFunction_QuitCamera::`vftable';
        }
        else
        {
          v23 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v29, nf: v23);
        idSWFScriptObject::Set(this: this->gui->globals, name: "QuitCamera", value: &v29);
        idSWFScriptVar::Free(this: &v29);
        v24 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0xCu,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        if ( v24 != nullptr )
        {
          v24[2].__vftable = (idSWFScriptFunction_vtbl *)this;
          v24[1].__vftable = nullptr;
          v25 = v24;
          v24->__vftable = (idSWFScriptFunction_vtbl *)&`idSlowMotionCamera::InternalActivate'::`30'::idSWFScriptFunction_GetNotificationFromCamera::`vftable';
        }
        else
        {
          v25 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v30, nf: v25);
        idSWFScriptObject::Set(this: this->gui->globals, name: "GetCameraNotification", value: &v30);
        idSWFScriptVar::Free(this: &v30);
        v26 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0xCu,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        if ( v26 != nullptr )
        {
          v26[2].__vftable = (idSWFScriptFunction_vtbl *)this;
          v26[1].__vftable = nullptr;
          v27 = v26;
          v26->__vftable = (idSWFScriptFunction_vtbl *)&`idSlowMotionCamera::InternalActivate'::`31'::idSWFScriptFunction_ClearCameraNotificaiton::`vftable';
        }
        else
        {
          v27 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: v31, nf: v27);
        idSWFScriptObject::Set(this: this->gui->globals, name: "ClearCameraNotification", value: v31);
        idSWFScriptVar::Free(this: v31);
        idSWF::Activate(this: this->gui, b: true);
      }
      idEntity::BecomeActive(this, flags: 1);
      return 1;
    }
    else
    {
      idLib::Warning(fmt: "Could not find a valid player for camera activation");
      this->activator.spawnId.value = 0x1FFF;
      return 0;
    }
  }
}


// ========================================================================
// __unwind$524431_0
// EA  : 0x82D16C0C
// RVA : 0x00D16C0C
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_524431_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$524433_0
// EA  : 0x82D16C34
// RVA : 0x00D16C34
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_524433_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$524435
// EA  : 0x82D16C5C
// RVA : 0x00D16C5C
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_524435()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 104));
}


// ========================================================================
// __unwind$524437
// EA  : 0x82D16C84
// RVA : 0x00D16C84
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_524437()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 112));
}


// ========================================================================
// `idSlowMotionCamera::InternalActivate'::`29'::idSWFScriptFunction_QuitCamera::Call
// EA  : 0x82D16CB0
// RVA : 0x00D16CB0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idSlowMotionCamera::InternalActivate_::_29_::idSWFScriptFunction_QuitCamera::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        __int64 parms,
        int a4,
        int a5,
        int a6)
{
  int v8; // [sp+8h] [-58h]
  __int64 v9; // [sp+10h] [-50h]
  __int64 v10; // [sp+18h] [-48h]
  __int64 v11; // [sp+20h] [-40h]
  __int64 v12; // [sp+28h] [-38h]
  __int64 v13; // [sp+30h] [-30h]

  *(float *)&parms = idColor::colorBlack.a;
  idSlowMotionCamera::CinematicDone(
    this: (idSlowMotionCamera *)LODWORD(idColor::colorBlack.r),
    color: parms,
    a3: a4,
    a4: a5,
    a5: a6,
    a6: (int)&idColor::colorBlack,
    a7: v8,
    a8: v9,
    a9: v10,
    a10: v11,
    a11: v12,
    a12: v13);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idSlowMotionCamera::InternalActivate'::`31'::idSWFScriptFunction_ClearCameraNotificaiton::Call
// EA  : 0x82D16D00
// RVA : 0x00D16D00
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idSlowMotionCamera::InternalActivate_::_31_::idSWFScriptFunction_ClearCameraNotificaiton::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int num; // r11

  num = thisObject->variables.num;
  result->type = SWF_VAR_UNDEF;
  *(_BYTE *)(num + 1026) = 0;
  return result;
}


// ========================================================================
// ?Draw@idRaceCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D16D18
// RVA : 0x00D16D18
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idRaceCamera::Draw(idRaceCamera *this, idPlayer *player)
{
  if ( racecam_version.valueInteger == 3 )
    return idRaceCamera::Draw_3(this, player);
  if ( racecam_version.valueInteger == 2 )
    return idRaceCamera::Draw_2(this, player);
  return idRaceCamera::Draw_1(this, player);
}


// ========================================================================
// ?Init@idDeathCamera@@UAAXVidVec3@@VidMat3@@PAVidEntity@@@Z
// EA  : 0x82D16D40
// RVA : 0x00D16D40
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeathCamera::Init(
        idDeathCamera *this,
        idVec3 *origin,
        __int64 activator_,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        int a16,
        idVehicle_Car *a17)
{
  idEntity *v17; // r3
  idEntity *v18; // r31
  idPhysics *Physics; // r3
  idPhysics *v20; // r3
  idVehicle_Car *v21; // r3
  idVehicle_Car *v22; // r3
  idVehicle_Car *v23; // r3
  idVehicle_Car *v24; // r3
  idEntity *Driver; // r3
  double v26; // fp11
  double v27; // fp8
  idClientGame *v28; // r9
  double v29; // fp6
  unsigned int v30; // r11
  __int128 v31; // r7
  unsigned int v32; // r10
  double v33; // fp30
  idVec3 *v34; // r3
  idClientGame *v35; // r11
  double v36; // fp3
  double v37; // fp2
  double v38; // fp9
  double v39; // fp8
  idClipModel *clip8x8; // r7
  double v41; // fp13
  double v42; // fp12
  int v43; // r9
  int v44; // r7
  __int64 v45; // r6
  int v46; // [sp+8h] [-128h]
  __int64 v47; // [sp+10h] [-120h]
  __int64 v48; // [sp+18h] [-118h]
  __int64 v49; // [sp+20h] [-110h]
  __int64 v50; // [sp+28h] [-108h]
  __int64 v51; // [sp+30h] [-100h]
  idAngles v52[2]; // [sp+58h] [-D8h] BYREF
  trace_t v53; // [sp+70h] [-C0h] BYREF

  a9 = *(_QWORD *)&origin;
  v18 = v17;
  a10 = *(__int64 *)((char *)&activator_ + 4);
  a11 = activator_;
  a12 = *(__int64 *)((char *)&a4 + 4);
  a13 = a4;
  a14 = *(__int64 *)((char *)&a5 + 4);
  a15 = a5;
  Physics = idEntity::GetPhysics(this: v17);
  Physics->SetOrigin(this: Physics, a2: (const idVec3 *)&a9, a3: -1);
  v20 = idEntity::GetPhysics(this: v18);
  v20->SetAxis(this: v20, a2: (const idMat3 *)&a11, a3: -1);
  v21 = a17;
  if ( a17 != nullptr )
    v18[1].__vftable = (idEntity_vtbl *)((gameLocal->spawnIds.ptr[a17->entityNumber] << 13) | a17->entityNumber);
  else
    v18[1].__vftable = (idEntity_vtbl *)0x1FFF;
  v22 = idVehicle_Car::CastTo(c: v21);
  if ( v22 != nullptr )
    LODWORD(v18[1].renderModelInfo.dimShadowClipZ) = (gameLocal->spawnIds.ptr[v22->entityNumber] << 13)
                                                   | v22->entityNumber;
  else
    LODWORD(v18[1].renderModelInfo.dimShadowClipZ) = 0x1FFF;
  if ( gameLocal->spawnIds.ptr[LODWORD(v18[1].renderModelInfo.dimShadowClipZ) & 0x1FFF] == SLODWORD(v18[1].renderModelInfo.dimShadowClipZ) >> 13 )
  {
    v23 = (idVehicle_Car *)gameLocal->entities.ptr[LODWORD(v18[1].renderModelInfo.dimShadowClipZ) & 0x1FFF];
    if ( v23 != nullptr )
      v24 = idVehicle_Car::CastTo(c: v23);
    else
      v24 = nullptr;
    Driver = idVehicle::GetDriver(this: v24);
    if ( Driver != nullptr )
      v18[1].__vftable = (idEntity_vtbl *)((gameLocal->spawnIds.ptr[Driver->entityNumber] << 13) | Driver->entityNumber);
    else
      v18[1].__vftable = (idEntity_vtbl *)0x1FFF;
  }
  v26 = (float)(*(float *)&a11 + *(float *)&a9);
  v27 = (float)(*((float *)&a11 + 1) + *((float *)&a9 + 1));
  v28 = clientGame;
  v29 = (float)(*(float *)&a12 + *(float *)&a10);
  v18[1].spawnOrientation.mat[2].x = *(float *)&a11 + *(float *)&a9;
  v18[1].spawnOrientation.mat[2].y = v27;
  v18[1].spawnOrientation.mat[2].z = v29;
  *(float *)&v18[1].flags = v26;
  *(float *)&v18[1].targets.list = v18[1].spawnOrientation.mat[2].y;
  *(float *)&v18[1].targets.num = v18[1].spawnOrientation.mat[2].z;
  v30 = 1664525 * v28->random.seed + 1013904223;
  v28->random.seed = v30;
  DWORD2(v31) = &off_82030000;
  LODWORD(v31) = (v30 >> 10) & 0x7FFF;
  v18[1].renderModelInfo.maxVisibleRange = (float)((float)((float)(__int64)v31 * (float)0.000061037019) - (float)1.0)
                                         * (float)180.0;
  DWORD2(v31) = 1664525 * clientGame->random.seed;
  clientGame->random.seed = DWORD2(v31) + 1013904223;
  v18[1].renderModelInfo.fadeVisibilityOver = 0.0;
  LODWORD(v31) = ((unsigned int)(DWORD2(v31) + 1013904223) >> 10) & 0x7FFF;
  v18[1].renderModelInfo.maxTexelDensity = -(float)((float)((float)(__int64)v31 * (float)0.0013733329) + (float)45.0);
  v32 = 1664525 * clientGame->random.seed + 1013904223;
  DWORD1(v31) = &unk_82150000;
  clientGame->random.seed = v32;
  DWORD2(v31) = (v32 >> 10) & 0x7FFF;
  v33 = (float)((float)((float)((float)*(__int64 *)((char *)&v31 + 4) * (float)0.000030518509) + (float)1.0)
              * (float)1000.0);
  v34 = idAngles::ToForward(this: v52, result: (idVec3 *)&v18[1].renderModelInfo.maxTexelDensity);
  v35 = clientGame;
  v36 = (float)(v34->z * (float)v33);
  v37 = (float)(v34->x * (float)v33);
  v38 = *(float *)&a10;
  v39 = *(float *)&a9;
  clip8x8 = clientGame->clip.clip8x8;
  *(float *)&v18[1].targets.granularity = (float)(v34->y * (float)v33) + *((float *)&a9 + 1);
  *(float *)&v18[1].renderModelInfo.model = (float)v36 + (float)v38;
  *(float *)&v18[1].targets.size = (float)v37 + (float)v39;
  idClip::TraceBounds(
    this: &v35->clip,
    result: &v53,
    start: (const idVec3 *)&v18[1].flags,
    end: (const idVec3 *)&v18[1].targets.size,
    trm: clip8x8,
    clipMask: 1,
    passEntityNumber: v18->entityNumber);
  if ( v53.fraction == 1.0 )
  {
    *((_BYTE *)&v18[1].renderModelInfo + 4) = 0;
  }
  else
  {
    v41 = *((float *)&a9 + 1);
    v42 = *(float *)&a10;
    v18[1].targets.size = SHIDWORD(a9);
    *(float *)&v18[1].targets.granularity = v41;
    *(float *)&v18[1].renderModelInfo.model = v42;
  }
  if ( !common->IsMultiplayer(this: common) )
  {
    LODWORD(v45) = 20000;
    *(float *)&v45 = idColor::colorBlack.a;
    idCameraView::FadeOut(
      this: (idCameraView *)LODWORD(idColor::colorBlack.r),
      timeMs: v45,
      a3: v44,
      a4: 0,
      a5: v43,
      a6: (int)&idColor::colorBlack,
      a7: v46,
      a8: v47,
      a9: v48,
      a10: v49,
      a11: v50,
      a12: v51);
  }
}


// ========================================================================
// ?InternalActivate@idRCBombDeathCamera@@UAA_NPAVidEntity@@@Z
// EA  : 0x82D170F0
// RVA : 0x00D170F0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idPlayer *__fastcall idRCBombDeathCamera::InternalActivate(idRCBombDeathCamera *this, idPlayer *activator_)
{
  idPlayer *v4; // r29
  idPlayer *result; // r3

  v4 = idCameraView::InternalActivate(this, activator_);
  if ( (_BYTE)v4 != 0 )
    idEntity::BecomeActive(this, flags: 1);
  result = v4;
  if ( activator_ != nullptr )
    this->activator.spawnId.value = (gameLocal->spawnIds.ptr[activator_->entityNumber] << 13) | activator_->entityNumber;
  else
    this->activator.spawnId.value = 0x1FFF;
  return result;
}


// ========================================================================
// ?AllocPresentable@idReviveCamera@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82D17178
// RVA : 0x00D17178
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idReviveCamera::AllocPresentable(idReviveCamera *this, idRenderModel *renderModel)
{
  idPresentable *v3; // r3
  idPresentableReviveCamera *v4; // r30

  v3 = (idPresentable *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x508u,
                          tag: TAG_PRESENTABLE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v4 = (idPresentableReviveCamera *)v3;
  if ( v3 != nullptr )
  {
    idPresentable::idPresentable(
      this: v3,
      e: this,
      renderModel_: nullptr,
      entityNumber_: this->entityNumber,
      fxDecl_: nullptr);
    v4->__vftable = (idPresentableReviveCamera_vtbl *)&idPresentableReviveCamera::`vftable';
    v4->reset.count = 0;
    v4->reset.lastCount = 0;
    v4->playerPresentable.spawnId = 0;
    idPresentableReviveCamera::SetDefaults(this: v4);
  }
}


// ========================================================================
// __unwind$526509
// EA  : 0x82D1721C
// RVA : 0x00D1721C
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_526509()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?InternalActivate@idOnlineVehicleDeathCamera@@UAA_NPAVidEntity@@@Z
// EA  : 0x82D17248
// RVA : 0x00D17248
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idOnlineVehicleDeathCamera::InternalActivate(idOnlineVehicleDeathCamera *this, idEntity *activator_)
{
  int result; // r3

  idEntity::BecomeActive(this, flags: 1);
  result = 1;
  if ( activator_ != nullptr )
    this->activator.spawnId.value = (gameLocal->spawnIds.ptr[activator_->entityNumber] << 13) | activator_->entityNumber;
  else
    this->activator.spawnId.value = 0x1FFF;
  return result;
}


// ========================================================================
// ?AllocPresentable@idOnlineVehicleDeathCamera@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82D172C8
// RVA : 0x00D172C8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idOnlineVehicleDeathCamera::AllocPresentable(
        idOnlineVehicleDeathCamera *this,
        idRenderModel *renderModel)
{
  idOnlineVehicleDeathCameraPresentable *v3; // r3

  v3 = (idOnlineVehicleDeathCameraPresentable *)idMem::AllocWithLocation(
                                                  this: &mem,
                                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                  size: 0x568u,
                                                  tag: TAG_PRESENTABLE,
                                                  zeroBuffer: false,
                                                  align: ALIGN_16,
                                                  heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    idOnlineVehicleDeathCameraPresentable::idOnlineVehicleDeathCameraPresentable(this: v3, ent: this);
}


// ========================================================================
// __unwind$526651
// EA  : 0x82D17340
// RVA : 0x00D17340
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_526651()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Draw@idCaptureController@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D17370
// RVA : 0x00D17370
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idCaptureController::Draw(idCaptureController *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v4; // r11
  idView *v5; // r17
  idPhysics *Physics; // r3
  int v7; // r3
  float v8; // r7
  float v9; // r6
  idPhysics *v10; // r3
  int v11; // r3
  float *p_yaw; // r10
  _DWORD *v13; // r9
  int i; // ctr
  int *v15; // r10
  float *v16; // r11
  int j; // ctr
  int value; // r9
  idEntity *v19; // r3
  idVehicle *v20; // r28
  idVehicle *v21; // r29
  idGameLocal_vtbl *v22; // r11
  idGameLocal *v23; // r11
  int v24; // r9
  idEntity *v25; // r3
  int v26; // r9
  idEntity *v27; // r3
  idEntity *v28; // r3
  idPhysics *v29; // r3
  float *v30; // r3
  double v31; // fp9
  double v32; // fp7
  float *v33; // r3
  idCameraView *v34; // r3
  float *v35; // r3
  int v36; // r9
  idEntity *v37; // r3
  idVehicle *v38; // r28
  idVehicle *v39; // r29
  __int64 v40; // r5 OVERLAPPED
  idGameLocal *v41; // r11
  int v42; // r9
  idEntity *v43; // r3
  int v44; // r9
  idEntity *v45; // r3
  idEntity *v46; // r3
  idPhysics *v47; // r3
  float *v48; // r3
  double v49; // fp9
  double v50; // fp7
  float *v51; // r3
  idCameraView *v52; // r3
  float *v53; // r3
  idCaptureController::shotInfo_t *v54; // r10
  double duration; // fp13
  int shotStartTime; // r6
  double v57; // fp31
  int v58; // r9
  idEntity *v59; // r3
  idEntity *v60; // r3
  idEntity *v61; // r30
  int v62; // r9
  idEntity *v63; // r3
  idEntity *v64; // r3
  idCaptureController::shotInfo_t *v65; // r11
  idAngles *v66; // r3
  __int64 v67; // r4
  const idVec3 *v68; // r5
  int currentShot; // r11
  idCaptureController::shotInfo_t *list; // r10
  __int64 v71; // r10
  double v72; // fp30
  idAngles *v73; // r3
  idVec3 v75; // [sp+50h] [-250h] BYREF
  idExtrapolate<idAngles> v76; // [sp+60h] [-240h] BYREF
  float v77; // [sp+A0h] [-200h]
  idAngles v78; // [sp+A8h] [-1F8h] BYREF
  idVec3 v79; // [sp+B8h] [-1E8h] BYREF
  int v80; // [sp+CCh] [-1D4h] BYREF
  idMat3 v81; // [sp+D0h] [-1D0h] BYREF
  float v82; // [sp+F4h] [-1ACh] BYREF
  idMat3 v83; // [sp+F8h] [-1A8h] BYREF
  idMat3 v84; // [sp+128h] [-178h] BYREF
  idQuat v85; // [sp+150h] [-150h] BYREF
  idMat3 v86; // [sp+160h] [-140h] BYREF
  idInterpolateAccelDecelLinear<idAngles> v87; // [sp+1A0h] [-100h] BYREF

  presentable = player->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = 0;
  v5 = (idView *)(v4 + 16224);
  Physics = idEntity::GetPhysics(this);
  v7 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v8 = *(float *)(v7 + 4);
  v9 = *(float *)(v7 + 8);
  v75.x = *(float *)v7;
  v75.y = v8;
  v75.z = v9;
  v10 = idEntity::GetPhysics(this);
  v11 = (int)v10->GetAxis(this: v10, a2: 0);
  p_yaw = &v76.baseSpeed.yaw;
  v13 = (_DWORD *)(v11 - 4);
  for ( i = 9; i != 0; --i )
    *++p_yaw = *(float *)++v13;
  v15 = &v80;
  v16 = &v76.baseSpeed.yaw;
  *(idVec3 *)&v76.startValue.yaw = v75;
  for ( j = 9; j != 0; --j )
    *++v15 = *(_DWORD *)++v16;
  value = this->shots.list[this->currentShot].entFrom.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v19 = gameLocal->entities.ptr[this->shots.list[this->currentShot].entFrom.spawnId.value & 0x1FFF]) != nullptr )
  {
    v20 = (idVehicle *)idEntity::CastTo(c: v19);
  }
  else
  {
    v20 = nullptr;
  }
  v21 = idVehicle::CastTo(c: v20);
  if ( this->shots.list[this->currentShot].stopTime )
  {
    v22 = gameLocal->__vftable;
    if ( g_stopTime.valueInteger != 0 )
    {
      useTime += v22->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    }
    else
    {
      useTime = v22->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idCVar::SetBool(this: &g_stopTime, newValue: true, force: true);
    }
  }
  else
  {
    useTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  }
  if ( v21 == nullptr )
  {
    v34 = idCameraView::CastTo(c: (idCameraView *)v20);
    if ( v34 != nullptr )
    {
      idCameraView::GetViewPos(this: v34, org: &v75, angles: (idAngles *)&v83.mat[2].z);
      v35 = (float *)idAngles::ToMat3(this: (idAngles *)&v86.mat[1].y, result: (idMat3 *)&v83.mat[2].z);
      v76.baseSpeed.roll = *v35;
      v76.speed.pitch = v35[1];
      v76.speed.yaw = v35[2];
      v76.speed.roll = v35[3];
      v76.currentTime = v35[4];
      v76.currentValue.pitch = v35[5];
      v76.currentValue.yaw = v35[6];
      v76.currentValue.roll = v35[7];
      v77 = v35[8];
    }
    goto LABEL_30;
  }
  cvarSystem->SetCVarString(
    this: cvarSystem,
    a2: "vehicle_cam_tag",
    a3: vehicle_cam_info[this->shots.list[this->currentShot].camTagFrom].tagName,
    a4: 0);
  cvarSystem->SetCVarString(this: cvarSystem, a2: "vehicle_follow", a3: v21->name.data, a4: 0);
  idVehicle::SetCurrentCameraTag(num: this->shots.list[this->currentShot].camTagFrom);
  if ( cine_ignoreCameraOffsets.valueInteger == 0 )
  {
    ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
      a1: cvarSystem,
      a2: "vehicle_cam_fwd",
      a3: this->shots.list[this->currentShot].camFromOffsets.x);
    ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
      a1: cvarSystem,
      a2: "vehicle_cam_rt",
      a3: this->shots.list[this->currentShot].camFromOffsets.y);
    ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
      a1: cvarSystem,
      a2: "vehicle_cam_up",
      a3: this->shots.list[this->currentShot].camFromOffsets.z);
  }
  idVehicle::GetVehicleCameraView(origin: &v75, axis: (idMat3 *)&v76.baseSpeed.roll, fov_x: &v82, view: v5);
  v23 = gameLocal;
  v24 = this->shots.list[this->currentShot].entFromLookAt.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v24 & 0x1FFF] == v24 >> 13 )
  {
    v25 = gameLocal->entities.ptr[this->shots.list[this->currentShot].entFromLookAt.spawnId.value & 0x1FFF];
    if ( v25 != nullptr )
    {
      if ( idEntity::CastTo(c: v25) != nullptr )
      {
        v26 = this->shots.list[this->currentShot].entFromLookAt.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v26 & 0x1FFF] == v26 >> 13
          && (v27 = gameLocal->entities.ptr[this->shots.list[this->currentShot].entFromLookAt.spawnId.value & 0x1FFF]) != nullptr )
        {
          v28 = idEntity::CastTo(c: v27);
        }
        else
        {
          v28 = nullptr;
        }
        v29 = idEntity::GetPhysics(this: v28);
        v30 = (float *)v29->GetOrigin(this: v29, a2: 0);
        v31 = (float)(v30[2] - v75.z);
        v32 = (float)(v30[1] - v75.y);
        v83.mat[1].y = *v30 - v75.x;
        v83.mat[2].x = v31;
        v83.mat[1].z = v32;
        idVec3::NormalizeFast(this: (idVec3 *)&v83.mat[1].y);
        v33 = (float *)idVec3::ToMat3(this: (idVec3 *)&v86.mat[1].y, result: (idMat3 *)&v83.mat[1].y);
        v76.baseSpeed.roll = *v33;
        v76.speed.pitch = v33[1];
        v76.speed.yaw = v33[2];
        v76.speed.roll = v33[3];
        v76.currentTime = v33[4];
        v76.currentValue.pitch = v33[5];
        v76.currentValue.yaw = v33[6];
        v76.currentValue.roll = v33[7];
        v77 = v33[8];
      }
LABEL_30:
      v23 = gameLocal;
    }
  }
  v36 = this->shots.list[this->currentShot].entTo.spawnId.value;
  if ( v23->spawnIds.ptr[v36 & 0x1FFF] == v36 >> 13
    && (v37 = v23->entities.ptr[this->shots.list[this->currentShot].entTo.spawnId.value & 0x1FFF]) != nullptr )
  {
    v38 = (idVehicle *)idEntity::CastTo(c: v37);
  }
  else
  {
    v38 = nullptr;
  }
  v39 = idVehicle::CastTo(c: v38);
  if ( v39 == nullptr )
  {
    v52 = idCameraView::CastTo(c: (idCameraView *)v38);
    if ( v52 != nullptr )
    {
      idCameraView::GetViewPos(this: v52, org: (idVec3 *)&v76.startValue.yaw, angles: (idAngles *)&v84);
      v53 = (float *)idAngles::ToMat3(this: (idAngles *)&v86.mat[1].y, result: &v84);
      v81.mat[0].x = *v53;
      v81.mat[0].y = v53[1];
      v81.mat[0].z = v53[2];
      v81.mat[1].x = v53[3];
      v81.mat[1].y = v53[4];
      v81.mat[1].z = v53[5];
      v81.mat[2].x = v53[6];
      v81.mat[2].y = v53[7];
      v81.mat[2].z = v53[8];
    }
    goto LABEL_48;
  }
  cvarSystem->SetCVarString(
    this: cvarSystem,
    a2: "vehicle_cam_tag",
    a3: vehicle_cam_info[this->shots.list[this->currentShot].camTagTo].tagName,
    a4: 0);
  cvarSystem->SetCVarString(this: cvarSystem, a2: "vehicle_follow", a3: v39->name.data, a4: 0);
  idVehicle::SetCurrentCameraTag(num: this->shots.list[this->currentShot].camTagTo);
  if ( cine_ignoreCameraOffsets.valueInteger == 0 )
  {
    ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
      a1: cvarSystem,
      a2: "vehicle_cam_fwd",
      a3: this->shots.list[this->currentShot].camToOffsets.x);
    ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
      a1: cvarSystem,
      a2: "vehicle_cam_rt",
      a3: this->shots.list[this->currentShot].camToOffsets.y);
    ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
      a1: cvarSystem,
      a2: "vehicle_cam_up",
      a3: this->shots.list[this->currentShot].camToOffsets.z);
  }
  idVehicle::GetVehicleCameraView(origin: (idVec3 *)&v76.startValue.yaw, axis: &v81, fov_x: &v82, view: v5);
  v41 = gameLocal;
  v42 = this->shots.list[this->currentShot].entToLookAt.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v42 & 0x1FFF] == v42 >> 13 )
  {
    v43 = gameLocal->entities.ptr[this->shots.list[this->currentShot].entToLookAt.spawnId.value & 0x1FFF];
    if ( v43 != nullptr )
    {
      if ( idEntity::CastTo(c: v43) != nullptr )
      {
        v44 = this->shots.list[this->currentShot].entToLookAt.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v44 & 0x1FFF] == v44 >> 13
          && (v45 = gameLocal->entities.ptr[this->shots.list[this->currentShot].entToLookAt.spawnId.value & 0x1FFF]) != nullptr )
        {
          v46 = idEntity::CastTo(c: v45);
        }
        else
        {
          v46 = nullptr;
        }
        v47 = idEntity::GetPhysics(this: v46);
        v48 = (float *)v47->GetOrigin(this: v47, a2: 0);
        v49 = (float)(v48[2] - v76.baseSpeed.pitch);
        v50 = (float)(v48[1] - v76.startValue.roll);
        v83.mat[0].x = *v48 - v76.startValue.yaw;
        v83.mat[0].z = v49;
        v83.mat[0].y = v50;
        idVec3::NormalizeFast(this: v83.mat);
        v51 = (float *)idVec3::ToMat3(this: (idVec3 *)&v86.mat[1].y, result: &v83);
        v81.mat[0].x = *v51;
        v81.mat[0].y = v51[1];
        v81.mat[0].z = v51[2];
        v81.mat[1].x = v51[3];
        v81.mat[1].y = v51[4];
        v81.mat[1].z = v51[5];
        v81.mat[2].x = v51[6];
        v81.mat[2].y = v51[7];
        v81.mat[2].z = v51[8];
      }
LABEL_48:
      v41 = gameLocal;
    }
  }
  v54 = &this->shots.list[this->currentShot];
  duration = v54->duration;
  if ( duration == 0.0 )
    duration = 1.0;
  shotStartTime = this->shotStartTime;
  LODWORD(v40) = useTime;
  *(_QWORD *)&v76.extrapolationType = v40;
  v57 = (float)((float)((float)v40 - (float)*(__int64 *)((char *)&v40 - 4)) / (float)((float)duration * (float)1000.0));
  if ( v57 >= 1.0 )
  {
    if ( !v54->fired )
    {
      if ( v54->stopTime )
        idCVar::SetBool(this: &g_stopTime, newValue: false, force: true);
      idEventReceiver::PostEventSec(this, ev: &EV_NextShot, time: this->shots.list[this->currentShot].wait);
      this->shots.list[this->currentShot].fired = true;
      v41 = gameLocal;
    }
    v57 = 1.0;
  }
  v58 = this->shots.list[this->currentShot].entTo.spawnId.value;
  if ( v41->spawnIds.ptr[v58 & 0x1FFF] == v58 >> 13
    && (v59 = v41->entities.ptr[this->shots.list[this->currentShot].entTo.spawnId.value & 0x1FFF]) != nullptr )
  {
    v60 = idEntity::CastTo(c: v59);
    v41 = gameLocal;
    v61 = v60;
  }
  else
  {
    v61 = nullptr;
  }
  v62 = this->shots.list[this->currentShot].entFrom.spawnId.value;
  if ( v41->spawnIds.ptr[v62 & 0x1FFF] == v62 >> 13
    && (v63 = v41->entities.ptr[this->shots.list[this->currentShot].entFrom.spawnId.value & 0x1FFF]) != nullptr )
  {
    v64 = idEntity::CastTo(c: v63);
  }
  else
  {
    v64 = nullptr;
  }
  if ( v61 == v64 && (v65 = &this->shots.list[this->currentShot])->camTagFrom == v65->camTagTo )
  {
    v79.x = v75.x;
    v79.y = v75.y;
    v79.z = v75.z;
    v66 = idMat3::ToAngles(this: (idMat3 *)&v76, result: (idAngles *)&v76.baseSpeed.roll);
    v78.pitch = v66->pitch;
    v78.yaw = v66->yaw;
    v78.roll = v66->roll;
  }
  else
  {
    HIDWORD(v67) = idInterpolateAccelDecelSine<idVec3>::idInterpolateAccelDecelSine<idVec3>(this: &v87);
    v68 = (const idVec3 *)this->shotStartTime;
    currentShot = this->currentShot;
    LODWORD(v67) = v68;
    list = this->shots.list;
    *(_QWORD *)&v76.extrapolationType = v67;
    idInterpolateAccelDecelSine<idVec3>::Init(
      this: (idInterpolateAccelDecelSine<idVec3> *)&v87,
      startTime: (float)((float)v67 * (float)0.001),
      accelTime: (float)(cine_cameraAccel.valueFloat * list[currentShot].duration),
      decelTime: (float)(cine_cameraAccel.valueFloat * list[currentShot].duration),
      duration: list[currentShot].duration,
      startValue: v68,
      endValue: v68,
      a8: (int)&list[currentShot],
      a9: (int)&cine_cameraAccel,
      a10: &v75,
      a11: (idVec3 *)&v76.startValue.yaw);
    LODWORD(v71) = useTime;
    v72 = (float)((float)v71 * 0.001);
    *(_QWORD *)&v76.extrapolationType = v71;
    idInterpolateAccelDecelSine<idVec3>::SetPhase(this: (idInterpolateAccelDecelSine<idVec3> *)&v87, time: v72);
    idExtrapolate<idAngles>::GetCurrentValue(this: &v76, result: (idAngles *)&v87.extrapolate, time: v72);
    v79.x = *(float *)&v76.extrapolationType;
    v79.y = v76.startTime;
    v79.z = v76.duration;
    idMat3::ToQuat(this: &v86, result: (idQuat *)&v76.baseSpeed.roll);
    idMat3::ToQuat(this: (idMat3 *)&v84.mat[2], result: (idQuat *)&v81);
    idQuat::Slerp(this: &v85, from: (const idQuat *)&v86, to: (const idQuat *)&v84.mat[2], t: v57);
    v73 = idQuat::ToAngles(this: (idQuat *)&v76, result: (idAngles *)&v85);
    v78.pitch = v73->pitch;
    v78.yaw = v73->yaw;
    v78.roll = v73->roll;
  }
  idView::SetViewPos(this: v5, origin: &v79, angles: &v78);
  idView::SetViewID(this: v5, id: this->entityNumber + 1);
  idView::Render(this: v5);
  return 1;
}


// ========================================================================
// ?Init@idSpectatorCamera@@UAAXVidVec3@@VidMat3@@PAVidEntity@@@Z
// EA  : 0x82D18010
// RVA : 0x00D18010
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSpectatorCamera::Init(
        idSpectatorCamera *this,
        idVec3 *origin,
        __int64 activator_,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        int a16,
        int a17)
{
  idEntity *v17; // r3
  idEntity *v18; // r31
  idPhysics *Physics; // r3
  idPhysics *v20; // r3
  int v21; // r10
  double v22; // fp13
  double v23; // fp12
  double v24; // fp9
  double v25; // fp8
  double v26; // fp7
  double v27; // fp6
  double v28; // fp5
  double v29; // fp4
  double v30; // fp3
  int v31; // r9
  idEntity *v32; // r3
  int v33; // r9
  idEntity *v34; // r3
  idEntity *v35; // r3
  idPhysics *v36; // r3
  float *p_dimShadowClipZ; // r3
  double v38; // fp11
  idPlayer *PlayerActivator; // r3
  int value; // r9
  idGameLocal *v41; // r11
  idVehicle *v42; // r3
  idVehicle *v43; // r3

  a9 = *(_QWORD *)&origin;
  v18 = v17;
  a10 = *(__int64 *)((char *)&activator_ + 4);
  a11 = activator_;
  a12 = *(__int64 *)((char *)&a4 + 4);
  a13 = a4;
  a14 = *(__int64 *)((char *)&a5 + 4);
  a15 = a5;
  Physics = idEntity::GetPhysics(this: v17);
  Physics->SetOrigin(this: Physics, a2: (const idVec3 *)&a9, a3: -1);
  v20 = idEntity::GetPhysics(this: v18);
  v20->SetAxis(this: v20, a2: (const idMat3 *)&a11, a3: -1);
  v21 = a17;
  v22 = *((float *)&a9 + 1);
  v23 = *(float *)&a10;
  v18[1].spawnOrientation.mat[2].y = *(float *)&a9;
  v18[1].spawnOrientation.mat[2].z = v22;
  *(float *)&v18[1].flags = v23;
  v18[1].targets.list = (idEntityPtr<idEntity> *)HIDWORD(a11);
  v24 = *((float *)&a11 + 1);
  v25 = *(float *)&a12;
  *(float *)&v18[1].targets.granularity = *((float *)&a12 + 1);
  v26 = *(float *)&a13;
  *(float *)&v18[1].targets.num = v24;
  *(float *)&v18[1].targets.size = v25;
  v27 = *((float *)&a13 + 1);
  *(float *)&v18[1].renderModelInfo.model = v26;
  v28 = *(float *)&a14;
  *((float *)&v18[1].renderModelInfo + 1) = v27;
  v29 = *((float *)&a14 + 1);
  v18[1].renderModelInfo.maxTexelDensity = v28;
  v30 = *(float *)&a15;
  v18[1].renderModelInfo.maxVisibleRange = v29;
  v18[1].renderModelInfo.fadeVisibilityOver = v30;
  if ( v21 != 0 )
    v18[1].__vftable = (idEntity_vtbl *)((gameLocal->spawnIds.ptr[*(_DWORD *)(v21 + 492)] << 13) | *(_DWORD *)(v21 + 492));
  else
    v18[1].__vftable = (idEntity_vtbl *)0x1FFF;
  LODWORD(v18[1].spawnOrientation.mat[2].x) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v31 = *(_DWORD *)&v18[1].name.baseBuffer[8];
  if ( gameLocal->spawnIds.ptr[v31 & 0x1FFF] == v31 >> 13
    && (v32 = gameLocal->entities.ptr[v31 & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v32) != nullptr )
  {
    v33 = *(_DWORD *)&v18[1].name.baseBuffer[8];
    if ( gameLocal->spawnIds.ptr[v33 & 0x1FFF] == v33 >> 13 && (v34 = gameLocal->entities.ptr[v33 & 0x1FFF]) != nullptr )
      v35 = idEntity::CastTo(c: v34);
    else
      v35 = nullptr;
    v36 = idEntity::GetPhysics(this: v35);
    p_dimShadowClipZ = (float *)v36->GetOrigin(this: v36, a2: 0);
  }
  else
  {
    p_dimShadowClipZ = &v18[1].renderModelInfo.dimShadowClipZ;
  }
  v38 = (float)(*(float *)&v18[1].flags - *(float *)&v18[1].flags);
  v18[1].renderModelInfo.scale.y = __fsqrts((float)((float)((float)(*p_dimShadowClipZ - v18[1].spawnOrientation.mat[2].y)
                                                          * (float)(*p_dimShadowClipZ - v18[1].spawnOrientation.mat[2].y))
                                                  + (float)((float)((float)v38 * (float)v38)
                                                          + (float)((float)(p_dimShadowClipZ[1]
                                                                          - v18[1].spawnOrientation.mat[2].z)
                                                                  * (float)(p_dimShadowClipZ[1]
                                                                          - v18[1].spawnOrientation.mat[2].z)))));
  LODWORD(v18[1].renderModelInfo.scale.z) = 0x1FFF;
  HIBYTE(v18[1].renderModelInfo.color.g) = 0;
  PlayerActivator = idCamera::GetPlayerActivator(this: (idCamera *)v18);
  if ( PlayerActivator != nullptr )
  {
    value = PlayerActivator->lastVehicle.spawnId.value;
    v41 = gameLocal;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v42 = (idVehicle *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v43 = idVehicle::CastTo(c: v42);
      v41 = gameLocal;
    }
    else
    {
      v43 = nullptr;
    }
    if ( v43 == nullptr )
    {
      LODWORD(v18[1].renderModelInfo.color.r) = 0x1FFF;
      idEntity::BecomeActive(this: v18, flags: 1);
      return;
    }
    LODWORD(v18[1].renderModelInfo.color.r) = (v41->spawnIds.ptr[v43->entityNumber] << 13) | v43->entityNumber;
  }
  idEntity::BecomeActive(this: v18, flags: 1);
}


// ========================================================================
// ?HandleUserCmds@idSpectatorCamera@@UAAXABVusercmd_t@@0@Z
// EA  : 0x82D182E8
// RVA : 0x00D182E8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idSpectatorCamera::HandleUserCmds(
        idSpectatorCamera *this,
        const usercmd_t *prevcmd,
        const usercmd_t *usercmd)
{
  int buttons; // r11
  int v7; // r11
  int value; // r9
  idEntityPtr<idVehicle> *p_followVehicle; // r31
  idGameLocal *v10; // r11
  idVehicle *v11; // r3
  idLinkList<idVehicle> *v12; // r10
  idVehicle *v13; // r10
  int v14; // r5
  idVehicle *Entity; // r3
  idLinkList<idVehicle> *next; // r11
  idVehicle *owner; // r11
  idGameLocal *v18; // r11
  idVehicle *v19; // r3
  idVehicle *v20; // r3
  int v21; // r10
  int v22; // r10
  int v23; // r9
  idEntityPtr<idVehicle> *v24; // r31
  idVehicle *v25; // r3
  idLinkList<idVehicle> *v26; // r10
  idVehicle *v27; // r10
  int v28; // r5
  idVehicle *v29; // r3
  idLinkList<idVehicle> *prev; // r11
  idVehicle *v31; // r11
  idVehicle *v32; // r3
  idVehicle *v33; // r3

  LOBYTE(buttons) = 0;
  if ( (*((_BYTE *)usercmd + 9) & 0x80) == 0 )
    buttons = usercmd->buttons;
  if ( (buttons & 0x40) == 0 )
    goto LABEL_33;
  LOBYTE(v7) = 0;
  if ( (*((_BYTE *)prevcmd + 9) & 0x80) == 0 )
    v7 = prevcmd->buttons;
  if ( (v7 & 0x40) != 0 )
    goto LABEL_33;
  value = this->followVehicle.spawnId.value;
  p_followVehicle = &this->followVehicle;
  v10 = gameLocal;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v11 = (idVehicle *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v11 != nullptr )
    {
      if ( idVehicle::CastTo(c: v11) != nullptr )
      {
        Entity = idEntityPtr<idVehicle>::GetEntity(this: &this->followVehicle);
        next = Entity->controlNode.next;
        if ( next == nullptr || next == Entity->controlNode.head )
          owner = nullptr;
        else
          owner = next->owner;
        if ( owner == nullptr )
        {
          p_followVehicle->spawnId.value = 0x1FFF;
          goto LABEL_26;
        }
        v14 = (gameLocal->spawnIds.ptr[owner->entityNumber] << 13) | owner->entityNumber;
LABEL_25:
        p_followVehicle->spawnId.value = v14;
        goto LABEL_26;
      }
      v10 = gameLocal;
    }
  }
  v12 = v10->vehicleEntities.next;
  if ( v12 == nullptr || v12 == v10->vehicleEntities.head )
    v13 = nullptr;
  else
    v13 = v12->owner;
  if ( v13 != nullptr )
  {
    v14 = (v10->spawnIds.ptr[v13->entityNumber] << 13) | v13->entityNumber;
    goto LABEL_25;
  }
  p_followVehicle->spawnId.value = 0x1FFF;
LABEL_26:
  v18 = gameLocal;
  if ( gameLocal->spawnIds.ptr[p_followVehicle->spawnId.value & 0x1FFF] == p_followVehicle->spawnId.value >> 13 )
  {
    v19 = (idVehicle *)gameLocal->entities.ptr[p_followVehicle->spawnId.value & 0x1FFF];
    if ( v19 != nullptr )
    {
      if ( idVehicle::CastTo(c: v19) != nullptr )
      {
        v20 = idEntityPtr<idVehicle>::GetEntity(this: &this->followVehicle);
        if ( v20 != nullptr )
          this->target.spawnId.value = (gameLocal->spawnIds.ptr[v20->entityNumber] << 13) | v20->entityNumber;
        else
          this->target.spawnId.value = 0x1FFF;
        this->lostVehicle = false;
      }
LABEL_33:
      v18 = gameLocal;
    }
  }
  v21 = 0;
  if ( (*((_BYTE *)usercmd + 9) & 0x80) == 0 )
    v21 = usercmd->buttons;
  if ( (v21 & 0x200000) != 0 )
  {
    v22 = 0;
    if ( (*((_BYTE *)prevcmd + 9) & 0x80) == 0 )
      v22 = prevcmd->buttons;
    if ( (v22 & 0x200000) == 0 )
    {
      v23 = this->followVehicle.spawnId.value;
      v24 = &this->followVehicle;
      if ( v18->spawnIds.ptr[v23 & 0x1FFF] == v23 >> 13 )
      {
        v25 = (idVehicle *)v18->entities.ptr[v23 & 0x1FFF];
        if ( v25 != nullptr )
        {
          if ( idVehicle::CastTo(c: v25) != nullptr )
          {
            v29 = idEntityPtr<idVehicle>::GetEntity(this: &this->followVehicle);
            prev = v29->controlNode.prev;
            if ( prev == nullptr || prev == v29->controlNode.head )
              v31 = nullptr;
            else
              v31 = prev->owner;
            if ( v31 == nullptr )
            {
              v24->spawnId.value = 0x1FFF;
              goto LABEL_59;
            }
            v28 = (gameLocal->spawnIds.ptr[v31->entityNumber] << 13) | v31->entityNumber;
LABEL_58:
            v24->spawnId.value = v28;
            goto LABEL_59;
          }
          v18 = gameLocal;
        }
      }
      v26 = v18->vehicleEntities.prev;
      if ( v26 == nullptr || v26 == v18->vehicleEntities.head )
        v27 = nullptr;
      else
        v27 = v26->owner;
      if ( v27 == nullptr )
      {
        v24->spawnId.value = 0x1FFF;
LABEL_59:
        if ( gameLocal->spawnIds.ptr[v24->spawnId.value & 0x1FFF] == v24->spawnId.value >> 13 )
        {
          v32 = (idVehicle *)gameLocal->entities.ptr[v24->spawnId.value & 0x1FFF];
          if ( v32 != nullptr && idVehicle::CastTo(c: v32) != nullptr )
          {
            v33 = idEntityPtr<idVehicle>::GetEntity(this: &this->followVehicle);
            if ( v33 != nullptr )
              this->target.spawnId.value = (gameLocal->spawnIds.ptr[v33->entityNumber] << 13) | v33->entityNumber;
            else
              this->target.spawnId.value = 0x1FFF;
            this->lostVehicle = false;
          }
        }
        return;
      }
      v28 = (v18->spawnIds.ptr[v27->entityNumber] << 13) | v27->entityNumber;
      goto LABEL_58;
    }
  }
}


// ========================================================================
// ?InternalActivate@idFreeCamera@@MAA_NPAVidEntity@@@Z
// EA  : 0x82D186B8
// RVA : 0x00D186B8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idPlayer *__fastcall idFreeCamera::InternalActivate(idFreeCamera *this, idPlayer *activator_)
{
  idPlayer *v4; // r30
  idPlayer *v5; // r3
  idPresentable *presentable; // r3
  int v7; // r3
  idMat3 v9[2]; // [sp+50h] [-60h] BYREF

  v4 = idCameraView::InternalActivate(this, activator_);
  v5 = idPlayer::CastTo(c: activator_);
  if ( v5 != nullptr )
  {
    presentable = v5->presentable;
    if ( presentable != nullptr )
      v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v7 = 0;
    idView::GetViewPos(this: (idView *)(v7 + 16224), origin: &this->curPos, axis: (idMat3 *)&v9[0].mat[1].y);
    this->curAngles = *idMat3::ToAngles(this: v9, result: (idAngles *)&v9[0].mat[1].y);
  }
  this->bFirstActive = true;
  return v4;
}


// ========================================================================
// `idCinematicCamera::InternalActivate'::`37'::idSWFScriptFunction_UnsuspendCamera::Call
// EA  : 0x82D188F8
// RVA : 0x00D188F8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idCinematicCamera::InternalActivate_::_37_::idSWFScriptFunction_UnsuspendCamera::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int num; // r11
  bool v5; // r31

  num = thisObject->variables.num;
  if ( *(_BYTE *)(num + 1029) != 0
    && *(_BYTE *)(num + 1030) != 0
    && gameLocal->spawnIds.ptr[*(_DWORD *)(num + 800) & 0x1FFF] == *(int *)(num + 800) >> 13 )
  {
    v5 = true;
    *(_BYTE *)(num + 1030) = 0;
  }
  else
  {
    v5 = false;
  }
  result->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: result);
  result->value.b = v5;
  result->type = SWF_VAR_BOOL;
  return result;
}


// ========================================================================
// `idCinematicCamera::InternalActivate'::`39'::idSWFScriptFunction_GetNotificationFromCamera::Call
// EA  : 0x82D189A0
// RVA : 0x00D189A0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idCinematicCamera::InternalActivate_::_39_::idSWFScriptFunction_GetNotificationFromCamera::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v4; // r30

  v4 = *(_BYTE *)(thisObject->variables.num + 1031);
  result->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: result);
  result->value.b = v4;
  result->type = SWF_VAR_BOOL;
  return result;
}


// ========================================================================
// ?GetSpline@idSlowMotionCamera@@IAAHPAVidSplinePath@@@Z
// EA  : 0x82D18B88
// RVA : 0x00D18B88
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idSlowMotionCamera::GetSpline(idSlowMotionCamera *this, idSplinePath *splinePath)
{
  int num; // r9
  int v4; // r10
  int v5; // r11
  idCurve_Spline<idVec3> *v7; // r3
  int v8; // r5
  idCurve<idVec3> *v9; // r30
  int v10; // r4
  double v11; // fp31
  int v12; // r31
  idDeclCameraTrigger::idSplineCurve v13; // [sp+50h] [-40h] BYREF

  num = this->splines.num;
  v4 = 0;
  if ( num > 0 )
  {
    v5 = 0;
    do
    {
      if ( this->splines.list[v5].splinePath == splinePath )
        break;
      ++v4;
      ++v5;
    }
    while ( v4 < num );
  }
  if ( v4 < num )
    return v4;
  v13.splinePath = splinePath;
  v13.lastOrigin = vec3_origin;
  v7 = idSplinePath::AllocSpline(this: splinePath);
  v8 = v7->values.num;
  v9 = v7;
  v13.curve = v7;
  v10 = 0;
  v11 = 0.0;
  v13.length = 0.0;
  if ( v8 - 1 > 0 )
  {
    do
    {
      v12 = v10 + 1;
      v11 = (float)(idCurve<idVec3>::GetLengthBetweenKnots(this: v9, i0: v10, i1: v10 + 1) + (float)v11);
      v10 = v12;
    }
    while ( v12 < v9->values.num - 1 );
    v13.length = v11;
  }
  idCurve<idVec3>::SetConstantSpeed(this: v9, totalTime: v11);
  idList<idDeclCameraTrigger::idSplineCurve,5>::Append(this: &this->splines, obj: &v13);
  return this->splines.num - 1;
}


// ========================================================================
// ?Trigger_Movement@idSlowMotionCamera@@IAAXAAVidTrigMovement@idDeclCameraTrigger@@H@Z
// EA  : 0x82D18C90
// RVA : 0x00D18C90
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idSlowMotionCamera::Trigger_Movement(
        idSlowMotionCamera *this,
        idDeclCameraTrigger::idTrigMovement *movement,
        int startTimeOfs)
{
  idDeclCameraTrigger::idCameraTriggerState *p_current; // r30

  if ( movement->moveType != CAM_MOVE_NONE )
  {
    p_current = &this->current;
    idDeclCameraTrigger::idTrigMovement::operator=(this: &this->previous.movement, __that: &this->current.movement);
    idDeclCameraTrigger::idTrigMovement::operator=(this: &p_current->movement, __that: movement);
    this->current.movement.viewOrigin.x = this->previous.movement.viewOrigin.x;
    this->current.movement.viewOrigin.y = this->previous.movement.viewOrigin.y;
    this->current.movement.viewOrigin.z = this->previous.movement.viewOrigin.z;
    if ( this->current.movement.moveType == CAM_MOVE_SPLINE )
      this->current.movement.spline.sc = idSlowMotionCamera::GetSpline(
                                           this,
                                           splinePath: this->current.movement.spline.path);
    this->current.movement.timing.startTimeOfs = startTimeOfs;
    this->current.movement.frameLerp.startTimeOfs = startTimeOfs;
  }
}


// ========================================================================
// ?Trigger_Focus@idSlowMotionCamera@@IAAXAAVidTrigFocus@idDeclCameraTrigger@@H@Z
// EA  : 0x82D18D18
// RVA : 0x00D18D18
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idSlowMotionCamera::Trigger_Focus(
        idSlowMotionCamera *this,
        idDeclCameraTrigger::idTrigFocus *focus,
        int startTimeOfs)
{
  idDeclCameraTrigger::idTrigFocus *p_focus; // r30
  idDeclCameraTrigger::cam_focus_t focusType; // r11
  idEntity *v8; // r3
  idPhysics *Physics; // r3
  float *v10; // r3

  if ( focus->focusType != CAM_FOCUS_NONE )
  {
    p_focus = &this->current.focus;
    idDeclCameraTrigger::idTrigFocus::operator=(this: &this->previous.focus, __that: &this->current.focus);
    idDeclCameraTrigger::idTrigFocus::operator=(this: p_focus, __that: focus);
    this->current.focus.viewAxis.mat[0].x = this->previous.focus.viewAxis.mat[0].x;
    this->current.focus.viewAxis.mat[0].y = this->previous.focus.viewAxis.mat[0].y;
    this->current.focus.viewAxis.mat[0].z = this->previous.focus.viewAxis.mat[0].z;
    this->current.focus.viewAxis.mat[1].x = this->previous.focus.viewAxis.mat[1].x;
    this->current.focus.viewAxis.mat[1].y = this->previous.focus.viewAxis.mat[1].y;
    this->current.focus.viewAxis.mat[1].z = this->previous.focus.viewAxis.mat[1].z;
    this->current.focus.viewAxis.mat[2].x = this->previous.focus.viewAxis.mat[2].x;
    this->current.focus.viewAxis.mat[2].y = this->previous.focus.viewAxis.mat[2].y;
    this->current.focus.viewAxis.mat[2].z = this->previous.focus.viewAxis.mat[2].z;
    focusType = this->current.focus.focusType;
    if ( focusType == CAM_FOCUS_SPLINE )
    {
      this->current.focus.spline.sc = idSlowMotionCamera::GetSpline(this, splinePath: this->current.focus.spline.path);
      this->current.focus.frameLerp.startTimeOfs = startTimeOfs;
      return;
    }
    if ( focusType == CAM_FOCUS_ENTITY )
    {
      v8 = idEntityPtr<idEntity const>::operator->(this: &this->current.focus.entity);
      if ( v8 != nullptr )
      {
        Physics = idEntity::GetPhysics(this: v8);
        v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        this->current.focus.lastKnownPosition.x = *v10;
        this->current.focus.lastKnownPosition.y = v10[1];
        this->current.focus.lastKnownPosition.z = v10[2];
        this->current.focus.frameLerp.startTimeOfs = startTimeOfs;
        return;
      }
      p_focus->focusType = CAM_FOCUS_POSITION;
      this->current.focus.position.x = this->current.focus.lastKnownPosition.x;
      this->current.focus.position.y = this->current.focus.lastKnownPosition.y;
      this->current.focus.position.z = this->current.focus.lastKnownPosition.z;
    }
    this->current.focus.frameLerp.startTimeOfs = startTimeOfs;
  }
}


// ========================================================================
// `idSlowMotionCamera::InternalActivate'::`28'::idSWFScriptFunction_UnsuspendCamera::Call
// EA  : 0x82D18E50
// RVA : 0x00D18E50
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idSlowMotionCamera::InternalActivate_::_28_::idSWFScriptFunction_UnsuspendCamera::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int num; // r11
  bool v5; // r31

  num = thisObject->variables.num;
  if ( *(_BYTE *)(num + 1024) != 0
    && *(_BYTE *)(num + 1025) != 0
    && gameLocal->spawnIds.ptr[*(_DWORD *)(num + 800) & 0x1FFF] == *(int *)(num + 800) >> 13 )
  {
    v5 = true;
    *(_BYTE *)(num + 1025) = 0;
  }
  else
  {
    v5 = false;
  }
  result->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: result);
  result->value.b = v5;
  result->type = SWF_VAR_BOOL;
  return result;
}


// ========================================================================
// `idSlowMotionCamera::InternalActivate'::`30'::idSWFScriptFunction_GetNotificationFromCamera::Call
// EA  : 0x82D18EF8
// RVA : 0x00D18EF8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idSlowMotionCamera::InternalActivate_::_30_::idSWFScriptFunction_GetNotificationFromCamera::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v4; // r30

  v4 = *(_BYTE *)(thisObject->variables.num + 1026);
  result->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: result);
  result->value.b = v4;
  result->type = SWF_VAR_BOOL;
  return result;
}


// ========================================================================
// ?ControlReleased@idOnlineVehicleDeathCameraPresentable@@UAAXXZ
// EA  : 0x82D18F50
// RVA : 0x00D18F50
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idOnlineVehicleDeathCameraPresentable::ControlReleased(idOnlineVehicleDeathCameraPresentable *this)
{
  idOnlineVehicleDeathCamera *v1; // r3

  this->attackerPresentable.spawnId = 0;
  v1 = idOnlineVehicleDeathCamera::CastTo(c: (idOnlineVehicleDeathCamera *)this->entity);
  if ( v1 != nullptr )
    idCamera::Deactivate(this: v1);
}


// ========================================================================
// ?EvaluateTriggers@idSlowMotionCamera@@IAAXMM@Z
// EA  : 0x82D19048
// RVA : 0x00D19048
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idSlowMotionCamera::EvaluateTriggers(idSlowMotionCamera *this, double startTime, double endTime)
{
  int v5; // r28
  int v6; // r30
  idDeclCameraTrigger::idCameraTriggerParms *v7; // r11
  idDeclCameraTrigger::idCameraTriggerParms *v8; // r5
  float *p_z; // r10
  idDeclCameraTrigger::idCameraTriggerParms *v10; // r11
  int i; // ctr
  double v12; // fp13
  bool *p_timeScaleFade; // r10
  bool *v14; // r9
  int j; // ctr
  bool *v16; // r10
  bool *v17; // r11
  int k; // ctr
  double scale; // fp0
  int v20; // r6
  float *p_initScale; // r10
  float *v22; // r11
  int m; // ctr
  idDeclCameraTrigger::idCameraTriggerParms *v24; // r11
  float *v25; // r10
  int n; // ctr
  idDeclCameraTrigger::idCameraTriggerParms *v27; // r11
  int v28; // r9
  int v29; // r8
  int v30; // r7
  __int64 v31; // r6
  idDeclCameraTrigger::idCameraTriggerParms *v32; // r10
  idDeclCameraTrigger::cam_showhud_t showHud; // r11
  int v34; // [sp+8h] [-A8h]
  __int64 v35; // [sp+10h] [-A0h]
  __int64 v36; // [sp+18h] [-98h]
  __int64 v37; // [sp+20h] [-90h]
  __int64 v38; // [sp+28h] [-88h]
  __int64 v39; // [sp+30h] [-80h]

  v5 = 0;
  if ( this->triggers.num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = &this->triggers.list[v6];
      if ( !v7->triggered && v7->offsetTime <= startTime )
      {
        v7->triggered = true;
        idCinematicCamera::Trigger_ActivateEnt(
          this,
          activateEnt: &this->triggers.list[v6].activate,
          startTimeOfs: (int)(float)(this->triggers.list[v6].offsetTime * (float)1000.0));
        idSlowMotionCamera::Trigger_Movement(
          this,
          movement: &this->triggers.list[v6].movement,
          startTimeOfs: (int)(float)(this->triggers.list[v6].offsetTime * (float)1000.0));
        idSlowMotionCamera::Trigger_Focus(
          this,
          focus: &this->triggers.list[v6].focus,
          startTimeOfs: (int)(float)(this->triggers.list[v6].offsetTime * (float)1000.0));
        v8 = &this->triggers.list[v6];
        if ( v8->fade.transTime >= 0.0 )
        {
          p_z = &this->current.focus.lastKnownPosition.z;
          v10 = (idDeclCameraTrigger::idCameraTriggerParms *)&v8->focus.lastKnownPosition.z;
          for ( i = 6; i != 0; --i )
          {
            v10 = (idDeclCameraTrigger::idCameraTriggerParms *)((char *)v10 + 4);
            *++p_z = *(float *)&v10->title.len;
          }
          this->current.fade.activate = true;
        }
        v12 = (float)(v8->offsetTime * (float)1000.0);
        if ( v8->timeScale.timing.duration >= 0.0 )
        {
          p_timeScaleFade = &this->current.fade.timeScaleFade;
          v14 = &this->previous.fade.timeScaleFade;
          for ( j = 7; j != 0; --j )
          {
            p_timeScaleFade += 4;
            v14 += 4;
            *(_DWORD *)v14 = *(_DWORD *)p_timeScaleFade;
          }
          v16 = &v8->fade.timeScaleFade;
          v17 = &this->current.fade.timeScaleFade;
          for ( k = 7; k != 0; --k )
          {
            v16 += 4;
            v17 += 4;
            *(_DWORD *)v17 = *(_DWORD *)v16;
          }
          scale = this->previous.timeScale.scale;
          this->current.timeScale.timing.startTimeOfs = (int)v12;
          this->current.timeScale.initScale = scale;
        }
        v20 = (int)(float)(v8->offsetTime * (float)1000.0);
        if ( v8->fovZoom.timing.duration >= 0.0 )
        {
          p_initScale = &this->previous.timeScale.initScale;
          v22 = &this->current.timeScale.initScale;
          for ( m = 6; m != 0; --m )
            *++p_initScale = *++v22;
          v24 = (idDeclCameraTrigger::idCameraTriggerParms *)&v8->timeScale.initScale;
          v25 = &this->current.timeScale.initScale;
          for ( n = 6; n != 0; --n )
          {
            v24 = (idDeclCameraTrigger::idCameraTriggerParms *)((char *)v24 + 4);
            *++v25 = *(float *)&v24->title.len;
          }
          this->current.fovZoom.timing.startTimeOfs = v20;
        }
        idSlowMotionCamera::Trigger_Sounds(
          this,
          sounds: &v8->sounds,
          startTimeOfs: (int)(float)(v8->offsetTime * (float)1000.0));
        idSlowMotionCamera::Trigger_DepthOfField(
          this,
          dof: &this->triggers.list[v6].depthOfField,
          startTimeOfs: (int)(float)(this->triggers.list[v6].offsetTime * (float)1000.0));
        v27 = &this->triggers.list[v6];
        if ( v27->shakeView.shakeVolume >= 0.0 )
        {
          this->current.shakeView.shakeVolume = v27->shakeView.shakeVolume;
          *(_DWORD *)&this->current.shakeView.activate = *(_DWORD *)&v27->shakeView.activate;
        }
        idSlowMotionCamera::Trigger_RenderParms(
          this,
          renderParms: &v27->renderParms,
          startTimeOfs: (int)(float)(v27->offsetTime * (float)1000.0));
        v32 = &this->triggers.list[v6];
        if ( v32->misc.notifyGUI )
          this->guiNotificationPending = true;
        if ( v32->misc.suspendCamera )
          this->suspended = true;
        showHud = v32->misc.showHud;
        if ( showHud == CAM_SHOWHUD_NO )
        {
          this->showPlayerHud = false;
        }
        else if ( showHud == CAM_SHOWHUD_YES )
        {
          this->showPlayerHud = true;
        }
        if ( v32->misc.endCinematic )
        {
          *(float *)&v31 = idColor::colorBlack.a;
          idSlowMotionCamera::CinematicDone(
            this: (idSlowMotionCamera *)LODWORD(idColor::colorBlack.r),
            color: v31,
            a3: v30,
            a4: v29,
            a5: v28,
            a6: (int)v32,
            a7: v34,
            a8: v35,
            a9: v36,
            a10: v37,
            a11: v38,
            a12: v39);
        }
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->triggers.num );
  }
}


// ========================================================================
// ?GetSpline@idCinematicCamera@@QAAHPAVidSplinePath@@@Z
// EA  : 0x82D19508
// RVA : 0x00D19508
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idCinematicCamera::GetSpline(idCinematicCamera *this, idSplinePath *splinePath)
{
  int v4; // r30
  idGameLocal *v5; // r10
  int v6; // r31
  int value; // r9
  idSplinePath *v8; // r3
  idSplinePath *v9; // r3
  idCurve_Spline<idVec3> *v11; // r3
  int num; // r10
  idCurve<idVec3> *v13; // r30
  int v14; // r4
  double v15; // fp31
  int v16; // r31
  idCinematicCamera::splineCurve_t v17; // [sp+50h] [-50h] BYREF

  v4 = 0;
  v5 = gameLocal;
  if ( this->splines.num > 0 )
  {
    v6 = 0;
    do
    {
      value = this->splines.list[v6].splinePath.spawnId.value;
      if ( v5->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v8 = (idSplinePath *)v5->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v9 = idSplinePath::CastTo(c: v8);
        v5 = gameLocal;
      }
      else
      {
        v9 = nullptr;
      }
      if ( v9 == splinePath )
        break;
      ++v4;
      ++v6;
    }
    while ( v4 < this->splines.num );
  }
  if ( v4 < this->splines.num )
    return v4;
  v17.lastOrigin = vec3_origin;
  if ( splinePath != nullptr )
    v17.splinePath.spawnId.value = (v5->spawnIds.ptr[splinePath->entityNumber] << 13) | splinePath->entityNumber;
  else
    v17.splinePath.spawnId.value = 0x1FFF;
  v11 = idSplinePath::AllocSpline(this: splinePath);
  num = v11->values.num;
  v13 = v11;
  v17.curve = v11;
  v14 = 0;
  v15 = 0.0;
  v17.length = 0.0;
  if ( num - 1 > 0 )
  {
    do
    {
      v16 = v14 + 1;
      v15 = (float)(idCurve<idVec3>::GetLengthBetweenKnots(this: v13, i0: v14, i1: v14 + 1) + (float)v15);
      v14 = v16;
    }
    while ( v16 < v13->values.num - 1 );
    v17.length = v15;
  }
  idCurve<idVec3>::SetConstantSpeed(this: v13, totalTime: v15);
  idList<idCinematicCamera::splineCurve_t,5>::Append(this: &this->splines, obj: &v17);
  return this->splines.num - 1;
}


// ========================================================================
// ?Trigger_Movement@idCinematicCamera@@QAAXAAUtrigMovement_t@1@H@Z
// EA  : 0x82D19698
// RVA : 0x00D19698
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idCinematicCamera::Trigger_Movement(
        idCinematicCamera *this,
        idCinematicCamera::trigMovement_t *movement,
        __int64 startTimeOfs,
        __int64 a4,
        __int64 a5)
{
  int v7; // r24
  va *v8; // r3
  int value; // r9
  idSplinePath *v10; // r3
  idSplinePath *v11; // r4
  idSplinePath *v12; // r3
  idPlayer *Player; // r3
  int v14; // [sp+8h] [-10E8h]
  int v15; // [sp+Ch] [-10E4h]
  int v16; // [sp+10h] [-10E0h]
  int v17; // [sp+14h] [-10DCh]
  int v18; // [sp+18h] [-10D8h]
  int v19; // [sp+1Ch] [-10D4h]
  idStr v20; // [sp+60h] [-1090h] BYREF
  _DWORD v21[8]; // [sp+80h] [-1070h] BYREF
  va v22; // [sp+A0h] [-1050h] BYREF

  v7 = HIDWORD(startTimeOfs);
  if ( movement->moveType != CAM_MOVE_NONE )
  {
    LODWORD(a5) = v20.baseBuffer;
    v20.len = 0;
    v20.allocedAndFlag = 20;
    v20.data = v20.baseBuffer;
    v20.baseBuffer[0] = 0;
    if ( cine_cam_debug.valueInteger != 0 )
    {
      v8 = va::va(
             this: &v22,
             fmt: "TRIG: %d Movement .. ",
             a3: startTimeOfs,
             a4,
             a5,
             a6: v14,
             a7: v15,
             a8: v16,
             a9: v17,
             a10: v18,
             a11: v19);
      idStr::Append(this: &v20, text: v8);
      v21[2] = "POSITION";
      v21[0] = "NONE";
      v21[3] = "ENTITY";
      v21[1] = "SPLINE";
      v21[4] = "PLAYER";
      idStr::Append(this: &v20, text: (char *)v21[movement->moveType]);
    }
    idCinematicCamera::trigMovement_t::operator=(this: &this->previous.movement, __that: &this->current.movement);
    idCinematicCamera::trigMovement_t::operator=(this: &this->current.movement, __that: movement);
    if ( this->current.movement.moveType == CAM_MOVE_SPLINE )
    {
      value = this->current.movement.spline.path.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v10 = (idSplinePath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v11 = idSplinePath::CastTo(c: v10);
      }
      else
      {
        v11 = nullptr;
      }
      this->current.movement.spline.sc = idCinematicCamera::GetSpline(this, splinePath: v11);
      if ( cine_cam_debug.valueInteger != 0 )
      {
        idStr::Append(this: &v20, text: " .. ");
        v12 = idEntityPtr<idSplinePath>::operator idSplinePath *(this: &this->current.movement.spline.path);
        idStr::Append(this: &v20, text: v12->name.data);
      }
    }
    if ( this->current.movement.moveType == CAM_MOVE_PLAYER )
    {
      Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
      if ( Player != nullptr )
        this->current.movement.entity.spawnId.value = (gameLocal->spawnIds.ptr[Player->entityNumber] << 13)
                                                    | Player->entityNumber;
      else
        this->current.movement.entity.spawnId.value = 0x1FFF;
    }
    this->current.movement.startTimeOfs = v7;
    this->current.movement.lastTrigTime = -1.0;
    if ( cine_cam_debug.valueInteger != 0 )
    {
      idStr::Append(this: &v20, text: "\n");
      idLib::Printf(fmt: "%s", v20.data);
    }
    idStr::FreeData(this: &v20);
  }
}


// ========================================================================
// __unwind$530484
// EA  : 0x82D198BC
// RVA : 0x00D198BC
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_530484()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 96));
}


// ========================================================================
// ?Trigger_Focus@idCinematicCamera@@QAAXAAUtrigFocus_t@1@H@Z
// EA  : 0x82D198F0
// RVA : 0x00D198F0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idCinematicCamera::Trigger_Focus(
        idCinematicCamera *this,
        idCinematicCamera::trigFocus_t *focus,
        __int64 startTimeOfs,
        __int64 a4)
{
  int v6; // r25
  __int64 v7; // r10
  va *v8; // r3
  idCinematicCamera::cam_focus_t focusType; // r11
  idSplinePath *v10; // r3
  idSplinePath *v11; // r3
  idEntityPtr<idEntity> *p_entity; // r30
  idEntity *v13; // r3
  idVehicleAI *v14; // r3
  idVehicleAI *v15; // r3
  idVehicle_Car *Owner; // r3
  idEntity *v17; // r3
  idPlayer *DebugPlayer; // r3
  idEntity *v19; // r3
  idPlayer *Player; // r3
  int v21; // [sp+8h] [-10D8h]
  int v22; // [sp+Ch] [-10D4h]
  int v23; // [sp+10h] [-10D0h]
  int v24; // [sp+14h] [-10CCh]
  int v25; // [sp+18h] [-10C8h]
  int v26; // [sp+1Ch] [-10C4h]
  idStr v27; // [sp+60h] [-1080h] BYREF
  _DWORD v28[8]; // [sp+80h] [-1060h] BYREF
  va v29; // [sp+A0h] [-1040h] BYREF

  v6 = HIDWORD(startTimeOfs);
  if ( focus->focusType != 0 )
  {
    LODWORD(v7) = 20;
    HIDWORD(v7) = v27.baseBuffer;
    v27.len = 0;
    v27.allocedAndFlag = 20;
    v27.data = v27.baseBuffer;
    v27.baseBuffer[0] = 0;
    if ( cine_cam_debug.valueInteger != 0 )
    {
      v8 = va::va(
             this: &v29,
             fmt: "TRIG: %d Focus .. ",
             a3: startTimeOfs,
             a4,
             a5: v7,
             a6: v21,
             a7: v22,
             a8: v23,
             a9: v24,
             a10: v25,
             a11: v26);
      idStr::Append(this: &v27, text: v8);
      v28[0] = "NONE";
      v28[2] = "SPLINE";
      v28[4] = "POSITION";
      v28[1] = "MOVEPATH";
      v28[3] = "ENTITY";
      v28[5] = "PLAYER VIEW";
      idStr::Append(this: &v27, text: (char *)v28[focus->focusType]);
    }
    idCinematicCamera::trigFocus_t::operator=(this: &this->previous.focus, __that: &this->current.focus);
    idCinematicCamera::trigFocus_t::operator=(this: &this->current.focus, __that: focus);
    focusType = this->current.focus.focusType;
    switch ( focusType )
    {
      case 2:
        if ( gameLocal->spawnIds.ptr[this->current.focus.spline.path.spawnId.value & 0x1FFF] == this->current.focus.spline.path.spawnId.value >> 13 )
        {
          v10 = idEntityPtr<idSplinePath>::operator idSplinePath *(this: &this->current.focus.spline.path);
          this->current.focus.spline.sc = idCinematicCamera::GetSpline(this, splinePath: v10);
          if ( cine_cam_debug.valueInteger != 0 )
          {
            idStr::Append(this: &v27, text: " .. ");
            v11 = idEntityPtr<idSplinePath>::operator idSplinePath *(this: &this->current.focus.spline.path);
            idStr::Append(this: &v27, text: v11->name.data);
          }
        }
        break;
      case 3:
        p_entity = &this->current.focus.entity;
        v13 = idEntityPtr<idEntity const>::operator->(this: &this->current.focus.entity);
        if ( (unsigned __int8)idClass::IsType(this: v13, superclass: &idVehicleAI::Type) != 0 )
        {
          v14 = (idVehicleAI *)idEntityPtr<idEntity const>::operator->(this: &this->current.focus.entity);
          v15 = idVehicleAI::CastTo(c: v14);
          Owner = idVehicleAI::GetOwner(this: v15);
          if ( Owner != nullptr )
            p_entity->spawnId.value = (gameLocal->spawnIds.ptr[Owner->entityNumber] << 13) | Owner->entityNumber;
          else
            p_entity->spawnId.value = 0x1FFF;
        }
        v17 = idEntityPtr<idEntity const>::operator->(this: &this->current.focus.entity);
        if ( (unsigned __int8)idClass::IsType(this: v17, superclass: &idPlayerStart::Type) != 0 )
        {
          DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
          if ( DebugPlayer != nullptr )
            p_entity->spawnId.value = (gameLocal->spawnIds.ptr[DebugPlayer->entityNumber] << 13)
                                    | DebugPlayer->entityNumber;
          else
            p_entity->spawnId.value = 0x1FFF;
        }
        if ( cine_cam_debug.valueInteger != 0 )
        {
          idStr::Append(this: &v27, text: " .. ");
          v19 = idEntityPtr<idEntity const>::operator->(this: &this->current.focus.entity);
          idStr::Append(this: &v27, text: v19->name.data);
        }
        break;
      case 5:
        Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
        if ( Player != nullptr )
          this->current.focus.entity.spawnId.value = (gameLocal->spawnIds.ptr[Player->entityNumber] << 13)
                                                   | Player->entityNumber;
        else
          this->current.focus.entity.spawnId.value = 0x1FFF;
        break;
      default:
        break;
    }
    this->current.focus.startTimeOfs = v6;
    if ( cine_cam_debug.valueInteger != 0 )
    {
      idStr::Append(this: &v27, text: "\n");
      idLib::Printf(fmt: "%s", v27.data);
    }
    idStr::FreeData(this: &v27);
  }
}


// ========================================================================
// __unwind$530663
// EA  : 0x82D19C14
// RVA : 0x00D19C14
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_530663()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 96));
}


// ========================================================================
// ?Think@idSlowMotionCamera@@UAAXXZ
// EA  : 0x82D19C40
// RVA : 0x00D19C40
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSlowMotionCamera::Think(idSlowMotionCamera *this, int a2, __int64 a3)
{
  __int64 v4; // r8
  __int64 v5; // fp12
  int v6; // r5
  int v7; // r7
  __int64 v8; // r6
  long double v9; // fp2
  idDeclCameraTrigger::idSplineCurve *list; // r9
  int sc; // r11
  double length; // fp0
  double v13; // fp13
  double TimeLerpFraction; // fp1
  idDeclCameraTrigger::idSplineCurve *v15; // r9
  int v16; // r11
  double v17; // fp0
  double v18; // fp13
  int currentTime; // r9
  int v20; // r8
  idPhysics *Physics; // r3
  int v22; // [sp+8h] [-68h]
  __int64 v23; // [sp+10h] [-60h]
  __int64 v24; // [sp+18h] [-58h]
  __int64 v25; // [sp+20h] [-50h]
  __int64 v26; // [sp+28h] [-48h]
  __int64 v27; // [sp+30h] [-40h]

  if ( this->active && !this->suspended )
  {
    LODWORD(v4) = this->startTime;
    HIDWORD(v4) = this->currentTime;
    LODWORD(a3) = this->totalTime;
    v5 = a3;
    v6 = HIDWORD(v4);
    idSlowMotionCamera::EvaluateTriggers(
      this,
      startTime: (float)((float)((float)*(__int64 *)(&a2 - 1) - (float)v4) * (float)0.001),
      endTime: (float)((float)v5 * (float)0.001));
    if ( this->current.timeScale.scale > 0.0 )
      idSlowMotionCamera::AdjustTiming(this, a2: v9, a3: 0x82000000, a4: v8);
    if ( this->current.movement.moveType == CAM_MOVE_SPLINE )
    {
      *(double *)&v9 = idSlowMotionCamera::GetTimeLerpFraction(this, timeLerpHelper: v8, a3: v9);
      list = this->splines.list;
      sc = this->current.movement.spline.sc;
      length = list[sc].length;
      v13 = (float)(list[sc].length * (float)*(double *)&v9);
      if ( v13 >= 0.0 )
      {
        if ( v13 <= length )
          length = (float)(list[sc].length * (float)*(double *)&v9);
      }
      else
      {
        length = 0.0;
      }
      this->current.movement.spline.dist = length;
    }
    if ( this->current.focus.focusType == CAM_FOCUS_SPLINE )
    {
      TimeLerpFraction = idSlowMotionCamera::GetTimeLerpFraction(this, timeLerpHelper: v8, a3: v9);
      v15 = this->splines.list;
      v16 = this->current.focus.spline.sc;
      v17 = v15[v16].length;
      v18 = (float)(v15[v16].length * (float)TimeLerpFraction);
      if ( v18 >= 0.0 )
      {
        if ( v18 <= v17 )
          v17 = (float)(v15[v16].length * (float)TimeLerpFraction);
      }
      else
      {
        v17 = 0.0;
      }
      this->current.focus.spline.dist = v17;
    }
    currentTime = this->currentTime;
    v20 = this->startTime + this->totalTime;
    if ( currentTime >= v20 )
    {
      *(float *)&v8 = idColor::colorBlack.a;
      idSlowMotionCamera::CinematicDone(
        this: (idSlowMotionCamera *)LODWORD(idColor::colorBlack.r),
        color: v8,
        a3: v7,
        a4: v20,
        a5: currentTime,
        a6: (int)&idColor::colorBlack,
        a7: v22,
        a8: v23,
        a9: v24,
        a10: v25,
        a11: v26,
        a12: v27);
    }
    Physics = idEntity::GetPhysics(this);
    Physics->SetOrigin(this: Physics, a2: &this->current.movement.viewOrigin, a3: -1);
    this->currentTime += gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_NORMAL);
  }
}


// ========================================================================
// ?EvaluateTriggers@idCinematicCamera@@QAAXMM@Z
// EA  : 0x82D19EF0
// RVA : 0x00D19EF0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idCinematicCamera::EvaluateTriggers(idCinematicCamera *this, double startTime, double endTime)
{
  int v6; // r28
  int v7; // r30
  idCinematicCamera::trigger_t *v8; // r11
  double time; // fp0
  idCinematicCamera::trigger_t *v10; // r11
  __int64 v11; // r6
  __int64 v12; // r10
  __int64 v13; // r8
  idCinematicCamera::trigger_t *v14; // r11
  __int64 v15; // r6
  __int64 v16; // r8
  idCinematicCamera::trigger_t *v17; // r11
  float *p_totalFocusTime; // r9
  idCinematicCamera::trigger_t *v19; // r10
  int i; // ctr
  double v21; // fp13
  int startTimeOfs; // r8
  float transTime; // r9
  int v24; // r10
  float angle; // r8
  float v26; // r7
  idCinematicCamera::trigger_t *v27; // r11
  int v28; // r9
  int v29; // r8
  int v30; // r7
  __int64 v31; // r6
  idCinematicCamera::trigger_t *v32; // r11
  idCinematicCamera::cam_showhud_t showHud; // r10
  idPresentablePlayer::playerGuis_t playerGui; // r11
  int v35; // [sp+8h] [-A8h]
  __int64 v36; // [sp+10h] [-A0h]
  __int64 v37; // [sp+18h] [-98h]
  __int64 v38; // [sp+20h] [-90h]
  __int64 v39; // [sp+28h] [-88h]
  __int64 v40; // [sp+30h] [-80h]

  v6 = 0;
  if ( this->triggers.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = &this->triggers.list[v7];
      time = v8->time;
      if ( time >= startTime && time <= endTime )
      {
        idCinematicCamera::Trigger_ActivateEnt(
          (idSlowMotionCamera *)this,
          activateEnt: (idDeclCameraTrigger::idTrigActivateEnt *)&v8->activate,
          startTimeOfs: (int)(float)(v8->time * (float)1000.0));
        v10 = &this->triggers.list[v7];
        HIDWORD(v11) = (int)(float)(v10->time * (float)1000.0);
        idCinematicCamera::Trigger_Movement(this, movement: &v10->movement, startTimeOfs: v11, a4: v13, a5: v12);
        v14 = &this->triggers.list[v7];
        HIDWORD(v15) = (int)(float)(v14->time * (float)1000.0);
        idCinematicCamera::Trigger_Focus(this, focus: &v14->focus, startTimeOfs: v15, a4: v16);
        v17 = &this->triggers.list[v7];
        if ( v17->fade.transTime >= 0.0 )
        {
          p_totalFocusTime = &this->current.focus.totalFocusTime;
          v19 = (idCinematicCamera::trigger_t *)&v17->focus.totalFocusTime;
          for ( i = 6; i != 0; --i )
          {
            v19 = (idCinematicCamera::trigger_t *)((char *)v19 + 4);
            *++p_totalFocusTime = *(float *)&v19->title.len;
          }
          this->current.fade.activate = true;
        }
        v21 = (float)(v17->time * (float)1000.0);
        if ( v17->timeScale.transTime >= 0.0 )
        {
          startTimeOfs = this->current.timeScale.startTimeOfs;
          transTime = this->current.timeScale.transTime;
          this->previous.timeScale.scale = this->current.timeScale.scale;
          this->previous.timeScale.startTimeOfs = startTimeOfs;
          this->previous.timeScale.transTime = transTime;
          this->current.timeScale.scale = v17->timeScale.scale;
          this->current.timeScale.transTime = v17->timeScale.transTime;
          this->current.timeScale.startTimeOfs = v17->timeScale.startTimeOfs;
          this->current.timeScale.startTimeOfs = (int)v21;
        }
        v24 = (int)(float)(v17->time * (float)1000.0);
        if ( v17->fovZoom.transTime >= 0.0 )
        {
          angle = this->current.fovZoom.angle;
          v26 = this->current.fovZoom.transTime;
          this->previous.fovZoom.startTimeOfs = this->current.fovZoom.startTimeOfs;
          this->previous.fovZoom.angle = angle;
          this->previous.fovZoom.transTime = v26;
          this->current.fovZoom.angle = v17->fovZoom.angle;
          this->current.fovZoom.transTime = v17->fovZoom.transTime;
          this->current.fovZoom.startTimeOfs = v17->fovZoom.startTimeOfs;
          this->current.fovZoom.startTimeOfs = v24;
        }
        idCinematicCamera::Trigger_Sounds(
          this,
          sounds: &v17->sounds,
          startTimeOfs: (int)(float)(v17->time * (float)1000.0));
        idCinematicCamera::Trigger_DepthOfField(
          this,
          dof: &this->triggers.list[v7].depthOfField,
          startTimeOfs: (int)(float)(this->triggers.list[v7].time * (float)1000.0));
        v27 = &this->triggers.list[v7];
        if ( v27->shakeView.shakeVolume >= 0.0 )
        {
          this->current.shakeView.shakeVolume = v27->shakeView.shakeVolume;
          *(_DWORD *)&this->current.shakeView.activate = *(_DWORD *)&v27->shakeView.activate;
        }
        idCinematicCamera::Trigger_RenderParms(
          this,
          renderParms: &v27->renderParms,
          startTimeOfs: (int)(float)(v27->time * (float)1000.0));
        v32 = &this->triggers.list[v7];
        if ( v32->misc.notifyGUI )
          this->guiNotificationPending = true;
        if ( v32->misc.suspendCamera )
          this->suspended = true;
        showHud = v32->misc.showHud;
        if ( showHud == CAM_SHOWHUD_NO )
        {
          this->showPlayerHud = false;
        }
        else if ( showHud == CAM_SHOWHUD_YES )
        {
          this->showPlayerHud = true;
        }
        if ( v32->misc.endCinematic )
        {
          *(float *)&v31 = idColor::colorBlack.a;
          idCinematicCamera::CinematicDone(
            this: (idCinematicCamera *)LODWORD(idColor::colorBlack.r),
            color: v31,
            a3: v30,
            a4: v29,
            a5: v28,
            a6: v32->misc.endCinematic,
            a7: v35,
            a8: v36,
            a9: v37,
            a10: v38,
            a11: v39,
            a12: v40);
        }
        else
        {
          playerGui = v32->misc.playerGui;
          if ( playerGui != (GUI_TUTORIAL|GUI_JOBOFFER) )
            this->playerGui = playerGui;
        }
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->triggers.num );
  }
}


// ========================================================================
// ??0idSlowMotionCamera@@QAA@XZ
// EA  : 0x82D1A1E0
// RVA : 0x00D1A1E0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idSlowMotionCamera *__fastcall idSlowMotionCamera::idSlowMotionCamera(idSlowMotionCamera *this)
{
  idEntityCamera::idEntityCamera(this);
  this->triggerGroup = nullptr;
  this->__vftable = (idSlowMotionCamera_vtbl *)&idSlowMotionCamera::`vftable';
  this->triggers.granularity = 0;
  this->triggers.memTag = 5;
  this->triggers.listStatic = 0;
  this->triggers.list = nullptr;
  this->triggers.size = 0;
  this->triggers.num = 0;
  this->hidePlayer = false;
  this->hidePlayerHands = false;
  this->fadeInOnReturn = false;
  this->setPlayerAnglesOnReturn = false;
  this->setPlayerPositionOnReturn = false;
  this->timeScale = 1.0;
  this->startTime = -1;
  this->endTime = -1;
  this->totalTime = -1;
  this->currentTime = -1;
  this->active = false;
  this->suspended = false;
  *(_WORD *)&this->guiNotificationPending = 1;
  idDeclCameraTrigger::idCameraTriggerState::idCameraTriggerState(this: &this->current);
  idDeclCameraTrigger::idCameraTriggerState::idCameraTriggerState(this: &this->previous);
  this->prevHudState = HUDSTATE_NONE;
  this->currentTrigger = 0;
  this->splines.list = nullptr;
  this->splines.granularity = 0;
  this->splines.memTag = 5;
  this->splines.listStatic = 0;
  this->splines.size = 0;
  this->splines.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splines);
  this->activatingPlayer = nullptr;
  this->gui = nullptr;
  return this;
}


// ========================================================================
// __unwind$531245
// EA  : 0x82D1A2C8
// RVA : 0x00D1A2C8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_531245()
{
  int v0; // r12

  idEntityCamera::~idEntityCamera(this: *(idEntityCamera **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$531246
// EA  : 0x82D1A2F0
// RVA : 0x00D1A2F0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_531246()
{
  int v0; // r12

  idList<idDeclCameraTrigger::idCameraTriggerParms,5>::Clear(this: (idList<idDeclCameraTrigger::idCameraTriggerParms,5> *)(*(_DWORD *)(v0 - 128 + 148) + 980));
}


// ========================================================================
// ??1idSlowMotionCamera@@UAA@XZ
// EA  : 0x82D1A328
// RVA : 0x00D1A328
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idSlowMotionCamera::~idSlowMotionCamera(idSlowMotionCamera *this)
{
  idSWF *gui; // r29
  idDeclCameraTrigger::idCameraTriggerParms *list; // r3

  this->__vftable = (idSlowMotionCamera_vtbl *)&idSlowMotionCamera::`vftable';
  gui = this->gui;
  if ( gui != nullptr )
  {
    idSWF::~idSWF(this: this->gui);
    idMem::Free(this: &mem, ptr: gui, align: ALIGN_16);
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splines);
  if ( this->triggers.listStatic == 0 || this->triggers.listStatic == 2 )
  {
    list = this->triggers.list;
    if ( list != nullptr )
      idListArrayDelete<idDeclCameraTrigger::idCameraTriggerParms>(ptr: list, num: this->triggers.size);
    this->triggers.list = nullptr;
    this->triggers.size = 0;
  }
  this->triggers.num = 0;
  this->__vftable = (idSlowMotionCamera_vtbl *)&idCamera::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$531291
// EA  : 0x82D1A3D0
// RVA : 0x00D1A3D0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_531291()
{
  int v0; // r12

  idEntityCamera::~idEntityCamera(this: *(idEntityCamera **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$531292
// EA  : 0x82D1A3F8
// RVA : 0x00D1A3F8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_531292()
{
  int v0; // r12

  idList<idDeclCameraTrigger::idCameraTriggerParms,5>::Clear(this: (idList<idDeclCameraTrigger::idCameraTriggerParms,5> *)(*(_DWORD *)(v0 - 112 + 132) + 980));
}


// ========================================================================
// __unwind$531293
// EA  : 0x82D1A424
// RVA : 0x00D1A424
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_531293()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1860));
}


// ========================================================================
// ??0idCaptureController@@QAA@XZ
// EA  : 0x82D1A458
// RVA : 0x00D1A458
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idCaptureController *__fastcall idCaptureController::idCaptureController(idCaptureController *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idCaptureController_vtbl *)&idCaptureController::`vftable';
  this->startTriggers.list = nullptr;
  this->startTriggers.granularity = 0;
  this->startTriggers.memTag = 5;
  this->startTriggers.listStatic = 0;
  this->startTriggers.size = 0;
  this->startTriggers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->startTriggers);
  this->cameras.list = nullptr;
  this->cameras.granularity = 0;
  this->cameras.memTag = 5;
  this->cameras.listStatic = 0;
  this->cameras.size = 0;
  this->cameras.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cameras);
  this->vehicles.granularity = 0;
  this->vehicles.memTag = 5;
  this->vehicles.listStatic = 0;
  this->vehicles.list = nullptr;
  this->vehicles.size = 0;
  this->vehicles.num = 0;
  this->shots.list = nullptr;
  this->shots.granularity = 0;
  this->shots.memTag = 5;
  this->shots.listStatic = 0;
  this->shots.size = 0;
  this->shots.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->shots);
  this->continous = false;
  this->fixedTic = true;
  this->currentCamera = 0;
  this->currentVehicle = 0;
  this->currentTrigger = 0;
  this->capturing = false;
  this->currentShot = 0;
  this->shotStartTime = 0;
  return this;
}


// ========================================================================
// __unwind$531366
// EA  : 0x82D1A538
// RVA : 0x00D1A538
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_531366()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$531367
// EA  : 0x82D1A560
// RVA : 0x00D1A560
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_531367()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 800));
}


// ========================================================================
// __unwind$531368
// EA  : 0x82D1A58C
// RVA : 0x00D1A58C
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_531368()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 816));
}


// ========================================================================
// __unwind$531369
// EA  : 0x82D1A5B8
// RVA : 0x00D1A5B8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_531369()
{
  int v0; // r12

  idList<idComponentTimeLine::idTimeLineEntity,5>::~idList<idComponentTimeLine::idTimeLineEntity,5>(this: (idList<idVOChainState,5> *)(*(_DWORD *)(v0 - 128 + 148) + 832));
}


// ========================================================================
// ??0idCinematicCamera@@QAA@XZ
// EA  : 0x82D1A900
// RVA : 0x00D1A900
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idCinematicCamera *__fastcall idCinematicCamera::idCinematicCamera(idCinematicCamera *this)
{
  int v2; // ctr
  float *p_z; // r9
  float *p_y; // r10

  idEntityCamera::idEntityCamera(this);
  this->__vftable = (idCinematicCamera_vtbl *)&idCinematicCamera::`vftable';
  this->triggers.granularity = 0;
  this->triggers.memTag = 5;
  this->triggers.listStatic = 0;
  this->triggers.list = nullptr;
  this->triggers.size = 0;
  this->triggers.num = 0;
  this->hidePlayer = false;
  this->hidePlayerHands = false;
  this->looping = false;
  this->fadeInOnReturn = false;
  this->setPlayerAnglesOnReturn = true;
  this->timeScale = 1.0;
  this->setPlayerPositionOnReturn = true;
  this->doTimeScale = false;
  this->playerInvulnerableDuringCine = false;
  this->startTime = -1;
  this->endTime = -1;
  this->totalTime = -1;
  this->lastTrigTime = -1;
  this->currentTime = -1;
  this->lastThinkTime = -1;
  this->playerTakesDamageState = true;
  this->active = false;
  this->suspended = false;
  this->guiNotificationPending = false;
  this->showPlayerHud = false;
  idCinematicCamera::state_t::state_t(this: &this->current);
  idCinematicCamera::state_t::state_t(this: &this->previous);
  this->prevHudState = HUDSTATE_NONE;
  this->lastDrawTime = -1;
  this->currentTrigger = 0;
  this->playerGui = GUI_TUTORIAL|GUI_JOBOFFER;
  this->splines.list = nullptr;
  this->splines.granularity = 0;
  this->splines.memTag = 5;
  this->splines.listStatic = 0;
  this->splines.size = 0;
  this->splines.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splines);
  this->gui = nullptr;
  v2 = 9;
  p_z = &this->cameraPos.z;
  p_y = &mat2_identity.mat[1].y;
  this->cameraDOF = vec3_origin;
  this->cameraPos = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  return this;
}


// ========================================================================
// __unwind$531530
// EA  : 0x82D1AA64
// RVA : 0x00D1AA64
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_531530()
{
  int v0; // r12

  idEntityCamera::~idEntityCamera(this: *(idEntityCamera **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$531531
// EA  : 0x82D1AA8C
// RVA : 0x00D1AA8C
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_531531()
{
  int v0; // r12

  idList<idCinematicCamera::trigger_t,5>::~idList<idCinematicCamera::trigger_t,5>(this: (idList<idCinematicCamera::trigger_t,5> *)(*(_DWORD *)(v0 - 144 + 164) + 976));
}


// ========================================================================
// ??1idCinematicCamera@@UAA@XZ
// EA  : 0x82D1AAC0
// RVA : 0x00D1AAC0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __fastcall idCinematicCamera::~idCinematicCamera(idCinematicCamera *this)
{
  idSWF *gui; // r29
  idCinematicCamera::trigger_t *list; // r3

  this->__vftable = (idCinematicCamera_vtbl *)&idCinematicCamera::`vftable';
  gui = this->gui;
  if ( gui != nullptr )
  {
    idSWF::~idSWF(this: this->gui);
    idMem::Free(this: &mem, ptr: gui, align: ALIGN_16);
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splines);
  if ( this->triggers.listStatic == 0 || this->triggers.listStatic == 2 )
  {
    list = this->triggers.list;
    if ( list != nullptr )
      idListArrayDelete<idCinematicCamera::trigger_t>(ptr: list, num: this->triggers.size);
    this->triggers.list = nullptr;
    this->triggers.size = 0;
  }
  this->triggers.num = 0;
  this->__vftable = (idCinematicCamera_vtbl *)&idCamera::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$531577
// EA  : 0x82D1AB68
// RVA : 0x00D1AB68
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_531577()
{
  int v0; // r12

  idEntityCamera::~idEntityCamera(this: *(idEntityCamera **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$531578
// EA  : 0x82D1AB90
// RVA : 0x00D1AB90
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_531578()
{
  int v0; // r12

  idList<idCinematicCamera::trigger_t,5>::~idList<idCinematicCamera::trigger_t,5>(this: (idList<idCinematicCamera::trigger_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 976));
}


// ========================================================================
// __unwind$531579
// EA  : 0x82D1ABBC
// RVA : 0x00D1ABBC
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_531579()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1692));
}


// ========================================================================
// ?Think@idCinematicCamera@@UAAXXZ
// EA  : 0x82D1ABE8
// RVA : 0x00D1ABE8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCinematicCamera::Think(idCinematicCamera *this)
{
  int v2; // r30
  int v3; // r3
  long double v4; // fp2
  __int128 v5; // r7 OVERLAPPED
  int totalTime; // r11
  __int64 v7; // r9
  __int64 v8; // fp13
  double v9; // fp30
  double easeInTime; // fp13
  double v11; // fp0
  double v12; // fp0
  double v13; // fp31
  double v14; // fp13
  double v15; // fp12
  long double v16; // fp2
  idCinematicCamera::splineCurve_t *list; // r9
  int sc; // r11
  double length; // fp0
  double v20; // fp13
  idCinematicCamera::cam_move_t moveType; // r11
  double v22; // fp13
  __int64 v23; // r9
  long double v24; // fp2
  double v25; // fp31
  long double v26; // fp2
  idCinematicCamera::splineCurve_t *v27; // r11
  double v28; // fp0
  double v29; // fp13
  float *v30; // r3
  double v31; // fp12
  idEntity *v32; // r3
  idPhysics *Physics; // r3
  float *v34; // r3
  idPresentable *presentable; // r3
  float *v36; // r3
  double splineTimeOfs; // fp0
  __int64 v38; // r9
  double v39; // fp12
  long double v40; // fp2
  double v41; // fp31
  long double v42; // fp2
  int v43; // r11
  idCinematicCamera::splineCurve_t *v44; // r9
  int v45; // r11
  double v46; // fp0
  double v47; // fp13
  int v48; // r8
  double v49; // fp10
  int v50; // r30
  idPhysics *v51; // r3
  idVec3 *p_viewOrigin; // r27
  __int64 v53; // r4
  double v54; // fp18
  __int64 v55; // r9
  __int64 v56; // r6 OVERLAPPED
  idPlayer *PlayerActivator; // r3
  idPresentable *v58; // r3
  int v59; // r3
  idCinematicCamera::trigFovZoom_t *p_fovZoom; // r30
  idView *v61; // r28
  double transTime; // fp0
  __int64 v63; // r9
  int startTimeOfs; // r7
  double v65; // fp0
  double angle; // fp1
  __int64 v67; // r8 OVERLAPPED
  __int64 v68; // r6 OVERLAPPED
  long double v69; // fp2
  double z; // fp13
  double v71; // fp0
  double v72; // fp13
  int startTime; // r9
  double v74; // fp0
  double v75; // fp12
  double v76; // fp11
  double v77; // fp3
  idCinematicCamera::cam_move_t v78; // r11
  float *v79; // r3
  double x; // fp29
  double y; // fp30
  double v82; // fp31
  idEntity *v83; // r3
  idPhysics *v84; // r3
  float *v85; // r3
  idPresentable *v86; // r3
  float *v87; // r3
  double v88; // fp0
  __int64 v89; // r9
  int currentTime; // r7
  double v91; // fp0
  double v92; // fp0
  double v93; // fp22
  double v94; // fp21
  double v95; // fp20
  idCinematicCamera::cam_focus_t focusType; // r11
  double v97; // fp10
  double v98; // fp9
  double v99; // fp0
  double v100; // fp13
  double v101; // fp12
  float *v102; // r3
  idEntity *v103; // r3
  double v104; // fp13
  double v105; // fp12
  double v106; // fp13
  double v107; // fp12
  char v108; // r11
  double v109; // fp13
  double v110; // fp12
  __int64 v111; // r6 OVERLAPPED
  long double v112; // fp2
  idPresentable *v113; // r3
  float *v114; // r3
  const idMat3 *v115; // r3
  double v116; // fp0
  __int64 v117; // r9
  int v118; // r7
  double v119; // fp0
  long double v120; // fp2
  double v121; // fp31
  long double v122; // fp2
  const idQuat *v123; // r30
  const idQuat *v124; // r3
  float *v125; // r3
  double v126; // fp31
  double v127; // fp30
  double v128; // fp29
  double v129; // fp28
  double v130; // fp27
  double v131; // fp26
  double v132; // fp25
  double v133; // fp24
  double v134; // fp23
  double v135; // fp12
  double timeScale; // fp1
  int v137; // [sp+8h] [-1B8h]
  __int64 v138; // [sp+10h] [-1B0h]
  __int64 v139; // [sp+18h] [-1A8h]
  __int64 v140; // [sp+20h] [-1A0h]
  __int64 v141; // [sp+28h] [-198h]
  __int64 v142; // [sp+30h] [-190h]
  __int64 v143; // [sp+50h] [-170h] BYREF
  idMat3 v144; // [sp+60h] [-160h] BYREF
  float v145; // [sp+84h] [-13Ch]
  float v146; // [sp+88h] [-138h]
  idMat3 v147; // [sp+90h] [-130h] BYREF
  idMat3 v148; // [sp+C0h] [-100h] BYREF
  idQuat v149[9]; // [sp+F0h] [-D0h] BYREF

  if ( !this->active )
    return;
  v2 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_NORMAL) - this->lastThinkTime;
  v3 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_NORMAL);
  DWORD2(v5) = this->suspended;
  this->lastThinkTime = v3;
  if ( DWORD2(v5) != 0 )
    return;
  HIDWORD(v7) = 0x82000000;
  totalTime = this->totalTime;
  LODWORD(v7) = this->startTime;
  LODWORD(v5) = totalTime;
  DWORD2(v5) = this->currentTime + v2;
  this->currentTime = DWORD2(v5);
  v8 = *(_QWORD *)((char *)&v5 + 4);
  DWORD1(v5) = v7;
  v143 = *(_QWORD *)&v5;
  v9 = (float)((float)((float)v8 - (float)*(__int64 *)&v5) / (float)(__int64)v5);
  if ( v9 >= 1.0 )
  {
    if ( !this->looping )
    {
      DWORD1(v5) = LODWORD(idColor::colorBlack.a);
      idCinematicCamera::CinematicDone(
        this: (idCinematicCamera *)LODWORD(idColor::colorBlack.r),
        color: *(__int64 *)((char *)&v5 + 4),
        a3: totalTime,
        a4: 0x82000000,
        a5: v7,
        a6: (int)&idColor::colorBlack,
        a7: v137,
        a8: v138,
        a9: v139,
        a10: v140,
        a11: v141,
        a12: v142);
      return;
    }
    this->startTime = totalTime + v7;
    this->endTime = totalTime + v7 + totalTime;
    LODWORD(v7) = totalTime + v7;
    v143 = v7;
    v9 = (float)((float)((float)v8 - (float)v7) / (float)(__int64)v5);
  }
  if ( this->doTimeScale )
    idCinematicCamera::AdjustTiming(this, a2: *(__int64 *)((char *)&v5 + 4));
  if ( this->current.movement.moveType == CAM_MOVE_SPLINE )
  {
    easeInTime = this->current.movement.easeInTime;
    DWORD1(v5) = this->currentTime - this->current.movement.startTimeOfs - this->startTime;
    v143 = *(_QWORD *)&v5;
    v11 = (float)((float)*(__int64 *)&v5 * (float)0.001);
    if ( v11 >= easeInTime )
    {
      if ( this->current.movement.easeOutTime == 0.0
        || v11 <= (float)(this->current.movement.totalMoveTime - this->current.movement.easeOutTime)
        || v11 >= this->current.movement.totalMoveTime )
      {
        v13 = (float)((float)((float)*(__int64 *)&v5 * (float)0.001) / this->current.movement.totalMoveTime);
      }
      else
      {
        v14 = (float)(this->current.movement.easeOutTime / this->current.movement.totalMoveTime);
        v15 = (float)((float)(this->current.movement.totalMoveTime - (float)((float)*(__int64 *)&v5 * (float)0.001))
                    / this->current.movement.easeOutTime);
        v13 = (float)((float)((float)-(float)((float)((float)v15 * (float)v15) - (float)1.0) * (float)v14)
                    + (float)((float)1.0 - (float)v14));
      }
    }
    else
    {
      v12 = (float)((float)((float)*(__int64 *)&v5 * (float)0.001) / (float)easeInTime);
      v13 = (float)((float)((float)easeInTime / this->current.movement.totalMoveTime) * (float)((float)v12 * (float)v12));
    }
    *(double *)&v4 = v13;
    v16 = floor(x: v4);
    list = this->splines.list;
    sc = this->current.movement.spline.sc;
    length = list[sc].length;
    v20 = (float)(list[sc].length * (float)((float)v13 - (float)*(double *)&v16));
    if ( v20 >= 0.0 )
    {
      if ( v20 <= length )
        length = (float)(list[sc].length * (float)((float)v13 - (float)*(double *)&v16));
    }
    else
    {
      length = 0.0;
    }
    this->current.movement.spline.dist = length;
  }
  if ( !this->current.movement.haltPrevMove )
  {
    moveType = this->previous.movement.moveType;
    if ( moveType == CAM_MOVE_SPLINE )
    {
      v22 = (float)(this->previous.movement.totalMoveTime * (float)1000.0);
      LODWORD(v23) = this->currentTime;
      HIDWORD(v23) = this->previous.movement.startTimeOfs;
      LODWORD(v5) = this->startTime;
      DWORD2(v5) = HIDWORD(v23);
      *(_QWORD *)&v144.mat[0].x = v5;
      v143 = *(_QWORD *)((char *)&v5 + 4);
      *((double *)&v24 + 1) = (float)((float)v23 - (float)((float)*(__int64 *)((char *)&v5 + 4) + (float)(__int64)v5));
      v25 = (float)((float)((float)v23 - (float)((float)*(__int64 *)((char *)&v5 + 4) + (float)(__int64)v5)) / (float)v22);
      *(double *)&v24 = v25;
      v26 = floor(x: v24);
      *(double *)&v26 = (float)*(double *)&v26;
      v27 = &this->splines.list[this->previous.movement.spline.sc];
      v28 = v27->length;
      v29 = (float)(v27->length * (float)((float)v25 - (float)*(double *)&v26));
      if ( v29 >= 0.0 )
      {
        if ( v29 <= v28 )
          v28 = (float)(v27->length * (float)((float)v25 - (float)*(double *)&v26));
      }
      else
      {
        v28 = 0.0;
      }
      this->previous.movement.spline.dist = v28;
      v30 = (float *)((int (__fastcall *)(idMat3 *, double, double))v27->curve->GetCurrentValue)(
                       a1: &v148,
                       a2: v28,
                       a3: *((double *)&v26 + 1));
      this->previous.movement.viewOrigin.x = *v30;
      this->previous.movement.viewOrigin.y = v30[1];
      v31 = v30[2];
      goto LABEL_37;
    }
    if ( moveType == CAM_MOVE_ENTITY )
    {
      v32 = idEntityPtr<idEntity const>::operator->(this: &this->previous.movement.entity);
      Physics = idEntity::GetPhysics(this: v32);
      v34 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      this->previous.movement.viewOrigin.x = *v34;
      this->previous.movement.viewOrigin.y = v34[1];
      v31 = v34[2];
LABEL_37:
      this->previous.movement.viewOrigin.z = v31;
      goto LABEL_38;
    }
    if ( this->current.movement.moveType == CAM_MOVE_PLAYER && idGameLocal::GetPlayer(this: gameLocal, i: 0) != nullptr )
    {
      presentable = idGameLocal::GetPlayer(this: gameLocal, i: 0)->presentable;
      if ( presentable != nullptr )
        v36 = (float *)presentable->GetPlayerInterface_2(this: presentable);
      else
        v36 = nullptr;
      this->previous.movement.viewOrigin.x = v36[11633];
      this->previous.movement.viewOrigin.y = v36[11634];
      v31 = v36[11635];
      goto LABEL_37;
    }
  }
LABEL_38:
  if ( this->current.focus.focusType == 2 )
  {
    splineTimeOfs = this->current.focus.splineTimeOfs;
    LODWORD(v38) = this->currentTime;
    HIDWORD(v38) = this->startTime;
    LODWORD(v5) = this->current.focus.startTimeOfs;
    v39 = (float)(this->current.focus.splineTime * (float)1000.0);
    DWORD2(v5) = HIDWORD(v38);
    v143 = v5;
    *(_QWORD *)&v144.mat[0].x = *(_QWORD *)((char *)&v5 + 4);
    *((double *)&v40 + 1) = (float)((float)((float)splineTimeOfs * (float)1000.0) + (float)v38);
    v41 = (float)((float)((float)((float)((float)splineTimeOfs * (float)1000.0) + (float)v38)
                        - (float)((float)(__int64)v5 + (float)*(__int64 *)((char *)&v5 + 4)))
                / (float)v39);
    *(double *)&v40 = v41;
    v42 = floor(x: v40);
    v43 = this->current.focus.spline.sc;
    v44 = this->splines.list;
    DWORD1(v5) = 3 * v43;
    v45 = v43;
    v46 = v44[v45].length;
    v47 = (float)(v44[v45].length * (float)((float)v41 - (float)*(double *)&v42));
    if ( v47 >= 0.0 )
    {
      if ( v47 <= v46 )
        v46 = (float)(v44[v45].length * (float)((float)v41 - (float)*(double *)&v42));
    }
    else
    {
      v46 = 0.0;
    }
    this->current.focus.spline.dist = v46;
  }
  v48 = this->totalTime;
  LODWORD(v5) = this->lastTrigTime;
  v49 = (double)(__int64)v5;
  v50 = (int)(float)((float)*(__int64 *)((char *)&v5 - 4) * (float)v9);
  DWORD2(v5) = v50;
  *(_QWORD *)&v144.mat[0].x = *(_QWORD *)((char *)&v5 + 4);
  idCinematicCamera::EvaluateTriggers(
    this,
    startTime: (float)((float)v49 * (float)0.001),
    endTime: (float)((float)*(__int64 *)((char *)&v5 + 4) * (float)0.001));
  this->lastTrigTime = v50 + 1;
  v51 = idEntity::GetPhysics(this);
  p_viewOrigin = &this->current.movement.viewOrigin;
  v51->SetOrigin(this: v51, a2: &this->current.movement.viewOrigin, a3: -1);
  HIDWORD(v53) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  LODWORD(v53) = this->lastDrawTime;
  *(_QWORD *)&v144.mat[0].x = v53;
  v54 = (float)((float)__SPAIR64__(&idEventDef::eventDefList[3154], HIDWORD(v53)) - (float)v53);
  if ( g_stopTime.valueInteger != 0 )
  {
    LODWORD(v55) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    *(_QWORD *)&v144.mat[0].x = v55;
    v54 = (float)v55;
  }
  else if ( v54 == 0.0 )
  {
    return;
  }
  this->lastDrawTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  PlayerActivator = idCamera::GetPlayerActivator(this);
  if ( PlayerActivator != nullptr )
  {
    v58 = PlayerActivator->presentable;
    if ( v58 != nullptr )
      v59 = (int)v58->GetPlayerInterface_2(this: v58);
    else
      v59 = 0;
    p_fovZoom = &this->current.fovZoom;
    v61 = (idView *)(v59 + 16224);
    if ( this->current.fovZoom.angle < 0.0 )
      idView::GetFOV(this: (idView *)(v59 + 16224), fov_x: &this->current.fovZoom.angle, fov_y: (float *)&v143);
    transTime = this->current.fovZoom.transTime;
    if ( transTime == 0.0 )
    {
      angle = p_fovZoom->angle;
      goto LABEL_62;
    }
    LODWORD(v63) = this->currentTime;
    HIDWORD(v63) = this->startTime;
    startTimeOfs = this->current.fovZoom.startTimeOfs;
    LODWORD(v56) = HIDWORD(v63);
    v143 = *(__int64 *)((char *)&v56 - 4);
    *(_QWORD *)&v144.mat[0].x = v56;
    v65 = (float)((float)((float)v63 - (float)((float)*(__int64 *)((char *)&v56 - 4) + (float)v56))
                / (float)((float)transTime * (float)1000.0));
    if ( v65 < 0.0 )
    {
      angle = (float)((float)((float)(p_fovZoom->angle - this->previous.fovZoom.angle) * (float)0.0)
                    + this->previous.fovZoom.angle);
LABEL_62:
      idView::CalcFOV(this: v61, base_fov: angle);
      if ( this->current.depthOfField.blurStart < 0.0 )
      {
        idParmBlock::GetVector(
          this: (idParmBlock *)&v148.mat[1].y,
          result: &v61->gameview.parmBlock,
          parm: rp->depthOfField);
        this->previous.depthOfField.vec.z = v148.mat[2].x;
        z = v148.mat[1].z;
        this->previous.depthOfField.vec.x = v148.mat[1].y;
        this->previous.depthOfField.vec.y = z;
        if ( this->current.depthOfField.transTime < 0.0 )
        {
          this->current.depthOfField.blurStart = this->previous.depthOfField.blurStart;
          this->current.depthOfField.blurScale = this->previous.depthOfField.blurScale;
          this->current.depthOfField.transTime = this->previous.depthOfField.transTime;
          this->current.depthOfField.vec.x = this->previous.depthOfField.vec.x;
          this->current.depthOfField.vec.y = this->previous.depthOfField.vec.y;
          this->current.depthOfField.vec.z = this->previous.depthOfField.vec.z;
          this->current.depthOfField.startTimeOfs = this->previous.depthOfField.startTimeOfs;
        }
      }
      v71 = this->current.depthOfField.transTime;
      if ( v71 < 0.0 )
      {
LABEL_73:
        v78 = this->current.movement.moveType;
        switch ( v78 )
        {
          case CAM_MOVE_SPLINE:
            v79 = (float *)((int (__fastcall *)(idMat3 *, double))this->splines.list[this->current.movement.spline.sc].curve->GetCurrentValue)(
                             a1: &v148,
                             a2: this->current.movement.spline.dist);
            x = *v79;
            y = v79[1];
            v82 = v79[2];
            break;
          case CAM_MOVE_POSITION:
            x = this->current.movement.position.x;
            y = this->current.movement.position.y;
            v82 = this->current.movement.position.z;
            this->current.movement.transTime = this->current.movement.totalMoveTime;
            break;
          case CAM_MOVE_ENTITY:
            v83 = idEntityPtr<idEntity const>::operator->(this: &this->current.movement.entity);
            v84 = idEntity::GetPhysics(this: v83);
            v85 = (float *)v84->GetOrigin(this: v84, a2: 0);
            x = *v85;
            y = v85[1];
            v82 = v85[2];
            break;
          case CAM_MOVE_PLAYER:
            if ( idGameLocal::GetPlayer(this: gameLocal, i: 0) != nullptr )
            {
              v86 = idGameLocal::GetPlayer(this: gameLocal, i: 0)->presentable;
              if ( v86 != nullptr )
              {
                v87 = (float *)v86->GetPlayerInterface_2(this: v86);
                x = v87[11633];
                y = v87[11634];
                v82 = v87[11635];
              }
              else
              {
                x = MEMORY[0xB5C4];
                y = MEMORY[0xB5C8];
                v82 = MEMORY[0xB5CC];
              }
            }
            else
            {
              v82 = v146;
              y = v145;
              x = v144.mat[2].z;
            }
            break;
          default:
            x = p_viewOrigin->x;
            y = this->current.movement.viewOrigin.y;
            v82 = this->current.movement.viewOrigin.z;
            break;
        }
        v88 = this->current.movement.transTime;
        if ( v88 == 0.0 )
        {
          v93 = x;
          v94 = y;
          v95 = v82;
          goto LABEL_98;
        }
        HIDWORD(v89) = this->startTime;
        LODWORD(v89) = this->current.movement.startTimeOfs;
        LODWORD(v68) = HIDWORD(v89);
        currentTime = this->currentTime;
        v143 = v89;
        *(_QWORD *)&v144.mat[0].x = v68;
        *(_QWORD *)&v148.mat[0].x = *(__int64 *)((char *)&v68 - 4);
        v91 = (float)((float)((float)*(__int64 *)((char *)&v68 - 4) - (float)((float)v89 + (float)v68))
                    / (float)((float)v88 * (float)1000.0));
        if ( v91 < 0.0 )
        {
          v91 = 0.0;
          goto LABEL_94;
        }
        if ( v91 <= 1.0 )
        {
          if ( v91 != 1.0 )
            goto LABEL_93;
        }
        else
        {
          v91 = 1.0;
        }
        this->current.movement.transTime = 0.0;
LABEL_93:
        if ( v91 > 0.5 )
        {
          *(double *)&v69 = (float)((float)((float)((float)1.0 - (float)v91) * (float)120.0) * idMath::M_DEG2RAD);
          v69 = cos(x: v69);
          v92 = (float)*(double *)&v69;
          goto LABEL_96;
        }
LABEL_94:
        *(double *)&v69 = (float)((float)((float)v91 * (float)120.0) * idMath::M_DEG2RAD);
        v69 = cos(x: v69);
        v92 = (float)((float)1.0 - (float)*(double *)&v69);
LABEL_96:
        v93 = (float)((float)((float)((float)x - this->previous.movement.viewOrigin.x) * (float)v92)
                    + this->previous.movement.viewOrigin.x);
        v94 = (float)((float)((float)((float)y - this->previous.movement.viewOrigin.y) * (float)v92)
                    + this->previous.movement.viewOrigin.y);
        v95 = (float)((float)((float)((float)v82 - this->previous.movement.viewOrigin.z) * (float)v92)
                    + this->previous.movement.viewOrigin.z);
LABEL_98:
        focusType = this->current.focus.focusType;
        if ( focusType != 1 || this->suspended )
        {
          switch ( focusType )
          {
            case 2:
              v102 = (float *)((int (__fastcall *)(idMat3 *, double, double))this->splines.list[this->current.focus.spline.sc].curve->GetCurrentValue)(
                                a1: &v148,
                                a2: this->current.focus.spline.dist,
                                a3: *((double *)&v69 + 1));
              v99 = *v102;
              v144.mat[1].y = *v102;
              v100 = v102[1];
              v144.mat[1].z = v102[1];
              v101 = v102[2];
              break;
            case 3:
              v103 = idEntityPtr<idEntity const>::operator->(this: &this->current.focus.entity);
              v103->GetAimPoint(this: v103, a2: AIMPOINT_HEAD, a3: (idVec3 *)&v144.mat[1].y);
              v101 = v144.mat[2].x;
              v100 = v144.mat[1].z;
              v99 = v144.mat[1].y;
              break;
            case 4:
              v99 = this->current.focus.position.x;
              v100 = this->current.focus.position.y;
              v101 = this->current.focus.position.z;
              break;
            default:
              v99 = (float)(this->current.focus.viewAxis.mat[0].x + p_viewOrigin->x);
              v100 = (float)(this->current.movement.viewOrigin.y + this->current.focus.viewAxis.mat[0].y);
              v101 = (float)(this->current.movement.viewOrigin.z + this->current.focus.viewAxis.mat[0].z);
              break;
          }
        }
        else
        {
          v97 = (float)((float)v94 - this->current.movement.viewOrigin.y);
          v98 = (float)((float)v95 - this->current.movement.viewOrigin.z);
          v144.mat[1].y = (float)v93 - p_viewOrigin->x;
          v144.mat[1].z = v97;
          v144.mat[2].x = v98;
          idVec3::NormalizeFast(this: (idVec3 *)&v144.mat[1].y);
          v99 = (float)(v144.mat[1].y + (float)v93);
          v100 = (float)(v144.mat[1].z + (float)v94);
          v101 = (float)(v144.mat[2].x + (float)v95);
        }
        v104 = (float)(this->current.focus.focusOffset.y + (float)v100);
        v105 = (float)(this->current.focus.focusOffset.z + (float)v101);
        v144.mat[1].y = this->current.focus.focusOffset.x + (float)v99;
        v144.mat[1].z = v104;
        v144.mat[2].x = v105;
        v144.mat[2].z = v144.mat[1].y - (float)v93;
        v106 = (float)((float)v104 - (float)v94);
        v145 = v106;
        v107 = (float)((float)v105 - (float)v95);
        v146 = v107;
        if ( v144.mat[2].z != vec3_origin.x || v106 != vec3_origin.y || (v108 = 1, v107 != vec3_origin.z) )
          v108 = 0;
        if ( v108 != 0 )
        {
          v109 = this->current.focus.viewAxis.mat[0].y;
          v110 = this->current.focus.viewAxis.mat[0].z;
          v144.mat[2].z = this->current.focus.viewAxis.mat[0].x;
          v145 = v109;
          v146 = v110;
        }
        else
        {
          idVec3::NormalizeFast(this: (idVec3 *)&v144.mat[2].z);
        }
        idVec3::ToMat3(this: v147.mat, result: (idMat3 *)&v144.mat[2].z);
        if ( this->current.focus.focusType == CAM_FOCUS_PLAYER_VIEW
          && idGameLocal::GetPlayer(this: gameLocal, i: 0) != nullptr )
        {
          v113 = idGameLocal::GetPlayer(this: gameLocal, i: 0)->presentable;
          if ( v113 != nullptr )
            v114 = (float *)v113->GetPlayerInterface_2(this: v113);
          else
            v114 = nullptr;
          v147.mat[0].x = v114[11636];
          v147.mat[0].y = v114[11637];
          v147.mat[0].z = v114[11638];
          v147.mat[1].x = v114[11639];
          v147.mat[1].y = v114[11640];
          v147.mat[1].z = v114[11641];
          v147.mat[2].x = v114[11642];
          v147.mat[2].y = v114[11643];
          v147.mat[2].z = v114[11644];
        }
        if ( this->current.focus.focusType == 1 )
        {
          v115 = idAngles::ToMat3(this: (idAngles *)v149, result: (idMat3 *)&this->current.focus.pathAdjust);
          idMat3::operator*=(this: &v147, a: v115);
        }
        v116 = this->current.focus.transTime;
        if ( v116 == 0.0 )
        {
          v126 = v147.mat[0].x;
          v127 = v147.mat[0].y;
          v128 = v147.mat[0].z;
          v129 = v147.mat[1].x;
          v130 = v147.mat[1].y;
          v131 = v147.mat[1].z;
          v132 = v147.mat[2].x;
          v133 = v147.mat[2].y;
          v134 = v147.mat[2].z;
LABEL_135:
          if ( this->current.shakeView.shakeVolume >= 0.0 )
          {
            v61->cameraShake = this->current.shakeView.shakeVolume;
            v135 = (float)(this->current.shakeView.shakeVolume * (float)0.94999999);
            this->current.shakeView.shakeVolume = this->current.shakeView.shakeVolume * (float)0.94999999;
            if ( v135 <= 0.0 )
              this->current.shakeView.shakeVolume = 0.0;
          }
          this->cameraPos.x = v93;
          this->cameraPos.y = v94;
          this->cameraPos.z = v95;
          this->cameraAxis.mat[0].x = v126;
          this->cameraAxis.mat[1].x = v129;
          this->cameraAxis.mat[0].y = v127;
          this->cameraAxis.mat[0].z = v128;
          this->cameraAxis.mat[1].y = v130;
          this->cameraAxis.mat[1].z = v131;
          this->cameraAxis.mat[2].x = v132;
          this->cameraAxis.mat[2].y = v133;
          this->cameraAxis.mat[2].z = v134;
          if ( cine_cam_debug.valueInteger != 0 )
          {
            timeScale = this->timeScale;
            if ( timeScale != lastTimeScale )
            {
              idLib::Printf(fmt: (const char *)HIDWORD(timeScale), LODWORD(timeScale), LODWORD(v54));
              lastTimeScale = this->timeScale;
            }
          }
          if ( this->doTimeScale )
            ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
              a1: cvarSystem,
              a2: "timescale",
              a3: this->timeScale);
          p_viewOrigin->x = v93;
          this->current.movement.viewOrigin.y = v94;
          this->current.movement.viewOrigin.z = v95;
          this->current.focus.viewAxis.mat[0].x = v126;
          this->current.focus.viewAxis.mat[1].x = v129;
          this->current.focus.viewAxis.mat[0].y = v127;
          this->current.focus.viewAxis.mat[0].z = v128;
          this->current.focus.viewAxis.mat[1].y = v130;
          this->current.focus.viewAxis.mat[1].z = v131;
          this->current.focus.viewAxis.mat[2].x = v132;
          this->current.focus.viewAxis.mat[2].y = v133;
          this->current.focus.viewAxis.mat[2].z = v134;
          return;
        }
        HIDWORD(v117) = this->startTime;
        LODWORD(v117) = this->current.focus.startTimeOfs;
        LODWORD(v111) = HIDWORD(v117);
        v118 = this->currentTime;
        *(_QWORD *)&v144.mat[0].x = v117;
        *(_QWORD *)&v148.mat[0].x = v111;
        v143 = *(__int64 *)((char *)&v111 - 4);
        v119 = (float)((float)((float)*(__int64 *)((char *)&v111 - 4) - (float)((float)v117 + (float)v111))
                     / (float)((float)v116 * (float)1000.0));
        if ( v119 < 0.0 )
        {
          v119 = 0.0;
          goto LABEL_131;
        }
        if ( v119 <= 1.0 )
        {
          if ( v119 != 1.0 )
            goto LABEL_130;
        }
        else
        {
          v119 = 1.0;
        }
        this->current.focus.transTime = 0.0;
LABEL_130:
        if ( v119 > 0.5 )
        {
          *(double *)&v112 = (float)((float)((float)((float)1.0 - (float)v119) * (float)120.0) * idMath::M_DEG2RAD);
          v122 = cos(x: v112);
          v121 = (float)*(double *)&v122;
          goto LABEL_133;
        }
LABEL_131:
        *(double *)&v112 = (float)((float)((float)v119 * (float)120.0) * idMath::M_DEG2RAD);
        v120 = cos(x: v112);
        v121 = (float)((float)1.0 - (float)*(double *)&v120);
LABEL_133:
        v123 = idMat3::ToQuat(this: &v148, result: (idQuat *)&v147);
        v124 = idMat3::ToQuat(this: &v144, result: (idQuat *)&this->previous.focus.viewAxis);
        idQuat::Lerp(this: (idQuat *)&v148.mat[2].z, from: v124, to: v123, t: v121);
        v125 = (float *)idQuat::ToMat3(this: v149, result: (idMat3 *)&v148.mat[2].z);
        v126 = *v125;
        v127 = v125[1];
        v128 = v125[2];
        v129 = v125[3];
        v130 = v125[4];
        v131 = v125[5];
        v132 = v125[6];
        v133 = v125[7];
        v134 = v125[8];
        goto LABEL_135;
      }
      v72 = this->current.depthOfField.startTimeOfs;
      startTime = this->startTime;
      LODWORD(v67) = this->currentTime;
      *(_QWORD *)&v144.mat[0].x = *(__int64 *)((char *)&v67 - 4);
      v143 = v67;
      v74 = (float)((float)((float)v67 - (float)((float)v72 + (float)*(__int64 *)((char *)&v67 - 4)))
                  / (float)((float)v71 * (float)1000.0));
      if ( v74 < 0.0 )
      {
        v74 = 0.0;
LABEL_72:
        v75 = this->previous.depthOfField.vec.y;
        v76 = this->previous.depthOfField.vec.z;
        v77 = (float)((float)(this->current.depthOfField.vec.y - this->previous.depthOfField.vec.y) * (float)v74);
        *((double *)&v69 + 1) = (float)((float)(this->current.depthOfField.vec.z - this->previous.depthOfField.vec.z)
                                      * (float)v74);
        this->cameraDOF.x = (float)((float)(this->current.depthOfField.vec.x - this->previous.depthOfField.vec.x)
                                  * (float)v74)
                          + this->previous.depthOfField.vec.x;
        this->cameraDOF.y = (float)v77 + (float)v75;
        this->cameraDOF.z = (float)*((double *)&v69 + 1) + (float)v76;
        goto LABEL_73;
      }
      if ( v74 <= 1.0 )
      {
        if ( v74 != 1.0 )
          goto LABEL_72;
      }
      else
      {
        v74 = 1.0;
      }
      this->current.depthOfField.transTime = -1.0;
      goto LABEL_72;
    }
    if ( v65 <= 1.0 )
    {
      if ( v65 != 1.0 )
      {
LABEL_60:
        angle = (float)((float)((float)(p_fovZoom->angle - this->previous.fovZoom.angle) * (float)v65)
                      + this->previous.fovZoom.angle);
        goto LABEL_62;
      }
    }
    else
    {
      v65 = 1.0;
    }
    this->current.fovZoom.transTime = 0.0;
    goto LABEL_60;
  }
}


// ========================================================================
// ?SetTriggers@idSlowMotionCamera@@QAA_NPBVidDeclCameraTrigger@@PBVidEntity@@PBVidPlayer@@@Z
// EA  : 0x82D1BC48
// RVA : 0x00D1BC48
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

int __fastcall idSlowMotionCamera::SetTriggers(
        idSlowMotionCamera *this,
        const idDeclCameraTrigger *decl,
        idVehicleAI *activator_,
        idPlayer *player)
{
  idVehicle *Control; // r3
  idList<idDeclCameraTrigger::idCameraTriggerParms,5> *p_triggers; // r29
  idVehicle *v10; // r26
  idPhysics *Physics; // r3
  int v12; // r3
  idPhysics *v13; // r3
  idPhysics *v14; // r3
  idPhysics *v15; // r3
  idList<idDeclCameraTrigger::idCameraTriggerParms,5> *v16; // r20
  int v17; // r15
  int v18; // r21
  idPhysics *v19; // r30
  idPhysics *v20; // r3
  float *v21; // r29
  float *v22; // r3
  double v23; // fp9
  double v24; // fp7
  idVehicleAI *v25; // r29
  char v26; // r30
  idVehicleAI *v27; // r3
  double z; // fp30
  double y; // fp29
  double x; // fp28
  idVehicle_Car *VehicleCar; // r3
  double v32; // fp27
  double v33; // fp26
  double v34; // fp25
  idPhysics *v35; // r3
  float *v36; // r3
  double v37; // fp9
  double v38; // fp7
  double v39; // fp6
  idVehicleAI *v40; // r11
  double v41; // fp30
  double v42; // fp29
  double v43; // fp28
  idPhysics *v44; // r3
  float *v45; // r3
  double v46; // fp7
  double v47; // fp6
  idPhysics *v48; // r30
  idPhysics *v49; // r3
  float *v50; // r29
  float *v51; // r3
  double v52; // fp9
  double v53; // fp7
  double v54; // fp30
  double v55; // fp29
  double v56; // fp28
  idPhysics *v57; // r3
  float *v58; // r3
  double v59; // fp11
  double v60; // fp9
  double v61; // fp8
  idPhysics *v62; // r3
  float *v63; // r3
  double v64; // fp7
  double v65; // fp6
  int entityNumber; // r11
  double v67; // fp3
  double v68; // fp2
  double v69; // fp13
  double v70; // fp12
  idPhysics *v71; // r3
  idPhysics *v72; // r30
  idPhysics *v73; // r3
  float *v74; // r29
  float *v75; // r3
  double v76; // fp9
  double v77; // fp7
  double v78; // fp30
  double v79; // fp29
  double v80; // fp28
  idEntity *v81; // r3
  idEntity *v82; // r3
  idPhysics *v83; // r3
  float *v84; // r3
  double v85; // fp9
  double v86; // fp7
  double v87; // fp6
  idPhysics *v88; // r3
  float *v89; // r3
  double v90; // fp9
  double v91; // fp7
  idPhysics *v92; // r3
  float *v93; // r3
  double v94; // fp9
  double v95; // fp7
  idVehicleAI *v96; // r29
  char v97; // r30
  idVehicleAI *v98; // r3
  int value; // r9
  idGameLocal *v100; // r10
  idVehicle_Car *v101; // r3
  idVehicle_Car *v102; // r3
  idPhysics *v103; // r3
  idVehicleAI *v104; // r11
  idPhysics *v105; // r3
  int v106; // r11
  idDeclCameraTrigger::idCameraTriggerParms *list; // r28
  int size; // r30
  idDeclCameraTrigger::idCameraTriggerParms *v109; // r29
  unsigned __int8 v111; // [sp+50h] [-1E20h]
  idVec3 v112; // [sp+60h] [-1E10h] BYREF
  idVec3 v113; // [sp+70h] [-1E00h] BYREF
  idVec3 v114; // [sp+80h] [-1DF0h] BYREF
  idVec3 v115; // [sp+90h] [-1DE0h] BYREF
  idMat3 v116; // [sp+A0h] [-1DD0h] BYREF
  idDeclCameraTrigger::idCameraTriggerParms v117; // [sp+D0h] [-1DA0h] BYREF
  float v118; // [sp+2B4h] [-1BBCh] BYREF
  idView v119; // [sp+2C0h] [-1BB0h] BYREF

  idView::idView(this: &v119);
  Control = (idVehicle *)idPlayer::GetControl(this: player);
  p_triggers = &this->triggers;
  v111 = 1;
  v10 = idVehicle::CastTo(c: Control);
  if ( this->triggers.listStatic == 0 || this->triggers.listStatic == 2 )
  {
    if ( p_triggers->list != nullptr )
      idListArrayDelete<idDeclCameraTrigger::idCameraTriggerParms>(ptr: p_triggers->list, num: this->triggers.size);
    p_triggers->list = nullptr;
    this->triggers.size = 0;
  }
  this->triggers.num = 0;
  if ( v10 != nullptr )
  {
    idVehicle::GetDriverView(this: v10, origin: &v112, axis: &v116, fov_x: &v118, view: &v119);
  }
  else
  {
    Physics = idEntity::GetPhysics(this: player);
    v12 = (int)Physics->GetAxis(this: Physics, a2: 0);
    v116.mat[0].x = *(float *)v12;
    v116.mat[0].y = *(float *)(v12 + 4);
    v116.mat[0].z = *(float *)(v12 + 8);
    v116.mat[1] = *(idVec3 *)(v12 + 12);
    v116.mat[2] = *(idVec3 *)(v12 + 24);
    v13 = idEntity::GetPhysics(this: player);
    v112 = *v13->GetOrigin(this: v13, a2: 0);
  }
  v14 = idEntity::GetPhysics(this);
  v14->SetOrigin(this: v14, a2: &v112, a3: -1);
  v15 = idEntity::GetPhysics(this);
  v15->SetAxis(this: v15, a2: &v116, a3: -1);
  v16 = &decl->triggers;
  v17 = 0;
  if ( decl->triggers.num <= 0 )
    goto LABEL_90;
  v18 = 0;
  while ( 1 )
  {
    idDeclCameraTrigger::idCameraTriggerParms::idCameraTriggerParms(this: &v117, __that: &v16->list[v18]);
    switch ( v117.movement.moveType )
    {
      case CAM_MOVE_PLAYER:
        v117.movement.moveType = CAM_MOVE_ENTITY;
        if ( player != nullptr )
        {
          entityNumber = player->entityNumber;
          goto LABEL_32;
        }
        v117.movement.entity.spawnId.value = 0x1FFF;
        break;
      case CAM_MOVE_PLAYER_VEHICLE:
        if ( v10 != nullptr )
        {
          v117.movement.moveType = CAM_MOVE_ENTITY;
          goto LABEL_30;
        }
        v111 = 0;
        break;
      case CAM_MOVE_VEHICLE_DEFAULT:
        if ( v10 != nullptr )
          goto LABEL_31;
        v111 = 0;
        break;
      case CAM_MOVE_ENTITY_POSITION:
        v72 = idEntity::GetPhysics(this);
        v73 = idEntity::GetPhysics(this: activator_);
        v74 = (float *)v73->GetOrigin(this: v73, a2: 0);
        v75 = (float *)v72->GetOrigin(this: v72, a2: 0);
        v76 = (float)(v74[2] - v75[2]);
        v77 = (float)(v74[1] - v75[1]);
        v114.x = *v74 - *v75;
        v114.z = v76;
        v114.y = v77;
        idVec3::NormalizeFast(this: &v114);
        v117.movement.moveType = CAM_MOVE_POSITION;
        v78 = (float)(v114.z * v117.movement.scalarOffset);
        v79 = (float)(v114.y * v117.movement.scalarOffset);
        v80 = (float)(v114.x * v117.movement.scalarOffset);
        if ( gameLocal->spawnIds.ptr[v117.movement.entity.spawnId.value & 0x1FFF] == v117.movement.entity.spawnId.value >> 13
          && (v81 = gameLocal->entities.ptr[v117.movement.entity.spawnId.value & 0x1FFF]) != nullptr )
        {
          v82 = idEntity::CastTo(c: v81);
        }
        else
        {
          v82 = nullptr;
        }
        v83 = idEntity::GetPhysics(this: v82);
        v84 = (float *)v83->GetOrigin(this: v83, a2: 0);
        v85 = (float)(v84[2] + v117.movement.entityOffset.z);
        v86 = (float)(v84[1] + v117.movement.entityOffset.y);
        v87 = (float)(*v84 + v117.movement.entityOffset.x);
        v117.movement.entity.spawnId.value = 0x1FFF;
        v117.movement.entityOffset.z = 0.0;
        v117.movement.entityOffset.y = 0.0;
        v117.movement.entityOffset.x = 0.0;
        v117.movement.position.z = (float)v85 + (float)v78;
        v117.movement.position.y = (float)v86 + (float)v79;
        v117.movement.position.x = (float)v87 + (float)v80;
        break;
      case CAM_MOVE_ACTIVATOR:
        v19 = idEntity::GetPhysics(this);
        v20 = idEntity::GetPhysics(this: activator_);
        v21 = (float *)v20->GetOrigin(this: v20, a2: 0);
        v22 = (float *)v19->GetOrigin(this: v19, a2: 0);
        v23 = (float)(v21[2] - v22[2]);
        v24 = (float)(v21[1] - v22[1]);
        v113.x = *v21 - *v22;
        v113.z = v23;
        v113.y = v24;
        idVec3::NormalizeFast(this: &v113);
        v25 = nullptr;
        v26 = 0;
        v27 = idVehicleAI::CastTo(c: activator_);
        z = v113.z;
        y = v113.y;
        x = v113.x;
        if ( v27 != nullptr )
        {
          VehicleCar = idVehicleAI::GetVehicleCar(this: v27);
          if ( VehicleCar != nullptr )
          {
            v25 = (idVehicleAI *)VehicleCar;
            if ( VehicleCar->destroyed )
            {
              v117.movement.moveType = CAM_MOVE_POSITION;
              v32 = (float)((float)z * v117.movement.scalarOffset);
              v33 = (float)((float)y * v117.movement.scalarOffset);
              v34 = (float)((float)x * v117.movement.scalarOffset);
              v35 = idEntity::GetPhysics(this: activator_);
              v36 = (float *)v35->GetOrigin(this: v35, a2: 0);
              v26 = 1;
              v37 = (float)(v36[2] + v117.movement.entityOffset.z);
              v38 = (float)(v36[1] + v117.movement.entityOffset.y);
              v39 = (float)(*v36 + v117.movement.entityOffset.x);
              v117.movement.entity.spawnId.value = 0x1FFF;
              v117.movement.entityOffset.z = 0.0;
              v117.movement.entityOffset.y = 0.0;
              v117.movement.entityOffset.x = 0.0;
              v117.movement.position.z = (float)v37 + (float)v32;
              v117.movement.position.y = (float)v38 + (float)v33;
              v117.movement.position.x = (float)v39 + (float)v34;
            }
          }
        }
        if ( v26 == 0 )
        {
          v117.movement.moveType = CAM_MOVE_ENTITY;
          v40 = v25;
          if ( v25 == nullptr )
            v40 = activator_;
          if ( v40 != nullptr )
            v117.movement.entity.spawnId.value = (gameLocal->spawnIds.ptr[v40->entityNumber] << 13) | v40->entityNumber;
          else
            v117.movement.entity.spawnId.value = 0x1FFF;
          v117.movement.entityOffset.z = 0.0;
          v117.movement.entityOffset.y = 0.0;
          v117.movement.entityOffset.x = 0.0;
          v41 = (float)((float)z * v117.movement.scalarOffset);
          v42 = (float)((float)y * v117.movement.scalarOffset);
          v43 = (float)((float)x * v117.movement.scalarOffset);
          v44 = idEntity::GetPhysics(this: activator_);
          v45 = (float *)v44->GetOrigin(this: v44, a2: 0);
          v46 = (float)(v45[1] + v117.movement.entityOffset.y);
          v47 = (float)(v117.movement.entityOffset.x + *v45);
          v117.movement.position.z = (float)(v45[2] + v117.movement.entityOffset.z) + (float)v41;
          v117.movement.position.y = (float)v46 + (float)v42;
          v117.movement.position.x = (float)v47 + (float)v43;
        }
        break;
      case CAM_MOVE_ACTIVATOR_POSITION:
        v48 = idEntity::GetPhysics(this);
        v49 = idEntity::GetPhysics(this: activator_);
        v50 = (float *)v49->GetOrigin(this: v49, a2: 0);
        v51 = (float *)v48->GetOrigin(this: v48, a2: 0);
        v52 = (float)(v50[2] - v51[2]);
        v53 = (float)(v50[1] - v51[1]);
        v115.x = *v50 - *v51;
        v115.z = v52;
        v115.y = v53;
        idVec3::NormalizeFast(this: &v115);
        v117.movement.moveType = CAM_MOVE_POSITION;
        v54 = (float)(v115.z * v117.movement.scalarOffset);
        v55 = (float)(v115.y * v117.movement.scalarOffset);
        v56 = (float)(v115.x * v117.movement.scalarOffset);
        v57 = idEntity::GetPhysics(this: activator_);
        v58 = (float *)v57->GetOrigin(this: v57, a2: 0);
        v59 = (float)(v58[2] + v117.movement.entityOffset.z);
        v60 = (float)(v58[1] + v117.movement.entityOffset.y);
        v61 = (float)(v117.movement.entityOffset.x + *v58);
        v117.movement.entity.spawnId.value = 0x1FFF;
        v117.movement.entityOffset.z = 0.0;
        v117.movement.entityOffset.y = 0.0;
        v117.movement.entityOffset.x = 0.0;
        v117.movement.position.z = (float)v59 + (float)v54;
        v117.movement.position.y = (float)v60 + (float)v55;
        v117.movement.position.x = (float)v61 + (float)v56;
        break;
      case CAM_MOVE_PLAYER_POSITION:
        v117.movement.moveType = CAM_MOVE_POSITION;
        v88 = idEntity::GetPhysics(this: player);
        v89 = (float *)v88->GetOrigin(this: v88, a2: 0);
        v90 = (float)(v89[2] + v117.movement.entityOffset.z);
        v91 = (float)(v89[1] + v117.movement.entityOffset.y);
        v117.movement.position.x = v117.movement.entityOffset.x + *v89;
        v117.movement.entity.spawnId.value = 0x1FFF;
        v117.movement.entityOffset.z = 0.0;
        v117.movement.position.z = v90;
        v117.movement.entityOffset.y = 0.0;
        v117.movement.position.y = v91;
        v117.movement.entityOffset.x = 0.0;
        break;
      case CAM_MOVE_PLAYER_VEHICLE_POSITION:
        if ( v10 != nullptr )
        {
          v117.movement.moveType = CAM_MOVE_POSITION;
          v92 = idEntity::GetPhysics(this: v10);
          v93 = (float *)v92->GetOrigin(this: v92, a2: 0);
          v94 = (float)(v93[2] + v117.movement.entityOffset.z);
          v95 = (float)(v93[1] + v117.movement.entityOffset.y);
          v117.movement.position.x = *v93 + v117.movement.entityOffset.x;
          v117.movement.entity.spawnId.value = 0x1FFF;
          v117.movement.entityOffset.z = 0.0;
          v117.movement.position.z = v94;
          v117.movement.entityOffset.y = 0.0;
          v117.movement.position.y = v95;
          v117.movement.entityOffset.x = 0.0;
        }
        else
        {
          v111 = 0;
        }
        break;
      case CAM_MOVE_CIRCLE_PLAYER:
        v117.movement.moveType = CAM_MOVE_CIRCLE_ENTITY;
        if ( player != nullptr )
          v117.movement.entity.spawnId.value = (gameLocal->spawnIds.ptr[player->entityNumber] << 13)
                                             | player->entityNumber;
        else
          v117.movement.entity.spawnId.value = 0x1FFF;
        break;
      case CAM_MOVE_CIRCLE_PLAYER_VEHICLE:
        if ( v10 != nullptr )
        {
          v117.movement.moveType = CAM_MOVE_CIRCLE_ENTITY;
LABEL_30:
          v62 = idEntity::GetPhysics(this: v10);
          v63 = (float *)v62->GetOrigin(this: v62, a2: 0);
          v64 = (float)(v112.y - v63[1]);
          v65 = (float)(v112.x - *v63);
          v117.movement.additionalOffset.z = v112.z - v63[2];
          v117.movement.additionalOffset.x = v65;
          v117.movement.additionalOffset.y = v64;
LABEL_31:
          entityNumber = v10->entityNumber;
LABEL_32:
          v117.movement.entity.spawnId.value = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
        }
        else
        {
          v111 = 0;
        }
        break;
      default:
        break;
    }
    if ( ((LODWORD(v117.movement.entityOffset.y)
         | LODWORD(v117.movement.entityOffset.z)
         | LODWORD(v117.movement.entityOffset.x))
        & 0x7FFFFFFF) != 0 )
    {
      v67 = this->current.focus.viewAxis.mat[0].y;
      v68 = this->current.focus.viewAxis.mat[0].x;
      v69 = (float)((float)(this->current.focus.viewAxis.mat[1].y * v117.movement.entityOffset.y)
                  + (float)(this->current.focus.viewAxis.mat[2].y * v117.movement.entityOffset.z));
      v70 = (float)((float)(this->current.focus.viewAxis.mat[1].x * v117.movement.entityOffset.y)
                  + (float)(this->current.focus.viewAxis.mat[2].x * v117.movement.entityOffset.z));
      v117.movement.entityOffset.z = (float)(this->current.focus.viewAxis.mat[0].z * v117.movement.entityOffset.x)
                                   + (float)((float)(this->current.focus.viewAxis.mat[1].z * v117.movement.entityOffset.y)
                                           + (float)(this->current.focus.viewAxis.mat[2].z * v117.movement.entityOffset.z));
      v117.movement.entityOffset.y = (float)((float)v67 * v117.movement.entityOffset.x) + (float)v69;
      v117.movement.entityOffset.x = (float)(v117.movement.entityOffset.x * (float)v68) + (float)v70;
    }
    if ( v117.focus.focusType == CAM_FOCUS_ACTIVATOR_POSITION )
    {
      if ( activator_ == nullptr )
      {
        v111 = 0;
        goto LABEL_88;
      }
      v117.focus.focusType = CAM_FOCUS_POSITION;
      v71 = idEntity::GetPhysics(this: activator_);
      v117.focus.position = *v71->GetOrigin(this: v71, a2: 0);
      goto LABEL_82;
    }
    if ( v117.focus.focusType == CAM_FOCUS_ACTIVATOR )
    {
      if ( activator_ == nullptr )
      {
        v111 = 0;
        goto LABEL_88;
      }
      v96 = nullptr;
      v97 = 0;
      v98 = idVehicleAI::CastTo(c: activator_);
      if ( v98 != nullptr )
      {
        value = v98->vehicleCar.spawnId.value;
        v100 = gameLocal;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
          || (v101 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) == nullptr )
        {
LABEL_64:
          if ( v97 == 0 )
          {
            v117.focus.focusType = CAM_FOCUS_ENTITY;
            v104 = v96;
            if ( v96 == nullptr )
              v104 = activator_;
            if ( v104 != nullptr )
              v117.focus.entity.spawnId.value = (v100->spawnIds.ptr[v104->entityNumber] << 13) | v104->entityNumber;
            else
              v117.focus.entity.spawnId.value = 0x1FFF;
            v105 = idEntity::GetPhysics(this: activator_);
            v117.focus.position = *v105->GetOrigin(this: v105, a2: 0);
          }
          goto LABEL_82;
        }
        v102 = idVehicle_Car::CastTo(c: v101);
        if ( v102 != nullptr )
        {
          v96 = (idVehicleAI *)v102;
          if ( v102->destroyed )
          {
            v117.focus.focusType = CAM_FOCUS_POSITION;
            v103 = idEntity::GetPhysics(this: activator_);
            v97 = 1;
            v117.focus.position = *v103->GetOrigin(this: v103, a2: 0);
          }
        }
      }
      v100 = gameLocal;
      goto LABEL_64;
    }
    if ( v117.focus.focusType != CAM_FOCUS_PLAYER )
      break;
    v117.focus.focusType = CAM_FOCUS_ENTITY;
    if ( player != nullptr )
    {
      v106 = player->entityNumber;
      goto LABEL_81;
    }
    v117.focus.entity.spawnId.value = 0x1FFF;
LABEL_82:
    idList<idDeclCameraTrigger::idCameraTriggerParms,5>::Append(this: &this->triggers, obj: &v117);
    idDeclCameraTrigger::idCameraTriggerParms::~idCameraTriggerParms(this: &v117);
    ++v17;
    ++v18;
    if ( v17 >= v16->num )
      goto LABEL_89;
  }
  if ( v117.focus.focusType == CAM_FOCUS_PLAYER_VEHICLE )
  {
    if ( v10 == nullptr )
    {
      v111 = 0;
      goto LABEL_88;
    }
    v117.focus.focusType = CAM_FOCUS_ENTITY;
LABEL_80:
    v106 = v10->entityNumber;
LABEL_81:
    v117.focus.entity.spawnId.value = (gameLocal->spawnIds.ptr[v106] << 13) | v106;
    goto LABEL_82;
  }
  if ( v117.focus.focusType != CAM_FOCUS_VEHICLE_DEFAULT )
    goto LABEL_82;
  if ( v10 != nullptr )
    goto LABEL_80;
  v111 = 0;
LABEL_88:
  idDeclCameraTrigger::idCameraTriggerParms::~idCameraTriggerParms(this: &v117);
LABEL_89:
  p_triggers = &this->triggers;
LABEL_90:
  if ( v111 == 0 )
  {
    if ( p_triggers->listStatic == 0 || p_triggers->listStatic == 2 )
    {
      list = p_triggers->list;
      if ( p_triggers->list != nullptr )
      {
        size = p_triggers->size;
        if ( size > 0 )
        {
          v109 = p_triggers->list;
          do
          {
            idDeclCameraTrigger::idCameraTriggerParms::~idCameraTriggerParms(this: v109);
            --size;
            ++v109;
          }
          while ( size != 0 );
        }
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        p_triggers = &this->triggers;
      }
      p_triggers->list = nullptr;
      p_triggers->size = 0;
    }
    p_triggers->num = 0;
  }
  idView::~idView(this: &v119);
  return v111;
}


// ========================================================================
// __unwind$532326
// EA  : 0x82D1C850
// RVA : 0x00D1C850
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_532326()
{
  int v0; // r12

  idView::~idView(this: (idView *)(v0 - 7792 + 704));
}


// ========================================================================
// __unwind$532327
// EA  : 0x82D1C878
// RVA : 0x00D1C878
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void _unwind_532327()
{
  int v0; // r12

  idDeclCameraTrigger::idCameraTriggerParms::~idCameraTriggerParms(this: (idDeclCameraTrigger::idCameraTriggerParms *)(v0 - 7792 + 208));
}


// ========================================================================
// `dynamic initializer for 'spectator_cam_distance''
// EA  : 0x8337A320
// RVA : 0x0137A320
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spectator_cam_distance__()
{
  idCVar::idCVar(
    this: &spectator_cam_distance,
    name: "spectator_cam_distance",
    value: "512",
    flags: 4,
    description: "Spectator camera distance from the target.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spectator_cam_distance__);
}


// ========================================================================
// `dynamic initializer for 'spectator_cam_height''
// EA  : 0x8337A378
// RVA : 0x0137A378
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spectator_cam_height__()
{
  idCVar::idCVar(
    this: &spectator_cam_height,
    name: "spectator_cam_height",
    value: "192",
    flags: 4,
    description: "Spectator camera height above the target.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spectator_cam_height__);
}


// ========================================================================
// `dynamic initializer for 'cam_maxDist''
// EA  : 0x8337A3D0
// RVA : 0x0137A3D0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_maxDist__()
{
  idCVar::idCVar(
    this: &cam_maxDist,
    name: "cam_maxDist",
    value: "2048.0",
    flags: 4,
    description: "max distance a utility camera can be from its target.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_maxDist__);
}


// ========================================================================
// `dynamic initializer for 'racecam_New''
// EA  : 0x8337A428
// RVA : 0x0137A428
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__racecam_New__()
{
  idCVar::idCVar(
    this: &racecam_New,
    name: "racecam_New",
    value: "0",
    flags: 1,
    description: "new finish race camera",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__racecam_New__);
}


// ========================================================================
// `dynamic initializer for 'racecam_PosLerp''
// EA  : 0x8337A480
// RVA : 0x0137A480
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__racecam_PosLerp__()
{
  idCVar::idCVar(
    this: &racecam_PosLerp,
    name: "racecam_PosLerp",
    value: "0.90",
    flags: 4,
    description: "how quickly the focal position goes to the target",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__racecam_PosLerp__);
}


// ========================================================================
// `dynamic initializer for 'racecam_PosUp''
// EA  : 0x8337A4D8
// RVA : 0x0137A4D8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__racecam_PosUp__()
{
  idCVar::idCVar(
    this: &racecam_PosUp,
    name: "racecam_PosUp",
    value: "0.0",
    flags: 4,
    description: "focal z-position offset added to the target",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__racecam_PosUp__);
}


// ========================================================================
// `dynamic initializer for 'racecam_BreathEnable''
// EA  : 0x8337A530
// RVA : 0x0137A530
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__racecam_BreathEnable__()
{
  idCVar::idCVar(
    this: &racecam_BreathEnable,
    name: "racecam_BreathEnable",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__racecam_BreathEnable__);
}


// ========================================================================
// `dynamic initializer for 'racecam_BreathMinFreq''
// EA  : 0x8337A588
// RVA : 0x0137A588
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__racecam_BreathMinFreq__()
{
  idCVar::idCVar(
    this: &racecam_BreathMinFreq,
    name: "racecam_BreathMinFreq",
    value: "100",
    flags: 4,
    description: "ms",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__racecam_BreathMinFreq__);
}


// ========================================================================
// `dynamic initializer for 'racecam_BreathMaxFreq''
// EA  : 0x8337A5E0
// RVA : 0x0137A5E0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__racecam_BreathMaxFreq__()
{
  idCVar::idCVar(
    this: &racecam_BreathMaxFreq,
    name: "racecam_BreathMaxFreq",
    value: "500",
    flags: 4,
    description: "ms",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__racecam_BreathMaxFreq__);
}


// ========================================================================
// `dynamic initializer for 'racecam_BreathAng''
// EA  : 0x8337A638
// RVA : 0x0137A638
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__racecam_BreathAng__()
{
  idCVar::idCVar(
    this: &racecam_BreathAng,
    name: "racecam_BreathAng",
    value: "8.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__racecam_BreathAng__);
}


// ========================================================================
// `dynamic initializer for 'racecam_BreathLerp''
// EA  : 0x8337A690
// RVA : 0x0137A690
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__racecam_BreathLerp__()
{
  idCVar::idCVar(
    this: &racecam_BreathLerp,
    name: "racecam_BreathLerp",
    value: "0.015",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__racecam_BreathLerp__);
}


// ========================================================================
// `dynamic initializer for 'racecam_BreathDebug''
// EA  : 0x8337A6E8
// RVA : 0x0137A6E8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__racecam_BreathDebug__()
{
  idCVar::idCVar(
    this: &racecam_BreathDebug,
    name: "racecam_BreathDebug",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__racecam_BreathDebug__);
}


// ========================================================================
// `dynamic initializer for 'racecam_version''
// EA  : 0x8337A740
// RVA : 0x0137A740
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__racecam_version__()
{
  idCVar::idCVar(
    this: &racecam_version,
    name: "racecam_version",
    value: "2",
    flags: 2,
    description: "1 - 3",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__racecam_version__);
}


// ========================================================================
// `dynamic initializer for 'racecam_focusLerpRate''
// EA  : 0x8337A798
// RVA : 0x0137A798
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__racecam_focusLerpRate__()
{
  idCVar::idCVar(
    this: &racecam_focusLerpRate,
    name: "racecam_focusLerpRate",
    value: "0.05",
    flags: 4,
    description: "how quickly the focal position goes to the target",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__racecam_focusLerpRate__);
}


// ========================================================================
// `dynamic initializer for 'racecam_goalLerpRate_3''
// EA  : 0x8337A7F0
// RVA : 0x0137A7F0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__racecam_goalLerpRate_3__()
{
  idCVar::idCVar(
    this: &racecam_goalLerpRate_3,
    name: "racecam_goalLerpRate_3",
    value: "0.02",
    flags: 4,
    description: "how quickly the goal position goes to the target",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__racecam_goalLerpRate_3__);
}


// ========================================================================
// `dynamic initializer for 'racecam_pathStepUnits''
// EA  : 0x8337A848
// RVA : 0x0137A848
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__racecam_pathStepUnits__()
{
  idCVar::idCVar(
    this: &racecam_pathStepUnits,
    name: "racecam_pathStepUnits",
    value: "5",
    flags: 4,
    description: "divisor for step size",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__racecam_pathStepUnits__);
}


// ========================================================================
// `dynamic initializer for 'racecam_pathMinDist''
// EA  : 0x8337A8A0
// RVA : 0x0137A8A0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__racecam_pathMinDist__()
{
  idCVar::idCVar(
    this: &racecam_pathMinDist,
    name: "racecam_pathMinDist",
    value: "1000",
    flags: 4,
    description: "min distance from vehicle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__racecam_pathMinDist__);
}


// ========================================================================
// `dynamic initializer for 'deathcam_goalLerpRate''
// EA  : 0x8337A8F8
// RVA : 0x0137A8F8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__deathcam_goalLerpRate__()
{
  idCVar::idCVar(
    this: &deathcam_goalLerpRate,
    name: "deathcam_goalLerpRate",
    value: "0.002",
    flags: 4,
    description: "how quickly the camera position moves towards it's goal position",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__deathcam_goalLerpRate__);
}


// ========================================================================
// `dynamic initializer for 'deathcam_focusLerpRate''
// EA  : 0x8337A950
// RVA : 0x0137A950
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__deathcam_focusLerpRate__()
{
  idCVar::idCVar(
    this: &deathcam_focusLerpRate,
    name: "deathcam_focusLerpRate",
    value: "0.0025",
    flags: 4,
    description: "how quickly the focal position goes to the target",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__deathcam_focusLerpRate__);
}


// ========================================================================
// `dynamic initializer for 'g_cameraPlayerHack''
// EA  : 0x8337A9A8
// RVA : 0x0137A9A8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_cameraPlayerHack__()
{
  idCVar::idCVar(
    this: &g_cameraPlayerHack,
    name: "g_cameraPlayerHack",
    value: "0",
    flags: 1,
    description: "true = force player 0 for camera",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_cameraPlayerHack__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionView_keepPitch''
// EA  : 0x8337AA00
// RVA : 0x0137AA00
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionView_keepPitch__()
{
  idCVar::idCVar(
    this: &ai_interactionView_keepPitch,
    name: "ai_interactionView_keepPitch",
    value: "1",
    flags: 1,
    description: "keep the pitch of the interaction camera on player camera. Note: pitch fails if player starts crouched.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionView_keepPitch__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionView_UseCvars''
// EA  : 0x8337AA58
// RVA : 0x0137AA58
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionView_UseCvars__()
{
  idCVar::idCVar(
    this: &ai_interactionView_UseCvars,
    name: "ai_interactionView_UseCvars",
    value: "0",
    flags: 1,
    description: "if true use the cvars, if false use the ai editable settings",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionView_UseCvars__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionView_xoffset''
// EA  : 0x8337AAB0
// RVA : 0x0137AAB0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionView_xoffset__()
{
  idCVar::idCVar(
    this: &ai_interactionView_xoffset,
    name: "ai_interactionView_xoffset",
    value: "0",
    flags: 4,
    description: "target offset x",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionView_xoffset__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionView_yoffset''
// EA  : 0x8337AB08
// RVA : 0x0137AB08
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionView_yoffset__()
{
  idCVar::idCVar(
    this: &ai_interactionView_yoffset,
    name: "ai_interactionView_yoffset",
    value: "0",
    flags: 4,
    description: "target offset y",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionView_yoffset__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionView_zoffset''
// EA  : 0x8337AB60
// RVA : 0x0137AB60
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionView_zoffset__()
{
  idCVar::idCVar(
    this: &ai_interactionView_zoffset,
    name: "ai_interactionView_zoffset",
    value: "-5",
    flags: 4,
    description: "target offset z",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionView_zoffset__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionView_PitchOffset''
// EA  : 0x8337ABB8
// RVA : 0x0137ABB8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionView_PitchOffset__()
{
  idCVar::idCVar(
    this: &ai_interactionView_PitchOffset,
    name: "ai_interactionView_PitchOffset",
    value: "15",
    flags: 4,
    description: "how far to offset the pitch of the camera we want when a job is offered",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionView_PitchOffset__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionView_YawOffset''
// EA  : 0x8337AC10
// RVA : 0x0137AC10
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionView_YawOffset__()
{
  idCVar::idCVar(
    this: &ai_interactionView_YawOffset,
    name: "ai_interactionView_YawOffset",
    value: "-23",
    flags: 4,
    description: "how far to offset the yaw of the camera we want when a job is offered",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionView_YawOffset__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionView_RollOffset''
// EA  : 0x8337AC68
// RVA : 0x0137AC68
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionView_RollOffset__()
{
  idCVar::idCVar(
    this: &ai_interactionView_RollOffset,
    name: "ai_interactionView_RollOffset",
    value: "0",
    flags: 4,
    description: "how far to offset the roll of the camera we want when a job is offered",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionView_RollOffset__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionView_Distance''
// EA  : 0x8337ACC0
// RVA : 0x0137ACC0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionView_Distance__()
{
  idCVar::idCVar(
    this: &ai_interactionView_Distance,
    name: "ai_interactionView_Distance",
    value: "55",
    flags: 4,
    description: "how far away from the ai",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionView_Distance__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionView_OffsetToPlayer''
// EA  : 0x8337AD18
// RVA : 0x0137AD18
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionView_OffsetToPlayer__()
{
  idCVar::idCVar(
    this: &ai_interactionView_OffsetToPlayer,
    name: "ai_interactionView_OffsetToPlayer",
    value: "1",
    flags: 1,
    description: "if true we just do between the ai and player, if false, offset in ai look dir.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionView_OffsetToPlayer__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionView_FOV''
// EA  : 0x8337AD70
// RVA : 0x0137AD70
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionView_FOV__()
{
  idCVar::idCVar(
    this: &ai_interactionView_FOV,
    name: "ai_interactionView_FOV",
    value: "80",
    flags: 4,
    description: "fov of interaction view",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionView_FOV__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionView_CorrectionDistance''
// EA  : 0x8337ADC8
// RVA : 0x0137ADC8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionView_CorrectionDistance__()
{
  idCVar::idCVar(
    this: &ai_interactionView_CorrectionDistance,
    name: "ai_interactionView_CorrectionDistance",
    value: "250",
    flags: 4,
    description: "if where we are and where we think we are supposed to be exceeds this distance, correct",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionView_CorrectionDistance__);
}


// ========================================================================
// `dynamic initializer for 'ai_interactionView_merchantswitch''
// EA  : 0x8337AE20
// RVA : 0x0137AE20
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionView_merchantswitch__()
{
  idCVar::idCVar(
    this: &ai_interactionView_merchantswitch,
    name: "ai_interactionView_merchantswitch",
    value: "150",
    flags: 2,
    description: "ms it takes to move between the buy and sell view of the merchants",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionView_merchantswitch__);
}


// ========================================================================
// `dynamic initializer for 'trailerCameraSpawn_v''
// EA  : 0x8337AE78
// RVA : 0x0137AE78
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__trailerCameraSpawn_v__()
{
  return idCommandLink::idCommandLink(
           this: &trailerCameraSpawn_v,
           cmdName: "trailerCameraSpawn",
           function: trailerCameraSpawn_f,
           description: "spawns a trailer utility camera for capturing cinematics",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'cine_cam_debug''
// EA  : 0x8337AEA0
// RVA : 0x0137AEA0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cine_cam_debug__()
{
  idCVar::idCVar(
    this: &cine_cam_debug,
    name: "cine_cam_debug",
    value: "0",
    flags: 1,
    description: "debug cinematic camera",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cine_cam_debug__);
}


// ========================================================================
// `dynamic initializer for 'cine_captureFrames''
// EA  : 0x8337AEF8
// RVA : 0x0137AEF8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cine_captureFrames__()
{
  idCVar::idCVar(
    this: &cine_captureFrames,
    name: "cine_captureFrames",
    value: "0",
    flags: 1,
    description: "set to 1 to capture the cinematic frames to jpgs/tgas",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cine_captureFrames__);
}


// ========================================================================
// `dynamic initializer for 'revivecam_HeightStart''
// EA  : 0x8337AF50
// RVA : 0x0137AF50
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__revivecam_HeightStart__()
{
  idCVar::idCVar(
    this: &revivecam_HeightStart,
    name: "revivecam_HeightStart",
    value: "85.0f",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__revivecam_HeightStart__);
}


// ========================================================================
// `dynamic initializer for 'revivecam_HeightEnd''
// EA  : 0x8337AFA8
// RVA : 0x0137AFA8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__revivecam_HeightEnd__()
{
  idCVar::idCVar(
    this: &revivecam_HeightEnd,
    name: "revivecam_HeightEnd",
    value: "-25.0f",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__revivecam_HeightEnd__);
}


// ========================================================================
// `dynamic initializer for 'cam_onlineDeathCamLerpDuration''
// EA  : 0x8337B000
// RVA : 0x0137B000
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_onlineDeathCamLerpDuration__()
{
  idCVar::idCVar(
    this: &cam_onlineDeathCamLerpDuration,
    name: "cam_onlineDeathCamLerpDuration",
    value: "5.0",
    flags: 4,
    description: "[s]",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_onlineDeathCamLerpDuration__);
}


// ========================================================================
// `dynamic initializer for 'cam_onlineDeathCamCircleOffset''
// EA  : 0x8337B058
// RVA : 0x0137B058
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_onlineDeathCamCircleOffset__()
{
  idCVar::idCVar(
    this: &cam_onlineDeathCamCircleOffset,
    name: "cam_onlineDeathCamCircleOffset",
    value: "300.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_onlineDeathCamCircleOffset__);
}


// ========================================================================
// `dynamic initializer for 'cam_onlineDeathCamMoveMinLerpSpeed''
// EA  : 0x8337B0B0
// RVA : 0x0137B0B0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_onlineDeathCamMoveMinLerpSpeed__()
{
  idCVar::idCVar(
    this: &cam_onlineDeathCamMoveMinLerpSpeed,
    name: "cam_onlineDeathCamMoveMinLerpSpeed",
    value: "0.01",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_onlineDeathCamMoveMinLerpSpeed__);
}


// ========================================================================
// `dynamic initializer for 'cam_onlineDeathCamMoveMaxLerpSpeed''
// EA  : 0x8337B108
// RVA : 0x0137B108
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_onlineDeathCamMoveMaxLerpSpeed__()
{
  idCVar::idCVar(
    this: &cam_onlineDeathCamMoveMaxLerpSpeed,
    name: "cam_onlineDeathCamMoveMaxLerpSpeed",
    value: "0.03",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_onlineDeathCamMoveMaxLerpSpeed__);
}


// ========================================================================
// `dynamic initializer for 'cam_onlineDeathCamCircleDuration''
// EA  : 0x8337B160
// RVA : 0x0137B160
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_onlineDeathCamCircleDuration__()
{
  idCVar::idCVar(
    this: &cam_onlineDeathCamCircleDuration,
    name: "cam_onlineDeathCamCircleDuration",
    value: "1.5",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_onlineDeathCamCircleDuration__);
}


// ========================================================================
// `dynamic initializer for 'cam_onlineDeathCamDebug''
// EA  : 0x8337B1B8
// RVA : 0x0137B1B8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_onlineDeathCamDebug__()
{
  idCVar::idCVar(
    this: &cam_onlineDeathCamDebug,
    name: "cam_onlineDeathCamDebug",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_onlineDeathCamDebug__);
}


// ========================================================================
// `dynamic initializer for 'cam_onlineDeathCamSuicideViewSpeed''
// EA  : 0x8337B210
// RVA : 0x0137B210
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_onlineDeathCamSuicideViewSpeed__()
{
  idCVar::idCVar(
    this: &cam_onlineDeathCamSuicideViewSpeed,
    name: "cam_onlineDeathCamSuicideViewSpeed",
    value: "0.05",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_onlineDeathCamSuicideViewSpeed__);
}


// ========================================================================
// `dynamic initializer for 'cam_onlineDeathCamStatic''
// EA  : 0x8337B268
// RVA : 0x0137B268
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_onlineDeathCamStatic__()
{
  idCVar::idCVar(
    this: &cam_onlineDeathCamStatic,
    name: "cam_onlineDeathCamStatic",
    value: "0",
    flags: 1,
    description: "Disable all fancy movement on vehicle deathcam",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_onlineDeathCamStatic__);
}


// ========================================================================
// `dynamic initializer for 'cam_onlineDeathCamSpecial''
// EA  : 0x8337B2C0
// RVA : 0x0137B2C0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_onlineDeathCamSpecial__()
{
  idCVar::idCVar(
    this: &cam_onlineDeathCamSpecial,
    name: "cam_onlineDeathCamSpecial",
    value: "1",
    flags: 1,
    description: "Disable all fancy movement on vehicle deathcam",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_onlineDeathCamSpecial__);
}


// ========================================================================
// `dynamic initializer for 'cam_onlineDeathCamDblStart''
// EA  : 0x8337B318
// RVA : 0x0137B318
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_onlineDeathCamDblStart__()
{
  idCVar::idCVar(
    this: &cam_onlineDeathCamDblStart,
    name: "cam_onlineDeathCamDblStart",
    value: "0.1",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_onlineDeathCamDblStart__);
}


// ========================================================================
// `dynamic initializer for 'cam_onlineDeathCamDblStop''
// EA  : 0x8337B370
// RVA : 0x0137B370
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_onlineDeathCamDblStop__()
{
  idCVar::idCVar(
    this: &cam_onlineDeathCamDblStop,
    name: "cam_onlineDeathCamDblStop",
    value: "0.002",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_onlineDeathCamDblStop__);
}


// ========================================================================
// `dynamic initializer for 'cam_onlineDeathCamDblDuration''
// EA  : 0x8337B3C8
// RVA : 0x0137B3C8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_onlineDeathCamDblDuration__()
{
  idCVar::idCVar(
    this: &cam_onlineDeathCamDblDuration,
    name: "cam_onlineDeathCamDblDuration",
    value: "1.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_onlineDeathCamDblDuration__);
}


// ========================================================================
// `dynamic initializer for 'cam_deathCamblurAmount''
// EA  : 0x8337B420
// RVA : 0x0137B420
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_deathCamblurAmount__()
{
  idCVar::idCVar(
    this: &cam_deathCamblurAmount,
    name: "cam_deathCamblurAmount",
    value: "0.1f",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_deathCamblurAmount__);
}


// ========================================================================
// `dynamic initializer for 'cam_deathCamblurTime''
// EA  : 0x8337B478
// RVA : 0x0137B478
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_deathCamblurTime__()
{
  idCVar::idCVar(
    this: &cam_deathCamblurTime,
    name: "cam_deathCamblurTime",
    value: "2.0f",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_deathCamblurTime__);
}


// ========================================================================
// `dynamic initializer for 'cam_onlineDeathDebug''
// EA  : 0x8337B4D0
// RVA : 0x0137B4D0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cam_onlineDeathDebug__()
{
  idCVar::idCVar(
    this: &cam_onlineDeathDebug,
    name: "cam_onlineDeathDebug",
    value: "0",
    flags: 1,
    description: "debug cinematic camera",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cam_onlineDeathDebug__);
}


// ========================================================================
// `dynamic initializer for 'mp_vdm_deathCamGoalDist''
// EA  : 0x8337B528
// RVA : 0x0137B528
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_vdm_deathCamGoalDist__()
{
  idCVar::idCVar(
    this: &mp_vdm_deathCamGoalDist,
    name: "mp_vdm_deathCamGoalDist",
    value: "800.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_vdm_deathCamGoalDist__);
}


// ========================================================================
// `dynamic initializer for 'throwCamera_fadeDelay''
// EA  : 0x8337B580
// RVA : 0x0137B580
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__throwCamera_fadeDelay__()
{
  idCVar::idCVar(
    this: &throwCamera_fadeDelay,
    name: "throwCamera_fadeDelay",
    value: "250",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__throwCamera_fadeDelay__);
}


// ========================================================================
// `dynamic initializer for 'rcbomb_initialOffset''
// EA  : 0x8337B5D8
// RVA : 0x0137B5D8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rcbomb_initialOffset__()
{
  idCVar::idCVar(
    this: &rcbomb_initialOffset,
    name: "rcbomb_initialOffset",
    value: "50.0f",
    flags: 4,
    description: "amount to offset from initial pose",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rcbomb_initialOffset__);
}


// ========================================================================
// `dynamic initializer for 'rcbomb_pulloutTime''
// EA  : 0x8337B630
// RVA : 0x0137B630
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rcbomb_pulloutTime__()
{
  idCVar::idCVar(
    this: &rcbomb_pulloutTime,
    name: "rcbomb_pulloutTime",
    value: "2000",
    flags: 4,
    description: "ms that the camera pulls out from car",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rcbomb_pulloutTime__);
}


// ========================================================================
// `dynamic initializer for 'rcbomb_updownRatio''
// EA  : 0x8337B688
// RVA : 0x0137B688
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rcbomb_updownRatio__()
{
  idCVar::idCVar(
    this: &rcbomb_updownRatio,
    name: "rcbomb_updownRatio",
    value: "0.5",
    flags: 4,
    description: "percentage camera goes up versus back",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rcbomb_updownRatio__);
}


// ========================================================================
// `dynamic initializer for 'rcbomb_pulloutDistance''
// EA  : 0x8337B6E0
// RVA : 0x0137B6E0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rcbomb_pulloutDistance__()
{
  idCVar::idCVar(
    this: &rcbomb_pulloutDistance,
    name: "rcbomb_pulloutDistance",
    value: "500",
    flags: 4,
    description: "how far camera will pullout during death",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rcbomb_pulloutDistance__);
}


// ========================================================================
// `dynamic initializer for 'cine_cameraAccel''
// EA  : 0x8337B738
// RVA : 0x0137B738
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cine_cameraAccel__()
{
  idCVar::idCVar(
    this: &cine_cameraAccel,
    name: "cine_cameraAccel",
    value: "0.10f",
    flags: 4,
    description: "what percentage of the duration to accel and decel",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cine_cameraAccel__);
}


// ========================================================================
// `dynamic initializer for 'cine_ignoreCameraOffsets''
// EA  : 0x8337B790
// RVA : 0x0137B790
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cine_ignoreCameraOffsets__()
{
  idCVar::idCVar(
    this: &cine_ignoreCameraOffsets,
    name: "cine_ignoreCameraOffsets",
    value: "0",
    flags: 1,
    description: "ignore the entity offsets for vehicle camera tags ( useful for setting up cameras) ",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cine_ignoreCameraOffsets__);
}

