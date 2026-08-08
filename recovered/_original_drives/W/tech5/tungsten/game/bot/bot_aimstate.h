
// ========================================================================
// ?Reset@BotAimRequest_t@idBotAimState@@QAAXXZ
// EA  : 0x82B40160
// RVA : 0x00B40160
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.h
// ========================================================================

void __fastcall idBotAimState::BotAimRequest_t::Reset(idBotAimState::BotAimRequest_t *this)
{
  idStr::Clear(this: &this->aimUserName);
  this->aimPriority = AIM_PRIORITY_NULL;
  this->aimType = AIM_TYPE_NONE;
  this->aimStartTimeInMS = 0;
  this->aimValidTimeInMS = 0;
  this->aimVector = vec3_origin;
  this->aimEntity.spawnId.value = 0x1FFF;
  this->aimPoint = AIMPOINT_MAX;
}


// ========================================================================
// ??0BotAimRequest_t@idBotAimState@@QAA@XZ
// EA  : 0x82B401E0
// RVA : 0x00B401E0
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.h
// ========================================================================

idBotAimState::BotAimRequest_t *__fastcall idBotAimState::BotAimRequest_t::BotAimRequest_t(
        idBotAimState::BotAimRequest_t *this)
{
  this->aimUserName.len = 0;
  this->aimUserName.allocedAndFlag = 20;
  this->aimUserName.data = this->aimUserName.baseBuffer;
  this->aimUserName.baseBuffer[0] = 0;
  this->aimEntity.spawnId.value = 0x1FFF;
  idBotAimState::BotAimRequest_t::Reset(this);
  return this;
}


// ========================================================================
// __unwind$489310
// EA  : 0x82B40250
// RVA : 0x00B40250
// PDB : w:\tech5\tungsten\game\bot\bot_aimstate.h
// ========================================================================

void _unwind_489310()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}

