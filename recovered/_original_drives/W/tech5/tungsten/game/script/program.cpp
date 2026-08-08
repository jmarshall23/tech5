
// ========================================================================
// ?Inherits@idTypeDef@@QBA_NPBV1@@Z
// EA  : 0x82E99EB0
// RVA : 0x00E99EB0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

int __fastcall idTypeDef::Inherits(idTypeDef *this, const idTypeDef *basetype)
{
  idTypeDef *auxType; // r11

  if ( this->type == ev_object )
  {
    if ( this == basetype )
      return 1;
    auxType = this->auxType;
    if ( auxType != nullptr )
    {
      while ( auxType != basetype )
      {
        auxType = auxType->auxType;
        if ( auxType == nullptr )
          return 0;
      }
      return 1;
    }
  }
  return 0;
}


// ========================================================================
// ?SetName@idTypeDef@@QAAXPBD@Z
// EA  : 0x82E99EF8
// RVA : 0x00E99EF8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idTypeDef::SetName(idTypeDef *this, const char *newname)
{
  idStr::operator=(this: &this->name, text: newname);
}


// ========================================================================
// ?RemoveDef@idVarDefName@@QAAXPAVidVarDef@@@Z
// EA  : 0x82E99F00
// RVA : 0x00E99F00
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idVarDefName::RemoveDef(idVarDefName *this, idVarDef *def)
{
  idVarDef *defs; // r11
  idVarDef **p_next; // r11
  idVarDef *v4; // r10

  defs = this->defs;
  if ( defs == def )
  {
    this->defs = def->next;
    def->next = nullptr;
    def->name = nullptr;
  }
  else
  {
    p_next = &defs->next;
    if ( *p_next != nullptr )
    {
      while ( 1 )
      {
        v4 = *p_next;
        if ( *p_next == def )
          break;
        p_next = &v4->next;
        if ( v4->next == nullptr )
        {
          def->next = nullptr;
          def->name = nullptr;
          return;
        }
      }
      *p_next = def->next;
    }
    def->next = nullptr;
    def->name = nullptr;
  }
}


// ========================================================================
// ?GetFunction@idScriptFunction@@QBAPBVfunction_t@@XZ
// EA  : 0x82E99F78
// RVA : 0x00E99F78
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

const function_t *__fastcall idScriptFunction::GetFunction(idScriptFunction *this)
{
  return this->function;
}


// ========================================================================
// ?HasObject@idScriptObject@@QBA_NXZ
// EA  : 0x82E99F80
// RVA : 0x00E99F80
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

BOOL __fastcall idScriptObject::HasObject(idScriptObject *this)
{
  return &type_object != this->type;
}


// ========================================================================
// ?MatchesType@idTypeDef@@QBA_NABV1@@Z
// EA  : 0x82E99FA0
// RVA : 0x00E99FA0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

int __fastcall idTypeDef::MatchesType(idTypeDef *this, const idTypeDef *matchtype)
{
  int num; // r7
  int v3; // r10
  int i; // r11

  if ( this == matchtype )
    return 1;
  if ( this->type == matchtype->type && this->auxType == matchtype->auxType )
  {
    num = matchtype->parmTypes.num;
    if ( this->parmTypes.num == num )
    {
      v3 = 0;
      if ( num > 0 )
      {
        for ( i = 0; this->parmTypes.list[i] == matchtype->parmTypes.list[i]; ++i )
        {
          if ( ++v3 >= num )
            return 1;
        }
        return 0;
      }
      return 1;
    }
  }
  return 0;
}


// ========================================================================
// ?MatchesVirtualFunction@idTypeDef@@QBA_NABV1@@Z
// EA  : 0x82E9A020
// RVA : 0x00E9A020
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

int __fastcall idTypeDef::MatchesVirtualFunction(idTypeDef *this, const idTypeDef *matchfunc)
{
  int num; // r7
  int v3; // r11
  idTypeDef *v4; // r11
  idTypeDef *v5; // r10
  char v6; // r11
  idTypeDef *auxType; // r11
  int v8; // r10
  int i; // r11

  if ( this == matchfunc )
    return 1;
  if ( this->type != matchfunc->type )
    return 0;
  if ( this->auxType != matchfunc->auxType )
    return 0;
  num = matchfunc->parmTypes.num;
  v3 = this->parmTypes.num;
  if ( v3 != num )
    return 0;
  if ( v3 <= 0 )
    goto LABEL_14;
  v4 = *this->parmTypes.list;
  v5 = *matchfunc->parmTypes.list;
  if ( v4->type == ev_object )
  {
    if ( v4 == v5 )
    {
LABEL_8:
      v6 = 1;
      goto LABEL_13;
    }
    auxType = v4->auxType;
    if ( auxType != nullptr )
    {
      while ( auxType != v5 )
      {
        auxType = auxType->auxType;
        if ( auxType == nullptr )
          goto LABEL_12;
      }
      goto LABEL_8;
    }
  }
LABEL_12:
  v6 = 0;
LABEL_13:
  if ( v6 != 0 )
  {
LABEL_14:
    v8 = 1;
    if ( num > 1 )
    {
      for ( i = 1; this->parmTypes.list[i] == matchfunc->parmTypes.list[i]; ++i )
      {
        if ( ++v8 >= num )
          return 1;
      }
      return 0;
    }
    return 1;
  }
  return 0;
}


