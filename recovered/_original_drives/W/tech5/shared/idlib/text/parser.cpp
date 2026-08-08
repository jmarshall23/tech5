
// ========================================================================
// ?PC_NameHash@@YAHPBD@Z
// EA  : 0x82F8BC70
// RVA : 0x00F8BC70
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall PC_NameHash(const char *name)
{
  const char *v1; // r11
  int v2; // r9
  int i; // r10
  int v4; // r8
  int v5; // r8

  v1 = name;
  v2 = 0;
  for ( i = *name; *v1 != 0; v2 += v5 )
  {
    v4 = (int)&(v1++)[119 - (_DWORD)name];
    v5 = v4 * i;
    i = *v1;
  }
  return ((((v2 >> 10) ^ v2) >> 10) ^ v2) & 0x7F;
}


// ========================================================================
// ?Error@idParser@@QBAXPBDZZ
// EA  : 0x82F8BCC0
// RVA : 0x00F8BCC0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idParser::Error(
        idParser *this,
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
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  idLexer *scriptstack; // r3
  int v16; // [sp+8h] [-468h]
  int v17; // [sp+Ch] [-464h]
  int v18; // [sp+10h] [-460h]
  int v19; // [sp+14h] [-45Ch]
  int v20; // [sp+18h] [-458h]
  int v21; // [sp+1Ch] [-454h]
  char v22[1024]; // [sp+60h] [-410h] BYREF
  __int64 v23; // [sp+490h] [+20h] BYREF
  va_list va; // [sp+490h] [+20h]
  __int64 v25; // [sp+498h] [+28h]
  __int64 v26; // [sp+4A0h] [+30h]
  __int64 v27; // [sp+4A8h] [+38h]
  __int64 v28; // [sp+4B0h] [+40h]
  __int64 v29; // [sp+4B8h] [+48h]
  va_list va1; // [sp+4C0h] [+50h] BYREF

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
  v23 = *(__int64 *)((char *)&a3 + 4);
  v25 = a3;
  v26 = *(__int64 *)((char *)&a4 + 4);
  v27 = a4;
  v28 = *(__int64 *)((char *)&a5 + 4);
  v29 = a5;
  vsprintf(string: v22, format: str, ap: va);
  scriptstack = this->scriptstack;
  if ( scriptstack != nullptr )
    idLexer::Error(
      this: scriptstack,
      str: v22,
      a3: v14,
      a4: v13,
      a5: v12,
      a6: v16,
      a7: v17,
      a8: v18,
      a9: v19,
      a10: v20,
      a11: v21);
}


// ========================================================================
// ?Warning@idParser@@QBAXPBDZZ
// EA  : 0x82F8BD30
// RVA : 0x00F8BD30
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idParser::Warning(
        idParser *this,
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
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  idLexer *scriptstack; // r3
  int v16; // [sp+8h] [-468h]
  int v17; // [sp+Ch] [-464h]
  int v18; // [sp+10h] [-460h]
  int v19; // [sp+14h] [-45Ch]
  int v20; // [sp+18h] [-458h]
  int v21; // [sp+1Ch] [-454h]
  char v22[1024]; // [sp+60h] [-410h] BYREF
  __int64 v23; // [sp+490h] [+20h] BYREF
  va_list va; // [sp+490h] [+20h]
  __int64 v25; // [sp+498h] [+28h]
  __int64 v26; // [sp+4A0h] [+30h]
  __int64 v27; // [sp+4A8h] [+38h]
  __int64 v28; // [sp+4B0h] [+40h]
  __int64 v29; // [sp+4B8h] [+48h]
  va_list va1; // [sp+4C0h] [+50h] BYREF

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
  v23 = *(__int64 *)((char *)&a3 + 4);
  v25 = a3;
  v26 = *(__int64 *)((char *)&a4 + 4);
  v27 = a4;
  v28 = *(__int64 *)((char *)&a5 + 4);
  v29 = a5;
  vsprintf(string: v22, format: str, ap: va);
  scriptstack = this->scriptstack;
  if ( scriptstack != nullptr )
    idLexer::Warning(
      this: scriptstack,
      str: v22,
      a3: v14,
      a4: v13,
      a5: v12,
      a6: v16,
      a7: v17,
      a8: v18,
      a9: v19,
      a10: v20,
      a11: v21);
}


// ========================================================================
// ?PushDefineScope@idParser@@QAAXXZ
// EA  : 0x82F8BDA0
// RVA : 0x00F8BDA0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void __fastcall idParser::PushDefineScope(idParser *this)
{
  ++this->defineScope;
}


// ========================================================================
// ?PC_OperatorPriority@@YAHH@Z
// EA  : 0x82F8BDB0
// RVA : 0x00F8BDB0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall PC_OperatorPriority(int op)
{
  int result; // r3

  switch ( op )
  {
    case 4:
      result = 7;
      break;
    case 5:
      result = 6;
      break;
    case 6:
    case 7:
    case 38:
    case 39:
      result = 12;
      break;
    case 8:
    case 9:
      result = 11;
      break;
    case 20:
    case 21:
      result = 13;
      break;
    case 27:
    case 28:
    case 29:
      result = 15;
      break;
    case 30:
    case 31:
      result = 14;
      break;
    case 33:
      result = 10;
      break;
    case 34:
      result = 8;
      break;
    case 35:
      result = 9;
      break;
    case 36:
    case 37:
      result = 16;
      break;
    case 42:
    case 43:
      result = 5;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// ========================================================================
// ?GetPunctuationId@idParser@@QAAHPBD@Z
// EA  : 0x82F8BEE8
// RVA : 0x00F8BEE8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::GetPunctuationId(idParser *this, const char *p)
{
  const punctuation_t *punctuations; // r11
  int PunctuationId; // r30
  int v7; // r29
  int v8; // r30
  int v9; // r3
  idLexer v10; // [sp+50h] [-C0h] BYREF

  punctuations = this->punctuations;
  if ( punctuations != nullptr )
  {
    v7 = 0;
    if ( punctuations->p != nullptr )
    {
      v8 = 0;
      while ( 1 )
      {
        v9 = idStr::Cmp(s1: punctuations[v8].p, s2: p);
        punctuations = this->punctuations;
        if ( v9 == 0 )
          break;
        v8 = ++v7;
        if ( punctuations[v7].p == nullptr )
          return 0;
      }
      return punctuations[v8].n;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    idLexer::idLexer(this: &v10, flags_: 0);
    PunctuationId = idLexer::GetPunctuationId(this: &v10, p);
    idLexer::~idLexer(this: &v10);
    return PunctuationId;
  }
}


// ========================================================================
// __unwind$114100
// EA  : 0x82F8BF90
// RVA : 0x00F8BF90
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_114100()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 272 + 80));
}


// ========================================================================
// ?HadError@idParser@@QBA_NXZ
// EA  : 0x82F8BFB8
// RVA : 0x00F8BFB8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

BOOL __fastcall idParser::HadError(idParser *this)
{
  idLexer *scriptstack; // r3

  scriptstack = this->scriptstack;
  if ( scriptstack != nullptr )
    return idLexer::HadError(this: scriptstack) || this->hadError;
  else
    return this->hadError;
}


// ========================================================================
// ?HadWarning@idParser@@QBA_NXZ
// EA  : 0x82F8C018
// RVA : 0x00F8C018
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

BOOL __fastcall idParser::HadWarning(idParser *this)
{
  idLexer *scriptstack; // r3

  scriptstack = this->scriptstack;
  if ( scriptstack != nullptr )
    return idLexer::HadWarning(this: scriptstack) || this->hadWarning;
  else
    return this->hadWarning;
}


// ========================================================================
// ?FindHashedDefine@idParser@@AAAPAUdefine_t@1@PBD@Z
// EA  : 0x82F8C078
// RVA : 0x00F8C078
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

idParser::define_t *__fastcall idParser::FindHashedDefine(idParser *this, const char *name)
{
  idParser::define_t *v3; // r31

  v3 = this->definehash[PC_NameHash(name)];
  if ( v3 == nullptr )
    return nullptr;
  while ( idStr::Cmp(s1: v3->name.data, s2: name) != 0 )
  {
    v3 = v3->hashnext;
    if ( v3 == nullptr )
      return nullptr;
  }
  return v3;
}


// ========================================================================
// ?FindDefineParm@idParser@@AAAHPAUdefine_t@1@PBD@Z
// EA  : 0x82F8C0F8
// RVA : 0x00F8C0F8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::FindDefineParm(idParser *this, idParser::define_t *define, const char *name)
{
  idToken *parms; // r31
  int v5; // r30

  parms = define->parms;
  v5 = 0;
  if ( parms == nullptr )
    return -1;
  while ( idStr::Cmp(s1: parms->data, s2: name) != 0 )
  {
    parms = parms->next;
    ++v5;
    if ( parms == nullptr )
      return -1;
  }
  return v5;
}


// ========================================================================
// ?GetNextWhiteSpace@idParser@@QAAHAAVidStr@@_N@Z
// EA  : 0x82F8C158
// RVA : 0x00F8C158
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::GetNextWhiteSpace(
        idParser *this,
        idStr *whiteSpace,
        __int64 currentLine,
        __int64 a4,
        __int64 a5)
{
  idLexer *scriptstack; // r3

  scriptstack = this->scriptstack;
  if ( scriptstack != nullptr )
    idLexer::GetNextWhiteSpace(this: scriptstack, whiteSpace, currentLine, a4, a5);
  else
    idStr::Clear(this: whiteSpace);
  return whiteSpace->len;
}


// ========================================================================
// ?GetLastWhiteSpace@idParser@@QBAHAAVidStr@@@Z
// EA  : 0x82F8C1A0
// RVA : 0x00F8C1A0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::GetLastWhiteSpace(idParser *this, idStr *whiteSpace)
{
  idLexer *scriptstack; // r3

  scriptstack = this->scriptstack;
  if ( scriptstack != nullptr )
    idLexer::GetLastWhiteSpace(this: scriptstack, whiteSpace);
  else
    idStr::Clear(this: whiteSpace);
  return whiteSpace->len;
}


// ========================================================================
// ?SetFlags@idParser@@QAAXH@Z
// EA  : 0x82F8C1E8
// RVA : 0x00F8C1E8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void __fastcall idParser::SetFlags(idParser *this, int flags)
{
  idLexer *scriptstack; // r11

  scriptstack = this->scriptstack;
  for ( this->flags = flags; scriptstack != nullptr; scriptstack = scriptstack->next )
    scriptstack->flags = flags;
}


// ========================================================================
// ?CopyDefine@idParser@@AAAPAUdefine_t@1@PAU21@@Z
// EA  : 0x82F8C210
// RVA : 0x00F8C210
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

idParser::define_t *__fastcall idParser::CopyDefine(idParser *this, idParser::define_t *define)
{
  idStr *v3; // r3
  idStr *v4; // r27
  size_t len; // r30
  idToken *v6; // r28
  idToken *i; // r29
  idToken *v8; // r3
  idToken *v9; // r30
  idToken *v10; // r28
  idToken *j; // r29
  idToken *v12; // r3
  idToken *v13; // r30

  v3 = (idStr *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                  size: 0x3Cu,
                  tag: TAG_LEXER,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
  {
    v3->allocedAndFlag = 20;
    v3->len = 0;
    v4 = v3;
    v3->data = v3->baseBuffer;
    v3->baseBuffer[0] = 0;
    v3[1].data = nullptr;
    v3[1].allocedAndFlag = 0;
    *(_DWORD *)v3[1].baseBuffer = 0;
    *(_DWORD *)&v3[1].baseBuffer[4] = 0;
    *(_DWORD *)&v3[1].baseBuffer[8] = 0;
    *(_DWORD *)&v3[1].baseBuffer[12] = 0;
  }
  else
  {
    v4 = nullptr;
  }
  len = define->name.len;
  idStr::EnsureAlloced(this: v4, amount: define->name.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v4->data, Src: define->name.data, Size: len);
  v6 = nullptr;
  v4->data[len] = 0;
  v4->len = len;
  v4[1].data = (char *)define->builtin;
  v4[1].allocedAndFlag = define->numparms;
  *(_DWORD *)&v4[1].baseBuffer[8] = 0;
  *(_DWORD *)&v4[1].baseBuffer[12] = 0;
  *(_DWORD *)&v4[1].baseBuffer[4] = 0;
  for ( i = define->tokens; i != nullptr; v6 = v9 )
  {
    v8 = (idToken *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x48u,
                      tag: TAG_LEXER,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
    if ( v8 != nullptr )
    {
      v8->allocedAndFlag = 20;
      v8->len = 0;
      v9 = v8;
      v8->data = v8->baseBuffer;
      v8->baseBuffer[0] = 0;
      v8->floatvalue = -3.4028235e38;
      v8->intvalue = 0;
      v8->whiteSpaceStart_p = nullptr;
      v8->whiteSpaceEnd_p = nullptr;
      v8->next = nullptr;
    }
    else
    {
      v9 = nullptr;
    }
    idToken::operator=(this: v9, __that: i);
    v9->next = nullptr;
    if ( v6 != nullptr )
      v6->next = v9;
    else
      *(_DWORD *)&v4[1].baseBuffer[4] = v9;
    i = i->next;
  }
  *(_DWORD *)v4[1].baseBuffer = 0;
  v10 = nullptr;
  for ( j = define->parms; j != nullptr; v10 = v13 )
  {
    v12 = (idToken *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x48u,
                       tag: TAG_LEXER,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
    if ( v12 != nullptr )
    {
      v12->allocedAndFlag = 20;
      v12->len = 0;
      v13 = v12;
      v12->data = v12->baseBuffer;
      v12->baseBuffer[0] = 0;
      v12->floatvalue = -3.4028235e38;
      v12->intvalue = 0;
      v12->whiteSpaceStart_p = nullptr;
      v12->whiteSpaceEnd_p = nullptr;
      v12->next = nullptr;
    }
    else
    {
      v13 = nullptr;
    }
    idToken::operator=(this: v13, __that: j);
    v13->next = nullptr;
    if ( v10 != nullptr )
      v10->next = v13;
    else
      *(_DWORD *)v4[1].baseBuffer = v13;
    j = j->next;
  }
  return (idParser::define_t *)v4;
}


// ========================================================================
// ?UnreadSourceToken@idParser@@AAA_NABVidToken@@@Z
// EA  : 0x82F8C448
// RVA : 0x00F8C448
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::UnreadSourceToken(idParser *this, const idToken *token)
{
  idToken *v4; // r3
  idToken *v5; // r31

  v4 = (idToken *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                    size: 0x48u,
                    tag: TAG_LEXER,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
  {
    v4->len = 0;
    v4->allocedAndFlag = 20;
    v5 = v4;
    v4->data = v4->baseBuffer;
    v4->baseBuffer[0] = 0;
    v4->floatvalue = -3.4028235e38;
    v4->intvalue = 0;
    v4->whiteSpaceStart_p = nullptr;
    v4->whiteSpaceEnd_p = nullptr;
    v4->next = nullptr;
  }
  else
  {
    v5 = nullptr;
  }
  idToken::operator=(this: v5, __that: token);
  v5->next = this->tokens;
  this->tokens = v5;
  return 1;
}


// ========================================================================
// ?StringizeTokens@idParser@@AAAHPAVidToken@@0@Z
// EA  : 0x82F8C4F8
// RVA : 0x00F8C4F8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::StringizeTokens(idParser *this, idToken *tokens, idToken *token)
{
  idToken *v5; // r27
  char *data; // r30
  int v7; // r11
  int v8; // r29
  char v9; // r10
  int i; // r11
  char *v11; // r11

  token->whiteSpaceStart_p = nullptr;
  token->type = 1;
  token->whiteSpaceEnd_p = nullptr;
  v5 = tokens;
  idStr::operator=(this: token, text: &byte_8200D768);
  if ( tokens != nullptr )
  {
    do
    {
      data = v5->data;
      if ( data != nullptr )
      {
        v7 = 0;
        if ( *data != 0 )
        {
          do
            ++v7;
          while ( data[v7] != 0 );
        }
        v8 = token->len + v7;
        idStr::EnsureAlloced(this: token, amount: v8 + 1, keepold: true, geometricGrowth: true);
        v9 = *data;
        for ( i = 0; v9 != 0; v9 = data[i] )
          token->data[token->len + i++] = v9;
        v11 = token->data;
        token->len = v8;
        v11[v8] = 0;
      }
      v5 = v5->next;
    }
    while ( v5 != nullptr );
  }
  return 1;
}


// ========================================================================
// ?MergeTokens@idParser@@AAAHPAVidToken@@0@Z
// EA  : 0x82F8C5E0
// RVA : 0x00F8C5E0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::MergeTokens(idParser *this, idToken *t1, idToken *t2)
{
  int type; // r10
  int v4; // r11
  int subtype; // r10
  int v7; // r11

  type = t1->type;
  if ( (type != 4 || (v4 = t2->type) != 4 && (v4 != 3 || (t2->subtype & 0x80) != 0)) && (type != 1 || t2->type != 1) )
  {
    if ( type != 3 )
      return 0;
    if ( t2->type != 3 )
      return 0;
    subtype = t1->subtype;
    if ( (subtype & 0x14) != 0 )
      return 0;
    v7 = t2->subtype;
    if ( (v7 & 0x14) != 0 || (subtype & 0x80) != 0 && (v7 & 0x80) != 0 )
      return 0;
  }
  idStr::Append(this: t1, text: t2->data);
  return 1;
}


// ========================================================================
// PreProcessorDate
// EA  : 0x82F8C6C0
// RVA : 0x00F8C6C0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

idStr *__fastcall PreProcessorDate(idStr *result)
{
  __int64 v2; // r3
  char *v3; // r3
  char *v4; // r27
  int v5; // r11
  int v7; // r30
  char v8; // r29
  char len; // r7
  int i; // r30
  char v11; // r29
  int v12; // r11
  __int64 v13; // r10
  __int64 v14; // r6
  bool v15; // r7
  unsigned int allocedAndFlag; // r11
  __int64 v17; // r10
  int v18; // r11
  int v19; // r30
  int v20; // r4
  bool v21; // zf
  __int64 v22; // r6
  char *v23; // r9
  char *v24; // r10
  char v25; // r11
  __int64 v26; // [sp+58h] [-78h] BYREF
  idStr v27[3]; // [sp+60h] [-70h] BYREF

  LODWORD(v2) = (unsigned __int64)time64(timeptr: nullptr) >> 32;
  v26 = v2;
  v3 = ctime64(timp: &v26);
  v4 = v3;
  v5 = 0;
  if ( *v3 == 0 )
    goto LABEL_4;
  do
    ++v5;
  while ( v3[v5] != 0 );
  if ( v5 >= 24 )
  {
    idStr::idStr(this: v27, text: "\"");
    v7 = 4;
    do
    {
      v8 = v4[v7];
      idStr::EnsureAlloced(this: v27, amount: v27[0].len + 2, keepold: true, geometricGrowth: true);
      ++v7;
      v27[0].data[v27[0].len] = v8;
      len = v27[0].len;
      v27[0].data[++v27[0].len] = 0;
    }
    while ( v7 < 10 );
    for ( i = 19; i < 24; ++i )
    {
      v11 = v4[i];
      v12 = v27[0].len + 2;
      LODWORD(v13) = v27[0].allocedAndFlag & 0x7FFFFFFF;
      if ( v27[0].allocedAndFlag >= 0 )
      {
        if ( v12 > (int)v13 )
          idStr::ReAllocate(this: v27, amount: (v12 >> 1) + v12, keepold: true);
      }
      else if ( v12 > (int)v13 )
      {
        HIDWORD(v14) = "amount <= GetAlloced()";
        LODWORD(v14) = 1;
        HIDWORD(v13) = (unsigned int)v27[0].allocedAndFlag >> 31;
        if ( (unsigned __int8)AssertFailed(
                                file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                                expression: v14,
                                inlineBreak: len,
                                a4: v13) != 0 )
          __trap();
      }
      v27[0].data[v27[0].len++] = v11;
      v27[0].data[v27[0].len] = 0;
    }
    idStr::Append(this: v27, text: "\"");
    result->len = 0;
    result->allocedAndFlag = 20;
    result->data = result->baseBuffer;
    result->baseBuffer[0] = 0;
    allocedAndFlag = result->allocedAndFlag;
    HIDWORD(v17) = allocedAndFlag >> 31;
    LODWORD(v17) = v27[0].len;
    v19 = v27[0].len;
    v20 = v27[0].len + 1;
    v21 = allocedAndFlag >> 31 == 0;
    v18 = allocedAndFlag & 0x7FFFFFFF;
    if ( v21 )
    {
      if ( v20 > v18 )
        idStr::ReAllocate(this: result, amount: v20, keepold: true);
    }
    else if ( v20 > v18 )
    {
      HIDWORD(v22) = "amount <= GetAlloced()";
      LODWORD(v22) = 1;
      if ( (unsigned __int8)AssertFailed(
                              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                              expression: v22,
                              inlineBreak: v15,
                              a4: v17) != 0 )
        __trap();
    }
    v23 = result->data - 1;
    v24 = v27[0].data - 1;
    do
    {
      v25 = *++v24;
      *++v23 = *v24;
    }
    while ( v25 != 0 );
    result->len = v19;
    idStr::FreeData(this: v27);
    return result;
  }
  else
  {
LABEL_4:
    idStr::idStr(this: result, text: "*** BAD CURTIME ***");
    return result;
  }
}


// ========================================================================
// __unwind$115476
// EA  : 0x82F8C910
// RVA : 0x00F8C910
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_115476()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 208;
  if ( (*(_DWORD *)(v0 - 208 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 228));
  }
}


// ========================================================================
// __unwind$115479
// EA  : 0x82F8C954
// RVA : 0x00F8C954
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_115479()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// PreProcessorTime
// EA  : 0x82F8C988
// RVA : 0x00F8C988
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

idStr *__fastcall PreProcessorTime(idStr *result)
{
  __int64 v2; // r3
  char *v3; // r3
  char *v4; // r29
  int v5; // r11
  int i; // r30
  char v8; // r25
  __int64 v9; // [sp+58h] [-68h] BYREF
  idStr v10[3]; // [sp+60h] [-60h] BYREF

  LODWORD(v2) = (unsigned __int64)time64(timeptr: nullptr) >> 32;
  v9 = v2;
  v3 = ctime64(timp: &v9);
  v4 = v3;
  v5 = 0;
  if ( *v3 == 0 )
    goto LABEL_4;
  do
    ++v5;
  while ( v3[v5] != 0 );
  if ( v5 >= 24 )
  {
    idStr::idStr(this: v10, text: "\"");
    for ( i = 11; i < 19; ++i )
    {
      v8 = v4[i];
      idStr::EnsureAlloced(this: v10, amount: v10[0].len + 2, keepold: true, geometricGrowth: true);
      v10[0].data[v10[0].len] = v8;
      v10[0].data[++v10[0].len] = 0;
    }
    idStr::Append(this: v10, text: "\"");
    idStr::idStr(this: result, text: v10);
    idStr::FreeData(this: v10);
    return result;
  }
  else
  {
LABEL_4:
    idStr::idStr(this: result, text: "*** BAD CURTIME ***");
    return result;
  }
}


// ========================================================================
// __unwind$115633
// EA  : 0x82F8CA94
// RVA : 0x00F8CA94
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_115633()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 212));
  }
}


// ========================================================================
// __unwind$115636
// EA  : 0x82F8CAD8
// RVA : 0x00F8CAD8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_115636()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?TestPreprocessorMacros_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F8CB08
// RVA : 0x00F8CB08
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void __fastcall TestPreprocessorMacros_f(const idCmdArgs *args)
{
  idStr *v1; // r3
  __int64 v2; // r10
  __int64 v3; // r6
  __int64 v4; // r4
  __int64 v5; // r8
  idStr *v6; // r3
  __int64 v7; // r10
  __int64 v8; // r6
  __int64 v9; // r4
  __int64 v10; // r8
  int v11; // [sp+8h] [-A8h]
  int v12; // [sp+8h] [-A8h]
  int v13; // [sp+Ch] [-A4h]
  int v14; // [sp+Ch] [-A4h]
  int v15; // [sp+10h] [-A0h]
  int v16; // [sp+10h] [-A0h]
  int v17; // [sp+14h] [-9Ch]
  int v18; // [sp+14h] [-9Ch]
  idStr v19; // [sp+50h] [-60h] BYREF
  idStr v20; // [sp+70h] [-40h] BYREF

  v1 = PreProcessorDate(result: &v19);
  LODWORD(v2) = &unk_821C0000;
  HIDWORD(v3) = v1->data;
  LODWORD(v4) = "Aug 29 2012";
  HIDWORD(v4) = "%s : %s\n";
  idLib::Printf(fmt: v4, a2: v3, a3: v5, a4: v2, a5: v11, a6: v13, a7: v15, a8: v17);
  idStr::FreeData(this: &v19);
  v6 = PreProcessorTime(result: &v20);
  HIDWORD(v7) = &unk_82390000;
  HIDWORD(v8) = v6->data;
  HIDWORD(v9) = "%s : %s\n";
  LODWORD(v9) = "10:38:27";
  idLib::Printf(fmt: v9, a2: v8, a3: v10, a4: v7, a5: v12, a6: v14, a7: v16, a8: v18);
  idStr::FreeData(this: &v20);
}


