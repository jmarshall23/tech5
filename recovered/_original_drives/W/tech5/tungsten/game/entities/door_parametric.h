
// ========================================================================
// ?CanKickOpen@idDoor_Parametric@@UBA_NXZ
// EA  : 0x82C25AF0
// RVA : 0x00C25AF0
// PDB : w:\tech5\tungsten\game\entities\door_parametric.h
// ========================================================================

BOOL __fastcall idDoor_Parametric::CanKickOpen(idDoor_Parametric *this)
{
  return !this->slidingDoor && this->canKickOpen;
}


// ========================================================================
// ?KickUnlocks@idDoor_Parametric@@UBA_NXZ
// EA  : 0x82C25B10
// RVA : 0x00C25B10
// PDB : w:\tech5\tungsten\game\entities\door_parametric.h
// ========================================================================

BOOL __fastcall idDoor_Parametric::KickUnlocks(idDoor_Parametric *this)
{
  return this->kickUnlocks;
}

