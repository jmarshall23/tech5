
// ========================================================================
// ??1idAIVar@@UAA@XZ
// EA  : 0x824E2D58
// RVA : 0x004E2D58
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar::~idAIVar(idAIVar *this)
{
  this->__vftable = (idAIVar_vtbl *)&idAIVar::`vftable';
  idStr::FreeData(this: &this->name);
  this->__vftable = (idAIVar_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$532971
// EA  : 0x824E2DB0
// RVA : 0x004E2DB0
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void _unwind_532971()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idAIVar_String@@QAA@XZ
// EA  : 0x824E2E38
// RVA : 0x004E2E38
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

idAIVar_String *__fastcall idAIVar_String::idAIVar_String(idAIVar_String *this)
{
  this->__vftable = (idAIVar_String_vtbl *)&idAIVar::`vftable';
  this->name.data = this->name.baseBuffer;
  this->name.len = 0;
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  this->__vftable = (idAIVar_String_vtbl *)&idAIVar_String::`vftable';
  this->stringVal.allocedAndFlag = 20;
  this->stringVal.data = this->stringVal.baseBuffer;
  this->stringVal.len = 0;
  this->stringVal.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// ??1idAIVar_String@@UAA@XZ
// EA  : 0x824E2F00
// RVA : 0x004E2F00
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_String::~idAIVar_String(idAIVar_String *this)
{
  this->__vftable = (idAIVar_String_vtbl *)&idAIVar_String::`vftable';
  idStr::FreeData(this: &this->stringVal);
  idAIVar::~idAIVar(this);
}


// ========================================================================
// __unwind$533095
// EA  : 0x824E2F54
// RVA : 0x004E2F54
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void _unwind_533095()
{
  int v0; // r12

  idAIVar::~idAIVar(this: *(idAIVar **)(v0 - 112 + 132));
}


// ========================================================================
// ?Compare@idAIVar_String@@UBA_NABVidAIVar@@W4aiVarOp_t@@@Z
// EA  : 0x824E2F88
// RVA : 0x004E2F88
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

int __fastcall idAIVar_String::Compare(idAIVar_String *this, idAIVar *other, aiVarOp_t op)
{
  int v5; // r30
  idStr v7[2]; // [sp+50h] [-40h] BYREF

  v7[0].len = 0;
  v7[0].allocedAndFlag = 20;
  v7[0].data = v7[0].baseBuffer;
  v7[0].baseBuffer[0] = 0;
  other->GetString(this: other, a2: v7);
  v5 = ((int (__fastcall *)(idAIVar_String *, char *, aiVarOp_t))this->Compare_3)(a1: this, a2: v7[0].data, a3: op);
  idStr::FreeData(this: v7);
  return v5;
}


// ========================================================================
// __unwind$533117
// EA  : 0x824E300C
// RVA : 0x004E300C
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void _unwind_533117()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?Compare@idAIVar_String@@UBA_NPBDW4aiVarOp_t@@@Z
// EA  : 0x824E3038
// RVA : 0x004E3038
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

BOOL __fastcall idAIVar_String::Compare(idAIVar_String *this, const char *otherVal, unsigned int op)
{
  int v3; // r3
  int v5; // r3

  if ( op > 4 )
    return false;
  switch ( op )
  {
    case 1u:
      v3 = idStr::Cmp(s1: this->stringVal.data, s2: otherVal);
      return (v3 | (unsigned int)(v3 - 1)) >> 31;
    case 2u:
      return (_cntlzw(idStr::Cmp(s1: this->stringVal.data, s2: otherVal)) & 0x20) != 0;
    case 3u:
      return idStr::Cmp(s1: this->stringVal.data, s2: otherVal) >= 0;
    default:
      if ( op != 0 )
      {
        v5 = idStr::Cmp(s1: this->stringVal.data, s2: otherVal);
        return (-v5 & (unsigned int)~v5) >> 31;
      }
      else
      {
        return (unsigned int)idStr::Cmp(s1: this->stringVal.data, s2: otherVal) >> 31;
      }
  }
}