// ========================================================================
// ?SuperClass@idTypeDef@@QBAPAV1@XZ
// EA  : 0x82E9A108
// RVA : 0x00E9A108
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idTypeDef *__fastcall idTypeDef::SuperClass(idTypeDef *this)
{
  _BYTE v2[8]; // [sp+50h] [-10h] BYREF

  if ( this->type != ev_object )
  {
    strncpy(
      dest: idException::error,
      source: "idTypeDef::SuperClass : tried to get superclass of a non-object type",
      count: 0x800u);
    CxxThrowException(pExceptionObject: v2, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  return this->auxType;
}


// ========================================================================
// ?ReturnType@idTypeDef@@QBAPAV1@XZ
// EA  : 0x82E9A168
// RVA : 0x00E9A168
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idTypeDef *__fastcall idTypeDef::ReturnType(idTypeDef *this)
{
  _BYTE v2[8]; // [sp+50h] [-10h] BYREF

  if ( this->type != ev_function )
  {
    strncpy(
      dest: idException::error,
      source: "idTypeDef::ReturnType: tried to get return type on non-function type",
      count: 0x800u);
    CxxThrowException(pExceptionObject: v2, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  return this->auxType;
}


// ========================================================================
// ?FieldType@idTypeDef@@QBAPAV1@XZ
// EA  : 0x82E9A1C8
// RVA : 0x00E9A1C8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idTypeDef *__fastcall idTypeDef::FieldType(idTypeDef *this)
{
  _BYTE v2[8]; // [sp+50h] [-10h] BYREF

  if ( this->type != ev_field )
  {
    strncpy(
      dest: idException::error,
      source: "idTypeDef::FieldType: tried to get field type on non-field type",
      count: 0x800u);
    CxxThrowException(pExceptionObject: v2, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  return this->auxType;
}


// ========================================================================
// ?SetFieldType@idTypeDef@@QAAXPAV1@@Z
// EA  : 0x82E9A228
// RVA : 0x00E9A228
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idTypeDef::SetFieldType(idTypeDef *this, idTypeDef *fieldtype)
{
  _BYTE v2[8]; // [sp+50h] [-10h] BYREF

  if ( this->type != ev_field )
  {
    strncpy(
      dest: idException::error,
      source: "idTypeDef::SetFieldType: tried to set return type on non-function type",
      count: 0x800u);
    CxxThrowException(pExceptionObject: v2, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  this->auxType = fieldtype;
}


// ========================================================================
// ?PointerType@idTypeDef@@QBAPAV1@XZ
// EA  : 0x82E9A288
// RVA : 0x00E9A288
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idTypeDef *__fastcall idTypeDef::PointerType(idTypeDef *this)
{
  _BYTE v2[8]; // [sp+50h] [-10h] BYREF

  if ( this->type != ev_pointer )
  {
    strncpy(
      dest: idException::error,
      source: "idTypeDef::PointerType: tried to get pointer type on non-pointer",
      count: 0x800u);
    CxxThrowException(pExceptionObject: v2, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  return this->auxType;
}


// ========================================================================
// ?SetPointerType@idTypeDef@@QAAXPAV1@@Z
// EA  : 0x82E9A2E8
// RVA : 0x00E9A2E8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idTypeDef::SetPointerType(idTypeDef *this, idTypeDef *pointertype)
{
  _BYTE v2[8]; // [sp+50h] [-10h] BYREF

  if ( this->type != ev_pointer )
  {
    strncpy(
      dest: idException::error,
      source: "idTypeDef::SetPointerType: tried to set type on non-pointer",
      count: 0x800u);
    CxxThrowException(pExceptionObject: v2, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  this->auxType = pointertype;
}


// ========================================================================
// ?GetParmType@idTypeDef@@QBAPAV1@H@Z
// EA  : 0x82E9A348
// RVA : 0x00E9A348
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idTypeDef *__fastcall idTypeDef::GetParmType(idTypeDef *this, int parmNumber)
{
  return this->parmTypes.list[parmNumber];
}


// ========================================================================
// ?GetParmName@idTypeDef@@QBAPBDH@Z
// EA  : 0x82E9A358
// RVA : 0x00E9A358
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

char *__fastcall idTypeDef::GetParmName(idTypeDef *this, int parmNumber)
{
  return this->parmNames.list[parmNumber].data;
}


// ========================================================================
// ?NumFunctions@idTypeDef@@QBAHXZ
// EA  : 0x82E9A370
// RVA : 0x00E9A370
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

XGRAPHICS::_SS_SHADER_STORE *__fastcall idTypeDef::NumFunctions(_DWORD *hSSMDev)
{
  return (XGRAPHICS::_SS_SHADER_STORE *)hSSMDev[21];
}


// ========================================================================
// ?GetFunctionNumber@idTypeDef@@QBAHPBVfunction_t@@@Z
// EA  : 0x82E9A378
// RVA : 0x00E9A378
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

int __fastcall idTypeDef::GetFunctionNumber(idTypeDef *this, const function_t *func)
{
  int num; // r9
  int v3; // r10
  int i; // r11

  num = this->functions.num;
  v3 = 0;
  if ( num <= 0 )
    return -1;
  for ( i = 0; this->functions.list[i] != func; ++i )
  {
    if ( ++v3 >= num )
      return -1;
  }
  return v3;
}


// ========================================================================
// ?GetFunction@idTypeDef@@QBAPBVfunction_t@@H@Z
// EA  : 0x82E9A3C0
// RVA : 0x00E9A3C0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

const function_t *__fastcall idTypeDef::GetFunction(idTypeDef *this, int funcNumber)
{
  return this->functions.list[funcNumber];
}


// ========================================================================
// ?Name@idVarDef@@QBAPBDXZ
// EA  : 0x82E9A3D0
// RVA : 0x00E9A3D0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

char *__fastcall idVarDef::Name(idVarDef *this)
{
  return this->name->name.data;
}


// ========================================================================
// ?SetValue@idVarDef@@QAAXABTeval_s@@_N@Z
// EA  : 0x82E9A3E0
// RVA : 0x00E9A3E0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idVarDef::SetValue(idVarDef *this, const eval_s *_value, __int64 constant, __int64 a4, __int64 a5)
{
  idVarDef::initialized_t v5; // r11
  va *v6; // r3
  int v7; // [sp+8h] [-1068h]
  int v8; // [sp+Ch] [-1064h]
  int v9; // [sp+10h] [-1060h]
  int v10; // [sp+14h] [-105Ch]
  int v11; // [sp+18h] [-1058h]
  int v12; // [sp+1Ch] [-1054h]
  _BYTE v13[16]; // [sp+50h] [-1020h] BYREF
  va v14; // [sp+60h] [-1010h] BYREF

  v5 = initializedConstant;
  if ( BYTE3(constant) == 0 )
    v5 = initializedVariable;
  this->initialized = v5;
  switch ( this->typeDef->type )
  {
    case ev_string:
      idStr::Copynz(dest: this->value.value.cp, src: _value->stringPtr, destsize: 256);
      break;
    case ev_float:
      *this->value.value.fp = _value->_float;
      break;
    case ev_integer:
    case ev_field:
    case ev_pointer:
    case ev_decl:
      *this->value.value.ip = _value->_int;
      break;
    case ev_vector:
      *this->value.value.fp = _value->_float;
      *(float *)(this->value.value.i + 4) = _value->vector[1];
      *(float *)(this->value.value.i + 8) = _value->vector[2];
      break;
    case ev_virtualfunction:
    case ev_jumpoffset:
    case ev_argsize:
      this->value.value.i = _value->_int;
      break;
    default:
      LODWORD(a5) = &unk_82360000;
      HIDWORD(constant) = this->name->name.data;
      v6 = va::va(
             this: &v14,
             fmt: "weird type on '%s'",
             a3: constant,
             a4,
             a5,
             a6: v7,
             a7: v8,
             a8: v9,
             a9: v10,
             a10: v11,
             a11: v12);
      strncpy(dest: idException::error, source: v6->buffer, count: 0x800u);
      CxxThrowException(pExceptionObject: v13, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
      return;
  }
}


// ========================================================================
// ?SetString@idVarDef@@QAAXPBD_N@Z
// EA  : 0x82E9A560
// RVA : 0x00E9A560
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idVarDef::SetString(idVarDef *this, const char *string, bool constant)
{
  idVarDef::initialized_t v3; // r11

  v3 = initializedConstant;
  if ( !constant )
    v3 = initializedVariable;
  this->initialized = v3;
  idStr::Copynz(dest: this->value.value.cp, src: string, destsize: 256);
}


// ========================================================================
// ??0idScriptFunction@@QAA@XZ
// EA  : 0x82E9A588
// RVA : 0x00E9A588
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idScriptFunction *__fastcall idScriptFunction::idScriptFunction(idScriptFunction *this)
{
  char *v1; // r11
  int i; // ctr

  v1 = (char *)this - 16;
  for ( i = 16; i != 0; --i )
  {
    v1[16] = 0;
    v1 += 20;
    *(_DWORD *)v1 = 0;
  }
  this->owner = nullptr;
  this->function = nullptr;
  return this;
}


// ========================================================================
// ?ValidateParms@idScriptFunction@@AAA_NHW4etype_t@@@Z
// EA  : 0x82E9A5B0
// RVA : 0x00E9A5B0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idScriptFunction::ValidateParms(idScriptFunction *this, int argNum, etype_t argType)
{
  const function_t *function; // r9
  const function_t *v4; // r11
  const idTypeDef *type; // r10
  idVarDef *def; // r11
  int num; // r10
  bool v8; // r11
  idVarDef *v9; // r11
  bool v10; // r11
  const idTypeDef *v11; // r11
  bool v12; // xer_ca

  function = this->function;
  if ( function != nullptr )
  {
    v4 = this->function;
    type = v4->type;
    def = v4->def;
    num = type->parmTypes.num;
    v8 = def != nullptr && def->scope->typeDef->type == ev_object;
    if ( argNum < num - v8 )
    {
      v9 = function->def;
      v10 = v9 != nullptr && v9->scope->typeDef->type == ev_object;
      v12 = v10;
      v11 = function->type;
      if ( *(_DWORD *)(*((_DWORD *)&v11->parmTypes.list[1 - !v12] + argNum) + 4) != argType )
        idLib::Error(fmt: "Script ERROR: Type Mismatch calling function %s, for parameter %d", v11->name.data, argNum);
    }
    else
    {
      idLib::Error(
        fmt: "Script ERROR: Attempted to call function %s with too many parameters",
        function->type->name.data);
    }
  }
}


// ========================================================================
// ?SetArg_Entity@idScriptFunction@@QAAXHPAVidEntity@@@Z
// EA  : 0x82E9A6A0
// RVA : 0x00E9A6A0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idScriptFunction::SetArg_Entity(idScriptFunction *this, int argNum, idEntity *ent)
{
  char v6; // r3
  char *v7; // r9
  int v8; // ctr
  float *v9; // r11
  char v10; // [sp+4Ch] [-44h] BYREF
  idEventArg v11[3]; // [sp+50h] [-40h] BYREF

  idScriptFunction::ValidateParms(this, argNum, argType: ev_entity);
  if ( v6 != 0 )
  {
    idEventArg::idEventArg(this: v11, data: ent);
    v7 = &v10;
    v8 = 5;
    v9 = &this->args[argNum].value.q[3];
    do
    {
      v7 += 4;
      *++v9 = *(float *)v7;
      --v8;
    }
    while ( v8 != 0 );
  }
}


// ========================================================================
// ?SetArg_Vec3@idScriptFunction@@QAAXHABVidVec3@@@Z
// EA  : 0x82E9A710
// RVA : 0x00E9A710
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idScriptFunction::SetArg_Vec3(idScriptFunction *this, int argNum, const idVec3 *vec)
{
  char v6; // r3
  double y; // fp13
  double z; // fp12
  int v9; // ctr
  float *v10; // r10
  float *v11; // r11
  float v12[17]; // [sp+4Ch] [-44h] BYREF

  idScriptFunction::ValidateParms(this, argNum, argType: ev_vector);
  if ( v6 != 0 )
  {
    y = vec->y;
    z = vec->z;
    v12[2] = vec->x;
    v12[3] = y;
    v12[4] = z;
    v9 = 5;
    HIBYTE(v12[1]) = 118;
    v10 = v12;
    v11 = &this->args[argNum].value.q[3];
    do
    {
      *++v11 = *++v10;
      --v9;
    }
    while ( v9 != 0 );
  }
}


// ========================================================================
// ?SetArg_Float@idScriptFunction@@QAAXHM@Z
// EA  : 0x82E9A798
// RVA : 0x00E9A798
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idScriptFunction::SetArg_Float(idScriptFunction *this, int argNum, double value)
{
  char v6; // r3
  int v7; // ctr
  float *v8; // r10
  float *v9; // r11
  float v10[9]; // [sp+4Ch] [-44h] BYREF

  idScriptFunction::ValidateParms(this, argNum, argType: ev_float);
  if ( v6 != 0 )
  {
    v10[2] = value;
    v7 = 5;
    HIBYTE(v10[1]) = 102;
    v8 = v10;
    v9 = &this->args[argNum].value.q[3];
    do
    {
      *++v9 = *++v8;
      --v7;
    }
    while ( v7 != 0 );
  }
}


// ========================================================================
// ?SetArg_Int@idScriptFunction@@QAAXHH@Z
// EA  : 0x82E9A830
// RVA : 0x00E9A830
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idScriptFunction::SetArg_Int(idScriptFunction *this, int argNum, int value)
{
  char v6; // r3
  int v7; // ctr
  _DWORD *v8; // r10
  float *v9; // r11
  _BYTE v10[68]; // [sp+4Ch] [-44h] BYREF

  idScriptFunction::ValidateParms(this, argNum, argType: ev_integer);
  if ( v6 != 0 )
  {
    *(_DWORD *)&v10[8] = value;
    v7 = 5;
    v10[4] = 105;
    v8 = v10;
    v9 = &this->args[argNum].value.q[3];
    do
    {
      *++v9 = *(float *)++v8;
      --v7;
    }
    while ( v7 != 0 );
  }
}


// ========================================================================
// ?SetArg_Decl@idScriptFunction@@QAAXHPBVidDecl@@@Z
// EA  : 0x82E9A8A8
// RVA : 0x00E9A8A8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idScriptFunction::SetArg_Decl(idScriptFunction *this, int argNum, const idDecl *decl)
{
  char v6; // r3
  int v7; // ctr
  _DWORD *v8; // r10
  float *v9; // r11
  _BYTE v10[68]; // [sp+4Ch] [-44h] BYREF

  idScriptFunction::ValidateParms(this, argNum, argType: ev_decl);
  if ( v6 != 0 )
  {
    *(_DWORD *)&v10[8] = decl;
    v7 = 5;
    v10[4] = 100;
    v8 = v10;
    v9 = &this->args[argNum].value.q[3];
    do
    {
      *++v9 = *(float *)++v8;
      --v7;
    }
    while ( v7 != 0 );
  }
}


// ========================================================================
// ?CallFunction@idScriptFunction@@QAAXPAVidThread@@_N1@Z
// EA  : 0x82E9A920
// RVA : 0x00E9A920
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idScriptFunction::CallFunction(idScriptFunction *this, idThread *thread, bool defer, bool clearStack)
{
  const function_t *function; // r11
  idScriptFunction *v5; // r30
  idVarDef *def; // r11
  int v10; // r31
  char *v12; // r11
  const function_t **p_function; // r10
  int i; // ctr
  const function_t *v15; // r4
  int v16; // r11
  int num; // r29
  idEventArg *v18; // r10
  idThread *v19; // r3
  idScriptFunction *v20; // r11
  int v21; // ctr
  char v22; // [sp+4Ch] [-64h] BYREF
  idEventArg v23[4]; // [sp+50h] [-60h] BYREF

  function = this->function;
  v5 = this;
  if ( function == nullptr )
    return;
  def = function->def;
  v10 = 1;
  if ( def != nullptr && def->scope->typeDef->type == ev_object )
  {
    idEventArg::idEventArg(this: v23, data: this->owner);
    v12 = &v22;
    p_function = &v5[-1].function;
    for ( i = 5; i != 0; --i )
    {
      v12 += 4;
      *++p_function = *(const function_t **)v12;
    }
    v10 = 0;
  }
  v15 = v5->function;
  v16 = 1;
  num = v15->type->parmTypes.num;
  if ( num + v10 <= 1 )
  {
LABEL_14:
    v5 = (idScriptFunction *)((char *)v5 + 20 * v10);
    idThread::CallFunctionWithParms(this: thread, func: v15, numArgs: num, args: v5->args, clearStack);
    v19 = thread;
    if ( defer )
    {
      idThread::DelayedStart(this: thread, delay: 0);
      goto LABEL_18;
    }
  }
  else
  {
    v18 = &v5->args[1];
    while ( v18->type != 0 )
    {
      ++v16;
      ++v18;
      if ( v16 >= num + v10 )
        goto LABEL_14;
    }
    idLib::Error(
      fmt: "entity '%s' tried to call function '%s' without all the function arguments set",
      v5->owner->name.data,
      v15->name.data);
  }
  idThread::Start(this: v19);
LABEL_18:
  if ( v10 < num )
  {
    v20 = (idScriptFunction *)((char *)v5 - 20);
    v21 = num - v10;
    do
    {
      v20 = (idScriptFunction *)((char *)v20 + 20);
      v20->args[0].type = 0;
      --v21;
    }
    while ( v21 != 0 );
  }
}


// ========================================================================
// ?CallFunction@idScriptFunction@@QAAPAVidThread@@_N@Z
// EA  : 0x82E9AA78
// RVA : 0x00E9AA78
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idThread *__fastcall idScriptFunction::CallFunction(idScriptFunction *this, bool defer)
{
  idThread *v5; // r3
  idThread *v6; // r30

  if ( this->function == nullptr )
    return nullptr;
  v5 = (idThread *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                     size: 0x1B94u,
                     tag: TAG_NEW,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idThread::idThread(this: v5);
  else
    v6 = nullptr;
  idScriptFunction::CallFunction(this, thread: v6, defer, clearStack: true);
  return v6;
}


// ========================================================================
// __unwind$493581_0
// EA  : 0x82E9AB08
// RVA : 0x00E9AB08
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall _unwind_493581_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ??0idScriptObject@@QAA@XZ
// EA  : 0x82E9AB30
// RVA : 0x00E9AB30
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idScriptObject *__fastcall idScriptObject::idScriptObject(idScriptObject *this)
{
  this->__vftable = (idScriptObject_vtbl *)&idScriptObject::`vftable';
  this->type = &type_object;
  this->data = nullptr;
  return this;
}


// ========================================================================
// ?GetTypeName@idScriptObject@@QBAPBDXZ
// EA  : 0x82E9AB58
// RVA : 0x00E9AB58
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

char *__fastcall idScriptObject::GetTypeName(idScriptObject *this)
{
  return this->type->name.data;
}


// ========================================================================
// ?GetVariableOffsetFromName@idScriptObject@@QBAHPBDAAW4etype_t@@@Z
// EA  : 0x82E9AB68
// RVA : 0x00E9AB68
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

int __fastcall idScriptObject::GetVariableOffsetFromName(idScriptObject *this, const char *name, etype_t *etype)
{
  idTypeDef *type; // r11
  idTypeDef *auxType; // r26
  int result; // r3
  int num; // r28
  int v7; // r31
  idStr *list; // r30
  int v9; // r6
  idTypeDef **v10; // r29
  int v11; // r7
  idStr *v12; // r11
  idTypeDef *v13; // r8
  const char *v14; // r10
  char *data; // r11
  int v16; // r9
  int v17; // r9
  bool v18; // zf
  etype_t v19; // r11
  idTypeDef *v20; // r10
  char v21; // r11
  idTypeDef *v22; // r11
  _BYTE v23[80]; // [sp+50h] [-50h] BYREF

  *etype = ev_error;
  type = this->type;
  if ( type == nullptr )
    return -1;
  while ( 1 )
  {
    if ( type == &type_object )
      return -1;
    if ( type->type != ev_object )
    {
      strncpy(
        dest: idException::error,
        source: "idTypeDef::SuperClass : tried to get superclass of a non-object type",
        count: 0x800u);
      CxxThrowException(pExceptionObject: v23, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
    }
    auxType = type->auxType;
    result = auxType == &type_object ? 0 : auxType->size;
    num = type->parmTypes.num;
    v7 = 0;
    if ( num > 0 )
      break;
LABEL_25:
    type = auxType;
    if ( auxType == nullptr )
      return -1;
  }
  list = type->parmNames.list;
  v9 = 0;
  v10 = type->parmTypes.list;
  v11 = 0;
  v12 = list;
  while ( 1 )
  {
    v13 = v10[v11];
    v14 = name;
    data = v12->data;
    do
    {
      v16 = (unsigned __int8)*data;
      v18 = v16 == 0;
      v17 = v16 - *(unsigned __int8 *)v14;
      if ( v18 )
        break;
      ++data;
      ++v14;
    }
    while ( v17 == 0 );
    v19 = v13->type;
    if ( v17 == 0 )
      break;
    if ( v19 != ev_field )
    {
      strncpy(
        dest: idException::error,
        source: "idTypeDef::FieldType: tried to get field type on non-field type",
        count: 0x800u);
      CxxThrowException(pExceptionObject: v23, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
    }
    v20 = v13->auxType;
    if ( v20->type != ev_object )
    {
LABEL_20:
      v21 = 0;
      goto LABEL_21;
    }
    if ( v20 != &type_object )
    {
      v22 = v20->auxType;
      if ( v22 == nullptr )
        goto LABEL_20;
      while ( v22 != &type_object )
      {
        v22 = v22->auxType;
        if ( v22 == nullptr )
          goto LABEL_20;
      }
    }
    v21 = 1;
LABEL_21:
    if ( v21 != 0 )
      result += type_object.size;
    else
      result += v20->size;
    ++v7;
    ++v9;
    ++v11;
    v12 = &list[v9];
    if ( v7 >= num )
      goto LABEL_25;
  }
  if ( v19 != ev_field )
  {
    strncpy(
      dest: idException::error,
      source: "idTypeDef::FieldType: tried to get field type on non-field type",
      count: 0x800u);
    CxxThrowException(pExceptionObject: v23, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  *etype = v13->auxType->type;
  return result;
}


// ========================================================================
// ?FindType@idProgram@@QAAPAVidTypeDef@@PBD@Z
// EA  : 0x82E9AD68
// RVA : 0x00E9AD68
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idTypeDef *__fastcall idProgram::FindType(idProgram *this, const char *name)
{
  int v3; // r29
  int v4; // r31
  idList<idTypeDef *,58> *p_types; // r28
  idTypeDef *v6; // r30

  v3 = this->types.num - 1;
  if ( v3 < 0 )
    return nullptr;
  v4 = v3;
  p_types = &this->types;
  while ( 1 )
  {
    v6 = p_types->list[v4];
    if ( idStr::Cmp(s1: v6->name.data, s2: name) == 0 )
      break;
    --v3;
    --v4;
    if ( v3 < 0 )
      return nullptr;
  }
  return v6;
}


// ========================================================================
// ?GetDefList@idProgram@@QBAABV?$idList@PAVidVarDef@@$04@@XZ
// EA  : 0x82E9ADD8
// RVA : 0x00E9ADD8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idList<idVarDef *,58> *__fastcall idProgram::GetDefList(idProgram *this)
{
  return &this->varDefs;
}


// ========================================================================
// ?ReturnList@idProgram@@QAAXPAVidScriptList@@@Z
// EA  : 0x82E9AE60
// RVA : 0x00E9AE60
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::ReturnList(idProgram *this, idScriptList *list)
{
  int *ip; // r9

  ip = this->returnDef->value.value.ip;
  if ( list != nullptr )
    *ip = list->id;
  else
    *ip = 0;
}


// ========================================================================
// ?DeclForId@idProgram@@QBAPBVidDecl@@V?$idIndex@HW4invalidScriptDecl_t@@@@@Z
// EA  : 0x82E9AE88
// RVA : 0x00E9AE88
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

const idDecl *__fastcall idProgram::DeclForId(idProgram *this, int declId)
{
  if ( declId >= 0 )
    return this->referencedDecls.list[declId];
  else
    return nullptr;
}


// ========================================================================
// ?Allocated@idTypeDef@@QBAIXZ
// EA  : 0x82E9AEB0
// RVA : 0x00E9AEB0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

int __fastcall idTypeDef::Allocated(idTypeDef *this)
{
  int v1; // r8
  int v2; // r4
  int v3; // r6
  int num; // r5
  int v5; // r7
  int v6; // r30
  idStr *list; // r31
  int v8; // r9
  idStr *v9; // r11
  int v10; // r10
  idStr *v11; // r11
  int v12; // r11
  idStr *v13; // r11

  if ( this->name.data == this->name.baseBuffer )
    v1 = 0;
  else
    v1 = this->name.allocedAndFlag & 0x7FFFFFFF;
  v2 = 0;
  v3 = 0;
  num = this->parmTypes.num;
  v5 = 0;
  v6 = 4 * (8 * this->parmNames.size + this->functions.size + this->parmTypes.size) + v1;
  if ( num >= 2 )
  {
    list = this->parmNames.list;
    v8 = 0;
    do
    {
      v9 = &list[v8];
      if ( list[v8].data == list[v8].baseBuffer )
        v10 = 0;
      else
        v10 = v9->allocedAndFlag & 0x7FFFFFFF;
      v11 = v9 + 1;
      v2 += v10;
      if ( v11->data == v11->baseBuffer )
        v12 = 0;
      else
        v12 = v11->allocedAndFlag & 0x7FFFFFFF;
      v5 += 2;
      v3 += v12;
      v8 += 2;
    }
    while ( v5 < num - 1 );
  }
  if ( v5 >= num )
    return v3 + v2 + v6;
  v13 = &this->parmNames.list[v5];
  if ( v13->data == v13->baseBuffer )
    return v3 + v2 + v6;
  else
    return v3 + v2 + (v13->allocedAndFlag & 0x7FFFFFFF) + v6;
}


// ========================================================================
// ?GlobalName@idVarDef@@QBA?AVidStr@@XZ
// EA  : 0x82E9AFE8
// RVA : 0x00E9AFE8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idVarDef *__fastcall idVarDef::GlobalName(idVarDef *this, idStr *result)
{
  idStr *allocedAndFlag; // r4
  idStr *v5; // r3
  __int64 v6; // r10
  __int64 v7; // r6
  __int64 v8; // r8
  va *v9; // r3
  int v11; // [sp+8h] [-1098h]
  int v12; // [sp+Ch] [-1094h]
  int v13; // [sp+10h] [-1090h]
  int v14; // [sp+14h] [-108Ch]
  int v15; // [sp+18h] [-1088h]
  int v16; // [sp+1Ch] [-1084h]
  idStr v17; // [sp+60h] [-1040h] BYREF
  va v18; // [sp+80h] [-1020h] BYREF

  allocedAndFlag = (idStr *)result->allocedAndFlag;
  if ( allocedAndFlag == (idStr *)&def_namespace )
  {
    idStr::idStr((idStr *)this, text: *(const char **)(*(_DWORD *)&result->baseBuffer[12] + 4));
  }
  else
  {
    v5 = idVarDef::GlobalName(this: (idVarDef *)&v17, result: allocedAndFlag);
    LODWORD(v6) = &unk_82360000;
    HIDWORD(v7) = v5->data;
    LODWORD(v7) = *(_DWORD *)(*(_DWORD *)&result->baseBuffer[12] + 4);
    v9 = va::va(
           this: &v18,
           fmt: "%s::%s",
           a3: v7,
           a4: v8,
           a5: v6,
           a6: v11,
           a7: v12,
           a8: v13,
           a9: v14,
           a10: v15,
           a11: v16);
    idStr::idStr((idStr *)this, text: v9);
    idStr::FreeData(this: &v17);
  }
  return this;
}


// ========================================================================
// __unwind$495397
// EA  : 0x82E9B078
// RVA : 0x00E9B078
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_495397()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4256 + 96));
}


// ========================================================================
// ?PrintInfo@idVarDef@@QBAXPAVidFile@@H@Z
// EA  : 0x82E9B0A8
// RVA : 0x00E9B0A8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idVarDef::PrintInfo(idVarDef *this, idFile *file, int instructionPointer)
{
  idTypeDef *typeDef; // r11
  etype_t type; // r27
  idVarDef *v7; // r3
  idVarDef *v8; // r3
  int i; // r5
  const char *v10; // r4
  idVarDef::initialized_t initialized; // r11
  _BYTE *v12; // r10
  int v13; // r11
  _BYTE *v14; // r26
  int v15; // r25
  const char *v17; // r4
  idAngles *cp; // r3
  idFile_vtbl *v19; // r29
  const char *v20; // r5
  idStr v21; // [sp+50h] [-90h] BYREF
  idStr v22[3]; // [sp+70h] [-70h] BYREF

  if ( this->initialized == initializedConstant )
    file->Printf(this: file, a2: "const ");
  typeDef = this->typeDef;
  type = typeDef->type;
  if ( (unsigned int)(type - 9) > 6 )
    goto LABEL_16;
  if ( type == ev_field )
  {
    i = this->value.value.i;
    v10 = "field %d";
    goto LABEL_47;
  }
  if ( type != ev_function )
  {
    if ( type != ev_virtualfunction && type != ev_pointer && type != ev_object )
    {
      if ( type == ev_jumpoffset )
      {
        file->Printf(this: file, a2: "address %d [%s(%d)]");
        return;
      }
      i = this->value.value.i;
      v10 = "args %d";
      goto LABEL_47;
    }
LABEL_16:
    file->Printf(this: file, a2: "%s ", typeDef->name.data);
    initialized = this->initialized;
    if ( initialized == initializedConstant )
    {
      if ( (unsigned int)(type - 3) > 8 )
        goto LABEL_43;
      switch ( type )
      {
        case ev_float:
          file->Printf(
            this: file,
            a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(*this->value.value.fp)),
            COERCE_UNSIGNED_INT64(*this->value.value.fp));
          return;
        case ev_integer:
          goto LABEL_43;
        case ev_vector:
          cp = (idAngles *)this->value.value.cp;
          v19 = file->__vftable;
          v20 = idVec3::ToString(this: cp, precision: 2);
          v19->Printf(this: file, a2: "'%s'", v20);
          return;
        case ev_quat:
        case ev_entity:
LABEL_43:
          file->Printf(this: file, a2: "%d", *this->value.value.ip);
          return;
        case ev_string:
          file->Printf(this: file, a2: "\"");
          v12 = this->value.value.cp;
          v13 = 0;
          if ( *v12 != 0 )
          {
            do
              ++v13;
            while ( v12[v13] != 0 );
          }
          v14 = this->value.value.cp;
          if ( v13 <= 0 )
          {
LABEL_41:
            file->Printf(this: file, a2: "\"");
            return;
          }
          v15 = v13;
          while ( (char)*v14 < 32 || (char)*v14 > 126 )
          {
            if ( *v14 != 10 )
            {
              v17 = "\\x%.2x";
              goto LABEL_39;
            }
            file->Printf(this: file, a2: "\\n");
LABEL_40:
            --v15;
            ++v14;
            if ( v15 == 0 )
              goto LABEL_41;
          }
          v17 = "%c";
LABEL_39:
          file->Printf(this: file, a2: v17);
          goto LABEL_40;
        default:
          break;
      }
      i = this->value.value.i;
      v10 = "vtable[ %d ]";
    }
    else if ( initialized == stackVariable )
    {
      i = this->value.value.i;
      v10 = "stack[%d]";
    }
    else
    {
      i = this->num;
      v10 = "global[%d]";
    }
LABEL_47:
    file->Printf(this: file, a2: v10, i);
    return;
  }
  if ( *this->value.value.ip != 0 )
  {
    v7 = idVarDef::GlobalName(this: (idVarDef *)&v21, result: (idStr *)this);
    file->Printf(this: file, a2: "event %s", v7->value.value.i);
    idStr::FreeData(this: &v21);
  }
  else
  {
    v8 = idVarDef::GlobalName(this: (idVarDef *)v22, result: (idStr *)this);
    file->Printf(this: file, a2: "function %s", v8->value.value.i);
    idStr::FreeData(this: v22);
  }
}


// ========================================================================
// __unwind$495461
// EA  : 0x82E9B468
// RVA : 0x00E9B468
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_495461()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$495462
// EA  : 0x82E9B490
// RVA : 0x00E9B490
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_495462()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?Free@idScriptObject@@QAAXXZ
// EA  : 0x82E9B4B8
// RVA : 0x00E9B4B8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idScriptObject::Free(idScriptObject *this)
{
  int v2; // r28
  int v3; // r30
  int v4; // r29
  idTypeDef *type; // r11
  idTypeDef *v6; // r10
  int VariableOffsetFromName; // r10
  char v8; // r11
  idScriptList *ScriptList; // r3
  unsigned __int8 *data; // r4
  _BYTE v11[4]; // [sp+50h] [-40h] BYREF
  int v12; // [sp+54h] [-3Ch] BYREF

  v2 = 0;
  if ( this->type->parmTypes.num > 0 )
  {
    v3 = 0;
    v4 = 0;
    do
    {
      type = this->type;
      v6 = type->parmTypes.list[v4];
      if ( v6->type != ev_field )
      {
        strncpy(
          dest: idException::error,
          source: "idTypeDef::FieldType: tried to get field type on non-field type",
          count: 0x800u);
        CxxThrowException(pExceptionObject: v11, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
      }
      if ( v6->auxType == &type_list )
      {
        VariableOffsetFromName = idScriptObject::GetVariableOffsetFromName(
                                   this,
                                   name: type->parmNames.list[v3].data,
                                   etype: (etype_t *)&v12);
        if ( VariableOffsetFromName < 0 || (v8 = 1, v12 != 16) )
          v8 = 0;
        if ( v8 != 0 )
        {
          ScriptList = idGameLocal::GetScriptList(
                         this: gameLocal,
                         idToGet: *(_DWORD *)&this->data[VariableOffsetFromName]);
          if ( ScriptList != nullptr )
            ((void (__fastcall *)(idScriptList *, int))ScriptList->dtr_idClass)(a1: ScriptList, a2: 1);
        }
      }
      ++v2;
      ++v4;
      ++v3;
    }
    while ( v2 < this->type->parmTypes.num );
  }
  data = this->data;
  if ( data != nullptr )
    idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
  this->data = nullptr;
  this->type = &type_object;
}


// ========================================================================
// ?SetType@idScriptObject@@QAA_NPBD_N@Z
// EA  : 0x82E9B608
// RVA : 0x00E9B608
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

int __fastcall idScriptObject::SetType(idScriptObject *this, const char *typeName, bool clear)
{
  idTypeDef *Type; // r3
  idTypeDef *v7; // r11
  idTypeDef *v8; // r30
  char v9; // r11
  idTypeDef *auxType; // r11
  unsigned __int8 *data; // r3
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  va *v16; // r3
  int v17; // r26
  int v18; // r29
  int v19; // r27
  idTypeDef *v20; // r11
  idScriptList *ScriptList; // r31
  int VariableOffsetFromName; // r3
  char v23; // r11
  __int64 v24; // r10
  __int64 v25; // r8
  __int64 v26; // r6
  va *v27; // r3
  int v28; // [sp+8h] [-10D8h]
  int v29; // [sp+Ch] [-10D4h]
  int v30; // [sp+10h] [-10D0h]
  int v31; // [sp+14h] [-10CCh]
  int v32; // [sp+18h] [-10C8h]
  int v33; // [sp+1Ch] [-10C4h]
  char v34[4]; // [sp+50h] [-1090h] BYREF
  etype_t v35[3]; // [sp+54h] [-108Ch] BYREF
  va v36; // [sp+60h] [-1080h] BYREF

  if ( typeName == nullptr || *typeName == 0 || idStr::Cmp(s1: typeName, s2: "object") == 0 )
  {
    idScriptObject::Free(this);
    return 1;
  }
  Type = idProgram::FindType(this: &gameLocal->program, name: typeName);
  v7 = this->type;
  v8 = Type;
  if ( Type == v7 )
  {
    if ( !clear || v7 == &type_object )
      goto LABEL_23;
    data = this->data;
    goto LABEL_21;
  }
  idScriptObject::Free(this);
  if ( v8 == nullptr )
    return 0;
  if ( v8->type == ev_object )
  {
    if ( v8 == &type_object )
    {
LABEL_8:
      v9 = 1;
      goto LABEL_13;
    }
    auxType = v8->auxType;
    if ( auxType != nullptr )
    {
      while ( auxType != &type_object )
      {
        auxType = auxType->auxType;
        if ( auxType == nullptr )
          goto LABEL_12;
      }
      goto LABEL_8;
    }
  }
LABEL_12:
  v9 = 0;
LABEL_13:
  if ( v9 == 0 )
  {
    idLib::Warning(
      fmt: "idScriptObject::SetType: Can't create object of type '%s'.  Must be an object type.",
      v8->name.data);
    return 0;
  }
  this->type = v8;
  data = (unsigned __int8 *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\tungsten\\game\\script\\Program.cpp(1269) : TAG_SCRIPT",
                              size: v8->size,
                              tag: TAG_SCRIPT,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  v7 = this->type;
  this->data = data;
  if ( v7 != &type_object )
  {
LABEL_21:
    if ( data != nullptr )
      memset(Dst: data, Val: 0, Size: v7->size);
  }
LABEL_23:
  if ( cvarSystem->GetCVarInteger(this: cvarSystem, a2: "script_debug", a3: 0) == 1 )
  {
    HIDWORD(v15) = typeName;
    v16 = va::va(
            this: &v36,
            fmt: "=== Initializing %s vars ===\n",
            a3: v15,
            a4: v14,
            a5: v13,
            a6: v28,
            a7: v29,
            a8: v30,
            a9: v31,
            a10: v32,
            a11: v33);
    console->Print(this: console, a2: (const char *)v16);
  }
  for ( ; v8 != nullptr; v8 = v8->auxType )
  {
    v17 = 0;
    if ( v8->parmTypes.num > 0 )
    {
      v18 = 0;
      v19 = 0;
      do
      {
        v20 = v8->parmTypes.list[v19];
        if ( v20->type != ev_field )
        {
          strncpy(
            dest: idException::error,
            source: "idTypeDef::FieldType: tried to get field type on non-field type",
            count: 0x800u);
          CxxThrowException(pExceptionObject: v34, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
        }
        if ( v20->auxType == &type_list )
        {
          ScriptList = idGameLocal::CreateScriptList(this: gameLocal);
          ScriptList->isMember = true;
          VariableOffsetFromName = idScriptObject::GetVariableOffsetFromName(
                                     this,
                                     name: v8->parmNames.list[v18].data,
                                     etype: v35);
          if ( VariableOffsetFromName < 0 || (v23 = 1, v35[0] != ev_list) )
            v23 = 0;
          if ( v23 == 0 )
          {
            idLib::Error(
              fmt: "Type mismatch when initializing list %s in script object %s",
              v8->parmNames.list[v17].data,
              typeName);
_LN120_0:
            strncpy(
              dest: idException::error,
              source: "idTypeDef::SuperClass : tried to get superclass of a non-object type",
              count: 0x800u);
            CxxThrowException(pExceptionObject: v34, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
          }
          *(_DWORD *)&this->data[VariableOffsetFromName] = ScriptList->id;
          if ( cvarSystem->GetCVarInteger(this: cvarSystem, a2: "script_debug", a3: 0) == 1 )
          {
            LODWORD(v26) = ScriptList->id;
            HIDWORD(v26) = v8->parmNames.list[v18].data;
            v27 = va::va(
                    this: &v36,
                    fmt: "Script: Init List %s to %d\n",
                    a3: v26,
                    a4: v25,
                    a5: v24,
                    a6: v28,
                    a7: v29,
                    a8: v30,
                    a9: v31,
                    a10: v32,
                    a11: v33);
            console->Print(this: console, a2: (const char *)v27);
          }
        }
        ++v17;
        ++v19;
        ++v18;
      }
      while ( v17 < v8->parmTypes.num );
    }
    if ( v8->type != ev_object )
      goto _LN120_0;
  }
  if ( cvarSystem->GetCVarInteger(this: cvarSystem, a2: "script_debug", a3: 0) == 1 )
  {
    console->Print(this: console, a2: "==========\n");
    return 1;
  }
  return 1;
}


// ========================================================================
// ?WriteType@idScriptObject@@ABAXAAVidTypeInfoFile@@PBVidTypeDef@@H_N@Z
// EA  : 0x82E9B9F8
// RVA : 0x00E9B9F8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idScriptObject::WriteType(
        idScriptObject *this,
        idTypeInfoFile *file,
        idTypeDef *t,
        int offset,
        bool writeEditables)
{
  const idTypeDef *v10; // r3
  int v11; // r28
  BOOL v12; // r16
  int v13; // r26
  int i; // r23
  idTypeDef *v15; // r30
  const float *v17; // r3
  const char *v18; // r3
  char *UnresolvedEntityName; // r3
  char *data; // r10
  idTypeDef *v21; // r10
  char v22; // r11
  idTypeDef *v23; // r11
  int size; // r11
  int v25; // [sp+50h] [-C0h] BYREF
  idTypeDef *auxType; // [sp+54h] [-BCh]
  idStr v27[5]; // [sp+60h] [-B0h] BYREF

  if ( t->type != ev_object )
  {
    strncpy(
      dest: idException::error,
      source: "idTypeDef::SuperClass : tried to get superclass of a non-object type",
      count: 0x800u);
    CxxThrowException(pExceptionObject: &v25, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  auxType = t->auxType;
  if ( auxType != nullptr && auxType != &type_object )
  {
    v10 = idTypeDef::SuperClass(this: t);
    idScriptObject::WriteType(this, file, t: v10, offset, writeEditables: false);
    offset += idTypeDef::SuperClass(this: t)->size;
  }
  v11 = 0;
  if ( t->parmTypes.num > 0 )
  {
    v12 = writeEditables;
    v13 = 0;
    for ( i = 0; ; ++i )
    {
      v15 = t->parmTypes.list[i];
      if ( !v12 )
      {
        if ( t->parmEditableFlags.num <= v11 || !t->parmEditableFlags.list[v11] )
          goto LABEL_40;
        if ( v15->type != ev_field )
        {
          strncpy(
            dest: idException::error,
            source: "idTypeDef::FieldType: tried to get field type on non-field type",
            count: 0x800u);
          CxxThrowException(pExceptionObject: &v25, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
        }
        if ( v15->auxType->type == ev_list )
          goto LABEL_40;
      }
      v27[0].allocedAndFlag = 20;
      v27[0].len = 0;
      v27[0].data = v27[0].baseBuffer;
      v27[0].baseBuffer[0] = 0;
      v17 = (const float *)&this->data[offset];
      if ( v15->type != ev_field )
      {
        strncpy(
          dest: idException::error,
          source: "idTypeDef::FieldType: tried to get field type on non-field type",
          count: 0x800u);
        CxxThrowException(pExceptionObject: &v25, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
      }
      switch ( v15->auxType->type )
      {
        case ev_string:
          goto LABEL_18;
        case ev_float:
          v17 = (const float *)idStr::FloatArrayToString(array: v17, length: 1, precision: 8);
LABEL_18:
          idStr::operator=(this: v27, text: (const char *)v17);
          break;
        case ev_integer:
        case ev_list:
          goto LABEL_21;
        case ev_vector:
          v18 = idStr::FloatArrayToString(array: v17, length: 3, precision: 8);
          idStr::operator=(this: v27, text: v18);
          break;
        case ev_entity:
        case ev_object:
          if ( file->settings.resolveEntityPointers )
          {
LABEL_21:
            idStr::Format(this: v27, fmt: "%i", *(_DWORD *)v17);
          }
          else
          {
            UnresolvedEntityName = idGameState::GetUnresolvedEntityName(ptr: (const idEntityPtr<idEntity> *)v17);
            idStr::operator=(this: v27, text: UnresolvedEntityName);
          }
          break;
        default:
          idStr::Format(this: v27, fmt: "0x%08x", *(_DWORD *)v17);
          break;
      }
      if ( v15->type != ev_field )
      {
        strncpy(
          dest: idException::error,
          source: "idTypeDef::FieldType: tried to get field type on non-field type",
          count: 0x800u);
        CxxThrowException(pExceptionObject: &v25, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
      }
      idTypeInfoFile::WriteType(
        this: file,
        type: v15->auxType->name.data,
        ops: &byte_8200D768,
        name: t->parmNames.list[v13].data);
      idTypeInfoFile::WriteStr(this: file, s: v27[0].data);
      auxType = (idTypeDef *)t->parmComments.num;
      if ( (int)auxType > v11 )
      {
        data = t->parmComments.list[v13].data;
        if ( data != nullptr )
          idTypeInfoFile::WriteComment(
            this: file,
            comment: (const char *)(((__PAIR64__((unsigned int)auxType >> 31, v11)
                           - __PAIR64__((unsigned int)v11 >> 31, (unsigned int)auxType)) >> 32)
                         & (unsigned int)data));
      }
      if ( v15->type != ev_field )
      {
        strncpy(
          dest: idException::error,
          source: "idTypeDef::FieldType: tried to get field type on non-field type",
          count: 0x800u);
        CxxThrowException(pExceptionObject: &v25, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
      }
      v21 = v15->auxType;
      if ( v21->type != ev_object )
        break;
      if ( v21 != &type_object )
      {
        v23 = v21->auxType;
        if ( v23 == nullptr )
          break;
        while ( v23 != &type_object )
        {
          v23 = v23->auxType;
          if ( v23 == nullptr )
            goto LABEL_35;
        }
      }
      v22 = 1;
LABEL_36:
      if ( v22 != 0 )
      {
        size = type_object.size;
      }
      else
      {
        size = v21->size;
        auxType = v15->auxType;
      }
      offset += size;
      idStr::FreeData(this: v27);
LABEL_40:
      ++v11;
      ++v13;
      if ( v11 >= t->parmTypes.num )
        return;
    }
LABEL_35:
    v22 = 0;
    goto LABEL_36;
  }
}


// ========================================================================
// $LN209_0
// EA  : 0x82E9BE0C
// RVA : 0x00E9BE0C
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _LN209_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// ?Write@idScriptObject@@QBAXAAVidTypeInfoFile@@_N@Z
// EA  : 0x82E9BE38
// RVA : 0x00E9BE38
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idScriptObject::Write(idScriptObject *this, idTypeInfoFile *file, bool writeEditables)
{
  idTypeInfoFile::WriteType(this: file, type: "idTypeDef", ops: "*", name: "type");
  idTypeInfoFile::WriteStr(this: file, s: this->type->name.data);
  idScriptObject::WriteType(this, file, t: this->type, offset: 0, writeEditables);
}


// ========================================================================
// ?GetDefList@idProgram@@QBAPAVidVarDef@@PBD@Z
// EA  : 0x82E9BEA0
// RVA : 0x00E9BEA0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idVarDef *__fastcall idProgram::GetDefList(idProgram *this, const char *name)
{
  idHashIndex *p_varDefNameHash; // r29
  int v5; // r31
  idList<idVarDefName *,58> *p_varDefNames; // r27

  p_varDefNameHash = &this->varDefNameHash;
  v5 = this->varDefNameHash.hash[idHashIndex::GenerateKeyForString(
                                   this: &this->varDefNameHash,
                                   string: name,
                                   caseSensitive: true)
                               & this->varDefNameHash.hashMask
                               & this->varDefNameHash.lookupMask];
  if ( v5 == -1 )
    return nullptr;
  p_varDefNames = &this->varDefNames;
  while ( idStr::Cmp(s1: p_varDefNames->list[v5]->name.data, s2: name) != 0 )
  {
    v5 = p_varDefNameHash->indexChain[p_varDefNameHash->lookupMask & v5];
    if ( v5 == -1 )
      return nullptr;
  }
  return p_varDefNames->list[v5]->defs;
}


// ========================================================================
// ?GetDef@idProgram@@QBAPAVidVarDef@@PBVidTypeDef@@PBDPBV2@@Z
// EA  : 0x82E9BF50
// RVA : 0x00E9BF50
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idVarDef *__fastcall idProgram::GetDef(idProgram *this, const idTypeDef *type, const char *name, const idVarDef *scope)
{
  int v7; // r30
  idVarDef *v8; // r29
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  idVarDef *DefList; // r3
  int v13; // r11
  const idVarDef *v14; // r11
  int v15; // r11
  va *v16; // r3
  int v18; // [sp+8h] [-1088h]
  int v19; // [sp+Ch] [-1084h]
  int v20; // [sp+10h] [-1080h]
  int v21; // [sp+14h] [-107Ch]
  int v22; // [sp+18h] [-1078h]
  int v23; // [sp+1Ch] [-1074h]
  _BYTE v24[16]; // [sp+50h] [-1040h] BYREF
  va v25; // [sp+60h] [-1030h] BYREF

  v7 = 0;
  v8 = nullptr;
  DefList = idProgram::GetDefList(this, name);
  if ( DefList == nullptr )
    return v8;
  do
  {
    HIDWORD(v9) = DefList->scope;
    v13 = *(_DWORD *)(HIDWORD(v9) + 20);
    if ( v13 == 0 || *(_DWORD *)(v13 + 4) != 2 )
    {
      if ( (const idVarDef *)HIDWORD(v9) != scope )
        goto LABEL_15;
      v15 = 1;
LABEL_12:
      if ( v8 == nullptr || v15 < v7 )
      {
        v7 = v15;
        v8 = DefList;
      }
      goto LABEL_15;
    }
    LODWORD(v9) = 1;
    v14 = scope;
    if ( scope != nullptr )
    {
      while ( v14 != (const idVarDef *)HIDWORD(v9) )
      {
        v14 = v14->scope;
        LODWORD(v9) = v9 + 1;
        if ( v14 == nullptr )
          goto LABEL_15;
      }
      v15 = v9;
      if ( (_DWORD)v9 != 0 )
        goto LABEL_12;
    }
LABEL_15:
    DefList = DefList->next;
  }
  while ( DefList != nullptr );
  if ( v8 != nullptr && type != nullptr && v8->typeDef != type )
  {
    HIDWORD(v11) = name;
    v16 = va::va(
            this: &v25,
            fmt: "Type mismatch on redeclaration of %s",
            a3: v11,
            a4: v10,
            a5: v9,
            a6: v18,
            a7: v19,
            a8: v20,
            a9: v21,
            a10: v22,
            a11: v23);
    strncpy(dest: idException::error, source: v16->buffer, count: 0x800u);
    CxxThrowException(pExceptionObject: v24, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  return v8;
}


// ========================================================================
// ?FreeDef@idProgram@@QAAXPAVidVarDef@@PBV2@@Z
// EA  : 0x82E9C080
// RVA : 0x00E9C080
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::FreeDef(idProgram *this, idVarDef *def, const idVarDef *scope)
{
  idTypeDef *typeDef; // r11
  idVarDef *v7; // r4
  idVarDef *v8; // r4
  idVarDef *v9; // r4
  int num; // r11
  int v11; // r10
  idVarDef *v12; // r7
  idVarDefName *name; // r3
  idStr v14[2]; // [sp+50h] [-50h] BYREF

  typeDef = def->typeDef;
  if ( typeDef != nullptr && typeDef->type == ev_vector )
  {
    v14[0].len = 0;
    v14[0].allocedAndFlag = 20;
    v14[0].data = v14[0].baseBuffer;
    v14[0].baseBuffer[0] = 0;
    idStr::Format(this: v14, fmt: "%s_x", def->name->name.data);
    v7 = idProgram::GetDef(this, type: nullptr, name: v14[0].data, scope);
    if ( v7 != nullptr )
      idProgram::FreeDef(this, def: v7, scope);
    idStr::Format(this: v14, fmt: "%s_y", def->name->name.data);
    v8 = idProgram::GetDef(this, type: nullptr, name: v14[0].data, scope);
    if ( v8 != nullptr )
      idProgram::FreeDef(this, def: v8, scope);
    idStr::Format(this: v14, fmt: "%s_z", def->name->name.data);
    v9 = idProgram::GetDef(this, type: nullptr, name: v14[0].data, scope);
    if ( v9 != nullptr )
      idProgram::FreeDef(this, def: v9, scope);
    idStr::FreeData(this: v14);
  }
  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
    this: (idList<idEntityPtr<idEntity>,58> *)&this->varDefs,
    index: def->num);
  num = def->num;
  if ( def->num < this->varDefs.num )
  {
    v11 = num;
    do
    {
      v12 = this->varDefs.list[v11++];
      v12->num = num++;
    }
    while ( num < this->varDefs.num );
  }
  name = def->name;
  if ( name != nullptr )
    idVarDefName::RemoveDef(this: name, def);
  idMem::Free(this: &mem, ptr: def, align: ALIGN_16);
}


// ========================================================================
// __unwind$496481
// EA  : 0x82E9C224
// RVA : 0x00E9C224
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_496481()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?FindFunction@idProgram@@QBAPAVfunction_t@@PBD@Z
// EA  : 0x82E9C258
// RVA : 0x00E9C258
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

function_t *__fastcall idProgram::FindFunction(idProgram *this, const char *name)
{
  int v3; // r30
  idVarDef *Def; // r29
  int v5; // r3
  int v6; // r28
  idTypeDef *typeDef; // r11
  idVarDef *v8; // r3
  idTypeDef *v9; // r11
  _DWORD *ip; // r30
  idStr v12; // [sp+60h] [-A0h] BYREF
  idStr v13; // [sp+80h] [-80h] BYREF
  idStr v14[3]; // [sp+A0h] [-60h] BYREF

  idStr::idStr(this: &v12, text: name);
  v3 = 0;
  Def = &def_namespace;
  do
  {
    v5 = idStr::Find(searchIn: v12.data, searchFor: "::", casesensitive: true, start: v3, end: v12.len);
    v6 = v5;
    if ( v5 < 0 )
      break;
    idStr::Mid(this: v14, result: &v12, start: v3, len: v5 - v3);
    Def = idProgram::GetDef(this, type: nullptr, name: v14[0].data, scope: Def);
    if ( Def == nullptr )
    {
      idStr::FreeData(this: v14);
      goto LABEL_14;
    }
    v3 = v6 + 2;
    idStr::FreeData(this: v14);
    typeDef = Def->typeDef;
    if ( typeDef == nullptr )
      break;
  }
  while ( typeDef->type == ev_namespace );
  idStr::Right(this: &v13, result: &v12, len: v12.len - v3);
  v8 = idProgram::GetDef(this, type: nullptr, name: v13.data, scope: Def);
  if ( v8 != nullptr )
  {
    v9 = v8->typeDef;
    if ( v9 != nullptr && v9->type == ev_function )
    {
      ip = v8->value.value.ip;
      if ( *ip == 0 )
      {
        idStr::FreeData(this: &v13);
        idStr::FreeData(this: &v12);
        return (function_t *)ip;
      }
    }
  }
  idStr::FreeData(this: &v13);
LABEL_14:
  idStr::FreeData(this: &v12);
  return nullptr;
}


// ========================================================================
// __unwind$496672_0
// EA  : 0x82E9C3B0
// RVA : 0x00E9C3B0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_496672_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$496673
// EA  : 0x82E9C3D8
// RVA : 0x00E9C3D8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_496673()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 160));
}


// ========================================================================
// __unwind$496674
// EA  : 0x82E9C400
// RVA : 0x00E9C400
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_496674()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// ?FindFunction@idProgram@@QBAPAVfunction_t@@PBDPBVidTypeDef@@@Z
// EA  : 0x82E9C428
// RVA : 0x00E9C428
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

function_t *__fastcall idProgram::FindFunction(idProgram *this, const char *name, const idTypeDef *type)
{
  idVarDef *def; // r31
  idVarDef *v6; // r3
  idTypeDef *typeDef; // r11
  char v9; // [sp+50h] [-30h] BYREF

  def = type->def;
  if ( type->def == &def_object )
    return nullptr;
  while ( 1 )
  {
    v6 = idProgram::GetDef(this, type: nullptr, name, scope: def);
    if ( v6 != nullptr )
      break;
    typeDef = def->typeDef;
    if ( typeDef->type != ev_object )
    {
      strncpy(
        dest: idException::error,
        source: "idTypeDef::SuperClass : tried to get superclass of a non-object type",
        count: 0x800u);
      CxxThrowException(pExceptionObject: &v9, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
    }
    def = typeDef->auxType->def;
    if ( def == &def_object )
      return nullptr;
  }
  return v6->value.value.up;
}


// ========================================================================
// ?DisassembleStatement@idProgram@@QBAXPAVidFile@@H@Z
// EA  : 0x82E9C4D8
// RVA : 0x00E9C4D8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::DisassembleStatement(idProgram *this, idFile *file, int instructionPointer)
{
  statement_t *v5; // r31

  v5 = &this->statements.list[instructionPointer];
  file->Printf(
    this: file,
    a2: "%20s(%d):\t%6d: %15s\t",
    *((_DWORD *)&this->fileList.list->fileName.data + v5->file + __ROL4__(v5->file, 3)),
    v5->linenumber,
    instructionPointer,
    *(const char **)((char *)&idCompiler::opcodes[0].opname + __ROL4__(v5->op, 5)));
  if ( v5->a != nullptr )
  {
    file->Printf(this: file, a2: "\ta: ");
    idVarDef::PrintInfo(this: v5->a, file, instructionPointer);
  }
  if ( v5->b != nullptr )
  {
    file->Printf(this: file, a2: "\tb: ");
    idVarDef::PrintInfo(this: v5->b, file, instructionPointer);
  }
  if ( v5->c != nullptr )
  {
    file->Printf(this: file, a2: "\tc: ");
    idVarDef::PrintInfo(this: v5->c, file, instructionPointer);
  }
  file->Printf(this: file, a2: "\n");
}


// ========================================================================
// ?Disassemble@idProgram@@QBAXXZ
// EA  : 0x82E9C628
// RVA : 0x00E9C628
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::Disassemble(idProgram *this)
{
  idFile *v2; // r29
  int *p_num; // r23
  int v4; // r25
  int v5; // r27
  function_t *v6; // r31
  int i; // r30

  p_num = &this->functions.num;
  v2 = fileSystem->OpenFileWrite(this: fileSystem, a2: "script/disasm.txt", a3: 0);
  v4 = 0;
  if ( this->functions.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->functions.list[v5];
      if ( v6->eventdef == nullptr )
      {
        v2->Printf(
          this: v2,
          a2: "\nfunction %s() %d stack used, %d parms, %d locals {\n",
          v6->name.data,
          v6->locals,
          v6->parmTotal,
          v6->locals - v6->parmTotal);
        for ( i = 0; i < v6->numStatements; ++i )
          idProgram::DisassembleStatement(this, file: v2, instructionPointer: i + v6->firstStatement);
        v2->Printf(this: v2, a2: "}\n");
      }
      ++v4;
      ++v5;
    }
    while ( v4 < *p_num );
  }
  if ( v2 != nullptr )
    ((void (__fastcall *)(idFile *, int))v2->dtr_idFile)(a1: v2, a2: 1);
}


// ========================================================================
// ?CompileStats@idProgram@@AAAXXZ
// EA  : 0x82E9C758
// RVA : 0x00E9C758
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::CompileStats(idProgram *this)
{
  int v2; // r28
  int v3; // r29
  idProgram::idFileInfo *list; // r11
  int v5; // r30
  idProgram::idFileInfo *v6; // r10
  int v7; // r11
  int num; // r11
  int v9; // r24
  int v10; // r27
  int v11; // r29
  int v12; // r30
  idTypeDef **v13; // r28
  int v14; // r4
  int v15; // r5
  int v16; // r9
  int v17; // r28
  int v18; // r26
  function_t *v19; // r29
  int v20; // r6
  function_t *v21; // r11
  int v22; // r7
  int size; // r8
  function_t *v24; // r10
  idStr *p_name; // r11
  char *data; // r22
  int v27; // r8
  function_t *v28; // r10
  int v29; // r9
  int v30; // r30
  int v31; // r29

  idLib::Printf(fmt: "---------- Compile stats ----------\n");
  idLib::Printf(fmt: "Files loaded:\n");
  v2 = 0;
  v3 = 0;
  if ( this->fileList.num > 0 )
  {
    list = this->fileList.list;
    v5 = 0;
    do
    {
      idLib::Printf(fmt: "   %s\n", list->fileName.data);
      v6 = this->fileList.list;
      if ( v6[v5].fileName.data == v6[v5].fileName.baseBuffer )
        v7 = 0;
      else
        v7 = v6[v5].fileName.allocedAndFlag & 0x7FFFFFFF;
      ++v3;
      ++v5;
      v2 += v7;
      list = &v6[v5];
    }
    while ( v3 < this->fileList.num );
  }
  num = this->types.num;
  v9 = 36 * this->fileList.size + v2;
  v10 = 32 * (this->varDefs.num + 4 * num) + v9;
  if ( num > 0 )
  {
    v11 = 0;
    v12 = this->types.num;
    v13 = this->types.list;
    do
    {
      --v12;
      v10 += idTypeDef::Allocated(this: v13[v11++]);
    }
    while ( v12 != 0 );
  }
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = this->functions.num;
  v18 = 80 * v17;
  if ( v17 >= 2 )
  {
    v19 = this->functions.list;
    v20 = 0;
    do
    {
      v21 = &v19[v20];
      if ( v19[v20].name.data == v19[v20].name.baseBuffer )
        v22 = 0;
      else
        v22 = v19[v20].name.allocedAndFlag & 0x7FFFFFFF;
      size = v21->parmSize.size;
      v24 = v21 + 1;
      data = v21[1].name.data;
      p_name = &v21[1].name;
      v14 += 4 * size + v22;
      if ( data == p_name->baseBuffer )
        v27 = 0;
      else
        v27 = p_name->allocedAndFlag & 0x7FFFFFFF;
      v16 += 2;
      v20 += 2;
      v15 += 4 * v24->parmSize.size + v27;
    }
    while ( v16 < v17 - 1 );
  }
  if ( v16 < v17 )
  {
    v28 = &this->functions.list[v16];
    if ( v28->name.data == v28->name.baseBuffer )
      v29 = 0;
    else
      v29 = v28->name.allocedAndFlag & 0x7FFFFFFF;
    v18 += 4 * v28->parmSize.size + v29;
  }
  v30 = v14 + v15 + v18;
  v31 = this->statements.num;
  idLib::Printf(fmt: "\nMemory usage:\n");
  idLib::Printf(fmt: "     Strings: %d, %d bytes\n", this->fileList.num, v9);
  idLib::Printf(fmt: "  Statements: %d, %d bytes\n", this->statements.num, 16 * this->statements.num);
  idLib::Printf(fmt: "   Functions: %d, %d bytes\n", this->functions.num, v30);
  idLib::Printf(fmt: "   Variables: %d bytes\n", this->numVariables);
  idLib::Printf(fmt: "    Mem used: %d bytes\n", 16 * (5 * v17 + v31 + 4096) + v10);
  idLib::Printf(fmt: " Static data: %d bytes\n", 541092);
  idLib::Printf(fmt: "   Allocated: %d bytes\n", v30 + v10 + 541092);
  idLib::Printf(fmt: " Thread size: %d bytes\n\n", 7060);
}


// ========================================================================
// ??0function_t@@QAA@XZ
// EA  : 0x82E9CB10
// RVA : 0x00E9CB10
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

function_t *__fastcall function_t::function_t(function_t *this)
{
  idList<int,58> *p_parmSize; // r28

  this->parmSize.list = nullptr;
  p_parmSize = &this->parmSize;
  this->parmSize.granularity = 0;
  this->parmSize.memTag = 58;
  this->parmSize.listStatic = 0;
  this->parmSize.size = 0;
  this->parmSize.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->parmSize);
  this->name.len = 0;
  this->name.allocedAndFlag = 20;
  this->name.data = this->name.baseBuffer;
  this->name.baseBuffer[0] = 0;
  this->eventdef = nullptr;
  this->def = nullptr;
  this->type = nullptr;
  this->firstStatement = 0;
  this->numStatements = 0;
  this->parmTotal = 0;
  this->locals = 0;
  this->filenum = 0;
  idStr::Clear(this: &this->name);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_parmSize);
  return this;
}


// ========================================================================
// __unwind$497478
// EA  : 0x82E9CBB0
// RVA : 0x00E9CBB0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_497478()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 32));
}


// ========================================================================
// __unwind$497479
// EA  : 0x82E9CBDC
// RVA : 0x00E9CBDC
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_497479()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// ??1idScriptObject@@UAA@XZ
// EA  : 0x82E9CC10
// RVA : 0x00E9CC10
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idScriptObject::~idScriptObject(idScriptObject *this)
{
  this->__vftable = (idScriptObject_vtbl *)&idScriptObject::`vftable';
  idScriptObject::Free(this);
  this->__vftable = (idScriptObject_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$497530
// EA  : 0x82E9CC64
// RVA : 0x00E9CC64
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_497530()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetFunction@idScriptObject@@QBAPBVfunction_t@@PBD@Z
// EA  : 0x82E9CC90
// RVA : 0x00E9CC90
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

const function_t *__fastcall idScriptObject::GetFunction(idScriptObject *this, const char *name)
{
  idTypeDef *type; // r5

  type = this->type;
  if ( type == &type_object )
    return nullptr;
  else
    return idProgram::FindFunction(this: &gameLocal->program, name, type);
}


// ========================================================================
// ?Read@idScriptObject@@QAAXAAVidTypeInfoFile@@@Z
// EA  : 0x82E9CCC8
// RVA : 0x00E9CCC8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idScriptObject::Read(idScriptObject *this, idTypeInfoFile *file)
{
  const char *v4; // r3
  int VariableOffsetFromName; // r10
  unsigned __int8 *v6; // r30
  idEntity *v7; // r3
  idStr v8; // [sp+50h] [-180h] BYREF
  int entityNumber; // [sp+70h] [-160h]
  etype_t v10[3]; // [sp+74h] [-15Ch] BYREF
  idStr v11; // [sp+80h] [-150h] BYREF
  idStr v12; // [sp+A0h] [-130h] BYREF
  idStr v13; // [sp+C0h] [-110h] BYREF
  idLexer v14; // [sp+E0h] [-F0h] BYREF

  v11.len = 0;
  v11.allocedAndFlag = 20;
  v11.data = v11.baseBuffer;
  v11.baseBuffer[0] = 0;
  v13.allocedAndFlag = 20;
  v13.data = v13.baseBuffer;
  v13.len = 0;
  v13.baseBuffer[0] = 0;
  v12.allocedAndFlag = 20;
  v12.data = v12.baseBuffer;
  v12.len = 0;
  v12.baseBuffer[0] = 0;
  v8.allocedAndFlag = 20;
  v8.data = v8.baseBuffer;
  v8.len = 0;
  v8.baseBuffer[0] = 0;
  if ( idTypeInfoFile::CheckType(this: file, type: "idTypeDef", ops: "*", name: "type") )
  {
    idTypeInfoFile::ReadStr(this: file, s: &v11);
    idScriptObject::SetType(this, typeName: v11.data, clear: false);
  }
  while ( !idTypeInfoFile::PeekClosingBrace(this: file) )
  {
    idTypeInfoFile::ReadType(this: file, type: &v11, ops: &v13, name: &v12);
    idTypeInfoFile::ReadValueString(this: file, value: &v8);
    if ( v8.len != 0 && *v8.data == 34 )
    {
      v4 = idStr::CStyleUnQuote(str: v8.data);
      idStr::operator=(this: &v8, text: v4);
    }
    VariableOffsetFromName = idScriptObject::GetVariableOffsetFromName(this, name: v12.data, etype: v10);
    if ( VariableOffsetFromName != -1 )
    {
      v6 = &this->data[VariableOffsetFromName];
      idLexer::idLexer(this: &v14, flags_: 0);
      idLexer::LoadMemory(this: &v14, ptr: v8.data, length_: v8.len, name: &byte_8200D768);
      switch ( v10[0] )
      {
        case ev_string:
          idStr::Copynz(dest: (char *)v6, src: v8.data, destsize: 256);
          goto LABEL_28;
        case ev_float:
          *(float *)v6 = idLexer::ParseFloat(this: &v14, errorFlag: nullptr);
          goto LABEL_28;
        case ev_vector:
          *(float *)v6 = idLexer::ParseFloat(this: &v14, errorFlag: nullptr);
          *((float *)v6 + 1) = idLexer::ParseFloat(this: &v14, errorFlag: nullptr);
          *((float *)v6 + 2) = idLexer::ParseFloat(this: &v14, errorFlag: nullptr);
          goto LABEL_28;
        case ev_entity:
        case ev_object:
          if ( file->settings.writeModifier != WRITE_ALL_PROPERTIES || !file->settings.resolveEntityPointers )
          {
            if ( !file->settings.resolveEntityPointers )
              goto LABEL_21;
            if ( v8.len == 0 )
            {
              *(_DWORD *)v6 = 0x1FFF;
              goto LABEL_28;
            }
            v7 = gameLocal->FindEntity(this: gameLocal, a2: v8.data);
            if ( v7 != nullptr )
            {
              entityNumber = v7->entityNumber;
              *(_DWORD *)v6 = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
            }
            else
            {
LABEL_21:
              idGameState::SetUnresolvedEntityName(ptr: (idEntityPtr<idEntity> *)v6, name: v8.data);
              if ( (*(_DWORD *)v6 & 0x1FFF) == 0 )
                idTypeInfoFile::Warning(this: file, str: "idScriptObject::Read: entity '%s' not found", v8.data);
            }
          }
          else
          {
            if ( v8.len != 0 )
              goto LABEL_27;
            *(_DWORD *)v6 = 0x1FFF;
          }
LABEL_28:
          idLexer::~idLexer(this: &v14);
          break;
        case ev_list:
          goto LABEL_27;
        default:
          if ( idLexer::CheckTokenString(this: &v14, string: "true") )
          {
            *(_DWORD *)v6 = 1;
          }
          else if ( idLexer::CheckTokenString(this: &v14, string: "false") )
          {
            *(_DWORD *)v6 = 0;
          }
          else
          {
LABEL_27:
            *(_DWORD *)v6 = idLexer::ParseInt(this: &v14);
          }
          goto LABEL_28;
      }
    }
  }
  idStr::FreeData(this: &v8);
  idStr::FreeData(this: &v12);
  idStr::FreeData(this: &v13);
  idStr::FreeData(this: &v11);
}


// ========================================================================
// __unwind$497551
// EA  : 0x82E9D064
// RVA : 0x00E9D064
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_497551()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 128));
}


// ========================================================================
// __unwind$497552
// EA  : 0x82E9D08C
// RVA : 0x00E9D08C
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_497552()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 192));
}


// ========================================================================
// __unwind$497553
// EA  : 0x82E9D0B4
// RVA : 0x00E9D0B4
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_497553()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 160));
}


// ========================================================================
// __unwind$497554
// EA  : 0x82E9D0DC
// RVA : 0x00E9D0DC
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_497554()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 80));
}


// ========================================================================
// __unwind$497555
// EA  : 0x82E9D104
// RVA : 0x00E9D104
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_497555()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 464 + 224));
}


// ========================================================================
// ?SetEntity@idProgram@@QAAXPBDPAVidEntity@@@Z
// EA  : 0x82E9D138
// RVA : 0x00E9D138
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::SetEntity(idProgram *this, char *name, idEntity *ent)
{
  idVarDef *Def; // r3
  idStr v7[2]; // [sp+60h] [-50h] BYREF

  idStr::idStr(this: v7, text: "$");
  idStr::Append(this: v7, text: name);
  idStr::MakeNameCanonical(this: v7);
  Def = idProgram::GetDef(this, type: &type_entity, name: v7[0].data, scope: &def_namespace);
  if ( Def != nullptr && Def->initialized != stackVariable )
  {
    if ( ent != nullptr )
    {
      *Def->value.value.ip = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
      Def->initialized = initializedVariable;
    }
    else
    {
      *Def->value.value.ip = 0x1FFF;
      Def->initialized = uninitialized;
    }
  }
  idStr::FreeData(this: v7);
}


// ========================================================================
// __unwind$498098
// EA  : 0x82E9D210
// RVA : 0x00E9D210
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_498098()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?ReturnEntity@idProgram@@QAAXPAVidEntity@@@Z
// EA  : 0x82E9D238
// RVA : 0x00E9D238
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::ReturnEntity(idProgram *this, idEntity *ent)
{
  int *ip; // r9

  ip = this->returnDef->value.value.ip;
  if ( ent != nullptr )
    *ip = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  else
    *ip = 0x1FFF;
}


// ========================================================================
// ??0idTypeDef@@QAA@W4etype_t@@PAVidVarDef@@PBDHPAV0@@Z
// EA  : 0x82E9D4F8
// RVA : 0x00E9D4F8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idTypeDef *__fastcall idTypeDef::idTypeDef(
        idTypeDef *this,
        etype_t etype,
        idVarDef *edef,
        const char *ename,
        int esize,
        idTypeDef *aux)
{
  idStr *p_name; // r27

  p_name = &this->name;
  this->name.len = 0;
  this->name.data = this->name.baseBuffer;
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  this->parmTypes.list = nullptr;
  this->parmTypes.granularity = 0;
  this->parmTypes.listStatic = 0;
  this->parmTypes.memTag = 58;
  this->parmTypes.size = 0;
  this->parmTypes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->parmTypes);
  this->parmNames.granularity = 0;
  this->parmNames.memTag = 58;
  this->parmNames.listStatic = 0;
  this->parmNames.list = nullptr;
  this->parmNames.size = 0;
  this->parmNames.num = 0;
  this->functions.list = nullptr;
  this->functions.granularity = 0;
  this->functions.memTag = 58;
  this->functions.listStatic = 0;
  this->functions.size = 0;
  this->functions.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->functions);
  this->parmEditableFlags.list = nullptr;
  this->parmEditableFlags.granularity = 0;
  this->parmEditableFlags.memTag = 58;
  this->parmEditableFlags.listStatic = 0;
  this->parmEditableFlags.size = 0;
  this->parmEditableFlags.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->parmEditableFlags);
  this->parmComments.granularity = 0;
  this->parmComments.memTag = 58;
  this->parmComments.listStatic = 0;
  this->parmComments.list = nullptr;
  this->parmComments.size = 0;
  this->parmComments.num = 0;
  idStr::operator=(this: p_name, text: ename);
  this->type = etype;
  this->def = edef;
  this->size = esize;
  this->auxType = aux;
  return this;
}


