
// ========================================================================
// ?aa_AssistMode_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82DF2B08
// RVA : 0x00DF2B08
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __fastcall aa_AssistMode_f(const idCmdArgs *args)
{
  const char *v2; // r3
  unsigned int v3; // r3
  bool v4; // r4
  bool v5; // r4
  double v6; // fp1
  bool v7; // r4
  bool v8; // r4
  bool v9; // r4
  bool v10; // r4

  if ( args->argc != 2 )
    idLib::Printf(fmt: "usage: aa_AssistMode < 0 - 3 >\n");
  if ( args->argc <= 1 )
    v2 = &byte_8200D768;
  else
    v2 = args->argv[1];
  v3 = atol(nptr: v2);
  if ( v3 <= 3 )
  {
    switch ( v3 )
    {
      case 1u:
        idCVar::SetBool(this: &aa_UseOld, newValue: false, force: true);
        idCVar::SetFloat(this: &aa_AssistStrength, newValue: 0.050000001, force: v4);
        idCVar::SetFloat(this: &aa_AssistStrengthSweetSpot, newValue: 0.035, force: v5);
        v6 = 0.02;
        break;
      case 2u:
        idCVar::SetBool(this: &aa_UseOld, newValue: false, force: true);
        idCVar::SetFloat(this: &aa_AssistStrength, newValue: 0.039999999, force: v7);
        idCVar::SetFloat(this: &aa_AssistStrengthSweetSpot, newValue: 0.02, force: v8);
        v6 = 0.0099999998;
        break;
      case 0u:
        idCVar::SetBool(this: &aa_UseOld, newValue: true, force: true);
        return;
      default:
        idCVar::SetBool(this: &aa_UseOld, newValue: false, force: true);
        idCVar::SetFloat(this: &aa_AssistStrength, newValue: 0.0099999998, force: v9);
        idCVar::SetFloat(this: &aa_AssistStrengthSweetSpot, newValue: 0.015, force: v10);
        v6 = 0.0049999999;
        break;
    }
    idCVar::SetFloat(this: &aa_AssistStrengthBestSpot, newValue: v6, force: (const bool)&pb_ss_UpdateAfterPhysics.name);
  }
}


// ========================================================================
// ?Init@idAimAssist@@QAAXPAVidPresentablePlayer@@@Z
// EA  : 0x82DF2CA8
// RVA : 0x00DF2CA8
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __fastcall idAimAssist::Init(idAimAssist *this, idPresentablePlayer *pres)
{
  __int16 *v2; // r11
  int v3; // ctr

  if ( pres != nullptr )
    this->player.spawnId = pres->spawnId;
  else
    this->player.spawnId = 0;
  this->angleCorrection = ang_zero;
  v2 = &this->savedAngle[2];
  v3 = 3;
  this->allowZoomSnap = true;
  this->lastZoomSnap = false;
  this->frictionScalar = 1.0;
  this->desiredFrictionScalar = 1.0;
  this->weaponTraceDistance = aa_lockdist.valueFloat;
  do
  {
    *(v2 - 2) = 0;
    *++v2 = 0;
    --v3;
  }
  while ( v3 != 0 );
}


// ========================================================================
// ?IsValidTarget@idAimAssist@@AAA_NPAVidPresentableAnimatedEntity@@@Z
// EA  : 0x82DF2D30
// RVA : 0x00DF2D30
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

BOOL __fastcall idAimAssist::IsValidTarget(idAimAssist *this, idPresentableAnimatedEntity *target)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_player; // r31
  int v5; // r30
  idPresentable *v6; // r3

  spawnId = this->player.spawnId;
  p_player = (idPresentablePtr<idPresentable> *)&this->player;
  v5 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v5)->spawnId == p_player->spawnId
    && idPresentablePtr<idPresentableProjectile>::operator->(this: p_player) != (idPresentable *)-37616
    && (v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_player),
        idWeapon::CastTo(c: (idWeapon *)LODWORD(v6[35].axes[0].mat[1].z)) != nullptr) )
  {
    return idRenderModel::IsRendered(this: target->model);
  }
  else
  {
    return false;
  }
}


// ========================================================================
// ?ShouldZoomSnap@idAimAssist@@AAA_NXZ
// EA  : 0x82DF2DE8
// RVA : 0x00DF2DE8
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

int __fastcall idAimAssist::ShouldZoomSnap(idAimAssist *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_player; // r30
  int v4; // r31
  idPresentable *PresentableByIndex; // r3
  int GameMs; // r31
  idPresentable *v7; // r25
  idPresentable *v8; // r3
  __int64 v9; // r11
  idPresentable *v10; // r31
  double CurrentValue; // fp1
  unsigned __int8 v12; // r11
  bool v13; // r31
  int v14; // r25
  int v15; // r31
  idPresentable *v16; // r3
  float y; // r11
  idPresentable *v18; // r3
  int v19; // r31
  idPresentable *v20; // r29
  idPresentable *v21; // r3
  __int64 v22; // r11
  unsigned __int8 v24; // r11

  spawnId = this->player.spawnId;
  p_player = (idPresentablePtr<idPresentable> *)&this->player;
  v4 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v4))->spawnId != p_player->spawnId )
  {
    PresentableByIndex = nullptr;
  }
  if ( !idPresentablePlayer::IsZoomedIn(ptr: PresentableByIndex)
    || (GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED),
        v7 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_player),
        v8 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_player),
        LODWORD(v9) = GameMs,
        v10 = v8,
        CurrentValue = idInterpolate<float>::GetCurrentValue(
                         this: (idInterpolate<float> *)&v7[38].fxManager.actionBufferPos,
                         time: (float)v9),
        v12 = 1,
        CurrentValue == *(float *)&v10[38].soundEmitter) )
  {
    v12 = 0;
  }
  v13 = v12;
  v14 = v12;
  if ( v12 != 0 )
  {
    if ( v12 != this->lastZoomSnap
      && idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->thisFrameEntity) != nullptr )
    {
      this->allowZoomSnap = false;
    }
  }
  else
  {
    this->allowZoomSnap = true;
  }
  this->lastZoomSnap = v13;
  v15 = p_player->spawnId & 0x3FFF;
  if ( p_player->spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: p_player->spawnId & 0x3FFF)
    || (v16 = idClientGame::GetPresentableByIndex(this: clientGame, index: v15))->spawnId != p_player->spawnId )
  {
    v16 = nullptr;
  }
  if ( this->zoomSnapThisFrame
    && ((*(&v16[38].fxManager.hasExternalPositionAndRotation + 1) & 0x80) == 0
      ? (y = v16[38].fxManager.externalPosition.y)
      : (LOBYTE(y) = 0),
        (LOBYTE(y) & 8) != 0) )
  {
    v18 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_player);
    if ( idPresentablePlayer::IsZoomedIn(ptr: v18) )
    {
      v19 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v20 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_player);
      v21 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_player);
      LODWORD(v22) = v19;
      if ( idInterpolate<float>::GetCurrentValue(
             this: (idInterpolate<float> *)&v20[38].fxManager.actionBufferPos,
             time: (float)v22) != *(float *)&v21[38].soundEmitter )
        this->zoomSnapThisFrame = false;
    }
    return 1;
  }
  else
  {
    this->zoomSnapThisFrame = false;
    if ( v14 == 0 )
      return 0;
    v24 = 1;
    if ( !this->allowZoomSnap )
      return 0;
    return v24;
  }
}


// ========================================================================
// ?GetAnglesToPosition@idAimAssist@@AAA?AVidAngles@@VidVec3@@@Z
// EA  : 0x82DF3040
// RVA : 0x00DF3040
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idAimAssist *__fastcall idAimAssist::GetAnglesToPosition(
        idAimAssist *this,
        idAngles *result,
        __int64 aimTowards,
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
  float yaw; // r11
  int v15; // r30
  idPresentable *PresentableByIndex; // r11
  float v17; // r11
  int v18; // r30
  float *v19; // r3
  double v20; // fp12
  double v21; // fp11
  idVec3 v23[5]; // [sp+50h] [-40h] BYREF

  yaw = result->yaw;
  a11 = *(__int64 *)((char *)&aimTowards + 4);
  a12 = aimTowards;
  v15 = LOWORD(yaw) & 0x3FFF;
  if ( yaw == 0.0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: LOWORD(yaw) & 0x3FFF)
    || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v15))->spawnId != LODWORD(result->yaw) )
  {
    PresentableByIndex = nullptr;
  }
  idVec3::ToAngles(this: v23, result: (idAngles *)&PresentableByIndex[38].fxManager.actionBuffer[6].condition);
  idAngles::Normalize180(this: (idAngles *)v23);
  v17 = result->yaw;
  v18 = LOWORD(v17) & 0x3FFF;
  if ( v17 == 0.0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: LOWORD(v17) & 0x3FFF)
    || *((_DWORD *)(v19 = (float *)idClientGame::GetPresentableByIndex(this: clientGame, index: v18)) + 275) != LODWORD(result->yaw) )
  {
    v19 = nullptr;
  }
  *(float *)&a11 = *(float *)&a11 - v19[11633];
  *((float *)&a11 + 1) = *((float *)&a11 + 1) - v19[11634];
  *(float *)&a12 = *(float *)&a12 - v19[11635];
  idVec3::ToAngles((idVec3 *)this, result: (idAngles *)&a11);
  idAngles::Normalize180((idAngles *)this);
  v20 = (float)(*(float *)&this->player.spawnId - v23[0].y);
  v21 = (float)(this->angleCorrection.pitch - v23[0].z);
  *(float *)&this->__vftable = *(float *)&this->__vftable - v23[0].x;
  *(float *)&this->player.spawnId = v20;
  this->angleCorrection.pitch = v21;
  idAngles::Normalize180((idAngles *)this);
  return this;
}


// ========================================================================
// ?AdhesionCorrection@idAimAssist@@AAA_NXZ
// EA  : 0x82DF31A0
// RVA : 0x00DF31A0
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idAimAssist::AdhesionCorrection(idAimAssist *this)
{
  idPresentablePtr<idPresentableAnimatedEntity> *p_thisFrameEntity; // r27
  idPresentable *v3; // r3
  int x_high; // r9
  int v5; // r8
  int valueInteger; // r10
  __int16 v7; // r30
  __int16 v8; // r28
  __int128 v9; // r6
  __int64 v10; // r8 OVERLAPPED
  double valueFloat; // fp10
  double v12; // fp11
  double v13; // fp13
  double v14; // fp12
  int v15; // r9
  double v16; // fp13
  double v17; // fp0
  double pitch; // fp12
  __int16 currentYaw; // r9
  int v20; // r10
  int frictionScalar_low; // r11
  __int16 currentPitch; // r8
  const idAngles *v23; // r3
  float *ViewAngles; // r3
  double v25; // fp7
  double v26; // fp6
  idPresentable *v27; // r3
  double v28; // fp2
  double v29; // fp0
  double v30; // fp13
  float y; // r6
  float z; // r8
  idPresentable *v33; // r3
  idPresentable *PresentableByEntityNum; // r3
  idPresentableAnimatedEntity *v35; // r3
  idPresentableAnimatedEntity *v36; // r30
  double v38; // fp13
  double v39; // fp12
  __int64 v40; // [sp+8h] [-168h]
  __int64 v41; // [sp+10h] [-160h]
  __int64 v42; // [sp+18h] [-158h]
  __int64 v43; // [sp+20h] [-150h]
  __int64 v44; // [sp+28h] [-148h]
  idAimAssist v45; // [sp+50h] [-120h] BYREF
  float v46; // [sp+F8h] [-78h]
  float v47; // [sp+FCh] [-74h]
  float v48; // [sp+100h] [-70h]
  int v49; // [sp+12Ch] [-44h]

  if ( g_AimAssist_Disable_Adhesion.valueInteger != 0 )
    return 0;
  p_thisFrameEntity = &this->thisFrameEntity;
  if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->thisFrameEntity) == nullptr )
    return 0;
  if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->lastFrameEntity) == nullptr )
    return 0;
  v3 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player);
  x_high = HIWORD(v3[38].fxManager.actionBuffer[0].org.x);
  v5 = *((unsigned __int16 *)&v3[38].fxManager.hasExternalPositionAndRotation + 1);
  valueInteger = g_AimAssist_Adhesion_While_Still.valueInteger;
  v7 = x_high - this->savedYaw;
  v8 = v5 - this->savedPitch;
  if ( g_AimAssist_Adhesion_While_Still.valueInteger == 0 )
  {
    valueInteger = BYTE2(v3[38].fxManager.externalPosition.z);
    if ( BYTE2(v3[38].fxManager.externalPosition.z) == 0 && LOBYTE(v3[38].fxManager.externalPosition.z) == 0 )
      return 0;
  }
  *(_QWORD *)((char *)&v9 + 4) = *(_QWORD *)&this->lastFrameHitLoc.x;
  LODWORD(v9) = __ROL4__(LODWORD(this->lastFrameHitLoc.z), 32);
  idAimAssist::GetAnglesToPosition(
    this: &v45,
    result: (idAngles *)LODWORD(this->lastFrameHitLoc.x),
    aimTowards: v9,
    a4: x_high - (unsigned __int16)this->savedYaw,
    a5: v5,
    a6: x_high,
    a7: valueInteger,
    a8: v40,
    a9: v41,
    a10: v42,
    a11: v43,
    a12: v44);
  valueFloat = aa_adhesionLockSpeed.valueFloat;
  v12 = -aa_adhesionLockSpeed.valueFloat;
  if ( *(float *)&v45.player.spawnId >= v12 )
  {
    if ( *(float *)&v45.player.spawnId <= valueFloat )
      v13 = *(float *)&v45.player.spawnId;
    else
      v13 = aa_adhesionLockSpeed.valueFloat;
  }
  else
  {
    v13 = -aa_adhesionLockSpeed.valueFloat;
  }
  v14 = *(float *)&v45.__vftable;
  if ( *(float *)&v45.__vftable >= v12 )
  {
    if ( v14 > valueFloat )
      v14 = aa_adhesionLockSpeed.valueFloat;
  }
  else
  {
    v14 = -aa_adhesionLockSpeed.valueFloat;
  }
  v15 = v8;
  LODWORD(v10) = v7;
  *(_QWORD *)&v45.angleCorrection.roll = v10;
  v16 = (float)((float)((float)v10 * (float)0.0054931641) + (float)v13);
  v17 = (float)((float)((float)*(__int64 *)((char *)&v10 - 4) * (float)0.0054931641) + (float)v14);
  if ( v16 >= v12 )
  {
    if ( v16 > valueFloat )
      v16 = aa_adhesionLockSpeed.valueFloat;
  }
  else
  {
    v16 = -aa_adhesionLockSpeed.valueFloat;
  }
  *(float *)&v45.player.spawnId = v16;
  if ( v17 >= v12 )
  {
    if ( v17 > valueFloat )
      v17 = aa_adhesionLockSpeed.valueFloat;
  }
  else
  {
    v17 = -aa_adhesionLockSpeed.valueFloat;
  }
  this->angleCorrection.pitch = v17;
  *(float *)&v45.__vftable = v17;
  pitch = v45.angleCorrection.pitch;
  this->angleCorrection.yaw = v16;
  this->angleCorrection.roll = pitch;
  currentYaw = this->currentYaw;
  LODWORD(v45.frictionScalar) = (int)(float)((float)v16 * (float)182.04445);
  v20 = (__int16)(int)(float)((float)v17 * (float)182.04445);
  frictionScalar_low = SLOWORD(v45.frictionScalar);
  currentPitch = this->currentPitch;
  this->currentYaw = currentYaw + LOWORD(v45.frictionScalar);
  this->currentPitch = currentPitch + v20;
  if ( frictionScalar_low > 2 || frictionScalar_low < -2 || v20 > 2 || v20 < -2 )
  {
    v23 = (const idAngles *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player);
    ViewAngles = (float *)idPresentablePlayer::GetViewAngles(
                            this: (idPresentablePlayer *)&v45.angleCorrection.roll,
                            result: v23,
                            includeWeaponKick: true);
    v25 = (float)(ViewAngles[1] + this->angleCorrection.yaw);
    v26 = (float)(ViewAngles[2] + this->angleCorrection.roll);
    *(float *)&v45.__vftable = *ViewAngles + this->angleCorrection.pitch;
    *(float *)&v45.player.spawnId = v25;
    v45.angleCorrection.pitch = v26;
    idAngles::ToMat3(this: (idAngles *)&v45.thisFrameHitLoc.z, result: (idMat3 *)&v45);
    v27 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player);
    v28 = (float)(v45.thisFrameHitLoc.z * this->weaponTraceDistance);
    v29 = (float)(v45.lastFrameHitLoc.x * this->weaponTraceDistance);
    v30 = (float)(v45.lastFrameHitLoc.y * this->weaponTraceDistance);
    y = v27[38].fxManager.actionBuffer[6].axis.mat[2].y;
    z = v27[38].fxManager.actionBuffer[6].axis.mat[2].z;
    *(float *)&v45.lastZoomSnap = v27[38].fxManager.actionBuffer[6].axis.mat[2].x;
    v45.zoomSnapAimPoint.x = y;
    v45.zoomSnapAimPoint.y = z;
    v45.thisFrameHitLoc.x = z + (float)v30;
    *(float *)&v45.lastFrameEntity.spawnId = y + (float)v29;
    *(float *)&v45.thisFrameEntity.spawnId = *(float *)&v45.lastZoomSnap + (float)v28;
    v33 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player);
    idClip::TracePoint(
      this: &clientGame->clip,
      result: (trace_t *)&v45.deferredHeadPoint,
      start: (const idVec3 *)&v45.lastZoomSnap,
      end: (const idVec3 *)&v45.thisFrameEntity,
      clipMask: 8462469,
      passEntityNumber: v33->entityNumber);
    if ( *(float *)&v45.deferredHeadPoint.index < 1.0 )
    {
      PresentableByEntityNum = idClientGame::GetPresentableByEntityNum(this: clientGame, entityNum: v49);
      if ( PresentableByEntityNum != nullptr )
      {
        v35 = PresentableByEntityNum->GetActorInterface_2(this: PresentableByEntityNum);
        v36 = v35;
        if ( v35 != nullptr
          && idPresentableAnimatedEntity::GetCanAimAssist(this: v35)
          && idAimAssist::IsValidTarget(this, target: v36) )
        {
          v38 = v47;
          v39 = v48;
          this->thisFrameHitLoc.x = v46;
          this->thisFrameHitLoc.y = v38;
          this->thisFrameHitLoc.z = v39;
          return 1;
        }
      }
    }
    p_thisFrameEntity->spawnId = 0;
  }
  return 1;
}


