
// ========================================================================
// ?GetPunctuationFromId@idLexer@@QBAPBDH@Z
// EA  : 0x82F87C80
// RVA : 0x00F87C80
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

char *__fastcall idLexer::GetPunctuationFromId(idLexer *this, int id)
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
// ?GetPunctuationId@idLexer@@QBAHPBD@Z
// EA  : 0x82F87CD0
// RVA : 0x00F87CD0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::GetPunctuationId(idLexer *this, const char *p)
{
  const punctuation_t *punctuations; // r11
  int v5; // r30
  int v6; // r31
  int v7; // r3

  punctuations = this->punctuations;
  v5 = 0;
  if ( punctuations->p == nullptr )
    return 0;
  v6 = 0;
  while ( 1 )
  {
    v7 = idStr::Cmp(s1: punctuations[v6].p, s2: p);
    punctuations = this->punctuations;
    if ( v7 == 0 )
      break;
    v6 = ++v5;
    if ( punctuations[v5].p == nullptr )
      return 0;
  }
  return punctuations[v6].n;
}


// ========================================================================
// ?CheckString@idLexer@@ABA_NPBD@Z
// EA  : 0x82F87D48
// RVA : 0x00F87D48
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::CheckString(idLexer *this, const char *str)
{
  int v2; // r11
  int v3; // r10

  v2 = 0;
  v3 = *str;
  if ( *str == 0 )
    return 1;
  while ( this->script_p[v2] == v3 )
  {
    v3 = str[++v2];
    if ( str[v2] == 0 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?UnreadToken@idLexer@@QAAXXZ
// EA  : 0x82F87D98
// RVA : 0x00F87D98
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void __fastcall idLexer::UnreadToken(idLexer *this)
{
  int lastline; // r10

  lastline = this->lastline;
  this->script_p = this->lastScript_p;
  this->line = lastline;
}


// ========================================================================
// ?Reset@idLexer@@QAAXXZ
// EA  : 0x82F87DB0
// RVA : 0x00F87DB0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void __fastcall idLexer::Reset(idLexer *this)
{
  const char *buffer; // r9

  buffer = this->buffer;
  this->whiteSpaceStart_p = nullptr;
  this->whiteSpaceEnd_p = nullptr;
  this->line = 1;
  this->script_p = buffer;
  this->lastScript_p = buffer;
  this->lastline = 1;
}


// ========================================================================
// ?EndOfFile@idLexer@@QBA_NXZ
// EA  : 0x82F87DD8
// RVA : 0x00F87DD8
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

BOOL __fastcall idLexer::EndOfFile(idLexer *this)
{
  return this->script_p >= this->end_p;
}


// ========================================================================
// ?LoadFile@idLexer@@QAA_NPBD_N@Z
// EA  : 0x82F87DF0
// RVA : 0x00F87DF0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idFile *__fastcall idLexer::LoadFile(idLexer *this, const char *filename_, __int64 OSPath, __int64 a4, __int64 a5)
{
  _BYTE *v5; // r3
  _BYTE *v6; // r31
  char v7; // r29
  const char *v8; // r3
  idFile *result; // r3
  idFile *v10; // r30
  int v11; // r3
  _BYTE *v12; // r28
  idFile_vtbl *v13; // r11
  const char *v14; // r3
  int v15; // r10
  int v16; // r11
  int v17; // [sp+8h] [-78h]
  int v18; // [sp+Ch] [-74h]
  int v19; // [sp+10h] [-70h]
  int v20; // [sp+14h] [-6Ch]

  v6 = v5;
  v7 = BYTE3(OSPath);
  if ( *v5 != 0 )
  {
    v8 = "LoadFile: another script already loaded";
    idLib::Error(fmt: *(__int64 *)&filename_, a2: OSPath, a3: a4, a4: a5, a5: v17, a6: v18, a7: v19, a8: v20);
  }
  result = fileSystem->OpenFileRead(this: fileSystem, a2: filename_, a3: 1, a4: 0);
  v10 = result;
  if ( result != nullptr )
  {
    v11 = result->Length(this: result);
    *((_DWORD *)v6 + 17) = v11;
    v12 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\shared\\idlib\\text\\Lexer.cpp(1777) : TAG_LEXER",
            size: v11 + 1,
            tag: TAG_LEXER,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    v10->Read(this: v10, a2: v12, a3: *((_DWORD *)v6 + 17));
    v12[*((_DWORD *)v6 + 17)] = 0;
    *((_DWORD *)v6 + 10) = v12;
    *((_DWORD *)v6 + 16) = v10->Timestamp(this: v10);
    v13 = v10->__vftable;
    if ( v7 != 0 )
      v14 = v13->GetFullPath(this: v10);
    else
      v14 = v13->GetName(this: v10);
    idStr::operator=(this: (idStr *)(v6 + 4), text: v14);
    idStr::CollapsePath(this: (idStr *)(v6 + 4));
    v15 = *((_DWORD *)v6 + 17);
    *((_DWORD *)v6 + 18) = 1;
    *((_DWORD *)v6 + 19) = 1;
    *((_DWORD *)v6 + 9) = 1;
    *v6 = 1;
    v16 = *((_DWORD *)v6 + 10);
    *((_DWORD *)v6 + 12) = v16 + v15;
    *((_DWORD *)v6 + 11) = v16;
    *((_DWORD *)v6 + 13) = v16;
    ((void (__fastcall *)(idFile *, int))v10->dtr_idFile)(a1: v10, a2: 1);
    return (idFile *)1;
  }
  return result;
}


// ========================================================================
// ?LoadMemory@idLexer@@QAA_NPBDI0@Z
// EA  : 0x82F87F70
// RVA : 0x00F87F70
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idLexer::LoadMemory(idLexer *this, const char *ptr, __int64 name, __int64 a4, __int64 a5)
{
  _BYTE *v5; // r3
  _BYTE *v6; // r31
  int v8; // r28
  const char *v9; // r3
  int v11; // [sp+8h] [-78h]
  int v12; // [sp+Ch] [-74h]
  int v13; // [sp+10h] [-70h]
  int v14; // [sp+14h] [-6Ch]

  v6 = v5;
  v8 = HIDWORD(name);
  if ( *v5 != 0 )
  {
    v9 = "LoadMemory: another script already loaded";
    idLib::Error(fmt: *(__int64 *)&ptr, a2: name, a3: a4, a4: a5, a5: v11, a6: v12, a7: v13, a8: v14);
  }
  idStr::operator=(this: (idStr *)(v6 + 4), text: (const char *)name);
  idStr::CollapsePath(this: (idStr *)(v6 + 4));
  *((_DWORD *)v6 + 10) = ptr;
  *((_DWORD *)v6 + 17) = v8;
  *((_DWORD *)v6 + 16) = 0;
  *((_DWORD *)v6 + 11) = ptr;
  *((_DWORD *)v6 + 13) = ptr;
  *((_DWORD *)v6 + 12) = &ptr[v8];
  *((_DWORD *)v6 + 18) = 1;
  *((_DWORD *)v6 + 19) = 1;
  *((_DWORD *)v6 + 9) = 0;
  *v6 = 1;
  return 1;
}


// ========================================================================
// ?HadError@idLexer@@QBA_NXZ
// EA  : 0x82F87FF8
// RVA : 0x00F87FF8
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

BOOL __fastcall idLexer::HadError(idLexer *this)
{
  return this->hadError;
}


// ========================================================================
// ?HadWarning@idLexer@@QBA_NXZ
// EA  : 0x82F88000
// RVA : 0x00F88000
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

BOOL __fastcall idLexer::HadWarning(idLexer *this)
{
  return this->hadWarning;
}


// ========================================================================
// ?SetScriptP@idLexer@@QAA_NPBD@Z
// EA  : 0x82F88008
// RVA : 0x00F88008
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::SetScriptP(idLexer *this, const char *p)
{
  const char *buffer; // r11
  const char *end_p; // r10

  buffer = this->buffer;
  if ( buffer == nullptr )
    return 0;
  end_p = this->end_p;
  if ( end_p == nullptr || p < buffer || p > end_p )
    return 0;
  this->script_p = p;
  return 1;
}


// ========================================================================
// ?CreatePunctuationTable@idLexer@@AAAXPBUpunctuation_t@@@Z
// EA  : 0x82F880A8
// RVA : 0x00F880A8
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void __fastcall idLexer::CreatePunctuationTable(idLexer *this, const punctuation_t *punctuations)
{
  int v4; // r31
  int *punctuationtable; // r11
  int *nextpunctuation; // r4
  const punctuation_t *v7; // r11
  int v8; // r4
  const punctuation_t *v9; // r5
  int v10; // r3
  int v11; // r7
  int v12; // r11
  int v13; // r9
  int v14; // r6
  int v15; // r10
  char *p; // r11
  int v17; // r11
  int *v18; // r11
  bool v19; // zf

  if ( punctuations == idLexer::defaultPunctuations )
  {
    this->punctuationtable = default_punctuationtable;
    this->nextpunctuation = default_nextpunctuation;
    if ( default_setup != 0 )
      return;
    v4 = 57;
    default_setup = 1;
  }
  else
  {
    punctuationtable = this->punctuationtable;
    if ( punctuationtable == nullptr || punctuationtable == default_punctuationtable )
      this->punctuationtable = (int *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\text\\Lexer.cpp(118) : TAG_LEXER",
                                        size: 0x400u,
                                        tag: TAG_LEXER,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
    nextpunctuation = this->nextpunctuation;
    if ( nextpunctuation != nullptr && nextpunctuation != default_nextpunctuation )
      idMem::Free(this: &mem, ptr: nextpunctuation, align: ALIGN_16);
    v4 = 0;
    if ( punctuations->p != nullptr )
    {
      v7 = punctuations;
      do
      {
        ++v7;
        ++v4;
      }
      while ( v7->p != nullptr );
    }
    this->nextpunctuation = (int *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\text\\Lexer.cpp(125) : TAG_LEXER",
                                     size: 4 * v4,
                                     tag: TAG_LEXER,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  }
  memset(Dst: this->punctuationtable, Val: 255, Size: 0x400u);
  memset(Dst: this->nextpunctuation, Val: 255, Size: 4 * v4);
  v8 = 0;
  if ( punctuations->p != nullptr )
  {
    v9 = punctuations;
    v10 = 0;
    do
    {
      v11 = -1;
      v12 = *(unsigned __int8 *)v9->p;
      v13 = *(int *)((char *)this->punctuationtable + __ROL4__(v12, 2));
      if ( v13 < 0 )
      {
LABEL_28:
        this->nextpunctuation[v10] = -1;
        if ( v11 < 0 )
          goto LABEL_30;
        this->nextpunctuation[v11] = v8;
      }
      else
      {
        v14 = (char)v12;
        while ( 1 )
        {
          v15 = 0;
          p = punctuations[v13].p;
          if ( *p != 0 )
          {
            do
              ++v15;
            while ( p[v15] != 0 );
          }
          v17 = 0;
          if ( v14 != 0 )
          {
            do
              ++v17;
            while ( v9->p[v17] != 0 );
          }
          v19 = v15 < v17;
          v18 = this->nextpunctuation;
          if ( v19 )
            break;
          v11 = v13;
          v13 = v18[v13];
          if ( v13 < 0 )
            goto LABEL_28;
        }
        v18[v10] = v13;
        if ( v11 < 0 )
        {
LABEL_30:
          *(int *)((char *)this->punctuationtable + __ROL4__(*(unsigned __int8 *)v9->p, 2)) = v8;
          goto LABEL_31;
        }
        this->nextpunctuation[v11] = v8;
      }
LABEL_31:
      ++v8;
      ++v10;
      v9 = &punctuations[v8];
    }
    while ( v9->p != nullptr );
  }
}


// ========================================================================
// ?Error@idLexer@@QAAXPBDZZ
// EA  : 0x82F88328
// RVA : 0x00F88328
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idLexer::Error(
        idLexer *this,
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
  __int64 v12; // r8
  __int64 v13; // r6
  __int64 v14; // r4
  int flags; // r11
  __int64 v16; // r10
  __int64 v17; // r4
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  int v21; // r10
  int v22; // r9
  int v23; // r8
  int v24; // r7
  int v25; // r6
  int v26; // r5
  int v27; // r4
  int v28; // r3
  int v29; // [sp+8h] [-9F8h]
  int v30; // [sp+Ch] [-9F4h]
  int v31; // [sp+10h] [-9F0h]
  int v32; // [sp+14h] [-9ECh]
  _BYTE v33[4]; // [sp+50h] [-9B0h] BYREF
  va_list v34; // [sp+54h] [-9ACh]
  char v35[128]; // [sp+60h] [-9A0h] BYREF
  char v36[256]; // [sp+E0h] [-920h] BYREF
  char v37[1024]; // [sp+1E0h] [-820h] BYREF
  char v38[1032]; // [sp+5E0h] [-420h] BYREF
  __int64 v40; // [sp+A20h] [+20h] BYREF
  va_list va; // [sp+A20h] [+20h]
  __int64 v42; // [sp+A28h] [+28h]
  __int64 v43; // [sp+A30h] [+30h]
  __int64 v44; // [sp+A38h] [+38h]
  __int64 v45; // [sp+A40h] [+40h]
  __int64 v46; // [sp+A48h] [+48h]
  va_list va1; // [sp+A50h] [+50h] BYREF

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
  v40 = *(__int64 *)((char *)&a3 + 4);
  v42 = a3;
  v43 = *(__int64 *)((char *)&a4 + 4);
  v44 = a4;
  v45 = *(__int64 *)((char *)&a5 + 4);
  v46 = a5;
  if ( (this->flags & 1) != 0 )
  {
    this->hadError = true;
    return;
  }
  va_copy(v34, va);
  idStr::vsnPrintf(dest: v38, size: 1024, fmt: str, argptr: va);
  if ( (this->flags & 8) != 0 )
  {
    idStr::Copynz(dest: v36, src: this->filename.data, destsize: 256);
    idStr::SlashesToBackSlashes(path: v36);
    idStr::snPrintf(dest: v37, size: 1024, fmt: "%s(%d) : error : %s", v36, this->line, v38);
  }
  else
  {
    idStr::snPrintf(dest: v37, size: 1024, fmt: "file %s, line %d: %s", this->filename.data, this->line, v38);
  }
  if ( this->hadError )
  {
    if ( (this->flags & 0x200000) == 0 )
      return;
  }
  else
  {
    idStr::operator=(this: &this->errorMsg, text: v37);
  }
  flags = this->flags;
  LODWORD(v16) = 1;
  HIDWORD(v16) = flags & 4;
  this->hadError = true;
  if ( (flags & 4) != 0 )
  {
    if ( (flags & 8) != 0 )
    {
      HIDWORD(v14) = v37;
      idLib::Printf(fmt: v14, a2: v13, a3: v12, a4: v16, a5: v29, a6: v30, a7: v31, a8: v32);
    }
    else
    {
      idStr::snPrintf(dest: v35, size: 128, fmt: "line %d", this->line);
      v33[0] = idLib::PushWarningInfo(type: this->filename.data, name: v35);
      HIDWORD(v17) = v38;
      idLib::Warning(fmt: v17, a2: v20, a3: v19, a4: v18, a5: v29, a6: v30, a7: v31, a8: v32);
      if ( v33[0] != 0 )
        idLib::PopWarningInfo();
    }
  }
  else
  {
    if ( (flags & 0x40000) != 0 )
    {
      strncpy(dest: idException::error, source: v37, count: 0x800u);
      CxxThrowException(pExceptionObject: v33, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidLexerException__);
    }
    HIDWORD(v14) = v37;
    idLib::Error(fmt: v14, a2: v13, a3: v12, a4: v16, a5: v29, a6: v30, a7: v31, a8: v32);
    _LN44_2(
      a1: v28,
      a2: v27,
      a3: v26,
      a4: v25,
      a5: v24,
      a6: v23,
      a7: v22,
      a8: v21,
      a9: a6,
      a10: a7,
      a11: a8,
      a12: a9,
      a13: a10,
      a14: str,
      a15: HIDWORD(v40),
      a16: v40,
      a17: HIDWORD(v42),
      a18: v42);
  }
}


// ========================================================================
// $LN44_2
// EA  : 0x82F884EC
// RVA : 0x00F884EC
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _LN44_2()
{
  int v0; // r12

  idWarningInfo::~idWarningInfo(this: (idWarningInfo *)(v0 - 2560 + 80));
}


// ========================================================================
// ?SetPunctuations@idLexer@@QAAXPBUpunctuation_t@@@Z
// EA  : 0x82F88518
// RVA : 0x00F88518
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void __fastcall idLexer::SetPunctuations(idLexer *this, const punctuation_t *p)
{
  const punctuation_t *v3; // r30

  v3 = p;
  if ( p == nullptr )
    v3 = idLexer::defaultPunctuations;
  idLexer::CreatePunctuationTable(this, punctuations: v3);
  this->punctuations = v3;
}


// ========================================================================
// ?ReadName@idLexer@@AAA_NAAVidToken@@@Z
// EA  : 0x82F88568
// RVA : 0x00F88568
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::ReadName(idLexer *this, idToken *token, int a3, int a4, char a5)
{
  const char *script_p; // r11
  char v8; // r30
  unsigned int allocedAndFlag; // r11
  __int64 v10; // r10
  int v11; // r4
  int v12; // r11
  bool v13; // zf
  __int64 v14; // r6
  int v15; // r9
  int flags; // r10

  token->type = 4;
  while ( 1 )
  {
    script_p = this->script_p;
    v8 = *script_p;
    this->script_p = script_p + 1;
    allocedAndFlag = token->allocedAndFlag;
    HIDWORD(v10) = allocedAndFlag >> 31;
    v11 = token->len + 2;
    v13 = allocedAndFlag >> 31 == 0;
    v12 = allocedAndFlag & 0x7FFFFFFF;
    if ( v13 )
    {
      if ( v11 > v12 )
        idStr::ReAllocate(this: token, amount: v11, keepold: true);
    }
    else if ( v11 > v12 )
    {
      HIDWORD(v14) = "amount <= GetAlloced()";
      LODWORD(v14) = 1;
      LODWORD(v10) = token->len;
      if ( (unsigned __int8)AssertFailed(
                              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                              expression: v14,
                              inlineBreak: a5,
                              a4: v10) != 0 )
        __trap();
    }
    token->data[token->len] = v8;
    v15 = token->len + 1;
    token->len = v15;
    a5 = *this->script_p;
    if ( (a5 < 97 || a5 > 122) && (a5 < 65 || a5 > 90) && (a5 < 48 || a5 > 57) && a5 != 95 )
    {
      flags = this->flags;
      if ( ((flags & 0x8000) == 0 || a5 != 45)
        && ((flags & 0x200) == 0 || a5 != 47 && a5 != 92 && a5 != 58 && a5 != 46 && a5 != 64)
        && ((flags & 0x100000) == 0 || a5 != 42) )
      {
        break;
      }
    }
  }
  token->data[v15] = 0;
  token->subtype = token->len;
  return 1;
}


// ========================================================================
// ?ReadNumber@idLexer@@AAA_NAAVidToken@@@Z
// EA  : 0x82F886E0
// RVA : 0x00F886E0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::ReadNumber(idLexer *this, idToken *token, __int64 a3, __int64 a4, __int64 a5)
{
  const char *script_p; // r11
  int v8; // r29
  const char *v9; // r10
  char v10; // r27
  int i; // r28
  const char *v12; // r11
  char v13; // r4
  const char *v14; // r11
  char v15; // r4
  const char *v16; // r11
  char v17; // r4
  const char *v18; // r11
  char v19; // r4
  const char *v20; // r11
  int v21; // r26
  unsigned int allocedAndFlag; // r11
  __int64 v23; // r10
  int v24; // r4
  int v25; // r11
  bool v26; // zf
  __int64 v27; // r6
  const char *v28; // r11
  const char *v30; // r11
  const char *v31; // r11
  const char *v32; // r11
  const char *v33; // r11
  bool v34; // r7
  int v35; // r10
  int v36; // r28
  const char *v37; // r11
  unsigned int v38; // r11
  __int64 v39; // r10
  int v40; // r4
  int v41; // r11
  __int64 v42; // r6
  const char *v43; // r11
  __int64 v44; // r6
  __int64 v45; // r10
  __int64 v46; // r8
  int subtype; // r11
  int v48; // r10
  int v49; // r9
  const char *v50; // r11
  const char *v51; // r11
  char v52; // r29
  int j; // r11
  const char *v54; // r11
  int v55; // [sp+8h] [-B8h]
  int v56; // [sp+Ch] [-B4h]
  int v57; // [sp+10h] [-B0h]
  int v58; // [sp+14h] [-ACh]
  int v59; // [sp+18h] [-A8h]
  int v60; // [sp+1Ch] [-A4h]

  token->subtype = 0;
  token->type = 3;
  token->intvalue = 0;
  token->floatvalue = 0.0;
  script_p = this->script_p;
  v8 = *(unsigned __int8 *)script_p;
  v9 = script_p + 1;
  v10 = script_p[1];
  if ( v8 == 48 )
  {
    HIDWORD(a5) = v10;
    if ( v10 != 46 )
    {
      if ( v10 == 120 || v10 == 88 )
      {
        v17 = *script_p;
        this->script_p = v9;
        idToken::AppendDirty(this: token, a: v17);
        v18 = this->script_p;
        v19 = *v18;
        this->script_p = v18 + 1;
        idToken::AppendDirty(this: token, a: v19);
        for ( LOBYTE(v8) = *this->script_p; ; LOBYTE(v8) = *v20 )
        {
          i = (char)v8;
          if ( ((char)v8 < 48 || (char)v8 > 57) && ((char)v8 < 97 || (char)v8 > 102) && ((char)v8 < 65 || (char)v8 > 70) )
            break;
          idStr::EnsureAlloced(this: token, amount: token->len + 2, keepold: true, geometricGrowth: false);
          token->data[token->len++] = v8;
          v20 = this->script_p + 1;
          this->script_p = v20;
        }
        token->subtype = 5;
      }
      else if ( v10 == 98 || v10 == 66 )
      {
        v13 = *script_p;
        this->script_p = v9;
        idToken::AppendDirty(this: token, a: v13);
        v14 = this->script_p;
        v15 = *v14;
        this->script_p = v14 + 1;
        idToken::AppendDirty(this: token, a: v15);
        for ( LOBYTE(v8) = *this->script_p; ; LOBYTE(v8) = *v16 )
        {
          i = (char)v8;
          if ( (char)v8 != 48 && (char)v8 != 49 )
            break;
          idToken::AppendDirty(this: token, a: v8);
          v16 = this->script_p + 1;
          this->script_p = v16;
        }
        token->subtype = 17;
      }
      else
      {
        this->script_p = v9;
        idToken::AppendDirty(this: token, a: 48);
        LOBYTE(v8) = *this->script_p;
        for ( i = (char)v8; i >= 48; i = *v12 )
        {
          if ( i > 55 )
            break;
          idToken::AppendDirty(this: token, a: v8);
          v12 = this->script_p + 1;
          this->script_p = v12;
          LOBYTE(v8) = *v12;
        }
        token->subtype = 9;
      }
      goto LABEL_79;
    }
  }
  v21 = 0;
  while ( 1 )
  {
    i = (char)v8;
    if ( (char)v8 < 48 || (char)v8 > 57 )
      break;
LABEL_30:
    allocedAndFlag = token->allocedAndFlag;
    HIDWORD(v23) = allocedAndFlag >> 31;
    v24 = token->len + 2;
    v26 = allocedAndFlag >> 31 == 0;
    v25 = allocedAndFlag & 0x7FFFFFFF;
    if ( v26 )
    {
      if ( v24 > v25 )
        idStr::ReAllocate(this: token, amount: v24, keepold: true);
    }
    else if ( v24 > v25 )
    {
      HIDWORD(v27) = "amount <= GetAlloced()";
      LODWORD(v27) = 1;
      LODWORD(v23) = token->len;
      if ( (unsigned __int8)AssertFailed(
                              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                              expression: v27,
                              inlineBreak: SBYTE3(a4),
                              a4: v23) != 0 )
        __trap();
    }
    token->data[token->len] = v8;
    HIDWORD(a5) = token->len + 1;
    token->len = HIDWORD(a5);
    v28 = this->script_p + 1;
    this->script_p = v28;
    LOBYTE(v8) = *v28;
  }
  if ( (char)v8 == 46 )
  {
    ++v21;
    goto LABEL_30;
  }
  if ( v21 == 1 || (char)v8 == 101 )
  {
    token->subtype = 130;
    if ( (char)v8 == 101 )
    {
      idToken::AppendDirty(this: token, a: v8);
      v30 = this->script_p + 1;
      this->script_p = v30;
      LOBYTE(v8) = *v30;
      if ( *v30 == 45 || (char)v8 == 43 )
      {
        idToken::AppendDirty(this: token, a: v8);
        v31 = this->script_p + 1;
        this->script_p = v31;
        LOBYTE(v8) = *v31;
      }
      for ( i = (char)v8; i >= 48; i = *v32 )
      {
        if ( i > 57 )
          break;
        idStr::EnsureAlloced(this: token, amount: token->len + 2, keepold: true, geometricGrowth: false);
        token->data[token->len++] = v8;
        v32 = this->script_p + 1;
        this->script_p = v32;
        LOBYTE(v8) = *v32;
      }
      goto LABEL_79;
    }
    if ( (char)v8 != 35 )
      goto LABEL_79;
    idToken::AppendDirty(this: token, a: v8);
    v33 = this->script_p + 1;
    this->script_p = v33;
    LOBYTE(v8) = *v33;
    if ( (unsigned __int8)idLexer::CheckString(this, str: "INF") != 0 )
    {
      v10 = 3;
      v35 = token->subtype | 0x800;
    }
    else if ( (unsigned __int8)idLexer::CheckString(this, str: "IND") != 0 )
    {
      v10 = 3;
      v35 = token->subtype | 0x1000;
    }
    else
    {
      if ( (unsigned __int8)idLexer::CheckString(this, str: "NAN") != 0 )
      {
        v10 = 3;
      }
      else
      {
        if ( (unsigned __int8)idLexer::CheckString(this, str: "QNAN") == 0
          && (unsigned __int8)idLexer::CheckString(this, str: "SNAN") == 0 )
        {
          goto LABEL_66;
        }
        v10 = 4;
      }
      v35 = token->subtype | 0x2000;
    }
    token->subtype = v35;
LABEL_66:
    v36 = v10;
    if ( v10 > 0 )
    {
      do
      {
        idStr::EnsureAlloced(this: token, amount: token->len + 2, keepold: true, geometricGrowth: false);
        --v36;
        token->data[token->len++] = v8;
        v37 = this->script_p + 1;
        this->script_p = v37;
        LOBYTE(v8) = *v37;
      }
      while ( v36 != 0 );
    }
    for ( i = (char)v8; i >= 48; i = *v43 )
    {
      if ( i > 57 )
        break;
      v38 = token->allocedAndFlag;
      HIDWORD(v39) = v38 >> 31;
      v40 = token->len + 2;
      v26 = v38 >> 31 == 0;
      v41 = v38 & 0x7FFFFFFF;
      if ( v26 )
      {
        if ( v40 > v41 )
          idStr::ReAllocate(this: token, amount: v40, keepold: true);
      }
      else if ( v40 > v41 )
      {
        HIDWORD(v42) = "amount <= GetAlloced()";
        LODWORD(v42) = 1;
        LODWORD(v39) = token->len;
        if ( (unsigned __int8)AssertFailed(
                                file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                                expression: v42,
                                inlineBreak: v34,
                                a4: v39) != 0 )
          __trap();
      }
      token->data[token->len++] = v8;
      v43 = this->script_p + 1;
      this->script_p = v43;
      LOBYTE(v8) = *v43;
    }
    if ( (this->flags & 0x1000) == 0 )
    {
      idToken::AppendDirty(this: token, a: 0);
      HIDWORD(v44) = token->data;
      idLexer::Error(
        this,
        str: "parsed %s",
        a3: v44,
        a4: v46,
        a5: v45,
        a6: v55,
        a7: v56,
        a8: v57,
        a9: v58,
        a10: v59,
        a11: v60);
    }
    goto LABEL_79;
  }
  if ( v21 <= 1 )
  {
    token->subtype = 3;
  }
  else
  {
    LODWORD(a5) = this->flags & 0x800;
    if ( (_DWORD)a5 == 0 )
    {
      idLexer::Error(
        this,
        str: "more than one dot in number",
        a3,
        a4,
        a5,
        a6: v55,
        a7: v56,
        a8: v57,
        a9: v58,
        a10: v59,
        a11: v60);
      return 0;
    }
    if ( v21 != 3 )
    {
      idLexer::Error(
        this,
        str: "ip address should have three dots",
        a3,
        a4,
        a5,
        a6: v55,
        a7: v56,
        a8: v57,
        a9: v58,
        a10: v59,
        a11: v60);
      return 0;
    }
    token->subtype = 0x4000;
  }
LABEL_79:
  subtype = token->subtype;
  if ( (subtype & 0x80) == 0 )
  {
    if ( (subtype & 1) != 0 )
    {
      if ( i > 32 )
      {
        v48 = 0;
        while ( 1 )
        {
          if ( (char)v8 == 108 || (char)v8 == 76 )
          {
            v49 = token->subtype | 0x20;
          }
          else
          {
            if ( (char)v8 != 117 && (char)v8 != 85 )
              goto LABEL_105;
            v49 = token->subtype | 0x40;
          }
          token->subtype = v49;
          ++v48;
          v50 = this->script_p + 1;
          this->script_p = v50;
          LOBYTE(v8) = *v50;
          if ( v48 >= 2 )
            goto LABEL_105;
        }
      }
    }
    else if ( (subtype & 0x4000) != 0 && i == 58 )
    {
      idToken::AppendDirty(this: token, a: v8);
      v51 = this->script_p + 1;
      this->script_p = v51;
      v52 = *v51;
      for ( j = v52; v52 >= 48; j = v52 )
      {
        if ( j > 57 )
          break;
        idStr::EnsureAlloced(this: token, amount: token->len + 2, keepold: true, geometricGrowth: false);
        token->data[token->len++] = v52;
        v54 = this->script_p + 1;
        this->script_p = v54;
        v52 = *v54;
      }
      token->subtype |= 0x8000u;
    }
    goto LABEL_105;
  }
  if ( i > 32 )
  {
    if ( i == 102 || i == 70 )
    {
      token->subtype = subtype | 0x100;
      ++this->script_p;
      goto LABEL_105;
    }
    if ( i == 108 || i == 76 )
    {
      token->subtype = subtype | 0x400;
      ++this->script_p;
LABEL_105:
      token->data[token->len] = 0;
      return 1;
    }
  }
  token->subtype = subtype | 0x200;
  goto LABEL_105;
}


// ========================================================================
// ?ReadRawStringBlock@idLexer@@AAA_NAAVidToken@@@Z
// EA  : 0x82F88E88
// RVA : 0x00F88E88
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::ReadRawStringBlock(idLexer *this, idToken *token, __int64 a3, __int64 a4, __int64 a5)
{
  const char *script_p; // r11
  char v8; // r29
  unsigned int allocedAndFlag; // r11
  __int64 v10; // r10
  int v11; // r4
  int v12; // r11
  bool v13; // zf
  __int64 v14; // r6
  int v16; // [sp+8h] [-88h]
  int v17; // [sp+Ch] [-84h]
  int v18; // [sp+10h] [-80h]
  int v19; // [sp+14h] [-7Ch]
  int v20; // [sp+18h] [-78h]
  int v21; // [sp+1Ch] [-74h]

  token->type = 1;
  this->script_p += 2;
  while ( 1 )
  {
    script_p = this->script_p;
    LODWORD(a5) = *script_p;
    if ( (_DWORD)a5 == 37 )
    {
      HIDWORD(a5) = *((unsigned __int8 *)script_p + 1);
      if ( HIDWORD(a5) == 62 )
      {
        this->script_p = script_p + 2;
        token->data[token->len] = 0;
        token->subtype = token->len;
        return 1;
      }
    }
    if ( *script_p == 0 )
      break;
    if ( (_DWORD)a5 == 10 )
      ++this->line;
    v8 = *script_p;
    this->script_p = script_p + 1;
    allocedAndFlag = token->allocedAndFlag;
    HIDWORD(v10) = allocedAndFlag >> 31;
    v11 = token->len + 2;
    v13 = allocedAndFlag >> 31 == 0;
    v12 = allocedAndFlag & 0x7FFFFFFF;
    if ( v13 )
    {
      if ( v11 > v12 )
        idStr::ReAllocate(this: token, amount: v11, keepold: true);
    }
    else if ( v11 > v12 )
    {
      HIDWORD(v14) = "amount <= GetAlloced()";
      LODWORD(v14) = 1;
      LODWORD(v10) = token->len;
      if ( (unsigned __int8)AssertFailed(
                              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                              expression: v14,
                              inlineBreak: SBYTE3(a4),
                              a4: v10) != 0 )
        __trap();
    }
    token->data[token->len] = v8;
    HIDWORD(a5) = token->len + 1;
    token->len = HIDWORD(a5);
  }
  idLexer::Error(
    this,
    str: "missing trailing identifier",
    a3,
    a4,
    a5,
    a6: v16,
    a7: v17,
    a8: v18,
    a9: v19,
    a10: v20,
    a11: v21);
  return 0;
}


// ========================================================================
// ?ReadPunctuation@idLexer@@AAA_NAAVidToken@@@Z
// EA  : 0x82F88FD0
// RVA : 0x00F88FD0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::ReadPunctuation(idLexer *this, idToken *token, int a3, int a4, char a5)
{
  const char *script_p; // r8
  __int64 v8; // r10
  int v9; // r31
  _DWORD *v10; // r28
  _BYTE *v11; // r30
  unsigned int allocedAndFlag; // r11
  int v14; // r29
  int v15; // r11
  bool v16; // zf
  __int64 v17; // r6
  int v18; // r11
  int v19; // ctr

  script_p = this->script_p;
  LODWORD(v8) = *(int *)((char *)this->punctuationtable + __ROL4__(*(unsigned __int8 *)script_p, 2));
  if ( (int)v8 < 0 )
    return 0;
  HIDWORD(v8) = this->punctuations;
  while ( 1 )
  {
    v9 = 0;
    v10 = (_DWORD *)(8 * v8 + HIDWORD(v8));
    v11 = (_BYTE *)*v10;
    if ( *(_BYTE *)*v10 != 0 )
    {
      do
      {
        if ( script_p[v9] == 0 )
          break;
        a5 = v11[v9];
        if ( script_p[v9] != a5 )
          break;
        ++v9;
      }
      while ( v11[v9] != 0 );
    }
    if ( v11[v9] == 0 )
      break;
    LODWORD(v8) = this->nextpunctuation[v8];
    if ( (int)v8 < 0 )
      return 0;
  }
  allocedAndFlag = token->allocedAndFlag;
  v14 = v9 + 1;
  v16 = allocedAndFlag >> 31 == 0;
  v15 = allocedAndFlag & 0x7FFFFFFF;
  if ( v16 )
  {
    if ( v14 > v15 )
      idStr::ReAllocate(this: token, amount: v9 + 1, keepold: false);
  }
  else if ( v14 > v15 )
  {
    LODWORD(v8) = 0x82000000;
    HIDWORD(v17) = "amount <= GetAlloced()";
    LODWORD(v17) = 1;
    if ( (unsigned __int8)AssertFailed(
                            file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                            expression: v17,
                            inlineBreak: a5,
                            a4: v8) != 0 )
      __trap();
  }
  v18 = 0;
  if ( v9 >= 0 )
  {
    v19 = v9 + 1;
    do
    {
      token->data[v18] = v11[v18];
      ++v18;
      --v19;
    }
    while ( v19 != 0 );
  }
  token->len = v9;
  this->script_p += v9;
  token->type = 5;
  token->subtype = v10[1];
  return 1;
}


// ========================================================================
// ?ParseRestOfLine@idLexer@@QAAPBDAAVidStr@@@Z
// EA  : 0x82F89140
// RVA : 0x00F89140
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

char *__fastcall idLexer::ParseRestOfLine(idLexer *this, idStr *out)
{
  const char *script_p; // r29
  const char *v5; // r11
  const char *v6; // r11
  char *data; // r30
  idStr v9; // [sp+50h] [-80h] BYREF
  int v10; // [sp+84h] [-4Ch]
  float v11; // [sp+88h] [-48h]
  int v12; // [sp+8Ch] [-44h]
  int v13; // [sp+90h] [-40h]
  int v14; // [sp+94h] [-3Ch]

  v9.len = 0;
  v9.allocedAndFlag = 20;
  v11 = -3.4028235e38;
  v9.data = v9.baseBuffer;
  v9.baseBuffer[0] = 0;
  v10 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  script_p = this->script_p;
  if ( *script_p != 0 )
  {
    do
    {
      v5 = this->script_p;
      if ( *v5 == 10 )
        break;
      this->script_p = v5 + 1;
    }
    while ( v5[1] != 0 );
  }
  for ( ; *script_p <= 32; ++script_p )
  {
    if ( script_p >= this->script_p )
      break;
  }
  if ( *((char *)this->script_p - 1) <= 32 )
  {
    do
    {
      v6 = this->script_p;
      if ( v6 <= script_p )
        break;
      this->script_p = v6 - 1;
    }
    while ( *(v6 - 2) <= 32 );
  }
  idStr::EnsureAlloced(this: out, amount: 1, keepold: true, geometricGrowth: false);
  *out->data = 0;
  out->len = 0;
  idStr::Append(this: out, text: script_p, l: this->script_p - script_p);
  data = out->data;
  idStr::FreeData(this: &v9);
  return data;
}


// ========================================================================
// __unwind$113029
// EA  : 0x82F8927C
// RVA : 0x00F8927C
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_113029()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?ParseCompleteLine@idLexer@@QAAPBDAAVidStr@@@Z
// EA  : 0x82F892B0
// RVA : 0x00F892B0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

char *__fastcall idLexer::ParseCompleteLine(idLexer *this, idStr *out)
{
  const char *script_p; // r27
  const char *v5; // r11
  int v6; // r10
  const char *v7; // r11
  char *data; // r30
  idStr v10; // [sp+50h] [-80h] BYREF
  int v11; // [sp+84h] [-4Ch]
  float v12; // [sp+88h] [-48h]
  int v13; // [sp+8Ch] [-44h]
  int v14; // [sp+90h] [-40h]
  int v15; // [sp+94h] [-3Ch]

  v10.len = 0;
  v10.allocedAndFlag = 20;
  v12 = -3.4028235e38;
  v10.data = v10.baseBuffer;
  v10.baseBuffer[0] = 0;
  v11 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  script_p = this->script_p;
  if ( *script_p != 0 )
  {
    while ( 1 )
    {
      v5 = this->script_p;
      v6 = *(unsigned __int8 *)v5;
      v7 = v5 + 1;
      this->script_p = v7;
      if ( v6 == 10 )
        break;
      if ( *v7 == 0 )
        goto LABEL_6;
    }
    ++this->line;
  }
LABEL_6:
  idStr::EnsureAlloced(this: out, amount: 1, keepold: true, geometricGrowth: false);
  *out->data = 0;
  out->len = 0;
  idStr::Append(this: out, text: script_p, l: this->script_p - script_p);
  data = out->data;
  idStr::FreeData(this: &v10);
  return data;
}


// ========================================================================
// __unwind$113105
// EA  : 0x82F89398
// RVA : 0x00F89398
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_113105()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?GetLastWhiteSpace@idLexer@@QBAHAAVidStr@@@Z
// EA  : 0x82F893C0
// RVA : 0x00F893C0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::GetLastWhiteSpace(idLexer *this, idStr *whiteSpace)
{
  bool v4; // r7
  const char *i; // r30
  unsigned int allocedAndFlag; // r11
  char v7; // r29
  __int64 v8; // r10
  int v9; // r11
  bool v10; // zf
  __int64 v11; // r6
  char *data; // r9
  int v13; // r11

  idStr::Clear(this: whiteSpace);
  for ( i = this->whiteSpaceStart_p; i < this->whiteSpaceEnd_p; data[v13] = 0 )
  {
    allocedAndFlag = whiteSpace->allocedAndFlag;
    HIDWORD(v8) = allocedAndFlag >> 31;
    v7 = *i;
    LODWORD(v8) = whiteSpace->len + 2;
    v10 = allocedAndFlag >> 31 == 0;
    v9 = allocedAndFlag & 0x7FFFFFFF;
    if ( v10 )
    {
      if ( (int)v8 > v9 )
        idStr::ReAllocate(this: whiteSpace, amount: ((int)v8 >> 1) + v8, keepold: true);
    }
    else if ( (int)v8 > v9 )
    {
      HIDWORD(v11) = "amount <= GetAlloced()";
      LODWORD(v11) = 1;
      if ( (unsigned __int8)AssertFailed(
                              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                              expression: v11,
                              inlineBreak: v4,
                              a4: v8) != 0 )
        __trap();
    }
    ++i;
    whiteSpace->data[whiteSpace->len] = v7;
    data = whiteSpace->data;
    v13 = whiteSpace->len + 1;
    whiteSpace->len = v13;
  }
  return whiteSpace->len;
}


// ========================================================================
// ?GetWhiteSpaceBeforeToken@idLexer@@QBA_NABVidToken@@AAVidStr@@@Z
// EA  : 0x82F894A8
// RVA : 0x00F894A8
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::GetWhiteSpaceBeforeToken(idLexer *this, const idToken *token, idStr *whiteSpace)
{
  char *whiteSpaceStart_p; // r31
  const char *buffer; // r11
  const char *v8; // r10
  const char *whiteSpaceEnd_p; // r11

  whiteSpaceStart_p = (char *)token->whiteSpaceStart_p;
  if ( whiteSpaceStart_p == idToken::DEFAULT_WHITESPACE )
  {
    idStr::operator=(this: whiteSpace, text: idToken::DEFAULT_WHITESPACE);
    return 1;
  }
  else
  {
    buffer = this->buffer;
    if ( whiteSpaceStart_p < buffer )
      return 0;
    v8 = &buffer[this->length];
    whiteSpaceEnd_p = token->whiteSpaceEnd_p;
    if ( whiteSpaceEnd_p >= v8 )
    {
      return 0;
    }
    else
    {
      if ( whiteSpaceStart_p < whiteSpaceEnd_p )
      {
        do
          idStr::Append(this: whiteSpace, a: *whiteSpaceStart_p++);
        while ( whiteSpaceStart_p < token->whiteSpaceEnd_p );
      }
      return 1;
    }
  }
}


// ========================================================================
// ?LoadFilePartial@idLexer@@QAA_NPBD_NH@Z
// EA  : 0x82F89540
// RVA : 0x00F89540
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idFile *__fastcall idLexer::LoadFilePartial(
        idLexer *this,
        const char *filename_,
        __int64 maxLoadBytes,
        __int64 a4,
        __int64 a5)
{
  _BYTE *v5; // r3
  _BYTE *v6; // r31
  char v7; // r28
  int v8; // r29
  const char *v9; // r3
  idFile *result; // r3
  idFile *v11; // r30
  int v12; // r3
  _BYTE *v13; // r29
  idFile_vtbl *v14; // r11
  const char *v15; // r3
  int v16; // r10
  int v17; // r11
  int v18; // [sp+8h] [-78h]
  int v19; // [sp+Ch] [-74h]
  int v20; // [sp+10h] [-70h]
  int v21; // [sp+14h] [-6Ch]

  v6 = v5;
  v7 = BYTE3(maxLoadBytes);
  v8 = maxLoadBytes;
  if ( *v5 != 0 )
  {
    v9 = "LoadFile: another script already loaded";
    idLib::Error(fmt: *(__int64 *)&filename_, a2: maxLoadBytes, a3: a4, a4: a5, a5: v18, a6: v19, a7: v20, a8: v21);
  }
  result = fileSystem->OpenFileRead(this: fileSystem, a2: filename_, a3: 1, a4: 0);
  v11 = result;
  if ( result != nullptr )
  {
    v12 = result->Length(this: result);
    if ( v12 >= v8 )
      v12 = v8;
    *((_DWORD *)v6 + 17) = v12;
    v13 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\shared\\idlib\\text\\Lexer.cpp(1823) : TAG_LEXER",
            size: v12 + 1,
            tag: TAG_LEXER,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    v11->Read(this: v11, a2: v13, a3: *((_DWORD *)v6 + 17));
    v13[*((_DWORD *)v6 + 17)] = 0;
    *((_DWORD *)v6 + 10) = v13;
    *((_DWORD *)v6 + 16) = v11->Timestamp(this: v11);
    v14 = v11->__vftable;
    if ( v7 != 0 )
      v15 = v14->GetFullPath(this: v11);
    else
      v15 = v14->GetName(this: v11);
    idStr::operator=(this: (idStr *)(v6 + 4), text: v15);
    idStr::CollapsePath(this: (idStr *)(v6 + 4));
    v16 = *((_DWORD *)v6 + 17);
    *((_DWORD *)v6 + 18) = 1;
    *((_DWORD *)v6 + 19) = 1;
    *((_DWORD *)v6 + 9) = 1;
    *v6 = 1;
    v17 = *((_DWORD *)v6 + 10);
    *((_DWORD *)v6 + 12) = v16 + v17;
    *((_DWORD *)v6 + 11) = v17;
    *((_DWORD *)v6 + 13) = v17;
    ((void (__fastcall *)(idFile *, int))v11->dtr_idFile)(a1: v11, a2: 1);
    return (idFile *)1;
  }
  return result;
}


// ========================================================================
// ?FreeSource@idLexer@@QAAXXZ
// EA  : 0x82F896D0
// RVA : 0x00F896D0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void __fastcall idLexer::FreeSource(idLexer *this)
{
  int *punctuationtable; // r4
  int *nextpunctuation; // r4

  punctuationtable = this->punctuationtable;
  if ( punctuationtable != nullptr && punctuationtable != default_punctuationtable )
  {
    idMem::Free(this: &mem, ptr: punctuationtable, align: ALIGN_16);
    this->punctuationtable = nullptr;
  }
  nextpunctuation = this->nextpunctuation;
  if ( nextpunctuation != nullptr && nextpunctuation != default_nextpunctuation )
  {
    idMem::Free(this: &mem, ptr: nextpunctuation, align: ALIGN_16);
    this->nextpunctuation = nullptr;
  }
  if ( this->allocated != 0 )
  {
    idMem::Free(this: &mem, ptr: (_DWORD *)this->buffer, align: ALIGN_16);
    this->allocated = 0;
  }
  this->buffer = nullptr;
  idStr::Clear(this: &this->filename);
  this->loaded = false;
  this->script_p = nullptr;
  this->end_p = nullptr;
  this->lastScript_p = nullptr;
  this->whiteSpaceStart_p = nullptr;
  this->whiteSpaceEnd_p = nullptr;
}


// ========================================================================
// ??0idLexer@@QAA@H@Z
// EA  : 0x82F89798
// RVA : 0x00F89798
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

idLexer *__fastcall idLexer::idLexer(idLexer *this, int flags_)
{
  this->filename.len = 0;
  this->filename.data = this->filename.baseBuffer;
  this->filename.allocedAndFlag = 20;
  this->filename.baseBuffer[0] = 0;
  this->errorMsg.allocedAndFlag = 20;
  this->errorMsg.len = 0;
  this->errorMsg.data = this->errorMsg.baseBuffer;
  this->errorMsg.baseBuffer[0] = 0;
  this->loaded = false;
  idStr::operator=(this: &this->filename, text: &byte_8200D768);
  this->flags = flags_;
  this->punctuations = nullptr;
  this->punctuationtable = nullptr;
  this->nextpunctuation = nullptr;
  this->allocated = 0;
  this->fileTime = 0;
  this->length = 0;
  this->line = 0;
  this->lastline = 0;
  this->hadError = false;
  this->hadWarning = false;
  this->buffer = nullptr;
  this->script_p = nullptr;
  this->end_p = nullptr;
  this->lastScript_p = nullptr;
  this->whiteSpaceStart_p = nullptr;
  this->whiteSpaceEnd_p = nullptr;
  this->next = nullptr;
  idLexer::CreatePunctuationTable(this, punctuations: idLexer::defaultPunctuations);
  this->punctuations = idLexer::defaultPunctuations;
  return this;
}


// ========================================================================
// __unwind$113266
// EA  : 0x82F8986C
// RVA : 0x00F8986C
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_113266()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$113267
// EA  : 0x82F89898
// RVA : 0x00F89898
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_113267()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 100));
}


// ========================================================================
// ??1idLexer@@QAA@XZ
// EA  : 0x82F898D0
// RVA : 0x00F898D0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void __fastcall idLexer::~idLexer(idLexer *this)
{
  idLexer::FreeSource(this);
  idStr::FreeData(this: &this->errorMsg);
  idStr::FreeData(this: &this->filename);
}


// ========================================================================
// __unwind$113341
// EA  : 0x82F8991C
// RVA : 0x00F8991C
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_113341()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$113342
// EA  : 0x82F89948
// RVA : 0x00F89948
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_113342()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 100));
}


