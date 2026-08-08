
// ========================================================================
// ?Start@Timer@bfx@@QAAXXZ
// EA  : 0x83254E78
// RVA : 0x01254E78
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxtimer.cpp
// ========================================================================

void __fastcall bfx::Timer::Start(bfx::Timer *this)
{
  __asm { mftb      r11 }
  HIDWORD(_R11) = 1;
  this->m_startTicks = _R11;
  this->m_running = true;
}


// ========================================================================
// ?Stop@Timer@bfx@@QAAXXZ
// EA  : 0x83254E90
// RVA : 0x01254E90
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxtimer.cpp
// ========================================================================

void __fastcall bfx::Timer::Stop(bfx::Timer *this, int a2, int a3, __int64 a4)
{
  __int64 m_startTicks; // r9
  __int64 m_accumTicks; // r11

  __asm { mftb      r10 }
  m_startTicks = this->m_startTicks;
  m_accumTicks = this->m_accumTicks;
  this->m_running = false;
  LODWORD(a4) = HIDWORD(m_accumTicks) - m_startTicks + m_accumTicks;
  this->m_accumTicks = a4;
}


// ========================================================================
// ?GetMicros@Timer@bfx@@QAAIXZ
// EA  : 0x83254EB8
// RVA : 0x01254EB8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxtimer.cpp
// ========================================================================

unsigned int __fastcall bfx::Timer::GetMicros(bfx::Timer *this)
{
  __int64 m_accumTicks; // r10
  __int64 v2; // r7
  __int128 v5; // r6

  if ( this->m_running )
  {
    __asm { mftb      r10 }
    LODWORD(v5) = 1000000;
    DWORD2(v5) = LODWORD(this->m_accumTicks) - LODWORD(this->m_startTicks) + HIDWORD(this->m_accumTicks);
    DWORD1(v5) = 50000000;
    HIDWORD(v5) = 1000000 * DWORD2(v5);
    return *(_QWORD *)((char *)&v5 + 4) * (_QWORD)v5 / *(__int64 *)&v5;
  }
  else
  {
    m_accumTicks = this->m_accumTicks;
    HIDWORD(m_accumTicks) = 49938432;
    LODWORD(v2) = 50000000;
    HIDWORD(v2) = 1000000 * m_accumTicks;
    return 214748364801000000LL * m_accumTicks / v2;
  }
}


// ========================================================================
// ?ResetTimingStats@bfx@@YAXXZ
// EA  : 0x83254F28
// RVA : 0x01254F28
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxtimer.cpp
// ========================================================================

void __fastcall bfx::ResetTimingStats(bfx *this)
{
  bfx::SystemInstance *v1; // r11
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  v1 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v1 = bfx::g_pCurInstance;
  }
  v1->m_pTimerManager->ResetTimingStats(this: v1->m_pTimerManager);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$72005
// EA  : 0x83254F88
// RVA : 0x01254F88
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxtimer.cpp
// ========================================================================

void _unwind_72005()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// bfx::`dynamic initializer for 'g_enableHTimersRestore''
// EA  : 0x83398218
// RVA : 0x01398218
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxtimer.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_enableHTimersRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_enableHTimersRestore);
  bfx::g_enableHTimersRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_enableHTimersRestore.m_targetBool = &bfx::g_enableHTimers;
  bfx::g_enableHTimersRestore.m_name = "enable_htimers";
  bfx::g_enableHTimersRestore.m_defaultBool = bfx::g_enableHTimers;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_enableHTimersRestore__);
}

