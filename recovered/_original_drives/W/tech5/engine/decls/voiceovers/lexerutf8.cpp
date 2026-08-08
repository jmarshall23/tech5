
// ========================================================================
// ?LoadMemory@idLexerUTF8@@QAAXPBEIPBD@Z
// EA  : 0x8262E6A0
// RVA : 0x0062E6A0
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void __fastcall idLexerUTF8::LoadMemory(
        idLexerUTF8 *this,
        const unsigned __int8 *ptr,
        unsigned int length,
        const char *name)
{
  this->buffer = ptr;
  this->cur = ptr;
  this->end = &ptr[length];
  this->prev = nullptr;
  this->len = length;
  idStr::operator=(this: &this->filename, text: name);
  this->line = 0;
  this->lastline = 0;
  this->loaded = true;
  this->hadError = false;
  this->hadWarning = false;
}


// ========================================================================
// ?UnreadToken@idLexerUTF8@@QAAXXZ
// EA  : 0x8262E710
// RVA : 0x0062E710
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void __fastcall idLexerUTF8::UnreadToken(idLexerUTF8 *this)
{
  int lastline; // r10

  lastline = this->lastline;
  this->cur = this->prev;
  this->line = lastline;
}


// ========================================================================
// ?GetPunctuationFromId@idLexerUTF8@@QBAPBDH@Z
// EA  : 0x8262E728
// RVA : 0x0062E728
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

char *__fastcall idLexerUTF8::GetPunctuationFromId(idLexerUTF8 *this, const int id)
{
  const punctuation_t *punctuations; // r9
  int v3; // r10
  const punctuation_t *v4; // r11

  punctuations = this->punctuations;
  v3 = 0;
  if ( punctuations->p == nullptr )
    return "unknown punctuation";
  v4 = this->punctuations;
  while ( v4->n != id )
  {
    v4 = &punctuations[++v3];
    if ( v4->p == nullptr )
      return "unknown punctuation";
  }
  return v4->p;
}


// ========================================================================
// ?SkipWhitespace@idLexerUTF8@@AAA_NXZ
// EA  : 0x8262E778
// RVA : 0x0062E778
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

BOOL __fastcall idLexerUTF8::SkipWhitespace(idLexerUTF8 *this)
{
  const unsigned __int8 *cur; // r3
  unsigned int v3; // r3
  const unsigned __int8 *v4; // r10
  int v6; // [sp+50h] [-20h] BYREF

  if ( this->cur != nullptr )
  {
    do
    {
      cur = this->cur;
      if ( cur > this->end )
        break;
      v6 = 0;
      v3 = idStr::UTF8Char(s: cur, idx: &v6);
      if ( v3 > 0x20 )
        break;
      if ( v3 == 10 )
        ++this->line;
      v4 = &this->cur[v6];
      this->cur = v4;
    }
    while ( v4 != nullptr );
  }
  return this->end >= this->cur;
}


// ========================================================================
// ??1idLexerUTF8@@QAA@XZ
// EA  : 0x8262E828
// RVA : 0x0062E828
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void __fastcall idLexerUTF8::~idLexerUTF8(idLexerUTF8 *this)
{
  int *punctuationtable; // r4
  int *nextpunctuation; // r4

  punctuationtable = this->punctuationtable;
  if ( punctuationtable != nullptr )
  {
    idMem::Free(this: &mem, ptr: punctuationtable, align: ALIGN_16);
    this->punctuationtable = nullptr;
  }
  nextpunctuation = this->nextpunctuation;
  if ( nextpunctuation != nullptr )
  {
    idMem::Free(this: &mem, ptr: nextpunctuation, align: ALIGN_16);
    this->nextpunctuation = nullptr;
  }
  idStr::FreeData(this: &this->filename);
}


// ========================================================================
// __unwind$219929
// EA  : 0x8262E894
// RVA : 0x0062E894
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void _unwind_219929()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// ?ReadName@idLexerUTF8@@AAA_NAAVidToken@@@Z
// EA  : 0x8262E8C0
// RVA : 0x0062E8C0
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

int __fastcall idLexerUTF8::ReadName(idLexerUTF8 *this, idToken *token)
{
  unsigned int v4; // r3
  int flags; // r11
  const unsigned __int8 *v6; // r10
  int v8; // [sp+50h] [-30h] BYREF

  token->type = 4;
  if ( this->cur <= this->end )
  {
    do
    {
      v8 = 0;
      v4 = idStr::UTF8Char(s: this->cur, idx: &v8);
      if ( (v4 < 0x61 || v4 > 0x7A) && (v4 < 0x41 || v4 > 0x5A) && (v4 < 0x30 || v4 > 0x39) && v4 != 95 && v4 <= 0x7F )
      {
        flags = this->flags;
        if ( ((flags & 0x8000) == 0 || v4 != 45)
          && ((flags & 0x200) == 0 || v4 != 47 && v4 != 92 && v4 != 58 && v4 != 46 && v4 != 64)
          && ((flags & 0x100000) == 0 || v4 != 42) )
        {
          break;
        }
      }
      idStr::AppendUTF8Char(this: token, c: v4);
      v6 = &this->cur[v8];
      this->cur = v6;
    }
    while ( v6 <= this->end );
  }
  token->subtype = token->len;
  return 1;
}


// ========================================================================
// ?ReadPunctuation@idLexerUTF8@@AAA_NAAVidToken@@@Z
// EA  : 0x8262E9E0
// RVA : 0x0062E9E0
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