// ========================================================================
// ?Warning@idLexer@@QAAXPBDZZ
// EA  : 0x82F89980
// RVA : 0x00F89980
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idLexer::Warning(
        idLexer *this,
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
  __int64 v13; // r6
  __int64 v14; // r10
  __int64 v15; // r8
  char v16; // r30
  __int64 v17; // r4
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  int v21; // [sp+8h] [-1118h]
  int v22; // [sp+Ch] [-1114h]
  int v23; // [sp+10h] [-1110h]
  int v24; // [sp+14h] [-110Ch]
  idStr v25; // [sp+60h] [-10C0h] BYREF
  char v26[128]; // [sp+80h] [-10A0h] BYREF
  char v27[32]; // [sp+100h] [-1020h] BYREF
  __int64 v28; // [sp+1140h] [+20h] BYREF
  va_list va; // [sp+1140h] [+20h]
  __int64 v30; // [sp+1148h] [+28h]
  __int64 v31; // [sp+1150h] [+30h]
  __int64 v32; // [sp+1158h] [+38h]
  __int64 v33; // [sp+1160h] [+40h]
  __int64 v34; // [sp+1168h] [+48h]
  va_list va1; // [sp+1170h] [+50h] BYREF

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
  v28 = *(__int64 *)((char *)&a3 + 4);
  v30 = a3;
  v31 = *(__int64 *)((char *)&a4 + 4);
  v32 = a4;
  v33 = *(__int64 *)((char *)&a5 + 4);
  v34 = a5;
  v12 = this->flags & 2;
  this->hadWarning = true;
  if ( v12 == 0 )
  {
    vsprintf(string: v27, format: str, ap: va);
    if ( (this->flags & 8) != 0 )
    {
      idStr::idStr(this: &v25, text: &this->filename);
      idStr::SlashesToBackSlashes(this: &v25);
      LODWORD(v13) = v27;
      HIDWORD(v13) = this->line;
      idLib::Warning(
        fmt: __SPAIR64__("%s(%d) : warning : %s", (unsigned int)v25.data),
        a2: v13,
        a3: v15,
        a4: v14,
        a5: v21,
        a6: v22,
        a7: v23,
        a8: v24);
      idStr::FreeData(this: &v25);
    }
    else
    {
      idStr::snPrintf(dest: v26, size: 128, fmt: "line %d", this->line);
      v16 = idLib::PushWarningInfo(type: this->filename.data, name: v26);
      HIDWORD(v17) = v27;
      idLib::Warning(fmt: v17, a2: v20, a3: v19, a4: v18, a5: v21, a6: v22, a7: v23, a8: v24);
      if ( v16 != 0 )
        idLib::PopWarningInfo();
    }
  }
}