// ========================================================================
// ?UpdateTraceEntity@idAimAssist@@AAAXXZ
// EA  : 0x82DF3558
// RVA : 0x00DF3558
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __fastcall idAimAssist::UpdateTraceEntity(idAimAssist *this)
{
  idVec3 *p_thisFrameHitLoc; // r28
  unsigned int spawnId; // r7
  int v4; // r29
  idPresentable *PresentableByIndex; // r3
  unsigned int v6; // r10
  int v7; // r29
  float y; // r8
  float z; // r7
  float *v10; // r3
  double weaponTraceDistance; // fp0
  unsigned int v12; // r10
  int v13; // r29
  float v14; // r7
  float v15; // r9
  idPresentable *v16; // r3
  idPresentable *PresentableByEntityNum; // r3
  idPresentableAnimatedEntity *v18; // r3
  idPresentableAnimatedEntity *v19; // r30
  double v20; // fp0
  double v21; // fp13
  double x; // fp12
  idVec3 v23; // [sp+50h] [-E0h] BYREF
  float v24; // [sp+60h] [-D0h]
  float v25; // [sp+64h] [-CCh]
  float v26; // [sp+68h] [-C8h]
  idVec3 v27; // [sp+70h] [-C0h] BYREF
  trace_t v28; // [sp+80h] [-B0h] BYREF

  p_thisFrameHitLoc = &this->thisFrameHitLoc;
  this->lastFrameEntity.spawnId = this->thisFrameEntity.spawnId;
  this->lastFrameHitLoc = this->thisFrameHitLoc;
  this->thisFrameEntity.spawnId = 0;
  this->thisFrameHitLoc = vec3_origin;
  spawnId = this->player.spawnId;
  v4 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v4))->spawnId != this->player.spawnId )
  {
    PresentableByIndex = nullptr;
  }
  v6 = this->player.spawnId;
  v7 = v6 & 0x3FFF;
  y = PresentableByIndex[38].fxManager.actionBuffer[6].axis.mat[2].y;
  z = PresentableByIndex[38].fxManager.actionBuffer[6].axis.mat[2].z;
  v23.x = PresentableByIndex[38].fxManager.actionBuffer[6].axis.mat[2].x;
  v23.y = y;
  v23.z = z;
  if ( v6 == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v6 & 0x3FFF)
    || *((_DWORD *)(v10 = (float *)idClientGame::GetPresentableByIndex(this: clientGame, index: v7)) + 275) != this->player.spawnId )
  {
    v10 = nullptr;
  }
  weaponTraceDistance = this->weaponTraceDistance;
  v12 = this->player.spawnId;
  v13 = v12 & 0x3FFF;
  v14 = v10[11638];
  v15 = v10[11637];
  v24 = v10[11636];
  v26 = v14;
  v25 = v15;
  v27.y = v23.y + (float)(v15 * (float)weaponTraceDistance);
  v27.z = v23.z + (float)(v14 * (float)weaponTraceDistance);
  v27.x = v23.x + (float)(v24 * (float)weaponTraceDistance);
  if ( v12 == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v12 & 0x3FFF)
    || (v16 = idClientGame::GetPresentableByIndex(this: clientGame, index: v13))->spawnId != this->player.spawnId )
  {
    v16 = nullptr;
  }
  idClip::TracePoint(
    this: &clientGame->clip,
    result: &v28,
    start: &v23,
    end: &v27,
    clipMask: 8462469,
    passEntityNumber: v16->entityNumber);
  if ( v28.fraction < 1.0 )
  {
    PresentableByEntityNum = idClientGame::GetPresentableByEntityNum(this: clientGame, entityNum: v28.c.entityNum);
    if ( PresentableByEntityNum != nullptr )
    {
      v18 = PresentableByEntityNum->GetAnimatedEntityInterface(this: PresentableByEntityNum);
      v19 = v18;
      if ( v18 != nullptr
        && idPresentableAnimatedEntity::GetCanAimAssist(this: v18)
        && idAimAssist::IsValidTarget(this, target: v19) )
      {
        v20 = v28.c.point.y;
        v21 = v28.c.point.z;
        x = v28.c.point.x;
        this->thisFrameEntity.spawnId = v19->spawnId;
        p_thisFrameHitLoc->y = v20;
        p_thisFrameHitLoc->z = v21;
        p_thisFrameHitLoc->x = x;
        this->frictionScalar = aa_focusSensitivityScale.valueFloat;
      }
    }
  }
}


// ========================================================================
// ?TraceToAimAssistLocation@idAimAssist@@AAA_NAAVidVec3@@PAVidPresentableAnimatedEntity@@@Z
// EA  : 0x82DF37D8
// RVA : 0x00DF37D8
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

int __fastcall idAimAssist::TraceToAimAssistLocation(idAimAssist *this, idVec3 *aim, idPresentableAnimatedEntity *ae)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_player; // r29
  int v7; // r30
  idPresentable *PresentableByIndex; // r3
  int v9; // r30
  bool v10; // cr58
  float y; // r8
  float z; // r7
  double v13; // fp31
  double v14; // fp30
  double v15; // fp29
  float *v16; // r3
  double v17; // fp9
  double v18; // fp8
  idPresentable *v19; // r3
  double v21; // fp13
  double v22; // fp12
  idVec3 v23; // [sp+50h] [-110h] BYREF
  idVec3 v24; // [sp+60h] [-100h] BYREF
  _BYTE v25[32]; // [sp+70h] [-F0h] BYREF
  trace_t v26; // [sp+90h] [-D0h] BYREF

  spawnId = this->player.spawnId;
  p_player = (idPresentablePtr<idPresentable> *)&this->player;
  v7 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v7))->spawnId != p_player->spawnId )
  {
    PresentableByIndex = nullptr;
  }
  v9 = p_player->spawnId & 0x3FFF;
  v10 = p_player->spawnId == 0;
  y = PresentableByIndex[38].fxManager.actionBuffer[6].axis.mat[2].y;
  z = PresentableByIndex[38].fxManager.actionBuffer[6].axis.mat[2].z;
  v24.x = PresentableByIndex[38].fxManager.actionBuffer[6].axis.mat[2].x;
  v24.y = y;
  v24.z = z;
  if ( !v10 && idClientGame::IsPresentableIndexValid(this: clientGame, index: v9) )
    idClientGame::GetPresentableByIndex(this: clientGame, index: v9);
  if ( ae == nullptr )
    return 0;
  idPresentableAnimatedEntity::GetEyePos(this: ae, eyePos: &v23);
  v13 = (float)(v23.x * (float)0.64999998);
  v14 = (float)(v23.y * (float)0.64999998);
  v15 = (float)(v23.z * (float)0.64999998);
  v16 = (float *)ae->GetAbsBounds(this: v25, result: ae, a3: -1);
  v17 = (float)((float)((float)(v16[4] + v16[1]) * (float)0.5) * (float)0.34999999);
  v18 = (float)((float)((float)(v16[5] + v16[2]) * (float)0.5) * (float)0.34999999);
  v23.x = (float)((float)((float)(v16[3] + *v16) * (float)0.5) * (float)0.34999999) + (float)v13;
  v23.y = (float)v17 + (float)v14;
  v23.z = (float)v18 + (float)v15;
  v19 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_player);
  idClip::TracePoint(
    this: &clientGame->clip,
    result: &v26,
    start: &v24,
    end: &v23,
    clipMask: 8462469,
    passEntityNumber: v19->entityNumber);
  if ( v26.fraction >= 1.0 || v26.c.entityNum != ae->entityNumber )
    return 0;
  v21 = v23.y;
  v22 = v23.z;
  aim->x = v23.x;
  aim->y = v21;
  aim->z = v22;
  return 1;
}


// ========================================================================
// ?CalculateAimAssist@idAimAssist@@AAAPAVidPresentableAnimatedEntity@@AAVidVec3@@0AAMAA_N@Z
// EA  : 0x82DF39F0
// RVA : 0x00DF39F0
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

