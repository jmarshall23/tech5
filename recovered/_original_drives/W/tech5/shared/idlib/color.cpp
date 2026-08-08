
// ========================================================================
// ?ToString@idColor@@QBAPBDH_N@Z
// EA  : 0x82EFA760
// RVA : 0x00EFA760
// PDB : w:\tech5\shared\idlib\color.cpp
// ========================================================================

char *__fastcall idColor::ToString(idColor *this, int precision, const bool parens)
{
  const char *v3; // r3

  if ( !parens )
    return (char *)idStr::FloatArrayToString(array: &this->r, length: 4, precision);
  v3 = idStr::FloatArrayToString(array: &this->r, length: 4, precision);
  idStr::snPrintf(dest: buffer, size: 4096, fmt: "( %s )", v3);
  return buffer;
}


// ========================================================================
// ?Lerp@idColor@@QAAXABV1@0M@Z
// EA  : 0x82EFA7D8
// RVA : 0x00EFA7D8
// PDB : w:\tech5\shared\idlib\color.cpp
// ========================================================================

void __fastcall idColor::Lerp(idColor *this, const idColor *from, const idColor *to, double lerp)
{
  if ( lerp > 0.0 )
  {
    if ( lerp < 1.0 )
    {
      this->r = (float)((float)(to->r - from->r) * (float)lerp) + from->r;
      this->g = (float)((float)(to->g - from->g) * (float)lerp) + from->g;
      this->b = (float)((float)(to->b - from->b) * (float)lerp) + from->b;
      this->a = (float)((float)(to->a - from->a) * (float)lerp) + from->a;
    }
    else
    {
      *this = *to;
    }
  }
  else
  {
    *this = *from;
  }
}


// ========================================================================
// ?PackColor@idColor@@SAIABVidVec4@@@Z
// EA  : 0x82EFA898
// RVA : 0x00EFA898
// PDB : w:\tech5\shared\idlib\color.cpp
// ========================================================================

int __fastcall idColor::PackColor(const idVec4 *color)
{
  int v1; // r11
  int v2; // r8
  int v3; // r11
  int v4; // r9
  int v5; // r11
  int v6; // r10
  int v7; // r11
  int v8; // r11

  v1 = (int)(float)(color->x * (float)255.0);
  if ( v1 >= 0 )
  {
    if ( v1 > 255 )
      LOBYTE(v1) = -1;
  }
  else
  {
    LOBYTE(v1) = 0;
  }
  v2 = (unsigned __int8)v1;
  v3 = (int)(float)(color->y * (float)255.0);
  if ( v3 >= 0 )
  {
    if ( v3 > 255 )
      LOBYTE(v3) = -1;
  }
  else
  {
    LOBYTE(v3) = 0;
  }
  v4 = (unsigned __int8)v3;
  v5 = (int)(float)(color->z * (float)255.0);
  if ( v5 >= 0 )
  {
    if ( v5 > 255 )
      LOBYTE(v5) = -1;
  }
  else
  {
    LOBYTE(v5) = 0;
  }
  v6 = (unsigned __int8)v5;
  v7 = (int)(float)(color->w * (float)255.0);
  if ( v7 >= 0 )
  {
    if ( v7 <= 255 )
      v8 = (unsigned __int8)(int)(float)(color->w * (float)255.0);
    else
      v8 = 255;
  }
  else
  {
    v8 = 0;
  }
  return (((((v8 << 8) & 0xFF00 | v6) << 8) | v4) << 8) | v2;
}


