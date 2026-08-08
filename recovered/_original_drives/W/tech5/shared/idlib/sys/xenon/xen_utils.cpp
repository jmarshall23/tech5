
// ========================================================================
// ?Sys_GetOSUserName@@YAPBDXZ
// EA  : 0x82F86970
// RVA : 0x00F86970
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_utils.cpp
// ========================================================================

char *__fastcall Sys_GetOSUserName()
{
  XUserGetName(dwUserIndex: 0, pUserName: szUserName, cchUserName: 0x40u);
  return szUserName;
}


// ========================================================================
// ?Sys_GetMachineName@@YAPBDXZ
// EA  : 0x82F869B0
// RVA : 0x00F869B0
// PDB : w:\tech5\shared\idlib\sys\xenon\xen_utils.cpp
// ========================================================================

char *__fastcall Sys_GetMachineName()
{
  unsigned int v1[4]; // [sp+50h] [-20h] BYREF

  v1[0] = 64;
  DmGetXboxName(a1: szMachineName_0, a2: v1);
  return szMachineName_0;
}

