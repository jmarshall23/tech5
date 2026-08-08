
// ========================================================================
// ?ColorForIndex@idStr@@SAAAVidVec4@@H@Z
// EA  : 0x82F94258
// RVA : 0x00F94258
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

idVec4 *__fastcall idStr::ColorForIndex(int i)
{
  return (idVec4 *)((char *)g_color_table + ((16 * i) & 0xF0));
}


// ========================================================================
// ?CountChar@idStr@@SAHPBDD@Z
// EA  : 0x82F94270
// RVA : 0x00F94270
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::CountChar(const char *str, const char c)
{
  const char *v2; // r10
  int result; // r3
  int v4; // r11

  v2 = str;
  v4 = *str;
  result = 0;
  if ( v4 != 0 )
  {
    do
    {
      if ( v4 == c )
        ++result;
      v4 = *++v2;
    }
    while ( *v2 != 0 );
  }
  return result;
}


// ========================================================================
// ?CStyleQuote@idStr@@SAPBDPBD@Z
// EA  : 0x82F942B0
// RVA : 0x00F942B0
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

char *__fastcall idStr::CStyleQuote(const char *str)
{
  int v2; // r11
  int v3; // r7
  char *result; // r3
  bool v5; // zf
  const char *v6; // r26
  int v7; // r9
  char *v8; // r11

  v2 = 1;
  v3 = index_1 << 14;
  index_1 = ((_BYTE)index_1 + 1) & 3;
  buffers[0][v3] = 34;
  v5 = str == nullptr;
  result = &buffers[0][v3];
  if ( v5 )
    goto LABEL_25;
  v6 = str - 1;
  while ( 1 )
  {
    v7 = *++v6;
    if ( v7 <= 12 )
      break;
    if ( v7 > 39 )
    {
      if ( v7 == 63 )
      {
        result[v2++] = 92;
        result[v2] = 63;
        goto LABEL_24;
      }
      if ( v7 == 92 )
      {
        result[v2++] = 92;
        result[v2] = 92;
        goto LABEL_24;
      }
LABEL_21:
      result[v2] = v7;
      goto LABEL_24;
    }
    switch ( v7 )
    {
      case 39:
        result[v2++] = 92;
        result[v2] = 39;
        break;
      case 13:
        result[v2++] = 92;
        result[v2] = 114;
        break;
      case 34:
        result[v2++] = 92;
        result[v2] = 34;
        break;
      default:
        goto LABEL_21;
    }
LABEL_24:
    if ( (unsigned int)++v2 >= 0x3FFE )
      goto LABEL_25;
  }
  if ( v7 == 12 )
  {
    result[v2++] = 92;
    result[v2] = 102;
    goto LABEL_24;
  }
  switch ( *v6 )
  {
    case 0:
      break;
    case 7:
      result[v2++] = 92;
      result[v2] = 97;
      goto LABEL_24;
    case 8:
      result[v2++] = 92;
      result[v2] = 98;
      goto LABEL_24;
    case 9:
      result[v2++] = 92;
      result[v2] = 116;
      goto LABEL_24;
    case 0xA:
      result[v2++] = 92;
      result[v2] = 110;
      goto LABEL_24;
    case 0xB:
      result[v2++] = 92;
      result[v2] = 118;
      goto LABEL_24;
    default:
      goto LABEL_21;
  }
LABEL_25:
  v8 = &result[v2];
  *v8 = 34;
  v8[1] = 0;
  return result;
}


// ========================================================================
// ?CStyleUnQuote@idStr@@SAPBDPBD@Z
// EA  : 0x82F94488
// RVA : 0x00F94488
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

char *__fastcall idStr::CStyleUnQuote(char *str)
{
  char *v1; // r7
  unsigned int v2; // r11
  char v3; // r10
  int v4; // r10

  if ( *str == 34 )
  {
    v1 = str;
    v2 = 0;
    str = buffers_0[index_2];
    index_2 = ((_BYTE)index_2 + 1) & 3;
    do
    {
      v3 = *++v1;
      if ( v3 == 0 )
        break;
      if ( v3 == 92 )
      {
        v4 = *++v1;
        if ( v4 > 98 )
        {
          switch ( *v1 )
          {
            case 'f':
              str[v2] = 12;
              break;
            case 'n':
              str[v2] = 10;
              break;
            case 'r':
              str[v2] = 13;
              break;
            case 't':
              str[v2] = 9;
              break;
            case 'v':
              str[v2] = 11;
              break;
            default:
              break;
          }
        }
        else if ( v4 == 98 )
        {
          str[v2] = 8;
        }
        else if ( v4 > 63 )
        {
          if ( v4 == 92 )
          {
            str[v2] = 92;
          }
          else if ( v4 == 97 )
          {
            str[v2] = 7;
          }
        }
        else
        {
          switch ( v4 )
          {
            case '?':
              str[v2] = 63;
              break;
            case '"':
              str[v2] = 34;
              break;
            case '\'':
              str[v2] = 39;
              break;
            default:
              break;
          }
        }
      }
      else
      {
        str[v2] = v3;
      }
      ++v2;
    }
    while ( v2 < 0x3FFF );
    str[v2 - 1] = 0;
  }
  return str;
}


// ========================================================================
// ?StripLeading@idStr@@QAAXD@Z
// EA  : 0x82F94630
// RVA : 0x00F94630
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::StripLeading(idStr *this, const char c)
{
  int i; // r30

  for ( i = c; *this->data == i; --this->len )
    memmove(Dst: this->data, Src: this->data + 1, Size: this->len);
}


// ========================================================================
// ?ReplaceChar@idStr@@QAA_NDD@Z
// EA  : 0x82F946A8
// RVA : 0x00F946A8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::ReplaceChar(idStr *this, char oldChar, char newChar)
{
  int result; // r3
  int v5; // r11
  bool v6; // zf
  char *data; // r10

  v5 = 0;
  v6 = this->len > 0;
  result = 0;
  if ( v6 )
  {
    do
    {
      data = this->data;
      if ( data[v5] == oldChar )
      {
        data[v5] = newChar;
        result = 1;
      }
      ++v5;
    }
    while ( v5 < this->len );
  }
  return result;
}


// ========================================================================
// ?StripQuotes@idStr@@QAAAAV1@XZ
// EA  : 0x82F946F8
// RVA : 0x00F946F8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

idStr *__fastcall idStr::StripQuotes(idStr *this)
{
  char *data; // r10
  char *v3; // r11
  char *v4; // r3
  int v5; // r5

  data = this->data;
  if ( *data == 34 )
  {
    v3 = &data[this->len];
    if ( *(v3 - 1) == 34 )
    {
      *(v3 - 1) = 0;
      --this->len;
    }
    v4 = this->data;
    v5 = this->len - 1;
    this->len = v5;
    memmove(Dst: v4, Src: v4 + 1, Size: v5);
    this->data[this->len] = 0;
  }
  return this;
}


// ========================================================================
// ?BackSlashesToSlashes@idStr@@QAAAAV1@XZ
// EA  : 0x82F94788
// RVA : 0x00F94788
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

idStr *__fastcall idStr::BackSlashesToSlashes(idStr *this)
{
  int i; // r11
  char *data; // r10

  for ( i = 0; i < this->len; ++i )
  {
    data = this->data;
    if ( data[i] == 92 )
      data[i] = 47;
  }
  return this;
}


// ========================================================================
// ?SlashesToBackSlashes@idStr@@QAAAAV1@XZ
// EA  : 0x82F947C8
// RVA : 0x00F947C8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

idStr *__fastcall idStr::SlashesToBackSlashes(idStr *this)
{
  int i; // r11
  char *data; // r10

  for ( i = 0; i < this->len; ++i )
  {
    data = this->data;
    if ( data[i] == 47 )
      data[i] = 92;
  }
  return this;
}


// ========================================================================
// ?CollapsePath@idStr@@QAAAAV1@XZ
// EA  : 0x82F94808
// RVA : 0x00F94808
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

idStr *__fastcall idStr::CollapsePath(idStr *this)
{
  int v1; // r11
  int v2; // r6
  char *data; // r10
  char *v4; // r9
  int v5; // r7
  int v6; // r8
  int v7; // r9
  char *v8; // r8
  int v9; // r9
  char *v10; // r9
  int v11; // r9
  char *v12; // r9
  int v13; // r11
  char v14; // r8

  v1 = 0;
  v2 = 0;
  if ( this->len > 0 )
  {
    while ( 1 )
    {
      data = this->data;
      v4 = &data[v2];
      v5 = (unsigned __int8)data[v2];
      if ( v5 != 46 )
        break;
      v6 = v4[1];
      if ( v6 == 46 )
      {
        v7 = v4[2];
        if ( v7 == 47 || v7 == 92 )
        {
          if ( v1 >= 2 )
          {
            v8 = &data[v1];
            v9 = data[v1 - 1];
            if ( (v9 == 47 || v9 == 92) && (v1 == 2 || *(v8 - 2) != 46 || *(v8 - 3) != 46) )
            {
              if ( --v1 > 0 )
              {
                v10 = &data[v1];
                do
                {
                  v11 = *(v10 - 1);
                  if ( v11 == 47 )
                    break;
                  if ( v11 == 92 )
                    break;
                  v10 = &data[--v1];
                }
                while ( v1 > 0 );
              }
              v2 += 2;
              goto LABEL_24;
            }
          }
          data[v1] = 46;
          v12 = this->data;
          v13 = v1 + 1;
          v14 = v12[v2 + 1];
          v2 += 2;
          v12[v13] = v14;
          v1 = v13 + 1;
          this->data[v1] = this->data[v2];
          goto LABEL_23;
        }
      }
      if ( v6 != 47 && v6 != 92 )
        break;
      ++v2;
LABEL_24:
      if ( ++v2 >= this->len )
        goto LABEL_25;
    }
    data[v1] = v5;
LABEL_23:
    ++v1;
    goto LABEL_24;
  }
LABEL_25:
  this->data[v1] = 0;
  this->len = v1;
  return this;
}


// ========================================================================
// ?StripFileExtension@idStr@@QAAAAV1@XZ
// EA  : 0x82F94948
// RVA : 0x00F94948
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

idStr *__fastcall idStr::StripFileExtension(idStr *this)
{
  int v1; // r11
  char *data; // r9
  int v3; // r10

  v1 = this->len - 1;
  if ( v1 >= 0 )
  {
    data = this->data;
    do
    {
      v3 = data[v1];
      if ( v3 == 92 || v3 == 47 )
        break;
      if ( v3 == 46 )
      {
        data[v1] = 0;
        this->len = v1;
        return this;
      }
      --v1;
    }
    while ( v1 >= 0 );
  }
  return this;
}


// ========================================================================
// ?IsNumeric@idStr@@SA_NPBD@Z
// EA  : 0x82F94998
// RVA : 0x00F94998
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::IsNumeric(const char *s)
{
  char v1; // r30
  const char *v2; // r31

  if ( *s == 45 )
    ++s;
  v1 = 0;
  if ( *s == 0 )
    return 1;
  v2 = s;
  while ( isdigit(c: *(unsigned __int8 *)v2) != 0 )
  {
LABEL_9:
    if ( *++v2 == 0 )
      return 1;
  }
  if ( *v2 == 46 && v1 == 0 )
  {
    v1 = 1;
    goto LABEL_9;
  }
  return 0;
}