// ========================================================================
// ?Compare@idAIVar_String@@UBA_NHW4aiVarOp_t@@@Z
// EA  : 0x824E3120
// RVA : 0x004E3120
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

BOOL __fastcall idAIVar_String::Compare(idAIVar_String *this, const int val, __int64 op, __int64 a4, __int64 a5)
{
  aiVarOp_t v5; // r30
  va *v7; // r3
  int v9; // [sp+8h] [-1068h]
  int v10; // [sp+Ch] [-1064h]
  int v11; // [sp+10h] [-1060h]
  int v12; // [sp+14h] [-105Ch]
  int v13; // [sp+18h] [-1058h]
  int v14; // [sp+1Ch] [-1054h]
  va v15; // [sp+50h] [-1020h] BYREF

  v5 = HIDWORD(op);
  HIDWORD(op) = val;
  v7 = va::va(this: &v15, fmt: "%d", a3: op, a4, a5, a6: v9, a7: v10, a8: v11, a9: v12, a10: v13, a11: v14);
  return this->Compare_3(this, a2: (const char *)v7, a3: v5);
}


// ========================================================================
// ?Compare@idAIVar_String@@UBA_NMW4aiVarOp_t@@@Z
// EA  : 0x824E3188
// RVA : 0x004E3188
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

BOOL __fastcall idAIVar_String::Compare(
        idAIVar_String *this,
        double val,
        const aiVarOp_t op,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  aiVarOp_t v6; // r30
  va *v8; // r3
  int v10; // [sp+8h] [-1068h]
  int v11; // [sp+Ch] [-1064h]
  int v12; // [sp+10h] [-1060h]
  int v13; // [sp+14h] [-105Ch]
  int v14; // [sp+18h] [-1058h]
  int v15; // [sp+1Ch] [-1054h]
  va v16; // [sp+50h] [-1020h] BYREF

  v6 = HIDWORD(a4);
  HIDWORD(a4) = LODWORD(val);
  v8 = va::va(this: &v16, fmt: "%g", a3: a4, a4: a5, a5: a6, a6: v10, a7: v11, a8: v12, a9: v13, a10: v14, a11: v15);
  return this->Compare_3(this, a2: (const char *)v8, a3: v6);
}


// ========================================================================
// ?Set@idAIVar_String@@UAAXPBD@Z
// EA  : 0x824E31F8
// RVA : 0x004E31F8
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_String::Set(idAIVar_String *this, const char *val)
{
  idStr::operator=(this: &this->stringVal, text: val);
}


// ========================================================================
// ?GetInt@idAIVar_String@@UBAHXZ
// EA  : 0x824E3200
// RVA : 0x004E3200
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

int __fastcall idAIVar_String::GetInt(idAIVar_String *this)
{
  return atol(nptr: this->stringVal.data);
}


// ========================================================================
// ?GetFloat@idAIVar_String@@UBAMXZ
// EA  : 0x824E3208
// RVA : 0x004E3208
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

