
// ========================================================================
// ?SetModifiedFlags@idCVarSystemLocal@@UAAXH@Z
// EA  : 0x82EFE520
// RVA : 0x00EFE520
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVarSystemLocal::SetModifiedFlags(idCVarSystemLocal *this, int flags)
{
  this->modifiedFlags |= flags;
}


// ========================================================================
// ?ClearModifiedFlags@idCVarSystemLocal@@UAAXH@Z
// EA  : 0x82EFE530
// RVA : 0x00EFE530
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVarSystemLocal::ClearModifiedFlags(idCVarSystemLocal *this, int flags)
{
  this->modifiedFlags &= ~flags;
}


// ========================================================================
// ?cvarsModified_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EFE540
// RVA : 0x00EFE540
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall cvarsModified_f(const idCmdArgs *args)
{
  cvarSystem->ReportModifiedCVars(this: cvarSystem);
}


// ========================================================================
// ?SetCVarBool@idCVarSystemLocal@@UAAXPBD_NH@Z
// EA  : 0x82EFE640
// RVA : 0x00EFE640
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVarSystemLocal::SetCVarBool(idCVarSystemLocal *this, const char *name, bool value, int flags)
{
  idStr *v7; // r3
  idStr v8[2]; // [sp+50h] [-50h] BYREF

  v7 = idStr::idStr(this: v8, b: value);
  this->SetCVarString(this, a2: name, a3: v7->data, a4: flags);
  idStr::FreeData(this: v8);
}


// ========================================================================
// __unwind$116444
// EA  : 0x82EFE698
// RVA : 0x00EFE698
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_116444()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?SetCVarInteger@idCVarSystemLocal@@UAAXPBDHH@Z
// EA  : 0x82EFE6C8
// RVA : 0x00EFE6C8
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVarSystemLocal::SetCVarInteger(idCVarSystemLocal *this, const char *name, int value, int flags)
{
  idStr *v7; // r3
  idStr v8[2]; // [sp+50h] [-50h] BYREF

  v7 = idStr::idStr(this: v8, i: value);
  this->SetCVarString(this, a2: name, a3: v7->data, a4: flags);
  idStr::FreeData(this: v8);
}


// ========================================================================
// __unwind$116479
// EA  : 0x82EFE720
// RVA : 0x00EFE720
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_116479()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?SetCVarFloat@idCVarSystemLocal@@UAAXPBDMH@Z
// EA  : 0x82EFE750
// RVA : 0x00EFE750
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVarSystemLocal::SetCVarFloat(
        idCVarSystemLocal *this,
        const char *name,
        double value,
        int flags,
        int a5)
{
  idStr *v8; // r3
  idStr v9[2]; // [sp+50h] [-50h] BYREF

  v8 = idStr::idStr(this: v9, f: value);
  this->SetCVarString(this, a2: name, a3: v8->data, a4: a5);
  idStr::FreeData(this: v9);
}


// ========================================================================
// __unwind$116511
// EA  : 0x82EFE7A4
// RVA : 0x00EFE7A4
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_116511()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetCVarString@idCVarSystemLocal@@UBAPBDPBD0@Z
// EA  : 0x82EFE7D0
// RVA : 0x00EFE7D0
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

char *__fastcall idCVarSystemLocal::GetCVarString(idCVarSystemLocal *this, const char *name, const char *defValue)
{
  idCVar *v4; // r3

  v4 = this->Find(this, a2: name);
  if ( v4 != nullptr )
    return v4->valueString.data;
  else
    return (char *)defValue;
}


// ========================================================================
// ?GetCVarBool@idCVarSystemLocal@@UBA_NPBD_N@Z
// EA  : 0x82EFE830
// RVA : 0x00EFE830
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

BOOL __fastcall idCVarSystemLocal::GetCVarBool(idCVarSystemLocal *this, const char *name, int defValue)
{
  idCVar *v4; // r3

  v4 = this->Find(this, a2: name);
  if ( v4 != nullptr )
    return v4->valueInteger != 0;
  else
    return defValue;
}


// ========================================================================
// ?GetCVarInteger@idCVarSystemLocal@@UBAHPBDH@Z
// EA  : 0x82EFE898
// RVA : 0x00EFE898
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

int __fastcall idCVarSystemLocal::GetCVarInteger(idCVarSystemLocal *this, const char *name, int defValue)
{
  idCVar *v4; // r3

  v4 = this->Find(this, a2: name);
  if ( v4 != nullptr )
    return v4->valueInteger;
  else
    return defValue;
}


// ========================================================================
// ?GetCVarFloat@idCVarSystemLocal@@UBAMPBDM@Z
// EA  : 0x82EFE8F8
// RVA : 0x00EFE8F8
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

float __fastcall idCVarSystemLocal::GetCVarFloat(idCVarSystemLocal *this, const char *name, double defValue)
{
  idCVar *v4; // r3
  double valueFloat; // fp1

  v4 = this->Find(this, a2: name);
  if ( v4 != nullptr )
    valueFloat = v4->valueFloat;
  else
    valueFloat = defValue;
  return *((float *)&valueFloat + 1);
}


// ========================================================================
// ?WriteFlaggedVariables@idCVarSystemLocal@@UBAXHPAVidFile@@@Z
// EA  : 0x82EFE958
// RVA : 0x00EFE958
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVarSystemLocal::WriteFlaggedVariables(idCVarSystemLocal *this, int flags, idFile *f)
{
  idCVar *i; // r31

  for ( i = staticVars; i != nullptr; i = i->next )
  {
    if ( (i->flags & flags) != 0 && idStr::Icmp(s1: i->valueString.data, s2: i->resetString) != 0 )
      f->Printf(this: f, a2: "%s \"%s\"\n", i->name, i->valueString.data);
  }
}


// ========================================================================
// ?ReportModifiedCVars@idCVarSystemLocal@@UAAXXZ
// EA  : 0x82EFEA38
// RVA : 0x00EFEA38
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVarSystemLocal::ReportModifiedCVars(idCVarSystemLocal *this)
{
  int v2; // r28
  int v3; // r31
  idCVar **list; // r11
  const char *v5; // r6

  idLib::Printf(fmt: "Modified CVars:\n");
  v2 = 0;
  if ( this->cvars.num > 0 )
  {
    v3 = 0;
    do
    {
      list = this->cvars.list;
      if ( (list[v3]->flags & 0x40000) != 0 )
      {
        list[v3]->flags &= ~0x40000u;
        v5 = "archived";
        if ( (this->cvars.list[v3]->flags & 0x10000) == 0 )
          v5 = &byte_8200D768;
        idLib::Printf(
          fmt: "Cvar '%s' was modified to '%s' %s\n",
          this->cvars.list[v3]->name,
          this->cvars.list[v3]->valueString.data,
          v5);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->cvars.num );
  }
}


// ========================================================================
// ?ClearModifiedCVars@idCVarSystemLocal@@UAAXXZ
// EA  : 0x82EFEB00
// RVA : 0x00EFEB00
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVarSystemLocal::ClearModifiedCVars(idCVarSystemLocal *this)
{
  int v1; // r10
  int v2; // r11
  idCVar *v3; // r9

  v1 = 0;
  if ( this->cvars.num > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      v3 = this->cvars.list[v2++];
      v3->flags &= ~0x40000u;
    }
    while ( v1 < this->cvars.num );
  }
}


// ========================================================================
// ?UpdateValue@idCVar@@IAAXXZ
// EA  : 0x82EFEE00
// RVA : 0x00EFEE00
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVar::UpdateValue(idCVar *this)
{
  int flags; // r11
  char *data; // r28
  int v4; // r29
  __int64 v5; // r9
  const idStr *v6; // r3
  __int64 v7; // r11
  int v8; // r3
  double valueMin; // fp0
  double valueMax; // fp12
  double v11; // fp13
  int v12; // fp0
  __int64 v13; // r10
  idStr *v14; // r3
  long double v15; // fp2
  double v16; // fp13
  double v17; // fp12
  double v18; // fp0
  const idStr *v19; // r3
  const char **valueStrings; // r10
  int v21; // r11
  __int64 v22; // r7
  long double v23; // fp2
  double v24; // fp0
  idCVar::cvarCallback_t *i; // r30
  idStr v26; // [sp+60h] [-90h] BYREF
  idStr v27; // [sp+80h] [-70h] BYREF
  idStr v28[2]; // [sp+A0h] [-50h] BYREF

  flags = this->flags;
  data = this->valueString.data;
  v4 = 0;
  this->flags = flags | 0x20000;
  if ( (flags & 1) != 0 )
  {
    LODWORD(v5) = atol(nptr: data) != 0;
    this->valueInteger = v5;
    this->valueFloat = (float)v5;
    if ( idStr::Icmp(s1: data, s2: "0") != 0 && idStr::Icmp(s1: data, s2: "1") != 0 )
    {
      v6 = idStr::idStr(this: &v26, b: this->valueInteger != 0);
      idStr::operator=(this: &this->valueString, text: v6);
      idStr::FreeData(this: &v26);
    }
    goto LABEL_40;
  }
  if ( (flags & 2) != 0 )
  {
    v8 = atol(nptr: data);
    valueMin = this->valueMin;
    valueMax = this->valueMax;
    this->valueInteger = v8;
    if ( valueMin < valueMax )
    {
      LODWORD(v7) = v8;
      v11 = (float)v7;
      if ( v11 >= valueMin )
      {
        if ( v11 <= valueMax )
          goto LABEL_12;
        v12 = (int)valueMax;
      }
      else
      {
        v12 = (int)valueMin;
      }
      LOBYTE(v4) = 1;
      this->valueInteger = v12;
    }
LABEL_12:
    if ( (_BYTE)v4 != 0 || !idStr::IsNumeric(s: data) )
    {
      v14 = idStr::idStr(this: &v27, i: this->valueInteger);
      idStr::operator=(this: &this->valueString, text: v14);
      idStr::FreeData(this: &v27);
    }
    LODWORD(v13) = this->valueInteger;
    this->valueFloat = (float)v13;
    goto LABEL_40;
  }
  if ( (flags & 4) != 0 )
  {
    v15 = atof(nptr: data);
    v16 = this->valueMin;
    v17 = this->valueMax;
    v18 = (float)*(double *)&v15;
    this->valueFloat = *(double *)&v15;
    if ( v16 < v17 )
    {
      if ( v18 >= v16 )
      {
        if ( v18 <= v17 )
          goto LABEL_23;
        this->valueFloat = v17;
      }
      else
      {
        this->valueFloat = v16;
      }
      LOBYTE(v4) = 1;
    }
LABEL_23:
    if ( (_BYTE)v4 != 0 || !idStr::IsNumeric(s: data) )
    {
      v19 = idStr::idStr(this: v28, f: this->valueFloat);
      idStr::operator=(this: &this->valueString, text: v19);
      idStr::FreeData(this: v28);
    }
    this->valueInteger = (int)this->valueFloat;
    goto LABEL_40;
  }
  valueStrings = this->valueStrings;
  if ( valueStrings != nullptr && *valueStrings != nullptr )
  {
    this->valueInteger = 0;
    if ( *valueStrings != nullptr )
    {
      v21 = 0;
      while ( idStr::Icmp(s1: this->valueString.data, s2: this->valueStrings[v21]) != 0 )
      {
        v21 = ++v4;
        if ( this->valueStrings[v4] == nullptr )
          goto LABEL_35;
      }
      this->valueInteger = v4;
    }
LABEL_35:
    idStr::operator=(this: &this->valueString, text: this->valueStrings[this->valueInteger]);
    LODWORD(v22) = this->valueInteger;
    this->valueFloat = (float)v22;
  }
  else
  {
    if ( this->valueString.len >= 32 )
    {
      this->valueInteger = 0;
      v24 = 0.0;
    }
    else
    {
      v23 = atof(nptr: data);
      v24 = (float)*(double *)&v23;
      this->valueInteger = (int)v24;
    }
    this->valueFloat = v24;
  }
LABEL_40:
  for ( i = this->onChange; i != nullptr; i = i->next )
    i->callback->Call(this: i->callback);
}


