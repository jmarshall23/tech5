
// ========================================================================
// ?PlayerBehavior_WallClimb_IsInWallClimb@idPlayer@@QBA_NXZ
// EA  : 0x82E4A8D0
// RVA : 0x00E4A8D0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

BOOL __fastcall idPlayer::PlayerBehavior_WallClimb_IsInWallClimb(idPlayer *this)
{
  return this->behaviors.wallClimb.state != WALLCLIMB_STATE_NONE;
}


// ========================================================================
// ?PlayerBehavior_WallClimb_Startup@idPlayer@@QAAXXZ
// EA  : 0x82E4A8E0
// RVA : 0x00E4A8E0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_WallClimb_Startup(idPlayer *this)
{
  idAlignedEntity *thirdPersonLegs; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v4; // r31
  idAlignedEntity *thirdPersonHands; // r3
  idTreeAnimator *v6; // r3
  idTreeAnimator *v7; // r31
  unsigned __int16 v8; // [sp+50h] [-30h] BYREF
  unsigned __int16 v9; // [sp+52h] [-2Eh] BYREF
  unsigned __int16 v10; // [sp+54h] [-2Ch] BYREF
  char v11; // [sp+56h] [-2Ah] BYREF
  char v12; // [sp+58h] [-28h] BYREF
  char v13; // [sp+5Ah] [-26h] BYREF
  char v14; // [sp+5Ch] [-24h] BYREF
  char v15; // [sp+5Eh] [-22h] BYREF
  char v16; // [sp+60h] [-20h] BYREF
  char v17; // [sp+62h] [-1Eh] BYREF
  char v18; // [sp+64h] [-1Ch] BYREF

  if ( gameLocal->FindEntityUsingClass(this: gameLocal, a2: 0, a3: "idWallClimb") != nullptr )
  {
    thirdPersonLegs = this->thirdPersonLegs;
    this->behaviors.wallClimb.bEnabled = true;
    if ( thirdPersonLegs != nullptr )
    {
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: thirdPersonLegs);
      v4 = TreeAnimatorFromPresentable;
      if ( TreeAnimatorFromPresentable != nullptr )
      {
        idDeclMD6::StrongLoadAlias(
          this: (idDeclMD6 *)&v8,
          result: TreeAnimatorFromPresentable->decl,
          aliasName: "shimmy/torsoTwist_center");
        this->behaviors.wallClimb.bodyRotationAnimAliasHandles[0].value = v8;
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v9, result: v4->decl, aliasName: "shimmy/torsoTwist_left");
        this->behaviors.wallClimb.bodyRotationAnimAliasHandles[1].value = v9;
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v10, result: v4->decl, aliasName: "shimmy/torsoTwist_right");
        this->behaviors.wallClimb.bodyRotationAnimAliasHandles[2].value = v10;
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v11, result: v4->decl, aliasName: "grapplingclimb/legs_mh");
        idDeclMD6::StrongLoadAlias(
          this: (idDeclMD6 *)&v12,
          result: v4->decl,
          aliasName: "grapplingclimb/legs_climb_forward");
        idDeclMD6::StrongLoadAlias(
          this: (idDeclMD6 *)&v13,
          result: v4->decl,
          aliasName: "grapplingclimb/legs_climb_downward");
        idDeclMD6::StrongLoadAlias(
          this: (idDeclMD6 *)&v14,
          result: v4->decl,
          aliasName: "grapplingclimb/legsexit_ledge_window");
      }
    }
    thirdPersonHands = this->thirdPersonHands;
    if ( thirdPersonHands != nullptr )
    {
      v6 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: thirdPersonHands);
      v7 = v6;
      if ( v6 != nullptr )
      {
        idDeclMD6::StrongLoadAlias(
          this: (idDeclMD6 *)&v15,
          result: v6->decl,
          aliasName: "grapplingclimb/playerexit_ledge_window");
        idDeclMD6::StrongLoadAlias(
          this: (idDeclMD6 *)&v16,
          result: v7->decl,
          aliasName: "grapplingclimb/player_climb_forward");
        idDeclMD6::StrongLoadAlias(
          this: (idDeclMD6 *)&v17,
          result: v7->decl,
          aliasName: "grapplingclimb/player_climb_downward");
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v18, result: v7->decl, aliasName: "grapplingclimb/player_mh");
      }
    }
  }
  else
  {
    this->behaviors.wallClimb.bEnabled = false;
  }
}


// ========================================================================
// ?PlayerBehavior_WallClimb_HandleAdditiveAnims@idPlayer@@QAAXXZ
// EA  : 0x82E4AA80
// RVA : 0x00E4AA80
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_WallClimb_HandleAdditiveAnims(idPlayer *this)
{
  if ( this->behaviors.wallClimb.state != WALLCLIMB_STATE_NONE )
  {
    idAlignedEntity::StopAdditiveAnim(this: this->thirdPersonLegs);
    idAlignedEntity::SetAdditiveAnimAlpha(this: this->thirdPersonLegs, alpha: 0.0, alphaRate: 10.0);
  }
}


// ========================================================================
// ?PlayerBehavior_WallClimb_EndWallClimb@idPlayer@@QAAXXZ
// EA  : 0x82E4AAE0
// RVA : 0x00E4AAE0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_WallClimb_EndWallClimb(idPlayer *this)
{
  idAnimator_Base::SetAlpha(this: &this->thirdPersonLegs->additiveSyncedAnimator, alpha: 0.0);
  idPlayer::idPlayerBehaviorWallClimb::Clear(this: &this->behaviors.wallClimb);
}


