
// ========================================================================
// ??4idCmdArgs@@QAAAAV0@ABV0@@Z
// EA  : 0x82F87590
// RVA : 0x00F87590
// PDB : w:\tech5\shared\idlib\text\cmdargs.cpp
// ========================================================================

idCmdArgs *__fastcall idCmdArgs::operator=(idCmdArgs *this, const idCmdArgs *rhs)
{
  int v4; // r10
  char **argv; // r11

  if ( rhs != this )
  {
    this->argc = rhs->argc;
    memcpy(Dst: this->tokenized, Src: rhs->tokenized, Size: sizeof(this->tokenized));
    v4 = 0;
    if ( this->argc > 0 )
    {
      argv = this->argv;
      do
      {
        ++v4;
        *argv = (char *)this + *(char **)((char *)argv + (char *)rhs - (char *)this) - (char *)rhs;
        ++argv;
      }
      while ( v4 < this->argc );
    }
  }
  return this;
}


// ========================================================================
// ??0idCmdArgs@@QAA@ABV0@@Z
// EA  : 0x82F87628
// RVA : 0x00F87628
// PDB : w:\tech5\shared\idlib\text\cmdargs.cpp
// ========================================================================

idCmdArgs *__fastcall idCmdArgs::idCmdArgs(idCmdArgs *this, const idCmdArgs *other)
{
  idCmdArgs::operator=(this, rhs: other);
  return this;
}


// ========================================================================
// ?Args@idCmdArgs@@QBAPBDHH_N0@Z
// EA  : 0x82F87658
// RVA : 0x00F87658
// PDB : w:\tech5\shared\idlib\text\cmdargs.cpp
// ========================================================================

char *__fastcall idCmdArgs::Args(idCmdArgs *this, int start, int end, bool quoteArgs, bool escapeArgs)
{
  int argc; // r11
  int v7; // r24
  BOOL v8; // r23
  const char *v9; // r10
  char *v10; // r11
  int v11; // r9
  char *v12; // r11
  int v13; // r9
  int v14; // r28
  const char **v15; // r30
  char *v16; // r11
  const char *v17; // r10
  int v18; // r9
  char *v19; // r11
  int v20; // r9
  const char *v21; // r7
  char v22; // r8
  int v23; // r11
  const char *v24; // r10
  char *v25; // r11
  int v26; // r9
  char *v27; // r11
  int v28; // r9
  const char *v29; // r10
  int v30; // r9
  char *v31; // r11
  int v32; // r9
  const char *v33; // r10
  char *v34; // r11
  int v35; // r9
  char *v36; // r11
  int v37; // r9
  const char *v38; // r10
  char *v39; // r11
  int v40; // r9
  char *v41; // r11
  int v42; // r9
  int v44; // r11
  char *v45; // r10

  argc = this->argc;
  v7 = end;
  if ( end < 0 || end >= argc )
    v7 = argc - 1;
  v8 = escapeArgs;
  cmd_args[0] = 0;
  if ( escapeArgs )
  {
    v9 = "\"";
    v10 = cmd_args;
    do
      v11 = (unsigned __int8)*v10++;
    while ( v11 != 0 );
    v12 = v10 - 1;
    do
    {
      v13 = *(unsigned __int8 *)v9++;
      *v12++ = v13;
    }
    while ( v13 != 0 );
  }
  v14 = start;
  if ( start <= v7 )
  {
    v15 = (const char **)&this->argv[start];
    do
    {
      if ( v14 > start )
      {
        v16 = cmd_args;
        if ( !v8 )
        {
          v29 = " ";
          do
            v30 = (unsigned __int8)*v16++;
          while ( v30 != 0 );
          v31 = v16 - 1;
          do
          {
            v32 = *(unsigned __int8 *)v29++;
            *v31++ = v32;
          }
          while ( v32 != 0 );
          goto LABEL_30;
        }
        v17 = "\" \"";
        do
          v18 = (unsigned __int8)*v16++;
        while ( v18 != 0 );
        v19 = v16 - 1;
        do
        {
          v20 = *(unsigned __int8 *)v17++;
          *v19++ = v20;
        }
        while ( v20 != 0 );
      }
      if ( v8 && strchr(Str: *v15, Val: 92) != nullptr )
      {
        v21 = *v15;
        v22 = **v15;
        v23 = v22;
        if ( v22 != 0 )
        {
          do
          {
            if ( v23 == 92 )
            {
              v24 = "\\\\";
              v25 = cmd_args;
              do
                v26 = (unsigned __int8)*v25++;
              while ( v26 != 0 );
              v27 = v25 - 1;
              do
              {
                v28 = *(unsigned __int8 *)v24++;
                *v27++ = v28;
              }
              while ( v28 != 0 );
            }
            else
            {
              v44 = 0;
              if ( cmd_args[0] != 0 )
              {
                v45 = cmd_args;
                do
                {
                  ++v45;
                  ++v44;
                }
                while ( *v45 != 0 );
              }
              cmd_args[v44] = v22;
              cmd_args[v44 + 1] = 0;
            }
            v22 = *++v21;
            v23 = *v21;
          }
          while ( *v21 != 0 );
        }
        goto LABEL_34;
      }
LABEL_30:
      v33 = *v15;
      v34 = cmd_args;
      do
        v35 = (unsigned __int8)*v34++;
      while ( v35 != 0 );
      v36 = v34 - 1;
      do
      {
        v37 = *(unsigned __int8 *)v33++;
        *v36++ = v37;
      }
      while ( v37 != 0 );
LABEL_34:
      ++v14;
      ++v15;
    }
    while ( v14 <= v7 );
  }
  if ( v8 )
  {
    v38 = "\"";
    v39 = cmd_args;
    do
      v40 = (unsigned __int8)*v39++;
    while ( v40 != 0 );
    v41 = v39 - 1;
    do
    {
      v42 = *(unsigned __int8 *)v38++;
      *v41++ = v42;
    }
    while ( v42 != 0 );
  }
  return cmd_args;
}


