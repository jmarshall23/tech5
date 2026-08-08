
// ========================================================================
// ?PlayerBehavior_Startup@idPlayer@@QAAXXZ
// EA  : 0x82E3B788
// RVA : 0x00E3B788
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Startup(idPlayer *this)
{
  if ( !idPlayer::IsBot(this) && !common->IsMultiplayer(this: common) )
  {
    idPlayer::PlayerBehavior_ContextualLadder_Startup(this);
    idPlayer::PlayerBehavior_ContextualShimmy_Startup(this);
    idPlayer::PlayerBehavior_SprintSlide_Startup(this);
    idPlayer::PlayerBehavior_Takedown_Startup(this);
    idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
    idPlayer::PlayerBehavior_WallClimb_Startup(this);
  }
}


// ========================================================================
// ?PlayerBehavior_Shared_ShouldHideWeapon@idPlayer@@QBA_NXZ
// EA  : 0x82E3B818
// RVA : 0x00E3B818
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_Shared_ShouldHideWeapon(idPlayer *this)
{
  idPlayer::idPlayerBehaviorContextualShimmyState_t state; // r11
  unsigned __int8 v3; // r11
  bool v4; // zf

  if ( idPlayer::PlayerBehavior_Takedown_IsInTakedown(this) )
    return 1;
  state = this->behaviors.contextualShimmy.state;
  if ( state == CONTEXTUAL_SHIMMY_STATE_MOUNT_INSIDESSHQ_CLIMBOUT )
    return 1;
  v4 = state != CONTEXTUAL_SHIMMY_STATE_MOUNT_CUSTOMANIM;
  v3 = 0;
  if ( !v4 )
    return 1;
  return v3;
}


// ========================================================================
// ?PlayerBehavior_Shared_CheckBlocked@idPlayer@@SA_NABVidVec3@@0AAMH_NPAUtrace_t@@H@Z
// EA  : 0x82E3B870
// RVA : 0x00E3B870
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

// attributes: thunk
int __fastcall idPlayer::PlayerBehavior_Shared_CheckBlocked(
        const idVec3 *startPos,
        const idVec3 *endPos,
        float *blockDist,
        int entityNum,
        bool bDebug,
        trace_t *tr,
        int contentMask)
{
  return idPresentablePlayer::PlayerBehavior_Shared_CheckBlocked(
           startPos,
           endPos,
           blockDist,
           entityNum,
           bDebug,
           tr,
           contentMask);
}


// ========================================================================
// ?PlayerBehavior_EndAllBehaviors@idPlayer@@QAAXXZ
// EA  : 0x82E3B878
// RVA : 0x00E3B878
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_EndAllBehaviors(idPlayer *this)
{
  idAlignedEntity *thirdPersonHands; // r3
  idAlignedEntity *v3; // r30
  idPresentable *presentable; // r11
  idAlignedEntity *thirdPersonLegs; // r3
  idAlignedEntity *v6; // r31
  idPresentable *v7; // r11

  if ( this->behaviors.takedown.state != TAKEDOWNSTATE_NONE )
    idPlayer::PlayerBehavior_Takedown_EndTakedown(this);
  if ( this->behaviors.lean.state != LEAN_STATE_NONE )
    idPlayer::PlayerBehavior_Lean_EndLean(this);
  if ( this->behaviors.contextualShimmy.state != CONTEXTUAL_SHIMMY_STATE_NONE )
    idPlayer::PlayerBehavior_ContextualShimmy_EndShimmy(this);
  if ( this->behaviors.sprintSlide.state != SPRINT_SLIDE_STATE_NONE )
    idPlayer::PlayerBehavior_SprintSlide_EndSlide(this);
  if ( this->behaviors.wallClimb.state != WALLCLIMB_STATE_NONE )
    idPlayer::PlayerBehavior_WallClimb_EndWallClimb(this);
  thirdPersonHands = this->thirdPersonHands;
  if ( thirdPersonHands != nullptr )
  {
    idAlignedEntity::StopAnim(this: thirdPersonHands);
    v3 = this->thirdPersonHands;
    presentable = v3->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: this->thirdPersonHands);
      presentable = v3->presentable;
    }
    presentable->Hide(this: presentable, a2: true);
  }
  thirdPersonLegs = this->thirdPersonLegs;
  if ( thirdPersonLegs != nullptr )
  {
    idAlignedEntity::StopAnim(this: thirdPersonLegs);
    v6 = this->thirdPersonLegs;
    v7 = v6->presentable;
    if ( v7 == nullptr )
    {
      idEntity::InitPresentableInternal(this: v6);
      v7 = v6->presentable;
    }
    v7->Hide(this: v7, a2: true);
  }
}


// ========================================================================
// ?PlayerBehavior_PostEvent@idPlayer@@QAAXW4idPlayerBehaviorEvent_t@@@Z
// EA  : 0x82E3B990
// RVA : 0x00E3B990
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_PostEvent(idPlayer *this, idPlayerBehaviorEvent_t event)
{
  if ( !idPlayer::IsBot(this) && !common->IsMultiplayer(this: common) )
  {
    idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
    idPlayer::PlayerBehavior_ContextualShimmy_HandleEvent(this, event);
    idPlayer::PlayerBehavior_SprintSlide_HandleEvent(this, event);
    idPlayer::PlayerBehavior_Lean_HandleEvent(this, event);
  }
}


// ========================================================================
// ?PlayerBehavior_Draw@idPlayer@@QAAXXZ
// EA  : 0x82E3BA28
// RVA : 0x00E3BA28
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Draw(idPlayer *this)
{
  if ( !idPlayer::IsBot(this) && !common->IsMultiplayer(this: common) )
  {
    idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
    idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  }
}


// ========================================================================
// ?PlayerBehavior_Shared_SetViewAnglesConstraint@idPlayer@@QAAX_NPBVidVec3@@MMM@Z
// EA  : 0x82E3BA98
// RVA : 0x00E3BA98
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
        idPlayer *this,
        bool constrain,
        idAngles *heading,
        double maxDeltaPitch,
        double maxDeltaYaw,
        double rate)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v11; // r3
  const idAngles *v12; // r6
  double v13; // fp1
  const idAngles *v14; // r5
  bool v15; // r4
  idPresentable *v16; // r3
  float v17[4]; // [sp+50h] [-50h] BYREF
  idVec3 v18[2]; // [sp+60h] [-40h] BYREF

  if ( constrain )
  {
    idVec3::ToAngles(this: v18, result: heading);
    presentable = this->presentable;
    v17[0] = maxDeltaPitch;
    v17[1] = maxDeltaYaw;
    v17[2] = 0.0;
    if ( presentable != nullptr )
    {
      v11 = presentable->GetPlayerInterface_2(this: presentable);
      v12 = (const idAngles *)v17;
      v13 = rate;
    }
    else
    {
      v11 = nullptr;
      v13 = rate;
      v12 = (const idAngles *)v17;
    }
    v14 = (const idAngles *)v18;
    v15 = true;
  }
  else
  {
    v16 = this->presentable;
    if ( v16 != nullptr )
      v11 = v16->GetPlayerInterface_2(this: v16);
    else
      v11 = nullptr;
    v14 = &ang_zero;
    v15 = false;
    v12 = &ang_zero;
    v13 = 0.0;
  }
  idPresentablePlayer::SetViewAnglesConstraint(this: v11, constrain: v15, minAngles: v14, maxAngles: v12, rate: v13);
}


// ========================================================================
// ?PlayerBehavior_Shared_SetViewAnglesConstraintExplicit@idPlayer@@QAAX_NPBVidVec3@@MMMMMMM@Z
// EA  : 0x82E3BB98
// RVA : 0x00E3BB98
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraintExplicit(
        idPlayer *this,
        bool constrain,
        idAngles *heading,
        double minDeltaPitch,
        double maxDeltaPitch,
        double minDeltaYaw,
        double maxDeltaYaw,
        double minDeltaRoll,
        double maxDeltaRoll,
        double rate)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v19; // r3
  const idAngles *v20; // r7
  double v21; // fp1
  const idAngles *v22; // r6
  const idAngles *v23; // r5
  bool v24; // r4
  idPresentable *v25; // r3
  float v26[4]; // [sp+50h] [-80h] BYREF
  float v27[4]; // [sp+60h] [-70h] BYREF
  idVec3 v28[6]; // [sp+70h] [-60h] BYREF

  if ( constrain )
  {
    idVec3::ToAngles(this: v28, result: heading);
    presentable = this->presentable;
    v27[0] = minDeltaPitch;
    v27[1] = minDeltaYaw;
    v27[2] = minDeltaRoll;
    v26[0] = maxDeltaPitch;
    v26[1] = maxDeltaYaw;
    v26[2] = maxDeltaRoll;
    if ( presentable != nullptr )
      v19 = presentable->GetPlayerInterface_2(this: presentable);
    else
      v19 = nullptr;
    v20 = (const idAngles *)v26;
    v21 = rate;
    v22 = (const idAngles *)v27;
    v23 = (const idAngles *)v28;
    v24 = true;
  }
  else
  {
    v25 = this->presentable;
    if ( v25 != nullptr )
      v19 = v25->GetPlayerInterface_2(this: v25);
    else
      v19 = nullptr;
    v23 = &ang_zero;
    v24 = false;
    v20 = &ang_zero;
    v22 = &ang_zero;
    v21 = 0.0;
  }
  idPresentablePlayer::SetViewAnglesConstraintExplicit(
    this: v19,
    constrain: v24,
    baseAngles: v23,
    minDeltaAngles: v22,
    maxDeltaAngles: v20,
    rate: v21);
}


// ========================================================================
// ?PlayerBehavior_Shared_AlignEntityOrigin@idPlayer@@QAAXPAVidAlignedEntity@@ABVidVec3@@@Z
// EA  : 0x82E3BCA0
// RVA : 0x00E3BCA0
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_AlignEntityOrigin(
        idPlayer *this,
        idAlignedEntity *ent,
        const idVec3 *origin)
{
  idPresentable *presentable; // r3
  const idAngles *v7; // r4
  idAngles *ViewAngles; // r3
  double v11; // fp3
  double v12; // fp6
  double v13; // fp3
  idPhysics *Physics; // r3
  float *v15; // r3
  double v16; // fp10
  double v17; // fp9
  double v18; // fp8
  idVec3 v19; // [sp+50h] [-70h] BYREF
  char v20; // [sp+60h] [-60h] BYREF
  idMat3 v21; // [sp+70h] [-50h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v7 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v7 = nullptr;
  ViewAngles = (idAngles *)idPresentablePlayer::GetViewAngles(
                             this: (idPresentablePlayer *)&v20,
                             result: v7,
                             includeWeaponKick: true);
  idAngles::ToVectors(this: ViewAngles, forward: &v19, right: nullptr, up: nullptr);
  _FP6 = (float)((float)((float)(v19.y * v19.y) + (float)(v19.x * v19.x)) - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f12 }
  v11 = __frsqrte(_FP4);
  v12 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                      * (float)((float)((float)(v19.y * v19.y) + (float)(v19.x * v19.x))
                                                                                              * (float)0.5))
                                                                              * (float)v11)
                                                                      - (float)1.5)
                                                      * (float)v11)
                                              * (float)((float)((float)(v19.y * v19.y) + (float)(v19.x * v19.x))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v11
                                                                              * (float)((float)((float)(v19.y * v19.y)
                                                                                              + (float)(v19.x * v19.x))
                                                                                      * (float)0.5))
                                                                      * (float)v11)
                                                              - (float)1.5)
                                              * (float)v11))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v11
                                                      * (float)((float)((float)(v19.y * v19.y) + (float)(v19.x * v19.x))
                                                              * (float)0.5))
                                              * (float)v11)
                                      - (float)1.5)
                      * (float)v11));
  v13 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)(v19.y * v19.y) + (float)(v19.x * v19.x)) * (float)0.5)) * (float)v11) - (float)1.5)
                                                                                              * (float)v11)
                                                                                      * (float)((float)((float)(v19.y * v19.y) + (float)(v19.x * v19.x))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)(v19.y * v19.y) + (float)(v19.x * v19.x)) * (float)0.5)) * (float)v11) - (float)1.5)
                                                                                      * (float)v11))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v11
                                                                                              * (float)((float)((float)(v19.y * v19.y) + (float)(v19.x * v19.x)) * (float)0.5))
                                                                                      * (float)v11)
                                                                              - (float)1.5)
                                                              * (float)v11))
                                              * (float)((float)((float)(v19.y * v19.y) + (float)(v19.x * v19.x))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)(v19.y * v19.y) + (float)(v19.x * v19.x)) * (float)0.5)) * (float)v11) - (float)1.5)
                                                                                      * (float)v11)
                                                                              * (float)((float)((float)(v19.y * v19.y)
                                                                                              + (float)(v19.x * v19.x))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)(v19.y * v19.y) + (float)(v19.x * v19.x)) * (float)0.5)) * (float)v11)
                                                                                              - (float)1.5)
                                                                              * (float)v11))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v11
                                                                                      * (float)((float)((float)(v19.y * v19.y) + (float)(v19.x * v19.x))
                                                                                              * (float)0.5))
                                                                              * (float)v11)
                                                                      - (float)1.5)
                                                      * (float)v11)))
                              - (float)1.5)
              * (float)v12);
  v19.x = v19.x * (float)v13;
  v19.y = v19.y * (float)v13;
  v19.z = (float)v13 * (float)0.0;
  Physics = idEntity::GetPhysics(this);
  v15 = (float *)Physics->GetGravityNormal(this: Physics);
  v16 = v15[1];
  v17 = -*v15;
  v18 = v15[2];
  v21.mat[0].x = v19.x;
  v21.mat[0].y = v19.y;
  v21.mat[0].z = v19.z;
  v21.mat[2].x = v17;
  v21.mat[2].y = -v16;
  v21.mat[2].z = -v18;
  v21.mat[1].z = -(float)((float)(v21.mat[2].y * v19.x) - (float)((float)v17 * v19.y));
  v21.mat[1].x = -(float)((float)(v21.mat[2].z * v19.y) - (float)(v21.mat[2].y * v19.z));
  v21.mat[1].y = -(float)((float)((float)v17 * v19.z) - (float)(v21.mat[2].z * v19.x));
  idAlignedEntity::Align(this: ent, origin, axis: &v21, alignMode: SET_POS_SET_AXIS);
}


