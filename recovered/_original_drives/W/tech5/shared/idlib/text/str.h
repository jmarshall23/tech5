
// ========================================================================
// ?EnsureAlloced@idStr@@QAAXH_N0@Z
// EA  : 0x824E0110
// RVA : 0x004E0110
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::EnsureAlloced(idStr *this, int amount, bool keepold, bool geometricGrowth)
{
  unsigned int allocedAndFlag; // r11
  int v5; // r11
  bool v6; // zf

  allocedAndFlag = this->allocedAndFlag;
  v6 = allocedAndFlag >> 31 == 0;
  v5 = allocedAndFlag & 0x7FFFFFFF;
  if ( v6 )
  {
    if ( amount > v5 )
    {
      if ( geometricGrowth )
        amount += amount >> 1;
      idStr::ReAllocate(this, amount, keepold);
    }
  }
  else if ( amount > v5
         && AssertFailed(
              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
              line: 463,
              expression: "amount <= GetAlloced()",
              inlineBreak: true) )
  {
    __trap();
  }
}


// ========================================================================
// ??0idZippedFile@@QAA@XZ
// EA  : 0x824E01A8
// RVA : 0x004E01A8
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idZippedFile::idZippedFile(idStr *this)
{
  this->len = 0;
  this->data = this->baseBuffer;
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// ?Append@idStr@@QAAXABV1@@Z
// EA  : 0x824E01C8
// RVA : 0x004E01C8
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::Append(idStr *this, const idStr *text)
{
  int v3; // r29
  int i; // r11
  char *data; // r11

  v3 = text->len + this->len;
  idStr::EnsureAlloced(this, amount: v3 + 1, keepold: true, geometricGrowth: true);
  for ( i = 0; i < text->len; ++i )
    this->data[this->len + i] = text->data[i];
  data = this->data;
  this->len = v3;
  data[v3] = 0;
}


// ========================================================================
// ?Length@idStr@@SAHPBD@Z
// EA  : 0x824E0248
// RVA : 0x004E0248
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

int __fastcall idStr::Length(const char *s)
{
  int v1; // r10
  int result; // r3

  v1 = *(unsigned __int8 *)s;
  result = 0;
  if ( v1 != 0 )
  {
    do
      ++result;
    while ( s[result] != 0 );
  }
  return result;
}


// ========================================================================
// ??0idStr@@QAA@ABV0@@Z
// EA  : 0x824E0330
// RVA : 0x004E0330
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::idStr(idStr *this, const idStr *text)
{
  int len; // r30
  char *v5; // r11
  char *v6; // r10
  char v7; // r9

  this->len = 0;
  this->data = this->baseBuffer;
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  len = text->len;
  idStr::EnsureAlloced(this, amount: text->len + 1, keepold: true, geometricGrowth: false);
  v5 = text->data - 1;
  v6 = this->data - 1;
  do
  {
    v7 = *++v5;
    *++v6 = *v5;
  }
  while ( v7 != 0 );
  this->len = len;
  return this;
}


// ========================================================================
// ??0idStr@@QAA@PBD@Z
// EA  : 0x824E03A8
// RVA : 0x004E03A8
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::idStr(idStr *this, const char *text)
{
  int v2; // r29
  const char *v5; // r10
  char *v6; // r9
  char v7; // r11

  v2 = 0;
  this->len = 0;
  this->allocedAndFlag = 20;
  this->data = this->baseBuffer;
  this->baseBuffer[0] = 0;
  if ( text != nullptr )
  {
    if ( *text != 0 )
    {
      do
        ++v2;
      while ( text[v2] != 0 );
    }
    idStr::EnsureAlloced(this, amount: v2 + 1, keepold: true, geometricGrowth: false);
    v5 = text - 1;
    v6 = this->data - 1;
    do
    {
      v7 = *++v5;
      *++v6 = *v5;
    }
    while ( v7 != 0 );
    this->len = v2;
  }
  return this;
}


// ========================================================================
// ??4idStr@@QAAXABV0@@Z
// EA  : 0x824E0440
// RVA : 0x004E0440
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::operator=(idStr *this, const idStr *text)
{
  int len; // r31

  len = text->len;
  idStr::EnsureAlloced(this, amount: text->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->data, Src: text->data, Size: len);
  this->data[len] = 0;
  this->len = len;
}


// ========================================================================
// ?Append@idStr@@QAAXPBD@Z
// EA  : 0x824E0490
// RVA : 0x004E0490
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::Append(idStr *this, char *text)
{
  int v4; // r11
  int v5; // r29
  char v6; // r10
  int i; // r11
  char *data; // r11

  if ( text != nullptr )
  {
    v4 = 0;
    if ( *text != 0 )
    {
      do
        ++v4;
      while ( text[v4] != 0 );
    }
    v5 = this->len + v4;
    idStr::EnsureAlloced(this, amount: v5 + 1, keepold: true, geometricGrowth: true);
    v6 = *text;
    for ( i = 0; v6 != 0; v6 = text[i] )
      this->data[this->len + i++] = v6;
    data = this->data;
    this->len = v5;
    data[v5] = 0;
  }
}


// ========================================================================
// ??0va@@QAA@PBDZZ
// EA  : 0x824E2E90
// RVA : 0x004E2E90
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
va *va::va(
        va *this,
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
  __int64 v13; // [sp+90h] [+20h] BYREF
  va_list va; // [sp+90h] [+20h]
  __int64 v15; // [sp+98h] [+28h]
  __int64 v16; // [sp+A0h] [+30h]
  __int64 v17; // [sp+A8h] [+38h]
  __int64 v18; // [sp+B0h] [+40h]
  __int64 v19; // [sp+B8h] [+48h]
  va_list va1; // [sp+C0h] [+50h] BYREF

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
  v13 = *(__int64 *)((char *)&a3 + 4);
  v15 = a3;
  v16 = *(__int64 *)((char *)&a4 + 4);
  v17 = a4;
  v18 = *(__int64 *)((char *)&a5 + 4);
  v19 = a5;
  idStr::vsnPrintf(dest: this->buffer, size: 4096, fmt, argptr: va);
  return this;
}


// ========================================================================
// ??4idStr@@QAAXABVva@@@Z
// EA  : 0x824FA040
// RVA : 0x004FA040
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::operator=(idStr *this, const va *text)
{
  size_t i; // r31

  for ( i = 0; text->buffer[i] != 0; ++i )
    ;
  idStr::EnsureAlloced(this, amount: i + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->data, Src: text, Size: i);
  this->data[i] = 0;
  this->len = i;
}


// ========================================================================
// ??0idStr@@QAA@H@Z
// EA  : 0x82560F20
// RVA : 0x00560F20
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::idStr(idStr *this, int i)
{
  int v3; // r30
  char *v4; // r11
  char *v5; // r10
  char v6; // r9
  char v8; // [sp+4Fh] [-61h] BYREF
  char v9[72]; // [sp+50h] [-60h] BYREF

  this->len = 0;
  this->data = this->baseBuffer;
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  v3 = sprintf_0(string: v9, format: "%d", i);
  idStr::EnsureAlloced(this, amount: v3 + 1, keepold: true, geometricGrowth: false);
  v4 = &v8;
  v5 = this->data - 1;
  do
  {
    v6 = *++v4;
    *++v5 = *v4;
  }
  while ( v6 != 0 );
  this->len = v3;
  return this;
}


// ========================================================================
// ?Append@idStr@@QAAXD@Z
// EA  : 0x825AEA30
// RVA : 0x005AEA30
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::Append(idStr *this, char a)
{
  char *data; // r7
  int v5; // r11

  idStr::EnsureAlloced(this, amount: this->len + 2, keepold: true, geometricGrowth: true);
  this->data[this->len] = a;
  data = this->data;
  v5 = this->len + 1;
  this->len = v5;
  data[v5] = 0;
}


// ========================================================================
// ??YidStr@@QAAAAV0@D@Z
// EA  : 0x825AEB48
// RVA : 0x005AEB48
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::operator+=(idStr *this, char a)
{
  char *data; // r7
  int v6; // r11

  idStr::EnsureAlloced(this, amount: this->len + 2, keepold: true, geometricGrowth: true);
  this->data[this->len] = a;
  data = this->data;
  v6 = this->len + 1;
  this->len = v6;
  data[v6] = 0;
  return this;
}


// ========================================================================
// ?Empty@idStr@@QAAXXZ
// EA  : 0x825AFF68
// RVA : 0x005AFF68
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::Empty(idStr *this)
{
  idStr::EnsureAlloced(this, amount: 1, keepold: true, geometricGrowth: false);
  *this->data = 0;
  this->len = 0;
}


// ========================================================================
// ?Insert@idStr@@QAAXDH@Z
// EA  : 0x825AFFB0
// RVA : 0x005AFFB0
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::Insert(idStr *this, char a, int index)
{
  int len; // r30
  int v6; // r11
  int v7; // ctr
  char *v8; // r10

  len = index;
  if ( index >= 0 )
  {
    if ( index > this->len )
      len = this->len;
  }
  else
  {
    len = 0;
  }
  idStr::EnsureAlloced(this, amount: this->len + 2, keepold: true, geometricGrowth: false);
  v6 = this->len;
  if ( this->len >= len )
  {
    v7 = v6 - len + 1;
    do
    {
      v8 = &this->data[v6--];
      v8[1] = *v8;
      --v7;
    }
    while ( v7 != 0 );
  }
  this->data[len] = a;
  ++this->len;
}


// ========================================================================
// ?Fill@idStr@@QAAXDH@Z
// EA  : 0x825B0050
// RVA : 0x005B0050
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::Fill(idStr *this, const char ch, size_t newlen)
{
  char *data; // r3

  idStr::EnsureAlloced(this, amount: newlen + 1, keepold: true, geometricGrowth: false);
  data = this->data;
  this->len = newlen;
  memset(Dst: data, Val: ch, Size: newlen);
  this->data[this->len] = 0;
}


// ========================================================================
// ?Left@idStr@@QBA?AV1@H@Z
// EA  : 0x825B00A8
// RVA : 0x005B00A8
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::Left(idStr *this, idStr *result, int len)
{
  idStr::Mid(this, result, start: 0, len);
  return this;
}


// ========================================================================
// ?Right@idStr@@QBA?AV1@H@Z
// EA  : 0x825B13A0
// RVA : 0x005B13A0
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::Right(idStr *this, idStr *result, int len)
{
  if ( len < result->len )
    idStr::Mid(this, result, start: result->len - len, len);
  else
    idStr::idStr(this, text: result);
  return this;
}


// ========================================================================
// ??0idStr@@QAA@ABVva@@@Z
// EA  : 0x825C7268
// RVA : 0x005C7268
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::idStr(idStr *this, const va *text)
{
  int v2; // r29
  char *v5; // r10
  char *v6; // r9
  char v7; // r11

  v2 = 0;
  this->len = 0;
  this->allocedAndFlag = 20;
  this->data = this->baseBuffer;
  for ( this->baseBuffer[0] = 0; text->buffer[v2] != 0; ++v2 )
    ;
  idStr::EnsureAlloced(this, amount: v2 + 1, keepold: true, geometricGrowth: false);
  v5 = &text[-1].buffer[4095];
  v6 = this->data - 1;
  do
  {
    v7 = *++v5;
    *++v6 = *v5;
  }
  while ( v7 != 0 );
  this->len = v2;
  return this;
}


// ========================================================================
// ?Append@idStr@@QAAXABVva@@@Z
// EA  : 0x825C72F8
// RVA : 0x005C72F8
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::Append(idStr *this, const va *text)
{
  int i; // r30
  int v5; // r28
  int v6; // r11
  int j; // ctr
  char *data; // r11

  for ( i = 0; text->buffer[i] != 0; ++i )
    ;
  v5 = this->len + i;
  idStr::EnsureAlloced(this, amount: v5 + 1, keepold: true, geometricGrowth: true);
  v6 = 0;
  if ( i > 0 )
  {
    for ( j = i; j != 0; --j )
    {
      this->data[this->len + v6] = text->buffer[v6];
      ++v6;
    }
  }
  data = this->data;
  this->len = v5;
  data[v5] = 0;
}


// ========================================================================
// ??H@YA?AVidStr@@PBDABV0@@Z
// EA  : 0x825D5578
// RVA : 0x005D5578
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall operator+(idStr *result, const char *a, const idStr *b)
{
  idStr::idStr(this: result, text: a);
  idStr::Append(this: result, text: b);
  return result;
}


// ========================================================================
// __unwind$228176
// EA  : 0x825D55C0
// RVA : 0x005D55C0
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void _unwind_228176()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 128;
  if ( (*(_DWORD *)(v0 - 128 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 148));
  }
}


