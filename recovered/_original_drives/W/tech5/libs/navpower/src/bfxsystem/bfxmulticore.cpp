
// ========================================================================
// ??0Task@bfx@@QAA@PAVHandleProxy@1@@Z
// EA  : 0x83297128
// RVA : 0x01297128
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmulticore.cpp
// ========================================================================

bfx::Task *__fastcall bfx::Task::Task(bfx::Task *this, bfx::HandleProxy *pProxy)
{
  this->m_pProxy = pProxy;
  this->__vftable = (bfx::Task_vtbl *)&bfx::Task::`vftable';
  bfx::HandleProxy::ConnectToTask(this: pProxy);
  return this;
}


// ========================================================================
// ??1Task@bfx@@UAA@XZ
// EA  : 0x83297170
// RVA : 0x01297170
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmulticore.cpp
// ========================================================================

void __fastcall bfx::Task::~Task(bfx::Task *this)
{
  bfx::HandleProxy *m_pProxy; // r3

  m_pProxy = this->m_pProxy;
  this->__vftable = (bfx::Task_vtbl *)&bfx::Task::`vftable';
  bfx::HandleProxy::DisconnectFromTask(this: m_pProxy);
}