// ========================================================================
// ?PlayerBehavior_Shared_PlayThirdPersonHandsAnim@idPlayer@@QAAXPBD_NHPBVblendParms_t@@M@Z
// EA  : 0x82E3BE20
// RVA : 0x00E3BE20
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
        idPlayer *this,
        const char *animName,
        bool loop,
        int durationMS,
        const blendParms_t *blendParms,
        double rateScale)
{
  idAlignedEntity *thirdPersonHands; // r3
  char *v11; // r10
  char *p_flags; // r11
  int i; // ctr
  const char *v14; // r31
  int Duration; // r30
  int v16; // r3
  char v17; // [sp+4Ch] [-44h] BYREF
  blendParms_t v18[3]; // [sp+50h] [-40h] BYREF

  thirdPersonHands = this->thirdPersonHands;
  if ( thirdPersonHands != nullptr )
  {
    if ( pb_EnableThirdPersonHands.valueInteger != 0 )
    {
      idAlignedEntity::PlayAnim(
        this: thirdPersonHands,
        aliasName: animName,
        loop,
        durationMS,
        _blendParms: blendParms,
        rateScale);
      accumulatedHandsAnimDeltaPos.x = vec3_origin.x;
      accumulatedHandsAnimDeltaAngles.pitch = ang_zero.pitch;
      accumulatedHandsAnimDeltaPos.y = vec3_origin.y;
      accumulatedHandsAnimDeltaPos.z = vec3_origin.z;
      accumulatedHandsAnimDeltaAngles.yaw = ang_zero.yaw;
      accumulatedHandsAnimDeltaAngles.roll = ang_zero.roll;
      if ( pb_TraceHandsAnims.valueInteger != 0 )
      {
        blendParms_t::blendParms_t(this: v18);
        if ( blendParms != nullptr )
        {
          v11 = &v17;
          p_flags = &blendParms[-1].parms.flags;
          for ( i = 5; i != 0; --i )
          {
            p_flags += 4;
            v11 += 4;
            *(_DWORD *)v11 = *(_DWORD *)p_flags;
          }
        }
        if ( loop )
          v14 = "true";
        else
          v14 = "false";
        Duration = (__int16)blendParms_t::GetDuration(this: v18);
        v16 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "(%d)%s: <%s>, loop = %s, durationMS = %d, blend frames = %d\n",
          v16,
          "idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim",
          animName,
          v14,
          durationMS,
          Duration);
      }
    }
  }
  else
  {
    idLib::Warning(
      fmt: "%s: third person hands model not present",
      "idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim");
  }
}


// ========================================================================
// ?PlayerBehavior_Shared_PlayThirdPersonHandsAnim@idPlayer@@QAA_NABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_NHPBVblendParms_t@@M@Z
// EA  : 0x82E3BF98
// RVA : 0x00E3BF98
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
        idPlayer *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *alias,
        bool loop,
        int durationMS,
        const blendParms_t *blendParms,
        double rateScale)
{
  idAlignedEntity *thirdPersonHands; // r3
  int v13; // r3
  int v14; // r26
  char *v15; // r10
  char *p_flags; // r11
  int i; // ctr
  const char *v18; // r31
  const char *v19; // r30
  int v20; // r29
  int v21; // r3
  const char *v22; // r31
  int Duration; // r30
  int v24; // r3
  unsigned __int16 v25[6]; // [sp+50h] [-60h] BYREF
  char v26; // [sp+5Ch] [-54h] BYREF
  blendParms_t v27[4]; // [sp+60h] [-50h] BYREF

  thirdPersonHands = this->thirdPersonHands;
  if ( thirdPersonHands == nullptr )
  {
    idLib::Warning(
      fmt: "%s: third person hands model not present",
      "idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim");
    return 0;
  }
  if ( pb_EnableThirdPersonHands.valueInteger == 0 )
    return 0;
  v13 = idAlignedEntity::PlayAnim(
          this: thirdPersonHands,
          aliasHandle: alias,
          loop,
          durationMS,
          _blendParms: blendParms,
          rateScale);
  accumulatedHandsAnimDeltaPos.x = vec3_origin.x;
  accumulatedHandsAnimDeltaAngles.pitch = ang_zero.pitch;
  v14 = v13;
  accumulatedHandsAnimDeltaPos.y = vec3_origin.y;
  accumulatedHandsAnimDeltaPos.z = vec3_origin.z;
  accumulatedHandsAnimDeltaAngles.yaw = ang_zero.yaw;
  accumulatedHandsAnimDeltaAngles.roll = ang_zero.roll;
  if ( pb_TraceHandsAnims.valueInteger == 0 )
    return v14;
  blendParms_t::blendParms_t(this: v27);
  if ( blendParms != nullptr )
  {
    v15 = &v26;
    p_flags = &blendParms[-1].parms.flags;
    for ( i = 5; i != 0; --i )
    {
      p_flags += 4;
      v15 += 4;
      *(_DWORD *)v15 = *(_DWORD *)p_flags;
    }
  }
  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->thirdPersonHands) == nullptr )
  {
    if ( loop )
      v22 = "true";
    else
      v22 = "false";
    Duration = (__int16)blendParms_t::GetDuration(this: v27);
    v24 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idLib::Printf(
      fmt: "(%d)%s: <UNKNOWN>, loop = %s, durationMS = %d, blend frames = %d\n",
      v24,
      "idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim",
      v22,
      durationMS,
      Duration);
    return v14;
  }
  if ( loop )
    v18 = "true";
  else
    v18 = "false";
  v25[0] = alias->value;
  v19 = animation->FindAliasName(this: animation, a2: v25);
  v20 = (__int16)blendParms_t::GetDuration(this: v27);
  v21 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idLib::Printf(
    fmt: "(%d)%s: <%s>, loop = %s, durationMS = %d, blend frames = %d\n",
    v21,
    "idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim",
    v19,
    v18,
    durationMS,
    v20);
  return v14;
}


// ========================================================================
// ?PlayerBehavior_Shared_QueueThirdPersonHandsAnim@idPlayer@@QAA_NABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_NHPBVblendParms_t@@M@Z
// EA  : 0x82E3C1D0
// RVA : 0x00E3C1D0
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_Shared_QueueThirdPersonHandsAnim(
        idPlayer *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *alias,
        bool loop,
        int durationMS,
        const blendParms_t *blendParms,
        double rateScale)
{
  idAlignedEntity *thirdPersonHands; // r3
  char *v13; // r10
  char *p_flags; // r11
  int i; // ctr
  const char *v16; // r31
  const char *v17; // r30
  int v18; // r29
  int v19; // r3
  const char *v20; // r31
  int Duration; // r30
  int v22; // r3
  unsigned __int16 v23[6]; // [sp+50h] [-60h] BYREF
  char v24; // [sp+5Ch] [-54h] BYREF
  blendParms_t v25[4]; // [sp+60h] [-50h] BYREF

  thirdPersonHands = this->thirdPersonHands;
  if ( thirdPersonHands == nullptr )
  {
    idLib::Warning(
      fmt: "%s: third person hands model not present",
      "idPlayer::PlayerBehavior_Shared_QueueThirdPersonHandsAnim");
    return 0;
  }
  if ( pb_EnableThirdPersonHands.valueInteger == 0 )
    return 0;
  idAlignedEntity::QueueAnim(
    this: thirdPersonHands,
    aliasHandle: alias,
    loop,
    durationMS,
    _blendParms: blendParms,
    rateScale);
  if ( pb_TraceHandsAnims.valueInteger == 0 )
    return 1;
  blendParms_t::blendParms_t(this: v25);
  if ( blendParms != nullptr )
  {
    v13 = &v24;
    p_flags = &blendParms[-1].parms.flags;
    for ( i = 5; i != 0; --i )
    {
      p_flags += 4;
      v13 += 4;
      *(_DWORD *)v13 = *(_DWORD *)p_flags;
    }
  }
  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->thirdPersonHands) == nullptr )
  {
    if ( loop )
      v20 = "true";
    else
      v20 = "false";
    Duration = (__int16)blendParms_t::GetDuration(this: v25);
    v22 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idLib::Printf(
      fmt: "(%d)%s: <UNKNOWN>, loop = %s, durationMS = %d, blend frames = %d\n",
      v22,
      "idPlayer::PlayerBehavior_Shared_QueueThirdPersonHandsAnim",
      v20,
      durationMS,
      Duration);
    return 1;
  }
  if ( loop )
    v16 = "true";
  else
    v16 = "false";
  v23[0] = alias->value;
  v17 = animation->FindAliasName(this: animation, a2: v23);
  v18 = (__int16)blendParms_t::GetDuration(this: v25);
  v19 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idLib::Printf(
    fmt: "(%d)%s: <%s>, loop = %s, durationMS = %d, blend frames = %d\n",
    v19,
    "idPlayer::PlayerBehavior_Shared_QueueThirdPersonHandsAnim",
    v17,
    v16,
    durationMS,
    v18);
  return 1;
}


// ========================================================================
// ?PlayerBehavior_Shared_HandleThirdPersonHandsAnim@idPlayer@@QAAXXZ
// EA  : 0x82E3C3B8
// RVA : 0x00E3C3B8
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_HandleThirdPersonHandsAnim(idPlayer *this)
{
  idAlignedEntity *thirdPersonHands; // r11
  idAlignedEntity *v3; // r31
  float *v4; // r11
  int v5; // r3
  idAlignedEntity *v6; // r31
  char v7; // r29
  idPresentable *v8; // r11
  int thirdPersonHandsFlags; // r11
  int v10; // r11
  int v11; // r11
  unsigned __int8 v12; // r11
  int v13; // r29
  idAlignedEntity *v14; // r31
  idPresentable *v15; // r11
  idAlignedEntity *v16; // r31
  idPresentable *v17; // r11
  idAlignedEntity *v18; // r31
  idPresentable *v19; // r11
  idAlignedEntity *v20; // r31
  idPresentable *presentable; // r11
  float v22; // [sp+50h] [-30h]
  float v23; // [sp+54h] [-2Ch]
  float v24; // [sp+58h] [-28h]

  thirdPersonHands = this->thirdPersonHands;
  if ( thirdPersonHands == nullptr )
    return;
  if ( ((unsigned __int8 (*)(void))thirdPersonHands->IsAnimating)() != 0 && (v3 = this->thirdPersonHands)->okToShow )
  {
    if ( pb_EnableThirdPersonHands.valueInteger == 0 )
    {
      idAlignedEntity::StopAnim(this: v3);
LABEL_33:
      v20 = this->thirdPersonHands;
      presentable = v20->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonHands);
        presentable = v20->presentable;
      }
      presentable->Hide(this: presentable, a2: true);
      return;
    }
    if ( pb_TraceHandsPos.valueInteger != 0 )
    {
      v4 = (float *)v3->presentable;
      if ( v4 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonHands);
        v4 = (float *)v3->presentable;
      }
      v22 = v4[30];
      v23 = v4[31];
      v24 = v4[32];
      v5 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s: handsPos=(%0.2f,%0.2f,%0.2f)\n",
        v5,
        "idPlayer::PlayerBehavior_Shared_HandleThirdPersonHandsAnim",
        v22,
        v23,
        v24);
    }
    v6 = this->thirdPersonHands;
    v7 = 1;
    v8 = v6->presentable;
    if ( v8 == nullptr )
    {
      idEntity::InitPresentableInternal(this: this->thirdPersonHands);
      v8 = v6->presentable;
    }
    v8->Present(this: v8);
  }
  else
  {
    thirdPersonHandsFlags = this->behaviors.shared.thirdPersonHandsFlags;
    v7 = 0;
    if ( (thirdPersonHandsFlags & 1) != 0 )
      this->behaviors.shared.thirdPersonHandsFlags = thirdPersonHandsFlags & 0xFFFFFFFE;
    v10 = this->behaviors.shared.thirdPersonHandsFlags;
    if ( (v10 & 2) != 0 )
      this->behaviors.shared.thirdPersonHandsFlags = v10 & 0xFFFFFFFD;
    v11 = this->behaviors.shared.thirdPersonHandsFlags;
    if ( (v11 & 4) != 0 )
      this->behaviors.shared.thirdPersonHandsFlags = v11 & 0xFFFFFFFB;
  }
  if ( pb_ForceShowThirdPersonHands.valueInteger != 0 )
    v12 = 1;
  else
    v12 = pb_ShowThirdPersonHands.valueInteger == 0 ? 0 : v7;
  v13 = v12;
  if ( v12 != 0 )
  {
    v14 = this->thirdPersonHands;
    v15 = v14->presentable;
    if ( v15 == nullptr )
    {
      idEntity::InitPresentableInternal(this: this->thirdPersonHands);
      v15 = v14->presentable;
    }
    if ( v15->hidden )
    {
      v16 = this->thirdPersonHands;
      v17 = v16->presentable;
      if ( v17 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonHands);
        v17 = v16->presentable;
      }
      v17->Show(this: v17);
      return;
    }
    if ( v13 != 0 )
      return;
  }
  v18 = this->thirdPersonHands;
  v19 = v18->presentable;
  if ( v19 == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->thirdPersonHands);
    v19 = v18->presentable;
  }
  if ( !v19->hidden )
    goto LABEL_33;
}


