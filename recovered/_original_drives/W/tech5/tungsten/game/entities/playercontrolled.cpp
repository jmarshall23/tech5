
// ========================================================================
// ?Use@idPlayerControlled@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C96238
// RVA : 0x00C96238
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

int __fastcall idPlayerControlled::Use(idPlayerControlled *this, idEntity *activator, const usableState_t usable)
{
  if ( usable == USABLE_PROP )
    this->OnActivate(this, a2: activator);
  return 1;
}


// ========================================================================
// ?Damage@idPlayerControlled@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82C96270
// RVA : 0x00C96270
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

float __fastcall idPlayerControlled::Damage(
        idPlayerControlled *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double _damageScale,
        const idVec3 *dir,
        trace_t *trace)
{
  idPlayer *playerUser; // r11
  double v8; // fp1

  playerUser = this->playerUser;
  if ( playerUser != nullptr )
    v8 = ((float (__fastcall *)(idPlayer *, idEntity *, idEntity *, const idDeclDamage *, double))playerUser->Damage)(
           a1: this->playerUser,
           a2: inflictor,
           a3: attacker,
           a4: damageDef,
           a5: (float)(this->damageScale * (float)_damageScale));
  else
    v8 = 0.0;
  return *((float *)&v8 + 1);
}


// ========================================================================
// ?Draw@idPlayerControlled@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82C962A8
// RVA : 0x00C962A8
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

int __fastcall idPlayerControlled::Draw(idPlayerControlled *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r11
  idView *v6; // r28
  int cameraTagIndex; // r5
  idMat3 *p_viewAxis; // r31
  idVec3 *p_viewOrigin; // r29
  idPhysics *Physics; // r3
  float *v11; // r3
  float y; // r8
  float z; // r9
  idAngles v15[8]; // [sp+60h] [-60h] BYREF

  presentable = player->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  v6 = (idView *)(v5 + 16224);
  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) == nullptr
    || (cameraTagIndex = this->cameraTagIndex) == -1 )
  {
    Physics = idEntity::GetPhysics(this);
    v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    p_viewOrigin = &this->viewOrigin;
    this->viewOrigin.x = *v11;
    this->viewOrigin.y = v11[1];
    this->viewOrigin.z = v11[2];
    this->viewAxis = *idAngles::ToMat3(this: v15, result: (idMat3 *)&this->viewAngles);
    p_viewAxis = &this->viewAxis;
  }
  else
  {
    p_viewAxis = &this->viewAxis;
    p_viewOrigin = &this->viewOrigin;
    idAnimatedEntity::GetTagPosition(
      this,
      propIndex: this->infoPropIndex,
      tagIndex: cameraTagIndex,
      origin: &this->viewOrigin,
      axis: &this->viewAxis);
  }
  idView::SetViewPos(this: v6, origin: p_viewOrigin, axis: p_viewAxis);
  y = vec3_origin.y;
  z = vec3_origin.z;
  v6->viewVelocity.x = vec3_origin.x;
  v6->viewVelocity.z = z;
  v6->viewVelocity.y = y;
  idView::SetViewID(this: v6, id: player->entityNumber + 1);
  idView::Render(this: v6);
  return 1;
}


// ========================================================================
// ?ModifyCrosshairInfo@idPlayerControlled@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C96428
// RVA : 0x00C96428
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

int __fastcall idPlayerControlled::ModifyCrosshairInfo(
        idPlayerControlled *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  idCrosshairCustomIcon *list; // r11

  if ( usable == USABLE_NOT_USABLE )
    return 0;
  if ( idPlayer::CastTo(c: activator) != nullptr )
  {
    list = info->icons.list;
    info->hideCrossHairInfo = false;
    list->usable = true;
  }
  return 1;
}


// ========================================================================
// ?OnActivate@idPlayerControlled@@UAAXPAVidEntity@@@Z
// EA  : 0x82C96498
// RVA : 0x00C96498
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void __fastcall idPlayerControlled::OnActivate(idPlayerControlled *this, idPlayer *activator)
{
  idPresentable *presentable; // r3
  int v4; // r3
  idPresentable *v5; // r3
  int v6; // r3
  idPresentable *v7; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r3
  idHandsItem *v11; // r3
  idPresentable *v12; // r3
  int v13; // r3
  idPresentable *v14; // r3
  int v15; // r3
  idPresentable *v16; // r3
  int v17; // r3
  idWeapon *v18; // r29
  idPresentable *v19; // r3
  int v20; // r3
  idWeapon *v21; // r30
  idFXManager *v22; // r3
  idPlayer *playerUser; // r11
  idAlignedEntity *thirdPersonHands; // r30
  idPresentable *v25; // r11
  idPresentable *v26; // r11
  idPlayer *v27; // r3
  idPresentable *v28; // r3
  int v29; // r3
  idPlayer *v30; // r11
  idPresentable *v31; // r3
  int v32; // r3
  idPresentable *v33; // r3
  int v34; // r3
  idPhysics *Physics; // r3
  float *v36; // r9
  idPlayer *v37; // r3
  idPhysics *v38; // r3
  idPhysics_Player *PhysicsObj; // r3
  idFaction *v40; // r3
  idPlayer *v41; // r4
  idAlignedEntity *v42; // r30
  idPresentable *v43; // r11
  idPresentable *v44; // r11
  float v45[6]; // [sp+50h] [-50h] BYREF

  if ( this->playerUser != nullptr )
  {
    idEntity::Unbind(this: this->playerUser);
    idPlayer::RemoveControl(this: this->playerUser, entity: this);
    this->playerUser->Show(this: this->playerUser);
    idPlayer::SetViewAngles(this: this->playerUser, angles: &this->viewAngles, force: true);
    presentable = this->playerUser->presentable;
    if ( presentable != nullptr )
      v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v4 = 0;
    if ( v4 != -37616 )
    {
      v5 = this->playerUser->presentable;
      v6 = v5 != nullptr ? (int)v5->GetPlayerInterface_2(this: v5) : 0;
      idHands::ClearPendingAction(this: (idHands *)(v6 + 37616));
      v7 = this->playerUser->presentable;
      v8 = v7 != nullptr ? (int)v7->GetPlayerInterface_2(this: v7) : 0;
      idHands::Show(this: (idHands *)(v8 + 37616), hideReason: HAND_HIDE_VEHICLE);
      v9 = this->playerUser->presentable;
      v10 = v9 != nullptr ? (int)v9->GetPlayerInterface_2(this: v9) : 0;
      v11 = idHands::ItemForSlot(this: (idHands *)(v10 + 37616), slot: EQUIP_RIGHT_HAND);
      idHandsItem::StopVideo(this: v11);
      v12 = this->playerUser->presentable;
      v13 = v12 != nullptr ? (int)v12->GetPlayerInterface_2(this: v12) : 0;
      idView::ResetControllerShake(this: (idView *)(v13 + 16224));
      v14 = this->playerUser->presentable;
      v15 = v14 != nullptr ? (int)v14->GetPlayerInterface_2(this: v14) : 0;
      *(float *)(v15 + 19128) = 0.0;
      v16 = this->playerUser->presentable;
      v17 = v16 != nullptr ? (int)v16->GetPlayerInterface_2(this: v16) : 0;
      v18 = idWeapon::CastTo(c: *(idWeapon **)(v17 + 42064));
      if ( v18 != nullptr )
      {
        v19 = this->playerUser->presentable;
        if ( v19 != nullptr )
          v20 = (int)v19->GetPlayerInterface_2(this: v19);
        else
          v20 = 0;
        v21 = idWeapon::CastTo(c: *(idWeapon **)(v20 + 42064));
        v22 = this->playerUser->GetFXMgrForAttachment(this: this->playerUser, a2: v18);
        idWeapon::SetZoomed(this: v21, zoomed: false, fxMgr: v22);
      }
    }
    playerUser = this->playerUser;
    thirdPersonHands = playerUser->thirdPersonHands;
    if ( thirdPersonHands != nullptr )
    {
      idEntity::Unbind(this: playerUser->thirdPersonHands);
      idAlignedEntity::StopAnim(this: thirdPersonHands);
      v25 = thirdPersonHands->presentable;
      thirdPersonHands->manualUpdate = true;
      if ( v25 == nullptr )
      {
        idEntity::InitPresentableInternal(this: thirdPersonHands);
        v25 = thirdPersonHands->presentable;
      }
      v25->model->useDeferredPosition = true;
      v26 = thirdPersonHands->presentable;
      if ( v26 == nullptr )
      {
        idEntity::InitPresentableInternal(this: thirdPersonHands);
        v26 = thirdPersonHands->presentable;
      }
      if ( !v26->hidden )
      {
        if ( v26 == nullptr )
        {
          idEntity::InitPresentableInternal(this: thirdPersonHands);
          v26 = thirdPersonHands->presentable;
        }
        v26->Hide(this: v26, a2: true);
      }
    }
    idAnimator_Channel::ClearAnimator(this: &this->leftArmAnimator);
    idAnimator_Channel::ClearAnimator(this: &this->specialAnimator);
    idAnimator_Channel::ClearAnimator(this: &this->targetAnimator);
    this->viewAngles.pitch = 0.0;
    this->UpdateModelTransform(this);
    this->playerUser = nullptr;
    this->currentFaction = nullptr;
  }
  else
  {
    v27 = idPlayer::CastTo(c: activator);
    this->playerUser = v27;
    if ( v27 != nullptr )
    {
      idEntity::BecomeActive(this, flags: 7);
      *(_BYTE *)(idPlayer::GetBobCycle(this: this->playerUser) + 216) = 0;
      v28 = this->playerUser->presentable;
      if ( v28 != nullptr )
        v29 = (int)v28->GetPlayerInterface_2(this: v28);
      else
        v29 = 0;
      *(idVec3 *)(v29 + 19044) = vec3_origin;
      *(idAngles *)(v29 + 19056) = ang_zero;
      if ( com_multiplayer.valueInteger == 0 )
        idPlayer::HideTutorialGui(this: this->playerUser);
      idPlayer::AddControl(this: this->playerUser, entity: this);
      this->playerUser->Hide_2(this: this->playerUser);
      v30 = this->playerUser;
      if ( v30 != nullptr )
      {
        v31 = v30->presentable;
        v32 = v31 != nullptr ? (int)v31->GetPlayerInterface_2(this: v31) : 0;
        if ( v32 != -37616 )
        {
          v33 = this->playerUser->presentable;
          if ( v33 != nullptr )
            v34 = (int)v33->GetPlayerInterface_2(this: v33);
          else
            v34 = 0;
          idHands::Hide(this: (idHands *)(v34 + 37616), hideReason: HAND_HIDE_VEHICLE);
        }
      }
      Physics = idEntity::GetPhysics(this);
      v36 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v37 = this->playerUser;
      v45[0] = *v36;
      v45[1] = v36[1];
      v45[2] = v36[2];
      v38 = idEntity::GetPhysics(this: v37);
      v38->SetOrigin(this: v38, a2: (const idVec3 *)v45, a3: -1);
      idEntity::Bind(this: this->playerUser, master: (idWorldspawn *)this, orientated: true);
      PhysicsObj = idPlayer::GetPhysicsObj(this: this->playerUser);
      idPhysics_Player::SetMovementType(this: PhysicsObj, type: PM_VEHICLE_NOCLIP);
      v40 = this->playerUser->GetFaction(this: this->playerUser);
      v41 = this->playerUser;
      this->currentFaction = v40;
      v42 = v41->thirdPersonHands;
      if ( v42 != nullptr && this->handsAnimMH.value != 0xFFFF )
      {
        idEntity::BindToTag(this: v42, master: (idWorldspawn *)this, tagName: "handsposition", orientated: true);
        idAlignedEntity::PlayAnim(
          this: v42,
          aliasHandle: &this->handsAnimMH,
          loop: true,
          durationMS: -1,
          _blendParms: nullptr,
          rateScale: 1.0);
        v43 = v42->presentable;
        v42->manualUpdate = false;
        if ( v43 == nullptr )
        {
          idEntity::InitPresentableInternal(this: v42);
          v43 = v42->presentable;
        }
        v43->model->useDeferredPosition = false;
        v44 = v42->presentable;
        if ( v44 == nullptr )
        {
          idEntity::InitPresentableInternal(this: v42);
          v44 = v42->presentable;
        }
        if ( v44->hidden )
        {
          if ( v44 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v42);
            v44 = v42->presentable;
          }
          v44->Show(this: v44);
        }
      }
    }
  }
}


