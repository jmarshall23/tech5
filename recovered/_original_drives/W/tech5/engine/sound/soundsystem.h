
// ========================================================================
// ?LinearToDB@@YAMM@Z
// EA  : 0x824E02D8
// RVA : 0x004E02D8
// PDB : w:\tech5\engine\sound\soundsystem.h
// ========================================================================

float __fastcall LinearToDB(long double linear)
{
  long double v1; // fp2
  double v2; // fp1

  if ( *(double *)&linear <= 0.0 )
  {
    v2 = -999.0;
  }
  else
  {
    v1 = log(x: linear);
    v2 = (float)((float)*(double *)&v1 * (float)8.6561699);
  }
  return *((float *)&v2 + 1);
}


// ========================================================================
// ??1idSoundSystem@@UAA@XZ
// EA  : 0x82991578
// RVA : 0x00991578
// PDB : w:\tech5\engine\sound\soundsystem.h
// ========================================================================

void __fastcall idSoundSystem::~idSoundSystem(idSoundSystem *this)
{
  this->__vftable = (idSoundSystem_vtbl *)&idSoundSystem::`vftable';
}

