
// ========================================================================
// ??0idLoot_ItemCase@@QAA@XZ
// EA  : 0x824FC000
// RVA : 0x004FC000
// PDB : w:\tech5\tungsten\game\entities\loot.h
// ========================================================================

idLoot_ItemCase *__fastcall idLoot_ItemCase::idLoot_ItemCase(idLoot_ItemCase *this)
{
  idEntity::idEntity(this);
  this->triggerTargets = false;
  this->__vftable = (idLoot_ItemCase_vtbl *)&idLoot_ItemCase::`vftable';
  this->useSound = nullptr;
  this->caseContents.list = nullptr;
  this->caseContents.granularity = 0;
  this->caseContents.memTag = 5;
  this->caseContents.listStatic = 0;
  this->caseContents.size = 0;
  this->caseContents.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->caseContents);
  this->foundSound = nullptr;
  this->ammoCalledOut = false;
  return this;
}


// ========================================================================
// __unwind$585861
// EA  : 0x824FC06C
// RVA : 0x004FC06C
// PDB : w:\tech5\tungsten\game\entities\loot.h
// ========================================================================

void _unwind_585861()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idLoot_ItemCase@@UAA@XZ
// EA  : 0x824FC0A0
// RVA : 0x004FC0A0
// PDB : w:\tech5\tungsten\game\entities\loot.h
// ========================================================================

void __fastcall idLoot_ItemCase::~idLoot_ItemCase(idLoot_ItemCase *this)
{
  this->__vftable = (idLoot_ItemCase_vtbl *)&idLoot_ItemCase::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->caseContents);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$585882
// EA  : 0x824FC0F4
// RVA : 0x004FC0F4
// PDB : w:\tech5\tungsten\game\entities\loot.h
// ========================================================================

void _unwind_585882()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?Looted@idDisassembleLoot@@QAAXXZ
// EA  : 0x82E76DD8
// RVA : 0x00E76DD8
// PDB : w:\tech5\tungsten\game\entities\loot.h
// ========================================================================

void __fastcall idDisassembleLoot::Looted(idDisassembleLoot *this)
{
  char *list; // r3

  if ( this->lootBoxes.listStatic == 0 || this->lootBoxes.listStatic == 2 )
  {
    list = (char *)this->lootBoxes.list;
    if ( list != nullptr )
      idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(ptr: list, num: this->lootBoxes.size);
    this->lootBoxes.list = nullptr;
    this->lootBoxes.size = 0;
  }
  this->lootBoxes.num = 0;
}

