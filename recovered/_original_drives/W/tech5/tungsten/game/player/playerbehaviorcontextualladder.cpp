
// ========================================================================
// ?PlayerBehavior_ContextualLadder_IsOnLadder@idPlayer@@QBA_NXZ
// EA  : 0x82E3F000
// RVA : 0x00E3F000
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

BOOL __fastcall idPlayer::PlayerBehavior_ContextualLadder_IsOnLadder(idPlayer *this)
{
  return this->behaviors.contextualLadder.state != CONTEXTUAL_LADDER_STATE_NONE;
}


// ========================================================================
// ?PlayerBehavior_ContextualLadder_Startup@idPlayer@@QAAXXZ
// EA  : 0x82E3F010
// RVA : 0x00E3F010
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualLadder_Startup(idPlayer *this)
{
  idAlignedEntity *thirdPersonHands; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r30
  unsigned __int16 v4; // [sp+50h] [-60h] BYREF
  unsigned __int16 v5; // [sp+52h] [-5Eh] BYREF
  unsigned __int16 v6; // [sp+54h] [-5Ch] BYREF
  unsigned __int16 v7; // [sp+56h] [-5Ah] BYREF
  unsigned __int16 v8; // [sp+58h] [-58h] BYREF
  unsigned __int16 v9; // [sp+5Ah] [-56h] BYREF
  unsigned __int16 v10; // [sp+5Ch] [-54h] BYREF
  unsigned __int16 v11; // [sp+5Eh] [-52h] BYREF
  unsigned __int16 v12; // [sp+60h] [-50h] BYREF
  unsigned __int16 v13; // [sp+62h] [-4Eh] BYREF
  unsigned __int16 v14; // [sp+64h] [-4Ch] BYREF
  unsigned __int16 v15; // [sp+66h] [-4Ah] BYREF
  unsigned __int16 v16; // [sp+68h] [-48h] BYREF
  unsigned __int16 v17; // [sp+6Ah] [-46h] BYREF
  unsigned __int16 v18; // [sp+6Ch] [-44h] BYREF
  unsigned __int16 v19; // [sp+6Eh] [-42h] BYREF
  unsigned __int16 v20; // [sp+70h] [-40h] BYREF
  unsigned __int16 v21; // [sp+72h] [-3Eh] BYREF
  unsigned __int16 v22; // [sp+74h] [-3Ch] BYREF
  unsigned __int16 v23; // [sp+76h] [-3Ah] BYREF
  unsigned __int16 v24; // [sp+78h] [-38h] BYREF
  unsigned __int16 v25; // [sp+7Ah] [-36h] BYREF
  unsigned __int16 v26; // [sp+7Ch] [-34h] BYREF

  thirdPersonHands = this->thirdPersonHands;
  if ( thirdPersonHands != nullptr && this->thirdPersonLegs != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: thirdPersonHands);
    if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->thirdPersonLegs) != nullptr
      && TreeAnimatorFromPresentable != nullptr )
    {
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v4,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_hide_to_ladder_mh");
      this->behaviors.contextualLadder.armsAliases[0].value = v4;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v5,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_hide_to_ladder_mh");
      this->behaviors.contextualLadder.armsAliases[1].value = v5;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v6,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_hide_to_ladder_mh");
      this->behaviors.contextualLadder.armsAliases[2].value = v6;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v7,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_mh_left");
      this->behaviors.contextualLadder.armsAliases[3].value = v7;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v8,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_mh_right");
      this->behaviors.contextualLadder.armsAliases[4].value = v8;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v9,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_mh_left");
      this->behaviors.contextualLadder.armsAliases[5].value = v9;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v10,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_mh_right");
      this->behaviors.contextualLadder.armsAliases[6].value = v10;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v11,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_down_left");
      this->behaviors.contextualLadder.armsAliases[7].value = v11;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v12,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_down_right");
      this->behaviors.contextualLadder.armsAliases[8].value = v12;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v13,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_up_left");
      this->behaviors.contextualLadder.armsAliases[9].value = v13;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v14,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_up_right");
      this->behaviors.contextualLadder.armsAliases[10].value = v14;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v15,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_exit_flat_left");
      this->behaviors.contextualLadder.armsAliases[19].value = v15;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v16,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_exit_flat_right");
      this->behaviors.contextualLadder.armsAliases[20].value = v16;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v17,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_mh_to_hide");
      this->behaviors.contextualLadder.armsAliases[15].value = v17;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v18,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_mh_to_hide");
      this->behaviors.contextualLadder.armsAliases[16].value = v18;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v19,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_mh_to_hide");
      this->behaviors.contextualLadder.armsAliases[17].value = v19;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v20,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_mh_to_hide");
      this->behaviors.contextualLadder.armsAliases[18].value = v20;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v21,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_mh_left");
      this->behaviors.contextualLadder.armsAliases[11].value = v21;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v22,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_mh_right");
      this->behaviors.contextualLadder.armsAliases[12].value = v22;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v23,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_mh_left");
      this->behaviors.contextualLadder.armsAliases[13].value = v23;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v24,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_mh_right");
      this->behaviors.contextualLadder.armsAliases[14].value = v24;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v25,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_mh_right");
      this->behaviors.contextualLadder.armsAliases[21].value = v25;
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v26,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: "ladder/player_ladder_mh_left");
      this->behaviors.contextualLadder.armsAliases[22].value = v26;
    }
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualLadder_EndLadder@idPlayer@@QAAXXZ
// EA  : 0x82E3F2C0
// RVA : 0x00E3F2C0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualLadder_EndLadder(idPlayer *this)
{
  idAlignedEntity *thirdPersonHands; // r11
  idAlignedEntity *thirdPersonLegs; // r11
  idPhysics *Physics; // r3
  const idVec3 *v5; // r3
  float y; // r8
  float z; // r7
  idPlayer::idPlayerBehaviorContextualLadderDismountType_t dismountType; // r11
  idCVar *v9; // r10
  idPresentable *presentable; // r3
  const idAngles *v11; // r4
  idPlayer_vtbl *v12; // r30
  idPresentablePlayer *ViewAngles; // r3
  idPresentable *v14; // r3
  int v15; // r3
  int valueInteger; // r30
  int v17; // r6
  idAlignedEntity *v18; // r3
  idPresentable *v19; // r3
  int v20; // r3
  _DWORD v21[2]; // [sp+50h] [-40h] BYREF
  float v22; // [sp+58h] [-38h]
  char v23; // [sp+60h] [-30h] BYREF

  thirdPersonHands = this->thirdPersonHands;
  if ( thirdPersonHands != (idAlignedEntity *)-5976 )
    idAnimator_Base::SetAlpha(this: &thirdPersonHands->additiveSyncedAnimator, alpha: 0.0);
  thirdPersonLegs = this->thirdPersonLegs;
  if ( thirdPersonLegs != (idAlignedEntity *)-5976 )
    idAnimator_Base::SetAlpha(this: &thirdPersonLegs->additiveSyncedAnimator, alpha: 0.0);
  idAlignedEntity::StopAnim(this: this->thirdPersonHands);
  idAlignedEntity::StopAnim(this: this->thirdPersonLegs);
  if ( this->springCamera->state != STATE_INACTIVE )
  {
    Physics = idEntity::GetPhysics(this: this->thirdPersonHands);
    v5 = Physics->GetOrigin(this: Physics, a2: 0);
    y = v5->y;
    z = v5->z;
    dismountType = this->behaviors.contextualLadder.dismountType;
    v21[0] = LODWORD(v5->x);
    *(float *)&v21[1] = y;
    v22 = z;
    if ( dismountType == CONTEXTUAL_LADDER_DISMOUNT_TYPE_LEFT || dismountType == CONTEXTUAL_LADDER_DISMOUNT_TYPE_RIGHT )
      v9 = &pm_crouchviewheight;
    else
      v9 = &pm_normalviewheight;
    presentable = this->presentable;
    v22 = v22 - v9->valueFloat;
    if ( presentable != nullptr )
      v11 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v11 = nullptr;
    v12 = this->__vftable;
    ViewAngles = idPresentablePlayer::GetViewAngles(
                   this: (idPresentablePlayer *)&v23,
                   result: v11,
                   includeWeaponKick: true);
    v12->Teleport(this, a2: (const idVec3 *)v21, a3: (const idAngles *)ViewAngles);
    idSpringCamera::BlendOut(this: this->springCamera, instantBlend: false);
  }
  v14 = this->presentable;
  if ( v14 != nullptr )
    v15 = (int)v14->GetPlayerInterface_2(this: v14);
  else
    v15 = 0;
  idPhysics_Player::SetCrouch(this: (idPhysics_Player *)(v15 + 36264), crouch: false);
  idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
    this,
    constrain: false,
    heading: nullptr,
    maxDeltaPitch: 0.0,
    maxDeltaYaw: 0.0,
    rate: 0.0);
  idPlayer::PlayerBehavior_Shared_AutoApplyThirdPersonHandsAnimDeltas(this, applyToPlayer: false, clip: false);
  idPlayer::PlayerBehavior_Shared_AutoApplyThirdPersonLegsAnimDeltas(this, applyToPlayer: false, clip: false);
  valueInteger = pb_clad_NoRemountTimeMS.valueInteger;
  v17 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + valueInteger;
  v18 = this->thirdPersonHands;
  this->behaviors.contextualLadder.canMountTime = v17;
  idAlignedEntity::SetAnimRateScale(this: v18, rateScale: 1.0);
  idAlignedEntity::SetAnimRateScale(this: this->thirdPersonLegs, rateScale: 1.0);
  v19 = this->presentable;
  if ( v19 != nullptr )
    v20 = (int)v19->GetPlayerInterface_2(this: v19);
  else
    v20 = 0;
  idHands::Show(this: (idHands *)(v20 + 37616), hideReason: HAND_HIDE_GENERIC);
}


// ========================================================================
// ?PlayerBehavior_ContextualLadder_AtLadderTop@idPlayer@@QBA_NXZ
// EA  : 0x82E3F508
// RVA : 0x00E3F508
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_ContextualLadder_AtLadderTop(idPlayer *this)
{
  int PhysicsObj; // r3
  double valueFloat; // fp31
  int result; // r3
  double v5; // fp13

  if ( !this->behaviors.contextualLadder.testTop.bDetectedLadder )
    return 0;
  if ( !this->behaviors.contextualLadder.testTop.bDetectedLadderTop )
    return 0;
  PhysicsObj = idPlayer::GetPhysicsObj(this);
  valueFloat = pb_clad_AtTopDist.valueFloat;
  v5 = (float)(*(float *)((*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)PhysicsObj + 64))(a1: PhysicsObj, a2: 0) + 8)
             + (float)valueFloat);
  result = 1;
  if ( v5 < this->behaviors.contextualLadder.testTop.point.z )
    return 0;
  return result;
}


// ========================================================================
// ?PlayerBehavior_ContextualLadder_AtLadderBottom@idPlayer@@QBA_NXZ
// EA  : 0x82E3F5A0
// RVA : 0x00E3F5A0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_ContextualLadder_AtLadderBottom(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  double valueFloat; // fp31
  double v5; // fp12
  int result; // r3

  if ( !this->behaviors.contextualLadder.testBottom.bDetectedLadder )
    return 0;
  presentable = this->presentable;
  v3 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
  valueFloat = pb_clad_AtBottomDist.valueFloat;
  v5 = *(float *)((*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v3 + 36264) + 64))(a1: v3 + 36264, a2: 0) + 8);
  result = 1;
  if ( v5 > (float)(this->behaviors.contextualLadder.testBottom.point.z + (float)valueFloat) )
    return 0;
  return result;
}


// ========================================================================
// ?PlayerBehavior_ContextualLadder_AtCeiling@idPlayer@@QBA_NXZ
// EA  : 0x82E3F650
// RVA : 0x00E3F650
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_ContextualLadder_AtCeiling(idPlayer *this)
{
  BOOL v2; // r30
  int PhysicsObj; // r3
  double valueFloat; // fp31

  v2 = false;
  if ( this->behaviors.contextualLadder.blockClimpOffAtTop )
    return 1;
  if ( this->behaviors.contextualLadder.testTop.bDetectedLadder
    && !this->behaviors.contextualLadder.testTop.bDetectedLadderTop )
  {
    PhysicsObj = idPlayer::GetPhysicsObj(this);
    valueFloat = pb_clad_AtTopDist.valueFloat;
    v2 = (float)(*(float *)((*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)PhysicsObj + 64))(a1: PhysicsObj, a2: 0) + 8)
               + (float)valueFloat) >= (double)this->behaviors.contextualLadder.testTop.point.z;
  }
  if ( !v2 && this->behaviors.contextualLadder.ceilingDist < (double)pb_clad_AtCeilingDist.valueFloat )
    return 1;
  return v2;
}


// ========================================================================
// ?PlayerBehavior_ContextualLadder_ShiftIntoPosition@idPlayer@@QAA_N_N@Z
// EA  : 0x82E3F728
// RVA : 0x00E3F728
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_ContextualLadder_ShiftIntoPosition(idPlayer *this, bool clipMovement)
{
  bool v4; // r5
  idVec3 v6; // [sp+50h] [-60h] BYREF
  idMat3 v7[2]; // [sp+60h] [-50h] BYREF

  if ( (unsigned __int8)idAnimatedEntity::GetWorldSpaceJointTransform(
                          this: this->thirdPersonHands,
                          jointName: "origin",
                          offset: &v6,
                          axis: v7) != 0 )
    return idPlayer::PlayerBehavior_Shared_ShiftIntoPosition(
             this,
             targetPos: &v6,
             minDist: pb_clad_ShiftIntoPositionDist.valueFloat,
             clipMovement: v4,
             a5: clipMovement);
  else
    return 0;
}


