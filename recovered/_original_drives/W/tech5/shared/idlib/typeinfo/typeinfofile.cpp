
// ========================================================================
// ?WriteOpeningBrace@idTypeInfoFile@@QAAXXZ
// EA  : 0x82F980F8
// RVA : 0x00F980F8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteOpeningBrace(idTypeInfoFile *this)
{
  idFile *fp; // r3

  fp = this->fp;
  if ( fp != nullptr )
  {
    fp->WriteFloatString(this: fp, a2: "{");
    ++this->indent;
  }
}


// ========================================================================
// ?ReadOpeningBrace@idTypeInfoFile@@QAAXXZ
// EA  : 0x82F98150
// RVA : 0x00F98150
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadOpeningBrace(idTypeInfoFile *this, int a2, __int64 a3, __int64 a4)
{
  idLexer::ExpectTokenString(this: &this->src, string: "{", a3, a4);
  ++this->indent;
}


// ========================================================================
// ?CheckOpeningBrace@idTypeInfoFile@@QAA_NXZ
// EA  : 0x82F98198
// RVA : 0x00F98198
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

int __fastcall idTypeInfoFile::CheckOpeningBrace(idTypeInfoFile *this, int a2, __int64 a3, __int64 a4)
{
  if ( (unsigned __int8)idLexer::CheckTokenString(this: &this->src, string: "{", a3, a4) == 0 )
    return 0;
  ++this->indent;
  return 1;
}


// ========================================================================
// ?WriteSkipObject@idTypeInfoFile@@QAAX_N@Z
// EA  : 0x82F98208
// RVA : 0x00F98208
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteSkipObject(idTypeInfoFile *this, bool skip)
{
  if ( this->fp != nullptr && skip )
    this->fp->WriteFloatString(this: this->fp, a2: "! ");
}


// ========================================================================
// ?CheckSkipObject@idTypeInfoFile@@QAA_NXZ
// EA  : 0x82F98240
// RVA : 0x00F98240
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

BOOL __fastcall idTypeInfoFile::CheckSkipObject(idTypeInfoFile *this, int a2, __int64 a3, __int64 a4)
{
  return (unsigned __int8)idLexer::CheckTokenString(this: &this->src, string: "!", a3, a4) != 0;
}


// ========================================================================
// ?ReadClosingBrace@idTypeInfoFile@@QAAXXZ
// EA  : 0x82F98278
// RVA : 0x00F98278
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadClosingBrace(idTypeInfoFile *this, int a2, __int64 a3, __int64 a4)
{
  LODWORD(a4) = this->indent - 1;
  this->indent = a4;
  idLexer::ExpectTokenString(this: &this->src, string: "}", a3, a4);
}


// ========================================================================
// ?CheckClosingBrace@idTypeInfoFile@@QAA_NXZ
// EA  : 0x82F98298
// RVA : 0x00F98298
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

int __fastcall idTypeInfoFile::CheckClosingBrace(idTypeInfoFile *this, int a2, __int64 a3, __int64 a4)
{
  if ( (unsigned __int8)idLexer::CheckTokenString(this: &this->src, string: "}", a3, a4) == 0 )
    return 0;
  --this->indent;
  return 1;
}


// ========================================================================
// ?PeekClosingBrace@idTypeInfoFile@@QAA_NXZ
// EA  : 0x82F98308
// RVA : 0x00F98308
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

BOOL __fastcall idTypeInfoFile::PeekClosingBrace(idTypeInfoFile *this, int a2, __int64 a3, __int64 a4)
{
  return (unsigned __int8)idLexer::PeekTokenString(this: &this->src, string: "}", a3, a4) != 0;
}


// ========================================================================
// ?WriteBool@idTypeInfoFile@@QAAX_N@Z
// EA  : 0x82F98340
// RVA : 0x00F98340
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteBool(idTypeInfoFile *this, const bool b)
{
  const char *v2; // r4

  if ( b )
    v2 = "true;";
  else
    v2 = "false;";
  this->fp->WriteFloatString(this: this->fp, a2: v2);
}


// ========================================================================
// ?WriteChar@idTypeInfoFile@@QAAXD@Z
// EA  : 0x82F98378
// RVA : 0x00F98378
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteChar(idTypeInfoFile *this, char c)
{
  this->fp->WriteFloatString(this: this->fp, a2: "%d;", c);
}


// ========================================================================
// ?WriteUnsignedChar@idTypeInfoFile@@QAAXE@Z
// EA  : 0x82F98398
// RVA : 0x00F98398
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteUnsignedChar(idTypeInfoFile *this, unsigned __int8 c)
{
  this->fp->WriteFloatString(this: this->fp, a2: "%u;", c);
}


// ========================================================================
// ?ReadUnsignedChar@idTypeInfoFile@@QAAXAAE@Z
// EA  : 0x82F983B8
// RVA : 0x00F983B8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadUnsignedChar(idTypeInfoFile *this, unsigned __int8 *c, __int64 a3, __int64 a4)
{
  idLexer *p_src; // r31
  __int64 v5; // r8
  __int64 v6; // r6

  p_src = &this->src;
  *c = idLexer::ParseInt(this: &this->src, a2: (int)c, a3, a4);
  idLexer::ExpectTokenString(this: p_src, string: ";", a3: v6, a4: v5);
}


// ========================================================================
// ?WriteWChar@idTypeInfoFile@@QAAX_W@Z
// EA  : 0x82F98408
// RVA : 0x00F98408
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteWChar(idTypeInfoFile *this, wchar_t w)
{
  this->fp->WriteFloatString(this: this->fp, a2: "%d;", w);
}


// ========================================================================
// ?ReadWChar@idTypeInfoFile@@QAAXAA_W@Z
// EA  : 0x82F98428
// RVA : 0x00F98428
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadWChar(idTypeInfoFile *this, unsigned __int16 *s, __int64 a3, __int64 a4)
{
  idLexer *p_src; // r31
  __int64 v5; // r8
  __int64 v6; // r6

  p_src = &this->src;
  *s = idLexer::ParseInt(this: &this->src, a2: (int)s, a3, a4);
  idLexer::ExpectTokenString(this: p_src, string: ";", a3: v6, a4: v5);
}


// ========================================================================
// ?WriteShort@idTypeInfoFile@@QAAXF@Z
// EA  : 0x82F98478
// RVA : 0x00F98478
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteShort(idTypeInfoFile *this, __int16 s)
{
  this->fp->WriteFloatString(this: this->fp, a2: "%d;", s);
}


// ========================================================================
// ?WriteUnsignedShort@idTypeInfoFile@@QAAXG@Z
// EA  : 0x82F98498
// RVA : 0x00F98498
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteUnsignedShort(idTypeInfoFile *this, unsigned __int16 s)
{
  this->fp->WriteFloatString(this: this->fp, a2: "%u;", s);
}


// ========================================================================
// ?WriteUnsignedLong@idTypeInfoFile@@QAAXK@Z
// EA  : 0x82F984B8
// RVA : 0x00F984B8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteUnsignedLong(idTypeInfoFile *this, unsigned int l)
{
  this->fp->WriteFloatString(this: this->fp, a2: "%u;", l);
}


// ========================================================================
// ?ReadUnsignedLong@idTypeInfoFile@@QAAXAAK@Z
// EA  : 0x82F984D8
// RVA : 0x00F984D8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadUnsignedLong(idTypeInfoFile *this, unsigned int *l, __int64 a3, __int64 a4)
{
  idLexer *p_src; // r31
  __int64 v5; // r8
  __int64 v6; // r6

  p_src = &this->src;
  *l = idLexer::ParseInt(this: &this->src, a2: (int)l, a3, a4);
  idLexer::ExpectTokenString(this: p_src, string: ";", a3: v6, a4: v5);
}


// ========================================================================
// ?WriteInt@idTypeInfoFile@@QAAXH@Z
// EA  : 0x82F98528
// RVA : 0x00F98528
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteInt(idTypeInfoFile *this, int l)
{
  this->fp->WriteFloatString(this: this->fp, a2: "%d;", l);
}


// ========================================================================
// ?WriteFloat@idTypeInfoFile@@QAAXM@Z
// EA  : 0x82F98548
// RVA : 0x00F98548
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteFloat(idTypeInfoFile *this, const long double d)
{
  this->fp->WriteFloatString(this: this->fp, a2: "%f;", DWORD1(d));
}


// ========================================================================
// ?ReadFloat@idTypeInfoFile@@QAAXAAM@Z
// EA  : 0x82F98588
// RVA : 0x00F98588
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadFloat(idTypeInfoFile *this, float *f, __int64 a3, __int64 a4)
{
  idLexer *p_src; // r31
  __int64 v5; // r8
  __int64 v6; // r6

  p_src = &this->src;
  *f = idLexer::ParseFloat(this: &this->src, errorFlag: nullptr, a3, a4);
  idLexer::ExpectTokenString(this: p_src, string: ";", a3: v6, a4: v5);
}


// ========================================================================
// ?ReadDouble@idTypeInfoFile@@QAAXAAN@Z
// EA  : 0x82F985E0
// RVA : 0x00F985E0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadDouble(idTypeInfoFile *this, long double *d, __int64 a3, __int64 a4)
{
  idLexer *p_src; // r31
  __int64 v5; // r8
  __int64 v6; // r6

  p_src = &this->src;
  *(double *)d = idLexer::ParseFloat(this: &this->src, errorFlag: nullptr, a3, a4);
  idLexer::ExpectTokenString(this: p_src, string: ";", a3: v6, a4: v5);
}


// ========================================================================
// ?WriteStr@idTypeInfoFile@@QAAXPBD@Z
// EA  : 0x82F98638
// RVA : 0x00F98638
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteStr(idTypeInfoFile *this, const char *s)
{
  idFile_vtbl *v3; // r31
  char *v4; // r3

  v3 = this->fp->__vftable;
  v4 = idStr::CStyleQuote(str: s);
  v3->WriteFloatString(this: this->fp, a2: "%s;", v4);
}


// ========================================================================
// ?WriteNullPointer@idTypeInfoFile@@QAAXXZ
// EA  : 0x82F98698
// RVA : 0x00F98698
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteNullPointer(idTypeInfoFile *this)
{
  this->fp->WriteFloatString(this: this->fp, a2: "NULL;");
}


// ========================================================================
// ?ReadNullPointer@idTypeInfoFile@@QAAXXZ
// EA  : 0x82F986B8
// RVA : 0x00F986B8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadNullPointer(idTypeInfoFile *this, int a2, __int64 a3, __int64 a4)
{
  idLexer *p_src; // r31
  __int64 v5; // r8
  __int64 v6; // r6

  p_src = &this->src;
  idLexer::ExpectTokenString(this: &this->src, string: "NULL", a3, a4);
  idLexer::ExpectTokenString(this: p_src, string: ";", a3: v6, a4: v5);
}


