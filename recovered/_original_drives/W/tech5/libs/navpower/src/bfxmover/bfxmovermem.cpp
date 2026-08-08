
// ========================================================================
// bfx::`dynamic initializer for 'MEM_BFXMOVER''
// EA  : 0x83399230
// RVA : 0x01399230
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmovermem.cpp
// ========================================================================

bfx::bfxMemTag bfx::_dynamic_initializer_for__MEM_BFXMOVER__()
{
  bfx::bfxMemTag result; // r3

  result = bfx::RegisterMemTag(tagName: "bfxMover");
  bfx::MEM_BFXMOVER = result;
  return result;
}