// ========================================================================
// __unwind$499051
// EA  : 0x82E9D614
// RVA : 0x00E9D614
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_499051()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 8));
}


// ========================================================================
// __unwind$499052
// EA  : 0x82E9D640
// RVA : 0x00E9D640
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_499052()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 48));
}


// ========================================================================
// __unwind$499053
// EA  : 0x82E9D66C
// RVA : 0x00E9D66C
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_499053()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 176 + 196) + 64));
}


// ========================================================================
// __unwind$499054
// EA  : 0x82E9D698
// RVA : 0x00E9D698
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_499054()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 80));
}


// ========================================================================
// __unwind$499055
// EA  : 0x82E9D6C4
// RVA : 0x00E9D6C4
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_499055()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 96));
}


// ========================================================================
// __unwind$499056
// EA  : 0x82E9D6F0
// RVA : 0x00E9D6F0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_499056()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 176 + 196) + 112));
}


// ========================================================================
// ??4idTypeDef@@QAAXABV0@@Z
// EA  : 0x82E9D720
// RVA : 0x00E9D720
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idTypeDef::operator=(idTypeDef *this, const idTypeDef *other)
{
  int len; // r29

  if ( other != this )
  {
    this->type = other->type;
    this->def = other->def;
    len = other->name.len;
    idStr::EnsureAlloced(this: &this->name, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: this->name.data, Src: other->name.data, Size: len);
    this->name.data[len] = 0;
    this->name.len = len;
    this->size = other->size;
    this->auxType = other->auxType;
    idList<idMaterial const *,59>::operator=(
      this: (idList<idMD6Node *,5> *)&this->parmTypes,
      other: (const idList<idMD6Node *,5> *)&other->parmTypes);
    idList<idStr,58>::operator=(
      this: (idList<idStr,5> *)&this->parmNames,
      other: (const idList<idStr,5> *)&other->parmNames);
    idList<idMaterial const *,59>::operator=(
      this: (idList<idMD6Node *,5> *)&this->functions,
      other: (const idList<idMD6Node *,5> *)&other->functions);
    idList<unsigned char,34>::operator=(
      this: (idList<unsigned char,25> *)&this->parmEditableFlags,
      other: (const idList<unsigned char,25> *)&other->parmEditableFlags);
    idList<idStr,58>::operator=(
      this: (idList<idStr,5> *)&this->parmComments,
      other: (const idList<idStr,5> *)&other->parmComments);
  }
}


