
// ========================================================================
// ?StrictEquals@idSWFScriptVar@@QAA_NABV1@@Z
// EA  : 0x8278C928
// RVA : 0x0078C928
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

int __fastcall idSWFScriptVar::StrictEquals(idSWFScriptVar *this, const idSWFScriptVar *other)
{
  idSWFScriptVar::swfScriptVarType type; // r11

  type = this->type;
  if ( this->type != other->type || (unsigned int)type > SWF_VAR_OBJECT )
    return 0;
  switch ( type )
  {
    case SWF_VAR_STRING:
      return (_cntlzw(idStr::Cmp(s1: *(const char **)(this->value.i + 4), s2: *(const char **)(other->value.i + 4)))
            & 0x20) != 0;
    case SWF_VAR_FLOAT:
      return this->value.f == other->value.f;
    case SWF_VAR_NULL:
    case SWF_VAR_UNDEF:
      return 1;
    case SWF_VAR_BOOL:
      return (_cntlzw(other->value.b - this->value.b) & 0x20) != 0;
    default:
      break;
  }
  return (_cntlzw(other->value.i - this->value.i) & 0x20) != 0;
}


// ========================================================================
// ?ToSprite@idSWFScriptVar@@QAAPAVidSWFSpriteInstance@@XZ
// EA  : 0x8278CA40
// RVA : 0x0078CA40
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

idSWFSpriteInstance *__fastcall idSWFScriptVar::ToSprite(idSWFScriptVar *this)
{
  idSWFScriptVar::swfScriptVarValue_t v1; // r11

  if ( this->type == SWF_VAR_OBJECT && (LODWORD(v1.f) = this->value, v1.i != 0) && *(_DWORD *)(v1.i + 88) == 2 )
    return *(idSWFSpriteInstance **)(v1.i + 92);
  else
    return nullptr;
}


// ========================================================================
// ?TypeOf@idSWFScriptVar@@QBAPBDXZ
// EA  : 0x8278CA78
// RVA : 0x0078CA78
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

char *__fastcall idSWFScriptVar::TypeOf(idSWFScriptVar *this)
{
  idSWFScriptVar::swfScriptVarType type; // r11
  idSWFScriptVar::swfScriptVarValue_t v3; // r11

  type = this->type;
  if ( this->type > (unsigned int)SWF_VAR_OBJECT )
    return &byte_8200D768;
  switch ( type )
  {
    case SWF_VAR_STRING:
      return "string";
    case SWF_VAR_FLOAT:
      return "number";
    case SWF_VAR_NULL:
      return "null";
    case SWF_VAR_UNDEF:
      return "undefined";
    case SWF_VAR_BOOL:
      return "boolean";
    case SWF_VAR_INTEGER:
      return "number";
    case SWF_VAR_FUNCTION:
      return "function";
    case SWF_VAR_STRINGID:
      return "stringid";
    default:
      break;
  }
  LODWORD(v3.f) = this->value;
  if ( *(_DWORD *)(v3.i + 88) == 2 && *(_DWORD *)(v3.i + 92) != 0 )
    return "movieclip";
  if ( *(_DWORD *)(v3.i + 88) == 3 && *(_DWORD *)(v3.i + 92) != 0 )
    return "text";
  return "object";
}


// ========================================================================
// ?ToString@idSWFScriptVar@@QBA?AVidStr@@XZ
// EA  : 0x8278CB70
// RVA : 0x0078CB70
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

