
// ========================================================================
// ?SetLookMode@idSpringCamera@@IAAXW4lookMode_t@1@@Z
// EA  : 0x82CC6E90
// RVA : 0x00CC6E90
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetLookMode(idSpringCamera *this, idSpringCamera::lookMode_t mode)
{
  idSpringCamera::lookMode_t valueInteger; // r5
  const char *EnumValueName; // r31
  int v4; // r3

  valueInteger = mode;
  if ( mode != LOOK_NONE && springCam_ForceLookMode.valueInteger != -1 )
    valueInteger = springCam_ForceLookMode.valueInteger;
  if ( valueInteger != this->lookMode )
  {
    if ( valueInteger == LOOK_ADD_HEADING || valueInteger == LOOK_ADD_HEADING_AUTOCENTER )
      this->constraintConeDegs = springCam_ConstraintConeDegs.valueFloat;
    if ( valueInteger == LOOK_ADD_DELTAANGLES )
    {
      this->springAutoCenter.p0.x = 0.0;
      this->springAutoCenter.p0.y = 0.0;
      this->springAutoCenter.p0.z = 0.0;
    }
    this->lookMode = valueInteger;
    if ( springCam_DebugTraceStates.valueInteger != 0 )
    {
      EnumValueName = idTypeInfoTools::FindEnumValueName(
                        this: typeInfoTools,
                        enumTypeName: "idSpringCamera::lookMode_t",
                        value: valueInteger);
      v4 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(fmt: "(%d)%s - setting look mode=%s\n", v4, "idSpringCamera::SetLookMode", EnumValueName);
    }
  }
}


// ========================================================================
// ?SetUserChannelFov@idSpringCamera@@QAAXPBD@Z
// EA  : 0x82CC6F88
// RVA : 0x00CC6F88
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetUserChannelFov(idSpringCamera *this, const char *userChannelName)
{
  idIndex<short,enum invalidUserChannelIndex_t> *lookSkeleton; // r4
  idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> v4; // [sp+50h] [-20h] BYREF
  char v5; // [sp+52h] [-1Eh] BYREF

  if ( this->lookAnimator != nullptr && userChannelName != nullptr )
  {
    ((void (__fastcall *)(idHandle<unsigned short,enum invalidUserChannelHandle_t,65535> *))animation->FindUserChannelHandle)(a1: &v4);
    if ( v4.value != 0xFFFF )
    {
      lookSkeleton = (idIndex<short,enum invalidUserChannelIndex_t> *)this->lookSkeleton;
      this->usesUserChannelFov = true;
      this->fovUserChannel.value = HIWORD(idMD6Skel::GetUserChannelIndex(
                                            this: (idMD6Skel *)&v5,
                                            result: lookSkeleton,
                                            handle: &v4)->__vftable);
    }
  }
  else
  {
    this->usesUserChannelFov = false;
  }
}


// ========================================================================
// ?SetFollowBlendMode@idSpringCamera@@QAAXW4blendMode_t@1@@Z
// EA  : 0x82CC7030
// RVA : 0x00CC7030
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetFollowBlendMode(idSpringCamera *this, idSpringCamera::blendMode_t mode)
{
  const char *EnumValueName; // r31
  int v3; // r3

  this->followBlendMode = mode;
  if ( springCam_ForceFollowBlendMode.valueInteger != -1 )
    this->followBlendMode = springCam_ForceFollowBlendMode.valueInteger;
  if ( springCam_DebugTraceStates.valueInteger != 0 )
  {
    EnumValueName = idTypeInfoTools::FindEnumValueName(
                      this: typeInfoTools,
                      enumTypeName: "idSpringCamera::blendMode_t",
                      value: this->followBlendMode);
    v3 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(
      fmt: "(%d)%s - setting follow blend mode=%s\n",
      v3,
      "idSpringCamera::SetFollowBlendMode",
      EnumValueName);
  }
}


// ========================================================================
// ?SetLookBlendMode@idSpringCamera@@QAAXW4blendMode_t@1@@Z
// EA  : 0x82CC70D8
// RVA : 0x00CC70D8
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetLookBlendMode(idSpringCamera *this, idSpringCamera::blendMode_t mode)
{
  const char *EnumValueName; // r31
  int v3; // r3

  this->lookBlendMode = mode;
  if ( springCam_ForceLookBlendMode.valueInteger != -1 )
    this->lookBlendMode = springCam_ForceLookBlendMode.valueInteger;
  if ( springCam_DebugTraceStates.valueInteger != 0 )
  {
    EnumValueName = idTypeInfoTools::FindEnumValueName(
                      this: typeInfoTools,
                      enumTypeName: "idSpringCamera::blendMode_t",
                      value: this->lookBlendMode);
    v3 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "(%d)%s - setting look blend mode=%s\n", v3, "idSpringCamera::SetLookBlendMode", EnumValueName);
  }
}


// ========================================================================
// ?GetAimPoint@idSpringCamera@@UBAXW4aimPoint_t@@AAVidVec3@@@Z
// EA  : 0x82CC7180
// RVA : 0x00CC7180
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::GetAimPoint(idSpringCamera *this, const aimPoint_t type, idVec3 *pos)
{
  *pos = this->springFollowPos.p1;
}


// ========================================================================
// ?ConstructLookTarget@idSpringCamera@@IAAXABVidVec3@@0AAVidMat3@@@Z
// EA  : 0x82CC71A0
// RVA : 0x00CC71A0
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::ConstructLookTarget(
        idSpringCamera *this,
        const idVec3 *followTarget,
        const idVec3 *lookTargetPos,
        idMat3 *lookTarget)
{
  double v4; // fp8
  double v6; // fp5
  double v9; // fp9
  double v10; // fp13
  double v11; // fp10
  double v12; // fp9
  double v13; // fp31
  double v14; // fp30
  double v15; // fp29
  idPlayer *PlayerActivator; // r3
  double v17; // fp0
  double v18; // fp13
  double v19; // fp8
  double v20; // fp12
  double v21; // fp7
  double v22; // fp6
  idVec3 v23; // [sp+50h] [-60h] BYREF
  char v24; // [sp+60h] [-50h] BYREF
  float v25; // [sp+6Ch] [-44h]
  float v26; // [sp+70h] [-40h]
  float v27; // [sp+74h] [-3Ch]

  v4 = (float)(lookTargetPos->y - followTarget->y);
  v6 = (float)(lookTargetPos->z - followTarget->z);
  _FP1 = (float)((float)((float)((float)v6 * (float)v6)
                       + (float)((float)((float)v4 * (float)v4)
                               + (float)((float)(lookTargetPos->x - followTarget->x)
                                       * (float)(lookTargetPos->x - followTarget->x))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f10, f1, f2, f13 }
  v9 = __frsqrte(_FP10);
  v10 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v9
                                                                                      * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v4 * (float)v4) + (float)((float)(lookTargetPos->x - followTarget->x) * (float)(lookTargetPos->x - followTarget->x))))
                                                                                              * (float)0.5))
                                                                              * (float)v9)
                                                                      - (float)1.5)
                                                      * (float)v9)
                                              * (float)((float)((float)((float)v6 * (float)v6)
                                                              + (float)((float)((float)v4 * (float)v4)
                                                                      + (float)((float)(lookTargetPos->x
                                                                                      - followTarget->x)
                                                                              * (float)(lookTargetPos->x
                                                                                      - followTarget->x))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v9
                                                                              * (float)((float)((float)((float)v6 * (float)v6)
                                                                                              + (float)((float)((float)v4 * (float)v4) + (float)((float)(lookTargetPos->x - followTarget->x) * (float)(lookTargetPos->x - followTarget->x))))
                                                                                      * (float)0.5))
                                                                      * (float)v9)
                                                              - (float)1.5)
                                              * (float)v9))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v9
                                                      * (float)((float)((float)((float)v6 * (float)v6)
                                                                      + (float)((float)((float)v4 * (float)v4)
                                                                              + (float)((float)(lookTargetPos->x
                                                                                              - followTarget->x)
                                                                                      * (float)(lookTargetPos->x
                                                                                              - followTarget->x))))
                                                              * (float)0.5))
                                              * (float)v9)
                                      - (float)1.5)
                      * (float)v9));
  v11 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v9 * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v4 * (float)v4) + (float)((float)(lookTargetPos->x - followTarget->x) * (float)(lookTargetPos->x - followTarget->x)))) * (float)0.5)) * (float)v9) - (float)1.5)
                                                                                      * (float)v9)
                                                                              * (float)((float)((float)((float)v6 * (float)v6)
                                                                                              + (float)((float)((float)v4 * (float)v4) + (float)((float)(lookTargetPos->x - followTarget->x) * (float)(lookTargetPos->x - followTarget->x))))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v9 * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v4 * (float)v4) + (float)((float)(lookTargetPos->x - followTarget->x) * (float)(lookTargetPos->x - followTarget->x)))) * (float)0.5)) * (float)v9)
                                                                                              - (float)1.5)
                                                                              * (float)v9))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v9
                                                                                      * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v4 * (float)v4) + (float)((float)(lookTargetPos->x - followTarget->x) * (float)(lookTargetPos->x - followTarget->x))))
                                                                                              * (float)0.5))
                                                                              * (float)v9)
                                                                      - (float)1.5)
                                                      * (float)v9))
                                      * (float)((float)((float)((float)v6 * (float)v6)
                                                      + (float)((float)((float)v4 * (float)v4)
                                                              + (float)((float)(lookTargetPos->x - followTarget->x)
                                                                      * (float)(lookTargetPos->x - followTarget->x))))
                                              * (float)0.5))
                              * (float)v10)
                      - (float)1.5);
  v12 = (float)((float)v11
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v9
                                                                                              * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v4 * (float)v4) + (float)((float)(lookTargetPos->x - followTarget->x) * (float)(lookTargetPos->x - followTarget->x)))) * (float)0.5))
                                                                                      * (float)v9)
                                                                              - (float)1.5)
                                                              * (float)v9)
                                                      * (float)((float)((float)((float)v6 * (float)v6)
                                                                      + (float)((float)((float)v4 * (float)v4)
                                                                              + (float)((float)(lookTargetPos->x
                                                                                              - followTarget->x)
                                                                                      * (float)(lookTargetPos->x
                                                                                              - followTarget->x))))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v9
                                                                                      * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v4 * (float)v4) + (float)((float)(lookTargetPos->x - followTarget->x) * (float)(lookTargetPos->x - followTarget->x))))
                                                                                              * (float)0.5))
                                                                              * (float)v9)
                                                                      - (float)1.5)
                                                      * (float)v9))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v9
                                                              * (float)((float)((float)((float)v6 * (float)v6)
                                                                              + (float)((float)((float)v4 * (float)v4)
                                                                                      + (float)((float)(lookTargetPos->x - followTarget->x)
                                                                                              * (float)(lookTargetPos->x - followTarget->x))))
                                                                      * (float)0.5))
                                                      * (float)v9)
                                              - (float)1.5)
                              * (float)v9)));
  v13 = (float)((float)(lookTargetPos->x - followTarget->x) * (float)v12);
  v14 = (float)((float)(lookTargetPos->y - followTarget->y) * (float)v12);
  v15 = (float)((float)(lookTargetPos->z - followTarget->z) * (float)v12);
  PlayerActivator = idCamera::GetPlayerActivator(this);
  PlayerActivator->GetViewTransform(this: PlayerActivator, a2: &v23, a3: (idMat3 *)&v24);
  v17 = v25;
  v18 = v26;
  v19 = (float)(v25 * (float)v14);
  v20 = v27;
  v21 = (float)(v26 * (float)v15);
  v22 = (float)(v27 * (float)v13);
  lookTarget->mat[0].x = v13;
  lookTarget->mat[0].y = v14;
  lookTarget->mat[0].z = v15;
  lookTarget->mat[1].x = (float)((float)((float)((float)v17 * (float)v15) - (float)v22) * (float)v15)
                       - (float)((float)((float)((float)v18 * (float)v13) - (float)v19) * (float)v14);
  lookTarget->mat[1].y = (float)((float)((float)((float)v18 * (float)v13) - (float)v19) * (float)v13)
                       - (float)((float)((float)((float)v20 * (float)v14) - (float)v21) * (float)v15);
  lookTarget->mat[1].z = (float)((float)((float)((float)v20 * (float)v14) - (float)v21) * (float)v14)
                       - (float)((float)((float)((float)v17 * (float)v15) - (float)v22) * (float)v13);
  lookTarget->mat[2].x = (float)((float)v20 * (float)v14) - (float)v21;
  lookTarget->mat[2].y = (float)((float)v17 * (float)v15) - (float)v22;
  lookTarget->mat[2].z = (float)((float)v18 * (float)v13) - (float)v19;
}


// ========================================================================
// ?GetCalculateViewStage@idSpringCamera@@QBA?AW4calculateViewStage_t@1@PAVidPlayer@@@Z
// EA  : 0x82CC72E8
// RVA : 0x00CC72E8
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

idSpringCamera::calculateViewStage_t __fastcall idSpringCamera::GetCalculateViewStage(
        idSpringCamera *this,
        idPlayer *player)
{
  idSpringCamera::calculateViewStage_t result; // r3
  idPresentable *presentable; // r3
  idPresentablePlayer *v5; // r3

  result = springCam_ForceCalcViewStage.valueInteger;
  if ( springCam_ForceCalcViewStage.valueInteger == 0 )
  {
    result = this->forceCalculateViewStage;
    if ( result == STAGE_DEFAULT )
    {
      if ( player != nullptr
        && ((presentable = player->presentable) == nullptr
          ? (v5 = nullptr)
          : (v5 = presentable->GetPlayerInterface_2(this: presentable)),
            idPresentablePlayer::GetControl(this: v5) != nullptr) )
      {
        return STAGE_UPDATE;
      }
      else
      {
        return this->manualUpdate;
      }
    }
  }
  return result;
}


// ========================================================================
// ?SetBlendMode@idSpringCamera@@QAAXW4blendMode_t@1@@Z
// EA  : 0x82CC7390
// RVA : 0x00CC7390
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetBlendMode(idSpringCamera *this, idSpringCamera::blendMode_t mode)
{
  idSpringCamera::blendMode_t v3; // r31

  if ( mode == BLEND_FOLLOW_SNAP_LOOK_SMOOTH_SNAP_SMOOTH )
  {
    mode = BLEND_SNAP;
    v3 = BLEND_SMOOTH_SNAP_SMOOTH;
  }
  else
  {
    v3 = mode;
  }
  idSpringCamera::SetFollowBlendMode(this, mode);
  idSpringCamera::SetLookBlendMode(this, mode: v3);
}


// ========================================================================
// ?SetFollowDestination@idSpringCamera@@QAAXABVidVec3@@_N@Z
// EA  : 0x82CC73F0
// RVA : 0x00CC73F0
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetFollowDestination(idSpringCamera *this, const idVec3 *pos, bool snap)
{
  this->springFollowPos.p0 = *pos;
  if ( snap )
  {
    this->springFollowPos.p1 = this->springFollowPos.p0;
    this->springFollowPos.vel.z = 0.0;
    this->springFollowPos.vel.y = 0.0;
    this->springFollowPos.vel.x = 0.0;
  }
}