// ========================================================================
// ?CheckNullPointer@idTypeInfoFile@@QAA_NXZ
// EA  : 0x82F98700
// RVA : 0x00F98700
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

int __fastcall idTypeInfoFile::CheckNullPointer(idTypeInfoFile *this, int a2, __int64 a3, __int64 a4)
{
  idLexer *p_src; // r31
  __int64 v5; // r8
  __int64 v6; // r6

  p_src = &this->src;
  if ( (unsigned __int8)idLexer::CheckTokenString(this: &this->src, string: "NULL", a3, a4) == 0 )
    return 0;
  idLexer::ExpectTokenString(this: p_src, string: ";", a3: v6, a4: v5);
  return 1;
}


// ========================================================================
// ?WriteUnknown@idTypeInfoFile@@QAAXXZ
// EA  : 0x82F98770
// RVA : 0x00F98770
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteUnknown(idTypeInfoFile *this)
{
  this->fp->WriteFloatString(this: this->fp, a2: "<unknown>;");
}


// ========================================================================
// ?ReadComment@idTypeInfoFile@@QAAXAAVidStr@@@Z
// EA  : 0x82F98790
// RVA : 0x00F98790
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadComment(idTypeInfoFile *this, idStr *comment, __int64 a3, __int64 a4, __int64 a5)
{
  HIDWORD(a3) = 1;
  idLexer::GetNextWhiteSpace(this: &this->src, whiteSpace: comment, currentLine: a3, a4, a5);
  idStr::StripTrailing(this: comment, c: 10);
  idStr::StripTrailing(this: comment, c: 13);
  idStr::StripLeading(this: comment, c: 9);
  idStr::StripLeading(this: comment, string: "//");
  idStr::StripLeading(this: comment, string: " ");
}


// ========================================================================
// ?Error@idTypeInfoFile@@QAAXPBDZZ
// EA  : 0x82F98808
// RVA : 0x00F98808
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idTypeInfoFile::Error(
        idTypeInfoFile *this,
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
  __int64 v13; // r6
  __int64 v14; // r8
  int v15; // [sp+8h] [-468h]
  int v16; // [sp+Ch] [-464h]
  int v17; // [sp+10h] [-460h]
  int v18; // [sp+14h] [-45Ch]
  int v19; // [sp+18h] [-458h]
  int v20; // [sp+1Ch] [-454h]
  char v21[1024]; // [sp+60h] [-410h] BYREF
  __int64 v22; // [sp+490h] [+20h] BYREF
  va_list va; // [sp+490h] [+20h]
  __int64 v24; // [sp+498h] [+28h]
  __int64 v25; // [sp+4A0h] [+30h]
  __int64 v26; // [sp+4A8h] [+38h]
  __int64 v27; // [sp+4B0h] [+40h]
  __int64 v28; // [sp+4B8h] [+48h]
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
  v22 = *(__int64 *)((char *)&a3 + 4);
  v24 = a3;
  v25 = *(__int64 *)((char *)&a4 + 4);
  v26 = a4;
  v27 = *(__int64 *)((char *)&a5 + 4);
  v28 = a5;
  vsprintf(string: v21, format: str, ap: va);
  HIDWORD(v12) = byte_821B0000;
  HIDWORD(v13) = v21;
  idLexer::Error(
    this: &this->src,
    str: "%s",
    a3: v13,
    a4: v14,
    a5: v12,
    a6: v15,
    a7: v16,
    a8: v17,
    a9: v18,
    a10: v19,
    a11: v20);
}


// ========================================================================
// ?Warning@idTypeInfoFile@@QAAXPBDZZ
// EA  : 0x82F98878
// RVA : 0x00F98878
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idTypeInfoFile::Warning(
        idTypeInfoFile *this,
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
  __int64 v13; // r6
  __int64 v14; // r8
  int v15; // [sp+8h] [-468h]
  int v16; // [sp+Ch] [-464h]
  int v17; // [sp+10h] [-460h]
  int v18; // [sp+14h] [-45Ch]
  int v19; // [sp+18h] [-458h]
  int v20; // [sp+1Ch] [-454h]
  char v21[1024]; // [sp+60h] [-410h] BYREF
  __int64 v22; // [sp+490h] [+20h] BYREF
  va_list va; // [sp+490h] [+20h]
  __int64 v24; // [sp+498h] [+28h]
  __int64 v25; // [sp+4A0h] [+30h]
  __int64 v26; // [sp+4A8h] [+38h]
  __int64 v27; // [sp+4B0h] [+40h]
  __int64 v28; // [sp+4B8h] [+48h]
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
  v22 = *(__int64 *)((char *)&a3 + 4);
  v24 = a3;
  v25 = *(__int64 *)((char *)&a4 + 4);
  v26 = a4;
  v27 = *(__int64 *)((char *)&a5 + 4);
  v28 = a5;
  vsprintf(string: v21, format: str, ap: va);
  HIDWORD(v12) = byte_821B0000;
  HIDWORD(v13) = v21;
  idLexer::Warning(
    this: &this->src,
    str: "%s",
    a3: v13,
    a4: v14,
    a5: v12,
    a6: v15,
    a7: v16,
    a8: v17,
    a9: v18,
    a10: v19,
    a11: v20);
}


// ========================================================================
// ?HadError@idTypeInfoFile@@QAA_NXZ
// EA  : 0x82F988E8
// RVA : 0x00F988E8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

BOOL __fastcall idTypeInfoFile::HadError(idTypeInfoFile *this)
{
  return idLexer::HadError(this: &this->src);
}


// ========================================================================
// ?WriteComment@idTypeInfoFile@@QAAXPBD@Z
// EA  : 0x82F988F0
// RVA : 0x00F988F0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteComment(idTypeInfoFile *this, const char *comment)
{
  if ( this->settings.writeComments && comment != nullptr && *comment != 0 )
    this->fp->WriteFloatString(this: this->fp, a2: "\t/* %s */", comment);
}


// ========================================================================
// ?OutputTabs@idTypeInfoFile@@SAPBDAA_NH@Z
// EA  : 0x82F98938
// RVA : 0x00F98938
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

char *__fastcall idTypeInfoFile::OutputTabs(bool *newline, int indent)
{
  char *result; // r3
  int v4; // r10
  BOOL v5; // r4

  v4 = lastIndent;
  lastIndent = indent;
  tabs[v4 + 1] = 9;
  tabs[indent + 1] = 0;
  tabs[0] = 10;
  v5 = *newline;
  result = tabs;
  if ( !v5 )
  {
    *newline = true;
    return &tabs[1];
  }
  return result;
}


// ========================================================================
// ??0idTypeInfoSettings@@QAA@XZ
// EA  : 0x82F98990
// RVA : 0x00F98990
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

idTypeInfoSettings *__fastcall idTypeInfoSettings::idTypeInfoSettings(idTypeInfoSettings *this)
{
  this->writeModifier = WRITE_ALL_PROPERTIES;
  this->resolveEntityPointers = true;
  this->resolveModelPointers = true;
  this->skipMarkedObjects = false;
  this->skipScriptObjects = false;
  *(_WORD *)&this->writeComments = 1;
  return this;
}


// ========================================================================
// ??0idTypeInfoSettings@@QAA@_N0@Z
// EA  : 0x82F989B8
// RVA : 0x00F989B8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

idTypeInfoSettings *__fastcall idTypeInfoSettings::idTypeInfoSettings(
        idTypeInfoSettings *this,
        bool resolveEntityPointers,
        bool resolveModelPointers)
{
  this->resolveEntityPointers = resolveEntityPointers;
  this->resolveModelPointers = resolveModelPointers;
  this->writeModifier = WRITE_ALL_PROPERTIES;
  this->skipMarkedObjects = false;
  this->skipScriptObjects = false;
  *(_WORD *)&this->writeComments = 1;
  return this;
}


// ========================================================================
// ??0idTypeInfoSettings@@QAA@_N00@Z
// EA  : 0x82F989E0
// RVA : 0x00F989E0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

idTypeInfoSettings *__fastcall idTypeInfoSettings::idTypeInfoSettings(
        idTypeInfoSettings *this,
        bool resolveEntityPointers,
        bool resolveModelPointers,
        bool skipMarkedObjects)
{
  this->resolveEntityPointers = resolveEntityPointers;
  this->resolveModelPointers = resolveModelPointers;
  this->writeModifier = WRITE_ALL_PROPERTIES;
  this->skipMarkedObjects = skipMarkedObjects;
  this->skipScriptObjects = false;
  *(_WORD *)&this->writeComments = 1;
  return this;
}


// ========================================================================
// ??0idTypeInfoFile@@QAA@H@Z
// EA  : 0x82F98A08
// RVA : 0x00F98A08
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

idTypeInfoFile *__fastcall idTypeInfoFile::idTypeInfoFile(idTypeInfoFile *this, int indent_)
{
  this->settings.writeModifier = WRITE_ALL_PROPERTIES;
  this->settings.resolveEntityPointers = true;
  this->settings.resolveModelPointers = true;
  this->settings.skipMarkedObjects = false;
  this->settings.skipScriptObjects = false;
  this->settings.writeComments = false;
  this->settings.writeType = true;
  this->fp = nullptr;
  idLexer::idLexer(this: &this->src, flags_: 0);
  this->indent = indent_;
  this->newline = false;
  return this;
}


// ========================================================================
// ??1idTypeInfoFile@@QAA@XZ
// EA  : 0x82F98A70
// RVA : 0x00F98A70
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::~idTypeInfoFile(idTypeInfoFile *this)
{
  idFile *fp; // r3
  idLexer *p_src; // r30

  fp = this->fp;
  if ( fp != nullptr )
  {
    ((void (__fastcall *)(idFile *, int))fp->dtr_idFile)(a1: fp, a2: 1);
    this->fp = nullptr;
  }
  p_src = &this->src;
  idLexer::FreeSource(this: p_src);
  idLexer::~idLexer(this: p_src);
}


// ========================================================================
// __unwind$113072
// EA  : 0x82F98AE8
// RVA : 0x00F98AE8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_113072()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// ?WriteMemoryFile@idTypeInfoFile@@QAA_NXZ
// EA  : 0x82F98B20
// RVA : 0x00F98B20
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