int __fastcall idLexerUTF8::ReadPunctuation(idLexerUTF8 *this, idToken *token)
{
  const unsigned __int8 *cur; // r8
  int v5; // r10
  int v6; // r31
  const punctuation_t *v7; // r28
  char *p; // r30
  unsigned int allocedAndFlag; // r11
  int v11; // r29
  int v12; // r11
  bool v13; // zf
  int v14; // r11
  int v15; // ctr

  cur = this->cur;
  v5 = *(int *)((char *)this->punctuationtable + __ROL4__(*cur, 2));
  if ( v5 < 0 )
    return 0;
  while ( 1 )
  {
    v6 = 0;
    v7 = &this->punctuations[v5];
    p = v7->p;
    if ( *v7->p != 0 )
    {
      do
      {
        if ( cur[v6] == 0 )
          break;
        if ( cur[v6] != p[v6] )
          break;
        ++v6;
      }
      while ( p[v6] != 0 );
    }
    if ( p[v6] == 0 )
      break;
    v5 = this->nextpunctuation[v5];
    if ( v5 < 0 )
      return 0;
  }
  allocedAndFlag = token->allocedAndFlag;
  v11 = v6 + 1;
  v13 = allocedAndFlag >> 31 == 0;
  v12 = allocedAndFlag & 0x7FFFFFFF;
  if ( v13 )
  {
    if ( v11 > v12 )
      idStr::ReAllocate(this: token, amount: v6 + 1, keepold: false);
  }
  else if ( v11 > v12
         && AssertFailed(
              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
              line: 463,
              expression: "amount <= GetAlloced()",
              inlineBreak: true) )
  {
    __trap();
  }
  v14 = 0;
  if ( v6 >= 0 )
  {
    v15 = v6 + 1;
    do
    {
      token->data[v14] = p[v14];
      ++v14;
      --v15;
    }
    while ( v15 != 0 );
  }
  token->len = v6;
  this->cur += v6;
  token->type = 5;
  token->subtype = v7->n;
  return 1;
}


// ========================================================================
// ?CreatePunctuationTable@idLexerUTF8@@AAAXPBUpunctuation_t@@@Z
// EA  : 0x8262EB40
// RVA : 0x0062EB40
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void __fastcall idLexerUTF8::CreatePunctuationTable(idLexerUTF8 *this, const punctuation_t *punctuations)
{
  int *punctuationtable; // r4
  int *nextpunctuation; // r4
  int v6; // r11
  const punctuation_t *v7; // r10
  size_t v8; // r28
  int v9; // r4
  const punctuation_t *v10; // r5
  int v11; // r3
  int v12; // r7
  int v13; // r11
  int v14; // r9
  int v15; // r6
  int v16; // r10
  char *p; // r11
  int v18; // r11
  int *v19; // r11
  bool v20; // zf

  punctuationtable = this->punctuationtable;
  if ( punctuationtable != nullptr )
    idMem::Free(this: &mem, ptr: punctuationtable, align: ALIGN_16);
  nextpunctuation = this->nextpunctuation;
  if ( nextpunctuation != nullptr )
    idMem::Free(this: &mem, ptr: nextpunctuation, align: ALIGN_16);
  this->punctuationtable = (int *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\engine\\decls\\VoiceOvers\\LexerUTF8.cpp(831) : TAG_LEXER",
                                    size: 0x400u,
                                    tag: TAG_LEXER,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  v6 = 0;
  if ( punctuations->p != nullptr )
  {
    v7 = punctuations;
    do
    {
      ++v7;
      ++v6;
    }
    while ( v7->p != nullptr );
  }
  v8 = 4 * v6;
  this->nextpunctuation = (int *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\engine\\decls\\VoiceOvers\\LexerUTF8.cpp(834) : TAG_LEXER",
                                   size: 4 * v6,
                                   tag: TAG_LEXER,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  memset(Dst: this->punctuationtable, Val: 255, Size: 0x400u);
  memset(Dst: this->nextpunctuation, Val: 255, Size: v8);
  v9 = 0;
  if ( punctuations->p != nullptr )
  {
    v10 = punctuations;
    v11 = 0;
    do
    {
      v12 = -1;
      v13 = *(unsigned __int8 *)v10->p;
      v14 = *(int *)((char *)this->punctuationtable + __ROL4__(v13, 2));
      if ( v14 < 0 )
      {
LABEL_22:
        this->nextpunctuation[v11] = -1;
        if ( v12 < 0 )
          goto LABEL_24;
        this->nextpunctuation[v12] = v9;
      }
      else
      {
        v15 = (char)v13;
        while ( 1 )
        {
          v16 = 0;
          p = punctuations[v14].p;
          if ( *p != 0 )
          {
            do
              ++v16;
            while ( p[v16] != 0 );
          }
          v18 = 0;
          if ( v15 != 0 )
          {
            do
              ++v18;
            while ( v10->p[v18] != 0 );
          }
          v20 = v16 < v18;
          v19 = this->nextpunctuation;
          if ( v20 )
            break;
          v12 = v14;
          v14 = v19[v14];
          if ( v14 < 0 )
            goto LABEL_22;
        }
        v19[v11] = v14;
        if ( v12 < 0 )
        {
LABEL_24:
          *(int *)((char *)this->punctuationtable + __ROL4__(*(unsigned __int8 *)v10->p, 2)) = v9;
          goto LABEL_25;
        }
        this->nextpunctuation[v12] = v9;
      }
LABEL_25:
      ++v9;
      ++v11;
      v10 = &punctuations[v9];
    }
    while ( v10->p != nullptr );
  }
}


// ========================================================================
// ?Error@idLexerUTF8@@QAAXPBDZZ
// EA  : 0x8262ED68
// RVA : 0x0062ED68
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idLexerUTF8::Error(
        idLexerUTF8 *this,
        const char *str,
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
  int v12; // r9
  __int64 v13; // r10 OVERLAPPED
  __int64 v14; // r8 OVERLAPPED
  int flags; // r11
  char *v16; // r11
  int i; // ctr
  __int64 v18; // r6
  va *v19; // r3
  int v20; // r10
  int v21; // r9
  int v22; // r8
  int v23; // r7
  int v24; // r6
  int v25; // r5
  int v26; // r4
  int v27; // r3
  int v28; // [sp+8h] [-1518h]
  int v29; // [sp+Ch] [-1514h]
  int v30; // [sp+10h] [-1510h]
  int v31; // [sp+14h] [-150Ch]
  int v32; // [sp+18h] [-1508h]
  int v33; // [sp+1Ch] [-1504h]
  bool v34[4]; // [sp+50h] [-14D0h] BYREF
  va_list v35; // [sp+54h] [-14CCh]
  idStr v36; // [sp+60h] [-14C0h] BYREF
  char v37[128]; // [sp+80h] [-14A0h] BYREF
  char v38[1024]; // [sp+100h] [-1420h] BYREF
  va v39; // [sp+500h] [-1020h] BYREF
  __int64 v41; // [sp+1540h] [+20h] BYREF
  va_list va; // [sp+1540h] [+20h]
  __int64 v43; // [sp+1548h] [+28h]
  __int64 v44; // [sp+1550h] [+30h]
  __int64 v45; // [sp+1558h] [+38h]
  __int64 v46; // [sp+1560h] [+40h]
  __int64 v47; // [sp+1568h] [+48h]
  va_list va1; // [sp+1570h] [+50h] BYREF

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
  v41 = *(__int64 *)((char *)&a3 + 4);
  v43 = a3;
  v44 = *(__int64 *)((char *)&a4 + 4);
  v45 = a4;
  v46 = *(__int64 *)((char *)&a5 + 4);
  v47 = a5;
  v12 = this->flags & 1;
  this->hadError = true;
  if ( v12 == 0 )
  {
    va_copy(v35, va);
    idStr::vsnPrintf(dest: v38, size: 1024, fmt: str, argptr: va);
    HIDWORD(v13) = this->flags;
    LODWORD(v14) = BYTE3(v13) & 8;
    if ( (v13 & 0x800000000LL) != 0 )
    {
      idStr::idStr(this: &v36, text: &this->filename);
      idStr::SlashesToBackSlashes(this: &v36);
      idLib::Printf(fmt: "%s(%d) : error : %s\n", v36.data, this->line, v38);
      idStr::FreeData(this: &v36);
    }
    flags = this->flags;
    if ( (flags & 4) != 0 )
    {
      if ( (flags & 8) == 0 )
      {
        v16 = &v36.baseBuffer[12];
        HIDWORD(v13) = 0;
        for ( i = 16; i != 0; --i )
        {
          v16 += 8;
          *(_QWORD *)v16 = *(__int64 *)((char *)&v13 + 4);
        }
        idStr::snPrintf(dest: v37, size: 127, fmt: "line %d", this->line);
        v34[0] = idLib::PushWarningInfo(type: this->filename.data, name: v37);
        idLib::Warning(fmt: "%s", v38);
        if ( v34[0] )
          idLib::PopWarningInfo();
      }
    }
    else
    {
      if ( (flags & 0x40000) != 0 )
      {
        HIDWORD(v14) = v38;
        HIDWORD(v18) = this->filename.data;
        LODWORD(v18) = this->line;
        LODWORD(v13) = this->flags & 4;
        v19 = va::va(
                this: &v39,
                fmt: "file %s, line %d: %s",
                a3: v18,
                a4: v14,
                a5: v13,
                a6: v28,
                a7: v29,
                a8: v30,
                a9: v31,
                a10: v32,
                a11: v33);
        strncpy(dest: idException::error, source: v19->buffer, count: 0x800u);
        CxxThrowException(pExceptionObject: v34, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidLexerException__);
      }
      idLib::Error(fmt: "file %s, line %d: %s", this->filename.data, this->line, v38);
      _LN48(
        a1: v27,
        a2: v26,
        a3: v25,
        a4: v24,
        a5: v23,
        a6: v22,
        a7: v21,
        a8: v20,
        a9: a6,
        a10: a7,
        a11: a8,
        a12: a9,
        a13: a10,
        a14: str,
        a15: HIDWORD(v41),
        a16: v41,
        a17: HIDWORD(v43),
        a18: v43);
    }
  }
}


// ========================================================================
// $LN48
// EA  : 0x8262EF20
// RVA : 0x0062EF20
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void _LN48()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5408 + 96));
}


