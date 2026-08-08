
// ========================================================================
// ?Hide@idActor@@UAAXXZ
// EA  : 0x82BE2558
// RVA : 0x00BE2558
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::Hide(idActor *this)
{
  idLight *NextTeamEntity; // r31
  idEntity *v3; // r30
  idLight *v4; // r3

  idEntity::Hide(this);
  NextTeamEntity = (idLight *)idEntity::GetNextTeamEntity(this);
  if ( NextTeamEntity != nullptr )
  {
    do
    {
      v3 = idEntity::GetNextTeamEntity(this: NextTeamEntity);
      if ( idEntity::GetBindMaster(this: NextTeamEntity) == this )
      {
        NextTeamEntity->Hide_2(this: NextTeamEntity);
        if ( (unsigned __int8)idLight::IsTypeOf(c: NextTeamEntity) != 0 )
        {
          v4 = idLight::CastTo(c: NextTeamEntity);
          idLight::Off(this: v4);
        }
      }
      NextTeamEntity = (idLight *)v3;
    }
    while ( v3 != nullptr );
  }
  idAttachmentCollection::HideAttachments(this: &this->attachments);
}


// ========================================================================
// ?Show@idActor@@UAAXXZ
// EA  : 0x82BE25F0
// RVA : 0x00BE25F0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::Show(idActor *this)
{
  idLight *NextTeamEntity; // r31
  idEntity *v3; // r30
  idLight *v4; // r3

  idEntity::Show(this);
  NextTeamEntity = (idLight *)idEntity::GetNextTeamEntity(this);
  if ( NextTeamEntity != nullptr )
  {
    do
    {
      v3 = idEntity::GetNextTeamEntity(this: NextTeamEntity);
      if ( idEntity::GetBindMaster(this: NextTeamEntity) == this )
      {
        NextTeamEntity->Show(this: NextTeamEntity);
        if ( (unsigned __int8)idLight::IsTypeOf(c: NextTeamEntity) != 0 )
        {
          v4 = idLight::CastTo(c: NextTeamEntity);
          idLight::On(this: v4);
        }
      }
      NextTeamEntity = (idLight *)v3;
    }
    while ( v3 != nullptr );
  }
  idAttachmentCollection::ShowAttachments(this: &this->attachments, hideVehicleAttachments: false);
}


// ========================================================================
// ?ProjectOverlay@idActor@@UAAXABVidVec3@@0MPBD@Z
// EA  : 0x82BE2688
// RVA : 0x00BE2688
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::ProjectOverlay(
        idActor *this,
        const idVec3 *origin,
        const idVec3 *dir,
        double size,
        const char *material)
{
  idEntity *NextTeamEntity; // r31
  idEntity *v10; // r26

  idEntity::ProjectOverlay(this, origin, dir, size, material);
  NextTeamEntity = idEntity::GetNextTeamEntity(this);
  if ( NextTeamEntity != nullptr )
  {
    do
    {
      v10 = idEntity::GetNextTeamEntity(this: NextTeamEntity);
      if ( idEntity::GetBindMaster(this: NextTeamEntity) == this && NextTeamEntity->TakesDamage(this: NextTeamEntity) )
        ((void (__fastcall *)(idEntity *, const idVec3 *, const idVec3 *, double))NextTeamEntity->ProjectOverlay)(
          a1: NextTeamEntity,
          a2: origin,
          a3: dir,
          a4: size);
      NextTeamEntity = v10;
    }
    while ( v10 != nullptr );
  }
}


// ========================================================================
// ?UpdateAttachments@idActor@@UAAXXZ
// EA  : 0x82BE2740
// RVA : 0x00BE2740
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::UpdateAttachments(idActor *this)
{
  idAnimatedEntity::UpdateAttachments(this);
  this->GetViewTransform(this, a2: &this->actorVolatile.modelInfo.eyePos, a3: &this->actorVolatile.modelInfo.eyeAxis);
}


// ========================================================================
// ?GetAreaNum@idActor@@QBAHPBVidAAS2@@@Z
// EA  : 0x82BE2788
// RVA : 0x00BE2788
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

int __fastcall idActor::GetAreaNum(idActor *this, idAAS2 *aas)
{
  idAASPositionMgr *v4; // r3
  idAASPosition *AASPosition; // r3

  v4 = this->GetAASPositionMgr(this);
  AASPosition = (idAASPosition *)idAASPositionMgr::GetAASPosition(this: v4, aas, ent: this);
  return idAASPosition::GetAreaNum(this: AASPosition);
}


// ========================================================================
// ?GetAASPosition@idActor@@QBAABVidAASPosition@@PBVidAAS2@@@Z
// EA  : 0x82BE27E0
// RVA : 0x00BE27E0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

const idAASPosition *__fastcall idActor::GetAASPosition(idActor *this, idAAS2 *aas)
{
  idAASPositionMgr *v4; // r3

  v4 = this->GetAASPositionMgr(this);
  return idAASPositionMgr::GetAASPosition(this: v4, aas, ent: this);
}


// ========================================================================
// ?GetEquippedWeapon@idActor@@QBAPAVidWeapon@@W4equipSlot_t@@@Z
// EA  : 0x82BE2830
// RVA : 0x00BE2830
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idWeapon *__fastcall idActor::GetEquippedWeapon(idActor *this, equipSlot_t slot)
{
  idWeapon *result; // r3

  result = (idWeapon *)this->GetEquipped(this, a2: slot);
  if ( result != nullptr )
    return idWeapon::CastTo(c: result);
  return result;
}


// ========================================================================
// ?GetEquippedWeapon@idActor@@UBAPAVidWeapon@@XZ
// EA  : 0x82BE2878
// RVA : 0x00BE2878
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idWeapon *__fastcall idActor::GetEquippedWeapon(idActor *this)
{
  equipSlot_t v2; // r3
  idWeapon *result; // r3

  v2 = this->GetWeaponSlot(this);
  result = (idWeapon *)this->GetEquipped(this, a2: v2);
  if ( result != nullptr )
    return idWeapon::CastTo(c: result);
  return result;
}


// ========================================================================
// ?InventoryRemoved@idActor@@UAAXPAVidInventoryItem@@@Z
// EA  : 0x82BE28E8
// RVA : 0x00BE28E8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::InventoryRemoved(idActor *this, idInventoryItem *item)
{
  int v2; // r10
  idInventoryItem **equipped; // r11

  v2 = 0;
  equipped = this->equipped;
  while ( *equipped != item )
  {
    ++v2;
    ++equipped;
    if ( v2 >= 15 )
      goto LABEL_6;
  }
  this->equipped[v2] = nullptr;
LABEL_6:
  idEntity::InventoryRemoved(this, item);
}


// ========================================================================
// ?DropAttachment@idActor@@UAAXW4equipSlot_t@@@Z
// EA  : 0x82BE2928
// RVA : 0x00BE2928
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::DropAttachment(idActor *this, equipSlot_t slot)
{
  idInventoryItem *v3; // r3

  v3 = this->GetEquipped(this, a2: slot);
  this->DropAttachment_2(this, a2: v3);
}


// ========================================================================
// ?GetEquipped@idActor@@UBAPAVidInventoryItem@@W4equipSlot_t@@@Z
// EA  : 0x82BE2978
// RVA : 0x00BE2978
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idInventoryItem *__fastcall idActor::GetEquipped(idActor *this, const equipSlot_t slot)
{
  return this->equipped[slot];
}


// ========================================================================
// ?ClearEquipped@idActor@@UAAXW4equipSlot_t@@@Z
// EA  : 0x82BE2988
// RVA : 0x00BE2988
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::ClearEquipped(idActor *this, const equipSlot_t slot)
{
  this->equipped[slot] = nullptr;
}


// ========================================================================
// ?ClearEquipped@idActor@@UAAXPAVidInventoryItem@@@Z
// EA  : 0x82BE29A0
// RVA : 0x00BE29A0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::ClearEquipped(idActor *this, idInventoryItem *item)
{
  int v2; // r10
  idInventoryItem **i; // r11

  v2 = 0;
  for ( i = this->equipped; *i != item; ++i )
  {
    if ( ++v2 >= 15 )
      return;
  }
  this->equipped[v2] = nullptr;
}


// ========================================================================
// ?SetFaction@idActor@@QAAXPBVidDeclFaction@@@Z
// EA  : 0x82BE29E0
// RVA : 0x00BE29E0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::SetFaction(idActor *this, const idDeclFaction *faction)
{
  idFaction::SetDeclFaction(this: &this->faction, faction, clearRelationships: false);
}


// ========================================================================
// ?IsCrouching@idActor@@QBA_NXZ
// EA  : 0x82BE29F0
// RVA : 0x00BE29F0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

BOOL __fastcall idActor::IsCrouching(idActor *this)
{
  return (_cntlzw(this->GetPosture(this) - 2) & 0x20) != 0;
}


// ========================================================================
// ?IsSitting@idActor@@QBA_NXZ
// EA  : 0x82BE2A28
// RVA : 0x00BE2A28
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

BOOL __fastcall idActor::IsSitting(idActor *this)
{
  return (_cntlzw(this->GetPosture(this) - 3) & 0x20) != 0;
}


// ========================================================================
// ?GetVehicle@idActor@@UAAPAVidVehicle@@XZ
// EA  : 0x82BE2A60
// RVA : 0x00BE2A60
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

const idVehicle *__fastcall idActor::GetVehicle(idActor *this)
{
  idVehicle *BindMaster; // r3

  BindMaster = (idVehicle *)idEntity::GetBindMaster(this);
  return idVehicle::CastTo(c: BindMaster);
}


// ========================================================================
// ?IsDrivingVehicle@idActor@@UBA_NXZ
// EA  : 0x82BE2A88
// RVA : 0x00BE2A88
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

int __fastcall idActor::IsDrivingVehicle(idActor *this)
{
  idVehicle *v2; // r3
  idActor *Driver; // r3
  unsigned __int8 v4; // r11

  v2 = (idVehicle *)this->GetVehicle(this);
  if ( v2 == nullptr )
    return 0;
  Driver = (idActor *)idVehicle::GetDriver(this: v2);
  v4 = 1;
  if ( Driver != this )
    return 0;
  return v4;
}


// ========================================================================
// ?Event_ItemInInventory@idActor@@AAA?AVeventBool@@PBDM@Z
// EA  : 0x82BE2AE0
// RVA : 0x00BE2AE0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_ItemInInventory(
        idActor *this,
        eventBool *result,
        const char *internalName,
        double count)
{
  idInventoryCollection *v8; // r3
  __int64 v9; // r8

  idLib::Warning(fmt: "itemInInventory() is DEPRECATED. Use numOfItemTypeInInventory() instead.");
  v8 = (idInventoryCollection *)(*(int (__fastcall **)(eventBool *))(*(_DWORD *)&result->value + 468))(a1: result);
  LODWORD(v9) = idInventoryCollection::FindTotalInventoryItemCount(this: v8, internalName);
  eventBool::eventBool((eventBool *)this, b: (float)v9 >= count);
  return this;
}


// ========================================================================
// ?Event_NumOfItemTypeInInventory@idActor@@AAA?AVeventInt@@PBD@Z
// EA  : 0x82BE2B68
// RVA : 0x00BE2B68
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_NumOfItemTypeInInventory(idActor *this, eventInt *result, const char *declName)
{
  idJobManager *v5; // r3
  idJob *InventoryItemByDeclName; // r3
  int v7; // r4

  v5 = (idJobManager *)(*(int (__fastcall **)(eventInt *))(result->value + 468))(a1: result);
  InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(this: v5, jobName: declName);
  if ( InventoryItemByDeclName != nullptr )
    v7 = ((int (__fastcall *)(idJob *))InventoryItemByDeclName->__vftable[2].dtr_idClass)(a1: InventoryItemByDeclName);
  else
    v7 = 0;
  eventInt::eventInt((eventInt *)this, i: v7);
  return this;
}


// ========================================================================
// ?Event_CurrentNPC@idActor@@AAA?AVeventString@@XZ
// EA  : 0x82BE2BE8
// RVA : 0x00BE2BE8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_CurrentNPC(idActor *this, eventString *result)
{
  idStrId *v3; // r3
  const char *Key; // r3
  _BYTE v6[16]; // [sp+50h] [-20h] BYREF

  v3 = (idStrId *)(*((int (__fastcall **)(_BYTE *))result->value + 189))(a1: v6);
  Key = idStrId::GetKey(this: v3);
  eventString::eventString((eventString *)this, s: Key);
  return this;
}


// ========================================================================
// ?Event_IsDead@idActor@@AAA?AVeventBool@@XZ
// EA  : 0x82BE2C38
// RVA : 0x00BE2C38
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_IsDead(idActor *this, eventBool *result)
{
  char v3; // r3

  v3 = (*(int (__fastcall **)(eventBool *))(*(_DWORD *)&result->value + 508))(a1: result);
  eventBool::eventBool((eventBool *)this, b: v3);
  return this;
}


// ========================================================================
// ?Event_GetWalkState@idActor@@ABA?AVeventFloat@@XZ
// EA  : 0x82BE2C88
// RVA : 0x00BE2C88
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_GetWalkState(idActor *this, eventFloat *result)
{
  __int64 v3; // r9

  LODWORD(v3) = (*(int (__fastcall **)(eventFloat *))(LODWORD(result->value) + 800))(a1: result);
  eventFloat::eventFloat((eventFloat *)this, f: (float)v3);
  return this;
}


// ========================================================================
// ?Event_GetWeaponReadyState@idActor@@ABA?AVeventFloat@@XZ
// EA  : 0x82BE2CE8
// RVA : 0x00BE2CE8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_GetWeaponReadyState(idActor *this, eventFloat *result)
{
  __int64 v3; // r9

  LODWORD(v3) = (*(int (__fastcall **)(eventFloat *))(LODWORD(result->value) + 808))(a1: result);
  eventFloat::eventFloat((eventFloat *)this, f: (float)v3);
  return this;
}


// ========================================================================
// ?GetDisassembleLoot@idActor@@QAAPAVidDisassembleLoot@@XZ
// EA  : 0x82BE2D48
// RVA : 0x00BE2D48
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idDisassembleLoot *__fastcall idActor::GetDisassembleLoot(idActor *this)
{
  return &this->disassembleLoot;
}


// ========================================================================
// ?Event_PostSpawn@idActor@@AAA?AVeventVoid@@XZ
// EA  : 0x82BE2D50
// RVA : 0x00BE2D50
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_PostSpawn(idActor *this, idEntity *result)
{
  idPhysics *Physics; // r3

  Physics = idEntity::GetPhysics(this: result);
  if ( Physics != nullptr
    && _RTDynamicCast(
         inptr: Physics,
         VfDelta: 0,
         SrcType: &idPhysics `RTTI Type Descriptor',
         TargetType: &idPhysics_Actor `RTTI Type Descriptor',
         isReference: 0) == nullptr )
  {
    idLib::Warning(
      fmt: "Entity '%s' does not have physics derived from idPhysics_Actor but the idActor entity assumes this to be true. Rem"
      "oving entity to prevent crashes.",
      result->name.data);
    idEventReceiver::PostEventMS(this: result, ev: &EV_Remove, time: 0);
  }
  return this;
}


// ========================================================================
// ?CanBeHealed@idActor@@UBA_NXZ
// EA  : 0x82BE2DE0
// RVA : 0x00BE2DE0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

const idBaseHealth *__fastcall idActor::CanBeHealed(idActor *this)
{
  const idBaseHealth *result; // r3
  const idBaseHealth *v2; // r31
  double v3; // fp31

  result = this->GetHealthComponent(this);
  v2 = result;
  if ( result != nullptr )
  {
    v3 = ((double (__fastcall *)(const idBaseHealth *))result->GetCurBaseHealth_Impl)(a1: result);
    return (const idBaseHealth *)(v3 < ((double (__fastcall *)(const idBaseHealth *))v2->GetMaxBaseHealth_Impl)(a1: v2));
  }
  return result;
}


// ========================================================================
// ?SetAxis@idActor@@UAAXABVidMat3@@@Z
// EA  : 0x82BE2E68
// RVA : 0x00BE2E68
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::SetAxis(idActor *this, const idMat3 *axis)
{
  this->actorVolatile.modelInfo.modelAxis = *axis;
}


// ========================================================================
// ?GetDefaultSurfaceType@idActor@@UBAHXZ
// EA  : 0x82BE2EB8
// RVA : 0x00BE2EB8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

int __fastcall idActor::GetDefaultSurfaceType(idActor *this)
{
  actorClass_t actorClass; // r11
  int result; // r3

  actorClass = this->actorConstants.actorClass;
  result = 27;
  if ( actorClass != ACTORCLASS_MUTANT )
    return 3;
  return result;
}


// ========================================================================
// ?AllocPresentable@idActor@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82BE2ED8
// RVA : 0x00BE2ED8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idPresentableActor *__fastcall idActor::AllocPresentable(idActor *this, idRenderModel *renderModel_)
{
  idPresentableActor *v4; // r29
  int entityNumber; // r27
  const idDeclFX *v6; // r26
  idInventoryCollection *v7; // r25
  idAnimStack *v8; // r3

  v4 = (idPresentableActor *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x3CE8u,
                               tag: TAG_PRESENTABLE,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v4 == nullptr )
    return nullptr;
  entityNumber = this->entityNumber;
  v6 = this->GetFXDecl(this);
  v7 = this->GetInventory_2(this);
  v8 = this->GetAnimStack_2(this);
  return idPresentableActor::idPresentableActor(
           this: v4,
           ent: this,
           renderModel_,
           animStack_: v8,
           inv: v7,
           entityNum_: entityNumber,
           fxDecl_: v6,
           useSphereModel_: true);
}


// ========================================================================
// __unwind$492829
// EA  : 0x82BE2FA4
// RVA : 0x00BE2FA4
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_492829()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?GetModelTransform@idActor@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82BE2FD0
// RVA : 0x00BE2FD0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::GetModelTransform(idActor *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  idAnimator_AF *p_afProperties; // r3
  BOOL isActive; // r11
  char v8; // r11
  idPhysics *Physics; // r3
  const idMat3 *v10; // r3
  idPhysics *v11; // r3
  double v12; // fp31
  double v13; // fp30
  double v14; // fp29
  float *v15; // r3
  double v16; // fp11
  double v17; // fp10
  idMat3 v18; // [sp+50h] [-60h] BYREF

  isActive = this->afProperties.isActive;
  p_afProperties = &this->afProperties;
  if ( isActive || (v8 = 0, p_afProperties->isClientAuthoritativeActive) )
    v8 = 1;
  if ( v8 != 0 )
  {
    idAnimator_AF::GetModelTransform(this: p_afProperties, modelOrigin, modelAxis);
  }
  else
  {
    Physics = idEntity::GetPhysics(this);
    v10 = Physics->GetAxis(this: Physics, a2: 0);
    *modelAxis = *idMat3::operator*(this: &v18, result: &this->actorVolatile.modelInfo.modelAxis, a: v10);
    v11 = idEntity::GetPhysics(this);
    v12 = (float)((float)(this->actorConstants.modelInfo.modelOffset.y * modelAxis->mat[1].x)
                + (float)((float)(this->actorConstants.modelInfo.modelOffset.x * modelAxis->mat[0].x)
                        + (float)(this->actorConstants.modelInfo.modelOffset.z * modelAxis->mat[2].x)));
    v13 = (float)((float)(this->actorConstants.modelInfo.modelOffset.x * modelAxis->mat[0].y)
                + (float)((float)(modelAxis->mat[1].y * this->actorConstants.modelInfo.modelOffset.y)
                        + (float)(modelAxis->mat[2].y * this->actorConstants.modelInfo.modelOffset.z)));
    v14 = (float)((float)(modelAxis->mat[0].z * this->actorConstants.modelInfo.modelOffset.x)
                + (float)((float)(modelAxis->mat[1].z * this->actorConstants.modelInfo.modelOffset.y)
                        + (float)(modelAxis->mat[2].z * this->actorConstants.modelInfo.modelOffset.z)));
    v15 = (float *)v11->GetOrigin(this: v11, a2: 0);
    v16 = (float)(v15[1] + (float)v13);
    v17 = (float)(v15[2] + (float)v14);
    modelOrigin->x = (float)v12 + *v15;
    modelOrigin->y = v16;
    modelOrigin->z = v17;
  }
}


// ========================================================================
// ?GetSoundTransform@idActor@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82BE3170
// RVA : 0x00BE3170
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::GetSoundTransform(idActor *this, idVec3 *soundOrigin, idMat3 *soundAxis)
{
  const idAnimator_AF *v6; // r3
  char v7; // r11
  const idAnimator_AF *v8; // r3
  const idAnimator_AF *v9; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v12; // r28
  idPhysics *v13; // r3
  double v14; // fp31
  double v15; // fp30
  double v16; // fp29
  float *v17; // r3
  double v18; // fp12
  double v19; // fp11
  idPhysics *v20; // r3
  float *v21; // r3
  idPhysics *Physics; // r28
  idPhysics *v23; // r27
  double v24; // fp31
  float *v25; // r3
  double v26; // fp30
  double v27; // fp29
  double v28; // fp31
  float *v29; // r3
  double v30; // fp6
  double v31; // fp5
  idPhysics *v32; // r3
  float *v33; // r3
  _BYTE v34[24]; // [sp+50h] [-60h] BYREF

  v6 = this->GetAF(this);
  if ( v6->isActive || (v7 = 0, v6->isClientAuthoritativeActive) )
    v7 = 1;
  if ( v7 != 0 )
  {
    v8 = this->GetAF(this);
    *soundOrigin = idPhysics_AF::GetBody(this: &v8->physicsObj, id: 0)->clipModel->origin;
    v9 = this->GetAF(this);
    *soundAxis = idPhysics_AF::GetBody(this: &v9->physicsObj, id: 0)->clipModel->axis;
  }
  else
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    presentable = this->presentable;
    v12 = TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( v12 == nullptr || (unsigned __int16)this->actorVolatile.modelInfo.soundJoint.value == 0xFFFF )
    {
      Physics = idEntity::GetPhysics(this);
      v23 = idEntity::GetPhysics(this);
      v24 = -this->GetEyeOffset(this: v34, result: this)->z;
      v25 = (float *)Physics->GetGravityNormal(this: Physics);
      v26 = (float)(*v25 * (float)v24);
      v27 = (float)(v25[1] * (float)v24);
      v28 = (float)(v25[2] * (float)v24);
      v29 = (float *)v23->GetOrigin(this: v23, a2: 0);
      v30 = (float)(v29[1] + (float)v27);
      v31 = (float)(v29[2] + (float)v28);
      soundOrigin->x = *v29 + (float)v26;
      soundOrigin->y = v30;
      soundOrigin->z = v31;
      v32 = idEntity::GetPhysics(this);
      v33 = (float *)v32->GetAxis(this: v32, a2: 0);
      soundAxis->mat[0].x = *v33;
      soundAxis->mat[0].y = v33[1];
      soundAxis->mat[0].z = v33[2];
      soundAxis->mat[1].x = v33[3];
      soundAxis->mat[1].y = v33[4];
      soundAxis->mat[1].z = v33[5];
      soundAxis->mat[2].x = v33[6];
      soundAxis->mat[2].y = v33[7];
      soundAxis->mat[2].z = v33[8];
    }
    else
    {
      idTreeAnimator::GetModelSpaceJointTransform(
        this: v12,
        pose: DRIVER_MODEL,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->actorVolatile.modelInfo.soundJoint.value,
        origin: soundOrigin,
        axis: soundAxis);
      v13 = idEntity::GetPhysics(this);
      v14 = (float)((float)(this->actorVolatile.modelInfo.modelAxis.mat[0].x
                          * (float)(this->actorConstants.modelInfo.modelOffset.x + soundOrigin->x))
                  + (float)((float)(this->actorVolatile.modelInfo.modelAxis.mat[2].x
                                  * (float)(this->actorConstants.modelInfo.modelOffset.z + soundOrigin->z))
                          + (float)(this->actorVolatile.modelInfo.modelAxis.mat[1].x
                                  * (float)(this->actorConstants.modelInfo.modelOffset.y + soundOrigin->y))));
      v15 = (float)((float)(this->actorVolatile.modelInfo.modelAxis.mat[0].y
                          * (float)(this->actorConstants.modelInfo.modelOffset.x + soundOrigin->x))
                  + (float)((float)(this->actorVolatile.modelInfo.modelAxis.mat[2].y
                                  * (float)(this->actorConstants.modelInfo.modelOffset.z + soundOrigin->z))
                          + (float)(this->actorVolatile.modelInfo.modelAxis.mat[1].y
                                  * (float)(this->actorConstants.modelInfo.modelOffset.y + soundOrigin->y))));
      v16 = (float)((float)(this->actorVolatile.modelInfo.modelAxis.mat[0].z
                          * (float)(this->actorConstants.modelInfo.modelOffset.x + soundOrigin->x))
                  + (float)((float)(this->actorVolatile.modelInfo.modelAxis.mat[2].z
                                  * (float)(this->actorConstants.modelInfo.modelOffset.z + soundOrigin->z))
                          + (float)(this->actorVolatile.modelInfo.modelAxis.mat[1].z
                                  * (float)(this->actorConstants.modelInfo.modelOffset.y + soundOrigin->y))));
      v17 = (float *)v13->GetOrigin(this: v13, a2: 0);
      v18 = (float)(v17[1] + (float)v15);
      v19 = (float)(v17[2] + (float)v16);
      soundOrigin->x = (float)v14 + *v17;
      soundOrigin->y = v18;
      soundOrigin->z = v19;
      v20 = idEntity::GetPhysics(this);
      v21 = (float *)v20->GetAxis(this: v20, a2: 0);
      soundAxis->mat[0].x = *v21;
      soundAxis->mat[0].y = v21[1];
      soundAxis->mat[0].z = v21[2];
      soundAxis->mat[1].x = v21[3];
      soundAxis->mat[1].y = v21[4];
      soundAxis->mat[1].z = v21[5];
      soundAxis->mat[2].x = v21[6];
      soundAxis->mat[2].y = v21[7];
      soundAxis->mat[2].z = v21[8];
    }
  }
}