// ========================================================================
// ?PlayerBehavior_ContextualLadder_AlignThirdPersonModels@idPlayer@@QAAXABVidVec3@@@Z
// EA  : 0x82E3F798
// RVA : 0x00E3F798
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualLadder_AlignThirdPersonModels(
        idPlayer *this,
        const idVec3 *extraOffset)
{
  idPlayer::idPlayerBehaviorContextualLadder *p_contextualLadder; // r31
  double v4; // fp7
  idVec3 *p_handsAlignPos; // r30
  double v6; // fp0
  idVec3 *p_legsAlignPos; // r28
  double v8; // fp9
  double v9; // fp6
  double y; // fp11
  double z; // fp10
  double v12; // fp9
  double x; // fp5
  double v14; // fp6
  double v15; // fp4
  double v16; // fp13
  double v17; // fp3
  const char *EnumValueName; // r3
  idMat3 v19[2]; // [sp+50h] [-60h] BYREF

  p_contextualLadder = &this->behaviors.contextualLadder;
  v4 = (float)(extraOffset->z * this->behaviors.contextualLadder.ladderUp.x);
  p_handsAlignPos = &this->behaviors.contextualLadder.handsAlignPos;
  v6 = (float)(extraOffset->z * this->behaviors.contextualLadder.ladderUp.z);
  p_legsAlignPos = &this->behaviors.contextualLadder.legsAlignPos;
  v8 = (float)((float)((float)(this->behaviors.contextualLadder.ladderNormal.x * extraOffset->x)
                     + (float)((float)(this->behaviors.contextualLadder.testLeft.point.x
                                     + this->behaviors.contextualLadder.testRight.point.x)
                             * (float)0.5))
             + (float)(this->behaviors.contextualLadder.ladderRight.x * extraOffset->y));
  v9 = (float)((float)((float)(extraOffset->x * this->behaviors.contextualLadder.ladderNormal.z)
                     + (float)((float)((float)(this->behaviors.contextualLadder.testLeft.point.z
                                             + this->behaviors.contextualLadder.testRight.point.z)
                                     * (float)0.5)
                             + pm_normalviewheight.valueFloat))
             + (float)(extraOffset->y * this->behaviors.contextualLadder.ladderRight.z));
  this->behaviors.contextualLadder.handsAlignPos.y = (float)((float)((float)(extraOffset->x
                                                                           * this->behaviors.contextualLadder.ladderNormal.y)
                                                                   + (float)((float)(this->behaviors.contextualLadder.testLeft.point.y
                                                                                   + this->behaviors.contextualLadder.testRight.point.y)
                                                                           * (float)0.5))
                                                           + (float)(extraOffset->y
                                                                   * this->behaviors.contextualLadder.ladderRight.y))
                                                   + (float)(extraOffset->z * this->behaviors.contextualLadder.ladderUp.y);
  this->behaviors.contextualLadder.handsAlignPos.x = (float)v8 + (float)v4;
  this->behaviors.contextualLadder.handsAlignPos.z = (float)v9 + (float)v6;
  this->behaviors.contextualLadder.legsAlignPos.x = (float)v8 + (float)v4;
  this->behaviors.contextualLadder.legsAlignPos.y = this->behaviors.contextualLadder.handsAlignPos.y;
  this->behaviors.contextualLadder.legsAlignPos.z = this->behaviors.contextualLadder.handsAlignPos.z;
  y = this->behaviors.contextualLadder.ladderRight.y;
  z = this->behaviors.contextualLadder.ladderRight.z;
  v12 = this->behaviors.contextualLadder.ladderNormal.z;
  x = this->behaviors.contextualLadder.ladderUp.x;
  v14 = -this->behaviors.contextualLadder.ladderNormal.y;
  v15 = this->behaviors.contextualLadder.ladderUp.y;
  v16 = this->behaviors.contextualLadder.ladderUp.z;
  v17 = -this->behaviors.contextualLadder.ladderRight.x;
  v19[0].mat[0].x = -this->behaviors.contextualLadder.ladderNormal.x;
  v19[0].mat[0].y = v14;
  v19[0].mat[2].x = x;
  v19[0].mat[0].z = -v12;
  v19[0].mat[2].y = v15;
  v19[0].mat[1].x = v17;
  v19[0].mat[2].z = v16;
  v19[0].mat[1].y = -y;
  v19[0].mat[1].z = -z;
  idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsAlignNode(
    this,
    origin: &this->behaviors.contextualLadder.handsAlignPos,
    axis: v19);
  idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsAlignNode(this, origin: p_legsAlignPos, axis: v19);
  if ( outputDeltaMove != 0 )
  {
    idTypeInfoTools::FindEnumValueName(
      this: typeInfoTools,
      enumTypeName: "idPlayer::idPlayerBehaviorContextualLadderState_t",
      value: p_contextualLadder->state);
    idLib::Printf(
      fmt: "state=%s: handsAlignPos:(%0.2f,%0.2f,%0.2f)\n",
      (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(p_handsAlignPos->x)),
      p_handsAlignPos->x,
      p_contextualLadder->handsAlignPos.y,
      p_contextualLadder->handsAlignPos.z);
  }
  if ( outputDeltaZ != 0 )
  {
    EnumValueName = idTypeInfoTools::FindEnumValueName(
                      this: typeInfoTools,
                      enumTypeName: "idPlayer::idPlayerBehaviorContextualLadderState_t",
                      value: p_contextualLadder->state);
    idLib::Printf(fmt: "state=%s: handsAlignPos.z:(%0.2f)\n", EnumValueName, p_contextualLadder->handsAlignPos.z);
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualLadder_DebugHandle@idPlayer@@QAAXXZ
// EA  : 0x82E3F9C0
// RVA : 0x00E3F9C0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPlayer::PlayerBehavior_ContextualLadder_DebugHandle(idPlayer *this)
{
  const char *EnumValueName; // r3
  __int64 v3; // r10
  const char *v4; // r30
  __int64 v5; // r8
  __int64 v6; // r6
  __int64 v7; // r8
  __int64 v8; // r6
  __int64 v9; // r10
  const char *CurAnimName; // r3
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r10
  const char *v14; // r3
  __int64 v15; // r6
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  __int64 v22; // r10
  __int64 v23; // r8
  __int64 v24; // r10
  __int64 v25; // r6
  __int64 v26; // r8
  __int64 v27; // r10
  __int64 v28; // r6
  __int64 v29; // r8
  __int64 v30; // r10
  __int64 v31; // r6
  __int64 v32; // r8
  idPresentable *presentable; // r3
  int v34; // r3
  idPresentable *v35; // r11
  int v36; // r28
  int v37; // r3
  idPresentable *v38; // r11
  int v39; // r29
  int v40; // r3
  float *v41; // r30
  double v42; // fp31
  __int128 v43; // r7 OVERLAPPED
  __int64 v44; // r10
  __int64 v45; // r6
  __int64 v46; // r10
  __int64 v47; // r8
  __int64 v48; // r8
  __int64 v49; // r6 OVERLAPPED
  __int64 v50; // r10
  const char *v51; // r4
  __int64 v52; // r10
  __int64 v53; // r8
  __int64 v54; // r6
  int v55; // [sp+8h] [-78h]
  int v56; // [sp+8h] [-78h]
  int v57; // [sp+8h] [-78h]
  int v58; // [sp+8h] [-78h]
  int v59; // [sp+8h] [-78h]
  int v60; // [sp+8h] [-78h]
  int v61; // [sp+8h] [-78h]
  int v62; // [sp+8h] [-78h]
  int v63; // [sp+8h] [-78h]
  int v64; // [sp+8h] [-78h]
  int v65; // [sp+8h] [-78h]
  int v66; // [sp+8h] [-78h]
  int v67; // [sp+8h] [-78h]
  int v68; // [sp+Ch] [-74h]
  int v69; // [sp+Ch] [-74h]
  int v70; // [sp+Ch] [-74h]
  int v71; // [sp+Ch] [-74h]
  int v72; // [sp+Ch] [-74h]
  int v73; // [sp+Ch] [-74h]
  int v74; // [sp+Ch] [-74h]
  int v75; // [sp+Ch] [-74h]
  int v76; // [sp+Ch] [-74h]
  int v77; // [sp+Ch] [-74h]
  int v78; // [sp+Ch] [-74h]
  int v79; // [sp+Ch] [-74h]
  int v80; // [sp+Ch] [-74h]
  int v81; // [sp+10h] [-70h]
  int v82; // [sp+10h] [-70h]
  int v83; // [sp+10h] [-70h]
  int v84; // [sp+10h] [-70h]
  int v85; // [sp+10h] [-70h]
  int v86; // [sp+10h] [-70h]
  int v87; // [sp+10h] [-70h]
  int v88; // [sp+10h] [-70h]
  int v89; // [sp+10h] [-70h]
  int v90; // [sp+10h] [-70h]
  int v91; // [sp+10h] [-70h]
  int v92; // [sp+10h] [-70h]
  int v93; // [sp+10h] [-70h]
  int v94; // [sp+14h] [-6Ch]
  int v95; // [sp+14h] [-6Ch]
  int v96; // [sp+14h] [-6Ch]
  int v97; // [sp+14h] [-6Ch]
  int v98; // [sp+14h] [-6Ch]
  int v99; // [sp+14h] [-6Ch]
  int v100; // [sp+14h] [-6Ch]
  int v101; // [sp+14h] [-6Ch]
  int v102; // [sp+14h] [-6Ch]
  int v103; // [sp+14h] [-6Ch]
  int v104; // [sp+14h] [-6Ch]
  int v105; // [sp+14h] [-6Ch]
  int v106; // [sp+14h] [-6Ch]
  int v107; // [sp+18h] [-68h]
  int v108; // [sp+18h] [-68h]
  int v109; // [sp+18h] [-68h]
  int v110; // [sp+18h] [-68h]
  int v111; // [sp+18h] [-68h]
  int v112; // [sp+18h] [-68h]
  int v113; // [sp+18h] [-68h]
  int v114; // [sp+18h] [-68h]
  int v115; // [sp+18h] [-68h]
  int v116; // [sp+18h] [-68h]
  int v117; // [sp+18h] [-68h]
  int v118; // [sp+18h] [-68h]
  int v119; // [sp+18h] [-68h]
  int v120; // [sp+1Ch] [-64h]
  int v121; // [sp+1Ch] [-64h]
  int v122; // [sp+1Ch] [-64h]
  int v123; // [sp+1Ch] [-64h]
  int v124; // [sp+1Ch] [-64h]
  int v125; // [sp+1Ch] [-64h]
  int v126; // [sp+1Ch] [-64h]
  int v127; // [sp+1Ch] [-64h]
  int v128; // [sp+1Ch] [-64h]
  int v129; // [sp+1Ch] [-64h]
  int v130; // [sp+1Ch] [-64h]
  int v131; // [sp+1Ch] [-64h]
  int v132; // [sp+1Ch] [-64h]
  double z; // [sp+20h] [-60h]
  double v134; // [sp+20h] [-60h]
  double groundDist; // [sp+20h] [-60h]

  if ( pb_clad_Debug.valueInteger != 0 )
  {
    EnumValueName = idTypeInfoTools::FindEnumValueName(
                      this: typeInfoTools,
                      enumTypeName: "idPlayer::idPlayerBehaviorContextualLadderState_t",
                      value: this->behaviors.contextualLadder.state);
    HIDWORD(v3) = &off_82350000;
    v4 = EnumValueName;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "--- contextual ladder ---",
      a3: v6,
      a4: v5,
      a5: v3,
      a6: v55,
      a7: v68,
      a8: v81,
      a9: v94,
      a10: v107,
      a11: v120);
    LODWORD(v7) = &off_82350000;
    HIDWORD(v8) = v4;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Ladder state: %s",
      a3: v8,
      a4: v7,
      a5: v9,
      a6: v56,
      a7: v69,
      a8: v82,
      a9: v95,
      a10: v108,
      a11: v121);
    CurAnimName = idAlignedEntity::GetCurAnimName(this: this->thirdPersonHands);
    HIDWORD(v11) = &off_82350000;
    HIDWORD(v12) = CurAnimName;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Hands anim: %s",
      a3: v12,
      a4: v11,
      a5: v13,
      a6: v57,
      a7: v70,
      a8: v83,
      a9: v96,
      a10: v109,
      a11: v122);
    v14 = idAlignedEntity::GetCurAnimName(this: this->thirdPersonLegs);
    LODWORD(v15) = &off_82350000;
    HIDWORD(v15) = v14;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Legs anim: %s",
      a3: v15,
      a4: v17,
      a5: v16,
      a6: v58,
      a7: v71,
      a8: v84,
      a9: v97,
      a10: v110,
      a11: v123);
    HIDWORD(v18) = this->behaviors.contextualLadder.testForward.bDetectedLadder;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Detected ladder forward: %d",
      a3: v18,
      a4: v20,
      a5: v19,
      a6: v59,
      a7: v72,
      a8: v85,
      a9: v98,
      a10: v111,
      a11: v124);
    HIDWORD(v21) = this->behaviors.contextualLadder.testLeft.bDetectedLadder;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Detected ladder left: %d",
      a3: v21,
      a4: v23,
      a5: v22,
      a6: v60,
      a7: v73,
      a8: v86,
      a9: v99,
      a10: v112,
      a11: v125);
    LODWORD(v24) = &off_82350000;
    HIDWORD(v25) = this->behaviors.contextualLadder.testRight.bDetectedLadder;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Detected ladder right: %d",
      a3: v25,
      a4: v26,
      a5: v24,
      a6: v61,
      a7: v74,
      a8: v87,
      a9: v100,
      a10: v113,
      a11: v126);
    HIDWORD(v27) = &off_82350000;
    HIDWORD(v28) = this->behaviors.contextualLadder.testTop.bDetectedLadder;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Detected ladder top: %d",
      a3: v28,
      a4: v29,
      a5: v27,
      a6: v62,
      a7: v75,
      a8: v88,
      a9: v101,
      a10: v114,
      a11: v127);
    LODWORD(v32) = this->behaviors.contextualLadder.testTop.bDetectedLadder;
    if ( this->behaviors.contextualLadder.testTop.bDetectedLadder )
    {
      z = this->behaviors.contextualLadder.testTop.point.z;
      HIDWORD(v31) = LODWORD(z);
      idPlayer::debugHUDPrintf(
        this,
        fmt: "Top height = %0.2f",
        a3: v31,
        a4: v32,
        a5: v30,
        a6: v63,
        a7: v76,
        a8: v89,
        a9: v102,
        a10: v115,
        a11: v128);
    }
    else
    {
      idPlayer::debugHUDPrintf(
        this,
        fmt: "Top height = <n/a>",
        a3: v31,
        a4: v32,
        a5: v30,
        a6: v63,
        a7: v76,
        a8: v89,
        a9: v102,
        a10: v115,
        a11: v128);
    }
    presentable = this->presentable;
    if ( presentable != nullptr )
      v34 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v34 = 0;
    v35 = this->presentable;
    v36 = v34 + 36264;
    if ( v35 != nullptr )
      v37 = (int)v35->GetPlayerInterface_2(this: this->presentable);
    else
      v37 = 0;
    v38 = this->presentable;
    v39 = v37 + 36264;
    if ( v38 != nullptr )
      v40 = (int)v38->GetPlayerInterface_2(this: this->presentable);
    else
      v40 = 0;
    v41 = (float *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v40 + 36264) + 64))(a1: v40 + 36264, a2: 0);
    v42 = *(float *)((*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)v36 + 64))(a1: v36, a2: 0) + 8);
    (*(void (__fastcall **)(int, _DWORD))(*(_DWORD *)v39 + 64))(a1: v39, a2: 0);
    v134 = *v41;
    DWORD1(v43) = LODWORD(v134);
    *((double *)&v43 + 1) = v42;
    idPlayer::debugHUDPrintf(
      this,
      fmt: (const char *)(HIDWORD(v134) + 14880),
      a3: *(__int64 *)((char *)&v43 + 4),
      a4: *(__int64 *)((char *)&v43 - 4),
      a5: v44,
      a6: v64,
      a7: v77,
      a8: v90,
      a9: v103,
      a10: v116,
      a11: v129);
    HIDWORD(v45) = this->behaviors.contextualLadder.testBottom.bDetectedLadder;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Detected ladder bottom: %d",
      a3: v45,
      a4: v47,
      a5: v46,
      a6: v65,
      a7: v78,
      a8: v91,
      a9: v104,
      a10: v117,
      a11: v130);
    LODWORD(v50) = this->behaviors.contextualLadder.testBottom.bDetectedLadder;
    if ( this->behaviors.contextualLadder.testBottom.bDetectedLadder )
    {
      *(double *)((char *)&v49 + 4) = this->behaviors.contextualLadder.testBottom.point.z;
      idPlayer::debugHUDPrintf(
        this,
        fmt: v51,
        a3: v49,
        a4: v48,
        a5: v50,
        a6: v66,
        a7: v79,
        a8: v92,
        a9: v105,
        a10: v118,
        a11: v131);
    }
    else
    {
      idPlayer::debugHUDPrintf(
        this,
        fmt: "Bottom height = <n/a>",
        a3: v49,
        a4: v48,
        a5: v50,
        a6: v66,
        a7: v79,
        a8: v92,
        a9: v105,
        a10: v118,
        a11: v131);
    }
    groundDist = this->behaviors.contextualLadder.groundDist;
    HIDWORD(v54) = LODWORD(groundDist);
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Ground dist = %0.2f",
      a3: v54,
      a4: v53,
      a5: v52,
      a6: v67,
      a7: v80,
      a8: v93,
      a9: v106,
      a10: v119,
      a11: v132);
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualLadder_CheckForLadder@idPlayer@@QAA_NABVidVec3@@0AAUidPlayerContextualLadderTestInfo@1@@Z
// EA  : 0x82E3FC70
// RVA : 0x00E3FC70
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

