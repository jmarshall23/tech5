
// ========================================================================
// ?SetSafeWhiteSpacePointers@idToken@@QAAXXZ
// EA  : 0x82F97D20
// RVA : 0x00F97D20
// PDB : w:\tech5\shared\idlib\text\token.cpp
// ========================================================================

void __fastcall idToken::SetSafeWhiteSpacePointers(idToken *this)
{
  bool v1; // cr57

  v1 = this->whiteSpaceEnd_p > this->whiteSpaceStart_p;
  this->whiteSpaceStart_p = idToken::DEFAULT_WHITESPACE;
  if ( v1 )
    this->whiteSpaceEnd_p = idToken::DEFAULT_WHITESPACE + 1;
  else
    this->whiteSpaceEnd_p = idToken::DEFAULT_WHITESPACE;
}


// ========================================================================
// ?InheritWhiteSpace@idToken@@QAAXABV1@@Z
// EA  : 0x82F97D58
// RVA : 0x00F97D58
// PDB : w:\tech5\shared\idlib\text\token.cpp
// ========================================================================

void __fastcall idToken::InheritWhiteSpace(idToken *this, const idToken *other)
{
  this->whiteSpaceStart_p = other->whiteSpaceStart_p;
  this->whiteSpaceEnd_p = other->whiteSpaceEnd_p;
  this->linesCrossed = other->linesCrossed;
}


// ========================================================================
// ?NumberValue@idToken@@AAAXXZ
// EA  : 0x82F97D78
// RVA : 0x00F97D78
// PDB : w:\tech5\shared\idlib\text\token.cpp
// ========================================================================

void __fastcall idToken::NumberValue(idToken *this, int a2, __int64 a3)
{
  int subtype; // r11
  char *data; // r3
  __int64 v6; // r10
  long double v7; // fp2
  int m; // r11
  double floatvalue; // fp13
  __int64 v10; // r10
  int v11; // ctr
  int v12; // ctr
  __int64 v13; // fp0
  _BYTE *v14; // r3
  int i; // r11
  _BYTE *j; // r3
  unsigned int v17; // r11
  _BYTE *v18; // r3
  int k; // r11

  subtype = this->subtype;
  data = this->data;
  HIDWORD(v6) = 0;
  this->floatvalue = 0.0;
  this->intvalue = 0;
  if ( (subtype & 0x80) != 0 )
  {
    if ( (subtype & 0x3800) != 0 )
    {
      if ( (subtype & 0x800) != 0 )
      {
        this->floatvalue = INFINITY;
        this->intvalue = (int)this->floatvalue;
        goto LABEL_49;
      }
      if ( (subtype & 0x1000) != 0 )
      {
        this->floatvalue = NAN;
        this->intvalue = (int)this->floatvalue;
        goto LABEL_49;
      }
      if ( (subtype & 0x2000) != 0 )
      {
        this->floatvalue = NAN;
        this->intvalue = (int)this->floatvalue;
        goto LABEL_49;
      }
    }
    else
    {
      v7 = atof(nptr: data);
      this->floatvalue = *(double *)&v7;
    }
    this->intvalue = (int)this->floatvalue;
    goto LABEL_49;
  }
  if ( (subtype & 2) == 0 )
  {
    if ( (subtype & 0x4000) != 0 )
    {
      v10 = (unsigned int)*data;
      if ( *data == 0 )
        goto LABEL_26;
      do
      {
        if ( (_DWORD)v10 == 58 )
          break;
        if ( (_DWORD)v10 == 46 )
        {
          if ( HIDWORD(v10) != 3 )
          {
            v11 = 3 - HIDWORD(v10);
            do
            {
              this->intvalue *= 10;
              --v11;
            }
            while ( v11 != 0 );
          }
          HIDWORD(v10) = 0;
        }
        else
        {
          ++HIDWORD(v10);
          this->intvalue = 10 * this->intvalue + v10 - 48;
        }
        LODWORD(v10) = *++data;
      }
      while ( *data != 0 );
      if ( HIDWORD(v10) != 3 )
      {
LABEL_26:
        v12 = 3 - HIDWORD(v10);
        do
        {
          this->intvalue *= 10;
          --v12;
        }
        while ( v12 != 0 );
      }
      LODWORD(v10) = this->intvalue;
      v13 = v10;
    }
    else if ( (subtype & 8) != 0 )
    {
      v14 = data + 1;
      for ( i = (char)*v14; *v14 != 0; i = (char)*v14 )
      {
        HIDWORD(v6) = 8 * this->intvalue + i - 48;
        this->intvalue = HIDWORD(v6);
        ++v14;
      }
      LODWORD(v6) = this->intvalue;
      v13 = v6;
    }
    else if ( (subtype & 4) != 0 )
    {
      for ( j = data + 2; *j != 0; ++j )
      {
        LODWORD(v6) = 16 * this->intvalue;
        this->intvalue = v6;
        HIDWORD(v6) = (unsigned __int8)*j;
        if ( SBYTE3(v6) < 97 || SBYTE3(v6) > 102 )
        {
          if ( SBYTE3(v6) < 65 || SBYTE3(v6) > 70 )
            v17 = v6 + SBYTE3(v6) - 48;
          else
            v17 = v6 + SBYTE3(v6) - 55;
        }
        else
        {
          v17 = v6 + SBYTE3(v6) - 87;
        }
        this->intvalue = v17;
      }
      LODWORD(v6) = this->intvalue;
      v13 = v6;
    }
    else
    {
      if ( (subtype & 0x10) == 0 )
        goto LABEL_49;
      v18 = data + 2;
      for ( k = (char)*v18; *v18 != 0; k = (char)*v18 )
      {
        HIDWORD(v6) = 2 * this->intvalue + k - 48;
        this->intvalue = HIDWORD(v6);
        ++v18;
      }
      LODWORD(v6) = this->intvalue;
      v13 = v6;
    }
    this->floatvalue = (float)v13;
    goto LABEL_49;
  }
  for ( m = *data; *data != 0; m = *data )
  {
    floatvalue = this->floatvalue;
    this->intvalue = 10 * this->intvalue + m - 48;
    LODWORD(a3) = *data - 48;
    this->floatvalue = (float)((float)floatvalue * (float)10.0) + (float)a3;
    ++data;
  }
LABEL_49:
  this->subtype |= 0x10000u;
}