// ========================================================================
// ?PlayerBehavior_Shared_AlignThirdPersonHandsAlignNode@idPlayer@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82E3C660
// RVA : 0x00E3C660
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsAlignNode(
        idPlayer *this,
        const idVec3 *origin,
        idMat3 *axis)
{
  idAlignedEntity *thirdPersonHands; // r31
  idPresentable *presentable; // r11
  float y; // r9
  float z; // r8
  idGameLocal_vtbl *v10; // r7
  int v11; // r3
  idAlignedEntity *v12; // r31
  idAngles *v13; // r11
  double v14; // fp31
  double v15; // fp30
  double x; // fp29
  int v17; // r3
  idAlignedEntity *v18; // r31
  idPresentable *v19; // r11
  float v20; // r9
  float v21; // r8
  idGameLocal_vtbl *v22; // r7
  int v23; // r3
  idAlignedEntity *v24; // r31
  idAngles *v25; // r11
  double v26; // fp31
  double v27; // fp30
  double v28; // fp29
  int v29; // r3
  idMat3 v30[3]; // [sp+50h] [-70h] BYREF

  thirdPersonHands = this->thirdPersonHands;
  if ( thirdPersonHands != nullptr )
  {
    if ( pb_TraceHandsPos.valueInteger > 1 )
    {
      presentable = thirdPersonHands->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonHands);
        presentable = thirdPersonHands->presentable;
      }
      y = presentable->origin.y;
      z = presentable->origin.z;
      v10 = gameLocal->__vftable;
      v30[0].mat[0].x = presentable->origin.x;
      v30[0].mat[0].y = y;
      v30[0].mat[0].z = z;
      v11 = v10->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s: pre handsPos=(%0.2f,%0.2f,%0.2f)\n",
        v11,
        "idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsAlignNode",
        v30[0].mat[0].x,
        v30[0].mat[0].y,
        v30[0].mat[0].z);
    }
    if ( pb_TraceHandsAngles.valueInteger > 1 )
    {
      v12 = this->thirdPersonHands;
      v13 = (idAngles *)v12->presentable;
      if ( v13 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonHands);
        v13 = (idAngles *)v12->presentable;
      }
      idMat3::ToAngles(this: v30, result: v13 + 11);
      v14 = v30[0].mat[0].z;
      v15 = v30[0].mat[0].y;
      x = v30[0].mat[0].x;
      v17 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(fmt: "(%d)%s: pre handsAngles=(%0.2f,%0.2f,%0.2f)\n", v17, (const char *)HIDWORD(x), x, v15, v14);
    }
    this->behaviors.shared.thirdPersonHandsFlags &= ~1u;
    idAlignedEntity::Align(this: this->thirdPersonHands, origin, axis, alignMode: ALIGN_NODE_POS_ALIGN_NODE_AXIS);
    if ( pb_TraceHandsPos.valueInteger != 0 )
    {
      v18 = this->thirdPersonHands;
      v19 = v18->presentable;
      if ( v19 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonHands);
        v19 = v18->presentable;
      }
      v20 = v19->origin.y;
      v21 = v19->origin.z;
      v22 = gameLocal->__vftable;
      v30[0].mat[0].x = v19->origin.x;
      v30[0].mat[0].y = v20;
      v30[0].mat[0].z = v21;
      v23 = v22->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s: post handsPos=(%0.2f,%0.2f,%0.2f)\n",
        v23,
        "idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsAlignNode",
        v30[0].mat[0].x,
        v30[0].mat[0].y,
        v30[0].mat[0].z);
    }
    if ( pb_TraceHandsAngles.valueInteger != 0 )
    {
      v24 = this->thirdPersonHands;
      v25 = (idAngles *)v24->presentable;
      if ( v25 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonHands);
        v25 = (idAngles *)v24->presentable;
      }
      idMat3::ToAngles(this: v30, result: v25 + 11);
      v26 = v30[0].mat[0].z;
      v27 = v30[0].mat[0].y;
      v28 = v30[0].mat[0].x;
      v29 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s: post handsAngles=(%0.2f,%0.2f,%0.2f)\n",
        v29,
        "idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsAlignNode",
        v28,
        v27,
        v26);
    }
  }
  else
  {
    idLib::Warning(
      fmt: "%s: third person hands model not present",
      "idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsAlignNode");
  }
}


// ========================================================================
// ?PlayerBehavior_Shared_AlignThirdPersonHandsToPlayer@idPlayer@@QAAXXZ
// EA  : 0x82E3C938
// RVA : 0x00E3C938
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsToPlayer(idPlayer *this)
{
  idAlignedEntity *thirdPersonHands; // r31
  idPresentable *presentable; // r11
  float y; // r9
  float z; // r8
  idGameLocal_vtbl *v6; // r7
  int v7; // r3
  idAlignedEntity *v8; // r31
  idAngles *v9; // r11
  double v10; // fp31
  double v11; // fp30
  double x; // fp29
  int v13; // r3
  idPhysics *Physics; // r3
  const idVec3 *v15; // r3
  idAlignedEntity *v16; // r31
  idPresentable *v17; // r11
  float v18; // r9
  float v19; // r8
  idGameLocal_vtbl *v20; // r7
  int v21; // r3
  idAlignedEntity *v22; // r31
  idAngles *v23; // r11
  double v24; // fp31
  double v25; // fp30
  double v26; // fp29
  int v27; // r3
  idMat3 v28[2]; // [sp+50h] [-60h] BYREF

  thirdPersonHands = this->thirdPersonHands;
  if ( thirdPersonHands != nullptr )
  {
    if ( pb_TraceHandsPos.valueInteger > 1 )
    {
      presentable = thirdPersonHands->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonHands);
        presentable = thirdPersonHands->presentable;
      }
      y = presentable->origin.y;
      z = presentable->origin.z;
      v6 = gameLocal->__vftable;
      v28[0].mat[0].x = presentable->origin.x;
      v28[0].mat[0].y = y;
      v28[0].mat[0].z = z;
      v7 = v6->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s: pre handsPos=(%0.2f,%0.2f,%0.2f)\n",
        v7,
        "idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsToPlayer",
        v28[0].mat[0].x,
        v28[0].mat[0].y,
        v28[0].mat[0].z);
    }
    if ( pb_TraceHandsAngles.valueInteger > 1 )
    {
      v8 = this->thirdPersonHands;
      v9 = (idAngles *)v8->presentable;
      if ( v9 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonHands);
        v9 = (idAngles *)v8->presentable;
      }
      idMat3::ToAngles(this: v28, result: v9 + 11);
      v10 = v28[0].mat[0].z;
      v11 = v28[0].mat[0].y;
      x = v28[0].mat[0].x;
      v13 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(fmt: "(%d)%s: pre handsAngles=(%0.2f,%0.2f,%0.2f)\n", v13, (const char *)HIDWORD(x), x, v11, v10);
    }
    Physics = idEntity::GetPhysics(this);
    v15 = Physics->GetOrigin(this: Physics, a2: 0);
    idPlayer::PlayerBehavior_Shared_AlignEntityOrigin(this, ent: this->thirdPersonHands, origin: v15);
    if ( pb_TraceHandsPos.valueInteger != 0 )
    {
      v16 = this->thirdPersonHands;
      v17 = v16->presentable;
      if ( v17 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonHands);
        v17 = v16->presentable;
      }
      v18 = v17->origin.y;
      v19 = v17->origin.z;
      v20 = gameLocal->__vftable;
      v28[0].mat[0].x = v17->origin.x;
      v28[0].mat[0].y = v18;
      v28[0].mat[0].z = v19;
      v21 = v20->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s: post handsPos=(%0.2f,%0.2f,%0.2f)\n",
        v21,
        "idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsToPlayer",
        v28[0].mat[0].x,
        v28[0].mat[0].y,
        v28[0].mat[0].z);
    }
    if ( pb_TraceHandsAngles.valueInteger != 0 )
    {
      v22 = this->thirdPersonHands;
      v23 = (idAngles *)v22->presentable;
      if ( v23 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonHands);
        v23 = (idAngles *)v22->presentable;
      }
      idMat3::ToAngles(this: v28, result: v23 + 11);
      v24 = v28[0].mat[0].z;
      v25 = v28[0].mat[0].y;
      v26 = v28[0].mat[0].x;
      v27 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s: post handsAngles=(%0.2f,%0.2f,%0.2f)\n",
        v27,
        "idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsToPlayer",
        v26,
        v25,
        v24);
    }
  }
  else
  {
    idLib::Warning(
      fmt: "%s: third person hands model not present",
      "idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsToPlayer");
  }
}


// ========================================================================
// ?PlayerBehavior_Shared_AutoApplyThirdPersonHandsAnimDeltas@idPlayer@@QAAX_N0@Z
// EA  : 0x82E3CC10
// RVA : 0x00E3CC10
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_AutoApplyThirdPersonHandsAnimDeltas(
        idPlayer *this,
        bool applyToPlayer,
        bool clip)
{
  int thirdPersonHandsFlags; // r11
  int v4; // r11
  int v5; // r10
  int v6; // r11
  int v7; // r10

  thirdPersonHandsFlags = this->behaviors.shared.thirdPersonHandsFlags;
  if ( (thirdPersonHandsFlags & 2) == 0 )
    this->behaviors.shared.thirdPersonHandsFlags = thirdPersonHandsFlags | 0x20;
  v4 = this->behaviors.shared.thirdPersonHandsFlags;
  v5 = v4 | 2;
  if ( !applyToPlayer )
    v5 = v4 & 0xFFFFFFFD;
  this->behaviors.shared.thirdPersonHandsFlags = v5;
  v6 = v5;
  v7 = v5 | 4;
  if ( !clip )
    v7 = v6 & 0xFFFFFFFB;
  this->behaviors.shared.thirdPersonHandsFlags = v7;
}


// ========================================================================
// ?PlayerBehavior_Shared_PlayThirdPersonLegsAnim@idPlayer@@QAAXPBD_NHPBVblendParms_t@@M@Z
// EA  : 0x82E3CC68
// RVA : 0x00E3CC68
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        idPlayer *this,
        const char *animName,
        bool loop,
        int durationMS,
        const blendParms_t *blendParms,
        double rateScale)
{
  idAlignedEntity *thirdPersonLegs; // r3
  char *v11; // r10
  char *p_flags; // r11
  int i; // ctr
  const char *v14; // r31
  int Duration; // r30
  int v16; // r3
  char v17; // [sp+4Ch] [-44h] BYREF
  blendParms_t v18[3]; // [sp+50h] [-40h] BYREF

  thirdPersonLegs = this->thirdPersonLegs;
  if ( thirdPersonLegs != nullptr )
  {
    if ( pb_EnableThirdPersonLegs.valueInteger != 0 )
    {
      idAlignedEntity::PlayAnim(
        this: thirdPersonLegs,
        aliasName: animName,
        loop,
        durationMS,
        _blendParms: blendParms,
        rateScale);
      accumulatedLegsAnimDeltaPos.x = vec3_origin.x;
      accumulatedLegsAnimDeltaAngles.pitch = ang_zero.pitch;
      accumulatedLegsAnimDeltaPos.y = vec3_origin.y;
      accumulatedLegsAnimDeltaPos.z = vec3_origin.z;
      accumulatedLegsAnimDeltaAngles.yaw = ang_zero.yaw;
      accumulatedLegsAnimDeltaAngles.roll = ang_zero.roll;
      if ( pb_TraceLegsAnims.valueInteger != 0 )
      {
        blendParms_t::blendParms_t(this: v18);
        if ( blendParms != nullptr )
        {
          v11 = &v17;
          p_flags = &blendParms[-1].parms.flags;
          for ( i = 5; i != 0; --i )
          {
            p_flags += 4;
            v11 += 4;
            *(_DWORD *)v11 = *(_DWORD *)p_flags;
          }
        }
        if ( loop )
          v14 = "true";
        else
          v14 = "false";
        Duration = (__int16)blendParms_t::GetDuration(this: v18);
        v16 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "(%d)%s: <%s>, loop = %s, durationMS = %d, blend frames = %d\n",
          v16,
          "idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim",
          animName,
          v14,
          durationMS,
          Duration);
      }
    }
  }
  else
  {
    idLib::Warning(
      fmt: "%s: third person legs model not present",
      "idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim");
  }
}


// ========================================================================
// ?PlayerBehavior_Shared_PlayThirdPersonLegsAnim@idPlayer@@QAA_NABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_NHPBVblendParms_t@@M@Z
// EA  : 0x82E3CDE0
// RVA : 0x00E3CDE0
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        idPlayer *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *alias,
        bool loop,
        int durationMS,
        const blendParms_t *blendParms,
        double rateScale)
{
  idAlignedEntity *thirdPersonLegs; // r3
  int v13; // r3
  int v14; // r26
  char *v15; // r10
  char *p_flags; // r11
  int i; // ctr
  const char *v18; // r31
  const char *v19; // r30
  int v20; // r29
  int v21; // r3
  const char *v22; // r31
  int Duration; // r30
  int v24; // r3
  unsigned __int16 v25[6]; // [sp+50h] [-60h] BYREF
  char v26; // [sp+5Ch] [-54h] BYREF
  blendParms_t v27[4]; // [sp+60h] [-50h] BYREF

  thirdPersonLegs = this->thirdPersonLegs;
  if ( thirdPersonLegs == nullptr )
  {
    idLib::Warning(
      fmt: "%s: third person legs model not present",
      "idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim");
    return 0;
  }
  if ( pb_EnableThirdPersonLegs.valueInteger == 0 )
    return 0;
  v13 = idAlignedEntity::PlayAnim(
          this: thirdPersonLegs,
          aliasHandle: alias,
          loop,
          durationMS,
          _blendParms: blendParms,
          rateScale);
  accumulatedLegsAnimDeltaPos.x = vec3_origin.x;
  accumulatedLegsAnimDeltaAngles.pitch = ang_zero.pitch;
  v14 = v13;
  accumulatedLegsAnimDeltaPos.y = vec3_origin.y;
  accumulatedLegsAnimDeltaPos.z = vec3_origin.z;
  accumulatedLegsAnimDeltaAngles.yaw = ang_zero.yaw;
  accumulatedLegsAnimDeltaAngles.roll = ang_zero.roll;
  if ( pb_TraceLegsAnims.valueInteger == 0 )
    return v14;
  blendParms_t::blendParms_t(this: v27);
  if ( blendParms != nullptr )
  {
    v15 = &v26;
    p_flags = &blendParms[-1].parms.flags;
    for ( i = 5; i != 0; --i )
    {
      p_flags += 4;
      v15 += 4;
      *(_DWORD *)v15 = *(_DWORD *)p_flags;
    }
  }
  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->thirdPersonLegs) == nullptr )
  {
    if ( loop )
      v22 = "true";
    else
      v22 = "false";
    Duration = (__int16)blendParms_t::GetDuration(this: v27);
    v24 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idLib::Printf(
      fmt: "(%d)%s: <UNKNOWN>, loop = %s, durationMS = %d, blend frames = %d\n",
      v24,
      "idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim",
      v22,
      durationMS,
      Duration);
    return v14;
  }
  if ( loop )
    v18 = "true";
  else
    v18 = "false";
  v25[0] = alias->value;
  v19 = animation->FindAliasName(this: animation, a2: v25);
  v20 = (__int16)blendParms_t::GetDuration(this: v27);
  v21 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idLib::Printf(
    fmt: "(%d)%s: <%s>, loop = %s, durationMS = %d, blend frames = %d\n",
    v21,
    "idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim",
    v19,
    v18,
    durationMS,
    v20);
  return v14;
}