// ========================================================================
// ?PlayerBehavior_WallClimb_HandleMovement@idPlayer@@QAAXXZ
// EA  : 0x82E4AB28
// RVA : 0x00E4AB28
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_WallClimb_HandleMovement(idPlayer *this)
{
  idPlayer::idPlayerBehaviorWallClimb *p_wallClimb; // r31
  double v3; // fp31
  double v4; // fp30
  idAlignedEntity *thirdPersonLegs; // r3
  idVec3 *v6; // r10
  float *p_z; // r11
  int i; // ctr
  idPresentable *presentable; // r3
  idPresentable *v10; // r3
  float *v11; // r3
  double v12; // fp13
  double v13; // fp12
  double v14; // fp11
  double v15; // fp10
  double v16; // fp9
  double v17; // fp8
  double v18; // fp7
  double v19; // fp6
  idQuat *v20; // r3
  idQuat *v21; // r3
  double v22; // fp1
  double v23; // fp1
  idQuat v24; // [sp+50h] [-130h] BYREF
  idMat3 v25; // [sp+60h] [-120h] BYREF
  idVec3 v26[2]; // [sp+88h] [-F8h] BYREF
  idQuat v27; // [sp+A0h] [-E0h] BYREF
  idMat3 v28; // [sp+B0h] [-D0h] BYREF
  idMat3 v29; // [sp+F0h] [-90h] BYREF
  idMat3 v30; // [sp+120h] [-60h] BYREF

  if ( this->behaviors.wallClimb.state != WALLCLIMB_STATE_NONE )
  {
    p_wallClimb = &this->behaviors.wallClimb;
    if ( (unsigned int)(this->behaviors.wallClimb.state - 1) > 6
      || this->behaviors.wallClimb.state == WALLCLIMB_STATE_IDLE
      || this->behaviors.wallClimb.state == WALLCLIMB_STATE_CLIMB_UP
      || this->behaviors.wallClimb.state == WALLCLIMB_STATE_CLIMB_DOWN )
    {
      v3 = 1.0;
      v4 = 0.0;
    }
    else if ( this->behaviors.wallClimb.state == WALLCLIMB_STATE_DISMOUNT_UP
           || this->behaviors.wallClimb.state == WALLCLIMB_STATE_DISMOUNT_FALL
           || this->behaviors.wallClimb.state == WALLCLIMB_STATE_MOUNT )
    {
      v3 = 1.0;
      v4 = 1.0;
    }
    else
    {
      v3 = 0.0;
      v4 = 0.0;
    }
    thirdPersonLegs = this->thirdPersonLegs;
    v24 = quat_identity;
    if ( (unsigned __int8)idAnimatedEntity::GetWorldSpaceJointTransform(
                            this: thirdPersonLegs,
                            jointName: "origin",
                            offset: v26,
                            axis: &v29) != 0 )
    {
      v6 = &v28.mat[1];
      p_z = &this->springCamera->viewOrigin.z;
      for ( i = 9; i != 0; --i )
      {
        ++p_z;
        v6 = (idVec3 *)((char *)v6 + 4);
        v6->x = *p_z;
      }
      presentable = this->presentable;
      if ( presentable != nullptr )
        presentable->GetPlayerInterface_2(this: presentable);
      v10 = this->presentable;
      if ( v10 != nullptr )
        v11 = (float *)v10->GetPlayerInterface_2(this: v10);
      else
        v11 = nullptr;
      v12 = v11[11641];
      v13 = v11[11638];
      v14 = v11[11643];
      v15 = v11[11640];
      v16 = v11[11637];
      v17 = v11[11642];
      v18 = v11[11639];
      v19 = v11[11636];
      v25.mat[2].z = v11[11644];
      v25.mat[2].y = v12;
      v25.mat[2].x = v13;
      v25.mat[1].z = v14;
      v25.mat[1].y = v15;
      v25.mat[1].x = v16;
      v25.mat[0].z = v17;
      v25.mat[0].y = v18;
      v25.mat[0].x = v19;
      v20 = (idQuat *)idMat3::operator*(this: &v30, result: (idMat3 *)&v28.mat[1].y, a: &v25);
      v21 = idMat3::ToQuat(this: &v28, result: v20);
      v24.x = v21->x;
      v24.y = v21->y;
      v24.z = v21->z;
      v24.w = v21->w;
    }
    p_wallClimb->extraWorldTranslationBlend.p0.x = v3;
    v22 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
    idSpring<idVec1>::Update(this: &p_wallClimb->extraWorldTranslationBlend, dt: v22);
    p_wallClimb->extraWorldRotationBlend.p0.x = v4;
    v23 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
    idSpring<idVec1>::Update(this: &p_wallClimb->extraWorldRotationBlend, dt: v23);
    idQuat::Slerp(this: &v27, from: &quat_identity, to: &v24, t: p_wallClimb->extraWorldRotationBlend.p1.x);
  }
}


// ========================================================================
// ?PlayerBehavior_WallClimb_StartWallClimb@idPlayer@@QAAXXZ
// EA  : 0x82E4ADC0
// RVA : 0x00E4ADC0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_WallClimb_StartWallClimb(idPlayer *this)
{
  idPlayer::idPlayerBehaviorWallClimb *p_wallClimb; // r30

  p_wallClimb = &this->behaviors.wallClimb;
  idSpringCamera::InitDefaultSprings(this: this->springCamera);
  idSpringCamera::InitSprings(this: this->springCamera, k: pb_cs_CameraSpringK.valueFloat);
  idAlignedEntity::AttachCamera(
    this: this->thirdPersonLegs,
    jointName: "camera",
    durationMode: DURATION_ALWAYS,
    lookMode: LOOK_ADD_DELTAANGLES,
    blendMode: BLEND_SMOOTH_SNAP_SMOOTH,
    blendDurationMS: -1,
    viewConeDeg: 0.0,
    autoCenterK: 1.0);
  this->springCamera->constraintConeDegs = pb_wc_MaxConeCamera.valueFloat;
  idSpring<idVec1>::SetConstants(
    this: &p_wallClimb->averagedBodyRotationT,
    _k: pb_cs_AveragedBodyRotationK.valueFloat,
    _c: -1.0);
  idSpring<idVec1>::SetConstants(
    this: &p_wallClimb->extraWorldTranslationBlend,
    _k: pb_cs_ExtraWorldOffsetBlendK.valueFloat,
    _c: -1.0);
  idSpring<idVec1>::SetConstants(
    this: &p_wallClimb->sideWaysTranslationBlend,
    _k: pb_wc_SideWaysBlendK.valueFloat,
    _c: -1.0);
  idSpring<idVec1>::SetConstants(
    this: &p_wallClimb->extraWorldRotationBlend,
    _k: pb_cs_ExtraWorldOffsetBlendK.valueFloat,
    _c: -1.0);
  idSpring<idVec1>::SetConstants(
    this: &p_wallClimb->sideWaysTranslationBlend,
    _k: pb_wc_SideWaysBlendK.valueFloat,
    _c: -1.0);
}


// ========================================================================
// ?PlayerBehavior_WallClimb_PostDismount@idPlayer@@QAAXXZ
// EA  : 0x82E4AEB8
// RVA : 0x00E4AEB8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPlayer::PlayerBehavior_WallClimb_PostDismount(idPlayer *this)
{
  int value; // r9
  idGameLocal *v3; // r11
  idWallClimb *v4; // r3
  idWallClimb *v5; // r3
  idList<idEntityPtr<idEntity>,5> *p_climbOffTriggers; // r29
  int v7; // r26
  int v8; // r30
  int v9; // r9
  idEntity *v10; // r3
  idEntity *v11; // r31
  idEventArg *v12; // r3
  __int64 v13; // r10
  __int128 v14; // r7 OVERLAPPED
  int v15; // r8
  __int64 v16; // [sp+8h] [-A8h]
  __int64 v17; // [sp+10h] [-A0h]
  __int64 v18; // [sp+18h] [-98h]
  __int64 v19; // [sp+20h] [-90h]
  __int64 v20; // [sp+28h] [-88h]
  __int64 v21; // [sp+30h] [-80h]
  __int64 v22; // [sp+38h] [-78h]
  __int64 v23; // [sp+40h] [-70h]
  idEventArg v24[4]; // [sp+50h] [-60h] BYREF

  idAlignedEntity::StopAnim(this: this->thirdPersonLegs);
  idPlayer::ShowHands(this);
  idSpringCamera::BlendOut(this: this->springCamera, instantBlend: false);
  idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
    this,
    constrain: false,
    heading: nullptr,
    maxDeltaPitch: 0.0,
    maxDeltaYaw: 0.0,
    rate: 0.0);
  idPlayer::PlayerBehavior_Shared_AutoApplyThirdPersonLegsAnimDeltas(this, applyToPlayer: false, clip: false);
  value = this->behaviors.wallClimb.wallClimb.spawnId.value;
  v3 = gameLocal;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v4 = (idWallClimb *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v5 = idWallClimb::CastTo(c: v4);
    v3 = gameLocal;
  }
  else
  {
    v5 = nullptr;
  }
  p_climbOffTriggers = &v5->climbOffTriggers;
  v7 = 0;
  if ( v5->climbOffTriggers.num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = p_climbOffTriggers->list[v8].spawnId.value;
      if ( v3->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 )
      {
        v10 = v3->entities.ptr[v9 & 0x1FFF];
        if ( v10 != nullptr )
        {
          v11 = idEntity::CastTo(c: v10);
          if ( v11 != nullptr )
          {
            v12 = idEventArg::idEventArg(this: v24, data: this);
            LODWORD(v13) = LODWORD(v12->value.q[3]);
            *(_QWORD *)((char *)&v14 + 4) = *(_QWORD *)&v12->type;
            v15 = __ROL4__(v13, 32);
            *((_QWORD *)&v14 + 1) = *(_QWORD *)&v12->value.q[1];
            idEventReceiver::PostEventMS(
              this: v11,
              ev: &EV_Activate,
              arg1: *(__int64 *)((char *)&v14 + 4),
              a4: *(__int64 *)((char *)&v14 - 4),
              a5: v13,
              a6: v16,
              a7: v17,
              a8: v18,
              a9: v19,
              a10: v20,
              a11: v21,
              a12: v22,
              a13: v23);
          }
          v3 = gameLocal;
        }
      }
      ++v7;
      ++v8;
    }
    while ( v7 < p_climbOffTriggers->num );
  }
}


