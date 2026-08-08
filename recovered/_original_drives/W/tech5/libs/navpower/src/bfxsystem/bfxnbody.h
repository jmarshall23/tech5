
// ========================================================================
// ??Ecursor@NBody@bfx@@QAAXXZ
// EA  : 0x83250BF8
// RVA : 0x01250BF8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.h
// ========================================================================

void __fastcall bfx::NBody::cursor::operator++(bfx::NBody::cursor *this)
{
  const bfx::NBody *m_nbody; // r10
  int v2; // r11
  int v3; // r11

  m_nbody = this->m_nbody;
  v2 = this->m_i + 1;
  this->m_i = v2;
  if ( v2 < m_nbody->m_endpts.m_x.m_size )
  {
    do
    {
      if ( this->m_nbody->m_endpts.m_x.m_data[this->m_i].m_type == MIN_X_ENDPT )
        break;
      v3 = this->m_i + 1;
      this->m_i = v3;
    }
    while ( v3 < this->m_nbody->m_endpts.m_x.m_size );
  }
}

