
// ========================================================================
// ?PlayerBehavior_SprintSlide_ForceEndSlide@idPlayer@@QAAXXZ
// EA  : 0x82E478D0
// RVA : 0x00E478D0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_ForceEndSlide(idPlayer *this)
{
  this->behaviors.sprintSlide.forceEndSlide = true;
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_CanSlide@idPlayer@@QBA_NXZ
// EA  : 0x82E478E0
// RVA : 0x00E478E0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_SprintSlide_CanSlide(idPlayer *this)
{
  int v2; // r11
  int result; // r3

  if ( pb_ss_Enable.valueInteger == 0 )
    return 0;
  if ( idPlayer::PlayerBehavior_Lean_IsLeaning(this, bAny: false) )
    return 0;
  if ( idPlayer::PlayerBehavior_ContextualShimmy_IsInShimmy(this) )
    return 0;
  if ( idPlayer::PlayerBehavior_WallClimb_IsInWallClimb(this) )
    return 0;
  if ( (unsigned __int8)idPlayer::IsOnLadder(this) != 0 )
    return 0;
  v2 = *(_DWORD *)(idPlayer::GetPhysicsObj(this) + 1200);
  result = 1;
  if ( v2 != 0 )
    return 0;
  return result;
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_Startup@idPlayer@@QAAXXZ
// EA  : 0x82E47988
// RVA : 0x00E47988
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_Startup(idPlayer *this)
{
  idAlignedEntity *thirdPersonLegs; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v4; // r31
  unsigned __int16 v5; // [sp+50h] [-40h] BYREF
  unsigned __int16 v6; // [sp+52h] [-3Eh] BYREF
  unsigned __int16 v7; // [sp+54h] [-3Ch] BYREF
  unsigned __int16 v8; // [sp+56h] [-3Ah] BYREF
  unsigned __int16 v9; // [sp+58h] [-38h] BYREF
  char v10; // [sp+5Ah] [-36h] BYREF
  char v11; // [sp+5Ch] [-34h] BYREF
  char v12; // [sp+5Eh] [-32h] BYREF
  char v13; // [sp+60h] [-30h] BYREF
  char v14; // [sp+62h] [-2Eh] BYREF
  char v15; // [sp+64h] [-2Ch] BYREF
  char v16; // [sp+66h] [-2Ah] BYREF
  char v17; // [sp+68h] [-28h] BYREF
  char v18; // [sp+6Ah] [-26h] BYREF
  char v19; // [sp+6Ch] [-24h] BYREF
  char v20; // [sp+6Eh] [-22h] BYREF

  thirdPersonLegs = this->thirdPersonLegs;
  if ( thirdPersonLegs != nullptr
    && idAnimatedEntity::GetTreeAnimatorFromPresentable(this: thirdPersonLegs) != nullptr
    && (TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->thirdPersonLegs),
        v4 = TreeAnimatorFromPresentable,
        TreeAnimatorFromPresentable != nullptr) )
  {
    idDeclMD6::StrongLoadAlias(
      this: (idDeclMD6 *)&v5,
      result: TreeAnimatorFromPresentable->decl,
      aliasName: "sprintSlide/torsoTwist_center");
    this->behaviors.sprintSlide.bodyRotationLegsAnimAliasHandles[0].value = v5;
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v6, result: v4->decl, aliasName: "sprintSlide/torsoTwist_left");
    this->behaviors.sprintSlide.bodyRotationLegsAnimAliasHandles[1].value = v6;
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v7, result: v4->decl, aliasName: "sprintSlide/torsoTwist_right");
    this->behaviors.sprintSlide.bodyRotationLegsAnimAliasHandles[2].value = v7;
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v8, result: v4->decl, aliasName: "sprintSlide/torsoTwist_up");
    this->behaviors.sprintSlide.bodyRotationLegsAnimAliasHandles[3].value = v8;
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v9, result: v4->decl, aliasName: "sprintSlide/torsoTwist_down");
    this->behaviors.sprintSlide.bodyRotationLegsAnimAliasHandles[4].value = v9;
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v10, result: v4->decl, aliasName: "sprintslide/additiveJitter");
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v11, result: v4->decl, aliasName: "sprintslide/slide_into");
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v12, result: v4->decl, aliasName: "sprintslide/slide_loop");
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v13, result: v4->decl, aliasName: "sprintslide/slide_out_crouch");
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v14, result: v4->decl, aliasName: "sprintslide/slide_out_fall");
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v15, result: v4->decl, aliasName: "sprintslide/slide_out_stand");
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v16, result: v4->decl, aliasName: "sprintslide/torsoTwist_center");
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v17, result: v4->decl, aliasName: "sprintslide/torsoTwist_down");
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v18, result: v4->decl, aliasName: "sprintslide/torsoTwist_left");
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v19, result: v4->decl, aliasName: "sprintslide/torsoTwist_right");
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v20, result: v4->decl, aliasName: "sprintslide/torsoTwist_up");
    pb_ss_DebugForceSlide.flags &= ~0x20000u;
  }
  else
  {
    pb_ss_DebugForceSlide.flags &= ~0x20000u;
  }
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_IsSliding@idPlayer@@QBA_NXZ
// EA  : 0x82E47B78
// RVA : 0x00E47B78
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