// ========================================================================
// ?UpdateModelTransform@idPlayerControlled@@UAAXXZ
// EA  : 0x82C96A60
// RVA : 0x00C96A60
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void __fastcall idPlayerControlled::UpdateModelTransform(idPlayerControlled *this)
{
  idPresentable *presentable; // r31
  float roll; // r6
  float *v4; // r3
  idMat3 v5; // [sp+50h] [-90h] BYREF
  float v6; // [sp+74h] [-6Ch]
  float v7; // [sp+78h] [-68h]
  float v8; // [sp+7Ch] [-64h]
  float v9; // [sp+80h] [-60h]
  float v10; // [sp+84h] [-5Ch]
  float v11; // [sp+88h] [-58h]
  float v12; // [sp+8Ch] [-54h]
  float v13; // [sp+90h] [-50h]
  idAngles v14[3]; // [sp+A0h] [-40h] BYREF

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  this->GetModelTransform(this, a2: (idVec3 *)&v5.mat[1].y, a3: (idMat3 *)&v5.mat[2].z);
  roll = this->viewAngles.roll;
  v5.mat[0].y = this->viewAngles.yaw;
  v5.mat[0].x = 0.0;
  v5.mat[0].z = roll;
  v4 = (float *)idAngles::ToMat3(this: v14, result: &v5);
  v5.mat[2].z = *v4;
  v6 = v4[1];
  v7 = v4[2];
  v8 = v4[3];
  v9 = v4[4];
  v10 = v4[5];
  v11 = v4[6];
  v12 = v4[7];
  v13 = v4[8];
  presentable->origin.x = v5.mat[1].y;
  presentable->origin.y = v5.mat[1].z;
  presentable->origin.z = v5.mat[2].x;
  presentable->axis.mat[0].x = v5.mat[2].z;
  presentable->axis.mat[0].y = v6;
  presentable->axis.mat[0].z = v7;
  presentable->axis.mat[1].x = v8;
  presentable->axis.mat[1].y = v9;
  presentable->axis.mat[1].z = v10;
  presentable->axis.mat[2].x = v11;
  presentable->axis.mat[2].y = v12;
  presentable->axis.mat[2].z = v13;
  idPresentable::UpdateModelTransform(this: presentable);
  presentable->Present(this: presentable);
}


// ========================================================================
// ?GetVisibilityPoint@idPlayerControlled@@UBAXW4visPoint_t@@AAVidVec3@@@Z
// EA  : 0x82C96BC0
// RVA : 0x00C96BC0
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void __fastcall idPlayerControlled::GetVisibilityPoint(idPlayerControlled *this, const visPoint_t type, idVec3 *pos)
{
  idPhysics *Physics; // r3
  float *v5; // r3
  double z; // fp12
  idPhysics *v7; // r3
  int v8; // r3
  char *v9; // r10
  _DWORD *v10; // r11
  int i; // ctr
  double v12; // fp8
  double v13; // fp6
  char v14; // [sp+4Ch] [-34h] BYREF
  float v15; // [sp+50h] [-30h]
  float v16; // [sp+54h] [-2Ch]
  float v17; // [sp+58h] [-28h]
  float v18; // [sp+5Ch] [-24h]
  float v19; // [sp+60h] [-20h]
  float v20; // [sp+64h] [-1Ch]

  if ( type == VISPOINT_EYES )
  {
    pos->x = this->viewOrigin.x;
    pos->y = this->viewOrigin.y;
    z = this->viewOrigin.z;
    goto LABEL_8;
  }
  if ( type != VISPOINT_CENTER )
  {
    Physics = idEntity::GetPhysics(this);
    v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    pos->x = *v5;
    pos->y = v5[1];
    z = v5[2];
LABEL_8:
    pos->z = z;
    return;
  }
  v7 = idEntity::GetPhysics(this);
  v8 = (int)v7->GetAbsBounds(this: v7, a2: -1);
  v9 = &v14;
  v10 = (_DWORD *)(v8 - 4);
  for ( i = 6; i != 0; --i )
  {
    ++v10;
    v9 += 4;
    *(_DWORD *)v9 = *v10;
  }
  v12 = (float)(v16 + v19);
  v13 = (float)(v17 + v20);
  pos->x = (float)(v15 + v18) * (float)0.5;
  pos->y = (float)v12 * (float)0.5;
  pos->z = (float)v13 * (float)0.5;
}


// ========================================================================
// ?AnimEvent_EndMeleeTrace@idPlayerControlled@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82C96CC8
// RVA : 0x00C96CC8
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

idPlayerControlled *__fastcall idPlayerControlled::AnimEvent_EndMeleeTrace(
        idPlayerControlled *this,
        eventVoid *result,
        const idMD6Anim *anim)
{
  idRibbon::~idRibbon(this: (idRibbon *)&result[6856]);
  return this;
}


// ========================================================================
// ?AnimEvent_StartMeleeTraceTag@idPlayerControlled@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82C96D98
// RVA : 0x00C96D98
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

idPlayerControlled *__fastcall idPlayerControlled::AnimEvent_StartMeleeTraceTag(
        idPlayerControlled *this,
        idAnimatedEntity *result,
        const idMD6Anim *anim,
        const char *tag)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  float fadeVisibilityOver; // r11
  int v9; // r11
  int v10; // r30
  idPropsCollection *decl; // r11
  const tagData_t *v12; // r3
  const idDeclProjectileImpactEffect *v14; // [sp+8h] [-B8h]
  idVec3 v15; // [sp+60h] [-60h] BYREF
  tagData_t v16; // [sp+70h] [-50h] BYREF

  v16.parentJoint.value = -1;
  v16.trans.x = 0.0;
  v16.trans.y = 0.0;
  v16.trans.z = 0.0;
  v16.rot.x = 0.0;
  v16.rot.y = 0.0;
  v16.rot.z = 0.0;
  v16.rot.w = 0.0;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    fadeVisibilityOver = result[1].renderModelInfo.fadeVisibilityOver;
    if ( fadeVisibilityOver != 0.0 )
    {
      v9 = *(_DWORD *)(LODWORD(fadeVisibilityOver) + 504);
      if ( v9 != 0 )
      {
        v10 = *(_DWORD *)(v9 + 504);
        if ( v10 != 0 )
        {
          decl = (idPropsCollection *)TreeAnimatorFromPresentable->decl;
          if ( decl != nullptr && decl != (idPropsCollection *)-352 )
          {
            v12 = idPropsCollection::GetTag(this: decl + 22, propName: idPropInfo::INFO_PROP_NAME, tagName: tag);
            v16.trans.x = v12->trans.x;
            v16.trans.y = v12->trans.y;
            v16.trans.z = v12->trans.z;
            v16.rot.x = v12->rot.x;
            v16.rot.y = v12->rot.y;
            v16.rot.z = v12->rot.z;
            v16.rot.w = v12->rot.w;
            v16.parentJoint.value = v12->parentJoint.value;
          }
          if ( v16.parentJoint.value == 0xFFFF )
          {
            idLib::Warning(fmt: "AnimEvent_StartMeleeTraceTag::AnimEvent_StartMeleeTraceTag - could not get tag data");
            return this;
          }
          idMeleeTrace::Start(
            this: (idMeleeTrace *)&result[1].animStack.usedSnapshotNodes.staticList[81],
            startPos: &v15,
            tagData_: &v16,
            useWeaponAnimator_: false,
            numSamples_: 100,
            damageCap_: 100.0,
            meleeType_: *(const idMeleeTrace::meleeDamage_t *)(v10 + 248),
            bounds_: *(const idMeleeTrace::meleeBounds_t *)&result[1].renderModelInfo.editorModel.baseBuffer[16],
            damageDef_: *(const idDeclDamage **)&result[1].renderModelInfo.editorModel.baseBuffer[12],
            impactEffect_: v14);
        }
      }
    }
  }
  return this;
}


// ========================================================================
// ?UpdateMovementAnimator@idPlayerControlled@@AAAXXZ
// EA  : 0x82C96EE0
// RVA : 0x00C96EE0
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void __fastcall idPlayerControlled::UpdateMovementAnimator(idPlayerControlled *this)
{
  idVec3 *p_physicsObj; // r31
  idVec3 *v3; // r29
  idVec3 *v4; // r3
  float roll; // r10
  double y; // fp13
  double z; // fp12
  double v8; // fp10
  double v9; // fp30
  double v10; // fp9
  double v11; // fp31
  double v12; // fp28
  idVec3 *v13; // r3
  __int64 v14; // r10
  double v15; // fp31
  double v16; // fp0
  const idMD6Anim *movementAnim; // r11
  idMD6AnimData *animData; // r11
  int frameRate; // r29
  double v20; // fp30
  int v21; // r27
  int GameMs; // r28
  int PreviousGameMs; // r3
  __int128 v24; // r7
  long double v25; // fp2
  long double v26; // fp4
  long double v27; // fp2
  unsigned __int64 v28; // [sp+50h] [-90h] BYREF
  idVec3 v29; // [sp+60h] [-80h] BYREF
  _BYTE v30[16]; // [sp+70h] [-70h] BYREF
  idAngles v31[4]; // [sp+80h] [-60h] BYREF

  if ( this->movementAnim != nullptr )
  {
    p_physicsObj = (idVec3 *)&this->physicsObj;
    v3 = this->physicsObj.GetPushedLinearVelocity(this: &v28, result: &this->physicsObj, a3: 0);
    v4 = this->physicsObj.GetLinearVelocity(this: v30, result: p_physicsObj, a3: 0);
    roll = this->viewAngles.roll;
    y = v3->y;
    z = v3->z;
    v8 = v4->y;
    v9 = (float)(v4->x - v3->x);
    v10 = v4->z;
    v29.y = this->viewAngles.yaw;
    v29.x = 0.0;
    v29.z = roll;
    v11 = (float)((float)v8 - (float)y);
    v12 = (float)((float)v10 - (float)z);
    v13 = idAngles::ToForward(this: v31, result: &v29);
    HIDWORD(v14) = &unk_82200000;
    v16 = (float)((float)((float)((float)v9 * v13->x)
                        + (float)((float)(v13->z * (float)v12) + (float)(v13->y * (float)v11)))
                / this->physicsObj.walkSpeed);
    v15 = -1.5;
    if ( v16 >= -1.5 )
    {
      v15 = 1.5;
      if ( v16 <= 1.5 )
        v15 = v16;
    }
    movementAnim = this->movementAnim;
    LODWORD(v14) = movementAnim->animData;
    if ( (_DWORD)v14 != 0 )
      LODWORD(v14) = *(unsigned __int16 *)(v14 + 8);
    animData = movementAnim->animData;
    frameRate = 30;
    v28 = v14;
    v20 = (float)v14;
    if ( animData != nullptr )
      frameRate = animData->frameRate;
    v21 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    LODWORD(v24) = frameRate;
    DWORD2(v24) = GameMs - PreviousGameMs;
    *((double *)&v25 + 1) = v20;
    DWORD1(v24) = v21;
    *(double *)&v26 = (float)(__int64)v24;
    *((double *)&v26 + 1) = (float)((float)1.0 / (float)__SPAIR64__(0x82000000, v21));
    *(double *)&v25 = (float)((float)((float)((float)(__int64)v24
                                            * (float)((float)*(__int64 *)((char *)&v24 + 4)
                                                    * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, v21))))
                                    * (float)v15)
                            + this->movementAnimFrame);
    v28 = __PAIR64__(0x82000000, v21);
    v27 = fmod(dX: v25, dY: v26);
    this->movementAnimFrame = *(double *)&v27;
    if ( (float)*(double *)&v27 < 0.0 )
      this->movementAnimFrame = (float)v20 - (float)*(double *)&v27;
    this->movementLeaf.frame = this->movementAnimFrame;
  }
}


