
// ========================================================================
// ?PlayerBehavior_ContextualShimmy_IsInShimmy@idPlayer@@QBA_NXZ
// EA  : 0x82E42990
// RVA : 0x00E42990
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

BOOL __fastcall idPlayer::PlayerBehavior_ContextualShimmy_IsInShimmy(idPlayer *this)
{
  return this->behaviors.contextualShimmy.state != CONTEXTUAL_SHIMMY_STATE_NONE;
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_Startup@idPlayer@@QAAXXZ
// EA  : 0x82E429A0
// RVA : 0x00E429A0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_Startup(idPlayer *this)
{
  idAlignedEntity *thirdPersonLegs; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v4; // r31
  unsigned __int16 v5; // [sp+50h] [-40h] BYREF
  unsigned __int16 v6; // [sp+52h] [-3Eh] BYREF
  unsigned __int16 v7; // [sp+54h] [-3Ch] BYREF
  char v8; // [sp+56h] [-3Ah] BYREF
  char v9; // [sp+58h] [-38h] BYREF
  char v10; // [sp+5Ah] [-36h] BYREF
  char v11; // [sp+5Ch] [-34h] BYREF
  char v12; // [sp+5Eh] [-32h] BYREF
  char v13; // [sp+60h] [-30h] BYREF
  char v14; // [sp+62h] [-2Eh] BYREF
  char v15; // [sp+64h] [-2Ch] BYREF
  char v16; // [sp+66h] [-2Ah] BYREF
  char v17; // [sp+68h] [-28h] BYREF

  if ( gameLocal->FindEntityUsingClass(this: gameLocal, a2: 0, a3: "idLedge") != nullptr )
  {
    thirdPersonLegs = this->thirdPersonLegs;
    this->behaviors.contextualShimmy.bEnabled = true;
    if ( thirdPersonLegs != nullptr )
    {
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: thirdPersonLegs);
      v4 = TreeAnimatorFromPresentable;
      if ( TreeAnimatorFromPresentable != nullptr )
      {
        idDeclMD6::StrongLoadAlias(
          this: (idDeclMD6 *)&v5,
          result: TreeAnimatorFromPresentable->decl,
          aliasName: "shimmy/torsoTwist_center");
        this->behaviors.contextualShimmy.bodyRotationAnimAliasHandles[0].value = v5;
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v6, result: v4->decl, aliasName: "shimmy/torsoTwist_left");
        this->behaviors.contextualShimmy.bodyRotationAnimAliasHandles[1].value = v6;
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v7, result: v4->decl, aliasName: "shimmy/torsoTwist_right");
        this->behaviors.contextualShimmy.bodyRotationAnimAliasHandles[2].value = v7;
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v8, result: v4->decl, aliasName: "shimmy/idle");
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v9, result: v4->decl, aliasName: "shimmy/idle_alt1");
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v10, result: v4->decl, aliasName: "shimmy/idle_alt2");
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v11, result: v4->decl, aliasName: "shimmy/idle_alt3");
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v12, result: v4->decl, aliasName: "shimmy/shimmy_right");
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v13, result: v4->decl, aliasName: "shimmy/shimmy_left");
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v14, result: v4->decl, aliasName: "shimmy/90_outside_corner_lft");
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v15, result: v4->decl, aliasName: "shimmy/90_outside_corner_rgh");
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v16, result: v4->decl, aliasName: "shimmy/90_inside_corner_lft");
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v17, result: v4->decl, aliasName: "shimmy/90_inside_corner_rgh");
      }
    }
  }
  else
  {
    this->behaviors.contextualShimmy.bEnabled = false;
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_HandleAdditiveAnims@idPlayer@@QAAXXZ
// EA  : 0x82E42B48
// RVA : 0x00E42B48
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_HandleAdditiveAnims(idPlayer *this)
{
  double v2; // fp31
  blendParms_t v3; // [sp+50h] [-30h] BYREF

  if ( this->behaviors.contextualShimmy.state != CONTEXTUAL_SHIMMY_STATE_NONE )
  {
    v2 = 0.0;
    idActor::IsEquippedWeaponOneHanded(this);
    if ( pb_cs_DebugAdditiveAnims.valueInteger != 0 )
    {
      idCVar::SetBool(this: &pb_cs_DebugAdditiveAnims, newValue: false, force: true);
      v2 = 1.0;
      idAlignedEntity::PlayAdditiveAnim(
        this: this->thirdPersonLegs,
        aliasName: "shimmy/fallLegsAdditive",
        loop: false,
        durationMS: -1,
        _blendParms: nullptr);
      blendParms_t::blendParms_t(this: &v3);
      blendParms_t::SetDurationMS(this: &v3, ms: pb_cs_AdditiveAnimBlendMS.valueInteger);
      idAlignedEntity::QueueAdditiveAnim(
        this: this->thirdPersonLegs,
        aliasName: "shimmy/fallLegsAdditive_loop",
        loop: false,
        durationMS: -1,
        _blendParms: nullptr);
    }
    else
    {
      idAlignedEntity::StopAdditiveAnim(this: this->thirdPersonLegs);
    }
    idAlignedEntity::SetAdditiveAnimAlpha(this: this->thirdPersonLegs, alpha: v2, alphaRate: 10.0);
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_EndShimmy@idPlayer@@QAAXXZ
// EA  : 0x82E42C80
// RVA : 0x00E42C80
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_EndShimmy(idPlayer *this)
{
  idAnimator_Base::SetAlpha(this: &this->thirdPersonLegs->additiveSyncedAnimator, alpha: 0.0);
  idPlayer::idPlayerBehaviorContextualShimmy::Clear(this: &this->behaviors.contextualShimmy);
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_HandleMovement@idPlayer@@QAAXXZ
// EA  : 0x82E42CC8
// RVA : 0x00E42CC8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_HandleMovement(idPlayer *this)
{
  idPlayer::idPlayerBehaviorContextualShimmy *p_contextualShimmy; // r30
  double v3; // fp31
  idAlignedEntity *thirdPersonLegs; // r3
  idVec3 *v5; // r10
  float *p_z; // r11
  int i; // ctr
  idPresentable *presentable; // r3
  idPresentable *v9; // r3
  float *v10; // r3
  double v11; // fp13
  double v12; // fp12
  double v13; // fp11
  double v14; // fp10
  double v15; // fp9
  double v16; // fp8
  double v17; // fp7
  double v18; // fp6
  idQuat *v19; // r3
  idQuat *v20; // r3
  double v21; // fp1
  double v22; // fp1
  idQuat v23; // [sp+50h] [-130h] BYREF
  idMat3 v24; // [sp+60h] [-120h] BYREF
  idVec3 v25[2]; // [sp+88h] [-F8h] BYREF
  idQuat v26; // [sp+A0h] [-E0h] BYREF
  idMat3 v27; // [sp+B0h] [-D0h] BYREF
  idMat3 v28; // [sp+F0h] [-90h] BYREF
  idMat3 v29; // [sp+120h] [-60h] BYREF

  if ( this->behaviors.contextualShimmy.state != CONTEXTUAL_SHIMMY_STATE_NONE )
  {
    p_contextualShimmy = &this->behaviors.contextualShimmy;
    switch ( this->behaviors.contextualShimmy.state )
    {
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_0:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_0:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_BACK_0:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_90:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_90:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_180:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_180:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_INSIDESSHQ_CLIMBOUT:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_CUSTOMANIM:
      case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_RIGHT:
      case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_FORWARD:
      case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_LEFT:
      case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_FALL:
      case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_CUSTOMANIM:
        v3 = 1.0;
        break;
      default:
        v3 = 0.0;
        break;
    }
    thirdPersonLegs = this->thirdPersonLegs;
    v23 = quat_identity;
    if ( (unsigned __int8)idAnimatedEntity::GetWorldSpaceJointTransform(
                            this: thirdPersonLegs,
                            jointName: "origin",
                            offset: v25,
                            axis: &v28) != 0 )
    {
      v5 = &v27.mat[1];
      p_z = &this->springCamera->viewOrigin.z;
      for ( i = 9; i != 0; --i )
      {
        ++p_z;
        v5 = (idVec3 *)((char *)v5 + 4);
        v5->x = *p_z;
      }
      presentable = this->presentable;
      if ( presentable != nullptr )
        presentable->GetPlayerInterface_2(this: presentable);
      v9 = this->presentable;
      if ( v9 != nullptr )
        v10 = (float *)v9->GetPlayerInterface_2(this: v9);
      else
        v10 = nullptr;
      v11 = v10[11641];
      v12 = v10[11638];
      v13 = v10[11643];
      v14 = v10[11640];
      v15 = v10[11637];
      v16 = v10[11642];
      v17 = v10[11639];
      v18 = v10[11636];
      v24.mat[2].z = v10[11644];
      v24.mat[2].y = v11;
      v24.mat[2].x = v12;
      v24.mat[1].z = v13;
      v24.mat[1].y = v14;
      v24.mat[1].x = v15;
      v24.mat[0].z = v16;
      v24.mat[0].y = v17;
      v24.mat[0].x = v18;
      v19 = (idQuat *)idMat3::operator*(this: &v29, result: (idMat3 *)&v27.mat[1].y, a: &v24);
      v20 = idMat3::ToQuat(this: &v27, result: v19);
      v23.x = v20->x;
      v23.y = v20->y;
      v23.z = v20->z;
      v23.w = v20->w;
    }
    if ( pb_cs_UseExtraWorldOffset.valueInteger == 1 )
    {
      p_contextualShimmy->extraWorldTranslationBlend.p0.x = 1.0;
      v21 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
      idSpring<idVec1>::Update(this: &p_contextualShimmy->extraWorldTranslationBlend, dt: v21);
      p_contextualShimmy->extraWorldRotationBlend.p0.x = v3;
      v22 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
      idSpring<idVec1>::Update(this: &p_contextualShimmy->extraWorldRotationBlend, dt: v22);
      idQuat::Slerp(this: &v26, from: &quat_identity, to: &v23, t: p_contextualShimmy->extraWorldRotationBlend.p1.x);
    }
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_StartShimmy@idPlayer@@QAAXXZ
// EA  : 0x82E42F98
// RVA : 0x00E42F98
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_StartShimmy(idPlayer *this)
{
  idPlayer::idPlayerBehaviorContextualShimmy *p_contextualShimmy; // r31

  p_contextualShimmy = &this->behaviors.contextualShimmy;
  idSpringCamera::InitDefaultSprings(this: this->springCamera);
  idSpringCamera::InitSprings(this: this->springCamera, k: pb_cs_CameraSpringK.valueFloat);
  idSpring<idVec1>::SetConstants(
    this: &p_contextualShimmy->averagedBodyRotationT,
    _k: pb_cs_AveragedBodyRotationK.valueFloat,
    _c: -1.0);
  idSpring<idVec1>::SetConstants(
    this: &p_contextualShimmy->extraWorldTranslationBlend,
    _k: pb_cs_ExtraWorldOffsetBlendK.valueFloat,
    _c: -1.0);
  idSpring<idVec1>::SetConstants(
    this: &p_contextualShimmy->extraWorldRotationBlend,
    _k: pb_cs_ExtraWorldOffsetBlendK.valueFloat,
    _c: -1.0);
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_PostMount@idPlayer@@QAAXXZ
// EA  : 0x82E43038
// RVA : 0x00E43038
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_PostMount(idPlayer *this)
{
  idGameLocal *v2; // r11
  idLedge *v3; // r3
  idLedge *v4; // r3
  int value; // r7
  idAngles *v6; // r29
  idLedge *v7; // r3
  idLedge *v8; // r3
  double maxDeltaYaw; // fp31
  int v10; // r9
  idLedge *v11; // r3
  idLedge *v12; // r3
  double maxDeltaPitch; // fp1

  v2 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->behaviors.contextualShimmy.ledge.spawnId.value & 0x1FFF] == this->behaviors.contextualShimmy.ledge.spawnId.value >> 13
    && (v3 = (idLedge *)gameLocal->entities.ptr[this->behaviors.contextualShimmy.ledge.spawnId.value & 0x1FFF]) != nullptr )
  {
    v4 = idLedge::CastTo(c: v3);
    v2 = gameLocal;
  }
  else
  {
    v4 = nullptr;
  }
  value = this->behaviors.contextualShimmy.ledge.spawnId.value;
  v6 = (idAngles *)&v4->ledgeBits.list[this->behaviors.contextualShimmy.currentLedgeBit];
  if ( v2->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v7 = (idLedge *)v2->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idLedge::CastTo(c: v7);
    v2 = gameLocal;
  }
  else
  {
    v8 = nullptr;
  }
  maxDeltaYaw = v8->maxDeltaYaw;
  if ( maxDeltaYaw < 0.0 )
    maxDeltaYaw = pb_cs_MaxDeltaYaw.valueFloat;
  v10 = this->behaviors.contextualShimmy.ledge.spawnId.value;
  if ( v2->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13 && (v11 = (idLedge *)v2->entities.ptr[v10 & 0x1FFF]) != nullptr )
    v12 = idLedge::CastTo(c: v11);
  else
    v12 = nullptr;
  maxDeltaPitch = v12->maxDeltaPitch;
  if ( maxDeltaPitch < 0.0 )
    maxDeltaPitch = pb_cs_MaxDeltaPitch.valueFloat;
  idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
    this,
    constrain: true,
    heading: v6 + 3,
    maxDeltaPitch,
    maxDeltaYaw,
    rate: pb_cs_ConstrainedViewAnglesRate.valueFloat);
  idSpringCamera::InitSprings(this: this->springCamera, k: pb_cs_CameraSpringK.valueFloat);
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_AlignThirdPersonModels@idPlayer@@QAAXPBVidVec3@@@Z
// EA  : 0x82E431B0
// RVA : 0x00E431B0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_AlignThirdPersonModels(
        idPlayer *this,
        const idVec3 *startPosOverride)
{
  int value; // r10
  idPlayer::idPlayerBehaviorContextualShimmy *p_contextualShimmy; // r29
  idLedge *v6; // r3
  idLedge *v7; // r3
  int currentLedgeBit; // r5
  idLedge::idLedgeBit *v9; // r31
  float *p_x; // r30
  double v11; // fp29
  double v12; // fp30
  double v13; // fp28
  idPhysics *Physics; // r3
  int v15; // r3
  float v16; // r6
  int v17; // r11
  float v18; // r5
  float v19; // r3
  int v20; // r8
  idLedge *v21; // r3
  idLedge *v22; // r3
  double valueFloat; // fp0
  double v24; // fp1
  double v25; // fp9
  double v26; // fp8
  idVec3 v27; // [sp+50h] [-90h] BYREF
  idMat3 v28[2]; // [sp+60h] [-80h] BYREF

  value = this->behaviors.contextualShimmy.ledge.spawnId.value;
  p_contextualShimmy = &this->behaviors.contextualShimmy;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idLedge *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idLedge::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  currentLedgeBit = p_contextualShimmy->currentLedgeBit;
  v9 = &v7->ledgeBits.list[currentLedgeBit];
  if ( v9 != nullptr )
  {
    p_x = &v9->normal.x;
    v11 = (float)((float)(v9->normal.z * (float)0.0) - v9->normal.y);
    v12 = (float)((float)(v9->normal.y * (float)0.0) - (float)(v9->normal.x * (float)0.0));
    v13 = (float)(v9->normal.x - (float)(v9->normal.z * (float)0.0));
    if ( startPosOverride != nullptr )
    {
      p_contextualShimmy->legsAlignPos.x = startPosOverride->x;
      p_contextualShimmy->legsAlignPos.y = startPosOverride->y;
      p_contextualShimmy->legsAlignPos.z = startPosOverride->z;
    }
    else
    {
      Physics = idEntity::GetPhysics(this);
      v15 = (int)Physics->GetOrigin(this: Physics, a2: 0);
      v16 = *(float *)v15;
      v17 = p_contextualShimmy->ledge.spawnId.value & 0x1FFF;
      v18 = *(float *)(v15 + 4);
      v19 = *(float *)(v15 + 8);
      v20 = p_contextualShimmy->ledge.spawnId.value >> 13;
      v27.x = v16;
      v27.y = v18;
      v27.z = v19;
      if ( gameLocal->spawnIds.ptr[v17] == v20 && (v21 = (idLedge *)gameLocal->entities.ptr[v17]) != nullptr )
        v22 = idLedge::CastTo(c: v21);
      else
        v22 = nullptr;
      idLedge::idLedgeBit::GetPointOnLedge(
        this: v9,
        player: this,
        pointOut: &v27,
        bFlipped: (_cntlzw(v22->ledgeNormalHint) & 0x20) != 0);
      valueFloat = pb_cs_LegsOffsetZ.valueFloat;
      v24 = (float)(pb_cs_LegsOffsetZ.valueFloat * (float)0.0);
      v25 = (float)((float)(v27.y + (float)(v9->normal.y * pb_cs_LegsOffsetX.valueFloat))
                  + (float)((float)v13 * pb_cs_LegsOffsetY.valueFloat));
      v26 = (float)((float)(v27.z + (float)(v9->normal.z * pb_cs_LegsOffsetX.valueFloat))
                  + (float)((float)v12 * pb_cs_LegsOffsetY.valueFloat));
      p_contextualShimmy->legsAlignPos.x = (float)((float)(v27.x + (float)(*p_x * pb_cs_LegsOffsetX.valueFloat))
                                                 + (float)(pb_cs_LegsOffsetY.valueFloat * (float)v11))
                                         + (float)(pb_cs_LegsOffsetZ.valueFloat * (float)0.0);
      p_contextualShimmy->legsAlignPos.y = (float)v25 + (float)v24;
      p_contextualShimmy->legsAlignPos.z = (float)v26 + (float)valueFloat;
    }
    v28[0].mat[0].x = *p_x;
    v28[0].mat[0].y = v9->normal.y;
    v28[0].mat[0].z = v9->normal.z;
    v28[0].mat[1].x = v11;
    v28[0].mat[1].y = v13;
    v28[0].mat[1].z = v12;
    v28[0].mat[2].x = 0.0;
    v28[0].mat[2].y = 0.0;
    v28[0].mat[2].z = 1.0;
    idPlayer::PlayerBehavior_Shared_AlignThirdPersonLegsAlignNode(
      this,
      origin: &p_contextualShimmy->legsAlignPos,
      axis: v28);
    idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsAlignNode(
      this,
      origin: &p_contextualShimmy->legsAlignPos,
      axis: v28);
    if ( outputDeltaMove_0 != 0 )
      idLib::Printf(
        fmt: "state=%s: legsAlignPos:(%0.2f,%0.2f,%0.2f)\n",
        stateNames[p_contextualShimmy->state],
        p_contextualShimmy->legsAlignPos.x,
        p_contextualShimmy->legsAlignPos.y,
        p_contextualShimmy->legsAlignPos.z);
    if ( outputDeltaZ_0 != 0 )
      idLib::Printf(
        fmt: "state=%s: legsAlignPos.z:(%0.2f)\n",
        (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(p_contextualShimmy->legsAlignPos.z)),
        p_contextualShimmy->legsAlignPos.z);
  }
  else
  {
    idLib::Warning(
      fmt: "PlayerBehavior_ContextualShimmy_AlignThirdPersonModels ledge '%s' could not fetch ledgebit '%d'",
      v7->name.data,
      currentLedgeBit);
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_OrientToSurface@idPlayer@@QAAXXZ
// EA  : 0x82E434B0
// RVA : 0x00E434B0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_OrientToSurface(idPlayer *this)
{
  int value; // r10
  idEntityPtr<idLedge> *p_ledge; // r28
  idLedge *v4; // r3
  idLedge *v5; // r3
  double maxDeltaPitch; // fp30
  int v7; // r11
  char v8; // r29
  idLedge *Entity; // r3
  int v10; // r5
  idLedge::idLedgeBit *v11; // r30
  idAlignedEntity *thirdPersonLegs; // r31
  idPresentable *presentable; // r11
  float y; // r9
  float z; // r8
  idAlignedEntity *v16; // r31
  idPresentable *v17; // r11
  char *v18; // r10
  idPresentable *p_z; // r11
  int i; // ctr
  float v21; // r10
  float x; // r9
  double v23; // fp3
  double v24; // fp2
  double maxDeltaYaw; // fp2
  idPresentable *v26; // r3
  const idAngles *v27; // r4
  idTreeAnimator *TreeAnimatorFromPresentable; // r31
  idVec3 *LastOriginRotation; // r30
  idMat3 *v30; // r3
  idMat3 *v31; // r3
  float *v32; // r3
  double v33; // fp31
  double v34; // fp30
  double v35; // fp29
  double v36; // fp28
  double v37; // fp27
  double v38; // fp26
  double v39; // fp25
  double v40; // fp24
  double v41; // fp23
  idAngles *v42; // r10
  idAlignedEntity *v43; // r3
  idVec3 v44; // [sp+50h] [-180h] BYREF
  float v45; // [sp+60h] [-170h] BYREF
  float v46; // [sp+64h] [-16Ch]
  float v47; // [sp+68h] [-168h]
  idAngles v48; // [sp+70h] [-160h] BYREF
  char v49; // [sp+7Ch] [-154h] BYREF
  idMat3 v50; // [sp+80h] [-150h] BYREF
  idVec3 v51; // [sp+A8h] [-128h] BYREF
  idQuat v52; // [sp+B8h] [-118h] BYREF
  idQuat v53; // [sp+D0h] [-100h] BYREF
  idVec3 v54; // [sp+E0h] [-F0h] BYREF
  idQuat v55; // [sp+F0h] [-E0h] BYREF
  idQuat v56; // [sp+100h] [-D0h] BYREF
  idMat3 v57[3]; // [sp+130h] [-A0h] BYREF

  if ( pb_cs_OrientToSurface.valueInteger != 0 )
  {
    value = this->behaviors.contextualShimmy.ledge.spawnId.value;
    p_ledge = &this->behaviors.contextualShimmy.ledge;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v4 = (idLedge *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v5 = idLedge::CastTo(c: v4);
    }
    else
    {
      v5 = nullptr;
    }
    maxDeltaPitch = v5->maxDeltaPitch;
    if ( maxDeltaPitch < 0.0 )
      maxDeltaPitch = pb_cs_MaxDeltaPitch.valueFloat;
    v7 = p_ledge[4].spawnId.value;
    switch ( v7 )
    {
      case 1:
      case 2:
      case 3:
      case 8:
      case 9:
      case 10:
      case 13:
      case 15:
        v8 = 1;
        if ( v7 == 13 || v7 == 15 )
          maxDeltaPitch = pb_cs_MaxDeltaPitchMount.valueFloat;
        goto LABEL_14;
      case 4:
      case 5:
      case 6:
      case 7:
      case 18:
      case 19:
      case 20:
      case 21:
        v8 = 0;
        goto LABEL_14;
      case 11:
      case 12:
        v8 = 1;
LABEL_14:
        Entity = idEntityPtr<idLedge>::GetEntity(this: p_ledge);
        v10 = p_ledge[2].spawnId.value;
        v11 = &Entity->ledgeBits.list[v10];
        if ( v11 != nullptr )
        {
          idLedge::idLedgeBit::GetPointOnLedge(
            this: v11,
            player: this,
            pointOut: &v51,
            bFlipped: (_cntlzw(Entity->ledgeNormalHint) & 0x20) != 0);
          thirdPersonLegs = this->thirdPersonLegs;
          presentable = thirdPersonLegs->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
            presentable = thirdPersonLegs->presentable;
          }
          y = presentable->origin.y;
          z = presentable->origin.z;
          v16 = this->thirdPersonLegs;
          v44.x = presentable->origin.x;
          v44.y = y;
          v44.z = z;
          v17 = v16->presentable;
          if ( v17 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v16);
            v17 = v16->presentable;
          }
          v18 = &v49;
          p_z = (idPresentable *)&v17->origin.z;
          for ( i = 9; i != 0; --i )
          {
            p_z = (idPresentable *)((char *)p_z + 4);
            v18 += 4;
            *(_DWORD *)v18 = p_z->__vftable;
          }
          if ( v8 != 0 )
          {
            v21 = v11->normal.y;
            x = v11->normal.x;
            v48.roll = v11->normal.z;
            v48.yaw = v21;
            v48.pitch = x;
            v50.mat[2].z = 1.0;
            v50.mat[0].x = x;
            v50.mat[0].y = v21;
            v50.mat[2].x = 0.0;
            v50.mat[2].y = 0.0;
            v50.mat[0].z = v48.roll;
            v50.mat[1].x = (float)(v48.roll * (float)0.0) - v21;
            v50.mat[1].y = x - (float)(v48.roll * (float)0.0);
            v50.mat[1].z = (float)(v21 * (float)0.0) - (float)(x * (float)0.0);
            v23 = (float)((float)(v48.roll
                                * (float)((float)((float)((float)(v44.x - v51.x) * x)
                                                + (float)((float)((float)(v44.z - v51.z) * v48.roll)
                                                        + (float)((float)(v44.y - v51.y) * v21)))
                                        - pb_cs_DistToShimmySurface.valueFloat))
                        * (float)0.5);
            v24 = (float)(v44.x
                        - (float)((float)(x
                                        * (float)((float)((float)((float)(v44.x - v51.x) * x)
                                                        + (float)((float)((float)(v44.z - v51.z) * v48.roll)
                                                                + (float)((float)(v44.y - v51.y) * v21)))
                                                - pb_cs_DistToShimmySurface.valueFloat))
                                * (float)0.5));
            v44.y = v44.y
                  - (float)((float)(v21
                                  * (float)((float)((float)((float)(v44.x - v51.x) * x)
                                                  + (float)((float)((float)(v44.z - v51.z) * v48.roll)
                                                          + (float)((float)(v44.y - v51.y) * v21)))
                                          - pb_cs_DistToShimmySurface.valueFloat))
                          * (float)0.5);
            v44.x = v24;
            v44.z = v44.z - (float)v23;
            maxDeltaYaw = idEntityPtr<idLedge>::GetEntity(this: p_ledge)->maxDeltaYaw;
            if ( maxDeltaYaw < 0.0 )
              maxDeltaYaw = pb_cs_MaxDeltaYaw.valueFloat;
            idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
              this,
              constrain: true,
              heading: &v48,
              maxDeltaPitch,
              maxDeltaYaw,
              rate: pb_cs_ConstrainedViewAnglesRate.valueFloat);
          }
          v26 = this->presentable;
          if ( v26 != nullptr )
            v27 = (const idAngles *)v26->GetPlayerInterface_2(this: v26);
          else
            v27 = nullptr;
          idPresentablePlayer::GetViewAngles(this: (idPresentablePlayer *)&v45, result: v27, includeWeaponKick: true);
          v44.z = v51.z;
          TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->thirdPersonLegs);
          LastOriginRotation = (idVec3 *)idTreeAnimator::GetLastOriginRotation(this: TreeAnimatorFromPresentable);
          idTreeAnimator::GetLastOriginDeltas(this: TreeAnimatorFromPresentable, rot: &v53, trans: &v54);
          v30 = (idMat3 *)idQuat::Inverse(this: &v55, result: &v53);
          v31 = idQuat::ToMat3(this: &v56, result: v30);
          v32 = (float *)idMat3::operator*(this: v57, result: v31, a: &v50);
          v33 = *v32;
          v50.mat[0].x = *v32;
          v34 = v32[1];
          v50.mat[0].y = v32[1];
          v35 = v32[2];
          v50.mat[0].z = v32[2];
          v36 = v32[3];
          v50.mat[1].x = v32[3];
          v37 = v32[4];
          v50.mat[1].y = v32[4];
          v38 = v32[5];
          v50.mat[1].z = v32[5];
          v39 = v32[6];
          v50.mat[2].x = v32[6];
          v40 = v32[7];
          v50.mat[2].y = v32[7];
          v41 = v32[8];
          v50.mat[2].z = v32[8];
          idQuat::operator*(this: &v52, result: LastOriginRotation, a: &v54);
          v44.x = (float)((float)((float)v33 * v52.x)
                        + (float)((float)((float)v36 * v52.y) + (float)((float)v39 * v52.z)))
                + v44.x;
          v44.y = (float)((float)((float)v34 * v52.x)
                        + (float)((float)((float)v37 * v52.y) + (float)((float)v40 * v52.z)))
                + v44.y;
          v44.z = (float)((float)((float)v35 * v52.x)
                        + (float)((float)((float)v38 * v52.y) + (float)((float)v41 * v52.z)))
                + v44.z;
          v42 = idQuat::ToAngles(this: &v52, result: (idAngles *)&v53);
          v43 = this->thirdPersonLegs;
          v45 = v45 - v42->pitch;
          v46 = v46 - v42->yaw;
          v47 = v47 - v42->roll;
          idAlignedEntity::Align(this: v43, origin: &v44, axis: &v50, alignMode: SET_POS_SET_AXIS);
          this->Teleport(this, a2: &v44, a3: (const idAngles *)&v45);
        }
        else
        {
          idLib::Warning(
            fmt: "PlayerBehavior_ContextualShimmy_OrientToSurface ledge '%s' could not fetch ledgebit '%d'",
            Entity->name.data,
            v10);
        }
        break;
      default:
        return;
    }
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_HandleBodyRotation@idPlayer@@QAAXXZ
// EA  : 0x82E43998
// RVA : 0x00E43998
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_HandleBodyRotation(idPlayer *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r27
  idPlayer::idPlayerBehaviorContextualShimmy *p_contextualShimmy; // r31
  idLedge *v4; // r3
  idLedge *Entity; // r3
  int currentLedgeBit; // r5
  idVec3 *p_firstPoint; // r30
  idPlayer::idPlayerBehaviorContextualShimmyState_t state; // r11
  bool v9; // r10
  idPresentable *presentable; // r3
  const idAngles *v11; // r4
  double v12; // fp1
  double v13; // fp1
  double v14; // fp31
  double maxDeltaYaw; // fp0
  double v16; // fp30
  double v17; // fp1
  double x; // fp0
  double v19; // fp31
  double v20; // fp0
  idAnimator_Synced *p_additiveSyncedAnimator; // r30
  int v22; // r3
  idAnimator_Synced *v23; // r30
  idAlignedEntity *thirdPersonLegs; // r29
  int valueInteger; // r31
  int v26; // r28
  const idAnimStack *v27; // r3
  int v28; // r6
  float v29; // [sp+50h] [-60h] BYREF
  float v30; // [sp+54h] [-5Ch]
  float v31; // [sp+58h] [-58h]
  char v32; // [sp+60h] [-50h] BYREF
  float v33; // [sp+64h] [-4Ch]

  if ( !common->IsMultiplayer(this: common) )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->thirdPersonLegs);
    p_contextualShimmy = &this->behaviors.contextualShimmy;
    if ( TreeAnimatorFromPresentable != nullptr
      && gameLocal->spawnIds.ptr[p_contextualShimmy->ledge.spawnId.value & 0x1FFF] == p_contextualShimmy->ledge.spawnId.value >> 13 )
    {
      v4 = (idLedge *)gameLocal->entities.ptr[p_contextualShimmy->ledge.spawnId.value & 0x1FFF];
      if ( v4 != nullptr && idLedge::CastTo(c: v4) != nullptr )
      {
        Entity = idEntityPtr<idLedge>::GetEntity(this: &this->behaviors.contextualShimmy.ledge);
        currentLedgeBit = this->behaviors.contextualShimmy.currentLedgeBit;
        p_firstPoint = &Entity->ledgeBits.list[currentLedgeBit].firstPoint;
        if ( p_firstPoint != nullptr )
        {
          state = this->behaviors.contextualShimmy.state;
          v9 = false;
          if ( state >= CONTEXTUAL_SHIMMY_STATE_IDLE )
            v9 = state <= CONTEXTUAL_SHIMMY_STATE_DISMOUNT_CUSTOMANIM;
          if ( v9 )
          {
            if ( pb_cs_EnableBodyRotation.valueInteger != 0 )
            {
              presentable = this->presentable;
              if ( presentable != nullptr )
                v11 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
              else
                v11 = nullptr;
              idPresentablePlayer::GetViewAngles(
                this: (idPresentablePlayer *)&v32,
                result: v11,
                includeWeaponKick: true);
              v12 = idVec3::ToYaw(this: p_firstPoint + 3);
              v13 = idMath::AngleNormalize360(angle: (float)(v33 - (float)v12));
              v14 = v13;
              if ( v13 > 180.0 )
                v14 = (float)((float)v13 - (float)360.0);
              maxDeltaYaw = idEntityPtr<idLedge>::GetEntity(this: &this->behaviors.contextualShimmy.ledge)->maxDeltaYaw;
              v16 = 0.0;
              if ( maxDeltaYaw < 0.0 )
                maxDeltaYaw = pb_cs_MaxDeltaYaw.valueFloat;
              this->behaviors.contextualShimmy.averagedBodyRotationT.p0.x = (float)v14 / (float)maxDeltaYaw;
            }
            else
            {
              v16 = 0.0;
              this->behaviors.contextualShimmy.averagedBodyRotationT.p0.x = 0.0;
            }
            v17 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetGameSecPerFrame)(a1: gameLocal, a2: 1);
            idSpring<idVec1>::Update(this: &this->behaviors.contextualShimmy.averagedBodyRotationT, dt: v17);
            x = this->behaviors.contextualShimmy.averagedBodyRotationT.p1.x;
            if ( x < v16 )
            {
              v20 = -x;
              if ( v20 >= v16 )
              {
                if ( v20 <= 1.0 )
                  v19 = v20;
                else
                  v19 = 1.0;
              }
              else
              {
                v19 = v16;
              }
              v30 = v16;
              v31 = 1.0;
            }
            else
            {
              v30 = 1.0;
              if ( x <= 1.0 )
                v19 = x;
              else
                v19 = 1.0;
              v31 = v16;
            }
            v29 = v16;
            p_additiveSyncedAnimator = &this->thirdPersonLegs->additiveSyncedAnimator;
            v22 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
            idAnimator_Synced::SetAnimHandlesAndWeights(
              this: p_additiveSyncedAnimator,
              animator: TreeAnimatorFromPresentable,
              curTime: v22,
              handles: this->behaviors.contextualShimmy.bodyRotationAnimAliasHandles,
              numAnims: 3,
              weights: &v29,
              numWeights: 3);
            v23 = &this->thirdPersonLegs->additiveSyncedAnimator;
            thirdPersonLegs = this->thirdPersonLegs;
            valueInteger = pb_cs_BodyRotationBlendMS.valueInteger;
            v26 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
            v27 = thirdPersonLegs->GetAnimStack_2(this: thirdPersonLegs);
            idAnimator_Base::Blend(
              this: v23,
              stack: v27,
              curTime: v26,
              targetAlpha: v19,
              blendDurationMS: v28,
              reset: valueInteger,
              a7: 1);
          }
        }
        else
        {
          idLib::Warning(
            fmt: "PlayerBehavior_ContextualShimmy_HandleBodyRotation ledge '%s' could not fetch ledgebit '%d'",
            Entity->name.data,
            currentLedgeBit);
        }
      }
    }
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_DebugHandle@idPlayer@@QAAXXZ
// EA  : 0x82E43CA8
// RVA : 0x00E43CA8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_DebugHandle(idPlayer *this)
{
  int value; // r10
  idPlayer::idPlayerBehaviorContextualShimmy *p_contextualShimmy; // r28
  idLedge *v4; // r3
  idLedge *v5; // r3
  idLedge *v6; // r3
  int currentLedgeBit; // r5
  idLedge::idLedgeBit *v8; // r27
  idLedge::ledgeEdgeType_t PointOnLedge; // r3
  __int64 v10; // r10
  idLedge::ledgeEdgeType_t v11; // r29
  __int64 v12; // r8
  __int64 v13; // r6
  __int64 v14; // r8
  __int64 v15; // r6
  __int64 v16; // r10
  __int64 v17; // r10
  __int64 v18; // r6
  __int64 v19; // r8
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  __int64 v23; // r10
  __int64 v24; // r8
  __int64 v25; // r6
  idAlignedEntity *thirdPersonLegs; // r3
  __int64 v27; // r10
  __int64 v28; // r8
  __int64 v29; // r6
  __int64 v30; // r10
  __int64 v31; // r6
  __int64 v32; // r8
  __int64 v33; // r10
  __int64 v34; // r8
  __int64 v35; // r6
  __int64 v36; // r10
  __int64 v37; // r8
  __int64 v38; // r6
  __int64 v39; // r6
  __int64 v40; // r10
  __int64 v41; // r8
  __int64 v42; // r6
  __int64 v43; // r8
  __int64 v44; // r10
  __int64 v45; // r10
  __int64 v46; // r8
  __int64 v47; // r6
  double v48; // fp5
  double v49; // fp3
  double v50; // fp7
  double v51; // fp5
  idRenderWorld *v52; // r3
  double v53; // fp9
  double v54; // fp6
  idRenderWorld *v55; // r3
  double v56; // fp13
  double v57; // fp8
  idLedge *Entity; // r3
  double z; // fp12
  double v60; // fp11
  double v61; // fp9
  idRenderWorld *v62; // r31
  idRenderWorld_vtbl *v63; // r30
  int v64; // r3
  int v65; // [sp+8h] [-118h]
  int v66; // [sp+8h] [-118h]
  int v67; // [sp+8h] [-118h]
  int v68; // [sp+8h] [-118h]
  int v69; // [sp+8h] [-118h]
  int v70; // [sp+8h] [-118h]
  int v71; // [sp+8h] [-118h]
  int v72; // [sp+8h] [-118h]
  int v73; // [sp+8h] [-118h]
  int v74; // [sp+8h] [-118h]
  int v75; // [sp+8h] [-118h]
  int v76; // [sp+8h] [-118h]
  int v77; // [sp+Ch] [-114h]
  int v78; // [sp+Ch] [-114h]
  int v79; // [sp+Ch] [-114h]
  int v80; // [sp+Ch] [-114h]
  int v81; // [sp+Ch] [-114h]
  int v82; // [sp+Ch] [-114h]
  int v83; // [sp+Ch] [-114h]
  int v84; // [sp+Ch] [-114h]
  int v85; // [sp+Ch] [-114h]
  int v86; // [sp+Ch] [-114h]
  int v87; // [sp+Ch] [-114h]
  int v88; // [sp+Ch] [-114h]
  int v89; // [sp+10h] [-110h]
  int v90; // [sp+10h] [-110h]
  int v91; // [sp+10h] [-110h]
  int v92; // [sp+10h] [-110h]
  int v93; // [sp+10h] [-110h]
  int v94; // [sp+10h] [-110h]
  int v95; // [sp+10h] [-110h]
  int v96; // [sp+10h] [-110h]
  int v97; // [sp+10h] [-110h]
  int v98; // [sp+10h] [-110h]
  int v99; // [sp+10h] [-110h]
  int v100; // [sp+10h] [-110h]
  int v101; // [sp+14h] [-10Ch]
  int v102; // [sp+14h] [-10Ch]
  int v103; // [sp+14h] [-10Ch]
  int v104; // [sp+14h] [-10Ch]
  int v105; // [sp+14h] [-10Ch]
  int v106; // [sp+14h] [-10Ch]
  int v107; // [sp+14h] [-10Ch]
  int v108; // [sp+14h] [-10Ch]
  int v109; // [sp+14h] [-10Ch]
  int v110; // [sp+14h] [-10Ch]
  int v111; // [sp+14h] [-10Ch]
  int v112; // [sp+14h] [-10Ch]
  int v113; // [sp+18h] [-108h]
  int v114; // [sp+18h] [-108h]
  int v115; // [sp+18h] [-108h]
  int v116; // [sp+18h] [-108h]
  int v117; // [sp+18h] [-108h]
  int v118; // [sp+18h] [-108h]
  int v119; // [sp+18h] [-108h]
  int v120; // [sp+18h] [-108h]
  int v121; // [sp+18h] [-108h]
  int v122; // [sp+18h] [-108h]
  int v123; // [sp+18h] [-108h]
  int v124; // [sp+18h] [-108h]
  int v125; // [sp+1Ch] [-104h]
  int v126; // [sp+1Ch] [-104h]
  int v127; // [sp+1Ch] [-104h]
  int v128; // [sp+1Ch] [-104h]
  int v129; // [sp+1Ch] [-104h]
  int v130; // [sp+1Ch] [-104h]
  int v131; // [sp+1Ch] [-104h]
  int v132; // [sp+1Ch] [-104h]
  int v133; // [sp+1Ch] [-104h]
  int v134; // [sp+1Ch] [-104h]
  int v135; // [sp+1Ch] [-104h]
  int v136; // [sp+1Ch] [-104h]
  double x; // [sp+20h] [-100h]
  double v138; // [sp+20h] [-100h]
  float v139; // [sp+58h] [-C8h] BYREF
  float v140; // [sp+5Ch] [-C4h]
  float v141; // [sp+60h] [-C0h]
  float v142; // [sp+68h] [-B8h] BYREF
  float v143; // [sp+6Ch] [-B4h]
  float v144; // [sp+70h] [-B0h]
  idVec3 v145; // [sp+78h] [-A8h] BYREF
  float v146[4]; // [sp+88h] [-98h] BYREF
  float v147[6]; // [sp+98h] [-88h] BYREF
  float v148[10]; // [sp+B0h] [-70h] BYREF

  if ( pb_cs_Debug.valueInteger != 0 )
  {
    value = this->behaviors.contextualShimmy.ledge.spawnId.value;
    p_contextualShimmy = &this->behaviors.contextualShimmy;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v4 = (idLedge *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v4 != nullptr && idLedge::CastTo(c: v4) != nullptr )
      {
        if ( gameLocal->spawnIds.ptr[p_contextualShimmy->ledge.spawnId.value & 0x1FFF] == p_contextualShimmy->ledge.spawnId.value >> 13
          && (v5 = (idLedge *)gameLocal->entities.ptr[p_contextualShimmy->ledge.spawnId.value & 0x1FFF]) != nullptr )
        {
          v6 = idLedge::CastTo(c: v5);
        }
        else
        {
          v6 = nullptr;
        }
        currentLedgeBit = p_contextualShimmy->currentLedgeBit;
        v8 = &v6->ledgeBits.list[currentLedgeBit];
        if ( v8 != nullptr )
        {
          PointOnLedge = idLedge::idLedgeBit::GetPointOnLedge(
                           this: v8,
                           player: this,
                           pointOut: &v145,
                           bFlipped: (_cntlzw(v6->ledgeNormalHint) & 0x20) != 0);
          HIDWORD(v10) = &off_82350000;
          v11 = PointOnLedge;
          idPlayer::debugHUDPrintf(
            this,
            fmt: "--- contextual shimmy ---",
            a3: v13,
            a4: v12,
            a5: v10,
            a6: v65,
            a7: v77,
            a8: v89,
            a9: v101,
            a10: v113,
            a11: v125);
          LODWORD(v14) = &aAvSsobjectVCom[20];
          LODWORD(v15) = stateNames;
          HIDWORD(v14) = &off_82350000;
          HIDWORD(v15) = stateNames[p_contextualShimmy->state];
          idPlayer::debugHUDPrintf(
            this,
            fmt: "Shimmy state: %s",
            a3: v15,
            a4: v14,
            a5: v16,
            a6: v66,
            a7: v78,
            a8: v90,
            a9: v102,
            a10: v114,
            a11: v126);
          LODWORD(v17) = &off_82350000;
          HIDWORD(v18) = (int)p_contextualShimmy->fireTimeMS;
          idPlayer::debugHUDPrintf(
            this,
            fmt: "shoot time: %d",
            a3: v18,
            a4: v19,
            a5: v17,
            a6: v67,
            a7: v79,
            a8: v91,
            a9: v103,
            a10: v115,
            a11: v127);
          idPlayer::debugHUDPrintf(
            this,
            fmt: &byte_8200D768,
            a3: v22,
            a4: v21,
            a5: v20,
            a6: v68,
            a7: v80,
            a8: v92,
            a9: v104,
            a10: v116,
            a11: v128);
          thirdPersonLegs = this->thirdPersonLegs;
          if ( thirdPersonLegs != nullptr )
            HIDWORD(v25) = idAlignedEntity::GetCurAnimName(this: thirdPersonLegs);
          else
            HIDWORD(v25) = "NoLegs";
          idPlayer::debugHUDPrintf(
            this,
            fmt: "Legs anim: %s",
            a3: v25,
            a4: v24,
            a5: v23,
            a6: v69,
            a7: v81,
            a8: v93,
            a9: v105,
            a10: v117,
            a11: v129);
          idPlayer::debugHUDPrintf(
            this,
            fmt: &byte_8200D768,
            a3: v29,
            a4: v28,
            a5: v27,
            a6: v70,
            a7: v82,
            a8: v94,
            a9: v106,
            a10: v118,
            a11: v130);
          LODWORD(v30) = &off_82350000;
          HIDWORD(v31) = v11;
          idPlayer::debugHUDPrintf(
            this,
            fmt: "LedgeType: %d",
            a3: v31,
            a4: v32,
            a5: v30,
            a6: v71,
            a7: v83,
            a8: v95,
            a9: v107,
            a10: v119,
            a11: v131);
          idPlayer::debugHUDPrintf(
            this,
            fmt: &byte_8200D768,
            a3: v35,
            a4: v34,
            a5: v33,
            a6: v72,
            a7: v84,
            a8: v96,
            a9: v108,
            a10: v120,
            a11: v132);
          idPlayer::debugHUDPrintf(
            this,
            fmt: &byte_8200D768,
            a3: v38,
            a4: v37,
            a5: v36,
            a6: v73,
            a7: v85,
            a8: v97,
            a9: v109,
            a10: v121,
            a11: v133);
          x = p_contextualShimmy->extraWorldTranslationBlend.p1.x;
          HIDWORD(v39) = LODWORD(x);
          HIDWORD(v40) = &off_82350000;
          idPlayer::debugHUDPrintf(
            this,
            fmt: "Hands extra world translation blend val: %0.2f",
            a3: v39,
            a4: v41,
            a5: v40,
            a6: v74,
            a7: v86,
            a8: v98,
            a9: v110,
            a10: v122,
            a11: v134);
          v138 = p_contextualShimmy->extraWorldRotationBlend.p1.x;
          HIDWORD(v42) = LODWORD(v138);
          LODWORD(v43) = &off_82350000;
          idPlayer::debugHUDPrintf(
            this,
            fmt: "Hands extra world rotation blend val: %0.2f",
            a3: v42,
            a4: v43,
            a5: v44,
            a6: v75,
            a7: v87,
            a8: v99,
            a9: v111,
            a10: v123,
            a11: v135);
          idPlayer::debugHUDPrintf(
            this,
            fmt: &byte_8200D768,
            a3: v47,
            a4: v46,
            a5: v45,
            a6: v76,
            a7: v88,
            a8: v100,
            a9: v112,
            a10: v124,
            a11: v136);
          v48 = (float)(v8->direction.z * ledge_playerWidth.valueFloat);
          v49 = (float)(v145.y - (float)(v8->direction.y * ledge_playerWidth.valueFloat));
          v139 = v145.x - (float)(v8->direction.x * ledge_playerWidth.valueFloat);
          v140 = v49;
          v141 = v145.z - (float)v48;
          v50 = (float)(v8->direction.x * ledge_playerWidth.valueFloat);
          v51 = (float)((float)(v8->direction.y * ledge_playerWidth.valueFloat) + v145.y);
          v144 = (float)(v8->direction.z * ledge_playerWidth.valueFloat) + v145.z;
          v143 = v51;
          v142 = (float)v50 + v145.x;
          v52 = gameLocal->GetRenderWorld(this: gameLocal);
          v53 = (float)(v8->normal.z * (float)10.0);
          v54 = (float)((float)(v8->normal.y * (float)10.0) + v140);
          v146[0] = (float)(v8->normal.x * (float)10.0) + v139;
          v146[1] = v54;
          v146[2] = (float)v53 + v141;
          v52->DebugLine(
            this: v52,
            a2: (const idVec4 *)&idColor::colorWhite,
            a3: (const idVec3 *)&v139,
            a4: (const idVec3 *)v146,
            a5: 0,
            a6: false);
          v55 = gameLocal->GetRenderWorld(this: gameLocal);
          v56 = (float)(v8->normal.z * (float)10.0);
          v57 = (float)((float)(v8->normal.y * (float)10.0) + v143);
          v147[0] = (float)(v8->normal.x * (float)10.0) + v142;
          v147[1] = v57;
          v147[2] = (float)v56 + v144;
          v55->DebugLine(
            this: v55,
            a2: (const idVec4 *)&idColor::colorWhite,
            a3: (const idVec3 *)&v142,
            a4: (const idVec3 *)v147,
            a5: 0,
            a6: false);
          if ( pb_cs_DebugDrawShimmyPoint.valueInteger != 0 )
          {
            Entity = idEntityPtr<idLedge>::GetEntity(this: &p_contextualShimmy->ledge);
            idLedge::idLedgeBit::GetPointOnLedge(
              this: v8,
              player: this,
              pointOut: &v145,
              bFlipped: (_cntlzw(Entity->ledgeNormalHint) & 0x20) != 0);
            if ( p_contextualShimmy->state != CONTEXTUAL_SHIMMY_STATE_NONE )
            {
              z = v8->direction.z;
              v60 = -v8->direction.x;
              v61 = -v8->direction.y;
              v148[0] = v8->normal.x;
              v148[1] = v8->normal.y;
              v148[2] = v8->normal.z;
              v148[3] = v60;
              v148[4] = v61;
              v148[5] = -z;
              v148[6] = 0.0;
              v148[7] = 0.0;
              v148[8] = 1.0;
              v62 = gameLocal->GetRenderWorld(this: gameLocal);
              v63 = v62->__vftable;
              v64 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
              v63->DebugAxis_2(this: v62, a2: &v145, a3: (const idMat3 *)v148, a4: v64, a5: true);
            }
          }
        }
        else
        {
          idLib::Warning(
            fmt: "PlayerBehavior_ContextualShimmy_DebugHandle ledge '%s' could not fetch ledgebit '%d'",
            v6->name.data,
            currentLedgeBit);
        }
      }
    }
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_SetState@idPlayer@@QAAXW4idPlayerBehaviorContextualShimmyState_t@1@PBVidVec3@@@Z
// EA  : 0x82E44140
// RVA : 0x00E44140
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_SetState(
        idPlayer *this,
        idPlayer::idPlayerBehaviorContextualShimmyState_t state,
        const idVec3 *startPosOverride)
{
  idPlayer::idPlayerBehaviorContextualShimmy *p_contextualShimmy; // r27
  const char *v7; // r29
  int v8; // r3
  const char *v9; // r4
  bool v10; // r5
  double valueFloat; // fp1
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v12; // [sp+50h] [-90h] BYREF
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v13; // [sp+52h] [-8Eh] BYREF
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v14; // [sp+54h] [-8Ch] BYREF
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v15; // [sp+56h] [-8Ah] BYREF
  blendParms_t v16; // [sp+60h] [-80h] BYREF
  blendParms_t v17; // [sp+80h] [-60h] BYREF

  p_contextualShimmy = &this->behaviors.contextualShimmy;
  if ( pb_cs_DebugTraceStates.valueInteger != 0 )
  {
    v7 = stateNames[state];
    v8 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(
      fmt: "^2(%d)%s - Setting shimmy state: %s\n",
      v8,
      "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
      v7);
  }
  blendParms_t::blendParms_t(this: &v17);
  blendParms_t::blendParms_t(this: &v16);
  blendParms_t::SetDuration(this: &v16, frame: pb_cs_AnimBlendFrames.valueInteger);
  switch ( state )
  {
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_0:
      idPlayer::PlayerBehavior_ContextualShimmy_StartShimmy(this);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        animName: "shimmy/mount_0_left",
        loop: false,
        durationMS: -1,
        blendParms: &v17,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_ContextualShimmy_AlignThirdPersonModels(this, startPosOverride);
      p_contextualShimmy->state = state;
      return;
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_0:
      idPlayer::PlayerBehavior_ContextualShimmy_StartShimmy(this);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        animName: "shimmy/mount_0_right",
        loop: false,
        durationMS: -1,
        blendParms: &v17,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_ContextualShimmy_AlignThirdPersonModels(this, startPosOverride);
      p_contextualShimmy->state = state;
      return;
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_BACK_0:
      idPlayer::PlayerBehavior_ContextualShimmy_StartShimmy(this);
      p_contextualShimmy->extraWorldTranslationBlend.p1.x = 1.0;
      p_contextualShimmy->extraWorldRotationBlend.p1.x = 1.0;
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        animName: "shimmy/mount_0_back",
        loop: false,
        durationMS: -1,
        blendParms: &v16,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_ContextualShimmy_AlignThirdPersonModels(this, startPosOverride);
      p_contextualShimmy->state = state;
      return;
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_90:
      idPlayer::PlayerBehavior_ContextualShimmy_StartShimmy(this);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        animName: "shimmy/mount_90_left",
        loop: false,
        durationMS: -1,
        blendParms: &v17,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_ContextualShimmy_AlignThirdPersonModels(this, startPosOverride);
      p_contextualShimmy->state = state;
      return;
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_90:
      idPlayer::PlayerBehavior_ContextualShimmy_StartShimmy(this);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        animName: "shimmy/mount_90_right",
        loop: false,
        durationMS: -1,
        blendParms: &v17,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_ContextualShimmy_AlignThirdPersonModels(this, startPosOverride);
      p_contextualShimmy->state = state;
      return;
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_180:
      idPlayer::PlayerBehavior_ContextualShimmy_StartShimmy(this);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        animName: "shimmy/mount_180_left",
        loop: false,
        durationMS: -1,
        blendParms: &v17,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_ContextualShimmy_AlignThirdPersonModels(this, startPosOverride);
      p_contextualShimmy->state = state;
      return;
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_180:
      idPlayer::PlayerBehavior_ContextualShimmy_StartShimmy(this);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        animName: "shimmy/mount_180_right",
        loop: false,
        durationMS: -1,
        blendParms: &v17,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_ContextualShimmy_AlignThirdPersonModels(this, startPosOverride);
      p_contextualShimmy->state = state;
      return;
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_INSIDESSHQ_CLIMBOUT:
      idPlayer::PlayerBehavior_ContextualShimmy_StartShimmy(this);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        animName: "shimmy/insidesshq_climbout",
        loop: false,
        durationMS: -1,
        blendParms: &v17,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
        this,
        animName: "shimmy/insidesshq_climbout",
        loop: false,
        durationMS: -1,
        blendParms: nullptr,
        rateScale: 1.0);
      idPlayer::PlayerBehavior_ContextualShimmy_AlignThirdPersonModels(this, startPosOverride);
      p_contextualShimmy->state = state;
      return;
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_CUSTOMANIM:
      idPlayer::PlayerBehavior_ContextualShimmy_StartShimmy(this);
      if ( gameLocal->spawnIds.ptr[p_contextualShimmy->useLedge.spawnId.value & 0x1FFF] != p_contextualShimmy->useLedge.spawnId.value >> 13 )
        goto LABEL_41;
      v12.value = idEntityPtr<idUseLedge>::operator->(this: &p_contextualShimmy->useLedge)->customLegsAnimationHandle.value;
      v13.value = idEntityPtr<idUseLedge>::operator->(this: &p_contextualShimmy->useLedge)->customHandsAnimationHandle.value;
      if ( v12.value != 0xFFFF )
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
          this,
          alias: &v12,
          loop: false,
          durationMS: -1,
          blendParms: &v17,
          rateScale: 1.0);
      if ( v13.value != 0xFFFF )
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
          this,
          alias: &v13,
          loop: false,
          durationMS: -1,
          blendParms: nullptr,
          rateScale: 1.0);
      idPlayer::PlayerBehavior_ContextualShimmy_AlignThirdPersonModels(this, startPosOverride);
      p_contextualShimmy->state = state;
      return;
    case CONTEXTUAL_SHIMMY_STATE_IDLE:
      blendParms_t::SetDuration(this: &v16, frame: pb_cs_IdleBlendFrames.valueInteger);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        animName: "shimmy/idle",
        loop: true,
        durationMS: -1,
        blendParms: &v16,
        rateScale: 1.0);
      p_contextualShimmy->state = state;
      p_contextualShimmy->nextFidgetTime = 0;
      return;
    case CONTEXTUAL_SHIMMY_STATE_SHIMMY_RIGHT:
      if ( p_contextualShimmy->state == CONTEXTUAL_SHIMMY_STATE_IDLE )
        blendParms_t::SetDuration(this: &v16, frame: pb_cs_IdleBlendFrames.valueInteger);
      v9 = "shimmy/shimmy_right";
      v10 = true;
      valueFloat = pb_cs_MovementScale.valueFloat;
      goto LABEL_40;
    case CONTEXTUAL_SHIMMY_STATE_SHIMMY_LEFT:
      if ( p_contextualShimmy->state == CONTEXTUAL_SHIMMY_STATE_IDLE )
        blendParms_t::SetDuration(this: &v16, frame: pb_cs_IdleBlendFrames.valueInteger);
      v9 = "shimmy/shimmy_left";
      v10 = true;
      valueFloat = pb_cs_MovementScale.valueFloat;
      goto LABEL_40;
    case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_RIGHT:
      v9 = "shimmy/dismount_right";
      goto LABEL_38;
    case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_FORWARD:
      v9 = "shimmy/dismount_forward";
      goto LABEL_38;
    case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_LEFT:
      v9 = "shimmy/dismount_left";
      goto LABEL_38;
    case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_FALL:
      v9 = "shimmy/falllegs_recovery_fall";
LABEL_38:
      valueFloat = 1.0;
      goto LABEL_39;
    case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_CUSTOMANIM:
      if ( gameLocal->spawnIds.ptr[p_contextualShimmy->useLedge.spawnId.value & 0x1FFF] != p_contextualShimmy->useLedge.spawnId.value >> 13 )
        goto LABEL_41;
      v14.value = idEntityPtr<idUseLedge>::operator->(this: &p_contextualShimmy->useLedge)->customLegsAnimationHandle.value;
      v15.value = idEntityPtr<idUseLedge>::operator->(this: &p_contextualShimmy->useLedge)->customHandsAnimationHandle.value;
      idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
        this,
        constrain: false,
        heading: nullptr,
        maxDeltaPitch: 0.0,
        maxDeltaYaw: 0.0,
        rate: 0.0);
      if ( v14.value != 0xFFFF )
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
          this,
          alias: &v14,
          loop: false,
          durationMS: -1,
          blendParms: &v16,
          rateScale: 1.0);
      if ( v15.value == 0xFFFF )
        goto LABEL_41;
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
        this,
        alias: &v15,
        loop: false,
        durationMS: -1,
        blendParms: nullptr,
        rateScale: 1.0);
      p_contextualShimmy->state = state;
      return;
    case CONTEXTUAL_SHIMMY_STATE_SWITCH_OUT90RIGHT:
      v9 = "shimmy/90_outside_corner_rgh";
      valueFloat = pb_cs_MovementScale.valueFloat;
      goto LABEL_39;
    case CONTEXTUAL_SHIMMY_STATE_SWITCH_OUT90LEFT:
      v9 = "shimmy/90_outside_corner_lft";
      valueFloat = pb_cs_MovementScale.valueFloat;
      goto LABEL_39;
    case CONTEXTUAL_SHIMMY_STATE_SWITCH_IN90RIGHT:
      v9 = "shimmy/90_inside_corner_lft";
      valueFloat = pb_cs_MovementScale.valueFloat;
      goto LABEL_39;
    case CONTEXTUAL_SHIMMY_STATE_SWITCH_IN90LEFT:
      v9 = "shimmy/90_inside_corner_rgh";
      valueFloat = pb_cs_MovementScale.valueFloat;