BOOL __fastcall idPlayer::PlayerBehavior_SprintSlide_IsSliding(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  return (*(_BYTE *)(v3 + 47032) & 0x20) == 0 && this->behaviors.sprintSlide.state != SPRINT_SLIDE_STATE_NONE;
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_CheckCrouch@idPlayer@@QAA_NABVidVec3@@000ABVusercmd_t@@@Z
// EA  : 0x82E47C00
// RVA : 0x00E47C00
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_SprintSlide_CheckCrouch(
        idPlayer *this,
        const idVec3 *pos,
        const idVec3 *forward,
        const idVec3 *right,
        const idVec3 *up,
        const usercmd_t *userCmd)
{
  idPlayer::idPlayerBehaviorSprintSlideState_t state; // r11
  idPresentable *presentable; // r3
  int v9; // r3
  idPresentable *v10; // r3
  int v11; // r3
  idPresentable *v12; // r3
  int v13; // r3
  int v15; // r3

  state = this->behaviors.sprintSlide.state;
  presentable = this->presentable;
  if ( state != SPRINT_SLIDE_STATE_NONE )
  {
    if ( presentable != nullptr )
      v15 = ((int (__fastcall *)(idPresentable *, const idVec3 *, const idVec3 *, const idVec3 *, const idVec3 *, const usercmd_t *))presentable->GetPlayerInterface_2)(
              a1: presentable,
              a2: pos,
              a3: forward,
              a4: right,
              a5: up,
              a6: userCmd);
    else
      v15 = 0;
    if ( (unsigned __int8)idPhysics_Player::IsCrouching(this: (idPhysics_Player *)(v15 + 36264)) == 0 )
    {
      this->behaviors.sprintSlide.endSlide = true;
      return 1;
    }
  }
  else
  {
    if ( presentable != nullptr )
      v9 = ((int (__fastcall *)(idPresentable *, const idVec3 *, const idVec3 *, const idVec3 *, const idVec3 *, const usercmd_t *))presentable->GetPlayerInterface_2)(
             a1: presentable,
             a2: pos,
             a3: forward,
             a4: right,
             a5: up,
             a6: userCmd);
    else
      v9 = 0;
    if ( (unsigned __int8)idPhysics_Player::IsCrouching(this: (idPhysics_Player *)(v9 + 36264)) != 0 )
    {
      v10 = this->presentable;
      v11 = v10 != nullptr ? (int)v10->GetPlayerInterface_2(this: v10) : 0;
      if ( *(_BYTE *)(v11 + 47121) != 0 && (unsigned __int8)idPlayer::PlayerBehavior_SprintSlide_CanSlide(this) != 0 )
      {
        v12 = this->presentable;
        v13 = v12 != nullptr ? (int)v12->GetPlayerInterface_2(this: v12) : 0;
        if ( *(char *)(v13 + 46318) > 63
          && *(_BYTE *)(idPlayer::GetPhysicsObj(this) + 1046) != 0
          && (unsigned __int8)idPlayer::IsOnLadder(this) == 0 )
        {
          this->behaviors.sprintSlide.startSlide = true;
          return 1;
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_ShouldEndSlide@idPlayer@@QBA?AW4idPlayerBehaviorSprintSlideState_t@1@XZ
// EA  : 0x82E47DA0
// RVA : 0x00E47DA0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

idPlayer::idPlayerBehaviorSprintSlideState_t __fastcall idPlayer::PlayerBehavior_SprintSlide_ShouldEndSlide(
        idPlayer *this)
{
  idPresentable *presentable; // r3
  char v3; // r27
  char v4; // r26
  int v5; // r3
  idPhysics *Physics; // r3
  double valueFloat; // fp31
  float *v8; // r3
  int valueInteger; // r30
  idPhysics *v10; // r3
  double v11; // fp30
  double v12; // fp29
  idPhysics *v15; // r3
  double v16; // fp29
  double v17; // fp28
  double v18; // fp27
  float *v19; // r3
  double v20; // fp0
  double v21; // fp11
  int entityNumber; // r6
  idPhysics_Player *PhysicsObj; // r3
  idPlayer::idPlayerBehaviorSprintSlideState_t result; // r3
  float v25[2]; // [sp+50h] [-B0h] BYREF
  idVec3 v26; // [sp+58h] [-A8h] BYREF
  idVec3 v27; // [sp+68h] [-98h] BYREF
  idVec3 v28; // [sp+78h] [-88h] BYREF
  idVec3 v29; // [sp+88h] [-78h] BYREF

  presentable = this->presentable;
  v3 = 0;
  v4 = 0;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  if ( *(_BYTE *)(v5 + 47121) == 0 )
    goto LABEL_15;
  if ( (unsigned __int8)idPlayer::PlayerBehavior_SprintSlide_CanSlide(this) == 0 )
    goto LABEL_15;
  if ( this->behaviors.sprintSlide.endSlide )
    goto LABEL_15;
  Physics = idEntity::GetPhysics(this);
  valueFloat = pb_ss_MinSpeed2D.valueFloat;
  v8 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v28, result: (idVec3 *)Physics, a3: 0);
  if ( (float)((float)(*v8 * *v8) + (float)(v8[1] * v8[1])) < (double)(float)((float)valueFloat * (float)valueFloat)
    && pb_ss_DebugForceSlide.valueInteger == 0 )
  {
    goto LABEL_15;
  }
  valueInteger = pb_ss_MaxDurationMS.valueInteger;
  if ( pb_ss_MaxDurationMS.valueInteger > 0
    && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->behaviors.sprintSlide.slideStartTime > valueInteger
    && pb_ss_DebugForceSlide.valueInteger == 0 )
  {
    goto LABEL_15;
  }
  v10 = idEntity::GetPhysics(this);
  v10->GetLinearVelocity(this: (idPhysics *)&v26, result: (idVec3 *)v10, a3: 0);
  v26.z = 0.0;
  v11 = idVec3::NormalizeFast(this: &v26);
  v12 = pb_ss_AltitudeForwardTestDist.valueFloat;
  _FP11 = (float)((float)v12
                - (float)((float)(gameLocal->GetGameSecPerFrame(this: gameLocal, a2: GAMETIME_SCALED) * (float)v11)
                        * (float)3.0));
  __asm { fsel      f30, f11, f12, f29 }
  v15 = idEntity::GetPhysics(this);
  v16 = (float)(v26.x * (float)_FP30);
  v17 = (float)(v26.y * (float)_FP30);
  v18 = (float)((float)_FP30 * v26.z);
  v19 = (float *)v15->GetOrigin(this: v15, a2: 0);
  v20 = (float)(*v19 + (float)v16);
  v21 = (float)(v19[1] + (float)v17);
  v29.z = v19[2] + (float)v18;
  v29.x = v20;
  entityNumber = this->entityNumber;
  v25[0] = 0.0;
  v29.y = v21;
  v27.z = (float)((float)_FP30 * v26.z) + v29.z;
  v27.x = (float)(v26.x * (float)_FP30) + (float)v20;
  v27.y = (float)(v26.y * (float)_FP30) + (float)v21;
  v28.z = v27.z - pb_ss_MaxAltitude.valueFloat;
  v28.y = v27.y;
  v28.x = v27.x;
  if ( (unsigned __int8)idPlayer::PlayerBehavior_Shared_CheckBlocked(
                          startPos: &v29,
                          endPos: &v27,
                          blockDist: v25,
                          entityNum: entityNumber,
                          bDebug: false,
                          tr: nullptr,
                          contentMask: 107529) == 0
    && (unsigned __int8)idPlayer::PlayerBehavior_Shared_CheckBlocked(
                          startPos: &v27,
                          endPos: &v28,
                          blockDist: v25,
                          entityNum: this->entityNumber,
                          bDebug: false,
                          tr: nullptr,
                          contentMask: 107529) == 0 )
  {
    v4 = 1;
LABEL_15:
    v3 = 1;
  }
  if ( v3 == 0 )
    return SPRINT_SLIDE_STATE_NONE;
  PhysicsObj = (idPhysics_Player *)idPlayer::GetPhysicsObj(this);
  if ( idPhysics_Player::CanStand(this: PhysicsObj) )
    result = v4 == 0 ? SPRINT_SLIDE_STATE_END_STAND : SPRINT_SLIDE_STATE_END_FALL;
  else
    result = SPRINT_SLIDE_STATE_END_CROUCH;
  switch ( pb_ss_DebugForceEndState.valueInteger )
  {
    case 1:
      return SPRINT_SLIDE_STATE_END_STAND;
    case 2:
      return SPRINT_SLIDE_STATE_END_CROUCH;
    case 3:
      return SPRINT_SLIDE_STATE_END_FALL;
    default:
      break;
  }
  return result;
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_AlignFirstPersonHands@idPlayer@@QAAXXZ
// EA  : 0x82E48120
// RVA : 0x00E48120
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_AlignFirstPersonHands(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  idPresentable *v4; // r11
  idHands *v5; // r31
  float *v6; // r3
  idSpringCamera *springCamera; // r11
  double x; // fp0
  float v9; // r3
  double y; // fp13
  float v11; // r9
  double z; // fp12
  float v13; // r30
  float v14; // r10
  __int64 v15; // r11
  double v16; // fp31
  double v17; // fp30
  double v18; // fp29
  double v19; // fp28
  double v20; // fp27
  double v21; // fp26
  double v22; // fp1
  double v23; // fp0

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  v4 = this->presentable;
  v5 = (idHands *)(v3 + 37616);
  if ( v4 != nullptr )
    v6 = (float *)v4->GetPlayerInterface_2(this: this->presentable);
  else
    v6 = nullptr;
  springCamera = this->springCamera;
  x = springCamera->viewVelocity.x;
  y = springCamera->viewVelocity.y;
  v11 = v6[11634];
  z = springCamera->viewVelocity.z;
  v13 = v6[11635];
  v14 = v6[11633];
  v9 = springCamera->viewOrigin.z;
  v16 = (float)(springCamera->viewOrigin.x - v14);
  HIDWORD(v15) = numFrames;
  v17 = (float)(springCamera->viewOrigin.y - v11);
  LODWORD(v15) = pb_ss_UpdateAfterPhysics.valueInteger != 0 ? 0 : numFrames;
  v18 = (float)(v9 - v13);
  v19 = (float)((float)v15 * (float)x);
  v20 = (float)((float)y * (float)v15);
  v21 = (float)((float)z * (float)v15);
  v22 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
  v23 = 0.0;
  if ( pb_ss_UseExtraWorldOffset.valueInteger == 1 )
    v23 = 1.0;
  v5->extraWorldTranslation.x = (float)((float)((float)v19 * (float)v22) + (float)v16) * (float)v23;
  v5->extraWorldTranslation.y = (float)((float)((float)v20 * (float)v22) + (float)v17) * (float)v23;
  v5->extraWorldTranslation.z = (float)((float)((float)v21 * (float)v22) + (float)v18) * (float)v23;
  v5->extraWorldRotation = mat3_identity;
  idHands::UpdatePosition(this: v5);
  idHandsItem::UpdatePosition(this: &v5->rightItem, hands: v5);
  idHandsItem::UpdatePosition(this: &v5->leftItem, hands: v5);
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_StartMovement@idPlayer@@QAAXXZ
// EA  : 0x82E48348
// RVA : 0x00E48348
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_StartMovement(idPlayer *this)
{
  idPlayer::idPlayerBehaviorSprintSlide *p_sprintSlide; // r31
  double v3; // fp31
  double v4; // fp30
  idPhysics *Physics; // r3
  idPhysics *v6; // r3
  idPresentable *presentable; // r3
  int v8; // r3
  idPresentable *v9; // r3
  double valueFloat; // fp31
  int v11; // r3
  idPresentable *v12; // r3
  int v13; // r3
  float v14[6]; // [sp+50h] [-40h] BYREF

  p_sprintSlide = &this->behaviors.sprintSlide;
  v3 = (float)(this->behaviors.sprintSlide.forwardDir.x * this->behaviors.sprintSlide.forwardSpeed);
  v4 = (float)(this->behaviors.sprintSlide.forwardDir.y * this->behaviors.sprintSlide.forwardSpeed);
  Physics = idEntity::GetPhysics(this);
  Physics->GetLinearVelocity(this: (idPhysics *)v14, result: (idVec3 *)Physics, a3: 0);
  v14[0] = v3;
  v14[1] = v4;
  v6 = idEntity::GetPhysics(this);
  v6->SetLinearVelocity(this: v6, a2: (const idVec3 *)v14, a3: 0);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v8 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v8 = 0;
  p_sprintSlide->walkFrictionSave = *(float *)(v8 + 37120);
  v9 = this->presentable;
  valueFloat = pb_ss_SlideFriction.valueFloat;
  if ( v9 != nullptr )
    v11 = (int)v9->GetPlayerInterface_2(this: v9);
  else
    v11 = 0;
  idPhysics_Player::SetWalkFriction(this: (idPhysics_Player *)(v11 + 36264), friction: valueFloat);
  v12 = this->presentable;
  if ( v12 != nullptr )
    v13 = (int)v12->GetPlayerInterface_2(this: v12);
  else
    v13 = 0;
  idPhysics_Player::SetSprintSliding(this: (idPhysics_Player *)(v13 + 36264), sprintSliding: true);
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_HandleMovement@idPlayer@@QAAXXZ
// EA  : 0x82E48498
// RVA : 0x00E48498
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_HandleMovement(idPlayer *this)
{
  double valueFloat; // fp31
  idPresentable *presentable; // r3
  int v4; // r3
  idPresentable *v5; // r11
  double v6; // fp29
  int v7; // r3
  idPresentable *v8; // r11
  double v9; // fp30
  int v10; // r3
  double v11; // fp28
  idPhysics *Physics; // r3
  double v15; // fp4
  double v16; // fp3
  double v17; // fp7
  double v18; // fp6
  double v19; // fp31
  idPhysics *v20; // r3
  float v21; // [sp+50h] [-50h] BYREF
  float v22; // [sp+54h] [-4Ch]
  float v23; // [sp+58h] [-48h]
  float v24[12]; // [sp+60h] [-40h] BYREF

  valueFloat = pb_ss_AdjustSpeedForHeightScale.valueFloat;
  if ( pb_ss_AdjustSpeedForHeightScale.valueFloat > 0.0 )
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
      v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v4 = 0;
    v5 = this->presentable;
    v6 = *(float *)(v4 + 36888);
    if ( v5 != nullptr )
      v7 = (int)v5->GetPlayerInterface_2(this: this->presentable);
    else
      v7 = 0;
    v8 = this->presentable;
    v9 = *(float *)(v7 + 36812);
    if ( v8 != nullptr )
      v10 = (int)v8->GetPlayerInterface_2(this: this->presentable);
    else
      v10 = 0;
    v11 = *(float *)((*(int (__fastcall **)(int))(*(_DWORD *)(v10 + 36264) + 100))(a1: v10 + 36264) + 8);
    Physics = idEntity::GetPhysics(this);
    Physics->GetLinearVelocity(this: (idPhysics *)&v21, result: (idVec3 *)Physics, a3: 0);
    _FP7 = (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f5, f7, f2, f12 }
    v15 = __frsqrte(_FP5);
    v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                        * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                                                * (float)0.5))
                                                                                * (float)v15)
                                                                        - (float)1.5)
                                                        * (float)v15)
                                                * (float)((float)((float)(v23 * v23)
                                                                + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v15
                                                                                * (float)((float)((float)(v23 * v23)
                                                                                                + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                                        * (float)0.5))
                                                                        * (float)v15)
                                                                - (float)1.5)
                                                * (float)v15))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v15
                                                        * (float)((float)((float)(v23 * v23)
                                                                        + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                * (float)0.5))
                                                * (float)v15)
                                        - (float)1.5)
                        * (float)v15));
    v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                                * (float)v15)
                                                                                        * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                        * (float)v15))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v15
                                                                                                * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5))
                                                                                        * (float)v15)
                                                                                - (float)1.5)
                                                                * (float)v15))
                                                * (float)((float)((float)(v23 * v23)
                                                                + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                        * (float)0.5))
                                        * (float)v16)
                                - (float)1.5)
                * (float)v16);
    v18 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15)
                                                                                                * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                                * (float)v15))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5))
                                                                                                * (float)v15)
                                                                                        - (float)1.5)
                                                                        * (float)v15))
                                                        * (float)((float)((float)(v23 * v23)
                                                                        + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                * (float)0.5))
                                                * (float)v16)
                                        - (float)1.5)
                        * (float)v16)
                * (float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21))));
    v21 = v21
        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                                * (float)v15)
                                                                                        * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                        * (float)v15))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v15
                                                                                                * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5))
                                                                                        * (float)v15)
                                                                                - (float)1.5)
                                                                * (float)v15))
                                                * (float)((float)((float)(v23 * v23)
                                                                + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                        * (float)0.5))
                                        * (float)v16)
                                - (float)1.5)
                * (float)v16);
    v22 = v22 * (float)v17;
    v23 = (float)v17 * v23;
    v19 = __fsqrts((float)((float)((float)((float)((float)__fabs(v11) * (float)((float)v6 - (float)v9))
                                         * (float)valueFloat)
                                 * (float)2.0)
                         + (float)((float)v18 * (float)v18)));
    v20 = idEntity::GetPhysics(this);
    v24[0] = v21 * (float)v19;
    v24[1] = v22 * (float)v19;
    v24[2] = v23 * (float)v19;
    v20->SetLinearVelocity(this: v20, a2: (const idVec3 *)v24, a3: 0);
  }
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_HandleSlideSound@idPlayer@@QAAXXZ
// EA  : 0x82E486A8
// RVA : 0x00E486A8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_HandleSlideSound(idPlayer *this)
{
  idPlayer::idPlayerBehaviorSprintSlide *p_sprintSlide; // r31
  const idSoundShader *ImpactSoundForMaterial; // r30
  int v4; // r4
  idPhysics *Physics; // r3
  float *v6; // r3
  double v7; // fp13
  double v8; // fp0
  char v9; // [sp+50h] [-30h] BYREF

  p_sprintSlide = &this->behaviors.sprintSlide;
  if ( this->behaviors.sprintSlide.state != SPRINT_SLIDE_STATE_NONE )
  {
    if ( this->behaviors.sprintSlide.playLoopingSlideSound )
    {
      ImpactSoundForMaterial = nullptr;
      if ( *(_BYTE *)(idPlayer::GetPhysicsObj(this) + 1046) != 0 )
      {
        v4 = *(_DWORD *)(idPlayer::GetPhysicsObj(this) + 1144);
        if ( p_sprintSlide->slideSounds != nullptr )
          ImpactSoundForMaterial = idDeclImpactSound::GetImpactSoundForMaterial(
                                     this: p_sprintSlide->slideSounds,
                                     materialID: v4);
      }
      if ( ImpactSoundForMaterial != p_sprintSlide->loopingSlideSound )
      {
        p_sprintSlide->loopingSlideSound = ImpactSoundForMaterial;
        if ( ImpactSoundForMaterial != nullptr )
          idEntity::StartSoundShader(
            this,
            channel: SND_CHANNEL_BODY,
            shader: ImpactSoundForMaterial,
            soundShaderFlags: SSF_LOOPING,
            peerMask: 0xFFu);
        else
          idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
      }
      if ( p_sprintSlide->loopingSlideSound != nullptr )
      {
        Physics = idEntity::GetPhysics(this);
        v6 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v9, result: (idVec3 *)Physics, a3: 0);
        v7 = 0.0;
        v8 = (float)((float)((float)__fsqrts((float)((float)(v6[2] * v6[2])
                                                   + (float)((float)(*v6 * *v6) + (float)(v6[1] * v6[1]))))
                           - p_sprintSlide->sndSlideMinVolumeSpeed)
                   / (float)(p_sprintSlide->sndSlideMaxVolumeSpeed - p_sprintSlide->sndSlideMinVolumeSpeed));
        if ( v8 < 0.0 || (v7 = 1.0, v8 > 1.0) )
          v8 = v7;
        idEntity::SetSoundVolume(
          this,
          channel: SND_CHANNEL_BODY,
          volume: (float)((float)((float)(p_sprintSlide->sndSlideMaxVolume - p_sprintSlide->sndSlideMinVolume) * (float)v8)
                + p_sprintSlide->sndSlideMinVolume));
      }
    }
    else
    {
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
    }
  }
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_HandleAdditiveAnims@idPlayer@@QAAXXZ
// EA  : 0x82E48808
// RVA : 0x00E48808
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_HandleAdditiveAnims(idPlayer *this)
{
  idPhysics *Physics; // r3
  float *v3; // r3
  double v4; // fp0
  double v5; // fp1
  char v6; // [sp+50h] [-20h] BYREF

  if ( this->behaviors.sprintSlide.state == SPRINT_SLIDE_STATE_SLIDING )
  {
    Physics = idEntity::GetPhysics(this);
    v3 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v6, result: (idVec3 *)Physics, a3: 0);
    v4 = (float)((float)__fabs((float)((float)__fsqrts((float)((float)(v3[2] * v3[2])
                                                             + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1]))))
                                     - this->behaviors.sprintSlide.additiveAnimAlphaMinSpeed))
               / (float)(this->behaviors.sprintSlide.additiveAnimAlphaMaxSpeed
                       - this->behaviors.sprintSlide.additiveAnimAlphaMinSpeed));
    if ( v4 >= 0.0 )
    {
      if ( v4 > 1.0 )
        v4 = 1.0;
    }
    else
    {
      v4 = 0.0;
    }
    v5 = (float)((float)((float)(this->behaviors.sprintSlide.additiveAnimAlphaMax
                               - this->behaviors.sprintSlide.additiveAnimAlphaMin)
                       * (float)v4)
               + this->behaviors.sprintSlide.additiveAnimAlphaMin);
    if ( v5 >= 0.0099999998 )
    {
      if ( v5 > 1.0 )
        v5 = 1.0;
    }
    else
    {
      v5 = 0.0099999998;
    }
    idAlignedEntity::SetAdditiveAnimAlpha(this: this->thirdPersonLegs, alpha: v5, alphaRate: -1.0);
  }
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_HandleCameraShake@idPlayer@@QAAXXZ
// EA  : 0x82E48908
// RVA : 0x00E48908
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_HandleCameraShake(idPlayer *this)
{
  idPhysics *Physics; // r3
  float *v3; // r3
  double v4; // fp0
  double v5; // fp1
  double v6; // fp13
  idPresentable *presentable; // r3
  double v8; // fp31
  int v9; // r3
  char v10; // [sp+50h] [-30h] BYREF

  if ( !common->IsMultiplayer(this: common) && this->behaviors.sprintSlide.state == SPRINT_SLIDE_STATE_SLIDING )
  {
    Physics = idEntity::GetPhysics(this);
    v3 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v10, result: (idVec3 *)Physics, a3: 0);
    v4 = 0.0;
    v5 = __fabs((float)((float)__fsqrts((float)((float)(v3[2] * v3[2])
                                              + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1]))))
                      - this->behaviors.sprintSlide.cameraShakeMinSpeed));
    v6 = (float)((float)v5
               / (float)(this->behaviors.sprintSlide.cameraShakeMaxSpeed
                       - this->behaviors.sprintSlide.additiveAnimAlphaMinSpeed));
    if ( v6 >= 0.0 )
    {
      v4 = 1.0;
      if ( v6 <= 1.0 )
        v4 = (float)((float)v5
                   / (float)(this->behaviors.sprintSlide.cameraShakeMaxSpeed
                           - this->behaviors.sprintSlide.additiveAnimAlphaMinSpeed));
    }
    presentable = this->presentable;
    v8 = (float)((float)((float)(this->behaviors.sprintSlide.cameraShakeMax - this->behaviors.sprintSlide.cameraShakeMin)
                       * (float)v4)
               + this->behaviors.sprintSlide.cameraShakeMin);
    if ( presentable != nullptr )
      v9 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v9 = 0;
    *(float *)(v9 + 19128) = v8;
  }
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_DebugHandle@idPlayer@@QAAXXZ
// EA  : 0x82E48A28
// RVA : 0x00E48A28
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_DebugHandle(idPlayer *this, int a2, __int64 a3)
{
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  const char *CurAnimName; // r3
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  idPhysics *Physics; // r3
  const idVec3 *v14; // r3
  idAlignedEntity *thirdPersonLegs; // r3
  float x; // r9
  float y; // r8
  float z; // r7
  idPhysics *v19; // r3
  __int64 v20; // r8
  int v21; // r3
  __int64 v22; // r10
  _DWORD *v23; // r11
  int i; // ctr
  __int128 v25; // r6
  __int64 v26; // r10
  __int64 v27; // r8
  __int64 v28; // r6
  __int64 v29; // r10
  __int64 v30; // r8
  __int64 v31; // r6
  __int64 v32; // r6
  __int64 v33; // r10
  __int64 v34; // r8
  __int64 v35; // r6
  __int64 v36; // r8
  __int64 v37; // r10
  __int64 v38; // r6
  __int64 v39; // r8
  __int64 v40; // r10
  __int64 v41; // r6
  __int64 v42; // r10
  __int64 v43; // r8
  __int64 v44; // r6
  __int64 v45; // r10
  __int64 v46; // r8
  __int64 v47; // r6
  __int64 v48; // r10
  __int64 v49; // r8
  idRenderWorld *v50; // r3
  idPresentable *presentable; // r3
  int v52; // r3
  __int64 v53; // r8
  __int128 v54; // r6
  __int64 v55; // r10
  idPhysics *v56; // r3
  __int64 v57; // r8
  __int64 v58; // r10
  int v59; // [sp+8h] [-F8h]
  int v60; // [sp+8h] [-F8h]
  int v61; // [sp+8h] [-F8h]
  int v62; // [sp+8h] [-F8h]
  int v63; // [sp+8h] [-F8h]
  int v64; // [sp+8h] [-F8h]
  int v65; // [sp+8h] [-F8h]
  int v66; // [sp+8h] [-F8h]
  int v67; // [sp+8h] [-F8h]
  int v68; // [sp+8h] [-F8h]
  int v69; // [sp+8h] [-F8h]
  int v70; // [sp+8h] [-F8h]
  int v71; // [sp+8h] [-F8h]
  int v72; // [sp+8h] [-F8h]
  int v73; // [sp+Ch] [-F4h]
  int v74; // [sp+Ch] [-F4h]
  int v75; // [sp+Ch] [-F4h]
  int v76; // [sp+Ch] [-F4h]
  int v77; // [sp+Ch] [-F4h]
  int v78; // [sp+Ch] [-F4h]
  int v79; // [sp+Ch] [-F4h]
  int v80; // [sp+Ch] [-F4h]
  int v81; // [sp+Ch] [-F4h]
  int v82; // [sp+Ch] [-F4h]
  int v83; // [sp+Ch] [-F4h]
  int v84; // [sp+Ch] [-F4h]
  int v85; // [sp+Ch] [-F4h]
  int v86; // [sp+Ch] [-F4h]
  int v87; // [sp+10h] [-F0h]
  int v88; // [sp+10h] [-F0h]
  int v89; // [sp+10h] [-F0h]
  int v90; // [sp+10h] [-F0h]
  int v91; // [sp+10h] [-F0h]
  int v92; // [sp+10h] [-F0h]
  int v93; // [sp+10h] [-F0h]
  int v94; // [sp+10h] [-F0h]
  int v95; // [sp+10h] [-F0h]
  int v96; // [sp+10h] [-F0h]
  int v97; // [sp+10h] [-F0h]
  int v98; // [sp+10h] [-F0h]
  int v99; // [sp+10h] [-F0h]
  int v100; // [sp+10h] [-F0h]
  int v101; // [sp+14h] [-ECh]
  int v102; // [sp+14h] [-ECh]
  int v103; // [sp+14h] [-ECh]
  int v104; // [sp+14h] [-ECh]
  int v105; // [sp+14h] [-ECh]
  int v106; // [sp+14h] [-ECh]
  int v107; // [sp+14h] [-ECh]
  int v108; // [sp+14h] [-ECh]
  int v109; // [sp+14h] [-ECh]
  int v110; // [sp+14h] [-ECh]
  int v111; // [sp+14h] [-ECh]
  int v112; // [sp+14h] [-ECh]
  int v113; // [sp+14h] [-ECh]
  int v114; // [sp+14h] [-ECh]
  int v115; // [sp+18h] [-E8h]
  int v116; // [sp+18h] [-E8h]
  int v117; // [sp+18h] [-E8h]
  int v118; // [sp+18h] [-E8h]
  int v119; // [sp+18h] [-E8h]
  int v120; // [sp+18h] [-E8h]
  int v121; // [sp+18h] [-E8h]
  int v122; // [sp+18h] [-E8h]
  int v123; // [sp+18h] [-E8h]
  int v124; // [sp+18h] [-E8h]
  int v125; // [sp+18h] [-E8h]
  int v126; // [sp+18h] [-E8h]
  int v127; // [sp+18h] [-E8h]
  int v128; // [sp+18h] [-E8h]
  int v129; // [sp+1Ch] [-E4h]
  int v130; // [sp+1Ch] [-E4h]
  int v131; // [sp+1Ch] [-E4h]
  int v132; // [sp+1Ch] [-E4h]
  int v133; // [sp+1Ch] [-E4h]
  int v134; // [sp+1Ch] [-E4h]
  int v135; // [sp+1Ch] [-E4h]
  int v136; // [sp+1Ch] [-E4h]
  int v137; // [sp+1Ch] [-E4h]
  int v138; // [sp+1Ch] [-E4h]
  int v139; // [sp+1Ch] [-E4h]
  int v140; // [sp+1Ch] [-E4h]
  int v141; // [sp+1Ch] [-E4h]
  int v142; // [sp+1Ch] [-E4h]
  double v143; // [sp+20h] [-E0h]
  double v144; // [sp+20h] [-E0h]
  double v145; // [sp+20h] [-E0h]
  double v146; // [sp+20h] [-E0h]
  double v147; // [sp+20h] [-E0h]
  double v148; // [sp+20h] [-E0h]
  double v149; // [sp+28h] [-D8h]
  double v150; // [sp+28h] [-D8h]
  double v151; // [sp+30h] [-D0h]
  double v152; // [sp+30h] [-D0h]
  double v153; // [sp+30h] [-D0h]
  float v154; // [sp+50h] [-B0h] BYREF
  float v155; // [sp+54h] [-ACh]
  float v156; // [sp+58h] [-A8h]
  idVec3 v157; // [sp+60h] [-A0h] BYREF
  float v158[4]; // [sp+70h] [-90h] BYREF
  idColor v159; // [sp+80h] [-80h] BYREF
  idMat3 v160; // [sp+90h] [-70h] BYREF
  idMat3 v161; // [sp+C0h] [-40h] BYREF

  if ( pb_ss_Debug.valueInteger != 0 )
  {
    LODWORD(v4) = &aAvSsobjectVCom[20];
    HIDWORD(v4) = &off_82350000;
    LODWORD(v5) = stateNames_0;
    HIDWORD(v5) = 4 * this->behaviors.sprintSlide.state;
    HIDWORD(a3) = *(const char **)((char *)stateNames_0 + HIDWORD(v5));
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Slide State: %s",
      a3,
      a4: v5,
      a5: v4,
      a6: v59,
      a7: v73,
      a8: v87,
      a9: v101,
      a10: v115,
      a11: v129);
    idPlayer::debugHUDPrintf(
      this,
      fmt: &byte_8200D768,
      a3: v8,
      a4: v7,
      a5: v6,
      a6: v60,
      a7: v74,
      a8: v88,
      a9: v102,
      a10: v116,
      a11: v130);
    CurAnimName = idAlignedEntity::GetCurAnimName(this: this->thirdPersonLegs);
    LODWORD(v10) = &off_82350000;
    HIDWORD(v10) = CurAnimName;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Legs Anim  : %s",
      a3: v10,
      a4: v12,
      a5: v11,
      a6: v61,
      a7: v75,
      a8: v89,
      a9: v103,
      a10: v117,
      a11: v131);
    Physics = idEntity::GetPhysics(this: this->thirdPersonLegs);
    v14 = Physics->GetOrigin(this: Physics, a2: 0);
    x = v14->x;
    y = v14->y;
    z = v14->z;
    thirdPersonLegs = this->thirdPersonLegs;
    v154 = x;
    v155 = y;
    v156 = z;
    v19 = idEntity::GetPhysics(this: thirdPersonLegs);
    v21 = (int)v19->GetAxis(this: v19, a2: 0);
    LODWORD(v22) = &v159.a;
    v23 = (_DWORD *)(v21 - 4);
    for ( i = 9; i != 0; --i )
    {
      HIDWORD(v22) = *++v23;
      LODWORD(v22) = v22 + 4;
      *(_DWORD *)v22 = *v23;
    }
    v151 = v156;
    HIDWORD(v20) = LODWORD(v151);
    v149 = v155;
    LODWORD(v25) = LODWORD(v149);
    *(double *)((char *)&v25 + 4) = v154;
    idPlayer::debugHUDPrintf(
      this,
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v154)),
      a3: v25,
      a4: v20,
      a5: v22,
      a6: v62,
      a7: v76,
      a8: v90,
      a9: v104,
      a10: v118,
      a11: v132);
    idPlayer::debugHUDPrintf(
      this,
      fmt: &byte_8200D768,
      a3: v28,
      a4: v27,
      a5: v26,
      a6: v63,
      a7: v77,
      a8: v91,
      a9: v105,
      a10: v119,
      a11: v133);
    LODWORD(v29) = &off_82350000;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Body rotation:",
      a3: v31,
      a4: v30,
      a5: v29,
      a6: v64,
      a7: v78,
      a8: v92,
      a9: v106,
      a10: v120,
      a11: v134);
    v143 = this->behaviors.sprintSlide.bodyRotationAnimWeights[0];
    HIDWORD(v32) = LODWORD(v143);
    HIDWORD(v33) = &off_82350000;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "   Center = %0.2f",
      a3: v32,
      a4: v34,
      a5: v33,
      a6: v65,
      a7: v79,
      a8: v93,
      a9: v107,
      a10: v121,
      a11: v135);
    v144 = this->behaviors.sprintSlide.bodyRotationAnimWeights[1];
    HIDWORD(v35) = LODWORD(v144);
    LODWORD(v36) = &off_82350000;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "   Left   = %0.2f",
      a3: v35,
      a4: v36,
      a5: v37,
      a6: v66,
      a7: v80,
      a8: v94,
      a9: v108,
      a10: v122,
      a11: v136);
    v145 = this->behaviors.sprintSlide.bodyRotationAnimWeights[2];
    HIDWORD(v38) = LODWORD(v145);
    HIDWORD(v39) = &off_82350000;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "   Right  = %0.2f",
      a3: v38,
      a4: v39,
      a5: v40,
      a6: v67,
      a7: v81,
      a8: v95,
      a9: v109,
      a10: v123,
      a11: v137);
    v146 = this->behaviors.sprintSlide.bodyRotationAnimWeights[3];
    HIDWORD(v41) = LODWORD(v146);
    LODWORD(v41) = &off_82350000;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "   Up     = %0.2f",
      a3: v41,
      a4: v43,
      a5: v42,
      a6: v68,
      a7: v82,
      a8: v96,
      a9: v110,
      a10: v124,
      a11: v138);
    v147 = this->behaviors.sprintSlide.bodyRotationAnimWeights[4];
    HIDWORD(v44) = LODWORD(v147);
    idPlayer::debugHUDPrintf(
      this,
      fmt: "   Down   = %0.2f",
      a3: v44,
      a4: v46,
      a5: v45,
      a6: v69,
      a7: v83,
      a8: v97,
      a9: v111,
      a10: v125,
      a11: v139);
    v148 = this->behaviors.sprintSlide.bodyRotationAlpha.p1.x;
    HIDWORD(v47) = LODWORD(v148);
    idPlayer::debugHUDPrintf(
      this,
      fmt: "   Alpha  = %0.2f",
      a3: v47,
      a4: v49,
      a5: v48,
      a6: v70,
      a7: v84,
      a8: v98,
      a9: v112,
      a10: v126,
      a11: v140);
    v159 = idColor::colorWhite;
    v50 = gameLocal->GetRenderWorld(this: gameLocal);
    v50->DebugAxis(this: v50, a2: (const idVec4 *)&v159, a3: (const idVec3 *)&v154, a4: &v160, a5: 10000, a6: false);
    presentable = this->presentable;
    if ( presentable != nullptr )
      v52 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v52 = 0;
    idView::GetViewPos(this: (idView *)(v52 + 16224), origin: &v157, axis: &v161);
    v152 = v157.z;
    HIDWORD(v53) = LODWORD(v152);
    v150 = v157.y;
    LODWORD(v54) = LODWORD(v150);
    *(double *)((char *)&v54 + 4) = v157.x;
    idPlayer::debugHUDPrintf(
      this,
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v157.x)),
      a3: v54,
      a4: v53,
      a5: v55,
      a6: v71,
      a7: v85,
      a8: v99,
      a9: v113,
      a10: v127,
      a11: v141);
    v56 = idEntity::GetPhysics(this);
    v56->GetLinearVelocity(this: (idPhysics *)v158, result: (idVec3 *)v56, a3: 0);
    v153 = v158[2];
    HIDWORD(v57) = LODWORD(v153);
    idPlayer::debugHUDPrintf(
      this,
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v158[0])),
      a3: COERCE__INT64(v158[1]),
      a4: v57,
      a5: v58,
      a6: v72,
      a7: v86,
      a8: v100,
      a9: v114,
      a10: v128,
      a11: v142);
  }
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_EndSlide@idPlayer@@QAAXXZ
// EA  : 0x82E48FF8
// RVA : 0x00E48FF8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_EndSlide(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPlayer::idPlayerBehaviorSprintSlide *p_sprintSlide; // r28
  int v4; // r3
  idPresentable *v5; // r3
  int v6; // r3
  idPresentable *v7; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r11
  idPresentable *v11; // r3
  int v12; // r3
  idAlignedEntity *thirdPersonLegs; // r30
  idPresentable *v14; // r11
  idPlayer::idPlayerBehaviorSprintSlideState_t state; // r11
  idPresentable *v16; // r3
  int v17; // r3
  idPresentable *v18; // r3
  idPresentablePlayer *v19; // r3

  p_sprintSlide = &this->behaviors.sprintSlide;
  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = 0;
  idPhysics_Player::SetWalkFriction(this: (idPhysics_Player *)(v4 + 36264), friction: p_sprintSlide->walkFrictionSave);
  p_sprintSlide->startSlide = false;
  p_sprintSlide->endSlide = false;
  v5 = this->presentable;
  if ( v5 != nullptr )
    v6 = (int)v5->GetPlayerInterface_2(this: v5);
  else
    v6 = 0;
  *(_BYTE *)(v6 + 37536) = 0;
  v7 = this->presentable;
  if ( v7 != nullptr )
    v8 = (int)v7->GetPlayerInterface_2(this: v7);
  else
    v8 = 0;
  idPhysics_Player::SetSprintSliding(this: (idPhysics_Player *)(v8 + 36264), sprintSliding: false);
  v9 = this->presentable;
  if ( v9 != nullptr )
    v10 = (int)v9->GetPlayerInterface_2(this: v9);
  else
    v10 = 0;
  *(float *)(v10 + 19128) = 0.0;
  idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
    this,
    constrain: false,
    heading: nullptr,
    maxDeltaPitch: 0.0,
    maxDeltaYaw: 0.0,
    rate: 0.0);
  idPlayer::PlayerBehavior_Shared_StopThirdPersonLegsAnim(this);
  this->springCamera->manualUpdate = false;
  v11 = this->presentable;
  if ( v11 != nullptr )
    v12 = (int)v11->GetPlayerInterface_2(this: v11);
  else
    v12 = 0;
  *(idVec3 *)(v12 + 45212) = vec3_origin;
  *(idMat3 *)(v12 + 45224) = mat3_identity;
  thirdPersonLegs = this->thirdPersonLegs;
  v14 = thirdPersonLegs->presentable;
  if ( v14 == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
    v14 = thirdPersonLegs->presentable;
  }
  v14->model->useDeferredPosition = p_sprintSlide->legsDeferredSave;
  this->springCamera->forceCalculateViewStage = p_sprintSlide->springCamForceCalculateViewStageSave;
  state = p_sprintSlide->state;
  if ( state == SPRINT_SLIDE_STATE_END_STAND || state == SPRINT_SLIDE_STATE_END_FALL )
  {
    v16 = this->presentable;
    if ( v16 != nullptr )
      v17 = (int)v16->GetPlayerInterface_2(this: v16);
    else
      v17 = 0;
    idPhysics_Player::ClearCrouch(this: (idPhysics_Player *)(v17 + 36264));
  }
  v18 = this->presentable;
  if ( v18 != nullptr )
    v19 = v18->GetPlayerInterface_2(this: v18);
  else
    v19 = nullptr;
  idPresentablePlayer::SetInhibitFlags(this: v19, flags: p_sprintSlide->inhibitFlagsSave);
  idPlayer::idPlayerBehaviorSprintSlide::Clear(this: p_sprintSlide);
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_AlignThirdPersonModels@idPlayer@@QAAXABVidVec3@@@Z
// EA  : 0x82E49260
// RVA : 0x00E49260
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_AlignThirdPersonModels(idPlayer *this, const idVec3 *extraOffset)
{
  idPlayer::idPlayerBehaviorSprintSlide *p_sprintSlide; // r31
  idPresentable *presentable; // r3
  int v5; // r3
  idPhysics *Physics; // r3
  int v7; // r3
  float v8; // r11
  float v9; // r10
  idPhysics *v10; // r3
  double v11; // fp1
  idPresentable *v12; // r3
  int v13; // r3
  float *PhysicsObj; // r3
  idSpring<idVec3> *p_legsFwdDirSpring; // r30
  double x; // fp13
  double z; // fp12
  double v18; // fp5
  double v19; // fp3
  double v20; // fp1
  double v21; // fp9
  double v22; // fp8
  double v24; // fp4
  double v26; // fp2
  double v27; // fp5
  double v28; // fp4
  double v29; // fp2
  double v30; // fp0
  double v31; // fp12
  double y; // fp13
  idMat3 v33[3]; // [sp+50h] [-70h] BYREF

  p_sprintSlide = &this->behaviors.sprintSlide;
  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  *(idVec3 *)(v5 + 45212) = vec3_origin;
  *(idMat3 *)(v5 + 45224) = mat3_identity;
  Physics = idEntity::GetPhysics(this);
  v7 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v8 = *(float *)(v7 + 4);
  v9 = *(float *)(v7 + 8);
  v33[0].mat[1].y = *(float *)v7;
  v33[0].mat[1].z = v8;
  v33[0].mat[2].x = v9;
  v10 = idEntity::GetPhysics(this);
  v10->GetAxis(this: v10, a2: 0);
  v33[0].mat[0] = vec3_origin;
  if ( pb_ss_LegsPitchForGroundSlope.valueInteger != 0 )
  {
    v12 = this->presentable;
    if ( v12 != nullptr )
      v13 = (int)v12->GetPlayerInterface_2(this: v12);
    else
      v13 = 0;
    if ( *(_BYTE *)(v13 + 37310) != 0 )
    {
      PhysicsObj = (float *)idPlayer::GetPhysicsObj(this);
      p_legsFwdDirSpring = &p_sprintSlide->legsFwdDirSpring;
      x = p_sprintSlide->forwardDir.x;
      z = p_sprintSlide->forwardDir.z;
      v18 = (float)(PhysicsObj[279]
                  * (float)((float)(p_sprintSlide->forwardDir.z * PhysicsObj[281])
                          + (float)((float)(p_sprintSlide->forwardDir.x * PhysicsObj[279])
                                  + (float)(p_sprintSlide->forwardDir.y * PhysicsObj[280]))));
      v19 = (float)(PhysicsObj[281]
                  * (float)((float)(p_sprintSlide->forwardDir.z * PhysicsObj[281])
                          + (float)((float)(p_sprintSlide->forwardDir.x * PhysicsObj[279])
                                  + (float)(p_sprintSlide->forwardDir.y * PhysicsObj[280]))));
      p_sprintSlide->legsFwdDirSpring.p0.y = p_sprintSlide->forwardDir.y
                                           - (float)(PhysicsObj[280]
                                                   * (float)((float)(p_sprintSlide->forwardDir.z * PhysicsObj[281])
                                                           + (float)((float)(p_sprintSlide->forwardDir.x
                                                                           * PhysicsObj[279])
                                                                   + (float)(p_sprintSlide->forwardDir.y
                                                                           * PhysicsObj[280]))));
      p_sprintSlide->legsFwdDirSpring.p0.x = (float)x - (float)v18;
      p_sprintSlide->legsFwdDirSpring.p0.z = (float)z - (float)v19;
      v11 = idVec3::NormalizeFast(this: &p_sprintSlide->legsFwdDirSpring.p0);
    }
    else
    {
      p_legsFwdDirSpring = &p_sprintSlide->legsFwdDirSpring;
      p_sprintSlide->legsFwdDirSpring.p0.x = p_sprintSlide->forwardDir.x;
      p_sprintSlide->legsFwdDirSpring.p0.y = p_sprintSlide->forwardDir.y;
      p_sprintSlide->legsFwdDirSpring.p0.z = p_sprintSlide->forwardDir.z;
    }
    v20 = ((double (__fastcall *)(idGameLocal *, int, double))gameLocal->GetGameSecPerFrame)(
            a1: gameLocal,
            a2: 1,
            a3: v11);
    idSpring<idVec3>::Update(this: p_legsFwdDirSpring, dt: v20);
    v21 = p_sprintSlide->legsFwdDirSpring.p1.x;
    v22 = p_sprintSlide->legsFwdDirSpring.p1.z;
    _FP5 = (float)((float)((float)(p_sprintSlide->legsFwdDirSpring.p1.z * p_sprintSlide->legsFwdDirSpring.p1.z)
                         + (float)((float)(p_sprintSlide->legsFwdDirSpring.p1.x * p_sprintSlide->legsFwdDirSpring.p1.x)
                                 + (float)(p_sprintSlide->legsFwdDirSpring.p1.y * p_sprintSlide->legsFwdDirSpring.p1.y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v24 = (float)((float)((float)(p_sprintSlide->legsFwdDirSpring.p1.z * p_sprintSlide->legsFwdDirSpring.p1.z)
                        + (float)((float)(p_sprintSlide->legsFwdDirSpring.p1.x * p_sprintSlide->legsFwdDirSpring.p1.x)
                                + (float)(p_sprintSlide->legsFwdDirSpring.p1.y * p_sprintSlide->legsFwdDirSpring.p1.y)))
                * (float)0.5);
    __asm { fsel      f3, f5, f6, f13 }
    v26 = __frsqrte(_FP3);
    v27 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26
                                                                                        * (float)((float)((float)(p_sprintSlide->legsFwdDirSpring.p1.z * p_sprintSlide->legsFwdDirSpring.p1.z) + (float)((float)(p_sprintSlide->legsFwdDirSpring.p1.x * p_sprintSlide->legsFwdDirSpring.p1.x) + (float)(p_sprintSlide->legsFwdDirSpring.p1.y * p_sprintSlide->legsFwdDirSpring.p1.y)))
                                                                                                * (float)0.5))
                                                                                * (float)v26)
                                                                        - (float)1.5)
                                                        * (float)v26)
                                                * (float)((float)((float)(p_sprintSlide->legsFwdDirSpring.p1.z
                                                                        * p_sprintSlide->legsFwdDirSpring.p1.z)
                                                                + (float)((float)(p_sprintSlide->legsFwdDirSpring.p1.x
                                                                                * p_sprintSlide->legsFwdDirSpring.p1.x)
                                                                        + (float)(p_sprintSlide->legsFwdDirSpring.p1.y
                                                                                * p_sprintSlide->legsFwdDirSpring.p1.y)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v26
                                                                                * (float)((float)((float)(p_sprintSlide->legsFwdDirSpring.p1.z * p_sprintSlide->legsFwdDirSpring.p1.z)
                                                                                                + (float)((float)(p_sprintSlide->legsFwdDirSpring.p1.x * p_sprintSlide->legsFwdDirSpring.p1.x) + (float)(p_sprintSlide->legsFwdDirSpring.p1.y * p_sprintSlide->legsFwdDirSpring.p1.y)))
                                                                                        * (float)0.5))
                                                                        * (float)v26)
                                                                - (float)1.5)
                                                * (float)v26))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v26
                                                        * (float)((float)((float)(p_sprintSlide->legsFwdDirSpring.p1.z
                                                                                * p_sprintSlide->legsFwdDirSpring.p1.z)
                                                                        + (float)((float)(p_sprintSlide->legsFwdDirSpring.p1.x
                                                                                        * p_sprintSlide->legsFwdDirSpring.p1.x)
                                                                                + (float)(p_sprintSlide->legsFwdDirSpring.p1.y
                                                                                        * p_sprintSlide->legsFwdDirSpring.p1.y)))
                                                                * (float)0.5))
                                                * (float)v26)
                                        - (float)1.5)
                        * (float)v26));
    v28 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26
                                                                                                * (float)((float)((float)(p_sprintSlide->legsFwdDirSpring.p1.z * p_sprintSlide->legsFwdDirSpring.p1.z) + (float)((float)(p_sprintSlide->legsFwdDirSpring.p1.x * p_sprintSlide->legsFwdDirSpring.p1.x) + (float)(p_sprintSlide->legsFwdDirSpring.p1.y * p_sprintSlide->legsFwdDirSpring.p1.y))) * (float)0.5))
                                                                                        * (float)v26)
                                                                                - (float)1.5)
                                                                * (float)v26)
                                                        * (float)((float)((float)(p_sprintSlide->legsFwdDirSpring.p1.z
                                                                                * p_sprintSlide->legsFwdDirSpring.p1.z)
                                                                        + (float)((float)(p_sprintSlide->legsFwdDirSpring.p1.x
                                                                                        * p_sprintSlide->legsFwdDirSpring.p1.x)
                                                                                + (float)(p_sprintSlide->legsFwdDirSpring.p1.y
                                                                                        * p_sprintSlide->legsFwdDirSpring.p1.y)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v26
                                                                                        * (float)((float)((float)(p_sprintSlide->legsFwdDirSpring.p1.z * p_sprintSlide->legsFwdDirSpring.p1.z) + (float)((float)(p_sprintSlide->legsFwdDirSpring.p1.x * p_sprintSlide->legsFwdDirSpring.p1.x) + (float)(p_sprintSlide->legsFwdDirSpring.p1.y * p_sprintSlide->legsFwdDirSpring.p1.y)))
                                                                                                * (float)0.5))
                                                                                * (float)v26)
                                                                        - (float)1.5)
                                                        * (float)v26))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v26
                                                                * (float)((float)((float)(p_sprintSlide->legsFwdDirSpring.p1.z
                                                                                        * p_sprintSlide->legsFwdDirSpring.p1.z)
                                                                                + (float)((float)(p_sprintSlide->legsFwdDirSpring.p1.x
                                                                                                * p_sprintSlide->legsFwdDirSpring.p1.x)
                                                                                        + (float)(p_sprintSlide->legsFwdDirSpring.p1.y
                                                                                                * p_sprintSlide->legsFwdDirSpring.p1.y)))
                                                                        * (float)0.5))
                                                        * (float)v26)
                                                - (float)1.5)
                                * (float)v26))
                * (float)v24);
    v29 = (float)((float)-(float)((float)((float)v28
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)(p_sprintSlide->legsFwdDirSpring.p1.z * p_sprintSlide->legsFwdDirSpring.p1.z) + (float)((float)(p_sprintSlide->legsFwdDirSpring.p1.x * p_sprintSlide->legsFwdDirSpring.p1.x) + (float)(p_sprintSlide->legsFwdDirSpring.p1.y * p_sprintSlide->legsFwdDirSpring.p1.y))) * (float)0.5)) * (float)v26) - (float)1.5)
                                                                                        * (float)v26)
                                                                                * (float)((float)((float)(p_sprintSlide->legsFwdDirSpring.p1.z * p_sprintSlide->legsFwdDirSpring.p1.z)
                                                                                                + (float)((float)(p_sprintSlide->legsFwdDirSpring.p1.x * p_sprintSlide->legsFwdDirSpring.p1.x) + (float)(p_sprintSlide->legsFwdDirSpring.p1.y * p_sprintSlide->legsFwdDirSpring.p1.y)))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)(p_sprintSlide->legsFwdDirSpring.p1.z * p_sprintSlide->legsFwdDirSpring.p1.z) + (float)((float)(p_sprintSlide->legsFwdDirSpring.p1.x * p_sprintSlide->legsFwdDirSpring.p1.x) + (float)(p_sprintSlide->legsFwdDirSpring.p1.y * p_sprintSlide->legsFwdDirSpring.p1.y))) * (float)0.5)) * (float)v26)
                                                                                                - (float)1.5)
                                                                                * (float)v26))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v26
                                                                                        * (float)((float)((float)(p_sprintSlide->legsFwdDirSpring.p1.z * p_sprintSlide->legsFwdDirSpring.p1.z) + (float)((float)(p_sprintSlide->legsFwdDirSpring.p1.x * p_sprintSlide->legsFwdDirSpring.p1.x) + (float)(p_sprintSlide->legsFwdDirSpring.p1.y * p_sprintSlide->legsFwdDirSpring.p1.y)))
                                                                                                * (float)0.5))
                                                                                * (float)v26)
                                                                        - (float)1.5)
                                                        * (float)v26)))
                                - (float)1.5)
                * (float)v27);
    v30 = (float)(p_sprintSlide->legsFwdDirSpring.p1.y * (float)v29);
    p_sprintSlide->legsFwdDirSpring.p1.y = p_sprintSlide->legsFwdDirSpring.p1.y * (float)v29;
    p_sprintSlide->legsFwdDirSpring.p1.x = (float)v21 * (float)v29;
    p_sprintSlide->legsFwdDirSpring.p1.z = (float)v22 * (float)v29;
    v33[0].mat[0].x = (float)v21 * (float)v29;
    v33[0].mat[0].y = v30;
    v31 = (float)((float)v22 * (float)v29);
  }
  else
  {
    y = p_sprintSlide->forwardDir.y;
    v31 = p_sprintSlide->forwardDir.z;
    v33[0].mat[0].x = p_sprintSlide->forwardDir.x;
    v33[0].mat[0].y = y;
  }
  v33[0].mat[0].z = v31;
  idVec3::ToMat3(this: (idVec3 *)&v33[0].mat[2].z, result: v33);
  idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsAlignNode(
    this,
    origin: (const idVec3 *)&v33[0].mat[1].y,
    axis: (idMat3 *)&v33[0].mat[2].z);
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_HandleBodyRotation@idPlayer@@QAAXXZ
// EA  : 0x82E49548
// RVA : 0x00E49548
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_HandleBodyRotation(idPlayer *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r26
  float y; // r8
  double v4; // fp1
  idPresentable *presentable; // r3
  const idAngles *v6; // r4
  double v7; // fp1
  idCVar *v8; // r9
  double v9; // fp0
  idSpring<idVec2> *p_bodyRotationPos; // r30
  double v11; // fp1
  idCVar *v12; // r10
  double v13; // fp0
  double v14; // fp13
  double v17; // fp6
  double v18; // fp2
  double v19; // fp0
  double v20; // fp8
  double x; // fp0
  double v22; // fp1
  idVec2 *p_p1; // r11
  double v24; // fp13
  double v27; // fp6
  double v28; // fp12
  double v29; // fp8
  double v30; // fp0
  double v31; // fp0
  double v32; // fp0
  double v33; // fp1
  idAnimator_Synced *p_additiveSyncedAnimator; // r30
  double v35; // fp31
  int v36; // r3
  idAnimator_Synced *v37; // r31
  idAlignedEntity *thirdPersonLegs; // r30
  int v39; // r29
  const idAnimStack *v40; // r3
  int v41; // r6
  idVec3 v42; // [sp+50h] [-A0h] BYREF
  float v43[4]; // [sp+60h] [-90h] BYREF
  idVec3 v44; // [sp+70h] [-80h] BYREF

  if ( !common->IsMultiplayer(this: common) )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->thirdPersonLegs);
    if ( TreeAnimatorFromPresentable != nullptr && (_cntlzw(this->behaviors.sprintSlide.state - 1) & 0x20) != 0 )
    {
      y = this->behaviors.sprintSlide.forwardDir.y;
      v42.x = this->behaviors.sprintSlide.forwardDir.x;
      v42.z = 0.0;
      v42.y = y;
      v4 = idVec3::NormalizeFast(this: &v42);
      if ( pb_ss_EnableBodyRotation.valueInteger != 0 )
      {
        presentable = this->presentable;
        if ( presentable != nullptr )
          v6 = (const idAngles *)((int (__fastcall *)(idPresentable *, double))presentable->GetPlayerInterface_2)(
                                   a1: presentable,
                                   a2: v4);
        else
          v6 = nullptr;
        idPresentablePlayer::GetViewAngles(this: (idPresentablePlayer *)v43, result: v6, includeWeaponKick: true);
        idVec3::ToAngles(this: &v44, result: (idAngles *)&v42);
        v7 = idMath::AngleNormalize360(angle: (float)(v43[1] - v44.y));
        if ( v7 > 180.0 )
          v7 = (float)((float)v7 - (float)360.0);
        if ( v7 < 0.0 )
          v8 = &pb_ss_BodyRotationYawRight;
        else
          v8 = &pb_ss_BodyRotationYawLeft;
        v9 = (float)((float)v7 / (float)__fabs(v8->valueFloat));
        if ( v9 >= -1.0 )
        {
          if ( v9 > 1.0 )
            v9 = 1.0;
        }
        else
        {
          v9 = -1.0;
        }
        this->behaviors.sprintSlide.bodyRotationPos.p0.x = v9;
        p_bodyRotationPos = &this->behaviors.sprintSlide.bodyRotationPos;
        v11 = idMath::AngleNormalize360(angle: (float)(v44.x - v43[0]));
        if ( v11 > 180.0 )
          v11 = (float)((float)v11 - (float)360.0);
        if ( v11 < 0.0 )
          v12 = &pb_ss_BodyRotationPitchDown;
        else
          v12 = &pb_ss_BodyRotationPitchUp;
        v13 = (float)((float)v11 / (float)__fabs(v12->valueFloat));
        if ( v13 >= -1.0 )
        {
          if ( v13 > 1.0 )
            v13 = 1.0;
        }
        else
        {
          v13 = -1.0;
        }
        this->behaviors.sprintSlide.bodyRotationPos.p0.y = v13;
        if ( (float)((float)(this->behaviors.sprintSlide.bodyRotationPos.p0.x
                           * this->behaviors.sprintSlide.bodyRotationPos.p0.x)
                   + (float)(this->behaviors.sprintSlide.bodyRotationPos.p0.y
                           * this->behaviors.sprintSlide.bodyRotationPos.p0.y)) > 1.0 )
        {
          v14 = this->behaviors.sprintSlide.bodyRotationPos.p0.y;
          _FP9 = (float)((float)((float)(this->behaviors.sprintSlide.bodyRotationPos.p0.x
                                       * this->behaviors.sprintSlide.bodyRotationPos.p0.x)
                               + (float)(this->behaviors.sprintSlide.bodyRotationPos.p0.y
                                       * this->behaviors.sprintSlide.bodyRotationPos.p0.y))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f7, f9, f10, f0 }
          v17 = __frsqrte(_FP7);
          v18 = (float)((float)-(float)((float)((float)((float)v17
                                                      * (float)((float)((float)(this->behaviors.sprintSlide.bodyRotationPos.p0.x
                                                                              * this->behaviors.sprintSlide.bodyRotationPos.p0.x)
                                                                      + (float)(this->behaviors.sprintSlide.bodyRotationPos.p0.y
                                                                              * this->behaviors.sprintSlide.bodyRotationPos.p0.y))
                                                              * (float)0.5))
                                              * (float)v17)
                                      - (float)1.5)
                      * (float)v17);
          v19 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)((float)(p_bodyRotationPos->p0.x * p_bodyRotationPos->p0.x) + (float)((float)v14 * (float)v14))
                                                                                              * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17)
                                              * (float)((float)((float)(p_bodyRotationPos->p0.x * p_bodyRotationPos->p0.x)
                                                              + (float)((float)v14 * (float)v14))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                              * (float)((float)((float)(p_bodyRotationPos->p0.x * p_bodyRotationPos->p0.x)
                                                                                              + (float)((float)v14 * (float)v14))
                                                                                      * (float)0.5))
                                                                      * (float)v17)
                                                              - (float)1.5)
                                              * (float)v17))
                              - (float)1.5);
          v20 = (float)((float)-(float)((float)((float)((float)((float)v19 * (float)v18)
                                                      * (float)((float)((float)(this->behaviors.sprintSlide.bodyRotationPos.p0.x
                                                                              * this->behaviors.sprintSlide.bodyRotationPos.p0.x)
                                                                      + (float)(this->behaviors.sprintSlide.bodyRotationPos.p0.y
                                                                              * this->behaviors.sprintSlide.bodyRotationPos.p0.y))
                                                              * (float)0.5))
                                              * (float)((float)v19 * (float)v18))
                                      - (float)1.5)
                      * (float)((float)v19 * (float)v18));
          p_bodyRotationPos->p0.x = (float)((float)-(float)((float)((float)((float)((float)v19 * (float)v18)
                                                                          * (float)((float)((float)(p_bodyRotationPos->p0.x
                                                                                                  * p_bodyRotationPos->p0.x)
                                                                                          + (float)(p_bodyRotationPos->p0.y
                                                                                                  * p_bodyRotationPos->p0.y))
                                                                                  * (float)0.5))
                                                                  * (float)((float)v19 * (float)v18))
                                                          - (float)1.5)
                                          * (float)((float)v19 * (float)v18))
                                  * p_bodyRotationPos->p0.x;
          this->behaviors.sprintSlide.bodyRotationPos.p0.y = (float)v20 * (float)v14;
        }
      }
      else
      {
        p_bodyRotationPos = &this->behaviors.sprintSlide.bodyRotationPos;
        x = vec2_origin.x;
        this->behaviors.sprintSlide.bodyRotationPos.p1 = vec2_origin;
        this->behaviors.sprintSlide.bodyRotationPos.p0.x = x;
        this->behaviors.sprintSlide.bodyRotationPos.p0.y = this->behaviors.sprintSlide.bodyRotationPos.p1.y;
      }
      if ( pb_ss_EnableBodyRotation.valueInteger == 2 )
      {
        this->behaviors.sprintSlide.bodyRotationPos.p1.x = p_bodyRotationPos->p0.x;
        this->behaviors.sprintSlide.bodyRotationPos.p1.y = p_bodyRotationPos->p0.y;
      }
      else
      {
        v22 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
        idSpring<idVec2>::Update(this: p_bodyRotationPos, dt: v22);
      }
      p_p1 = &this->behaviors.sprintSlide.bodyRotationPos.p1;
      if ( (float)((float)(this->behaviors.sprintSlide.bodyRotationPos.p1.x
                         * this->behaviors.sprintSlide.bodyRotationPos.p1.x)
                 + (float)(this->behaviors.sprintSlide.bodyRotationPos.p1.y
                         * this->behaviors.sprintSlide.bodyRotationPos.p1.y)) > 1.0 )
      {
        v24 = this->behaviors.sprintSlide.bodyRotationPos.p1.y;
        _FP9 = (float)((float)((float)(this->behaviors.sprintSlide.bodyRotationPos.p1.x
                                     * this->behaviors.sprintSlide.bodyRotationPos.p1.x)
                             + (float)(this->behaviors.sprintSlide.bodyRotationPos.p1.y
                                     * this->behaviors.sprintSlide.bodyRotationPos.p1.y))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f7, f9, f10, f0 }
        v27 = __frsqrte(_FP7);
        v28 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27
                                                                                            * (float)((float)((float)(p_p1->x * p_p1->x) + (float)(p_p1->y * p_p1->y)) * (float)0.5))
                                                                                    * (float)v27)
                                                                            - (float)1.5)
                                                            * (float)v27)
                                                    * (float)((float)((float)(p_p1->x * p_p1->x)
                                                                    + (float)(p_p1->y * p_p1->y))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v27
                                                                                    * (float)((float)((float)(p_p1->x * p_p1->x) + (float)(p_p1->y * p_p1->y))
                                                                                            * (float)0.5))
                                                                            * (float)v27)
                                                                    - (float)1.5)
                                                    * (float)v27))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v27
                                                            * (float)((float)((float)(p_p1->x * p_p1->x)
                                                                            + (float)(p_p1->y * p_p1->y))
                                                                    * (float)0.5))
                                                    * (float)v27)
                                            - (float)1.5)
                            * (float)v27));
        v29 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)(p_p1->x * p_p1->x) + (float)(p_p1->y * p_p1->y)) * (float)0.5)) * (float)v27) - (float)1.5) * (float)v27)
                                                                                            * (float)((float)((float)(p_p1->x * p_p1->x) + (float)(p_p1->y * p_p1->y)) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)(p_p1->x * p_p1->x) + (float)(p_p1->y * p_p1->y)) * (float)0.5)) * (float)v27) - (float)1.5)
                                                                                            * (float)v27))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)(p_p1->x * p_p1->x) + (float)(p_p1->y * p_p1->y)) * (float)0.5))
                                                                                            * (float)v27)
                                                                                    - (float)1.5)
                                                                    * (float)v27))
                                                    * (float)((float)((float)(p_p1->x * p_p1->x)
                                                                    + (float)(p_p1->y * p_p1->y))
                                                            * (float)0.5))
                                            * (float)v28)
                                    - (float)1.5)
                    * (float)v28);
        p_p1->x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)(p_p1->x * p_p1->x) + (float)(p_p1->y * p_p1->y)) * (float)0.5)) * (float)v27) - (float)1.5) * (float)v27)
                                                                                                * (float)((float)((float)(p_p1->x * p_p1->x) + (float)(p_p1->y * p_p1->y)) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)(p_p1->x * p_p1->x) + (float)(p_p1->y * p_p1->y)) * (float)0.5)) * (float)v27) - (float)1.5)
                                                                                                * (float)v27))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)(p_p1->x * p_p1->x) + (float)(p_p1->y * p_p1->y)) * (float)0.5))
                                                                                                * (float)v27)
                                                                                        - (float)1.5)
                                                                        * (float)v27))
                                                        * (float)((float)((float)(p_p1->x * p_p1->x)
                                                                        + (float)(p_p1->y * p_p1->y))
                                                                * (float)0.5))
                                                * (float)v28)
                                        - (float)1.5)
                        * (float)v28)
                * p_p1->x;
        this->behaviors.sprintSlide.bodyRotationPos.p1.y = (float)v29 * (float)v24;
      }
      v30 = __fsqrts((float)((float)(this->behaviors.sprintSlide.bodyRotationPos.p1.y
                                   * this->behaviors.sprintSlide.bodyRotationPos.p1.y)
                           + (float)(this->behaviors.sprintSlide.bodyRotationPos.p1.x
                                   * this->behaviors.sprintSlide.bodyRotationPos.p1.x)));
      if ( v30 >= 0.0 )
      {
        if ( v30 > 1.0 )
          v30 = 1.0;
      }
      else
      {
        v30 = 0.0;
      }
      this->behaviors.sprintSlide.bodyRotationAnimWeights[0] = -(float)((float)((float)v30 * (float)v30) - (float)1.0);
      if ( v30 == 0.0 )
      {
        this->behaviors.sprintSlide.bodyRotationAnimWeights[1] = 0.0;
        this->behaviors.sprintSlide.bodyRotationAnimWeights[2] = 0.0;
        this->behaviors.sprintSlide.bodyRotationAnimWeights[3] = 0.0;
      }
      else
      {
        v31 = (float)(p_p1->x * p_p1->x);
        if ( p_p1->x < 0.0 )
        {
          this->behaviors.sprintSlide.bodyRotationAnimWeights[1] = 0.0;
          this->behaviors.sprintSlide.bodyRotationAnimWeights[2] = v31;
        }
        else
        {
          this->behaviors.sprintSlide.bodyRotationAnimWeights[1] = p_p1->x * p_p1->x;
          this->behaviors.sprintSlide.bodyRotationAnimWeights[2] = 0.0;
        }
        v32 = (float)(this->behaviors.sprintSlide.bodyRotationPos.p1.y * this->behaviors.sprintSlide.bodyRotationPos.p1.y);
        if ( this->behaviors.sprintSlide.bodyRotationPos.p1.y < 0.0 )
        {
          this->behaviors.sprintSlide.bodyRotationAnimWeights[3] = 0.0;
          this->behaviors.sprintSlide.bodyRotationAnimWeights[4] = v32;
LABEL_47:
          this->behaviors.sprintSlide.bodyRotationAlpha.p0.x = 1.0;
          v33 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
          idSpring<idVec1>::Update(this: &this->behaviors.sprintSlide.bodyRotationAlpha, dt: v33);
          p_additiveSyncedAnimator = &this->thirdPersonLegs->additiveSyncedAnimator;
          v35 = this->behaviors.sprintSlide.bodyRotationAlpha.p1.x;
          v36 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          idAnimator_Synced::SetAnimHandlesAndWeights(
            this: p_additiveSyncedAnimator,
            animator: TreeAnimatorFromPresentable,
            curTime: v36,
            handles: this->behaviors.sprintSlide.bodyRotationLegsAnimAliasHandles,
            numAnims: 5,
            weights: this->behaviors.sprintSlide.bodyRotationAnimWeights,
            numWeights: 5);
          v37 = &this->thirdPersonLegs->additiveSyncedAnimator;
          thirdPersonLegs = this->thirdPersonLegs;
          v39 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          v40 = thirdPersonLegs->GetAnimStack_2(this: thirdPersonLegs);
          idAnimator_Base::Blend(
            this: v37,
            stack: v40,
            curTime: v39,
            targetAlpha: v35,
            blendDurationMS: v41,
            reset: 10,
            a7: 1);
          return;
        }
        this->behaviors.sprintSlide.bodyRotationAnimWeights[3] = this->behaviors.sprintSlide.bodyRotationPos.p1.y
                                                               * this->behaviors.sprintSlide.bodyRotationPos.p1.y;
      }
      this->behaviors.sprintSlide.bodyRotationAnimWeights[4] = 0.0;
      goto LABEL_47;
    }
  }
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_StartSlide@idPlayer@@QAAXXZ
// EA  : 0x82E49A10
// RVA : 0x00E49A10
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_StartSlide(idPlayer *this)
{
  idPlayer::idPlayerBehaviorSprintSlide *p_sprintSlide; // r28
  idPresentable *presentable; // r3
  int v4; // r3
  idPresentable *v5; // r3
  int v6; // r3
  idPhysics_Player *Physics; // r3
  double friction; // fp1
  idAlignedEntity *thirdPersonLegs; // r31
  idPresentable *v10; // r11
  idAlignedEntity *v11; // r31
  idPresentable *v12; // r10
  bool v13; // r27
  idPhysics *v14; // r3
  float *v15; // r3
  float *p_x; // r31
  double y; // fp9
  double v18; // fp6
  double v21; // fp2
  double v22; // fp5
  double v23; // fp3
  double v24; // fp2
  idPresentable *v25; // r3
  float *v26; // r3
  double z; // fp11
  double v28; // fp10
  double v31; // fp2
  double v32; // fp6
  double v33; // fp4
  double v34; // fp3
  idPresentable *v35; // r3
  idPresentablePlayer *v36; // r3
  idPresentable *v37; // r3
  idPresentablePlayer *v38; // r3
  int v39; // [sp+60h] [-70h] BYREF
  _BYTE v40[24]; // [sp+68h] [-68h] BYREF

  this->behaviors.sprintSlide.startSlide = false;
  this->behaviors.sprintSlide.endSlide = false;
  p_sprintSlide = &this->behaviors.sprintSlide;
  this->behaviors.sprintSlide.slideStartTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = 0;
  *(_BYTE *)(v4 + 37536) = 1;
  idSpring<idVec2>::SetConstants(
    this: &p_sprintSlide->bodyRotationPos,
    _k: pb_ss_BodyRotationPosSpringK.valueFloat,
    _c: -1.0);
  idSpring<idVec1>::SetConstants(
    this: &p_sprintSlide->bodyRotationAlpha,
    _k: pb_ss_BodyRotationAlphaSpringK.valueFloat,
    _c: -1.0);
  idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
    this,
    constrain: false,
    heading: nullptr,
    maxDeltaPitch: 0.0,
    maxDeltaYaw: 0.0,
    rate: 0.0);
  idSpringCamera::InitSprings(this: this->springCamera, k: pb_ss_SpringCameraPosK.valueFloat);
  if ( pb_ss_UpdateAfterPhysics.valueInteger != 0 )
    this->springCamera->manualUpdate = true;
  p_sprintSlide->legsFwdDirSpring.restLength = 0.0;
  p_sprintSlide->legsFwdDirSpring.p0.x = 0.0;
  p_sprintSlide->legsFwdDirSpring.p0.z = 0.0;
  p_sprintSlide->legsFwdDirSpring.p0.y = 0.0;
  p_sprintSlide->legsFwdDirSpring.k = 1.0;
  p_sprintSlide->legsFwdDirSpring.m = 1.0;
  p_sprintSlide->legsFwdDirSpring.c = 2.0;
  p_sprintSlide->legsFwdDirSpring.p1.z = 0.0;
  p_sprintSlide->legsFwdDirSpring.p1.y = 0.0;
  p_sprintSlide->legsFwdDirSpring.p1.x = 0.0;
  p_sprintSlide->legsFwdDirSpring.vel.z = 0.0;
  p_sprintSlide->legsFwdDirSpring.vel.y = 0.0;
  p_sprintSlide->legsFwdDirSpring.vel.x = 0.0;
  p_sprintSlide->legsFwdDirSpring.maxSpeed = 0.0;
  p_sprintSlide->legsFwdDirSpring.pMin.z = 0.0;
  p_sprintSlide->legsFwdDirSpring.pMin.y = 0.0;
  p_sprintSlide->legsFwdDirSpring.pMin.x = 0.0;
  p_sprintSlide->legsFwdDirSpring.hasPMin = false;
  p_sprintSlide->legsFwdDirSpring.pMax.z = 0.0;
  p_sprintSlide->legsFwdDirSpring.pMax.y = 0.0;
  p_sprintSlide->legsFwdDirSpring.pMax.x = 0.0;
  p_sprintSlide->legsFwdDirSpring.hasPMax = false;
  idSpring<idVec3>::SetConstants(
    this: &p_sprintSlide->legsFwdDirSpring,
    _k: pb_ss_LegsFwdDirSpringK.valueFloat,
    _c: -1.0);
  v5 = this->presentable;
  if ( v5 != nullptr )
    v6 = (int)v5->GetPlayerInterface_2(this: v5);
  else
    v6 = 0;
  *(idVec3 *)(v6 + 45212) = vec3_origin;
  *(idMat3 *)(v6 + 45224) = mat3_identity;
  Physics = (idPhysics_Player *)idEntity::GetPhysics(this);
  friction = p_sprintSlide->friction;
  if ( friction < 0.0 )
    friction = pb_ss_SlideFriction.valueFloat;
  idPhysics_Player::SetSlideFriction(this: Physics, friction);
  thirdPersonLegs = this->thirdPersonLegs;
  v10 = thirdPersonLegs->presentable;
  if ( v10 == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
    v10 = thirdPersonLegs->presentable;
  }
  p_sprintSlide->legsDeferredSave = v10->model->useDeferredPosition;
  v11 = this->thirdPersonLegs;
  v12 = v11->presentable;
  v13 = pb_ss_UseDeferredLegs.valueInteger != 0;
  if ( v12 == nullptr )
  {
    idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
    v12 = v11->presentable;
  }
  v12->model->useDeferredPosition = v13;
  p_sprintSlide->springCamForceCalculateViewStageSave = this->springCamera->forceCalculateViewStage;
  this->springCamera->forceCalculateViewStage = pb_ss_SpringCamCalcViewStage.valueInteger;
  v14 = idEntity::GetPhysics(this);
  v15 = (float *)((int (__fastcall *)(_BYTE *))v14->GetLinearVelocity)(a1: v40);
  p_sprintSlide->forwardDir.x = *v15;
  p_x = &p_sprintSlide->forwardDir.x;
  p_sprintSlide->forwardDir.y = v15[1];
  p_sprintSlide->forwardDir.z = v15[2];
  p_sprintSlide->forwardDir.z = 0.0;
  y = p_sprintSlide->forwardDir.y;
  v18 = (float)((float)((float)0.0 * (float)0.0)
              + (float)((float)(p_sprintSlide->forwardDir.x * p_sprintSlide->forwardDir.x)
                      + (float)(p_sprintSlide->forwardDir.y * p_sprintSlide->forwardDir.y)));
  _FP5 = (float)((float)((float)((float)0.0 * (float)0.0)
                       + (float)((float)(p_sprintSlide->forwardDir.x * p_sprintSlide->forwardDir.x)
                               + (float)(p_sprintSlide->forwardDir.y * p_sprintSlide->forwardDir.y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f0 }
  v21 = __frsqrte(_FP3);
  v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                                      * (float)((float)((float)((float)0.0 * (float)0.0) + (float)((float)(p_sprintSlide->forwardDir.x * p_sprintSlide->forwardDir.x) + (float)(p_sprintSlide->forwardDir.y * p_sprintSlide->forwardDir.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v21)
                                                                      - (float)1.5)
                                                      * (float)v21)
                                              * (float)((float)((float)((float)0.0 * (float)0.0)
                                                              + (float)((float)(p_sprintSlide->forwardDir.x
                                                                              * p_sprintSlide->forwardDir.x)
                                                                      + (float)(p_sprintSlide->forwardDir.y
                                                                              * p_sprintSlide->forwardDir.y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v21
                                                                              * (float)((float)((float)((float)0.0 * (float)0.0)
                                                                                              + (float)((float)(p_sprintSlide->forwardDir.x * p_sprintSlide->forwardDir.x) + (float)(p_sprintSlide->forwardDir.y * p_sprintSlide->forwardDir.y)))
                                                                                      * (float)0.5))
                                                                      * (float)v21)
                                                              - (float)1.5)
                                              * (float)v21))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v21
                                                      * (float)((float)((float)((float)0.0 * (float)0.0)
                                                                      + (float)((float)(p_sprintSlide->forwardDir.x
                                                                                      * p_sprintSlide->forwardDir.x)
                                                                              + (float)(p_sprintSlide->forwardDir.y
                                                                                      * p_sprintSlide->forwardDir.y)))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21));
  v23 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)0.0 * (float)0.0) + (float)((float)(p_sprintSlide->forwardDir.x * p_sprintSlide->forwardDir.x) + (float)(p_sprintSlide->forwardDir.y * p_sprintSlide->forwardDir.y))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                      * (float)v21)
                                                                              * (float)((float)((float)((float)0.0 * (float)0.0)
                                                                                              + (float)((float)(p_sprintSlide->forwardDir.x * p_sprintSlide->forwardDir.x) + (float)(p_sprintSlide->forwardDir.y * p_sprintSlide->forwardDir.y)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)0.0 * (float)0.0) + (float)((float)(p_sprintSlide->forwardDir.x * p_sprintSlide->forwardDir.x) + (float)(p_sprintSlide->forwardDir.y * p_sprintSlide->forwardDir.y))) * (float)0.5)) * (float)v21)
                                                                                              - (float)1.5)
                                                                              * (float)v21))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v21
                                                                                      * (float)((float)((float)((float)0.0 * (float)0.0) + (float)((float)(p_sprintSlide->forwardDir.x * p_sprintSlide->forwardDir.x) + (float)(p_sprintSlide->forwardDir.y * p_sprintSlide->forwardDir.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v21)
                                                                      - (float)1.5)
                                                      * (float)v21))
                                      * (float)((float)((float)((float)0.0 * (float)0.0)
                                                      + (float)((float)(p_sprintSlide->forwardDir.x
                                                                      * p_sprintSlide->forwardDir.x)
                                                              + (float)(p_sprintSlide->forwardDir.y
                                                                      * p_sprintSlide->forwardDir.y)))
                                              * (float)0.5))
                              * (float)v22)
                      - (float)1.5);
  v24 = (float)((float)v23
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                                              * (float)((float)((float)((float)0.0 * (float)0.0) + (float)((float)(p_sprintSlide->forwardDir.x * p_sprintSlide->forwardDir.x) + (float)(p_sprintSlide->forwardDir.y * p_sprintSlide->forwardDir.y))) * (float)0.5))
                                                                                      * (float)v21)
                                                                              - (float)1.5)
                                                              * (float)v21)
                                                      * (float)((float)((float)((float)0.0 * (float)0.0)
                                                                      + (float)((float)(p_sprintSlide->forwardDir.x
                                                                                      * p_sprintSlide->forwardDir.x)
                                                                              + (float)(p_sprintSlide->forwardDir.y
                                                                                      * p_sprintSlide->forwardDir.y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v21
                                                                                      * (float)((float)((float)((float)0.0 * (float)0.0) + (float)((float)(p_sprintSlide->forwardDir.x * p_sprintSlide->forwardDir.x) + (float)(p_sprintSlide->forwardDir.y * p_sprintSlide->forwardDir.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v21)
                                                                      - (float)1.5)
                                                      * (float)v21))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v21
                                                              * (float)((float)((float)((float)0.0 * (float)0.0)
                                                                              + (float)((float)(p_sprintSlide->forwardDir.x
                                                                                              * p_sprintSlide->forwardDir.x)
                                                                                      + (float)(p_sprintSlide->forwardDir.y
                                                                                              * p_sprintSlide->forwardDir.y)))
                                                                      * (float)0.5))
                                                      * (float)v21)
                                              - (float)1.5)
                              * (float)v21)));
  p_sprintSlide->forwardDir.x = p_sprintSlide->forwardDir.x * (float)v24;
  p_sprintSlide->forwardDir.y = (float)y * (float)v24;
  p_sprintSlide->forwardDir.z = (float)0.0 * (float)v24;
  p_sprintSlide->forwardSpeed = (float)v24 * (float)v18;
  if ( (float)((float)(p_sprintSlide->forwardDir.z * p_sprintSlide->forwardDir.z)
             + (float)((float)(p_sprintSlide->forwardDir.x * p_sprintSlide->forwardDir.x)
                     + (float)(p_sprintSlide->forwardDir.y * p_sprintSlide->forwardDir.y))) == 0.0 )
  {
    v25 = this->presentable;
    if ( v25 != nullptr )
      v26 = (float *)v25->GetPlayerInterface_2(this: v25);
    else
      v26 = nullptr;
    *p_x = v26[11636];
    p_sprintSlide->forwardDir.y = v26[11637];
    p_sprintSlide->forwardDir.z = v26[11638];
    p_sprintSlide->forwardDir.z = 0.0;
    z = p_sprintSlide->forwardDir.z;
    v28 = p_sprintSlide->forwardDir.y;
    _FP5 = (float)((float)((float)(p_x[2] * p_x[2]) + (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f5, f6, f0 }
    v31 = __frsqrte(_FP3);
    v32 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31
                                                                                        * (float)((float)((float)(p_x[2] * p_x[2]) + (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])))
                                                                                                * (float)0.5))
                                                                                * (float)v31)
                                                                        - (float)1.5)
                                                        * (float)v31)
                                                * (float)((float)((float)(p_x[2] * p_x[2])
                                                                + (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v31
                                                                                * (float)((float)((float)(p_x[2] * p_x[2])
                                                                                                + (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])))
                                                                                        * (float)0.5))
                                                                        * (float)v31)
                                                                - (float)1.5)
                                                * (float)v31))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v31
                                                        * (float)((float)((float)(p_x[2] * p_x[2])
                                                                        + (float)((float)(*p_x * *p_x)
                                                                                + (float)(p_x[1] * p_x[1])))
                                                                * (float)0.5))
                                                * (float)v31)
                                        - (float)1.5)
                        * (float)v31));
    v33 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)(p_x[2] * p_x[2]) + (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1]))) * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                        * (float)v31)
                                                                                * (float)((float)((float)(p_x[2] * p_x[2])
                                                                                                + (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)(p_x[2] * p_x[2]) + (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1]))) * (float)0.5)) * (float)v31)
                                                                                                - (float)1.5)
                                                                                * (float)v31))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v31
                                                                                        * (float)((float)((float)(p_x[2] * p_x[2]) + (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])))
                                                                                                * (float)0.5))
                                                                                * (float)v31)
                                                                        - (float)1.5)
                                                        * (float)v31))
                                        * (float)((float)((float)(p_x[2] * p_x[2])
                                                        + (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])))
                                                * (float)0.5))
                                * (float)v32)
                        - (float)1.5);
    v34 = (float)((float)v33
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31
                                                                                                * (float)((float)((float)(p_x[2] * p_x[2]) + (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1]))) * (float)0.5))
                                                                                        * (float)v31)
                                                                                - (float)1.5)
                                                                * (float)v31)
                                                        * (float)((float)((float)(p_x[2] * p_x[2])
                                                                        + (float)((float)(*p_x * *p_x)
                                                                                + (float)(p_x[1] * p_x[1])))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v31
                                                                                        * (float)((float)((float)(p_x[2] * p_x[2]) + (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])))
                                                                                                * (float)0.5))
                                                                                * (float)v31)
                                                                        - (float)1.5)
                                                        * (float)v31))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v31
                                                                * (float)((float)((float)(p_x[2] * p_x[2])
                                                                                + (float)((float)(*p_x * *p_x)
                                                                                        + (float)(p_x[1] * p_x[1])))
                                                                        * (float)0.5))
                                                        * (float)v31)
                                                - (float)1.5)
                                * (float)v31)));
    *p_x = *p_x
         * (float)((float)v33
                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31
                                                                                                 * (float)((float)((float)(p_x[2] * p_x[2]) + (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1]))) * (float)0.5))
                                                                                         * (float)v31)
                                                                                 - (float)1.5)
                                                                 * (float)v31)
                                                         * (float)((float)((float)(p_x[2] * p_x[2])
                                                                         + (float)((float)(*p_x * *p_x)
                                                                                 + (float)(p_x[1] * p_x[1])))
                                                                 * (float)0.5))
                                                 * (float)((float)-(float)((float)((float)((float)v31
                                                                                         * (float)((float)((float)(p_x[2] * p_x[2]) + (float)((float)(*p_x * *p_x) + (float)(p_x[1] * p_x[1])))
                                                                                                 * (float)0.5))
                                                                                 * (float)v31)
                                                                         - (float)1.5)
                                                         * (float)v31))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v31
                                                                 * (float)((float)((float)(p_x[2] * p_x[2])
                                                                                 + (float)((float)(*p_x * *p_x)
                                                                                         + (float)(p_x[1] * p_x[1])))
                                                                         * (float)0.5))
                                                         * (float)v31)
                                                 - (float)1.5)
                                 * (float)v31)));
    p_sprintSlide->forwardDir.y = (float)v28 * (float)v34;
    p_sprintSlide->forwardDir.z = (float)z * (float)v34;
  }
  p_sprintSlide->legsFwdDirSpring.p0.x = *p_x;
  p_sprintSlide->legsFwdDirSpring.p0.y = p_sprintSlide->forwardDir.y;
  p_sprintSlide->legsFwdDirSpring.p0.z = p_sprintSlide->forwardDir.z;
  idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraintExplicit(
    this,
    constrain: true,
    heading: (idAngles *)&p_sprintSlide->forwardDir,
    minDeltaPitch: pb_ss_ViewConstraintPitchUp.valueFloat,
    maxDeltaPitch: pb_ss_ViewConstraintPitchDown.valueFloat,
    minDeltaYaw: pb_ss_ViewConstraintYawRight.valueFloat,
    maxDeltaYaw: pb_ss_ViewConstraintYawLeft.valueFloat,
    minDeltaRoll: 0.0,
    maxDeltaRoll: 0.0,
    rate: 0.0);
  idPlayer::PlayerBehavior_SprintSlide_StartMovement(this);
  v35 = this->presentable;
  v39 = 0;
  if ( v35 != nullptr )
    v36 = v35->GetPlayerInterface_2(this: v35);
  else
    v36 = nullptr;
  p_sprintSlide->inhibitFlagsSave = idPresentablePlayer::GetInhibitFlags(this: v36, specificInhibitButtons: &v39);
  v37 = this->presentable;
  if ( v37 != nullptr )
    v38 = v37->GetPlayerInterface_2(this: v37);
  else
    v38 = nullptr;
  idPresentablePlayer::SetInhibitFlags(this: v38, flags: UCMD_INHIBIT_MOVEMENT_RT);
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_SetState@idPlayer@@QAAXW4idPlayerBehaviorSprintSlideState_t@1@@Z
// EA  : 0x82E49F68
// RVA : 0x00E49F68
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_SetState(
        idPlayer *this,
        idPlayer::idPlayerBehaviorSprintSlideState_t state)
{
  const char *v4; // r29
  int v5; // r3
  const char *v6; // r4
  blendParms_t v7; // [sp+50h] [-60h] BYREF
  blendParms_t v8; // [sp+70h] [-40h] BYREF

  if ( pb_ss_DebugTraceStates.valueInteger != 0 )
  {
    v4 = stateNames_0[state];
    v5 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(
      fmt: "^2(%d)%s - Setting sprint slide state: %s\n",
      v5,
      "idPlayer::PlayerBehavior_SprintSlide_SetState",
      v4);
  }
  blendParms_t::blendParms_t(this: &v8);
  blendParms_t::blendParms_t(this: &v7);
  blendParms_t::SetDurationMS(this: &v7, ms: pb_ss_HandsAdditiveAnimBlendMS.valueInteger);
  if ( (unsigned int)(state - 1) > 3 )
    goto LABEL_13;
  if ( state == SPRINT_SLIDE_STATE_END_STAND )
  {
    v6 = "sprintSlide/slide_out_stand";
LABEL_12:
    idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
      this,
      animName: v6,
      loop: false,
      durationMS: -1,
      blendParms: &v7,
      rateScale: 1.0);
    goto LABEL_13;
  }
  if ( state == SPRINT_SLIDE_STATE_END_CROUCH )
  {
    v6 = "sprintSlide/slide_out_crouch";
    goto LABEL_12;
  }
  if ( state != SPRINT_SLIDE_STATE_SLIDING )
  {
    v6 = "sprintSlide/slide_out_fall";
    goto LABEL_12;
  }
  idPlayer::PlayerBehavior_SprintSlide_StartSlide(this);
  idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
    this,
    animName: "sprintSlide/slide_into",
    loop: false,
    durationMS: -1,
    blendParms: &v7,
    rateScale: 1.0);
  idPlayer::PlayerBehavior_Shared_QueueThirdPersonLegsAnim(
    this,
    animName: "sprintSlide/slide_loop",
    loop: true,
    durationMS: -1,
    blendParms: &v7,
    rateScale: 1.0);
  if ( pb_ss_PlayAdditiveLegsAnims.valueInteger != 0 )
  {
    idAlignedEntity::PlayAdditiveAnim(
      this: this->thirdPersonLegs,
      aliasName: "sprintSlide/additiveJitter",
      loop: true,
      durationMS: -1,
      _blendParms: nullptr);
    this->behaviors.sprintSlide.state = SPRINT_SLIDE_STATE_SLIDING;
    return;
  }