// ========================================================================
// __unwind$115686
// EA  : 0x82F8CB88
// RVA : 0x00F8CB88
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_115686()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$115687
// EA  : 0x82F8CBB0
// RVA : 0x00F8CBB0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_115687()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// ?ExpandBuiltinDefine@idParser@@AAAHPAVidToken@@PAUdefine_t@1@PAPAV2@2@Z
// EA  : 0x82F8CBE0
// RVA : 0x00F8CBE0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::ExpandBuiltinDefine(
        idParser *this,
        idToken *deftoken,
        idParser::define_t *define,
        idToken **firsttoken,
        idToken **lasttoken)
{
  idToken *v10; // r3
  idToken *v11; // r30
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r5
  idLexer *scriptstack; // r11
  const char *data; // r4
  int v18; // r11
  const idStr *v19; // r3
  int len; // r10
  const idStr *v21; // r3
  int v22; // r10
  int v24; // [sp+8h] [-518h]
  int v25; // [sp+Ch] [-514h]
  int v26; // [sp+10h] [-510h]
  int v27; // [sp+14h] [-50Ch]
  int v28; // [sp+18h] [-508h]
  int v29; // [sp+1Ch] [-504h]
  idStr v30; // [sp+90h] [-490h] BYREF
  idStr v31; // [sp+B0h] [-470h] BYREF
  char v32[1104]; // [sp+D0h] [-450h] BYREF

  v10 = (idToken *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                     size: 0x48u,
                     tag: TAG_LEXER,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
  if ( v10 != nullptr )
  {
    v10->len = 0;
    v10->allocedAndFlag = 20;
    v11 = v10;
    v10->data = v10->baseBuffer;
    v10->baseBuffer[0] = 0;
    v10->floatvalue = -3.4028235e38;
    v10->intvalue = 0;
    v10->whiteSpaceStart_p = nullptr;
    v10->whiteSpaceEnd_p = nullptr;
    v10->next = nullptr;
  }
  else
  {
    v11 = nullptr;
  }
  idToken::operator=(this: v11, __that: deftoken);
  if ( (unsigned int)(define->builtin - 1) > 4 )
  {
LABEL_17:
    *firsttoken = nullptr;
    *lasttoken = nullptr;
    if ( v11 != nullptr )
    {
      idStr::FreeData(this: v11);
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    }
    return 1;
  }
  if ( define->builtin != 2 )
  {
    switch ( define->builtin )
    {
      case 3:
        v19 = PreProcessorDate(result: &v30);
        idStr::operator=(this: v11, text: v19);
        idStr::FreeData(this: &v30);
        len = v11->len;
        v11->type = 1;
        v11->subtype = len;
        v11->line = deftoken->line;
        v11->linesCrossed = deftoken->linesCrossed;
        v11->flags = 0;
        *firsttoken = v11;
        *lasttoken = v11;
        return 1;
      case 4:
        v21 = PreProcessorTime(result: &v31);
        idStr::operator=(this: v11, text: v21);
        idStr::FreeData(this: &v31);
        v22 = v11->len;
        v11->type = 1;
        v11->subtype = v22;
        v11->line = deftoken->line;
        v11->linesCrossed = deftoken->linesCrossed;
        v11->flags = 0;
        *firsttoken = v11;
        *lasttoken = v11;
        return 1;
      case 1:
        sprintf_0(string: v32, format: "%d", deftoken->line);
        idStr::operator=(this: v11, text: v32);
        v11->intvalue = deftoken->line;
        LODWORD(v15) = deftoken->line;
        v11->type = 3;
        v11->floatvalue = (float)v15;
        v11->subtype = 65539;
        v11->line = deftoken->line;
        v11->linesCrossed = deftoken->linesCrossed;
        v11->flags = 0;
        *firsttoken = v11;
        *lasttoken = v11;
        return 1;
      default:
        break;
    }
    idParser::Warning(
      this,
      str: "__STDC__ not supported",
      a3: v14,
      a4: v13,
      a5: v12,
      a6: v24,
      a7: v25,
      a8: v26,
      a9: v27,
      a10: v28,
      a11: v29);
    goto LABEL_17;
  }
  scriptstack = this->scriptstack;
  if ( scriptstack != nullptr )
    data = scriptstack->filename.data;
  else
    data = "<NO_SCRIPT>";
  idStr::operator=(this: v11, text: data);
  v18 = v11->len;
  v11->type = 4;
  v11->subtype = v18;
  v11->line = deftoken->line;
  v11->linesCrossed = deftoken->linesCrossed;
  v11->flags = 0;
  *firsttoken = v11;
  *lasttoken = v11;
  return 1;
}


// ========================================================================
// __unwind$115741
// EA  : 0x82F8CE58
// RVA : 0x00F8CE58
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_115741()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1312 + 144));
}


// ========================================================================
// __unwind$115742_0
// EA  : 0x82F8CE80
// RVA : 0x00F8CE80
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_115742_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1312 + 176));
}


// ========================================================================
// ?AddGlobalDefinesToSource@idParser@@AAAXXZ
// EA  : 0x82F8CEA8
// RVA : 0x00F8CEA8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void __fastcall idParser::AddGlobalDefinesToSource(idParser *this)
{
  idParser::define_t *i; // r31
  idParser::define_t *v3; // r3
  char *data; // r10
  int v5; // r11
  int v6; // r9
  int v7; // r7
  int v8; // r8
  int v9; // r11

  for ( i = idParser::globaldefines; i != nullptr; i = i->next )
  {
    v3 = idParser::CopyDefine(this, define: i);
    data = v3->name.data;
    v5 = 0;
    v3->scope = this->defineScope;
    v6 = *data;
    if ( *data != 0 )
    {
      v7 = 119 - (_DWORD)data;
      do
      {
        v8 = (_DWORD)&(data++)[v7] * v6;
        v6 = *data;
        v5 += v8;
      }
      while ( *data != 0 );
    }
    v9 = 4 * ((((((v5 >> 10) ^ v5) >> 10) ^ v5) & 0x7F) + 23);
    v3->hashnext = *(idParser::define_t **)(&this->loaded + v9);
    *(_DWORD *)(&this->loaded + v9) = v3;
  }
}