idPresentableAnimatedEntity *__fastcall idAimAssist::CalculateAimAssist(
        idAimAssist *this,
        idVec3 *aim,
        idVec3 *aimPoint,
        float *aimAsisstStrength,
        bool *canZoomSnap)
{
  idPresentablePtr<idPresentablePlayer> *p_player; // r29
  unsigned int spawnId; // r11
  int v12; // r30
  __int64 v13; // r4
  __int64 v14; // r10
  unsigned int v15; // r6
  __int64 v16; // fp12
  __int128 v17; // r5
  double v18; // fp2
  int v19; // r30
  double v20; // fp1
  double v21; // fp12
  double v24; // fp6
  double v25; // fp10
  double v26; // fp30
  double v27; // fp31
  idPresentablePlayer *PresentableByIndex; // r3
  double y; // fp12
  double v30; // fp9
  double z; // fp11
  double x; // fp10
  idPresentableAnimatedEntity *result; // r3
  double v34; // fp15
  double v35; // fp8
  double v36; // fp2
  double v37; // fp1
  double v38; // fp6
  double v39; // fp5
  double v40; // fp4
  idClientGame *v41; // r26
  double v42; // fp27
  float v43; // r25
  idPresentableAnimatedEntity *v44; // r28
  double v45; // fp6
  double v46; // fp0
  double v47; // fp13
  double v48; // fp12
  double v49; // fp31
  double v50; // fp30
  double v51; // fp24
  double v52; // fp29
  double v53; // fp25
  double v54; // fp23
  double v55; // fp9
  double v56; // fp8
  double v57; // fp20
  double v58; // fp8
  double v59; // fp7
  double v60; // fp5
  double v61; // fp6
  double v62; // fp26
  double v63; // fp27
  double v64; // fp28
  double v65; // fp22
  double v66; // fp21
  double v67; // fp1
  int valueInteger; // r30
  double v69; // fp31
  double v70; // fp30
  double v71; // fp29
  __int64 v72; // r10
  __int64 v73; // r8
  __int64 v74; // r6
  va *v75; // r3
  double v76; // fp31
  double v77; // fp30
  idPresentablePtr<idPresentable> *v78; // r3
  double v79; // fp29
  idPresentable *v80; // r3
  int v81; // r3
  idAmmoItem *v82; // r3
  const idDeclProjectile *ProjectileDef; // r3
  double aimAssistZoomSnapScale; // fp0
  double v85; // fp0
  double v86; // fp12
  int v87; // r11
  double valueFloat; // fp0
  int v89; // [sp+8h] [-12C8h]
  int v90; // [sp+Ch] [-12C4h]
  int v91; // [sp+10h] [-12C0h]
  int v92; // [sp+14h] [-12BCh]
  int v93; // [sp+18h] [-12B8h]
  int v94; // [sp+1Ch] [-12B4h]
  float v95; // [sp+60h] [-1270h] BYREF
  float v96; // [sp+64h] [-126Ch]
  float v97; // [sp+68h] [-1268h]
  float v98; // [sp+6Ch] [-1264h]
  __int64 v99; // [sp+70h] [-1260h]
  idVec3 v100; // [sp+78h] [-1258h] BYREF
  idVec3 v101; // [sp+88h] [-1248h] BYREF
  idVec3 v102; // [sp+98h] [-1238h] BYREF
  float v103; // [sp+A8h] [-1228h] BYREF
  float v104; // [sp+ACh] [-1224h]
  float v105; // [sp+B0h] [-1220h]
  idPresentableAnimatedEntity *v106; // [sp+B4h] [-121Ch]
  float v107; // [sp+B8h] [-1218h]
  int v108; // [sp+BCh] [-1214h]
  float v109; // [sp+C0h] [-1210h]
  idMat3 v110; // [sp+D0h] [-1200h] BYREF
  idVec3 v111; // [sp+F8h] [-11D8h] BYREF
  idVec3 v112; // [sp+108h] [-11C8h] BYREF
  float v113; // [sp+114h] [-11BCh]
  float v114; // [sp+118h] [-11B8h]
  float v115; // [sp+11Ch] [-11B4h]
  idPresentablePtr<idPresentablePlayer> *v116; // [sp+120h] [-11B0h]
  float v117; // [sp+124h] [-11ACh]
  idVec3 v118; // [sp+128h] [-11A8h] BYREF
  float v119[4]; // [sp+138h] [-1198h] BYREF
  float v120[6]; // [sp+148h] [-1188h] BYREF
  float v121[4]; // [sp+160h] [-1170h] BYREF
  float v122[4]; // [sp+170h] [-1160h] BYREF
  float v123[6]; // [sp+180h] [-1150h] BYREF
  float v124; // [sp+198h] [-1138h]
  va v125; // [sp+1A0h] [-1130h] BYREF

  p_player = &this->player;
  v116 = &this->player;
  spawnId = this->player.spawnId;
  v12 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (HIDWORD(v13) = idClientGame::GetPresentableByIndex(this: clientGame, index: v12),
        *(_DWORD *)(HIDWORD(v13) + 1100) != p_player->spawnId) )
  {
    HIDWORD(v13) = 0;
  }
  HIDWORD(v14) = (unsigned __int16)this->savedAngle[1];
  LODWORD(v13) = this->savedAngle[0];
  v15 = p_player->spawnId;
  LODWORD(v14) = SWORD1(v14);
  v99 = v14;
  v16 = v14;
  v18 = (float)v13;
  WORD1(v14) = *(_WORD *)(HIDWORD(v13) + 46038);
  DWORD1(v17) = *(unsigned __int16 *)(HIDWORD(v13) + 46040);
  LODWORD(v17) = SWORD3(v17);
  DWORD2(v17) = SWORD1(v14);
  v99 = *(_QWORD *)((char *)&v17 + 4);
  v19 = v15 & 0x3FFF;
  v20 = (float)((float)(__int64)v17 - (float)v16);
  v21 = (float)((float)*(__int64 *)((char *)&v17 + 4) - (float)v18);
  _FP9 = (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f7, f9, f10, f13 }
  v24 = __frsqrte(_FP7);
  v25 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24
                                                                                      * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))
                                                                                              * (float)0.5))
                                                                              * (float)v24)
                                                                      - (float)1.5)
                                                      * (float)v24)
                                              * (float)((float)((float)((float)v21 * (float)v21)
                                                              + (float)((float)v20 * (float)v20))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v24
                                                                              * (float)((float)((float)((float)v21 * (float)v21)
                                                                                              + (float)((float)v20 * (float)v20))
                                                                                      * (float)0.5))
                                                                      * (float)v24)
                                                              - (float)1.5)
                                              * (float)v24))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v24
                                                      * (float)((float)((float)((float)v21 * (float)v21)
                                                                      + (float)((float)v20 * (float)v20))
                                                              * (float)0.5))
                                              * (float)v24)
                                      - (float)1.5)
                      * (float)v24));
  v26 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24)
                                                                                              * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                              * (float)v24))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)) * (float)0.5))
                                                                                              * (float)v24)
                                                                                      - (float)1.5)
                                                                      * (float)v24))
                                                      * (float)((float)((float)((float)v21 * (float)v21)
                                                                      + (float)((float)v20 * (float)v20))
                                                              * (float)0.5))
                                              * (float)v25)
                                      - (float)1.5)
                      * (float)v25)
              * (float)v20);
  v124 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                               * (float)v24)
                                                                                       * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))
                                                                                               * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                       * (float)v24))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v24
                                                                                               * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)) * (float)0.5))
                                                                                       * (float)v24)
                                                                               - (float)1.5)
                                                               * (float)v24))
                                               * (float)((float)((float)((float)v21 * (float)v21)
                                                               + (float)((float)v20 * (float)v20))
                                                       * (float)0.5))
                                       * (float)v25)
                               - (float)1.5)
               * (float)v25)
       * (float)v20;
  v27 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24)
                                                                                              * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                              * (float)v24))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)) * (float)0.5))
                                                                                              * (float)v24)
                                                                                      - (float)1.5)
                                                                      * (float)v24))
                                                      * (float)((float)((float)((float)v21 * (float)v21)
                                                                      + (float)((float)v20 * (float)v20))
                                                              * (float)0.5))
                                              * (float)v25)
                                      - (float)1.5)
                      * (float)v25)
              * (float)v21);
  if ( v15 == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v15 & 0x3FFF)
    || (PresentableByIndex = (idPresentablePlayer *)idClientGame::GetPresentableByIndex(this: clientGame, index: v19))->spawnId != p_player->spawnId )
  {
    PresentableByIndex = nullptr;
  }
  idPresentablePlayer::GetViewTransform(this: PresentableByIndex, origin: &v100, axis: &v110);
  y = v110.mat[0].y;
  v30 = v100.y;
  z = v110.mat[0].z;
  x = v100.x;
  result = nullptr;
  v34 = (float)((float)v27 * (float)-1.0);
  v117 = -1.0;
  v35 = v100.z;
  v36 = v110.mat[1].y;
  v106 = nullptr;
  v108 = 0;
  v37 = (float)(v110.mat[1].x * (float)v26);
  v38 = (float)(v100.y + (float)(v110.mat[0].y * (float)36.0));
  v39 = (float)(v100.z + (float)(v110.mat[0].z * (float)36.0));
  v40 = (float)(v110.mat[0].x * (float)36.0);
  aim->x = v110.mat[0].x;
  aim->y = y;
  aim->z = z;
  aimPoint->y = v30;
  aimPoint->z = v35;
  aimPoint->x = x;
  *aimAsisstStrength = 0.0;
  *canZoomSnap = false;
  v41 = clientGame;
  v109 = 1.0e30;
  v101.y = (float)((float)v38 + (float)((float)v36 * (float)v26))
         + (float)(v110.mat[2].y * (float)((float)v27 * (float)-1.0));
  v101.z = (float)((float)v39 + (float)(v110.mat[1].z * (float)v26))
         + (float)(v110.mat[2].z * (float)((float)v27 * (float)-1.0));
  v101.x = (float)((float)((float)x + (float)v40) + (float)v37)
         + (float)(v110.mat[2].x * (float)((float)v27 * (float)-1.0));
  if ( clientGame->aimAssistTargets.num > 0 )
  {
    v98 = 0.0;
    v42 = 1.0;
    v115 = 0.15000001;
    v114 = 16.0;
    v113 = 2.0;
    v107 = 1.0;
    HIDWORD(v99) = &aa_AssistStrengthBestSpot;
    while ( 1 )
    {
      v43 = v98;
      v44 = *(idPresentableAnimatedEntity **)((char *)v41->aimAssistTargets.list + LODWORD(v98));
      if ( idAimAssist::IsValidTarget(this, target: v44)
        && (float)((float)((float)(v100.x - v44->origin.x) * (float)(v100.x - v44->origin.x))
                 + (float)((float)((float)(v100.z - v44->origin.z) * (float)(v100.z - v44->origin.z))
                         + (float)((float)(v100.y - v44->origin.y) * (float)(v100.y - v44->origin.y)))) <= (double)(float)(this->weaponTraceDistance * this->weaponTraceDistance) )
      {
        v44->GetAbsBounds(this: (struct idPresentableAnimatedEntity *)v123, result: (idBounds *)v44, a3: -1);
        idPresentableAnimatedEntity::GetEyePos(this: v44, eyePos: &v118);
        v45 = (float)(v44->origin.x * (float)0.75);
        v46 = (float)((float)(v118.y * (float)0.25) + (float)(v44->origin.y * (float)0.75));
        v47 = (float)((float)(v118.z * (float)0.25) + (float)(v44->origin.z * (float)0.75));
        v119[2] = (float)(v118.z * (float)0.25) + (float)(v44->origin.z * (float)0.75);
        v119[1] = v46;
        v48 = (float)((float)(v118.x * (float)0.25) + (float)v45);
        v119[0] = (float)(v118.x * (float)0.25) + (float)v45;
        v49 = v110.mat[0].y;
        v50 = v110.mat[0].z;
        v51 = v100.y;
        v52 = v110.mat[0].x;
        v53 = v100.z;
        v54 = v100.x;
        v55 = (float)(v118.x - v119[0]);
        v98 = (float)((float)(v100.z - (float)v47) * (float)(v118.z - (float)v47))
            + (float)((float)(v100.y - (float)v46) * (float)(v118.y - (float)v46));
        v56 = (float)((float)(v110.mat[0].x * (float)(v118.x - v119[0]))
                    + (float)((float)(v110.mat[0].z * (float)(v118.z - (float)v47))
                            + (float)(v110.mat[0].y * (float)(v118.y - (float)v46))));
        v57 = __fsqrts((float)((float)((float)(v119[0] - v118.x) * (float)(v119[0] - v118.x))
                             + (float)((float)((float)((float)v47 - v118.z) * (float)((float)v47 - v118.z))
                                     + (float)((float)((float)v46 - v118.y) * (float)((float)v46 - v118.y)))));
        if ( __fabs((float)((float)((float)((float)((float)(v118.x - v119[0]) * (float)(v118.x - v119[0]))
                                          + (float)((float)((float)(v118.z - (float)v47) * (float)(v118.z - (float)v47))
                                                  + (float)((float)(v118.y - (float)v46) * (float)(v118.y - (float)v46))))
                                  * (float)((float)(v110.mat[0].x * v110.mat[0].x)
                                          + (float)((float)(v110.mat[0].z * v110.mat[0].z)
                                                  + (float)(v110.mat[0].y * v110.mat[0].y))))
                          - (float)((float)v56 * (float)v56))) >= 0.0000001 )
        {
          v59 = (float)((float)(v110.mat[0].x
                              * (float)((float)((float)((float)((float)((float)(v100.x
                                                                              - (float)((float)(v118.x * (float)0.25)
                                                                                      + (float)v45))
                                                                      * (float)(v118.x
                                                                              - (float)((float)(v118.x * (float)0.25)
                                                                                      + (float)v45)))
                                                              + v98)
                                                      * (float)v56)
                                              - (float)((float)((float)(v110.mat[0].x
                                                                      * (float)(v100.x
                                                                              - (float)((float)(v118.x * (float)0.25)
                                                                                      + (float)v45)))
                                                              + (float)((float)(v110.mat[0].z
                                                                              * (float)(v100.z - (float)v47))
                                                                      + (float)(v110.mat[0].y
                                                                              * (float)(v100.y - (float)v46))))
                                                      * (float)((float)((float)v55 * (float)v55)
                                                              + (float)((float)((float)(v118.z - (float)v47)
                                                                              * (float)(v118.z - (float)v47))
                                                                      + (float)((float)(v118.y - (float)v46)
                                                                              * (float)(v118.y - (float)v46))))))
                                      * (float)((float)v42
                                              / (float)((float)((float)((float)((float)v55 * (float)v55)
                                                                      + (float)((float)((float)(v118.z - (float)v47)
                                                                                      * (float)(v118.z - (float)v47))
                                                                              + (float)((float)(v118.y - (float)v46)
                                                                                      * (float)(v118.y - (float)v46))))
                                                              * (float)((float)(v110.mat[0].x * v110.mat[0].x)
                                                                      + (float)((float)(v110.mat[0].z * v110.mat[0].z)
                                                                              + (float)(v110.mat[0].y * v110.mat[0].y))))
                                                      - (float)((float)v56 * (float)v56)))))
                      + v100.x);
          v103 = (float)(v110.mat[0].x
                       * (float)((float)((float)((float)((float)((float)(v100.x
                                                                       - (float)((float)(v118.x * (float)0.25)
                                                                               + (float)v45))
                                                               * (float)(v118.x
                                                                       - (float)((float)(v118.x * (float)0.25)
                                                                               + (float)v45)))
                                                       + v98)
                                               * (float)v56)
                                       - (float)((float)((float)(v110.mat[0].x
                                                               * (float)(v100.x
                                                                       - (float)((float)(v118.x * (float)0.25)
                                                                               + (float)v45)))
                                                       + (float)((float)(v110.mat[0].z * (float)(v100.z - (float)v47))
                                                               + (float)(v110.mat[0].y * (float)(v100.y - (float)v46))))
                                               * (float)((float)((float)v55 * (float)v55)
                                                       + (float)((float)((float)(v118.z - (float)v47)
                                                                       * (float)(v118.z - (float)v47))
                                                               + (float)((float)(v118.y - (float)v46)
                                                                       * (float)(v118.y - (float)v46))))))
                               * (float)((float)v42
                                       / (float)((float)((float)((float)((float)v55 * (float)v55)
                                                               + (float)((float)((float)(v118.z - (float)v47)
                                                                               * (float)(v118.z - (float)v47))
                                                                       + (float)((float)(v118.y - (float)v46)
                                                                               * (float)(v118.y - (float)v46))))
                                                       * (float)((float)(v110.mat[0].x * v110.mat[0].x)
                                                               + (float)((float)(v110.mat[0].z * v110.mat[0].z)
                                                                       + (float)(v110.mat[0].y * v110.mat[0].y))))
                                               - (float)((float)v56 * (float)v56)))))
               + v100.x;
          v60 = (float)((float)(v110.mat[0].z
                              * (float)((float)((float)((float)((float)((float)(v100.x
                                                                              - (float)((float)(v118.x * (float)0.25)
                                                                                      + (float)v45))
                                                                      * (float)(v118.x
                                                                              - (float)((float)(v118.x * (float)0.25)
                                                                                      + (float)v45)))
                                                              + v98)
                                                      * (float)v56)
                                              - (float)((float)((float)(v110.mat[0].x
                                                                      * (float)(v100.x
                                                                              - (float)((float)(v118.x * (float)0.25)
                                                                                      + (float)v45)))
                                                              + (float)((float)(v110.mat[0].z
                                                                              * (float)(v100.z - (float)v47))
                                                                      + (float)(v110.mat[0].y
                                                                              * (float)(v100.y - (float)v46))))
                                                      * (float)((float)((float)v55 * (float)v55)
                                                              + (float)((float)((float)(v118.z - (float)v47)
                                                                              * (float)(v118.z - (float)v47))
                                                                      + (float)((float)(v118.y - (float)v46)
                                                                              * (float)(v118.y - (float)v46))))))
                                      * (float)((float)v42
                                              / (float)((float)((float)((float)((float)v55 * (float)v55)
                                                                      + (float)((float)((float)(v118.z - (float)v47)
                                                                                      * (float)(v118.z - (float)v47))
                                                                              + (float)((float)(v118.y - (float)v46)
                                                                                      * (float)(v118.y - (float)v46))))
                                                              * (float)((float)(v110.mat[0].x * v110.mat[0].x)
                                                                      + (float)((float)(v110.mat[0].z * v110.mat[0].z)
                                                                              + (float)(v110.mat[0].y * v110.mat[0].y))))
                                                      - (float)((float)v56 * (float)v56)))))
                      + v100.z);
          v105 = (float)(v110.mat[0].z
                       * (float)((float)((float)((float)((float)((float)(v100.x
                                                                       - (float)((float)(v118.x * (float)0.25)
                                                                               + (float)v45))
                                                               * (float)(v118.x
                                                                       - (float)((float)(v118.x * (float)0.25)
                                                                               + (float)v45)))
                                                       + v98)
                                               * (float)v56)
                                       - (float)((float)((float)(v110.mat[0].x
                                                               * (float)(v100.x
                                                                       - (float)((float)(v118.x * (float)0.25)
                                                                               + (float)v45)))
                                                       + (float)((float)(v110.mat[0].z * (float)(v100.z - (float)v47))
                                                               + (float)(v110.mat[0].y * (float)(v100.y - (float)v46))))
                                               * (float)((float)((float)v55 * (float)v55)
                                                       + (float)((float)((float)(v118.z - (float)v47)
                                                                       * (float)(v118.z - (float)v47))
                                                               + (float)((float)(v118.y - (float)v46)
                                                                       * (float)(v118.y - (float)v46))))))
                               * (float)((float)v42
                                       / (float)((float)((float)((float)((float)v55 * (float)v55)
                                                               + (float)((float)((float)(v118.z - (float)v47)
                                                                               * (float)(v118.z - (float)v47))
                                                                       + (float)((float)(v118.y - (float)v46)
                                                                               * (float)(v118.y - (float)v46))))
                                                       * (float)((float)(v110.mat[0].x * v110.mat[0].x)
                                                               + (float)((float)(v110.mat[0].z * v110.mat[0].z)
                                                                       + (float)(v110.mat[0].y * v110.mat[0].y))))
                                               - (float)((float)v56 * (float)v56)))))
               + v100.z;
          v61 = (float)((float)(v110.mat[0].y
                              * (float)((float)((float)((float)((float)((float)(v100.x
                                                                              - (float)((float)(v118.x * (float)0.25)
                                                                                      + (float)v45))
                                                                      * (float)(v118.x
                                                                              - (float)((float)(v118.x * (float)0.25)
                                                                                      + (float)v45)))
                                                              + v98)
                                                      * (float)v56)
                                              - (float)((float)((float)(v110.mat[0].x
                                                                      * (float)(v100.x
                                                                              - (float)((float)(v118.x * (float)0.25)
                                                                                      + (float)v45)))
                                                              + (float)((float)(v110.mat[0].z
                                                                              * (float)(v100.z - (float)v47))
                                                                      + (float)(v110.mat[0].y
                                                                              * (float)(v100.y - (float)v46))))
                                                      * (float)((float)((float)v55 * (float)v55)
                                                              + (float)((float)((float)(v118.z - (float)v47)
                                                                              * (float)(v118.z - (float)v47))
                                                                      + (float)((float)(v118.y - (float)v46)
                                                                              * (float)(v118.y - (float)v46))))))
                                      * (float)((float)v42
                                              / (float)((float)((float)((float)((float)v55 * (float)v55)
                                                                      + (float)((float)((float)(v118.z - (float)v47)
                                                                                      * (float)(v118.z - (float)v47))
                                                                              + (float)((float)(v118.y - (float)v46)
                                                                                      * (float)(v118.y - (float)v46))))
                                                              * (float)((float)(v110.mat[0].x * v110.mat[0].x)
                                                                      + (float)((float)(v110.mat[0].z * v110.mat[0].z)
                                                                              + (float)(v110.mat[0].y * v110.mat[0].y))))
                                                      - (float)((float)v56 * (float)v56)))))
                      + v100.y);
          v104 = (float)(v110.mat[0].y
                       * (float)((float)((float)((float)((float)((float)(v100.x - v119[0]) * (float)(v118.x - v119[0]))
                                                       + v98)
                                               * (float)v56)
                                       - (float)((float)((float)(v110.mat[0].x * (float)(v100.x - v119[0]))
                                                       + (float)((float)(v110.mat[0].z * (float)(v100.z - (float)v47))
                                                               + (float)(v110.mat[0].y * (float)(v100.y - (float)v46))))
                                               * (float)((float)((float)v55 * (float)v55)
                                                       + (float)((float)((float)(v118.z - (float)v47)
                                                                       * (float)(v118.z - (float)v47))
                                                               + (float)((float)(v118.y - (float)v46)
                                                                       * (float)(v118.y - (float)v46))))))
                               * (float)((float)v42
                                       / (float)((float)((float)((float)((float)v55 * (float)v55)
                                                               + (float)((float)((float)(v118.z - (float)v47)
                                                                               * (float)(v118.z - (float)v47))
                                                                       + (float)((float)(v118.y - (float)v46)
                                                                               * (float)(v118.y - (float)v46))))
                                                       * (float)((float)(v110.mat[0].x * v110.mat[0].x)
                                                               + (float)((float)(v110.mat[0].z * v110.mat[0].z)
                                                                       + (float)(v110.mat[0].y * v110.mat[0].y))))
                                               - (float)((float)v56 * (float)v56)))))
               + v100.y;
          v58 = (float)((float)((float)((float)((float)((float)(v100.x - v119[0]) * (float)(v118.x - v119[0])) + v98)
                                      * (float)((float)(v110.mat[0].x * v110.mat[0].x)
                                              + (float)((float)(v110.mat[0].z * v110.mat[0].z)
                                                      + (float)(v110.mat[0].y * v110.mat[0].y))))
                              - (float)((float)((float)(v110.mat[0].x * (float)(v100.x - v119[0]))
                                              + (float)((float)(v110.mat[0].z * (float)(v100.z - (float)v47))
                                                      + (float)(v110.mat[0].y * (float)(v100.y - (float)v46))))
                                      * (float)v56))
                      * (float)((float)v42
                              / (float)((float)((float)((float)((float)(v118.x - v119[0]) * (float)(v118.x - v119[0]))
                                                      + (float)((float)((float)(v118.z - (float)v47)
                                                                      * (float)(v118.z - (float)v47))
                                                              + (float)((float)(v118.y - (float)v46)
                                                                      * (float)(v118.y - (float)v46))))
                                              * (float)((float)(v110.mat[0].x * v110.mat[0].x)
                                                      + (float)((float)(v110.mat[0].z * v110.mat[0].z)
                                                              + (float)(v110.mat[0].y * v110.mat[0].y))))
                                      - (float)((float)v56 * (float)v56))));
          if ( v58 >= 0.0 )
          {
            if ( v58 <= v42 )
            {
              v62 = (float)((float)((float)(v118.x - v119[0]) * (float)v58) + (float)v48);
              v63 = (float)((float)((float)(v118.y - (float)v46) * (float)v58) + (float)v46);
              v64 = (float)((float)((float)(v118.z - (float)v47) * (float)v58) + (float)v47);
            }
            else
            {
              v62 = v118.x;
              v63 = v118.y;
              v64 = v118.z;
            }
          }
          else
          {
            v62 = v48;
            v63 = v46;
            v64 = v47;
          }
          v95 = v62;
          v96 = v63;
          v65 = (float)((float)v57 * v113);
          v97 = v64;
          v102.y = (float)v63 - (float)v61;
          v102.z = (float)v64 - (float)v60;
          v102.x = (float)v62 - (float)v59;
          v66 = __fsqrts((float)((float)(v102.x * v102.x) + (float)((float)(v102.z * v102.z) + (float)(v102.y * v102.y))));
          if ( v66 <= v65 )
          {
            v111.x = (float)((float)(v123[0] + v123[3]) * (float)0.5) - v100.x;
            v111.y = (float)((float)(v123[1] + v123[4]) * (float)0.5) - v100.y;
            v111.z = (float)((float)(v123[2] + v123[5]) * (float)0.5) - v100.z;
            v67 = idVec3::NormalizeFast(this: &v111);
            if ( (float)((float)((float)v50 * v111.z)
                       + (float)((float)((float)v49 * v111.y) + (float)((float)v52 * v111.x))) >= 0.0
              && (float)((float)((float)((float)v54 - (float)v62) * (float)((float)v54 - (float)v62))
                       + (float)((float)((float)((float)v53 - (float)v64) * (float)((float)v53 - (float)v64))
                               + (float)((float)((float)v51 - (float)v63) * (float)((float)v51 - (float)v63)))) >= (double)(float)(aa_minAssistDistance.valueFloat * aa_minAssistDistance.valueFloat) )
            {
              valueInteger = aa_TargetDebug.valueInteger;
              if ( aa_TargetDebug.valueInteger != 0 )
              {
                v122[2] = v64;
                v122[0] = v62;
                v122[1] = v63;
                v122[3] = 0.5;
                ((void (__fastcall *)(idRenderWorld *, idColor *, float *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugSphere)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorYellow,
                  a3: v122,
                  a4: 12,
                  a5: 0,
                  a6: 0,
                  a7: v67);
                v121[3] = 0.5;
                v121[0] = v103;
                v121[1] = v104;
                v121[2] = v105;
                clientGame->renderWorld->DebugSphere(
                  this: clientGame->renderWorld,
                  a2: (const idVec4 *)&idColor::colorBlue,
                  a3: (const idSphere *)v121,
                  a4: 12,
                  a5: 0,
                  a6: false);
                clientGame->renderWorld->DebugLine(
                  this: clientGame->renderWorld,
                  a2: (const idVec4 *)&idColor::colorRed,
                  a3: (const idVec3 *)&v95,
                  a4: (const idVec3 *)&v103,
                  a5: 0,
                  a6: false);
                clientGame->renderWorld->DebugLine(
                  this: clientGame->renderWorld,
                  a2: (const idVec4 *)&idColor::colorRed,
                  a3: &v118,
                  a4: (const idVec3 *)v119,
                  a5: 0,
                  a6: false);
                ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idMat3 *, double))clientGame->renderWorld->DebugCircle)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorYellow,
                  a3: &v95,
                  a4: &v110,
                  a5: v57);
                ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idMat3 *, double))clientGame->renderWorld->DebugCircle)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorYellow,
                  a3: &v95,
                  a4: &v110,
                  a5: v65);
                ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idMat3 *, double))clientGame->renderWorld->DebugCircle)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorYellow,
                  a3: &v95,
                  a4: &v110,
                  a5: (float)((float)v57 * (float)0.5));
                v53 = v100.z;
                valueInteger = aa_TargetDebug.valueInteger;
                v51 = v100.y;
                v54 = v100.x;
                v64 = v97;
                v63 = v96;
                v62 = v95;
              }
              idVec3::NormalizeFast(this: &v102);
              v69 = v102.x;
              v70 = v102.y;
              v71 = v102.z;
              v112.x = (float)(v102.x + (float)v54) - (float)v54;
              v112.y = (float)(v102.y + (float)v51) - (float)v51;
              v112.z = (float)(v102.z + (float)v53) - (float)v53;
              idVec3::NormalizeFast(this: &v112);
              v101.x = (float)((float)((float)(v110.mat[1].x * v124) + (float)v54) + (float)(v110.mat[2].x * (float)v34))
                     - (float)v54;
              v101.y = (float)((float)((float)(v110.mat[1].y * v124) + (float)v51) + (float)(v110.mat[2].y * (float)v34))
                     - (float)v51;
              v101.z = (float)((float)((float)(v110.mat[1].z * v124) + (float)v53) + (float)(v110.mat[2].z * (float)v34))
                     - (float)v53;
              idVec3::NormalizeFast(this: &v101);
              if ( valueInteger != 0 )
              {
                HIDWORD(v74) = LODWORD(v66);
                v120[0] = (float)((float)v69 * v117) + (float)v62;
                v120[1] = (float)((float)v70 * v117) + (float)v63;
                v120[2] = (float)((float)((float)v71 * v117) + (float)v64) + v114;
                v75 = va::va(
                        this: &v125,
                        fmt: "%f",
                        a3: v74,
                        a4: v73,
                        a5: v72,
                        a6: v89,
                        a7: v90,
                        a8: v91,
                        a9: v92,
                        a10: v93,
                        a11: v94,
                        v66);
                ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: v75,
                  a3: v120,
                  a4: clientGame->renderWorld->__vftable,
                  a5: &idColor::colorLtGrey,
                  a6: 1,
                  a7: 0,
                  a8: v115);
                v64 = v97;
                v63 = v96;
                v62 = v95;
              }
              if ( v66 < v109 )
              {
                v76 = v112.x;
                v77 = v112.y;
                v78 = (idPresentablePtr<idPresentable> *)v116;
                v79 = v112.z;
                v106 = v44;
                v109 = v66;
                aim->x = v112.x;
                aim->y = v77;
                aim->z = v79;
                aimPoint->x = v62;
                aimPoint->y = v63;
                aimPoint->z = v64;
                v80 = idPresentablePtr<idPresentableProjectile>::operator->(this: v78);
                v81 = ((int (__fastcall *)(idPresentable *))v80->__vftable[1].GetInputSettings)(a1: v80);
                if ( v81 != 0
                  && (v82 = *(idAmmoItem **)(v81 + 44)) != nullptr
                  && (ProjectileDef = idAmmoItem::GetProjectileDef(this: v82)) != nullptr )
                {
                  aimAssistZoomSnapScale = ProjectileDef->aimAssistZoomSnapScale;
                }
                else
                {
                  aimAssistZoomSnapScale = v107;
                }
                if ( v66 < (float)((float)aimAssistZoomSnapScale * (float)v57) )
                  *canZoomSnap = true;
                v102.x = v95 - v103;
                v102.y = v96 - v104;
                v102.z = v97 - v105;
                v85 = (float)((float)(v102.y * v102.y) + (float)((float)(v102.x * v102.x) + (float)(v102.z * v102.z)));
                v86 = (float)((float)((float)v57 * (float)0.5) * (float)((float)v57 * (float)0.5));
                if ( (float)((float)((float)v76 * v101.x)
                           + (float)((float)((float)v79 * v101.z) + (float)((float)v77 * v101.y))) >= 0.0 )
                {
                  if ( v85 >= v86 )
                  {
                    if ( v85 >= (float)((float)v57 * (float)v57) )
                    {
                      this->desiredFrictionScalar = aa_SensitivityScale.valueFloat;
                      valueFloat = aa_AssistStrength.valueFloat;
                    }
                    else
                    {
                      this->desiredFrictionScalar = aa_SensitivityScaleSweetSpot.valueFloat;
                      valueFloat = aa_AssistStrengthSweetSpot.valueFloat;
                    }
                    *aimAsisstStrength = valueFloat;
                  }
                  else
                  {
                    v87 = HIDWORD(v99);
                    this->desiredFrictionScalar = aa_SensitivityScaleBestSpot.valueFloat;
                    *aimAsisstStrength = *(float *)(v87 + 36);
                  }
                }
                else if ( v85 >= v86 )
                {
                  if ( v85 >= (float)((float)v57 * (float)v57) )
                    this->desiredFrictionScalar = aa_SensitivityScale.valueFloat;
                  else
                    this->desiredFrictionScalar = aa_SensitivityScaleSweetSpot.valueFloat;
                  *aimAsisstStrength = 0.0;
                }
                else
                {
                  this->desiredFrictionScalar = aa_SensitivityScaleBestSpot.valueFloat;
                  *aimAsisstStrength = 0.0;
                }
              }
            }
          }
        }
      }
      v41 = clientGame;
      LODWORD(v98) = LODWORD(v43) + 4;
      if ( ++v108 >= clientGame->aimAssistTargets.num )
        break;
      v42 = v107;
    }
    return v106;
  }
  return result;
}