// ========================================================================
// ?GetEyeOffset@idActor@@UBA?BVidVec3@@XZ
// EA  : 0x82BE3530
// RVA : 0x00BE3530
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::GetEyeOffset(idActor *this, idAI2 *result)
{
  float y; // r10
  float z; // r9
  float v6; // r8
  idAI2 *v7; // r3
  coverAction_t coverAction; // r11
  double x; // fp0
  double v10; // fp13
  double v11; // fp12
  idPresentable *presentable; // r11
  double v13; // fp0
  double v14; // fp1
  double v15; // fp12
  void (__fastcall *GetScale)(struct idAI2 *, idVec3 *); // ctr
  double v17; // fp10
  double v18; // fp9
  double v20; // fp12
  double v21; // fp11
  float v22[6]; // [sp+50h] [-30h] BYREF

  y = result->actorConstants.perception.eyeOffset.y;
  z = result->actorConstants.perception.eyeOffset.z;
  v6 = *(float *)&result->__vftable;
  this->__vftable = (idActor_vtbl *)LODWORD(result->actorConstants.perception.eyeOffset.x);
  *(float *)&this->listenerList = y;
  *(float *)&this->listeningToList = z;
  if ( (*(int (__fastcall **)(idAI2 *))(LODWORD(v6) + 784))(a1: result) == 2
    || result->GetPosture(this: result) == POSTURE_SITTING )
  {
    v7 = idAI2::CastTo(c: result);
    if ( v7 != nullptr
      && ((coverAction = v7->aiVolatile.cover.coverAction) == COVERACTION_PEEK_OVER
       || coverAction == COVERACTION_FIRE_OVER) )
    {
      x = result->actorConstants.perception.eyeOffset.x;
      v10 = result->actorConstants.perception.eyeOffset.y;
      v11 = result->actorConstants.perception.eyeOffset.z;
    }
    else
    {
      x = result->actorConstants.perception.crouchedEyeOffset.x;
      v10 = result->actorConstants.perception.crouchedEyeOffset.y;
      v11 = result->actorConstants.perception.crouchedEyeOffset.z;
    }
    *(float *)&this->listeningToList = v11;
    *(float *)&this->listenerList = v10;
    *(float *)&this->__vftable = x;
  }
  presentable = result->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  v13 = *(float *)&this->listeningToList;
  v14 = presentable->axis.mat[2].y;
  v15 = presentable->axis.mat[2].z;
  GetScale = result->GetScale;
  v17 = (float)((float)(presentable->axis.mat[0].y * *(float *)&this->__vftable)
              + (float)(presentable->axis.mat[1].y * *(float *)&this->listenerList));
  v18 = (float)((float)(presentable->axis.mat[0].z * *(float *)&this->__vftable)
              + (float)(presentable->axis.mat[1].z * *(float *)&this->listenerList));
  *(float *)&this->__vftable = (float)(presentable->axis.mat[0].x * *(float *)&this->__vftable)
                             + (float)((float)(presentable->axis.mat[1].x * *(float *)&this->listenerList)
                                     + (float)(presentable->axis.mat[2].x * *(float *)&this->listeningToList));
  *(float *)&this->listenerList = (float)((float)v14 * (float)v13) + (float)v17;
  *(float *)&this->listeningToList = (float)((float)v15 * (float)v13) + (float)v18;
  GetScale(this: result, a2: (idVec3 *)v22);
  v20 = (float)(v22[1] * *(float *)&this->listenerList);
  v21 = (float)(*(float *)&this->listeningToList * v22[2]);
  *(float *)&this->__vftable = *(float *)&this->__vftable * v22[0];
  *(float *)&this->listenerList = v20;
  *(float *)&this->listeningToList = v21;
  return this;
}


// ========================================================================
// ?GetViewTransform@idActor@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82BE36D0
// RVA : 0x00BE36D0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::GetViewTransform(idActor *this, idVec3 *origin, idMat3 *axis)
{
  idPhysics *Physics; // r28
  idPhysics *v7; // r27
  double v8; // fp31
  float *v9; // r3
  double v10; // fp30
  double v11; // fp29
  double v12; // fp31
  float *v13; // r3
  double v14; // fp6
  double v15; // fp5
  _BYTE v16[24]; // [sp+50h] [-60h] BYREF

  Physics = idEntity::GetPhysics(this);
  v7 = idEntity::GetPhysics(this);
  v8 = -this->GetEyeOffset(this: v16, result: this)->z;
  v9 = (float *)Physics->GetGravityNormal(this: Physics);
  v10 = (float)(*v9 * (float)v8);
  v11 = (float)(v9[1] * (float)v8);
  v12 = (float)(v9[2] * (float)v8);
  v13 = (float *)v7->GetOrigin(this: v7, a2: 0);
  v14 = (float)(v13[1] + (float)v11);
  v15 = (float)(v13[2] + (float)v12);
  origin->x = *v13 + (float)v10;
  origin->y = v14;
  origin->z = v15;
  *axis = this->actorVolatile.modelInfo.modelAxis;
}


// ========================================================================
// ?GetEyePos@idActor@@UBAXAAVidVec3@@@Z
// EA  : 0x82BE37F0
// RVA : 0x00BE37F0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::GetEyePos(idActor *this, idVec3 *eyePos)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  float *v6; // r29
  double v7; // fp7
  double v8; // fp0
  double v9; // fp6
  double v10; // fp11
  idPhysics *Physics; // r3
  float *v12; // r3
  float v13; // [sp+50h] [-30h] BYREF
  float v14; // [sp+54h] [-2Ch]
  float v15; // [sp+58h] [-28h]

  this->GetEyeOffset(this: (idActor *)&v13, result: (const idVec3 *)this);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v6 = (float *)TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v6 != nullptr )
  {
    v7 = (float)(v6[30] + v14);
    v8 = v6[29];
    v9 = (float)(v6[31] + v15);
    v10 = v13;
  }
  else
  {
    Physics = idEntity::GetPhysics(this);
    v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v7 = (float)(v12[1] + v14);
    v8 = v13;
    v9 = (float)(v12[2] + v15);
    v10 = *v12;
  }
  eyePos->z = v9;
  eyePos->y = v7;
  eyePos->x = (float)v10 + (float)v8;
  if ( ai_debugEyePos.valueInteger != 0 )
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorWhite,
      a3: eyePos,
      a4: ai_debugEyePos.valueInteger,
      a5: true);
}


// ========================================================================
// ?GetAimPoint@idActor@@UBAXW4aimPoint_t@@AAVidVec3@@@Z
// EA  : 0x82BE3908
// RVA : 0x00BE3908
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::GetAimPoint(idActor *this, unsigned int type, idVec3 *pos)
{
  idEntity *BindMaster; // r3
  idPhysics *Physics; // r3
  float *v8; // r3
  double v9; // fp6
  double v10; // fp4
  double v11; // fp13
  double v12; // fp12
  idPhysics *v13; // r3
  int v14; // r3
  char *v15; // r10
  _DWORD *v16; // r11
  int j; // ctr
  double v18; // fp8
  double v19; // fp6
  idPhysics *v20; // r3
  int v21; // r3
  char *v22; // r10
  _DWORD *v23; // r11
  int i; // ctr
  idPhysics *v25; // r3
  float *v26; // r3
  idPhysics *v27; // r3
  double y; // fp12
  double v29; // fp6
  double z; // fp11
  double v31; // fp5
  idPhysics *v32; // r3
  float *v33; // r3
  idVec3 v34; // [sp+50h] [-60h] BYREF
  float v35[3]; // [sp+60h] [-50h] BYREF
  char v36; // [sp+6Ch] [-44h] BYREF
  float v37; // [sp+70h] [-40h]
  float v38; // [sp+74h] [-3Ch]
  float v39; // [sp+78h] [-38h]
  float v40; // [sp+7Ch] [-34h]
  float v41; // [sp+80h] [-30h]
  float v42; // [sp+84h] [-2Ch]

  BindMaster = idEntity::GetBindMaster(this);
  if ( BindMaster != nullptr )
  {
    BindMaster->GetAimPoint(this: BindMaster, a2: (const aimPoint_t)type, a3: pos);
    return;
  }
  if ( type > 8 || type == 0 )
    goto LABEL_21;
  switch ( type )
  {
    case 1u:
LABEL_12:
      this->GetEyePos(this, a2: pos);
      return;
    case 2u:
      this->GetEyePos(this, a2: (idVec3 *)v35);
      Physics = idEntity::GetPhysics(this);
      v8 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
      v9 = (float)(v35[1] * (float)0.64999998);
      v10 = (float)(v35[2] * (float)0.64999998);
      v11 = (float)((float)((float)(v8[4] + v8[1]) * (float)0.5) * (float)0.35000002);
      v12 = (float)((float)((float)(v8[5] + v8[2]) * (float)0.5) * (float)0.35000002);
      pos->x = (float)((float)((float)(v8[3] + *v8) * (float)0.5) * (float)0.35000002)
             + (float)(v35[0] * (float)0.64999998);
      pos->y = (float)v11 + (float)v9;
      pos->z = (float)v12 + (float)v10;
      return;
    case 3u:
      goto LABEL_14;
    case 4u:
      v20 = idEntity::GetPhysics(this);
      v21 = (int)v20->GetAbsBounds(this: v20, a2: -1);
      v22 = &v36;
      v23 = (_DWORD *)(v21 - 4);
      for ( i = 6; i != 0; --i )
      {
        ++v23;
        v22 += 4;
        *(_DWORD *)v22 = *v23;
      }
      v25 = idEntity::GetPhysics(this);
      v26 = (float *)v25->GetOrigin(this: v25, a2: 0);
      pos->x = *v26;
      pos->y = v26[1];
      pos->z = (float)((float)(v42 - v39) * (float)0.25) + v26[2];
      return;
    case 5u:
LABEL_21:
      v32 = idEntity::GetPhysics(this);
      v33 = (float *)v32->GetOrigin(this: v32, a2: 0);
      pos->x = *v33;
      pos->y = v33[1];
      pos->z = v33[2];
      return;
    case 6u:
LABEL_14:
      v13 = idEntity::GetPhysics(this);
      v14 = (int)v13->GetAbsBounds(this: v13, a2: -1);
      v15 = &v36;
      v16 = (_DWORD *)(v14 - 4);
      for ( j = 6; j != 0; --j )
      {
        ++v16;
        v15 += 4;
        *(_DWORD *)v15 = *v16;
      }
      v18 = (float)(v38 + v41);
      v19 = (float)(v39 + v42);
      pos->x = (float)(v37 + v40) * (float)0.5;
      pos->y = (float)v18 * (float)0.5;
      pos->z = (float)v19 * (float)0.5;
      return;
    case 7u:
      goto LABEL_12;
    default:
      break;
  }
  this->GetEyePos(this, a2: pos);
  v27 = idEntity::GetPhysics(this);
  v27->GetLinearVelocity(this: (idPhysics *)&v34, result: (idVec3 *)v27, a3: 0);
  idVec3::NormalizeFast(this: &v34);
  y = pos->y;
  v29 = (float)(v34.y * (float)64.0);
  z = pos->z;
  v31 = (float)(v34.z * (float)64.0);
  pos->x = pos->x + (float)(v34.x * (float)64.0);
  pos->y = (float)y + (float)v29;
  pos->z = (float)z + (float)v31;
}


// ========================================================================
// ?StartRagdoll@idActor@@UAA?AW4testSolidResult_t@idAnimator_AF@@ABVidRagdollInfo@@@Z
// EA  : 0x82BE3C40
// RVA : 0x00BE3C40
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

int __fastcall idActor::StartRagdoll(idActor *this, const idRagdollInfo *info)
{
  idAnimator_AF *p_afProperties; // r31
  char v6; // r11
  idPhysics_AF *p_physicsObj; // r29
  idPhysics *Physics; // r3
  bool v9; // r27
  int v10; // r3
  int v11; // r27
  __int64 v12; // r5
  double v13; // fp31
  __int64 v14; // r11
  double jointFrictionDent; // fp31
  __int64 v16; // r10
  double v17; // fp30
  __int64 v18; // r8
  double contactFrictionDent; // fp31
  __int64 v20; // r7
  double v21; // fp30
  __int64 v22; // r5

  p_afProperties = &this->afProperties;
  if ( !this->afProperties.isLoaded )
    return 3;
  if ( this->afProperties.isSyncing )
  {
    idAnimator_AF::EndSync(this: &this->afProperties);
    return 3;
  }
  if ( this->afProperties.isActive || (v6 = 0, this->afProperties.isClientAuthoritativeActive) )
    v6 = 1;
  if ( v6 != 0 )
    return 3;
  p_physicsObj = &this->afProperties.physicsObj;
  this->afProperties.physicsObj.PutToRest(this: &this->afProperties.physicsObj);
  Physics = idEntity::GetPhysics(this);
  Physics->DisableClip(this: Physics);
  p_afProperties->physicsObj.EnableClip(this: &p_afProperties->physicsObj);
  v9 = info->velocityTime != 0;
  v10 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v11 = idAnimator_AF::StartFromCurrentPose(
          this: p_afProperties,
          time: v10,
          inheritAnimationVelocity_: v9,
          inheritOverrideVelocity_: false,
          overrideVelocity_: &vec3_origin);
  idEntity::UpdateVisuals(this);
  LODWORD(v12) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v13 = (float)((float)((float)v12 * (float)0.001) + info->slomoStart);
  LODWORD(v14) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idPhysics_AF::SetTimeScaleRamp(
    this: p_physicsObj,
    start: v13,
    end: (float)((float)((float)v14 * 0.001) + info->slomoEnd));
  jointFrictionDent = info->jointFrictionDent;
  LODWORD(v16) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v17 = (float)((float)((float)v16 * 0.001) + info->jointFrictionStart);
  LODWORD(v18) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idPhysics_AF::SetJointFrictionDent(
    this: p_physicsObj,
    dent: jointFrictionDent,
    start: v17,
    end: (float)((float)((float)v18 * 0.001) + info->jointFrictionEnd));
  contactFrictionDent = info->contactFrictionDent;
  LODWORD(v20) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v21 = (float)((float)((float)v20 * 0.001) + info->contactFrictionStart);
  LODWORD(v22) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idPhysics_AF::SetContactFrictionDent(
    this: p_physicsObj,
    dent: contactFrictionDent,
    start: v21,
    end: (float)((float)((float)v22 * 0.001) + info->contactFrictionEnd));
  return v11;
}


// ========================================================================
// ?StopRagdoll@idActor@@UAAXXZ
// EA  : 0x82BE3ED8
// RVA : 0x00BE3ED8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::StopRagdoll(idActor *this)
{
  idAnimator_AF *p_afProperties; // r3
  char v2; // r11

  p_afProperties = &this->afProperties;
  if ( p_afProperties->isActive || (v2 = 0, p_afProperties->isClientAuthoritativeActive) )
    v2 = 1;
  if ( v2 != 0 )
    idAnimator_AF::Stop(this: p_afProperties);
}


// ========================================================================
// ?Teleport@idActor@@UAAXABVidVec3@@ABVidAngles@@@Z
// EA  : 0x82BE3F10
// RVA : 0x00BE3F10
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::Teleport(idActor *this, const idVec3 *origin, idMat3 *angles)
{
  idPhysics *Physics; // r3
  double z; // fp13
  double y; // fp11
  idPhysics *v9; // r3
  float v10[4]; // [sp+50h] [-60h] BYREF
  idAngles v11[6]; // [sp+60h] [-50h] BYREF

  Physics = idEntity::GetPhysics(this);
  z = origin->z;
  y = origin->y;
  v10[0] = origin->x;
  v10[1] = y;
  v10[2] = (float)z + (float)0.25;
  Physics->SetOrigin(this: Physics, a2: (const idVec3 *)v10, a3: -1);
  v9 = idEntity::GetPhysics(this);
  v9->SetLinearVelocity(this: v9, a2: &vec3_origin, a3: 0);
  this->actorVolatile.modelInfo.modelAxis = *idAngles::ToMat3(this: v11, result: angles);
  idEntity::UpdateVisuals(this);
  idEntity::ForceDormancy(this, dormant: false, durationMS: 30000);
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) == 0 )
    idGameLocal::KillBox(this: gameLocal, ent: this, catch_teleport: false, teleportDmgDef: gameLocal->damageTelefrag);
}


// ========================================================================
// ?GetLastValidAreaNum@idActor@@QBAHPBVidAAS2@@@Z
// EA  : 0x82BE4040
// RVA : 0x00BE4040
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

int __fastcall idActor::GetLastValidAreaNum(idActor *this, idAAS2 *aas)
{
  idAASPositionMgr *v4; // r3

  v4 = this->GetAASPositionMgr(this);
  return idAASPositionMgr::GetAASPosition(this: v4, aas, ent: this)->areaNum;
}


// ========================================================================
// ?GetLastValidAASOrigin@idActor@@QBAABVidVec3@@PBVidAAS2@@@Z
// EA  : 0x82BE4098
// RVA : 0x00BE4098
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

const idVec3 *__fastcall idActor::GetLastValidAASOrigin(idActor *this, idAAS2 *aas)
{
  idAASPositionMgr *v4; // r3

  v4 = this->GetAASPositionMgr(this);
  return &idAASPositionMgr::GetAASPosition(this: v4, aas, ent: this)->validOrigin;
}


// ========================================================================
// ?GetAASOrigin@idActor@@QBAABVidVec3@@PBVidAAS2@@@Z
// EA  : 0x82BE40F0
// RVA : 0x00BE40F0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

const idVec3 *__fastcall idActor::GetAASOrigin(idActor *this, idAAS2 *aas)
{
  idAASPositionMgr *v4; // r3

  v4 = this->GetAASPositionMgr(this);
  return &idAASPositionMgr::GetAASPosition(this: v4, aas, ent: this)->origin;
}


// ========================================================================
// ?DoLocationDamage@idActor@@QAAXPBVidDeclDamage@@PAVidDamageGroup@@MAAM222222W4damageType_t@2@@Z
// EA  : 0x82BE4148
// RVA : 0x00BE4148
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::DoLocationDamage(
        idActor *this,
        const idDeclDamage *declDamage,
        idDamageGroup *damageGroup,
        double baseDamage,
        float *outBodyDamage,
        float *outLimbDamage,
        float *outArmorDamage,
        float *outArmorDamageScale,
        float *outArmoredHealthDamageScale,
        float *outBleedThroughDamage,
        float *outExcessDamage,
        const idDeclDamage::damageType_t damageTypes,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        float *a29,
        int a30,
        float *a31,
        int a32,
        float *a33,
        int a34,
        __int16 a35)
{
  double v35; // fp12
  double v44; // fp8

  *outArmorDamageScale = 0.0;
  *outLimbDamage = 0.0;
  *outArmorDamage = 0.0;
  *outArmoredHealthDamageScale = 1.0;
  *a29 = 0.0;
  *a31 = 0.0;
  *a33 = 0.0;
  if ( damageGroup != nullptr )
  {
    v35 = 0.0;
    if ( (a35 & 0x100) != 0 )
    {
      v35 = 0.30000001;
      *outArmoredHealthDamageScale = *outArmoredHealthDamageScale * (float)2.0;
    }
    _FP8 = (float)((float)1.0 - (float)((float)((float)v35 * damageGroup->damageScale) + damageGroup->armoredDamageScale));
    __asm { fsel      f7, f8, f9, f13 }
    *a29 = _FP7;
    _FP3 = (float)((float)(*outArmoredHealthDamageScale * (float)baseDamage) - damageGroup->locationArmor);
    __asm { fsel      f2, f3, f6, f4 }
    *outArmorDamageScale = _FP2;
    _FP10 = (float)(damageGroup->locationArmor - (float)baseDamage);
    __asm { fsel      f9, f10, f1, f11 }
    *a31 = (float)_FP9 * *a29;
    _FP3 = -(float)((float)baseDamage - (float)(damageGroup->locationArmor / *outArmoredHealthDamageScale));
    __asm { fsel      f2, f3, f0, f4 }
    *outArmorDamage = _FP2;
    *a33 = (float)_FP2 * damageGroup->damageScale;
    v44 = (float)(damageGroup->locationArmor - *outArmorDamageScale);
    damageGroup->locationArmor = damageGroup->locationArmor - *outArmorDamageScale;
    if ( v44 < 0.1 )
      damageGroup->locationArmor = 0.0;
    if ( damageGroup->affectsOverallHealth )
      *outLimbDamage = *a31 + *a33;
    if ( declDamage->ignoreArmor )
    {
      *outArmorDamage = baseDamage;
      *outLimbDamage = baseDamage;
    }
    damageGroup->health = damageGroup->health - *outArmorDamage;
  }
  else
  {
    *outLimbDamage = baseDamage;
  }
}


// ========================================================================
// ?GetDamageGroup@idActor@@QAAPAVidDamageGroup@@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82BE42B0
// RVA : 0x00BE42B0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idDamageGroup *__fastcall idActor::GetDamageGroup(idActor *this, const idIndex<short,enum invalidJointIndex_t> *joint)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v6; // r31
  const idDeclMD6 *decl; // r11
  idJointGroupCollection *p_jointGroupCollection; // r3
  const idJointGroup *JointGroupForJoint; // r28
  int v10; // r29
  int i; // r31

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v6 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v6 == nullptr )
    return nullptr;
  decl = v6->decl;
  p_jointGroupCollection = &decl->jointGroupCollection;
  if ( decl == nullptr )
    p_jointGroupCollection = nullptr;
  JointGroupForJoint = idJointGroupCollection::GetJointGroupForJoint(
                         this: p_jointGroupCollection,
                         type: 0,
                         jointIndex: joint);
  if ( JointGroupForJoint == nullptr )
    return nullptr;
  v10 = 0;
  if ( this->actorEditable.damageGroups.num <= 0 )
    return nullptr;
  for ( i = 0;
        idStr::Icmp(s1: this->actorEditable.damageGroups.list[i].groupName.data, s2: JointGroupForJoint->groupName.str) != 0;
        ++i )
  {
    if ( ++v10 >= this->actorEditable.damageGroups.num )
      return nullptr;
  }
  return &this->actorEditable.damageGroups.list[v10];
}


// ========================================================================
// ?GetDamageGroupHandle@idActor@@QAA?AV?$idHandle@HW4invalidJointGroupHandle@@$0A@@@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82BE4388
// RVA : 0x00BE4388
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::GetDamageGroupHandle(
        idActor *this,
        idAnimatedEntity *result,
        const idIndex<short,enum invalidJointIndex_t> *joint)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r30
  const idDeclMD6 *decl; // r11
  idJointGroupCollection *p_jointGroupCollection; // r4

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  presentable = result->presentable;
  v8 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 != nullptr )
  {
    decl = v8->decl;
    p_jointGroupCollection = &decl->jointGroupCollection;
    if ( decl == nullptr )
      p_jointGroupCollection = nullptr;
    idJointGroupCollection::GetJointGroupHandle(
      (idJointGroupCollection *)this,
      result: p_jointGroupCollection,
      type: 0,
      jointIndex: joint);
    return this;
  }
  else
  {
    this->__vftable = nullptr;
    return this;
  }
}


// ========================================================================
// ?GetDamageGroup@idActor@@QAAPAVidDamageGroup@@ABV?$idHandle@HW4invalidJointGroupHandle@@$0A@@@@Z
// EA  : 0x82BE4418
// RVA : 0x00BE4418
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idDamageGroup *__fastcall idActor::GetDamageGroup(
        idActor *this,
        const idHandle<int,enum invalidJointGroupHandle,0> *handle)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v6; // r31
  const idDeclMD6 *decl; // r11
  idJointGroupCollection *p_jointGroupCollection; // r3
  const idJointGroup *JointGroup; // r28
  int v10; // r29
  int i; // r31

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v6 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v6 == nullptr )
    return nullptr;
  decl = v6->decl;
  p_jointGroupCollection = &decl->jointGroupCollection;
  if ( decl == nullptr )
    p_jointGroupCollection = nullptr;
  JointGroup = idJointGroupCollection::GetJointGroup(this: p_jointGroupCollection, handle);
  if ( JointGroup == nullptr )
    return nullptr;
  v10 = 0;
  if ( this->actorEditable.damageGroups.num <= 0 )
    return nullptr;
  for ( i = 0;
        idStr::Icmp(s1: this->actorEditable.damageGroups.list[i].groupName.data, s2: JointGroup->groupName.str) != 0;
        ++i )
  {
    if ( ++v10 >= this->actorEditable.damageGroups.num )
      return nullptr;
  }
  return &this->actorEditable.damageGroups.list[v10];
}


// ========================================================================
// ?GetDamageGroup@idActor@@QAAPAVidDamageGroup@@PBD@Z
// EA  : 0x82BE44E8
// RVA : 0x00BE44E8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idDamageGroup *__fastcall idActor::GetDamageGroup(idActor *this, const char *name)
{
  int v4; // r29
  int i; // r30

  v4 = 0;
  if ( this->actorEditable.damageGroups.num <= 0 )
    return nullptr;
  for ( i = 0; idStr::Icmp(s1: this->actorEditable.damageGroups.list[i].groupName.data, s2: name) != 0; ++i )
  {
    if ( ++v4 >= this->actorEditable.damageGroups.num )
      return nullptr;
  }
  return &this->actorEditable.damageGroups.list[v4];
}


// ========================================================================
// ?GetPainGroupHandle@idActor@@QAA?AV?$idHandle@HW4invalidJointGroupHandle@@$0A@@@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82BE4560
// RVA : 0x00BE4560
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::GetPainGroupHandle(
        idActor *this,
        idAnimatedEntity *result,
        const idIndex<short,enum invalidJointIndex_t> *joint)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r30
  const idDeclMD6 *decl; // r11
  idJointGroupCollection *p_jointGroupCollection; // r4

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  presentable = result->presentable;
  v8 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 != nullptr )
  {
    decl = v8->decl;
    p_jointGroupCollection = &decl->jointGroupCollection;
    if ( decl == nullptr )
      p_jointGroupCollection = nullptr;
    idJointGroupCollection::GetJointGroupHandle(
      (idJointGroupCollection *)this,
      result: p_jointGroupCollection,
      type: 1,
      jointIndex: joint);
    return this;
  }
  else
  {
    this->__vftable = (idActor_vtbl *)NULL_JOINT_GROUP.value;
    return this;
  }
}


// ========================================================================
// ?GetDeathGroupHandle@idActor@@QAA?AV?$idHandle@HW4invalidJointGroupHandle@@$0A@@@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82BE45F8
// RVA : 0x00BE45F8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::GetDeathGroupHandle(
        idActor *this,
        idAnimatedEntity *result,
        const idIndex<short,enum invalidJointIndex_t> *joint)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r30
  const idDeclMD6 *decl; // r11
  idJointGroupCollection *p_jointGroupCollection; // r4

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  presentable = result->presentable;
  v8 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 != nullptr )
  {
    decl = v8->decl;
    p_jointGroupCollection = &decl->jointGroupCollection;
    if ( decl == nullptr )
      p_jointGroupCollection = nullptr;
    idJointGroupCollection::GetJointGroupHandle(
      (idJointGroupCollection *)this,
      result: p_jointGroupCollection,
      type: 3,
      jointIndex: joint);
    return this;
  }
  else
  {
    this->__vftable = (idActor_vtbl *)NULL_JOINT_GROUP.value;
    return this;
  }
}


// ========================================================================
// ?GetDamageDirection@idActor@@SA?AW4damageDirection_t@@ABVidMat3@@ABVidVec3@@H@Z
// EA  : 0x82BE4690
// RVA : 0x00BE4690
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

int __fastcall idActor::GetDamageDirection(const idMat3 *axis, const idVec3 *dir, const int numDirs)
{
  double v3; // fp12
  double v4; // fp0

  v3 = (float)((float)(axis->mat[1].x * dir->x)
             + (float)((float)(axis->mat[1].y * dir->y) + (float)(axis->mat[1].z * dir->z)));
  v4 = (float)((float)(axis->mat[0].x * dir->x)
             + (float)((float)(axis->mat[0].y * dir->y) + (float)(axis->mat[0].z * dir->z)));
  switch ( numDirs )
  {
    case 1:
      return 1;
    case 2:
      if ( v4 > 0.0 )
        return 2;
      return 1;
    case 4:
      if ( v4 >= 0.70710677 )
        return 2;
      if ( v4 <= -0.70710677 )
        return 1;
      if ( v3 <= -0.70710677 )
        return 3;
      return 4;
    default:
      break;
  }
  if ( numDirs != 8 )
    return 0;
  if ( v3 >= 0.0 )
  {
    if ( v4 < -0.92387003 )
      return 1;
    if ( v4 >= -0.38262999 )
    {
      if ( v4 < 0.38262999 )
        return 4;
      if ( v4 >= 0.92387003 )
        return 2;
      return 8;
    }
    else
    {
      return 6;
    }
  }
  else
  {
    if ( v4 < -0.92387003 )
      return 1;
    if ( v4 >= -0.38262999 )
    {
      if ( v4 < 0.38262999 )
        return 3;
      if ( v4 >= 0.92387003 )
        return 2;
      return 7;
    }
    else
    {
      return 5;
    }
  }
}


