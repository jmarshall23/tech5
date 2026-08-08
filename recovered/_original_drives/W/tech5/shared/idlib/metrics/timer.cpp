
// ========================================================================
// ?InitBaseClockTicks@idTimer@@ABAXXZ
// EA  : 0x82F3FB60
// RVA : 0x00F3FB60
// PDB : w:\tech5\shared\idlib\metrics\timer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idTimer::InitBaseClockTicks(idTimer *this)
{
  int v1; // r28 OVERLAPPED
  __int64 v2; // r30 OVERLAPPED
  __int64 v3; // r3
  idTimer v4; // [sp+50h] [-50h] BYREF

  v4.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  *(__int64 *)((char *)&v2 + 4) = 0x3E800000000LL;
  LODWORD(v2) = -1;
  idTimer::base = 0x3E800000000LL;
  do
  {
    v4.clockTicks = *(__int64 *)((char *)&v2 + 4);
    v4.state = TS_STARTED;
    LODWORD(v3) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v4.start = v3;
    idTimer::Stop(this: &v4);
    if ( (int)v2 < 0 || SLODWORD(v4.clockTicks) < (int)v2 )
      LODWORD(v2) = v4.clockTicks;
    --v1;
  }
  while ( v1 != 0 );
  idTimer::base = v2;
}


// ========================================================================
// __unwind$111445
// EA  : 0x82F3FBD8
// RVA : 0x00F3FBD8
// PDB : w:\tech5\shared\idlib\metrics\timer.cpp
// ========================================================================

void _unwind_111445()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 160 + 80));
}

