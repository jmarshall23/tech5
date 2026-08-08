
// ========================================================================
// ?PlayerBehavior_Takedown_IsInTakedown@idPlayer@@QBA_NXZ
// EA  : 0x82E4A3A8
// RVA : 0x00E4A3A8
// PDB : w:\tech5\tungsten\game\player\playerbehaviortakedown.cpp
// ========================================================================

BOOL __fastcall idPlayer::PlayerBehavior_Takedown_IsInTakedown(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  return (*(_BYTE *)(v3 + 47032) & 0x20) == 0 && this->behaviors.takedown.state != TAKEDOWNSTATE_NONE;
}


// ========================================================================
// ?PlayerBehavior_Takedown_StartTakedown@idPlayer@@QAAXPBDABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82E4A430
// RVA : 0x00E4A430
// PDB : w:\tech5\tungsten\game\player\playerbehaviortakedown.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Takedown_StartTakedown(
        idPlayer *this,
        const char *takedownName,
        const idVec3 *enemyPos,
        const idMat3 *enemyAxis)
{
  idPresentable *presentable; // r3
  int v9; // r3
  idWeapon *EquippedWeapon; // r3
  idWeapon *v11; // r3
  idAngles v12; // [sp+50h] [-70h] BYREF
  float v13[10]; // [sp+60h] [-60h] BYREF

  idPlayer::PlayerBehavior_Shared_PlayThirdPersonHandsAnim(
    this,
    animName: takedownName,
    loop: false,
    durationMS: -1,
    blendParms: nullptr,
    rateScale: 1.0);
  idLib::Printf(fmt: "starting %s on player\n", takedownName);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v9 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v9 = 0;
  idHands::Hide(this: (idHands *)(v9 + 37616), hideReason: HAND_HIDE_TAKEDOWN);
  EquippedWeapon = idActor::GetEquippedWeapon(this, slot: EQUIP_RIGHT_HAND);
  if ( EquippedWeapon != nullptr )
    idAlignedEntity::AttachItem(
      this: this->thirdPersonHands,
      decl: EquippedWeapon->decl,
      slotName: "rightHand",
      autoDetach: true,
      autoGive: false,
      noClone: true);
  v11 = idActor::GetEquippedWeapon(this, slot: EQUIP_LEFT_HAND);
  if ( v11 != nullptr )
    idAlignedEntity::AttachItem(
      this: this->thirdPersonHands,
      decl: v11->decl,
      slotName: "leftHand",
      autoDetach: true,
      autoGive: false,
      noClone: true);
  this->behaviors.takedown.state = TAKEDOWNSTATE_INTAKEDOWN;
  this->behaviors.takedown.enemyPosition.x = enemyPos->x;
  this->behaviors.takedown.enemyPosition.y = enemyPos->y;
  this->behaviors.takedown.enemyPosition.z = enemyPos->z;
  this->behaviors.takedown.enemyAxis.mat[0].x = enemyAxis->mat[0].x;
  this->behaviors.takedown.enemyAxis.mat[0].y = enemyAxis->mat[0].y;
  this->behaviors.takedown.enemyAxis.mat[0].z = enemyAxis->mat[0].z;
  this->behaviors.takedown.enemyAxis.mat[1].x = enemyAxis->mat[1].x;
  this->behaviors.takedown.enemyAxis.mat[1].y = enemyAxis->mat[1].y;
  this->behaviors.takedown.enemyAxis.mat[1].z = enemyAxis->mat[1].z;
  this->behaviors.takedown.enemyAxis.mat[2].x = enemyAxis->mat[2].x;
  this->behaviors.takedown.enemyAxis.mat[2].y = enemyAxis->mat[2].y;
  this->behaviors.takedown.enemyAxis.mat[2].z = enemyAxis->mat[2].z;
  idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsAlignNode(
    this,
    origin: &this->behaviors.takedown.enemyPosition,
    axis: &this->behaviors.takedown.enemyAxis);
  this->GetViewTransform(this, a2: (idVec3 *)&v12, a3: (idMat3 *)v13);
  v12.pitch = v13[0];
  v12.yaw = v13[1];
  v12.roll = v13[2];
  idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
    this,
    constrain: true,
    heading: &v12,
    maxDeltaPitch: 0.0,
    maxDeltaYaw: 0.0,
    rate: 0.0);
  idSpringCamera::InitDefaultSprings(this: this->springCamera);
  idSpringCamera::InitSprings(this: this->springCamera, k: 150.0);
  idAlignedEntity::AttachCamera(
    this: this->thirdPersonHands,
    jointName: "camera",
    durationMode: DURATION_ALWAYS,
    lookMode: LOOK_HEADING,
    blendMode: BLEND_SMOOTH_SNAP_SMOOTH,
    blendDurationMS: -1,
    viewConeDeg: 0.0,
    autoCenterK: 1.0);
}


