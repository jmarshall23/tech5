
// ========================================================================
// ?SetGameHz@idTimeManager@@QAAXH@Z
// EA  : 0x826A7900
// RVA : 0x006A7900
// PDB : w:\tech5\engine\framework\timemanager.cpp
// ========================================================================

void __fastcall idTimeManager::SetGameHz(idTimeManager *this, signed int hertz)
{
  if ( hertz > 0 )
  {
    this->gameHz = hertz;
    this->gameTimePerFrame.value = (int)(float)((float)1000.0 / (float)__SPAIR64__(&unk_82150000, hertz));
  }
}