// ========================================================================
// ?GetDamageIntensity@idActor@@QAA?AW4damageIntensity_t@@PBVidDeclDamage@@M@Z
// EA  : 0x82BE47F0
// RVA : 0x00BE47F0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

damageIntensity_t __fastcall idActor::GetDamageIntensity(idActor *this, const idDeclDamage *damageDef, double damage)
{
  damageIntensity_t result; // r3
  idBaseHealth *v5; // r3
  idBaseHealth *v6; // r31
  double v7; // fp0

  if ( damageDef != nullptr && damageDef->intensity != DAMAGEINTENSITY_NONE )
    return damageDef->intensity;
  v5 = this->GetHealthComponent_2(this);
  v6 = v5;
  if ( v5 == nullptr || ((double (__fastcall *)(idBaseHealth *))v5->GetMaxBaseHealth_Impl)(a1: v5) <= 0.0 )
    return DAMAGEINTENSITY_HEAVY;
  v7 = (float)((float)damage / v6->GetMaxBaseHealth_Impl(this: v6));
  if ( v7 < 0.25999999 )
    return DAMAGEINTENSITY_LIGHT;
  result = DAMAGEINTENSITY_MEDIUM;
  if ( v7 >= 0.66000003 )
    return DAMAGEINTENSITY_HEAVY;
  return result;
}


// ========================================================================
// ?ApplyWaterEffects@idActor@@UAAXHH@Z
// EA  : 0x82BE48C0
// RVA : 0x00BE48C0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::ApplyWaterEffects(idActor *this, int physId, const int id)
{
  idPhysics *Physics; // r3
  __int64 v6; // r4
  const idDeclParticle *waterPrtFast; // r26
  unsigned int v8; // r7
  double emissionRate; // fp13
  idPhysics *v10; // r3
  int v11; // r3
  float v12; // r7
  float v13; // r6
  idPhysics *PhysicsForId; // r3
  idPhysics *v15; // r30
  int v16; // r25
  __int64 v17; // r10
  unsigned int v18; // r7
  double v19; // fp31
  int GameMsPerFrame; // r29
  int GameMs; // r31
  idRenderModelEffects *MergeBranch; // r3
  int v23; // [sp+8h] [-D8h]
  int v24; // [sp+Ch] [-D4h]
  int v25; // [sp+10h] [-D0h]
  int v26; // [sp+14h] [-CCh]
  int v27; // [sp+18h] [-C8h]
  int v28; // [sp+1Ch] [-C4h]
  int v29; // [sp+20h] [-C0h]
  int v30; // [sp+24h] [-BCh]
  int v31; // [sp+28h] [-B8h]
  int v32; // [sp+2Ch] [-B4h]
  int v33; // [sp+30h] [-B0h]
  int v34; // [sp+34h] [-ACh]
  int v35; // [sp+38h] [-A8h]
  int v36; // [sp+3Ch] [-A4h]
  int v37; // [sp+40h] [-A0h]
  int v38; // [sp+44h] [-9Ch]
  int v39; // [sp+48h] [-98h]
  int v40; // [sp+4Ch] [-94h]
  int v41; // [sp+50h] [-90h]
  _QWORD v42[2]; // [sp+60h] [-80h] BYREF
  idMat3 v43; // [sp+70h] [-70h] BYREF

  Physics = idEntity::GetPhysics(this);
  HIDWORD(v6) = Physics->GetLinearVelocity(this: (idPhysics *)&v43.mat[1].y, result: (idVec3 *)Physics, a3: 0);
  if ( __fsqrts((float)((float)(v43.mat[1].y * v43.mat[1].y)
                      + (float)((float)(v43.mat[1].z * v43.mat[1].z) + (float)(v43.mat[2].x * v43.mat[2].x)))) > this->actorConstants.waterInteraction.moveSpeedSlow )
    waterPrtFast = this->actorConstants.waterInteraction.waterPrtFast;
  else
    waterPrtFast = this->actorConstants.waterInteraction.waterPrtSlow;
  if ( waterPrtFast != nullptr )
  {
    v8 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v8;
    emissionRate = this->actorConstants.waterInteraction.emissionRate;
    LODWORD(v6) = (v8 >> 10) & 0x7FFF;
    v42[0] = v6;
    if ( (float)((float)v6 * (float)0.000030518509) < emissionRate )
    {
      v10 = idEntity::GetPhysics(this);
      v11 = (int)v10->GetOrigin(this: v10, a2: 0);
      v12 = *(float *)(v11 + 4);
      v13 = *(float *)(v11 + 8);
      v43.mat[0].x = *(float *)v11;
      v43.mat[0].y = v12;
      v43.mat[0].z = v13;
      PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: physId);
      v15 = PhysicsForId;
      if ( PhysicsForId != nullptr )
      {
        v16 = (int)PhysicsForId->GetBounds(this: PhysicsForId, a2: -1);
        v43.mat[0].z = v15->GetOrigin(this: v15, a2: 0)->z + *(float *)(v16 + 20);
      }
      HIDWORD(v17) = 458752;
      HIDWORD(v42[0]) = -1;
      v18 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v18 + 1013904223;
      LODWORD(v17) = ((v18 + 1013904223) >> 10) & 0x7FFF;
      v42[1] = v17;
      v19 = (float)((float)v17 * (float)0.000030518509);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
      idRenderModelEffects::AddParticles(
        this: MergeBranch,
        particle: waterPrtFast,
        systemStartTime: GameMs,
        gameMsPerFrame: GameMsPerFrame,
        diversity: v19,
        origin: (const idVec3 *)v42,
        axis: &v43,
        velocity: mat3_identity.mat,
        color: &vec3_origin.x,
        a10: v23,
        a11: v24,
        a12: v25,
        a13: v26,
        a14: v27,
        a15: v28,
        a16: v29,
        a17: v30,
        a18: v31,
        a19: v32,
        a20: v33,
        a21: v34,
        a22: v35,
        a23: v36,
        a24: v37,
        a25: v38,
        a26: v39,
        a27: v40,
        a28: v41,
        a29: (unsigned int *)v42);
    }
  }
}


