
// ========================================================================
// bfx::`dynamic initializer for 'MEM_BFXMOVER3D''
// EA  : 0x83399200
// RVA : 0x01399200
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dmem.cpp
// ========================================================================

bfx::bfxMemTag bfx::_dynamic_initializer_for__MEM_BFXMOVER3D__()
{
  bfx::bfxMemTag result; // r3

  result = bfx::RegisterMemTag(tagName: "bfxMover3D");
  bfx::MEM_BFXMOVER3D = result;
  return result;
}