// ========================================================================
// ?PlayAnimOnTarget@idPlayerControlled@@QAAXABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@H_N@Z
// EA  : 0x82C97100
// RVA : 0x00C97100
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void __fastcall idPlayerControlled::PlayAnimOnTarget(
        idPlayerControlled *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *animAlias,
        unsigned int blendMS,
        const bool loop)
{
  int value; // r10
  idAI2 *v9; // r3
  idAI2 *v10; // r3
  idAnimator_Channel *p_targetAnimator; // r29
  idAnimStack *v12; // r30
  idGameTimeManager *v13; // r3
  __int64 v14; // r8
  int GameMs; // r3
  blendParms_t v16; // [sp+50h] [-B0h] BYREF
  idAnimatorParms_Base v17[2]; // [sp+70h] [-90h] BYREF

  value = this->specialAttackTarget.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v9 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v9 != nullptr )
      v10 = idAI2::CastTo(c: v9);
    else
      v10 = nullptr;
    p_targetAnimator = &this->targetAnimator;
    v12 = v10->GetAnimStack_2(this: v10);
    if ( !idAnimator_Base::IsInitialized(this: p_targetAnimator, animStack: v12) )
    {
      v17[0].animStack = v12;
      idStr::idStr(this: &v17[0].name, text: "override");
      v17[0].blendOp = BOP_LERP;
      v17[0].originBlend = ORIGINBLEND_BRANCH;
      v17[0].weightGroup = MD6_WEIGHTGROUP_ALL;
      v17[0].filterGroup = MD6_WEIGHTGROUP_ALL;
      v17[0].alpha = 0.0;
      v13 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_Base::Init(this: p_targetAnimator, gametimeManager: v13, parms: v17);
      idStr::FreeData(this: &v17[0].name);
    }
    blendParms_t::blendParms_t(this: &v16);
    blendParms_t::SetDestStartFrame(this: &v16, frame: 0);
    blendParms_t::SetDurationMS(this: &v16, ms: blendMS);
    v16.parms.originBlend = 1;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    if ( loop )
    {
      LODWORD(v14) = &v16;
      idAnimator_Channel::CycleAnim(
        this: p_targetAnimator,
        stack: v12,
        ah: animAlias,
        curTime: GameMs,
        rateScale: 1.0,
        leafStarted: v14,
        a7: nullptr);
    }
    else
    {
      idAnimator_Channel::PlayAnim(
        this: p_targetAnimator,
        stack: v12,
        ah: animAlias,
        curTime: GameMs,
        rateScale: 1.0,
        blendParms: (const blendParms_t *)HIDWORD(v14),
        blendOutDurationMS_: &v16,
        leafStarted: nullptr,
        a9: nullptr);
    }
  }
}


// ========================================================================
// __unwind$491859_0
// EA  : 0x82C972B4
// RVA : 0x00C972B4
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_491859_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 256 + 112));
}


// ========================================================================
// ?Spawn@idPlayerControlled@@QAAXXZ
// EA  : 0x82C974E8
// RVA : 0x00C974E8
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void __fastcall idPlayerControlled::Spawn(idPlayerControlled *this)
{
  idAngles *v2; // r3
  idPhysics_Player *p_physicsObj; // r30
  idClip *p_clip; // r4
  double y; // fp11
  double x; // fp10
  idClipModel *v7; // r3
  idClipModel *v8; // r28
  double v9; // fp11
  double z; // fp8
  int v11; // r5
  int v12; // r5
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v14; // r27
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r26
  int PropIndex; // r3
  int len; // r10
  const idDeclWeapon *weaponDecl; // r3
  idWeapon *v20; // r30
  idWeapon *v21; // r3
  __int16 *JointIndex; // r3
  idAnimStack *(__fastcall *GetAnimStack_2)(struct idPlayerControlled *); // r8
  idGameTimeManager *v24; // r3
  idGameTimeManager *v25; // r3
  idGameTimeManager *v26; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *p_animMovement; // r4
  const idMD6Anim *v28; // r3
  idMD6Leaf::wrapMode_t v29; // r5
  const idDeclMD6 *v30; // r23
  int num; // r6
  int v32; // r24
  int v33; // r12
  int v34; // r25
  idPlayerControlled::specialAttack_t *v35; // r30
  idTreeAnimator *v36; // r3
  __int16 v37; // r11
  const idMD6Alias *Alias; // r3
  const idMD6Anim *Existing; // r5
  double v40; // fp12
  double v41; // fp11
  double v42; // fp6
  double v43; // fp5
  double v44; // fp4
  double v45; // fp3
  idDeclMD6 *v46; // r3
  const char *data; // r5
  const idDeclMD6 *responseDecl; // r4
  idDeclMD6 *v49; // r3
  const char *v50; // r5
  const idDeclMD6 *v51; // r4
  int v52; // r28
  int v53; // r30
  _DWORD back_chain[20]; // [sp+0h] [-770h]
  idJointMat v55; // [sp+50h] [-720h] BYREF
  int v56; // [sp+84h] [-6ECh]
  int v57; // [sp+88h] [-6E8h]
  int v58; // [sp+8Ch] [-6E4h]
  int v59; // [sp+90h] [-6E0h]
  float v60; // [sp+94h] [-6DCh]
  idBounds v61; // [sp+A0h] [-6D0h] BYREF
  float v62[12]; // [sp+C0h] [-6B0h] BYREF
  idMat3 v63[43]; // [sp+F0h] [-680h] BYREF

  v2 = idMat3::ToAngles(this: v63, result: (idAngles *)&this->spawnOrientation);
  this->viewAngles.pitch = v2->pitch;
  p_physicsObj = &this->physicsObj;
  this->viewAngles.yaw = v2->yaw;
  p_clip = &clientGame->clip;
  this->viewAngles.roll = v2->roll;
  LODWORD(v55.mat[0]) = &this->viewAngles;
  idPhysics::InitPhysics(
    this: &this->physicsObj,
    clip_: p_clip,
    callbacks_: &this->physicsCallbacks,
    entityNumber_: this->entityNumber);
  y = this->clipModelInfo.size.y;
  x = this->clipModelInfo.size.x;
  v61.b[1].z = this->clipModelInfo.size.z;
  v61.b[0].z = 0.0;
  v61.b[0].x = (float)x * (float)-0.5;
  v61.b[1].x = (float)x * (float)0.5;
  this->physicsObj.pusher = &clientGame->push;
  v61.b[0].y = (float)y * (float)-0.5;
  v61.b[1].y = (float)y * (float)0.5;
  idTraceModel::InitBox(this: (idTraceModel *)&v63[0].mat[1].y);
  idTraceModel::SetupBox(this: (idTraceModel *)&v63[0].mat[1].y, boxBounds: &v61);
  v7 = (idClipModel *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0xD8u,
                        tag: TAG_CLIPMODEL,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  LODWORD(v55.mat[0]) = v7;
  if ( v7 != nullptr )
    v8 = idClipModel::idClipModel(
           this: v7,
           clip: &clientGame->clip,
           trm: (const idTraceModel *)&v63[0].mat[1].y,
           numTraceModels: 1,
           material: nullptr);
  else
    v8 = nullptr;
  idClipModel::SetContents(this: v8, newContents: 2129920);
  idClipModel::Unlink(this: v8);
  v9 = v8->origin.y;
  v8->origin.x = v8->origin.x + this->spawnPosition.x;
  z = v8->origin.z;
  v8->origin.y = this->spawnPosition.y + (float)v9;
  v8->origin.z = this->spawnPosition.z + (float)z;
  idPhysics_Player::SetClipModelStanding(this: &this->physicsObj, clipModel: v8);
  idPhysics_Actor::SetClipModel(this: &this->physicsObj, model: v8, density: 0.0049999999, id: v11, freeOld: 0, a6: 1);
  ((void (__fastcall *)(idPhysics_Player *, double))p_physicsObj->SetMass)(a1: &this->physicsObj, a2: this->mass);
  idPhysics_Player::SetClientCrouch(this: &this->physicsObj, crouch: false);
  p_physicsObj->SetContents(this: &this->physicsObj, a2: 2261120, a3: -1);
  p_physicsObj->SetClipMask(this: &this->physicsObj, a2: 107529, a3: -1);
  p_physicsObj->SetGravity(this: &this->physicsObj, a2: &gameLocal->clientGame.gravity);
  idPhysics_Actor::SetClipModelAxis(this: &this->physicsObj);
  p_physicsObj->EnableClip(this: &this->physicsObj);
  p_physicsObj->SetLinearVelocity(this: &this->physicsObj, a2: &vec3_origin, a3: 0);
  idEntity::SetPhysics(this, phys: &this->physicsObj, a3: v12);
  p_physicsObj->SetOrigin(this: &this->physicsObj, a2: &this->spawnPosition, a3: -1);
  idPhysics_Player::SetSpeed(this: &this->physicsObj, newWalkSpeed: this->speed, newCrouchSpeed: this->speed);
  idPhysics_Player::SetMaxStepHeight(this: &this->physicsObj, newMaxStepHeight: pm_stepsize.valueFloat);
  idEntity::BecomeInactive(this, flags: 7);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  v14 = TreeAnimatorFromPresentable;
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    idTreeAnimator::SetRemoveOriginRotation(this: TreeAnimatorFromPresentable, removeRotation: true);
    idTreeAnimator::SetRemoveOriginRotation(this: v14, removeRotation: true);
    decl = v14->decl;
    v14->useDeferredPosition = false;
    if ( decl != nullptr )
    {
      p_props = &decl->props;
      if ( decl != (const idDeclMD6 *)-352 )
      {
        PropIndex = idPropsCollection::FindPropIndex(this: p_props, propName: idPropInfo::INFO_PROP_NAME);
        len = this->cameraTagName.len;
        this->infoPropIndex = PropIndex;
        if ( len != 0 )
          this->cameraTagIndex = idPropsCollection::FindTagIndex(
                                   this: p_props,
                                   propIdx: PropIndex,
                                   tagName: this->cameraTagName.data);
        weaponDecl = this->primaryWeapon.weaponDecl;
        if ( weaponDecl != nullptr )
        {
          v20 = (idWeapon *)idInventoryItem::Create(decl: weaponDecl);
          v21 = idWeapon::CastTo(c: v20);
          this->primaryWeapon.weapon = v21;
          if ( v21 == nullptr && v20 != nullptr )
            ((void (__fastcall *)(idWeapon *, int))v20->dtr_idClass)(a1: v20, a2: 1);
          if ( this->primaryWeapon.muzzleTagName.len != 0 )
            this->primaryWeapon.weaponTagIndexPrimary = idPropsCollection::FindTagIndex(
                                                          this: p_props,
                                                          propIdx: this->infoPropIndex,
                                                          tagName: this->primaryWeapon.muzzleTagName.data);
        }
      }
    }
    JointIndex = (__int16 *)idTreeAnimator::GetJointIndex(
                              this: (idTreeAnimator *)&v55.mat[1],
                              result: (idIndex<short,enum invalidJointIndex_t> *)v14,
                              jointName: this->pitchJoint.data);
    GetAnimStack_2 = this->GetAnimStack_2;
    this->pitchJointIndex.value = *JointIndex;
    LODWORD(v55.mat[4]) = GetAnimStack_2(this);
    idStr::idStr(this: (idStr *)&v55.mat[5], text: "movement");
    v57 = 0;
    v58 = 0;
    v56 = 1;
    v59 = 0;
    v60 = 1.0;
    v24 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(
      this: &this->movementAnimator,
      gametimeManager: v24,
      parms: (const idAnimatorParms_Base *)&v55.mat[4]);
    v60 = 0.0;
    idStr::operator=(this: (idStr *)&v55.mat[5], text: "leftArm");
    v58 = 1;
    v59 = 1;
    v25 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(
      this: &this->leftArmAnimator,
      gametimeManager: v25,
      parms: (const idAnimatorParms_Base *)&v55.mat[4]);
    idStr::operator=(this: (idStr *)&v55.mat[5], text: "special");
    v58 = 0;
    v59 = 0;
    v26 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(
      this: &this->specialAnimator,
      gametimeManager: v26,
      parms: (const idAnimatorParms_Base *)&v55.mat[4]);
    p_animMovement = &this->animMovement;
    if ( this->animMovement.value != 0xFFFF )
    {
      LODWORD(v55.mat[0]) = v14->decl;
      if ( LODWORD(v55.mat[0]) != 0 )
      {
        v28 = idDeclMD6::AnimForAlias(this: (idDeclMD6 *)LODWORD(v55.mat[0]), aliasHandle: p_animMovement, load: false);
        this->movementAnim = v28;
        idTreeAnimator::SetFrameFromAnim(
          this: v14,
          anim: v28,
          frame: 0,
          updateRenderModel: true,
          checkForOriginTranslation: false,
          translationScale: nullptr);
        this->movementAnimFrame = 0.0;
        idMD6LeafPause::Init(
          this: &this->movementLeaf,
          anim: this->movementAnim,
          frame: 0.0,
          wrapMode: v29,
          weightGroup: MD6_WEIGHTGROUP_LEGS,
          a6: 0);
        idAnimator_Proxy::SetTree(this: &this->movementAnimator, tree: &this->movementLeaf);
      }
    }
    v30 = v14->decl;
    if ( v30 != nullptr && this->specialAttacks.num != 0 )
    {
      idTreeAnimator::NumJoints(this: v14);
      ((void (*)(void))RtlCheckStack12)();
      num = this->specialAttacks.num;
      v32 = 0;
      *(_DWORD *)((char *)back_chain + v33) = back_chain[0];
      if ( num > 0 )
      {
        v34 = 0;
        do
        {
          v35 = &this->specialAttacks.list[v34];
          v36 = idTreeAnimator::GetJointIndex(
                  this: (idTreeAnimator *)&v55.mat[1],
                  result: (idIndex<short,enum invalidJointIndex_t> *)v14,
                  jointName: v35->attachJoint.data);
          v37 = HIWORD(v36->__vftable);
          v35->attachJointIndex.value = HIWORD(v36->__vftable);
          if ( v37 >= 0 && v35->responseDecl != nullptr )
          {
            Alias = idDeclMD6::FindAlias(this: v14->decl, aliasHandle: &v35->attackAnim, includeInherited: true);
            if ( Alias != nullptr )
            {
              Existing = (const idMD6Anim *)idResourceList::FindExisting(
                                              this: &idMD6Anim::resourceList,
                                              name: (char *)Alias->animRefs.list->str,
                                              skipStaleCheck: false);
              if ( Existing != nullptr )
              {
                v35->initialized = true;
                idMD6Model::GetJointsForAnimFrame(
                  this: v30->model,
                  joints: &v55,
                  anim: Existing,
                  frame: 0,
                  offset: &vec3_origin,
                  removeOriginOffset: false);
                memcpy(Dst: v62, Src: &v55 + v35->attachJointIndex.value, Size: sizeof(v62));
                v35->attachAxis.mat[0].x = v62[0];
                v40 = v62[1];
                v41 = v62[2];
                v35->attachAxis.mat[1].x = v62[4];
                v35->attachAxis.mat[0].y = v40;
                v35->attachAxis.mat[0].z = v41;
                LODWORD(v55.mat[0]) = &v35->attachAxis.mat[2];
                v35->attachAxis.mat[1].y = v62[5];
                v35->attachAxis.mat[1].z = v62[6];
                v35->attachAxis.mat[2].x = v62[8];
                v42 = v62[10];
                v35->attachAxis.mat[2].y = v62[9];
                v43 = v62[3];
                v44 = v62[7];
                v45 = v62[11];
                v35->attachAxis.mat[2].z = v42;
                v35->attachOffset.x = v43;
                v35->attachOffset.y = v44;
                v35->attachOffset.z = v45;
              }
            }
            v46 = idDeclMD6::StrongLoadAlias(
                    this: (idDeclMD6 *)&v55.mat[2],
                    result: v35->responseDecl,
                    aliasName: v35->responseAnim.data);
            data = v35->responseAnimMH.data;
            responseDecl = v35->responseDecl;
            v35->responseHandle.value = HIWORD(v46->__vftable);
            v49 = idDeclMD6::StrongLoadAlias(
                    this: (idDeclMD6 *)((char *)&v55.mat[2] + 2),
                    result: responseDecl,
                    aliasName: data);
            v50 = v35->responseKillAnim.data;
            v51 = v35->responseDecl;
            v35->responseHandleMH.value = HIWORD(v49->__vftable);
            v35->responseKillAnimHandle.value = HIWORD(idDeclMD6::StrongLoadAlias(
                                                         this: (idDeclMD6 *)((char *)&v55.mat[1] + 2),
                                                         result: v51,
                                                         aliasName: v50)->__vftable);
          }
          ++v32;
          ++v34;
        }
        while ( v32 < this->specialAttacks.num );
      }
    }
    v52 = 0;
    if ( this->specialAttacks.num > 0 )
    {
      v53 = 0;
      do
      {
        if ( !this->specialAttacks.list[v53].initialized )
        {
          idLib::Warning(
            fmt: "idPlayerControlled::Spawn Removing a special attack because it couldn't initialize",
            p_animMovement);
          idList<idPlayerControlled::specialAttack_t,5>::RemoveIndex(this: &this->specialAttacks, index: v52--);
          --v53;
        }
        ++v52;
        ++v53;
      }
      while ( v52 < this->specialAttacks.num );
    }
    idStr::FreeData(this: (idStr *)&v55.mat[5]);
  }
}