// ========================================================================
// ?PlayerBehavior_Takedown_EndTakedown@idPlayer@@QAAXXZ
// EA  : 0x82E4A640
// RVA : 0x00E4A640
// PDB : w:\tech5\tungsten\game\player\playerbehaviortakedown.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Takedown_EndTakedown(idPlayer *this)
{
  idPhysics *Physics; // r3
  const idVec3 *v3; // r9
  idPresentable *presentable; // r3
  float y; // r7
  float z; // r6
  const idAngles *v7; // r4
  idPlayer_vtbl *v8; // r30
  idPresentablePlayer *ViewAngles; // r3
  idAlignedEntity *thirdPersonHands; // r3
  idPresentable *v11; // r3
  int v12; // r3
  _DWORD v13[4]; // [sp+50h] [-40h] BYREF
  char v14; // [sp+60h] [-30h] BYREF

  Physics = idEntity::GetPhysics(this: this->thirdPersonHands);
  v3 = Physics->GetOrigin(this: Physics, a2: 0);
  y = v3->y;
  z = v3->z;
  presentable = this->presentable;
  v13[0] = LODWORD(v3->x);
  *(float *)&v13[1] = y;
  *(float *)&v13[2] = z;
  if ( presentable != nullptr )
    v7 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v7 = nullptr;
  v8 = this->__vftable;
  ViewAngles = idPresentablePlayer::GetViewAngles(
                 this: (idPresentablePlayer *)&v14,
                 result: v7,
                 includeWeaponKick: true);
  v8->Teleport(this, a2: (const idVec3 *)v13, a3: (const idAngles *)ViewAngles);
  thirdPersonHands = this->thirdPersonHands;
  this->behaviors.takedown.state = TAKEDOWNSTATE_NONE;
  idAlignedEntity::DetachCamera(this: thirdPersonHands, instantBlend: false);
  v11 = this->presentable;
  if ( v11 != nullptr )
    v12 = (int)v11->GetPlayerInterface_2(this: v11);
  else
    v12 = 0;
  idHands::Show(this: (idHands *)(v12 + 37616), hideReason: HAND_HIDE_TAKEDOWN);
  idPlayer::PlayerBehavior_Shared_SetViewAnglesConstraint(
    this,
    constrain: false,
    heading: nullptr,
    maxDeltaPitch: 0.0,
    maxDeltaYaw: 0.0,
    rate: 0.0);
}


// ========================================================================
// ?PlayerBehavior_Takedown_Handle@idPlayer@@QAAXXZ
// EA  : 0x82E4A760
// RVA : 0x00E4A760
// PDB : w:\tech5\tungsten\game\player\playerbehaviortakedown.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Takedown_Handle(idPlayer *this)
{
  if ( this->behaviors.takedown.state != TAKEDOWNSTATE_NONE )
  {
    if ( this->thirdPersonHands->IsAnimating(this: this->thirdPersonHands) )
      idPlayer::PlayerBehavior_Shared_AlignThirdPersonHandsAlignNode(
        this,
        origin: &this->behaviors.takedown.enemyPosition,
        axis: &this->behaviors.takedown.enemyAxis);
    else
      idPlayer::PlayerBehavior_Takedown_EndTakedown(this);
  }
}


// ========================================================================
// ?PlayerBehavior_Takedown_Startup@idPlayer@@QAAXXZ
// EA  : 0x82E4A7E0
// RVA : 0x00E4A7E0
// PDB : w:\tech5\tungsten\game\player\playerbehaviortakedown.cpp
// ========================================================================

void __fastcall idPlayer::PlayerBehavior_Takedown_Startup(idPlayer *this)
{
  idAlignedEntity *thirdPersonHands; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r25
  idGameLocal *v3; // r11
  int v4; // r29
  int v5; // r31
  idList<idStr,5> *p_extraBehaviorAnimsToLoad; // r31
  int listStatic; // r11
  char v8; // [sp+50h] [-50h] BYREF

  thirdPersonHands = this->thirdPersonHands;
  if ( thirdPersonHands != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: thirdPersonHands);
    if ( TreeAnimatorFromPresentable != nullptr )
    {
      v3 = gameLocal;
      v4 = 0;
      if ( gameLocal->extraBehaviorAnimsToLoad.num > 0 )
      {
        v5 = 0;
        do
        {
          idDeclMD6::StrongLoadAlias(
            this: (idDeclMD6 *)&v8,
            result: TreeAnimatorFromPresentable->decl,
            aliasName: v3->extraBehaviorAnimsToLoad.list[v5].data);
          idLib::Printf(fmt: "Strongload %s\n", gameLocal->extraBehaviorAnimsToLoad.list[v5].data);
          v3 = gameLocal;
          ++v4;
          ++v5;
        }
        while ( v4 < gameLocal->extraBehaviorAnimsToLoad.num );
      }
      p_extraBehaviorAnimsToLoad = &v3->extraBehaviorAnimsToLoad;
      listStatic = v3->extraBehaviorAnimsToLoad.listStatic;
      if ( listStatic == 0 || listStatic == 2 )
      {
        if ( p_extraBehaviorAnimsToLoad->list != nullptr )
          idListArrayDelete<idStr>(ptr: p_extraBehaviorAnimsToLoad->list, num: p_extraBehaviorAnimsToLoad->size);
        p_extraBehaviorAnimsToLoad->list = nullptr;
        p_extraBehaviorAnimsToLoad->size = 0;
      }
      p_extraBehaviorAnimsToLoad->num = 0;
    }
  }
}