// ========================================================================
// ?PlayerBehavior_WallClimb_AlignThirdPersonModels@idPlayer@@QAAXPBVidVec3@@@Z
// EA  : 0x82E4B018
// RVA : 0x00E4B018
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_WallClimb_AlignThirdPersonModels(
        idPlayer *this,
        const idVec3 *startPosOverride)
{
  int value; // r10
  idPlayer::idPlayerBehaviorWallClimb *p_wallClimb; // r28
  idWallClimb *v6; // r3
  idWallClimb *v7; // r3
  idPhysics *Physics; // r3
  float *v9; // r3
  float v10; // r7
  float v11; // r8
  double v12; // fp30
  double v13; // fp29
  double v14; // fp28
  double v15; // fp26
  double v16; // fp25
  double v17; // fp27
  double z; // fp12
  idPhysics *v19; // r3
  int v20; // r3
  int v21; // r11
  int v22; // r4
  float v23; // r9
  float v24; // r6
  double valueFloat; // fp24
  idVec3 *v26; // r5
  idWallClimb *v27; // r3
  idWallClimb *v28; // r3
  double v29; // fp13
  float v30; // [sp+50h] [-B0h] BYREF
  float v31; // [sp+54h] [-ACh]
  float v32; // [sp+58h] [-A8h]
  float v33; // [sp+60h] [-A0h]
  float v34; // [sp+64h] [-9Ch]
  float v35; // [sp+68h] [-98h]
  idMat3 v36[2]; // [sp+70h] [-90h] BYREF

  value = this->behaviors.wallClimb.wallClimb.spawnId.value;
  p_wallClimb = &this->behaviors.wallClimb;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idWallClimb *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idWallClimb::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v7);
  v9 = (float *)Physics->GetAxis(this: Physics, a2: 0);
  v10 = v9[1];
  v11 = v9[2];
  v33 = *v9;
  v12 = v33;
  v34 = v10;
  v13 = v10;
  v35 = v11;
  v14 = v11;
  v15 = (float)((float)(v11 * (float)0.0) - v10);
  v16 = (float)(v33 - (float)(v11 * (float)0.0));
  v17 = (float)((float)(v10 * (float)0.0) - (float)(v33 * (float)0.0));
  if ( startPosOverride != nullptr )
  {
    p_wallClimb->legsAlignPos.x = startPosOverride->x;
    p_wallClimb->legsAlignPos.y = startPosOverride->y;
    z = startPosOverride->z;
  }
  else
  {
    v19 = idEntity::GetPhysics(this);
    v20 = (int)v19->GetOrigin(this: v19, a2: 0);
    v21 = p_wallClimb->wallClimb.spawnId.value & 0x1FFF;
    v22 = p_wallClimb->wallClimb.spawnId.value >> 13;
    v23 = *(float *)(v20 + 4);
    v24 = *(float *)(v20 + 8);
    v30 = *(float *)v20;
    valueFloat = pb_wc_climbOffDistance.valueFloat;
    v31 = v23;
    v32 = v24;
    v26 = (idVec3 *)gameLocal->spawnIds.ptr[v21];
    if ( v26 == (idVec3 *)v22 && (v27 = (idWallClimb *)gameLocal->entities.ptr[v21]) != nullptr )
      v28 = idWallClimb::CastTo(c: v27);
    else
      v28 = nullptr;
    idWallClimb::GetClosestPoint(this: v28, player: this, climbOffDistance: valueFloat, point: v26, a5: &v30);
    v29 = v31;
    z = v32;
    p_wallClimb->legsAlignPos.x = v30;
    p_wallClimb->legsAlignPos.y = v29;
  }
  p_wallClimb->legsAlignPos.z = z;
  v36[0].mat[0].x = v12;
  v36[0].mat[0].y = v13;
  v36[0].mat[0].z = v14;
  v36[0].mat[1].x = v15;
  v36[0].mat[1].y = v16;
  v36[0].mat[1].z = v17;
  v36[0].mat[2].x = 0.0;
  v36[0].mat[2].y = 0.0;
  v36[0].mat[2].z = 1.0;
  idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsAlignNode(this, origin: &p_wallClimb->legsAlignPos, axis: v36);
  idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsAlignNode(this, origin: &p_wallClimb->legsAlignPos, axis: v36);
  if ( outputDeltaMove_1 != 0 )
    idLib::Printf(
      fmt: "state=%s: legsAlignPos:(%0.2f,%0.2f,%0.2f)\n",
      wcStateNames[p_wallClimb->state],
      p_wallClimb->legsAlignPos.x,
      p_wallClimb->legsAlignPos.y,
      p_wallClimb->legsAlignPos.z);
  if ( outputDeltaZ_1 != 0 )
    idLib::Printf(
      fmt: "state=%s: legsAlignPos.z:(%0.2f)\n",
      (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(p_wallClimb->legsAlignPos.z)),
      p_wallClimb->legsAlignPos.z);
}