// ========================================================================
// ?CalculateAssistAngles@idAimAssist@@AAA_NVidVec3@@M@Z
// EA  : 0x82DF4520
// RVA : 0x00DF4520
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

int __fastcall idAimAssist::CalculateAssistAngles(idAimAssist *this, idVec3 *aim, double aimAssistPower)
{
  unsigned int spawnId; // r11
  int v7; // r30
  idPresentablePlayer *PresentableByIndex; // r3
  int v9; // r10
  int v10; // r9
  int v11; // r8
  int v12; // r7
  double v13; // fp13
  double v14; // fp0
  double pitch; // fp12
  __int64 v17; // [sp+8h] [-C8h]
  __int64 v18; // [sp+10h] [-C0h]
  __int64 v19; // [sp+18h] [-B8h]
  __int64 v20; // [sp+20h] [-B0h]
  __int64 v21; // [sp+28h] [-A8h]
  idAimAssist v22; // [sp+50h] [-80h] BYREF

  spawnId = this->player.spawnId;
  v7 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = (idPresentablePlayer *)idClientGame::GetPresentableByIndex(this: clientGame, index: v7))->spawnId != this->player.spawnId )
  {
    PresentableByIndex = nullptr;
  }
  idPresentablePlayer::GetViewTransform(
    this: PresentableByIndex,
    origin: (idVec3 *)&v22.angleCorrection.roll,
    axis: (idMat3 *)&v22.lastZoomSnap);
  idAimAssist::GetAnglesToPosition(
    this: &v22,
    result: (idAngles *)this,
    aimTowards: __SPAIR64__((unsigned int)aim, __ROL4__(aim, 32)),
    a4: v12,
    a5: v11,
    a6: v10,
    a7: v9,
    a8: v17,
    a9: v18,
    a10: v19,
    a11: v20,
    a12: v21);
  v13 = *(float *)&v22.player.spawnId;
  if ( *(float *)&v22.player.spawnId >= -aimAssistPower )
  {
    if ( v13 > aimAssistPower )
      v13 = aimAssistPower;
  }
  else
  {
    v13 = -aimAssistPower;
  }
  v14 = *(float *)&v22.__vftable;
  if ( *(float *)&v22.__vftable >= -aimAssistPower )
  {
    if ( v14 > aimAssistPower )
      v14 = aimAssistPower;
  }
  else
  {
    v14 = -aimAssistPower;
  }
  pitch = v22.angleCorrection.pitch;
  this->angleCorrection.pitch = v14;
  this->angleCorrection.yaw = v13;
  this->angleCorrection.roll = pitch;
  return 1;
}


// ========================================================================
// ?SnapToAimPoint@idAimAssist@@AAAXVidVec3@@M@Z
// EA  : 0x82DF4618
// RVA : 0x00DF4618
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __fastcall idAimAssist::SnapToAimPoint(idAimAssist *this, idVec3 *aimPoint, double aimPower)
{
  unsigned int spawnId; // r11
  int v6; // r31
  idPresentableAnimatedEntity *PresentableByIndex; // r3
  int v8; // r10
  int v9; // r9
  int v10; // r8
  int v11; // r7
  double v12; // fp12
  double valueFloat; // fp13
  double v14; // fp11
  double v15; // fp0
  double v16; // fp13
  __int64 v17; // [sp+8h] [-88h]
  __int64 v18; // [sp+10h] [-80h]
  __int64 v19; // [sp+18h] [-78h]
  __int64 v20; // [sp+20h] [-70h]
  __int64 v21; // [sp+28h] [-68h]
  float v22; // [sp+50h] [-40h] BYREF
  float v23; // [sp+54h] [-3Ch]
  float v24; // [sp+58h] [-38h]

  spawnId = this->thisFrameEntity.spawnId;
  v6 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = (idPresentableAnimatedEntity *)idClientGame::GetPresentableByIndex(
                                                              this: clientGame,
                                                              index: v6))->spawnId != this->thisFrameEntity.spawnId )
  {
    PresentableByIndex = nullptr;
  }
  if ( idPresentableAnimatedEntity::GetCanAimAssist(this: PresentableByIndex) )
  {
    idAimAssist::GetAnglesToPosition(
      this: (idAimAssist *)&v22,
      result: (idAngles *)this,
      aimTowards: __SPAIR64__((unsigned int)aimPoint, __ROL4__(aimPoint, 32)),
      a4: v11,
      a5: v10,
      a6: v9,
      a7: v8,
      a8: v17,
      a9: v18,
      a10: v19,
      a11: v20,
      a12: v21);
    v12 = v23;
    valueFloat = aa_zoomLockSpeed.valueFloat;
    v14 = -aa_zoomLockSpeed.valueFloat;
    if ( v23 >= v14 )
    {
      if ( v12 > valueFloat )
        v12 = aa_zoomLockSpeed.valueFloat;
    }
    else
    {
      v12 = -aa_zoomLockSpeed.valueFloat;
    }
    v15 = v22;
    if ( v22 >= v14 )
    {
      if ( v15 > valueFloat )
        v15 = aa_zoomLockSpeed.valueFloat;
    }
    else
    {
      v15 = -aa_zoomLockSpeed.valueFloat;
    }
    v16 = v24;
    this->angleCorrection.pitch = v15;
    this->angleCorrection.yaw = v12;
    this->angleCorrection.roll = v16;
  }
}