// ========================================================================
// __unwind$220107
// EA  : 0x8262EF48
// RVA : 0x0062EF48
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void _unwind_220107()
{
  int v0; // r12

  idWarningInfo::~idWarningInfo(this: (idWarningInfo *)(v0 - 5408 + 80));
}


// ========================================================================
// ??0idLexerUTF8@@QAA@H@Z
// EA  : 0x8262EF78
// RVA : 0x0062EF78
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

idLexerUTF8 *__fastcall idLexerUTF8::idLexerUTF8(idLexerUTF8 *this, int flags_)
{
  this->filename.len = 0;
  this->filename.data = this->filename.baseBuffer;
  this->filename.allocedAndFlag = 20;
  this->filename.baseBuffer[0] = 0;
  this->flags = flags_;
  this->buffer = nullptr;
  this->cur = nullptr;
  this->end = nullptr;
  this->prev = nullptr;
  this->len = 0;
  this->lastline = 0;
  this->line = 0;
  this->punctuationtable = nullptr;
  this->nextpunctuation = nullptr;
  this->loaded = false;
  this->hadError = false;
  this->hadWarning = false;
  idLexerUTF8::CreatePunctuationTable(this, punctuations: idLexer::defaultPunctuations);
  this->punctuations = idLexer::defaultPunctuations;
  return this;
}


// ========================================================================
// __unwind$220238
// EA  : 0x8262F000
// RVA : 0x0062F000
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void _unwind_220238()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ?ReadNumber@idLexerUTF8@@AAA_NAAVidToken@@@Z
// EA  : 0x8262F028
// RVA : 0x0062F028
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