// ========================================================================
// ?PlayerBehavior_WallClimb_OrientToSurface@idPlayer@@QAAXXZ
// EA  : 0x82E4B290
// RVA : 0x00E4B290
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_WallClimb_OrientToSurface(idPlayer *this)
{
  int value; // r10
  idWallClimb *v3; // r3
  idWallClimb *v4; // r3
  idPhysics *Physics; // r3
  int v6; // r3
  char v7; // r30
  char v8; // r28
  float v9; // r8
  unsigned __int32 v10; // r11
  float v11; // r7
  int v12; // r27
  int v13; // r9
  int v14; // r5
  double valueFloat; // fp31
  idWallClimb *v16; // r3
  idWallClimb *v17; // r3
  unsigned __int8 v18; // r11
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  float *p_w; // r10
  int v21; // ctr
  float *p_y; // r11
  double v23; // fp29
  double v24; // fp31
  double v25; // fp30
  idAlignedEntity *thirdPersonLegs; // r3
  idPhysics *v27; // r3
  float *v28; // r3
  double v29; // fp2
  double v30; // fp0
  double v31; // fp8
  double v32; // fp3
  idPresentable *presentable; // r3
  const idAngles *v34; // r4
  idPlayer_vtbl *v35; // r30
  idPresentablePlayer *ViewAngles; // r3
  idVec3 v37; // [sp+50h] [-C0h] BYREF
  float v38; // [sp+60h] [-B0h] BYREF
  float v39; // [sp+64h] [-ACh]
  float v40; // [sp+68h] [-A8h]
  idVec3 v41; // [sp+70h] [-A0h] BYREF
  idVec3 v42; // [sp+80h] [-90h] BYREF
  idQuat v43; // [sp+90h] [-80h] BYREF
  idMat3 v44; // [sp+A0h] [-70h] BYREF

  value = this->behaviors.wallClimb.wallClimb.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = (idWallClimb *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v4 = idWallClimb::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v4);
  v6 = (int)Physics->GetAxis(this: Physics, a2: 0);
  v7 = 0;
  v8 = 0;
  v9 = *(float *)(v6 + 4);
  v10 = this->behaviors.wallClimb.state - 1;
  v11 = *(float *)(v6 + 8);
  v38 = *(float *)v6;
  v39 = v9;
  v40 = v11;
  if ( v10 > 4 )
    return;
  if ( v10 == 0 )
  {
    v7 = 1;
    goto LABEL_12;
  }
  if ( v10 == 1 )
  {
    v7 = 1;
    goto LABEL_11;
  }
  if ( v10 - 2 < 2 )
  {
LABEL_11:
    v8 = 1;
LABEL_12:
    v18 = 1;
    goto LABEL_13;
  }
  v18 = 0;
  v7 = 0;
LABEL_13:
  v12 = v18;
  if ( v18 != 0 || v7 != 0 )
  {
    v13 = this->behaviors.wallClimb.wallClimb.spawnId.value;
    v14 = v13 >> 13;
    valueFloat = pb_wc_climbOffDistance.valueFloat;
    if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13
      && (v16 = (idWallClimb *)gameLocal->entities.ptr[v13 & 0x1FFF]) != nullptr )
    {
      v17 = idWallClimb::CastTo(c: v16);
    }
    else
    {
      v17 = nullptr;
    }
    idWallClimb::GetClosestPoint(
      this: v17,
      player: this,
      climbOffDistance: valueFloat,
      point: (idVec3 *)v14,
      a5: &v41.x);
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->thirdPersonLegs);
    idTreeAnimator::GetLastOriginDeltas(this: TreeAnimatorFromPresentable, rot: &v43, trans: &v42);
    p_w = &v43.w;
    v21 = 9;
    p_y = &mat2_identity.mat[1].y;
    v37 = v41;
    do
    {
      *++p_w = *++p_y;
      --v21;
    }
    while ( v21 != 0 );
    v23 = v40;
    v24 = v39;
    v25 = v38;
    if ( v12 != 0 )
    {
      v44.mat[0].x = v38;
      v44.mat[0].y = v39;
      v44.mat[0].z = v40;
      thirdPersonLegs = this->thirdPersonLegs;
      v44.mat[2].x = 0.0;
      v44.mat[2].y = 0.0;
      v44.mat[2].z = 1.0;
      v44.mat[1].x = (float)(v40 * (float)0.0) - v39;
      v44.mat[1].z = (float)(v39 * (float)0.0) - (float)(v38 * (float)0.0);
      v44.mat[1].y = v38 - (float)(v40 * (float)0.0);
      v27 = idEntity::GetPhysics(this: thirdPersonLegs);
      v28 = (float *)v27->GetAxis(this: v27, a2: 0);
      v29 = (float)((float)(v28[2] * v42.x) + (float)((float)(v28[5] * v42.y) + (float)(v28[8] * v42.z)));
      v30 = (float)(v37.y + (float)((float)(v28[1] * v42.x) + (float)((float)(v28[4] * v42.y) + (float)(v28[7] * v42.z))));
      v37.x = (float)((float)(*v28 * v42.x) + (float)((float)(v28[3] * v42.y) + (float)(v28[6] * v42.z))) + v37.x;
      v37.y = v30;
      v37.z = (float)v29 + v37.z;
    }
    if ( v7 != 0 )
      v37.z = v41.z;
    if ( v8 != 0 )
    {
      v31 = (float)(v44.mat[1].z * this->behaviors.wallClimb.sidewaysPosition);
      v32 = (float)((float)(v44.mat[1].y * this->behaviors.wallClimb.sidewaysPosition) + v37.y);
      v37.x = (float)(v44.mat[1].x * this->behaviors.wallClimb.sidewaysPosition) + v37.x;
      v37.y = v32;
      v37.z = (float)v31 + v37.z;
    }
    if ( v12 != 0 || v7 != 0 )
    {
      idAlignedEntity::Align(
        this: this->thirdPersonLegs,
        origin: &v37,
        axis: &v44,
        alignMode: ALIGN_NODE_POS_ALIGN_NODE_AXIS);
      idAlignedEntity::Align(
        this: this->thirdPersonHands,
        origin: &v37,
        axis: &v44,
        alignMode: ALIGN_NODE_POS_ALIGN_NODE_AXIS);
    }
    presentable = this->presentable;
    v37.x = (float)((float)v25 * (float)75.0) + v37.x;
    v37.y = (float)((float)v24 * (float)75.0) + v37.y;
    v37.z = (float)((float)((float)v23 * (float)75.0) + v37.z) - (float)0.25;
    if ( presentable != nullptr )
      v34 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v34 = nullptr;
    v35 = this->__vftable;
    ViewAngles = idPresentablePlayer::GetViewAngles(
                   this: (idPresentablePlayer *)&v38,
                   result: v34,
                   includeWeaponKick: true);
    v35->Teleport(this, a2: &v37, a3: (const idAngles *)ViewAngles);
  }
}