// ========================================================================
// __unwind$113500
// EA  : 0x82F89A90
// RVA : 0x00F89A90
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_113500()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4384 + 96));
}


// ========================================================================
// __unwind$113501
// EA  : 0x82F89AB8
// RVA : 0x00F89AB8
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_113501()
{
  int v0; // r12

  idWarningInfo::~idWarningInfo(this: (idWarningInfo *)(v0 - 4384 + 80));
}


// ========================================================================
// ?SkipWhiteSpace@idLexer@@QAA_N_N@Z
// EA  : 0x82F89AE0
// RVA : 0x00F89AE0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::SkipWhiteSpace(idLexer *this, bool currentLine, __int64 a3, __int64 a4, __int64 a5)
{
  const char *script_p; // r11
  const char *v8; // r11
  const char *v9; // r11
  const char *v10; // r11
  bool v11; // zf
  const char *v12; // r11
  const char *v13; // r11
  char v14; // r10
  int v16; // [sp+8h] [-78h]
  int v17; // [sp+Ch] [-74h]
  int v18; // [sp+10h] [-70h]
  int v19; // [sp+14h] [-6Ch]
  int v20; // [sp+18h] [-68h]
  int v21; // [sp+1Ch] [-64h]

  script_p = this->script_p;
  if ( script_p == this->end_p )
    return 0;
LABEL_2:
  if ( *script_p <= 32 )
  {
    HIDWORD(a5) = this->end_p;
    do
    {
      v8 = this->script_p;
      if ( v8 == (const char *)HIDWORD(a5) || *v8 == 0 )
        return 0;
      if ( *v8 == 10 )
      {
        ++this->line;
        if ( currentLine )
        {
          this->script_p = v8 + 1;
          return 1;
        }
      }
      this->script_p = v8 + 1;
      LODWORD(a4) = *((unsigned __int8 *)v8 + 1);
      HIDWORD(a4) = (char)a4;
    }
    while ( (char)a4 <= 32 );
  }
  v9 = this->script_p;
  if ( *v9 == 47 )
  {
    v11 = v9[1] != 47;
    v10 = this->script_p;
    if ( !v11 )
    {
      v12 = v10 + 1;
      this->script_p = v12;
      while ( 1 )
      {
        this->script_p = ++v12;
        if ( *v12 == 0 )
          return 0;
        if ( *v12 == 10 )
        {
          script_p = v12 + 1;
          LODWORD(a4) = this->line + 1;
          this->script_p = script_p;
          this->line = a4;
          if ( currentLine )
            return 1;
          goto LABEL_26;
        }
      }
    }
    if ( v10[1] == 42 )
    {
      ++this->script_p;
      while ( 1 )
      {
        v13 = this->script_p + 1;
        this->script_p = v13;
        v14 = *v13;
        if ( *v13 == 0 )
          return 0;
        if ( v14 == 10 )
        {
          ++this->line;
        }
        else if ( v14 == 47 )
        {
          LODWORD(a5) = *((unsigned __int8 *)v13 - 1);
          if ( (_DWORD)a5 == 42 )
          {
            script_p = v13 + 1;
            this->script_p = script_p;
LABEL_26:
            if ( *script_p != 0 )
            {
              HIDWORD(a5) = this->end_p;
              if ( this->script_p != (const char *)HIDWORD(a5) )
                goto LABEL_2;
            }
            return 0;
          }
          if ( v13[1] == 42 )
            idLexer::Warning(
              this,
              str: "nested comment",
              a3,
              a4,
              a5,
              a6: v16,
              a7: v17,
              a8: v18,
              a9: v19,
              a10: v20,
              a11: v21);
        }
      }
    }
  }
  return 1;
}


