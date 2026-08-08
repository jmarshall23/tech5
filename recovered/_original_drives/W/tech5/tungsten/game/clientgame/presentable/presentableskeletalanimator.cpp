
// ========================================================================
// ?Hide@idPresentableAnimatedEntity@@UAAX_N@Z
// EA  : 0x82B8E668
// RVA : 0x00B8E668
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall idPresentableAnimatedEntity::Hide(
        idPresentableAnimatedEntity *this,
        bool stopFx,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idClipModel *sphereModel; // r3

  idPresentable::Hide(this, stopFx, a3, a4, a5, a6, a7, a8);
  sphereModel = this->sphereModel;
  if ( sphereModel != nullptr && this->useSphereModel )
    idClipModel::Unlink(this: sphereModel);
}


// ========================================================================
// ?GetTreeAnimator@idPresentableAnimatedEntity@@QBAPBVidTreeAnimator@@XZ
// EA  : 0x82B8E6B0
// RVA : 0x00B8E6B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

idTreeAnimator *__fastcall idPresentableAnimatedEntity::GetTreeAnimator(idPresentableAnimatedEntity *this)
{
  return this->cachedAnimator;
}


// ========================================================================
// ??0idPresentableAnimatedEntity@@QAA@PAVidAnimatedEntity@@PAVidRenderModel@@PAVidAnimStack@@HPBVidDeclFX@@_N@Z
// EA  : 0x82B8E6C0
// RVA : 0x00B8E6C0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