idSWFScriptVar *__fastcall idSWFScriptVar::ToString(
        idSWFScriptVar *this,
        idStr *result,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  unsigned int len; // r11
  va *v7; // r3
  va *v8; // r3
  const char *LocalizedString; // r4
  idStr *v10; // r3
  va *v11; // r3
  int v13; // [sp+8h] [-3078h]
  int v14; // [sp+Ch] [-3074h]
  int v15; // [sp+10h] [-3070h]
  int v16; // [sp+14h] [-306Ch]
  int v17; // [sp+18h] [-3068h]
  int v18; // [sp+1Ch] [-3064h]
  double v19; // [sp+20h] [-3060h]
  idStrId v20; // [sp+50h] [-3030h] BYREF
  idSWFScriptObject v21[42]; // [sp+58h] [-3028h] BYREF
  va v22; // [sp+1060h] [-2020h] BYREF
  va v23; // [sp+2060h] [-1020h] BYREF

  len = result->len;
  LODWORD(a5) = 0;
  v20.index = 0;
  if ( len > 8 )
  {
    LocalizedString = &byte_8200D768;
    goto LABEL_24;
  }
  if ( len != 1 )
  {
    switch ( len )
    {
      case 2u:
        v19 = *(float *)&result->data;
        HIDWORD(a3) = LODWORD(v19);
        v7 = va::va(
               this: (va *)&v21[0].variables.num,
               fmt: "%g",
               a3,
               a4,
               a5,
               a6: v13,
               a7: v14,
               a8: v15,
               a9: v16,
               a10: v17,
               a11: v18);
        idStr::idStr((idStr *)this, text: v7);
        return this;
      case 3u:
        LocalizedString = "[null]";
        break;
      case 4u:
        LocalizedString = "[undefined]";
        break;
      case 5u:
        if ( HIBYTE(result->data) != 0 )
          LocalizedString = "true";
        else
          LocalizedString = "false";
        break;
      case 6u:
        HIDWORD(a3) = result->data;
        v8 = va::va(this: &v22, fmt: "%i", a3, a4, a5, a6: v13, a7: v14, a8: v15, a9: v16, a10: v17, a11: v18);
        idStr::idStr((idStr *)this, text: v8);
        return this;
      case 7u:
        LODWORD(a5) = &swf_debugShowAddress;
        if ( swf_debugShowAddress.valueInteger != 0 )
        {
          HIDWORD(a3) = result->data;
          v11 = va::va(
                  this: &v23,
                  fmt: "[function:%p]",
                  a3,
                  a4,
                  a5,
                  a6: v13,
                  a7: v14,
                  a8: v15,
                  a9: v16,
                  a10: v17,
                  a11: v18);
          idStr::idStr((idStr *)this, text: v11);
          return this;
        }
        LocalizedString = "[function]";
        break;
      case 0u:
        v20.index = (int)result->data;
        LocalizedString = idStrId::GetLocalizedString(this: &v20);
        break;
      default:
        v10 = (idStr *)idSWFScriptObject::DefaultValue(
                         this: v21,
                         result: (idSWFScriptObject *)result->data,
                         stringHint: true);
        idSWFScriptVar::ToString(this, result: v10);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)v21);
        return this;
    }
LABEL_24:
    idStr::idStr((idStr *)this, text: LocalizedString);
    return this;
  }
  idStr::idStr((idStr *)this, text: (const idStr *)result->data);
  return this;
}


// ========================================================================
// __unwind$219767
// EA  : 0x8278CD20
// RVA : 0x0078CD20
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

void _unwind_219767()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 12416 + 88));
}


// ========================================================================
// ?ToFloat@idSWFScriptVar@@QBAMXZ
// EA  : 0x8278CD50
// RVA : 0x0078CD50
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

float __fastcall idSWFScriptVar::ToFloat(idSWFScriptVar *this, int a2, int a3, int a4, int a5, int a6, __int64 a7)
{
  long double v7; // fp2
  double f; // fp1
  idSWFScriptObject *v9; // r3
  double v10; // fp31
  idSWFScriptVar v12; // [sp+50h] [-20h] BYREF

  if ( (unsigned int)(this->type - 1) <= 7 )
  {
    if ( this->type == SWF_VAR_FLOAT )
    {
      f = this->value.f;
      return *((float *)&f + 1);
    }
    if ( this->type != SWF_VAR_NULL && this->type != SWF_VAR_UNDEF )
    {
      if ( this->type == SWF_VAR_BOOL )
      {
        LODWORD(a7) = this->value.b;
        f = (float)a7;
        return *((float *)&f + 1);
      }
      if ( this->type == SWF_VAR_INTEGER )
      {
        LODWORD(a7) = this->value.i;
        f = (float)a7;
        return *((float *)&f + 1);
      }
      if ( this->type != SWF_VAR_FUNCTION )
      {
        if ( this->type == SWF_VAR_STRING )
        {
          v7 = atof(nptr: (const char *)*(_DWORD *)(this->value.i + 4));
          f = (float)*(double *)&v7;
        }
        else
        {
          v9 = idSWFScriptObject::DefaultValue(
                 this: (idSWFScriptObject *)&v12,
                 result: this->value.object,
                 stringHint: false);
          v10 = idSWFScriptVar::ToFloat(this: (idSWFScriptVar *)v9);
          idSWFScriptVar::Free(this: &v12);
          f = v10;
        }
        return *((float *)&f + 1);
      }
    }
  }
  f = 0.0;
  return *((float *)&f + 1);
}


// ========================================================================
// __unwind$219801
// EA  : 0x8278CE34
// RVA : 0x0078CE34
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