// ========================================================================
// ?FindAimAssistLocation@idAimAssist@@AAA_NAAVidVec3@@_N@Z
// EA  : 0x82DF4710
// RVA : 0x00DF4710
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

int __fastcall idAimAssist::FindAimAssistLocation(idAimAssist *this, idVec3 *aim, bool zoomTarget)
{
  unsigned int spawnId; // r11
  int v7; // r31
  idPresentable *PresentableByIndex; // r3
  unsigned int v9; // r10
  int v10; // r31
  float y; // r8
  float z; // r7
  idPresentable *v13; // r3
  unsigned int v14; // r10
  int v15; // r30
  float v16; // r8
  float v17; // r7
  idPresentableAnimatedEntity *v18; // r3
  int v20; // r23
  idClientGame *v21; // r11
  int v22; // r29
  double v23; // fp15
  double v24; // fp26
  double v25; // fp25
  double x; // fp24
  int v27; // r30
  idPresentableAnimatedEntity *v28; // r31
  double v29; // fp13
  double v30; // fp11
  double v31; // fp9
  double v32; // fp12
  double v33; // fp0
  double yaw; // fp30
  double roll; // fp28
  double pitch; // fp29
  double v37; // fp6
  double v38; // fp5
  double v39; // fp13
  double v40; // fp13
  double v41; // fp23
  double v42; // fp21
  double v43; // fp22
  double v44; // fp11
  double v45; // fp9
  double v46; // fp10
  double v47; // fp13
  double v48; // fp12
  idAngles v49; // [sp+50h] [-150h] BYREF
  idVec3 v50; // [sp+60h] [-140h] BYREF
  idVec3 v51; // [sp+70h] [-130h] BYREF
  idVec3 v52; // [sp+80h] [-120h] BYREF
  float v53; // [sp+90h] [-110h] BYREF
  float v54; // [sp+94h] [-10Ch]
  float v55; // [sp+98h] [-108h]
  float v56; // [sp+9Ch] [-104h]
  float v57; // [sp+A0h] [-100h]
  float v58; // [sp+A4h] [-FCh]

  spawnId = this->player.spawnId;
  v7 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v7))->spawnId != this->player.spawnId )
  {
    PresentableByIndex = nullptr;
  }
  v9 = this->player.spawnId;
  v10 = v9 & 0x3FFF;
  y = PresentableByIndex[38].fxManager.actionBuffer[6].axis.mat[2].y;
  z = PresentableByIndex[38].fxManager.actionBuffer[6].axis.mat[2].z;
  v51.x = PresentableByIndex[38].fxManager.actionBuffer[6].axis.mat[2].x;
  v51.y = y;
  v51.z = z;
  if ( v9 == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v9 & 0x3FFF)
    || (v13 = idClientGame::GetPresentableByIndex(this: clientGame, index: v10))->spawnId != this->player.spawnId )
  {
    v13 = nullptr;
  }
  v14 = this->thisFrameEntity.spawnId;
  v15 = v14 & 0x3FFF;
  v16 = *(float *)&v13[38].fxManager.actionBuffer[6].time;
  v17 = *(float *)&v13[38].fxManager.actionBuffer[6].extraCondition;
  LODWORD(v49.pitch) = v13[38].fxManager.actionBuffer[6].condition;
  v49.yaw = v16;
  v49.roll = v17;
  if ( v14 != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: v14 & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v15)->spawnId == this->thisFrameEntity.spawnId )
  {
    if ( zoomTarget )
    {
      v18 = (idPresentableAnimatedEntity *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->thisFrameEntity);
      return idAimAssist::TraceToAimAssistLocation(this, aim, ae: v18);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v20 = 0;
    idVec3::ToAngles(this: &v52, result: &v49);
    v21 = clientGame;
    v22 = 0;
    v23 = 1.0e30;
    if ( clientGame->aimAssistTargets.num > 0 )
    {
      v24 = v51.z;
      v25 = v51.y;
      x = v51.x;
      v27 = 0;
      do
      {
        v28 = v21->aimAssistTargets.list[v27];
        if ( idAimAssist::IsValidTarget(this, target: v28) )
        {
          v29 = (float)((float)v25 - v28->origin.y);
          v30 = (float)((float)v24 - v28->origin.z);
          v31 = (float)((float)x - v28->origin.x);
          if ( (float)((float)((float)v31 * (float)v31)
                     + (float)((float)((float)v30 * (float)v30) + (float)((float)v29 * (float)v29))) <= (double)(float)(this->weaponTraceDistance * this->weaponTraceDistance) )
          {
            v28->GetAbsBounds(this: (struct idPresentableAnimatedEntity *)&v53, result: (idBounds *)v28, a3: -1);
            v32 = (float)(v55 + aa_shrink.valueFloat);
            v33 = (float)((float)(v58 - aa_shrink.valueFloat) - (float)(v55 + aa_shrink.valueFloat));
            yaw = v49.yaw;
            roll = v49.roll;
            pitch = v49.pitch;
            v37 = (float)((float)(v54 + v57) * (float)0.5);
            v38 = (float)((float)(v53 + v56) * (float)0.5);
            v39 = (float)((float)(v49.pitch * (float)0.0)
                        + (float)((float)(v49.roll
                                        * (float)((float)(v58 - aa_shrink.valueFloat)
                                                - (float)(v55 + aa_shrink.valueFloat)))
                                + (float)(v49.yaw * (float)0.0)));
            if ( __fabs((float)((float)((float)((float)((float)0.0 * (float)0.0)
                                              + (float)((float)((float)((float)(v58 - aa_shrink.valueFloat)
                                                                      - (float)(v55 + aa_shrink.valueFloat))
                                                              * (float)((float)(v58 - aa_shrink.valueFloat)
                                                                      - (float)(v55 + aa_shrink.valueFloat)))
                                                      + (float)((float)0.0 * (float)0.0)))
                                      * (float)((float)(v49.roll * v49.roll)
                                              + (float)((float)(v49.pitch * v49.pitch) + (float)(v49.yaw * v49.yaw))))
                              - (float)((float)v39 * (float)v39))) >= 0.0000001 )
            {
              v41 = (float)(v49.pitch
                          * (float)((float)((float)((float)((float)((float)((float)x
                                                                          - (float)((float)(v53 + v56) * (float)0.5))
                                                                  * (float)0.0)
                                                          + (float)((float)((float)((float)v24
                                                                                  - (float)(v55 + aa_shrink.valueFloat))
                                                                          * (float)((float)(v58 - aa_shrink.valueFloat)
                                                                                  - (float)(v55 + aa_shrink.valueFloat)))
                                                                  + (float)((float)((float)v25
                                                                                  - (float)((float)(v54 + v57)
                                                                                          * (float)0.5))
                                                                          * (float)0.0)))
                                                  * (float)((float)(v49.pitch * (float)0.0)
                                                          + (float)((float)(v49.roll
                                                                          * (float)((float)(v58 - aa_shrink.valueFloat)
                                                                                  - (float)(v55 + aa_shrink.valueFloat)))
                                                                  + (float)(v49.yaw * (float)0.0))))
                                          - (float)((float)((float)(v49.yaw
                                                                  * (float)((float)v25
                                                                          - (float)((float)(v54 + v57) * (float)0.5)))
                                                          + (float)((float)(v49.pitch
                                                                          * (float)((float)x
                                                                                  - (float)((float)(v53 + v56)
                                                                                          * (float)0.5)))
                                                                  + (float)(v49.roll
                                                                          * (float)((float)v24
                                                                                  - (float)(v55 + aa_shrink.valueFloat)))))
                                                  * (float)((float)((float)0.0 * (float)0.0)
                                                          + (float)((float)((float)v33 * (float)v33)
                                                                  + (float)((float)0.0 * (float)0.0)))))
                                  * (float)((float)1.0
                                          / (float)((float)((float)((float)((float)0.0 * (float)0.0)
                                                                  + (float)((float)((float)v33 * (float)v33)
                                                                          + (float)((float)0.0 * (float)0.0)))
                                                          * (float)((float)(v49.roll * v49.roll)
                                                                  + (float)((float)(v49.pitch * v49.pitch)
                                                                          + (float)(v49.yaw * v49.yaw))))
                                                  - (float)((float)v39 * (float)v39)))));
              v42 = (float)(v49.roll
                          * (float)((float)((float)((float)((float)((float)((float)x
                                                                          - (float)((float)(v53 + v56) * (float)0.5))
                                                                  * (float)0.0)
                                                          + (float)((float)((float)((float)v24
                                                                                  - (float)(v55 + aa_shrink.valueFloat))
                                                                          * (float)((float)(v58 - aa_shrink.valueFloat)
                                                                                  - (float)(v55 + aa_shrink.valueFloat)))
                                                                  + (float)((float)((float)v25
                                                                                  - (float)((float)(v54 + v57)
                                                                                          * (float)0.5))
                                                                          * (float)0.0)))
                                                  * (float)((float)(v49.pitch * (float)0.0)
                                                          + (float)((float)(v49.roll
                                                                          * (float)((float)(v58 - aa_shrink.valueFloat)
                                                                                  - (float)(v55 + aa_shrink.valueFloat)))
                                                                  + (float)(v49.yaw * (float)0.0))))
                                          - (float)((float)((float)(v49.yaw
                                                                  * (float)((float)v25
                                                                          - (float)((float)(v54 + v57) * (float)0.5)))
                                                          + (float)((float)(v49.pitch
                                                                          * (float)((float)x
                                                                                  - (float)((float)(v53 + v56)
                                                                                          * (float)0.5)))
                                                                  + (float)(v49.roll
                                                                          * (float)((float)v24
                                                                                  - (float)(v55 + aa_shrink.valueFloat)))))
                                                  * (float)((float)((float)0.0 * (float)0.0)
                                                          + (float)((float)((float)v33 * (float)v33)
                                                                  + (float)((float)0.0 * (float)0.0)))))
                                  * (float)((float)1.0
                                          / (float)((float)((float)((float)((float)0.0 * (float)0.0)
                                                                  + (float)((float)((float)v33 * (float)v33)
                                                                          + (float)((float)0.0 * (float)0.0)))
                                                          * (float)((float)(v49.roll * v49.roll)
                                                                  + (float)((float)(v49.pitch * v49.pitch)
                                                                          + (float)(v49.yaw * v49.yaw))))
                                                  - (float)((float)v39 * (float)v39)))));
              v43 = (float)(v49.yaw
                          * (float)((float)((float)((float)((float)((float)((float)x
                                                                          - (float)((float)(v53 + v56) * (float)0.5))
                                                                  * (float)0.0)
                                                          + (float)((float)((float)((float)v24
                                                                                  - (float)(v55 + aa_shrink.valueFloat))
                                                                          * (float)((float)(v58 - aa_shrink.valueFloat)
                                                                                  - (float)(v55 + aa_shrink.valueFloat)))
                                                                  + (float)((float)((float)v25
                                                                                  - (float)((float)(v54 + v57)
                                                                                          * (float)0.5))
                                                                          * (float)0.0)))
                                                  * (float)((float)(v49.pitch * (float)0.0)
                                                          + (float)((float)(v49.roll
                                                                          * (float)((float)(v58 - aa_shrink.valueFloat)
                                                                                  - (float)(v55 + aa_shrink.valueFloat)))
                                                                  + (float)(v49.yaw * (float)0.0))))
                                          - (float)((float)((float)(v49.yaw
                                                                  * (float)((float)v25
                                                                          - (float)((float)(v54 + v57) * (float)0.5)))
                                                          + (float)((float)(v49.pitch
                                                                          * (float)((float)x
                                                                                  - (float)((float)(v53 + v56)
                                                                                          * (float)0.5)))
                                                                  + (float)(v49.roll
                                                                          * (float)((float)v24
                                                                                  - (float)(v55 + aa_shrink.valueFloat)))))
                                                  * (float)((float)((float)0.0 * (float)0.0)
                                                          + (float)((float)((float)v33 * (float)v33)
                                                                  + (float)((float)0.0 * (float)0.0)))))
                                  * (float)((float)1.0
                                          / (float)((float)((float)((float)((float)0.0 * (float)0.0)
                                                                  + (float)((float)((float)v33 * (float)v33)
                                                                          + (float)((float)0.0 * (float)0.0)))
                                                          * (float)((float)(v49.roll * v49.roll)
                                                                  + (float)((float)(v49.pitch * v49.pitch)
                                                                          + (float)(v49.yaw * v49.yaw))))
                                                  - (float)((float)v39 * (float)v39)))));
              v44 = (float)((float)(v49.pitch
                                  * (float)((float)((float)((float)((float)((float)((float)x
                                                                                  - (float)((float)(v53 + v56)
                                                                                          * (float)0.5))
                                                                          * (float)0.0)
                                                                  + (float)((float)((float)((float)v24
                                                                                          - (float)(v55
                                                                                                  + aa_shrink.valueFloat))
                                                                                  * (float)((float)(v58
                                                                                                  - aa_shrink.valueFloat)
                                                                                          - (float)(v55
                                                                                                  + aa_shrink.valueFloat)))
                                                                          + (float)((float)((float)v25
                                                                                          - (float)((float)(v54 + v57)
                                                                                                  * (float)0.5))
                                                                                  * (float)0.0)))
                                                          * (float)((float)(v49.pitch * (float)0.0)
                                                                  + (float)((float)(v49.roll
                                                                                  * (float)((float)(v58
                                                                                                  - aa_shrink.valueFloat)
                                                                                          - (float)(v55
                                                                                                  + aa_shrink.valueFloat)))
                                                                          + (float)(v49.yaw * (float)0.0))))
                                                  - (float)((float)((float)(v49.yaw
                                                                          * (float)((float)v25
                                                                                  - (float)((float)(v54 + v57)
                                                                                          * (float)0.5)))
                                                                  + (float)((float)(v49.pitch
                                                                                  * (float)((float)x
                                                                                          - (float)((float)(v53 + v56)
                                                                                                  * (float)0.5)))
                                                                          + (float)(v49.roll
                                                                                  * (float)((float)v24
                                                                                          - (float)(v55
                                                                                                  + aa_shrink.valueFloat)))))
                                                          * (float)((float)((float)0.0 * (float)0.0)
                                                                  + (float)((float)((float)v33 * (float)v33)
                                                                          + (float)((float)0.0 * (float)0.0)))))
                                          * (float)((float)1.0
                                                  / (float)((float)((float)((float)((float)0.0 * (float)0.0)
                                                                          + (float)((float)((float)v33 * (float)v33)
                                                                                  + (float)((float)0.0 * (float)0.0)))
                                                                  * (float)((float)(v49.roll * v49.roll)
                                                                          + (float)((float)(v49.pitch * v49.pitch)
                                                                                  + (float)(v49.yaw * v49.yaw))))
                                                          - (float)((float)v39 * (float)v39)))))
                          + (float)x);
              v45 = (float)((float)(v49.roll
                                  * (float)((float)((float)((float)((float)((float)((float)x
                                                                                  - (float)((float)(v53 + v56)
                                                                                          * (float)0.5))
                                                                          * (float)0.0)
                                                                  + (float)((float)((float)((float)v24
                                                                                          - (float)(v55
                                                                                                  + aa_shrink.valueFloat))
                                                                                  * (float)((float)(v58
                                                                                                  - aa_shrink.valueFloat)
                                                                                          - (float)(v55
                                                                                                  + aa_shrink.valueFloat)))
                                                                          + (float)((float)((float)v25
                                                                                          - (float)((float)(v54 + v57)
                                                                                                  * (float)0.5))
                                                                                  * (float)0.0)))
                                                          * (float)((float)(v49.pitch * (float)0.0)
                                                                  + (float)((float)(v49.roll
                                                                                  * (float)((float)(v58
                                                                                                  - aa_shrink.valueFloat)
                                                                                          - (float)(v55
                                                                                                  + aa_shrink.valueFloat)))
                                                                          + (float)(v49.yaw * (float)0.0))))
                                                  - (float)((float)((float)(v49.yaw
                                                                          * (float)((float)v25
                                                                                  - (float)((float)(v54 + v57)
                                                                                          * (float)0.5)))
                                                                  + (float)((float)(v49.pitch
                                                                                  * (float)((float)x
                                                                                          - (float)((float)(v53 + v56)
                                                                                                  * (float)0.5)))
                                                                          + (float)(v49.roll
                                                                                  * (float)((float)v24
                                                                                          - (float)(v55
                                                                                                  + aa_shrink.valueFloat)))))
                                                          * (float)((float)((float)0.0 * (float)0.0)
                                                                  + (float)((float)((float)v33 * (float)v33)
                                                                          + (float)((float)0.0 * (float)0.0)))))
                                          * (float)((float)1.0
                                                  / (float)((float)((float)((float)((float)0.0 * (float)0.0)
                                                                          + (float)((float)((float)v33 * (float)v33)
                                                                                  + (float)((float)0.0 * (float)0.0)))
                                                                  * (float)((float)(v49.roll * v49.roll)
                                                                          + (float)((float)(v49.pitch * v49.pitch)
                                                                                  + (float)(v49.yaw * v49.yaw))))
                                                          - (float)((float)v39 * (float)v39)))))
                          + (float)v24);
              v46 = (float)((float)(v49.yaw
                                  * (float)((float)((float)((float)((float)((float)((float)x
                                                                                  - (float)((float)(v53 + v56)
                                                                                          * (float)0.5))
                                                                          * (float)0.0)
                                                                  + (float)((float)((float)((float)v24
                                                                                          - (float)(v55
                                                                                                  + aa_shrink.valueFloat))
                                                                                  * (float)((float)(v58
                                                                                                  - aa_shrink.valueFloat)
                                                                                          - (float)(v55
                                                                                                  + aa_shrink.valueFloat)))
                                                                          + (float)((float)((float)v25
                                                                                          - (float)((float)(v54 + v57)
                                                                                                  * (float)0.5))
                                                                                  * (float)0.0)))
                                                          * (float)((float)(v49.pitch * (float)0.0)
                                                                  + (float)((float)(v49.roll
                                                                                  * (float)((float)(v58
                                                                                                  - aa_shrink.valueFloat)
                                                                                          - (float)(v55
                                                                                                  + aa_shrink.valueFloat)))
                                                                          + (float)(v49.yaw * (float)0.0))))
                                                  - (float)((float)((float)(v49.yaw
                                                                          * (float)((float)v25
                                                                                  - (float)((float)(v54 + v57)
                                                                                          * (float)0.5)))
                                                                  + (float)((float)(v49.pitch
                                                                                  * (float)((float)x
                                                                                          - (float)((float)(v53 + v56)
                                                                                                  * (float)0.5)))
                                                                          + (float)(v49.roll
                                                                                  * (float)((float)v24
                                                                                          - (float)(v55
                                                                                                  + aa_shrink.valueFloat)))))
                                                          * (float)((float)((float)0.0 * (float)0.0)
                                                                  + (float)((float)((float)v33 * (float)v33)
                                                                          + (float)((float)0.0 * (float)0.0)))))
                                          * (float)((float)1.0
                                                  / (float)((float)((float)((float)((float)0.0 * (float)0.0)
                                                                          + (float)((float)((float)v33 * (float)v33)
                                                                                  + (float)((float)0.0 * (float)0.0)))
                                                                  * (float)((float)(v49.roll * v49.roll)
                                                                          + (float)((float)(v49.pitch * v49.pitch)
                                                                                  + (float)(v49.yaw * v49.yaw))))
                                                          - (float)((float)v39 * (float)v39)))))
                          + (float)v25);
              v40 = (float)((float)((float)((float)((float)((float)((float)x - (float)((float)(v53 + v56) * (float)0.5))
                                                          * (float)0.0)
                                                  + (float)((float)((float)((float)v24
                                                                          - (float)(v55 + aa_shrink.valueFloat))
                                                                  * (float)((float)(v58 - aa_shrink.valueFloat)
                                                                          - (float)(v55 + aa_shrink.valueFloat)))
                                                          + (float)((float)((float)v25
                                                                          - (float)((float)(v54 + v57) * (float)0.5))
                                                                  * (float)0.0)))
                                          * (float)((float)(v49.roll * v49.roll)
                                                  + (float)((float)(v49.pitch * v49.pitch) + (float)(v49.yaw * v49.yaw))))
                                  - (float)((float)((float)(v49.yaw
                                                          * (float)((float)v25 - (float)((float)(v54 + v57) * (float)0.5)))
                                                  + (float)((float)(v49.pitch
                                                                  * (float)((float)x
                                                                          - (float)((float)(v53 + v56) * (float)0.5)))
                                                          + (float)(v49.roll
                                                                  * (float)((float)v24
                                                                          - (float)(v55 + aa_shrink.valueFloat)))))
                                          * (float)((float)(v49.pitch * (float)0.0)
                                                  + (float)((float)(v49.roll
                                                                  * (float)((float)(v58 - aa_shrink.valueFloat)
                                                                          - (float)(v55 + aa_shrink.valueFloat)))
                                                          + (float)(v49.yaw * (float)0.0)))))
                          * (float)((float)1.0
                                  / (float)((float)((float)((float)((float)0.0 * (float)0.0)
                                                          + (float)((float)((float)v33 * (float)v33)
                                                                  + (float)((float)0.0 * (float)0.0)))
                                                  * (float)((float)(v49.roll * v49.roll)
                                                          + (float)((float)(v49.pitch * v49.pitch)
                                                                  + (float)(v49.yaw * v49.yaw))))
                                          - (float)((float)v39 * (float)v39))));
              if ( v40 >= 0.0 )
              {
                if ( v40 <= 1.0 )
                {
                  v38 = (float)((float)((float)0.0 * (float)v40) + (float)((float)(v53 + v56) * (float)0.5));
                  v37 = (float)((float)((float)0.0 * (float)v40) + (float)((float)(v54 + v57) * (float)0.5));
                  v32 = (float)((float)((float)((float)(v58 - aa_shrink.valueFloat) - (float)(v55 + aa_shrink.valueFloat))
                                      * (float)v40)
                              + (float)(v55 + aa_shrink.valueFloat));
                }
                else
                {
                  v32 = (float)(v58 - aa_shrink.valueFloat);
                }
              }
              if ( (float)((float)((float)((float)v37 - (float)v46) * (float)((float)v37 - (float)v46))
                         + (float)((float)((float)((float)v38 - (float)v44) * (float)((float)v38 - (float)v44))
                                 + (float)((float)((float)v32 - (float)v45) * (float)((float)v32 - (float)v45)))) <= (double)(float)(aa_lockLineRange.valueFloat * aa_lockLineRange.valueFloat) )
              {
                v50.y = (float)((float)(v54 + v57) * (float)0.5) - (float)v25;
                v50.z = (float)((float)(v58 + v55) * (float)0.5) - (float)v24;
                v50.x = (float)((float)(v53 + v56) * (float)0.5) - (float)x;
                idVec3::NormalizeFast(this: &v50);
                if ( (float)((float)((float)yaw * v50.y)
                           + (float)((float)(v50.x * (float)pitch) + (float)((float)roll * v50.z))) >= 0.0
                  && (float)((float)((float)v41 * (float)v41)
                           + (float)((float)((float)v42 * (float)v42) + (float)((float)v43 * (float)v43))) < v23 )
                {
                  v51.x = 0.0;
                  v51.y = 0.0;
                  v51.z = 0.0;
                  if ( (unsigned __int8)idAimAssist::TraceToAimAssistLocation(this, aim: &v51, ae: v28) != 0 )
                  {
                    v23 = (float)((float)((float)v41 * (float)v41)
                                + (float)((float)((float)v42 * (float)v42) + (float)((float)v43 * (float)v43)));
                    v47 = v51.y;
                    v20 = 1;
                    v48 = v51.z;
                    aim->x = v51.x;
                    aim->y = v47;
                    aim->z = v48;
                  }
                }
              }
            }
          }
        }
        v21 = clientGame;
        ++v22;
        ++v27;
      }
      while ( v22 < clientGame->aimAssistTargets.num );
    }
    return v20;
  }
}


