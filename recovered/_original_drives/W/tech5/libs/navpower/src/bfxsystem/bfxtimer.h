
// ========================================================================
// ??0FTimerOb@bfx@@QAA@ABVFTimerEntry@1@@Z
// EA  : 0x8323E2B8
// RVA : 0x0123E2B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxtimer.h
// ========================================================================

bfx::FTimerOb *__fastcall bfx::FTimerOb::FTimerOb(bfx::FTimerOb *this, const bfx::FTimerEntry *timerEntry)
{
  __int64 v2; // r10
  bfx::FTimer *v4; // r11

  LODWORD(v2) = 0;
  this->m_pFTimer = nullptr;
  if ( bfx::g_pCurInstance->m_pDebugOptions->m_drawTimings )
  {
    HIDWORD(v2) = timerEntry->m_timerID << 6;
    v4 = (bfx::FTimer *)((char *)bfx::g_pCurInstance->m_pTimerManager->m_pFTimerArray + HIDWORD(v2));
    this->m_pFTimer = v4;
    v4->m_timer.m_running = false;
    v4->m_timer.m_accumTicks = v2;
    bfx::Timer::Start(this: &v4->m_timer);
  }
  return this;
}


// ========================================================================
// ?Stop@FTimer@bfx@@QAAXXZ
// EA  : 0x8323F320
// RVA : 0x0123F320
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxtimer.h
// ========================================================================

void __fastcall bfx::FTimer::Stop(bfx::FTimer *this)
{
  bfx::Timer *p_m_timer; // r30
  unsigned int Micros; // r3
  unsigned int m_maxCallTime; // r11
  unsigned int v5; // r8

  p_m_timer = &this->m_timer;
  bfx::Timer::Stop(this: &this->m_timer);
  Micros = bfx::Timer::GetMicros(this: p_m_timer);
  m_maxCallTime = this->m_maxCallTime;
  v5 = this->m_frameTime + Micros;
  ++this->m_frameCount;
  this->m_frameTime = v5;
  if ( Micros <= m_maxCallTime )
    this->m_maxCallTime = m_maxCallTime;
  else
    this->m_maxCallTime = Micros;
}


// ========================================================================
// ??1FTimerOb@bfx@@QAA@XZ
// EA  : 0x8323F398
// RVA : 0x0123F398
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxtimer.h
// ========================================================================

void __fastcall bfx::FTimerOb::~FTimerOb(bfx::FTimerOb *this)
{
  bfx::FTimer *m_pFTimer; // r3

  m_pFTimer = this->m_pFTimer;
  if ( m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: m_pFTimer);
}

