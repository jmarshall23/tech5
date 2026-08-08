
// ========================================================================
// bfx::`dynamic initializer for 'MEM_BFXSYSTEM''
// EA  : 0x83398748
// RVA : 0x01398748
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemmem.cpp
// ========================================================================

bfx::bfxMemTag bfx::_dynamic_initializer_for__MEM_BFXSYSTEM__()
{
  bfx::bfxMemTag result; // r3

  result = bfx::RegisterMemTag(tagName: "bfxSystem");
  bfx::MEM_BFXSYSTEM = result;
  return result;
}


// ========================================================================
// bfx::`dynamic initializer for 'MEM_REPLAY''
// EA  : 0x83398778
// RVA : 0x01398778
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemmem.cpp
// ========================================================================

bfx::bfxMemTag bfx::_dynamic_initializer_for__MEM_REPLAY__()
{
  bfx::bfxMemTag result; // r3

  result = bfx::RegisterMemTag(tagName: "Replay");
  bfx::MEM_REPLAY = result;
  return result;
}