// ========================================================================
// ?ZoomSnapCorrection@idAimAssist@@AAA_NXZ
// EA  : 0x82DF4B98
// RVA : 0x00DF4B98
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

int __fastcall idAimAssist::ZoomSnapCorrection(idAimAssist *this)
{
  int AimAssistLocation; // r10
  int v3; // r9
  int v4; // r8
  int v5; // r7
  double v6; // fp12
  double valueFloat; // fp13
  double v8; // fp11
  double v9; // fp0
  double v10; // fp13
  __int64 v12; // [sp+8h] [-78h]
  __int64 v13; // [sp+10h] [-70h]
  __int64 v14; // [sp+18h] [-68h]
  __int64 v15; // [sp+20h] [-60h]
  __int64 v16; // [sp+28h] [-58h]
  float v17; // [sp+50h] [-30h] BYREF
  float v18; // [sp+54h] [-2Ch]
  float v19; // [sp+58h] [-28h]
  idVec3 v20; // [sp+60h] [-20h] BYREF

  this->zoomSnapThisFrame = false;
  AimAssistLocation = (unsigned __int8)idAimAssist::FindAimAssistLocation(this, aim: &v20, zoomTarget: true);
  if ( AimAssistLocation == 0 )
    return 0;
  idAimAssist::GetAnglesToPosition(
    this: (idAimAssist *)&v17,
    result: (idAngles *)LODWORD(v20.x),
    aimTowards: __SPAIR64__(LODWORD(v20.y), __ROL4__(LODWORD(v20.z), 32)),
    a4: v5,
    a5: v4,
    a6: v3,
    a7: AimAssistLocation,
    a8: v12,
    a9: v13,
    a10: v14,
    a11: v15,
    a12: v16);
  v6 = v18;
  valueFloat = aa_zoomLockSpeed.valueFloat;
  v8 = -aa_zoomLockSpeed.valueFloat;
  if ( v18 >= v8 )
  {
    if ( v6 > valueFloat )
      v6 = aa_zoomLockSpeed.valueFloat;
  }
  else
  {
    v6 = -aa_zoomLockSpeed.valueFloat;
  }
  v9 = v17;
  if ( v17 >= v8 )
  {
    if ( v9 > valueFloat )
      v9 = aa_zoomLockSpeed.valueFloat;
  }
  else
  {
    v9 = -aa_zoomLockSpeed.valueFloat;
  }
  v10 = v19;
  this->angleCorrection.pitch = v9;
  this->angleCorrection.yaw = v6;
  this->angleCorrection.roll = v10;
  return 1;
}


// ========================================================================
// ?ShootingCorrection@idAimAssist@@AAA_NXZ
// EA  : 0x82DF4C78
// RVA : 0x00DF4C78
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

int __fastcall idAimAssist::ShootingCorrection(idAimAssist *this)
{
  idPresentable *v2; // r3
  int v3; // r10
  int v4; // r9
  int v5; // r8
  int v6; // r7
  double v7; // fp12
  double valueFloat; // fp13
  double v9; // fp11
  double v10; // fp0
  double v11; // fp13
  __int64 v13; // [sp+8h] [-78h]
  __int64 v14; // [sp+10h] [-70h]
  __int64 v15; // [sp+18h] [-68h]
  __int64 v16; // [sp+20h] [-60h]
  __int64 v17; // [sp+28h] [-58h]
  float v18; // [sp+50h] [-30h] BYREF
  float v19; // [sp+54h] [-2Ch]
  float v20; // [sp+58h] [-28h]
  idVec3 v21; // [sp+60h] [-20h] BYREF

  if ( g_AimAssist_Disable_Shooting.valueInteger != 0 )
    return 0;
  v2 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player);
  if ( !idUCmdTracker::IsPressedForPlayer(this: (idUCmdTracker *)&v2[38].fxManager.actionState.size, mask: 1)
    || (unsigned __int8)idAimAssist::FindAimAssistLocation(this, aim: &v21, zoomTarget: false) == 0 )
  {
    return 0;
  }
  idAimAssist::GetAnglesToPosition(
    this: (idAimAssist *)&v18,
    result: (idAngles *)LODWORD(v21.x),
    aimTowards: __SPAIR64__(LODWORD(v21.y), __ROL4__(LODWORD(v21.z), 32)),
    a4: v6,
    a5: v5,
    a6: v4,
    a7: v3,
    a8: v13,
    a9: v14,
    a10: v15,
    a11: v16,
    a12: v17);
  v7 = v19;
  valueFloat = aa_shootingLockSpeed.valueFloat;
  v9 = -aa_shootingLockSpeed.valueFloat;
  if ( v19 >= v9 )
  {
    if ( v7 > valueFloat )
      v7 = aa_shootingLockSpeed.valueFloat;
  }
  else
  {
    v7 = -aa_shootingLockSpeed.valueFloat;
  }
  v10 = v18;
  if ( v18 >= v9 )
  {
    if ( v10 > valueFloat )
      v10 = aa_shootingLockSpeed.valueFloat;
  }
  else
  {
    v10 = -aa_shootingLockSpeed.valueFloat;
  }
  v11 = v20;
  this->angleCorrection.pitch = v10;
  this->angleCorrection.yaw = v7;
  this->angleCorrection.roll = v11;
  return 1;
}