// ========================================================================
// ?AppendArg@idCmdArgs@@QAAXPBD@Z
// EA  : 0x82F878C8
// RVA : 0x00F878C8
// PDB : w:\tech5\shared\idlib\text\cmdargs.cpp
// ========================================================================

void __fastcall idCmdArgs::AppendArg(idCmdArgs *this, const char *text)
{
  int argc; // r11
  char *tokenized; // r3
  int v5; // r11
  int *v6; // r10
  char *v7; // r3

  argc = this->argc;
  if ( this->argc < 64 )
  {
    if ( argc != 0 )
    {
      v6 = &this->argc + argc;
      v5 = 0;
      if ( *(_BYTE *)*v6 != 0 )
      {
        do
          ++v5;
        while ( *(_BYTE *)(*(&this->argc + this->argc) + v5) != 0 );
      }
      v7 = (char *)(*v6 + v5 + 1);
      v6[1] = (int)v7;
      idStr::Copynz(dest: v7, src: text, destsize: (char *)this - v7 + 2308);
      ++this->argc;
    }
    else
    {
      tokenized = this->tokenized;
      this->argv[0] = tokenized;
      this->argc = 1;
      idStr::Copynz(dest: tokenized, src: text, destsize: 2048);
    }
  }
}


// ========================================================================
// ?TokenizeString@idCmdArgs@@QAAXPBD_N@Z
// EA  : 0x82F87998
// RVA : 0x00F87998
// PDB : w:\tech5\shared\idlib\text\cmdargs.cpp
// ========================================================================

void __fastcall idCmdArgs::TokenizeString(idCmdArgs *this, const char *text, bool keepAsStrings)
{
  unsigned int v5; // r5
  int v6; // r29
  const char *v7; // r3
  int v8; // r28
  char *v9; // r3
  char *data; // r4
  idToken v11; // [sp+50h] [-190h] BYREF
  idToken v12; // [sp+A0h] [-140h] BYREF
  idLexer v13; // [sp+F0h] [-F0h] BYREF

  idLexer::idLexer(this: &v13, flags_: (!keepAsStrings ? 0 : 0x8000) | 0xA33);
  this->argc = 0;
  if ( text != nullptr )
  {
    v5 = 0;
    if ( *text != 0 )
    {
      do
        ++v5;
      while ( text[v5] != 0 );
    }
    idLexer::LoadMemory(this: &v13, ptr: text, length_: v5, name: "idCmdSystemLocal::TokenizeString");
    v6 = 0;
    if ( this->argc != 64 )
    {
      while ( 1 )
      {
        v11.floatvalue = -3.4028235e38;
        v11.allocedAndFlag = 20;
        v11.data = v11.baseBuffer;
        v11.len = 0;
        v11.baseBuffer[0] = 0;
        v11.intvalue = 0;
        memset(&v11.whiteSpaceStart_p, 0, 12);
        if ( !idLexer::ReadToken(this: &v13, token: &v11) )
          break;
        if ( idStr::Cmp(s1: v11.data, s2: "-") == 0 )
        {
          v12.floatvalue = -3.4028235e38;
          v12.allocedAndFlag = 20;
          v12.data = v12.baseBuffer;
          v12.len = 0;
          v12.baseBuffer[0] = 0;
          v12.intvalue = 0;
          memset(&v12.whiteSpaceStart_p, 0, 12);
          if ( idLexer::ReadToken(this: &v13, token: &v12) )
          {
            if ( v12.whiteSpaceEnd_p > v12.whiteSpaceStart_p )
              idLexer::UnreadToken(this: &v13);
            else
              idStr::Append(this: &v11, text: &v12);
          }
          idStr::FreeData(this: &v12);
        }
        if ( idStr::Cmp(s1: v11.data, s2: "$") == 0 )
        {
          if ( !idLexer::ReadToken(this: &v13, token: &v11) )
            break;
          v7 = cvarSystem->GetCVarString(this: cvarSystem, a2: v11.data, a3: &byte_8200D768);
          idStr::operator=(this: &v11, text: v7);
        }
        v8 = v11.len + v6;
        if ( (unsigned int)(v11.len + v6 + 1) > 0x800 )
          break;
        v9 = &this->tokenized[v6];
        this->argv[this->argc] = v9;
        data = v11.data;
        ++this->argc;
        idStr::Copynz(dest: v9, src: data, destsize: 2048 - v6);
        v6 = v8 + 1;
        idStr::FreeData(this: &v11);
        if ( this->argc == 64 )
          goto _M111412;
      }
      idStr::FreeData(this: &v11);
    }
  }
_M111412:
  idLexer::~idLexer(this: &v13);
}


// ========================================================================
// __unwind$111239
// EA  : 0x82F87C08
// RVA : 0x00F87C08
// PDB : w:\tech5\shared\idlib\text\cmdargs.cpp
// ========================================================================

void _unwind_111239()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 480 + 240));
}


// ========================================================================
// __unwind$111240
// EA  : 0x82F87C30
// RVA : 0x00F87C30
// PDB : w:\tech5\shared\idlib\text\cmdargs.cpp
// ========================================================================

void _unwind_111240()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 80));
}


// ========================================================================
// __unwind$111241
// EA  : 0x82F87C58
// RVA : 0x00F87C58
// PDB : w:\tech5\shared\idlib\text\cmdargs.cpp
// ========================================================================

void _unwind_111241()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 160));
}