int __fastcall idLexerUTF8::ReadNumber(idLexerUTF8 *this, idToken *token)
{
  int v4; // r21
  char v5; // r20
  char v6; // r29
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  unsigned int v10; // r3
  unsigned int v11; // r28
  const unsigned __int8 *v12; // r9
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  unsigned int v16; // r3
  int v17; // r11
  int v18; // r10
  const unsigned __int8 *v19; // r9
  char v20; // r11
  char *v21; // r4
  const unsigned __int8 *v22; // r9
  int v23; // r11
  int v24; // r10
  char v25; // r11
  int v26; // r11
  int v27; // r10
  char v28; // r11
  int v29; // r11
  int v30; // r10
  char v31; // r11
  int v32; // r11
  int v33; // r10
  char v34; // r11
  int v35; // r11
  int v37; // [sp+8h] [-C8h]
  int v38; // [sp+Ch] [-C4h]
  int v39; // [sp+10h] [-C0h]
  int v40; // [sp+14h] [-BCh]
  int v41; // [sp+18h] [-B8h]
  int v42; // [sp+1Ch] [-B4h]
  int v43[28]; // [sp+60h] [-70h] BYREF

  token->type = 3;
  token->subtype = 0;
  token->floatvalue = 0.0;
  token->intvalue = 0;
  v4 = 0;
  v5 = 0;
  do
  {
    v43[0] = 0;
    v6 = 0;
    v10 = idStr::UTF8Char(s: this->cur, idx: v43);
    v11 = v10;
    if ( v10 >= 0x30 && v10 <= 0x39 )
    {
      idStr::AppendUTF8Char(this: token, c: v10);
      this->cur += v43[0];
      continue;
    }
    if ( v10 <= 0x20 )
      break;
    if ( v10 != 46 )
    {
      if ( v4 <= 0 )
        continue;
      if ( v10 == 101 )
      {
        if ( v5 != 0 )
        {
          idLexerUTF8::Error(
            this,
            str: "invalid number",
            a3: v9,
            a4: v8,
            a5: v7,
            a6: v37,
            a7: v38,
            a8: v39,
            a9: v40,
            a10: v41,
            a11: v42);
          return 0;
        }
        v5 = 1;
        token->subtype |= 0x80u;
        idStr::AppendUTF8Char(this: token, c: 0x65u);
        v12 = &this->cur[v43[0]];
        v43[0] = 0;
        this->cur = v12;
        v16 = idStr::UTF8Char(s: v12, idx: v43);
        v11 = v16;
        if ( v16 != 45 && v16 != 43 )
        {
          idLexerUTF8::Error(
            this,
            str: "e must be followed by + or -",
            a3: v15,
            a4: v14,
            a5: v13,
            a6: v37,
            a7: v38,
            a8: v39,
            a9: v40,
            a10: v41,
            a11: v42);
          return 0;
        }
        idStr::AppendUTF8Char(this: token, c: v16);
        this->cur += v43[0];
        goto LABEL_52;
      }
      if ( v10 != 35 )
        continue;
      token->subtype |= 0x80u;
      idStr::AppendUTF8Char(this: token, c: 0x23u);
      v17 = 0;
      v18 = 73;
      v19 = &this->cur[v43[0]];
      this->cur = v19;
      while ( v19[v17] == v18 )
      {
        v18 = aInf[++v17];
        if ( aInf[v17] == 0 )
        {
          v20 = 1;
          goto LABEL_20;
        }
      }
      v20 = 0;
LABEL_20:
      if ( v20 != 0 )
      {
        v21 = "INF";
        token->subtype |= 0x800u;
        v22 = this->cur + 3;
      }
      else
      {
        v23 = 0;
        v24 = 73;
        while ( v19[v23] == v24 )
        {
          v24 = aInd[++v23];
          if ( aInd[v23] == 0 )
          {
            v25 = 1;
            goto LABEL_27;
          }
        }
        v25 = 0;
LABEL_27:
        if ( v25 != 0 )
        {
          v21 = "IND";
          token->subtype |= 0x1000u;
          v22 = this->cur + 3;
        }
        else
        {
          v26 = 0;
          v27 = 78;
          while ( v19[v26] == v27 )
          {
            v27 = aNan[++v26];
            if ( aNan[v26] == 0 )
            {
              v28 = 1;
              goto LABEL_34;
            }
          }
          v28 = 0;
LABEL_34:
          if ( v28 != 0 )
          {
            v21 = "NAN";
            token->subtype |= 0x2000u;
            v22 = this->cur + 3;
          }
          else
          {
            v29 = 0;
            v30 = 81;
            while ( v19[v29] == v30 )
            {
              v30 = aQnan[++v29];
              if ( aQnan[v29] == 0 )
              {
                v31 = 1;
                goto LABEL_41;
              }
            }
            v31 = 0;
LABEL_41:
            if ( v31 != 0 )
            {
              v21 = "QNAN";
            }
            else
            {
              v32 = 0;
              v33 = 83;
              while ( v19[v32] == v33 )
              {
                v33 = aSnan[++v32];
                if ( aSnan[v32] == 0 )
                {
                  v34 = 1;
                  goto LABEL_48;
                }
              }
              v34 = 0;
LABEL_48:
              if ( v34 == 0 )
                goto LABEL_52;
              v21 = "SNAN";
            }
            token->subtype |= 0x2000u;
            v22 = this->cur + 4;
          }
        }
      }
      this->cur = v22;
      idStr::Append(this: token, text: v21);
LABEL_52:
      v6 = 1;
      continue;
    }
    if ( v4 > 0 )
    {
      idLexerUTF8::Error(
        this,
        str: "more than one dot in number",
        a3: v9,
        a4: v8,
        a5: v7,
        a6: v37,
        a7: v38,
        a8: v39,
        a9: v40,
        a10: v41,
        a11: v42);
      return 0;
    }
    ++v4;
    token->subtype |= 0x80u;
    idStr::AppendUTF8Char(this: token, c: 0x2Eu);
    this->cur += v43[0];
  }
  while ( this->cur <= this->end && v11 >= 0x30 && v11 <= 0x39 || v11 == 46 || v6 != 0 );
  v35 = token->subtype | 2;
  token->subtype = v35;
  if ( v4 == 0 && v5 == 0 )
    token->subtype = v35 | 1;
  return 1;
}


// ========================================================================
// ?ReadEscapeCharacter@idLexerUTF8@@AAA_NAAI@Z
// EA  : 0x8262F458
// RVA : 0x0062F458
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