idPresentableAnimatedEntity *__fastcall idPresentableAnimatedEntity::idPresentableAnimatedEntity(
        idPresentableAnimatedEntity *this,
        idAnimatedEntity *ent,
        idTreeAnimator *renderModel_,
        idAnimStack *animStack_,
        int entityNumber_,
        const idDeclFX *fxDecl_,
        bool useSphereModel_)
{
  idTreeAnimator *v13; // r3
  BOOL useSphereModel; // r10
  idClipModel *v15; // r3
  idClipModel *v16; // r3
  int entityNumber; // r11

  idPresentable::idPresentable(this, e: ent, renderModel_, entityNumber_, fxDecl_);
  this->animStack = animStack_;
  this->useSphereModel = useSphereModel_;
  this->sphereModel = nullptr;
  this->__vftable = (idPresentableAnimatedEntity_vtbl *)&idPresentableAnimatedEntity::`vftable';
  this->sphereModelContents = 0;
  this->createdAnimStack = false;
  this->serializedEyePos = vec3_origin;
  this->isAimAssistable = true;
  this->serializedAimAssist = false;
  this->serializedTotalCurHealth = 0.0;
  this->wasAddedToAimAssistList = false;
  this->serializedTotalMaxHealth = 0.0;
  v13 = (idTreeAnimator *)_RTDynamicCast(
                            inptr: renderModel_,
                            VfDelta: 0,
                            SrcType: &idRenderModel `RTTI Type Descriptor',
                            TargetType: &idTreeAnimator `RTTI Type Descriptor',
                            isReference: 0);
  useSphereModel = this->useSphereModel;
  this->cachedAnimator = v13;
  if ( useSphereModel && ent->clipModelInfo.type == CLIPMODEL_NONE )
    this->useSphereModel = false;
  if ( entityNumber_ != 0x1FFF && v13 != nullptr && this->useSphereModel )
  {
    v15 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v15 != nullptr )
      v16 = idClipModel::idClipModel(this: v15, clip: &clientGame->clip, animatedModel: this->cachedAnimator);
    else
      v16 = nullptr;
    entityNumber = this->entityNumber;
    this->sphereModel = v16;
    v16->entityNumber = entityNumber;
  }
  return this;
}


// ========================================================================
// __unwind$488379
// EA  : 0x82B8E838
// RVA : 0x00B8E838
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void _unwind_488379()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$488380
// EA  : 0x82B8E860
// RVA : 0x00B8E860
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void _unwind_488380()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?Present@idPresentableAnimatedEntity@@UAAXXZ
// EA  : 0x82B8E890
// RVA : 0x00B8E890
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall idPresentableAnimatedEntity::Present(idPresentableAnimatedEntity *this)
{
  idClipModel *sphereModel; // r3
  idTreeAnimator *cachedAnimator; // r11
  const idMat3 *p_deferredAxis; // r8
  const idVec3 *p_deferredOrigin; // r7

  idPresentable::Present(this);
  sphereModel = this->sphereModel;
  if ( sphereModel != nullptr )
  {
    if ( this->hidden )
    {
      idClipModel::Unlink(this: sphereModel);
    }
    else
    {
      cachedAnimator = this->cachedAnimator;
      p_deferredAxis = &cachedAnimator->deferredAxis;
      if ( !cachedAnimator->useDeferredPosition )
        p_deferredAxis = &cachedAnimator->g.axis;
      p_deferredOrigin = &cachedAnimator->deferredOrigin;
      if ( !cachedAnimator->useDeferredPosition )
        p_deferredOrigin = &cachedAnimator->g.origin;
      idClipModel::Link(
        this: this->sphereModel,
        newEntityNumber: this->sphereModel->entityNumber,
        newPhysicsId: -1,
        newBodyId: 0,
        newOrigin: p_deferredOrigin,
        newAxis: p_deferredAxis,
        newBounds: &cachedAnimator->referenceBounds);
    }
  }
}


// ========================================================================
// ?UpdateClientCollision@idPresentableAnimatedEntity@@UAAXABVidVec3@@ABVidMat3@@01@Z
// EA  : 0x82B8E930
// RVA : 0x00B8E930
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall idPresentableAnimatedEntity::UpdateClientCollision(
        idPresentableAnimatedEntity *this,
        const idVec3 *oldOrigin,
        const idMat3 *oldAxis,
        const idVec3 *newOrigin,
        const idMat3 *newAxis)
{
  idPresentable::UpdateClientCollision(this, oldOrigin, oldAxis, newOrigin, newAxis);
  if ( this->sphereModel != nullptr && this->useSphereModel )
    this->sphereModel->enabled = this->ShouldEnableSphereCollision(this);
}


// ========================================================================
// ?Show@idPresentableAnimatedEntity@@UAAXXZ
// EA  : 0x82B8E9A8
// RVA : 0x00B8E9A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall idPresentableAnimatedEntity::Show(idPresentableAnimatedEntity *this)
{
  idClipModel *sphereModel; // r3
  idTreeAnimator *cachedAnimator; // r11
  const idMat3 *p_deferredAxis; // r8
  const idVec3 *p_deferredOrigin; // r7

  idPresentable::Show(this);
  sphereModel = this->sphereModel;
  if ( sphereModel != nullptr && this->useSphereModel )
  {
    cachedAnimator = this->cachedAnimator;
    p_deferredAxis = &cachedAnimator->deferredAxis;
    if ( !cachedAnimator->useDeferredPosition )
      p_deferredAxis = &cachedAnimator->g.axis;
    p_deferredOrigin = &cachedAnimator->deferredOrigin;
    if ( !cachedAnimator->useDeferredPosition )
      p_deferredOrigin = &cachedAnimator->g.origin;
    idClipModel::Link(
      this: sphereModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: -1,
      newBodyId: 0,
      newOrigin: p_deferredOrigin,
      newAxis: p_deferredAxis);
  }
}


// ========================================================================
// ?ClientJobSync@idPresentableAnimatedEntity@@UAAXXZ
// EA  : 0x82B8EA28
// RVA : 0x00B8EA28
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall idPresentableAnimatedEntity::ClientJobSync(idPresentableAnimatedEntity *this)
{
  idTreeAnimator *cachedAnimator; // r31
  int ServerGameTime; // r3

  cachedAnimator = this->cachedAnimator;
  idPresentable::UpdateModelTransform(this);
  if ( cachedAnimator != nullptr )
  {
    ServerGameTime = idClientGame::GetServerGameTime(this: clientGame);
    idTreeAnimator::SyncJoints(this: cachedAnimator, time: ServerGameTime);
  }
}


// ========================================================================
// ?SetRenderModel@idPresentableAnimatedEntity@@UAAXPAVidRenderModel@@_N@Z
// EA  : 0x82B8EA80
// RVA : 0x00B8EA80
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall idPresentableAnimatedEntity::SetRenderModel(
        idPresentableAnimatedEntity *this,
        idTreeAnimator *renderModel_,
        bool inheritTransform)
{
  idClipModel *sphereModel; // r3
  idTreeAnimator *cachedAnimator; // r11
  idClipModel *v7; // r3
  idClipModel *v8; // r3
  int entityNumber; // r11
  idPresentable *Parent; // r3
  idTreeAnimator *v11; // r11

  idPresentable::SetRenderModel(this, renderModel_, inheritTransform);
  this->cachedAnimator = (idTreeAnimator *)_RTDynamicCast(
                                             inptr: renderModel_,
                                             VfDelta: 0,
                                             SrcType: &idRenderModel `RTTI Type Descriptor',
                                             TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                             isReference: 0);
  sphereModel = this->sphereModel;
  if ( sphereModel != nullptr )
  {
    idClipModel::Delete(this: sphereModel);
    cachedAnimator = this->cachedAnimator;
    this->sphereModel = nullptr;
    if ( cachedAnimator != nullptr )
    {
      v7 = (idClipModel *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0xD8u,
                            tag: TAG_CLIPMODEL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
      if ( v7 != nullptr )
        v8 = idClipModel::idClipModel(this: v7, clip: &clientGame->clip, animatedModel: this->cachedAnimator);
      else
        v8 = nullptr;
      entityNumber = this->entityNumber;
      this->sphereModel = v8;
      v8->entityNumber = entityNumber;
    }
  }
  if ( common->IsClient(this: common) && this->cachedAnimator != nullptr )
  {
    Parent = idPresentable::GetParent(this);
    v11 = this->cachedAnimator;
    v11->useDeferredPosition = Parent == nullptr;
  }
}