// ========================================================================
// ?ReadEscapeCharacter@idLexer@@AAA_NPAD@Z
// EA  : 0x82F89CA8
// RVA : 0x00F89CA8
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::ReadEscapeCharacter(idLexer *this, char *ch, __int64 a3, __int64 a4)
{
  __int64 v6; // r10
  int v7; // r11
  int v8; // r11
  __int64 v9; // r10
  int v10; // r11
  int v12; // [sp+8h] [-78h]
  int v13; // [sp+Ch] [-74h]
  int v14; // [sp+10h] [-70h]
  int v15; // [sp+14h] [-6Ch]
  int v16; // [sp+18h] [-68h]
  int v17; // [sp+1Ch] [-64h]

  LODWORD(v6) = this->script_p + 1;
  LODWORD(a4) = this->flags & 0x10000;
  this->script_p = (const char *)v6;
  if ( (_DWORD)a4 != 0 )
  {
    LOBYTE(v7) = *(_BYTE *)v6;
    goto LABEL_45;
  }
  HIDWORD(v6) = *(unsigned __int8 *)v6;
  LOBYTE(v7) = *(_BYTE *)v6;
  if ( HIDWORD(v6) > 0x66 )
  {
    switch ( *(_BYTE *)v6 )
    {
      case 'n':
        LOBYTE(v7) = 10;
        break;
      case 'r':
        LOBYTE(v7) = 13;
        break;
      case 't':
        LOBYTE(v7) = 9;
        break;
      case 'v':
        LOBYTE(v7) = 11;
        break;
      case 'x':
        this->script_p = (const char *)(v6 + 1);
        LODWORD(v6) = 0;
        while ( 1 )
        {
          while ( 1 )
          {
            while ( 1 )
            {
              HIDWORD(v6) = this->script_p;
              v8 = (char)*(_BYTE *)HIDWORD(v6);
              if ( v8 < 48 || v8 > 57 )
                break;
              LODWORD(v6) = 16 * v6 + v8 - 48;
              this->script_p = (const char *)(HIDWORD(v6) + 1);
            }
            if ( v8 < 65 || v8 > 90 )
              break;
            LODWORD(v6) = 16 * v6 + v8 - 55;
            this->script_p = (const char *)(HIDWORD(v6) + 1);
          }
          if ( v8 < 97 || v8 > 122 )
            break;
          LODWORD(v6) = 16 * v6 + v8 - 87;
          this->script_p = (const char *)(HIDWORD(v6) + 1);
        }
        this->script_p = (const char *)(HIDWORD(v6) - 1);
        if ( (int)v6 > 255 )
        {
          idLexer::Warning(
            this,
            str: "too large value in escape character",
            a3,
            a4,
            a5: v6,
            a6: v12,
            a7: v13,
            a8: v14,
            a9: v15,
            a10: v16,
            a11: v17);
          LOBYTE(v6) = -1;
        }
        LOBYTE(v7) = v6;
        break;
      default:
        goto LABEL_36;
    }
  }
  else
  {
    if ( HIDWORD(v6) == 102 )
    {
      LOBYTE(v7) = 12;
      goto LABEL_45;
    }
    if ( HIDWORD(v6) > 0x5C )
    {
      if ( HIDWORD(v6) == 97 )
      {
        LOBYTE(v7) = 7;
        goto LABEL_45;
      }
      if ( HIDWORD(v6) == 98 )
      {
        LOBYTE(v7) = 8;
        goto LABEL_45;
      }
    }
    else
    {
      switch ( HIDWORD(v6) )
      {
        case '\\':
          LOBYTE(v7) = 92;
          goto LABEL_45;
        case '"':
          LOBYTE(v7) = 34;
          goto LABEL_45;
        case '\'':
          LOBYTE(v7) = 39;
          goto LABEL_45;
        case '?':
          goto LABEL_45;
        default:
          break;
      }
    }
LABEL_36:
    if ( SBYTE3(v6) < 48 || SBYTE3(v6) > 57 )
      idLexer::Error(
        this,
        str: "unknown escape char",
        a3,
        a4,
        a5: v6,
        a6: v12,
        a7: v13,
        a8: v14,
        a9: v15,
        a10: v16,
        a11: v17);
    v7 = 0;
    HIDWORD(v9) = *(unsigned __int8 *)this->script_p;
    LODWORD(v9) = SBYTE3(v9);
    if ( SBYTE3(v9) >= 48 )
    {
      do
      {
        if ( (int)v9 > 57 )
          break;
        HIDWORD(v9) = this->script_p + 1;
        LODWORD(a4) = 5 * v7;
        HIDWORD(a4) = HIDWORD(v9);
        this->script_p = (const char *)HIDWORD(v9);
        v10 = 10 * v7 + v9;
        LODWORD(a3) = (unsigned __int8)*(_BYTE *)HIDWORD(v9);
        LODWORD(v9) = (char)a3;
        v7 = v10 - 48;
      }
      while ( (char)a3 >= 48 );
    }
    LODWORD(v9) = this->script_p - 1;
    this->script_p = (const char *)v9;
    if ( v7 > 255 )
    {
      idLexer::Warning(
        this,
        str: "too large value in escape character",
        a3,
        a4,
        a5: v9,
        a6: v12,
        a7: v13,
        a8: v14,
        a9: v15,
        a10: v16,
        a11: v17);
      LOBYTE(v7) = -1;
    }
  }
LABEL_45:
  ++this->script_p;
  *ch = v7;
  return 1;
}