// ========================================================================
// ?PlayerBehavior_Shared_QueueThirdPersonLegsAnim@idPlayer@@QAAXPBD_NHPBVblendParms_t@@M@Z
// EA  : 0x82E3D018
// RVA : 0x00E3D018
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_QueueThirdPersonLegsAnim(
        idPlayer *this,
        const char *animName,
        bool loop,
        int durationMS,
        const blendParms_t *blendParms,
        double rateScale)
{
  idAlignedEntity *thirdPersonLegs; // r3
  char *v11; // r10
  char *p_flags; // r11
  int i; // ctr
  const char *v14; // r31
  int Duration; // r30
  int v16; // r3
  char v17; // [sp+4Ch] [-44h] BYREF
  blendParms_t v18[3]; // [sp+50h] [-40h] BYREF

  thirdPersonLegs = this->thirdPersonLegs;
  if ( thirdPersonLegs != nullptr )
  {
    if ( pb_EnableThirdPersonLegs.valueInteger != 0 )
    {
      idAlignedEntity::QueueAnim(
        this: thirdPersonLegs,
        aliasName: animName,
        loop,
        durationMS,
        _blendParms: blendParms,
        rateScale);
      if ( pb_TraceLegsAnims.valueInteger != 0 )
      {
        blendParms_t::blendParms_t(this: v18);
        if ( blendParms != nullptr )
        {
          v11 = &v17;
          p_flags = &blendParms[-1].parms.flags;
          for ( i = 5; i != 0; --i )
          {
            p_flags += 4;
            v11 += 4;
            *(_DWORD *)v11 = *(_DWORD *)p_flags;
          }
        }
        if ( loop )
          v14 = "true";
        else
          v14 = "false";
        Duration = (__int16)blendParms_t::GetDuration(this: v18);
        v16 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "(%d)%s: <%s>, loop = %s, durationMS = %d, blend frames = %d\n",
          v16,
          "idPlayer::PlayerBehavior_Shared_QueueThirdPersonLegsAnim",
          animName,
          v14,
          durationMS,
          Duration);
      }
    }
  }
  else
  {
    idLib::Warning(
      fmt: "%s: third person legs model not present",
      "idPlayer::PlayerBehavior_Shared_QueueThirdPersonLegsAnim");
  }
}


// ========================================================================
// ?PlayerBehavior_Shared_QueueThirdPersonLegsAnim@idPlayer@@QAA_NABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_NHPBVblendParms_t@@M@Z
// EA  : 0x82E3D140
// RVA : 0x00E3D140
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_Shared_QueueThirdPersonLegsAnim(
        idPlayer *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *alias,
        bool loop,
        int durationMS,
        const blendParms_t *blendParms,
        double rateScale)
{
  idAlignedEntity *thirdPersonLegs; // r3
  char *v13; // r10
  char *p_flags; // r11
  int i; // ctr
  const char *v16; // r31
  const char *v17; // r30
  int v18; // r29
  int v19; // r3
  const char *v20; // r31
  int Duration; // r30
  int v22; // r3
  unsigned __int16 v23[6]; // [sp+50h] [-60h] BYREF
  char v24; // [sp+5Ch] [-54h] BYREF
  blendParms_t v25[4]; // [sp+60h] [-50h] BYREF

  thirdPersonLegs = this->thirdPersonLegs;
  if ( thirdPersonLegs == nullptr )
  {
    idLib::Warning(
      fmt: "%s: third person legs model not present",
      "idPlayer::PlayerBehavior_Shared_QueueThirdPersonLegsAnim");
    return 0;
  }
  if ( pb_EnableThirdPersonLegs.valueInteger == 0 )
    return 0;
  idAlignedEntity::QueueAnim(
    this: thirdPersonLegs,
    aliasHandle: alias,
    loop,
    durationMS,
    _blendParms: blendParms,
    rateScale);
  if ( pb_TraceLegsAnims.valueInteger == 0 )
    return 1;
  blendParms_t::blendParms_t(this: v25);
  if ( blendParms != nullptr )
  {
    v13 = &v24;
    p_flags = &blendParms[-1].parms.flags;
    for ( i = 5; i != 0; --i )
    {
      p_flags += 4;
      v13 += 4;
      *(_DWORD *)v13 = *(_DWORD *)p_flags;
    }
  }
  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->thirdPersonLegs) == nullptr )
  {
    if ( loop )
      v20 = "true";
    else
      v20 = "false";
    Duration = (__int16)blendParms_t::GetDuration(this: v25);
    v22 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idLib::Printf(
      fmt: "(%d)%s: <UNKNOWN>, loop = %s, durationMS = %d, blend frames = %d\n",
      v22,
      "idPlayer::PlayerBehavior_Shared_QueueThirdPersonLegsAnim",
      v20,
      durationMS,
      Duration);
    return 1;
  }
  if ( loop )
    v16 = "true";
  else
    v16 = "false";
  v23[0] = alias->value;
  v17 = animation->FindAliasName(this: animation, a2: v23);
  v18 = (__int16)blendParms_t::GetDuration(this: v25);
  v19 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idLib::Printf(
    fmt: "(%d)%s: <%s>, loop = %s, durationMS = %d, blend frames = %d\n",
    v19,
    "idPlayer::PlayerBehavior_Shared_QueueThirdPersonLegsAnim",
    v17,
    v16,
    durationMS,
    v18);
  return 1;
}


// ========================================================================
// ?PlayerBehavior_Shared_HandleThirdPersonLegsAnim@idPlayer@@QAAXXZ
// EA  : 0x82E3D328
// RVA : 0x00E3D328
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_HandleThirdPersonLegsAnim(idPlayer *this)
{
  idAlignedEntity *thirdPersonLegs; // r11
  idAlignedEntity *v3; // r31
  idPresentable *v4; // r11
  float y; // r9
  float z; // r8
  idGameLocal_vtbl *v7; // r7
  int v8; // r3
  idAlignedEntity *v9; // r31
  idAngles *v10; // r11
  double v11; // fp31
  double v12; // fp30
  double x; // fp29
  int v14; // r3
  idAlignedEntity *v15; // r31
  char v16; // r30
  idPresentable *v17; // r11
  int thirdPersonLegsFlags; // r11
  int v19; // r11
  int v20; // r11
  unsigned __int8 v21; // r11
  int v22; // r30
  idAlignedEntity *v23; // r31
  idPresentable *v24; // r11
  idAlignedEntity *v25; // r31
  idPresentable *v26; // r11
  idAlignedEntity *v27; // r31
  idPresentable *v28; // r11
  idAlignedEntity *v29; // r31
  idPresentable *presentable; // r11
  idMat3 v31; // [sp+50h] [-50h] BYREF

  thirdPersonLegs = this->thirdPersonLegs;
  if ( thirdPersonLegs == nullptr )
    return;
  if ( ((unsigned __int8 (*)(void))thirdPersonLegs->IsAnimating)() != 0 && (v3 = this->thirdPersonLegs)->okToShow )
  {
    if ( pb_EnableThirdPersonLegs.valueInteger == 0 )
    {
      idAlignedEntity::StopAnim(this: v3);
LABEL_37:
      v29 = this->thirdPersonLegs;
      presentable = v29->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
        presentable = v29->presentable;
      }
      presentable->Hide(this: presentable, a2: true);
      return;
    }
    if ( pb_TraceLegsPos.valueInteger != 0 )
    {
      v4 = v3->presentable;
      if ( v4 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
        v4 = v3->presentable;
      }
      y = v4->origin.y;
      z = v4->origin.z;
      v7 = gameLocal->__vftable;
      v31.mat[0].x = v4->origin.x;
      v31.mat[0].y = y;
      v31.mat[0].z = z;
      v8 = v7->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s: legsPos=(%0.2f,%0.2f,%0.2f)\n",
        v8,
        "idPlayer::PlayerBehavior_Shared_HandleThirdPersonLegsAnim",
        v31.mat[0].x,
        v31.mat[0].y,
        v31.mat[0].z);
    }
    if ( pb_TraceLegsAngles.valueInteger != 0 )
    {
      v9 = this->thirdPersonLegs;
      v10 = (idAngles *)v9->presentable;
      if ( v10 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
        v10 = (idAngles *)v9->presentable;
      }
      idMat3::ToAngles(this: &v31, result: v10 + 11);
      v11 = v31.mat[0].z;
      v12 = v31.mat[0].y;
      x = v31.mat[0].x;
      v14 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(fmt: "(%d)%s: legsAngles=(%0.2f,%0.2f,%0.2f)\n", v14, (const char *)HIDWORD(x), x, v12, v11);
    }
    v15 = this->thirdPersonLegs;
    v16 = 1;
    v17 = v15->presentable;
    if ( v17 == nullptr )
    {
      idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
      v17 = v15->presentable;
    }
    v17->Present(this: v17);
  }
  else
  {
    thirdPersonLegsFlags = this->behaviors.shared.thirdPersonLegsFlags;
    v16 = 0;
    if ( (thirdPersonLegsFlags & 1) != 0 )
      this->behaviors.shared.thirdPersonLegsFlags = thirdPersonLegsFlags & 0xFFFFFFFE;
    v19 = this->behaviors.shared.thirdPersonLegsFlags;
    if ( (v19 & 2) != 0 )
      this->behaviors.shared.thirdPersonLegsFlags = v19 & 0xFFFFFFFD;
    v20 = this->behaviors.shared.thirdPersonLegsFlags;
    if ( (v20 & 4) != 0 )
      this->behaviors.shared.thirdPersonLegsFlags = v20 & 0xFFFFFFFB;
  }
  if ( pb_ForceShowThirdPersonLegs.valueInteger != 0 )
    v21 = 1;
  else
    v21 = pb_ShowThirdPersonLegs.valueInteger == 0 ? 0 : v16;
  v22 = v21;
  if ( v21 != 0 )
  {
    v23 = this->thirdPersonLegs;
    v24 = v23->presentable;
    if ( v24 == nullptr )
    {
      idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
      v24 = v23->presentable;
    }
    if ( v24->hidden )
    {
      v25 = this->thirdPersonLegs;
      v26 = v25->presentable;
      if ( v26 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
        v26 = v25->presentable;
      }
      v26->Show(this: v26);
      return;
    }
    if ( v22 != 0 )
      return;
  }
  v27 = this->thirdPersonLegs;
  v28 = v27->presentable;
  if ( v28 == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
    v28 = v27->presentable;
  }
  if ( !v28->hidden )
    goto LABEL_37;
}


// ========================================================================
// ?PlayerBehavior_Shared_StopThirdPersonLegsAnim@idPlayer@@QAAXXZ
// EA  : 0x82E3D690
// RVA : 0x00E3D690
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_StopThirdPersonLegsAnim(idPlayer *this)
{
  idAlignedEntity *thirdPersonLegs; // r31
  idPresentable *presentable; // r3

  thirdPersonLegs = this->thirdPersonLegs;
  if ( thirdPersonLegs != nullptr )
  {
    presentable = thirdPersonLegs->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: thirdPersonLegs);
      presentable = thirdPersonLegs->presentable;
    }
    presentable->Hide(this: presentable, a2: true);
    idAlignedEntity::StopAnim(this: this->thirdPersonLegs);
  }
}


// ========================================================================
// ?PlayerBehavior_Shared_AlignThirdPersonLegsAlignNode@idPlayer@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82E3D700
// RVA : 0x00E3D700
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsAlignNode(
        idPlayer *this,
        const idVec3 *origin,
        idMat3 *axis)
{
  idAlignedEntity *thirdPersonLegs; // r31
  idPresentable *presentable; // r11
  float y; // r9
  float z; // r8
  idGameLocal_vtbl *v10; // r7
  int v11; // r3
  idAlignedEntity *v12; // r31
  idAngles *v13; // r11
  double v14; // fp31
  double v15; // fp30
  double x; // fp29
  int v17; // r3
  idAlignedEntity *v18; // r31
  idPresentable *v19; // r11
  float v20; // r9
  float v21; // r8
  idGameLocal_vtbl *v22; // r7
  int v23; // r3
  idAlignedEntity *v24; // r31
  idAngles *v25; // r11
  double v26; // fp31
  double v27; // fp30
  double v28; // fp29
  int v29; // r3
  idMat3 v30[3]; // [sp+50h] [-70h] BYREF

  thirdPersonLegs = this->thirdPersonLegs;
  if ( thirdPersonLegs != nullptr )
  {
    if ( pb_TraceLegsPos.valueInteger > 1 )
    {
      presentable = thirdPersonLegs->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
        presentable = thirdPersonLegs->presentable;
      }
      y = presentable->origin.y;
      z = presentable->origin.z;
      v10 = gameLocal->__vftable;
      v30[0].mat[0].x = presentable->origin.x;
      v30[0].mat[0].y = y;
      v30[0].mat[0].z = z;
      v11 = v10->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s: pre legsPos=(%0.2f,%0.2f,%0.2f)\n",
        v11,
        "idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsAlignNode",
        v30[0].mat[0].x,
        v30[0].mat[0].y,
        v30[0].mat[0].z);
    }
    if ( pb_TraceLegsAngles.valueInteger > 1 )
    {
      v12 = this->thirdPersonLegs;
      v13 = (idAngles *)v12->presentable;
      if ( v13 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
        v13 = (idAngles *)v12->presentable;
      }
      idMat3::ToAngles(this: v30, result: v13 + 11);
      v14 = v30[0].mat[0].z;
      v15 = v30[0].mat[0].y;
      x = v30[0].mat[0].x;
      v17 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(fmt: "(%d)%s: pre legsAngles=(%0.2f,%0.2f,%0.2f)\n", v17, (const char *)HIDWORD(x), x, v15, v14);
    }
    this->behaviors.shared.thirdPersonLegsFlags &= ~1u;
    idAlignedEntity::Align(this: this->thirdPersonLegs, origin, axis, alignMode: ALIGN_NODE_POS_ALIGN_NODE_AXIS);
    if ( pb_TraceLegsPos.valueInteger != 0 )
    {
      v18 = this->thirdPersonLegs;
      v19 = v18->presentable;
      if ( v19 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
        v19 = v18->presentable;
      }
      v20 = v19->origin.y;
      v21 = v19->origin.z;
      v22 = gameLocal->__vftable;
      v30[0].mat[0].x = v19->origin.x;
      v30[0].mat[0].y = v20;
      v30[0].mat[0].z = v21;
      v23 = v22->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s: post legsPos=(%0.2f,%0.2f,%0.2f)\n",
        v23,
        "idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsAlignNode",
        v30[0].mat[0].x,
        v30[0].mat[0].y,
        v30[0].mat[0].z);
    }
    if ( pb_TraceLegsAngles.valueInteger != 0 )
    {
      v24 = this->thirdPersonLegs;
      v25 = (idAngles *)v24->presentable;
      if ( v25 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
        v25 = (idAngles *)v24->presentable;
      }
      idMat3::ToAngles(this: v30, result: v25 + 11);
      v26 = v30[0].mat[0].z;
      v27 = v30[0].mat[0].y;
      v28 = v30[0].mat[0].x;
      v29 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s: post legsAngles=(%0.2f,%0.2f,%0.2f)\n",
        v29,
        "idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsAlignNode",
        v28,
        v27,
        v26);
    }
  }
  else
  {
    idLib::Warning(
      fmt: "%s: third person legs model not present",
      "idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsAlignNode");
  }
}


