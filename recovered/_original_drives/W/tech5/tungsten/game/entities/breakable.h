
// ========================================================================
// ?IsDead@idBreakable@@UBA_NXZ
// EA  : 0x82C0DE78
// RVA : 0x00C0DE78
// PDB : w:\tech5\tungsten\game\entities\breakable.h
// ========================================================================

unsigned int __fastcall idBreakable::IsDead(idBreakable *this)
{
  return (((unsigned int)this->brokenStartTime >> 31) + 1) & 1;
}


// ========================================================================
// ?IsTargetLockable@idBreakable@@UBA_NXZ
// EA  : 0x82C0DE98
// RVA : 0x00C0DE98
// PDB : w:\tech5\tungsten\game\entities\breakable.h
// ========================================================================

int __fastcall idBreakable::IsTargetLockable(idBreakable *this)
{
  unsigned __int8 v1; // r11

  if ( !this->targetable )
    return 0;
  v1 = 1;
  if ( this->brokenStartTime <= -1 )
    return 0;
  return v1;
}