int __fastcall idLexerUTF8::ReadEscapeCharacter(idLexerUTF8 *this, unsigned int *c, __int64 a3, __int64 a4)
{
  const unsigned __int8 *cur; // r11
  const unsigned __int8 *v7; // r3
  __int64 v8; // r10
  unsigned int v9; // r3
  int v10; // r10
  unsigned int v11; // r11
  int v12; // r10
  const unsigned __int8 *v13; // r9
  unsigned int v14; // r11
  unsigned __int8 v15; // r11
  unsigned int i; // r11
  const unsigned __int8 *v17; // r6
  int v19; // [sp+8h] [-78h]
  int v20; // [sp+Ch] [-74h]
  int v21; // [sp+10h] [-70h]
  int v22; // [sp+14h] [-6Ch]
  int v23; // [sp+18h] [-68h]
  int v24; // [sp+1Ch] [-64h]
  int v25; // [sp+60h] [-20h] BYREF

  cur = this->cur;
  LODWORD(v8) = this->flags;
  HIDWORD(v8) = v8 & 0x10000;
  this->cur = cur + 1;
  v7 = cur + 1;
  if ( (v8 & 0x10000) != 0 )
  {
    v25 = 0;
    v9 = idStr::UTF8Char(s: v7, idx: &v25);
    v10 = v25;
    *c = v9;
    this->cur += v10;
  }
  else
  {
    v11 = *v7;
    if ( v11 > 0x66 )
    {
      LODWORD(v8) = v11 - 110;
      switch ( *v7 )
      {
        case 'n':
          *c = 10;
          ++this->cur;
          return 1;
        case 'r':
          *c = 13;
          ++this->cur;
          return 1;
        case 't':
          *c = 9;
          ++this->cur;
          return 1;
        case 'v':
          *c = 11;
          ++this->cur;
          return 1;
        case 'x':
          v12 = 0;
          this->cur = v7 + 1;
          break;
        default:
          goto LABEL_35;
      }
      while ( 1 )
      {
        v13 = this->cur;
        v14 = *v13;
        if ( v14 < 0x30 || v14 > 0x39 )
        {
          if ( v14 < 0x41 || v14 > 0x5A )
          {
            if ( v14 < 0x61 || v14 > 0x7A )
              goto LABEL_41;
            v15 = v14 - 87;
          }
          else
          {
            v15 = v14 - 55;
          }
        }
        else
        {
          v15 = v14 - 48;
        }
        v12 = 16 * v12 + v15;
        this->cur = v13 + 1;
      }
    }
    if ( v11 == 102 )
    {
      *c = 12;
      ++this->cur;
      return 1;
    }
    if ( v11 > 0x5C )
    {
      if ( v11 == 97 )
      {
        *c = 7;
        ++this->cur;
        return 1;
      }
      if ( v11 == 98 )
      {
        *c = 8;
        ++this->cur;
        return 1;
      }
    }
    else
    {
      switch ( v11 )
      {
        case '\\':
          *c = 92;
          ++this->cur;
          return 1;
        case '"':
          *c = 34;
          ++this->cur;
          return 1;
        case '\'':
          *c = 39;
          ++this->cur;
          return 1;
        case '?':
          *c = 63;
          ++this->cur;
          return 1;
        default:
          break;
      }
    }
LABEL_35:
    if ( v11 < 0x30 || v11 > 0x39 )
      idLexerUTF8::Error(
        this,
        str: "unknown escape char",
        a3,
        a4,
        a5: v8,
        a6: v19,
        a7: v20,
        a8: v21,
        a9: v22,
        a10: v23,
        a11: v24);
    v12 = 0;
    for ( i = *this->cur; i >= 0x30; i = *v17 )
    {
      if ( i > 0x39 )
        break;
      v17 = this->cur + 1;
      this->cur = v17;
      v12 = (unsigned __int8)(i - 48) + 10 * v12;
    }
LABEL_41:
    *c = v12;
  }
  return 1;
}


// ========================================================================
// ?ReadString@idLexerUTF8@@AAA_NAAVidToken@@I@Z
// EA  : 0x8262F758
// RVA : 0x0062F758
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

int __fastcall idLexerUTF8::ReadString(idLexerUTF8 *this, idToken *token, const unsigned int quote)
{
  int v6; // r11
  const unsigned __int8 *end; // r10
  const unsigned __int8 *v8; // r11
  __int64 v9; // r8
  __int64 v10; // r6
  unsigned int v11; // r3
  unsigned int v12; // r4
  int flags; // r11
  char *data; // r9
  int v15; // r11
  int v17; // [sp+50h] [-40h] BYREF
  unsigned int v18; // [sp+54h] [-3Ch] BYREF

  v6 = 1;
  if ( quote != 34 )
    v6 = 2;
  token->type = v6;
  end = this->end;
  v8 = this->cur + 1;
  this->cur = v8;
  if ( v8 <= end )
  {
    do
    {
      v17 = 0;
      v11 = idStr::UTF8Char(s: this->cur, idx: &v17);
      v12 = v11;
      v18 = v11;
      if ( v11 == 0 || v17 == 0 )
        break;
      if ( v11 != 92 || ((flags = this->flags) & 0x20) != 0 )
      {
        this->cur += v17;
        if ( v11 == quote )
          return 1;
      }
      else
      {
        if ( (flags & 0x10000) != 0 )
        {
          idStr::EnsureAlloced(this: token, amount: token->len + 2, keepold: true, geometricGrowth: true);
          token->data[token->len] = 92;
          data = token->data;
          v15 = token->len + 1;
          token->len = v15;
          data[v15] = 0;
        }
        if ( (unsigned __int8)idLexerUTF8::ReadEscapeCharacter(this, c: &v18, a3: v10, a4: v9) == 0 )
          return 0;
        v12 = v18;
      }
      idStr::AppendUTF8Char(this: token, c: v12);
    }
    while ( this->cur <= this->end );
  }
  return 1;
}


// ========================================================================
// ?ReadToken@idLexerUTF8@@QAA_NAAVidToken@@@Z
// EA  : 0x8262F890
// RVA : 0x0062F890
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