// ========================================================================
// ?ToLower@idStr@@QAAXXZ
// EA  : 0x825F6EA8
// RVA : 0x005F6EA8
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::ToLower(idStr *this)
{
  char *data; // r10
  int v2; // r11
  int v3; // r10

  data = this->data;
  v2 = 0;
  if ( *data != 0 )
  {
    do
    {
      v3 = data[v2];
      if ( v3 <= 90 && v3 >= 65 )
        this->data[v2] += 32;
      data = this->data;
      ++v2;
    }
    while ( data[v2] != 0 );
  }
}


// ========================================================================
// ?GetFilePath@idStr@@QBA?AV1@XZ
// EA  : 0x825F7610
// RVA : 0x005F7610
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::GetFilePath(idStr *this, idStr *result)
{
  this->data = this->baseBuffer;
  this->allocedAndFlag = 20;
  this->len = 0;
  this->baseBuffer[0] = 0;
  idStr::ExtractFilePath(this: result, dest: this);
  return this;
}


// ========================================================================
// __unwind$221602
// EA  : 0x825F7680
// RVA : 0x005F7680
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void _unwind_221602()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 112;
  if ( (*(_DWORD *)(v0 - 112 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 132));
  }
}


// ========================================================================
// ?GetWithoutExtension@idStr@@QBA?AV1@XZ
// EA  : 0x825F76D0
// RVA : 0x005F76D0
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::GetWithoutExtension(idStr *this, idStr *result)
{
  idStr::idStr(this, text: result->data);
  idStr::StripFileExtension(this);
  return this;
}