idFile_Memory *__fastcall idTypeInfoFile::WriteMemoryFile(idTypeInfoFile *this)
{
  idFile *fp; // r3
  idFile_Memory *v3; // r3
  idFile_Memory *result; // r3

  fp = this->fp;
  if ( fp != nullptr )
  {
    ((void (__fastcall *)(idFile *, int))fp->dtr_idFile)(a1: fp, a2: 1);
    this->fp = nullptr;
  }
  idLexer::FreeSource(this: &this->src);
  v3 = (idFile_Memory *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x14Cu,
                          tag: TAG_FILE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    result = idFile_Memory::idFile_Memory(this: v3);
  else
    result = nullptr;
  if ( result != nullptr )
  {
    this->fp = result;
    return (idFile_Memory *)1;
  }
  return result;
}


// ========================================================================
// __unwind$113106
// EA  : 0x82F98BD8
// RVA : 0x00F98BD8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_113106()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_FILE);
}


// ========================================================================
// ?GetTypeInfoString@idTypeInfoFile@@QBAPBDXZ
// EA  : 0x82F98C08
// RVA : 0x00F98C08
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

char *__fastcall idTypeInfoFile::GetTypeInfoString(idTypeInfoFile *this)
{
  idFile *fp; // r11

  fp = this->fp;
  if ( fp != nullptr )
    return (char *)fp[40].__vftable;
  else
    return &byte_8200D768;
}


// ========================================================================
// ?WriteClosingBrace@idTypeInfoFile@@QAAXXZ
// EA  : 0x82F98C28
// RVA : 0x00F98C28
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteClosingBrace(idTypeInfoFile *this)
{
  int v1; // r10
  char *v2; // r11
  int v3; // r9

  if ( this->fp != nullptr )
  {
    v1 = this->indent - 1;
    v2 = tabs;
    this->indent = v1;
    v3 = lastIndent;
    lastIndent = v1;
    tabs[v3 + 1] = 9;
    tabs[v1 + 1] = 0;
    tabs[0] = 10;
    if ( !this->newline )
    {
      v2 = &tabs[1];
      this->newline = true;
    }
    this->fp->WriteFloatString(this: this->fp, a2: "%s}", v2);
  }
}


// ========================================================================
// ?CheckType@idTypeInfoFile@@QAA_NPBD00@Z
// EA  : 0x82F98CB8
// RVA : 0x00F98CB8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

int __fastcall idTypeInfoFile::CheckType(idTypeInfoFile *this, const char *type, const char *ops, const char *name)
{
  idLexer *p_src; // r30
  cmType_t ScriptP; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  const char *v11; // r25
  __int64 v12; // r6
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  unsigned int v17; // r6
  __int64 v18; // r8
  __int64 v19; // r6
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  __int64 v23; // r8
  __int64 v24; // r6
  idToken v26; // [sp+50h] [-130h] BYREF
  idToken v27; // [sp+A0h] [-E0h] BYREF
  idToken v28[2]; // [sp+F0h] [-90h] BYREF

  p_src = &this->src;
  ScriptP = idLexer::GetScriptP(this: (idCollisionModelLocal *)&this->src);
  HIDWORD(v9) = byte_821B0000;
  LODWORD(v9) = 20;
  LODWORD(v10) = v26.baseBuffer;
  v26.len = 0;
  v26.allocedAndFlag = 20;
  v11 = (const char *)ScriptP;
  v26.data = v26.baseBuffer;
  v26.floatvalue = -3.4028235e38;
  v26.baseBuffer[0] = 0;
  v26.intvalue = 0;
  memset(&v26.whiteSpaceStart_p, 0, 12);
  HIDWORD(v10) = v27.baseBuffer;
  v27.floatvalue = -3.4028235e38;
  v27.allocedAndFlag = 20;
  v27.data = v27.baseBuffer;
  v27.len = 0;
  v27.baseBuffer[0] = 0;
  v27.intvalue = 0;
  memset(&v27.whiteSpaceStart_p, 0, 12);
  LODWORD(v12) = v28[0].baseBuffer;
  v28[0].floatvalue = -3.4028235e38;
  v28[0].allocedAndFlag = 20;
  v28[0].data = v28[0].baseBuffer;
  v28[0].len = 0;
  v28[0].baseBuffer[0] = 0;
  v28[0].intvalue = 0;
  v28[0].whiteSpaceStart_p = nullptr;
  v28[0].whiteSpaceEnd_p = nullptr;
  v28[0].next = nullptr;
  idLexer::ReadToken(this: p_src, token: &v26, a3: v12, a4: v10, a5: v9);
  if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "=", a3: v14, a4: v13) != 0 )
  {
    if ( idStr::Cmp(s1: v26.data, s2: name) == 0 )
    {
LABEL_20:
      idStr::FreeData(this: &v28[0]);
      idStr::FreeData(this: &v27);
      idStr::FreeData(this: &v26);
      return 1;
    }
  }
  else
  {
    idLexer::ReadToken(this: p_src, token: &v27, a3: v17, a4: v16, a5: v15);
    if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "=", a3: v19, a4: v18) != 0 )
    {
      if ( (type == nullptr || *type == 0 || idStr::Cmp(s1: v26.data, s2: type) == 0)
        && (ops == nullptr || *ops == 0)
        && idStr::Cmp(s1: v27.data, s2: name) == 0 )
      {
        goto LABEL_20;
      }
    }
    else
    {
      idLexer::ReadToken(this: p_src, token: v28, a3: v22, a4: v21, a5: v20);
      if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "=", a3: v24, a4: v23) != 0
        && (type == nullptr || *type == 0 || idStr::Cmp(s1: v26.data, s2: type) == 0)
        && (ops == nullptr || *ops == 0 || idStr::Cmp(s1: v27.data, s2: ops) == 0)
        && idStr::Cmp(s1: v28[0].data, s2: name) == 0 )
      {
        goto LABEL_20;
      }
    }
  }
  idLexer::SetScriptP(this: p_src, p: v11);
  idStr::FreeData(this: &v28[0]);
  idStr::FreeData(this: &v27);
  idStr::FreeData(this: &v26);
  return 0;
}


// ========================================================================
// __unwind$113159
// EA  : 0x82F98F38
// RVA : 0x00F98F38
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_113159()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 80));
}


// ========================================================================
// __unwind$113160
// EA  : 0x82F98F60
// RVA : 0x00F98F60
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_113160()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 160));
}


// ========================================================================
// __unwind$113161
// EA  : 0x82F98F88
// RVA : 0x00F98F88
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_113161()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 240));
}


// ========================================================================
// ?WriteType@idTypeInfoFile@@QAAXPBD00@Z
// EA  : 0x82F98FB0
// RVA : 0x00F98FB0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteType(idTypeInfoFile *this, const char *type, const char *ops, char *name)
{
  char *v7; // r3
  BOOL writeType; // r11
  int v9; // r11
  char *v10; // r28
  idFile_vtbl *v11; // r29
  char *v12; // r26
  char *v13; // r27
  char *v14; // r3
  int v15; // r11
  char *v16; // r28
  idFile_vtbl *v17; // r29
  char *v18; // r27
  char *v19; // r3
  int v20; // r11
  int v21; // r10
  char *v22; // r11
  int v23; // r9

  writeType = this->settings.writeType;
  v7 = name;
  if ( writeType && type != nullptr && *type != 0 )
  {
    if ( ops != nullptr && *ops != 0 )
    {
      v9 = *name;
      if ( (v9 < 97 || v9 > 122) && (v9 < 65 || v9 > 90) && v9 != 95 )
        v7 = idStr::CStyleQuote(str: name);
      v10 = v7;
      v11 = this->fp->__vftable;
      v12 = idStr::CStyleQuote(str: ops);
      v13 = idStr::CStyleQuote(str: type);
      v14 = idTypeInfoFile::OutputTabs(newline: &this->newline, indent: this->indent);
      v11->WriteFloatString(this: this->fp, a2: "%s%s %s %s = ", v14, v13, v12, v10);
    }
    else
    {
      v15 = *name;
      if ( (v15 < 97 || v15 > 122) && (v15 < 65 || v15 > 90) && v15 != 95 )
        v7 = idStr::CStyleQuote(str: name);
      v16 = v7;
      v17 = this->fp->__vftable;
      v18 = idStr::CStyleQuote(str: type);
      v19 = idTypeInfoFile::OutputTabs(newline: &this->newline, indent: this->indent);
      v17->WriteFloatString(this: this->fp, a2: "%s%s %s = ", v19, v18, v16);
    }
  }
  else
  {
    v20 = *name;
    if ( (v20 < 97 || v20 > 122) && (v20 < 65 || v20 > 90) && v20 != 95 )
      v7 = idStr::CStyleQuote(str: name);
    v22 = tabs;
    v23 = lastIndent;
    lastIndent = this->indent;
    v21 = lastIndent;
    tabs[v23 + 1] = 9;
    tabs[v21 + 1] = 0;
    tabs[0] = 10;
    if ( !this->newline )
    {
      v22 = &tabs[1];
      this->newline = true;
    }
    this->fp->WriteFloatString(this: this->fp, a2: "%s%s = ", v22, v7);
  }
}


// ========================================================================
// ?WriteArrayElementType@idTypeInfoFile@@QAAXPBD00H@Z
// EA  : 0x82F991D8
// RVA : 0x00F991D8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idTypeInfoFile::WriteArrayElementType(
        idTypeInfoFile *this,
        const char *type,
        const char *ops,
        const char *name,
        __int64 i,
        __int64 a6)
{
  va *v9; // r3
  int v10; // [sp+8h] [-1068h]
  int v11; // [sp+Ch] [-1064h]
  int v12; // [sp+10h] [-1060h]
  int v13; // [sp+14h] [-105Ch]
  int v14; // [sp+18h] [-1058h]
  int v15; // [sp+1Ch] [-1054h]
  va v16; // [sp+50h] [-1020h] BYREF

  v9 = va::va(
         this: &v16,
         fmt: "%s[%d]",
         a3: *(__int64 *)((char *)&i + 4),
         a4: i,
         a5: a6,
         a6: v10,
         a7: v11,
         a8: v12,
         a9: v13,
         a10: v14,
         a11: v15);
  idTypeInfoFile::WriteType(this, type, ops, name: v9->buffer);
}


// ========================================================================
// ?WriteValueString@idTypeInfoFile@@QAAXAAVidStr@@@Z
// EA  : 0x82F99228
// RVA : 0x00F99228
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteValueString(idTypeInfoFile *this, idStr *value)
{
  this->fp->Write(this: this->fp, a2: value->data, a3: value->len);
  this->fp->Write(this: this->fp, a2: ";", a3: 1u);
}