BOOL __fastcall idLexerUTF8::ReadToken(idLexerUTF8 *this, idToken *token)
{
  int line; // r11
  unsigned int v5; // r3
  const unsigned __int8 *cur; // r11
  const unsigned __int8 *end; // r7
  unsigned int v8; // r28
  unsigned int v9; // r3
  int flags; // r11
  BOOL result; // r3
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  bool v15; // zf
  int v16; // [sp+8h] [-98h]
  int v17; // [sp+Ch] [-94h]
  int v18; // [sp+10h] [-90h]
  int v19; // [sp+14h] [-8Ch]
  int v20; // [sp+18h] [-88h]
  int v21; // [sp+1Ch] [-84h]
  int v22; // [sp+70h] [-30h] BYREF
  int v23; // [sp+74h] [-2Ch] BYREF

  idStr::EnsureAlloced(this: token, amount: 1, keepold: true, geometricGrowth: false);
  *token->data = 0;
  token->len = 0;
  token->type = 0;
  token->subtype = 0;
  token->flags = 0;
  this->prev = this->cur;
  if ( idLexerUTF8::SkipWhitespace(this) )
  {
    line = this->line;
    v22 = 0;
    token->line = line;
    token->linesCrossed = this->line - this->lastline;
    v5 = idStr::UTF8Char(s: this->cur, idx: &v22);
    cur = this->cur;
    end = this->end;
    v8 = v5;
    v23 = 0;
    v9 = 0;
    if ( cur + 1 <= end )
      v9 = idStr::UTF8Char(s: &cur[v22], idx: &v23);
    flags = this->flags;
    if ( (flags & 0x8000) != 0 )
    {
      if ( v8 != 34 && v8 != 39 )
        return (unsigned __int8)idLexerUTF8::ReadName(this, token) != 0;
    }
    else
    {
      if ( v8 >= 0x30 && v8 <= 0x39 || v9 != 0 && v8 == 46 && v9 >= 0x30 && v9 <= 0x39 )
        return (unsigned __int8)idLexerUTF8::ReadNumber(this, token) != 0;
      if ( (flags & 0x80000) != 0 || v8 != 34 && v8 != 39 )
      {
        if ( v8 >= 0x61 && v8 <= 0x7A || v8 >= 0x41 && v8 <= 0x5A || v8 == 95 || v8 > 0x7F )
        {
          v15 = (unsigned __int8)idLexerUTF8::ReadName(this, token) == 0;
          result = false;
          if ( v15 )
            return result;
          return true;
        }
        if ( (flags & 0x200) == 0 || v8 != 46 )
        {
          if ( ((flags & 0x20000) == 0 || v9 == 0 || v8 != 60 || v9 != 37)
            && (unsigned __int8)idLexerUTF8::ReadPunctuation(this, token) == 0 )
          {
            HIDWORD(v14) = v8;
            idLexerUTF8::Error(
              this,
              str: "unknown punctuation %c",
              a3: v14,
              a4: v13,
              a5: v12,
              a6: v16,
              a7: v17,
              a8: v18,
              a9: v19,
              a10: v20,
              a11: v21);
            return true;
          }
          return true;
        }
        return (unsigned __int8)idLexerUTF8::ReadName(this, token) != 0;
      }
    }
    if ( (unsigned __int8)idLexerUTF8::ReadString(this, token, quote: v8) != 0 )
      return true;
  }
  return false;
}


// ========================================================================
// ?CheckTokenType@idLexerUTF8@@QAA_NHHAAVidToken@@@Z
// EA  : 0x8262FAF8
// RVA : 0x0062FAF8
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

int __fastcall idLexerUTF8::CheckTokenType(idLexerUTF8 *this, const int type, const int subType, idToken *token)
{
  int lastline; // r10
  int v10; // r10
  idToken v11; // [sp+50h] [-80h] BYREF

  v11.len = 0;
  v11.allocedAndFlag = 20;
  v11.floatvalue = -3.4028235e38;
  v11.data = v11.baseBuffer;
  v11.baseBuffer[0] = 0;
  v11.intvalue = 0;
  memset(&v11.whiteSpaceStart_p, 0, 12);
  if ( !idLexerUTF8::ReadToken(this, token: &v11) )
  {
    idStr::FreeData(this: &v11);
    return 0;
  }
  if ( type != v11.type )
    goto LABEL_4;
  if ( v11.type != 3 )
  {
    if ( v11.type == 5 && v11.subtype != subType )
    {
LABEL_4:
      lastline = this->lastline;
      this->cur = this->prev;
      this->line = lastline;
      idStr::FreeData(this: &v11);
      return 0;
    }
  }
  else if ( (v11.subtype & subType) != subType )
  {
    v10 = this->lastline;
    this->cur = this->prev;
    this->line = v10;
_M220503:
    idStr::FreeData(this: &v11);
    return 1;
  }
  idToken::operator=(this: token, __that: &v11);
  goto _M220503;
}


// ========================================================================
// __unwind$220410
// EA  : 0x8262FC24
// RVA : 0x0062FC24
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void _unwind_220410()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?ExpectTokenType@idLexerUTF8@@QAA_NHHAAVidToken@@@Z
// EA  : 0x8262FC58
// RVA : 0x0062FC58
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