int __fastcall idPlayer::PlayerBehavior_ContextualLadder_CheckForLadder(
        idPlayer *this,
        const idVec3 *p0,
        const idVec3 *p1,
        idPlayer::idPlayerContextualLadderTestInfo *testInfo)
{
  idVec3 *p_point; // r30
  idVec3 *p_normal; // r29
  int v9; // r26
  int surfaceFlags; // r10
  double fraction; // fp0
  double y; // fp11
  double z; // fp8
  double x; // fp6
  double v16; // fp2
  double v17; // fp10
  double v18; // fp1
  double v19; // fp0
  double v20; // fp12
  double v21; // fp1
  double v22; // fp4
  double v23; // fp10
  double v24; // fp9
  double v25; // fp6
  float v26[4]; // [sp+50h] [-D0h] BYREF
  trace_t v27; // [sp+60h] [-C0h] BYREF

  testInfo->bDisabled = false;
  testInfo->bDetectedLadder = false;
  testInfo->bDetectedLadderTop = false;
  testInfo->point = vec3_origin;
  p_point = &testInfo->point;
  p_normal = &testInfo->normal;
  v9 = 0;
  testInfo->normal = vec3_origin;
  testInfo->surfaceFlags = 0;
  if ( testInfo->bDisabled )
    return 0;
  testInfo->bDetectedLadder = false;
  testInfo->bDetectedLadderTop = false;
  if ( (unsigned __int8)idPlayer::PlayerBehavior_Shared_CheckBlocked(
                          startPos: p0,
                          endPos: p1,
                          blockDist: v26,
                          entityNum: this->entityNumber,
                          bDebug: pb_clad_Debug.valueInteger != 0,
                          tr: &v27,
                          contentMask: 8) != 0 )
  {
    surfaceFlags = v27.c.surfaceFlags;
    if ( (v27.c.surfaceFlags & 0x80) != 0 )
    {
      fraction = v27.fraction;
      y = v27.c.normal.y;
      testInfo->bDetectedLadder = true;
      z = p0->z;
      x = p0->x;
      v16 = (float)(p1->x - p0->x);
      v17 = v27.c.normal.z;
      v18 = (float)(p1->z - p0->z);
      p_point->y = p0->y + (float)((float)(p1->y - p0->y) * (float)fraction);
      p_point->x = (float)x + (float)((float)v16 * (float)fraction);
      p_point->z = (float)z + (float)((float)v18 * (float)fraction);
      p_normal->y = y;
      p_normal->z = v17;
LABEL_8:
      v9 = 1;
      p_normal->x = v27.c.normal.x;
      testInfo->surfaceFlags = surfaceFlags;
      return v9;
    }
    if ( (v27.c.surfaceFlags & 0x40000000) != 0 )
    {
      v19 = v27.fraction;
      v20 = v27.c.normal.y;
      testInfo->bDetectedLadder = true;
      v21 = v27.c.normal.z;
      testInfo->bDetectedLadderTop = true;
      v22 = p0->y;
      v23 = p0->z;
      v24 = (float)((float)(p1->y - p0->y) * (float)v19);
      v25 = (float)((float)(p1->z - p0->z) * (float)v19);
      p_point->x = p0->x + (float)((float)(p1->x - p0->x) * (float)v19);
      p_point->z = (float)v23 + (float)v25;
      p_point->y = (float)v22 + (float)v24;
      p_normal->y = v20;
      p_normal->z = v21;
      goto LABEL_8;
    }
  }
  return v9;
}


// ========================================================================
// ?PlayerBehavior_ContextualLadder_HandleSpeedScale@idPlayer@@QAAXXZ
// EA  : 0x82E3FE48
// RVA : 0x00E3FE48
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualLadder_HandleSpeedScale(idPlayer *this)
{
  idPlayer::idPlayerBehaviorContextualLadderState_t state; // r11
  idPlayer::idPlayerBehaviorContextualLadder *p_contextualLadder; // r31
  double valueFloat; // fp31
  idPresentable *presentable; // r3
  int v6; // r3
  double v7; // fp1
  float v8; // [sp+50h] [-30h]

  state = this->behaviors.contextualLadder.state;
  p_contextualLadder = &this->behaviors.contextualLadder;
  if ( state != CONTEXTUAL_LADDER_STATE_NONE )
  {
    valueFloat = 1.0;
    if ( state >= CONTEXTUAL_LADDER_STATE_CLIMB_DOWN_LEFT && state <= CONTEXTUAL_LADDER_STATE_CLIMB_UP_RIGHT )
    {
      presentable = this->presentable;
      if ( presentable != nullptr )
        v6 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v6 = 0;
      if ( *(_BYTE *)(v6 + 47121) != 0 )
        valueFloat = pb_clad_SprintSpeedScale.valueFloat;
    }
    v8 = valueFloat;
    p_contextualLadder->speedScaleSpring.p0.x = v8;
    v7 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
    idSpring<idVec1>::Update(this: &p_contextualLadder->speedScaleSpring, dt: v7);
    idAlignedEntity::SetAnimRateScale(
      this: this->thirdPersonHands,
      rateScale: p_contextualLadder->speedScaleSpring.p1.x);
    idAlignedEntity::SetAnimRateScale(this: this->thirdPersonLegs, rateScale: p_contextualLadder->speedScaleSpring.p1.x);
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualLadder_CheckSurroundings@idPlayer@@QAAXXZ
// EA  : 0x82E3FFD8
// RVA : 0x00E3FFD8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualLadder_CheckSurroundings(idPlayer *this)
{
  idPlayer::idPlayerBehaviorContextualLadder *p_contextualLadder; // r31
  idPresentable *presentable; // r3
  int v4; // r3
  int v5; // r3
  float v6; // r6
  float v7; // r5
  bool v8; // cr58
  double v9; // fp10
  double v10; // fp9
  idPresentable *v11; // r3
  float *v12; // r3
  double v13; // fp13
  double v14; // fp12
  idPhysics *Physics; // r3
  float *v16; // r3
  double z; // fp12
  float v18; // r5
  double x; // fp0
  float v20; // r7
  double y; // fp13
  double v22; // fp28
  double v23; // fp27
  double v24; // fp26
  double v25; // fp7
  double v26; // fp8
  double v27; // fp6
  double v28; // fp11
  double v29; // fp10
  double v30; // fp9
  double valueFloat; // fp29
  double v32; // fp24
  double v33; // fp30
  double v34; // fp31
  double v35; // fp25
  double v36; // fp0
  double v37; // fp13
  double v38; // fp5
  double v39; // fp10
  double v40; // fp4
  double v41; // fp9
  double v42; // fp8
  double v43; // fp7
  double v44; // fp5
  double v45; // fp4
  double v46; // fp3
  double v47; // fp2
  double v48; // fp11
  double v49; // fp2
  double v50; // fp1
  double v51; // fp12
  double v52; // fp13
  double v53; // fp13
  double v54; // fp8
  double v55; // fp1
  double v56; // fp10
  double v57; // fp3
  double v58; // fp12
  float *p_groundDist; // r29
  int entityNumber; // r6
  float *p_ceilingDist; // r31
  int v62; // r6
  int PhysicsObj; // r3
  int v64; // r3
  int v65; // r3
  double v66; // fp0
  double v67; // fp13
  double v68; // fp5
  double v69; // fp10
  double v70; // fp4
  double v71; // fp5
  double v72; // fp4
  double v73; // fp11
  double v74; // fp9
  double v75; // fp8
  double v76; // fp6
  double v77; // fp0
  double v78; // fp8
  double v79; // fp2
  double v80; // fp7
  double v81; // fp12
  double v82; // fp13
  double v83; // fp1
  double v84; // fp10
  double v85; // fp6
  double v86; // fp4
  double v87; // fp3
  double v88; // fp1
  idVec3 v89; // [sp+50h] [-240h] BYREF
  idVec3 v90; // [sp+60h] [-230h] BYREF
  idVec3 v91; // [sp+70h] [-220h] BYREF
  idVec3 v92; // [sp+80h] [-210h] BYREF
  idVec3 v93; // [sp+90h] [-200h] BYREF
  idVec3 v94; // [sp+A0h] [-1F0h] BYREF
  idVec3 v95; // [sp+B0h] [-1E0h] BYREF
  idVec3 v96; // [sp+C0h] [-1D0h] BYREF
  idVec3 v97; // [sp+D0h] [-1C0h] BYREF
  idVec3 v98; // [sp+E0h] [-1B0h] BYREF
  idVec3 v99; // [sp+F0h] [-1A0h] BYREF
  idVec3 v100; // [sp+100h] [-190h] BYREF
  idVec3 v101; // [sp+110h] [-180h] BYREF
  idVec3 v102; // [sp+120h] [-170h] BYREF
  idVec3 v103; // [sp+130h] [-160h] BYREF
  idVec3 v104; // [sp+140h] [-150h] BYREF
  idVec3 v105; // [sp+150h] [-140h] BYREF
  idVec3 v106; // [sp+160h] [-130h] BYREF
  idVec3 v107; // [sp+170h] [-120h] BYREF
  idVec3 v108; // [sp+180h] [-110h] BYREF
  trace_t v109; // [sp+190h] [-100h] BYREF

  p_contextualLadder = &this->behaviors.contextualLadder;
  switch ( this->behaviors.contextualLadder.state )
  {
    case CONTEXTUAL_LADDER_STATE_MOUNT_BOTTOM:
    case CONTEXTUAL_LADDER_STATE_MOUNT_MID:
    case CONTEXTUAL_LADDER_STATE_MOUNT_TOP:
    case CONTEXTUAL_LADDER_STATE_DISMOUNT_GROUND:
    case CONTEXTUAL_LADDER_STATE_DISMOUNT_MID:
    case CONTEXTUAL_LADDER_STATE_DISMOUNT_MID_PUSH:
    case CONTEXTUAL_LADDER_STATE_DISMOUNT_TOP:
      return;
    default:
      presentable = this->presentable;
      if ( presentable != nullptr )
        v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v4 = 0;
      v5 = (*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v4 + 36264) + 64))(a1: v4 + 36264, a2: 0);
      v6 = *(float *)(v5 + 4);
      v7 = *(float *)(v5 + 8);
      v8 = p_contextualLadder->state == CONTEXTUAL_LADDER_STATE_NONE;
      v89.x = *(float *)v5;
      v89.y = v6;
      v89.z = v7;
      if ( v8
        || (float)((float)(p_contextualLadder->ladderNormal.z * p_contextualLadder->ladderNormal.z)
                 + (float)((float)(p_contextualLadder->ladderNormal.x * p_contextualLadder->ladderNormal.x)
                         + (float)(p_contextualLadder->ladderNormal.y * p_contextualLadder->ladderNormal.y))) == 0.0 )
      {
        v11 = this->presentable;
        if ( v11 != nullptr )
          v12 = (float *)v11->GetPlayerInterface_2(this: v11);
        else
          v12 = nullptr;
        v13 = v12[11637];
        v14 = v12[11638];
        v90.x = v12[11636];
        v90.y = v13;
        v90.z = v14;
      }
      else
      {
        v9 = -p_contextualLadder->ladderNormal.y;
        v10 = -p_contextualLadder->ladderNormal.z;
        v90.x = -p_contextualLadder->ladderNormal.x;
        v90.y = v9;
        v90.z = v10;
      }
      idPlayer::idPlayerBehaviorContextualLadder::ClearSpacialAnalysis(this: p_contextualLadder);
      if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) >= this->behaviors.contextualLadder.canMountTime )
      {
        v90.z = 0.0;
        idVec3::NormalizeFast(this: &v90);
        Physics = idEntity::GetPhysics(this);
        v16 = (float *)Physics->GetGravityNormal(this: Physics);
        z = v90.z;
        v18 = *v16;
        x = v90.x;
        v20 = v16[1];
        y = v90.y;
        v22 = -*v16;
        v90.z = v16[2];
        v23 = -v20;
        v24 = -v90.z;
        v25 = (float)((float)(v90.y * v18) - (float)(v20 * v90.x));
        v26 = (float)((float)(v90.z * v90.x) - (float)(v18 * (float)z));
        v90.x = v18;
        v27 = (float)((float)(v20 * (float)z) - (float)(v90.z * v90.y));
        v90.y = v20;
        if ( pb_clad_DebugNoQueryUpdate.valueInteger != 0 )
        {
          v22 = prevUp.x;
          v28 = prevPos.x;
          x = prevForward.x;
          v29 = prevPos.y;
          v30 = prevPos.z;
          y = prevForward.y;
          z = prevForward.z;
          v23 = prevUp.y;
          v24 = prevUp.z;
          v89.x = prevPos.x;
          v89.y = prevPos.y;
          v89.z = prevPos.z;
        }
        else
        {
          v28 = v89.x;
          v29 = v89.y;
          v30 = v89.z;
          prevUp.x = v22;
          prevForward.x = x;
          prevRight.x = v27;
          prevPos.x = v89.x;
          prevForward.y = y;
          prevForward.z = z;
          prevRight.y = v26;
          prevRight.z = v25;
          prevUp.y = v23;
          prevUp.z = v24;
          prevPos.y = v89.y;
          prevPos.z = v89.z;
        }
        valueFloat = pb_clad_ForwardTestDist.valueFloat;
        v32 = pb_clad_ForwardTestBackupDist.valueFloat;
        v33 = pb_clad_VerticalTestDist.valueFloat;
        v34 = pb_clad_SideTestDist.valueFloat;
        v35 = pb_clad_RayTestDepth.valueFloat;
        v100.x = (float)((float)x * pb_clad_ForwardTestDist.valueFloat) + (float)v28;
        v96.x = (float)v28 - (float)((float)x * pb_clad_ForwardTestBackupDist.valueFloat);
        v100.y = (float)((float)y * pb_clad_ForwardTestDist.valueFloat) + (float)v29;
        v100.z = (float)(pb_clad_ForwardTestDist.valueFloat * (float)z) + (float)v30;
        v96.y = (float)v29 - (float)((float)y * pb_clad_ForwardTestBackupDist.valueFloat);
        v96.z = (float)v30 - (float)(pb_clad_ForwardTestBackupDist.valueFloat * (float)z);
        if ( (unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_CheckForLadder(
                                this,
                                p0: &v96,
                                p1: &v100,
                                testInfo: &p_contextualLadder->testForward) != 0 )
        {
          v36 = p_contextualLadder->testForward.normal.x;
          p_contextualLadder->ladderNormal.x = p_contextualLadder->testForward.normal.x;
          v37 = p_contextualLadder->testForward.normal.y;
          v38 = (float)((float)((float)v22 * (float)v36) + (float)((float)v23 * p_contextualLadder->testForward.normal.y));
          p_contextualLadder->ladderNormal.y = p_contextualLadder->testForward.normal.y;
          v39 = p_contextualLadder->testForward.normal.z;
          v40 = (float)((float)((float)v24 * p_contextualLadder->testForward.normal.z) + (float)v38);
          p_contextualLadder->ladderNormal.z = p_contextualLadder->testForward.normal.z;
          p_contextualLadder->ladderUp.x = (float)v22 - (float)((float)v40 * (float)v36);
          p_contextualLadder->ladderUp.y = (float)v23 - (float)((float)v37 * (float)v40);
          p_contextualLadder->ladderUp.z = (float)v24 - (float)((float)v40 * (float)v39);
          idVec3::NormalizeFast(this: &p_contextualLadder->ladderUp);
          v41 = p_contextualLadder->ladderNormal.y;
          v42 = p_contextualLadder->ladderUp.z;
          v43 = p_contextualLadder->ladderNormal.x;
          v44 = p_contextualLadder->ladderUp.x;
          v45 = (float)(p_contextualLadder->ladderUp.y * p_contextualLadder->ladderNormal.x);
          v46 = (float)(p_contextualLadder->ladderUp.x * p_contextualLadder->ladderNormal.z);
          v47 = (float)((float)(p_contextualLadder->ladderUp.y * p_contextualLadder->ladderNormal.z)
                      - (float)(p_contextualLadder->ladderUp.z * p_contextualLadder->ladderNormal.y));
          p_contextualLadder->ladderRight.x = (float)(p_contextualLadder->ladderUp.y * p_contextualLadder->ladderNormal.z)
                                            - (float)(p_contextualLadder->ladderUp.z * p_contextualLadder->ladderNormal.y);
          p_contextualLadder->ladderRight.z = (float)((float)v44 * (float)v41) - (float)v45;
          p_contextualLadder->ladderRight.y = (float)((float)v42 * (float)v43) - (float)v46;
          v48 = p_contextualLadder->testForward.point.x;
          v50 = (float)((float)v34 * (float)v47);
          v49 = (float)(p_contextualLadder->ladderNormal.x * (float)v35);
          v51 = (float)(p_contextualLadder->testForward.point.z
                      - (float)(p_contextualLadder->ladderNormal.z * (float)v35));
          v52 = (float)(p_contextualLadder->testForward.point.y
                      - (float)(p_contextualLadder->ladderNormal.y * (float)v35));
          v91.y = p_contextualLadder->testForward.point.y - (float)(p_contextualLadder->ladderNormal.y * (float)v35);
          v91.z = v51;
          v91.x = (float)v48 - (float)v49;
          v106.z = (float)v51 - (float)((float)((float)((float)v44 * (float)v41) - (float)v45) * (float)v34);
          v106.y = (float)v52 - (float)((float)((float)((float)v42 * (float)v43) - (float)v46) * (float)v34);
          v106.x = v91.x - (float)v50;
          idPlayer::PlayerBehavior_ContextualLadder_CheckForLadder(
            this,
            p0: &v106,
            p1: &v91,
            testInfo: &p_contextualLadder->testRight);
          v53 = (float)(p_contextualLadder->ladderRight.z * (float)v34);
          v54 = (float)((float)(p_contextualLadder->ladderRight.y * (float)v34) + v91.y);
          v98.x = (float)((float)v34 * p_contextualLadder->ladderRight.x) + v91.x;
          v98.y = v54;
          v98.z = (float)v53 + v91.z;
          idPlayer::PlayerBehavior_ContextualLadder_CheckForLadder(
            this,
            p0: &v98,
            p1: &v91,
            testInfo: &p_contextualLadder->testLeft);
          v55 = (float)(p_contextualLadder->ladderUp.z * (float)v33);
          v56 = (float)((float)(p_contextualLadder->ladderUp.y * (float)v33) + v91.y);
          v104.x = (float)(p_contextualLadder->ladderUp.x * (float)v33) + v91.x;
          v104.y = v56;
          v104.z = (float)v55 + v91.z;
          idPlayer::PlayerBehavior_ContextualLadder_CheckForLadder(
            this,
            p0: &v104,
            p1: &v91,
            testInfo: &p_contextualLadder->testTop);
          v57 = (float)(p_contextualLadder->ladderUp.z * (float)v33);
          v58 = (float)(v91.y - (float)(p_contextualLadder->ladderUp.y * (float)v33));
          v94.x = v91.x - (float)(p_contextualLadder->ladderUp.x * (float)v33);
          v94.y = v58;
          v94.z = v91.z - (float)v57;
          idPlayer::PlayerBehavior_ContextualLadder_CheckForLadder(
            this,
            p0: &v94,
            p1: &v91,
            testInfo: &p_contextualLadder->testBottom);
          p_groundDist = &p_contextualLadder->groundDist;
          entityNumber = this->entityNumber;
          v108.x = v89.x - (float)((float)v22 * (float)valueFloat);
          v108.y = v89.y - (float)((float)v23 * (float)valueFloat);
          v108.z = v89.z - (float)((float)v24 * (float)valueFloat);
          v102.x = (float)((float)v22 * (float)valueFloat) + v89.x;
          v102.y = (float)((float)v23 * (float)valueFloat) + v89.y;
          v102.z = (float)((float)v24 * (float)valueFloat) + v89.z;
          if ( (unsigned __int8)idPlayer::PlayerBehavior_Shared_CheckBlocked(
                                  startPos: &v102,
                                  endPos: &v108,
                                  blockDist: &p_contextualLadder->groundDist,
                                  entityNum: entityNumber,
                                  bDebug: pb_clad_Debug.valueInteger != 0,
                                  tr: &v109,
                                  contentMask: 107529) != 0 )
            *p_groundDist = *p_groundDist - (float)valueFloat;
          else
            *p_groundDist = 1000.0;
          p_ceilingDist = &p_contextualLadder->ceilingDist;
          v62 = this->entityNumber;
          v95.x = (float)((float)v22 * (float)v33) + v89.x;
          v95.y = (float)((float)v23 * (float)v33) + v89.y;
          v95.z = (float)((float)v24 * (float)v33) + v89.z;
          if ( (unsigned __int8)idPlayer::PlayerBehavior_Shared_CheckBlocked(
                                  startPos: &v89,
                                  endPos: &v95,
                                  blockDist: p_ceilingDist,
                                  entityNum: v62,
                                  bDebug: pb_clad_Debug.valueInteger != 0,
                                  tr: &v109,
                                  contentMask: 107529) == 0 )
            *p_ceilingDist = 1000.0;
        }
        else if ( p_contextualLadder->state == CONTEXTUAL_LADDER_STATE_NONE )
        {
          PhysicsObj = idPlayer::GetPhysicsObj(this);
          if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)PhysicsObj + 248))(a1: PhysicsObj) == 0 )
          {
            v64 = idPlayer::GetPhysicsObj(this);
            if ( *(float *)((*(int (__fastcall **)(idVec3 *, int, _DWORD))(*(_DWORD *)v64 + 88))(
                              a1: &v90,
                              a2: v64,
                              a3: 0)
                          + 8) < 0.0 )
            {
              v65 = idPlayer::GetPhysicsObj(this);
              (*(void (__fastcall **)(idVec3 *, int, _DWORD))(*(_DWORD *)v65 + 88))(a1: &v93, a2: v65, a3: 0);
              v93.z = 0.0;
              idVec3::NormalizeFast(this: &v93);
              v97.x = v89.x - (float)(v93.x * (float)valueFloat);
              v99.x = (float)(v93.x * (float)v32) + v89.x;
              v97.y = v89.y - (float)(v93.y * (float)valueFloat);
              v97.z = v89.z - (float)(v93.z * (float)valueFloat);
              v99.y = (float)(v93.y * (float)v32) + v89.y;
              v99.z = (float)(v93.z * (float)v32) + v89.z;
              idPlayer::PlayerBehavior_ContextualLadder_CheckForLadder(
                this,
                p0: &v99,
                p1: &v97,
                testInfo: &p_contextualLadder->testBackward);
              if ( p_contextualLadder->testBackward.bDetectedLadderTop )
              {
                v66 = p_contextualLadder->testBackward.normal.x;
                p_contextualLadder->ladderNormal.x = p_contextualLadder->testBackward.normal.x;
                v67 = p_contextualLadder->testBackward.normal.y;
                v68 = (float)((float)((float)v22 * (float)v66)
                            + (float)((float)v23 * p_contextualLadder->testBackward.normal.y));
                p_contextualLadder->ladderNormal.y = p_contextualLadder->testBackward.normal.y;
                v69 = p_contextualLadder->testBackward.normal.z;
                v70 = (float)((float)((float)v24 * p_contextualLadder->testBackward.normal.z) + (float)v68);
                p_contextualLadder->ladderNormal.z = p_contextualLadder->testBackward.normal.z;
                p_contextualLadder->ladderUp.x = (float)v22 - (float)((float)v70 * (float)v66);
                p_contextualLadder->ladderUp.y = (float)v23 - (float)((float)v67 * (float)v70);
                p_contextualLadder->ladderUp.z = (float)v24 - (float)((float)v70 * (float)v69);
                idVec3::NormalizeFast(this: &p_contextualLadder->ladderUp);
                v71 = p_contextualLadder->ladderNormal.z;
                v72 = p_contextualLadder->ladderUp.x;
                v73 = p_contextualLadder->ladderNormal.y;
                v74 = p_contextualLadder->ladderUp.y;
                v75 = (float)(p_contextualLadder->ladderUp.z * p_contextualLadder->ladderNormal.y);
                v76 = (float)(p_contextualLadder->ladderUp.y * p_contextualLadder->ladderNormal.x);
                v77 = (float)((float)(p_contextualLadder->ladderUp.z * p_contextualLadder->ladderNormal.x)
                            - (float)(p_contextualLadder->ladderNormal.z * p_contextualLadder->ladderUp.x));
                p_contextualLadder->ladderRight.y = (float)(p_contextualLadder->ladderUp.z
                                                          * p_contextualLadder->ladderNormal.x)
                                                  - (float)(p_contextualLadder->ladderNormal.z
                                                          * p_contextualLadder->ladderUp.x);
                p_contextualLadder->ladderRight.x = (float)((float)v74 * (float)v71) - (float)v75;
                p_contextualLadder->ladderRight.z = (float)((float)v73 * (float)v72) - (float)v76;
                v79 = (float)((float)v34 * (float)((float)((float)v74 * (float)v71) - (float)v75));
                v78 = p_contextualLadder->testBackward.point.x;
                v80 = (float)(p_contextualLadder->ladderNormal.x * (float)v35);
                v81 = (float)(p_contextualLadder->testBackward.point.z
                            - (float)(p_contextualLadder->ladderNormal.z * (float)v35));
                v82 = (float)(p_contextualLadder->testBackward.point.y
                            - (float)(p_contextualLadder->ladderNormal.y * (float)v35));
                v92.y = p_contextualLadder->testBackward.point.y
                      - (float)(p_contextualLadder->ladderNormal.y * (float)v35);
                v92.z = v81;
                v92.x = (float)v78 - (float)v80;
                v101.y = (float)v82 - (float)((float)v77 * (float)v34);
                v101.z = (float)v81 - (float)((float)((float)((float)v73 * (float)v72) - (float)v76) * (float)v34);
                v101.x = v92.x - (float)v79;
                idPlayer::PlayerBehavior_ContextualLadder_CheckForLadder(
                  this,
                  p0: &v101,
                  p1: &v92,
                  testInfo: &p_contextualLadder->testRight);
                v83 = (float)(p_contextualLadder->ladderRight.z * (float)v34);
                v84 = (float)((float)(p_contextualLadder->ladderRight.y * (float)v34) + v92.y);
                v103.x = (float)((float)v34 * p_contextualLadder->ladderRight.x) + v92.x;
                v103.y = v84;
                v103.z = (float)v83 + v92.z;
                idPlayer::PlayerBehavior_ContextualLadder_CheckForLadder(
                  this,
                  p0: &v103,
                  p1: &v92,
                  testInfo: &p_contextualLadder->testLeft);
                v85 = (float)(p_contextualLadder->ladderUp.x * (float)v33);
                v86 = (float)(p_contextualLadder->ladderUp.y * (float)v33);
                v87 = (float)(p_contextualLadder->ladderUp.z * (float)v33);
                v88 = (float)(v92.y - (float)(p_contextualLadder->ladderUp.y * (float)v33));
                v105.x = v92.x - (float)(p_contextualLadder->ladderUp.x * (float)v33);
                v105.y = v88;
                v105.z = v92.z - (float)v87;
                v107.x = (float)v85 + v92.x;
                v107.y = (float)v86 + v92.y;
                v107.z = (float)v87 + v92.z;
                idPlayer::PlayerBehavior_ContextualLadder_CheckForLadder(
                  this,
                  p0: &v107,
                  p1: &v105,
                  testInfo: &p_contextualLadder->testTop);
              }
            }
          }
        }
      }
      break;
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualLadder_StartLadder@idPlayer@@QAAXXZ
// EA  : 0x82E409B8
// RVA : 0x00E409B8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualLadder_StartLadder(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPlayer::idPlayerBehaviorContextualLadder *p_contextualLadder; // r30
  int v4; // r3
  double v5; // fp10
  double v6; // fp9
  idAngles v7; // [sp+50h] [-30h] BYREF

  p_contextualLadder = &this->behaviors.contextualLadder;
  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = 0;
  idHands::Hide(this: (idHands *)(v4 + 37616), hideReason: HAND_HIDE_GENERIC);
  idSpring<idVec2>::SetConstants(
    this: &p_contextualLadder->averagedBodyRotationT,
    _k: pb_clad_AveragedBodyRotationK.valueFloat,
    _c: -1.0);
  v5 = -this->behaviors.contextualLadder.ladderNormal.y;
  v6 = -this->behaviors.contextualLadder.ladderNormal.z;
  v7.pitch = -this->behaviors.contextualLadder.ladderNormal.x;
  v7.yaw = v5;
  v7.roll = v6;
  idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
    this,
    constrain: true,
    heading: &v7,
    maxDeltaPitch: pb_clad_MaxDeltaPitch.valueFloat,
    maxDeltaYaw: pb_clad_MaxDeltaYaw.valueFloat,
    rate: pb_clad_ConstrainedViewAnglesRate.valueFloat);
  idSpring<idVec1>::SetConstants(
    this: &p_contextualLadder->speedScaleSpring,
    _k: pb_clad_SpeedScaleSpringK.valueFloat,
    _c: -1.0);
}


