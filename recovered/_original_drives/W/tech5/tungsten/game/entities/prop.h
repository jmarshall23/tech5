
// ========================================================================
// ?GetInventory@idProp_Moveable@@UBAPBVidInventoryCollection@@XZ
// EA  : 0x824E36A0
// RVA : 0x004E36A0
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

const idInventoryCollection *__fastcall idProp_Moveable::GetInventory(idProp_Moveable *this)
{
  return &this->inventory;
}


// ========================================================================
// ??0idProp_AmmoRefill@@QAA@XZ
// EA  : 0x824FC200
// RVA : 0x004FC200
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

idProp_AmmoRefill *__fastcall idProp_AmmoRefill::idProp_AmmoRefill(idProp_AmmoRefill *this)
{
  idProp_Moveable::idProp_Moveable(this);
  this->useSound = nullptr;
  this->__vftable = (idProp_AmmoRefill_vtbl *)&idProp_AmmoRefill::`vftable';
  this->caseContents.list = nullptr;
  this->caseContents.granularity = 0;
  this->caseContents.memTag = 5;
  this->caseContents.listStatic = 0;
  this->caseContents.size = 0;
  this->caseContents.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->caseContents);
  return this;
}


// ========================================================================
// __unwind$585944
// EA  : 0x824FC278
// RVA : 0x004FC278
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_585944()
{
  int v0; // r12

  idProp_Moveable::~idProp_Moveable(this: *(idProp_Moveable **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idProp_AmmoRefill@@UAA@XZ
// EA  : 0x824FC2A8
// RVA : 0x004FC2A8
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void __fastcall idProp_AmmoRefill::~idProp_AmmoRefill(idProp_AmmoRefill *this)
{
  this->__vftable = (idProp_AmmoRefill_vtbl *)&idProp_AmmoRefill::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->caseContents);
  idProp_Moveable::~idProp_Moveable(this);
}


// ========================================================================
// __unwind$585965
// EA  : 0x824FC2FC
// RVA : 0x004FC2FC
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_585965()
{
  int v0; // r12

  idProp_Moveable::~idProp_Moveable(this: *(idProp_Moveable **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idUse@@UAA@XZ
// EA  : 0x8251D030
// RVA : 0x0051D030
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void __fastcall idUse::~idUse(idUse *this)
{
  this->__vftable = (idUse_vtbl *)&idUse::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// ??0idProp_Loot@@QAA@XZ
// EA  : 0x825588A0
// RVA : 0x005588A0
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

idProp_Loot *__fastcall idProp_Loot::idProp_Loot(idProp_Loot *this)
{
  idProp_Moveable::idProp_Moveable(this);
  this->__vftable = (idProp_Loot_vtbl *)&idProp_Loot::`vftable';
  this->randomLootPool.list = nullptr;
  this->randomLootPool.granularity = 0;
  this->randomLootPool.memTag = 5;
  this->randomLootPool.listStatic = 0;
  this->randomLootPool.size = 0;
  this->randomLootPool.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->randomLootPool);
  this->loot.loot.list = nullptr;
  this->loot.loot.granularity = 0;
  this->loot.loot.memTag = 5;
  this->loot.loot.listStatic = 0;
  this->loot.loot.size = 0;
  this->loot.loot.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->loot);
  this->hasBeenLooted = false;
  this->maxItemsToGive = 0;
  this->lootedSound = nullptr;
  return this;
}


// ========================================================================
// __unwind$568847
// EA  : 0x82558928
// RVA : 0x00558928
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_568847()
{
  int v0; // r12

  idProp_Moveable::~idProp_Moveable(this: *(idProp_Moveable **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$568848
// EA  : 0x82558950
// RVA : 0x00558950
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_568848()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 7000));
}


// ========================================================================
// ??1idProp_Loot@@UAA@XZ
// EA  : 0x82558988
// RVA : 0x00558988
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void __fastcall idProp_Loot::~idProp_Loot(idProp_Loot *this)
{
  this->__vftable = (idProp_Loot_vtbl *)&idProp_Loot::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->loot);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->randomLootPool);
  idProp_Moveable::~idProp_Moveable(this);
}


// ========================================================================
// __unwind$568889
// EA  : 0x825589E4
// RVA : 0x005589E4
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_568889()
{
  int v0; // r12

  idProp_Moveable::~idProp_Moveable(this: *(idProp_Moveable **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$568890
// EA  : 0x82558A0C
// RVA : 0x00558A0C
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_568890()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 7000));
}


// ========================================================================
// ??1idProp_ContinuallyUsed@@UAA@XZ
// EA  : 0x82C0B700
// RVA : 0x00C0B700
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void __fastcall idProp_ContinuallyUsed::~idProp_ContinuallyUsed(idProp_ContinuallyUsed *this)
{
  this->__vftable = (idProp_ContinuallyUsed_vtbl *)&idProp_ContinuallyUsed::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triggerFail);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triggerSuccess);
  idProp_Usable::~idProp_Usable(this);
}