// ========================================================================
// ?PlayerBehavior_WallClimb_DebugHandle@idPlayer@@QAAXXZ
// EA  : 0x82E4B670
// RVA : 0x00E4B670
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_WallClimb_DebugHandle(idPlayer *this)
{
  int value; // r10
  idVec3 *v3; // r5
  double valueFloat; // fp31
  idWallClimb *v5; // r3
  idWallClimb *v6; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r8
  __int64 v11; // r10
  __int64 v12; // r6
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  idAlignedEntity *thirdPersonLegs; // r3
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  __int64 v23; // r10
  __int64 v24; // r8
  __int64 v25; // r6
  __int64 v26; // r6
  __int64 v27; // r10
  __int64 v28; // r8
  __int64 v29; // r6
  __int64 v30; // r10
  __int64 v31; // r8
  __int64 v32; // r10
  __int64 v33; // r8
  __int64 v34; // r6
  int v35; // [sp+8h] [-78h]
  int v36; // [sp+8h] [-78h]
  int v37; // [sp+8h] [-78h]
  int v38; // [sp+8h] [-78h]
  int v39; // [sp+8h] [-78h]
  int v40; // [sp+8h] [-78h]
  int v41; // [sp+8h] [-78h]
  int v42; // [sp+8h] [-78h]
  int v43; // [sp+8h] [-78h]
  int v44; // [sp+Ch] [-74h]
  int v45; // [sp+Ch] [-74h]
  int v46; // [sp+Ch] [-74h]
  int v47; // [sp+Ch] [-74h]
  int v48; // [sp+Ch] [-74h]
  int v49; // [sp+Ch] [-74h]
  int v50; // [sp+Ch] [-74h]
  int v51; // [sp+Ch] [-74h]
  int v52; // [sp+Ch] [-74h]
  int v53; // [sp+10h] [-70h]
  int v54; // [sp+10h] [-70h]
  int v55; // [sp+10h] [-70h]
  int v56; // [sp+10h] [-70h]
  int v57; // [sp+10h] [-70h]
  int v58; // [sp+10h] [-70h]
  int v59; // [sp+10h] [-70h]
  int v60; // [sp+10h] [-70h]
  int v61; // [sp+10h] [-70h]
  int v62; // [sp+14h] [-6Ch]
  int v63; // [sp+14h] [-6Ch]
  int v64; // [sp+14h] [-6Ch]
  int v65; // [sp+14h] [-6Ch]
  int v66; // [sp+14h] [-6Ch]
  int v67; // [sp+14h] [-6Ch]
  int v68; // [sp+14h] [-6Ch]
  int v69; // [sp+14h] [-6Ch]
  int v70; // [sp+14h] [-6Ch]
  int v71; // [sp+18h] [-68h]
  int v72; // [sp+18h] [-68h]
  int v73; // [sp+18h] [-68h]
  int v74; // [sp+18h] [-68h]
  int v75; // [sp+18h] [-68h]
  int v76; // [sp+18h] [-68h]
  int v77; // [sp+18h] [-68h]
  int v78; // [sp+18h] [-68h]
  int v79; // [sp+18h] [-68h]
  int v80; // [sp+1Ch] [-64h]
  int v81; // [sp+1Ch] [-64h]
  int v82; // [sp+1Ch] [-64h]
  int v83; // [sp+1Ch] [-64h]
  int v84; // [sp+1Ch] [-64h]
  int v85; // [sp+1Ch] [-64h]
  int v86; // [sp+1Ch] [-64h]
  int v87; // [sp+1Ch] [-64h]
  int v88; // [sp+1Ch] [-64h]
  double x; // [sp+20h] [-60h]
  double v90; // [sp+20h] [-60h]
  float v91[4]; // [sp+50h] [-30h] BYREF

  if ( pb_cs_Debug.valueInteger != 0 )
  {
    value = this->behaviors.wallClimb.wallClimb.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v3 = (idVec3 *)&pb_wc_climbOffDistance;
      valueFloat = pb_wc_climbOffDistance.valueFloat;
      v5 = (idWallClimb *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v5 != nullptr )
        v6 = idWallClimb::CastTo(c: v5);
      else
        v6 = nullptr;
      idWallClimb::GetClosestPoint(this: v6, player: this, climbOffDistance: valueFloat, point: v3, a5: v91);
      idPlayer::debugHUDPrintf(
        this,
        fmt: "--- WallClimb ---",
        a3: v9,
        a4: v8,
        a5: v7,
        a6: v35,
        a7: v44,
        a8: v53,
        a9: v62,
        a10: v71,
        a11: v80);
      HIDWORD(v10) = this->behaviors.wallClimb.state;
      LODWORD(v11) = &aAvSsobjectVCom[20];
      LODWORD(v12) = 4 * HIDWORD(v10);
      LODWORD(v10) = wcStateNames;
      HIDWORD(v11) = &off_82350000;
      HIDWORD(v12) = wcStateNames[HIDWORD(v10)];
      idPlayer::debugHUDPrintf(
        this,
        fmt: "WallClimb state: %s",
        a3: v12,
        a4: v10,
        a5: v11,
        a6: v36,
        a7: v45,
        a8: v54,
        a9: v63,
        a10: v72,
        a11: v81);
      idPlayer::debugHUDPrintf(
        this,
        fmt: &byte_8200D768,
        a3: v15,
        a4: v14,
        a5: v13,
        a6: v37,
        a7: v46,
        a8: v55,
        a9: v64,
        a10: v73,
        a11: v82);
      thirdPersonLegs = this->thirdPersonLegs;
      if ( thirdPersonLegs != nullptr )
        HIDWORD(v18) = idAlignedEntity::GetCurAnimName(this: thirdPersonLegs);
      else
        HIDWORD(v18) = "NoLegs";
      idPlayer::debugHUDPrintf(
        this,
        fmt: "Legs anim: %s",
        a3: v18,
        a4: v17,
        a5: v16,
        a6: v38,
        a7: v47,
        a8: v56,
        a9: v65,
        a10: v74,
        a11: v83);
      idPlayer::debugHUDPrintf(
        this,
        fmt: &byte_8200D768,
        a3: v22,
        a4: v21,
        a5: v20,
        a6: v39,
        a7: v48,
        a8: v57,
        a9: v66,
        a10: v75,
        a11: v84);
      idPlayer::debugHUDPrintf(
        this,
        fmt: &byte_8200D768,
        a3: v25,
        a4: v24,
        a5: v23,
        a6: v40,
        a7: v49,
        a8: v58,
        a9: v67,
        a10: v76,
        a11: v85);
      x = this->behaviors.wallClimb.extraWorldTranslationBlend.p1.x;
      HIDWORD(v26) = LODWORD(x);
      LODWORD(v27) = &off_82350000;
      idPlayer::debugHUDPrintf(
        this,
        fmt: "Hands extra world translation blend val: %0.2f",
        a3: v26,
        a4: v28,
        a5: v27,
        a6: v41,
        a7: v50,
        a8: v59,
        a9: v68,
        a10: v77,
        a11: v86);
      v90 = this->behaviors.wallClimb.extraWorldRotationBlend.p1.x;
      HIDWORD(v29) = LODWORD(v90);
      HIDWORD(v30) = &off_82350000;
      idPlayer::debugHUDPrintf(
        this,
        fmt: "Hands extra world rotation blend val: %0.2f",
        a3: v29,
        a4: v31,
        a5: v30,
        a6: v42,
        a7: v51,
        a8: v60,
        a9: v69,
        a10: v78,
        a11: v87);
      idPlayer::debugHUDPrintf(
        this,
        fmt: &byte_8200D768,
        a3: v34,
        a4: v33,
        a5: v32,
        a6: v43,
        a7: v52,
        a8: v61,
        a9: v70,
        a10: v79,
        a11: v88);
    }
  }
}


