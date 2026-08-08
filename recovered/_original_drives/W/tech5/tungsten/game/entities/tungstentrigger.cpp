
// ========================================================================
// ??0idTrigger_SaveGame@@QAA@XZ
// EA  : 0x82CF5040
// RVA : 0x00CF5040
// PDB : w:\tech5\tungsten\game\entities\tungstentrigger.cpp
// ========================================================================

idTrigger_SaveGame *__fastcall idTrigger_SaveGame::idTrigger_SaveGame(idTrigger_SaveGame *this)
{
  idTrigger::idTrigger(this);
  this->__vftable = (idTrigger_SaveGame_vtbl *)&idTrigger_SaveGame::`vftable';
  return this;
}


// ========================================================================
// ?Event_TriggerSaveGame@idTrigger_SaveGame@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CF5080
// RVA : 0x00CF5080
// PDB : w:\tech5\tungsten\game\entities\tungstentrigger.cpp
// ========================================================================

idTrigger_SaveGame *__fastcall idTrigger_SaveGame::Event_TriggerSaveGame(
        idTrigger_SaveGame *this,
        eventVoid *result,
        idEntity *activator)
{
  gameLocal->SaveGame(this: gameLocal, a2: "autosave", a3: true, a4: false);
  return this;
}


// ========================================================================
// ?Event_Touch@idTrigger_SaveGame@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CF50D8
// RVA : 0x00CF50D8
// PDB : w:\tech5\tungsten\game\entities\tungstentrigger.cpp
// ========================================================================

idTrigger_SaveGame *__fastcall idTrigger_SaveGame::Event_Touch(
        idTrigger_SaveGame *this,
        eventVoid *result,
        idEntity *other,
        int clipModelId)
{
  int v4; // r10
  idEntity *v8; // r3
  int v9; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3

  v4 = *(_DWORD *)&result[876];
  if ( gameLocal->spawnIds.ptr[v4 & 0x1FFF] == v4 >> 13
    && (v8 = gameLocal->entities.ptr[v4 & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v8) != nullptr
    && ((v9 = *(_DWORD *)&result[876], gameLocal->spawnIds.ptr[v9 & 0x1FFF] != v9 >> 13)
     || (v10 = gameLocal->entities.ptr[v9 & 0x1FFF]) == nullptr
      ? (v11 = nullptr)
      : (v11 = idEntity::CastTo(c: v10)),
        v11 == other)
    || *(_BYTE *)&result[880] != 0 && (unsigned __int8)idClass::IsType(this: other, superclass: &idPlayer::Type) != 0
    || *(_BYTE *)&result[884] != 0 && (unsigned __int8)idClass::IsType(this: other, superclass: &idAI2::Type) != 0 )
  {
    (*(void (__fastcall **)(eventVoid *, idEntity *))(*(_DWORD *)result + 616))(a1: result, a2: other);
  }
  return this;
}


// ========================================================================
// ?Event_TriggerStuff@idTrigger_SaveGame@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CF51F8
// RVA : 0x00CF51F8
// PDB : w:\tech5\tungsten\game\entities\tungstentrigger.cpp
// ========================================================================

idTrigger_SaveGame *__fastcall idTrigger_SaveGame::Event_TriggerStuff(
        idTrigger_SaveGame *this,
        idEntity *result,
        idEntity *activator)
{
  char v5; // [sp+50h] [-20h] BYREF

  idTrigger::Event_TriggerStuff(this: (idTrigger *)&v5, result, activator);
  gameLocal->SaveGame(this: gameLocal, a2: "autosave", a3: true, a4: false);
  return this;
}


// ========================================================================
// ?OnActivate@idTrigger_SaveGame@@UAAXPAVidEntity@@@Z
// EA  : 0x82CF5258
// RVA : 0x00CF5258
// PDB : w:\tech5\tungsten\game\entities\tungstentrigger.cpp
// ========================================================================

void __fastcall idTrigger_SaveGame::OnActivate(idTrigger_SaveGame *this, idEntity *activator)
{
  int nextTriggerTime; // r11
  const idEventArg **v5; // r3
  char v6; // [sp+50h] [-40h] BYREF
  int v8; // [sp+5Ch] [-34h]
  idEventArg v9; // [sp+60h] [-30h] BYREF

  if ( ((unsigned __int8 (__fastcall *)(idTrigger_SaveGame *))this->CanActivate)(a1: this) != 0 )
  {
    if ( this->delay <= 0.0 )
    {
      idTrigger_SaveGame::Event_TriggerStuff(this: (idTrigger_SaveGame *)&v6, result: this, activator);
    }
    else
    {
      nextTriggerTime = this->nextTriggerTime;
      v8 = (int)(float)(this->delay * (float)1000.0);
      this->nextTriggerTime = v8 + nextTriggerTime;
      v5 = (const idEventArg **)idEventArg::idEventArg(this: &v9, data: activator);
      idEventReceiver::PostEventSec(this, ev: &EV_TriggerStuff, time: this->delay, arg1: *v5);
    }
  }
}

