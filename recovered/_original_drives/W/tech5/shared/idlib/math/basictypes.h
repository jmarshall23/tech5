
// ========================================================================
// ?SetValue@?$idBoundedInt@$0A@$03@@UAAXH@Z
// EA  : 0x82CE2358
// RVA : 0x00CE2358
// PDB : w:\tech5\shared\idlib\math\basictypes.h
// ========================================================================

void __fastcall idBoundedInt<0,4>::SetValue(idBoundedInt<0,4> *this, int i)
{
  if ( i > 0 )
  {
    if ( i < 4 )
      this->value = i;
    else
      this->value = 4;
  }
  else
  {
    this->value = 0;
  }
}


// ========================================================================
// ?SetValue@?$idBoundedFloat@$0A@$0A@$00$0A@@@UAAXM@Z
// EA  : 0x82CE2388
// RVA : 0x00CE2388
// PDB : w:\tech5\shared\idlib\math\basictypes.h
// ========================================================================

void __fastcall idBoundedFloat<0,0,1,0>::SetValue(idBoundedFloat<0,0,1,0> *this, double i)
{
  double v2; // fp0

  v2 = 0.0;
  if ( i > 0.0 && (v2 = 1.0, i < 1.0) )
    this->value = i;
  else
    this->value = v2;
}