// ========================================================================
// __unwind$117185
// EA  : 0x82EFF128
// RVA : 0x00EFF128
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_117185()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$117186
// EA  : 0x82EFF150
// RVA : 0x00EFF150
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_117186()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$117187
// EA  : 0x82EFF178
// RVA : 0x00EFF178
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_117187()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 160));
}


// ========================================================================
// ?Reset@idCVar@@QAAXXZ
// EA  : 0x82EFF1A0
// RVA : 0x00EFF1A0
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVar::Reset(idCVar *this)
{
  idStr::operator=(this: &this->valueString, text: this->resetString);
  idCVar::UpdateValue(this);
}


// ========================================================================
// ?Set@idCVar@@QAA_NPBD_N@Z
// EA  : 0x82EFF1D8
// RVA : 0x00EFF1D8
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

int __fastcall idCVar::Set(idCVar *this, const char *newValue, bool force)
{
  const char *resetString; // r30
  int flags; // r11
  int v7; // r7

  resetString = newValue;
  if ( force )
    goto LABEL_7;
  flags = this->flags;
  if ( (flags & 0x4000) != 0 )
  {
    idLib::Printf(fmt: "%s can only be set on the command line\n", this->name);
    return 0;
  }
  if ( (flags & 0x8000) == 0 )
  {
LABEL_7:
    if ( newValue == nullptr )
      resetString = this->resetString;
    if ( idStr::Icmp(s1: this->valueString.data, s2: resetString) == 0 )
      return 0;
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idStr::operator=(this: &this->valueString, text: resetString);
    idMem::PopHeap(this: &mem);
    idCVar::UpdateValue(this);
    localCVarSystem.modifiedFlags |= this->flags;
    v7 = this->flags;
    this->flags = v7 | 0x40000;
    if ( (v7 & 0x10000) != 0 && idLib::production == PROD_LOADED )
      idLib::Warning(fmt: "Archived CVar '%s' in production mode", this->name);
    return 1;
  }
  else
  {
    idLib::Printf(fmt: "%s is read only\n", this->name);
    return 0;
  }
}


// ========================================================================
// ?SetString@idCVar@@QAAXPBD_N@Z
// EA  : 0x82EFF2F8
// RVA : 0x00EFF2F8
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

// attributes: thunk
void __fastcall idCVar::SetString(idCVar *this, const char *newValue, bool force)
{
  idCVar::Set(this, newValue, force);
}


// ========================================================================
// ?SetBool@idCVar@@QAAX_N0@Z
// EA  : 0x82EFF308
// RVA : 0x00EFF308
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVar::SetBool(idCVar *this, bool newValue, bool force)
{
  idStr *v5; // r3
  idStr v6[2]; // [sp+50h] [-40h] BYREF

  v5 = idStr::idStr(this: v6, b: newValue);
  idCVar::Set(this, newValue: v5->data, force);
  idStr::FreeData(this: v6);
}


// ========================================================================
// __unwind$117316
// EA  : 0x82EFF348
// RVA : 0x00EFF348
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_117316()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?SetInteger@idCVar@@QAAXH_N@Z
// EA  : 0x82EFF378
// RVA : 0x00EFF378
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVar::SetInteger(idCVar *this, int newValue, bool force)
{
  idStr *v5; // r3
  idStr v6[2]; // [sp+50h] [-40h] BYREF

  v5 = idStr::idStr(this: v6, i: newValue);
  idCVar::Set(this, newValue: v5->data, force);
  idStr::FreeData(this: v6);
}


// ========================================================================
// __unwind$117348
// EA  : 0x82EFF3B8
// RVA : 0x00EFF3B8
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_117348()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?SetFloat@idCVar@@QAAXM_N@Z
// EA  : 0x82EFF3E8
// RVA : 0x00EFF3E8
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVar::SetFloat(idCVar *this, double newValue, const bool force, bool a4)
{
  idStr *v6; // r3
  idStr v7[2]; // [sp+50h] [-40h] BYREF

  v6 = idStr::idStr(this: v7, f: newValue);
  idCVar::Set(this, newValue: v6->data, force: a4);
  idStr::FreeData(this: v7);
}


// ========================================================================
// __unwind$117380
// EA  : 0x82EFF428
// RVA : 0x00EFF428
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_117380()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?CreateColumn@@YAPBDPBDH0AAVidStr@@@Z
// EA  : 0x82EFF450
// RVA : 0x00EFF450
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