// ========================================================================
// ?Copynz@idStr@@SAXPADPBDH@Z
// EA  : 0x82F94A30
// RVA : 0x00F94A30
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::Copynz(__int64 src, __int64 destsize, __int64 a3, __int64 a4)
{
  int v4; // r30
  int v5; // r31
  int v6; // [sp+8h] [-68h]
  int v7; // [sp+Ch] [-64h]
  int v8; // [sp+10h] [-60h]
  int v9; // [sp+14h] [-5Ch]

  v4 = HIDWORD(src);
  v5 = HIDWORD(destsize);
  if ( (_DWORD)src != 0 )
  {
    if ( SHIDWORD(destsize) >= 1 )
    {
      strncpy(dest: (char *)HIDWORD(src), source: (const char *)src, count: HIDWORD(destsize) - 1);
      *(_BYTE *)(v4 + v5 - 1) = 0;
    }
    else
    {
      HIDWORD(src) = "idStr::Copynz: destsize < 1";
      idLib::Warning(fmt: src, a2: destsize, a3, a4, a5: v6, a6: v7, a7: v8, a8: v9);
    }
  }
  else
  {
    HIDWORD(src) = "idStr::Copynz: NULL src";
    idLib::Warning(fmt: src, a2: destsize, a3, a4, a5: v6, a6: v7, a7: v8, a8: v9);
  }
}


// ========================================================================
// ?CopyCountAndZero@idStr@@SAXPADHPBDH@Z
// EA  : 0x82F94AB0
// RVA : 0x00F94AB0
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::CopyCountAndZero(__int64 destSize, __int64 count, __int64 a3, __int64 a4)
{
  __int64 v4; // kr00_8
  int v5; // r29
  int v6; // [sp+8h] [-68h]
  int v7; // [sp+Ch] [-64h]
  int v8; // [sp+10h] [-60h]
  int v9; // [sp+14h] [-5Ch]

  v4 = destSize;
  LODWORD(destSize) = HIDWORD(count);
  v5 = count;
  if ( HIDWORD(count) != 0 )
  {
    if ( (int)v4 >= 1 )
    {
      if ( (int)count >= 1 )
      {
        if ( (int)count >= (int)v4 - 1 )
        {
          strncpy(dest: (char *)HIDWORD(destSize), source: (const char *)HIDWORD(count), count: v4 - 1);
          *(_BYTE *)(HIDWORD(v4) + v4 - 1) = 0;
        }
        else
        {
          strncpy(dest: (char *)HIDWORD(destSize), source: (const char *)HIDWORD(count), count);
          *(_BYTE *)(HIDWORD(v4) + v5) = 0;
        }
      }
      else
      {
        HIDWORD(destSize) = "idStr::Copynz: count < 1";
        idLib::Warning(fmt: destSize, a2: count, a3, a4, a5: v6, a6: v7, a7: v8, a8: v9);
      }
    }
    else
    {
      HIDWORD(destSize) = "idStr::Copynz: destsize < 1";
      idLib::Warning(fmt: destSize, a2: count, a3, a4, a5: v6, a6: v7, a7: v8, a8: v9);
    }
  }
  else
  {
    HIDWORD(destSize) = "idStr::Copynz: NULL src";
    idLib::Warning(fmt: destSize, a2: (unsigned int)count, a3, a4, a5: v6, a6: v7, a7: v8, a8: v9);
  }
}


// ========================================================================
// ?vsnPrintf@idStr@@SAHPADHPBD0@Z
// EA  : 0x82F94B68
// RVA : 0x00F94B68
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::vsnPrintf(char *dest, int size, const char *fmt, char *argptr)
{
  int result; // r3

  result = vsnprintf(string: dest, count: size - 1, format: fmt, ap: argptr);
  dest[size - 1] = 0;
  if ( result < 0 || result >= size )
    return -1;
  return result;
}


// ========================================================================
// ?UTF8Char@idStr@@SAIPBEAAH@Z
// EA  : 0x82F94BC8
// RVA : 0x00F94BC8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

unsigned int __fastcall idStr::UTF8Char(const unsigned __int8 *s, int *idx)
{
  int v2; // r10
  unsigned int v3; // r11
  unsigned int result; // r3
  int v5; // r10
  unsigned int v6; // r11
  int i; // ctr
  unsigned int v8; // r9
  int v9; // r11

  v2 = *idx;
  if ( *idx >= 0 && (v3 = s[v2], s[v2] != 0) )
  {
    if ( v3 >= 0x80 )
    {
      v5 = 0;
      if ( v3 >= 0xC0 )
        v5 = trailingBytes[v3 - 192];
      v6 = trailingMask[v5] & v3;
      if ( v5 > 0 )
      {
        for ( i = v5; i != 0; --i )
        {
          v8 = v6 << 6;
          v9 = *idx + 1;
          *idx = v9;
          v6 = (s[v9] & 0x3F) + v8;
        }
      }
      ++*idx;
      return v6;
    }
    else
    {
      result = s[v2];
      *idx = v2 + 1;
    }
  }
  else
  {
    *idx = v2 + 1;
    return 0;
  }
  return result;
}


// ========================================================================
// ?EmitEscapeChar@idStr@@SA_NAAPBDAAD@Z
// EA  : 0x82F94C78
// RVA : 0x00F94C78
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

BOOL __fastcall idStr::EmitEscapeChar(__int64 c, __int64 a2, __int64 a3)
{
  _DWORD *v3; // r30
  _BYTE *v4; // r31
  unsigned __int8 v5; // r29
  _BYTE *v6; // r11
  unsigned __int8 *v7; // r11
  __int64 v8; // r10
  __int64 v10; // r10
  unsigned __int8 v11; // r11
  int v12; // r11
  _BYTE *v13; // r10
  __int64 v14; // r10
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+10h] [-60h]
  int v18; // [sp+14h] [-5Ch]

  v3 = (_DWORD *)HIDWORD(c);
  v4 = (_BYTE *)c;
  v5 = 0;
  *(_BYTE *)c = **(_BYTE **)HIDWORD(c);
  v6 = (_BYTE *)(*(_DWORD *)HIDWORD(c) + 1);
  *(_DWORD *)HIDWORD(c) = v6;
  if ( *(_BYTE *)c != 92 )
    return true;
  *(_BYTE *)c = *v6;
  v7 = (unsigned __int8 *)(*(_DWORD *)HIDWORD(c) + 1);
  *(_DWORD *)HIDWORD(c) = v7;
  HIDWORD(v8) = *(unsigned __int8 *)c;
  LODWORD(v8) = HIDWORD(v8);
  if ( HIDWORD(v8) > 0x66 )
  {
    LODWORD(v8) = HIDWORD(v8) - 110;
    switch ( *(_BYTE *)c )
    {
      case 'n':
        *(_BYTE *)c = 10;
        return true;
      case 'r':
        *(_BYTE *)c = 13;
        return true;
      case 't':
        *(_BYTE *)c = 9;
        return true;
      case 'v':
        *(_BYTE *)c = 11;
        return true;
      case 'x':
        LODWORD(v10) = 0;
        break;
      default:
        goto LABEL_38;
    }
    while ( 1 )
    {
      HIDWORD(v10) = *v7;
      *(_BYTE *)c = BYTE3(v10);
      if ( SBYTE3(v10) < 48 || SBYTE3(v10) > 57 )
      {
        if ( SBYTE3(v10) < 65 || SBYTE3(v10) > 90 )
        {
          if ( SBYTE3(v10) < 97 || SBYTE3(v10) > 122 )
          {
            if ( (int)v10 > 255 )
            {
              HIDWORD(c) = "too large value in escape character";
              idLib::Warning(fmt: c, a2, a3, a4: v10, a5: v15, a6: v16, a7: v17, a8: v18);
              LOBYTE(v10) = -1;
              v5 = 1;
            }
            *v4 = v10;
            return (_cntlzw(v5) & 0x20) != 0;
          }
          v11 = BYTE3(v10) - 87;
        }
        else
        {
          v11 = BYTE3(v10) - 55;
        }
      }
      else
      {
        v11 = BYTE3(v10) - 48;
      }
      *(_BYTE *)c = v11;
      LODWORD(a3) = v11;
      LODWORD(v10) = 16 * v10 + (char)v11;
      v7 = (unsigned __int8 *)(*(_DWORD *)HIDWORD(c) + 1);
      *(_DWORD *)HIDWORD(c) = v7;
    }
  }
  if ( HIDWORD(v8) == 102 )
  {
    *(_BYTE *)c = 12;
    return true;
  }
  else
  {
    if ( HIDWORD(v8) > 0x5C )
    {
      if ( HIDWORD(v8) == 97 )
      {
        *(_BYTE *)c = 7;
        return true;
      }
      if ( HIDWORD(v8) == 98 )
      {
        *(_BYTE *)c = 8;
        return true;
      }
    }
    else
    {
      switch ( HIDWORD(v8) )
      {
        case '\\':
          *(_BYTE *)c = 92;
          return true;
        case '"':
          *(_BYTE *)c = 34;
          return true;
        case '\'':
          *(_BYTE *)c = 39;
          return true;
        case '?':
          *(_BYTE *)c = 63;
          return true;
        default:
          break;
      }
    }
LABEL_38:
    if ( SBYTE3(v8) < 48 || (LODWORD(v8) = *(char *)c, (int)v8 > 57) )
    {
      HIDWORD(c) = "unknown escape char";
      idLib::Warning(fmt: c, a2, a3, a4: v8, a5: v15, a6: v16, a7: v17, a8: v18);
    }
    v12 = 0;
    v13 = (_BYTE *)(*v3 - 1);
    *v3 = v13;
    LOBYTE(v13) = *v13;
    *v4 = (_BYTE)v13;
    if ( (char)v13 >= 48 )
    {
      do
      {
        LODWORD(v14) = (unsigned __int8)*v4;
        HIDWORD(v14) = (char)v14;
        if ( (char)v14 > 57 )
          break;
        HIDWORD(v14) = (char)v14;
        LODWORD(a3) = 5 * v12;
        HIDWORD(a3) = (char)v14 - 48;
        LODWORD(a2) = SBYTE3(a3);
        *v4 = BYTE3(a3);
        v12 = 10 * v12 + SBYTE3(a3);
        HIDWORD(a2) = *v3 + 1;
        LODWORD(c) = HIDWORD(a2);
        *v3 = HIDWORD(a2);
        BYTE3(c) = *(_BYTE *)HIDWORD(a2);
        LODWORD(v14) = (char)*(_BYTE *)HIDWORD(a2);
        *v4 = *(_BYTE *)HIDWORD(a2);
      }
      while ( SBYTE3(c) >= 48 );
      if ( v12 > 255 )
      {
        HIDWORD(c) = "too large value in escape character";
        idLib::Warning(fmt: c, a2, a3, a4: v14, a5: v15, a6: v16, a7: v17, a8: v18);
        LOBYTE(v12) = -1;
        v5 = 1;
      }
    }
    *v4 = v12;
    return (_cntlzw(v5) & 0x20) != 0;
  }
}


// ========================================================================
// ?ToEscapedString@idStr@@SA_NPBDHPADH@Z
// EA  : 0x82F94FC0
// RVA : 0x00F94FC0
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::ToEscapedString(
        const char *str,
        int strLen,
        __int64 outSize,
        __int64 a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        const char *a10)
{
  int v11; // r28
  int v12; // r30
  int v13; // r31
  int v14; // r27
  __int64 v15; // r4
  bool v16; // r3
  char v18; // [sp+50h] [-40h] BYREF

  a10 = str;
  v11 = HIDWORD(outSize);
  if ( str == nullptr || HIDWORD(outSize) == 0 || (int)outSize <= 0 )
    return 0;
  v12 = 0;
  v13 = 0;
  if ( strLen > 0 )
  {
    v14 = outSize - 1;
    do
    {
      if ( v13 >= v14 )
        break;
      LODWORD(v15) = &v18;
      HIDWORD(v15) = &a10;
      v16 = idStr::EmitEscapeChar(c: v15, a2: outSize, a3: a4);
      *(_BYTE *)(v13 + v11) = v18;
      ++v13;
      LODWORD(a4) = (_cntlzw(v16) & 0x20) != 0;
      v12 |= a4;
    }
    while ( v13 < strLen );
  }
  *(_BYTE *)(v13 + v11) = 0;
  return v12;
}