// ========================================================================
// __unwind$488535
// EA  : 0x82B8EB9C
// RVA : 0x00B8EB9C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void _unwind_488535()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?GetPresentableTagPosition@idPresentableAnimatedEntity@@QBA_NPBD0AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82B8EBC8
// RVA : 0x00B8EBC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

int __fastcall idPresentableAnimatedEntity::GetPresentableTagPosition(
        idPresentableAnimatedEntity *this,
        const char *propName,
        const char *tagName,
        idVec3 *origin,
        idMat3 *axis)
{
  idTreeAnimator *cachedAnimator; // r28
  float *model; // r11
  int result; // r3
  double v13; // fp8
  double v14; // fp6
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r3
  const tagData_t *Tag; // r3

  cachedAnimator = this->cachedAnimator;
  idPresentable::UpdateModelTransform(this);
  if ( cachedAnimator != nullptr )
  {
    decl = cachedAnimator->decl;
    p_props = &decl->props;
    if ( decl == nullptr )
      p_props = nullptr;
    Tag = idPropsCollection::GetTag(this: p_props, propName, tagName);
    return idTreeAnimator::GetWorldSpaceTagTransform(this: cachedAnimator, tagData: Tag, origin, axis);
  }
  else
  {
    model = (float *)this->model;
    result = 0;
    if ( model != nullptr )
    {
      v13 = (float)(model[27] + model[24]);
      v14 = (float)(model[28] + model[25]);
      origin->x = (float)(model[26] + model[23]) * (float)0.5;
      origin->y = (float)v13 * (float)0.5;
      origin->z = (float)v14 * (float)0.5;
      axis->mat[0].x = this->axis.mat[0].x;
      axis->mat[0].y = this->axis.mat[0].y;
      axis->mat[0].z = this->axis.mat[0].z;
      axis->mat[1].x = this->axis.mat[1].x;
      axis->mat[1].y = this->axis.mat[1].y;
      axis->mat[1].z = this->axis.mat[1].z;
      axis->mat[2].x = this->axis.mat[2].x;
      axis->mat[2].y = this->axis.mat[2].y;
      axis->mat[2].z = this->axis.mat[2].z;
    }
    else
    {
      *origin = vec3_origin;
      *axis = mat3_identity;
    }
  }
  return result;
}


// ========================================================================
// ?GetPresentableTagPosition@idPresentableAnimatedEntity@@QBA_NHHAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82B8ED58
// RVA : 0x00B8ED58
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

