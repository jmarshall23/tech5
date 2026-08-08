
// ========================================================================
// ??1CriticalSectionOb@bfx@@QAA@XZ
// EA  : 0x8323D058
// RVA : 0x0123D058
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmulticore.h
// ========================================================================

void __fastcall bfx::CriticalSectionOb::~CriticalSectionOb(bfx::CriticalSectionOb *this)
{
  bfx::APICriticalSection *m_pCS; // r3

  m_pCS = this->m_pCS;
  if ( m_pCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pCS->m_criticalSection);
}