// ========================================================================
// ?AddField@idTypeDef@@QAAXPAV1@PBD_N1@Z
// EA  : 0x82E9D7E0
// RVA : 0x00E9D7E0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idTypeDef::AddField(
        idTypeDef *this,
        idTypeDef *fieldtype,
        const char *name,
        bool editable,
        const char *comment,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idTypeDef *a14,
        int a15,
        int a16,
        int a17,
        bool a18)
{
  etype_t type; // r11
  const idStr *v23; // r3
  const idStr *v24; // r3
  idTypeDef *auxType; // r11
  char v26; // r11
  idTypeDef *v27; // r11
  int size; // r11
  int v29; // r10
  _BYTE v30[16]; // [sp+50h] [-80h] BYREF
  idStr v31; // [sp+60h] [-70h] BYREF
  idStr v32[2]; // [sp+80h] [-50h] BYREF

  type = this->type;
  a14 = fieldtype;
  a18 = editable;
  if ( type != ev_object )
  {
    strncpy(
      dest: idException::error,
      source: "idTypeDef::AddField : tried to add field to non-object type",
      count: 0x800u);
    CxxThrowException(pExceptionObject: v30, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->parmTypes,
    obj: (encounterGroupRole_t *)&a14);
  idList<unsigned char,25>::Append(
    this: (idList<unsigned char,37> *)&this->parmEditableFlags,
    obj: (unsigned __int8 *)&a18);
  v23 = idStr::idStr(this: &v31, text: name);
  idList<idStr,5>::Append(this: (idList<idStr,5> *)&this->parmNames, obj: v23);
  idStr::FreeData(this: &v31);
  v24 = idStr::idStr(this: v32, text: comment);
  idList<idStr,5>::Append(this: (idList<idStr,5> *)&this->parmComments, obj: v24);
  idStr::FreeData(this: v32);
  if ( fieldtype->type != ev_field )
  {
    strncpy(
      dest: idException::error,
      source: "idTypeDef::FieldType: tried to get field type on non-field type",
      count: 0x800u);
    CxxThrowException(pExceptionObject: v30, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  auxType = fieldtype->auxType;
  if ( auxType->type == ev_object )
  {
    if ( auxType == &type_object )
    {
LABEL_7:
      v26 = 1;
      goto LABEL_12;
    }
    v27 = auxType->auxType;
    if ( v27 != nullptr )
    {
      while ( v27 != &type_object )
      {
        v27 = v27->auxType;
        if ( v27 == nullptr )
          goto LABEL_11;
      }
      goto LABEL_7;
    }
  }
LABEL_11:
  v26 = 0;
LABEL_12:
  if ( v26 != 0 )
  {
    size = type_object.size;
    v29 = this->size;
  }
  else
  {
    v29 = idTypeDef::FieldType(this: fieldtype)->size;
    size = this->size;
  }
  this->size = v29 + size;
}


// ========================================================================
// $LN39_5
// EA  : 0x82E9D95C
// RVA : 0x00E9D95C
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _LN39_5()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$499183
// EA  : 0x82E9D984
// RVA : 0x00E9D984
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_499183()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 128));
}