// ========================================================================
// ?PlayerBehavior_Shared_AlignThirdPersonLegsToPlayer@idPlayer@@QAAXXZ
// EA  : 0x82E3D9D8
// RVA : 0x00E3D9D8
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsToPlayer(idPlayer *this)
{
  idAlignedEntity *thirdPersonLegs; // r31
  idPresentable *presentable; // r11
  float y; // r9
  float z; // r8
  idGameLocal_vtbl *v6; // r7
  int v7; // r3
  idAlignedEntity *v8; // r31
  idAngles *v9; // r11
  double v10; // fp31
  double v11; // fp30
  double x; // fp29
  int v13; // r3
  idPhysics *Physics; // r3
  const idVec3 *v15; // r3
  idAlignedEntity *v16; // r31
  idPresentable *v17; // r11
  float v18; // r9
  float v19; // r8
  idGameLocal_vtbl *v20; // r7
  int v21; // r3
  idAlignedEntity *v22; // r31
  idAngles *v23; // r11
  double v24; // fp31
  double v25; // fp30
  double v26; // fp29
  int v27; // r3
  idMat3 v28[2]; // [sp+50h] [-60h] BYREF

  thirdPersonLegs = this->thirdPersonLegs;
  if ( thirdPersonLegs != nullptr )
  {
    if ( pb_TraceLegsPos.valueInteger > 1 )
    {
      presentable = thirdPersonLegs->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
        presentable = thirdPersonLegs->presentable;
      }
      y = presentable->origin.y;
      z = presentable->origin.z;
      v6 = gameLocal->__vftable;
      v28[0].mat[0].x = presentable->origin.x;
      v28[0].mat[0].y = y;
      v28[0].mat[0].z = z;
      v7 = v6->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s: pre legsPos=(%0.2f,%0.2f,%0.2f)\n",
        v7,
        "idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsToPlayer",
        v28[0].mat[0].x,
        v28[0].mat[0].y,
        v28[0].mat[0].z);
    }
    if ( pb_TraceLegsAngles.valueInteger > 1 )
    {
      v8 = this->thirdPersonLegs;
      v9 = (idAngles *)v8->presentable;
      if ( v9 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
        v9 = (idAngles *)v8->presentable;
      }
      idMat3::ToAngles(this: v28, result: v9 + 11);
      v10 = v28[0].mat[0].z;
      v11 = v28[0].mat[0].y;
      x = v28[0].mat[0].x;
      v13 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(fmt: "(%d)%s: pre legsAngles=(%0.2f,%0.2f,%0.2f)\n", v13, (const char *)HIDWORD(x), x, v11, v10);
    }
    Physics = idEntity::GetPhysics(this);
    v15 = Physics->GetOrigin(this: Physics, a2: 0);
    idPlayer::PlayerBehavior_Shared_AlignEntityOrigin(this, ent: this->thirdPersonLegs, origin: v15);
    if ( pb_TraceLegsPos.valueInteger != 0 )
    {
      v16 = this->thirdPersonLegs;
      v17 = v16->presentable;
      if ( v17 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
        v17 = v16->presentable;
      }
      v18 = v17->origin.y;
      v19 = v17->origin.z;
      v20 = gameLocal->__vftable;
      v28[0].mat[0].x = v17->origin.x;
      v28[0].mat[0].y = v18;
      v28[0].mat[0].z = v19;
      v21 = v20->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s: post legsPos=(%0.2f,%0.2f,%0.2f)\n",
        v21,
        "idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsToPlayer",
        v28[0].mat[0].x,
        v28[0].mat[0].y,
        v28[0].mat[0].z);
    }
    if ( pb_TraceLegsAngles.valueInteger != 0 )
    {
      v22 = this->thirdPersonLegs;
      v23 = (idAngles *)v22->presentable;
      if ( v23 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
        v23 = (idAngles *)v22->presentable;
      }
      idMat3::ToAngles(this: v28, result: v23 + 11);
      v24 = v28[0].mat[0].z;
      v25 = v28[0].mat[0].y;
      v26 = v28[0].mat[0].x;
      v27 = gameLocal->GetGameFrame(this: gameLocal);
      idLib::Printf(
        fmt: "(%d)%s: post legsAngles=(%0.2f,%0.2f,%0.2f)\n",
        v27,
        "idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsToPlayer",
        v26,
        v25,
        v24);
    }
  }
  else
  {
    idLib::Warning(
      fmt: "%s: third person legs model not present",
      "idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsToPlayer");
  }
}


// ========================================================================
// ?PlayerBehavior_Shared_AutoApplyThirdPersonLegsAnimDeltas@idPlayer@@QAAX_N0@Z
// EA  : 0x82E3DCB0
// RVA : 0x00E3DCB0
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_AutoApplyThirdPersonLegsAnimDeltas(
        idPlayer *this,
        bool applyToPlayer,
        bool clip)
{
  int thirdPersonLegsFlags; // r11
  int v4; // r10
  int v5; // r9
  int v6; // r10
  int v7; // r9

  thirdPersonLegsFlags = this->behaviors.shared.thirdPersonLegsFlags;
  if ( (thirdPersonLegsFlags & 2) == 0 )
    this->behaviors.shared.thirdPersonLegsFlags = thirdPersonLegsFlags | 0x20;
  v4 = this->behaviors.shared.thirdPersonLegsFlags;
  v5 = v4 | 2;
  if ( !applyToPlayer )
    v5 = v4 & 0xFFFFFFFD;
  this->behaviors.shared.thirdPersonLegsFlags = v5;
  v6 = v5;
  v7 = v5 | 4;
  if ( !clip )
    v7 = v6 & 0xFFFFFFFB;
  this->behaviors.shared.thirdPersonLegsFlags = v7;
}


// ========================================================================
// ?PlayerBehavior_PlayerKilled@idPlayer@@QAAXXZ
// EA  : 0x82E3DD10
// RVA : 0x00E3DD10
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

// attributes: thunk
void __fastcall idPlayer::PlayerBehavior_PlayerKilled(idPlayer *this)
{
  idPlayer::PlayerBehavior_EndAllBehaviors(this);
}


// ========================================================================
// ?PlayerBehavior_Shared_ShiftIntoPosition@idPlayer@@QAA_NABVidVec3@@0M_N@Z
// EA  : 0x82E3DD18
// RVA : 0x00E3DD18
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_Shared_ShiftIntoPosition(
        idPlayer *this,
        const idVec3 *origin,
        const idVec3 *targetPos,
        double minDist,
        bool clipMovement,
        bool a6)
{
  double v6; // fp10
  int result; // r3
  double v10; // fp2
  double v13; // fp9
  double v14; // fp12
  double v15; // fp9
  double v16; // fp7
  double v17; // fp12
  double v18; // fp11
  double v21; // fp13
  double v22; // fp1
  double v23; // fp13
  double v24; // fp31
  double v25; // fp30
  double v26; // fp29
  __int64 v27; // r5
  idPresentable *presentable; // r3
  double v29; // fp12
  idPresentablePlayer *v30; // r3
  float x; // [sp+50h] [-70h]
  float y; // [sp+54h] [-6Ch]
  playerExplicitMove_t v33; // [sp+60h] [-60h] BYREF

  v6 = (float)(targetPos->z - targetPos->z);
  y = origin->y;
  x = origin->x;
  result = 0;
  v10 = (float)((float)((float)v6 * (float)v6)
              + (float)((float)((float)(targetPos->y - y) * (float)(targetPos->y - y))
                      + (float)((float)(targetPos->x - x) * (float)(targetPos->x - x))));
  _FP12 = (float)((float)((float)((float)v6 * (float)v6)
                        + (float)((float)((float)(targetPos->y - y) * (float)(targetPos->y - y))
                                + (float)((float)(targetPos->x - x) * (float)(targetPos->x - x))))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f10, f12, f2, f13 }
  v13 = __frsqrte(_FP10);
  v14 = (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v10 * (float)0.5)) * (float)v13) - (float)1.5)
              * (float)v13);
  v15 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13
                                                                              * (float)((float)v10 * (float)0.5))
                                                                      * (float)v13)
                                                              - (float)1.5)
                                              * (float)v13)
                                      * (float)((float)v10 * (float)0.5))
                              * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v10 * (float)0.5))
                                                              * (float)v13)
                                                      - (float)1.5)
                                      * (float)v13))
                      - (float)1.5);
  v16 = (float)((float)((float)-(float)((float)((float)((float)((float)v15 * (float)v14)
                                                      * (float)((float)v10 * (float)0.5))
                                              * (float)((float)v15 * (float)v14))
                                      - (float)1.5)
                      * (float)((float)v15 * (float)v14))
              * (float)v10);
  v18 = (float)((float)(targetPos->y - y)
              * (float)((float)-(float)((float)((float)((float)((float)v15 * (float)v14)
                                                      * (float)((float)v10 * (float)0.5))
                                              * (float)((float)v15 * (float)v14))
                                      - (float)1.5)
                      * (float)((float)v15 * (float)v14)));
  v17 = (float)((float)(targetPos->x - origin->x)
              * (float)((float)-(float)((float)((float)((float)((float)v15 * (float)v14)
                                                      * (float)((float)v10 * (float)0.5))
                                              * (float)((float)v15 * (float)v14))
                                      - (float)1.5)
                      * (float)((float)v15 * (float)v14)));
  if ( v16 > minDist )
  {
    _FP3 = (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f1, f3, f4, f13 }
    v21 = __frsqrte(_FP1);
    v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))
                                                                                                * (float)0.5))
                                                                                * (float)v21)
                                                                        - (float)1.5)
                                                        * (float)v21)
                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                + (float)((float)v17 * (float)v17))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v21
                                                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                                                + (float)((float)v17 * (float)v17))
                                                                                        * (float)0.5))
                                                                        * (float)v21)
                                                                - (float)1.5)
                                                * (float)v21))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v21
                                                        * (float)((float)((float)((float)v18 * (float)v18)
                                                                        + (float)((float)v17 * (float)v17))
                                                                * (float)0.5))
                                                * (float)v21)
                                        - (float)1.5)
                        * (float)v21));
    v23 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                                                * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5))
                                                                                        * (float)v21)
                                                                                - (float)1.5)
                                                                * (float)v21)
                                                        * (float)((float)((float)((float)v18 * (float)v18)
                                                                        + (float)((float)v17 * (float)v17))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v21
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))
                                                                                                * (float)0.5))
                                                                                * (float)v21)
                                                                        - (float)1.5)
                                                        * (float)v21))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v21
                                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                                + (float)((float)v17 * (float)v17))
                                                                        * (float)0.5))
                                                        * (float)v21)
                                                - (float)1.5)
                                * (float)v21))
                * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5));
    v24 = (float)((float)(pb_PlayerMoveSpeedFactor.valueFloat * (float)v16)
                * (float)((float)((float)-(float)((float)((float)v23 * (float)v22) - (float)1.5) * (float)v22)
                        * (float)v17));
    v25 = (float)((float)((float)v18
                        * (float)((float)-(float)((float)((float)v23 * (float)v22) - (float)1.5) * (float)v22))
                * (float)(pb_PlayerMoveSpeedFactor.valueFloat * (float)v16));
    v26 = (float)((float)(pb_PlayerMoveSpeedFactor.valueFloat * (float)v16)
                * (float)((float)((float)-(float)((float)((float)v23 * (float)v22) - (float)1.5) * (float)v22)
                        * (float)0.0));
    v27 = __PAIR64__(
            (volatile int (*)[2])allocationCurrent[242],
            gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED));
    presentable = this->presentable;
    v33.clipMove = a6;
    v33.overrideVelocity.x = *(float *)(HIDWORD(v27) - 16600);
    v29 = *(float *)(HIDWORD(v27) - 16600 + offsetof(idVec3, z));
    v33.overrideVelocity.y = *(float *)(HIDWORD(v27) - 16600 + offsetof(idVec3, y));
    v33.ignoreEntityNum = 0x1FFF;
    v33.overrideVelocity.z = v29;
    v33.velocityType = VEL_EXPLICIT;
    v33.delta.x = (float)((float)v24 * (float)v27) * (float)0.001;
    v33.delta.y = (float)((float)v25 * (float)v27) * (float)0.001;
    v33.delta.z = (float)((float)v26 * (float)v27) * (float)0.001;
    if ( presentable != nullptr )
      v30 = presentable->GetPlayerInterface_2(this: presentable);
    else
      v30 = nullptr;
    idPresentablePlayer::SetExplicitMove(this: v30, move: &v33, alsoAllowPhysicsMove: false, useExplicitMove2: false);
    return 1;
  }
  return result;
}