// ========================================================================
// ?PlayerBehavior_ContextualLadder_SetState@idPlayer@@QAAXW4idPlayerBehaviorContextualLadderState_t@1@@Z
// EA  : 0x82E40AB8
// RVA : 0x00E40AB8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualLadder_SetState(idPlayer *this, int state)
{
  idPlayer::idPlayerBehaviorContextualLadder *p_contextualLadder; // r30
  const char *EnumValueName; // r28
  int v6; // r3
  double v7; // fp31
  const blendParms_t *v8; // r7
  bool v9; // r5
  const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v10; // r4
  idPlayer::idPlayerBehaviorContextualLadderState_t v11; // r11
  idPlayer::idPlayerBehaviorContextualLadderState_t v12; // r11
  idVec3 v13; // [sp+50h] [-80h] BYREF
  blendParms_t v14; // [sp+60h] [-70h] BYREF
  blendParms_t v15; // [sp+80h] [-50h] BYREF

  p_contextualLadder = &this->behaviors.contextualLadder;
  if ( pb_clad_DebugTraceStates.valueInteger != 0 )
  {
    EnumValueName = idTypeInfoTools::FindEnumValueName(
                      this: typeInfoTools,
                      enumTypeName: "idPlayer::idPlayerBehaviorContextualLadderState_t",
                      value: state);
    v6 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(
      fmt: "^2(%d)%s - Setting ladder state: %s\n",
      v6,
      "idPlayer::PlayerBehavior_ContextualLadder_SetState",
      EnumValueName);
  }
  blendParms_t::blendParms_t(this: &v15);
  blendParms_t::blendParms_t(this: &v14);
  blendParms_t::SetDuration(this: &v14, frame: pb_clad_AnimBlendFrames.valueInteger);
  switch ( state )
  {
    case 1:
      idPlayer::PlayerBehavior_PostEvent(this, event: PBE_CONTEXTUAL_LADDER_START);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
        this,
        alias: p_contextualLadder->armsAliases,
        loop: false,
        durationMS: -1,
        blendParms: &v15,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        alias: p_contextualLadder->legsAliases,
        loop: false,
        durationMS: -1,
        blendParms: &v15,
        rateScale: 1.0);
      v13.x = pb_clad_MountBotOffsetX.valueFloat;
      v13.y = pb_clad_MountBotOffsetY.valueFloat;
      v13.z = pb_clad_MountBotOffsetZ.valueFloat;
      idPlayer::PlayerBehavior_ContextualLadder_AlignThirdPersonModels(this, extraOffset: &v13);
      idPlayer::PlayerBehavior_ContextualLadder_StartLadder(this);
      goto LABEL_47;
    case 2:
      idPlayer::PlayerBehavior_PostEvent(this, event: PBE_CONTEXTUAL_LADDER_START);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
        this,
        alias: &p_contextualLadder->armsAliases[1],
        loop: false,
        durationMS: -1,
        blendParms: &v15,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        alias: &p_contextualLadder->legsAliases[1],
        loop: false,
        durationMS: -1,
        blendParms: &v15,
        rateScale: 1.0);
      v13.x = pb_clad_MountMidOffsetX.valueFloat;
      v13.y = pb_clad_MountMidOffsetY.valueFloat;
      v13.z = pb_clad_MountMidOffsetZ.valueFloat;
      idPlayer::PlayerBehavior_ContextualLadder_AlignThirdPersonModels(this, extraOffset: &v13);
      idPlayer::PlayerBehavior_ContextualLadder_StartLadder(this);
      goto LABEL_47;
    case 3:
      idPlayer::PlayerBehavior_PostEvent(this, event: PBE_CONTEXTUAL_LADDER_START);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
        this,
        alias: &p_contextualLadder->armsAliases[2],
        loop: false,
        durationMS: -1,
        blendParms: &v15,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        alias: &p_contextualLadder->legsAliases[2],
        loop: false,
        durationMS: -1,
        blendParms: &v15,
        rateScale: 1.0);
      v13.x = pb_clad_MountTopOffsetX.valueFloat;
      v13.y = pb_clad_MountTopOffsetY.valueFloat;
      v13.z = pb_clad_MountTopOffsetZ.valueFloat;
      idPlayer::PlayerBehavior_ContextualLadder_AlignThirdPersonModels(this, extraOffset: &v13);
      idPlayer::PlayerBehavior_ContextualLadder_StartLadder(this);
      goto LABEL_47;
    case 4:
      v7 = 1.0;
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
        this,
        alias: &p_contextualLadder->armsAliases[5],
        loop: true,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      v8 = &v14;
      v9 = true;
      v10 = &p_contextualLadder->legsAliases[5];
      goto LABEL_46;
    case 5:
      idPlayer::PlayerBehavior_Shared_QueueThirdPersonHandsAnim(
        this,
        alias: &p_contextualLadder->armsAliases[6],
        loop: true,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_Shared_QueueThirdPersonLegsAnim(
        this,
        alias: &p_contextualLadder->legsAliases[6],
        loop: true,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      goto LABEL_47;
    case 6:
      v7 = 1.0;
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
        this,
        alias: &p_contextualLadder->armsAliases[7],
        loop: false,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      v8 = &v14;
      v10 = &p_contextualLadder->legsAliases[7];
      goto LABEL_45;
    case 7:
      v7 = 1.0;
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
        this,
        alias: &p_contextualLadder->armsAliases[8],
        loop: false,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      v8 = &v14;
      v10 = &p_contextualLadder->legsAliases[8];
      goto LABEL_45;
    case 8:
      v7 = 1.0;
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
        this,
        alias: &p_contextualLadder->armsAliases[9],
        loop: false,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      v8 = &v14;
      v10 = &p_contextualLadder->legsAliases[9];
      goto LABEL_45;
    case 9:
      v7 = 1.0;
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
        this,
        alias: &p_contextualLadder->armsAliases[10],
        loop: false,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      v8 = &v14;
      v10 = &p_contextualLadder->legsAliases[10];
      goto LABEL_45;
    case 10:
      idSpringCamera::InitSprings(this: this->springCamera, k: 1000.0);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
        this,
        alias: &p_contextualLadder->armsAliases[11],
        loop: false,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        alias: &p_contextualLadder->legsAliases[11],
        loop: false,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_Shared_QueueThirdPersonHandsAnim(
        this,
        alias: &p_contextualLadder->armsAliases[22],
        loop: true,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_Shared_QueueThirdPersonLegsAnim(
        this,
        alias: &p_contextualLadder->legsAliases[22],
        loop: true,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      goto LABEL_47;
    case 11:
      idSpringCamera::InitSprings(this: this->springCamera, k: 1000.0);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
        this,
        alias: &p_contextualLadder->armsAliases[12],
        loop: false,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        alias: &p_contextualLadder->legsAliases[12],
        loop: false,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_Shared_QueueThirdPersonHandsAnim(
        this,
        alias: &p_contextualLadder->armsAliases[21],
        loop: true,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_Shared_QueueThirdPersonLegsAnim(
        this,
        alias: &p_contextualLadder->legsAliases[21],
        loop: true,
        durationMS: -1,
        blendParms: &v14,
        rateScale: 1.0);
      goto LABEL_47;
    case 12:
      idSpringCamera::InitDefaultSprings(this: this->springCamera);
      v11 = p_contextualLadder->state;
      if ( p_contextualLadder->state == CONTEXTUAL_LADDER_STATE_SLIDE_DOWN_LEFT )
      {
        v7 = 1.0;
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
          this,
          alias: &p_contextualLadder->armsAliases[13],
          loop: false,
          durationMS: -1,
          blendParms: &v14,
          rateScale: 1.0);
        v8 = &v14;
        v10 = &p_contextualLadder->legsAliases[13];
      }
      else
      {
        switch ( v11 )
        {
          case CONTEXTUAL_LADDER_STATE_SLIDE_DOWN_RIGHT:
            v7 = 1.0;
            idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
              this,
              alias: &p_contextualLadder->armsAliases[14],
              loop: false,
              durationMS: -1,
              blendParms: &v14,
              rateScale: 1.0);
            v8 = &v14;
            v10 = &p_contextualLadder->legsAliases[14];
            break;
          case CONTEXTUAL_LADDER_STATE_CLIMB_DOWN_LEFT:
            v7 = 1.0;
            idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
              this,
              alias: &p_contextualLadder->armsAliases[15],
              loop: false,
              durationMS: -1,
              blendParms: &v14,
              rateScale: 1.0);
            v8 = &v14;
            v10 = &p_contextualLadder->legsAliases[15];
            break;
          case CONTEXTUAL_LADDER_STATE_CLIMB_DOWN_RIGHT:
          case CONTEXTUAL_LADDER_STATE_IDLE_UP_LEFT:
            v7 = 1.0;
            idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
              this,
              alias: &p_contextualLadder->armsAliases[16],
              loop: false,
              durationMS: -1,
              blendParms: &v14,
              rateScale: 1.0);
            v8 = &v14;
            v10 = &p_contextualLadder->legsAliases[16];
            break;
          default:
            v7 = 1.0;
            if ( v11 == CONTEXTUAL_LADDER_STATE_IDLE_UP_RIGHT )
            {
              idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
                this,
                alias: &p_contextualLadder->armsAliases[15],
                loop: false,
                durationMS: -1,
                blendParms: &v14,
                rateScale: 1.0);
              v8 = &v14;
              v10 = &p_contextualLadder->legsAliases[15];
            }
            else
            {
              idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
                this,
                alias: &p_contextualLadder->armsAliases[16],
                loop: false,
                durationMS: -1,
                blendParms: &v14,
                rateScale: 1.0);
              v8 = &v14;
              v10 = &p_contextualLadder->legsAliases[16];
            }
            break;
        }
      }
      goto LABEL_45;
    case 13:
      idSpringCamera::InitDefaultSprings(this: this->springCamera);
      v12 = p_contextualLadder->state;
      if ( p_contextualLadder->state == CONTEXTUAL_LADDER_STATE_SLIDE_DOWN_LEFT )
        goto LABEL_37;
      switch ( v12 )
      {
        case CONTEXTUAL_LADDER_STATE_SLIDE_DOWN_RIGHT:
        case CONTEXTUAL_LADDER_STATE_CLIMB_DOWN_LEFT:
          goto LABEL_34;
        case CONTEXTUAL_LADDER_STATE_CLIMB_DOWN_RIGHT:
          goto LABEL_37;
        case CONTEXTUAL_LADDER_STATE_CLIMB_UP_LEFT:
LABEL_34:
          v7 = 1.0;
          idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
            this,
            alias: &p_contextualLadder->armsAliases[18],
            loop: false,
            durationMS: -1,
            blendParms: &v14,
            rateScale: 1.0);
          v8 = &v14;
          v10 = &p_contextualLadder->legsAliases[18];
          break;
        case CONTEXTUAL_LADDER_STATE_CLIMB_UP_RIGHT:
        case CONTEXTUAL_LADDER_STATE_IDLE_UP_LEFT:
LABEL_37:
          v7 = 1.0;
          idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
            this,
            alias: &p_contextualLadder->armsAliases[17],
            loop: false,
            durationMS: -1,
            blendParms: &v14,
            rateScale: 1.0);
          v8 = &v14;
          v10 = &p_contextualLadder->legsAliases[17];
          break;
        default:
          v7 = 1.0;
          if ( v12 == CONTEXTUAL_LADDER_STATE_IDLE_UP_RIGHT )
          {
            idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
              this,
              alias: &p_contextualLadder->armsAliases[18],
              loop: false,
              durationMS: -1,
              blendParms: &v14,
              rateScale: 1.0);
            v8 = &v14;
            v10 = &p_contextualLadder->legsAliases[18];
          }
          else
          {
            idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
              this,
              alias: &p_contextualLadder->armsAliases[17],
              loop: false,
              durationMS: -1,
              blendParms: &v14,
              rateScale: 1.0);
            v8 = &v14;
            v10 = &p_contextualLadder->legsAliases[17];
          }
          break;
      }
LABEL_45:
      v9 = false;
LABEL_46:
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        alias: v10,
        loop: v9,
        durationMS: -1,
        blendParms: v8,
        rateScale: v7);
LABEL_47:
      p_contextualLadder->state = state;
      if ( state != 0 )
      {
        idPlayer::PlayerBehavior_Shared_AutoApplyThirdPersonHandsAnimDeltas(this, applyToPlayer: true, clip: false);
        idPlayer::PlayerBehavior_Shared_AutoApplyThirdPersonLegsAnimDeltas(this, applyToPlayer: true, clip: false);
      }
      return;
    case 15:
      idSpringCamera::InitDefaultSprings(this: this->springCamera);
      v7 = 1.0;
      if ( p_contextualLadder->state == CONTEXTUAL_LADDER_STATE_CLIMB_UP_LEFT )
      {
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
          this,
          alias: &p_contextualLadder->armsAliases[19],
          loop: false,
          durationMS: -1,
          blendParms: &v15,
          rateScale: 1.0);
        v10 = &p_contextualLadder->legsAliases[19];
      }
      else
      {
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
          this,
          alias: &p_contextualLadder->armsAliases[20],
          loop: false,
          durationMS: -1,
          blendParms: &v15,
          rateScale: 1.0);
        v10 = &p_contextualLadder->legsAliases[20];
      }
      v8 = &v15;
      goto LABEL_45;
    default:
      goto LABEL_47;
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualLadder_Handle@idPlayer@@QAAXXZ
// EA  : 0x82E41308
// RVA : 0x00E41308
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualLadder_Handle(idPlayer *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  unsigned __int64 v4; // r26
  char v5; // r11
  idPresentable *presentable; // r3
  char v7; // r30
  int v8; // r3
  unsigned __int8 v9; // r5
  int v10; // r23
  idPlayer::idPlayerBehaviorContextualLadderState_t state; // r11
  idPlayer::idPlayerBehaviorContextualLadder *p_contextualLadder; // r30
  idPresentable *v13; // r3
  double valueFloat; // fp26
  double v15; // fp25
  int v16; // r3
  __int64 v17; // r7
  __int64 v18; // r11
  double v19; // fp27
  idPresentable *v20; // r3
  int v21; // r3
  bool v22; // r11
  idPresentable *v23; // r3
  int v24; // r3
  idPresentable *v25; // r3
  int v26; // r3
  idPlayer::idPlayerBehaviorContextualLadderState_t v27; // r9
  bool v28; // r25
  int v29; // r11
  char v30; // r11
  bool v31; // zf
  int v32; // r11
  char v33; // r11
  char v34; // r29
  char v35; // r3
  long double v36; // fp2
  double groundDist; // fp13
  bool v38; // r28
  int v39; // r4
  idPresentable *v40; // r3
  double v41; // fp31
  double v42; // fp30
  double v43; // fp29
  float *v44; // r3
  float v45; // r9
  float v46; // r10
  double v47; // fp28
  idVec3 *v48; // r11
  double v49; // fp9
  double v50; // fp30
  double v51; // fp29
  double v52; // fp31
  int PhysicsObj; // r3
  double v54; // fp26
  double v55; // fp25
  double v56; // fp24
  float *v57; // r3
  double v58; // fp13
  double v59; // fp5
  double v60; // fp4
  int v61; // r29
  int v62; // r28
  int entityNumber; // r25
  idMat3 *v64; // r24
  idClipModel *v65; // r3
  unsigned __int64 *v66; // r3
  idPlayer::idPlayerBehaviorContextualLadderDismountType_t v67; // r11
  int v68; // r3
  float *v69; // r3
  double v76; // fp29
  int v77; // r3
  float *v78; // r3
  idPlayer::idPlayerBehaviorContextualLadderState_t v79; // r10
  idPhysics *Physics; // r3
  int v81; // r9
  idPresentable *v82; // r3
  float v83; // r7
  float v84; // r6
  const idAngles *v85; // r4
  idPlayer_vtbl *v86; // r29
  idPresentablePlayer *ViewAngles; // r3
  idPhysics_Player *v88; // r3
  int v89; // r3
  int v90; // r3
  int v91; // r3
  char v92; // r11
  char v93; // r28
  double v94; // fp13
  double v95; // fp11
  double v96; // fp8
  double v97; // fp5
  idPresentable *v98; // r3
  int p_firstPersonViewAxis; // r11
  float *v100; // r3
  double v101; // fp12
  double v102; // fp10
  float v103; // r8
  long double v104; // fp2
  idVec3 *p_normal; // r11
  idPhysics_Player *v106; // r3
  idPresentable *v107; // r3
  int v108; // r3
  double v109; // fp13
  idPhysics *v110; // r3
  int v111; // r3
  float v112; // r6
  float v113; // r11
  double v114; // fp10
  double v115; // fp8
  double x; // fp9
  idPlayer_vtbl *v117; // r29
  idAngles *v118; // r3
  idPhysics_Player *v119; // r3
  BOOL v120; // r30
  idPlayer *v121; // r3
  BOOL v122; // r30
  BOOL v123; // r30
  idPlayer *v124; // r3
  idClipQuery *p_ladderClipQuery; // r29
  idClip *p_clip; // r28
  unsigned __int64 index; // r11
  idVec3 *v128; // r11
  double z; // fp13
  double y; // fp12
  double v131; // fp11
  double v132; // fp10
  double v133; // fp7
  double v134; // fp6
  int v135; // r3
  int v136; // r3
  double v137; // fp12
  double v138; // fp11
  int v139; // [sp+8h] [-298h]
  bool v140; // [sp+Fh] [-291h]
  const char *v141; // [sp+10h] [-290h]
  int v142; // [sp+14h] [-28Ch]
  int v143; // [sp+18h] [-288h]
  int v144; // [sp+1Ch] [-284h]
  int v145; // [sp+20h] [-280h]
  int v146; // [sp+24h] [-27Ch]
  int v147; // [sp+28h] [-278h]
  int v148; // [sp+2Ch] [-274h]
  int v149; // [sp+30h] [-270h]
  int v150; // [sp+34h] [-26Ch]
  int v151; // [sp+38h] [-268h]
  int v152; // [sp+3Ch] [-264h]
  int v153; // [sp+40h] [-260h]
  int v154; // [sp+44h] [-25Ch]
  int v155; // [sp+48h] [-258h]
  int v156; // [sp+4Ch] [-254h]
  int v157; // [sp+50h] [-250h]
  int v158; // [sp+58h] [-248h]
  int v159; // [sp+60h] [-240h]
  idVec3 v160; // [sp+70h] [-230h] BYREF
  idVec3 v161; // [sp+80h] [-220h] BYREF
  idPLogScope v162; // [sp+90h] [-210h] BYREF
  idVec3 v163; // [sp+98h] [-208h] BYREF
  float v164[4]; // [sp+A8h] [-1F8h] BYREF
  float v165[4]; // [sp+B8h] [-1E8h] BYREF
  idVec3 v166; // [sp+C8h] [-1D8h] BYREF
  float v167[16]; // [sp+E0h] [-1C0h] BYREF
  idMat3 v168; // [sp+120h] [-180h] BYREF
  idMat3 v169; // [sp+148h] [-158h] BYREF
  trace_t v170; // [sp+170h] [-130h] BYREF

  RD_EventBegin(name: "idPlayer::PlayerBehavior_ContextualLadder_Handle");
  LODWORD(v2) = "idPlayer::PlayerBehavior_ContextualLadder_Handle";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v162, pl: &pLog, gMask: v2, label: v3);
  LODWORD(v4) = 0;
  if ( pb_clad_Enable.valueInteger == 0 || (v5 = 1, !this->behaviors.contextualLadder.bEnabled) )
    v5 = 0;
  presentable = this->presentable;
  v7 = v5;
  if ( presentable != nullptr )
    v8 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v8 = 0;
  if ( (*(_BYTE *)(v8 + 47032) & 0x20) != 0 )
  {
    if ( this->behaviors.contextualLadder.state != CONTEXTUAL_LADDER_STATE_NONE )
    {
      idPlayer::PlayerBehavior_ContextualLadder_EndLadder(this);
      idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 0);
    }
    goto LABEL_82;
  }
  v9 = common->IsMultiplayer(this: common) - 1;
  v10 = (unsigned __int8)(v9 & v7);
  if ( (v9 & (unsigned __int8)v7) != 0 )
  {
    *(_BYTE *)(idPlayer::GetPhysicsObj(this) + 1196) = 0;
  }
  else
  {
    *(_BYTE *)(idPlayer::GetPhysicsObj(this) + 1196) = 1;
    if ( this->behaviors.contextualLadder.state == CONTEXTUAL_LADDER_STATE_NONE )
    {
LABEL_82:
      idPLogScope::~idPLogScope(this: &v162);
      goto LABEL_210;
    }
  }
  if ( v10 != 0 )
    idPlayer::PlayerBehavior_ContextualLadder_CheckSurroundings(this);
  state = this->behaviors.contextualLadder.state;
  p_contextualLadder = &this->behaviors.contextualLadder;
  LODWORD(v160.x) = &this->behaviors.contextualLadder;
  if ( state == CONTEXTUAL_LADDER_STATE_NONE
    && !this->behaviors.contextualLadder.testForward.bDetectedLadder
    && !this->behaviors.contextualLadder.testBackward.bDetectedLadderTop )
  {
    goto LABEL_82;
  }
  if ( (pb_clad_OutputDeltaMove.flags & 0x20000) != 0 )
  {
    pb_clad_OutputDeltaMove.flags &= ~0x20000u;
    outputDeltaMove = pb_clad_OutputDeltaMove.valueInteger;
  }
  if ( (pb_clad_OutputDeltaZ.flags & 0x20000) != 0 )
  {
    pb_clad_OutputDeltaZ.flags &= ~0x20000u;
    outputDeltaZ = pb_clad_OutputDeltaZ.valueInteger;
  }
  v13 = this->presentable;
  valueFloat = pb_clad_InputDeadZone.valueFloat;
  v15 = pb_clad_InputSlideThreshold.valueFloat;
  if ( v13 != nullptr )
    v16 = (int)v13->GetPlayerInterface_2(this: v13);
  else
    v16 = 0;
  HIDWORD(v18) = p_contextualLadder->state;
  HIDWORD(v17) = byte_821B0000;
  LODWORD(v160.x) = &this->behaviors.contextualLadder;
  LODWORD(v18) = *(char *)(v16 + 46318);
  *(_QWORD *)&v160.x = v18;
  v19 = (float)((float)v18 * (float)0.0078740157);
  if ( HIDWORD(v18) != 0 )
  {
    v22 = false;
    if ( HIDWORD(v18) != 1 )
    {
      if ( this->behaviors.contextualLadder.prevState == CONTEXTUAL_LADDER_STATE_NONE
        || ((v20 = this->presentable) == nullptr ? (v21 = 0) : (v21 = (int)v20->GetPlayerInterface_2(this: v20)),
            LODWORD(v17) = *(char *)(v21 + 46258),
            *(_QWORD *)&v160.x = v17,
            __fabs((float)((float)v17 * (float)0.0078740157)) < 0.0099999998) )
      {
        v22 = true;
      }
    }
    if ( v22 || this->behaviors.contextualLadder.blockClimpOffAtTop )
    {
      v23 = this->presentable;
      if ( v23 != nullptr )
        v24 = (int)v23->GetPlayerInterface_2(this: v23);
      else
        v24 = 0;
      this->behaviors.contextualLadder.invertInput = *(float *)(v24 + 46552) < -0.40000001;
    }
  }
  else
  {
    this->behaviors.contextualLadder.invertInput = false;
  }
  if ( this->behaviors.contextualLadder.invertInput )
    v19 = -v19;
  if ( this->behaviors.contextualLadder.blockClimpOffAtTop && v19 < 0.0099999998 )
    this->behaviors.contextualLadder.blockClimpOffAtTop = false;
  this->behaviors.contextualLadder.prevState = this->behaviors.contextualLadder.state;
  v25 = this->presentable;
  if ( v25 != nullptr )
    v26 = (int)v25->GetPlayerInterface_2(this: v25);
  else
    v26 = 0;
  v27 = p_contextualLadder->state;
  LODWORD(v160.x) = &this->behaviors.contextualLadder;
  v28 = *(char *)(v26 + 46320) >= 10;
  if ( v27 != CONTEXTUAL_LADDER_STATE_NONE )
  {
    v29 = p_contextualLadder->state;
    LODWORD(v160.x) = &this->behaviors.contextualLadder;
    if ( v29 < 12 || (v31 = v29 <= 15, v30 = 1, !v31) )
      v30 = 0;
    if ( v30 == 0 )
    {
      v32 = p_contextualLadder->state;
      LODWORD(v160.x) = &this->behaviors.contextualLadder;
      if ( v32 <= 0 || (v31 = v32 <= 3, v33 = 1, !v31) )
        v33 = 0;
      if ( v33 == 0 )
      {
        v34 = 0;
        v35 = idPlayer::PlayerBehavior_ContextualLadder_AtLadderBottom(this);
        groundDist = this->behaviors.contextualLadder.groundDist;
        LODWORD(v160.x) = &this->behaviors.contextualLadder;
        v38 = groundDist < pb_clad_AtBottomDist.valueFloat;
        if ( v10 == 0 || (v35 != 0 || groundDist < pb_clad_AtBottomDist.valueFloat) && v19 < -valueFloat )
          v34 = 1;
        if ( v28 )
        {
          this->behaviors.contextualLadder.dismountType = CONTEXTUAL_LADDER_DISMOUNT_TYPE_JUMP;
          idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 14);
          v34 = 0;
        }
        else
        {
          v40 = this->presentable;
          v41 = -this->behaviors.contextualLadder.ladderNormal.z;
          v42 = -this->behaviors.contextualLadder.ladderNormal.y;
          v43 = -this->behaviors.contextualLadder.ladderNormal.x;
          if ( v40 != nullptr )
            v44 = (float *)v40->GetPlayerInterface_2(this: v40);
          else
            v44 = nullptr;
          v45 = v44[11639];
          v46 = v44[11640];
          v160.z = v44[11641];
          v160.x = v45;
          v160.y = v46;
          *(double *)&v36 = (float)((float)(v45 * (float)v43)
                                  + (float)((float)(v160.z * (float)v41) + (float)(v46 * (float)v42)));
          v47 = (float)((float)(idMath::ACos(a: v36) * idMath::M_RAD2DEG) - (float)90.0);
          if ( __fabs(v47) > (float)(pb_clad_MaxDeltaYaw.valueFloat - (float)3.0) )
          {
            idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 14);
            if ( v47 >= 0.0 )
            {
              v48 = &v160;
              v160.x = -vec3_up.x;
              v160.z = -vec3_up.z;
              v160.y = -vec3_up.y;
            }
            else
            {
              v48 = &vec3_up;
            }
            v49 = (float)(v48->z * (float)v43);
            v51 = (float)((float)(v48->y * (float)v43) - (float)(v48->x * (float)v42));
            v50 = (float)((float)(v48->z * (float)v42) - (float)(v48->y * (float)v41));
            v52 = (float)((float)(v48->x * (float)v41) - (float)v49);
            PhysicsObj = idPlayer::GetPhysicsObj(this);
            v54 = (float)(vec3_up.z * (float)30.0);
            v55 = (float)(vec3_up.y * (float)30.0);
            v56 = (float)(vec3_up.x * (float)30.0);
            v57 = (float *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)PhysicsObj + 64))(a1: PhysicsObj, a2: 0);
            v58 = (float)((float)v56 + *v57);
            v59 = (float)(v57[2] + (float)v54);
            v60 = (float)(v57[1] + (float)v55);
            v166.x = (float)v56 + *v57;
            v166.y = v60;
            v166.z = v59;
            v163.y = (float)((float)v52 * (float)60.0) + (float)v60;
            v163.x = (float)((float)v50 * (float)60.0) + (float)v58;
            v163.z = (float)((float)v51 * (float)60.0) + (float)v59;
            v61 = idPlayer::GetPhysicsObj(this);
            v62 = idPlayer::GetPhysicsObj(this);
            entityNumber = this->entityNumber;
            v64 = (idMat3 *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)v61 + 68))(a1: v61, a2: 0);
            v65 = (idClipModel *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)v62 + 8))(a1: v62, a2: 0);
            v66 = (unsigned __int64 *)idClip::Translation(
                                        this: (idClip *)&v160,
                                        result: &clientGame->clip,
                                        a3: nullptr,
                                        start: &v166,
                                        end: &v163,
                                        clipModel: v65,
                                        startAxis: v64,
                                        clipMask: 107529,
                                        passEntityNumber: v139,
                                        moveClipModel: v140,
                                        userName: v141,
                                        a12: v142,
                                        a13: v143,
                                        a14: v144,
                                        a15: v145,
                                        a16: v146,
                                        a17: v147,
                                        a18: v148,
                                        a19: v149,
                                        a20: v150,
                                        a21: v151,
                                        a22: v152,
                                        a23: v153,
                                        a24: v154,
                                        a25: v155,
                                        a26: v156,
                                        a27: v157,
                                        a28: entityNumber,
                                        a29: v158,
                                        a30: false,
                                        a31: v159,
                                        a32: (int)"w:\\tech5\\tungsten\\game\\player\\PlayerBehaviorContextualLadder.cpp(489) : Translation");
            v67 = CONTEXTUAL_LADDER_DISMOUNT_TYPE_LEFT;
            this->behaviors.contextualLadder.ladderClipQuery.index = *v66;
            if ( v47 <= 0.0 )
              v67 = CONTEXTUAL_LADDER_DISMOUNT_TYPE_RIGHT;
            this->behaviors.contextualLadder.dismountType = v67;
            if ( pb_clad_Debug.valueInteger != 0 )
            {
              v68 = idPlayer::GetPhysicsObj(this);
              v69 = (float *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)v68 + 8))(a1: v68, a2: 0);
              LODWORD(v160.x) = v69 + 20;
              _FP12 = (float)((float)__fabs(v69[22]) - (float)__fabs(v69[25]));
              _FP11 = (float)((float)__fabs(v69[21]) - (float)__fabs(v69[24]));
              _FP8 = (float)((float)__fabs(v69[20]) - (float)__fabs(v69[23]));
              __asm
              {
                fsel      f7, f12, f9, f10
                fsel      f31, f11, f4, f6
                fsel      f30, f8, f1, f2
              }
              v76 = (float)((float)_FP7 * (float)0.5);
              v163.z = (float)((float)_FP7 * (float)0.5) + v163.z;
              v77 = idPlayer::GetPhysicsObj(this);
              v78 = (float *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)v77 + 68))(a1: v77, a2: 0);
              v167[0] = v163.x;
              LODWORD(v160.x) = v78 + 6;
              v167[1] = v163.y;
              v167[2] = v163.z;
              v167[3] = _FP30;
              v167[4] = _FP31;
              v167[5] = v76;
              v167[6] = *v78;
              v167[7] = v78[1];
              v167[8] = v78[2];
              v167[9] = v78[3];
              v167[10] = v78[4];
              v167[11] = v78[5];
              v167[12] = v78[6];
              v167[13] = v78[7];
              v167[14] = v78[8];
              clientGame->renderWorld->DebugBox(
                this: clientGame->renderWorld,
                a2: (const idVec4 *)&idColor::colorYellow,
                a3: (const idBox *)v167,
                a4: 10000,
                a5: false);
            }
            goto LABEL_82;
          }
        }
        if ( v34 != 0 )
        {
          this->behaviors.contextualLadder.dismountType = CONTEXTUAL_LADDER_DISMOUNT_TYPE_BACK;
          if ( v38 )
            v39 = 12;
          else
            v39 = 13;
          idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: v39);
        }
      }
    }
  }
  v79 = p_contextualLadder->state;
  HIDWORD(v4) = &pm_normalviewheight;
  LODWORD(v160.x) = &this->behaviors.contextualLadder;
  if ( v79 != CONTEXTUAL_LADDER_STATE_NONE )
  {
    Physics = idEntity::GetPhysics(this: this->thirdPersonHands);
    v81 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v83 = *(float *)v81;
    v84 = *(float *)(v81 + 4);
    v82 = this->presentable;
    v160.z = *(float *)(v81 + 8) - pm_normalviewheight.valueFloat;
    v160.x = v83;
    v160.y = v84;
    if ( v82 != nullptr )
      v85 = (const idAngles *)v82->GetPlayerInterface_2(this: v82);
    else
      v85 = nullptr;
    v86 = this->__vftable;
    ViewAngles = idPresentablePlayer::GetViewAngles(
                   this: (idPresentablePlayer *)&v161,
                   result: v85,
                   includeWeaponKick: true);
    v86->Teleport(this, a2: &v160, a3: (const idAngles *)ViewAngles);
    v88 = (idPhysics_Player *)idPlayer::GetPhysicsObj(this);
    idPhysics_Player::SetCrouch(this: v88, crouch: true);
  }
  idPlayer::PlayerBehavior_ContextualLadder_HandleSpeedScale(this);
  switch ( p_contextualLadder->state )
  {
    case CONTEXTUAL_LADDER_STATE_NONE:
      this->behaviors.contextualLadder.blockClimpOffAtTop = false;
      v89 = idPlayer::GetPhysicsObj(this);
      if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v89 + 248))(a1: v89) != 0
        || (v90 = idPlayer::GetPhysicsObj(this),
            v91 = (*(int (__fastcall **)(float *, int, _DWORD))(*(_DWORD *)v90 + 88))(
                    a1: &v169.mat[1].y,
                    a2: v90,
                    a3: 0),
            v92 = 1,
            *(float *)(v91 + 8) >= 0.0) )
      {
        v92 = 0;
      }
      v93 = v92;
      v94 = 180.0;
      if ( (this->behaviors.contextualLadder.testForward.bDetectedLadder
         || v92 != 0 && this->behaviors.contextualLadder.testBackward.bDetectedLadderTop)
        && this->behaviors.contextualLadder.testLeft.bDetectedLadder
        && this->behaviors.contextualLadder.testRight.bDetectedLadder )
      {
        v95 = (float)(this->behaviors.contextualLadder.testRight.point.y
                    - this->behaviors.contextualLadder.testLeft.point.y);
        v96 = (float)(this->behaviors.contextualLadder.testRight.point.x
                    - this->behaviors.contextualLadder.testLeft.point.x);
        v97 = (float)(this->behaviors.contextualLadder.testRight.point.z
                    - this->behaviors.contextualLadder.testLeft.point.z);
        LODWORD(v160.x) = &this->behaviors.contextualLadder.testLeft.point;
        if ( (float)((float)((float)v97 * (float)v97)
                   + (float)((float)((float)v96 * (float)v96) + (float)((float)v95 * (float)v95))) >= (double)(float)(pb_clad_MinLadderWidth.valueFloat * pb_clad_MinLadderWidth.valueFloat)
          && (v19 > 0.0 || v92 != 0) )
        {
          v98 = this->presentable;
          if ( this->behaviors.contextualLadder.testBackward.bDetectedLadderTop )
          {
            if ( v98 != nullptr )
              p_firstPersonViewAxis = (int)&v98->GetPlayerInterface_2(this: v98)->firstPersonViewAxis;
            else
              p_firstPersonViewAxis = 46544;
          }
          else
          {
            if ( v98 != nullptr )
              v100 = (float *)v98->GetPlayerInterface_2(this: v98);
            else
              v100 = nullptr;
            p_firstPersonViewAxis = (int)&v161;
            v101 = -v100[11638];
            v102 = -v100[11637];
            v161.x = -v100[11636];
            v161.z = v101;
            v161.y = v102;
          }
          v103 = *(float *)(p_firstPersonViewAxis + 4);
          v160.x = *(float *)p_firstPersonViewAxis;
          v160.z = 0.0;
          v160.y = v103;
          idVec3::NormalizeFast(this: &v160);
          p_normal = &this->behaviors.contextualLadder.testBackward.normal;
          if ( !this->behaviors.contextualLadder.testBackward.bDetectedLadderTop )
            p_normal = &this->behaviors.contextualLadder.testForward.normal;
          *(double *)&v104 = (float)((float)(p_normal->x * v160.x)
                                   + (float)((float)(p_normal->z * v160.z) + (float)(p_normal->y * v160.y)));
          v94 = (float)(idMath::ACos(a: v104) * idMath::M_RAD2DEG);
        }
      }
      if ( v94 > pb_clad_InitiateMaxAngle.valueFloat )
      {
        this->behaviors.contextualLadder.initiateInputTime = 0;
      }
      else if ( v93 != 0 )
      {
        this->behaviors.contextualLadder.initiateInputTime = pb_clad_InitiateInputTime.valueInteger;
      }
      else
      {
        this->behaviors.contextualLadder.initiateInputTime += gameLocal->GetGameMsPerFrame(
                                                                this: gameLocal,
                                                                a2: GAMETIME_SCALED);
      }
      if ( this->behaviors.contextualLadder.initiateInputTime < pb_clad_InitiateInputTime.valueInteger )
        goto LABEL_209;
      this->behaviors.contextualLadder.dismountType = CONTEXTUAL_LADDER_DISMOUNT_TYPE_NONE;
      idAlignedEntity::AttachCamera(
        this: this->thirdPersonHands,
        jointName: "camera",
        durationMode: DURATION_ALWAYS,
        lookMode: LOOK_ADD_HEADING,
        blendMode: BLEND_SMOOTH_SNAP_SMOOTH,
        blendDurationMS: -1,
        viewConeDeg: 0.0,
        autoCenterK: 1.0);
      v106 = (idPhysics_Player *)idPlayer::GetPhysicsObj(this);
      idPhysics_Player::SetCrouch(this: v106, crouch: true);
      v107 = this->presentable;
      if ( v107 != nullptr )
        v108 = (int)v107->GetPlayerInterface_2(this: v107);
      else
        v108 = 0;
      *(_BYTE *)(v108 + 19040) = 1;
      if ( !this->behaviors.contextualLadder.testForward.bDetectedLadderTop
        && !this->behaviors.contextualLadder.testBackward.bDetectedLadderTop )
      {
        if ( (unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_AtLadderBottom(this) != 0
          || (v109 = this->behaviors.contextualLadder.groundDist,
              LODWORD(v160.x) = &this->behaviors.contextualLadder,
              v109 < pb_clad_AtBottomDist.valueFloat) )
        {
          idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 1);
          goto LABEL_209;
        }
      }
      else if ( (unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_AtLadderTop(this) != 0 )
      {
        if ( this->behaviors.contextualLadder.testBackward.bDetectedLadderTop )
        {
          v110 = idEntity::GetPhysics(this: this->thirdPersonHands);
          v111 = (int)v110->GetOrigin(this: v110, a2: 0);
          v112 = *(float *)v111;
          v113 = *(float *)(v111 + 4);
          v114 = -this->behaviors.contextualLadder.ladderNormal.z;
          v115 = -this->behaviors.contextualLadder.ladderNormal.y;
          x = this->behaviors.contextualLadder.ladderNormal.x;
          v160.z = *(float *)(v111 + 8);
          v160.x = v112;
          v160.y = v113;
          v168.mat[0].x = -x;
          v168.mat[2].x = vec3_up.x;
          v168.mat[2].y = vec3_up.y;
          v168.mat[2].z = vec3_up.z;
          v168.mat[0].z = v114;
          v168.mat[0].y = v115;
          v160.z = v160.z - pm_normalviewheight.valueFloat;
          idMat3::OrthoNormalizeSelf(this: &v168, prio1: 0, prio2: 2);
          v117 = this->__vftable;
          v118 = idMat3::ToAngles(this: &v169, result: (idAngles *)&v168);
          v117->Teleport(this, a2: &v160, a3: v118);
          v119 = (idPhysics_Player *)idPlayer::GetPhysicsObj(this);
          idPhysics_Player::SetCrouch(this: v119, crouch: true);
        }
        idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 3);
        this->behaviors.contextualLadder.blockClimpOffAtTop = true;
LABEL_209:
        idPlayer::PlayerBehavior_ContextualLadder_DebugHandle(this);
        idPLogScope::~idPLogScope(this: &v162);
LABEL_210:
        RD_EventEnd();
        return;
      }
      idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 2);
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_MOUNT_BOTTOM:
      v120 = (_cntlzw((unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_ShiftIntoPosition(
                                         this,
                                         clipMovement: false))
            & 0x20) != 0;
      v161.x = pb_clad_MountBotOffsetX.valueFloat;
      v161.y = pb_clad_MountBotOffsetY.valueFloat;
      v161.z = pb_clad_MountBotOffsetZ.valueFloat;
      idPlayer::PlayerBehavior_ContextualLadder_AlignThirdPersonModels(this, extraOffset: &v161);
      if ( v120 )
      {
        v121 = this;
        if ( v19 <= valueFloat )
          goto LABEL_135;
        goto LABEL_134;
      }
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_MOUNT_MID:
      v122 = (_cntlzw((unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_ShiftIntoPosition(
                                         this,
                                         clipMovement: false))
            & 0x20) != 0;
      v161.x = pb_clad_MountMidOffsetX.valueFloat;
      v161.y = pb_clad_MountMidOffsetY.valueFloat;
      v161.z = pb_clad_MountMidOffsetZ.valueFloat;
      idPlayer::PlayerBehavior_ContextualLadder_AlignThirdPersonModels(this, extraOffset: &v161);
      if ( v122 )
      {
        if ( v19 <= valueFloat )
          goto LABEL_140;
        goto LABEL_138;
      }
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_MOUNT_TOP:
      v123 = (_cntlzw((unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_ShiftIntoPosition(
                                         this,
                                         clipMovement: false))
            & 0x20) != 0;
      v161.x = pb_clad_MountTopOffsetX.valueFloat;
      v161.y = pb_clad_MountTopOffsetY.valueFloat;
      v161.z = pb_clad_MountTopOffsetZ.valueFloat;
      idPlayer::PlayerBehavior_ContextualLadder_AlignThirdPersonModels(this, extraOffset: &v161);
      if ( v123 )
        goto LABEL_140;
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_IDLE_UP_LEFT:
      if ( v19 > valueFloat && (unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_AtCeiling(this) == 0 )
        goto LABEL_171;
      if ( v19 < -valueFloat )
        goto LABEL_141;
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_IDLE_UP_RIGHT:
      if ( v19 > valueFloat && (unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_AtCeiling(this) == 0 )
      {
        v31 = (unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_AtLadderTop(this) != 0;
        v121 = this;
        if ( v31 )
          goto LABEL_158;
        goto LABEL_149;
      }
      if ( v19 < -valueFloat )
        goto LABEL_151;
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_CLIMB_DOWN_LEFT:
      this->behaviors.contextualLadder.blockClimpOffAtTop = false;
      if ( idAlignedEntity::IsCurAnimDone(this: this->thirdPersonHands, numFramesAhead: -1, ignoreQueuedAnims: false)
        && idAlignedEntity::IsCurAnimDone(this: this->thirdPersonLegs, numFramesAhead: -1, ignoreQueuedAnims: false) )
      {
        if ( v19 <= valueFloat || (unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_AtCeiling(this) != 0 )
          goto LABEL_159;
        idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 9);
      }
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_CLIMB_DOWN_RIGHT:
      this->behaviors.contextualLadder.blockClimpOffAtTop = false;
      if ( idAlignedEntity::IsCurAnimDone(this: this->thirdPersonHands, numFramesAhead: -1, ignoreQueuedAnims: false)
        && idAlignedEntity::IsCurAnimDone(this: this->thirdPersonLegs, numFramesAhead: -1, ignoreQueuedAnims: false) )
      {
        if ( v19 <= valueFloat || (unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_AtCeiling(this) != 0 )
          goto LABEL_140;
LABEL_138:
        idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 8);
      }
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_CLIMB_UP_LEFT:
      if ( (unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_AtCeiling(this) != 0 )
        goto LABEL_153;
      if ( idAlignedEntity::IsCurAnimDone(this: this->thirdPersonHands, numFramesAhead: -1, ignoreQueuedAnims: false)
        && idAlignedEntity::IsCurAnimDone(this: this->thirdPersonLegs, numFramesAhead: -1, ignoreQueuedAnims: false) )
      {
        if ( v19 <= valueFloat )
        {
LABEL_159:
          if ( v19 < -valueFloat )
LABEL_151:
            idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 7);
          else
LABEL_153:
            idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 5);
        }
        else
        {
          v31 = (unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_AtLadderTop(this) == 0;
          v121 = this;
          if ( !v31 )
            goto LABEL_158;
LABEL_149:
          idPlayer::PlayerBehavior_ContextualLadder_SetState(this: v121, state: 9);
        }
      }
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_CLIMB_UP_RIGHT:
      if ( (unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_AtCeiling(this) != 0 )
      {
        idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 4);
      }
      else if ( idAlignedEntity::IsCurAnimDone(
                  this: this->thirdPersonHands,
                  numFramesAhead: -1,
                  ignoreQueuedAnims: false)
             && idAlignedEntity::IsCurAnimDone(
                  this: this->thirdPersonLegs,
                  numFramesAhead: -1,
                  ignoreQueuedAnims: false) )
      {
        if ( v19 <= valueFloat )
        {
LABEL_140:
          v121 = this;
          if ( v19 >= -valueFloat )
LABEL_135:
            idPlayer::PlayerBehavior_ContextualLadder_SetState(this: v121, state: 4);
          else
LABEL_141:
            idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 6);
        }
        else
        {
LABEL_171:
          v31 = (unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_AtLadderTop(this) == 0;
          v121 = this;
          if ( v31 )
LABEL_134:
            idPlayer::PlayerBehavior_ContextualLadder_SetState(this: v121, state: 8);
          else
LABEL_158:
            idPlayer::PlayerBehavior_ContextualLadder_SetState(this: v121, state: 15);
        }
      }
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_SLIDE_DOWN_LEFT:
      this->behaviors.contextualLadder.blockClimpOffAtTop = false;
      if ( v19 <= valueFloat || (unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_AtCeiling(this) != 0 )
      {
        if ( v19 >= -v15 )
        {
          v124 = this;
          if ( v19 >= -valueFloat )
            goto LABEL_184;
          idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 6);
          idSpringCamera::InitDefaultSprings(this: this->springCamera);
        }
      }
      else
      {
        idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 8);
        idSpringCamera::InitDefaultSprings(this: this->springCamera);
      }
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_SLIDE_DOWN_RIGHT:
      this->behaviors.contextualLadder.blockClimpOffAtTop = false;
      if ( v19 <= valueFloat || (unsigned __int8)idPlayer::PlayerBehavior_ContextualLadder_AtCeiling(this) != 0 )
      {
        if ( v19 >= -v15 )
        {
          v124 = this;
          if ( v19 >= -valueFloat )
          {
LABEL_184:
            idPlayer::PlayerBehavior_ContextualLadder_SetState(this: v124, state: 4);
            idSpringCamera::InitDefaultSprings(this: this->springCamera);
          }
          else
          {
            idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 7);
            idSpringCamera::InitDefaultSprings(this: this->springCamera);
          }
        }
      }
      else
      {
        idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 9);
        idSpringCamera::InitDefaultSprings(this: this->springCamera);
      }
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_DISMOUNT_GROUND:
      goto LABEL_193;
    case CONTEXTUAL_LADDER_STATE_DISMOUNT_MID:
      if ( idAlignedEntity::IsCurAnimDone(this: this->thirdPersonHands, numFramesAhead: -1, ignoreQueuedAnims: false)
        && idAlignedEntity::IsCurAnimDone(this: this->thirdPersonLegs, numFramesAhead: -1, ignoreQueuedAnims: false) )
      {
        idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 14);
      }
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_DISMOUNT_MID_PUSH:
      idPlayer::PlayerBehavior_ContextualLadder_EndLadder(this);
      p_ladderClipQuery = &this->behaviors.contextualLadder.ladderClipQuery;
      p_clip = &clientGame->clip;
      if ( (unsigned __int8)idClip::QueryIsValid(
                              this: &clientGame->clip,
                              clipQuery: &this->behaviors.contextualLadder.ladderClipQuery) != 0 )
      {
        index = p_ladderClipQuery->index;
        p_ladderClipQuery->index = v4;
        LODWORD(v160.x) = p_clip;
        if ( idCollisionModelManager::GetContentsResult(
               this: collisionModelManager,
               result: &v170,
               query: &p_clip->collisionQueries[index & 0xFFF].query,
               peek: false)
          && v170.c.type == CONTACT_NONE )
        {
          if ( this->behaviors.contextualLadder.dismountType == CONTEXTUAL_LADDER_DISMOUNT_TYPE_LEFT )
          {
            v128 = &vec3_up;
          }
          else
          {
            v128 = &v161;
            v161.x = -vec3_up.x;
            v161.z = -vec3_up.z;
            v161.y = -vec3_up.y;
          }
          z = v128->z;
          y = v128->y;
          v131 = this->behaviors.contextualLadder.ladderNormal.x;
          v132 = this->behaviors.contextualLadder.ladderNormal.y;
          v133 = (float)(v128->x * this->behaviors.contextualLadder.ladderNormal.y);
          v134 = (float)(v128->y * this->behaviors.contextualLadder.ladderNormal.z);
          v160.y = (float)(v128->x * this->behaviors.contextualLadder.ladderNormal.z)
                 - (float)(this->behaviors.contextualLadder.ladderNormal.x * v128->z);
          v160.z = (float)((float)v131 * (float)y) - (float)v133;
          v160.x = (float)((float)z * (float)v132) - (float)v134;
          idVec3::NormalizeFast(this: &v160);
          v135 = idPlayer::GetPhysicsObj(this);
          v164[2] = v160.z * pb_clad_LookDismountVel.valueFloat;
          v164[1] = v160.y * pb_clad_LookDismountVel.valueFloat;
          v164[0] = v160.x * pb_clad_LookDismountVel.valueFloat;
          (*(void (__fastcall **)(int, float *, _DWORD))(*(_DWORD *)v135 + 80))(a1: v135, a2: v164, a3: 0);
          LOBYTE(v4) = 1;
        }
      }
      if ( (_BYTE)v4 == 0 )
      {
        v136 = idPlayer::GetPhysicsObj(this);
        v137 = this->behaviors.contextualLadder.ladderNormal.y;
        v138 = this->behaviors.contextualLadder.ladderNormal.x;
        v165[2] = this->behaviors.contextualLadder.ladderNormal.z * pb_clad_DismountMidVel.valueFloat;
        v165[1] = (float)v137 * pb_clad_DismountMidVel.valueFloat;
        v165[0] = (float)v138 * pb_clad_DismountMidVel.valueFloat;
        (*(void (__fastcall **)(int, float *, _DWORD))(*(_DWORD *)v136 + 80))(a1: v136, a2: v165, a3: 0);
      }
      idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 0);
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_DISMOUNT_TOP:
      if ( idAlignedEntity::IsCurAnimDone(this: this->thirdPersonHands, numFramesAhead: -1, ignoreQueuedAnims: false)
        && idAlignedEntity::IsCurAnimDone(this: this->thirdPersonLegs, numFramesAhead: -1, ignoreQueuedAnims: false) )
      {
LABEL_193:
        idPlayer::PlayerBehavior_ContextualLadder_EndLadder(this);
        idPlayer::PlayerBehavior_ContextualLadder_SetState(this, state: 0);
      }
      goto LABEL_209;
    case CONTEXTUAL_LADDER_STATE_DEBUG_TEST_ANIM:
      if ( idAlignedEntity::IsCurAnimDone(this: this->thirdPersonHands, numFramesAhead: -1, ignoreQueuedAnims: false) )
        idAlignedEntity::IsCurAnimDone(this: this->thirdPersonLegs, numFramesAhead: -1, ignoreQueuedAnims: false);
      goto LABEL_209;
    default:
      goto LABEL_209;
  }
}