// ========================================================================
// ?AddFunction@idTypeDef@@QAAXPBVfunction_t@@@Z
// EA  : 0x82E9D9B0
// RVA : 0x00E9D9B0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idTypeDef::AddFunction(
        idTypeDef *this,
        const function_t *func,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        const function_t *a14)
{
  int num; // r26
  int v17; // r28
  const function_t **list; // r29
  int v19; // r31
  idVarDef *def; // r30
  idVarDef *v21; // r8
  char *data; // r10
  char *v23; // r11
  int v24; // r9
  int v25; // r9
  bool v26; // zf

  num = this->functions.num;
  a14 = func;
  v17 = 0;
  if ( num <= 0 )
  {
LABEL_9:
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->functions,
      obj: (encounterGroupRole_t *)&a14);
  }
  else
  {
    list = this->functions.list;
    v19 = 0;
    def = func->def;
    while ( 1 )
    {
      v21 = list[v19]->def;
      data = def->name->name.data;
      v23 = v21->name->name.data;
      do
      {
        v24 = (unsigned __int8)*v23;
        v26 = v24 == 0;
        v25 = v24 - (unsigned __int8)*data;
        if ( v26 )
          break;
        ++v23;
        ++data;
      }
      while ( v25 == 0 );
      if ( v25 == 0
        && (unsigned __int8)idTypeDef::MatchesVirtualFunction(this: def->typeDef, matchfunc: v21->typeDef) != 0 )
      {
        break;
      }
      ++v17;
      ++v19;
      if ( v17 >= num )
        goto LABEL_9;
    }
    list[v17] = func;
  }
}


// ========================================================================
// ?SetFunction@idScriptFunction@@QAA_NPAVidEntity@@PBDW4etype_t@@HZZ
// EA  : 0x82E9DA80
// RVA : 0x00E9DA80
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
BOOL idScriptFunction::SetFunction(
        idScriptFunction *this,
        idEntity *ent,
        const char *functionName,
        unsigned int returnType,
        __int64 numParms,
        __int64 a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        ...)
{
  idTypeDef *type; // r5
  const function_t *Function; // r3
  const function_t *v25; // r11
  const function_t *v26; // r3
  idTypeDef *v27; // r29
  idVarDef *def; // r10
  bool v29; // r11
  int v30; // r30
  __int64 v31; // r10
  __int64 v32; // r8
  va_list v33; // r11
  unsigned int v34; // r11
  int v35; // r3
  __int64 v36; // r6
  va *v37; // r3
  __int64 v38; // r8
  __int64 v39; // r10
  int v40; // r29
  va_list v41; // r30
  unsigned int v42; // r11
  __int64 v43; // r6
  va *v44; // r3
  int v45; // r10
  int v46; // r9
  int v47; // r8
  int v48; // r7
  int v49; // r6
  int v50; // r5
  int v51; // r4
  int v52; // r3
  int v53; // [sp+8h] [-10C8h]
  int v54; // [sp+8h] [-10C8h]
  int v55; // [sp+Ch] [-10C4h]
  int v56; // [sp+Ch] [-10C4h]
  int v57; // [sp+10h] [-10C0h]
  int v58; // [sp+10h] [-10C0h]
  int v59; // [sp+14h] [-10BCh]
  int v60; // [sp+14h] [-10BCh]
  int v61; // [sp+18h] [-10B8h]
  int v62; // [sp+18h] [-10B8h]
  int v63; // [sp+1Ch] [-10B4h]
  int v64; // [sp+1Ch] [-10B4h]
  idStr v65; // [sp+60h] [-1070h] BYREF
  va v66; // [sp+80h] [-1050h] BYREF
  int v67; // [sp+1104h] [+34h]
  __int64 v68; // [sp+1108h] [+38h] BYREF
  va_list va; // [sp+1108h] [+38h]
  __int64 v70; // [sp+1110h] [+40h]
  __int64 v71; // [sp+1118h] [+48h]
  va_list va1; // [sp+1120h] [+50h] BYREF

  va_start(va1, a18);
  va_start(va, a18);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v68 = numParms;
  v70 = *(__int64 *)((char *)&a6 + 4);
  v71 = a6;
  v67 = HIDWORD(numParms);
  v65.len = 0;
  v65.allocedAndFlag = 20;
  v65.data = v65.baseBuffer;
  v65.baseBuffer[0] = 0;
  this->owner = ent;
  if ( ent != nullptr )
  {
    type = ent->GetScriptObject_2(this: ent)->type;
    if ( type == &type_object )
      Function = nullptr;
    else
      Function = idProgram::FindFunction(this: &gameLocal->program, name: functionName, type);
    v25 = Function;
    this->function = Function;
    if ( Function == nullptr )
    {
      v26 = idProgram::FindFunction(this: &gameLocal->program, name: functionName);
      this->function = v26;
      v25 = v26;
      if ( v26 == nullptr )
        idLib::Error(fmt: "'%s' calls unknown function '%s'", ent->name.data, functionName);
    }
    v27 = (idTypeDef *)v25->type;
    if ( v27->parmTypes.num > 15 )
      idLib::Error(
        fmt: "Function '%s' has too many args (>%d) to be called by entity '%s'",
        functionName,
        14,
        ent->name.data);
    def = v25->def;
    v29 = def != nullptr && def->scope->typeDef->type == ev_object;
    v30 = v29;
    HIDWORD(v31) = idTypeDef::ReturnType(this: v27)->type;
    if ( returnType != HIDWORD(v31) )
      goto LABEL_23;
    HIDWORD(v31) = v27->parmTypes.num;
    if ( v30 + v67 != HIDWORD(v31) )
      goto LABEL_23;
    va_copy((va_list)v31, va);
    HIDWORD(v32) = v30;
    if ( v30 < SHIDWORD(v31) )
    {
      LODWORD(v32) = v27->parmTypes.list;
      LODWORD(v31) = 4 * v30;
      va_copy(v33, va);
      do
      {
        v34 = ((unsigned int)(v33 + 7) & 0xFFFFFFF8) + 8;
        v35 = *(_DWORD *)(v34 - 4);
        v33 = (va_list)(((v34 + 7) & 0xFFFFFFF8) + 8);
        if ( *(_DWORD *)(*(_DWORD *)(v31 + v32) + 4) != v35 )
          break;
        ++HIDWORD(v32);
        LODWORD(v31) = v31 + 4;
      }
      while ( SHIDWORD(v32) < SHIDWORD(v31) );
    }
    if ( HIDWORD(v32) == HIDWORD(v31) )
    {
      idStr::FreeData(this: &v65);
      return true;
    }
    else
    {
LABEL_23:
      if ( returnType > 0x12 )
      {
        HIDWORD(v36) = 0;
      }
      else
      {
        LODWORD(v31) = basicTypes[returnType];
        HIDWORD(v36) = *(_DWORD *)(v31 + 12);
      }
      LODWORD(v36) = functionName;
      v37 = va::va(
              this: &v66,
              fmt: "%s %s(",
              a3: v36,
              a4: v32,
              a5: v31,
              a6: v53,
              a7: v55,
              a8: v57,
              a9: v59,
              a10: v61,
              a11: v63);
      idStr::operator=(this: &v65, text: v37);
      LODWORD(v38) = v67;
      va_copy((va_list)HIDWORD(v39), va);
      v40 = 0;
      if ( v67 > 0 )
      {
        va_copy(v41, va);
        do
        {
          if ( v40 > 0 )
            idStr::Append(this: &v65, text: ",");
          LODWORD(v39) = (((unsigned int)(v41 + 7) & 0xFFFFFFF8) + 15) & 0xFFFFFFF8;
          v42 = *(_DWORD *)(((unsigned int)(v41 + 7) & 0xFFFFFFF8) + 4);
          v41 = (va_list)(v39 + 8);
          LODWORD(v43) = *(_DWORD *)(v39 + 4);
          if ( v42 > 0x12 )
          {
            HIDWORD(v43) = 0;
          }
          else
          {
            LODWORD(v39) = basicTypes[v42];
            HIDWORD(v43) = *(_DWORD *)(v39 + 12);
          }
          v44 = va::va(
                  this: &v66,
                  fmt: " %s %s",
                  a3: v43,
                  a4: v38,
                  a5: v39,
                  a6: v54,
                  a7: v56,
                  a8: v58,
                  a9: v60,
                  a10: v62,
                  a11: v64);
          idStr::Append(this: &v65, text: v44);
          ++v40;
        }
        while ( v40 < v67 );
        if ( v40 > 0 )
          idStr::Append(this: &v65, text: " ");
      }
      idStr::Append(this: &v65, text: ")");
      idLib::Error(
        fmt: "function '%s' must be defined as '%s' in order to be called by '%s'",
        functionName,
        v65.data,
        this->owner->name.data);
      return _LN142_1(
               a1: v52,
               a2: v51,
               a3: v50,
               a4: v49,
               a5: v48,
               a6: v47,
               a7: v46,
               a8: v45,
               a9: a7,
               a10: a8,
               a11: a9,
               a12: a10,
               a13: a11,
               a14: a12,
               a15: a13,
               a16: a14,
               a17: a15,
               a18: a16);
    }
  }
  else
  {
    idStr::FreeData(this: &v65);
    return false;
  }
}


// ========================================================================
// $LN142_1
// EA  : 0x82E9DDD4
// RVA : 0x00E9DDD4
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _LN142_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4304 + 96));
}


// ========================================================================
// ?GetConstructor@idScriptObject@@QBAPBVfunction_t@@XZ
// EA  : 0x82E9DE60
// RVA : 0x00E9DE60
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

const function_t *__fastcall idScriptObject::GetConstructor(idScriptObject *this)
{
  idTypeDef *type; // r5

  type = this->type;
  if ( type == &type_object )
    return nullptr;
  else
    return idProgram::FindFunction(this: &gameLocal->program, name: "init", type);
}


// ========================================================================
// ?GetDestructor@idScriptObject@@QBAPBVfunction_t@@XZ
// EA  : 0x82E9DE98
// RVA : 0x00E9DE98
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

const function_t *__fastcall idScriptObject::GetDestructor(idScriptObject *this)
{
  idTypeDef *type; // r5

  type = this->type;
  if ( type == &type_object )
    return nullptr;
  else
    return idProgram::FindFunction(this: &gameLocal->program, name: "destroy", type);
}


// ========================================================================
// ?AllocType@idProgram@@QAAPAVidTypeDef@@W4etype_t@@PAVidVarDef@@PBDHPAV2@@Z
// EA  : 0x82E9DED8
// RVA : 0x00E9DED8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idTypeDef *__fastcall idProgram::AllocType(
        idProgram *this,
        etype_t etype,
        idVarDef *edef,
        const char *ename,
        int esize,
        idTypeDef *aux)
{
  idTypeDef *v12; // r3
  idTypeDef *v13; // r30
  idTypeDef *v15; // [sp+50h] [-50h] BYREF

  v12 = (idTypeDef *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x80u,
                       tag: TAG_SCRIPT,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  v15 = v12;
  if ( v12 != nullptr )
    v13 = idTypeDef::idTypeDef(this: v12, etype, edef, ename, esize, aux);
  else
    v13 = nullptr;
  v15 = v13;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->types,
    obj: (encounterGroupRole_t *)&v15);
  return v13;
}


// ========================================================================
// __unwind$499649
// EA  : 0x82E9DF78
// RVA : 0x00E9DF78
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_499649()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_SCRIPT);
}


// ========================================================================
// ?GetScriptObjectNames@idProgram@@QAAXAAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82E9DFB0
// RVA : 0x00E9DFB0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::GetScriptObjectNames(idProgram *this, idList<idStr,5> *list)
{
  int *p_num; // r25
  int v5; // r4
  int v6; // r8
  int num; // r10
  int v8; // r9
  idTypeDef *v9; // r11
  char v10; // r11
  idTypeDef *auxType; // r11
  int v12; // r28
  int i; // r30
  idList<idTypeDef *,58> *p_types; // r29
  idTypeDef **v15; // r10
  idTypeDef *v16; // r11
  char v17; // r11
  idTypeDef *v18; // r11
  idStr v19[3]; // [sp+60h] [-70h] BYREF

  if ( list->listStatic == 0 || list->listStatic == 2 )
  {
    if ( list->list != nullptr )
      idListArrayDelete<idStr>(ptr: list->list, num: list->size);
    list->list = nullptr;
    list->size = 0;
  }
  list->num = 0;
  p_num = &this->types.num;
  v5 = 0;
  v6 = 0;
  num = this->types.num;
  if ( num > 0 )
  {
    v8 = 0;
    while ( 1 )
    {
      v9 = this->types.list[v8];
      if ( v9->type != ev_object )
        break;
      if ( v9 != &type_object )
      {
        auxType = v9->auxType;
        if ( auxType == nullptr )
          break;
        while ( auxType != &type_object )
        {
          auxType = auxType->auxType;
          if ( auxType == nullptr )
            goto LABEL_14;
        }
      }
      v10 = 1;
LABEL_15:
      if ( v10 != 0 )
        ++v5;
      ++v6;
      ++v8;
      if ( v6 >= num )
        goto LABEL_18;
    }
LABEL_14:
    v10 = 0;
    goto LABEL_15;
  }
LABEL_18:
  if ( v5 > list->size )
    idList<idStr,3>::Resize(this: list, newsize: v5);
  v12 = 0;
  if ( *p_num > 0 )
  {
    p_types = &this->types;
    for ( i = 0; ; ++i )
    {
      v15 = &p_types->list[i];
      v16 = *v15;
      if ( (*v15)->type != ev_object )
        break;
      if ( v16 != &type_object )
      {
        v18 = v16->auxType;
        if ( v18 == nullptr )
          break;
        while ( v18 != &type_object )
        {
          v18 = v18->auxType;
          if ( v18 == nullptr )
            goto LABEL_28;
        }
      }
      v17 = 1;
LABEL_29:
      if ( v17 != 0 )
      {
        idStr::idStr(this: v19, text: (*v15)->name.data);
        idList<idStr,5>::Append(this: list, obj: v19);
        idStr::FreeData(this: v19);
      }
      if ( ++v12 >= *p_num )
        return;
    }
LABEL_28:
    v17 = 0;
    goto LABEL_29;
  }
}


// ========================================================================
// __unwind$499671
// EA  : 0x82E9E168
// RVA : 0x00E9E168
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_499671()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?AddDefToNameList@idProgram@@QAAXPAVidVarDef@@PBD@Z
// EA  : 0x82E9E198
// RVA : 0x00E9E198
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::AddDefToNameList(idProgram *this, idVarDef *def, const char *name)
{
  idHashIndex *p_varDefNameHash; // r30
  int KeyForString; // r23
  int v8; // r29
  idList<idVarDefName *,58> *p_varDefNames; // r26
  int v10; // r28
  idStr *v11; // r3
  idStr *v12; // r29
  int v13; // r3
  int v14; // r29
  int indexSize; // r11
  int v16; // r7
  idVarDefName *v17; // r10
  idStr *v18; // [sp+50h] [-60h] BYREF

  p_varDefNameHash = &this->varDefNameHash;
  KeyForString = idHashIndex::GenerateKeyForString(this: &this->varDefNameHash, string: name, caseSensitive: true);
  v8 = p_varDefNameHash->hash[p_varDefNameHash->lookupMask & p_varDefNameHash->hashMask & KeyForString];
  if ( v8 == -1 )
  {
LABEL_7:
    v11 = (idStr *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                     size: 0x24u,
                     tag: TAG_SCRIPT,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
    v12 = v11;
    v18 = v11;
    if ( v11 != nullptr )
    {
      v11->len = 0;
      v11->allocedAndFlag = 20;
      v11->data = v11->baseBuffer;
      v11->baseBuffer[0] = 0;
      idStr::operator=(this: v11, text: name);
      v12[1].len = 0;
    }
    else
    {
      v12 = nullptr;
    }
    v18 = v12;
    p_varDefNames = &this->varDefNames;
    v13 = idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->varDefNames,
            obj: (encounterGroupRole_t *)&v18);
    v14 = v13;
    indexSize = p_varDefNameHash->indexSize;
    if ( p_varDefNameHash->hash == idHashIndex::INVALID_INDEX )
    {
      if ( v13 >= indexSize )
        indexSize = v13 + 1;
      idHashIndex::Allocate(this: p_varDefNameHash, newHashSize: p_varDefNameHash->hashSize, newIndexSize: indexSize);
    }
    else if ( v13 >= indexSize )
    {
      idHashIndex::ResizeIndex(this: p_varDefNameHash, newIndexSize: v13 + 1);
    }
    v10 = v14;
    v16 = p_varDefNameHash->hashMask & KeyForString;
    p_varDefNameHash->indexChain[v14] = p_varDefNameHash->hash[v16];
    p_varDefNameHash->hash[v16] = v14;
  }
  else
  {
    p_varDefNames = &this->varDefNames;
    while ( 1 )
    {
      v10 = v8;
      if ( idStr::Cmp(s1: p_varDefNames->list[v8]->name.data, s2: name) == 0 )
        break;
      v8 = p_varDefNameHash->indexChain[p_varDefNameHash->lookupMask & v8];
      if ( v8 == -1 )
        goto LABEL_7;
    }
  }
  v17 = p_varDefNames->list[v10];
  def->name = v17;
  def->next = v17->defs;
  v17->defs = def;
}


// ========================================================================
// __unwind$499778_0
// EA  : 0x82E9E35C
// RVA : 0x00E9E35C
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_499778_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 80), tag: TAG_SCRIPT);
}


// ========================================================================
// __unwind$499811
// EA  : 0x82E9E388
// RVA : 0x00E9E388
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_499811()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 176 + 80));
}


// ========================================================================
// ?FinishCompilation@idProgram@@QAAXXZ
// EA  : 0x82E9E3B0
// RVA : 0x00E9E3B0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::FinishCompilation(idProgram *this)
{
  int num; // r10
  int v3; // r6
  int v4; // r29
  int v5; // r4
  idList<unsigned char,37> *p_variableDefaults; // r30
  int numVariables; // r29
  int size; // r11
  int i; // r11

  num = this->fileList.num;
  v3 = this->statements.num;
  v4 = this->varDefs.num;
  v5 = this->types.num;
  this->top_functions = this->functions.num;
  this->top_statements = v3;
  this->top_types = v5;
  p_variableDefaults = (idList<unsigned char,37> *)&this->variableDefaults;
  this->top_defs = v4;
  this->top_files = num;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->variableDefaults);
  numVariables = this->numVariables;
  if ( numVariables <= p_variableDefaults->size
    || (unsigned __int8)idList<unsigned char,25>::Resize(this: p_variableDefaults, newsize: this->numVariables) != 0 )
  {
    size = p_variableDefaults->size;
    if ( numVariables < size )
      size = numVariables;
    p_variableDefaults->num = size;
  }
  for ( i = 0; i < this->numVariables; ++i )
    p_variableDefaults->list[i] = this->variables[i];
}


// ========================================================================
// ?RegisterDecl@idProgram@@QAA?AV?$idIndex@HW4invalidScriptDecl_t@@@@PBVidDecl@@@Z
// EA  : 0x82E9E4B8
// RVA : 0x00E9E4B8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idProgram *__fastcall idProgram::RegisterDecl(
        idProgram *this,
        idIndex<int,enum invalidScriptDecl_t> *result,
        idSpawnArea::GeneratedPosition *decl)
{
  idProgram *v3; // r29
  idVarDef *v5; // r10
  int value; // r9
  int v7; // r11
  idList<idSpawnArea::GeneratedPosition *,5> *v8; // r31
  int value_high; // r4
  int size; // r11
  signed int granularity; // r10
  int v12; // r4
  int v13; // r11
  int num; // r11
  idVarDef *v15; // r11

  v3 = this;
  v5 = nullptr;
  value = result[135255].value;
  if ( value <= 0 )
  {
LABEL_5:
    v8 = (idList<idSpawnArea::GeneratedPosition *,5> *)&result[135254];
    if ( result[135254].value == 0 )
    {
      value_high = SHIWORD(result[135257].value);
      if ( value_high <= 0 )
        value_high = 1;
      if ( (unsigned __int8)idList<idNavSpline *,5>::Resize(this: v8, newsize: value_high) == 0 )
        goto LABEL_12;
    }
    size = v8->size;
    if ( v8->num == size )
    {
      if ( forceIdListsToReallocateEveryAppend )
      {
        if ( (unsigned __int8)idList<idNavSpline *,5>::Resize(this: v8, newsize: size + 1) == 0 )
        {
LABEL_12:
          v3->returnDef = (idVarDef *)-1;
          return v3;
        }
      }
      else
      {
        granularity = v8->granularity;
        if ( v8->granularity != 0 )
        {
          v13 = size + granularity;
          __twllei(granularity, 0);
          __twlgei(granularity & ~(__ROL4__(v13, 1) - 1), 0xFFFFFFFF);
          if ( (unsigned __int8)idList<idNavSpline *,5>::Resize(this: v8, newsize: v13 - v13 % granularity) == 0 )
          {
            v3->returnDef = (idVarDef *)-1;
            return v3;
          }
        }
        else
        {
          v12 = 2 * size;
          if ( 2 * size >= size )
          {
            if ( v12 == 0 )
              v12 = 1;
          }
          else
          {
            v12 = 0x7FFFFFFF;
          }
          if ( (unsigned __int8)idList<idNavSpline *,5>::Resize(this: v8, newsize: v12) == 0 )
          {
            v3->returnDef = (idVarDef *)-1;
            return v3;
          }
        }
      }
    }
    num = v8->num;
    if ( num >= v8->size )
    {
      v15 = (idVarDef *)(num - 1);
      this = v3;
    }
    else
    {
      this = v3;
      v8->list[num] = decl;
      v15 = (idVarDef *)v8->num;
      v8->num = (int)&v15->num + 1;
    }
    v3->returnDef = v15;
    return this;
  }
  v7 = 0;
  while ( *(idSpawnArea::GeneratedPosition **)(v7 + result[135254].value) != decl )
  {
    v5 = (idVarDef *)((char *)v5 + 1);
    v7 += 4;
    if ( (int)v5 >= value )
      goto LABEL_5;
  }
  this->returnDef = v5;
  return this;
}