int __fastcall idPresentableAnimatedEntity::GetPresentableTagPosition(
        idPresentableAnimatedEntity *this,
        int propIndex,
        int tagIndex,
        idVec3 *origin,
        idMat3 *axis)
{
  idTreeAnimator *cachedAnimator; // r28
  float *model; // r11
  int result; // r3
  double v13; // fp8
  double v14; // fp6
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r3
  const tagData_t *TagByIndices; // r3

  cachedAnimator = this->cachedAnimator;
  idPresentable::UpdateModelTransform(this);
  if ( cachedAnimator != nullptr )
  {
    decl = cachedAnimator->decl;
    p_props = &decl->props;
    if ( decl == nullptr )
      p_props = nullptr;
    TagByIndices = idPropsCollection::GetTagByIndices(this: p_props, propIndex, tagIndex);
    return idTreeAnimator::GetWorldSpaceTagTransform(this: cachedAnimator, tagData: TagByIndices, origin, axis);
  }
  else
  {
    model = (float *)this->model;
    result = 0;
    if ( model != nullptr )
    {
      v13 = (float)(model[27] + model[24]);
      v14 = (float)(model[28] + model[25]);
      origin->x = (float)(model[26] + model[23]) * (float)0.5;
      origin->y = (float)v13 * (float)0.5;
      origin->z = (float)v14 * (float)0.5;
      axis->mat[0].x = this->axis.mat[0].x;
      axis->mat[0].y = this->axis.mat[0].y;
      axis->mat[0].z = this->axis.mat[0].z;
      axis->mat[1].x = this->axis.mat[1].x;
      axis->mat[1].y = this->axis.mat[1].y;
      axis->mat[1].z = this->axis.mat[1].z;
      axis->mat[2].x = this->axis.mat[2].x;
      axis->mat[2].y = this->axis.mat[2].y;
      axis->mat[2].z = this->axis.mat[2].z;
    }
    else
    {
      *origin = vec3_origin;
      *axis = mat3_identity;
    }
  }
  return result;
}


// ========================================================================
// ?GetInventory@idPresentableAnimatedEntity@@UBAPBVidInventoryCollection@@XZ
// EA  : 0x82B8EEE8
// RVA : 0x00B8EEE8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

const idInventoryCollection *__fastcall idPresentableAnimatedEntity::GetInventory(idPresentableAnimatedEntity *this)
{
  idEntity *entity; // r31

  entity = this->entity;
  if ( entity != nullptr && common->IsServer(this: common) )
    return entity->GetInventory(this: entity);
  else
    return nullptr;
}


// ========================================================================
// ?GetInventory@idPresentableAnimatedEntity@@UAAPAVidInventoryCollection@@XZ
// EA  : 0x82B8EF68
// RVA : 0x00B8EF68
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

idInventoryCollection *__fastcall idPresentableAnimatedEntity::GetInventory(idPresentableAnimatedEntity *this)
{
  idEntity *entity; // r31

  entity = this->entity;
  if ( entity != nullptr && common->IsServer(this: common) )
    return entity->GetInventory_2(this: entity);
  else
    return nullptr;
}


// ========================================================================
// ?InventoryAdded@idPresentableAnimatedEntity@@UAAXPAVidInventoryItem@@H_N@Z
// EA  : 0x82B8EFE8
// RVA : 0x00B8EFE8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall idPresentableAnimatedEntity::InventoryAdded(
        idPresentableAnimatedEntity *this,
        idInventoryItem *item,
        int count,
        bool canIntro)
{
  idEntity *entity; // r3

  entity = this->entity;
  if ( entity != nullptr )
    ((void (__fastcall *)(idEntity *, idInventoryItem *, int, bool))entity->InventoryAdded)(
      a1: entity,
      a2: item,
      a3: count,
      a4: canIntro);
}


// ========================================================================
// ?GetEyePos@idPresentableAnimatedEntity@@QBAXAAVidVec3@@@Z
// EA  : 0x82B8F008
// RVA : 0x00B8F008
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall idPresentableAnimatedEntity::GetEyePos(idPresentableAnimatedEntity *this, idVec3 *eyePos)
{
  if ( this->entity != nullptr && common->IsServer(this: common) )
  {
    this->entity->GetEyePos(this: this->entity, a2: eyePos);
  }
  else
  {
    eyePos->x = this->serializedEyePos.x;
    eyePos->y = this->serializedEyePos.y;
    eyePos->z = this->serializedEyePos.z;
  }
}


// ========================================================================
// ?GetTotalCurHealth@idPresentableAnimatedEntity@@UBAMXZ
// EA  : 0x82B8F0A0
// RVA : 0x00B8F0A0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