// ========================================================================
// ?ReadBool@idTypeInfoFile@@QAAXAA_N@Z
// EA  : 0x82F99298
// RVA : 0x00F99298
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadBool(idTypeInfoFile *this, bool *b, int a3, int a4, __int64 a5)
{
  idLexer *p_src; // r28
  __int64 v7; // r8
  __int64 v8; // r6
  __int64 v9; // r10
  int v10; // [sp+8h] [-B8h]
  int v11; // [sp+Ch] [-B4h]
  int v12; // [sp+10h] [-B0h]
  int v13; // [sp+14h] [-ACh]
  int v14; // [sp+18h] [-A8h]
  int v15; // [sp+1Ch] [-A4h]
  idStr v16; // [sp+50h] [-70h] BYREF
  int v17; // [sp+84h] [-3Ch]
  float v18; // [sp+88h] [-38h]
  int v19; // [sp+8Ch] [-34h]
  int v20; // [sp+90h] [-30h]
  int v21; // [sp+94h] [-2Ch]

  v16.len = 0;
  v16.allocedAndFlag = 20;
  v16.data = v16.baseBuffer;
  v18 = -3.4028235e38;
  v16.baseBuffer[0] = 0;
  v17 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  p_src = &this->src;
  idLexer::ExpectTokenType(this: &this->src, type: 4, token: (unsigned int)&v16, a4: a5);
  if ( idStr::Cmp(s1: v16.data, s2: "true") != 0 )
  {
    if ( idStr::Cmp(s1: v16.data, s2: "false") != 0 )
    {
      HIDWORD(v8) = v16.data;
      idLexer::Warning(
        this: p_src,
        str: "Unknown value '%s' for boolean",
        a3: v8,
        a4: v7,
        a5: v9,
        a6: v10,
        a7: v11,
        a8: v12,
        a9: v13,
        a10: v14,
        a11: v15);
    }
    else
    {
      *b = false;
    }
  }
  else
  {
    *b = true;
  }
  idLexer::ExpectTokenString(this: p_src, string: ";", a3: v8, a4: v7);
  idStr::FreeData(this: &v16);
}


// ========================================================================
// __unwind$113499
// EA  : 0x82F99374
// RVA : 0x00F99374
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_113499()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?WriteVec3@idTypeInfoFile@@QAAXABVidVec3@@@Z
// EA  : 0x82F993A0
// RVA : 0x00F993A0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteVec3(idTypeInfoFile *this, const idVec3 *v)
{
  idFile *fp; // r3

  fp = this->fp;
  if ( fp != nullptr )
  {
    fp->WriteFloatString(this: fp, a2: "{");
    ++this->indent;
  }
  idTypeInfoFile::WriteType(this, type: "float", ops: &byte_8200D768, name: "x");
  this->fp->WriteFloatString(this: this->fp, a2: "%f;", (unsigned int)COERCE_UNSIGNED_INT64(v->x));
  idTypeInfoFile::WriteType(this, type: "float", ops: &byte_8200D768, name: "y");
  this->fp->WriteFloatString(this: this->fp, a2: "%f;", (unsigned int)COERCE_UNSIGNED_INT64(v->y));
  idTypeInfoFile::WriteType(this, type: "float", ops: &byte_8200D768, name: "z");
  this->fp->WriteFloatString(this: this->fp, a2: "%f;", (unsigned int)COERCE_UNSIGNED_INT64(v->z));
  idTypeInfoFile::WriteClosingBrace(this);
}


// ========================================================================
// ?ReadVec3@idTypeInfoFile@@QAAXAAVidVec3@@@Z
// EA  : 0x82F994C0
// RVA : 0x00F994C0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadVec3(idTypeInfoFile *this, idVec3 *v, __int64 a3, __int64 a4)
{
  idLexer *p_src; // r30
  __int64 v7; // r8
  __int64 v8; // r6
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r8
  __int64 v16; // r6
  __int64 v17; // r8
  __int64 v18; // r6

  p_src = &this->src;
  idLexer::ExpectTokenString(this: &this->src, string: "{", a3, a4);
  ++this->indent;
  LODWORD(v7) = (unsigned __int8)idTypeInfoFile::CheckType(this, type: "float", ops: &byte_8200D768, name: "x");
  if ( (_DWORD)v7 != 0 )
  {
    v->x = idLexer::ParseFloat(this: p_src, errorFlag: nullptr, a3: v8, a4: v7);
    idLexer::ExpectTokenString(this: p_src, string: ";", a3: v10, a4: v9);
  }
  if ( (unsigned __int8)idTypeInfoFile::CheckType(this, type: "float", ops: &byte_8200D768, name: "y") != 0 )
  {
    v->y = idLexer::ParseFloat(this: p_src, errorFlag: nullptr, a3: v12, a4: v11);
    idLexer::ExpectTokenString(this: p_src, string: ";", a3: v14, a4: v13);
  }
  if ( (unsigned __int8)idTypeInfoFile::CheckType(this, type: "float", ops: &byte_8200D768, name: "z") != 0 )
  {
    v->z = idLexer::ParseFloat(this: p_src, errorFlag: nullptr, a3: v16, a4: v15);
    idLexer::ExpectTokenString(this: p_src, string: ";", a3: v18, a4: v17);
  }
  --this->indent;
  idLexer::ExpectTokenString(this: p_src, string: "}", a3: v16, a4: v15);
}


// ========================================================================
// ?WriteVecX@idTypeInfoFile@@QAAXABVidVecX@@@Z
// EA  : 0x82F995F0
// RVA : 0x00F995F0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteVecX(idTypeInfoFile *this, const idVecX *v)
{
  float *p; // r3
  int size; // r30
  idFile_vtbl *v5; // r29
  char *v6; // r3

  p = v->p;
  size = v->size;
  if ( p != nullptr )
  {
    v5 = this->fp->__vftable;
    v6 = idStr::FloatArrayToString(array: p, length: v->size, precision: 8);
    v5->WriteFloatString(this: this->fp, a2: "%d %s;", size, v6);
  }
  else
  {
    this->fp->WriteFloatString(this: this->fp, a2: "0;");
  }
}


// ========================================================================
// ?ReadVecX@idTypeInfoFile@@QAAXAAVidVecX@@@Z
// EA  : 0x82F99670
// RVA : 0x00F99670
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadVecX(idTypeInfoFile *this, idVecX *v, __int64 a3, __int64 a4)
{
  idLexer *p_src; // r29
  signed int v6; // r31
  __int64 v7; // r8
  __int64 v8; // r6
  float *v9; // r30

  p_src = &this->src;
  v6 = idLexer::ParseInt(this: &this->src, a2: (int)v, a3, a4);
  idVecX::SetSize(this: v, newSize: v6);
  if ( v6 > 0 )
  {
    v9 = v->p - 1;
    do
    {
      *++v9 = idLexer::ParseFloat(this: p_src, errorFlag: nullptr, a3: v8, a4: v7);
      --v6;
    }
    while ( v6 != 0 );
  }
  idLexer::ExpectTokenString(this: p_src, string: ";", a3: v8, a4: v7);
}


// ========================================================================
// ?WriteMatX@idTypeInfoFile@@QAAXABVidMatX@@@Z
// EA  : 0x82F996E0
// RVA : 0x00F996E0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteMatX(idTypeInfoFile *this, const idMatX *m)
{
  float *mat; // r3
  int numRows; // r30
  int numColumns; // r29
  idFile_vtbl *v6; // r28
  char *v7; // r3

  mat = m->mat;
  numRows = m->numRows;
  numColumns = m->numColumns;
  if ( mat != nullptr )
  {
    v6 = this->fp->__vftable;
    v7 = idStr::FloatArrayToString(array: mat, length: numColumns * numRows, precision: 8);
    v6->WriteFloatString(this: this->fp, a2: "%d %d %s;", numRows, numColumns, v7);
  }
  else
  {
    this->fp->WriteFloatString(this: this->fp, a2: "0 0;");
  }
}


// ========================================================================
// ?ReadMatX@idTypeInfoFile@@QAAXAAVidMatX@@@Z
// EA  : 0x82F99768
// RVA : 0x00F99768
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadMatX(idTypeInfoFile *this, idMatX *m, __int64 a3, __int64 a4)
{
  idLexer *p_src; // r29
  unsigned int v6; // r31
  __int64 v7; // r8
  __int64 v8; // r6
  int v9; // r4
  unsigned int v10; // r28
  __int64 v11; // r8
  __int64 v12; // r6
  int v13; // r31
  float *v14; // r30

  p_src = &this->src;
  v6 = idLexer::ParseInt(this: &this->src, a2: (int)m, a3, a4);
  v10 = idLexer::ParseInt(this: p_src, a2: v9, a3: v8, a4: v7);
  idMatX::SetSize(this: m, rows: v6, columns: v10);
  v13 = v10 * v6;
  if ( v13 > 0 )
  {
    v14 = m->mat - 1;
    do
    {
      *++v14 = idLexer::ParseFloat(this: p_src, errorFlag: nullptr, a3: v12, a4: v11);
      --v13;
    }
    while ( v13 != 0 );
  }
  idLexer::ExpectTokenString(this: p_src, string: ";", a3: v12, a4: v11);
}


// ========================================================================
// ?WriteAngles@idTypeInfoFile@@QAAXABVidAngles@@@Z
// EA  : 0x82F997E8
// RVA : 0x00F997E8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteAngles(idTypeInfoFile *this, const idAngles *a)
{
  idFile *fp; // r3

  fp = this->fp;
  if ( fp != nullptr )
  {
    fp->WriteFloatString(this: fp, a2: "{");
    ++this->indent;
  }
  idTypeInfoFile::WriteType(this, type: "float", ops: &byte_8200D768, name: "pitch");
  this->fp->WriteFloatString(this: this->fp, a2: "%f;", (unsigned int)COERCE_UNSIGNED_INT64(a->pitch));
  idTypeInfoFile::WriteType(this, type: "float", ops: &byte_8200D768, name: "yaw");
  this->fp->WriteFloatString(this: this->fp, a2: "%f;", (unsigned int)COERCE_UNSIGNED_INT64(a->yaw));
  idTypeInfoFile::WriteType(this, type: "float", ops: &byte_8200D768, name: "roll");
  this->fp->WriteFloatString(this: this->fp, a2: "%f;", (unsigned int)COERCE_UNSIGNED_INT64(a->roll));
  idTypeInfoFile::WriteClosingBrace(this);
}


// ========================================================================
// ?WriteColor@idTypeInfoFile@@QAAXABVidColor@@@Z
// EA  : 0x82F99908
// RVA : 0x00F99908
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::WriteColor(idTypeInfoFile *this, const idColor *c)
{
  idFile *fp; // r3

  fp = this->fp;
  if ( fp != nullptr )
  {
    fp->WriteFloatString(this: fp, a2: "{");
    ++this->indent;
  }
  idTypeInfoFile::WriteType(this, type: "float", ops: &byte_8200D768, name: "r");
  this->fp->WriteFloatString(this: this->fp, a2: "%f;", (unsigned int)COERCE_UNSIGNED_INT64(c->r));
  idTypeInfoFile::WriteType(this, type: "float", ops: &byte_8200D768, name: "g");
  this->fp->WriteFloatString(this: this->fp, a2: "%f;", (unsigned int)COERCE_UNSIGNED_INT64(c->g));
  idTypeInfoFile::WriteType(this, type: "float", ops: &byte_8200D768, name: "b");
  this->fp->WriteFloatString(this: this->fp, a2: "%f;", (unsigned int)COERCE_UNSIGNED_INT64(c->b));
  idTypeInfoFile::WriteType(this, type: "float", ops: &byte_8200D768, name: "a");
  this->fp->WriteFloatString(this: this->fp, a2: "%f;", (unsigned int)COERCE_UNSIGNED_INT64(c->a));
  idTypeInfoFile::WriteClosingBrace(this);
}