// ========================================================================
// ??0idTypeDef@@QAA@ABV0@@Z
// EA  : 0x82E9E898
// RVA : 0x00E9E898
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idTypeDef *__fastcall idTypeDef::idTypeDef(idTypeDef *this, const idTypeDef *other)
{
  this->name.len = 0;
  this->name.allocedAndFlag = 20;
  this->name.data = this->name.baseBuffer;
  this->name.baseBuffer[0] = 0;
  this->parmTypes.list = nullptr;
  this->parmTypes.granularity = 0;
  this->parmTypes.memTag = 58;
  this->parmTypes.listStatic = 0;
  this->parmTypes.size = 0;
  this->parmTypes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->parmTypes);
  this->parmNames.granularity = 0;
  this->parmNames.memTag = 58;
  this->parmNames.listStatic = 0;
  this->parmNames.list = nullptr;
  this->parmNames.size = 0;
  this->parmNames.num = 0;
  this->functions.list = nullptr;
  this->functions.granularity = 0;
  this->functions.memTag = 58;
  this->functions.listStatic = 0;
  this->functions.size = 0;
  this->functions.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->functions);
  this->parmEditableFlags.list = nullptr;
  this->parmEditableFlags.granularity = 0;
  this->parmEditableFlags.memTag = 58;
  this->parmEditableFlags.listStatic = 0;
  this->parmEditableFlags.size = 0;
  this->parmEditableFlags.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->parmEditableFlags);
  this->parmComments.granularity = 0;
  this->parmComments.memTag = 58;
  this->parmComments.listStatic = 0;
  this->parmComments.list = nullptr;
  this->parmComments.size = 0;
  this->parmComments.num = 0;
  idTypeDef::operator=(this, other);
  return this;
}


// ========================================================================
// __unwind$500230
// EA  : 0x82E9E990
// RVA : 0x00E9E990
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_500230()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 8));
}


// ========================================================================
// __unwind$500231
// EA  : 0x82E9E9BC
// RVA : 0x00E9E9BC
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_500231()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 48));
}


// ========================================================================
// __unwind$500232
// EA  : 0x82E9E9E8
// RVA : 0x00E9E9E8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_500232()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 144 + 164) + 64));
}


// ========================================================================
// __unwind$500233
// EA  : 0x82E9EA14
// RVA : 0x00E9EA14
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_500233()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 80));
}


// ========================================================================
// __unwind$500234
// EA  : 0x82E9EA40
// RVA : 0x00E9EA40
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_500234()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 96));
}


// ========================================================================
// __unwind$500235
// EA  : 0x82E9EA6C
// RVA : 0x00E9EA6C
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_500235()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 144 + 164) + 112));
}


// ========================================================================
// ?AddFunctionParm@idTypeDef@@QAAXPAV1@PBD@Z
// EA  : 0x82E9EA98
// RVA : 0x00E9EA98
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idTypeDef::AddFunctionParm(
        idTypeDef *this,
        idTypeDef *parmtype,
        const char *name,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idTypeDef *a14)
{
  etype_t type; // r11
  idStr *v17; // r3
  _BYTE v18[8]; // [sp+50h] [-20h] BYREF

  type = this->type;
  a14 = parmtype;
  if ( type != ev_function )
  {
    strncpy(
      dest: idException::error,
      source: "idTypeDef::AddFunctionParm : tried to add parameter on non-function type",
      count: 0x800u);
    CxxThrowException(pExceptionObject: v18, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->parmTypes,
    obj: (encounterGroupRole_t *)&a14);
  v17 = idList<idStr,72>::Alloc(this: (idList<idStr,72> *)&this->parmNames);
  idStr::operator=(this: v17, text: name);
}


// ========================================================================
// ?AllocType@idProgram@@QAAPAVidTypeDef@@AAV2@@Z
// EA  : 0x82E9EB30
// RVA : 0x00E9EB30
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idTypeDef *__fastcall idProgram::AllocType(idProgram *this, idTypeDef *type)
{
  idTypeDef *v4; // r3
  idTypeDef *v5; // r30
  idTypeDef *v7; // [sp+50h] [-30h] BYREF

  v4 = (idTypeDef *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x80u,
                      tag: TAG_SCRIPT,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  v7 = v4;
  if ( v4 != nullptr )
    v5 = idTypeDef::idTypeDef(this: v4, other: type);
  else
    v5 = nullptr;
  v7 = v5;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->types,
    obj: (encounterGroupRole_t *)&v7);
  return v5;
}


// ========================================================================
// __unwind$500362_0
// EA  : 0x82E9EBB0
// RVA : 0x00E9EBB0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_500362_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_SCRIPT);
}


// ========================================================================
// ?GetType@idProgram@@QAAPAVidTypeDef@@AAV2@_N@Z
// EA  : 0x82E9EBE0
// RVA : 0x00E9EBE0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idTypeDef *__fastcall idProgram::GetType(idProgram *this, idTypeDef *type, bool allocate)
{
  int v5; // r29
  int v6; // r30
  idTypeDef **list; // r28
  idTypeDef *v8; // r31
  char *data; // r10
  char *v10; // r11
  int v11; // r9
  int v12; // r9
  bool v13; // zf

  v5 = this->types.num - 1;
  if ( v5 < 0 )
  {
LABEL_9:
    if ( allocate )
      return idProgram::AllocType(this, type);
    else
      return nullptr;
  }
  else
  {
    v6 = v5;
    list = this->types.list;
    while ( 1 )
    {
      v8 = list[v6];
      if ( (unsigned __int8)idTypeDef::MatchesType(this: v8, matchtype: type) != 0 )
      {
        data = type->name.data;
        v10 = v8->name.data;
        do
        {
          v11 = (unsigned __int8)*v10;
          v13 = v11 == 0;
          v12 = v11 - (unsigned __int8)*data;
          if ( v13 )
            break;
          ++v10;
          ++data;
        }
        while ( v12 == 0 );
        if ( v12 == 0 )
          return list[v5];
      }
      --v5;
      --v6;
      if ( v5 < 0 )
        goto LABEL_9;
    }
  }
}


