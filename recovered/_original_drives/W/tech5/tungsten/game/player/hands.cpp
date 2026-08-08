
// ========================================================================
// ?Hide@idHands@@QAAXW4handHideReason_t@1@@Z
// EA  : 0x82DFDA88
// RVA : 0x00DFDA88
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::Hide(idHands *this, idHands::handHideReason_t hideReason)
{
  int v2; // r9

  v2 = this->hiddenReasons | hideReason;
  this->shouldShowAfterUpdate = false;
  this->hiddenReasons = v2;
}


// ========================================================================
// ?Enable@idHands@@QAAXXZ
// EA  : 0x82DFDAA0
// RVA : 0x00DFDAA0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::Enable(idHands *this)
{
  if ( (this->hiddenReasons & 8) == 0 )
    this->disabled = false;
}


// ========================================================================
// ?Draw@idHands@@QAAXXZ
// EA  : 0x82DFDAC0
// RVA : 0x00DFDAC0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::Draw(idHands *this)
{
  idRenderModel *testModel; // r3
  idPresentableAnimatedEntity *presentable; // r11

  testModel = this->testModel;
  if ( testModel != nullptr )
  {
    idRenderModel::CommitThisFrame(this: testModel);
  }
  else if ( !this->unlinked )
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
    {
      ((void (*)(void))presentable->Present)();
      idHandsItem::Draw(this: &this->rightItem);
      idHandsItem::Draw(this: &this->leftItem);
    }
  }
}


// ========================================================================
// ?ItemForSlot@idHands@@QAAPAVidHandsItem@@W4equipSlot_t@@@Z
// EA  : 0x82DFDB48
// RVA : 0x00DFDB48
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHandsItem *__fastcall idHands::ItemForSlot(idHands *this, const equipSlot_t slot)
{
  if ( slot == EQUIP_LEFT_HAND )
    return &this->leftItem;
  if ( slot == EQUIP_RIGHT_HAND )
    return &this->rightItem;
  return nullptr;
}


// ========================================================================
// ?AttackPending@idHands@@QBA_NXZ
// EA  : 0x82DFDB70
// RVA : 0x00DFDB70
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idWeapon *__fastcall idHands::AttackPending(idHands *this)
{
  idWeapon *result; // r3

  result = this->owner->GetEquippedWeapon(this: this->owner, a2: 2);
  if ( result != nullptr )
    return (idWeapon *)((_cntlzw(this->pendingAction.action - 1) & 0x20) != 0);
  return result;
}


// ========================================================================
// ?ReloadPending@idHands@@QBA_NXZ
// EA  : 0x82DFDBE0
// RVA : 0x00DFDBE0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idWeapon *__fastcall idHands::ReloadPending(idHands *this)
{
  idWeapon *result; // r3

  result = this->owner->GetEquippedWeapon(
             this: this->owner,
             a2: ((_cntlzw(this->pendingAction.leftHand) & 0x20) != 0) + 1);
  if ( result != nullptr )
    return (idWeapon *)((_cntlzw(this->pendingAction.action - 3) & 0x20) != 0);
  return result;
}


// ========================================================================
// ?AmmoChangePending@idHands@@QBA_NXZ
// EA  : 0x82DFDC58
// RVA : 0x00DFDC58
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idWeapon *__fastcall idHands::AmmoChangePending(idHands *this)
{
  idWeapon *result; // r3

  result = this->owner->GetEquippedWeapon(this: this->owner, a2: 2);
  if ( result != nullptr )
    return (idWeapon *)((_cntlzw(this->pendingAction.action - 4) & 0x20) != 0);
  return result;
}


// ========================================================================
// ?BringDownPending@idHands@@QBA_NXZ
// EA  : 0x82DFDCC8
// RVA : 0x00DFDCC8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

BOOL __fastcall idHands::BringDownPending(idHands *this)
{
  return (_cntlzw(this->pendingAction.action - 6) & 0x20) != 0;
}


// ========================================================================
// ?BringUpPending@idHands@@QBA_NXZ
// EA  : 0x82DFDCE0
// RVA : 0x00DFDCE0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

BOOL __fastcall idHands::BringUpPending(idHands *this)
{
  return (_cntlzw(this->pendingAction.action - 7) & 0x20) != 0;
}


// ========================================================================
// ?CookItemPending@idHands@@QBA_NXZ
// EA  : 0x82DFDCF8
// RVA : 0x00DFDCF8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

BOOL __fastcall idHands::CookItemPending(idHands *this)
{
  return (_cntlzw(this->pendingAction.action - 9) & 0x20) != 0;
}


// ========================================================================
// ?GetTreeAnimatorFromPresentable@idHands@@QBAPAVidTreeAnimator@@XZ
// EA  : 0x82DFDD10
// RVA : 0x00DFDD10
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idTreeAnimator *__fastcall idHands::GetTreeAnimatorFromPresentable(idHands *this)
{
  idPresentableAnimatedEntity *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return idPresentableAnimatedEntity::GetTreeAnimator(this: presentable);
  else
    return nullptr;
}


// ========================================================================
// ?GetPresentable@idHands@@QAAPAVidPresentable@@XZ
// EA  : 0x82DFDD28
// RVA : 0x00DFDD28
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idPresentableAnimatedEntity *__fastcall idHands::GetPresentable(idHands *this)
{
  return this->presentable;
}


// ========================================================================
// ?ShouldShow@idHands@@IBA_NXZ
// EA  : 0x82DFDDF0
// RVA : 0x00DFDDF0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

int __fastcall idHands::ShouldShow(idHands *this)
{
  unsigned __int8 v1; // r11

  if ( !this->unlinked )
    return 0;
  if ( hands_show.valueInteger == 0 )
    return 0;
  if ( g_editEntityMode.valueInteger != 0 )
    return 0;
  if ( this->hiddenReasons != 0 )
    return 0;
  v1 = 1;
  if ( this->testModel != nullptr )
    return 0;
  return v1;
}


// ========================================================================
// ?SetVariationIndex@idHands@@IAAX_NW4handsState_t@1@@Z
// EA  : 0x82DFDE58
// RVA : 0x00DFDE58
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SetVariationIndex(
        idHands *this,
        bool relaxed,
        idHands::handsState_t state,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  int v9; // r11
  swimdepthstate_t lastSwimDepthState; // r11
  idWeapon *v11; // r3
  char v12; // r11
  unsigned __int8 v13; // r31
  idWeapon *v14; // r3
  unsigned __int8 v15; // r11
  BOOL v16; // r11
  unsigned int v17; // r11

  if ( (*((_BYTE *)this + 7912) & 4) != 0 )
  {
    v9 = 2;
    goto LABEL_21;
  }
  lastSwimDepthState = this->lastSwimDepthState;
  if ( lastSwimDepthState != SWIMDEPTH_STATE_NONE )
  {
    v17 = lastSwimDepthState - 1;
    goto LABEL_20;
  }
  v11 = this->owner->GetEquippedWeapon(this: this->owner, a2: 2);
  if ( v11 == nullptr || (v12 = 1, v11->weaponState != WEAPONSTATE_NORMAL) )
    v12 = 0;
  v13 = v12;
  v14 = this->owner->GetEquippedWeapon(this: this->owner, a2: 1);
  if ( v14 == nullptr || (v15 = 1, v14->weaponState != WEAPONSTATE_NORMAL) )
    v15 = 0;
  if ( relaxed )
  {
    if ( this->currentDualWieldState == SET_DUALWIELD_ON )
      v9 = 8;
    else
      v9 = ((_cntlzw(v13) & 0x20) != 0) + 6;
    goto LABEL_21;
  }
  if ( this->currentDualWieldState != SET_DUALWIELD_ON )
  {
    v17 = v13;
LABEL_20:
    v9 = (_cntlzw(v17) & 0x20) != 0;
    goto LABEL_21;
  }
  v16 = (_cntlzw(v15) & 0x20) != 0;
  if ( v13 != 0 )
    v9 = v16 + 2;
  else
    v9 = v16 + 4;
LABEL_21:
  LODWORD(a7) = v9;
  this->currentVariationIndex = v9;
  this->web.variationIndex = (float)a7;
  this->secondaryWeb.variationIndex = (float)a7;
}


// ========================================================================
// ?UpdateMeleeTrace@idHands@@IAAXXZ
// EA  : 0x82DFDFA8
// RVA : 0x00DFDFA8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::UpdateMeleeTrace(idHands *this)
{
  idHandsItem *p_rightItem; // r30
  float z; // r10
  float x; // r9
  double v7; // fp3
  double v8; // fp4
  double v9; // fp3
  idMeleeTrace *p_handsMeleeTrace; // r30
  idAnimatedEntity *entity; // r29
  const idTreeAnimator *TreeAnimatorFromPresentable; // r3
  bool updated; // r3
  idPresentableAnimatedEntity *presentable; // r3
  const idTreeAnimator *TreeAnimator; // r5
  idMeleeTrace *v16; // r30
  const idTreeAnimator *v17; // r3
  idPresentableAnimatedEntity *v18; // r3
  const idTreeAnimator *v19; // r5
  int v20; // r4
  idVec3 v21[2]; // [sp+50h] [-40h] BYREF

  if ( this->handsMeleeTrace.numSamples != 0 )
  {
    p_rightItem = &this->rightItem;
    z = this->owner->firstPersonViewAxis.mat[0].z;
    x = this->owner->firstPersonViewAxis.mat[0].x;
    v21[0].y = this->owner->firstPersonViewAxis.mat[0].y;
    _FP6 = (float)((float)((float)(x * x) + (float)((float)(v21[0].y * v21[0].y) + (float)(z * z)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f12 }
    v7 = __frsqrte(_FP4);
    v8 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v7
                                                                                       * (float)((float)((float)(x * x) + (float)((float)(v21[0].y * v21[0].y) + (float)(z * z)))
                                                                                               * (float)0.5))
                                                                               * (float)v7)
                                                                       - (float)1.5)
                                                       * (float)v7)
                                               * (float)((float)((float)(x * x)
                                                               + (float)((float)(v21[0].y * v21[0].y) + (float)(z * z)))
                                                       * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v7
                                                                               * (float)((float)((float)(x * x)
                                                                                               + (float)((float)(v21[0].y * v21[0].y) + (float)(z * z)))
                                                                                       * (float)0.5))
                                                                       * (float)v7)
                                                               - (float)1.5)
                                               * (float)v7))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v7
                                                       * (float)((float)((float)(x * x)
                                                                       + (float)((float)(v21[0].y * v21[0].y)
                                                                               + (float)(z * z)))
                                                               * (float)0.5))
                                               * (float)v7)
                                       - (float)1.5)
                       * (float)v7));
    v9 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v7
                                                                                               * (float)((float)((float)(x * x) + (float)((float)(v21[0].y * v21[0].y) + (float)(z * z))) * (float)0.5))
                                                                                       * (float)v7)
                                                                               - (float)1.5)
                                                               * (float)v7)
                                                       * (float)((float)((float)(x * x)
                                                                       + (float)((float)(v21[0].y * v21[0].y)
                                                                               + (float)(z * z)))
                                                               * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)v7
                                                                                       * (float)((float)((float)(x * x) + (float)((float)(v21[0].y * v21[0].y) + (float)(z * z)))
                                                                                               * (float)0.5))
                                                                               * (float)v7)
                                                                       - (float)1.5)
                                                       * (float)v7))
                                       - (float)1.5)
                       * (float)((float)-(float)((float)((float)((float)v7
                                                               * (float)((float)((float)(x * x)
                                                                               + (float)((float)(v21[0].y * v21[0].y)
                                                                                       + (float)(z * z)))
                                                                       * (float)0.5))
                                                       * (float)v7)
                                               - (float)1.5)
                               * (float)v7))
               * (float)((float)((float)(x * x) + (float)((float)(v21[0].y * v21[0].y) + (float)(z * z))) * (float)0.5));
    v21[0].x = hands_meleeOffset.valueFloat
             * (float)(x * (float)((float)-(float)((float)((float)v9 * (float)v8) - (float)1.5) * (float)v8));
    v21[0].y = hands_meleeOffset.valueFloat
             * (float)(v21[0].y * (float)((float)-(float)((float)((float)v9 * (float)v8) - (float)1.5) * (float)v8));
    v21[0].z = hands_meleeOffset.valueFloat
             * (float)(z * (float)((float)-(float)((float)((float)v9 * (float)v8) - (float)1.5) * (float)v8));
    if ( common->IsServer(this: common) )
    {
      if ( p_rightItem != nullptr && idHandsItem::GetTreeAnimatorFromPresentable(this: p_rightItem) != nullptr )
      {
        entity = (idAnimatedEntity *)this->owner->entity;
        TreeAnimatorFromPresentable = idHandsItem::GetTreeAnimatorFromPresentable(this: p_rightItem);
        p_handsMeleeTrace = &this->handsMeleeTrace;
        updated = idMeleeTrace::UpdateTag(
                    this: &this->handsMeleeTrace,
                    owner: entity,
                    ta: TreeAnimatorFromPresentable,
                    ta2: nullptr,
                    offset: v21);
      }
      else
      {
        presentable = this->presentable;
        if ( presentable != nullptr )
          TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: presentable);
        else
          TreeAnimator = nullptr;
        p_handsMeleeTrace = &this->handsMeleeTrace;
        updated = idMeleeTrace::Update(
                    this: &this->handsMeleeTrace,
                    owner: (idAnimatedEntity *)this->owner->entity,
                    ta: TreeAnimator,
                    offset: v21);
      }
      if ( !updated )
        updated = idMeleeTrace::PastUpdate(
                    this: p_handsMeleeTrace,
                    owner: (idActor *)this->owner->entity,
                    pastPos: &this->owner->firstPersonViewOrigin);
    }
    else
    {
      if ( p_rightItem != nullptr && idHandsItem::GetTreeAnimatorFromPresentable(this: p_rightItem) != nullptr )
      {
        v17 = idHandsItem::GetTreeAnimatorFromPresentable(this: p_rightItem);
        v16 = &this->handsMeleeTrace;
        updated = idMeleeTrace::UpdateTag(
                    this: &this->handsMeleeTrace,
                    owner: this->owner,
                    ta: v17,
                    ta2: nullptr,
                    offset: v21);
      }
      else
      {
        v18 = this->presentable;
        if ( v18 != nullptr )
          v19 = idPresentableAnimatedEntity::GetTreeAnimator(this: v18);
        else
          v19 = nullptr;
        v16 = &this->handsMeleeTrace;
        updated = idMeleeTrace::Update(this: &this->handsMeleeTrace, owner: this->owner, ta: v19, offset: v21);
      }
      if ( !updated )
        updated = idMeleeTrace::PastUpdate(this: v16, owner: this->owner, pastPos: &this->owner->firstPersonViewOrigin);
    }
    if ( updated )
    {
      *((_BYTE *)this + 7912) |= 8u;
      this->lastMeleeHitTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idPresentablePlayer::SetControllerShake(
        this: this->owner,
        highMagnitude: 0.5,
        highDuration: v20,
        lowMagnitude: 1.0,
        lowDuration: 250);
      if ( this->handsMeleeTrace.hasKilled )
        this->web.meleeReturnSelector = 1.0;
    }
  }
}


// ========================================================================
// ?JobSync@idHands@@QAAXXZ
// EA  : 0x82DFE250
// RVA : 0x00DFE250
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::JobSync(idHands *this)
{
  idPresentableAnimatedEntity *presentable; // r3
  idTreeAnimator *TreeAnimator; // r31
  idPresentableAnimatedEntity *v4; // r3
  int PlayerGameTime; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: presentable);
  else
    TreeAnimator = nullptr;
  v4 = this->presentable;
  if ( v4 != nullptr )
    idPresentable::UpdateModelTransform(this: v4);
  if ( TreeAnimator != nullptr )
  {
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idTreeAnimator::SyncJoints(this: TreeAnimator, time: PlayerGameTime);
  }
  idHandsItem::JobSync(this: &this->rightItem);
  idHandsItem::JobSync(this: &this->leftItem);
}


// ========================================================================
// ?ModifyAxisForTCAngles@idHands@@QAAXAAVidMat3@@@Z
// EA  : 0x82DFE2E0
// RVA : 0x00DFE2E0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::ModifyAxisForTCAngles(idHands *this, idMat3 *inMat)
{
  float *p_y; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  idHands::handsTCAnglesBlendState_t handsTCAnglesBlendState; // r10
  char v8; // r11
  double v9; // fp12
  idMat3 *v10; // r3
  idMat3 v11[2]; // [sp+50h] [-C0h] BYREF
  idQuat v12[3]; // [sp+A0h] [-70h] BYREF
  idQuat v13; // [sp+D0h] [-40h] BYREF

  p_y = &v11[0].mat[2].y;
  p_z = (_DWORD *)&inMat[-1].mat[2].z;
  for ( i = 9; i != 0; --i )
    *++p_y = *(float *)++p_z;
  idAngles::ToMat3(this: (idAngles *)v12, result: (idMat3 *)&this->handsTCAngles);
  handsTCAnglesBlendState = this->handsTCAnglesBlendState;
  v8 = 0;
  if ( (unsigned int)handsTCAnglesBlendState > HANDSTCBLENDSTATE_OUT_FULL )
    goto LABEL_12;
  if ( handsTCAnglesBlendState != HANDSTCBLENDSTATE_IN )
  {
    if ( handsTCAnglesBlendState == HANDSTCBLENDSTATE_IN_FULL )
      goto LABEL_11;
    if ( handsTCAnglesBlendState != HANDSTCBLENDSTATE_OUT )
    {
      v8 = 0;
      goto LABEL_12;
    }
    v9 = (float)(this->handsTCAnglesBlend - (float)0.1);
    this->handsTCAnglesBlend = this->handsTCAnglesBlend - (float)0.1;
    if ( v9 >= 0.0 )
    {
LABEL_11:
      v8 = 1;
    }
    else
    {
      this->handsTCAnglesBlend = 0.0;
      this->handsTCAnglesBlendState = HANDSTCBLENDSTATE_OUT_FULL;
    }
  }
  else
  {
    v8 = 1;
    this->handsTCAnglesBlendState = HANDSTCBLENDSTATE_IN_FULL;
    this->handsTCAnglesBlend = 1.0;
  }
LABEL_12:
  if ( v8 != 0 )
  {
    idMat3::ToQuat(this: v11, result: (idQuat *)&v11[0].mat[2].z);
    idMat3::ToQuat(this: (idMat3 *)&v11[0].mat[1].y, result: v12);
    v10 = (idMat3 *)idQuat::Lerp(
                      this: (idQuat *)v11,
                      from: (const idQuat *)v11,
                      to: (const idQuat *)&v11[0].mat[1].y,
                      t: this->handsTCAnglesBlend);
    *inMat = *idQuat::ToMat3(this: &v13, result: v10);
  }
}


// ========================================================================
// ?GetFovScale@idHands@@QBAMXZ
// EA  : 0x82DFE448
// RVA : 0x00DFE448
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

float __fastcall idHands::GetFovScale(idHands *this)
{
  double valueFloat; // fp1
  const idDeclInventory *itemDecl; // r11

  if ( g_freeCam.valueInteger != 0 )
    goto LABEL_6;
  valueFloat = hands_fovScale.valueFloat;
  if ( hands_fovScale.valueFloat == 0.0 )
  {
    itemDecl = this->rightItem.itemDecl;
    if ( itemDecl != nullptr || (itemDecl = this->leftItem.itemDecl) != nullptr )
    {
      valueFloat = itemDecl->handsFovScale;
      return *((float *)&valueFloat + 1);
    }
LABEL_6:
    valueFloat = 1.0;
  }
  return *((float *)&valueFloat + 1);
}


// ========================================================================
// ?FreePresentables@idHands@@IAAXXZ
// EA  : 0x82DFE4A8
// RVA : 0x00DFE4A8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::FreePresentables(idHands *this)
{
  idPresentableAnimatedEntity *presentable; // r11
  idRenderModel *model; // r11

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    model = presentable->model;
    if ( model != nullptr )
      *((_BYTE *)&model->g + 104) &= ~4u;
    idPresentable::Delete(this: this->presentable);
    this->presentable = nullptr;
  }
  idHandsItem::FreePresentable(this: &this->rightItem);
  idHandsItem::FreePresentable(this: &this->leftItem);
}


// ========================================================================
// ?SetModelAngles@idHands@@QAAXABVidAngles@@@Z
// EA  : 0x82DFE518
// RVA : 0x00DFE518
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SetModelAngles(idHands *this, const idAngles *angles)
{
  idMat3 *p_modelAxis; // r31
  double z; // fp6
  double v4; // fp9
  double x; // fp8
  double y; // fp7
  double v7; // fp5
  double v8; // fp4
  double v9; // fp2
  double modelScale; // fp3
  double v11; // fp11
  const idMat3 *v12; // r3
  idAngles v13[4]; // [sp+50h] [-40h] BYREF

  this->modelAngles = *angles;
  p_modelAxis = &this->modelAxis;
  this->modelAxis.mat[0].x = mat3_identity.mat[0].x;
  this->modelAxis.mat[0].y = mat3_identity.mat[0].y;
  this->modelAxis.mat[0].z = mat3_identity.mat[0].z;
  this->modelAxis.mat[1] = mat3_identity.mat[1];
  this->modelAxis.mat[2].x = mat3_identity.mat[2].x;
  this->modelAxis.mat[2].y = mat3_identity.mat[2].y;
  z = mat3_identity.mat[2].z;
  this->modelAxis.mat[2].z = mat3_identity.mat[2].z;
  v4 = this->modelAxis.mat[1].z;
  x = this->modelAxis.mat[2].x;
  y = this->modelAxis.mat[2].y;
  v7 = this->modelAxis.mat[0].x;
  v8 = this->modelAxis.mat[0].y;
  v9 = this->modelAxis.mat[0].z;
  modelScale = this->modelScale;
  v11 = (float)(this->modelAxis.mat[1].y * this->modelScale);
  this->modelAxis.mat[1].x = this->modelAxis.mat[1].x * this->modelScale;
  this->modelAxis.mat[1].y = v11;
  this->modelAxis.mat[1].z = (float)v4 * (float)modelScale;
  this->modelAxis.mat[2].x = (float)x * (float)modelScale;
  this->modelAxis.mat[0].z = (float)v9 * (float)modelScale;
  this->modelAxis.mat[0].y = (float)v8 * (float)modelScale;
  this->modelAxis.mat[0].x = (float)v7 * (float)modelScale;
  this->modelAxis.mat[2].y = (float)y * (float)modelScale;
  this->modelAxis.mat[2].z = (float)z * (float)modelScale;
  v12 = idAngles::ToMat3(this: v13, result: (idMat3 *)&this->modelAngles);
  idMat3::operator*=(this: p_modelAxis, a: v12);
}


// ========================================================================
// ?SetModelOffset@idHands@@QAAXABVidVec3@@@Z
// EA  : 0x82DFE640
// RVA : 0x00DFE640
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SetModelOffset(idHands *this, const idVec3 *offset)
{
  this->modelOffset = *offset;
}


// ========================================================================
// ?DetachItem@idHands@@QAAXW4equipSlot_t@@@Z
// EA  : 0x82DFE660
// RVA : 0x00DFE660
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::DetachItem(idHands *this, const equipSlot_t slot)
{
  idHandsItem *p_leftItem; // r31
  idPresentable *Presentable; // r3

  if ( slot == EQUIP_LEFT_HAND )
  {
    p_leftItem = &this->leftItem;
  }
  else
  {
    if ( slot != EQUIP_RIGHT_HAND )
      return;
    p_leftItem = &this->rightItem;
  }
  if ( p_leftItem != nullptr )
  {
    if ( idHandsItem::GetPresentable(this: p_leftItem) != nullptr
      && idHandsItem::GetPresentable(this: p_leftItem)->model != nullptr )
    {
      Presentable = idHandsItem::GetPresentable(this: p_leftItem);
      *((_BYTE *)&Presentable->model->g + 104) &= ~4u;
    }
    idHandsItem::Clear(this: p_leftItem);
  }
}


// ========================================================================
// ?ShowHands@idHands@@IAAXXZ
// EA  : 0x82DFE6F0
// RVA : 0x00DFE6F0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::ShowHands(idHands *this)
{
  idPresentableAnimatedEntity *presentable; // r11

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    presentable->model->g.modelDepthHack = hands_depthHack.valueFloat;
    *((_BYTE *)&this->presentable->model->g + 105) |= 0x80u;
    this->presentable->Show(this: this->presentable);
  }
}


// ========================================================================
// ?CanThrowItem@idHands@@QBA_NPAVidThrowableItem@@@Z
// EA  : 0x82DFE740
// RVA : 0x00DFE740
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

int __fastcall idHands::CanThrowItem(idHands *this, idThrowableItem *item)
{
  idHands::handsAction_t action; // r11
  const idDeclThrowable *throwItem; // r11
  int result; // r3

  action = this->pendingAction.action;
  if ( action == HANDSACTION_COOKITEM )
    return 0;
  if ( action == HANDSACTION_THROWITEM )
    return 0;
  throwItem = this->throwItem;
  result = 1;
  if ( throwItem != nullptr )
    return 0;
  return result;
}


// ========================================================================
// ?GetCurrentWeapon@idHands@@QBAPBVidWeapon@@W4equipSlot_t@@@Z
// EA  : 0x82DFE770
// RVA : 0x00DFE770
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

const idWeapon *__fastcall idHands::GetCurrentWeapon(idHands *this, const equipSlot_t slot)
{
  idHandsItem *p_leftItem; // r11

  if ( slot == EQUIP_LEFT_HAND )
  {
    p_leftItem = &this->leftItem;
  }
  else
  {
    if ( slot != EQUIP_RIGHT_HAND )
      return nullptr;
    p_leftItem = &this->rightItem;
  }
  if ( p_leftItem == nullptr )
    return nullptr;
  return idWeapon::CastTo(c: (idWeapon *)p_leftItem->item);
}


// ========================================================================
// `idHands::PreLoadWeaponSounds'::`2'::local_t::PreLoadSoundList
// EA  : 0x82DFE7A8
// RVA : 0x00DFE7A8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall _idHands::PreLoadWeaponSounds_::_2_::local_t::PreLoadSoundList(
        const idList<projectileEnvSound,5> *list)
{
  int v2; // r29
  int v3; // r31
  idSoundShader *sound0; // r3
  idSoundShader *sound0LoopingEndSound; // r3
  idSoundShader *sound1; // r3
  idSoundShader *sound2; // r3

  v2 = 0;
  if ( list->num > 0 )
  {
    v3 = 0;
    do
    {
      sound0 = list->list[v3].sound0;
      if ( sound0 != nullptr )
        idSoundShader::GetNextEntry(this: sound0, preTouchData: true);
      sound0LoopingEndSound = list->list[v3].sound0LoopingEndSound;
      if ( sound0LoopingEndSound != nullptr )
        idSoundShader::GetNextEntry(this: sound0LoopingEndSound, preTouchData: true);
      sound1 = list->list[v3].sound1;
      if ( sound1 != nullptr )
        idSoundShader::GetNextEntry(this: sound1, preTouchData: true);
      sound2 = list->list[v3].sound2;
      if ( sound2 != nullptr )
        idSoundShader::GetNextEntry(this: sound2, preTouchData: true);
      ++v2;
      ++v3;
    }
    while ( v2 < list->num );
  }
}


// ========================================================================
// ?SetLingeringAction@idHands@@QAAXW4handsAction_t@1@PBVidDeclAmmo@@_N2PBD@Z
// EA  : 0x82DFE858
// RVA : 0x00DFE858
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SetLingeringAction(
        idHands *this,
        idHands::handsAction_t action,
        const idDeclAmmo *ammoDecl,
        bool secondary,
        bool leftHand,
        const char *nodeInfo)
{
  this->lingeringAction.action = HANDSACTION_NONE;
  this->lingeringAction.ammoDecl = nullptr;
  this->lingeringAction.weapon = nullptr;
  this->lingeringAction.throwable = nullptr;
  this->lingeringAction.useIntroBringUp = false;
  this->lingeringAction.isSecondary = false;
  this->lingeringAction.leftHand = false;
  idStr::Clear(this: &this->lingeringAction.extraNodeInfo);
  this->lingeringAction.action = action;
  this->lingeringAction.ammoDecl = ammoDecl;
  this->lingeringAction.isSecondary = secondary;
  this->lingeringAction.leftHand = leftHand;
  if ( nodeInfo != nullptr )
    idStr::operator=(this: &this->lingeringAction.extraNodeInfo, text: nodeInfo);
}


// ========================================================================
// ?SetPendingAction@idHands@@QAAXW4handsAction_t@1@_N@Z
// EA  : 0x82DFE8D8
// RVA : 0x00DFE8D8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SetPendingAction(idHands *this, idHands::handsAction_t action, bool secondary)
{
  this->pendingAction.action = HANDSACTION_NONE;
  this->pendingAction.ammoDecl = nullptr;
  this->pendingAction.weapon = nullptr;
  this->pendingAction.throwable = nullptr;
  this->pendingAction.useIntroBringUp = false;
  this->pendingAction.isSecondary = false;
  this->pendingAction.leftHand = false;
  idStr::Clear(this: &this->pendingAction.extraNodeInfo);
  this->pendingAction.action = action;
  this->pendingAction.isSecondary = secondary;
}


// ========================================================================
// ?SetPendingAction@idHands@@QAAXW4handsAction_t@1@PBD@Z
// EA  : 0x82DFE930
// RVA : 0x00DFE930
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SetPendingAction(idHands *this, idHands::handsAction_t action, const char *nodeInfo)
{
  this->pendingAction.action = HANDSACTION_NONE;
  this->pendingAction.ammoDecl = nullptr;
  this->pendingAction.weapon = nullptr;
  this->pendingAction.throwable = nullptr;
  this->pendingAction.useIntroBringUp = false;
  this->pendingAction.isSecondary = false;
  this->pendingAction.leftHand = false;
  idStr::Clear(this: &this->pendingAction.extraNodeInfo);
  this->pendingAction.action = action;
  if ( nodeInfo != nullptr )
    idStr::operator=(this: &this->pendingAction.extraNodeInfo, text: nodeInfo);
}


// ========================================================================
// ?SetPendingAction@idHands@@QAAXW4handsAction_t@1@PBVidDeclAmmo@@_N2@Z
// EA  : 0x82DFE998
// RVA : 0x00DFE998
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SetPendingAction(
        idHands *this,
        idHands::handsAction_t action,
        const idDeclAmmo *ammoDecl,
        bool secondary,
        bool leftHand)
{
  this->pendingAction.action = HANDSACTION_NONE;
  this->pendingAction.ammoDecl = nullptr;
  this->pendingAction.weapon = nullptr;
  this->pendingAction.throwable = nullptr;
  this->pendingAction.useIntroBringUp = false;
  this->pendingAction.isSecondary = false;
  this->pendingAction.leftHand = false;
  idStr::Clear(this: &this->pendingAction.extraNodeInfo);
  this->pendingAction.action = action;
  this->pendingAction.ammoDecl = ammoDecl;
  this->pendingAction.isSecondary = secondary;
  this->pendingAction.leftHand = leftHand;
}


// ========================================================================
// ?SetPendingAction@idHands@@QAAXW4handsAction_t@1@PAVidWeapon@@_N2@Z
// EA  : 0x82DFEA00
// RVA : 0x00DFEA00
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SetPendingAction(
        idHands *this,
        idHands::handsAction_t action,
        idWeapon *weapon,
        bool useIntroBringUp,
        bool secondary)
{
  idLobbyBase *v10; // r3

  this->pendingAction.action = HANDSACTION_NONE;
  this->pendingAction.ammoDecl = nullptr;
  this->pendingAction.weapon = nullptr;
  this->pendingAction.throwable = nullptr;
  this->pendingAction.useIntroBringUp = false;
  this->pendingAction.isSecondary = false;
  this->pendingAction.leftHand = false;
  idStr::Clear(this: &this->pendingAction.extraNodeInfo);
  this->pendingAction.action = action;
  this->pendingAction.weapon = weapon;
  this->pendingAction.isSecondary = secondary;
  this->pendingAction.useIntroBringUp = (!common->IsMultiplayer(this: common)
                                      || (v10 = session->GetActivePlatformLobbyBase(this: session),
                                          v10->GetMatchParms(this: v10)->gameType != 1))
                                     && useIntroBringUp;
}


// ========================================================================
// ?ClearPendingAction@idHands@@QAAXXZ
// EA  : 0x82DFEAC8
// RVA : 0x00DFEAC8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::ClearPendingAction(idHands *this)
{
  this->pendingAction.action = HANDSACTION_NONE;
  this->pendingAction.ammoDecl = nullptr;
  this->pendingAction.weapon = nullptr;
  this->pendingAction.throwable = nullptr;
  this->pendingAction.useIntroBringUp = false;
  this->pendingAction.isSecondary = false;
  this->pendingAction.leftHand = false;
  idStr::Clear(this: &this->pendingAction.extraNodeInfo);
  this->lastActionTime = idClientGame::GetPlayerGameTime(this: clientGame);
}


// ========================================================================
// ?PistolWhipPending@idHands@@QBA_NXZ
// EA  : 0x82DFEB30
// RVA : 0x00DFEB30
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

BOOL __fastcall idHands::PistolWhipPending(idHands *this)
{
  idWeapon *v2; // r3

  v2 = this->owner->GetEquippedWeapon(this: this->owner);
  return v2 != nullptr
      && LODWORD(v2->decl[2].droppedControllerShake.highMagnitude) != 0
      && (_cntlzw(this->pendingAction.action - 5) & 0x20) != 0;
}


// ========================================================================
// ?UpdateWeaponCondition@idHands@@QAAXPBVidWeapon@@@Z
// EA  : 0x82DFEBB0
// RVA : 0x00DFEBB0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::UpdateWeaponCondition(idHands *this, const idWeapon *weapon)
{
  idAmmoItem *ammoClipSecondary; // r3
  double v4; // fp0

  if ( weapon->weaponState == WEAPONSTATE_SECONDARY )
    ammoClipSecondary = weapon->ammoClipSecondary;
  else
    ammoClipSecondary = weapon->ammoClip;
  if ( ammoClipSecondary->GetCount(this: ammoClipSecondary) <= 0 )
    v4 = 0.0;
  else
    v4 = 2.0;
  this->web.weaponCondition = v4;
}


// ========================================================================
// ?AnimEvent_SoundWeapon@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82DFEC20
// RVA : 0x00DFEC20
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_SoundWeapon(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  const char *str; // r31
  int PlayerGameTime; // r3
  int v9; // r11

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_SoundWeapon - '^2%s^7'\n", PlayerGameTime, str);
  }
  if ( common->IsServer(this: common) )
    v9 = ~(1 << *(_DWORD *)(*(_DWORD *)&result[12] + 1076));
  else
    LOBYTE(v9) = -1;
  idPresentableVehicle::StartSoundShader(
    this: *(idPresentablePlayer **)&result[12],
    channel: SND_CHANNEL_WEAPON,
    shader,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: v9);
  return this;
}


// ========================================================================
// ?AnimEvent_Sound@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82DFECE8
// RVA : 0x00DFECE8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_Sound(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_Sound - '^2%s^7'\n", PlayerGameTime, str);
  }
  idPresentableVehicle::StartSoundShader(
    this: *(idPresentablePlayer **)&result[12],
    channel: SND_CHANNEL_ANY,
    shader,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundVoice@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82DFED70
// RVA : 0x00DFED70
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_SoundVoice(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_SoundVoice - '^2%s^7'\n", PlayerGameTime, str);
  }
  idPresentableVehicle::StartSoundShader(
    this: *(idPresentablePlayer **)&result[12],
    channel: SND_CHANNEL_VOICE,
    shader,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundVoice2@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82DFEDF8
// RVA : 0x00DFEDF8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_SoundVoice2(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_SoundVoice2 - '^2%s^7'\n", PlayerGameTime, str);
  }
  idPresentableVehicle::StartSoundShader(
    this: *(idPresentablePlayer **)&result[12],
    channel: SND_CHANNEL_VOICE2,
    shader,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundBody@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82DFEE80
// RVA : 0x00DFEE80
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_SoundBody(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_SoundBody - '^2%s^7'\n", PlayerGameTime, str);
  }
  idPresentableVehicle::StartSoundShader(
    this: *(idPresentablePlayer **)&result[12],
    channel: SND_CHANNEL_BODY,
    shader,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundBody2@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82DFEF08
// RVA : 0x00DFEF08
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_SoundBody2(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_SoundBody2 - '^2%s^7'\n", PlayerGameTime, str);
  }
  idPresentableVehicle::StartSoundShader(
    this: *(idPresentablePlayer **)&result[12],
    channel: SND_CHANNEL_BODY2,
    shader,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundBody3@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82DFEF90
// RVA : 0x00DFEF90
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_SoundBody3(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_SoundBody3 - '^2%s^7'\n", PlayerGameTime, str);
  }
  idPresentableVehicle::StartSoundShader(
    this: *(idPresentablePlayer **)&result[12],
    channel: SND_CHANNEL_BODY3,
    shader,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SoundItem@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@@Z
// EA  : 0x82DFF018
// RVA : 0x00DFF018
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_SoundItem(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idSoundShader *shader)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_SoundItem - '^2%s^7'\n", PlayerGameTime, str);
  }
  idPresentableVehicle::StartSoundShader(
    this: *(idPresentablePlayer **)&result[12],
    channel: SND_CHANNEL_ITEM,
    shader,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_SetWeaponMode@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@W4setWeaponModeType_t@1@W4equipSlot_t@@@Z
// EA  : 0x82DFF0A0
// RVA : 0x00DFF0A0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_SetWeaponMode(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idHands::setWeaponModeType_t setType,
        equipSlot_t slot)
{
  idWeapon *v9; // r3

  *(_DWORD *)&result[7904] = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v9 = (idWeapon *)(*(int (__fastcall **)(_DWORD, equipSlot_t))(**(_DWORD **)&result[12] + 344))(
                     a1: *(_DWORD *)&result[12],
                     a2: slot);
  if ( v9 == nullptr )
    return this;
  if ( setType == SET_WEAPONMODE_PRIMARY )
  {
    idWeapon::SetWeaponMode(this: v9, secondary: false);
    return this;
  }
  if ( setType == SET_WEAPONMODE_SECONDARY )
    idWeapon::SetWeaponMode(this: v9, secondary: true);
  else
    idWeapon::ToggleWeaponMode(this: v9);
  return this;
}


// ========================================================================
// ?AnimEvent_SetWeaponRelaxed@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@W4setRestStateType_t@1@@Z
// EA  : 0x82DFF140
// RVA : 0x00DFF140
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_SetWeaponRelaxed(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idHands::setRestStateType_t setType)
{
  idHands *v6; // r3

  if ( setType == SET_RESTSTATE_REST )
  {
    result[7929] = (eventVoid)1;
  }
  else if ( setType == SET_RESTSTATE_COMBAT )
  {
    result[7929] = 0;
    *(_DWORD *)&result[7904] = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  }
  else
  {
    result[7929] = (eventVoid)((_cntlzw(*(_BYTE *)&result[7929]) & 0x20) != 0);
  }
  v6 = this;
  if ( *(_BYTE *)&result[7929] != 0 )
    *(_DWORD *)&result[7904] = -10000;
  return v6;
}


// ========================================================================
// ?AnimEvent_SetDualWieldWeapon@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@W4setWeaponDualWieldType_t@1@@Z
// EA  : 0x82DFF1E0
// RVA : 0x00DFF1E0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_SetDualWieldWeapon(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        int setType)
{
  int GameMs; // r3
  eventVoid v8; // r9
  idPresentablePlayer *v9; // r3
  bool v11; // r4
  int v12; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v8 = result[7912];
  *(_DWORD *)&result[7904] = GameMs;
  if ( (*(_BYTE *)&v8 & 4) != 0 )
    setType = 2;
  if ( (unsigned int)(setType - 1) > 3 )
  {
    *(_DWORD *)&result[7956] = ((_cntlzw(*(_DWORD *)&result[7956] - 1) & 0x20) != 0) + 1;
    goto LABEL_21;
  }
  if ( setType == 2 )
  {
    if ( *(_DWORD *)&result[7956] == 2 )
      return this;
    *(_DWORD *)&result[7956] = 2;
LABEL_21:
    v11 = false;
    goto LABEL_22;
  }
  if ( setType == 3 )
  {
    if ( *(_DWORD *)&result[7956] != 2 )
    {
      *(_DWORD *)&result[7956] = 2;
      v11 = true;
LABEL_22:
      idPresentablePlayer::ToggleDualWieldItem(
        this: *(idPresentablePlayer **)&result[12],
        justClear: v11,
        leftWeaponToRightHand: false,
        forceOn: false);
    }
    return this;
  }
  if ( setType != 1 )
  {
    if ( g_infiniteAmmo.valueInteger == 0 && g_permaInfiniteAmmo.valueInteger == 0 && *(_DWORD *)&result[7956] != 2 )
    {
      *(_DWORD *)&result[7956] = 2;
      idPresentablePlayer::ToggleDualWieldItem(
        this: *(idPresentablePlayer **)&result[12],
        justClear: false,
        leftWeaponToRightHand: true,
        forceOn: false);
      v12 = (*(int (__fastcall **)(_DWORD, int))(**(_DWORD **)&result[12] + 344))(a1: *(_DWORD *)&result[12], a2: 2);
      if ( v12 != 0 )
      {
        *(_BYTE *)(v12 + 452) &= ~1u;
        return this;
      }
    }
    return this;
  }
  v9 = *(idPresentablePlayer **)&result[12];
  if ( *(_DWORD *)&result[7956] == 1 )
  {
    idPresentablePlayer::ToggleDualWieldItem(this: v9, justClear: false, leftWeaponToRightHand: false, forceOn: true);
  }
  else
  {
    *(_DWORD *)&result[7956] = 1;
    idPresentablePlayer::ToggleDualWieldItem(this: v9, justClear: false, leftWeaponToRightHand: false, forceOn: false);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_CycleWeaponFiremode@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFF380
// RVA : 0x00DFF380
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_CycleWeaponFiremode(idHands *this, eventVoid *result, const idMD6Anim *anim)
{
  idWeapon *v5; // r3

  *(_DWORD *)&result[7904] = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v5 = (idWeapon *)(*(int (__fastcall **)(_DWORD, int))(**(_DWORD **)&result[12] + 344))(
                     a1: *(_DWORD *)&result[12],
                     a2: 2);
  idWeapon::ToggleFireMode(this: v5, justFetchNextMode: false, ignoreMode: false);
  return this;
}


// ========================================================================
// ?AnimEvent_SetPendingVariationIndex@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFF3F8
// RVA : 0x00DFF3F8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idHands::AnimEvent_SetPendingVariationIndex@<r4>(
        idHands *this@<r3>,
        int result@<r4>,
        const idMD6Anim *anim@<r5>)
{
  int v3; // r11

  v3 = *(_DWORD *)(result + 7920);
  if ( v3 != -1 )
  {
    *(_DWORD *)(result + 7916) = v3;
    *(_DWORD *)(result + 7920) = -1;
  }
  return result;
}


// ========================================================================
// ?AnimEvent_RightWeaponFullSpinThrottle@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@H@Z
// EA  : 0x82DFF418
// RVA : 0x00DFF418
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_RightWeaponFullSpinThrottle(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const int throttle)
{
  idHandsItem::SetBarrelSpinThrottle(this: (idHandsItem *)&result[2996], fullThrottle: throttle > 0);
  return this;
}


// ========================================================================
// ?AnimEvent_EmptyWeaponAndReload@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@W4equipSlot_t@@@Z
// EA  : 0x82DFF460
// RVA : 0x00DFF460
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_EmptyWeaponAndReload(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        equipSlot_t slot)
{
  idWeapon *v6; // r31
  const idDeclJob *decl; // r29
  idJobManager *v8; // r3
  idInventoryItem *JobByDecl; // r29
  int v10; // r3

  v6 = (idWeapon *)(*(int (__fastcall **)(_DWORD, equipSlot_t))(**(_DWORD **)&result[12] + 344))(
                     a1: *(_DWORD *)&result[12],
                     a2: slot);
  idWeapon::SetFireState(this: v6, fs: FIRESTATE_RELOADING);
  decl = (const idDeclJob *)v6->ammoClip->decl;
  v8 = (idJobManager *)(*(int (__fastcall **)(_DWORD))(**(_DWORD **)&result[12] + 324))(a1: *(_DWORD *)&result[12]);
  JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v8, jobDecl: decl);
  if ( JobByDecl != nullptr )
  {
    v10 = v6->ammoClip->GetCount(this: v6->ammoClip);
    idInventoryItem::ModifyCount(this: JobByDecl, amount: v10);
  }
  idInventoryItem::SetCount(this: &v6->ammoClip->idInventoryItem, amount: 0);
  result[7644] = (eventVoid)1;
  return this;
}


// ========================================================================
// ?AnimEvent_AddPlayerWhiplash@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@MMM@Z
// EA  : 0x82DFF508
// RVA : 0x00DFF508
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_AddPlayerWhiplash(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        double pitch,
        double yaw,
        double roll)
{
  idPlayer *Player; // r3
  idPresentable *presentable; // r3
  int v12; // r3
  idAngles v14; // [sp+50h] [-40h] BYREF

  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  if ( Player != nullptr )
  {
    v14.pitch = pitch;
    v14.yaw = yaw;
    v14.roll = roll;
    presentable = Player->presentable;
    if ( presentable != nullptr )
      v12 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v12 = 0;
    idView::AddCustomWhiplash(
      this: (idView *)(v12 + 16224),
      angles: &v14,
      updateFrac: 1.0,
      velocityFrac: 0.0049999999,
      frictionFrac: 0.94999999,
      minVelocityLen: 0.000099999997);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_SetInteruptable@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFF5D0
// RVA : 0x00DFF5D0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_SetInteruptable(idHands *this, eventVoid *result, const idMD6Anim *anim)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_SetInteruptable- '^2%s^7'\n", PlayerGameTime, str);
  }
  result[7648] = (eventVoid)1;
  return this;
}


// ========================================================================
// ?AnimEvent_AttachThrowItemToLeftItem@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82DFF648
// RVA : 0x00DFF648
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_AttachThrowItemToLeftItem(
        idHands *this,
        idHands *result,
        const idMD6Anim *anim,
        const char *slotName)
{
  const char *str; // r31
  int PlayerGameTime; // r3
  equipSlot_t v10; // r6

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_AttachThrowItemToLeftItem - '^2%s^7'\n", PlayerGameTime, str);
  }
  if ( result->throwItem != nullptr )
  {
    v10 = idDeclInventory::EquipSlotForName(name: slotName);
    if ( v10 != EQUIP_NONE )
      idHandsItem::Attach(this: &result->leftItem, hands: result, itemDecl: result->throwItem, slot: v10, initFX: true);
    return this;
  }
  else
  {
    idLib::Warning(fmt: "throwItem is NULL in AnimEvent_AttachThrowItemToLeftItem");
    return this;
  }
}


// ========================================================================
// ?AnimEvent_UpdateWeaponMeshes@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFF708
// RVA : 0x00DFF708
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_UpdateWeaponMeshes(idHands *this, eventVoid *result, const idMD6Anim *anim)
{
  int valueInteger; // r11
  const char *str; // r30
  int PlayerGameTime; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r30
  int v10; // r3
  int v11; // r3

  valueInteger = hands_debugfc.valueInteger;
  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_UpdateWeaponMeshes - '^2%s^7'\n", PlayerGameTime, str);
    valueInteger = hands_debugfc.valueInteger;
  }
  if ( result == (eventVoid *)-2996 )
  {
    if ( valueInteger > 0 )
    {
      idLib::Warning(fmt: "handsItem == NULL");
      return this;
    }
  }
  else
  {
    TreeAnimatorFromPresentable = idHandsItem::GetTreeAnimatorFromPresentable(this: (idHandsItem *)&result[2996]);
    if ( TreeAnimatorFromPresentable != nullptr )
    {
      v10 = (*(int (__fastcall **)(_DWORD, int))(**(_DWORD **)&result[12] + 344))(a1: *(_DWORD *)&result[12], a2: 2);
      if ( v10 != 0 )
      {
        (*(void (__fastcall **)(int, idTreeAnimator *))(*(_DWORD *)v10 + 164))(a1: v10, a2: TreeAnimatorFromPresentable);
        v11 = (*(int (__fastcall **)(_DWORD, int))(**(_DWORD **)&result[12] + 344))(a1: *(_DWORD *)&result[12], a2: 1);
        if ( v11 != 0 )
          (*(void (__fastcall **)(int, idTreeAnimator *))(*(_DWORD *)v11 + 164))(
            a1: v11,
            a2: TreeAnimatorFromPresentable);
      }
      else if ( hands_debugfc.valueInteger > 0 )
      {
        idLib::Warning(fmt: "weapon == NULL");
        return this;
      }
    }
    else if ( hands_debugfc.valueInteger > 0 )
    {
      idLib::Warning(fmt: "animator == NULL on handsItem");
      return this;
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_ClearLeftItem@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82DFF860
// RVA : 0x00DFF860
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_ClearLeftItem(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const char *slotName)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_ClearLeftItem - %s '^2%s^7'\n", PlayerGameTime, slotName, str);
  }
  idHandsItem::Clear(this: (idHandsItem *)&result[4532]);
  return this;
}


// ========================================================================
// ?AnimEvent_HandsStartFXRight@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@W4fxCondition_t@@@Z
// EA  : 0x82DFF8E0
// RVA : 0x00DFF8E0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_HandsStartFXRight(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        fxCondition_t condition)
{
  idHandsItem::StartFX(this: (idHandsItem *)&result[2996], cond: condition);
  return this;
}


// ========================================================================
// ?AnimEvent_HandsStopFXRight@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@W4fxCondition_t@@@Z
// EA  : 0x82DFF920
// RVA : 0x00DFF920
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_HandsStopFXRight(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        fxCondition_t condition)
{
  idHandsItem::StopFX(this: (idHandsItem *)&result[2996], cond: condition);
  return this;
}


// ========================================================================
// ?AnimEvent_StartPlayerFX@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@W4fxCondition_t@@@Z
// EA  : 0x82DFF960
// RVA : 0x00DFF960
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_StartPlayerFX(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        fxCondition_t condition)
{
  (*(void (__fastcall **)(_DWORD, fxCondition_t, _DWORD))(**(_DWORD **)&result[1588] + 252))(
    a1: *(_DWORD *)&result[1588],
    a2: condition,
    a3: 0);
  result[8024] = (eventVoid)1;
  return this;
}


// ========================================================================
// ?AnimEvent_ZoomSnap@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFF9C0
// RVA : 0x00DFF9C0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idHands::AnimEvent_ZoomSnap@<r4>(idHands *this@<r3>, int result@<r4>, const idMD6Anim *anim@<r5>)
{
  int v3; // r11

  v3 = *(_DWORD *)(result + 12);
  if ( v3 != 0 )
    *(_BYTE *)(v3 + 48722) = 1;
  return result;
}


// ========================================================================
// ?AnimEvent_StartMelee@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFF9E0
// RVA : 0x00DFF9E0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idHands::AnimEvent_StartMelee@<r4>(idHands *this@<r3>, int result@<r4>, const idMD6Anim *anim@<r5>)
{
  char v3; // r9

  v3 = *(_BYTE *)(result + 7912);
  *(_BYTE *)(result + 7647) = 1;
  *(_BYTE *)(result + 7912) = v3 & 0xF7;
  return result;
}


// ========================================================================
// ?AnimEvent_EndMelee@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFFA00
// RVA : 0x00DFFA00
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_EndMelee(idHands *this, eventVoid *result, const idMD6Anim *anim)
{
  int v4; // r9

  v4 = *(_BYTE *)&result[7912] & 8;
  result[7647] = 0;
  if ( v4 != 0 )
  {
    ++*(_DWORD *)&result[7892];
    *(_DWORD *)&result[7896] = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_SetNextAttackAvailable@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFFA78
// RVA : 0x00DFFA78
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_SetNextAttackAvailable(idHands *this, eventVoid *result, const idMD6Anim *anim)
{
  idWeapon *Equipped; // r3
  idWeapon *v5; // r11
  idHands *v6; // r3

  Equipped = (idWeapon *)idPresentablePlayer::GetEquipped(
                           this: *(idPresentablePlayer **)&result[12],
                           slot: EQUIP_RIGHT_HAND);
  if ( Equipped == nullptr )
    return this;
  v5 = idWeapon::CastTo(c: Equipped);
  v6 = this;
  if ( v5 != nullptr )
    v5->nextFireTime = 0;
  return v6;
}


// ========================================================================
// ?AnimEvent_CanInteruptCooking@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFFAF0
// RVA : 0x00DFFAF0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idHands::AnimEvent_CanInteruptCooking@<r4>(
        idHands *this@<r3>,
        int result@<r4>,
        const idMD6Anim *anim@<r5>)
{
  *(_BYTE *)(result + 7668) = 1;
  return result;
}


// ========================================================================
// ?AnimEvent_ChamberAmmo@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFFB00
// RVA : 0x00DFFB00
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_ChamberAmmo(idHands *this, eventVoid *result, const idMD6Anim *anim)
{
  const char *str; // r31
  int PlayerGameTime; // r3
  idHandsItem *v7; // r31
  idWeapon *v8; // r30
  idFXManager *FXMgr; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_ChamberAmmo - '^2%s^7'\n", PlayerGameTime, str);
  }
  v7 = (idHandsItem *)&result[2996];
  if ( result != (eventVoid *)-2996 )
  {
    v8 = idWeapon::CastTo(c: *(idWeapon **)&result[4448]);
    if ( v8 != nullptr )
    {
      FXMgr = idHandsItem::GetFXMgr(this: v7);
      idWeapon::OnChamberAmmo(this: v8, fxMgr: FXMgr);
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_HideChamberedAmmo@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFFBA0
// RVA : 0x00DFFBA0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_HideChamberedAmmo(idHands *this, eventVoid *result, const idMD6Anim *anim)
{
  const char *str; // r31
  int PlayerGameTime; // r3
  idHandsItem *v7; // r31
  idWeapon *v8; // r30
  idTreeAnimator *TreeAnimatorFromPresentable; // r4

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_HideChamberedAmmo - '^2%s^7'\n", PlayerGameTime, str);
  }
  v7 = (idHandsItem *)&result[2996];
  if ( result != (eventVoid *)-2996 )
  {
    v8 = idWeapon::CastTo(c: *(idWeapon **)&result[4448]);
    if ( v8 != nullptr )
    {
      TreeAnimatorFromPresentable = idHandsItem::GetTreeAnimatorFromPresentable(this: v7);
      if ( TreeAnimatorFromPresentable != nullptr )
        idWeapon::HideChamberedAmmo(this: v8, animator: TreeAnimatorFromPresentable);
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_ShowChamberedAmmo@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFFC48
// RVA : 0x00DFFC48
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_ShowChamberedAmmo(idHands *this, eventVoid *result, const idMD6Anim *anim)
{
  const char *str; // r31
  int PlayerGameTime; // r3
  idHandsItem *v7; // r31
  idWeapon *v8; // r30
  idTreeAnimator *TreeAnimatorFromPresentable; // r4
  idFXManager *FXMgr; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_ShowChamberedAmmo - '^2%s^7'\n", PlayerGameTime, str);
  }
  v7 = (idHandsItem *)&result[2996];
  if ( result != (eventVoid *)-2996 )
  {
    v8 = idWeapon::CastTo(c: *(idWeapon **)&result[4448]);
    if ( v8 != nullptr )
    {
      TreeAnimatorFromPresentable = idHandsItem::GetTreeAnimatorFromPresentable(this: v7);
      if ( TreeAnimatorFromPresentable != nullptr )
      {
        idWeapon::ShowChamberedAmmo(this: v8, animator: TreeAnimatorFromPresentable);
        FXMgr = idHandsItem::GetFXMgr(this: v7);
        idWeapon::OnChamberAmmo(this: v8, fxMgr: FXMgr);
      }
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_HideHandsItem@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFFD00
// RVA : 0x00DFFD00
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_HideHandsItem(idHands *this, eventVoid *result, const idMD6Anim *anim)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_HideHandsItem - '^2%s^7'\n", PlayerGameTime, str);
  }
  if ( result != (eventVoid *)-2996 )
    idHandsItem::Hide(this: (idHandsItem *)&result[2996]);
  if ( result != (eventVoid *)-4532 )
    idHandsItem::Hide(this: (idHandsItem *)&result[4532]);
  return this;
}


// ========================================================================
// ?AnimEvent_ShowHandsItem@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFFD88
// RVA : 0x00DFFD88
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_ShowHandsItem(idHands *this, eventVoid *result, const idMD6Anim *anim)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_ShowHandsItem - '^2%s^7'\n", PlayerGameTime, str);
  }
  if ( result != (eventVoid *)-2996 )
    idHandsItem::Show(this: (idHandsItem *)&result[2996]);
  if ( result != (eventVoid *)-4532 )
    idHandsItem::Show(this: (idHandsItem *)&result[4532]);
  return this;
}


// ========================================================================
// ?AnimEvent_AttachEquippedWeapon@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82DFFE10
// RVA : 0x00DFFE10
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_AttachEquippedWeapon(idHands *this, idHands *result, const idMD6Anim *anim)
{
  idInventoryItem *v5; // r5

  v5 = result->owner->GetEquippedWeapon(this: result->owner);
  if ( v5 != nullptr )
    idHandsItem::Attach(this: &result->rightItem, hands: result, item: v5, slot: EQUIP_RIGHT_HAND, initFX: true);
  return this;
}


// ========================================================================
// ?AnimEvent_DeclParticle@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclParticle@@PBD@Z
// EA  : 0x82DFFE80
// RVA : 0x00DFFE80
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_DeclParticle(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idDeclParticle *particleDecl,
        const char *jointName)
{
  const char *str; // r31
  int PlayerGameTime; // r3
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v12; // r31
  idRenderModelParms *p_deferredOrigin; // r11
  float y; // r9
  float z; // r8
  idMat3 *p_deferredAxis; // r11
  idVec3 *v17; // r10
  float *p_z; // r11
  int i; // ctr
  __int64 v20; // r9
  unsigned int v21; // r5
  double v22; // fp31
  int GameMsPerFrame; // r31
  int v24; // r30
  idRenderModelEffects *MergeBranch; // r3
  int v27; // [sp+8h] [-E8h]
  int v28; // [sp+Ch] [-E4h]
  int v29; // [sp+10h] [-E0h]
  int v30; // [sp+14h] [-DCh]
  int v31; // [sp+18h] [-D8h]
  int v32; // [sp+1Ch] [-D4h]
  int v33; // [sp+20h] [-D0h]
  int v34; // [sp+24h] [-CCh]
  int v35; // [sp+28h] [-C8h]
  int v36; // [sp+2Ch] [-C4h]
  int v37; // [sp+30h] [-C0h]
  int v38; // [sp+34h] [-BCh]
  int v39; // [sp+38h] [-B8h]
  int v40; // [sp+3Ch] [-B4h]
  int v41; // [sp+40h] [-B0h]
  int v42; // [sp+44h] [-ACh]
  int v43; // [sp+48h] [-A8h]
  int v44; // [sp+4Ch] [-A4h]
  int v45; // [sp+50h] [-A0h]
  unsigned __int16 v46; // [sp+60h] [-90h] BYREF
  idVec3 v47; // [sp+64h] [-8Ch] BYREF
  idMat3 v48; // [sp+70h] [-80h] BYREF

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_DeclParticle - '^2%s^7'\n", PlayerGameTime, str);
  }
  if ( particleDecl != nullptr && result != (eventVoid *)-2996 )
  {
    TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idHandsItem::GetTreeAnimatorFromPresentable(this: (idHandsItem *)&result[2996]);
    v12 = (idTreeAnimator *)TreeAnimatorFromPresentable;
    if ( TreeAnimatorFromPresentable != nullptr )
    {
      idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v46, result: TreeAnimatorFromPresentable, jointName);
      p_deferredOrigin = (idRenderModelParms *)&v12->deferredOrigin;
      if ( !v12->useDeferredPosition )
        p_deferredOrigin = &v12->g;
      y = p_deferredOrigin->origin.y;
      z = p_deferredOrigin->origin.z;
      v48.mat[0].x = p_deferredOrigin->origin.x;
      p_deferredAxis = &v12->deferredAxis;
      v48.mat[0].y = y;
      v48.mat[0].z = z;
      if ( !v12->useDeferredPosition )
        p_deferredAxis = &v12->g.axis;
      v17 = &v48.mat[1];
      p_z = &p_deferredAxis[-1].mat[2].z;
      for ( i = 9; i != 0; --i )
      {
        ++p_z;
        v17 = (idVec3 *)((char *)v17 + 4);
        v17->x = *p_z;
      }
      if ( (v46 & 0x8000u) == 0 )
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: v12,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)v46,
          origin: v48.mat,
          axis: (idMat3 *)&v48.mat[1].y);
      HIDWORD(v20) = 1664525;
      v47.x = NAN;
      v21 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v21 + 1013904223;
      LODWORD(v20) = ((v21 + 1013904223) >> 10) & 0x7FFF;
      *(_QWORD *)&v47.y = v20;
      v22 = (float)((float)v20 * (float)0.000030518509);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v24 = idClientGame::GetPlayerGameTime(this: clientGame);
      MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
      idRenderModelEffects::AddParticles(
        this: MergeBranch,
        particle: particleDecl,
        systemStartTime: v24,
        gameMsPerFrame: GameMsPerFrame,
        diversity: v22,
        origin: &v47,
        axis: &v48,
        velocity: (const idVec3 *)&v48.mat[1].y,
        color: &vec3_origin.x,
        a10: v27,
        a11: v28,
        a12: v29,
        a13: v30,
        a14: v31,
        a15: v32,
        a16: v33,
        a17: v34,
        a18: v35,
        a19: v36,
        a20: v37,
        a21: v38,
        a22: v39,
        a23: v40,
        a24: v41,
        a25: v42,
        a26: v43,
        a27: v44,
        a28: v45,
        a29: (unsigned int *)&v47);
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_HandsStartMeleeTrace@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@@Z
// EA  : 0x82E00058
// RVA : 0x00E00058
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_HandsStartMeleeTrace(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idJointName *jointName)
{
  const char *str; // r30
  int PlayerGameTime; // r3
  idIndex<short,enum invalidJointIndex_t> *TreeAnimator; // r29
  idPresentableAnimatedEntity *v10; // r3
  idPresentablePlayer *v12; // r3
  idWeapon *Equipped; // r3
  idWeapon *v14; // r3
  const idDeclInventory *decl; // r11
  float highMagnitude; // r11
  const idIndex<short,enum invalidJointIndex_t> *v17; // r5
  idMeleeTrace *v18; // r3
  bool v19; // zf
  bool v20; // r3
  int v21; // r4
  __int16 v22; // [sp+60h] [-50h] BYREF

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_HandsStartMeleeTrace - '^2%s^7'\n", PlayerGameTime, str);
  }
  *(_BYTE *)&result[7912] &= ~8u;
  TreeAnimator = nullptr;
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - *(_DWORD *)&result[7896] > hands_meleeComboInterval.valueInteger )
    *(_DWORD *)&result[7892] = 0;
  v10 = *(idPresentableAnimatedEntity **)&result[1588];
  if ( v10 != nullptr )
    TreeAnimator = (idIndex<short,enum invalidJointIndex_t> *)idPresentableAnimatedEntity::GetTreeAnimator(this: v10);
  idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v22, result: TreeAnimator, jointName: jointName->data);
  if ( v22 < 0 )
  {
    idLib::Warning(fmt: "idHands::AnimEvent_HandsStartMeleeTrace invalidJointIndex");
    return this;
  }
  v12 = *(idPresentablePlayer **)&result[12];
  *(float *)&result[2252] = 0.0;
  Equipped = (idWeapon *)idPresentablePlayer::GetEquipped(this: v12, slot: EQUIP_RIGHT_HAND);
  v14 = idWeapon::CastTo(c: Equipped);
  if ( v14 != nullptr
    && (decl = v14->decl) != nullptr
    && (highMagnitude = decl[2].droppedControllerShake.highMagnitude) != 0.0 )
  {
    v17 = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v22;
    *(_DWORD *)&result[7696] = 1;
    idMeleeTrace::Start(
      this: (idMeleeTrace *)&result[7684],
      ta: (const idTreeAnimator *)TreeAnimator,
      jointIndex_: v17,
      numSamples_: 20,
      damageCap_: 100.0,
      meleeType_: (const idMeleeTrace::meleeDamage_t)&unk_82150000,
      boundsType_: BOUNDS_16x16,
      damageDef_: (const idDeclDamage *)7,
      impactEffect_: *(const idDeclProjectileImpactEffect **)(LODWORD(highMagnitude) + 444));
    v19 = !common->IsServer(this: common);
    v18 = (idMeleeTrace *)&result[7684];
    if ( v19 )
      v20 = idMeleeTrace::PastUpdate(
              this: v18,
              owner: *(idPresentable **)&result[12],
              pastPos: (const idVec3 *)(*(_DWORD *)&result[12] + 46532));
    else
      v20 = idMeleeTrace::PastUpdate(
              this: v18,
              owner: *(idActor **)(*(_DWORD *)&result[12] + 1096),
              pastPos: (const idVec3 *)(*(_DWORD *)&result[12] + 46532));
    if ( v20 )
    {
      *(_BYTE *)&result[7912] |= 8u;
      *(_DWORD *)&result[7896] = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idPresentablePlayer::SetControllerShake(
        this: *(idPresentablePlayer **)&result[12],
        highMagnitude: 0.5,
        highDuration: v21,
        lowMagnitude: 1.0,
        lowDuration: 250);
      if ( *(_BYTE *)&result[7739] != 0 )
      {
        *(float *)&result[2252] = 1.0;
        return this;
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "idHands::AnimEvent_HandsStartMeleeTrace could not find pistolWhipProjectile");
  }
  return this;
}


// ========================================================================
// ?AnimEvent_HandsStartMeleeTraceTag@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82E002B0
// RVA : 0x00E002B0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_HandsStartMeleeTraceTag(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const char *tagName)
{
  const char *str; // r31
  int PlayerGameTime; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v10; // r31
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r3
  BOOL useDeferredPosition; // r10
  idRenderModelParms *p_deferredOrigin; // r11
  float y; // r8
  float z; // r7
  idMat3 *p_deferredAxis; // r11
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *p_parentJoint; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  const tagData_t *Tag; // r3
  char *v23; // r10
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *v24; // r11
  int j; // ctr
  idWeapon *Equipped; // r3
  idWeapon *v27; // r3
  const idDeclInventory *v28; // r11
  idMeleeTrace *v29; // r3
  bool v30; // zf
  bool v31; // r3
  int v32; // r4
  const idDeclProjectileImpactEffect *v33; // [sp+8h] [-F8h]
  idVec3 v34; // [sp+60h] [-A0h] BYREF
  char v35; // [sp+6Ch] [-94h] BYREF
  tagData_t v36; // [sp+70h] [-90h] BYREF
  idMat3 v37; // [sp+90h] [-70h] BYREF

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_HandsStartMeleeTraceTag - '^2%s^7'\n", PlayerGameTime, str);
  }
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - *(_DWORD *)&result[7896] > hands_meleeComboInterval.valueInteger )
    *(_DWORD *)&result[7892] = 0;
  if ( result == (eventVoid *)-2996 )
  {
    idLib::Warning(fmt: "idHands::AnimEvent_HandsStartMeleeTraceTag no hands item");
  }
  else
  {
    TreeAnimatorFromPresentable = idHandsItem::GetTreeAnimatorFromPresentable(this: (idHandsItem *)&result[2996]);
    v10 = TreeAnimatorFromPresentable;
    if ( TreeAnimatorFromPresentable == nullptr )
    {
      idLib::Warning(fmt: "idHands::AnimEvent_HandsStartMeleeTraceTag could not find animator for handsitem");
      return this;
    }
    *(float *)&result[2252] = 0.0;
    decl = TreeAnimatorFromPresentable->decl;
    if ( decl == nullptr || (p_props = &decl->props, decl == (const idDeclMD6 *)-352) )
    {
      idLib::Warning(fmt: "idHands::AnimEvent_HandsStartMeleeTraceTag no props on animator");
      return this;
    }
    useDeferredPosition = v10->useDeferredPosition;
    p_deferredOrigin = (idRenderModelParms *)&v10->deferredOrigin;
    if ( !v10->useDeferredPosition )
      p_deferredOrigin = &v10->g;
    y = p_deferredOrigin->origin.y;
    z = p_deferredOrigin->origin.z;
    v34.x = p_deferredOrigin->origin.x;
    p_deferredAxis = &v10->deferredAxis;
    v34.y = y;
    v34.z = z;
    if ( !useDeferredPosition )
      p_deferredAxis = &v10->g.axis;
    p_parentJoint = &v36.parentJoint;
    p_z = (_DWORD *)&p_deferredAxis[-1].mat[2].z;
    for ( i = 9; i != 0; --i )
    {
      ++p_z;
      p_parentJoint += 2;
      *(_DWORD *)&p_parentJoint->value = *p_z;
    }
    Tag = idPropsCollection::GetTag(this: p_props, propName: "_info", tagName);
    v23 = &v35;
    v24 = &Tag[-1].parentJoint;
    for ( j = 8; j != 0; --j )
    {
      v24 += 2;
      v23 += 4;
      *(_DWORD *)v23 = *(_DWORD *)&v24->value;
    }
    idTreeAnimator::GetWorldSpaceTagTransform(this: v10, tagData: &v36, origin: &v34, axis: &v37);
    Equipped = (idWeapon *)idPresentablePlayer::GetEquipped(
                             this: *(idPresentablePlayer **)&result[12],
                             slot: EQUIP_RIGHT_HAND);
    v27 = idWeapon::CastTo(c: Equipped);
    if ( v27 == nullptr || (v28 = v27->decl) == nullptr || LODWORD(v28[2].droppedControllerShake.highMagnitude) == 0 )
    {
      idLib::Warning(fmt: "idHands::AnimEvent_HandsStartMeleeTraceTag could not find pistolWhipProjectile");
      return this;
    }
    idMeleeTrace::Start(
      this: (idMeleeTrace *)&result[7684],
      startPos: &v34,
      tagData_: &v36,
      useWeaponAnimator_: false,
      numSamples_: 20,
      damageCap_: 100.0,
      meleeType_: (const idMeleeTrace::meleeDamage_t)&unk_82150000,
      bounds_: BOUNDS_16x16,
      damageDef_: (const idDeclDamage *)7,
      impactEffect_: v33);
    v30 = !common->IsServer(this: common);
    v29 = (idMeleeTrace *)&result[7684];
    if ( v30 )
      v31 = idMeleeTrace::PastUpdate(
              this: v29,
              owner: *(idPresentable **)&result[12],
              pastPos: (const idVec3 *)(*(_DWORD *)&result[12] + 46532));
    else
      v31 = idMeleeTrace::PastUpdate(
              this: v29,
              owner: *(idActor **)(*(_DWORD *)&result[12] + 1096),
              pastPos: (const idVec3 *)(*(_DWORD *)&result[12] + 46532));
    if ( v31 )
    {
      *(_BYTE *)&result[7912] |= 8u;
      *(_DWORD *)&result[7896] = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idPresentablePlayer::SetControllerShake(
        this: *(idPresentablePlayer **)&result[12],
        highMagnitude: 0.5,
        highDuration: v32,
        lowMagnitude: 1.0,
        lowDuration: 250);
      if ( *(_BYTE *)&result[7739] != 0 )
      {
        *(float *)&result[2252] = 1.0;
        return this;
      }
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_HandsEndMeleeTrace@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82E005C8
// RVA : 0x00E005C8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_HandsEndMeleeTrace(idHands *this, eventVoid *result, const idMD6Anim *anim)
{
  const char *str; // r30
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_HandsEndMeleeTrace - '^2%s^7'\n", PlayerGameTime, str);
  }
  idRibbon::~idRibbon(this: (idRibbon *)&result[7684]);
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - *(_DWORD *)&result[7896] <= hands_meleeComboInterval.valueInteger )
  {
    if ( (*(_BYTE *)&result[7912] & 8) != 0 )
    {
      ++*(_DWORD *)&result[7892];
      *(_DWORD *)&result[7896] = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    }
    return this;
  }
  else
  {
    *(_DWORD *)&result[7892] = 0;
    return this;
  }
}


// ========================================================================
// ?AnimEvent_HandsStartMeleeTraceSimple@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82E006B8
// RVA : 0x00E006B8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_HandsStartMeleeTraceSimple(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim)
{
  const char *str; // r30
  int PlayerGameTime; // r3
  idPresentablePlayer *v7; // r3
  idWeapon *Equipped; // r3
  idWeapon *v9; // r3
  const idDeclInventory *decl; // r11
  float highMagnitude; // r11
  idMeleeTrace::meleeDamage_t v12; // r6
  float *v13; // r10
  float v14; // r3
  float v15; // r26
  double v16; // fp11
  double v17; // fp6
  double v18; // fp4
  idMeleeTrace *v19; // r3
  bool v20; // zf
  bool v21; // r3
  int v22; // r4
  idVec3 v24; // [sp+50h] [-60h] BYREF
  idVec3 v25; // [sp+60h] [-50h] BYREF

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_HandsStartMeleeTraceSimple - '^2%s^7'\n", PlayerGameTime, str);
  }
  *(_BYTE *)&result[7912] &= ~8u;
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - *(_DWORD *)&result[7896] > hands_meleeComboInterval.valueInteger )
    *(_DWORD *)&result[7892] = 0;
  v7 = *(idPresentablePlayer **)&result[12];
  *(float *)&result[2252] = 0.0;
  Equipped = (idWeapon *)idPresentablePlayer::GetEquipped(this: v7, slot: EQUIP_RIGHT_HAND);
  v9 = idWeapon::CastTo(c: Equipped);
  if ( v9 != nullptr )
    decl = v9->decl;
  else
    decl = nullptr;
  if ( decl == nullptr || (highMagnitude = decl[2].droppedControllerShake.highMagnitude) == 0.0 )
  {
    idLib::Warning(fmt: "idHands::AnimEvent_HandsStartMeleeTraceSimple could not find pistolWhipProjectile");
  }
  else
  {
    v12 = *(_DWORD *)&result[12] + 0x10000;
    *(_DWORD *)&result[7696] = 1;
    v13 = (float *)(v12 - 18992);
    v12 -= 19004;
    v14 = *(float *)(v12 + 4);
    v15 = *(float *)(v12 + 8);
    v24.x = *(float *)v12;
    v24.y = v14;
    v24.z = v15;
    v16 = *(float *)(v12 + 8);
    v17 = (float)(v13[2] * (float)75.0);
    v18 = (float)(*(float *)v12 + (float)(*v13 * (float)75.0));
    v25.y = *(float *)(v12 + 4) + (float)(v13[1] * (float)75.0);
    v25.x = v18;
    v25.z = (float)v16 + (float)v17;
    idMeleeTrace::Start(
      this: (idMeleeTrace *)&result[7684],
      startPos: &v25,
      numSamples_: 1,
      damageCap_: 100.0,
      meleeType_: v12,
      boundsType_: BOUNDS_16x16,
      damageDef_: nullptr,
      impactEffect_: *(const idDeclProjectileImpactEffect **)(LODWORD(highMagnitude) + 444));
    v20 = !common->IsServer(this: common);
    v19 = (idMeleeTrace *)&result[7684];
    if ( v20 )
      v21 = idMeleeTrace::PastUpdate(this: v19, owner: *(idPresentable **)&result[12], pastPos: &v24);
    else
      v21 = idMeleeTrace::PastUpdate(this: v19, owner: *(idActor **)(*(_DWORD *)&result[12] + 1096), pastPos: &v24);
    if ( v21 )
    {
      *(_BYTE *)&result[7912] |= 8u;
      *(_DWORD *)&result[7896] = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idPresentablePlayer::SetControllerShake(
        this: *(idPresentablePlayer **)&result[12],
        highMagnitude: 0.5,
        highDuration: v22,
        lowMagnitude: 1.0,
        lowDuration: 250);
      if ( *(_BYTE *)&result[7739] != 0 )
        *(float *)&result[2252] = 1.0;
    }
  }
  idRibbon::~idRibbon(this: (idRibbon *)&result[7684]);
  return this;
}


// ========================================================================
// ?AnimEvent_WeaponPlayVideo@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82E00920
// RVA : 0x00E00920
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_WeaponPlayVideo(idHands *this, eventVoid *result, const idMD6Anim *anim)
{
  idHandsItem::StartVideo(this: (idHandsItem *)&result[2996]);
  return this;
}


// ========================================================================
// ?AnimEvent_WeaponStopVideo@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82E00958
// RVA : 0x00E00958
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_WeaponStopVideo(idHands *this, eventVoid *result, const idMD6Anim *anim)
{
  idHandsItem::StopVideo(this: (idHandsItem *)&result[2996]);
  return this;
}


// ========================================================================
// ?AnimEvent_SwimStroke@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@W4handsSwimStroke_t@1@@Z
// EA  : 0x82E00990
// RVA : 0x00E00990
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idHands *__fastcall idHands::AnimEvent_SwimStroke(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idHands::handsSwimStroke_t strokeType)
{
  int v4; // r28
  idHands *v5; // r27
  bool v6; // r30
  bool v7; // r29
  int v8; // r10
  int v9; // r11
  __int64 v10; // r10 OVERLAPPED
  double v11; // fp10
  __int64 v12; // r8
  double v13; // fp13
  double v14; // fp12
  double v15; // fp0
  int v16; // r31
  double v17; // fp31
  int v18; // r10
  int v19; // r10
  double v20; // fp1
  double v21; // fp11
  double v22; // fp9
  idVec3 v24[2]; // [sp+50h] [-50h] BYREF

  v4 = *(_DWORD *)&result[12];
  v5 = this;
  v6 = false;
  v7 = false;
  v8 = *(unsigned __int8 *)(v4 + 46035);
  HIDWORD(v10) = *(unsigned __int8 *)(v4 + 46036);
  HIDWORD(v12) = *(unsigned __int8 *)(v4 + 46034);
  v9 = SBYTE3(v10);
  v11 = (double)*(__int64 *)((char *)&v10 - 4);
  LODWORD(v12) = SBYTE3(v12);
  v13 = (float)v12;
  v24[0].x = (float)v12;
  v14 = (float)*(__int64 *)((char *)&v10 - 4);
  v24[0].z = (float)*(__int64 *)((char *)&v10 - 4);
  LODWORD(v10) = -(char)v8;
  v15 = (float)v10;
  v24[0].y = (float)v10;
  switch ( strokeType )
  {
    case SWIMSTROKE_FORWARD:
      v16 = 1250;
      v15 = (float)((float)v10 * (float)0.5);
      v17 = 220.0;
      v24[0].y = (float)v10 * (float)0.5;
      goto LABEL_17;
    case SWIMSTROKE_SPRINT:
      v16 = 1050;
      v15 = (float)((float)v10 * (float)0.5);
      v17 = 200.0;
      v14 = (float)((float)v11 * (float)0.5);
      v24[0].y = (float)v10 * (float)0.5;
      v24[0].z = (float)v11 * (float)0.5;
      goto LABEL_17;
    case SWIMSTROKE_BACK:
      v16 = 800;
      v15 = (float)((float)v10 * (float)0.5);
      v17 = 200.0;
      v14 = (float)((float)v11 * (float)0.5);
      v24[0].y = (float)v10 * (float)0.5;
      v24[0].z = (float)v11 * (float)0.5;
      goto LABEL_17;
    case SWIMSTROKE_LEFT:
    case SWIMSTROKE_RIGHT:
      v6 = false;
      v13 = (float)((float)v12 * (float)0.5);
      v17 = 150.0;
      v14 = (float)((float)v11 * (float)0.5);
      v24[0].x = (float)v12 * (float)0.5;
      v24[0].z = (float)v11 * (float)0.5;
      goto LABEL_16;
    case SWIMSTROKE_UP:
      v16 = 800;
      v6 = true;
      v13 = (float)((float)v12 * (float)0.5);
      v17 = 220.0;
      v15 = (float)((float)v10 * (float)0.5);
      v24[0].x = (float)v12 * (float)0.5;
      v24[0].y = (float)v10 * (float)0.5;
      goto LABEL_17;
    case SWIMSTROKE_DOWN:
      v13 = (float)((float)v12 * (float)0.5);
      v17 = 180.0;
      v15 = (float)((float)v10 * (float)0.5);
      v24[0].x = (float)v12 * (float)0.5;
      v24[0].y = (float)v10 * (float)0.5;
      goto LABEL_15;
    case SWIMSTROKE_SURFACE:
    case SWIMSTROKE_SUBMERGE:
      *(_DWORD *)&result[8016] = 9;
      return this;
    case SWIMSTROKE_TURNLEFT:
      v18 = *(_DWORD *)&result[8020];
      v13 = -0.34999999;
      v15 = -0.64999998;
      v14 = 0.0;
      v24[0].x = -0.34999999;
      v24[0].y = -0.64999998;
      v24[0].z = 0.0;
      if ( v18 != 1 )
        goto LABEL_13;
      v17 = 70.0;
      goto LABEL_14;
    case SWIMSTROKE_TURNRIGHT:
      v19 = *(_DWORD *)&result[8020];
      v13 = -0.34999999;
      v15 = 0.64999998;
      v14 = 0.0;
      v24[0].x = -0.34999999;
      v24[0].y = 0.64999998;
      v24[0].z = 0.0;
      if ( v19 == 1 )
        v17 = 70.0;
      else
LABEL_13:
        v17 = 140.0;
LABEL_14:
      v7 = true;
LABEL_15:
      v6 = true;
LABEL_16:
      v16 = 650;
LABEL_17:
      if ( v7 )
      {
        v24[0].x = (float)v13 * (float)v17;
        v24[0].y = (float)v15 * (float)v17;
        v24[0].z = (float)v14 * (float)v17;
      }
      else
      {
        v20 = idVec3::NormalizeFast(this: v24);
        v21 = (float)((float)((float)(*(float *)(v4 + 46552) * v24[0].x)
                            + (float)((float)(*(float *)(v4 + 46576) * v24[0].z)
                                    + (float)(*(float *)(v4 + 46564) * v24[0].y)))
                    * (float)v17);
        v22 = (float)((float)((float)((float)(*(float *)(v4 + 46548) * v24[0].x)
                                    + (float)((float)(*(float *)(v4 + 46572) * v24[0].z)
                                            + (float)(*(float *)(v4 + 46560) * v24[0].y)))
                            * (float)v17)
                    * (float)((float)v20 * (float)0.0078740157));
        v24[0].x = (float)((float)((float)(*(float *)(v4 + 46544) * v24[0].x)
                                 + (float)((float)(*(float *)(v4 + 46568) * v24[0].z)
                                         + (float)(*(float *)(v4 + 46556) * v24[0].y)))
                         * (float)v17)
                 * (float)((float)v20 * (float)0.0078740157);
        v24[0].y = v22;
        v24[0].z = (float)v21 * (float)((float)v20 * (float)0.0078740157);
      }
      idPhysics_Player::SetSwimStroke(
        this: (idPhysics_Player *)(v4 + 36264),
        vel: v24,
        duration: v16,
        backABit: v6,
        ignoreInput: v7);
      break;
    default:
      return v5;
  }
  return v5;
}


// ========================================================================
// ?SetTestModel@idHands@@QAAXPBD@Z
// EA  : 0x82E00CD8
// RVA : 0x00E00CD8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SetTestModel(idHands *this, const char *modelName)
{
  idRenderModel *testModel; // r3
  idRenderModel *v5; // r3

  testModel = this->testModel;
  if ( testModel != nullptr )
  {
    testModel->unlinked = true;
    testModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: testModel);
    this->testModel = nullptr;
  }
  if ( modelName != nullptr && *modelName != 0 )
  {
    v5 = clientGame->renderWorld->AllocRenderModel(this: clientGame->renderWorld, a2: modelName, a3: 1, a4: -1);
    this->testModel = v5;
    if ( v5 == nullptr )
      idLib::Printf(fmt: "Failed to load model '%s'\n", modelName);
  }
}


// ========================================================================
// ?Cmd_TestWeapon_f@idHands@@SAXABVidCmdArgs@@@Z
// EA  : 0x82E00D88
// RVA : 0x00E00D88
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::Cmd_TestWeapon_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPresentable *presentable; // r3
  int v4; // r3
  idHands *v5; // r3
  const char *v6; // r4

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr )
  {
    presentable = DebugPlayer->presentable;
    if ( presentable != nullptr )
      v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v4 = 0;
    v5 = (idHands *)(v4 + 37616);
    if ( v5 != nullptr )
    {
      if ( args->argc < 2 )
        v6 = &byte_8200D768;
      else
        v6 = args->argv[1];
      idHands::SetTestModel(this: v5, modelName: v6);
    }
  }
  else
  {
    idLib::Printf(fmt: "No local client entity was found.\n");
  }
}


// ========================================================================
// ?TakedownKnifeGripIsReverse@idHands@@QAA_NXZ
// EA  : 0x82E00E40
// RVA : 0x00E00E40
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

BOOL __fastcall idHands::TakedownKnifeGripIsReverse(idHands *this)
{
  idWeapon *v1; // r3

  v1 = this->owner->GetEquippedWeapon(this: this->owner, a2: 2);
  if ( v1 != nullptr && v1->decl[1].parent == nullptr )
    return (_cntlzw(v1->weaponState) & 0x20) != 0;
  clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
  return false;
}


// ========================================================================
// ?TakedownKnifeGripIsDW@idHands@@QAA_NXZ
// EA  : 0x82E00ED0
// RVA : 0x00E00ED0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

BOOL __fastcall idHands::TakedownKnifeGripIsDW(idHands *this)
{
  idWeapon *v2; // r3
  idInventoryCollection *v4; // r3
  idWeapon *InventoryItemByName; // r3
  idWeapon *v6; // r3

  v2 = this->owner->GetEquippedWeapon(this: this->owner, a2: 2);
  if ( v2 != nullptr && v2->decl[1].parent == nullptr )
    return (_cntlzw(this->currentDualWieldState - 1) & 0x20) != 0;
  v4 = this->owner->GetInventory(this: this->owner);
  InventoryItemByName = (idWeapon *)idInventoryCollection::FindInventoryItemByName(this: v4, internalName: "knife");
  v6 = idWeapon::CastTo(c: InventoryItemByName);
  if ( v6 != nullptr && (*((_BYTE *)v6 + 452) & 1) != 0 )
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
  return false;
}


// ========================================================================
// ?hands_SetRelaxed_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E00FB0
// RVA : 0x00E00FB0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall hands_SetRelaxed_f(const idCmdArgs *args)
{
  idPresentablePlayer *PlayerPresentableByIndex; // r3

  PlayerPresentableByIndex = idClientGame::FindPlayerPresentableByIndex(this: clientGame, playerNum: 0);
  PlayerPresentableByIndex->hands.weaponRelaxedToggler = true;
  PlayerPresentableByIndex->hands.lastWeaponUsedTime = -10000;
}


// ========================================================================
// ?UpdateWeaponReload@idHands@@IAA_NPAVidWeapon@@_N1@Z
// EA  : 0x82E00FF8
// RVA : 0x00E00FF8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

int __fastcall idHands::UpdateWeaponReload(idHands *this, idWeapon *weapon, BOOL secondary, bool leftHand)
{
  int v9; // r4
  char v10; // r29
  int v11; // r4
  char v12; // r3
  const idInventoryCollection *v13; // r3
  idAmmoItem *ammoClip; // r25
  char v15; // r27
  int (__fastcall *GetCount)(struct idAmmoItem *); // ctr
  idWeapon_vtbl *v17; // r29
  idInventoryCollection *v18; // r3
  idWeapon *v19; // r3
  idWeapon *v20; // r11
  idAmmoItem *v21; // r3
  idAmmoItem *v22; // r29
  idWeapon_vtbl *v23; // r29
  idInventoryCollection *v24; // r3
  bool v25; // r11
  const idDeclAmmo *v26; // r29
  idAmmoItem *ammoClipSecondary; // r11
  const idDeclAmmo *decl; // r5

  if ( this->isReloading )
  {
    idPresentablePlayer::ToggleZoom(this: this->owner, z: false);
    return 1;
  }
  if ( !weapon->NeedsReload(this: weapon, a2: secondary) )
    return 0;
  v9 = 8;
  if ( !leftHand )
    v9 = 1;
  v10 = idUCmdTracker::WasPressedForPlayer(this: &this->owner->ucmdTracker1, mask: v9);
  v11 = 8;
  if ( !leftHand )
    v11 = 1;
  v12 = idUCmdTracker::WasReleasedForPlayer(this: &this->owner->ucmdTracker1, mask: v11);
  if ( (v10 == 0 || weapon->triggerState != TRIGGERSTATE_RELEASED)
    && (v12 == 0 || weapon->triggerState != TRIGGERSTATE_PULLED) )
  {
    return 1;
  }
  v13 = this->owner->GetInventory(this: this->owner);
  if ( idWeapon::CanReload(this: weapon, inventory: v13, secondaryAmmo: secondary) )
  {
    if ( !this->isHandsSprinting )
    {
      if ( secondary )
        ammoClipSecondary = weapon->ammoClipSecondary;
      else
        ammoClipSecondary = weapon->ammoClip;
      if ( ammoClipSecondary != nullptr )
        decl = (const idDeclAmmo *)ammoClipSecondary->decl;
      else
        decl = nullptr;
      idHands::SetPendingAction(this, action: HANDSACTION_RELOAD, ammoDecl: decl, secondary, leftHand);
    }
    return 1;
  }
  if ( secondary || (*((_BYTE *)weapon + 453) & 0x40) == 0 || (ammoClip = weapon->ammoClipSecondary) == nullptr )
    ammoClip = weapon->ammoClip;
  if ( ammoClip != nullptr )
  {
    v15 = 0;
    GetCount = ammoClip->GetCount;
    if ( this->currentDualWieldState != SET_DUALWIELD_ON )
    {
      v25 = true;
      if ( GetCount(this: ammoClip) <= 0 )
      {
        if ( !secondary && (*((_BYTE *)weapon + 453) & 0x40) == 0
          || (v23 = weapon->__vftable,
              v24 = this->owner->GetInventory(this: this->owner),
              v23->TotalLoadedAmmoCount(this: weapon, a2: v24, a3: (_cntlzw(secondary) & 0x20) != 0) <= 0) )
        {
          v25 = false;
        }
      }
      v15 = v25;
      goto LABEL_38;
    }
    if ( GetCount(this: ammoClip) > 0 )
    {
      v15 = 1;
LABEL_38:
      if ( v15 == 0 )
      {
        idPresentablePlayer::SelectBestWeapon(this: this->owner);
        return 1;
      }
      if ( leftHand )
      {
        this->dualWieldLeftHandPendingAction.action = HANDSACTION_NONE;
        this->dualWieldLeftHandPendingAction.ammoDecl = nullptr;
        this->dualWieldLeftHandPendingAction.weapon = nullptr;
        this->dualWieldLeftHandPendingAction.throwable = nullptr;
        this->dualWieldLeftHandPendingAction.useIntroBringUp = false;
        this->dualWieldLeftHandPendingAction.isSecondary = false;
        this->dualWieldLeftHandPendingAction.leftHand = false;
        idStr::Clear(this: &this->dualWieldLeftHandPendingAction.extraNodeInfo);
        this->dualWieldLeftHandPendingAction.action = HANDSACTION_TOGGLEFIREMODE;
      }
      else
      {
        idHands::SetPendingAction(this, action: HANDSACTION_TOGGLEFIREMODE, secondary: leftHand);
      }
      if ( ammoClip->GetCount(this: ammoClip) <= 0 )
      {
        v26 = (const idDeclAmmo *)ammoClip->decl;
        this->lingeringAction.action = HANDSACTION_NONE;
        this->lingeringAction.ammoDecl = nullptr;
        this->lingeringAction.weapon = nullptr;
        this->lingeringAction.throwable = nullptr;
        this->lingeringAction.useIntroBringUp = false;
        this->lingeringAction.isSecondary = false;
        this->lingeringAction.leftHand = false;
        idStr::Clear(this: &this->lingeringAction.extraNodeInfo);
        this->lingeringAction.ammoDecl = v26;
        this->lingeringAction.leftHand = leftHand;
        this->lingeringAction.action = HANDSACTION_RELOAD;
        this->lingeringAction.isSecondary = (_cntlzw(secondary) & 0x20) != 0;
        return 1;
      }
      return 1;
    }
    v17 = weapon->__vftable;
    v18 = this->owner->GetInventory(this: this->owner);
    if ( v17->TotalLoadedAmmoCount(this: weapon, a2: v18, a3: secondary) > 0 )
    {
      v15 = 1;
      goto LABEL_38;
    }
    v19 = this->owner->GetEquippedWeapon(this: this->owner, a2: ((_cntlzw(leftHand) & 0x20) == 0) + 1);
    v20 = v19;
    if ( (*((_BYTE *)v19 + 453) & 0x40) != 0 )
      v21 = v19->ammoClipSecondary;
    else
      v21 = nullptr;
    v22 = v20->ammoClip;
    if ( (v21 == nullptr || v21->GetCount(this: v21) <= 0) && (v22 == nullptr || v22->GetCount(this: v22) <= 0) )
      goto LABEL_38;
    return 0;
  }
  return 1;
}


// ========================================================================
// ?HandleFire@idHands@@IAA_NW4handsState_t@1@_N11@Z
// EA  : 0x82E013F0
// RVA : 0x00E013F0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

int __fastcall idHands::HandleFire(
        idHands *this,
        idHands::handsState_t state,
        bool friendlyTarget,
        bool inhibitFire,
        bool rightWeapon)
{
  unsigned int v6; // r27
  bool v10; // r26
  idWeapon *v11; // r3
  idWeapon *v12; // r29
  BOOL v13; // r21
  const idDeclInventory *decl; // r10
  char v16; // r9
  BOOL v17; // r23
  char v18; // r11
  bool v19; // r22
  idAmmoItem *ammoClipSecondary; // r11
  __int32 burstMode; // r11
  char v22; // r11
  char v23; // r25
  int v24; // r4
  BOOL IsPressedForPlayer; // r28
  idWeapon *v26; // r3
  idLaserCutter *v27; // r30
  idLaserCutter_vtbl *v28; // r29
  idActor *ActorEntity; // r3
  idAmmoItem *v30; // r11
  int v31; // r11
  idAmmoItem *v32; // r11
  idAmmoItem *ammoClip; // r11
  int num; // r11
  idWeapon::triggerState_t triggerState; // r11
  idAmmoItem *v36; // r11
  unsigned int alternateFiringNode; // r11
  unsigned int alternateLeftFiringNode; // r11

  v6 = rightWeapon;
  v10 = rightWeapon;
  v11 = this->owner->GetEquippedWeapon(this: this->owner, a2: ((_cntlzw(rightWeapon) & 0x20) == 0) + 1);
  v12 = v11;
  if ( v11 == nullptr
    || inhibitFire
    || v6 == 0 && this->currentDualWieldState != SET_DUALWIELD_ON
    || this->currentDualWieldState == SET_DUALWIELD_ON && this->isHandsSprinting )
  {
    return 0;
  }
  v13 = (_cntlzw(v11->weaponState - 1) & 0x20) != 0;
  if ( !idWeapon::IsReadyToFire(this: v11) )
  {
    if ( !this->isReloading )
      idHands::UpdateWeaponReload(this, weapon: v12, secondary: v13, leftHand: (_cntlzw(v6) & 0x20) != 0);
    return 0;
  }
  decl = v12->decl;
  v16 = _cntlzw((unsigned int)decl[1].parent);
  v17 = (v16 & 0x20) != 0;
  if ( (v16 & 0x20) == 0 || (v18 = 1, v6 != 0) )
    v18 = 0;
  v19 = v18;
  if ( v13 )
    ammoClipSecondary = v12->ammoClipSecondary;
  else
    ammoClipSecondary = v12->ammoClip;
  if ( ammoClipSecondary != nullptr )
    burstMode = ammoClipSecondary->burstMode;
  else
    burstMode = decl[1].attachmentInfo.num;
  if ( burstMode != 1 || (v22 = 1, v12->burstCount <= 0) )
    v22 = 0;
  v23 = v22;
  v24 = 8;
  if ( v6 != 0 )
    v24 = 1;
  IsPressedForPlayer = idUCmdTracker::IsPressedForPlayer(this: &this->owner->ucmdTracker1, mask: v24);
  if ( IsPressedForPlayer && v17 )
  {
    if ( v6 != 0 )
    {
      v26 = this->owner->GetEquippedWeapon(this: this->owner, a2: 1);
      if ( v26 != nullptr && v26->weaponState == WEAPONSTATE_SECONDARY )
      {
        v10 = false;
        v13 = true;
      }
    }
    else if ( v12->weaponState != WEAPONSTATE_SECONDARY )
    {
      v10 = true;
      v12 = this->owner->GetEquippedWeapon(this: this->owner, a2: 2);
    }
  }
  if ( (unsigned __int8)idHands::UpdateWeaponReload(
                          this,
                          weapon: v12,
                          secondary: v13,
                          leftHand: (_cntlzw(v10) & 0x20) != 0) != 0
    || !IsPressedForPlayer && v23 == 0 )
  {
    return 0;
  }
  if ( friendlyTarget )
  {
    if ( this->weaponRelaxed || state == HS_HIDEMOVE )
      return 0;
    this->weaponRelaxed = true;
    goto LABEL_40;
  }
  if ( !v10 )
  {
    if ( this->dualWieldLeftHandPendingAction.action != HANDSACTION_FIRE )
    {
      if ( v13 )
        ammoClip = v12->ammoClipSecondary;
      else
        ammoClip = v12->ammoClip;
      if ( ammoClip != nullptr )
        num = ammoClip->burstMode;
      else
        num = v12->decl[1].attachmentInfo.num;
      if ( num == 2
        || (triggerState = v12->triggerState) == TRIGGERSTATE_RELEASED
        || triggerState == TRIGGERSTATE_PULLED && v12->burstCount > 0 )
      {
        this->weaponRelaxedToggler = false;
        this->weaponRelaxed = false;
        if ( v17 )
        {
          if ( v13 )
            v36 = v12->ammoClipSecondary;
          else
            v36 = v12->ammoClip;
          idHands::SetPendingAction(
            this,
            action: HANDSACTION_FIRE,
            ammoDecl: (const idDeclAmmo *)v36->decl,
            secondary: v13,
            leftHand: true);
          this->isInterruptableTransition = true;
          if ( state == HS_TRANSITIONING )
          {
            alternateFiringNode = this->alternateFiringNode;
            this->dualWieldLeftHandPendingAction.leftHand = true;
            this->dualWieldLeftHandPendingAction.isSecondary = v13;
            this->dualWieldLeftHandPendingAction.action = HANDSACTION_RETURNTOIDLE;
            this->alternateFiringNode = (_cntlzw(alternateFiringNode) & 0x20) != 0;
          }
          else
          {
            this->alternateFiringNode = false;
            this->dualWieldLeftHandPendingAction.leftHand = true;
            this->dualWieldLeftHandPendingAction.action = HANDSACTION_RETURNTOIDLE;
            this->dualWieldLeftHandPendingAction.isSecondary = v13;
          }
          return 1;
        }
        if ( !this->isReloading )
        {
          alternateLeftFiringNode = this->alternateLeftFiringNode;
          this->dualWieldLeftHandPendingAction.action = HANDSACTION_FIRE;
          this->dualWieldLeftHandPendingAction.leftHand = true;
          this->dualWieldLeftHandPendingAction.isSecondary = v13;
          this->alternateLeftFiringNode = (_cntlzw(alternateLeftFiringNode) & 0x20) != 0;
        }
      }
      return 1;
    }
    return 0;
  }
  v27 = idLaserCutter::CastTo(c: (idLaserCutter *)v12);
  if ( this->weaponRelaxed || state == HS_HIDEMOVE )
  {
    this->weaponRelaxed = false;
    this->lastWeaponUsedTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    if ( v27 != nullptr && v27->weaponState == WEAPONSTATE_SECONDARY )
    {
LABEL_40:
      idPresentablePlayer::ToggleZoom(this: this->owner, z: false);
      v12->burstCount = 0;
      idHands::SetPendingAction(this, action: HANDSACTION_LOWERWEAPON, secondary: false);
      return 0;
    }
  }
  if ( (unsigned __int8)idHands::AttackPending(this) != 0 )
    return 0;
  if ( v27 != nullptr && !v13 && !idLaserCutter::GetOkToFire(this: v27) )
  {
    v28 = v27->__vftable;
    ActorEntity = idPresentableActor::GetActorEntity(this: this->owner);
    v28->ClickWeapon(this: v27, a2: ActorEntity, a3: false);
    return 1;
  }
  if ( v13 )
    v30 = v12->ammoClipSecondary;
  else
    v30 = v12->ammoClip;
  if ( v30 != nullptr )
    v31 = v30->burstMode;
  else
    v31 = v12->decl[1].attachmentInfo.num;
  if ( v31 == 2 || v12->triggerState == TRIGGERSTATE_RELEASED || v23 != 0 )
  {
    if ( v13 )
      v32 = v12->ammoClipSecondary;
    else
      v32 = v12->ammoClip;
    idHands::SetPendingAction(
      this,
      action: HANDSACTION_FIRE,
      ammoDecl: (const idDeclAmmo *)v32->decl,
      secondary: v13,
      leftHand: v19);
    this->weaponRelaxedToggler = false;
    this->weaponRelaxed = false;
    this->isInterruptableTransition = true;
    if ( state == HS_TRANSITIONING )
    {
      this->alternateFiringNode = (_cntlzw(this->alternateFiringNode) & 0x20) != 0;
      return 1;
    }
    this->alternateFiringNode = false;
  }
  return 1;
}


// ========================================================================
// ?GetState@idHands@@QBA?AW4handsState_t@1@PBVidAnimWebHands@@@Z
// EA  : 0x82E01930
// RVA : 0x00E01930
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

int __fastcall idHands::GetState(idHands *this, const idAnimWebHands *animWeb)
{
  int value; // r11
  idDeclAnimWebNode *v5; // r11
  const char *StateName; // r3
  const char *v7; // r30
  char v8; // r11

  if ( animWeb == nullptr )
    return 0;
  if ( this->currentSwimState != HS_IDLE )
    return 9;
  value = animWeb->curNodeIndex.value;
  if ( value == -1 )
    v5 = nullptr;
  else
    v5 = animWeb->decl->nodes.list[value];
  StateName = idDeclAnimWeb::GetStateName(
                this: animWeb->decl,
                index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v5->states.stateIndex[0].value);
  v7 = StateName;
  if ( *StateName != 0 )
  {
    if ( (unsigned __int16)animWeb->curEdgeNodeIndex.value >= 0x8000u
      || (v8 = 1, (unsigned __int16)animWeb->curEdgeIndex >= 0x8000u) )
    {
      v8 = 0;
    }
    if ( v8 == 0 )
    {
      if ( idStr::Icmp(s1: StateName, s2: "idle") == 0 )
        return 0;
      if ( idStr::Icmp(s1: v7, s2: "zoomidle") == 0 )
        return 1;
      if ( idStr::Icmp(s1: v7, s2: "throwidle") == 0 )
        return 2;
      if ( idStr::Icmp(s1: v7, s2: "sprint") == 0 )
        return 6;
      if ( idStr::Icmp(s1: v7, s2: "charging") == 0 )
        return 4;
      if ( idStr::Icmp(s1: v7, s2: "lasering") == 0 || idStr::Icmp(s1: v7, s2: "zoomlasering") == 0 )
        return 5;
      if ( idStr::Icmp(s1: v7, s2: "hide") == 0 )
        return 7;
      if ( idStr::Icmp(s1: v7, s2: "chargebattery") == 0 )
        return 8;
    }
  }
  return 3;
}


// ========================================================================
// ?UpdateHidden@idHands@@QAAXXZ
// EA  : 0x82E01B08
// RVA : 0x00E01B08
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::UpdateHidden(idHands *this)
{
  char v2; // r11
  idPresentableAnimatedEntity *presentable; // r3
  bool v4; // r11

  if ( this->unlinked )
  {
    v2 = 0;
  }
  else if ( hands_show.valueInteger == 0
         || g_editEntityMode.valueInteger != 0
         || this->hiddenReasons != 0
         || (v2 = 0, this->testModel != nullptr) )
  {
    v2 = 1;
  }
  if ( v2 != 0 )
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
      presentable->Hide(this: presentable, a2: true);
    idHandsItem::Hide(this: &this->leftItem);
    idHandsItem::Hide(this: &this->rightItem);
    v4 = true;
  }
  else
  {
    if ( (unsigned __int8)idHands::ShouldShow(this) == 0 )
      return;
    idHands::ShowHands(this);
    idHandsItem::Show(this: &this->leftItem);
    idHandsItem::Show(this: &this->rightItem);
    v4 = false;
  }
  this->unlinked = v4;
}


// ========================================================================
// ?RestHandsToIdle@idHands@@QAAXXZ
// EA  : 0x82E01C08
// RVA : 0x00E01C08
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::RestHandsToIdle(idHands *this)
{
  int value; // r11
  idDeclAnimWebNode *v3; // r11
  const char *SubWebName; // r29
  int GameMs; // r3
  blendParms_t v6[3]; // [sp+50h] [-40h] BYREF

  value = this->web.curNodeIndex.value;
  if ( value == -1 )
    v3 = nullptr;
  else
    v3 = this->web.decl->nodes.list[value];
  SubWebName = idDeclAnimWeb::GetSubWebName(
                 this: this->web.decl,
                 index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v3->subWebIndex.value);
  blendParms_t::blendParms_t(this: v6);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAnimator_AnimWeb::Reset(this: &this->web, initialSubWebName: SubWebName, initialStateName: "idle", curTime: GameMs);
  idPresentablePlayer::StopSound(this: this->owner, channel: SND_CHANNEL_ANY, peerMask: 0xFFu);
  this->isReloading = false;
  this->isInReloadOut = false;
}


// ========================================================================
// ?UpdateAmmoMeshForWeapon@idHands@@QAAXPBVidDeclAmmo@@@Z
// EA  : 0x82E01CB0
// RVA : 0x00E01CB0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::UpdateAmmoMeshForWeapon(idHands *this, const idDeclAmmo *ammoDecl)
{
  idHandsItem *p_rightItem; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r29
  int v5; // r28
  int v6; // r30
  int MeshIndex; // r3
  int v8; // r28
  int v9; // r30
  int v10; // r3

  p_rightItem = &this->rightItem;
  if ( p_rightItem != nullptr )
  {
    TreeAnimatorFromPresentable = idHandsItem::GetTreeAnimatorFromPresentable(this: p_rightItem);
    if ( TreeAnimatorFromPresentable != nullptr )
    {
      v5 = 0;
      if ( ammoDecl->meshesHiddenOnWeapon.num > 0 )
      {
        v6 = 0;
        do
        {
          MeshIndex = idTreeAnimator::GetMeshIndex(
                        this: TreeAnimatorFromPresentable,
                        meshName: ammoDecl->meshesHiddenOnWeapon.list[v6].data);
          if ( MeshIndex >= 0 )
            TreeAnimatorFromPresentable->meshVisibility.list[MeshIndex] = false;
          ++v5;
          ++v6;
        }
        while ( v5 < ammoDecl->meshesHiddenOnWeapon.num );
      }
      v8 = 0;
      if ( ammoDecl->meshesShownOnWeapon.num > 0 )
      {
        v9 = 0;
        do
        {
          v10 = idTreeAnimator::GetMeshIndex(
                  this: TreeAnimatorFromPresentable,
                  meshName: ammoDecl->meshesShownOnWeapon.list[v9].data);
          if ( v10 >= 0 )
            TreeAnimatorFromPresentable->meshVisibility.list[v10] = true;
          ++v8;
          ++v9;
        }
        while ( v8 < ammoDecl->meshesShownOnWeapon.num );
      }
    }
    else if ( hands_debugfc.valueInteger > 0 )
    {
      idLib::Warning(fmt: "animator == NULL on handsItem");
    }
  }
  else if ( hands_debugfc.valueInteger > 0 )
  {
    idLib::Warning(fmt: "handsItem == NULL");
  }
}


// ========================================================================
// ?UpdatePosition@idHands@@QAAXXZ
// EA  : 0x82E01DD0
// RVA : 0x00E01DD0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::UpdatePosition(idHands *this)
{
  idPresentableAnimatedEntity *presentable; // r10
  double valueFloat; // fp23
  double v4; // fp28
  double v5; // fp27
  double handsFovScale; // fp0
  const idDeclInventory *itemDecl; // r11
  const idDeclInventory *v8; // r11
  idPresentablePlayer *owner; // r3
  char *v10; // r10
  int v11; // ctr
  idPresentablePlayer *p_z; // r11
  float y; // r6
  float z; // r5
  idEntity *entity; // r30
  float distance; // r11
  float *distance_low; // r11
  double v18; // fp29
  double v19; // fp30
  double v20; // fp31
  double v21; // fp16
  double v22; // fp17
  double v23; // fp18
  double v24; // fp19
  double v25; // fp20
  double v26; // fp21
  double v27; // fp0
  double v28; // fp14
  double v29; // fp15
  int *v30; // r10
  char *v31; // r11
  int i; // ctr
  idWeapon *v33; // r3
  idWeapon *v34; // r30
  const idDeclInventory *decl; // r11
  bool v36; // r11
  BOOL v37; // r29
  idPresentableAnimatedEntity *v38; // r3
  idTreeAnimator *v39; // r3
  int v40; // r3
  idPresentablePlayer *v41; // r7
  double v42; // fp25
  double v43; // fp24
  double CrouchDecay; // fp1
  idFocusTracker_Player *p_focusTracker; // r3
  double v46; // fp28
  double v47; // fp27
  double v48; // fp26
  double v49; // fp10
  double v50; // fp8
  double v51; // fp0
  double v52; // fp0
  __int64 v53; // r9
  double aimPointBlend; // fp13
  double aimPointDepthBlend; // fp11
  double v56; // fp9
  double v58; // fp13
  double v59; // fp12
  double v61; // fp0
  double v65; // fp0
  const idDeclMD6 *v66; // r11
  idPropsCollection *p_props; // r3
  const tagData_t *Tag; // r3
  float v69; // r8
  float v70; // r7
  double v71; // fp5
  double v72; // fp27
  double v73; // fp26
  double v74; // fp23
  double v75; // fp28
  double v76; // fp25
  double v77; // fp24
  long double v78; // fp2
  double v79; // fp1
  int GameMs; // r3
  idPresentablePlayer *v81; // r11
  float v82; // r8
  float v83; // r7
  double v84; // fp9
  double v85; // fp7
  double v86; // fp27
  double v87; // fp28
  double v88; // fp26
  float *v89; // r3
  float *v90; // r3
  double v91; // fp2
  const idMat3 *v92; // r30
  const idMat3 *v93; // r29
  idMat3 *v94; // r3
  idMat3 *v95; // r3
  idRenderModel *testModel; // r3
  double v97; // fp13
  idPresentableAnimatedEntity *v98; // r11
  idRenderModel *v99; // r3
  idRenderModel *v100; // r30
  double v101; // fp0
  idRenderModel *v102; // r11
  idVec3 v103; // [sp+50h] [-2E0h] BYREF
  idVec3 v104; // [sp+60h] [-2D0h] BYREF
  float v105; // [sp+6Ch] [-2C4h]
  float v106; // [sp+70h] [-2C0h]
  int v107; // [sp+7Ch] [-2B4h] BYREF
  idMat3 v108; // [sp+80h] [-2B0h] BYREF
  idVec3 v109; // [sp+A8h] [-288h] BYREF
  idVec3 v110; // [sp+B8h] [-278h] BYREF
  float v111; // [sp+C4h] [-26Ch]
  float v112; // [sp+C8h] [-268h]
  float x; // [sp+D0h] [-260h]
  float v114; // [sp+D4h] [-25Ch]
  float v115; // [sp+D8h] [-258h]
  char v116; // [sp+DCh] [-254h] BYREF
  idMat3 v117; // [sp+E0h] [-250h] BYREF
  float v118; // [sp+104h] [-22Ch]
  int v119; // [sp+108h] [-228h] BYREF
  idVec3 v120; // [sp+110h] [-220h] BYREF
  idRotation v121; // [sp+120h] [-210h] BYREF
  idRotation v122; // [sp+170h] [-1C0h] BYREF
  idRotation v123; // [sp+1C0h] [-170h] BYREF
  idMat3 v124; // [sp+210h] [-120h] BYREF
  idMat3 v125[5]; // [sp+240h] [-F0h] BYREF

  presentable = this->presentable;
  valueFloat = hands_offsetX.valueFloat;
  v4 = hands_offsetY.valueFloat;
  v5 = hands_offsetZ.valueFloat;
  v118 = hands_offsetX.valueFloat;
  v111 = hands_offsetY.valueFloat;
  v112 = hands_offsetZ.valueFloat;
  if ( presentable != nullptr )
  {
    if ( g_freeCam.valueInteger != 0 )
    {
      handsFovScale = 1.0;
      v106 = 1.0;
    }
    else
    {
      v106 = 1.0;
      handsFovScale = hands_fovScale.valueFloat;
      if ( hands_fovScale.valueFloat == 0.0 )
      {
        itemDecl = this->rightItem.itemDecl;
        if ( itemDecl != nullptr )
        {
          handsFovScale = itemDecl->handsFovScale;
        }
        else
        {
          v8 = this->leftItem.itemDecl;
          if ( v8 != nullptr )
            handsFovScale = v8->handsFovScale;
          else
            handsFovScale = 1.0;
        }
      }
    }
    owner = this->owner;
    v10 = &v116;
    v105 = handsFovScale;
    v11 = 9;
    p_z = (idPresentablePlayer *)&owner->firstPersonViewOrigin.z;
    y = owner->firstPersonViewOrigin.y;
    z = owner->firstPersonViewOrigin.z;
    x = owner->firstPersonViewOrigin.x;
    v114 = y;
    v115 = z;
    do
    {
      p_z = (idPresentablePlayer *)((char *)p_z + 4);
      v10 += 4;
      *(_DWORD *)v10 = p_z->__vftable;
      --v11;
    }
    while ( v11 != 0 );
    entity = owner->entity;
    if ( (idPresentablePlayer::PlayerBehavior_ContextualShimmy_IsInShimmy(this: owner)
       || idPresentablePlayer::PlayerBehavior_WallClimb_IsInWallClimb(this: this->owner))
      && (distance = entity[16].dormancy.distance) != 0.0
      && *(_DWORD *)(LODWORD(distance) + 1336) != 0 )
    {
      distance_low = (float *)LODWORD(entity[16].dormancy.distance);
      v18 = distance_low[339];
      v19 = distance_low[340];
      v20 = distance_low[341];
      v21 = distance_low[342];
      v22 = distance_low[343];
      v23 = distance_low[344];
      v24 = distance_low[345];
      v25 = distance_low[346];
      v26 = distance_low[347];
      v27 = distance_low[336];
      v28 = distance_low[337];
      v29 = distance_low[338];
      v117.mat[0].x = distance_low[339];
      v117.mat[0].y = v19;
      v117.mat[0].z = v20;
      v117.mat[1].x = v21;
      v117.mat[1].y = v22;
      v117.mat[1].z = v23;
      v117.mat[2].x = v24;
      v117.mat[2].y = v25;
      v117.mat[2].z = v26;
      x = v27;
    }
    else
    {
      v29 = v115;
      v28 = v114;
      v26 = v117.mat[2].z;
      v25 = v117.mat[2].y;
      v24 = v117.mat[2].x;
      v23 = v117.mat[1].z;
      v22 = v117.mat[1].y;
      v21 = v117.mat[1].x;
      v20 = v117.mat[0].z;
      v19 = v117.mat[0].y;
      v18 = v117.mat[0].x;
    }
    v30 = &v107;
    v31 = &v116;
    for ( i = 9; i != 0; --i )
    {
      v31 += 4;
      *++v30 = *(_DWORD *)v31;
    }
    idHands::ModifyAxisForTCAngles(this, inMat: &v108);
    v33 = this->owner->GetEquippedWeapon(this: this->owner, a2: 2);
    v34 = v33;
    if ( v33 != nullptr )
    {
      decl = v33->decl;
      v36 = v33->weaponState == WEAPONSTATE_SECONDARY
          ? decl->aimWeaponSettings.aimSecondary
          : decl->aimWeaponSettings.aimPrimary;
      v37 = v36;
      if ( v36 || this->aimPointBlend > 0.0 )
      {
        v38 = this->presentable;
        v39 = v38 != nullptr ? idPresentableAnimatedEntity::GetTreeAnimator(this: v38) : nullptr;
        if ( (unsigned __int8)idTreeAnimator::GetModelSpaceJointTransform(
                                this: v39,
                                pose: DRIVER_MODEL,
                                jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)0x20,
                                origin: &v110,
                                axis: &v117) != 0 )
        {
          v40 = idWeapon::MaxRange(this: v34, secondaryAmmo: (_cntlzw(v34->weaponState - 1) & 0x20) != 0);
          v41 = this->owner;
          *(_QWORD *)&v109.x = __PAIR64__(0x82000000, v40);
          v42 = 0.5;
          v43 = (float)__SPAIR64__(0x82000000, v40);
          CrouchDecay = idBobCycle::GetCrouchDecay(this: &v41->bobCycle);
          v119 = 0;
          p_focusTracker = &this->owner->focusTracker;
          v46 = (float)((float)((float)CrouchDecay * vec3_up.x) + x);
          v47 = (float)((float)(vec3_up.y * (float)CrouchDecay) + (float)v28);
          v48 = (float)((float)(vec3_up.z * (float)CrouchDecay) + (float)v29);
          v49 = (float)((float)((float)v20 * v110.x)
                      + (float)((float)((float)v23 * v110.y) + (float)((float)v26 * v110.z)));
          v50 = (float)((float)((float)((float)v19 * v110.x)
                              + (float)((float)((float)v22 * v110.y) + (float)((float)v25 * v110.z)))
                      + (float)((float)(vec3_up.y * (float)CrouchDecay) + (float)v28));
          v110.x = (float)((float)((float)v18 * v110.x)
                         + (float)((float)((float)v21 * v110.y) + (float)((float)v24 * v110.z)))
                 + (float)((float)((float)CrouchDecay * vec3_up.x) + x);
          v110.y = v50;
          v110.z = (float)v49 + (float)((float)(vec3_up.z * (float)CrouchDecay) + (float)v29);
          if ( idFocusTracker::GetValidTraceResultFocusEntity(
                 this: p_focusTracker,
                 includeBoundCheck: false,
                 checkTypes: nullptr,
                 numCheckTypes: 0,
                 maxRanges: nullptr,
                 resultEndPos: &v104,
                 resultID: &v119) != nullptr )
          {
            v51 = (float)((float)((float)(v104.x - (float)v46) * (float)(v104.x - (float)v46))
                        + (float)((float)((float)(v104.z - (float)v48) * (float)(v104.z - (float)v48))
                                + (float)((float)(v104.y - (float)v47) * (float)(v104.y - (float)v47))));
            if ( v51 <= 16384.0 )
              v52 = 128.0;
            else
              v52 = __fsqrts(v51);
            v42 = (float)((float)v52 / (float)v43);
            v104.x = (float)((float)v18 * (float)v52) + (float)v46;
            v104.y = (float)((float)v19 * (float)v52) + (float)v47;
            v104.z = (float)((float)v20 * (float)v52) + (float)v48;
            if ( v42 >= 0.0 )
            {
              if ( v42 > v106 )
                v42 = v106;
            }
            else
            {
              v42 = 0.0;
            }
          }
          else
          {
            v104.x = (float)((float)v18 * (float)v43) + (float)v46;
            v104.y = (float)((float)v19 * (float)v43) + (float)v47;
            v104.z = (float)((float)v20 * (float)v43) + (float)v48;
          }
          LODWORD(v53) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                       - this->lastAimUpdateTime;
          *(_QWORD *)&v109.x = v53;
          aimPointBlend = this->aimPointBlend;
          if ( v37 )
          {
            if ( aimPointBlend <= 0.0 )
              this->aimPointDepthBlend = v42;
            this->aimPointBlend = (float)((float)v53 * 0.025) + (float)aimPointBlend;
          }
          else
          {
            this->aimPointBlend = -(float)((float)((float)v53 * 0.025) - this->aimPointBlend);
          }
          if ( this->aimPointBlend > 0.0 )
          {
            aimPointDepthBlend = this->aimPointDepthBlend;
            v56 = v106;
            _FP8 = (float)(this->aimPointBlend - v106);
            v58 = 0.0000099999997;
            v59 = __fabs((float)(this->aimPointDepthBlend - (float)v42));
            __asm { fsel      f7, f8, f9, f0 }
            this->aimPointBlend = _FP7;
            v61 = (float)((float)v59 * (float)v59);
            if ( v61 < 0.0000099999997 || (v58 = 0.001, v61 > 0.001) )
              v61 = v58;
            if ( v59 >= 0.00000011920929 )
            {
              if ( aimPointDepthBlend <= v42 )
              {
                _FP13 = (float)((float)((float)((float)v61 * (float)v53) + (float)aimPointDepthBlend) - (float)v42);
                __asm { fsel      f12, f13, f25, f0 }
              }
              else
              {
                _FP13 = (float)((float)-(float)((float)((float)v61 * (float)v53) - (float)aimPointDepthBlend)
                              - (float)v42);
                __asm { fsel      f12, f13, f0, f25 }
              }
              this->aimPointDepthBlend = _FP12;
            }
            else
            {
              this->aimPointDepthBlend = v42;
            }
            v65 = this->aimPointDepthBlend;
            if ( v65 >= (float)(128.0 / (float)v43) )
            {
              if ( v65 > v56 )
                v65 = v56;
            }
            else
            {
              v65 = (float)(128.0 / (float)v43);
            }
            this->aimPointDepthBlend = v65;
            v104.x = (float)((float)((float)v18 * (float)v43) * (float)v65) + (float)v46;
            v104.y = (float)((float)((float)v19 * (float)v43) * (float)v65) + (float)v47;
            v104.z = (float)((float)((float)v20 * (float)v43) * (float)v65) + (float)v48;
            v66 = idHandsItem::GetTreeAnimatorFromPresentable(this: &this->rightItem)->decl;
            p_props = &v66->props;
            if ( v66 == nullptr )
              p_props = nullptr;
            Tag = idPropsCollection::GetTag(this: p_props, propName: idPropInfo::INFO_PROP_NAME, tagName: "muzzle");
            v109.y = v104.y - (float)v47;
            v109.z = v104.z - (float)v48;
            v69 = Tag->trans.z;
            v70 = Tag->trans.y;
            v109.x = v104.x - (float)v46;
            v71 = __fsqrts((float)((float)(v109.x * v109.x)
                                 + (float)((float)(v109.z * v109.z) + (float)(v109.y * v109.y))));
            v103.x = (float)((float)((float)v18 * (float)v71)
                           + (float)((float)((float)((float)v18 * (float)0.0)
                                           + (float)((float)(v70 * (float)v21) + (float)(v69 * (float)v24)))
                                   + v110.x))
                   - (float)v46;
            v103.y = (float)((float)((float)v19 * (float)v71)
                           + (float)((float)((float)((float)v19 * (float)0.0)
                                           + (float)((float)(v70 * (float)v22) + (float)(v69 * (float)v25)))
                                   + v110.y))
                   - (float)v47;
            v103.z = (float)((float)((float)v20 * (float)v71)
                           + (float)((float)((float)((float)v20 * (float)0.0)
                                           + (float)((float)(v70 * (float)v23) + (float)(v69 * (float)v26)))
                                   + v110.z))
                   - (float)v48;
            idVec3::NormalizeFast(this: &v109);
            idVec3::NormalizeFast(this: &v103);
            v72 = v109.y;
            v73 = v109.z;
            v74 = v109.x;
            v75 = v103.z;
            v76 = v103.x;
            v77 = v103.y;
            v120.x = (float)(v103.y * v109.z) - (float)(v103.z * v109.y);
            v120.y = (float)(v103.z * v109.x) - (float)(v109.z * v103.x);
            v120.z = (float)(v109.y * v103.x) - (float)(v103.y * v109.x);
            idVec3::NormalizeFast(this: &v120);
            *(double *)&v78 = (float)((float)((float)v76 * (float)v74)
                                    + (float)((float)((float)v75 * (float)v73) + (float)((float)v77 * (float)v72)));
            v79 = idMath::ACos(a: v78);
            idMat3::RotateSelf(this: &v108, axis: &v120, angle: (float)((float)v79 * this->aimPointBlend));
            valueFloat = v118;
          }
          else
          {
            this->aimPointBlend = 0.0;
          }
          v5 = v112;
          v4 = v111;
        }
      }
    }
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v81 = this->owner;
    this->lastAimUpdateTime = GameMs;
    v82 = v81->bobCycle.handsOffset.y;
    v83 = v81->bobCycle.handsOffset.z;
    v103.x = v81->bobCycle.handsOffset.x;
    v103.z = v83;
    v103.y = v82;
    idAngles::ToMat3(this: (idAngles *)&v124, result: (idMat3 *)&v81->bobCycle.handsAngles);
    v84 = (float)((float)((float)((float)v21 * (float)v4)
                        + (float)((float)((float)v18 * (float)valueFloat) + (float)((float)v24 * (float)v5)))
                + (float)(v103.x + x));
    v85 = (float)((float)((float)((float)v20 * (float)valueFloat)
                        + (float)((float)((float)v23 * (float)v4) + (float)((float)v26 * (float)v5)))
                + (float)(v103.z + (float)v29));
    v86 = (float)(this->extraWorldTranslation.y
                + (float)((float)((float)((float)v19 * (float)valueFloat)
                                + (float)((float)((float)v25 * (float)v5) + (float)((float)v22 * (float)v4)))
                        + (float)(v103.y + (float)v28)));
    v87 = (float)(this->extraWorldTranslation.x + (float)v84);
    v88 = (float)(this->extraWorldTranslation.z + (float)v85);
    v89 = (float *)idMat3::operator*(this: &v117, result: &this->extraWorldRotation, a: &v108);
    v108.mat[0].x = *v89;
    v108.mat[0].y = v89[1];
    v108.mat[0].z = v89[2];
    v108.mat[1].x = v89[3];
    v108.mat[1].y = v89[4];
    v108.mat[1].z = v89[5];
    v108.mat[2].x = v89[6];
    v108.mat[2].y = v89[7];
    v108.mat[2].z = v89[8];
    v90 = (float *)idMat3::operator*(this: v125, result: &v124, a: &v108);
    v108.mat[0].x = *v90;
    v108.mat[0].y = v90[1];
    v108.mat[0].z = v90[2];
    v108.mat[1].x = v90[3];
    v108.mat[1].y = v90[4];
    v108.mat[1].z = v90[5];
    v108.mat[2].x = v90[6];
    v108.mat[2].y = v90[7];
    v91 = v90[8];
    v121.axisValid = false;
    v123.axisValid = false;
    v122.axisValid = false;
    v121.origin.x = vec3_origin.x;
    v121.origin.y = vec3_origin.y;
    v121.origin.z = vec3_origin.z;
    v121.vec.x = v24;
    v121.vec.y = v25;
    v121.vec.z = v26;
    v121.angle = 0.0;
    v121.axis.mat[0].x = mat3_identity.mat[0].x;
    v121.axis.mat[0].y = mat3_identity.mat[0].y;
    v121.axis.mat[0].z = mat3_identity.mat[0].z;
    v121.axis.mat[1].x = mat3_identity.mat[1].x;
    v121.axis.mat[1].y = mat3_identity.mat[1].y;
    v121.axis.mat[1].z = mat3_identity.mat[1].z;
    v121.axis.mat[2].x = mat3_identity.mat[2].x;
    v121.axis.mat[2].y = mat3_identity.mat[2].y;
    v121.axis.mat[2].z = mat3_identity.mat[2].z;
    v123.origin.x = vec3_origin.x;
    v123.origin.y = vec3_origin.y;
    v123.origin.z = vec3_origin.z;
    v123.vec.x = v21;
    v123.vec.y = v22;
    v123.vec.z = v23;
    v123.angle = 0.0;
    v123.axis.mat[0].x = mat3_identity.mat[0].x;
    v123.axis.mat[0].y = mat3_identity.mat[0].y;
    v123.axis.mat[0].z = mat3_identity.mat[0].z;
    v123.axis.mat[1].x = mat3_identity.mat[1].x;
    v108.mat[2].z = v91;
    v123.axis.mat[1].y = mat3_identity.mat[1].y;
    v123.axis.mat[1].z = mat3_identity.mat[1].z;
    v123.axis.mat[2].x = mat3_identity.mat[2].x;
    v123.axis.mat[2].y = mat3_identity.mat[2].y;
    v123.axis.mat[2].z = mat3_identity.mat[2].z;
    v122.origin.x = vec3_origin.x;
    v122.origin.y = vec3_origin.y;
    v122.origin.z = vec3_origin.z;
    v122.vec.x = v18;
    v122.vec.y = v19;
    v122.vec.z = v20;
    v122.angle = 0.0;
    v122.axis.mat[0].x = mat3_identity.mat[0].x;
    v122.axis.mat[0].y = mat3_identity.mat[0].y;
    v122.axis.mat[0].z = mat3_identity.mat[0].z;
    v122.axis.mat[1].x = mat3_identity.mat[1].x;
    v122.axis.mat[1].y = mat3_identity.mat[1].y;
    v122.axis.mat[1].z = mat3_identity.mat[1].z;
    v122.axis.mat[2].x = mat3_identity.mat[2].x;
    v122.axis.mat[2].y = mat3_identity.mat[2].y;
    v122.axis.mat[2].z = mat3_identity.mat[2].z;
    v92 = idRotation::ToMat3(this: &v122);
    v93 = idRotation::ToMat3(this: &v123);
    v94 = (idMat3 *)idRotation::ToMat3(this: &v121);
    v95 = idMat3::operator*(this: v125, result: v94, a: v93);
    idMat3::operator*(this: &v117, result: v95, a: v92);
    idMat3::operator*=(this: &v108, a: &v117);
    if ( hands_updatePos.valueInteger != 0 )
    {
      testModel = this->testModel;
      if ( testModel != nullptr )
      {
        v99 = (idRenderModel *)_RTDynamicCast(
                                 inptr: testModel,
                                 VfDelta: 0,
                                 SrcType: &idRenderModel `RTTI Type Descriptor',
                                 TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                 isReference: 0);
        v100 = v99;
        if ( v99 != nullptr )
        {
          idRenderModel::SetAxis(this: v99, a: &v108);
          if ( !v100->deferredPositionInitialized || !v100->useDeferredPosition )
          {
            v100->g.origin.x = v87;
            v100->g.origin.y = v86;
            v100->g.origin.z = v88;
          }
          v101 = v105;
          v100->deferredOrigin.x = v87;
          v100->deferredOrigin.y = v86;
          v100->deferredOrigin.z = v88;
          v100->g.fovScale = v101;
        }
        else
        {
          idRenderModel::SetAxis(this: this->testModel, a: &v108);
          v102 = this->testModel;
          if ( !v102->deferredPositionInitialized || !v102->useDeferredPosition )
          {
            v102->g.origin.x = v87;
            v102->g.origin.y = v86;
            v102->g.origin.z = v88;
          }
          v102->deferredOrigin.z = v88;
          v102->deferredOrigin.x = v87;
          v102->deferredOrigin.y = v86;
          this->testModel->g.fovScale = v105;
        }
      }
      else
      {
        v97 = v105;
        this->presentable->axis = v108;
        v98 = this->presentable;
        v98->origin.x = v87;
        v98->origin.y = v86;
        v98->origin.z = v88;
        this->presentable->model->g.fovScale = v97;
      }
    }
  }
}


// ========================================================================
// ?LoadPresentable@idHands@@IAA_NPBD@Z
// EA  : 0x82E02928
// RVA : 0x00E02928
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idRenderModel *__fastcall idHands::LoadPresentable(idHands *this, const char *modelName)
{
  idRenderModel *result; // r3
  idRenderModel *v5; // r30
  idTreeAnimator *v6; // r26
  idPresentableAnimatedEntity *v7; // r3
  idPresentableAnimatedEntity *v8; // r3
  int v9; // r10
  int v10; // r9
  int v11; // r8
  int v12; // r7
  int v13; // [sp+8h] [-88h]
  int v14; // [sp+Ch] [-84h]
  int v15; // [sp+10h] [-80h]
  int v16; // [sp+14h] [-7Ch]
  int v17; // [sp+18h] [-78h]
  idPresentable *v18; // [sp+1Ch] [-74h]

  idHands::FreePresentables(this);
  result = clientGame->renderWorld->AllocRenderModel(this: clientGame->renderWorld, a2: modelName, a3: 1, a4: -1);
  v5 = result;
  if ( result != nullptr )
  {
    *((_BYTE *)&result->g + 107) |= 0x40u;
    v6 = (idTreeAnimator *)_RTDynamicCast(
                             inptr: result,
                             VfDelta: 0,
                             SrcType: &idRenderModel `RTTI Type Descriptor',
                             TargetType: &idTreeAnimator `RTTI Type Descriptor',
                             isReference: 0);
    if ( v6 != nullptr )
    {
      *((_BYTE *)&v5->g + 104) |= 4u;
      v7 = (idPresentableAnimatedEntity *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x4E0u,
                                            tag: TAG_PRESENTABLE,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      if ( v7 != nullptr )
        v8 = idPresentableAnimatedEntity::idPresentableAnimatedEntity(
               this: v7,
               ent: nullptr,
               renderModel_: v6,
               animStack_: &this->animStack,
               entityNumber_: 0x1FFF,
               fxDecl_: nullptr,
               useSphereModel_: false);
      else
        v8 = nullptr;
      this->presentable = v8;
      this->presentable->debugName = idClass::GetClassname(this);
      idClientGame::AddPresentable(
        this: clientGame,
        presentable: this->presentable,
        index: -1,
        skipReplication: true,
        a5: v12,
        a6: v11,
        a7: v10,
        a8: v9,
        a9: v13,
        a10: v14,
        a11: v15,
        a12: v16,
        a13: v17,
        a14: v18);
    }
    else
    {
      idLib::Warning(fmt: "Failed to load hands model '%s'... model is incorrect type.", modelName);
      v5->unlinked = true;
      v5->deleteOnSync = true;
      idRenderModel::CommitThisFrame(this: v5);
    }
    return (idRenderModel *)(v6 != nullptr);
  }
  return result;
}


// ========================================================================
// __unwind$499315
// EA  : 0x82E02A74
// RVA : 0x00E02A74
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_499315()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?AttachItem@idHands@@QAAXPAVidInventoryItem@@W4equipSlot_t@@_N@Z
// EA  : 0x82E02AA0
// RVA : 0x00E02AA0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::AttachItem(idHands *this, idInventoryItem *item, equipSlot_t slot, bool initFX)
{
  idHandsItem *p_leftItem; // r31
  idPresentable *Presentable; // r3

  if ( slot == EQUIP_LEFT_HAND )
  {
    p_leftItem = &this->leftItem;
  }
  else
  {
    if ( slot != EQUIP_RIGHT_HAND )
      return;
    p_leftItem = &this->rightItem;
  }
  if ( p_leftItem != nullptr )
  {
    idHandsItem::Attach(this: p_leftItem, hands: this, item, slot, initFX);
    if ( idHandsItem::GetPresentable(this: p_leftItem) != nullptr
      && idHandsItem::GetPresentable(this: p_leftItem)->model != nullptr )
    {
      Presentable = idHandsItem::GetPresentable(this: p_leftItem);
      *((_BYTE *)&Presentable->model->g + 104) |= 4u;
    }
    idHands::UpdateHidden(this);
  }
}


// ========================================================================
// ?ReloadWeapon@idHands@@IAAXW4equipSlot_t@@_N_N@Z
// EA  : 0x82E02B58
// RVA : 0x00E02B58
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::ReloadWeapon(idHands *this, const equipSlot_t slot, BOOL sameAmmoCount, BOOL secondary)
{
  idHandsItem *p_leftItem; // r24
  idWeapon *v8; // r30
  int value; // r10
  idProjectile *v10; // r3
  __int64 v11; // r10
  __int64 v12; // r8
  idProjectile *v13; // r3
  idProjectile *v14; // r3
  __int64 v15; // r10
  __int64 v16; // r8
  int v17; // r6
  idAmmoItem *ammoClipSecondary; // r11
  const idDeclAmmo *nextAmmo; // r28
  idAmmoItem *v20; // r11
  idAmmoItem *v21; // r11
  const idDeclInventory *decl; // r9
  int entityNumber; // r5
  const idInventoryCollection *v24; // r3
  idWeapon_vtbl *v25; // r29
  idPresentablePlayer *owner; // r25
  idFXManager *FXMgr; // r24
  int v28; // r3
  idClientGameMsg v29; // [sp+50h] [-70h] BYREF
  const idDeclAmmo *v30; // [sp+58h] [-68h]
  const idDeclInventory *v31; // [sp+5Ch] [-64h]
  int v32; // [sp+60h] [-60h]
  char v33; // [sp+64h] [-5Ch]

  if ( slot == EQUIP_LEFT_HAND )
  {
    p_leftItem = &this->leftItem;
  }
  else if ( slot == EQUIP_RIGHT_HAND )
  {
    p_leftItem = &this->rightItem;
  }
  else
  {
    p_leftItem = nullptr;
  }
  v8 = idWeapon::CastTo(c: (idWeapon *)p_leftItem->item);
  if ( common->IsServer(this: common)
    && (value = this->previousProjectile.spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v10 = (idProjectile *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idProjectile::CastTo(c: v10) != nullptr )
  {
    HIDWORD(v11) = this->previousProjectile.spawnId.value;
    LODWORD(v11) = gameLocal;
    LODWORD(v12) = SHIDWORD(v11) >> 13;
    HIDWORD(v12) = (WORD1(v11) & 0x1FFF) + 29755;
    if ( *((_DWORD *)&gameLocal->__vftable + HIDWORD(v12)) == SHIDWORD(v11) >> 13
      && (HIDWORD(v11) = 4 * ((WORD1(v11) & 0x1FFF) + 21563),
          (v13 = *(idProjectile **)((char *)&gameLocal->__vftable + HIDWORD(v11))) != nullptr) )
    {
      v14 = idProjectile::CastTo(c: v13);
      idEventReceiver::PostEventMS(this: v14, ev: &EV_Remove, time: 0, a4: v17, a5: v16, a6: v15);
    }
    else
    {
      idEventReceiver::PostEventMS(this: nullptr, ev: &EV_Remove, time: 0, a4: 4 * HIDWORD(v12), a5: v12, a6: v11);
    }
  }
  else
  {
    if ( v8->nextAmmo == nullptr )
    {
      if ( secondary )
        ammoClipSecondary = v8->ammoClipSecondary;
      else
        ammoClipSecondary = v8->ammoClip;
      idWeapon::BeginReloading(
        this: v8,
        ammoDecl: (const idDeclAmmo *)ammoClipSecondary->decl,
        secondaryAmmo: secondary);
    }
    nextAmmo = v8->nextAmmo;
    if ( common->IsMultiplayer(this: common) )
    {
      v20 = secondary ? v8->ammoClipSecondary : v8->ammoClip;
      if ( v20 != nullptr )
      {
        v21 = secondary ? v8->ammoClipSecondary : v8->ammoClip;
        if ( nextAmmo != v21->decl && !common->IsServer(this: common) )
        {
          decl = v8->decl;
          entityNumber = this->owner->entityNumber;
          v29.peerMask = -1;
          v29.__vftable = (idClientGameMsg_vtbl *)&idClientGameMsg_HandsAmmoChange::`vftable';
          v30 = nextAmmo;
          v31 = decl;
          v32 = entityNumber;
          v33 = 0;
          idClientGame::HandleReliableGameMsg(this: clientGame, gameMsg: &v29);
          v29.__vftable = (idClientGameMsg_vtbl *)&idClientGameMsg::`vftable';
        }
      }
    }
    v24 = this->owner->GetInventory(this: this->owner);
    if ( idWeapon::CanReload(this: v8, inventory: v24, ammoDecl: nextAmmo, secondaryAmmo: secondary) )
    {
      v25 = v8->__vftable;
      owner = this->owner;
      FXMgr = idHandsItem::GetFXMgr(this: p_leftItem);
      v28 = (int)owner->GetInventory(this: owner);
      v25->Reload(this: v8, a2: (idInventoryCollection *)v28, a3: FXMgr, a4: sameAmmoCount, a5: false, a6: secondary);
      if ( idWeapon::MultipleReloads(this: v8, ammoDecl: nextAmmo, secondaryAmmo: secondary) )
        idWeapon::BeginReloading(this: v8, ammoDecl: nextAmmo, secondaryAmmo: this->pendingAction.isSecondary);
    }
    else
    {
      idWeapon::SetFireState(this: v8, fs: FIRESTATE_IDLE);
      if ( !idWeapon::IsFullyLoaded(this: v8, secondaryAmmo: secondary) && v8->decl->blockEquipIfEmpty )
        idPresentablePlayer::SelectBestWeapon(this: this->owner);
    }
  }
}


// ========================================================================
// __unwind$499417
// EA  : 0x82E02E74
// RVA : 0x00E02E74
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_499417()
{
  int v0; // r12

  idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(this: (idClientGameMsg_VehicleWeaponChange *)(v0 - 192 + 80));
}


// ========================================================================
// ?CheckAutoReload@idHands@@QAAX_N0@Z
// EA  : 0x82E02EA0
// RVA : 0x00E02EA0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idHands::CheckAutoReload(idHands *this, BOOL secondary, unsigned __int8 setLingeringAction)
{
  idPresentablePlayer *owner; // r3
  idWeapon *v7; // r28
  bool v8; // r11
  idAmmoItem *ammoClipSecondary; // r26
  const idDeclAmmo *decl; // r30
  const idInventoryCollection *v11; // r3
  idPresentablePlayer *v12; // r11
  idEventReceiver *entity; // r3
  const idDeclPlayerProps *playerProps; // r11
  __int64 v15; // r10
  __int128 v16; // r7 OVERLAPPED
  int v17; // r8
  int v18; // r29
  int v19; // r29
  idInventoryCollection *v20; // r3
  __int64 v21; // [sp+8h] [-D8h]
  __int64 v22; // [sp+10h] [-D0h]
  __int64 v23; // [sp+18h] [-C8h]
  __int64 v24; // [sp+20h] [-C0h]
  __int64 v25; // [sp+28h] [-B8h]
  __int64 v26; // [sp+30h] [-B0h]
  __int64 v27; // [sp+38h] [-A8h]
  __int64 v28; // [sp+40h] [-A0h]
  int v29; // [sp+50h] [-90h] BYREF
  const idDeclTutorialEvent *reloadTutorial; // [sp+54h] [-8Ch]
  __int64 v31; // [sp+58h] [-88h]
  int v32; // [sp+60h] [-80h]

  for ( ; !this->isHandsSprinting; secondary = true )
  {
    owner = this->owner;
    if ( owner == nullptr )
      break;
    v7 = owner->GetEquippedWeapon(this: owner, a2: EQUIP_RIGHT_HAND);
    if ( v7 == nullptr || idPresentablePlayer::GetControl(this: this->owner) != nullptr )
      break;
    v8 = (_cntlzw(idUCmdTracker::IsPressedForPlayer(this: &this->owner->ucmdTracker1, mask: 1)) & 0x20) != 0;
    if ( secondary )
      ammoClipSecondary = v7->ammoClipSecondary;
    else
      ammoClipSecondary = v7->ammoClip;
    if ( ammoClipSecondary != nullptr )
      decl = (const idDeclAmmo *)ammoClipSecondary->decl;
    else
      decl = nullptr;
    if ( v8
      && decl != nullptr
      && (unsigned __int8)XGComparePixelShaders() != 0
      && v7->NeedsReload(this: v7, a2: secondary) )
    {
      v11 = this->owner->GetInventory(this: this->owner);
      if ( idWeapon::CanReload(this: v7, inventory: v11, ammoDecl: decl, secondaryAmmo: secondary) )
      {
        if ( setLingeringAction != 0 )
        {
          this->lingeringAction.action = HANDSACTION_NONE;
          this->lingeringAction.ammoDecl = nullptr;
          this->lingeringAction.weapon = nullptr;
          this->lingeringAction.throwable = nullptr;
          this->lingeringAction.useIntroBringUp = false;
          this->lingeringAction.isSecondary = false;
          this->lingeringAction.leftHand = false;
          idStr::Clear(this: &this->lingeringAction.extraNodeInfo);
          this->lingeringAction.ammoDecl = decl;
          this->lingeringAction.action = HANDSACTION_RELOAD;
          this->lingeringAction.isSecondary = secondary;
          this->lingeringAction.leftHand = false;
        }
        else
        {
          idHands::SetPendingAction(this, action: HANDSACTION_RELOAD, ammoDecl: decl, secondary, leftHand: false);
        }
        if ( com_multiplayer.valueInteger == 0 )
        {
          v12 = this->owner;
          entity = v12->entity;
          if ( entity != nullptr )
          {
            playerProps = v12->playerProps;
            LODWORD(v15) = &v29;
            HIBYTE(v29) = 100;
            reloadTutorial = playerProps->tutorialData.reloadTutorial;
            HIDWORD(v15) = reloadTutorial;
            DWORD1(v16) = v29;
            *((_QWORD *)&v16 + 1) = v31;
            v17 = __ROL4__(v32, 32);
            idEventReceiver::PostEventMS(
              this: entity,
              ev: &EV_EndSpecificTutorial,
              arg1: *(__int64 *)((char *)&v16 + 4),
              a4: *(__int64 *)((char *)&v16 - 4),
              a5: v15,
              a6: v21,
              a7: v22,
              a8: v23,
              a9: v24,
              a10: v25,
              a11: v26,
              a12: v27,
              a13: v28);
          }
        }
      }
    }
    if ( secondary )
      break;
    if ( this->currentDualWieldState != SET_DUALWIELD_ON )
      break;
    if ( (unsigned __int8)idHands::ReloadPending(this) == 0 )
      break;
    v18 = v7->GetClipSize(this: v7, a2: ammoClipSecondary, a3: decl, a4: false, a5: false);
    v19 = v18 - idWeapon::AmmoInClip(this: v7, secondaryAmmo: false);
    v20 = this->owner->GetInventory(this: this->owner);
    if ( idInventoryCollection::FindTotalInventoryItemCount(this: v20, decl) - v19 <= 0 )
      break;
    setLingeringAction = (unsigned __int8)idHands::ReloadPending(this);
  }
}


// ========================================================================
// ?PistolWhip@idHands@@QAAXXZ
// EA  : 0x82E03150
// RVA : 0x00E03150
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::PistolWhip(idHands *this)
{
  this->pendingAction.action = HANDSACTION_NONE;
  this->pendingAction.ammoDecl = nullptr;
  this->pendingAction.weapon = nullptr;
  this->pendingAction.throwable = nullptr;
  this->pendingAction.useIntroBringUp = false;
  this->pendingAction.isSecondary = false;
  this->pendingAction.leftHand = false;
  idStr::Clear(this: &this->pendingAction.extraNodeInfo);
  this->pendingAction.isSecondary = false;
  this->pendingAction.action = HANDSACTION_PISTOLWHIP;
}


// ========================================================================
// ?ThrowItem@idHands@@QAAXPAVidThrowableItem@@@Z
// EA  : 0x82E031B8
// RVA : 0x00E031B8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::ThrowItem(idHands *this, idThrowableItem *item)
{
  const idDeclThrowable *DeclThrowable; // r3
  const idDeclThrowable *v4; // r29

  DeclThrowable = idThrowableItem::GetDeclThrowable(this: item);
  this->pendingAction.action = HANDSACTION_NONE;
  v4 = DeclThrowable;
  this->pendingAction.ammoDecl = nullptr;
  this->pendingAction.weapon = nullptr;
  this->pendingAction.throwable = nullptr;
  this->pendingAction.useIntroBringUp = false;
  this->pendingAction.isSecondary = false;
  this->pendingAction.leftHand = false;
  idStr::Clear(this: &this->pendingAction.extraNodeInfo);
  this->pendingAction.throwable = v4;
  this->pendingAction.action = HANDSACTION_THROWITEM;
  this->pendingAction.isSecondary = false;
}


// ========================================================================
// ?PreLoadWeaponSounds@idHands@@SAXPBVidDeclProjectile@@@Z
// EA  : 0x82E03218
// RVA : 0x00E03218
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::PreLoadWeaponSounds(const idDeclProjectile *projectile)
{
  idSoundShader *fireSound; // r3
  idSoundShader *lastShotSound; // r3
  idSoundShader *onlineFireSound; // r3
  idSoundShader *onlineLastShotSound; // r3

  if ( projectile != nullptr )
  {
    _idHands::PreLoadWeaponSounds_::_2_::local_t::PreLoadSoundList(list: &projectile->envFireSounds);
    _idHands::PreLoadWeaponSounds_::_2_::local_t::PreLoadSoundList(list: &projectile->envLastShotSound);
    _idHands::PreLoadWeaponSounds_::_2_::local_t::PreLoadSoundList(list: &projectile->envOnlineFireSounds);
    _idHands::PreLoadWeaponSounds_::_2_::local_t::PreLoadSoundList(list: &projectile->envOnlineLastShotSound);
    fireSound = projectile->fireSound;
    if ( fireSound != nullptr )
      idSoundShader::GetNextEntry(this: fireSound, preTouchData: true);
    lastShotSound = projectile->lastShotSound;
    if ( lastShotSound != nullptr )
      idSoundShader::GetNextEntry(this: lastShotSound, preTouchData: true);
    onlineFireSound = projectile->onlineFireSound;
    if ( onlineFireSound != nullptr )
      idSoundShader::GetNextEntry(this: onlineFireSound, preTouchData: true);
    onlineLastShotSound = projectile->onlineLastShotSound;
    if ( onlineLastShotSound != nullptr )
      idSoundShader::GetNextEntry(this: onlineLastShotSound, preTouchData: true);
  }
}


// ========================================================================
// ?AnimEvent_PitchedSound@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidSoundShader@@M@Z
// EA  : 0x82E032B8
// RVA : 0x00E032B8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_PitchedSound(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idSoundShader *shader,
        double pitchAdj)
{
  const char *str; // r31
  int PlayerGameTime; // r3
  soundShaderParms_t v12; // [sp+50h] [-D0h] BYREF

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_PitchedSound - '^2%s^7'\n", PlayerGameTime, str);
  }
  soundShaderParms_t::Clear(this: &v12);
  v12.pitch.max = pitchAdj;
  v12.pitch.min = pitchAdj;
  idPresentablePlayer::StartSoundShader(
    this: *(idPresentablePlayer **)&result[12],
    channel: SND_CHANNEL_ANY,
    shader,
    parms: &v12,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?AnimEvent_ReloadWeaponSavedAmmo@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@W4equipSlot_t@@@Z
// EA  : 0x82E03360
// RVA : 0x00E03360
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_ReloadWeaponSavedAmmo(
        idHands *this,
        idHands *result,
        const idMD6Anim *anim,
        equipSlot_t slot)
{
  idWeapon *v7; // r3

  v7 = result->owner->GetEquippedWeapon(this: result->owner, a2: slot);
  idWeapon::SetFireState(this: v7, fs: FIRESTATE_RELOADING);
  idHands::ReloadWeapon(this: result, slot, sameAmmoCount: true, secondary: false);
  return this;
}


// ========================================================================
// ?AnimEvent_ReloadWeapon@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@W4equipSlot_t@@@Z
// EA  : 0x82E033B8
// RVA : 0x00E033B8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_ReloadWeapon(
        idHands *this,
        idHands *result,
        const idMD6Anim *anim,
        equipSlot_t slot)
{
  const char *str; // r29
  int PlayerGameTime; // r3
  idWeapon *v10; // r3
  idWeapon *v11; // r31

  result->lastWeaponUsedTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_ReloadWeaponRight - '^2%s^7'\n", PlayerGameTime, str);
  }
  v10 = result->owner->GetEquippedWeapon(this: result->owner, a2: slot);
  v11 = v10;
  if ( v10 != nullptr )
  {
    idWeapon::SetFireState(this: v10, fs: FIRESTATE_RELOADING);
    idHands::ReloadWeapon(
      this: result,
      slot,
      sameAmmoCount: false,
      secondary: (_cntlzw(v11->weaponState - 1) & 0x20) != 0);
  }
  return this;
}


// ========================================================================
// ?AnimEvent_CheackAutoReload@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82E03490
// RVA : 0x00E03490
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_CheackAutoReload(idHands *this, idHands *result, const idMD6Anim *anim)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_CheackAutoReload - '^2%s^7'\n", PlayerGameTime, str);
  }
  idHands::CheckAutoReload(this: result, secondary: false, setLingeringAction: 0);
  return this;
}


// ========================================================================
// ?AnimEvent_HideMeshForSlot@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD1@Z
// EA  : 0x82E03510
// RVA : 0x00E03510
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_HideMeshForSlot(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const char *slotName,
        const char *meshName)
{
  const char *str; // r31
  int PlayerGameTime; // r3
  int v11; // r3
  eventVoid *v13; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v15; // r31
  int MeshIndex; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(
      fmt: "^7( %d )idHands::AnimEvent_HideMeshForSlot - %s '^2%s^7, %s'\n",
      PlayerGameTime,
      slotName,
      str,
      meshName);
  }
  v11 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( v11 != 0 )
  {
    if ( v11 == 15 )
    {
      if ( hands_debugfc.valueInteger > 0 )
      {
        idLib::Warning(fmt: "slot == EQUIP_MAX for %s", slotName);
        return this;
      }
    }
    else
    {
      if ( v11 == 1 )
      {
        v13 = result + 4532;
      }
      else if ( v11 == 2 )
      {
        v13 = result + 2996;
      }
      else
      {
        v13 = nullptr;
      }
      TreeAnimatorFromPresentable = idHandsItem::GetTreeAnimatorFromPresentable(this: (idHandsItem *)v13);
      v15 = TreeAnimatorFromPresentable;
      if ( TreeAnimatorFromPresentable != nullptr )
      {
        MeshIndex = idTreeAnimator::GetMeshIndex(this: TreeAnimatorFromPresentable, meshName);
        if ( MeshIndex >= 0 )
        {
          v15->meshVisibility.list[MeshIndex] = false;
          return this;
        }
        if ( hands_debugfc.valueInteger > 0 )
          idLib::Warning(fmt: "clipMeshIndex invalid for %s", meshName);
      }
      else if ( hands_debugfc.valueInteger > 0 )
      {
        idLib::Warning(fmt: "animator == NULL on handsItem");
        return this;
      }
    }
  }
  else if ( hands_debugfc.valueInteger > 0 )
  {
    idLib::Warning(fmt: "slot == EQUIP_NONE for %s", slotName);
    return this;
  }
  return this;
}


// ========================================================================
// ?AnimEvent_ShowMeshForSlot@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD1@Z
// EA  : 0x82E03698
// RVA : 0x00E03698
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_ShowMeshForSlot(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const char *slotName,
        const char *meshName)
{
  const char *str; // r31
  int PlayerGameTime; // r3
  int v11; // r3
  eventVoid *v13; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v15; // r31
  int MeshIndex; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(
      fmt: "^7( %d )idHands::AnimEvent_ShowMeshForSlot - %s '^2%s^7, %s'\n",
      PlayerGameTime,
      slotName,
      str,
      meshName);
  }
  v11 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( v11 != 0 )
  {
    if ( v11 == 15 )
    {
      if ( hands_debugfc.valueInteger > 0 )
      {
        idLib::Warning(fmt: "slot == EQUIP_MAX for %s", slotName);
        return this;
      }
    }
    else
    {
      if ( v11 == 1 )
      {
        v13 = result + 4532;
      }
      else if ( v11 == 2 )
      {
        v13 = result + 2996;
      }
      else
      {
        v13 = nullptr;
      }
      TreeAnimatorFromPresentable = idHandsItem::GetTreeAnimatorFromPresentable(this: (idHandsItem *)v13);
      v15 = TreeAnimatorFromPresentable;
      if ( TreeAnimatorFromPresentable != nullptr )
      {
        MeshIndex = idTreeAnimator::GetMeshIndex(this: TreeAnimatorFromPresentable, meshName);
        if ( MeshIndex >= 0 )
        {
          v15->meshVisibility.list[MeshIndex] = true;
          return this;
        }
        if ( hands_debugfc.valueInteger > 0 )
          idLib::Warning(fmt: "clipMeshIndex invalid for %s", meshName);
      }
      else if ( hands_debugfc.valueInteger > 0 )
      {
        idLib::Warning(fmt: "animator == NULL on handsItem");
        return this;
      }
    }
  }
  else if ( hands_debugfc.valueInteger > 0 )
  {
    idLib::Warning(fmt: "slot == EQUIP_NONE for %s", slotName);
    return this;
  }
  return this;
}


// ========================================================================
// ?AnimEvent_WeaponMeshForNextAmmo@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82E03820
// RVA : 0x00E03820
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_WeaponMeshForNextAmmo(idHands *this, idHands *result, const idMD6Anim *anim)
{
  const char *str; // r31
  int PlayerGameTime; // r3
  int v7; // r3
  const idDeclAmmo *v9; // r4

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_WeaponMeshForNextAmmo'^2%s^7'\n", PlayerGameTime, str);
  }
  v7 = (int)result->owner->GetEquippedWeapon(this: result->owner, a2: EQUIP_RIGHT_HAND);
  if ( v7 != 0 )
  {
    v9 = *(const idDeclAmmo **)(v7 + 48);
    if ( v9 != nullptr )
    {
      idHands::UpdateAmmoMeshForWeapon(this: result, ammoDecl: v9);
    }
    else if ( hands_debugfc.valueInteger > 0 )
    {
      idLib::Warning(fmt: "ammoDecl == NULL");
      return this;
    }
  }
  else if ( hands_debugfc.valueInteger > 0 )
  {
    idLib::Warning(fmt: "weapon == NULL");
    return this;
  }
  return this;
}


// ========================================================================
// ShowMesh
// EA  : 0x82E03910
// RVA : 0x00E03910
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall ShowMesh(idTreeAnimator *animator, idStr *mesh, bool show)
{
  int MeshIndex; // r3

  MeshIndex = idTreeAnimator::GetMeshIndex(this: animator, meshName: mesh->data);
  if ( MeshIndex >= 0 )
    animator->meshVisibility.list[MeshIndex] = show;
  idStr::FreeData(this: mesh);
}


// ========================================================================
// __unwind$500060
// EA  : 0x82E0396C
// RVA : 0x00E0396C
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_500060()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 156));
}


// ========================================================================
// ?AnimEvent_EjectShell@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@W4equipSlot_t@@@Z
// EA  : 0x82E03998
// RVA : 0x00E03998
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_EjectShell(
        idHands *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const equipSlot_t slot)
{
  eventVoid *v6; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r31
  idWeapon *v8; // r3
  idWeapon *v9; // r30
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r8
  idRenderModelParms *p_deferredOrigin; // r11
  float y; // r9
  float z; // r7
  idMat3 *p_deferredAxis; // r11
  idInventoryItem *v16; // r10
  idInventoryItem_vtbl **p_z; // r11
  int i; // ctr
  idMat3 *p_axis; // r11
  char *v20; // r10
  _DWORD *v21; // r11
  int j; // ctr
  idRenderModelParms *p_g; // r11
  float v24; // r7
  float v25; // r5
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *p_parentJoint; // r10
  eventVoid *v27; // r11
  int k; // ctr
  float *v29; // r11
  const idDeclInventory *v30; // r11
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *v31; // r10
  eventVoid *v32; // r11
  int m; // ctr
  float *v34; // r11
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *v35; // r10
  eventVoid *v36; // r11
  int n; // ctr
  float *v38; // r11
  int v39; // r31
  float *v40; // r28
  float *v41; // r3
  double v42; // fp6
  double v43; // fp4
  idFXManager *FXMgr; // r3
  idStrId *DisplayName; // r3
  const char *LocalizedString; // r3
  tagData_t v48; // [sp+50h] [-130h] BYREF
  float v49; // [sp+70h] [-110h]
  float v50; // [sp+74h] [-10Ch]
  float v51; // [sp+78h] [-108h]
  float v52; // [sp+7Ch] [-104h]
  float v53; // [sp+80h] [-100h]
  float v54; // [sp+84h] [-FCh]
  float v55; // [sp+88h] [-F8h]
  unsigned __int16 v56; // [sp+8Ch] [-F4h]
  idVec3 v57; // [sp+90h] [-F0h] BYREF
  idVec3 v58; // [sp+A0h] [-E0h] BYREF
  idVec3 v59; // [sp+B0h] [-D0h] BYREF
  idVec3 v60; // [sp+C0h] [-C0h] BYREF
  idInventoryItem v61; // [sp+CCh] [-B4h] BYREF
  char v62; // [sp+FCh] [-84h] BYREF
  idMat3 v63; // [sp+100h] [-80h] BYREF
  char v64[16]; // [sp+128h] [-58h] BYREF
  char v65; // [sp+138h] [-48h] BYREF

  if ( slot == EQUIP_LEFT_HAND )
  {
    v6 = result + 4532;
  }
  else
  {
    if ( slot != EQUIP_RIGHT_HAND )
      return this;
    v6 = result + 2996;
  }
  if ( v6 != nullptr )
  {
    TreeAnimatorFromPresentable = idHandsItem::GetTreeAnimatorFromPresentable(this: (idHandsItem *)v6);
    if ( TreeAnimatorFromPresentable != nullptr )
    {
      v8 = idWeapon::CastTo(c: *(idWeapon **)&v6[1452]);
      v9 = v8;
      if ( v8 != nullptr )
      {
        decl = TreeAnimatorFromPresentable->decl;
        p_props = &decl->props;
        if ( decl == nullptr )
          p_props = nullptr;
        p_deferredOrigin = (idRenderModelParms *)&TreeAnimatorFromPresentable->deferredOrigin;
        if ( !TreeAnimatorFromPresentable->useDeferredPosition )
          p_deferredOrigin = &TreeAnimatorFromPresentable->g;
        y = p_deferredOrigin->origin.y;
        z = p_deferredOrigin->origin.z;
        v57.x = p_deferredOrigin->origin.x;
        p_deferredAxis = &TreeAnimatorFromPresentable->deferredAxis;
        v57.y = y;
        v57.z = z;
        if ( !TreeAnimatorFromPresentable->useDeferredPosition )
          p_deferredAxis = &TreeAnimatorFromPresentable->g.axis;
        v16 = &v61;
        p_z = (idInventoryItem_vtbl **)&p_deferredAxis[-1].mat[2].z;
        for ( i = 9; i != 0; --i )
        {
          ++p_z;
          v16 = (idInventoryItem *)((char *)v16 + 4);
          v16->__vftable = *p_z;
        }
        p_axis = &TreeAnimatorFromPresentable->deferredAxis;
        if ( !TreeAnimatorFromPresentable->useDeferredPosition )
          p_axis = &TreeAnimatorFromPresentable->g.axis;
        v20 = &v62;
        v21 = (_DWORD *)&p_axis[-1].mat[2].z;
        for ( j = 9; j != 0; --j )
        {
          ++v21;
          v20 += 4;
          *(_DWORD *)v20 = *v21;
        }
        p_g = (idRenderModelParms *)&TreeAnimatorFromPresentable->deferredOrigin;
        if ( !TreeAnimatorFromPresentable->useDeferredPosition )
          p_g = &TreeAnimatorFromPresentable->g;
        v24 = p_g->origin.y;
        v25 = p_g->origin.z;
        v58.x = p_g->origin.x;
        v48.parentJoint.value = -1;
        v48.trans.x = 0.0;
        v58.y = v24;
        v48.trans.y = 0.0;
        v58.z = v25;
        v48.trans.z = 0.0;
        v48.rot.x = 0.0;
        v48.rot.y = 0.0;
        v48.rot.z = 0.0;
        v48.rot.w = 0.0;
        if ( p_props != nullptr )
        {
          if ( (*((_BYTE *)v8 + 452) & 0x80) != 0 && (*((_BYTE *)v8 + 452) & 0x40) != 0 )
          {
            p_parentJoint = &v48.parentJoint;
            v27 = v6 + 1488;
            for ( k = 8; k != 0; --k )
            {
              v27 += 4;
              p_parentJoint += 2;
              *(_DWORD *)&p_parentJoint->value = *(_DWORD *)v27;
            }
            v48.parentJoint.value = v56;
            v48.trans.x = v49;
            v48.trans.y = v50;
            v48.trans.z = v51;
            v48.rot.x = v52;
            v48.rot.y = v53;
            v48.rot.z = v54;
            v48.rot.w = v55;
            idTreeAnimator::GetWorldSpaceTagTransform(
              this: TreeAnimatorFromPresentable,
              tagData: &v48,
              origin: &v57,
              axis: (idMat3 *)&v61.listenerList);
            v29 = (float *)v9->decl;
            v48.trans.x = v48.trans.x - v29[460];
            v48.trans.y = v48.trans.y - v29[461];
            v48.trans.z = v48.trans.z - v29[462];
            idTreeAnimator::GetWorldSpaceTagTransform(
              this: TreeAnimatorFromPresentable,
              tagData: &v48,
              origin: &v58,
              axis: (idMat3 *)&v61.listenerList);
            *((_BYTE *)v9 + 452) &= ~0x40u;
LABEL_36:
            idMat3::RotateSelf(this: &v63, axis: &v63.mat[2], angle: 90.0);
            v39 = *(_DWORD *)&result[12] + 36264;
            v40 = (float *)(*(int (__fastcall **)(char *, int, _DWORD))(*(_DWORD *)v39 + 92))(a1: v64, a2: v39, a3: 0);
            v41 = (float *)(*(int (__fastcall **)(char *, int, _DWORD))(*(_DWORD *)v39 + 88))(a1: &v65, a2: v39, a3: 0);
            v42 = (float)(v41[2] + v40[2]);
            v43 = (float)(v41[1] + v40[1]);
            v60.x = *v41 + *v40;
            v59.x = v58.x - v57.x;
            v59.y = v58.y - v57.y;
            v59.z = v58.z - v57.z;
            v60.z = v42;
            v60.y = v43;
            FXMgr = idHandsItem::GetFXMgr(this: (idHandsItem *)v6);
            idWeapon::EjectShell(
              this: v9,
              ejectPos: &v57,
              firstPersonOffset: &v59,
              shellOrientation: &v63,
              ejectAxis: (const idMat3 *)&v61.listenerList,
              emitterVelocity: &v60,
              fxMgr: FXMgr);
            return this;
          }
          v30 = v8->decl;
          if ( *(_DWORD *)&v30[3].giveable != 0 )
          {
            v31 = &v48.parentJoint;
            v32 = v6 + 1456;
            for ( m = 8; m != 0; --m )
            {
              v32 += 4;
              v31 += 2;
              *(_DWORD *)&v31->value = *(_DWORD *)v32;
            }
            v48.parentJoint.value = v56;
            v48.trans.x = v49;
            v48.trans.y = v50;
            v48.trans.z = v51;
            v48.rot.x = v52;
            v48.rot.y = v53;
            v48.rot.z = v54;
            v48.rot.w = v55;
            idTreeAnimator::GetWorldSpaceTagTransform(
              this: TreeAnimatorFromPresentable,
              tagData: &v48,
              origin: &v57,
              axis: (idMat3 *)&v61.listenerList);
            v34 = (float *)v9->decl;
            v48.trans.x = v48.trans.x + v34[449];
            v48.trans.y = v34[450] + v48.trans.y;
            v48.trans.z = v34[451] + v48.trans.z;
            idTreeAnimator::GetWorldSpaceTagTransform(
              this: TreeAnimatorFromPresentable,
              tagData: &v48,
              origin: &v58,
              axis: (idMat3 *)&v61.listenerList);
            *((_BYTE *)v9 + 452) |= 0x40u;
            goto LABEL_36;
          }
          if ( *(_DWORD *)v30[3].vehicleJointName.baseBuffer != 0 )
          {
            v35 = &v48.parentJoint;
            v36 = v6 + 1488;
            for ( n = 8; n != 0; --n )
            {
              v36 += 4;
              v35 += 2;
              *(_DWORD *)&v35->value = *(_DWORD *)v36;
            }
            v48.parentJoint.value = v56;
            v48.trans.x = v49;
            v48.trans.y = v50;
            v48.trans.z = v51;
            v48.rot.x = v52;
            v48.rot.y = v53;
            v48.rot.z = v54;
            v48.rot.w = v55;
            idTreeAnimator::GetWorldSpaceTagTransform(
              this: TreeAnimatorFromPresentable,
              tagData: &v48,
              origin: &v57,
              axis: (idMat3 *)&v61.listenerList);
            v38 = (float *)v9->decl;
            v48.trans.x = v48.trans.x - v38[460];
            v48.trans.y = v48.trans.y - v38[461];
            v48.trans.z = v48.trans.z - v38[462];
            idTreeAnimator::GetWorldSpaceTagTransform(
              this: TreeAnimatorFromPresentable,
              tagData: &v48,
              origin: &v58,
              axis: (idMat3 *)&v61.listenerList);
            goto LABEL_36;
          }
          DisplayName = idInventoryItem::GetDisplayName(this: &v61, result: (idStrId *)v8);
          LocalizedString = idStrId::GetLocalizedString(this: DisplayName);
          idLib::Warning(
            fmt: "'%s' does not have a tag to eject from. Set a shellEject in the weapon decl.",
            LocalizedString);
        }
      }
    }
  }
  return this;
}


// ========================================================================
// ?ShowRRL@idHands@@QAAX_NPAVidWeapon@@@Z
// EA  : 0x82E03EA8
// RVA : 0x00E03EA8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::ShowRRL(idHands *this, bool usePending, idWeapon *equipingWeapon)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r24
  idWeapon *v7; // r25
  const idDeclAmmo *nextAmmo; // r20
  idAmmoItem *ammoClip; // r10
  char v10; // r14
  char v11; // r15
  int AmmoDeclIndex; // r22
  idStr *v13; // r3
  idStr *v14; // r3
  idInventoryCollection *v15; // r21
  int v16; // r11
  unsigned int v17; // r30
  int v18; // r26
  bool v19; // r27
  int v20; // r28
  unsigned __int8 v21; // r29
  unsigned int TotalInventoryItemCount; // r3
  idStr *v23; // r30
  int MeshIndex; // r3
  bool *list; // r11
  idStr v26; // [sp+60h] [-1C0h] BYREF
  char v27[416]; // [sp+80h] [-1A0h] BYREF

  TreeAnimatorFromPresentable = idHandsItem::GetTreeAnimatorFromPresentable(this: &this->rightItem);
  if ( TreeAnimatorFromPresentable == nullptr )
    return;
  v7 = equipingWeapon != nullptr ? equipingWeapon : this->owner->GetEquippedWeapon(this: this->owner, a2: 2);
  if ( v7 == nullptr )
    return;
  nextAmmo = v7->nextAmmo;
  ammoClip = v7->ammoClip;
  v10 = 0;
  v11 = 0;
  if ( usePending && nextAmmo != nullptr )
  {
    if ( ammoClip == nullptr || ammoClip->decl != nextAmmo )
    {
      v10 = 1;
      goto LABEL_14;
    }
    goto LABEL_13;
  }
  if ( ammoClip != nullptr )
  {
    nextAmmo = (const idDeclAmmo *)ammoClip->decl;
    if ( usePending )
LABEL_13:
      v11 = 1;
  }
LABEL_14:
  if ( nextAmmo != nullptr )
  {
    AmmoDeclIndex = idWeapon::GetAmmoDeclIndex(this: v7, ammo: nextAmmo, secondaryAmmo: false);
    v13 = idStr::idStr(this: &v26, text: "ammoclip1_mesh");
    ShowMesh(
      animator: TreeAnimatorFromPresentable,
      mesh: v13,
      show: ((AmmoDeclIndex >= 0) + ((unsigned int)AmmoDeclIndex >= 2)) & 1);
    v14 = idStr::idStr(this: &v26, text: "ammoclip2_mesh");
    ShowMesh(animator: TreeAnimatorFromPresentable, mesh: v14, show: (_cntlzw(AmmoDeclIndex - 2) & 0x20) != 0);
    v15 = this->owner->GetInventory(this: this->owner);
    v16 = 0;
    do
    {
      v17 = 0;
      v18 = v16 + 1;
      v19 = (_cntlzw(v16 - AmmoDeclIndex) & 0x20) != 0;
      do
      {
        v20 = v17 + 1;
        sprintf_0(string: v27, format: "shell%d_mesh%d", v18, v17 + 1);
        v21 = v19;
        if ( v19 )
        {
          if ( v10 != 0 )
          {
            TotalInventoryItemCount = v7->TotalLoadedAmmoCount(this: v7, a2: v15, a3: false);
          }
          else if ( v11 != 0 )
          {
            TotalInventoryItemCount = idInventoryCollection::FindTotalInventoryItemCount(this: v15, decl: nextAmmo);
          }
          else
          {
            TotalInventoryItemCount = idWeapon::AmmoInClip(this: v7, secondaryAmmo: false);
          }
          v21 = ((((TotalInventoryItemCount ^ v17) & 0x80000000) == 0) + (v17 >= TotalInventoryItemCount)) & 1;
        }
        if ( hands_debugfc.valueInteger > 0 )
          idLib::Printf(fmt: "^7calling ShowMesh - '^2%s %d^7'\n", v27, v21);
        v23 = idStr::idStr(this: &v26, text: v27);
        MeshIndex = idTreeAnimator::GetMeshIndex(this: TreeAnimatorFromPresentable, meshName: v23->data);
        if ( MeshIndex >= 0 )
        {
          list = TreeAnimatorFromPresentable->meshVisibility.list;
          list[MeshIndex] = v21 != 0;
        }
        idStr::FreeData(this: v23);
        v17 = v20;
      }
      while ( v20 < 4 );
      v16 = v18;
    }
    while ( v18 < 3 );
  }
  else
  {
    idLib::Warning(fmt: "idHands::ShowRRL(): could not find ammo for weapon '%s'", v7->decl->name.str);
  }
}


// ========================================================================
// __unwind$500428
// EA  : 0x82E04160
// RVA : 0x00E04160
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_500428()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 544 + 80));
}


// ========================================================================
// ?AnimEvent_HideAmmoShellsRRL@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82E04188
// RVA : 0x00E04188
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_HideAmmoShellsRRL(idHands *this, idHands *result, const idMD6Anim *anim)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_HideAmmoShellsRRL - '^2%s^7'\n", PlayerGameTime, str);
  }
  idHands::ShowRRL(this: result, usePending: false, equipingWeapon: nullptr);
  return this;
}


// ========================================================================
// ?AnimEvent_ShowAmmoShellsRRL@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82E04208
// RVA : 0x00E04208
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_ShowAmmoShellsRRL(idHands *this, idHands *result, const idMD6Anim *anim)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_ShowAmmoShellsRRL - '^2%s^7'\n", PlayerGameTime, str);
  }
  idHands::ShowRRL(this: result, usePending: true, equipingWeapon: nullptr);
  return this;
}


// ========================================================================
// ?ShouldAnimateCamera@idHands@@QAA_NXZ
// EA  : 0x82E04288
// RVA : 0x00E04288
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

BOOL __fastcall idHands::ShouldAnimateCamera(idHands *this)
{
  int value; // r11
  idDeclAnimWebNode *v3; // r11
  unsigned __int8 flags; // r11
  BOOL result; // r3
  int num; // r10
  int v7; // r11
  __int16 v8; // r11

  value = this->web.curNodeIndex.value;
  if ( value == -1 )
    v3 = nullptr;
  else
    v3 = this->web.decl->nodes.list[value];
  flags = v3->flags;
  result = (flags & 0x20) != 0;
  if ( (flags & 0x20) == 0 )
  {
    num = this->web.curPath.num;
    if ( num <= 0 )
    {
      v8 = -1;
    }
    else
    {
      v7 = (__int16)(num - 1);
      if ( v7 < 0 || v7 >= this->web.curPath.num )
        v8 = -1;
      else
        v8 = this->web.curPath.path[v7].value;
    }
    if ( v8 != -1 )
      return (this->web.decl->nodes.list[v8]->flags & 0x20) != 0;
  }
  return result;
}


// ========================================================================
// ??1idHands@@UAA@XZ
// EA  : 0x82E04390
// RVA : 0x00E04390
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::~idHands(idHands *this)
{
  idRenderModel *testModel; // r3

  this->__vftable = (idHands_vtbl *)&idHands::`vftable';
  idHands::FreePresentables(this);
  testModel = this->testModel;
  if ( testModel != nullptr )
  {
    testModel->unlinked = true;
    testModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: testModel);
    this->testModel = nullptr;
  }
  idStr::FreeData(this: &this->dualWieldLeftHandPendingAction.extraNodeInfo);
  idStr::FreeData(this: &this->lingeringAction.extraNodeInfo);
  idStr::FreeData(this: &this->pendingAction.extraNodeInfo);
  idMeleeTrace::~idMeleeTrace(this: &this->handsMeleeTrace);
  idAnimEventHandler::~idAnimEventHandler(this: &this->animEventHandler);
  idHandsItem::~idHandsItem(this: &this->leftItem);
  idHandsItem::~idHandsItem(this: &this->rightItem);
  idAnimWebHands::~idAnimWebHands(this: &this->secondaryWeb);
  idAnimWebHands::~idAnimWebHands(this: &this->web);
  idAnimStack::~idAnimStack(this: &this->animStack);
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$501092
// EA  : 0x82E04464
// RVA : 0x00E04464
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501092()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$501093
// EA  : 0x82E0448C
// RVA : 0x00E0448C
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501093()
{
  int v0; // r12

  idAnimStack::~idAnimStack(this: (idAnimStack *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// __unwind$501094
// EA  : 0x82E044B8
// RVA : 0x00E044B8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501094()
{
  int v0; // r12

  idAnimWebHands::~idAnimWebHands(this: (idAnimWebHands *)(*(_DWORD *)(v0 - 112 + 132) + 1592));
}


// ========================================================================
// __unwind$501095
// EA  : 0x82E044E4
// RVA : 0x00E044E4
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501095()
{
  int v0; // r12

  idAnimWebHands::~idAnimWebHands(this: (idAnimWebHands *)(*(_DWORD *)(v0 - 112 + 132) + 2284));
}


// ========================================================================
// __unwind$501096
// EA  : 0x82E04510
// RVA : 0x00E04510
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501096()
{
  int v0; // r12

  idHandsItem::~idHandsItem(this: (idHandsItem *)(*(_DWORD *)(v0 - 112 + 132) + 2996));
}


// ========================================================================
// __unwind$501097
// EA  : 0x82E0453C
// RVA : 0x00E0453C
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501097()
{
  int v0; // r12

  idHandsItem::~idHandsItem(this: (idHandsItem *)(*(_DWORD *)(v0 - 112 + 132) + 4532));
}


// ========================================================================
// __unwind$501098
// EA  : 0x82E04568
// RVA : 0x00E04568
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501098()
{
  int v0; // r12

  idAnimEventHandler::~idAnimEventHandler(this: (idAnimEventHandler *)(*(_DWORD *)(v0 - 112 + 132) + 6136));
}


// ========================================================================
// __unwind$501099
// EA  : 0x82E04594
// RVA : 0x00E04594
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501099()
{
  int v0; // r12

  idMeleeTrace::~idMeleeTrace(this: (idMeleeTrace *)(*(_DWORD *)(v0 - 112 + 132) + 7684));
}


// ========================================================================
// __unwind$501100
// EA  : 0x82E045C0
// RVA : 0x00E045C0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501100()
{
  int v0; // r12

  idHudPickupInfo::~idHudPickupInfo(this: (idHudPickupInfo *)(*(_DWORD *)(v0 - 112 + 132) + 7784));
}


// ========================================================================
// __unwind$501101_0
// EA  : 0x82E045EC
// RVA : 0x00E045EC
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501101_0()
{
  int v0; // r12

  idHudPickupInfo::~idHudPickupInfo(this: (idHudPickupInfo *)(*(_DWORD *)(v0 - 112 + 132) + 7836));
}


// ========================================================================
// __unwind$501102_0
// EA  : 0x82E04618
// RVA : 0x00E04618
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501102_0()
{
  int v0; // r12

  idHudPickupInfo::~idHudPickupInfo(this: (idHudPickupInfo *)(*(_DWORD *)(v0 - 112 + 132) + 7960));
}


// ========================================================================
// ?SelectAmmo@idHands@@QAAXW4equipSlot_t@@PBVidDeclAmmo@@@Z
// EA  : 0x82E04648
// RVA : 0x00E04648
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SelectAmmo(idHands *this, const equipSlot_t slot, const idDeclAmmo *ammoDecl)
{
  idHandsItem *p_leftItem; // r11
  idWeapon *v7; // r30
  const idInventoryCollection *v8; // r3
  const idDeclProjectile *projectileDecl; // r3

  if ( this->isWeaponBringUp )
    return;
  if ( slot == EQUIP_LEFT_HAND )
  {
    p_leftItem = &this->leftItem;
  }
  else
  {
    if ( slot != EQUIP_RIGHT_HAND )
    {
LABEL_8:
      v7 = nullptr;
      goto LABEL_9;
    }
    p_leftItem = &this->rightItem;
  }
  if ( p_leftItem == nullptr )
    goto LABEL_8;
  v7 = idWeapon::CastTo(c: (idWeapon *)p_leftItem->item);
LABEL_9:
  if ( slot == EQUIP_RIGHT_HAND )
    v7 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
  if ( v7 != nullptr )
  {
    v8 = this->owner->GetInventory(this: this->owner);
    if ( idWeapon::CanReload(this: v7, inventory: v8, ammoDecl, secondaryAmmo: false) )
    {
      idHands::SetPendingAction(this, action: HANDSACTION_AMMOCHANGE, ammoDecl, secondary: false, leftHand: false);
      if ( ammoDecl != nullptr )
      {
        projectileDecl = ammoDecl->projectileDecl;
        if ( projectileDecl != nullptr )
          idHands::PreLoadWeaponSounds(projectile: projectileDecl);
      }
    }
  }
}


// ========================================================================
// ?ForceAmmo@idHands@@QAAXPBVidDeclAmmo@@@Z
// EA  : 0x82E04738
// RVA : 0x00E04738
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::ForceAmmo(idHands *this, const idDeclAmmo *ammoDecl)
{
  const idDeclProjectile *projectileDecl; // r3
  idPresentablePlayer *owner; // r3
  idFXManager *p_fxManager; // r28
  BOOL isSecondary; // r26
  idWeapon_vtbl *v8; // r27
  int v9; // r3
  const idDeclInventory *decl; // r5
  int entityNumber; // r4
  idClientGameMsg v12; // [sp+50h] [-50h] BYREF
  const idDeclAmmo *v13; // [sp+58h] [-48h]
  const idDeclInventory *v14; // [sp+5Ch] [-44h]
  int v15; // [sp+60h] [-40h]
  char v16; // [sp+64h] [-3Ch]

  if ( this->pendingAction.weapon != nullptr )
  {
    if ( ammoDecl != nullptr )
    {
      projectileDecl = ammoDecl->projectileDecl;
      if ( projectileDecl != nullptr )
        idHands::PreLoadWeaponSounds(projectile: projectileDecl);
    }
    idWeapon::BeginReloading(this: this->pendingAction.weapon, ammoDecl, secondaryAmmo: false);
    owner = this->owner;
    p_fxManager = &owner->fxManager;
    isSecondary = this->pendingAction.isSecondary;
    v8 = this->pendingAction.weapon->__vftable;
    v9 = (int)owner->GetInventory(this: owner);
    v8->Reload(
      this: this->pendingAction.weapon,
      a2: (idInventoryCollection *)v9,
      a3: p_fxManager,
      a4: false,
      a5: true,
      a6: isSecondary);
    if ( common->IsMultiplayer(this: common) )
    {
      decl = this->pendingAction.weapon->decl;
      entityNumber = this->owner->entityNumber;
      v12.peerMask = -1;
      v12.__vftable = (idClientGameMsg_vtbl *)&idClientGameMsg_HandsAmmoChange::`vftable';
      v13 = ammoDecl;
      v14 = decl;
      v15 = entityNumber;
      v16 = 1;
      idClientGame::HandleReliableGameMsg(this: clientGame, gameMsg: &v12);
    }
  }
}


// ========================================================================
// __unwind$501285_0
// EA  : 0x82E04840
// RVA : 0x00E04840
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501285_0()
{
  int v0; // r12

  idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(this: (idClientGameMsg_VehicleWeaponChange *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetWeaponSubWebName@idHands@@QBAXPBVidWeapon@@AAVidStr@@_N@Z
// EA  : 0x82E04868
// RVA : 0x00E04868
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::GetWeaponSubWebName(idHands *this, const idWeapon *weapon, idStr *name, bool secondary)
{
  const idDeclAmmo *nextAmmo; // r31
  idAmmoItem *ammoClipSecondary; // r11
  idAmmoItem *ammoClip; // r11
  char *data; // r10
  int v11; // r11

  if ( weapon == nullptr )
  {
    idStr::operator=(this: name, text: "knife");
    return;
  }
  idStr::operator=(this: name, text: weapon->decl->internalName.data);
  if ( HIBYTE(weapon->decl[1].displayName.index) == 0 )
    return;
  if ( weapon->nextAmmo != nullptr )
  {
    nextAmmo = weapon->nextAmmo;
  }
  else
  {
    if ( secondary )
      ammoClipSecondary = weapon->ammoClipSecondary;
    else
      ammoClipSecondary = weapon->ammoClip;
    if ( ammoClipSecondary == nullptr )
      return;
    if ( secondary )
      ammoClip = weapon->ammoClipSecondary;
    else
      ammoClip = weapon->ammoClip;
    nextAmmo = (const idDeclAmmo *)ammoClip->decl;
  }
  if ( nextAmmo != nullptr )
  {
    idStr::Append(this: name, text: "_");
    idStr::Append(this: name, text: &nextAmmo->internalName);
    data = nextAmmo->internalName.data;
    v11 = 0;
    if ( *data == 0 )
      goto LABEL_17;
    do
      ++v11;
    while ( data[v11] != 0 );
    if ( v11 == 0 )
LABEL_17:
      idLib::Warning(fmt: "GetWeaponSubName() using empty internalName to try and create state '%s'", name->data);
  }
}


// ========================================================================
// ?GetWeaponSubWebName@idHands@@QBAXAAVidStr@@_N@Z
// EA  : 0x82E04970
// RVA : 0x00E04970
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::GetWeaponSubWebName(idHands *this, idStr *name, bool secondary)
{
  idWeapon *v6; // r4

  if ( this == (idHands *)-2996 )
    v6 = nullptr;
  else
    v6 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
  idHands::GetWeaponSubWebName(this, weapon: v6, name, secondary);
}


// ========================================================================
// ?GetShootNodeName@idHands@@QBA?AVidStr@@PBD_N1W4handsState_t@1@@Z
// EA  : 0x82E049C8
// RVA : 0x00E049C8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::GetShootNodeName(
        idHands *this,
        idStr *result,
        const char *stateName,
        bool rightWeapon,
        bool secondary,
        idHands::handsState_t state)
{
  BOOL v10; // r26
  char v11; // r9
  char *v12; // r11
  idWeapon *v13; // r3
  idWeapon *v14; // r30
  const idDeclAmmo *nextAmmo; // r11
  idAmmoItem *ammoClip; // r11
  idAmmoItem *ammoClipSecondary; // r11
  const idStr *v18; // r3
  char *v19; // r4
  idStr v21[3]; // [sp+60h] [-60h] BYREF

  v10 = rightWeapon;
  idStr::idStr((idStr *)this, text: stateName);
  v11 = _cntlzw(rightWeapon);
  if ( (v11 & 0x20) != 0 )
  {
    v12 = &result[141].baseBuffer[8];
  }
  else
  {
    if ( (v11 & 0x20) != 0 )
      return this;
    v12 = &result[93].baseBuffer[8];
  }
  if ( v12 != nullptr )
  {
    v13 = idWeapon::CastTo(c: *((idWeapon **)v12 + 363));
    v14 = v13;
    if ( v13 != nullptr )
    {
      nextAmmo = v13->nextAmmo;
      if ( nextAmmo != nullptr
        || (!secondary ? (ammoClip = v13->ammoClip) : (ammoClip = v13->ammoClipSecondary),
            ammoClip != nullptr
         && (!secondary ? (ammoClipSecondary = v13->ammoClip) : (ammoClipSecondary = v13->ammoClipSecondary),
             (nextAmmo = (const idDeclAmmo *)ammoClipSecondary->decl) != nullptr)) )
      {
        idStr::Append((idStr *)this, text: &nextAmmo->shootAnimPostfix);
      }
      if ( HIBYTE(result[239].data) == 0 && BYTE2(result[239].data) != 0 && LOBYTE(v14->decl[3].price) != 0 )
      {
        v18 = operator+(result: v21, a: "sprint", b: (const idStr *)this);
        idStr::operator=((idStr *)this, text: v18);
        idStr::FreeData(this: v21);
      }
      if ( *(_DWORD *)&result[248].baseBuffer[8] == 1 || (result[247].allocedAndFlag & 0x4000000) != 0 )
      {
        if ( v10 )
          v19 = "dwright";
        else
          v19 = "dwleft";
        idStr::Append((idStr *)this, text: v19);
      }
      if ( result[248].baseBuffer[4] != 0 && v10 || result[248].baseBuffer[5] != 0 && !v10 )
        idStr::Append((idStr *)this, text: "again");
    }
  }
  return this;
}


// ========================================================================
// __unwind$501438_0
// EA  : 0x82E04B80
// RVA : 0x00E04B80
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501438_0()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 212));
  }
}


// ========================================================================
// __unwind$501441_0
// EA  : 0x82E04BC4
// RVA : 0x00E04BC4
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501441_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?GetReloadNodeName@idHands@@QAA?AVidStr@@_N0@Z
// EA  : 0x82E04BF8
// RVA : 0x00E04BF8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::GetReloadNodeName(idHands *this, idHands *result, bool secondary, bool leftHand)
{
  BOOL v8; // r26
  char v9; // r8
  idWeapon **p_rightItem; // r11
  idWeapon *v11; // r3
  _DWORD *v12; // r30
  int v13; // r11
  int v14; // r11
  int v15; // r11
  char *v16; // r4

  v8 = leftHand;
  idStr::idStr((idStr *)this, text: "reload");
  v9 = _cntlzw(leftHand);
  if ( (v9 & 0x20) != 0 )
  {
    if ( (v9 & 0x20) == 0 )
      return this;
    p_rightItem = (idWeapon **)&result->rightItem;
  }
  else
  {
    p_rightItem = (idWeapon **)&result->leftItem;
  }
  if ( p_rightItem != nullptr )
  {
    v11 = idWeapon::CastTo(c: p_rightItem[363]);
    v12 = &v11->__vftable;
    if ( v11 != nullptr )
    {
      idHands::UpdateWeaponCondition(this: result, weapon: v11);
      v13 = v12[12];
      if ( v13 != 0
        || (!secondary ? (v14 = v12[11]) : (v14 = v12[13]),
            v14 != 0 && (!secondary ? (v15 = v12[11]) : (v15 = v12[13]), (v13 = *(_DWORD *)(v15 + 12)) != 0)) )
      {
        idStr::Append((idStr *)this, text: (const idStr *)(v13 + 580));
      }
      if ( result->currentDualWieldState == SET_DUALWIELD_ON || (*((_BYTE *)result + 7912) & 4) != 0 )
      {
        if ( v8 )
          v16 = "dwleft";
        else
          v16 = "dwright";
        idStr::Append((idStr *)this, text: v16);
      }
    }
  }
  return this;
}


// ========================================================================
// __unwind$501539
// EA  : 0x82E04D34
// RVA : 0x00E04D34
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501539()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 144;
  if ( (*(_DWORD *)(v0 - 144 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 164));
  }
}


// ========================================================================
// ?GetAmmoChangeNodeName@idHands@@QAA?AVidStr@@_N0@Z
// EA  : 0x82E04D80
// RVA : 0x00E04D80
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::GetAmmoChangeNodeName(idHands *this, idHands *result, bool secondary, bool leftHand)
{
  idWeapon *v7; // r3
  idWeapon *v8; // r30
  const idDeclAmmo *nextAmmo; // r11
  idAmmoItem *ammoClip; // r11
  idAmmoItem *ammoClipSecondary; // r11
  idAmmoItem *v12; // r11
  idAmmoItem *v13; // r11
  const idDeclInventory *decl; // r11
  const idStr *v15; // r3
  idStr v17[2]; // [sp+60h] [-50h] BYREF

  idHands::GetReloadNodeName(this, result, secondary, leftHand);
  if ( result != (idHands *)-2996 )
  {
    v7 = idWeapon::CastTo(c: (idWeapon *)result->rightItem.item);
    v8 = v7;
    if ( v7 != nullptr && (*((_BYTE *)v7 + 452) & 4) == 0 )
    {
      nextAmmo = v7->nextAmmo;
      if ( nextAmmo != nullptr
        || (!secondary ? (ammoClip = v7->ammoClip) : (ammoClip = v7->ammoClipSecondary),
            ammoClip != nullptr
         && (!secondary ? (ammoClipSecondary = v7->ammoClip) : (ammoClipSecondary = v7->ammoClipSecondary),
             (nextAmmo = (const idDeclAmmo *)ammoClipSecondary->decl) != nullptr)) )
      {
        if ( nextAmmo->ammoChangeAnimOverride.len != 0 )
          idStr::operator=((idStr *)this, text: &nextAmmo->ammoChangeAnimOverride);
      }
      if ( secondary )
        v12 = v8->ammoClipSecondary;
      else
        v12 = v8->ammoClip;
      if ( v12 != nullptr )
      {
        if ( secondary )
          v13 = v8->ammoClipSecondary;
        else
          v13 = v8->ammoClip;
        decl = v13->decl;
        if ( decl != nullptr )
        {
          v15 = operator+(result: v17, a: (const idStr *)&decl[1].dualWieldItemDecl, b: (const idStr *)this);
          idStr::operator=((idStr *)this, text: v15);
          idStr::FreeData(this: v17);
        }
      }
    }
  }
  return this;
}


// ========================================================================
// __unwind$501624
// EA  : 0x82E04EB8
// RVA : 0x00E04EB8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501624()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 176;
  if ( (*(_DWORD *)(v0 - 176 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 196));
  }
}


// ========================================================================
// __unwind$501627
// EA  : 0x82E04EFC
// RVA : 0x00E04EFC
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501627()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?AnimEvent_Melee@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82E04F30
// RVA : 0x00E04F30
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_Melee(idHands *this, eventVoid *result, const idMD6Anim *anim)
{
  const char *str; // r30
  int PlayerGameTime; // r3
  idWeapon *Equipped; // r3
  idWeapon *v9; // r3
  idWeapon *v10; // r30
  int v11; // r11
  idFinishFireResults *v12; // r11
  int i; // ctr
  int v14; // r4
  idVec3 v16; // [sp+50h] [-A70h] BYREF
  idMat3 v17; // [sp+60h] [-A60h] BYREF
  idFireParms v18; // [sp+90h] [-A30h] BYREF
  idFinishFireResults v19; // [sp+130h] [-990h] BYREF
  idTestFireResults v20; // [sp+180h] [-940h] BYREF

  if ( common->IsServer(this: common) )
  {
    if ( hands_debugfc.valueInteger > 0 )
    {
      if ( anim != nullptr )
        str = anim->name.str;
      else
        str = "<NULL>";
      PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
      idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_Melee - '^2%s^7'\n", PlayerGameTime, str);
    }
    Equipped = (idWeapon *)idPresentablePlayer::GetEquipped(
                             this: *(idPresentablePlayer **)&result[12],
                             slot: EQUIP_RIGHT_HAND);
    v9 = idWeapon::CastTo(c: Equipped);
    v10 = v9;
    if ( v9 != nullptr && LODWORD(v9->decl[2].droppedControllerShake.highMagnitude) != 0 )
    {
      idPresentablePlayer::GetFireTrajectory(this: *(idPresentablePlayer **)&result[12], firePos: &v16, fireAxis: &v17);
      idPresentablePlayer::WeaponFireFeedback(
        this: *(idPresentablePlayer **)&result[12],
        weapon: v10,
        projDecl: (const idDeclProjectile *)LODWORD(v10->decl[2].droppedControllerShake.highMagnitude));
      idFireParms::idFireParms(this: &v18);
      v11 = *(_DWORD *)&result[12];
      if ( v11 != 0 )
        v18.attacker.spawnId = *(_DWORD *)(v11 + 1100);
      else
        v18.attacker.spawnId = 0;
      v18.target.spawnId = 0;
      v18.wepDef = (const idDeclWeapon *)v10->decl;
      v18.start.x = v16.x;
      v18.start.y = v16.y;
      v18.start.z = v16.z;
      v18.fireAxis.mat[0].x = v17.mat[0].x;
      v18.fireAxis.mat[0].y = v17.mat[0].y;
      v18.fireAxis.mat[0].z = v17.mat[0].z;
      v18.fireAxis.mat[1].x = v17.mat[1].x;
      v18.fireAxis.mat[1].y = v17.mat[1].y;
      v18.fireAxis.mat[1].z = v17.mat[1].z;
      v18.fireAxis.mat[2].x = v17.mat[2].x;
      v18.fireAxis.mat[2].y = v17.mat[2].y;
      v18.fireAxis.mat[2].z = v17.mat[2].z;
      v18.projDef = (const idDeclProjectile *)LODWORD(v10->decl[2].droppedControllerShake.highMagnitude);
      *((_BYTE *)&v18 + 128) = *((_BYTE *)&v18 + 128) & 0x2F | 0x10;
      *((_BYTE *)&v18 + 129) &= ~0x20u;
      memset(&v20, 0, sizeof(v20));
      v12 = &v19;
      v19.numProjectiles = 0;
      for ( i = 16; i != 0; --i )
      {
        v12 = (idFinishFireResults *)((char *)v12 + 4);
        v12->numProjectiles = 0;
      }
      idClientGame::TestFire(this: clientGame, fp: &v18, tfr: &v20);
      if ( idGameLocal::FinishFire(this: gameLocal, fp: &v18, tfr: &v20, ffr: &v19) )
        idView::SetControllerShake(
          this: (idView *)(*(_DWORD *)&result[12] + 16224),
          highMagnitude: 0.5,
          highDuration: v14,
          lowMagnitude: 1.0,
          lowDuration: 250);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v18.targetList);
    }
  }
  return this;
}


// ========================================================================
// __unwind$501733
// EA  : 0x82E05188
// RVA : 0x00E05188
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501733()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2752 + 144));
}


// ========================================================================
// ?Cmd_tw_save_f@idHands@@SAXABVidCmdArgs@@@Z
// EA  : 0x82E051B8
// RVA : 0x00E051B8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idHands::Cmd_tw_save_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v2; // r4
  idFile *v3; // r29
  __int64 v4; // r6 OVERLAPPED
  __int64 v5; // r10
  __int64 v6; // r8
  va *v7; // r3
  __int128 v8; // r6
  __int64 v9; // r10
  __int64 v10; // r8
  va *v11; // r3
  __int64 v12; // r10
  __int64 v13; // r8
  __int128 v14; // r6
  va *v15; // r3
  __int64 v16; // r8
  __int128 v17; // r6
  __int64 v18; // r10
  va *v19; // r3
  __int128 v20; // r6
  __int64 v21; // r10
  __int64 v22; // r8
  va *v23; // r3
  __int64 v24; // r10
  __int64 v25; // r8
  __int128 v26; // r6
  va *v27; // r3
  __int64 v28; // r8
  __int128 v29; // r6
  __int64 v30; // r10
  va *v31; // r3
  __int64 v32; // r10
  __int64 v33; // r8
  __int64 v34; // r6
  idPlayer *DebugPlayer; // r3
  idPresentable *presentable; // r3
  int v37; // r3
  int v38; // r11
  va *v39; // r3
  int v40; // [sp+8h] [-10B8h]
  int v41; // [sp+8h] [-10B8h]
  int v42; // [sp+8h] [-10B8h]
  int v43; // [sp+8h] [-10B8h]
  int v44; // [sp+8h] [-10B8h]
  int v45; // [sp+8h] [-10B8h]
  int v46; // [sp+8h] [-10B8h]
  int v47; // [sp+8h] [-10B8h]
  int v48; // [sp+Ch] [-10B4h]
  int v49; // [sp+Ch] [-10B4h]
  int v50; // [sp+Ch] [-10B4h]
  int v51; // [sp+Ch] [-10B4h]
  int v52; // [sp+Ch] [-10B4h]
  int v53; // [sp+Ch] [-10B4h]
  int v54; // [sp+Ch] [-10B4h]
  int v55; // [sp+Ch] [-10B4h]
  int v56; // [sp+10h] [-10B0h]
  int v57; // [sp+10h] [-10B0h]
  int v58; // [sp+10h] [-10B0h]
  int v59; // [sp+10h] [-10B0h]
  int v60; // [sp+10h] [-10B0h]
  int v61; // [sp+10h] [-10B0h]
  int v62; // [sp+10h] [-10B0h]
  int v63; // [sp+10h] [-10B0h]
  int v64; // [sp+14h] [-10ACh]
  int v65; // [sp+14h] [-10ACh]
  int v66; // [sp+14h] [-10ACh]
  int v67; // [sp+14h] [-10ACh]
  int v68; // [sp+14h] [-10ACh]
  int v69; // [sp+14h] [-10ACh]
  int v70; // [sp+14h] [-10ACh]
  int v71; // [sp+14h] [-10ACh]
  int v72; // [sp+18h] [-10A8h]
  int v73; // [sp+18h] [-10A8h]
  int v74; // [sp+18h] [-10A8h]
  int v75; // [sp+18h] [-10A8h]
  int v76; // [sp+18h] [-10A8h]
  int v77; // [sp+18h] [-10A8h]
  int v78; // [sp+18h] [-10A8h]
  int v79; // [sp+18h] [-10A8h]
  int v80; // [sp+1Ch] [-10A4h]
  int v81; // [sp+1Ch] [-10A4h]
  int v82; // [sp+1Ch] [-10A4h]
  int v83; // [sp+1Ch] [-10A4h]
  int v84; // [sp+1Ch] [-10A4h]
  int v85; // [sp+1Ch] [-10A4h]
  int v86; // [sp+1Ch] [-10A4h]
  int v87; // [sp+1Ch] [-10A4h]
  idStr v88; // [sp+50h] [-1070h] BYREF
  int v89; // [sp+70h] [-1050h]
  idStr v90; // [sp+80h] [-1040h] BYREF
  va v91; // [sp+A0h] [-1020h] BYREF

  argc = args->argc;
  v89 = args->argc;
  if ( v89 == 2 )
  {
    if ( argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    idStr::idStr(this: &v90, text: v2);
    idStr::SetFileExtension(this: &v90, extension: ".cfg");
    v3 = fileSystem->OpenFileWrite(this: fileSystem, a2: v90.data, a3: 2);
    if ( v3 != nullptr )
    {
      LODWORD(v5) = v88.baseBuffer;
      v88.len = 0;
      v88.allocedAndFlag = 20;
      v88.data = v88.baseBuffer;
      v88.baseBuffer[0] = 0;
      HIDWORD(v5) = &pb_ss_UpdateAfterPhysics.name;
      LODWORD(v6) = &unk_82340000;
      HIDWORD(v6) = &tw_offsetX;
      *(double *)((char *)&v4 + 4) = tw_offsetX.valueFloat;
      v7 = va::va(
             this: &v91,
             fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(tw_offsetX.valueFloat)),
             a3: v4,
             a4: v6,
             a5: v5,
             a6: v40,
             a7: v48,
             a8: v56,
             a9: v64,
             a10: v72,
             a11: v80);
      idStr::Append(this: &v88, text: v7);
      LODWORD(v8) = &pb_ss_UpdateAfterPhysics.name;
      *(double *)((char *)&v8 + 4) = tw_offsetY.valueFloat;
      v11 = va::va(
              this: &v91,
              fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(tw_offsetY.valueFloat)),
              a3: v8,
              a4: v10,
              a5: v9,
              a6: v41,
              a7: v49,
              a8: v57,
              a9: v65,
              a10: v73,
              a11: v81);
      idStr::Append(this: &v88, text: v11);
      LODWORD(v12) = &pb_ss_UpdateAfterPhysics.name;
      HIDWORD(v12) = &unk_82340000;
      LODWORD(v13) = &tw_offsetZ;
      *(double *)((char *)&v14 + 4) = tw_offsetZ.valueFloat;
      v15 = va::va(
              this: &v91,
              fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(tw_offsetZ.valueFloat)),
              a3: v14,
              a4: v13,
              a5: v12,
              a6: v42,
              a7: v50,
              a8: v58,
              a9: v66,
              a10: v74,
              a11: v82);
      idStr::Append(this: &v88, text: v15);
      HIDWORD(v16) = &pb_ss_UpdateAfterPhysics.name;
      LODWORD(v17) = &unk_82340000;
      *(double *)((char *)&v17 + 4) = tw_pitch.valueFloat;
      v19 = va::va(
              this: &v91,
              fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(tw_pitch.valueFloat)),
              a3: v17,
              a4: v16,
              a5: v18,
              a6: v43,
              a7: v51,
              a8: v59,
              a9: v67,
              a10: v75,
              a11: v83);
      idStr::Append(this: &v88, text: v19);
      *(double *)((char *)&v20 + 4) = tw_yaw.valueFloat;
      v23 = va::va(
              this: &v91,
              fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(tw_yaw.valueFloat)),
              a3: v20,
              a4: v22,
              a5: v21,
              a6: v44,
              a7: v52,
              a8: v60,
              a9: v68,
              a10: v76,
              a11: v84);
      idStr::Append(this: &v88, text: v23);
      LODWORD(v24) = &pb_ss_UpdateAfterPhysics.name;
      HIDWORD(v24) = &unk_82340000;
      LODWORD(v25) = &tw_roll;
      *(double *)((char *)&v26 + 4) = tw_roll.valueFloat;
      v27 = va::va(
              this: &v91,
              fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(tw_roll.valueFloat)),
              a3: v26,
              a4: v25,
              a5: v24,
              a6: v45,
              a7: v53,
              a8: v61,
              a9: v69,
              a10: v77,
              a11: v85);
      idStr::Append(this: &v88, text: v27);
      HIDWORD(v28) = &pb_ss_UpdateAfterPhysics.name;
      LODWORD(v29) = &unk_82340000;
      *(double *)((char *)&v29 + 4) = tw_fovScale.valueFloat;
      v31 = va::va(
              this: &v91,
              fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(tw_fovScale.valueFloat)),
              a3: v29,
              a4: v28,
              a5: v30,
              a6: v46,
              a7: v54,
              a8: v62,
              a9: v70,
              a10: v78,
              a11: v86);
      idStr::Append(this: &v88, text: v31);
      DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
      if ( DebugPlayer == nullptr
        || ((presentable = DebugPlayer->presentable) == nullptr
          ? (v37 = 0)
          : (v37 = (int)presentable->GetPlayerInterface_2(this: presentable)),
            v37 == -37616) )
      {
        v38 = 0;
      }
      else
      {
        v38 = *(_DWORD *)(v37 + 40592);
      }
      if ( v38 != 0 )
      {
        LODWORD(v32) = &unk_82340000;
        HIDWORD(v34) = *(_DWORD *)(v38 + 16);
        v39 = va::va(
                this: &v91,
                fmt: "testWeapon %s\n",
                a3: v34,
                a4: v33,
                a5: v32,
                a6: v47,
                a7: v55,
                a8: v63,
                a9: v71,
                a10: v79,
                a11: v87);
        idStr::Append(this: &v88, text: v39);
      }
      v3->Write(this: v3, a2: v88.data, a3: v88.len);
      ((void (__fastcall *)(idFile *, int))v3->dtr_idFile)(a1: v3, a2: 1);
      idLib::Printf(fmt: "Saved as '%s'.\n", v90.data);
      idStr::FreeData(this: &v88);
    }
    else
    {
      idLib::Printf(fmt: "Failed to open file '%s'\n", v90.data);
    }
    idStr::FreeData(this: &v90);
  }
  else
  {
    idLib::Printf(fmt: "USAGE: tw_save [config name]\n");
    idLib::Printf(fmt: "Writes out the current test weapon parameters to a config file.\n");
  }
}


// ========================================================================
// __unwind$501945
// EA  : 0x82E054AC
// RVA : 0x00E054AC
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501945()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 128));
}


// ========================================================================
// __unwind$501946
// EA  : 0x82E054D4
// RVA : 0x00E054D4
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_501946()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 80));
}


// ========================================================================
// ?HandsEquipItem@idHands@@QAAXPAVidInventoryItem@@@Z
// EA  : 0x82E05508
// RVA : 0x00E05508
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::HandsEquipItem(idHands *this, idWeapon *item)
{
  idDeclAnimWebNode *v4; // r28
  const idDeclInventory *decl; // r26
  idWeapon *v6; // r3
  idWeapon *v7; // r29
  int value; // r11
  const char *SubWebName; // r3
  idAmmoItem *ammoClip; // r11
  const idDeclInventory *v11; // r9
  int entityNumber; // r6
  int v13; // r6
  _DWORD v14[4]; // [sp+50h] [-90h] BYREF
  idClientGameMsg v15; // [sp+60h] [-80h] BYREF
  const idDeclInventory *v16; // [sp+68h] [-78h]
  const idDeclInventory *v17; // [sp+6Ch] [-74h]
  int v18; // [sp+70h] [-70h]
  idStr v19[3]; // [sp+80h] [-60h] BYREF

  if ( item == nullptr )
  {
    idLib::Printf(fmt: "%s - invalid item\n", "idHands::HandsEquipItem");
    return;
  }
  v4 = nullptr;
  decl = nullptr;
  v6 = idWeapon::CastTo(c: item);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v19[0].len = 0;
    v19[0].baseBuffer[0] = 0;
    v19[0].allocedAndFlag = 20;
    v19[0].data = v19[0].baseBuffer;
    idHands::GetWeaponSubWebName(this, weapon: v6, name: v19, secondary: false);
    value = this->web.curNodeIndex.value;
    if ( value != -1 )
      v4 = this->web.decl->nodes.list[value];
    SubWebName = idDeclAnimWeb::GetSubWebName(
                   this: this->web.decl,
                   index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v4->subWebIndex.value);
    if ( idStr::Cmp(s1: v19[0].data, s2: SubWebName) != 0 && this->lastSwimDepthState == SWIMDEPTH_STATE_NONE )
    {
      idStr::FreeData(this: v19);
      return;
    }
    ammoClip = v7->ammoClip;
    if ( ammoClip != nullptr )
    {
      decl = ammoClip->decl;
      v14[1] = v7->ammoClip;
    }
    idStr::FreeData(this: v19);
  }
  v11 = item->decl;
  entityNumber = this->owner->entityNumber;
  v15.peerMask = -1;
  v15.__vftable = (idClientGameMsg_vtbl *)&idClientGameMsg_HandsEquip::`vftable';
  v16 = v11;
  v17 = decl;
  v18 = entityNumber;
  idClientGame::HandleReliableGameMsg(this: clientGame, gameMsg: &v15);
  idPresentablePlayer::EquipItem(this: this->owner, item);
  idHands::ShowRRL(this, usePending: false, equipingWeapon: nullptr);
  if ( v7 == nullptr || (v13 = 1, !v7->wasDualWielding) )
    v13 = 2;
  idHands::AnimEvent_SetDualWieldWeapon(this: (idHands *)v14, result: (eventVoid *)this, anim: nullptr, setType: v13);
}


// ========================================================================
// __unwind$502138
// EA  : 0x82E05688
// RVA : 0x00E05688
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502138()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// __unwind$502139
// EA  : 0x82E056B0
// RVA : 0x00E056B0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502139()
{
  int v0; // r12

  idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(this: (idClientGameMsg_VehicleWeaponChange *)(v0 - 224 + 96));
}


// ========================================================================
// ??0idHands@@QAA@XZ
// EA  : 0x82E05728
// RVA : 0x00E05728
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::idHands(idHands *this)
{
  float *p_z; // r10
  float *p_y; // r11
  int v4; // ctr
  char v5; // r9
  idClientGame *v6; // r3

  idEventReceiver::idEventReceiver(this);
  this->owner = nullptr;
  this->__vftable = (idHands_vtbl *)&idHands::`vftable';
  idAnimStack::idAnimStack(this: &this->animStack);
  this->presentable = nullptr;
  idAnimWebHands::idAnimWebHands(this: &this->web);
  idAnimWebHands::idAnimWebHands(this: &this->secondaryWeb);
  this->testModel = nullptr;
  this->hiddenReasons = 0;
  this->usedToHaveHideReasons = 0;
  this->disabled = false;
  this->shouldDisable = false;
  this->shouldShowAfterUpdate = false;
  this->unlinked = true;
  this->pickupSlot = EQUIP_NONE;
  idHandsItem::idHandsItem(this: &this->rightItem, slot: EQUIP_RIGHT_HAND, tagIndex: HANDSTAG_RIGHT);
  idHandsItem::idHandsItem(this: &this->leftItem, slot: EQUIP_LEFT_HAND, tagIndex: HANDSTAG_LEFT);
  this->throwItem = nullptr;
  this->modelAngles.pitch = 0.0;
  this->modelAngles.yaw = 0.0;
  this->modelAngles.roll = 0.0;
  this->modelScale = 1.0;
  this->modelOffset.x = 0.0;
  this->modelOffset.y = 0.0;
  this->modelOffset.z = 0.0;
  idAnimEventHandler::idAnimEventHandler(this: &this->animEventHandler);
  this->lastFriendlyTime = 0;
  p_z = &this->extraWorldTranslation.z;
  p_y = &mat2_identity.mat[1].y;
  this->lockOnPosition = vec3_origin;
  v4 = 9;
  this->extraWorldTranslation = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v4;
  }
  while ( v4 != 0 );
  this->isReloading = false;
  this->isWeaponBringUp = false;
  this->isInReloadOut = false;
  this->isInMeleeSwing = false;
  this->isInterruptableTransition = false;
  this->isChainFiring = false;
  this->isChargeFiring = false;
  this->isLaserFiring = false;
  this->isZooming = false;
  this->isInEndSprint = false;
  this->isHandsSprinting = false;
  this->isInAccentIdle = false;
  this->isInTown = false;
  this->isChangingAmmo = false;
  this->cookingProjectile.spawnId.value = 0x1FFF;
  this->cookingProjectileDecl = nullptr;
  this->canInteruptCooking = false;
  this->playingWarningSound = false;
  this->cookingStartTime = 0;
  this->cookingDetonationTime = 0;
  idMeleeTrace::idMeleeTrace(this: &this->handsMeleeTrace);
  idHands::idHandsAction::idHandsAction(this: &this->pendingAction);
  idHands::idHandsAction::idHandsAction(this: &this->lingeringAction);
  this->previousProjectile.spawnId.value = 0x1FFF;
  v5 = *((_BYTE *)this + 7912);
  this->aimPointBlend = 0.0;
  this->aimPointDepthBlend = 0.5;
  this->meleeComboCount = 0;
  this->lastMeleeHitTime = -10000;
  this->lastAttackTime = -10000;
  this->lastWeaponUsedTime = -10000;
  this->lastOnLadderTime = -10000;
  *((_BYTE *)this + 7912) = v5 & 3;
  this->currentVariationIndex = 0;
  this->pendingVariationIndex = -1;
  this->weaponAnimVar = 0;
  this->weaponRelaxed = false;
  this->weaponRelaxedToggler = false;
  this->lastAttackVariation = 0;
  this->lastAttackVariationDWLeft = 0;
  this->lastAimUpdateTime = 0;
  this->alternateFiringNode = false;
  this->alternateLeftFiringNode = false;
  this->currentDualWieldState = SET_DUALWIELD_OFF;
  idHands::idHandsAction::idHandsAction(this: &this->dualWieldLeftHandPendingAction);
  this->pendingWeaponToEquip = nullptr;
  this->currentSwimState = HS_IDLE;
  this->lastSwimDepthState = SWIMDEPTH_STATE_NONE;
  this->handBubblesActivated = false;
  this->handsTCAngles.pitch = 0.0;
  this->handsTCAngles.yaw = 0.0;
  this->handsTCAngles.roll = 0.0;
  this->handsTCAnglesBlendState = HANDSTCBLENDSTATE_OUT_FULL;
  this->handsTCAnglesBlend = 0.0;
  this->modelAxis.mat[0].x = mat3_identity.mat[0].x;
  this->modelAxis.mat[0].y = mat3_identity.mat[0].y;
  this->modelAxis.mat[0].z = mat3_identity.mat[0].z;
  v6 = clientGame;
  this->modelAxis.mat[1] = mat3_identity.mat[1];
  this->modelAxis.mat[2] = mat3_identity.mat[2];
  this->lastActionTime = idClientGame::GetPlayerGameTime(this: v6);
  return this;
}


// ========================================================================
// __unwind$502495
// EA  : 0x82E05A04
// RVA : 0x00E05A04
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502495()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$502496
// EA  : 0x82E05A2C
// RVA : 0x00E05A2C
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502496()
{
  int v0; // r12

  idAnimStack::~idAnimStack(this: (idAnimStack *)(*(_DWORD *)(v0 - 144 + 164) + 16));
}


// ========================================================================
// __unwind$502497
// EA  : 0x82E05A58
// RVA : 0x00E05A58
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502497()
{
  int v0; // r12

  idAnimWebHands::~idAnimWebHands(this: (idAnimWebHands *)(*(_DWORD *)(v0 - 144 + 164) + 1592));
}


// ========================================================================
// __unwind$502498
// EA  : 0x82E05A84
// RVA : 0x00E05A84
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502498()
{
  int v0; // r12

  idAnimWebHands::~idAnimWebHands(this: (idAnimWebHands *)(*(_DWORD *)(v0 - 144 + 164) + 2284));
}


// ========================================================================
// __unwind$502499
// EA  : 0x82E05AB0
// RVA : 0x00E05AB0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502499()
{
  int v0; // r12

  idHandsItem::~idHandsItem(this: (idHandsItem *)(*(_DWORD *)(v0 - 144 + 164) + 2996));
}


// ========================================================================
// __unwind$502500
// EA  : 0x82E05ADC
// RVA : 0x00E05ADC
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502500()
{
  int v0; // r12

  idHandsItem::~idHandsItem(this: (idHandsItem *)(*(_DWORD *)(v0 - 144 + 164) + 4532));
}


// ========================================================================
// __unwind$502501
// EA  : 0x82E05B08
// RVA : 0x00E05B08
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502501()
{
  int v0; // r12

  idAnimEventHandler::~idAnimEventHandler(this: (idAnimEventHandler *)(*(_DWORD *)(v0 - 144 + 164) + 6136));
}


// ========================================================================
// __unwind$502502
// EA  : 0x82E05B34
// RVA : 0x00E05B34
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502502()
{
  int v0; // r12

  idMeleeTrace::~idMeleeTrace(this: (idMeleeTrace *)(*(_DWORD *)(v0 - 144 + 164) + 7684));
}


// ========================================================================
// __unwind$502503
// EA  : 0x82E05B60
// RVA : 0x00E05B60
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502503()
{
  int v0; // r12

  idHudPickupInfo::~idHudPickupInfo(this: (idHudPickupInfo *)(*(_DWORD *)(v0 - 144 + 164) + 7784));
}


// ========================================================================
// __unwind$502504
// EA  : 0x82E05B8C
// RVA : 0x00E05B8C
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502504()
{
  int v0; // r12

  idHudPickupInfo::~idHudPickupInfo(this: (idHudPickupInfo *)(*(_DWORD *)(v0 - 144 + 164) + 7836));
}


// ========================================================================
// __unwind$502505
// EA  : 0x82E05BB8
// RVA : 0x00E05BB8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502505()
{
  int v0; // r12

  idHudPickupInfo::~idHudPickupInfo(this: (idHudPickupInfo *)(*(_DWORD *)(v0 - 144 + 164) + 7960));
}


// ========================================================================
// ?SetEquipState@idHands@@IAAXPBD@Z
// EA  : 0x82E05C50
// RVA : 0x00E05C50
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SetEquipState(idHands *this, char *subWebName)
{
  int GameMs; // r3
  bool isSecondary; // r6
  idWeapon *v6; // r28
  BOOL useIntroBringUp; // r4
  __int64 v8; // r3
  idWeapon *pendingWeaponToEquip; // r11
  char *data; // r6
  const char *v11; // r7
  double v12; // fp13
  __int64 v13; // r4
  idStr v14[3]; // [sp+60h] [-60h] BYREF

  v14[0].len = 0;
  this->isWeaponBringUp = true;
  v14[0].allocedAndFlag = 20;
  v14[0].data = v14[0].baseBuffer;
  v14[0].baseBuffer[0] = 0;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  isSecondary = this->pendingAction.isSecondary;
  this->lastWeaponUsedTime = GameMs + 500;
  idHands::GetWeaponSubWebName(this, weapon: this->pendingAction.weapon, name: v14, secondary: isSecondary);
  v6 = this->owner->GetEquippedWeapon(this: this->owner, a2: 2);
  useIntroBringUp = this->pendingAction.useIntroBringUp;
  LODWORD(v8) = this->currentVariationIndex;
  this->web.previousVariationIndex = (float)v8;
  if ( useIntroBringUp )
  {
    pendingWeaponToEquip = this->pendingWeaponToEquip;
    if ( pendingWeaponToEquip != nullptr )
    {
      data = v14[0].data;
      v11 = "intro";
      HIDWORD(v13) = &this->web;
      LODWORD(v13) = pendingWeaponToEquip->decl[3].equipSlot;
      v12 = (double)v13;
      LODWORD(v13) = v14[0].data;
      this->web.attackVariation = v12;
LABEL_11:
      idAnimator_AnimWeb::ChangeStateVia(
        this: (idAnimator_AnimWeb *)HIDWORD(v13),
        subWebName: (const char *)v13,
        stateName: "idle",
        viaSubWebName: data,
        viaStateName: v11,
        interruptPath_: INTR_PATH_YES,
        interruptBlend_: INTR_BLEND_NO,
        blendEventMask_: 0);
      goto LABEL_12;
    }
  }
  if ( idHands::GetState(this, animWeb: &this->web) != 7
    && (v6 == nullptr || v6->decl[1].parent != nullptr || !this->weaponRelaxedToggler)
    || idStr::Cmp(s1: subWebName, s2: v14[0].data) == 0 )
  {
    LODWORD(v13) = v14[0].data;
    v11 = "bringdown";
    data = subWebName;
    HIDWORD(v13) = &this->web;
    goto LABEL_11;
  }
  idAnimator_AnimWeb::ChangeState(
    this: &this->web,
    subWebName: v14[0].data,
    stateName: "idle",
    interruptPath_: INTR_PATH_YES,
    interruptBlend_: INTR_BLEND_NO,
    blendEventMask_: 0);
LABEL_12:
  this->pendingAction.action = HANDSACTION_NONE;
  this->pendingAction.ammoDecl = nullptr;
  this->pendingAction.weapon = nullptr;
  this->pendingAction.throwable = nullptr;
  this->pendingAction.useIntroBringUp = false;
  this->pendingAction.isSecondary = false;
  this->pendingAction.leftHand = false;
  idStr::Clear(this: &this->pendingAction.extraNodeInfo);
  this->lastActionTime = idClientGame::GetPlayerGameTime(this: clientGame);
  idStr::FreeData(this: v14);
}


// ========================================================================
// __unwind$502713
// EA  : 0x82E05E34
// RVA : 0x00E05E34
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502713()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?DropThrowable@idHands@@QAAXXZ
// EA  : 0x82E05E68
// RVA : 0x00E05E68
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::DropThrowable(idHands *this)
{
  const idDeclProjectile *projectileDecl; // r25
  idPresentablePlayer *owner; // r10
  idFinishFireResults *v4; // r11
  int i; // ctr
  idProjectile *CookingProjectile; // r3
  idSoundShader *warningSound; // r3
  int v8; // r29
  int v9; // r29
  idPresentablePtr<idPresentable> *projectiles; // r28
  idPresentableProjectile *v11; // r3
  const idDeclThrowable *v12; // r29
  idJobManager *v13; // r3
  idInventoryItem *JobByDecl; // r4
  const idDeclThrowable *throwItem; // [sp+50h] [-AA0h]
  idVec3 v16; // [sp+58h] [-A98h] BYREF
  idFireParms v17; // [sp+70h] [-A80h] BYREF
  idFinishFireResults v18; // [sp+110h] [-9E0h] BYREF
  idMat3 v19; // [sp+160h] [-990h] BYREF
  idTestFireResults v20; // [sp+190h] [-960h] BYREF

  if ( common->IsServer(this: common) )
  {
    throwItem = this->throwItem;
    if ( throwItem != nullptr )
    {
      projectileDecl = throwItem->projectileDecl;
      idHandsItem::GetMuzzlePosition(this: &this->leftItem, hands: this, origin: &v16, axis: &v19);
      idFireParms::idFireParms(this: &v17);
      idFireParms::Clear(this: &v17);
      owner = this->owner;
      if ( owner != nullptr )
        v17.attacker.spawnId = owner->spawnId;
      else
        v17.attacker.spawnId = 0;
      v17.target.spawnId = 0;
      v17.start.x = v16.x;
      v17.wepDef = nullptr;
      v17.start.y = v16.y;
      v17.start.z = v16.z;
      v17.fireAxis.mat[0].x = owner->firstPersonViewAxis.mat[0].x;
      v17.fireAxis.mat[0].y = owner->firstPersonViewAxis.mat[0].y;
      v17.fireAxis.mat[0].z = owner->firstPersonViewAxis.mat[0].z;
      v17.fireAxis.mat[1].x = owner->firstPersonViewAxis.mat[1].x;
      v17.fireAxis.mat[1].y = owner->firstPersonViewAxis.mat[1].y;
      v17.fireAxis.mat[1].z = owner->firstPersonViewAxis.mat[1].z;
      v17.fireAxis.mat[2].x = owner->firstPersonViewAxis.mat[2].x;
      v17.fireAxis.mat[2].y = owner->firstPersonViewAxis.mat[2].y;
      v17.fireAxis.mat[2].z = owner->firstPersonViewAxis.mat[2].z;
      *((_BYTE *)&v17 + 128) = *((_BYTE *)&v17 + 128) & 0x2B | 0x14;
      v17.projDef = projectileDecl;
      v17.targetPos.x = owner->focusTracker.focusTrace.tr.endpos.x;
      v17.targetPos.y = owner->focusTracker.focusTrace.tr.endpos.y;
      v17.targetPos.z = owner->focusTracker.focusTrace.tr.endpos.z;
      memset(&v20, 0, sizeof(v20));
      v17.startSpeed = 0.0;
      v4 = &v18;
      v18.numProjectiles = 0;
      for ( i = 16; i != 0; --i )
      {
        v4 = (idFinishFireResults *)((char *)v4 + 4);
        v4->numProjectiles = 0;
      }
      if ( this->cookingStartTime > 0 )
      {
        v17.startTime = this->cookingStartTime;
        CookingProjectile = idHands::GetCookingProjectile(this);
        if ( CookingProjectile != nullptr )
          v17.projectile.spawnId.value = (gameLocal->spawnIds.ptr[CookingProjectile->entityNumber] << 13)
                                       | CookingProjectile->entityNumber;
        else
          v17.projectile.spawnId.value = 0x1FFF;
        this->cookingProjectile.spawnId.value = 0x1FFF;
        this->cookingProjectileDecl = nullptr;
      }
      idClientGame::TestFire(this: clientGame, fp: &v17, tfr: &v20);
      idGameLocal::FinishFire(this: gameLocal, fp: &v17, tfr: &v20, ffr: &v18);
      if ( this->cookingStartTime > 0 )
      {
        warningSound = projectileDecl->notHitscanInfo.grenadeInfo.warningSound;
        if ( warningSound != nullptr )
        {
          v8 = this->cookingDetonationTime - idSoundShader::GetMaxLength(this: warningSound) + this->cookingStartTime;
          if ( idPresentablePlayer::GetPlayerGameTime(this: this->owner) >= v8 )
          {
            v9 = 0;
            if ( v18.numProjectiles > 0 )
            {
              projectiles = (idPresentablePtr<idPresentable> *)v18.projectiles;
              do
              {
                ++v9;
                HIBYTE(idPresentablePtr<idPresentableProjectile>::operator->(this: projectiles++)[1].axes[0].mat[1].z) = 1;
              }
              while ( v9 < v18.numProjectiles );
            }
          }
        }
      }
      idHandsItem::Clear(this: &this->leftItem);
      idPresentablePlayer::WeaponFireFeedback(this: this->owner, weapon: nullptr, projDecl: projectileDecl);
      if ( projectileDecl->notHitscanInfo.allowOnlyOne
        && v18.numProjectiles > 0
        && idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)v18.projectiles) )
      {
        v11 = (idPresentableProjectile *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)v18.projectiles);
        idPresentablePlayer::TrackUniqueProjectile(this: this->owner, projectile: v11);
      }
      if ( g_infiniteAmmo.valueInteger == 0 && g_permaInfiniteAmmo.valueInteger == 0 )
      {
        v12 = this->throwItem;
        v13 = (idJobManager *)this->owner->GetInventory(this: this->owner);
        JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v13, jobDecl: (const idDeclJob *)v12);
        if ( JobByDecl != nullptr )
          idPresentablePlayer::RespondToUseItem(this: this->owner, item: JobByDecl, used: true);
      }
      this->playingWarningSound = false;
      this->throwItem = nullptr;
      this->cookingProjectile.spawnId.value = 0x1FFF;
      this->cookingProjectileDecl = nullptr;
      this->cookingStartTime = 0;
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v17.targetList);
    }
    else
    {
      idLib::Warning(fmt: "no item to throw in idHands::ActuallyThrowItem");
    }
  }
  else
  {
    idHandsItem::Clear(this: &this->leftItem);
  }
}


// ========================================================================
// __unwind$502838
// EA  : 0x82E06208
// RVA : 0x00E06208
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_502838()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2800 + 112));
}


// ========================================================================
// ?Reset@idHands@@QAAX_N@Z
// EA  : 0x82E06238
// RVA : 0x00E06238
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::Reset(idHands *this, bool doIntro)
{
  idHandsItem *p_rightItem; // r3
  int v5; // r29
  int value; // r11
  const char *SubWebName; // r3
  __int64 v8; // r9
  idWeapon *PendingWeapon; // r3
  idWeapon *v10; // r29
  idAnimWebHands *p_web; // r29
  char *data; // r28
  int PlayerGameTime; // r3
  const char *v14; // r5
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *decl; // r4
  char *v16; // r27
  const char *v17; // r4
  __int64 v18; // [sp+50h] [-70h] BYREF
  idStr v19[3]; // [sp+60h] [-60h] BYREF

  p_rightItem = &this->rightItem;
  if ( p_rightItem != nullptr )
    idHandsItem::Reset(this: p_rightItem);
  if ( this != (idHands *)-4532 )
    idHandsItem::Reset(this: &this->leftItem);
  v5 = 0;
  this->throwItem = nullptr;
  this->pendingAction.action = HANDSACTION_NONE;
  this->pendingAction.ammoDecl = nullptr;
  this->pendingAction.weapon = nullptr;
  this->pendingAction.throwable = nullptr;
  this->pendingAction.useIntroBringUp = false;
  this->pendingAction.isSecondary = false;
  this->pendingAction.leftHand = false;
  idStr::Clear(this: &this->pendingAction.extraNodeInfo);
  this->lastActionTime = idClientGame::GetPlayerGameTime(this: clientGame);
  this->lingeringAction.action = HANDSACTION_NONE;
  this->lingeringAction.ammoDecl = nullptr;
  this->lingeringAction.weapon = nullptr;
  this->lingeringAction.throwable = nullptr;
  this->lingeringAction.useIntroBringUp = false;
  this->lingeringAction.isSecondary = false;
  this->lingeringAction.leftHand = false;
  idStr::Clear(this: &this->lingeringAction.extraNodeInfo);
  HIDWORD(v18) = this->web.decl;
  if ( HIDWORD(v18) != 0 )
  {
    value = this->web.curNodeIndex.value;
    if ( value != -1 )
      v5 = *(_DWORD *)(4 * value + *(_DWORD *)(HIDWORD(v18) + 56));
    SubWebName = idDeclAnimWeb::GetSubWebName(
                   this: (idDeclAnimWeb *)HIDWORD(v18),
                   index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)*(unsigned __int16 *)(v5 + 2));
    idStr::idStr(this: v19, text: SubWebName);
    idPresentablePlayer::ClearPendingAmmo(this: this->owner);
    PendingWeapon = idPresentablePlayer::GetPendingWeapon(this: this->owner);
    v10 = PendingWeapon;
    if ( PendingWeapon != nullptr )
    {
      idWeapon::SetFireState(this: PendingWeapon, fs: FIRESTATE_IDLE);
      idWeapon::BeginReloading(this: v10, ammoDecl: nullptr, secondaryAmmo: false);
      idHands::GetWeaponSubWebName(this, weapon: v10, name: v19, secondary: false);
    }
    if ( doIntro )
    {
      p_web = &this->web;
      data = v19[0].data;
      PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
      v14 = "intro";
    }
    else
    {
      decl = (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->web.decl;
      LODWORD(v8) = this->currentVariationIndex;
      v18 = v8;
      this->web.previousVariationIndex = (float)v8;
      p_web = &this->web;
      if ( HIWORD(idDeclAnimWeb::GetSubWebIndexForName(this: (idDeclAnimWeb *)&v18, result: decl, subWebName: "bringup")->__vftable) < 0x8000u )
      {
        v16 = v19[0].data;
        PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
        v14 = "bringup";
        v17 = v16;
LABEL_16:
        idAnimator_AnimWeb::Reset(this: p_web, initialSubWebName: v17, initialStateName: v14, curTime: PlayerGameTime);
        idAnimator_AnimWeb::ChangeState(
          this: p_web,
          subWebName: v19[0].data,
          stateName: "idle",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_YES,
          blendEventMask_: 0);
        idHandsItem::Clear(this: &this->leftItem);
        idRibbon::~idRibbon(this: (idRibbon *)&this->handsMeleeTrace);
        idStr::FreeData(this: v19);
        return;
      }
      data = v19[0].data;
      PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
      v14 = "idle";
    }
    v17 = data;
    goto LABEL_16;
  }
}


// ========================================================================
// __unwind$503233
// EA  : 0x82E06448
// RVA : 0x00E06448
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_503233()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?ResetAnimWeb@idHands@@QAAXXZ
// EA  : 0x82E06478
// RVA : 0x00E06478
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::ResetAnimWeb(idHands *this)
{
  idWeapon *v2; // r4
  idPresentablePlayer *owner; // r11
  int v4; // r3
  char v5; // r11
  const char *v6; // r30
  char *data; // r28
  int PlayerGameTime; // r3
  idStr v9[2]; // [sp+50h] [-50h] BYREF

  v9[0].len = 0;
  v9[0].allocedAndFlag = 20;
  v9[0].data = v9[0].baseBuffer;
  v9[0].baseBuffer[0] = 0;
  if ( this == (idHands *)-2996 )
    v2 = nullptr;
  else
    v2 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
  idHands::GetWeaponSubWebName(this, weapon: v2, name: v9, secondary: false);
  owner = this->owner;
  if ( owner == nullptr
    || (v4 = ((int (*)(void))owner->GetEquippedWeapon)()) == 0
    || (v5 = 1, *(_DWORD *)(*(_DWORD *)(v4 + 12) + 560) != 0) )
  {
    v5 = 0;
  }
  if ( v5 != 0 )
    v6 = "hide";
  else
    v6 = "idle";
  data = v9[0].data;
  PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
  idAnimator_AnimWeb::Reset(this: &this->web, initialSubWebName: data, initialStateName: v6, curTime: PlayerGameTime);
  idStr::FreeData(this: v9);
}


// ========================================================================
// __unwind$503392
// EA  : 0x82E0656C
// RVA : 0x00E0656C
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_503392()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?ActuallyThrowItem@idHands@@QAAXXZ
// EA  : 0x82E065A0
// RVA : 0x00E065A0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::ActuallyThrowItem(idHands *this)
{
  const idDeclProjectile *projectileDecl; // r23
  idPresentablePlayer *owner; // r10
  idFinishFireResults *v4; // r11
  int i; // ctr
  int value; // r9
  idProjectile *v7; // r3
  idProjectile *v8; // r3
  idSoundShader *warningSound; // r3
  int v10; // r29
  int v11; // r29
  idPresentablePtr<idPresentable> *projectiles; // r28
  int entityNumber; // r28
  double v14; // fp8
  double v15; // fp7
  double v16; // fp6
  double v17; // fp5
  double v18; // fp4
  double v19; // fp3
  double v20; // fp2
  idPresentableProjectile *v21; // r5
  idPresentableProjectile *v22; // r3
  const idDeclThrowable *v23; // r29
  idJobManager *v24; // r3
  idInventoryItem *JobByDecl; // r4
  __int64 v26; // [sp+8h] [-1558h]
  int v27; // [sp+10h] [-1550h]
  int v28; // [sp+14h] [-154Ch]
  int v29; // [sp+18h] [-1548h]
  int v30; // [sp+1Ch] [-1544h]
  int v31; // [sp+20h] [-1540h]
  int v32; // [sp+24h] [-153Ch]
  int v33; // [sp+28h] [-1538h]
  int v34; // [sp+2Ch] [-1534h]
  int v35; // [sp+30h] [-1530h]
  int v36; // [sp+34h] [-152Ch]
  int v37; // [sp+38h] [-1528h]
  int v38; // [sp+3Ch] [-1524h]
  int v39; // [sp+40h] [-1520h]
  int v40; // [sp+44h] [-151Ch]
  int v41; // [sp+48h] [-1518h]
  int v42; // [sp+4Ch] [-1514h]
  int v43[9]; // [sp+50h] [-1510h] BYREF
  int cookingStartTime; // [sp+74h] [-14ECh]
  int v45; // [sp+78h] [-14E8h]
  int v46; // [sp+7Ch] [-14E4h]
  const idDeclThrowable *throwItem; // [sp+80h] [-14E0h]
  idVec3 v48; // [sp+88h] [-14D8h] BYREF
  idFireParms v49; // [sp+A0h] [-14C0h] BYREF
  idFinishFireResults v50; // [sp+140h] [-1420h] BYREF
  idMat3 v51; // [sp+190h] [-13D0h] BYREF
  idTestFireResults v52; // [sp+1C0h] [-13A0h] BYREF
  idClientGameMsg_HandsThrow v53; // [sp+AD0h] [-A90h] BYREF

  throwItem = this->throwItem;
  if ( throwItem != nullptr )
  {
    projectileDecl = throwItem->projectileDecl;
    idHandsItem::GetMuzzlePosition(this: &this->leftItem, hands: this, origin: &v48, axis: &v51);
    idFireParms::idFireParms(this: &v49);
    owner = this->owner;
    if ( owner != nullptr )
      v49.attacker.spawnId = owner->spawnId;
    else
      v49.attacker.spawnId = 0;
    v49.target.spawnId = 0;
    v49.start.x = v48.x;
    v49.wepDef = nullptr;
    v49.start.y = v48.y;
    v49.start.z = v48.z;
    v49.fireAxis.mat[0].x = owner->firstPersonViewAxis.mat[0].x;
    v49.fireAxis.mat[0].y = owner->firstPersonViewAxis.mat[0].y;
    v49.fireAxis.mat[0].z = owner->firstPersonViewAxis.mat[0].z;
    v49.fireAxis.mat[1].x = owner->firstPersonViewAxis.mat[1].x;
    v49.fireAxis.mat[1].y = owner->firstPersonViewAxis.mat[1].y;
    v49.fireAxis.mat[1].z = owner->firstPersonViewAxis.mat[1].z;
    throwItem = (const idDeclThrowable *)&owner->firstPersonViewAxis.mat[2];
    v49.fireAxis.mat[2].x = owner->firstPersonViewAxis.mat[2].x;
    v49.fireAxis.mat[2].y = owner->firstPersonViewAxis.mat[2].y;
    v49.fireAxis.mat[2].z = owner->firstPersonViewAxis.mat[2].z;
    *((_BYTE *)&v49 + 128) = *((_BYTE *)&v49 + 128) & 0x2B | 0x14;
    v49.projDef = projectileDecl;
    v49.targetPos.x = owner->focusTracker.focusTrace.tr.endpos.x;
    v49.targetPos.y = owner->focusTracker.focusTrace.tr.endpos.y;
    v49.targetPos.z = owner->focusTracker.focusTrace.tr.endpos.z;
    memset(&v52, 0, sizeof(v52));
    *((_BYTE *)&v49 + 129) &= ~0x20u;
    v4 = &v50;
    v50.numProjectiles = 0;
    for ( i = 16; i != 0; --i )
    {
      v4 = (idFinishFireResults *)((char *)v4 + 4);
      v4->numProjectiles = 0;
    }
    if ( this->cookingStartTime > 0 )
    {
      value = this->cookingProjectile.spawnId.value;
      v49.startTime = this->cookingStartTime;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = (idProjectile *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
        && (v8 = idProjectile::CastTo(c: v7)) != nullptr )
      {
        throwItem = (const idDeclThrowable *)v8->entityNumber;
        v49.projectile.spawnId.value = (*((_DWORD *)&gameLocal->__vftable + (_DWORD)throwItem + 29755) << 13)
                                     | (unsigned int)throwItem;
      }
      else
      {
        v49.projectile.spawnId.value = 0x1FFF;
      }
      this->cookingProjectile.spawnId.value = 0x1FFF;
      this->cookingProjectileDecl = nullptr;
    }
    idClientGame::TestFire(this: clientGame, fp: &v49, tfr: &v52);
    if ( common->IsServer(this: common) )
      idGameLocal::FinishFire(this: gameLocal, fp: &v49, tfr: &v52, ffr: &v50);
    else
      idClientGame::FinishFire(this: clientGame, fp: &v49, tfr: &v52, ffr: &v50);
    if ( this->cookingStartTime > 0 )
    {
      warningSound = projectileDecl->notHitscanInfo.grenadeInfo.warningSound;
      if ( warningSound != nullptr )
      {
        v10 = this->cookingDetonationTime - idSoundShader::GetMaxLength(this: warningSound) + this->cookingStartTime;
        if ( idPresentablePlayer::GetPlayerGameTime(this: this->owner) >= v10 )
        {
          v11 = 0;
          if ( v50.numProjectiles > 0 )
          {
            projectiles = (idPresentablePtr<idPresentable> *)v50.projectiles;
            do
            {
              ++v11;
              HIBYTE(idPresentablePtr<idPresentableProjectile>::operator->(this: projectiles++)[1].axes[0].mat[1].z) = 1;
            }
            while ( v11 < v50.numProjectiles );
          }
        }
      }
    }
    if ( !common->IsMultiplayer(this: common) || common->IsServer(this: common) )
    {
      v21 = nullptr;
      if ( v50.numProjectiles >= 1 )
        v21 = (idPresentableProjectile *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)v50.projectiles);
      idPresentablePlayer::NotifyThrowRelease(this: this->owner, throwItem: this->throwItem, spawnedProjectile: v21);
    }
    else
    {
      entityNumber = this->owner->entityNumber;
      cookingStartTime = this->cookingStartTime;
      memcpy(Dst: v43, Src: &v49.fireAxis.mat[1].y, Size: 0x14u);
      idClientGameMsg_HandsThrow::idClientGameMsg_HandsThrow(
        this: &v53,
        playerNumber_: entityNumber,
        throwType_: HANDS_THROW_RELEASE,
        start_: __SPAIR64__(LODWORD(v49.start.y), __ROL4__(LODWORD(v49.fireAxis.mat[0].x), 32)),
        fireAxis_: (idMat3 *)LODWORD(v49.fireAxis.mat[0].z),
        initialSpeed_: v49.startSpeed,
        startTime_: v26,
        a8: v20,
        a9: v19,
        a10: v18,
        a11: v17,
        a12: v16,
        a13: v15,
        a14: v14,
        a15: v27,
        a16: v28,
        a17: v29,
        a18: v30,
        a19: v31,
        a20: v32,
        a21: v33,
        a22: v34,
        a23: v35,
        a24: v36,
        a25: v37,
        a26: v38,
        a27: v39,
        a28: v40,
        a29: v41,
        a30: v42,
        a31: v43[0],
        a32: v43[1],
        a33: *(float *)&v43[2],
        a34: *(float *)&v43[3],
        a35: *(float *)&v43[4],
        a36: *(float *)&v43[5],
        a37: *(float *)&v43[6],
        a38: v43[7],
        a39: v43[8],
        a40: cookingStartTime,
        a41: v45,
        a42: v46);
      idClientGame::HandleReliableGameMsg(this: clientGame, gameMsg: &v53);
      idClientGameMsg_HandsThrow::~idClientGameMsg_HandsThrow(this: &v53);
    }
    idHandsItem::Clear(this: &this->leftItem);
    idPresentablePlayer::WeaponFireFeedback(this: this->owner, weapon: nullptr, projDecl: projectileDecl);
    if ( projectileDecl->notHitscanInfo.allowOnlyOne
      && v50.numProjectiles > 0
      && idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)v50.projectiles) )
    {
      v22 = (idPresentableProjectile *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)v50.projectiles);
      idPresentablePlayer::TrackUniqueProjectile(this: this->owner, projectile: v22);
    }
    if ( g_infiniteAmmo.valueInteger == 0 && g_permaInfiniteAmmo.valueInteger == 0 )
    {
      v23 = this->throwItem;
      v24 = (idJobManager *)this->owner->GetInventory(this: this->owner);
      JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v24, jobDecl: (const idDeclJob *)v23);
      if ( JobByDecl != nullptr )
        idPresentablePlayer::RespondToUseItem(this: this->owner, item: JobByDecl, used: true);
    }
    this->playingWarningSound = false;
    this->throwItem = nullptr;
    this->cookingProjectile.spawnId.value = 0x1FFF;
    this->cookingProjectileDecl = nullptr;
    this->cookingStartTime = 0;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v49.targetList);
  }
  else
  {
    idLib::Warning(fmt: "no item to throw in idHands::ActuallyThrowItem");
  }
}


// ========================================================================
// __unwind$503490
// EA  : 0x82E06A44
// RVA : 0x00E06A44
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_503490()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 5472 + 160));
}


// ========================================================================
// __unwind$503491
// EA  : 0x82E06A6C
// RVA : 0x00E06A6C
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_503491()
{
  int v0; // r12

  idClientGameMsg_HandsThrow::~idClientGameMsg_HandsThrow(this: (idClientGameMsg_HandsThrow *)(v0 - 5472 + 2768));
}


// ========================================================================
// ?FireWeapon@idHands@@IAAXW4equipSlot_t@@_N@Z
// EA  : 0x82E06AA0
// RVA : 0x00E06AA0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::FireWeapon(idHands *this, const equipSlot_t slot, BOOL secondary)
{
  float *v6; // r30
  idHandsItem *p_leftItem; // r25
  idWeapon *v8; // r3
  idPresentablePlayer *owner; // r8
  int *v10; // r9
  int v11; // ctr
  idWeapon *v12; // r26
  idPresentablePlayer *p_z; // r11
  float y; // r5
  float z; // r4
  idPresentablePlayer *v16; // r3
  idEntity *entity; // r29
  float *distance_low; // r11
  double v19; // fp11
  double v20; // fp9
  double v21; // fp8
  double v22; // fp7
  double v23; // fp6
  double v24; // fp5
  double v25; // fp4
  double v26; // fp3
  int *v27; // r10
  int *v28; // r11
  int i; // ctr
  idHandsItem *p_rightItem; // r3
  idFinishFireResults *v31; // r11
  int j; // ctr
  idEntity *v33; // r30
  idProjectile *v34; // r3
  idAmmoItem *ammoClipSecondary; // r3
  const idDeclProjectile *ProjectileDef; // r3
  idPresentablePlayer *v37; // r9
  double v38; // fp1
  float *v39; // r3
  double v40; // fp3
  double v41; // fp2
  double v42; // fp1
  double v43; // fp11
  double v44; // fp7
  double v45; // fp2
  double v46; // fp1
  double v47; // fp31
  float v48; // r10
  float v49; // r11
  float x; // r8
  const idPresentable *v51; // r3
  idEntity *v52; // r11
  const idDeclProjectile *CurrentProjectileDecl; // r3
  idFXManager *v54; // [sp+8h] [-C18h]
  bool v55; // [sp+Fh] [-C11h]
  float distance; // [sp+60h] [-BC0h]
  idEntity *v57; // [sp+60h] [-BC0h]
  idVec3 v58; // [sp+68h] [-BB8h] BYREF
  idVec3 v59; // [sp+78h] [-BA8h] BYREF
  idVec3 v60; // [sp+88h] [-B98h] BYREF
  idMat3 v61; // [sp+A0h] [-B80h] BYREF
  idVec3 v62; // [sp+C8h] [-B58h] BYREF
  float v63; // [sp+D8h] [-B48h]
  float v64; // [sp+DCh] [-B44h]
  float v65; // [sp+E0h] [-B40h]
  int v66; // [sp+ECh] [-B34h] BYREF
  float v67; // [sp+F0h] [-B30h]
  float v68; // [sp+F4h] [-B2Ch]
  float v69; // [sp+F8h] [-B28h]
  float v70; // [sp+FCh] [-B24h]
  float v71; // [sp+100h] [-B20h]
  float v72; // [sp+104h] [-B1Ch]
  float v73; // [sp+108h] [-B18h]
  float v74; // [sp+10Ch] [-B14h]
  float v75; // [sp+110h] [-B10h]
  idFireParms v76; // [sp+120h] [-B00h] BYREF
  int v77; // [sp+1BCh] [-A64h] BYREF
  idMat3 v78; // [sp+1C0h] [-A60h] BYREF
  idFinishFireResults v79; // [sp+1F0h] [-A30h] BYREF
  trace_t v80; // [sp+240h] [-9E0h] BYREF
  idTestFireResults v81; // [sp+2C0h] [-960h] BYREF

  v6 = nullptr;
  if ( slot == EQUIP_LEFT_HAND )
  {
    p_leftItem = &this->leftItem;
  }
  else if ( slot == EQUIP_RIGHT_HAND )
  {
    p_leftItem = &this->rightItem;
  }
  else
  {
    p_leftItem = nullptr;
  }
  v8 = idWeapon::CastTo(c: (idWeapon *)p_leftItem->item);
  owner = this->owner;
  v10 = &v66;
  v11 = 9;
  v12 = v8;
  p_z = (idPresentablePlayer *)&owner->firstPersonViewOrigin.z;
  y = owner->firstPersonViewOrigin.y;
  z = owner->firstPersonViewOrigin.z;
  v59.x = owner->firstPersonViewOrigin.x;
  v59.y = y;
  v59.z = z;
  do
  {
    p_z = (idPresentablePlayer *)((char *)p_z + 4);
    *++v10 = (int)p_z->__vftable;
    --v11;
  }
  while ( v11 != 0 );
  v16 = this->owner;
  entity = v16->entity;
  if ( idPresentablePlayer::PlayerBehavior_ContextualShimmy_IsInShimmy(this: v16)
    || idPresentablePlayer::PlayerBehavior_WallClimb_IsInWallClimb(this: this->owner) )
  {
    distance = entity[16].dormancy.distance;
    if ( distance != 0.0 && *(_DWORD *)(LODWORD(distance) + 1336) != 0 )
    {
      v59 = *(idVec3 *)(LODWORD(distance) + 1344);
      distance_low = (float *)LODWORD(entity[16].dormancy.distance);
      v19 = distance_low[343];
      v20 = distance_low[346];
      v21 = distance_low[347];
      v22 = distance_low[339];
      v23 = distance_low[340];
      v24 = distance_low[341];
      v25 = distance_low[342];
      v26 = distance_low[344];
      v73 = distance_low[345];
      v71 = v19;
      v72 = v26;
      v67 = v22;
      v68 = v23;
      v69 = v24;
      v70 = v25;
      v74 = v20;
      v75 = v21;
    }
  }
  v27 = &v77;
  v28 = &v66;
  v58 = v59;
  for ( i = 9; i != 0; --i )
    *++v27 = *++v28;
  if ( (_cntlzw((unsigned int)v12->decl[1].parent) & 0x20) != 0 && secondary && slot == EQUIP_LEFT_HAND )
  {
    p_rightItem = &this->rightItem;
    if ( this->hiddenReasons != 0 )
      goto LABEL_24;
  }
  else
  {
    if ( this->hiddenReasons != 0 )
      goto LABEL_24;
    p_rightItem = p_leftItem;
  }
  if ( !idHandsItem::GetMuzzlePosition(this: p_rightItem, hands: this, origin: &v58, axis: &v78) )
    idLib::Warning(fmt: "GetMuzzlePosition() failed in idHands::FireWeapon");
LABEL_24:
  idFireParms::idFireParms(this: &v76);
  memset(&v81, 0, sizeof(v81));
  v31 = &v79;
  v79.numProjectiles = 0;
  for ( j = 16; j != 0; --j )
  {
    v31 = (idFinishFireResults *)((char *)v31 + 4);
    v31->numProjectiles = 0;
  }
  if ( v12->NeedsReload(this: v12, a2: secondary) )
  {
    idWeapon::SetFireState(this: v12, fs: FIRESTATE_IDLE);
  }
  else
  {
    if ( common->IsServer(this: common)
      && gameLocal->spawnIds.ptr[this->previousProjectile.spawnId.value & 0x1FFF] == this->previousProjectile.spawnId.value >> 13 )
    {
      v33 = this->owner->entity;
      if ( v33 != nullptr )
      {
        v34 = idEntityPtr<idProjectile>::GetEntity(this: &this->previousProjectile);
        idEntity::Activate(this: v34, activator: v33);
      }
    }
    else
    {
      if ( secondary )
        ammoClipSecondary = v12->ammoClipSecondary;
      else
        ammoClipSecondary = v12->ammoClip;
      if ( ammoClipSecondary != nullptr
        && (ProjectileDef = idAmmoItem::GetProjectileDef(this: ammoClipSecondary),
            v6 = (float *)ProjectileDef,
            ProjectileDef != nullptr)
        && !ProjectileDef->hitscan
        && ProjectileDef->notHitscanInfo.fireFromMuzzle )
      {
        v37 = this->owner;
        v62.x = v58.x;
        v62.y = v58.y;
        v62.z = v58.z;
        v60.z = v59.z + (float)(v69 * (float)8192.0);
        v60.x = (float)(v67 * (float)8192.0) + v59.x;
        v60.y = v59.y + (float)(v68 * (float)8192.0);
        idClip::TracePoint(
          this: &clientGame->clip,
          result: &v80,
          start: &v59,
          end: &v60,
          clipMask: 8462469,
          passEntityNumber: v37->entityNumber);
        if ( v80.fraction < 1.0 )
        {
          v60.x = v80.endpos.x;
          v60.y = v80.endpos.y;
          v60.z = v80.endpos.z;
        }
        v61.mat[0].x = v60.x - v58.x;
        v61.mat[0].z = v60.z - v58.z;
        v61.mat[0].y = v60.y - v58.y;
        v38 = idVec3::NormalizeFast(this: v61.mat);
        v39 = (float *)((int (__fastcall *)(idPhysics_Player *, double))this->owner->physicsObj.GetGravityNormal)(
                         a1: &this->owner->physicsObj,
                         a2: v38);
        v40 = v39[2];
        v41 = (float)(*v39 * (float)-1.0);
        v42 = (float)(v39[1] * (float)-1.0);
        v61.mat[2].x = *v39 * (float)-1.0;
        v61.mat[2].y = v42;
        v61.mat[2].z = (float)v40 * (float)-1.0;
        v61.mat[1].y = (float)(v61.mat[0].x * v61.mat[2].z) - (float)(v61.mat[0].z * (float)v41);
        v61.mat[1].z = (float)(v61.mat[0].y * (float)v41) - (float)(v61.mat[0].x * (float)v42);
        v61.mat[1].x = (float)(v61.mat[0].z * (float)v42) - (float)(v61.mat[0].y * v61.mat[2].z);
        idMat3::OrthoNormalizeSelf(this: &v61);
      }
      else
      {
        idPresentablePlayer::GetFireTrajectory(this: this->owner, firePos: &v62, fireAxis: &v61);
      }
      if ( this->unlinked && v6 != nullptr )
      {
        v43 = (float)(v61.mat[2].z * v6[134]);
        v44 = (float)(v61.mat[2].y * v6[134]);
        v45 = (float)((float)(v61.mat[0].z * v6[132]) + (float)(v61.mat[1].z * v6[133]));
        v46 = (float)((float)(v61.mat[0].y * v6[132]) + (float)(v61.mat[1].y * v6[133]));
        v76.muzzleOffset.x = (float)((float)(v61.mat[0].x * v6[132]) + (float)(v61.mat[1].x * v6[133]))
                           + (float)(v61.mat[2].x * v6[134]);
        v76.muzzleOffset.z = (float)v45 + (float)v43;
        v76.muzzleOffset.y = (float)v46 + (float)v44;
      }
      else
      {
        v76.muzzleOffset.x = v58.x - v62.x;
        v76.muzzleOffset.z = v58.z - v62.z;
        v76.muzzleOffset.y = v58.y - v62.y;
      }
      *((_BYTE *)&v76 + 128) |= 0x10u;
      if ( v6 != nullptr )
        v47 = v6[123];
      else
        v47 = 0.0;
      v76.addSpread = idPresentablePlayer::GetCurWeaponSpread(this: this->owner, secondary) - (float)v47;
      v57 = this->owner->entity;
      if ( v57 != nullptr )
        v76.damageScale = ((double (__fastcall *)(idEntity *))v57->__vftable[1].GetJointIndexFromTrace)(a1: v57);
      v48 = v58.y;
      v49 = v58.z;
      x = v58.x;
      v12->ribbonStart.x = v58.x;
      v64 = v48;
      v65 = v49;
      v12->ribbonStart.z = v49;
      v63 = x;
      v12->ribbonStart.y = v48;
      idHandsItem::GetFXMgr(this: p_leftItem);
      v51 = idPresentablePtr<idPresentableProjectile>::operator->(this: &v76.target);
      idWeapon::Fire(
        this: v12,
        attacker: this->owner,
        target: v51,
        start: &v62,
        fireAxis: &v61,
        fp: &v76,
        tfr: &v81,
        ffr: &v79,
        fxMgr: v54,
        secondaryAmmo: v55);
      if ( HIBYTE(v12->decl[2].quickSlotGroup) != 0 )
      {
        v52 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)v79.projectiles)->entity;
        if ( v52 != nullptr )
          this->previousProjectile.spawnId.value = (gameLocal->spawnIds.ptr[v52->entityNumber] << 13)
                                                 | v52->entityNumber;
        else
          this->previousProjectile.spawnId.value = 0x1FFF;
      }
    }
    CurrentProjectileDecl = idWeapon::GetCurrentProjectileDecl(this: v12, secondaryAmmo: secondary);
    idPresentablePlayer::WeaponFireFeedback(
      this: this->owner,
      weapon: v12,
      projDecl: CurrentProjectileDecl,
      fp: &v76,
      tfr: &v81,
      ffr: &v79);
  }
  idHands::CheckAutoReload(this, secondary, setLingeringAction: 0);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v76.targetList);
}


// ========================================================================
// __unwind$503992
// EA  : 0x82E071CC
// RVA : 0x00E071CC
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_503992()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 3104 + 288));
}


// ========================================================================
// ?Reload@idHands@@QAA_NW4equipSlot_t@@_N@Z
// EA  : 0x82E07200
// RVA : 0x00E07200
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

int __fastcall idHands::Reload(idHands *this, const equipSlot_t slot, bool forceSecondary)
{
  idHandsItem *p_leftItem; // r11
  idWeapon *v7; // r3
  idWeapon *v8; // r26
  bool v9; // r11
  BOOL v10; // r27
  const idAmmoItem *v11; // r25
  const idDeclAmmo *v12; // r29
  const idDeclAmmo *NextLoadableAmmo; // r30
  const idInventoryCollection *v14; // r3
  idInventoryCollection *v15; // r3
  idWeapon *v16; // r4
  char *data; // r30
  int PlayerGameTime; // r3
  idStr v20[3]; // [sp+50h] [-70h] BYREF

  if ( slot == EQUIP_LEFT_HAND )
  {
    p_leftItem = &this->leftItem;
  }
  else
  {
    if ( slot != EQUIP_RIGHT_HAND )
      return 0;
    p_leftItem = &this->rightItem;
  }
  if ( p_leftItem == nullptr )
    return 0;
  v7 = idWeapon::CastTo(c: (idWeapon *)p_leftItem->item);
  v8 = v7;
  if ( v7 == nullptr )
    return 0;
  if ( forceSecondary || (v9 = false, v7->weaponState == WEAPONSTATE_SECONDARY) )
    v9 = true;
  v10 = v9;
  if ( idWeapon::IsFullyLoaded(this: v7, secondaryAmmo: v9)
    || this->isReloading
    || (unsigned __int8)idHands::ReloadPending(this) != 0 )
  {
    return 0;
  }
  v11 = v10 ? v8->ammoClipSecondary : v8->ammoClip;
  v12 = v11 != nullptr ? (const idDeclAmmo *)v11->decl : nullptr;
  NextLoadableAmmo = v12;
  if ( v12 == nullptr
    || (v14 = this->owner->GetInventory(this: this->owner),
        !idWeapon::CanReload(this: v8, inventory: v14, ammoDecl: v12, secondaryAmmo: v10)) )
  {
    if ( !v8->NeedsReload(this: v8, a2: v10) )
      return 0;
    v15 = this->owner->GetInventory(this: this->owner);
    NextLoadableAmmo = idWeapon::FindNextLoadableAmmo(this: v8, inventory: v15, curAmmo: v11, secondaryAmmo: v10);
    if ( v12 == NextLoadableAmmo )
      return 0;
  }
  if ( NextLoadableAmmo == nullptr )
    return 0;
  idPlayer::CancelSprint(this: (idPlayer *)this->owner->entity);
  idHands::SetPendingAction(
    this,
    action: (idHands::handsAction_t)(((_cntlzw((char *)v12 - (char *)NextLoadableAmmo) & 0x20) == 0) + 3),
    ammoDecl: NextLoadableAmmo,
    secondary: v10,
    leftHand: (_cntlzw(slot - 1) & 0x20) != 0);
  if ( this->currentDualWieldState == SET_DUALWIELD_ON )
  {
    v20[0].len = 0;
    v20[0].baseBuffer[0] = 0;
    v20[0].allocedAndFlag = 20;
    v20[0].data = v20[0].baseBuffer;
    if ( this == (idHands *)-2996 )
      v16 = nullptr;
    else
      v16 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
    idHands::GetWeaponSubWebName(this, weapon: v16, name: v20, secondary: false);
    data = v20[0].data;
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idAnimator_AnimWeb::Reset(
      this: &this->secondaryWeb,
      initialSubWebName: data,
      initialStateName: "idle",
      curTime: PlayerGameTime);
    idStr::FreeData(this: v20);
  }
  return 1;
}


// ========================================================================
// __unwind$504521
// EA  : 0x82E07450
// RVA : 0x00E07450
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_504521()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?SetReloadState@idHands@@QAAXPBD@Z
// EA  : 0x82E07480
// RVA : 0x00E07480
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SetReloadState(idHands *this, const char *subWebName)
{
  idWeapon *v4; // r29
  idWeapon *v5; // r3
  __int64 v6; // r9
  bool isSecondary; // r5
  idAmmoItem *ammoClipSecondary; // r11
  const idDeclInventory *decl; // r11
  idAmmoItem *ammoClip; // r11
  const idDeclInventory *v11; // r11
  idHands *ReloadNodeName; // r3
  idStr *v13; // r3
  bool leftHand; // r6
  idHands *v15; // r3
  _BYTE v16[32]; // [sp+60h] [-70h] BYREF
  _BYTE v17[80]; // [sp+80h] [-50h] BYREF

  v4 = this->owner->GetEquippedWeapon(this: this->owner, a2: ((_cntlzw(this->pendingAction.leftHand) & 0x20) != 0) + 1);
  v5 = this->owner->GetEquippedWeapon(this: this->owner, a2: ((_cntlzw(this->pendingAction.leftHand) & 0x20) == 0) + 1);
  if ( v5 != nullptr )
    idWeapon::StopLoopingFireSound(this: v5);
  idWeapon::BeginReloading(
    this: v4,
    ammoDecl: this->pendingAction.ammoDecl,
    secondaryAmmo: this->pendingAction.isSecondary);
  isSecondary = this->pendingAction.isSecondary;
  if ( isSecondary )
    ammoClipSecondary = v4->ammoClipSecondary;
  else
    ammoClipSecondary = v4->ammoClip;
  if ( ammoClipSecondary != nullptr )
    decl = ammoClipSecondary->decl;
  else
    decl = nullptr;
  if ( decl != nullptr
    && (!this->pendingAction.isSecondary ? (ammoClip = v4->ammoClip) : (ammoClip = v4->ammoClipSecondary),
        ammoClip == nullptr ? (v11 = nullptr) : (v11 = ammoClip->decl),
        HIBYTE(v11[1].vehicleJointName.len) != 0 && (*((_BYTE *)v4 + 452) & 4) == 0) )
  {
    ReloadNodeName = idHands::GetReloadNodeName(
                       this: (idHands *)v16,
                       result: this,
                       secondary: isSecondary,
                       leftHand: this->pendingAction.leftHand);
    idAnimator_AnimWeb::ChangeState(
      this: &this->web,
      subWebName,
      stateName: (const char *)ReloadNodeName->listenerList,
      interruptPath_: INTR_PATH_YES,
      interruptBlend_: INTR_BLEND_NO,
      blendEventMask_: 0);
    v13 = (idStr *)v16;
  }
  else
  {
    leftHand = this->pendingAction.leftHand;
    LODWORD(v6) = v4->decl[3].holsterSlot;
    this->web.attackVariation = (float)v6;
    v15 = idHands::GetReloadNodeName(this: (idHands *)v17, result: this, secondary: isSecondary, leftHand);
    idAnimator_AnimWeb::ChangeStateVia(
      this: &this->web,
      subWebName,
      stateName: "idle",
      viaSubWebName: subWebName,
      viaStateName: (const char *)v15->listenerList,
      interruptPath_: INTR_PATH_YES,
      interruptBlend_: INTR_BLEND_NO,
      blendEventMask_: 0);
    v13 = (idStr *)v17;
  }
  idStr::FreeData(this: v13);
  this->isReloading = true;
  this->pendingAction.action = HANDSACTION_NONE;
  this->pendingAction.ammoDecl = nullptr;
  this->pendingAction.weapon = nullptr;
  this->pendingAction.throwable = nullptr;
  this->pendingAction.useIntroBringUp = false;
  this->pendingAction.isSecondary = false;
  this->pendingAction.leftHand = false;
  idStr::Clear(this: &this->pendingAction.extraNodeInfo);
  this->lastActionTime = idClientGame::GetPlayerGameTime(this: clientGame);
}


// ========================================================================
// __unwind$504656
// EA  : 0x82E07664
// RVA : 0x00E07664
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_504656()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$504657
// EA  : 0x82E0768C
// RVA : 0x00E0768C
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_504657()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 128));
}


// ========================================================================
// ?SelectWeapon@idHands@@QAAXW4equipSlot_t@@PAVidWeapon@@_N@Z
// EA  : 0x82E076B8
// RVA : 0x00E076B8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SelectWeapon(idHands *this, const equipSlot_t slot, idWeapon *weapon, bool useIntroBringUp)
{
  idWeapon *v8; // r3
  idWeapon *v9; // r29
  idAmmoItem *ammoClip; // r11
  const idDeclInventory *decl; // r11
  const idDeclProjectile *v12; // r3
  const idDeclInventory *v13; // r9
  const idDeclInventory *v14; // r11
  int parent; // r10
  int v16; // r11
  const idDeclInventory *itemDecl; // r11

  if ( weapon == nullptr )
    return;
  v8 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
  v9 = v8;
  if ( slot != EQUIP_RIGHT_HAND )
  {
    if ( slot == EQUIP_LEFT_HAND )
      idWeapon::CastTo(c: (idWeapon *)this->leftItem.item);
    goto LABEL_30;
  }
  if ( v8 == weapon )
  {
LABEL_30:
    this->pickupSlot = EQUIP_NONE;
    return;
  }
  ammoClip = weapon->ammoClip;
  if ( ammoClip != nullptr )
    decl = ammoClip->decl;
  else
    decl = nullptr;
  if ( decl != nullptr )
  {
    v12 = (const idDeclProjectile *)decl[1].__vftable;
    if ( v12 != nullptr )
      idHands::PreLoadWeaponSounds(projectile: v12);
  }
  v13 = weapon->decl;
  if ( v9 != nullptr )
    v14 = v9->decl;
  else
    v14 = nullptr;
  if ( v13 != nullptr )
    parent = (int)v13[1].parent;
  else
    parent = -1;
  if ( v14 != nullptr )
    v16 = (int)v14[1].parent;
  else
    v16 = -1;
  if ( v13 != nullptr && (parent == -1 || v16 == -1) && v13[3].equipSlot < EQUIP_NONE )
  {
    idPresentablePlayer::EquipItem(this: this->owner, item: weapon);
    idHands::ResetAnimWeb(this);
    this->pendingWeaponToEquip = nullptr;
    this->pickupSlot = EQUIP_NONE;
  }
  else
  {
    itemDecl = this->rightItem.itemDecl;
    this->pendingWeaponToEquip = weapon;
    if ( itemDecl != nullptr )
    {
      this->isInterruptableTransition = true;
      idHands::SetPendingAction(this, action: HANDSACTION_BRINGDOWN, weapon, useIntroBringUp, secondary: false);
    }
    else
    {
      idHands::HandsEquipItem(this, item: weapon);
      idHands::UpdateWeaponCondition(this, weapon);
      idHands::SetPendingAction(this, action: HANDSACTION_BRINGUP, weapon, useIntroBringUp, secondary: false);
    }
    this->pickupSlot = EQUIP_NONE;
  }
}


// ========================================================================
// ?SelectWeaponInstantly@idHands@@QAAXW4equipSlot_t@@PAVidWeapon@@@Z
// EA  : 0x82E07850
// RVA : 0x00E07850
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SelectWeaponInstantly(idHands *this, const equipSlot_t slot, idWeapon *weapon)
{
  idInventoryItem_vtbl *v5; // r27
  idFXManager *FXMgr; // r3
  int GameMs; // r26
  int v8; // r3
  double v9; // fp1
  idAmmoItem *ammoClip; // r11
  const idDeclInventory *decl; // r10
  idInventoryItem *item; // [sp+50h] [-90h]
  blendParms_t v13; // [sp+60h] [-80h] BYREF
  idStr v14[3]; // [sp+80h] [-60h] BYREF

  if ( slot != EQUIP_RIGHT_HAND )
  {
    if ( slot == EQUIP_LEFT_HAND )
      idWeapon::CastTo(c: (idWeapon *)this->leftItem.item);
    goto LABEL_14;
  }
  if ( idWeapon::CastTo(c: (idWeapon *)this->rightItem.item) == weapon )
  {
LABEL_14:
    this->pickupSlot = EQUIP_NONE;
    return;
  }
  item = this->rightItem.item;
  if ( item != nullptr && this->owner != nullptr )
  {
    v5 = item->__vftable;
    FXMgr = idHandsItem::GetFXMgr(this: &this->rightItem);
    v5->OnUnequip(this: item, a2: this->owner, a3: FXMgr);
  }
  v14[0].len = 0;
  v14[0].allocedAndFlag = 20;
  v14[0].data = v14[0].baseBuffer;
  v14[0].baseBuffer[0] = 0;
  idHands::GetWeaponSubWebName(this, weapon, name: v14, secondary: false);
  blendParms_t::blendParms_t(this: &v13);
  blendParms_t::SetDuration(this: &v13, frame: 0);
  idAnimator_AnimWeb::ForceState(
    this: &this->web,
    subWebName: v14[0].data,
    stateName: "idle",
    blendParms: &v13,
    blendEventMask_: 0);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v8 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
  idAnimator_JointMod::PreBlendSnapshot(
    this: (idAnimator_JointMod *)&this->web,
    stack: &this->animStack,
    curTime: GameMs,
    ticksPerSec: v8,
    fraction: v9);
  idHands::ClearPendingAction(this);
  if ( weapon != nullptr )
  {
    idHands::HandsEquipItem(this, item: weapon);
    ammoClip = weapon->ammoClip;
    if ( ammoClip != nullptr )
    {
      decl = ammoClip->decl;
      if ( decl != nullptr && decl[1].__vftable != nullptr )
        idHands::PreLoadWeaponSounds(projectile: (const idDeclProjectile *)ammoClip->decl[1].__vftable);
    }
  }
  idStr::FreeData(this: v14);
  this->pickupSlot = EQUIP_NONE;
}


// ========================================================================
// __unwind$504830
// EA  : 0x82E079F8
// RVA : 0x00E079F8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_504830()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// ?SelectAmmo@idHands@@QAAXW4equipSlot_t@@PAVidAmmoItem@@@Z
// EA  : 0x82E07A20
// RVA : 0x00E07A20
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::SelectAmmo(idHands *this, equipSlot_t slot, idAmmoItem *ammo)
{
  if ( ammo != nullptr )
    idHands::SelectAmmo(this, slot, ammoDecl: (const idDeclAmmo *)ammo->decl);
}


// ========================================================================
// ?AnimEvent_FireWeapon@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@W4equipSlot_t@@W4weaponState_t@idWeapon@@@Z
// EA  : 0x82E07A38
// RVA : 0x00E07A38
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_FireWeapon(
        idHands *this,
        idHands *result,
        const idMD6Anim *anim,
        equipSlot_t slot,
        const idWeapon::weaponState_t weaponstate)
{
  const char *str; // r30
  int PlayerGameTime; // r3
  eventVoid *p_leftItem; // r11
  idWeapon *v13; // r3
  unsigned int v14; // r11

  result->lastWeaponUsedTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_FireWeaponRight - '^2%s^7'\n", PlayerGameTime, str);
  }
  if ( slot == EQUIP_LEFT_HAND )
  {
    p_leftItem = (eventVoid *)&result->leftItem;
  }
  else if ( slot == EQUIP_RIGHT_HAND )
  {
    p_leftItem = (eventVoid *)&result->rightItem;
  }
  else
  {
    p_leftItem = nullptr;
  }
  v13 = idWeapon::CastTo(c: *(idWeapon **)&p_leftItem[1452]);
  if ( weaponstate == WEAPONSTATE_MAX )
    v14 = v13->weaponState - 1;
  else
    v14 = weaponstate - 1;
  idHands::FireWeapon(this: result, slot, secondary: (_cntlzw(v14) & 0x20) != 0);
  result->weaponRelaxedToggler = false;
  return this;
}


// ========================================================================
// ?AnimEvent_ThrowItem@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82E07B30
// RVA : 0x00E07B30
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_ThrowItem(idHands *this, idHands *result, const idMD6Anim *anim)
{
  const char *str; // r31
  int PlayerGameTime; // r3

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_ThrowItem- '^2%s^7'\n", PlayerGameTime, str);
  }
  if ( result->throwItem != nullptr )
    idHands::ActuallyThrowItem(this: result);
  else
    idLib::Warning(fmt: "throwItem is NULL in AnimEvent_ThrowItem");
  return this;
}


// ========================================================================
// ?AnimEvent_EquipWeapon@idHands@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82E07BD0
// RVA : 0x00E07BD0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idHands *__fastcall idHands::AnimEvent_EquipWeapon(idHands *this, idHands *result, const idMD6Anim *anim)
{
  const char *str; // r29
  int PlayerGameTime; // r3
  int v7; // r28
  idFXManager *FXMgr; // r3
  idWeapon *pendingWeaponToEquip; // r4
  idFXManager *v10; // r3
  idPresentableAnimatedEntity *presentable; // r24
  idWeapon_vtbl *v12; // r28
  idFXManager *v13; // r3
  idWeapon *v14; // r3
  char *data; // r29
  int v16; // r3
  int *item; // [sp+50h] [-80h]
  idStr v19[3]; // [sp+60h] [-70h] BYREF

  if ( hands_debugfc.valueInteger > 0 )
  {
    if ( anim != nullptr )
      str = anim->name.str;
    else
      str = "<NULL>";
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idLib::Printf(fmt: "^7( %d )idHands::AnimEvent_EquipWeapon - '^2%s^7'\n", PlayerGameTime, str);
  }
  item = (int *)result->rightItem.item;
  if ( item != nullptr )
  {
    v7 = *item;
    FXMgr = idHandsItem::GetFXMgr(this: &result->rightItem);
    (*(void (__fastcall **)(int *, idPresentablePlayer *, idFXManager *))(v7 + 44))(
      a1: item,
      a2: result->owner,
      a3: FXMgr);
  }
  pendingWeaponToEquip = result->pendingWeaponToEquip;
  result->weaponRelaxed = false;
  result->weaponRelaxedToggler = false;
  if ( pendingWeaponToEquip != nullptr )
  {
    idHands::HandsEquipItem(this: result, item: pendingWeaponToEquip);
    if ( result != (idHands *)-2996 )
    {
      idHandsItem::Show(this: &result->rightItem);
      v10 = idHandsItem::GetFXMgr(this: &result->rightItem);
      idWeapon::OnChamberAmmo(this: result->pendingWeaponToEquip, fxMgr: v10);
      presentable = result->presentable;
      v12 = result->pendingWeaponToEquip->__vftable;
      v13 = idHandsItem::GetFXMgr(this: &result->rightItem);
      v12->OnEquip(this: result->pendingWeaponToEquip, a2: presentable, a3: v13);
    }
    v19[0].len = 0;
    v19[0].baseBuffer[0] = 0;
    v19[0].allocedAndFlag = 20;
    v19[0].data = v19[0].baseBuffer;
    if ( (*((_BYTE *)result->pendingWeaponToEquip + 453) & 0x80) != 0 )
    {
      if ( result == (idHands *)-2996 )
      {
        idHands::GetWeaponSubWebName(this: (idHands *)0xFFFFF44C, weapon: nullptr, name: v19, secondary: false);
      }
      else
      {
        v14 = idWeapon::CastTo(c: (idWeapon *)result->rightItem.item);
        idHands::GetWeaponSubWebName(this: result, weapon: v14, name: v19, secondary: false);
      }
    }
    else
    {
      idStr::operator=(this: v19, text: "pistol");
    }
    data = v19[0].data;
    v16 = idClientGame::GetPlayerGameTime(this: clientGame);
    idAnimator_AnimWeb::Reset(
      this: &result->secondaryWeb,
      initialSubWebName: data,
      initialStateName: "idle",
      curTime: v16);
    idStr::FreeData(this: v19);
  }
  return this;
}


// ========================================================================
// __unwind$505031
// EA  : 0x82E07D90
// RVA : 0x00E07D90
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_505031()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?Serialize@idHands@@QAAXAAVidSerializer@@@Z
// EA  : 0x82E07DB8
// RVA : 0x00E07DB8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::Serialize(idHands *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  unsigned __int8 hiddenReasons; // r31

  hiddenReasons = this->hiddenReasons;
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: hiddenReasons, numBits: 8);
  else
    hiddenReasons = idBitMsg::ReadBits(this: msg, numBits: 8);
  if ( (this->hiddenReasons & 0x20) != 0 )
  {
    if ( (hiddenReasons & 0x20) == 0 )
      idHands::Reset(this, doIntro: false);
  }
  else if ( (hiddenReasons & 0x20) != 0 )
  {
    usercmdGen->ClearAngles(this: usercmdGen);
  }
  this->hiddenReasons = this->hiddenReasons & 0xC | this->hiddenReasons & 0xFFFFFFC1 | hiddenReasons & 0x32;
}


// ========================================================================
// ?RenderDebugGUI@idHands@@QAAXAAUgameReturn_t@@@Z
// EA  : 0x82E07E88
// RVA : 0x00E07E88
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::RenderDebugGUI(idHands *this, gameReturn_t *ret, unsigned __int64 a3)
{
  idHandsItem *p_leftItem; // r29
  idTreeAnimator *v6; // r3
  unsigned __int64 v7; // r6
  idRenderModelGui *v8; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  unsigned __int64 v10; // r6
  __int16 v11; // [sp+50h] [-30h] BYREF
  idRenderModelGui *v12; // [sp+54h] [-2Ch] BYREF

  switch ( hands_showBlendTree.valueInteger )
  {
    case 1:
      HIDWORD(a3) = this->web.modelAnimStates.list->tree;
      v8 = ((idRenderModelGui *(__fastcall *)(idGameAnimToolsLocal *, const char *, unsigned __int64, int))gameAnimTools->DrawBlendTree)(
             this: (idGameAnimToolsLocal *)gameAnimTools,
             name: "Player Hands",
             tree: a3,
             a4: (int)gameAnimTools->DrawBlendTree);
      goto LABEL_9;
    case 2:
      if ( idHandsItem::GetTreeAnimatorFromPresentable(this: &this->rightItem) == nullptr )
        return;
      TreeAnimatorFromPresentable = idHandsItem::GetTreeAnimatorFromPresentable(this: &this->rightItem);
      idDeclAnimWeb::FindModelIndex(
        this: (idDeclAnimWeb *)&v11,
        result: (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)this->web.decl,
        decl: TreeAnimatorFromPresentable->decl);
      LODWORD(v10) = this->web.modelAnimStates.list;
      HIDWORD(v10) = *(_DWORD *)(72 * v11 + v10);
      v8 = ((idRenderModelGui *(__fastcall *)(idGameAnimToolsLocal *, const char *, unsigned __int64, int))gameAnimTools->DrawBlendTree)(
             this: (idGameAnimToolsLocal *)gameAnimTools,
             name: "Player Right Hand Item",
             tree: v10,
             a4: (int)gameAnimTools->__vftable);
      goto LABEL_9;
    case 3:
      p_leftItem = &this->leftItem;
      if ( idHandsItem::GetTreeAnimatorFromPresentable(this: &this->leftItem) != nullptr )
      {
        v6 = idHandsItem::GetTreeAnimatorFromPresentable(this: p_leftItem);
        idDeclAnimWeb::FindModelIndex(
          this: (idDeclAnimWeb *)&v11,
          result: (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)this->web.decl,
          decl: v6->decl);
        LODWORD(v7) = this->web.modelAnimStates.list;
        HIDWORD(v7) = *(_DWORD *)(72 * v11 + v7);
        v8 = ((idRenderModelGui *(__fastcall *)(idGameAnimToolsLocal *, const char *, unsigned __int64, int))gameAnimTools->DrawBlendTree)(
               this: (idGameAnimToolsLocal *)gameAnimTools,
               name: "Player Left Hand Item",
               tree: v7,
               a4: (int)gameAnimTools->__vftable);
LABEL_9:
        v12 = v8;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&ret->debugGuis,
          obj: (encounterGroupRole_t *)&v12);
      }
      break;
    default:
      break;
  }
}


// ========================================================================
// ?StartCooking@idHands@@QAAXPBVidDeclThrowable@@PBD@Z
// EA  : 0x82E07FD8
// RVA : 0x00E07FD8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::StartCooking(idHands *this, const idDeclThrowable *throwable, const char *nextSubWebName)
{
  const idDeclThrowable *v3; // r11
  int PlayerGameTime; // r3
  const idDeclThrowable *throwItem; // r9
  const idDeclProjectile *projectileDecl; // r30
  idProjectile *v10; // r3
  idProjectile *v11; // r3
  idEntityPtr<idProjectile> *p_cookingProjectile; // r30
  idProjectile *Entity; // r3
  idPresentable *presentable; // r3
  idPresentable *v15; // r3
  int v16; // r3
  idPresentableAnimatedEntity *v17; // r3
  idTreeAnimator *TreeAnimator; // r3
  const idVec3 *p_deferredOrigin; // r31
  idProjectile *v20; // r3
  idProjectile *v21; // r3

  v3 = this->pendingAction.throwable;
  this->throwItem = throwable;
  if ( v3 != nullptr )
  {
    idPlayer::CancelSprint(this: (idPlayer *)this->owner->entity);
    this->web.throwSelector = throwable->animIndex;
    idAnimator_AnimWeb::ChangeState(
      this: &this->web,
      subWebName: nextSubWebName,
      stateName: "throwidle",
      interruptPath_: INTR_PATH_YES,
      interruptBlend_: INTR_BLEND_NO,
      blendEventMask_: 0);
    PlayerGameTime = idPresentablePlayer::GetPlayerGameTime(this: this->owner);
    throwItem = this->throwItem;
    this->cookingStartTime = PlayerGameTime;
    projectileDecl = throwItem->projectileDecl;
    if ( throwItem != nullptr && projectileDecl != nullptr )
    {
      this->cookingDetonationTime = projectileDecl->notHitscanInfo.grenadeInfo.maxDetonationDelay;
      if ( projectileDecl->notHitscanInfo.grenadeInfo.cookable )
      {
        this->cookingProjectileDecl = projectileDecl;
        if ( common->IsServer(this: common) )
        {
          v10 = (idProjectile *)gameLocal->SpawnEntityFromDef(
                                  this: gameLocal,
                                  a2: projectileDecl->notHitscanInfo.entityDef,
                                  a3: -1,
                                  a4: -1,
                                  a5: -1);
          v11 = idProjectile::CastTo(c: v10);
          p_cookingProjectile = &this->cookingProjectile;
          if ( v11 != nullptr )
            p_cookingProjectile->spawnId.value = (gameLocal->spawnIds.ptr[v11->entityNumber] << 13) | v11->entityNumber;
          else
            p_cookingProjectile->spawnId.value = 0x1FFF;
        }
        else
        {
          p_cookingProjectile = &this->cookingProjectile;
          this->cookingProjectile.spawnId.value = 0x1FFF;
        }
        if ( idEntityPtr<idProjectile>::GetEntity(this: p_cookingProjectile) != nullptr )
        {
          Entity = idEntityPtr<idProjectile>::GetEntity(this: p_cookingProjectile);
          Entity->Hide_2(this: Entity);
          presentable = idEntityPtr<idProjectile>::GetEntity(this: p_cookingProjectile)->presentable;
          if ( presentable != nullptr && presentable->GetProjectileInterface(this: presentable) != nullptr )
          {
            v15 = idEntityPtr<idProjectile>::GetEntity(this: p_cookingProjectile)->presentable;
            if ( v15 != nullptr )
              v16 = (int)v15->GetProjectileInterface(this: v15);
            else
              v16 = 0;
            *(_DWORD *)(v16 + 1252) = 0;
          }
          v17 = this->presentable;
          if ( v17 != nullptr )
            TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v17);
          else
            TreeAnimator = nullptr;
          p_deferredOrigin = &TreeAnimator->deferredOrigin;
          if ( !TreeAnimator->useDeferredPosition )
            p_deferredOrigin = &TreeAnimator->g.origin;
          v20 = idEntityPtr<idProjectile>::GetEntity(this: p_cookingProjectile);
          idEntity::SetOrigin(this: v20, org: p_deferredOrigin);
          v21 = idEntityPtr<idProjectile>::GetEntity(this: p_cookingProjectile);
          idProjectile::StartFlySound(this: v21);
        }
        else
        {
          common->IsClient(this: common);
        }
      }
    }
    else
    {
      this->cookingDetonationTime = 5000;
    }
  }
}


// ========================================================================
// ?Show@idHands@@QAAXW4handHideReason_t@1@@Z
// EA  : 0x82E08210
// RVA : 0x00E08210
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::Show(idHands *this, idHands::handHideReason_t hideReason)
{
  this->hiddenReasons &= ~hideReason;
  if ( (hideReason & 0x20) != 0 )
    idHands::Reset(this, doIntro: false);
}


// ========================================================================
// ?HandlePendingAttack@idHands@@IAA_NPAVidWeapon@@PBD_NW4handsState_t@1@@Z
// EA  : 0x82E08240
// RVA : 0x00E08240
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

int __fastcall idHands::HandlePendingAttack(
        idHands *this,
        idLaserCutter *weapon,
        const char *subWebName,
        BOOL secondary,
        idHands::handsState_t state)
{
  int v10; // r29
  int v11; // r11
  __int64 v12; // r10
  __int64 v13; // r8
  int GameMs; // r28
  idHands *ShootNodeName; // r3
  idLaserCutter *v16; // r3
  idHands *v17; // r3
  char v18; // r27
  idWeapon *v19; // r3
  idWeapon_vtbl *v20; // r27
  idInventoryCollection *v21; // r3
  idHands *v22; // r3
  idHands *v23; // r3
  idHands::handsAction_t action; // r11
  idStr v26; // [sp+60h] [-110h] BYREF
  idStr v27; // [sp+80h] [-F0h] BYREF
  idStr v28; // [sp+A0h] [-D0h] BYREF
  idStr v29; // [sp+C0h] [-B0h] BYREF
  idStr v30[4]; // [sp+E0h] [-90h] BYREF

  v10 = 0;
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->lastMeleeHitTime > hands_meleeComboInterval.valueInteger )
    this->meleeComboCount = 0;
  if ( (_cntlzw(this->pendingAction.action - 2) & 0x20) != 0 )
  {
    idAnimator_AnimWeb::ChangeStateVia(
      this: &this->web,
      subWebName,
      stateName: "idle",
      viaSubWebName: subWebName,
      viaStateName: "dryfire",
      interruptPath_: INTR_PATH_YES,
      interruptBlend_: INTR_BLEND_YES,
      blendEventMask_: 0);
LABEL_55:
    v10 = 1;
    goto LABEL_56;
  }
  if ( (unsigned __int8)idHands::AttackPending(this) != 0 )
  {
    this->weaponAnimVar = weapon->attackType == ATTACK_LEFT;
    if ( idWeapon::IsMelee(this: weapon) )
    {
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) <= this->lastAttackTime + 1500 )
      {
        v11 = this->lastAttackVariation + 1;
        this->lastAttackVariation = v11;
        if ( v11 == 3 )
          this->lastAttackVariation = 0;
      }
      else
      {
        this->lastAttackVariation = 0;
      }
    }
    else
    {
      this->lastAttackVariation = (idRandom2::RandomInt(this: &clientGame->random, min: 1, max: 2)
                                 + this->lastAttackVariation)
                                % 3;
    }
    this->lastAttackTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    LODWORD(v12) = idWeapon::GetAttackVariation(this: weapon, slot: this->lastAttackVariation);
    HIDWORD(v12) = this->owner;
    LODWORD(v13) = this->weaponAnimVar;
    this->web.attackVariation = (float)v12;
    this->web.weaponAnimVarIndex = (float)v13;
    weapon->PullTrigger(this: weapon, a2: *(idActor **)(HIDWORD(v12) + 1096), a3: secondary);
    if ( idWeapon::IsMelee(this: weapon) )
    {
      weapon->burstCount = 0;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      weapon->nextFireTime = idWeapon::GetFiringInterval(
                               this: weapon,
                               secondaryAmmo: (_cntlzw(weapon->weaponState - 1) & 0x20) != 0)
                           + GameMs;
    }
    if ( this->isZooming )
    {
      if ( idWeapon::GetLaserFire(this: weapon, secondary) )
      {
        this->isLaserFiring = true;
        idAnimator_AnimWeb::ChangeState(
          this: &this->web,
          subWebName,
          stateName: "zoomlasering",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_YES,
          blendEventMask_: 0);
        v10 = 1;
      }
      else if ( idWeapon::GetChainFire(this: weapon) )
      {
        this->isChainFiring = true;
        idAnimator_AnimWeb::ChangeState(
          this: &this->web,
          subWebName,
          stateName: "zoom_chainfire_cycle",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_YES,
          blendEventMask_: 0);
        v10 = 1;
      }
      else
      {
        if ( idWeapon::GetChargeFire(this: weapon) )
        {
          this->isChargeFiring = true;
        }
        else
        {
          ShootNodeName = idHands::GetShootNodeName(
                            this: (idHands *)&v27,
                            result: (idStr *)this,
                            stateName: "zoomshoot",
                            rightWeapon: (_cntlzw(this->pendingAction.leftHand) & 0x20) != 0,
                            secondary: this->pendingAction.isSecondary,
                            state);
          idAnimator_AnimWeb::ChangeStateVia(
            this: &this->web,
            subWebName,
            stateName: "zoomidle",
            viaSubWebName: subWebName,
            viaStateName: (const char *)ShootNodeName->listenerList,
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_YES,
            blendEventMask_: 0);
          idStr::FreeData(this: &v27);
        }
        v10 = 1;
      }
      goto LABEL_56;
    }
    if ( idPresentablePlayer::IsZoomedIn(ptr: this->owner) )
    {
      idAnimator_AnimWeb::ChangeStateVia(
        this: &this->web,
        subWebName,
        stateName: "zoomidle",
        viaSubWebName: subWebName,
        viaStateName: "zoomin_shoot",
        interruptPath_: INTR_PATH_YES,
        interruptBlend_: INTR_BLEND_YES,
        blendEventMask_: 0);
      this->isZooming = true;
      v10 = 1;
    }
    else if ( idWeapon::GetChainFire(this: weapon) )
    {
      this->isChainFiring = true;
      idAnimator_AnimWeb::ChangeState(
        this: &this->web,
        subWebName,
        stateName: "chainfire_cycle",
        interruptPath_: INTR_PATH_YES,
        interruptBlend_: INTR_BLEND_YES,
        blendEventMask_: 0);
      v10 = 1;
    }
    else
    {
      if ( !idWeapon::GetChargeFire(this: weapon) )
      {
        if ( idWeapon::GetLaserFire(this: weapon, secondary) )
        {
          this->isLaserFiring = true;
          v16 = idLaserCutter::CastTo(c: weapon);
          if ( v16 == nullptr || idLaserCutter::GetOkToFire(this: v16) )
          {
            idAnimator_AnimWeb::ChangeState(
              this: &this->web,
              subWebName,
              stateName: "lasering",
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_YES,
              blendEventMask_: 0);
            v10 = 1;
            goto LABEL_56;
          }
        }
        else
        {
          if ( this->isHandsSprinting )
          {
            v17 = idHands::GetShootNodeName(
                    this: (idHands *)&v29,
                    result: (idStr *)this,
                    stateName: "shoot",
                    rightWeapon: (_cntlzw(this->pendingAction.leftHand) & 0x20) != 0,
                    secondary,
                    state);
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->web,
              subWebName,
              stateName: "sprint",
              viaSubWebName: subWebName,
              viaStateName: (const char *)v17->listenerList,
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_YES,
              blendEventMask_: 0);
            idStr::FreeData(this: &v29);
            v10 = 1;
            goto LABEL_56;
          }
          v18 = 0;
          if ( weapon->decl[1].parent == nullptr && this->pendingAction.leftHand )
          {
            if ( secondary )
            {
              idAnimator_AnimWeb::ChangeStateVia(
                this: &this->web,
                subWebName,
                stateName: "idle",
                viaSubWebName: subWebName,
                viaStateName: "throw",
                interruptPath_: INTR_PATH_YES,
                interruptBlend_: INTR_BLEND_YES,
                blendEventMask_: 0);
              v18 = 1;
            }
            else
            {
              v19 = this->owner->GetEquippedWeapon(this: this->owner, a2: 2);
              if ( v19 != nullptr )
                secondary = (_cntlzw(v19->weaponState - 1) & 0x20) != 0;
            }
          }
          if ( v18 == 0 )
          {
            if ( weapon->decl->blockEquipIfEmpty )
            {
              v20 = (idWeapon_vtbl *)weapon->__vftable;
              v21 = this->owner->GetInventory(this: this->owner);
              if ( v20->TotalLoadedAmmoCount(this: weapon, a2: v21, a3: secondary) == 1 )
              {
                idPresentablePlayer::SelectBestWeapon(this: this->owner);
                idHands::ClearPendingAction(this);
                idHands::HandsEquipItem(this, item: this->pendingWeaponToEquip);
                idHands::UpdateWeaponCondition(this, weapon: this->pendingWeaponToEquip);
                v26.len = 0;
                v26.allocedAndFlag = 20;
                v26.data = v26.baseBuffer;
                v26.baseBuffer[0] = 0;
                idHands::GetWeaponSubWebName(this, weapon: this->pendingWeaponToEquip, name: &v26, secondary: false);
                v22 = idHands::GetShootNodeName(
                        this: (idHands *)&v28,
                        result: (idStr *)this,
                        stateName: "shoot",
                        rightWeapon: (_cntlzw(this->pendingAction.leftHand) & 0x20) != 0,
                        secondary,
                        state);
                idAnimator_AnimWeb::ChangeStateVia(
                  this: &this->web,
                  subWebName: v26.data,
                  stateName: "idle",
                  viaSubWebName: subWebName,
                  viaStateName: (const char *)v22->listenerList,
                  interruptPath_: INTR_PATH_YES,
                  interruptBlend_: INTR_BLEND_YES,
                  blendEventMask_: 0);
                idStr::FreeData(this: &v28);
                idStr::FreeData(this: &v26);
                v10 = 1;
                goto LABEL_56;
              }
            }
            v23 = idHands::GetShootNodeName(
                    this: (idHands *)v30,
                    result: (idStr *)this,
                    stateName: "shoot",
                    rightWeapon: (_cntlzw(this->pendingAction.leftHand) & 0x20) != 0,
                    secondary,
                    state);
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->web,
              subWebName,
              stateName: "idle",
              viaSubWebName: subWebName,
              viaStateName: (const char *)v23->listenerList,
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_YES,
              blendEventMask_: 0);
            idStr::FreeData(this: v30);
          }
        }
        v10 = 1;
        goto LABEL_56;
      }
      this->isChargeFiring = true;
      idAnimator_AnimWeb::ChangeState(
        this: &this->web,
        subWebName,
        stateName: "charging",
        interruptPath_: INTR_PATH_YES,
        interruptBlend_: INTR_BLEND_YES,
        blendEventMask_: 0);
      v10 = 1;
    }
  }
  else
  {
    if ( idHands::PistolWhipPending(this) )
    {
      idAnimator_AnimWeb::ChangeStateVia(
        this: &this->web,
        subWebName,
        stateName: "idle",
        viaSubWebName: subWebName,
        viaStateName: "melee",
        interruptPath_: INTR_PATH_YES,
        interruptBlend_: INTR_BLEND_NO,
        blendEventMask_: 0);
      goto LABEL_55;
    }
    action = this->pendingAction.action;
    if ( action == HANDSACTION_THROWITEM || action == HANDSACTION_COOKITEM )
    {
      idHands::StartCooking(this, throwable: this->pendingAction.throwable, nextSubWebName: subWebName);
      goto LABEL_55;
    }
  }
LABEL_56:
  if ( (_BYTE)v10 != 0 && weapon->decl != nullptr )
    this->lastWeaponUsedTime = 2 * *(_DWORD *)&weapon->decl[2].vehicleJointName.baseBuffer[12]
                             + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  return v10;
}


// ========================================================================
// __unwind$505549_0
// EA  : 0x82E089CC
// RVA : 0x00E089CC
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_505549_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 128));
}


// ========================================================================
// __unwind$505550
// EA  : 0x82E089F4
// RVA : 0x00E089F4
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_505550()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 192));
}


// ========================================================================
// __unwind$505551
// EA  : 0x82E08A1C
// RVA : 0x00E08A1C
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_505551()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$505552
// EA  : 0x82E08A44
// RVA : 0x00E08A44
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_505552()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 160));
}


// ========================================================================
// __unwind$505553
// EA  : 0x82E08A6C
// RVA : 0x00E08A6C
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_505553()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 224));
}


// ========================================================================
// ?Init@idHands@@QAAXPAVidPresentablePlayer@@PBVidDeclMD6@@PBVidDeclAnimWeb@@2PBVidDeclFX@@@Z
// EA  : 0x82E08AA0
// RVA : 0x00E08AA0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::Init(
        idHands *this,
        idPresentablePlayer *owner,
        const idDeclMD6 *declMD6,
        const idDeclAnimWeb *declAnimWeb,
        const idDeclAnimWeb *declSecondaryAnimWeb,
        const idDeclFX *setFxDecl)
{
  idPresentableAnimatedEntity *presentable; // r3
  idPresentableAnimatedEntity *v11; // r3
  idTreeAnimator *TreeAnimator; // r4
  int PlayerGameTime; // r3
  idGameTimeManager *v14; // r3
  int v15; // r3
  const idDeclAnimWeb *v16; // r10
  idGameTimeManager *v17; // r3
  const char *v18; // [sp+8h] [-138h]
  const char *v19; // [sp+8h] [-138h]
  const char *v20; // [sp+Ch] [-134h]
  const char *v21; // [sp+Ch] [-134h]
  int v22; // [sp+10h] [-130h]
  int v23; // [sp+10h] [-130h]
  int v24; // [sp+14h] [-12Ch]
  int v25; // [sp+14h] [-12Ch]
  int v26; // [sp+18h] [-128h]
  int v27; // [sp+18h] [-128h]
  int v28; // [sp+1Ch] [-124h]
  int v29; // [sp+1Ch] [-124h]
  int v30; // [sp+20h] [-120h]
  int v31; // [sp+20h] [-120h]
  int v32; // [sp+24h] [-11Ch]
  int v33; // [sp+24h] [-11Ch]
  int v34; // [sp+28h] [-118h]
  int v35; // [sp+28h] [-118h]
  int v36; // [sp+2Ch] [-114h]
  int v37; // [sp+2Ch] [-114h]
  int v38; // [sp+30h] [-110h]
  int v39; // [sp+30h] [-110h]
  int v40; // [sp+34h] [-10Ch]
  int v41; // [sp+34h] [-10Ch]
  int v42; // [sp+38h] [-108h]
  int v43; // [sp+38h] [-108h]
  int v44; // [sp+3Ch] [-104h]
  int v45; // [sp+3Ch] [-104h]
  int v46; // [sp+40h] [-100h]
  int v47; // [sp+40h] [-100h]
  int v48; // [sp+44h] [-FCh]
  int v49; // [sp+44h] [-FCh]
  int v50; // [sp+48h] [-F8h]
  int v51; // [sp+48h] [-F8h]
  int v52; // [sp+4Ch] [-F4h]
  int v53; // [sp+4Ch] [-F4h]
  int v54; // [sp+50h] [-F0h]
  int v55; // [sp+50h] [-F0h]
  int v56; // [sp+58h] [-E8h]
  int v57; // [sp+58h] [-E8h]
  int v58; // [sp+60h] [-E0h]
  int v59; // [sp+60h] [-E0h]
  int v60; // [sp+68h] [-D8h]
  int v61; // [sp+68h] [-D8h]
  idAnimatorParms_AnimWeb v62; // [sp+70h] [-D0h] BYREF

  this->owner = owner;
  if ( declMD6 != nullptr && declAnimWeb != nullptr && declSecondaryAnimWeb != nullptr )
  {
    idHands::LoadPresentable(this, modelName: declMD6->name.str);
    presentable = this->presentable;
    if ( presentable != nullptr )
      idPresentable::ResetFXMgr(this: presentable, fxDecl_: setFxDecl);
    v11 = this->presentable;
    if ( v11 != nullptr )
      TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v11);
    else
      TreeAnimator = nullptr;
    idAnimStack::Init(this: &this->animStack, treeAnimator: TreeAnimator);
    this->web.hands = this;
    this->animStack.disableSerialization = true;
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    idAnimatorParms_AnimWeb::idAnimatorParms_AnimWeb(
      this: &v62,
      animStack_: &this->animStack,
      name_: "hands",
      blendOp_: BOP_LERP,
      originBlend_: ORIGINBLEND_BRANCH,
      weightGroup_: MD6_WEIGHTGROUP_ALL,
      filterGroup_: MD6_WEIGHTGROUP_ALL,
      alpha_: 1.0,
      webDecl_: (const idDeclAnimWeb *)0x82000000,
      initialSubWebName_: v18,
      initialStateName_: v20,
      curTime_: v22,
      a13: v24,
      a14: v26,
      a15: v28,
      a16: v30,
      a17: v32,
      a18: v34,
      a19: v36,
      a20: v38,
      a21: v40,
      a22: v42,
      a23: v44,
      a24: v46,
      a25: v48,
      a26: v50,
      a27: v52,
      a28: v54,
      a29: declAnimWeb,
      a30: v56,
      a31: "knife",
      a32: v58,
      a33: "hide",
      a34: v60,
      a35: PlayerGameTime);
    v14 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->web, gametimeManager: v14, parms: &v62);
    idAnimatorParms_AnimWeb::~idAnimatorParms_AnimWeb(this: &v62);
    this->secondaryWeb.hands = this;
    v15 = idClientGame::GetPlayerGameTime(this: clientGame);
    idAnimatorParms_AnimWeb::idAnimatorParms_AnimWeb(
      this: &v62,
      animStack_: &this->animStack,
      name_: "secondaryHands",
      blendOp_: BOP_LERP,
      originBlend_: ORIGINBLEND_BRANCH,
      weightGroup_: MD6_WEIGHTGROUP_LEGS,
      filterGroup_: MD6_WEIGHTGROUP_LEGS,
      alpha_: 0.0,
      webDecl_: v16,
      initialSubWebName_: v19,
      initialStateName_: v21,
      curTime_: v23,
      a13: v25,
      a14: v27,
      a15: v29,
      a16: v31,
      a17: v33,
      a18: v35,
      a19: v37,
      a20: v39,
      a21: v41,
      a22: v43,
      a23: v45,
      a24: v47,
      a25: v49,
      a26: v51,
      a27: v53,
      a28: v55,
      a29: declSecondaryAnimWeb,
      a30: v57,
      a31: "pistol",
      a32: v59,
      a33: "idle",
      a34: v61,
      a35: v15);
    v17 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->secondaryWeb, gametimeManager: v17, parms: &v62);
    idAnimatorParms_AnimWeb::~idAnimatorParms_AnimWeb(this: &v62);
    idHands::SetModelAngles(this, angles: &this->modelAngles);
    this->hiddenReasons &= ~1u;
  }
}


// ========================================================================
// __unwind$505778
// EA  : 0x82E08C58
// RVA : 0x00E08C58
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_505778()
{
  int v0; // r12

  idAnimatorParms_AnimWeb::~idAnimatorParms_AnimWeb(this: (idAnimatorParms_AnimWeb *)(v0 - 320 + 112));
}


// ========================================================================
// __unwind$505779
// EA  : 0x82E08C80
// RVA : 0x00E08C80
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_505779()
{
  int v0; // r12

  idAnimatorParms_AnimWeb::~idAnimatorParms_AnimWeb(this: (idAnimatorParms_AnimWeb *)(v0 - 320 + 112));
}


// ========================================================================
// ?UpdateWeapon@idHands@@IAAXXZ
// EA  : 0x82E08CB0
// RVA : 0x00E08CB0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::UpdateWeapon(idHands *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idHands::handsState_t State; // r22
  idLaserCutter *v5; // r3
  idLaserCutter *v6; // r19
  idLaserCutter *v7; // r18
  __int64 v8; // r10
  int v9; // r8
  int v10; // r7
  int v11; // r6
  BOOL weaponRelaxedToggler; // r11
  idPresentablePlayer *owner; // r10
  int lastMeleeHitTime; // r11
  idUCmdTracker *p_ucmdTracker1; // r24
  char v16; // r26
  char FocusFriendly; // r21
  bool v18; // r27
  char v19; // r28
  idEntity *FocusUsable; // r3
  idProp_BatteryChargePoint *v21; // r29
  idActor *user; // r29
  int GameMs; // r3
  const idDeclInventory *v24; // r11
  const idDeclInventory *decl; // r11
  idPLogScope v26[19]; // [sp+58h] [-98h] BYREF

  RD_EventBegin(name: "idHands::UpdateWeapon");
  LODWORD(v2) = "idHands::UpdateWeapon";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v26, pl: &pLog, gMask: v2, label: v3);
  if ( this->presentable == nullptr )
    goto LABEL_117;
  State = idHands::GetState(this, animWeb: &this->web);
  v5 = (idLaserCutter *)this->owner->GetEquippedWeapon(this: this->owner, a2: 2);
  v6 = v5;
  if ( v5 == nullptr )
    goto LABEL_117;
  v7 = idLaserCutter::CastTo(c: v5);
  idHands::SetVariationIndex(this, relaxed: this->weaponRelaxedToggler, state: State, a4: v11, a5: v10, a6: v9, a7: v8);
  if ( State == HS_IDLE )
  {
    weaponRelaxedToggler = this->weaponRelaxedToggler;
    if ( weaponRelaxedToggler != this->weaponRelaxed )
      this->weaponRelaxed = weaponRelaxedToggler;
  }
  idHandsItem::UpdateJointMods(this: &this->rightItem);
  idHandsItem::UpdateJointMods(this: &this->leftItem);
  owner = this->owner;
  if ( (*((_BYTE *)&owner->ucmdTracker1.usercmd + 9) & 0x80) != 0 )
  {
    if ( this->isChainFiring )
      idHands::SetPendingAction(this, action: HANDSACTION_RETURNTOIDLE, secondary: false);
    if ( HIBYTE(v6->decl[3].internalName.data) != 0 && v6->triggerState != TRIGGERSTATE_PULLED )
      idWeapon::SlowBarrelSpinDown(this: v6);
    if ( HIBYTE(v6->decl[3].internalName.data) != 0 )
    {
      idHandsItem::WeaponBarrelSpin(this: &this->rightItem);
      idHandsItem::WeaponBarrelSpin(this: &this->leftItem);
    }
    goto LABEL_117;
  }
  if ( g_dragEntity.valueInteger != 0 )
  {
LABEL_117:
    idPLogScope::~idPLogScope(this: v26);
    goto LABEL_118;
  }
  lastMeleeHitTime = this->lastMeleeHitTime;
  p_ucmdTracker1 = &owner->ucmdTracker1;
  if ( this->lastWeaponUsedTime < lastMeleeHitTime )
    this->lastWeaponUsedTime = lastMeleeHitTime;
  if ( idPlayer::IsOnLadder(this: (idPlayer *)owner->entity)
    || (unsigned __int8)idPresentablePlayer::PlayerBehavior_Shared_ShouldHideWeapon(this: this->owner) != 0 )
  {
    if ( State != HS_HIDEMOVE && State != HS_TRANSITIONING )
      idHands::SetPendingAction(this, action: HANDSACTION_HIDEMOVE, secondary: false);
    goto LABEL_117;
  }
  v16 = idPresentablePlayer::CheckInhibitFire(this: this->owner);
  FocusFriendly = idPresentablePlayer::GetFocusFriendly(this: this->owner);
  v18 = (_cntlzw((unsigned int)v6->decl[1].parent) & 0x20) != 0;
  if ( State == HS_TRANSITIONING )
  {
LABEL_37:
    if ( this->owner->isSprinting )
    {
      if ( !this->isHandsSprinting )
      {
        if ( !v18 )
        {
          this->lastWeaponUsedTime = idGameTimeManager::GetGameMs(
                                       this: &clientGame->gameTimeManager,
                                       type: GAMETIME_SCALED);
          this->weaponRelaxed = false;
        }
        idHands::SetPendingAction(this, action: HANDSACTION_BEGINSPRINT, secondary: false);
      }
      if ( idPresentablePlayer::IsZoomedIn(ptr: this->owner) )
        idPlayer::CancelSprint(this: (idPlayer *)this->owner->entity);
      if ( LOBYTE(v6->decl[3].price) != 0 && this->currentDualWieldState != SET_DUALWIELD_ON )
      {
        idHands::HandleFire(this, state: State, friendlyTarget: FocusFriendly, inhibitFire: v16, rightWeapon: false);
        idHands::HandleFire(this, state: State, friendlyTarget: FocusFriendly, inhibitFire: v16, rightWeapon: true);
      }
      goto LABEL_117;
    }
    if ( State == HS_TRANSITIONING )
    {
      if ( v7 == nullptr || v7->weaponState == WEAPONSTATE_NORMAL )
      {
        idHands::HandleFire(
          this,
          state: HS_TRANSITIONING,
          friendlyTarget: FocusFriendly,
          inhibitFire: v16,
          rightWeapon: false);
        idHands::HandleFire(
          this,
          state: HS_TRANSITIONING,
          friendlyTarget: FocusFriendly,
          inhibitFire: v16,
          rightWeapon: true);
      }
    }
    else
    {
      if ( (unsigned int)State < HS_THROW_IDLE || State == HS_SPRINTING || State == HS_HIDEMOVE )
      {
        if ( (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: p_ucmdTracker1, mask: 0x20000000) != 0 )
        {
          idHands::SetPendingAction(this, action: HANDSACTION_TOGGLEFIREMODE, secondary: false);
        }
        else if ( (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: p_ucmdTracker1, mask: 0x10000000) != 0 )
        {
          if ( this->currentDualWieldState == SET_DUALWIELD_ON )
          {
            if ( v18 )
              idHands::SetPendingAction(
                this,
                action: HANDSACTION_TOGGLEFIREMODE,
                ammoDecl: nullptr,
                secondary: false,
                leftHand: true);
            this->dualWieldLeftHandPendingAction.action = HANDSACTION_NONE;
            this->dualWieldLeftHandPendingAction.ammoDecl = nullptr;
            this->dualWieldLeftHandPendingAction.weapon = nullptr;
            this->dualWieldLeftHandPendingAction.throwable = nullptr;
            this->dualWieldLeftHandPendingAction.useIntroBringUp = false;
            this->dualWieldLeftHandPendingAction.isSecondary = false;
            this->dualWieldLeftHandPendingAction.leftHand = false;
            idStr::Clear(this: &this->dualWieldLeftHandPendingAction.extraNodeInfo);
            this->dualWieldLeftHandPendingAction.action = HANDSACTION_TOGGLEFIREMODE;
          }
          else if ( v7 != nullptr )
          {
            idLaserCutter::NextFunctionalityLens(this: v7);
          }
        }
        else if ( (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: p_ucmdTracker1, mask: 0x100000) != 0
               && (*((_BYTE *)&v6->idWeapon + 452) & 1) != 0
               && (*((_BYTE *)this + 7912) & 4) == 0 )
        {
          idHands::SetPendingAction(this, action: HANDSACTION_TOGGLEDUALWIELD, secondary: false);
          this->lastWeaponUsedTime = idGameTimeManager::GetGameMs(
                                       this: &clientGame->gameTimeManager,
                                       type: GAMETIME_SCALED);
        }
        else
        {
          if ( idUCmdTracker::IsPressedForPlayer(this: p_ucmdTracker1, mask: 2)
            && LODWORD(v6->decl[2].droppedControllerShake.highMagnitude) != 0 )
          {
            goto LABEL_55;
          }
          idHands::HandleFire(this, state: State, friendlyTarget: FocusFriendly, inhibitFire: v16, rightWeapon: false);
          idHands::HandleFire(this, state: State, friendlyTarget: FocusFriendly, inhibitFire: v16, rightWeapon: true);
        }
        goto LABEL_88;
      }
      if ( State == HS_LASERING )
      {
        if ( idUCmdTracker::IsPressedForPlayer(this: p_ucmdTracker1, mask: 1)
          && v7 != nullptr
          && v7->batteryCount != 0
          && v16 == 0 )
        {
          if ( idLaserCutter::IsReadyToFire(this: v7) )
            idHands::FireWeapon(this, slot: EQUIP_RIGHT_HAND, secondary: true);
        }
        else
        {
          idHands::SetPendingAction(this, action: HANDSACTION_RETURNTOIDLE, secondary: true);
        }
        goto LABEL_89;
      }
    }
    if ( this->isReloading )
    {
      if ( idUCmdTracker::IsPressedForPlayer(this: p_ucmdTracker1, mask: 2)
        && LODWORD(v6->decl[2].droppedControllerShake.highMagnitude) != 0 )
      {
LABEL_55:
        idHands::PistolWhip(this);
      }
    }
    else if ( this->isChainFiring )
    {
      if ( !idUCmdTracker::IsPressedForPlayer(this: p_ucmdTracker1, mask: 1) || v16 != 0 )
        idHands::SetPendingAction(this, action: HANDSACTION_RETURNTOIDLE, secondary: false);
      else
        idHands::UpdateWeaponReload(this, weapon: v6, secondary: false, leftHand: false);
    }
LABEL_88:
    if ( State == HS_TRANSITIONING )
    {
LABEL_99:
      decl = v6->decl;
      if ( HIBYTE(decl[3].internalName.data) != 0 && v6->triggerState != TRIGGERSTATE_PULLED )
      {
        idWeapon::SlowBarrelSpinDown(this: v6);
      }
      else if ( HIBYTE(decl[3].internalName.data) != 0 && v6->triggerState == TRIGGERSTATE_PULLED )
      {
        idWeapon::SpeedBarrelSpinUp(this: v6);
      }
      if ( HIBYTE(v6->decl[3].internalName.data) != 0 )
      {
        if ( idHandsItem::WeaponBarrelSpin(this: &this->rightItem) )
          idHands::FireWeapon(this, slot: EQUIP_RIGHT_HAND, secondary: false);
        if ( idHandsItem::WeaponBarrelSpin(this: &this->leftItem) )
          idHands::FireWeapon(this, slot: EQUIP_LEFT_HAND, secondary: false);
      }
      if ( this->isHandsSprinting && this->pendingAction.action == HANDSACTION_NONE )
      {
        idHands::SetPendingAction(this, action: HANDSACTION_ENDSPRINT, secondary: false);
        this->isHandsSprinting = false;
      }
      goto LABEL_117;
    }
LABEL_89:
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v24 = v6->decl;
    if ( GameMs - this->lastWeaponUsedTime <= *(_DWORD *)&v24[2].vehicleJointName.baseBuffer[12] )
    {
      if ( v24[2].giveable && this->weaponRelaxedToggler && v7 == nullptr && FocusFriendly == 0 )
      {
        this->weaponRelaxed = false;
        idHands::SetPendingAction(this, action: HANDSACTION_RAISEWEAPON, secondary: false);
        this->lastWeaponUsedTime = idGameTimeManager::GetGameMs(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED);
      }
    }
    else if ( v24[2].giveable && !this->weaponRelaxed && State != HS_HIDEMOVE )
    {
      this->weaponRelaxed = true;
      idHands::SetPendingAction(this, action: HANDSACTION_LOWERWEAPON, secondary: false);
    }
    goto LABEL_99;
  }
  if ( v7 == nullptr )
  {
LABEL_32:
    if ( !v18 && idUCmdTracker::IsPressedForPlayer(this: p_ucmdTracker1, mask: 0x800000)
      || (int)this->owner->entity[15].clipModelInfo.overrideClipMaterial >= 1 && !v6->decl[2].dropable )
    {
      this->lastWeaponUsedTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    }
    goto LABEL_37;
  }
  v19 = 0;
  FocusUsable = idFocusTracker::GetFocusUsable(this: &this->owner->focusTracker);
  v21 = (idProp_BatteryChargePoint *)FocusUsable;
  if ( FocusUsable == nullptr
    || (unsigned __int8)idProp_BatteryChargePoint::IsTypeOf(c: FocusUsable) == 0
    || (user = idProp_BatteryChargePoint::CastTo(c: v21)->user) != idPresentableActor::GetActorEntity(this: this->owner)
    || ((double (__fastcall *)(idLaserCutter *, _DWORD))v7->AmmoInClipPercentage)(a1: v7, a2: 0) >= 1.0 )
  {
    if ( State == HS_CHARGEWEAPONBATTERY )
      v19 = 1;
    if ( v19 != 0 )
      idHands::SetPendingAction(this, action: HANDSACTION_RETURNTOIDLE, secondary: false);
    goto LABEL_32;
  }
  idHands::SetPendingAction(this, action: HANDSACTION_CHARGEWEAPONBATTERY, secondary: false);
  idPLogScope::~idPLogScope(this: v26);
LABEL_118:
  RD_EventEnd();
}


// ========================================================================
// __unwind$505832
// EA  : 0x82E09594
// RVA : 0x00E09594
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_505832()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$505833
// EA  : 0x82E095BC
// RVA : 0x00E095BC
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_505833()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 88));
}


// ========================================================================
// ?UpdateCooking@idHands@@IAAXXZ
// EA  : 0x82E095F0
// RVA : 0x00E095F0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::UpdateCooking(idHands *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int cookingStartTime; // r28
  int cookingDetonationTime; // r29
  int ServerGameTime; // r3
  __int128 v7; // r10
  __int64 v8; // fp13
  const idDeclProjectile *projectileDecl; // r26
  idSoundShader *warningSound; // r3
  int v11; // r29
  idEntityPtr<idProjectile> *p_cookingProjectile; // r3
  const idSoundShader *v13; // r30
  idProjectile *Entity; // r3
  idPLogScope v15[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idHands::UpdateCooking");
  LODWORD(v2) = "idHands::UpdateCooking";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v15, pl: &pLog, gMask: v2, label: v3);
  if ( !common->IsServer(this: common)
    || this->cookingProjectileDecl == nullptr
    || (cookingStartTime = this->cookingStartTime) <= 0
    || this->throwItem == nullptr )
  {
LABEL_15:
    idPLogScope::~idPLogScope(this: v15);
    goto LABEL_16;
  }
  cookingDetonationTime = this->cookingDetonationTime;
  if ( cookingDetonationTime <= 0
    || (ServerGameTime = idClientGame::GetServerGameTime(this: clientGame),
        LODWORD(v7) = cookingDetonationTime,
        v8 = v7,
        DWORD2(v7) = ServerGameTime,
        v15[1] = *(idPLogScope *)((char *)&v7 + 4),
        (float)((float)((float)*(__int64 *)((char *)&v7 + 4)
                      - (float)__SPAIR64__(cookingDetonationTime, cookingStartTime))
              / (float)v8) < 1.0) )
  {
    projectileDecl = this->throwItem->projectileDecl;
    if ( this->cookingProjectileDecl != nullptr && !this->playingWarningSound && cookingDetonationTime > 0 )
    {
      warningSound = projectileDecl->notHitscanInfo.grenadeInfo.warningSound;
      if ( warningSound != nullptr )
      {
        v11 = this->cookingDetonationTime + this->cookingStartTime - idSoundShader::GetMaxLength(this: warningSound);
        if ( v11 <= idClientGame::GetServerGameTime(this: clientGame)
          && idEntityPtr<idProjectile>::GetEntity(this: &this->cookingProjectile) != nullptr )
        {
          p_cookingProjectile = &this->cookingProjectile;
          this->playingWarningSound = true;
          v13 = projectileDecl->notHitscanInfo.grenadeInfo.warningSound;
          Entity = idEntityPtr<idProjectile>::GetEntity(this: p_cookingProjectile);
          idEntity::StartSoundShader(
            this: Entity,
            channel: SND_CHANNEL_BODY3,
            shader: v13,
            soundShaderFlags: (soundShaderFlags_t)0,
            peerMask: 0);
        }
      }
    }
    goto LABEL_15;
  }
  idHands::ActuallyThrowItem(this);
  idHands::Reset(this, doIntro: false);
  idPLogScope::~idPLogScope(this: v15);
LABEL_16:
  RD_EventEnd();
}


// ========================================================================
// __unwind$506082
// EA  : 0x82E097C8
// RVA : 0x00E097C8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506082()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$506083
// EA  : 0x82E097F0
// RVA : 0x00E097F0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506083()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?UpdateAnimator@idHands@@IAAXXZ
// EA  : 0x82E09820
// RVA : 0x00E09820
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __fastcall idHands::UpdateAnimator(idHands *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPresentableAnimatedEntity *presentable; // r3
  idTreeAnimator *TreeAnimator; // r26
  idPresentableAnimatedEntity *v6; // r3
  idGameTimeManager *p_gameTimeManager; // r25
  idGameTimeManager *v8; // r24
  int GameMsPerFrame; // r23
  idParallelJobList *parallelJobList; // r22
  int PreviousPlayerGameTime; // r21
  int PlayerGameTime; // r3
  const idDeclMD6 *decl; // r28
  int v14; // r24
  idMD6Node *tree; // r25
  const char *v16; // r30
  const char *v17; // r3
  float *v18; // [sp+8h] [-E8h]
  float *v19; // [sp+Ch] [-E4h]
  float *v20; // [sp+10h] [-E0h]
  idPLogScope v21[15]; // [sp+78h] [-78h] BYREF

  RD_EventBegin(name: "idHands::UpdateAnimator");
  LODWORD(v2) = "idHands::UpdateAnimator";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v21, pl: &pLog, gMask: v2, label: v3);
  if ( hands_updateAnim.valueInteger != 0 )
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
      TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: presentable);
    else
      TreeAnimator = nullptr;
    v6 = this->presentable;
    if ( v6 != nullptr )
      idPresentable::UpdateModelTransform(this: v6);
    if ( hands_blendTree.valueInteger != 0 )
    {
      p_gameTimeManager = &clientGame->gameTimeManager;
      v8 = (idGameTimeManager *)(timeManager.gameTimePerFrame.value * timeManager.gameHz);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      parallelJobList = gameLocal->parallelJobList;
      PreviousPlayerGameTime = idClientGame::GetPreviousPlayerGameTime(this: clientGame);
      PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
      idAnimStack::BlendStackInternal(
        this: &this->animStack,
        currentTime: PlayerGameTime,
        previousTime: PreviousPlayerGameTime,
        gameMsPerFrame: GameMsPerFrame,
        ticksPerSec: v8,
        game: p_gameTimeManager,
        parallelJobList,
        localR: nullptr,
        localS: v18,
        localT: v19,
        localU: v20);
    }
    v14 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    decl = TreeAnimator->decl;
    tree = this->animStack.tree;
    v16 = (const char *)idClientGame::GetPreviousPlayerGameTime(this: clientGame);
    v17 = (const char *)idClientGame::GetPlayerGameTime(this: clientGame);
    idAnimEventHandler::BuildAnimEventList(
      this: &this->animEventHandler,
      decl,
      tree,
      curTime: v17,
      previousTime: v16,
      ticksPerSec: v14,
      onlyEvents: nullptr,
      onlyNumEvents: 0);
    idEventReceiver::ProcessAnimEvents(this, handler: &this->animEventHandler);
    if ( this->owner->entityNumber == g_debugAnim.valueInteger && hands_debugweb.valueInteger != 0 )
      gameAnimTools->AnimDebugHud(this: gameAnimTools, a2: this, a3: TreeAnimator, a4: this->animStack.tree);
  }
  idPLogScope::~idPLogScope(this: v21);
  RD_EventEnd();
}


// ========================================================================
// __unwind$506144
// EA  : 0x82E09A20
// RVA : 0x00E09A20
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506144()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$506145
// EA  : 0x82E09A48
// RVA : 0x00E09A48
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506145()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 120));
}


// ========================================================================
// ?Update@idHands@@QAAXXZ
// EA  : 0x82E09A78
// RVA : 0x00E09A78
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idHands::Update(idHands *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idLobbyBase *v4; // r3
  idPresentableAnimatedEntity *presentable; // r3
  idPresentablePlayer *owner; // r11
  swimdepthstate_t currentSwimDepthState; // r27
  double v8; // fp31
  double v9; // fp31
  idPresentable *v10; // r3
  idPresentablePlayer *v11; // r3
  idHands::handsState_t v12; // r11
  idPresentableAnimatedEntity *v13; // r10
  double valueFloat; // fp31
  idWeapon *v15; // r3
  idWeapon *v16; // r15
  char garageIcon_high; // r29
  idHands::handsTCAnglesBlendState_t handsTCAnglesBlendState; // r11
  idPresentable *v19; // r3
  idPresentablePlayer *v20; // r3
  idPresentablePlayer *v21; // r10
  idPresentable *v22; // r3
  idPresentablePlayer *v23; // r3
  double v24; // fp27
  double v25; // fp1
  double x; // fp0
  double z; // fp12
  double v28; // fp0
  double v29; // fp13
  int value; // r11
  idDeclAnimWebNode *v31; // r21
  char *SubWebName; // r24
  BOOL isInTown; // r10
  char v34; // r11
  int State; // r3
  int hiddenReasons; // r8
  idHands::handsState_t v37; // r25
  idHands::handsAction_t action; // r4
  float *v39; // r3
  int valueInteger; // r29
  idHands *v41; // r3
  bool v42; // zf
  idAmmoItem *ammoClipSecondary; // r11
  const idDeclAmmo *ammoDecl; // r4
  bool isSecondary; // r29
  idWeapon *v46; // r4
  idHands *v47; // r3
  char v48; // r10
  idAnimWebHands *p_web; // r3
  idHands::handsAction_t v50; // r11
  __int64 v51; // r9 OVERLAPPED
  __int64 v52; // r9
  __int64 v53; // r10
  burstMode_t v54; // r3
  burstMode_t v55; // r29
  idAmmoItem *ammoClip; // r11
  int burstMode; // r11
  BOOL leftHand; // r10
  __int64 v59; // r9
  const char *v60; // r7
  __int64 v61; // r9
  const idStr *v62; // r3
  idHands::handsAction_t v63; // r11
  idHands::handsAction_t v64; // r11
  idAmmoItem *v65; // r11
  idHands::handsAction_t v66; // r11
  idHands::handsAction_t v67; // r9
  int buttons; // r11
  int v69; // r11
  int GameMs; // r29
  int GameMsPerFrame; // r3
  int lastOnLadderTime; // r11
  const idDeclInventory *decl; // r29
  idHands::handsAction_t v74; // r10
  __int64 v75; // r9
  idHands::handsAction_t v76; // r11
  idHands::handsAction_t v77; // r11
  idAnimWebHands *v78; // r3
  idHands::handsAction_t v79; // r11
  idAnimWebHands *v80; // r3
  int currentVariationIndex; // r10
  char v82; // r28
  idEntity *FocusUsable; // r3
  idProp_BatteryChargePoint *v84; // r29
  idProp_BatteryChargePoint *v85; // r29
  idActor *user; // r27
  idLaserCutter *v87; // r3
  idLaserCutter *v88; // r3
  int v89; // r3
  int lastChargetTime; // r11
  __int64 v91; // r10
  const idDeclAmmo *nextAmmo; // r29
  idAmmoItem *v93; // r11
  const idDeclAmmo *v94; // r11
  bool v95; // r28
  idAmmoItem *v96; // r11
  const idDeclInventory *v97; // r11
  idAmmoItem *v98; // r11
  const idDeclInventory *v99; // r11
  const idInventoryCollection *v100; // r3
  bool CanReload; // r3
  char v102; // r11
  char v103; // r29
  idAmmoItem *v104; // r11
  const idDeclInventory *v105; // r11
  idAmmoItem *v106; // r11
  const idDeclInventory *v107; // r11
  idAmmoItem *v108; // r11
  const idDeclInventory *v109; // r11
  idAmmoItem *v110; // r11
  const idDeclInventory *v111; // r11
  idHands::handsAction_t v112; // r11
  idAmmoItem *v113; // r11
  bool v114; // r29
  idWeapon *v115; // r4
  idHands *v116; // r3
  idHands::handsAction_t v117; // r11
  bool v118; // r6
  __int64 v119; // r8
  idWeapon *weapon; // r4
  idStr *v121; // r3
  idAmmoItem *v122; // r11
  const idDeclInventory *v123; // r11
  idAmmoItem *v124; // r11
  const idDeclInventory *v125; // r11
  idHands *ReloadNodeName; // r3
  idAmmoItem *v127; // r11
  idAmmoItem *v128; // r11
  idAmmoItem *v129; // r11
  bool v130; // r29
  idWeapon *v131; // r4
  idHands::handsAction_t v132; // r11
  idHands::handsAction_t v133; // r11
  idAmmoItem *v134; // r11
  bool v135; // r29
  idWeapon *v136; // r4
  idHands *v137; // r3
  idHands::handsAction_t v138; // r11
  bool v139; // r6
  __int64 v140; // r8
  idWeapon *v141; // r4
  idStr *v142; // r3
  const idDeclInventory *v143; // r11
  int v144; // r27
  int v145; // r28
  idAmmoItem *v146; // r10
  idAmmoItem *v147; // r3
  const char *str; // r10
  bool v149; // r29
  idWeapon *v150; // r4
  idHands::handsAction_t v151; // r11
  BOOL isChainFiring; // r11
  char v153; // r29
  idHands::handsAction_t v154; // r11
  bool v155; // r28
  idWeapon *v156; // r4
  idStr *v157; // r3
  __int64 v158; // r8
  idAmmoItem *v159; // r11
  const idDeclAmmo *v160; // r4
  bool v161; // r28
  idWeapon *v162; // r4
  idHands *v163; // r3
  idHands::handsAction_t v164; // r11
  bool v165; // r6
  idWeapon *v166; // r4
  __int64 v167; // r9
  __int64 v168; // r9
  const char *StateName; // r3
  bool HasJumped; // r28
  float *v171; // r3
  bool v172; // r29
  idWeapon *v173; // r4
  idHands::handsAction_t v174; // r11
  idAnimWebHands *v175; // r3
  bool IsZoomedIn; // r3
  const char *v177; // r5
  idHands::handsAction_t v178; // r11
  bool v179; // r28
  idWeapon *v180; // r4
  idStr *v181; // r3
  __int64 v182; // r8
  idAmmoItem *v183; // r11
  const idDeclAmmo *v184; // r4
  idHands *v185; // r3
  idHands::handsAction_t v186; // r11
  bool v187; // r6
  idWeapon *v188; // r4
  __int64 v189; // r9
  bool v190; // r29
  idWeapon *v191; // r4
  idHands::handsAction_t v192; // r11
  idHands::handsAction_t v193; // r11
  BOOL isZooming; // r11
  const char *v195; // r5
  __int128 v196; // r11
  usercmd_t *p_usercmd; // r29
  double v198; // fp5
  double v199; // fp7
  double v202; // fp12
  long double v203; // fp2
  double v204; // fp13
  double v205; // fp12
  double v206; // fp31
  __int64 v207; // r8
  double v208; // fp1
  idHands::handsState_t currentSwimState; // r11
  double v210; // fp0
  idPresentablePlayer *v211; // r3
  idInventoryCollection *v212; // r3
  idWeapon *InventoryItemByName; // r3
  idHands::handsState_t v214; // r9
  int upmove; // r10
  idEntity *entity; // r24
  BOOL v217; // r11
  char *data; // r28
  int PlayerGameTime; // r3
  idStr *v220; // r3
  int v221; // r11
  idDeclAnimWebNode *v222; // r11
  const char *v223; // r3
  float v224; // r29
  idPresentablePlayer *v225; // r3
  idUCmdTracker *p_ucmdTracker1; // r25
  idWeapon *v227; // r3
  idWeapon *v228; // r29
  char v229; // r26
  idHands::handsAction_t v230; // r11
  const char *v231; // r5
  idStr *v232; // r3
  burstMode_t v233; // r28
  unsigned int v234; // r3
  char *v235; // r6
  const char *v236; // r7
  __int64 v237; // r3
  char *v238; // r4
  int v239; // r9
  __int64 v240; // r6
  idPresentablePlayer *v241; // r4
  double v242; // fp13
  idHands *ShootNodeName; // r3
  idDeclInventory *v244; // r11
  BOOL giveable; // r10
  BOOL dropable; // r10
  int v247; // r11
  const idDeclThrowable *throwItem; // [sp+50h] [-590h]
  bool v249; // [sp+58h] [-588h] BYREF
  idHands::handsState_t v250; // [sp+5Ch] [-584h]
  idHands::idHandsAction *p_dualWieldLeftHandPendingAction; // [sp+60h] [-580h]
  idMat3 v252; // [sp+70h] [-570h] BYREF
  idAngles v253; // [sp+98h] [-548h] BYREF
  idAngles v254; // [sp+A8h] [-538h] BYREF
  idStr v255; // [sp+C0h] [-520h] BYREF
  idStr v256; // [sp+E0h] [-500h] BYREF
  idStr v257; // [sp+100h] [-4E0h] BYREF
  idStr v258; // [sp+120h] [-4C0h] BYREF
  idStr v259; // [sp+140h] [-4A0h] BYREF
  idStr v260; // [sp+160h] [-480h] BYREF
  idStr v261; // [sp+180h] [-460h] BYREF
  idStr v262; // [sp+1A0h] [-440h] BYREF
  idStr v263; // [sp+1C0h] [-420h] BYREF
  idStr v264; // [sp+1E0h] [-400h] BYREF
  idStr v265; // [sp+200h] [-3E0h] BYREF
  idStr v266; // [sp+220h] [-3C0h] BYREF
  idStr v267; // [sp+240h] [-3A0h] BYREF
  idStr v268; // [sp+260h] [-380h] BYREF
  idStr v269; // [sp+280h] [-360h] BYREF
  idStr v270; // [sp+2A0h] [-340h] BYREF
  idStr v271; // [sp+2C0h] [-320h] BYREF
  idStr v272; // [sp+2E0h] [-300h] BYREF
  idStr v273; // [sp+300h] [-2E0h] BYREF
  idStr v274; // [sp+320h] [-2C0h] BYREF
  idStr v275; // [sp+340h] [-2A0h] BYREF
  idStr v276; // [sp+360h] [-280h] BYREF
  idStr v277; // [sp+380h] [-260h] BYREF
  idStr v278; // [sp+3A0h] [-240h] BYREF
  blendParms_t v279; // [sp+3C0h] [-220h] BYREF
  idStr v280; // [sp+3E0h] [-200h] BYREF
  int v281; // [sp+400h] [-1E0h] BYREF
  _BYTE v282[32]; // [sp+410h] [-1D0h] BYREF
  idStr v283; // [sp+430h] [-1B0h] BYREF
  idStr v284; // [sp+450h] [-190h] BYREF
  idStr v285; // [sp+470h] [-170h] BYREF
  idStr v286; // [sp+490h] [-150h] BYREF
  idStr v287; // [sp+4B0h] [-130h] BYREF
  idStr v288; // [sp+4D0h] [-110h] BYREF
  idStr v289[2]; // [sp+4F0h] [-F0h] BYREF

  RD_EventBegin(name: "idHands::Update");
  LODWORD(v2) = "idHands::Update";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v252.mat[2], pl: &pLog, gMask: v2, label: v3);
  if ( common->IsMultiplayer(this: common) )
  {
    v4 = session->GetActivePlatformLobbyBase(this: session);
    if ( v4->GetMatchParms(this: v4)->gameType == 2 )
      goto LABEL_711;
  }
  if ( this->disabled )
    goto LABEL_711;
  if ( this->presentable == nullptr )
    goto LABEL_711;
  this->web.debug = hands_debugweb.valueInteger != 0;
  this->secondaryWeb.debug = hands_debugweb.valueInteger != 0;
  idHands::UpdateHidden(this);
  presentable = this->presentable;
  if ( presentable == nullptr || idPresentableAnimatedEntity::GetTreeAnimator(this: presentable) == nullptr )
    goto LABEL_711;
  owner = this->owner;
  currentSwimDepthState = owner->physicsObj.currentSwimDepthState;
  if ( this->hiddenReasons == 64 || idPlayer::IsOnLadder(this: (idPlayer *)owner->entity) )
  {
    currentSwimDepthState = SWIMDEPTH_STATE_NONE;
    if ( this->currentSwimState != HS_IDLE )
    {
      this->lastSwimDepthState = SWIMDEPTH_STATE_NONE;
      idPresentable::StopFX(this: this->presentable, condition: 132, extraCondition: FX_EXTRA_COND_NONE);
      this->currentSwimState = HS_IDLE;
      idHands::ResetAnimWeb(this);
    }
    goto LABEL_39;
  }
  if ( currentSwimDepthState != this->lastSwimDepthState )
  {
    idPresentable::StopFX(this: this->presentable, condition: 132, extraCondition: FX_EXTRA_COND_NONE);
    if ( currentSwimDepthState == SWIMDEPTH_STATE_ON_SURFACE )
    {
      if ( this->lastSwimDepthState == SWIMDEPTH_STATE_NONE )
      {
        this->lastSwimDepthState = SWIMDEPTH_STATE_ON_SURFACE;
        this->currentSwimState = HS_SWIMMING_ENTER;
        goto LABEL_39;
      }
      v13 = this->presentable;
      this->currentSwimState = HS_SWIMMING_SURFACE;
      v13->model->g.modelDepthHack = hands_depthHackSwim.valueFloat;
      if ( this != (idHands *)-2996
        && idHandsItem::GetPresentable(this: &this->rightItem) != nullptr
        && idHandsItem::GetPresentable(this: &this->rightItem)->model != nullptr )
      {
        valueFloat = hands_depthHackSwim.valueFloat;
        idHandsItem::GetPresentable(this: &this->rightItem)->model->g.modelDepthHack = valueFloat;
      }
    }
    else
    {
      this->presentable->model->g.modelDepthHack = hands_depthHack.valueFloat;
      if ( currentSwimDepthState != SWIMDEPTH_STATE_UNDER_SURFACE )
      {
        if ( this != (idHands *)-2996
          && idHandsItem::GetPresentable(this: &this->rightItem) != nullptr
          && idHandsItem::GetPresentable(this: &this->rightItem)->model != nullptr )
        {
          v8 = hands_depthHack.valueFloat;
          idHandsItem::GetPresentable(this: &this->rightItem)->model->g.modelDepthHack = v8;
        }
        this->lastSwimDepthState = currentSwimDepthState;
        this->currentSwimState = HS_SWIMMING_EXIT;
        goto LABEL_39;
      }
      if ( this != (idHands *)-2996
        && idHandsItem::GetPresentable(this: &this->rightItem) != nullptr
        && idHandsItem::GetPresentable(this: &this->rightItem)->model != nullptr )
      {
        v9 = hands_depthHack.valueFloat;
        idHandsItem::GetPresentable(this: &this->rightItem)->model->g.modelDepthHack = v9;
      }
      v10 = this->owner->entity->presentable;
      if ( v10 != nullptr )
        v11 = v10->GetPlayerInterface_2(this: v10);
      else
        v11 = nullptr;
      idPresentablePlayer::ResetLocalViewLimits(this: v11);
      v12 = HS_SWIMMING_ENTER;
      if ( this->lastSwimDepthState != SWIMDEPTH_STATE_NONE )
        v12 = HS_SWIMMING_SUBMERGE;
      this->currentSwimState = v12;
      if ( this->handsTCAnglesBlendState >= (unsigned int)HANDSTCBLENDSTATE_OUT )
      {
        this->handsTCAnglesBlendState = HANDSTCBLENDSTATE_IN;
        this->lastSwimDepthState = SWIMDEPTH_STATE_UNDER_SURFACE;
        goto LABEL_39;
      }
    }
    this->lastSwimDepthState = currentSwimDepthState;
  }
LABEL_39:
  v15 = this->owner->GetEquippedWeapon(this: this->owner, a2: 2);
  v16 = v15;
  if ( v15 != nullptr )
    garageIcon_high = HIBYTE(v15->decl[1].garageIcon);
  else
    garageIcon_high = 0;
  if ( currentSwimDepthState == SWIMDEPTH_STATE_ON_SURFACE || garageIcon_high != 0 )
  {
    if ( this->handsTCAnglesBlendState >= (unsigned int)HANDSTCBLENDSTATE_OUT )
    {
      v21 = this->owner;
      v253.roll = 0.0;
      v254.yaw = 180.0;
      v254.roll = 0.0;
      this->handsTCAnglesBlendState = HANDSTCBLENDSTATE_IN;
      v253.yaw = -180.0;
      v253.pitch = -89.0;
      v254.pitch = 45.0;
      v22 = v21->entity->presentable;
      if ( v22 != nullptr )
        v23 = v22->GetPlayerInterface_2(this: v22);
      else
        v23 = nullptr;
      idPresentablePlayer::SetLocalViewLimits(this: v23, minAngles: &v253, maxAngles: &v254);
    }
  }
  else if ( currentSwimDepthState == SWIMDEPTH_STATE_NONE )
  {
    handsTCAnglesBlendState = this->handsTCAnglesBlendState;
    if ( handsTCAnglesBlendState != HANDSTCBLENDSTATE_OUT_FULL && handsTCAnglesBlendState != HANDSTCBLENDSTATE_OUT )
    {
      v19 = this->owner->entity->presentable;
      if ( v19 != nullptr )
      {
        v20 = v19->GetPlayerInterface_2(this: v19);
        idPresentablePlayer::ResetLocalViewLimits(this: v20);
      }
      else
      {
        idPresentablePlayer::ResetLocalViewLimits(this: nullptr);
      }
      this->handsTCAnglesBlendState = HANDSTCBLENDSTATE_OUT;
    }
  }
  v24 = 0.0;
  if ( this->handsTCAnglesBlendState != HANDSTCBLENDSTATE_OUT_FULL )
  {
    idMat3::ToAngles(this: &v252, result: (idAngles *)&this->owner->firstPersonViewAxis);
    v25 = idMath::AngleNormalize360(angle: (float)(v252.mat[0].y - this->handsTCAngles.yaw));
    if ( v25 > 180.0 )
      v25 = (float)((float)v25 - (float)360.0);
    v24 = v25;
    if ( currentSwimDepthState == SWIMDEPTH_STATE_ON_SURFACE || garageIcon_high != 0 )
      x = 0.0;
    else
      x = v252.mat[0].x;
    z = v252.mat[0].z;
    this->handsTCAngles.pitch = x;
    this->handsTCAngles.roll = z;
    if ( __fabs(v25) >= 0.000099999997 )
    {
      if ( (_S18_20 & 1) != 0 )
      {
        v28 = maxAngle;
      }
      else
      {
        _S18_20 |= 1u;
        if ( currentSwimDepthState != SWIMDEPTH_STATE_NONE )
        {
          v28 = 34.0;
          maxAngle = 34.0;
        }
        else
        {
          maxAngle = 0.0;
          v28 = 0.0;
        }
      }
      v29 = 0.0;
      if ( v25 <= v28 )
      {
        if ( v25 < -v28 )
          v29 = (float)((float)v25 + (float)v28);
      }
      else
      {
        v29 = (float)((float)v25 - (float)v28);
      }
      this->handsTCAngles.yaw = (float)((float)((float)v25 * speeder) + this->handsTCAngles.yaw) + (float)v29;
    }
    else
    {
      this->handsTCAngles.yaw = v252.mat[0].y;
    }
  }
  this->presentable->model->useDeferredPosition = false;
  value = this->web.curNodeIndex.value;
  if ( value == -1 )
    v31 = nullptr;
  else
    v31 = this->web.decl->nodes.list[value];
  SubWebName = (char *)idDeclAnimWeb::GetSubWebName(
                         this: this->web.decl,
                         index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v31->subWebIndex.value);
  if ( v16 != nullptr )
  {
    if ( idWeapon::AmmoInClip(this: v16, secondaryAmmo: false) != 0 )
      this->web.idleSelector = 0.0;
    else
      this->web.idleSelector = 1.0;
  }
  isInTown = this->isInTown;
  this->web.zoomSelector = 0.0;
  v34 = 1;
  if ( isInTown )
  {
    if ( !this->weaponRelaxed && idHands::GetState(this, animWeb: &this->web) != 3 )
    {
      this->weaponRelaxed = true;
      idHands::SetPendingAction(this, action: HANDSACTION_LOWERWEAPON, secondary: false);
    }
    v34 = 0;
  }
  if ( v34 != 0 )
    idHands::UpdateWeapon(this);
  idHands::UpdateCooking(this);
  idHands::UpdateMeleeTrace(this);
  State = idHands::GetState(this, animWeb: &this->web);
  hiddenReasons = this->hiddenReasons;
  v250 = State;
  v37 = State;
  LODWORD(v252.mat[2].z) = "hide";
  p_dualWieldLeftHandPendingAction = (idHands::idHandsAction *)"toggleWeaponMode";
  if ( hiddenReasons != 0 && State != 7 )
  {
    blendParms_t::blendParms_t(this: &v279);
    blendParms_t::SetDuration(this: &v279, frame: 0);
    idAnimator_AnimWeb::ForceState(
      this: &this->web,
      subWebName: SubWebName,
      stateName: "hide",
      blendParms: &v279,
      blendEventMask_: 0);
    v37 = HS_HIDEMOVE;
    v250 = HS_HIDEMOVE;
    idHands::ClearPendingAction(this);
  }
  switch ( v37 )
  {
    case HS_IDLE:
      if ( hands_debugstate.valueInteger != 0 )
        idLib::Printf(fmt: "State: HS_IDLE\n");
      this->isInterruptableTransition = false;
      this->isChainFiring = false;
      this->isChargeFiring = false;
      this->isLaserFiring = false;
      this->isReloading = false;
      this->isInReloadOut = false;
      this->isZooming = false;
      this->isInEndSprint = false;
      this->isHandsSprinting = false;
      this->isWeaponBringUp = false;
      this->cookingProjectile.spawnId.value = 0x1FFF;
      this->cookingProjectileDecl = nullptr;
      this->canInteruptCooking = false;
      this->isInAccentIdle = false;
      this->isChangingAmmo = false;
      this->cookingStartTime = 0;
      this->throwItem = nullptr;
      if ( this->pendingAction.action == HANDSACTION_NONE )
      {
        action = this->lingeringAction.action;
        if ( action != HANDSACTION_NONE )
        {
          idHands::SetPendingAction(
            this,
            action,
            ammoDecl: this->lingeringAction.ammoDecl,
            secondary: this->lingeringAction.isSecondary,
            leftHand: this->lingeringAction.leftHand);
          this->lingeringAction.action = HANDSACTION_NONE;
          this->lingeringAction.ammoDecl = nullptr;
          this->lingeringAction.weapon = nullptr;
          this->lingeringAction.throwable = nullptr;
          this->lingeringAction.useIntroBringUp = false;
          this->lingeringAction.isSecondary = false;
          this->lingeringAction.leftHand = false;
          idStr::Clear(this: &this->lingeringAction.extraNodeInfo);
        }
      }
      if ( this->pendingAction.action != HANDSACTION_NONE || idPresentablePlayer::IsZoomedIn(ptr: this->owner) )
      {
        if ( (_cntlzw(this->pendingAction.action - 15) & 0x20) != 0 )
        {
          idHands::ClearPendingAction(this);
          idAnimator_AnimWeb::ChangeStateVia(
            this: &this->web,
            subWebName: SubWebName,
            stateName: "idle",
            viaSubWebName: SubWebName,
            viaStateName: "takedown",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
        }
        else
        {
          v42 = (unsigned __int8)idHands::ReloadPending(this) == 0;
          v41 = this;
          if ( !v42 )
            goto LABEL_110;
          if ( (unsigned __int8)idHands::AmmoChangePending(this) != 0 )
          {
            if ( this->pendingAction.isSecondary )
              ammoClipSecondary = v16->ammoClipSecondary;
            else
              ammoClipSecondary = v16->ammoClip;
            ammoDecl = this->pendingAction.ammoDecl;
            if ( ammoClipSecondary->decl != ammoDecl )
            {
              idWeapon::BeginReloading(this: v16, ammoDecl, secondaryAmmo: this->pendingAction.isSecondary);
              v262.len = 0;
              v262.data = v262.baseBuffer;
              v262.allocedAndFlag = 20;
              v262.baseBuffer[0] = 0;
              isSecondary = this->pendingAction.isSecondary;
              if ( this == (idHands *)-2996 )
                v46 = nullptr;
              else
                v46 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
              idHands::GetWeaponSubWebName(this, weapon: v46, name: &v262, secondary: isSecondary);
              v47 = idHands::GetAmmoChangeNodeName(
                      this: (idHands *)&v286,
                      result: this,
                      secondary: this->pendingAction.isSecondary,
                      leftHand: this->pendingAction.leftHand);
              idAnimator_AnimWeb::ChangeStateVia(
                this: &this->web,
                subWebName: v262.data,
                stateName: "idle",
                viaSubWebName: SubWebName,
                viaStateName: (const char *)v47->listenerList,
                interruptPath_: INTR_PATH_YES,
                interruptBlend_: INTR_BLEND_NO,
                blendEventMask_: 0);
              idStr::FreeData(this: &v286);
              this->isReloading = true;
              this->isChangingAmmo = true;
              idStr::FreeData(this: &v262);
            }
            goto LABEL_602;
          }
          if ( (unsigned __int8)idHands::AttackPending(this) != 0 )
          {
            if ( (unsigned __int8)idHands::HandlePendingAttack(
                                    this,
                                    weapon: (idLaserCutter *)v16,
                                    subWebName: SubWebName,
                                    secondary: this->pendingAction.isSecondary,
                                    state: HS_IDLE) != 0 )
              goto LABEL_602;
          }
          else if ( !idPresentablePlayer::IsZoomedIn(ptr: this->owner)
                 || idPlayer::IsOnLadder(this: (idPlayer *)this->owner->entity) )
          {
            v50 = this->pendingAction.action;
            if ( (_cntlzw(v50 - 6) & 0x20) != 0 || (_cntlzw(v50 - 7) & 0x20) != 0 )
              goto LABEL_241;
            LOBYTE(v51) = _cntlzw(v50 - 12);
            HIDWORD(v51) = (v51 & 0x20) != 0;
            if ( (v51 & 0x20) != 0 )
              goto LABEL_261;
            LOBYTE(v51) = _cntlzw(v50 - 11);
            HIDWORD(v51) = (v51 & 0x20) != 0;
            if ( (v51 & 0x20) != 0 )
              goto LABEL_261;
            if ( (_cntlzw(v50 - 13) & 0x20) != 0 )
            {
              this->isHandsSprinting = true;
              idAnimator_AnimWeb::ChangeState(
                this: &this->web,
                subWebName: SubWebName,
                stateName: "sprint",
                interruptPath_: INTR_PATH_YES,
                interruptBlend_: INTR_BLEND_NO,
                blendEventMask_: 0);
              idHands::ClearPendingAction(this);
            }
            else
            {
              if ( (_cntlzw(v50 - 10) & 0x20) != 0 )
                goto LABEL_602;
              if ( (_cntlzw(v50 - 16) & 0x20) != 0 )
              {
                idAnimator_AnimWeb::ChangeStateVia(
                  this: &this->web,
                  subWebName: SubWebName,
                  stateName: "hide",
                  viaSubWebName: SubWebName,
                  viaStateName: "hide_in",
                  interruptPath_: INTR_PATH_YES,
                  interruptBlend_: INTR_BLEND_NO,
                  blendEventMask_: 0);
                idHands::ClearPendingAction(this);
              }
              else
              {
                LOBYTE(v52) = _cntlzw(v50 - 17);
                HIDWORD(v52) = (v52 & 0x20) != 0;
                if ( (v52 & 0x20) != 0 )
                {
                  LODWORD(v52) = this->currentVariationIndex;
                  this->web.previousVariationIndex = (float)v52;
                  idAnimator_AnimWeb::ChangeStateVia(
                    this: &this->web,
                    subWebName: SubWebName,
                    stateName: "idle",
                    viaSubWebName: SubWebName,
                    viaStateName: "toggledualwield",
                    interruptPath_: INTR_PATH_YES,
                    interruptBlend_: INTR_BLEND_NO,
                    blendEventMask_: 0);
                  idHands::ClearPendingAction(this);
                }
                else
                {
                  HIDWORD(v53) = _cntlzw(v50 - 18);
                  if ( (v53 & 0x2000000000LL) != 0 )
                  {
                    LODWORD(v53) = this->currentVariationIndex;
                    this->web.previousVariationIndex = (float)v53;
                    v54 = idWeapon::ToggleFireMode(this: v16, justFetchNextMode: true, ignoreMode: false);
                    v55 = v54;
                    if ( v16->weaponState == WEAPONSTATE_SECONDARY )
                      ammoClip = v16->ammoClipSecondary;
                    else
                      ammoClip = v16->ammoClip;
                    if ( ammoClip != nullptr )
                      burstMode = ammoClip->burstMode;
                    else
                      burstMode = v16->decl[1].attachmentInfo.num;
                    if ( v54 != burstMode )
                    {
                      leftHand = this->pendingAction.leftHand;
                      HIDWORD(v59) = 1;
                      LODWORD(v59) = this->currentVariationIndex;
                      this->web.previousVariationIndex = (float)v59;
                      if ( leftHand )
                        v60 = "toggleWeaponModeDWLeft";
                      else
                        v60 = "toggleWeaponMode";
                      idAnimator_AnimWeb::ChangeStateVia(
                        this: &this->web,
                        subWebName: SubWebName,
                        stateName: "idle",
                        viaSubWebName: SubWebName,
                        viaStateName: v60,
                        interruptPath_: INTR_PATH_YES,
                        interruptBlend_: INTR_BLEND_NO,
                        blendEventMask_: 0);
                    }
                    if ( v55 != BURSTMODE_MAX )
                      idWeapon::ToggleFireMode(this: v16, justFetchNextMode: false, ignoreMode: false);
                    goto LABEL_602;
                  }
                  LOBYTE(v61) = _cntlzw(v50 - 19);
                  HIDWORD(v61) = (v61 & 0x20) != 0;
                  if ( (v61 & 0x20) != 0 )
                  {
                    idAnimator_AnimWeb::ChangeState(
                      this: &this->web,
                      subWebName: SubWebName,
                      stateName: "chargebattery",
                      interruptPath_: INTR_PATH_YES,
                      interruptBlend_: INTR_BLEND_NO,
                      blendEventMask_: 0);
                    idHands::ClearPendingAction(this);
                  }
                  else
                  {
                    if ( (_cntlzw(v50 - 20) & 0x20) == 0 )
                      goto LABEL_602;
                    LODWORD(v61) = this->currentVariationIndex;
                    this->web.previousVariationIndex = (float)v61;
                    operator+(result: &v280, a: "upgradeweapon", b: &this->pendingAction.extraNodeInfo);
                    if ( idLaserCutter::CastTo(c: (idLaserCutter *)v16) != nullptr
                      && v16->weaponState == WEAPONSTATE_SECONDARY )
                    {
                      v62 = operator+(result: &v284, a: "pre", b: &v280);
                      idStr::operator=(this: &v280, text: v62);
                      idStr::FreeData(this: &v284);
                    }
                    idAnimator_AnimWeb::ChangeStateVia(
                      this: &this->web,
                      subWebName: SubWebName,
                      stateName: "idle",
                      viaSubWebName: SubWebName,
                      viaStateName: v280.data,
                      interruptPath_: INTR_PATH_YES,
                      interruptBlend_: INTR_BLEND_YES,
                      blendEventMask_: 0);
                    this->lastWeaponUsedTime = idGameTimeManager::GetGameMs(
                                                 this: &clientGame->gameTimeManager,
                                                 type: GAMETIME_SCALED);
                    idHands::ClearPendingAction(this);
                    idStr::FreeData(this: &v280);
                  }
                }
              }
            }
          }
          else
          {
            v48 = _cntlzw(this->pendingAction.action - 6);
            v249 = (v48 & 0x20) != 0;
            if ( (v48 & 0x20) != 0 )
            {
              v249 = true;
            }
            else
            {
              v42 = !idHands::PistolWhipPending(this);
              p_web = &this->web;
              if ( v42 )
              {
                idAnimator_AnimWeb::ChangeState(
                  this: p_web,
                  subWebName: SubWebName,
                  stateName: "zoomidle",
                  interruptPath_: INTR_PATH_YES,
                  interruptBlend_: INTR_BLEND_YES,
                  blendEventMask_: 0);
                idHands::ClearPendingAction(this);
                this->isZooming = true;
              }
              else
              {
                idAnimator_AnimWeb::ChangeStateVia(
                  this: p_web,
                  subWebName: SubWebName,
                  stateName: "idle",
                  viaSubWebName: SubWebName,
                  viaStateName: "melee",
                  interruptPath_: INTR_PATH_YES,
                  interruptBlend_: INTR_BLEND_YES,
                  blendEventMask_: 0);
                idHands::ClearPendingAction(this);
                this->isZooming = false;
              }
            }
          }
        }
      }
      else
      {
        if ( idPhysics_Player::HasJumped(this: &this->owner->physicsObj) )
          this->lastActionTime = idClientGame::GetPlayerGameTime(this: clientGame);
        if ( this->owner->physicsObj.HasGroundContacts(this: &this->owner->physicsObj) )
        {
          v39 = (float *)((int (__fastcall *)(int *))this->owner->physicsObj.GetLinearVelocity)(a1: &v281);
          if ( (float)((float)(*v39 * *v39) + (float)(v39[1] * v39[1])) > 0.0099999998 )
            this->lastActionTime = idClientGame::GetPlayerGameTime(this: clientGame);
        }
        valueInteger = hands_idleaccent_delay.valueInteger;
        if ( idClientGame::GetPlayerGameTime(this: clientGame) - this->lastActionTime > valueInteger )
        {
          this->isInAccentIdle = true;
          idAnimator_AnimWeb::ChangeStateVia(
            this: &this->web,
            subWebName: SubWebName,
            stateName: "idle",
            viaSubWebName: SubWebName,
            viaStateName: "idle_accent",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
          this->isInterruptableTransition = true;
          idHands::ClearPendingAction(this);
        }
      }
      goto LABEL_642;
    case HS_ZOOM_IDLE:
      if ( hands_debugstate.valueInteger != 0 )
        idLib::Printf(fmt: "State: HS_ZOOM_IDLE\n");
      if ( (_cntlzw(idPresentablePlayer::IsZoomedIn(ptr: this->owner)) & 0x20) != 0
        || idPlayer::IsOnLadder(this: (idPlayer *)this->owner->entity) )
      {
        idAnimator_AnimWeb::ChangeState(
          this: &this->web,
          subWebName: SubWebName,
          stateName: "idle",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_YES,
          blendEventMask_: 0);
      }
      else
      {
        v63 = this->pendingAction.action;
        if ( v63 != HANDSACTION_NONE )
        {
          if ( (_cntlzw(v63 - 2) & 0x20) != 0 )
          {
            idHands::ClearPendingAction(this);
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->web,
              subWebName: SubWebName,
              stateName: "zoomidle",
              viaSubWebName: SubWebName,
              viaStateName: "zoomdryfire",
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_YES,
              blendEventMask_: 0);
          }
          else if ( (unsigned __int8)idHands::AttackPending(this) != 0 )
          {
            if ( (unsigned __int8)idHands::HandlePendingAttack(
                                    this,
                                    weapon: (idLaserCutter *)v16,
                                    subWebName: SubWebName,
                                    secondary: this->pendingAction.isSecondary,
                                    state: HS_ZOOM_IDLE) != 0 )
              goto LABEL_602;
          }
          else
          {
            if ( idHands::PistolWhipPending(this) )
              goto LABEL_191;
            v64 = this->pendingAction.action;
            if ( (_cntlzw(v64 - 8) & 0x20) != 0 || (_cntlzw(v64 - 9) & 0x20) != 0 )
              goto LABEL_191;
            v42 = (unsigned __int8)idHands::ReloadPending(this) == 0;
            v41 = this;
            if ( v42 )
            {
              if ( (unsigned __int8)idHands::AmmoChangePending(this) != 0 )
              {
                if ( v16 != nullptr )
                {
                  v65 = this->pendingAction.isSecondary ? v16->ammoClipSecondary : v16->ammoClip;
                  if ( v65->decl != this->pendingAction.ammoDecl )
                  {
                    idAnimator_AnimWeb::ChangeState(
                      this: &this->web,
                      subWebName: SubWebName,
                      stateName: "idle",
                      interruptPath_: INTR_PATH_YES,
                      interruptBlend_: INTR_BLEND_NO,
                      blendEventMask_: 0);
                    this->isChangingAmmo = true;
                  }
                }
              }
              else
              {
                v66 = this->pendingAction.action;
                if ( (_cntlzw(v66 - 6) & 0x20) != 0 || (_cntlzw(v66 - 7) & 0x20) != 0 )
                  goto LABEL_191;
                LOBYTE(v51) = _cntlzw(v66 - 12);
                HIDWORD(v51) = (v51 & 0x20) != 0;
                if ( (v51 & 0x20) != 0 )
                  goto LABEL_261;
                LOBYTE(v51) = _cntlzw(v66 - 11);
                HIDWORD(v51) = (v51 & 0x20) != 0;
                if ( (v51 & 0x20) != 0 )
                  goto LABEL_261;
                if ( (_cntlzw(v66 - 13) & 0x20) == 0 )
                  goto LABEL_602;
                this->isHandsSprinting = true;
                idAnimator_AnimWeb::ChangeStateVia(
                  this: &this->web,
                  subWebName: SubWebName,
                  stateName: "sprint",
                  viaSubWebName: SubWebName,
                  viaStateName: "idle",
                  interruptPath_: INTR_PATH_YES,
                  interruptBlend_: INTR_BLEND_NO,
                  blendEventMask_: 0);
                idHands::ClearPendingAction(this);
              }
            }
            else
            {
LABEL_110:
              idHands::SetReloadState(this: v41, subWebName: SubWebName);
            }
          }
        }
      }
      goto LABEL_642;
    case HS_THROW_IDLE:
      if ( hands_debugstate.valueInteger != 0 )
        idLib::Printf(fmt: "State: HS_THROW_IDLE\n");
      v67 = this->pendingAction.action;
      if ( v67 == HANDSACTION_NONE )
      {
        throwItem = this->throwItem;
        if ( throwItem == nullptr || throwItem->projectileDecl->notHitscanInfo.grenadeInfo.cookable )
        {
          buttons = 0;
          if ( (*((_BYTE *)&this->owner->ucmdTracker1.usercmd + 9) & 0x80) == 0 )
            buttons = this->owner->ucmdTracker1.usercmd.buttons;
          if ( (buttons & 0x200000) != 0 )
            goto LABEL_642;
        }
      }
      if ( (_cntlzw(v67 - 8) & 0x20) != 0 )
        idHands::ClearPendingAction(this);
      goto LABEL_191;
    case HS_TRANSITIONING:
      goto LABEL_277;
    case HS_CHARGING:
      if ( hands_debugstate.valueInteger != 0 )
        idLib::Printf(fmt: "State: HS_CHARGING\n");
LABEL_191:
      idAnimator_AnimWeb::ChangeState(
        this: &this->web,
        subWebName: SubWebName,
        stateName: "idle",
        interruptPath_: INTR_PATH_YES,
        interruptBlend_: INTR_BLEND_NO,
        blendEventMask_: 0);
      goto LABEL_642;
    case HS_LASERING:
      if ( hands_debugstate.valueInteger != 0 )
        idLib::Printf(fmt: "State: HS_LASERING\n");
      v79 = this->pendingAction.action;
      if ( v79 == HANDSACTION_NONE )
      {
        v16->PullTrigger(this: v16, a2: (idActor *)this->owner->entity, a3: this->pendingAction.isSecondary);
        v80 = &this->web;
        if ( this->isZooming )
          idAnimator_AnimWeb::ChangeState(
            this: v80,
            subWebName: SubWebName,
            stateName: "zoomlasering",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_YES,
            blendEventMask_: 0);
        else
          idAnimator_AnimWeb::ChangeState(
            this: v80,
            subWebName: SubWebName,
            stateName: "lasering",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_YES,
            blendEventMask_: 0);
        goto LABEL_602;
      }
      LODWORD(v51) = _cntlzw(v79 - 10);
      HIDWORD(v51) = (v51 & 0x20) != 0;
      if ( (v51 & 0x20) != 0 )
      {
        currentVariationIndex = this->currentVariationIndex;
        this->web.previousVariationIndex = (float)*(__int64 *)((char *)&v51 - 4);
        idAnimator_AnimWeb::ChangeState(
          this: &this->web,
          subWebName: SubWebName,
          stateName: "idle",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
      }
      else if ( (_cntlzw(v79 - 11) & 0x20) != 0 )
      {
LABEL_261:
        LODWORD(v51) = this->currentVariationIndex;
        this->web.previousVariationIndex = (float)v51;
        idAnimator_AnimWeb::ChangeStateVia(
          this: &this->web,
          subWebName: SubWebName,
          stateName: "idle",
          viaSubWebName: SubWebName,
          viaStateName: "rest",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
        idHands::ClearPendingAction(this);
      }
      goto LABEL_642;
    case HS_SPRINTING:
      this->isHandsSprinting = true;
      if ( hands_debugstate.valueInteger != 0 )
        idLib::Printf(fmt: "State: HS_SPRINTING\n");
      v77 = this->pendingAction.action;
      if ( (_cntlzw(v77 - 13) & 0x20) != 0 )
        goto LABEL_602;
      if ( v77 == HANDSACTION_NONE )
        goto LABEL_642;
      if ( (unsigned __int8)idHands::HandlePendingAttack(
                              this,
                              weapon: (idLaserCutter *)v16,
                              subWebName: SubWebName,
                              secondary: this->pendingAction.isSecondary,
                              state: HS_SPRINTING) != 0 )
        goto LABEL_602;
      if ( (_cntlzw(this->pendingAction.action - 6) & 0x20) != 0 )
      {
LABEL_241:
        idHands::SetEquipState(this, subWebName: SubWebName);
        goto LABEL_642;
      }
      if ( (unsigned __int8)idHands::ReloadPending(this) != 0 )
      {
        idHands::SetReloadState(this, subWebName: SubWebName);
        goto LABEL_642;
      }
      if ( (_cntlzw(this->pendingAction.action - 14) & 0x20) != 0 )
        this->isInEndSprint = true;
      v42 = !idPresentablePlayer::IsZoomedIn(ptr: this->owner);
      v78 = &this->web;
      if ( v42 )
        idAnimator_AnimWeb::ChangeState(
          this: v78,
          subWebName: SubWebName,
          stateName: "idle",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
      else
        idAnimator_AnimWeb::ChangeState(
          this: v78,
          subWebName: SubWebName,
          stateName: "zoomidle",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
      goto LABEL_602;
    case HS_HIDEMOVE:
      v69 = this->hiddenReasons;
      if ( v69 != 0 )
      {
        this->usedToHaveHideReasons = v69;
        goto LABEL_642;
      }
      if ( idPlayer::IsOnLadder(this: (idPlayer *)this->owner->entity) )
      {
        this->lastOnLadderTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        goto LABEL_642;
      }
      if ( (unsigned __int8)idPresentablePlayer::PlayerBehavior_Shared_ShouldHideWeapon(this: this->owner) != 0 )
        goto LABEL_642;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      lastOnLadderTime = this->lastOnLadderTime;
      if ( GameMs - lastOnLadderTime <= 2 * GameMsPerFrame )
        goto LABEL_642;
      decl = nullptr;
      if ( v16 != nullptr )
        decl = v16->decl;
      v74 = this->pendingAction.action;
      if ( v74 == HANDSACTION_NONE && this->usedToHaveHideReasons == 0 && lastOnLadderTime < 0 )
        goto LABEL_642;
      LODWORD(v75) = this->currentVariationIndex;
      HIDWORD(v75) = _cntlzw(v74 - 6);
      this->web.previousVariationIndex = (float)v75;
      if ( (v75 & 0x2000000000LL) != 0 )
      {
        idHands::SetEquipState(this, subWebName: SubWebName);
        this->usedToHaveHideReasons = 0;
        this->lastOnLadderTime = -1;
        goto LABEL_642;
      }
      if ( (unsigned __int8)idHands::HandlePendingAttack(
                              this,
                              weapon: (idLaserCutter *)v16,
                              subWebName: SubWebName,
                              secondary: this->pendingAction.isSecondary,
                              state: HS_HIDEMOVE) != 0 )
      {
        this->lastWeaponUsedTime = idGameTimeManager::GetGameMs(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED)
                                 + 500;
LABEL_224:
        idHands::ClearPendingAction(this);
LABEL_225:
        this->usedToHaveHideReasons = 0;
        this->lastOnLadderTime = -1;
        goto LABEL_642;
      }
      v76 = this->pendingAction.action;
      if ( (_cntlzw(v76 - 13) & 0x20) != 0 || (_cntlzw(v76 - 14) & 0x20) != 0 )
        goto LABEL_224;
      if ( (_cntlzw(v76 - 12) & 0x20) != 0 )
      {
        idHands::ClearPendingAction(this);
        this->lastWeaponUsedTime = idGameTimeManager::GetGameMs(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED)
                                 + 500;
        idAnimator_AnimWeb::ChangeStateVia(
          this: &this->web,
          subWebName: SubWebName,
          stateName: "idle",
          viaSubWebName: SubWebName,
          viaStateName: "hide_out",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
        this->usedToHaveHideReasons = 0;
        this->lastOnLadderTime = -1;
      }
      else
      {
        if ( (decl == nullptr || decl[1].parent == nullptr) && this->usedToHaveHideReasons != 128 )
          goto LABEL_225;
        this->lastWeaponUsedTime = idGameTimeManager::GetGameMs(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED)
                                 + 500;
        idAnimator_AnimWeb::ChangeStateVia(
          this: &this->web,
          subWebName: SubWebName,
          stateName: "idle",
          viaSubWebName: SubWebName,
          viaStateName: "hide_out",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
        this->usedToHaveHideReasons = 0;
        this->lastOnLadderTime = -1;
      }
      goto LABEL_642;
    case HS_CHARGEWEAPONBATTERY:
      if ( hands_debugstate.valueInteger != 0 )
        idLib::Printf(fmt: "State: HS_CHARGEWEAPONBATTERY\n");
      v82 = 0;
      FocusUsable = idFocusTracker::GetFocusUsable(this: &this->owner->focusTracker);
      v84 = (idProp_BatteryChargePoint *)FocusUsable;
      if ( FocusUsable != nullptr && (unsigned __int8)idProp_BatteryChargePoint::IsTypeOf(c: FocusUsable) != 0 )
      {
        v85 = idProp_BatteryChargePoint::CastTo(c: v84);
        user = v85->user;
        if ( user != idPresentableActor::GetActorEntity(this: this->owner) )
        {
          v87 = (idLaserCutter *)this->owner->GetEquippedWeapon(this: this->owner, a2: 2);
          if ( v87 != nullptr )
          {
            v88 = idLaserCutter::CastTo(c: v87);
            if ( v88 != nullptr
              && ((double (__fastcall *)(idLaserCutter *, _DWORD))v88->AmmoInClipPercentage)(a1: v88, a2: 0) < 1.0 )
            {
              v89 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              lastChargetTime = v85->lastChargetTime;
              if ( this->web.nodeStartTime > lastChargetTime )
                lastChargetTime = this->web.nodeStartTime;
              if ( v89 - lastChargetTime < 750 )
                v82 = 1;
            }
          }
        }
      }
      if ( v82 == 0 )
      {
        LOBYTE(v91) = _cntlzw(this->pendingAction.action - 10);
        HIDWORD(v91) = (v91 & 0x20) != 0;
        if ( (v91 & 0x20) != 0 )
        {
          LODWORD(v91) = this->currentVariationIndex;
          this->web.previousVariationIndex = (float)v91;
          idAnimator_AnimWeb::ChangeState(
            this: &this->web,
            subWebName: SubWebName,
            stateName: "idle",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
        }
      }
LABEL_277:
      if ( v16 == nullptr )
      {
        idHands::RestHandsToIdle(this);
        goto LABEL_642;
      }
      if ( hands_debugstate.valueInteger != 0 )
        idLib::Printf(fmt: "State: HS_TRANSITIONING\n");
      if ( !this->isReloading )
        goto LABEL_410;
      if ( hands_debugstate.valueInteger != 0 )
        idLib::Printf(fmt: "isReloading\n");
      this->isInReloadOut = false;
      nextAmmo = v16->nextAmmo;
      if ( nextAmmo == nullptr )
      {
        v93 = this->pendingAction.isSecondary ? v16->ammoClipSecondary : v16->ammoClip;
        v94 = v93 != nullptr ? (const idDeclAmmo *)v93->decl : nullptr;
        nextAmmo = v94;
        if ( v94 == nullptr )
          goto LABEL_308;
      }
      v95 = this->pendingAction.isSecondary;
      v96 = v95 ? v16->ammoClipSecondary : v16->ammoClip;
      v97 = v96 != nullptr ? v96->decl : nullptr;
      if ( v97 == nullptr
        || (!this->pendingAction.isSecondary ? (v98 = v16->ammoClip) : (v98 = v16->ammoClipSecondary),
            v98 == nullptr ? (v99 = nullptr) : (v99 = v98->decl),
            HIBYTE(v99[1].vehicleJointName.len) == 0
         || (*((_BYTE *)v16 + 452) & 4) != 0
         || (v100 = this->owner->GetInventory(this: this->owner),
             CanReload = idWeapon::CanReload(this: v16, inventory: v100, ammoDecl: nextAmmo, secondaryAmmo: v95),
             v102 = 1,
             CanReload)) )
      {
LABEL_308:
        v102 = 0;
      }
      v103 = v102;
      if ( !this->isChangingAmmo && (v102 != 0 || (unsigned __int8)idHands::ReloadPending(this) != 0) )
      {
        idWeapon::SetFireState(this: v16, fs: FIRESTATE_IDLE);
        v104 = this->pendingAction.isSecondary ? v16->ammoClipSecondary : v16->ammoClip;
        v105 = v104 != nullptr ? v104->decl : nullptr;
        if ( v105 != nullptr
          && (!this->pendingAction.isSecondary ? (v106 = v16->ammoClip) : (v106 = v16->ammoClipSecondary),
              v106 == nullptr ? (v107 = nullptr) : (v107 = v106->decl),
              HIBYTE(v107[1].vehicleJointName.len) != 0 && (*((_BYTE *)v16 + 452) & 4) == 0) )
        {
          idAnimator_AnimWeb::ChangeStateVia(
            this: &this->web,
            subWebName: SubWebName,
            stateName: "idle",
            viaSubWebName: SubWebName,
            viaStateName: "reload_out",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
          this->isInReloadOut = true;
        }
        else
        {
          idAnimator_AnimWeb::ChangeState(
            this: &this->web,
            subWebName: SubWebName,
            stateName: "idle",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
        }
        this->isReloading = false;
        if ( (unsigned __int8)idHands::ReloadPending(this) != 0 )
        {
          v108 = this->pendingAction.isSecondary ? v16->ammoClipSecondary : v16->ammoClip;
          v109 = v108 != nullptr ? v108->decl : nullptr;
          if ( v109 != nullptr )
          {
            v110 = this->pendingAction.isSecondary ? v16->ammoClipSecondary : v16->ammoClip;
            v111 = v110 != nullptr ? v110->decl : nullptr;
            if ( HIBYTE(v111[1].vehicleJointName.len) != 0 && (*((_BYTE *)v16 + 452) & 4) == 0 )
              idHands::ClearPendingAction(this);
          }
        }
      }
      if ( idHands::PistolWhipPending(this)
        || (unsigned __int8)idHands::AttackPending(this) != 0
        || (v112 = this->pendingAction.action, (_cntlzw(v112 - 8) & 0x20) != 0)
        || (_cntlzw(v112 - 9) & 0x20) != 0 )
      {
        idPresentablePlayer::StopSound(this: this->owner, channel: SND_CHANNEL_WEAPON, peerMask: 0xFFu);
        idWeapon::SetFireState(this: v16, fs: FIRESTATE_IDLE);
        idPresentablePlayer::ClearPendingAmmo(this: this->owner);
        if ( LOBYTE(v16->decl[2].quickSlotGroup) != 0 )
          idWeapon::BeginReloading(this: v16, ammoDecl: nullptr, secondaryAmmo: this->pendingAction.isSecondary);
        if ( this->pendingAction.isSecondary )
          v127 = v16->ammoClipSecondary;
        else
          v127 = v16->ammoClip;
        if ( v127 != nullptr )
        {
          v128 = this->pendingAction.isSecondary ? v16->ammoClipSecondary : v16->ammoClip;
          if ( v128->decl != nullptr )
          {
            if ( this->pendingAction.isSecondary )
              v129 = v16->ammoClipSecondary;
            else
              v129 = v16->ammoClip;
            idHands::UpdateAmmoMeshForWeapon(this, ammoDecl: (const idDeclAmmo *)v129->decl);
          }
        }
        v274.len = 0;
        v274.baseBuffer[0] = 0;
        v274.data = v274.baseBuffer;
        v274.allocedAndFlag = 20;
        v130 = this->pendingAction.isSecondary;
        if ( this == (idHands *)-2996 )
          v131 = nullptr;
        else
          v131 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
        idHands::GetWeaponSubWebName(this, weapon: v131, name: &v274, secondary: v130);
        this->isInterruptableTransition = false;
        this->isReloading = false;
        if ( idHands::PistolWhipPending(this) )
        {
          idAnimator_AnimWeb::ChangeStateVia(
            this: &this->web,
            subWebName: v274.data,
            stateName: "idle",
            viaSubWebName: v274.data,
            viaStateName: "melee",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
        }
        else if ( (unsigned __int8)idHands::AttackPending(this) != 0 )
        {
          if ( (unsigned __int8)idHands::HandlePendingAttack(
                                  this,
                                  weapon: (idLaserCutter *)v16,
                                  subWebName: SubWebName,
                                  secondary: this->pendingAction.isSecondary,
                                  state: v37) != 0 )
            idHands::ClearPendingAction(this);
        }
        else
        {
          v132 = this->pendingAction.action;
          if ( (_cntlzw(v132 - 8) & 0x20) != 0 || (_cntlzw(v132 - 9) & 0x20) != 0 )
            idHands::StartCooking(this, throwable: this->pendingAction.throwable, nextSubWebName: SubWebName);
        }
        idHands::ClearPendingAction(this);
        v121 = &v274;
        goto LABEL_409;
      }
      if ( (unsigned __int8)idHands::AmmoChangePending(this) != 0 && !this->isReloading )
      {
        if ( this->pendingAction.isSecondary )
          v113 = v16->ammoClipSecondary;
        else
          v113 = v16->ammoClip;
        if ( v113->decl != this->pendingAction.ammoDecl )
        {
          idPresentablePlayer::StopSound(this: this->owner, channel: SND_CHANNEL_WEAPON, peerMask: 0xFFu);
          idWeapon::BeginReloading(
            this: v16,
            ammoDecl: this->pendingAction.ammoDecl,
            secondaryAmmo: this->pendingAction.isSecondary);
          v272.len = 0;
          v272.baseBuffer[0] = 0;
          v272.data = v272.baseBuffer;
          v272.allocedAndFlag = 20;
          v114 = this->pendingAction.isSecondary;
          if ( this == (idHands *)-2996 )
            v115 = nullptr;
          else
            v115 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
          idHands::GetWeaponSubWebName(this, weapon: v115, name: &v272, secondary: v114);
          v116 = idHands::GetAmmoChangeNodeName(
                   this: (idHands *)&v288,
                   result: this,
                   secondary: this->pendingAction.isSecondary,
                   leftHand: this->pendingAction.leftHand);
          idAnimator_AnimWeb::ChangeStateVia(
            this: &this->web,
            subWebName: v272.data,
            stateName: "idle",
            viaSubWebName: SubWebName,
            viaStateName: (const char *)v116->listenerList,
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
          idStr::FreeData(this: &v288);
          this->isInterruptableTransition = true;
          this->isChangingAmmo = true;
          idStr::FreeData(this: &v272);
        }
        idHands::ClearPendingAction(this);
        goto LABEL_410;
      }
      v117 = this->pendingAction.action;
      if ( (_cntlzw(v117 - 6) & 0x20) != 0 )
      {
        this->isWeaponBringUp = true;
        this->isReloading = false;
        idPresentablePlayer::StopSound(this: this->owner, channel: SND_CHANNEL_WEAPON, peerMask: 0xFFu);
        v264.len = 0;
        v264.data = v264.baseBuffer;
        v264.allocedAndFlag = 20;
        v264.baseBuffer[0] = 0;
        v118 = this->pendingAction.isSecondary;
        LODWORD(v119) = this->currentVariationIndex;
        weapon = this->pendingAction.weapon;
        this->web.previousVariationIndex = (float)v119;
        idHands::GetWeaponSubWebName(this, weapon, name: &v264, secondary: v118);
        idAnimator_AnimWeb::ChangeStateVia(
          this: &this->web,
          subWebName: v264.data,
          stateName: "idle",
          viaSubWebName: v264.data,
          viaStateName: "bringup",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
        idHands::ClearPendingAction(this);
        this->isInterruptableTransition = true;
        v121 = &v264;
LABEL_409:
        idStr::FreeData(this: v121);
        goto LABEL_410;
      }
      if ( (_cntlzw(v117 - 13) & 0x20) != 0 )
      {
        this->isHandsSprinting = true;
        idPresentablePlayer::StopSound(this: this->owner, channel: SND_CHANNEL_WEAPON, peerMask: 0xFFu);
        idAnimator_AnimWeb::ChangeState(
          this: &this->web,
          subWebName: SubWebName,
          stateName: "sprint",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
        idHands::ClearPendingAction(this);
        goto LABEL_410;
      }
      if ( !this->isChangingAmmo && v103 == 0 )
      {
        v122 = this->pendingAction.isSecondary ? v16->ammoClipSecondary : v16->ammoClip;
        v123 = v122 != nullptr ? v122->decl : nullptr;
        if ( v123 != nullptr )
        {
          v124 = this->pendingAction.isSecondary ? v16->ammoClipSecondary : v16->ammoClip;
          v125 = v124 != nullptr ? v124->decl : nullptr;
          if ( HIBYTE(v125[1].vehicleJointName.len) != 0 && (*((_BYTE *)v16 + 452) & 4) == 0 )
          {
            ReloadNodeName = idHands::GetReloadNodeName(
                               this: (idHands *)v282,
                               result: this,
                               secondary: this->pendingAction.isSecondary,
                               leftHand: this->pendingAction.leftHand);
            idAnimator_AnimWeb::ChangeState(
              this: &this->web,
              subWebName: SubWebName,
              stateName: (const char *)ReloadNodeName->listenerList,
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
            v121 = (idStr *)v282;
            goto LABEL_409;
          }
        }
      }
LABEL_410:
      if ( !this->isInReloadOut )
        goto LABEL_458;
      if ( hands_debugstate.valueInteger != 0 )
        idLib::Printf(fmt: "isInReloadOut\n");
      if ( idHands::PistolWhipPending(this)
        || (unsigned __int8)idHands::AttackPending(this) != 0
        || (v133 = this->pendingAction.action, (_cntlzw(v133 - 8) & 0x20) != 0)
        || (_cntlzw(v133 - 9) & 0x20) != 0 )
      {
        idPresentablePlayer::StopSound(this: this->owner, channel: SND_CHANNEL_WEAPON, peerMask: 0xFFu);
        idWeapon::SetFireState(this: v16, fs: FIRESTATE_IDLE);
        idPresentablePlayer::ClearPendingAmmo(this: this->owner);
        idWeapon::BeginReloading(this: v16, ammoDecl: nullptr, secondaryAmmo: this->pendingAction.isSecondary);
        v259.len = 0;
        v259.data = v259.baseBuffer;
        v259.allocedAndFlag = 20;
        v259.baseBuffer[0] = 0;
        v149 = this->pendingAction.isSecondary;
        if ( this == (idHands *)-2996 )
          v150 = nullptr;
        else
          v150 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
        idHands::GetWeaponSubWebName(this, weapon: v150, name: &v259, secondary: v149);
        this->isInterruptableTransition = false;
        this->isInReloadOut = false;
        if ( idHands::PistolWhipPending(this) )
        {
          idAnimator_AnimWeb::ChangeStateVia(
            this: &this->web,
            subWebName: v259.data,
            stateName: "idle",
            viaSubWebName: v259.data,
            viaStateName: "melee",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
        }
        else if ( (unsigned __int8)idHands::AttackPending(this) != 0 )
        {
          if ( (unsigned __int8)idHands::HandlePendingAttack(
                                  this,
                                  weapon: (idLaserCutter *)v16,
                                  subWebName: SubWebName,
                                  secondary: this->pendingAction.isSecondary,
                                  state: v37) != 0 )
            idHands::ClearPendingAction(this);
        }
        else
        {
          v151 = this->pendingAction.action;
          if ( (_cntlzw(v151 - 8) & 0x20) != 0 || (_cntlzw(v151 - 9) & 0x20) != 0 )
            idHands::StartCooking(this, throwable: this->pendingAction.throwable, nextSubWebName: SubWebName);
        }
        idHands::ClearPendingAction(this);
        v142 = &v259;
        goto LABEL_457;
      }
      if ( (unsigned __int8)idHands::AmmoChangePending(this) != 0 && !this->isInReloadOut )
      {
        if ( this->pendingAction.isSecondary )
          v134 = v16->ammoClipSecondary;
        else
          v134 = v16->ammoClip;
        if ( v134->decl != this->pendingAction.ammoDecl )
        {
          idPresentablePlayer::StopSound(this: this->owner, channel: SND_CHANNEL_WEAPON, peerMask: 0xFFu);
          idWeapon::BeginReloading(
            this: v16,
            ammoDecl: this->pendingAction.ammoDecl,
            secondaryAmmo: this->pendingAction.isSecondary);
          v266.len = 0;
          v266.baseBuffer[0] = 0;
          v266.data = v266.baseBuffer;
          v266.allocedAndFlag = 20;
          v135 = this->pendingAction.isSecondary;
          if ( this == (idHands *)-2996 )
            v136 = nullptr;
          else
            v136 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
          idHands::GetWeaponSubWebName(this, weapon: v136, name: &v266, secondary: v135);
          v137 = idHands::GetAmmoChangeNodeName(
                   this: (idHands *)&v283,
                   result: this,
                   secondary: this->pendingAction.isSecondary,
                   leftHand: this->pendingAction.leftHand);
          idAnimator_AnimWeb::ChangeStateVia(
            this: &this->web,
            subWebName: v266.data,
            stateName: "idle",
            viaSubWebName: SubWebName,
            viaStateName: (const char *)v137->listenerList,
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
          idStr::FreeData(this: &v283);
          this->isInterruptableTransition = true;
          idStr::FreeData(this: &v266);
        }
        idHands::ClearPendingAction(this);
        goto LABEL_458;
      }
      v138 = this->pendingAction.action;
      if ( (_cntlzw(v138 - 6) & 0x20) != 0 )
      {
        this->isWeaponBringUp = true;
        idPresentablePlayer::StopSound(this: this->owner, channel: SND_CHANNEL_WEAPON, peerMask: 0xFFu);
        v276.len = 0;
        v276.data = v276.baseBuffer;
        v276.allocedAndFlag = 20;
        v276.baseBuffer[0] = 0;
        v139 = this->pendingAction.isSecondary;
        LODWORD(v140) = this->currentVariationIndex;
        v141 = this->pendingAction.weapon;
        this->web.previousVariationIndex = (float)v140;
        idHands::GetWeaponSubWebName(this, weapon: v141, name: &v276, secondary: v139);
        idAnimator_AnimWeb::ChangeStateVia(
          this: &this->web,
          subWebName: v276.data,
          stateName: "idle",
          viaSubWebName: v276.data,
          viaStateName: "bringup",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
        idHands::ClearPendingAction(this);
        this->isInterruptableTransition = true;
        v142 = &v276;
LABEL_457:
        idStr::FreeData(this: v142);
        goto LABEL_458;
      }
      if ( (_cntlzw(v138 - 13) & 0x20) != 0 )
      {
        this->isHandsSprinting = true;
        idPresentablePlayer::StopSound(this: this->owner, channel: SND_CHANNEL_WEAPON, peerMask: 0xFFu);
        idAnimator_AnimWeb::ChangeState(
          this: &this->web,
          subWebName: SubWebName,
          stateName: "sprint",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
        idHands::ClearPendingAction(this);
      }
      else
      {
        v143 = v16->decl;
        v144 = 0;
        if ( (int)v143[1].nextOnHashChain > 0 )
        {
          v145 = 0;
          do
          {
            if ( this->pendingAction.isSecondary )
              v146 = v16->ammoClipSecondary;
            else
              v146 = v16->ammoClip;
            if ( v146->decl == *(const idDeclInventory **)&v143[1].name.str[v145] )
            {
              v147 = this->pendingAction.isSecondary ? v16->ammoClipSecondary : v16->ammoClip;
              str = v143[1].name.str;
              if ( v147->GetCount(this: v147) == *(_DWORD *)&str[v145 + 8] )
                idAnimator_AnimWeb::ChangeState(
                  this: &this->web,
                  subWebName: SubWebName,
                  stateName: "idle",
                  interruptPath_: INTR_PATH_YES,
                  interruptBlend_: INTR_BLEND_NO,
                  blendEventMask_: 0);
            }
            v143 = v16->decl;
            ++v144;
            v145 += 28;
          }
          while ( v144 < (int)v143[1].nextOnHashChain );
        }
      }
LABEL_458:
      if ( (unsigned __int8)idHands::ReloadPending(this) != 0 )
      {
        idHands::SetReloadState(this, subWebName: SubWebName);
        this->isReloading = true;
      }
      if ( this->isZooming )
      {
        if ( hands_debugstate.valueInteger != 0 )
          idLib::Printf(fmt: "isZooming\n");
        if ( !idPresentablePlayer::IsZoomedIn(ptr: this->owner) && !this->isReloading )
        {
          isChainFiring = this->isChainFiring;
          v153 = 1;
          this->isZooming = false;
          if ( isChainFiring )
          {
            idPresentablePlayer::StopSound(this: this->owner, channel: SND_CHANNEL_ITEM, peerMask: 0xFFu);
            this->isChainFiring = false;
          }
          else if ( (unsigned __int8)idHands::AttackPending(this) != 0 )
          {
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->web,
              subWebName: SubWebName,
              stateName: "idle",
              viaSubWebName: SubWebName,
              viaStateName: "zoomout_shoot",
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_YES,
              blendEventMask_: 0);
            v153 = 0;
          }
          if ( v153 != 0 )
            idAnimator_AnimWeb::ChangeState(
              this: &this->web,
              subWebName: SubWebName,
              stateName: "idle",
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_YES,
              blendEventMask_: 0);
        }
      }
      if ( this->isInterruptableTransition )
      {
        if ( hands_debugstate.valueInteger != 0 )
          idLib::Printf(fmt: "isInterruptableTransition\n");
        if ( idHands::PistolWhipPending(this)
          || (unsigned __int8)idHands::AttackPending(this) != 0
          || (v154 = this->pendingAction.action, (_cntlzw(v154 - 8) & 0x20) != 0)
          || (_cntlzw(v154 - 9) & 0x20) != 0 )
        {
          idWeapon::SetFireState(this: v16, fs: FIRESTATE_IDLE);
          idPresentablePlayer::ClearPendingAmmo(this: this->owner);
          idWeapon::BeginReloading(this: v16, ammoDecl: nullptr, secondaryAmmo: this->pendingAction.isSecondary);
          v257.len = 0;
          v257.data = v257.baseBuffer;
          v257.allocedAndFlag = 20;
          v257.baseBuffer[0] = 0;
          v172 = this->pendingAction.isSecondary;
          if ( this == (idHands *)-2996 )
            v173 = nullptr;
          else
            v173 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
          idHands::GetWeaponSubWebName(this, weapon: v173, name: &v257, secondary: v172);
          this->isInterruptableTransition = false;
          this->isReloading = false;
          if ( idHands::PistolWhipPending(this) )
          {
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->web,
              subWebName: v257.data,
              stateName: "idle",
              viaSubWebName: v257.data,
              viaStateName: "melee",
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
          }
          else if ( (unsigned __int8)idHands::AttackPending(this) != 0 )
          {
            if ( (unsigned __int8)idHands::HandlePendingAttack(
                                    this,
                                    weapon: (idLaserCutter *)v16,
                                    subWebName: SubWebName,
                                    secondary: this->pendingAction.isSecondary,
                                    state: v250) != 0 )
              idHands::ClearPendingAction(this);
          }
          else
          {
            v174 = this->pendingAction.action;
            if ( (_cntlzw(v174 - 8) & 0x20) != 0 || (_cntlzw(v174 - 9) & 0x20) != 0 )
            {
              idHands::StartCooking(this, throwable: this->pendingAction.throwable, nextSubWebName: v257.data);
            }
            else if ( idPresentablePlayer::IsZoomedIn(ptr: this->owner) )
            {
              v42 = (unsigned __int8)idHands::AttackPending(this) == 0;
              v175 = &this->web;
              if ( v42 )
                idAnimator_AnimWeb::ChangeState(
                  this: v175,
                  subWebName: SubWebName,
                  stateName: "idle",
                  interruptPath_: INTR_PATH_YES,
                  interruptBlend_: INTR_BLEND_YES,
                  blendEventMask_: 0);
              else
                idAnimator_AnimWeb::ChangeStateVia(
                  this: v175,
                  subWebName: SubWebName,
                  stateName: "idle",
                  viaSubWebName: SubWebName,
                  viaStateName: "zoomout_shoot",
                  interruptPath_: INTR_PATH_YES,
                  interruptBlend_: INTR_BLEND_YES,
                  blendEventMask_: 0);
            }
          }
          idHands::ClearPendingAction(this);
          idHandsItem::StopVideo(this: &this->rightItem);
          v157 = &v257;
          goto LABEL_526;
        }
        if ( idPresentablePlayer::IsZoomedIn(ptr: this->owner) )
        {
          idWeapon::SetFireState(this: v16, fs: FIRESTATE_IDLE);
          idPresentablePlayer::ClearPendingAmmo(this: this->owner);
          idWeapon::BeginReloading(this: v16, ammoDecl: nullptr, secondaryAmmo: this->pendingAction.isSecondary);
          this->isInterruptableTransition = false;
          this->isReloading = false;
          v278.allocedAndFlag = 20;
          v278.data = v278.baseBuffer;
          v278.len = 0;
          v278.baseBuffer[0] = 0;
          v155 = this->pendingAction.isSecondary;
          if ( this == (idHands *)-2996 )
            v156 = nullptr;
          else
            v156 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
          idHands::GetWeaponSubWebName(this, weapon: v156, name: &v278, secondary: v155);
          idAnimator_AnimWeb::ChangeState(
            this: &this->web,
            subWebName: SubWebName,
            stateName: "zoomidle",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_YES,
            blendEventMask_: 0);
          this->isZooming = true;
          idHands::ClearPendingAction(this);
          idHandsItem::StopVideo(this: &this->rightItem);
          v157 = &v278;
          goto LABEL_526;
        }
        if ( (unsigned __int8)idHands::AmmoChangePending(this) != 0 )
        {
          if ( this->pendingAction.isSecondary )
            v159 = v16->ammoClipSecondary;
          else
            v159 = v16->ammoClip;
          v160 = this->pendingAction.ammoDecl;
          if ( v159->decl != v160 )
          {
            idWeapon::BeginReloading(this: v16, ammoDecl: v160, secondaryAmmo: this->pendingAction.isSecondary);
            v273.len = 0;
            v273.data = v273.baseBuffer;
            v273.allocedAndFlag = 20;
            v273.baseBuffer[0] = 0;
            v161 = this->pendingAction.isSecondary;
            if ( this == (idHands *)-2996 )
              v162 = nullptr;
            else
              v162 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
            idHands::GetWeaponSubWebName(this, weapon: v162, name: &v273, secondary: v161);
            v163 = idHands::GetAmmoChangeNodeName(
                     this: (idHands *)&v285,
                     result: this,
                     secondary: this->pendingAction.isSecondary,
                     leftHand: this->pendingAction.leftHand);
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->web,
              subWebName: v273.data,
              stateName: "idle",
              viaSubWebName: SubWebName,
              viaStateName: (const char *)v163->listenerList,
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
            idStr::FreeData(this: &v285);
            this->isReloading = true;
            this->isChangingAmmo = true;
            idHandsItem::StopVideo(this: &this->rightItem);
            idStr::FreeData(this: &v273);
          }
          idHands::ClearPendingAction(this);
        }
        else
        {
          v164 = this->pendingAction.action;
          if ( (_cntlzw(v164 - 6) & 0x20) != 0 )
          {
            this->isWeaponBringUp = true;
            v270.len = 0;
            v270.data = v270.baseBuffer;
            v270.allocedAndFlag = 20;
            v270.baseBuffer[0] = 0;
            v165 = this->pendingAction.isSecondary;
            LODWORD(v158) = this->currentVariationIndex;
            v166 = this->pendingAction.weapon;
            this->web.previousVariationIndex = (float)v158;
            idHands::GetWeaponSubWebName(this, weapon: v166, name: &v270, secondary: v165);
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->web,
              subWebName: v270.data,
              stateName: "idle",
              viaSubWebName: v270.data,
              viaStateName: "bringup",
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
            idHands::ClearPendingAction(this);
            this->isInterruptableTransition = true;
            idHandsItem::StopVideo(this: &this->rightItem);
            v157 = &v270;
LABEL_526:
            idStr::FreeData(this: v157);
            goto LABEL_527;
          }
          LOBYTE(v167) = _cntlzw(v164 - 12);
          HIDWORD(v167) = (v167 & 0x20) != 0;
          if ( (v167 & 0x20) != 0 )
          {
            LODWORD(v167) = this->currentVariationIndex;
            this->web.previousVariationIndex = (float)v167;
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->web,
              subWebName: SubWebName,
              stateName: "idle",
              viaSubWebName: SubWebName,
              viaStateName: "rest",
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
            idHands::ClearPendingAction(this);
          }
          else
          {
            LOBYTE(v168) = _cntlzw(v164 - 11);
            HIDWORD(v168) = (v168 & 0x20) != 0;
            if ( (v168 & 0x20) != 0 )
            {
              LODWORD(v168) = this->currentVariationIndex;
              this->web.previousVariationIndex = (float)v168;
              idAnimator_AnimWeb::ChangeStateVia(
                this: &this->web,
                subWebName: SubWebName,
                stateName: "idle",
                viaSubWebName: SubWebName,
                viaStateName: "rest",
                interruptPath_: INTR_PATH_YES,
                interruptBlend_: INTR_BLEND_NO,
                blendEventMask_: 0);
              idHands::ClearPendingAction(this);
              idHandsItem::StopVideo(this: &this->rightItem);
            }
            else if ( (_cntlzw(v164 - 13) & 0x20) != 0 )
            {
              this->isHandsSprinting = true;
              idAnimator_AnimWeb::ChangeState(
                this: &this->web,
                subWebName: SubWebName,
                stateName: "sprint",
                interruptPath_: INTR_PATH_YES,
                interruptBlend_: INTR_BLEND_NO,
                blendEventMask_: 0);
              idHands::ClearPendingAction(this);
              idHandsItem::StopVideo(this: &this->rightItem);
            }
            else if ( (unsigned __int8)idHands::ReloadPending(this) != 0 )
            {
              idHands::SetReloadState(this, subWebName: SubWebName);
              this->isReloading = true;
              idHandsItem::StopVideo(this: &this->rightItem);
            }
            else
            {
              StateName = idDeclAnimWeb::GetStateName(
                            this: this->web.decl,
                            index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v31->states.stateIndex[0].value);
              if ( idStr::Icmp(s1: StateName, s2: "idle_accent") == 0 )
              {
                HasJumped = idPhysics_Player::HasJumped(this: &this->owner->physicsObj);
                if ( !HasJumped && this->owner->physicsObj.HasGroundContacts(this: &this->owner->physicsObj) )
                {
                  v171 = (float *)((int (__fastcall *)(blendParms_t *))this->owner->physicsObj.GetLinearVelocity)(a1: &v279);
                  if ( __fsqrts((float)((float)(*v171 * *v171) + (float)(v171[1] * v171[1]))) > 0.000099999997 )
                    HasJumped = true;
                }
                if ( HasJumped )
                {
                  blendParms_t::blendParms_t(this: (blendParms_t *)&v252);
                  blendParms_t::SetDuration(this: (blendParms_t *)&v252, frame: 10);
                  idAnimator_AnimWeb::ForceState(
                    this: &this->web,
                    subWebName: SubWebName,
                    stateName: "idle",
                    blendParms: (const blendParms_t *)&v252,
                    blendEventMask_: 0);
                  this->lastActionTime = idClientGame::GetPlayerGameTime(this: clientGame);
                }
              }
            }
          }
        }
      }
LABEL_527:
      if ( this->cookingProjectileDecl != nullptr && this->canInteruptCooking )
      {
        if ( hands_debugstate.valueInteger != 0 )
          idLib::Printf(fmt: "GetIsCooking() && canInteruptCooking\n");
        if ( (_cntlzw(this->pendingAction.action - 8) & 0x20) != 0 )
        {
          idHands::ClearPendingAction(this);
          idAnimator_AnimWeb::ChangeState(
            this: &this->web,
            subWebName: SubWebName,
            stateName: "idle",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_YES,
            blendEventMask_: 0);
        }
      }
      if ( (_cntlzw(this->pendingAction.action - 14) & 0x20) != 0 )
      {
        this->isInEndSprint = true;
        IsZoomedIn = idPresentablePlayer::IsZoomedIn(ptr: this->owner);
        v177 = "zoomidle";
        if ( !IsZoomedIn )
          v177 = "idle";
        idAnimator_AnimWeb::ChangeState(
          this: &this->web,
          subWebName: SubWebName,
          stateName: v177,
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
        idHands::ClearPendingAction(this);
      }
      if ( this->isInEndSprint )
      {
        if ( hands_debugstate.valueInteger != 0 )
          idLib::Printf(fmt: "isInEndSprint\n");
        if ( idHands::PistolWhipPending(this)
          || (unsigned __int8)idHands::AttackPending(this) != 0
          || (v178 = this->pendingAction.action, (_cntlzw(v178 - 8) & 0x20) != 0)
          || (_cntlzw(v178 - 9) & 0x20) != 0 )
        {
          idWeapon::SetFireState(this: v16, fs: FIRESTATE_IDLE);
          idPresentablePlayer::ClearPendingAmmo(this: this->owner);
          idWeapon::BeginReloading(this: v16, ammoDecl: nullptr, secondaryAmmo: this->pendingAction.isSecondary);
          v255.len = 0;
          v255.data = v255.baseBuffer;
          v255.allocedAndFlag = 20;
          v255.baseBuffer[0] = 0;
          v190 = this->pendingAction.isSecondary;
          if ( this == (idHands *)-2996 )
            v191 = nullptr;
          else
            v191 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
          idHands::GetWeaponSubWebName(this, weapon: v191, name: &v255, secondary: v190);
          this->isInterruptableTransition = false;
          this->isReloading = false;
          this->isInEndSprint = false;
          if ( idHands::PistolWhipPending(this) )
          {
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->web,
              subWebName: v255.data,
              stateName: "idle",
              viaSubWebName: v255.data,
              viaStateName: "melee",
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
          }
          else if ( (unsigned __int8)idHands::AttackPending(this) != 0 )
          {
            if ( (unsigned __int8)idHands::HandlePendingAttack(
                                    this,
                                    weapon: (idLaserCutter *)v16,
                                    subWebName: SubWebName,
                                    secondary: this->pendingAction.isSecondary,
                                    state: v250) != 0 )
              idHands::ClearPendingAction(this);
          }
          else
          {
            v192 = this->pendingAction.action;
            if ( (_cntlzw(v192 - 8) & 0x20) != 0 || (_cntlzw(v192 - 9) & 0x20) != 0 )
              idHands::StartCooking(this, throwable: this->pendingAction.throwable, nextSubWebName: v255.data);
          }
          idHands::ClearPendingAction(this);
          idHandsItem::StopVideo(this: &this->rightItem);
          v181 = &v255;
          goto LABEL_576;
        }
        if ( idPresentablePlayer::IsZoomedIn(ptr: this->owner) )
        {
          idWeapon::SetFireState(this: v16, fs: FIRESTATE_IDLE);
          idPresentablePlayer::ClearPendingAmmo(this: this->owner);
          idWeapon::BeginReloading(this: v16, ammoDecl: nullptr, secondaryAmmo: this->pendingAction.isSecondary);
          this->isInterruptableTransition = false;
          this->isReloading = false;
          this->isInEndSprint = false;
          v277.allocedAndFlag = 20;
          v277.data = v277.baseBuffer;
          v277.len = 0;
          v277.baseBuffer[0] = 0;
          v179 = this->pendingAction.isSecondary;
          if ( this == (idHands *)-2996 )
            v180 = nullptr;
          else
            v180 = idWeapon::CastTo(c: (idWeapon *)this->rightItem.item);
          idHands::GetWeaponSubWebName(this, weapon: v180, name: &v277, secondary: v179);
          idAnimator_AnimWeb::ChangeState(
            this: &this->web,
            subWebName: SubWebName,
            stateName: "zoomidle",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_YES,
            blendEventMask_: 0);
          this->isZooming = true;
          idHands::ClearPendingAction(this);
          idHandsItem::StopVideo(this: &this->rightItem);
          v181 = &v277;
          goto LABEL_576;
        }
        if ( (unsigned __int8)idHands::AmmoChangePending(this) != 0 )
        {
          if ( this->pendingAction.isSecondary )
            v183 = v16->ammoClipSecondary;
          else
            v183 = v16->ammoClip;
          v184 = this->pendingAction.ammoDecl;
          if ( v183->decl != v184 )
          {
            idWeapon::BeginReloading(this: v16, ammoDecl: v184, secondaryAmmo: this->pendingAction.isSecondary);
            v271.len = 0;
            v271.data = v271.baseBuffer;
            v271.allocedAndFlag = 20;
            v271.baseBuffer[0] = 0;
            idHands::GetWeaponSubWebName(this, name: &v271, secondary: this->pendingAction.isSecondary);
            v185 = idHands::GetAmmoChangeNodeName(
                     this: (idHands *)&v287,
                     result: this,
                     secondary: this->pendingAction.isSecondary,
                     leftHand: this->pendingAction.leftHand);
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->web,
              subWebName: v271.data,
              stateName: "idle",
              viaSubWebName: SubWebName,
              viaStateName: (const char *)v185->listenerList,
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
            idStr::FreeData(this: &v287);
            this->isReloading = true;
            this->isInEndSprint = false;
            this->isChangingAmmo = true;
            idHandsItem::StopVideo(this: &this->rightItem);
            idStr::FreeData(this: &v271);
          }
          idHands::ClearPendingAction(this);
        }
        else
        {
          v186 = this->pendingAction.action;
          if ( (_cntlzw(v186 - 6) & 0x20) != 0 )
          {
            this->isWeaponBringUp = true;
            v275.len = 0;
            v275.data = v275.baseBuffer;
            v275.allocedAndFlag = 20;
            v275.baseBuffer[0] = 0;
            v187 = this->pendingAction.isSecondary;
            LODWORD(v182) = this->currentVariationIndex;
            v188 = this->pendingAction.weapon;
            this->web.previousVariationIndex = (float)v182;
            idHands::GetWeaponSubWebName(this, weapon: v188, name: &v275, secondary: v187);
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->web,
              subWebName: v275.data,
              stateName: "idle",
              viaSubWebName: v275.data,
              viaStateName: "bringup",
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
            idHands::ClearPendingAction(this);
            this->isInterruptableTransition = true;
            this->isInEndSprint = false;
            idHandsItem::StopVideo(this: &this->rightItem);
            v181 = &v275;
LABEL_576:
            idStr::FreeData(this: v181);
            goto LABEL_577;
          }
          LOBYTE(v189) = _cntlzw(v186 - 12);
          HIDWORD(v189) = (v189 & 0x20) != 0;
          if ( (v189 & 0x20) != 0 )
          {
            LODWORD(v189) = this->currentVariationIndex;
            this->web.previousVariationIndex = (float)v189;
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->web,
              subWebName: SubWebName,
              stateName: "idle",
              viaSubWebName: SubWebName,
              viaStateName: "rest",
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
            idHands::ClearPendingAction(this);
          }
          else if ( (_cntlzw(v186 - 11) & 0x20) != 0 )
          {
            LODWORD(v189) = this->currentVariationIndex;
            this->web.previousVariationIndex = (float)v189;
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->web,
              subWebName: SubWebName,
              stateName: "idle",
              viaSubWebName: SubWebName,
              viaStateName: "rest",
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
            idHands::ClearPendingAction(this);
            idHandsItem::StopVideo(this: &this->rightItem);
            this->isInEndSprint = false;
          }
          else if ( (unsigned __int8)idHands::ReloadPending(this) != 0 )
          {
            idHands::SetReloadState(this, subWebName: SubWebName);
            this->isReloading = true;
            this->isInEndSprint = false;
            idHandsItem::StopVideo(this: &this->rightItem);
          }
        }
      }
LABEL_577:
      if ( this->isChainFiring )
      {
        if ( hands_debugstate.valueInteger != 0 )
          idLib::Printf(fmt: "isChainFiring\n");
        v16->PullTrigger(this: v16, a2: (idActor *)this->owner->entity, a3: this->pendingAction.isSecondary);
        v193 = this->pendingAction.action;
        if ( v193 != HANDSACTION_NONE )
        {
          if ( (_cntlzw(v193 - 10) & 0x20) != 0 )
            idHands::ClearPendingAction(this);
          this->isChainFiring = false;
          idPresentablePlayer::StopSound(this: this->owner, channel: SND_CHANNEL_ITEM, peerMask: 0xFFu);
          isZooming = this->isZooming;
          this->isInterruptableTransition = true;
          v195 = "zoomidle";
          if ( !isZooming )
            v195 = "idle";
          idAnimator_AnimWeb::ChangeState(
            this: &this->web,
            subWebName: SubWebName,
            stateName: v195,
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_YES,
            blendEventMask_: 0);
        }
      }
      if ( this->isChargeFiring )
      {
        if ( hands_debugstate.valueInteger != 0 )
          idLib::Printf(fmt: "isChargeFiring\n");
        v16->PullTrigger(this: v16, a2: (idActor *)this->owner->entity, a3: this->pendingAction.isSecondary);
        if ( this->pendingAction.action != HANDSACTION_NONE && (unsigned __int8)idHands::AttackPending(this) == 0 )
          idHands::ClearPendingAction(this);
      }
      if ( this->isLaserFiring )
      {
        if ( hands_debugstate.valueInteger != 0 )
          idLib::Printf(fmt: "isLaserFiring\n");
        if ( this->pendingAction.action != HANDSACTION_NONE && (unsigned __int8)idHands::AttackPending(this) == 0 )
LABEL_602:
          idHands::ClearPendingAction(this);
      }
LABEL_642:
      entity = this->owner->entity;
      v217 = idPlayer::PlayerBehavior_WallClimb_IsInWallClimb(this: (idPlayer *)entity);
      if ( v217 || (*((_BYTE *)this + 7912) & 4) != 0 )
      {
        if ( (*((_BYTE *)this + 7912) & 4) == 0 )
        {
          if ( this->currentDualWieldState == SET_DUALWIELD_ON )
            idHands::AnimEvent_SetDualWieldWeapon(
              this: (idHands *)&v249,
              result: (eventVoid *)this,
              anim: nullptr,
              setType: 2);
          v268.len = 0;
          v268.baseBuffer[0] = 0;
          v268.data = v268.baseBuffer;
          v268.allocedAndFlag = 20;
          idHands::GetWeaponSubWebName(this, name: &v268, secondary: false);
          idAnimator_AnimWeb::ChangeState(
            this: &this->secondaryWeb,
            subWebName: v268.data,
            stateName: (const char *)LODWORD(v252.mat[2].z),
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
          *((_BYTE *)this + 7912) |= 4u;
          v220 = &v268;
          goto LABEL_662;
        }
        if ( v217 )
        {
          v221 = this->secondaryWeb.curNodeIndex.value;
          if ( v221 == -1 )
            v222 = nullptr;
          else
            v222 = this->secondaryWeb.decl->nodes.list[v221];
          v223 = idDeclAnimWeb::GetStateName(
                   this: this->secondaryWeb.decl,
                   index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v222->states.stateIndex[0].value);
          v224 = v252.mat[2].z;
          if ( idStr::Icmp(s1: v223, s2: (const char *)LODWORD(v252.mat[2].z)) == 0 )
            goto LABEL_663;
          v261.len = 0;
          v261.baseBuffer[0] = 0;
          v261.data = v261.baseBuffer;
          v261.allocedAndFlag = 20;
          idHands::GetWeaponSubWebName(this, name: &v261, secondary: false);
          idAnimator_AnimWeb::ChangeState(
            this: &this->secondaryWeb,
            subWebName: v261.data,
            stateName: (const char *)LODWORD(v224),
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
          v220 = &v261;
        }
        else
        {
          v260.len = 0;
          v260.baseBuffer[0] = 0;
          v260.data = v260.baseBuffer;
          v260.allocedAndFlag = 20;
          idHands::GetWeaponSubWebName(this, name: &v260, secondary: false);
          idAnimator_AnimWeb::ChangeState(
            this: &this->secondaryWeb,
            subWebName: v260.data,
            stateName: "idle",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_NO,
            blendEventMask_: 0);
          *((_BYTE *)this + 7912) &= ~4u;
          v220 = &v260;
        }
LABEL_662:
        idStr::FreeData(this: v220);
        goto LABEL_663;
      }
      if ( this->currentDualWieldState != SET_DUALWIELD_ON && idHands::GetState(this, animWeb: &this->secondaryWeb) != 0 )
      {
        v256.len = 0;
        v256.baseBuffer[0] = 0;
        v256.data = v256.baseBuffer;
        v256.allocedAndFlag = 20;
        if ( v16 != nullptr && (*((_BYTE *)v16 + 453) & 0x80) != 0 )
          idHands::GetWeaponSubWebName(this, name: &v256, secondary: false);
        else
          idStr::operator=(this: &v256, text: "pistol");
        data = v256.data;
        PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
        idAnimator_AnimWeb::Reset(
          this: &this->secondaryWeb,
          initialSubWebName: data,
          initialStateName: "idle",
          curTime: PlayerGameTime);
        v220 = &v256;
        goto LABEL_662;
      }
LABEL_663:
      v225 = this->owner;
      p_ucmdTracker1 = &v225->ucmdTracker1;
      v227 = v225->GetEquippedWeapon(this: v225, a2: EQUIP_LEFT_HAND);
      v228 = v227;
      v229 = 0;
      if ( v227 != nullptr )
      {
        v230 = this->dualWieldLeftHandPendingAction.action;
        switch ( v230 )
        {
          case HANDSACTION_FIRE:
            v239 = idRandom2::RandomInt(this: &clientGame->random, min: 1, max: 2) + this->lastAttackVariationDWLeft;
            this->lastAttackVariationDWLeft = v239 % 3;
            LODWORD(v240) = idWeapon::GetAttackVariation(this: v228, slot: v239 % 3);
            v241 = this->owner;
            *(_QWORD *)&v252.mat[0].x = v240;
            v242 = (double)v240;
            HIDWORD(v240) = this->dualWieldLeftHandPendingAction.isSecondary;
            this->secondaryWeb.attackVariation = v242;
            v228->PullTrigger(this: v228, a2: (idActor *)v241->entity, a3: HIDWORD(v240));
            if ( idWeapon::IsMelee(this: v228) )
              v228->burstCount = 0;
            v267.len = 0;
            v267.baseBuffer[0] = 0;
            v267.data = v267.baseBuffer;
            v267.allocedAndFlag = 20;
            idHands::GetWeaponSubWebName(this, name: &v267, secondary: false);
            ShootNodeName = idHands::GetShootNodeName(
                              this: (idHands *)v289,
                              result: (idStr *)this,
                              stateName: "shoot",
                              rightWeapon: (_cntlzw(this->dualWieldLeftHandPendingAction.leftHand) & 0x20) != 0,
                              secondary: this->dualWieldLeftHandPendingAction.isSecondary,
                              state: v250);
            idAnimator_AnimWeb::ChangeStateVia(
              this: &this->secondaryWeb,
              subWebName: v267.data,
              stateName: "idle",
              viaSubWebName: v267.data,
              viaStateName: (const char *)ShootNodeName->listenerList,
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_YES,
              blendEventMask_: 0);
            idStr::FreeData(this: v289);
            v229 = 1;
            v232 = &v267;
            break;
          case HANDSACTION_RETURNTOIDLE:
            v265.len = 0;
            v265.baseBuffer[0] = 0;
            v265.data = v265.baseBuffer;
            v265.allocedAndFlag = 20;
            idHands::GetWeaponSubWebName(this, name: &v265, secondary: false);
            idAnimator_AnimWeb::ChangeState(
              this: &this->secondaryWeb,
              subWebName: v265.data,
              stateName: "idle",
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_YES,
              blendEventMask_: 0);
            v232 = &v265;
            break;
          case HANDSACTION_TOGGLEFIREMODE:
            if ( (_cntlzw((unsigned int)v227->decl[1].parent) & 0x20) == 0 )
            {
              v233 = idWeapon::ToggleFireMode(this: v227, justFetchNextMode: true, ignoreMode: false);
              if ( v233 != idWeapon::GetBurstMode(this: v228) )
              {
                v263.len = 0;
                v263.baseBuffer[0] = 0;
                v263.data = v263.baseBuffer;
                v263.allocedAndFlag = 20;
                idHands::GetWeaponSubWebName(this, name: &v263, secondary: false);
                v234 = idWeapon::GetBurstMode(this: v228);
                v235 = v263.data;
                v236 = (const char *)p_dualWieldLeftHandPendingAction;
                LODWORD(v237) = ((((v233 ^ v234) & 0x80000000) == 0) + (v234 >= v233)) & 1;
                *(_QWORD *)&v252.mat[0].x = v237;
                v238 = v263.data;
                this->secondaryWeb.previousVariationIndex = (float)v237;
                idAnimator_AnimWeb::ChangeStateVia(
                  this: &this->secondaryWeb,
                  subWebName: v238,
                  stateName: "idle",
                  viaSubWebName: v235,
                  viaStateName: v236,
                  interruptPath_: INTR_PATH_YES,
                  interruptBlend_: INTR_BLEND_NO,
                  blendEventMask_: 0);
                idStr::FreeData(this: &v263);
              }
              if ( v233 != BURSTMODE_MAX )
                idWeapon::ToggleFireMode(this: v228, justFetchNextMode: false, ignoreMode: false);
              goto LABEL_681;
            }
            v258.len = 0;
            v258.baseBuffer[0] = 0;
            v258.data = v258.baseBuffer;
            v258.allocedAndFlag = 20;
            idHands::GetWeaponSubWebName(this, name: &v258, secondary: false);
            if ( v228->weaponState != WEAPONSTATE_NORMAL )
              v231 = "idle";
            else
              v231 = "throwidle";
            idAnimator_AnimWeb::ChangeState(
              this: &this->secondaryWeb,
              subWebName: v258.data,
              stateName: v231,
              interruptPath_: INTR_PATH_YES,
              interruptBlend_: INTR_BLEND_NO,
              blendEventMask_: 0);
            v232 = &v258;
            break;
          default:
            goto LABEL_681;
        }
        idStr::FreeData(this: v232);
LABEL_681:
        this->dualWieldLeftHandPendingAction.action = HANDSACTION_NONE;
        this->dualWieldLeftHandPendingAction.ammoDecl = nullptr;
        this->dualWieldLeftHandPendingAction.weapon = nullptr;
        this->dualWieldLeftHandPendingAction.throwable = nullptr;
        this->dualWieldLeftHandPendingAction.useIntroBringUp = false;
        this->dualWieldLeftHandPendingAction.isSecondary = false;
        this->dualWieldLeftHandPendingAction.leftHand = false;
        p_dualWieldLeftHandPendingAction = &this->dualWieldLeftHandPendingAction;
        idStr::Clear(this: &this->dualWieldLeftHandPendingAction.extraNodeInfo);
        if ( v229 == 0 && !idUCmdTracker::IsPressedForPlayer(this: p_ucmdTracker1, mask: 8) && v228->burstCount == 0
          || (unsigned __int8)idPresentablePlayer::CheckInhibitFire(this: this->owner) != 0 )
        {
          v228->ReleaseTrigger(this: v228, a2: (idActor *)this->owner->entity);
        }
      }
      if ( v16 != nullptr
        && (!idUCmdTracker::IsPressedForPlayer(this: p_ucmdTracker1, mask: 1)
         && (!idWeapon::IsMelee(this: v16) || !idUCmdTracker::IsPressedForPlayer(this: p_ucmdTracker1, mask: 8))
         && v16->burstCount == 0
         || (unsigned __int8)idPresentablePlayer::CheckInhibitFire(this: this->owner) != 0) )
      {
        v16->ReleaseTrigger(this: v16, a2: (idActor *)this->owner->entity);
      }
      if ( v250 != HS_IDLE && v250 != HS_HIDEMOVE && v250 != HS_SPRINTING && v250 != HS_TRANSITIONING
        || v16 != nullptr
        && (v244 = (idDeclInventory *)v16->decl,
            giveable = v244[2].giveable,
            p_dualWieldLeftHandPendingAction = (idHands::idHandsAction *)v244,
            giveable)
        && entity != nullptr
        && (int)entity[15].clipModelInfo.overrideClipMaterial >= 1
        && (dropable = v244[2].dropable, p_dualWieldLeftHandPendingAction = (idHands::idHandsAction *)v244, !dropable) )
      {
        this->lastWeaponUsedTime = idGameTimeManager::GetGameMs(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED);
      }
      if ( this->presentable != nullptr )
      {
        idHands::UpdateAnimator(this);
        this->presentable->UpdateFX_3(this: this->presentable, a2: 1.0, a3: 0.0);
      }
      idHands::UpdatePosition(this);
      if ( hands_show.valueInteger != 0 )
      {
        idHandsItem::Update(this: &this->rightItem, hands: this, useAlternativeModel: false);
        idHandsItem::Update(
          this: &this->leftItem,
          hands: this,
          useAlternativeModel: (_cntlzw(this->currentDualWieldState - 1) & 0x20) != 0);
      }
      if ( this->shouldDisable )
      {
        this->disabled = true;
        idRibbon::~idRibbon(this: (idRibbon *)&this->handsMeleeTrace);
        this->shouldDisable = false;
        idHands::ResetAnimWeb(this);
      }
      if ( this->shouldShowAfterUpdate )
      {
        v247 = this->hiddenReasons;
        this->shouldShowAfterUpdate = false;
        this->hiddenReasons = v247 & 0xFFFFFFFE;
      }
LABEL_711:
      idPLogScope::~idPLogScope(this: (idPLogScope *)&v252.mat[2]);
      RD_EventEnd();
      return;
    case HS_SWIMMING:
      if ( currentSwimDepthState == SWIMDEPTH_STATE_NONE )
      {
        v269.len = 0;
        v269.baseBuffer[0] = 0;
        v269.data = v269.baseBuffer;
        v269.allocedAndFlag = 20;
        idHands::GetWeaponSubWebName(this, name: &v269, secondary: false);
        idAnimator_AnimWeb::ChangeState(
          this: &this->web,
          subWebName: v269.data,
          stateName: "idle",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
        this->currentSwimState = HS_IDLE;
        idHands::ClearPendingAction(this);
        idStr::FreeData(this: &v269);
        goto LABEL_642;
      }
      if ( (_cntlzw(this->pendingAction.action - 6) & 0x20) != 0 )
      {
        idAnimator_AnimWeb::ChangeStateVia(
          this: &this->web,
          subWebName: "swimming",
          stateName: "idle",
          viaSubWebName: "swimming",
          viaStateName: "EquipWeapon",
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_NO,
          blendEventMask_: 0);
        goto LABEL_602;
      }
      DWORD1(v196) = 0x82000000;
      p_usercmd = &this->owner->ucmdTracker1.usercmd;
      DWORD2(v196) = this->owner->ucmdTracker1.usercmd.forwardmove;
      LODWORD(v196) = this->owner->ucmdTracker1.usercmd.rightmove;
      *(_QWORD *)&v252.mat[0].x = v196;
      v198 = (float)(__int64)v196;
      v199 = (float)*(__int64 *)((char *)&v196 + 4);
      _FP2 = (float)((float)((float)((float)*(__int64 *)((char *)&v196 + 4) * (float)*(__int64 *)((char *)&v196 + 4))
                           + (float)((float)(__int64)v196 * (float)(__int64)v196))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f13, f2, f3, f13 }
      v202 = __frsqrte(_FP13);
      *((double *)&v203 + 1) = (float)-(float)((float)((float)((float)((float)((float)((float)v199 * (float)v199)
                                                                             + (float)((float)v198 * (float)v198))
                                                                     * (float)0.5)
                                                             * (float)((float)-(float)((float)((float)((float)((float)((float)((float)v199 * (float)v199) + (float)((float)v198 * (float)v198)) * (float)0.5) * (float)v202)
                                                                                             * (float)v202)
                                                                                     - (float)1.5)
                                                                     * (float)v202))
                                                     * (float)((float)-(float)((float)((float)((float)((float)((float)((float)v199 * (float)v199) + (float)((float)v198 * (float)v198)) * (float)0.5)
                                                                                             * (float)v202)
                                                                                     * (float)v202)
                                                                             - (float)1.5)
                                                             * (float)v202))
                                             - (float)1.5);
      v204 = (float)((float)-(float)((float)((float)((float)((float)((float)((float)v199 * (float)v199)
                                                                   + (float)((float)v198 * (float)v198))
                                                           * (float)0.5)
                                                   * (float)((float)-(float)((float)((float)((float)((float)((float)((float)v199 * (float)v199) + (float)((float)v198 * (float)v198)) * (float)0.5)
                                                                                           * (float)v202)
                                                                                   * (float)v202)
                                                                           - (float)1.5)
                                                           * (float)v202))
                                           * (float)((float)-(float)((float)((float)((float)((float)((float)((float)v199 * (float)v199) + (float)((float)v198 * (float)v198))
                                                                                           * (float)0.5)
                                                                                   * (float)v202)
                                                                           * (float)v202)
                                                                   - (float)1.5)
                                                   * (float)v202))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)((float)((float)((float)v199 * (float)v199)
                                                                           + (float)((float)v198 * (float)v198))
                                                                   * (float)0.5)
                                                           * (float)v202)
                                                   * (float)v202)
                                           - (float)1.5)
                           * (float)v202));
      v205 = (float)((float)((float)((float)((float)v199 * (float)v199) + (float)((float)v198 * (float)v198))
                           * (float)0.5)
                   * (float)((float)-(float)((float)((float)((float)((float)((float)((float)v199 * (float)v199)
                                                                           + (float)((float)v198 * (float)v198))
                                                                   * (float)0.5)
                                                           * (float)((float)-(float)((float)((float)((float)((float)((float)((float)v199 * (float)v199) + (float)((float)v198 * (float)v198)) * (float)0.5) * (float)v202)
                                                                                           * (float)v202)
                                                                                   - (float)1.5)
                                                                   * (float)v202))
                                                   * (float)((float)-(float)((float)((float)((float)((float)((float)((float)v199 * (float)v199) + (float)((float)v198 * (float)v198)) * (float)0.5)
                                                                                           * (float)v202)
                                                                                   * (float)v202)
                                                                           - (float)1.5)
                                                           * (float)v202))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)((float)((float)((float)v199 * (float)v199)
                                                                                   + (float)((float)v198 * (float)v198))
                                                                           * (float)0.5)
                                                                   * (float)v202)
                                                           * (float)v202)
                                                   - (float)1.5)
                                   * (float)v202)));
      *(double *)&v203 = (float)((float)((float)((float)((float)-(float)((float)((float)v205 * (float)v204) - (float)1.5)
                                                       * (float)v204)
                                               * (float)(__int64)v196)
                                       * (float)0.0)
                               + (float)((float)((float)-(float)((float)((float)v205 * (float)v204) - (float)1.5)
                                               * (float)v204)
                                       * (float)*(__int64 *)((char *)&v196 + 4)));
      v206 = (float)((float)((float)((float)-(float)((float)((float)v205 * (float)v204) - (float)1.5) * (float)v204)
                           * (float)((float)((float)*(__int64 *)((char *)&v196 + 4)
                                           * (float)*(__int64 *)((char *)&v196 + 4))
                                   + (float)((float)(__int64)v196 * (float)(__int64)v196)))
                   * (float)0.0078740157);
      v208 = idMath::ACos(a: v203);
      currentSwimState = this->currentSwimState;
      v210 = (float)((float)v208 / (float)3.1415927);
      switch ( currentSwimState )
      {
        case HS_SWIMMING_LOCKED:
          goto LABEL_642;
        case HS_SWIMMING_ENTER:
          idAnimator_AnimWeb::ChangeState(
            this: &this->web,
            subWebName: "swimming",
            stateName: "idle",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_YES,
            blendEventMask_: 0);
          v211 = this->owner;
          this->currentSwimState = HS_SWIMMING;
          v212 = v211->GetInventory(this: v211);
          InventoryItemByName = (idWeapon *)idInventoryCollection::FindInventoryItemByName(
                                              this: v212,
                                              internalName: "knife");
          this->pendingWeaponToEquip = idWeapon::CastTo(c: InventoryItemByName);
          goto LABEL_642;
        case HS_SWIMMING_SURFACE:
          idAnimator_AnimWeb::ChangeStateVia(
            this: &this->web,
            subWebName: "swimming",
            stateName: "idle",
            viaSubWebName: "swimming",
            viaStateName: "surface",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_YES,
            blendEventMask_: 0);
          v214 = HS_SWIMMING;
          break;
        case HS_SWIMMING_SUBMERGE:
          idAnimator_AnimWeb::ChangeStateVia(
            this: &this->web,
            subWebName: "swimming",
            stateName: "idle",
            viaSubWebName: "swimming",
            viaStateName: "submerge",
            interruptPath_: INTR_PATH_YES,
            interruptBlend_: INTR_BLEND_YES,
            blendEventMask_: 0);
          v214 = HS_SWIMMING;
          break;
        default:
          if ( v206 >= 0.050000001 )
          {
            if ( v210 >= 0.30000001 )
            {
              if ( v210 >= 0.75 )
              {
                if ( currentSwimState == HS_SWIMMING_BACK )
                  goto LABEL_642;
                idAnimator_AnimWeb::ChangeState(
                  this: &this->web,
                  subWebName: "Swimming",
                  stateName: "Back",
                  interruptPath_: INTR_PATH_YES,
                  interruptBlend_: INTR_BLEND_YES,
                  blendEventMask_: 0);
                v214 = HS_SWIMMING_BACK;
              }
              else
              {
                LODWORD(v207) = p_usercmd->rightmove;
                *(_QWORD *)&v252.mat[0].x = v207;
                if ( (float)v207 <= 0.0 )
                {
                  if ( currentSwimState == HS_SWIMMING_LEFT )
                    goto LABEL_642;
                  idAnimator_AnimWeb::ChangeState(
                    this: &this->web,
                    subWebName: "Swimming",
                    stateName: "Left",
                    interruptPath_: INTR_PATH_YES,
                    interruptBlend_: INTR_BLEND_YES,
                    blendEventMask_: 0);
                  v214 = HS_SWIMMING_LEFT;
                }
                else
                {
                  if ( currentSwimState == HS_SWIMMING_RIGHT )
                    goto LABEL_642;
                  idAnimator_AnimWeb::ChangeState(
                    this: &this->web,
                    subWebName: "Swimming",
                    stateName: "Right",
                    interruptPath_: INTR_PATH_YES,
                    interruptBlend_: INTR_BLEND_YES,
                    blendEventMask_: 0);
                  v214 = HS_SWIMMING_RIGHT;
                }
              }
            }
            else if ( this->owner->isSprinting )
            {
              if ( currentSwimState == HS_SWIMMING_FORWARD_SPRINT )
                goto LABEL_642;
              idAnimator_AnimWeb::ChangeState(
                this: &this->web,
                subWebName: "Swimming",
                stateName: "Sprint",
                interruptPath_: INTR_PATH_YES,
                interruptBlend_: INTR_BLEND_YES,
                blendEventMask_: 0);
              v214 = HS_SWIMMING_FORWARD_SPRINT;
            }
            else
            {
              if ( currentSwimState == HS_SWIMMING_FORWARD )
                goto LABEL_642;
              idAnimator_AnimWeb::ChangeState(
                this: &this->web,
                subWebName: "Swimming",
                stateName: "Forward",
                interruptPath_: INTR_PATH_YES,
                interruptBlend_: INTR_BLEND_YES,
                blendEventMask_: 0);
              v214 = HS_SWIMMING_FORWARD;
            }
          }
          else
          {
            upmove = p_usercmd->upmove;
            if ( upmove <= 10 )
            {
              if ( upmove >= -10 )
              {
                if ( v24 >= -triggerSideStepAngle )
                {
                  if ( v24 <= triggerSideStepAngle )
                  {
                    if ( currentSwimState == HS_SWIMMING )
                    {
                      if ( this->handBubblesActivated )
                      {
                        this->presentable->StopAllFX(this: this->presentable);
                        this->handBubblesActivated = false;
                      }
                    }
                    else
                    {
                      idAnimator_AnimWeb::ChangeState(
                        this: &this->web,
                        subWebName: "swimming",
                        stateName: "idle",
                        interruptPath_: INTR_PATH_YES,
                        interruptBlend_: INTR_BLEND_YES,
                        blendEventMask_: 0);
                      this->currentSwimState = HS_SWIMMING;
                    }
                    goto LABEL_642;
                  }
                  if ( currentSwimState == HS_SWIMMING_TURN_RIGHT )
                    goto LABEL_642;
                  idAnimator_AnimWeb::ChangeState(
                    this: &this->web,
                    subWebName: "swimming",
                    stateName: "turnright",
                    interruptPath_: INTR_PATH_YES,
                    interruptBlend_: INTR_BLEND_YES,
                    blendEventMask_: 0);
                  v214 = HS_SWIMMING_TURN_RIGHT;
                }
                else
                {
                  if ( currentSwimState == HS_SWIMMING_TURN_LEFT )
                    goto LABEL_642;
                  idAnimator_AnimWeb::ChangeState(
                    this: &this->web,
                    subWebName: "swimming",
                    stateName: "turnleft",
                    interruptPath_: INTR_PATH_YES,
                    interruptBlend_: INTR_BLEND_YES,
                    blendEventMask_: 0);
                  v214 = HS_SWIMMING_TURN_LEFT;
                }
              }
              else
              {
                if ( currentSwimState == HS_SWIMMING_DOWN )
                  goto LABEL_642;
                idAnimator_AnimWeb::ChangeState(
                  this: &this->web,
                  subWebName: "Swimming",
                  stateName: "Down",
                  interruptPath_: INTR_PATH_YES,
                  interruptBlend_: INTR_BLEND_YES,
                  blendEventMask_: 0);
                v214 = HS_SWIMMING_DOWN;
              }
            }
            else
            {
              if ( currentSwimState == HS_SWIMMING_UP )
                goto LABEL_642;
              idAnimator_AnimWeb::ChangeState(
                this: &this->web,
                subWebName: "Swimming",
                stateName: "Up",
                interruptPath_: INTR_PATH_YES,
                interruptBlend_: INTR_BLEND_YES,
                blendEventMask_: 0);
              v214 = HS_SWIMMING_UP;
            }
          }
          break;
      }
      this->currentSwimState = v214;
      goto LABEL_642;
    default:
      goto LABEL_642;
  }
}


// ========================================================================
// __unwind$506389
// EA  : 0x82E0DD78
// RVA : 0x00E0DD78
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506389()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1504 + 1296));
}


// ========================================================================
// __unwind$506390
// EA  : 0x82E0DDA0
// RVA : 0x00E0DDA0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506390()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1504 + 136));
}


// ========================================================================
// __unwind$506391
// EA  : 0x82E0DDC8
// RVA : 0x00E0DDC8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506391()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 416));
}


// ========================================================================
// __unwind$506392
// EA  : 0x82E0DDF0
// RVA : 0x00E0DDF0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506392()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 1168));
}


// ========================================================================
// __unwind$506393
// EA  : 0x82E0DE18
// RVA : 0x00E0DE18
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506393()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 992));
}


// ========================================================================
// __unwind$506394
// EA  : 0x82E0DE40
// RVA : 0x00E0DE40
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506394()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 1104));
}


// ========================================================================
// __unwind$506396
// EA  : 0x82E0DE68
// RVA : 0x00E0DE68
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506396()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 736));
}


// ========================================================================
// __unwind$506397
// EA  : 0x82E0DE90
// RVA : 0x00E0DE90
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506397()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 1232));
}


// ========================================================================
// __unwind$506398
// EA  : 0x82E0DEB8
// RVA : 0x00E0DEB8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506398()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 480));
}


// ========================================================================
// __unwind$506399
// EA  : 0x82E0DEE0
// RVA : 0x00E0DEE0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506399()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 1040));
}


// ========================================================================
// __unwind$506395
// EA  : 0x82E0DF08
// RVA : 0x00E0DF08
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506395()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 800));
}


// ========================================================================
// __unwind$506401
// EA  : 0x82E0DF30
// RVA : 0x00E0DF30
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506401()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 544));
}


// ========================================================================
// __unwind$506402
// EA  : 0x82E0DF58
// RVA : 0x00E0DF58
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506402()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 1072));
}


// ========================================================================
// __unwind$506403
// EA  : 0x82E0DF80
// RVA : 0x00E0DF80
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506403()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 864));
}


// ========================================================================
// __unwind$506400
// EA  : 0x82E0DFA8
// RVA : 0x00E0DFA8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506400()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 320));
}


// ========================================================================
// __unwind$506405
// EA  : 0x82E0DFD0
// RVA : 0x00E0DFD0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506405()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 928));
}


// ========================================================================
// __unwind$506406
// EA  : 0x82E0DFF8
// RVA : 0x00E0DFF8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506406()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 768));
}


// ========================================================================
// __unwind$506407
// EA  : 0x82E0E020
// RVA : 0x00E0E020
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506407()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 1136));
}


// ========================================================================
// __unwind$506408
// EA  : 0x82E0E048
// RVA : 0x00E0E048
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506408()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 672));
}


// ========================================================================
// __unwind$506404
// EA  : 0x82E0E070
// RVA : 0x00E0E070
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506404()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 256));
}


// ========================================================================
// __unwind$506410
// EA  : 0x82E0E098
// RVA : 0x00E0E098
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506410()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 896));
}


// ========================================================================
// __unwind$506411
// EA  : 0x82E0E0C0
// RVA : 0x00E0E0C0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506411()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 704));
}


// ========================================================================
// __unwind$506412
// EA  : 0x82E0E0E8
// RVA : 0x00E0E0E8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506412()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 1200));
}


// ========================================================================
// __unwind$506413
// EA  : 0x82E0E110
// RVA : 0x00E0E110
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506413()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 832));
}


// ========================================================================
// __unwind$506409
// EA  : 0x82E0E138
// RVA : 0x00E0E138
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506409()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 192));
}


// ========================================================================
// __unwind$506414
// EA  : 0x82E0E160
// RVA : 0x00E0E160
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506414()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 640));
}


// ========================================================================
// __unwind$506418
// EA  : 0x82E0E188
// RVA : 0x00E0E188
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506418()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 224));
}


// ========================================================================
// __unwind$506415
// EA  : 0x82E0E1B0
// RVA : 0x00E0E1B0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506415()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 608));
}


// ========================================================================
// __unwind$506416
// EA  : 0x82E0E1D8
// RVA : 0x00E0E1D8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506416()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 352));
}


// ========================================================================
// __unwind$506417
// EA  : 0x82E0E200
// RVA : 0x00E0E200
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506417()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 384));
}


// ========================================================================
// __unwind$506421
// EA  : 0x82E0E228
// RVA : 0x00E0E228
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506421()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 288));
}


// ========================================================================
// __unwind$506422
// EA  : 0x82E0E250
// RVA : 0x00E0E250
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506422()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 448));
}


// ========================================================================
// __unwind$506423
// EA  : 0x82E0E278
// RVA : 0x00E0E278
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506423()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 512));
}


// ========================================================================
// __unwind$506419
// EA  : 0x82E0E2A0
// RVA : 0x00E0E2A0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506419()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 576));
}


// ========================================================================
// __unwind$506420
// EA  : 0x82E0E2C8
// RVA : 0x00E0E2C8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void _unwind_506420()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1504 + 1264));
}


// ========================================================================
// `dynamic initializer for 'hands_depthHack''
// EA  : 0x83387578
// RVA : 0x01387578
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_depthHack__()
{
  idCVar::idCVar(
    this: &hands_depthHack,
    name: "hands_depthHack",
    value: "0.1",
    flags: 4,
    description: "tweak to avoid hands / weapons being clipped by world",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_depthHack__);
}


// ========================================================================
// `dynamic initializer for 'hands_depthHackSwim''
// EA  : 0x833875D0
// RVA : 0x013875D0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_depthHackSwim__()
{
  idCVar::idCVar(
    this: &hands_depthHackSwim,
    name: "hands_depthHackSwim",
    value: "0.75",
    flags: 4,
    description: "tweak to avoid hands / weapons being clipped by world, but while swimming on the surface of water",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_depthHackSwim__);
}


// ========================================================================
// `dynamic initializer for 'hands_debugfc''
// EA  : 0x83387628
// RVA : 0x01387628
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_debugfc__()
{
  idCVar::idCVar(
    this: &hands_debugfc,
    name: "hands_debugfc",
    value: "0",
    flags: 2,
    description: "> 0 = show frame commands callbacks",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_debugfc__);
}


// ========================================================================
// `dynamic initializer for 'hands_debugweb''
// EA  : 0x83387680
// RVA : 0x01387680
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_debugweb__()
{
  idCVar::idCVar(
    this: &hands_debugweb,
    name: "hands_debugweb",
    value: "0",
    flags: 1,
    description: "1 = show debug info for hands anim web",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_debugweb__);
}


// ========================================================================
// `dynamic initializer for 'hands_debugstate''
// EA  : 0x833876D8
// RVA : 0x013876D8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_debugstate__()
{
  idCVar::idCVar(
    this: &hands_debugstate,
    name: "hands_debugstate",
    value: "0",
    flags: 1,
    description: "1 = show debug info for hands state",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_debugstate__);
}


// ========================================================================
// `dynamic initializer for 'hands_usecvars''
// EA  : 0x83387730
// RVA : 0x01387730
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_usecvars__()
{
  idCVar::idCVar(
    this: &hands_usecvars,
    name: "hands_usecvars",
    value: "0",
    flags: 4,
    description: "Use cvars for hand movement/rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_usecvars__);
}


// ========================================================================
// `dynamic initializer for 'hands_lagClamp''
// EA  : 0x83387788
// RVA : 0x01387788
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_lagClamp__()
{
  idCVar::idCVar(
    this: &hands_lagClamp,
    name: "hands_lagClamp",
    value: "4",
    flags: 4,
    description: "Max lag distance from center to the left",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_lagClamp__);
}


// ========================================================================
// `dynamic initializer for 'hands_lagScale''
// EA  : 0x833877E0
// RVA : 0x013877E0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_lagScale__()
{
  idCVar::idCVar(
    this: &hands_lagScale,
    name: "hands_lagScale",
    value: "0.0005",
    flags: 4,
    description: "Amount of velocity applied to hands",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_lagScale__);
}


// ========================================================================
// `dynamic initializer for 'hands_lagRetain''
// EA  : 0x83387838
// RVA : 0x01387838
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_lagRetain__()
{
  idCVar::idCVar(
    this: &hands_lagRetain,
    name: "hands_lagRetain",
    value: ".95",
    flags: 4,
    description: "Lag retention rate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_lagRetain__);
}


// ========================================================================
// `dynamic initializer for 'hands_lagRecenter''
// EA  : 0x83387890
// RVA : 0x01387890
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_lagRecenter__()
{
  idCVar::idCVar(
    this: &hands_lagRecenter,
    name: "hands_lagRecenter",
    value: "0",
    flags: 4,
    description: "Lag recenter speed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_lagRecenter__);
}


// ========================================================================
// `dynamic initializer for 'hands_rotMinAnglesX''
// EA  : 0x833878E8
// RVA : 0x013878E8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_rotMinAnglesX__()
{
  idCVar::idCVar(
    this: &hands_rotMinAnglesX,
    name: "hands_rotMinAnglesX",
    value: "12",
    flags: 4,
    description: "min X-rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_rotMinAnglesX__);
}


// ========================================================================
// `dynamic initializer for 'hands_rotMinAnglesY''
// EA  : 0x83387940
// RVA : 0x01387940
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_rotMinAnglesY__()
{
  idCVar::idCVar(
    this: &hands_rotMinAnglesY,
    name: "hands_rotMinAnglesY",
    value: "12",
    flags: 4,
    description: "min Y-rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_rotMinAnglesY__);
}


// ========================================================================
// `dynamic initializer for 'hands_rotMinAnglesZ''
// EA  : 0x83387998
// RVA : 0x01387998
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_rotMinAnglesZ__()
{
  idCVar::idCVar(
    this: &hands_rotMinAnglesZ,
    name: "hands_rotMinAnglesZ",
    value: "12",
    flags: 4,
    description: "min Z-rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_rotMinAnglesZ__);
}


// ========================================================================
// `dynamic initializer for 'hands_rotMaxAnglesX''
// EA  : 0x833879F0
// RVA : 0x013879F0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_rotMaxAnglesX__()
{
  idCVar::idCVar(
    this: &hands_rotMaxAnglesX,
    name: "hands_rotMaxAnglesX",
    value: "12",
    flags: 4,
    description: "max X-rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_rotMaxAnglesX__);
}


// ========================================================================
// `dynamic initializer for 'hands_rotMaxAnglesY''
// EA  : 0x83387A48
// RVA : 0x01387A48
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_rotMaxAnglesY__()
{
  idCVar::idCVar(
    this: &hands_rotMaxAnglesY,
    name: "hands_rotMaxAnglesY",
    value: "12",
    flags: 4,
    description: "max Y-rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_rotMaxAnglesY__);
}


// ========================================================================
// `dynamic initializer for 'hands_rotMaxAnglesZ''
// EA  : 0x83387AA0
// RVA : 0x01387AA0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_rotMaxAnglesZ__()
{
  idCVar::idCVar(
    this: &hands_rotMaxAnglesZ,
    name: "hands_rotMaxAnglesZ",
    value: "12",
    flags: 4,
    description: "max Z-rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_rotMaxAnglesZ__);
}


// ========================================================================
// `dynamic initializer for 'hands_offsetAtMaxPitchX''
// EA  : 0x83387AF8
// RVA : 0x01387AF8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_offsetAtMaxPitchX__()
{
  idCVar::idCVar(
    this: &hands_offsetAtMaxPitchX,
    name: "hands_offsetAtMaxPitchX",
    value: "0",
    flags: 4,
    description: "X-Offset of hands when looking up",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_offsetAtMaxPitchX__);
}


// ========================================================================
// `dynamic initializer for 'hands_offsetAtMaxPitchY''
// EA  : 0x83387B50
// RVA : 0x01387B50
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_offsetAtMaxPitchY__()
{
  idCVar::idCVar(
    this: &hands_offsetAtMaxPitchY,
    name: "hands_offsetAtMaxPitchY",
    value: "0",
    flags: 4,
    description: "Y-Offset of hands when looking up",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_offsetAtMaxPitchY__);
}


// ========================================================================
// `dynamic initializer for 'hands_offsetAtMaxPitchZ''
// EA  : 0x83387BA8
// RVA : 0x01387BA8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_offsetAtMaxPitchZ__()
{
  idCVar::idCVar(
    this: &hands_offsetAtMaxPitchZ,
    name: "hands_offsetAtMaxPitchZ",
    value: "0",
    flags: 4,
    description: "Z-Offset of hands when looking up",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_offsetAtMaxPitchZ__);
}


// ========================================================================
// `dynamic initializer for 'hands_offsetAtMinPitchX''
// EA  : 0x83387C00
// RVA : 0x01387C00
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_offsetAtMinPitchX__()
{
  idCVar::idCVar(
    this: &hands_offsetAtMinPitchX,
    name: "hands_offsetAtMinPitchX",
    value: "0",
    flags: 4,
    description: "X-Offset of hands when looking down",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_offsetAtMinPitchX__);
}


// ========================================================================
// `dynamic initializer for 'hands_offsetAtMinPitchY''
// EA  : 0x83387C58
// RVA : 0x01387C58
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_offsetAtMinPitchY__()
{
  idCVar::idCVar(
    this: &hands_offsetAtMinPitchY,
    name: "hands_offsetAtMinPitchY",
    value: "0",
    flags: 4,
    description: "Y-Offset of hands when looking down",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_offsetAtMinPitchY__);
}


// ========================================================================
// `dynamic initializer for 'hands_offsetAtMinPitchZ''
// EA  : 0x83387CB0
// RVA : 0x01387CB0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_offsetAtMinPitchZ__()
{
  idCVar::idCVar(
    this: &hands_offsetAtMinPitchZ,
    name: "hands_offsetAtMinPitchZ",
    value: "0",
    flags: 4,
    description: "Z-Offset of hands when looking down",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_offsetAtMinPitchZ__);
}


// ========================================================================
// `dynamic initializer for 'hands_offsetByYaw''
// EA  : 0x83387D08
// RVA : 0x01387D08
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_offsetByYaw__()
{
  idCVar::idCVar(
    this: &hands_offsetByYaw,
    name: "hands_offsetByYaw",
    value: "0",
    flags: 4,
    description: "Offset compensation for yaw rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_offsetByYaw__);
}


// ========================================================================
// `dynamic initializer for 'hands_offsetByPitch''
// EA  : 0x83387D60
// RVA : 0x01387D60
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_offsetByPitch__()
{
  idCVar::idCVar(
    this: &hands_offsetByPitch,
    name: "hands_offsetByPitch",
    value: "0",
    flags: 4,
    description: "Offset compensation for pitch rotation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_offsetByPitch__);
}


// ========================================================================
// `dynamic initializer for 'hands_extraYawMul''
// EA  : 0x83387DB8
// RVA : 0x01387DB8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_extraYawMul__()
{
  idCVar::idCVar(
    this: &hands_extraYawMul,
    name: "hands_extraYawMul",
    value: "1.0f",
    flags: 4,
    description: "increase or decrease the final yaw. Used in combination with  offsetByYaw",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_extraYawMul__);
}


// ========================================================================
// `dynamic initializer for 'hands_extraPitchMul''
// EA  : 0x83387E10
// RVA : 0x01387E10
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_extraPitchMul__()
{
  idCVar::idCVar(
    this: &hands_extraPitchMul,
    name: "hands_extraPitchMul",
    value: "1.0f",
    flags: 4,
    description: "increase or decrease the final pitch. Used in combination with  offsetByPitch",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_extraPitchMul__);
}


// ========================================================================
// `dynamic initializer for 'hands_rotScale''
// EA  : 0x83387E68
// RVA : 0x01387E68
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_rotScale__()
{
  idCVar::idCVar(
    this: &hands_rotScale,
    name: "hands_rotScale",
    value: "0.2",
    flags: 4,
    description: "Amount of rotation applied to hands",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_rotScale__);
}


// ========================================================================
// `dynamic initializer for 'hands_rotRetain''
// EA  : 0x83387EC0
// RVA : 0x01387EC0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_rotRetain__()
{
  idCVar::idCVar(
    this: &hands_rotRetain,
    name: "hands_rotRetain",
    value: "-0.0066",
    flags: 4,
    description: "Rotation retention rate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_rotRetain__);
}


// ========================================================================
// `dynamic initializer for 'hands_rotRecenter''
// EA  : 0x83387F18
// RVA : 0x01387F18
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_rotRecenter__()
{
  idCVar::idCVar(
    this: &hands_rotRecenter,
    name: "hands_rotRecenter",
    value: "0.015",
    flags: 4,
    description: "Lag recenter speed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_rotRecenter__);
}


// ========================================================================
// `dynamic initializer for 'hands_show''
// EA  : 0x83387F70
// RVA : 0x01387F70
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_show__()
{
  idCVar::idCVar(
    this: &hands_show,
    name: "hands_show",
    value: "1",
    flags: 1,
    description: "1 = show gun",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_show__);
}


// ========================================================================
// `dynamic initializer for 'hands_updatePos''
// EA  : 0x83387FC8
// RVA : 0x01387FC8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_updatePos__()
{
  idCVar::idCVar(
    this: &hands_updatePos,
    name: "hands_updatePos",
    value: "1",
    flags: 1,
    description: "1 = update position to match player view, 0 = leave hands where they currently are",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_updatePos__);
}


// ========================================================================
// `dynamic initializer for 'hands_updateAnim''
// EA  : 0x83388020
// RVA : 0x01388020
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_updateAnim__()
{
  idCVar::idCVar(
    this: &hands_updateAnim,
    name: "hands_updateAnim",
    value: "1",
    flags: 1,
    description: "1 = update hands animations",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_updateAnim__);
}


// ========================================================================
// `dynamic initializer for 'hands_offsetX''
// EA  : 0x83388078
// RVA : 0x01388078
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_offsetX__()
{
  idCVar::idCVar(
    this: &hands_offsetX,
    name: "hands_offsetX",
    value: "0",
    flags: 4,
    description: "position of the gun in the x coordinate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_offsetX__);
}


// ========================================================================
// `dynamic initializer for 'hands_offsetY''
// EA  : 0x833880D0
// RVA : 0x013880D0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_offsetY__()
{
  idCVar::idCVar(
    this: &hands_offsetY,
    name: "hands_offsetY",
    value: "0",
    flags: 4,
    description: "position of the gun in the y coordinate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_offsetY__);
}


// ========================================================================
// `dynamic initializer for 'hands_offsetZ''
// EA  : 0x83388128
// RVA : 0x01388128
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_offsetZ__()
{
  idCVar::idCVar(
    this: &hands_offsetZ,
    name: "hands_offsetZ",
    value: "0",
    flags: 4,
    description: "position of the gun in the z coordinate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_offsetZ__);
}


// ========================================================================
// `dynamic initializer for 'hands_fovScale''
// EA  : 0x83388180
// RVA : 0x01388180
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_fovScale__()
{
  idCVar::idCVar(
    this: &hands_fovScale,
    name: "hands_FovScale",
    value: "0.0",
    flags: 4,
    description: "scale the fov for gun models by this float value",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_fovScale__);
}


// ========================================================================
// `dynamic initializer for 'hands_showBlendTree''
// EA  : 0x833881D8
// RVA : 0x013881D8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_showBlendTree__()
{
  idCVar::idCVar(
    this: &hands_showBlendTree,
    name: "hands_showBlendTree",
    value: "0",
    flags: 2,
    description: "1 = show the blend tree for the hands, 2 = show the blend tree for the right hand item, 3 = show the blend tree for "
    "the left hand item",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_showBlendTree__);
}


// ========================================================================
// `dynamic initializer for 'hands_blendTree''
// EA  : 0x83388230
// RVA : 0x01388230
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_blendTree__()
{
  idCVar::idCVar(
    this: &hands_blendTree,
    name: "hands_blendTree",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_blendTree__);
}


// ========================================================================
// `dynamic initializer for 'tw_offsetX''
// EA  : 0x83388288
// RVA : 0x01388288
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tw_offsetX__()
{
  idCVar::idCVar(
    this: &tw_offsetX,
    name: "tw_offsetX",
    value: "0",
    flags: 4,
    description: "sets the x axis offset for the test weapon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tw_offsetX__);
}


// ========================================================================
// `dynamic initializer for 'tw_offsetY''
// EA  : 0x833882E0
// RVA : 0x013882E0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tw_offsetY__()
{
  idCVar::idCVar(
    this: &tw_offsetY,
    name: "tw_offsetY",
    value: "0",
    flags: 4,
    description: "sets the y axis offset for the test weapon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tw_offsetY__);
}


// ========================================================================
// `dynamic initializer for 'tw_offsetZ''
// EA  : 0x83388338
// RVA : 0x01388338
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tw_offsetZ__()
{
  idCVar::idCVar(
    this: &tw_offsetZ,
    name: "tw_offsetZ",
    value: "0",
    flags: 4,
    description: "sets the z axis offset for the test weapon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tw_offsetZ__);
}


// ========================================================================
// `dynamic initializer for 'tw_pitch''
// EA  : 0x83388390
// RVA : 0x01388390
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tw_pitch__()
{
  idCVar::idCVar(
    this: &tw_pitch,
    name: "tw_pitch",
    value: "0",
    flags: 4,
    description: "sets the pitch for the test weapon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tw_pitch__);
}


// ========================================================================
// `dynamic initializer for 'tw_yaw''
// EA  : 0x833883E8
// RVA : 0x013883E8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tw_yaw__()
{
  idCVar::idCVar(
    this: &tw_yaw,
    name: "tw_yaw",
    value: "0",
    flags: 4,
    description: "sets the yaw for the test weapon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tw_yaw__);
}


// ========================================================================
// `dynamic initializer for 'tw_roll''
// EA  : 0x83388440
// RVA : 0x01388440
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tw_roll__()
{
  idCVar::idCVar(
    this: &tw_roll,
    name: "tw_roll",
    value: "0",
    flags: 4,
    description: "sets the roll for the test weapon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tw_roll__);
}


// ========================================================================
// `dynamic initializer for 'tw_fovScale''
// EA  : 0x83388498
// RVA : 0x01388498
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__tw_fovScale__()
{
  idCVar::idCVar(
    this: &tw_fovScale,
    name: "tw_fovScale",
    value: "0.7",
    flags: 4,
    description: "sets the scale for the test weapon's field of view",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__tw_fovScale__);
}


// ========================================================================
// `dynamic initializer for 'hands_idleaccent_delay''
// EA  : 0x833884F0
// RVA : 0x013884F0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_idleaccent_delay__()
{
  idCVar::idCVar(
    this: &hands_idleaccent_delay,
    name: "hands_idleaccent_delay",
    value: "300000",
    flags: 2,
    description: "how many milliseconds of inactivity before we do the accent idle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_idleaccent_delay__);
}


// ========================================================================
// `dynamic initializer for 'hands_mh_shift_delay''
// EA  : 0x83388548
// RVA : 0x01388548
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_mh_shift_delay__()
{
  idCVar::idCVar(
    this: &hands_mh_shift_delay,
    name: "hands_mh_shift_delay",
    value: "7000",
    flags: 2,
    description: "how many milliseconds of inactivity before we shift idle MH",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_mh_shift_delay__);
}


// ========================================================================
// `dynamic initializer for 'hands_meleeOffset''
// EA  : 0x833885A0
// RVA : 0x013885A0
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_meleeOffset__()
{
  idCVar::idCVar(
    this: &hands_meleeOffset,
    name: "hands_meleeOffset",
    value: "20.0",
    flags: 4,
    description: "how many units to offset the melee traces by",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_meleeOffset__);
}


// ========================================================================
// `dynamic initializer for 'hands_meleeComboInterval''
// EA  : 0x833885F8
// RVA : 0x013885F8
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__hands_meleeComboInterval__()
{
  idCVar::idCVar(
    this: &hands_meleeComboInterval,
    name: "hands_meleeComboInterval",
    value: "750",
    flags: 2,
    description: "successive melee hits must occur within this interval to perform a combo",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__hands_meleeComboInterval__);
}


// ========================================================================
// `dynamic initializer for 'hands_SetRelaxed_v''
// EA  : 0x83388650
// RVA : 0x01388650
// PDB : w:\tech5\tungsten\game\player\hands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__hands_SetRelaxed_v__()
{
  return idCommandLink::idCommandLink(
           this: &hands_SetRelaxed_v,
           cmdName: "hands_SetRelaxed",
           function: hands_SetRelaxed_f,
           description: "go to relaxed mode",
           argCompletion: nullptr);
}