// ========================================================================
// ?Update@idAimAssist@@QAAXXZ
// EA  : 0x82DF4D90
// RVA : 0x00DF4D90
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAimAssist::Update(idAimAssist *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  unsigned int spawnId; // r8
  unsigned __int64 v5; // r23
  idPresentablePtr<idPresentableAnimatedEntity> *p_thisFrameEntity; // r21
  idPresentablePlayer *v7; // r3
  idPresentable *v8; // r3
  int v9; // r3
  idAmmoItem *v10; // r3
  __int64 v11; // r10
  const idDeclProjectile *v12; // r3
  double v13; // fp0
  idWorldspawn *v14; // r10
  idPresentable *v15; // r3
  int v16; // r3
  char v17; // r11
  unsigned __int16 *v18; // r3
  __int64 v19; // r10 OVERLAPPED
  __int16 v20; // r8
  __int16 v21; // r7
  __int64 v22; // r5 OVERLAPPED
  int v23; // r11
  int v24; // r6
  double v25; // fp11
  double v26; // fp4
  double v29; // fp12
  double v30; // fp13
  double v31; // fp13
  int ShouldZoomSnap; // r20
  __int16 v33; // r6
  int v34; // r8
  double v35; // fp11
  int v36; // r9
  __int16 v37; // r7
  int v38; // r9
  char v39; // r25
  idPresentableAnimatedEntity *v40; // r3
  idClientGame *v41; // r29
  idClipQuery *p_deferredAimPoint; // r26
  idClip *p_clip; // r28
  idClipQuery *p_deferredHeadPoint; // r27
  unsigned __int64 index; // r11
  unsigned __int64 v46; // r7
  idClip *v47; // r10
  idPresentable *PresentableByEntityNum; // r3
  idPresentableAnimatedEntity *v49; // r3
  idPresentableAnimatedEntity *v50; // r29
  idPresentable *v51; // r3
  idPresentableAnimatedEntity *v52; // r3
  idPresentableAnimatedEntity *v53; // r29
  idPresentable *v54; // r3
  idPresentableAnimatedEntity *v55; // r3
  idPresentable *v56; // r3
  char v57; // r11
  double y; // fp13
  double z; // fp12
  idPresentable *v60; // r28
  idPresentable *v61; // r28
  double v62; // fp1
  __int64 v63; // r4
  idPresentablePlayer *v64; // r3
  idPresentable *v65; // r3
  float *v66; // r3
  double v67; // fp8
  double v68; // fp6
  idPresentable *v69; // r3
  __int64 v70; // r6
  idPresentable *v71; // r30
  __int64 v72; // r10
  __int64 v73; // r8
  va *v74; // r3
  unsigned __int64 v75; // r6
  const char *v76; // r7
  idWorldspawn *world; // r6
  idPresentable *v78; // r3
  int v79; // r3
  char v80; // r11
  __int16 currentPitch; // r10
  idPresentable *v82; // r3
  idPresentable *v83; // r3
  int v84; // r3
  idAmmoItem *v85; // r3
  __int64 v86; // r10
  const idDeclProjectile *ProjectileDef; // r3
  double valueFloat; // fp0
  int v89; // [sp+8h] [-1358h]
  int v90; // [sp+8h] [-1358h]
  int v91; // [sp+Ch] [-1354h]
  bool v92; // [sp+Fh] [-1351h]
  const char *v93; // [sp+10h] [-1350h]
  const char *v94; // [sp+10h] [-1350h]
  int v95; // [sp+14h] [-134Ch]
  int v96; // [sp+14h] [-134Ch]
  int v97; // [sp+18h] [-1348h]
  int v98; // [sp+18h] [-1348h]
  int v99; // [sp+1Ch] [-1344h]
  int v100; // [sp+1Ch] [-1344h]
  int v101; // [sp+20h] [-1340h]
  int v102; // [sp+20h] [-1340h]
  double frictionScalar; // [sp+20h] [-1340h]
  int v104; // [sp+24h] [-133Ch]
  int v105; // [sp+24h] [-133Ch]
  int v106; // [sp+28h] [-1338h]
  int v107; // [sp+28h] [-1338h]
  int v108; // [sp+2Ch] [-1334h]
  int v109; // [sp+2Ch] [-1334h]
  int v110; // [sp+30h] [-1330h]
  int v111; // [sp+30h] [-1330h]
  int v112; // [sp+34h] [-132Ch]
  int v113; // [sp+34h] [-132Ch]
  int v114; // [sp+38h] [-1328h]
  int v115; // [sp+38h] [-1328h]
  int v116; // [sp+3Ch] [-1324h]
  int v117; // [sp+3Ch] [-1324h]
  int v118; // [sp+40h] [-1320h]
  int v119; // [sp+40h] [-1320h]
  int v120; // [sp+44h] [-131Ch]
  int v121; // [sp+44h] [-131Ch]
  int v122; // [sp+48h] [-1318h]
  int v123; // [sp+48h] [-1318h]
  int v124; // [sp+4Ch] [-1314h]
  int v125; // [sp+4Ch] [-1314h]
  int v126; // [sp+50h] [-1310h]
  int v127; // [sp+50h] [-1310h]
  int v128; // [sp+58h] [-1308h]
  int v129; // [sp+58h] [-1308h]
  int v130; // [sp+60h] [-1300h]
  int v131; // [sp+60h] [-1300h]
  idWorldspawn::mapType_t mapType; // [sp+70h] [-12F0h] BYREF
  bool v133; // [sp+74h] [-12ECh] BYREF
  idPLogScope v134; // [sp+78h] [-12E8h] BYREF
  __int64 v135; // [sp+80h] [-12E0h]
  __int64 v136; // [sp+88h] [-12D8h] BYREF
  idVec3 v137; // [sp+90h] [-12D0h] BYREF
  idVec3 v138; // [sp+A0h] [-12C0h] BYREF
  idVec3 v139; // [sp+B0h] [-12B0h] BYREF
  idVec3 v140; // [sp+C0h] [-12A0h] BYREF
  float v141[4]; // [sp+D0h] [-1290h] BYREF
  float v142[4]; // [sp+E0h] [-1280h] BYREF
  float v143[2]; // [sp+F0h] [-1270h] BYREF
  float v144; // [sp+F8h] [-1268h]
  float v145; // [sp+100h] [-1260h] BYREF
  float v146; // [sp+104h] [-125Ch]
  float v147; // [sp+108h] [-1258h]
  float v148[4]; // [sp+110h] [-1250h] BYREF
  float v149[4]; // [sp+120h] [-1240h] BYREF
  idMat3 v150; // [sp+130h] [-1230h] BYREF
  __int64 v151; // [sp+158h] [-1208h]
  idMat3 v152; // [sp+160h] [-1200h] BYREF
  idVec3 v153[2]; // [sp+188h] [-11D8h] BYREF
  trace_t v154; // [sp+1A0h] [-11C0h] BYREF
  int v155; // [sp+220h] [-1140h] BYREF
  trace_t v156; // [sp+240h] [-1120h] BYREF
  va v157; // [sp+2C0h] [-10A0h] BYREF

  if ( gameLocal->GetGameDifficulty(this: gameLocal) <= 0 || gameLocal->GetGameDifficulty(this: gameLocal) >= 3 )
  {
    if ( gameLocal->GetGameDifficulty(this: gameLocal) != 0 )
      return;
    RD_EventBegin(name: "idAimAssist::Update");
    LODWORD(v75) = "idAimAssist::Update";
    HIDWORD(v75) = 2;
    idPLogScope::idPLogScope(this: &v134, pl: &pLog, gMask: v75, label: v76);
    this->angleCorrection = ang_zero;
    this->frictionScalar = 1.0;
    world = gameLocal->world;
    if ( world == nullptr || (HIDWORD(v135) = world->mapType, HIDWORD(v135) != 3) && HIDWORD(v135) != 2 )
    {
      if ( idPresentablePtr<idPresentablePlayer>::operator idPresentablePlayer *(this: &this->player) == nullptr
        || idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player) == (idPresentable *)-37616
        || (v78 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player),
            v79 = ((int (__fastcall *)(idPresentable *))v78->__vftable[1].GetInputSettings)(a1: v78),
            v80 = 1,
            v79 == 0) )
      {
        v80 = 0;
      }
      if ( v80 != 0 )
      {
        currentPitch = this->currentPitch;
        this->savedYaw = this->currentYaw;
        this->savedPitch = currentPitch;
        v82 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player);
        this->currentYaw = HIWORD(v82[38].fxManager.actionBuffer[0].org.x);
        this->currentPitch = *((_WORD *)&v82[38].fxManager.hasExternalPositionAndRotation + 1);
        if ( g_dragEntity.valueInteger == 0 && g_AimAssist_Disable_All.valueInteger == 0 )
        {
          v83 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player);
          v84 = ((int (__fastcall *)(idPresentable *))v83->__vftable[1].GetInputSettings)(a1: v83);
          if ( v84 != 0
            && (v85 = *(idAmmoItem **)(v84 + 44)) != nullptr
            && (ProjectileDef = idAmmoItem::GetProjectileDef(this: v85)) != nullptr )
          {
            LODWORD(v86) = ProjectileDef->maxRange;
            v136 = v86;
            valueFloat = (float)v86;
          }
          else
          {
            valueFloat = aa_lockdist.valueFloat;
          }
          this->weaponTraceDistance = valueFloat;
          idAimAssist::UpdateTraceEntity(this);
          if ( (unsigned __int8)idAimAssist::ShouldZoomSnap(this) != 0 || this->zoomSnapThisFrame )
          {
            idAimAssist::ZoomSnapCorrection(this);
          }
          else if ( (unsigned __int8)idAimAssist::ShootingCorrection(this) == 0 )
          {
            idAimAssist::AdhesionCorrection(this);
          }
        }
      }
    }
    goto _M492633_2;
  }
  RD_EventBegin(name: "idAimAssist::Update");
  LODWORD(v2) = "idAimAssist::Update";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v134, pl: &pLog, gMask: v2, label: v3);
  spawnId = this->thisFrameEntity.spawnId;
  LODWORD(v5) = 0;
  HIDWORD(v5) = &this->player;
  p_thisFrameEntity = &this->thisFrameEntity;
  this->frictionScalar = 1.0;
  this->desiredFrictionScalar = 1.0;
  this->lastFrameEntity.spawnId = spawnId;
  this->thisFrameEntity.spawnId = 0;
  v7 = (idPresentablePlayer *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player);
  idPresentablePlayer::GetViewTransform(this: v7, origin: &v139, axis: &v150);
  v8 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player);
  v9 = ((int (__fastcall *)(idPresentable *))v8->__vftable[1].GetInputSettings)(a1: v8);
  if ( v9 != 0
    && (v10 = *(idAmmoItem **)(v9 + 44)) != nullptr
    && (v12 = idAmmoItem::GetProjectileDef(this: v10)) != nullptr )
  {
    LODWORD(v11) = v12->aimAssistRange;
    v135 = v11;
    v13 = (float)v11;
  }
  else
  {
    v13 = aa_lockdist.valueFloat;
  }
  this->weaponTraceDistance = v13;
  v14 = gameLocal->world;
  if ( v14 != nullptr )
  {
    mapType = v14->mapType;
    if ( mapType == MAPTYPE_TOWN || mapType == MAPTYPE_RACETRACK )
      goto _M492633_2;
  }
  if ( idPresentablePtr<idPresentablePlayer>::operator idPresentablePlayer *(this: &this->player) == nullptr
    || idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player) == (idPresentable *)-37616
    || (v15 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player),
        v16 = ((int (__fastcall *)(idPresentable *))v15->__vftable[1].GetInputSettings)(a1: v15),
        v17 = 1,
        v16 == 0) )
  {
    v17 = 0;
  }
  if ( v17 == 0 )
    goto _M492633_2;
  v18 = (unsigned __int16 *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player);
  HIDWORD(v19) = (unsigned __int16)this->currentAngle[0];
  v20 = this->currentAngle[1];
  v21 = this->currentAngle[2];
  this->savedAngle[0] = WORD1(v19);
  HIDWORD(v22) = v18[23019];
  this->currentAngle[0] = WORD1(v22);
  this->savedAngle[1] = v20;
  this->currentAngle[1] = v18[23020];
  this->savedAngle[2] = v21;
  this->currentAngle[2] = v18[23021];
  if ( aa_TargetDebug.valueInteger != 0 )
  {
    LODWORD(v19) = v18[23020];
    LOWORD(v22) = v18[23019];
    v23 = (__int16)v19;
    v135 = *(__int64 *)((char *)&v19 - 4);
    LODWORD(v19) = v20;
    v151 = v19;
    LODWORD(v22) = (__int16)v22;
    v24 = this->savedAngle[0];
    v136 = v22;
    *(_QWORD *)&v137.x = *(__int64 *)((char *)&v22 - 4);
    *(float *)&mapType = v150.mat[0].y * (float)36.0;
    v145 = (float)(v150.mat[0].x * (float)36.0) + v139.x;
    v25 = (float)((float)v135 - (float)v19);
    v26 = (float)((float)v22 - (float)*(__int64 *)((char *)&v22 - 4));
    _FP28 = (float)((float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f13, f28, f12, f13 }
    v29 = __frsqrte(_FP13);
    v30 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29
                                                                                        * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))
                                                                                                * (float)0.5))
                                                                                * (float)v29)
                                                                        - (float)1.5)
                                                        * (float)v29)
                                                * (float)((float)((float)((float)v26 * (float)v26)
                                                                + (float)((float)v25 * (float)v25))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v29
                                                                                * (float)((float)((float)((float)v26 * (float)v26)
                                                                                                + (float)((float)v25 * (float)v25))
                                                                                        * (float)0.5))
                                                                        * (float)v29)
                                                                - (float)1.5)
                                                * (float)v29))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v29
                                                        * (float)((float)((float)((float)v26 * (float)v26)
                                                                        + (float)((float)v25 * (float)v25))
                                                                * (float)0.5))
                                                * (float)v29)
                                        - (float)1.5)
                        * (float)v29));
    v31 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)) * (float)0.5)) * (float)v29) - (float)1.5)
                                                                                                * (float)v29)
                                                                                        * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)) * (float)0.5)) * (float)v29) - (float)1.5)
                                                                                        * (float)v29))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v29
                                                                                                * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)) * (float)0.5))
                                                                                        * (float)v29)
                                                                                - (float)1.5)
                                                                * (float)v29))
                                                * (float)((float)((float)((float)v26 * (float)v26)
                                                                + (float)((float)v25 * (float)v25))
                                                        * (float)0.5))
                                        * (float)v30)
                                - (float)1.5)
                * (float)v30);
    v147 = v139.z + (float)(v150.mat[0].z * (float)36.0);
    v146 = v139.y + *(float *)&mapType;
    v141[2] = (float)(v147 + (float)(v150.mat[1].z * (float)((float)v31 * (float)((float)v135 - (float)v19))))
            + (float)((float)((float)((float)((float)v22 - (float)*(__int64 *)((char *)&v22 - 4)) * (float)v31)
                            * (float)-1.0)
                    * v150.mat[2].z);
    v141[0] = (float)((float)(v139.x + (float)(v150.mat[0].x * (float)36.0))
                    + (float)(v150.mat[1].x * (float)((float)v31 * (float)((float)v135 - (float)v19))))
            + (float)((float)((float)((float)((float)v22 - (float)*(__int64 *)((char *)&v22 - 4)) * (float)v31)
                            * (float)-1.0)
                    * v150.mat[2].x);
    v141[1] = (float)(v146 + (float)(v150.mat[1].y * (float)((float)v31 * (float)((float)v135 - (float)v19))))
            + (float)((float)((float)((float)((float)v22 - (float)*(__int64 *)((char *)&v22 - 4)) * (float)v31)
                            * (float)-1.0)
                    * v150.mat[2].y);
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorYellow,
      a3: &v145,
      a4: v141,
      a5: 0.5);
  }
  ShouldZoomSnap = (unsigned __int8)idAimAssist::ShouldZoomSnap(this);
  if ( ShouldZoomSnap != 0 )
    goto _M492611_0;
  v33 = this->currentAngle[1];
  v34 = this->savedAngle[1];
  v35 = (float)(this->angleCorrection.yaw * (float)182.04445);
  LODWORD(v137.y) = (int)(float)(this->angleCorrection.pitch * (float)182.04445);
  LODWORD(v136) = (int)v35;
  v36 = v34 + (__int16)(int)v35;
  if ( v36 <= v33 - SLOWORD(aa_sensitivityThreshold.valueInteger)
    || v36 >= SLOWORD(aa_sensitivityThreshold.valueInteger) + v33
    || (v38 = SLOWORD(v137.y) + this->savedAngle[0],
        v37 = this->currentAngle[0],
        v38 <= v37 - SLOWORD(aa_sensitivityThreshold.valueInteger))
    || v38 >= v37 + SLOWORD(aa_sensitivityThreshold.valueInteger) )
  {
_M492611_0:
    this->angleCorrection = ang_zero;
    if ( g_dragEntity.valueInteger == 0 && g_AimAssist_Disable_All.valueInteger == 0 )
    {
      v39 = 1;
      v40 = idAimAssist::CalculateAimAssist(
              this,
              aim: &v137,
              aimPoint: &v140,
              aimAsisstStrength: (float *)&mapType,
              canZoomSnap: &v133);
      if ( v40 != nullptr )
        p_thisFrameEntity->spawnId = v40->spawnId;
      else
        p_thisFrameEntity->spawnId = 0;
      v41 = clientGame;
      p_deferredAimPoint = &this->deferredAimPoint;
      p_clip = &clientGame->clip;
      if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->deferredAimPoint) != 0 )
      {
        p_deferredHeadPoint = &this->deferredHeadPoint;
        if ( (unsigned __int8)idClip::QueryIsValid(this: &v41->clip, clipQuery: &this->deferredHeadPoint) != 0 )
        {
          index = p_deferredAimPoint->index;
          p_deferredAimPoint->index = v5;
          HIDWORD(v135) = &v41->clip;
          idCollisionModelManager::GetContentsResult(
            this: collisionModelManager,
            result: &v154,
            query: &p_clip->collisionQueries[index & 0xFFF].query,
            peek: false);
          v46 = p_deferredHeadPoint->index;
          v47 = &clientGame->clip;
          p_deferredHeadPoint->index = v5;
          idCollisionModelManager::GetContentsResult(
            this: collisionModelManager,
            result: &v156,
            query: &v47->collisionQueries[v46 & 0xFFF].query,
            peek: false);
          v39 = 0;
          v41 = clientGame;
        }
      }
      if ( v39 == 0 )
      {
        if ( v154.c.type != CONTACT_NONE )
        {
          PresentableByEntityNum = idClientGame::GetPresentableByEntityNum(this: v41, entityNum: v154.c.entityNum);
          if ( PresentableByEntityNum != nullptr )
          {
            v49 = PresentableByEntityNum->GetActorInterface_2(this: PresentableByEntityNum);
            v50 = v49;
            if ( v49 != nullptr
              && idPresentableAnimatedEntity::GetCanAimAssist(this: v49)
              && idAimAssist::IsValidTarget(this, target: v50) )
            {
              this->lastFrameEntity.spawnId = v50->spawnId;
            }
          }
        }
        else if ( v156.c.type != CONTACT_NONE )
        {
          v51 = idClientGame::GetPresentableByEntityNum(this: v41, entityNum: v156.c.entityNum);
          if ( v51 != nullptr )
          {
            v52 = v51->GetActorInterface_2(this: v51);
            v53 = v52;
            if ( v52 != nullptr
              && idPresentableAnimatedEntity::GetCanAimAssist(this: v52)
              && idAimAssist::IsValidTarget(this, target: v53) )
            {
              this->lastFrameEntity.spawnId = v53->spawnId;
            }
          }
        }
        else
        {
          this->lastFrameEntity.spawnId = 0;
        }
      }
      if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->thisFrameEntity) != nullptr )
      {
        v54 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player);
        p_deferredAimPoint->index = *(unsigned __int64 *)&idClip::Translation(
                                                            this: (idClip *)&v136,
                                                            result: &clientGame->clip,
                                                            a3: nullptr,
                                                            start: &v139,
                                                            end: &v140,
                                                            clipModel: nullptr,
                                                            startAxis: &mat3_identity,
                                                            clipMask: 8462469,
                                                            passEntityNumber: v89,
                                                            moveClipModel: v91,
                                                            userName: v93,
                                                            a12: v95,
                                                            a13: v97,
                                                            a14: v99,
                                                            a15: v101,
                                                            a16: v104,
                                                            a17: v106,
                                                            a18: v108,
                                                            a19: v110,
                                                            a20: v112,
                                                            a21: v114,
                                                            a22: v116,
                                                            a23: v118,
                                                            a24: v120,
                                                            a25: v122,
                                                            a26: v124,
                                                            a27: v126,
                                                            a28: v54->entityNumber,
                                                            a29: v128,
                                                            a30: false,
                                                            a31: v130,
                                                            a32: (int)"w:\\tech5\\tungsten\\game\\player\\AimAssist.cpp(201) : Translation")->world;
        v55 = (idPresentableAnimatedEntity *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->thisFrameEntity);
        idPresentableAnimatedEntity::GetEyePos(this: v55, eyePos: v153);
        v56 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player);
        this->deferredHeadPoint.index = *(_QWORD *)&idClip::Translation(
                                                      this: (idClip *)&v136,
                                                      result: &clientGame->clip,
                                                      a3: nullptr,
                                                      start: &v139,
                                                      end: v153,
                                                      clipModel: nullptr,
                                                      startAxis: &mat3_identity,
                                                      clipMask: 8462469,
                                                      passEntityNumber: v90,
                                                      moveClipModel: v92,
                                                      userName: v94,
                                                      a12: v96,
                                                      a13: v98,
                                                      a14: v100,
                                                      a15: v102,
                                                      a16: v105,
                                                      a17: v107,
                                                      a18: v109,
                                                      a19: v111,
                                                      a20: v113,
                                                      a21: v115,
                                                      a22: v117,
                                                      a23: v119,
                                                      a24: v121,
                                                      a25: v123,
                                                      a26: v125,
                                                      a27: v127,
                                                      a28: v56->entityNumber,
                                                      a29: v129,
                                                      a30: false,
                                                      a31: v131,
                                                      a32: (int)"w:\\tech5\\tungsten\\game\\player\\AimAssist.cpp(204) : Translation")->world;
      }
      if ( v39 != 0 )
      {
        this->lastZoomSnap = false;
        idPLogScope::~idPLogScope(this: &v134);
        goto LABEL_99;
      }
      if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->thisFrameEntity) == nullptr
        || p_thisFrameEntity->spawnId != this->lastFrameEntity.spawnId )
      {
        goto LABEL_71;
      }
      this->frictionScalar = this->desiredFrictionScalar;
      if ( ShouldZoomSnap != 0 && v133 )
      {
        if ( this->zoomSnapAimPoint.x != vec3_origin.x
          || this->zoomSnapAimPoint.y != vec3_origin.y
          || (v57 = 1, this->zoomSnapAimPoint.z != vec3_origin.z) )
        {
          v57 = 0;
        }
        if ( v57 != 0 )
        {
          y = v154.endpos.y;
          z = v154.endpos.z;
          this->zoomSnapAimPoint.x = v154.endpos.x;
          this->zoomSnapAimPoint.y = y;
          this->zoomSnapAimPoint.z = z;
        }
        if ( v154.c.type != CONTACT_NONE
          && (v60 = idClientGame::GetPresentableByEntityNum(this: clientGame, entityNum: v154.c.entityNum)) == idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->thisFrameEntity)
          || v156.c.type != CONTACT_NONE
          && (v61 = idClientGame::GetPresentableByEntityNum(this: clientGame, entityNum: v156.c.entityNum)) == idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->thisFrameEntity) )
        {
          idAimAssist::SnapToAimPoint(
            this: (idAimAssist *)LODWORD(this->zoomSnapAimPoint.x),
            aimPoint: (idVec3 *)LODWORD(this->zoomSnapAimPoint.y),
            aimPower: *(float *)&mapType);
        }
