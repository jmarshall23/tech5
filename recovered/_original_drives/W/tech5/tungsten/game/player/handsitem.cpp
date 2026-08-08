
// ========================================================================
// ?FreePresentable@idHandsItem@@QAAXXZ
// EA  : 0x82E0E2F0
// RVA : 0x00E0E2F0
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::FreePresentable(idHandsItem *this)
{
  idPresentableAnimatedEntity *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    idPresentable::Delete(this: presentable);
    this->presentable = nullptr;
  }
}


// ========================================================================
// ?Draw@idHandsItem@@QAAXXZ
// EA  : 0x82E0E330
// RVA : 0x00E0E330
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::Draw(idHandsItem *this)
{
  idPresentableAnimatedEntity *presentable; // r11

  presentable = this->presentable;
  if ( presentable != nullptr )
    ((void (*)(void))presentable->Present)();
}


// ========================================================================
// ?GetTreeAnimatorFromPresentable@idHandsItem@@QBAPAVidTreeAnimator@@XZ
// EA  : 0x82E0E358
// RVA : 0x00E0E358
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

idTreeAnimator *__fastcall idHandsItem::GetTreeAnimatorFromPresentable(idHandsItem *this)
{
  idPresentableAnimatedEntity *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return idPresentableAnimatedEntity::GetTreeAnimator(this: presentable);
  else
    return nullptr;
}


// ========================================================================
// ?GetPresentable@idHandsItem@@QAAPAVidPresentable@@XZ
// EA  : 0x82E0E370
// RVA : 0x00E0E370
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

idPresentableAnimatedEntity *__fastcall idHandsItem::GetPresentable(idHandsItem *this)
{
  return this->presentable;
}


// ========================================================================
// ??1idHandsItem@@QAA@XZ
// EA  : 0x82E0E380
// RVA : 0x00E0E380
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::~idHandsItem(idHandsItem *this)
{
  idPresentableAnimatedEntity *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    idPresentable::Delete(this: presentable);
    this->presentable = nullptr;
  }
  idAnimEventHandler::~idAnimEventHandler(this: &this->animEventHandler);
}


// ========================================================================
// __unwind$488146_1
// EA  : 0x82E0E3D8
// RVA : 0x00E0E3D8
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void _unwind_488146_1()
{
  int v0; // r12

  idAnimEventHandler::~idAnimEventHandler(this: (idAnimEventHandler *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ?Clear@idHandsItem@@QAAXXZ
// EA  : 0x82E0E408
// RVA : 0x00E0E408
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::Clear(idHandsItem *this)
{
  idPresentableAnimatedEntity *presentable; // r11
  idRenderModel *model; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    model = presentable->model;
    if ( model != nullptr )
    {
      model->unlinked = true;
      model->deleteOnSync = true;
      idRenderModel::CommitThisFrame(this: model);
    }
    this->presentable->SetRenderModel(this: this->presentable, a2: nullptr, a3: true);
  }
  this->itemDecl = nullptr;
  this->item = nullptr;
  this->lastWeapon = nullptr;
  this->hidden = false;
}


// ========================================================================
// ?Hide@idHandsItem@@QAAXXZ
// EA  : 0x82E0E488
// RVA : 0x00E0E488
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::Hide(idHandsItem *this)
{
  idPresentableAnimatedEntity *presentable; // r3
  idInventoryItem *item; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->Hide(this: presentable, a2: true);
  item = this->item;
  if ( item != nullptr )
    item->Hide(this: item);
  this->hidden = true;
}


// ========================================================================
// ?GetFXMgr@idHandsItem@@QAAPAVidFXManager@@XZ
// EA  : 0x82E0E510
// RVA : 0x00E0E510
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

idFXManager *__fastcall idHandsItem::GetFXMgr(idHandsItem *this)
{
  idPresentableAnimatedEntity *presentable; // r11
  idFXManager *result; // r3

  presentable = this->presentable;
  result = &presentable->fxManager;
  if ( presentable == nullptr )
    return nullptr;
  return result;
}


// ========================================================================
// ?StartFX@idHandsItem@@QAAXW4fxCondition_t@@@Z
// EA  : 0x82E0E528
// RVA : 0x00E0E528
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::StartFX(idHandsItem *this, int cond)
{
  idPresentableAnimatedEntity *presentable; // r11
  int GameMs; // r3
  idVec3 v6; // [sp+50h] [-50h] BYREF
  idMat3 v7; // [sp+60h] [-40h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    ((void (*)(void))presentable->GetWorldTransform)();
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idFXManager::StartFX(this: &this->presentable->fxManager, org: &v6, axis: &v7, time: GameMs, startCondition: cond);
  }
}


// ========================================================================
// ?StopFX@idHandsItem@@QAAXW4fxCondition_t@@@Z
// EA  : 0x82E0E5B8
// RVA : 0x00E0E5B8
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::StopFX(idHandsItem *this, int cond)
{
  idPresentableAnimatedEntity *presentable; // r11
  idFXManager *p_fxManager; // r31
  int v5; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    p_fxManager = &presentable->fxManager;
    v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idFXManager::StopFX(this: p_fxManager, time: v5, stopCondition: cond, immediateStop: false);
  }
}


