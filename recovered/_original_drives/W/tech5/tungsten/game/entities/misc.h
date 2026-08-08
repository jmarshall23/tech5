
// ========================================================================
// ??1idFuncShadowCaster@@UAA@XZ
// EA  : 0x824FA7A0
// RVA : 0x004FA7A0
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void __fastcall idFuncShadowCaster::~idFuncShadowCaster(idFuncShadowCaster *this)
{
  this->__vftable = (idFuncShadowCaster_vtbl *)&idFuncShadowCaster::`vftable';
  idStr::FreeData(this: &this->shadowModelName);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$583665
// EA  : 0x824FA7F4
// RVA : 0x004FA7F4
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void _unwind_583665()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idDynamicEntity@@UAA@XZ
// EA  : 0x82C497B0
// RVA : 0x00C497B0
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void __fastcall idDynamicEntity::~idDynamicEntity(idDynamicEntity *this)
{
  this->__vftable = (idDynamicEntity_vtbl *)&idDynamicEntity::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// ??1idReferenceMap@@UAA@XZ
// EA  : 0x82C704F8
// RVA : 0x00C704F8
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void __fastcall idReferenceMap::~idReferenceMap(idReferenceMap *this)
{
  this->__vftable = (idReferenceMap_vtbl *)&idReferenceMap::`vftable';
  idStr::FreeData(this: &this->mapname);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$497461
// EA  : 0x82C7054C
// RVA : 0x00C7054C
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void _unwind_497461()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idDebrisEntity@@UAA@XZ
// EA  : 0x82C73908
// RVA : 0x00C73908
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void __fastcall idDebrisEntity::~idDebrisEntity(idDebrisEntity *this)
{
  this->__vftable = (idDebrisEntity_vtbl *)&idDebrisEntity::`vftable';
  idPhysics_RigidBody::~idPhysics_RigidBody(this: &this->physicsObj);
  this->__vftable = (idDebrisEntity_vtbl *)&idDynamicEntity::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$500517
// EA  : 0x82C73968
// RVA : 0x00C73968
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void _unwind_500517()
{
  int v0; // r12

  idDynamicEntity::~idDynamicEntity(this: *(idDynamicEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idAnnouncementManager@@UAA@XZ
// EA  : 0x82C770D8
// RVA : 0x00C770D8
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void __fastcall idAnnouncementManager::~idAnnouncementManager(idAnnouncementManager *this)
{
  this->__vftable = (idAnnouncementManager_vtbl *)&idAnnouncementManager::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->announcementsVO);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->announcements);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$504716_0
// EA  : 0x82C77134
// RVA : 0x00C77134
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void _unwind_504716_0()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$504717
// EA  : 0x82C7715C
// RVA : 0x00C7715C
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void _unwind_504717()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 828));
}


// ========================================================================
// ??1idCoopStartingInventory@@UAA@XZ
// EA  : 0x82C771F0
// RVA : 0x00C771F0
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void __fastcall idCoopStartingInventory::~idCoopStartingInventory(idCoopStartingInventory *this)
{
  this->__vftable = (idCoopStartingInventory_vtbl *)&idCoopStartingInventory::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->playerTwoItemList);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->playerOneItemList);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$504756
// EA  : 0x82C7724C
// RVA : 0x00C7724C
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void _unwind_504756()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$504757
// EA  : 0x82C77274
// RVA : 0x00C77274
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void _unwind_504757()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 800));
}


// ========================================================================
// ??1idInventoryStorage@@UAA@XZ
// EA  : 0x82C77F08
// RVA : 0x00C77F08
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void __fastcall idInventoryStorage::~idInventoryStorage(idInventoryStorage *this)
{
  this->__vftable = (idInventoryStorage_vtbl *)&idInventoryStorage::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->startingInventory);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->inventory);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$505392
// EA  : 0x82C77F64
// RVA : 0x00C77F64
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void _unwind_505392()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$505393
// EA  : 0x82C77F8C
// RVA : 0x00C77F8C
// PDB : w:\tech5\tungsten\game\entities\misc.h
// ========================================================================

void _unwind_505393()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 800));
}