// ========================================================================
// ?AllocDef@idProgram@@QAAPAVidVarDef@@PAVidTypeDef@@PBDPAV2@H_N3@Z
// EA  : 0x82E9ECB0
// RVA : 0x00E9ECB0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idVarDef *__fastcall idProgram::AllocDef(
        idProgram *this,
        idTypeDef *type,
        const char *name,
        idVarDef *scope,
        const int size,
        bool constant,
        const bool isTypeDeclaration)
{
  int v7; // r29
  idVarDef *v15; // r3
  idVarDef *v16; // r28
  __int64 v17; // r8
  __int64 v18; // r6
  idTypeDef *v19; // r10
  char v20; // r11
  idTypeDef *v21; // r11
  int v22; // r11
  varEval_t::<unnamed_type_value> v23; // r11
  char v24; // r11
  idTypeDef *v25; // r11
  void **p_cp; // r26
  char *v27; // r11
  __int64 v28; // r10
  char v29; // r11
  idTypeDef *v30; // r11
  int v31; // r11
  va *v32; // r3
  idTypeDef *v33; // r9
  char *v34; // r25
  const char *v35; // r11
  const char *v36; // r10
  int v37; // r9
  int v38; // r9
  bool v39; // zf
  varEval_t::<unnamed_type_value> v40; // r11
  idTypeDef *typeDef; // r11
  char v42; // r11
  idTypeDef *auxType; // r11
  idTypeDef *v44; // r29
  int v45; // r6
  idVarDef *v46; // r27
  idVarDef *v47; // r3
  varEval_t::<unnamed_type_value> v48; // r10
  idVarDef *v49; // r27
  idVarDef *v50; // r29
  int v52; // [sp+8h] [-1158h]
  int v53; // [sp+Ch] [-1154h]
  int v54; // [sp+10h] [-1150h]
  int v55; // [sp+14h] [-114Ch]
  int v56; // [sp+18h] [-1148h]
  int v57; // [sp+1Ch] [-1144h]
  int v58; // [sp+50h] [-1110h] BYREF
  encounterGroupRole_t v59[3]; // [sp+54h] [-110Ch] BYREF
  idStr v60; // [sp+60h] [-1100h] BYREF
  idTypeDef v61; // [sp+80h] [-10E0h] BYREF
  va v62; // [sp+100h] [-1060h] BYREF

  v7 = 0;
  v60.len = 0;
  v60.allocedAndFlag = 20;
  v60.data = v60.baseBuffer;
  v60.baseBuffer[0] = 0;
  v15 = (idVarDef *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x20u,
                      tag: TAG_SCRIPT,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  if ( v15 != nullptr )
  {
    v15->typeDef = type;
    v16 = v15;
    v15->num = 0;
    v15->scope = nullptr;
    v15->numUsers = 0;
    v15->initialized = uninitialized;
    v15->value.value.i = 0;
    v15->name = nullptr;
    v15->next = nullptr;
  }
  else
  {
    v16 = nullptr;
  }
  v16->scope = scope;
  v59[0] = (encounterGroupRole_t)v16;
  v16->numUsers = 1;
  v16->num = idList<idAnimWebBlendTree *,5>::Append(
               this: (idList<enum encounterGroupRole_t,5> *)&this->varDefs,
               obj: v59);
  idProgram::AddDefToNameList(this, def: v16, name);
  v59[0] = (encounterGroupRole_t)type->type;
  if ( v59[0] == ROLE_THROW || v59[0] == ROLE_MAX && idTypeDef::FieldType(this: type)->type == ev_vector )
  {
    v35 = name;
    v36 = "<RESULT>";
    do
    {
      v37 = *(unsigned __int8 *)v35;
      v39 = v37 == 0;
      v38 = v37 - *(unsigned __int8 *)v36;
      if ( v39 )
        break;
      ++v35;
      ++v36;
    }
    while ( v38 == 0 );
    if ( v38 == 0 )
    {
      v40.cp = (char *)scope->value.value;
      v59[0] = (encounterGroupRole_t)&v16->value;
      v16->value.value.i = *(_DWORD *)(v40.i + 24);
      v16->initialized = stackVariable;
      *(_DWORD *)(scope->value.value.i + 24) += type->size;
      goto LABEL_60;
    }
    typeDef = scope->typeDef;
    if ( typeDef->type == ev_object )
    {
      if ( typeDef == &type_object )
      {
LABEL_52:
        v42 = 1;
        goto LABEL_57;
      }
      auxType = typeDef->auxType;
      if ( auxType != nullptr )
      {
        while ( auxType != &type_object )
        {
          auxType = auxType->auxType;
          if ( auxType == nullptr )
            goto LABEL_56;
        }
        goto LABEL_52;
      }
    }
LABEL_56:
    v42 = 0;
LABEL_57:
    if ( v42 != 0 )
    {
      idTypeDef::idTypeDef(this: &v61, etype: ev_field, edef: nullptr, ename: "float field", esize: 0, aux: &type_float);
      v44 = idProgram::GetType(this, type: &v61, allocate: true);
      v45 = scope->typeDef->size;
      v59[0] = (encounterGroupRole_t)&v16->value;
      v16->value.value.i = v45;
      idStr::Format(this: &v60, fmt: "%s_x", v16->name->name.data);
      v46 = idProgram::AllocDef(this, type: v44, name: v60.data, scope, size: 1, constant, isTypeDeclaration: false);
      idStr::Format(this: &v60, fmt: "%s_y", v16->name->name.data);
      v47 = idProgram::AllocDef(this, type: v44, name: v60.data, scope, size: 1, constant, isTypeDeclaration: false);
      v48.cp = (char *)v46->value.value;
      v49 = v47;
      v47->value.value.i = v48.i + type_float.size;
      idStr::Format(this: &v60, fmt: "%s_z", v16->name->name.data);
      idProgram::AllocDef(this, type: v44, name: v60.data, scope, size: 1, constant, isTypeDeclaration: false)->value.value.i = v49->value.value.i + type_float.size;
      idTypeDef::~idTypeDef(this: &v61);
    }
    else
    {
      idStr::Format(this: &v60, fmt: "%s_x", v16->name->name.data);
      v50 = idProgram::AllocDef(
              this,
              type: &type_float,
              name: v60.data,
              scope,
              size: 1,
              constant,
              isTypeDeclaration: false);
      idStr::Format(this: &v60, fmt: "%s_y", v16->name->name.data);
      idProgram::AllocDef(this, type: &type_float, name: v60.data, scope, size: 1, constant, isTypeDeclaration: false);
      idStr::Format(this: &v60, fmt: "%s_z", v16->name->name.data);
      idProgram::AllocDef(this, type: &type_float, name: v60.data, scope, size: 1, constant, isTypeDeclaration: false);
      v16->value.value.i = v50->value.value.i;
      v16->initialized = v50->initialized;
    }
    goto LABEL_60;
  }
  v19 = scope->typeDef;
  if ( v19->type == ev_object )
  {
    if ( v19 == &type_object )
    {
LABEL_9:
      v20 = 1;
      goto LABEL_14;
    }
    v21 = v19->auxType;
    if ( v21 != nullptr )
    {
      while ( v21 != &type_object )
      {
        v21 = v21->auxType;
        if ( v21 == nullptr )
          goto LABEL_13;
      }
      goto LABEL_9;
    }
  }
LABEL_13:
  v20 = 0;
LABEL_14:
  if ( v20 != 0 )
  {
    v22 = v19->size;
    v59[0] = (encounterGroupRole_t)&v16->value;
    v16->value.value.i = v22;
    goto LABEL_60;
  }
  if ( v19 != nullptr && v19->type == ev_function )
  {
    v23.cp = (char *)scope->value.value;
    v59[0] = (encounterGroupRole_t)&v16->value;
    v16->value.value.i = *(_DWORD *)(v23.i + 24);
    v16->initialized = stackVariable;
    if ( type->type == ev_object )
    {
      if ( type == &type_object )
      {
LABEL_20:
        v24 = 1;
        goto LABEL_25;
      }
      v25 = type->auxType;
      if ( v25 != nullptr )
      {
        while ( v25 != &type_object )
        {
          v25 = v25->auxType;
          if ( v25 == nullptr )
            goto LABEL_24;
        }
        goto LABEL_20;
      }
    }
LABEL_24:
    v24 = 0;
LABEL_25:
    if ( v24 != 0 )
      *(_DWORD *)(scope->value.value.i + 24) += type_object.size * size;
    else
      *(_DWORD *)(scope->value.value.i + 24) += type->size * size;
    goto LABEL_60;
  }
  p_cp = (void **)&v16->value.value.cp;
  v27 = (char *)this + this->numVariables;
  v59[0] = (encounterGroupRole_t)&v16->value;
  v16->value.value.i = (int)(v27 + 216);
  LODWORD(v17) = v16->typeDef->size;
  LODWORD(v28) = v17 * size;
  if ( type->type == ev_object )
  {
    if ( type == &type_object )
    {
LABEL_30:
      v29 = 1;
      goto LABEL_35;
    }
    v30 = type->auxType;
    if ( v30 != nullptr )
    {
      while ( v30 != &type_object )
      {
        v30 = v30->auxType;
        if ( v30 == nullptr )
          goto LABEL_34;
      }
      goto LABEL_30;
    }
  }
LABEL_34:
  v29 = 0;
LABEL_35:
  if ( v29 != 0 && !isTypeDeclaration )
    LODWORD(v28) = type_object.size * size;
  HIDWORD(v28) = 0x10000;
  v31 = this->numVariables + v28;
  this->numVariables = v31;
  if ( v31 > 0x10000 )
  {
    HIDWORD(v18) = 0x10000;
    v32 = va::va(
            this: &v62,
            fmt: "Exceeded global memory size (%d bytes)",
            a3: v18,
            a4: v17,
            a5: v28,
            a6: v52,
            a7: v53,
            a8: v54,
            a9: v55,
            a10: v56,
            a11: v57);
    strncpy(dest: idException::error, source: v32->buffer, count: 0x800u);
    CxxThrowException(pExceptionObject: &v58, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  memset(Dst: *p_cp, Val: 0, Size: v16->typeDef->size * size);
  v33 = v16->typeDef;
  if ( v33 != nullptr && v33->type == ev_list && size > 0 )
  {
    do
    {
      v34 = (char *)*p_cp;
      --size;
      *(_DWORD *)&v34[v7] = idGameLocal::CreateScriptList(this: gameLocal)->id;
      v7 += 4;
    }
    while ( size != 0 );
  }
LABEL_60:
  idStr::FreeData(this: &v60);
  return v16;
}


// ========================================================================
// $LN249
// EA  : 0x82E9F2E8
// RVA : 0x00E9F2E8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _LN249()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4448 + 96));
}


// ========================================================================
// __unwind$500449
// EA  : 0x82E9F310
// RVA : 0x00E9F310
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_500449()
{
  int v0; // r12

  idTypeDef::~idTypeDef(this: (idTypeDef *)(v0 - 4448 + 128));
}


// ========================================================================
// ?AllocStatement@idProgram@@QAAAAUstatement_t@@XZ
// EA  : 0x82E9F338
// RVA : 0x00E9F338
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

aas2Cluster_t *__fastcall idProgram::AllocStatement(idProgram *this, int a2, __int64 a3)
{
  __int64 v3; // r8
  va *v4; // r3
  int v6; // [sp+8h] [-1068h]
  int v7; // [sp+Ch] [-1064h]
  int v8; // [sp+10h] [-1060h]
  int v9; // [sp+14h] [-105Ch]
  int v10; // [sp+18h] [-1058h]
  int v11; // [sp+1Ch] [-1054h]
  _BYTE v12[16]; // [sp+50h] [-1020h] BYREF
  va v13; // [sp+60h] [-1010h] BYREF

  LODWORD(v3) = 377084;
  HIDWORD(a3) = this->statements.size;
  HIDWORD(v3) = this->statements.num;
  if ( SHIDWORD(v3) >= SHIDWORD(a3) )
  {
    v4 = va::va(
           this: &v13,
           fmt: "Exceeded maximum allowed number of statements (%d)",
           a3,
           a4: v3,
           a5: 0x5C10000050000LL,
           a6: v6,
           a7: v7,
           a8: v8,
           a9: v9,
           a10: v10,
           a11: v11);
    strncpy(dest: idException::error, source: v4->buffer, count: 0x800u);
    CxxThrowException(pExceptionObject: v12, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  return idList<idPlayerCoverScore_t,5>::Alloc(this: (idList<aas2Cluster_t,37> *)&this->statements);
}


// ========================================================================
// ?ReturnDecl@idProgram@@QAAXPBVidDecl@@@Z
// EA  : 0x82E9F3C0
// RVA : 0x00E9F3C0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::ReturnDecl(idProgram *this, idSpawnArea::GeneratedPosition *decl)
{
  int v3; // [sp+50h] [-20h] BYREF

  idProgram::RegisterDecl(this: (idProgram *)&v3, result: (idIndex<int,enum invalidScriptDecl_t> *)this, decl);
  *this->returnDef->value.value.ip = v3;
}


// ========================================================================
// ?RegisterDecl@idProgram@@QAA?AV?$idIndex@HW4invalidScriptDecl_t@@@@PBD0@Z
// EA  : 0x82E9F408
// RVA : 0x00E9F408
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idProgram *__fastcall idProgram::RegisterDecl(
        idProgram *this,
        idIndex<int,enum invalidScriptDecl_t> *result,
        const char *declName,
        const char *declTypeName)
{
  char v8; // r11
  unsigned __int8 v9; // r31
  int v10; // r27
  int v11; // r30
  int v12; // r28
  idDeclInfo *v13; // r31
  idSpawnArea::GeneratedPosition *v14; // r5

  if ( declTypeName == nullptr || (v8 = 0, *declTypeName == 0) )
    v8 = 1;
  v9 = v8;
  v10 = declManager->GetNumDeclTypes(this: declManager);
  v11 = 0;
  if ( v10 <= 0 )
  {
LABEL_12:
    this->returnDef = (idVarDef *)-1;
    return this;
  }
  v12 = v9;
  while ( 1 )
  {
    v13 = declManager->GetDeclType_2(this: declManager, a2: v11);
    if ( v12 != 0 || idStr::Cmp(s1: declTypeName, s2: v13->name) == 0 )
      break;
LABEL_11:
    if ( ++v11 >= v10 )
      goto LABEL_12;
  }
  if ( declName == nullptr
    || (v14 = (idSpawnArea::GeneratedPosition *)idDeclInfo::FindWithInheritance(
                                                  this: v13,
                                                  name: declName,
                                                  makeDefault: false)) == nullptr )
  {
    if ( v12 == 0 )
      goto LABEL_12;
    goto LABEL_11;
  }
  idProgram::RegisterDecl(this, result, decl: v14);
  return this;
}


// ========================================================================
// ?FreeData@idProgram@@QAAXXZ
// EA  : 0x82E9F708
// RVA : 0x00E9F708
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::FreeData(idProgram *this)
{
  int v2; // r26
  int v3; // r27
  function_t *v4; // r30
  idStr *p_name; // r28
  char *data; // r11
  int *list; // r4
  idStr *p_filename; // r26
  char *v9; // r11
  idProgram::idFileInfo *v10; // r27
  int size; // r30
  idProgram::idFileInfo *v12; // r28
  idStaticList<statement_t,10240> *p_statements; // r30
  char **p_functions; // r30

  idThreadManager::Restart(this: &this->threadManager);
  idList<idVarDef *,58>::DeleteContents(this: &this->varDefs);
  idList<idVarDefName *,58>::DeleteContents(this: (idList<idMapBrushSide *,5> *)&this->varDefNames);
  idHashIndex::Free(this: &this->varDefNameHash);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->referencedDecls);
  this->returnDef = nullptr;
  this->returnStringDef = nullptr;
  this->sysDef = nullptr;
  idList<idTypeDef *,58>::DeleteContents(this: &this->types);
  this->filenum = 0;
  this->numVariables = 0;
  memset(Dst: this->variables, Val: 0, Size: sizeof(this->variables));
  v2 = 0;
  if ( this->functions.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->functions.list[v3];
      p_name = &v4->name;
      v4->eventdef = nullptr;
      v4->def = nullptr;
      v4->type = nullptr;
      v4->firstStatement = 0;
      v4->numStatements = 0;
      v4->parmTotal = 0;
      v4->locals = 0;
      v4->filenum = 0;
      if ( v4->name.allocedAndFlag >= 0 )
      {
        idStr::FreeData(this: &v4->name);
        v4->name.allocedAndFlag = 20;
        v4->name.data = v4->name.baseBuffer;
        p_name->len = 0;
        v4->name.baseBuffer[0] = 0;
      }
      else
      {
        data = v4->name.data;
        p_name->len = 0;
        *data = 0;
      }
      if ( v4->parmSize.listStatic == 0 || v4->parmSize.listStatic == 2 )
      {
        list = v4->parmSize.list;
        if ( list != nullptr )
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        v4->parmSize.list = nullptr;
        v4->parmSize.size = 0;
      }
      ++v2;
      v4->parmSize.num = 0;
      ++v3;
    }
    while ( v2 < this->functions.num );
  }
  p_filename = &this->filename;
  if ( this->filename.allocedAndFlag >= 0 )
  {
    idStr::FreeData(this: &this->filename);
    this->filename.allocedAndFlag = 20;
    this->filename.data = this->filename.baseBuffer;
    p_filename->len = 0;
    this->filename.baseBuffer[0] = 0;
  }
  else
  {
    v9 = this->filename.data;
    p_filename->len = 0;
    *v9 = 0;
  }
  if ( this->fileList.listStatic == 0 || this->fileList.listStatic == 2 )
  {
    v10 = this->fileList.list;
    if ( v10 != nullptr )
    {
      size = this->fileList.size;
      if ( size > 0 )
      {
        v12 = this->fileList.list;
        do
        {
          idStr::FreeData(this: &v12->fileName);
          --size;
          ++v12;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    }
    this->fileList.list = nullptr;
    this->fileList.size = 0;
  }
  this->fileList.num = 0;
  p_statements = &this->statements;
  if ( this->statements.listStatic == 0 || this->statements.listStatic == 2 )
  {
    if ( p_statements->list != nullptr )
      idMem::Free(this: &mem, ptr: p_statements->list, align: ALIGN_16);
    p_statements->list = nullptr;
    this->statements.size = 0;
  }
  this->statements.num = 0;
  p_functions = (char **)&this->functions;
  if ( this->functions.listStatic == 0 || this->functions.listStatic == 2 )
  {
    if ( *p_functions != nullptr )
      idListArrayDelete<function_t>(ptr: *p_functions, num: this->functions.size);
    *p_functions = nullptr;
    this->functions.size = 0;
  }
  this->functions.num = 0;
  this->top_statements = 0;
  this->top_types = 0;
  this->top_functions = 0;
  this->top_defs = 0;
  this->top_files = 0;
  this->compileFlags = 0;
  idStr::operator=(this: &this->filename, text: &byte_8200D768);
  idStr::operator=(this: &this->errMsg, text: &byte_8200D768);
}


// ========================================================================
// ?BeginCompilation@idProgram@@QAAXXZ
// EA  : 0x82E9FAD8
// RVA : 0x00E9FAD8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::BeginCompilation(idProgram *this)
{
  __int64 v2; // r6
  int v3; // r4
  aas2Cluster_t *v4; // [sp+50h] [-30h]

  idProgram::FreeData(this);
  v4 = idProgram::AllocStatement(this, a2: v3, a3: v2);
  LOWORD(v4->firstPortal) = 0;
  BYTE1(v4->firstPortal) = 0;
  HIBYTE(v4->firstPortal) = 0;
  v4->numAreas = 0;
  v4->numReachableAreas = 0;
  v4->numPortals = 0;
  this->returnDef = idProgram::AllocDef(
                      this,
                      type: &type_vector,
                      name: "<RETURN>",
                      scope: &def_namespace,
                      size: 1,
                      constant: false,
                      isTypeDeclaration: false);
  this->returnStringDef = idProgram::AllocDef(
                            this,
                            type: &type_string,
                            name: "<RETURN>",
                            scope: &def_namespace,
                            size: 1,
                            constant: false,
                            isTypeDeclaration: false);
  this->sysDef = idProgram::AllocDef(
                   this,
                   type: &type_void,
                   name: "sys",
                   scope: &def_namespace,
                   size: 1,
                   constant: true,
                   isTypeDeclaration: true);
}


// ========================================================================
// $M501371
// EA  : 0x82E9FBD4
// RVA : 0x00E9FBD4
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _M501371()
{
  idLib::Error(fmt: "%s", idException::error);
  JUMPOUT(0x82E9FBF4);
}


// ========================================================================
// ?Restart@idProgram@@QAAXXZ
// EA  : 0x82E9FBF8
// RVA : 0x00E9FBF8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::Restart(idProgram *this)
{
  int *p_top_types; // r25
  int *p_num; // r28
  int top_types; // r31
  int v5; // r29
  idList<idTypeDef *,58> *p_types; // r26
  idTypeDef *v7; // r30
  int v8; // r31
  int size; // r11
  int *p_top_defs; // r26
  int top_defs; // r31
  int v12; // r30
  idVarDef *v13; // r4
  idVarDefName *name; // r3
  int v15; // r31
  int v16; // r11
  int *p_top_functions; // r22
  int top_functions; // r28
  int v19; // r27
  function_t *v20; // r31
  idStr *p_name; // r29
  char *data; // r11
  int *list; // r4
  int v24; // r31
  int v25; // r11
  int top_statements; // r31
  int v27; // r11
  int top_files; // r31
  int v29; // r11
  idStr *p_filename; // r31
  char *v31; // r11
  int v32; // r11
  int num; // r8

  p_top_types = &this->top_types;
  p_num = &this->types.num;
  idThreadManager::Restart(this: &this->threadManager);
  top_types = this->top_types;
  if ( top_types < this->types.num )
  {
    v5 = top_types;
    p_types = &this->types;
    do
    {
      v7 = p_types->list[v5];
      if ( v7 != nullptr )
      {
        idTypeDef::~idTypeDef(this: p_types->list[v5]);
        idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
      }
      ++top_types;
      ++v5;
    }
    while ( top_types < *p_num );
  }
  v8 = *p_top_types;
  if ( *p_top_types <= this->types.size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->types,
                          newsize: *p_top_types) != 0 )
  {
    size = this->types.size;
    if ( v8 < size )
      size = v8;
    this->types.num = size;
  }
  p_top_defs = &this->top_defs;
  top_defs = this->top_defs;
  if ( top_defs < this->varDefs.num )
  {
    v12 = top_defs;
    do
    {
      v13 = this->varDefs.list[v12];
      if ( v13 != nullptr )
      {
        name = v13->name;
        if ( name != nullptr )
          idVarDefName::RemoveDef(this: name, def: v13);
        idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
      }
      ++top_defs;
      ++v12;
    }
    while ( top_defs < this->varDefs.num );
  }
  v15 = *p_top_defs;
  if ( *p_top_defs <= this->varDefs.size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->varDefs,
                          newsize: *p_top_defs) != 0 )
  {
    v16 = this->varDefs.size;
    if ( v15 < v16 )
      v16 = v15;
    this->varDefs.num = v16;
  }
  p_top_functions = &this->top_functions;
  top_functions = this->top_functions;
  if ( top_functions < this->functions.num )
  {
    v19 = top_functions;
    do
    {
      v20 = &this->functions.list[v19];
      p_name = &v20->name;
      v20->eventdef = nullptr;
      v20->def = nullptr;
      v20->type = nullptr;
      v20->firstStatement = 0;
      v20->numStatements = 0;
      v20->parmTotal = 0;
      v20->locals = 0;
      v20->filenum = 0;
      if ( v20->name.allocedAndFlag >= 0 )
      {
        idStr::FreeData(this: &v20->name);
        v20->name.allocedAndFlag = 20;
        v20->name.data = v20->name.baseBuffer;
        p_name->len = 0;
        v20->name.baseBuffer[0] = 0;
      }
      else
      {
        data = v20->name.data;
        p_name->len = 0;
        *data = 0;
      }
      if ( v20->parmSize.listStatic == 0 || v20->parmSize.listStatic == 2 )
      {
        list = v20->parmSize.list;
        if ( list != nullptr )
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        v20->parmSize.list = nullptr;
        v20->parmSize.size = 0;
      }
      ++top_functions;
      v20->parmSize.num = 0;
      ++v19;
    }
    while ( top_functions < this->functions.num );
  }
  v24 = *p_top_functions;
  if ( *p_top_functions <= this->functions.size
    || (unsigned __int8)idList<function_t,5>::Resize(this: &this->functions, newsize: *p_top_functions) != 0 )
  {
    v25 = this->functions.size;
    if ( v24 < v25 )
      v25 = v24;
    this->functions.num = v25;
  }
  top_statements = this->top_statements;
  if ( top_statements <= this->statements.size
    || (unsigned __int8)idList<idPlayerCoverScore_t,5>::Resize(
                          this: (idList<idPlane,37> *)&this->statements,
                          newsize: this->top_statements) != 0 )
  {
    v27 = this->statements.size;
    if ( top_statements < v27 )
      v27 = top_statements;
    this->statements.num = v27;
  }
  top_files = this->top_files;
  if ( top_files <= this->fileList.size
    || (unsigned __int8)idList<idProgram::idFileInfo,58>::Resize(this: &this->fileList, newsize: this->top_files) != 0 )
  {
    v29 = this->fileList.size;
    if ( top_files < v29 )
      v29 = top_files;
    this->fileList.num = v29;
  }
  p_filename = &this->filename;
  if ( this->filename.allocedAndFlag >= 0 )
  {
    idStr::FreeData(this: &this->filename);
    this->filename.allocedAndFlag = 20;
    this->filename.data = this->filename.baseBuffer;
    p_filename->len = 0;
    this->filename.baseBuffer[0] = 0;
  }
  else
  {
    v31 = this->filename.data;
    p_filename->len = 0;
    *v31 = 0;
  }
  this->filenum = 0;
  v32 = 0;
  num = this->variableDefaults.num;
  this->numVariables = num;
  if ( num > 0 )
  {
    do
    {
      this->variables[v32] = this->variableDefaults.list[v32];
      ++v32;
    }
    while ( v32 < this->numVariables );
  }
}


// ========================================================================
// ?GetFilenum@idProgram@@QAAHPBD_N@Z
// EA  : 0x82E9FFD0
// RVA : 0x00E9FFD0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

int __fastcall idProgram::GetFilenum(idProgram *this, const char *name, const bool includeFile)
{
  int v6; // r10
  int filenum; // r11
  int v8; // r29
  int v9; // r31
  int num; // r11
  idList<idProgram::idFileInfo,58> *p_fileList; // r31
  int v12; // r11
  int size; // r10
  idProgram::idFileInfo *list; // r10
  int v15; // r31

  if ( idStr::Icmp(s1: this->filename.data, s2: name) != 0
    || (v6 = this->fileList.num) == 0
    || (filenum = this->filenum) >= v6
    || idStr::Icmp(s1: this->fileList.list[filenum].fileName.data, s2: name) != 0 )
  {
    v8 = 0;
    if ( this->fileList.num > 0 )
    {
      v9 = 0;
      do
      {
        if ( idStr::Icmp(s1: this->fileList.list[v9].fileName.data, s2: name) == 0 )
          break;
        ++v8;
        ++v9;
      }
      while ( v8 < this->fileList.num );
    }
    num = this->fileList.num;
    if ( v8 >= num )
    {
      p_fileList = &this->fileList;
      idList<idProgram::idFileInfo,58>::PreAllocateWithGranularity(this: &this->fileList, newSize: num + 1);
      v12 = this->fileList.num;
      size = this->fileList.size;
      if ( v12 >= size )
      {
        v15 = (int)&p_fileList->list[size - 1];
      }
      else
      {
        list = p_fileList->list;
        this->fileList.num = v12 + 1;
        v15 = (int)&list[v12];
      }
      idStr::operator=(this: (idStr *)v15, text: name);
      *(_BYTE *)(v15 + 32) = includeFile;
    }
  }
  return this->filenum;
}


// ========================================================================
// ??1idProgram@@QAA@XZ
// EA  : 0x82EA01C8
// RVA : 0x00EA01C8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::~idProgram(idProgram *this)
{
  idProgram::idFileInfo *list; // r3

  idProgram::FreeData(this);
  idStr::FreeData(this: &this->errMsg);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->referencedDecls);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->varDefs);
  idHashIndex::Free(this: &this->varDefNameHash);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->varDefNames);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->types);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->statements);
  idStaticList<function_t,3072>::~idStaticList<function_t,3072>(this: &this->functions);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->variableDefaults);
  idStr::FreeData(this: &this->filename);
  if ( this->fileList.listStatic == 0 || this->fileList.listStatic == 2 )
  {
    list = this->fileList.list;
    if ( list != nullptr )
      idListArrayDelete<idProgram::idFileInfo>(ptr: &list->fileName, num: this->fileList.size);
    this->fileList.list = nullptr;
    this->fileList.size = 0;
  }
  this->fileList.num = 0;
  idThreadManager::~idThreadManager(this: &this->threadManager);
}


// ========================================================================
// __unwind$501754
// EA  : 0x82EA02A0
// RVA : 0x00EA02A0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_501754()
{
  int v0; // r12

  idThreadManager::~idThreadManager(this: (idThreadManager *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$501755
// EA  : 0x82EA02CC
// RVA : 0x00EA02CC
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_501755()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                         + 160));
}


// ========================================================================
// __unwind$501756
// EA  : 0x82EA02F8
// RVA : 0x00EA02F8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_501756()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 176));
}


// ========================================================================
// __unwind$501757
// EA  : 0x82EA0324
// RVA : 0x00EA0324
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_501757()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 65752));
}


// ========================================================================
// __unwind$501758
// EA  : 0x82EA0358
// RVA : 0x00EA0358
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_501758()
{
  int v0; // r12

  idStaticList<function_t,3072>::~idStaticList<function_t,3072>(this: (idStaticList<function_t,3072> *)(*(_DWORD *)(v0 - 112 + 132) + 131304));
}


// ========================================================================
// __unwind$501759
// EA  : 0x82EA038C
// RVA : 0x00EA038C
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_501759()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 377080));
}


// ========================================================================
// __unwind$501760
// EA  : 0x82EA03C0
// RVA : 0x00EA03C0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_501760()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 540936));
}


// ========================================================================
// __unwind$501761
// EA  : 0x82EA03F4
// RVA : 0x00EA03F4
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_501761()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 540952));
}


// ========================================================================
// __unwind$501762
// EA  : 0x82EA0428
// RVA : 0x00EA0428
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_501762()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 540968));
}


// ========================================================================
// __unwind$501763
// EA  : 0x82EA045C
// RVA : 0x00EA045C
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_501763()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 541000));
}


// ========================================================================
// __unwind$501764
// EA  : 0x82EA0490
// RVA : 0x00EA0490
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_501764()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 541016));
}


// ========================================================================
// __unwind$501765
// EA  : 0x82EA04C4
// RVA : 0x00EA04C4
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_501765()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 541060));
}


// ========================================================================
// ?AllocFunction@idProgram@@QAAAAVfunction_t@@PAVidVarDef@@@Z
// EA  : 0x82EA0648
// RVA : 0x00EA0648
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

function_t *__fastcall idProgram::AllocFunction(idProgram *this, idStr *def, __int64 a3)
{
  __int64 v5; // r8
  va *v6; // r3
  function_t *v7; // r30
  idTypeDef *v8; // r10
  idVarDef *v9; // r3
  int v11; // [sp+8h] [-10A8h]
  int v12; // [sp+Ch] [-10A4h]
  int v13; // [sp+10h] [-10A0h]
  int v14; // [sp+14h] [-109Ch]
  int v15; // [sp+18h] [-1098h]
  int v16; // [sp+1Ch] [-1094h]
  int v17; // [sp+50h] [-1060h] BYREF
  int size; // [sp+54h] [-105Ch]
  idStr v19; // [sp+60h] [-1050h] BYREF
  va v20; // [sp+80h] [-1030h] BYREF

  LODWORD(v5) = 131308;
  HIDWORD(v5) = this->functions.num;
  size = this->functions.size;
  HIDWORD(a3) = size;
  if ( SHIDWORD(v5) >= size )
  {
    v6 = va::va(
           this: &v20,
           fmt: "Exceeded maximum allowed number of functions (%d)",
           a3,
           a4: v5,
           a5: 0x200F000020000LL,
           a6: v11,
           a7: v12,
           a8: v13,
           a9: v14,
           a10: v15,
           a11: v16);
    strncpy(dest: idException::error, source: v6->buffer, count: 0x800u);
    CxxThrowException(pExceptionObject: &v17, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
  }
  v7 = idList<function_t,5>::Alloc(this: &this->functions);
  v7->eventdef = nullptr;
  v7->def = (idVarDef *)def;
  v8 = *(idTypeDef **)&def->baseBuffer[8];
  v7->firstStatement = 0;
  v7->numStatements = 0;
  v7->parmTotal = 0;
  v7->locals = 0;
  v7->type = v8;
  v7->filenum = this->filenum;
  v9 = idVarDef::GlobalName(this: (idVarDef *)&v19, result: def);
  idStr::operator=(this: &v7->name, text: v9->value.value.cp);
  idStr::FreeData(this: &v19);
  def->data = (char *)v7;
  *(_DWORD *)&def->baseBuffer[4] = 2;
  return v7;
}


// ========================================================================
// $LN31_0
// EA  : 0x82EA073C
// RVA : 0x00EA073C
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _LN31_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4272 + 96));
}


// ========================================================================
// ?CompileText@idProgram@@QAA_NPBD0H@Z
// EA  : 0x82EA0770
// RVA : 0x00EA0770
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