float __fastcall idAIVar_String::GetFloat(idAIVar_String *this)
{
  long double v1; // fp2
  double v2; // fp1

  v1 = atof(nptr: this->stringVal.data);
  v2 = (float)*(double *)&v1;
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?Copy@idAIVar@@UAAXABV1@@Z
// EA  : 0x824FA1B0
// RVA : 0x004FA1B0
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar::Copy(idAIVar *this, const idAIVar *other)
{
  int len; // r30

  if ( other != this )
  {
    len = other->name.len;
    idStr::EnsureAlloced(this: &this->name, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->name.data, Src: other->name.data, Size: len);
    this->name.data[len] = 0;
    this->name.len = len;
  }
}


// ========================================================================
// ?Copy@idAIVar_String@@UAAXABVidAIVar@@@Z
// EA  : 0x824FA218
// RVA : 0x004FA218
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_String::Copy(idAIVar_String *this, idAIVar_String *other)
{
  int len; // r28
  int v5; // r29
  idStr v6[2]; // [sp+60h] [-50h] BYREF

  if ( other != this )
  {
    len = other->name.len;
    idStr::EnsureAlloced(this: &this->name, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->name.data, Src: other->name.data, Size: len);
    this->name.data[len] = 0;
    v6[0].allocedAndFlag = 20;
    this->name.len = len;
    v6[0].data = v6[0].baseBuffer;
    v6[0].len = 0;
    v6[0].baseBuffer[0] = 0;
    other->GetString(this: other, a2: v6);
    v5 = v6[0].len;
    idStr::EnsureAlloced(this: &this->stringVal, amount: v6[0].len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->stringVal.data, Src: v6[0].data, Size: v5);
    this->stringVal.data[v5] = 0;
    this->stringVal.len = v5;
    idStr::FreeData(this: v6);
  }
}


// ========================================================================
// __unwind$578523
// EA  : 0x824FA2F0
// RVA : 0x004FA2F0
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void _unwind_578523()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?Set@idAIVar_String@@UAAXH@Z
// EA  : 0x824FA318
// RVA : 0x004FA318
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_String::Set(idAIVar_String *this, const int val, __int64 a3, __int64 a4, __int64 a5)
{
  va *v6; // r3
  int v7; // [sp+8h] [-1058h]
  int v8; // [sp+Ch] [-1054h]
  int v9; // [sp+10h] [-1050h]
  int v10; // [sp+14h] [-104Ch]
  int v11; // [sp+18h] [-1048h]
  int v12; // [sp+1Ch] [-1044h]
  va v13; // [sp+50h] [-1010h] BYREF

  HIDWORD(a3) = val;
  v6 = va::va(this: &v13, fmt: "%d", a3, a4, a5, a6: v7, a7: v8, a8: v9, a9: v10, a10: v11, a11: v12);
  idStr::operator=(this: &this->stringVal, text: v6);
}


// ========================================================================
// ?Set@idAIVar_String@@UAAXM@Z
// EA  : 0x824FA368
// RVA : 0x004FA368
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_String::Set(idAIVar_String *this, double val, int a3, __int64 a4, __int64 a5, __int64 a6)
{
  va *v7; // r3
  int v8; // [sp+8h] [-1058h]
  int v9; // [sp+Ch] [-1054h]
  int v10; // [sp+10h] [-1050h]
  int v11; // [sp+14h] [-104Ch]
  int v12; // [sp+18h] [-1048h]
  int v13; // [sp+1Ch] [-1044h]
  va v14; // [sp+50h] [-1010h] BYREF

  HIDWORD(a4) = LODWORD(val);
  v7 = va::va(this: &v14, fmt: "%g", a3: a4, a4: a5, a5: a6, a6: v8, a7: v9, a8: v10, a9: v11, a10: v12, a11: v13);
  idStr::operator=(this: &this->stringVal, text: v7);
}


// ========================================================================
// ?GetString@idAIVar_String@@UBAXAAVidStr@@@Z
// EA  : 0x824FA3B8
// RVA : 0x004FA3B8
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_String::GetString(idAIVar_String *this, idStr *out)
{
  int len; // r31

  len = this->stringVal.len;
  idStr::EnsureAlloced(this: out, amount: len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: out->data, Src: this->stringVal.data, Size: len);
  out->data[len] = 0;
  out->len = len;
}


// ========================================================================
// ??0idAIVar_Int@@QAA@XZ
// EA  : 0x82501048
// RVA : 0x00501048
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

idAIVar_Int *__fastcall idAIVar_Int::idAIVar_Int(idAIVar_Int *this)
{
  this->__vftable = (idAIVar_Int_vtbl *)&idAIVar::`vftable';
  this->name.len = 0;
  this->name.allocedAndFlag = 20;
  this->name.data = this->name.baseBuffer;
  this->name.baseBuffer[0] = 0;
  this->__vftable = (idAIVar_Int_vtbl *)&idAIVar_Int::`vftable';
  this->intVal = 0;
  return this;
}


// ========================================================================
// ??1idAIVar_Int@@UAA@XZ
// EA  : 0x82501088
// RVA : 0x00501088
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_Int::~idAIVar_Int(idAIVar_Int *this)
{
  this->__vftable = (idAIVar_Int_vtbl *)&idAIVar_Int::`vftable';
  idAIVar::~idAIVar(this);
}


// ========================================================================
// ?Compare@idAIVar_Int@@UBA_NABVidAIVar@@W4aiVarOp_t@@@Z
// EA  : 0x82501098
// RVA : 0x00501098
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

BOOL __fastcall idAIVar_Int::Compare(idAIVar_Int *this, idAIVar *other, aiVarOp_t op)
{
  int v5; // r3

  v5 = other->GetInt(this: other);
  return this->Compare_2(this, a2: v5, a3: op);
}


// ========================================================================
// ?Compare@idAIVar_Int@@UBA_NPBDW4aiVarOp_t@@@Z
// EA  : 0x82501100
// RVA : 0x00501100
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

BOOL __fastcall idAIVar_Int::Compare(idAIVar_Int *this, const char *val, aiVarOp_t op)
{
  int v5; // r3

  v5 = atol(nptr: val);
  return this->Compare_2(this, a2: v5, a3: op);
}


// ========================================================================
// ?Compare@idAIVar_Int@@UBA_NHW4aiVarOp_t@@@Z
// EA  : 0x82501158
// RVA : 0x00501158
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

int __fastcall idAIVar_Int::Compare(idAIVar_Int *this, unsigned int otherVal, unsigned int op)
{
  char v3; // r7

  if ( op > 4 )
    return 0;
  switch ( op )
  {
    case 1u:
      return (int)otherVal >= this->intVal;
    case 2u:
      return (_cntlzw(otherVal - this->intVal) & 0x20) != 0;
    case 3u:
      return this->intVal >= (int)otherVal;
    default:
      break;
  }
  if ( op != 0 )
    v3 = (((this->intVal ^ otherVal) & 0x80000000) == 0) + (otherVal >= this->intVal);
  else
    v3 = (((otherVal ^ this->intVal) & 0x80000000) == 0) + (this->intVal >= otherVal);
  return v3 & 1;
}


// ========================================================================
// ?Compare@idAIVar_Int@@UBA_NMW4aiVarOp_t@@@Z
// EA  : 0x82501208
// RVA : 0x00501208
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

BOOL __fastcall idAIVar_Int::Compare(idAIVar_Int *this, double val, const aiVarOp_t op)
{
  return ((bool (__fastcall *)(idAIVar_Int *, int))this->Compare_2)(a1: this, a2: (int)val);
}


// ========================================================================
// ?Set@idAIVar_Int@@UAAXPBD@Z
// EA  : 0x82501240
// RVA : 0x00501240
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_Int::Set(idAIVar_Int *this, const char *val)
{
  if ( val != nullptr )
    this->intVal = atol(nptr: val);
  else
    this->intVal = 0;
}


// ========================================================================
// ?Set@idAIVar_Int@@UAAXH@Z
// EA  : 0x82501298
// RVA : 0x00501298
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_Int::Set(idAIVar_Int *this, int val)
{
  this->intVal = val;
}


// ========================================================================
// ?Set@idAIVar_Int@@UAAXM@Z
// EA  : 0x825012A0
// RVA : 0x005012A0
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_Int::Set(idAIVar_Int *this, double val)
{
  this->intVal = (int)val;
}


// ========================================================================
// ?GetFloat@idAIVar_Int@@UBAMXZ
// EA  : 0x825012B0
// RVA : 0x005012B0
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

float __fastcall idAIVar_Int::GetFloat(idAIVar_Int *this, int a2, int a3, int a4, int a5, int a6, __int64 a7)
{
  double v7; // fp1

  LODWORD(a7) = this->intVal;
  v7 = (float)a7;
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?Copy@idAIVar_Int@@UAAXABVidAIVar@@@Z
// EA  : 0x82518048
// RVA : 0x00518048
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_Int::Copy(idAIVar_Int *this, idAIVar_Int *other)
{
  int len; // r29

  if ( other != this )
  {
    len = other->name.len;
    idStr::EnsureAlloced(this: &this->name, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->name.data, Src: other->name.data, Size: len);
    this->name.data[len] = 0;
    this->name.len = len;
    this->intVal = other->GetInt(this: other);
  }
}


// ========================================================================
// ?GetString@idAIVar_Int@@UBAXAAVidStr@@@Z
// EA  : 0x825180C0
// RVA : 0x005180C0
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_Int::GetString(idAIVar_Int *this, idStr *out, __int64 a3, __int64 a4, __int64 a5)
{
  va *v6; // r3
  int v7; // [sp+8h] [-1058h]
  int v8; // [sp+Ch] [-1054h]
  int v9; // [sp+10h] [-1050h]
  int v10; // [sp+14h] [-104Ch]
  int v11; // [sp+18h] [-1048h]
  int v12; // [sp+1Ch] [-1044h]
  va v13; // [sp+50h] [-1010h] BYREF

  HIDWORD(a3) = this->intVal;
  v6 = va::va(this: &v13, fmt: "%d", a3, a4, a5, a6: v7, a7: v8, a8: v9, a9: v10, a10: v11, a11: v12);
  idStr::operator=(this: out, text: v6);
}


// ========================================================================
// ??0idAIVar_Float@@QAA@XZ
// EA  : 0x8251CB60
// RVA : 0x0051CB60
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

idAIVar_Float *__fastcall idAIVar_Float::idAIVar_Float(idAIVar_Float *this)
{
  this->__vftable = (idAIVar_Float_vtbl *)&idAIVar::`vftable';
  this->name.len = 0;
  this->name.allocedAndFlag = 20;
  this->name.data = this->name.baseBuffer;
  this->name.baseBuffer[0] = 0;
  this->floatVal = 0.0;
  this->__vftable = (idAIVar_Float_vtbl *)&idAIVar_Float::`vftable';
  return this;
}


// ========================================================================
// ??1idAIVar_Float@@UAA@XZ
// EA  : 0x8251CBA8
// RVA : 0x0051CBA8
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_Float::~idAIVar_Float(idAIVar_Float *this)
{
  this->__vftable = (idAIVar_Float_vtbl *)&idAIVar_Float::`vftable';
  idAIVar::~idAIVar(this);
}


// ========================================================================
// ?Compare@idAIVar_Float@@UBA_NABVidAIVar@@W4aiVarOp_t@@@Z
// EA  : 0x8251CBB8
// RVA : 0x0051CBB8
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

BOOL __fastcall idAIVar_Float::Compare(idAIVar_Float *this, idAIVar *other, const aiVarOp_t op)
{
  other->GetFloat(this: other);
  return ((bool (__fastcall *)(idAIVar_Float *))this->Compare)(a1: this);
}


// ========================================================================
// ?Compare@idAIVar_Float@@UBA_NPBDW4aiVarOp_t@@@Z
// EA  : 0x8251CC18
// RVA : 0x0051CC18
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

BOOL __fastcall idAIVar_Float::Compare(idAIVar_Float *this, const char *val, const aiVarOp_t op)
{
  long double v4; // fp2

  v4 = atof(nptr: val);
  return ((bool (__fastcall *)(idAIVar_Float *, double, double))this->Compare)(
           a1: this,
           a2: (float)*(double *)&v4,
           a3: *((double *)&v4 + 1));
}


// ========================================================================
// ?Compare@idAIVar_Float@@UBA_NHW4aiVarOp_t@@@Z
// EA  : 0x8251CC70
// RVA : 0x0051CC70
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

BOOL __fastcall idAIVar_Float::Compare(idAIVar_Float *this, int val, aiVarOp_t op)
{
  __int64 v3; // r11

  LODWORD(v3) = val;
  HIDWORD(v3) = this->__vftable;
  return ((bool (__fastcall *)(idAIVar_Float *, int, aiVarOp_t, double))this->Compare)(
           a1: this,
           a2: val,
           a3: op,
           a4: (float)v3);
}


// ========================================================================
// ?Compare@idAIVar_Float@@UBA_NMW4aiVarOp_t@@@Z
// EA  : 0x8251CCB0
// RVA : 0x0051CCB0
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

int __fastcall idAIVar_Float::Compare(idAIVar_Float *this, double otherVal, const aiVarOp_t op, unsigned int a4)
{
  unsigned __int8 v4; // r11

  if ( a4 > 4 )
    return 0;
  switch ( a4 )
  {
    case 1u:
      v4 = 1;
      if ( this->floatVal <= otherVal )
        return v4;
      return 0;
    case 2u:
      v4 = 1;
      if ( this->floatVal == otherVal )
        return v4;
      return 0;
    case 3u:
      v4 = 1;
      if ( this->floatVal >= otherVal )
        return v4;
      return 0;
    case 0u:
      return this->floatVal < otherVal;
    default:
      v4 = 1;
      if ( this->floatVal > otherVal )
        return v4;
      return 0;
  }
}


// ========================================================================
// ?Set@idAIVar_Float@@UAAXPBD@Z
// EA  : 0x8251CD68
// RVA : 0x0051CD68
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_Float::Set(idAIVar_Float *this, const char *val)
{
  double v3; // fp0
  long double v4; // fp2

  if ( val != nullptr )
  {
    v4 = atof(nptr: val);
    v3 = (float)*(double *)&v4;
  }
  else
  {
    v3 = 0.0;
  }
  this->floatVal = v3;
}


// ========================================================================
// ?Set@idAIVar_Float@@UAAXH@Z
// EA  : 0x8251CDB8
// RVA : 0x0051CDB8
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_Float::Set(idAIVar_Float *this, const int val)
{
  __int64 v2; // r11

  LODWORD(v2) = val;
  this->floatVal = (float)v2;
}


// ========================================================================
// ?Set@idAIVar_Float@@UAAXM@Z
// EA  : 0x8251CDD8
// RVA : 0x0051CDD8
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_Float::Set(idAIVar_Float *this, double val)
{
  this->floatVal = val;
}


// ========================================================================
// ?GetInt@idAIVar_Float@@UBAHXZ
// EA  : 0x8251CDE0
// RVA : 0x0051CDE0
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

int __fastcall idAIVar_Float::GetInt(idAIVar_Float *this)
{
  return (int)this->floatVal;
}


// ========================================================================
// ?GetFloat@idAIVar_Float@@UBAMXZ
// EA  : 0x8251CDF8
// RVA : 0x0051CDF8
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

float __fastcall idAIVar_Float::GetFloat(idAIVar_Float *this)
{
  double floatVal; // fp1

  floatVal = this->floatVal;
  return *((float *)&floatVal + 1);
}


// ========================================================================
// ?Copy@idAIVar_Float@@UAAXABVidAIVar@@@Z
// EA  : 0x82536580
// RVA : 0x00536580
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_Float::Copy(idAIVar_Float *this, idAIVar_Float *other)
{
  int len; // r29

  if ( other != this )
  {
    len = other->name.len;
    idStr::EnsureAlloced(this: &this->name, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->name.data, Src: other->name.data, Size: len);
    this->name.data[len] = 0;
    this->name.len = len;
    this->floatVal = other->GetFloat(this: other);
  }
}


// ========================================================================
// ?GetString@idAIVar_Float@@UBAXAAVidStr@@@Z
// EA  : 0x825365F8
// RVA : 0x005365F8
// PDB : w:\tech5\tungsten\game\ai\aiblackboard.h
// ========================================================================

void __fastcall idAIVar_Float::GetString(idAIVar_Float *this, idStr *out, __int64 a3, __int64 a4, __int64 a5)
{
  double floatVal; // kr00_8
  va *v6; // r3
  int v7; // [sp+8h] [-1058h]
  int v8; // [sp+Ch] [-1054h]
  int v9; // [sp+10h] [-1050h]
  int v10; // [sp+14h] [-104Ch]
  int v11; // [sp+18h] [-1048h]
  int v12; // [sp+1Ch] [-1044h]
  va v13; // [sp+50h] [-1010h] BYREF

  floatVal = this->floatVal;
  HIDWORD(a3) = LODWORD(floatVal);
  v6 = va::va(this: &v13, fmt: "%g", a3, a4, a5, a6: v7, a7: v8, a8: v9, a9: v10, a10: v11, a11: v12);
  idStr::operator=(this: (idStr *)HIDWORD(floatVal), text: v6);
}