int __fastcall idLexerUTF8::ExpectTokenType(idLexerUTF8 *this, const int type, int subType, idToken *token)
{
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v12; // r10
  int v13; // r11
  const char *v14; // r4
  __int64 v15; // r6
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  __int64 v22; // r10
  __int64 v23; // r8
  int v24; // [sp+8h] [-B8h]
  int v25; // [sp+Ch] [-B4h]
  int v26; // [sp+10h] [-B0h]
  int v27; // [sp+14h] [-ACh]
  int v28; // [sp+18h] [-A8h]
  int v29; // [sp+1Ch] [-A4h]
  idStr v30[2]; // [sp+70h] [-50h] BYREF

  if ( !idLexerUTF8::ReadToken(this, token) )
  {
    idLexerUTF8::Error(
      this,
      str: "couldn't read expected token",
      a3: v10,
      a4: v9,
      a5: v8,
      a6: v24,
      a7: v25,
      a8: v26,
      a9: v27,
      a10: v28,
      a11: v29);
    return 0;
  }
  LODWORD(v12) = 20;
  HIDWORD(v12) = v30[0].baseBuffer;
  v30[0].len = 0;
  v30[0].allocedAndFlag = 20;
  v30[0].data = v30[0].baseBuffer;
  v30[0].baseBuffer[0] = 0;
  v13 = token->type;
  if ( v13 != type )
  {
    if ( (unsigned int)(type - 1) > 4 )
    {
      v14 = "unknown type";
    }
    else
    {
      switch ( type )
      {
        case 2:
          v14 = "literal";
          break;
        case 3:
          v14 = "number";
          break;
        case 4:
          v14 = "name";
          break;
        case 1:
          v14 = "string";
          break;
        default:
          v14 = "punctuation";
          break;
      }
    }
    idStr::operator=(this: v30, text: v14);
    LODWORD(v15) = token->data;
    HIDWORD(v15) = v30[0].data;
    idLexerUTF8::Error(
      this,
      str: "expected a %s but found '%s'",
      a3: v15,
      a4: v17,
      a5: v16,
      a6: v24,
      a7: v25,
      a8: v26,
      a9: v27,
      a10: v28,
      a11: v29);
    idStr::FreeData(this: v30);
    return 0;
  }
  if ( v13 != 3 )
  {
    if ( v13 == 5 )
    {
      if ( subType < 0 )
      {
        idLexerUTF8::Error(
          this,
          str: "BUG: wrong punctuation subtype",
          a3: v10,
          a4: v9,
          a5: v12,
          a6: v24,
          a7: v25,
          a8: v26,
          a9: v27,
          a10: v28,
          a11: v29);
        idStr::FreeData(this: v30);
        return 0;
      }
      if ( token->subtype != subType )
      {
        HIDWORD(v21) = idLexerUTF8::GetPunctuationFromId(this, id: subType);
        idLexerUTF8::Error(
          this,
          str: "expected '%s' but found '%s'",
          a3: v21,
          a4: v23,
          a5: v22,
          a6: v24,
          a7: v25,
          a8: v26,
          a9: v27,
          a10: v28,
          a11: v29);
        idStr::FreeData(this: v30);
        return 0;
      }
    }
  }
  else if ( (token->subtype & subType) != subType )
  {
    idStr::Clear(this: v30);
    if ( (subType & 2) != 0 )
      idStr::operator=(this: v30, text: "decimal ");
    if ( (subType & 4) != 0 )
      idStr::operator=(this: v30, text: "hex ");
    if ( (subType & 8) != 0 )
      idStr::operator=(this: v30, text: "octal ");
    if ( (subType & 0x10) != 0 )
      idStr::operator=(this: v30, text: "binary ");
    if ( (subType & 0x40) != 0 )
      idStr::Append(this: v30, text: "unsigned ");
    if ( (subType & 0x20) != 0 )
      idStr::Append(this: v30, text: "long ");
    if ( (subType & 0x80) != 0 )
      idStr::Append(this: v30, text: "float ");
    if ( (subType & 1) != 0 )
      idStr::Append(this: v30, text: "integer ");
    idStr::StripTrailing(this: v30, c: 32);
    HIDWORD(v18) = v30[0].data;
    LODWORD(v18) = token->data;
    idLexerUTF8::Error(
      this,
      str: "expected %s but found '%s'",
      a3: v18,
      a4: v20,
      a5: v19,
      a6: v24,
      a7: v25,
      a8: v26,
      a9: v27,
      a10: v28,
      a11: v29);
    idStr::FreeData(this: v30);
    return 0;
  }
  idStr::FreeData(this: v30);
  return 1;
}


// ========================================================================
// __unwind$220523
// EA  : 0x8262FF20
// RVA : 0x0062FF20
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void _unwind_220523()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// ?ExpectTokenString@idLexerUTF8@@QAA_NPBD@Z
// EA  : 0x8262FF50
// RVA : 0x0062FF50
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

int __fastcall idLexerUTF8::ExpectTokenString(idLexerUTF8 *this, const char *string)
{
  __int64 v4; // r10
  unsigned int v5; // r8
  __int64 v6; // r6
  __int64 v8; // r10
  __int64 v9; // r8
  int v10; // [sp+8h] [-D8h]
  int v11; // [sp+Ch] [-D4h]
  int v12; // [sp+10h] [-D0h]
  int v13; // [sp+14h] [-CCh]
  int v14; // [sp+18h] [-C8h]
  int v15; // [sp+1Ch] [-C4h]
  idToken v16; // [sp+70h] [-70h] BYREF

  v16.len = 0;
  v16.allocedAndFlag = 20;
  v16.floatvalue = -3.4028235e38;
  v16.data = v16.baseBuffer;
  v16.baseBuffer[0] = 0;
  v16.intvalue = 0;
  memset(&v16.whiteSpaceStart_p, 0, 12);
  if ( idLexerUTF8::ReadToken(this, token: &v16) )
  {
    if ( idStr::Cmp(s1: v16.data, s2: string) != 0 )
    {
      idLexerUTF8::Error(
        this,
        str: "expected '%s' but found '%s'",
        a3: __SPAIR64__((unsigned int)string, (unsigned int)v16.data),
        a4: v9,
        a5: v8,
        a6: v10,
        a7: v11,
        a8: v12,
        a9: v13,
        a10: v14,
        a11: v15);
      idStr::FreeData(this: &v16);
      return 0;
    }
    else
    {
      idStr::FreeData(this: &v16);
      return 1;
    }
  }
  else
  {
    HIDWORD(v6) = string;
    idLexerUTF8::Error(
      this,
      str: "couldn't find expected '%s'",
      a3: v6,
      a4: v5,
      a5: v4,
      a6: v10,
      a7: v11,
      a8: v12,
      a9: v13,
      a10: v14,
      a11: v15);
    idStr::FreeData(this: &v16);
    return 0;
  }
}


// ========================================================================
// __unwind$220623
// EA  : 0x82630028
// RVA : 0x00630028
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void _unwind_220623()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?CheckTokenString@idLexerUTF8@@QAA_NPBD@Z
// EA  : 0x82630058
// RVA : 0x00630058
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

int __fastcall idLexerUTF8::CheckTokenString(idLexerUTF8 *this, const char *string)
{
  int lastline; // r10
  idToken v6; // [sp+50h] [-70h] BYREF

  v6.len = 0;
  v6.allocedAndFlag = 20;
  v6.floatvalue = -3.4028235e38;
  v6.data = v6.baseBuffer;
  v6.baseBuffer[0] = 0;
  v6.intvalue = 0;
  memset(&v6.whiteSpaceStart_p, 0, 12);
  if ( idLexerUTF8::ReadToken(this, token: &v6) )
  {
    if ( idStr::Cmp(s1: v6.data, s2: string) == 0 )
    {
      idStr::FreeData(this: &v6);
      return 1;
    }
    lastline = this->lastline;
    this->cur = this->prev;
    this->line = lastline;
  }
  idStr::FreeData(this: &v6);
  return 0;
}


// ========================================================================
// __unwind$220718
// EA  : 0x8263010C
// RVA : 0x0063010C
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void _unwind_220718()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?SkipBracedSection@idLexerUTF8@@QAA_N_N@Z
// EA  : 0x82630140
// RVA : 0x00630140
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