// ========================================================================
// ?ReadString@idLexer@@AAA_NAAVidToken@@H@Z
// EA  : 0x82F89F60
// RVA : 0x00F89F60
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::ReadString(idLexer *this, idToken *token, __int64 quote, __int64 a4, __int64 a5)
{
  int v7; // r27
  int v8; // r11
  const char *script_p; // r11
  char v10; // r29
  const char *v11; // r29
  int flags; // r11
  int line; // r28
  __int64 v14; // r10
  const char *v15; // r11
  __int64 v16; // r10
  const char *v17; // r11
  unsigned int allocedAndFlag; // r11
  __int64 v19; // r10
  int v20; // r4
  int v21; // r11
  bool v22; // zf
  __int64 v23; // r6
  __int64 v25; // r10
  int v26; // [sp+8h] [-B8h]
  int v27; // [sp+Ch] [-B4h]
  int v28; // [sp+10h] [-B0h]
  int v29; // [sp+14h] [-ACh]
  int v30; // [sp+18h] [-A8h]
  int v31; // [sp+1Ch] [-A4h]
  char v32; // [sp+70h] [-50h] BYREF

  v7 = HIDWORD(quote);
  v8 = 1;
  if ( HIDWORD(quote) != 34 )
    v8 = 2;
  token->type = v8;
  ++this->script_p;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        script_p = this->script_p;
        v10 = *script_p;
        LODWORD(a5) = *script_p;
        if ( (_DWORD)a5 != 92 )
          break;
        HIDWORD(a5) = this->flags;
        LODWORD(a4) = BYTE3(a5) & 0x20;
        if ( (a5 & 0x2000000000LL) != 0 )
          break;
        if ( (a5 & 0x1000000000000LL) != 0 )
        {
          idStr::EnsureAlloced(this: token, amount: token->len + 2, keepold: true, geometricGrowth: false);
          token->data[token->len++] = 92;
        }
        if ( (unsigned __int8)idLexer::ReadEscapeCharacter(this, ch: &v32, a3: quote, a4) == 0 )
          return 0;
        idStr::EnsureAlloced(this: token, amount: token->len + 2, keepold: true, geometricGrowth: false);
        HIDWORD(a5) = token->data;
        *(_BYTE *)(HIDWORD(a5) + token->len) = v32;
        LODWORD(a4) = token->len + 1;
        token->len = a4;
      }
      if ( v10 == v7 )
        break;
      if ( v10 == 0 )
      {
        idLexer::Error(
          this,
          str: "missing trailing quote",
          a3: quote,
          a4,
          a5,
          a6: v26,
          a7: v27,
          a8: v28,
          a9: v29,
          a10: v30,
          a11: v31);
        return 0;
      }
      if ( v10 == 10 )
      {
        idLexer::Error(
          this,
          str: "newline inside string",
          a3: quote,
          a4,
          a5,
          a6: v26,
          a7: v27,
          a8: v28,
          a9: v29,
          a10: v30,
          a11: v31);
        return 0;
      }
      this->script_p = script_p + 1;
      allocedAndFlag = token->allocedAndFlag;
      HIDWORD(v19) = allocedAndFlag >> 31;
      v20 = token->len + 2;
      v22 = allocedAndFlag >> 31 == 0;
      v21 = allocedAndFlag & 0x7FFFFFFF;
      if ( v22 )
      {
        if ( v20 > v21 )
          idStr::ReAllocate(this: token, amount: v20, keepold: true);
      }
      else if ( v20 > v21 )
      {
        HIDWORD(v23) = "amount <= GetAlloced()";
        LODWORD(v23) = 1;
        LODWORD(v19) = token->len;
        if ( (unsigned __int8)AssertFailed(
                                file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                                expression: v23,
                                inlineBreak: SBYTE3(a4),
                                a4: v19) != 0 )
          __trap();
      }
      token->data[token->len] = v10;
      HIDWORD(a5) = token->len + 1;
      token->len = HIDWORD(a5);
    }
    v11 = script_p + 1;
    flags = this->flags;
    this->script_p = v11;
    if ( (flags & 0x10) != 0 && ((flags & 0x4000) == 0 || v7 != 34) )
      goto LABEL_32;
    line = this->line;
    LODWORD(a5) = flags & 0x10;
    if ( (unsigned __int8)idLexer::SkipWhiteSpace(this, currentLine: false, a3: quote, a4, a5) == 0 )
      break;
    if ( (this->flags & 0x10) != 0 )
    {
      v15 = this->script_p;
      LODWORD(v14) = *(unsigned __int8 *)v15;
      if ( (_DWORD)v14 != 92 )
        break;
      this->script_p = v15 + 1;
      LODWORD(v16) = (unsigned __int8)idLexer::SkipWhiteSpace(this, currentLine: false, a3: quote, a4, a5: v14);
      if ( (_DWORD)v16 == 0
        || (LODWORD(v16) = *(unsigned __int8 *)this->script_p, HIDWORD(v16) = (char)v16, (char)v16 != v7) )
      {
        idLexer::Error(
          this,
          str: "expecting string after '' terminated line",
          a3: quote,
          a4,
          a5: v16,
          a6: v26,
          a7: v27,
          a8: v28,
          a9: v29,
          a10: v30,
          a11: v31);
        return 0;
      }
    }
    v17 = this->script_p;
    HIDWORD(a5) = *v17;
    if ( HIDWORD(a5) != v7 )
      break;
    this->script_p = v17 + 1;
  }
  this->script_p = v11;
  this->line = line;
LABEL_32:
  HIDWORD(v25) = token->data;
  *(_BYTE *)(token->len + HIDWORD(v25)) = 0;
  LODWORD(a4) = token->type;
  if ( (_DWORD)a4 == 2 )
  {
    LODWORD(v25) = this->flags & 0x2000;
    if ( (_DWORD)v25 == 0 && token->len != 1 )
      idLexer::Warning(
        this,
        str: "literal is not one character long",
        a3: quote,
        a4,
        a5: v25,
        a6: v26,
        a7: v27,
        a8: v28,
        a9: v29,
        a10: v30,
        a11: v31);
    token->subtype = *token->data;
    return 1;
  }
  else
  {
    token->subtype = token->len;
    return 1;
  }
}


