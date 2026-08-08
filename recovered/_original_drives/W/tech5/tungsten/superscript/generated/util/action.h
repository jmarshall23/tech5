
// ========================================================================
// ??0action_moveToGoalEntity@@QAA@XZ
// EA  : 0x82EE39B0
// RVA : 0x00EE39B0
// PDB : w:\tech5\tungsten\superscript\generated\util\action.h
// ========================================================================

action_moveToGoalEntity *__fastcall action_moveToGoalEntity::action_moveToGoalEntity(action_moveToGoalEntity *this)
{
  int v2; // r11

  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (action_moveToGoalEntity_vtbl *)&action_moveToGoalEntity::`vftable';
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->actor);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->goal);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->activationEntity);
  v2 = 0;
  this->activationList.data = nullptr;
  this->activationList.num = 0;
  this->activationList.size = 0;
  if ( gameInterface != nullptr )
    v2 = gameInterface->GetAllocThread(this: gameInterface);
  this->activationList.threadId = v2;
  return this;
}


// ========================================================================
// __unwind$23189
// EA  : 0x82EE3A4C
// RVA : 0x00EE3A4C
// PDB : w:\tech5\tungsten\superscript\generated\util\action.h
// ========================================================================

void _unwind_23189()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 112 + 132));
}


// ========================================================================
// ?_name@action_moveToGoalEntity@@UBAPBDXZ
// EA  : 0x82EE3A78
// RVA : 0x00EE3A78
// PDB : w:\tech5\tungsten\superscript\generated\util\action.h
// ========================================================================

const char *__fastcall action_moveToGoalEntity::_name(action_moveToGoalEntity *this)
{
  return "action_moveToGoalEntity";
}


// ========================================================================
// ?_isTypeOf@action_moveToGoalEntity@@UAA_NPBD@Z
// EA  : 0x82EE3A88
// RVA : 0x00EE3A88
// PDB : w:\tech5\tungsten\superscript\generated\util\action.h
// ========================================================================

BOOL __fastcall action_moveToGoalEntity::_isTypeOf(action_moveToGoalEntity *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "action_moveToGoalEntity")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@action_moveToGoalEntity@@UAAPAXXZ
// EA  : 0x82EE3AC0
// RVA : 0x00EE3AC0
// PDB : w:\tech5\tungsten\superscript\generated\util\action.h
// ========================================================================

ssDeclInfo_t *__fastcall action_moveToGoalEntity::_getDeclPtr(action_moveToGoalEntity *this)
{
  return `action_moveToGoalEntity::_getDeclPtr'::`2'::varInfo;
}