LABEL_39:
      v10 = false;
LABEL_40:
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        animName: v9,
        loop: v10,
        durationMS: -1,
        blendParms: &v16,
        rateScale: valueFloat);
      goto LABEL_41;
    default:
LABEL_41:
      p_contextualShimmy->state = state;
      return;
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_MountLedge@idPlayer@@QAAXPAVidLedge@@HABVidVec3@@PBVidUseLedge@@@Z
// EA  : 0x82E447E8
// RVA : 0x00E447E8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_MountLedge(
        idPlayer *this,
        idLedge *ledge,
        int startLedgeBit,
        const idVec3 *closestLedgePoint,
        const idUseLedge *useLedge)
{
  idPlayer::idPlayerBehaviorContextualShimmy *p_contextualShimmy; // r11

  p_contextualShimmy = &this->behaviors.contextualShimmy;
  if ( ledge != nullptr )
    p_contextualShimmy->ledge.spawnId.value = (gameLocal->spawnIds.ptr[ledge->entityNumber] << 13) | ledge->entityNumber;
  else
    p_contextualShimmy->ledge.spawnId.value = 0x1FFF;
  if ( useLedge != nullptr )
    this->behaviors.contextualShimmy.useLedge.spawnId.value = (gameLocal->spawnIds.ptr[useLedge->entityNumber] << 13)
                                                            | useLedge->entityNumber;
  else
    this->behaviors.contextualShimmy.useLedge.spawnId.value = 0x1FFF;
  this->behaviors.contextualShimmy.currentLedgeBit = startLedgeBit;
  idPlayer::PlayerBehavior_ContextualShimmy_SetState(
    this,
    state: useLedge->mountType,
    startPosOverride: closestLedgePoint);
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_PostDismount@idPlayer@@QAAXXZ
// EA  : 0x82E44888
// RVA : 0x00E44888
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_PostDismount(idPlayer *this)
{
  idPlayer::idPlayerBehaviorContextualShimmy *p_contextualShimmy; // r29
  int value; // r9
  idUseLedge *v4; // r3
  int v5; // r9
  idGameLocal *v6; // r11
  idUseLedge *v7; // r3
  idUseLedge *v8; // r3
  int v9; // r9
  idEntity *v10; // r3
  idEntity *v11; // r31
  idPresentable *presentable; // r3
  const idAngles *v13; // r4
  idPhysics *Physics; // r3
  const idVec3 *v15; // r3
  _BYTE v16[48]; // [sp+50h] [-30h] BYREF

  p_contextualShimmy = &this->behaviors.contextualShimmy;
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
  value = this->behaviors.contextualShimmy.useLedge.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v4 = (idUseLedge *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v4 != nullptr && idUseLedge::CastTo(c: v4) != nullptr )
    {
      v5 = p_contextualShimmy->useLedge.spawnId.value;
      v6 = gameLocal;
      if ( gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13
        && (v7 = (idUseLedge *)gameLocal->entities.ptr[v5 & 0x1FFF]) != nullptr )
      {
        v8 = idUseLedge::CastTo(c: v7);
        v6 = gameLocal;
      }
      else
      {
        v8 = nullptr;
      }
      v9 = v8->endPositionEntity.spawnId.value;
      if ( v6->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 )
      {
        v10 = v6->entities.ptr[v9 & 0x1FFF];
        if ( v10 != nullptr )
        {
          v11 = idEntity::CastTo(c: v10);
          if ( v11 != nullptr )
          {
            presentable = this->presentable;
            if ( presentable != nullptr )
              v13 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
            else
              v13 = nullptr;
            idPresentablePlayer::GetViewAngles(this: (idPresentablePlayer *)v16, result: v13, includeWeaponKick: true);
            Physics = idEntity::GetPhysics(this: v11);
            v15 = Physics->GetOrigin(this: Physics, a2: 0);
            this->Teleport(this, a2: v15, a3: (const idAngles *)v16);
          }
        }
      }
    }
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_HandleEvent@idPlayer@@QAAXW4idPlayerBehaviorEvent_t@@@Z
// EA  : 0x82E44A30
// RVA : 0x00E44A30
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_HandleEvent(idPlayer *this, idPlayerBehaviorEvent_t event)
{
  idPlayer::idPlayerBehaviorContextualShimmy *p_contextualShimmy; // r30
  const char *v4; // r29
  int v5; // r3
  blendParms_t v6; // [sp+50h] [-60h] BYREF
  blendParms_t v7; // [sp+70h] [-40h] BYREF

  p_contextualShimmy = &this->behaviors.contextualShimmy;
  if ( event == PBE_BRANCHING_MELEE_START )
  {
    if ( this->behaviors.contextualShimmy.state == CONTEXTUAL_SHIMMY_STATE_NONE )
      return;
  }
  else
  {
    if ( event != PBE_SHIMMY_FORCE_END || this->behaviors.contextualShimmy.state == CONTEXTUAL_SHIMMY_STATE_NONE )
      return;
    idAlignedEntity::StopAnim(this: this->thirdPersonLegs);
  }
  if ( pb_cs_DebugTraceStates.valueInteger != 0 )
  {
    v4 = stateNames[0];
    v5 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(
      fmt: "^2(%d)%s - Setting shimmy state: %s\n",
      v5,
      "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
      v4);
  }
  blendParms_t::blendParms_t(this: &v7);
  blendParms_t::blendParms_t(this: &v6);
  blendParms_t::SetDuration(this: &v6, frame: pb_cs_AnimBlendFrames.valueInteger);
  p_contextualShimmy->state = CONTEXTUAL_SHIMMY_STATE_NONE;
  idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
    this,
    constrain: false,
    heading: nullptr,
    maxDeltaPitch: 0.0,
    maxDeltaYaw: 0.0,
    rate: 0.0);
  idPlayer::PlayerBehavior_Shared_AutoApplyThirdPersonLegsAnimDeltas(this, applyToPlayer: false, clip: false);
  idAnimator_Base::SetAlpha(this: &this->thirdPersonLegs->additiveSyncedAnimator, alpha: 0.0);
  idPlayer::idPlayerBehaviorContextualShimmy::Clear(this: p_contextualShimmy);
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_SwitchLedge@idPlayer@@QAAX_N@Z
// EA  : 0x82E44B58
// RVA : 0x00E44B58
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_SwitchLedge(idPlayer *this, bool bSecondPoint)
{
  int value; // r10
  idLedge *v5; // r3
  idLedge *v6; // r3
  int currentLedgeBit; // r5
  int flags; // r11
  const char *v9; // r30
  int v10; // r3
  const char *v11; // r30
  int v12; // r3
  const char *v13; // r30
  int v14; // r3
  int v15; // r11
  const char *v16; // r30
  int v17; // r3
  const char *v18; // r30
  int v19; // r3
  const char *v20; // r30
  int v21; // r3
  const char *v22; // r30
  int v23; // r3
  blendParms_t v24; // [sp+50h] [-60h] BYREF
  blendParms_t v25[3]; // [sp+70h] [-40h] BYREF

  value = this->behaviors.contextualShimmy.ledge.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = (idLedge *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idLedge::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  currentLedgeBit = this->behaviors.contextualShimmy.currentLedgeBit;
  if ( &v6->ledgeBits.list[currentLedgeBit] == nullptr )
  {
    idLib::Warning(
      fmt: "PlayerBehavior_ContextualShimmy_SwitchLedge ledge '%s' could not fetch ledgebit '%d'",
      v6->name.data,
      currentLedgeBit);
    return;
  }
  flags = v6->ledgeBits.list[currentLedgeBit].flags;
  if ( bSecondPoint )
  {
    if ( (flags & 0x80) != 0 )
    {
      this->behaviors.contextualShimmy.nextLedgeBit = currentLedgeBit + 1;
      if ( pb_cs_DebugTraceStates.valueInteger != 0 )
      {
        v9 = stateNames[18];
        v10 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "^2(%d)%s - Setting shimmy state: %s\n",
          v10,
          "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
          v9);
      }
LABEL_11:
      blendParms_t::blendParms_t(this: v25);
      blendParms_t::blendParms_t(this: &v24);
      blendParms_t::SetDuration(this: &v24, frame: pb_cs_AnimBlendFrames.valueInteger);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        animName: "shimmy/90_outside_corner_rgh",
        loop: false,
        durationMS: -1,
        blendParms: &v24,
        rateScale: pb_cs_MovementScale.valueFloat);
      this->behaviors.contextualShimmy.state = CONTEXTUAL_SHIMMY_STATE_SWITCH_OUT90RIGHT;
      return;
    }
    if ( (flags & 0x20) != 0 )
    {
      this->behaviors.contextualShimmy.nextLedgeBit = currentLedgeBit + 1;
      if ( pb_cs_DebugTraceStates.valueInteger != 0 )
      {
        v11 = stateNames[19];
        v12 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "^2(%d)%s - Setting shimmy state: %s\n",
          v12,
          "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
          v11);
      }
LABEL_15:
      blendParms_t::blendParms_t(this: v25);
      blendParms_t::blendParms_t(this: &v24);
      blendParms_t::SetDuration(this: &v24, frame: pb_cs_AnimBlendFrames.valueInteger);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        animName: "shimmy/90_outside_corner_lft",
        loop: false,
        durationMS: -1,
        blendParms: &v24,
        rateScale: pb_cs_MovementScale.valueFloat);
      this->behaviors.contextualShimmy.state = CONTEXTUAL_SHIMMY_STATE_SWITCH_OUT90LEFT;
      return;
    }
    if ( (flags & 0x10) != 0 )
    {
      this->behaviors.contextualShimmy.nextLedgeBit = currentLedgeBit + 1;
      if ( pb_cs_DebugTraceStates.valueInteger != 0 )
      {
        v13 = stateNames[21];
        v14 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "^2(%d)%s - Setting shimmy state: %s\n",
          v14,
          "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
          v13);
      }
LABEL_19:
      blendParms_t::blendParms_t(this: v25);
      blendParms_t::blendParms_t(this: &v24);
      blendParms_t::SetDuration(this: &v24, frame: pb_cs_AnimBlendFrames.valueInteger);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        animName: "shimmy/90_inside_corner_rgh",
        loop: false,
        durationMS: -1,
        blendParms: &v24,
        rateScale: pb_cs_MovementScale.valueFloat);
      this->behaviors.contextualShimmy.state = CONTEXTUAL_SHIMMY_STATE_SWITCH_IN90LEFT;
      return;
    }
    if ( (flags & 0x40) != 0 )
    {
      v15 = currentLedgeBit + 1;
LABEL_36:
      this->behaviors.contextualShimmy.nextLedgeBit = v15;
      if ( pb_cs_DebugTraceStates.valueInteger != 0 )
      {
        v22 = stateNames[20];
        v23 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "^2(%d)%s - Setting shimmy state: %s\n",
          v23,
          "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
          v22);
      }
      blendParms_t::blendParms_t(this: v25);
      blendParms_t::blendParms_t(this: &v24);
      blendParms_t::SetDuration(this: &v24, frame: pb_cs_AnimBlendFrames.valueInteger);
      idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
        this,
        animName: "shimmy/90_inside_corner_lft",
        loop: false,
        durationMS: -1,
        blendParms: &v24,
        rateScale: pb_cs_MovementScale.valueFloat);
      this->behaviors.contextualShimmy.state = CONTEXTUAL_SHIMMY_STATE_SWITCH_IN90RIGHT;
    }
  }
  else
  {
    if ( (flags & 2) != 0 )
    {
      this->behaviors.contextualShimmy.nextLedgeBit = currentLedgeBit - 1;
      if ( pb_cs_DebugTraceStates.valueInteger != 0 )
      {
        v16 = stateNames[19];
        v17 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "^2(%d)%s - Setting shimmy state: %s\n",
          v17,
          "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
          v16);
      }
      goto LABEL_15;
    }
    if ( (flags & 8) != 0 )
    {
      this->behaviors.contextualShimmy.nextLedgeBit = currentLedgeBit - 1;
      if ( pb_cs_DebugTraceStates.valueInteger != 0 )
      {
        v18 = stateNames[18];
        v19 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "^2(%d)%s - Setting shimmy state: %s\n",
          v19,
          "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
          v18);
      }
      goto LABEL_11;
    }
    if ( (flags & 1) != 0 )
    {
      this->behaviors.contextualShimmy.nextLedgeBit = currentLedgeBit - 1;
      if ( pb_cs_DebugTraceStates.valueInteger != 0 )
      {
        v20 = stateNames[21];
        v21 = gameLocal->GetGameFrame(this: gameLocal);
        idLib::Printf(
          fmt: "^2(%d)%s - Setting shimmy state: %s\n",
          v21,
          "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
          v20);
      }
      goto LABEL_19;
    }
    if ( (flags & 4) != 0 )
    {
      v15 = currentLedgeBit - 1;
      goto LABEL_36;
    }
  }
}