// ========================================================================
// ?EvaluateTokens@idParser@@AAAHPAVidToken@@PAHPANH@Z
// EA  : 0x82F8CF70
// RVA : 0x00F8CF70
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idParser::EvaluateTokens(
        idParser *this,
        idToken *tokens,
        int *intvalue,
        long double *floatvalue,
        int integer)
{
  int v5; // r29
  int v10; // r19
  int v11; // r24
  int v12; // r26
  int v13; // r20
  _BYTE v14[12]; // r11 OVERLAPPED
  __int64 v15; // r8
  __int64 v16; // r6
  int v17; // r23
  _DWORD *v18; // r22
  _DWORD *v19; // r27
  idToken *v20; // r28
  int *v21; // r21
  _BYTE *v22; // r25
  idParser *v23; // r3
  _BYTE *v24; // r30
  _BYTE *v25; // r30
  int subtype; // r11
  const char *v27; // r4
  int v28; // r3
  int v29; // r26
  double v30; // fp30
  int v31; // r25
  int *v32; // r28
  _BYTE *v33; // r30
  int v34; // r27
  int v35; // r29
  double v36; // fp0
  double v37; // fp0
  signed int v38; // r11
  double v39; // fp0
  signed int v40; // r11
  double v41; // fp0
  double v42; // fp0
  int v43; // r11
  double v44; // fp0
  int v45; // r11
  double v46; // fp0
  int v47; // r11
  double v48; // fp0
  int v49; // r11
  double v50; // fp0
  unsigned int v51; // r11
  double v52; // fp0
  unsigned int v53; // r11
  double v54; // fp0
  int v55; // r11
  int v56; // r11
  int v57; // r11
  int v58; // r11
  const char *v59; // r4
  long double *v60; // r8
  int *i; // r11
  _BYTE *j; // r11
  int v64; // [sp+8h] [-1688h]
  int v65; // [sp+Ch] [-1684h]
  int v66; // [sp+10h] [-1680h]
  int v67; // [sp+14h] [-167Ch]
  int v68; // [sp+18h] [-1678h]
  int v69; // [sp+1Ch] [-1674h]
  int v70; // [sp+80h] [-1610h]
  _BYTE *v71; // [sp+84h] [-160Ch]
  int *v72; // [sp+88h] [-1608h]
  int v73; // [sp+E0h] [-15B0h] BYREF
  _BYTE v74[176]; // [sp+5E0h] [-10B0h] BYREF

  v5 = 0;
  v70 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  `eh vector constructor iterator'(
    ptr: v74,
    size: 0x40u,
    count: 64,
    pCtor: (void (__fastcall *)(void *))idRaceSpectator::spectatorAttachment_t::spectatorAttachment_t,
    pDtor: (void (__fastcall *)(void *))idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels);
  v17 = 0;
  v72 = nullptr;
  v18 = nullptr;
  v71 = nullptr;
  v19 = nullptr;
  if ( intvalue != nullptr )
    *intvalue = 0;
  if ( floatvalue != nullptr )
    *(_QWORD *)floatvalue = 0;
  v20 = tokens;
  if ( tokens == nullptr )
    goto LABEL_80;
  HIDWORD(v15) = byte_821B0000;
  *(_DWORD *)&v14[4] = byte_821B0000;
  *(_DWORD *)v14 = byte_821B0000;
  LODWORD(v15) = &unk_82390000;
  v21 = &v73;
  v22 = v74;
  while ( 1 )
  {
    if ( (unsigned int)(v20->type - 1) > 4 )
    {
LABEL_94:
      HIDWORD(v16) = v20->data;
      idParser::Error(
        this,
        str: "unknown '%s' in #if/#elif",
        a3: v16,
        a4: v15,
        a5: *(__int64 *)v14,
        a6: v64,
        a7: v65,
        a8: v66,
        a9: v67,
        a10: v68,
        a11: v69);
      goto LABEL_99;
    }
    if ( v20->type != 1 )
      break;
    if ( v5 != 0 )
      goto LABEL_85;
    if ( v18 != nullptr && *v18 != 8 && *v18 != 9 )
    {
      v27 = "only == and != are allowed on strings";
      goto LABEL_97;
    }
    if ( v17 >= 64 )
      goto LABEL_87;
    v25 = v22;
    ++v17;
    idStr::operator=(this: (idStr *)(v22 + 4), text: v20);
    *((_DWORD *)v22 + 12) = v11;
    *((_DWORD *)v22 + 13) = v19;
    *(_DWORD *)v22 = 0;
    *((_DWORD *)v22 + 14) = 0;
    v22 += 64;
    if ( v19 == nullptr )
      goto LABEL_38;
    v19[14] = v25;
    v19 = v25;
    v5 = 1;
    v12 = 0;
LABEL_78:
    v20 = v20->next;
    if ( v20 == nullptr )
    {
      if ( v5 != 0 )
      {
        if ( v11 != 0 )
        {
          v27 = "too many ( in #if/#elif";
          goto LABEL_97;
        }
        goto LABEL_100;
      }
LABEL_80:
      v27 = "trailing operator in #if/#elif";
      goto LABEL_97;
    }
  }
  if ( v20->type == 2 )
    goto LABEL_94;
  if ( v20->type == 3 )
  {
    if ( v5 != 0 )
      goto LABEL_85;
    if ( v17 >= 64 )
    {
LABEL_87:
      v27 = "out of value space";
      goto LABEL_97;
    }
    v25 = v22;
    ++v17;
    v22 += 64;
    if ( v12 != 0 )
    {
      *((_DWORD *)v25 + 9) = -idToken::GetUnsignedIntValue(this: v20);
      *((double *)v25 + 5) = -idToken::GetFloatValue(this: v20);
    }
    else
    {
      *((_DWORD *)v25 + 9) = idToken::GetUnsignedIntValue(this: v20);
      *((double *)v25 + 5) = idToken::GetFloatValue(this: v20);
    }
    *(_DWORD *)&v14[8] = v20->subtype;
    *(_QWORD *)v14 = *(_QWORD *)&v14[-4] & 0x100000000LL;
    *((_DWORD *)v25 + 12) = v11;
    *((_DWORD *)v25 + 14) = 0;
    *((_DWORD *)v25 + 13) = v19;
    LODWORD(v15) = _cntlzw(v14[11] & 1);
    HIDWORD(v15) = ((v15 & 0x20) != 0) + 1;
    *(_DWORD *)v25 = HIDWORD(v15);
    if ( v19 != nullptr )
    {
      v19[14] = v25;
      v19 = v25;
      v5 = 1;
      v12 = 0;
      goto LABEL_78;
    }
LABEL_38:
    v71 = v25;
    v19 = v25;
    v5 = 1;
    v12 = 0;
    goto LABEL_78;
  }
  if ( v20->type != 4 )
  {
    if ( v12 != 0 )
    {
      v27 = "misplaced minus sign in #if/#elif";
      goto LABEL_97;
    }
    subtype = v20->subtype;
    if ( subtype == 44 )
    {
      ++v11;
    }
    else if ( subtype == 45 )
    {
      if ( --v11 < 0 )
      {
        v27 = "too many ) in #if/#elif";
        goto LABEL_97;
      }
    }
    else
    {
      *(_DWORD *)&v14[4] = integer;
      if ( integer == 0
        && (subtype == 36
         || subtype == 29
         || subtype == 20
         || subtype == 21
         || subtype == 33
         || subtype == 34
         || subtype == 35) )
      {
        HIDWORD(v16) = v20->data;
        idParser::Error(
          this,
          str: "illegal operator '%s' on floating point operands",
          a3: v16,
          a4: v15,
          a5: *(__int64 *)v14,
          a6: v64,
          a7: v65,
          a8: v66,
          a9: v67,
          a10: v68,
          a11: v69);
        goto LABEL_99;
      }
      if ( v5 != 0 && v19 != nullptr )
      {
        *(_DWORD *)&v14[4] = *v19;
        if ( *v19 == 0 && subtype != 8 && subtype != 9 )
        {
          HIDWORD(v16) = v20->data;
          idParser::Error(
            this,
            str: "illegal operator '%s' on string operands",
            a3: v16,
            a4: v15,
            a5: *(__int64 *)v14,
            a6: v64,
            a7: v65,
            a8: v66,
            a9: v67,
            a10: v68,
            a11: v69);
          goto LABEL_99;
        }
      }
      switch ( subtype )
      {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 20:
        case 21:
        case 27:
        case 28:
        case 29:
        case 30:
        case 33:
        case 34:
        case 35:
        case 38:
        case 39:
        case 42:
        case 43:
          if ( v5 != 0 )
            goto LABEL_72;
          HIDWORD(v16) = v20->data;
          idParser::Error(
            this,
            str: "operator '%s' after operator in #if/#elif",
            a3: v16,
            a4: v15,
            a5: *(__int64 *)v14,
            a6: v64,
            a7: v65,
            a8: v66,
            a9: v67,
            a10: v68,
            a11: v69);
          goto LABEL_99;
        case 15:
        case 16:
          idParser::Error(
            this,
            str: "++ or -- used in #if/#elif",
            a3: v16,
            a4: v15,
            a5: *(__int64 *)v14,
            a6: v64,
            a7: v65,
            a8: v66,
            a9: v67,
            a10: v68,
            a11: v69);
          goto LABEL_72;
        case 31:
          if ( v5 == 0 )
            v12 = 1;
          goto LABEL_72;
        case 36:
        case 37:
          if ( v5 != 0 )
          {
            v27 = "! or ~ after value in #if/#elif";
            goto LABEL_97;
          }
LABEL_72:
          if ( v12 != 0 )
            goto LABEL_78;
          if ( v13 >= 64 )
          {
            v27 = "out of operator space";
            goto LABEL_97;
          }
          ++v13;
          *v21 = v20->subtype;
          v21 += 5;
          v28 = PC_OperatorPriority(op: v20->subtype);
          v5 = 0;
          *(_DWORD *)(*(_DWORD *)&v14[4] + 4) = v28;
          *(_DWORD *)(*(_DWORD *)&v14[4] + 8) = v11;
          *(_DWORD *)(*(_DWORD *)&v14[4] + 16) = 0;
          *(_DWORD *)(*(_DWORD *)&v14[4] + 12) = v18;
          if ( v18 != nullptr )
            v18[4] = *(_DWORD *)&v14[4];
          else
            v72 = *(int **)&v14[4];
          v18 = *(_DWORD **)&v14[4];
          break;
        default:
          HIDWORD(v16) = v20->data;
          idParser::Error(
            this,
            str: "invalid operator '%s' in #if/#elif",
            a3: v16,
            a4: v15,
            a5: *(__int64 *)v14,
            a6: v64,
            a7: v65,
            a8: v66,
            a9: v67,
            a10: v68,
            a11: v69);
          goto LABEL_99;
      }
    }
    goto LABEL_78;
  }
  if ( v5 == 0 && v12 == 0 )
  {
    if ( idStr::Cmp(s1: v20->data, s2: "defined") != 0 )
    {
      HIDWORD(v16) = v20->data;
      idParser::Error(
        this,
        str: "undefined name '%s' in #if/#elif",
        a3: v16,
        a4: v15,
        a5: *(__int64 *)v14,
        a6: v64,
        a7: v65,
        a8: v66,
        a9: v67,
        a10: v68,
        a11: v69);
      goto LABEL_99;
    }
    v20 = v20->next;
    if ( v20 != nullptr )
    {
      if ( idStr::Cmp(s1: v20->data, s2: "(") == 0 )
      {
        v20 = v20->next;
        v10 = 1;
      }
      if ( v20 != nullptr && v20->type == 4 )
      {
        v23 = this;
        if ( v17 >= 64 )
        {
          v27 = "out of value space";
          goto LABEL_98;
        }
        v24 = v22;
        ++v17;
        v22 += 64;
        if ( idParser::FindHashedDefine(this, name: v20->data) != nullptr )
        {
          *((_QWORD *)v24 + 5) = 0x3FF0000000000000LL;
          *((_DWORD *)v24 + 9) = 1;
        }
        else
        {
          *((_QWORD *)v24 + 5) = 0;
          *((_DWORD *)v24 + 9) = 0;
        }
        *((_DWORD *)v24 + 12) = v11;
        *((_DWORD *)v24 + 13) = v19;
        *(_DWORD *)v24 = 1;
        *((_DWORD *)v24 + 14) = 0;
        if ( v19 != nullptr )
          v19[14] = v24;
        else
          v71 = v24;
        v19 = v24;
        if ( v10 != 0 )
        {
          v20 = v20->next;
          if ( v20 == nullptr || idStr::Cmp(s1: v20->data, s2: ")") != 0 )
          {
            idParser::Error(
              this,
              str: "defined missing ) in #if/#elif",
              a3: v16,
              a4: v15,
              a5: *(__int64 *)v14,
              a6: v64,
              a7: v65,
              a8: v66,
              a9: v67,
              a10: v68,
              a11: v69);
            v70 = 1;
            goto LABEL_100;
          }
        }
        v10 = 0;
        v5 = 1;
        goto LABEL_78;
      }
    }
    v27 = "defined() without name in #if/#elif";
    goto LABEL_97;
  }
LABEL_85:
  v27 = "syntax error in #if/#elif";
LABEL_97:
  v23 = this;
LABEL_98:
  idParser::Error(
    this: v23,
    str: v27,
    a3: v16,
    a4: v15,
    a5: *(__int64 *)v14,
    a6: v64,
    a7: v65,
    a8: v66,
    a9: v67,
    a10: v68,
    a11: v69);
LABEL_99:
  v70 = 1;
LABEL_100:
  v29 = 0;
  v30 = 0.0;
  v31 = 0;
  if ( v70 == 0 )
  {
    while ( 1 )
    {
      if ( v72 == nullptr )
        goto LABEL_187;
      v32 = v72;
      v33 = v71;
      *(_DWORD *)&v14[4] = v72 + 4;
      v34 = (int)(v72 + 4);
      *(_DWORD *)&v14[8] = v72[4];
      if ( *(_DWORD *)&v14[8] != 0 )
        break;
LABEL_111:
      v35 = *((_DWORD *)v33 + 14);
      switch ( *v32 )
      {
        case 4:
          if ( *((_DWORD *)v33 + 9) == 0 || (v43 = 1, *(_DWORD *)(v35 + 36) == 0) )
            v43 = 0;
          v44 = *((double *)v33 + 5);
          *((_DWORD *)v33 + 9) = v43;
          if ( v44 == 0.0 || (*(_DWORD *)&v14[8] = 1, *(double *)(v35 + 40) == 0.0) )
            *(_DWORD *)&v14[8] = 0;
          *((double *)v33 + 5) = (double)*(__int64 *)&v14[4];
          goto LABEL_168;
        case 5:
          if ( *((_DWORD *)v33 + 9) != 0 || (v45 = 0, *(_DWORD *)(v35 + 36) != 0) )
            v45 = 1;
          v46 = *((double *)v33 + 5);
          *((_DWORD *)v33 + 9) = v45;
          if ( v46 != 0.0 || (*(_DWORD *)&v14[8] = 0, *(double *)(v35 + 40) != 0.0) )
            *(_DWORD *)&v14[8] = 1;
          *((double *)v33 + 5) = (double)*(__int64 *)&v14[4];
          goto LABEL_168;
        case 6:
          v47 = *((_DWORD *)v33 + 9);
          v48 = *((double *)v33 + 5);
          *(_DWORD *)&v14[4] = *(_DWORD *)(v35 + 36);
          *(_DWORD *)v14 = v47 >> 31;
          HIDWORD(v15) = v47 - *(_DWORD *)&v14[4];
          LODWORD(v15) = *(_DWORD *)&v14[4] >> 31;
          *((_DWORD *)v33 + 9) = (v47 >> 31) + ((unsigned int)v47 >= *(_DWORD *)&v14[4]) + (*(_DWORD *)&v14[4] >> 31);
          *(_DWORD *)&v14[8] = v48 >= *(double *)(v35 + 40);
          *((double *)v33 + 5) = (double)*(__int64 *)&v14[4];
          goto LABEL_168;
        case 7:
          v49 = *(_DWORD *)(v35 + 36);
          v50 = *((double *)v33 + 5);
          *(_DWORD *)&v14[4] = *((_DWORD *)v33 + 9);
          *(_DWORD *)v14 = v49 >> 31;
          HIDWORD(v15) = v49 - *(_DWORD *)&v14[4];
          LODWORD(v15) = *(_DWORD *)&v14[4] >> 31;
          *((_DWORD *)v33 + 9) = (v49 >> 31) + ((unsigned int)v49 >= *(_DWORD *)&v14[4]) + (*(_DWORD *)&v14[4] >> 31);
          *(_DWORD *)&v14[8] = v50 <= *(double *)(v35 + 40);
          *((double *)v33 + 5) = (double)*(__int64 *)&v14[4];
          goto LABEL_168;
        case 8:
          if ( *(_DWORD *)v33 != 0 )
          {
            *(_DWORD *)v14 = *(_DWORD *)(v35 + 36) - *((_DWORD *)v33 + 9);
            LODWORD(v15) = _cntlzw(*(unsigned int *)v14);
            *(_DWORD *)&v14[8] = (v15 & 0x20) != 0;
          }
          else
          {
            *(_DWORD *)&v14[8] = (_cntlzw(idStr::Icmp(s1: *((const char **)v33 + 2), s2: *(const char **)(v35 + 8)))
                                & 0x20) != 0;
          }
          *(_DWORD *)&v14[4] = *(_DWORD *)v33;
          *((_DWORD *)v33 + 9) = *(_DWORD *)&v14[8];
          if ( *(_DWORD *)&v14[4] != 0 )
            *(_DWORD *)&v14[8] = *((double *)v33 + 5) == *(double *)(v35 + 40);
          else
            *(_DWORD *)&v14[8] = (_cntlzw(idStr::Icmp(s1: *((const char **)v33 + 2), s2: *(const char **)(v35 + 8)))
                                & 0x20) != 0;
          *((double *)v33 + 5) = (double)*(__int64 *)&v14[4];
          goto LABEL_168;
        case 9:
          if ( *(_DWORD *)v33 != 0 )
          {
            *(_DWORD *)v14 = *(_DWORD *)(v35 + 36) - *((_DWORD *)v33 + 9);
            LODWORD(v15) = *(_DWORD *)v14 - 1;
            *(_DWORD *)&v14[8] = *(_DWORD *)(v35 + 36) != *((_DWORD *)v33 + 9);
          }
          else
          {
            *(_DWORD *)&v14[8] = idStr::Icmp(s1: *((const char **)v33 + 2), s2: *(const char **)(v35 + 8)) != 0;
          }
          *(_DWORD *)&v14[4] = *(_DWORD *)v33;
          *((_DWORD *)v33 + 9) = *(_DWORD *)&v14[8];
          if ( *(_DWORD *)&v14[4] != 0 )
            *(_DWORD *)&v14[8] = *((double *)v33 + 5) != *(double *)(v35 + 40);
          else
            *(_DWORD *)&v14[8] = idStr::Icmp(s1: *((const char **)v33 + 2), s2: *(const char **)(v35 + 8)) != 0;
          *((double *)v33 + 5) = (double)*(__int64 *)&v14[4];
          goto LABEL_168;
        case 20:
          *(_DWORD *)v14 = *((int *)v33 + 9) >> *(_DWORD *)(v35 + 36);
          *((_DWORD *)v33 + 9) = *(_DWORD *)v14;
          goto LABEL_168;
        case 21:
          *(_DWORD *)v14 = *((_DWORD *)v33 + 9) << *(_DWORD *)(v35 + 36);
          *((_DWORD *)v33 + 9) = *(_DWORD *)v14;
          goto LABEL_168;
        case 27:
          v37 = *((double *)v33 + 5);
          *(_DWORD *)v14 = *(_DWORD *)(v35 + 36) * *((_DWORD *)v33 + 9);
          *((_DWORD *)v33 + 9) = *(_DWORD *)v14;
          *((double *)v33 + 5) = *(double *)(v35 + 40) * v37;
          goto LABEL_168;
        case 28:
          v38 = *(_DWORD *)(v35 + 36);
          if ( v38 == 0 || *(double *)(v35 + 40) == 0.0 )
            goto LABEL_183;
          *(_DWORD *)v14 = *((_DWORD *)v33 + 9);
          v39 = *((double *)v33 + 5);
          __twllei(v38, 0);
          LODWORD(v15) = *(_DWORD *)v14 / v38;
          *((_DWORD *)v33 + 9) = *(_DWORD *)v14 / v38;
          HIDWORD(v15) = __ROL4__(*(_DWORD *)v14, 1) - 1;
          LODWORD(v16) = v38 & ~HIDWORD(v15);
          __twlgei(v16, 0xFFFFFFFF);
          *((double *)v33 + 5) = v39 / *(double *)(v35 + 40);
          goto LABEL_168;
        case 29:
          v40 = *(_DWORD *)(v35 + 36);
          if ( v40 == 0 )
          {
LABEL_183:
            v59 = "divide by zero in #if/#elif";
            goto LABEL_186;
          }
          *(_DWORD *)v14 = *((_DWORD *)v33 + 9);
          __twllei(v40, 0);
          LODWORD(v15) = *(_DWORD *)v14 / v40;
          HIDWORD(v15) = *(_DWORD *)v14 / v40 * v40;
          LODWORD(v16) = __ROL4__(*(_DWORD *)v14, 1) - 1;
          HIDWORD(v16) = *(_DWORD *)v14 % v40;
          *((_DWORD *)v33 + 9) = *(_DWORD *)v14 % v40;
          __twlgei(v40 & ~(_DWORD)v16, 0xFFFFFFFF);
          goto LABEL_168;
        case 30:
          v41 = *((double *)v33 + 5);
          *((_DWORD *)v33 + 9) += *(_DWORD *)(v35 + 36);
          *((double *)v33 + 5) = *(double *)(v35 + 40) + v41;
          goto LABEL_168;
        case 31:
          v42 = *((double *)v33 + 5);
          *(_DWORD *)v14 = *((_DWORD *)v33 + 9) - *(_DWORD *)(v35 + 36);
          *((_DWORD *)v33 + 9) = *(_DWORD *)v14;
          *((double *)v33 + 5) = v42 - *(double *)(v35 + 40);
          goto LABEL_168;
        case 33:
          *(_DWORD *)v14 = *(_DWORD *)(v35 + 36) & *((_DWORD *)v33 + 9);
          *((_DWORD *)v33 + 9) = *(_DWORD *)v14;
          goto LABEL_168;
        case 34:
          *(_DWORD *)v14 = *(_DWORD *)(v35 + 36) | *((_DWORD *)v33 + 9);
          *((_DWORD *)v33 + 9) = *(_DWORD *)v14;
          goto LABEL_168;
        case 35:
          *(_DWORD *)v14 = *(_DWORD *)(v35 + 36) ^ *((_DWORD *)v33 + 9);
          *((_DWORD *)v33 + 9) = *(_DWORD *)v14;
          goto LABEL_168;
        case 36:
          *((_DWORD *)v33 + 9) = ~*((_DWORD *)v33 + 9);
          goto LABEL_168;
        case 37:
          v36 = *((double *)v33 + 5);
          *(_DWORD *)&v14[4] = _cntlzw(*((_DWORD *)v33 + 9));
          *(_DWORD *)v14 = (v14[7] & 0x20) != 0;
          *((_DWORD *)v33 + 9) = *(_DWORD *)v14;
          *(_DWORD *)&v14[8] = v36 == 0.0;
          *((double *)v33 + 5) = (double)*(__int64 *)&v14[4];
          goto LABEL_168;
        case 38:
          v51 = *(_DWORD *)(v35 + 36);
          v52 = *((double *)v33 + 5);
          *(_DWORD *)&v14[4] = *((_DWORD *)v33 + 9);
          *(_DWORD *)v14 = v51 - *(_DWORD *)&v14[4];
          LODWORD(v15) = ~(*(_DWORD *)&v14[4] ^ v51);
          HIDWORD(v15) = ((*(_DWORD *)&v14[4] ^ v51) & 0x80000000) == 0;
          LODWORD(v16) = HIDWORD(v15) + (v51 >= *(_DWORD *)&v14[4]);
          HIDWORD(v16) = v16 & 1;
          *((_DWORD *)v33 + 9) = HIDWORD(v16);
          *(_DWORD *)&v14[8] = v52 > *(double *)(v35 + 40);
          *((double *)v33 + 5) = (double)*(__int64 *)&v14[4];
          goto LABEL_168;
        case 39:
          v53 = *(_DWORD *)(v35 + 36);
          v54 = *((double *)v33 + 5);
          *(_DWORD *)&v14[4] = *((_DWORD *)v33 + 9);
          *(_DWORD *)v14 = *(_DWORD *)&v14[4] - v53;
          LODWORD(v15) = ~(v53 ^ *(_DWORD *)&v14[4]);
          HIDWORD(v15) = ((v53 ^ *(_DWORD *)&v14[4]) & 0x80000000) == 0;
          LODWORD(v16) = HIDWORD(v15) + (*(_DWORD *)&v14[4] >= v53);
          HIDWORD(v16) = v16 & 1;
          *((_DWORD *)v33 + 9) = HIDWORD(v16);
          *(_DWORD *)&v14[8] = v54 < *(double *)(v35 + 40);
          *((double *)v33 + 5) = (double)*(__int64 *)&v14[4];
          goto LABEL_168;
        case 42:
          if ( v29 == 0 )
          {
            v59 = ": without ? in #if/#elif";
            goto LABEL_186;
          }
          if ( integer != 0 )
          {
            if ( v31 == 0 )
            {
              v29 = 0;
              *((_DWORD *)v33 + 9) = *(_DWORD *)(v35 + 36);
              goto LABEL_168;
            }
          }
          else if ( v30 == 0.0 )
          {
            *((_QWORD *)v33 + 5) = *(_QWORD *)(v35 + 40);
          }
          v29 = 0;
          goto LABEL_168;
        case 43:
          if ( v29 != 0 )
          {
            v59 = "? after ? in #if/#elif";
            goto LABEL_186;
          }
          v31 = *((_DWORD *)v33 + 9);
          v30 = *((double *)v33 + 5);
          v29 = 1;
LABEL_168:
          v55 = *v32;
          if ( *v32 != 37 && v55 != 36 )
          {
            if ( v55 != 43 )
              v33 = *((_BYTE **)v33 + 14);
            v56 = *((_DWORD *)v33 + 13);
            if ( v56 != 0 )
              *(_DWORD *)(v56 + 56) = *((_DWORD *)v33 + 14);
            else
              v71 = *((_BYTE **)v33 + 14);
            v57 = *((_DWORD *)v33 + 14);
            if ( v57 != 0 )
              *(_DWORD *)(v57 + 52) = *((_DWORD *)v33 + 13);
          }
          v58 = v32[3];
          if ( v58 != 0 )
            *(_DWORD *)(v58 + 16) = *(_DWORD *)v34;
          else
            v72 = *(int **)v34;
          if ( *(_DWORD *)v34 != 0 )
            *(_DWORD *)(*(_DWORD *)v34 + 12) = v32[3];
          break;
        default:
          goto LABEL_168;
      }
    }
    while ( 1 )
    {
      *(_DWORD *)&v14[4] = v32[2];
      *(_DWORD *)v14 = *(_DWORD *)(*(_DWORD *)&v14[8] + 8);
      if ( *(int *)&v14[4] > *(int *)v14 )
        goto LABEL_111;
      if ( *(_DWORD *)&v14[4] == *(_DWORD *)v14 )
      {
        *(_DWORD *)&v14[4] = v32[1];
        *(_DWORD *)v14 = *(_DWORD *)(*(_DWORD *)&v14[8] + 4);
        if ( *(int *)&v14[4] >= *(int *)v14 )
          goto LABEL_111;
      }
      if ( v33 == nullptr )
        break;
      *(_DWORD *)&v14[4] = *v32;
      if ( *v32 != 37 && *(_DWORD *)&v14[4] != 36 )
        v33 = *((_BYTE **)v33 + 14);
      v34 = *(_DWORD *)&v14[8] + 16;
      v32 = *(int **)&v14[8];
      *(_DWORD *)&v14[8] = *(_DWORD *)(*(_DWORD *)&v14[8] + 16);
      if ( *(_DWORD *)&v14[8] == 0 )
        goto LABEL_111;
    }
    v59 = "mising values in #if/#elif";
LABEL_186:
    idParser::Error(
      this,
      str: v59,
      a3: v16,
      a4: v15,
      a5: *(__int64 *)v14,
      a6: v64,
      a7: v65,
      a8: v66,
      a9: v67,
      a10: v68,
      a11: v69);
    v70 = 1;
  }
LABEL_187:
  if ( v71 != nullptr )
  {
    if ( intvalue != nullptr )
      *intvalue = *((_DWORD *)v71 + 9);
    v60 = floatvalue;
    if ( floatvalue != nullptr )
      *(_QWORD *)floatvalue = *((_QWORD *)v71 + 5);
  }
  else
  {
    v60 = floatvalue;
  }
  for ( i = v72; i != nullptr; i = (int *)i[4] )
    ;
  for ( j = v71; j != nullptr; j = *((_BYTE **)j + 14) )
    ;
  if ( v70 != 0 )
  {
    if ( intvalue != nullptr )
      *intvalue = 0;
    if ( v60 != nullptr )
      *(_QWORD *)v60 = 0;
    `eh vector destructor iterator'(
      ptr: v74,
      size: 0x40u,
      count: 64,
      pDtor: (void (__fastcall *)(void *))idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels);
    return 0;
  }
  else
  {
    `eh vector destructor iterator'(
      ptr: v74,
      size: 0x40u,
      count: 64,
      pDtor: (void (__fastcall *)(void *))idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels);
    return 1;
  }
}


// ========================================================================
// __unwind$115979
// EA  : 0x82F8DDF4
// RVA : 0x00F8DDF4
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_115979()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(v0 - 5776 + 1504),
    size: 0x40u,
    count: 64,
    pDtor: (void (__fastcall *)(void *))idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels);
}


// ========================================================================
// ?UnreadSignToken@idParser@@AAAXXZ
// EA  : 0x82F8DE38
// RVA : 0x00F8DE38
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void __fastcall idParser::UnreadSignToken(idParser *this)
{
  idLexer *scriptstack; // r10
  idToken v3; // [sp+50h] [-60h] BYREF

  v3.len = 0;
  v3.allocedAndFlag = 20;
  v3.data = v3.baseBuffer;
  v3.floatvalue = -3.4028235e38;
  v3.baseBuffer[0] = 0;
  v3.intvalue = 0;
  memset(&v3.whiteSpaceStart_p, 0, 12);
  scriptstack = this->scriptstack;
  if ( scriptstack != nullptr )
    v3.line = scriptstack->line;
  else
    v3.line = 0;
  v3.linesCrossed = 0;
  v3.flags = 0;
  v3.whiteSpaceEnd_p = idToken::DEFAULT_WHITESPACE + 1;
  v3.whiteSpaceStart_p = idToken::DEFAULT_WHITESPACE;
  idStr::operator=(this: &v3, text: "-");
  v3.type = 5;
  v3.subtype = 31;
  idParser::UnreadSourceToken(this, token: &v3);
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$116149
// EA  : 0x82F8DF10
// RVA : 0x00F8DF10
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_116149()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?CheckTokenString@idParser@@QAAHPBD@Z
// EA  : 0x82F8DF40
// RVA : 0x00F8DF40
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::CheckTokenString(idParser *this, const char *string)
{
  idToken v5; // [sp+50h] [-70h] BYREF

  v5.len = 0;
  v5.allocedAndFlag = 20;
  v5.floatvalue = -3.4028235e38;
  v5.data = v5.baseBuffer;
  v5.baseBuffer[0] = 0;
  v5.intvalue = 0;
  memset(&v5.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadToken(this, token: &v5) )
  {
    if ( idStr::Cmp(s1: v5.data, s2: string) == 0 )
    {
      idStr::FreeData(this: &v5);
      return 1;
    }
    idParser::UnreadSourceToken(this, token: &v5);
  }
  idStr::FreeData(this: &v5);
  return 0;
}


// ========================================================================
// __unwind$116218
// EA  : 0x82F8DFEC
// RVA : 0x00F8DFEC
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_116218()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?UnreadToken@idParser@@QAAXABVidToken@@@Z
// EA  : 0x82F8E018
// RVA : 0x00F8E018
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

// attributes: thunk
void __fastcall idParser::UnreadToken(idParser *this, const idToken *token)
{
  idParser::UnreadSourceToken(this, token);
}


// ========================================================================
// ?LoadFile@idParser@@QAA_NPBD_N@Z
// EA  : 0x82F8E028
// RVA : 0x00F8E028
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idParser::LoadFile(idParser *this, const char *filename, __int64 OSPath, __int64 a4, __int64 a5)
{
  _BYTE *v5; // r3
  _BYTE *v6; // r30
  int v8; // r26
  const char *v9; // r3
  idLexer *v10; // r3
  idLexer *v11; // r29
  __int64 v12; // r6
  __int64 v13; // r10
  __int64 v14; // r8
  int v16; // r10
  int v17; // [sp+8h] [-98h]
  int v18; // [sp+Ch] [-94h]
  int v19; // [sp+10h] [-90h]
  int v20; // [sp+14h] [-8Ch]

  v6 = v5;
  v8 = HIDWORD(OSPath);
  if ( *v5 != 0 )
  {
    v9 = "idParser::LoadFile: another source already loaded";
    idLib::FatalError(fmt: *(__int64 *)&filename, a2: OSPath, a3: a4, a4: a5, a5: v17, a6: v18, a7: v19, a8: v20);
  }
  v10 = (idLexer *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                     size: 0x88u,
                     tag: TAG_LEXER,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
  if ( v10 != nullptr )
    v11 = idLexer::idLexer(this: v10, flags_: 0);
  else
    v11 = nullptr;
  v11->flags = *((_DWORD *)v6 + 19);
  idLexer::SetPunctuations(this: v11, p: *((const punctuation_t **)v6 + 18));
  HIDWORD(v12) = v8;
  if ( (unsigned __int8)idLexer::LoadFile(this: v11, filename_: filename, OSPath: v12, a4: v14, a5: v13) != 0 )
  {
    v11->next = nullptr;
    v6[68] = v8;
    idStr::operator=(this: (idStr *)(v6 + 4), text: filename);
    *((_DWORD *)v6 + 20) = v11;
    *((_DWORD *)v6 + 21) = 0;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(v6 + 604));
    v16 = *((_DWORD *)v6 + 19);
    *((_DWORD *)v6 + 155) = 0;
    *((_DWORD *)v6 + 156) = 0;
    *v6 = 1;
    *((_DWORD *)v6 + 157) = 0;
    if ( (v16 & 0x100) == 0 )
      idParser::AddGlobalDefinesToSource(this: (idParser *)v6);
    return 1;
  }
  else
  {
    idLexer::~idLexer(this: v11);
    idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    return 0;
  }
}


// ========================================================================
// $LN20_4
// EA  : 0x82F8E158
// RVA : 0x00F8E158
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _LN20_4()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_LEXER);
}


// ========================================================================
// ?LoadMemory@idParser@@QAA_NPBDH0@Z
// EA  : 0x82F8E190
// RVA : 0x00F8E190
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idParser::LoadMemory(idParser *this, const char *ptr, __int64 name, __int64 a4, __int64 a5)
{
  _BYTE *v5; // r3
  _BYTE *v6; // r30
  unsigned int v8; // r24
  const char *v9; // r27
  const char *v10; // r3
  idLexer *v11; // r3
  idLexer *v12; // r29
  __int64 v13; // r10
  __int64 v14; // r8
  int v16; // r10
  int v17; // [sp+8h] [-98h]
  int v18; // [sp+Ch] [-94h]
  int v19; // [sp+10h] [-90h]
  int v20; // [sp+14h] [-8Ch]

  v6 = v5;
  v8 = HIDWORD(name);
  v9 = (const char *)name;
  if ( *v5 != 0 )
  {
    v10 = "idParser::LoadMemory: another source already loaded";
    idLib::FatalError(fmt: *(__int64 *)&ptr, a2: name, a3: a4, a4: a5, a5: v17, a6: v18, a7: v19, a8: v20);
  }
  v11 = (idLexer *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                     size: 0x88u,
                     tag: TAG_LEXER,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
  if ( v11 != nullptr )
    v12 = idLexer::idLexer(this: v11, flags_: 0);
  else
    v12 = nullptr;
  v12->flags = *((_DWORD *)v6 + 19);
  idLexer::SetPunctuations(this: v12, p: *((const punctuation_t **)v6 + 18));
  if ( (unsigned __int8)idLexer::LoadMemory(this: v12, ptr, name: __SPAIR64__(v8, (unsigned int)v9), a4: v14, a5: v13) != 0 )
  {
    v12->next = nullptr;
    idStr::operator=(this: (idStr *)(v6 + 4), text: v9);
    *((_DWORD *)v6 + 20) = v12;
    *((_DWORD *)v6 + 21) = 0;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(v6 + 604));
    v16 = *((_DWORD *)v6 + 19);
    *((_DWORD *)v6 + 155) = 0;
    *((_DWORD *)v6 + 156) = 0;
    *v6 = 1;
    *((_DWORD *)v6 + 157) = 0;
    if ( (v16 & 0x100) == 0 )
      idParser::AddGlobalDefinesToSource(this: (idParser *)v6);
    return 1;
  }
  else
  {
    idLexer::~idLexer(this: v12);
    idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
    return 0;
  }
}


// ========================================================================
// $LN20_5
// EA  : 0x82F8E2C4
// RVA : 0x00F8E2C4
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _LN20_5()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_LEXER);
}


// ========================================================================
// ?FreeDefine@idParser@@CAXPAUdefine_t@1@@Z
// EA  : 0x82F8E2F0
// RVA : 0x00F8E2F0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void __fastcall idParser::FreeDefine(idParser::define_t *define)
{
  idToken *parms; // r31
  idToken *next; // r30
  idToken *tokens; // r31
  idToken *v5; // r30

  parms = define->parms;
  if ( parms != nullptr )
  {
    do
    {
      next = parms->next;
      idStr::FreeData(this: parms);
      idMem::Free(this: &mem, ptr: parms, align: ALIGN_16);
      parms = next;
    }
    while ( next != nullptr );
  }
  tokens = define->tokens;
  if ( tokens != nullptr )
  {
    do
    {
      v5 = tokens->next;
      idStr::FreeData(this: tokens);
      idMem::Free(this: &mem, ptr: tokens, align: ALIGN_16);
      tokens = v5;
    }
    while ( v5 != nullptr );
  }
  idStr::FreeData(this: &define->name);
  idMem::Free(this: &mem, ptr: define, align: ALIGN_16);
}


// ========================================================================
// ?AddInclude@idParser@@QAAXPBD@Z
// EA  : 0x82F8E398
// RVA : 0x00F8E398
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void __fastcall idParser::AddInclude(idParser *this, const char *fileName, __int64 a3, __int64 a4, __int64 a5)
{
  va *v6; // r3
  __int64 v7; // r10
  __int64 v8; // r6
  __int64 v9; // r8
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  int v19; // [sp+8h] [-1208h]
  int v20; // [sp+Ch] [-1204h]
  int v21; // [sp+10h] [-1200h]
  int v22; // [sp+14h] [-11FCh]
  int v23; // [sp+18h] [-11F8h]
  int v24; // [sp+1Ch] [-11F4h]
  idToken v25; // [sp+50h] [-11C0h] BYREF
  idToken v26; // [sp+A0h] [-1170h] BYREF
  idToken v27; // [sp+F0h] [-1120h] BYREF
  idStr v28; // [sp+140h] [-10D0h] BYREF
  idLexer v29; // [sp+160h] [-10B0h] BYREF
  va v30; // [sp+1F0h] [-1020h] BYREF

  HIDWORD(a3) = fileName;
  v6 = va::va(this: &v30, fmt: "#include \"%s\"", a3, a4, a5, a6: v19, a7: v20, a8: v21, a9: v22, a10: v23, a11: v24);
  idStr::idStr(this: &v28, text: v6);
  idStr::BackSlashesToSlashes(this: &v28);
  idLexer::idLexer(this: &v29, flags_: 512);
  LODWORD(v7) = &unk_82390000;
  HIDWORD(v8) = v28.len;
  LODWORD(v8) = "AddInclude";
  idLexer::LoadMemory(this: &v29, ptr: v28.data, name: v8, a4: v9, a5: v7);
  HIDWORD(v10) = byte_821B0000;
  LODWORD(v10) = 20;
  LODWORD(v11) = v26.baseBuffer;
  v26.len = 0;
  v26.allocedAndFlag = 20;
  v26.data = v26.baseBuffer;
  v26.floatvalue = -3.4028235e38;
  v26.baseBuffer[0] = 0;
  v26.intvalue = 0;
  memset(&v26.whiteSpaceStart_p, 0, 12);
  HIDWORD(v11) = v25.baseBuffer;
  v25.floatvalue = -3.4028235e38;
  v25.allocedAndFlag = 20;
  v25.data = v25.baseBuffer;
  v25.len = 0;
  v25.baseBuffer[0] = 0;
  v25.intvalue = 0;
  memset(&v25.whiteSpaceStart_p, 0, 12);
  LODWORD(v12) = v27.baseBuffer;
  v27.floatvalue = -3.4028235e38;
  v27.allocedAndFlag = 20;
  v27.data = v27.baseBuffer;
  v27.len = 0;
  v27.baseBuffer[0] = 0;
  v27.intvalue = 0;
  memset(&v27.whiteSpaceStart_p, 0, 12);
  idLexer::ReadToken(this: &v29, token: &v26, a3: v12, a4: v11, a5: v10);
  idLexer::ReadToken(this: &v29, token: &v25, a3: v15, a4: v14, a5: v13);
  idLexer::ReadToken(this: &v29, token: &v27, a3: v18, a4: v17, a5: v16);
  idParser::UnreadSourceToken(this, token: &v27);
  idParser::UnreadSourceToken(this, token: &v25);
  idParser::UnreadSourceToken(this, token: &v26);
  idStr::FreeData(this: &v27);
  idStr::FreeData(this: &v25);
  idStr::FreeData(this: &v26);
  idLexer::~idLexer(this: &v29);
  idStr::FreeData(this: &v28);
}


// ========================================================================
// __unwind$116684_0
// EA  : 0x82F8E514
// RVA : 0x00F8E514
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_116684_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4624 + 320));
}


// ========================================================================
// __unwind$116685
// EA  : 0x82F8E53C
// RVA : 0x00F8E53C
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_116685()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 4624 + 352));
}


// ========================================================================
// __unwind$116686
// EA  : 0x82F8E564
// RVA : 0x00F8E564
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_116686()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4624 + 160));
}


// ========================================================================
// __unwind$116687
// EA  : 0x82F8E58C
// RVA : 0x00F8E58C
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_116687()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4624 + 80));
}


// ========================================================================
// __unwind$116688
// EA  : 0x82F8E5B4
// RVA : 0x00F8E5B4
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_116688()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4624 + 240));
}


// ========================================================================
// ?PopDefineScope@idParser@@QAAXXZ
// EA  : 0x82F8E5E0
// RVA : 0x00F8E5E0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void __fastcall idParser::PopDefineScope(idParser *this)
{
  idParser::define_t **definehash; // r25
  int i; // r23
  idParser::define_t *v4; // r29
  idParser::define_t *v5; // r26
  idParser::define_t *hashnext; // r27
  idStr *parms; // r31
  char *data; // r30
  idStr *tokens; // r31
  char *v10; // r30

  definehash = this->definehash;
  for ( i = 128; i != 0; --i )
  {
    v4 = *definehash;
    v5 = nullptr;
    if ( *definehash != nullptr )
    {
      do
      {
        hashnext = v4->hashnext;
        if ( v4->scope == this->defineScope )
        {
          if ( v5 != nullptr )
            v5->hashnext = hashnext;
          else
            *definehash = hashnext;
          parms = v4->parms;
          if ( parms != nullptr )
          {
            do
            {
              data = parms[2].data;
              idStr::FreeData(this: parms);
              idMem::Free(this: &mem, ptr: parms, align: ALIGN_16);
              parms = (idStr *)data;
            }
            while ( data != nullptr );
          }
          tokens = v4->tokens;
          if ( tokens != nullptr )
          {
            do
            {
              v10 = tokens[2].data;
              idStr::FreeData(this: tokens);
              idMem::Free(this: &mem, ptr: tokens, align: ALIGN_16);
              tokens = (idStr *)v10;
            }
            while ( v10 != nullptr );
          }
          idStr::FreeData(this: &v4->name);
          idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
        }
        else
        {
          v5 = v4;
        }
        v4 = hashnext;
      }
      while ( hashnext != nullptr );
    }
    ++definehash;
  }
  --this->defineScope;
}


// ========================================================================
// ?FreeSource@idParser@@QAAXXZ
// EA  : 0x82F8E6F0
// RVA : 0x00F8E6F0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void __fastcall idParser::FreeSource(idParser *this)
{
  idParser::define_t **definehash; // r31
  int i; // r29
  idParser::define_t *v4; // r3
  idLexer *scriptstack; // r31
  idToken *tokens; // r31

  definehash = this->definehash;
  for ( i = 128; i != 0; --i )
  {
    while ( *definehash != nullptr )
    {
      v4 = *definehash;
      *definehash = (*definehash)->hashnext;
      idParser::FreeDefine(define: v4);
    }
    ++definehash;
  }
  while ( this->scriptstack != nullptr )
  {
    scriptstack = this->scriptstack;
    this->scriptstack = scriptstack->next;
    if ( scriptstack != nullptr )
    {
      idLexer::~idLexer(this: scriptstack);
      idMem::Free(this: &mem, ptr: scriptstack, align: ALIGN_16);
    }
  }
  while ( this->tokens != nullptr )
  {
    tokens = this->tokens;
    this->tokens = tokens->next;
    if ( tokens != nullptr )
    {
      idStr::FreeData(this: tokens);
      idMem::Free(this: &mem, ptr: tokens, align: ALIGN_16);
    }
  }
  this->loaded = false;
}


// ========================================================================
// ?ReadSourceToken@idParser@@AAAHAAVidToken@@@Z
// EA  : 0x82F8E850
// RVA : 0x00F8E850
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idParser::ReadSourceToken(idParser *this, idToken *token, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // r3
  int v6; // r31
  const char *v8; // r3
  int v9; // r29
  __int64 v10; // r6
  _DWORD *v11; // r29
  __int64 v12; // r10
  __int64 v13; // r8
  int v14; // r10
  int v15; // r11
  int v16; // r30
  int v17; // r11
  idLexer *v18; // r3
  idLexer *v19; // r3
  char v20; // r9
  bool v21; // r3
  idLexer *v22; // r30
  idStr *v23; // r30
  int v25; // [sp+8h] [-98h]
  int v26; // [sp+Ch] [-94h]
  int v27; // [sp+10h] [-90h]
  int v28; // [sp+14h] [-8Ch]
  int v29; // [sp+18h] [-88h]
  int v30; // [sp+1Ch] [-84h]

  v6 = v5;
  if ( *(_DWORD *)(v5 + 80) == 0 )
  {
    v8 = "idParser::ReadSourceToken: not loaded";
    idLib::FatalError(fmt: *(__int64 *)&token, a2: a3, a3: a4, a4: a5, a5: v25, a6: v26, a7: v27, a8: v28);
  }
  LODWORD(a5) = *(_DWORD *)(v6 + 84);
  v9 = 0;
  if ( (_DWORD)a5 != 0 )
  {
LABEL_22:
    idToken::operator=(this: token, __that: *(const idToken **)(v6 + 84));
    v23 = *(idStr **)(v6 + 84);
    *(_DWORD *)(v6 + 84) = v23[2].data;
    if ( v23 != nullptr )
    {
      idStr::FreeData(this: v23);
      idMem::Free(this: &mem, ptr: v23, align: ALIGN_16);
    }
    return 1;
  }
  else
  {
    while ( 1 )
    {
      if ( (unsigned __int8)idLexer::ReadToken(this: *(idLexer **)(v6 + 80), token, a3, a4, a5) != 0 )
      {
        token->linesCrossed += v9;
        return 1;
      }
      if ( idLexer::EndOfFile(this: *(idLexer **)(v6 + 80)) )
      {
        if ( *(int *)(v6 + 608) > 0 )
        {
          v11 = (_DWORD *)(v6 + 604);
          do
          {
            HIDWORD(v12) = *(_DWORD *)(v6 + 80);
            LODWORD(v13) = 16 * *(_DWORD *)(v6 + 608) + *v11;
            HIDWORD(v13) = *(_DWORD *)(v13 - 4);
            if ( HIDWORD(v13) != HIDWORD(v12) )
              break;
            LODWORD(v12) = *v11;
            idParser::Warning(
              this: (idParser *)v6,
              str: "missing #endif",
              a3: v10,
              a4: v13,
              a5: v12,
              a6: v25,
              a7: v26,
              a8: v27,
              a9: v28,
              a10: v29,
              a11: v30);
            v14 = *(_DWORD *)(v6 + 608);
            if ( v14 != 0 )
            {
              v15 = 16 * v14 + *v11;
              if ( *(_DWORD *)(v15 - 4) == *(_DWORD *)(v6 + 80) )
              {
                v16 = v14 - 1;
                *(_DWORD *)(v6 + 620) -= *(_DWORD *)(v15 - 12);
                LODWORD(v10) = *(_DWORD *)(v6 + 612);
                if ( v14 - 1 <= (int)v10
                  || (unsigned __int8)idList<idPlayerCoverScore_t,5>::Resize(
                                        this: (idList<idPlane,37> *)(v6 + 604),
                                        newsize: v14 - 1) != 0 )
                {
                  v17 = *(_DWORD *)(v6 + 612);
                  if ( v16 < v17 )
                    v17 = v16;
                  *(_DWORD *)(v6 + 608) = v17;
                }
              }
            }
          }
          while ( *(int *)(v6 + 608) > 0 );
        }
        v9 = 1;
      }
      v18 = *(idLexer **)(v6 + 80);
      if ( v18->next == nullptr )
        return 0;
      v20 = idLexer::HadError(this: v18) | *(_BYTE *)(v6 + 632);
      v19 = *(idLexer **)(v6 + 80);
      *(_BYTE *)(v6 + 632) = v20;
      v21 = idLexer::HadWarning(this: v19);
      LODWORD(a4) = *(unsigned __int8 *)(v6 + 633);
      HIDWORD(a4) = v21;
      v22 = *(idLexer **)(v6 + 80);
      LODWORD(a3) = v21 | (unsigned int)a4;
      *(_BYTE *)(v6 + 633) = v21 | a4;
      if ( v22 != nullptr )
      {
        *(_DWORD *)(v6 + 80) = v22->next;
        idLexer::~idLexer(this: v22);
        idMem::Free(this: &mem, ptr: v22, align: ALIGN_16);
        --*(_DWORD *)(v6 + 636);
      }
      if ( *(_DWORD *)(v6 + 84) != 0 )
        goto LABEL_22;
    }
  }
}


// ========================================================================
// ?ReadDefineParms@idParser@@AAAHPAUdefine_t@1@PAPAVidToken@@H@Z
// EA  : 0x82F8EA80
// RVA : 0x00F8EA80
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::ReadDefineParms(idParser *this, idParser::define_t *define, __int64 maxparms, __int64 a4)
{
  __int64 v4; // r10
  idToken **v7; // r23
  int v8; // r28
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  int v13; // r11
  idToken **v14; // r10
  __int64 v15; // r6
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  int v21; // r22
  int v22; // r24
  int v23; // r19
  int v24; // r27
  idToken *v25; // r28
  __int64 v26; // r10
  __int64 v27; // r8
  __int64 v28; // r6
  idToken *v29; // r3
  idToken *v30; // r30
  int v31; // [sp+8h] [-168h]
  int v32; // [sp+Ch] [-164h]
  int v33; // [sp+10h] [-160h]
  int v34; // [sp+14h] [-15Ch]
  int v35; // [sp+18h] [-158h]
  int v36; // [sp+1Ch] [-154h]
  idToken v37; // [sp+80h] [-F0h] BYREF
  int v38; // [sp+194h] [+24h]
  int v39; // [sp+19Ch] [+2Ch]

  v38 = HIDWORD(maxparms);
  v39 = maxparms;
  LODWORD(v4) = v37.baseBuffer;
  HIDWORD(v4) = 20;
  v37.len = 0;
  v37.data = v37.baseBuffer;
  v37.floatvalue = -3.4028235e38;
  v7 = (idToken **)HIDWORD(maxparms);
  v8 = maxparms;
  v37.allocedAndFlag = 20;
  v37.baseBuffer[0] = 0;
  v37.intvalue = 0;
  memset(&v37.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadSourceToken(this, token: &v37, a3: maxparms, a4, a5: v4) == 0 )
  {
    HIDWORD(v11) = define->name.data;
    idParser::Error(
      this,
      str: "define '%s' missing parameters",
      a3: v11,
      a4: v10,
      a5: v9,
      a6: v31,
      a7: v32,
      a8: v33,
      a9: v34,
      a10: v35,
      a11: v36);
    idStr::FreeData(this: &v37);
    return 0;
  }
  LODWORD(v9) = define->numparms;
  if ( (int)v9 > v8 )
  {
    HIDWORD(v11) = v8;
    idParser::Error(
      this,
      str: "define with more than %d parameters",
      a3: v11,
      a4: v10,
      a5: v9,
      a6: v31,
      a7: v32,
      a8: v33,
      a9: v34,
      a10: v35,
      a11: v36);
    idStr::FreeData(this: &v37);
    return 0;
  }
  v13 = 0;
  if ( (int)v9 > 0 )
  {
    v14 = v7 - 1;
    do
    {
      ++v13;
      *++v14 = nullptr;
    }
    while ( v13 < define->numparms );
  }
  if ( idStr::Cmp(s1: v37.data, s2: "(") != 0 )
  {
    idParser::UnreadSourceToken(this, token: &v37);
    HIDWORD(v15) = define->name.data;
    idParser::Error(
      this,
      str: "define '%s' missing parameters",
      a3: v15,
      a4: v17,
      a5: v16,
      a6: v31,
      a7: v32,
      a8: v33,
      a9: v34,
      a10: v35,
      a11: v36);
    idStr::FreeData(this: &v37);
    return 0;
  }
  LODWORD(v18) = allocationCurrent[242];
  HIDWORD(v18) = &unk_82390000;
  LODWORD(v19) = byte_821B0000;
  HIDWORD(v19) = &unk_82390000;
  LODWORD(v20) = &unk_82390000;
  HIDWORD(v20) = byte_821B0000;
  v21 = 0;
  v22 = 0;
  v23 = 1;
  while ( 2 )
  {
    if ( v22 >= v8 )
    {
      HIDWORD(v20) = define->name.data;
      idParser::Error(
        this,
        str: "define '%s' with too many parameters",
        a3: v20,
        a4: v19,
        a5: v18,
        a6: v31,
        a7: v32,
        a8: v33,
        a9: v34,
        a10: v35,
        a11: v36);
      idStr::FreeData(this: &v37);
      return 0;
    }
    v24 = 1;
    *v7 = nullptr;
    v25 = nullptr;
    while ( 1 )
    {
      while ( 1 )
      {
        if ( idParser::ReadSourceToken(this, token: &v37, a3: v20, a4: v19, a5: v18) == 0 )
        {
          HIDWORD(v28) = define->name.data;
          idParser::Error(
            this,
            str: "define '%s' incomplete",
            a3: v28,
            a4: v27,
            a5: v26,
            a6: v31,
            a7: v32,
            a8: v33,
            a9: v34,
            a10: v35,
            a11: v36);
          idStr::FreeData(this: &v37);
          return 0;
        }
        if ( idStr::Cmp(s1: v37.data, s2: ",") != 0 )
          break;
        if ( v23 <= 1 )
        {
          if ( v24 != 0 )
          {
            HIDWORD(v20) = define->name.data;
            idParser::Warning(
              this,
              str: "define '%s' has too many commas",
              a3: v20,
              a4: v19,
              a5: v18,
              a6: v31,
              a7: v32,
              a8: v33,
              a9: v34,
              a10: v35,
              a11: v36);
          }
          if ( v22 >= define->numparms )
          {
            HIDWORD(v20) = define->name.data;
            idParser::Warning(
              this,
              str: "define '%s' has too many define parameters",
              a3: v20,
              a4: v19,
              a5: v18,
              a6: v31,
              a7: v32,
              a8: v33,
              a9: v34,
              a10: v35,
              a11: v36);
          }
          goto LABEL_27;
        }
LABEL_17:
        v24 = 0;
        if ( v22 < define->numparms )
        {
          v29 = (idToken *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x48u,
                             tag: TAG_LEXER,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
          if ( v29 != nullptr )
          {
            v29->len = 0;
            v29->data = v29->baseBuffer;
            v30 = v29;
            v29->allocedAndFlag = 20;
            v29->baseBuffer[0] = 0;
            v29->floatvalue = -3.4028235e38;
            v29->intvalue = 0;
            v29->whiteSpaceStart_p = nullptr;
            v29->whiteSpaceEnd_p = nullptr;
            v29->next = nullptr;
          }
          else
          {
            v30 = nullptr;
          }
          idToken::operator=(this: v30, __that: &v37);
          v30->next = nullptr;
          if ( v25 != nullptr )
            v25->next = v30;
          else
            *v7 = v30;
          v25 = v30;
        }
      }
      if ( idStr::Cmp(s1: v37.data, s2: "(") == 0 )
      {
        ++v23;
        goto LABEL_17;
      }
      if ( idStr::Cmp(s1: v37.data, s2: ")") == 0 )
        break;
      if ( v37.type != 4 )
        goto LABEL_17;
      HIDWORD(v20) = idParser::FindHashedDefine(this, name: v37.data);
      if ( HIDWORD(v20) == 0 )
        goto LABEL_17;
      if ( idParser::ExpandDefineIntoSource(this, deftoken: &v37, define: (idParser::define_t *)HIDWORD(v20)) == 0 )
      {
        idStr::FreeData(this: &v37);
        return 0;
      }
    }
    if ( --v23 > 0 )
      goto LABEL_17;
    LODWORD(v18) = v38;
    HIDWORD(v18) = 4 * define->numparms + v38;
    LODWORD(v19) = *(_DWORD *)(HIDWORD(v18) - 4);
    if ( (_DWORD)v19 == 0 )
    {
      HIDWORD(v20) = define->name.data;
      idParser::Warning(
        this,
        str: "define '%s' has too few define parameters",
        a3: v20,
        a4: v19,
        a5: v18,
        a6: v31,
        a7: v32,
        a8: v33,
        a9: v34,
        a10: v35,
        a11: v36);
    }
    v21 = 1;
LABEL_27:
    ++v22;
    ++v7;
    if ( v21 == 0 )
    {
      v8 = v39;
      continue;
    }
    break;
  }
  idStr::FreeData(this: &v37);
  return 1;
}


// ========================================================================
// __unwind$117678
// EA  : 0x82F8EE54
// RVA : 0x00F8EE54
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_117678()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 128));
}


// ========================================================================
// ?ExpandDefine@idParser@@AAAHPAVidToken@@PAUdefine_t@1@PAPAV2@2@Z
// EA  : 0x82F8EE88
// RVA : 0x00F8EE88
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::ExpandDefine(
        idParser *this,
        idToken *deftoken,
        idParser::define_t *define,
        idToken **firsttoken,
        idToken **lasttoken)
{
  int v8; // r30
  __int64 v11; // r8
  int v12; // r30
  __int64 v14; // r6
  idToken *tokens; // r26
  idToken *v16; // r17
  idToken *i; // r25
  int v18; // r3
  const idToken *v19; // r27
  const idToken *j; // r28
  idToken *v21; // r3
  idToken *v22; // r29
  int line; // r11
  idToken *next; // r11
  int DefineParm; // r3
  __int64 v26; // r10
  __int64 v27; // r8
  __int64 v28; // r6
  idToken *v29; // r3
  idToken *v30; // r29
  idToken *v31; // r3
  int v32; // r11
  idToken *v33; // r29
  idToken *v34; // r11
  idToken *v35; // r11
  idStr *v36; // r28
  __int64 v37; // r10
  __int64 v38; // r8
  idToken *v39; // r27
  idStr **v40; // r27
  idStr *v41; // r29
  char *data; // r28
  __int64 v43; // r6
  int v44; // [sp+8h] [-378h]
  int v45; // [sp+Ch] [-374h]
  int v46; // [sp+10h] [-370h]
  int v47; // [sp+14h] [-36Ch]
  int v48; // [sp+18h] [-368h]
  int v49; // [sp+1Ch] [-364h]
  idToken v50; // [sp+90h] [-2F0h] BYREF
  _DWORD v51[130]; // [sp+E0h] [-2A0h] BYREF

  v8 = 0;
  memset(v51, 0, 512);
  v50.len = 0;
  v50.baseBuffer[0] = 0;
  v50.intvalue = 0;
  v50.allocedAndFlag = 20;
  v50.data = v50.baseBuffer;
  memset(&v50.whiteSpaceStart_p, 0, 12);
  v50.floatvalue = -3.4028235e38;
  if ( define->builtin != 0 )
  {
    v12 = idParser::ExpandBuiltinDefine(this, deftoken, define, firsttoken, lasttoken);
    idStr::FreeData(this: &v50);
    return v12;
  }
  if ( define->numparms != 0 )
  {
    LODWORD(v14) = 128;
    HIDWORD(v14) = v51;
    if ( idParser::ReadDefineParms(this, define, maxparms: v14, a4: v11) == 0 )
    {
      idStr::FreeData(this: &v50);
      return 0;
    }
  }
  tokens = define->tokens;
  v16 = nullptr;
  for ( i = nullptr; tokens != nullptr; tokens = tokens->next )
  {
    if ( tokens->type == 4 && (v18 = idParser::FindDefineParm(this, define, name: tokens->data)) >= 0 )
    {
      v19 = (const idToken *)v51[v18];
      for ( j = v19; j != nullptr; i = v22 )
      {
        v21 = (idToken *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x48u,
                           tag: TAG_LEXER,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
        if ( v21 != nullptr )
        {
          v21->allocedAndFlag = 20;
          v21->len = 0;
          v22 = v21;
          v21->data = v21->baseBuffer;
          v21->baseBuffer[0] = 0;
          v21->floatvalue = -3.4028235e38;
          v21->intvalue = 0;
          v21->whiteSpaceStart_p = nullptr;
          v21->whiteSpaceEnd_p = nullptr;
          v21->next = nullptr;
        }
        else
        {
          v22 = nullptr;
        }
        idToken::operator=(this: v22, __that: j);
        if ( j == v19 )
          idToken::InheritWhiteSpace(this: v22, other: tokens);
        line = deftoken->line;
        v22->next = nullptr;
        v22->line = line;
        if ( i != nullptr )
          i->next = v22;
        else
          v16 = v22;
        j = j->next;
      }
    }
    else
    {
      if ( idStr::Cmp(s1: tokens->data, s2: "#") != 0
        || (next = tokens->next) == nullptr
        || (DefineParm = idParser::FindDefineParm(this, define, name: next->data)) < 0 )
      {
        v31 = (idToken *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x48u,
                           tag: TAG_LEXER,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
        if ( v31 != nullptr )
        {
          v31->allocedAndFlag = 20;
          v31->len = 0;
          v31->data = v31->baseBuffer;
          v31->baseBuffer[0] = 0;
          v31->floatvalue = -3.4028235e38;
          v31->intvalue = 0;
          v31->whiteSpaceStart_p = nullptr;
          v31->whiteSpaceEnd_p = nullptr;
          v31->next = nullptr;
        }
        else
        {
          v31 = nullptr;
        }
        v30 = v31;
        idToken::operator=(this: v31, __that: tokens);
      }
      else
      {
        tokens = tokens->next;
        if ( idParser::StringizeTokens(this, tokens: (idToken *)v51[DefineParm], token: &v50) == 0 )
        {
          idParser::Error(
            this,
            str: "can't stringize tokens",
            a3: v28,
            a4: v27,
            a5: v26,
            a6: v44,
            a7: v45,
            a8: v46,
            a9: v47,
            a10: v48,
            a11: v49);
          idStr::FreeData(this: &v50);
          return 0;
        }
        v29 = (idToken *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x48u,
                           tag: TAG_LEXER,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
        if ( v29 != nullptr )
        {
          v29->allocedAndFlag = 20;
          v29->len = 0;
          v30 = v29;
          v29->data = v29->baseBuffer;
          v29->baseBuffer[0] = 0;
          v29->floatvalue = -3.4028235e38;
          v29->intvalue = 0;
          v29->whiteSpaceStart_p = nullptr;
          v29->whiteSpaceEnd_p = nullptr;
          v29->next = nullptr;
        }
        else
        {
          v30 = nullptr;
        }
        idToken::operator=(this: v30, __that: &v50);
        idToken::InheritWhiteSpace(this: v30, other: tokens);
      }
      v32 = deftoken->line;
      v30->next = nullptr;
      v30->line = v32;
      if ( i != nullptr )
        i->next = v30;
      else
        v16 = v30;
      i = v30;
    }
  }
  v33 = v16;
  while ( v33 != nullptr )
  {
    v34 = v33->next;
    if ( v34 != nullptr && idStr::Cmp(s1: v34->data, s2: "##") == 0 && (v35 = v33->next, (v36 = v35->next) != nullptr) )
    {
      if ( idParser::MergeTokens(this, t1: v33, t2: v35->next) == 0 )
      {
        LODWORD(v43) = v36->data;
        HIDWORD(v43) = v33->data;
        idParser::Error(
          this,
          str: "can't merge '%s' with '%s'",
          a3: v43,
          a4: v38,
          a5: v37,
          a6: v44,
          a7: v45,
          a8: v46,
          a9: v47,
          a10: v48,
          a11: v49);
        idStr::FreeData(this: &v50);
        return 0;
      }
      v39 = v33->next;
      if ( v39 != nullptr )
      {
        idStr::FreeData(this: v33->next);
        idMem::Free(this: &mem, ptr: v39, align: ALIGN_16);
      }
      v33->next = (idToken *)v36[2].data;
      if ( v36 == i )
        i = v33;
      idStr::FreeData(this: v36);
      idMem::Free(this: &mem, ptr: v36, align: ALIGN_16);
    }
    else
    {
      v33 = v33->next;
    }
  }
  *firsttoken = v16;
  *lasttoken = i;
  if ( define->numparms > 0 )
  {
    v40 = (idStr **)v51;
    do
    {
      v41 = *v40;
      if ( *v40 != nullptr )
      {
        do
        {
          data = v41[2].data;
          idStr::FreeData(this: v41);
          idMem::Free(this: &mem, ptr: v41, align: ALIGN_16);
          v41 = (idStr *)data;
        }
        while ( data != nullptr );
      }
      ++v8;
      ++v40;
    }
    while ( v8 < define->numparms );
  }
  idStr::FreeData(this: &v50);
  return 1;
}


// ========================================================================
// __unwind$117936_0
// EA  : 0x82F8F36C
// RVA : 0x00F8F36C
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_117936_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 896 + 144));
}


// ========================================================================
// ?ExpandDefineIntoSource@idParser@@AAAHPAVidToken@@PAUdefine_t@1@@Z
// EA  : 0x82F8F398
// RVA : 0x00F8F398
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::ExpandDefineIntoSource(idParser *this, idToken *deftoken, idParser::define_t *define)
{
  int result; // r3
  idToken *v6; // r11
  idToken *v7; // r8
  idToken *v8; // [sp+50h] [-20h] BYREF
  idToken *v9; // [sp+54h] [-1Ch] BYREF

  result = idParser::ExpandDefine(this, deftoken, define, firsttoken: &v8, lasttoken: &v9);
  if ( result != 0 )
  {
    v6 = v8;
    if ( v8 != nullptr )
    {
      v7 = v9;
      if ( v9 != nullptr )
      {
        v8->linesCrossed += deftoken->linesCrossed;
        v6->whiteSpaceStart_p = deftoken->whiteSpaceStart_p;
        v6->whiteSpaceEnd_p = deftoken->whiteSpaceEnd_p;
        v7->next = this->tokens;
        this->tokens = v6;
      }
    }
    return 1;
  }
  return result;
}


// ========================================================================
// ?ReadLine@idParser@@AAAHAAVidToken@@_N@Z
// EA  : 0x82F8F428
// RVA : 0x00F8F428
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

BOOL __fastcall idParser::ReadLine(idParser *this, idToken *token, __int64 multiline, __int64 a4, __int64 a5)
{
  int v8; // r30

  if ( BYTE3(multiline) != 0 )
  {
    if ( idParser::ReadSourceToken(this, token, a3: multiline, a4, a5) != 0 )
      return idStr::Cmp(s1: token->data, s2: "%>") != 0;
  }
  else
  {
    v8 = 0;
    while ( idParser::ReadSourceToken(this, token, a3: multiline, a4, a5) != 0 )
    {
      if ( token->linesCrossed > v8 )
      {
        idParser::UnreadSourceToken(this, token);
        return false;
      }
      v8 = 1;
      if ( idStr::Cmp(s1: token->data, s2: "\\") != 0 )
        return true;
    }
  }
  return false;
}


// ========================================================================
// ?Evaluate@idParser@@AAAHPAHPANH@Z
// EA  : 0x82F8F4E8
// RVA : 0x00F8F4E8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::Evaluate(
        idParser *this,
        int *intvalue,
        long double *floatvalue,
        int integer,
        __int64 a5,
        __int64 a6)
{
  int v10; // r21
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  __int64 v15; // r6
  __int64 v16; // r10
  __int64 v17; // r8
  idToken *v18; // r22
  idToken *v19; // r28
  idToken *v20; // r3
  idParser::define_t *HashedDefine; // r5
  idToken *v22; // r3
  idToken *v23; // r29
  __int64 v24; // r10
  __int64 v25; // r8
  unsigned int v26; // r6
  idStr *v27; // r30
  char *data; // r29
  int v29; // [sp+8h] [-158h]
  int v30; // [sp+Ch] [-154h]
  int v31; // [sp+10h] [-150h]
  int v32; // [sp+14h] [-14Ch]
  int v33; // [sp+18h] [-148h]
  int v34; // [sp+1Ch] [-144h]
  idToken v35; // [sp+70h] [-F0h] BYREF

  LODWORD(a6) = v35.baseBuffer;
  v35.len = 0;
  v35.baseBuffer[0] = 0;
  v35.floatvalue = -3.4028235e38;
  v35.intvalue = 0;
  memset(&v35.whiteSpaceStart_p, 0, 12);
  v35.allocedAndFlag = 20;
  v35.data = v35.baseBuffer;
  v10 = 0;
  if ( intvalue != nullptr )
    *intvalue = 0;
  if ( floatvalue != nullptr )
    *(_QWORD *)floatvalue = 0;
  if ( !idParser::ReadLine(this, token: &v35, multiline: (unsigned int)integer, a4: a5, a5: a6) )
  {
    idParser::Error(
      this,
      str: "no value after #if/#elif",
      a3: v13,
      a4: v12,
      a5: v11,
      a6: v29,
      a7: v30,
      a8: v31,
      a9: v32,
      a10: v33,
      a11: v34);
    idStr::FreeData(this: &v35);
    return 0;
  }
  HIDWORD(v17) = 0x82000000;
  LODWORD(v15) = 0x10000;
  LODWORD(v16) = allocationCurrent[242];
  HIDWORD(v16) = "visemeExType_t";
  LODWORD(v17) = &unk_82390000;
  v18 = nullptr;
  v19 = nullptr;
  do
  {
    if ( v35.type != 4 )
    {
      if ( v35.type != 3 && v35.type != 5 )
      {
        HIDWORD(v15) = v35.data;
        idParser::Error(
          this,
          str: "can't evaluate '%s'",
          a3: v15,
          a4: v17,
          a5: v16,
          a6: v29,
          a7: v30,
          a8: v31,
          a9: v32,
          a10: v33,
          a11: v34);
        idStr::FreeData(this: &v35);
        return 0;
      }
      v20 = (idToken *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x48u,
                         tag: TAG_LEXER,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
      if ( v20 != nullptr )
        goto LABEL_26;
      goto LABEL_27;
    }
    if ( v10 != 0 )
    {
      v10 = 0;
      v20 = (idToken *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x48u,
                         tag: TAG_LEXER,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
      if ( v20 != nullptr )
      {
LABEL_26:
        v20->allocedAndFlag = 20;
        v20->len = 0;
        v23 = v20;
        v20->data = v20->baseBuffer;
        v20->baseBuffer[0] = 0;
        v20->floatvalue = -3.4028235e38;
        v20->intvalue = 0;
        v20->whiteSpaceStart_p = nullptr;
        v20->whiteSpaceEnd_p = nullptr;
        v20->next = nullptr;
        goto LABEL_28;
      }
LABEL_27:
      v23 = nullptr;
LABEL_28:
      idToken::operator=(this: v23, __that: &v35);
      v23->next = nullptr;
      if ( v19 != nullptr )
      {
        v19->next = v23;
        goto LABEL_31;
      }
      goto LABEL_30;
    }
    if ( idStr::Cmp(s1: v35.data, s2: "defined") == 0 )
    {
      v10 = 1;
      v20 = (idToken *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x48u,
                         tag: TAG_LEXER,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
      if ( v20 != nullptr )
        goto LABEL_26;
      goto LABEL_27;
    }
    HashedDefine = idParser::FindHashedDefine(this, name: v35.data);
    if ( HashedDefine == nullptr )
    {
      v22 = (idToken *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x48u,
                         tag: TAG_LEXER,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
      if ( v22 != nullptr )
      {
        v22->allocedAndFlag = 20;
        v22->len = 0;
        v23 = v22;
        v22->data = v22->baseBuffer;
        v22->baseBuffer[0] = 0;
        v22->floatvalue = -3.4028235e38;
        v22->intvalue = 0;
        v22->whiteSpaceStart_p = nullptr;
        v22->whiteSpaceEnd_p = nullptr;
        v22->next = nullptr;
      }
      else
      {
        v23 = nullptr;
      }
      idStr::operator=(this: v23, text: "0");
      v23->floatvalue = 0.0;
      v23->intvalue = 0;
      v23->type = 3;
      v23->subtype = 65539;
      v23->flags = 0;
      v23->next = nullptr;
      if ( v19 != nullptr )
      {
        v19->next = v23;
LABEL_31:
        v19 = v23;
        continue;
      }
LABEL_30:
      v18 = v23;
      goto LABEL_31;
    }
    if ( idParser::ExpandDefineIntoSource(this, deftoken: &v35, define: HashedDefine) == 0 )
      goto LABEL_22;
  }
  while ( idParser::ReadLine(this, token: &v35, multiline: v26, a4: v25, a5: v24) );
  if ( idParser::EvaluateTokens(this, tokens: v18, intvalue, floatvalue, integer) == 0 )
  {
LABEL_22:
    idStr::FreeData(this: &v35);
    return 0;
  }
  v27 = v18;
  if ( v18 != nullptr )
  {
    do
    {
      data = v27[2].data;
      idStr::FreeData(this: v27);
      idMem::Free(this: &mem, ptr: v27, align: ALIGN_16);
      v27 = (idStr *)data;
    }
    while ( data != nullptr );
  }
  idStr::FreeData(this: &v35);
  return 1;
}


// ========================================================================
// __unwind$118343
// EA  : 0x82F8F8DC
// RVA : 0x00F8F8DC
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_118343()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 112));
}


// ========================================================================
// ?EvaluateFunction@idParser@@AAAHPAHPANH@Z
// EA  : 0x82F8F910
// RVA : 0x00F8F910
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::EvaluateFunction(idParser *this, int *intvalue, __int64 integer, __int64 a4, __int64 a5)
{
  long double *v7; // r18
  int v8; // r17
  int v9; // r24
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  __int64 v16; // r10
  int v17; // r21
  idToken *v18; // r23
  idToken *v19; // r28
  idToken *v20; // r3
  __int64 v21; // r10
  __int64 v22; // r8
  __int64 v23; // r6
  __int64 v24; // r10
  __int64 v25; // r8
  __int64 v26; // r6
  idToken *v27; // r29
  idStr *v28; // r30
  char *data; // r29
  int v31; // [sp+8h] [-138h]
  int v32; // [sp+Ch] [-134h]
  int v33; // [sp+10h] [-130h]
  int v34; // [sp+14h] [-12Ch]
  int v35; // [sp+18h] [-128h]
  int v36; // [sp+1Ch] [-124h]
  idToken v37; // [sp+70h] [-D0h] BYREF

  LODWORD(a5) = v37.baseBuffer;
  v37.len = 0;
  v37.allocedAndFlag = 20;
  v37.floatvalue = -3.4028235e38;
  v7 = (long double *)HIDWORD(integer);
  v8 = integer;
  v37.data = v37.baseBuffer;
  v9 = 0;
  v37.baseBuffer[0] = 0;
  v37.intvalue = 0;
  memset(&v37.whiteSpaceStart_p, 0, 12);
  if ( intvalue != nullptr )
    *intvalue = 0;
  if ( HIDWORD(integer) != 0 )
    *(_QWORD *)HIDWORD(integer) = 0;
  if ( idParser::ReadSourceToken(this, token: &v37, a3: integer, a4, a5) == 0 || idStr::Cmp(s1: v37.data, s2: "(") != 0 )
  {
    idParser::Error(
      this,
      str: "no leading ( after $evalint/$evalfloat",
      a3: v12,
      a4: v11,
      a5: v10,
      a6: v31,
      a7: v32,
      a8: v33,
      a9: v34,
      a10: v35,
      a11: v36);
    goto _M118951;
  }
  if ( idParser::ReadSourceToken(this, token: &v37, a3: v12, a4: v11, a5: v10) == 0 )
  {
    idParser::Error(
      this,
      str: "nothing to evaluate",
      a3: v15,
      a4: v14,
      a5: v13,
      a6: v31,
      a7: v32,
      a8: v33,
      a9: v34,
      a10: v35,
      a11: v36);
_M118951:
    idStr::FreeData(this: &v37);
    return 0;
  }
  LODWORD(v16) = allocationCurrent[242];
  HIDWORD(v16) = &unk_82390000;
  v17 = 1;
  v18 = nullptr;
  v19 = nullptr;
  while ( v37.type == 4 )
  {
    if ( v9 != 0 )
    {
      v9 = 0;
      v20 = (idToken *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x48u,
                         tag: TAG_LEXER,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
      if ( v20 == nullptr )
        goto LABEL_30;
    }
    else
    {
      if ( idStr::Cmp(s1: v37.data, s2: "defined") != 0 )
      {
        HIDWORD(v23) = idParser::FindHashedDefine(this, name: v37.data);
        if ( HIDWORD(v23) == 0 )
        {
          HIDWORD(v23) = v37.data;
          idParser::Warning(
            this,
            str: "can't evaluate '%s', not defined",
            a3: v23,
            a4: v22,
            a5: v21,
            a6: v31,
            a7: v32,
            a8: v33,
            a9: v34,
            a10: v35,
            a11: v36);
          goto _M118951;
        }
        if ( idParser::ExpandDefineIntoSource(this, deftoken: &v37, define: (idParser::define_t *)HIDWORD(v23)) == 0 )
          goto _M118951;
        goto LABEL_35;
      }
      v9 = 1;
      v20 = (idToken *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x48u,
                         tag: TAG_LEXER,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
      if ( v20 == nullptr )
      {
LABEL_30:
        v27 = nullptr;
        goto LABEL_31;
      }
    }
LABEL_29:
    v20->allocedAndFlag = 20;
    v20->len = 0;
    v27 = v20;
    v20->data = v20->baseBuffer;
    v20->baseBuffer[0] = 0;
    v20->floatvalue = -3.4028235e38;
    v20->intvalue = 0;
    v20->whiteSpaceStart_p = nullptr;
    v20->whiteSpaceEnd_p = nullptr;
    v20->next = nullptr;
LABEL_31:
    idToken::operator=(this: v27, __that: &v37);
    v27->next = nullptr;
    if ( v19 != nullptr )
      v19->next = v27;
    else
      v18 = v27;
    v19 = v27;
LABEL_35:
    if ( idParser::ReadSourceToken(this, token: &v37, a3: v26, a4: v25, a5: v24) == 0 )
      goto LABEL_36;
  }
  if ( v37.type != 1 && v37.type != 3 && v37.type != 5 )
  {
    HIDWORD(v15) = v37.data;
    idParser::Error(
      this,
      str: "can't evaluate '%s'",
      a3: v15,
      a4: v14,
      a5: v16,
      a6: v31,
      a7: v32,
      a8: v33,
      a9: v34,
      a10: v35,
      a11: v36);
    goto _M118951;
  }
  if ( *v37.data == 40 )
  {
    ++v17;
  }
  else if ( *v37.data == 41 )
  {
    --v17;
  }
  if ( v17 > 0 )
  {
    v20 = (idToken *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x48u,
                       tag: TAG_LEXER,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
    if ( v20 == nullptr )
      goto LABEL_30;
    goto LABEL_29;
  }
LABEL_36:
  if ( idParser::EvaluateTokens(this, tokens: v18, intvalue, floatvalue: v7, integer: v8) == 0 )
    goto _M118951;
  v28 = v18;
  if ( v18 != nullptr )
  {
    do
    {
      data = v28[2].data;
      idStr::FreeData(this: v28);
      idMem::Free(this: &mem, ptr: v28, align: ALIGN_16);
      v28 = (idStr *)data;
    }
    while ( data != nullptr );
  }
  idStr::FreeData(this: &v37);
  return 1;
}


// ========================================================================
// __unwind$118661
// EA  : 0x82F8FCB8
// RVA : 0x00F8FCB8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_118661()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 112));
}


// ========================================================================
// ?Directive_undef@idParser@@AAAHXZ
// EA  : 0x82F8FCE8
// RVA : 0x00F8FCE8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::Directive_undef(idParser *this, int a2, int a3, unsigned int a4, __int64 a5)
{
  __int64 v5; // r10
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v11; // r6
  __int64 v12; // r10
  __int64 v13; // r8
  idParser::define_t *v14; // r28
  int v15; // r26
  idParser::define_t *v16; // r30
  idParser::define_t *hashnext; // r29
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  idParser::define_t *v21; // r11
  int v22; // [sp+8h] [-E8h]
  int v23; // [sp+Ch] [-E4h]
  int v24; // [sp+10h] [-E0h]
  int v25; // [sp+14h] [-DCh]
  int v26; // [sp+18h] [-D8h]
  int v27; // [sp+1Ch] [-D4h]
  idToken v28; // [sp+70h] [-80h] BYREF

  LODWORD(v5) = 20;
  HIDWORD(v5) = v28.baseBuffer;
  v28.len = 0;
  v28.allocedAndFlag = 20;
  v28.data = v28.baseBuffer;
  v28.floatvalue = -3.4028235e38;
  v28.baseBuffer[0] = 0;
  v28.intvalue = 0;
  memset(&v28.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadLine(this, token: &v28, multiline: a4, a4: a5, a5: v5) )
  {
    if ( v28.type == 4 )
    {
      v14 = nullptr;
      v15 = 4 * (PC_NameHash(name: v28.data) + 23);
      v16 = *(idParser::define_t **)(&this->loaded + v15);
      if ( v16 != nullptr )
      {
        while ( 1 )
        {
          hashnext = v16->hashnext;
          if ( idStr::Cmp(s1: v28.data, s2: v16->name.data) == 0 )
            break;
          v14 = v16;
          v16 = hashnext;
          if ( hashnext == nullptr )
            goto LABEL_15;
        }
        if ( v16->builtin != 0 )
        {
          HIDWORD(v20) = v28.data;
          idParser::Warning(
            this,
            str: "can't undef '%s'",
            a3: v20,
            a4: v19,
            a5: v18,
            a6: v22,
            a7: v23,
            a8: v24,
            a9: v25,
            a10: v26,
            a11: v27);
        }
        else
        {
          v21 = v16->hashnext;
          if ( v14 != nullptr )
            v14->hashnext = v21;
          else
            *(_DWORD *)(&this->loaded + v15) = v21;
          idParser::FreeDefine(define: v16);
        }
      }
LABEL_15:
      idStr::FreeData(this: &v28);
      return 1;
    }
    else
    {
      idParser::UnreadSourceToken(this, token: &v28);
      HIDWORD(v11) = v28.data;
      idParser::Error(
        this,
        str: "expected name but found '%s'",
        a3: v11,
        a4: v13,
        a5: v12,
        a6: v22,
        a7: v23,
        a8: v24,
        a9: v25,
        a10: v26,
        a11: v27);
      idStr::FreeData(this: &v28);
      return 0;
    }
  }
  else
  {
    idParser::Error(
      this,
      str: "undef without name",
      a3: v9,
      a4: v8,
      a5: v7,
      a6: v22,
      a7: v23,
      a8: v24,
      a9: v25,
      a10: v26,
      a11: v27);
    idStr::FreeData(this: &v28);
    return 0;
  }
}


// ========================================================================
// __unwind$118969_0
// EA  : 0x82F8FE48
// RVA : 0x00F8FE48
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_118969_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// ?Directive_endif@idParser@@AAAHXZ
// EA  : 0x82F8FE70
// RVA : 0x00F8FE70
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::Directive_endif(idParser *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  idParser::indent_t *list; // r11
  idList<idParser::indent_t,11> *p_indentstack; // r3
  idParser::indent_t *v8; // r11
  int type; // r30
  int v11; // [sp+8h] [-78h]
  int v12; // [sp+Ch] [-74h]
  int v13; // [sp+10h] [-70h]
  int v14; // [sp+14h] [-6Ch]
  int v15; // [sp+18h] [-68h]
  int v16; // [sp+1Ch] [-64h]

  LODWORD(a5) = this->indentstack.num;
  if ( (_DWORD)a5 != 0 )
  {
    list = this->indentstack.list;
    HIDWORD(a5) = 16 * a5;
    LODWORD(a4) = this->scriptstack;
    p_indentstack = &this->indentstack;
    v8 = &list[a5];
    HIDWORD(a4) = v8[-1].script;
    if ( HIDWORD(a4) == (_DWORD)a4 )
    {
      type = v8[-1].type;
      this->skip -= v8[-1].skip;
      idList<parmValue_t,56>::SetNum(this: (idList<idPlane,37> *)p_indentstack, newNum: a5 - 1);
      if ( type != 0 )
        return 1;
    }
  }
  idParser::Error(this, str: "misplaced #endif", a3, a4, a5, a6: v11, a7: v12, a8: v13, a9: v14, a10: v15, a11: v16);
  return 0;
}


// ========================================================================
// ?Directive_line@idParser@@AAAHXZ
// EA  : 0x82F8FF18
// RVA : 0x00F8FF18
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::Directive_line(idParser *this, int a2, __int64 a3)
{
  __int64 v3; // r10
  __int64 v4; // r8
  __int64 v6; // r10
  __int64 v7; // r8
  unsigned int v8; // r6
  int v10; // [sp+8h] [-B8h]
  int v11; // [sp+Ch] [-B4h]
  int v12; // [sp+10h] [-B0h]
  int v13; // [sp+14h] [-ACh]
  int v14; // [sp+18h] [-A8h]
  int v15; // [sp+1Ch] [-A4h]
  idToken v16; // [sp+60h] [-60h] BYREF

  LODWORD(v3) = byte_821B0000;
  HIDWORD(v3) = 20;
  LODWORD(v4) = v16.baseBuffer;
  v16.len = 0;
  v16.allocedAndFlag = 20;
  v16.data = v16.baseBuffer;
  v16.floatvalue = -3.4028235e38;
  v16.baseBuffer[0] = 0;
  v16.intvalue = 0;
  memset(&v16.whiteSpaceStart_p, 0, 12);
  HIDWORD(v4) = &unk_82390000;
  idParser::Error(
    this,
    str: "#line directive not supported",
    a3,
    a4: v4,
    a5: v3,
    a6: v10,
    a7: v11,
    a8: v12,
    a9: v13,
    a10: v14,
    a11: v15);
  while ( idParser::ReadLine(this, token: &v16, multiline: v8, a4: v7, a5: v6) )
    ;
  idStr::FreeData(this: &v16);
  return 1;
}


// ========================================================================
// __unwind$119116
// EA  : 0x82F8FFB4
// RVA : 0x00F8FFB4
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_119116()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?Directive_error@idParser@@AAAHXZ
// EA  : 0x82F8FFE8
// RVA : 0x00F8FFE8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::Directive_error(idParser *this, int a2, int a3, unsigned int a4, __int64 a5)
{
  __int64 v5; // r10
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  int v11; // [sp+8h] [-C8h]
  int v12; // [sp+Ch] [-C4h]
  int v13; // [sp+10h] [-C0h]
  int v14; // [sp+14h] [-BCh]
  int v15; // [sp+18h] [-B8h]
  int v16; // [sp+1Ch] [-B4h]
  idToken v17; // [sp+70h] [-60h] BYREF

  LODWORD(v5) = byte_821B0000;
  HIDWORD(v5) = 20;
  LODWORD(a5) = v17.baseBuffer;
  v17.len = 0;
  v17.allocedAndFlag = 20;
  v17.data = v17.baseBuffer;
  v17.floatvalue = -3.4028235e38;
  v17.baseBuffer[0] = 0;
  v17.intvalue = 0;
  memset(&v17.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadLine(this, token: &v17, multiline: a4, a4: a5, a5: v5) && v17.type == 1 )
  {
    HIDWORD(v9) = v17.data;
    idParser::Error(
      this,
      str: "#error: %s",
      a3: v9,
      a4: v8,
      a5: v7,
      a6: v11,
      a7: v12,
      a8: v13,
      a9: v14,
      a10: v15,
      a11: v16);
    idStr::FreeData(this: &v17);
    return 1;
  }
  else
  {
    idParser::Error(
      this,
      str: "#error without string",
      a3: v9,
      a4: v8,
      a5: v7,
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
// __unwind$119178
// EA  : 0x82F900B4
// RVA : 0x00F900B4
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_119178()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?Directive_warning@idParser@@AAAHXZ
// EA  : 0x82F900E8
// RVA : 0x00F900E8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::Directive_warning(idParser *this, int a2, int a3, unsigned int a4, __int64 a5)
{
  __int64 v5; // r10
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  int v11; // [sp+8h] [-C8h]
  int v12; // [sp+Ch] [-C4h]
  int v13; // [sp+10h] [-C0h]
  int v14; // [sp+14h] [-BCh]
  int v15; // [sp+18h] [-B8h]
  int v16; // [sp+1Ch] [-B4h]
  idToken v17; // [sp+70h] [-60h] BYREF

  LODWORD(v5) = byte_821B0000;
  HIDWORD(v5) = 20;
  LODWORD(a5) = v17.baseBuffer;
  v17.len = 0;
  v17.allocedAndFlag = 20;
  v17.data = v17.baseBuffer;
  v17.floatvalue = -3.4028235e38;
  v17.baseBuffer[0] = 0;
  v17.intvalue = 0;
  memset(&v17.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadLine(this, token: &v17, multiline: a4, a4: a5, a5: v5) && v17.type == 1 )
  {
    HIDWORD(v9) = v17.data;
    idParser::Warning(
      this,
      str: "#warning: %s",
      a3: v9,
      a4: v8,
      a5: v7,
      a6: v11,
      a7: v12,
      a8: v13,
      a9: v14,
      a10: v15,
      a11: v16);
    idStr::FreeData(this: &v17);
    return 1;
  }
  else
  {
    idParser::Warning(
      this,
      str: "#warning without string",
      a3: v9,
      a4: v8,
      a5: v7,
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
// __unwind$119254
// EA  : 0x82F901B4
// RVA : 0x00F901B4
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_119254()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?Directive_pragma@idParser@@AAAHXZ
// EA  : 0x82F901E8
// RVA : 0x00F901E8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::Directive_pragma(idParser *this, int a2, int a3, unsigned int a4, __int64 a5)
{
  __int64 v5; // r10
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r10
  __int64 v11; // r8
  unsigned int v12; // r6
  idStr *v13; // r3
  __int64 v14; // r10
  __int64 v15; // r8
  unsigned int v16; // r6
  int v18; // [sp+8h] [-118h]
  int v19; // [sp+Ch] [-114h]
  int v20; // [sp+10h] [-110h]
  int v21; // [sp+14h] [-10Ch]
  int v22; // [sp+18h] [-108h]
  int v23; // [sp+1Ch] [-104h]
  idToken v24; // [sp+70h] [-B0h] BYREF
  idStr v25; // [sp+C0h] [-60h] BYREF
  idStr v26[2]; // [sp+E0h] [-40h] BYREF

  LODWORD(v5) = byte_821B0000;
  HIDWORD(v5) = 20;
  LODWORD(a5) = v24.baseBuffer;
  v24.len = 0;
  v24.allocedAndFlag = 20;
  v24.data = v24.baseBuffer;
  v24.floatvalue = -3.4028235e38;
  v24.baseBuffer[0] = 0;
  v24.intvalue = 0;
  memset(&v24.whiteSpaceStart_p, 0, 12);
  idParser::ReadLine(this, token: &v24, multiline: a4, a4: a5, a5: v5);
  if ( idStr::Cmp(s1: v24.data, s2: "flags") != 0 )
  {
    if ( this->pragmaCallback != nullptr )
    {
      operator+(result: &v25, a: &v24, b: " ");
      if ( idParser::ReadLine(this, token: &v24, multiline: v12, a4: v11, a5: v10) )
      {
        do
        {
          v13 = operator+(result: v26, a: &v24, b: " ");
          idStr::Append(this: &v25, text: v13);
          idStr::FreeData(this: v26);
        }
        while ( idParser::ReadLine(this, token: &v24, multiline: v16, a4: v15, a5: v14) );
      }
      idStr::StripTrailing(this: &v25, string: " ");
      this->pragmaCallback(a1: this->pragmaData, a2: v25.data);
      idStr::FreeData(this: &v25);
    }
    else
    {
      HIDWORD(v9) = v24.data;
      idParser::Warning(
        this,
        str: "#pragma directive '%s' not supported",
        a3: v9,
        a4: v8,
        a5: v7,
        a6: v18,
        a7: v19,
        a8: v20,
        a9: v21,
        a10: v22,
        a11: v23);
    }
  }
  idStr::FreeData(this: &v24);
  return 1;
}


// ========================================================================
// __unwind$119330
// EA  : 0x82F90324
// RVA : 0x00F90324
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_119330()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$119331
// EA  : 0x82F9034C
// RVA : 0x00F9034C
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_119331()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 192));
}


// ========================================================================
// __unwind$119332
// EA  : 0x82F90374
// RVA : 0x00F90374
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_119332()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 224));
}


// ========================================================================
// ?Directive_evalint@idParser@@AAAHXZ
// EA  : 0x82F903A8
// RVA : 0x00F903A8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::Directive_evalint(idParser *this, int a2, int a3, int a4, __int64 a5)
{
  __int64 v5; // r10
  int v8; // r29
  __int64 v9; // [sp+50h] [-110h] BYREF
  idToken v10; // [sp+60h] [-100h] BYREF
  char v11[176]; // [sp+B0h] [-B0h] BYREF

  LODWORD(v5) = 20;
  HIDWORD(v5) = v10.baseBuffer;
  v10.len = 0;
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v10.floatvalue = -3.4028235e38;
  v10.baseBuffer[0] = 0;
  v10.intvalue = 0;
  memset(&v10.whiteSpaceStart_p, 0, 12);
  if ( idParser::EvaluateFunction(this, intvalue: (int *)&v9, integer: 1, a4: a5, a5: v5) != 0 )
  {
    v8 = HIDWORD(v9);
    v10.line = this->scriptstack->line;
    if ( v9 >= 0 )
    {
      v10.whiteSpaceEnd_p = idToken::DEFAULT_WHITESPACE + 1;
      v10.whiteSpaceStart_p = idToken::DEFAULT_WHITESPACE;
    }
    else
    {
      v10.whiteSpaceStart_p = nullptr;
      v10.whiteSpaceEnd_p = nullptr;
    }
    v10.linesCrossed = 0;
    v10.flags = 0;
    sprintf_0(string: v11, format: "%d", abs32(SHIDWORD(v9)));
    idStr::operator=(this: &v10, text: v11);
    v10.intvalue = abs32(v8);
    v9 = v10.intvalue | 0x1000000000000LL;
    v10.floatvalue = (float)v9;
    v10.type = 3;
    v10.subtype = 65571;
    idParser::UnreadSourceToken(this, token: &v10);
    if ( v8 < 0 )
      idParser::UnreadSignToken(this);
    idStr::FreeData(this: &v10);
    return 1;
  }
  else
  {
    idStr::FreeData(this: &v10);
    return 0;
  }
}


// ========================================================================
// __unwind$119434
// EA  : 0x82F904E8
// RVA : 0x00F904E8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_119434()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 96));
}


// ========================================================================
// ?Directive_evalfloat@idParser@@AAAHXZ
// EA  : 0x82F90518
// RVA : 0x00F90518
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::Directive_evalfloat(idParser *this, int a2, int a3, int a4, __int64 a5)
{
  __int64 v5; // r10
  __int64 v7; // r6
  double v9; // fp31
  double v10; // fp29
  double v11; // [sp+20h] [-150h]
  __int64 v12; // [sp+50h] [-120h] BYREF
  idToken v13; // [sp+60h] [-110h] BYREF
  char v14[136]; // [sp+B0h] [-C0h] BYREF

  LODWORD(v5) = 20;
  HIDWORD(v5) = v13.baseBuffer;
  v13.len = 0;
  v13.allocedAndFlag = 20;
  v13.data = v13.baseBuffer;
  v13.floatvalue = -3.4028235e38;
  v13.baseBuffer[0] = 0;
  v13.intvalue = 0;
  memset(&v13.whiteSpaceStart_p, 0, 12);
  LODWORD(v7) = 0;
  HIDWORD(v7) = &v12;
  if ( idParser::EvaluateFunction(this, intvalue: nullptr, integer: v7, a4: a5, a5: v5) != 0 )
  {
    v9 = *(double *)&v12;
    v13.line = this->scriptstack->line;
    if ( *(double *)&v12 >= 0.0 )
    {
      v13.whiteSpaceEnd_p = idToken::DEFAULT_WHITESPACE + 1;
      v13.whiteSpaceStart_p = idToken::DEFAULT_WHITESPACE;
    }
    else
    {
      v13.whiteSpaceStart_p = nullptr;
      v13.whiteSpaceEnd_p = nullptr;
    }
    v10 = (float)*(double *)&v12;
    *(float *)&v12 = *(double *)&v12;
    v13.linesCrossed = 0;
    v13.flags = 0;
    v11 = __fabs(v10);
    sprintf_0(string: v14, format: (const char *)HIDWORD(v11), LODWORD(v11));
    idStr::operator=(this: &v13, text: v14);
    v13.floatvalue = v11;
    v13.type = 3;
    v13.subtype = 65698;
    v12 = (__int64)v11;
    v13.intvalue = (__int64)v11;
    idParser::UnreadSourceToken(this, token: &v13);
    if ( v9 < 0.0 )
      idParser::UnreadSignToken(this);
    idStr::FreeData(this: &v13);
    return 1;
  }
  else
  {
    idStr::FreeData(this: &v13);
    return 0;
  }
}


// ========================================================================
// __unwind$119514
// EA  : 0x82F90684
// RVA : 0x00F90684
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_119514()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 96));
}


// ========================================================================
// ?DollarDirective_endif@idParser@@AAAHXZ
// EA  : 0x82F906B0
// RVA : 0x00F906B0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::DollarDirective_endif(idParser *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  idParser::indent_t *list; // r11
  idList<idParser::indent_t,11> *p_indentstack; // r3
  idParser::indent_t *v8; // r11
  int type; // r30
  int v11; // [sp+8h] [-78h]
  int v12; // [sp+Ch] [-74h]
  int v13; // [sp+10h] [-70h]
  int v14; // [sp+14h] [-6Ch]
  int v15; // [sp+18h] [-68h]
  int v16; // [sp+1Ch] [-64h]

  LODWORD(a5) = this->indentstack.num;
  if ( (_DWORD)a5 != 0 )
  {
    list = this->indentstack.list;
    HIDWORD(a5) = 16 * a5;
    LODWORD(a4) = this->scriptstack;
    p_indentstack = &this->indentstack;
    v8 = &list[a5];
    HIDWORD(a4) = v8[-1].script;
    if ( HIDWORD(a4) == (_DWORD)a4 )
    {
      type = v8[-1].type;
      this->skip -= v8[-1].skip;
      idList<parmValue_t,56>::SetNum(this: (idList<idPlane,37> *)p_indentstack, newNum: a5 - 1);
      if ( type != 0 )
        return 1;
    }
  }
  idParser::Error(this, str: "misplaced $endif", a3, a4, a5, a6: v11, a7: v12, a8: v13, a9: v14, a10: v15, a11: v16);
  return 0;
}


// ========================================================================
// ?PushIndent@idParser@@AAAXHHH@Z
// EA  : 0x82F90878
// RVA : 0x00F90878
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void __fastcall idParser::PushIndent(idParser *this, int type, int skip, int skipElse)
{
  aas2Cluster_t *v8; // r3
  int v9; // r11

  v8 = idList<idPlayerCoverScore_t,5>::Alloc(this: (idList<aas2Cluster_t,37> *)&this->indentstack);
  v8->numAreas = type;
  v8->firstPortal = (int)this->scriptstack;
  v9 = skip != 0;
  v8->numReachableAreas = v9;
  v8->numPortals = skipElse != 0;
  this->skip += v9;
}


// ========================================================================
// ?Directive_define@idParser@@AAAPAUdefine_t@1@_N@Z
// EA  : 0x82F908E0
// RVA : 0x00F908E0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

idParser::define_t *__fastcall idParser::Directive_define(
        idParser *this,
        int isTemplate,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v11; // r6
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  idParser::define_t *HashedDefine; // r3
  __int64 v18; // r8
  unsigned int v19; // r6
  int v20; // r5
  int v21; // r4
  idParser::define_t *v22; // r3
  idParser::define_t *v23; // r26
  const char *data; // r3
  __int64 v25; // r10
  __int64 v26; // r6
  __int64 v27; // r8
  idToken *v28; // r28
  __int64 v29; // r10
  __int64 v30; // r8
  __int64 v31; // r6
  __int64 v32; // r10
  __int64 v33; // r8
  __int64 v34; // r6
  __int64 v35; // r10
  __int64 v36; // r8
  __int64 v37; // r6
  __int64 v38; // r10
  __int64 v39; // r8
  __int64 v40; // r6
  idToken *v41; // r3
  idToken *v42; // r29
  __int64 v43; // r10
  __int64 v44; // r8
  __int64 v45; // r6
  __int64 v46; // r10
  __int64 v47; // r8
  __int64 v48; // r6
  __int64 v49; // r10
  __int64 v50; // r8
  __int64 v51; // r6
  idToken *v52; // r28
  __int64 v53; // r10
  __int64 v54; // r8
  __int64 v55; // r6
  idToken *v56; // r3
  idToken *v57; // r29
  __int64 v58; // r10
  __int64 v59; // r8
  __int64 v60; // r6
  __int64 v61; // r10
  __int64 v62; // r8
  __int64 v63; // r6
  __int64 v64; // r10
  __int64 v65; // r8
  __int64 v66; // r6
  int v67; // [sp+8h] [-188h]
  int v68; // [sp+Ch] [-184h]
  int v69; // [sp+10h] [-180h]
  int v70; // [sp+14h] [-17Ch]
  int v71; // [sp+18h] [-178h]
  int v72; // [sp+1Ch] [-174h]
  idToken v73; // [sp+70h] [-120h] BYREF
  idToken v74; // [sp+C0h] [-D0h] BYREF

  LODWORD(a5) = v73.baseBuffer;
  v73.len = 0;
  v73.allocedAndFlag = 20;
  v73.floatvalue = -3.4028235e38;
  v73.data = v73.baseBuffer;
  v73.baseBuffer[0] = 0;
  v73.intvalue = 0;
  memset(&v73.whiteSpaceStart_p, 0, 12);
  HIDWORD(a3) = isTemplate;
  if ( !idParser::ReadLine(this, token: &v73, multiline: a3, a4, a5) )
  {
    idParser::Error(
      this,
      str: "#define without name",
      a3: v9,
      a4: v8,
      a5: v7,
      a6: v67,
      a7: v68,
      a8: v69,
      a9: v70,
      a10: v71,
      a11: v72);
    idStr::FreeData(this: &v73);
    return nullptr;
  }
  if ( v73.type != 4 )
  {
    idParser::UnreadSourceToken(this, token: &v73);
    HIDWORD(v11) = v73.data;
    idParser::Error(
      this,
      str: "expected name after #define, found '%s'",
      a3: v11,
      a4: v13,
      a5: v12,
      a6: v67,
      a7: v68,
      a8: v69,
      a9: v70,
      a10: v71,
      a11: v72);
    idStr::FreeData(this: &v73);
    return nullptr;
  }
  HashedDefine = idParser::FindHashedDefine(this, name: v73.data);
  if ( HashedDefine != nullptr )
  {
    if ( HashedDefine->builtin != 0 )
    {
      HIDWORD(v16) = v73.data;
      idParser::Error(
        this,
        str: "can't redefine '%s'",
        a3: v16,
        a4: v15,
        a5: v14,
        a6: v67,
        a7: v68,
        a8: v69,
        a9: v70,
        a10: v71,
        a11: v72);
      idStr::FreeData(this: &v73);
      return nullptr;
    }
    HIDWORD(v16) = v73.data;
    idParser::Warning(
      this,
      str: "redefinition of '%s'",
      a3: v16,
      a4: v15,
      a5: v14,
      a6: v67,
      a7: v68,
      a8: v69,
      a9: v70,
      a10: v71,
      a11: v72);
    idParser::UnreadSourceToken(this, token: &v73);
    if ( idParser::Directive_undef(this, a2: v21, a3: v20, a4: v19, a5: v18) == 0 )
    {
      idStr::FreeData(this: &v73);
      return nullptr;
    }
    idParser::FindHashedDefine(this, name: v73.data);
  }
  v22 = (idParser::define_t *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x3Cu,
                                tag: TAG_LEXER,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v22 != nullptr )
  {
    v22->name.allocedAndFlag = 20;
    v22->name.len = 0;
    v23 = v22;
    v22->name.data = v22->name.baseBuffer;
    v22->name.baseBuffer[0] = 0;
    v22->builtin = 0;
    v22->numparms = 0;
    v22->parms = nullptr;
    v22->tokens = nullptr;
    v22->next = nullptr;
    v22->hashnext = nullptr;
  }
  else
  {
    v23 = nullptr;
  }
  idStr::operator=(this: &v23->name, text: &v73);
  data = v23->name.data;
  v23->scope = this->defineScope;
  LODWORD(v25) = PC_NameHash(name: data) + 23;
  HIDWORD(v26) = isTemplate;
  HIDWORD(v25) = *((_DWORD *)&this->loaded + v25);
  v23->hashnext = (idParser::define_t *)HIDWORD(v25);
  *((_DWORD *)&this->loaded + v25) = v23;
  if ( !idParser::ReadLine(this, token: &v73, multiline: v26, a4: v27, a5: v25) )
    goto LABEL_61;
  if ( v73.whiteSpaceEnd_p <= v73.whiteSpaceStart_p && idStr::Cmp(s1: v73.data, s2: "(") == 0 )
  {
    v28 = nullptr;
    if ( idParser::CheckTokenString(this, string: ")") == 0 )
    {
      HIDWORD(v31) = isTemplate;
      if ( !idParser::ReadLine(this, token: &v73, multiline: v31, a4: v30, a5: v29) )
      {
LABEL_32:
        idParser::Error(
          this,
          str: "expected define parameter",
          a3: v34,
          a4: v33,
          a5: v32,
          a6: v67,
          a7: v68,
          a8: v69,
          a9: v70,
          a10: v71,
          a11: v72);
        idStr::FreeData(this: &v73);
        return nullptr;
      }
      while ( 1 )
      {
        if ( v73.type != 4 && idStr::Cmp(s1: v73.data, s2: "...") != 0 )
        {
          idParser::Error(
            this,
            str: "invalid define parameter",
            a3: v37,
            a4: v36,
            a5: v35,
            a6: v67,
            a7: v68,
            a8: v69,
            a9: v70,
            a10: v71,
            a11: v72);
          idStr::FreeData(this: &v73);
          return nullptr;
        }
        if ( idParser::FindDefineParm(this, define: v23, name: v73.data) >= 0 )
        {
          idParser::Error(
            this,
            str: "two the same define parameters",
            a3: v40,
            a4: v39,
            a5: v38,
            a6: v67,
            a7: v68,
            a8: v69,
            a9: v70,
            a10: v71,
            a11: v72);
          idStr::FreeData(this: &v73);
          return nullptr;
        }
        v41 = (idToken *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x48u,
                           tag: TAG_LEXER,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
        if ( v41 != nullptr )
        {
          v41->allocedAndFlag = 20;
          v41->len = 0;
          v42 = v41;
          v41->data = v41->baseBuffer;
          v41->baseBuffer[0] = 0;
          v41->floatvalue = -3.4028235e38;
          v41->intvalue = 0;
          v41->whiteSpaceStart_p = nullptr;
          v41->whiteSpaceEnd_p = nullptr;
          v41->next = nullptr;
        }
        else
        {
          v42 = nullptr;
        }
        idToken::operator=(this: v42, __that: &v73);
        idToken::SetSafeWhiteSpacePointers(this: v42);
        v42->next = nullptr;
        if ( v28 != nullptr )
          v28->next = v42;
        else
          v23->parms = v42;
        HIDWORD(v45) = isTemplate;
        ++v23->numparms;
        v28 = v42;
        if ( !idParser::ReadLine(this, token: &v73, multiline: v45, a4: v44, a5: v43) )
        {
          idParser::Error(
            this,
            str: "define parameters not terminated",
            a3: v48,
            a4: v47,
            a5: v46,
            a6: v67,
            a7: v68,
            a8: v69,
            a9: v70,
            a10: v71,
            a11: v72);
          idStr::FreeData(this: &v73);
          return nullptr;
        }
        if ( idStr::Cmp(s1: v73.data, s2: ")") == 0 )
          break;
        if ( idStr::Cmp(s1: v73.data, s2: ",") != 0 )
        {
          idParser::Error(
            this,
            str: "define not terminated ( missing comma )",
            a3: v51,
            a4: v50,
            a5: v49,
            a6: v67,
            a7: v68,
            a8: v69,
            a9: v70,
            a10: v71,
            a11: v72);
          idStr::FreeData(this: &v73);
          return nullptr;
        }
        HIDWORD(v51) = isTemplate;
        if ( !idParser::ReadLine(this, token: &v73, multiline: v51, a4: v50, a5: v49) )
          goto LABEL_32;
      }
    }
    HIDWORD(v31) = isTemplate;
    if ( !idParser::ReadLine(this, token: &v73, multiline: v31, a4: v30, a5: v29) )
      goto LABEL_61;
  }
  v52 = nullptr;
  while ( (_BYTE)isTemplate == 0
       || v73.type != 5
       || idStr::Cmp(s1: v73.data, s2: "#") != 0 && idStr::Cmp(s1: v73.data, s2: "$") != 0 )
  {
LABEL_45:
    v56 = (idToken *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x48u,
                       tag: TAG_LEXER,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
    if ( v56 != nullptr )
    {
      v56->allocedAndFlag = 20;
      v56->len = 0;
      v57 = v56;
      v56->data = v56->baseBuffer;
      v56->baseBuffer[0] = 0;
      v56->floatvalue = -3.4028235e38;
      v56->intvalue = 0;
      v56->whiteSpaceStart_p = nullptr;
      v56->whiteSpaceEnd_p = nullptr;
      v56->next = nullptr;
    }
    else
    {
      v57 = nullptr;
    }
    idToken::operator=(this: v57, __that: &v73);
    if ( v57->type == 4 && idStr::Cmp(s1: v57->data, s2: v23->name.data) == 0 )
    {
      LODWORD(v58) = v57->flags | 1;
      v57->flags = v58;
      HIDWORD(v60) = v23->name.data;
      idParser::Warning(
        this,
        str: "recursive define of '%s' (removed recursion)",
        a3: v60,
        a4: v59,
        a5: v58,
        a6: v67,
        a7: v68,
        a8: v69,
        a9: v70,
        a10: v71,
        a11: v72);
    }
    idToken::SetSafeWhiteSpacePointers(this: v57);
    v57->next = nullptr;
    if ( v52 != nullptr )
      v52->next = v57;
    else
      v23->tokens = v57;
    HIDWORD(v63) = isTemplate;
    v52 = v57;
    if ( !idParser::ReadLine(this, token: &v73, multiline: v63, a4: v62, a5: v61) )
      goto LABEL_57;
  }
  v74.floatvalue = -3.4028235e38;
  v74.allocedAndFlag = 20;
  v74.data = v74.baseBuffer;
  v74.len = 0;
  v74.baseBuffer[0] = 0;
  v74.intvalue = 0;
  memset(&v74.whiteSpaceStart_p, 0, 12);
  HIDWORD(v55) = isTemplate;
  idParser::ReadLine(this, token: &v74, multiline: v55, a4: v54, a5: v53);
  if ( idStr::Cmp(s1: v74.data, s2: "endtemplate") != 0 )
  {
    idParser::UnreadSourceToken(this, token: &v74);
    idStr::FreeData(this: &v74);
    goto LABEL_45;
  }
  idStr::FreeData(this: &v74);
LABEL_57:
  if ( v52 != nullptr && (idStr::Cmp(s1: v23->tokens->data, s2: "##") == 0 || idStr::Cmp(s1: v52->data, s2: "##") == 0) )
  {
    idParser::Error(
      this,
      str: "define with misplaced ##",
      a3: v66,
      a4: v65,
      a5: v64,
      a6: v67,
      a7: v68,
      a8: v69,
      a9: v70,
      a10: v71,
      a11: v72);
    idStr::FreeData(this: &v73);
    return nullptr;
  }
LABEL_61:
  idStr::FreeData(this: &v73);
  return v23;
}


// ========================================================================
// __unwind$119691
// EA  : 0x82F90F6C
// RVA : 0x00F90F6C
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_119691()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 112));
}


// ========================================================================
// __unwind$119694
// EA  : 0x82F90F94
// RVA : 0x00F90F94
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_119694()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 192));
}


// ========================================================================
// ?Directive_if_def@idParser@@AAAHH@Z
// EA  : 0x82F90FC8
// RVA : 0x00F90FC8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::Directive_if_def(idParser *this, int type, int a3, unsigned int a4, __int64 a5)
{
  __int64 v5; // r10
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v12; // r6
  __int64 v13; // r10
  __int64 v14; // r8
  BOOL v15; // r5
  int v16; // [sp+8h] [-D8h]
  int v17; // [sp+Ch] [-D4h]
  int v18; // [sp+10h] [-D0h]
  int v19; // [sp+14h] [-CCh]
  int v20; // [sp+18h] [-C8h]
  int v21; // [sp+1Ch] [-C4h]
  idToken v22; // [sp+70h] [-70h] BYREF

  LODWORD(v5) = byte_821B0000;
  HIDWORD(v5) = 20;
  LODWORD(a5) = v22.baseBuffer;
  v22.len = 0;
  v22.allocedAndFlag = 20;
  v22.floatvalue = -3.4028235e38;
  v22.data = v22.baseBuffer;
  v22.baseBuffer[0] = 0;
  v22.intvalue = 0;
  memset(&v22.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadLine(this, token: &v22, multiline: a4, a4: a5, a5: v5) )
  {
    if ( v22.type == 4 )
    {
      v15 = (_cntlzw(
               ((_cntlzw((unsigned int)idParser::FindHashedDefine(this, name: v22.data)) & 0x20) != 0)
             - ((_cntlzw(type - 8) & 0x20) != 0))
           & 0x20) != 0;
      idParser::PushIndent(this, type, skip: v15, skipElse: (_cntlzw(v15) & 0x20) != 0);
      idStr::FreeData(this: &v22);
      return 1;
    }
    else
    {
      idParser::UnreadSourceToken(this, token: &v22);
      HIDWORD(v12) = v22.data;
      idParser::Error(
        this,
        str: "expected name after #ifdef, found '%s'",
        a3: v12,
        a4: v14,
        a5: v13,
        a6: v16,
        a7: v17,
        a8: v18,
        a9: v19,
        a10: v20,
        a11: v21);
      idStr::FreeData(this: &v22);
      return 0;
    }
  }
  else
  {
    idParser::Error(
      this,
      str: "#ifdef without name",
      a3: v10,
      a4: v9,
      a5: v8,
      a6: v16,
      a7: v17,
      a8: v18,
      a9: v19,
      a10: v20,
      a11: v21);
    idStr::FreeData(this: &v22);
    return 0;
  }
}


// ========================================================================
// __unwind$120161
// EA  : 0x82F910D8
// RVA : 0x00F910D8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_120161()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?Directive_else@idParser@@AAAHXZ
// EA  : 0x82F91100
// RVA : 0x00F91100
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::Directive_else(idParser *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  idList<idParser::indent_t,11> *p_indentstack; // r30
  idParser::indent_t *v7; // r11
  int type; // r28
  int skipElse; // r29
  aas2Cluster_t *v11; // r3
  int v12; // r11
  int v13; // [sp+8h] [-88h]
  int v14; // [sp+Ch] [-84h]
  int v15; // [sp+10h] [-80h]
  int v16; // [sp+14h] [-7Ch]
  int v17; // [sp+18h] [-78h]
  int v18; // [sp+1Ch] [-74h]

  LODWORD(a5) = this->indentstack.num;
  if ( (_DWORD)a5 == 0 )
    goto LABEL_4;
  HIDWORD(a5) = 16 * a5;
  LODWORD(a4) = this->scriptstack;
  p_indentstack = &this->indentstack;
  v7 = &this->indentstack.list[a5];
  HIDWORD(a4) = v7[-1].script;
  if ( HIDWORD(a4) != (_DWORD)a4 )
    goto LABEL_4;
  type = v7[-1].type;
  skipElse = v7[-1].skipElse;
  this->skip -= v7[-1].skip;
  idList<parmValue_t,56>::SetNum(this: (idList<idPlane,37> *)&this->indentstack, newNum: a5 - 1);
  if ( type != 0 )
  {
    if ( type == 2 )
    {
      idParser::Error(
        this,
        str: "#else after #else",
        a3,
        a4,
        a5,
        a6: v13,
        a7: v14,
        a8: v15,
        a9: v16,
        a10: v17,
        a11: v18);
      return 0;
    }
    else
    {
      v11 = idList<idPlayerCoverScore_t,5>::Alloc(this: (idList<aas2Cluster_t,37> *)p_indentstack);
      v12 = skipElse != 0;
      v11->numAreas = 2;
      v11->firstPortal = (int)this->scriptstack;
      v11->numReachableAreas = v12;
      v11->numPortals = 1;
      this->skip += v12;
      return 1;
    }
  }
  else
  {
LABEL_4:
    idParser::Error(this, str: "misplaced #else", a3, a4, a5, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
    return 0;
  }
}


// ========================================================================
// ?Directive_if@idParser@@AAAHXZ
// EA  : 0x82F911F0
// RVA : 0x00F911F0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::Directive_if(idParser *this, int a2, int a3, int a4, __int64 a5, __int64 a6)
{
  int skip; // r11
  int result; // r3
  unsigned int v9; // r30
  aas2Cluster_t *v10; // r3
  int v11; // r11
  unsigned int v12; // [sp+50h] [-20h] BYREF

  skip = this->skip;
  LODWORD(a6) = 0;
  v12 = 0;
  if ( skip != 0 )
  {
    v9 = 1;
  }
  else
  {
    result = idParser::Evaluate(this, intvalue: (int *)&v12, floatvalue: nullptr, integer: 1, a5, a6);
    if ( result == 0 )
      return result;
    v9 = (_cntlzw(v12) & 0x20) != 0;
  }
  v10 = idList<idPlayerCoverScore_t,5>::Alloc(this: (idList<aas2Cluster_t,37> *)&this->indentstack);
  v11 = v9 != 0;
  v10->numAreas = 1;
  v10->firstPortal = (int)this->scriptstack;
  v10->numReachableAreas = v11;
  v10->numPortals = (_cntlzw(v9) & 0x20) != 0;
  this->skip += v11;
  return 1;
}


// ========================================================================
// ?Directive_elif@idParser@@AAAHXZ
// EA  : 0x82F912A8
// RVA : 0x00F912A8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::Directive_elif(idParser *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  idList<idParser::indent_t,11> *p_indentstack; // r3
  int v7; // r11
  int v8; // r30
  int v9; // r29
  int v10; // r5
  int v11; // r6
  int v13; // [sp+8h] [-88h]
  int v14; // [sp+Ch] [-84h]
  int v15; // [sp+10h] [-80h]
  int v16; // [sp+14h] [-7Ch]
  int v17; // [sp+18h] [-78h]
  int v18; // [sp+1Ch] [-74h]
  int v19; // [sp+60h] [-30h] BYREF

  LODWORD(a5) = this->indentstack.num;
  v19 = 0;
  if ( (_DWORD)a5 == 0 )
    goto LABEL_13;
  HIDWORD(a5) = this->indentstack.list;
  LODWORD(a4) = this->scriptstack;
  p_indentstack = &this->indentstack;
  v7 = 16 * a5 + HIDWORD(a5);
  HIDWORD(a4) = *(_DWORD *)(v7 - 4);
  if ( HIDWORD(a4) != (_DWORD)a4 )
    goto LABEL_13;
  v8 = *(_DWORD *)(v7 - 16);
  v9 = *(_DWORD *)(v7 - 8);
  this->skip -= *(_DWORD *)(v7 - 12);
  idList<parmValue_t,56>::SetNum(this: (idList<idPlane,37> *)p_indentstack, newNum: a5 - 1);
  if ( v8 != 0 && v8 != 2 )
  {
    if ( this->skip != 0 )
      goto LABEL_10;
    if ( idParser::Evaluate(this, intvalue: &v19, floatvalue: nullptr, integer: 1, a5: a4, a6: a5) != 0 )
    {
      if ( v9 == 0 && v19 != 0 )
      {
        v10 = 0;
        goto LABEL_11;
      }
LABEL_10:
      v10 = 1;
      v11 = 0;
      if ( v9 == 0 )
      {
LABEL_12:
        idParser::PushIndent(this, type: 4, skip: v10, skipElse: v11);
        return 1;
      }
LABEL_11:
      v11 = 1;
      goto LABEL_12;
    }
  }
  else
  {
LABEL_13:
    idParser::Error(this, str: "misplaced #elif", a3, a4, a5, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
  }
  return 0;
}


// ========================================================================
// ?DollarDirective_if_def@idParser@@AAAHH@Z
// EA  : 0x82F913B0
// RVA : 0x00F913B0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::DollarDirective_if_def(idParser *this, int type, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v11; // r6
  __int64 v12; // r10
  __int64 v13; // r8
  BOOL v14; // r5
  int v15; // [sp+8h] [-D8h]
  int v16; // [sp+Ch] [-D4h]
  int v17; // [sp+10h] [-D0h]
  int v18; // [sp+14h] [-CCh]
  int v19; // [sp+18h] [-C8h]
  int v20; // [sp+1Ch] [-C4h]
  idToken v21; // [sp+70h] [-70h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v21.baseBuffer;
  v21.len = 0;
  v21.allocedAndFlag = 20;
  v21.floatvalue = -3.4028235e38;
  v21.data = v21.baseBuffer;
  v21.baseBuffer[0] = 0;
  v21.intvalue = 0;
  memset(&v21.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadSourceToken(this, token: &v21, a3, a4, a5: v4) != 0 )
  {
    if ( v21.type == 4 )
    {
      v14 = (_cntlzw(
               ((_cntlzw((unsigned int)idParser::FindHashedDefine(this, name: v21.data)) & 0x20) != 0)
             - ((_cntlzw(type - 8) & 0x20) != 0))
           & 0x20) != 0;
      idParser::PushIndent(this, type, skip: v14, skipElse: (_cntlzw(v14) & 0x20) != 0);
      idStr::FreeData(this: &v21);
      return 1;
    }
    else
    {
      idParser::UnreadSourceToken(this, token: &v21);
      HIDWORD(v11) = v21.data;
      idParser::Error(
        this,
        str: "expected name after $ifdef, found '%s'",
        a3: v11,
        a4: v13,
        a5: v12,
        a6: v15,
        a7: v16,
        a8: v17,
        a9: v18,
        a10: v19,
        a11: v20);
      idStr::FreeData(this: &v21);
      return 0;
    }
  }
  else
  {
    idParser::Error(
      this,
      str: "$ifdef without name",
      a3: v9,
      a4: v8,
      a5: v7,
      a6: v15,
      a7: v16,
      a8: v17,
      a9: v18,
      a10: v19,
      a11: v20);
    idStr::FreeData(this: &v21);
    return 0;
  }
}


// ========================================================================
// __unwind$120351_0
// EA  : 0x82F914BC
// RVA : 0x00F914BC
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_120351_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?DollarDirective_else@idParser@@AAAHXZ
// EA  : 0x82F914E8
// RVA : 0x00F914E8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::DollarDirective_else(idParser *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  idList<idParser::indent_t,11> *p_indentstack; // r30
  idParser::indent_t *v7; // r11
  int type; // r28
  int skipElse; // r29
  aas2Cluster_t *v11; // r3
  int v12; // r11
  int v13; // [sp+8h] [-88h]
  int v14; // [sp+Ch] [-84h]
  int v15; // [sp+10h] [-80h]
  int v16; // [sp+14h] [-7Ch]
  int v17; // [sp+18h] [-78h]
  int v18; // [sp+1Ch] [-74h]

  LODWORD(a5) = this->indentstack.num;
  if ( (_DWORD)a5 == 0 )
    goto LABEL_4;
  HIDWORD(a5) = 16 * a5;
  LODWORD(a4) = this->scriptstack;
  p_indentstack = &this->indentstack;
  v7 = &this->indentstack.list[a5];
  HIDWORD(a4) = v7[-1].script;
  if ( HIDWORD(a4) != (_DWORD)a4 )
    goto LABEL_4;
  type = v7[-1].type;
  skipElse = v7[-1].skipElse;
  this->skip -= v7[-1].skip;
  idList<parmValue_t,56>::SetNum(this: (idList<idPlane,37> *)&this->indentstack, newNum: a5 - 1);
  if ( type != 0 )
  {
    if ( type == 2 )
    {
      idParser::Error(
        this,
        str: "$else after $else",
        a3,
        a4,
        a5,
        a6: v13,
        a7: v14,
        a8: v15,
        a9: v16,
        a10: v17,
        a11: v18);
      return 0;
    }
    else
    {
      v11 = idList<idPlayerCoverScore_t,5>::Alloc(this: (idList<aas2Cluster_t,37> *)p_indentstack);
      v12 = skipElse != 0;
      v11->numAreas = 2;
      v11->firstPortal = (int)this->scriptstack;
      v11->numReachableAreas = v12;
      v11->numPortals = 1;
      this->skip += v12;
      return 1;
    }
  }
  else
  {
LABEL_4:
    idParser::Error(this, str: "misplaced $else", a3, a4, a5, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
    return 0;
  }
}


// ========================================================================
// ?DollarDirective_elif@idParser@@AAAHXZ
// EA  : 0x82F915D8
// RVA : 0x00F915D8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::DollarDirective_elif(idParser *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  idList<idParser::indent_t,11> *p_indentstack; // r3
  int v7; // r11
  int v8; // r30
  int v9; // r29
  int v10; // r5
  int v11; // r6
  int v13; // [sp+8h] [-88h]
  int v14; // [sp+Ch] [-84h]
  int v15; // [sp+10h] [-80h]
  int v16; // [sp+14h] [-7Ch]
  int v17; // [sp+18h] [-78h]
  int v18; // [sp+1Ch] [-74h]
  int v19; // [sp+60h] [-30h] BYREF

  LODWORD(a5) = this->indentstack.num;
  v19 = 0;
  if ( (_DWORD)a5 == 0 )
    goto LABEL_13;
  HIDWORD(a5) = this->indentstack.list;
  LODWORD(a4) = this->scriptstack;
  p_indentstack = &this->indentstack;
  v7 = 16 * a5 + HIDWORD(a5);
  HIDWORD(a4) = *(_DWORD *)(v7 - 4);
  if ( HIDWORD(a4) != (_DWORD)a4 )
    goto LABEL_13;
  v8 = *(_DWORD *)(v7 - 16);
  v9 = *(_DWORD *)(v7 - 8);
  this->skip -= *(_DWORD *)(v7 - 12);
  idList<parmValue_t,56>::SetNum(this: (idList<idPlane,37> *)p_indentstack, newNum: a5 - 1);
  if ( v8 != 0 && v8 != 2 )
  {
    if ( this->skip != 0 )
      goto LABEL_10;
    if ( idParser::Evaluate(this, intvalue: &v19, floatvalue: nullptr, integer: 1, a5: a4, a6: a5) != 0 )
    {
      if ( v9 == 0 && v19 != 0 )
      {
        v10 = 0;
        goto LABEL_11;
      }
LABEL_10:
      v10 = 1;
      v11 = 0;
      if ( v9 == 0 )
      {
LABEL_12:
        idParser::PushIndent(this, type: 4, skip: v10, skipElse: v11);
        return 1;
      }
LABEL_11:
      v11 = 1;
      goto LABEL_12;
    }
  }
  else
  {
LABEL_13:
    idParser::Error(this, str: "misplaced $elif", a3, a4, a5, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
  }
  return 0;
}


// ========================================================================
// ?ReadDollarDirective@idParser@@AAAHXZ
// EA  : 0x82F916E0
// RVA : 0x00F916E0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::ReadDollarDirective(idParser *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  __int64 v6; // r10
  __int64 v7; // r8
  int v8; // r6
  int v9; // r5
  int v10; // r4
  int v11; // r30
  __int64 v13; // r8
  __int64 v14; // r6
  int v15; // r30
  __int64 v16; // r8
  __int64 v17; // r6
  int v18; // r30
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  int v22; // r4
  int v23; // r30
  __int64 v24; // r10
  __int64 v25; // r8
  __int64 v26; // r6
  int v27; // r4
  int v28; // r30
  __int64 v29; // r10
  __int64 v30; // r8
  __int64 v31; // r6
  int v32; // r4
  int v33; // r30
  __int64 v34; // r8
  int v35; // r6
  int v36; // r5
  int v37; // r4
  int v38; // r30
  __int64 v39; // r8
  int v40; // r6
  int v41; // r5
  int v42; // r4
  int v43; // r30
  __int64 v44; // r10
  __int64 v45; // r8
  __int64 v46; // r6
  BOOL v47; // r30
  idToken v48; // [sp+50h] [-60h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v48.baseBuffer;
  v48.len = 0;
  v48.allocedAndFlag = 20;
  v48.data = v48.baseBuffer;
  v48.floatvalue = -3.4028235e38;
  v48.baseBuffer[0] = 0;
  v48.intvalue = 0;
  memset(&v48.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadSourceToken(this, token: &v48, a3, a4, a5: v4) == 0 || v48.linesCrossed > 0 || v48.type != 4 )
    goto LABEL_26;
  if ( idStr::Cmp(s1: v48.data, s2: "if") == 0 )
  {
    v11 = idParser::Directive_if(this, a2: v10, a3: v9, a4: v8, a5: v7, a6: v6);
    idStr::FreeData(this: &v48);
    return v11;
  }
  if ( idStr::Cmp(s1: v48.data, s2: "ifdef") == 0 )
  {
    v15 = idParser::DollarDirective_if_def(this, type: 8, a3: v14, a4: v13);
    idStr::FreeData(this: &v48);
    return v15;
  }
  if ( idStr::Cmp(s1: v48.data, s2: "ifndef") == 0 )
  {
    v18 = idParser::DollarDirective_if_def(this, type: 16, a3: v17, a4: v16);
    idStr::FreeData(this: &v48);
    return v18;
  }
  if ( idStr::Cmp(s1: v48.data, s2: "elif") == 0 )
  {
    v23 = idParser::DollarDirective_elif(this, a2: v22, a3: v21, a4: v20, a5: v19);
    idStr::FreeData(this: &v48);
    return v23;
  }
  if ( idStr::Cmp(s1: v48.data, s2: "else") == 0 )
  {
    v28 = idParser::DollarDirective_else(this, a2: v27, a3: v26, a4: v25, a5: v24);
    idStr::FreeData(this: &v48);
    return v28;
  }
  if ( idStr::Cmp(s1: v48.data, s2: "endif") == 0 )
  {
    v33 = idParser::DollarDirective_endif(this, a2: v32, a3: v31, a4: v30, a5: v29);
    idStr::FreeData(this: &v48);
    return v33;
  }
  if ( idStr::Cmp(s1: v48.data, s2: "break") == 0 || this->skip > 0 )
  {
    idStr::FreeData(this: &v48);
    return 1;
  }
  if ( idStr::Cmp(s1: v48.data, s2: "evalint") == 0 )
  {
    v38 = idParser::Directive_evalint(this, a2: v37, a3: v36, a4: v35, a5: v34);
    idStr::FreeData(this: &v48);
    return v38;
  }
  if ( idStr::Cmp(s1: v48.data, s2: "evalfloat") == 0 )
  {
    v43 = idParser::Directive_evalfloat(this, a2: v42, a3: v41, a4: v40, a5: v39);
    idStr::FreeData(this: &v48);
    return v43;
  }
  if ( idStr::Cmp(s1: v48.data, s2: "template") == 0 )
  {
    v47 = idParser::Directive_define(this, isTemplate: 1, a3: v46, a4: v45, a5: v44) != nullptr;
    idStr::FreeData(this: &v48);
    return v47;
  }
  else
  {
LABEL_26:
    idParser::UnreadSourceToken(this, token: &v48);
    idStr::FreeData(this: &v48);
    return 0;
  }
}


// ========================================================================
// __unwind$120552
// EA  : 0x82F919D4
// RVA : 0x00F919D4
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_120552()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ??0idParser@@QAA@H@Z
// EA  : 0x82F91AD8
// RVA : 0x00F91AD8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

idParser *__fastcall idParser::idParser(idParser *this, int flags)
{
  this->filename.len = 0;
  this->filename.allocedAndFlag = 20;
  this->filename.data = this->filename.baseBuffer;
  this->filename.baseBuffer[0] = 0;
  this->includepath.allocedAndFlag = 20;
  this->includepath.len = 0;
  this->includepath.data = this->includepath.baseBuffer;
  this->includepath.baseBuffer[0] = 0;
  this->indentstack.list = nullptr;
  this->indentstack.granularity = 0;
  this->indentstack.memTag = 11;
  this->indentstack.listStatic = 0;
  this->indentstack.size = 0;
  this->indentstack.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->indentstack);
  this->dependencies.granularity = 0;
  this->dependencies.memTag = 11;
  this->dependencies.listStatic = 0;
  this->dependencies.list = nullptr;
  this->dependencies.size = 0;
  this->dependencies.num = 0;
  this->defineScope = 0;
  memset(Dst: this->definehash, Val: 0, Size: sizeof(this->definehash));
  this->flags = flags;
  this->loaded = false;
  this->OSPath = false;
  this->punctuations = nullptr;
  this->scriptstack = nullptr;
  this->tokens = nullptr;
  this->skip = 0;
  this->pragmaCallback = nullptr;
  this->pragmaData = nullptr;
  this->hadError = false;
  this->hadWarning = false;
  this->includeLevel = 1;
  return this;
}


// ========================================================================
// __unwind$120820
// EA  : 0x82F91BC4
// RVA : 0x00F91BC4
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_120820()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 4));
}


// ========================================================================
// __unwind$120821
// EA  : 0x82F91BF0
// RVA : 0x00F91BF0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_120821()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 36));
}


// ========================================================================
// __unwind$120822
// EA  : 0x82F91C1C
// RVA : 0x00F91C1C
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_120822()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 604));
}


// ========================================================================
// ??1idParser@@QAA@XZ
// EA  : 0x82F91C50
// RVA : 0x00F91C50
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void __fastcall idParser::~idParser(idParser *this)
{
  char *list; // r3

  idParser::FreeSource(this);
  this->pragmaCallback = nullptr;
  this->pragmaData = nullptr;
  this->punctuations = nullptr;
  if ( this->dependencies.listStatic == 0 || this->dependencies.listStatic == 2 )
  {
    list = (char *)this->dependencies.list;
    if ( list != nullptr )
      idListArrayDelete<idSpawnRenderParm>(ptr: list, num: this->dependencies.size);
    this->dependencies.list = nullptr;
    this->dependencies.size = 0;
  }
  this->dependencies.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->indentstack);
  idStr::FreeData(this: &this->includepath);
  idStr::FreeData(this: &this->filename);
}


// ========================================================================
// __unwind$120914
// EA  : 0x82F91CD0
// RVA : 0x00F91CD0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_120914()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$120915
// EA  : 0x82F91CFC
// RVA : 0x00F91CFC
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_120915()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// __unwind$120916
// EA  : 0x82F91D28
// RVA : 0x00F91D28
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_120916()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 604));
}


// ========================================================================
// __unwind$120917
// EA  : 0x82F91D54
// RVA : 0x00F91D54
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_120917()
{
  int v0; // r12

  idList<idSpawnRenderParm,5>::Clear(this: (idList<idRenderParm,5> *)(*(_DWORD *)(v0 - 112 + 132) + 640));
}


// ========================================================================
// ?DefineFromString@idParser@@CAPAUdefine_t@1@PBD@Z
// EA  : 0x82F91D88
// RVA : 0x00F91D88
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

idParser::define_t *__fastcall idParser::DefineFromString(const char *string)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  idParser::define_t *v9; // r4
  idParser::define_t *v10; // r30
  idParser v11; // [sp+50h] [-2B0h] BYREF

  idParser::idParser(this: &v11, flags: 0);
  HIDWORD(v4) = 0;
  if ( *string != 0 )
  {
    do
      ++HIDWORD(v4);
    while ( string[HIDWORD(v4)] != 0 );
  }
  LODWORD(v4) = "*defineString";
  LODWORD(v5) = (unsigned __int8)idParser::LoadMemory(this: &v11, ptr: string, name: v4, a4: v3, a5: v2);
  if ( (_DWORD)v5 != 0 )
  {
    v9 = idParser::Directive_define(this: &v11, isTemplate: 0, a3: v7, a4: v6, a5: v5);
    if ( v9 != nullptr )
    {
      v10 = idParser::CopyDefine(this: &v11, define: v9);
      idParser::FreeSource(this: &v11);
      idParser::~idParser(this: &v11);
      return v10;
    }
    else
    {
      idParser::FreeSource(this: &v11);
      idParser::~idParser(this: &v11);
      return nullptr;
    }
  }
  else
  {
    idParser::~idParser(this: &v11);
    return nullptr;
  }
}


// ========================================================================
// __unwind$120983
// EA  : 0x82F91E68
// RVA : 0x00F91E68
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_120983()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 768 + 80));
}


// ========================================================================
// ?AddDependency@idParser@@AAAXHPBD@Z
// EA  : 0x82F91E90
// RVA : 0x00F91E90
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void __fastcall idParser::AddDependency(idParser *this, int includeLevel, const char *fileName)
{
  int v6; // r29
  int v7; // r30
  idParser::idDependency *v8; // r11
  idList<idParser::idDependency,11> *p_dependencies; // r31
  int num; // r11
  int size; // r10
  idParser::idDependency *list; // r10
  int v13; // r11

  v6 = 0;
  if ( this->dependencies.num <= 0 )
  {
LABEL_6:
    p_dependencies = &this->dependencies;
    idList<idParser::idDependency,11>::PreAllocateWithGranularity(
      this: p_dependencies,
      newSize: p_dependencies->num + 1);
    num = p_dependencies->num;
    size = p_dependencies->size;
    if ( num >= size )
    {
      v13 = (int)&p_dependencies->list[size - 1];
    }
    else
    {
      list = p_dependencies->list;
      p_dependencies->num = num + 1;
      v13 = (int)&list[num];
    }
    *(_DWORD *)v13 = includeLevel;
    idStr::operator=(this: (idStr *)(v13 + 4), text: fileName);
  }
  else
  {
    v7 = 0;
    while ( 1 )
    {
      v8 = &this->dependencies.list[v7];
      if ( v8->includeLevel == includeLevel && idStr::IcmpPath(s1: v8->fileName.data, s2: fileName) == 0 )
        break;
      ++v6;
      ++v7;
      if ( v6 >= this->dependencies.num )
        goto LABEL_6;
    }
  }
}


// ========================================================================
// ?AddDefine@idParser@@QAAHPBD@Z
// EA  : 0x82F91F70
// RVA : 0x00F91F70
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::AddDefine(idParser *this, const char *string)
{
  int result; // r3
  int v4; // r31
  const char *v5; // r3
  int v6; // r11

  result = (int)idParser::DefineFromString(string);
  v4 = result;
  if ( result != 0 )
  {
    v5 = *(const char **)(result + 4);
    *(_DWORD *)(v4 + 32) = this->defineScope;
    v6 = 4 * (PC_NameHash(name: v5) + 23);
    *(_DWORD *)(v4 + 56) = *(_DWORD *)(&this->loaded + v6);
    *(_DWORD *)(&this->loaded + v6) = v4;
    return 1;
  }
  return result;
}


// ========================================================================
// ?PushScript@idParser@@AAA_NPAVidLexer@@@Z
// EA  : 0x82F91FE0
// RVA : 0x00F91FE0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::PushScript(idParser *this, idLexer *script)
{
  idLexer *scriptstack; // r29
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  char *data; // r5
  int v10; // [sp+8h] [-488h]
  int v11; // [sp+Ch] [-484h]
  int v12; // [sp+10h] [-480h]
  int v13; // [sp+14h] [-47Ch]
  int v14; // [sp+18h] [-478h]
  int v15; // [sp+1Ch] [-474h]
  _BYTE v16[1056]; // [sp+70h] [-420h] BYREF

  scriptstack = this->scriptstack;
  if ( scriptstack != nullptr )
  {
    while ( idStr::Icmp(s1: scriptstack->filename.data, s2: script->filename.data) != 0 )
    {
      scriptstack = scriptstack->next;
      if ( scriptstack == nullptr )
        goto LABEL_4;
    }
    HIDWORD(v7) = script->filename.data;
    idParser::Warning(
      this,
      str: "'%s' recursively included",
      a3: v7,
      a4: v6,
      a5: v5,
      a6: v10,
      a7: v11,
      a8: v12,
      a9: v13,
      a10: v14,
      a11: v15);
    idLexer::~idLexer(this: script);
    idMem::Free(this: &mem, ptr: script, align: ALIGN_16);
    return 0;
  }
  else
  {
LABEL_4:
    memset(v16, 0, 1024);
    if ( this->OSPath )
      fileSystem->OSPathToRelativePath(this: fileSystem, a2: script->filename.data, a3: v16, a4: 1024);
    if ( v16[0] != 0 )
      data = v16;
    else
      data = script->filename.data;
    idParser::AddDependency(this, includeLevel: this->includeLevel, fileName: data);
    script->next = this->scriptstack;
    this->scriptstack = script;
    ++this->includeLevel;
    return 1;
  }
}


// ========================================================================
// ?Directive_include@idParser@@AAAHXZ
// EA  : 0x82F920F8
// RVA : 0x00F920F8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::Directive_include(idParser *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  idLexer *v5; // r29
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  idLexer *v10; // r3
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  idLexer *v24; // r3
  idStr *v25; // r3
  __int64 v26; // r6
  __int64 v27; // r10
  __int64 v28; // r8
  BOOL v29; // r27
  __int64 v30; // r6
  __int64 v31; // r10
  __int64 v32; // r8
  int v33; // [sp+8h] [-138h]
  int v34; // [sp+Ch] [-134h]
  int v35; // [sp+10h] [-130h]
  int v36; // [sp+14h] [-12Ch]
  int v37; // [sp+18h] [-128h]
  int v38; // [sp+1Ch] [-124h]
  idStr v39; // [sp+70h] [-D0h] BYREF
  idLexer *v40; // [sp+90h] [-B0h]
  idToken v41; // [sp+A0h] [-A0h] BYREF
  idStr v42[2]; // [sp+F0h] [-50h] BYREF

  LODWORD(v4) = byte_821B0000;
  v5 = nullptr;
  HIDWORD(v4) = v41.baseBuffer;
  v41.len = 0;
  v41.allocedAndFlag = 20;
  v41.data = v41.baseBuffer;
  v41.floatvalue = -3.4028235e38;
  v41.baseBuffer[0] = 0;
  v41.intvalue = 0;
  memset(&v41.whiteSpaceStart_p, 0, 12);
  LODWORD(a4) = v39.baseBuffer;
  v39.allocedAndFlag = 20;
  v39.data = v39.baseBuffer;
  v39.len = 0;
  v39.baseBuffer[0] = 0;
  if ( idParser::ReadSourceToken(this, token: &v41, a3, a4, a5: v4) != 0 && v41.linesCrossed <= 0 )
  {
    if ( v41.type == 1 )
    {
      v10 = (idLexer *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x88u,
                         tag: TAG_LEXER,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
      v40 = v10;
      if ( v10 != nullptr )
        v5 = idLexer::idLexer(this: v10, flags_: 0);
      v5->flags = this->flags;
      idLexer::SetPunctuations(this: v5, p: this->punctuations);
      if ( *v41.data == 47 || *v41.data == 92 )
      {
        idStr::operator=(this: &v39, text: &v41);
      }
      else
      {
        idStr::operator=(this: &v39, text: this->scriptstack->filename.data);
        idStr::StripFilename(this: &v39);
        if ( strstr(str1: v39.data, str2: "generated/decls/renderProg") != nullptr )
          idStr::operator=(this: &v39, text: "decls/renderprogs");
        idStr::Append(this: &v39, text: "/");
        idStr::Append(this: &v39, text: &v41);
        idStr::CollapsePath(this: &v39);
      }
      HIDWORD(v13) = this->OSPath;
      if ( (unsigned __int8)idLexer::LoadFile(this: v5, filename_: v39.data, OSPath: v13, a4: v12, a5: v11) != 0 )
        goto LABEL_14;
LABEL_34:
      idLexer::~idLexer(this: v5);
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
      HIDWORD(v30) = v39.data;
      idParser::Error(
        this,
        str: "file '%s' not found",
        a3: v30,
        a4: v32,
        a5: v31,
        a6: v33,
        a7: v34,
        a8: v35,
        a9: v36,
        a10: v37,
        a11: v38);
      idStr::FreeData(this: &v39);
      goto LABEL_37;
    }
    if ( v41.type == 5 && idStr::Cmp(s1: v41.data, s2: "<") == 0 )
    {
      idStr::operator=(this: &v39, text: &this->includepath);
      if ( idParser::ReadSourceToken(this, token: &v41, a3: v16, a4: v15, a5: v14) != 0 )
      {
        while ( v41.linesCrossed <= 0 )
        {
          if ( v41.type != 5 || idStr::Cmp(s1: v41.data, s2: ">") != 0 )
          {
            idStr::Append(this: &v39, text: &v41);
            if ( idParser::ReadSourceToken(this, token: &v41, a3: v19, a4: v18, a5: v17) != 0 )
              continue;
          }
          goto LABEL_25;
        }
        idParser::UnreadSourceToken(this, token: &v41);
      }
LABEL_25:
      if ( idStr::Cmp(s1: v41.data, s2: ">") != 0 )
        idParser::Warning(
          this,
          str: "#include missing trailing >",
          a3: v22,
          a4: v21,
          a5: v20,
          a6: v33,
          a7: v34,
          a8: v35,
          a9: v36,
          a10: v37,
          a11: v38);
      if ( v39.len == 0 )
      {
        idParser::Error(
          this,
          str: "#include without file name between < >",
          a3: v22,
          a4: v21,
          a5: v20,
          a6: v33,
          a7: v34,
          a8: v35,
          a9: v36,
          a10: v37,
          a11: v38);
        idStr::FreeData(this: &v39);
        goto LABEL_37;
      }
      if ( (this->flags & 0x80) != 0 )
      {
LABEL_30:
        idStr::FreeData(this: &v39);
        idStr::FreeData(this: &v41);
        return 1;
      }
      v24 = (idLexer *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x88u,
                         tag: TAG_LEXER,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
      v40 = v24;
      if ( v24 != nullptr )
        v5 = idLexer::idLexer(this: v24, flags_: 0);
      v5->flags = this->flags;
      idLexer::SetPunctuations(this: v5, p: this->punctuations);
      v25 = operator+(result: v42, a: &this->includepath, b: &v39);
      HIDWORD(v26) = this->OSPath;
      v29 = (_cntlzw((unsigned __int8)idLexer::LoadFile(this: v5, filename_: v25->data, OSPath: v26, a4: v28, a5: v27))
           & 0x20) != 0;
      idStr::FreeData(this: v42);
      if ( v29 )
        goto LABEL_34;
LABEL_14:
      if ( (unsigned __int8)idParser::PushScript(this, script: v5) != 0 )
        goto LABEL_30;
      idStr::FreeData(this: &v39);
LABEL_37:
      idStr::FreeData(this: &v41);
      return 0;
    }
  }
  idParser::Error(
    this,
    str: "#include without file name",
    a3: v9,
    a4: v8,
    a5: v7,
    a6: v33,
    a7: v34,
    a8: v35,
    a9: v36,
    a10: v37,
    a11: v38);
  idStr::FreeData(this: &v39);
  goto LABEL_37;
}


// ========================================================================
// __unwind$121200
// EA  : 0x82F9250C
// RVA : 0x00F9250C
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_121200()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 160));
}


// ========================================================================
// __unwind$121201
// EA  : 0x82F92534
// RVA : 0x00F92534
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_121201()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 112));
}


// ========================================================================
// __unwind$121202
// EA  : 0x82F9255C
// RVA : 0x00F9255C
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_121202()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 320 + 144), tag: TAG_LEXER);
}


// ========================================================================
// __unwind$121203
// EA  : 0x82F92588
// RVA : 0x00F92588
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_121203()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 320 + 144), tag: TAG_LEXER);
}


// ========================================================================
// __unwind$121204
// EA  : 0x82F925B4
// RVA : 0x00F925B4
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_121204()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 240));
}


// ========================================================================
// ?ReadDirective@idParser@@AAAHXZ
// EA  : 0x82F925E8
// RVA : 0x00F925E8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::ReadDirective(idParser *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  __int64 v12; // r10
  __int64 v13; // r8
  int v14; // r6
  int v15; // r5
  int v16; // r4
  int v17; // r30
  __int64 v19; // r8
  unsigned int v20; // r6
  int v21; // r5
  int v22; // r30
  __int64 v23; // r8
  unsigned int v24; // r6
  int v25; // r5
  int v26; // r30
  __int64 v27; // r10
  __int64 v28; // r8
  __int64 v29; // r6
  int v30; // r4
  int v31; // r30
  __int64 v32; // r10
  __int64 v33; // r8
  __int64 v34; // r6
  int v35; // r4
  int v36; // r30
  __int64 v37; // r10
  __int64 v38; // r8
  __int64 v39; // r6
  int v40; // r4
  int v41; // r30
  __int64 v42; // r8
  __int64 v43; // r6
  int v44; // r4
  int v45; // r30
  __int64 v46; // r10
  __int64 v47; // r8
  __int64 v48; // r6
  BOOL v49; // r30
  __int64 v50; // r8
  unsigned int v51; // r6
  int v52; // r5
  int v53; // r4
  int v54; // r30
  __int64 v55; // r6
  int v56; // r4
  int v57; // r30
  __int64 v58; // r8
  unsigned int v59; // r6
  int v60; // r5
  int v61; // r4
  int v62; // r30
  __int64 v63; // r8
  unsigned int v64; // r6
  int v65; // r5
  int v66; // r4
  int v67; // r30
  __int64 v68; // r8
  unsigned int v69; // r6
  int v70; // r5
  int v71; // r4
  int v72; // r30
  __int64 v73; // r8
  int v74; // r6
  int v75; // r5
  int v76; // r4
  int v77; // r30
  __int64 v78; // r8
  int v79; // r6
  int v80; // r5
  int v81; // r4
  int v82; // r30
  BOOL v83; // r30
  int v84; // [sp+8h] [-C8h]
  int v85; // [sp+Ch] [-C4h]
  int v86; // [sp+10h] [-C0h]
  int v87; // [sp+14h] [-BCh]
  int v88; // [sp+18h] [-B8h]
  int v89; // [sp+1Ch] [-B4h]
  idToken v90; // [sp+70h] [-60h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v90.baseBuffer;
  v90.len = 0;
  v90.allocedAndFlag = 20;
  v90.data = v90.baseBuffer;
  v90.floatvalue = -3.4028235e38;
  v90.baseBuffer[0] = 0;
  v90.intvalue = 0;
  memset(&v90.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadSourceToken(this, token: &v90, a3, a4, a5: v4) == 0 )
  {
    idParser::Error(
      this,
      str: "found '#' without name",
      a3: v8,
      a4: v7,
      a5: v6,
      a6: v84,
      a7: v85,
      a8: v86,
      a9: v87,
      a10: v88,
      a11: v89);
LABEL_42:
    idStr::FreeData(this: &v90);
    return 0;
  }
  if ( v90.linesCrossed > 0 )
  {
    idParser::UnreadSourceToken(this, token: &v90);
    idParser::Error(
      this,
      str: "found '#' at end of line",
      a3: v11,
      a4: v10,
      a5: v9,
      a6: v84,
      a7: v85,
      a8: v86,
      a9: v87,
      a10: v88,
      a11: v89);
    goto LABEL_42;
  }
  if ( v90.type != 4 )
  {
LABEL_41:
    HIDWORD(v8) = v90.data;
    idParser::Error(
      this,
      str: "unknown precompiler directive '%s'",
      a3: v8,
      a4: v7,
      a5: v6,
      a6: v84,
      a7: v85,
      a8: v86,
      a9: v87,
      a10: v88,
      a11: v89);
    goto LABEL_42;
  }
  if ( idStr::Cmp(s1: v90.data, s2: "if") == 0 )
  {
    v17 = idParser::Directive_if(this, a2: v16, a3: v15, a4: v14, a5: v13, a6: v12);
    idStr::FreeData(this: &v90);
    return v17;
  }
  if ( idStr::Cmp(s1: v90.data, s2: "ifdef") == 0 )
  {
    v22 = idParser::Directive_if_def(this, type: 8, a3: v21, a4: v20, a5: v19);
    idStr::FreeData(this: &v90);
    return v22;
  }
  if ( idStr::Cmp(s1: v90.data, s2: "ifndef") == 0 )
  {
    v26 = idParser::Directive_if_def(this, type: 16, a3: v25, a4: v24, a5: v23);
    idStr::FreeData(this: &v90);
    return v26;
  }
  if ( idStr::Cmp(s1: v90.data, s2: "elif") == 0 )
  {
    v31 = idParser::Directive_elif(this, a2: v30, a3: v29, a4: v28, a5: v27);
    idStr::FreeData(this: &v90);
    return v31;
  }
  if ( idStr::Cmp(s1: v90.data, s2: "else") == 0 )
  {
    v36 = idParser::Directive_else(this, a2: v35, a3: v34, a4: v33, a5: v32);
    idStr::FreeData(this: &v90);
    return v36;
  }
  if ( idStr::Cmp(s1: v90.data, s2: "endif") == 0 )
  {
    v41 = idParser::Directive_endif(this, a2: v40, a3: v39, a4: v38, a5: v37);
    idStr::FreeData(this: &v90);
    return v41;
  }
  if ( this->skip <= 0 )
  {
    if ( idStr::Cmp(s1: v90.data, s2: "include") == 0 )
    {
      v45 = idParser::Directive_include(this, a2: v44, a3: v43, a4: v42);
      idStr::FreeData(this: &v90);
      return v45;
    }
    if ( idStr::Cmp(s1: v90.data, s2: "define") == 0 )
    {
      v49 = idParser::Directive_define(this, isTemplate: 0, a3: v48, a4: v47, a5: v46) != nullptr;
      idStr::FreeData(this: &v90);
      return v49;
    }
    if ( idStr::Cmp(s1: v90.data, s2: "undef") == 0 )
    {
      v54 = idParser::Directive_undef(this, a2: v53, a3: v52, a4: v51, a5: v50);
      idStr::FreeData(this: &v90);
      return v54;
    }
    if ( idStr::Cmp(s1: v90.data, s2: "line") == 0 )
    {
      v57 = idParser::Directive_line(this, a2: v56, a3: v55);
      idStr::FreeData(this: &v90);
      return v57;
    }
    if ( idStr::Cmp(s1: v90.data, s2: "error") == 0 )
    {
      v62 = idParser::Directive_error(this, a2: v61, a3: v60, a4: v59, a5: v58);
      idStr::FreeData(this: &v90);
      return v62;
    }
    if ( idStr::Cmp(s1: v90.data, s2: "warning") == 0 )
    {
      v67 = idParser::Directive_warning(this, a2: v66, a3: v65, a4: v64, a5: v63);
      idStr::FreeData(this: &v90);
      return v67;
    }
    if ( idStr::Cmp(s1: v90.data, s2: "pragma") == 0 )
    {
      v72 = idParser::Directive_pragma(this, a2: v71, a3: v70, a4: v69, a5: v68);
      idStr::FreeData(this: &v90);
      return v72;
    }
    if ( idStr::Cmp(s1: v90.data, s2: "evalint") == 0 )
    {
      v77 = idParser::Directive_evalint(this, a2: v76, a3: v75, a4: v74, a5: v73);
      idStr::FreeData(this: &v90);
      return v77;
    }
    if ( idStr::Cmp(s1: v90.data, s2: "evalfloat") == 0 )
    {
      v82 = idParser::Directive_evalfloat(this, a2: v81, a3: v80, a4: v79, a5: v78);
      idStr::FreeData(this: &v90);
      return v82;
    }
    if ( idStr::Cmp(s1: v90.data, s2: "template") == 0 )
    {
      v83 = idParser::Directive_define(this, isTemplate: 1, a3: v8, a4: v7, a5: v6) != nullptr;
      idStr::FreeData(this: &v90);
      return v83;
    }
    goto LABEL_41;
  }
  while ( idParser::ReadLine(this, token: &v90, multiline: (unsigned int)v39, a4: v38, a5: v37) )
    ;
  idStr::FreeData(this: &v90);
  return 1;
}


// ========================================================================
// __unwind$121561
// EA  : 0x82F92A5C
// RVA : 0x00F92A5C
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_121561()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?ReadToken@idParser@@QAA_NAAVidToken@@@Z
// EA  : 0x82F92A90
// RVA : 0x00F92A90
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::ReadToken(idParser *this, idToken *token, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v7; // r8
  __int64 v8; // r6
  int v9; // r4
  __int64 v10; // r10
  char *v11; // r11
  char *data; // r11
  int Directive; // r3
  idParser::define_t *HashedDefine; // r5
  int flags; // [sp+50h] [-90h]
  idToken v17; // [sp+60h] [-80h] BYREF

  if ( idParser::ReadSourceToken(this, token, a3, a4, a5) != 0 )
  {
    do
    {
      flags = this->scriptstack->flags;
      HIDWORD(v10) = flags;
      if ( (flags & 0x40) != 0 || token->type != 5 || *(v11 = token->data) != 36 || v11[1] != 0 )
      {
        LODWORD(v10) = token->type;
        if ( (_DWORD)v10 == 5 )
        {
          data = token->data;
          LODWORD(v7) = (unsigned __int8)*data;
          if ( (_DWORD)v7 == 35 && data[1] == 0 )
          {
            Directive = idParser::ReadDirective(this, a2: v9, a3: v8, a4: v7);
LABEL_24:
            if ( Directive == 0 )
              return 0;
            continue;
          }
        }
        if ( this->skip == 0 )
        {
          if ( (_DWORD)v10 == 1 && (flags & 0x10) == 0 )
          {
            v17.floatvalue = -3.4028235e38;
            v17.allocedAndFlag = 20;
            v17.data = v17.baseBuffer;
            v17.len = 0;
            v17.baseBuffer[0] = 0;
            v17.intvalue = 0;
            memset(&v17.whiteSpaceStart_p, 0, 12);
            if ( idParser::ReadToken(this, token: &v17) )
            {
              if ( v17.type == 1 )
                idStr::Append(this: token, text: v17.data);
              else
                idParser::UnreadSourceToken(this, token: &v17);
            }
            idStr::FreeData(this: &v17);
          }
          if ( token->type != 4 )
            return 1;
          if ( (token->flags & 1) != 0 )
            return 1;
          HashedDefine = idParser::FindHashedDefine(this, name: token->data);
          if ( HashedDefine == nullptr )
            return 1;
          Directive = idParser::ExpandDefineIntoSource(this, deftoken: token, define: HashedDefine);
          goto LABEL_24;
        }
      }
      else if ( idParser::ReadDollarDirective(this, a2: v9, a3: v8, a4: v7) == 0 )
      {
        return 1;
      }
    }
    while ( idParser::ReadSourceToken(this, token, a3: v8, a4: v7, a5: v10) != 0 );
  }
  return 0;
}


// ========================================================================
// __unwind$121889
// EA  : 0x82F92C54
// RVA : 0x00F92C54
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_121889()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// ?ExpectTokenString@idParser@@QAA_NPBD@Z
// EA  : 0x82F92C88
// RVA : 0x00F92C88
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::ExpectTokenString(idParser *this, const char *string, __int64 a3, __int64 a4)
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
  if ( (unsigned __int8)idParser::ReadToken(this, token: &v19, a3, a4, a5: v4) != 0 )
  {
    if ( idStr::Cmp(s1: v19.data, s2: string) != 0 )
    {
      idParser::Error(
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
    idParser::Error(
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
// __unwind$121990
// EA  : 0x82F92D60
// RVA : 0x00F92D60
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_121990()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?ExpectTokenType@idParser@@QAAHHHAAVidToken@@@Z
// EA  : 0x82F92D90
// RVA : 0x00F92D90
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::ExpectTokenType(idParser *this, int type, __int64 token, __int64 a4)
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
  int v21; // r4
  unsigned int v22; // r30
  char *PunctuationFromId; // r3
  __int64 v24; // r10
  __int64 v25; // r8
  int v26; // [sp+8h] [-B8h]
  int v27; // [sp+Ch] [-B4h]
  int v28; // [sp+10h] [-B0h]
  int v29; // [sp+14h] [-ACh]
  int v30; // [sp+18h] [-A8h]
  int v31; // [sp+1Ch] [-A4h]
  idStr v32[2]; // [sp+70h] [-50h] BYREF

  LODWORD(v4) = 20;
  HIDWORD(v4) = v32[0].baseBuffer;
  v32[0].len = 0;
  v32[0].allocedAndFlag = 20;
  v32[0].data = v32[0].baseBuffer;
  v7 = HIDWORD(token);
  v32[0].baseBuffer[0] = 0;
  v8 = (_DWORD *)token;
  LODWORD(v10) = (unsigned __int8)idParser::ReadToken(this, (idToken *)token, a3: token, a4, a5: v4);
  if ( (_DWORD)v10 == 0 )
  {
    idParser::Error(
      this,
      str: "couldn't read expected token",
      a3: v11,
      a4: v10,
      a5: v9,
      a6: v26,
      a7: v27,
      a8: v28,
      a9: v29,
      a10: v30,
      a11: v31);
    idStr::FreeData(this: v32);
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
    idStr::operator=(this: v32, text: v14);
    LODWORD(v15) = v8[1];
    HIDWORD(v15) = v32[0].data;
    idParser::Error(
      this,
      str: "expected a %s but found '%s'",
      a3: v15,
      a4: v17,
      a5: v16,
      a6: v26,
      a7: v27,
      a8: v28,
      a9: v29,
      a10: v30,
      a11: v31);
    idStr::FreeData(this: v32);
    return 0;
  }
  if ( v13 != 3 )
  {
    if ( v13 == 5 )
    {
      if ( v7 < 0 )
      {
        idParser::Error(
          this,
          str: "BUG: wrong punctuation subtype",
          a3: v11,
          a4: v10,
          a5: v9,
          a6: v26,
          a7: v27,
          a8: v28,
          a9: v29,
          a10: v30,
          a11: v31);
        idStr::FreeData(this: v32);
        return 0;
      }
      if ( v8[9] != v7 )
      {
        v21 = v7;
        v22 = v8[1];
        PunctuationFromId = idLexer::GetPunctuationFromId(this: this->scriptstack, id: v21);
        idParser::Error(
          this,
          str: "expected '%s' but found '%s'",
          a3: __SPAIR64__((unsigned int)PunctuationFromId, v22),
          a4: v25,
          a5: v24,
          a6: v26,
          a7: v27,
          a8: v28,
          a9: v29,
          a10: v30,
          a11: v31);
        idStr::FreeData(this: v32);
        return 0;
      }
    }
  }
  else if ( (v8[9] & v7) != v7 )
  {
    idStr::Clear(this: v32);
    if ( (v7 & 2) != 0 )
      idStr::operator=(this: v32, text: "decimal ");
    if ( (v7 & 4) != 0 )
      idStr::operator=(this: v32, text: "hex ");
    if ( (v7 & 8) != 0 )
      idStr::operator=(this: v32, text: "octal ");
    if ( (v7 & 0x10) != 0 )
      idStr::operator=(this: v32, text: "binary ");
    if ( (v7 & 0x40) != 0 )
      idStr::Append(this: v32, text: "unsigned ");
    if ( (v7 & 0x20) != 0 )
      idStr::Append(this: v32, text: "long ");
    if ( (v7 & 0x80) != 0 )
      idStr::Append(this: v32, text: "float ");
    if ( (v7 & 1) != 0 )
      idStr::Append(this: v32, text: "integer ");
    idStr::StripTrailing(this: v32, c: 32);
    HIDWORD(v18) = v32[0].data;
    LODWORD(v18) = v8[1];
    idParser::Error(
      this,
      str: "expected %s but found '%s'",
      a3: v18,
      a4: v20,
      a5: v19,
      a6: v26,
      a7: v27,
      a8: v28,
      a9: v29,
      a10: v30,
      a11: v31);
    idStr::FreeData(this: v32);
    return 0;
  }
  idStr::FreeData(this: v32);
  return 1;
}


// ========================================================================
// __unwind$122088
// EA  : 0x82F93064
// RVA : 0x00F93064
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_122088()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// ?ExpectAnyToken@idParser@@QAAHAAVidToken@@@Z
// EA  : 0x82F93090
// RVA : 0x00F93090
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::ExpectAnyToken(idParser *this, idToken *token, __int64 a3, __int64 a4, __int64 a5)
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

  if ( (unsigned __int8)idParser::ReadToken(this, token, a3, a4, a5) != 0 )
    return 1;
  idParser::Error(
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
// ?CheckTokenType@idParser@@QAAHHHAAVidToken@@@Z
// EA  : 0x82F93100
// RVA : 0x00F93100
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::CheckTokenType(idParser *this, int type, __int64 token, __int64 a4)
{
  __int64 v4; // r10
  int v7; // r28
  idToken *v8; // r27
  idToken v10; // [sp+50h] [-80h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v10.baseBuffer;
  v10.len = 0;
  v10.allocedAndFlag = 20;
  v10.floatvalue = -3.4028235e38;
  v7 = HIDWORD(token);
  v8 = (idToken *)token;
  v10.data = v10.baseBuffer;
  v10.baseBuffer[0] = 0;
  v10.intvalue = 0;
  memset(&v10.whiteSpaceStart_p, 0, 12);
  if ( (unsigned __int8)idParser::ReadToken(this, token: &v10, a3: token, a4, a5: v4) == 0 )
    goto LABEL_16;
  if ( (unsigned int)(type - 1) <= 4 )
  {
    if ( type == 1 || type == 2 )
      goto LABEL_10;
    if ( type != 3 )
    {
      if ( type != 4 )
      {
        if ( v10.type == type && v10.subtype == v7 )
          goto LABEL_14;
        goto LABEL_15;
      }
LABEL_10:
      if ( v10.type == type )
      {
LABEL_14:
        idToken::operator=(this: v8, __that: &v10);
        idStr::FreeData(this: &v10);
        return 1;
      }
      goto LABEL_15;
    }
  }
  if ( v10.type == type && (v10.subtype & v7) == v7 )
    goto LABEL_14;
LABEL_15:
  idParser::UnreadSourceToken(this, token: &v10);
LABEL_16:
  idStr::FreeData(this: &v10);
  return 0;
}


// ========================================================================
// __unwind$122201
// EA  : 0x82F93248
// RVA : 0x00F93248
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_122201()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?PeekTokenString@idParser@@QAAHPBD@Z
// EA  : 0x82F93278
// RVA : 0x00F93278
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::PeekTokenString(idParser *this, const char *string, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  idToken v8; // [sp+50h] [-70h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v8.baseBuffer;
  v8.len = 0;
  v8.allocedAndFlag = 20;
  v8.floatvalue = -3.4028235e38;
  v8.data = v8.baseBuffer;
  v8.baseBuffer[0] = 0;
  v8.intvalue = 0;
  memset(&v8.whiteSpaceStart_p, 0, 12);
  if ( (unsigned __int8)idParser::ReadToken(this, token: &v8, a3, a4, a5: v4) == 0
    || (idParser::UnreadSourceToken(this, token: &v8), idStr::Cmp(s1: v8.data, s2: string) != 0) )
  {
    idStr::FreeData(this: &v8);
    return 0;
  }
  else
  {
    idStr::FreeData(this: &v8);
    return 1;
  }
}


// ========================================================================
// __unwind$122311
// EA  : 0x82F93328
// RVA : 0x00F93328
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_122311()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?PeekTokenType@idParser@@QAAHHHAAVidToken@@@Z
// EA  : 0x82F93358
// RVA : 0x00F93358
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::PeekTokenType(idParser *this, int type, __int64 token, __int64 a4)
{
  __int64 v4; // r10
  int v7; // r28
  idToken *v8; // r27
  idToken v10; // [sp+50h] [-80h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v10.baseBuffer;
  v10.len = 0;
  v10.allocedAndFlag = 20;
  v10.floatvalue = -3.4028235e38;
  v7 = HIDWORD(token);
  v8 = (idToken *)token;
  v10.data = v10.baseBuffer;
  v10.baseBuffer[0] = 0;
  v10.intvalue = 0;
  memset(&v10.whiteSpaceStart_p, 0, 12);
  if ( (unsigned __int8)idParser::ReadToken(this, token: &v10, a3: token, a4, a5: v4) == 0 )
    goto LABEL_15;
  idParser::UnreadSourceToken(this, token: &v10);
  if ( (unsigned int)(type - 1) <= 4 )
  {
    if ( type == 1 || type == 2 )
      goto LABEL_10;
    if ( type != 3 )
    {
      if ( type != 4 )
      {
        if ( v10.type != type || v10.subtype != v7 )
          goto LABEL_15;
LABEL_14:
        idToken::operator=(this: v8, __that: &v10);
        idStr::FreeData(this: &v10);
        return 1;
      }
LABEL_10:
      if ( v10.type == type )
        goto LABEL_14;
LABEL_15:
      idStr::FreeData(this: &v10);
      return 0;
    }
  }
  if ( v10.type != type || (v10.subtype & v7) != v7 )
    goto LABEL_15;
  goto LABEL_14;
}


// ========================================================================
// __unwind$122400
// EA  : 0x82F93478
// RVA : 0x00F93478
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_122400()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?SkipUntilString@idParser@@QAA_NPBD@Z
// EA  : 0x82F934A8
// RVA : 0x00F934A8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::SkipUntilString(idParser *this, const char *string, __int64 a3, __int64 a4)
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
  if ( (unsigned __int8)idParser::ReadToken(this, token: &v11, a3, a4, a5: v4) != 0 )
  {
    while ( idStr::Cmp(s1: v11.data, s2: string) != 0 )
    {
      if ( (unsigned __int8)idParser::ReadToken(this, token: &v11, a3: v9, a4: v8, a5: v7) == 0 )
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
// __unwind$122504
// EA  : 0x82F9355C
// RVA : 0x00F9355C
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_122504()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?SkipRestOfLine@idParser@@QAAHXZ
// EA  : 0x82F93590
// RVA : 0x00F93590
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::SkipRestOfLine(idParser *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  idToken v10; // [sp+50h] [-60h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v10.baseBuffer;
  v10.len = 0;
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v10.floatvalue = -3.4028235e38;
  v10.baseBuffer[0] = 0;
  v10.intvalue = 0;
  memset(&v10.whiteSpaceStart_p, 0, 12);
  HIDWORD(v7) = (unsigned __int8)idParser::ReadToken(this, token: &v10, a3, a4, a5: v4);
  if ( HIDWORD(v7) != 0 )
  {
    while ( v10.linesCrossed == 0 )
    {
      if ( (unsigned __int8)idParser::ReadToken(this, token: &v10, a3: v8, a4: v7, a5: v6) == 0 )
        goto LABEL_4;
    }
    idParser::UnreadSourceToken(this, token: &v10);
    idStr::FreeData(this: &v10);
    return 1;
  }
  else
  {
LABEL_4:
    idStr::FreeData(this: &v10);
    return 0;
  }
}


// ========================================================================
// __unwind$122581
// EA  : 0x82F93654
// RVA : 0x00F93654
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_122581()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?SkipBracedSection@idParser@@QAAH_N@Z
// EA  : 0x82F93688
// RVA : 0x00F93688
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::SkipBracedSection(idParser *this, bool parseFirstBrace, __int64 a3)
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
  while ( (unsigned __int8)idParser::ReadToken(this, token: &v8, a3, a4: v4, a5: v5) != 0 )
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
// __unwind$122655
// EA  : 0x82F93774
// RVA : 0x00F93774
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_122655()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?ParseBracedSectionExact@idParser@@QAA_NAAVidStr@@_N@Z
// EA  : 0x82F937A8
// RVA : 0x00F937A8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::ParseBracedSectionExact(idParser *this, idStr *out, bool parseFirstBrace)
{
  __int64 v6; // r8
  __int64 v7; // r6
  __int64 v8; // r10
  int v9; // r23
  const idStr *v10; // r3
  idStr *v11; // r3
  const idStr *v12; // r3
  idStr *v13; // r3
  idToken v15; // [sp+50h] [-150h] BYREF
  idStr v16; // [sp+A0h] [-100h] BYREF
  idStr v17; // [sp+C0h] [-E0h] BYREF
  idStr v18; // [sp+E0h] [-C0h] BYREF
  idStr v19; // [sp+100h] [-A0h] BYREF
  idStr v20; // [sp+120h] [-80h] BYREF

  idStr::EnsureAlloced(this: out, amount: 1, keepold: true, geometricGrowth: false);
  *out->data = 0;
  out->len = 0;
  if ( parseFirstBrace )
  {
    if ( (unsigned __int8)idParser::ExpectTokenString(this, string: "{", a3: v7, a4: v6) == 0 )
      return 0;
    idStr::operator=(this: out, text: "{");
  }
  LODWORD(v6) = byte_821B0000;
  LODWORD(v8) = &unk_821D0000;
  HIDWORD(v8) = "rmState::parmStack_t::parmBlockStack_t";
  v9 = 1;
  while ( 1 )
  {
    v15.floatvalue = -3.4028235e38;
    v15.allocedAndFlag = 20;
    v15.data = v15.baseBuffer;
    v15.len = 0;
    v15.baseBuffer[0] = 0;
    v15.intvalue = 0;
    memset(&v15.whiteSpaceStart_p, 0, 12);
    if ( (unsigned __int8)idParser::ReadToken(this, token: &v15, a3: v7, a4: v6, a5: v8) == 0 )
      break;
    v16.allocedAndFlag = 20;
    v16.len = 0;
    v16.data = v16.baseBuffer;
    v16.baseBuffer[0] = 0;
    idLexer::GetWhiteSpaceBeforeToken(this: this->scriptstack, token: &v15, whiteSpace: &v16);
    idStr::Append(this: out, text: &v16);
    if ( v15.type == 1 )
    {
      v10 = operator+(result: &v17, a: "\"", b: &v15);
      v11 = operator+(result: &v20, a: v10, b: "\"");
      idStr::Append(this: out, text: v11);
      idStr::FreeData(this: &v20);
      idStr::FreeData(this: &v17);
    }
    else if ( v15.type == 2 )
    {
      v12 = operator+(result: &v18, a: "'", b: &v15);
      v13 = operator+(result: &v19, a: v12, b: "'");
      idStr::Append(this: out, text: v13);
      idStr::FreeData(this: &v19);
      idStr::FreeData(this: &v18);
    }
    else
    {
      idStr::Append(this: out, text: &v15);
    }
    if ( idStr::Cmp(s1: v15.data, s2: "{") != 0 )
    {
      if ( idStr::Cmp(s1: v15.data, s2: "}") == 0 )
        --v9;
    }
    else
    {
      ++v9;
    }
    idStr::FreeData(this: &v16);
    idStr::FreeData(this: &v15);
    if ( v9 <= 0 )
      return 1;
  }
  idStr::FreeData(this: &v15);
  return 0;
}


// ========================================================================
// __unwind$122739
// EA  : 0x82F939C8
// RVA : 0x00F939C8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_122739()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 80));
}


// ========================================================================
// __unwind$122740
// EA  : 0x82F939F0
// RVA : 0x00F939F0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_122740()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 160));
}


// ========================================================================
// __unwind$122741
// EA  : 0x82F93A18
// RVA : 0x00F93A18
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_122741()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 192));
}


// ========================================================================
// __unwind$122742
// EA  : 0x82F93A40
// RVA : 0x00F93A40
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_122742()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 288));
}


// ========================================================================
// __unwind$122743
// EA  : 0x82F93A68
// RVA : 0x00F93A68
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_122743()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 224));
}


// ========================================================================
// __unwind$122744_0
// EA  : 0x82F93A90
// RVA : 0x00F93A90
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_122744_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 256));
}


// ========================================================================
// ?ParseRestOfLine@idParser@@QAAPBDAAVidStr@@@Z
// EA  : 0x82F93AC0
// RVA : 0x00F93AC0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

char *__fastcall idParser::ParseRestOfLine(idParser *this, idStr *out)
{
  __int64 v4; // r8
  __int64 v5; // r10
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  char *data; // r30
  idToken v12; // [sp+50h] [-70h] BYREF

  v12.len = 0;
  v12.allocedAndFlag = 20;
  v12.floatvalue = -3.4028235e38;
  v12.data = v12.baseBuffer;
  v12.baseBuffer[0] = 0;
  v12.intvalue = 0;
  memset(&v12.whiteSpaceStart_p, 0, 12);
  idStr::EnsureAlloced(this: out, amount: 1, keepold: true, geometricGrowth: false);
  LODWORD(v4) = out->data;
  *(_BYTE *)v4 = 0;
  out->len = 0;
  if ( (unsigned __int8)idParser::ReadToken(this, token: &v12, a3: v6, a4: v4, a5: v5) != 0 )
  {
    while ( v12.linesCrossed == 0 )
    {
      if ( out->len != 0 )
        idStr::Append(this: out, text: " ");
      idStr::Append(this: out, text: &v12);
      if ( (unsigned __int8)idParser::ReadToken(this, token: &v12, a3: v9, a4: v8, a5: v7) == 0 )
        goto LABEL_8;
    }
    idParser::UnreadSourceToken(this, token: &v12);
  }
LABEL_8:
  data = out->data;
  idStr::FreeData(this: &v12);
  return data;
}


// ========================================================================
// __unwind$123092
// EA  : 0x82F93BC0
// RVA : 0x00F93BC0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_123092()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?ReadTokenOnLine@idParser@@QAAHAAVidToken@@@Z
// EA  : 0x82F93BF0
// RVA : 0x00F93BF0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::ReadTokenOnLine(idParser *this, idToken *token, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  idToken v8; // [sp+50h] [-70h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v8.baseBuffer;
  v8.len = 0;
  v8.allocedAndFlag = 20;
  v8.floatvalue = -3.4028235e38;
  v8.data = v8.baseBuffer;
  v8.baseBuffer[0] = 0;
  v8.intvalue = 0;
  memset(&v8.whiteSpaceStart_p, 0, 12);
  if ( (unsigned __int8)idParser::ReadToken(this, token: &v8, a3, a4, a5: v4) != 0 )
  {
    if ( v8.linesCrossed == 0 )
    {
      idToken::operator=(this: token, __that: &v8);
      idStr::FreeData(this: &v8);
      return 1;
    }
    idParser::UnreadSourceToken(this, token: &v8);
  }
  idStr::FreeData(this: &v8);
  return 0;
}


// ========================================================================
// __unwind$123174
// EA  : 0x82F93C9C
// RVA : 0x00F93C9C
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_123174()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?ParseInt@idParser@@QAAHXZ
// EA  : 0x82F93CD0
// RVA : 0x00F93CD0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

unsigned int __fastcall idParser::ParseInt(idParser *this, int a2, __int64 a3, __int64 a4)
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
  HIDWORD(v7) = (unsigned __int8)idParser::ReadToken(this, token: &v18, a3, a4, a5: v4);
  if ( HIDWORD(v7) != 0 )
  {
    if ( v18.type != 5 || idStr::Cmp(s1: v18.data, s2: "-") != 0 )
    {
      if ( v18.type != 3 || v18.subtype == 128 )
      {
        HIDWORD(v8) = v18.data;
        idParser::Error(
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
      idParser::ExpectTokenType(this, type: 3, token: v10, a4: v7);
      UnsignedIntValue = -idToken::GetUnsignedIntValue(this: &v18);
    }
    idStr::FreeData(this: &v18);
    return UnsignedIntValue;
  }
  else
  {
    idParser::Error(
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
// __unwind$123260
// EA  : 0x82F93DFC
// RVA : 0x00F93DFC
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_123260()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?ParseBool@idParser@@QAA_NXZ
// EA  : 0x82F93E30
// RVA : 0x00F93E30
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

int __fastcall idParser::ParseBool(idParser *this, int a2, __int64 a3, __int64 a4)
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
  HIDWORD(v7) = (unsigned __int8)idParser::ReadToken(this, token: &v17, a3, a4, a5: v4);
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
    idParser::Error(
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
// __unwind$123354
// EA  : 0x82F93F44
// RVA : 0x00F93F44
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_123354()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?ParseFloat@idParser@@QAAMPA_N@Z
// EA  : 0x82F93F78
// RVA : 0x00F93F78
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

float __fastcall idParser::ParseFloat(idParser *this, bool *errorFlag, __int64 a3, __int64 a4)
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
  if ( (unsigned __int8)idParser::ReadToken(this, token: &v19, a3, a4, a5: v4) != 0 )
  {
    if ( v19.type != 5 || idStr::Cmp(s1: v19.data, s2: "-") != 0 )
    {
      if ( v19.type != 3 )
      {
        HIDWORD(v9) = v19.data;
        idParser::Error(
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
        if ( errorFlag != nullptr )
          *errorFlag = true;
      }
      FloatValue = idToken::GetFloatValue(this: &v19);
    }
    else
    {
      idParser::ExpectTokenType(this, type: 3, token: (unsigned int)&v19, a4: v8);
      FloatValue = -idToken::GetFloatValue(this: &v19);
    }
    idStr::FreeData(this: &v19);
    v10 = FloatValue;
  }
  else
  {
    idParser::Error(
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
    if ( errorFlag != nullptr )
      *errorFlag = true;
    idStr::FreeData(this: &v19);
    v10 = 0.0;
  }
  return *((float *)&v10 + 1);
}


// ========================================================================
// __unwind$123456
// EA  : 0x82F940C0
// RVA : 0x00F940C0
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

void _unwind_123456()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?Parse1DMatrix@idParser@@QAA_NHPAM@Z
// EA  : 0x82F940E8
// RVA : 0x00F940E8
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

BOOL __fastcall idParser::Parse1DMatrix(idParser *this, int x, __int64 m, __int64 a4)
{
  int v6; // r30
  __int64 v7; // r8
  __int64 v8; // r6
  float *v10; // r30

  v6 = HIDWORD(m);
  if ( (unsigned __int8)idParser::ExpectTokenString(this, string: "(", a3: m, a4) == 0 )
    return false;
  if ( x > 0 )
  {
    v10 = (float *)(v6 - 4);
    do
    {
      *++v10 = idParser::ParseFloat(this, errorFlag: nullptr, a3: v8, a4: v7);
      --x;
    }
    while ( x != 0 );
  }
  return (unsigned __int8)idParser::ExpectTokenString(this, string: ")", a3: v8, a4: v7) != 0;
}


// ========================================================================
// ?SetupGlobalDefines@idParser@@SAXXZ
// EA  : 0x82F94170
// RVA : 0x00F94170
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

static void __fastcall idParser::SetupGlobalDefines()
{
  idParser::define_t *v0; // r3
  idParser::define_t *v1; // r3
  idParser::define_t *v2; // r3
  idParser::define_t *v3; // r3
  idParser::define_t *v4; // r3
  idParser::define_t *v5; // r3

  v0 = idParser::DefineFromString(string: "XBOX 1");
  if ( v0 != nullptr )
  {
    v0->next = idParser::globaldefines;
    idParser::globaldefines = v0;
  }
  v1 = idParser::DefineFromString(string: "RETAIL 1");
  if ( v1 != nullptr )
  {
    v1->next = idParser::globaldefines;
    idParser::globaldefines = v1;
  }
  v2 = idParser::DefineFromString(string: "DVD1");
  if ( v2 != nullptr )
  {
    v2->next = idParser::globaldefines;
    idParser::globaldefines = v2;
  }
  v3 = idParser::DefineFromString(string: "DVD2");
  if ( v3 != nullptr )
  {
    v3->next = idParser::globaldefines;
    idParser::globaldefines = v3;
  }
  v4 = idParser::DefineFromString(string: "DVD3");
  if ( v4 != nullptr )
  {
    v4->next = idParser::globaldefines;
    idParser::globaldefines = v4;
  }
  v5 = idParser::DefineFromString(string: "__HAPPY__");
  if ( v5 != nullptr )
  {
    v5->next = idParser::globaldefines;
    idParser::globaldefines = v5;
  }
}


// ========================================================================
// `dynamic initializer for 'TestPreprocessorMacros_v''
// EA  : 0x83397430
// RVA : 0x01397430
// PDB : w:\tech5\shared\idlib\text\parser.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestPreprocessorMacros_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestPreprocessorMacros_v,
           cmdName: "TestPreprocessorMacros",
           function: TestPreprocessorMacros_f,
           description: "check analyze warning",
           argCompletion: nullptr);
}