// ========================================================================
// ?UnpackColor@idColor@@SAXIAAVidVec4@@@Z
// EA  : 0x82EFA9A8
// RVA : 0x00EFA9A8
// PDB : w:\tech5\shared\idlib\color.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idColor::UnpackColor(
        const unsigned int color,
        idVec4 *unpackedColor,
        int a3,
        int a4,
        int a5,
        __int64 a6)
{
  __int64 v6; // r11
  __int64 v7; // fp11
  char *v8; // r7

  LODWORD(v6) = HIBYTE(color);
  HIDWORD(v6) = (unsigned __int8)color;
  LODWORD(a6) = BYTE2(color);
  v7 = a6;
  HIDWORD(a6) = BYTE1(color);
  v8 = byte_821B0000;
  unpackedColor->z = (float)*(__int64 *)((char *)&a6 + 4) * (float)0.0039215689;
  unpackedColor->y = (float)v7 * (float)0.0039215689;
  unpackedColor->x = (float)*(__int64 *)((char *)&a6 - 4) * (float)0.0039215689;
  unpackedColor->w = (float)v6 * (float)0.0039215689;
}


// ========================================================================
// ?SetFromString@idColor@@QAA_NPBD_N@Z
// EA  : 0x82EFAA30
// RVA : 0x00EFAA30
// PDB : w:\tech5\shared\idlib\color.cpp
// ========================================================================

BOOL __fastcall idColor::SetFromString(idColor *this, const char *str, bool parseParens)
{
  unsigned int v6; // r5
  BOOL v8; // r30
  idLexer v9; // [sp+50h] [-B0h] BYREF

  idLexer::idLexer(this: &v9, flags_: 4);
  v6 = 0;
  if ( *str != 0 )
  {
    do
      ++v6;
    while ( str[v6] != 0 );
  }
  idLexer::LoadMemory(this: &v9, ptr: str, length_: v6, name: str);
  if ( parseParens && !idLexer::ExpectTokenString(this: &v9, string: "(")
    || (this->r = idLexer::ParseFloat(this: &v9, errorFlag: nullptr),
        this->g = idLexer::ParseFloat(this: &v9, errorFlag: nullptr),
        this->b = idLexer::ParseFloat(this: &v9, errorFlag: nullptr),
        this->a = idLexer::ParseFloat(this: &v9, errorFlag: nullptr),
        parseParens)
    && !idLexer::ExpectTokenString(this: &v9, string: ")") )
  {
    idLexer::~idLexer(this: &v9);
    return false;
  }
  else
  {
    v8 = idLexer::HadError(this: &v9);
    idLexer::~idLexer(this: &v9);
    return v8;
  }
}


// ========================================================================
// __unwind$111604
// EA  : 0x82EFAB54
// RVA : 0x00EFAB54
// PDB : w:\tech5\shared\idlib\color.cpp
// ========================================================================

void _unwind_111604()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 256 + 80));
}


// ========================================================================
// `dynamic initializer for 'idColor::colorXAxis''
// EA  : 0x833941B0
// RVA : 0x013941B0
// PDB : w:\tech5\shared\idlib\color.cpp
// ========================================================================

__int64 _dynamic_initializer_for__idColor::colorXAxis__()
{
  __int64 result; // r4

  LODWORD(result) = LODWORD(idColor::colorBlue.a);
  idColor::colorXAxis = idColor::colorBlue;
  return result;
}


// ========================================================================
// `dynamic initializer for 'idColor::colorYAxis''
// EA  : 0x833941E8
// RVA : 0x013941E8
// PDB : w:\tech5\shared\idlib\color.cpp
// ========================================================================

__int64 _dynamic_initializer_for__idColor::colorYAxis__()
{
  __int64 result; // r4

  LODWORD(result) = LODWORD(idColor::colorRed.a);
  idColor::colorYAxis = idColor::colorRed;
  return result;
}


// ========================================================================
// `dynamic initializer for 'idColor::colorZAxis''
// EA  : 0x83394220
// RVA : 0x01394220
// PDB : w:\tech5\shared\idlib\color.cpp
// ========================================================================

__int64 _dynamic_initializer_for__idColor::colorZAxis__()
{
  __int64 result; // r4

  LODWORD(result) = LODWORD(idColor::colorGreen.a);
  idColor::colorZAxis = idColor::colorGreen;
  return result;
}

