
// ========================================================================
// ??1ObstacleRequestData@MoverSpaceComponent@bfx@@QAA@XZ
// EA  : 0x8325A3F8
// RVA : 0x0125A3F8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.h
// ========================================================================

void __fastcall bfx::MoverSpaceComponent::ObstacleRequestData::~ObstacleRequestData(
        bfx::MoverSpaceComponent::ObstacleRequestData *this)
{
  bfx::HandleProxy *m_pProxy; // r3

  m_pProxy = this->m_obstacle.m_pProxy;
  if ( m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    this->m_obstacle.m_pProxy = nullptr;
  }
}