// ========================================================================
// ?Show@idHandsItem@@QAAXXZ
// EA  : 0x82E0E628
// RVA : 0x00E0E628
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::Show(idHandsItem *this)
{
  idPresentableAnimatedEntity *presentable; // r11
  idRenderModel *model; // r11
  idInventoryItem *item; // r3

  presentable = this->presentable;
  if ( presentable != nullptr && (model = presentable->model) != nullptr )
  {
    model->useDeferredPosition = false;
    this->presentable->model->g.modelDepthHack = hands_depthHack.valueFloat;
    *((_BYTE *)&this->presentable->model->g + 105) |= 0x80u;
    this->presentable->Show(this: this->presentable);
    item = this->item;
    if ( item != nullptr )
      item->Show(this: item);
    this->hidden = false;
  }
  else
  {
    this->hidden = false;
  }
}


// ========================================================================
// ?Attach@idHandsItem@@QAAXPAVidHands@@PBVidDeclInventory@@W4equipSlot_t@@_N@Z
// EA  : 0x82E0E6F0
// RVA : 0x00E0E6F0
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::Attach(
        idHandsItem *this,
        idHands *hands,
        const idDeclInventory *itemDecl,
        const equipSlot_t slot,
        bool initFX)
{
  idPresentableAnimatedEntity *presentable; // r11
  idRenderModel *model; // r3
  const idDeclMD6 *handsModelMD6; // r29
  idRenderModel *v12; // r3
  idTreeAnimator *v13; // r28
  const idDeclFX *weaponFX; // r29
  idPresentableAnimatedEntity *v15; // r3
  int v16; // r9
  int v17; // r8
  int v18; // r7
  idPresentableAnimatedEntity *v19; // r3
  idPresentableAnimatedEntity *v20; // r3
  int v21; // [sp+8h] [-98h]
  int v22; // [sp+Ch] [-94h]
  int v23; // [sp+10h] [-90h]
  int v24; // [sp+14h] [-8Ch]
  int v25; // [sp+18h] [-88h]
  idPresentable *v26; // [sp+1Ch] [-84h]

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    model = presentable->model;
    if ( model != nullptr )
    {
      model->unlinked = true;
      model->deleteOnSync = true;
      idRenderModel::CommitThisFrame(this: model);
    }
    this->presentable->SetRenderModel(this: this->presentable, a2: nullptr, a3: true);
  }
  this->itemDecl = itemDecl;
  handsModelMD6 = itemDecl->handsModelMD6;
  if ( handsModelMD6 != nullptr && hands->presentable != nullptr )
  {
    v12 = clientGame->renderWorld->AllocRenderModel(
            this: clientGame->renderWorld,
            a2: handsModelMD6->name.str,
            a3: 1,
            a4: -1);
    if ( v12 != nullptr )
    {
      v13 = (idTreeAnimator *)_RTDynamicCast(
                                inptr: v12,
                                VfDelta: 0,
                                SrcType: &idRenderModel `RTTI Type Descriptor',
                                TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                isReference: 0);
      if ( v13 != nullptr )
      {
        weaponFX = nullptr;
        if ( initFX )
          weaponFX = itemDecl->weaponFX;
        v15 = this->presentable;
        if ( v15 != nullptr )
        {
          v15->SetRenderModel(this: v15, a2: v13, a3: true);
        }
        else
        {
          v19 = (idPresentableAnimatedEntity *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                 size: 0x4E0u,
                                                 tag: TAG_PRESENTABLE,
                                                 zeroBuffer: false,
                                                 align: ALIGN_16,
                                                 heap: HEAP_DEFAULTHEAP);
          if ( v19 != nullptr )
            v20 = idPresentableAnimatedEntity::idPresentableAnimatedEntity(
                    this: v19,
                    ent: nullptr,
                    renderModel_: v13,
                    animStack_: nullptr,
                    entityNumber_: 0x1FFF,
                    fxDecl_: weaponFX,
                    useSphereModel_: false);
          else
            v20 = nullptr;
          this->presentable = v20;
          v20->debugName = "idHandsItem";
          idClientGame::AddPresentable(
            this: clientGame,
            presentable: this->presentable,
            index: -1,
            skipReplication: true,
            a5: v18,
            a6: v17,
            a7: v16,
            a8: (int)"idHandsItem",
            a9: v21,
            a10: v22,
            a11: v23,
            a12: v24,
            a13: v25,
            a14: v26);
        }
        if ( initFX )
        {
          idPresentable::ResetFXMgr(this: this->presentable, fxDecl_: weaponFX);
          this->presentable->fxManager.allowSurfaceOnlyInViewID = hands->owner->entityNumber + 1;
        }
        if ( !hands->disabled && hands->hiddenReasons == 0 )
        {
          idPresentable::SetGroupMaster(this: this->presentable, pres: hands->presentable);
          idHandsItem::Show(this);
          idHands::ShowHands(this: hands);
        }
        this->presentable->model->g.allowSurfaceOnlyInViewID = hands->owner->entityNumber + 1;
      }
      else
      {
        idLib::Warning(fmt: "Cannot attach '%s' to hands. Player weapons must be .md6 models", handsModelMD6->name.str);
      }
    }
  }
}


// ========================================================================
// __unwind$488287
// EA  : 0x82E0E910
// RVA : 0x00E0E910
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void _unwind_488287()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?JobSync@idHandsItem@@QAAXXZ
// EA  : 0x82E0E940
// RVA : 0x00E0E940
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::JobSync(idHandsItem *this)
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
}


// ========================================================================
// ?Reset@idHandsItem@@QAAXXZ
// EA  : 0x82E0E9C0
// RVA : 0x00E0E9C0
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::Reset(idHandsItem *this)
{
  idWeapon *v1; // r3

  v1 = idWeapon::CastTo(c: (idWeapon *)this->item);
  if ( v1 != nullptr )
    idWeapon::SetFireState(this: v1, fs: FIRESTATE_IDLE);
}


// ========================================================================
// ?GetMuzzlePosition@idHandsItem@@QBA_NPBVidHands@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82E0E9F8
// RVA : 0x00E0E9F8
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

int __fastcall idHandsItem::GetMuzzlePosition(idHandsItem *this, idHands *hands, idVec3 *origin, idMat3 *axis)
{
  idPresentableAnimatedEntity *presentable; // r3
  const idTreeAnimator *TreeAnimator; // r28
  idWeapon *v11; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  handsTag_t tagIndex; // r11
  idTreeAnimator *v14; // r29
  idPropsCollection *p_props; // r3
  const char *v16; // r5
  const tagData_t *Tag; // r4

  presentable = this->presentable;
  if ( presentable == nullptr )
    return 0;
  TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: presentable);
  if ( TreeAnimator == nullptr )
    return 0;
  v11 = idWeapon::CastTo(c: (idWeapon *)this->item);
  if ( v11 != nullptr )
    return idWeapon::GetMuzzleFlashWorldTransform(this: v11, ta: TreeAnimator, attackType: ATTACK_DEFAULT, origin, axis);
  TreeAnimatorFromPresentable = idHands::GetTreeAnimatorFromPresentable(this: hands);
  tagIndex = this->tagIndex;
  v14 = TreeAnimatorFromPresentable;
  p_props = &TreeAnimatorFromPresentable->decl->props;
  if ( (unsigned int)tagIndex > HANDSTAG_LEFT )
    v16 = &byte_8200D768;
  else
    v16 = idHands::HANDSTAGS[tagIndex];
  Tag = idPropsCollection::GetTag(this: p_props, propName: this->itemDecl->handsModelMD6->name.str, tagName: v16);
  if ( Tag->parentJoint.value != 0xFFFF )
    return idTreeAnimator::GetWorldSpaceTagTransform(this: v14, tagData: Tag, origin, axis);
  *origin = vec3_origin;
  *axis = mat3_identity;
  return 0;
}


// ========================================================================
// ?WeaponBarrelSpin@idHandsItem@@QAA_NXZ
// EA  : 0x82E0EB60
// RVA : 0x00E0EB60
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

BOOL __fastcall idHandsItem::WeaponBarrelSpin(idHandsItem *this)
{
  idPresentableAnimatedEntity *presentable; // r3
  idTreeAnimator *TreeAnimator; // r30
  idWeapon *v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: presentable);
  else
    TreeAnimator = nullptr;
  v4 = idWeapon::CastTo(c: (idWeapon *)this->item);
  return v4 != nullptr
      && TreeAnimator != nullptr
      && HIBYTE(v4->decl[3].internalName.data) != 0
      && idWeapon::SpinBarrel(this: v4, parentModel: TreeAnimator);
}


// ========================================================================
// ?UpdateJointMods@idHandsItem@@QAAXXZ
// EA  : 0x82E0EBD8
// RVA : 0x00E0EBD8
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::UpdateJointMods(idHandsItem *this)
{
  idPresentableAnimatedEntity *presentable; // r3
  idTreeAnimator *TreeAnimator; // r31
  idWeapon *v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: presentable);
  else
    TreeAnimator = nullptr;
  v4 = idWeapon::CastTo(c: (idWeapon *)this->item);
  if ( v4 != nullptr && TreeAnimator != nullptr )
    v4->UpdateJointMods(this: v4, a2: TreeAnimator);
}


// ========================================================================
// ?SetBarrelSpinThrottle@idHandsItem@@QAAX_N@Z
// EA  : 0x82E0EC50
// RVA : 0x00E0EC50
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::SetBarrelSpinThrottle(idHandsItem *this, bool fullThrottle)
{
  idWeapon *v3; // r3

  v3 = idWeapon::CastTo(c: (idWeapon *)this->item);
  if ( v3 != nullptr && HIBYTE(v3->decl[3].internalName.data) != 0 )
    v3->fullSpinThrottle = fullThrottle;
}


// ========================================================================
// ?GetLaserSightPosition@idHandsItem@@QBA_NPBVidHands@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82E0ECA0
// RVA : 0x00E0ECA0
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

BOOL __fastcall idHandsItem::GetLaserSightPosition(
        idHandsItem *this,
        const idHands *hands,
        idVec3 *origin,
        idMat3 *axis)
{
  idWeapon *v7; // r30
  idPresentableAnimatedEntity *presentable; // r3
  const idTreeAnimator *TreeAnimator; // r4

  v7 = idWeapon::CastTo(c: (idWeapon *)this->item);
  return v7 != nullptr
      && (presentable = this->presentable) != nullptr
      && (TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: presentable)) != nullptr
      && idWeapon::GetLaserSightWorldTransform(this: v7, ta: TreeAnimator, origin, axis);
}


// ========================================================================
// ??0idHandsItem@@QAA@W4equipSlot_t@@W4handsTag_t@@@Z
// EA  : 0x82E0ED10
// RVA : 0x00E0ED10
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

idHandsItem *__fastcall idHandsItem::idHandsItem(idHandsItem *this, equipSlot_t slot, handsTag_t tagIndex)
{
  this->slot = slot;
  this->itemDecl = nullptr;
  idAnimEventHandler::idAnimEventHandler(this: &this->animEventHandler);
  this->item = nullptr;
  this->lastWeapon = nullptr;
  this->itemEjectLeftTagData.trans.x = 0.0;
  this->itemEjectLeftTagData.trans.y = 0.0;
  this->itemEjectLeftTagData.trans.z = 0.0;
  this->itemEjectLeftTagData.rot.x = 0.0;
  this->itemEjectLeftTagData.rot.y = 0.0;
  this->itemEjectLeftTagData.rot.z = 0.0;
  this->itemEjectLeftTagData.rot.w = 0.0;
  this->itemEjectLeftTagData.parentJoint.value = -1;
  this->itemEjectRightTagData.trans.x = 0.0;
  this->itemEjectRightTagData.trans.y = 0.0;
  this->itemEjectRightTagData.trans.z = 0.0;
  this->itemEjectRightTagData.rot.x = 0.0;
  this->itemEjectRightTagData.rot.y = 0.0;
  this->itemEjectRightTagData.rot.z = 0.0;
  this->itemEjectRightTagData.rot.w = 0.0;
  this->itemEjectRightTagData.parentJoint.value = -1;
  this->tagIndex = tagIndex;
  this->hidden = false;
  this->presentable = nullptr;
  return this;
}


// ========================================================================
// ?StartVideo@idHandsItem@@QAAXXZ
// EA  : 0x82E0EDB8
// RVA : 0x00E0EDB8
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::StartVideo(idHandsItem *this)
{
  idPresentableAnimatedEntity *presentable; // r3
  idTreeAnimator *TreeAnimator; // r3
  idTreeAnimator *v4; // r31
  int MeshIndex; // r3
  idWeapon *v6; // r3
  idWeapon *v7; // r31
  int v8; // r29

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: presentable);
    v4 = TreeAnimator;
    if ( TreeAnimator != nullptr )
    {
      MeshIndex = idTreeAnimator::GetMeshIndex(this: TreeAnimator, meshName: "screen");
      if ( MeshIndex >= 0 )
        v4->meshVisibility.list[MeshIndex] = true;
      v6 = idWeapon::CastTo(c: (idWeapon *)this->item);
      v7 = v6;
      if ( v6 != nullptr && *(_DWORD *)&v6->decl[3].sellStack != 0 )
      {
        v8 = videoManager->GetWeaponVideoIndex(this: videoManager);
        videoManager->BindVideo(this: videoManager, a2: v8, a3: *(const idInGameVideoFile **)&v7->decl[3].sellStack);
        videoManager->SetVideoTime(this: videoManager, a2: v8, a3: 0);
        videoManager->SetLooping(this: videoManager, a2: v8, a3: false);
        videoManager->SetPaused(this: videoManager, a2: v8, a3: false);
      }
    }
  }
}


// ========================================================================
// ?StopVideo@idHandsItem@@QAAXXZ
// EA  : 0x82E0EEC8
// RVA : 0x00E0EEC8
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::StopVideo(idHandsItem *this)
{
  idPresentableAnimatedEntity *presentable; // r3
  idTreeAnimator *TreeAnimator; // r3
  idTreeAnimator *v4; // r31
  int MeshIndex; // r3
  idWeapon *v6; // r3
  int v7; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: presentable);
    v4 = TreeAnimator;
    if ( TreeAnimator != nullptr )
    {
      MeshIndex = idTreeAnimator::GetMeshIndex(this: TreeAnimator, meshName: "screen");
      if ( MeshIndex >= 0 )
        v4->meshVisibility.list[MeshIndex] = false;
      v6 = idWeapon::CastTo(c: (idWeapon *)this->item);
      if ( v6 != nullptr && *(_DWORD *)&v6->decl[3].sellStack != 0 )
      {
        v7 = videoManager->GetWeaponVideoIndex(this: videoManager);
        videoManager->SetPaused(this: videoManager, a2: v7, a3: true);
      }
    }
  }
}


// ========================================================================
// ?Attach@idHandsItem@@QAAXPAVidHands@@PAVidInventoryItem@@W4equipSlot_t@@_N@Z
// EA  : 0x82E0EF90
// RVA : 0x00E0EF90
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::Attach(idHandsItem *this, idHands *hands, idWeapon *item, equipSlot_t slot, bool initFX)
{
  idWeapon *v6; // r3
  idWeapon *v11; // r28
  idPresentableAnimatedEntity *presentable; // r3
  idTreeAnimator *TreeAnimator; // r30
  idPresentableAnimatedEntity *v14; // r3
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r29
  const idDeclInventory *v17; // r11
  const idDeclInventory *v18; // r11
  const idDeclInventory *v19; // r11

  v6 = (idWeapon *)this->item;
  if ( v6 != nullptr && v6 != item )
    this->lastWeapon = idWeapon::CastTo(c: v6);
  this->item = item;
  idHandsItem::Attach(this, hands, itemDecl: item->decl, slot, initFX);
  v11 = idWeapon::CastTo(c: (idWeapon *)this->item);
  if ( v11 != nullptr )
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
      TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: presentable);
    else
      TreeAnimator = nullptr;
    v14 = this->presentable;
    if ( v14 != nullptr )
      idPresentable::UpdateModelTransform(this: v14);
    if ( TreeAnimator != nullptr )
    {
      decl = TreeAnimator->decl;
      if ( decl != nullptr )
      {
        p_props = &decl->props;
        if ( decl != (const idDeclMD6 *)-352 )
        {
          v17 = v11->decl;
          if ( *(_DWORD *)&v17[3].giveable != 0 )
            this->itemEjectLeftTagData = *idPropsCollection::GetTag(
                                            this: p_props,
                                            propName: "_info",
                                            tagName: (const char *)LODWORD(v17[3].droppedControllerShake.highMagnitude));
          v18 = v11->decl;
          if ( *(_DWORD *)v18[3].vehicleJointName.baseBuffer != 0 )
            this->itemEjectRightTagData = *idPropsCollection::GetTag(
                                             this: p_props,
                                             propName: "_info",
                                             tagName: *(const char **)&v18[3].vehicleJointName.baseBuffer[4]);
        }
      }
    }
    v19 = v11->decl;
    if ( *(_DWORD *)&v19[3].sellStack != 0 && HIBYTE(v19[3].price) == 0 )
      idHandsItem::StopVideo(this);
  }
}


// ========================================================================
// ?UpdatePosition@idHandsItem@@QAAXPAVidHands@@@Z
// EA  : 0x82E0F150
// RVA : 0x00E0F150
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::UpdatePosition(idHandsItem *this, idHands *hands)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idWeapon *v6; // r28
  idTreeAnimator *TreeAnimatorFromPresentable; // r29
  handsTag_t tagIndex; // r11
  const idDeclMD6 *handsModelMD6; // r26
  const char *v10; // r27
  const tagData_t *Tag; // r4
  idPresentableAnimatedEntity *presentable; // r11
  idPresentablePlayer *owner; // r29
  idWeapon::weaponState_t weaponState; // r27
  idWeapon *v15; // r3
  __int64 v16; // r8
  double v17; // fp31
  char v18; // r27
  float x; // r11
  float y; // r10
  idPlayer *ActorEntity; // r3
  idPlayer *v22; // r3
  idFocusTracker *FocusTracker; // r3
  double v24; // fp0
  double v25; // fp0
  double z; // fp30
  double v27; // fp29
  double v28; // fp28
  idPresentableActor *v29; // r3
  int entityNumber; // r29
  idWeapon_vtbl *v31; // r27
  idActor *v32; // r3
  idRenderWorld *v33; // r3
  idVec3 v34; // [sp+50h] [-1A0h] BYREF
  idVec3 v35; // [sp+60h] [-190h] BYREF
  idVec3 v36; // [sp+70h] [-180h] BYREF
  float v37[4]; // [sp+80h] [-170h] BYREF
  idPLogScope v38; // [sp+90h] [-160h] BYREF
  idVec3 v39; // [sp+98h] [-158h] BYREF
  idVec3 v40; // [sp+A8h] [-148h] BYREF
  idMat3 v41; // [sp+C0h] [-130h] BYREF
  idMat3 v42; // [sp+F0h] [-100h] BYREF
  idVec3 v43[2]; // [sp+118h] [-D8h] BYREF
  idMat3 v44; // [sp+130h] [-C0h] BYREF
  idMat3 v45[2]; // [sp+160h] [-90h] BYREF

  RD_EventBegin(name: "idHandsItem::UpdatePosition");
  LODWORD(v4) = "idHandsItem::UpdatePosition";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v38, pl: &pLog, gMask: v4, label: v5);
  if ( this->presentable == nullptr || this->itemDecl == nullptr )
  {
_M489341_1:
    idPLogScope::~idPLogScope(this: &v38);
    goto LABEL_24;
  }
  v6 = idWeapon::CastTo(c: (idWeapon *)this->item);
  TreeAnimatorFromPresentable = idHands::GetTreeAnimatorFromPresentable(this: hands);
  idPresentable::UpdateModelTransform(this: hands->presentable);
  tagIndex = this->tagIndex;
  handsModelMD6 = this->itemDecl->handsModelMD6;
  if ( (unsigned int)tagIndex > HANDSTAG_LEFT )
    v10 = &byte_8200D768;
  else
    v10 = idHands::HANDSTAGS[tagIndex];
  Tag = idPropsCollection::GetTag(
          this: &TreeAnimatorFromPresentable->decl->props,
          propName: handsModelMD6->name.str,
          tagName: v10);
  if ( Tag->parentJoint.value != 0xFFFF )
  {
    idTreeAnimator::GetWorldSpaceTagTransform(this: TreeAnimatorFromPresentable, tagData: Tag, origin: &v39, axis: &v41);
    LODWORD(v34.x) = &this->presentable->origin;
    *(idVec3 *)LODWORD(v34.x) = v39;
    presentable = this->presentable;
    presentable->axis.mat[0].x = v41.mat[0].x;
    presentable->axis.mat[0].y = v41.mat[0].y;
    presentable->axis.mat[0].z = v41.mat[0].z;
    LODWORD(v34.x) = &presentable->axis.mat[2];
    presentable->axis.mat[1] = v41.mat[1];
    presentable->axis.mat[2] = v41.mat[2];
    this->presentable->model->g.fovScale = TreeAnimatorFromPresentable->g.fovScale;
    this->presentable->Present(this: this->presentable);
    this->presentable->UpdateFX_3(
      this: this->presentable,
      a2: TreeAnimatorFromPresentable->g.fovScale,
      a3: hands_depthHack.valueFloat);
    idPresentable::UpdateSound(this: this->presentable);
    if ( v6 != nullptr )
    {
      if ( (*((_BYTE *)v6 + 452) & 2) != 0 && idHandsItem::GetLaserSightPosition(this, hands, origin: &v36, axis: &v44) )
      {
        owner = hands->owner;
        weaponState = idWeapon::CastTo(c: (idWeapon *)this->item)->weaponState;
        v15 = idWeapon::CastTo(c: (idWeapon *)this->item);
        LODWORD(v16) = idWeapon::MaxRange(this: v15, secondaryAmmo: (_cntlzw(weaponState - 1) & 0x20) != 0);
        *(_QWORD *)&v34.x = v16;
        v17 = (float)v16;
        idWeapon::ShowLaserSight(this: v6);
        idPresentablePlayer::GetViewTransform(this: owner, origin: &v35, axis: &v42);
        v18 = 0;
        x = owner->bobCycle.viewBob.x;
        y = owner->bobCycle.viewBob.y;
        v34.z = owner->bobCycle.viewBob.z;
        v34.x = x;
        v34.y = y;
        v35.x = (float)(v34.z * vec3_up.x) + v35.x;
        v35.z = v35.z + (float)(v34.z * vec3_up.z);
        v35.y = v35.y + (float)(v34.z * vec3_up.y);
        ActorEntity = (idPlayer *)idPresentableActor::GetActorEntity(this: owner);
        v22 = idPlayer::CastTo(c: ActorEntity);
        if ( v22 != nullptr
          && (v34.x = 0.0,
              FocusTracker = (idFocusTracker *)idPlayer::GetFocusTracker(this: v22),
              idFocusTracker::GetValidTraceResultFocusEntity(
                this: FocusTracker,
                includeBoundCheck: false,
                checkTypes: nullptr,
                numCheckTypes: 0,
                maxRanges: nullptr,
                resultEndPos: &v40,
                resultID: (int *)&v34) != nullptr) )
        {
          v24 = (float)((float)((float)(v40.z - v35.z) * (float)(v40.z - v35.z))
                      + (float)((float)((float)(v40.x - v35.x) * (float)(v40.x - v35.x))
                              + (float)((float)(v40.y - v35.y) * (float)(v40.y - v35.y))));
          if ( v24 <= 16384.0 )
            v25 = 128.0;
          else
            v25 = __fsqrts(v24);
          z = v36.z;
          v27 = v36.y;
          v28 = v36.x;
          v34.x = (float)((float)(v42.mat[0].x * (float)v25) + v35.x) - v36.x;
          v34.z = (float)(v35.z + (float)(v42.mat[0].z * (float)v25)) - v36.z;
          v34.y = (float)(v35.y + (float)(v42.mat[0].y * (float)v25)) - v36.y;
          idVec3::NormalizeFast(this: &v34);
          v18 = 1;
          v37[2] = (float)z + (float)(v34.z * (float)v17);
          v37[1] = (float)v27 + (float)(v34.y * (float)v17);
          v37[0] = (float)(v34.x * (float)v17) + (float)v28;
        }
        else
        {
          z = v36.z;
          v27 = v36.y;
          v28 = v36.x;
        }
        if ( v18 == 0 )
        {
          v37[2] = (float)z + (float)(v42.mat[0].z * (float)v17);
          v37[1] = (float)v27 + (float)(v42.mat[0].y * (float)v17);
          v37[0] = (float)(v42.mat[0].x * (float)v17) + (float)v28;
        }
        v29 = owner;
        entityNumber = owner->entityNumber;
        v31 = v6->__vftable;
        v32 = idPresentableActor::GetActorEntity(this: v29);
        v31->UpdateLaserSight(this: v6, a2: &v36, a3: (const idVec3 *)v37, a4: entityNumber, a5: v32);
        if ( g_debugLaserSight.valueInteger != 0 )
        {
          v33 = common->RW(this: common);
          v33->DebugLine(
            this: v33,
            a2: (const idVec4 *)&idColor::colorRed,
            a3: &v36,
            a4: (const idVec3 *)v37,
            a5: 0,
            a6: true);
        }
      }
      idHandsItem::GetMuzzlePosition(this, hands, origin: v43, axis: v45);
      idWeapon::UpdateRibbon(this: v6);
    }
    goto _M489341_1;
  }
  idLib::Warning(
    fmt: "Model '%s' has no tag info for prop '%s', tag '%s'.",
    TreeAnimatorFromPresentable->decl->name.str,
    handsModelMD6->name.str,
    v10);
  idPLogScope::~idPLogScope(this: &v38);
LABEL_24:
  RD_EventEnd();
}


// ========================================================================
// __unwind$489021_0
// EA  : 0x82E0F65C
// RVA : 0x00E0F65C
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void _unwind_489021_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 496 + 388));
}


// ========================================================================
// __unwind$489022_1
// EA  : 0x82E0F684
// RVA : 0x00E0F684
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void _unwind_489022_1()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 496 + 144));
}


// ========================================================================
// ?Update@idHandsItem@@QAAXPAVidHands@@_N@Z
// EA  : 0x82E0F6B8
// RVA : 0x00E0F6B8
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void __fastcall idHandsItem::Update(idHandsItem *this, idHands *hands, bool useAlternativeModel)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idPresentableAnimatedEntity *presentable; // r3
  idTreeAnimator *TreeAnimator; // r28
  const idDeclMD6 *handsModelMD6; // r27
  idWeapon *v11; // r3
  idAnimator_AnimWeb::idModelAnimState *list; // r9
  idMD6LeafPlay *tree; // r29
  unsigned int v14; // r22
  int GameMsPerFrame; // r21
  idParallelJobList *parallelJobList; // r20
  int PreviousPlayerGameTime; // r19
  int PlayerGameTime; // r3
  idAnimEventHandler *p_animEventHandler; // r30
  int v20; // r25
  const char *v21; // r23
  const char *v22; // r3
  int v23; // r3
  float *v24; // [sp+8h] [-F8h]
  float *v25; // [sp+Ch] [-F4h]
  float *v26; // [sp+10h] [-F0h]
  int v27; // [sp+14h] [-ECh]
  int v28; // [sp+18h] [-E8h]
  int v29; // [sp+1Ch] [-E4h]
  int v30; // [sp+20h] [-E0h]
  int v31; // [sp+24h] [-DCh]
  int v32; // [sp+28h] [-D8h]
  int v33; // [sp+2Ch] [-D4h]
  int v34; // [sp+30h] [-D0h]
  int v35; // [sp+34h] [-CCh]
  int v36; // [sp+38h] [-C8h]
  int v37; // [sp+3Ch] [-C4h]
  int v38; // [sp+40h] [-C0h]
  int v39; // [sp+44h] [-BCh]
  int v40; // [sp+48h] [-B8h]
  int v41; // [sp+4Ch] [-B4h]
  int v42; // [sp+50h] [-B0h]
  int v43; // [sp+58h] [-A8h]
  int v44; // [sp+60h] [-A0h]
  __int16 v45; // [sp+70h] [-90h] BYREF
  idPLogScope v46[17]; // [sp+78h] [-88h] BYREF

  RD_EventBegin(name: "idHandsItem::Update");
  LODWORD(v6) = "idHandsItem::Update";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: v46, pl: &pLog, gMask: v6, label: v7);
  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: presentable);
    if ( TreeAnimator != nullptr )
    {
      if ( !useAlternativeModel || (handsModelMD6 = this->itemDecl->handsModelMD6Alt) == nullptr )
        handsModelMD6 = this->itemDecl->handsModelMD6;
      idHandsItem::UpdatePosition(this, hands);
      v11 = idWeapon::CastTo(c: (idWeapon *)this->item);
      if ( v11 != nullptr )
        v11->UpdateWeaponFunctionality(this: v11, a2: hands->owner);
      if ( hands != (idHands *)-1592 )
      {
        idDeclAnimWeb::FindModelIndex(
          this: (idDeclAnimWeb *)&v45,
          result: (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)hands->web.decl,
          decl: handsModelMD6);
        if ( v45 >= 0 )
        {
          list = hands->web.modelAnimStates.list;
          tree = (idMD6LeafPlay *)list[v45].tree;
          if ( tree != nullptr && (unsigned __int8)idMD6Node::IsValid(this: list[v45].tree) != 0 )
          {
            v14 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
            GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                               this: &clientGame->gameTimeManager,
                               type: GAMETIME_SCALED);
            parallelJobList = gameLocal->parallelJobList;
            PreviousPlayerGameTime = idClientGame::GetPreviousPlayerGameTime(this: clientGame);
            PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
            idTreeAnimator::BlendTreeInternal(
              this: TreeAnimator,
              currentTime: PlayerGameTime,
              previousTime: PreviousPlayerGameTime,
              gameMsPerFrame: GameMsPerFrame,
              ticksPerSec: v14,
              tree,
              parallelJobList,
              localR: nullptr,
              localS: v24,
              localT: v25,
              localU: v26,
              a12: v27,
              a13: v28,
              a14: v29,
              a15: v30,
              a16: v31,
              a17: v32,
              a18: v33,
              a19: v34,
              a20: v35,
              a21: v36,
              a22: v37,
              a23: v38,
              a24: v39,
              a25: v40,
              a26: v41,
              a27: v42,
              a28: nullptr,
              a29: v43,
              a30: nullptr,
              a31: v44,
              a32: nullptr);
            p_animEventHandler = &this->animEventHandler;
            v20 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
            v21 = (const char *)idClientGame::GetPreviousPlayerGameTime(this: clientGame);
            v22 = (const char *)idClientGame::GetPlayerGameTime(this: clientGame);
            idAnimEventHandler::BuildAnimEventList(
              this: p_animEventHandler,
              decl: handsModelMD6,
              tree,
              curTime: v22,
              previousTime: v21,
              ticksPerSec: v20,
              onlyEvents: nullptr,
              onlyNumEvents: 0);
            idEventReceiver::ProcessAnimEvents(this: hands, handler: p_animEventHandler);
            v23 = idClientGame::GetPlayerGameTime(this: clientGame);
            idTreeAnimator::UpdateTime(this: TreeAnimator, time: v23);
          }
        }
      }
    }
  }
  idPLogScope::~idPLogScope(this: v46);
  RD_EventEnd();
}


// ========================================================================
// __unwind$489364_0
// EA  : 0x82E0F8E4
// RVA : 0x00E0F8E4
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void _unwind_489364_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$489365
// EA  : 0x82E0F90C
// RVA : 0x00E0F90C
// PDB : w:\tech5\tungsten\game\player\handsitem.cpp
// ========================================================================

void _unwind_489365()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 120));
}