// ========================================================================
// __unwind$221642
// EA  : 0x825F772C
// RVA : 0x005F772C
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void _unwind_221642()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 112;
  if ( (*(_DWORD *)(v0 - 112 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 132));
  }
}


// ========================================================================
// ?CopyRange@idStr@@QAAXPBDHH@Z
// EA  : 0x82618908
// RVA : 0x00618908
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::CopyRange(idStr *this, const char *text, int start, int end)
{
  signed int v6; // r31
  int v8; // r11
  signed int i; // ctr

  v6 = (((unsigned int)(end - start) >> 31) - 1) & (end - start);
  idStr::EnsureAlloced(this, amount: v6 + 1, keepold: true, geometricGrowth: false);
  v8 = 0;
  if ( v6 > 0 )
  {
    for ( i = v6; i != 0; --i )
    {
      this->data[v8] = text[start + v8];
      ++v8;
    }
  }
  this->data[v6] = 0;
  this->len = v6;
}


// ========================================================================
// ?Clear@idStr@@QAAXXZ
// EA  : 0x82618980
// RVA : 0x00618980
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::Clear(idStr *this)
{
  char *data; // r10

  if ( this->allocedAndFlag >= 0 )
  {
    idStr::FreeData(this);
    this->len = 0;
    this->allocedAndFlag = 20;
    this->data = this->baseBuffer;
    this->baseBuffer[0] = 0;
  }
  else
  {
    data = this->data;
    this->len = 0;
    *data = 0;
  }
}