// ========================================================================
// ?PlayerBehavior_ContextualShimmy_Handle@idPlayer@@QAAXXZ
// EA  : 0x82E45168
// RVA : 0x00E45168
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_ContextualShimmy_Handle(idPlayer *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  __int64 v4; // r5
  idPresentable *presentable; // r3
  int v6; // r3
  char v7; // r11
  idPlayer::idPlayerBehaviorContextualShimmyState_t v8; // r11
  idPresentable *v9; // r3
  double valueFloat; // fp24
  int v11; // r3
  idPresentable *v12; // r11
  double v13; // fp25
  int v14; // r11
  int currentLedgeBit; // r30
  double v16; // fp30
  double v17; // fp29
  idLedge::idLedgeBit *v18; // r30
  double v19; // fp28
  double v20; // fp27
  double v21; // fp26
  idLedge *Entity; // r3
  idLedge::ledgeEdgeType_t PointOnLedge; // r3
  idPlayer::idPlayerBehaviorContextualShimmyState_t state; // r8
  idLedge::ledgeEdgeType_t v25; // r25
  idPresentable *v26; // r3
  int v27; // r11
  const idMD6Anim **v28; // r11
  const idMD6Anim *v29; // r8
  double v30; // fp1
  idPresentable *v31; // r3
  int v32; // r11
  const idMD6Anim **v33; // r11
  const idMD6Anim *v34; // r8
  idAlignedEntity *thirdPersonLegs; // r3
  const char *v36; // r30
  int v37; // r3
  int nextFidgetTime; // r30
  unsigned int v39; // r3
  unsigned int v40; // r11
  const char *v41; // r4
  int v42; // r30
  char v43; // r11
  char v44; // r10
  char v45; // r11
  const char *v46; // r30
  int v47; // r3
  const char *v48; // r30
  int v49; // r3
  idLedge *v50; // r3
  idLedge *v51; // r3
  char v52; // r11
  const char *v53; // r30
  int v54; // r3
  char v55; // r11
  const char *v56; // r30
  int v57; // r3
  idPresentable *v58; // r3
  idPresentablePlayer *v59; // r3
  const char *v60; // r30
  int v61; // r3
  idAlignedEntity *v62; // r11
  blendParms_t v63; // [sp+50h] [-110h] BYREF
  idPLogScope v64; // [sp+68h] [-F8h] BYREF
  blendParms_t v65; // [sp+70h] [-F0h] BYREF
  idVec3 v66[2]; // [sp+88h] [-D8h] BYREF
  playerExplicitMove_t v67; // [sp+A0h] [-C0h] BYREF

  RD_EventBegin(name: "idPlayer::PlayerBehavior_ContextualShimmy_Handle");
  LODWORD(v2) = "idPlayer::PlayerBehavior_ContextualShimmy_Handle";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v64, pl: &pLog, gMask: v2, label: v3);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v6 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v6 = 0;
  if ( (*(_BYTE *)(v6 + 47032) & 0x20) != 0 )
    goto _M496985_0;
  if ( pb_cs_Enable.valueInteger == 0 || (v7 = 1, !this->behaviors.contextualShimmy.bEnabled) )
    v7 = 0;
  if ( v7 != 0
    && (v8 = this->behaviors.contextualShimmy.state,
        v63.parms.srcAnim = (const idMD6Anim *)&this->behaviors.contextualShimmy,
        v8 != CONTEXTUAL_SHIMMY_STATE_NONE) )
  {
    v9 = this->presentable;
    valueFloat = pb_cs_InputDeadZone.valueFloat;
    if ( v9 != nullptr )
      v11 = (int)v9->GetPlayerInterface_2(this: v9);
    else
      v11 = 0;
    v12 = this->presentable;
    LODWORD(v4) = *(char *)(v11 + 46319);
    *(_QWORD *)&v63.parms.srcAnim = v4;
    v13 = (float)((float)v4 * (float)0.0078740157);
    if ( v12 != nullptr )
      v14 = (int)v12->GetPlayerInterface_2(this: v12);
    else
      v14 = 0;
    currentLedgeBit = this->behaviors.contextualShimmy.currentLedgeBit;
    v16 = 0.0;
    LODWORD(v4) = *(char *)(v14 + 46318);
    *(_QWORD *)&v63.parms.srcAnim = v4;
    v17 = (float)((float)v4 * (float)0.0078740157);
    v18 = &idEntityPtr<idLedge>::GetEntity(this: &this->behaviors.contextualShimmy.ledge)->ledgeBits.list[currentLedgeBit];
    v63.parms.srcAnim = (const idMD6Anim *)&v18->normal;
    v19 = (float)((float)(v18->normal.y * (float)0.0) - (float)(v18->normal.x * (float)0.0));
    v20 = (float)(v18->normal.x - (float)(v18->normal.z * (float)0.0));
    v21 = (float)((float)(v18->normal.z * (float)0.0) - v18->normal.y);
    Entity = idEntityPtr<idLedge>::GetEntity(this: &this->behaviors.contextualShimmy.ledge);
    PointOnLedge = idLedge::idLedgeBit::GetPointOnLedge(
                     this: v18,
                     player: this,
                     pointOut: v66,
                     bFlipped: (_cntlzw(Entity->ledgeNormalHint) & 0x20) != 0);
    state = this->behaviors.contextualShimmy.state;
    v25 = PointOnLedge;
    v63.parms.srcAnim = (const idMD6Anim *)&this->behaviors.contextualShimmy;
    this->behaviors.contextualShimmy.prevState = state;
    if ( state != CONTEXTUAL_SHIMMY_STATE_NONE )
    {
      v26 = this->presentable;
      if ( v26 != nullptr )
        v27 = (int)v26->GetPlayerInterface_2(this: v26);
      else
        v27 = 0;
      v28 = (const idMD6Anim **)(v27 + 46544);
      v29 = v28[1];
      v63.parms.srcAnim = *v28;
      *(float *)&v63.parms.sourceStartFrame = 0.0;
      v63.parms.destAnim = v29;
      v30 = idVec3::NormalizeFast(this: (idVec3 *)&v63);
      v31 = this->presentable;
      if ( v31 != nullptr )
        v32 = ((int (__fastcall *)(idPresentable *, double))v31->GetPlayerInterface_2)(a1: v31, a2: v30);
      else
        v32 = 0;
      v33 = (const idMD6Anim **)(v32 + 46556);
      v34 = v33[1];
      v65.parms.srcAnim = *v33;
      *(float *)&v65.parms.sourceStartFrame = 0.0;
      v65.parms.destAnim = v34;
      idVec3::NormalizeFast(this: (idVec3 *)&v65);
      v16 = (float)((float)((float)((float)((float)-v13 * *(float *)&v65.parms.sourceStartFrame)
                                  + (float)(*(float *)&v63.parms.sourceStartFrame * (float)v17))
                          * (float)-v19)
                  + (float)((float)((float)((float)(*(float *)&v65.parms.srcAnim * (float)-v13)
                                          + (float)(*(float *)&v63.parms.srcAnim * (float)v17))
                                  * (float)-v21)
                          + (float)((float)((float)(*(float *)&v65.parms.destAnim * (float)-v13)
                                          + (float)(*(float *)&v63.parms.destAnim * (float)v17))
                                  * (float)-v20)));
    }
    switch ( this->behaviors.contextualShimmy.state )
    {
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_0:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_0:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_BACK_0:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_90:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_90:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_180:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_180:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_INSIDESSHQ_CLIMBOUT:
      case CONTEXTUAL_SHIMMY_STATE_MOUNT_CUSTOMANIM:
      case CONTEXTUAL_SHIMMY_STATE_SWITCH_OUT90RIGHT:
      case CONTEXTUAL_SHIMMY_STATE_SWITCH_OUT90LEFT:
      case CONTEXTUAL_SHIMMY_STATE_SWITCH_IN90RIGHT:
      case CONTEXTUAL_SHIMMY_STATE_SWITCH_IN90LEFT:
        thirdPersonLegs = this->thirdPersonLegs;
        if ( !thirdPersonLegs->baseAnimInfo.startBlendOut
          && !idAlignedEntity::IsCurAnimDone(this: thirdPersonLegs, numFramesAhead: -1, ignoreQueuedAnims: false) )
        {
          break;
        }
        idPlayer::PlayerBehavior_ContextualShimmy_PostMount(this);
        goto LABEL_28;
      case CONTEXTUAL_SHIMMY_STATE_IDLE:
        nextFidgetTime = this->behaviors.contextualShimmy.nextFidgetTime;
        if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) <= nextFidgetTime )
          goto LABEL_42;
        if ( nextFidgetTime <= 0 )
          goto LABEL_41;
        blendParms_t::blendParms_t(this: &v65);
        blendParms_t::SetDuration(this: &v65, frame: pb_cs_IdleBlendFrames.valueInteger);
        v39 = 1664525 * clientGame->random.seed + 1013904223;
        clientGame->random.seed = v39;
        v40 = ((v39 >> 10) & 0x7FFF) - 3 * ((unsigned __int64)(1431655766LL * ((v39 >> 10) & 0x7FFF)) >> 32);
        if ( v40 != 0 )
        {
          if ( v40 == 1 )
          {
            v41 = "shimmy/idle_alt2";
          }
          else
          {
            if ( v40 >= 3 )
              goto LABEL_41;
            v41 = "shimmy/idle_alt3";
          }
        }
        else
        {
          v41 = "shimmy/idle_alt1";
        }
        idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
          this,
          animName: v41,
          loop: false,
          durationMS: -1,
          blendParms: &v65,
          rateScale: 1.0);
        idPlayer::PlayerBehavior_Shared_QueueThirdPersonLegsAnim(
          this,
          animName: "shimmy/idle",
          loop: true,
          durationMS: -1,
          blendParms: &v65,
          rateScale: 1.0);
