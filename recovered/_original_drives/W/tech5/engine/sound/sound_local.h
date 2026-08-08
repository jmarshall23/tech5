
// ========================================================================
// ?Read@idLocalizedSampleOnDisc@@QAAXPAVidFile@@@Z
// EA  : 0x8299F968
// RVA : 0x0099F968
// PDB : w:\tech5\engine\sound\sound_local.h
// ========================================================================

void __fastcall idLocalizedSampleOnDisc::Read(idLocalizedSampleOnDisc *this, idFile *file)
{
  file->Read(this: file, a2: this, a3: 16u);
  file->Read(this: file, a2: &this->size, a3: 4u);
  file->Read(this: file, a2: &this->offset, a3: 4u);
}