// ========================================================================
// __unwind$492454
// EA  : 0x82C97C90
// RVA : 0x00C97C90
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_492454()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1904 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$492455
// EA  : 0x82C97CBC
// RVA : 0x00C97CBC
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_492455()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 1904 + 96));
}


// ========================================================================
// ??0idPlayerControlled@@QAA@XZ
// EA  : 0x82C97D58
// RVA : 0x00C97D58
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

idPlayerControlled *__fastcall idPlayerControlled::idPlayerControlled(idPlayerControlled *this)
{
  float *p_z; // r8
  float *p_y; // r9
  int v4; // ctr
  float w; // r9

  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idPlayerControlled_vtbl *)&idPlayerControlled::`vftable';
  this->cameraTagName.len = 0;
  this->cameraTagName.allocedAndFlag = 20;
  this->cameraTagName.data = this->cameraTagName.baseBuffer;
  this->cameraTagName.baseBuffer[0] = 0;
  this->mass = 185.0;
  this->damageScale = 1.0;
  this->speed = 200.0;
  this->primaryWeapon.weaponDecl = nullptr;
  this->primaryWeapon.muzzleTagName.allocedAndFlag = 20;
  this->primaryWeapon.muzzleTagName.data = this->primaryWeapon.muzzleTagName.baseBuffer;
  this->primaryWeapon.muzzleTagName.len = 0;
  this->primaryWeapon.muzzleTagName.baseBuffer[0] = 0;
  this->primaryWeapon.secondarymuzzleTagName.allocedAndFlag = 20;
  this->primaryWeapon.secondarymuzzleTagName.data = this->primaryWeapon.secondarymuzzleTagName.baseBuffer;
  this->primaryWeapon.secondarymuzzleTagName.len = 0;
  this->primaryWeapon.secondarymuzzleTagName.baseBuffer[0] = 0;
  this->primaryWeapon.weapon = nullptr;
  this->primaryWeapon.weaponTagIndexPrimary = -1;
  this->primaryWeapon.weaponTagIndexSecondary = -1;
  this->primaryWeapon.inSecondaryMode = false;
  this->secondaryWeapon.weaponDecl = nullptr;
  this->secondaryWeapon.muzzleTagName.allocedAndFlag = 20;
  this->secondaryWeapon.muzzleTagName.len = 0;
  this->secondaryWeapon.muzzleTagName.data = this->secondaryWeapon.muzzleTagName.baseBuffer;
  this->secondaryWeapon.muzzleTagName.baseBuffer[0] = 0;
  this->secondaryWeapon.secondarymuzzleTagName.allocedAndFlag = 20;
  this->secondaryWeapon.secondarymuzzleTagName.data = this->secondaryWeapon.secondarymuzzleTagName.baseBuffer;
  this->secondaryWeapon.secondarymuzzleTagName.len = 0;
  this->secondaryWeapon.secondarymuzzleTagName.baseBuffer[0] = 0;
  this->secondaryWeapon.weapon = nullptr;
  this->secondaryWeapon.weaponTagIndexPrimary = -1;
  this->secondaryWeapon.weaponTagIndexSecondary = -1;
  this->secondaryWeapon.inSecondaryMode = false;
  this->animMovement.value = -1;
  this->animAttacks.list = nullptr;
  this->animAttacks.granularity = 0;
  this->animAttacks.memTag = 5;
  this->animAttacks.listStatic = 0;
  this->animAttacks.size = 0;
  this->animAttacks.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animAttacks);
  this->specialAttacks.granularity = 0;
  this->specialAttacks.memTag = 5;
  this->specialAttacks.listStatic = 0;
  this->specialAttacks.list = nullptr;
  this->specialAttacks.size = 0;
  this->specialAttacks.num = 0;
  this->handsAnimMH.value = -1;
  idStr::idStr(this: &this->pitchJoint, text: "base");
  this->currentFaction = nullptr;
  idPhysics_Player::idPhysics_Player(this: &this->physicsObj);
  idMeleeTrace::idMeleeTrace(this: &this->meleeTrace);
  idAnimator_Proxy::idAnimator_Proxy(this: &this->movementAnimator);
  idMD6LeafPause::idMD6LeafPause(this: &this->movementLeaf);
  idAnimator_Channel::idAnimator_Channel(this: &this->leftArmAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->specialAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->targetAnimator);
  p_z = &this->viewOrigin.z;
  p_y = &mat2_identity.mat[1].y;
  v4 = 9;
  this->viewOrigin = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v4;
  }
  while ( v4 != 0 );
  this->viewAngles = ang_zero;
  this->specialAttackStartPos = vec3_origin;
  this->specialAttackStartRotation = quat_identity;
  this->aiAttackStartPos = vec3_origin;
  this->aiAttackStartRotation = quat_identity;
  this->specialAttackTargetPos = vec3_origin;
  this->specialAttackTargetRotation = quat_identity;
  this->aiAttackTargetPos = vec3_origin;
  this->aiAttackTargetRotation.x = quat_identity.x;
  this->aiAttackTargetRotation.y = quat_identity.y;
  this->aiAttackTargetRotation.z = quat_identity.z;
  w = quat_identity.w;
  this->specialAttackStartPitch = 0.0;
  this->movementAnimFrame = 0.0;
  this->aiAttackTargetRotation.w = w;
  this->specialAttackTarget.spawnId.value = 0x1FFF;
  this->specialAttackIndex = -1;
  this->specialAttackStartTime = -1;
  this->infoPropIndex = -1;
  this->cameraTagIndex = -1;
  this->animStartFrame = -1;
  this->animUpdatedFrame = -1;
  this->pitchJointIndex.value = -1;
  this->curMoveMode = MOVEMODE_FREE;
  this->playerUser = nullptr;
  this->specialAttackHasBoundAI = false;
  return this;
}


// ========================================================================
// __unwind$493100
// EA  : 0x82C980CC
// RVA : 0x00C980CC
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493100()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$493101
// EA  : 0x82C980F4
// RVA : 0x00C980F4
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493101()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 5200));
}


// ========================================================================
// __unwind$493102
// EA  : 0x82C98120
// RVA : 0x00C98120
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493102()
{
  int v0; // r12

  idFuncChain::binddef_t::~binddef_t(this: (idSelectedTypeInfo *)(*(_DWORD *)(v0 - 160 + 180) + 5244));
}


// ========================================================================
// __unwind$493103
// EA  : 0x82C9814C
// RVA : 0x00C9814C
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493103()
{
  int v0; // r12

  idFuncChain::binddef_t::~binddef_t(this: (idSelectedTypeInfo *)(*(_DWORD *)(v0 - 160 + 180) + 5328));
}


// ========================================================================
// __unwind$493104
// EA  : 0x82C98178
// RVA : 0x00C98178
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493104()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 5424));
}


// ========================================================================
// __unwind$493105
// EA  : 0x82C981A4
// RVA : 0x00C981A4
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493105()
{
  int v0; // r12

  idList<idPlayerControlled::specialAttack_t,5>::~idList<idPlayerControlled::specialAttack_t,5>(this: (idList<idPlayerControlled::specialAttack_t,5> *)(*(_DWORD *)(v0 - 160 + 180) + 5440));
}


// ========================================================================
// __unwind$493106
// EA  : 0x82C981D0
// RVA : 0x00C981D0
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493106()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 5460));
}


// ========================================================================
// __unwind$493107
// EA  : 0x82C981FC
// RVA : 0x00C981FC
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493107()
{
  int v0; // r12

  idPhysics_Player::~idPhysics_Player(this: (idPhysics_Player *)(*(_DWORD *)(v0 - 160 + 180) + 5504));
}


// ========================================================================
// __unwind$493108
// EA  : 0x82C98228
// RVA : 0x00C98228
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493108()
{
  int v0; // r12

  idMeleeTrace::~idMeleeTrace(this: (idMeleeTrace *)(*(_DWORD *)(v0 - 160 + 180) + 6856));
}


// ========================================================================
// __unwind$493109
// EA  : 0x82C98254
// RVA : 0x00C98254
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493109()
{
  int v0; // r12

  idAnimator_Proxy::~idAnimator_Proxy(this: (idAnimator_Proxy *)(*(_DWORD *)(v0 - 160 + 180) + 6956));
}


// ========================================================================
// __unwind$493110
// EA  : 0x82C98280
// RVA : 0x00C98280
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493110()
{
  int v0; // r12

  idMD6LeafPause::~idMD6LeafPause(this: (idMD6LeafPause *)(*(_DWORD *)(v0 - 160 + 180) + 7000));
}


// ========================================================================
// __unwind$493111
// EA  : 0x82C982AC
// RVA : 0x00C982AC
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493111()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 160 + 180) + 7080));
}


// ========================================================================
// __unwind$493112
// EA  : 0x82C982D8
// RVA : 0x00C982D8
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493112()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 160 + 180) + 7176));
}


// ========================================================================
// ??1idPlayerControlled@@UAA@XZ
// EA  : 0x82C98318
// RVA : 0x00C98318
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void __fastcall idPlayerControlled::~idPlayerControlled(idPlayerControlled *this)
{
  idWeapon *weapon; // r3
  idAI2 *v3; // r3
  idAI2 *v4; // r3
  idAnimStack *v5; // r3
  idPlayerControlled::specialAttack_t *list; // r3

  this->__vftable = (idPlayerControlled_vtbl *)&idPlayerControlled::`vftable';
  weapon = this->primaryWeapon.weapon;
  if ( weapon != nullptr )
  {
    ((void (__fastcall *)(idWeapon *, int))weapon->dtr_idClass)(a1: weapon, a2: 1);
    this->primaryWeapon.weapon = nullptr;
  }
  if ( gameLocal->spawnIds.ptr[this->specialAttackTarget.spawnId.value & 0x1FFF] == this->specialAttackTarget.spawnId.value >> 13 )
  {
    v3 = (idAI2 *)gameLocal->entities.ptr[this->specialAttackTarget.spawnId.value & 0x1FFF];
    if ( v3 != nullptr )
      v4 = idAI2::CastTo(c: v3);
    else
      v4 = nullptr;
    v5 = v4->GetAnimStack_2(this: v4);
    idAnimator_Base::Shutdown(this: &this->targetAnimator, stack: v5);
  }
  idAnimator_Channel::~idAnimator_Channel(this: &this->targetAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->specialAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->leftArmAnimator);
  idMD6LeafPause::~idMD6LeafPause(this: &this->movementLeaf);
  idAnimator_Proxy::~idAnimator_Proxy(this: &this->movementAnimator);
  idMeleeTrace::~idMeleeTrace(this: &this->meleeTrace);
  idPhysics_Player::~idPhysics_Player(this: &this->physicsObj);
  idStr::FreeData(this: &this->pitchJoint);
  if ( this->specialAttacks.listStatic == 0 || this->specialAttacks.listStatic == 2 )
  {
    list = this->specialAttacks.list;
    if ( list != nullptr )
      idListArrayDelete<idPlayerControlled::specialAttack_t>(ptr: list, num: this->specialAttacks.size);
    this->specialAttacks.list = nullptr;
    this->specialAttacks.size = 0;
  }
  this->specialAttacks.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animAttacks);
  idFuncChain::binddef_t::~binddef_t(this: (idSelectedTypeInfo *)&this->secondaryWeapon);
  idFuncChain::binddef_t::~binddef_t(this: (idSelectedTypeInfo *)&this->primaryWeapon);
  idStr::FreeData(this: &this->cameraTagName);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$493628_1