// ========================================================================
// ?ReadColor@idTypeInfoFile@@QAAXAAVidColor@@@Z
// EA  : 0x82F99A68
// RVA : 0x00F99A68
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadColor(idTypeInfoFile *this, idColor *c, __int64 a3, __int64 a4)
{
  idLexer *p_src; // r30
  __int64 v7; // r8
  __int64 v8; // r6
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r8
  __int64 v16; // r6
  __int64 v17; // r8
  __int64 v18; // r6
  __int64 v19; // r8
  __int64 v20; // r6
  __int64 v21; // r8
  __int64 v22; // r6

  p_src = &this->src;
  idLexer::ExpectTokenString(this: &this->src, string: "{", a3, a4);
  ++this->indent;
  LODWORD(v7) = (unsigned __int8)idTypeInfoFile::CheckType(this, type: "float", ops: &byte_8200D768, name: "r");
  if ( (_DWORD)v7 != 0 )
  {
    c->r = idLexer::ParseFloat(this: p_src, errorFlag: nullptr, a3: v8, a4: v7);
    idLexer::ExpectTokenString(this: p_src, string: ";", a3: v10, a4: v9);
  }
  if ( (unsigned __int8)idTypeInfoFile::CheckType(this, type: "float", ops: &byte_8200D768, name: "g") != 0 )
  {
    c->g = idLexer::ParseFloat(this: p_src, errorFlag: nullptr, a3: v12, a4: v11);
    idLexer::ExpectTokenString(this: p_src, string: ";", a3: v14, a4: v13);
  }
  if ( (unsigned __int8)idTypeInfoFile::CheckType(this, type: "float", ops: &byte_8200D768, name: "b") != 0 )
  {
    c->b = idLexer::ParseFloat(this: p_src, errorFlag: nullptr, a3: v16, a4: v15);
    idLexer::ExpectTokenString(this: p_src, string: ";", a3: v18, a4: v17);
  }
  if ( (unsigned __int8)idTypeInfoFile::CheckType(this, type: "float", ops: &byte_8200D768, name: "a") != 0 )
  {
    c->a = idLexer::ParseFloat(this: p_src, errorFlag: nullptr, a3: v20, a4: v19);
    idLexer::ExpectTokenString(this: p_src, string: ";", a3: v22, a4: v21);
  }
  --this->indent;
  idLexer::ExpectTokenString(this: p_src, string: "}", a3: v20, a4: v19);
}


// ========================================================================
// ?ReadUnknown@idTypeInfoFile@@QAAXXZ
// EA  : 0x82F99BE0
// RVA : 0x00F99BE0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadUnknown(idTypeInfoFile *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // r10
  int v5; // r30
  idLexer *p_src; // r26
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  idToken v10; // [sp+50h] [-80h] BYREF

  LODWORD(v4) = byte_821B0000;
  HIDWORD(v4) = 20;
  LODWORD(a4) = v10.baseBuffer;
  v10.len = 0;
  v10.allocedAndFlag = 20;
  v5 = 0;
  v10.data = v10.baseBuffer;
  v10.floatvalue = -3.4028235e38;
  v10.baseBuffer[0] = 0;
  v10.intvalue = 0;
  memset(&v10.whiteSpaceStart_p, 0, 12);
  p_src = &this->src;
  if ( (unsigned __int8)idLexer::ReadToken(this: &this->src, token: &v10, a3, a4, a5: v4) != 0 )
  {
    do
    {
      if ( idStr::Cmp(s1: v10.data, s2: "{") != 0 )
      {
        if ( idStr::Cmp(s1: v10.data, s2: "}") != 0 )
        {
          if ( idStr::Cmp(s1: v10.data, s2: ";") == 0 && v5 <= 0 )
            break;
        }
        else if ( --v5 <= 0 )
        {
          break;
        }
      }
      else
      {
        ++v5;
      }
    }
    while ( (unsigned __int8)idLexer::ReadToken(this: p_src, token: &v10, a3: v9, a4: v8, a5: v7) != 0 );
  }
  idStr::FreeData(this: &v10);
}


// ========================================================================
// __unwind$114130
// EA  : 0x82F99CE0
// RVA : 0x00F99CE0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_114130()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?CheckUnknown@idTypeInfoFile@@QAA_NXZ
// EA  : 0x82F99D08
// RVA : 0x00F99D08
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

int __fastcall idTypeInfoFile::CheckUnknown(idTypeInfoFile *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v5; // r8
  __int64 v6; // r6
  int v7; // r4

  if ( (unsigned __int8)idLexer::CheckTokenString(this: &this->src, string: "<", a3, a4) == 0 )
    return 0;
  idTypeInfoFile::ReadUnknown(this, a2: v7, a3: v6, a4: v5);
  return 1;
}


// ========================================================================
// ?GetStringForIndex@idTypeInfoStrings@@QBAPBDH@Z
// EA  : 0x82F99D70
// RVA : 0x00F99D70
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

char *__fastcall idTypeInfoStrings::GetStringForIndex(idTypeInfoStrings *this, int index)
{
  return this->strings.list[index].data;
}


// ========================================================================
// ?ReadMemory@idTypeInfoFile@@QAA_NPBDH0H@Z
// EA  : 0x82F99D88
// RVA : 0x00F99D88
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

BOOL __fastcall idTypeInfoFile::ReadMemory(
        idTypeInfoFile *this,
        const char *data,
        __int64 name,
        __int64 startLine,
        __int64 a5)
{
  idLexer *p_src; // r31
  int v6; // r30

  p_src = &this->src;
  this->src.flags = 4116;
  v6 = HIDWORD(startLine);
  idLexer::LoadMemory(this: &this->src, ptr: data, name, a4: startLine, a5);
  if ( v6 < 1 )
    v6 = 1;
  p_src->line = v6;
  p_src->lastline = v6;
  return p_src->loaded;
}


// ========================================================================
// ?ReadType@idTypeInfoFile@@QAA_NAAVidStr@@00@Z
// EA  : 0x82F99DF8
// RVA : 0x00F99DF8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

int __fastcall idTypeInfoFile::ReadType(idTypeInfoFile *this, idStr *type, __int64 name)
{
  __int64 v3; // r10
  idStr *v5; // r25
  idStr *v6; // r29
  __int64 v7; // r8
  idLexer *p_src; // r27
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  size_t len; // r28
  __int64 v16; // r8
  __int64 v17; // r6
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  int v21; // r27
  size_t v22; // r28
  __int64 v23; // r8
  __int64 v24; // r6
  __int64 v25; // r10
  __int64 v26; // r8
  int v27; // [sp+8h] [-178h]
  int v28; // [sp+Ch] [-174h]
  int v29; // [sp+10h] [-170h]
  int v30; // [sp+14h] [-16Ch]
  int v31; // [sp+18h] [-168h]
  int v32; // [sp+1Ch] [-164h]
  idToken v33; // [sp+50h] [-130h] BYREF
  idToken v34; // [sp+A0h] [-E0h] BYREF
  idToken v35[2]; // [sp+F0h] [-90h] BYREF

  LODWORD(v3) = byte_821B0000;
  HIDWORD(v3) = v33.baseBuffer;
  v33.len = 0;
  v33.allocedAndFlag = 20;
  v5 = (idStr *)HIDWORD(name);
  v33.floatvalue = -3.4028235e38;
  v6 = (idStr *)name;
  v33.data = v33.baseBuffer;
  v33.baseBuffer[0] = 0;
  v33.intvalue = 0;
  memset(&v33.whiteSpaceStart_p, 0, 12);
  LODWORD(v7) = v34.baseBuffer;
  v34.floatvalue = -3.4028235e38;
  v34.allocedAndFlag = 20;
  v34.data = v34.baseBuffer;
  v34.len = 0;
  v34.baseBuffer[0] = 0;
  v34.intvalue = 0;
  memset(&v34.whiteSpaceStart_p, 0, 12);
  HIDWORD(v7) = v35[0].baseBuffer;
  v35[0].floatvalue = -3.4028235e38;
  v35[0].allocedAndFlag = 20;
  v35[0].data = v35[0].baseBuffer;
  v35[0].len = 0;
  v35[0].baseBuffer[0] = 0;
  v35[0].intvalue = 0;
  v35[0].whiteSpaceStart_p = nullptr;
  v35[0].whiteSpaceEnd_p = nullptr;
  v35[0].next = nullptr;
  p_src = &this->src;
  idLexer::ExpectAnyToken(this: &this->src, token: &v33, a3: name, a4: v7, a5: v3);
  LODWORD(v13) = (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "=", a3: v10, a4: v9);
  if ( (_DWORD)v13 != 0 )
  {
    idStr::Clear(this: type);
    idStr::Clear(this: v5);
    len = v33.len;
    idStr::EnsureAlloced(this: v6, amount: v33.len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v6->data, Src: v33.data, Size: len);
    v6->data[len] = 0;
    v6->len = len;
    idStr::FreeData(this: &v35[0]);
    idStr::FreeData(this: &v34);
    idStr::FreeData(this: &v33);
    return 1;
  }
  else
  {
    idLexer::ExpectAnyToken(this: p_src, token: &v34, a3: v13, a4: v12, a5: v11);
    if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "=", a3: v17, a4: v16) != 0 )
    {
      v21 = v33.len;
      idStr::EnsureAlloced(this: type, amount: v33.len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: type->data, Src: v33.data, Size: v21);
      type->data[v21] = 0;
      type->len = v21;
      idStr::Clear(this: v5);
      v22 = v34.len;
      idStr::EnsureAlloced(this: v6, amount: v34.len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v6->data, Src: v34.data, Size: v22);
      v6->data[v22] = 0;
      v6->len = v22;
      idStr::FreeData(this: &v35[0]);
      idStr::FreeData(this: &v34);
      idStr::FreeData(this: &v33);
      return 1;
    }
    else
    {
      idLexer::ExpectAnyToken(this: p_src, token: v35, a3: v20, a4: v19, a5: v18);
      if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "=", a3: v24, a4: v23) != 0 )
      {
        idStr::operator=(this: type, text: &v33);
        idStr::operator=(this: v5, text: &v34);
        idStr::operator=(this: v6, text: &v35[0]);
        idStr::FreeData(this: &v35[0]);
        idStr::FreeData(this: &v34);
        idStr::FreeData(this: &v33);
        return 1;
      }
      else
      {
        HIDWORD(v26) = v35[0].data;
        idLexer::Error(
          this: p_src,
          str: "Expected 'type ops name =' but found '%s %s %s'",
          a3: __SPAIR64__((unsigned int)v33.data, (unsigned int)v34.data),
          a4: v26,
          a5: v25,
          a6: v27,
          a7: v28,
          a8: v29,
          a9: v30,
          a10: v31,
          a11: v32);
        idStr::FreeData(this: &v35[0]);
        idStr::FreeData(this: &v34);
        idStr::FreeData(this: &v33);
        return 0;
      }
    }
  }
}