LABEL_41:
        v42 = idRandom2::RandomInt(
                this: &clientGame->random,
                min: pb_cs_FidgetMinInterval.valueInteger,
                max: pb_cs_FidgetMaxInterval.valueInteger);
        this->behaviors.contextualShimmy.nextFidgetTime = v42
                                                        + gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
LABEL_42:
        if ( v25 == EDGETYPE_RIGHTEDGE || (v43 = 1, v25 == EDGETYPE_RIGHTEDGE_HASTURN) )
          v43 = 0;
        v44 = v43;
        if ( v25 == EDGETYPE_LEFTEDGE || (v45 = 1, v25 == EDGETYPE_LEFTEDGE_HASTURN) )
          v45 = 0;
        if ( v16 > valueFloat && v44 != 0 )
        {
          if ( pb_cs_DebugTraceStates.valueInteger != 0 )
          {
            v46 = stateNames[11];
            v47 = gameLocal->GetGameFrame(this: gameLocal);
            idLib::Printf(
              fmt: "^2(%d)%s - Setting shimmy state: %s\n",
              v47,
              "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
              v46);
          }
          blendParms_t::blendParms_t(this: &v63);
          blendParms_t::blendParms_t(this: &v65);
          blendParms_t::SetDuration(this: &v65, frame: pb_cs_AnimBlendFrames.valueInteger);
          if ( this->behaviors.contextualShimmy.state == CONTEXTUAL_SHIMMY_STATE_IDLE )
            blendParms_t::SetDuration(this: &v65, frame: pb_cs_IdleBlendFrames.valueInteger);
          goto LABEL_54;
        }
        if ( v16 < -valueFloat && v45 != 0 )
        {
          if ( pb_cs_DebugTraceStates.valueInteger != 0 )
          {
            v48 = stateNames[12];
            v49 = gameLocal->GetGameFrame(this: gameLocal);
            idLib::Printf(
              fmt: "^2(%d)%s - Setting shimmy state: %s\n",
              v49,
              "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
              v48);
          }
          blendParms_t::blendParms_t(this: &v63);
          blendParms_t::blendParms_t(this: &v65);
          blendParms_t::SetDuration(this: &v65, frame: pb_cs_AnimBlendFrames.valueInteger);
          if ( this->behaviors.contextualShimmy.state == CONTEXTUAL_SHIMMY_STATE_IDLE )
            blendParms_t::SetDuration(this: &v65, frame: pb_cs_IdleBlendFrames.valueInteger);
LABEL_61:
          idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
            this,
            animName: "shimmy/shimmy_left",
            loop: true,
            durationMS: -1,
            blendParms: &v65,
            rateScale: pb_cs_MovementScale.valueFloat);
          this->behaviors.contextualShimmy.state = CONTEXTUAL_SHIMMY_STATE_SHIMMY_LEFT;
        }
        else if ( v16 <= valueFloat || v44 != 0 || v25 != EDGETYPE_RIGHTEDGE_HASTURN )
        {
          if ( v16 < -valueFloat && v45 == 0 && v25 == EDGETYPE_LEFTEDGE_HASTURN )
          {
            v51 = idEntityPtr<idLedge>::GetEntity(this: &this->behaviors.contextualShimmy.ledge);
            idPlayer::PlayerBehavior_ContextualShimmy_SwitchLedge(
              this,
              bSecondPoint: (_cntlzw(v51->ledgeNormalHint) & 0x20) != 0);
          }
        }
        else
        {
          v50 = idEntityPtr<idLedge>::GetEntity(this: &this->behaviors.contextualShimmy.ledge);
          idPlayer::PlayerBehavior_ContextualShimmy_SwitchLedge(
            this,
            bSecondPoint: v50->ledgeNormalHint != LEDGETYPE_CLOCKWISE);
        }
        break;
      case CONTEXTUAL_SHIMMY_STATE_SHIMMY_RIGHT:
        if ( v25 == EDGETYPE_RIGHTEDGE || (v52 = 1, v25 == EDGETYPE_RIGHTEDGE_HASTURN) )
          v52 = 0;
        if ( v16 > valueFloat && v52 != 0 )
          break;
        if ( v16 >= -valueFloat || v52 == 0 )
          goto LABEL_28;
        if ( pb_cs_DebugTraceStates.valueInteger != 0 )
        {
          v53 = stateNames[12];
          v54 = gameLocal->GetGameFrame(this: gameLocal);
          idLib::Printf(
            fmt: "^2(%d)%s - Setting shimmy state: %s\n",
            v54,
            "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
            v53);
        }
        blendParms_t::blendParms_t(this: &v63);
        blendParms_t::blendParms_t(this: &v65);
        blendParms_t::SetDuration(this: &v65, frame: pb_cs_AnimBlendFrames.valueInteger);
        if ( this->behaviors.contextualShimmy.state == CONTEXTUAL_SHIMMY_STATE_IDLE )
          blendParms_t::SetDuration(this: &v65, frame: pb_cs_IdleBlendFrames.valueInteger);
        goto LABEL_61;
      case CONTEXTUAL_SHIMMY_STATE_SHIMMY_LEFT:
        if ( v25 == EDGETYPE_LEFTEDGE || (v55 = 1, v25 == EDGETYPE_LEFTEDGE_HASTURN) )
          v55 = 0;
        if ( v16 < -valueFloat && v55 != 0 )
          break;
        if ( v16 > valueFloat && v55 != 0 )
        {
          if ( pb_cs_DebugTraceStates.valueInteger != 0 )
          {
            v56 = stateNames[11];
            v57 = gameLocal->GetGameFrame(this: gameLocal);
            idLib::Printf(
              fmt: "^2(%d)%s - Setting shimmy state: %s\n",
              v57,
              "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
              v56);
          }
          blendParms_t::blendParms_t(this: &v63);
          blendParms_t::blendParms_t(this: &v65);
          blendParms_t::SetDuration(this: &v65, frame: pb_cs_AnimBlendFrames.valueInteger);
          if ( this->behaviors.contextualShimmy.state == CONTEXTUAL_SHIMMY_STATE_IDLE )
            blendParms_t::SetDuration(this: &v65, frame: pb_cs_IdleBlendFrames.valueInteger);
LABEL_54:
          idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
            this,
            animName: "shimmy/shimmy_right",
            loop: true,
            durationMS: -1,
            blendParms: &v65,
            rateScale: pb_cs_MovementScale.valueFloat);
          this->behaviors.contextualShimmy.state = CONTEXTUAL_SHIMMY_STATE_SHIMMY_RIGHT;
        }
        else
        {
LABEL_28:
          if ( pb_cs_DebugTraceStates.valueInteger != 0 )
          {
            v36 = stateNames[10];
            v37 = gameLocal->GetGameFrame(this: gameLocal);
            idLib::Printf(
              fmt: "^2(%d)%s - Setting shimmy state: %s\n",
              v37,
              "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
              v36);
          }
          blendParms_t::blendParms_t(this: &v63);
          blendParms_t::blendParms_t(this: &v65);
          blendParms_t::SetDuration(this: &v65, frame: pb_cs_AnimBlendFrames.valueInteger);
          blendParms_t::SetDuration(this: &v65, frame: pb_cs_IdleBlendFrames.valueInteger);
          idPlayer::PlayerBehavior_Shared_PlayThirdPersonLegsAnim(
            this,
            animName: "shimmy/idle",
            loop: true,
            durationMS: -1,
            blendParms: &v65,
            rateScale: 1.0);
          this->behaviors.contextualShimmy.nextFidgetTime = 0;
          this->behaviors.contextualShimmy.state = CONTEXTUAL_SHIMMY_STATE_IDLE;
        }
        break;
      case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_RIGHT:
      case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_FORWARD:
      case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_LEFT:
      case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_FALL:
      case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_CUSTOMANIM:
        if ( this->thirdPersonLegs->IsAnimating(this: this->thirdPersonLegs) )
          break;
        this->behaviors.contextualShimmy.dismountState = this->behaviors.contextualShimmy.state;
        idPlayer::PlayerBehavior_ContextualShimmy_PostDismount(this);
        v58 = this->presentable;
        v67.velocityType = VEL_EXPLICIT;
        v67.clipMove = true;
        v67.ignoreEntityNum = 0x1FFF;
        v67.delta.x = vec3_origin.x;
        v67.delta.y = vec3_origin.y;
        v67.delta.z = vec3_origin.z;
        v67.overrideVelocity.x = vec3_origin.x;
        v67.overrideVelocity.y = vec3_origin.y;
        v67.overrideVelocity.z = vec3_origin.z;
        if ( v58 != nullptr )
          v59 = v58->GetPlayerInterface_2(this: v58);
        else
          v59 = nullptr;
        idPresentablePlayer::SetExplicitMove(
          this: v59,
          move: &v67,
          alsoAllowPhysicsMove: false,
          useExplicitMove2: false);
        if ( pb_cs_DebugTraceStates.valueInteger != 0 )
        {
          v60 = stateNames[0];
          v61 = gameLocal->GetGameFrame(this: gameLocal);
          idLib::Printf(
            fmt: "^2(%d)%s - Setting shimmy state: %s\n",
            v61,
            "idPlayer::PlayerBehavior_ContextualShimmy_SetState",
            v60);
        }
        blendParms_t::blendParms_t(this: &v63);
        blendParms_t::blendParms_t(this: &v65);
        blendParms_t::SetDuration(this: &v65, frame: pb_cs_AnimBlendFrames.valueInteger);
        this->behaviors.contextualShimmy.state = CONTEXTUAL_SHIMMY_STATE_NONE;
        if ( this->behaviors.contextualShimmy.dismountState == CONTEXTUAL_SHIMMY_STATE_DISMOUNT_FALL )
          idPlayer::PlayerBehavior_PostEvent(this, event: PBE_FALL_LONG);
        v62 = this->thirdPersonLegs;
        v63.parms.srcAnim = (const idMD6Anim *)&this->behaviors.contextualShimmy;
        idAnimator_Base::SetAlpha(this: &v62->additiveSyncedAnimator, alpha: 0.0);
        idPlayer::idPlayerBehaviorContextualShimmy::Clear(this: &this->behaviors.contextualShimmy);
        idPLogScope::~idPLogScope(this: &v64);
        goto LABEL_104;
      default:
        break;
    }
    idPlayer::PlayerBehavior_ContextualShimmy_OrientToSurface(this);
    idPlayer::PlayerBehavior_ContextualShimmy_HandleMovement(this);
    idPlayer::PlayerBehavior_ContextualShimmy_HandleBodyRotation(this);
    idPlayer::PlayerBehavior_ContextualShimmy_HandleAdditiveAnims(this);
    idPlayer::PlayerBehavior_ContextualShimmy_DebugHandle(this);
    idPLogScope::~idPLogScope(this: &v64);
  }
  else
  {
_M496985_0:
    idPLogScope::~idPLogScope(this: &v64);
  }