// ========================================================================
// ?CopyString@@YAPADPBDW4memTag_t@@@Z
// EA  : 0x82F95060
// RVA : 0x00F95060
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

char *__fastcall CopyString(const char *str, memTag_t tag)
{
  int v3; // r11
  size_t v4; // r30
  void *v5; // r29

  v3 = 0;
  if ( *str != 0 )
  {
    do
      ++v3;
    while ( str[v3] != 0 );
  }
  v4 = v3 + 1;
  v5 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\text\\Str.cpp(22) : tag",
         size: v3 + 1,
         tag,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  memcpy(Dst: v5, Src: str, Size: v4);
  return (char *)v5;
}


// ========================================================================
// ?ReAllocate@idStr@@QAAXH_N@Z
// EA  : 0x82F950D8
// RVA : 0x00F950D8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::ReAllocate(idStr *this, int amount, bool keepold)
{
  int allocedAndFlag; // r11
  char *v6; // r3
  char *v7; // r30
  bool v8; // zf
  char *data; // r4
  idStr *v10; // r4

  allocedAndFlag = this->allocedAndFlag;
  if ( allocedAndFlag >= 0 )
  {
    this->allocedAndFlag = allocedAndFlag & 0x80000000 | (amount + 15) & 0x7FFFFFF0;
    v6 = (char *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\text\\Str.cpp(71) : TAG_STRING",
                   size: (amount + 15) & 0x7FFFFFF0,
                   tag: TAG_STRING,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
    v8 = !keepold;
    v7 = v6;
    if ( !v8 )
    {
      data = this->data;
      if ( data != nullptr )
      {
        if ( this->len != 0 )
        {
          strncpy(dest: v6, source: data, count: this->len);
          v7[this->len] = 0;
        }
        else
        {
          *v6 = 0;
        }
      }
    }
    v10 = (idStr *)this->data;
    if ( v10 != nullptr && v10 != (idStr *)this->baseBuffer )
      idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    this->data = v7;
  }
}


// ========================================================================
// ?FreeData@idStr@@QAAXXZ
// EA  : 0x82F951B0
// RVA : 0x00F951B0
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::FreeData(idStr *this)
{
  idStr *data; // r4
  char *baseBuffer; // r30

  if ( this->allocedAndFlag >= 0 )
  {
    data = (idStr *)this->data;
    if ( data != nullptr )
    {
      baseBuffer = this->baseBuffer;
      if ( data != (idStr *)this->baseBuffer )
      {
        idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
        this->data = baseBuffer;
      }
    }
  }
}


// ========================================================================
// ?Find@idStr@@SAHPBDDHH@Z
// EA  : 0x82F95220
// RVA : 0x00F95220
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::Find(const char *str, const char c, int start, int end)
{
  int v4; // r11
  int v5; // r10

  v4 = start;
  if ( end == -1 )
  {
    v5 = 0;
    if ( *str != 0 )
    {
      do
        ++v5;
      while ( str[v5] != 0 );
    }
    end = v5 - 1;
  }
  if ( start > end )
    return -1;
  while ( str[v4] != c )
  {
    if ( ++v4 > end )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?Find@idStr@@SAHPBD0_NHH@Z
// EA  : 0x82F95288
// RVA : 0x00F95288
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::Find(const char *searchIn, const char *searchFor, bool casesensitive, int start, int end)
{
  int v6; // r11
  int v7; // r11
  int v8; // r27
  int v9; // r28
  BOOL v10; // r26
  const char *i; // r29
  int v12; // r31
  int v13; // r11
  int v14; // r25

  if ( end == -1 )
  {
    v6 = 0;
    if ( *searchIn != 0 )
    {
      do
        ++v6;
      while ( searchIn[v6] != 0 );
    }
    end = v6;
  }
  v7 = 0;
  if ( *searchFor != 0 )
  {
    do
      ++v7;
    while ( searchFor[v7] != 0 );
  }
  v8 = end - v7;
  v9 = start;
  if ( start > end - v7 )
    return -1;
  v10 = casesensitive;
  for ( i = &searchIn[start]; ; ++i )
  {
    v12 = 0;
    if ( v10 )
    {
      v13 = *searchFor;
      if ( *searchFor != 0 )
      {
        do
        {
          if ( i[v12] != v13 )
            break;
          v13 = searchFor[++v12];
        }
        while ( searchFor[v12] != 0 );
      }
    }
    else if ( *searchFor != 0 )
    {
      do
      {
        v14 = toupper(c: i[v12]);
        if ( v14 != toupper(c: searchFor[v12]) )
          break;
        ++v12;
      }
      while ( searchFor[v12] != 0 );
    }
    if ( searchFor[v12] == 0 )
      break;
    if ( ++v9 > v8 )
      return -1;
  }
  return v9;
}


// ========================================================================
// ?Last@idStr@@QBAHDH@Z
// EA  : 0x82F953B8
// RVA : 0x00F953B8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::Last(idStr *this, const char c, int index)
{
  if ( index == -1 )
    index = this->len;
  if ( index < 0 )
    return -1;
  while ( this->data[index] != c )
  {
    if ( --index < 0 )
      return -1;
  }
  return index;
}


// ========================================================================
// ?StripTrailing@idStr@@QAAXD@Z
// EA  : 0x82F95400
// RVA : 0x00F95400
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::StripTrailing(idStr *this, const char c)
{
  int i; // r11
  char *v3; // r10

  for ( i = this->len; i > 0; --this->len )
  {
    v3 = &this->data[i];
    if ( *(v3 - 1) != c )
      break;
    *(v3 - 1) = 0;
    --i;
  }
}


// ========================================================================
// ?StripLeadingWhiteSpace@idStr@@QAAXXZ
// EA  : 0x82F95448
// RVA : 0x00F95448
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::StripLeadingWhiteSpace(idStr *this)
{
  int len; // r11
  int v3; // r31
  char *data; // r3

  len = this->len;
  v3 = 0;
  if ( this->len > 0 )
  {
    data = this->data;
    do
    {
      if ( (unsigned __int8)data[v3] > 0x20u )
        break;
      ++v3;
    }
    while ( v3 < this->len );
    if ( v3 > 0 && v3 != len )
    {
      memmove(Dst: data, Src: &data[v3], Size: len - v3 + 1);
      this->len -= v3;
    }
  }
}


// ========================================================================
// ?StripTrailingWhitespace@idStr@@QAAXXZ
// EA  : 0x82F954D8
// RVA : 0x00F954D8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::StripTrailingWhitespace(idStr *this)
{
  int i; // r11
  char *v2; // r10

  for ( i = this->len; i > 0; --this->len )
  {
    v2 = &this->data[i];
    if ( (unsigned __int8)*(v2 - 1) > 0x20u )
      break;
    *(v2 - 1) = 0;
    --i;
  }
}


// ========================================================================
// ?FileNameHash@idStr@@SAHPBDH@Z
// EA  : 0x82F95518
// RVA : 0x00F95518
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::FileNameHash(char *string, const int hashSize)
{
  char v2; // r11
  const char *v3; // r9
  int i; // r8
  char v5; // r10
  int v6; // r6

  v2 = *string;
  v3 = string;
  for ( i = 0; *v3 != 0; i += v6 * v5 )
  {
    if ( v2 > 90 || v2 < 65 )
      v5 = v2;
    else
      v5 = v2 + 32;
    if ( v5 == 46 )
      break;
    if ( v5 == 92 )
      v5 = 47;
    v6 = (int)&(v3++)[119 - (_DWORD)string];
    v2 = *v3;
  }
  return (hashSize - 1) & i;
}


// ========================================================================
// ?BackSlashesToSlashes@idStr@@SAXPAD@Z
// EA  : 0x82F95598
// RVA : 0x00F95598
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::BackSlashesToSlashes(char *path)
{
  int v1; // r11
  int v2; // r10
  int i; // ctr

  v1 = 0;
  if ( *path != 0 )
  {
    do
      ++v1;
    while ( path[v1] != 0 );
  }
  v2 = 0;
  if ( v1 > 0 )
  {
    for ( i = v1; i != 0; --i )
    {
      if ( path[v2] == 92 )
        path[v2] = 47;
      ++v2;
    }
  }
}


// ========================================================================
// ?SlashesToBackSlashes@idStr@@SAXPAD@Z
// EA  : 0x82F955E8
// RVA : 0x00F955E8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::SlashesToBackSlashes(char *path)
{
  int v1; // r11
  int v2; // r10
  int i; // ctr

  v1 = 0;
  if ( *path != 0 )
  {
    do
      ++v1;
    while ( path[v1] != 0 );
  }
  v2 = 0;
  if ( v1 > 0 )
  {
    for ( i = v1; i != 0; --i )
    {
      if ( path[v2] == 47 )
        path[v2] = 92;
      ++v2;
    }
  }
}


// ========================================================================
// ?StripFilename@idStr@@QAAAAV1@XZ
// EA  : 0x82F95638
// RVA : 0x00F95638
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

idStr *__fastcall idStr::StripFilename(idStr *this)
{
  int i; // r11
  int v2; // r10

  for ( i = this->len - 1; i > 0; --i )
  {
    v2 = this->data[i];
    if ( v2 == 47 )
      break;
    if ( v2 == 92 )
      break;
  }
  if ( this->len > i && i >= 0 )
  {
    this->data[i] = 0;
    this->len = i;
  }
  return this;
}


// ========================================================================
// ?IsNameCanonical@idStr@@SA_NQBD@Z
// EA  : 0x82F95690
// RVA : 0x00F95690
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::IsNameCanonical(const char *const name)
{
  int v2; // r11

  if ( name == nullptr )
    return 0;
  v2 = *name;
  if ( v2 == 47 && name[1] != 47 )
    return 0;
  if ( *name != 0 )
  {
    while ( v2 != 92 )
    {
      if ( v2 <= 90 && v2 >= 65 )
        break;
      v2 = *++name;
      if ( *name == 0 )
        return 1;
    }
    return 0;
  }
  return 1;
}


// ========================================================================
// ?Cmp@idStr@@SAHPBD0@Z
// EA  : 0x82F95720
// RVA : 0x00F95720
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

unsigned int __fastcall idStr::Cmp(const char *s1, const char *s2)
{
  int v2; // r9
  char v3; // r11
  int v4; // r8

  if ( s1 == nullptr || s2 == nullptr )
    return 1;
  v2 = s1 - s2;
  while ( 1 )
  {
    v3 = s2[v2];
    v4 = *s2++;
    if ( v3 != v4 )
      break;
    if ( v3 == 0 )
      return 0;
  }
  return (((unsigned int)~(v3 - v4) >> 30) & 2) - 1;
}


// ========================================================================
// ?Cmpn@idStr@@SAHPBD0H@Z
// EA  : 0x82F95778
// RVA : 0x00F95778
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

unsigned int __fastcall idStr::Cmpn(const char *s1, const char *s2, int n)
{
  int v3; // r9
  int v4; // r11
  int v5; // r10
  int v7; // r10

  v3 = s1 - s2;
  while ( 1 )
  {
    v4 = s2[v3];
    v5 = *s2++;
    if ( n-- == 0 )
      return 0;
    v7 = v4 - v5;
    if ( v7 != 0 )
      break;
    if ( v4 == 0 )
      return 0;
  }
  return (((unsigned int)~v7 >> 30) & 2) - 1;
}


// ========================================================================
// ?Icmp@idStr@@SAHPBD0@Z
// EA  : 0x82F957C8
// RVA : 0x00F957C8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

unsigned int __fastcall idStr::Icmp(const char *s1, const char *s2)
{
  int v2; // r8
  int v3; // r10
  int v4; // r9
  int v5; // r11

  v2 = s1 - s2;
  while ( 1 )
  {
    v3 = s2[v2];
    v4 = *s2++;
    v5 = v3 - v4;
    if ( v3 != v4 )
    {
      if ( v3 > 90 || v3 < 65 || (v5 += 32, v5 != 0) )
      {
        if ( v4 > 90 )
          break;
        if ( v4 < 65 )
          break;
        v5 -= 32;
        if ( v5 != 0 )
          break;
      }
    }
    if ( v3 == 0 )
      return 0;
  }
  return (((unsigned int)~v5 >> 30) & 2) - 1;
}


// ========================================================================
// ?Icmpn@idStr@@SAHPBD0H@Z
// EA  : 0x82F95838
// RVA : 0x00F95838
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

unsigned int __fastcall idStr::Icmpn(const char *s1, const char *s2, int n)
{
  int v3; // r8
  char v4; // r11
  int v5; // r10
  int v6; // r9
  int v8; // r11

  v3 = s1 - s2;
  while ( 1 )
  {
    v4 = s2[v3];
    v5 = v4;
    v6 = *s2++;
    if ( n-- == 0 )
      return 0;
    v8 = v4 - v6;
    if ( v5 != v6 )
    {
      if ( v5 > 90 || v5 < 65 || (v8 += 32, v8 != 0) )
      {
        if ( v6 > 90 )
          break;
        if ( v6 < 65 )
          break;
        v8 -= 32;
        if ( v8 != 0 )
          break;
      }
    }
    if ( v5 == 0 )
      return 0;
  }
  return (((unsigned int)~v8 >> 30) & 2) - 1;
}


// ========================================================================
// ?IcmpPath@idStr@@SAHPBD0@Z
// EA  : 0x82F958B8
// RVA : 0x00F958B8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::IcmpPath(const char *s1, const char *s2)
{
  int v2; // r11
  int v3; // r10
  int v4; // r8
  const char *v6; // r9
  const char *v7; // r9

  do
  {
    while ( 1 )
    {
      v2 = *s1++;
      v3 = *s2++;
      v4 = v2 - v3;
      if ( v2 != v3 )
      {
        if ( v2 > 90 )
          break;
        if ( v2 < 65 )
          break;
        v4 += 32;
        if ( v4 != 0 )
          break;
      }
LABEL_12:
      if ( v2 == 0 )
        return 0;
    }
    if ( v2 != 92 )
      break;
    v4 -= 45;
  }
  while ( v4 == 0 );
  if ( v3 <= 90 && v3 >= 65 )
  {
    v4 -= 32;
    if ( v4 == 0 )
      goto LABEL_12;
  }
  if ( v3 == 92 )
  {
    v4 += 45;
    if ( v4 == 0 )
      goto LABEL_12;
  }
  if ( v2 != 0 )
  {
    v6 = s1 - 1;
    do
    {
      if ( v2 == 47 )
        break;
      if ( v2 == 92 )
        break;
      v2 = *++v6;
    }
    while ( *v6 != 0 );
  }
  if ( v3 != 0 )
  {
    v7 = s2 - 1;
    do
    {
      if ( v3 == 47 )
        break;
      if ( v3 == 92 )
        break;
      v3 = *++v7;
    }
    while ( *v7 != 0 );
  }
  if ( v2 != 0 )
  {
    if ( v3 == 0 )
      return -1;
    return (((unsigned int)~v4 >> 30) & 2) - 1;
  }
  else
  {
    if ( v3 == 0 )
      return (((unsigned int)~v4 >> 30) & 2) - 1;
    return 1;
  }
}


// ========================================================================
// ?IcmpnPath@idStr@@SAHPBD0H@Z
// EA  : 0x82F959C8
// RVA : 0x00F959C8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::IcmpnPath(const char *s1, const char *s2, int n)
{
  int v3; // r11
  int v4; // r10
  int v6; // r8
  const char *v8; // r9
  const char *v9; // r9

  do
  {
    while ( 1 )
    {
      v3 = *s1++;
      v4 = *s2++;
      if ( n-- == 0 )
        return 0;
      v6 = v3 - v4;
      if ( v3 != v4 )
      {
        if ( v3 > 90 )
          break;
        if ( v3 < 65 )
          break;
        v6 += 32;
        if ( v6 != 0 )
          break;
      }
LABEL_13:
      if ( v3 == 0 )
        return 0;
    }
    if ( v3 != 92 )
      break;
    v6 -= 45;
  }
  while ( v6 == 0 );
  if ( v4 <= 90 && v4 >= 65 )
  {
    v6 -= 32;
    if ( v6 == 0 )
      goto LABEL_13;
  }
  if ( v4 == 92 )
  {
    v6 += 45;
    if ( v6 == 0 )
      goto LABEL_13;
  }
  if ( v3 != 0 )
  {
    v8 = s1 - 1;
    do
    {
      if ( v3 == 47 )
        break;
      if ( v3 == 92 )
        break;
      v3 = *++v8;
    }
    while ( *v8 != 0 );
  }
  if ( v4 != 0 )
  {
    v9 = s2 - 1;
    do
    {
      if ( v4 == 47 )
        break;
      if ( v4 == 92 )
        break;
      v4 = *++v9;
    }
    while ( *v9 != 0 );
  }
  if ( v3 != 0 )
  {
    if ( v4 == 0 )
      return -1;
    return (((unsigned int)~v6 >> 30) & 2) - 1;
  }
  else
  {
    if ( v4 == 0 )
      return (((unsigned int)~v6 >> 30) & 2) - 1;
    return 1;
  }
}


// ========================================================================
// ?Append@idStr@@SAXPADHPBD@Z
// EA  : 0x82F95AE8
// RVA : 0x00F95AE8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::Append(__int64 size, __int64 src, __int64 a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  __int64 v9; // r10
  int v10; // r11

  HIDWORD(v9) = (unsigned __int8)*(_BYTE *)HIDWORD(size);
  LODWORD(v9) = size;
  LODWORD(size) = HIDWORD(src);
  v10 = 0;
  if ( *(_BYTE *)HIDWORD(size) != 0 )
  {
    do
      HIDWORD(v9) = *(unsigned __int8 *)(++v10 + HIDWORD(size));
    while ( *(_BYTE *)(v10 + HIDWORD(size)) != 0 );
  }
  if ( v10 < (int)v9 )
  {
    HIDWORD(src) = v9 - v10;
    HIDWORD(size) += v10;
    idStr::Copynz(src: size, destsize: src, a3, a4: v9);
  }
  else
  {
    HIDWORD(size) = "idStr::Append: already overflowed";
    idLib::Error(fmt: size, a2: src, a3, a4: v9, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?LengthWithoutColors@idStr@@SAHPBD@Z
// EA  : 0x82F95B30
// RVA : 0x00F95B30
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::LengthWithoutColors(const char *s)
{
  const char *v1; // r11
  int result; // r3
  bool v3; // zf
  char v4; // r10

  v1 = s;
  v3 = s != nullptr;
  result = 0;
  if ( v3 && *v1 != 0 )
  {
    do
    {
      if ( v1 == nullptr || *v1 != 94 || v1[1] == 0 || (v4 = 1, v1[1] == 32) )
        v4 = 0;
      if ( v4 != 0 )
      {
        v1 += 2;
      }
      else
      {
        ++v1;
        ++result;
      }
    }
    while ( *v1 != 0 );
  }
  return result;
}


// ========================================================================
// ?RemoveColors@idStr@@SAPADPAD@Z
// EA  : 0x82F95BB0
// RVA : 0x00F95BB0
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

char *__fastcall idStr::RemoveColors(char *string)
{
  char *v1; // r10
  char *v2; // r8
  char i; // r9
  char v4; // r11

  v1 = string;
  v2 = string;
  for ( i = *string; *v1 != 0; i = *v1 )
  {
    if ( *v1 != 94 || v1[1] == 0 || (v4 = 1, v1[1] == 32) )
      v4 = 0;
    if ( v4 != 0 )
      ++v1;
    else
      *v2++ = i;
    ++v1;
  }
  *v2 = 0;
  return string;
}


// ========================================================================
// ?snPrintf@idStr@@SAHPADHPBDZZ
// EA  : 0x82F95C30
// RVA : 0x00F95C30
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int idStr::snPrintf(
        char *dest,
        int size,
        __int64 fmt,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        ...)
{
  int result; // r3
  __int64 v16; // [sp+98h] [+28h] BYREF
  va_list va; // [sp+98h] [+28h]
  __int64 v18; // [sp+A0h] [+30h]
  __int64 v19; // [sp+A8h] [+38h]
  __int64 v20; // [sp+B0h] [+40h]
  __int64 v21; // [sp+B8h] [+48h]
  va_list va1; // [sp+C0h] [+50h] BYREF

  va_start(va1, a13);
  va_start(va, a13);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v16 = fmt;
  v18 = *(__int64 *)((char *)&a4 + 4);
  v19 = a4;
  v20 = *(__int64 *)((char *)&a5 + 4);
  v21 = a5;
  result = vsnprintf(string: dest, count: size - 1, format: (const char *)HIDWORD(fmt), ap: va);
  dest[size - 1] = 0;
  if ( result < 0 || result >= size )
    return -1;
  return result;
}


// ========================================================================
// ?IsValidUTF8@idStr@@SA_NPBEHAAW4utf8Encoding_t@@@Z
// EA  : 0x82F95CB8
// RVA : 0x00F95CB8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::IsValidUTF8(const unsigned __int8 *s, int maxLen, utf8Encoding_t *encoding)
{
  utf8Encoding_t v3; // r30
  int v4; // r31
  int v5; // r7
  int v6; // r9
  int v7; // r8
  int v8; // r6
  unsigned int v9; // r11
  char v10; // r11
  char v11; // r11
  int v12; // r11
  char v13; // r11
  int v14; // r11
  int v15; // r11

  v3 = UTF8_ENCODED_NO_BOM;
  *encoding = UTF8_PURE_ASCII;
  if ( maxLen > 3 && *s == 239 && s[1] == 187 && s[2] == 191 )
    v3 = UTF8_ENCODED_BOM;
  v4 = 0;
  if ( *s != 0 )
  {
    v5 = 3;
    v6 = 1;
    v7 = 2;
    v8 = maxLen;
    while ( 1 )
    {
      if ( v4 >= maxLen )
        return 1;
      v9 = s[v4];
      if ( v9 >= 0x80 )
        break;
LABEL_41:
      ++v7;
      ++v4;
      --v8;
      ++v6;
      ++v5;
      if ( s[v4] == 0 )
        return 1;
    }
    if ( v9 >> 5 == 6 )
    {
      if ( v8 >= 1 )
      {
        v12 = v6;
        while ( s[v12] != 0 && (s[v12] & 0xC0) == 0x80 )
        {
          if ( ++v12 > v6 )
          {
            v11 = 1;
            goto LABEL_22;
          }
        }
      }
      v11 = 0;
LABEL_22:
      if ( v11 == 0 )
        return 0;
      ++v7;
      ++v4;
      --v8;
      ++v6;
      ++v5;
      goto LABEL_40;
    }
    if ( (s[v4] & 0xF0) != 0xE0 )
    {
      if ( v9 >> 5 != 30 )
      {
        *encoding = ((_cntlzw(v3 - 1) & 0x20) != 0) + 3;
        return 0;
      }
      if ( v8 >= 3 )
      {
        v15 = v6;
        if ( v6 > v5 )
        {
LABEL_37:
          v10 = 1;
          goto LABEL_38;
        }
        while ( s[v15] != 0 && (s[v15] & 0xC0) == 0x80 )
        {
          if ( ++v15 > v5 )
            goto LABEL_37;
        }
      }
      v10 = 0;
LABEL_38:
      if ( v10 == 0 )
        return 0;
      v7 += 3;
      v4 += 3;
      v8 -= 3;
      v6 += 3;
      v5 += 3;
      goto LABEL_40;
    }
    if ( v8 >= 2 )
    {
      v14 = v6;
      if ( v6 > v7 )
      {
LABEL_30:
        v13 = 1;
        goto LABEL_31;
      }
      while ( s[v14] != 0 && (s[v14] & 0xC0) == 0x80 )
      {
        if ( ++v14 > v7 )
          goto LABEL_30;
      }
    }
    v13 = 0;
LABEL_31:
    if ( v13 == 0 )
      return 0;
    v7 += 2;
    v4 += 2;
    v8 -= 2;
    v6 += 2;
    v5 += 2;
LABEL_40:
    *encoding = v3;
    goto LABEL_41;
  }
  return 1;
}


// ========================================================================
// ??4idStr@@QAAXPBD@Z
// EA  : 0x82F95EE8
// RVA : 0x00F95EE8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::operator=(idStr *this, char *text)
{
  char *data; // r11
  char v5; // r10
  const char *v6; // r9
  int i; // r11
  int v8; // r29
  const char *v9; // r10
  char *v10; // r9
  char v11; // r11

  if ( text != nullptr )
  {
    data = this->data;
    if ( text != data )
    {
      if ( text < data || text > &data[this->len] )
      {
        v8 = 0;
        if ( *text != 0 )
        {
          do
            ++v8;
          while ( text[v8] != 0 );
        }
        idStr::EnsureAlloced(this, amount: v8 + 1, keepold: false, geometricGrowth: false);
        v9 = text - 1;
        v10 = this->data - 1;
        do
        {
          v11 = *++v9;
          *++v10 = *v9;
        }
        while ( v11 != 0 );
        this->len = v8;
      }
      else
      {
        v5 = *text;
        v6 = (const char *)(text - data);
        for ( i = 0; v5 != 0; v5 = text[i] )
          this->data[i++] = v5;
        this->data[i] = 0;
        this->len -= (int)v6;
      }
    }
  }
  else
  {
    idStr::EnsureAlloced(this, amount: 1, keepold: false, geometricGrowth: false);
    *this->data = 0;
    this->len = 0;
  }
}


// ========================================================================
// ?FloatArrayToString@idStr@@SAPBDPBMHH@Z
// EA  : 0x82F96000
// RVA : 0x00F96000
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

char *__fastcall idStr::FloatArrayToString(const float *array, int length, signed int precision)
{
  __int64 v3; // r8
  __int64 v7; // r10
  char *v8; // r30
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r10
  __int64 v12; // r8
  int v13; // r3
  int v14; // r31
  char *v15; // r11
  __int64 v16; // r10
  __int64 v17; // r8
  float *v18; // r29
  int v19; // r28
  char *v20; // r11
  int v22; // [sp+8h] [-B8h]
  int v23; // [sp+8h] [-B8h]
  int v24; // [sp+8h] [-B8h]
  int v25; // [sp+8h] [-B8h]
  int v26; // [sp+Ch] [-B4h]
  int v27; // [sp+Ch] [-B4h]
  int v28; // [sp+Ch] [-B4h]
  int v29; // [sp+Ch] [-B4h]
  int v30; // [sp+10h] [-B0h]
  int v31; // [sp+10h] [-B0h]
  int v32; // [sp+10h] [-B0h]
  int v33; // [sp+10h] [-B0h]
  int v34; // [sp+14h] [-ACh]
  int v35; // [sp+14h] [-ACh]
  int v36; // [sp+14h] [-ACh]
  int v37; // [sp+14h] [-ACh]
  int v38; // [sp+18h] [-A8h]
  int v39; // [sp+18h] [-A8h]
  int v40; // [sp+18h] [-A8h]
  int v41; // [sp+18h] [-A8h]
  int v42; // [sp+1Ch] [-A4h]
  int v43; // [sp+1Ch] [-A4h]
  int v44; // [sp+1Ch] [-A4h]
  int v45; // [sp+1Ch] [-A4h]
  int v46; // [sp+20h] [-A0h]
  int v47; // [sp+20h] [-A0h]
  int v48; // [sp+20h] [-A0h]
  int v49; // [sp+20h] [-A0h]
  int v50; // [sp+24h] [-9Ch]
  int v51; // [sp+24h] [-9Ch]
  int v52; // [sp+24h] [-9Ch]
  int v53; // [sp+24h] [-9Ch]
  char v54[80]; // [sp+70h] [-50h] BYREF

  LODWORD(v3) = &str_0[3][7272];
  HIDWORD(v3) = &buffers_0[3][7280];
  LODWORD(v7) = str_0;
  HIDWORD(v7) = index_3 << 14;
  v8 = str_0[index_3];
  index_3 = ((_BYTE)index_3 + 1) & 3;
  idStr::snPrintf(
    dest: v54,
    size: 16,
    fmt: __SPAIR64__("%%.%df", precision),
    a4: v3,
    a5: v7,
    a6: v22,
    a7: v26,
    a8: v30,
    a9: v34,
    a10: v38,
    a11: v42,
    a12: v46,
    a13: v50);
  v13 = idStr::snPrintf(
          dest: v8,
          size: 0x4000,
          fmt: __SPAIR64__(v54, COERCE_UNSIGNED_INT64(*array)),
          a4: v10,
          a5: v9,
          a6: v23,
          a7: v27,
          a8: v31,
          a9: v35,
          a10: v39,
          a11: v43,
          a12: v47,
          a13: v51);
  v14 = v13;
  if ( precision > 0 && v13 > 0 )
  {
    v15 = v8 - 1;
    while ( 1 )
    {
      LODWORD(v11) = (unsigned __int8)v15[v14];
      if ( (_DWORD)v11 != 48 )
        break;
      v8[--v14] = 0;
      if ( v14 <= 0 )
        goto LABEL_10;
    }
    for ( ; v14 > 0; v8[--v14] = 0 )
    {
      LODWORD(v11) = (unsigned __int8)v15[v14];
      if ( (_DWORD)v11 != 46 )
        break;
    }
  }
LABEL_10:
  idStr::snPrintf(
    dest: v54,
    size: 16,
    fmt: __SPAIR64__(" %%.%df", precision),
    a4: v12,
    a5: v11,
    a6: v24,
    a7: v28,
    a8: v32,
    a9: v36,
    a10: v40,
    a11: v44,
    a12: v48,
    a13: v52);
  if ( length > 1 )
  {
    v18 = (float *)(array + 1);
    v19 = length - 1;
    do
    {
      v14 += idStr::snPrintf(
               dest: &v8[v14],
               size: 0x4000 - v14,
               fmt: COERCE__INT64(*v18),
               a4: v17,
               a5: v16,
               a6: v25,
               a7: v29,
               a8: v33,
               a9: v37,
               a10: v41,
               a11: v45,
               a12: v49,
               a13: v53);
      if ( precision > 0 && v14 > 0 )
      {
        v20 = v8 - 1;
        while ( 1 )
        {
          LODWORD(v16) = (unsigned __int8)v20[v14];
          if ( (_DWORD)v16 != 48 )
            break;
          v8[--v14] = 0;
          if ( v14 <= 0 )
            goto LABEL_20;
        }
        do
        {
          LODWORD(v16) = (unsigned __int8)v20[v14];
          if ( (_DWORD)v16 != 46 )
            break;
          v8[--v14] = 0;
        }
        while ( v14 > 0 );
      }
LABEL_20:
      --v19;
      ++v18;
    }
    while ( v19 != 0 );
  }
  return v8;
}


// ========================================================================
// ?StripLeading@idStr@@QAAXPBD@Z
// EA  : 0x82F96178
// RVA : 0x00F96178
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::StripLeading(idStr *this, const char *string)
{
  int v4; // r31

  v4 = 0;
  if ( *string != 0 )
  {
    do
      ++v4;
    while ( string[v4] != 0 );
    if ( v4 > 0 && idStr::Cmpn(this, text: string, n: v4) == 0 )
    {
      do
      {
        memmove(Dst: this->data, Src: &this->data[v4], Size: this->len - v4 + 1);
        this->len -= v4;
      }
      while ( idStr::Cmpn(this, text: string, n: v4) == 0 );
    }
  }
}


// ========================================================================
// ?StripLeadingOnce@idStr@@QAA_NPBD@Z
// EA  : 0x82F96210
// RVA : 0x00F96210
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::StripLeadingOnce(idStr *this, const char *string)
{
  int v3; // r31

  v3 = 0;
  if ( *string == 0 )
    return 0;
  do
    ++v3;
  while ( string[v3] != 0 );
  if ( v3 <= 0 || idStr::Cmpn(this, text: string, n: v3) != 0 )
    return 0;
  memmove(Dst: this->data, Src: &this->data[v3], Size: this->len - v3 + 1);
  this->len -= v3;
  return 1;
}


// ========================================================================
// ?StripTrailing@idStr@@QAAXPBD@Z
// EA  : 0x82F962B0
// RVA : 0x00F962B0
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::StripTrailing(idStr *this, const char *string)
{
  int v2; // r8
  char *data; // r5
  int v4; // r10
  int len; // r31
  int v6; // r11
  const char *v7; // r6
  int v8; // r9
  int v9; // r7
  int v11; // r7

  v2 = 0;
  if ( *string != 0 )
  {
    do
      ++v2;
    while ( string[v2] != 0 );
    if ( v2 > 0 && this->len >= v2 )
    {
      do
      {
        data = this->data;
        v4 = v2;
        len = this->len;
        v6 = (int)&data[this->len - v2];
        v7 = &string[-v6];
        do
        {
          v8 = v7[v6];
          v9 = *(char *)v6++;
          if ( v4-- == 0 )
            break;
          v11 = v8 - v9;
          if ( v11 != 0 )
          {
            if ( (((unsigned int)~v11 >> 30) & 2) != 1 )
              return;
            break;
          }
        }
        while ( v8 != 0 );
        this->len = len - v2;
        data[len - v2] = 0;
      }
      while ( this->len >= v2 );
    }
  }
}


// ========================================================================
// ?StripTrailingOnce@idStr@@QAA_NPBD@Z
// EA  : 0x82F96378
// RVA : 0x00F96378
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::StripTrailingOnce(idStr *this, const char *string)
{
  int v2; // r9
  int len; // r31
  char *data; // r5
  int v5; // r10
  char *v6; // r11
  const char *v7; // r6
  int v8; // r8
  int v9; // r7
  int v11; // r7

  v2 = 0;
  if ( *string == 0 )
    return 0;
  do
    ++v2;
  while ( string[v2] != 0 );
  if ( v2 <= 0 )
    return 0;
  len = this->len;
  if ( this->len < v2 )
    return 0;
  data = this->data;
  v5 = v2;
  v6 = &data[len - v2];
  v7 = (const char *)(string - v6);
  do
  {
    v8 = v6[(_DWORD)v7];
    v9 = *v6++;
    if ( v5-- == 0 )
      break;
    v11 = v8 - v9;
    if ( v11 != 0 )
    {
      if ( (((unsigned int)~v11 >> 30) & 2) != 1 )
        return 0;
      break;
    }
  }
  while ( v8 != 0 );
  this->len = len - v2;
  data[len - v2] = 0;
  return 1;
}


// ========================================================================
// ?Replace@idStr@@QAA_NPBD0@Z
// EA  : 0x82F96440
// RVA : 0x00F96440
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::Replace(idStr *this, char *old, const char *nw)
{
  int v6; // r11
  int v7; // r28
  size_t v8; // r25
  int v9; // r30
  int v10; // r6
  char *data; // r4
  int v12; // r10
  char *v13; // r11
  int v14; // r9
  int v15; // r8
  bool v16; // zf
  int v17; // r8
  int v18; // r4
  int v19; // r30
  int i; // r29
  int v21; // r10
  char *v22; // r11
  int v23; // r9
  int v24; // r8
  int v25; // r8
  int v26; // r11
  char *v27; // r8
  idStr v29[3]; // [sp+50h] [-70h] BYREF

  v6 = 0;
  if ( *old == 0 )
    return 0;
  do
    ++v6;
  while ( old[v6] != 0 );
  if ( v6 == 0 )
    return 0;
  v7 = 0;
  do
    ++v7;
  while ( old[v7] != 0 );
  v8 = 0;
  if ( *nw != 0 )
  {
    do
      ++v8;
    while ( nw[v8] != 0 );
  }
  v9 = 0;
  v10 = 0;
  if ( this->len <= 0 )
    return 0;
  data = this->data;
  do
  {
    v12 = v7;
    v13 = old;
    do
    {
      v14 = v13[data - old + v10];
      v15 = *v13++;
      v16 = v12-- == 0;
      if ( v16 )
        break;
      v17 = v14 - v15;
      if ( v17 != 0 )
      {
        if ( (((unsigned int)~v17 >> 30) & 2) != 1 )
          goto LABEL_17;
        break;
      }
    }
    while ( v14 != 0 );
    ++v9;
    v10 = v7 + v10 - 1;
LABEL_17:
    ++v10;
  }
  while ( v10 < this->len );
  if ( v9 == 0 )
    return 0;
  idStr::idStr(this: v29, text: data);
  v18 = (v8 - v7) * v9 + this->len + 2;
  v19 = 0;
  idStr::EnsureAlloced(this, amount: v18, keepold: false, geometricGrowth: false);
  for ( i = 0; i < v29[0].len; ++i )
  {
    v21 = v7;
    v22 = old;
    while ( 1 )
    {
      v23 = v22[&v29[0].data[i] - old];
      v24 = *v22++;
      v16 = v21-- == 0;
      if ( v16 )
        goto LABEL_26;
      v25 = v23 - v24;
      if ( v25 != 0 )
        break;
      if ( v23 == 0 )
        goto LABEL_26;
    }
    if ( (((unsigned int)~v25 >> 30) & 2) == 1 )
    {
LABEL_26:
      memcpy(Dst: &this->data[v19], Src: nw, Size: v8);
      v19 += v8;
      i = v7 + i - 1;
      continue;
    }
    this->data[v19++] = v29[0].data[i];
  }
  v26 = 0;
  this->data[v19] = 0;
  v27 = this->data;
  if ( *v27 != 0 )
  {
    do
      ++v26;
    while ( v27[v26] != 0 );
  }
  this->len = v26;
  if ( v29[0].allocedAndFlag >= 0 && v29[0].data != nullptr && v29[0].data != v29[0].baseBuffer )
    idMem::Free(this: &mem, ptr: (_DWORD *)v29[0].data, align: ALIGN_16);
  return 1;
}


// ========================================================================
// __unwind$113786
// EA  : 0x82F966B0
// RVA : 0x00F966B0
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void _unwind_113786()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?IReplace@idStr@@QAA_NPBD0@Z
// EA  : 0x82F966E0
// RVA : 0x00F966E0
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::IReplace(idStr *this, const char *old, const char *nw)
{
  int v6; // r11
  int v7; // r28
  size_t v8; // r26
  int v9; // r30
  int v10; // r7
  char *data; // r6
  int len; // r29
  int v13; // r7
  int v14; // r29
  int i; // r30
  char *v16; // r7
  unsigned int v17; // r3
  char *v18; // r11
  int v19; // r11
  char *v20; // r8
  idStr v22[3]; // [sp+50h] [-70h] BYREF

  v6 = 0;
  if ( *old == 0 )
    return 0;
  do
    ++v6;
  while ( old[v6] != 0 );
  if ( v6 == 0 )
    return 0;
  v7 = 0;
  do
    ++v7;
  while ( old[v7] != 0 );
  v8 = 0;
  if ( *nw != 0 )
  {
    do
      ++v8;
    while ( nw[v8] != 0 );
  }
  v9 = 0;
  v10 = 0;
  if ( this->len <= 0 )
    return 0;
  data = this->data;
  len = this->len;
  do
  {
    if ( idStr::Icmpn(s1: &data[v10], s2: old, n: v7) == 0 )
    {
      ++v9;
      v13 = v7 + v13 - 1;
    }
    v10 = v13 + 1;
  }
  while ( v10 < len );
  if ( v9 == 0 )
    return 0;
  idStr::idStr(this: v22, text: data);
  idStr::EnsureAlloced(this, amount: (v8 - v7) * v9 + this->len + 2, keepold: false, geometricGrowth: false);
  v14 = 0;
  for ( i = 0; v14 < v22[0].len; ++v14 )
  {
    v17 = idStr::Icmpn(s1: &v22[0].data[v14], s2: old, n: v7);
    v18 = this->data;
    if ( v17 != 0 )
    {
      v18[i++] = *v16;
    }
    else
    {
      memcpy(Dst: &v18[i], Src: nw, Size: v8);
      i += v8;
      v14 = v7 + v14 - 1;
    }
  }
  v19 = 0;
  this->data[i] = 0;
  v20 = this->data;
  if ( *v20 != 0 )
  {
    do
      ++v19;
    while ( v20[v19] != 0 );
  }
  this->len = v19;
  if ( v22[0].allocedAndFlag >= 0 && v22[0].data != nullptr && v22[0].data != v22[0].baseBuffer )
    idMem::Free(this: &mem, ptr: (_DWORD *)v22[0].data, align: ALIGN_16);
  return 1;
}


// ========================================================================
// __unwind$113931
// EA  : 0x82F968D4
// RVA : 0x00F968D4
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void _unwind_113931()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?ReplaceFirst@idStr@@QAA_NPBD0@Z
// EA  : 0x82F96908
// RVA : 0x00F96908
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

int __fastcall idStr::ReplaceFirst(idStr *this, char *old, const char *nw)
{
  int v6; // r11
  int v7; // r27
  size_t v8; // r25
  char v9; // r5
  int v10; // r6
  int v11; // r7
  int v12; // r10
  char *v13; // r11
  int v14; // r9
  int v15; // r8
  bool v16; // zf
  int v17; // r8
  int v18; // r30
  int i; // r29
  int v20; // r10
  char *v21; // r11
  char *v22; // r6
  int v23; // r9
  int v24; // r8
  int v25; // r8
  int v26; // r11
  char *data; // r5
  idStr v29[3]; // [sp+50h] [-70h] BYREF

  v6 = 0;
  if ( *old == 0 )
    return 0;
  do
    ++v6;
  while ( old[v6] != 0 );
  if ( v6 == 0 )
    return 0;
  v7 = 0;
  do
    ++v7;
  while ( old[v7] != 0 );
  v8 = 0;
  if ( *nw != 0 )
  {
    do
      ++v8;
    while ( nw[v8] != 0 );
  }
  v9 = 0;
  v10 = 0;
  if ( this->len > 0 )
  {
    v11 = this->data - old;
    do
    {
      v12 = v7;
      v13 = old;
      while ( 1 )
      {
        v14 = v13[v11];
        v15 = *v13++;
        v16 = v12-- == 0;
        if ( v16 )
          goto LABEL_14;
        v17 = v14 - v15;
        if ( v17 != 0 )
          break;
        if ( v14 == 0 )
          goto LABEL_14;
      }
      if ( (((unsigned int)~v17 >> 30) & 2) == 1 )
      {
LABEL_14:
        v9 = 1;
        break;
      }
      ++v10;
      ++v11;
    }
    while ( v10 < this->len );
  }
  if ( v9 == 0 )
    return 0;
  idStr::idStr(this: v29, text: this->data);
  idStr::EnsureAlloced(this, amount: this->len - v7 + v8 + 2, keepold: false, geometricGrowth: false);
  v18 = 0;
  for ( i = 0; v18 < v29[0].len; ++i )
  {
    v20 = v7;
    v21 = old;
    v22 = &v29[0].data[v18];
    while ( 1 )
    {
      v23 = v21[&v29[0].data[v18] - old];
      v24 = *v21++;
      v16 = v20-- == 0;
      if ( v16 )
        goto LABEL_21;
      v25 = v23 - v24;
      if ( v25 != 0 )
        break;
      if ( v23 == 0 )
        goto LABEL_21;
    }
    if ( (((unsigned int)~v25 >> 30) & 2) == 1 )
    {
LABEL_21:
      memcpy(Dst: &this->data[i], Src: nw, Size: v8);
      v18 += v7;
      i += v8;
      break;
    }
    ++v18;
    this->data[i] = *v22;
  }
  memcpy(Dst: &this->data[i], Src: &v29[0].data[v18], Size: v29[0].len - v18);
  v26 = 0;
  this->data[v29[0].len - v18 + i] = 0;
  data = this->data;
  if ( *data != 0 )
  {
    do
      ++v26;
    while ( data[v26] != 0 );
  }
  this->len = v26;
  if ( v29[0].allocedAndFlag >= 0 && v29[0].data != nullptr && v29[0].data != v29[0].baseBuffer )
    idMem::Free(this: &mem, ptr: (_DWORD *)v29[0].data, align: ALIGN_16);
  return 1;
}


// ========================================================================
// __unwind$114019
// EA  : 0x82F96B8C
// RVA : 0x00F96B8C
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void _unwind_114019()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?Mid@idStr@@QBAPBDHHAAV1@@Z
// EA  : 0x82F96BB8
// RVA : 0x00F96BB8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

char *__fastcall idStr::Mid(idStr *this, int start, int len, idStr *result)
{
  int v8; // r11

  idStr::EnsureAlloced(this: result, amount: 1, keepold: true, geometricGrowth: false);
  *result->data = 0;
  result->len = 0;
  v8 = this->len;
  if ( this->len == 0 || len <= 0 || start >= v8 )
    return nullptr;
  if ( start + len >= v8 )
    len = v8 - start;
  idStr::Append(this: result, text: &this->data[start], l: len);
  return result->data;
}


// ========================================================================
// ?Mid@idStr@@QBA?AV1@HH@Z
// EA  : 0x82F96C58
// RVA : 0x00F96C58
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

idStr *__fastcall idStr::Mid(idStr *this, idStr *result, int start, int len)
{
  int v5; // r11
  idStr v7; // [sp+60h] [-40h] BYREF

  v7.allocedAndFlag = 20;
  v7.data = v7.baseBuffer;
  v7.len = 0;
  v7.baseBuffer[0] = 0;
  v5 = result->len;
  if ( result->len != 0 && len > 0 && start < v5 )
  {
    if ( start + len >= v5 )
      len = v5 - start;
    idStr::Append(this: &v7, text: &result->data[start], l: len);
    idStr::idStr(this, text: &v7);
  }
  else
  {
    idStr::idStr(this, text: &v7);
  }
  idStrStatic<260>::~idStrStatic<260>(this: &v7);
  return this;
}


// ========================================================================
// __unwind$114194
// EA  : 0x82F96D2C
// RVA : 0x00F96D2C
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void _unwind_114194()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$114195
// EA  : 0x82F96D54
// RVA : 0x00F96D54
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void _unwind_114195()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 160;
  if ( (*(_DWORD *)(v0 - 160 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 180));
  }
}


// ========================================================================
// ?VFormat@idStr@@QAAXPBDPAD@Z
// EA  : 0x82F96D98
// RVA : 0x00F96D98
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::VFormat(idStr *this, const char *fmt, char *argptr)
{
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  unsigned int v8; // r3
  int v9; // [sp+8h] [-1068h]
  int v10; // [sp+Ch] [-1064h]
  int v11; // [sp+10h] [-1060h]
  int v12; // [sp+14h] [-105Ch]
  char v13[4104]; // [sp+50h] [-1020h] BYREF

  v8 = vsnprintf(string: v13, count: 0xFFEu, format: fmt, ap: argptr);
  v13[4094] = 0;
  if ( v8 > 0xFFE )
    v8 = -1;
  v13[4095] = 0;
  if ( v8 >= 0xFFF )
    idLib::FatalError(
      fmt: __SPAIR64__("Tried to printf a large buffer using %s", (unsigned int)fmt),
      a2: v7,
      a3: v6,
      a4: v5,
      a5: v9,
      a6: v10,
      a7: v11,
      a8: v12);
  idStr::operator=(this, text: v13);
}


// ========================================================================
// ?Format@idStr@@QAAXPBDZZ
// EA  : 0x82F96E28
// RVA : 0x00F96E28
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idStr::Format(
        idStr *this,
        const char *fmt,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        ...)
{
  __int64 v11; // [sp+80h] [+20h] BYREF
  va_list va; // [sp+80h] [+20h]
  __int64 v13; // [sp+88h] [+28h]
  __int64 v14; // [sp+90h] [+30h]
  __int64 v15; // [sp+98h] [+38h]
  __int64 v16; // [sp+A0h] [+40h]
  __int64 v17; // [sp+A8h] [+48h]
  va_list va1; // [sp+B0h] [+50h] BYREF

  va_start(va1, a11);
  va_start(va, a11);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v11 = *(__int64 *)((char *)&a3 + 4);
  v13 = a3;
  v14 = *(__int64 *)((char *)&a4 + 4);
  v15 = a4;
  v16 = *(__int64 *)((char *)&a5 + 4);
  v17 = a5;
  idStr::VFormat(this, fmt, argptr: va);
}


// ========================================================================
// ?SetFileExtension@idStr@@QAAAAV1@PBD@Z
// EA  : 0x82F96E78
// RVA : 0x00F96E78
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

idStr *__fastcall idStr::SetFileExtension(idStr *this, char *extension)
{
  idStr *v4; // r3
  _BYTE *v5; // r4

  v4 = idStr::StripFileExtension(this);
  if ( *v5 != 46 )
    idStr::Append(this: v4, a: 46);
  idStr::Append(this, text: extension);
  return this;
}


// ========================================================================
// ?DefaultFileExtension@idStr@@QAAAAV1@PBD@Z
// EA  : 0x82F96ED8
// RVA : 0x00F96ED8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

idStr *__fastcall idStr::DefaultFileExtension(idStr *this, char *extension, int a3, int a4, bool a5)
{
  int i; // r10
  int v8; // r11
  unsigned int allocedAndFlag; // r10
  int v10; // r11
  __int64 v11; // r10
  bool v12; // zf
  __int64 v13; // r6
  char *data; // r7
  int v15; // r11

  for ( i = this->len - 1; i >= 0; --i )
  {
    v8 = this->data[i];
    if ( v8 == 92 || v8 == 47 )
      break;
    if ( v8 == 46 )
      return this;
  }
  if ( *extension != 46 )
  {
    allocedAndFlag = this->allocedAndFlag;
    v10 = this->len + 2;
    HIDWORD(v11) = allocedAndFlag >> 31;
    v12 = allocedAndFlag >> 31 == 0;
    LODWORD(v11) = allocedAndFlag & 0x7FFFFFFF;
    if ( v12 )
    {
      if ( v10 > (int)v11 )
        idStr::ReAllocate(this, amount: (v10 >> 1) + v10, keepold: true);
    }
    else if ( v10 > (int)v11 )
    {
      LODWORD(v11) = 0x82000000;
      HIDWORD(v13) = "amount <= GetAlloced()";
      LODWORD(v13) = 1;
      if ( (unsigned __int8)AssertFailed(
                              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                              expression: v13,
                              inlineBreak: a5,
                              a4: v11) != 0 )
        __trap();
    }
    this->data[this->len] = 46;
    data = this->data;
    v15 = this->len + 1;
    this->len = v15;
    data[v15] = 0;
  }
  idStr::Append(this, text: extension);
  return this;
}


// ========================================================================
// ?AppendPath@idStr@@QAAXPBD@Z
// EA  : 0x82F96FF8
// RVA : 0x00F96FF8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::AppendPath(idStr *this, const char *text)
{
  int v4; // r28
  int len; // r31
  int v6; // r11
  char *v7; // r11
  int v8; // r10
  int v9; // r11
  const char *v10; // r10
  int v11; // r11
  char *data; // r11

  v4 = 0;
  if ( text != nullptr && *text != 0 )
  {
    len = this->len;
    v6 = 0;
    do
      ++v6;
    while ( text[v6] != 0 );
    idStr::EnsureAlloced(this, amount: len + v6 + 2, keepold: true, geometricGrowth: false);
    if ( len != 0 )
    {
      v7 = &this->data[len];
      v8 = *(v7 - 1);
      if ( v8 != 47 && v8 != 92 )
      {
        ++len;
        *v7 = 47;
      }
    }
    v9 = *text;
    if ( v9 == 47 || v9 == 92 )
      v4 = 1;
    if ( text[v4] != 0 )
    {
      v10 = &text[v4];
      do
      {
        v11 = *(unsigned __int8 *)v10;
        if ( v11 == 92 )
          this->data[len] = 47;
        else
          this->data[len] = v11;
        ++v10;
        ++len;
      }
      while ( *v10 != 0 );
    }
    data = this->data;
    this->len = len;
    data[len] = 0;
  }
}


// ========================================================================
// ?ExtractFileBase@idStr@@QBAXAAV1@@Z
// EA  : 0x82F97100
// RVA : 0x00F97100
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::ExtractFileBase(idStr *this, idStr *dest)
{
  int len; // r8
  int v3; // r11
  char *data; // r9
  char *v5; // r10
  int v6; // r10
  int i; // r9

  len = this->len;
  v3 = this->len - 1;
  if ( v3 > 0 )
  {
    data = this->data;
    v5 = &data[v3];
    do
    {
      v6 = *(v5 - 1);
      if ( v6 == 47 )
        break;
      if ( v6 == 92 )
        break;
      v5 = &data[--v3];
    }
    while ( v3 > 0 );
  }
  for ( i = v3; v3 < len; ++v3 )
  {
    if ( this->data[v3] == 46 )
      break;
  }
  idStr::Mid(this, start: i, len: v3 - i, result: dest);
}


// ========================================================================
// ?FormatInt@idStr@@SA?AV1@H_N@Z
// EA  : 0x82F97178
// RVA : 0x00F97178
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

idStr *__fastcall idStr::FormatInt(idStr *result, const int num, __int64 isCash, __int64 a4, __int64 a5)
{
  char v6; // r26
  int v7; // r28
  va *v8; // r3
  int v9; // r27
  int v10; // r29
  int v11; // r5
  idStr *v12; // r3
  int v13; // [sp+8h] [-1098h]
  int v14; // [sp+Ch] [-1094h]
  int v15; // [sp+10h] [-1090h]
  int v16; // [sp+14h] [-108Ch]
  int v17; // [sp+18h] [-1088h]
  int v18; // [sp+1Ch] [-1084h]
  va v19; // [sp+60h] [-1040h] BYREF

  v6 = BYTE3(isCash);
  LODWORD(a5) = 0x82000000;
  v7 = 0;
  HIDWORD(isCash) = num;
  v8 = va::va(this: &v19, fmt: "%d", a3: isCash, a4, a5, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
  idStr::idStr(this: result, text: v8);
  v9 = (result->len - 1) / 3;
  if ( v9 > 0 )
  {
    v10 = 0;
    do
    {
      v11 = result->len - v10 - 3;
      if ( v11 > 1 || *result->data != 45 )
        idStr::Insert(this: result, a: 44, index: v11);
      ++v7;
      v10 += 4;
    }
    while ( v7 < v9 );
  }
  v12 = result;
  if ( v6 != 0 )
  {
    idStr::Insert(this: result, a: 36, index: (_cntlzw(*(unsigned __int8 *)result->data - 45) & 0x20) != 0);
    return result;
  }
  return v12;
}


// ========================================================================
// __unwind$114366
// EA  : 0x82F9725C
// RVA : 0x00F9725C
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void _unwind_114366()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 4256;
  if ( (*(_DWORD *)(v0 - 4256 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 4276));
  }
}


// ========================================================================
// ?Erase@idStr@@QAAXHH@Z
// EA  : 0x82F972A0
// RVA : 0x00F972A0
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::Erase(idStr *this, unsigned int start, int len)
{
  int v3; // r29
  int v5; // r31
  unsigned int v6; // r11

  v3 = this->len;
  v5 = len;
  if ( this->len != 0 )
  {
    v6 = ((start >> 31) - 1) & start;
    if ( len == -1 )
      v5 = v3 - v6;
    if ( v5 == v3 )
    {
      idStr::EnsureAlloced(this, amount: 1, keepold: true, geometricGrowth: false);
      *this->data = 0;
      this->len = 0;
    }
    else
    {
      if ( v3 - v6 != v5 )
        memmove(Dst: &this->data[v6], Src: &this->data[v6 + v5], Size: v3 - v6 - v5);
      this->data[v3 - v5] = 0;
      this->len -= v5;
    }
  }
}


// ========================================================================
// ?AppendUTF8Char@idStr@@QAAXI@Z
// EA  : 0x82F97350
// RVA : 0x00F97350
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::AppendUTF8Char(idStr *this, unsigned int c)
{
  if ( c >= 0x80 )
  {
    if ( c >= 0x800 )
    {
      if ( c >= 0x10000 )
      {
        if ( c >= 0x200000 )
        {
          idStr::Append(this, a: 63);
        }
        else
        {
          idStr::Append(this, a: __ROL4__(c, 14) & 0xF | 0xF0);
          idStr::Append(this, a: __ROR4__(c, 12) & 0x3F | 0x80);
          idStr::Append(this, a: (c >> 6) & 0x3F | 0x80);
          idStr::Append(this, a: c & 0x3F | 0x80);
        }
      }
      else
      {
        idStr::Append(this, a: __ROR4__(c, 12) & 0x1F | 0xE0);
        idStr::Append(this, a: __ROR4__(c, 6) & 0x3F | 0x80);
        idStr::Append(this, a: c & 0x3F | 0x80);
      }
    }
    else
    {
      idStr::Append(this, a: __ROR4__(c, 6) & 0x3F | 0xC0);
      idStr::Append(this, a: c & 0x3F | 0x80);
    }
  }
  else
  {
    idStr::Append(this, a: c);
  }
}


// ========================================================================
// ?StripUntil@idStr@@QAAXPBD@Z
// EA  : 0x82F97488
// RVA : 0x00F97488
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::StripUntil(idStr *this, const char *until)
{
  int v3; // r3

  v3 = idStr::Find(searchIn: this->data, searchFor: until, casesensitive: true, start: 0, end: -1);
  if ( v3 != -1 )
    idStr::Erase(this, start: 0, len: v3 + 1);
}


// ========================================================================
// ?DefaultPath@idStr@@QAAAAV1@PBD@Z
// EA  : 0x82F974E8
// RVA : 0x00F974E8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

idStr *__fastcall idStr::DefaultPath(idStr *this, const char *basepath)
{
  char v3; // r10
  idStr *v4; // r28
  size_t len; // r29
  idStr v7[2]; // [sp+50h] [-50h] BYREF

  v3 = *this->data;
  if ( v3 != 47 && v3 != 92 )
  {
    v4 = operator+(result: v7, a: basepath, b: this);
    len = v4->len;
    idStr::EnsureAlloced(this, amount: v4->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->data, Src: v4->data, Size: len);
    this->data[len] = 0;
    this->len = len;
    idStrStatic<260>::~idStrStatic<260>(this: v7);
  }
  return this;
}


// ========================================================================
// __unwind$114795
// EA  : 0x82F97574
// RVA : 0x00F97574
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void _unwind_114795()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?StripPath@idStr@@QAAAAV1@XZ
// EA  : 0x82F975A8
// RVA : 0x00F975A8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

idStr *__fastcall idStr::StripPath(idStr *this)
{
  int len; // r8
  int v3; // r11
  char *data; // r9
  char *v5; // r10
  int v6; // r10
  idStr *v7; // r28
  size_t v8; // r29
  idStr v10[2]; // [sp+60h] [-50h] BYREF

  len = this->len;
  v3 = this->len;
  if ( this->len > 0 )
  {
    data = this->data;
    v5 = &data[len];
    do
    {
      v6 = *(v5 - 1);
      if ( v6 == 47 )
        break;
      if ( v6 == 92 )
        break;
      v5 = &data[--v3];
    }
    while ( v3 > 0 );
  }
  v7 = idStr::Right(this: v10, result: this, len: len - v3);
  v8 = v7->len;
  idStr::EnsureAlloced(this, amount: v7->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->data, Src: v7->data, Size: v8);
  this->data[v8] = 0;
  this->len = v8;
  if ( v10[0].allocedAndFlag >= 0 && v10[0].data != nullptr && v10[0].data != v10[0].baseBuffer )
    idMem::Free(this: &mem, ptr: (_DWORD *)v10[0].data, align: ALIGN_16);
  return this;
}


// ========================================================================
// __unwind$114830
// EA  : 0x82F9768C
// RVA : 0x00F9768C
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void _unwind_114830()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?ExtractFilePath@idStr@@QBAXAAV1@@Z
// EA  : 0x82F976B8
// RVA : 0x00F976B8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::ExtractFilePath(idStr *this, idStr *dest)
{
  int len; // r5
  char *data; // r10
  char *v4; // r11
  int v5; // r11

  len = this->len;
  if ( this->len > 0 )
  {
    data = this->data;
    v4 = &data[len];
    do
    {
      v5 = *(v4 - 1);
      if ( v5 == 47 )
        break;
      if ( v5 == 92 )
        break;
      v4 = &data[--len];
    }
    while ( len > 0 );
  }
  idStr::Mid(this, start: 0, len, result: dest);
}


// ========================================================================
// ?ExtractFileName@idStr@@QBAXAAV1@@Z
// EA  : 0x82F97700
// RVA : 0x00F97700
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::ExtractFileName(idStr *this, idStr *dest)
{
  int v2; // r11
  char *data; // r9
  char *v4; // r10
  int v5; // r10

  v2 = this->len - 1;
  if ( v2 > 0 )
  {
    data = this->data;
    v4 = &data[v2];
    do
    {
      v5 = *(v4 - 1);
      if ( v5 == 47 )
        break;
      if ( v5 == 92 )
        break;
      v4 = &data[--v2];
    }
    while ( v2 > 0 );
  }
  idStr::Right(this, len: this->len - v2, result: dest);
}


// ========================================================================
// ?ExtractFileExtension@idStr@@QBAXAAV1@@Z
// EA  : 0x82F97748
// RVA : 0x00F97748
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::ExtractFileExtension(idStr *this, idStr *dest)
{
  int v3; // r11
  char *data; // r9
  char *v5; // r10

  v3 = this->len - 1;
  if ( v3 > 0 )
  {
    data = this->data;
    v5 = &data[v3];
    do
    {
      if ( *(v5 - 1) == 46 )
        break;
      v5 = &data[--v3];
    }
    while ( v3 > 0 );
  }
  if ( v3 != 0 )
  {
    idStr::Right(this, len: this->len - v3, result: dest);
  }
  else
  {
    idStr::EnsureAlloced(this: dest, amount: 1, keepold: true, geometricGrowth: false);
    *dest->data = 0;
    dest->len = 0;
  }
}


// ========================================================================
// ?MakeNameCanonical@idStr@@QAAXXZ
// EA  : 0x82F977E8
// RVA : 0x00F977E8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall idStr::MakeNameCanonical(idStr *this)
{
  int i; // r11
  char *data; // r8
  int v4; // r10
  char *v6; // r10
  const char *v7; // r11
  int v8; // r8
  int v9; // r9
  int v10; // r10
  unsigned int v11; // r11
  bool v12; // r31
  idStr v13; // [sp+50h] [-40h] BYREF

  for ( i = 0; i < this->len; ++i )
  {
    data = this->data;
    v4 = data[i];
    if ( v4 <= 90 && v4 >= 65 )
    {
      this->data[i] += 32;
    }
    else if ( v4 == 92 )
    {
      data[i] = 47;
    }
  }
  v6 = idStr::Left(this: &v13, result: this, len: 2)->data;
  v7 = "//";
  if ( v6 != nullptr )
  {
    v8 = v6 - "//";
    while ( 1 )
    {
      v9 = v7[v8];
      v10 = v9 - *v7++;
      if ( v10 != 0 )
        break;
      if ( v9 == 0 )
      {
        v11 = 0;
        goto LABEL_18;
      }
    }
    v11 = (((unsigned int)~v10 >> 30) & 2) - 1;
  }
  else
  {
    v11 = 1;
  }
LABEL_18:
  v12 = v11 != 0;
  if ( v13.allocedAndFlag >= 0 && v13.data != nullptr && v13.data != v13.baseBuffer )
  {
    idMem::Free(this: &mem, ptr: (_DWORD *)v13.data, align: ALIGN_16);
    v13.data = v13.baseBuffer;
  }
  if ( v12 )
    idStr::StripLeading(this, c: 47);
}


// ========================================================================
// ?TestStrStatic_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F97978
// RVA : 0x00F97978
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void __fastcall TestStrStatic_f(const idCmdArgs *args)
{
  int len; // [sp+50h] [-100h]
  char v2; // [sp+5Ch] [-F4h]
  _DWORD v3[5]; // [sp+70h] [-E0h] BYREF
  char *v4; // [sp+84h] [-CCh]
  int v5; // [sp+88h] [-C8h]
  char v6; // [sp+8Ch] [-C4h] BYREF
  char v7; // [sp+A0h] [-B0h] BYREF
  idStrStatic<8> v8; // [sp+B0h] [-A0h] BYREF
  idStrStatic<8> v9; // [sp+E0h] [-70h] BYREF
  idStr v10; // [sp+110h] [-40h] BYREF

  v6 = 0;
  v7 = 0;
  v4 = &v7;
  v3[4] = 0;
  v5 = -2147483640;
  v2 = 0;
  HIBYTE(v3[0]) = 0;
  idStr::idStr(this: &v10, text: "This is a long dynamic str");
  idStrStatic<8>::idStrStatic<8>(this: &v8, text: "1234567");
  len = v8.len;
  memcpy(Dst: v3, Src: v8.data, Size: v8.len + 1);
  if ( v8.allocedAndFlag >= 0 && v8.data != nullptr && v8.data != v8.baseBuffer )
  {
    idMem::Free(this: &mem, ptr: (_DWORD *)v8.data, align: ALIGN_16);
    v8.data = v8.baseBuffer;
  }
  v3[4] = len;
  memcpy(Dst: v4, Src: v3, Size: len + 1);
  idStrStatic<8>::idStrStatic<8>(this: &v9, text: "123456789");
  v3[4] = v9.len;
  memcpy(Dst: v4, Src: v9.data, Size: v9.len + 1);
  if ( v9.allocedAndFlag >= 0 && v9.data != nullptr && v9.data != v9.baseBuffer )
  {
    idMem::Free(this: &mem, ptr: (_DWORD *)v9.data, align: ALIGN_16);
    v9.data = v9.baseBuffer;
  }
  if ( v10.allocedAndFlag >= 0 && v10.data != nullptr && v10.data != v10.baseBuffer )
  {
    idMem::Free(this: &mem, ptr: (_DWORD *)v10.data, align: ALIGN_16);
    v10.data = v10.baseBuffer;
  }
  if ( v5 >= 0 && v4 != nullptr && v4 != &v6 )
    idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
}


// ========================================================================
// __unwind$115298
// EA  : 0x82F97B88
// RVA : 0x00F97B88
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void _unwind_115298()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 128));
}


// ========================================================================
// __unwind$115299
// EA  : 0x82F97BB0
// RVA : 0x00F97BB0
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void _unwind_115299()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 80));
}


