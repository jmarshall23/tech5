
// ========================================================================
// ?GetPresentable@idVehicleWeapon@@QAAPAVidPresentable@@XZ
// EA  : 0x82B9B4F8
// RVA : 0x00B9B4F8
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.h
// ========================================================================

idPresentable *__fastcall idVehicleWeapon::GetPresentable(idVehicleWeapon *this)
{
  unsigned int spawnId; // r11
  int v3; // r30
  idPresentable *result; // r3

  spawnId = this->presentable.spawnId;
  v3 = spawnId & 0x3FFF;
  if ( spawnId == 0 )
    return nullptr;
  if ( !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF) )
    return nullptr;
  result = idClientGame::GetPresentableByIndex(this: clientGame, index: v3);
  if ( result->spawnId != this->presentable.spawnId )
    return nullptr;
  return result;
}


// ========================================================================
// ?GetLeafPlay@idVehicleWeapon@@QAAAAVidMD6LeafPlay@@XZ
// EA  : 0x82D37E78
// RVA : 0x00D37E78
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.h
// ========================================================================

idMD6LeafPlay *__fastcall idVehicleWeapon::GetLeafPlay(idVehicleWeapon *this)
{
  idVehicleWeapon *v1; // r11

  do
  {
    v1 = this;
    this = this->dependentWeapon;
  }
  while ( this != nullptr );
  return &v1->leafPlay;
}