int __fastcall idProgram::CompileText(idProgram *this, const char *source, const char *text, int flags)
{
  int *p_compileFlags; // r30
  int i; // r9
  idVarDef *v10; // r4
  idTypeDef *typeDef; // r11
  idVarDef *scope; // r11
  idTypeDef *v13; // r10
  idTypeDef *v14; // r11
  char v15; // r11
  idVarDef *cp; // r11
  int num; // r10
  int numUsers; // r10
  idVarDef *v19; // r3
  __int64 v20; // r10
  __int64 v21; // r6
  __int64 v22; // r8
  va *v23; // r3
  int v25; // [sp+8h] [-13E8h]
  int v26; // [sp+Ch] [-13E4h]
  int v27; // [sp+10h] [-13E0h]
  int v28; // [sp+14h] [-13DCh]
  int v29; // [sp+18h] [-13D8h]
  int v30; // [sp+1Ch] [-13D4h]
  _BYTE v31[4]; // [sp+50h] [-13A0h] BYREF
  idVarDef *v32; // [sp+54h] [-139Ch]
  idVarDef v33; // [sp+60h] [-1390h] BYREF
  idCompiler v34; // [sp+80h] [-1370h] BYREF
  va v35; // [sp+3A0h] [-1050h] BYREF

  p_compileFlags = &this->compileFlags;
  idCompiler::idCompiler(this: &v34);
  this->compileFlags = flags;
  idStr::operator=(this: &this->filename, text: source);
  this->filenum = idProgram::GetFilenum(this, name: source, includeFile: false);
  idCompiler::CompileFile(this: &v34, text, filename: this->filename.data, flags: *p_compileFlags);
  for ( i = 0; i < this->varDefs.num; ++i )
  {
    v10 = this->varDefs.list[i];
    typeDef = v10->typeDef;
    if ( typeDef != nullptr && typeDef->type == ev_function )
    {
      scope = v10->scope;
      v13 = scope->typeDef;
      v32 = scope;
      if ( v13 != nullptr && v13->type == ev_namespace )
        goto LABEL_13;
      v14 = scope->typeDef;
      if ( v14->type == ev_object )
      {
        while ( v14 != &type_object )
        {
          v14 = v14->auxType;
          if ( v14 == nullptr )
            goto LABEL_11;
        }
        v15 = 1;
      }
      else
      {
LABEL_11:
        v15 = 0;
      }
      if ( v15 != 0 )
      {
LABEL_13:
        cp = (idVarDef *)v10->value.value.cp;
        num = cp->num;
        v32 = cp;
        if ( num == 0 )
        {
          numUsers = cp->numUsers;
          v32 = cp;
          if ( numUsers == 0 )
          {
            v19 = idVarDef::GlobalName(this: &v33, result: (idStr *)v10);
            LODWORD(v20) = "plode - unlink clip";
            HIDWORD(v21) = v19->value.value.cp;
            v23 = va::va(
                    this: &v35,
                    fmt: "function %s was not defined",
                    a3: v21,
                    a4: v22,
                    a5: v20,
                    a6: v25,
                    a7: v26,
                    a8: v27,
                    a9: v28,
                    a10: v29,
                    a11: v30);
            strncpy(dest: idException::error, source: v23->buffer, count: 0x800u);
            v31[0] = v31[1];
            CxxThrowException(pExceptionObject: v31, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
          }
        }
      }
    }
  }
  if ( (this->compileFlags & 2) == 0 )
    idProgram::CompileStats(this);
  idStr::FreeData(this: &v34.token);
  idParser::~idParser(this: &v34.parser);
  return 1;
}


// ========================================================================
// $M502181_0
// EA  : 0x82EA0970
// RVA : 0x00EA0970
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void *_M502181_0()
{
  int v0; // r12
  int v1; // r29

  v1 = *(_DWORD *)(v0 - 5104 + 5124);
  idStr::operator=(this: (idStr *)(v1 + 541060), text: idException::error);
  if ( (*(_DWORD *)(v1 + 541056) & 1) != 0 )
  {
    idLib::Warning(fmt: "%s", idException::error);
    return &_LN18_5;
  }
  else
  {
    idLib::Error(fmt: "%s", idException::error);
    return (void *)_M502176_1();
  }
}


// ========================================================================
// $M502176_1
// EA  : 0x82EA09E0
// RVA : 0x00EA09E0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _M502176_1()
{
  int v0; // r12

  idCompiler::~idCompiler(this: (idCompiler *)(v0 - 5104 + 128));
}


// ========================================================================
// __unwind$502025_0
// EA  : 0x82EA0A08
// RVA : 0x00EA0A08
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_502025_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5104 + 96));
}


// ========================================================================
// __unwind$502129_0
// EA  : 0x82EA0A30
// RVA : 0x00EA0A30
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_502129_0()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 5104 + 128));
}


// ========================================================================
// ?CompileFile@idProgram@@QAA_NPBDH@Z
// EA  : 0x82EA0A58
// RVA : 0x00EA0A58
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

int __fastcall idProgram::CompileFile(idProgram *this, const char *filename, const int flags)
{
  const char *v6; // r4
  const char *v7; // r3
  char v9; // r31
  char *v10; // [sp+50h] [-30h] BYREF

  if ( fileSystem->ReadFile(this: fileSystem, a2: filename, a3: (void **)&v10, a4: nullptr) < 0 )
  {
    if ( (flags & 0x10) != 0 )
      return 0;
    v6 = filename;
    if ( (flags & 1) != 0 )
    {
      v7 = "Couldn't load %s";
LABEL_5:
      idLib::Warning(fmt: v7, v6);
      return 0;
    }
    idLib::Error(fmt: "Couldn't load %s\n", filename);
  }
  v9 = idProgram::CompileText(this, source: filename, text: v10, flags: flags & 0xFFFFFFEF);
  fileSystem->FreeFile(this: fileSystem, a2: v10);
  if ( g_disasm.valueInteger != 0 )
    idProgram::Disassemble(this);
  if ( v9 == 0 )
  {
    v6 = filename;
    v7 = "Compile failed in file %s.";
    if ( (flags & 1) != 0 )
      goto LABEL_5;
    idLib::Error(fmt: "Compile failed in file %s.", filename);
  }
  return 1;
}


// ========================================================================
// ?Startup@idProgram@@QAAXPBD_N@Z
// EA  : 0x82EA0B60
// RVA : 0x00EA0B60
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __fastcall idProgram::Startup(idProgram *this, const char *defaultScript, const bool errorsAsWarnings)
{
  idLib::Printf(fmt: "Initializing scripts\n");
  idThreadManager::Restart(this: &this->threadManager);
  idProgram::BeginCompilation(this);
  if ( defaultScript != nullptr && *defaultScript != 0 )
    idProgram::CompileFile(this, filename: defaultScript, flags: errorsAsWarnings | 2);
  idProgram::CompileStats(this);
  idProgram::FinishCompilation(this);
}


// ========================================================================
// ??0idProgram@@QAA@XZ
// EA  : 0x82EA0BE8
// RVA : 0x00EA0BE8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

idProgram *__fastcall idProgram::idProgram(idProgram *this)
{
  idThreadManager::idThreadManager(this: &this->threadManager);
  this->fileList.granularity = 0;
  this->fileList.memTag = 58;
  this->fileList.listStatic = 0;
  this->fileList.list = nullptr;
  this->fileList.size = 0;
  this->fileList.num = 0;
  this->filename.len = 0;
  this->filename.allocedAndFlag = 20;
  this->filename.data = this->filename.baseBuffer;
  this->filename.baseBuffer[0] = 0;
  this->variableDefaults.size = 0x10000;
  this->variableDefaults.num = 0;
  this->variableDefaults.granularity = 1;
  this->variableDefaults.list = this->variableDefaults.staticList;
  this->variableDefaults.memTag = 5;
  this->variableDefaults.listStatic = 1;
  idStaticList<function_t,3072>::idStaticList<function_t,3072>(this: &this->functions);
  this->statements.size = 10240;
  this->statements.num = 0;
  this->statements.granularity = 1;
  this->statements.list = this->statements.staticList;
  this->statements.memTag = 5;
  this->statements.listStatic = 1;
  this->types.list = nullptr;
  this->types.granularity = 0;
  this->types.memTag = 58;
  this->types.listStatic = 0;
  this->types.size = 0;
  this->types.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->types);
  this->varDefNames.list = nullptr;
  this->varDefNames.granularity = 0;
  this->varDefNames.memTag = 58;
  this->varDefNames.listStatic = 0;
  this->varDefNames.size = 0;
  this->varDefNames.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->varDefNames);
  this->varDefNameHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->varDefNameHash, initialHashSize: 1024, initialIndexSize: 1024);
  this->varDefs.list = nullptr;
  this->varDefs.granularity = 0;
  this->varDefs.memTag = 58;
  this->varDefs.listStatic = 0;
  this->varDefs.size = 0;
  this->varDefs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->varDefs);
  this->referencedDecls.list = nullptr;
  this->referencedDecls.granularity = 0;
  this->referencedDecls.memTag = 58;
  this->referencedDecls.listStatic = 0;
  this->referencedDecls.size = 0;
  this->referencedDecls.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->referencedDecls);
  this->errMsg.allocedAndFlag = 20;
  this->errMsg.data = this->errMsg.baseBuffer;
  this->errMsg.len = 0;
  this->errMsg.baseBuffer[0] = 0;
  idProgram::FreeData(this);
  return this;
}


// ========================================================================
// __unwind$502424_0
// EA  : 0x82EA0D8C
// RVA : 0x00EA0D8C
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_502424_0()
{
  int v0; // r12

  idThreadManager::~idThreadManager(this: (idThreadManager *)(*(_DWORD *)(v0 - 160 + 180) + 8));
}


// ========================================================================
// __unwind$502425_0
// EA  : 0x82EA0DB8
// RVA : 0x00EA0DB8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_502425_0()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                         + 160));
}


// ========================================================================
// __unwind$502426_0
// EA  : 0x82EA0DE4
// RVA : 0x00EA0DE4
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_502426_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 176));
}


// ========================================================================
// __unwind$502427_0
// EA  : 0x82EA0E10
// RVA : 0x00EA0E10
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_502427_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 65752));
}


// ========================================================================
// __unwind$502428_0
// EA  : 0x82EA0E44
// RVA : 0x00EA0E44
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_502428_0()
{
  int v0; // r12

  idStaticList<function_t,3072>::~idStaticList<function_t,3072>(this: (idStaticList<function_t,3072> *)(*(_DWORD *)(v0 - 160 + 180) + 131304));
}


// ========================================================================
// __unwind$502429_0
// EA  : 0x82EA0E78
// RVA : 0x00EA0E78
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_502429_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 377080));
}


// ========================================================================
// __unwind$502430_0
// EA  : 0x82EA0EAC
// RVA : 0x00EA0EAC
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_502430_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 540936));
}


// ========================================================================
// __unwind$502431_0
// EA  : 0x82EA0EE0
// RVA : 0x00EA0EE0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_502431_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 540952));
}


// ========================================================================
// __unwind$502432_0
// EA  : 0x82EA0F14
// RVA : 0x00EA0F14
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_502432_0()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 160 + 180) + 540968));
}


// ========================================================================
// __unwind$502433_0
// EA  : 0x82EA0F48
// RVA : 0x00EA0F48
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_502433_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 541000));
}


// ========================================================================
// __unwind$502434_0
// EA  : 0x82EA0F7C
// RVA : 0x00EA0F7C
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_502434_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 541016));
}


// ========================================================================
// __unwind$502435_0
// EA  : 0x82EA0FB0
// RVA : 0x00EA0FB0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void _unwind_502435_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 541060));
}


// ========================================================================
// `dynamic initializer for 'type_void''
// EA  : 0x83391D10
// RVA : 0x01391D10
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_void__()
{
  idTypeDef::idTypeDef(this: &type_void, etype: ev_void, edef: &def_void, ename: "void", esize: 0, aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_void__);
}


// ========================================================================
// `dynamic initializer for 'type_scriptevent''
// EA  : 0x83391D60
// RVA : 0x01391D60
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_scriptevent__()
{
  idTypeDef::idTypeDef(
    this: &type_scriptevent,
    etype: ev_scriptevent,
    edef: &def_scriptevent,
    ename: "scriptevent",
    esize: 4,
    aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_scriptevent__);
}


// ========================================================================
// `dynamic initializer for 'type_namespace''
// EA  : 0x83391DB0
// RVA : 0x01391DB0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_namespace__()
{
  idTypeDef::idTypeDef(
    this: &type_namespace,
    etype: ev_namespace,
    edef: &def_namespace,
    ename: "namespace",
    esize: 4,
    aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_namespace__);
}


// ========================================================================
// `dynamic initializer for 'type_string''
// EA  : 0x83391E00
// RVA : 0x01391E00
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_string__()
{
  idTypeDef::idTypeDef(
    this: &type_string,
    etype: ev_string,
    edef: &def_string,
    ename: "string",
    esize: 256,
    aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_string__);
}


// ========================================================================
// `dynamic initializer for 'type_float''
// EA  : 0x83391E50
// RVA : 0x01391E50
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_float__()
{
  idTypeDef::idTypeDef(this: &type_float, etype: ev_float, edef: &def_float, ename: "float", esize: 4, aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_float__);
}


// ========================================================================
// `dynamic initializer for 'type_vector''
// EA  : 0x83391EA0
// RVA : 0x01391EA0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_vector__()
{
  idTypeDef::idTypeDef(
    this: &type_vector,
    etype: ev_vector,
    edef: &def_vector,
    ename: "vector",
    esize: 12,
    aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_vector__);
}


// ========================================================================
// `dynamic initializer for 'type_quat''
// EA  : 0x83391EF0
// RVA : 0x01391EF0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_quat__()
{
  idTypeDef::idTypeDef(this: &type_quat, etype: ev_quat, edef: &def_quat, ename: "quat", esize: 16, aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_quat__);
}


// ========================================================================
// `dynamic initializer for 'type_entity''
// EA  : 0x83391F40
// RVA : 0x01391F40
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_entity__()
{
  idTypeDef::idTypeDef(this: &type_entity, etype: ev_entity, edef: &def_entity, ename: "entity", esize: 4, aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_entity__);
}


// ========================================================================
// `dynamic initializer for 'type_field''
// EA  : 0x83391F90
// RVA : 0x01391F90
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_field__()
{
  idTypeDef::idTypeDef(this: &type_field, etype: ev_field, edef: &def_field, ename: "field", esize: 4, aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_field__);
}


// ========================================================================
// `dynamic initializer for 'type_function''
// EA  : 0x83391FE0
// RVA : 0x01391FE0
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_function__()
{
  idTypeDef::idTypeDef(
    this: &type_function,
    etype: ev_function,
    edef: &def_function,
    ename: "function",
    esize: 4,
    aux: &type_void);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_function__);
}


// ========================================================================
// `dynamic initializer for 'type_virtualfunction''
// EA  : 0x83392038
// RVA : 0x01392038
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_virtualfunction__()
{
  idTypeDef::idTypeDef(
    this: &type_virtualfunction,
    etype: ev_virtualfunction,
    edef: &def_virtualfunction,
    ename: "virtual function",
    esize: 4,
    aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_virtualfunction__);
}


// ========================================================================
// `dynamic initializer for 'type_pointer''
// EA  : 0x83392088
// RVA : 0x01392088
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_pointer__()
{
  idTypeDef::idTypeDef(
    this: &type_pointer,
    etype: ev_pointer,
    edef: &def_pointer,
    ename: "pointer",
    esize: 4,
    aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_pointer__);
}


// ========================================================================
// `dynamic initializer for 'type_object''
// EA  : 0x833920D8
// RVA : 0x013920D8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_object__()
{
  idTypeDef::idTypeDef(this: &type_object, etype: ev_object, edef: &def_object, ename: "object", esize: 4, aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_object__);
}


// ========================================================================
// `dynamic initializer for 'type_jumpoffset''
// EA  : 0x83392128
// RVA : 0x01392128
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_jumpoffset__()
{
  idTypeDef::idTypeDef(
    this: &type_jumpoffset,
    etype: ev_jumpoffset,
    edef: &def_jumpoffset,
    ename: "<jump>",
    esize: 4,
    aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_jumpoffset__);
}


// ========================================================================
// `dynamic initializer for 'type_argsize''
// EA  : 0x83392178
// RVA : 0x01392178
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_argsize__()
{
  idTypeDef::idTypeDef(
    this: &type_argsize,
    etype: ev_argsize,
    edef: &def_argsize,
    ename: "<argsize>",
    esize: 4,
    aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_argsize__);
}


// ========================================================================
// `dynamic initializer for 'type_integer''
// EA  : 0x833921C8
// RVA : 0x013921C8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_integer__()
{
  idTypeDef::idTypeDef(this: &type_integer, etype: ev_integer, edef: &def_list, ename: "int", esize: 4, aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_integer__);
}


// ========================================================================
// `dynamic initializer for 'type_list''
// EA  : 0x83392218
// RVA : 0x01392218
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_list__()
{
  idTypeDef::idTypeDef(this: &type_list, etype: ev_list, edef: &def_list, ename: "list", esize: 4, aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_list__);
}


// ========================================================================
// `dynamic initializer for 'type_varArgs''
// EA  : 0x83392268
// RVA : 0x01392268
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_varArgs__()
{
  idTypeDef::idTypeDef(
    this: &type_varArgs,
    etype: ev_varArgs,
    edef: &def_varArgs,
    ename: "varArgs",
    esize: 4,
    aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_varArgs__);
}


// ========================================================================
// `dynamic initializer for 'type_decl''
// EA  : 0x833922B8
// RVA : 0x013922B8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__type_decl__()
{
  idTypeDef::idTypeDef(this: &type_decl, etype: ev_decl, edef: &def_decl, ename: "decl", esize: 4, aux: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__type_decl__);
}


// ========================================================================
// `dynamic initializer for 'def_void''
// EA  : 0x83392308
// RVA : 0x01392308
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_void__()
{
  def_void.value.value.i = 0;
  def_void.name = nullptr;
  def_void.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_void__);
}


// ========================================================================
// `dynamic initializer for 'def_scriptevent''
// EA  : 0x83392338
// RVA : 0x01392338
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_scriptevent__()
{
  def_scriptevent.value.value.i = 0;
  def_scriptevent.name = nullptr;
  def_scriptevent.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_scriptevent__);
}


// ========================================================================
// `dynamic initializer for 'def_namespace''
// EA  : 0x83392368
// RVA : 0x01392368
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_namespace__()
{
  def_namespace.value.value.i = 0;
  def_namespace.name = nullptr;
  def_namespace.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_namespace__);
}


// ========================================================================
// `dynamic initializer for 'def_string''
// EA  : 0x83392398
// RVA : 0x01392398
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_string__()
{
  def_string.value.value.i = 0;
  def_string.name = nullptr;
  def_string.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_string__);
}


// ========================================================================
// `dynamic initializer for 'def_float''
// EA  : 0x833923C8
// RVA : 0x013923C8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_float__()
{
  def_float.value.value.i = 0;
  def_float.name = nullptr;
  def_float.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_float__);
}


// ========================================================================
// `dynamic initializer for 'def_vector''
// EA  : 0x833923F8
// RVA : 0x013923F8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_vector__()
{
  def_vector.value.value.i = 0;
  def_vector.name = nullptr;
  def_vector.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_vector__);
}


// ========================================================================
// `dynamic initializer for 'def_quat''
// EA  : 0x83392428
// RVA : 0x01392428
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_quat__()
{
  def_quat.value.value.i = 0;
  def_quat.name = nullptr;
  def_quat.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_quat__);
}


// ========================================================================
// `dynamic initializer for 'def_entity''
// EA  : 0x83392458
// RVA : 0x01392458
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_entity__()
{
  def_entity.value.value.i = 0;
  def_entity.name = nullptr;
  def_entity.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_entity__);
}


// ========================================================================
// `dynamic initializer for 'def_field''
// EA  : 0x83392488
// RVA : 0x01392488
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_field__()
{
  def_field.value.value.i = 0;
  def_field.name = nullptr;
  def_field.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_field__);
}


// ========================================================================
// `dynamic initializer for 'def_function''
// EA  : 0x833924B8
// RVA : 0x013924B8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_function__()
{
  def_function.value.value.i = 0;
  def_function.name = nullptr;
  def_function.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_function__);
}


// ========================================================================
// `dynamic initializer for 'def_virtualfunction''
// EA  : 0x833924E8
// RVA : 0x013924E8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_virtualfunction__()
{
  def_virtualfunction.value.value.i = 0;
  def_virtualfunction.name = nullptr;
  def_virtualfunction.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_virtualfunction__);
}


// ========================================================================
// `dynamic initializer for 'def_pointer''
// EA  : 0x83392518
// RVA : 0x01392518
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_pointer__()
{
  def_pointer.value.value.i = 0;
  def_pointer.name = nullptr;
  def_pointer.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_pointer__);
}


// ========================================================================
// `dynamic initializer for 'def_object''
// EA  : 0x83392548
// RVA : 0x01392548
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_object__()
{
  def_object.value.value.i = 0;
  def_object.name = nullptr;
  def_object.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_object__);
}


// ========================================================================
// `dynamic initializer for 'def_jumpoffset''
// EA  : 0x83392578
// RVA : 0x01392578
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_jumpoffset__()
{
  def_jumpoffset.value.value.i = 0;
  def_jumpoffset.name = nullptr;
  def_jumpoffset.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_jumpoffset__);
}


// ========================================================================
// `dynamic initializer for 'def_argsize''
// EA  : 0x833925A8
// RVA : 0x013925A8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_argsize__()
{
  def_argsize.value.value.i = 0;
  def_argsize.name = nullptr;
  def_argsize.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_argsize__);
}


// ========================================================================
// `dynamic initializer for 'def_integer''
// EA  : 0x833925D8
// RVA : 0x013925D8
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_integer__()
{
  def_integer.value.value.i = 0;
  def_integer.name = nullptr;
  def_integer.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_integer__);
}


// ========================================================================
// `dynamic initializer for 'def_list''
// EA  : 0x83392608
// RVA : 0x01392608
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_list__()
{
  def_list.value.value.i = 0;
  def_list.name = nullptr;
  def_list.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_list__);
}


// ========================================================================
// `dynamic initializer for 'def_varArgs''
// EA  : 0x83392638
// RVA : 0x01392638
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_varArgs__()
{
  def_varArgs.value.value.i = 0;
  def_varArgs.name = nullptr;
  def_varArgs.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_varArgs__);
}


// ========================================================================
// `dynamic initializer for 'def_decl''
// EA  : 0x83392668
// RVA : 0x01392668
// PDB : w:\tech5\tungsten\game\script\program.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__def_decl__()
{
  def_decl.value.value.i = 0;
  def_decl.name = nullptr;
  def_decl.next = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__def_decl__);
}