// ========================================================================
// ??YidStr@@QAAAAV0@H@Z
// EA  : 0x82631468
// RVA : 0x00631468
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::operator+=(idStr *this, int a)
{
  char v4[64]; // [sp+50h] [-50h] BYREF

  sprintf_0(string: v4, format: "%d", a);
  idStr::Append(this, text: v4);
  return this;
}


// ========================================================================
// ??4idStr@@QAAXD@Z
// EA  : 0x82636588
// RVA : 0x00636588
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::operator=(idStr *this, char c)
{
  idStr::EnsureAlloced(this, amount: 2, keepold: true, geometricGrowth: false);
  *this->data = c;
  this->data[1] = 0;
  this->len = (-c & (unsigned int)~c) >> 31;
}


// ========================================================================
// ?GetFileName@idStr@@QBA?AV1@XZ
// EA  : 0x826439F0
// RVA : 0x006439F0
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::GetFileName(idStr *this, idStr *result)
{
  this->data = this->baseBuffer;
  this->allocedAndFlag = 20;
  this->len = 0;
  this->baseBuffer[0] = 0;
  idStr::ExtractFileName(this: result, dest: this);
  return this;
}


// ========================================================================
// __unwind$236690
// EA  : 0x82643A60
// RVA : 0x00643A60
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void _unwind_236690()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 112;
  if ( (*(_DWORD *)(v0 - 112 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 132));
  }
}