// EA  : 0x82C9849C
// RVA : 0x00C9849C
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493628_1()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$493629_1
// EA  : 0x82C984C4
// RVA : 0x00C984C4
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493629_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 5200));
}


// ========================================================================
// __unwind$493630_1
// EA  : 0x82C984F0
// RVA : 0x00C984F0
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493630_1()
{
  int v0; // r12

  idFuncChain::binddef_t::~binddef_t(this: (idSelectedTypeInfo *)(*(_DWORD *)(v0 - 128 + 148) + 5244));
}


// ========================================================================
// __unwind$493631_0
// EA  : 0x82C9851C
// RVA : 0x00C9851C
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493631_0()
{
  int v0; // r12

  idFuncChain::binddef_t::~binddef_t(this: (idSelectedTypeInfo *)(*(_DWORD *)(v0 - 128 + 148) + 5328));
}


// ========================================================================
// __unwind$493632_0
// EA  : 0x82C98548
// RVA : 0x00C98548
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493632_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5424));
}


// ========================================================================
// __unwind$493633
// EA  : 0x82C98574
// RVA : 0x00C98574
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493633()
{
  int v0; // r12

  idList<idPlayerControlled::specialAttack_t,5>::~idList<idPlayerControlled::specialAttack_t,5>(this: (idList<idPlayerControlled::specialAttack_t,5> *)(*(_DWORD *)(v0 - 128 + 148) + 5440));
}


// ========================================================================
// __unwind$493634
// EA  : 0x82C985A0
// RVA : 0x00C985A0
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493634()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 5460));
}


// ========================================================================
// __unwind$493635
// EA  : 0x82C985CC
// RVA : 0x00C985CC
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493635()
{
  int v0; // r12

  idPhysics_Player::~idPhysics_Player(this: (idPhysics_Player *)(*(_DWORD *)(v0 - 128 + 148) + 5504));
}


// ========================================================================
// __unwind$493636
// EA  : 0x82C985F8
// RVA : 0x00C985F8
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493636()
{
  int v0; // r12

  idMeleeTrace::~idMeleeTrace(this: (idMeleeTrace *)(*(_DWORD *)(v0 - 128 + 148) + 6856));
}


// ========================================================================
// __unwind$493637
// EA  : 0x82C98624
// RVA : 0x00C98624
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493637()
{
  int v0; // r12

  idAnimator_Proxy::~idAnimator_Proxy(this: (idAnimator_Proxy *)(*(_DWORD *)(v0 - 128 + 148) + 6956));
}


// ========================================================================
// __unwind$493638
// EA  : 0x82C98650
// RVA : 0x00C98650
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493638()
{
  int v0; // r12

  idMD6LeafPause::~idMD6LeafPause(this: (idMD6LeafPause *)(*(_DWORD *)(v0 - 128 + 148) + 7000));
}


// ========================================================================
// __unwind$493639
// EA  : 0x82C9867C
// RVA : 0x00C9867C
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493639()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 128 + 148) + 7080));
}


// ========================================================================
// __unwind$493640
// EA  : 0x82C986A8
// RVA : 0x00C986A8
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493640()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 128 + 148) + 7176));
}


// ========================================================================
// __unwind$493641
// EA  : 0x82C986D4
// RVA : 0x00C986D4
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_493641()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 128 + 148) + 7272));
}


