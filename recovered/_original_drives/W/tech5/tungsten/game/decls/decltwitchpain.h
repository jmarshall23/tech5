
// ========================================================================
// ??0idTwitchPain_WeaponGroup@@QAA@XZ
// EA  : 0x82519D70
// RVA : 0x00519D70
// PDB : w:\tech5\tungsten\game\decls\decltwitchpain.h
// ========================================================================

idTwitchPain_WeaponGroup *__fastcall idTwitchPain_WeaponGroup::idTwitchPain_WeaponGroup(idTwitchPain_WeaponGroup *this)
{
  this->__vftable = (idTwitchPain_WeaponGroup_vtbl *)&idTwitchPain_WeaponGroup::`vftable';
  this->weaponPrefix.len = 0;
  this->weaponPrefix.allocedAndFlag = 20;
  this->weaponPrefix.data = this->weaponPrefix.baseBuffer;
  this->weaponPrefix.baseBuffer[0] = 0;
  this->damageDirectionGroups.granularity = 0;
  this->damageDirectionGroups.listStatic = 0;
  this->damageDirectionGroups.memTag = 5;
  this->damageDirectionGroups.list = nullptr;
  this->damageDirectionGroups.size = 0;
  this->damageDirectionGroups.num = 0;
  return this;
}


// ========================================================================
// __unwind$573462
// EA  : 0x82519DD8
// RVA : 0x00519DD8
// PDB : w:\tech5\tungsten\game\decls\decltwitchpain.h
// ========================================================================

void _unwind_573462()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 32 + 52));
}


// ========================================================================
// __unwind$573463
// EA  : 0x82519E00
// RVA : 0x00519E00
// PDB : w:\tech5\tungsten\game\decls\decltwitchpain.h
// ========================================================================

void _unwind_573463()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 4));
}


// ========================================================================
// ?GetDeclInfo@idDeclTwitchPain@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BCBA60
// RVA : 0x00BCBA60
// PDB : w:\tech5\tungsten\game\decls\decltwitchpain.h
// ========================================================================

idDeclInfoTemplate<idDeclTwitchPain> *__fastcall idDeclTwitchPain::GetDeclInfo(idDeclTwitchPain *this)
{
  return &idDeclTwitchPain::resourceList;
}