void _unwind_219801()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 112 + 80));
}


// ========================================================================
// ?ToBool@idSWFScriptVar@@QBA_NXZ
// EA  : 0x8278CE68
// RVA : 0x0078CE68
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

int __fastcall idSWFScriptVar::ToBool(idSWFScriptVar *this)
{
  int v2; // r3
  unsigned __int8 v3; // r11
  idSWFScriptObject *v5; // r3
  BOOL v6; // r30
  idSWFScriptVar v7; // [sp+50h] [-20h] BYREF

  if ( (unsigned int)(this->type - 1) > 7 )
    return 0;
  switch ( this->type )
  {
    case SWF_VAR_FLOAT:
      return this->value.f != 0.0;
    case SWF_VAR_NULL:
    case SWF_VAR_UNDEF:
      return 0;
    case SWF_VAR_BOOL:
      return this->value.b;
    case SWF_VAR_INTEGER:
      return this->value.i != 0;
    case SWF_VAR_FUNCTION:
      return 0;
    case SWF_VAR_STRING:
      if ( idStr::Icmp(s1: *(const char **)(this->value.i + 4), s2: "true") == 0 )
        return 1;
      v2 = idStr::Icmp(s1: *(const char **)(this->value.i + 4), s2: "1");
      v3 = 0;
      if ( v2 == 0 )
        return 1;
      return v3;
    default:
      v5 = idSWFScriptObject::DefaultValue(
             this: (idSWFScriptObject *)&v7,
             result: this->value.object,
             stringHint: false);
      v6 = idSWFScriptVar::ToBool(this: (idSWFScriptVar *)v5);
      idSWFScriptVar::Free(this: &v7);
      return v6;
  }
}


// ========================================================================
// __unwind$219840
// EA  : 0x8278CF80
// RVA : 0x0078CF80
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

void _unwind_219840()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 112 + 80));
}


// ========================================================================
// ?ToInteger@idSWFScriptVar@@QBAHXZ
// EA  : 0x8278CFB0
// RVA : 0x0078CFB0
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

int __fastcall idSWFScriptVar::ToInteger(idSWFScriptVar *this)
{
  idSWFScriptObject *v2; // r3
  int v3; // r30
  idSWFScriptVar v4; // [sp+50h] [-20h] BYREF

  if ( (unsigned int)(this->type - 1) > 7 )
    return 0;
  switch ( this->type )
  {
    case SWF_VAR_FLOAT:
      v4.value.i = (int)this->value.f;
      return v4.value.i;
    case SWF_VAR_NULL:
    case SWF_VAR_UNDEF:
      return 0;
    case SWF_VAR_BOOL:
      return this->value.b;
    case SWF_VAR_INTEGER:
      return this->value.i;
    case SWF_VAR_FUNCTION:
      return 0;
    case SWF_VAR_STRING:
      return atol(nptr: *(const char **)(this->value.i + 4));
    default:
      break;
  }
  v2 = idSWFScriptObject::DefaultValue(this: (idSWFScriptObject *)&v4, result: this->value.object, stringHint: false);
  v3 = idSWFScriptVar::ToInteger(this: (idSWFScriptVar *)v2);
  idSWFScriptVar::Free(this: &v4);
  return v3;
}


// ========================================================================
// __unwind$219872
// EA  : 0x8278D07C
// RVA : 0x0078D07C
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

void _unwind_219872()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetNestedVar@idSWFScriptVar@@QAA?AV1@PBD00000@Z
// EA  : 0x8278D0A8
// RVA : 0x0078D0A8
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

idSWFScriptVar *__fastcall idSWFScriptVar::GetNestedVar(
        idSWFScriptVar *this,
        idSWFScriptVar *result,
        const char *arg1,
        const char *arg2,
        const char *arg3,
        const char *arg4,
        const char *arg5,
        const char *arg6)
{
  idSWFScriptVar *v8; // r31

  v8 = this;
  if ( result->type == SWF_VAR_OBJECT )
  {
    idSWFScriptObject::GetNestedVar(
      (idSWFScriptObject *)this,
      result: result->value.object,
      arg1,
      arg2,
      arg3,
      arg4,
      arg5,
      arg6);
    return v8;
  }
  else
  {
    this->type = SWF_VAR_UNDEF;
  }
  return this;
}


// ========================================================================
// ?PrintToConsole@idSWFScriptVar@@QBAXXZ
// EA  : 0x8278D110
// RVA : 0x0078D110
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