// ========================================================================
// ?ReadToken@idLexer@@QAA_NAAVidToken@@@Z
// EA  : 0x82F8A288
// RVA : 0x00F8A288
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idLexer::ReadToken(idLexer *this, idToken *token, __int64 a3, __int64 a4, __int64 a5)
{
  idLexer *v5; // r3
  idLexer *v6; // r31
  const char *v8; // r3
  const char *script_p; // r11
  __int64 v10; // r10
  const char *v11; // r11
  __int64 v12; // r8
  __int64 v13; // r10
  __int64 v14; // r6
  char v15; // r4
  int v16; // r29
  int v18; // r11
  char v19; // r10
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  int v23; // [sp+8h] [-88h]
  int v24; // [sp+Ch] [-84h]
  int v25; // [sp+10h] [-80h]
  int v26; // [sp+14h] [-7Ch]
  int v27; // [sp+18h] [-78h]
  int v28; // [sp+1Ch] [-74h]

  v6 = v5;
  if ( !v5->loaded )
  {
    v8 = "ReadToken: no file loaded";
    idLib::Error(fmt: *(__int64 *)&token, a2: a3, a3: a4, a4: a5, a5: v23, a6: v24, a7: v25, a8: v26);
  }
  script_p = v6->script_p;
  if ( script_p == v6->end_p )
    return 0;
  LODWORD(v10) = v6->line;
  v6->lastScript_p = script_p;
  v6->lastline = v10;
  HIDWORD(v10) = token->data;
  *(_BYTE *)HIDWORD(v10) = 0;
  token->len = 0;
  LODWORD(a4) = v6->script_p;
  v6->whiteSpaceStart_p = (const char *)a4;
  token->whiteSpaceStart_p = (const char *)a4;
  if ( (unsigned __int8)idLexer::SkipWhiteSpace(this: v6, currentLine: false, a3, a4, a5: v10) == 0 )
    return 0;
  v11 = v6->script_p;
  if ( v11 == v6->end_p )
    return 0;
  v6->whiteSpaceEnd_p = v11;
  token->whiteSpaceEnd_p = v11;
  token->line = v6->line;
  LODWORD(v12) = v6->line;
  HIDWORD(v12) = v6->lastline;
  token->floatvalue = 0.0;
  LODWORD(v14) = v12 - HIDWORD(v12);
  token->flags = 0;
  token->linesCrossed = v12 - HIDWORD(v12);
  HIDWORD(v13) = v6->script_p;
  LODWORD(v13) = v6->flags;
  HIDWORD(v14) = v13 & 0x8000;
  v15 = *(_BYTE *)HIDWORD(v13);
  v16 = (char)*(_BYTE *)HIDWORD(v13);
  if ( (v13 & 0x8000) != 0 )
  {
    if ( v15 == 34 || v15 == 39 )
      goto LABEL_9;
    return (unsigned __int8)idLexer::ReadName(this: v6, token, a3: SHIDWORD(v14), a4: v14, a5: SBYTE3(v12)) != 0;
  }
  if ( v15 >= 48 && v15 <= 57 || v15 == 46 && (v18 = *(char *)(HIDWORD(v13) + 1)) >= 48 && v18 <= 57 )
  {
    if ( (unsigned __int8)idLexer::ReadNumber(this: v6, token, a3: v14, a4: v12, a5: v13) == 0 )
      return 0;
    if ( (v6->flags & 0x400) == 0 )
      return 1;
    v19 = *v6->script_p;
    if ( (v19 < 97 || v19 > 122) && (v19 < 65 || v19 > 90) && v19 != 95 )
      return 1;
    return (unsigned __int8)idLexer::ReadName(this: v6, token, a3: SHIDWORD(v14), a4: v14, a5: SBYTE3(v12)) != 0;
  }
  if ( (v13 & 0x100000) != 0 && v15 == 42 )
    return (unsigned __int8)idLexer::ReadName(this: v6, token, a3: SHIDWORD(v14), a4: v14, a5: SBYTE3(v12)) != 0;
  if ( (v13 & 0x80000) == 0 && (v15 == 34 || v15 == 39) )
  {
LABEL_9:
    HIDWORD(v14) = v15;
    return (unsigned __int8)idLexer::ReadString(this: v6, token, quote: v14, a4: v12, a5: v13) != 0;
  }
  if ( v15 >= 97 && v15 <= 122 || v15 >= 65 && v15 <= 90 || v15 == 95 || (v13 & 0x200) != 0 && v15 == 46 )
    return (unsigned __int8)idLexer::ReadName(this: v6, token, a3: SHIDWORD(v14), a4: v14, a5: SBYTE3(v12)) != 0;
  if ( (v13 & 0x20000) != 0 && v15 == 60 && *(_BYTE *)(HIDWORD(v13) + 1) == 37 )
  {
    if ( (unsigned __int8)idLexer::ReadRawStringBlock(this: v6, token, a3: v14, a4: v12, a5: v13) == 0 )
      return 0;
  }
  else if ( (unsigned __int8)idLexer::ReadPunctuation(this: v6, token, a3: 0, a4: v14, a5: SBYTE3(v12)) == 0 )
  {
    HIDWORD(v22) = v16;
    idLexer::Error(
      this: v6,
      str: "unknown punctuation %c",
      a3: v22,
      a4: v21,
      a5: v20,
      a6: v23,
      a7: v24,
      a8: v25,
      a9: v26,
      a10: v27,
      a11: v28);
    return 0;
  }
  return 1;
}


// ========================================================================
// ?ExpectTokenString@idLexer@@QAA_NPBD@Z
// EA  : 0x82F8A548
// RVA : 0x00F8A548
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::ExpectTokenString(idLexer *this, const char *string, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  __int64 v7; // r10
  unsigned int v8; // r8
  __int64 v9; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  int v13; // [sp+8h] [-D8h]
  int v14; // [sp+Ch] [-D4h]
  int v15; // [sp+10h] [-D0h]
  int v16; // [sp+14h] [-CCh]
  int v17; // [sp+18h] [-C8h]
  int v18; // [sp+1Ch] [-C4h]
  idToken v19; // [sp+70h] [-70h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v19.baseBuffer;
  v19.len = 0;
  v19.allocedAndFlag = 20;
  v19.floatvalue = -3.4028235e38;
  v19.data = v19.baseBuffer;
  v19.baseBuffer[0] = 0;
  v19.intvalue = 0;
  memset(&v19.whiteSpaceStart_p, 0, 12);
  if ( (unsigned __int8)idLexer::ReadToken(this, token: &v19, a3, a4, a5: v4) != 0 )
  {
    if ( idStr::Cmp(s1: v19.data, s2: string) != 0 )
    {
      idLexer::Error(
        this,
        str: "expected '%s' but found '%s'",
        a3: __SPAIR64__((unsigned int)string, (unsigned int)v19.data),
        a4: v12,
        a5: v11,
        a6: v13,
        a7: v14,
        a8: v15,
        a9: v16,
        a10: v17,
        a11: v18);
      idStr::FreeData(this: &v19);
      return 0;
    }
    else
    {
      idStr::FreeData(this: &v19);
      return 1;
    }
  }
  else
  {
    HIDWORD(v9) = string;
    idLexer::Error(
      this,
      str: "couldn't find expected '%s'",
      a3: v9,
      a4: v8,
      a5: v7,
      a6: v13,
      a7: v14,
      a8: v15,
      a9: v16,
      a10: v17,
      a11: v18);
    idStr::FreeData(this: &v19);
    return 0;
  }
}


// ========================================================================
// __unwind$113672
// EA  : 0x82F8A620
// RVA : 0x00F8A620
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_113672()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?ExpectAnyToken@idLexer@@QAA_NAAVidToken@@@Z
// EA  : 0x82F8A648
// RVA : 0x00F8A648
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::ExpectAnyToken(idLexer *this, idToken *token, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  int v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+10h] [-60h]
  int v13; // [sp+14h] [-5Ch]
  int v14; // [sp+18h] [-58h]
  int v15; // [sp+1Ch] [-54h]

  if ( (unsigned __int8)idLexer::ReadToken(this, token, a3, a4, a5) != 0 )
    return 1;
  idLexer::Error(
    this,
    str: "couldn't read expected token",
    a3: v8,
    a4: v7,
    a5: v6,
    a6: v10,
    a7: v11,
    a8: v12,
    a9: v13,
    a10: v14,
    a11: v15);
  return 0;
}


// ========================================================================
// ?CheckTokenString@idLexer@@QAA_NPBD@Z
// EA  : 0x82F8A6B8
// RVA : 0x00F8A6B8
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::CheckTokenString(idLexer *this, const char *string, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  int lastline; // r10
  idToken v9; // [sp+50h] [-70h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v9.baseBuffer;
  v9.len = 0;
  v9.allocedAndFlag = 20;
  v9.floatvalue = -3.4028235e38;
  v9.data = v9.baseBuffer;
  v9.baseBuffer[0] = 0;
  v9.intvalue = 0;
  memset(&v9.whiteSpaceStart_p, 0, 12);
  if ( (unsigned __int8)idLexer::ReadToken(this, token: &v9, a3, a4, a5: v4) != 0 )
  {
    if ( idStr::Cmp(s1: v9.data, s2: string) == 0 )
    {
      idStr::FreeData(this: &v9);
      return 1;
    }
    lastline = this->lastline;
    this->script_p = this->lastScript_p;
    this->line = lastline;
  }
  idStr::FreeData(this: &v9);
  return 0;
}


// ========================================================================
// __unwind$113773
// EA  : 0x82F8A76C
// RVA : 0x00F8A76C
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_113773()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?CheckTokenType@idLexer@@QAA_NHHAAVidToken@@@Z
// EA  : 0x82F8A7A0
// RVA : 0x00F8A7A0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::CheckTokenType(idLexer *this, int type, __int64 token, __int64 a4)
{
  __int64 v4; // r10
  int v7; // r28
  idToken *v8; // r26
  bool v9; // r11
  int lastline; // r10
  idToken v12; // [sp+50h] [-80h] BYREF

  LODWORD(v4) = 20;
  HIDWORD(v4) = v12.baseBuffer;
  v12.len = 0;
  v12.allocedAndFlag = 20;
  v12.floatvalue = -3.4028235e38;
  v7 = HIDWORD(token);
  v8 = (idToken *)token;
  v12.data = v12.baseBuffer;
  v12.baseBuffer[0] = 0;
  v12.intvalue = 0;
  memset(&v12.whiteSpaceStart_p, 0, 12);
  if ( (unsigned __int8)idLexer::ReadToken(this, token: &v12, a3: token, a4, a5: v4) != 0 )
  {
    if ( v12.type == type )
    {
      v9 = true;
      if ( v12.type == 3 )
      {
        v9 = (v12.subtype & v7) == v7;
      }
      else if ( v12.type == 5 )
      {
        v9 = v7 == v12.subtype;
      }
      if ( v9 )
      {
        idToken::operator=(this: v8, __that: &v12);
        idStr::FreeData(this: &v12);
        return 1;
      }
    }
    lastline = this->lastline;
    this->script_p = this->lastScript_p;
    this->line = lastline;
  }
  idStr::FreeData(this: &v12);
  return 0;
}


// ========================================================================
// __unwind$113863
// EA  : 0x82F8A8AC
// RVA : 0x00F8A8AC
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_113863()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?PeekTokenString@idLexer@@QAA_NPBD@Z
// EA  : 0x82F8A8E0
// RVA : 0x00F8A8E0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::PeekTokenString(idLexer *this, const char *string, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  int lastline; // r10
  char *data; // r3
  idToken v10; // [sp+50h] [-70h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v10.baseBuffer;
  v10.len = 0;
  v10.allocedAndFlag = 20;
  v10.floatvalue = -3.4028235e38;
  v10.data = v10.baseBuffer;
  v10.baseBuffer[0] = 0;
  v10.intvalue = 0;
  memset(&v10.whiteSpaceStart_p, 0, 12);
  if ( (unsigned __int8)idLexer::ReadToken(this, token: &v10, a3, a4, a5: v4) == 0
    || (lastline = this->lastline,
        data = v10.data,
        this->script_p = this->lastScript_p,
        this->line = lastline,
        idStr::Cmp(s1: data, s2: string) != 0) )
  {
    idStr::FreeData(this: &v10);
    return 0;
  }
  else
  {
    idStr::FreeData(this: &v10);
    return 1;
  }
}


// ========================================================================
// __unwind$113950
// EA  : 0x82F8A994
// RVA : 0x00F8A994
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_113950()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?PeekTokenType@idLexer@@QAA_NHHAAVidToken@@@Z
// EA  : 0x82F8A9C8
// RVA : 0x00F8A9C8
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::PeekTokenType(idLexer *this, int type, __int64 token, __int64 a4)
{
  __int64 v4; // r10
  int v7; // r27
  idToken *v8; // r26
  int lastline; // r9
  int v10; // r10
  bool v11; // r11
  idToken v13; // [sp+50h] [-80h] BYREF

  LODWORD(v4) = 20;
  HIDWORD(v4) = v13.baseBuffer;
  v13.len = 0;
  v13.allocedAndFlag = 20;
  v13.floatvalue = -3.4028235e38;
  v7 = HIDWORD(token);
  v8 = (idToken *)token;
  v13.data = v13.baseBuffer;
  v13.baseBuffer[0] = 0;
  v13.intvalue = 0;
  memset(&v13.whiteSpaceStart_p, 0, 12);
  if ( (unsigned __int8)idLexer::ReadToken(this, token: &v13, a3: token, a4, a5: v4) == 0 )
    goto LABEL_9;
  lastline = this->lastline;
  v10 = v13.type;
  this->script_p = this->lastScript_p;
  this->line = lastline;
  if ( v10 != type )
    goto LABEL_9;
  v11 = true;
  if ( v10 == 3 )
  {
    v11 = (v13.subtype & v7) == v7;
  }
  else if ( v10 == 5 )
  {
    v11 = v7 == v13.subtype;
  }
  if ( v11 )
  {
    idToken::operator=(this: v8, __that: &v13);
    idStr::FreeData(this: &v13);
    return 1;
  }
  else
  {
LABEL_9:
    idStr::FreeData(this: &v13);
    return 0;
  }
}


