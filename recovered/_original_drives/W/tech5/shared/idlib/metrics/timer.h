
// ========================================================================
// ??1idTimer@@UAA@XZ
// EA  : 0x825B98F8
// RVA : 0x005B98F8
// PDB : w:\tech5\shared\idlib\metrics\timer.h
// ========================================================================

void __fastcall idTimer::~idTimer(idTimer *this)
{
  this->__vftable = (idTimer_vtbl *)&idTimer::`vftable';
}


// ========================================================================
// ?Stop@idTimer@@QAAXXZ
// EA  : 0x825B9908
// RVA : 0x005B9908
// PDB : w:\tech5\shared\idlib\metrics\timer.h
// ========================================================================

void __fastcall idTimer::Stop(idTimer *this)
{
  __int64 v2; // r7
  __int64 clockTicks; // r11
  __int64 v4; // r11

  LODWORD(v2) = ((unsigned __int64)Sys_GetClockTicks() >> 32) + LODWORD(this->clockTicks) - LODWORD(this->start);
  this->clockTicks = v2;
  if ( (float)idTimer::base < 0.0 )
    idTimer::InitBaseClockTicks(this);
  clockTicks = this->clockTicks;
  if ( (int)clockTicks > (int)idTimer::base )
  {
    LODWORD(v4) = clockTicks - idTimer::base;
    HIDWORD(v4) = 1;
    this->clockTicks = v4;
  }
  this->state = TS_STOPPED;
}


// ========================================================================
// ?Milliseconds@idTimer@@QBAMXZ
// EA  : 0x825D9C78
// RVA : 0x005D9C78
// PDB : w:\tech5\shared\idlib\metrics\timer.h
// ========================================================================

float __fastcall idTimer::Milliseconds(idTimer *this)
{
  double clockTicks; // fp31
  __int64 v2; // r3
  double v3; // fp1

  clockTicks = (float)this->clockTicks;
  LODWORD(v2) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
  v3 = (float)((float)clockTicks / (float)((float)v2 * (float)0.001));
  return *((float *)&v3 + 1);
}