// ========================================================================
// ?PlayerBehavior_WallClimb_SetState@idPlayer@@QAAXW4idPlayerBehaviorWallClimbState_t@1@PBVidVec3@@@Z
// EA  : 0x82E4B808
// RVA : 0x00E4B808
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_WallClimb_SetState(
        idPlayer *this,
        unsigned int state,
        const idVec3 *startPosOverride)
{
  char v6; // r28
  idEntityPtr<idWallClimb> *p_wallClimb; // r30
  const char *v8; // r26
  int v9; // r3
  double maxDeltaYaw; // fp29
  double maxDeltaPitch; // fp30
  const idIndex<short,enum invalidJointIndex_t> *value; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r3
  int v15; // r3
  idWallClimb *v16; // r3
  idWallClimb *v17; // r3
  idPhysics *Physics; // r3
  float *v19; // r3
  idAlignedEntity *thirdPersonLegs; // r3
  float v21; // r9
  float v22; // r8
  float v23; // r7
  idMat3 v24; // [sp+50h] [-120h] BYREF
  idVec3 v25[2]; // [sp+78h] [-F8h] BYREF
  idMat3 v26; // [sp+90h] [-E0h] BYREF
  idVec3 v27[2]; // [sp+B8h] [-B8h] BYREF
  blendParms_t v28; // [sp+D0h] [-A0h] BYREF
  idMat3 v29; // [sp+F0h] [-80h] BYREF

  v6 = 0;
  p_wallClimb = &this->behaviors.wallClimb.wallClimb;
  if ( pb_cs_DebugTraceStates.valueInteger != 0 )
  {
    v8 = wcStateNames[state];
    v9 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "^2(%d)%s - Setting shimmy state: %s\n", v9, "idPlayer::PlayerBehavior_WallClimb_SetState", v8);
  }
  blendParms_t::blendParms_t(this: &v28);
  blendParms_t::blendParms_t(this: (blendParms_t *)&v24.mat[1].y);
  blendParms_t::SetDuration(this: (blendParms_t *)&v24.mat[1].y, frame: pb_cs_AnimBlendFrames.valueInteger);
  if ( state <= 6 && state != 0 )
  {
    switch ( state )
    {
      case 1u:
        idPlayer::PlayerBehavior_WallClimb_StartWallClimb(this);
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
          this,
          animName: "grapplingclimb/legs_mh",
          loop: false,
          durationMS: -1,
          blendParms: &v28,
          rateScale: 1.0);
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
          this,
          animName: "grapplingclimb/player_mh",
          loop: false,
          durationMS: -1,
          blendParms: &v28,
          rateScale: 1.0);
        idPlayer::PlayerBehavior_WallClimb_AlignThirdPersonModels(this, startPosOverride);
        maxDeltaYaw = idEntityPtr<idWallClimb>::operator->(this: p_wallClimb)->maxDeltaYaw;
        if ( maxDeltaYaw < 0.0 )
          maxDeltaYaw = pb_wc_MaxDeltaYaw.valueFloat;
        maxDeltaPitch = idEntityPtr<idWallClimb>::operator->(this: p_wallClimb)->maxDeltaPitch;
        if ( maxDeltaPitch < 0.0 )
          maxDeltaPitch = pb_wc_MaxDeltaPitch.valueFloat;
        value = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->springCamera->lookJointIndex.value;
        TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->thirdPersonLegs);
        idTreeAnimator::GetModelSpaceJointTransform(
          this: TreeAnimatorFromPresentable,
          pose: DRIVER_MODEL,
          jointIndex: value,
          origin: v27,
          axis: &v29);
        idEntity::ConvertLocalToWorldTransform(this: this->thirdPersonLegs, offset: v27, axis: &v29);
        idMat3::ToAngles(this: &v24, result: (idAngles *)&v29);
        v24.mat[0].z = 0.0;
        idPlayer::SetViewAngles(this, angles: (idAngles *)&v24, force: true);
        idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
          this,
          constrain: true,
          heading: (idAngles *)&v29,
          maxDeltaPitch,
          maxDeltaYaw,
          rate: pb_cs_ConstrainedViewAnglesRate.valueFloat);
        presentable = this->presentable;
        if ( presentable != nullptr )
          v15 = (int)presentable->GetPlayerInterface_2(this: presentable);
        else
          v15 = 0;
        idUCmdTracker::ResetPrevViewAngles(this: (idUCmdTracker *)(v15 + 45960));
        idSpringCamera::InitSprings(this: this->springCamera, k: pb_cs_CameraSpringK.valueFloat);
        break;
      case 2u:
        blendParms_t::SetDuration(this: (blendParms_t *)&v24.mat[1].y, frame: pb_cs_IdleBlendFrames.valueInteger);
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
          this,
          animName: "grapplingclimb/legs_mh",
          loop: true,
          durationMS: -1,
          blendParms: (const blendParms_t *)&v24.mat[1].y,
          rateScale: 1.0);
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
          this,
          animName: "grapplingclimb/player_mh",
          loop: true,
          durationMS: -1,
          blendParms: (const blendParms_t *)&v24.mat[1].y,
          rateScale: 1.0);
        p_wallClimb[53].spawnId.value = 0;
        break;
      case 3u:
        if ( p_wallClimb[3].spawnId.value == 2 )
          blendParms_t::SetDuration(this: (blendParms_t *)&v24.mat[1].y, frame: pb_cs_IdleBlendFrames.valueInteger);
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
          this,
          animName: "grapplingclimb/legs_climb_forward",
          loop: true,
          durationMS: -1,
          blendParms: (const blendParms_t *)&v24.mat[1].y,
          rateScale: pb_wc_MovementScale.valueFloat);
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
          this,
          animName: "grapplingclimb/player_climb_forward",
          loop: true,
          durationMS: -1,
          blendParms: (const blendParms_t *)&v24.mat[1].y,
          rateScale: 1.0);
        break;
      case 4u:
        if ( p_wallClimb[3].spawnId.value == 2 )
          blendParms_t::SetDuration(this: (blendParms_t *)&v24.mat[1].y, frame: pb_cs_IdleBlendFrames.valueInteger);
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
          this,
          animName: "grapplingclimb/legs_climb_downward",
          loop: true,
          durationMS: -1,
          blendParms: (const blendParms_t *)&v24.mat[1].y,
          rateScale: pb_wc_MovementScaleDown.valueFloat);
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
          this,
          animName: "grapplingclimb/player_climb_downward",
          loop: true,
          durationMS: -1,
          blendParms: (const blendParms_t *)&v24.mat[1].y,
          rateScale: pb_wc_MovementScaleDown.valueFloat);
        break;
      case 5u:
        v16 = idEntityPtr<idWallClimb>::operator->(this: p_wallClimb);
        idWallClimb::GetClimbOffPosition(this: v16, point: v25, axis: &v26);
        v25[0].z = v25[0].z - pb_wc_climbOffDistance.valueFloat;
        v17 = idEntityPtr<idWallClimb>::operator->(this: p_wallClimb);
        Physics = idEntity::GetPhysics(this: v17);
        v19 = (float *)Physics->GetAxis(this: Physics, a2: 0);
        v21 = *v19;
        v22 = v19[2];
        v23 = v19[1];
        thirdPersonLegs = this->thirdPersonLegs;
        v26.mat[2].x = 0.0;
        v26.mat[2].y = 0.0;
        v24.mat[0].x = v21;
        v24.mat[0].z = v22;
        v26.mat[0].z = v22;
        v24.mat[0].y = v23;
        v26.mat[2].z = 1.0;
        v26.mat[0].x = v21;
        v26.mat[0].y = v23;
        v26.mat[1].z = (float)(v23 * (float)0.0) - (float)(v21 * (float)0.0);
        v26.mat[1].x = (float)(v22 * (float)0.0) - v23;
        v26.mat[1].y = v21 - (float)(v22 * (float)0.0);
        idAlignedEntity::Align(
          this: thirdPersonLegs,
          origin: v25,
          axis: &v26,
          alignMode: ALIGN_NODE_POS_ALIGN_NODE_AXIS);
        idAlignedEntity::Align(
          this: this->thirdPersonHands,
          origin: v25,
          axis: &v26,
          alignMode: ALIGN_NODE_POS_ALIGN_NODE_AXIS);
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
          this,
          animName: "grapplingclimb/legsexit_ledge_window",
          loop: false,
          durationMS: -1,
          blendParms: (const blendParms_t *)&v24.mat[1].y,
          rateScale: 1.0);
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
          this,
          animName: "grapplingclimb/playerexit_ledge_window",
          loop: false,
          durationMS: -1,
          blendParms: (const blendParms_t *)&v24.mat[1].y,
          rateScale: 1.0);
        v6 = 1;
        idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
          this,
          constrain: false,
          heading: nullptr,
          maxDeltaPitch: 0.0,
          maxDeltaYaw: 0.0,
          rate: 0.0);
        break;
      default:
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
          this,
          animName: "grapplingclimb/legs_mh",
          loop: false,
          durationMS: -1,
          blendParms: (const blendParms_t *)&v24.mat[1].y,
          rateScale: 1.0);
        break;
    }
  }
  p_wallClimb[3].spawnId.value = state;
  if ( v6 != 0 )
    idPlayer::PlayerBehavior_Shared_AutoApplyThirdPersonLegsAnimDeltas(this, applyToPlayer: true, clip: false);
}


// ========================================================================
// ?PlayerBehavior_WallClimb_MountWall@idPlayer@@QAAXPAVidWallClimb@@ABVidVec3@@@Z
// EA  : 0x82E4BD28
// RVA : 0x00E4BD28
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_WallClimb_MountWall(
        idPlayer *this,
        idWallClimb *wallClimb,
        const idVec3 *closestPoint)
{
  if ( wallClimb != nullptr )
    this->behaviors.wallClimb.wallClimb.spawnId.value = (gameLocal->spawnIds.ptr[wallClimb->entityNumber] << 13)
                                                      | wallClimb->entityNumber;
  else
    this->behaviors.wallClimb.wallClimb.spawnId.value = 0x1FFF;
  idPlayer::PlayerBehavior_WallClimb_SetState(this, state: 1u, startPosOverride: closestPoint);
}


