
// ========================================================================
// ??0Setting@bfx@@QAA@XZ
// EA  : 0x8329B2C8
// RVA : 0x0129B2C8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsettings.cpp
// ========================================================================

bfx::Setting *__fastcall bfx::Setting::Setting(bfx::Setting *this)
{
  bfx::Setting *v1; // r11

  this->__vftable = (bfx::Setting_vtbl *)&bfx::Setting::`vftable';
  v1 = bfx::g_pSettingHead;
  this->m_prev = nullptr;
  this->m_next = v1;
  bfx::g_pSettingHead = this;
  return this;
}


// ========================================================================
// ??1Setting@bfx@@UAA@XZ
// EA  : 0x8329B2F0
// RVA : 0x0129B2F0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsettings.cpp
// ========================================================================

void __fastcall bfx::Setting::~Setting(bfx::Setting *this)
{
  bfx::Setting *m_next; // r11
  bfx::Setting *m_prev; // r11

  this->__vftable = (bfx::Setting_vtbl *)&bfx::Setting::`vftable';
  if ( bfx::g_pSettingHead != nullptr )
    bfx::g_pSettingHead = this->m_next;
  m_next = this->m_next;
  if ( m_next != nullptr )
    m_next->m_prev = this->m_prev;
  m_prev = this->m_prev;
  if ( m_prev != nullptr )
    m_prev->m_next = this->m_next;
}


// ========================================================================
// ?Read@BoolSetting@bfx@@UAAXPAU_iobuf@@@Z
// EA  : 0x8329B340
// RVA : 0x0129B340
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsettings.cpp
// ========================================================================

void __fastcall bfx::BoolSetting::Read(bfx::BoolSetting *this, _iobuf *pFile)
{
  int v3; // [sp+50h] [-20h] BYREF

  if ( fscanf(stream: pFile, format: "%d", &v3) == 1 )
    *this->m_targetBool = (_cntlzw(v3 - 1) & 0x20) != 0;
}


// ========================================================================
// ?Write@BoolSetting@bfx@@UAAXPAU_iobuf@@@Z
// EA  : 0x8329B3A0
// RVA : 0x0129B3A0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsettings.cpp
// ========================================================================

void __fastcall bfx::BoolSetting::Write(bfx::BoolSetting *this, _iobuf *pFile)
{
  fprintf(str: pFile, format: "%u;\n", *(unsigned __int8 *)this->m_targetBool != 0);
}

