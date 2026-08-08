
// ========================================================================
// ?GetGroundSpeedMultiplier@idAAS2Local@@UBAMXZ
// EA  : 0x826AA590
// RVA : 0x006AA590
// PDB : w:\tech5\engine\gamelib\aas2\aas2_local.h
// ========================================================================

float __fastcall idAAS2Local::GetGroundSpeedMultiplier(idAAS2Local *this)
{
  double groundSpeedMultiplier; // fp1

  groundSpeedMultiplier = this->groundSpeedMultiplier;
  return *((float *)&groundSpeedMultiplier + 1);
}