// ========================================================================
// ?IHash@idStr@@SAHPBD@Z
// EA  : 0x8265C2D8
// RVA : 0x0065C2D8
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

int __fastcall idStr::IHash(const char *string)
{
  int v1; // r11
  const char *v2; // r8
  int result; // r3
  char v4; // r10

  v1 = *(unsigned __int8 *)string;
  v2 = string;
  result = 0;
  if ( v1 != 0 )
  {
    do
    {
      if ( (char)v1 > 90 || (char)v1 < 65 )
        v4 = v1;
      else
        v4 = v1 + 32;
      LOBYTE(v1) = *++v2;
      result = 31 * result + v4;
    }
    while ( *v2 != 0 );
  }
  return result;
}


// ========================================================================
// ??H@YA?AVidStr@@ABV0@0@Z
// EA  : 0x8265E0B0
// RVA : 0x0065E0B0
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall operator+(idStr *result, const idStr *a, const idStr *b)
{
  idStr::idStr(this: result, text: a);
  idStr::Append(this: result, text: b);
  return result;
}


// ========================================================================
// __unwind$232945
// EA  : 0x8265E0F8
// RVA : 0x0065E0F8
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void _unwind_232945()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 128;
  if ( (*(_DWORD *)(v0 - 128 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 148));
  }
}


// ========================================================================
// ??H@YA?AVidStr@@ABV0@PBD@Z
// EA  : 0x8265F120
// RVA : 0x0065F120
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall operator+(idStr *result, const idStr *a, char *b)
{
  idStr::idStr(this: result, text: a);
  idStr::Append(this: result, text: b);
  return result;
}


// ========================================================================
// __unwind$234568
// EA  : 0x8265F168
// RVA : 0x0065F168
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void _unwind_234568()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 128;
  if ( (*(_DWORD *)(v0 - 128 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 148));
  }
}


// ========================================================================
// ?RemoveColors@idStr@@QAAAAV1@XZ
// EA  : 0x82666F78
// RVA : 0x00666F78
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::RemoveColors(idStr *this)
{
  char *data; // r10
  int v3; // r11

  idStr::RemoveColors(string: this->data);
  data = this->data;
  v3 = 0;
  if ( *data != 0 )
  {
    do
      ++v3;
    while ( data[v3] != 0 );
  }
  this->len = v3;
  return this;
}


