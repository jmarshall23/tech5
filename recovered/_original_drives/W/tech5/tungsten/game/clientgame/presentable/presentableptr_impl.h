
// ========================================================================
// ??C?$idPresentablePtr@VidPresentableProjectile@@@@QBAPAVidPresentableProjectile@@XZ
// EA  : 0x829FC538
// RVA : 0x009FC538
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableptr_impl.h
// ========================================================================

idPresentable *__fastcall idPresentablePtr<idPresentableProjectile>::operator->(idPresentablePtr<idPresentable> *this)
{
  unsigned int v2; // r30
  idPresentable *result; // r3

  v2 = this->spawnId & 0x3FFF;
  if ( this->spawnId == 0 )
    return nullptr;
  if ( !idClientGame::IsPresentableIndexValid(this: clientGame, index: this->spawnId & 0x3FFF) )
    return nullptr;
  result = idClientGame::GetPresentableByIndex(this: clientGame, index: v2);
  if ( result->spawnId != this->spawnId )
    return nullptr;
  return result;
}


// ========================================================================
// ?GetPresentable@?$idPresentablePtr@VidPresentablePlayer@@@@QBAPAVidPresentablePlayer@@XZ
// EA  : 0x82B4DB78
// RVA : 0x00B4DB78
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableptr_impl.h
// ========================================================================

idPresentablePlayer *__fastcall idPresentablePtr<idPresentablePlayer>::GetPresentable(
        idPresentablePtr<idPresentablePlayer> *this)
{
  unsigned int spawnId; // r7
  signed int v2; // r11
  idPresentablePlayer *result; // r3

  spawnId = this->spawnId;
  v2 = this->spawnId & 0x3FFF;
  if ( this->spawnId == 0 )
    return nullptr;
  if ( v2 >= clientGame->presentables.num || clientGame->presentables.list[v2] == nullptr )
    return nullptr;
  result = (idPresentablePlayer *)clientGame->presentables.list[v2];
  if ( result->spawnId != spawnId )
    return nullptr;
  return result;
}


// ========================================================================
// ?Serialize@?$idPresentablePtr@VidPresentableVehicle@@@@QAAXAAVidSerializer@@@Z
// EA  : 0x82B596B0
// RVA : 0x00B596B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableptr_impl.h
// ========================================================================

void __fastcall idPresentablePtr<idPresentableVehicle>::Serialize(
        idPresentablePtr<idPresentableVehicle> *this,
        idSerializer *ser)
{
  idBitMsg *msg; // r3

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->spawnId, numBits: 32);
  else
    this->spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
}


// ========================================================================
// ?IsValid@?$idPresentablePtr@VidPresentable@@@@QBA_NXZ
// EA  : 0x82EC3F20
// RVA : 0x00EC3F20
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableptr_impl.h
// ========================================================================

BOOL __fastcall idPresentablePtr<idPresentable>::IsValid(idPresentablePtr<idPresentableActor> *this)
{
  unsigned int v2; // r30
  idPresentable *PresentableByIndex; // r3

  v2 = this->spawnId & 0x3FFF;
  return this->spawnId != 0
      && idClientGame::IsPresentableIndexValid(this: clientGame, index: this->spawnId & 0x3FFF)
      && (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v2))->spawnId == this->spawnId
      && PresentableByIndex != nullptr;
}

