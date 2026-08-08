
// ========================================================================
// ?SetWaterEntNum@idPhysics_Player@@UAAXH@Z
// EA  : 0x82753A48
// RVA : 0x00753A48
// PDB : w:\tech5\engine\gamelib\physics\physics_player.h
// ========================================================================

void __fastcall idPhysics_Player::SetWaterEntNum(idPhysics_Player *this, int entNum)
{
  this->currentWaterEnt = entNum;
}


// ========================================================================
// ?GetWaterEntNum@idPhysics_Player@@UBAHXZ
// EA  : 0x82753A50
// RVA : 0x00753A50
// PDB : w:\tech5\engine\gamelib\physics\physics_player.h
// ========================================================================

int __fastcall idPhysics_Player::GetWaterEntNum(idPhysics_Player *this)
{
  return this->currentWaterEnt;
}


// ========================================================================
// ?SetWaterSurfaceWrldHeight@idPhysics_Player@@UAAXM@Z
// EA  : 0x82753A58
// RVA : 0x00753A58
// PDB : w:\tech5\engine\gamelib\physics\physics_player.h
// ========================================================================

void __fastcall idPhysics_Player::SetWaterSurfaceWrldHeight(idPhysics_Player *this, double height)
{
  this->currentWaterSurfaceHeight = height;
}


// ========================================================================
// ?GetWaterSurfaceWrldHeight@idPhysics_Player@@UBAMXZ
// EA  : 0x82753A60
// RVA : 0x00753A60
// PDB : w:\tech5\engine\gamelib\physics\physics_player.h
// ========================================================================

float __fastcall idPhysics_Player::GetWaterSurfaceWrldHeight(idPhysics_Player *this)
{
  double currentWaterSurfaceHeight; // fp1

  currentWaterSurfaceHeight = this->currentWaterSurfaceHeight;
  return *((float *)&currentWaterSurfaceHeight + 1);
}