// ========================================================================
// __unwind$114445
// EA  : 0x82F9A098
// RVA : 0x00F9A098
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_114445()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 80));
}


// ========================================================================
// __unwind$114446
// EA  : 0x82F9A0C0
// RVA : 0x00F9A0C0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_114446()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 160));
}


// ========================================================================
// __unwind$114447
// EA  : 0x82F9A0E8
// RVA : 0x00F9A0E8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_114447()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 240));
}


// ========================================================================
// ?ReadArrayElementType@idTypeInfoFile@@QAA_NAAVidStr@@00AAH@Z
// EA  : 0x82F9A118
// RVA : 0x00F9A118
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

int __fastcall idTypeInfoFile::ReadArrayElementType(idTypeInfoFile *this, idStr *type, __int64 name, __int64 index)
{
  unsigned __int8 v4; // r30
  __int64 v5; // r10
  idStr *v7; // r25
  idStr *v8; // r29
  _DWORD *v9; // r22
  char v10; // r26
  idLexer *p_src; // r27
  __int64 v12; // r8
  __int64 v13; // r6
  __int64 v14; // r10
  unsigned int v15; // r8
  __int64 v16; // r6
  size_t len; // r28
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r8
  __int64 v21; // r6
  __int64 v22; // r10
  __int64 v23; // r8
  __int64 v24; // r6
  int v25; // r26
  size_t v26; // r28
  __int64 v27; // r8
  __int64 v28; // r6
  __int64 v29; // r8
  __int64 v30; // r6
  __int64 v31; // r8
  __int64 v32; // r6
  int v34; // [sp+8h] [-1E8h]
  int v35; // [sp+Ch] [-1E4h]
  int v36; // [sp+10h] [-1E0h]
  int v37; // [sp+14h] [-1DCh]
  int v38; // [sp+18h] [-1D8h]
  int v39; // [sp+1Ch] [-1D4h]
  idToken v40; // [sp+50h] [-1A0h] BYREF
  idToken v41; // [sp+A0h] [-150h] BYREF
  idToken v42; // [sp+F0h] [-100h] BYREF
  idToken v43; // [sp+140h] [-B0h] BYREF

  v4 = 0;
  LODWORD(v5) = v40.baseBuffer;
  v40.len = 0;
  v40.allocedAndFlag = 20;
  v7 = (idStr *)HIDWORD(name);
  v40.floatvalue = -3.4028235e38;
  v8 = (idStr *)name;
  v9 = (_DWORD *)HIDWORD(index);
  v40.data = v40.baseBuffer;
  v10 = 0;
  v40.baseBuffer[0] = 0;
  v40.intvalue = 0;
  memset(&v40.whiteSpaceStart_p, 0, 12);
  HIDWORD(v5) = v41.baseBuffer;
  v41.floatvalue = -3.4028235e38;
  v41.allocedAndFlag = 20;
  v41.data = v41.baseBuffer;
  v41.len = 0;
  v41.baseBuffer[0] = 0;
  v41.intvalue = 0;
  memset(&v41.whiteSpaceStart_p, 0, 12);
  LODWORD(index) = v42.baseBuffer;
  v42.floatvalue = -3.4028235e38;
  v42.allocedAndFlag = 20;
  v42.data = v42.baseBuffer;
  v42.len = 0;
  v42.baseBuffer[0] = 0;
  v42.intvalue = 0;
  memset(&v42.whiteSpaceStart_p, 0, 12);
  p_src = &this->src;
  idLexer::ExpectAnyToken(this: &this->src, token: &v40, a3: name, a4: index, a5: v5);
  if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "[", a3: v13, a4: v12) != 0 )
  {
    idStr::Clear(this: type);
    idStr::Clear(this: v7);
    len = v40.len;
    idStr::EnsureAlloced(this: v8, amount: v40.len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v8->data, Src: v40.data, Size: len);
    v8->data[len] = 0;
    v8->len = len;
  }
  else
  {
    idLexer::ExpectAnyToken(this: p_src, token: &v41, a3: v16, a4: v15, a5: v14);
    if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "[", a3: v21, a4: v20) != 0 )
    {
      v25 = v40.len;
      idStr::EnsureAlloced(this: type, amount: v40.len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: type->data, Src: v40.data, Size: v25);
      type->data[v25] = 0;
      type->len = v25;
      idStr::Clear(this: v7);
      v26 = v41.len;
      idStr::EnsureAlloced(this: v8, amount: v41.len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v8->data, Src: v41.data, Size: v26);
      LODWORD(v18) = v8->data;
      *(_BYTE *)(v18 + v26) = 0;
      v8->len = v26;
    }
    else
    {
      idLexer::ExpectAnyToken(this: p_src, token: &v42, a3: v24, a4: v23, a5: v22);
      if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "[", a3: v28, a4: v27) == 0 )
        goto LABEL_8;
      idStr::operator=(this: type, text: &v40);
      idStr::operator=(this: v7, text: &v41);
      idStr::operator=(this: v8, text: &v42);
    }
  }
  v10 = 1;
LABEL_8:
  if ( v10 == 0 )
  {
    HIDWORD(v19) = v42.data;
    idLexer::Error(
      this: p_src,
      str: "Expected 'type ops name[n]', found '%s %s %s'",
      a3: __SPAIR64__((unsigned int)v40.data, (unsigned int)v41.data),
      a4: v19,
      a5: v18,
      a6: v34,
      a7: v35,
      a8: v36,
      a9: v37,
      a10: v38,
      a11: v39);
    idStr::FreeData(this: &v42);
    idStr::FreeData(this: &v41);
    goto LABEL_16;
  }
  v43.floatvalue = -3.4028235e38;
  v43.allocedAndFlag = 20;
  v43.data = v43.baseBuffer;
  v43.len = 0;
  v43.baseBuffer[0] = 0;
  v43.intvalue = 0;
  memset(&v43.whiteSpaceStart_p, 0, 12);
  if ( (unsigned __int8)idLexer::ExpectTokenType(this: p_src, type: 3, token: (unsigned int)&v43, a4: v19) == 0 )
  {
    *v9 = -1;
    idStr::FreeData(this: &v43);
    idStr::FreeData(this: &v42);
    idStr::FreeData(this: &v41);
LABEL_16:
    idStr::FreeData(this: &v40);
    return 0;
  }
  *v9 = idToken::GetUnsignedIntValue(this: &v43);
  if ( (unsigned __int8)idLexer::ExpectTokenString(this: p_src, string: "]", a3: v30, a4: v29) != 0
    && (unsigned __int8)idLexer::ExpectTokenString(this: p_src, string: "=", a3: v32, a4: v31) != 0 )
  {
    v4 = 1;
  }
  idStr::FreeData(this: &v43);
  idStr::FreeData(this: &v42);
  idStr::FreeData(this: &v41);
  idStr::FreeData(this: &v40);
  return v4;
}


// ========================================================================
// __unwind$114738
// EA  : 0x82F9A460
// RVA : 0x00F9A460
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_114738()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 80));
}


// ========================================================================
// __unwind$114739
// EA  : 0x82F9A488
// RVA : 0x00F9A488
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_114739()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 160));
}


// ========================================================================
// __unwind$114740
// EA  : 0x82F9A4B0
// RVA : 0x00F9A4B0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_114740()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 240));
}


// ========================================================================
// __unwind$114741
// EA  : 0x82F9A4D8
// RVA : 0x00F9A4D8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_114741()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 320));
}


// ========================================================================
// ?CheckArrayElementType@idTypeInfoFile@@QAA_NAAVidStr@@00AAH@Z
// EA  : 0x82F9A508
// RVA : 0x00F9A508
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

