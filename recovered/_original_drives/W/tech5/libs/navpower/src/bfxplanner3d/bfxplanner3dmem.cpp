
// ========================================================================
// bfx::`dynamic initializer for 'MEM_BFXPLANNER3D''
// EA  : 0x833991D0
// RVA : 0x013991D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxplanner3dmem.cpp
// ========================================================================

bfx::bfxMemTag bfx::_dynamic_initializer_for__MEM_BFXPLANNER3D__()
{
  bfx::bfxMemTag result; // r3

  result = bfx::RegisterMemTag(tagName: "bfxPlanner3D");
  bfx::MEM_BFXPLANNER3D = result;
  return result;
}

