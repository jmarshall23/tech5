
// ========================================================================
// ?InhibitFlags@idSpringCamera@@UBAHXZ
// EA  : 0x82CC8588
// RVA : 0x00CC8588
// PDB : w:\tech5\tungsten\game\entities\springcamera.h
// ========================================================================

int __fastcall idSpringCamera::InhibitFlags(idSpringCamera *this)
{
  return !this->inhibitControl ? 0 : 0x1F;
}


// ========================================================================
// ?InhibitButtons@idSpringCamera@@UBAHXZ
// EA  : 0x82CC85A0
// RVA : 0x00CC85A0
// PDB : w:\tech5\tungsten\game\entities\springcamera.h
// ========================================================================

int __fastcall idSpringCamera::InhibitButtons(idSpringCamera *this)
{
  return !this->inhibitControl - 1;
}

