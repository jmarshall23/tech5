
// ========================================================================
// ?NumFrames@idMD6Anim@@QBAHXZ
// EA  : 0x825FDD28
// RVA : 0x005FDD28
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.h
// ========================================================================

int __fastcall idMD6Anim::NumFrames(idMD6Anim *this)
{
  idMD6AnimData *animData; // r11
  int result; // r3

  animData = this->animData;
  result = 0;
  if ( animData != nullptr )
    return animData->numFrames;
  return result;
}


// ========================================================================
// ?GetResourceList@idMD6Anim@@UBAPAVidResourceList@@XZ
// EA  : 0x82827ED8
// RVA : 0x00827ED8
// PDB : w:\tech5\engine\models\skeletalanimation\md6anim.h
// ========================================================================

idTypedResourceList<idMD6Anim> *__fastcall idMD6Anim::GetResourceList(idMD6Anim *this)
{
  return &idMD6Anim::resourceList;
}