// ========================================================================
// ?PlayerBehavior_Shared_ShiftIntoPosition@idPlayer@@QAA_NABVidVec3@@M_N@Z
// EA  : 0x82E3DF48
// RVA : 0x00E3DF48
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_Shared_ShiftIntoPosition(
        idPlayer *this,
        const idVec3 *targetPos,
        double minDist,
        bool clipMovement,
        bool a5)
{
  idPresentable *presentable; // r3
  int v10; // r3
  int v11; // r3
  float v12; // r6
  float v13; // r11
  idVec3 v15; // [sp+50h] [-40h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v10 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v10 = 0;
  v11 = (*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v10 + 36264) + 64))(a1: v10 + 36264, a2: 0);
  v12 = *(float *)(v11 + 4);
  v13 = *(float *)(v11 + 8);
  v15.x = *(float *)v11;
  v15.y = v12;
  v15.z = v13;
  return idPlayer::PlayerBehavior_Shared_ShiftIntoPosition(
           this,
           origin: &v15,
           targetPos,
           minDist,
           clipMovement: SLOBYTE(v12),
           a6: a5);
}


// ========================================================================
// ?PlayerBehavior_Shared_ApplyAnimDeltas@idPlayer@@QAAXPAVidAlignedEntity@@_N1PAH@Z
// EA  : 0x82E3DFE8
// RVA : 0x00E3DFE8
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_ApplyAnimDeltas(
        idPlayer *this,
        idAlignedEntity *ent,
        bool applyToPlayer,
        bool clip,
        int *results)
{
  bool v9; // r24
  idAngles *v10; // r3
  double roll; // fp12
  double x; // fp0
  double v13; // fp7
  double v14; // fp12
  double y; // fp11
  double z; // fp10
  idList<idVec3,5> *p_animDeltasTrans; // r31
  idList<idAngles,5> *p_animDeltasRot; // r30
  __int64 v19; // r11
  int v20; // r11
  float *p_x; // r11
  int v22; // r11
  float *v23; // r3
  int v24; // r10
  int num; // r4
  double v26; // fp0
  double v27; // fp13
  int v28; // r8
  double v29; // fp12
  idVec3 *list; // r9
  double v31; // fp0
  double v32; // fp13
  idVec3 *v33; // r9
  int v34; // ctr
  int v35; // r4
  int v36; // r8
  __int64 v37; // r11
  double pitch; // fp0
  double yaw; // fp13
  double v40; // fp12
  idAngles *v41; // r9
  double v42; // fp0
  double v43; // fp13
  idAngles *v44; // r9
  int v45; // ctr
  float *v46; // r3
  idPresentable *presentable; // r3
  const idAngles *v48; // r4
  idPresentable *v49; // r3
  idPresentablePlayer *v50; // r3
  idPresentable *v51; // r3
  double v52; // fp9
  double v53; // fp0
  idPresentablePlayer *v54; // r3
  idVec3 v55; // [sp+50h] [-180h] BYREF
  idMat3 v56; // [sp+60h] [-170h] BYREF
  float v57; // [sp+84h] [-14Ch]
  float v58; // [sp+88h] [-148h]
  float v59; // [sp+8Ch] [-144h]
  float v60; // [sp+90h] [-140h]
  idMat3 v61; // [sp+98h] [-138h] BYREF
  float v62; // [sp+BCh] [-114h]
  float v63; // [sp+C0h] [-110h]
  float v64[6]; // [sp+C8h] [-108h] BYREF
  float v65[2]; // [sp+E0h] [-F0h] BYREF
  float v66; // [sp+E8h] [-E8h]
  float v67; // [sp+ECh] [-E4h]
  float v68; // [sp+F0h] [-E0h]
  float v69; // [sp+F4h] [-DCh]
  float v70; // [sp+F8h] [-D8h]
  float v71; // [sp+FCh] [-D4h]
  float v72; // [sp+100h] [-D0h]
  playerExplicitMove_t v73; // [sp+110h] [-C0h] BYREF
  char v74[24]; // [sp+138h] [-98h] BYREF
  idAngles v75[3]; // [sp+150h] [-80h] BYREF

  v9 = pb_ApplyAnimDeltasForceClip.valueInteger != 0 || pb_ApplyAnimDeltasForceNoClip.valueInteger == 0 && clip;
  if ( results != nullptr )
    *results = 0;
  idAlignedEntity::ApplyOriginDeltas(this: ent, clip: v9);
  if ( applyToPlayer && pb_ApplyAnimDeltasToPlayer.valueInteger != 0 )
  {
    idAlignedEntity::GetLastOriginDeltas(this: ent, deltaRot: (idMat3 *)&v56.mat[1].y, deltaTrans: &v55, time: nullptr);
    v10 = idMat3::ToAngles(this: &v61, result: (idAngles *)&v56.mat[1].y);
    v56.mat[0].x = v10->pitch;
    v56.mat[0].y = v10->yaw;
    roll = v10->roll;
    this->behaviors.shared.deltaTransScale.x = 1.0;
    this->behaviors.shared.deltaTransScale.y = 1.0;
    this->behaviors.shared.deltaTransScale.z = 1.0;
    x = this->behaviors.shared.deltaTransExternalWorld.x;
    v13 = (float)((float)(this->behaviors.shared.deltaTransExternalWorld.z
                        * this->behaviors.shared.deltaTransExternalWorld.z)
                + (float)((float)(this->behaviors.shared.deltaTransExternalWorld.x
                                * this->behaviors.shared.deltaTransExternalWorld.x)
                        + (float)(this->behaviors.shared.deltaTransExternalWorld.y
                                * this->behaviors.shared.deltaTransExternalWorld.y)));
    v56.mat[0].z = roll;
    if ( v13 != 0.0 )
    {
      v14 = (float)((float)x + v55.x);
      y = this->behaviors.shared.deltaTransExternalWorld.y;
      z = this->behaviors.shared.deltaTransExternalWorld.z;
      this->behaviors.shared.deltaTransExternalWorld.x = vec3_origin.x;
      this->behaviors.shared.deltaTransExternalWorld.y = vec3_origin.y;
      v55.x = v14;
      v55.y = (float)y + v55.y;
      v55.z = (float)z + v55.z;
      this->behaviors.shared.deltaTransExternalWorld.z = vec3_origin.z;
      if ( results != nullptr )
        *results |= 0x10u;
    }
    if ( this->behaviors.animDeltasTrans.num == 10 )
      idList<idAngles,5>::RemoveIndex(this: (idList<idVec3,116> *)&this->behaviors.animDeltasTrans, index: 0);
    p_animDeltasTrans = &this->behaviors.animDeltasTrans;
    idList<idAngles,5>::Append(this: &this->behaviors.animDeltasTrans, obj: &v55);
    if ( this->behaviors.animDeltasRot.num == 10 )
      idList<idAngles,5>::RemoveIndex(this: (idList<idVec3,116> *)&this->behaviors.animDeltasRot, index: 0);
    p_animDeltasRot = &this->behaviors.animDeltasRot;
    idList<idAngles,5>::Append(this: (idList<idVec3,5> *)&this->behaviors.animDeltasRot, obj: v56.mat);
    HIDWORD(v19) = &pb_AnimDeltaSmooth;
    if ( pb_AnimDeltaSmooth.valueInteger != 0
      || (LODWORD(v19) = this->behaviors.shared.sharedFlags, (HIDWORD(v19) = (v19 & 8) != 0) != 0) )
    {
      num = this->behaviors.animDeltasTrans.num;
      v26 = vec3_origin.x;
      v27 = vec3_origin.y;
      v28 = 0;
      v29 = vec3_origin.z;
      v55.x = vec3_origin.x;
      v55.y = vec3_origin.y;
      v55.z = vec3_origin.z;
      if ( num >= 4 )
      {
        list = p_animDeltasTrans->list;
        HIDWORD(v19) = 0;
        do
        {
          v55.x = *(float *)((char *)&list->x + HIDWORD(v19)) + (float)v26;
          v28 += 4;
          v55.y = *(float *)((char *)&list->y + HIDWORD(v19)) + (float)v27;
          v55.z = *(float *)((char *)&list->z + HIDWORD(v19)) + (float)v29;
          v31 = (float)(*(float *)((char *)&list[1].x + HIDWORD(v19)) + v55.x);
          v55.x = *(float *)((char *)&list[1].x + HIDWORD(v19)) + v55.x;
          v32 = (float)(*(float *)((char *)&list[1].y + HIDWORD(v19)) + v55.y);
          v55.y = *(float *)((char *)&list[1].y + HIDWORD(v19)) + v55.y;
          v55.z = *(float *)((char *)&list[1].z + HIDWORD(v19)) + v55.z;
          LODWORD(v19) = (char *)list + HIDWORD(v19) + 36;
          v55.x = *(float *)(v19 - 12) + (float)v31;
          v55.y = *(float *)(v19 - 8) + (float)v32;
          v55.z = *(float *)(v19 - 4) + v55.z;
          v26 = (float)(*(float *)v19 + v55.x);
          v55.x = *(float *)v19 + v55.x;
          HIDWORD(v19) += 48;
          v27 = (float)(*(float *)(v19 + 4) + v55.y);
          v55.y = *(float *)(v19 + 4) + v55.y;
          v29 = (float)(*(float *)(v19 + 8) + v55.z);
          v55.z = *(float *)(v19 + 8) + v55.z;
        }
        while ( v28 < num - 3 );
      }
      if ( v28 < num )
      {
        v33 = p_animDeltasTrans->list;
        HIDWORD(v19) = 12 * v28;
        v34 = num - v28;
        do
        {
          v26 = (float)(*(float *)((char *)&v33->x + HIDWORD(v19)) + (float)v26);
          v55.x = v26;
          v27 = (float)(*(float *)((char *)&v33->y + HIDWORD(v19)) + (float)v27);
          v55.y = v27;
          v29 = (float)(*(float *)((char *)&v33->z + HIDWORD(v19)) + (float)v29);
          HIDWORD(v19) += 12;
          v55.z = v29;
          --v34;
        }
        while ( v34 != 0 );
      }
      LODWORD(v19) = num;
      *(_QWORD *)&v61.mat[0].x = v19;
      v55.x = (float)((float)1.0 / (float)v19) * (float)v26;
      v55.y = (float)v27 * (float)((float)1.0 / (float)v19);
      v55.z = (float)v29 * (float)((float)1.0 / (float)v19);
      if ( results != nullptr )
        *results |= 1u;
      v35 = this->behaviors.animDeltasRot.num;
      v36 = 0;
      HIDWORD(v37) = &ang_zero;
      pitch = ang_zero.pitch;
      v56.mat[0].x = ang_zero.pitch;
      yaw = ang_zero.yaw;
      v40 = ang_zero.roll;
      v56.mat[0].y = ang_zero.yaw;
      v56.mat[0].z = ang_zero.roll;
      if ( v35 >= 4 )
      {
        v41 = p_animDeltasRot->list;
        HIDWORD(v37) = 0;
        do
        {
          v56.mat[0].x = (float)pitch + *(float *)((char *)&v41->pitch + HIDWORD(v37));
          v36 += 4;
          v56.mat[0].y = *(float *)((char *)&v41->yaw + HIDWORD(v37)) + (float)yaw;
          v56.mat[0].z = *(float *)((char *)&v41->roll + HIDWORD(v37)) + (float)v40;
          v42 = (float)(v56.mat[0].x + *(float *)((char *)&v41[1].pitch + HIDWORD(v37)));
          v56.mat[0].x = v56.mat[0].x + *(float *)((char *)&v41[1].pitch + HIDWORD(v37));
          v43 = (float)(*(float *)((char *)&v41[1].yaw + HIDWORD(v37)) + v56.mat[0].y);
          v56.mat[0].y = *(float *)((char *)&v41[1].yaw + HIDWORD(v37)) + v56.mat[0].y;
          LODWORD(v37) = (char *)v41 + HIDWORD(v37) + 36;
          v56.mat[0].z = *(float *)((char *)&v41[1].roll + HIDWORD(v37)) + v56.mat[0].z;
          v56.mat[0].x = (float)v42 + *(float *)(v37 - 12);
          v56.mat[0].y = *(float *)(v37 - 8) + (float)v43;
          v56.mat[0].z = *(float *)(v37 - 4) + v56.mat[0].z;
          pitch = (float)(v56.mat[0].x + *(float *)v37);
          v56.mat[0].x = v56.mat[0].x + *(float *)v37;
          HIDWORD(v37) += 48;
          yaw = (float)(*(float *)(v37 + 4) + v56.mat[0].y);
          v56.mat[0].y = *(float *)(v37 + 4) + v56.mat[0].y;
          v40 = (float)(*(float *)(v37 + 8) + v56.mat[0].z);
          v56.mat[0].z = *(float *)(v37 + 8) + v56.mat[0].z;
        }
        while ( v36 < v35 - 3 );
      }
      if ( v36 < v35 )
      {
        v44 = p_animDeltasRot->list;
        HIDWORD(v37) = 12 * v36;
        v45 = v35 - v36;
        do
        {
          pitch = (float)((float)pitch + *(float *)((char *)&v44->pitch + HIDWORD(v37)));
          v56.mat[0].x = pitch;
          yaw = (float)(*(float *)((char *)&v44->yaw + HIDWORD(v37)) + (float)yaw);
          v56.mat[0].y = yaw;
          v40 = (float)(*(float *)((char *)&v44->roll + HIDWORD(v37)) + (float)v40);
          HIDWORD(v37) += 12;
          v56.mat[0].z = v40;
          --v45;
        }
        while ( v45 != 0 );
      }
      LODWORD(v37) = v35;
      *(_QWORD *)&v61.mat[0].x = v37;
      v56.mat[0].x = (float)((float)1.0 / (float)v37) * (float)pitch;
      v56.mat[0].y = (float)yaw * (float)((float)1.0 / (float)v37);
      v56.mat[0].z = (float)v40 * (float)((float)1.0 / (float)v37);
      v46 = (float *)idAngles::ToMat3(this: v75, result: &v56);
      v56.mat[1].y = *v46;
      v56.mat[1].z = v46[1];
      v56.mat[2].x = v46[2];
      v56.mat[2].y = v46[3];
      v56.mat[2].z = v46[4];
      v57 = v46[5];
      v58 = v46[6];
      v59 = v46[7];
      v60 = v46[8];
      if ( results == nullptr )
        goto LABEL_44;
      v24 = *results | 2;
    }
    else
    {
      if ( pb_AnimDeltaRepeatOnZero.valueInteger == 0 && (v19 & 0x10) == 0 )
        goto LABEL_44;
      if ( (float)((float)(v55.x * v55.x) + (float)((float)(v55.y * v55.y) + (float)(v55.z * v55.z))) == 0.0 )
      {
        v20 = this->behaviors.animDeltasTrans.num;
        if ( v20 >= 2 )
        {
          p_x = &p_animDeltasTrans->list[v20 - 2].x;
          v55.x = *p_x;
          v55.y = p_x[1];
          v55.z = p_x[2];
          if ( results != nullptr )
            *results |= 4u;
        }
      }
      if ( (float)((float)(v56.mat[0].x * v56.mat[0].x)
                 + (float)((float)(v56.mat[0].z * v56.mat[0].z) + (float)(v56.mat[0].y * v56.mat[0].y))) != 0.0 )
        goto LABEL_44;
      v22 = this->behaviors.animDeltasRot.num;
      if ( v22 < 2 )
        goto LABEL_44;
      v23 = (float *)idAngles::ToMat3(this: v75, result: (idMat3 *)&p_animDeltasRot->list[v22 - 2]);
      v56.mat[1].y = *v23;
      v56.mat[1].z = v23[1];
      v56.mat[2].x = v23[2];
      v56.mat[2].y = v23[3];
      v56.mat[2].z = v23[4];
      v57 = v23[5];
      v58 = v23[6];
      v59 = v23[7];
      v60 = v23[8];
      if ( results == nullptr )
        goto LABEL_44;
      v24 = *results | 8;
    }
    *results = v24;
LABEL_44:
    presentable = this->presentable;
    if ( presentable != nullptr )
      v48 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v48 = nullptr;
    idPresentablePlayer::GetViewAngles(this: (idPresentablePlayer *)v64, result: v48, includeWeaponKick: true);
    idMat3::ToAngles(this: (idMat3 *)&v61.mat[2].z, result: (idAngles *)&v56.mat[1].y);
    v49 = this->presentable;
    v61.mat[1].y = v64[0] - v61.mat[2].z;
    v61.mat[1].z = v64[1] - v62;
    v61.mat[2].x = v64[2] - v63;
    if ( v49 != nullptr )
      v50 = v49->GetPlayerInterface_2(this: v49);
    else
      v50 = nullptr;
    idPresentablePlayer::SetViewAngles(this: v50, angles: (const idAngles *)&v61.mat[1].y, force: false);
    ent->GetModelTransform(this: ent, a2: (idVec3 *)v74, a3: (idMat3 *)v65);
    v51 = this->presentable;
    v73.overrideVelocity.y = vec3_origin.y;
    v73.clipMove = v9;
    v73.velocityType = VEL_EXPLICIT;
    v73.overrideVelocity.z = vec3_origin.z;
    v73.ignoreEntityNum = 0x1FFF;
    v73.overrideVelocity.x = vec3_origin.x;
    v73.delta.y = (float)(v65[1] * v55.x) + (float)((float)(v68 * v55.y) + (float)(v71 * v55.z));
    v52 = (float)((float)(v67 * v55.y) + (float)(v70 * v55.z));
    v53 = (float)((float)(v66 * v55.x) + (float)((float)(v69 * v55.y) + (float)(v72 * v55.z)));
    v55.z = (float)(v66 * v55.x) + (float)((float)(v69 * v55.y) + (float)(v72 * v55.z));
    v55.y = v73.delta.y;
    v73.delta.x = (float)(v65[0] * v55.x) + (float)v52;
    v55.x = v73.delta.x;
    v73.delta.z = v53;
    if ( v51 != nullptr )
      v54 = v51->GetPlayerInterface_2(this: v51);
    else
      v54 = nullptr;
    idPresentablePlayer::SetExplicitMove(this: v54, move: &v73, alsoAllowPhysicsMove: false, useExplicitMove2: false);
  }
}