int __fastcall idLexerUTF8::SkipBracedSection(idLexerUTF8 *this, bool parseFirstBrace)
{
  int v3; // r30
  idToken v5; // [sp+50h] [-80h] BYREF

  v5.len = 0;
  v5.allocedAndFlag = 20;
  v5.data = v5.baseBuffer;
  v5.floatvalue = -3.4028235e38;
  v5.baseBuffer[0] = 0;
  v5.intvalue = 0;
  memset(&v5.whiteSpaceStart_p, 0, 12);
  v3 = (_cntlzw(parseFirstBrace) & 0x20) != 0;
  while ( idLexerUTF8::ReadToken(this, token: &v5) )
  {
    if ( v5.type == 5 )
    {
      if ( idStr::Cmp(s1: v5.data, s2: "{") != 0 )
      {
        if ( idStr::Cmp(s1: v5.data, s2: "}") == 0 )
          --v3;
      }
      else
      {
        ++v3;
      }
    }
    if ( v3 == 0 )
    {
      idStr::FreeData(this: &v5);
      return 1;
    }
  }
  idStr::FreeData(this: &v5);
  return 0;
}


// ========================================================================
// __unwind$220884
// EA  : 0x8263022C
// RVA : 0x0063022C
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void _unwind_220884()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?ParseFloat@idLexerUTF8@@QAAMXZ
// EA  : 0x82630260
// RVA : 0x00630260
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

float __fastcall idLexerUTF8::ParseFloat(idLexerUTF8 *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  double v5; // fp1
  double FloatValue; // fp31
  int v8; // [sp+8h] [-D8h]
  int v9; // [sp+Ch] [-D4h]
  int v10; // [sp+10h] [-D0h]
  int v11; // [sp+14h] [-CCh]
  int v12; // [sp+18h] [-C8h]
  int v13; // [sp+1Ch] [-C4h]
  idToken v14; // [sp+70h] [-70h] BYREF

  v14.len = 0;
  v14.allocedAndFlag = 20;
  v14.data = v14.baseBuffer;
  v14.floatvalue = -3.4028235e38;
  v14.baseBuffer[0] = 0;
  v14.intvalue = 0;
  memset(&v14.whiteSpaceStart_p, 0, 12);
  HIDWORD(v3) = idLexerUTF8::ReadToken(this, token: &v14);
  if ( HIDWORD(v3) != 0 )
  {
    if ( v14.type == 5 )
    {
      if ( v14.subtype == 31 )
      {
        idLexerUTF8::ExpectTokenType(this, type: 3, subType: 0, token: &v14);
        FloatValue = -idToken::GetFloatValue(this: &v14);
LABEL_9:
        idStr::FreeData(this: &v14);
        v5 = FloatValue;
        return *((float *)&v5 + 1);
      }
    }
    else if ( v14.type == 3 )
    {
LABEL_8:
      FloatValue = idToken::GetFloatValue(this: &v14);
      goto LABEL_9;
    }
    HIDWORD(v4) = v14.data;
    idLexerUTF8::Error(
      this,
      str: "expected float value, found '%s'",
      a3: v4,
      a4: v3,
      a5: v2,
      a6: v8,
      a7: v9,
      a8: v10,
      a9: v11,
      a10: v12,
      a11: v13);
    goto LABEL_8;
  }
  idLexerUTF8::Error(
    this,
    str: "couldn't read expected floating point number",
    a3: v4,
    a4: (unsigned int)v3,
    a5: v2,
    a6: v8,
    a7: v9,
    a8: v10,
    a9: v11,
    a10: v12,
    a11: v13);
  idStr::FreeData(this: &v14);
  v5 = 0.0;
  return *((float *)&v5 + 1);
}


// ========================================================================
// __unwind$220966
// EA  : 0x8263037C
// RVA : 0x0063037C
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void _unwind_220966()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?ParseInt@idLexerUTF8@@QAAHXZ
// EA  : 0x826303B0
// RVA : 0x006303B0
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

unsigned int __fastcall idLexerUTF8::ParseInt(idLexerUTF8 *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  unsigned int UnsignedIntValue; // r30
  int v7; // [sp+8h] [-C8h]
  int v8; // [sp+Ch] [-C4h]
  int v9; // [sp+10h] [-C0h]
  int v10; // [sp+14h] [-BCh]
  int v11; // [sp+18h] [-B8h]
  int v12; // [sp+1Ch] [-B4h]
  idToken v13; // [sp+70h] [-60h] BYREF

  v13.len = 0;
  v13.allocedAndFlag = 20;
  v13.data = v13.baseBuffer;
  v13.floatvalue = -3.4028235e38;
  v13.baseBuffer[0] = 0;
  v13.intvalue = 0;
  memset(&v13.whiteSpaceStart_p, 0, 12);
  HIDWORD(v3) = idLexerUTF8::ReadToken(this, token: &v13);
  if ( HIDWORD(v3) == 0 )
  {
    idLexerUTF8::Error(
      this,
      str: "couldn't read expected integer",
      a3: v4,
      a4: (unsigned int)v3,
      a5: v2,
      a6: v7,
      a7: v8,
      a8: v9,
      a9: v10,
      a10: v11,
      a11: v12);
    idStr::FreeData(this: &v13);
    return 0;
  }
  if ( v13.type != 5 )
  {
    if ( v13.type == 3 && v13.subtype != 128 )
      goto LABEL_9;
  }
  else if ( v13.subtype == 31 )
  {
    idLexerUTF8::ExpectTokenType(this, type: 3, subType: 1, token: &v13);
    UnsignedIntValue = -idToken::GetUnsignedIntValue(this: &v13);
LABEL_10:
    idStr::FreeData(this: &v13);
    return UnsignedIntValue;
  }
  HIDWORD(v4) = v13.data;
  idLexerUTF8::Error(
    this,
    str: "expected integer value, found '%s'",
    a3: v4,
    a4: v3,
    a5: v2,
    a6: v7,
    a7: v8,
    a8: v9,
    a9: v10,
    a10: v11,
    a11: v12);
LABEL_9:
  UnsignedIntValue = idToken::GetUnsignedIntValue(this: &v13);
  goto LABEL_10;
}


// ========================================================================
// __unwind$221056
// EA  : 0x826304CC
// RVA : 0x006304CC
// PDB : w:\tech5\engine\decls\voiceovers\lexerutf8.cpp
// ========================================================================

void _unwind_221056()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}

