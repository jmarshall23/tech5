
// ========================================================================
// ?GetType@idPresentableWeapon@@UBA?AW4presentableType_t@@XZ
// EA  : 0x82BB1CE0
// RVA : 0x00BB1CE0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.h
// ========================================================================

int __fastcall idPresentableWeapon::GetType(idPresentableWeapon *this)
{
  return 19;
}


// ========================================================================
// ?GetFiredWeapon@idPresentableWeapon@@UAAPAVidWeapon@@PBVidDeclWeapon@@@Z
// EA  : 0x82BB1CE8
// RVA : 0x00BB1CE8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableweapon.h
// ========================================================================

idWeapon *__fastcall idPresentableWeapon::GetFiredWeapon(idPresentableWeapon *this, const idDeclWeapon *wepDef)
{
  return this->clientWeapon;
}

