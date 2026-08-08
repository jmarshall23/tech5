
// ========================================================================
// ??0idVoiceChatMgr@@QAA@XZ
// EA  : 0x829E4B28
// RVA : 0x009E4B28
// PDB : w:\tech5\engine\sys\sys_voicechat.h
// ========================================================================

idVoiceChatMgr *__fastcall idVoiceChatMgr::idVoiceChatMgr(idVoiceChatMgr *this)
{
  this->__vftable = (idVoiceChatMgr_vtbl *)&idVoiceChatMgr::`vftable';
  idStaticList<idVoiceChatMgr::talker_t,12>::idStaticList<idVoiceChatMgr::talker_t,12>(this: &this->talkers);
  idStaticList<idVoiceChatMgr::remoteMachine_t,12>::idStaticList<idVoiceChatMgr::remoteMachine_t,12>(this: &this->remoteMachines);
  this->activeGroupIndex = 0;
  this->activeLobbyType = -1;
  this->sendFrame = 0;
  this->disableVoiceReasons = 0;
  this->sendGlobal = false;
  return this;
}


// ========================================================================
// __unwind$240606
// EA  : 0x829E4B9C
// RVA : 0x009E4B9C
// PDB : w:\tech5\engine\sys\sys_voicechat.h
// ========================================================================

void _unwind_240606()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}