// ========================================================================
// ?GetEquippedWeaponAnimator@idActor@@QAAPAVidTreeAnimator@@XZ
// EA  : 0x82BE4AD0
// RVA : 0x00BE4AD0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idTreeAnimator *__fastcall idActor::GetEquippedWeaponAnimator(idActor *this)
{
  idWeapon *v2; // r30
  idHandle<int,enum invalidAttachment_t,-1> *v3; // r3
  idAttachmentCollection *v4; // r3
  const idAttachment *v5; // r3
  idAttachmentCollection v7; // [sp+50h] [-20h] BYREF

  v2 = this->GetEquippedWeapon(this);
  if ( v2 != nullptr )
  {
    v3 = (idHandle<int,enum invalidAttachment_t,-1> *)this->GetAttachments_2(this);
    idAttachmentCollection::FindAttachment(this: &v7, result: v3, item: v2);
    if ( v7.attachments.list == (idAttachment *)-1 )
    {
      idLib::Warning(fmt: "idActor::GetEquippedWeaponAnimator - could not find weapon attachment");
    }
    else
    {
      v4 = this->GetAttachments_2(this);
      v5 = idAttachmentCollection::Get(this: v4, handle: (const idHandle<int,enum invalidAttachment_t,-1> *)&v7);
      if ( v5 == nullptr || v5->handle.value == -1 )
      {
        idLib::Warning(fmt: "idActor::GetEquippedWeaponAnimator - attachment is null or has no handle");
      }
      else
      {
        if ( v5->presentable != nullptr )
          return (idTreeAnimator *)_RTDynamicCast(
                                     inptr: v5->presentable->model,
                                     VfDelta: 0,
                                     SrcType: &idRenderModel `RTTI Type Descriptor',
                                     TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                     isReference: 0);
        idLib::Warning(fmt: "idActor::GetEquippedWeaponAnimator - attachment has no model");
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "idActor::GetEquippedWeaponAnimator - no equipped weapon");
  }
  return nullptr;
}


// ========================================================================
// ?GetMeleeTagData@idActor@@QAA_NPBDAAUtagData_t@@AAVidVec3@@AA_N@Z
// EA  : 0x82BE4BE0
// RVA : 0x00BE4BE0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

int __fastcall idActor::GetMeleeTagData(
        idActor *this,
        const char *tagName,
        tagData_t *outTagData,
        idVec3 *outOrigin,
        bool *outUseWeaponAnimator)
{
  idTreeAnimator *EquippedWeaponAnimator; // r3
  idTreeAnimator *v11; // r29
  idPropsCollection *v12; // r11
  const tagData_t *v13; // r3
  int v14; // r11
  float *v15; // r11
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v19; // r29
  idPropsCollection *decl; // r11
  const tagData_t *Tag; // r3
  int value; // r11
  float *p_x; // r11

  EquippedWeaponAnimator = idActor::GetEquippedWeaponAnimator(this);
  v11 = EquippedWeaponAnimator;
  *outUseWeaponAnimator = false;
  if ( EquippedWeaponAnimator == nullptr
    || (v12 = (idPropsCollection *)EquippedWeaponAnimator->decl) == nullptr
    || v12 == (idPropsCollection *)-352
    || (v13 = idPropsCollection::GetTag(this: v12 + 22, propName: idPropInfo::INFO_PROP_NAME, tagName),
        outTagData->trans = v13->trans,
        outTagData->rot = v13->rot,
        v14 = v13->parentJoint.value,
        outTagData->parentJoint.value = v14,
        v14 == 0xFFFF) )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    presentable = this->presentable;
    v19 = TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( v19 == nullptr )
      return 0;
    decl = (idPropsCollection *)v19->decl;
    if ( decl == nullptr )
      return 0;
    if ( decl == (idPropsCollection *)-352 )
      return 0;
    Tag = idPropsCollection::GetTag(this: decl + 22, propName: idPropInfo::INFO_PROP_NAME, tagName);
    outTagData->trans = Tag->trans;
    outTagData->rot = Tag->rot;
    value = Tag->parentJoint.value;
    outTagData->parentJoint.value = value;
    if ( value == 0xFFFF )
    {
      return 0;
    }
    else
    {
      p_x = &v19->deferredOrigin.x;
      if ( !v19->useDeferredPosition )
        p_x = &v19->g.origin.x;
      outOrigin->x = *p_x;
      outOrigin->y = p_x[1];
      outOrigin->z = p_x[2];
      return 1;
    }
  }
  else
  {
    v15 = &v11->deferredOrigin.x;
    if ( !v11->useDeferredPosition )
      v15 = &v11->g.origin.x;
    outOrigin->x = *v15;
    outOrigin->y = v15[1];
    outOrigin->z = v15[2];
    *outUseWeaponAnimator = true;
    return 1;
  }
}


// ========================================================================
// ?IsEquippedWeaponOneHanded@idActor@@QBA_NXZ
// EA  : 0x82BE4DB0
// RVA : 0x00BE4DB0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

BOOL __fastcall idActor::IsEquippedWeaponOneHanded(idActor *this)
{
  idWeapon *v1; // r3
  const idDeclInventory *decl; // r11

  v1 = this->GetEquippedWeapon(this);
  return v1 != nullptr && (decl = v1->decl) != nullptr && (_cntlzw(decl->numHands - 1) & 0x20) != 0;
}


// ========================================================================
// ?EquipItem@idActor@@UAA_NPAVidInventoryItem@@W4equipSlot_t@@@Z
// EA  : 0x82BE4E28
// RVA : 0x00BE4E28
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

int __fastcall idActor::EquipItem(idActor *this, idInventoryItem *item, equipSlot_t equipSlot)
{
  const idDeclInventory *decl; // r29
  equipSlot_t holsterSlot; // r30
  idAttachmentCollection *v8; // r3
  __int32 v10; // r26
  idInventoryItem *v11; // r11
  idInventoryItem *v12; // r25
  idAttachmentCollection *v13; // r3
  int num; // r6
  const idDeclInventory::idAttachmentInfo *v15; // r7
  int v16; // r9
  idDeclInventory::idAttachmentInfo *list; // r8
  int v18; // r11
  idPresentable *presentable; // r30
  idInventoryItem_vtbl *v20; // r29
  idFXManager *v21; // r3
  idAttachmentCollection *v22; // r3
  idAttachmentCollection v23[4]; // [sp+50h] [-50h] BYREF

  decl = item->decl;
  holsterSlot = decl->holsterSlot;
  if ( this->equipped[holsterSlot] == item )
  {
    v8 = this->GetAttachments_2(this);
    idAttachmentCollection::RemoveAttachment(this: v8, item);
    this->ClearEquipped_2(this, a2: holsterSlot);
  }
  if ( equipSlot == EQUIP_NONE )
  {
    equipSlot = decl->equipSlot;
    if ( equipSlot == EQUIP_NONE )
      return 0;
  }
  v10 = 4 * (equipSlot + 2349);
  v11 = *(idInventoryItem **)((char *)&this->__vftable + v10);
  if ( v11 == item )
    return 0;
  if ( v11 != nullptr )
  {
    if ( idAI2::CastTo(c: (idAI2 *)this) != nullptr )
      idLib::Warning(
        fmt: "Tried to equip item '%s' in slot '%s' when it is already occupied by '%s'",
        item->decl->name.str,
        idDeclInventory::equipSlotTagNames[decl->equipSlot],
        this->equipped[decl->equipSlot]->decl->name.str);
    v12 = *(idInventoryItem **)((char *)&this->__vftable + v10);
    v13 = this->GetAttachments_2(this);
    idAttachmentCollection::RemoveAttachment(this: v13, item: v12);
    this->ClearEquipped_2(this, a2: equipSlot);
    this->HolsterItem(this, a2: v12, a3: true);
  }
  if ( !decl->noAttachment && common->IsServer(this: common) )
  {
    num = decl->attachmentInfo.num;
    v15 = nullptr;
    v16 = 0;
    if ( num > 0 )
    {
      list = decl->attachmentInfo.list;
      v18 = 0;
      while ( list[v18].equipSlot != equipSlot || list[v18].particleFx == nullptr )
      {
        ++v16;
        ++v18;
        if ( v16 >= num )
          goto LABEL_20;
      }
      v15 = &list[v18];
    }
LABEL_20:
    idAttachmentCollection::AddAttachment(
      this: v23,
      result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
      item,
      tagName: idDeclInventory::equipSlotTagNames[equipSlot],
      fxAttachInfo: v15);
  }
  *(idActor_vtbl **)((char *)&this->__vftable + v10) = (idActor_vtbl *)item;
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  presentable = this->presentable;
  v20 = item->__vftable;
  v21 = this->GetFXMgrForAttachment(this, a2: item);
  v20->OnEquip(this: item, a2: presentable, a3: v21);
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) != 0 )
  {
    v22 = this->GetAttachments_2(this);
    idAttachmentCollection::HideAttachments(this: v22);
  }
  return 1;
}


// ========================================================================
// ?ShowAttachment@idActor@@UAAXPAVidInventoryItem@@@Z
// EA  : 0x82BE5090
// RVA : 0x00BE5090
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::ShowAttachment(idActor *this, idInventoryItem *item)
{
  idAttachmentCollection *p_attachments; // r30
  idAttachmentCollection v4; // [sp+50h] [-20h] BYREF

  p_attachments = &this->attachments;
  idAttachmentCollection::FindAttachment(
    this: &v4,
    result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
    item);
  if ( v4.attachments.list == (idAttachment *)-1 )
    idLib::Warning(fmt: "ShowAttachment - no attachment for item '%s'.", item->decl->internalName.data);
  else
    idAttachmentCollection::ShowAttachment(
      this: p_attachments,
      handle: (const idHandle<int,enum invalidAttachment_t,-1> *)&v4);
}


// ========================================================================
// ?HideAttachment@idActor@@UAAXPAVidInventoryItem@@@Z
// EA  : 0x82BE5108
// RVA : 0x00BE5108
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::HideAttachment(idActor *this, idInventoryItem *item)
{
  idAttachmentCollection *p_attachments; // r30
  idAttachmentCollection v4; // [sp+50h] [-20h] BYREF

  p_attachments = &this->attachments;
  idAttachmentCollection::FindAttachment(
    this: &v4,
    result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
    item);
  if ( v4.attachments.list == (idAttachment *)-1 )
    idLib::Warning(fmt: "ShowAttachment - no attachment for item '%s'.", item->decl->internalName.data);
  else
    idAttachmentCollection::HideAttachment(
      this: p_attachments,
      handle: (const idHandle<int,enum invalidAttachment_t,-1> *)&v4,
      ignoreShowAll: false);
}


// ========================================================================
// ?Event_UnequipAndDeleteDroppedItem@idActor@@AAA?AVeventVoid@@W4equipSlot_t@@@Z
// EA  : 0x82BE5180
// RVA : 0x00BE5180
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_UnequipAndDeleteDroppedItem(idActor *this, idEntity *result, const equipSlot_t slot)
{
  idInventoryItem *v5; // r30
  idPresentable *presentable; // r4

  v5 = *((idInventoryItem **)&result[11].defaultPhysicsObj.current.worldAxis.mat[0].z + slot);
  if ( v5 != nullptr )
  {
    result->__vftable[1].SetModelByName(this: result, a2: (const char *)v5);
    presentable = result->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      presentable = result->presentable;
    }
    idInventoryCollection::DeleteInventoryItem(
      this: (idInventoryCollection *)((char *)&result[11].touchTriggersQuery.index + 4),
      owner: presentable,
      item: v5,
      count: 1);
  }
  return this;
}


// ========================================================================
// ?GetFXMgrForAttachment@idAlignedEntity@@QAAPAVidFXManager@@PAVidInventoryItem@@@Z
// EA  : 0x82BE51F8
// RVA : 0x00BE51F8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idFXManager *__fastcall idAlignedEntity::GetFXMgrForAttachment(idActor *this, idInventoryItem *item)
{
  idHandle<int,enum invalidAttachment_t,-1> *v4; // r3
  idAttachmentCollection *v5; // r3
  const idAttachment *v6; // r3
  idPresentable *presentable; // r11
  idAttachmentCollection v9; // [sp+50h] [-20h] BYREF

  v4 = (idHandle<int,enum invalidAttachment_t,-1> *)this->GetAttachments_2(this);
  idAttachmentCollection::FindAttachment(this: &v9, result: v4, item);
  if ( v9.attachments.list == (idAttachment *)-1
    || (v5 = this->GetAttachments_2(this),
        (v6 = idAttachmentCollection::Get(this: v5, handle: (const idHandle<int,enum invalidAttachment_t,-1> *)&v9)) == nullptr)
    || (presentable = v6->presentable, v6->presentable == nullptr) )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
  }
  return &presentable->fxManager;
}


// ========================================================================
// ?RepairShield@idActor@@UAAXM@Z
// EA  : 0x82BE52A8
// RVA : 0x00BE52A8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::RepairShield(idActor *this, double value)
{
  idBaseHealth *v3; // r3

  v3 = this->GetHealthComponent_2(this);
  if ( v3 != nullptr )
    v3->HealShield_Impl(this: v3, a2: value);
}


// ========================================================================
// ?HolsterItem@idActor@@UAA_NPAVidInventoryItem@@_N@Z
// EA  : 0x82BE5300
// RVA : 0x00BE5300
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

int __fastcall idActor::HolsterItem(idActor *this, idInventoryItem *item, bool showHolstered)
{
  const idDeclInventory *decl; // r9
  equipSlot_t holsterSlot; // r11
  int v7; // r29
  idInventoryItem *v8; // r10
  idAttachmentCollection v10[2]; // [sp+50h] [-30h] BYREF

  if ( item == nullptr )
    return 0;
  decl = item->decl;
  holsterSlot = decl->holsterSlot;
  if ( holsterSlot == EQUIP_NONE )
    return 0;
  v7 = 4 * (holsterSlot + 2349);
  v8 = *(idInventoryItem **)((char *)&this->__vftable + v7);
  if ( v8 == item )
    return 0;
  if ( v8 != nullptr )
  {
    idLib::Warning(
      fmt: "Tried to holster item '%s' in slot '%s' when it is already occupied by '%s'",
      decl->name.str,
      idDeclInventory::equipSlotTagNames[holsterSlot],
      v8->decl->name.str);
    return 0;
  }
  if ( showHolstered )
    idAttachmentCollection::AddAttachment(
      this: v10,
      result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
      item,
      tagName: idDeclInventory::equipSlotTagNames[holsterSlot],
      fxAttachInfo: nullptr);
  *(idActor_vtbl **)((char *)&this->__vftable + v7) = (idActor_vtbl *)item;
  return 1;
}


// ========================================================================
// ?UnequipItem@idActor@@UAA_NPAVidInventoryItem@@@Z
// EA  : 0x82BE53C0
// RVA : 0x00BE53C0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

int __fastcall idActor::UnequipItem(idActor *this, idInventoryItem *item)
{
  equipSlot_t v4; // r27
  idInventoryItem **i; // r11
  idPresentable *presentable; // r28
  idInventoryItem_vtbl *v8; // r29
  idFXManager *v9; // r3
  idAttachmentCollection *v10; // r3

  v4 = EQUIP_NONE;
  for ( i = this->equipped; *i != item || item == nullptr; ++i )
  {
    if ( ++v4 >= EQUIP_MAX )
      return 0;
  }
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v8 = item->__vftable;
  v9 = this->GetFXMgrForAttachment(this, a2: item);
  v8->OnUnequip(this: item, a2: presentable, a3: v9);
  v10 = this->GetAttachments_2(this);
  idAttachmentCollection::RemoveAttachment(this: v10, item);
  this->ClearEquipped_2(this, a2: v4);
  return 1;
}


// ========================================================================
// ?SetLooted@idActor@@QAAX_N@Z
// EA  : 0x82BE5498
// RVA : 0x00BE5498
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::SetLooted(idActor *this, bool b)
{
  idPresentable *presentable; // r11
  idRenderModel *model; // r9

  this->looted = b;
  if ( b )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    model = presentable->model;
    presentable->highlightColor = HIGHLIGHT_COLOR_NONE;
    model->g.highlightColor = HIGHLIGHT_COLOR_NONE;
  }
}


// ========================================================================
// ?HasLootableItems@idActor@@QBA_NXZ
// EA  : 0x82BE54F8
// RVA : 0x00BE54F8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

int __fastcall idActor::HasLootableItems(idActor *this)
{
  bfx::Planner3D *v1; // r30
  int v2; // r31
  idInventoryItem *InventoryItem; // r3

  v1 = (bfx::Planner3D *)this->GetInventory(this);
  v2 = 0;
  if ( (int)idScriptObject::GetTypeDef(this: v1) <= 0 )
    return 0;
  while ( 1 )
  {
    InventoryItem = idInventoryCollection::GetInventoryItem(this: (idInventoryCollection *)v1, index: v2);
    if ( InventoryItem != nullptr && InventoryItem->lootable )
      break;
    if ( ++v2 >= (int)idScriptObject::GetTypeDef(this: v1) )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?GetFaction@idActor@@UAAPAVidFaction@@XZ
// EA  : 0x82BE5588
// RVA : 0x00BE5588
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idFaction *__fastcall idActor::GetFaction(idActor *this)
{
  idFaction *result; // r3
  bool v3; // zf

  if ( this->tempFactionTime > 0 )
  {
    v3 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) <= this->tempFactionTime;
    result = &this->faction;
    if ( v3 )
      return result;
    idFaction::SetDeclFaction(this: result, faction: this->tempFaction, clearRelationships: false);
    this->tempFaction = nullptr;
    this->tempFactionTime = 0;
  }
  return &this->faction;
}


// ========================================================================
// ?UpdateTempFaction@idActor@@QAAXXZ
// EA  : 0x82BE5600
// RVA : 0x00BE5600
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::UpdateTempFaction(idActor *this)
{
  if ( this->tempFactionTime > 0
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->tempFactionTime )
  {
    idFaction::SetDeclFaction(this: &this->faction, faction: this->tempFaction, clearRelationships: false);
    this->tempFaction = nullptr;
    this->tempFactionTime = 0;
  }
}


// ========================================================================
// ?SetPosture@idActor@@UAAXW4posture_t@@@Z
// EA  : 0x82BE5678
// RVA : 0x00BE5678
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::SetPosture(idActor *this, posture_t state)
{
  char v4; // r11
  posture_t bodyState; // r11
  idPhysics *Physics; // r3
  idPhysics *v7; // r31
  physicsType_t type; // r11
  idPhysics_vtbl *v9; // r11

  if ( state < POSTURE_NONE || (v4 = 1, state >= POSTURE_MAX) )
    v4 = 0;
  if ( v4 != 0 && !this->actorEditable.forceBodyState )
  {
    bodyState = this->actorEditable.bodyState;
    this->actorEditable.bodyState = state;
    if ( bodyState != state )
    {
      this->actorVolatile.postureChangeTime = idGameTimeManager::GetGameMs(
                                                this: &clientGame->gameTimeManager,
                                                type: GAMETIME_SCALED);
      Physics = idEntity::GetPhysics(this);
      v7 = Physics;
      if ( Physics != nullptr )
      {
        type = Physics->type;
        if ( (type == PHYSICS_AI || type == PHYSICS_PLAYER) && Physics->GetClipModel(this: Physics, a2: 1) != nullptr )
        {
          v9 = v7->__vftable;
          if ( state == POSTURE_SITTING )
            ((void (__fastcall *)(idPhysics *, int))v9[1].GetNumClipModels)(a1: v7, a2: 1);
          else
            v9[1].GetClipModel(this: v7, a2: 1);
        }
      }
    }
  }
}


// ========================================================================
// ?DamageFeedback@idActor@@UAAXPAVidEntity@@0PBVidDeclDamage@@AAM@Z
// EA  : 0x82BE5778
// RVA : 0x00BE5778
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::DamageFeedback(
        idActor *this,
        idEntity *victim,
        idEntity *inflictor,
        const idDeclDamage *damageDef,
        float *damage)
{
  idPresentable *presentable; // r3
  int v11; // r3
  double v12; // fp31
  idActorModifierManager *v13; // r3
  bool v14; // r8
  idPresentable *v15; // r3
  int v16; // r3
  double v17; // fp31
  idActorModifierManager *v18; // r3
  bool v19; // r8

  if ( common->IsMultiplayer(this: common) )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v11 = (int)presentable->GetActorInterface_2(this: presentable);
    if ( v11 != 0 )
    {
      v12 = *damage;
      v13 = (idActorModifierManager *)(*(int (__fastcall **)(int))(*(_DWORD *)v11 + 360))(a1: v11);
      idActorModifierManager::OnDamageDealt(
        this: v13,
        attacker: this,
        victim,
        inflictor,
        damageDecl: damageDef,
        damage: v12,
        isDead: v14);
    }
    if ( victim != nullptr )
    {
      v15 = victim->presentable;
      if ( v15 == nullptr )
      {
        idEntity::InitPresentableInternal(this: victim);
        v15 = victim->presentable;
      }
      v16 = (int)v15->GetActorInterface_2(this: v15);
      if ( v16 != 0 )
      {
        v17 = *damage;
        v18 = (idActorModifierManager *)(*(int (__fastcall **)(int))(*(_DWORD *)v16 + 360))(a1: v16);
        idActorModifierManager::OnDamageTaken(
          this: v18,
          attacker: this,
          victim,
          inflictor,
          damageDecl: damageDef,
          damage: v17,
          isDead: v19);
      }
    }
  }
}


// ========================================================================
// ?GetViewStateFOV@idActor@@UAAXAAVidVec3@@AAE1@Z
// EA  : 0x82BE5898
// RVA : 0x00BE5898
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::GetViewStateFOV(
        idActor *this,
        idVec3 *viewfwd,
        unsigned __int8 *horzFOV,
        unsigned __int8 *vertFOV)
{
  idAI2 *v8; // r31
  double v9; // fp13
  double v10; // fp12
  double fovDot; // fp1
  float v12[24]; // [sp+50h] [-60h] BYREF

  v8 = idAI2::CastTo(c: (idAI2 *)this);
  this->GetEyeAxis(this, a2: (idMat3 *)v12);
  v9 = v12[1];
  v10 = v12[2];
  viewfwd->x = v12[0];
  viewfwd->y = v9;
  viewfwd->z = v10;
  if ( v8 != nullptr )
    fovDot = v8->aiVolatile.perception.fovDot;
  else
    fovDot = 0.0;
  *horzFOV = idAIVisibility::FOVDotToByte(fov: fovDot);
  *vertFOV = 0;
}


// ========================================================================
// ?Event_SetPosture@idActor@@AAA?AVeventVoid@@W4posture_t@@@Z
// EA  : 0x82BE5920
// RVA : 0x00BE5920
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_SetPosture(idActor *this, eventVoid *result, posture_t posture)
{
  (*(void (__fastcall **)(eventVoid *, posture_t))(*(_DWORD *)result + 788))(a1: result, a2: posture);
  return this;
}


// ========================================================================
// ?Event_NeedsHealth@idActor@@ABA?AVeventBool@@XZ
// EA  : 0x82BE5968
// RVA : 0x00BE5968
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_NeedsHealth(idActor *this, eventBool *result)
{
  int v3; // r3
  int v4; // r31
  double v5; // fp31
  double v6; // fp1
  bool v7; // r4

  v3 = (*(int (__fastcall **)(eventBool *))(*(_DWORD *)&result->value + 388))(a1: result);
  v4 = v3;
  if ( v3 == 0
    || (v5 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v3 + 60))(a1: v3),
        v6 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v4 + 64))(a1: v4),
        v7 = true,
        v5 >= v6) )
  {
    v7 = false;
  }
  eventBool::eventBool((eventBool *)this, b: v7);
  return this;
}


// ========================================================================
// ?Event_IncreaseHealth@idActor@@AAA?AVeventVoid@@M@Z
// EA  : 0x82BE5A08
// RVA : 0x00BE5A08
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_IncreaseHealth(idActor *this, eventVoid *result, double amt)
{
  int v5; // r3

  v5 = (*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 392))(a1: result);
  if ( v5 != 0 )
    (*(void (__fastcall **)(int, double))(*(_DWORD *)v5 + 12))(a1: v5, a2: amt);
  return this;
}


// ========================================================================
// ?Event_DecreaseHealth@idActor@@AAA?AVeventVoid@@M@Z
// EA  : 0x82BE5A70
// RVA : 0x00BE5A70
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_DecreaseHealth(
        idActor *this,
        eventVoid *result,
        double amt,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        float a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17,
        float a18)
{
  int v19; // r4
  int v20; // r3

  a18 = amt;
  v20 = (*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 392))(a1: result);
  if ( v20 != 0 )
    (*(void (__fastcall **)(int, int, int, float *, double))(*(_DWORD *)v20 + 8))(
      a1: v20,
      a2: v19,
      a3: 1,
      a4: &a18,
      a5: a18);
  return this;
}


// ========================================================================
// ?Event_SetHealth@idActor@@AAA?AVeventVoid@@M@Z
// EA  : 0x82BE5AD8
// RVA : 0x00BE5AD8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_SetHealth(idActor *this, eventVoid *result, double health)
{
  int v5; // r3
  int v6; // r31

  v5 = (*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 392))(a1: result);
  v6 = v5;
  if ( v5 != 0 && health > 0.0 )
  {
    (*(void (__fastcall **)(int))(*(_DWORD *)v5 + 104))(a1: v5);
    (*(void (__fastcall **)(int, _DWORD, double))(*(_DWORD *)v6 + 44))(a1: v6, a2: 0, a3: health);
  }
  return this;
}


// ========================================================================
// ?Event_EnableWalkIK@idActor@@AAA?AVeventVoid@@XZ
// EA  : 0x82BE5B78
// RVA : 0x00BE5B78
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_EnableWalkIK(idActor *this, eventVoid *result)
{
  idAnimator_WalkIK::EnableAll(this: (idAnimator_WalkIK *)&result[7648]);
  return this;
}


// ========================================================================
// ?Event_DisableWalkIK@idActor@@AAA?AVeventVoid@@XZ
// EA  : 0x82BE5BB0
// RVA : 0x00BE5BB0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_DisableWalkIK(idActor *this, eventVoid *result)
{
  idAnimator_WalkIK::DisableAll(this: (idAnimator_WalkIK *)&result[7648]);
  return this;
}


// ========================================================================
// ?Event_EnableLegIK@idActor@@AAA?AVeventVoid@@H@Z
// EA  : 0x82BE5BE8
// RVA : 0x00BE5BE8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_EnableLegIK(idActor *this, eventVoid *result, char num)
{
  idAnimator_WalkIK::EnableLeg(this: (idAnimator_WalkIK *)&result[7648], num);
  return this;
}


// ========================================================================
// ?Event_DisableLegIK@idActor@@AAA?AVeventVoid@@H@Z
// EA  : 0x82BE5C28
// RVA : 0x00BE5C28
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_DisableLegIK(idActor *this, eventVoid *result, char num)
{
  idAnimator_WalkIK::DisableLeg(this: (idAnimator_WalkIK *)&result[7648], num);
  return this;
}


// ========================================================================
// ?Event_RemoveAllInventoryItems@idActor@@AAA?AVeventVoid@@XZ
// EA  : 0x82BE5C68
// RVA : 0x00BE5C68
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_RemoveAllInventoryItems(idActor *this, idEntity *result)
{
  eventVoid *p_z; // r30
  int i; // r29
  idPresentable *presentable; // r30
  idInventoryCollection *v7; // r3

  p_z = (eventVoid *)&result[11].defaultPhysicsObj.current.worldAxis.mat[0].z;
  for ( i = 15; i != 0; --i )
  {
    if ( *(_DWORD *)p_z != 0 )
      ((void (__fastcall *)(idEntity *))result->__vftable[1].SetModelByName)(a1: result);
    p_z += 4;
  }
  presentable = result->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  v7 = result->GetInventory_2(this: result);
  idInventoryCollection::FreeInventory(this: v7, owner: presentable);
  return this;
}


// ========================================================================
// ?Event_HideAttachment@idActor@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82BE5CF0
// RVA : 0x00BE5CF0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_HideAttachment(idActor *this, eventVoid *result, const char *slotName)
{
  int v5; // r4
  idInventoryItem *v7; // r3
  idInventoryItem *v8; // r30
  idHandle<int,enum invalidAttachment_t,-1> *v9; // r31
  idAttachmentCollection v10[2]; // [sp+50h] [-30h] BYREF

  v5 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( (((v5 >= 0) + ((unsigned int)v5 >= 0xF)) & 1) != 0 )
  {
    v7 = (idInventoryItem *)(*(int (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 740))(a1: result, a2: v5);
    v8 = v7;
    if ( v7 != nullptr )
    {
      v9 = (idHandle<int,enum invalidAttachment_t,-1> *)&result[9456];
      idAttachmentCollection::FindAttachment(this: v10, result: v9, item: v7);
      if ( v10[0].attachments.list == (idAttachment *)-1 )
        idLib::Warning(fmt: "Event_HideAttachment - no attachment for item '%s'.", v8->decl->internalName.data);
      else
        idAttachmentCollection::HideAttachment(
          this: (idAttachmentCollection *)v9,
          handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v10,
          ignoreShowAll: false);
      return this;
    }
    else
    {
      idLib::Warning(fmt: "Event_HideAttachment - Tried to hide an item in an empty slot.");
      return this;
    }
  }
  else
  {
    idLib::Warning(fmt: "Event_HideAttachment - Invalid equip slot", v5);
    return this;
  }
}


// ========================================================================
// ?Event_ShowAttachment@idActor@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82BE5DE0
// RVA : 0x00BE5DE0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_ShowAttachment(idActor *this, eventVoid *result, const char *slotName)
{
  int v5; // r4
  idInventoryItem *v7; // r3
  idInventoryItem *v8; // r30
  idHandle<int,enum invalidAttachment_t,-1> *v9; // r31
  idAttachmentCollection v10[2]; // [sp+50h] [-30h] BYREF

  v5 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( (((v5 >= 0) + ((unsigned int)v5 >= 0xF)) & 1) != 0 )
  {
    v7 = (idInventoryItem *)(*(int (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 740))(a1: result, a2: v5);
    v8 = v7;
    if ( v7 != nullptr )
    {
      v9 = (idHandle<int,enum invalidAttachment_t,-1> *)&result[9456];
      idAttachmentCollection::FindAttachment(this: v10, result: v9, item: v7);
      if ( v10[0].attachments.list == (idAttachment *)-1 )
        idLib::Warning(fmt: "Event_ShowAttachment - no attachment for index '%s'.", v8->decl->internalName.data);
      else
        idAttachmentCollection::ShowAttachment(
          this: (idAttachmentCollection *)v9,
          handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v10);
      return this;
    }
    else
    {
      idLib::Warning(fmt: "Event_ShowAttachment - Tried to show an item in an empty slot.");
      return this;
    }
  }
  else
  {
    idLib::Warning(fmt: "Event_ShowAttachment - Invalid equip slot", v5);
    return this;
  }
}


// ========================================================================
// ?Event_RemoveAttachment@idActor@@AAA?AVeventVoid@@PBVidEntity@@@Z
// EA  : 0x82BE5EC8
// RVA : 0x00BE5EC8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_RemoveAttachment(idActor *this, eventVoid *result, const idEntity *entity)
{
  idAttachmentCollection::RemoveAttachment(this: (idAttachmentCollection *)&result[9456], ent: entity);
  return this;
}


// ========================================================================
// ?Event_WeaponBurstMode@idActor@@ABA?AVeventFloat@@H@Z
// EA  : 0x82BE5F08
// RVA : 0x00BE5F08
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_WeaponBurstMode(idActor *this, eventFloat *result, const int slot)
{
  __int64 v4; // r11
  idWeapon *v5; // r3
  idAmmoItem *ammoClip; // r11
  double v7; // fp1

  v5 = idWeapon::CastTo(c: (idWeapon *)LODWORD(result[slot + 2349].value));
  if ( v5 != nullptr )
  {
    ammoClip = v5->ammoClip;
    if ( ammoClip != nullptr )
      LODWORD(v4) = ammoClip->burstMode;
    else
      LODWORD(v4) = v5->decl[1].attachmentInfo.num;
    v7 = (float)v4;
  }
  else
  {
    v7 = 3.0;
  }
  eventFloat::eventFloat((eventFloat *)this, f: v7);
  return this;
}


// ========================================================================
// ?AnimEvent_StartRagdoll@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@HHH@Z
// EA  : 0x82BE5F90
// RVA : 0x00BE5F90
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_StartRagdoll(
        idActor *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const int velocityTime,
        unsigned int slomoStartTime,
        unsigned int slomoEndTime)
{
  char *v6; // r10
  int v11; // ctr
  eventVoid *v12; // r11
  int v13; // r3
  __int64 v14; // r7
  void (__fastcall *v15)(eventVoid *, float *); // ctr
  char v17; // [sp+5Ch] [-54h] BYREF
  float v18[20]; // [sp+60h] [-50h] BYREF

  v6 = &v17;
  v11 = 9;
  v12 = result + 7088;
  do
  {
    v12 += 4;
    v6 += 4;
    *(_DWORD *)v6 = *(_DWORD *)v12;
    --v11;
  }
  while ( v11 != 0 );
  v13 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  LODWORD(v14) = slomoStartTime;
  LODWORD(v18[0]) = v13;
  HIDWORD(v14) = *(_DWORD *)result;
  v15 = *(void (__fastcall **)(eventVoid *, float *))(*(_DWORD *)result + 692);
  v18[2] = (float)__SPAIR64__(slomoStartTime, slomoEndTime);
  v18[1] = (float)v14;
  v15(a1: result, a2: v18);
  return this;
}


// ========================================================================
// ?AnimEvent_HideAttachment@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82BE6040
// RVA : 0x00BE6040
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_HideAttachment(
        idActor *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *slotName)
{
  int v6; // r4
  idInventoryItem *v8; // r3
  idInventoryItem *v9; // r30
  idHandle<int,enum invalidAttachment_t,-1> *v10; // r31
  idAttachmentCollection v11[2]; // [sp+50h] [-30h] BYREF

  v6 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( (((v6 >= 0) + ((unsigned int)v6 >= 0xF)) & 1) != 0 )
  {
    v8 = (idInventoryItem *)(*(int (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 740))(a1: result, a2: v6);
    v9 = v8;
    if ( v8 != nullptr )
    {
      v10 = (idHandle<int,enum invalidAttachment_t,-1> *)&result[9456];
      idAttachmentCollection::FindAttachment(this: v11, result: v10, item: v8);
      if ( v11[0].attachments.list == (idAttachment *)-1 )
        idLib::Warning(fmt: "AnimEvent_HideAttachment - no attachment for item '%s'.", v9->decl->internalName.data);
      else
        idAttachmentCollection::HideAttachment(
          this: (idAttachmentCollection *)v10,
          handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v11,
          ignoreShowAll: false);
      return this;
    }
    else
    {
      idLib::Warning(fmt: "AnimEvent_HideAttachment - Tried to hide an item in an empty slot.");
      return this;
    }
  }
  else
  {
    idLib::Warning(fmt: "AnimEvent_HideAttachment - Invalid equip slot", v6);
    return this;
  }
}


// ========================================================================
// ?AnimEvent_ShowAttachment@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82BE6130
// RVA : 0x00BE6130
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_ShowAttachment(
        idActor *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *slotName)
{
  int v6; // r4
  idInventoryItem *v8; // r3
  idInventoryItem *v9; // r30
  idHandle<int,enum invalidAttachment_t,-1> *v10; // r31
  idAttachmentCollection v11[2]; // [sp+50h] [-30h] BYREF

  v6 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( (((v6 >= 0) + ((unsigned int)v6 >= 0xF)) & 1) != 0 )
  {
    v8 = (idInventoryItem *)(*(int (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 740))(a1: result, a2: v6);
    v9 = v8;
    if ( v8 != nullptr )
    {
      v10 = (idHandle<int,enum invalidAttachment_t,-1> *)&result[9456];
      idAttachmentCollection::FindAttachment(this: v11, result: v10, item: v8);
      if ( v11[0].attachments.list == (idAttachment *)-1 )
        idLib::Warning(fmt: "AnimEvent_ShowAttachment - no attachment for index '%s'.", v9->decl->internalName.data);
      else
        idAttachmentCollection::ShowAttachment(
          this: (idAttachmentCollection *)v10,
          handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v11);
      return this;
    }
    else
    {
      idLib::Warning(fmt: "AnimEvent_ShowAttachment - Tried to show an item in an empty slot.");
      return this;
    }
  }
  else
  {
    idLib::Warning(fmt: "AnimEvent_ShowAttachment - Invalid equip slot", v6);
    return this;
  }
}


// ========================================================================
// ?AnimEvent_DetachAttachment@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82BE6218
// RVA : 0x00BE6218
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_DetachAttachment(
        idActor *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *slotName)
{
  int v6; // r4
  idInventoryItem *v8; // r3
  idInventoryItem *v9; // r30
  idHandle<int,enum invalidAttachment_t,-1> *v10; // r31
  idAttachmentCollection v11[2]; // [sp+50h] [-30h] BYREF

  v6 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( (((v6 >= 0) + ((unsigned int)v6 >= 0xF)) & 1) != 0 )
  {
    v8 = (idInventoryItem *)(*(int (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 740))(a1: result, a2: v6);
    v9 = v8;
    if ( v8 != nullptr )
    {
      v10 = (idHandle<int,enum invalidAttachment_t,-1> *)&result[9456];
      idAttachmentCollection::FindAttachment(this: v11, result: v10, item: v8);
      if ( v11[0].attachments.list == (idAttachment *)-1 )
        idLib::Warning(fmt: "AnimEvent_ShowAttachment - no attachment for index '%s'.", v9->decl->internalName.data);
      else
        idAttachmentCollection::DetachAttachment(
          this: (idAttachmentCollection *)v10,
          handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v11);
      return this;
    }
    else
    {
      idLib::Warning(fmt: "AnimEvent_ShowAttachment - Tried to show an item in an empty slot.");
      return this;
    }
  }
  else
  {
    idLib::Warning(fmt: "AnimEvent_ShowAttachment - Invalid equip slot", v6);
    return this;
  }
}


// ========================================================================
// ?AnimEvent_ReattachAttachment@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82BE6300
// RVA : 0x00BE6300
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_ReattachAttachment(
        idActor *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *slotName)
{
  int v6; // r4
  idInventoryItem *v8; // r3
  idInventoryItem *v9; // r30
  idHandle<int,enum invalidAttachment_t,-1> *v10; // r31
  idAttachmentCollection v11[2]; // [sp+50h] [-30h] BYREF

  v6 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( (((v6 >= 0) + ((unsigned int)v6 >= 0xF)) & 1) != 0 )
  {
    v8 = (idInventoryItem *)(*(int (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 740))(a1: result, a2: v6);
    v9 = v8;
    if ( v8 != nullptr )
    {
      v10 = (idHandle<int,enum invalidAttachment_t,-1> *)&result[9456];
      idAttachmentCollection::FindAttachment(this: v11, result: v10, item: v8);
      if ( v11[0].attachments.list == (idAttachment *)-1 )
        idLib::Warning(fmt: "AnimEvent_ShowAttachment - no attachment for index '%s'.", v9->decl->internalName.data);
      else
        idAttachmentCollection::ReattachAttachment(
          this: (idAttachmentCollection *)v10,
          handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v11);
      return this;
    }
    else
    {
      idLib::Warning(fmt: "AnimEvent_ShowAttachment - Tried to show an item in an empty slot.");
      return this;
    }
  }
  else
  {
    idLib::Warning(fmt: "AnimEvent_ShowAttachment - Invalid equip slot", v6);
    return this;
  }
}


// ========================================================================
// ?AnimEvent_HideModel@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclMD6@@@Z
// EA  : 0x82BE63E8
// RVA : 0x00BE63E8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_HideModel(
        idActor *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const idDeclMD6 *model)
{
  if ( model != nullptr )
    idAttachmentCollection::RemoveAttachment(this: (idAttachmentCollection *)&result[9456], modelName: model->name.str);
  return this;
}


// ========================================================================
// ?AnimEvent_ShowModel@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclMD6@@PBD@Z
// EA  : 0x82BE6428
// RVA : 0x00BE6428
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_ShowModel(
        idActor *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const idDeclMD6 *model,
        const char *tag)
{
  idAttachmentCollection v7; // [sp+50h] [-20h] BYREF

  if ( model != nullptr )
    idAttachmentCollection::AddAttachment(
      this: &v7,
      result: (idHandle<int,enum invalidAttachment_t,-1> *)&result[9456],
      modelName: model->name.str,
      propName: nullptr,
      tag,
      tagInfo: nullptr,
      allowDuplicate: false);
  return this;
}


// ========================================================================
// ?AnimEvent_AttachEntity@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD1@Z
// EA  : 0x82BE6478
// RVA : 0x00BE6478
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_AttachEntity(
        idActor *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *entityName,
        const char *tagName)
{
  idEntity *v8; // r5
  idAttachmentCollection v10[2]; // [sp+50h] [-30h] BYREF

  v8 = gameLocal->FindEntity(this: gameLocal, a2: entityName);
  if ( v8 != nullptr )
    idAttachmentCollection::AddAttachment(
      this: v10,
      result: (idHandle<int,enum invalidAttachment_t,-1> *)&result[9456],
      ent: v8,
      tag: tagName);
  return this;
}


// ========================================================================
// ?AnimEvent_DetachEntity@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82BE64D8
// RVA : 0x00BE64D8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_DetachEntity(
        idActor *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *entityName)
{
  const idEntity *v6; // r4

  v6 = (const idEntity *)((int (__fastcall *)(idGameLocal *, const char *, const idMD6Anim *))gameLocal->FindEntity)(
                           a1: gameLocal,
                           a2: entityName,
                           a3: animHandle);
  if ( v6 != nullptr )
    idAttachmentCollection::RemoveAttachment(this: (idAttachmentCollection *)&result[9456], ent: v6);
  return this;
}


// ========================================================================
// ?AnimEvent_DisableTwoLegIKBlend@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BE6540
// RVA : 0x00BE6540
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_DisableTwoLegIKBlend(
        idActor *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  idAnimator_WalkIK *v3; // r31
  int GameMs; // r28
  const idAnimStack *v7; // r3

  v3 = (idAnimator_WalkIK *)&result[7648];
  idAnimator_WalkIK::DisableLeg(this: (idAnimator_WalkIK *)&result[7648], num: 0);
  idAnimator_WalkIK::DisableLeg(this: v3, num: 1);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v7 = (const idAnimStack *)(*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 184))(a1: result);
  idAnimator_Base::End(this: v3, stack: v7, curTime: GameMs, blendDurationMS: 0, reset: false);
  return this;
}


// ========================================================================
// ?AnimEvent_EnableTwoLegIKBlend@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BE65C8
// RVA : 0x00BE65C8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_EnableTwoLegIKBlend(
        idActor *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  idAnimator_WalkIK *v3; // r31
  int valueInteger; // r29
  int GameMs; // r27
  const idAnimStack *v8; // r3

  v3 = (idAnimator_WalkIK *)&result[7648];
  idAnimator_WalkIK::EnableLeg(this: (idAnimator_WalkIK *)&result[7648], num: 0);
  idAnimator_WalkIK::EnableLeg(this: v3, num: 1);
  valueInteger = pm_walkIKBlendInMS.valueInteger;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v8 = (const idAnimStack *)(*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 184))(a1: result);
  idAnimator_Base::Blend(
    this: v3,
    stack: v8,
    curTime: GameMs,
    targetAlpha: 1.0,
    blendDurationMS: 0x82000000,
    reset: valueInteger,
    a7: 0);
  return this;
}


// ========================================================================
// ?AnimEvent_ModifyDamageGroupScale@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@PBDM@Z
// EA  : 0x82BE6660
// RVA : 0x00BE6660
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_ModifyDamageGroupScale(
        idActor *this,
        idActor *result,
        const idMD6Anim *animHandle,
        const char *damageGroupName,
        double scale)
{
  idDamageGroup *DamageGroup; // r3

  DamageGroup = idActor::GetDamageGroup(this: result, name: damageGroupName);
  if ( DamageGroup != nullptr )
    DamageGroup->damageScale = scale;
  return this;
}


// ========================================================================
// ?SetModel@idActor@@UAAXPAVidRenderModel@@@Z
// EA  : 0x82BE66B0
// RVA : 0x00BE66B0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::SetModel(idActor *this, idRenderModel *model)
{
  idAnimator_AF *v3; // r3
  idVec3 *p_gravity; // r29
  int entityNumber; // r28
  idSoundEmitter *SoundEmitter; // r27
  idClip *p_clip; // r25
  idAnimStack *v8; // r24
  idAnimator_AF *v9; // r3
  idPhysicsCallbacks *v10; // [sp+8h] [-98h]
  int v11; // [sp+Ch] [-94h]
  int v12; // [sp+10h] [-90h]
  int v13; // [sp+14h] [-8Ch]
  int v14; // [sp+18h] [-88h]
  int v15; // [sp+1Ch] [-84h]
  int v16; // [sp+20h] [-80h]
  int v17; // [sp+24h] [-7Ch]
  int v18; // [sp+28h] [-78h]
  int v19; // [sp+2Ch] [-74h]
  int v20; // [sp+30h] [-70h]
  int v21; // [sp+34h] [-6Ch]
  int v22; // [sp+38h] [-68h]
  int v23; // [sp+3Ch] [-64h]
  int v24; // [sp+40h] [-60h]
  int v25; // [sp+44h] [-5Ch]
  int v26; // [sp+48h] [-58h]
  int v27; // [sp+4Ch] [-54h]
  int v28; // [sp+50h] [-50h]

  idAnimatedEntity::SetModel(this, model);
  v3 = this->GetAF_2(this);
  idAnimator_AF::Shutdown(this: v3);
  p_gravity = &gameLocal->clientGame.gravity;
  entityNumber = this->entityNumber;
  SoundEmitter = idEntity::GetSoundEmitter(this, alloc: true);
  p_clip = &clientGame->clip;
  v8 = this->GetAnimStack_2(this);
  v9 = this->GetAF_2(this);
  idAnimator_AF::InitAF(
    this: v9,
    animStack: v8,
    clip: p_clip,
    impactManager: &this->impactManager,
    soundEmitter: SoundEmitter,
    soundChannel: SND_CHANNEL_BODY3,
    gravityVector: p_gravity,
    entityNumber,
    callback: v10,
    a10: v11,
    a11: v12,
    a12: v13,
    a13: v14,
    a14: v15,
    a15: v16,
    a16: v17,
    a17: v18,
    a18: v19,
    a19: v20,
    a20: v21,
    a21: v22,
    a22: v23,
    a23: v24,
    a24: v25,
    a25: v26,
    a26: v27,
    a27: v28,
    a28: &this->defaultPhysicsCallbacks);
}


// ========================================================================
// ?GetDamageForJoint@idActor@@QAAMV?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82BE6770
// RVA : 0x00BE6770
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

float __fastcall idActor::GetDamageForJoint(idActor *this, const idIndex<short,enum invalidJointIndex_t> *joint)
{
  idDamageGroup *DamageGroup; // r3
  double damageScale; // fp1

  DamageGroup = idActor::GetDamageGroup(this, joint);
  if ( DamageGroup != nullptr )
  {
    if ( DamageGroup->locationArmor <= 0.0 )
      damageScale = DamageGroup->damageScale;
    else
      damageScale = DamageGroup->armoredDamageScale;
  }
  else
  {
    damageScale = 1.0;
  }
  return *((float *)&damageScale + 1);
}


// ========================================================================
// ?GetAttachedLoot@idActor@@QBAPAVidEntity@@XZ
// EA  : 0x82BE67E0
// RVA : 0x00BE67E0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idEntity *__fastcall idActor::GetAttachedLoot(idActor *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->attachedLoot.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?Event_GiveInventoryItem@idActor@@AAA?AVeventVoid@@PBDM@Z
// EA  : 0x82BE6828
// RVA : 0x00BE6828
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_GiveInventoryItem(
        idActor *this,
        idEntity *result,
        const char *declName,
        double count)
{
  const idDeclInventory *v7; // r29
  idPresentable *presentable; // r30
  idInventoryCollection *v9; // r3

  if ( declName != nullptr )
  {
    v7 = (const idDeclInventory *)idDeclInfo::FindWithInheritance(
                                    this: &idDeclInventory::resourceList,
                                    name: declName,
                                    makeDefault: false);
    if ( v7 != nullptr )
    {
      presentable = result->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: result);
        presentable = result->presentable;
      }
      v9 = result->GetInventory_2(this: result);
      idInventoryCollection::GiveItem(
        this: v9,
        owner: presentable,
        decl: v7,
        (int)count,
        forceCount: false,
        canIntro: false);
    }
  }
  return this;
}


// ========================================================================
// ?Event_RemoveInventoryItem@idActor@@AAA?AVeventVoid@@PBDM@Z
// EA  : 0x82BE68C8
// RVA : 0x00BE68C8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::Event_RemoveInventoryItem(
        idActor *this,
        idEntity *result,
        const char *declName,
        double count)
{
  const idDeclJob *v7; // r30
  idJobManager *v8; // r3
  idInventoryItem *JobByDecl; // r29
  idPresentable *presentable; // r30
  idInventoryCollection *v11; // r3

  if ( declName != nullptr )
  {
    v7 = (const idDeclJob *)idDeclInfo::FindWithInheritance(
                              this: &idDeclInventory::resourceList,
                              name: declName,
                              makeDefault: false);
    if ( v7 != nullptr )
    {
      v8 = (idJobManager *)result->GetInventory_2(this: result);
      JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v8, jobDecl: v7);
      if ( JobByDecl != nullptr )
      {
        presentable = result->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this: result);
          presentable = result->presentable;
        }
        v11 = result->GetInventory_2(this: result);
        idInventoryCollection::DeleteInventoryItem(this: v11, owner: presentable, item: JobByDecl, (int)count);
      }
    }
  }
  return this;
}


// ========================================================================
// ?Crush@idActorPhysicsCallbacks@@UAA_NH@Z
// EA  : 0x82BE6988
// RVA : 0x00BE6988
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

int __fastcall idActorPhysicsCallbacks::Crush(idActorPhysicsCallbacks *this, int physId)
{
  idPhysics *PhysicsForId; // r3
  idGameLocal *v4; // r11
  idEntity *v5; // r30
  int value; // r9
  idEntity *v7; // r3
  idEntity *v8; // r3

  if ( gameLocal->damageCrush == nullptr )
    return 0;
  PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: physId);
  if ( PhysicsForId != nullptr )
  {
    v4 = gameLocal;
    v5 = gameLocal->entities.ptr[PhysicsForId->entityNumber];
    if ( v5 != nullptr )
    {
      value = this->ent.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = idEntity::CastTo(c: v7);
        v4 = gameLocal;
      }
      else
      {
        v8 = nullptr;
      }
      ((void (__fastcall *)(idEntity *, idEntity *, idEntity *, const idDeclDamage *, double))v8->Damage)(
        a1: v8,
        a2: v5,
        a3: v5,
        a4: v4->damageGib,
        a5: 1.0);
    }
  }
  return 1;
}


// ========================================================================
// ?DeleteSubEntities@idActor@@UAAXXZ
// EA  : 0x82BE6A78
// RVA : 0x00BE6A78
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::DeleteSubEntities(idActor *this)
{
  int v2; // r29
  idAttachmentCollection *p_attachments; // r27
  idAttachment *v4; // r3
  idAttachment *v5; // r31
  int value; // r9
  idEntity *v7; // r3
  int v8; // r9
  idGameLocal *v9; // r11
  idEntity *v10; // r3
  idEntity *v11; // r3
  idEntity *v12; // r4

  v2 = 0;
  if ( this->attachments.attachments.num > 0 )
  {
    p_attachments = &this->attachments;
    do
    {
      v4 = idAttachmentCollection::ForIndex(this: p_attachments, index: v2);
      v5 = v4;
      if ( v4 != nullptr )
      {
        value = v4->entity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v7 = gameLocal->entities.ptr[value & 0x1FFF];
          if ( v7 != nullptr && idEntity::CastTo(c: v7) != nullptr )
          {
            v8 = v5->entity.spawnId.value;
            v9 = gameLocal;
            if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13
              && (v10 = gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
            {
              v11 = idEntity::CastTo(c: v10);
              v9 = gameLocal;
              v12 = v11;
            }
            else
            {
              v12 = nullptr;
            }
            v9->DeleteEntity(this: v9, a2: v12);
          }
        }
      }
      ++v2;
    }
    while ( v2 < this->attachments.attachments.num );
  }
}


// ========================================================================
// ?DropItem@idActor@@UAAPAVidEntity@@PAVidInventoryItem@@_N1HABVidVec3@@2@Z
// EA  : 0x82BE6B78
// RVA : 0x00BE6B78
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idVehicle_Car *__fastcall idActor::DropItem(
        idActor *this,
        idInventoryItem *item,
        bool dropToGround,
        bool deleteOnDrop,
        int count,
        const idVec3 *offset,
        const idVec3 *velocity)
{
  const idDeclInventory *decl; // r11
  idVehicle_Car *v12; // r28
  idPhysics *Physics; // r3
  int v14; // r25
  double v19; // fp30
  char v20; // r18
  idVehicle_Car *v21; // r19
  double v22; // fp9
  double v23; // fp1
  idAI2 *v24; // r3
  idAI2 *v25; // r29
  idAIOrientation *BodyOrientation; // r3
  double v27; // fp31
  double v28; // fp30
  double v29; // fp29
  idPhysics *v30; // r3
  float *v31; // r3
  double v32; // fp2
  double v33; // fp1
  idLinkList<idActor> *next; // r11
  idAI2 *owner; // r31
  idAI2 *v36; // r30
  idPhysics *v37; // r3
  float *v38; // r15
  idPhysics *v39; // r3
  float *v40; // r3
  double v41; // fp10
  double v42; // fp8
  idLinkList<idActor> *v43; // r11
  idPhysics *v44; // r3
  const idDeclPlayerProps::playerSounds_t *v45; // r26
  char v46; // r31
  idPhysics *v47; // r30
  idPhysics *v48; // r15
  int entityNumber; // r14
  int v50; // r30
  const idMat3 *v51; // r3
  idPhysics *v52; // r30
  idPhysics *v53; // r15
  int v54; // r14
  int v55; // r30
  idMat3 *v56; // r3
  int v57; // r4
  idPhysics *v58; // r30
  idPhysics *v59; // r15
  int v60; // r14
  int v61; // r30
  idMat3 *v62; // r3
  idEntity *v63; // r3
  int v64; // r3
  idPhysics *PhysicsForId; // r3
  unsigned __int8 v66; // r30
  idPresentable *presentable; // r31
  const idDeclPlayerProps::playerSounds_t *PlayerSounds; // r3
  idRenderWorld *v69; // r3
  idRenderWorld *v70; // r3
  const idSoundShader *sndDeath; // r3
  const idDeclInventory *v73; // r31
  idPresentablePlayer *v74; // r3
  const idSoundShader *v75; // r3
  int v76; // r3
  idProp_Moveable *v77; // r3
  const idDeclInventory *v78; // r11
  idPhysics *v79; // r3
  const idSoundShader *dropSound; // r5
  idPhysics *v81; // r31
  int GameMs; // r30
  idPhysics *v83; // r3
  const idDeclInventory *v84; // r29
  idAIEventManager *p_aiEventManager; // r31
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v87; // r3
  idPresentable *v88; // r31
  idInventoryCollection *v89; // r3
  const char *v90; // [sp+8h] [-378h]
  int v91; // [sp+8h] [-378h]
  int v92; // [sp+8h] [-378h]
  int v93; // [sp+Ch] [-374h]
  bool v94; // [sp+Fh] [-371h]
  bool v95; // [sp+Fh] [-371h]
  int v96; // [sp+10h] [-370h]
  const char *v97; // [sp+10h] [-370h]
  const char *v98; // [sp+10h] [-370h]
  int v99; // [sp+14h] [-36Ch]
  int v100; // [sp+14h] [-36Ch]
  int v101; // [sp+14h] [-36Ch]
  int v102; // [sp+18h] [-368h]
  int v103; // [sp+18h] [-368h]
  int v104; // [sp+18h] [-368h]
  int v105; // [sp+1Ch] [-364h]
  int v106; // [sp+1Ch] [-364h]
  int v107; // [sp+1Ch] [-364h]
  int v108; // [sp+20h] [-360h]
  int v109; // [sp+20h] [-360h]
  int v110; // [sp+20h] [-360h]
  int v111; // [sp+24h] [-35Ch]
  int v112; // [sp+24h] [-35Ch]
  int v113; // [sp+24h] [-35Ch]
  int v114; // [sp+28h] [-358h]
  int v115; // [sp+28h] [-358h]
  int v116; // [sp+28h] [-358h]
  int v117; // [sp+2Ch] [-354h]
  int v118; // [sp+2Ch] [-354h]
  int v119; // [sp+2Ch] [-354h]
  int v120; // [sp+30h] [-350h]
  int v121; // [sp+30h] [-350h]
  int v122; // [sp+30h] [-350h]
  int v123; // [sp+34h] [-34Ch]
  int v124; // [sp+34h] [-34Ch]
  int v125; // [sp+34h] [-34Ch]
  int v126; // [sp+38h] [-348h]
  int v127; // [sp+38h] [-348h]
  int v128; // [sp+38h] [-348h]
  int v129; // [sp+3Ch] [-344h]
  int v130; // [sp+3Ch] [-344h]
  int v131; // [sp+3Ch] [-344h]
  int v132; // [sp+40h] [-340h]
  int v133; // [sp+40h] [-340h]
  int v134; // [sp+40h] [-340h]
  int v135; // [sp+44h] [-33Ch]
  int v136; // [sp+44h] [-33Ch]
  int v137; // [sp+44h] [-33Ch]
  int v138; // [sp+48h] [-338h]
  int v139; // [sp+48h] [-338h]
  int v140; // [sp+48h] [-338h]
  int v141; // [sp+4Ch] [-334h]
  int v142; // [sp+4Ch] [-334h]
  int v143; // [sp+4Ch] [-334h]
  int v144; // [sp+50h] [-330h]
  int v145; // [sp+50h] [-330h]
  int v146; // [sp+50h] [-330h]
  int v147; // [sp+58h] [-328h]
  int v148; // [sp+58h] [-328h]
  int v149; // [sp+60h] [-320h]
  int v150; // [sp+60h] [-320h]
  idVec3 v151; // [sp+70h] [-310h] BYREF
  idVec3 v152; // [sp+80h] [-300h] BYREF
  idAIEventManager v153; // [sp+90h] [-2F0h] BYREF
  trace_t v154; // [sp+100h] [-280h] BYREF
  trace_t v155; // [sp+180h] [-200h] BYREF
  char v156; // [sp+200h] [-180h] BYREF

  if ( item == nullptr )
    return nullptr;
  decl = item->decl;
  if ( !decl->dropable )
    return nullptr;
  v12 = nullptr;
  if ( !dropToGround )
    goto LABEL_62;
  v12 = (idVehicle_Car *)gameLocal->SpawnEntityFromDef(this: gameLocal, a2: decl->entityDef, a3: -1, a4: -1, a5: -1);
  if ( v12 == nullptr )
    return nullptr;
  this->GetViewTransform(this, a2: (idVec3 *)&v153.eventList.size, a3: (idMat3 *)&v153.eventPools);
  Physics = idEntity::GetPhysics(this: v12);
  v14 = (int)Physics->GetClipModel(this: Physics, a2: 0);
  _FP6 = (float)((float)__fabs(*(float *)(v14 + 80)) - (float)__fabs(*(float *)(v14 + 92)));
  _FP5 = (float)((float)__fabs(*(float *)(v14 + 84)) - (float)__fabs(*(float *)(v14 + 96)));
  __asm
  {
    fsel      f0, f6, f10, f12
    fsel      f13, f5, f7, f8
  }
  if ( _FP0 <= _FP13 )
    v19 = (float)((float)_FP13 * (float)_FP13);
  else
    v19 = (float)((float)_FP0 * (float)_FP0);
  v20 = 0;
  v21 = idVehicle_Car::CastTo(c: v12);
  LODWORD(v151.x) = v153.eventPools.list;
  v151.z = 0.0;
  LODWORD(v151.y) = v153.eventPools.num;
  idVec3::NormalizeFast(this: &v151);
  v22 = __fsqrts((float)((float)v19 * (float)2.0));
  v151.x = (float)(v151.x * (float)((float)v22 + (float)12.0)) + *(float *)&v153.eventList.size;
  v151.z = *(float *)&v153.eventHash.hash + (float)((float)((float)((float)v22 + (float)12.0) * v151.z) - (float)35.0);
  v151.y = *(float *)&v153.eventList.granularity + (float)(v151.y * (float)((float)v22 + (float)12.0));
  v23 = idMat3::ToYaw(this: (idMat3 *)&v153.eventPools);
  *(float *)&v153.eventHash.hashSize = 0.0;
  *(float *)&v153.eventHash.granularity = 0.0;
  *(float *)&v153.eventHash.indexSize = v23;
  idEntity::SetAngles(this: v12, ang: (const idAngles *)&v153.eventHash.hashSize);
  v24 = idAI2::CastTo(c: (idAI2 *)v12);
  v25 = v24;
  if ( v24 != nullptr )
  {
    BodyOrientation = idAI2::GetBodyOrientation(this: v24);
    idAIOrientation::SetIdealDir(this: BodyOrientation, ai: v25, dir: (const idVec3 *)&v153.eventPools);
    v25->GetEyeOffset(this: (struct idAI2 *)&v152, result: (const idVec3 *)v25);
    v27 = (float)(v25->actorVolatile.modelInfo.modelAxis.mat[0].x
                * (float)((float)(UNITS_PER_INCH_14 * (float)20.0) * (float)12.0));
    v29 = (float)(v25->actorVolatile.modelInfo.modelAxis.mat[0].z
                * (float)((float)(UNITS_PER_INCH_14 * (float)20.0) * (float)12.0));
    v28 = (float)(v25->actorVolatile.modelInfo.modelAxis.mat[0].y
                * (float)((float)(UNITS_PER_INCH_14 * (float)20.0) * (float)12.0));
    v30 = idEntity::GetPhysics(this: v25);
    v31 = (float *)v30->GetOrigin(this: v30, a2: 0);
    v32 = (float)(v31[1] + (float)v28);
    v33 = (float)(v31[2] + (float)v29);
    v152.x = (float)((float)v27 + *v31) + v152.x;
    v152.y = v152.y + (float)v32;
    v152.z = v152.z + (float)v33;
    idFocusInfo::SetExplicitFocusPoint(
      this: v25->aiVolatile.focus.foci.ptr,
      owner: v25,
      focusPoint: &v152,
      _keepFocusInView: true,
      duration: -1,
      _focusType: AIFOCUS_LAST_SENSED_POS);
    next = gameLocal->actorEntities.next;
    if ( next != nullptr && next != gameLocal->actorEntities.head )
    {
      owner = (idAI2 *)next->owner;
      while ( owner != nullptr )
      {
        if ( owner != v25 && owner != this && !owner->IsDead(this: owner) )
        {
          v36 = idAI2::CastTo(c: owner);
          if ( v36 != nullptr )
          {
            v37 = idEntity::GetPhysics(this);
            v38 = (float *)v37->GetOrigin(this: v37, a2: 0);
            v39 = idEntity::GetPhysics(this: v36);
            v40 = (float *)v39->GetOrigin(this: v39, a2: 0);
            v41 = (float)(v40[1] - v38[1]);
            v42 = (float)(v40[2] - v38[2]);
            if ( (float)((float)((float)(*v40 - *v38) * (float)(*v40 - *v38))
                       + (float)((float)((float)v42 * (float)v42) + (float)((float)v41 * (float)v41))) < 1048576.0
              && idAIMemory::GetEnemy(this: &v36->aiVolatile.memory) == this )
            {
              idAI2::GiveAwarenessOfEntity(this: v25, ent: owner, alertCycle: ALERTCYCLE_COMBAT);
            }
          }
        }
        v43 = owner->actorNode.next;
        if ( v43 == nullptr || v43 == owner->actorNode.head )
          owner = nullptr;
        else
          owner = (idAI2 *)v43->owner;
      }
    }
  }
  v44 = idEntity::GetPhysics(this: v12);
  v44->UnlinkClip(this: v44);
  v45 = (const idDeclPlayerProps::playerSounds_t *)idPlayer::CastTo(c: (idPlayer *)this);
  if ( v45 != nullptr )
  {
    v46 = 0;
    v47 = idEntity::GetPhysics(this: v12);
    v48 = idEntity::GetPhysics(this: v12);
    entityNumber = this->entityNumber;
    v50 = v47->GetClipMask(this: v47, a2: -1) | 0x420;
    v51 = v48->GetAxis(this: v48, a2: 0);
    idClip::Contents(
      this: (idClip *)&v153,
      result: &clientGame->clip,
      a3: &v155,
      start: &v151,
      clipModel: (const idClipModel *)v14,
      startAxis: v51,
      clipMask: v50,
      passEntityNumber: entityNumber,
      userName: v90,
      a10: v93,
      a11: v96,
      a12: v99,
      a13: v102,
      a14: v105,
      a15: v108,
      a16: v111,
      a17: v114,
      a18: v117,
      a19: v120,
      a20: v123,
      a21: v126,
      a22: v129,
      a23: v132,
      a24: v135,
      a25: v138,
      a26: v141,
      a27: v144,
      a28: 0);
    v52 = idEntity::GetPhysics(this: v12);
    v53 = idEntity::GetPhysics(this: v12);
    v54 = this->entityNumber;
    v55 = v52->GetClipMask(this: v52, a2: -1) | 0x420;
    v56 = (idMat3 *)v53->GetAxis(this: v53, a2: 0);
    idClip::Translation(
      this: (idClip *)&v153,
      result: &clientGame->clip,
      a3: &v154,
      start: (const idVec3 *)&v153.eventList.size,
      end: &v151,
      clipModel: (idClipModel *)v14,
      startAxis: v56,
      clipMask: v55,
      passEntityNumber: v91,
      moveClipModel: v94,
      userName: v97,
      a12: v100,
      a13: v103,
      a14: v106,
      a15: v109,
      a16: v112,
      a17: v115,
      a18: v118,
      a19: v121,
      a20: v124,
      a21: v127,
      a22: v130,
      a23: v133,
      a24: v136,
      a25: v139,
      a26: v142,
      a27: v145,
      a28: v54,
      a29: v147,
      a30: false,
      a31: v149,
      a32: 0);
    if ( v155.fraction < 1.0 || v154.fraction < 1.0 )
    {
      v46 = 1;
    }
    else if ( v21 == nullptr || this->GetPosture(this) == POSTURE_CROUCHED )
    {
      v58 = idEntity::GetPhysics(this: v12);
      v59 = idEntity::GetPhysics(this: v12);
      *(float *)&v153.eventHash.lookupMask = v151.x;
      v60 = this->entityNumber;
      *(float *)&v153.eventHash.memTag = v151.y;
      *(float *)&v153.receivers.list = v151.z - (float)256.0;
      v61 = v58->GetClipMask(this: v58, a2: -1) | 0x420;
      v62 = (idMat3 *)v59->GetAxis(this: v59, a2: 0);
      idClip::Translation(
        this: (idClip *)&v153,
        result: &clientGame->clip,
        a3: &v154,
        start: &v151,
        end: (const idVec3 *)&v153.eventHash.lookupMask,
        clipModel: (idClipModel *)v14,
        startAxis: v62,
        clipMask: v61,
        passEntityNumber: v92,
        moveClipModel: v95,
        userName: v98,
        a12: v101,
        a13: v104,
        a14: v107,
        a15: v110,
        a16: v113,
        a17: v116,
        a18: v119,
        a19: v122,
        a20: v125,
        a21: v128,
        a22: v131,
        a23: v134,
        a24: v137,
        a25: v140,
        a26: v143,
        a27: v146,
        a28: v60,
        a29: v148,
        a30: false,
        a31: v150,
        a32: 0);
      v63 = gameLocal->entities.ptr[v154.c.entityNum];
      if ( item->decl->dropRemoveOnContact
        && v63 != nullptr
        && (unsigned __int8)idClass::IsType(this: v63, superclass: &idWorldspawn::Type) == 0 )
      {
        v46 = 1;
      }
      if ( v25 != nullptr )
      {
        v64 = (int)v25->GetAAS(this: v25);
        if ( (*(int (__fastcall **)(int, _DWORD, idVec3 *))(*(_DWORD *)v64 + 28))(a1: v64, a2: 0, a3: &v154.endpos) == 0 )
          v46 = 1;
      }
      if ( (unsigned __int8)idClass::IsType(this: v12, superclass: &idVehicle_Car::Type) != 0 )
      {
        v151.x = v154.endpos.x;
        v151.y = v154.endpos.y;
        v151.z = v154.endpos.z + (float)10.0;
      }
      else
      {
        v151.x = v154.endpos.x;
        v151.y = v154.endpos.y;
        v151.z = v154.endpos.z;
      }
      PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: v154.c.physicsId);
      if ( PhysicsForId != nullptr
        && PhysicsForId->type == PHYSICS_PARAMETRIC
        && idPhysics_Parametric::IsPusher(this: (idPhysics_Parametric *)PhysicsForId) )
      {
        v20 = 1;
      }
    }
    if ( v46 != 0 )
    {
      idEventReceiver::PostEventMS(this: v12, ev: &EV_Remove, time: 0);
      v66 = idClientGame::ConstructPeerMaskForPlayer(this: clientGame, playerNum: this->entityNumber);
      if ( this->presentable == nullptr )
        idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
      PlayerSounds = idPlayer::GetPlayerSounds(this: (idPlayer *)&v156, result: v45);
      idPresentable::StartSoundShader(
        this: presentable,
        channel: SND_CHANNEL_ITEM,
        shader: PlayerSounds->sndCantDropItem,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: v66);
      if ( actor_debugFailedDrop.valueInteger != 0 )
      {
        v69 = gameLocal->GetRenderWorld(this: gameLocal);
        v69->DebugBounds(
          this: v69,
          a2: (const idVec4 *)&idColor::colorWhite,
          a3: (const idBounds *)(v14 + 80),
          a4: &v151,
          a5: 25000,
          a6: false);
        v70 = gameLocal->GetRenderWorld(this: gameLocal);
        v70->DebugPoint(this: v70, a2: (const idVec4 *)&idColor::colorRed, a3: &v154.c.point, a4: 25000, a5: false);
      }
      return nullptr;
    }
    sndDeath = v45[2].sndDeath;
    v73 = item->decl;
    if ( sndDeath != nullptr )
      v74 = (idPresentablePlayer *)((int (__fastcall *)(const idSoundShader *))sndDeath->__vftable[1].SetImplicitText)(a1: sndDeath);
    else
      v74 = nullptr;
    idPresentablePlayer::SetControllerShake(
      this: v74,
      highMagnitude: v73->droppedControllerShake.highMagnitude,
      highDuration: v57,
      lowMagnitude: v73->droppedControllerShake.lowMagnitude,
      lowDuration: v73->droppedControllerShake.highDuration);
    if ( v21 != nullptr )
    {
      v75 = v45[2].sndDeath;
      if ( v75 != nullptr )
        v76 = ((int (__fastcall *)(const idSoundShader *))v75->__vftable[1].SetImplicitText)(a1: v75);
      else
        v76 = 0;
      idHands::RestHandsToIdle(this: (idHands *)(v76 + 37616));
      idVehicle_Car::AddToPlayerCarList(this: v21);
    }
  }
  idEntity::SetOrigin(this: v12, org: &v151);
  v77 = idProp_Moveable::CastTo(c: (idProp_Moveable *)v12);
  if ( v77 != nullptr )
  {
    v78 = item->decl;
    v77->removeCondition = v78->removeCondition;
    v77->fadeTimeDelay = v78->fadeDelay;
  }
  if ( v20 != 0 )
  {
    v79 = idEntity::GetPhysics(this: v12);
    v79->EvaluateContacts(this: v79);
  }
LABEL_62:
  dropSound = item->decl->dropSound;
  if ( dropSound != nullptr )
    idEntity::StartSoundShader(this, channel: SND_CHANNEL_ITEM, shader: dropSound, soundShaderFlags: 0, peerMask: 0xFFu);
  if ( v12 != nullptr )
  {
    v81 = idEntity::GetPhysics(this);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v83 = v81;
    v84 = item->decl;
    GetOrigin = v81->GetOrigin;
    p_aiEventManager = &gameLocal->aiEventManager;
    v87 = GetOrigin(this: v83, a2: 0);
    idAIEventManager::AddEvent(
      this: &v153,
      result: p_aiEventManager,
      eventDecl: v84->dropEventDecl,
      curTime: GameMs,
      originator: v12,
      instigator: this,
      origin: v87,
      delay: 750);
  }
  if ( deleteOnDrop )
  {
    v88 = this->presentable;
    if ( v88 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v88 = this->presentable;
    }
    v89 = this->GetInventory_2(this);
    idInventoryCollection::DeleteInventoryItem(this: v89, owner: v88, item, count);
  }
  return v12;
}


// ========================================================================
// ?HasLootableProjectiles@idActor@@QBA_NXZ
// EA  : 0x82BE7580
// RVA : 0x00BE7580
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

int __fastcall idActor::HasLootableProjectiles(idActor *this)
{
  const idAnimator_AF *v2; // r3
  int v3; // r3
  char *v4; // r10
  _DWORD *v5; // r11
  int i; // ctr
  int EntitiesTouchingBounds; // r29
  int v8; // r30
  int *v9; // r31
  int v10; // r30
  idAttachmentCollection *v11; // r3
  idAttachment *v12; // r3
  int value; // r9
  idAttachment *v14; // r31
  idEntity *v15; // r3
  int v16; // r9
  idEntity *v17; // r3
  idProjectile_Arrow *v18; // r3
  idProjectile_Arrow *v20; // r3
  char v21; // [sp+4Ch] [-D4h] BYREF
  idBounds v22; // [sp+50h] [-D0h] BYREF
  int v23[44]; // [sp+70h] [-B0h] BYREF

  v2 = this->GetAF(this);
  v3 = (int)v2->physicsObj.GetAbsBounds(this: &v2->physicsObj, a2: -1);
  v4 = &v21;
  v5 = (_DWORD *)(v3 - 4);
  for ( i = 6; i != 0; --i )
  {
    ++v5;
    v4 += 4;
    *(_DWORD *)v4 = *v5;
  }
  EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                             this: &clientGame->clip,
                             bounds: &v22,
                             clipMask: 2048,
                             entityList: v23,
                             maxCount: 32);
  v8 = 0;
  if ( EntitiesTouchingBounds > 0 )
  {
    v9 = v23;
    while ( idProjectile_Arrow::CastTo(c: (idProjectile_Arrow *)gameLocal->entities.ptr[*v9]) == nullptr )
    {
      ++v8;
      ++v9;
      if ( v8 >= EntitiesTouchingBounds )
        goto LABEL_7;
    }
    return 1;
  }
LABEL_7:
  v10 = 0;
  if ( this->GetAttachments(this)->attachments.num > 0 )
  {
    while ( 1 )
    {
      v11 = (idAttachmentCollection *)this->GetAttachments(this);
      v12 = idAttachmentCollection::ForIndex(this: v11, index: v10);
      value = v12->entity.spawnId.value;
      v14 = v12;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v15 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v15 != nullptr && idEntity::CastTo(c: v15) != nullptr )
        {
          v16 = v14->entity.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v16 & 0x1FFF] == v16 >> 13
            && (v17 = gameLocal->entities.ptr[v16 & 0x1FFF]) != nullptr )
          {
            v18 = (idProjectile_Arrow *)idEntity::CastTo(c: v17);
          }
          else
          {
            v18 = nullptr;
          }
          v20 = idProjectile_Arrow::CastTo(c: v18);
          if ( v20 != nullptr && idProjectile::IsStuck(this: v20) )
            break;
        }
      }
      if ( ++v10 >= this->GetAttachments(this)->attachments.num )
        return 0;
    }
    return 1;
  }
  return 0;
}


// ========================================================================
// ?SetAttachedLoot@idActor@@QAAXPAVidEntity@@@Z
// EA  : 0x82BE7760
// RVA : 0x00BE7760
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::SetAttachedLoot(idActor *this, idEntity *object)
{
  if ( object != nullptr )
    this->attachedLoot.spawnId.value = (gameLocal->spawnIds.ptr[object->entityNumber] << 13) | object->entityNumber;
  else
    this->attachedLoot.spawnId.value = 0x1FFF;
}


// ========================================================================
// ?SetPain@idActor@@QAAXW4painType_t@@V?$idIndex@FW4invalidJointIndex_t@@@@PBVidEntity@@2ABV?$idHandle@HW4invalidJointGroupHandle@@$0A@@@W4damageDirection_t@@W4damageIntensity_t@@PBVidDeclDamage@@@Z
// EA  : 0x82BE77A0
// RVA : 0x00BE77A0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::SetPain(
        idActor *this,
        painType_t type,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex,
        const idEntity *attacker,
        const idEntity *inflictor,
        const idHandle<int,enum invalidJointGroupHandle,0> *jgh,
        damageDirection_t damageDir,
        damageIntensity_t damageIntensity,
        const idDeclDamage *damageDecl,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const idDeclDamage *a28)
{
  this->actorVolatile.pain.type = type;
  this->actorVolatile.pain.joint.value = (__int16)jointIndex;
  this->actorVolatile.pain.direction = damageDir;
  this->actorVolatile.pain.intensity = damageIntensity;
  this->actorVolatile.pain.jointGroupHandle = (idHandle<int,enum invalidJointGroupHandle,0>)jgh->value;
  if ( attacker != nullptr )
    this->actorVolatile.pain.attacker.spawnId.value = (gameLocal->spawnIds.ptr[attacker->entityNumber] << 13)
                                                    | attacker->entityNumber;
  else
    this->actorVolatile.pain.attacker.spawnId.value = 0x1FFF;
  if ( inflictor != nullptr )
    this->actorVolatile.pain.inflictor.spawnId.value = (gameLocal->spawnIds.ptr[inflictor->entityNumber] << 13)
                                                     | inflictor->entityNumber;
  else
    this->actorVolatile.pain.inflictor.spawnId.value = 0x1FFF;
  this->actorVolatile.pain.damageDecl = a28;
}


// ========================================================================
// ?ClearPain@idActor@@QAAXXZ
// EA  : 0x82BE7838
// RVA : 0x00BE7838
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::ClearPain(idActor *this)
{
  this->actorVolatile.pain.type = PAIN_NONE;
  this->actorVolatile.pain.joint.value = -1;
  this->actorVolatile.pain.direction = DAMAGEDIR_NONE;
  this->actorVolatile.pain.intensity = DAMAGEINTENSITY_NONE;
  this->actorVolatile.pain.jointGroupHandle.value = 0;
  this->actorVolatile.pain.attacker.spawnId.value = 0x1FFF;
  this->actorVolatile.pain.inflictor.spawnId.value = 0x1FFF;
  this->actorVolatile.pain.damageDecl = nullptr;
}


// ========================================================================
// ?PlayFootStepEffect@idActor@@QAA_NW4footStepType_t@@@Z
// EA  : 0x82BE7870
// RVA : 0x00BE7870
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idActor::PlayFootStepEffect(idActor *this, footStepType_t footstepType)
{
  idPhysics *Physics; // r3
  idPhysics *v6; // r29
  int GameMs; // r28
  idPhysics *v8; // r3
  idAIEventManager *p_aiEventManager; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v11; // r3
  idDeclProjectileImpactEffect *footstepEffectTable_Landing; // r25
  walkState_t v13; // r3
  idPhysics *v14; // r29
  int v15; // r28
  idPhysics *v16; // r3
  idAIEventManager *v17; // r29
  const idVec3 *(__fastcall *v18)(idPhysics *, int); // ctr
  const idVec3 *v19; // r3
  const idDeclProjectileImpactEffect *footstepEffectTable_SlowWalk; // r11
  idPhysics *v21; // r29
  int v22; // r28
  idPhysics *v23; // r3
  idAIEventManager *v24; // r29
  const idVec3 *(__fastcall *v25)(idPhysics *, int); // ctr
  const idVec3 *v26; // r3
  posture_t v27; // r3
  const idDeclFootstepEvents *footstepEvents; // r9
  idPhysics *v29; // r29
  int v30; // r28
  idPhysics *v31; // r3
  idAIEventManager *v32; // r29
  const idVec3 *(__fastcall *v33)(idPhysics *, int); // ctr
  const idVec3 *v34; // r3
  idPhysics *v35; // r29
  int v36; // r28
  idPhysics *v37; // r3
  idAIEventManager *v38; // r29
  const idVec3 *(__fastcall *v39)(idPhysics *, int); // ctr
  const idVec3 *v40; // r3
  idPhysics *v41; // r3
  int v42; // r3
  BOOL enabled; // r9
  idMat3 *v44; // r29
  char v45; // r10
  int FootSurfaceType; // r24
  const char *v47; // r28
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v49; // r3
  idPhysics *v50; // r3
  int v51; // r3
  idPhysics *v52; // r3
  int v53; // r3
  double v54; // fp13
  double v55; // fp12
  double v56; // fp11
  double v57; // fp7
  double v58; // fp6
  double v59; // fp8
  double v60; // fp7
  idPhysics *v61; // r24
  idPhysics *v62; // r21
  int entityNumber; // r20
  idMat3 *v64; // r24
  idClipModel *v65; // r3
  __int64 v66; // r7
  __int64 v67; // r4 OVERLAPPED
  int memTag; // r5
  idPhysics *v69; // r3
  const idDeclProjectileImpactEffect::projectileImpactEffect_t *ImpactEffectForMaterial; // r7
  idColor *v71; // r29
  idRenderWorld *v72; // r3
  __int64 v73; // r10
  __int64 v74; // r6
  __int64 v75; // r8
  va *v76; // r3
  char *v77; // r4
  walkState_t v78; // r3
  const idPresentable *v79; // [sp+8h] [-1248h]
  int v80; // [sp+8h] [-1248h]
  idPresentable *v81; // [sp+Ch] [-1244h]
  int v82; // [sp+Ch] [-1244h]
  char *v83; // [sp+10h] [-1240h]
  int v84; // [sp+10h] [-1240h]
  int v85; // [sp+14h] [-123Ch]
  int v86; // [sp+14h] [-123Ch]
  int v87; // [sp+18h] [-1238h]
  int v88; // [sp+18h] [-1238h]
  int v89; // [sp+1Ch] [-1234h]
  int v90; // [sp+1Ch] [-1234h]
  int v91; // [sp+20h] [-1230h]
  int v92; // [sp+24h] [-122Ch]
  int v93; // [sp+28h] [-1228h]
  int v94; // [sp+2Ch] [-1224h]
  int v95; // [sp+30h] [-1220h]
  int v96; // [sp+34h] [-121Ch]
  int v97; // [sp+38h] [-1218h]
  int v98; // [sp+3Ch] [-1214h]
  int v99; // [sp+40h] [-1210h]
  int v100; // [sp+44h] [-120Ch]
  int v101; // [sp+48h] [-1208h]
  int v102; // [sp+4Ch] [-1204h]
  int v103; // [sp+50h] [-1200h]
  int v104; // [sp+58h] [-11F8h]
  int v105; // [sp+60h] [-11F0h]
  idTreeAnimator v106; // [sp+70h] [-11E0h] BYREF

  Physics = idEntity::GetPhysics(this);
  if ( !Physics->HasGroundContacts(this: Physics) )
    return 0;
  if ( footstepType == FOOTSTEP_LAND )
  {
    if ( this->actorConstants.footstepEvents != nullptr )
    {
      v6 = idEntity::GetPhysics(this);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v8 = v6;
      GetOrigin = v6->GetOrigin;
      p_aiEventManager = &gameLocal->aiEventManager;
      v11 = GetOrigin(this: v8, a2: 0);
      idAIEventManager::AddEvent(
        this: (idAIEventManager *)&v106.deferredOrigin.z,
        result: p_aiEventManager,
        eventDecl: this->actorConstants.footstepEvents->landEventDecl,
        curTime: GameMs,
        originator: this,
        instigator: this,
        origin: v11,
        delay: 0);
    }
    footstepEffectTable_Landing = this->actorConstants.footstepEffectTable_Landing;
    if ( footstepEffectTable_Landing != nullptr )
    {
LABEL_27:
      v41 = idEntity::GetPhysics(this);
      v42 = (int)v41->GetGravityNormal(this: v41);
      enabled = this->walkIK.enabled;
      v44 = (idMat3 *)v42;
      *((float *)&v106.__vftable + 2) = 0.0;
      *((float *)&v106.__vftable + 3) = 0.0;
      *(idColor *)&v106.g.axis.mat[1].y = idColor::colorWhite;
      *(float *)&v106.name.str = 0.0;
      if ( !enabled || (v45 = 1, this->walkIK.enabledLegs == 0) )
        v45 = 0;
      if ( v45 != 0 && this->walkIK.onGround && footstepType != FOOTSTEP_LAND )
      {
        FootSurfaceType = idAnimator_WalkIK::GetFootSurfaceType(this: &this->walkIK, footstep: footstepType);
        if ( footstepType != FOOTSTEP_LEFT_FOOT )
          v47 = "righttoebase";
        else
          v47 = "lefttoebase";
        TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        idTreeAnimator::GetJointIndex(this: &v106, result: TreeAnimatorFromPresentable, jointName: v47);
        if ( SHIWORD(v106.__vftable) < 0 )
        {
          v50 = idEntity::GetPhysics(this);
          v51 = (int)v50->GetOrigin(this: v50, a2: 0);
          *((float *)&v106.__vftable + 2) = *(float *)v51;
          *((float *)&v106.__vftable + 3) = *(float *)(v51 + 4);
          v106.name.str = *(const char **)(v51 + 8);
        }
        else
        {
          v49 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
          idTreeAnimator::GetWorldSpaceJointTransform(
            this: v49,
            pose: DRIVER_MODEL,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)HIWORD(v106.__vftable),
            origin: (idVec3 *)(&v106.__vftable + 2),
            axis: (idMat3 *)&v106.gameParmBlock.constants);
        }
      }
      else
      {
        v52 = idEntity::GetPhysics(this);
        v53 = (int)v52->GetOrigin(this: v52, a2: 0);
        v54 = *(float *)v53;
        *((float *)&v106.__vftable + 2) = *(float *)v53;
        v55 = *(float *)(v53 + 4);
        *((float *)&v106.__vftable + 3) = *(float *)(v53 + 4);
        v56 = *(float *)(v53 + 8);
        v106.name.str = *(const char **)(v53 + 8);
        v57 = (float)(v44->mat[0].y * (float)4.0);
        v58 = (float)(v44->mat[0].z * (float)4.0);
        v106.referenceBounds.b[0].y = (float)v54 - (float)(v44->mat[0].x * (float)4.0);
        v106.referenceBounds.b[0].z = (float)v55 - (float)v57;
        v106.referenceBounds.b[1].x = (float)v56 - (float)v58;
        v59 = (float)(v44->mat[0].y * (float)32.0);
        v60 = (float)(v44->mat[0].z * (float)32.0);
        *(float *)&v106.nextOnCommitList = (float)(v44->mat[0].x * (float)32.0) + (float)v54;
        *(float *)&v106.needCommitFrameNum = (float)v59 + (float)v55;
        *(float *)&v106.committed = (float)v56 + (float)v60;
        v61 = idEntity::GetPhysics(this);
        v62 = idEntity::GetPhysics(this);
        entityNumber = this->entityNumber;
        v64 = (idMat3 *)v61->GetAxis(this: v61, a2: 0);
        v65 = v62->GetClipModel(this: v62, a2: 0);
        HIDWORD(v67) = idClip::Translation(
                         this: (idClip *)&v106.deferredOrigin,
                         result: &clientGame->clip,
                         a3: (trace_t *)&v106.g.customMaterial,
                         start: (const idVec3 *)&v106.referenceBounds.b[0].y,
                         end: (const idVec3 *)&v106.nextOnCommitList,
                         clipModel: v65,
                         startAxis: v64,
                         clipMask: 257,
                         passEntityNumber: (int)v79,
                         moveClipModel: (bool)v81,
                         userName: v83,
                         a12: v85,
                         a13: v87,
                         a14: v89,
                         a15: v91,
                         a16: v92,
                         a17: v93,
                         a18: v94,
                         a19: v95,
                         a20: v96,
                         a21: v97,
                         a22: v98,
                         a23: v99,
                         a24: v100,
                         a25: v101,
                         a26: v102,
                         a27: v103,
                         a28: entityNumber,
                         a29: v104,
                         a30: false,
                         a31: v105,
                         a32: 0);
        if ( *(float *)&v106.g.customMaterial >= 1.0 )
        {
          FootSurfaceType = 0;
          *(idColor *)&v106.g.axis.mat[1].y = idColor::colorWhite;
        }
        else
        {
          memTag = v106.gameParmBlock.ops.memTag;
          LODWORD(v67) = v106.gameParmBlock.ops.listStatic;
          LODWORD(v66) = LOBYTE(v106.gameParmBlock.ops.granularity);
          v106.g.axis.mat[1].x = 1.0;
          FootSurfaceType = v106.g.viewport.y1;
          *(_QWORD *)&v106.deferredOrigin.x = v66;
          v106.g.axis.mat[0].y = (float)*(__int64 *)((char *)&v67 - 4) * (float)0.0039215689;
          v106.g.axis.mat[0].z = (float)v67 * (float)0.0039215689;
          v106.g.axis.mat[0].x = (float)v66 * (float)0.0039215689;
          *(idVec3 *)&v106.g.axis.mat[1].y = v106.g.axis.mat[0];
          v106.g.axis.mat[2].y = 1.0;
        }
      }
      v69 = idEntity::GetPhysics(this);
      if ( ((double (__fastcall *)(idPhysics *, _DWORD))v69->GetWaterLevel)(a1: v69, a2: 0) > 0.0 )
        FootSurfaceType = 6;
      ImpactEffectForMaterial = idDeclProjectileImpactEffect::GetImpactEffectForMaterial(
                                  this: footstepEffectTable_Landing,
                                  materialID: FootSurfaceType);
      if ( ImpactEffectForMaterial == nullptr )
      {
        idLib::Warning(fmt: "no effect for footstep effect table?");
        return 1;
      }
      idClientGame::ImpactEffect(
        this: clientGame,
        point: (const idMat3 *)(&v106.__vftable + 2),
        normal: v44,
        color: (idColor *)&v106.g.axis.mat[1].y,
        effect: ImpactEffectForMaterial,
        skipParticle: false,
        noDecals: false,
        noSounds: false,
        owner: v79,
        entity: v81,
        jointId: (idIndex<short,enum invalidJointIndex_t> *)v83,
        a12: v85,
        a13: v87,
        a14: v89,
        a15: v91,
        a16: v92,
        a17: v93,
        a18: v94,
        a19: v95,
        a20: v96,
        a21: v97,
        a22: v98,
        a23: v99,
        a24: v100,
        a25: v101,
        a26: v102,
        a27: v103,
        a28: 0,
        a29: v104,
        a30: 0,
        a31: v105,
        a32: NULL_JOINT_INDEX.value);
      if ( g_debugFootStepEffect.valueInteger == 0 )
        return 1;
      v71 = &idColor::colorRed;
      if ( (unsigned int)footstepType <= FOOTSTEP_LAND )
      {
        switch ( footstepType )
        {
          case FOOTSTEP_RIGHT_FOOT:
            v71 = &idColor::colorGreen;
            break;
          case FOOTSTEP_LEFT_REAR_FOOT:
            v71 = &idColor::colorBlue;
            break;
          case FOOTSTEP_RIGHT_REAR_FOOT:
            v71 = &idColor::colorOrange;
            break;
          default:
            if ( footstepType != FOOTSTEP_LEFT_FOOT )
              v71 = &idColor::colorMdGrey;
            else
              v71 = &idColor::colorYellow;
            break;
        }
      }
      v72 = gameLocal->GetRenderWorld(this: gameLocal);
      v106.g.origin.z = 4.0;
      v106.g.origin.x = *((float *)&v106.__vftable + 3);
      v106.referenceBounds.b[1].z = *((float *)&v106.__vftable + 2);
      v106.g.origin.y = *(float *)&v106.name.str;
      v72->DebugSphere(
        this: v72,
        a2: (const idVec4 *)v71,
        a3: (const idSphere *)&v106.referenceBounds.b[1].z,
        a4: 12,
        a5: 5000,
        a6: true);
      LODWORD(v73) = &unk_822C0000;
      HIDWORD(v74) = this->name.data;
      LODWORD(v74) = FootSurfaceType;
      v76 = va::va(
              this: (va *)&v106.gameParmBlock.staticOps[3],
              fmt: "FootStep for %s surface type: %d     ",
              a3: v74,
              a4: v75,
              a5: v73,
              a6: v80,
              a7: v82,
              a8: v84,
              a9: v86,
              a10: v88,
              a11: v90);
      idStr::idStr(this: (idStr *)&v106.deferredAxis.mat[1], text: v76);
      if ( footstepType == FOOTSTEP_LAND )
      {
        v77 = "landing, using footstepEffectTable\n";
      }
      else
      {
        v78 = this->GetWalkState(this);
        switch ( v78 )
        {
          case WALKSTATE_WALKING:
            if ( this->GetPosture(this) == POSTURE_CROUCHED )
            {
              idStr::Append(this: (idStr *)&v106.deferredAxis.mat[1], text: "crouching, ");
              if ( this->actorConstants.footstepEffectTable_CrouchWalk != nullptr )
              {
                v77 = "using footstepEffectTable_CrouchWalk\n";
              }
              else if ( this->actorConstants.footstepEffectTable_SlowWalk != nullptr )
              {
                v77 = "using footstepEffectTable_SlowWalk\n";
              }
              else
              {
                v77 = "using footstepEffectTable\n";
              }
            }
            else
            {
              idStr::Append(this: (idStr *)&v106.deferredAxis.mat[1], text: "walking, ");
              if ( this->actorConstants.footstepEffectTable_SlowWalk != nullptr )
                v77 = "using footstepEffectTable_SlowWalk\n";
              else
                v77 = "using footstepEffectTable\n";
            }
            break;
          case WALKSTATE_RUNNING:
            v77 = "running, using footstepEffectTable\n";
            break;
          case WALKSTATE_SPRINTING:
            if ( this->actorConstants.footstepEffectTable_Sprint != nullptr )
              v77 = "sprinting, using footstepEffectTable_Sprint\n";
            else
              v77 = "sprinting but no effect so using footstepEffectTable\n";
            break;
          default:
LABEL_76:
            idLib::Printf(fmt: "%s", (const char *)LODWORD(v106.deferredAxis.mat[1].y));
            idStr::FreeData(this: (idStr *)&v106.deferredAxis.mat[1]);
            return 1;
        }
      }
      idStr::Append(this: (idStr *)&v106.deferredAxis.mat[1], text: v77);
      goto LABEL_76;
    }
    goto LABEL_25;
  }
  v13 = this->GetWalkState(this);
  if ( v13 == WALKSTATE_WALKING )
  {
    v27 = this->GetPosture(this);
    footstepEvents = this->actorConstants.footstepEvents;
    if ( v27 == POSTURE_CROUCHED )
    {
      if ( footstepEvents != nullptr )
      {
        v29 = idEntity::GetPhysics(this);
        v30 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v31 = v29;
        v33 = v29->GetOrigin;
        v32 = &gameLocal->aiEventManager;
        v34 = v33(this: v31, a2: 0);
        idAIEventManager::AddEvent(
          this: (idAIEventManager *)&v106.g.scale,
          result: v32,
          eventDecl: this->actorConstants.footstepEvents->sneakEventDecl,
          curTime: v30,
          originator: this,
          instigator: this,
          origin: v34,
          delay: 0);
      }
      if ( this->actorConstants.footstepEffectTable_CrouchWalk != nullptr )
      {
        footstepEffectTable_Landing = this->actorConstants.footstepEffectTable_CrouchWalk;
        goto LABEL_26;
      }
    }
    else if ( footstepEvents != nullptr )
    {
      v35 = idEntity::GetPhysics(this);
      v36 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v37 = v35;
      v39 = v35->GetOrigin;
      v38 = &gameLocal->aiEventManager;
      v40 = v39(this: v37, a2: 0);
      idAIEventManager::AddEvent(
        this: (idAIEventManager *)&v106.g.scale.y,
        result: v38,
        eventDecl: this->actorConstants.footstepEvents->walkEventDecl,
        curTime: v36,
        originator: this,
        instigator: this,
        origin: v40,
        delay: 0);
    }
    footstepEffectTable_SlowWalk = this->actorConstants.footstepEffectTable_SlowWalk;
LABEL_24:
    footstepEffectTable_Landing = footstepEffectTable_SlowWalk;
    if ( footstepEffectTable_SlowWalk != nullptr )
      goto LABEL_26;
    goto LABEL_25;
  }
  if ( v13 != WALKSTATE_RUNNING )
  {
    if ( v13 != WALKSTATE_SPRINTING )
      return 1;
    if ( this->actorConstants.footstepEvents != nullptr )
    {
      v14 = idEntity::GetPhysics(this);
      v15 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v16 = v14;
      v18 = v14->GetOrigin;
      v17 = &gameLocal->aiEventManager;
      v19 = v18(this: v16, a2: 0);
      idAIEventManager::AddEvent(
        this: (idAIEventManager *)&v106.deferredOrigin.z,
        result: v17,
        eventDecl: this->actorConstants.footstepEvents->sprintEventDecl,
        curTime: v15,
        originator: this,
        instigator: this,
        origin: v19,
        delay: 0);
    }
    footstepEffectTable_SlowWalk = this->actorConstants.footstepEffectTable_Sprint;
    goto LABEL_24;
  }
  if ( this->actorConstants.footstepEvents != nullptr )
  {
    v21 = idEntity::GetPhysics(this);
    v22 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v23 = v21;
    v25 = v21->GetOrigin;
    v24 = &gameLocal->aiEventManager;
    v26 = v25(this: v23, a2: 0);
    idAIEventManager::AddEvent(
      this: (idAIEventManager *)&v106.g.axis.mat[2].z,
      result: v24,
      eventDecl: this->actorConstants.footstepEvents->runEventDecl,
      curTime: v22,
      originator: this,
      instigator: this,
      origin: v26,
      delay: 0);
  }
LABEL_25:
  footstepEffectTable_Landing = this->actorConstants.footstepEffectTable;
LABEL_26:
  if ( footstepEffectTable_Landing != nullptr )
    goto LABEL_27;
  return 1;
}


// ========================================================================
// __unwind$498538
// EA  : 0x82BE8200
// RVA : 0x00BE8200
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_498538()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4688 + 160));
}


// ========================================================================
// ?AnimEvent_LeftFoot@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BE8228
// RVA : 0x00BE8228
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_LeftFoot(idActor *this, idActor *result, const idMD6Anim *animHandle)
{
  idActor::PlayFootStepEffect(this: result, footstepType: FOOTSTEP_LEFT_FOOT);
  return this;
}


// ========================================================================
// ?AnimEvent_RightFoot@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BE8260
// RVA : 0x00BE8260
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_RightFoot(idActor *this, idActor *result, const idMD6Anim *animHandle)
{
  idActor::PlayFootStepEffect(this: result, footstepType: FOOTSTEP_RIGHT_FOOT);
  return this;
}


// ========================================================================
// ?AnimEvent_LeftRearFoot@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BE8298
// RVA : 0x00BE8298
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_LeftRearFoot(idActor *this, idActor *result, const idMD6Anim *animHandle)
{
  idActor::PlayFootStepEffect(this: result, footstepType: FOOTSTEP_LEFT_REAR_FOOT);
  return this;
}


// ========================================================================
// ?AnimEvent_RightRearFoot@idActor@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82BE82D0
// RVA : 0x00BE82D0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::AnimEvent_RightRearFoot(idActor *this, idActor *result, const idMD6Anim *animHandle)
{
  idActor::PlayFootStepEffect(this: result, footstepType: FOOTSTEP_RIGHT_REAR_FOOT);
  return this;
}


// ========================================================================
// StringListAddIfUnique
// EA  : 0x82BE8910
// RVA : 0x00BE8910
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall StringListAddIfUnique(const idList<idStr,5> *listToAdd, idList<idStr,5> *addToList)
{
  int v4; // r27
  int v5; // r29
  int Index; // r3
  idStr *v7; // r11
  BOOL v8; // r26
  idStr v9; // [sp+50h] [-80h] BYREF
  idStr v10[3]; // [sp+70h] [-60h] BYREF

  v4 = 0;
  if ( listToAdd->num > 0 )
  {
    v5 = 0;
    do
    {
      idStr::idStr(this: &v9, text: listToAdd->list[v5].data);
      Index = idList<idStr,5>::FindIndex(this: addToList, obj: &v9, startIndex: 0);
      if ( Index < 0 )
        v7 = nullptr;
      else
        v7 = &addToList->list[Index];
      v8 = (_cntlzw((unsigned int)v7) & 0x20) != 0;
      idStr::FreeData(this: &v9);
      if ( v8 )
      {
        idStr::idStr(this: v10, text: listToAdd->list[v5].data);
        idList<idStr,5>::Append(this: addToList, obj: v10);
        idStr::FreeData(this: v10);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < listToAdd->num );
  }
}


// ========================================================================
// __unwind$499568
// EA  : 0x82BE89D8
// RVA : 0x00BE89D8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_499568()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$499569
// EA  : 0x82BE8A00
// RVA : 0x00BE8A00
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_499569()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?Spawn@idActor@@QAAXXZ
// EA  : 0x82BE8A30
// RVA : 0x00BE8A30
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::Spawn(idActor *this)
{
  idLinkList<idActor> *head; // r5
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idIndex<short,enum invalidJointIndex_t> *v5; // r26
  idPhysics *Physics; // r3
  int v7; // r3
  double v8; // fp11
  double v9; // fp10
  double v10; // fp8
  idGameTimeManager *v11; // r3
  int entityNumber; // r23
  idVec3 *p_gravity; // r24
  idSoundEmitter *SoundEmitter; // r22
  idClip *p_clip; // r20
  idAnimStack *v16; // r3
  int v17; // r11
  idPhysics *v18; // r3
  char *data; // r29
  char *v20; // r28
  idAngles *v21; // r3
  const char *v22; // r3
  idPresentable *v23; // r11
  idRenderModel *model; // r10
  char v25; // r10
  bool v26; // zf
  int v27; // r24
  int v28; // r26
  idInventoryAttachmentDef *v29; // r28
  const idDeclInventory *inventoryDecl; // r29
  idJobManager *v31; // r3
  idInventoryItem *JobByDecl; // r29
  idPresentable *v33; // r29
  int count; // r23
  const idDeclInventory *v35; // r22
  idInventoryCollection *v36; // r3
  idInventoryAttachmentDef::startingSlot_t startSlot; // r11
  idWeapon *v38; // r3
  int v39; // r28
  int v40; // r29
  idEntityAttachmentDef *v41; // r11
  const idDeclEntityDef *entityDef; // r5
  idPhysics *v43; // r3
  const idVec3 *v44; // r3
  idPhysicsCallbacks *v45; // [sp+8h] [-138h]
  int v46; // [sp+Ch] [-134h]
  int v47; // [sp+10h] [-130h]
  int v48; // [sp+14h] [-12Ch]
  int v49; // [sp+18h] [-128h]
  int v50; // [sp+1Ch] [-124h]
  int v51; // [sp+20h] [-120h]
  int v52; // [sp+24h] [-11Ch]
  int v53; // [sp+28h] [-118h]
  int v54; // [sp+2Ch] [-114h]
  int v55; // [sp+30h] [-110h]
  int v56; // [sp+34h] [-10Ch]
  int v57; // [sp+38h] [-108h]
  int v58; // [sp+3Ch] [-104h]
  int v59; // [sp+40h] [-100h]
  int v60; // [sp+44h] [-FCh]
  int v61; // [sp+48h] [-F8h]
  int v62; // [sp+4Ch] [-F4h]
  int v63; // [sp+50h] [-F0h]
  idAttachmentCollection v64; // [sp+60h] [-E0h] BYREF
  char *v65; // [sp+74h] [-CCh]
  int v66; // [sp+78h] [-C8h]
  char v67; // [sp+7Ch] [-C4h] BYREF
  idAnimatorParms_Base v68; // [sp+90h] [-B0h] BYREF

  v64.parent = nullptr;
  v66 = 20;
  v65 = &v67;
  v67 = 0;
  head = gameLocal->actorEntities.head;
  this->actorNode.prev->next = this->actorNode.next;
  this->actorNode.next->prev = this->actorNode.prev;
  this->actorNode.prev = &this->actorNode;
  this->actorNode.head = &this->actorNode;
  this->actorNode.next = head;
  this->actorNode.prev = head->prev;
  head->prev = &this->actorNode;
  this->actorNode.prev->next = &this->actorNode;
  this->actorNode.head = head->head;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v5 = (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v5 == nullptr && idPlayer::CastTo(c: (idPlayer *)this) == nullptr )
    idLib::Error(fmt: "No animated model specified for '%s'", this->name.data);
  idAnimatedEntity::SetRadiusDamageJointIndices(this, jointNames: &this->actorEditable.radiusDamageJoints);
  Physics = idEntity::GetPhysics(this);
  v7 = (int)Physics->GetAxis(this: Physics, a2: 0);
  this->actorVolatile.modelInfo.modelAxis.mat[0].x = *(float *)v7;
  this->actorVolatile.modelInfo.modelAxis.mat[0].y = *(float *)(v7 + 4);
  this->actorVolatile.modelInfo.modelAxis.mat[0].z = *(float *)(v7 + 8);
  v8 = *(float *)(v7 + 12);
  v64.attachments.list = (idAttachment *)(v7 + 12);
  this->actorVolatile.modelInfo.modelAxis.mat[1].x = v8;
  v9 = *(float *)(v7 + 16);
  v64.attachments.list = (idAttachment *)&this->actorVolatile.modelInfo.modelAxis.mat[1];
  this->actorVolatile.modelInfo.modelAxis.mat[1].y = v9;
  this->actorVolatile.modelInfo.modelAxis.mat[1].z = *(float *)(v7 + 20);
  v64.attachments.list = (idAttachment *)(v7 + 24);
  v10 = *(float *)(v7 + 24);
  v64.attachments.list = (idAttachment *)&this->actorVolatile.modelInfo.modelAxis.mat[2];
  this->actorVolatile.modelInfo.modelAxis.mat[2].x = v10;
  this->actorVolatile.modelInfo.modelAxis.mat[2].y = *(float *)(v7 + 28);
  this->actorVolatile.modelInfo.modelAxis.mat[2].z = *(float *)(v7 + 32);
  v68.animStack = this->GetAnimStack_2(this);
  idStr::idStr(this: &v68.name, text: "af");
  memset(&v68.originBlend, 0, 12);
  v68.blendOp = BOP_LERP;
  v68.alpha = 0.0;
  v11 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->afProperties, gametimeManager: v11, parms: &v68);
  v64.attachments.list = (idAttachment *)this->entityNumber;
  this->actorPhysicsCallbacks.ent.spawnId.value = (*((_DWORD *)&gameLocal->__vftable
                                                   + (int)&v64.attachments.list[275].originOffset.z
                                                   + 3) << 13)
                                                | (int)v64.attachments.list;
  this->actorPhysicsCallbacks.af = &this->afProperties;
  entityNumber = this->entityNumber;
  p_gravity = &gameLocal->clientGame.gravity;
  SoundEmitter = idEntity::GetSoundEmitter(this, alloc: true);
  p_clip = &clientGame->clip;
  v16 = this->GetAnimStack_2(this);
  idAnimator_AF::InitAF(
    this: &this->afProperties,
    animStack: v16,
    clip: p_clip,
    impactManager: &this->impactManager,
    soundEmitter: SoundEmitter,
    soundChannel: SND_CHANNEL_BODY3,
    gravityVector: p_gravity,
    entityNumber,
    callback: v45,
    a10: v46,
    a11: v47,
    a12: v48,
    a13: v49,
    a14: v50,
    a15: v51,
    a16: v52,
    a17: v53,
    a18: v54,
    a19: v55,
    a20: v56,
    a21: v57,
    a22: v58,
    a23: v59,
    a24: v60,
    a25: v61,
    a26: v62,
    a27: v63,
    a28: &this->actorPhysicsCallbacks);
  if ( this->actorConstants.modelInfo.soundJoint.len != 0 )
  {
    v17 = HIWORD(idTreeAnimator::GetJointIndex(
                   this: (idTreeAnimator *)&v64,
                   result: v5,
                   jointName: this->actorConstants.modelInfo.soundJoint.data)->__vftable);
    this->actorVolatile.modelInfo.soundJoint.value = v17;
    if ( v17 == 0xFFFF )
    {
      v18 = idEntity::GetPhysics(this);
      data = this->actorConstants.modelInfo.soundJoint.data;
      v20 = this->name.data;
      v21 = (idAngles *)v18->GetOrigin(this: v18, a2: 0);
      v22 = idVec3::ToString(this: v21, precision: 0);
      idLib::Warning(fmt: "idAnimated '%s' at (%s): cannot find joint '%s' for sound playback", v20, v22, data);
    }
  }
  if ( this->actorConstants.perception.eyeOffset.z == 0.0 )
    idLib::Warning(fmt: "'%s' has no 'eyeOffset' set.", this->name.data);
  if ( this->actorConstants.perception.crouchedEyeOffset.z == 0.0 )
    idLib::Warning(fmt: "'%s' has no 'crouchedEyeOffset' set.", this->name.data);
  v23 = this->presentable;
  if ( v23 == nullptr
    || (model = v23->model,
        v64.attachments.list = (idAttachment *)this->presentable,
        v26 = model != nullptr,
        v25 = 1,
        !v26) )
  {
    v25 = 0;
  }
  if ( v25 != 0 )
  {
    if ( v23 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v23 = this->presentable;
    }
    v23->model->g.castDimShadows = DIMSHADOW_HIGH_QUALITY;
  }
  v27 = 0;
  if ( this->startingInventory.num > 0 )
  {
    v28 = 0;
    do
    {
      v29 = &this->startingInventory.list[v28];
      inventoryDecl = v29->inventoryDecl;
      if ( inventoryDecl != nullptr )
      {
        if ( inventoryDecl->stackable )
        {
          v31 = (idJobManager *)this->GetInventory_2(this);
          JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(
                                           this: v31,
                                           jobDecl: (const idDeclJob *)inventoryDecl);
          if ( JobByDecl != nullptr )
            goto LABEL_28;
        }
        v33 = this->presentable;
        if ( v33 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v33 = this->presentable;
        }
        count = v29->count;
        v35 = v29->inventoryDecl;
        v36 = this->GetInventory_2(this);
        JobByDecl = idInventoryCollection::GiveItem(
                      this: v36,
                      owner: v33,
                      decl: v35,
                      count,
                      forceCount: false,
                      canIntro: false);
        if ( JobByDecl != nullptr )
        {
LABEL_28:
          startSlot = v29->startSlot;
          if ( v29->startSlot == EQUIPPED
            && (v64.attachments.num = JobByDecl->decl->equipSlot, v64.attachments.num != 0) )
          {
            v38 = (idWeapon *)((int (__fastcall *)(idActor *))this->GetEquipped)(a1: this);
            if ( v38 == nullptr || idWeapon::CastTo(c: v38) == nullptr )
              this->EquipItem(this, a2: JobByDecl, a3: EQUIP_NONE);
          }
          else if ( startSlot == HOLSTERED )
          {
            this->HolsterItem(this, a2: JobByDecl, a3: v29->showHolstered);
          }
          JobByDecl->forSale = v29->forSale;
          JobByDecl->lootable = v29->lootable;
          if ( v29->inventoryDecl->initiallyHidden )
          {
            idAttachmentCollection::FindAttachment(
              this: &v64,
              result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
              item: JobByDecl);
            if ( v64.attachments.list != (idAttachment *)-1 )
              idAttachmentCollection::HideAttachment(
                this: &this->attachments,
                handle: (const idHandle<int,enum invalidAttachment_t,-1> *)&v64,
                ignoreShowAll: false);
          }
        }
      }
      ++v27;
      ++v28;
    }
    while ( v27 < this->startingInventory.num );
  }
  v39 = 0;
  if ( this->entityAttachments.num > 0 )
  {
    v40 = 0;
    do
    {
      v41 = &this->entityAttachments.list[v40];
      entityDef = v41->entityDef;
      if ( entityDef != nullptr )
        idAttachmentCollection::AddAttachment(
          this: (idAttachmentCollection *)&v64.attachments.num,
          result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
          entityDef,
          tag: v41->tag.data,
          forceReplicationFlags: -1);
      ++v39;
      ++v40;
    }
    while ( v39 < this->entityAttachments.num );
  }
  v43 = idEntity::GetPhysics(this);
  v44 = v43->GetOrigin(this: v43, a2: 0);
  idDeferredVisGrid::Init(this: &this->deferredVisGrid, entityPos: v44);
  StringListAddIfUnique(listToAdd: &this->takedownTypes.stealthSWFWD, addToList: &gameLocal->extraBehaviorAnimsToLoad);
  StringListAddIfUnique(listToAdd: &this->takedownTypes.stealthSWREV, addToList: &gameLocal->extraBehaviorAnimsToLoad);
  StringListAddIfUnique(listToAdd: &this->takedownTypes.stealthDWFWD, addToList: &gameLocal->extraBehaviorAnimsToLoad);
  StringListAddIfUnique(listToAdd: &this->takedownTypes.stealthDWREV, addToList: &gameLocal->extraBehaviorAnimsToLoad);
  StringListAddIfUnique(listToAdd: &this->takedownTypes.counterSWFWD, addToList: &gameLocal->extraBehaviorAnimsToLoad);
  StringListAddIfUnique(listToAdd: &this->takedownTypes.counterSWREV, addToList: &gameLocal->extraBehaviorAnimsToLoad);
  StringListAddIfUnique(listToAdd: &this->takedownTypes.counterDWFWD, addToList: &gameLocal->extraBehaviorAnimsToLoad);
  StringListAddIfUnique(listToAdd: &this->takedownTypes.counterDWREV, addToList: &gameLocal->extraBehaviorAnimsToLoad);
  StringListAddIfUnique(listToAdd: &this->takedownTypes.AITakedowns, addToList: &gameLocal->extraBehaviorAnimsToLoad);
  idEventReceiver::PostEventMS(this, ev: &EV_PostSpawn, time: 0);
  idStr::FreeData(this: &v68.name);
  idStr::FreeData(this: (idStr *)&v64.parent);
}


// ========================================================================
// $LN181
// EA  : 0x82BE909C
// RVA : 0x00BE909C
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _LN181()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 112));
}


// ========================================================================
// __unwind$499631
// EA  : 0x82BE90C4
// RVA : 0x00BE90C4
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_499631()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 320 + 144));
}


// ========================================================================
// ?IsLootable@idActor@@QBA_NXZ
// EA  : 0x82BE90F0
// RVA : 0x00BE90F0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

int __fastcall idActor::IsLootable(idActor *this)
{
  unsigned __int8 v3; // r11

  if ( common->IsMultiplayer(this: common)
    && idGameLocal::GetChallengeMode(this: gameLocal) == CHALLENGE_MODE_COOP
    && actor_allowLootingInCoop.valueInteger == 0 )
  {
    return 0;
  }
  if ( this->lootable )
    return 1;
  v3 = 0;
  if ( this->dropRandomLoot )
    return 1;
  return v3;
}


// ========================================================================
// ?DropAttachment@idActor@@UAAXPAVidInventoryItem@@@Z
// EA  : 0x82BE91A0
// RVA : 0x00BE91A0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::DropAttachment(idActor *this, idInventoryItem *item)
{
  int v4; // r31
  idAttachmentCollection *p_attachments; // r23
  idAttachment *v6; // r3
  idAttachment *v7; // r27
  const idHandle<int,enum invalidAttachment_t,-1> *p_handle; // r24
  idProp_Loot *v9; // r31
  idEntityPtr<idEntity> *p_droppedItem1; // r30
  idEntity *v11; // r26
  idEntity *v12; // r26
  idProp_Loot *v13; // r30
  int v14; // r10
  int v15; // r9
  int v16; // r8
  int v17; // r7
  int v18; // r6
  int v19; // r5
  lobbyUser_t *presentable; // r4
  char v21; // r11
  int v22; // r4
  const idVec3 *Body; // r3
  float *PointVelocity; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *v26; // r11
  idTreeAnimator *v27; // r30
  double v28; // fp31
  __int64 v29; // r11
  double v30; // fp31
  double v31; // fp11
  double v32; // fp10
  idVec3 *v33; // r3
  double v34; // fp10
  double v35; // fp9
  idPhysics *Physics; // r3
  idPhysics *v37; // r3
  idProjectile_Grenade *v38; // r3
  idProjectile *v39; // r30
  double v40; // fp31
  int v41; // r3
  int v42; // r8
  idRenderModel *RenderModelFromPresentable; // r3
  idDamageableEntity *v44; // r3
  idProjectile_Grenade *v45; // r3
  idProjectile_Grenade *v46; // r30
  int GameMs; // r3
  char v48; // r27
  idPhysics *v49; // r3
  const idClipModel *v50; // r29
  idPhysics *v51; // r3
  int v52; // r30
  int v53; // r28
  double v54; // fp31
  idPhysics *v55; // r3
  int entityNumber; // r24
  int v57; // r3
  idProp_Moveable *v58; // r3
  idProp_Moveable *v59; // r31
  idPresentable *v60; // r30
  idInventoryCollection *v61; // r3
  const idDeclInventory *decl; // r11
  float v63; // r9
  int v64; // r10
  idInventoryItem **equipped; // r11
  idPresentable *v66; // r11
  const char *v67; // [sp+8h] [-248h]
  int v68; // [sp+Ch] [-244h]
  int v69; // [sp+10h] [-240h]
  int v70; // [sp+14h] [-23Ch]
  int v71; // [sp+18h] [-238h]
  int v72; // [sp+1Ch] [-234h]
  int v73; // [sp+20h] [-230h]
  int v74; // [sp+24h] [-22Ch]
  int v75; // [sp+28h] [-228h]
  int v76; // [sp+2Ch] [-224h]
  int v77; // [sp+30h] [-220h]
  int v78; // [sp+34h] [-21Ch]
  int v79; // [sp+38h] [-218h]
  int v80; // [sp+3Ch] [-214h]
  int v81; // [sp+40h] [-210h]
  int v82; // [sp+44h] [-20Ch]
  int v83; // [sp+48h] [-208h]
  int v84; // [sp+4Ch] [-204h]
  int v85; // [sp+50h] [-200h]
  float v86; // [sp+60h] [-1F0h] BYREF
  float v87; // [sp+64h] [-1ECh]
  float v88; // [sp+68h] [-1E8h]
  idVec3 v89; // [sp+70h] [-1E0h] BYREF
  float z; // [sp+80h] [-1D0h] BYREF
  float x; // [sp+84h] [-1CCh]
  float y; // [sp+88h] [-1C8h]
  idMat3 v93; // [sp+90h] [-1C0h] BYREF
  idProjectileTarget v94; // [sp+C0h] [-190h] BYREF
  idMat3 v95; // [sp+E0h] [-170h] BYREF
  idMat3 v96; // [sp+110h] [-140h] BYREF
  trace_t v97; // [sp+140h] [-110h] BYREF

  if ( item != nullptr && item->decl->dropable && !item->alreadyDropped )
  {
    v4 = 0;
    if ( this->attachments.attachments.num > 0 )
    {
      p_attachments = &this->attachments;
      while ( 1 )
      {
        v6 = idAttachmentCollection::ForIndex(this: p_attachments, index: v4);
        v7 = v6;
        if ( v6 != nullptr )
        {
          p_handle = &v6->handle;
          if ( v6->handle.value != -1 && v6->item == item )
            break;
        }
        if ( ++v4 >= this->attachments.attachments.num )
          return;
      }
      v9 = (idProp_Loot *)gameLocal->SpawnEntityFromDef(
                            this: gameLocal,
                            a2: item->decl->entityDef,
                            a3: -1,
                            a4: -1,
                            a5: -1);
      if ( v9 != nullptr )
      {
        p_droppedItem1 = &this->droppedItem1;
        if ( idEntityPtr<idEntity const>::operator->(this: &this->droppedItem1) == nullptr
          || (v11 = idEntityPtr<idEntity const>::operator->(this: &this->droppedItem1)) == idEntityPtr<idEntity const>::operator->(this: &this->droppedItem1)
          || (p_droppedItem1 = &this->droppedItem2,
              idEntityPtr<idEntity const>::operator->(this: &this->droppedItem2) == nullptr)
          || (v12 = idEntityPtr<idEntity const>::operator->(this: &this->droppedItem2)) == idEntityPtr<idEntity const>::operator->(this: &this->droppedItem2) )
        {
          p_droppedItem1->spawnId.value = (gameLocal->spawnIds.ptr[v9->entityNumber] << 13) | v9->entityNumber;
          if ( (unsigned __int8)idProp_Loot::IsTypeOf(c: v9) != 0 )
          {
            v13 = idProp_Loot::CastTo(c: v9);
            v13->whoDroppedMe.spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
            if ( common->IsMultiplayer(this: common) && actor_allowWeaponDropInCoop.valueInteger == 0 )
              idProp_Usable::SetUsable(this: v13, b: false);
          }
        }
        if ( common->IsMultiplayer(this: common)
          && actor_allowWeaponDropInCoop.valueInteger == 0
          && (unsigned __int8)idProjectile_Grenade::IsTypeOf(c: v9) == 0 )
        {
          presentable = (lobbyUser_t *)v9->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: v9);
            presentable = (lobbyUser_t *)v9->presentable;
          }
          idClientGame::MakePresentableNonReplicated(
            this: clientGame,
            presentable,
            a3: v19,
            a4: v18,
            a5: v17,
            a6: v16,
            a7: v15,
            a8: v14);
        }
        if ( this->afProperties.isActive || (v21 = 0, this->afProperties.isClientAuthoritativeActive) )
          v21 = 1;
        if ( v21 != 0 )
        {
          idAttachmentCollection::GetWorldSpaceAttachmentTransform(
            this: p_attachments,
            handle: p_handle,
            origin: &v89,
            axis: &v95);
          v22 = idAnimator_AF::BodyForJoint(
                  this: &this->afProperties,
                  joint: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v7->jointIndex.value);
          if ( v22 >= 0 )
          {
            Body = (const idVec3 *)idPhysics_AF::GetBody(this: &this->afProperties.physicsObj, id: v22);
            if ( Body != nullptr )
            {
              z = Body[27].z;
              x = Body[28].x;
              y = Body[28].y;
              PointVelocity = (float *)idAFBody::GetPointVelocity(this: (idAFBody *)&v93, result: Body, point: &v89);
              v86 = *PointVelocity;
              v87 = PointVelocity[1];
              v88 = PointVelocity[2];
            }
          }
        }
        else
        {
          TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
          v26 = this->presentable;
          v27 = TreeAnimatorFromPresentable;
          if ( v26 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v26 = this->presentable;
          }
          idPresentable::UpdateModelTransform(this: v26);
          if ( v27 != nullptr && v7->jointIndex.value != 0 )
          {
            v28 = (float)((float)1.0
                        / idGameTimeManager::GetTimeScale(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
            LODWORD(v29) = idGameTimeManager::GetGameHz(this: &clientGame->gameTimeManager, type: GAMETIME_NORMAL);
            *(_QWORD *)&v93.mat[0].x = v29;
            v30 = (float)((float)v29 * (float)v28);
            idAttachmentCollection::GetAttachmentWorldFrameDelta(
              this: p_attachments,
              handle: p_handle,
              tDelta: &v93.mat[2],
              rDelta: &v96);
            v87 = v93.mat[2].y * (float)v30;
            v88 = v93.mat[2].z * (float)v30;
            v86 = v93.mat[2].x * (float)v30;
            v31 = (float)((float)(v86 * v86) + (float)((float)(v88 * v88) + (float)(v87 * v87)));
            if ( v31 > 40000.0 )
            {
              v32 = __fsqrts(v31);
              v86 = (float)(v93.mat[2].x * (float)v30) * (float)((float)200.0 / (float)v32);
              v87 = (float)(v93.mat[2].y * (float)v30) * (float)((float)200.0 / (float)v32);
              v88 = (float)(v93.mat[2].z * (float)v30) * (float)((float)200.0 / (float)v32);
            }
            v33 = idMat3::ToAngularVelocity(this: &v93, result: v96.mat);
            v34 = (float)(v33->y * (float)v30);
            v35 = (float)(v33->z * (float)v30);
            z = (float)v30 * v33->x;
            x = v34;
            y = v35;
          }
          else
          {
            v88 = 0.0;
            v87 = 0.0;
            v86 = 0.0;
            y = 0.0;
            x = 0.0;
            z = 0.0;
          }
          idAttachmentCollection::GetWorldSpaceAttachmentTransform(
            this: p_attachments,
            handle: p_handle,
            origin: &v89,
            axis: &v95);
        }
        idEntity::SetOrigin(this: v9, org: &v89);
        v9->SetAxis(this: v9, a2: &v95);
        Physics = idEntity::GetPhysics(this: v9);
        Physics->SetLinearVelocity(this: Physics, a2: (const idVec3 *)&v86, a3: 0);
        v37 = idEntity::GetPhysics(this: v9);
        v37->SetAngularVelocity(this: v37, a2: (const idVec3 *)&z, a3: 0);
        if ( (unsigned __int8)idProjectile_Grenade::IsTypeOf(c: v9) != 0 )
        {
          v38 = idProjectile_Grenade::CastTo(c: (idProjectile_Grenade *)v9);
          v94.type = TARGET_PRESENTABLE;
          v94.presentable.spawnId = 0;
          v39 = v38;
          v94.pos = vec3_origin;
          v40 = (float)((float)(v86 * v86) + (float)((float)(v88 * v88) + (float)(v87 * v87)));
          v41 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          idProjectile::Launch(
            this: v39,
            attacker_: this,
            start: &v89,
            fireAxis: &v95,
            target: &v94,
            initialSpeed: __fsqrts(v40),
            startTime: v42,
            launchTimeOverride: v41);
        }
        RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: v9);
        if ( RenderModelFromPresentable != nullptr )
          RenderModelFromPresentable->g.firstVisibleFrameCount = 0;
        v44 = idDamageableEntity::CastTo(c: (idDamageableEntity *)v9);
        if ( v44 != nullptr && v44->breakImmediately )
          idDamageableEntity::ApplyRadiusDamage(
            this: v44,
            inflictor: nullptr,
            attacker: nullptr,
            damageDef: gameLocal->damageDecl,
            pos: &v89,
            damageScale: 1.0,
            radiusScale: 1.0,
            radius: 1.0);
        v45 = idProjectile_Grenade::CastTo(c: (idProjectile_Grenade *)v9);
        v46 = v45;
        if ( v45 != nullptr )
        {
          idEntity::BecomeActive(this: v45, flags: 1);
          if ( v46->projectileDecl->notHitscanInfo.grenadeInfo.countDownOnThrow )
          {
            GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            idProjectile_Grenade::StartDetonationTimer(this: v46, startTime: GameMs);
          }
        }
        v48 = 0;
        v49 = idEntity::GetPhysics(this: v9);
        v50 = v49->GetClipModel(this: v49, a2: 0);
        if ( v50 != nullptr )
        {
          v51 = idEntity::GetPhysics(this: v9);
          v52 = v51->GetClipMask(this: v51, a2: -1);
          v53 = 0;
          v54 = (float)(this->clipModelInfo.size.z * (float)0.0625);
          while ( 1 )
          {
            v55 = idEntity::GetPhysics(this: v9);
            entityNumber = v9->entityNumber;
            v57 = v55->GetClipMask(this: v55, a2: -1);
            idClip::Contents(
              this: (idClip *)&v93,
              result: &clientGame->clip,
              a3: &v97,
              start: &v89,
              clipModel: v50,
              startAxis: &v95,
              clipMask: v57,
              passEntityNumber: entityNumber,
              userName: v67,
              a10: v68,
              a11: v69,
              a12: v70,
              a13: v71,
              a14: v72,
              a15: v73,
              a16: v74,
              a17: v75,
              a18: v76,
              a19: v77,
              a20: v78,
              a21: v79,
              a22: v80,
              a23: v81,
              a24: v82,
              a25: v83,
              a26: v84,
              a27: v85,
              a28: 0);
            if ( (v97.c.contentFlags & v52) == 0 )
              break;
            ++v53;
            v89.z = v89.z + (float)v54;
            if ( v53 >= 8 )
              goto LABEL_60;
          }
          if ( v53 > 0 )
            idEntity::SetOrigin(this: v9, org: &v89);
LABEL_60:
          if ( (v97.c.contentFlags & v52) != 0 )
          {
            idEventReceiver::PostEventMS(this: v9, ev: &EV_Remove, time: 0);
            v48 = 1;
          }
        }
        v58 = idProp_Moveable::CastTo(c: v9);
        v59 = v58;
        if ( v58 != nullptr )
        {
          v58->whoDroppedMe.spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
          if ( v48 == 0 )
          {
            if ( (unsigned __int8)idActor::IsLootable(this) != 0 )
            {
              if ( this->dropRandomLoot )
              {
                decl = item->decl;
                v59->removeCondition = decl->removeCondition;
                v59->fadeTimeDelay = decl->fadeDelay;
              }
              else
              {
                idProp_Usable::SetUsable(this: v59, b: false);
                v59->fadeTimeDelay = 0.0;
                v59->removeCondition = REMOVE_CONDITION_TIMEOUT;
                v59->fadeTime = 0.1;
                idEntity::BecomeActive(this: v59, flags: 1);
              }
            }
            else
            {
              v60 = v59->presentable;
              if ( v60 == nullptr )
              {
                idEntity::InitPresentableInternal(this: v59);
                v60 = v59->presentable;
              }
              v61 = v59->GetInventory_2(this: v59);
              idInventoryCollection::FreeInventory(this: v61, owner: v60);
              v59->removeCondition = REMOVE_CONDITION_DORMANT;
              v59->fadeTimeDelay = 0.5;
              idProp_Usable::SetNoBlink(this: v59, noBlink_: true);
            }
          }
        }
        LODWORD(v63) = 15;
        v64 = 0;
        equipped = this->equipped;
        while ( *equipped != item )
        {
          ++v64;
          ++equipped;
          if ( v64 >= 15 )
            goto LABEL_76;
        }
        v63 = *(float *)&v64;
LABEL_76:
        item->alreadyDropped = true;
        if ( LODWORD(v63) != 15 )
        {
          v93.mat[0].y = v63;
          HIBYTE(v93.mat[0].x) = 105;
          gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
          idEventReceiver::PostEventMS(
            this,
            ev: &EV_UnequipAndDeleteDroppedItem,
            time: SLODWORD(v93.mat[0].x),
            arg1: (const idEventArg *)LODWORD(v93.mat[0].z));
          return;
        }
        this->UnequipItem(this, a2: item);
      }
      else
      {
        item->alreadyDropped = true;
        this->UnequipItem(this, a2: item);
      }
      v66 = this->presentable;
      if ( v66 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v66 = this->presentable;
      }
      idInventoryCollection::DeleteInventoryItem(this: &this->inventory, owner: v66, item, count: 1);
    }
  }
}


// ========================================================================
// ?SetRelationshipList@idActor@@QAAXABVidRelationshipList@@@Z
// EA  : 0x82BE9AF0
// RVA : 0x00BE9AF0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::SetRelationshipList(idActor *this, const idRelationshipList *list)
{
  idList<idRelationship,5>::operator=(this: &this->faction.relationships.relationships, other: &list->relationships);
}


// ========================================================================
// ??1idActor@@UAA@XZ
// EA  : 0x82BE9C28
// RVA : 0x00BE9C28
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __fastcall idActor::~idActor(idActor *this)
{
  idLinkList<idActor> *p_actorNode; // r29
  idEntityAttachmentDef *list; // r3

  this->__vftable = (idActor_vtbl *)&idActor::`vftable';
  p_actorNode = &this->actorNode;
  this->actorNode.prev->next = this->actorNode.next;
  this->actorNode.next->prev = this->actorNode.prev;
  this->actorNode.next = &this->actorNode;
  this->actorNode.prev = &this->actorNode;
  this->actorNode.head = &this->actorNode;
  idEntity::StopSound(this, channel: SND_CHANNEL_ANY, peerMask: 0xFFu);
  idInventoryCollection::FreeInventory(this: &this->inventory, owner: nullptr);
  idAttachmentCollection::FreeAttachments(this: &this->attachments);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touching);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->inventory);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)p_actorNode);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attachments);
  idAnimator_WalkIK::~idAnimator_WalkIK(this: &this->walkIK);
  takedownTypes_t::~takedownTypes_t(this: &this->takedownTypes);
  idSmartLootComponent::~idSmartLootComponent(this: &this->smartLoot);
  idDisassembleLoot::~idDisassembleLoot(this: &this->disassembleLoot);
  if ( this->entityAttachments.listStatic == 0 || this->entityAttachments.listStatic == 2 )
  {
    list = this->entityAttachments.list;
    if ( list != nullptr )
      idListArrayDelete<subTimingWordData_t>(ptr: &list->tag, num: this->entityAttachments.size);
    this->entityAttachments.list = nullptr;
    this->entityAttachments.size = 0;
  }
  this->entityAttachments.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->startingInventory);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->faction.relationships);
  idActor::idActorEditable::~idActorEditable(this: &this->actorEditable);
  idStr::FreeData(this: &this->actorConstants.modelInfo.soundJoint);
  idAnimator_AF::~idAnimator_AF(this: &this->afProperties);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$501281
