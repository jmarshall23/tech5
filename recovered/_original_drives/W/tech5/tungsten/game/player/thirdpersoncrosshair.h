
// ========================================================================
// ?HasOwner@idThirdPersonCrosshair@@QBA_NXZ
// EA  : 0x82B97FA0
// RVA : 0x00B97FA0
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.h
// ========================================================================

BOOL __fastcall idThirdPersonCrosshair::HasOwner(idThirdPersonCrosshair *this)
{
  unsigned int spawnId; // r11
  int v3; // r30
  idPresentable *PresentableByIndex; // r3

  spawnId = this->presentable.spawnId;
  v3 = spawnId & 0x3FFF;
  return spawnId != 0
      && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
      && (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v3))->spawnId == this->presentable.spawnId
      && PresentableByIndex != nullptr;
}


// ========================================================================
// ?GetTarget@idThirdPersonCrosshair@@QBAPAVidPresentable@@XZ
// EA  : 0x82B98020
// RVA : 0x00B98020
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.h
// ========================================================================

idPresentable *__fastcall idThirdPersonCrosshair::GetTarget(idThirdPersonCrosshair *this)
{
  unsigned int spawnId; // r11
  int v3; // r30
  idPresentable *result; // r3

  spawnId = this->target.spawnId;
  v3 = spawnId & 0x3FFF;
  if ( spawnId == 0 )
    return nullptr;
  if ( !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF) )
    return nullptr;
  result = idClientGame::GetPresentableByIndex(this: clientGame, index: v3);
  if ( result->spawnId != this->target.spawnId )
    return nullptr;
  return result;
}

