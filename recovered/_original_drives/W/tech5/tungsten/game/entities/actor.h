
// ========================================================================
// ?HealthRatio@idDamageGroup@@QBAMXZ
// EA  : 0x829F0958
// RVA : 0x009F0958
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

float __fastcall idDamageGroup::HealthRatio(idDamageGroup *this)
{
  double v1; // fp1

  v1 = 0.0;
  if ( this->maxHealth > 0.0 )
    v1 = (float)(this->health / this->maxHealth);
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?GetWalkState@idActor@@UBA?AW4walkState_t@@XZ
// EA  : 0x829F0978
// RVA : 0x009F0978
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

walkState_t __fastcall idActor::GetWalkState(idActor *this)
{
  return this->actorVolatile.walkState;
}


// ========================================================================
// ?SetWalkState@idActor@@UAAXW4walkState_t@@@Z
// EA  : 0x829F0980
// RVA : 0x009F0980
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

void __fastcall idActor::SetWalkState(idActor *this, walkState_t state)
{
  this->actorVolatile.walkState = state;
}


// ========================================================================
// ?GetAF@idActor@@UBAPBVidAnimator_AF@@XZ
// EA  : 0x82A25BA0
// RVA : 0x00A25BA0
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

const idAnimator_AF *__fastcall idActor::GetAF(idActor *this)
{
  return &this->afProperties;
}


// ========================================================================
// ?GetLastEyePos@idActor@@UBAXAAVidVec3@@@Z
// EA  : 0x82A25BA8
// RVA : 0x00A25BA8
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

void __fastcall idActor::GetLastEyePos(idActor *this, idVec3 *eyePos)
{
  *eyePos = this->actorVolatile.modelInfo.eyePos;
}


// ========================================================================
// ?GetEyeAxis@idActor@@UBAXAAVidMat3@@@Z
// EA  : 0x82A25BC8
// RVA : 0x00A25BC8
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

void __fastcall idActor::GetEyeAxis(idActor *this, idMat3 *eyeAxis)
{
  *eyeAxis = this->actorVolatile.modelInfo.eyeAxis;
}


// ========================================================================
// ?SetEyeAxis@idActor@@UAAXABVidMat3@@@Z
// EA  : 0x82A25C18
// RVA : 0x00A25C18
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

void __fastcall idActor::SetEyeAxis(idActor *this, const idMat3 *eyeAxis)
{
  this->actorVolatile.modelInfo.eyeAxis = *eyeAxis;
}


// ========================================================================
// ?GetInventory@idActor@@UAAPAVidInventoryCollection@@XZ
// EA  : 0x82A25C68
// RVA : 0x00A25C68
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

const idInventoryCollection *__fastcall idActor::GetInventory(idActor *this)
{
  return &this->inventory;
}


// ========================================================================
// ?GetSmartLootComponent@idActor@@UBAPBVidSmartLootComponent@@XZ
// EA  : 0x82A25C70
// RVA : 0x00A25C70
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

idSmartLootComponentActor *__fastcall idActor::GetSmartLootComponent(idActor *this)
{
  BOOL dropRandomLoot; // r11
  idSmartLootComponentActor *result; // r3

  dropRandomLoot = this->dropRandomLoot;
  result = &this->smartLoot;
  if ( !dropRandomLoot )
    return nullptr;
  return result;
}


// ========================================================================
// ?GetAttachments@idActor@@UAAPAVidAttachmentCollection@@XZ
// EA  : 0x82A25C88
// RVA : 0x00A25C88
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

const idAttachmentCollection *__fastcall idActor::GetAttachments(idActor *this)
{
  return &this->attachments;
}


// ========================================================================
// ?GetTriggerTouchList@idActor@@UAAPAV?$idList@V?$idEntityPtr@VidEntity@@@@$04@@XZ
// EA  : 0x82A25C90
// RVA : 0x00A25C90
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

const idList<idEntityPtr<idEntity>,5> *__fastcall idActor::GetTriggerTouchList(idActor *this)
{
  return &this->touching;
}


// ========================================================================
// ??1idDragEntity@@QAA@XZ
// EA  : 0x82A25C98
// RVA : 0x00A25C98
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

idActor *__fastcall idDragEntity::~idDragEntity(idActor *this, idStrId *result)
{
  this->__vftable = (idActor_vtbl *)-1;
  return this;
}


// ========================================================================
// ?GetPosture@idActor@@UBA?AW4posture_t@@XZ
// EA  : 0x82A25CA8
// RVA : 0x00A25CA8
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

posture_t __fastcall idActor::GetPosture(idActor *this)
{
  return this->actorEditable.bodyState;
}


// ========================================================================
// ?GetLeanState@idActor@@UBA?AW4leanState_t@@XZ
// EA  : 0x82A25CB0
// RVA : 0x00A25CB0
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

leanState_t __fastcall idActor::GetLeanState(idActor *this)
{
  return this->actorVolatile.leanState;
}


// ========================================================================
// ?SetLeanState@idActor@@UAAXW4leanState_t@@@Z
// EA  : 0x82A25CB8
// RVA : 0x00A25CB8
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

void __fastcall idActor::SetLeanState(idActor *this, leanState_t _leanState)
{
  this->actorVolatile.leanState = _leanState;
}


// ========================================================================
// ?GetWeaponReadyState@idActor@@UBA?AW4weaponReadyState_t@@XZ
// EA  : 0x82A25CC0
// RVA : 0x00A25CC0
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

weaponReadyState_t __fastcall idActor::GetWeaponReadyState(idActor *this)
{
  return this->actorVolatile.weaponReadyState;
}


// ========================================================================
// ?SetWeaponReadyState@idActor@@UAAXW4weaponReadyState_t@@@Z
// EA  : 0x82A25CC8
// RVA : 0x00A25CC8
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

void __fastcall idActor::SetWeaponReadyState(idActor *this, weaponReadyState_t state)
{
  this->actorVolatile.weaponReadyState = state;
}


// ========================================================================
// ?GetMaxSpeed@idVehicle@@UBAMXZ
// EA  : 0x82A25CD0
// RVA : 0x00A25CD0
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

float __fastcall idVehicle::GetMaxSpeed(idVoiceGameEvent *this, const int curTimeMS, const int gameMsPerFrame)
{
  double v3; // fp1

  v3 = 1.0;
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?GetDroppedItem1@idActor@@QBAPAVidEntity@@XZ
// EA  : 0x82BB7260
// RVA : 0x00BB7260
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

idEntity *__fastcall idActor::GetDroppedItem1(idActor *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->droppedItem1.spawnId.value;
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
// ?GetDeclInfo@idDeclFootstepEvents@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BCCA98
// RVA : 0x00BCCA98
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

idDeclInfoTemplate<idDeclFootstepEvents> *__fastcall idDeclFootstepEvents::GetDeclInfo(idDeclFootstepEvents *this)
{
  return &idDeclFootstepEvents::resourceList;
}


// ========================================================================
// ?IsDead@idActor@@UBA_NXZ
// EA  : 0x82BE9FF0
// RVA : 0x00BE9FF0
// PDB : w:\tech5\tungsten\game\entities\actor.h
// ========================================================================

BOOL __fastcall idActor::IsDead(idActor *this)
{
  const idBaseHealth *v1; // r3

  v1 = this->GetHealthComponent(this);
  return v1->IsDead_Impl(this: (idBaseHealth *)v1);
}

