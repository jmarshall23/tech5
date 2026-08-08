
// ========================================================================
// ?GetSectorSize@idFile_Permanent@@UAAHXZ
// EA  : 0x82F085B0
// RVA : 0x00F085B0
// PDB : w:\tech5\shared\idlib\filesystem\file_permanent.h
// ========================================================================

int __fastcall idFile_Permanent::GetSectorSize(idFile_Permanent *this)
{
  return this->sectorSize;
}


// ========================================================================
// ?GetDevice@idFile_Permanent@@UAA?AW4fsDevice_t@@XZ
// EA  : 0x82F085B8
// RVA : 0x00F085B8
// PDB : w:\tech5\shared\idlib\filesystem\file_permanent.h
// ========================================================================

XGRAPHICS::_SSM_REGISTRY *__fastcall idFile_Permanent::GetDevice(_DWORD *hSSMDev)
{
  return (XGRAPHICS::_SSM_REGISTRY *)hSSMDev[23];
}