// EA  : 0x82BE9D5C
// RVA : 0x00BE9D5C
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501281()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$501282
// EA  : 0x82BE9D84
// RVA : 0x00BE9D84
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501282()
{
  int v0; // r12

  idAnimator_AF::~idAnimator_AF(this: (idAnimator_AF *)(*(_DWORD *)(v0 - 144 + 164) + 5336));
}


// ========================================================================
// __unwind$501283
// EA  : 0x82BE9DB0
// RVA : 0x00BE9DB0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501283()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 6944));
}


// ========================================================================
// __unwind$501284
// EA  : 0x82BE9DDC
// RVA : 0x00BE9DDC
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501284()
{
  int v0; // r12

  idActor::idActorEditable::~idActorEditable(this: (idActor::idActorEditable *)(*(_DWORD *)(v0 - 144 + 164) + 7128));
}


// ========================================================================
// __unwind$501285
// EA  : 0x82BE9E08
// RVA : 0x00BE9E08
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501285()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 144 + 164) + 7188));
}


// ========================================================================
// __unwind$501286
// EA  : 0x82BE9E34
// RVA : 0x00BE9E34
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501286()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 7240));
}


// ========================================================================
// __unwind$501287
// EA  : 0x82BE9E60
// RVA : 0x00BE9E60
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501287()
{
  int v0; // r12

  idList<idTarget_TestPlayerState::playerState_Job_t,5>::~idList<idTarget_TestPlayerState::playerState_Job_t,5>(this: (vaiAction_t::throwAttachedItem_t *)(*(_DWORD *)(v0 - 144 + 164) + 7256));
}