// ========================================================================
// ?HandleUserCmds@idPlayerControlled@@QAAXPAVidPlayer@@@Z
// EA  : 0x82C98768
// RVA : 0x00C98768
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void __fastcall idPlayerControlled::HandleUserCmds(idPlayerControlled *this, idPlayer *player)
{
  int v4; // r27
  int v5; // r28
  idPresentable *presentable; // r3
  int v7; // r3
  idPresentable *v8; // r11
  idFocusTracker *v9; // r21
  int v10; // r3
  int v11; // r29
  int v12; // r11
  int v13; // r11
  unsigned __int8 v14; // r11
  bool v15; // zf
  int v16; // r23
  idPresentable *v17; // r3
  idPresentablePlayer *v18; // r3
  idPresentable *v19; // r3
  idPresentablePlayer *v20; // r3
  int v21; // r11
  int v22; // r11
  idPresentable *v23; // r3
  idPresentablePlayer *v24; // r3
  __int64 v25; // r8
  __int64 v26; // r10
  idAngles *p_viewAngles; // r25
  double v28; // fp31
  double v29; // fp1
  double v30; // fp1
  double pitch; // fp0
  double v32; // fp13
  double v33; // fp0
  idPhysics_Player *p_physicsObj; // r22
  idWeapon *weapon; // r3
  idFinishFireResults *v36; // r11
  int i; // ctr
  idPresentable *v38; // r11
  idPresentable *v39; // r3
  idPresentablePlayer *v40; // r29
  const idDeclProjectile *CurrentProjectileDecl; // r3
  idWeapon *v42; // r3
  int v43; // r11
  int v44; // r11
  int v45; // r10
  int v46; // r11
  char v47; // r9
  int v48; // r11
  char v49; // r11
  idPlayerControlled::specialAttack_t *v50; // r29
  int GameMs; // r26
  const idAnimStack *v52; // r3
  const blendParms_t *v53; // r7
  idAI2 *FocusEntity; // r3
  idAI2 *v55; // r3
  idAI2 *v56; // r29
  idPlayerControlled::specialAttack_t *list; // r11
  idPlayerControlled::specialAttack_t *v58; // r28
  idPhysics *Physics; // r3
  float *v60; // r21
  idPhysics *v61; // r3
  float *v62; // r3
  float roll; // r10
  double v64; // fp13
  double v65; // fp12
  double v66; // fp10
  double v67; // fp31
  double v68; // fp9
  double v69; // fp30
  double v70; // fp29
  double v71; // fp31
  double v72; // fp30
  double v73; // fp29
  idPhysics *v74; // r3
  float *v75; // r3
  double v76; // fp28
  double v77; // fp27
  double v78; // fp26
  idPhysics *v79; // r3
  float *v80; // r3
  double v81; // fp31
  double v82; // fp30
  double v83; // fp29
  idPhysics *v84; // r3
  float *v85; // r3
  idPhysics *v86; // r3
  float *v87; // r3
  idAIOrientation *BodyOrientation; // r3
  idPlayerControlled_vtbl *v89; // r8
  int specialAttackStartTime; // r25
  const idAnimStack *v91; // r3
  const blendParms_t *v92; // r7
  int v93; // r3
  int v94; // r27
  int blendMS; // r28
  const idAnimStack *v96; // r3
  const idDeclProjectile *v97; // r29
  idPresentable *v98; // r10
  idPresentable *v99; // r3
  idPresentablePlayer *v100; // r3
  double CurWeaponSpread; // fp1
  idPresentable *v102; // r11
  idPresentable *v103; // r29
  bool inSecondaryMode; // r28
  const idMat3 *v105; // r3
  bool Noclip; // r3
  void (__fastcall *SetContents)(struct idPhysics_Player *, int, int); // ctr
  pmtype_t v108; // r4
  idList<idScriptAction,5> v109; // [sp+60h] [-C90h] BYREF
  idMat3 v110; // [sp+70h] [-C80h] BYREF
  float v111; // [sp+94h] [-C5Ch]
  float v112; // [sp+98h] [-C58h]
  float v113; // [sp+9Ch] [-C54h]
  float v114; // [sp+A0h] [-C50h]
  blendParms_t v115; // [sp+B0h] [-C40h] BYREF
  blendParms_t v116; // [sp+D0h] [-C20h] BYREF
  idVec3 v117; // [sp+E8h] [-C08h] BYREF
  idVec3 v118[2]; // [sp+F8h] [-BF8h] BYREF
  idMat3 v119; // [sp+110h] [-BE0h] BYREF
  idMat3 v120; // [sp+150h] [-BA0h] BYREF
  idFireParms v121; // [sp+190h] [-B60h] BYREF
  idFinishFireResults v122; // [sp+230h] [-AC0h] BYREF
  idAngles v123[4]; // [sp+280h] [-A70h] BYREF
  idFireParms v124; // [sp+2B0h] [-A40h] BYREF
  idTestFireResults v125; // [sp+350h] [-9A0h] BYREF

  if ( player == nullptr || g_freeCam.valueInteger != 0 )
    return;
  v4 = idPlayer::GetUCmdTracker2(this: player) + 8;
  v5 = idPlayer::GetUCmdTracker2(this: player) + 68;
  presentable = player->presentable;
  if ( presentable != nullptr )
    v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v7 = 0;
  v8 = player->presentable;
  v9 = (idFocusTracker *)(v7 + 47160);
  if ( v8 != nullptr )
    v10 = (int)v8->GetPlayerInterface_2(this: player->presentable);
  else
    v10 = 0;
  idView::GetViewPos(this: (idView *)(v10 + 16224), origin: v118, axis: (idMat3 *)&v120.mat[1].y);
  idFocusTracker::UpdateFocus(
    this: v9,
    owner: player,
    viewPos: v118,
    viewAxis: (idMat3 *)&v120.mat[1].y,
    passEntityOverride: this);
  v11 = v9->useButtonOverride | 0x20;
  v12 = 0;
  if ( (*(_BYTE *)(v5 + 9) & 0x80) == 0 )
    v12 = *(_DWORD *)v5;
  if ( (v12 & v11) == 0 )
    goto LABEL_15;
  v13 = 0;
  if ( (*(_BYTE *)(v4 + 9) & 0x80) == 0 )
    v13 = *(_DWORD *)v4;
  v15 = (v13 & v11) == 0;
  v14 = 1;
  if ( !v15 )
LABEL_15:
    v14 = 0;
  v16 = v14;
  if ( v14 != 0 )
  {
    v17 = player->presentable;
    if ( v17 != nullptr )
      v18 = v17->GetPlayerInterface_2(this: v17);
    else
      v18 = nullptr;
    idPresentablePlayer::BeforeUse(this: v18);
  }
  v19 = player->presentable;
  if ( v19 != nullptr )
    v20 = v19->GetPlayerInterface_2(this: v19);
  else
    v20 = nullptr;
  if ( idPresentablePlayer::BeforeUseIsRunning(this: v20) )
  {
    v21 = 0;
    if ( (*(_BYTE *)(v5 + 9) & 0x80) == 0 )
      v21 = *(_DWORD *)v5;
    if ( (v21 & v11) != 0 )
      goto LABEL_37;
    v22 = 0;
    if ( (*(_BYTE *)(v4 + 9) & 0x80) == 0 )
      v22 = *(_DWORD *)v4;
    if ( (v22 & v11) == 0 )
      goto LABEL_37;
    goto LABEL_33;
  }
  if ( v16 != 0 )
  {
LABEL_33:
    v23 = player->presentable;
    if ( v23 != nullptr )
      v24 = v23->GetPlayerInterface_2(this: v23);
    else
      v24 = nullptr;
    idPresentablePlayer::Use(this: v24);
  }
LABEL_37:
  HIDWORD(v25) = *(unsigned __int16 *)(v5 + 10);
  HIDWORD(v26) = SWORD1(v25) - *(__int16 *)(v4 + 10);
  LODWORD(v26) = *(__int16 *)(v5 + 12) - *(__int16 *)(v4 + 12);
  LODWORD(v25) = HIDWORD(v26);
  p_viewAngles = &this->viewAngles;
  v28 = (float)((float)v26 * (float)0.0054931641);
  v29 = idMath::AngleNormalize360(angle: (float)((float)((float)v25 * (float)0.0054931641) + this->viewAngles.pitch));
  if ( v29 > 180.0 )
    v29 = (float)((float)v29 - (float)360.0);
  p_viewAngles->pitch = v29;
  v30 = idMath::AngleNormalize360(angle: (float)(this->viewAngles.yaw + (float)v28));
  if ( v30 > 180.0 )
    v30 = (float)((float)v30 - (float)360.0);
  pitch = p_viewAngles->pitch;
  this->viewAngles.yaw = v30;
  v32 = -89.0;
  if ( pitch < -89.0 || (v32 = 89.0, pitch > 89.0) )
    pitch = v32;
  p_viewAngles->pitch = pitch;
  v33 = -180.0;
  if ( v30 >= -180.0 )
  {
    if ( v30 <= 180.0 )
      v33 = v30;
    else
      v33 = 180.0;
  }
  this->viewAngles.yaw = v33;
  p_physicsObj = &this->physicsObj;
  idPhysics_Player::SetPlayerInput(
    this: &this->physicsObj,
    _prevcmd: (const usercmd_t *)v4,
    cmd: (const usercmd_t *)v5,
    newViewAngles: &this->viewAngles);
  weapon = this->primaryWeapon.weapon;
  if ( weapon != nullptr && idWeapon::CheckFireHandle(this: weapon) )
  {
    idFireParms::idFireParms(this: &v124);
    memset(&v125, 0, sizeof(v125));
    v36 = &v122;
    v122.numProjectiles = 0;
    for ( i = 16; i != 0; --i )
    {
      v36 = (idFinishFireResults *)((char *)v36 + 4);
      v36->numProjectiles = 0;
    }
    v38 = this->presentable;
    if ( v38 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v38 = this->presentable;
    }
    idWeapon::ResolveFire(this: this->primaryWeapon.weapon, fp: &v124, tfr: &v125, ffr: &v122, fxMgr: &v38->fxManager);
    v39 = player->presentable;
    if ( v39 != nullptr )
      v40 = v39->GetPlayerInterface_2(this: v39);
    else
      v40 = nullptr;
    CurrentProjectileDecl = idWeapon::GetCurrentProjectileDecl(this: this->primaryWeapon.weapon, secondaryAmmo: false);
    idPresentablePlayer::WeaponFireFeedback(
      this: v40,
      weapon: this->primaryWeapon.weapon,
      projDecl: CurrentProjectileDecl);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v124.targetList);
  }
  v42 = this->primaryWeapon.weapon;
  if ( v42 == nullptr )
    goto LABEL_66;
  v43 = 0;
  if ( (*(_BYTE *)(v5 + 9) & 0x80) == 0 )
    v43 = *(_DWORD *)v5;
  if ( (v43 & 0x20000000) == 0 )
    goto LABEL_66;
  v44 = 0;
  if ( (*(_BYTE *)(v4 + 9) & 0x80) == 0 )
    v44 = *(_DWORD *)v4;
  if ( (v44 & 0x20000000) == 0 )
  {
    idWeapon::StopLoopingFireSound(this: v42);
    this->primaryWeapon.inSecondaryMode = (_cntlzw(this->primaryWeapon.inSecondaryMode) & 0x20) != 0;
  }
  else
  {
LABEL_66:
    v45 = *(unsigned __int8 *)(v5 + 9) >> 7;
    LOBYTE(v46) = 0;
    if ( v45 == 0 )
      v46 = *(_DWORD *)v5;
    v47 = v46 & 1;
    LOBYTE(v46) = 0;
    if ( v45 == 0 )
      v46 = *(_DWORD *)v5;
    if ( (v46 & 8) == 0 )
      goto LABEL_74;
    LOBYTE(v48) = 0;
    if ( (*(_BYTE *)(v4 + 9) & 0x80) == 0 )
      v48 = *(_DWORD *)v4;
    v15 = (v48 & 8) == 0;
    v49 = 1;
    if ( !v15 )
LABEL_74:
      v49 = 0;
    if ( v16 != 0 )
    {
      this->OnActivate(this, a2: player);
      return;
    }
    if ( v49 != 0 )
    {
      if ( gameLocal->spawnIds.ptr[this->specialAttackTarget.spawnId.value & 0x1FFF] == this->specialAttackTarget.spawnId.value >> 13 )
      {
        if ( this->curMoveMode == MOVEMODE_PICKEDUP )
        {
          v50 = &this->specialAttacks.list[this->specialAttackIndex];
          blendParms_t::blendParms_t(this: &v116);
          blendParms_t::SetDestStartFrame(this: &v116, frame: 0);
          blendParms_t::SetDurationMS(this: &v116, ms: 0x1Eu);
          v116.parms.originBlend = 1;
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v52 = this->GetAnimStack_2(this);
          idAnimator_Channel::PlayAnim(
            this: &this->leftArmAnimator,
            stack: v52,
            ah: &v50->killAnim,
            curTime: GameMs,
            rateScale: 1.0,
            blendParms: v53,
            blendOutDurationMS_: &v116,
            leafStarted: (idMD6LeafPlay **)0xA0,
            a9: nullptr);
          this->animStartFrame = idAccolade::Count(this: &clientGame->gameTimeManager);
          idPlayerControlled::PlayAnimOnTarget(
            this,
            animAlias: &v50->responseKillAnimHandle,
            blendMS: 0x1Eu,
            loop: false);
          this->curMoveMode = MOVEMODE_KILLING;
        }
      }
      else
      {
        FocusEntity = (idAI2 *)idFocusTracker::GetFocusEntity(this: v9);
        v55 = idAI2::CastTo(c: FocusEntity);
        v56 = v55;
        if ( v55 != nullptr && !v55->aiHealth.IsDead_Impl(this: &v55->aiHealth) )
        {
          this->specialAttackIndex = idRandom2::RandomInt(this: &clientGame->random, max: this->specialAttacks.num);
          this->specialAttackHasBoundAI = false;
          this->specialAttackStartTime = idGameTimeManager::GetGameMs(
                                           this: &clientGame->gameTimeManager,
                                           type: GAMETIME_SCALED);
          this->specialAttackTarget.spawnId.value = (gameLocal->spawnIds.ptr[v56->entityNumber] << 13)
                                                  | v56->entityNumber;
          list = this->specialAttacks.list;
          this->curMoveMode = MOVEMODE_ANIMATEDTRANSITION;
          v58 = &list[this->specialAttackIndex];
          Physics = idEntity::GetPhysics(this);
          v60 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v61 = idEntity::GetPhysics(this: v56);
          v62 = (float *)v61->GetOrigin(this: v61, a2: 0);
          roll = this->viewAngles.roll;
          v64 = v60[1];
          v65 = *v60;
          v66 = v62[1];
          v67 = (float)(v62[2] - v60[2]);
          v68 = *v62;
          v110.mat[0].y = this->viewAngles.yaw;
          v110.mat[0].x = 0.0;
          v110.mat[0].z = roll;
          v69 = (float)((float)v66 - (float)v64);
          v70 = (float)((float)v68 - (float)v65);
          idAngles::ToMat3(this: (idAngles *)&v110.mat[1].y, result: &v110);
          v71 = (float)((float)((float)v67
                              - (float)((float)(v111 * v58->attachOffset.y)
                                      + (float)((float)(v110.mat[2].x * v58->attachOffset.x)
                                              + (float)(v114 * v58->attachOffset.z))))
                      * (float)0.5);
          v72 = (float)((float)((float)v69
                              - (float)((float)(v110.mat[2].z * v58->attachOffset.y)
                                      + (float)((float)(v110.mat[1].z * v58->attachOffset.x)
                                              + (float)(v113 * v58->attachOffset.z))))
                      * (float)0.5);
          v73 = (float)((float)((float)v70
                              - (float)((float)(v110.mat[1].y * v58->attachOffset.x)
                                      + (float)((float)(v112 * v58->attachOffset.z)
                                              + (float)(v110.mat[2].y * v58->attachOffset.y))))
                      * (float)0.5);
          v74 = idEntity::GetPhysics(this);
          v75 = (float *)v74->GetOrigin(this: v74, a2: 0);
          v76 = (float)(v75[2] + (float)v71);
          v77 = (float)(v75[1] + (float)v72);
          v78 = (float)(*v75 + (float)v73);
          v79 = idEntity::GetPhysics(this: v56);
          v80 = (float *)v79->GetOrigin(this: v79, a2: 0);
          v81 = (float)(v80[2] - (float)v71);
          v82 = (float)(v80[1] - (float)v72);
          v83 = (float)(*v80 - (float)v73);
          idMat3::operator*(this: (idMat3 *)&v119.mat[1].y, result: &v58->attachAxis, a: (idMat3 *)&v110.mat[1].y);
          v84 = idEntity::GetPhysics(this);
          v85 = (float *)v84->GetOrigin(this: v84, a2: 0);
          this->specialAttackStartPos.x = *v85;
          this->specialAttackStartPos.y = v85[1];
          this->specialAttackStartPos.z = v85[2];
          this->specialAttackStartRotation = *idMat3::ToQuat(this: &v119, result: (idQuat *)&v110.mat[1].y);
          this->specialAttackTargetPos.y = v77;
          this->specialAttackTargetPos.x = v78;
          this->specialAttackTargetPos.z = v76;
          this->specialAttackTargetRotation.x = this->specialAttackStartRotation.x;
          this->specialAttackTargetRotation.y = this->specialAttackStartRotation.y;
          this->specialAttackTargetRotation.z = this->specialAttackStartRotation.z;
          this->specialAttackTargetRotation.w = this->specialAttackStartRotation.w;
          v86 = idEntity::GetPhysics(this: v56);
          v87 = (float *)v86->GetOrigin(this: v86, a2: 0);
          this->aiAttackStartPos.x = *v87;
          this->aiAttackStartPos.y = v87[1];
          this->aiAttackStartPos.z = v87[2];
          BodyOrientation = idAI2::GetBodyOrientation(this: v56);
          this->aiAttackStartRotation = *idMat3::ToQuat(this: &v119, result: (idQuat *)&BodyOrientation->axis);
          this->aiAttackTargetPos.x = v83;
          this->aiAttackTargetPos.y = v82;
          this->aiAttackTargetPos.z = v81;
          this->aiAttackTargetRotation = *idMat3::ToQuat(this: &v120, result: (idQuat *)&v119.mat[1].y);
          this->specialAttackStartPitch = p_viewAngles->pitch;
          blendParms_t::blendParms_t(this: &v115);
          blendParms_t::SetDestStartFrame(this: &v115, frame: 0);
          blendParms_t::SetDurationMS(this: &v115, ms: v58->blendMS);
          v89 = this->__vftable;
          v115.parms.originBlend = 1;
          specialAttackStartTime = this->specialAttackStartTime;
          v91 = v89->GetAnimStack_2(this);
          idAnimator_Channel::PlayAnim(
            this: &this->specialAnimator,
            stack: v91,
            ah: &v58->attackAnim,
            curTime: specialAttackStartTime,
            rateScale: 1.0,
            blendParms: v92,
            blendOutDurationMS_: &v115,
            leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
            a9: nullptr);
          this->animStartFrame = idAccolade::Count(this: &clientGame->gameTimeManager);
          *(_WORD *)&v109.memTag = 1280;
          memset(&v109, 0, 14);
          idList<idScriptAction,5>::SetNum(this: &v109, newNum: 2);
          idStr::operator=(this: &v109.list->eventName, text: "action_ReleaseTriggerRight");
          idStr::operator=(this: &v109.list[1].eventName, text: "action_Wait");
          idList<idAIActionParm,5>::SetNum(this: &v109.list[1].parms, newNum: 1);
          idAIActionParm::Set(this: v109.list[1].parms.list, in: -1);
          idAI2::SetActionScript(this: v56, script: &v109, scriptExecutor: this, activator: this);
          v93 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idAI2::StartActionScript(this: v56, curTime: v93);
          idAI2::SetWorldCollision(this: v56, collideWithWorld: false);
          idAI2::SetSolid(this: v56, isSolid: false);
          idPlayerControlled::PlayAnimOnTarget(
            this,
            animAlias: &v58->responseHandle,
            blendMS: v58->blendMS,
            loop: false);
          idAnimator_WalkIK::DisableAll(this: &v56->walkIK);
          v94 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          blendMS = v58->blendMS;
          v96 = v56->GetAnimStack_2(this: v56);
          idAnimator_Base::End(this: &v56->walkIK, stack: v96, curTime: v94, blendDurationMS: blendMS, reset: false);
          idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v56)->useDeferredPosition = false;
          *(_BYTE *)&v56->flags &= ~2u;
          idList<idScriptAction,5>::Clear(this: &v109);
        }
      }
    }
    else if ( v42 != nullptr )
    {
      if ( v47 != 0 )
      {
        if ( idWeapon::IsReadyToFire(this: v42) && this->primaryWeapon.weaponTagIndexPrimary != -1 )
        {
          idFireParms::idFireParms(this: &v121);
          v97 = idWeapon::GetCurrentProjectileDecl(
                  this: this->primaryWeapon.weapon,
                  secondaryAmmo: this->primaryWeapon.inSecondaryMode);
          v98 = this->presentable;
          *((_BYTE *)&v121 + 128) |= 0x20u;
          if ( v98 == nullptr )
            idEntity::InitPresentableInternal(this);
          v99 = player->presentable;
          *((_BYTE *)&v121 + 128) |= 0x10u;
          if ( v99 != nullptr )
            v100 = v99->GetPlayerInterface_2(this: v99);
          else
            v100 = nullptr;
          CurWeaponSpread = idPresentablePlayer::GetCurWeaponSpread(
                              this: v100,
                              secondary: this->primaryWeapon.inSecondaryMode);
          v102 = player->presentable;
          v121.addSpread = (float)CurWeaponSpread - v97->spread;
          if ( v102 != nullptr )
          {
            v103 = v102;
          }
          else
          {
            idEntity::InitPresentableInternal(this: player);
            v103 = player->presentable;
          }
          idAnimatedEntity::GetTagPosition(
            this,
            propIndex: this->infoPropIndex,
            tagIndex: this->primaryWeapon.weaponTagIndexPrimary,
            origin: &v117,
            axis: (idMat3 *)&v119.mat[1].y);
          inSecondaryMode = this->primaryWeapon.inSecondaryMode;
          v105 = idAngles::ToMat3(this: v123, result: (idMat3 *)&this->viewAngles);
          idWeapon::DeferredFire(
            this: this->primaryWeapon.weapon,
            attacker: v103,
            target: nullptr,
            start: &v117,
            fireAxis: v105,
            fp: &v121,
            secondaryAmmo: inSecondaryMode);
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v121.targetList);
        }
      }
      else
      {
        idWeapon::StopLoopingFireSound(this: v42);
      }
    }
  }
  Noclip = idPlayer::GetNoclip(this: player);
  SetContents = p_physicsObj->SetContents;
  if ( Noclip )
  {
    SetContents(this: p_physicsObj, a2: 0, a3: -1);
    p_physicsObj->SetClipMask(this: p_physicsObj, a2: 0, a3: -1);
    v108 = PM_NOCLIP;
  }
  else
  {
    SetContents(this: p_physicsObj, a2: 2261120, a3: -1);
    p_physicsObj->SetClipMask(this: p_physicsObj, a2: 107529, a3: -1);
    v108 = PM_NORMAL;
  }
  idPhysics_Player::SetMovementType(this: p_physicsObj, type: v108);
}


