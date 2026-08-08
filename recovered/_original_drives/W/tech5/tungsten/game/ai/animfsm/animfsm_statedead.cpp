
// ========================================================================
// ?Enter@idAnimStateDead@@UAAXPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A7F148
// RVA : 0x00A7F148
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statedead.cpp
// ========================================================================

void __fastcall idAnimStateDead::Enter(idAnimStateDead *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  idAnimBaseFSM::SetDestination(this: fsm, cmd: &idAIMoveCmd::s_null);
}


// ========================================================================
// ??0idAnimStateDead@@QAA@XZ
// EA  : 0x82A7F158
// RVA : 0x00A7F158
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statedead.cpp
// ========================================================================

idAnimStateDead *__fastcall idAnimStateDead::idAnimStateDead(idAnimStateDead *this)
{
  idAIStateLite::idAIStateLite(this);
  this->__vftable = (idAnimStateDead_vtbl *)&idAnimStateDead::`vftable';
  return this;
}