// ========================================================================
// __unwind$501288
// EA  : 0x82BE9E8C
// RVA : 0x00BE9E8C
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501288()
{
  int v0; // r12

  idDisassembleLoot::~idDisassembleLoot(this: (idDisassembleLoot *)(*(_DWORD *)(v0 - 144 + 164) + 7272));
}


// ========================================================================
// __unwind$501289
// EA  : 0x82BE9EB8
// RVA : 0x00BE9EB8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501289()
{
  int v0; // r12

  idSmartLootComponentActor::~idSmartLootComponentActor(this: (idSmartLootComponentActor *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                          + 7300));
}


// ========================================================================
// __unwind$501290
// EA  : 0x82BE9EE4
// RVA : 0x00BE9EE4
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501290()
{
  int v0; // r12

  takedownTypes_t::~takedownTypes_t(this: (takedownTypes_t *)(*(_DWORD *)(v0 - 144 + 164) + 7328));
}


// ========================================================================
// __unwind$501291
// EA  : 0x82BE9F10
// RVA : 0x00BE9F10
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501291()
{
  int v0; // r12

  idAnimator_WalkIK::~idAnimator_WalkIK(this: (idAnimator_WalkIK *)(*(_DWORD *)(v0 - 144 + 164) + 7648));
}


// ========================================================================
// __unwind$501292
// EA  : 0x82BE9F3C
// RVA : 0x00BE9F3C
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501292()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 9456));
}