LABEL_13:
  this->behaviors.sprintSlide.state = state;
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_Update@idPlayer@@QAAXXZ
// EA  : 0x82E4A108
// RVA : 0x00E4A108
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_Update(idPlayer *this)
{
  bool v2; // r11
  bool v3; // r10
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idPlayer::idPlayerBehaviorSprintSlideState_t state; // r11
  idPlayer::idPlayerBehaviorSprintSlideState_t v7; // r3
  idPlayer::idPlayerBehaviorSprintSlideState_t v8; // r4
  idSpringCamera *springCamera; // r3
  __int64 v10; // r6
  int v11; // r4
  idPLogScope v12[7]; // [sp+58h] [-38h] BYREF

  if ( !common->IsMultiplayer(this: common) )
  {
    if ( (pb_ss_DebugForceSlide.flags & 0x20000) != 0 )
    {
      pb_ss_DebugForceSlide.flags &= ~0x20000u;
      if ( this->behaviors.sprintSlide.state != SPRINT_SLIDE_STATE_NONE )
      {
        v2 = false;
        v3 = true;
      }
      else
      {
        v2 = true;
        v3 = false;
      }
      this->behaviors.sprintSlide.endSlide = v3;
      this->behaviors.sprintSlide.startSlide = v2;
    }
    RD_EventBegin(name: "idPlayer::PlayerBehavior_SprintSlide_Update");
    LODWORD(v4) = "idPlayer::PlayerBehavior_SprintSlide_Update";
    HIDWORD(v4) = 2;
    idPLogScope::idPLogScope(this: v12, pl: &pLog, gMask: v4, label: v5);
    state = this->behaviors.sprintSlide.state;
    if ( (unsigned int)state > SPRINT_SLIDE_STATE_END_FALL )
      goto LABEL_22;
    if ( state == SPRINT_SLIDE_STATE_SLIDING )
    {
      idPlayer::PlayerBehavior_SprintSlide_AlignThirdPersonModels(this, extraOffset: &vec3_origin);
      idPlayer::PlayerBehavior_SprintSlide_HandleMovement(this);
      v7 = idPlayer::PlayerBehavior_SprintSlide_ShouldEndSlide(this);
      v8 = v7;
      if ( v7 != SPRINT_SLIDE_STATE_NONE )
        goto LABEL_21;
    }
    else if ( state != SPRINT_SLIDE_STATE_NONE )
    {
      if ( this->behaviors.sprintSlide.forceEndSlide
        || idAlignedEntity::IsCurAnimDone(this: this->thirdPersonLegs, numFramesAhead: -1, ignoreQueuedAnims: false) )
      {
        idPlayer::PlayerBehavior_SprintSlide_EndSlide(this);
        v8 = SPRINT_SLIDE_STATE_NONE;
LABEL_21:
        idPlayer::PlayerBehavior_SprintSlide_SetState(this, state: v8);
        goto LABEL_22;
      }
      idPlayer::PlayerBehavior_SprintSlide_AlignThirdPersonModels(this, extraOffset: &vec3_origin);
    }
    else
    {
      if ( (unsigned __int8)idPlayer::PlayerBehavior_SprintSlide_CanSlide(this) == 0
        || !this->behaviors.sprintSlide.startSlide )
      {
        idPLogScope::~idPLogScope(this: v12);
LABEL_25:
        RD_EventEnd();
        return;
      }
      idPlayer::PlayerBehavior_SprintSlide_SetState(this, state: SPRINT_SLIDE_STATE_SLIDING);
      idPlayer::PlayerBehavior_SprintSlide_AlignThirdPersonModels(this, extraOffset: &vec3_origin);
    }
LABEL_22:
    springCamera = this->springCamera;
    if ( springCamera->manualUpdate )
      idSpringCamera::Update(this: springCamera);
    idPlayer::PlayerBehavior_SprintSlide_HandleAdditiveAnims(this);
    idPlayer::PlayerBehavior_SprintSlide_HandleSlideSound(this);
    idPlayer::PlayerBehavior_SprintSlide_HandleBodyRotation(this);
    idPlayer::PlayerBehavior_SprintSlide_HandleCameraShake(this);
    idPlayer::PlayerBehavior_SprintSlide_DebugHandle(this, a2: v11, a3: v10);
    idPLogScope::~idPLogScope(this: v12);
    goto LABEL_25;
  }
}