void __fastcall idSWFScriptVar::PrintToConsole(idSWFScriptVar *this)
{
  char *v2; // r3
  __int64 v3; // r10
  __int64 v4; // r8
  __int64 v5; // r6
  idSWFScriptVar::swfScriptVarType type; // r11
  int v7; // r3
  char v8; // r11
  bool v9; // zf
  idSWFScriptVar *v10; // r3
  idStr v11; // [sp+50h] [-40h] BYREF

  v2 = idSWFScriptVar::TypeOf(this);
  idLib::Printf(fmt: "Object type: %s\n", v2);
  type = this->type;
  if ( this->type == SWF_VAR_OBJECT )
  {
    idSWFScriptObject::PrintToConsole(this: this->value.object);
  }
  else
  {
    if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (LOBYTE(v3) = 0, type == SWF_VAR_BOOL) )
      LOBYTE(v3) = 1;
    LODWORD(v3) = (unsigned __int8)v3;
    if ( (_BYTE)v3 != 0 )
    {
      v7 = idSWFScriptVar::ToInteger(this);
      idLib::Printf(fmt: "%d\n", v7);
    }
    else
    {
      if ( type == SWF_VAR_STRING || (v9 = type != SWF_VAR_STRINGID, v8 = 0, !v9) )
        v8 = 1;
      if ( v8 != 0 )
      {
        v10 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v11, result: (idStr *)this, a3: v5, a4: v4, a5: v3);
        idLib::Printf(fmt: "%s\n", (const char *)v10->value.i);
        idStr::FreeData(this: &v11);
      }
      else
      {
        idLib::Printf(fmt: "unknown\n");
      }
    }
  }
}


// ========================================================================
// __unwind$219926
// EA  : 0x8278D210
// RVA : 0x0078D210
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

void _unwind_219926()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?AbstractEquals@idSWFScriptVar@@QAA_NABV1@@Z
// EA  : 0x8278D240
// RVA : 0x0078D240
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

int __fastcall idSWFScriptVar::AbstractEquals(idSWFScriptVar *this, idStr *other, __int64 a3, __int64 a4, __int64 a5)
{
  idSWFScriptVar::swfScriptVarType type; // r11
  unsigned __int8 v9; // r11
  idSWFScriptVar *v10; // r29
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  idSWFScriptVar *v14; // r3
  BOOL v15; // r30
  idSWFScriptVar *v16; // r3
  BOOL v17; // r30
  double v18; // fp1
  idSWFScriptVar *v19; // r3
  double v20; // fp1
  idSWFScriptVar *v21; // r3
  BOOL v22; // r30
  idStr v23; // [sp+50h] [-C0h] BYREF
  idStr v24; // [sp+70h] [-A0h] BYREF
  idStr v25; // [sp+90h] [-80h] BYREF
  idStr v26; // [sp+B0h] [-60h] BYREF
  idStr v27[2]; // [sp+D0h] [-40h] BYREF

  type = this->type;
  LODWORD(a5) = other->len;
  if ( this->type != other->len )
  {
    if ( (unsigned int)type > SWF_VAR_OBJECT )
      return 0;
    switch ( type )
    {
      case SWF_VAR_STRING:
        if ( (unsigned int)a5 > 8 || (_DWORD)a5 == 1 )
          return 0;
        switch ( (_DWORD)a5 )
        {
          case 2:
            goto LABEL_40;
          case 3:
          case 4:
            return 0;
          case 5:
            return (_cntlzw(HIBYTE(other->data) - (unsigned __int8)idSWFScriptVar::ToBool(this)) & 0x20) != 0;
          case 6:
            return (_cntlzw((unsigned int)&other->data[-idSWFScriptVar::ToInteger(this)]) & 0x20) != 0;
          default:
            break;
        }
        if ( (_DWORD)a5 != 7 )
        {
          if ( (_DWORD)a5 != 0 )
          {
            v19 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v25, result: other, a3, a4, a5);
            v17 = (_cntlzw(idStr::Cmp(s1: *(const char **)(this->value.i + 4), s2: (const char *)v19->value.i)) & 0x20) != 0;
            idStr::FreeData(this: &v25);
          }
          else
          {
            v16 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v23, result: other, a3, a4, a5);
            v17 = (_cntlzw(idStr::Cmp(s1: *(const char **)(this->value.i + 4), s2: (const char *)v16->value.i)) & 0x20) != 0;
            idStr::FreeData(this: &v23);
          }
          return v17;
        }
        break;
      case SWF_VAR_FLOAT:
        v20 = idSWFScriptVar::ToFloat(
                this: (idSWFScriptVar *)other,
                a2: (int)other,
                a3: SHIDWORD(a3),
                a4: a3,
                a5: SHIDWORD(a4),
                a6: a4,
                a7: a5);
        v9 = 1;
        if ( v20 == this->value.f )
          return v9;
        return 0;
      case SWF_VAR_NULL:
        return (_cntlzw(a5 - 4) & 0x20) != 0;
      case SWF_VAR_UNDEF:
        return (_cntlzw(a5 - 3) & 0x20) != 0;
      case SWF_VAR_BOOL:
        return (_cntlzw(this->value.b - (unsigned __int8)idSWFScriptVar::ToBool(this: (idSWFScriptVar *)other)) & 0x20) != 0;
      case SWF_VAR_INTEGER:
        return (_cntlzw(this->value.i - idSWFScriptVar::ToInteger(this: (idSWFScriptVar *)other)) & 0x20) != 0;
      case SWF_VAR_FUNCTION:
LABEL_57:
        break;
      case SWF_VAR_STRINGID:
        v10 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v26, result: other, a3, a4, a5);
        v14 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v24, result: (idStr *)this, a3: v13, a4: v12, a5: v11);
        v15 = (_cntlzw(idStr::Cmp(s1: (const char *)v14->value.i, s2: (const char *)v10->value.i)) & 0x20) != 0;
        idStr::FreeData(this: &v24);
        idStr::FreeData(this: &v26);
        return v15;
      default:
        if ( (unsigned int)(a5 - 1) <= 5 )
        {
          if ( (_DWORD)a5 != 2 )
          {
            if ( (_DWORD)a5 == 3 || (_DWORD)a5 == 4 )
              return 0;
            if ( (_DWORD)a5 != 5 )
            {
              if ( (_DWORD)a5 == 1 )
              {
                v21 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v27, result: (idStr *)this, a3, a4, a5);
                v22 = (_cntlzw(idStr::Cmp(s1: (const char *)v21->value.i, s2: *((const char **)other->data + 1))) & 0x20) != 0;
                idStr::FreeData(this: v27);
                return v22;
              }
              return (_cntlzw((unsigned int)&other->data[-idSWFScriptVar::ToInteger(this)]) & 0x20) != 0;
            }
            return (_cntlzw(HIBYTE(other->data) - (unsigned __int8)idSWFScriptVar::ToBool(this)) & 0x20) != 0;
          }