// ========================================================================
// __unwind$501293
// EA  : 0x82BE9F68
// RVA : 0x00BE9F68
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501293()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                           + 9476));
}


// ========================================================================
// __unwind$501294
// EA  : 0x82BE9F94
// RVA : 0x00BE9F94
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501294()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 9492));
}


// ========================================================================
// __unwind$501295
// EA  : 0x82BE9FC0
// RVA : 0x00BE9FC0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501295()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 10296));
}


// ========================================================================
// ??0idActor@@QAA@XZ
// EA  : 0x82BEA038
// RVA : 0x00BEA038
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

idActor *__fastcall idActor::idActor(idActor *this)
{
  int v2; // ctr
  float *p_nonPlayerEngagementTimer; // r10
  takedownTypes_t *p_takedownTypes; // r22
  idStr *list; // r3
  idStr *v6; // r3
  idStr *v7; // r3
  idStr *v8; // r3
  idStr *v9; // r3
  idStr *v10; // r3
  idStr *v11; // r3
  idStr *v12; // r3

  idAnimatedEntity::idAnimatedEntity(this);
  this->looted = false;
  this->__vftable = (idActor_vtbl *)&idActor::`vftable';
  this->droppedItem1.spawnId.value = 0x1FFF;
  this->droppedItem2.spawnId.value = 0x1FFF;
  this->attachedLoot.spawnId.value = 0x1FFF;
  v2 = 6;
  this->engagementTracker.nonPlayerEngagementTimer = 0.0;
  this->engagementTracker.lastNonPlayerEngagementTime = 0;
  p_nonPlayerEngagementTimer = &this->engagementTracker.nonPlayerEngagementTimer;
  do
  {
    *++p_nonPlayerEngagementTimer = 0.0;
    --v2;
  }
  while ( v2 != 0 );
  this->engagementTracker.isEngaged = false;
  this->engagementTracker.lastAttacker.spawnId.value = 0x1FFF;
  this->engagementTracker.lastAttackerTime = 0;
  this->spawnPending = false;
  idDeferredVisGrid::idDeferredVisGrid(this: &this->deferredVisGrid);
  idAnimator_AF::idAnimator_AF(this: &this->afProperties);
  this->actorConstants.modelInfo.soundJoint.len = 0;
  this->actorConstants.modelInfo.soundJoint.allocedAndFlag = 20;
  this->actorConstants.modelInfo.soundJoint.data = this->actorConstants.modelInfo.soundJoint.baseBuffer;
  this->actorConstants.modelInfo.soundJoint.baseBuffer[0] = 0;
  this->actorConstants.actorSounds.sndPainSmall = nullptr;
  this->actorConstants.actorSounds.sndPainMedium = nullptr;
  this->actorConstants.actorSounds.sndPainLarge = nullptr;
  this->actorConstants.actorSounds.sndPainHuge = nullptr;
  this->actorConstants.actorSounds.sndFootsteps = nullptr;
  this->actorConstants.actorSounds.sndFoliage = nullptr;
  this->actorConstants.footstepEffectTable_Sprint = nullptr;
  this->actorConstants.footstepEffectTable = nullptr;
  this->actorConstants.footstepEffectTable_SlowWalk = nullptr;
  this->actorConstants.footstepEffectTable_CrouchWalk = nullptr;
  this->actorConstants.footstepEffectTable_Landing = nullptr;
  this->actorConstants.waterInteraction.moveSpeedSlow = 150.0;
  this->actorConstants.waterInteraction.emissionRate = 0.5;
  this->actorConstants.waterInteraction.waterPrtSlow = nullptr;
  this->actorConstants.waterInteraction.waterPrtFast = nullptr;
  this->actorConstants.waterInteraction.waterPrtSplash = nullptr;
  this->actorEditable.damageGroups.granularity = 0;
  this->actorEditable.damageGroups.memTag = 5;
  this->actorEditable.damageGroups.listStatic = 0;
  this->actorEditable.damageGroups.list = nullptr;
  this->actorEditable.damageGroups.size = 0;
  this->actorEditable.damageGroups.num = 0;
  this->actorEditable.radiusDamageJoints.granularity = 0;
  this->actorEditable.radiusDamageJoints.memTag = 5;
  this->actorEditable.radiusDamageJoints.listStatic = 0;
  this->actorEditable.radiusDamageJoints.list = nullptr;
  this->actorEditable.radiusDamageJoints.size = 0;
  this->actorEditable.radiusDamageJoints.num = 0;
  this->npcName.index = -1;
  idFaction::idFaction(this: &this->faction);
  this->tempFaction = nullptr;
  this->tempFactionTime = 0;
  this->shieldBleedThrough = 0.0;
  this->factionType = FACTIONTYPE_NONE;
  this->weaponProficiency = 1.0;
  this->lootable = true;
  this->armorProficiency = 1.0;
  this->dropRandomLoot = true;
  this->mass = 185.0;
  this->startingInventory.list = nullptr;
  this->startingInventory.granularity = 0;
  this->startingInventory.memTag = 5;
  this->startingInventory.listStatic = 0;
  this->startingInventory.size = 0;
  this->startingInventory.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->startingInventory);
  this->entityAttachments.granularity = 0;
  this->entityAttachments.memTag = 5;
  this->entityAttachments.listStatic = 0;
  this->entityAttachments.list = nullptr;
  this->entityAttachments.size = 0;
  this->entityAttachments.num = 0;
  this->disassembleLoot.__vftable = (idDisassembleLoot_vtbl *)&idDisassembleLoot::`vftable';
  this->disassembleLoot.lootBoxes.granularity = 0;
  this->disassembleLoot.lootBoxes.memTag = 5;
  this->disassembleLoot.lootBoxes.listStatic = 0;
  this->disassembleLoot.lootBoxes.list = nullptr;
  this->disassembleLoot.lootBoxes.size = 0;
  this->disassembleLoot.lootBoxes.num = 0;
  this->disassembleLoot.disassembleParticle = nullptr;
  this->disassembleLoot.soundShader = nullptr;
  idSmartLootComponent::idSmartLootComponent(this: &this->smartLoot);
  this->smartLoot.__vftable = (idSmartLootComponentActor_vtbl *)&idSmartLootComponentActor::`vftable';
  p_takedownTypes = &this->takedownTypes;
  takedownTypes_t::takedownTypes_t(this: &this->takedownTypes);
  this->actorVolatile.modelInfo.soundJoint.value = -1;
  this->actorVolatile.pain.jointGroupHandle.value = 0;
  this->actorVolatile.pain.attacker.spawnId.value = 0x1FFF;
  this->actorVolatile.pain.inflictor.spawnId.value = 0x1FFF;
  this->actorVolatile.pain.joint.value = -1;
  this->actorVolatile.pain.type = PAIN_NONE;
  this->actorVolatile.pain.direction = DAMAGEDIR_NONE;
  this->actorVolatile.pain.intensity = DAMAGEINTENSITY_NONE;
  this->actorVolatile.pain.damageDecl = nullptr;
  this->actorVolatile.pain.joint.value = -1;
  this->actorVolatile.aasPosition.valid = false;
  this->actorVolatile.aasPosition.areaNum = 0;
  this->actorVolatile.aasPosition.origin.x = 0.0;
  this->actorVolatile.aasPosition.origin.y = 0.0;
  this->actorVolatile.aasPosition.origin.z = 0.0;
  this->actorVolatile.aasPosition.validOrigin.x = 0.0;
  this->actorVolatile.aasPosition.validOrigin.y = 0.0;
  this->actorVolatile.aasPosition.validOrigin.z = 0.0;
  this->actorVolatile.aasPosition.aas = nullptr;
  idAnimator_WalkIK::idAnimator_WalkIK(this: &this->walkIK);
  this->walkIKDecl = nullptr;
  idMQBuffer::idMQBuffer(this: &this->attachments);
  this->actorNode.owner = nullptr;
  this->actorNode.head = &this->actorNode;
  this->actorNode.next = &this->actorNode;
  this->actorNode.prev = &this->actorNode;
  idInventoryCollection::idInventoryCollection(this: &this->inventory);
  this->damageGroup = -1;
  this->touching.list = nullptr;
  this->touching.granularity = 0;
  this->touching.memTag = 5;
  this->touching.listStatic = 0;
  this->touching.size = 0;
  this->touching.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touching);
  this->actorPhysicsCallbacks.ent.spawnId.value = 0x1FFF;
  this->actorPhysicsCallbacks.af = nullptr;
  this->actorPhysicsCallbacks.__vftable = (idActorPhysicsCallbacks_vtbl *)&idActorPhysicsCallbacks::`vftable';
  idStr::operator=(this: &this->actorConstants.modelInfo.soundJoint, text: &byte_8200D768);
  this->actorConstants.modelInfo.modelOffset = vec3_origin;
  this->actorConstants.perception.eyeOffset = vec3_origin;
  this->actorConstants.perception.crouchedEyeOffset = vec3_origin;
  this->actorConstants.actorClass = ACTORCLASS_MAX;
  this->actorConstants.aimAssistRadiusOverrideScale = 1.0;
  this->actorConstants.useCombatBox = false;
  this->ragdollInfo.slomoStart = 0.0;
  this->actorConstants.footstepEvents = nullptr;
  this->ragdollInfo.slomoEnd = 0.0;
  this->ragdollInfo.velocityTime = 0;
  this->ragdollInfo.jointFrictionDent = 0.0;
  this->attachments.parent = this;
  this->ragdollInfo.jointFrictionStart = 0.0;
  this->actorNode.owner = this;
  this->ragdollInfo.jointFrictionEnd = 0.0;
  this->actorVolatile.modelInfo.soundJoint.value = -1;
  this->ragdollInfo.contactFrictionDent = 0.0;
  this->ragdollInfo.contactFrictionStart = 0.0;
  this->ragdollInfo.contactFrictionEnd = 0.0;
  this->actorVolatile.modelInfo.modelAxis.mat[2].z = 1.0;
  this->actorVolatile.modelInfo.modelAxis.mat[1].y = 1.0;
  this->actorVolatile.modelInfo.modelAxis.mat[0].x = 1.0;
  this->actorVolatile.modelInfo.modelAxis.mat[1].z = 0.0;
  this->actorVolatile.modelInfo.modelAxis.mat[0].z = 0.0;
  this->actorVolatile.modelInfo.modelAxis.mat[0].y = 0.0;
  this->actorVolatile.modelInfo.modelAxis.mat[2].y = 0.0;
  this->actorVolatile.modelInfo.modelAxis.mat[2].x = 0.0;
  this->actorVolatile.modelInfo.modelAxis.mat[1].x = 0.0;
  this->actorVolatile.modelInfo.eyeAxis = mat3_identity;
  this->actorVolatile.modelInfo.eyePos = vec3_origin;
  this->actorVolatile.walkState = WALKSTATE_WALKING;
  this->actorVolatile.damageTakenMultiplier = 1.0;
  this->actorVolatile.weaponReadyState = WEAPONREADY_LOWERED;
  this->actorVolatile.leanState = LEAN_NONE;
  this->actorVolatile.onStairs = false;
  this->actorVolatile.postureChangeTime = -10000;
  this->actorEditable.bodyState = POSTURE_STANDING;
  this->actorEditable.standState = STANDSTATE_DEFAULT;
  this->actorEditable.sitState = SITSTATE_DEFAULT;
  this->actorEditable.turnState = TURNSTATE_DEFAULT;
  this->actorEditable.forceBodyState = false;
  this->actorEditable.isInteracting = false;
  this->actorEditable.mentalState = MENTALSTATE_AWAKE;
  memset(Dst: this->equipped, Val: 0, Size: sizeof(this->equipped));
  if ( this->takedownTypes.stealthSWFWD.listStatic == 0 || this->takedownTypes.stealthSWFWD.listStatic == 2 )
  {
    if ( p_takedownTypes->stealthSWFWD.list != nullptr )
      idListArrayDelete<idStr>(ptr: p_takedownTypes->stealthSWFWD.list, num: this->takedownTypes.stealthSWFWD.size);
    p_takedownTypes->stealthSWFWD.list = nullptr;
    this->takedownTypes.stealthSWFWD.size = 0;
  }
  this->takedownTypes.stealthSWFWD.num = 0;
  if ( this->takedownTypes.stealthSWREV.listStatic == 0 || this->takedownTypes.stealthSWREV.listStatic == 2 )
  {
    list = this->takedownTypes.stealthSWREV.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->takedownTypes.stealthSWREV.size);
    this->takedownTypes.stealthSWREV.list = nullptr;
    this->takedownTypes.stealthSWREV.size = 0;
  }
  this->takedownTypes.stealthSWREV.num = 0;
  if ( this->takedownTypes.stealthDWFWD.listStatic == 0 || this->takedownTypes.stealthDWFWD.listStatic == 2 )
  {
    v6 = this->takedownTypes.stealthDWFWD.list;
    if ( v6 != nullptr )
      idListArrayDelete<idStr>(ptr: v6, num: this->takedownTypes.stealthDWFWD.size);
    this->takedownTypes.stealthDWFWD.list = nullptr;
    this->takedownTypes.stealthDWFWD.size = 0;
  }
  this->takedownTypes.stealthDWFWD.num = 0;
  if ( this->takedownTypes.stealthDWREV.listStatic == 0 || this->takedownTypes.stealthDWREV.listStatic == 2 )
  {
    v7 = this->takedownTypes.stealthDWREV.list;
    if ( v7 != nullptr )
      idListArrayDelete<idStr>(ptr: v7, num: this->takedownTypes.stealthDWREV.size);
    this->takedownTypes.stealthDWREV.list = nullptr;
    this->takedownTypes.stealthDWREV.size = 0;
  }
  this->takedownTypes.stealthDWREV.num = 0;
  if ( this->takedownTypes.counterSWFWD.listStatic == 0 || this->takedownTypes.counterSWFWD.listStatic == 2 )
  {
    v8 = this->takedownTypes.counterSWFWD.list;
    if ( v8 != nullptr )
      idListArrayDelete<idStr>(ptr: v8, num: this->takedownTypes.counterSWFWD.size);
    this->takedownTypes.counterSWFWD.list = nullptr;
    this->takedownTypes.counterSWFWD.size = 0;
  }
  this->takedownTypes.counterSWFWD.num = 0;
  if ( this->takedownTypes.counterSWREV.listStatic == 0 || this->takedownTypes.counterSWREV.listStatic == 2 )
  {
    v9 = this->takedownTypes.counterSWREV.list;
    if ( v9 != nullptr )
      idListArrayDelete<idStr>(ptr: v9, num: this->takedownTypes.counterSWREV.size);
    this->takedownTypes.counterSWREV.list = nullptr;
    this->takedownTypes.counterSWREV.size = 0;
  }
  this->takedownTypes.counterSWREV.num = 0;
  if ( this->takedownTypes.counterDWFWD.listStatic == 0 || this->takedownTypes.counterDWFWD.listStatic == 2 )
  {
    v10 = this->takedownTypes.counterDWFWD.list;
    if ( v10 != nullptr )
      idListArrayDelete<idStr>(ptr: v10, num: this->takedownTypes.counterDWFWD.size);
    this->takedownTypes.counterDWFWD.list = nullptr;
    this->takedownTypes.counterDWFWD.size = 0;
  }
  this->takedownTypes.counterDWFWD.num = 0;
  if ( this->takedownTypes.counterDWREV.listStatic == 0 || this->takedownTypes.counterDWREV.listStatic == 2 )
  {
    v11 = this->takedownTypes.counterDWREV.list;
    if ( v11 != nullptr )
      idListArrayDelete<idStr>(ptr: v11, num: this->takedownTypes.counterDWREV.size);
    this->takedownTypes.counterDWREV.list = nullptr;
    this->takedownTypes.counterDWREV.size = 0;
  }
  this->takedownTypes.counterDWREV.num = 0;
  if ( this->takedownTypes.AITakedowns.listStatic == 0 || this->takedownTypes.AITakedowns.listStatic == 2 )
  {
    v12 = this->takedownTypes.AITakedowns.list;
    if ( v12 != nullptr )
      idListArrayDelete<idStr>(ptr: v12, num: this->takedownTypes.AITakedowns.size);
    this->takedownTypes.AITakedowns.list = nullptr;
    this->takedownTypes.AITakedowns.size = 0;
  }
  this->takedownTypes.AITakedowns.num = 0;
  *((_BYTE *)&this->flags + 2) |= 0x80u;
  return this;
}