LABEL_104:
  RD_EventEnd();
}


// ========================================================================
// __unwind$494928_0
// EA  : 0x82E45DA0
// RVA : 0x00E45DA0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void _unwind_494928_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 352 + 196));
}


// ========================================================================
// __unwind$494929_0
// EA  : 0x82E45DC8
// RVA : 0x00E45DC8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void _unwind_494929_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 352 + 104));
}


// ========================================================================
// `dynamic initializer for 'pb_cs_Enable''
// EA  : 0x8338C678
// RVA : 0x0138C678
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_Enable__()
{
  idCVar::idCVar(
    this: &pb_cs_Enable,
    name: "pb_cs_Enable",
    value: "1",
    flags: 1,
    description: "Enable player contextual shimmy behavior",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_Enable__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_Debug''
// EA  : 0x8338C6D0
// RVA : 0x0138C6D0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_Debug__()
{
  idCVar::idCVar(
    this: &pb_cs_Debug,
    name: "pb_cs_Debug",
    value: "0",
    flags: 1,
    description: "Debug player contextual shimmy behavior",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_Debug__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_DebugNoQueryUpdate''
// EA  : 0x8338C728
// RVA : 0x0138C728
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_DebugNoQueryUpdate__()
{
  idCVar::idCVar(
    this: &pb_cs_DebugNoQueryUpdate,
    name: "pb_cs_DebugNoQueryUpdate",
    value: "0",
    flags: 1,
    description: "Update the query or not",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_DebugNoQueryUpdate__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_DebugDrawShimmyPoint''
// EA  : 0x8338C780
// RVA : 0x0138C780
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_DebugDrawShimmyPoint__()
{
  idCVar::idCVar(
    this: &pb_cs_DebugDrawShimmyPoint,
    name: "pb_cs_DebugDrawShimmyPoint",
    value: "0",
    flags: 1,
    description: "Draw the shimmy coord system at the shimmy basepoint",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_DebugDrawShimmyPoint__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_DebugAdditiveAnims''
// EA  : 0x8338C7D8
// RVA : 0x0138C7D8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_DebugAdditiveAnims__()
{
  idCVar::idCVar(
    this: &pb_cs_DebugAdditiveAnims,
    name: "pb_cs_DebugAdditiveAnims",
    value: "0",
    flags: 1,
    description: "Debug additive anim behavior",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_DebugAdditiveAnims__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_UpTestOffset''
// EA  : 0x8338C830
// RVA : 0x0138C830
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_UpTestOffset__()
{
  idCVar::idCVar(
    this: &pb_cs_UpTestOffset,
    name: "pb_cs_UpTestOffset",
    value: "20",
    flags: 4,
    description: "How far above the current ground to test",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_UpTestOffset__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_ForwardTestDist''
// EA  : 0x8338C888
// RVA : 0x0138C888
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_ForwardTestDist__()
{
  idCVar::idCVar(
    this: &pb_cs_ForwardTestDist,
    name: "pb_cs_ForwardTestDist",
    value: "50",
    flags: 4,
    description: "How far forward to test the world",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_ForwardTestDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_ForwardTestBackupDist''
// EA  : 0x8338C8E0
// RVA : 0x0138C8E0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_ForwardTestBackupDist__()
{
  idCVar::idCVar(
    this: &pb_cs_ForwardTestBackupDist,
    name: "pb_cs_ForwardTestBackupDist",
    value: "20",
    flags: 4,
    description: "How far to back up the forward test rays",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_ForwardTestBackupDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_SideTestDist''
// EA  : 0x8338C938
// RVA : 0x0138C938
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_SideTestDist__()
{
  idCVar::idCVar(
    this: &pb_cs_SideTestDist,
    name: "pb_cs_SideTestDist",
    value: "10",
    flags: 4,
    description: "How far sideways or up to test for a shimmy",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_SideTestDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_SideTestDistMount''
// EA  : 0x8338C990
// RVA : 0x0138C990
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_SideTestDistMount__()
{
  idCVar::idCVar(
    this: &pb_cs_SideTestDistMount,
    name: "pb_cs_SideTestDistMount",
    value: "30",
    flags: 4,
    description: "How far sideways or up to test for a shimmy when looking for a mount",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_SideTestDistMount__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_ShiftIntoPositionDist''
// EA  : 0x8338C9E8
// RVA : 0x0138C9E8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_ShiftIntoPositionDist__()
{
  idCVar::idCVar(
    this: &pb_cs_ShiftIntoPositionDist,
    name: "pb_cs_ShiftIntoPositionDist",
    value: "5",
    flags: 4,
    description: "Error allowance for shifting into initial position",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_ShiftIntoPositionDist__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_LegsOffsetX''
// EA  : 0x8338CA40
// RVA : 0x0138CA40
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_LegsOffsetX__()
{
  idCVar::idCVar(
    this: &pb_cs_LegsOffsetX,
    name: "pb_cs_LegsOffsetX",
    value: "0.0",
    flags: 4,
    description: "Legs x offset from the hands position",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_LegsOffsetX__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_LegsOffsetY''
// EA  : 0x8338CA98
// RVA : 0x0138CA98
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_LegsOffsetY__()
{
  idCVar::idCVar(
    this: &pb_cs_LegsOffsetY,
    name: "pb_cs_LegsOffsetY",
    value: "0.0",
    flags: 4,
    description: "Legs y offset from the hands position",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_LegsOffsetY__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_LegsOffsetZ''
// EA  : 0x8338CAF0
// RVA : 0x0138CAF0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_LegsOffsetZ__()
{
  idCVar::idCVar(
    this: &pb_cs_LegsOffsetZ,
    name: "pb_cs_LegsOffsetZ",
    value: "0.0",
    flags: 4,
    description: "Legs z offset from the hands position",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_LegsOffsetZ__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_InputDeadZone''
// EA  : 0x8338CB48
// RVA : 0x0138CB48
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_InputDeadZone__()
{
  idCVar::idCVar(
    this: &pb_cs_InputDeadZone,
    name: "pb_cs_InputDeadZone",
    value: "0.1",
    flags: 4,
    description: "Dead zone for shimmy input",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_InputDeadZone__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_InitiateMaxAngle''
// EA  : 0x8338CBA0
// RVA : 0x0138CBA0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_InitiateMaxAngle__()
{
  idCVar::idCVar(
    this: &pb_cs_InitiateMaxAngle,
    name: "pb_cs_InitiateMaxAngle",
    value: "120",
    flags: 4,
    description: "Maximum angle in degrees between the shimmy normal and the player heading to interact with the shimmy",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_InitiateMaxAngle__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_InitiateInputTime''
// EA  : 0x8338CBF8
// RVA : 0x0138CBF8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_InitiateInputTime__()
{
  idCVar::idCVar(
    this: &pb_cs_InitiateInputTime,
    name: "pb_cs_InitiateInputTime",
    value: "200",
    flags: 2,
    description: "How long in ms to attempt interaction with shimmy before interaction begins",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_InitiateInputTime__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_AnimBlendFrames''
// EA  : 0x8338CC50
// RVA : 0x0138CC50
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_AnimBlendFrames__()
{
  idCVar::idCVar(
    this: &pb_cs_AnimBlendFrames,
    name: "pb_cs_AnimBlendFrames",
    value: "2",
    flags: 2,
    description: "Animation blend frames",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_AnimBlendFrames__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_IdleBlendFrames''
// EA  : 0x8338CCA8
// RVA : 0x0138CCA8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_IdleBlendFrames__()
{
  idCVar::idCVar(
    this: &pb_cs_IdleBlendFrames,
    name: "pb_cs_IdleBlendFrames",
    value: "5",
    flags: 2,
    description: "Idle animation blend frames",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_IdleBlendFrames__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_DebugTraceStates''
// EA  : 0x8338CD00
// RVA : 0x0138CD00
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_DebugTraceStates__()
{
  idCVar::idCVar(
    this: &pb_cs_DebugTraceStates,
    name: "pb_cs_DebugTraceStates",
    value: "0",
    flags: 1,
    description: "Trace the shimmy states",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_DebugTraceStates__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_MaxDeltaPitch''
// EA  : 0x8338CD58
// RVA : 0x0138CD58
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_MaxDeltaPitch__()
{
  idCVar::idCVar(
    this: &pb_cs_MaxDeltaPitch,
    name: "pb_cs_MaxDeltaPitch",
    value: "90",
    flags: 4,
    description: "Maximum delta pitch, relative to shimmy normal",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_MaxDeltaPitch__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_MaxDeltaPitchMount''
// EA  : 0x8338CDB0
// RVA : 0x0138CDB0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_MaxDeltaPitchMount__()
{
  idCVar::idCVar(
    this: &pb_cs_MaxDeltaPitchMount,
    name: "pb_cs_MaxDeltaPitchMount",
    value: "50",
    flags: 4,
    description: "Maximum delta pitch during mounting and dismounting, relative to shimmy normal",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_MaxDeltaPitchMount__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_MaxDeltaYaw''
// EA  : 0x8338CE08
// RVA : 0x0138CE08
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_MaxDeltaYaw__()
{
  idCVar::idCVar(
    this: &pb_cs_MaxDeltaYaw,
    name: "pb_cs_MaxDeltaYaw",
    value: "72.5",
    flags: 4,
    description: "Maximum delta yaw, relative to shimmy normal",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_MaxDeltaYaw__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_ConstrainedViewAnglesRate''
// EA  : 0x8338CE60
// RVA : 0x0138CE60
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_ConstrainedViewAnglesRate__()
{
  idCVar::idCVar(
    this: &pb_cs_ConstrainedViewAnglesRate,
    name: "pb_cs_ConstrainedViewAnglesRate",
    value: "40",
    flags: 4,
    description: "Rate for the entry into the constrained view range, if restriction is necessary (degs/sec)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_ConstrainedViewAnglesRate__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_EnableBodyRotation''
// EA  : 0x8338CEB8
// RVA : 0x0138CEB8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_EnableBodyRotation__()
{
  idCVar::idCVar(
    this: &pb_cs_EnableBodyRotation,
    name: "pb_cs_EnableBodyRotation",
    value: "1",
    flags: 1,
    description: "Enables additive anims to simulate body rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_EnableBodyRotation__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_BodyRotationBlendMS''
// EA  : 0x8338CF10
// RVA : 0x0138CF10
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_BodyRotationBlendMS__()
{
  idCVar::idCVar(
    this: &pb_cs_BodyRotationBlendMS,
    name: "pb_cs_BodyRotationBlendMS",
    value: "1",
    flags: 2,
    description: "blend duration for additive rotationanimations",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_BodyRotationBlendMS__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_DistToShimmySurface''
// EA  : 0x8338CF68
// RVA : 0x0138CF68
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_DistToShimmySurface__()
{
  idCVar::idCVar(
    this: &pb_cs_DistToShimmySurface,
    name: "pb_cs_DistToShimmySurface",
    value: "19.4",
    flags: 4,
    description: "Perpendicular distance between the shimmy surface and the origin of the third person legs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_DistToShimmySurface__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_AveragedNormalK''
// EA  : 0x8338CFC0
// RVA : 0x0138CFC0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_AveragedNormalK__()
{
  idCVar::idCVar(
    this: &pb_cs_AveragedNormalK,
    name: "pb_cs_AveragedNormalK",
    value: "80.0",
    flags: 4,
    description: "Spring constant for averaging the shimmy normal vector",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_AveragedNormalK__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_AveragedBodyRotationK''
// EA  : 0x8338D018
// RVA : 0x0138D018
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_AveragedBodyRotationK__()
{
  idCVar::idCVar(
    this: &pb_cs_AveragedBodyRotationK,
    name: "pb_cs_AveragedBodyRotationK",
    value: "4000.0",
    flags: 4,
    description: "Spring constant for averaging the body rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_AveragedBodyRotationK__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_ExtraWorldOffsetBlendK''
// EA  : 0x8338D070
// RVA : 0x0138D070
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_ExtraWorldOffsetBlendK__()
{
  idCVar::idCVar(
    this: &pb_cs_ExtraWorldOffsetBlendK,
    name: "pb_cs_ExtraWorldOffsetBlendK",
    value: "30.0",
    flags: 4,
    description: "Spring constant for smoothing the blend into or out of using the extra world offset",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_ExtraWorldOffsetBlendK__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_CameraSpringK''
// EA  : 0x8338D0C8
// RVA : 0x0138D0C8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_CameraSpringK__()
{
  idCVar::idCVar(
    this: &pb_cs_CameraSpringK,
    name: "pb_cs_CameraSpringK",
    value: "4000.0",
    flags: 4,
    description: "Spring constant for spring camera",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_CameraSpringK__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_ShootTimeLoseBalanceMS''
// EA  : 0x8338D120
// RVA : 0x0138D120
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_ShootTimeLoseBalanceMS__()
{
  idCVar::idCVar(
    this: &pb_cs_ShootTimeLoseBalanceMS,
    name: "pb_cs_ShootTimeLoseBalanceMS",
    value: "0.0",
    flags: 4,
    description: "How long player can shoot continuously before starting to lose balance (ms) (-1 to disable losing balance)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_ShootTimeLoseBalanceMS__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_ShootTimeRecoveryNoneMS''
// EA  : 0x8338D178
// RVA : 0x0138D178
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_ShootTimeRecoveryNoneMS__()
{
  idCVar::idCVar(
    this: &pb_cs_ShootTimeRecoveryNoneMS,
    name: "pb_cs_ShootTimeRecoveryNoneMS",
    value: "600.0",
    flags: 4,
    description: "How long player can shoot continuously and stay within the no recovery period (ms)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_ShootTimeRecoveryNoneMS__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_ShootTimeRecoverySmallMS''
// EA  : 0x8338D1D0
// RVA : 0x0138D1D0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_ShootTimeRecoverySmallMS__()
{
  idCVar::idCVar(
    this: &pb_cs_ShootTimeRecoverySmallMS,
    name: "pb_cs_ShootTimeRecoverySmallMS",
    value: "1200.0",
    flags: 4,
    description: "How long player can shoot continuously and stay within the small recovery period (ms)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_ShootTimeRecoverySmallMS__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_ShootTimeRecoveryMediumMS''
// EA  : 0x8338D228
// RVA : 0x0138D228
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_ShootTimeRecoveryMediumMS__()
{
  idCVar::idCVar(
    this: &pb_cs_ShootTimeRecoveryMediumMS,
    name: "pb_cs_ShootTimeRecoveryMediumMS",
    value: "1800.0",
    flags: 4,
    description: "How long player can shoot continuously and stay within the medium recovery period (ms)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_ShootTimeRecoveryMediumMS__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_ShootTimeNoReturnAnimMS''
// EA  : 0x8338D280
// RVA : 0x0138D280
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_ShootTimeNoReturnAnimMS__()
{
  idCVar::idCVar(
    this: &pb_cs_ShootTimeNoReturnAnimMS,
    name: "pb_cs_ShootTimeNoReturnAnimMS",
    value: "1800.0",
    flags: 4,
    description: "How long player can shoot continuously before 'no return' anim plays (ms)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_ShootTimeNoReturnAnimMS__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_ShootTimeRecoveryLargeMS''
// EA  : 0x8338D2D8
// RVA : 0x0138D2D8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_ShootTimeRecoveryLargeMS__()
{
  idCVar::idCVar(
    this: &pb_cs_ShootTimeRecoveryLargeMS,
    name: "pb_cs_ShootTimeRecoveryLargeMS",
    value: "2400.0",
    flags: 4,
    description: "How long player can shoot continuously and stay within the large recovery period (ms)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_ShootTimeRecoveryLargeMS__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_MovementScale''
// EA  : 0x8338D330
// RVA : 0x0138D330
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_MovementScale__()
{
  idCVar::idCVar(
    this: &pb_cs_MovementScale,
    name: "pb_cs_MovementScale",
    value: "1.3",
    flags: 4,
    description: "Timescale for movement animations",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_MovementScale__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_DisableFall''
// EA  : 0x8338D388
// RVA : 0x0138D388
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_DisableFall__()
{
  idCVar::idCVar(
    this: &pb_cs_DisableFall,
    name: "pb_cs_DisableFall",
    value: "0",
    flags: 1,
    description: "Disables the fall behavior",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_DisableFall__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_UseExtraWorldOffset''
// EA  : 0x8338D3E0
// RVA : 0x0138D3E0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_UseExtraWorldOffset__()
{
  idCVar::idCVar(
    this: &pb_cs_UseExtraWorldOffset,
    name: "pb_cs_UseExtraWorldOffset",
    value: "1",
    flags: 2,
    description: "Applies extra world offset to compensate the hands for the animated origin (0=off, 1=spring, 2=lock",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_UseExtraWorldOffset__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_ExtraWorldOffsetExitValue''
// EA  : 0x8338D438
// RVA : 0x0138D438
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_ExtraWorldOffsetExitValue__()
{
  idCVar::idCVar(
    this: &pb_cs_ExtraWorldOffsetExitValue,
    name: "pb_cs_ExtraWorldOffsetExitValue",
    value: "0.1",
    flags: 4,
    description: "Magnitude of extra world offset values before exiting from shimmy",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_ExtraWorldOffsetExitValue__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_OrientToSurface''
// EA  : 0x8338D490
// RVA : 0x0138D490
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_OrientToSurface__()
{
  idCVar::idCVar(
    this: &pb_cs_OrientToSurface,
    name: "pb_cs_OrientToSurface",
    value: "1",
    flags: 1,
    description: "Orient to the shimmy surface and smooth the shimmy path",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_OrientToSurface__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_AdditiveAnimBlendMS''
// EA  : 0x8338D4E8
// RVA : 0x0138D4E8
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_AdditiveAnimBlendMS__()
{
  idCVar::idCVar(
    this: &pb_cs_AdditiveAnimBlendMS,
    name: "pb_cs_AdditiveAnimBlendMS",
    value: "1",
    flags: 2,
    description: "blend duration for additive channel animator",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_AdditiveAnimBlendMS__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_Enable180Intos''
// EA  : 0x8338D540
// RVA : 0x0138D540
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_Enable180Intos__()
{
  idCVar::idCVar(
    this: &pb_cs_Enable180Intos,
    name: "pb_cs_Enable180Intos",
    value: "0",
    flags: 1,
    description: "enable the 180 degree intos",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_Enable180Intos__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_Enable90Intos''
// EA  : 0x8338D598
// RVA : 0x0138D598
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_Enable90Intos__()
{
  idCVar::idCVar(
    this: &pb_cs_Enable90Intos,
    name: "pb_cs_Enable90Intos",
    value: "1",
    flags: 1,
    description: "enable the 90 degree intos",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_Enable90Intos__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_FidgetMinInterval''
// EA  : 0x8338D5F0
// RVA : 0x0138D5F0
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_FidgetMinInterval__()
{
  idCVar::idCVar(
    this: &pb_cs_FidgetMinInterval,
    name: "pb_cs_FidgetMinInterval",
    value: "4000",
    flags: 2,
    description: "minimum interval between idle fidget animations (MS)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_FidgetMinInterval__);
}


// ========================================================================
// `dynamic initializer for 'pb_cs_FidgetMaxInterval''
// EA  : 0x8338D648
// RVA : 0x0138D648
// PDB : w:\tech5\tungsten\game\player\playerbehaviorcontextualshimmy.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pb_cs_FidgetMaxInterval__()
{
  idCVar::idCVar(
    this: &pb_cs_FidgetMaxInterval,
    name: "pb_cs_FidgetMaxInterval",
    value: "8000",
    flags: 2,
    description: "maximum interval between idle fidget animations (MS)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pb_cs_FidgetMaxInterval__);
}