// ========================================================================
// ?GetFileExtension@idStr@@QBA?AV1@XZ
// EA  : 0x8267FC40
// RVA : 0x0067FC40
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::GetFileExtension(idStr *this, idStr *result)
{
  this->data = this->baseBuffer;
  this->allocedAndFlag = 20;
  this->len = 0;
  this->baseBuffer[0] = 0;
  idStr::ExtractFileExtension(this: result, dest: this);
  return this;
}


// ========================================================================
// __unwind$239996
// EA  : 0x8267FCB0
// RVA : 0x0067FCB0
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void _unwind_239996()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 112;
  if ( (*(_DWORD *)(v0 - 112 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 132));
  }
}


// ========================================================================
// ?ToUpper@idStr@@QAAXXZ
// EA  : 0x82776B58
// RVA : 0x00776B58
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::ToUpper(idStr *this)
{
  char *data; // r10
  int v2; // r11
  int v3; // r10

  data = this->data;
  v2 = 0;
  if ( *data != 0 )
  {
    do
    {
      v3 = data[v2];
      if ( v3 >= 97 && v3 <= 122 )
        this->data[v2] -= 32;
      data = this->data;
      ++v2;
    }
    while ( data[v2] != 0 );
  }
}


// ========================================================================
// ?PadLength@idStr@@QAAXH@Z
// EA  : 0x827DE000
// RVA : 0x007DE000
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::PadLength(idStr *this, int newlen)
{
  int v4; // r29
  int len; // r11
  int v6; // ctr

  if ( this->len - 1 < newlen && newlen >= 0 )
  {
    v4 = newlen + 1;
    idStr::EnsureAlloced(this, amount: newlen + 1, keepold: true, geometricGrowth: false);
    len = this->len;
    if ( this->len < newlen )
    {
      v6 = newlen - len;
      do
      {
        this->data[len++] = 32;
        --v6;
      }
      while ( v6 != 0 );
    }
    this->data[len] = 0;
    this->len = v4;
  }
}


// ========================================================================
// ?Insert@idStr@@QAAXPBDH@Z
// EA  : 0x828024F8
// RVA : 0x008024F8
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::Insert(idStr *this, const char *text, int index)
{
  int len; // r29
  int v6; // r30
  int v7; // r11
  int v8; // ctr
  char *v9; // r10
  int v10; // r11
  int i; // ctr

  len = index;
  if ( index >= 0 )
  {
    if ( index > this->len )
      len = this->len;
  }
  else
  {
    len = 0;
  }
  v6 = 0;
  if ( *text != 0 )
  {
    do
      ++v6;
    while ( text[v6] != 0 );
  }
  idStr::EnsureAlloced(this, amount: this->len + v6 + 1, keepold: true, geometricGrowth: false);
  v7 = this->len;
  if ( this->len >= len )
  {
    v8 = v7 - len + 1;
    do
    {
      v9 = &this->data[v7--];
      v9[v6] = *v9;
      --v8;
    }
    while ( v8 != 0 );
  }
  v10 = 0;
  if ( v6 > 0 )
  {
    for ( i = v6; i != 0; --i )
    {
      this->data[v10 + len] = text[v10];
      ++v10;
    }
  }
  this->len += v6;
}


// ========================================================================
// ?Append@idStr@@QAAXPBDH@Z
// EA  : 0x8280D938
// RVA : 0x0080D938
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::Append(idStr *this, const char *text, int l)
{
  int v6; // r29
  int v7; // r11
  char *data; // r11

  if ( text != nullptr && l != 0 )
  {
    v6 = this->len + l;
    idStr::EnsureAlloced(this, amount: v6 + 1, keepold: true, geometricGrowth: true);
    v7 = 0;
    if ( *text != 0 )
    {
      do
      {
        if ( v7 >= l )
          break;
        this->data[this->len + v7] = text[v7];
        ++v7;
      }
      while ( text[v7] != 0 );
    }
    data = this->data;
    this->len = v6;
    data[v6] = 0;
  }
}


// ========================================================================
// ?ToWordCase@idStr@@QAAXXZ
// EA  : 0x82824270
// RVA : 0x00824270
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