// ========================================================================
// __unwind$494191
// EA  : 0x82C994C8
// RVA : 0x00C994C8
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_494191()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 3312 + 688));
}


// ========================================================================
// __unwind$494192
// EA  : 0x82C994F0
// RVA : 0x00C994F0
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_494192()
{
  int v0; // r12

  idList<idScriptAction,5>::Clear(this: (idList<idScriptAction,5> *)(v0 - 3312 + 96));
}


// ========================================================================
// __unwind$494193
// EA  : 0x82C99518
// RVA : 0x00C99518
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_494193()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 3312 + 400));
}


// ========================================================================
// ?Think@idPlayerControlled@@UAAXXZ
// EA  : 0x82C99548
// RVA : 0x00C99548
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPlayerControlled::Think(idPlayerControlled *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPlayerControlled::moveMode_t curMoveMode; // r11
  idTreeAnimator *v4; // r22
  idPlayerControlled::specialAttack_t *v5; // r28
  int GameMs; // r3
  int v7; // r25
  double v8; // fp31
  idAI2 *v9; // r3
  idPhysics *Physics; // r3
  idAI2 *v11; // r3
  idAIOrientation *BodyOrientation; // r3
  idIndex<short,enum invalidJointIndex_t> *value; // r21
  idAI2 *v14; // r3
  int v15; // r26
  const idAnimStack *v16; // r3
  __int64 v17; // r8
  int v18; // r29
  const idAnimStack *v19; // r3
  __int64 v20; // r10 OVERLAPPED
  idAI2 *v21; // r3
  int v22; // r28
  idAI2 *v23; // r3
  idAI2 *v24; // r3
  long double v25; // fp2
  int specialAttackStartTime; // r11
  double v27; // fp0
  float v28; // r7
  float v29; // r6
  float v30; // r10
  double v31; // fp26
  double v32; // fp27
  double x; // fp28
  BOOL specialAttackHasBoundAI; // r5
  float v35; // r7
  float v36; // r6
  float v37; // r11
  float v38; // r8
  idAI2 *v39; // r3
  idPhysics *v40; // r3
  const idMat3 *v41; // r28
  idAI2 *v42; // r3
  idAIOrientation *v43; // r3
  double y; // fp13
  double z; // fp12
  double w; // fp11
  idQuat *v47; // r3
  double v48; // fp31
  double v49; // fp30
  double v50; // fp29
  double v51; // fp24
  idPhysics *v52; // r3
  idPhysics *v53; // r28
  idPhysics_vtbl *v54; // r29
  idMat3 *v55; // r3
  idAI2 *v56; // r28
  int v57; // r26
  const idAnimStack *v58; // r3
  idAI2 *v59; // r3
  idAI2 *v60; // r3
  idAnimStack *v61; // r3
  const idMat3 *v62; // r3
  float v63; // [sp+50h] [-210h]
  idQuat v64; // [sp+60h] [-200h] BYREF
  idList<idScriptAction,5> v65; // [sp+70h] [-1F0h] BYREF
  idVec3 v66; // [sp+80h] [-1E0h] BYREF
  idMat3 v67; // [sp+90h] [-1D0h] BYREF
  float v68; // [sp+B4h] [-1ACh]
  float v69; // [sp+B8h] [-1A8h]
  float v70[4]; // [sp+C0h] [-1A0h] BYREF
  idMat3 v71; // [sp+D0h] [-190h] BYREF
  idVec3 v72[2]; // [sp+F8h] [-168h] BYREF
  idMat3 v73[2]; // [sp+110h] [-150h] BYREF
  idQuat v74[3]; // [sp+160h] [-100h] BYREF
  idQuat v75; // [sp+190h] [-D0h] BYREF

  if ( this->playerUser != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    curMoveMode = this->curMoveMode;
    v4 = TreeAnimatorFromPresentable;
    if ( (unsigned int)curMoveMode <= MOVEMODE_KILLING )
    {
      if ( curMoveMode == MOVEMODE_ANIMATEDTRANSITION )
      {
        v5 = &this->specialAttacks.list[this->specialAttackIndex];
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v7 = GameMs;
        v8 = 1.0;
        if ( !this->specialAttackHasBoundAI && GameMs > this->specialAttackStartTime + v5->blendMS )
        {
          this->specialAttackHasBoundAI = true;
          if ( gameLocal->spawnIds.ptr[this->specialAttackTarget.spawnId.value & 0x1FFF] == this->specialAttackTarget.spawnId.value >> 13 )
          {
            idTreeAnimator::GetWorldSpaceJointTransform(
              this: v4,
              pose: DRIVER_MODEL,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v5->attachJointIndex.value,
              origin: v72,
              axis: (idMat3 *)&v73[0].mat[2].z);
            v9 = idEntityPtr<idAI2>::operator->(this: &this->specialAttackTarget);
            Physics = idEntity::GetPhysics(this: v9);
            Physics->SetOrigin(this: Physics, a2: v72, a3: -1);
            v11 = idEntityPtr<idAI2>::operator->(this: &this->specialAttackTarget);
            BodyOrientation = idAI2::GetBodyOrientation(this: v11);
            idAIOrientation::SetAxis(this: BodyOrientation, axis: (idMat3 *)&v73[0].mat[2].z);
            value = (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v5->attachJointIndex.value;
            v14 = idEntityPtr<idAI2>::operator->(this: &this->specialAttackTarget);
            idEntity::BindToJoint(this: v14, master: (idWorldspawn *)this, jointnum: value, orientated: true);
          }
          if ( v5->attackMH.value != 0xFFFF )
          {
            blendParms_t::blendParms_t(this: (blendParms_t *)&v71.mat[1].y);
            blendParms_t::SetDestStartFrame(this: (blendParms_t *)&v71.mat[1].y, frame: 0);
            BYTE1(v71.mat[2].z) = 1;
            v15 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v16 = this->GetAnimStack_2(this);
            LODWORD(v17) = &v71.mat[1].y;
            idAnimator_Channel::CycleAnim(
              this: &this->leftArmAnimator,
              stack: v16,
              ah: &v5->attackMH,
              curTime: v15,
              rateScale: 1.0,
              leafStarted: v17,
              a7: nullptr);
          }
        }
        v18 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + v7;
        v19 = this->GetAnimStack_2(this);
        if ( (unsigned __int8)idAnimator_Channel::IsAnimPlaying(
                                this: &this->specialAnimator,
                                stack: v19,
                                ah: &v5->attackAnim,
                                curTime: v18) != 0 )
        {
          specialAttackStartTime = this->specialAttackStartTime;
          LODWORD(v20) = v5->blendMS;
          if ( v7 >= (int)v20 + specialAttackStartTime )
          {
            y = this->specialAttackTargetRotation.y;
            z = this->specialAttackTargetRotation.z;
            w = this->specialAttackTargetRotation.w;
            x = this->specialAttackTargetPos.x;
            v32 = this->specialAttackTargetPos.y;
            v31 = this->specialAttackTargetPos.z;
            v67.mat[1].y = this->specialAttackTargetRotation.x;
            v67.mat[1].z = y;
            v67.mat[2].x = z;
            v67.mat[2].y = w;
            this->viewAngles.pitch = 0.0;
          }
          else
          {
            HIDWORD(v20) = v7 - specialAttackStartTime;
            v27 = (float)((float)*(__int64 *)((char *)&v20 + 4) / (float)v20);
            if ( v27 >= 0.0 )
            {
              if ( v27 <= 1.0 )
                v8 = (float)((float)*(__int64 *)((char *)&v20 + 4) / (float)v20);
            }
            else
            {
              v8 = 0.0;
            }
            v28 = this->specialAttackTargetPos.y;
            v29 = this->specialAttackStartPos.y;
            v30 = this->specialAttackStartPos.z;
            v63 = this->specialAttackStartPos.x;
            v64.x = this->specialAttackTargetPos.x;
            v64.y = v28;
            v64.z = this->specialAttackTargetPos.z;
            v31 = (float)((float)((float)(v64.z - v30) * (float)v8) + v30);
            v32 = (float)((float)((float)(v28 - v29) * (float)v8) + v29);
            x = (float)((float)((float)(v64.x - v63) * (float)v8) + v63);
            idQuat::Slerp(
              this: (idQuat *)&v67.mat[1].y,
              from: &this->specialAttackStartRotation,
              to: &this->specialAttackTargetRotation,
              t: v8);
            specialAttackHasBoundAI = this->specialAttackHasBoundAI;
            this->viewAngles.pitch = (float)((float)-this->specialAttackStartPitch * (float)v8)
                                   + this->specialAttackStartPitch;
            if ( !specialAttackHasBoundAI
              && gameLocal->spawnIds.ptr[this->specialAttackTarget.spawnId.value & 0x1FFF] == this->specialAttackTarget.spawnId.value >> 13 )
            {
              v35 = this->aiAttackTargetPos.x;
              v36 = this->aiAttackTargetPos.y;
              v37 = this->aiAttackTargetPos.z;
              v38 = this->aiAttackStartPos.z;
              v64.x = this->aiAttackStartPos.x;
              v64.z = v38;
              v64.y = this->aiAttackStartPos.y;
              v70[1] = (float)((float)(v36 - v64.y) * (float)v8) + v64.y;
              v70[2] = (float)((float)(v37 - v38) * (float)v8) + v38;
              v70[0] = (float)((float)(v35 - v64.x) * (float)v8) + v64.x;
              idQuat::Slerp(
                this: (idQuat *)v73,
                from: &this->aiAttackStartRotation,
                to: &this->aiAttackTargetRotation,
                t: v8);
              v39 = idEntityPtr<idAI2>::operator->(this: &this->specialAttackTarget);
              v40 = idEntity::GetPhysics(this: v39);
              v40->SetOrigin(this: v40, a2: (const idVec3 *)v70, a3: -1);
              v41 = idQuat::ToMat3(this: &v75, result: v73);
              v42 = idEntityPtr<idAI2>::operator->(this: &this->specialAttackTarget);
              v43 = idAI2::GetBodyOrientation(this: v42);
              idAIOrientation::SetAxis(this: v43, axis: v41);
            }
          }
          if ( this->animUpdatedFrame > this->animStartFrame )
          {
            idEntity::BecomeActive(this, flags: 2);
            idTreeAnimator::GetTotalOriginTransform(this: v4, rot: (idQuat *)&v67, trans: &v66);
            v47 = idQuat::Inverse(this: (idQuat *)&v73[0].mat[1].y, result: (idQuat *)&v67);
            v48 = v47->x;
            v67.mat[0].x = v47->x;
            v49 = v47->y;
            v67.mat[0].y = v47->y;
            v50 = v47->z;
            v67.mat[0].z = v47->z;
            v51 = v47->w;
            idQuat::operator*(this: &v64, result: (idVec3 *)&v67.mat[1].y, a: &v66);
            v66.x = v64.x;
            v66.y = v64.y;
            v66.z = v64.z;
            v67.mat[0].x = -(float)((float)((float)v50 * v67.mat[1].z)
                                  - (float)((float)((float)v51 * v67.mat[1].y)
                                          + (float)((float)((float)v49 * v67.mat[2].x)
                                                  + (float)(v67.mat[2].y * (float)v48))));
            v67.mat[0].y = -(float)((float)(v67.mat[2].x * (float)v48)
                                  - (float)((float)((float)v50 * v67.mat[1].y)
                                          + (float)((float)((float)v49 * v67.mat[2].y)
                                                  + (float)((float)v51 * v67.mat[1].z))));
            v67.mat[0].z = -(float)((float)((float)v49 * v67.mat[1].y)
                                  - (float)((float)(v67.mat[1].z * (float)v48)
                                          + (float)((float)((float)v50 * v67.mat[2].y)
                                                  + (float)((float)v51 * v67.mat[2].x))));
            v67.mat[1].x = -(float)((float)((float)v50 * v67.mat[2].x)
                                  - (float)-(float)((float)((float)v49 * v67.mat[1].z)
                                                  - (float)((float)((float)v51 * v67.mat[2].y)
                                                          - (float)((float)v48 * v67.mat[1].y))));
            v52 = idEntity::GetPhysics(this);
            v67.mat[2].z = v66.x + (float)x;
            v68 = v66.y + (float)v32;
            v69 = v66.z + (float)v31;
            v52->SetOrigin(this: v52, a2: (const idVec3 *)&v67.mat[2].z, a3: -1);
            v53 = idEntity::GetPhysics(this);
            v54 = v53->__vftable;
            v55 = idQuat::ToMat3(this: v74, result: &v67);
            v54->SetAxis(this: v53, a2: v55, a3: -1);
          }
        }
        else
        {
          this->curMoveMode = MOVEMODE_PICKEDUP;
          if ( gameLocal->spawnIds.ptr[this->specialAttackTarget.spawnId.value & 0x1FFF] == this->specialAttackTarget.spawnId.value >> 13 )
          {
            idPlayerControlled::PlayAnimOnTarget(this, animAlias: &v5->responseHandleMH, blendMS: 0, loop: true);
            *(_WORD *)&v65.memTag = 1280;
            memset(&v65, 0, 14);
            idList<idScriptAction,5>::SetNum(this: &v65, newNum: 2);
            idStr::operator=(this: &v65.list->eventName, text: "action_PullTriggerRight");
            idStr::operator=(this: &v65.list[1].eventName, text: "action_Wait");
            idList<idAIActionParm,5>::SetNum(this: &v65.list[1].parms, newNum: 1);
            idAIActionParm::Set(this: v65.list[1].parms.list, in: -1);
            v21 = idEntityPtr<idAI2>::operator->(this: &this->specialAttackTarget);
            idAI2::SetActionScript(this: v21, script: &v65, scriptExecutor: this, activator: this);
            v22 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v23 = idEntityPtr<idAI2>::operator->(this: &this->specialAttackTarget);
            idAI2::StartActionScript(this: v23, curTime: v22);
            idEntityPtr<idAI2>::operator->(this: &this->specialAttackTarget)->aiEditable.actionSettings.fire.aimAngle = 50.0;
            v24 = idEntityPtr<idAI2>::operator->(this: &this->specialAttackTarget);
            idAIEditable::idAIActionSettings::UpdateAimDot(this: &v24->aiEditable.actionSettings, a2: v25);
            idList<idScriptAction,5>::Clear(this: &v65);
          }
        }
      }
      else if ( curMoveMode != MOVEMODE_PICKEDUP && curMoveMode != MOVEMODE_FREE )
      {
        v56 = idEntityPtr<idAI2>::operator->(this: &this->specialAttackTarget);
        v57 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v58 = v56->GetAnimStack_2(this: v56);
        if ( idAnimator_Channel::IsDone(this: &this->targetAnimator, stack: v58, curTime: v57) )
        {
          v59 = idEntityPtr<idAI2>::operator->(this: &this->specialAttackTarget);
          idEntity::Unbind(this: v59);
          v60 = idEntityPtr<idAI2>::operator->(this: &this->specialAttackTarget);
          v61 = v60->GetAnimStack_2(this: v60);
          idAnimator_Base::Shutdown(this: &this->targetAnimator, stack: v61);
          this->specialAttackTarget.spawnId.value = 0x1FFF;
          this->curMoveMode = MOVEMODE_FREE;
        }
      }
      else
      {
        idPlayerControlled::HandleUserCmds(this, player: this->playerUser);
      }
    }
    if ( this->meleeTrace.numSamples != 0 )
      idMeleeTrace::Update(this: &this->meleeTrace, owner: this);
    if ( v4 != nullptr )
    {
      v71.mat[0].x = this->viewAngles.pitch;
      v71.mat[0].y = 0.0;
      v71.mat[0].z = 0.0;
      v62 = idAngles::ToMat3(this: (idAngles *)v74, result: &v71);
      idTreeAnimator::SetJointAxis(
        this: v4,
        pose: (animationPose_t)0,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->pitchJointIndex.value,
        type: JOINTMOD_LOCAL,
        axis: v62);
    }
    idPlayerControlled::UpdateMovementAnimator(this);
    idAnimatedEntity::UpdateProxyAnimator(this);
    idAnimatedEntity::UpdateFrameCommands(this);
    idEntity::RunPhysics(this);
    idEntity::TouchTriggers(this);
    idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
    this->animUpdatedFrame = idAccolade::Count(this: &clientGame->gameTimeManager);
    idAnimatedEntity::UpdateDamageEffects(this);
    this->UpdateFX(this);
    idAnimatedEntity::UpdateImpacts(this);
  }
  else
  {
    idEntity::BecomeInactive(this, flags: 7);
  }
}


// ========================================================================
// __unwind$495200
// EA  : 0x82C99D80
// RVA : 0x00C99D80
// PDB : w:\tech5\tungsten\game\entities\playercontrolled.cpp
// ========================================================================

void _unwind_495200()
{
  int v0; // r12

  idList<idScriptAction,5>::Clear(this: (idList<idScriptAction,5> *)(v0 - 608 + 112));
}