// ========================================================================
// ?PlayerBehavior_Shared_ApplyThirdPersonHandsAnimDeltas@idPlayer@@QAAX_N0@Z
// EA  : 0x82E3E7E0
// RVA : 0x00E3E7E0
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_ApplyThirdPersonHandsAnimDeltas(
        idPlayer *this,
        bool applyToPlayer,
        bool clip)
{
  int thirdPersonHandsFlags; // r11
  int valueInteger; // r30
  double v6; // fp28
  double v7; // fp27
  double v8; // fp26
  char v9; // r27
  double pitch; // fp29
  double yaw; // fp30
  double roll; // fp31
  double x; // fp31
  double z; // fp30
  double y; // fp29
  int v16; // r3
  double v17; // fp28
  double v18; // fp27
  double v19; // fp26
  int v20; // r3
  int v21; // [sp+60h] [-E0h] BYREF
  int v22; // [sp+64h] [-DCh] BYREF
  idMat3 v23; // [sp+68h] [-D8h] BYREF
  idMat3 v24[2]; // [sp+90h] [-B0h] BYREF

  thirdPersonHandsFlags = this->behaviors.shared.thirdPersonHandsFlags;
  v21 = 0;
  if ( (thirdPersonHandsFlags & 0x20) != 0 )
  {
    this->behaviors.shared.thirdPersonHandsFlags = thirdPersonHandsFlags & 0xFFFFFFDF;
  }
  else
  {
    idPlayer::PlayerBehavior_Shared_ApplyAnimDeltas(
      this,
      ent: this->thirdPersonHands,
      applyToPlayer,
      clip,
      results: &v21);
    valueInteger = pb_TraceHandsAnimDeltas.valueInteger;
    if ( pb_TraceHandsAnimDeltas.valueInteger != 0 )
    {
      idAlignedEntity::GetLastOriginDeltas(
        this: this->thirdPersonHands,
        deltaRot: v24,
        deltaTrans: (idVec3 *)&v23.mat[1].y,
        time: &v22);
      idMat3::ToAngles(this: &v23, result: (idAngles *)v24);
      v6 = (float)(accumulatedHandsAnimDeltaPos.x + v23.mat[1].y);
      v7 = (float)(accumulatedHandsAnimDeltaPos.y + v23.mat[1].z);
      v8 = (float)(accumulatedHandsAnimDeltaPos.z + v23.mat[2].x);
      v9 = v21;
      accumulatedHandsAnimDeltaPos.x = accumulatedHandsAnimDeltaPos.x + v23.mat[1].y;
      accumulatedHandsAnimDeltaPos.y = accumulatedHandsAnimDeltaPos.y + v23.mat[1].z;
      accumulatedHandsAnimDeltaPos.z = accumulatedHandsAnimDeltaPos.z + v23.mat[2].x;
      pitch = (float)(accumulatedHandsAnimDeltaAngles.pitch + v23.mat[0].x);
      yaw = (float)(accumulatedHandsAnimDeltaAngles.yaw + v23.mat[0].y);
      roll = (float)(accumulatedHandsAnimDeltaAngles.roll + v23.mat[0].z);
      accumulatedHandsAnimDeltaAngles.pitch = accumulatedHandsAnimDeltaAngles.pitch + v23.mat[0].x;
      accumulatedHandsAnimDeltaAngles.yaw = accumulatedHandsAnimDeltaAngles.yaw + v23.mat[0].y;
      accumulatedHandsAnimDeltaAngles.roll = accumulatedHandsAnimDeltaAngles.roll + v23.mat[0].z;
      if ( valueInteger == 1 || valueInteger == 3 )
      {
        x = v23.mat[2].x;
        z = v23.mat[1].z;
        y = v23.mat[1].y;
        v16 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "(%d)%s: handsDeltaTrans=(%0.2f,%0.2f,%0.2f) at time %d (%0.2f,%0.2f,%0.2f)",
          v16,
          "idPlayer::PlayerBehavior_Shared_ApplyThirdPersonHandsAnimDeltas",
          y,
          z,
          x,
          HIDWORD(z),
          v6,
          v7,
          v8);
        if ( (v9 & 0x10) != 0 )
          idLib::Printf(fmt: " (includes external)");
        if ( (v9 & 1) != 0 )
          idLib::Printf(fmt: " (smoothed)");
        if ( (v9 & 4) != 0 )
          idLib::Printf(fmt: " (repeated)");
        idLib::Printf(fmt: "\n");
        roll = accumulatedHandsAnimDeltaAngles.roll;
        yaw = accumulatedHandsAnimDeltaAngles.yaw;
        pitch = accumulatedHandsAnimDeltaAngles.pitch;
      }
      if ( valueInteger == 2 || valueInteger == 3 )
      {
        v17 = v23.mat[0].z;
        v18 = v23.mat[0].y;
        v19 = v23.mat[0].x;
        v20 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "(%d)%s: handsDeltaAngles=(%0.2f,%0.2f,%0.2f) at time %d (%0.2f,%0.2f,%0.2f)",
          v20,
          "idPlayer::PlayerBehavior_Shared_ApplyThirdPersonHandsAnimDeltas",
          v19,
          v18,
          v17,
          HIDWORD(v18),
          pitch,
          yaw,
          roll);
        if ( (v9 & 2) != 0 )
          idLib::Printf(fmt: " (smoothed)");
        if ( (v9 & 8) != 0 )
          idLib::Printf(fmt: " (repeated)");
        idLib::Printf(fmt: "\n");
      }
    }
  }
}


// ========================================================================
// ?PlayerBehavior_Shared_ApplyThirdPersonLegsAnimDeltas@idPlayer@@QAAX_N0@Z
// EA  : 0x82E3EAC0
// RVA : 0x00E3EAC0
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_ApplyThirdPersonLegsAnimDeltas(
        idPlayer *this,
        bool applyToPlayer,
        bool clip)
{
  int thirdPersonLegsFlags; // r11
  int valueInteger; // r30
  double v6; // fp28
  double v7; // fp27
  double v8; // fp26
  char v9; // r27
  double pitch; // fp29
  double yaw; // fp30
  double roll; // fp31
  double x; // fp31
  double z; // fp30
  double y; // fp29
  int v16; // r3
  double v17; // fp28
  double v18; // fp27
  double v19; // fp26
  int v20; // r3
  int v21; // [sp+60h] [-E0h] BYREF
  int v22; // [sp+64h] [-DCh] BYREF
  idMat3 v23; // [sp+68h] [-D8h] BYREF
  idMat3 v24[2]; // [sp+90h] [-B0h] BYREF

  thirdPersonLegsFlags = this->behaviors.shared.thirdPersonLegsFlags;
  v21 = 0;
  if ( (thirdPersonLegsFlags & 0x20) != 0 )
  {
    this->behaviors.shared.thirdPersonLegsFlags = thirdPersonLegsFlags & 0xFFFFFFDF;
  }
  else
  {
    idPlayer::PlayerBehavior_Shared_ApplyAnimDeltas(
      this,
      ent: this->thirdPersonLegs,
      applyToPlayer,
      clip,
      results: &v21);
    valueInteger = pb_TraceLegsAnimDeltas.valueInteger;
    if ( pb_TraceLegsAnimDeltas.valueInteger != 0 )
    {
      idAlignedEntity::GetLastOriginDeltas(
        this: this->thirdPersonLegs,
        deltaRot: v24,
        deltaTrans: (idVec3 *)&v23.mat[1].y,
        time: &v22);
      idMat3::ToAngles(this: &v23, result: (idAngles *)v24);
      v6 = (float)(accumulatedLegsAnimDeltaPos.x + v23.mat[1].y);
      v7 = (float)(accumulatedLegsAnimDeltaPos.y + v23.mat[1].z);
      v8 = (float)(accumulatedLegsAnimDeltaPos.z + v23.mat[2].x);
      v9 = v21;
      accumulatedLegsAnimDeltaPos.x = accumulatedLegsAnimDeltaPos.x + v23.mat[1].y;
      accumulatedLegsAnimDeltaPos.y = accumulatedLegsAnimDeltaPos.y + v23.mat[1].z;
      accumulatedLegsAnimDeltaPos.z = accumulatedLegsAnimDeltaPos.z + v23.mat[2].x;
      pitch = (float)(accumulatedLegsAnimDeltaAngles.pitch + v23.mat[0].x);
      yaw = (float)(accumulatedLegsAnimDeltaAngles.yaw + v23.mat[0].y);
      roll = (float)(accumulatedLegsAnimDeltaAngles.roll + v23.mat[0].z);
      accumulatedLegsAnimDeltaAngles.pitch = accumulatedLegsAnimDeltaAngles.pitch + v23.mat[0].x;
      accumulatedLegsAnimDeltaAngles.yaw = accumulatedLegsAnimDeltaAngles.yaw + v23.mat[0].y;
      accumulatedLegsAnimDeltaAngles.roll = accumulatedLegsAnimDeltaAngles.roll + v23.mat[0].z;
      if ( valueInteger == 1 || valueInteger == 3 )
      {
        x = v23.mat[2].x;
        z = v23.mat[1].z;
        y = v23.mat[1].y;
        v16 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "(%d)%s: legsDeltaTrans=(%0.2f,%0.2f,%0.2f) at time %d (%0.2f,%0.2f,%0.2f)",
          v16,
          "idPlayer::PlayerBehavior_Shared_ApplyThirdPersonLegsAnimDeltas",
          y,
          z,
          x,
          HIDWORD(z),
          v6,
          v7,
          v8);
        if ( (v9 & 0x10) != 0 )
          idLib::Printf(fmt: " (includes external)");
        if ( (v9 & 1) != 0 )
          idLib::Printf(fmt: " (smoothed)");
        if ( (v9 & 4) != 0 )
          idLib::Printf(fmt: " (repeated)");
        idLib::Printf(fmt: "\n");
        roll = accumulatedLegsAnimDeltaAngles.roll;
        yaw = accumulatedLegsAnimDeltaAngles.yaw;
        pitch = accumulatedLegsAnimDeltaAngles.pitch;
      }
      if ( valueInteger == 2 || valueInteger == 3 )
      {
        v17 = v23.mat[0].z;
        v18 = v23.mat[0].y;
        v19 = v23.mat[0].x;
        v20 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "(%d)%s: legsDeltaAngles=(%0.2f,%0.2f,%0.2f) at time %d (%0.2f,%0.2f,%0.2f)",
          v20,
          "idPlayer::PlayerBehavior_Shared_ApplyThirdPersonLegsAnimDeltas",
          v19,
          v18,
          v17,
          HIDWORD(v18),
          pitch,
          yaw,
          roll);
        if ( (v9 & 2) != 0 )
          idLib::Printf(fmt: " (smoothed)");
        if ( (v9 & 8) != 0 )
          idLib::Printf(fmt: " (repeated)");
        idLib::Printf(fmt: "\n");
      }
    }
  }
}