char *__fastcall CreateColumn(const char *text, int columnWidth, char *indent, idStr *string)
{
  int v8; // r28
  int v9; // r30
  int v10; // r11
  unsigned int allocedAndFlag; // r11
  char v12; // r29
  int v13; // r10
  int v14; // r11
  bool v15; // zf
  char *data; // r9
  int v17; // r11
  unsigned int v18; // r11
  char v19; // r29
  int v20; // r10
  int v21; // r11
  char *v22; // r9
  int v23; // r11

  idStr::Clear(this: string);
  v8 = 0;
  v9 = 0;
  if ( *text != 0 )
  {
    do
    {
      if ( v8 - v9 >= columnWidth || text[v8] == 10 )
      {
        for ( ; v8 > 0; --v8 )
        {
          v10 = text[v8];
          if ( v10 <= 32 )
            break;
          if ( v10 == 47 )
            break;
          if ( v10 == 44 )
            break;
          if ( v10 == 92 )
            break;
        }
        for ( ; v9 < v8; data[v17] = 0 )
        {
          allocedAndFlag = string->allocedAndFlag;
          v12 = text[v9];
          v13 = string->len + 2;
          v15 = allocedAndFlag >> 31 == 0;
          v14 = allocedAndFlag & 0x7FFFFFFF;
          if ( v15 )
          {
            if ( v13 > v14 )
              idStr::ReAllocate(this: string, amount: (v13 >> 1) + v13, keepold: true);
          }
          else if ( v13 > v14
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          ++v9;
          string->data[string->len] = v12;
          data = string->data;
          v17 = string->len + 1;
          string->len = v17;
        }
        idStr::Append(this: string, text: indent);
        ++v9;
      }
      ++v8;
    }
    while ( text[v8] != 0 );
    for ( ; v9 < v8; v22[v23] = 0 )
    {
      v18 = string->allocedAndFlag;
      v19 = text[v9];
      v20 = string->len + 2;
      v15 = v18 >> 31 == 0;
      v21 = v18 & 0x7FFFFFFF;
      if ( v15 )
      {
        if ( v20 > v21 )
          idStr::ReAllocate(this: string, amount: (v20 >> 1) + v20, keepold: true);
      }
      else if ( v20 > v21
             && AssertFailed(
                  file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                  line: 463,
                  expression: "amount <= GetAlloced()",
                  inlineBreak: true) )
      {
        __trap();
      }
      ++v9;
      string->data[string->len] = v19;
      v22 = string->data;
      v23 = string->len + 1;
      string->len = v23;
    }
  }
  return string->data;
}


// ========================================================================
// ?Find@idCVarSystemLocal@@UBAPAVidCVar@@PBD@Z
// EA  : 0x82EFF658
// RVA : 0x00EFF658
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCVar *__fastcall idCVarSystemLocal::Find(idCVarSystemLocal *this, const char *name)
{
  idHashIndex *p_cvarHash; // r29
  int v5; // r31

  p_cvarHash = &this->cvarHash;
  v5 = this->cvarHash.hash[idHashIndex::GenerateKeyForString(this: &this->cvarHash, string: name, caseSensitive: false)
                         & this->cvarHash.hashMask
                         & this->cvarHash.lookupMask];
  if ( v5 == -1 )
    return nullptr;
  while ( idStr::Icmp(s1: this->cvars.list[v5]->name, s2: name) != 0 )
  {
    v5 = p_cvarHash->indexChain[p_cvarHash->lookupMask & v5];
    if ( v5 == -1 )
      return nullptr;
  }
  return this->cvars.list[v5];
}


// ========================================================================
// ?CvarExists@idCVarSystemLocal@@UBA_NPBD_N@Z
// EA  : 0x82EFF6F8
// RVA : 0x00EFF6F8
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

int __fastcall idCVarSystemLocal::CvarExists(idCVarSystemLocal *this, const char *name, const bool searchForString)
{
  int v5; // r29
  int i; // r31
  int v8; // r31

  if ( searchForString )
  {
    v5 = 0;
    if ( this->cvars.num > 0 )
    {
      for ( i = 0;
            idStr::Find(searchIn: name, searchFor: this->cvars.list[i]->name, casesensitive: false, start: 0, end: -1) == -1;
            ++i )
      {
        if ( ++v5 >= this->cvars.num )
          return 0;
      }
      return 1;
    }
  }
  else
  {
    v8 = this->cvarHash.hash[idHashIndex::GenerateKeyForString(
                               this: &this->cvarHash,
                               string: name,
                               caseSensitive: false)
                           & this->cvarHash.hashMask
                           & this->cvarHash.lookupMask];
    if ( v8 != -1 )
    {
      while ( idStr::Icmp(s1: this->cvars.list[v8]->name, s2: name) != 0 )
      {
        v8 = this->cvarHash.indexChain[this->cvarHash.lookupMask & v8];
        if ( v8 == -1 )
          return 0;
      }
      return 1;
    }
  }
  return 0;
}


// ========================================================================
// ?SetCVarString@idCVarSystemLocal@@UAAXPBD0H@Z
// EA  : 0x82EFF800
// RVA : 0x00EFF800
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVarSystemLocal::SetCVarString(
        idCVarSystemLocal *this,
        const char *name,
        const char *value,
        int flags)
{
  idCVar *v5; // r3

  v5 = (idCVar *)((int (__fastcall *)(idCVarSystemLocal *, const char *, const char *, int))this->Find)(
                   a1: this,
                   a2: name,
                   a3: value,
                   a4: flags);
  if ( v5 != nullptr )
    idCVar::Set(this: v5, newValue: value, force: true);
}


// ========================================================================
// ?Command@idCVarSystemLocal@@UAA_NABVidCmdArgs@@@Z
// EA  : 0x82EFF850
// RVA : 0x00EFF850
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCVar *__fastcall idCVarSystemLocal::Command(idCVarSystemLocal *this, const idCmdArgs *args)
{
  const char *v3; // r4
  idCVar *result; // r3
  idCVar *v5; // r31
  const char *description; // r4
  int v7; // r11
  const char *v8; // r3

  if ( args->argc <= 0 )
    v3 = &byte_8200D768;
  else
    v3 = args->argv[0];
  result = this->Find(this, a2: v3);
  v5 = result;
  if ( result != nullptr )
  {
    if ( args->argc == 1 )
    {
      idLib::Printf(
        fmt: "\"%s\" is:\"%s\"^7 default:\"%s\"\n",
        result->name,
        result->valueString.data,
        result->resetString);
      description = v5->description;
      v7 = 0;
      if ( *description != 0 )
      {
        do
          ++v7;
        while ( description[v7] != 0 );
        if ( v7 > 0 )
          idLib::Printf(fmt: "^7%s\n", description);
      }
    }
    else
    {
      v8 = idCmdArgs::Args(this: args, start: 1, end: -1, quoteArgs: false, escapeArgs: false);
      idCVar::Set(this: v5, newValue: v8, force: false);
    }
    return (idCVar *)1;
  }
  return result;
}


// ========================================================================
// ?CommandCompletion@idCVarSystemLocal@@UAAXAAVidAutoComplete@@@Z
// EA  : 0x82EFF950
// RVA : 0x00EFF950
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVarSystemLocal::CommandCompletion(idCVarSystemLocal *this, idAutoComplete *autoComplete)
{
  int v4; // r27
  int v5; // r30
  idCVar **v6; // r11
  const char *name; // r26
  char *Arg; // r3
  idStr v9[3]; // [sp+60h] [-60h] BYREF

  v4 = 0;
  if ( this->cvars.num > 0 )
  {
    v5 = 0;
    do
    {
      if ( autoComplete->args.argc == 1 )
      {
        idStr::idStr(this: v9, text: this->cvars.list[v5]->name);
        idAutoComplete::Append(this: autoComplete, suggestion: v9, completingArg: -1);
        idStr::FreeData(this: v9);
      }
      v6 = &this->cvars.list[v5];
      if ( (*v6)->valueCompletion != nullptr )
      {
        name = (*v6)->name;
        Arg = idAutoComplete::GetArg(this: autoComplete, n: 0);
        if ( idStr::Icmp(s1: Arg, s2: name) == 0 )
          this->cvars.list[v5]->valueCompletion(a1: autoComplete);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->cvars.num );
  }
}


// ========================================================================
// __unwind$117621
// EA  : 0x82EFFA28
// RVA : 0x00EFFA28
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_117621()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?ResetFlaggedVariables@idCVarSystemLocal@@UAAXH@Z
// EA  : 0x82EFFA50
// RVA : 0x00EFFA50
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVarSystemLocal::ResetFlaggedVariables(idCVarSystemLocal *this, int flags)
{
  idCVar *i; // r31
  const char *resetString; // r30
  char v5; // r11
  int v6; // r9

  for ( i = staticVars; i != nullptr; i = i->next )
  {
    if ( (i->flags & flags) != 0 )
    {
      resetString = i->resetString;
      if ( idStr::Icmp(s1: i->valueString.data, s2: resetString) != 0 )
      {
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
        idStr::operator=(this: &i->valueString, text: resetString);
        idMem::PopHeap(this: &mem);
        idCVar::UpdateValue(this: i);
        localCVarSystem.modifiedFlags |= i->flags;
        v6 = i->flags;
        i->flags = v6 | 0x40000;
        if ( (v6 & 0x10000) != 0 && idLib::production == PROD_LOADED )
          idLib::Warning(fmt: "Archived CVar '%s' in production mode", i->name);
        v5 = 1;
      }
      else
      {
        v5 = 0;
      }
      if ( v5 != 0 )
        idLib::Printf(fmt: "Resetting cheat cvar: %s\n", i->name);
    }
  }
}


// ========================================================================
// ?toggle_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EFFB68
// RVA : 0x00EFFB68
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall toggle_f(const idCmdArgs *args)
{
  int argc; // r28
  const char *v3; // r4
  idCVar *v4; // r3
  idCVar *v5; // r25
  const char *v6; // r5
  const char *v7; // r27
  int v8; // r30
  char **v9; // r29
  const char *v10; // r4
  const char *v11; // r5
  const char *v12; // r4
  const char *v13; // r30
  idCVar *v14; // r3
  double valueFloat; // fp30
  long double v16; // fp2
  double v17; // fp31
  char *data; // r30
  idCVar *v19; // r3
  idStr v20; // [sp+50h] [-80h] BYREF

  argc = args->argc;
  if ( args->argc >= 2 )
  {
    if ( argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    v4 = idCVarSystemLocal::Find(this: &localCVarSystem, name: v3);
    v5 = v4;
    if ( v4 != nullptr )
    {
      if ( argc <= 3 )
      {
        valueFloat = v4->valueFloat;
        if ( argc == 3 )
        {
          if ( args->argc <= 2 )
            v16 = atof(nptr: &byte_8200D768);
          else
            v16 = atof(nptr: args->argv[2]);
          v17 = (float)*(double *)&v16;
        }
        else
        {
          v17 = 1.0;
        }
        if ( valueFloat != 0.0 )
          v17 = 0.0;
        idLib::Printf(fmt: "%s = %f\n", (const char *)HIDWORD(v17), v17);
        data = idStr::idStr(this: &v20, f: v17)->data;
        v19 = localCVarSystem.Find(this: &localCVarSystem, a2: v5->name);
        if ( v19 != nullptr )
          idCVar::Set(this: v19, newValue: data, force: true);
        idStr::FreeData(this: &v20);
      }
      else
      {
        v7 = v4->valueString.data;
        v8 = 2;
        v9 = &args->argv[2];
        while ( 1 )
        {
          v10 = v8 < 0 || v8 >= args->argc ? &byte_8200D768 : *v9;
          ++v8;
          if ( idStr::Icmp(s1: v7, s2: v10) == 0 )
            break;
          ++v9;
          if ( v8 >= argc )
          {
            v8 = 2;
            goto LABEL_25;
          }
        }
        if ( v8 < argc )
        {
          if ( v8 < 0 )
            goto LABEL_27;
        }
        else
        {
          v8 = 2;
        }
LABEL_25:
        if ( v8 < args->argc )
        {
          v11 = args->argv[v8];
          goto LABEL_28;
        }
LABEL_27:
        v11 = &byte_8200D768;
LABEL_28:
        if ( args->argc <= 1 )
          v12 = &byte_8200D768;
        else
          v12 = args->argv[1];
        idLib::Printf(fmt: "%s = %s\n", v12, v11);
        if ( v8 < 0 || v8 >= args->argc )
          v13 = &byte_8200D768;
        else
          v13 = args->argv[v8];
        v14 = localCVarSystem.Find(this: &localCVarSystem, a2: v5->name);
        if ( v14 != nullptr )
          idCVar::Set(this: v14, newValue: v13, force: true);
      }
    }
    else
    {
      if ( args->argc <= 1 )
        v6 = &byte_8200D768;
      else
        v6 = args->argv[1];
      if ( args->argc <= 0 )
        idLib::Warning(fmt: "%s: cvar \"%s\" not found", &byte_8200D768, v6);
      else
        idLib::Warning(fmt: "%s: cvar \"%s\" not found", args->argv[0], v6);
    }
  }
  else
  {
    idLib::Printf(
      fmt: "usage:\n"
      "   toggle <variable>  - toggles between 0 and 1\n"
      "   toggle <variable> <value> - toggles between 0 and <value>\n"
      "   toggle <variable> [string 1] [string 2]...[string n] - cycles through all strings\n");
  }
}


// ========================================================================
// __unwind$117754
// EA  : 0x82EFFE14
// RVA : 0x00EFFE14
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_117754()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?ArgCompletion_Cvar1@@YAXAAVidAutoComplete@@@Z
// EA  : 0x82EFFE48
// RVA : 0x00EFFE48
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall ArgCompletion_Cvar1(idAutoComplete *autoComplete)
{
  int v2; // r26
  int v3; // r28
  const char *name; // r30
  int v5; // r29
  char *v6; // r10
  char *v7; // r9
  char v8; // r11
  idStr v9[3]; // [sp+60h] [-70h] BYREF

  if ( autoComplete->args.argc <= 2 )
  {
    v2 = 0;
    if ( localCVarSystem.cvars.num > 0 )
    {
      v3 = 0;
      do
      {
        name = localCVarSystem.cvars.list[v3]->name;
        v9[0].allocedAndFlag = 20;
        v9[0].data = v9[0].baseBuffer;
        v9[0].len = 0;
        v9[0].baseBuffer[0] = 0;
        if ( name != nullptr )
        {
          v5 = 0;
          if ( *name != 0 )
          {
            do
              ++v5;
            while ( name[v5] != 0 );
          }
          idStr::EnsureAlloced(this: v9, amount: v5 + 1, keepold: true, geometricGrowth: false);
          v6 = (char *)(name - 1);
          v7 = v9[0].data - 1;
          do
          {
            v8 = *++v6;
            *++v7 = *v6;
          }
          while ( v8 != 0 );
          v9[0].len = v5;
        }
        idAutoComplete::Append(this: autoComplete, suggestion: v9, completingArg: -1);
        idStr::FreeData(this: v9);
        ++v2;
        ++v3;
      }
      while ( v2 < localCVarSystem.cvars.num );
    }
  }
}


// ========================================================================
// __unwind$117902
// EA  : 0x82EFFF48
// RVA : 0x00EFFF48
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_117902()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?cvarAdd_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EFFF78
// RVA : 0x00EFFF78
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall cvarAdd_f(const idCmdArgs *args)
{
  const char *v2; // r4
  idCVar *v3; // r3
  int argc; // r11
  idCVar *v5; // r29
  const char *v6; // r3
  long double v7; // fp2
  char *data; // r30
  idCVar *v9; // r3
  idStr v10[2]; // [sp+50h] [-50h] BYREF

  if ( args->argc <= 1 )
    v2 = &byte_8200D768;
  else
    v2 = args->argv[1];
  v3 = idCVarSystemLocal::Find(this: &localCVarSystem, name: v2);
  argc = args->argc;
  v5 = v3;
  if ( v3 != nullptr )
  {
    if ( argc <= 2 )
      v6 = &byte_8200D768;
    else
      v6 = args->argv[2];
    v7 = atof(nptr: v6);
    data = idStr::idStr(this: v10, f: (float)(v5->valueFloat + (float)*(double *)&v7))->data;
    v9 = localCVarSystem.Find(this: &localCVarSystem, a2: v5->name);
    if ( v9 != nullptr )
      idCVar::Set(this: v9, newValue: data, force: true);
    idStr::FreeData(this: v10);
  }
  else if ( argc <= 1 )
  {
    idLib::Warning(fmt: "CvarAdd_f: cvar \"%s\" not found", &byte_8200D768);
  }
  else
  {
    idLib::Warning(fmt: "CvarAdd_f: cvar \"%s\" not found", args->argv[1]);
  }
}


// ========================================================================
// __unwind$117989
// EA  : 0x82F0006C
// RVA : 0x00F0006C
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_117989()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?cvarRandom_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F000A0
// RVA : 0x00F000A0
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall cvarRandom_f(const idCmdArgs *args)
{
  idCVar *v2; // r3
  int argc; // r11
  idCVar *v4; // r28
  const char *v5; // r5
  const char *v6; // r3
  long double v7; // fp2
  double v8; // fp31
  const char *v9; // r3
  __int64 v10; // r5
  long double v11; // fp2
  int seed; // r10
  char *data; // r30
  idCVar *v14; // r3
  idStr v15; // [sp+60h] [-60h] BYREF

  if ( args->argc == 4 )
  {
    v2 = idCVarSystemLocal::Find(this: &localCVarSystem, name: args->argv[1]);
    argc = args->argc;
    v4 = v2;
    if ( v2 != nullptr )
    {
      if ( argc <= 2 )
        v6 = &byte_8200D768;
      else
        v6 = args->argv[2];
      v7 = atof(nptr: v6);
      v8 = (float)*(double *)&v7;
      if ( args->argc <= 3 )
        v9 = &byte_8200D768;
      else
        v9 = args->argv[3];
      v11 = atof(nptr: v9);
      if ( (_S6 & 1) != 0 )
      {
        seed = r_0.seed;
      }
      else
      {
        _S6 |= 1u;
        seed = 0;
      }
      r_0.seed = 1103515245 * seed + 12345;
      LODWORD(v10) = HIWORD(r_0.seed) & 0x7FFF;
      data = idStr::idStr(
               this: &v15,
               f: (float)((float)((float)((float)*(double *)&v11 - (float)v8) * (float)((float)v10 * (float)0.000030518509))
                     + (float)v8))->data;
      v14 = localCVarSystem.Find(this: &localCVarSystem, a2: v4->name);
      if ( v14 != nullptr )
        idCVar::Set(this: v14, newValue: data, force: true);
      idStr::FreeData(this: &v15);
    }
    else
    {
      if ( argc <= 1 )
        v5 = &byte_8200D768;
      else
        v5 = args->argv[1];
      if ( argc <= 0 )
        idLib::Warning(fmt: "%s: cvar \"%s\" not found", &byte_8200D768, v5);
      else
        idLib::Warning(fmt: "%s: cvar \"%s\" not found", args->argv[0], v5);
    }
  }
  else
  {
    idLib::Printf(fmt: "Usage: cvarRandom <cvar> <from> <to>\n");
  }
}


// ========================================================================
// __unwind$118061
// EA  : 0x82F00250
// RVA : 0x00F00250
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118061()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?addWrap_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F00280
// RVA : 0x00F00280
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall addWrap_f(const idCmdArgs *args)
{
  const char *v2; // r4
  idCVar *v3; // r3
  int argc; // r11
  idCVar *v5; // r28
  const char *v6; // r5
  long double v7; // fp2
  double v8; // fp30
  const char *v9; // r3
  long double v10; // fp2
  double v11; // fp31
  const char *v12; // r3
  long double v13; // fp2
  double v14; // fp0
  char *data; // r30
  idCVar *v16; // r3
  idStr v17; // [sp+60h] [-60h] BYREF

  if ( args->argc <= 1 )
    v2 = &byte_8200D768;
  else
    v2 = args->argv[1];
  v3 = idCVarSystemLocal::Find(this: &localCVarSystem, name: v2);
  argc = args->argc;
  v5 = v3;
  if ( v3 != nullptr )
  {
    if ( argc >= 5 )
    {
      v7 = atof(nptr: args->argv[2]);
      v8 = (float)*(double *)&v7;
      if ( args->argc <= 3 )
        v9 = &byte_8200D768;
      else
        v9 = args->argv[3];
      v10 = atof(nptr: v9);
      v11 = (float)*(double *)&v10;
      if ( args->argc <= 4 )
        v12 = &byte_8200D768;
      else
        v12 = args->argv[4];
      v13 = atof(nptr: v12);
      v14 = (float)(v5->valueFloat + (float)v8);
      if ( v14 >= v11 )
      {
        if ( v14 > (float)*(double *)&v13 )
          v14 = v11;
      }
      else
      {
        v14 = (float)*(double *)&v13;
      }
      data = idStr::idStr(this: &v17, f: v14)->data;
      v16 = localCVarSystem.Find(this: &localCVarSystem, a2: v5->name);
      if ( v16 != nullptr )
        idCVar::Set(this: v16, newValue: data, force: true);
      idStr::FreeData(this: &v17);
    }
    else
    {
      idLib::Printf(fmt: "USAGE: addWrap [variablename] [add] [min] [max]\n");
    }
  }
  else
  {
    if ( argc <= 1 )
      v6 = &byte_8200D768;
    else
      v6 = args->argv[1];
    if ( argc <= 0 )
      idLib::Warning(fmt: "%s: cvar \"%s\" not found", &byte_8200D768, v6);
    else
      idLib::Warning(fmt: "%s: cvar \"%s\" not found", args->argv[0], v6);
  }
}


// ========================================================================
// __unwind$118159
// EA  : 0x82F00414
// RVA : 0x00F00414
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118159()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?addClamp_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F00448
// RVA : 0x00F00448
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall addClamp_f(const idCmdArgs *args)
{
  const char *v2; // r4
  idCVar *v3; // r3
  int argc; // r11
  idCVar *v5; // r28
  const char *v6; // r5
  long double v7; // fp2
  double v8; // fp30
  const char *v9; // r3
  long double v10; // fp2
  double v11; // fp31
  const char *v12; // r3
  long double v13; // fp2
  double v14; // fp0
  char *data; // r30
  idCVar *v16; // r3
  idStr v17; // [sp+60h] [-60h] BYREF

  if ( args->argc <= 1 )
    v2 = &byte_8200D768;
  else
    v2 = args->argv[1];
  v3 = idCVarSystemLocal::Find(this: &localCVarSystem, name: v2);
  argc = args->argc;
  v5 = v3;
  if ( v3 != nullptr )
  {
    if ( argc >= 5 )
    {
      v7 = atof(nptr: args->argv[2]);
      v8 = (float)*(double *)&v7;
      if ( args->argc <= 3 )
        v9 = &byte_8200D768;
      else
        v9 = args->argv[3];
      v10 = atof(nptr: v9);
      v11 = (float)*(double *)&v10;
      if ( args->argc <= 4 )
        v12 = &byte_8200D768;
      else
        v12 = args->argv[4];
      v13 = atof(nptr: v12);
      v14 = (float)(v5->valueFloat + (float)v8);
      if ( v14 >= v11 )
      {
        if ( v14 > (float)*(double *)&v13 )
          v14 = (float)*(double *)&v13;
      }
      else
      {
        v14 = v11;
      }
      data = idStr::idStr(this: &v17, f: v14)->data;
      v16 = localCVarSystem.Find(this: &localCVarSystem, a2: v5->name);
      if ( v16 != nullptr )
        idCVar::Set(this: v16, newValue: data, force: true);
      idStr::FreeData(this: &v17);
    }
    else
    {
      idLib::Printf(fmt: "USAGE: addClamp [variablename] [add] [min] [max]\n");
    }
  }
  else
  {
    if ( argc <= 1 )
      v6 = &byte_8200D768;
    else
      v6 = args->argv[1];
    if ( argc <= 0 )
      idLib::Warning(fmt: "%s: cvar \"%s\" not found", &byte_8200D768, v6);
    else
      idLib::Warning(fmt: "%s: cvar \"%s\" not found", args->argv[0], v6);
  }
}


// ========================================================================
// __unwind$118255
// EA  : 0x82F005DC
// RVA : 0x00F005DC
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118255()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?cvarMultiply_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F00610
// RVA : 0x00F00610
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall cvarMultiply_f(const idCmdArgs *args)
{
  const char *v2; // r4
  idCVar *v3; // r3
  int argc; // r11
  idCVar *v5; // r29
  const char *v6; // r5
  double valueFloat; // fp31
  const char *v8; // r3
  long double v9; // fp2
  char *data; // r30
  idCVar *v11; // r3
  idStr v12; // [sp+50h] [-60h] BYREF

  if ( args->argc <= 1 )
    v2 = &byte_8200D768;
  else
    v2 = args->argv[1];
  v3 = idCVarSystemLocal::Find(this: &localCVarSystem, name: v2);
  argc = args->argc;
  v5 = v3;
  if ( v3 != nullptr )
  {
    valueFloat = v3->valueFloat;
    if ( argc <= 2 )
      v8 = &byte_8200D768;
    else
      v8 = args->argv[2];
    v9 = atof(nptr: v8);
    data = idStr::idStr(this: &v12, f: (float)(*(double *)&v9 * valueFloat))->data;
    v11 = localCVarSystem.Find(this: &localCVarSystem, a2: v5->name);
    if ( v11 != nullptr )
      idCVar::Set(this: v11, newValue: data, force: true);
    idStr::FreeData(this: &v12);
  }
  else
  {
    if ( argc <= 1 )
      v6 = &byte_8200D768;
    else
      v6 = args->argv[1];
    if ( argc <= 0 )
      idLib::Warning(fmt: "%s: cvar \"%s\" not found", &byte_8200D768, v6);
    else
      idLib::Warning(fmt: "%s: cvar \"%s\" not found", args->argv[0], v6);
  }
}


// ========================================================================
// __unwind$118351
// EA  : 0x82F00720
// RVA : 0x00F00720
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118351()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?reset_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F00748
// RVA : 0x00F00748
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall reset_f(const idCmdArgs *args)
{
  idCVar *v1; // r3
  idCVar *v2; // r31

  if ( args->argc == 2 )
  {
    v1 = idCVarSystemLocal::Find(this: &localCVarSystem, name: args->argv[1]);
    v2 = v1;
    if ( v1 != nullptr )
    {
      idStr::operator=(this: &v1->valueString, text: v1->resetString);
      idCVar::UpdateValue(this: v2);
    }
  }
  else
  {
    idLib::Printf(fmt: "usage: reset <variable>\n");
  }
}


// ========================================================================
// ?cvar_restart_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F007D8
// RVA : 0x00F007D8
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall cvar_restart_f(const idCmdArgs *args)
{
  int v1; // r28
  int num; // r11
  int v3; // r30
  idCVar *v4; // r31

  v1 = 0;
  num = localCVarSystem.cvars.num;
  if ( localCVarSystem.cvars.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = localCVarSystem.cvars.list[v3];
      if ( (v4->flags & 0xC000) == 0 )
      {
        idStr::operator=(this: &localCVarSystem.cvars.list[v3]->valueString, text: v4->resetString);
        idCVar::UpdateValue(this: v4);
        num = localCVarSystem.cvars.num;
      }
      ++v1;
      ++v3;
    }
    while ( v1 < num );
  }
}


// ========================================================================
// ??1idCVarSystemLocal@@UAA@XZ
// EA  : 0x82F00850
// RVA : 0x00F00850
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVarSystemLocal::~idCVarSystemLocal(idCVarSystemLocal *this)
{
  this->__vftable = (idCVarSystemLocal_vtbl *)&idCVarSystemLocal::`vftable';
  idHashIndex::Free(this: &this->cvarHash);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cvars);
  this->__vftable = (idCVarSystemLocal_vtbl *)&idCVarSystem::`vftable';
}


// ========================================================================
// __unwind$118567
// EA  : 0x82F008B0
// RVA : 0x00F008B0
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118567()
{
  int v0; // r12

  idCVarSystem::~idCVarSystem(this: *(idCVarSystem **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$118568
// EA  : 0x82F008D8
// RVA : 0x00F008D8
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118568()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ?NodeForIndex@idMD6Allocator_New@@UAAPAVidMD6Node@@H@Z
// EA  : 0x82F00908
// RVA : 0x00F00908
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

bfx::Area *__fastcall idMD6Allocator_New::NodeForIndex(bfx::Path *this, int i)
{
  return this->m_areas.m_data[i];
}


// ========================================================================
// ?Init@idCVar@@IAAXPBD0H0MMPAPBDP6AXAAVidAutoComplete@@@Z@Z
// EA  : 0x82F00978
// RVA : 0x00F00978
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVar::Init(
        idCVar *this,
        const char *name,
        const char *value,
        int flags,
        const char *description,
        double valueMin,
        double valueMax,
        const char **valueStrings,
        void (__fastcall *valueCompletion)(idAutoComplete *),
        const char **a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        void (__fastcall *a30)(idAutoComplete *))
{
  int v35; // r28
  idCVar *v36; // r11

  if ( staticCVarsRegistered )
  {
    this->name = CopyString(str: name, tag: TAG_CVAR);
    this->resetString = CopyString(str: value, tag: TAG_CVAR);
    this->valueStrings = nullptr;
    this->valueCompletion = nullptr;
    this->description = &byte_8200D768;
  }
  else
  {
    this->name = name;
    this->resetString = value;
    this->description = description;
    this->valueStrings = a10;
    this->valueCompletion = a30;
  }
  if ( (flags & 0x1C010) != 0 )
    v35 = flags & 0xFFFFFFE7 | 0x10;
  else
    v35 = flags | 8;
  idStr::operator=(this: &this->valueString, text: value);
  v36 = staticVars;
  this->valueMin = valueMin;
  this->valueMax = valueMax;
  this->flags = v35;
  this->valueInteger = 0;
  this->onChange = nullptr;
  staticVars = this;
  this->valueFloat = 0.0;
  this->next = v36;
  idCVar::UpdateValue(this);
}


// ========================================================================
// ??0idCVar@@QAA@PBD0H0P6AXAAVidAutoComplete@@@Z@Z
// EA  : 0x82F00A80
// RVA : 0x00F00A80
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCVar *__fastcall idCVar::idCVar(
        idCVar *this,
        const char *name,
        const char *value,
        char flags,
        const char *description,
        const char **valueCompletion)
{
  int v8; // [sp+8h] [-68h]
  int v9; // [sp+Ch] [-64h]
  int v10; // [sp+10h] [-60h]
  int v11; // [sp+14h] [-5Ch]
  int v12; // [sp+18h] [-58h]
  int v13; // [sp+1Ch] [-54h]
  int v14; // [sp+20h] [-50h]
  int v15; // [sp+24h] [-4Ch]
  int v16; // [sp+28h] [-48h]
  int v17; // [sp+2Ch] [-44h]
  int v18; // [sp+30h] [-40h]
  int v19; // [sp+34h] [-3Ch]
  int v20; // [sp+38h] [-38h]
  int v21; // [sp+3Ch] [-34h]
  int v22; // [sp+40h] [-30h]
  int v23; // [sp+44h] [-2Ch]
  int v24; // [sp+48h] [-28h]
  int v25; // [sp+4Ch] [-24h]
  int v26; // [sp+50h] [-20h]

  this->valueString.len = 0;
  this->valueString.allocedAndFlag = 20;
  this->valueString.data = this->valueString.baseBuffer;
  this->valueString.baseBuffer[0] = 0;
  if ( valueCompletion == nullptr && (flags & 1) != 0 )
    valueCompletion = (const char **)idCmdSystem::ArgCompletion_Boolean;
  idCVar::Init(
    this,
    name,
    value,
    flags,
    description,
    valueMin: 1.0,
    valueMax: -1.0,
    valueStrings: valueCompletion,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))0x82000000,
    a10: nullptr,
    a11: v8,
    a12: v9,
    a13: v10,
    a14: v11,
    a15: v12,
    a16: v13,
    a17: v14,
    a18: v15,
    a19: v16,
    a20: v17,
    a21: v18,
    a22: v19,
    a23: v20,
    a24: v21,
    a25: v22,
    a26: v23,
    a27: v24,
    a28: v25,
    a29: v26,
    a30: (void (__fastcall *)(idAutoComplete *))valueCompletion);
  return this;
}


// ========================================================================
// __unwind$118626
// EA  : 0x82F00B14
// RVA : 0x00F00B14
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118626()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idCVar@@QAA@PBD0H0MMP6AXAAVidAutoComplete@@@Z@Z
// EA  : 0x82F00B48
// RVA : 0x00F00B48
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCVar *__fastcall idCVar::idCVar(
        idCVar *this,
        const char *name,
        const char *value,
        int flags,
        const char *description,
        double valueMin,
        double valueMax,
        void (__fastcall *valueCompletion)(idAutoComplete *),
        int a9,
        void (__fastcall *a10)(idAutoComplete *))
{
  int v12; // [sp+8h] [-68h]
  int v13; // [sp+Ch] [-64h]
  int v14; // [sp+10h] [-60h]
  int v15; // [sp+14h] [-5Ch]
  int v16; // [sp+18h] [-58h]
  int v17; // [sp+1Ch] [-54h]
  int v18; // [sp+20h] [-50h]
  int v19; // [sp+24h] [-4Ch]
  int v20; // [sp+28h] [-48h]
  int v21; // [sp+2Ch] [-44h]
  int v22; // [sp+30h] [-40h]
  int v23; // [sp+34h] [-3Ch]
  int v24; // [sp+38h] [-38h]
  int v25; // [sp+3Ch] [-34h]
  int v26; // [sp+40h] [-30h]
  int v27; // [sp+44h] [-2Ch]
  int v28; // [sp+48h] [-28h]
  int v29; // [sp+4Ch] [-24h]
  int v30; // [sp+50h] [-20h]

  this->valueString.len = 0;
  this->valueString.data = this->valueString.baseBuffer;
  this->valueString.allocedAndFlag = 20;
  this->valueString.baseBuffer[0] = 0;
  idCVar::Init(
    this,
    name,
    value,
    flags,
    description,
    valueMin,
    valueMax,
    valueStrings: (const char **)0x14,
    valueCompletion: nullptr,
    a10: nullptr,
    a11: v12,
    a12: v13,
    a13: v14,
    a14: v15,
    a15: v16,
    a16: v17,
    a17: v18,
    a18: v19,
    a19: v20,
    a20: v21,
    a21: v22,
    a22: v23,
    a23: v24,
    a24: v25,
    a25: v26,
    a26: v27,
    a27: v28,
    a28: v29,
    a29: v30,
    a30: a10);
  return this;
}


// ========================================================================
// __unwind$118666
// EA  : 0x82F00BB0
// RVA : 0x00F00BB0
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118666()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idCVar@@QAA@PBD0H0PAPBDP6AXAAVidAutoComplete@@@Z@Z
// EA  : 0x82F00BE0
// RVA : 0x00F00BE0
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCVar *__fastcall idCVar::idCVar(
        idCVar *this,
        const char *name,
        const char *value,
        int flags,
        const char *description,
        const char **valueStrings,
        void (__fastcall *valueCompletion)(idAutoComplete *))
{
  int v9; // [sp+8h] [-78h]
  int v10; // [sp+Ch] [-74h]
  int v11; // [sp+10h] [-70h]
  int v12; // [sp+14h] [-6Ch]
  int v13; // [sp+18h] [-68h]
  int v14; // [sp+1Ch] [-64h]
  int v15; // [sp+20h] [-60h]
  int v16; // [sp+24h] [-5Ch]
  int v17; // [sp+28h] [-58h]
  int v18; // [sp+2Ch] [-54h]
  int v19; // [sp+30h] [-50h]
  int v20; // [sp+34h] [-4Ch]
  int v21; // [sp+38h] [-48h]
  int v22; // [sp+3Ch] [-44h]
  int v23; // [sp+40h] [-40h]
  int v24; // [sp+44h] [-3Ch]
  int v25; // [sp+48h] [-38h]
  int v26; // [sp+4Ch] [-34h]
  int v27; // [sp+50h] [-30h]

  this->valueString.len = 0;
  this->valueString.data = this->valueString.baseBuffer;
  this->valueString.allocedAndFlag = 20;
  this->valueString.baseBuffer[0] = 0;
  idCVar::Init(
    this,
    name,
    value,
    flags,
    description,
    valueMin: 1.0,
    valueMax: -1.0,
    valueStrings,
    valueCompletion,
    a10: valueStrings,
    a11: v9,
    a12: v10,
    a13: v11,
    a14: v12,
    a15: v13,
    a16: v14,
    a17: v15,
    a18: v16,
    a19: v17,
    a20: v18,
    a21: v19,
    a22: v20,
    a23: v21,
    a24: v22,
    a25: v23,
    a26: v24,
    a27: v25,
    a28: v26,
    a29: v27,
    a30: valueCompletion);
  return this;
}


// ========================================================================
// __unwind$118704
// EA  : 0x82F00C40
// RVA : 0x00F00C40
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118704()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idCVarSystemLocal@@QAA@XZ
// EA  : 0x82F00C70
// RVA : 0x00F00C70
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCVarSystemLocal *__fastcall idCVarSystemLocal::idCVarSystemLocal(idCVarSystemLocal *this)
{
  this->__vftable = (idCVarSystemLocal_vtbl *)&idCVarSystemLocal::`vftable';
  this->cvars.list = nullptr;
  this->cvars.granularity = 0;
  this->cvars.memTag = 49;
  this->cvars.listStatic = 0;
  this->cvars.size = 0;
  this->cvars.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cvars);
  this->cvarHash.memTag = TAG_CVAR;
  idHashIndex::InternalInit(this: &this->cvarHash, initialHashSize: 1024, initialIndexSize: 1024);
  return this;
}


// ========================================================================
// __unwind$118742
// EA  : 0x82F00CDC
// RVA : 0x00F00CDC
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118742()
{
  int v0; // r12

  idCVarSystem::~idCVarSystem(this: *(idCVarSystem **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$118743
// EA  : 0x82F00D04
// RVA : 0x00F00D04
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118743()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ?RegisterStaticVars@idCVar@@SAXXZ
// EA  : 0x82F00D30
// RVA : 0x00F00D30
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

static void __fastcall idCVar::RegisterStaticVars()
{
  idCVar *v0; // r29
  const char *name; // r30
  int KeyForString; // r28
  int v3; // r11
  int num; // r30
  int indexSize; // r11
  int v6; // r7
  idCVar *i; // [sp+50h] [-40h] BYREF

  staticCVarsRegistered = true;
  v0 = staticVars;
  for ( i = staticVars; v0 != nullptr; i = v0 )
  {
    name = v0->name;
    KeyForString = idHashIndex::GenerateKeyForString(
                     this: &localCVarSystem.cvarHash,
                     string: name,
                     caseSensitive: false);
    v3 = localCVarSystem.cvarHash.hash[localCVarSystem.cvarHash.lookupMask
                                     & localCVarSystem.cvarHash.hashMask
                                     & KeyForString];
    if ( v3 != -1 )
      idStr::Icmp(s1: localCVarSystem.cvars.list[v3]->name, s2: name);
    num = localCVarSystem.cvars.num;
    indexSize = localCVarSystem.cvarHash.indexSize;
    if ( localCVarSystem.cvarHash.hash == idHashIndex::INVALID_INDEX )
    {
      if ( localCVarSystem.cvars.num >= localCVarSystem.cvarHash.indexSize )
        indexSize = localCVarSystem.cvars.num + 1;
      idHashIndex::Allocate(
        this: &localCVarSystem.cvarHash,
        newHashSize: localCVarSystem.cvarHash.hashSize,
        newIndexSize: indexSize);
    }
    else if ( localCVarSystem.cvars.num >= localCVarSystem.cvarHash.indexSize )
    {
      idHashIndex::ResizeIndex(this: &localCVarSystem.cvarHash, newIndexSize: localCVarSystem.cvars.num + 1);
    }
    v6 = localCVarSystem.cvarHash.hashMask & KeyForString;
    localCVarSystem.cvarHash.indexChain[num] = localCVarSystem.cvarHash.hash[v6];
    localCVarSystem.cvarHash.hash[v6] = num;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&localCVarSystem.cvars,
      obj: (encounterGroupRole_t *)&i);
    v0 = v0->next;
  }
}


// ========================================================================
// ?FindCvarsByPrefix@idCVarSystemLocal@@UBAXPBDAAV?$idList@PAVidCVar@@$04@@@Z
// EA  : 0x82F00E58
// RVA : 0x00F00E58
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVarSystemLocal::FindCvarsByPrefix(
        idCVarSystemLocal *this,
        const char *prefix,
        idList<enum encounterGroupRole_t,5> *cvarList)
{
  int v6; // r28
  int v7; // r26
  int v8; // r31
  int v9; // r10
  int num; // r9
  encounterGroupRole_t *v11; // r4
  int v12; // r11

  v6 = 0;
  if ( *prefix != 0 )
  {
    do
      ++v6;
    while ( prefix[v6] != 0 );
  }
  v7 = 0;
  if ( this->cvars.num > 0 )
  {
    v8 = 0;
    do
    {
      if ( idStr::Icmpn(s1: this->cvars.list[v8]->name, s2: prefix, n: v6) == 0 )
      {
        v9 = 0;
        num = cvarList->num;
        v11 = (encounterGroupRole_t *)&this->cvars.list[v8];
        if ( num <= 0 )
          goto LABEL_12;
        v12 = 0;
        while ( cvarList->list[v12] != *v11 )
        {
          ++v9;
          ++v12;
          if ( v9 >= num )
            goto LABEL_12;
        }
        if ( v9 < 0 )
LABEL_12:
          idList<idAnimWebBlendTree *,5>::Append(this: cvarList, obj: v11);
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->cvars.num );
  }
}


// ========================================================================
// ?ListCvars@idCVarSystemLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82F00F40
// RVA : 0x00F00F40
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall idCVarSystemLocal::ListCvars(const idCmdArgs *args)
{
  int v2; // r26
  int v3; // r29
  int v4; // r25
  const char *v5; // r3
  const char *v6; // r3
  const char *v7; // r3
  const char *v8; // r3
  const char *v9; // r3
  const char *v10; // r3
  const char *v11; // r3
  const char *v12; // r3
  int v13; // r8
  int v14; // r7
  int v15; // r6
  int v16; // r27
  __int64 v17; // r10
  int v18; // r29
  idCVar *v19; // r11
  idStr *v20; // r3
  int len; // r7
  int v22; // r3
  char v23; // r11
  char v24; // r30
  encounterGroupRole_t *list; // r22
  int num; // r14
  encounterGroupRole_t *v27; // r29
  int m; // r30
  encounterGroupRole_t *v29; // r28
  int i; // r30
  int v31; // r29
  char *v32; // r3
  encounterGroupRole_t *v33; // r18
  int j; // r17
  encounterGroupRole_t v35; // r30
  double v36; // fp0
  const char *v37; // r4
  double v38; // fp13
  double v39; // fp1
  double v40; // fp0
  idStr *v41; // r29
  idStr *v42; // r3
  _DWORD *v43; // r11
  int v44; // r29
  int v45; // r10
  int v46; // r10
  int k; // r17
  encounterGroupRole_t v48; // r30
  char *v49; // r4
  char *v50; // r4
  char *v51; // r4
  char *v52; // r4
  char *v53; // r4
  encounterGroupRole_t v54[4]; // [sp+50h] [-1A0h] BYREF
  idList<enum encounterGroupRole_t,5> v55; // [sp+60h] [-190h] BYREF
  idSort_Quick<idCVar const *,idSort_CVarPtr> v56; // [sp+70h] [-180h] BYREF
  idStr v57; // [sp+80h] [-170h] BYREF
  int v58; // [sp+A0h] [-150h]
  int v59; // [sp+A4h] [-14Ch]
  idStr v60; // [sp+B0h] [-140h] BYREF
  idStr v61; // [sp+D0h] [-120h] BYREF
  idStr v62; // [sp+F0h] [-100h] BYREF
  idStr v63; // [sp+110h] [-E0h] BYREF
  idStr v64[6]; // [sp+130h] [-C0h] BYREF

  v58 = 0;
  v61.len = 0;
  v2 = 0;
  v61.baseBuffer[0] = 0;
  v61.allocedAndFlag = 20;
  v61.data = v61.baseBuffer;
  v60.len = 0;
  v60.baseBuffer[0] = 0;
  v60.allocedAndFlag = 20;
  v60.data = v60.baseBuffer;
  v57.len = 0;
  v57.baseBuffer[0] = 0;
  v57.allocedAndFlag = 20;
  v57.data = v57.baseBuffer;
  memset(&v55, 0, 14);
  *(_WORD *)&v55.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v55);
  v3 = 1;
  v4 = 0;
  if ( args->argc <= 1 )
    v5 = &byte_8200D768;
  else
    v5 = args->argv[1];
  if ( idStr::Icmp(s1: v5, s2: "-") == 0
    || (args->argc <= 1 ? (v6 = &byte_8200D768) : (v6 = args->argv[1]), idStr::Icmp(s1: v6, s2: "/") == 0) )
  {
    if ( args->argc <= 2 )
      v7 = &byte_8200D768;
    else
      v7 = args->argv[2];
    if ( idStr::Icmp(s1: v7, s2: "help") == 0
      || (args->argc <= 2 ? (v8 = &byte_8200D768) : (v8 = args->argv[2]), idStr::Icmp(s1: v8, s2: "?") == 0) )
    {
      v4 = 1;
      goto LABEL_32;
    }
    if ( args->argc <= 2 )
      v9 = &byte_8200D768;
    else
      v9 = args->argv[2];
    if ( idStr::Icmp(s1: v9, s2: "type") == 0
      || (args->argc <= 2 ? (v10 = &byte_8200D768) : (v10 = args->argv[2]), idStr::Icmp(s1: v10, s2: "range") == 0) )
    {
      v4 = 2;
      goto LABEL_32;
    }
    if ( args->argc <= 2 )
      v11 = &byte_8200D768;
    else
      v11 = args->argv[2];
    if ( idStr::Icmp(s1: v11, s2: "flags") == 0 )
    {
      v4 = 3;
LABEL_32:
      v3 = 3;
    }
  }
  if ( args->argc <= v3 )
  {
    idStr::operator=(this: &v61, text: &byte_8200D768);
  }
  else
  {
    v12 = idCmdArgs::Args(this: args, start: v3, end: -1, quoteArgs: false, escapeArgs: false);
    idStr::operator=(this: &v61, text: v12);
    idStr::Replace(this: &v61, old: " ", nw: &byte_8200D768);
  }
  idStr::Replace(this: &v61, old: "*", nw: &byte_8200D768);
  v16 = 0;
  LODWORD(v17) = localCVarSystem.cvars.num;
  if ( localCVarSystem.cvars.num > 0 )
  {
    v18 = 0;
    do
    {
      LODWORD(v17) = v61.len;
      v19 = localCVarSystem.cvars.list[v18];
      v54[0] = (encounterGroupRole_t)v19;
      if ( v61.len <= 0
        || (v20 = idStr::idStr(this: &v63, text: v19->name),
            v2 |= 1u,
            len = v20->len,
            v58 = v2,
            v22 = idStr::Find(searchIn: v20->data, searchFor: v61.data, casesensitive: false, start: 0, end: len),
            v23 = 1,
            v22 != -1) )
      {
        v23 = 0;
      }
      v24 = v23;
      if ( (v2 & 1) != 0 )
      {
        v2 &= ~1u;
        idStr::FreeData(this: &v63);
      }
      if ( v24 == 0 )
        idList<idAnimWebBlendTree *,5>::Append(this: &v55, obj: v54);
      ++v16;
      ++v18;
    }
    while ( v16 < localCVarSystem.cvars.num );
  }
  v56.__vftable = (idSort_Quick<idCVar const *,idSort_CVarPtr>_vtbl *)&idSort_CVarPtr::`vftable';
  list = v55.list;
  num = v55.num;
  if ( v55.list != nullptr )
    idSort_Quick<idCVar const *,idSort_CVarPtr>::Sort(
      this: &v56,
      base: (const idCVar **)v55.list,
      num: v55.num,
      a4: v15,
      a5: v14,
      a6: v13,
      a7: v17);
  v56.__vftable = (idSort_Quick<idCVar const *,idSort_CVarPtr>_vtbl *)&idSort<idCVar const *>::`vftable';
  if ( v4 == 1 )
  {
    idStr::EnsureAlloced(this: &v60, amount: 34, keepold: true, geometricGrowth: false);
    v60.len = 33;
    memset(Dst: v60.data, Val: 32, Size: 0x21u);
    v60.data[v60.len] = 0;
    idStr::Insert(this: &v60, text: "\n", index: 0);
    if ( num > 0 )
    {
      v29 = list - 1;
      for ( i = num; i != 0; --i )
      {
        v31 = *++v29;
        v32 = CreateColumn(text: *(const char **)(*v29 + 48), columnWidth: 44, indent: v60.data, string: &v57);
        idLib::Printf(fmt: "%-32s ^7%s\n", *(const char **)(v31 + 40), v32);
      }
    }
    goto LABEL_101;
  }
  if ( v4 == 2 )
  {
    if ( num <= 0 )
      goto LABEL_101;
    v33 = list;
    for ( j = num; j != 0; --j )
    {
      v35 = *v33;
      v54[0] = *(encounterGroupRole_t *)(*v33 + 52);
      if ( (v54[0] & 1) != 0 )
      {
        idLib::Printf(fmt: "%-32s ^5bool\n", *(_DWORD *)(v35 + 40));
      }
      else if ( (v54[0] & 2) != 0 )
      {
        v36 = *(float *)(v35 + 56);
        v37 = *(const char **)(v35 + 40);
        v38 = *(float *)(v35 + 60);
        v54[0] = *(encounterGroupRole_t *)(v35 + 60);
        if ( v36 >= v38 )
        {
          idLib::Printf(fmt: "%-32s ^2int\n", v37);
        }
        else
        {
          v54[1] = (int)v38;
          v59 = (int)v36;
          *(float *)v54 = v36;
          idLib::Printf(fmt: "%-32s ^2int ^7[%d, %d]\n", v37, (int)v36, (int)v38);
        }
      }
      else if ( (v54[0] & 4) != 0 )
      {
        v39 = *(float *)(v35 + 60);
        v40 = *(float *)(v35 + 56);
        v54[0] = *(encounterGroupRole_t *)(v35 + 60);
        if ( v40 >= v39 )
        {
          idLib::Printf(fmt: "%-32s ^1float\n", *(_DWORD *)(v35 + 40));
        }
        else
        {
          *(float *)v54 = v39;
          v41 = idStr::idStr(this: v64, f: v39);
          v42 = idStr::idStr(this: &v62, f: *(float *)(v35 + 56));
          idLib::Printf(fmt: "%-32s ^1float ^7[%s, %s]\n", *(const char **)(v35 + 40), v42->data, v41->data);
          idStr::FreeData(this: &v62);
          idStr::FreeData(this: v64);
        }
      }
      else if ( *(_DWORD *)(v35 + 64) != 0 )
      {
        idLib::Printf(fmt: "%-32s ^7string ^7[", *(const char **)(v35 + 40));
        v43 = *(_DWORD **)(v35 + 64);
        v44 = 0;
        v45 = *v43;
        v54[0] = (encounterGroupRole_t)v43;
        if ( v45 != 0 )
        {
          v46 = 0;
          do
          {
            v54[0] = (encounterGroupRole_t)v43;
            if ( v44 != 0 )
              idLib::Printf(fmt: "^7, %s", v43[v46]);
            else
              idLib::Printf(fmt: "^7%s", *v43);
            ++v44;
            v43 = *(_DWORD **)(v35 + 64);
            v46 = v44;
            v54[0] = (encounterGroupRole_t)v43;
          }
          while ( v43[v44] != 0 );
        }
        idLib::Printf(fmt: "^7]\n");
      }
      else
      {
        idLib::Printf(fmt: "%-32s ^7string\n", *(_DWORD *)(v35 + 40));
      }
      ++v33;
    }
LABEL_100:
    list = v55.list;
    goto LABEL_101;
  }
  if ( v4 != 0 )
  {
    if ( num <= 0 )
      goto LABEL_101;
    for ( k = num; k != 0; --k )
    {
      v48 = *list;
      idLib::Printf(fmt: "%-32s ", *(const char **)(*list + 40));
      idStr::operator=(this: &v57, text: &byte_8200D768);
      v54[0] = *(encounterGroupRole_t *)(v48 + 52);
      if ( (v54[0] & 1) != 0 )
      {
        v49 = "^5B ";
      }
      else if ( (v54[0] & 2) != 0 )
      {
        v49 = "^2I ";
      }
      else
      {
        v49 = "^1F ";
        if ( (v54[0] & 4) == 0 )
          v49 = "^7S ";
      }
      idStr::Append(this: &v57, text: v49);
      v50 = "IN ";
      if ( (*(_DWORD *)(v48 + 52) & 0x4000) == 0 )
        v50 = "   ";
      idStr::Append(this: &v57, text: v50);
      v51 = "RO ";
      if ( (*(_DWORD *)(v48 + 52) & 0x8000) == 0 )
        v51 = "   ";
      idStr::Append(this: &v57, text: v51);
      v52 = "AR ";
      if ( (*(_DWORD *)(v48 + 52) & 0x10000) == 0 )
        v52 = "   ";
      idStr::Append(this: &v57, text: v52);
      v53 = "MO ";
      if ( (*(_DWORD *)(v48 + 52) & 0x20000) == 0 )
        v53 = "   ";
      idStr::Append(this: &v57, text: v53);
      idStr::Append(this: &v57, text: "\n");
      idLib::Printf(fmt: v57.data);
      ++list;
    }
    goto LABEL_100;
  }
  if ( num > 0 )
  {
    v27 = list - 1;
    for ( m = num; m != 0; --m )
    {
      ++v27;
      idLib::Printf(fmt: "%-32s ^7\"%s\"\n", *(const char **)(*v27 + 40), *(const char **)(*v27 + 4));
    }
  }
LABEL_101:
  idLib::Printf(fmt: "\n%i cvars listed\n\n", num);
  idLib::Printf(
    fmt: "listCvars [search string]          = list cvar values\n"
    "listCvars -help [search string]    = list cvar descriptions\n"
    "listCvars -type [search string]    = list cvar types\n"
    "listCvars -flags [search string]   = list cvar flags\n");
  if ( (v55.listStatic == 0 || v55.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  idStr::FreeData(this: &v57);
  idStr::FreeData(this: &v60);
  idStr::FreeData(this: &v61);
}


// ========================================================================
// __unwind$118967
// EA  : 0x82F01740
// RVA : 0x00F01740
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118967()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 208));
}


// ========================================================================
// __unwind$118968
// EA  : 0x82F01768
// RVA : 0x00F01768
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118968()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 176));
}


// ========================================================================
// __unwind$118969
// EA  : 0x82F01790
// RVA : 0x00F01790
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118969()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 128));
}


// ========================================================================
// __unwind$118970
// EA  : 0x82F017B8
// RVA : 0x00F017B8
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118970()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 496 + 96));
}


// ========================================================================
// __unwind$118972
// EA  : 0x82F017E0
// RVA : 0x00F017E0
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118972()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 496;
  if ( (*(_DWORD *)(v0 - 496 + 160) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 160) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 272));
  }
}


// ========================================================================
// __unwind$118975
// EA  : 0x82F01824
// RVA : 0x00F01824
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118975()
{
  int v0; // r12

  idSort_CVarPtr::~idSort_CVarPtr(this: (idSort_CVarPtr *)(v0 - 496 + 112));
}


// ========================================================================
// __unwind$118976
// EA  : 0x82F0184C
// RVA : 0x00F0184C
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118976()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 304));
}


// ========================================================================
// __unwind$118977
// EA  : 0x82F01874
// RVA : 0x00F01874
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_118977()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 240));
}


// ========================================================================
// ?listCvars_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F018A0
// RVA : 0x00F018A0
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

// attributes: thunk
void __fastcall listCvars_f(const idCmdArgs *args)
{
  idCVarSystemLocal::ListCvars(args);
}


// ========================================================================
// ?ArgCompletion_Toggle@@YAXAAVidAutoComplete@@@Z
// EA  : 0x82F018B0
// RVA : 0x00F018B0
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __fastcall ArgCompletion_Toggle(idAutoComplete *autoComplete)
{
  int argc; // r11
  idCmdArgs *p_args; // r26
  int v4; // r30
  int j; // r29
  int v6; // r28
  int v7; // r27
  const char *v8; // r4
  int i; // r29
  idStr *v10; // r29
  int v11; // r30
  idStr *v12; // r28
  idStr v13; // [sp+60h] [-980h] BYREF
  _DWORD v14[2]; // [sp+80h] [-960h] BYREF
  idCmdArgs v15; // [sp+88h] [-958h] BYREF
  idStr *v16; // [sp+98Ch] [-54h]
  int v17; // [sp+990h] [-50h]
  int v18; // [sp+994h] [-4Ch]
  __int16 v19; // [sp+998h] [-48h]
  char v20; // [sp+99Ah] [-46h]
  char v21; // [sp+99Bh] [-45h]

  p_args = &autoComplete->args;
  v4 = 0;
  argc = autoComplete->args.argc;
  if ( argc > 2 )
  {
    v14[0] = 0;
    v15.argc = 0;
    v14[1] = -1;
    v19 = 0;
    v20 = 5;
    v21 = 0;
    v16 = nullptr;
    v18 = 0;
    v17 = 0;
    v6 = 1;
    v7 = 1;
    do
    {
      if ( v6 < 0 || v6 >= argc )
        v8 = &byte_8200D768;
      else
        v8 = p_args->argv[v7];
      idCmdArgs::AppendArg(this: &v15, text: v8);
      argc = p_args->argc;
      ++v6;
      ++v7;
    }
    while ( v6 < p_args->argc );
    cvarSystem->CommandCompletion(this: cvarSystem, a2: (idAutoComplete *)v14);
    for ( i = 0; i < v17; v4 += 8 )
    {
      idAutoComplete::Append(this: autoComplete, suggestion: (idStr *)((char *)v16 + v4 * 4), completingArg: 1);
      ++i;
    }
    if ( v21 == 0 || v21 == 2 )
    {
      v10 = v16;
      if ( v16 != nullptr )
      {
        v11 = v18;
        v12 = v16;
        if ( v18 > 0 )
        {
          do
          {
            idStr::FreeData(this: v10);
            --v11;
            ++v10;
          }
          while ( v11 != 0 );
        }
        idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
      }
    }
  }
  else
  {
    for ( j = 0; j < localCVarSystem.cvars.num; ++v4 )
    {
      idStr::idStr(this: &v13, text: localCVarSystem.cvars.list[v4]->name);
      idAutoComplete::Append(this: autoComplete, suggestion: &v13, completingArg: -1);
      idStr::FreeData(this: &v13);
      ++j;
    }
  }
}


// ========================================================================
// __unwind$119568
// EA  : 0x82F01A7C
// RVA : 0x00F01A7C
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_119568()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2528 + 96));
}


// ========================================================================
// __unwind$119569
// EA  : 0x82F01AA4
// RVA : 0x00F01AA4
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void _unwind_119569()
{
  int v0; // r12

  idAutoComplete::~idAutoComplete(this: (idAutoComplete *)(v0 - 2528 + 128));
}


// ========================================================================
// `dynamic initializer for 'localCVarSystem''
// EA  : 0x833943A8
// RVA : 0x013943A8
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__localCVarSystem__()
{
  idCVarSystemLocal::idCVarSystemLocal(this: &localCVarSystem);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__localCVarSystem__);
}


// ========================================================================
// `dynamic initializer for 'toggle_v''
// EA  : 0x833943E0
// RVA : 0x013943E0
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__toggle_v__()
{
  return idCommandLink::idCommandLink(
           this: &toggle_v,
           cmdName: "toggle",
           function: toggle_f,
           description: "toggles a cvar",
           argCompletion: ArgCompletion_Toggle);
}


// ========================================================================
// `dynamic initializer for 'cvarAdd_v''
// EA  : 0x83394410
// RVA : 0x01394410
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__cvarAdd_v__()
{
  return idCommandLink::idCommandLink(
           this: &cvarAdd_v,
           cmdName: "cvarAdd",
           function: cvarAdd_f,
           description: "adds a value to a cvar",
           argCompletion: ArgCompletion_Cvar1);
}


// ========================================================================
// `dynamic initializer for 'cvarRandom_v''
// EA  : 0x83394440
// RVA : 0x01394440
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__cvarRandom_v__()
{
  return idCommandLink::idCommandLink(
           this: &cvarRandom_v,
           cmdName: "cvarRandom",
           function: cvarRandom_f,
           description: "sets a cvar to a random value",
           argCompletion: ArgCompletion_Cvar1);
}


// ========================================================================
// `dynamic initializer for 'addWrap_v''
// EA  : 0x83394470
// RVA : 0x01394470
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__addWrap_v__()
{
  return idCommandLink::idCommandLink(
           this: &addWrap_v,
           cmdName: "addWrap",
           function: addWrap_f,
           description: "adds to a cvar, with wrapping",
           argCompletion: ArgCompletion_Cvar1);
}


// ========================================================================
// `dynamic initializer for 'addClamp_v''
// EA  : 0x833944A0
// RVA : 0x013944A0
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__addClamp_v__()
{
  return idCommandLink::idCommandLink(
           this: &addClamp_v,
           cmdName: "addClamp",
           function: addClamp_f,
           description: "adds to a cvar, with clamping",
           argCompletion: ArgCompletion_Cvar1);
}


// ========================================================================
// `dynamic initializer for 'cvarMultiply_v''
// EA  : 0x833944D0
// RVA : 0x013944D0
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__cvarMultiply_v__()
{
  return idCommandLink::idCommandLink(
           this: &cvarMultiply_v,
           cmdName: "cvarMultiply",
           function: cvarMultiply_f,
           description: "multiplies a cvar by a value",
           argCompletion: ArgCompletion_Cvar1);
}


// ========================================================================
// `dynamic initializer for 'reset_v''
// EA  : 0x83394500
// RVA : 0x01394500
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reset_v__()
{
  return idCommandLink::idCommandLink(
           this: &reset_v,
           cmdName: "reset",
           function: reset_f,
           description: "resets a cvar to it's default value",
           argCompletion: ArgCompletion_Cvar1);
}


// ========================================================================
// `dynamic initializer for 'listCvars_v''
// EA  : 0x83394530
// RVA : 0x01394530
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__listCvars_v__()
{
  return idCommandLink::idCommandLink(
           this: &listCvars_v,
           cmdName: "listCvars",
           function: listCvars_f,
           description: "lists cvars",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'cvar_restart_v''
// EA  : 0x83394558
// RVA : 0x01394558
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__cvar_restart_v__()
{
  return idCommandLink::idCommandLink(
           this: &cvar_restart_v,
           cmdName: "cvar_restart",
           function: cvar_restart_f,
           description: "restarts the cvar system, defaulting all cvars",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'cvarsModified_v''
// EA  : 0x83394580
// RVA : 0x01394580
// PDB : w:\tech5\shared\idlib\csystems\cvarsystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__cvarsModified_v__()
{
  return idCommandLink::idCommandLink(
           this: &cvarsModified_v,
           cmdName: "cvarsModified",
           function: cvarsModified_f,
           description: "reports cvars modified since the last call",
           argCompletion: nullptr);
}

