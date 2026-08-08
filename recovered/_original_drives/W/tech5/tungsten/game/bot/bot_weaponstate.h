
// ========================================================================
// ??0BotWeaponRequest_t@idBotWeaponState@@QAA@XZ
// EA  : 0x82B44420
// RVA : 0x00B44420
// PDB : w:\tech5\tungsten\game\bot\bot_weaponstate.h
// ========================================================================

idBotWeaponState::BotWeaponRequest_t *__fastcall idBotWeaponState::BotWeaponRequest_t::BotWeaponRequest_t(
        idBotWeaponState::BotWeaponRequest_t *this)
{
  this->weaponUserName.len = 0;
  this->weaponUserName.data = this->weaponUserName.baseBuffer;
  this->weaponUserName.allocedAndFlag = 20;
  this->weaponUserName.baseBuffer[0] = 0;
  idStr::Clear(this: &this->weaponUserName);
  this->weaponPriority = WEAPON_PRIORITY_NULL;
  this->weaponHandler = nullptr;
  this->weaponSlot = WEAPON_SLOT_MAX;
  this->weaponFireMode = WEAPON_FIRE_MODE_WHEN_READY;
  return this;
}


// ========================================================================
// __unwind$488358
// EA  : 0x82B44484
// RVA : 0x00B44484
// PDB : w:\tech5\tungsten\game\bot\bot_weaponstate.h
// ========================================================================

void _unwind_488358()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}

