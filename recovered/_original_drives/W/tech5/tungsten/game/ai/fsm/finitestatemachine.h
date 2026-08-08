
// ========================================================================
// ??1idFSMCallback@@UAA@XZ
// EA  : 0x829F0780
// RVA : 0x009F0780
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.h
// ========================================================================

void __fastcall idFSMCallback::~idFSMCallback(idFSMCallback *this)
{
  this->__vftable = (idFSMCallback_vtbl *)&idFSMCallback::`vftable';
}


// ========================================================================
// ??1idFSMManager@@UAA@XZ
// EA  : 0x829F07E8
// RVA : 0x009F07E8
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.h
// ========================================================================

void __fastcall idFSMManager::~idFSMManager(idFSMManager *this)
{
  this->__vftable = (idFSMManager_vtbl *)&idFSMManager::`vftable';
  idEventReceiver::~idEventReceiver(this);
}

