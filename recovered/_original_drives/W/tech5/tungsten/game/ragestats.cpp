
// ========================================================================
// ?RageStatTypeIsInt@@YA_NW4rageStat_t@@@Z
// EA  : 0x82E8A810
// RVA : 0x00E8A810
// PDB : w:\tech5\tungsten\game\ragestats.cpp
// ========================================================================

BOOL __fastcall RageStatTypeIsInt(int stat)
{
  return stat < 12 || stat > 15 && stat != 230;
}


// ========================================================================
// ?GetStatAsInt@@YAHAAVidLocalUser@@W4rageStat_t@@@Z
// EA  : 0x82E8A838
// RVA : 0x00E8A838
// PDB : w:\tech5\tungsten\game\ragestats.cpp
// ========================================================================

int __fastcall GetStatAsInt(idLocalUser *user, int stat)
{
  bool v2; // r11
  idLocalUser_vtbl *v3; // r11
  bool v4; // zf

  v2 = stat < 12 || stat > 15 && stat != 230;
  v4 = !v2;
  v3 = user->__vftable;
  if ( v4 )
    return (int)((double (*)(void))v3->GetStatFloat)();
  else
    return ((int (*)(void))v3->GetStatInt)();
}