float __fastcall idPresentableAnimatedEntity::GetTotalCurHealth(idPresentableAnimatedEntity *this)
{
  idBaseHealth *v2; // r3
  double serializedTotalCurHealth; // fp1

  if ( this->entity != nullptr && common->IsServer(this: common) )
  {
    v2 = this->entity->GetHealthComponent_2(this: this->entity);
    if ( v2 != nullptr )
      serializedTotalCurHealth = v2->GetTotalCurHealth_Impl(this: v2);
    else
      serializedTotalCurHealth = 0.0;
  }
  else
  {
    serializedTotalCurHealth = this->serializedTotalCurHealth;
  }
  return *((float *)&serializedTotalCurHealth + 1);
}


// ========================================================================
// ?GetTotalMaxHealth@idPresentableAnimatedEntity@@UBAMXZ
// EA  : 0x82B8F158
// RVA : 0x00B8F158
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

float __fastcall idPresentableAnimatedEntity::GetTotalMaxHealth(idPresentableAnimatedEntity *this)
{
  idBaseHealth *v2; // r3
  double serializedTotalMaxHealth; // fp1

  if ( this->entity != nullptr && common->IsServer(this: common) )
  {
    v2 = this->entity->GetHealthComponent_2(this: this->entity);
    if ( v2 != nullptr )
      serializedTotalMaxHealth = v2->GetTotalMaxHealth_Impl(this: v2);
    else
      serializedTotalMaxHealth = 0.0;
  }
  else
  {
    serializedTotalMaxHealth = this->serializedTotalMaxHealth;
  }
  return *((float *)&serializedTotalMaxHealth + 1);
}


// ========================================================================
// ?GetCanAimAssist@idPresentableAnimatedEntity@@QAA_NXZ
// EA  : 0x82B8F210
// RVA : 0x00B8F210
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

BOOL __fastcall idPresentableAnimatedEntity::GetCanAimAssist(idPresentableAnimatedEntity *this)
{
  idEntity *entity; // r3
  idEntity *v4; // r3
  idFaction *v5; // r30
  idPresentablePlayer *LocalPresentablePlayer; // r3

  if ( this->entity == nullptr || !common->IsServer(this: common) )
    return this->serializedAimAssist;
  if ( this->entity->TakesDamage(this: this->entity) )
  {
    entity = this->entity;
    if ( entity == nullptr || !entity->IsDead(this: entity) )
    {
      v4 = this->entity;
      if ( (v4->thinkFlags & 1) != 0 && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v4) == 0 )
      {
        v5 = this->entity->GetFaction(this: this->entity);
        if ( v5 != nullptr && idClientGame::GetLocalPresentablePlayer(this: clientGame) != nullptr )
        {
          LocalPresentablePlayer = idClientGame::GetLocalPresentablePlayer(this: clientGame);
          if ( idFaction::GetAttitudeTowards(this: v5, otherEnt: LocalPresentablePlayer->entity) < ATTITUDE_NEUTRAL )
            return true;
        }
      }
    }
  }
  return false;
}


// ========================================================================
// ?IsTargetLockable@idPresentableAnimatedEntity@@UBA_NPBVidDeclAmmo@@@Z
// EA  : 0x82B8F348
// RVA : 0x00B8F348
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

BOOL __fastcall idPresentableAnimatedEntity::IsTargetLockable(
        idPresentableAnimatedEntity *this,
        const idDeclAmmo *ammo)
{
  idEntity *entity; // r11

  entity = this->entity;
  if ( entity != nullptr )
    return entity->IsTargetLockable(this: this->entity, a2: ammo);
  else
    return ((double (__fastcall *)(idPresentableAnimatedEntity *, const idDeclAmmo *))this->GetTotalCurHealth)(
             a1: this,
             a2: ammo) > 0.0;
}


