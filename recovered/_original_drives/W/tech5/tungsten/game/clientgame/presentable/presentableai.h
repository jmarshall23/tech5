
// ========================================================================
// ?SetWeaponPrefix@idPresentableAI@@QAAXABVidStr@@@Z
// EA  : 0x829F5D80
// RVA : 0x009F5D80
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.h
// ========================================================================

void __fastcall idPresentableAI::SetWeaponPrefix(idPresentableAI *this, const idStr *strWeaponPrefix)
{
  int len; // r30

  len = strWeaponPrefix->len;
  idStr::EnsureAlloced(
    this: &this->painAnimationEventInfo.weaponPrefix,
    amount: strWeaponPrefix->len + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->painAnimationEventInfo.weaponPrefix.data, Src: strWeaponPrefix->data, Size: len);
  this->painAnimationEventInfo.weaponPrefix.data[len] = 0;
  this->painAnimationEventInfo.weaponPrefix.len = len;
}


// ========================================================================
// ?GetType@idPresentableAI@@UBA?AW4presentableType_t@@XZ
// EA  : 0x82B6A528
// RVA : 0x00B6A528
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableai.h
// ========================================================================

int __fastcall idPresentableAI::GetType(idPresentableAI *this)
{
  return 15;
}