// ========================================================================
// ?SetLookDestination@idSpringCamera@@QAAXABVidVec3@@0_N@Z
// EA  : 0x82CC7448
// RVA : 0x00CC7448
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetLookDestination(
        idSpringCamera *this,
        const idVec3 *fwdDir,
        const idVec3 *upDir,
        bool snap)
{
  double x; // fp0
  double z; // fp10
  double y; // fp9
  double v9; // fp2
  double v10; // fp3
  double v11; // fp2
  double v12; // fp4
  double v13; // fp6
  double v14; // fp11
  double v15; // fp5
  double v16; // fp2
  double v19; // fp8
  double v20; // fp6
  double v21; // fp12
  double v22; // fp11
  double v23; // fp8

  x = fwdDir->x;
  this->springLookFwdDir.p0.x = fwdDir->x;
  this->springLookFwdDir.p0.y = fwdDir->y;
  z = fwdDir->z;
  this->springLookFwdDir.p0.z = fwdDir->z;
  y = this->springLookFwdDir.p0.y;
  _FP5 = (float)((float)((float)((float)z * (float)z)
                       + (float)((float)((float)x * (float)x)
                               + (float)(this->springLookFwdDir.p0.y * this->springLookFwdDir.p0.y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v9 = __frsqrte(_FP3);
  v10 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v9
                                                                                      * (float)((float)((float)((float)z * (float)z) + (float)((float)((float)x * (float)x) + (float)(this->springLookFwdDir.p0.y * this->springLookFwdDir.p0.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v9)
                                                                      - (float)1.5)
                                                      * (float)v9)
                                              * (float)((float)((float)((float)z * (float)z)
                                                              + (float)((float)((float)x * (float)x)
                                                                      + (float)(this->springLookFwdDir.p0.y
                                                                              * this->springLookFwdDir.p0.y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v9
                                                                              * (float)((float)((float)((float)z * (float)z)
                                                                                              + (float)((float)((float)x * (float)x) + (float)(this->springLookFwdDir.p0.y * this->springLookFwdDir.p0.y)))
                                                                                      * (float)0.5))
                                                                      * (float)v9)
                                                              - (float)1.5)
                                              * (float)v9))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v9
                                                      * (float)((float)((float)((float)z * (float)z)
                                                                      + (float)((float)((float)x * (float)x)
                                                                              + (float)(this->springLookFwdDir.p0.y
                                                                                      * this->springLookFwdDir.p0.y)))
                                                              * (float)0.5))
                                              * (float)v9)
                                      - (float)1.5)
                      * (float)v9));
  v11 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v9
                                                                                              * (float)((float)((float)((float)z * (float)z) + (float)((float)((float)x * (float)x) + (float)(this->springLookFwdDir.p0.y * this->springLookFwdDir.p0.y))) * (float)0.5))
                                                                                      * (float)v9)
                                                                              - (float)1.5)
                                                              * (float)v9)
                                                      * (float)((float)((float)((float)z * (float)z)
                                                                      + (float)((float)((float)x * (float)x)
                                                                              + (float)(this->springLookFwdDir.p0.y
                                                                                      * this->springLookFwdDir.p0.y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v9
                                                                                      * (float)((float)((float)((float)z * (float)z) + (float)((float)((float)x * (float)x) + (float)(this->springLookFwdDir.p0.y * this->springLookFwdDir.p0.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v9)
                                                                      - (float)1.5)
                                                      * (float)v9))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v9
                                                              * (float)((float)((float)((float)z * (float)z)
                                                                              + (float)((float)((float)x * (float)x)
                                                                                      + (float)(this->springLookFwdDir.p0.y
                                                                                              * this->springLookFwdDir.p0.y)))
                                                                      * (float)0.5))
                                                      * (float)v9)
                                              - (float)1.5)
                              * (float)v9))
              * (float)((float)((float)((float)z * (float)z)
                              + (float)((float)((float)x * (float)x)
                                      + (float)(this->springLookFwdDir.p0.y * this->springLookFwdDir.p0.y)))
                      * (float)0.5));
  this->springLookFwdDir.p0.z = (float)z
                              * (float)((float)-(float)((float)((float)v11 * (float)v10) - (float)1.5) * (float)v10);
  this->springLookFwdDir.p0.x = (float)x
                              * (float)((float)-(float)((float)((float)v11 * (float)v10) - (float)1.5) * (float)v10);
  this->springLookFwdDir.p0.y = (float)y
                              * (float)((float)-(float)((float)((float)v11 * (float)v10) - (float)1.5) * (float)v10);
  v12 = upDir->x;
  this->springLookUpDir.p0.x = upDir->x;
  v13 = upDir->y;
  v14 = (float)((float)((float)v12 * (float)v12) + (float)(upDir->y * upDir->y));
  this->springLookUpDir.p0.y = upDir->y;
  v15 = upDir->z;
  v16 = v13;
  this->springLookUpDir.p0.z = upDir->z;
  _FP9 = (float)((float)((float)((float)v15 * (float)v15) + (float)v14) - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f7, f9, f10, f13 }
  v19 = (float)((float)((float)((float)v15 * (float)v15) + (float)v14) * (float)0.5);
  v20 = __frsqrte(_FP7);
  v21 = (float)((float)-(float)((float)((float)((float)v20
                                              * (float)((float)((float)((float)v15 * (float)v15) + (float)v14)
                                                      * (float)0.5))
                                      * (float)v20)
                              - (float)1.5)
              * (float)v20);
  v22 = (float)((float)((float)-(float)((float)((float)((float)v20
                                                      * (float)((float)((float)((float)v15 * (float)v15) + (float)v14)
                                                              * (float)0.5))
                                              * (float)v20)
                                      - (float)1.5)
                      * (float)v20)
              * (float)((float)((float)((float)v15 * (float)v15) + (float)v14) * (float)0.5));
  v23 = (float)((float)((float)-(float)((float)((float)v22 * (float)v21) - (float)1.5) * (float)v21) * (float)v19);
  this->springLookUpDir.p0.x = (float)v12
                             * (float)((float)-(float)((float)((float)v23
                                                             * (float)((float)-(float)((float)((float)v22 * (float)v21)
                                                                                     - (float)1.5)
                                                                     * (float)v21))
                                                     - (float)1.5)
                                     * (float)((float)-(float)((float)((float)v22 * (float)v21) - (float)1.5)
                                             * (float)v21));
  this->springLookUpDir.p0.y = (float)v16
                             * (float)((float)-(float)((float)((float)v23
                                                             * (float)((float)-(float)((float)((float)v22 * (float)v21)
                                                                                     - (float)1.5)
                                                                     * (float)v21))
                                                     - (float)1.5)
                                     * (float)((float)-(float)((float)((float)v22 * (float)v21) - (float)1.5)
                                             * (float)v21));
  this->springLookUpDir.p0.z = (float)v15
                             * (float)((float)-(float)((float)((float)v23
                                                             * (float)((float)-(float)((float)((float)v22 * (float)v21)
                                                                                     - (float)1.5)
                                                                     * (float)v21))
                                                     - (float)1.5)
                                     * (float)((float)-(float)((float)((float)v22 * (float)v21) - (float)1.5)
                                             * (float)v21));
  if ( snap )
  {
    this->springLookFwdDir.p1 = this->springLookFwdDir.p0;
    this->springLookFwdDir.vel.y = 0.0;
    this->springLookFwdDir.vel.z = 0.0;
    this->springLookFwdDir.vel.x = 0.0;
    this->springLookUpDir.p1 = this->springLookUpDir.p0;
    this->springLookUpDir.vel.z = 0.0;
    this->springLookUpDir.vel.y = 0.0;
    this->springLookUpDir.vel.x = 0.0;
  }
}