// ========================================================================
// __unwind$114040
// EA  : 0x82F8AAD4
// RVA : 0x00F8AAD4
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_114040()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?SkipUntilString@idLexer@@QAA_NPBD@Z
// EA  : 0x82F8AB08
// RVA : 0x00F8AB08
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::SkipUntilString(idLexer *this, const char *string, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  idToken v11; // [sp+50h] [-70h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v11.baseBuffer;
  v11.len = 0;
  v11.allocedAndFlag = 20;
  v11.floatvalue = -3.4028235e38;
  v11.data = v11.baseBuffer;
  v11.baseBuffer[0] = 0;
  v11.intvalue = 0;
  memset(&v11.whiteSpaceStart_p, 0, 12);
  if ( (unsigned __int8)idLexer::ReadToken(this, token: &v11, a3, a4, a5: v4) != 0 )
  {
    while ( idStr::Cmp(s1: v11.data, s2: string) != 0 )
    {
      if ( (unsigned __int8)idLexer::ReadToken(this, token: &v11, a3: v9, a4: v8, a5: v7) == 0 )
        goto LABEL_4;
    }
    idStr::FreeData(this: &v11);
    return 1;
  }
  else
  {
LABEL_4:
    idStr::FreeData(this: &v11);
    return 0;
  }
}


// ========================================================================
// __unwind$114126
// EA  : 0x82F8ABBC
// RVA : 0x00F8ABBC
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_114126()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?SkipRestOfLine@idLexer@@QAA_NXZ
// EA  : 0x82F8ABF0
// RVA : 0x00F8ABF0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::SkipRestOfLine(idLexer *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  int lastline; // r10
  idToken v11; // [sp+50h] [-60h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v11.baseBuffer;
  v11.len = 0;
  v11.allocedAndFlag = 20;
  v11.data = v11.baseBuffer;
  v11.floatvalue = -3.4028235e38;
  v11.baseBuffer[0] = 0;
  v11.intvalue = 0;
  memset(&v11.whiteSpaceStart_p, 0, 12);
  HIDWORD(v7) = (unsigned __int8)idLexer::ReadToken(this, token: &v11, a3, a4, a5: v4);
  if ( HIDWORD(v7) != 0 )
  {
    while ( v11.linesCrossed == 0 )
    {
      if ( (unsigned __int8)idLexer::ReadToken(this, token: &v11, a3: v8, a4: v7, a5: v6) == 0 )
        goto LABEL_4;
    }
    lastline = this->lastline;
    this->script_p = this->lastScript_p;
    this->line = lastline;
    idStr::FreeData(this: &v11);
    return 1;
  }
  else
  {
LABEL_4:
    idStr::FreeData(this: &v11);
    return 0;
  }
}


// ========================================================================
// __unwind$114203
// EA  : 0x82F8ACC0
// RVA : 0x00F8ACC0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_114203()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?SkipBracedSection@idLexer@@QAA_N_N@Z
// EA  : 0x82F8ACF0
// RVA : 0x00F8ACF0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::SkipBracedSection(idLexer *this, bool parseFirstBrace, __int64 a3)
{
  __int64 v4; // r8
  __int64 v5; // r10
  int v6; // r30
  idToken v8; // [sp+50h] [-80h] BYREF

  HIDWORD(v5) = 20;
  LODWORD(v4) = v8.baseBuffer;
  v8.len = 0;
  v8.allocedAndFlag = 20;
  v8.data = v8.baseBuffer;
  v8.floatvalue = -3.4028235e38;
  v8.baseBuffer[0] = 0;
  v8.intvalue = 0;
  memset(&v8.whiteSpaceStart_p, 0, 12);
  HIDWORD(v4) = parseFirstBrace;
  LODWORD(a3) = _cntlzw(parseFirstBrace);
  LODWORD(v5) = byte_821B0000;
  v6 = (a3 & 0x20) != 0;
  while ( (unsigned __int8)idLexer::ReadToken(this, token: &v8, a3, a4: v4, a5: v5) != 0 )
  {
    if ( v8.type == 5 )
    {
      if ( idStr::Cmp(s1: v8.data, s2: "{") != 0 )
      {
        if ( idStr::Cmp(s1: v8.data, s2: "}") == 0 )
          --v6;
      }
      else
      {
        ++v6;
      }
    }
    if ( v6 == 0 )
    {
      idStr::FreeData(this: &v8);
      return 1;
    }
  }
  idStr::FreeData(this: &v8);
  return 0;
}


// ========================================================================
// __unwind$114280
// EA  : 0x82F8ADDC
// RVA : 0x00F8ADDC
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_114280()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?ReadTokenOnLine@idLexer@@QAA_NAAVidToken@@@Z
// EA  : 0x82F8AE10
// RVA : 0x00F8AE10
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::ReadTokenOnLine(idLexer *this, idToken *token, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  int v7; // r10
  int lastline; // r10
  idToken v10; // [sp+50h] [-70h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v10.baseBuffer;
  v10.len = 0;
  v10.allocedAndFlag = 20;
  v10.floatvalue = -3.4028235e38;
  v10.data = v10.baseBuffer;
  v10.baseBuffer[0] = 0;
  v10.intvalue = 0;
  memset(&v10.whiteSpaceStart_p, 0, 12);
  if ( (unsigned __int8)idLexer::ReadToken(this, token: &v10, a3, a4, a5: v4) != 0 )
  {
    if ( v10.linesCrossed == 0 )
    {
      idToken::operator=(this: token, __that: &v10);
      idStr::FreeData(this: &v10);
      return 1;
    }
    lastline = this->lastline;
    this->script_p = this->lastScript_p;
    this->line = lastline;
    idStr::Clear(this: token);
  }
  else
  {
    v7 = this->lastline;
    this->script_p = this->lastScript_p;
    this->line = v7;
  }
  idStr::FreeData(this: &v10);
  return 0;
}


// ========================================================================
// __unwind$114362
// EA  : 0x82F8AED8
// RVA : 0x00F8AED8
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_114362()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?ParseUnsignedInt@idLexer@@QAAIXZ
// EA  : 0x82F8AF08
// RVA : 0x00F8AF08
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

unsigned int __fastcall idLexer::ParseUnsignedInt(idLexer *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  unsigned int UnsignedIntValue; // r30
  int v11; // [sp+8h] [-C8h]
  int v12; // [sp+Ch] [-C4h]
  int v13; // [sp+10h] [-C0h]
  int v14; // [sp+14h] [-BCh]
  int v15; // [sp+18h] [-B8h]
  int v16; // [sp+1Ch] [-B4h]
  idToken v17; // [sp+70h] [-60h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v17.baseBuffer;
  v17.len = 0;
  v17.allocedAndFlag = 20;
  v17.data = v17.baseBuffer;
  v17.floatvalue = -3.4028235e38;
  v17.baseBuffer[0] = 0;
  v17.intvalue = 0;
  memset(&v17.whiteSpaceStart_p, 0, 12);
  HIDWORD(v7) = (unsigned __int8)idLexer::ReadToken(this, token: &v17, a3, a4, a5: v4);
  if ( HIDWORD(v7) != 0 )
  {
    if ( v17.type == 5 && idStr::Cmp(s1: v17.data, s2: "-") == 0 )
      idLexer::Error(
        this,
        str: "expected unsigned integer value, found '-'",
        a3: v8,
        a4: v7,
        a5: v6,
        a6: v11,
        a7: v12,
        a8: v13,
        a9: v14,
        a10: v15,
        a11: v16);
    if ( v17.type != 3 || v17.subtype == 128 )
    {
      HIDWORD(v8) = v17.data;
      idLexer::Error(
        this,
        str: "expected unsigned integer value, found '%s'",
        a3: v8,
        a4: v7,
        a5: v6,
        a6: v11,
        a7: v12,
        a8: v13,
        a9: v14,
        a10: v15,
        a11: v16);
    }
    UnsignedIntValue = idToken::GetUnsignedIntValue(this: &v17);
    idStr::FreeData(this: &v17);
    return UnsignedIntValue;
  }
  else
  {
    idLexer::Error(
      this,
      str: "couldn't read expected unsigned integer",
      a3: v8,
      a4: (unsigned int)v7,
      a5: v6,
      a6: v11,
      a7: v12,
      a8: v13,
      a9: v14,
      a10: v15,
      a11: v16);
    idStr::FreeData(this: &v17);
    return 0;
  }
}


// ========================================================================
// __unwind$114453
// EA  : 0x82F8B020
// RVA : 0x00F8B020
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_114453()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?ParseBool@idLexer@@QAA_NXZ
// EA  : 0x82F8B050
// RVA : 0x00F8B050
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::ParseBool(idLexer *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  BOOL v9; // r30
  int v11; // [sp+8h] [-B8h]
  int v12; // [sp+Ch] [-B4h]
  int v13; // [sp+10h] [-B0h]
  int v14; // [sp+14h] [-ACh]
  int v15; // [sp+18h] [-A8h]
  int v16; // [sp+1Ch] [-A4h]
  idToken v17; // [sp+60h] [-60h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v17.baseBuffer;
  v17.len = 0;
  v17.allocedAndFlag = 20;
  v17.data = v17.baseBuffer;
  v17.floatvalue = -3.4028235e38;
  v17.baseBuffer[0] = 0;
  v17.intvalue = 0;
  memset(&v17.whiteSpaceStart_p, 0, 12);
  HIDWORD(v7) = (unsigned __int8)idLexer::ReadToken(this, token: &v17, a3, a4, a5: v4);
  if ( HIDWORD(v7) == 0 )
    goto LABEL_8;
  if ( v17.type == 3 )
  {
    v9 = idToken::GetUnsignedIntValue(this: &v17) != 0;
    idStr::FreeData(this: &v17);
    return v9;
  }
  if ( v17.type != 4 )
  {
LABEL_8:
    idLexer::Error(
      this,
      str: "couldn't read expected boolean",
      a3: v8,
      a4: v7,
      a5: v6,
      a6: v11,
      a7: v12,
      a8: v13,
      a9: v14,
      a10: v15,
      a11: v16);
    goto LABEL_9;
  }
  if ( idStr::Cmp(s1: v17.data, s2: "false") != 0 )
  {
    if ( idStr::Cmp(s1: v17.data, s2: "true") == 0 )
    {
      idStr::FreeData(this: &v17);
      return 1;
    }
    goto LABEL_8;
  }
LABEL_9:
  idStr::FreeData(this: &v17);
  return 0;
}


// ========================================================================
// __unwind$114535
// EA  : 0x82F8B164
// RVA : 0x00F8B164
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_114535()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?GetNextWhiteSpace@idLexer@@QAAHAAVidStr@@_N@Z
// EA  : 0x82F8B190
// RVA : 0x00F8B190
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::GetNextWhiteSpace(
        idLexer *this,
        idStr *whiteSpace,
        __int64 currentLine,
        __int64 a4,
        __int64 a5)
{
  this->whiteSpaceStart_p = this->script_p;
  idLexer::SkipWhiteSpace(this, currentLine: SBYTE3(currentLine), a3: currentLine, a4, a5);
  this->whiteSpaceEnd_p = this->script_p;
  return idLexer::GetLastWhiteSpace(this, whiteSpace);
}