// ========================================================================
// __unwind$501773
// EA  : 0x82BEA738
// RVA : 0x00BEA738
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501773()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 192 + 212));
}


// ========================================================================
// __unwind$501774_0
// EA  : 0x82BEA760
// RVA : 0x00BEA760
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501774_0()
{
  int v0; // r12

  idAnimator_AF::~idAnimator_AF(this: (idAnimator_AF *)(*(_DWORD *)(v0 - 192 + 212) + 5336));
}


// ========================================================================
// __unwind$501775
// EA  : 0x82BEA78C
// RVA : 0x00BEA78C
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501775()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 6944));
}


// ========================================================================
// __unwind$502056
// EA  : 0x82BEA7B8
// RVA : 0x00BEA7B8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_502056()
{
  int v0; // r12

  idList<idDamageGroup,5>::~idList<idDamageGroup,5>(this: (idList<idDamageGroup,5> *)(*(_DWORD *)(v0 - 192 + 80) + 24));
}


// ========================================================================
// __unwind$501776
// EA  : 0x82BEA7E4
// RVA : 0x00BEA7E4
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501776()
{
  int v0; // r12

  idActor::idActorEditable::~idActorEditable(this: (idActor::idActorEditable *)(*(_DWORD *)(v0 - 192 + 212) + 7128));
}


// ========================================================================
// __unwind$501777
// EA  : 0x82BEA810
// RVA : 0x00BEA810
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501777()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 192 + 212) + 7188));
}


// ========================================================================
// __unwind$501778
// EA  : 0x82BEA83C
// RVA : 0x00BEA83C
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501778()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 7240));
}


// ========================================================================
// __unwind$501779
// EA  : 0x82BEA868
// RVA : 0x00BEA868
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501779()
{
  int v0; // r12

  idList<idTarget_TestPlayerState::playerState_Job_t,5>::~idList<idTarget_TestPlayerState::playerState_Job_t,5>(this: (vaiAction_t::throwAttachedItem_t *)(*(_DWORD *)(v0 - 192 + 212) + 7256));
}


// ========================================================================
// __unwind$502129
// EA  : 0x82BEA894
// RVA : 0x00BEA894
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_502129()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 192 + 84));
}


// ========================================================================
// __unwind$501780
// EA  : 0x82BEA8BC
// RVA : 0x00BEA8BC
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501780()
{
  int v0; // r12

  idDisassembleLoot::~idDisassembleLoot(this: (idDisassembleLoot *)(*(_DWORD *)(v0 - 192 + 212) + 7272));
}


// ========================================================================
// __unwind$501781
// EA  : 0x82BEA8E8
// RVA : 0x00BEA8E8
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501781()
{
  int v0; // r12

  idSmartLootComponentActor::~idSmartLootComponentActor(this: (idSmartLootComponentActor *)(*(_DWORD *)(v0 - 192 + 212)
                                                                                          + 7300));
}


// ========================================================================
// __unwind$501782
// EA  : 0x82BEA914
// RVA : 0x00BEA914
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501782()
{
  int v0; // r12

  takedownTypes_t::~takedownTypes_t(this: (takedownTypes_t *)(*(_DWORD *)(v0 - 192 + 212) + 7328));
}


// ========================================================================
// __unwind$501783
// EA  : 0x82BEA940
// RVA : 0x00BEA940
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501783()
{
  int v0; // r12

  idAnimator_WalkIK::~idAnimator_WalkIK(this: (idAnimator_WalkIK *)(*(_DWORD *)(v0 - 192 + 212) + 7648));
}


// ========================================================================
// __unwind$501784
// EA  : 0x82BEA96C
// RVA : 0x00BEA96C
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501784()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 9456));
}


// ========================================================================
// __unwind$501785
// EA  : 0x82BEA998
// RVA : 0x00BEA998
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501785()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 192 + 212)
                                                                                           + 9476));
}


// ========================================================================
// __unwind$501786
// EA  : 0x82BEA9C4
// RVA : 0x00BEA9C4
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501786()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 9492));
}


// ========================================================================
// __unwind$501787
// EA  : 0x82BEA9F0
// RVA : 0x00BEA9F0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void _unwind_501787()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 10296));
}


// ========================================================================
// `dynamic initializer for 'actor_debugFailedDrop''
// EA  : 0x83374658
// RVA : 0x01374658
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__actor_debugFailedDrop__()
{
  idCVar::idCVar(
    this: &actor_debugFailedDrop,
    name: "actor_debugFailedDrop",
    value: "0",
    flags: 1,
    description: "1 to draw volumes for failed actor drops",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__actor_debugFailedDrop__);
}


// ========================================================================
// `dynamic initializer for 'actor_allowWeaponDropInCoop''
// EA  : 0x833746B0
// RVA : 0x013746B0
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__actor_allowWeaponDropInCoop__()
{
  idCVar::idCVar(
    this: &actor_allowWeaponDropInCoop,
    name: "actor_allowWeaponDropInCoop",
    value: "0",
    flags: 1,
    description: "if true, Actors are allowed to drop their weapons on death in coop.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__actor_allowWeaponDropInCoop__);
}


// ========================================================================
// `dynamic initializer for 'actor_allowLootingInCoop''
// EA  : 0x83374708
// RVA : 0x01374708
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__actor_allowLootingInCoop__()
{
  idCVar::idCVar(
    this: &actor_allowLootingInCoop,
    name: "actor_allowLootingInCoop",
    value: "0",
    flags: 1,
    description: "if true, looting corpses is allowed in coop.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__actor_allowLootingInCoop__);
}


// ========================================================================
// `dynamic initializer for 'pm_walkIKBlendInMS''
// EA  : 0x83374760
// RVA : 0x01374760
// PDB : w:\tech5\tungsten\game\entities\actor.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_walkIKBlendInMS__()
{
  idCVar::idCVar(
    this: &pm_walkIKBlendInMS,
    name: "pm_walkIKBlendInMS",
    value: "3000",
    flags: 2,
    description: "Blend in time for player leg IK after jumping",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_walkIKBlendInMS__);
}