LABEL_40:
          v18 = idSWFScriptVar::ToFloat(
                  this,
                  a2: (int)other,
                  a3: SHIDWORD(a3),
                  a4: a3,
                  a5: SHIDWORD(a4),
                  a6: a4,
                  a7: a5);
          v9 = 1;
          if ( v18 == *(float *)&other->data )
            return v9;
          return 0;
        }
        goto LABEL_57;
    }
    return 0;
  }
  if ( (unsigned int)type > SWF_VAR_OBJECT )
    return 0;
  switch ( type )
  {
    case SWF_VAR_STRING:
      return (_cntlzw(idStr::Cmp(s1: *(const char **)(this->value.i + 4), s2: *((const char **)other->data + 1))) & 0x20) != 0;
    case SWF_VAR_FLOAT:
      return this->value.f == *(float *)&other->data;
    case SWF_VAR_NULL:
    case SWF_VAR_UNDEF:
      return 1;
    case SWF_VAR_BOOL:
      return (_cntlzw(HIBYTE(other->data) - this->value.b) & 0x20) != 0;
    default:
      break;
  }
  return (_cntlzw((unsigned int)&other->data[-this->value.i]) & 0x20) != 0;
}


// ========================================================================
// __unwind$219989
// EA  : 0x8278D568
// RVA : 0x0078D568
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

void _unwind_219989()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 176));
}


// ========================================================================
// __unwind$219990
// EA  : 0x8278D590
// RVA : 0x0078D590
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

void _unwind_219990()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 112));
}


// ========================================================================
// __unwind$219991
// EA  : 0x8278D5B8
// RVA : 0x0078D5B8
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

void _unwind_219991()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$219992
// EA  : 0x8278D5E0
// RVA : 0x0078D5E0
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

void _unwind_219992()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 144));
}


// ========================================================================
// __unwind$219993
// EA  : 0x8278D608
// RVA : 0x0078D608
// PDB : w:\tech5\engine\guis\swf\swf_scriptvar.cpp
// ========================================================================

void _unwind_219993()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 208));
}