int __fastcall idTypeInfoFile::CheckArrayElementType(
        idTypeInfoFile *this,
        idStr *type,
        idStr *ops,
        idStr *name,
        int *index)
{
  idLexer *p_src; // r28
  unsigned __int64 v6; // r27
  const char *ScriptP; // r20
  char v11; // r21
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  int len; // r22
  __int64 v16; // r6
  __int64 v17; // r8
  __int64 v18; // r8
  unsigned int v19; // r6
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  size_t v23; // r19
  int v24; // r19
  __int64 v25; // r8
  __int64 v26; // r6
  __int64 v27; // r6
  __int64 v28; // r10
  __int64 v29; // r8
  __int64 v30; // r6
  __int64 v31; // r8
  __int64 v32; // r6
  __int64 v33; // r6
  __int64 v35; // r8
  __int64 v36; // r6
  __int64 v37; // r8
  __int64 v38; // r6
  idToken v39; // [sp+50h] [-1B0h] BYREF
  idToken v40; // [sp+A0h] [-160h] BYREF
  idToken v41; // [sp+F0h] [-110h] BYREF
  idToken v42; // [sp+140h] [-C0h] BYREF

  p_src = &this->src;
  v6 = __PAIR64__("[", (unsigned int)type);
  ScriptP = (const char *)idLexer::GetScriptP(this: (idCollisionModelLocal *)&this->src);
  v11 = 0;
  idStr::Clear(this: (idStr *)v6);
  idStr::Clear(this: ops);
  v39.len = 0;
  LODWORD(v12) = -1;
  v39.baseBuffer[0] = 0;
  HIDWORD(v12) = v39.baseBuffer;
  v39.allocedAndFlag = 20;
  *index = -1;
  v39.data = v39.baseBuffer;
  v39.floatvalue = -3.4028235e38;
  v39.intvalue = 0;
  memset(&v39.whiteSpaceStart_p, 0, 12);
  LODWORD(v13) = v40.baseBuffer;
  v40.floatvalue = -3.4028235e38;
  v40.allocedAndFlag = 20;
  v40.data = v40.baseBuffer;
  v40.len = 0;
  v40.baseBuffer[0] = 0;
  v40.intvalue = 0;
  memset(&v40.whiteSpaceStart_p, 0, 12);
  HIDWORD(v13) = v41.baseBuffer;
  v41.floatvalue = -3.4028235e38;
  v41.allocedAndFlag = 20;
  v41.data = v41.baseBuffer;
  v41.len = 0;
  v41.baseBuffer[0] = 0;
  v41.intvalue = 0;
  memset(&v41.whiteSpaceStart_p, 0, 12);
  idLexer::ReadToken(this: p_src, token: &v39, a3: v14, a4: v13, a5: v12);
  len = v39.len;
  idStr::EnsureAlloced(this: name, amount: v39.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: name->data, Src: v39.data, Size: len);
  LODWORD(v16) = name->data;
  *(_BYTE *)(v16 + len) = 0;
  name->len = len;
  if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "[", a3: v16, a4: v17) != 0 )
    goto LABEL_9;
  if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "=", a3: v19, a4: v18) != 0 )
    goto LABEL_8;
  idLexer::ReadToken(this: p_src, token: &v40, a3: v22, a4: v21, a5: v20);
  v23 = v39.len;
  idStr::EnsureAlloced(this: (idStr *)v6, amount: v39.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: *(void **)(v6 + 4), Src: v39.data, Size: v23);
  *(_BYTE *)(*(_DWORD *)(v6 + 4) + v23) = 0;
  *(_DWORD *)v6 = v23;
  v24 = v40.len;
  idStr::EnsureAlloced(this: name, amount: v40.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: name->data, Src: v40.data, Size: v24);
  name->data[v24] = 0;
  name->len = v24;
  if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "[", a3: v26, a4: v25) != 0 )
    goto LABEL_9;
  if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "=", a3: v27, a4: v18) != 0 )
    goto LABEL_8;
  idLexer::ReadToken(this: p_src, token: &v41, a3: v30, a4: v29, a5: v28);
  idStr::operator=(this: (idStr *)v6, text: &v39);
  idStr::operator=(this: ops, text: &v40);
  idStr::operator=(this: name, text: &v41);
  if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "[", a3: v32, a4: v31) != 0 )
  {
LABEL_9:
    v11 = 1;
  }
  else if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "=", a3: v33, a4: v18) != 0 )
  {
LABEL_8:
    idStr::FreeData(this: &v41);
    idStr::FreeData(this: &v40);
    idStr::FreeData(this: &v39);
    return 1;
  }
  if ( v11 != 0 )
  {
    v42.floatvalue = -3.4028235e38;
    v42.allocedAndFlag = 20;
    v42.data = v42.baseBuffer;
    v42.len = 0;
    v42.baseBuffer[0] = 0;
    v42.intvalue = 0;
    memset(&v42.whiteSpaceStart_p, 0, 12);
    if ( (unsigned __int8)idLexer::CheckTokenType(this: p_src, type: 3, token: (unsigned int)&v42, a4: v18) != 0 )
    {
      *index = idToken::GetUnsignedIntValue(this: &v42);
      if ( (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "]", a3: v36, a4: v35) != 0
        && (unsigned __int8)idLexer::CheckTokenString(this: p_src, string: "=", a3: v38, a4: v37) != 0 )
      {
        idStr::FreeData(this: &v42);
        idStr::FreeData(this: &v41);
        idStr::FreeData(this: &v40);
        idStr::FreeData(this: &v39);
        return 1;
      }
    }
    idStr::FreeData(this: &v42);
  }
  idLexer::SetScriptP(this: p_src, p: ScriptP);
  idStr::FreeData(this: &v41);
  idStr::FreeData(this: &v40);
  idStr::FreeData(this: &v39);
  return 0;
}


// ========================================================================
// __unwind$115090
// EA  : 0x82F9A8CC
// RVA : 0x00F9A8CC
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_115090()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 80));
}


// ========================================================================
// __unwind$115091
// EA  : 0x82F9A8F4
// RVA : 0x00F9A8F4
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_115091()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 160));
}


// ========================================================================
// __unwind$115092
// EA  : 0x82F9A91C
// RVA : 0x00F9A91C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_115092()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 240));
}


// ========================================================================
// __unwind$115093
// EA  : 0x82F9A944
// RVA : 0x00F9A944
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_115093()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 320));
}


// ========================================================================
// ?ReadValueString@idTypeInfoFile@@QAAXAAVidStr@@@Z
// EA  : 0x82F9A978
// RVA : 0x00F9A978
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadValueString(idTypeInfoFile *this, idStr *value)
{
  __int64 v2; // r30
  __int64 v4; // r8
  __int64 v5; // r10
  __int64 v6; // r6
  int v7; // r9
  int v8; // r11
  char *v9; // r3
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  idToken v13; // [sp+50h] [-80h] BYREF

  v2 = (unsigned int)value;
  idStr::EnsureAlloced(this: value, amount: 1, keepold: true, geometricGrowth: false);
  LODWORD(v4) = *(_DWORD *)(v2 + 4);
  LODWORD(v5) = 20;
  HIDWORD(v5) = v13.baseBuffer;
  *(_BYTE *)v4 = 0;
  v13.allocedAndFlag = 20;
  v13.floatvalue = -3.4028235e38;
  *(_DWORD *)v2 = 0;
  v13.data = v13.baseBuffer;
  v13.len = 0;
  v13.baseBuffer[0] = 0;
  v13.intvalue = 0;
  memset(&v13.whiteSpaceStart_p, 0, 12);
  if ( (unsigned __int8)idLexer::ExpectAnyToken(this: &this->src, token: &v13, a3: v6, a4: v4, a5: v5) != 0 )
  {
    do
    {
      if ( idStr::Cmp(s1: v13.data, s2: ";") == 0 )
        break;
      if ( v13.whiteSpaceEnd_p > v13.whiteSpaceStart_p && *(_DWORD *)v2 != 0 )
      {
        idStr::EnsureAlloced(this: (idStr *)v2, amount: *(_DWORD *)v2 + 2, keepold: true, geometricGrowth: true);
        *(_BYTE *)(*(_DWORD *)v2 + *(_DWORD *)(v2 + 4)) = 32;
        v7 = *(_DWORD *)(v2 + 4);
        v8 = *(_DWORD *)v2 + 1;
        *(_DWORD *)v2 = v8;
        *(_BYTE *)(v8 + v7) = 0;
      }
      if ( v13.type == 1 )
      {
        v9 = idStr::CStyleQuote(str: v13.data);
        idStr::operator=(this: (idStr *)v2, text: v9);
      }
      else
      {
        idStr::Append(this: (idStr *)v2, text: &v13);
      }
    }
    while ( (unsigned __int8)idLexer::ExpectAnyToken(this: &this->src, token: &v13, a3: v12, a4: v11, a5: v10) != 0 );
  }
  idStr::FreeData(this: &v13);
}


// ========================================================================
// __unwind$115459
// EA  : 0x82F9AACC
// RVA : 0x00F9AACC
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_115459()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?ReadStr@idTypeInfoFile@@QAAXAAVidStr@@@Z
// EA  : 0x82F9AB00
// RVA : 0x00F9AB00
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadStr(idTypeInfoFile *this, idStr *s, int a3, int a4, __int64 a5)
{
  idLexer *p_src; // r28
  int len; // r27
  __int64 v8; // r8
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  __int64 v12; // r6
  idToken v13; // [sp+50h] [-80h] BYREF

  v13.len = 0;
  v13.allocedAndFlag = 20;
  v13.data = v13.baseBuffer;
  v13.floatvalue = -3.4028235e38;
  v13.baseBuffer[0] = 0;
  v13.intvalue = 0;
  memset(&v13.whiteSpaceStart_p, 0, 12);
  p_src = &this->src;
  if ( (unsigned __int8)idLexer::CheckTokenType(this: &this->src, type: 1, token: (unsigned int)&v13, a4: a5) != 0 )
  {
    len = v13.len;
    idStr::EnsureAlloced(this: s, amount: v13.len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: s->data, Src: v13.data, Size: len);
    s->data[len] = 0;
    s->len = len;
  }
  else
  {
    idStr::Clear(this: s);
    idLexer::ExpectAnyToken(this: p_src, token: &v13, a3: v11, a4: v10, a5: v9);
  }
  LODWORD(v12) = &v13;
  HIDWORD(v12) = 41;
  idLexer::ExpectTokenType(this: p_src, type: 5, token: v12, a4: v8);
  idStr::FreeData(this: &v13);
}


// ========================================================================
// __unwind$115553
// EA  : 0x82F9ABE0
// RVA : 0x00F9ABE0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_115553()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?ReadMemoryFile@idTypeInfoFile@@QAA_NXZ
// EA  : 0x82F9ACC8
// RVA : 0x00F9ACC8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

int __fastcall idTypeInfoFile::ReadMemoryFile(idTypeInfoFile *this)
{
  int result; // r3
  idFile_Memory *fp; // r30
  const char *filePtr; // r29
  int v5; // r28
  int v6; // r3
  __int64 v7; // r8
  __int64 v8; // r10

  result = (int)_RTDynamicCast(
                  inptr: this->fp,
                  VfDelta: 0,
                  SrcType: &idFile `RTTI Type Descriptor',
                  TargetType: &idFile_Memory `RTTI Type Descriptor',
                  isReference: 0);
  if ( result != 0 )
  {
    fp = (idFile_Memory *)this->fp;
    idFile_Memory::MakeReadOnly(this: fp);
    filePtr = fp->filePtr;
    v5 = (int)fp->GetFullPath(this: fp);
    v6 = fp->Length(this: fp);
    HIDWORD(v7) = 4116;
    this->src.flags = 4116;
    idLexer::LoadMemory(this: &this->src, ptr: filePtr, name: __SPAIR64__(v6, v5), a4: v7, a5: v8);
    this->src.line = 1;
    this->src.lastline = 1;
    return 1;
  }
  return result;
}


// ========================================================================
// ?ExpectType@idTypeInfoFile@@QAA_NPBD00@Z
// EA  : 0x82F9AD88
// RVA : 0x00F9AD88
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

