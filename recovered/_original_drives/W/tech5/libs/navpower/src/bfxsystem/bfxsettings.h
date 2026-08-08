
// ========================================================================
// ?IsChangedFromDefault@BoolSetting@bfx@@UAA_NXZ
// EA  : 0x832503B0
// RVA : 0x012503B0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsettings.h
// ========================================================================

BOOL __fastcall bfx::BoolSetting::IsChangedFromDefault(bfx::BoolSetting *this)
{
  return this->m_defaultBool != *(unsigned __int8 *)this->m_targetBool;
}