// ========================================================================
// ?InternalCalculateView@idSpringCamera@@IAAXPAVidPlayer@@@Z
// EA  : 0x82CC75D0
// RVA : 0x00CC75D0
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::InternalCalculateView(idSpringCamera *this, idPlayer *player)
{
  int v4; // r3
  BOOL getPlayerLookFromView; // r9
  idPresentable *presentable; // r3
  int v7; // r30
  double v8; // fp19
  float *v9; // r3
  idPresentable *v10; // r11
  float *v11; // r3
  idSpringCamera::state_t state; // r11
  double x; // fp28
  double y; // fp29
  double z; // fp30
  double v16; // fp22
  double v17; // fp23
  double v18; // fp24
  double v19; // fp25
  double v20; // fp26
  double v21; // fp27
  double v22; // fp21
  float v23; // r10
  double v24; // fp31
  float v25; // r9
  idVec3 *p_viewOrigin; // r30
  idSpringCamera::state_t followState; // r8
  double v28; // fp13
  double v29; // fp12
  float v30; // r10
  float v31; // r11
  double v32; // fp8
  double v33; // fp13
  double v34; // fp20
  double v35; // fp18
  double v36; // fp17
  double v37; // fp16
  double v38; // fp15
  double v39; // fp14
  int v40; // r3
  idTreeAnimator *lookAnimator; // r11
  int value; // r10
  char *v43; // r11
  int v44; // r11
  int v45; // r10
  double v46; // fp12
  double v47; // fp11
  double v48; // fp10
  double v49; // fp9
  double v50; // fp8
  double v51; // fp7
  double v52; // fp6
  float v53; // r10
  float v54; // r6
  float v55; // r9
  float v56; // r7
  double v57; // fp27
  double v58; // fp26
  double v59; // fp25
  double v60; // fp31
  double v61; // fp30
  double v62; // fp29
  double v63; // fp0
  double v64; // fp12
  double v65; // fp1
  double v66; // fp13
  double v67; // fp11
  double v68; // fp10
  int v69; // r3
  int viewTimestamp; // r9
  __int64 v71; // r6
  double v72; // fp9
  double v73; // fp6
  idPresentable *v74; // r3
  idPresentablePlayer *v75; // r3
  double v76; // [sp+8h] [-1A8h]
  double v77; // [sp+10h] [-1A0h]
  idVec3 v78; // [sp+80h] [-130h] BYREF
  idVec3 v79; // [sp+90h] [-120h] BYREF
  float v80; // [sp+A0h] [-110h]
  float v81; // [sp+A4h] [-10Ch]
  float v82; // [sp+A8h] [-108h]
  idMat3 v83; // [sp+B0h] [-100h] BYREF
  float v84; // [sp+D4h] [-DCh]
  float v85; // [sp+D8h] [-D8h]
  float v86; // [sp+DCh] [-D4h]
  float v87; // [sp+E0h] [-D0h]

  if ( this->state == STATE_INACTIVE || this->lastUpdateFrame == gameLocal->GetGameFrame(this: gameLocal) )
    return;
  v4 = gameLocal->GetGameFrame(this: gameLocal);
  getPlayerLookFromView = this->getPlayerLookFromView;
  this->lastUpdateFrame = v4;
  presentable = player->presentable;
  if ( getPlayerLookFromView )
  {
    if ( presentable != nullptr )
      v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v7 = 0;
    idView::GetViewPos(this: (idView *)(v7 + 16224), origin: &v79, axis: (idMat3 *)&v83.mat[1].y);
    v8 = *(float *)(v7 + 18112);
  }
  else
  {
    if ( presentable != nullptr )
      v9 = (float *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v9 = nullptr;
    v10 = player->presentable;
    v79.x = v9[11633];
    v79.y = v9[11634];
    v79.z = v9[11635];
    if ( v10 != nullptr )
      v11 = (float *)v10->GetPlayerInterface_2(this: v10);
    else
      v11 = nullptr;
    v83.mat[1].y = v11[11636];
    v83.mat[1].z = v11[11637];
    v83.mat[2].x = v11[11638];
    v83.mat[2].y = v11[11639];
    v83.mat[2].z = v11[11640];
    v84 = v11[11641];
    v85 = v11[11642];
    v86 = v11[11643];
    v87 = v11[11644];
    v8 = idPlayer::CalcFov(this: player, honorZoom: true);
  }
  state = this->state;
  v78.x = v8;
  if ( (unsigned int)state > (STATE_ACTIVE_READY_TO_BLEND_OUT|STATE_REACTIVATE) )
    goto LABEL_24;
  if ( state == STATE_INACTIVE )
  {
LABEL_23:
    x = v79.x;
    y = v79.y;
    z = v79.z;
    v16 = v83.mat[1].y;
    v17 = v83.mat[1].z;
    v18 = v83.mat[2].x;
    v19 = v85;
    v20 = v86;
    v21 = v87;
    idMat3::ToAngles(this: &v83, result: (idAngles *)&v83.mat[1].y);
    goto LABEL_25;
  }
  if ( state != STATE_BLEND_IN && state != STATE_REACTIVATE && state != STATE_ACTIVE )
  {
    if ( state != STATE_ACTIVE_READY_TO_BLEND_OUT )
      goto LABEL_23;
LABEL_24:
    z = v83.mat[0].z;
    y = v83.mat[0].y;
    x = v83.mat[0].x;
    v21 = v87;
    v20 = v86;
    v19 = v85;
    v18 = v83.mat[2].x;
    v17 = v83.mat[1].z;
    v16 = v83.mat[1].y;
    goto LABEL_25;
  }
  x = this->fromViewOrigin.x;
  y = this->fromViewOrigin.y;
  z = this->fromViewOrigin.z;
  v16 = this->fromViewAxis.mat[0].x;
  v17 = this->fromViewAxis.mat[0].y;
  v18 = this->fromViewAxis.mat[0].z;
  v19 = this->fromViewAxis.mat[2].x;
  v20 = this->fromViewAxis.mat[2].y;
  v21 = this->fromViewAxis.mat[2].z;
LABEL_25:
  v22 = this->followBlendSpring.p1.x;
  v23 = this->viewOrigin.y;
  v24 = this->lookBlendSpring.p1.x;
  v25 = this->viewOrigin.z;
  p_viewOrigin = &this->viewOrigin;
  followState = this->followState;
  v80 = this->viewOrigin.x;
  v81 = v23;
  v82 = v25;
  if ( followState != STATE_INACTIVE )
  {
    v30 = this->springFollowPos.p1.z;
    v31 = this->springFollowPos.p1.x;
    v83.mat[0].y = this->springFollowPos.p1.y;
    v83.mat[0].z = v30;
    v83.mat[0].x = v31;
    v32 = (float)((float)(v83.mat[0].y - (float)y) * (float)v22);
    p_viewOrigin->x = (float)((float)(v31 - (float)x) * (float)v22) + (float)x;
    this->viewOrigin.y = (float)v32 + (float)y;
    this->viewOrigin.z = (float)((float)(v30 - (float)z) * (float)v22) + (float)z;
  }
  else
  {
    v28 = v79.y;
    v29 = v79.z;
    p_viewOrigin->x = v79.x;
    this->viewOrigin.y = v28;
    this->viewOrigin.z = v29;
  }
  if ( this->calculatedViewOrigin )
  {
    v34 = v82;
  }
  else
  {
    this->calculatedViewOrigin = true;
    v33 = p_viewOrigin->x;
    v81 = this->viewOrigin.y;
    v34 = this->viewOrigin.z;
    v80 = v33;
  }
  if ( springCam_DebugTraceBlend.valueInteger != 0 )
  {
    v35 = this->springFollowPos.p1.y;
    v36 = this->springFollowPos.p1.x;
    v37 = this->viewOrigin.z;
    v38 = this->viewOrigin.y;
    v39 = p_viewOrigin->x;
    v40 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(
      fmt: "(%d)%s - viewOrigin = (%0.2f,%0.2f,%0.2f ), playerViewOrigin = (%0.2f,%0.2f,%0.2f ), springFollowPos = (%0.2f,%0.2"
      "f,%0.2f ), t=%0.2f\n",
      v40,
      "idSpringCamera::InternalCalculateView",
      v39,
      v38,
      v37,
      x,
      y,
      z,
      v36,
      v35,
      v76,
      v77);
    v8 = v78.x;
  }
  if ( this->springFOV.p0.x <= 0.0 )
    this->viewFov = v8;
  else
    this->viewFov = (float)((float)(this->springFOV.p1.x - (float)v8) * (float)v24) + (float)v8;
  if ( this->usesUserChannelFov )
  {
    lookAnimator = this->lookAnimator;
    if ( lookAnimator != nullptr )
    {
      value = this->fovUserChannel.value;
      v43 = (char *)lookAnimator + ((16 * lookAnimator->currentDeferred) ^ 0x10);
      if ( *((_DWORD *)v43 + 531) > value )
      {
        v44 = *((_DWORD *)v43 + 530);
        v45 = 4 * value;
        if ( *(float *)(v45 + v44) != 0.0 )
          this->viewFov = (float)((float)(*(float *)(v45 + v44) - (float)v8) * (float)v24) + (float)v8;
      }
    }
  }
  if ( this->lookState != STATE_INACTIVE )
  {
    v53 = this->springLookFwdDir.p1.y;
    v54 = this->springLookFwdDir.p1.z;
    v55 = this->springLookUpDir.p1.y;
    v56 = this->springLookUpDir.p1.x;
    v78.x = this->springLookFwdDir.p1.x;
    v78.y = v53;
    v78.z = v54;
    v83.mat[0].y = v55;
    v83.mat[0].x = v56;
    v83.mat[0].z = this->springLookUpDir.p1.z;
    v57 = (float)((float)v21 + (float)((float)(v83.mat[0].z - (float)v21) * (float)v24));
    v78.x = (float)v16 + (float)((float)(v78.x - (float)v16) * (float)v24);
    v78.z = (float)v18 + (float)((float)(v54 - (float)v18) * (float)v24);
    v78.y = (float)v17 + (float)((float)(v53 - (float)v17) * (float)v24);
    v58 = (float)((float)v20 + (float)((float)(v55 - (float)v20) * (float)v24));
    v59 = (float)((float)v19 + (float)((float)(v56 - (float)v19) * (float)v24));
    idVec3::NormalizeFast(this: &v78);
    v60 = v78.y;
    v61 = v78.z;
    v62 = v78.x;
    v83.mat[0].x = (float)((float)v58 * v78.z) - (float)((float)v57 * v78.y);
    v83.mat[0].y = (float)((float)v57 * v78.x) - (float)(v78.z * (float)v59);
    v83.mat[0].z = (float)(v78.y * (float)v59) - (float)((float)v58 * v78.x);
    idVec3::NormalizeFast(this: v83.mat);
    v63 = v83.mat[0].y;
    v64 = v83.mat[0].z;
    v65 = (float)(v83.mat[0].y * (float)v61);
    v66 = v83.mat[0].x;
    v67 = (float)(v83.mat[0].z * (float)v62);
    v68 = (float)((float)v60 * v83.mat[0].x);
    this->viewAxis.mat[0].x = v62;
    this->viewAxis.mat[1].x = v66;
    this->viewAxis.mat[0].y = v60;
    this->viewAxis.mat[0].z = v61;
    this->viewAxis.mat[1].y = v63;
    this->viewAxis.mat[1].z = v64;
    this->viewAxis.mat[2].x = (float)((float)v64 * (float)v60) - (float)v65;
    this->viewAxis.mat[2].y = (float)((float)v61 * (float)v66) - (float)v67;
    this->viewAxis.mat[2].z = (float)((float)v63 * (float)v62) - (float)v68;
  }
  else
  {
    this->viewAxis.mat[0].x = v83.mat[1].y;
    v46 = v83.mat[1].z;
    v47 = v83.mat[2].x;
    this->viewAxis.mat[1].x = v83.mat[2].y;
    v48 = v83.mat[2].z;
    this->viewAxis.mat[0].y = v46;
    this->viewAxis.mat[0].z = v47;
    v49 = v84;
    this->viewAxis.mat[1].y = v48;
    v50 = v85;
    this->viewAxis.mat[1].z = v49;
    v51 = v86;
    this->viewAxis.mat[2].x = v50;
    v52 = v87;
    this->viewAxis.mat[2].y = v51;
    this->viewAxis.mat[2].z = v52;
  }
  v69 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  viewTimestamp = this->viewTimestamp;
  this->viewTimestamp = v69;
  LODWORD(v71) = v69 - viewTimestamp;
  *(_QWORD *)&v78.x = v71;
  if ( (float)((float)v71 * (float)0.001) != 0.0 )
  {
    v72 = (float)(this->viewOrigin.z - (float)v34);
    v73 = (float)(this->viewOrigin.y - v81);
    this->viewVelocity.x = (float)((float)1.0 / (float)((float)v71 * (float)0.001)) * (float)(p_viewOrigin->x - v80);
    this->viewVelocity.y = (float)v73 * (float)((float)1.0 / (float)((float)v71 * (float)0.001));
    this->viewVelocity.z = (float)v72 * (float)((float)1.0 / (float)((float)v71 * (float)0.001));
  }
  v74 = player->presentable;
  if ( v74 != nullptr )
    v75 = v74->GetPlayerInterface_2(this: v74);
  else
    v75 = nullptr;
  idPresentablePlayer::PresentablePlayerBehavior_PostEvent(this: v75, event: PBE_SPRING_CAMERA_VIEW_UPDATED);
  this->calculatedView = true;
}


// ========================================================================
// ?Draw@idSpringCamera@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82CC7C78
// RVA : 0x00CC7C78
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

int __fastcall idSpringCamera::Draw(idSpringCamera *this, idPlayer *player)
{
  idRenderWorld *v5; // r3
  idPresentable *presentable; // r3
  int v7; // r28
  const char *EnumValueName; // r3
  const char *v9; // r3
  const char *v10; // r3
  const char *v11; // r3
  const char *v12; // r3
  const char *v13; // r3
  const char *v14; // r3
  const char *v15; // r3
  idMat3 v16[2]; // [sp+50h] [-50h] BYREF

  if ( player == nullptr )
    return 0;
  if ( idSpringCamera::GetCalculateViewStage(this, player) == STAGE_DRAW || this->calculateViewInDraw )
    idSpringCamera::InternalCalculateView(this, player);
  if ( springCam_Debug.valueInteger != 0 )
  {
    v5 = gameLocal->GetRenderWorld(this: gameLocal);
    v5->DebugAxis_2(this: v5, a2: &this->viewOrigin, a3: &this->viewAxis, a4: 0, a5: false);
    idMat3::ToAngles(this: v16, result: (idAngles *)&this->viewAxis);
  }
  if ( springCam_UpdateView.valueInteger != 0 && !idPlayer::GetNoclip(this: player) )
  {
    presentable = player->presentable;
    if ( presentable != nullptr )
      v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v7 = 0;
    idView::SetViewPos(this: (idView *)(v7 + 16224), origin: &this->viewOrigin, axis: &this->viewAxis);
    idView::CalcFOV(this: (idView *)(v7 + 16224), base_fov: this->viewFov);
    *(float *)(v7 + 18124) = this->viewVelocity.x;
    *(float *)(v7 + 18128) = this->viewVelocity.y;
    *(float *)(v7 + 18132) = this->viewVelocity.z;
    idView::SetViewID(this: (idView *)(v7 + 16224), id: player->entityNumber + 1);
    idView::Render(this: (idView *)(v7 + 16224));
  }
  if ( springCam_Debug.valueInteger != 0 )
  {
    idPlayer::debugHUDPrintf(this: player, fmt: "--- spring camera ---");
    EnumValueName = idTypeInfoTools::FindEnumValueName(
                      this: typeInfoTools,
                      enumTypeName: "idSpringCamera::state_t",
                      value: this->state);
    idPlayer::debugHUDPrintf(this: player, fmt: "camera state: %s", EnumValueName);
    v9 = idTypeInfoTools::FindEnumValueName(
           this: typeInfoTools,
           enumTypeName: "idSpringCamera::lookMode_t",
           value: this->lookMode);
    idPlayer::debugHUDPrintf(this: player, fmt: "look mode: %s", v9);
    v10 = idTypeInfoTools::FindEnumValueName(
            this: typeInfoTools,
            enumTypeName: "idSpringCamera::duration_t",
            value: this->lookDuration);
    idPlayer::debugHUDPrintf(this: player, fmt: "look duration: %s", v10);
    v11 = idTypeInfoTools::FindEnumValueName(
            this: typeInfoTools,
            enumTypeName: "idSpringCamera::state_t",
            value: this->lookState);
    idPlayer::debugHUDPrintf(this: player, fmt: "look state: %s", v11);
    v12 = idTypeInfoTools::FindEnumValueName(
            this: typeInfoTools,
            enumTypeName: "idSpringCamera::blendMode_t",
            value: this->lookBlendMode);
    idPlayer::debugHUDPrintf(this: player, fmt: "look blend mode: %s", v12);
    idPlayer::debugHUDPrintf(this: player, fmt: "lookBlendVal: %0.2f", this->lookBlendSpring.p1.x);
    v13 = idTypeInfoTools::FindEnumValueName(
            this: typeInfoTools,
            enumTypeName: "idSpringCamera::duration_t",
            value: this->followDuration);
    idPlayer::debugHUDPrintf(this: player, fmt: "follow duration: %s", v13);
    v14 = idTypeInfoTools::FindEnumValueName(
            this: typeInfoTools,
            enumTypeName: "idSpringCamera::state_t",
            value: this->followState);
    idPlayer::debugHUDPrintf(this: player, fmt: "follow state: %s", v14);
    v15 = idTypeInfoTools::FindEnumValueName(
            this: typeInfoTools,
            enumTypeName: "idSpringCamera::blendMode_t",
            value: this->followBlendMode);
    idPlayer::debugHUDPrintf(this: player, fmt: "follow blend mode: %s", v15);
    idPlayer::debugHUDPrintf(this: player, fmt: "followBlendVal: %0.2f", this->followBlendSpring.p1.x);
    idPlayer::debugHUDPrintf(
      this: player,
      fmt: "view vel: (%0.2f, %0.2f, %0.2f)",
      this->viewVelocity.x,
      this->viewVelocity.y,
      this->viewVelocity.z);
  }
  return 1;
}


// ========================================================================
// ??0idSpringCamera@@QAA@XZ
// EA  : 0x82CC7FA0
// RVA : 0x00CC7FA0
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

idSpringCamera *__fastcall idSpringCamera::idSpringCamera(idSpringCamera *this)
{
  idEntity::idEntity(this);
  this->activator.spawnId.value = 0x1FFF;
  this->__vftable = (idSpringCamera_vtbl *)&idSpringCamera::`vftable';
  this->followBlendSpring.hasPMin = false;
  this->followBlendSpring.restLength = 0.0;
  this->followBlendSpring.hasPMax = false;
  this->followBlendSpring.k = 1.0;
  this->followBlendSpring.m = 1.0;
  this->followBlendSpring.p0.x = 0.0;
  this->followBlendSpring.p1.x = 0.0;
  this->followBlendSpring.vel.x = 0.0;
  this->followBlendSpring.maxSpeed = 0.0;
  this->followBlendSpring.pMin.x = 0.0;
  this->followBlendSpring.pMax.x = 0.0;
  this->followBlendSpring.c = 2.0;
  this->lookBlendSpring.hasPMin = false;
  this->lookBlendSpring.restLength = 0.0;
  this->lookBlendSpring.hasPMax = false;
  this->lookBlendSpring.k = 1.0;
  this->lookBlendSpring.m = 1.0;
  this->lookBlendSpring.c = 2.0;
  this->lookBlendSpring.p0.x = 0.0;
  this->lookBlendSpring.p1.x = 0.0;
  this->lookBlendSpring.vel.x = 0.0;
  this->lookBlendSpring.maxSpeed = 0.0;
  this->lookBlendSpring.pMin.x = 0.0;
  this->lookBlendSpring.pMax.x = 0.0;
  this->springFollowPos.restLength = 0.0;
  this->springFollowPos.k = 1.0;
  this->springFollowPos.m = 1.0;
  this->springFollowPos.c = 2.0;
  this->springFollowPos.p0.z = 0.0;
  this->springFollowPos.p0.y = 0.0;
  this->springFollowPos.p0.x = 0.0;
  this->springFollowPos.p1.z = 0.0;
  this->springFollowPos.p1.y = 0.0;
  this->springFollowPos.p1.x = 0.0;
  this->springFollowPos.vel.z = 0.0;
  this->springFollowPos.vel.y = 0.0;
  this->springFollowPos.vel.x = 0.0;
  this->springFollowPos.maxSpeed = 0.0;
  this->springFollowPos.pMin.z = 0.0;
  this->springFollowPos.pMin.y = 0.0;
  this->springFollowPos.pMin.x = 0.0;
  this->springFollowPos.hasPMin = false;
  this->springFollowPos.pMax.z = 0.0;
  this->springFollowPos.pMax.y = 0.0;
  this->springFollowPos.pMax.x = 0.0;
  this->springFollowPos.hasPMax = false;
  this->springLookFwdDir.restLength = 0.0;
  this->springLookFwdDir.k = 1.0;
  this->springLookFwdDir.m = 1.0;
  this->springLookFwdDir.c = 2.0;
  this->springLookFwdDir.p0.z = 0.0;
  this->springLookFwdDir.p0.y = 0.0;
  this->springLookFwdDir.p0.x = 0.0;
  this->springLookFwdDir.p1.z = 0.0;
  this->springLookFwdDir.p1.y = 0.0;
  this->springLookFwdDir.p1.x = 0.0;
  this->springLookFwdDir.vel.z = 0.0;
  this->springLookFwdDir.vel.y = 0.0;
  this->springLookFwdDir.vel.x = 0.0;
  this->springLookFwdDir.maxSpeed = 0.0;
  this->springLookFwdDir.pMin.z = 0.0;
  this->springLookFwdDir.pMin.y = 0.0;
  this->springLookFwdDir.pMin.x = 0.0;
  this->springLookFwdDir.hasPMin = false;
  this->springLookFwdDir.pMax.z = 0.0;
  this->springLookFwdDir.pMax.y = 0.0;
  this->springLookFwdDir.pMax.x = 0.0;
  this->springLookFwdDir.hasPMax = false;
  this->springLookUpDir.restLength = 0.0;
  this->springLookUpDir.k = 1.0;
  this->springLookUpDir.m = 1.0;
  this->springLookUpDir.c = 2.0;
  this->springLookUpDir.p0.z = 0.0;
  this->springLookUpDir.p0.y = 0.0;
  this->springLookUpDir.p0.x = 0.0;
  this->springLookUpDir.p1.z = 0.0;
  this->springLookUpDir.p1.y = 0.0;
  this->springLookUpDir.p1.x = 0.0;
  this->springLookUpDir.vel.z = 0.0;
  this->springLookUpDir.vel.y = 0.0;
  this->springLookUpDir.vel.x = 0.0;
  this->springLookUpDir.maxSpeed = 0.0;
  this->springLookUpDir.pMin.z = 0.0;
  this->springLookUpDir.pMin.y = 0.0;
  this->springLookUpDir.pMin.x = 0.0;
  this->springLookUpDir.hasPMin = false;
  this->springLookUpDir.pMax.z = 0.0;
  this->springLookUpDir.pMax.y = 0.0;
  this->springLookUpDir.pMax.x = 0.0;
  this->springLookUpDir.hasPMax = false;
  this->springFOV.restLength = 0.0;
  this->springFOV.hasPMin = false;
  this->springFOV.k = 1.0;
  this->springFOV.hasPMax = false;
  this->springFOV.m = 1.0;
  this->springFOV.c = 2.0;
  this->springFOV.p0.x = 0.0;
  this->springFOV.p1.x = 0.0;
  this->springFOV.vel.x = 0.0;
  this->springFOV.maxSpeed = 0.0;
  this->springFOV.pMin.x = 0.0;
  this->springFOV.pMax.x = 0.0;
  this->springAutoCenter.restLength = 0.0;
  this->springAutoCenter.k = 1.0;
  this->springAutoCenter.m = 1.0;
  this->springAutoCenter.c = 2.0;
  this->springAutoCenter.p0.z = 0.0;
  this->springAutoCenter.p0.y = 0.0;
  this->springAutoCenter.p0.x = 0.0;
  this->springAutoCenter.p1.z = 0.0;
  this->springAutoCenter.p1.y = 0.0;
  this->springAutoCenter.p1.x = 0.0;
  this->springAutoCenter.vel.z = 0.0;
  this->springAutoCenter.vel.y = 0.0;
  this->springAutoCenter.vel.x = 0.0;
  this->springAutoCenter.maxSpeed = 0.0;
  this->springAutoCenter.pMin.z = 0.0;
  this->springAutoCenter.pMin.y = 0.0;
  this->springAutoCenter.pMin.x = 0.0;
  this->springAutoCenter.hasPMin = false;
  this->springAutoCenter.pMax.z = 0.0;
  this->springAutoCenter.pMax.y = 0.0;
  this->springAutoCenter.pMax.x = 0.0;
  this->springAutoCenter.hasPMax = false;
  this->followEntity.spawnId.value = 0x1FFF;
  this->followAnimator = nullptr;
  this->followJointIndex = NULL_JOINT_INDEX;
  this->lookEntity.spawnId.value = 0x1FFF;
  this->lookAnimator = nullptr;
  this->lookJointIndex = NULL_JOINT_INDEX;
  this->lookSkeleton = nullptr;
  this->followDuration = DURATION_NEVER;
  this->lookDuration = DURATION_NEVER;
  this->lookMode = LOOK_NONE;
  this->lookBlendMode = BLEND_SMOOTH;
  this->followBlendMode = BLEND_SMOOTH;
  this->fovUserChannel.value = -1;
  this->lastUpdateFrame = -1;
  this->followState = STATE_INACTIVE;
  this->lookState = STATE_INACTIVE;
  this->state = STATE_INACTIVE;
  this->activatorParent.spawnId.value = 0x1FFF;
  this->constraintConeDegs = 0.0;
  this->calculateViewInDraw = false;
  this->manualUpdate = false;
  this->calculatedView = false;
  this->calculatedViewOrigin = false;
  this->usesUserChannelFov = false;
  this->resetManualUpdate = false;
  this->getPlayerLookFromView = false;
  this->forceCalculateViewStage = STAGE_DEFAULT;
  this->inhibitControl = false;
  this->followBlendSpring.restLength = 0.0;
  this->followBlendSpring.k = 1.0;
  this->followBlendSpring.hasPMin = false;
  this->followBlendSpring.m = 1.0;
  this->followBlendSpring.hasPMax = false;
  this->followBlendSpring.c = 2.0;
  this->followBlendSpring.p0.x = 0.0;
  this->followBlendSpring.p1.x = 0.0;
  this->followBlendSpring.vel.x = 0.0;
  this->followBlendSpring.maxSpeed = 0.0;
  this->followBlendSpring.pMin.x = 0.0;
  this->followBlendSpring.pMax.x = 0.0;
  this->lookBlendSpring.hasPMin = false;
  this->lookBlendSpring.restLength = 0.0;
  this->lookBlendSpring.hasPMax = false;
  this->lookBlendSpring.k = 1.0;
  this->lookBlendSpring.m = 1.0;
  this->lookBlendSpring.c = 2.0;
  this->lookBlendSpring.p0.x = 0.0;
  this->lookBlendSpring.p1.x = 0.0;
  this->lookBlendSpring.vel.x = 0.0;
  this->lookBlendSpring.maxSpeed = 0.0;
  this->lookBlendSpring.pMin.x = 0.0;
  this->lookBlendSpring.pMax.x = 0.0;
  this->springFollowPos.restLength = 0.0;
  this->springFollowPos.k = 1.0;
  this->springFollowPos.m = 1.0;
  this->springFollowPos.c = 2.0;
  this->springFollowPos.p0.z = 0.0;
  this->springFollowPos.p0.y = 0.0;
  this->springFollowPos.p0.x = 0.0;
  this->springFollowPos.p1.z = 0.0;
  this->springFollowPos.p1.y = 0.0;
  this->springFollowPos.p1.x = 0.0;
  this->springFollowPos.vel.z = 0.0;
  this->springFollowPos.vel.y = 0.0;
  this->springFollowPos.vel.x = 0.0;
  this->springFollowPos.maxSpeed = 0.0;
  this->springFollowPos.pMin.z = 0.0;
  this->springFollowPos.pMin.y = 0.0;
  this->springFollowPos.pMin.x = 0.0;
  this->springFollowPos.hasPMin = false;
  this->springFollowPos.pMax.z = 0.0;
  this->springFollowPos.pMax.y = 0.0;
  this->springFollowPos.pMax.x = 0.0;
  this->springFollowPos.hasPMax = false;
  this->springLookFwdDir.restLength = 0.0;
  this->springLookFwdDir.k = 1.0;
  this->springLookFwdDir.m = 1.0;
  this->springLookFwdDir.c = 2.0;
  this->springLookFwdDir.p0.z = 0.0;
  this->springLookFwdDir.p0.y = 0.0;
  this->springLookFwdDir.p0.x = 0.0;
  this->springLookFwdDir.p1.z = 0.0;
  this->springLookFwdDir.p1.y = 0.0;
  this->springLookFwdDir.p1.x = 0.0;
  this->springLookFwdDir.vel.z = 0.0;
  this->springLookFwdDir.vel.y = 0.0;
  this->springLookFwdDir.vel.x = 0.0;
  this->springLookFwdDir.maxSpeed = 0.0;
  this->springLookFwdDir.pMin.z = 0.0;
  this->springLookFwdDir.pMin.y = 0.0;
  this->springLookFwdDir.pMin.x = 0.0;
  this->springLookFwdDir.hasPMin = false;
  this->springLookFwdDir.pMax.z = 0.0;
  this->springLookFwdDir.pMax.y = 0.0;
  this->springLookFwdDir.pMax.x = 0.0;
  this->springLookFwdDir.hasPMax = false;
  this->springLookUpDir.restLength = 0.0;
  this->springLookUpDir.k = 1.0;
  this->springLookUpDir.m = 1.0;
  this->springLookUpDir.c = 2.0;
  this->springLookUpDir.p0.z = 0.0;
  this->springLookUpDir.p0.y = 0.0;
  this->springLookUpDir.p0.x = 0.0;
  this->springLookUpDir.p1.z = 0.0;
  this->springLookUpDir.p1.y = 0.0;
  this->springLookUpDir.p1.x = 0.0;
  this->springLookUpDir.vel.z = 0.0;
  this->springLookUpDir.vel.y = 0.0;
  this->springLookUpDir.vel.x = 0.0;
  this->springLookUpDir.maxSpeed = 0.0;
  this->springLookUpDir.pMin.z = 0.0;
  this->springLookUpDir.pMin.y = 0.0;
  this->springLookUpDir.pMin.x = 0.0;
  this->springLookUpDir.hasPMin = false;
  this->springLookUpDir.pMax.z = 0.0;
  this->springLookUpDir.pMax.y = 0.0;
  this->springLookUpDir.pMax.x = 0.0;
  this->springLookUpDir.hasPMax = false;
  this->springFOV.restLength = 0.0;
  this->springFOV.hasPMin = false;
  this->springFOV.k = 1.0;
  this->springFOV.hasPMax = false;
  this->springFOV.m = 1.0;
  this->springFOV.c = 2.0;
  this->springFOV.p0.x = 0.0;
  this->springFOV.p1.x = 0.0;
  this->springFOV.vel.x = 0.0;
  this->springFOV.maxSpeed = 0.0;
  this->springFOV.pMin.x = 0.0;
  this->springFOV.pMax.x = 0.0;
  this->viewOrigin = vec3_origin;
  this->viewAxis = mat3_identity;
  this->viewFov = 0.0;
  this->viewVelocity = vec3_origin;
  this->viewTimestamp = 0;
  this->fromViewOrigin = vec3_origin;
  this->fromViewAxis = mat3_identity;
  this->activatorParent.spawnId.value = 0x1FFF;
  this->activatorParentPos = vec3_origin;
  return this;
}


// ========================================================================
// ?Spawn@idSpringCamera@@QAAXXZ
// EA  : 0x82CC8618
// RVA : 0x00CC8618
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::Spawn(idSpringCamera *this)
{
  this->followBlendSpring.hasPMin = false;
  this->followBlendSpring.restLength = 0.0;
  this->followBlendSpring.hasPMax = false;
  this->followBlendSpring.p0.x = 0.0;
  this->followBlendSpring.p1.x = 0.0;
  this->followBlendSpring.vel.x = 0.0;
  this->followBlendSpring.maxSpeed = 0.0;
  this->followBlendSpring.pMin.x = 0.0;
  this->followBlendSpring.pMax.x = 0.0;
  this->followBlendSpring.k = 1.0;
  this->followBlendSpring.m = 1.0;
  this->followBlendSpring.c = 2.0;
  this->lookBlendSpring.hasPMin = false;
  this->lookBlendSpring.restLength = 0.0;
  this->lookBlendSpring.hasPMax = false;
  this->lookBlendSpring.k = 1.0;
  this->lookBlendSpring.m = 1.0;
  this->lookBlendSpring.c = 2.0;
  this->lookBlendSpring.p0.x = 0.0;
  this->lookBlendSpring.p1.x = 0.0;
  this->lookBlendSpring.vel.x = 0.0;
  this->lookBlendSpring.maxSpeed = 0.0;
  this->lookBlendSpring.pMin.x = 0.0;
  this->lookBlendSpring.pMax.x = 0.0;
  this->springFollowPos.restLength = 0.0;
  this->springFollowPos.k = 1.0;
  this->springFollowPos.m = 1.0;
  this->springFollowPos.c = 2.0;
  this->springFollowPos.p0.z = 0.0;
  this->springFollowPos.p0.y = 0.0;
  this->springFollowPos.p0.x = 0.0;
  this->springFollowPos.p1.z = 0.0;
  this->springFollowPos.p1.y = 0.0;
  this->springFollowPos.p1.x = 0.0;
  this->springFollowPos.vel.z = 0.0;
  this->springFollowPos.vel.y = 0.0;
  this->springFollowPos.vel.x = 0.0;
  this->springFollowPos.maxSpeed = 0.0;
  this->springFollowPos.pMin.z = 0.0;
  this->springFollowPos.pMin.y = 0.0;
  this->springFollowPos.pMin.x = 0.0;
  this->springFollowPos.hasPMin = false;
  this->springFollowPos.pMax.z = 0.0;
  this->springFollowPos.pMax.y = 0.0;
  this->springFollowPos.pMax.x = 0.0;
  this->springFollowPos.hasPMax = false;
  this->springLookFwdDir.restLength = 0.0;
  this->springLookFwdDir.k = 1.0;
  this->springLookFwdDir.m = 1.0;
  this->springLookFwdDir.c = 2.0;
  this->springLookFwdDir.p0.z = 0.0;
  this->springLookFwdDir.p0.y = 0.0;
  this->springLookFwdDir.p0.x = 0.0;
  this->springLookFwdDir.p1.z = 0.0;
  this->springLookFwdDir.p1.y = 0.0;
  this->springLookFwdDir.p1.x = 0.0;
  this->springLookFwdDir.vel.z = 0.0;
  this->springLookFwdDir.vel.y = 0.0;
  this->springLookFwdDir.vel.x = 0.0;
  this->springLookFwdDir.maxSpeed = 0.0;
  this->springLookFwdDir.pMin.z = 0.0;
  this->springLookFwdDir.pMin.y = 0.0;
  this->springLookFwdDir.pMin.x = 0.0;
  this->springLookFwdDir.hasPMin = false;
  this->springLookFwdDir.pMax.z = 0.0;
  this->springLookFwdDir.pMax.y = 0.0;
  this->springLookFwdDir.pMax.x = 0.0;
  this->springLookFwdDir.hasPMax = false;
  this->springLookUpDir.restLength = 0.0;
  this->springLookUpDir.k = 1.0;
  this->springLookUpDir.m = 1.0;
  this->springLookUpDir.c = 2.0;
  this->springLookUpDir.p0.z = 0.0;
  this->springLookUpDir.p0.y = 0.0;
  this->springLookUpDir.p0.x = 0.0;
  this->springLookUpDir.p1.z = 0.0;
  this->springLookUpDir.p1.y = 0.0;
  this->springLookUpDir.p1.x = 0.0;
  this->springLookUpDir.vel.z = 0.0;
  this->springLookUpDir.vel.y = 0.0;
  this->springLookUpDir.vel.x = 0.0;
  this->springLookUpDir.maxSpeed = 0.0;
  this->springLookUpDir.pMin.z = 0.0;
  this->springLookUpDir.pMin.y = 0.0;
  this->springLookUpDir.pMin.x = 0.0;
  this->springLookUpDir.hasPMin = false;
  this->springLookUpDir.pMax.z = 0.0;
  this->springLookUpDir.pMax.y = 0.0;
  this->springLookUpDir.pMax.x = 0.0;
  this->springLookUpDir.hasPMax = false;
  this->springFOV.restLength = 0.0;
  this->springFOV.hasPMin = false;
  this->springFOV.k = 1.0;
  this->springFOV.hasPMax = false;
  this->springFOV.m = 1.0;
  this->springFOV.c = 2.0;
  this->springFOV.p0.x = 0.0;
  this->springFOV.p1.x = 0.0;
  this->springFOV.vel.x = 0.0;
  this->springFOV.maxSpeed = 0.0;
  this->springFOV.pMin.x = 0.0;
  this->springFOV.pMax.x = 0.0;
  this->springAutoCenter.restLength = 0.0;
  this->springAutoCenter.k = 1.0;
  this->springAutoCenter.m = 1.0;
  this->springAutoCenter.c = 2.0;
  this->springAutoCenter.p0.z = 0.0;
  this->springAutoCenter.p0.y = 0.0;
  this->springAutoCenter.p0.x = 0.0;
  this->springAutoCenter.p1.z = 0.0;
  this->springAutoCenter.p1.y = 0.0;
  this->springAutoCenter.p1.x = 0.0;
  this->springAutoCenter.vel.z = 0.0;
  this->springAutoCenter.vel.y = 0.0;
  this->springAutoCenter.vel.x = 0.0;
  this->springAutoCenter.maxSpeed = 0.0;
  this->springAutoCenter.pMin.z = 0.0;
  this->springAutoCenter.pMin.y = 0.0;
  this->springAutoCenter.pMin.x = 0.0;
  this->springAutoCenter.hasPMin = false;
  this->springAutoCenter.pMax.z = 0.0;
  this->springAutoCenter.pMax.y = 0.0;
  this->springAutoCenter.pMax.x = 0.0;
  this->springAutoCenter.hasPMax = false;
  this->followEntity.spawnId.value = 0x1FFF;
  this->followAnimator = nullptr;
  this->followJointIndex = NULL_JOINT_INDEX;
  this->lookEntity.spawnId.value = 0x1FFF;
  this->lookAnimator = nullptr;
  this->lookSkeleton = nullptr;
  this->lookJointIndex = NULL_JOINT_INDEX;
}


// ========================================================================
// ?Zero@idSpringCamera@@QAAXXZ
// EA  : 0x82CC8868
// RVA : 0x00CC8868
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::Zero(idSpringCamera *this)
{
  this->followBlendSpring.p0.x = 0.0;
  this->followBlendSpring.p1.x = 0.0;
  this->followBlendSpring.vel.x = 0.0;
  this->lookBlendSpring.p0.x = 0.0;
  this->lookBlendSpring.p1.x = 0.0;
  this->lookBlendSpring.vel.x = 0.0;
  this->springFollowPos.p0.z = 0.0;
  this->springFollowPos.p0.y = 0.0;
  this->springFollowPos.p0.x = 0.0;
  this->springFollowPos.p1.z = 0.0;
  this->springFollowPos.p1.y = 0.0;
  this->springFollowPos.p1.x = 0.0;
  this->springFollowPos.vel.z = 0.0;
  this->springFollowPos.vel.y = 0.0;
  this->springFollowPos.vel.x = 0.0;
  this->springLookFwdDir.p0.z = 0.0;
  this->springLookFwdDir.p0.y = 0.0;
  this->springLookFwdDir.p0.x = 0.0;
  this->springLookFwdDir.p1.z = 0.0;
  this->springLookFwdDir.p1.y = 0.0;
  this->springLookFwdDir.p1.x = 0.0;
  this->springLookFwdDir.vel.z = 0.0;
  this->springLookFwdDir.vel.y = 0.0;
  this->springLookFwdDir.vel.x = 0.0;
  this->springLookUpDir.p0.z = 0.0;
  this->springLookUpDir.p0.y = 0.0;
  this->springLookUpDir.p0.x = 0.0;
  this->springLookUpDir.p1.z = 0.0;
  this->springLookUpDir.p1.y = 0.0;
  this->springLookUpDir.p1.x = 0.0;
  this->springLookUpDir.vel.z = 0.0;
  this->springLookUpDir.vel.y = 0.0;
  this->springLookUpDir.vel.x = 0.0;
  this->springFOV.p0.x = 0.0;
  this->springFOV.p1.x = 0.0;
  this->springFOV.vel.x = 0.0;
  this->springAutoCenter.p0.z = 0.0;
  this->springAutoCenter.p0.y = 0.0;
  this->springAutoCenter.p0.x = 0.0;
  this->springAutoCenter.p1.z = 0.0;
  this->springAutoCenter.p1.y = 0.0;
  this->springAutoCenter.p1.x = 0.0;
  this->springAutoCenter.vel.z = 0.0;
  this->springAutoCenter.vel.y = 0.0;
  this->springAutoCenter.vel.x = 0.0;
  this->followEntity.spawnId.value = 0x1FFF;
  this->followAnimator = nullptr;
  this->followJointIndex = NULL_JOINT_INDEX;
  this->lookEntity.spawnId.value = 0x1FFF;
  this->lookAnimator = nullptr;
  this->lookSkeleton = nullptr;
  this->lookJointIndex = NULL_JOINT_INDEX;
}


// ========================================================================
// ?ClearFollowTarget@idSpringCamera@@QAAXXZ
// EA  : 0x82CC8968
// RVA : 0x00CC8968
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::ClearFollowTarget(idSpringCamera *this)
{
  __int16 value; // r10
  int v2; // r3

  this->followEntity.spawnId.value = 0x1FFF;
  this->followAnimator = nullptr;
  value = NULL_JOINT_INDEX.value;
  this->followDuration = DURATION_NEVER;
  this->followState = STATE_INACTIVE;
  this->followJointIndex.value = value;
  if ( springCam_DebugTraceStates.valueInteger != 0 )
  {
    v2 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "(%d)%s - clearing follow target\n", v2, "idSpringCamera::ClearFollowTarget");
  }
}


// ========================================================================
// ?ClearLookTarget@idSpringCamera@@QAAXXZ
// EA  : 0x82CC89F0
// RVA : 0x00CC89F0
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::ClearLookTarget(idSpringCamera *this)
{
  int v2; // r3

  this->lookEntity.spawnId.value = 0x1FFF;
  this->lookAnimator = nullptr;
  this->lookSkeleton = nullptr;
  this->lookJointIndex = NULL_JOINT_INDEX;
  idSpringCamera::SetLookMode(this, mode: LOOK_NONE);
  this->lookDuration = DURATION_NEVER;
  this->lookState = STATE_INACTIVE;
  this->usesUserChannelFov = false;
  if ( springCam_DebugTraceStates.valueInteger != 0 )
  {
    v2 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "(%d)%s - clearing look target\n", v2, "idSpringCamera::ClearLookTarget");
  }
}


// ========================================================================
// ?SetBlendDurationMS@idSpringCamera@@QAAXH@Z
// EA  : 0x82CC8AA0
// RVA : 0x00CC8AA0
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetBlendDurationMS(idSpringCamera *this, int blendDurationMS, long double a3)
{
  __int64 v4; // r11
  double valueFloat; // fp31
  double v6; // fp31
  long double v7; // fp2

  HIDWORD(v4) = &springCam_ForceBlendDurationMS;
  if ( springCam_ForceBlendDurationMS.valueInteger >= 0 )
    blendDurationMS = springCam_ForceBlendDurationMS.valueInteger;
  if ( blendDurationMS > 0 )
  {
    LODWORD(v4) = blendDurationMS;
    *(_QWORD *)&a3 = 0x4059000000000000LL;
    v6 = (float)((float)v4 * (float)0.001);
    v7 = log(x: a3);
    valueFloat = (float)((float)((float)*(double *)&v7 / (float)v6) * (float)((float)*(double *)&v7 / (float)v6));
  }
  else
  {
    valueFloat = springCam_BlendSpringK.valueFloat;
  }
  idSpring<idVec1>::SetConstants(this: &this->followBlendSpring, _k: valueFloat, _c: -1.0);
  idSpring<idVec1>::SetConstants(this: &this->lookBlendSpring, _k: valueFloat, _c: -1.0);
}


// ========================================================================
// ?SetFromData@idSpringCamera@@IAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82CC8B68
// RVA : 0x00CC8B68
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetFromData(idSpringCamera *this, const idVec3 *fromOrigin, const idMat3 *fromAxis)
{
  idGameLocal *v4; // r10
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r3
  idEntity *BindMaster; // r3
  idEntity *v9; // r30
  idRenderModel *RenderModelFromPresentable; // r3
  float *p_x; // r11
  const char *data; // r30
  int v13; // r3
  double z; // fp31
  double y; // fp30
  double x; // fp29
  int v17; // r3
  int v18; // r3

  this->fromViewOrigin.x = fromOrigin->x;
  this->fromViewOrigin.y = fromOrigin->y;
  v4 = gameLocal;
  this->fromViewOrigin.z = fromOrigin->z;
  this->fromViewAxis = *fromAxis;
  value = this->activator.spawnId.value;
  if ( v4->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = v4->entities.ptr[value & 0x1FFF]) != nullptr
    && (v7 = idEntity::CastTo(c: v6)) != nullptr
    && (BindMaster = idEntity::GetBindMaster(this: v7), v9 = BindMaster, BindMaster != nullptr) )
  {
    this->activatorParent.spawnId.value = (gameLocal->spawnIds.ptr[BindMaster->entityNumber] << 13)
                                        | BindMaster->entityNumber;
    RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: BindMaster);
    p_x = &RenderModelFromPresentable->deferredOrigin.x;
    if ( !RenderModelFromPresentable->useDeferredPosition )
      p_x = &RenderModelFromPresentable->g.origin.x;
    this->activatorParentPos.x = *p_x;
    this->activatorParentPos.y = p_x[1];
    this->activatorParentPos.z = p_x[2];
    if ( springCam_DebugParentInfo.valueInteger != 0 )
    {
      data = v9->name.data;
      v13 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(fmt: "(%d)%s - setting parent to <%s>\n", v13, "idSpringCamera::SetFromData", data);
      z = this->activatorParentPos.z;
      y = this->activatorParentPos.y;
      x = this->activatorParentPos.x;
      v17 = ((int (*)(void))gameLocal->GetGameFrame)();
      idLib::Printf(fmt: "(%d)%s - parent pos = (%0.2f, %0.2f, %0.2f)\n", v17, "idSpringCamera::SetFromData", x, y, z);
    }
  }
  else
  {
    this->activatorParent.spawnId.value = 0x1FFF;
    this->activatorParentPos = vec3_origin;
    if ( springCam_DebugParentInfo.valueInteger != 0 )
    {
      v18 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(fmt: "(%d)%s - setting parent to NULL\n", v18, "idSpringCamera::SetFromData");
    }
  }
}


// ========================================================================
// ?UpdateFromData@idSpringCamera@@IAAXXZ
// EA  : 0x82CC8DD0
// RVA : 0x00CC8DD0
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::UpdateFromData(idSpringCamera *this)
{
  idGameLocal *v2; // r11
  idEntity *v3; // r3
  idEntity *v4; // r3
  idEntity *BindMaster; // r3
  idEntity *v6; // r29
  idRenderModel *RenderModelFromPresentable; // r3
  int value; // r9
  idGameLocal *v9; // r11
  idRenderModel *v10; // r30
  idEntity *v11; // r3
  idEntity *v12; // r3
  idVec3 *p_deferredOrigin; // r10
  double x; // fp11
  float y; // r11
  double v16; // fp8
  double v17; // fp4
  double v18; // fp3
  double v19; // fp29
  double v20; // fp30
  int v21; // r3
  float *p_x; // r11
  const char *data; // r30
  int v24; // r3
  double v25; // fp31
  double v26; // fp30
  double v27; // fp29
  int v28; // r3
  int v29; // r9
  idEntity *v30; // r3
  int v31; // r3
  float v32; // [sp+50h] [-50h]
  float z; // [sp+58h] [-48h]

  v2 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->activator.spawnId.value & 0x1FFF] == this->activator.spawnId.value >> 13 )
  {
    v3 = gameLocal->entities.ptr[this->activator.spawnId.value & 0x1FFF];
    if ( v3 != nullptr )
    {
      v4 = idEntity::CastTo(c: v3);
      if ( v4 != nullptr )
      {
        BindMaster = idEntity::GetBindMaster(this: v4);
        v6 = BindMaster;
        if ( BindMaster != nullptr )
        {
          RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: BindMaster);
          value = this->activatorParent.spawnId.value;
          v9 = gameLocal;
          v10 = RenderModelFromPresentable;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v11 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v12 = idEntity::CastTo(c: v11);
            v9 = gameLocal;
          }
          else
          {
            v12 = nullptr;
          }
          if ( v6 == v12 )
          {
            if ( v10 != nullptr )
            {
              if ( v10->useDeferredPosition )
                p_deferredOrigin = &v10->deferredOrigin;
              else
                p_deferredOrigin = &v10->g.origin;
            }
            else
            {
              p_deferredOrigin = &vec3_origin;
            }
            x = this->activatorParentPos.x;
            y = p_deferredOrigin->y;
            v16 = this->fromViewOrigin.x;
            z = p_deferredOrigin->z;
            v32 = p_deferredOrigin->x;
            v17 = this->fromViewOrigin.z;
            v18 = (float)(z - this->activatorParentPos.z);
            this->fromViewOrigin.y = this->fromViewOrigin.y + (float)(y - this->activatorParentPos.y);
            this->fromViewOrigin.x = (float)v16 + (float)(v32 - (float)x);
            this->fromViewOrigin.z = (float)v17 + (float)v18;
            this->activatorParentPos.x = v32;
            this->activatorParentPos.y = y;
            this->activatorParentPos.z = z;
            if ( springCam_DebugParentInfo.valueInteger != 0 )
            {
              v19 = this->activatorParentPos.x;
              v20 = y;
              v21 = gameLocal->GetGameFrame(this: gameLocal);
              idLib::Printf(fmt: (const char *)HIDWORD(v20), v21, v19, z, v19, v20, z);
            }
          }
          else
          {
            this->activatorParent.spawnId.value = (v9->spawnIds.ptr[v6->entityNumber] << 13) | v6->entityNumber;
            if ( v10 != nullptr )
            {
              p_x = &v10->deferredOrigin.x;
              if ( !v10->useDeferredPosition )
                p_x = &v10->g.origin.x;
              this->activatorParentPos.x = *p_x;
              this->activatorParentPos.y = p_x[1];
              this->activatorParentPos.z = p_x[2];
            }
            if ( springCam_DebugParentInfo.valueInteger != 0 )
            {
              data = v6->name.data;
              v24 = gameLocal->GetGameFrame(this: gameLocal);
              idLib::Printf(fmt: "(%d)%s - setting parent to <%s>\n", v24, "idSpringCamera::UpdateFromData", data);
              v25 = this->activatorParentPos.z;
              v26 = this->activatorParentPos.y;
              v27 = this->activatorParentPos.x;
              v28 = ((int (*)(void))gameLocal->GetGameFrame)();
              idLib::Printf(
                fmt: "(%d)%s - parent pos = (%0.2f, %0.2f, %0.2f)\n",
                v28,
                "idSpringCamera::UpdateFromData",
                v27,
                v26,
                v25);
            }
          }
          return;
        }
      }
      v2 = gameLocal;
    }
  }
  v29 = this->activatorParent.spawnId.value;
  if ( v2->spawnIds.ptr[v29 & 0x1FFF] == v29 >> 13 )
  {
    v30 = v2->entities.ptr[v29 & 0x1FFF];
    if ( v30 != nullptr && idEntity::CastTo(c: v30) != nullptr )
    {
      this->activatorParent.spawnId.value = 0x1FFF;
      if ( springCam_DebugParentInfo.valueInteger != 0 )
      {
        v31 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(fmt: "(%d)%s - setting parent to NULL\n", v31, "idSpringCamera::UpdateFromData");
      }
    }
  }
}


// ========================================================================
// ?InitSprings@idSpringCamera@@QAAXMMMMMMMMMM@Z
// EA  : 0x82CC9178
// RVA : 0x00CC9178
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::InitSprings(
        idSpringCamera *this,
        double posK,
        double posC,
        double fwdPosK,
        double fwdPosC,
        double upPosK,
        double upPosC,
        double fovK,
        double fovC,
        float autoCenterK,
        float autoCenterC)
{
  double v11; // fp10
  double v12; // fp9
  double v22; // fp22
  double v23; // fp21

  v22 = v12;
  v23 = v11;
  idSpring<idVec1>::SetConstants(this: &this->followBlendSpring, _k: springCam_BlendSpringK.valueFloat, _c: -1.0);
  idSpring<idVec1>::SetConstants(this: &this->lookBlendSpring, _k: springCam_BlendSpringK.valueFloat, _c: -1.0);
  idSpring<idVec3>::SetConstants(this: &this->springFollowPos, _k: posK, _c: posC);
  idSpring<idVec3>::SetConstants(this: &this->springLookFwdDir, _k: fwdPosK, _c: fwdPosC);
  idSpring<idVec3>::SetConstants(this: &this->springLookUpDir, _k: upPosK, _c: upPosC);
  idSpring<idVec1>::SetConstants(this: &this->springFOV, _k: fovK, _c: fovC);
  idSpring<idVec3>::SetConstants(this: &this->springAutoCenter, _k: v22, _c: v23);
}


// ========================================================================
// ?CalculateView@idSpringCamera@@QAAXPAVidPlayer@@@Z
// EA  : 0x82CC9260
// RVA : 0x00CC9260
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::CalculateView(idSpringCamera *this, idPlayer *player)
{
  if ( idSpringCamera::GetCalculateViewStage(this, player) == STAGE_DEFAULT )
    idSpringCamera::InternalCalculateView(this, player);
}


// ========================================================================
// ?SetFollowTarget@idSpringCamera@@QAAXPAVidEntity@@PAVidTreeAnimator@@V?$idIndex@FW4invalidJointIndex_t@@@@W4duration_t@1@@Z
// EA  : 0x82CC92B0
// RVA : 0x00CC92B0
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetFollowTarget(
        idSpringCamera *this,
        idEntity *entity,
        idTreeAnimator *ta,
        idIndex<short,enum invalidJointIndex_t> *jointIndex,
        __int32 duration)
{
  __int16 v6; // r29
  const char *EnumValueName; // r30
  char *data; // r31
  int v9; // r3

  v6 = (__int16)jointIndex;
  if ( entity != nullptr )
  {
    this->followEntity.spawnId.value = (gameLocal->spawnIds.ptr[entity->entityNumber] << 13) | entity->entityNumber;
    this->followAnimator = ta;
    this->followJointIndex.value = (__int16)jointIndex;
    this->followDuration = duration;
    this->followState = STATE_ACTIVE;
    if ( springCam_DebugTraceStates.valueInteger != 0 )
    {
      EnumValueName = idTypeInfoTools::FindEnumValueName(
                        this: typeInfoTools,
                        enumTypeName: "idSpringCamera::duration_t",
                        value: duration);
      data = entity->name.data;
      v9 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s - setting follow target=%s, jointIndex=%d, follow duration=%s\n",
        v9,
        "idSpringCamera::SetFollowTarget",
        data,
        v6,
        EnumValueName);
    }
  }
  else
  {
    idSpringCamera::ClearFollowTarget(this);
  }
}


// ========================================================================
// ?SetLookTarget@idSpringCamera@@QAAXPAVidEntity@@PAVidTreeAnimator@@V?$idIndex@FW4invalidJointIndex_t@@@@W4duration_t@1@W4lookMode_t@1@@Z
// EA  : 0x82CC9390
// RVA : 0x00CC9390
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetLookTarget(
        idSpringCamera *this,
        idEntity *entity,
        idTreeAnimator *ta,
        idIndex<short,enum invalidJointIndex_t> *jointIndex,
        __int32 duration,
        idSpringCamera::lookMode_t mode)
{
  __int16 v9; // r27
  const idDeclMD6 *decl; // r11
  const idMD6Model *model; // r11
  const idMD6Skel *skeleton; // r11
  const char *EnumValueName; // r3
  idSpringCamera::lookMode_t lookMode; // r5
  const char *v16; // r31
  const char *v17; // r30
  char *data; // r29
  int v19; // r3

  v9 = (__int16)jointIndex;
  if ( mode != LOOK_NONE && entity != nullptr )
  {
    this->lookEntity.spawnId.value = (gameLocal->spawnIds.ptr[entity->entityNumber] << 13) | entity->entityNumber;
    this->lookAnimator = ta;
    this->lookJointIndex.value = (__int16)jointIndex;
    idSpringCamera::SetLookMode(this, mode);
    this->lookDuration = duration;
    this->lookState = STATE_ACTIVE;
    if ( ta != nullptr )
      decl = ta->decl;
    else
      decl = nullptr;
    if ( decl != nullptr )
      model = decl->model;
    else
      model = nullptr;
    if ( model != nullptr )
      skeleton = model->skeleton;
    else
      skeleton = nullptr;
    this->lookSkeleton = skeleton;
    if ( springCam_DebugTraceStates.valueInteger != 0 )
    {
      EnumValueName = idTypeInfoTools::FindEnumValueName(
                        this: typeInfoTools,
                        enumTypeName: "idSpringCamera::duration_t",
                        value: duration);
      lookMode = this->lookMode;
      v16 = EnumValueName;
      v17 = idTypeInfoTools::FindEnumValueName(
              this: typeInfoTools,
              enumTypeName: "idSpringCamera::lookMode_t",
              value: lookMode);
      data = entity->name.data;
      v19 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s - setting look target=%s, jointIndex=%d, look mode=%s, look duration=%s\n",
        v19,
        "idSpringCamera::SetLookTarget",
        data,
        v9,
        v17,
        v16);
    }
  }
  else
  {
    idSpringCamera::ClearLookTarget(this);
  }
}


// ========================================================================
// ?Init@idSpringCamera@@QAAXABVidVec3@@ABVidMat3@@M@Z
// EA  : 0x82CC94E8
// RVA : 0x00CC94E8
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::Init(
        idSpringCamera *this,
        const idVec3 *viewOrigin,
        const idMat3 *viewAxis,
        double fov)
{
  double x; // fp0
  int v6; // r3
  const idMat3 *v7; // r4
  float v8; // [sp+50h] [-30h]

  x = viewOrigin->x;
  this->springFollowPos.p0 = *viewOrigin;
  this->springFollowPos.p1.x = x;
  this->springFollowPos.p1.y = this->springFollowPos.p0.y;
  this->springFollowPos.p1.z = this->springFollowPos.p0.z;
  this->springFollowPos.vel.z = 0.0;
  this->springFollowPos.vel.y = 0.0;
  this->springFollowPos.vel.x = 0.0;
  v8 = fov;
  idSpringCamera::SetLookDestination(this, fwdDir: viewAxis->mat, upDir: &viewAxis->mat[2], snap: true);
  *(float *)(v6 + 1148) = v8;
  *(float *)(v6 + 1156) = 0.0;
  *(_DWORD *)(v6 + 1152) = *(_DWORD *)(v6 + 1148);
  idSpringCamera::SetFromData(this: (idSpringCamera *)v6, fromOrigin: viewOrigin, fromAxis: v7);
}


// ========================================================================
// ?InitSprings@idSpringCamera@@QAAXM@Z
// EA  : 0x82CC95A0
// RVA : 0x00CC95A0
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::InitSprings(idSpringCamera *this, double k)
{
  float v2; // [sp+8h] [-68h]
  float v3; // [sp+Ch] [-64h]

  idSpringCamera::InitSprings(
    this,
    posK: k,
    posC: -1.0,
    fwdPosK: k,
    fwdPosC: -1.0,
    upPosK: k,
    upPosC: -1.0,
    fovK: 0.0,
    fovC: 0.0,
    autoCenterK: v2,
    autoCenterC: v3);
}


// ========================================================================
// ?InitFromView@idSpringCamera@@QAAXABVidView@@@Z
// EA  : 0x82CC95F0
// RVA : 0x00CC95F0
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::InitFromView(idSpringCamera *this, idView *view)
{
  int v3; // r3
  idVec3 v4; // [sp+50h] [-50h] BYREF
  idMat3 v5; // [sp+60h] [-40h] BYREF

  idView::GetViewPos(this: view, origin: &v4, axis: &v5);
  idSpringCamera::Init(this, viewOrigin: &v4, viewAxis: &v5, fov: 0.0);
  if ( springCam_DebugTraceStates.valueInteger != 0 )
  {
    v3 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "(%d)%s - initing from view\n", v3, "idSpringCamera::InitFromView");
  }
}


// ========================================================================
// ?SetupBlend@idSpringCamera@@IAAXXZ
// EA  : 0x82CC9688
// RVA : 0x00CC9688
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetupBlend(idSpringCamera *this)
{
  idSpringCamera::state_t state; // r5
  const char *EnumValueName; // r3
  idPlayer *v4; // r3
  idPlayer *PlayerActivator; // r3
  idPlayer *v6; // r30
  idPresentable *presentable; // r3
  idPresentable *v8; // r3
  int v9; // r3
  idSpringCamera::blendMode_t followBlendMode; // r11
  idSpringCamera::blendMode_t lookBlendMode; // r11

  state = this->state;
  if ( state == STATE_BLEND_IN )
  {
    PlayerActivator = idCamera::GetPlayerActivator(this);
    v6 = PlayerActivator;
    if ( PlayerActivator != nullptr )
    {
      presentable = PlayerActivator->presentable;
      if ( presentable != nullptr && presentable->GetPlayerInterface_2(this: presentable) != nullptr )
      {
        v8 = v6->presentable;
        if ( v8 != nullptr )
          v9 = (int)v8->GetPlayerInterface_2(this: v8);
        else
          v9 = 0;
        idSpringCamera::InitFromView(this, view: (idView *)(v9 + 16224));
      }
    }
  }
  else
  {
    if ( state != STATE_REACTIVATE )
    {
      EnumValueName = idTypeInfoTools::FindEnumValueName(
                        this: typeInfoTools,
                        enumTypeName: "idSpringCamera::state_t",
                        value: state);
      idLib::Warning(fmt: "%s - unsupported state <%s>", "idSpringCamera::SetupBlend", EnumValueName);
      return;
    }
    if ( !this->calculatedView )
    {
      v4 = idCamera::GetPlayerActivator(this);
      idSpringCamera::InternalCalculateView(this, player: v4);
    }
    idSpringCamera::Init(this, viewOrigin: &this->viewOrigin, viewAxis: &this->viewAxis, fov: 0.0);
    this->followBlendSpring.p1.x = 0.0;
    this->lookBlendSpring.p1.x = 0.0;
  }
  followBlendMode = this->followBlendMode;
  if ( (unsigned int)followBlendMode <= BLEND_SNAP )
  {
    if ( (unsigned int)followBlendMode >= BLEND_SNAP_SNAP_SMOOTH )
      this->followBlendSpring.p1.x = 1.0;
    this->followBlendSpring.p0.x = 1.0;
  }
  if ( springCam_AlwaysSnap.valueInteger != 0 )
  {
    this->followBlendSpring.p0.x = 1.0;
    this->followBlendSpring.p1.x = 1.0;
  }
  lookBlendMode = this->lookBlendMode;
  if ( (unsigned int)lookBlendMode <= BLEND_SNAP )
  {
    if ( (unsigned int)lookBlendMode >= BLEND_SNAP_SNAP_SMOOTH )
      this->lookBlendSpring.p1.x = 1.0;
    this->lookBlendSpring.p0.x = 1.0;
  }
  if ( springCam_AlwaysSnap.valueInteger != 0 )
  {
    this->lookBlendSpring.p0.x = 1.0;
    this->lookBlendSpring.p1.x = 1.0;
  }
}


// ========================================================================
// ?SetFollowTarget@idSpringCamera@@QAAXPAVidEntity@@@Z
// EA  : 0x82CC9840
// RVA : 0x00CC9840
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetFollowTarget(idSpringCamera *this, idEntity *entity)
{
  idSpringCamera::SetFollowTarget(
    this,
    entity,
    ta: nullptr,
    jointIndex: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)NULL_JOINT_INDEX.value,
    duration: 1);
}


// ========================================================================
// ?SetFollowTarget@idSpringCamera@@QAAXPAVidEntity@@PAVidTreeAnimator@@PBDW4duration_t@1@@Z
// EA  : 0x82CC9858
// RVA : 0x00CC9858
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetFollowTarget(
        idSpringCamera *this,
        idEntity *entity,
        idIndex<short,enum invalidJointIndex_t> *ta,
        const char *jointName,
        __int32 duration)
{
  idIndex<short,enum invalidJointIndex_t> *value; // r6
  bool v11; // zf
  char v12; // [sp+50h] [-30h] BYREF

  v11 = jointName == nullptr;
  value = (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)NULL_JOINT_INDEX.value;
  if ( !v11 && ta != nullptr )
    value = (idIndex<short,enum invalidJointIndex_t> *)HIWORD(idTreeAnimator::GetJointIndex(
                                                                this: (idTreeAnimator *)&v12,
                                                                result: ta,
                                                                jointName)->__vftable);
  idSpringCamera::SetFollowTarget(this, entity, (idTreeAnimator *)ta, jointIndex: value, duration);
}


// ========================================================================
// ?SetLookTarget@idSpringCamera@@QAAXPAVidEntity@@@Z
// EA  : 0x82CC98C0
// RVA : 0x00CC98C0
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetLookTarget(idSpringCamera *this, idEntity *entity)
{
  idSpringCamera::SetLookTarget(
    this,
    entity,
    ta: nullptr,
    jointIndex: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)NULL_JOINT_INDEX.value,
    duration: 1,
    mode: LOOK_POSITION);
}


// ========================================================================
// ?SetLookTarget@idSpringCamera@@QAAXPAVidEntity@@PAVidTreeAnimator@@PBDW4duration_t@1@W4lookMode_t@1@@Z
// EA  : 0x82CC98D8
// RVA : 0x00CC98D8
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetLookTarget(
        idSpringCamera *this,
        idEntity *entity,
        idIndex<short,enum invalidJointIndex_t> *ta,
        const char *jointName,
        __int32 duration,
        idSpringCamera::lookMode_t mode)
{
  idIndex<short,enum invalidJointIndex_t> *value; // r11
  char v12; // [sp+50h] [-40h] BYREF

  if ( mode != LOOK_NONE && entity != nullptr )
  {
    value = (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)NULL_JOINT_INDEX.value;
    if ( jointName != nullptr && ta != nullptr )
      value = (idIndex<short,enum invalidJointIndex_t> *)HIWORD(idTreeAnimator::GetJointIndex(
                                                                  this: (idTreeAnimator *)&v12,
                                                                  result: ta,
                                                                  jointName)->__vftable);
    idSpringCamera::SetLookTarget(this, entity, (idTreeAnimator *)ta, jointIndex: value, duration, mode);
  }
  else
  {
    idSpringCamera::ClearLookTarget(this);
  }
}


// ========================================================================
// ?SetState@idSpringCamera@@IAAXW4state_t@1@@Z
// EA  : 0x82CC9968
// RVA : 0x00CC9968
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::SetState(idSpringCamera *this, __int32 state)
{
  const char *EnumValueName; // r22
  int v5; // r3
  idCamera *v6; // r3

  while ( 1 )
  {
    while ( 1 )
    {
      if ( springCam_DebugTraceStates.valueInteger != 0 )
      {
        EnumValueName = idTypeInfoTools::FindEnumValueName(
                          this: typeInfoTools,
                          enumTypeName: "idSpringCamera::state_t",
                          value: state);
        v5 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(fmt: "(%d)%s - setting state=%s\n", v5, "idSpringCamera::SetState", EnumValueName);
      }
      this->state = state;
      if ( state != 1 )
        break;
      this->calculatedViewOrigin = false;
      idSpringCamera::SetupBlend(this);
      state = 3;
    }
    if ( state != 2 )
      break;
    idSpringCamera::SetupBlend(this);
    state = 3;
  }
  if ( state == 6 )
  {
    idSpringCamera::Zero(this);
    idCamera::Deactivate(this: v6);
    idSpringCamera::SetState(this, state: STATE_INACTIVE);
    if ( this->resetManualUpdate )
    {
      this->manualUpdate = false;
      this->resetManualUpdate = false;
    }
    this->getPlayerLookFromView = false;
  }
}


// ========================================================================
// ?InternalActivate@idSpringCamera@@MAA_NPAVidEntity@@@Z
// EA  : 0x82CC9A70
// RVA : 0x00CC9A70
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

int __fastcall idSpringCamera::InternalActivate(idSpringCamera *this, idEntity *activator_)
{
  idGameLocal *v3; // r11
  idEntity *v5; // r3
  idEntity *v6; // r3
  const char *EnumValueName; // r31
  int v8; // r3
  idPlayer *PlayerActivator; // r3
  idPlayer *v11; // r31
  idPresentable *presentable; // r3
  int v13; // r3

  v3 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->activator.spawnId.value & 0x1FFF] == this->activator.spawnId.value >> 13
    && (v5 = gameLocal->entities.ptr[this->activator.spawnId.value & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
    v3 = gameLocal;
  }
  else
  {
    v6 = nullptr;
  }
  if ( v6 != activator_ )
  {
    if ( this->state != STATE_INACTIVE )
    {
      this->InternalDeactivate(this);
      v3 = gameLocal;
    }
    if ( activator_ != nullptr )
      this->activator.spawnId.value = (v3->spawnIds.ptr[activator_->entityNumber] << 13) | activator_->entityNumber;
    else
      this->activator.spawnId.value = 0x1FFF;
    if ( springCam_UpdateView.valueInteger != 0 )
    {
      PlayerActivator = idCamera::GetPlayerActivator(this);
      v11 = PlayerActivator;
      if ( PlayerActivator != nullptr )
      {
        idPlayer::SetControlCamera(this: PlayerActivator, entity: this, allowHUD: true);
        presentable = v11->presentable;
        if ( presentable != nullptr )
          v13 = (int)presentable->GetPlayerInterface_2(this: presentable);
        else
          v13 = 0;
        *(_BYTE *)(v13 + 19040) = 0;
      }
    }
    idEntity::BecomeActive(this, flags: 1);
    idSpringCamera::SetState(this, state: 1);
  }
  else if ( this->state != STATE_INACTIVE )
  {
    if ( springCam_DebugTraceStates.valueInteger != 0 )
    {
      EnumValueName = idTypeInfoTools::FindEnumValueName(
                        this: typeInfoTools,
                        enumTypeName: "idSpringCamera::state_t",
                        value: 2);
      v8 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(fmt: "(%d)%s - setting state=%s\n", v8, "idSpringCamera::SetState", EnumValueName);
    }
    this->state = STATE_REACTIVATE;
    idSpringCamera::SetupBlend(this);
    idSpringCamera::SetState(this, state: 3);
    return 0;
  }
  return 0;
}


// ========================================================================
// ?InternalDeactivate@idSpringCamera@@MAA_NXZ
// EA  : 0x82CC9C50
// RVA : 0x00CC9C50
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

int __fastcall idSpringCamera::InternalDeactivate(idSpringCamera *this)
{
  idPlayer *PlayerActivator; // r3
  idPlayer *v3; // r31
  idPresentable *presentable; // r3
  int v5; // r3

  PlayerActivator = idCamera::GetPlayerActivator(this);
  v3 = PlayerActivator;
  if ( PlayerActivator != nullptr )
  {
    idPlayer::SetControlCamera(this: PlayerActivator, entity: nullptr, allowHUD: false);
    presentable = v3->presentable;
    if ( presentable != nullptr )
      v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = 0;
    *(_BYTE *)(v5 + 19040) = 1;
  }
  this->activator.spawnId.value = 0x1FFF;
  idEntity::BecomeInactive(this, flags: 1);
  idSpringCamera::SetState(this, state: 0);
  this->inhibitControl = false;
  return 1;
}


// ========================================================================
// ?InitDefaultSprings@idSpringCamera@@QAAXXZ
// EA  : 0x82CC9CF8
// RVA : 0x00CC9CF8
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::InitDefaultSprings(idSpringCamera *this)
{
  float v1; // [sp+8h] [-68h]
  float v2; // [sp+Ch] [-64h]

  idSpringCamera::InitSprings(
    this,
    posK: 150.0,
    posC: -1.0,
    fwdPosK: 150.0,
    fwdPosC: -1.0,
    upPosK: 150.0,
    upPosC: -1.0,
    fovK: 0.0,
    fovC: 0.0,
    autoCenterK: v1,
    autoCenterC: v2);
}


// ========================================================================
// ?HandleStateActive@idSpringCamera@@IAAXXZ
// EA  : 0x82CC9D50
// RVA : 0x00CC9D50
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSpringCamera::HandleStateActive(idSpringCamera *this)
{
  int value; // r9
  idEntity *v3; // r3
  idEntity *v4; // r3
  idAnimatedEntity *v5; // r30
  idPhysics *Physics; // r3
  float *v7; // r3
  double v8; // fp12
  idAnimatedEntity *v9; // r3
  int v10; // r9
  idEntity *v11; // r3
  idEntity *v12; // r3
  idAnimatedEntity *v13; // r28
  idPhysics *v14; // r3
  const idVec3 *v15; // r3
  char *v16; // r10
  int *v17; // r11
  int i; // ctr
  double v19; // fp6
  idPlayer *PlayerActivator; // r3
  float *v21; // r3
  long double v22; // fp2
  bool v23; // mr_fpscr49
  double v24; // fp0
  double v25; // fp13
  double v26; // fp12
  double v27; // fp1
  double constraintConeDegs; // fp31
  float *v29; // r3
  __int64 v30; // r7
  idPlayer *v31; // r3
  idPresentable *presentable; // r3
  __int64 v33; // r4 OVERLAPPED
  double x; // fp12
  __int128 v35; // r10
  __int64 v36; // r6
  double v37; // fp1
  __int64 v38; // fp4
  double v39; // fp7
  double v40; // fp1
  double v41; // fp1
  double v42; // fp1
  double v43; // fp1
  double y; // fp13
  double z; // fp12
  idMat3 *v46; // r3
  float *v47; // r3
  long double v48; // fp2
  double v49; // fp0
  double v50; // fp13
  double v51; // fp12
  double v52; // fp11
  double v53; // fp1
  double v54; // fp31
  float *v55; // r3
  idPresentable *v56; // r3
  int v57; // r2 OVERLAPPED
  int v58; // r3
  _WORD *v59; // r11
  __int64 v60; // r11
  int v61; // r3
  __int128 v62; // r8
  __int16 v63; // r4
  double v64; // fp0
  float v65; // r6
  float v66; // r10
  float v67; // r7
  float v68; // r5
  double v69; // fp1
  double v70; // fp1
  double v71; // fp1
  double v72; // fp13
  float *v73; // r3
  long double v74; // fp2
  double v75; // fp13
  bool v76; // mr_fpscr49
  double v77; // fp12
  double v78; // fp11
  double v79; // fp1
  double v80; // fp31
  char *v81; // r10
  float *p_y; // r11
  int j; // ctr
  float *v84; // r3
  idAngles *v85; // r3
  float *v86; // r3
  double v87; // fp0
  double v88; // fp13
  float *v89; // r3
  idAnimatedEntity *v90; // r3
  idSpringCamera::state_t followState; // r11
  idSpringCamera::state_t lookState; // r11
  idSpringCamera::blendMode_t followBlendMode; // r11
  bool v94; // r10
  idSpringCamera::blendMode_t lookBlendMode; // r11
  bool v96; // r6
  double v97; // fp13
  double v98; // fp12
  idRenderWorld *v99; // r3
  idMat3 v100; // [sp+50h] [-2F0h] BYREF
  __int64 v101; // [sp+78h] [-2C8h]
  float v102; // [sp+80h] [-2C0h]
  idMat3 v103; // [sp+88h] [-2B8h] BYREF
  int v104; // [sp+ACh] [-294h] BYREF
  idMat3 v105; // [sp+B0h] [-290h] BYREF
  idMat3 v106; // [sp+D8h] [-268h] BYREF
  float v107; // [sp+FCh] [-244h]
  float v108; // [sp+100h] [-240h]
  idVec3 v109; // [sp+108h] [-238h] BYREF
  idVec3 v110; // [sp+118h] [-228h] BYREF
  idVec3 v111; // [sp+128h] [-218h] BYREF
  char v112; // [sp+13Ch] [-204h] BYREF
  idMat3 v113; // [sp+140h] [-200h] BYREF
  idMat3 v114; // [sp+170h] [-1D0h] BYREF
  idMat3 v115; // [sp+198h] [-1A8h] BYREF
  idMat3 v116; // [sp+1C0h] [-180h] BYREF
  idAngles v117[4]; // [sp+1F0h] [-150h] BYREF
  idAngles v118[4]; // [sp+220h] [-120h] BYREF
  idAngles v119[4]; // [sp+250h] [-F0h] BYREF
  idMat3 v120; // [sp+280h] [-C0h] BYREF
  idMat3 v121; // [sp+2B0h] [-90h] BYREF

  if ( this->followDuration != DURATION_NEVER )
  {
    value = this->followEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v3 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v3 != nullptr )
      {
        v4 = idEntity::CastTo(c: v3);
        v5 = (idAnimatedEntity *)v4;
        if ( v4 != nullptr )
        {
          if ( this->followJointIndex.value == NULL_JOINT_INDEX.value )
          {
            Physics = idEntity::GetPhysics(this: v4);
            v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
            v103.mat[1].y = *v7;
            v103.mat[1].z = v7[1];
            v8 = v7[2];
            this->followState = STATE_ACTIVE;
            v103.mat[2].x = v8;
            goto LABEL_12;
          }
          idTreeAnimator::GetModelSpaceJointTransform(
            this: this->followAnimator,
            pose: DRIVER_MODEL,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->followJointIndex.value,
            origin: (idVec3 *)&v103.mat[1].y,
            axis: &v114);
          idEntity::ConvertLocalToWorldTransform(this: v5, offset: (idVec3 *)&v103.mat[1].y, axis: &v114);
          if ( this->followDuration != DURATION_ANIM
            || (v9 = idAnimatedEntity::CastTo(c: v5), v9->IsAnimating(this: v9)) )
          {
            this->followState = STATE_ACTIVE;
            goto LABEL_12;
          }
        }
      }
    }
    this->followState = STATE_ACTIVE_READY_TO_BLEND_OUT;
    goto LABEL_12;
  }
  this->followState = STATE_INACTIVE;
LABEL_12:
  if ( this->lookDuration != DURATION_NEVER && this->lookMode != LOOK_NONE )
  {
    v10 = this->lookEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] != v10 >> 13 )
      goto LABEL_68;
    v11 = gameLocal->entities.ptr[v10 & 0x1FFF];
    if ( v11 == nullptr )
      goto LABEL_68;
    v12 = idEntity::CastTo(c: v11);
    v13 = (idAnimatedEntity *)v12;
    if ( v12 == nullptr )
      goto LABEL_68;
    if ( this->lookJointIndex.value == NULL_JOINT_INDEX.value )
    {
      v14 = idEntity::GetPhysics(this: v12);
      v15 = v14->GetOrigin(this: v14, a2: 0);
      idSpringCamera::ConstructLookTarget(
        this,
        followTarget: (const idVec3 *)&v103.mat[1].y,
        lookTargetPos: v15,
        lookTarget: &v100);
LABEL_19:
      this->lookState = STATE_ACTIVE;
      goto LABEL_71;
    }
    idTreeAnimator::GetModelSpaceJointTransform(
      this: this->lookAnimator,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->lookJointIndex.value,
      origin: &v111,
      axis: &v105);
    v16 = &v112;
    v17 = &v104;
    for ( i = 9; i != 0; --i )
    {
      ++v17;
      v16 += 4;
      *(_DWORD *)v16 = *v17;
    }
    idEntity::ConvertLocalToWorldTransform(this: v13, offset: &v111, axis: &v105);
    if ( (unsigned int)(this->lookMode - 1) <= 4 )
    {
      if ( this->lookMode == LOOK_POSITION )
      {
        idSpringCamera::ConstructLookTarget(
          this,
          followTarget: (const idVec3 *)&v103.mat[1].y,
          lookTargetPos: &v111,
          lookTarget: &v100);
      }
      else if ( this->lookMode == LOOK_ADD_HEADING )
      {
        PlayerActivator = idCamera::GetPlayerActivator(this);
        PlayerActivator->GetViewTransform(this: PlayerActivator, a2: (idVec3 *)&v115.mat[1].y, a3: &v114);
        v21 = (float *)idMat3::operator*(this: &v120, result: &v113, a: &v114);
        v23 = this->constraintConeDegs > 0.0;
        v24 = *v21;
        v100.mat[0].x = *v21;
        v25 = v21[1];
        v100.mat[0].y = v21[1];
        v26 = v21[2];
        v100.mat[0].z = v21[2];
        v100.mat[1].x = v21[3];
        v100.mat[1].y = v21[4];
        v100.mat[1].z = v21[5];
        v100.mat[2].x = v21[6];
        v100.mat[2].y = v21[7];
        v100.mat[2].z = v21[8];
        if ( v23 )
        {
          *(double *)&v22 = (float)((float)(v105.mat[0].z * (float)v26)
                                  + (float)((float)((float)v25 * v105.mat[0].y) + (float)((float)v24 * v105.mat[0].x)));
          v27 = idMath::ACos(a: v22);
          constraintConeDegs = this->constraintConeDegs;
          if ( (float)((float)v27 * idMath::M_RAD2DEG) > constraintConeDegs )
          {
            v109.x = (float)(v105.mat[0].y * v100.mat[0].z) - (float)(v105.mat[0].z * v100.mat[0].y);
            v109.y = (float)(v105.mat[0].z * v100.mat[0].x) - (float)(v105.mat[0].x * v100.mat[0].z);
            v109.z = (float)(v100.mat[0].y * v105.mat[0].x) - (float)(v105.mat[0].y * v100.mat[0].x);
            idVec3::NormalizeFast(this: &v109);
            v29 = (float *)idMat3::RotateSelf(
                             this: &v105,
                             axis: &v109,
                             angle: (float)((float)constraintConeDegs * idMath::M_DEG2RAD));
            v100.mat[0].x = *v29;
            v100.mat[0].y = v29[1];
            v100.mat[0].z = v29[2];
            v100.mat[1].x = v29[3];
            v100.mat[1].y = v29[4];
            v100.mat[1].z = v29[5];
            v100.mat[2].x = v29[6];
            v100.mat[2].y = v29[7];
            v100.mat[2].z = v29[8];
          }
        }
      }
      else if ( this->lookMode == LOOK_ADD_HEADING_AUTOCENTER )
      {
        v31 = idCamera::GetPlayerActivator(this);
        presentable = v31->presentable;
        if ( presentable != nullptr )
          HIDWORD(v33) = presentable->GetPlayerInterface_2(this: presentable);
        else
          HIDWORD(v33) = 0;
        x = this->springAutoCenter.p1.x;
        DWORD2(v35) = *(unsigned __int16 *)(HIDWORD(v33) + 46038);
        DWORD1(v35) = *(unsigned __int16 *)(HIDWORD(v33) + 45978);
        HIDWORD(v36) = SWORD5(v35);
        LODWORD(v33) = SWORD3(v35);
        v101 = v33;
        v106.mat[0].x = (float)((float)*(__int64 *)((char *)&v33 - 4) * (float)0.0054931641)
                      - (float)((float)v33 * (float)0.0054931641);
        LODWORD(v30) = *(__int16 *)(HIDWORD(v33) + 45980);
        v37 = (float)((float)x + v106.mat[0].x);
        v38 = v30;
        LODWORD(v36) = *(__int16 *)(HIDWORD(v33) + 46040);
        v101 = v36;
        v106.mat[0].y = (float)((float)v36 * (float)0.0054931641) - (float)((float)v38 * (float)0.0054931641);
        LODWORD(v35) = *(__int16 *)(HIDWORD(v33) + 45982);
        v39 = (double)(__int64)v35;
        DWORD2(v35) = *(__int16 *)(HIDWORD(v33) + 46042);
        v101 = *(_QWORD *)((char *)&v35 + 4);
        this->springAutoCenter.p0.x = 0.0;
        this->springAutoCenter.p0.y = 0.0;
        this->springAutoCenter.p0.z = 0.0;
        v106.mat[0].z = (float)((float)*(__int64 *)((char *)&v35 + 4) * (float)0.0054931641)
                      - (float)((float)v39 * (float)0.0054931641);
        v40 = idMath::AngleNormalize360(angle: v37);
        if ( v40 > 180.0 )
          v40 = (float)((float)v40 - (float)360.0);
        this->springAutoCenter.p1.x = v40;
        v41 = idMath::AngleNormalize360(angle: (float)(v106.mat[0].y + this->springAutoCenter.p1.y));
        if ( v41 > 180.0 )
          v41 = (float)((float)v41 - (float)360.0);
        this->springAutoCenter.p1.y = v41;
        v42 = idMath::AngleNormalize360(angle: (float)(this->springAutoCenter.p1.z + v106.mat[0].z));
        if ( v42 > 180.0 )
          v42 = (float)((float)v42 - (float)360.0);
        this->springAutoCenter.p1.z = v42;
        v43 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
        idSpring<idVec3>::Update(this: &this->springAutoCenter, dt: v43);
        y = this->springAutoCenter.p1.y;
        z = this->springAutoCenter.p1.z;
        v106.mat[0].x = this->springAutoCenter.p1.x;
        v106.mat[0].y = y;
        v106.mat[0].z = z;
        v46 = idAngles::ToMat3(this: v118, result: &v106);
        v47 = (float *)idMat3::operator*(this: &v116, result: v46, a: &v105);
        v49 = *v47;
        v100.mat[0].x = *v47;
        v50 = v47[1];
        v100.mat[0].y = v47[1];
        v51 = v47[2];
        v100.mat[0].z = v47[2];
        v100.mat[1].x = v47[3];
        v100.mat[1].y = v47[4];
        v100.mat[1].z = v47[5];
        v100.mat[2].x = v47[6];
        v100.mat[2].y = v47[7];
        v52 = this->constraintConeDegs;
        v100.mat[2].z = v47[8];
        if ( v52 > 0.0 )
        {
          *(double *)&v48 = (float)((float)(v105.mat[0].z * (float)v51)
                                  + (float)((float)((float)v50 * v105.mat[0].y) + (float)((float)v49 * v105.mat[0].x)));
          v53 = idMath::ACos(a: v48);
          v54 = this->constraintConeDegs;
          if ( (float)((float)v53 * idMath::M_RAD2DEG) > v54 )
          {
            v106.mat[2].z = (float)(v105.mat[0].y * v100.mat[0].z) - (float)(v105.mat[0].z * v100.mat[0].y);
            v107 = (float)(v105.mat[0].z * v100.mat[0].x) - (float)(v105.mat[0].x * v100.mat[0].z);
            v108 = (float)(v100.mat[0].y * v105.mat[0].x) - (float)(v105.mat[0].y * v100.mat[0].x);
            idVec3::NormalizeFast(this: (idVec3 *)&v106.mat[2].z);
            v55 = (float *)idMat3::RotateSelf(
                             this: &v105,
                             axis: (const idVec3 *)&v106.mat[2].z,
                             angle: (float)((float)v54 * idMath::M_DEG2RAD));
            v100.mat[0].x = *v55;
            v100.mat[0].y = v55[1];
            v100.mat[0].z = v55[2];
            v100.mat[1].x = v55[3];
            v100.mat[1].y = v55[4];
            v100.mat[1].z = v55[5];
            v100.mat[2].x = v55[6];
            v100.mat[2].y = v55[7];
            v100.mat[2].z = v55[8];
          }
        }
      }
      else
      {
        if ( this->lookMode == LOOK_HEADING )
        {
          v19 = v105.mat[2].z;
          v100.mat[0].x = v105.mat[0].x;
          v100.mat[0].y = v105.mat[0].y;
          v100.mat[0].z = v105.mat[0].z;
          v100.mat[1].x = v105.mat[1].x;
          v100.mat[1].y = v105.mat[1].y;
          v100.mat[1].z = v105.mat[1].z;
          v100.mat[2].x = v105.mat[2].x;
          v100.mat[2].y = v105.mat[2].y;
        }
        else
        {
          v56 = idCamera::GetPlayerActivator(this)->presentable;
          if ( v56 != nullptr )
            v58 = (int)v56->GetPlayerInterface_2(this: v56);
          else
            v58 = 0;
          v59 = (_WORD *)(v58 + 45960);
          if ( this->constraintConeDegs <= 0.0 )
          {
            v65 = *(float *)(v58 + 46168);
            v66 = *(float *)(v58 + 46172);
            v67 = *(float *)(v58 + 46164);
            v68 = *(float *)(v58 + 46176);
            v106.mat[1].z = *(float *)(v58 + 46180);
            *((float *)&v101 + 1) = v65;
            v102 = v66;
            *(float *)&v101 = v67;
            v106.mat[1].y = v68;
            v106.mat[2].x = *(float *)(v58 + 46184);
            v103.mat[0].z = v66 - v106.mat[2].x;
            v64 = (float)(v67 - v68);
            v103.mat[0].y = v65 - v106.mat[1].z;
          }
          else
          {
            HIDWORD(v60) = *(unsigned __int16 *)(v58 + 45980);
            v61 = SWORD1(v60);
            DWORD1(v62) = (unsigned __int16)v59[39];
            v63 = v59[9];
            LODWORD(v60) = (__int16)v59[40];
            DWORD2(v62) = v63;
            LODWORD(v62) = SWORD3(v62);
            v101 = *(_QWORD *)((char *)&v62 + 4);
            *(_QWORD *)&v106.mat[1].y = v62;
            v103.mat[0].z = 0.0;
            v103.mat[0].y = (float)((float)v60 * (float)0.0054931641)
                          - (float)((float)*(__int64 *)(&v57 - 1) * (float)0.0054931641);
            v64 = (float)((float)((float)(__int64)v62 * (float)0.0054931641)
                        - (float)((float)*(__int64 *)((char *)&v62 + 4) * (float)0.0054931641));
          }
          v103.mat[0].x = v64;
          v69 = idMath::AngleNormalize360(angle: (float)((float)v64 + this->springAutoCenter.p0.x));
          if ( v69 > 180.0 )
            v69 = (float)((float)v69 - (float)360.0);
          this->springAutoCenter.p0.x = v69;
          v70 = idMath::AngleNormalize360(angle: (float)(this->springAutoCenter.p0.y + v103.mat[0].y));
          if ( v70 > 180.0 )
            v70 = (float)((float)v70 - (float)360.0);
          this->springAutoCenter.p0.y = v70;
          v71 = idMath::AngleNormalize360(angle: (float)(v103.mat[0].z + this->springAutoCenter.p0.z));
          if ( v71 > 180.0 )
            v71 = (float)((float)v71 - (float)360.0);
          v72 = this->springAutoCenter.p0.y;
          v103.mat[0].x = this->springAutoCenter.p0.x;
          v103.mat[0].z = v71;
          v103.mat[0].y = v72;
          this->springAutoCenter.p0.z = v71;
          v73 = (float *)idAngles::ToMat3(this: v117, result: &v103);
          v75 = *v73;
          v76 = this->constraintConeDegs > 0.0;
          v100.mat[0].x = *v73;
          v77 = v73[1];
          v100.mat[0].y = v73[1];
          v78 = v73[2];
          v100.mat[0].z = v73[2];
          v100.mat[1].x = v73[3];
          v100.mat[1].y = v73[4];
          v100.mat[1].z = v73[5];
          v100.mat[2].x = v73[6];
          v100.mat[2].y = v73[7];
          v100.mat[2].z = v73[8];
          if ( v76 )
          {
            *(double *)&v74 = (float)((float)((float)v78 * mat3_identity.mat[0].z)
                                    + (float)((float)((float)v77 * mat3_identity.mat[0].y)
                                            + (float)((float)v75 * mat3_identity.mat[0].x)));
            v79 = idMath::ACos(a: v74);
            v80 = this->constraintConeDegs;
            if ( (float)((float)v79 * idMath::M_RAD2DEG) > v80 )
            {
              v110.x = (float)(v100.mat[0].z * mat3_identity.mat[0].y) - (float)(v100.mat[0].y * mat3_identity.mat[0].z);
              v110.y = (float)(v100.mat[0].x * mat3_identity.mat[0].z) - (float)(v100.mat[0].z * mat3_identity.mat[0].x);
              v110.z = (float)(v100.mat[0].y * mat3_identity.mat[0].x) - (float)(v100.mat[0].x * mat3_identity.mat[0].y);
              idVec3::NormalizeFast(this: &v110);
              v81 = &v112;
              p_y = &mat2_identity.mat[1].y;
              for ( j = 9; j != 0; --j )
              {
                ++p_y;
                v81 += 4;
                *(float *)v81 = *p_y;
              }
              v84 = (float *)idMat3::RotateSelf(
                               this: &v113,
                               axis: &v110,
                               angle: (float)((float)v80 * idMath::M_DEG2RAD));
              v100.mat[0].x = *v84;
              v100.mat[0].y = v84[1];
              v100.mat[0].z = v84[2];
              v100.mat[1].x = v84[3];
              v100.mat[1].y = v84[4];
              v100.mat[1].z = v84[5];
              v100.mat[2].x = v84[6];
              v100.mat[2].y = v84[7];
              v100.mat[2].z = v84[8];
              v100.mat[1].z = 0.0;
              idVec3::NormalizeFast(this: &v100.mat[1]);
              v100.mat[2].x = (float)(v100.mat[0].y * v100.mat[1].z) - (float)(v100.mat[1].y * v100.mat[0].z);
              v100.mat[2].y = (float)(v100.mat[1].x * v100.mat[0].z) - (float)(v100.mat[0].x * v100.mat[1].z);
              v100.mat[2].z = (float)(v100.mat[0].x * v100.mat[1].y) - (float)(v100.mat[0].y * v100.mat[1].x);
              v85 = idMat3::ToAngles(this: &v115, result: (idAngles *)&v100);
              v103.mat[0].x = v85->pitch;
              v103.mat[0].y = v85->yaw;
              v103.mat[0].z = v85->roll;
              v86 = (float *)idAngles::ToMat3(this: v119, result: &v103);
              v100.mat[0].x = *v86;
              v100.mat[0].y = v86[1];
              v100.mat[0].z = v86[2];
              v100.mat[1].x = v86[3];
              v100.mat[1].y = v86[4];
              v100.mat[1].z = v86[5];
              v100.mat[2].x = v86[6];
              v100.mat[2].y = v86[7];
              v87 = v103.mat[0].y;
              v88 = v103.mat[0].z;
              v100.mat[2].z = v86[8];
              this->springAutoCenter.p0.x = v103.mat[0].x;
              this->springAutoCenter.p0.y = v87;
              this->springAutoCenter.p0.z = v88;
            }
          }
          v89 = (float *)idMat3::operator*(this: &v121, result: &v100, a: &v105);
          v100.mat[0].x = *v89;
          v100.mat[0].y = v89[1];
          v100.mat[0].z = v89[2];
          v100.mat[1].x = v89[3];
          v100.mat[1].y = v89[4];
          v100.mat[1].z = v89[5];
          v100.mat[2].x = v89[6];
          v100.mat[2].y = v89[7];
          v19 = v89[8];
        }
        v100.mat[2].z = v19;
      }
    }
    if ( this->lookDuration != DURATION_ANIM )
      goto LABEL_19;
    v90 = idAnimatedEntity::CastTo(c: v13);
    if ( v90->IsAnimating(this: v90) )
      this->lookState = STATE_ACTIVE;
    else
LABEL_68:
      this->lookState = STATE_ACTIVE_READY_TO_BLEND_OUT;
  }
  else if ( this->lookState != STATE_INACTIVE )
  {
    this->lookState = STATE_INACTIVE;
  }
LABEL_71:
  followState = this->followState;
  if ( followState == STATE_INACTIVE || followState == STATE_ACTIVE_READY_TO_BLEND_OUT )
  {
    lookState = this->lookState;
    if ( lookState == STATE_INACTIVE || lookState == STATE_ACTIVE_READY_TO_BLEND_OUT )
      idSpringCamera::SetState(this, state: 5);
  }
  followBlendMode = this->followBlendMode;
  v94 = followBlendMode != BLEND_SMOOTH && (unsigned int)followBlendMode < BLEND_FOLLOW_SNAP_LOOK_SMOOTH_SNAP_SMOOTH;
  lookBlendMode = this->lookBlendMode;
  v96 = lookBlendMode != BLEND_SMOOTH && (unsigned int)lookBlendMode < BLEND_FOLLOW_SNAP_LOOK_SMOOTH_SNAP_SMOOTH;
  if ( springCam_AlwaysSnap.valueInteger != 0 )
  {
    v94 = true;
    v96 = true;
  }
  if ( this->followState != STATE_INACTIVE )
  {
    v97 = v103.mat[1].z;
    v98 = v103.mat[2].x;
    this->springFollowPos.p0.x = v103.mat[1].y;
    this->springFollowPos.p0.y = v97;
    this->springFollowPos.p0.z = v98;
    if ( v94 )
    {
      this->springFollowPos.p1.x = this->springFollowPos.p0.x;
      this->springFollowPos.p1.y = this->springFollowPos.p0.y;
      this->springFollowPos.p1.z = this->springFollowPos.p0.z;
      this->springFollowPos.vel.z = 0.0;
      this->springFollowPos.vel.y = 0.0;
      this->springFollowPos.vel.x = 0.0;
    }
  }
  if ( this->lookState != STATE_INACTIVE )
    idSpringCamera::SetLookDestination(this, fwdDir: v100.mat, upDir: &v100.mat[2], snap: v96);
  if ( springCam_Debug.valueInteger != 0 )
  {
    v99 = gameLocal->GetRenderWorld(this: gameLocal);
    v99->DebugAxis_2(this: v99, a2: (const idVec3 *)&v103.mat[1].y, a3: &v100, a4: 0, a5: false);
  }
}


// ========================================================================
// ?BlendOut@idSpringCamera@@QAAX_N@Z
// EA  : 0x82CCAA60
// RVA : 0x00CCAA60
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::BlendOut(idSpringCamera *this, bool instantBlend)
{
  if ( this->state != STATE_INACTIVE )
  {
    if ( instantBlend )
      idSpringCamera::SetState(this, state: 6);
    else
      idSpringCamera::SetState(this, state: 5);
  }
}


// ========================================================================
// ?HandleStateBlendOut@idSpringCamera@@IAAXXZ
// EA  : 0x82CCAA90
// RVA : 0x00CCAA90
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::HandleStateBlendOut(idSpringCamera *this)
{
  idPlayer *PlayerActivator; // r3
  idPresentable *presentable; // r3
  int v4; // r3
  idSpringCamera::blendMode_t followBlendMode; // r11
  bool v6; // r29
  idSpringCamera::blendMode_t lookBlendMode; // r11
  bool v8; // r30
  char v9; // r11
  idRenderWorld *v10; // r3
  idVec3 v11; // [sp+50h] [-70h] BYREF
  idMat3 v12; // [sp+60h] [-60h] BYREF
  idVec3 v13[4]; // [sp+88h] [-38h] BYREF

  PlayerActivator = idCamera::GetPlayerActivator(this);
  if ( PlayerActivator != nullptr )
  {
    if ( this->getPlayerLookFromView )
    {
      presentable = PlayerActivator->presentable;
      if ( presentable != nullptr )
      {
        v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
        idView::GetViewPos(this: (idView *)(v4 + 16224), origin: &v11, axis: (idMat3 *)&v12.mat[1].y);
      }
      else
      {
        idView::GetViewPos(this: (idView *)0x3F60, origin: &v11, axis: (idMat3 *)&v12.mat[1].y);
      }
    }
    else
    {
      PlayerActivator->GetViewTransform(this: PlayerActivator, a2: &v11, a3: (idMat3 *)&v12.mat[1].y);
    }
    if ( springCam_Debug.valueInteger != 0 )
      idMat3::ToAngles(this: &v12, result: (idAngles *)&this->viewAxis);
    followBlendMode = this->followBlendMode;
    v6 = (unsigned int)followBlendMode >= BLEND_SNAP && followBlendMode == BLEND_SNAP;
    lookBlendMode = this->lookBlendMode;
    v8 = (unsigned int)lookBlendMode >= BLEND_SNAP && lookBlendMode == BLEND_SNAP;
    if ( springCam_AlwaysSnap.valueInteger != 0 )
    {
      v6 = true;
      v8 = true;
    }
    if ( this->followState != STATE_INACTIVE )
      idSpringCamera::SetFollowDestination(this, pos: &v11, snap: v6);
    if ( this->lookState != STATE_INACTIVE )
      idSpringCamera::SetLookDestination(this, fwdDir: (const idVec3 *)&v12.mat[1].y, upDir: v13, snap: v8);
    this->followBlendSpring.p0.x = 0.0;
    if ( v6 )
      this->followBlendSpring.p1.x = 0.0;
    this->lookBlendSpring.p0.x = 0.0;
    if ( v8 )
      this->lookBlendSpring.p1.x = 0.0;
    if ( this->followBlendSpring.p1.x >= 0.001 || (v9 = 1, this->lookBlendSpring.p1.x >= 0.001) )
      v9 = 0;
    if ( v9 != 0 )
      idSpringCamera::SetState(this, state: 6);
    if ( springCam_Debug.valueInteger != 0 )
    {
      v10 = gameLocal->GetRenderWorld(this: gameLocal);
      v10->DebugAxis_2(this: v10, a2: &v11, a3: (idMat3 *)&v12.mat[1].y, a4: 0, a5: false);
    }
  }
}


// ========================================================================
// ?Update@idSpringCamera@@QAAXXZ
// EA  : 0x82CCAC90
// RVA : 0x00CCAC90
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::Update(idSpringCamera *this)
{
  idPlayer *PlayerActivator; // r3
  idPlayer *v3; // r30
  idSpringCamera::state_t state; // r11
  double v5; // fp31
  double v6; // fp1
  double v7; // fp1

  idEntity::Think(this);
  this->calculatedView = false;
  if ( (springCam_BlendSpringK.flags & 0x20000) != 0 )
  {
    springCam_BlendSpringK.flags &= ~0x20000u;
    idSpring<idVec1>::SetConstants(this: &this->followBlendSpring, _k: springCam_BlendSpringK.valueFloat, _c: -1.0);
    idSpring<idVec1>::SetConstants(this: &this->lookBlendSpring, _k: springCam_BlendSpringK.valueFloat, _c: -1.0);
  }
  PlayerActivator = idCamera::GetPlayerActivator(this);
  v3 = PlayerActivator;
  if ( PlayerActivator != nullptr
    && PlayerActivator->IsDead(this: PlayerActivator)
    && this->state != (STATE_ACTIVE_READY_TO_BLEND_OUT|STATE_REACTIVATE) )
  {
    idSpringCamera::SetState(this, state: 6);
  }
  state = this->state;
  if ( state == STATE_ACTIVE )
  {
    idSpringCamera::HandleStateActive(this);
  }
  else if ( state == STATE_BLEND_OUT )
  {
    idSpringCamera::HandleStateBlendOut(this);
  }
  v5 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
  idSpring<idVec3>::Update(this: &this->springFollowPos, dt: v5);
  idSpring<idVec3>::Update(this: &this->springLookFwdDir, dt: v5);
  idSpring<idVec3>::Update(this: &this->springLookUpDir, dt: v5);
  idSpring<idVec1>::Update(this: &this->springFOV, dt: v5);
  v6 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
  idSpring<idVec1>::Update(this: &this->followBlendSpring, dt: v6);
  v7 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
  idSpring<idVec1>::Update(this: &this->lookBlendSpring, dt: v7);
  idSpringCamera::UpdateFromData(this);
  if ( idSpringCamera::GetCalculateViewStage(this, player: v3) == STAGE_UPDATE )
    idSpringCamera::InternalCalculateView(this, player: v3);
}


// ========================================================================
// ?Think@idSpringCamera@@UAAXXZ
// EA  : 0x82CCAE28
// RVA : 0x00CCAE28
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __fastcall idSpringCamera::Think(idSpringCamera *this)
{
  if ( !this->manualUpdate )
    idSpringCamera::Update(this);
}


// ========================================================================
// `dynamic initializer for 'springCam_UpdateView''
// EA  : 0x833790D8
// RVA : 0x013790D8
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__springCam_UpdateView__()
{
  idCVar::idCVar(
    this: &springCam_UpdateView,
    name: "springCam_UpdateView",
    value: "1",
    flags: 1,
    description: "should the spring cam update the view?",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__springCam_UpdateView__);
}


// ========================================================================
// `dynamic initializer for 'springCam_Debug''
// EA  : 0x83379130
// RVA : 0x01379130
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__springCam_Debug__()
{
  idCVar::idCVar(
    this: &springCam_Debug,
    name: "springCam_Debug",
    value: "0",
    flags: 1,
    description: "show debug info on the spring cam",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__springCam_Debug__);
}


// ========================================================================
// `dynamic initializer for 'springCam_DebugTraceStates''
// EA  : 0x83379188
// RVA : 0x01379188
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__springCam_DebugTraceStates__()
{
  idCVar::idCVar(
    this: &springCam_DebugTraceStates,
    name: "springCam_DebugTraceStates",
    value: "0",
    flags: 1,
    description: "trace the camera states to the console",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__springCam_DebugTraceStates__);
}


// ========================================================================
// `dynamic initializer for 'springCam_DebugTraceBlend''
// EA  : 0x833791E0
// RVA : 0x013791E0
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__springCam_DebugTraceBlend__()
{
  idCVar::idCVar(
    this: &springCam_DebugTraceBlend,
    name: "springCam_DebugTraceBlend",
    value: "0",
    flags: 1,
    description: "trace the camera blending",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__springCam_DebugTraceBlend__);
}


// ========================================================================
// `dynamic initializer for 'springCam_DebugParentInfo''
// EA  : 0x83379238
// RVA : 0x01379238
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__springCam_DebugParentInfo__()
{
  idCVar::idCVar(
    this: &springCam_DebugParentInfo,
    name: "springCam_DebugParentInfo",
    value: "0",
    flags: 1,
    description: "trace the updates due to parent movement",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__springCam_DebugParentInfo__);
}


// ========================================================================
// `dynamic initializer for 'springCam_BlendSpringK''
// EA  : 0x83379290
// RVA : 0x01379290
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__springCam_BlendSpringK__()
{
  idCVar::idCVar(
    this: &springCam_BlendSpringK,
    name: "springCam_BlendSpringK",
    value: "300",
    flags: 4,
    description: "spring constant for blend spring controlling blend to and from the player view",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__springCam_BlendSpringK__);
}


// ========================================================================
// `dynamic initializer for 'springCam_AlwaysSnap''
// EA  : 0x833792E8
// RVA : 0x013792E8
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__springCam_AlwaysSnap__()
{
  idCVar::idCVar(
    this: &springCam_AlwaysSnap,
    name: "springCam_AlwaysSnap",
    value: "0",
    flags: 1,
    description: "always snap position and orientation to desired values",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__springCam_AlwaysSnap__);
}


// ========================================================================
// `dynamic initializer for 'springCam_ForceCalcViewStage''
// EA  : 0x83379340
// RVA : 0x01379340
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__springCam_ForceCalcViewStage__()
{
  idCVar::idCVar(
    this: &springCam_ForceCalcViewStage,
    name: "springCam_ForceCalcViewStage",
    value: "0",
    flags: 2,
    description: "0=STAGE_DEFAULT, 1=STAGE_UPDATE, 2=STAGE_DRAW",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__springCam_ForceCalcViewStage__);
}


// ========================================================================
// `dynamic initializer for 'springCam_ForceBlendDurationMS''
// EA  : 0x83379398
// RVA : 0x01379398
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__springCam_ForceBlendDurationMS__()
{
  idCVar::idCVar(
    this: &springCam_ForceBlendDurationMS,
    name: "springCam_ForceBlendDurationMS",
    value: "-1",
    flags: 2,
    description: "forces the blend duration",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__springCam_ForceBlendDurationMS__);
}


// ========================================================================
// `dynamic initializer for 'springCam_ForceLookMode''
// EA  : 0x833793F0
// RVA : 0x013793F0
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__springCam_ForceLookMode__()
{
  idCVar::idCVar(
    this: &springCam_ForceLookMode,
    name: "springCam_ForceLookMode",
    value: "-1",
    flags: 2,
    description: "force the look mode, or -1 to ignore (0=NONE, 1=HEADING, 2=POSITION, 3=ADD_POSITION)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__springCam_ForceLookMode__);
}


// ========================================================================
// `dynamic initializer for 'springCam_ForceFollowBlendMode''
// EA  : 0x83379448
// RVA : 0x01379448
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__springCam_ForceFollowBlendMode__()
{
  idCVar::idCVar(
    this: &springCam_ForceFollowBlendMode,
    name: "springCam_ForceFollowBlendMode",
    value: "-1",
    flags: 2,
    description: "force the blend mode, or -1 to ignore (0=SMOOTH, 1=SMOOTH_SNAP_SMOOTH, 2=SNAP_SNAP_SMOOTH, 3=SNAP)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__springCam_ForceFollowBlendMode__);
}


// ========================================================================
// `dynamic initializer for 'springCam_ForceLookBlendMode''
// EA  : 0x833794A0
// RVA : 0x013794A0
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__springCam_ForceLookBlendMode__()
{
  idCVar::idCVar(
    this: &springCam_ForceLookBlendMode,
    name: "springCam_ForceLookBlendMode",
    value: "-1",
    flags: 2,
    description: "force the blend mode, or -1 to ignore (0=SMOOTH, 1=SMOOTH_SNAP_SMOOTH, 2=SNAP_SNAP_SMOOTH, 3=SNAP)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__springCam_ForceLookBlendMode__);
}


// ========================================================================
// `dynamic initializer for 'springCam_ConstraintConeDegs''
// EA  : 0x833794F8
// RVA : 0x013794F8
// PDB : w:\tech5\tungsten\game\entities\springcamera.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__springCam_ConstraintConeDegs__()
{
  idCVar::idCVar(
    this: &springCam_ConstraintConeDegs,
    name: "springCam_ConstraintConeDegs",
    value: "30",
    flags: 4,
    description: "angle of LOOK_ADD_HEADING and LOOK_ADD_HEADING_AUTOCENTER mode constraint cone in degrees, centered on animated forward direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__springCam_ConstraintConeDegs__);
}