// ========================================================================
// ?PlayerBehavior_WallClimb_Handle@idPlayer@@QAAXXZ
// EA  : 0x82E4BD70
// RVA : 0x00E4BD70
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPlayer::PlayerBehavior_WallClimb_Handle(idPlayer *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  __int64 v4; // r5 OVERLAPPED
  idPresentable *presentable; // r3
  int v6; // r3
  char v7; // r11
  idPresentable *v8; // r3
  double valueFloat; // fp29
  int v10; // r3
  idPresentable *v11; // r11
  double v12; // fp30
  int v13; // r11
  int v14; // r6
  double v15; // fp28
  idWallClimb *v16; // r3
  idPhysics *Physics; // r3
  double v18; // fp31
  idWallClimb *v19; // r3
  idVec3 *v20; // r5
  idWallClimb::wallClimbEndPointType_t ClosestPoint; // r3
  idAlignedEntity *thirdPersonLegs; // r3
  const char *v23; // r29
  int v24; // r3
  const char *v25; // r29
  int v26; // r3
  idPresentable *v27; // r3
  idPresentablePlayer *v28; // r3
  const char *v29; // r29
  int v30; // r3
  idWallClimb *v31; // r3
  double MaxSidewaysDistance; // fp1
  double v33; // fp31
  double v34; // fp1
  double v35; // fp30
  int v36; // r29
  __int64 v37; // r11
  double v38; // fp0
  idPLogScope v39; // [sp+58h] [-D8h] BYREF
  idVec3 v40; // [sp+60h] [-D0h] BYREF
  blendParms_t v41; // [sp+70h] [-C0h] BYREF
  blendParms_t v42; // [sp+90h] [-A0h] BYREF
  playerExplicitMove_t v43; // [sp+B0h] [-80h] BYREF

  RD_EventBegin(name: "idPlayer::PlayerBehavior_WallClimb_Handle");
  LODWORD(v2) = "idPlayer::PlayerBehavior_WallClimb_Handle";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v39, pl: &pLog, gMask: v2, label: v3);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v6 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v6 = 0;
  if ( (*(_BYTE *)(v6 + 47032) & 0x20) != 0 )
    goto _M491850;
  if ( pb_cs_Enable.valueInteger == 0 || (v7 = 1, !this->behaviors.wallClimb.bEnabled) )
    v7 = 0;
  if ( v7 == 0 || this->behaviors.wallClimb.state == WALLCLIMB_STATE_NONE )
  {
_M491850:
    idPLogScope::~idPLogScope(this: &v39);
    goto LABEL_59;
  }
  v8 = this->presentable;
  valueFloat = pb_cs_InputDeadZone.valueFloat;
  if ( v8 != nullptr )
    v10 = (int)v8->GetPlayerInterface_2(this: v8);
  else
    v10 = 0;
  v11 = this->presentable;
  LODWORD(v4) = *(char *)(v10 + 46318);
  v12 = (float)((float)v4 * (float)0.0078740157);
  if ( v11 != nullptr )
    v13 = (int)v11->GetPlayerInterface_2(this: v11);
  else
    v13 = 0;
  v14 = *(char *)(v13 + 46319);
  v15 = (float)((float)*(__int64 *)((char *)&v4 - 4) * (float)0.0078740157);
  v16 = idEntityPtr<idWallClimb>::operator->(this: &this->behaviors.wallClimb.wallClimb);
  Physics = idEntity::GetPhysics(this: v16);
  Physics->GetAxis(this: Physics, a2: 0);
  v18 = pb_wc_climbOffDistance.valueFloat;
  v19 = idEntityPtr<idWallClimb>::operator->(this: &this->behaviors.wallClimb.wallClimb);
  ClosestPoint = idWallClimb::GetClosestPoint(this: v19, player: this, climbOffDistance: v18, point: v20, a5: &v40.x);
  if ( (unsigned int)(this->behaviors.wallClimb.state - 1) <= 6 )
  {
    switch ( this->behaviors.wallClimb.state )
    {
      case WALLCLIMB_STATE_IDLE:
        if ( v12 <= valueFloat )
        {
          if ( v12 < -valueFloat && ClosestPoint != WALLCLIMB_ENDPOINT_DOWN )
          {
            if ( pb_cs_DebugTraceStates.valueInteger != 0 )
            {
              v25 = wcStateNames[4];
              v26 = gameLocal->GetGameFrame(this: gameLocal);
              idLib::Printf(
                fmt: "^2(%d)%s - Setting shimmy state: %s\n",
                v26,
                "idPlayer::PlayerBehavior_WallClimb_SetState",
                v25);
            }
            blendParms_t::blendParms_t(this: &v42);
            blendParms_t::blendParms_t(this: &v41);
            blendParms_t::SetDuration(this: &v41, frame: pb_cs_AnimBlendFrames.valueInteger);
            if ( this->behaviors.wallClimb.state == WALLCLIMB_STATE_IDLE )
              blendParms_t::SetDuration(this: &v41, frame: pb_cs_IdleBlendFrames.valueInteger);
            idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
              this,
              animName: "grapplingclimb/legs_climb_downward",
              loop: true,
              durationMS: -1,
              blendParms: &v41,
              rateScale: pb_wc_MovementScaleDown.valueFloat);
            idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
              this,
              animName: "grapplingclimb/player_climb_downward",
              loop: true,
              durationMS: -1,
              blendParms: &v41,
              rateScale: pb_wc_MovementScaleDown.valueFloat);
            this->behaviors.wallClimb.state = WALLCLIMB_STATE_CLIMB_DOWN;
          }
        }
        else
        {
          if ( pb_cs_DebugTraceStates.valueInteger != 0 )
          {
            v23 = wcStateNames[3];
            v24 = gameLocal->GetGameFrame(this: gameLocal);
            idLib::Printf(
              fmt: "^2(%d)%s - Setting shimmy state: %s\n",
              v24,
              "idPlayer::PlayerBehavior_WallClimb_SetState",
              v23);
          }
          blendParms_t::blendParms_t(this: &v42);
          blendParms_t::blendParms_t(this: &v41);
          blendParms_t::SetDuration(this: &v41, frame: pb_cs_AnimBlendFrames.valueInteger);
          if ( this->behaviors.wallClimb.state == WALLCLIMB_STATE_IDLE )
            blendParms_t::SetDuration(this: &v41, frame: pb_cs_IdleBlendFrames.valueInteger);
          idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
            this,
            animName: "grapplingclimb/legs_climb_forward",
            loop: true,
            durationMS: -1,
            blendParms: &v41,
            rateScale: pb_wc_MovementScale.valueFloat);
          idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
            this,
            animName: "grapplingclimb/player_climb_forward",
            loop: true,
            durationMS: -1,
            blendParms: &v41,
            rateScale: 1.0);
          this->behaviors.wallClimb.state = WALLCLIMB_STATE_CLIMB_UP;
        }
        goto LABEL_53;
      case WALLCLIMB_STATE_CLIMB_UP:
        if ( v12 > valueFloat )
        {
          if ( true == (ClosestPoint == WALLCLIMB_ENDPOINT_UP) )
            idPlayer::PlayerBehavior_WallClimb_SetState(this, state: 5u, startPosOverride: nullptr);
          goto LABEL_53;
        }
        goto LABEL_44;
      case WALLCLIMB_STATE_CLIMB_DOWN:
        if ( true != (ClosestPoint == WALLCLIMB_ENDPOINT_DOWN) && v12 < -valueFloat )
          goto LABEL_53;
        goto LABEL_44;
      case WALLCLIMB_STATE_DISMOUNT_UP:
      case WALLCLIMB_STATE_DISMOUNT_FALL:
        if ( !this->thirdPersonHands->IsAnimating(this: this->thirdPersonHands) )
        {
          idPlayer::PlayerBehavior_WallClimb_PostDismount(this);
          idPlayer::PlayerBehavior_WallClimb_SetState(this, state: 7u, startPosOverride: nullptr);
        }
        goto LABEL_53;
      default:
        break;
    }
    if ( this->behaviors.wallClimb.state != WALLCLIMB_STATE_MOUNT )
    {
      v27 = this->presentable;
      v43.velocityType = VEL_EXPLICIT;
      v43.clipMove = true;
      v43.ignoreEntityNum = 0x1FFF;
      v43.delta.x = vec3_origin.x;
      v43.delta.y = vec3_origin.y;
      v43.delta.z = vec3_origin.z;
      v43.overrideVelocity.x = vec3_origin.x;
      v43.overrideVelocity.y = vec3_origin.y;
      v43.overrideVelocity.z = vec3_origin.z;
      if ( v27 != nullptr )
        v28 = v27->GetPlayerInterface_2(this: v27);
      else
        v28 = nullptr;
      idPresentablePlayer::SetExplicitMove(this: v28, move: &v43, alsoAllowPhysicsMove: false, useExplicitMove2: false);
      if ( pb_cs_DebugTraceStates.valueInteger != 0 )
      {
        v29 = wcStateNames[0];
        v30 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "^2(%d)%s - Setting shimmy state: %s\n",
          v30,
          "idPlayer::PlayerBehavior_WallClimb_SetState",
          v29);
      }
      blendParms_t::blendParms_t(this: &v42);
      blendParms_t::blendParms_t(this: &v41);
      blendParms_t::SetDuration(this: &v41, frame: pb_cs_AnimBlendFrames.valueInteger);
      this->behaviors.wallClimb.state = WALLCLIMB_STATE_NONE;
      idAnimator_Base::SetAlpha(this: &this->thirdPersonLegs->additiveSyncedAnimator, alpha: 0.0);
      idPlayer::idPlayerBehaviorWallClimb::Clear(this: &this->behaviors.wallClimb);
      goto LABEL_53;
    }
    thirdPersonLegs = this->thirdPersonLegs;
    if ( thirdPersonLegs->baseAnimInfo.startBlendOut
      || idAlignedEntity::IsCurAnimDone(this: thirdPersonLegs, numFramesAhead: -1, ignoreQueuedAnims: false) )
    {
LABEL_44:
      idPlayer::PlayerBehavior_WallClimb_SetState(this, state: 2u, startPosOverride: nullptr);
    }
  }
