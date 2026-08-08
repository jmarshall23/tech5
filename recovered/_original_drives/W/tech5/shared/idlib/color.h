
// ========================================================================
// ??9idQuat@@QBA_NABV0@@Z
// EA  : 0x82618A00
// RVA : 0x00618A00
// PDB : w:\tech5\shared\idlib\color.h
// ========================================================================

BOOL __fastcall idQuat::operator!=(idColor *this, const idColor *rhs)
{
  unsigned __int8 v2; // r11

  if ( this->r != rhs->r || this->g != rhs->g || this->b != rhs->b || (v2 = 1, this->a != rhs->a) )
    v2 = 0;
  return (_cntlzw(v2) & 0x20) != 0;
}


// ========================================================================
// ?ToColorRef@idColor@@QBAIXZ
// EA  : 0x8279E908
// RVA : 0x0079E908
// PDB : w:\tech5\shared\idlib\color.h
// ========================================================================

int __fastcall idColor::ToColorRef(idColor *this)
{
  int v2; // r11
  unsigned __int8 v3; // r3
  int v4; // r11
  unsigned __int8 v5; // r10
  int v6; // r11
  unsigned __int16 v8; // r10

  v2 = (int)(float)((float)(this->r * (float)255.0) + (float)0.5);
  if ( v2 >= 0 )
  {
    v3 = -1;
    if ( v2 <= 255 )
      v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  v4 = (int)(float)((float)(this->g * (float)255.0) + (float)0.5);
  if ( v4 >= 0 )
  {
    v5 = -1;
    if ( v4 <= 255 )
      v5 = (int)(float)((float)(this->g * (float)255.0) + (float)0.5);
  }
  else
  {
    v5 = 0;
  }
  v6 = (int)(float)((float)(this->b * (float)255.0) + (float)0.5);
  if ( v6 < 0 )
    return (v5 << 8) | v3;
  if ( v6 <= 255 )
    v8 = ((unsigned __int8)(int)(float)((float)(this->b * (float)255.0) + (float)0.5) << 8) | v5;
  else
    v8 = v5 | 0xFF00;
  return (v8 << 8) | v3;
}