// ========================================================================
// __unwind$493159
// EA  : 0x82E4A2F8
// RVA : 0x00E4A2F8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void _unwind_493159()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$493160
// EA  : 0x82E4A320
// RVA : 0x00E4A320
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void _unwind_493160()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 88));
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_HandleEvent@idPlayer@@QAAXW4idPlayerBehaviorEvent_t@@@Z
// EA  : 0x82E4A348
// RVA : 0x00E4A348
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_HandleEvent(idPlayer *this, idPlayerBehaviorEvent_t event)
{
  if ( event == PBE_SPRING_CAMERA_VIEW_UPDATED )
  {
    if ( this->behaviors.sprintSlide.state != SPRINT_SLIDE_STATE_NONE )
      idPlayer::PlayerBehavior_SprintSlide_AlignFirstPersonHands(this);
  }
  else if ( event == PBE_PHYSICS_UPDATED && pb_ss_UpdateAfterPhysics.valueInteger != 0 )
  {
    idPlayer::PlayerBehavior_SprintSlide_Update(this);
  }
}


// ========================================================================
// ?PlayerBehavior_SprintSlide_Handle@idPlayer@@QAAXXZ
// EA  : 0x82E4A388
// RVA : 0x00E4A388
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_SprintSlide_Handle(idPlayer *this)
{
  if ( pb_ss_UpdateAfterPhysics.valueInteger == 0 )
    idPlayer::PlayerBehavior_SprintSlide_Update(this);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_Enable''
// EA  : 0x8338DC78
// RVA : 0x0138DC78
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_Enable__()
{
  idCVar::idCVar(
    this: &pb_ss_Enable,
    name: "pb_ss_Enable",
    value: "1",
    flags: 1,
    description: "Enable player contextual slide behavior",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_Enable__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_Debug''
// EA  : 0x8338DCD0
// RVA : 0x0138DCD0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_Debug__()
{
  idCVar::idCVar(
    this: &pb_ss_Debug,
    name: "pb_ss_Debug",
    value: "0",
    flags: 1,
    description: "Debug player contextual slide behavior",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_Debug__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_DebugTraceStates''
// EA  : 0x8338DD28
// RVA : 0x0138DD28
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_DebugTraceStates__()
{
  idCVar::idCVar(
    this: &pb_ss_DebugTraceStates,
    name: "pb_ss_DebugTraceStates",
    value: "0",
    flags: 1,
    description: "Debug player contextual slide behavior states",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_DebugTraceStates__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_DebugForceSlide''
// EA  : 0x8338DD80
// RVA : 0x0138DD80
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_DebugForceSlide__()
{
  idCVar::idCVar(
    this: &pb_ss_DebugForceSlide,
    name: "pb_ss_DebugForceSlide",
    value: "0",
    flags: 1,
    description: "Debug player - Forces the player into a slide position for debugging",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_DebugForceSlide__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_DebugForceEndState''
// EA  : 0x8338DDD8
// RVA : 0x0138DDD8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_DebugForceEndState__()
{
  idCVar::idCVar(
    this: &pb_ss_DebugForceEndState,
    name: "pb_ss_DebugForceEndState",
    value: "0",
    flags: 2,
    description: "Force the end state: 1 = STAND, 2 = CROUCH, 3 = FALL",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_DebugForceEndState__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_UpdateAfterPhysics''
// EA  : 0x8338DE30
// RVA : 0x0138DE30
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_UpdateAfterPhysics__()
{
  idCVar::idCVar(
    this: &pb_ss_UpdateAfterPhysics,
    name: "pb_ss_UpdateAfterPhysics",
    value: "1",
    flags: 1,
    description: "If this is true the slide update happens after the physics update",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_UpdateAfterPhysics__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_UseDeferredHands''
// EA  : 0x8338DE88
// RVA : 0x0138DE88
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_UseDeferredHands__()
{
  idCVar::idCVar(
    this: &pb_ss_UseDeferredHands,
    name: "pb_ss_UseDeferredHands",
    value: "0",
    flags: 1,
    description: "Use deferred handling on the fp hands",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_UseDeferredHands__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_UseDeferredLegs''
// EA  : 0x8338DEE0
// RVA : 0x0138DEE0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_UseDeferredLegs__()
{
  idCVar::idCVar(
    this: &pb_ss_UseDeferredLegs,
    name: "pb_ss_UseDeferredLegs",
    value: "0",
    flags: 1,
    description: "Use deferred handling on the tp legs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_UseDeferredLegs__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_UseExtraWorldOffset''
// EA  : 0x8338DF38
// RVA : 0x0138DF38
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_UseExtraWorldOffset__()
{
  idCVar::idCVar(
    this: &pb_ss_UseExtraWorldOffset,
    name: "pb_ss_UseExtraWorldOffset",
    value: "1",
    flags: 2,
    description: "0 = don't use extra world offset to correct the hands position, 1=snap",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_UseExtraWorldOffset__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_SpringCamCalcViewStage''
// EA  : 0x8338DF90
// RVA : 0x0138DF90
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_SpringCamCalcViewStage__()
{
  idCVar::idCVar(
    this: &pb_ss_SpringCamCalcViewStage,
    name: "pb_ss_SpringCamCalcViewStage",
    value: "2",
    flags: 2,
    description: "spring camera calculate view stage to use",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_SpringCamCalcViewStage__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_EnableBodyRotation''
// EA  : 0x8338DFE8
// RVA : 0x0138DFE8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_EnableBodyRotation__()
{
  idCVar::idCVar(
    this: &pb_ss_EnableBodyRotation,
    name: "pb_ss_EnableBodyRotation",
    value: "1",
    flags: 1,
    description: "Enables Slide Body Rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_EnableBodyRotation__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_EnableBodyRotationPitch''
// EA  : 0x8338E040
// RVA : 0x0138E040
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_EnableBodyRotationPitch__()
{
  idCVar::idCVar(
    this: &pb_ss_EnableBodyRotationPitch,
    name: "pb_ss_EnableBodyRotationPitch",
    value: "0",
    flags: 1,
    description: "Enables Slide Body Pitch Rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_EnableBodyRotationPitch__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_BodyRotationYawLeft''
// EA  : 0x8338E098
// RVA : 0x0138E098
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_BodyRotationYawLeft__()
{
  idCVar::idCVar(
    this: &pb_ss_BodyRotationYawLeft,
    name: "pb_ss_BodyRotationYawLeft",
    value: "45.0",
    flags: 4,
    description: "Maximum animated angle for body models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_BodyRotationYawLeft__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_BodyRotationYawRight''
// EA  : 0x8338E0F0
// RVA : 0x0138E0F0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_BodyRotationYawRight__()
{
  idCVar::idCVar(
    this: &pb_ss_BodyRotationYawRight,
    name: "pb_ss_BodyRotationYawRight",
    value: "45.0",
    flags: 4,
    description: "Maximum animated angle for body models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_BodyRotationYawRight__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_BodyRotationPitchUp''
// EA  : 0x8338E148
// RVA : 0x0138E148
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_BodyRotationPitchUp__()
{
  idCVar::idCVar(
    this: &pb_ss_BodyRotationPitchUp,
    name: "pb_ss_BodyRotationPitchUp",
    value: "60.0",
    flags: 4,
    description: "Maximum animated angle for body models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_BodyRotationPitchUp__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_BodyRotationPitchDown''
// EA  : 0x8338E1A0
// RVA : 0x0138E1A0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_BodyRotationPitchDown__()
{
  idCVar::idCVar(
    this: &pb_ss_BodyRotationPitchDown,
    name: "pb_ss_BodyRotationPitchDown",
    value: "30.0",
    flags: 4,
    description: "Maximum animated angle for body models",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_BodyRotationPitchDown__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_BodyRotationPosSpringK''
// EA  : 0x8338E1F8
// RVA : 0x0138E1F8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_BodyRotationPosSpringK__()
{
  idCVar::idCVar(
    this: &pb_ss_BodyRotationPosSpringK,
    name: "pb_ss_BodyRotationPosSpringK",
    value: "750.0",
    flags: 4,
    description: "Spring constant for averaging the body rotation position",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_BodyRotationPosSpringK__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_BodyRotationAlphaSpringK''
// EA  : 0x8338E250
// RVA : 0x0138E250
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_BodyRotationAlphaSpringK__()
{
  idCVar::idCVar(
    this: &pb_ss_BodyRotationAlphaSpringK,
    name: "pb_ss_BodyRotationAlphaSpringK",
    value: "150.0",
    flags: 4,
    description: "Spring constant for the body rotation anim alpha",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_BodyRotationAlphaSpringK__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_ViewConstraintYawLeft''
// EA  : 0x8338E2A8
// RVA : 0x0138E2A8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_ViewConstraintYawLeft__()
{
  idCVar::idCVar(
    this: &pb_ss_ViewConstraintYawLeft,
    name: "pb_ss_ViewConstraintYawLeft",
    value: "45.0",
    flags: 4,
    description: "Maximum view angle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_ViewConstraintYawLeft__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_ViewConstraintYawRight''
// EA  : 0x8338E300
// RVA : 0x0138E300
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_ViewConstraintYawRight__()
{
  idCVar::idCVar(
    this: &pb_ss_ViewConstraintYawRight,
    name: "pb_ss_ViewConstraintYawRight",
    value: "45.0",
    flags: 4,
    description: "Maximum view angle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_ViewConstraintYawRight__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_ViewConstraintPitchUp''
// EA  : 0x8338E358
// RVA : 0x0138E358
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_ViewConstraintPitchUp__()
{
  idCVar::idCVar(
    this: &pb_ss_ViewConstraintPitchUp,
    name: "pb_ss_ViewConstraintPitchUp",
    value: "60.0",
    flags: 4,
    description: "Maximum view angle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_ViewConstraintPitchUp__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_ViewConstraintPitchDown''
// EA  : 0x8338E3B0
// RVA : 0x0138E3B0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_ViewConstraintPitchDown__()
{
  idCVar::idCVar(
    this: &pb_ss_ViewConstraintPitchDown,
    name: "pb_ss_ViewConstraintPitchDown",
    value: "30.0",
    flags: 4,
    description: "Maximum view angle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_ViewConstraintPitchDown__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_MinSpeed2D''
// EA  : 0x8338E408
// RVA : 0x0138E408
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_MinSpeed2D__()
{
  idCVar::idCVar(
    this: &pb_ss_MinSpeed2D,
    name: "pb_ss_MinSpeed2D",
    value: "140.0",
    flags: 4,
    description: "Slide ends if 2d speed goes below this value",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_MinSpeed2D__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_SlideFriction''
// EA  : 0x8338E460
// RVA : 0x0138E460
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_SlideFriction__()
{
  idCVar::idCVar(
    this: &pb_ss_SlideFriction,
    name: "pb_ss_SlideFriction",
    value: "0.5",
    flags: 4,
    description: "Friction Value To Apply while we are on the slide",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_SlideFriction__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_MaxDurationMS''
// EA  : 0x8338E4B8
// RVA : 0x0138E4B8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_MaxDurationMS__()
{
  idCVar::idCVar(
    this: &pb_ss_MaxDurationMS,
    name: "pb_ss_MaxDurationMS",
    value: "1500",
    flags: 2,
    description: "Max duration for a single slide, or 0 for unlimited",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_MaxDurationMS__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_MaxAltitude''
// EA  : 0x8338E510
// RVA : 0x0138E510
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_MaxAltitude__()
{
  idCVar::idCVar(
    this: &pb_ss_MaxAltitude,
    name: "pb_ss_MaxAltitude",
    value: "15.0",
    flags: 4,
    description: "Height off the ground to exit slide into fall",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_MaxAltitude__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_AltitudeForwardTestDist''
// EA  : 0x8338E568
// RVA : 0x0138E568
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_AltitudeForwardTestDist__()
{
  idCVar::idCVar(
    this: &pb_ss_AltitudeForwardTestDist,
    name: "pb_ss_AltitudeForwardTestDist",
    value: "75.0",
    flags: 4,
    description: "How far ahead of the player to do the altitude check",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_AltitudeForwardTestDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_AdjustSpeedForHeightScale''
// EA  : 0x8338E5C0
// RVA : 0x0138E5C0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_AdjustSpeedForHeightScale__()
{
  idCVar::idCVar(
    this: &pb_ss_AdjustSpeedForHeightScale,
    name: "pb_ss_AdjustSpeedForHeightScale",
    value: "0.75",
    flags: 4,
    description: "Scales the adjustment of speed for height change",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_AdjustSpeedForHeightScale__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_HandsAdditiveAnimBlendMS''
// EA  : 0x8338E618
// RVA : 0x0138E618
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_HandsAdditiveAnimBlendMS__()
{
  idCVar::idCVar(
    this: &pb_ss_HandsAdditiveAnimBlendMS,
    name: "pb_ss_HandsAdditiveAnimBlendMS",
    value: "60",
    flags: 2,
    description: "How long additive animations take to blend",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_HandsAdditiveAnimBlendMS__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_HandsAdditiveAnimAlphaRate''
// EA  : 0x8338E670
// RVA : 0x0138E670
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_HandsAdditiveAnimAlphaRate__()
{
  idCVar::idCVar(
    this: &pb_ss_HandsAdditiveAnimAlphaRate,
    name: "pb_ss_HandsAdditiveAnimAlphaRate",
    value: "5.0",
    flags: 4,
    description: "alpha rate for additive anim",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_HandsAdditiveAnimAlphaRate__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_HandsVelocityFrameOffset''
// EA  : 0x8338E6C8
// RVA : 0x0138E6C8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_HandsVelocityFrameOffset__()
{
  idCVar::idCVar(
    this: &pb_ss_HandsVelocityFrameOffset,
    name: "pb_ss_HandsVelocityFrameOffset",
    value: "1",
    flags: 2,
    description: "Number of frames the hands are moved ahead of the legs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_HandsVelocityFrameOffset__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_PlayAdditiveHandsAnims''
// EA  : 0x8338E720
// RVA : 0x0138E720
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_PlayAdditiveHandsAnims__()
{
  idCVar::idCVar(
    this: &pb_ss_PlayAdditiveHandsAnims,
    name: "pb_ss_PlayAdditiveHandsAnims",
    value: "1",
    flags: 1,
    description: "Play additive anims on the fp hands",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_PlayAdditiveHandsAnims__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_PlayAdditiveLegsAnims''
// EA  : 0x8338E778
// RVA : 0x0138E778
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_PlayAdditiveLegsAnims__()
{
  idCVar::idCVar(
    this: &pb_ss_PlayAdditiveLegsAnims,
    name: "pb_ss_PlayAdditiveLegsAnims",
    value: "1",
    flags: 1,
    description: "Play additive anims on the tp legs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_PlayAdditiveLegsAnims__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_SlideSpeed''
// EA  : 0x8338E7D0
// RVA : 0x0138E7D0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_SlideSpeed__()
{
  idCVar::idCVar(
    this: &pb_ss_SlideSpeed,
    name: "pb_ss_SlideSpeed",
    value: "500.0",
    flags: 4,
    description: "Default Slide Speed for Normal Slide",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_SlideSpeed__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_LegsPitchForGroundSlope''
// EA  : 0x8338E828
// RVA : 0x0138E828
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_LegsPitchForGroundSlope__()
{
  idCVar::idCVar(
    this: &pb_ss_LegsPitchForGroundSlope,
    name: "pb_ss_LegsPitchForGroundSlope",
    value: "1",
    flags: 1,
    description: "Rotates the legs to align with the ground slope",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_LegsPitchForGroundSlope__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_LegsFwdDirSpringK''
// EA  : 0x8338E880
// RVA : 0x0138E880
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_LegsFwdDirSpringK__()
{
  idCVar::idCVar(
    this: &pb_ss_LegsFwdDirSpringK,
    name: "pb_ss_LegsFwdDirSpringK",
    value: "500.0",
    flags: 4,
    description: "Spring constant for the legs forward dir spring",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_LegsFwdDirSpringK__);
}


// ========================================================================
// `dynamic initializer for 'pb_ss_SpringCameraPosK''
// EA  : 0x8338E8D8
// RVA : 0x0138E8D8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorsprintslide.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_ss_SpringCameraPosK__()
{
  idCVar::idCVar(
    this: &pb_ss_SpringCameraPosK,
    name: "pb_ss_SpringCameraPosK",
    value: "1000.0",
    flags: 4,
    description: "Tension (K) of the Spring Camera",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_ss_SpringCameraPosK__);
}

