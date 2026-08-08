
// ========================================================================
// ??1idCommon@@UAA@XZ
// EA  : 0x82642710
// RVA : 0x00642710
// PDB : w:\tech5\engine\framework\common.h
// ========================================================================

void __fastcall idCommon::~idCommon(idCommon *this)
{
  this->__vftable = (idCommon_vtbl *)&idCommon::`vftable';
}


// ========================================================================
// ?IsServer@idCommon@@UBA_NXZ
// EA  : 0x82642720
// RVA : 0x00642720
// PDB : w:\tech5\engine\framework\common.h
// ========================================================================

int __fastcall idCommon::IsServer(idCommon *this)
{
  bool v2; // r3
  unsigned __int8 v3; // r11

  if ( this->SnapshotState(this) != SNAP_READING )
    return 1;
  v2 = this->TimeTrialPlaying(this);
  v3 = 0;
  if ( v2 )
    return 1;
  return v3;
}


// ========================================================================
// ?IsClient@idCommon@@UBA_NXZ
// EA  : 0x82642790
// RVA : 0x00642790
// PDB : w:\tech5\engine\framework\common.h
// ========================================================================

BOOL __fastcall idCommon::IsClient(idCommon *this)
{
  return (_cntlzw(this->SnapshotState(this) - 1) & 0x20) != 0;
}

