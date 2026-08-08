
// ========================================================================
// ?IsMainThread@idLib@@SA_NXZ
// EA  : 0x82F2E6E0
// RVA : 0x00F2E6E0
// PDB : w:\tech5\shared\idlib\lib.cpp
// ========================================================================

int __fastcall idLib::IsMainThread()
{
  int v0; // r3
  unsigned __int8 v1; // r11

  if ( idLib::mainThreadID == 0 )
    return 1;
  v0 = mgthread_getid();
  v1 = 0;
  if ( idLib::mainThreadID == v0 )
    return 1;
  return v1;
}


// ========================================================================
// ?AvoidLinkErrorGetProduction@idLib@@SA?AW4production_t@@XZ
// EA  : 0x82F2E730
// RVA : 0x00F2E730
// PDB : w:\tech5\shared\idlib\lib.cpp
// ========================================================================

production_t __fastcall idLib::AvoidLinkErrorGetProduction()
{
  return idLib::production;
}


// ========================================================================
// ?Init@idLib@@SAXXZ
// EA  : 0x82F2E740
// RVA : 0x00F2E740
// PDB : w:\tech5\shared\idlib\lib.cpp
// ========================================================================

static void __fastcall idLib::Init()
{
  if ( idLib::mainThreadID != 0 && idLib::mainThreadID != mgthread_getid() )
    idLib::FatalError(fmt: "idLib::Init called from different thread!");
  idLib::mainThreadID = mgthread_getid();
}