LABEL_53:
  v31 = idEntityPtr<idWallClimb>::operator->(this: &this->behaviors.wallClimb.wallClimb);
  MaxSidewaysDistance = idWallClimb::GetMaxSidewaysDistance(this: v31, point: &v40);
  this->behaviors.wallClimb.sideWaysTranslationBlend.p0.x = v15;
  v33 = MaxSidewaysDistance;
  v34 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
  idSpring<idVec1>::Update(this: &this->behaviors.wallClimb.sideWaysTranslationBlend, dt: v34);
  v35 = (float)(this->behaviors.wallClimb.sideWaysTranslationBlend.p1.x
              * idEntityPtr<idWallClimb>::operator->(this: &this->behaviors.wallClimb.wallClimb)->sidewaysSpeed);
  v36 = gameLocal->GetPreviousGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  LODWORD(v37) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - v36;
  v38 = (float)((float)((float)((float)v37 * (float)v35) * (float)0.001) + this->behaviors.wallClimb.sidewaysPosition);
  if ( v38 >= -v33 )
  {
    if ( v38 > v33 )
      v38 = v33;
  }
  else
  {
    v38 = -v33;
  }
  this->behaviors.wallClimb.sidewaysPosition = v38;
  idPlayer::PlayerBehavior_WallClimb_OrientToSurface(this);
  idPlayer::PlayerBehavior_WallClimb_HandleMovement(this);
  common->IsMultiplayer(this: common);
  idPlayer::PlayerBehavior_WallClimb_HandleAdditiveAnims(this);
  idPlayer::PlayerBehavior_WallClimb_DebugHandle(this);
  idPLogScope::~idPLogScope(this: &v39);
LABEL_59:
  RD_EventEnd();
}


// ========================================================================
// __unwind$490662
// EA  : 0x82E4C4A0
// RVA : 0x00E4C4A0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void _unwind_490662()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 304 + 212));
}


// ========================================================================
// __unwind$490663
// EA  : 0x82E4C4C8
// RVA : 0x00E4C4C8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void _unwind_490663()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 304 + 88));
}


// ========================================================================
// `dynamic initializer for 'pb_wc_SideWaysBlendK''
// EA  : 0x8338E930
// RVA : 0x0138E930
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_wc_SideWaysBlendK__()
{
  idCVar::idCVar(
    this: &pb_wc_SideWaysBlendK,
    name: "pb_wc_SideWaysBlendK",
    value: "300.0",
    flags: 4,
    description: "Spring constant for smoothing the blend when moving sideways",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_wc_SideWaysBlendK__);
}


// ========================================================================
// `dynamic initializer for 'pb_wc_MaxDeltaPitch''
// EA  : 0x8338E988
// RVA : 0x0138E988
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_wc_MaxDeltaPitch__()
{
  idCVar::idCVar(
    this: &pb_wc_MaxDeltaPitch,
    name: "pb_wc_MaxDeltaPitch",
    value: "75",
    flags: 4,
    description: "Maximum delta pitch, relative to wallclimb normal",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_wc_MaxDeltaPitch__);
}


// ========================================================================
// `dynamic initializer for 'pb_wc_MaxDeltaYaw''
// EA  : 0x8338E9E0
// RVA : 0x0138E9E0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_wc_MaxDeltaYaw__()
{
  idCVar::idCVar(
    this: &pb_wc_MaxDeltaYaw,
    name: "pb_wc_MaxDeltaYaw",
    value: "85",
    flags: 4,
    description: "Maximum delta yaw, relative to wallclimb normal",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_wc_MaxDeltaYaw__);
}


// ========================================================================
// `dynamic initializer for 'pb_wc_MaxConeCamera''
// EA  : 0x8338EA38
// RVA : 0x0138EA38
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_wc_MaxConeCamera__()
{
  idCVar::idCVar(
    this: &pb_wc_MaxConeCamera,
    name: "pb_wc_MaxConeCamera",
    value: "65",
    flags: 4,
    description: "Maximum cone angle for camera",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_wc_MaxConeCamera__);
}


// ========================================================================
// `dynamic initializer for 'pb_wc_MovementScale''
// EA  : 0x8338EA90
// RVA : 0x0138EA90
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_wc_MovementScale__()
{
  idCVar::idCVar(
    this: &pb_wc_MovementScale,
    name: "pb_wc_MovementScale",
    value: "1.0",
    flags: 4,
    description: "Timescale for movement animations upward",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_wc_MovementScale__);
}


// ========================================================================
// `dynamic initializer for 'pb_wc_MovementScaleDown''
// EA  : 0x8338EAE8
// RVA : 0x0138EAE8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_wc_MovementScaleDown__()
{
  idCVar::idCVar(
    this: &pb_wc_MovementScaleDown,
    name: "pb_wc_MovementScaleDown",
    value: "0.5",
    flags: 4,
    description: "Timescale for movement animations downward",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_wc_MovementScaleDown__);
}


// ========================================================================
// `dynamic initializer for 'pb_wc_climbOffDistance''
// EA  : 0x8338EB40
// RVA : 0x0138EB40
// PDB : w:\tech5\tungsten\game\player\playerbehaviorwallclimb.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_wc_climbOffDistance__()
{
  idCVar::idCVar(
    this: &pb_wc_climbOffDistance,
    name: "pb_wc_climbOffDistance",
    value: "200.0",
    flags: 4,
    description: "Distance from anchor point to start climboff",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_wc_climbOffDistance__);
}

