
// ========================================================================
// ??0FollowerLeaderDatabase@bfx@@QAA@XZ
// EA  : 0x832B5048
// RVA : 0x012B5048
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollowerleaderdatabase.h
// ========================================================================

bfx::FollowerLeaderDatabase *__fastcall bfx::FollowerLeaderDatabase::FollowerLeaderDatabase(
        bfx::FollowerLeaderDatabase *this)
{
  bfx::bfxMemTag v2; // r11

  v2 = bfx::MEM_BFXMOVER;
  this->m_entries.m_data = nullptr;
  this->m_entries.m_size = 0;
  this->m_entries.m_cap = 0;
  this->m_entries.m_tag = v2;
  bfx::FMSpec::FMSpec(this: &this->m_spec);
  this->m_leaderIsCloseToGoal = false;
  this->m_leader.m_pProxy = nullptr;
  return this;
}


// ========================================================================
// __unwind$32805
// EA  : 0x832B50A0
// RVA : 0x012B50A0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollowerleaderdatabase.h
// ========================================================================

void _unwind_32805()
{
  int v0; // r12

  bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord>::~Array<bfx::FollowerLeaderDatabase::DatabaseRecord>(this: *(bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord> **)(v0 - 128 + 148));
}


// ========================================================================
// ??1FollowerLeaderDatabase@bfx@@QAA@XZ
// EA  : 0x832BD408
// RVA : 0x012BD408
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollowerleaderdatabase.h
// ========================================================================

void __fastcall bfx::FollowerLeaderDatabase::~FollowerLeaderDatabase(bfx::FollowerLeaderDatabase *this)
{
  bfx::HandleProxy *m_pProxy; // r3

  m_pProxy = this->m_leader.m_pProxy;
  if ( m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    this->m_leader.m_pProxy = nullptr;
  }
  bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord>::shrink(this: &this->m_entries, size: 0);
  if ( this->m_entries.m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_entries.m_data);
    this->m_entries.m_data = nullptr;
  }
  this->m_entries.m_cap = 0;
}


// ========================================================================
// __unwind$37593
// EA  : 0x832BD474
// RVA : 0x012BD474
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollowerleaderdatabase.h
// ========================================================================

void _unwind_37593()
{
  int v0; // r12

  bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord>::~Array<bfx::FollowerLeaderDatabase::DatabaseRecord>(this: *(bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord> **)(v0 - 128 + 148));
}