int __fastcall idTypeInfoFile::ExpectType(idTypeInfoFile *this, char *type, char *ops, const char *name)
{
  __int64 v8; // r6
  int v9; // r26
  int v11; // [sp+8h] [-128h]
  int v12; // [sp+Ch] [-124h]
  int v13; // [sp+10h] [-120h]
  int v14; // [sp+14h] [-11Ch]
  int v15; // [sp+18h] [-118h]
  int v16; // [sp+1Ch] [-114h]
  idStr v17; // [sp+90h] [-A0h] BYREF
  idStr v18; // [sp+B0h] [-80h] BYREF
  idStr v19[3]; // [sp+D0h] [-60h] BYREF

  v18.len = 0;
  v18.allocedAndFlag = 20;
  v18.data = v18.baseBuffer;
  v18.baseBuffer[0] = 0;
  v17.allocedAndFlag = 20;
  v17.data = v17.baseBuffer;
  v17.len = 0;
  v17.baseBuffer[0] = 0;
  v19[0].allocedAndFlag = 20;
  v19[0].data = v19[0].baseBuffer;
  v19[0].len = 0;
  v19[0].baseBuffer[0] = 0;
  LODWORD(v8) = v19;
  HIDWORD(v8) = &v17;
  v9 = idTypeInfoFile::ReadType(this, type: &v18, name: v8);
  if ( type != nullptr && *type != 0 )
  {
    if ( v18.len == 0 )
    {
      idStr::operator=(this: &v18, text: type);
      idStr::operator=(this: &v17, text: ops);
    }
  }
  else
  {
    idStr::Clear(this: &v18);
    idStr::Clear(this: &v17);
  }
  if ( ops != nullptr && *ops != 0 )
  {
    if ( v17.len == 0 )
      idStr::operator=(this: &v17, text: ops);
  }
  else
  {
    idStr::Clear(this: &v17);
  }
  if ( (_BYTE)v9 != 0
    && (idStr::Cmp(s1: v19[0].data, s2: name) != 0
     || idStr::Cmp(s1: v18.data, s2: type) != 0
     || idStr::Cmp(s1: v17.data, s2: ops) != 0) )
  {
    idTypeInfoFile::Warning(
      this,
      str: "Expected '%s %s %s' but found '%s %s %s'",
      a3: __SPAIR64__((unsigned int)type, (unsigned int)ops),
      a4: __SPAIR64__((unsigned int)name, (unsigned int)v18.data),
      a5: __SPAIR64__((unsigned int)v17.data, (unsigned int)v19[0].data),
      a6: v11,
      a7: v12,
      a8: v13,
      a9: v14,
      a10: v15,
      a11: v16);
    v9 = 0;
  }
  idStr::FreeData(this: v19);
  idStr::FreeData(this: &v17);
  idStr::FreeData(this: &v18);
  return v9;
}


// ========================================================================
// __unwind$115825
// EA  : 0x82F9AF1C
// RVA : 0x00F9AF1C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_115825()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 176));
}


// ========================================================================
// __unwind$115826
// EA  : 0x82F9AF44
// RVA : 0x00F9AF44
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_115826()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 144));
}


// ========================================================================
// __unwind$115827
// EA  : 0x82F9AF6C
// RVA : 0x00F9AF6C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_115827()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 208));
}


// ========================================================================
// ?ExpectArrayElementType@idTypeInfoFile@@QAA_NPBD00AAH@Z
// EA  : 0x82F9AFA0
// RVA : 0x00F9AFA0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

int __fastcall idTypeInfoFile::ExpectArrayElementType(
        idTypeInfoFile *this,
        char *type,
        char *ops,
        const char *name,
        __int64 index)
{
  __int64 v9; // r6
  int v10; // r25
  int v12; // [sp+8h] [-148h]
  int v13; // [sp+Ch] [-144h]
  int v14; // [sp+10h] [-140h]
  int v15; // [sp+14h] [-13Ch]
  int v16; // [sp+18h] [-138h]
  int v17; // [sp+1Ch] [-134h]
  idStr v18; // [sp+A0h] [-B0h] BYREF
  idStr v19; // [sp+C0h] [-90h] BYREF
  idStr v20[3]; // [sp+E0h] [-70h] BYREF

  v19.len = 0;
  v19.allocedAndFlag = 20;
  v19.data = v19.baseBuffer;
  v19.baseBuffer[0] = 0;
  v18.allocedAndFlag = 20;
  v18.data = v18.baseBuffer;
  v18.len = 0;
  v18.baseBuffer[0] = 0;
  LODWORD(index) = v20[0].baseBuffer;
  v20[0].allocedAndFlag = 20;
  v20[0].data = v20[0].baseBuffer;
  v20[0].len = 0;
  v20[0].baseBuffer[0] = 0;
  LODWORD(v9) = v20;
  HIDWORD(v9) = &v18;
  v10 = idTypeInfoFile::ReadArrayElementType(this, type: &v19, name: v9, index);
  if ( type != nullptr && *type != 0 )
  {
    if ( v19.len == 0 )
    {
      idStr::operator=(this: &v19, text: type);
      idStr::operator=(this: &v18, text: ops);
    }
  }
  else
  {
    idStr::Clear(this: &v19);
    idStr::Clear(this: &v18);
  }
  if ( ops != nullptr && *ops != 0 )
  {
    if ( v18.len == 0 )
      idStr::operator=(this: &v18, text: ops);
  }
  else
  {
    idStr::Clear(this: &v18);
  }
  if ( (_BYTE)v10 != 0
    && (idStr::Cmp(s1: v20[0].data, s2: name) != 0
     || idStr::Cmp(s1: v19.data, s2: type) != 0
     || idStr::Cmp(s1: v18.data, s2: ops) != 0) )
  {
    idTypeInfoFile::Warning(
      this,
      str: "Expected '%s %s %s[n]' but found '%s %s %s[%d]'",
      a3: __SPAIR64__((unsigned int)type, (unsigned int)ops),
      a4: __SPAIR64__((unsigned int)name, (unsigned int)v19.data),
      a5: __SPAIR64__((unsigned int)v18.data, (unsigned int)v20[0].data),
      a6: v12,
      a7: v13,
      a8: v14,
      a9: v15,
      a10: v16,
      a11: v17);
    v10 = 0;
  }
  idStr::FreeData(this: v20);
  idStr::FreeData(this: &v18);
  idStr::FreeData(this: &v19);
  return v10;
}


// ========================================================================
// __unwind$115973
// EA  : 0x82F9B140
// RVA : 0x00F9B140
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_115973()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 192));
}


// ========================================================================
// __unwind$115974
// EA  : 0x82F9B168
// RVA : 0x00F9B168
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_115974()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 160));
}


// ========================================================================
// __unwind$115975
// EA  : 0x82F9B190
// RVA : 0x00F9B190
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_115975()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 224));
}


// ========================================================================
// ?ReadAngles@idTypeInfoFile@@QAAXAAVidAngles@@@Z
// EA  : 0x82F9B1B8
// RVA : 0x00F9B1B8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoFile::ReadAngles(idTypeInfoFile *this, idAngles *a, __int64 a3, __int64 a4)
{
  idLexer *p_src; // r31
  __int64 v7; // r8
  __int64 v8; // r6
  __int64 v9; // r6
  __int64 v10; // r8
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r8
  __int64 v16; // r6
  __int64 v17; // r8
  __int64 v18; // r6
  __int64 v19; // r8
  __int64 v20; // r6

  p_src = &this->src;
  idLexer::ExpectTokenString(this: &this->src, string: "{", a3, a4);
  ++this->indent;
  idTypeInfoFile::ExpectType(this, type: "float", ops: &byte_8200D768, name: "pitch");
  a->pitch = idLexer::ParseFloat(this: p_src, errorFlag: nullptr, a3: v8, a4: v7);
  LODWORD(v9) = &unk_821C0000;
  idLexer::ExpectTokenString(this: p_src, string: ";", a3: v9, a4: v10);
  idTypeInfoFile::ExpectType(this, type: "float", ops: &byte_8200D768, name: "yaw");
  a->yaw = idLexer::ParseFloat(this: p_src, errorFlag: nullptr, a3: v12, a4: v11);
  idLexer::ExpectTokenString(this: p_src, string: ";", a3: v14, a4: v13);
  idTypeInfoFile::ExpectType(this, type: "float", ops: &byte_8200D768, name: "roll");
  a->roll = idLexer::ParseFloat(this: p_src, errorFlag: nullptr, a3: v16, a4: v15);
  idLexer::ExpectTokenString(this: p_src, string: ";", a3: v18, a4: v17);
  --this->indent;
  idLexer::ExpectTokenString(this: p_src, string: "}", a3: v20, a4: v19);
}


// ========================================================================
// ?Shutdown@idTypeInfoStrings@@QAAXXZ
// EA  : 0x82F9B2C8
// RVA : 0x00F9B2C8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void __fastcall idTypeInfoStrings::Shutdown(idTypeInfoStrings *this)
{
  idStr *list; // r3

  if ( this->strings.listStatic == 0 || this->strings.listStatic == 2 )
  {
    list = this->strings.list;
    if ( this->strings.list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->strings.size);
    this->strings.list = nullptr;
    this->strings.size = 0;
  }
  this->strings.num = 0;
  idHashIndex::Clear(this: &this->stringHash);
}


// ========================================================================
// ?FindString@idTypeInfoStrings@@QAAHPBD@Z
// EA  : 0x82F9B340
// RVA : 0x00F9B340
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

int __fastcall idTypeInfoStrings::FindString(idTypeInfoStrings *this, const char *s)
{
  idHashIndex *p_stringHash; // r30
  int KeyForString; // r25
  int v6; // r29
  int indexSize; // r11
  int v8; // r6
  idStr v10[3]; // [sp+50h] [-60h] BYREF

  p_stringHash = &this->stringHash;
  KeyForString = idHashIndex::GenerateKeyForString(this: &this->stringHash, string: s, caseSensitive: true);
  v6 = this->stringHash.hash[this->stringHash.lookupMask & KeyForString & this->stringHash.hashMask];
  if ( v6 == -1 )
  {
LABEL_4:
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idStr::idStr(this: v10, text: s);
    v6 = idList<idStr,5>::Append((idList<idStr,5> *)this, obj: v10);
    idStr::FreeData(this: v10);
    indexSize = p_stringHash->indexSize;
    if ( p_stringHash->hash == idHashIndex::INVALID_INDEX )
    {
      if ( v6 >= indexSize )
        indexSize = v6 + 1;
      idHashIndex::Allocate(this: p_stringHash, newHashSize: p_stringHash->hashSize, newIndexSize: indexSize);
    }
    else if ( v6 >= indexSize )
    {
      idHashIndex::ResizeIndex(this: p_stringHash, newIndexSize: v6 + 1);
    }
    v8 = KeyForString & p_stringHash->hashMask;
    p_stringHash->indexChain[v6] = p_stringHash->hash[v8];
    p_stringHash->hash[v8] = v6;
    idMem::PopHeap(this: &mem);
  }
  else
  {
    while ( idStr::Cmp(s1: this->strings.list[v6].data, s2: s) != 0 )
    {
      v6 = p_stringHash->indexChain[p_stringHash->lookupMask & v6];
      if ( v6 == -1 )
        goto LABEL_4;
    }
  }
  return v6;
}


// ========================================================================
// __unwind$116278
// EA  : 0x82F9B48C
// RVA : 0x00F9B48C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfofile.cpp
// ========================================================================

void _unwind_116278()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}