// ========================================================================
// __unwind$115300
// EA  : 0x82F97BD8
// RVA : 0x00F97BD8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void _unwind_115300()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 272));
}


// ========================================================================
// ?CheckExtension@idStr@@SA_NPBD0@Z
// EA  : 0x82F97C08
// RVA : 0x00F97C08
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

BOOL __fastcall idStr::CheckExtension(const char *name, const char *ext)
{
  idStr *v3; // r3
  BOOL v4; // r30
  idStr *v5; // r7
  idStr v7; // [sp+50h] [-60h] BYREF
  idStr v8[2]; // [sp+70h] [-40h] BYREF

  v3 = idStr::idStr(this: &v7, text: name);
  idStr::GetFileExtension(this: v8, result: v3);
  if ( v7.allocedAndFlag >= 0 && v7.data != nullptr && v7.data != v7.baseBuffer )
  {
    idMem::Free(this: &mem, ptr: (_DWORD *)v7.data, align: ALIGN_16);
    v7.data = v7.baseBuffer;
  }
  v4 = (_cntlzw(idStr::Icmp(s1: v8[0].data, s2: ext)) & 0x20) != 0;
  if ( v8[0].allocedAndFlag >= 0 && v5 != nullptr && v5 != (idStr *)v8[0].baseBuffer )
    idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
  return v4;
}


// ========================================================================
// __unwind$115643
// EA  : 0x82F97CD0
// RVA : 0x00F97CD0
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void _unwind_115643()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$115644
// EA  : 0x82F97CF8
// RVA : 0x00F97CF8
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

void _unwind_115644()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// `dynamic initializer for 'TestStrStatic_v''
// EA  : 0x83397458
// RVA : 0x01397458
// PDB : w:\tech5\shared\idlib\text\str.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestStrStatic_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestStrStatic_v,
           cmdName: "TestStrStatic",
           function: TestStrStatic_f,
           description: "Test idStrStatic",
           argCompletion: nullptr);
}