// ========================================================================
// ?PlayerBehavior_Shared_Handle@idPlayer@@QAAXXZ
// EA  : 0x82E3EDA0
// RVA : 0x00E3EDA0
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Shared_Handle(idPlayer *this)
{
  unsigned __int8 v2; // r29
  char v3; // r30

  idPlayer::PlayerBehavior_Shared_HandleThirdPersonHandsAnim(this);
  idPlayer::PlayerBehavior_Shared_HandleThirdPersonLegsAnim(this);
  if ( (this->behaviors.shared.thirdPersonHandsFlags & 1) != 0 )
    idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsToPlayer(this);
  if ( (this->behaviors.shared.thirdPersonLegsFlags & 1) != 0 )
    idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsToPlayer(this);
  v2 = 0;
  v3 = 0;
  if ( (this->behaviors.shared.thirdPersonHandsFlags & 2) != 0 )
  {
    v2 = 1;
    v3 = 1;
    idPlayer::PlayerBehavior_Shared_ApplyThirdPersonHandsAnimDeltas(
      this,
      applyToPlayer: true,
      clip: (this->behaviors.shared.thirdPersonHandsFlags & 4) != 0);
  }
  if ( (this->behaviors.shared.thirdPersonLegsFlags & 2) != 0 )
  {
    v3 = 1;
    idPlayer::PlayerBehavior_Shared_ApplyThirdPersonLegsAnimDeltas(
      this,
      applyToPlayer: (_cntlzw(v2) & 0x20) != 0,
      clip: (this->behaviors.shared.thirdPersonLegsFlags & 4) != 0);
  }
  if ( v3 == 0 )
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->behaviors.animDeltasTrans);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->behaviors.animDeltasRot);
  }
}


// ========================================================================
// ?PlayerBehavior_Handle@idPlayer@@QAAXXZ
// EA  : 0x82E3EE78
// RVA : 0x00E3EE78
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Handle(idPlayer *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPLogScope v4[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idPlayer::PlayerBehavior_Handle");
  LODWORD(v2) = "idPlayer::PlayerBehavior_Handle";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v4, pl: &pLog, gMask: v2, label: v3);
  if ( !idPlayer::IsBot(this)
    && (!common->IsMultiplayer(this: common)
     || (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0
     && !this->playerHealth.IsDead_Impl(this: &this->playerHealth)) )
  {
    idPlayer::PlayerBehavior_Shared_Handle(this);
    if ( !common->IsMultiplayer(this: common) )
    {
      idPlayer::PlayerBehavior_ContextualLadder_Handle(this);
      idPlayer::PlayerBehavior_ContextualShimmy_Handle(this);
      idPlayer::PlayerBehavior_SprintSlide_Handle(this);
      idPlayer::PlayerBehavior_Takedown_Handle(this);
      idPlayer::PlayerBehavior_Lean_Handle(this);
      idPlayer::PlayerBehavior_WallClimb_Handle(this);
    }
  }
  idPLogScope::~idPLogScope(this: v4);
  RD_EventEnd();
}


// ========================================================================
// __unwind$491831
// EA  : 0x82E3EFB0
// RVA : 0x00E3EFB0
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void _unwind_491831()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$491832
// EA  : 0x82E3EFD8
// RVA : 0x00E3EFD8
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void _unwind_491832()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// `dynamic initializer for 'pb_PlayerMoveSpeedFactor''
// EA  : 0x8338B010
// RVA : 0x0138B010
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_PlayerMoveSpeedFactor__()
{
  idCVar::idCVar(
    this: &pb_PlayerMoveSpeedFactor,
    name: "pb_PlayerMoveSpeedFactor",
    value: "5",
    flags: 4,
    description: "How fast the shifts into position for a given interaction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_PlayerMoveSpeedFactor__);
}


// ========================================================================
// `dynamic initializer for 'pb_EnableThirdPersonHands''
// EA  : 0x8338B068
// RVA : 0x0138B068
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_EnableThirdPersonHands__()
{
  idCVar::idCVar(
    this: &pb_EnableThirdPersonHands,
    name: "pb_EnableThirdPersonHands",
    value: "1",
    flags: 1,
    description: "Enable the 3rd person hands",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_EnableThirdPersonHands__);
}


// ========================================================================
// `dynamic initializer for 'pb_ShowThirdPersonHands''
// EA  : 0x8338B0C0
// RVA : 0x0138B0C0
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ShowThirdPersonHands__()
{
  idCVar::idCVar(
    this: &pb_ShowThirdPersonHands,
    name: "pb_ShowThirdPersonHands",
    value: "1",
    flags: 1,
    description: "Draw the 3rd person hands (when enabled)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ShowThirdPersonHands__);
}


// ========================================================================
// `dynamic initializer for 'pb_ForceShowThirdPersonHands''
// EA  : 0x8338B118
// RVA : 0x0138B118
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ForceShowThirdPersonHands__()
{
  idCVar::idCVar(
    this: &pb_ForceShowThirdPersonHands,
    name: "pb_ForceShowThirdPersonHands",
    value: "0",
    flags: 1,
    description: "Always draw the 3rd person hands",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ForceShowThirdPersonHands__);
}


// ========================================================================
// `dynamic initializer for 'pb_TraceHandsAnims''
// EA  : 0x8338B170
// RVA : 0x0138B170
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_TraceHandsAnims__()
{
  idCVar::idCVar(
    this: &pb_TraceHandsAnims,
    name: "pb_TraceHandsAnims",
    value: "0",
    flags: 1,
    description: "Traces the animation calls on the hands to the debug console",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_TraceHandsAnims__);
}


// ========================================================================
// `dynamic initializer for 'pb_TraceHandsPos''
// EA  : 0x8338B1C8
// RVA : 0x0138B1C8
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_TraceHandsPos__()
{
  idCVar::idCVar(
    this: &pb_TraceHandsPos,
    name: "pb_TraceHandsPos",
    value: "0",
    flags: 2,
    description: "Traces the third person hands position (1=post-values, 2=pre and post-values",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_TraceHandsPos__);
}


// ========================================================================
// `dynamic initializer for 'pb_TraceHandsAngles''
// EA  : 0x8338B220
// RVA : 0x0138B220
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_TraceHandsAngles__()
{
  idCVar::idCVar(
    this: &pb_TraceHandsAngles,
    name: "pb_TraceHandsAngles",
    value: "0",
    flags: 2,
    description: "Traces the third person hands angles (1=post-values, 2=pre and post-values",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_TraceHandsAngles__);
}


// ========================================================================
// `dynamic initializer for 'pb_TraceHandsAnimDeltas''
// EA  : 0x8338B278
// RVA : 0x0138B278
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_TraceHandsAnimDeltas__()
{
  idCVar::idCVar(
    this: &pb_TraceHandsAnimDeltas,
    name: "pb_TraceHandsAnimDeltas",
    value: "0",
    flags: 2,
    description: "Traces the third person hands anim deltas (1 for trans, 2 for rot, 3 for both)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_TraceHandsAnimDeltas__);
}


// ========================================================================
// `dynamic initializer for 'pb_EnableThirdPersonLegs''
// EA  : 0x8338B2D0
// RVA : 0x0138B2D0
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_EnableThirdPersonLegs__()
{
  idCVar::idCVar(
    this: &pb_EnableThirdPersonLegs,
    name: "pb_EnableThirdPersonLegs",
    value: "1",
    flags: 1,
    description: "Enable the 3rd person legs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_EnableThirdPersonLegs__);
}


// ========================================================================
// `dynamic initializer for 'pb_ShowThirdPersonLegs''
// EA  : 0x8338B328
// RVA : 0x0138B328
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ShowThirdPersonLegs__()
{
  idCVar::idCVar(
    this: &pb_ShowThirdPersonLegs,
    name: "pb_ShowThirdPersonLegs",
    value: "1",
    flags: 1,
    description: "Draw the 3rd person legs (when enabled)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ShowThirdPersonLegs__);
}


// ========================================================================
// `dynamic initializer for 'pb_ForceShowThirdPersonLegs''
// EA  : 0x8338B380
// RVA : 0x0138B380
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ForceShowThirdPersonLegs__()
{
  idCVar::idCVar(
    this: &pb_ForceShowThirdPersonLegs,
    name: "pb_ForceShowThirdPersonLegs",
    value: "0",
    flags: 1,
    description: "Always draw the 3rd person legs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ForceShowThirdPersonLegs__);
}


// ========================================================================
// `dynamic initializer for 'pb_TraceLegsAnims''
// EA  : 0x8338B3D8
// RVA : 0x0138B3D8
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_TraceLegsAnims__()
{
  idCVar::idCVar(
    this: &pb_TraceLegsAnims,
    name: "pb_TraceLegsAnims",
    value: "0",
    flags: 1,
    description: "Traces the animation calls on the legs to the debug console",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_TraceLegsAnims__);
}


// ========================================================================
// `dynamic initializer for 'pb_TraceLegsPos''
// EA  : 0x8338B430
// RVA : 0x0138B430
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_TraceLegsPos__()
{
  idCVar::idCVar(
    this: &pb_TraceLegsPos,
    name: "pb_TraceLegsPos",
    value: "0",
    flags: 2,
    description: "Traces the third person legs position (1=post-values, 2=pre and post-values",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_TraceLegsPos__);
}


// ========================================================================
// `dynamic initializer for 'pb_TraceLegsAngles''
// EA  : 0x8338B488
// RVA : 0x0138B488
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_TraceLegsAngles__()
{
  idCVar::idCVar(
    this: &pb_TraceLegsAngles,
    name: "pb_TraceLegsAngles",
    value: "0",
    flags: 2,
    description: "Traces the third person legs angles (1=post-values, 2=pre and post-values",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_TraceLegsAngles__);
}


// ========================================================================
// `dynamic initializer for 'pb_TraceLegsAnimDeltas''
// EA  : 0x8338B4E0
// RVA : 0x0138B4E0
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_TraceLegsAnimDeltas__()
{
  idCVar::idCVar(
    this: &pb_TraceLegsAnimDeltas,
    name: "pb_TraceLegsAnimDeltas",
    value: "0",
    flags: 2,
    description: "Traces the third person legs anim deltas (1 for trans, 2 for rot, 3 for both)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_TraceLegsAnimDeltas__);
}


// ========================================================================
// `dynamic initializer for 'pb_BlockCheckUse8x8''
// EA  : 0x8338B538
// RVA : 0x0138B538
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_BlockCheckUse8x8__()
{
  idCVar::idCVar(
    this: &pb_BlockCheckUse8x8,
    name: "pb_BlockCheckUse8x8",
    value: "0",
    flags: 1,
    description: "If set, then the block check uses an 8x8 cube instead of a point",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_BlockCheckUse8x8__);
}


// ========================================================================
// `dynamic initializer for 'pb_ApplyAnimDeltasToPlayer''
// EA  : 0x8338B590
// RVA : 0x0138B590
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ApplyAnimDeltasToPlayer__()
{
  idCVar::idCVar(
    this: &pb_ApplyAnimDeltasToPlayer,
    name: "pb_ApplyAnimDeltasToPlayer",
    value: "1",
    flags: 1,
    description: "Can be set to 0 to disable application of anim deltas to player",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ApplyAnimDeltasToPlayer__);
}


// ========================================================================
// `dynamic initializer for 'pb_ApplyAnimDeltasForceClip''
// EA  : 0x8338B5E8
// RVA : 0x0138B5E8
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ApplyAnimDeltasForceClip__()
{
  idCVar::idCVar(
    this: &pb_ApplyAnimDeltasForceClip,
    name: "pb_ApplyAnimDeltasForceClip",
    value: "0",
    flags: 1,
    description: "Force the anim deltas to clipped against geometry",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ApplyAnimDeltasForceClip__);
}


// ========================================================================
// `dynamic initializer for 'pb_ApplyAnimDeltasForceNoClip''
// EA  : 0x8338B640
// RVA : 0x0138B640
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ApplyAnimDeltasForceNoClip__()
{
  idCVar::idCVar(
    this: &pb_ApplyAnimDeltasForceNoClip,
    name: "pb_ApplyAnimDeltasForceNoClip",
    value: "0",
    flags: 1,
    description: "Force the anim deltas to ignore clipping with geometry",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ApplyAnimDeltasForceNoClip__);
}


// ========================================================================
// `dynamic initializer for 'pb_AnimDeltaSmooth''
// EA  : 0x8338B698
// RVA : 0x0138B698
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_AnimDeltaSmooth__()
{
  idCVar::idCVar(
    this: &pb_AnimDeltaSmooth,
    name: "pb_AnimDeltaSmooth",
    value: "0",
    flags: 1,
    description: "Smooth the animation deltas over successive frames",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_AnimDeltaSmooth__);
}


// ========================================================================
// `dynamic initializer for 'pb_AnimDeltaRepeatOnZero''
// EA  : 0x8338B6F0
// RVA : 0x0138B6F0
// PDB : w:\tech5\tungsten\game\player\playerbehavior.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_AnimDeltaRepeatOnZero__()
{
  idCVar::idCVar(
    this: &pb_AnimDeltaRepeatOnZero,
    name: "pb_AnimDeltaRepeatOnZero",
    value: "0",
    flags: 1,
    description: "Ignore a zero delta value, and instead use the values from the previous frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_AnimDeltaRepeatOnZero__);
}