LABEL_71:
        if ( aa_TargetDebug.valueInteger != 0
          && idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->thisFrameEntity) != nullptr )
        {
          v69 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->thisFrameEntity);
          frictionScalar = this->frictionScalar;
          HIDWORD(v70) = LODWORD(frictionScalar);
          v71 = v69;
          v74 = va::va(
                  this: &v157,
                  fmt: "friction: %f",
                  a3: v70,
                  a4: v73,
                  a5: v72,
                  a6: v89,
                  a7: v91,
                  a8: (int)v93,
                  a9: v95,
                  a10: v97,
                  a11: v99);
          ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
            a1: clientGame->renderWorld,
            a2: v74,
            a3: &v71->origin,
            a4: clientGame->renderWorld->__vftable,
            a5: &idColor::colorLtGrey,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: 1.0);
        }
        goto _M492633_2;
      }
      v62 = *(float *)&mapType;
      v63 = *(_QWORD *)&v140.x;
      this->zoomSnapAimPoint = vec3_origin;
      idAimAssist::CalculateAssistAngles(this: (idAimAssist *)HIDWORD(v63), aim: (idVec3 *)v63, aimAssistPower: v62);
      if ( aa_TargetDebug.valueInteger != 0 )
      {
        v64 = (idPresentablePlayer *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->player);
        idPresentablePlayer::GetViewTransform(this: v64, origin: &v138, axis: &v152);
        if ( aa_TargetDebug.valueInteger != 0 )
        {
          v142[2] = v138.z + (float)(v152.mat[0].z * (float)36.0);
          v142[1] = v138.y + (float)(v152.mat[0].y * (float)36.0);
          v142[0] = v138.x + (float)(v152.mat[0].x * (float)36.0);
          ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idVec3 *, double))clientGame->renderWorld->DebugArrow)(
            a1: clientGame->renderWorld,
            a2: &idColor::colorCyan,
            a3: v142,
            a4: &v140,
            a5: 0.5);
        }
        v65 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->thisFrameEntity);
        v66 = (float *)v65->GetAbsBounds(this: (idPresentable *)&v155, result: (idBounds *)v65, a3: -1);
        v67 = (float)(v66[2] + v66[5]);
        v68 = (float)(v66[1] + v66[4]);
        v149[0] = (float)(*v66 + v66[3]) * (float)0.5;
        v149[3] = 1.0;
        v149[2] = (float)v67 * (float)0.5;
        v149[1] = (float)v68 * (float)0.5;
        clientGame->renderWorld->DebugSphere(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorLtGrey,
          a3: (const idSphere *)v149,
          a4: 12,
          a5: 0,
          a6: false);
        *(float *)&v135 = v152.mat[0].y * (float)36.0;
        v144 = v138.z + (float)(v152.mat[0].z * (float)36.0);
        v143[1] = v138.y + *(float *)&v135;
        v143[0] = (float)(v152.mat[0].x * (float)36.0) + v138.x;
        v148[0] = v143[0] + v137.x;
        v148[2] = v137.z + v144;
        v148[1] = v137.y + (float)(v138.y + *(float *)&v135);
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorGreen,
          a3: v143,
          a4: v148,
          a5: 0.5);
        goto LABEL_71;
      }
    }
_M492633_2:
    idPLogScope::~idPLogScope(this: &v134);
    goto LABEL_99;
  }
  this->angleCorrection = ang_zero;
  idPLogScope::~idPLogScope(this: &v134);
LABEL_99:
  RD_EventEnd();
}


// ========================================================================
// __unwind$491891_0
// EA  : 0x82DF5B9C
// RVA : 0x00DF5B9C
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void _unwind_491891_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4960 + 4800));
}


// ========================================================================
// __unwind$491892_0
// EA  : 0x82DF5BC4
// RVA : 0x00DF5BC4
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void _unwind_491892_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4960 + 120));
}


// ========================================================================
// __unwind$491893_0
// EA  : 0x82DF5BEC
// RVA : 0x00DF5BEC
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void _unwind_491893_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4960 + 4801));
}


// ========================================================================
// __unwind$491894_0
// EA  : 0x82DF5C14
// RVA : 0x00DF5C14
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void _unwind_491894_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4960 + 120));
}


// ========================================================================
// `dynamic initializer for 'aa_lockdist''
// EA  : 0x83386118
// RVA : 0x01386118
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_lockdist__()
{
  idCVar::idCVar(
    this: &aa_lockdist,
    name: "aa_lockdist",
    value: "8192",
    flags: 4,
    description: "Max distance from player to enemy.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_lockdist__);
}


// ========================================================================
// `dynamic initializer for 'aa_lockLineRange''
// EA  : 0x83386170
// RVA : 0x01386170
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_lockLineRange__()
{
  idCVar::idCVar(
    this: &aa_lockLineRange,
    name: "aa_lockLineRange",
    value: "35",
    flags: 4,
    description: "Max distance between aim line and tested entity for aim assist",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_lockLineRange__);
}


// ========================================================================
// `dynamic initializer for 'aa_shootingLockSpeed''
// EA  : 0x833861C8
// RVA : 0x013861C8
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_shootingLockSpeed__()
{
  idCVar::idCVar(
    this: &aa_shootingLockSpeed,
    name: "aa_shootingLockSpeed",
    value: "0.6",
    flags: 4,
    description: "Speed that lock occurs for shooting",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_shootingLockSpeed__);
}


// ========================================================================
// `dynamic initializer for 'aa_shrink''
// EA  : 0x83386220
// RVA : 0x01386220
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_shrink__()
{
  idCVar::idCVar(
    this: &aa_shrink,
    name: "aa_shrink",
    value: "5",
    flags: 4,
    description: "Shrink center line",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_shrink__);
}


// ========================================================================
// `dynamic initializer for 'aa_zoomLockSpeed''
// EA  : 0x83386278
// RVA : 0x01386278
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_zoomLockSpeed__()
{
  idCVar::idCVar(
    this: &aa_zoomLockSpeed,
    name: "aa_zoomLockSpeed",
    value: "1.5",
    flags: 4,
    description: "Speed for lock when zooming",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_zoomLockSpeed__);
}


// ========================================================================
// `dynamic initializer for 'aa_adhesionLockSpeed''
// EA  : 0x833862D0
// RVA : 0x013862D0
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_adhesionLockSpeed__()
{
  idCVar::idCVar(
    this: &aa_adhesionLockSpeed,
    name: "aa_adhesionLockSpeed",
    value: "0.25",
    flags: 4,
    description: "Speed for lock when adhesion",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_adhesionLockSpeed__);
}


// ========================================================================
// `dynamic initializer for 'aa_focusSensitivityScale''
// EA  : 0x83386328
// RVA : 0x01386328
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_focusSensitivityScale__()
{
  idCVar::idCVar(
    this: &aa_focusSensitivityScale,
    name: "aa_focusSensitivityScale",
    value: "0.5",
    flags: 4,
    description: "How much to scale the sensitivity by when you're over an interesting entity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_focusSensitivityScale__);
}


// ========================================================================
// `dynamic initializer for 'aa_UseOld''
// EA  : 0x83386380
// RVA : 0x01386380
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_UseOld__()
{
  idCVar::idCVar(
    this: &aa_UseOld,
    name: "aa_UseOld",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_UseOld__);
}


// ========================================================================
// `dynamic initializer for 'aa_TargetDebug''
// EA  : 0x833863D8
// RVA : 0x013863D8
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_TargetDebug__()
{
  idCVar::idCVar(
    this: &aa_TargetDebug,
    name: "aa_TargetDebug",
    value: "0",
    flags: 1,
    description: "if true will show debug for the the aim assist",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_TargetDebug__);
}


// ========================================================================
// `dynamic initializer for 'aa_SensitivityScaleBestSpot''
// EA  : 0x83386430
// RVA : 0x01386430
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_SensitivityScaleBestSpot__()
{
  idCVar::idCVar(
    this: &aa_SensitivityScaleBestSpot,
    name: "aa_SensitivityScaleBestSpot",
    value: "0.4",
    flags: 4,
    description: "How much to scale the sensitivity by when you're on interesting entity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_SensitivityScaleBestSpot__);
}


// ========================================================================
// `dynamic initializer for 'aa_SensitivityScaleSweetSpot''
// EA  : 0x83386488
// RVA : 0x01386488
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_SensitivityScaleSweetSpot__()
{
  idCVar::idCVar(
    this: &aa_SensitivityScaleSweetSpot,
    name: "aa_SensitivityScaleSweetSpot",
    value: "0.5",
    flags: 4,
    description: "How much to scale the sensitivity by when you're really close to an interesting entity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_SensitivityScaleSweetSpot__);
}


// ========================================================================
// `dynamic initializer for 'aa_SensitivityScale''
// EA  : 0x833864E0
// RVA : 0x013864E0
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_SensitivityScale__()
{
  idCVar::idCVar(
    this: &aa_SensitivityScale,
    name: "aa_SensitivityScale",
    value: "0.75",
    flags: 4,
    description: "How much to scale the sensitivity by when you're somewhat close to an interesting entity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_SensitivityScale__);
}


// ========================================================================
// `dynamic initializer for 'aa_AssistStrengthBestSpot''
// EA  : 0x83386538
// RVA : 0x01386538
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_AssistStrengthBestSpot__()
{
  idCVar::idCVar(
    this: &aa_AssistStrengthBestSpot,
    name: "aa_AssistStrengthBestSpot",
    value: "0.005",
    flags: 4,
    description: "How much to help by when in the BEST spot",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_AssistStrengthBestSpot__);
}


// ========================================================================
// `dynamic initializer for 'aa_AssistStrengthSweetSpot''
// EA  : 0x83386590
// RVA : 0x01386590
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_AssistStrengthSweetSpot__()
{
  idCVar::idCVar(
    this: &aa_AssistStrengthSweetSpot,
    name: "aa_AssistStrengthSweetSpot",
    value: "0.015",
    flags: 4,
    description: "How much to help by when in the sweet spot",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_AssistStrengthSweetSpot__);
}


// ========================================================================
// `dynamic initializer for 'aa_AssistStrength''
// EA  : 0x833865E8
// RVA : 0x013865E8
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_AssistStrength__()
{
  idCVar::idCVar(
    this: &aa_AssistStrength,
    name: "aa_AssistStrength",
    value: "0.01",
    flags: 4,
    description: "How much to help by when somewhat close",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_AssistStrength__);
}


// ========================================================================
// `dynamic initializer for 'aa_minAssistDistance''
// EA  : 0x83386640
// RVA : 0x01386640
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_minAssistDistance__()
{
  idCVar::idCVar(
    this: &aa_minAssistDistance,
    name: "aa_minAssistDistance",
    value: "32",
    flags: 4,
    description: "min distance the target has to be before we will aim assist",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_minAssistDistance__);
}


// ========================================================================
// `dynamic initializer for 'aa_sensitivityThreshold''
// EA  : 0x83386698
// RVA : 0x01386698
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_sensitivityThreshold__()
{
  idCVar::idCVar(
    this: &aa_sensitivityThreshold,
    name: "aa_sensitivityThreshold",
    value: "2",
    flags: 2,
    description: "the min threshold the user must change their view by to get assistance !this should not go below 2!",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_sensitivityThreshold__);
}


// ========================================================================
// `dynamic initializer for 'aa_ZoomSnapScale''
// EA  : 0x833866F0
// RVA : 0x013866F0
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aa_ZoomSnapScale__()
{
  idCVar::idCVar(
    this: &aa_ZoomSnapScale,
    name: "aa_ZoomSnapScale",
    value: "2.0f",
    flags: 4,
    description: "the scale that is applied to the zoom snap",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aa_ZoomSnapScale__);
}


// ========================================================================
// `dynamic initializer for 'aa_AssistMode_v''
// EA  : 0x83386748
// RVA : 0x01386748
// PDB : w:\tech5\tungsten\game\player\aimassist.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__aa_AssistMode_v__()
{
  return idCommandLink::idCommandLink(
           this: &aa_AssistMode_v,
           cmdName: "aa_AssistMode",
           function: aa_AssistMode_f,
           description: "sets the aim assist to easy mode",
           argCompletion: nullptr);
}