// ========================================================================
// ??1idPresentableAnimatedEntity@@UAA@XZ
// EA  : 0x82B8F3C8
// RVA : 0x00B8F3C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall idPresentableAnimatedEntity::~idPresentableAnimatedEntity(idPresentableAnimatedEntity *this)
{
  idClipModel *sphereModel; // r3
  idAnimStack *animStack; // r3
  idAnimStack *v4; // r3
  idPresentableAnimatedEntity *v5; // [sp+50h] [-30h] BYREF

  this->__vftable = (idPresentableAnimatedEntity_vtbl *)&idPresentableAnimatedEntity::`vftable';
  sphereModel = this->sphereModel;
  if ( sphereModel != nullptr )
    idClipModel::Delete(this: sphereModel);
  if ( this->wasAddedToAimAssistList )
  {
    v5 = this;
    idList<idPresentableAnimatedEntity *,5>::Remove(
      this: (idList<lobbyUser_t *,5> *)&clientGame->aimAssistTargets,
      obj: (lobbyUser_t *const *)&v5);
    this->wasAddedToAimAssistList = false;
  }
  if ( this->createdAnimStack )
  {
    animStack = this->animStack;
    if ( animStack != nullptr )
    {
      idAnimStack::FreeSerializedAnimators(this: animStack);
      v4 = this->animStack;
      if ( v4 != nullptr )
        ((void (__fastcall *)(idAnimStack *, int))v4->dtr_idAnimStack)(a1: v4, a2: 1);
      this->animStack = nullptr;
    }
  }
  idPresentable::~idPresentable(this);
}


// ========================================================================
// __unwind$489253_0
// EA  : 0x82B8F47C
// RVA : 0x00B8F47C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void _unwind_489253_0()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 128 + 148));
}


// ========================================================================
// ?Serialize@idPresentableAnimatedEntity@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B8F4B0
// RVA : 0x00B8F4B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall idPresentableAnimatedEntity::Serialize(idPresentableAnimatedEntity *this, idSerializer *ser)
{
  idTreeAnimator *v4; // r3
  idTreeAnimator *v5; // r26
  unsigned __int8 v6; // r11
  bool v7; // r27
  idBitMsg *msg; // r3
  bool useSphereModel; // r29
  idBitMsg *v10; // r3
  idBitMsg *v11; // r3
  idBitMsg *v12; // r3
  idClipModel *sphereModel; // r11
  idBitMsg *v14; // r3
  idAnimStack *animStack; // r11
  idAnimStack *v16; // r3
  idAnimStack *v17; // r3
  idAnimStack *v18; // r3
  BOOL initialized; // r10
  idGameTimeManager *p_gameTimeManager; // r27
  int GameMs; // r3
  idAnimStack *v22; // r3
  idTreeAnimator *treeAnimator; // [sp+50h] [-50h]

  idPresentable::Serialize(this, ser);
  v4 = (idTreeAnimator *)_RTDynamicCast(
                           inptr: this->model,
                           VfDelta: 0,
                           SrcType: &idRenderModel `RTTI Type Descriptor',
                           TargetType: &idTreeAnimator `RTTI Type Descriptor',
                           isReference: 0);
  v5 = v4;
  if ( this->animStack == nullptr || (v6 = 1, v4 == nullptr) )
    v6 = 0;
  v7 = v6;
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: v6, numBits: 1);
  else
    v7 = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  useSphereModel = this->useSphereModel;
  v10 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v10, value: this->useSphereModel, numBits: 1);
  else
    useSphereModel = (_cntlzw(idBitMsg::ReadBits(this: v10, numBits: 1) - 1) & 0x20) != 0;
  this->useSphereModel = useSphereModel;
  this->serializedTotalMaxHealth = this->GetTotalMaxHealth(this);
  this->serializedTotalCurHealth = this->GetTotalCurHealth(this);
  v11 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v11, value: COERCE_INT(this->serializedTotalMaxHealth), numBits: 32);
  else
    LODWORD(this->serializedTotalMaxHealth) = idBitMsg::ReadBits(this: v11, numBits: 32);
  v12 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v12, value: COERCE_INT(this->serializedTotalCurHealth), numBits: 32);
  else
    LODWORD(this->serializedTotalCurHealth) = idBitMsg::ReadBits(this: v12, numBits: 32);
  sphereModel = this->sphereModel;
  if ( sphereModel != nullptr )
    this->sphereModelContents = sphereModel->contents;
  v14 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v14, value: this->sphereModelContents, numBits: 32);
  else
    this->sphereModelContents = idBitMsg::ReadBits(this: v14, numBits: 32);
  if ( v7 )
  {
    if ( this->animStack != nullptr && !this->createdAnimStack && common->IsClient(this: common) )
      this->animStack = nullptr;
    animStack = this->animStack;
    if ( animStack != nullptr )
    {
      treeAnimator = animStack->treeAnimator;
      if ( treeAnimator != v5 )
      {
        idLib::Printf(
          fmt: "idPresentableAnimatedEntity::Serialize - Changing tree animators: %p/%p\n",
          treeAnimator,
          v5);
        if ( this->createdAnimStack )
        {
          v16 = this->animStack;
          if ( v16 != nullptr )
            ((void (__fastcall *)(idAnimStack *, int))v16->dtr_idAnimStack)(a1: v16, a2: 1);
        }
        this->animStack = nullptr;
      }
    }
    if ( this->animStack == nullptr )
    {
      v17 = (idAnimStack *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0x624u,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      if ( v17 != nullptr )
        v18 = idAnimStack::idAnimStack(this: v17);
      else
        v18 = nullptr;
      this->animStack = v18;
      idAnimStack::Init(this: v18, treeAnimator: v5);
      initialized = this->fxManager.initialized;
      this->createdAnimStack = true;
      if ( initialized )
        idFXManager::ResetTreeAnimator(this: &this->fxManager, _ta: v5);
    }
    p_gameTimeManager = &clientGame->gameTimeManager;
    GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    idAnimStack::SerializeSnapshot(
      this: this->animStack,
      ser,
      clip: &clientGame->clip,
      curTime: GameMs,
      game: p_gameTimeManager);
  }
  else
  {
    v22 = this->animStack;
    if ( v22 != nullptr )
    {
      if ( !ser->writing )
        ((void (__fastcall *)(idAnimStack *, int))v22->dtr_idAnimStack)(a1: v22, a2: 1);
      this->animStack = nullptr;
    }
  }
  this->cachedAnimator = v5;
}


// ========================================================================
// __unwind$489285
// EA  : 0x82B8F804
// RVA : 0x00B8F804
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall _unwind_489285(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// ?UpdateAnimation@idPresentableAnimatedEntity@@QAAXHM@Z
// EA  : 0x82B8F890
// RVA : 0x00B8F890
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall idPresentableAnimatedEntity::UpdateAnimation(
        idPresentableAnimatedEntity *this,
        int curTime,
        double fraction)
{
  idGameTimeManager *p_gameTimeManager; // r29
  int v6; // r28
  int GameMsPerFrame; // r30
  idAnimStack *animStack; // r31
  idParallelJobList *parallelJobList; // r27
  int ServerGameTime; // r3
  idGameTimeManager *v11; // r7

  if ( this->animStack != nullptr && !this->hidden )
  {
    p_gameTimeManager = &clientGame->gameTimeManager;
    v6 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: p_gameTimeManager, type: GAMETIME_SCALED);
    animStack = this->animStack;
    parallelJobList = gameLocal->parallelJobList;
    ServerGameTime = idClientGame::GetServerGameTime(this: clientGame);
    idAnimStack::BlendSnapshot(
      this: animStack,
      curTime: ServerGameTime,
      gameMsPerFrame: GameMsPerFrame,
      ticksPerSec: v6,
      fraction,
      game: v11,
      parallelJobList: p_gameTimeManager,
      a8: parallelJobList);
  }
}


// ========================================================================
// ?ClientThink@idPresentableAnimatedEntity@@UAAXHM_N@Z
// EA  : 0x82B8F948
// RVA : 0x00B8F948
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall idPresentableAnimatedEntity::ClientThink(
        idPresentableAnimatedEntity *this,
        int curTime,
        double fraction,
        bool predict,
        char a5)
{
  if ( this->index < 0x2000 )
  {
    ((void (__fastcall *)(idPresentableAnimatedEntity *))this->Interpolate)(a1: this);
    if ( a5 == 1 )
      this->ClientPredict(this, a2: curTime, a3: fraction);
    idPresentableAnimatedEntity::UpdateAnimation(this, curTime, fraction);
    this->UpdateFX_3(this, a2: 1.0, a3: 0.0);
    idPresentable::UpdateSound(this);
    this->Present(this);
  }
}


// ========================================================================
// ?PostSerializeRead@idPresentableAnimatedEntity@@UAAX_N@Z
// EA  : 0x82B8FA10
// RVA : 0x00B8FA10
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall idPresentableAnimatedEntity::PostSerializeRead(
        idPresentableAnimatedEntity *this,
        bool firstClientFrame)
{
  lobbyUser_t *v3; // r3
  idClipModel *v4; // r3
  idTreeAnimator *cachedAnimator; // r11
  const idMat3 *p_deferredAxis; // r8
  const idVec3 *p_deferredOrigin; // r7
  idClipModel *sphereModel; // r3
  idClipModel *v9; // r3
  lobbyUser_t *v10[12]; // [sp+50h] [-30h] BYREF

  idPresentable::PostSerializeRead(this, firstClientFrame);
  if ( this->entityNumber != 0x1FFF && this->cachedAnimator != nullptr && this->useSphereModel )
  {
    if ( this->sphereModel == nullptr )
    {
      v3 = (lobbyUser_t *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0xD8u,
                            tag: TAG_CLIPMODEL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
      v10[0] = v3;
      if ( v3 != nullptr )
        v4 = idClipModel::idClipModel(
               this: (idClipModel *)v3,
               clip: &clientGame->clip,
               animatedModel: this->cachedAnimator);
      else
        v4 = nullptr;
      this->sphereModel = v4;
    }
    cachedAnimator = this->cachedAnimator;
    p_deferredAxis = &cachedAnimator->deferredAxis;
    if ( !cachedAnimator->useDeferredPosition )
      p_deferredAxis = &cachedAnimator->g.axis;
    p_deferredOrigin = &cachedAnimator->deferredOrigin;
    if ( !cachedAnimator->useDeferredPosition )
      p_deferredOrigin = &cachedAnimator->g.origin;
    idClipModel::Link(
      this: this->sphereModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: -1,
      newBodyId: 0,
      newOrigin: p_deferredOrigin,
      newAxis: p_deferredAxis);
  }
  else
  {
    sphereModel = this->sphereModel;
    if ( sphereModel != nullptr )
    {
      idClipModel::Delete(this: sphereModel);
      this->sphereModel = nullptr;
    }
  }
  v9 = this->sphereModel;
  if ( v9 != nullptr )
    idClipModel::SetContents(this: v9, newContents: this->sphereModelContents);
  if ( this->wasAddedToAimAssistList )
    goto LABEL_22;
  if ( this->serializedAimAssist )
  {
    v10[0] = (lobbyUser_t *)this;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&clientGame->aimAssistTargets,
      obj: (encounterGroupRole_t *)v10);
    this->wasAddedToAimAssistList = true;
    return;
  }
  if ( this->wasAddedToAimAssistList )
  {
LABEL_22:
    if ( !this->serializedAimAssist )
    {
      v10[0] = (lobbyUser_t *)this;
      idList<idPresentableAnimatedEntity *,5>::Remove(
        this: (idList<lobbyUser_t *,5> *)&clientGame->aimAssistTargets,
        obj: v10);
      this->wasAddedToAimAssistList = false;
    }
  }
}


// ========================================================================
// __unwind$489836_0
// EA  : 0x82B8FB90
// RVA : 0x00B8FB90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void _unwind_489836_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?UpdateAimAssist@idPresentableAnimatedEntity@@QAAXXZ
// EA  : 0x82B8FBC0
// RVA : 0x00B8FBC0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableskeletalanimator.cpp
// ========================================================================

void __fastcall idPresentableAnimatedEntity::UpdateAimAssist(idPresentableAnimatedEntity *this)
{
  bool CanAimAssist; // r3
  BOOL wasAddedToAimAssistList; // r11
  bool v4; // r10
  lobbyUser_t *v5[4]; // [sp+50h] [-20h] BYREF

  CanAimAssist = idPresentableAnimatedEntity::GetCanAimAssist(this);
  wasAddedToAimAssistList = this->wasAddedToAimAssistList;
  this->serializedAimAssist = CanAimAssist;
  if ( wasAddedToAimAssistList )
  {
    if ( CanAimAssist )
      return;
    v5[0] = (lobbyUser_t *)this;
    idList<idPresentableAnimatedEntity *,5>::Remove(
      this: (idList<lobbyUser_t *,5> *)&clientGame->aimAssistTargets,
      obj: v5);
    v4 = false;
    goto LABEL_7;
  }
  if ( CanAimAssist )
  {
    v5[0] = (lobbyUser_t *)this;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&clientGame->aimAssistTargets,
      obj: (encounterGroupRole_t *)v5);
    v4 = true;
LABEL_7:
    this->wasAddedToAimAssistList = v4;
  }
}