void __fastcall idStr::ToWordCase(idStr *this)
{
  char *data; // r11
  int v2; // r8
  char *v3; // r9
  char v4; // r10
  char v5; // r9

  data = this->data;
  v2 = 0;
  if ( *data != 0 )
  {
    do
    {
      if ( v2 != 0 && (v3 = &data[v2], data[v2 - 1] > 32) )
      {
        v4 = *v3;
        if ( *v3 <= 90 && v4 >= 65 )
          v4 += 32;
        *v3 = v4;
      }
      else
      {
        v5 = data[v2];
        if ( v5 >= 97 && v5 <= 122 )
          v5 -= 32;
        data[v2] = v5;
      }
      data = this->data;
      ++v2;
    }
    while ( data[v2] != 0 );
  }
}


// ========================================================================
// ?Cmpn@idStr@@QBAHPBDH@Z
// EA  : 0x82874FC0
// RVA : 0x00874FC0
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

int __fastcall idStr::Cmpn(idStr *this, const char *text, int n)
{
  return idStr::Cmpn(s1: this->data, s2: text, n);
}


// ========================================================================
// ??0idStr@@QAA@M@Z
// EA  : 0x82B04DB8
// RVA : 0x00B04DB8
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::idStr(idStr *this, double f)
{
  int v3; // r31
  char *v4; // r10
  char *v5; // r9
  char v6; // r11
  char v8; // [sp+4Fh] [-61h] BYREF
  char v9[96]; // [sp+50h] [-60h] BYREF

  this->data = this->baseBuffer;
  this->len = 0;
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  v3 = idStr::snPrintf(dest: v9, size: 64, fmt: "%f", f);
  if ( v3 > 0 )
  {
    while ( v9[v3 - 1] == 48 )
    {
      v9[--v3] = 0;
      if ( v3 <= 0 )
        goto LABEL_7;
    }
    do
    {
      if ( v9[v3 - 1] != 46 )
        break;
      v9[--v3] = 0;
    }
    while ( v3 > 0 );
  }
LABEL_7:
  idStr::EnsureAlloced(this, amount: v3 + 1, keepold: true, geometricGrowth: false);
  v4 = &v8;
  v5 = this->data - 1;
  do
  {
    v6 = *++v4;
    *++v5 = *v4;
  }
  while ( v6 != 0 );
  this->len = v3;
  return this;
}


// ========================================================================
// ?Right@idStr@@QBAPBDHAAV1@@Z
// EA  : 0x82CACE88
// RVA : 0x00CACE88
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

char *__fastcall idStr::Right(idStr *this, int len, idStr *result)
{
  int v3; // r31
  char *data; // r3

  v3 = this->len;
  if ( len < this->len )
    return (char *)idStr::Mid(this, start: v3 - len, len, result);
  idStr::EnsureAlloced(this: result, amount: v3 + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: result->data, Src: this->data, Size: v3);
  result->data[v3] = 0;
  data = result->data;
  result->len = v3;
  return data;
}


// ========================================================================
// ?FormatCash@idStr@@SA?AV1@H@Z
// EA  : 0x82DBF010
// RVA : 0x00DBF010
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::FormatCash(idStr *result, int num)
{
  idStr::FormatInt(result, num, isCash: true);
  return result;
}


// ========================================================================
// ??0idStr@@QAA@_N@Z
// EA  : 0x82EFE558
// RVA : 0x00EFE558
// PDB : w:\tech5\shared\idlib\text\str.h
// ========================================================================

idStr *__fastcall idStr::idStr(idStr *this, const bool b)
{
  this->data = this->baseBuffer;
  this->len = 0;
  this->allocedAndFlag = 20;
  this->baseBuffer[0] = 0;
  idStr::EnsureAlloced(this, amount: 2, keepold: true, geometricGrowth: false);
  *this->data = ((_cntlzw(b) & 0x20) == 0) + 48;
  this->data[1] = 0;
  this->len = 1;
  return this;
}