// ========================================================================
// __unwind$488153
// EA  : 0x82C0B75C
// RVA : 0x00C0B75C
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_488153()
{
  int v0; // r12

  idProp_Usable::~idProp_Usable(this: *(idProp_Usable **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488154
// EA  : 0x82C0B784
// RVA : 0x00C0B784
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_488154()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 5276));
}


// ========================================================================
// ?IsEverUsable@idProp_ContinuallyUsed@@UBA_NPBVidEntity@@@Z
// EA  : 0x82C0B7B0
// RVA : 0x00C0B7B0
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

BOOL __fastcall idProp_ContinuallyUsed::IsEverUsable(idProp_ContinuallyUsed *this, idActor *activator)
{
  idActor *user; // r11

  return idProp_Usable::IsEverUsable(this, activator)
      && ((user = this->user) == nullptr || user == activator)
      && (this->usedState < 1.0 || !this->finishes);
}


// ========================================================================
// ??1idProp_MissionPin@@UAA@XZ
// EA  : 0x82CA2810
// RVA : 0x00CA2810
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void __fastcall idProp_MissionPin::~idProp_MissionPin(idProp_MissionPin *this)
{
  this->__vftable = (idProp_MissionPin_vtbl *)&idProp_MissionPin::`vftable';
  keyBindings_t::~keyBindings_t(this: (testReportField_t *)&this->spawn);
  idStr::FreeData(this: &this->fromLayers);
  this->__vftable = (idProp_MissionPin_vtbl *)&idUse::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$501689
// EA  : 0x82CA2878
// RVA : 0x00CA2878
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_501689()
{
  int v0; // r12

  idUse::~idUse(this: *(idUse **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$501690
// EA  : 0x82CA28A0
// RVA : 0x00CA28A0
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_501690()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 872));
}


// ========================================================================
// ??0effectsDef_t@idProp_BreakableLoot@@QAA@XZ
// EA  : 0x82CA5B20
// RVA : 0x00CA5B20
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

idProp_BreakableLoot::effectsDef_t *__fastcall idProp_BreakableLoot::effectsDef_t::effectsDef_t(
        idProp_BreakableLoot::effectsDef_t *this)
{
  double z; // fp12

  this->parts.list = nullptr;
  this->parts.granularity = 0;
  this->parts.memTag = 5;
  this->parts.listStatic = 0;
  this->parts.size = 0;
  this->parts.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->parts);
  this->splinters.list = nullptr;
  this->splinters.granularity = 0;
  this->splinters.memTag = 5;
  this->splinters.listStatic = 0;
  this->splinters.size = 0;
  this->splinters.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splinters);
  this->impulseDir.x = vec3_up.x;
  this->impulseDir.y = vec3_up.y;
  z = vec3_up.z;
  this->lootParticle = nullptr;
  this->impulseDir.z = z;
  this->minSplinters = 2;
  this->impulseMag = 500.0;
  this->maxSplinters = 5;
  this->breakableFadeTime = -1.0;
  this->soundBreak = nullptr;
  this->breakableFadeDelay = -1.0;
  this->idleParticle = nullptr;
  this->fadeTime = 0.0;
  this->highlightColor = HIGHLIGHT_COLOR_LOOT;
  this->fadeDelay = 0.0;
  return this;
}


// ========================================================================
// __unwind$506198
// EA  : 0x82CA5BF8
// RVA : 0x00CA5BF8
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_506198()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 20));
}


// ========================================================================
// ??0inventoryDef_t@idProp_BreakableLoot@@QAA@XZ
// EA  : 0x82CA5C28
// RVA : 0x00CA5C28
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

idProp_BreakableLoot::inventoryDef_t *__fastcall idProp_BreakableLoot::inventoryDef_t::inventoryDef_t(
        idProp_BreakableLoot::inventoryDef_t *this)
{
  this->randomLootPool.list = nullptr;
  this->randomLootPool.granularity = 0;
  this->randomLootPool.memTag = 5;
  this->randomLootPool.listStatic = 0;
  this->randomLootPool.size = 0;
  this->randomLootPool.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->requiredJobDecl.len = 0;
  this->requiredJobDecl.allocedAndFlag = 20;
  this->requiredJobDecl.data = this->requiredJobDecl.baseBuffer;
  this->requiredJobDecl.baseBuffer[0] = 0;
  this->randomLootQuantity = -1;
  this->requiredInvDecl = nullptr;
  this->requiredJobStatus = JOBSTATUS_ACCEPTED;
  return this;
}


// ========================================================================
// ??1idCombiner@@UAA@XZ
// EA  : 0x82CA5CB8
// RVA : 0x00CA5CB8
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void __fastcall idCombiner::~idCombiner(idCombiner *this)
{
  this->__vftable = (idCombiner_vtbl *)&idCombiner::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->onActivate);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->neededItemsDecl);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->neededItems);
  this->__vftable = (idCombiner_vtbl *)&idUse::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$506274
// EA  : 0x82CA5D28
// RVA : 0x00CA5D28
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_506274()
{
  int v0; // r12

  idUse::~idUse(this: *(idUse **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$506275
// EA  : 0x82CA5D50
// RVA : 0x00CA5D50
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_506275()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 856));
}


// ========================================================================
// __unwind$506276
// EA  : 0x82CA5D7C
// RVA : 0x00CA5D7C
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_506276()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 876));
}


// ========================================================================
// ?GetSmartLootComponent@idPropSmartLoot@@UAAPAVidSmartLootComponent@@XZ
// EA  : 0x82CA6140
// RVA : 0x00CA6140
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

const idSmartLootComponent *__fastcall idPropSmartLoot::GetSmartLootComponent(idPropSmartLoot *this)
{
  return &this->smartLootComponent;
}


// ========================================================================
// ?GetInventory@idPropSmartLoot@@UAAPAVidInventoryCollection@@XZ
// EA  : 0x82CA6148
// RVA : 0x00CA6148
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

const idInventoryCollection *__fastcall idPropSmartLoot::GetInventory(idPropSmartLoot *this)
{
  return &this->inventory;
}


// ========================================================================
// ?GetInventory@idProp_BreakableLoot@@UBAPBVidInventoryCollection@@XZ
// EA  : 0x82CA7288
// RVA : 0x00CA7288
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

const idInventoryCollection *__fastcall idProp_BreakableLoot::GetInventory(idProp_BreakableLoot *this)
{
  return &this->inventory;
}


// ========================================================================
// ?GetHealth@idProp_Breakable@@UBAMXZ
// EA  : 0x82CA7DA8
// RVA : 0x00CA7DA8
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

float __fastcall idProp_Breakable::GetHealth(idProp_Breakable *this)
{
  double health; // fp1

  health = this->health;
  return *((float *)&health + 1);
}


// ========================================================================
// ?SetHealth@idProp_Breakable@@UAAXM@Z
// EA  : 0x82CA7DB0
// RVA : 0x00CA7DB0
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void __fastcall idProp_Breakable::SetHealth(idProp_Breakable *this, double h)
{
  this->health = h;
}


// ========================================================================
// ??1idProp_Breakable@@UAA@XZ
// EA  : 0x82CA8C90
// RVA : 0x00CA8C90
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void __fastcall idProp_Breakable::~idProp_Breakable(idProp_Breakable *this)
{
  this->__vftable = (idProp_Breakable_vtbl *)&idProp_Breakable::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->ammoDamage);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnSplinters);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnParts);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splinters);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->parts);
  idProp_Moveable::~idProp_Moveable(this);
}


// ========================================================================
// __unwind$508801
// EA  : 0x82CA8D04
// RVA : 0x00CA8D04
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_508801()
{
  int v0; // r12

  idProp_Moveable::~idProp_Moveable(this: *(idProp_Moveable **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$508802
// EA  : 0x82CA8D2C
// RVA : 0x00CA8D2C
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_508802()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 7016));
}


// ========================================================================
// __unwind$508803
// EA  : 0x82CA8D58
// RVA : 0x00CA8D58
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_508803()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 7032));
}


// ========================================================================
// __unwind$508804
// EA  : 0x82CA8D84
// RVA : 0x00CA8D84
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_508804()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 7100));
}


// ========================================================================
// __unwind$508805
// EA  : 0x82CA8DB0
// RVA : 0x00CA8DB0
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_508805()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 7116));
}


// ========================================================================
// ??1idProp_ExplosivePlunger@@UAA@XZ
// EA  : 0x82CA8EB0
// RVA : 0x00CA8EB0
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void __fastcall idProp_ExplosivePlunger::~idProp_ExplosivePlunger(idProp_ExplosivePlunger *this)
{
  this->__vftable = (idProp_ExplosivePlunger_vtbl *)&idProp_ExplosivePlunger::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activateList);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->explosivePacks);
  idProp_Moveable::~idProp_Moveable(this);
}


// ========================================================================
// __unwind$508916
// EA  : 0x82CA8F0C
// RVA : 0x00CA8F0C
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_508916()
{
  int v0; // r12

  idProp_Moveable::~idProp_Moveable(this: *(idProp_Moveable **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$508917
// EA  : 0x82CA8F34
// RVA : 0x00CA8F34
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

void _unwind_508917()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 7008));
}


// ========================================================================
// ?DormantBegin@idProp_VehicleJump@@UAAXXZ
// EA  : 0x82CA97B0
// RVA : 0x00CA97B0
// PDB : w:\tech5\tungsten\game\entities\prop.h
// ========================================================================

// attributes: thunk
void __fastcall idProp_VehicleJump::DormantBegin(idProp_VehicleJump *this)
{
  idEntity::DormantBegin(this);
}