// ========================================================================
// __unwind$492213_0
// EA  : 0x82E42940
// RVA : 0x00E42940
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void _unwind_492213_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 672 + 496));
}


// ========================================================================
// __unwind$492214_0
// EA  : 0x82E42968
// RVA : 0x00E42968
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void _unwind_492214_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 672 + 144));
}


// ========================================================================
// `dynamic initializer for 'pb_clad_Enable''
// EA  : 0x8338B748
// RVA : 0x0138B748
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_Enable__()
{
  idCVar::idCVar(
    this: &pb_clad_Enable,
    name: "pb_clad_Enable",
    value: "1",
    flags: 1,
    description: "Enable player contextual ladder behavior",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_Enable__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_ShiftIntoPositionDist''
// EA  : 0x8338B7A0
// RVA : 0x0138B7A0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_ShiftIntoPositionDist__()
{
  idCVar::idCVar(
    this: &pb_clad_ShiftIntoPositionDist,
    name: "pb_clad_ShiftIntoPositionDist",
    value: "7",
    flags: 4,
    description: "Error allowance for shifting into initial position",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_ShiftIntoPositionDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_InitiateMaxAngle''
// EA  : 0x8338B7F8
// RVA : 0x0138B7F8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_InitiateMaxAngle__()
{
  idCVar::idCVar(
    this: &pb_clad_InitiateMaxAngle,
    name: "pb_clad_InitiateMaxAngle",
    value: "45",
    flags: 4,
    description: "Maximum angle in degrees between the ladder normal and the player heading to interact with the ladder",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_InitiateMaxAngle__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_InitiateInputTime''
// EA  : 0x8338B850
// RVA : 0x0138B850
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_InitiateInputTime__()
{
  idCVar::idCVar(
    this: &pb_clad_InitiateInputTime,
    name: "pb_clad_InitiateInputTime",
    value: "50",
    flags: 2,
    description: "How long in ms to attempt interaction with ladder before interaction begins",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_InitiateInputTime__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_ForwardTestDist''
// EA  : 0x8338B8A8
// RVA : 0x0138B8A8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_ForwardTestDist__()
{
  idCVar::idCVar(
    this: &pb_clad_ForwardTestDist,
    name: "pb_clad_ForwardTestDist",
    value: "50",
    flags: 4,
    description: "How far forward to test the world",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_ForwardTestDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_ForwardTestBackupDist''
// EA  : 0x8338B900
// RVA : 0x0138B900
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_ForwardTestBackupDist__()
{
  idCVar::idCVar(
    this: &pb_clad_ForwardTestBackupDist,
    name: "pb_clad_ForwardTestBackupDist",
    value: "5",
    flags: 4,
    description: "How far to back up the forward test rays",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_ForwardTestBackupDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_VerticalTestDist''
// EA  : 0x8338B958
// RVA : 0x0138B958
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_VerticalTestDist__()
{
  idCVar::idCVar(
    this: &pb_clad_VerticalTestDist,
    name: "pb_clad_VerticalTestDist",
    value: "150",
    flags: 4,
    description: "How far up or down to test for the ladder top and bottom",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_VerticalTestDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_SideTestDist''
// EA  : 0x8338B9B0
// RVA : 0x0138B9B0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_SideTestDist__()
{
  idCVar::idCVar(
    this: &pb_clad_SideTestDist,
    name: "pb_clad_SideTestDist",
    value: "50",
    flags: 4,
    description: "How far sideways or up to test for a ladder",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_SideTestDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_RayTestDepth''
// EA  : 0x8338BA08
// RVA : 0x0138BA08
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_RayTestDepth__()
{
  idCVar::idCVar(
    this: &pb_clad_RayTestDepth,
    name: "pb_clad_RayTestDepth",
    value: "1",
    flags: 4,
    description: "How far inside a blocking surface to test",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_RayTestDepth__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_AnimBlendFrames''
// EA  : 0x8338BA60
// RVA : 0x0138BA60
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_AnimBlendFrames__()
{
  idCVar::idCVar(
    this: &pb_clad_AnimBlendFrames,
    name: "pb_clad_AnimBlendFrames",
    value: "5",
    flags: 2,
    description: "Animation blend frames",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_AnimBlendFrames__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_MinLadderWidth''
// EA  : 0x8338BAB8
// RVA : 0x0138BAB8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_MinLadderWidth__()
{
  idCVar::idCVar(
    this: &pb_clad_MinLadderWidth,
    name: "pb_clad_MinLadderWidth",
    value: "15",
    flags: 4,
    description: "Minimum width to allow a sides of ladder brushes to be ignored",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_MinLadderWidth__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_Debug''
// EA  : 0x8338BB10
// RVA : 0x0138BB10
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_Debug__()
{
  idCVar::idCVar(
    this: &pb_clad_Debug,
    name: "pb_clad_Debug",
    value: "0",
    flags: 1,
    description: "Debug player contextual ladder behavior",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_Debug__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_DebugTraceStates''
// EA  : 0x8338BB68
// RVA : 0x0138BB68
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_DebugTraceStates__()
{
  idCVar::idCVar(
    this: &pb_clad_DebugTraceStates,
    name: "pb_clad_DebugTraceStates",
    value: "0",
    flags: 1,
    description: "Trace the ladder states",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_DebugTraceStates__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_DebugNoQueryUpdate''
// EA  : 0x8338BBC0
// RVA : 0x0138BBC0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_DebugNoQueryUpdate__()
{
  idCVar::idCVar(
    this: &pb_clad_DebugNoQueryUpdate,
    name: "pb_clad_DebugNoQueryUpdate",
    value: "0",
    flags: 1,
    description: "Update the query or not",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_DebugNoQueryUpdate__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_InputDeadZone''
// EA  : 0x8338BC18
// RVA : 0x0138BC18
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_InputDeadZone__()
{
  idCVar::idCVar(
    this: &pb_clad_InputDeadZone,
    name: "pb_clad_InputDeadZone",
    value: "0.1",
    flags: 4,
    description: "Dead zone for ladder input",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_InputDeadZone__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_InputSlideThreshold''
// EA  : 0x8338BC70
// RVA : 0x0138BC70
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_InputSlideThreshold__()
{
  idCVar::idCVar(
    this: &pb_clad_InputSlideThreshold,
    name: "pb_clad_InputSlideThreshold",
    value: "0.5",
    flags: 4,
    description: "Input required to initiate slide behavior",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_InputSlideThreshold__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_OutputDeltaMove''
// EA  : 0x8338BCC8
// RVA : 0x0138BCC8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_OutputDeltaMove__()
{
  idCVar::idCVar(
    this: &pb_clad_OutputDeltaMove,
    name: "pb_clad_OutputDeltaMove",
    value: "0",
    flags: 2,
    description: "How many delta moves to output",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_OutputDeltaMove__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_OutputDeltaZ''
// EA  : 0x8338BD20
// RVA : 0x0138BD20
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_OutputDeltaZ__()
{
  idCVar::idCVar(
    this: &pb_clad_OutputDeltaZ,
    name: "pb_clad_OutputDeltaZ",
    value: "0",
    flags: 2,
    description: "Same as output delta move, except only z info is reported",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_OutputDeltaZ__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_AtBottomDist''
// EA  : 0x8338BD78
// RVA : 0x0138BD78
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_AtBottomDist__()
{
  idCVar::idCVar(
    this: &pb_clad_AtBottomDist,
    name: "pb_clad_AtBottomDist",
    value: "25",
    flags: 4,
    description: "How far above the bottom of the ladder to consider player 'at bottom'",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_AtBottomDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_AtCeilingDist''
// EA  : 0x8338BDD0
// RVA : 0x0138BDD0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_AtCeilingDist__()
{
  idCVar::idCVar(
    this: &pb_clad_AtCeilingDist,
    name: "pb_clad_AtCeilingDist",
    value: "140",
    flags: 4,
    description: "How far below the 'ceiling' the player's physics object is allowed to be",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_AtCeilingDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_AtTopDist''
// EA  : 0x8338BE28
// RVA : 0x0138BE28
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_AtTopDist__()
{
  idCVar::idCVar(
    this: &pb_clad_AtTopDist,
    name: "pb_clad_AtTopDist",
    value: "110",
    flags: 4,
    description: "How far below the top of the ladder to consider player 'at top'",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_AtTopDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_AlignHandsToTopDist''
// EA  : 0x8338BE80
// RVA : 0x0138BE80
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_AlignHandsToTopDist__()
{
  idCVar::idCVar(
    this: &pb_clad_AlignHandsToTopDist,
    name: "pb_clad_AlignHandsAtTopDist",
    value: "64",
    flags: 4,
    description: "How far below the top of the ladder to align the hands model",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_AlignHandsToTopDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_AlignPhysicsToTopDist''
// EA  : 0x8338BED8
// RVA : 0x0138BED8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_AlignPhysicsToTopDist__()
{
  idCVar::idCVar(
    this: &pb_clad_AlignPhysicsToTopDist,
    name: "pb_clad_AlignPhysicsAtTopDist",
    value: "60",
    flags: 4,
    description: "How far below the top of the ladder to align the player physics object",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_AlignPhysicsToTopDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_DismountMidVel''
// EA  : 0x8338BF30
// RVA : 0x0138BF30
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_DismountMidVel__()
{
  idCVar::idCVar(
    this: &pb_clad_DismountMidVel,
    name: "pb_clad_DismountMidVel",
    value: "100",
    flags: 4,
    description: "How much velocity to apply to the player to push away from the ladder",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_DismountMidVel__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_LookDismountVel''
// EA  : 0x8338BF88
// RVA : 0x0138BF88
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_LookDismountVel__()
{
  idCVar::idCVar(
    this: &pb_clad_LookDismountVel,
    name: "pb_clad_LookDismountVel",
    value: "200",
    flags: 4,
    description: "How much velocity to apply to the player to push away from the ladder",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_LookDismountVel__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_MountBotOffsetX''
// EA  : 0x8338BFE0
// RVA : 0x0138BFE0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_MountBotOffsetX__()
{
  idCVar::idCVar(
    this: &pb_clad_MountBotOffsetX,
    name: "pb_clad_MountBotOffsetX",
    value: "30",
    flags: 4,
    description: "X offset for top mount",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_MountBotOffsetX__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_MountBotOffsetY''
// EA  : 0x8338C038
// RVA : 0x0138C038
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_MountBotOffsetY__()
{
  idCVar::idCVar(
    this: &pb_clad_MountBotOffsetY,
    name: "pb_clad_MountBotOffsetY",
    value: "0",
    flags: 4,
    description: "Y offset for top mount",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_MountBotOffsetY__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_MountBotOffsetZ''
// EA  : 0x8338C090
// RVA : 0x0138C090
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_MountBotOffsetZ__()
{
  idCVar::idCVar(
    this: &pb_clad_MountBotOffsetZ,
    name: "pb_clad_MountBotOffsetZ",
    value: "5",
    flags: 4,
    description: "Z offset for top mount",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_MountBotOffsetZ__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_MountMidOffsetX''
// EA  : 0x8338C0E8
// RVA : 0x0138C0E8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_MountMidOffsetX__()
{
  idCVar::idCVar(
    this: &pb_clad_MountMidOffsetX,
    name: "pb_clad_MountMidOffsetX",
    value: "30",
    flags: 4,
    description: "X offset for top mount",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_MountMidOffsetX__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_MountMidOffsetY''
// EA  : 0x8338C140
// RVA : 0x0138C140
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_MountMidOffsetY__()
{
  idCVar::idCVar(
    this: &pb_clad_MountMidOffsetY,
    name: "pb_clad_MountMidOffsetY",
    value: "0",
    flags: 4,
    description: "Y offset for top mount",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_MountMidOffsetY__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_MountMidOffsetZ''
// EA  : 0x8338C198
// RVA : 0x0138C198
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_MountMidOffsetZ__()
{
  idCVar::idCVar(
    this: &pb_clad_MountMidOffsetZ,
    name: "pb_clad_MountMidOffsetZ",
    value: "5",
    flags: 4,
    description: "Z offset for top mount",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_MountMidOffsetZ__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_MountTopOffsetX''
// EA  : 0x8338C1F0
// RVA : 0x0138C1F0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_MountTopOffsetX__()
{
  idCVar::idCVar(
    this: &pb_clad_MountTopOffsetX,
    name: "pb_clad_MountTopOffsetX",
    value: "30",
    flags: 4,
    description: "X offset for top mount",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_MountTopOffsetX__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_MountTopOffsetY''
// EA  : 0x8338C248
// RVA : 0x0138C248
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_MountTopOffsetY__()
{
  idCVar::idCVar(
    this: &pb_clad_MountTopOffsetY,
    name: "pb_clad_MountTopOffsetY",
    value: "0",
    flags: 4,
    description: "Y offset for top mount",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_MountTopOffsetY__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_MountTopOffsetZ''
// EA  : 0x8338C2A0
// RVA : 0x0138C2A0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_MountTopOffsetZ__()
{
  idCVar::idCVar(
    this: &pb_clad_MountTopOffsetZ,
    name: "pb_clad_MountTopOffsetZ",
    value: "-90",
    flags: 4,
    description: "Z offset for top mount",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_MountTopOffsetZ__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_MaxDeltaPitch''
// EA  : 0x8338C2F8
// RVA : 0x0138C2F8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_MaxDeltaPitch__()
{
  idCVar::idCVar(
    this: &pb_clad_MaxDeltaPitch,
    name: "pb_clad_MaxDeltaPitch",
    value: "70",
    flags: 4,
    description: "Maximum delta pitch, relative to ladder normal",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_MaxDeltaPitch__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_MaxDeltaYaw''
// EA  : 0x8338C350
// RVA : 0x0138C350
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_MaxDeltaYaw__()
{
  idCVar::idCVar(
    this: &pb_clad_MaxDeltaYaw,
    name: "pb_clad_MaxDeltaYaw",
    value: "80",
    flags: 4,
    description: "Maximum delta yaw, relative to ladder normal",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_MaxDeltaYaw__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_ConstrainedViewAnglesRate''
// EA  : 0x8338C3A8
// RVA : 0x0138C3A8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_ConstrainedViewAnglesRate__()
{
  idCVar::idCVar(
    this: &pb_clad_ConstrainedViewAnglesRate,
    name: "pb_clad_ConstrainedViewAnglesRate",
    value: "40",
    flags: 4,
    description: "Rate for the entry into the constrained view range, if restriction is necessary (degs/sec)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_ConstrainedViewAnglesRate__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_EnableBodyRotation''
// EA  : 0x8338C400
// RVA : 0x0138C400
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_EnableBodyRotation__()
{
  idCVar::idCVar(
    this: &pb_clad_EnableBodyRotation,
    name: "pb_clad_EnableBodyRotation",
    value: "1",
    flags: 1,
    description: "Enables additive anims to simulate body rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_EnableBodyRotation__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_AveragedBodyRotationK''
// EA  : 0x8338C458
// RVA : 0x0138C458
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_AveragedBodyRotationK__()
{
  idCVar::idCVar(
    this: &pb_clad_AveragedBodyRotationK,
    name: "pb_clad_AveragedBodyRotationK",
    value: "300.0",
    flags: 4,
    description: "Spring constant for averaging the body rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_AveragedBodyRotationK__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_NoRemountTimeMS''
// EA  : 0x8338C4B0
// RVA : 0x0138C4B0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_NoRemountTimeMS__()
{
  idCVar::idCVar(
    this: &pb_clad_NoRemountTimeMS,
    name: "pb_clad_NoRemountTimeMS",
    value: "500",
    flags: 2,
    description: "This many MS after dismounting before player can mount again",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_NoRemountTimeMS__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_SprintSpeedScale''
// EA  : 0x8338C508
// RVA : 0x0138C508
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_SprintSpeedScale__()
{
  idCVar::idCVar(
    this: &pb_clad_SprintSpeedScale,
    name: "pb_clad_SprintSpeedScale",
    value: "1.75",
    flags: 4,
    description: "Speed scale allowed while sprinting",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_SprintSpeedScale__);
}


// ========================================================================
// `dynamic initializer for 'pb_clad_SpeedScaleSpringK''
// EA  : 0x8338C560
// RVA : 0x0138C560
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_clad_SpeedScaleSpringK__()
{
  idCVar::idCVar(
    this: &pb_clad_SpeedScaleSpringK,
    name: "pb_clad_SpeedScaleSpringK",
    value: "150.0",
    flags: 4,
    description: "Spring constant for speed spring scale",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_clad_SpeedScaleSpringK__);
}


// ========================================================================
// `dynamic initializer for 'prevForward''
// EA  : 0x8338C5B8
// RVA : 0x0138C5B8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void _dynamic_initializer_for__prevForward__()
{
  prevForward = vec3_origin;
}


// ========================================================================
// `dynamic initializer for 'prevRight''
// EA  : 0x8338C5E8
// RVA : 0x0138C5E8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void _dynamic_initializer_for__prevRight__()
{
  prevRight = vec3_origin;
}


// ========================================================================
// `dynamic initializer for 'prevUp''
// EA  : 0x8338C618
// RVA : 0x0138C618
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void _dynamic_initializer_for__prevUp__()
{
  prevUp = vec3_origin;
}


// ========================================================================
// `dynamic initializer for 'prevPos''
// EA  : 0x8338C648
// RVA : 0x0138C648
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualladder.cpp
// ========================================================================

void _dynamic_initializer_for__prevPos__()
{
  prevPos = vec3_origin;
}