// ========================================================================
// ?ExpectTokenType@idLexer@@QAA_NHHAAVidToken@@@Z
// EA  : 0x82F8B1F0
// RVA : 0x00F8B1F0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::ExpectTokenType(idLexer *this, int type, __int64 token, __int64 a4)
{
  __int64 v4; // r10
  int v7; // r30
  _DWORD *v8; // r28
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
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

  LODWORD(v4) = 20;
  HIDWORD(v4) = v30[0].baseBuffer;
  v30[0].len = 0;
  v30[0].allocedAndFlag = 20;
  v30[0].data = v30[0].baseBuffer;
  v7 = HIDWORD(token);
  v30[0].baseBuffer[0] = 0;
  v8 = (_DWORD *)token;
  LODWORD(v10) = (unsigned __int8)idLexer::ReadToken(this, (idToken *)token, a3: token, a4, a5: v4);
  if ( (_DWORD)v10 == 0 )
  {
    idLexer::Error(
      this,
      str: "couldn't read expected token",
      a3: v11,
      a4: v10,
      a5: v9,
      a6: v24,
      a7: v25,
      a8: v26,
      a9: v27,
      a10: v28,
      a11: v29);
    idStr::FreeData(this: v30);
    return 0;
  }
  v13 = v8[8];
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
    LODWORD(v15) = v8[1];
    HIDWORD(v15) = v30[0].data;
    idLexer::Error(
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
      if ( v7 < 0 )
      {
        idLexer::Error(
          this,
          str: "BUG: wrong punctuation subtype",
          a3: v11,
          a4: v10,
          a5: v9,
          a6: v24,
          a7: v25,
          a8: v26,
          a9: v27,
          a10: v28,
          a11: v29);
        idStr::FreeData(this: v30);
        return 0;
      }
      if ( v8[9] != v7 )
      {
        HIDWORD(v21) = idLexer::GetPunctuationFromId(this, id: v7);
        idLexer::Error(
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
  else if ( (v8[9] & v7) != v7 )
  {
    idStr::Clear(this: v30);
    if ( (v7 & 2) != 0 )
      idStr::operator=(this: v30, text: "decimal ");
    if ( (v7 & 4) != 0 )
      idStr::operator=(this: v30, text: "hex ");
    if ( (v7 & 8) != 0 )
      idStr::operator=(this: v30, text: "octal ");
    if ( (v7 & 0x10) != 0 )
      idStr::operator=(this: v30, text: "binary ");
    if ( (v7 & 0x40) != 0 )
      idStr::Append(this: v30, text: "unsigned ");
    if ( (v7 & 0x20) != 0 )
      idStr::Append(this: v30, text: "long ");
    if ( (v7 & 0x80) != 0 )
      idStr::Append(this: v30, text: "float ");
    if ( (v7 & 1) != 0 )
      idStr::Append(this: v30, text: "integer ");
    idStr::StripTrailing(this: v30, c: 32);
    HIDWORD(v18) = v30[0].data;
    LODWORD(v18) = v8[1];
    idLexer::Error(
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
// __unwind$114670
// EA  : 0x82F8B4C0
// RVA : 0x00F8B4C0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_114670()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// ?ParseInt@idLexer@@QAAHXZ
// EA  : 0x82F8B4F0
// RVA : 0x00F8B4F0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

unsigned int __fastcall idLexer::ParseInt(idLexer *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  __int64 v10; // r6
  unsigned int UnsignedIntValue; // r30
  int v12; // [sp+8h] [-C8h]
  int v13; // [sp+Ch] [-C4h]
  int v14; // [sp+10h] [-C0h]
  int v15; // [sp+14h] [-BCh]
  int v16; // [sp+18h] [-B8h]
  int v17; // [sp+1Ch] [-B4h]
  idToken v18; // [sp+70h] [-60h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v18.baseBuffer;
  v18.len = 0;
  v18.allocedAndFlag = 20;
  v18.data = v18.baseBuffer;
  v18.floatvalue = -3.4028235e38;
  v18.baseBuffer[0] = 0;
  v18.intvalue = 0;
  memset(&v18.whiteSpaceStart_p, 0, 12);
  HIDWORD(v7) = (unsigned __int8)idLexer::ReadToken(this, token: &v18, a3, a4, a5: v4);
  if ( HIDWORD(v7) != 0 )
  {
    if ( v18.type != 5 || idStr::Cmp(s1: v18.data, s2: "-") != 0 )
    {
      if ( v18.type != 3 || v18.subtype == 128 )
      {
        HIDWORD(v8) = v18.data;
        idLexer::Error(
          this,
          str: "expected integer value, found '%s'",
          a3: v8,
          a4: v7,
          a5: v6,
          a6: v12,
          a7: v13,
          a8: v14,
          a9: v15,
          a10: v16,
          a11: v17);
      }
      UnsignedIntValue = idToken::GetUnsignedIntValue(this: &v18);
    }
    else
    {
      LODWORD(v10) = &v18;
      HIDWORD(v10) = 1;
      idLexer::ExpectTokenType(this, type: 3, token: v10, a4: v7);
      UnsignedIntValue = -idToken::GetUnsignedIntValue(this: &v18);
    }
    idStr::FreeData(this: &v18);
    return UnsignedIntValue;
  }
  else
  {
    idLexer::Error(
      this,
      str: "couldn't read expected integer",
      a3: v8,
      a4: (unsigned int)v7,
      a5: v6,
      a6: v12,
      a7: v13,
      a8: v14,
      a9: v15,
      a10: v16,
      a11: v17);
    idStr::FreeData(this: &v18);
    return 0;
  }
}


// ========================================================================
// __unwind$114775
// EA  : 0x82F8B61C
// RVA : 0x00F8B61C
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_114775()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?ParseFloat@idLexer@@QAAMPA_N@Z
// EA  : 0x82F8B650
// RVA : 0x00F8B650
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

float __fastcall idLexer::ParseFloat(idLexer *this, bool *errorFlag, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  double v10; // fp1
  double FloatValue; // fp31
  int v13; // [sp+8h] [-D8h]
  int v14; // [sp+Ch] [-D4h]
  int v15; // [sp+10h] [-D0h]
  int v16; // [sp+14h] [-CCh]
  int v17; // [sp+18h] [-C8h]
  int v18; // [sp+1Ch] [-C4h]
  idToken v19; // [sp+70h] [-70h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v19.baseBuffer;
  v19.len = 0;
  v19.allocedAndFlag = 20;
  v19.floatvalue = -3.4028235e38;
  v19.data = v19.baseBuffer;
  v19.baseBuffer[0] = 0;
  v19.intvalue = 0;
  memset(&v19.whiteSpaceStart_p, 0, 12);
  if ( errorFlag != nullptr )
    *errorFlag = false;
  if ( (unsigned __int8)idLexer::ReadToken(this, token: &v19, a3, a4, a5: v4) != 0 )
  {
    if ( v19.type != 5 || idStr::Cmp(s1: v19.data, s2: "-") != 0 )
    {
      if ( v19.type != 3 )
      {
        HIDWORD(v9) = v19.data;
        if ( errorFlag != nullptr )
        {
          idLexer::Warning(
            this,
            str: "expected float value, found '%s'",
            a3: v9,
            a4: v8,
            a5: v7,
            a6: v13,
            a7: v14,
            a8: v15,
            a9: v16,
            a10: v17,
            a11: v18);
          *errorFlag = true;
        }
        else
        {
          idLexer::Error(
            this,
            str: "expected float value, found '%s'",
            a3: v9,
            a4: v8,
            a5: v7,
            a6: v13,
            a7: v14,
            a8: v15,
            a9: v16,
            a10: v17,
            a11: v18);
        }
      }
      FloatValue = idToken::GetFloatValue(this: &v19);
    }
    else
    {
      idLexer::ExpectTokenType(this, type: 3, token: (unsigned int)&v19, a4: v8);
      FloatValue = -idToken::GetFloatValue(this: &v19);
    }
    idStr::FreeData(this: &v19);
    v10 = FloatValue;
  }
  else
  {
    if ( errorFlag != nullptr )
    {
      idLexer::Warning(
        this,
        str: "couldn't read expected floating point number",
        a3: v9,
        a4: v8,
        a5: v7,
        a6: v13,
        a7: v14,
        a8: v15,
        a9: v16,
        a10: v17,
        a11: v18);
      *errorFlag = true;
    }
    else
    {
      idLexer::Error(
        this,
        str: "couldn't read expected floating point number",
        a3: v9,
        a4: v8,
        a5: v7,
        a6: v13,
        a7: v14,
        a8: v15,
        a9: v16,
        a10: v17,
        a11: v18);
    }
    idStr::FreeData(this: &v19);
    v10 = 0.0;
  }
  return *((float *)&v10 + 1);
}


// ========================================================================
// __unwind$114868
// EA  : 0x82F8B7B8
// RVA : 0x00F8B7B8
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_114868()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?Parse1DMatrix@idLexer@@QAA_NHPAM_N@Z
// EA  : 0x82F8B7E0
// RVA : 0x00F8B7E0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

BOOL __fastcall idLexer::Parse1DMatrix(idLexer *this, int x, __int64 expectCommas, __int64 a4)
{
  float *v6; // r31
  char v7; // r29
  __int64 v8; // r8
  __int64 v9; // r6
  int v11; // r30

  v6 = (float *)HIDWORD(expectCommas);
  v7 = expectCommas;
  if ( (unsigned __int8)idLexer::ExpectTokenString(this, string: "(", a3: expectCommas, a4) == 0 )
    return false;
  v11 = 0;
  if ( x > 0 )
  {
    while ( 1 )
    {
      *v6 = idLexer::ParseFloat(this, errorFlag: nullptr, a3: v9, a4: v8);
      if ( v7 != 0
        && v11 != x - 1
        && (unsigned __int8)idLexer::ExpectTokenString(this, string: ",", a3: v9, a4: v8) == 0 )
      {
        break;
      }
      ++v11;
      ++v6;
      if ( v11 >= x )
        return (unsigned __int8)idLexer::ExpectTokenString(this, string: ")", a3: v9, a4: v8) != 0;
    }
    return false;
  }
  return (unsigned __int8)idLexer::ExpectTokenString(this, string: ")", a3: v9, a4: v8) != 0;
}


// ========================================================================
// ?Parse2DMatrix@idLexer@@QAA_NHHPAM@Z
// EA  : 0x82F8B8A8
// RVA : 0x00F8B8A8
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

BOOL __fastcall idLexer::Parse2DMatrix(idLexer *this, int y, __int64 m, __int64 a4)
{
  int v6; // r27
  int v7; // r31
  __int64 v8; // r8
  __int64 v9; // r6
  int v11; // r30
  __int64 v12; // r6

  v6 = HIDWORD(m);
  v7 = m;
  if ( (unsigned __int8)idLexer::ExpectTokenString(this, string: "(", a3: m, a4) == 0 )
    return false;
  v11 = 0;
  if ( y > 0 )
  {
    while ( 1 )
    {
      LODWORD(v12) = 0;
      HIDWORD(v12) = v7;
      if ( !idLexer::Parse1DMatrix(this, x: v6, expectCommas: v12, a4: v8) )
        break;
      ++v11;
      v7 += 4 * v6;
      if ( v11 >= y )
        return (unsigned __int8)idLexer::ExpectTokenString(this, string: ")", a3: v9, a4: v8) != 0;
    }
    return false;
  }
  return (unsigned __int8)idLexer::ExpectTokenString(this, string: ")", a3: v9, a4: v8) != 0;
}


// ========================================================================
// ?ParseBracedSectionExact@idLexer@@QAA_NAAVidStr@@_NDD@Z
// EA  : 0x82F8B958
// RVA : 0x00F8B958
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

int __fastcall idLexer::ParseBracedSectionExact(
        idLexer *this,
        idStr *out,
        bool parseFirstBrace,
        char intro,
        char outro)
{
  __int64 v10; // r8
  __int64 v11; // r6
  __int64 v12; // r10
  int v13; // r24
  const idStr *v14; // r3
  idStr *v15; // r3
  const idStr *v16; // r3
  idStr *v17; // r3
  char v19[16]; // [sp+50h] [-160h] BYREF
  idToken v20; // [sp+60h] [-150h] BYREF
  idStr v21; // [sp+B0h] [-100h] BYREF
  idStr v22; // [sp+D0h] [-E0h] BYREF
  idStr v23; // [sp+F0h] [-C0h] BYREF
  idStr v24; // [sp+110h] [-A0h] BYREF
  idStr v25; // [sp+130h] [-80h] BYREF

  idStr::EnsureAlloced(this: out, amount: 1, keepold: true, geometricGrowth: false);
  *out->data = 0;
  v19[1] = 0;
  out->len = 0;
  v19[0] = intro;
  if ( parseFirstBrace )
  {
    if ( (unsigned __int8)idLexer::ExpectTokenString(this, string: v19, a3: v11, a4: v10) == 0 )
      return 0;
    idStr::operator=(this: out, text: v19);
  }
  HIDWORD(v12) = byte_821B0000;
  LODWORD(v12) = "rmState::parmStack_t::parmBlockStack_t";
  v13 = 1;
  while ( 1 )
  {
    v20.floatvalue = -3.4028235e38;
    v20.allocedAndFlag = 20;
    v20.data = v20.baseBuffer;
    v20.len = 0;
    v20.baseBuffer[0] = 0;
    v20.intvalue = 0;
    memset(&v20.whiteSpaceStart_p, 0, 12);
    if ( (unsigned __int8)idLexer::ReadToken(this, token: &v20, a3: v11, a4: v10, a5: v12) == 0 )
      break;
    v21.allocedAndFlag = 20;
    v21.len = 0;
    v21.data = v21.baseBuffer;
    v21.baseBuffer[0] = 0;
    idLexer::GetWhiteSpaceBeforeToken(this, token: &v20, whiteSpace: &v21);
    idStr::Append(this: out, text: &v21);
    if ( v20.type == 1 )
    {
      v14 = operator+(result: &v22, a: "\"", b: &v20);
      v15 = operator+(result: &v25, a: v14, b: "\"");
      idStr::Append(this: out, text: v15);
      idStr::FreeData(this: &v25);
      idStr::FreeData(this: &v22);
    }
    else if ( v20.type == 2 )
    {
      v16 = operator+(result: &v23, a: "'", b: &v20);
      v17 = operator+(result: &v24, a: v16, b: "'");
      idStr::Append(this: out, text: v17);
      idStr::FreeData(this: &v24);
      idStr::FreeData(this: &v23);
    }
    else
    {
      idStr::Append(this: out, text: &v20);
    }
    if ( v20.type != 1 )
    {
      if ( *v20.data == intro )
      {
        ++v13;
      }
      else if ( *v20.data == outro )
      {
        --v13;
      }
    }
    idStr::FreeData(this: &v21);
    idStr::FreeData(this: &v20);
    if ( v13 <= 0 )
      return 1;
  }
  idStr::FreeData(this: &v20);
  return 0;
}


// ========================================================================
// __unwind$115231
// EA  : 0x82F8BB80
// RVA : 0x00F8BB80
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_115231()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 96));
}


// ========================================================================
// __unwind$115232
// EA  : 0x82F8BBA8
// RVA : 0x00F8BBA8
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_115232()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 176));
}


// ========================================================================
// __unwind$115233
// EA  : 0x82F8BBD0
// RVA : 0x00F8BBD0
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_115233()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 208));
}


// ========================================================================
// __unwind$115234
// EA  : 0x82F8BBF8
// RVA : 0x00F8BBF8
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_115234()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 304));
}


// ========================================================================
// __unwind$115235
// EA  : 0x82F8BC20
// RVA : 0x00F8BC20
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_115235()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 240));
}


// ========================================================================
// __unwind$115236
// EA  : 0x82F8BC48
// RVA : 0x00F8BC48
// PDB : w:\tech5\shared\idlib\text\lexer.cpp
// ========================================================================

void _unwind_115236()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 272));
}

