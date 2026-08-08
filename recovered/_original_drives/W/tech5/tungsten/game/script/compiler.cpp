
// ========================================================================
// ?Warning@idCompiler@@ABAXPBDZZ
// EA  : 0x82E8A8C0
// RVA : 0x00E8A8C0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idCompiler::Warning(
        idCompiler *this,
        const char *message,
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
  char v12[1024]; // [sp+60h] [-410h] BYREF
  __int64 v13; // [sp+490h] [+20h] BYREF
  va_list va; // [sp+490h] [+20h]
  __int64 v15; // [sp+498h] [+28h]
  __int64 v16; // [sp+4A0h] [+30h]
  __int64 v17; // [sp+4A8h] [+38h]
  __int64 v18; // [sp+4B0h] [+40h]
  __int64 v19; // [sp+4B8h] [+48h]
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
  v13 = *(__int64 *)((char *)&a3 + 4);
  v15 = a3;
  v16 = *(__int64 *)((char *)&a4 + 4);
  v17 = a4;
  v18 = *(__int64 *)((char *)&a5 + 4);
  v19 = a5;
  idStr::vsnPrintf(dest: v12, size: 1023, fmt: message, argptr: va);
  idParser::Warning(this: this->parserPtr, str: "%s", v12);
}


// ========================================================================
// ?GetTypeForEventArg@idCompiler@@AAAPAVidTypeDef@@D@Z
// EA  : 0x82E8A938
// RVA : 0x00E8A938
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idTypeDef *__fastcall idCompiler::GetTypeForEventArg(idCompiler *this, char argType)
{
  idTypeDef *result; // r3

  if ( argType <= 101 )
  {
    if ( argType == 101 )
      return &type_entity;
    if ( argType > 53 )
    {
      switch ( argType )
      {
        case 'a':
          return &type_vector;
        case 'b':
          return &type_integer;
        case 'd':
          return &type_decl;
        default:
          break;
      }
      return nullptr;
    }
    if ( argType != 53 )
    {
      if ( argType > 50 )
        return nullptr;
      if ( argType < 49 )
      {
        if ( argType == 0 )
          return &type_void;
        return nullptr;
      }
    }
    return &type_string;
  }
  switch ( argType )
  {
    case 'f':
      result = &type_float;
      break;
    case 'i':
      return &type_integer;
    case 'l':
      result = &type_list;
      break;
    case 'q':
      result = &type_quat;
      break;
    case 's':
      return &type_string;
    case 'v':
      return &type_vector;
    case 'x':
      result = &type_varArgs;
      break;
    default:
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?ReadComment@idCompiler@@AAAXAAVidStr@@@Z
// EA  : 0x82E8AA78
// RVA : 0x00E8AA78
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ReadComment(idCompiler *this, idStr *comment)
{
  idParser::GetLastWhiteSpace(this: this->parserPtr, whiteSpace: comment);
  idStr::StripTrailing(this: comment, c: 10);
  idStr::StripTrailing(this: comment, c: 13);
  idStr::StripLeading(this: comment, c: 9);
  idStr::StripLeading(this: comment, string: " ");
  idStr::StripLeading(this: comment, string: "//");
  idStr::StripLeading(this: comment, string: " ");
}


// ========================================================================
// ??0idCompiler@@QAA@XZ
// EA  : 0x82E8AB10
// RVA : 0x00E8AB10
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idCompiler *__fastcall idCompiler::idCompiler(idCompiler *this)
{
  const char **i; // r29
  unsigned int PunctuationId; // r3

  idParser::idParser(this: &this->parser, flags: 0);
  this->token.len = 0;
  this->token.allocedAndFlag = 20;
  this->token.data = this->token.baseBuffer;
  this->token.baseBuffer[0] = 0;
  this->token.floatvalue = -3.4028235e38;
  this->token.intvalue = 0;
  this->token.whiteSpaceStart_p = nullptr;
  this->token.whiteSpaceEnd_p = nullptr;
  this->token.next = nullptr;
  this->callthread = false;
  this->parserPtr = &this->parser;
  this->loopDepth = 0;
  this->eof = false;
  this->braceDepth = 0;
  this->immediateType = nullptr;
  this->basetype = nullptr;
  this->currentLineNumber = 0;
  this->currentFileNumber = 0;
  this->errorCount = 0;
  this->compileFlags = 0;
  this->scope = &def_namespace;
  this->immediate._int = 0;
  this->immediate.vector[1] = 0.0;
  this->immediate.vector[2] = 0.0;
  this->immediate.quat[3] = 0.0;
  memset(Dst: idCompiler::punctuationValid, Val: 0, Size: sizeof(idCompiler::punctuationValid));
  for ( i = (const char **)idCompiler::punctuation; *i != nullptr; ++i )
  {
    PunctuationId = idParser::GetPunctuationId(this: this->parserPtr, p: *i);
    if ( PunctuationId < 0x100 )
      idCompiler::punctuationValid[PunctuationId] = true;
  }
  return this;
}


// ========================================================================
// __unwind$490805
// EA  : 0x82E8AC20
// RVA : 0x00E8AC20
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_490805()
{
  int v0; // r12

  idParser::~idParser(this: *(idParser **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$490806
// EA  : 0x82E8AC48
// RVA : 0x00E8AC48
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_490806()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 660));
}


// ========================================================================
// ?Error@idCompiler@@ABAXPBDZZ
// EA  : 0x82E8AC78
// RVA : 0x00E8AC78
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __noreturn idCompiler::Error(
        idCompiler *this,
        const char *message,
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
  _BYTE v12[4]; // [sp+50h] [-420h] BYREF
  va_list v13; // [sp+54h] [-41Ch]
  char v14[1024]; // [sp+60h] [-410h] BYREF
  __int64 v15; // [sp+490h] [+20h] BYREF
  va_list va; // [sp+490h] [+20h]
  __int64 v17; // [sp+498h] [+28h]
  __int64 v18; // [sp+4A0h] [+30h]
  __int64 v19; // [sp+4A8h] [+38h]
  __int64 v20; // [sp+4B0h] [+40h]
  __int64 v21; // [sp+4B8h] [+48h]
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
  v15 = *(__int64 *)((char *)&a3 + 4);
  v17 = a3;
  v18 = *(__int64 *)((char *)&a4 + 4);
  v19 = a4;
  v20 = *(__int64 *)((char *)&a5 + 4);
  v21 = a5;
  va_copy(v13, va);
  idStr::vsnPrintf(dest: v14, size: 1023, fmt: message, argptr: va);
  idParser::Error(this: this->parserPtr, str: "%s", v14);
  strncpy(dest: idException::error, source: v14, count: 0x800u);
  CxxThrowException(pExceptionObject: v12, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
}


// ========================================================================
// ?FindFreeResultDef@idCompiler@@AAAPAVidVarDef@@PAVidTypeDef@@PAV2@PBV2@2@Z
// EA  : 0x82E8AD08
// RVA : 0x00E8AD08
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::FindFreeResultDef(
        idCompiler *this,
        idTypeDef *type,
        idVarDef *scope,
        const idVarDef *a,
        const idVarDef *b)
{
  idVarDef *result; // r3

  result = idProgram::GetDefList(this: &gameLocal->program, name: "<RESULT>");
  if ( result == nullptr )
    return idProgram::AllocDef(
             this: &gameLocal->program,
             type,
             name: "<RESULT>",
             scope,
             size: 1,
             constant: false,
             isTypeDeclaration: false);
  while ( result->typeDef != type || result->scope != scope || result->numUsers <= 1 || result == a || result == b )
  {
    result = result->next;
    if ( result == nullptr )
      return idProgram::AllocDef(
               this: &gameLocal->program,
               type,
               name: "<RESULT>",
               scope,
               size: 1,
               constant: false,
               isTypeDeclaration: false);
  }
  return result;
}


// ========================================================================
// ?FindImmediate@idCompiler@@AAAPAVidVarDef@@PAVidTypeDef@@PBTeval_s@@PBD@Z
// EA  : 0x82E8ADC0
// RVA : 0x00E8ADC0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::FindImmediate(
        idCompiler *this,
        bfx::Planner3D *type,
        const eval_s *eval,
        const char *string)
{
  bfx::Space *TypeDef; // r25
  idVarDef *DefList; // r31
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  bool v13; // cr58
  float *fp; // r11
  float *v15; // r11
  _DWORD *ip; // r11
  idVarDef *v17; // r31
  int v19; // [sp+8h] [-B8h]
  int v20; // [sp+Ch] [-B4h]
  int v21; // [sp+10h] [-B0h]
  int v22; // [sp+14h] [-ACh]
  int v23; // [sp+18h] [-A8h]
  int v24; // [sp+1Ch] [-A4h]

  TypeDef = idScriptObject::GetTypeDef(this: type);
  DefList = idProgram::GetDefList(this: &gameLocal->program, name: "<IMMEDIATE>");
  if ( DefList != nullptr )
  {
    while ( 1 )
    {
      if ( (bfx::Planner3D *)DefList->typeDef == type )
      {
        switch ( (unsigned int)TypeDef )
        {
          case 3u:
            v13 = idStr::Cmp(s1: DefList->value.value.cp, s2: string) == 0;
            break;
          case 4u:
            v13 = *DefList->value.value.fp == eval->_float;
            break;
          case 5u:
          case 9u:
          case 0x12u:
            ip = DefList->value.value.ip;
            LODWORD(v10) = eval->_int;
            HIDWORD(v10) = *ip;
            v13 = *ip == eval->_int;
            break;
          case 6u:
            fp = DefList->value.value.fp;
            if ( *fp != eval->_float || fp[1] != eval->vector[1] )
              goto LABEL_16;
            v13 = fp[2] == eval->vector[2];
            break;
          case 7u:
            v15 = DefList->value.value.fp;
            if ( *v15 != eval->_float || v15[1] != eval->vector[1] || v15[2] != eval->vector[2] )
              goto LABEL_16;
            v13 = v15[3] == eval->quat[3];
            break;
          case 0xBu:
          case 0xEu:
          case 0xFu:
            LODWORD(v10) = eval->_int;
            v13 = DefList->value.value.i == eval->_int;
            break;
          default:
            idCompiler::Error(
              this,
              message: "weird immediate type",
              a3: v12,
              a4: v11,
              a5: v10,
              a6: v19,
              a7: v20,
              a8: v21,
              a9: v22,
              a10: v23,
              a11: v24);
        }
        if ( v13 )
          break;
      }
LABEL_16:
      DefList = DefList->next;
      if ( DefList == nullptr )
        goto LABEL_17;
    }
    ++DefList->numUsers;
    return DefList;
  }
  else
  {
LABEL_17:
    v17 = idProgram::AllocDef(
            this: &gameLocal->program,
            (idTypeDef *)type,
            name: "<IMMEDIATE>",
            scope: &def_namespace,
            size: 1,
            constant: true,
            isTypeDeclaration: false);
    if ( idScriptObject::GetTypeDef(this: type) == (bfx::Space *)3 )
      idVarDef::SetString(this: v17, string, constant: true);
    else
      idVarDef::SetValue(this: v17, _value: eval, constant: true);
    return v17;
  }
}


// ========================================================================
// ?VirtualFunctionConstant@idCompiler@@AAAPAVidVarDef@@PAV2@@Z
// EA  : 0x82E8AFF0
// RVA : 0x00E8AFF0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::VirtualFunctionConstant(idCompiler *this, idVarDef *func)
{
  __int64 v2; // r11
  idVarDef *scope; // r9
  const function_t *up; // r4
  __int64 v7; // r6
  __int64 v8; // r10
  __int64 v9; // r8
  int v11; // [sp+8h] [-98h]
  int v12; // [sp+Ch] [-94h]
  int v13; // [sp+10h] [-90h]
  int v14; // [sp+14h] [-8Ch]
  int v15; // [sp+18h] [-88h]
  int v16; // [sp+1Ch] [-84h]
  eval_s v17; // [sp+70h] [-30h] BYREF

  HIDWORD(v2) = &v17;
  scope = func->scope;
  LODWORD(v2) = 0;
  up = func->value.value.up;
  *(_QWORD *)HIDWORD(v2) = v2;
  *(_QWORD *)(HIDWORD(v2) + 8) = v2;
  v17._int = idTypeDef::GetFunctionNumber(this: scope->typeDef, func: up);
  if ( v17._int < 0 )
  {
    HIDWORD(v7) = idVarDef::Name(this: func);
    idCompiler::Error(
      this,
      message: "Function '%s' not found ",
      a3: v7,
      a4: v9,
      a5: v8,
      a6: v11,
      a7: v12,
      a8: v13,
      a9: v14,
      a10: v15,
      a11: v16);
  }
  return idCompiler::FindImmediate(
           this,
           type: (bfx::Planner3D *)&type_virtualfunction,
           eval: &v17,
           string: &byte_8200D768);
}


// ========================================================================
// ?SizeConstant@idCompiler@@AAAPAVidVarDef@@H@Z
// EA  : 0x82E8B088
// RVA : 0x00E8B088
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::SizeConstant(idCompiler *this, int size)
{
  __int64 v2; // r11
  eval_s v4; // [sp+50h] [-20h] BYREF

  LODWORD(v2) = 0;
  HIDWORD(v2) = size;
  v4.vector[1] = 0.0;
  *((_QWORD *)&v4._int + 1) = v2;
  v4._int = size;
  return idCompiler::FindImmediate(this, type: (bfx::Planner3D *)&type_argsize, eval: &v4, string: &byte_8200D768);
}


// ========================================================================
// ?OptimizeOpcode@idCompiler@@AAAPAVidVarDef@@PBUopcode_t@@PAV2@1@Z
// EA  : 0x82E8B0D8
// RVA : 0x00E8B0D8
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idVarDef *__fastcall idCompiler::OptimizeOpcode(
        idCompiler *this,
        const opcode_t *op,
        __int64 var_b,
        double a4,
        double a5,
        long double a6)
{
  idVarDef *v7; // r30
  idVarDef *v8; // r29
  __int128 v9; // r10 OVERLAPPED
  idTypeDef *v10; // r31
  float *v11; // r10
  float *v12; // r9
  double v13; // fp8
  double v14; // fp6
  float *v15; // r10
  float *v16; // r9
  double v17; // fp8
  double v18; // fp6
  float *v19; // r10
  float *v20; // r9
  double v21; // fp9
  double v22; // fp8
  float *v23; // r10
  float *v24; // r9
  double v25; // fp9
  double v26; // fp8
  float *v27; // r11
  signed int v28; // r11
  long double v29; // fp2
  long double v30; // fp2
  _DWORD *v31; // r10
  unsigned int *v32; // r9
  unsigned int v33; // r3
  int v34; // r11
  int v35; // r7
  int v36; // r7
  int v37; // r7
  int v38; // r7
  int v39; // r7
  int v40; // r7
  int v41; // r7
  int v42; // r7
  float *v43; // r11
  double v44; // fp13
  int v45; // r11
  float *v46; // r10
  double v47; // fp10
  double v48; // fp9
  float *v49; // r11
  float *v50; // r10
  double v51; // fp13
  unsigned __int8 v52; // r11
  float *v53; // r11
  float *v54; // r10
  double v55; // fp13
  unsigned __int8 v56; // r11
  int v57; // r7
  double v58; // fp10
  int v59; // r7
  int v60; // r7
  int v61; // r7
  int v62; // r7
  float *v63; // r9
  int v64; // r7
  __int64 v65; // fp13
  int v66; // r7
  int v67; // r11
  int v68; // r11
  int v70; // [sp+8h] [-C8h]
  int v71; // [sp+Ch] [-C4h]
  int v72; // [sp+10h] [-C0h]
  int v73; // [sp+14h] [-BCh]
  int v74; // [sp+18h] [-B8h]
  int v75; // [sp+1Ch] [-B4h]
  eval_s v76; // [sp+80h] [-50h] BYREF

  v7 = (idVarDef *)HIDWORD(var_b);
  v8 = (idVarDef *)var_b;
  if ( HIDWORD(var_b) == 0
    || (_DWORD)var_b == 0
    || *(_DWORD *)(HIDWORD(var_b) + 16) != 2
    || *(_DWORD *)(var_b + 16) != 2 )
  {
    return nullptr;
  }
  DWORD1(v9) = idCompiler::opcodes;
  DWORD2(v9) = 0;
  HIDWORD(v9) = (char *)op - (char *)idCompiler::opcodes;
  *(_QWORD *)&v76.stringPtr = *(_QWORD *)((char *)&v9 + 4);
  *((_QWORD *)&v76._int + 1) = *(_QWORD *)((char *)&v9 + 4);
  switch ( op - idCompiler::opcodes )
  {
    case 9:
      v57 = ~(int)**(float **)(HIDWORD(var_b) + 4);
      v58 = (float)*(__int64 *)((char *)&var_b - 4);
      goto LABEL_100;
    case 10:
      v10 = &type_integer;
      v76._int = ~**(_DWORD **)(HIDWORD(var_b) + 4);
      break;
    case 11:
      *((double *)&v29 + 1) = **(float **)(var_b + 4);
      *(double *)&v29 = **(float **)(HIDWORD(var_b) + 4);
      v30 = fmod(dX: v29, dY: a6);
      v76._float = *(double *)&v30;
      goto LABEL_101;
    case 12:
      v31 = *(_DWORD **)(HIDWORD(var_b) + 4);
      v32 = *(unsigned int **)(var_b + 4);
      v10 = &type_integer;
      v33 = *v32 & ~(__ROL4__(*v31, 1) - 1);
      v34 = *v31 % (int)*v32;
      __twllei(*v32, 0);
      __twlgei(v33, 0xFFFFFFFF);
      v76._int = v34;
      break;
    case 13:
      v76._float = **(float **)(HIDWORD(var_b) + 4) * **(float **)(var_b + 4);
      goto LABEL_101;
    case 14:
      v76._float = (float)(**(float **)(var_b + 4) * **(float **)(HIDWORD(var_b) + 4))
                 + (float)((float)(*(float *)(*(_DWORD *)(HIDWORD(var_b) + 4) + 8)
                                 * *(float *)(*(_DWORD *)(var_b + 4) + 8))
                         + (float)(*(float *)(*(_DWORD *)(HIDWORD(var_b) + 4) + 4)
                                 * *(float *)(*(_DWORD *)(var_b + 4) + 4)));
      goto LABEL_101;
    case 15:
      v10 = &type_integer;
      v76._int = **(_DWORD **)(HIDWORD(var_b) + 4) * **(_DWORD **)(var_b + 4);
      break;
    case 16:
      v19 = *(float **)(var_b + 4);
      v20 = *(float **)(HIDWORD(var_b) + 4);
      v10 = &type_vector;
      v21 = (float)(v19[1] * *v20);
      v22 = (float)(v19[2] * *v20);
      v76._float = *v20 * *v19;
      v76.vector[1] = v21;
      v76.vector[2] = v22;
      break;
    case 17:
      v23 = *(float **)(HIDWORD(var_b) + 4);
      v24 = *(float **)(var_b + 4);
      v10 = &type_vector;
      v25 = (float)(v23[1] * *v24);
      v26 = (float)(v23[2] * *v24);
      v76._float = *v23 * *v24;
      v76.vector[1] = v25;
      v76.vector[2] = v26;
      break;
    case 20:
      v63 = *(float **)(HIDWORD(var_b) + 4);
      v64 = **(_DWORD **)(var_b + 4);
      v65 = *(__int64 *)((char *)&var_b - 4);
      goto LABEL_99;
    case 21:
      v63 = *(float **)(var_b + 4);
      v66 = **(_DWORD **)(HIDWORD(var_b) + 4);
      v65 = *(__int64 *)((char *)&var_b - 4);
LABEL_99:
      v58 = (float)((float)v65 * *v63);
      goto LABEL_100;
    case 22:
      v76._float = **(float **)(HIDWORD(var_b) + 4) + **(float **)(var_b + 4);
      goto LABEL_101;
    case 23:
      v11 = *(float **)(var_b + 4);
      v12 = *(float **)(HIDWORD(var_b) + 4);
      v10 = &type_vector;
      v13 = (float)(v12[1] + v11[1]);
      v14 = (float)(v12[2] + v11[2]);
      v76._float = *v12 + *v11;
      v76.vector[1] = v13;
      v76.vector[2] = v14;
      break;
    case 24:
      v10 = &type_integer;
      v76._int = **(_DWORD **)(HIDWORD(var_b) + 4) + **(_DWORD **)(var_b + 4);
      break;
    case 32:
      v61 = **(_DWORD **)(var_b + 4);
      v58 = (float)((float)*(__int64 *)((char *)&var_b - 4) + **(float **)(HIDWORD(var_b) + 4));
      goto LABEL_100;
    case 33:
      v62 = **(_DWORD **)(HIDWORD(var_b) + 4);
      v58 = (float)((float)*(__int64 *)((char *)&var_b - 4) + **(float **)(var_b + 4));
      goto LABEL_100;
    case 34:
      v76._float = **(float **)(HIDWORD(var_b) + 4) - **(float **)(var_b + 4);
      goto LABEL_101;
    case 35:
      v15 = *(float **)(var_b + 4);
      v16 = *(float **)(HIDWORD(var_b) + 4);
      v10 = &type_vector;
      v17 = (float)(v16[1] - v15[1]);
      v18 = (float)(v16[2] - v15[2]);
      v76._float = *v16 - *v15;
      v76.vector[1] = v17;
      v76.vector[2] = v18;
      break;
    case 36:
      v10 = &type_integer;
      v76._int = **(_DWORD **)(HIDWORD(var_b) + 4) - **(_DWORD **)(var_b + 4);
      break;
    case 39:
      v27 = *(float **)(var_b + 4);
      LODWORD(v9) = 0x82000000;
      DWORD2(v9) = *(_DWORD *)(HIDWORD(var_b) + 4);
      if ( *v27 == 0.0 )
        idCompiler::Error(
          this,
          message: "Divide by zero",
          a3: var_b,
          a4: *(__int64 *)&v9,
          a5: v9,
          a6: v70,
          a7: v71,
          a8: v72,
          a9: v73,
          a10: v74,
          a11: v75);
      v76._float = *(float *)DWORD2(v9) / *v27;
      goto LABEL_101;
    case 40:
      v28 = **(_DWORD **)(var_b + 4);
      LODWORD(v9) = **(_DWORD **)(HIDWORD(var_b) + 4);
      if ( v28 == 0 )
        idCompiler::Error(
          this,
          message: "Divide by zero",
          a3: var_b,
          a4: *(__int64 *)&v9,
          a5: v9,
          a6: v70,
          a7: v71,
          a8: v72,
          a9: v73,
          a10: v74,
          a11: v75);
      __twllei(v28, 0);
      v76._int = (int)v9 / v28;
      v10 = &type_integer;
      __twlgei(v28 & ~(__ROL4__(v9, 1) - 1), 0xFFFFFFFF);
      break;
    case 41:
      v59 = **(_DWORD **)(var_b + 4);
      v58 = (float)((float)*(__int64 *)((char *)&var_b - 4) / **(float **)(HIDWORD(var_b) + 4));
      goto LABEL_100;
    case 42:
      v60 = **(_DWORD **)(HIDWORD(var_b) + 4);
      v58 = (float)(**(float **)(var_b + 4) / (float)*(__int64 *)((char *)&var_b - 4));
LABEL_100:
      v76._float = v58;
      goto LABEL_101;
    case 45:
      if ( **(float **)(HIDWORD(var_b) + 4) != **(float **)(var_b + 4) )
        goto LABEL_29;
      v76._int = 1;
      v10 = &type_integer;
      break;
    case 46:
      v49 = *(float **)(var_b + 4);
      v50 = *(float **)(HIDWORD(var_b) + 4);
      if ( *v50 != *v49 || v50[1] != v49[1] || (v51 = v49[2], v52 = 1, v50[2] != v51) )
        v52 = 0;
      v10 = &type_integer;
      v76._int = v52;
      break;
    case 51:
      v10 = &type_integer;
      v76._int = (_cntlzw(**(_DWORD **)(var_b + 4) - **(_DWORD **)(HIDWORD(var_b) + 4)) & 0x20) != 0;
      break;
    case 56:
      if ( **(float **)(HIDWORD(var_b) + 4) == **(float **)(var_b + 4) )
        goto LABEL_29;
      v76._int = 1;
      v10 = &type_integer;
      break;
    case 57:
      v53 = *(float **)(var_b + 4);
      v54 = *(float **)(HIDWORD(var_b) + 4);
      if ( *v54 != *v53 || v54[1] != v53[1] || (v55 = v53[2], v56 = 1, v54[2] != v55) )
        v56 = 0;
      v10 = &type_integer;
      v76._int = (_cntlzw(v56) & 0x20) != 0;
      break;
    case 62:
      v10 = &type_integer;
      v76._int = **(_DWORD **)(var_b + 4) != **(_DWORD **)(HIDWORD(var_b) + 4);
      break;
    case 67:
      if ( **(float **)(HIDWORD(var_b) + 4) > (double)**(float **)(var_b + 4) )
        goto LABEL_29;
      v76._int = 1;
      v10 = &type_integer;
      break;
    case 68:
      v10 = &type_integer;
      v76._int = (**(int **)(var_b + 4) >> 31)
               + (**(_DWORD **)(var_b + 4) >= **(_DWORD **)(HIDWORD(var_b) + 4))
               + (**(_DWORD **)(HIDWORD(var_b) + 4) >> 31);
      break;
    case 69:
      v39 = **(_DWORD **)(var_b + 4);
      if ( **(float **)(HIDWORD(var_b) + 4) > (double)(float)*(__int64 *)((char *)&var_b - 4) )
        goto LABEL_29;
      v76._int = 1;
      v10 = &type_integer;
      break;
    case 70:
      v40 = **(_DWORD **)(HIDWORD(var_b) + 4);
      if ( (float)*(__int64 *)((char *)&var_b - 4) > (double)**(float **)(var_b + 4) )
        goto LABEL_29;
      v76._int = 1;
      v10 = &type_integer;
      break;
    case 71:
      if ( **(float **)(HIDWORD(var_b) + 4) < (double)**(float **)(var_b + 4) )
        goto LABEL_29;
      v76._int = 1;
      v10 = &type_integer;
      break;
    case 72:
      v10 = &type_integer;
      v76._int = (**(int **)(HIDWORD(var_b) + 4) >> 31)
               + (**(_DWORD **)(HIDWORD(var_b) + 4) >= **(_DWORD **)(var_b + 4))
               + (**(_DWORD **)(var_b + 4) >> 31);
      break;
    case 73:
      v35 = **(_DWORD **)(var_b + 4);
      if ( **(float **)(HIDWORD(var_b) + 4) < (double)(float)*(__int64 *)((char *)&var_b - 4) )
        goto LABEL_29;
      v76._int = 1;
      v10 = &type_integer;
      break;
    case 74:
      v36 = **(_DWORD **)(HIDWORD(var_b) + 4);
      if ( (float)*(__int64 *)((char *)&var_b - 4) < (double)**(float **)(var_b + 4) )
        goto LABEL_29;
      v76._int = 1;
      v10 = &type_integer;
      break;
    case 75:
      if ( **(float **)(HIDWORD(var_b) + 4) >= (double)**(float **)(var_b + 4) )
        goto LABEL_29;
      v76._int = 1;
      v10 = &type_integer;
      break;
    case 76:
      v10 = &type_integer;
      v76._int = (((**(_DWORD **)(var_b + 4) ^ **(_DWORD **)(HIDWORD(var_b) + 4)) >= 0)
                + (**(_DWORD **)(HIDWORD(var_b) + 4) >= **(_DWORD **)(var_b + 4)))
               & 1;
      break;
    case 77:
      v41 = **(_DWORD **)(var_b + 4);
      if ( **(float **)(HIDWORD(var_b) + 4) >= (double)(float)*(__int64 *)((char *)&var_b - 4) )
        goto LABEL_29;
      v76._int = 1;
      v10 = &type_integer;
      break;
    case 78:
      v42 = **(_DWORD **)(HIDWORD(var_b) + 4);
      if ( (float)*(__int64 *)((char *)&var_b - 4) >= (double)**(float **)(var_b + 4) )
        goto LABEL_29;
      v76._int = 1;
      v10 = &type_integer;
      break;
    case 79:
      if ( **(float **)(HIDWORD(var_b) + 4) <= (double)**(float **)(var_b + 4) )
        goto LABEL_29;
      v76._int = 1;
      v10 = &type_integer;
      break;
    case 80:
      v10 = &type_integer;
      v76._int = (((**(_DWORD **)(HIDWORD(var_b) + 4) ^ **(_DWORD **)(var_b + 4)) >= 0)
                + (**(_DWORD **)(var_b + 4) >= **(_DWORD **)(HIDWORD(var_b) + 4)))
               & 1;
      break;
    case 81:
      v37 = **(_DWORD **)(var_b + 4);
      if ( **(float **)(HIDWORD(var_b) + 4) <= (double)(float)*(__int64 *)((char *)&var_b - 4) )
        goto LABEL_29;
      v76._int = 1;
      v10 = &type_integer;
      break;
    case 82:
      v38 = **(_DWORD **)(HIDWORD(var_b) + 4);
      if ( (float)*(__int64 *)((char *)&var_b - 4) <= (double)**(float **)(var_b + 4) )
        goto LABEL_29;
      v76._int = 1;
      v10 = &type_integer;
      break;
    case 83:
      v10 = &type_integer;
      v76._int = **(_DWORD **)(HIDWORD(var_b) + 4) & **(_DWORD **)(var_b + 4);
      break;
    case 84:
      v10 = &type_integer;
      v76._int = **(_DWORD **)(HIDWORD(var_b) + 4) | **(_DWORD **)(var_b + 4);
      break;
    case 85:
      if ( **(_DWORD **)(HIDWORD(var_b) + 4) != 0 && **(_DWORD **)(var_b + 4) != 0 )
      {
        v76._int = 1;
        v10 = &type_integer;
      }
      else
      {
LABEL_29:
        v76._int = 0;
        v10 = &type_integer;
      }
      break;
    case 86:
      if ( **(_DWORD **)(HIDWORD(var_b) + 4) != 0 || **(_DWORD **)(var_b + 4) != 0 )
      {
        v76._int = 1;
        v10 = &type_integer;
      }
      else
      {
        v76._int = 0;
        v10 = &type_integer;
      }
      break;
    case 176:
      v10 = &type_integer;
      v76._int = (_cntlzw(**(_DWORD **)(HIDWORD(var_b) + 4)) & 0x20) != 0;
      break;
    case 177:
      v76._float = (float)(**(float **)(HIDWORD(var_b) + 4) == 0.0);
      goto LABEL_101;
    case 178:
      v43 = *(float **)(HIDWORD(var_b) + 4);
      if ( *v43 != 0.0 || v43[1] != 0.0 || (v44 = v43[2], v45 = 1, v44 != 0.0) )
        v45 = 0;
      v76._float = (float)(unsigned int)v45;
      goto LABEL_101;
    case 182:
      v76._float = -**(float **)(HIDWORD(var_b) + 4);
      goto LABEL_101;
    case 183:
      v46 = *(float **)(HIDWORD(var_b) + 4);
      v10 = &type_vector;
      v47 = -v46[1];
      v48 = -v46[2];
      v76._float = -*v46;
      v76.vector[1] = v47;
      v76.vector[2] = v48;
      break;
    case 184:
      v10 = &type_integer;
      v76._int = -**(_DWORD **)(HIDWORD(var_b) + 4);
      break;
    case 185:
      DWORD1(v9) = **(_DWORD **)(HIDWORD(var_b) + 4);
      v76._float = (float)*(__int64 *)&v9;
LABEL_101:
      v10 = &type_float;
      break;
    case 186:
      v10 = &type_integer;
      v76._int = (int)**(float **)(HIDWORD(var_b) + 4);
      break;
    default:
      return nullptr;
  }
  v67 = v7->numUsers - 1;
  v7->numUsers = v67;
  if ( v67 <= 0 )
    idProgram::FreeDef(this: &gameLocal->program, def: v7, scope: nullptr);
  v68 = v8->numUsers - 1;
  v8->numUsers = v68;
  if ( v68 <= 0 )
    idProgram::FreeDef(this: &gameLocal->program, def: v8, scope: nullptr);
  return idCompiler::FindImmediate(this, type: (bfx::Planner3D *)v10, eval: &v76, string: &byte_8200D768);
}


// ========================================================================
// ?EmitOpcode@idCompiler@@AAAPAVidVarDef@@PBUopcode_t@@PAV2@1@Z
// EA  : 0x82E8BFD8
// RVA : 0x00E8BFD8
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::EmitOpcode(
        idCompiler *this,
        const opcode_t *op,
        __int64 var_b,
        double a4,
        double a5,
        long double a6)
{
  idVarDef *v8; // r30
  idVarDef *v9; // r28
  idVarDef *result; // r3
  const char *v11; // r3
  const char *v12; // r3
  statement_t *v13; // r31
  idVarDef *type_c; // r11
  idVarDef *FreeResultDef; // r29

  v8 = (idVarDef *)HIDWORD(var_b);
  v9 = (idVarDef *)var_b;
  result = idCompiler::OptimizeOpcode(this, op, var_b, a4, a5, a6);
  if ( result == nullptr )
  {
    if ( v8 != nullptr )
    {
      v11 = idVarDef::Name(this: v8);
      if ( idStr::Cmp(s1: v11, s2: "<RESULT>") == 0 )
        ++v8->numUsers;
    }
    if ( v9 != nullptr )
    {
      v12 = idVarDef::Name(this: v9);
      if ( idStr::Cmp(s1: v12, s2: "<RESULT>") == 0 )
        ++v9->numUsers;
    }
    v13 = idProgram::AllocStatement(this: &gameLocal->program);
    v13->linenumber = this->currentLineNumber;
    v13->file = this->currentFileNumber;
    type_c = op->type_c;
    if ( type_c == &def_void || op->rightAssociative )
    {
      FreeResultDef = nullptr;
    }
    else
    {
      FreeResultDef = idCompiler::FindFreeResultDef(this, type: type_c->typeDef, scope: this->scope, a: v8, b: v9);
      FreeResultDef->numUsers = 1;
    }
    v13->a = v8;
    v13->b = v9;
    v13->c = FreeResultDef;
    v13->op = op - idCompiler::opcodes;
    if ( op->rightAssociative )
    {
      return v8;
    }
    else
    {
      if ( g_debugScript.valueInteger != 0 )
        idLib::Printf(fmt: "EMIT: %s\n", op->name);
      return FreeResultDef;
    }
  }
  return result;
}


// ========================================================================
// ?EmitPush@idCompiler@@AAA_NPAVidVarDef@@PBVidTypeDef@@@Z
// EA  : 0x82E8C140
// RVA : 0x00E8C140
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

int __fastcall idCompiler::EmitPush(
        idCompiler *this,
        idVarDef *expression,
        bfx::Planner3D *funcArg,
        double a4,
        double a5,
        long double a6)
{
  opcode_t *i; // r30
  const char *name; // r11
  const char *v11; // r10
  int v12; // r9
  int v13; // r9
  bool v14; // zf
  bfx::Planner3D *typeDef; // r3
  bfx::Space *v16; // r31
  idTypeDef *v17; // r3
  bfx::Space *v18; // r31
  bfx::Planner3D *v19; // r3
  bfx::Space *v20; // r3
  idTypeDef *v21; // r3
  const opcode_t *v23; // r4
  __int64 v24; // r6

  for ( i = &idCompiler::opcodes[194]; i->name != nullptr; ++i )
  {
    name = i->name;
    v11 = "<PUSH>";
    do
    {
      v12 = *(unsigned __int8 *)name;
      v14 = v12 == 0;
      v13 = v12 - *(unsigned __int8 *)v11;
      if ( v14 )
        break;
      ++name;
      ++v11;
    }
    while ( v13 == 0 );
    if ( v13 != 0 )
      break;
    typeDef = (bfx::Planner3D *)i->type_a->typeDef;
    if ( typeDef != nullptr )
      v16 = idScriptObject::GetTypeDef(this: typeDef);
    else
      v16 = nullptr;
    if ( idScriptObject::GetTypeDef(this: funcArg) == v16 )
    {
      v17 = expression->typeDef;
      v18 = v17 != nullptr ? idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v17) : nullptr;
      v19 = (bfx::Planner3D *)i->type_b->typeDef;
      v20 = v19 != nullptr ? idScriptObject::GetTypeDef(this: v19) : nullptr;
      if ( v18 == v20 )
      {
        v23 = i;
        goto LABEL_23;
      }
    }
  }
  v21 = expression->typeDef;
  if ( v21 != (idTypeDef *)funcArg && !idTypeDef::Inherits(this: v21, basetype: (const idTypeDef *)funcArg) )
    return 0;
  v23 = &idCompiler::opcodes[198];
LABEL_23:
  LODWORD(v24) = 0;
  HIDWORD(v24) = expression;
  idCompiler::EmitOpcode(this, op: v23, var_b: v24, a4, a5, a6);
  return 1;
}


// ========================================================================
// ?CheckType@idCompiler@@AAAPAVidTypeDef@@XZ
// EA  : 0x82E8C280
// RVA : 0x00E8C280
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idTypeDef *__fastcall idCompiler::CheckType(idCompiler *this)
{
  idTypeDef *v2; // r31
  idTypeDef *Type; // r3

  if ( idStr::Cmp(s1: this->token.data, s2: "float") == 0 )
    return &type_float;
  if ( idStr::Cmp(s1: this->token.data, s2: "int") != 0 )
  {
    if ( idStr::Cmp(s1: this->token.data, s2: "vector") == 0 )
      return &type_vector;
    if ( idStr::Cmp(s1: this->token.data, s2: "quat") == 0 )
      return &type_quat;
    if ( idStr::Cmp(s1: this->token.data, s2: "entity") == 0 )
      return &type_entity;
    if ( idStr::Cmp(s1: this->token.data, s2: "decl") == 0 )
      return &type_decl;
    if ( idStr::Cmp(s1: this->token.data, s2: "string") == 0 )
      return &type_string;
    if ( idStr::Cmp(s1: this->token.data, s2: "void") == 0 )
      return &type_void;
    if ( idStr::Cmp(s1: this->token.data, s2: "object") == 0 )
      return &type_object;
    if ( idStr::Cmp(s1: this->token.data, s2: "boolean") != 0 )
    {
      if ( idStr::Cmp(s1: this->token.data, s2: "namespace") == 0 )
        return &type_namespace;
      if ( idStr::Cmp(s1: this->token.data, s2: "scriptEvent") == 0 )
        return &type_scriptevent;
      if ( idStr::Cmp(s1: this->token.data, s2: "list") == 0 )
        return &type_list;
      if ( idStr::Cmp(s1: this->token.data, s2: "varArgs") == 0 )
        return &type_varArgs;
      Type = idProgram::FindType(this: &gameLocal->program, name: this->token.data);
      v2 = Type;
      if ( Type != nullptr )
        return !idTypeDef::Inherits(this: Type, basetype: &type_object) ? nullptr : Type;
      return v2;
    }
  }
  return &type_integer;
}


// ========================================================================
// ?CleanUpLists@idCompiler@@AAAXPBVidVarDef@@@Z
// EA  : 0x82E8C4D8
// RVA : 0x00E8C4D8
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::CleanUpLists(idCompiler *this, idVarDef *excludeVar)
{
  int v4; // r24
  int v5; // r26
  idVarDef *v6; // r30
  bfx::Planner3D *typeDef; // r3
  const char *v8; // r3
  BOOL v9; // r29
  const char *v10; // r31
  const char *v11; // r3
  int v12; // r31
  long double v13; // fp4
  double v14; // fp2
  double v15; // fp1
  idTypeDef *v16; // r20
  const char *v17; // r19
  const char *ParmName; // r3

  v4 = 0;
  if ( idProgram::GetDefList(this: &gameLocal->program)->num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = idProgram::GetDefList(this: &gameLocal->program)->list[v5];
      if ( v6 != nullptr && v6->scope == this->scope )
      {
        typeDef = (bfx::Planner3D *)v6->typeDef;
        if ( typeDef != nullptr && idScriptObject::GetTypeDef(this: typeDef) == (bfx::Space *)16 )
        {
          v8 = idVarDef::Name(this: v6);
          if ( idStr::Icmp(s1: v8, s2: "<RESULT>") != 0 )
          {
            LOBYTE(v9) = 1;
            if ( excludeVar != nullptr )
            {
              v10 = idVarDef::Name(this: v6);
              v11 = idVarDef::Name(this: excludeVar);
              v9 = idStr::Icmp(s1: v11, s2: v10) != 0;
            }
            v12 = 0;
            if ( (int)function_t::Name(this: (idDecl *)this->scope->typeDef) > 0 )
            {
              while ( 1 )
              {
                v16 = this->scope->typeDef;
                v17 = idVarDef::Name(this: v6);
                ParmName = idTypeDef::GetParmName(this: v16, parmNumber: v12);
                if ( idStr::Icmp(s1: ParmName, s2: v17) == 0 )
                  break;
                if ( ++v12 >= (int)function_t::Name(this: (idDecl *)this->scope->typeDef) )
                  goto LABEL_15;
              }
              LOBYTE(v9) = 0;
            }
LABEL_15:
            if ( v9 )
              idCompiler::EmitOpcode(
                this,
                op: &idCompiler::opcodes[193],
                var_b: (unsigned int)v6,
                a4: v15,
                a5: v14,
                a6: v13);
          }
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < idProgram::GetDefList(this: &gameLocal->program)->num );
  }
}


// ========================================================================
// ?HtmlScriptOperators_f@idCompiler@@SAXABVidCmdArgs@@@Z
// EA  : 0x82E8C670
// RVA : 0x00E8C670
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::HtmlScriptOperators_f(const idCmdArgs *args)
{
  idFile *v2; // r3
  idFile *v3; // r29
  idFile_vtbl *v4; // r28
  const char *v5; // r3
  char *v6; // r5
  idVarDef **p_type_a; // r30
  int v8; // r24
  bfx::ObstacleImpl *typeDef; // r3
  char *v10; // r27
  char *Name; // r28
  idVarDef *v12; // r11
  const char *v13; // r8
  idStr v14[4]; // [sp+60h] [-80h] BYREF

  idStr::idStr(this: v14, text: "../docs/Editing/Script/script_operators.html");
  if ( args->argc > 1 )
  {
    idStr::operator=(this: v14, text: args->argv[1]);
    idStr::SetFileExtension(this: v14, extension: "html");
  }
  v2 = fileSystem->OpenFileWrite(this: fileSystem, a2: v14[0].data, a3: 0);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v2->Printf(
      this: v2,
      a2: "<html>\n"
      "<head>\n"
      "<title>Tungsten CVar List</title>\n"
      "<style type=\"text/css\">\n"
      "\tbody { background-color: #DDD; }\n"
      "\ttable { background-color: #FFF; border: 1px solid black; width: 100%%; }\n"
      "\ttr { border: 1px solid black; }\n"
      "\tth { horizontal-align: left; border-bottom: 1px solid black; }\n"
      "\ttd { vertical-align: top; border-top: 1px solid black; }\n"
      "</style>\n"
      "</head>\n"
      "<body>\n");
    v4 = v3->__vftable;
    v5 = Sys_DateStr(padded: true);
    v4->Printf(this: v3, a2: "<p align=\"right\">Last Updated: %s</p>\n", v5);
    if ( args->argc <= 0 )
      v6 = &byte_8200D768;
    else
      v6 = args->argv[0];
    v3->Printf(this: v3, a2: "<p>This file has been automatically generated with the '%s' console command.</p>\n", v6);
    v3->Printf(this: v3, a2: "<table>\n");
    v3->Printf(
      this: v3,
      a2: "\t<tr><th>Operator</th><th>Return Type</th><th>Precedence</th><th>Description</th></tr>\n");
    p_type_a = &idCompiler::opcodes[0].type_a;
    v8 = 212;
    while ( p_type_a[3] == nullptr )
    {
LABEL_19:
      --v8;
      p_type_a += 8;
      if ( v8 == 0 )
      {
        v3->Printf(this: v3, a2: "</table>");
        v3->Printf(this: v3, a2: "</body>\n");
        v3->Printf(this: v3, a2: "</html>\n");
        ((void (__fastcall *)(idFile *, int))v3->dtr_idFile)(a1: v3, a2: 1);
        idLib::Printf(fmt: "Wrote %s\n", v14[0].data);
        goto LABEL_21;
      }
    }
    typeDef = (bfx::ObstacleImpl *)(*p_type_a)->typeDef;
    if ( p_type_a[1] == &def_void )
    {
      v10 = &byte_8200D768;
      Name = &byte_8200D768;
      if ( *((_BYTE *)p_type_a - 4) != 0 )
      {
        Name = (char *)idFile_MTP::GetName(pObstacle: typeDef);
LABEL_15:
        v12 = p_type_a[2];
        if ( v12 == &def_void )
          v13 = "-";
        else
          v13 = (const char *)idFile_MTP::GetName(pObstacle: (bfx::ObstacleImpl *)v12->typeDef);
        v3->Printf(
          this: v3,
          a2: "\t<tr><td><b>%s %s %s</b></td><td><b>%s</b></td><td>%d</td><td>%s</td></tr>\n",
          Name,
          *(p_type_a - 4),
          v10,
          v13,
          15 - (_DWORD)*(p_type_a - 2),
          p_type_a[3]);
        goto LABEL_19;
      }
    }
    else
    {
      Name = (char *)idFile_MTP::GetName(pObstacle: typeDef);
      typeDef = (bfx::ObstacleImpl *)p_type_a[1]->typeDef;
    }
    v10 = (char *)idFile_MTP::GetName(pObstacle: typeDef);
    goto LABEL_15;
  }
  idLib::Printf(fmt: "Could not open %s!\n", v14[0].data);
LABEL_21:
  idStr::FreeData(this: v14);
}


// ========================================================================
// __unwind$492171
// EA  : 0x82E8C920
// RVA : 0x00E8C920
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_492171()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// ?JumpTo@idCompiler@@AAAPAVidVarDef@@H@Z
// EA  : 0x82E8C948
// RVA : 0x00E8C948
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::JumpTo(idCompiler *this, int jumpto)
{
  __int64 v2; // r10
  eval_s v4; // [sp+50h] [-20h] BYREF

  LODWORD(v2) = 0;
  HIDWORD(v2) = jumpto;
  *(_QWORD *)&v4.stringPtr = v2;
  *((_QWORD *)&v4._int + 1) = v2;
  v4._int = jumpto - gameLocal->program.statements.num;
  return idCompiler::FindImmediate(this, type: (bfx::Planner3D *)&type_jumpoffset, eval: &v4, string: &byte_8200D768);
}


// ========================================================================
// ?JumpFrom@idCompiler@@AAAPAVidVarDef@@H@Z
// EA  : 0x82E8C9B0
// RVA : 0x00E8C9B0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::JumpFrom(idCompiler *this, int jumpfrom)
{
  __int64 v2; // r10
  eval_s v4; // [sp+50h] [-20h] BYREF

  LODWORD(v2) = 0;
  HIDWORD(v2) = jumpfrom;
  *(_QWORD *)&v4.stringPtr = v2;
  *((_QWORD *)&v4._int + 1) = v2;
  v4._int = gameLocal->program.statements.num - jumpfrom;
  return idCompiler::FindImmediate(this, type: (bfx::Planner3D *)&type_jumpoffset, eval: &v4, string: &byte_8200D768);
}


// ========================================================================
// ?IsIncludeFile@idCompiler@@ABA_NPBD@Z
// EA  : 0x82E8CA18
// RVA : 0x00E8CA18
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

int __fastcall idCompiler::IsIncludeFile(idCompiler *this, const char *filename)
{
  int v4; // r30
  int num; // r28
  int i; // r31

  v4 = 0;
  num = this->parserPtr->dependencies.num;
  if ( num <= 0 )
    return 0;
  for ( i = 0; idStr::Icmp(s1: this->parserPtr->dependencies.list[i].fileName.data, s2: filename) != 0; ++i )
  {
    if ( ++v4 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?NextToken@idCompiler@@AAAXXZ
// EA  : 0x82E8CA98
// RVA : 0x00E8CA98
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::NextToken(idCompiler *this)
{
  int v1; // r30
  eval_s *p_immediate; // r24
  idParser *parserPtr; // r11
  idLexer *scriptstack; // r10
  const char *data; // r4
  idLexer *v7; // r10
  const char *v8; // r28
  char IsIncludeFile; // r3
  idParser *v10; // r11
  idLexer *v11; // r10
  const char *v12; // r4
  idLexer *v13; // r10
  const char *v14; // r28
  char v15; // r3
  __int64 v16; // r8
  __int64 v17; // r6
  int Filenum; // r3
  __int64 v19; // r10
  idTypeDef *typeDef; // r3
  __int64 v21; // r6
  __int64 v22; // r10
  __int64 v23; // r8
  idTypeDef *v24; // r3
  __int64 v25; // r6
  __int64 v26; // r10
  __int64 v27; // r8
  idTypeDef *v28; // r3
  __int64 v29; // r6
  __int64 v30; // r10
  __int64 v31; // r8
  idLexer *v32; // r11
  const char *v33; // r6
  float *v34; // r28
  __int64 v35; // r10
  __int64 v36; // r8
  __int64 v37; // r6
  __int64 v38; // r10
  __int64 v39; // r8
  __int64 v40; // r6
  __int64 v41; // r6
  idToken *p_token; // r3
  int subtype; // r11
  idParser *v44; // r3
  idToken *v45; // r3
  idParser *v46; // r3
  __int64 v47; // r6
  __int64 v48; // r8
  __int64 v49; // r10
  idParser *v50; // r11
  __int64 v51; // r10
  __int64 v52; // r8
  __int64 v53; // r6
  __int64 v54; // r8
  __int64 v55; // r6
  __int64 v56; // r10
  int v57; // [sp+8h] [-308h]
  int v58; // [sp+Ch] [-304h]
  int v59; // [sp+10h] [-300h]
  int v60; // [sp+14h] [-2FCh]
  int v61; // [sp+18h] [-2F8h]
  int v62; // [sp+1Ch] [-2F4h]
  idParser *v63; // [sp+70h] [-2A0h] BYREF
  idParser *v64; // [sp+74h] [-29Ch]
  idToken v65; // [sp+80h] [-290h] BYREF
  idToken v66; // [sp+D0h] [-240h] BYREF
  idStr v67; // [sp+120h] [-1F0h] BYREF
  idToken v68; // [sp+140h] [-1D0h] BYREF
  idToken v69; // [sp+190h] [-180h] BYREF
  idToken v70; // [sp+1E0h] [-130h] BYREF
  idLexer v71; // [sp+230h] [-E0h] BYREF

  v1 = 0;
  this->immediateType = nullptr;
  this->immediate._int = 0;
  this->immediate.vector[1] = 0.0;
  p_immediate = &this->immediate;
  this->immediate.vector[2] = 0.0;
  this->immediate.quat[3] = 0.0;
  parserPtr = this->parserPtr;
  this->currentLineNumber = this->token.line;
  scriptstack = parserPtr->scriptstack;
  v63 = parserPtr;
  if ( scriptstack != nullptr )
    data = scriptstack->filename.data;
  else
    data = &byte_8200D768;
  v7 = parserPtr->scriptstack;
  v63 = parserPtr;
  if ( v7 != nullptr )
    v8 = v7->filename.data;
  else
    v8 = &byte_8200D768;
  IsIncludeFile = idCompiler::IsIncludeFile(this, filename: data);
  this->currentFileNumber = idProgram::GetFilenum(this: &gameLocal->program, name: v8, includeFile: IsIncludeFile);
  if ( !idParser::ReadToken(this: this->parserPtr, token: &this->token) )
  {
    this->eof = true;
    return;
  }
  v10 = this->parserPtr;
  v11 = v10->scriptstack;
  v64 = v10;
  if ( v11 != nullptr )
    v12 = v11->filename.data;
  else
    v12 = &byte_8200D768;
  v13 = v10->scriptstack;
  v64 = v10;
  if ( v13 != nullptr )
    v14 = v13->filename.data;
  else
    v14 = &byte_8200D768;
  v15 = idCompiler::IsIncludeFile(this, filename: v12);
  Filenum = idProgram::GetFilenum(this: &gameLocal->program, name: v14, includeFile: v15);
  LODWORD(v19) = this->currentFileNumber;
  if ( (_DWORD)v19 != Filenum && this->braceDepth > 0 && idStr::Cmp(s1: this->token.data, s2: "}") != 0 )
  {
    typeDef = this->scope->typeDef;
    if ( typeDef != nullptr && idScriptObject::GetTypeDef(this: (bfx::Planner3D *)typeDef) == (bfx::Space *)10 )
    {
      HIDWORD(v21) = idVarDef::Name(this: this->scope);
      idCompiler::Error(
        this,
        message: "Unexpected end of file inside function '%s'.  Missing closing braces.",
        a3: v21,
        a4: v23,
        a5: v22,
        a6: v57,
        a7: v58,
        a8: v59,
        a9: v60,
        a10: v61,
        a11: v62);
    }
    v24 = this->scope->typeDef;
    if ( v24 != nullptr && idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v24) == (bfx::Space *)13 )
    {
      HIDWORD(v25) = idVarDef::Name(this: this->scope);
      idCompiler::Error(
        this,
        message: "Unexpected end of file inside object '%s'.  Missing closing braces.",
        a3: v25,
        a4: v27,
        a5: v26,
        a6: v57,
        a7: v58,
        a8: v59,
        a9: v60,
        a10: v61,
        a11: v62);
    }
    v28 = this->scope->typeDef;
    if ( v28 != nullptr && idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v28) == (bfx::Space *)2 )
    {
      HIDWORD(v29) = idVarDef::Name(this: this->scope);
      idCompiler::Error(
        this,
        message: "Unexpected end of file inside namespace '%s'.  Missing closing braces.",
        a3: v29,
        a4: v31,
        a5: v30,
        a6: v57,
        a7: v58,
        a8: v59,
        a9: v60,
        a10: v61,
        a11: v62);
    }
    idCompiler::Error(
      this,
      message: "Unexpected end of file inside braced section",
      a3: v17,
      a4: v16,
      a5: v19,
      a6: v57,
      a7: v58,
      a8: v59,
      a9: v60,
      a10: v61,
      a11: v62);
  }
  if ( (unsigned int)(this->token.type - 1) > 4 )
  {
    HIDWORD(v17) = this->token.data;
    idCompiler::Error(
      this,
      message: "Unknown token '%s'",
      a3: v17,
      a4: v16,
      a5: v19,
      a6: v57,
      a7: v58,
      a8: v59,
      a9: v60,
      a10: v61,
      a11: v62);
  }
  switch ( this->token.type )
  {
    case 2:
      this->immediateType = &type_vector;
      idLexer::idLexer(this: &v71, flags_: 1);
      v32 = this->parserPtr->scriptstack;
      if ( v32 != nullptr )
        v33 = v32->filename.data;
      else
        v33 = &byte_8200D768;
      idLexer::LoadMemory(this: &v71, ptr: this->token.data, length_: this->token.len, name: v33);
      v65.len = 0;
      v65.baseBuffer[0] = 0;
      v65.allocedAndFlag = 20;
      v65.data = v65.baseBuffer;
      v65.intvalue = 0;
      v65.floatvalue = -3.4028235e38;
      memset(&v65.whiteSpaceStart_p, 0, 12);
      v34 = (float *)p_immediate;
      do
      {
        if ( !idLexer::ReadToken(this: &v71, token: &v65) )
        {
          HIDWORD(v37) = this->token.data;
          idCompiler::Error(
            this,
            message: "Couldn't read vector. '%s' is not in the form of 'x y z'",
            a3: v37,
            a4: v36,
            a5: v35,
            a6: v57,
            a7: v58,
            a8: v59,
            a9: v60,
            a10: v61,
            a11: v62);
        }
        if ( v65.type != 5 || idStr::Cmp(s1: v65.data, s2: "-") != 0 )
        {
          if ( v65.type != 3 )
          {
            HIDWORD(v41) = this->token.data;
            LODWORD(v41) = v65.data;
            idCompiler::Error(
              this,
              message: "vector '%s' is not in the form of 'x y z'.  expected float value, found '%s'",
              a3: v41,
              a4: v36,
              a5: v35,
              a6: v57,
              a7: v58,
              a8: v59,
              a9: v60,
              a10: v61,
              a11: v62);
          }
          *v34 = idToken::GetFloatValue(this: &v65);
        }
        else
        {
          if ( !idLexer::CheckTokenType(this: &v71, type: 3, subtype: 0, token: &v65) )
          {
            LODWORD(v40) = this->token.data;
            HIDWORD(v40) = v65.data;
            idCompiler::Error(
              this,
              message: "expected a number following '-' but found '%s' in vector '%s'",
              a3: v40,
              a4: v39,
              a5: v38,
              a6: v57,
              a7: v58,
              a8: v59,
              a9: v60,
              a10: v61,
              a11: v62);
          }
          *v34 = -idToken::GetFloatValue(this: &v65);
        }
        ++v1;
        ++v34;
      }
      while ( v1 < 3 );
      idStr::FreeData(this: &v65);
      idLexer::~idLexer(this: &v71);
      return;
    case 3:
      p_token = &this->token;
      if ( (this->token.subtype & 1) != 0 )
      {
        this->immediateType = &type_integer;
        p_immediate->_int = idToken::GetUnsignedIntValue(this: p_token);
      }
      else
      {
        this->immediateType = &type_float;
        p_immediate->_float = idToken::GetFloatValue(this: p_token);
      }
      return;
    case 4:
      return;
    case 1:
      this->immediateType = &type_string;
      return;
    default:
      break;
  }
  subtype = this->token.subtype;
  if ( subtype == 52 )
  {
    v67.len = 0;
    v67.baseBuffer[0] = 0;
    v67.allocedAndFlag = 20;
    v67.data = v67.baseBuffer;
    v66.allocedAndFlag = 20;
    v66.len = 0;
    v66.data = v66.baseBuffer;
    v66.baseBuffer[0] = 0;
    v66.intvalue = 0;
    v66.floatvalue = -3.4028235e38;
    memset(&v66.whiteSpaceStart_p, 0, 12);
    v44 = this->parserPtr;
    this->immediateType = &type_entity;
    idParser::ReadToken(this: v44, token: &this->token);
    if ( idParser::GetNextWhiteSpace(this: this->parserPtr, whiteSpace: &v67, currentLine: true) == 0 )
    {
      while ( 1 )
      {
        idParser::ReadToken(this: this->parserPtr, token: &v66);
        if ( (v66.len <= 0 || idStr::Cmp(s1: v66.data, s2: "/") != 0 && *v66.data != 92) && v66.type != 4 )
          break;
        idStr::Append(this: &this->token, text: &v66);
        if ( idParser::GetNextWhiteSpace(this: this->parserPtr, whiteSpace: &v67, currentLine: true) != 0 )
          goto LABEL_63;
      }
      idParser::UnreadToken(this: this->parserPtr, token: &v66);
    }
LABEL_63:
    idStr::MakeNameCanonical(this: &this->token);
    idStr::FreeData(this: &v66);
    v45 = (idToken *)&v67;
    goto _M492944_0;
  }
  if ( subtype == 55 )
  {
    v46 = this->parserPtr;
    this->immediateType = &type_decl;
    idParser::ReadToken(this: v46, token: &this->token);
    HIDWORD(v49) = byte_821B0000;
    v68.len = 0;
    LODWORD(v48) = v68.baseBuffer;
    v68.baseBuffer[0] = 0;
    v68.allocedAndFlag = 20;
    v68.data = v68.baseBuffer;
    v68.intvalue = 0;
    v68.floatvalue = -3.4028235e38;
    memset(&v68.whiteSpaceStart_p, 0, 12);
    HIDWORD(v48) = v70.baseBuffer;
    v70.floatvalue = -3.4028235e38;
    v70.allocedAndFlag = 20;
    v70.data = v70.baseBuffer;
    v70.len = 0;
    v70.baseBuffer[0] = 0;
    v70.intvalue = 0;
    memset(&v70.whiteSpaceStart_p, 0, 12);
    LODWORD(v49) = this->token.type;
    if ( (_DWORD)v49 == 1 )
      idCompiler::Error(
        this,
        message: "Decl literal specifier '@' must be followed by a decl type name.",
        a3: v47,
        a4: v48,
        a5: v49,
        a6: v57,
        a7: v58,
        a8: v59,
        a9: v60,
        a10: v61,
        a11: v62);
    if ( (_DWORD)v49 == 4 )
    {
      v69.floatvalue = -3.4028235e38;
      v69.allocedAndFlag = 20;
      v69.data = v69.baseBuffer;
      v69.len = 0;
      v69.baseBuffer[0] = 0;
      v69.intvalue = 0;
      memset(&v69.whiteSpaceStart_p, 0, 12);
      idToken::operator=(this: &v70, __that: &this->token);
      idParser::ExpectTokenType(this: this->parserPtr, type: 5, subtype: 44, token: &v69);
      idParser::ExpectTokenType(this: this->parserPtr, type: 1, subtype: 0, token: &this->token);
      idToken::operator=(this: &v68, __that: &this->token);
      idParser::ExpectTokenType(this: this->parserPtr, type: 5, subtype: 45, token: &v69);
      idStr::FreeData(this: &v69);
    }
    idStr::MakeNameCanonical(this: &v68);
    idProgram::RegisterDecl(
      this: (idProgram *)&v63,
      result: (idIndex<int,enum invalidScriptDecl_t> *)&gameLocal->program,
      declName: v68.data,
      declTypeName: v70.data);
    v50 = v63;
    p_immediate->_int = (int)v63;
    if ( v50 == (idParser *)-1 && idStr::Cmp(s1: v68.data, s2: &byte_8200D768) != 0 )
    {
      HIDWORD(v53) = v68.data;
      idCompiler::Warning(
        this,
        message: "Script referenced decl '%s' but decl does not exist",
        a3: v53,
        a4: v52,
        a5: v51,
        a6: v57,
        a7: v58,
        a8: v59,
        a9: v60,
        a10: v61,
        a11: v62);
    }
    idStr::FreeData(this: &v70);
    v45 = &v68;
_M492944_0:
    idStr::FreeData(this: v45);
    return;
  }
  if ( idStr::Cmp(s1: this->token.data, s2: "{") != 0 )
  {
    if ( idStr::Cmp(s1: this->token.data, s2: "}") != 0 )
    {
      LODWORD(v56) = this->token.subtype;
      HIDWORD(v56) = idCompiler::punctuationValid;
      if ( !idCompiler::punctuationValid[v56] )
      {
        HIDWORD(v55) = this->token.data;
        LODWORD(v54) = idCompiler::punctuationValid[v56];
        idCompiler::Error(
          this,
          message: "Unknown punctuation '%s'",
          a3: v55,
          a4: v54,
          a5: v56,
          a6: v57,
          a7: v58,
          a8: v59,
          a9: v60,
          a10: v61,
          a11: v62);
      }
    }
    else
    {
      --this->braceDepth;
    }
  }
  else
  {
    ++this->braceDepth;
  }
}


// ========================================================================
// $LN312
// EA  : 0x82E8D1D8
// RVA : 0x00E8D1D8
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _LN312()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 784 + 560));
}


// ========================================================================
// __unwind$492406
// EA  : 0x82E8D200
// RVA : 0x00E8D200
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_492406()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 784 + 128));
}


// ========================================================================
// __unwind$492407
// EA  : 0x82E8D228
// RVA : 0x00E8D228
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_492407()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 784 + 288));
}


// ========================================================================
// __unwind$492408
// EA  : 0x82E8D250
// RVA : 0x00E8D250
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_492408()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 784 + 208));
}


// ========================================================================
// __unwind$492409
// EA  : 0x82E8D278
// RVA : 0x00E8D278
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_492409()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 784 + 320));
}


// ========================================================================
// __unwind$492410
// EA  : 0x82E8D2A0
// RVA : 0x00E8D2A0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_492410()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 784 + 480));
}


// ========================================================================
// __unwind$492411
// EA  : 0x82E8D2C8
// RVA : 0x00E8D2C8
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_492411()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 784 + 400));
}


// ========================================================================
// ?ExpectToken@idCompiler@@AAAXPBD@Z
// EA  : 0x82E8D2F0
// RVA : 0x00E8D2F0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ExpectToken(idCompiler *this, const char *string)
{
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  int v7; // [sp+8h] [-88h]
  int v8; // [sp+Ch] [-84h]
  int v9; // [sp+10h] [-80h]
  int v10; // [sp+14h] [-7Ch]
  int v11; // [sp+18h] [-78h]
  int v12; // [sp+1Ch] [-74h]

  if ( idStr::Cmp(s1: this->token.data, s2: string) != 0 )
  {
    LODWORD(v6) = this->token.data;
    HIDWORD(v6) = string;
    idCompiler::Error(
      this,
      message: "expected '%s', found '%s'",
      a3: v6,
      a4: v5,
      a5: v4,
      a6: v7,
      a7: v8,
      a8: v9,
      a9: v10,
      a10: v11,
      a11: v12);
  }
  idCompiler::NextToken(this);
}


// ========================================================================
// ?CheckToken@idCompiler@@AAA_NPBD@Z
// EA  : 0x82E8D358
// RVA : 0x00E8D358
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

int __fastcall idCompiler::CheckToken(idCompiler *this, const char *string)
{
  if ( idStr::Cmp(s1: this->token.data, s2: string) != 0 )
    return 0;
  idCompiler::NextToken(this);
  return 1;
}


// ========================================================================
// ?ParseName@idCompiler@@AAAXAAVidStr@@@Z
// EA  : 0x82E8D3B8
// RVA : 0x00E8D3B8
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ParseName(idCompiler *this, idStr *name, __int64 a3, __int64 a4, __int64 a5)
{
  int len; // r30
  int v8; // [sp+8h] [-88h]
  int v9; // [sp+Ch] [-84h]
  int v10; // [sp+10h] [-80h]
  int v11; // [sp+14h] [-7Ch]
  int v12; // [sp+18h] [-78h]
  int v13; // [sp+1Ch] [-74h]

  if ( this->token.type != 4 )
  {
    HIDWORD(a3) = this->token.data;
    idCompiler::Error(
      this,
      message: "'%s' is not a name",
      a3,
      a4,
      a5,
      a6: v8,
      a7: v9,
      a8: v10,
      a9: v11,
      a10: v12,
      a11: v13);
  }
  len = this->token.len;
  idStr::EnsureAlloced(this: name, amount: len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: name->data, Src: this->token.data, Size: len);
  name->data[len] = 0;
  name->len = len;
  idCompiler::NextToken(this);
}


// ========================================================================
// ?ParseType@idCompiler@@AAAPAVidTypeDef@@XZ
// EA  : 0x82E8D430
// RVA : 0x00E8D430
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idTypeDef *__fastcall idCompiler::ParseType(idCompiler *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  idTypeDef *v5; // r3
  idTypeDef *v6; // r30
  idTypeDef *typeDef; // r3
  int v9; // [sp+8h] [-78h]
  int v10; // [sp+Ch] [-74h]
  int v11; // [sp+10h] [-70h]
  int v12; // [sp+14h] [-6Ch]
  int v13; // [sp+18h] [-68h]
  int v14; // [sp+1Ch] [-64h]

  v5 = idCompiler::CheckType(this);
  v6 = v5;
  if ( v5 == nullptr )
  {
    HIDWORD(v4) = this->token.data;
    idCompiler::Error(
      this,
      message: "\"%s\" is not a type",
      a3: v4,
      a4: v3,
      a5: v2,
      a6: v9,
      a7: v10,
      a8: v11,
      a9: v12,
      a10: v13,
      a11: v14);
  }
  if ( v5 == &type_scriptevent )
  {
    LODWORD(v2) = this->scope;
    HIDWORD(v2) = &def_namespace;
    if ( (idVarDef *)v2 != &def_namespace )
      idCompiler::Error(
        this,
        message: "scriptEvents can only defined in the global namespace",
        a3: v4,
        a4: v3,
        a5: v2,
        a6: v9,
        a7: v10,
        a8: v11,
        a9: v12,
        a10: v13,
        a11: v14);
  }
  LODWORD(v2) = &type_namespace;
  if ( v5 == &type_namespace )
  {
    typeDef = this->scope->typeDef;
    if ( typeDef == nullptr || idScriptObject::GetTypeDef(this: (bfx::Planner3D *)typeDef) != (bfx::Space *)2 )
      idCompiler::Error(
        this,
        message: "A namespace may only be defined globally, or within another namespace",
        a3: v4,
        a4: v3,
        a5: v2,
        a6: v9,
        a7: v10,
        a8: v11,
        a9: v12,
        a10: v13,
        a11: v14);
  }
  idCompiler::NextToken(this);
  return v6;
}


// ========================================================================
// ?ParseImmediate@idCompiler@@AAAPAVidVarDef@@XZ
// EA  : 0x82E8D500
// RVA : 0x00E8D500
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::ParseImmediate(idCompiler *this)
{
  idVarDef *Immediate; // r30

  Immediate = idCompiler::FindImmediate(
                this,
                type: (bfx::Planner3D *)this->immediateType,
                eval: &this->immediate,
                string: this->token.data);
  idCompiler::NextToken(this);
  return Immediate;
}


// ========================================================================
// ?PatchLoop@idCompiler@@AAAXHH@Z
// EA  : 0x82E8D550
// RVA : 0x00E8D550
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::PatchLoop(idCompiler *this, int start, int continuePos)
{
  __int64 v3; // r30
  idGameLocal *v4; // r11
  int v6; // r25
  statement_t *v7; // r31
  int v8; // r22
  int op; // r10
  const eval_s *v10; // r5
  _QWORD v11[2]; // [sp+50h] [-80h] BYREF
  _QWORD v12[14]; // [sp+60h] [-70h] BYREF

  HIDWORD(v3) = &idEventDef::eventDefList[3154];
  v4 = gameLocal;
  v6 = start;
  v7 = &gameLocal->program.statements.list[start];
  if ( start < gameLocal->program.statements.num )
  {
    v8 = continuePos - start;
    LODWORD(v3) = 0;
    while ( 1 )
    {
      op = v7->op;
      if ( op == 209 )
        break;
      if ( op == 210 )
      {
        v7->op = -48;
        v10 = (const eval_s *)v12;
        LODWORD(v12[0]) = 0;
        v12[1] = v3;
        HIDWORD(v12[0]) = v8;
        goto LABEL_7;
      }
LABEL_8:
      ++v6;
      --v8;
      ++v7;
      if ( v6 >= v4->program.statements.num )
        return;
    }
    v7->op = -48;
    v10 = (const eval_s *)v11;
    v11[0] = v3;
    v11[1] = v3;
    HIDWORD(v11[0]) = gameLocal->program.statements.num - v6;
LABEL_7:
    v7->a = idCompiler::FindImmediate(this, type: (bfx::Planner3D *)&type_jumpoffset, eval: v10, string: &byte_8200D768);
    v4 = gameLocal;
    goto LABEL_8;
  }
}


// ========================================================================
// ?EmitFunctionParms@idCompiler@@AAAPAVidVarDef@@HPAV2@HH0@Z
// EA  : 0x82E8D648
// RVA : 0x00E8D648
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::EmitFunctionParms(
        idCompiler *this,
        int op,
        idVarDef *func,
        idVarDef *startarg,
        int startsize,
        idVarDef *object)
{
  int v7; // r22
  __int64 v8; // r15
  char v11; // r20
  const bfx::Vec3 *CachedSize; // r28
  bfx::ObstacleImpl *v13; // r19
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  char *data; // r3
  int v18; // r23
  const char *v19; // r21
  long double v20; // fp4
  double v21; // fp2
  double v22; // fp1
  char v23; // r11
  idVarDef *v24; // r26
  bfx::Planner3D *ParmType; // r29
  long double v26; // fp4
  double v27; // fp2
  double v28; // fp1
  bfx::SystemInstance *v29; // r3
  bool v30; // zf
  char v31; // r11
  int num; // r16
  int v33; // r26
  idVarDef **list; // r29
  encounterGroupRole_t *v35; // r28
  bfx::Planner3D *v36; // r3
  bfx::Space *TypeDef; // r3
  __int64 v38; // r6
  __int64 v39; // r10
  __int64 v40; // r8
  __int64 v41; // r6
  __int64 v42; // r10
  __int64 v43; // r8
  char v44; // r4
  idVarDef *Immediate; // r3
  long double v46; // fp4
  double v47; // fp2
  double v48; // fp1
  long double v49; // fp4
  double v50; // fp2
  double v51; // fp1
  int v52; // r17
  bfx::Planner3D *v53; // r3
  bfx::Space *v54; // r3
  __int64 v55; // r6
  __int64 v56; // r10
  __int64 v57; // r8
  idTypeDef *v58; // r3
  __int64 v59; // r6
  __int64 v60; // r10
  __int64 v61; // r8
  idDeclSource *v62; // r3
  bfx::Planner3D *v63; // r3
  idVarDef *v64; // r3
  long double v65; // fp4
  double v66; // fp2
  double v67; // fp1
  __int64 v68; // r10
  __int64 v69; // r8
  __int64 v70; // r6
  idDeclSource *v71; // r3
  __int64 v72; // r6
  __int64 v73; // r10
  __int64 v74; // r8
  __int64 v75; // r6
  idVarDef *v76; // r3
  long double v77; // fp4
  double v78; // fp2
  double v79; // fp1
  idVarDef *v80; // r3
  long double v81; // fp4
  double v82; // fp2
  double v83; // fp1
  int v84; // r7
  statement_t *v85; // r29
  idTypeDef *v86; // r28
  int v87; // r29
  idVarDef *returnStringDef; // r23
  statement_t *v90; // r11
  idVarDef *FreeResultDef; // r28
  long double v92; // fp4
  double v93; // fp2
  double v94; // fp1
  __int64 v95; // r6
  __int64 v96; // r10
  __int64 v97; // r8
  int v98; // [sp+8h] [-168h]
  int v99; // [sp+Ch] [-164h]
  int v100; // [sp+10h] [-160h]
  int v101; // [sp+14h] [-15Ch]
  int v102; // [sp+18h] [-158h]
  int v103; // [sp+1Ch] [-154h]
  idVarDef *Expression; // [sp+84h] [-ECh] BYREF
  bfx::ObstacleImpl *v105; // [sp+88h] [-E8h]
  const char *v106; // [sp+8Ch] [-E4h]
  idList<enum encounterGroupRole_t,5> v107; // [sp+90h] [-E0h] BYREF
  eval_s v108; // [sp+A0h] [-D0h] BYREF
  idStr v109[6]; // [sp+B0h] [-C0h] BYREF

  LODWORD(v8) = 0;
  v109[0].len = 0;
  v109[0].baseBuffer[0] = 0;
  v7 = op;
  v109[0].allocedAndFlag = 20;
  HIDWORD(v8) = func;
  v109[0].data = v109[0].baseBuffer;
  v11 = 0;
  memset(&v107, 0, 14);
  CachedSize = nullptr;
  *(_WORD *)&v107.memTag = 14848;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v107);
  v105 = *(bfx::ObstacleImpl **)(HIDWORD(v8) + 20);
  v13 = v105;
  if ( v105 == nullptr || idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v105) != (bfx::Space *)10 )
  {
    HIDWORD(v14) = idVarDef::Name(this: (idVarDef *)HIDWORD(v8));
    idCompiler::Error(
      this,
      message: "'%s' is not a function",
      a3: v14,
      a4: v16,
      a5: v15,
      a6: v98,
      a7: v99,
      a8: v100,
      a9: v101,
      a10: v102,
      a11: v103);
  }
  data = this->token.data;
  v18 = (int)startarg;
  Expression = startarg;
  v19 = ")";
  v106 = ")";
  if ( idStr::Cmp(s1: data, s2: ")") != 0 )
  {
    v23 = 0;
  }
  else
  {
    idCompiler::NextToken(this);
    v23 = 1;
  }
  if ( v23 == 0 )
  {
    do
    {
      if ( v11 != 0 )
      {
        Expression = idCompiler::GetExpression(this, priority: 15);
        idList<idAnimWebBlendTree *,5>::Append(this: &v107, obj: (encounterGroupRole_t *)&Expression);
      }
      else
      {
        if ( v18 >= (int)function_t::Name(this: (idDecl *)v13) )
        {
          Expression = (idVarDef *)v18;
          HIDWORD(v38) = idFile_MTP::GetName(pObstacle: v13);
          idCompiler::Error(
            this,
            message: "too many parameters to %s",
            a3: v38,
            a4: v40,
            a5: v39,
            a6: v98,
            a7: v99,
            a8: v100,
            a9: v101,
            a10: v102,
            a11: v103);
        }
        v24 = idCompiler::GetExpression(this, priority: 15);
        ParmType = (bfx::Planner3D *)idTypeDef::GetParmType(this: (idTypeDef *)v13, parmNumber: v18);
        if ( idScriptObject::GetTypeDef(this: ParmType) == (bfx::Space *)17 )
          v11 = 1;
        if ( (unsigned __int8)idCompiler::EmitPush(this, expression: v24, funcArg: ParmType, a4: v28, a5: v27, a6: v26) == 0 )
        {
          Expression = (idVarDef *)v18;
          LODWORD(v41) = idVarDef::Name(this: (idVarDef *)HIDWORD(v8));
          HIDWORD(v41) = v18 + 1;
          idCompiler::Error(
            this,
            message: "type mismatch on parm %i of call to '%s'",
            a3: v41,
            a4: v43,
            a5: v42,
            a6: v98,
            a7: v99,
            a8: v100,
            a9: v101,
            a10: v102,
            a11: v103);
        }
        v30 = idScriptObject::GetTypeDef(this: ParmType) == (bfx::Space *)13;
        v29 = (bfx::SystemInstance *)&type_object;
        if ( !v30 )
          v29 = (bfx::SystemInstance *)ParmType;
        startsize += (int)idreports::MapWarning::GetCachedSize(this: v29);
        ++v18;
      }
      if ( idStr::Cmp(s1: this->token.data, s2: ",") != 0 )
      {
        v31 = 0;
      }
      else
      {
        idCompiler::NextToken(this);
        v31 = 1;
      }
    }
    while ( v31 != 0 );
    Expression = (idVarDef *)v18;
    if ( v11 != 0 )
    {
      num = v107.num;
      v33 = 0;
      list = (idVarDef **)v107.list;
      if ( v107.num > 0 )
      {
        v35 = v107.list;
        do
        {
          v36 = *(bfx::Planner3D **)(*v35 + 20);
          if ( v36 != nullptr )
            TypeDef = idScriptObject::GetTypeDef(this: v36);
          else
            TypeDef = nullptr;
          switch ( (unsigned int)TypeDef )
          {
            case 0u:
              v44 = 46;
              break;
            case 3u:
              v44 = 115;
              break;
            case 4u:
              v44 = 102;
              break;
            case 5u:
              v44 = 100;
              break;
            case 6u:
              v44 = 118;
              break;
            case 7u:
              v44 = 113;
              break;
            case 8u:
            case 0xDu:
              v44 = 101;
              break;
            case 0x10u:
              v44 = 108;
              break;
            case 0x12u:
              v44 = 112;
              break;
            default:
              HIDWORD(v55) = idVarDef::Name(this: (idVarDef *)HIDWORD(v8));
              idCompiler::Error(
                this,
                message: "Invalid variable in '%s'",
                a3: v55,
                a4: v57,
                a5: v56,
                a6: v98,
                a7: v99,
                a8: v100,
                a9: v101,
                a10: v102,
                a11: v103);
          }
          idStr::Append(this: v109, a: v44);
          ++v33;
          ++v35;
        }
        while ( v33 < num );
      }
      Immediate = idCompiler::FindImmediate(
                    this,
                    type: (bfx::Planner3D *)&type_string,
                    eval: nullptr,
                    string: v109[0].data);
      idCompiler::EmitPush(
        this,
        expression: Immediate,
        funcArg: (bfx::Planner3D *)&type_string,
        a4: v48,
        a5: v47,
        a6: v46);
      CachedSize = idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)&type_string);
      v52 = 0;
      if ( num > 0 )
      {
        do
        {
          v53 = (bfx::Planner3D *)(*list)->typeDef;
          if ( v53 != nullptr )
            v54 = idScriptObject::GetTypeDef(this: v53);
          else
            v54 = nullptr;
          switch ( (unsigned int)v54 )
          {
            case 0u:
              idCompiler::EmitPush(
                this,
                expression: *list,
                funcArg: (bfx::Planner3D *)&type_void,
                a4: v51,
                a5: v50,
                a6: v49);
              v58 = &type_void;
              break;
            case 3u:
              idCompiler::EmitPush(
                this,
                expression: *list,
                funcArg: (bfx::Planner3D *)&type_string,
                a4: v51,
                a5: v50,
                a6: v49);
              v58 = &type_string;
              break;
            case 4u:
              idCompiler::EmitPush(
                this,
                expression: *list,
                funcArg: (bfx::Planner3D *)&type_float,
                a4: v51,
                a5: v50,
                a6: v49);
              v58 = &type_float;
              break;
            case 5u:
              idCompiler::EmitPush(
                this,
                expression: *list,
                funcArg: (bfx::Planner3D *)&type_integer,
                a4: v51,
                a5: v50,
                a6: v49);
              v58 = &type_integer;
              break;
            case 6u:
              idCompiler::EmitPush(
                this,
                expression: *list,
                funcArg: (bfx::Planner3D *)&type_vector,
                a4: v51,
                a5: v50,
                a6: v49);
              v58 = &type_vector;
              break;
            case 7u:
              idCompiler::EmitPush(
                this,
                expression: *list,
                funcArg: (bfx::Planner3D *)&type_quat,
                a4: v51,
                a5: v50,
                a6: v49);
              v58 = &type_quat;
              break;
            case 8u:
            case 0xDu:
              idCompiler::EmitPush(
                this,
                expression: *list,
                funcArg: (bfx::Planner3D *)&type_entity,
                a4: v51,
                a5: v50,
                a6: v49);
              v58 = &type_entity;
              break;
            case 0x10u:
              idCompiler::EmitPush(
                this,
                expression: *list,
                funcArg: (bfx::Planner3D *)&type_list,
                a4: v51,
                a5: v50,
                a6: v49);
              v58 = &type_list;
              break;
            case 0x12u:
              idCompiler::EmitPush(
                this,
                expression: *list,
                funcArg: (bfx::Planner3D *)&type_decl,
                a4: v51,
                a5: v50,
                a6: v49);
              v58 = &type_decl;
              break;
            default:
              HIDWORD(v59) = idVarDef::Name(this: (idVarDef *)HIDWORD(v8));
              idCompiler::Error(
                this,
                message: "Invalid variable in '%s'",
                a3: v59,
                a4: v61,
                a5: v60,
                a6: v98,
                a7: v99,
                a8: v100,
                a9: v101,
                a10: v102,
                a11: v103);
          }
          ++v52;
          CachedSize = (const bfx::Vec3 *)((char *)CachedSize
                                         + (_DWORD)idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)v58));
          ++list;
        }
        while ( v52 < num );
        v13 = v105;
        v19 = v106;
        v7 = op;
        v18 = (int)Expression;
      }
    }
    else
    {
      v62 = function_t::Name(this: (idDecl *)v13);
      v63 = (bfx::Planner3D *)idTypeDef::GetParmType(
                                this: (idTypeDef *)v13,
                                parmNumber: (int)&v62[-1].sourceTextLength + 3);
      if ( idScriptObject::GetTypeDef(this: v63) == (bfx::Space *)17 )
      {
        v64 = idCompiler::FindImmediate(this, type: (bfx::Planner3D *)&type_string, eval: nullptr, string: v109[0].data);
        idCompiler::EmitPush(this, expression: v64, funcArg: (bfx::Planner3D *)&type_string, a4: v67, a5: v66, a6: v65);
        CachedSize = idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)&type_string);
      }
    }
    if ( idStr::Cmp(s1: this->token.data, s2: v19) != 0 )
    {
      LODWORD(v70) = this->token.data;
      HIDWORD(v70) = v19;
      idCompiler::Error(
        this,
        message: "expected '%s', found '%s'",
        a3: v70,
        a4: v69,
        a5: v68,
        a6: v98,
        a7: v99,
        a8: v100,
        a9: v101,
        a10: v102,
        a11: v103);
    }
    idCompiler::NextToken(this);
  }
  if ( v11 == 0 && v18 < (int)function_t::Name(this: (idDecl *)v13) )
  {
    v71 = function_t::Name(this: (idDecl *)v13);
    if ( idTypeDef::GetParmType(this: (idTypeDef *)v13, parmNumber: (int)&v71[-1].sourceTextLength + 3) != &type_varArgs )
    {
      HIDWORD(v72) = idVarDef::Name(this: (idVarDef *)HIDWORD(v8));
      idCompiler::Error(
        this,
        message: "too few parameters for function '%s'",
        a3: v72,
        a4: v74,
        a5: v73,
        a6: v98,
        a7: v99,
        a8: v100,
        a9: v101,
        a10: v102,
        a11: v103);
    }
  }
  if ( v7 == 189 )
  {
    LODWORD(v75) = 0;
    HIDWORD(v75) = HIDWORD(v8);
    idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[189], var_b: v75, a4: v22, a5: v21, a6: v20);
  }
  else if ( v7 == 97 || v7 == 191 )
  {
    v80 = idCompiler::VirtualFunctionConstant(this, func: (idVarDef *)HIDWORD(v8));
    idCompiler::EmitOpcode(
      this,
      op: &idCompiler::opcodes[v7],
      var_b: __SPAIR64__((unsigned int)object, (unsigned int)v80),
      a4: v83,
      a5: v82,
      a6: v81);
    v84 = *(_DWORD *)(HIDWORD(v8) + 4);
    *(_QWORD *)&v108.stringPtr = v8;
    *((_QWORD *)&v108._int + 1) = v8;
    v85 = &gameLocal->program.statements.list[gameLocal->program.statements.num];
    v108._int = (int)CachedSize + *(_DWORD *)(v84 + 20);
    v85[-1].c = idCompiler::FindImmediate(
                  this,
                  type: (bfx::Planner3D *)&type_argsize,
                  eval: &v108,
                  string: &byte_8200D768);
  }
  else
  {
    v76 = idCompiler::SizeConstant(this, size: (int)CachedSize + startsize);
    idCompiler::EmitOpcode(
      this,
      op: &idCompiler::opcodes[v7],
      var_b: __SPAIR64__(HIDWORD(v8), (unsigned int)v76),
      a4: v79,
      a5: v78,
      a6: v77);
  }
  v86 = idTypeDef::ReturnType(this: (idTypeDef *)v13);
  if ( idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v86) == (bfx::Space *)3 )
  {
    v87 = 117;
    returnStringDef = gameLocal->program.returnStringDef;
  }
  else
  {
    gameLocal->program.returnDef->typeDef = v86;
    returnStringDef = gameLocal->program.returnDef;
    switch ( (unsigned int)idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v86) )
    {
      case 0u:
      case 4u:
        v87 = 114;
        break;
      case 5u:
        v87 = 118;
        break;
      case 6u:
        v87 = 115;
        break;
      case 7u:
        v87 = 116;
        break;
      case 8u:
        v87 = 119;
        break;
      case 0xDu:
        v87 = 121;
        break;
      case 0x10u:
        v87 = 120;
        break;
      case 0x12u:
        v87 = 122;
        break;
      default:
        HIDWORD(v95) = idVarDef::Name(this: (idVarDef *)HIDWORD(v8));
        idCompiler::Error(
          this,
          message: "Invalid return type for function '%s'",
          a3: v95,
          a4: v97,
          a5: v96,
          a6: v98,
          a7: v99,
          a8: v100,
          a9: v101,
          a10: v102,
          a11: v103);
    }
  }
  if ( idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v86) != nullptr )
  {
    v90 = &gameLocal->program.statements.list[gameLocal->program.statements.num];
    FreeResultDef = idCompiler::FindFreeResultDef(this, type: v86, scope: this->scope, a: v90[-1].a, b: v90[-1].b);
    FreeResultDef->numUsers = 0;
    idCompiler::EmitOpcode(
      this,
      op: &idCompiler::opcodes[v87],
      var_b: __SPAIR64__((unsigned int)returnStringDef, (unsigned int)FreeResultDef),
      a4: v94,
      a5: v93,
      a6: v92);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v107);
    idStr::FreeData(this: v109);
    return FreeResultDef;
  }
  else
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v107);
    idStr::FreeData(this: v109);
    return returnStringDef;
  }
}


// ========================================================================
// $LN433_0
// EA  : 0x82E8DF6C
// RVA : 0x00E8DF6C
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _LN433_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 176));
}


// ========================================================================
// __unwind$493262
// EA  : 0x82E8DF94
// RVA : 0x00E8DF94
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_493262()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 368 + 144));
}


// ========================================================================
// ?ParseObjectCall@idCompiler@@AAAPAVidVarDef@@PAV2@0@Z
// EA  : 0x82E8DFC0
// RVA : 0x00E8DFC0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::ParseObjectCall(
        idCompiler *this,
        idVarDef *object,
        idVarDef *func,
        double a4,
        double a5,
        long double a6)
{
  idCompiler::EmitPush(this, expression: object, funcArg: (bfx::Planner3D *)object->typeDef, a4, a5, a6);
  if ( !this->callthread )
    return idCompiler::EmitFunctionParms(this, op: 97, func, startarg: (idVarDef *)1, startsize: 0, object);
  this->callthread = false;
  return idCompiler::EmitFunctionParms(this, op: 191, func, startarg: (idVarDef *)1, startsize: 0, object);
}


// ========================================================================
// ?ParseEventCall@idCompiler@@AAAPAVidVarDef@@HPAV2@0@Z
// EA  : 0x82E8E030
// RVA : 0x00E8E030
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::ParseEventCall(idCompiler *this, int op, __int64 funcDef, __int64 a4, __int64 a5)
{
  idVarDef *v7; // r30
  idVarDef *v8; // r29
  bfx::Planner3D *v9; // r3
  long double v10; // fp4
  double v11; // fp2
  double v12; // fp1
  __int64 v13; // r6
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  __int64 v17; // r10
  __int64 v18; // r8
  bfx::Planner3D *typeDef; // r3
  bfx::Planner3D *v20; // r5
  const bfx::Vec3 *CachedSize; // r3
  int v23; // [sp+8h] [-98h]
  int v24; // [sp+Ch] [-94h]
  int v25; // [sp+10h] [-90h]
  int v26; // [sp+14h] [-8Ch]
  int v27; // [sp+18h] [-88h]
  int v28; // [sp+1Ch] [-84h]

  v7 = (idVarDef *)HIDWORD(funcDef);
  v8 = (idVarDef *)funcDef;
  if ( this->callthread )
    idCompiler::Error(
      this,
      message: "Cannot call built-in functions as a thread",
      a3: funcDef,
      a4,
      a5,
      a6: v23,
      a7: v24,
      a8: v25,
      a9: v26,
      a10: v27,
      a11: v28);
  v9 = *(bfx::Planner3D **)(funcDef + 20);
  if ( v9 == nullptr || idScriptObject::GetTypeDef(this: v9) != (bfx::Space *)10 )
  {
    HIDWORD(v13) = idVarDef::Name(this: v8);
    idCompiler::Error(
      this,
      message: "'%s' is not a function",
      a3: v13,
      a4: v15,
      a5: v14,
      a6: v23,
      a7: v24,
      a8: v25,
      a9: v26,
      a10: v27,
      a11: v28);
  }
  if ( *v8->value.value.ip == 0 )
  {
    HIDWORD(v16) = idVarDef::Name(this: v8);
    idCompiler::Error(
      this,
      message: "\"%s\" cannot be called with object notation",
      a3: v16,
      a4: v18,
      a5: v17,
      a6: v23,
      a7: v24,
      a8: v25,
      a9: v26,
      a10: v27,
      a11: v28);
  }
  typeDef = (bfx::Planner3D *)v7->typeDef;
  if ( typeDef != nullptr && idScriptObject::GetTypeDef(this: typeDef) == (bfx::Space *)13 )
    v20 = (bfx::Planner3D *)&type_entity;
  else
    v20 = (bfx::Planner3D *)v7->typeDef;
  idCompiler::EmitPush(this, expression: v7, funcArg: v20, a4: v12, a5: v11, a6: v10);
  CachedSize = idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)&type_object);
  return idCompiler::EmitFunctionParms(
           this,
           op,
           func: v8,
           startarg: nullptr,
           startsize: (int)CachedSize,
           object: nullptr);
}


// ========================================================================
// ?ParseSysObjectCall@idCompiler@@AAAPAVidVarDef@@PAV2@@Z
// EA  : 0x82E8E128
// RVA : 0x00E8E128
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::ParseSysObjectCall(
        idCompiler *this,
        idVarDef *funcDef,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  idTypeDef *typeDef; // r3
  __int64 v8; // r6
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  __int64 v12; // r10
  __int64 v13; // r8
  int v15; // [sp+8h] [-78h]
  int v16; // [sp+Ch] [-74h]
  int v17; // [sp+10h] [-70h]
  int v18; // [sp+14h] [-6Ch]
  int v19; // [sp+18h] [-68h]
  int v20; // [sp+1Ch] [-64h]

  if ( this->callthread )
    idCompiler::Error(
      this,
      message: "Cannot call built-in functions as a thread",
      a3,
      a4,
      a5,
      a6: v15,
      a7: v16,
      a8: v17,
      a9: v18,
      a10: v19,
      a11: v20);
  typeDef = funcDef->typeDef;
  if ( typeDef == nullptr || idScriptObject::GetTypeDef(this: (bfx::Planner3D *)typeDef) != (bfx::Space *)10 )
  {
    HIDWORD(v8) = idVarDef::Name(this: funcDef);
    idCompiler::Error(
      this,
      message: "'%s' is not a function",
      a3: v8,
      a4: v10,
      a5: v9,
      a6: v15,
      a7: v16,
      a8: v17,
      a9: v18,
      a10: v19,
      a11: v20);
  }
  if ( *funcDef->value.value.ip == 0 )
  {
    HIDWORD(v11) = idVarDef::Name(this: funcDef);
    idCompiler::Error(
      this,
      message: "\"%s\" cannot be called with object notation",
      a3: v11,
      a4: v13,
      a5: v12,
      a6: v15,
      a7: v16,
      a8: v17,
      a9: v18,
      a10: v19,
      a11: v20);
  }
  return idCompiler::EmitFunctionParms(this, op: 98, func: funcDef, startarg: nullptr, startsize: 0, object: nullptr);
}


// ========================================================================
// ?LookupDef@idCompiler@@AAAPAVidVarDef@@PBDPBV2@@Z
// EA  : 0x82E8E1F0
// RVA : 0x00E8E1F0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::LookupDef(idCompiler *this, const char *name, idVarDef *baseobj)
{
  idVarDef *def; // r29
  idTypeDef *typeDef; // r3
  idVarDef *i; // r31
  idTypeDef *v9; // r3
  idTypeDef *v10; // r3
  idVarDef *v11; // r26
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  idVarDef *v15; // r3
  idVarDef *v16; // r30
  bfx::Planner3D *v17; // r3
  bfx::Space *v18; // r24
  bfx::Planner3D *v19; // r3
  bfx::Planner3D *v20; // r3
  bfx::Space *v21; // r29
  opcode_t *v22; // r31
  bfx::Planner3D *v23; // r3
  long double v24; // fp4
  double v25; // fp2
  double v26; // fp1
  bfx::Planner3D *v27; // r3
  bfx::Space *v28; // r3
  bfx::Planner3D *v29; // r3
  __int64 v30; // r10
  __int64 v31; // r8
  __int64 v32; // r6
  long double v33; // fp4
  double v34; // fp2
  double v35; // fp1
  __int64 v36; // r10
  __int64 v37; // r8
  __int64 v38; // r6
  long double v39; // fp4
  double v40; // fp2
  double v41; // fp1
  bfx::Planner3D *v42; // r3
  bfx::Space *v43; // r3
  bfx::Planner3D *v44; // r3
  bfx::Planner3D *v45; // r3
  bfx::Planner3D *v46; // r3
  bfx::Space *v47; // r3
  const char *v48; // r11
  const char *v49; // r10
  int v50; // r9
  int v51; // r9
  bool v52; // zf
  bfx::ObstacleImpl *v53; // r3
  __int64 v54; // r6
  __int64 v55; // r10
  __int64 v56; // r8
  long double v57; // fp4
  double v58; // fp2
  double v59; // fp1
  idVarDef *v60; // r31
  int v61; // [sp+8h] [-A8h]
  int v62; // [sp+Ch] [-A4h]
  int v63; // [sp+10h] [-A0h]
  int v64; // [sp+14h] [-9Ch]
  int v65; // [sp+18h] [-98h]
  int v66; // [sp+1Ch] [-94h]

  def = baseobj;
  if ( baseobj != nullptr )
  {
    typeDef = baseobj->typeDef;
    if ( typeDef != nullptr && idScriptObject::GetTypeDef(this: (bfx::Planner3D *)typeDef) == (bfx::Space *)13 )
    {
      for ( i = nullptr; def != &def_object; def = idTypeDef::SuperClass(this: def->typeDef)->def )
      {
        i = idProgram::GetDef(this: &gameLocal->program, type: nullptr, name, scope: def);
        if ( i != nullptr )
          break;
      }
      return i;
    }
  }
  i = idProgram::GetDef(this: &gameLocal->program, type: nullptr, name, scope: this->scope);
  if ( i != nullptr )
    return i;
  v9 = this->scope->typeDef;
  if ( v9 != nullptr && idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v9) == (bfx::Space *)2 )
    return i;
  v10 = this->scope->scope->typeDef;
  if ( v10 == nullptr || idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v10) != (bfx::Space *)13 )
    return i;
  v11 = idProgram::GetDef(
          this: &gameLocal->program,
          type: this->scope->scope->typeDef,
          name: "self",
          scope: this->scope);
  v15 = idCompiler::LookupDef(this, name, baseobj: this->scope->scope->typeDef->def);
  v16 = v15;
  if ( v15 == nullptr )
  {
    HIDWORD(v14) = name;
    idCompiler::Error(
      this,
      message: "Unknown value \"%s\"",
      a3: v14,
      a4: v13,
      a5: v12,
      a6: v61,
      a7: v62,
      a8: v63,
      a9: v64,
      a10: v65,
      a11: v66);
  }
  v17 = (bfx::Planner3D *)v15->typeDef;
  if ( v17 != nullptr )
    v18 = idScriptObject::GetTypeDef(this: v17);
  else
    v18 = nullptr;
  v19 = (bfx::Planner3D *)v16->typeDef;
  if ( v19 != nullptr && idScriptObject::GetTypeDef(this: v19) == (bfx::Space *)10 )
  {
    v20 = (bfx::Planner3D *)idTypeDef::ReturnType(this: v16->typeDef);
    v21 = idScriptObject::GetTypeDef(this: v20);
    goto LABEL_21;
  }
  v29 = (bfx::Planner3D *)idTypeDef::FieldType(this: v16->typeDef);
  v21 = idScriptObject::GetTypeDef(this: v29);
  LODWORD(v30) = (unsigned __int8)idCompiler::CheckToken(this, string: "++");
  if ( (_DWORD)v30 != 0 )
  {
    if ( v21 == (bfx::Space *)4 )
    {
      return idCompiler::EmitOpcode(
               this,
               op: &idCompiler::opcodes[3],
               var_b: __SPAIR64__((unsigned int)v11, (unsigned int)v16),
               a4: v35,
               a5: v34,
               a6: v33);
    }
    else
    {
      if ( v21 != (bfx::Space *)5 )
        idCompiler::Error(
          this,
          message: "Invalid type for ++",
          a3: v32,
          a4: v31,
          a5: v30,
          a6: v61,
          a7: v62,
          a8: v63,
          a9: v64,
          a10: v65,
          a11: v66);
      return idCompiler::EmitOpcode(
               this,
               op: &idCompiler::opcodes[4],
               var_b: __SPAIR64__((unsigned int)v11, (unsigned int)v16),
               a4: v35,
               a5: v34,
               a6: v33);
    }
  }
  else
  {
    LODWORD(v36) = (unsigned __int8)idCompiler::CheckToken(this, string: "--");
    if ( (_DWORD)v36 == 0 )
    {
LABEL_21:
      v22 = &idCompiler::opcodes[87];
      while ( 1 )
      {
        v23 = (bfx::Planner3D *)v22->type_a->typeDef;
        if ( v23 != nullptr && idScriptObject::GetTypeDef(this: v23) == (bfx::Space *)13 )
        {
          v27 = (bfx::Planner3D *)v22->type_b->typeDef;
          v28 = v27 != nullptr ? idScriptObject::GetTypeDef(this: v27) : nullptr;
          if ( v18 == v28 )
          {
            v42 = (bfx::Planner3D *)v22->type_c->typeDef;
            v43 = v42 != nullptr ? idScriptObject::GetTypeDef(this: v42) : nullptr;
            if ( v21 == v43 )
              break;
          }
        }
        if ( v22->priority == 2 )
        {
          v44 = (bfx::Planner3D *)v22->type_a->typeDef;
          if ( v44 != nullptr && idScriptObject::GetTypeDef(this: v44) == (bfx::Space *)13 )
          {
            v45 = (bfx::Planner3D *)v22->type_c->typeDef;
            if ( v45 == nullptr || idScriptObject::GetTypeDef(this: v45) == nullptr )
            {
              v46 = (bfx::Planner3D *)v22->type_c->typeDef;
              v47 = v46 != nullptr ? idScriptObject::GetTypeDef(this: v46) : nullptr;
              if ( v21 != v47 )
                break;
            }
          }
        }
        ++v22;
        v48 = v22->name;
        if ( v22->name != nullptr )
        {
          v49 = ".";
          do
          {
            v50 = *(unsigned __int8 *)v48;
            v52 = v50 == 0;
            v51 = v50 - *(unsigned __int8 *)v49;
            if ( v52 )
              break;
            ++v48;
            ++v49;
          }
          while ( v51 == 0 );
          if ( v51 == 0 )
            continue;
        }
        v53 = (bfx::ObstacleImpl *)idTypeDef::SuperClass(this: v16->typeDef);
        HIDWORD(v54) = idFile_MTP::GetName(pObstacle: v53);
        idCompiler::Error(
          this,
          message: "no valid opcode to access type '%s'",
          a3: v54,
          a4: v56,
          a5: v55,
          a6: v61,
          a7: v62,
          a8: v63,
          a9: v64,
          a10: v65,
          a11: v66);
      }
      if ( (((char *)v22 - (char *)idCompiler::opcodes) & 0xFFFFFFE0) == 0xC20 )
      {
        idCompiler::ExpectToken(this, string: "(");
        return idCompiler::ParseObjectCall(this, object: v11, func: v16, a4: v59, a5: v58, a6: v57);
      }
      else
      {
        v60 = idCompiler::EmitOpcode(
                this,
                op: v22,
                var_b: __SPAIR64__((unsigned int)v11, (unsigned int)v16),
                a4: v26,
                a5: v25,
                a6: v24);
        v60->typeDef = idTypeDef::FieldType(this: v16->typeDef);
        return v60;
      }
    }
    if ( v21 == (bfx::Space *)4 )
    {
      return idCompiler::EmitOpcode(
               this,
               op: &idCompiler::opcodes[7],
               var_b: __SPAIR64__((unsigned int)v11, (unsigned int)v16),
               a4: v41,
               a5: v40,
               a6: v39);
    }
    else
    {
      if ( v21 != (bfx::Space *)5 )
        idCompiler::Error(
          this,
          message: "Invalid type for --",
          a3: v38,
          a4: v37,
          a5: v36,
          a6: v61,
          a7: v62,
          a8: v63,
          a9: v64,
          a10: v65,
          a11: v66);
      return idCompiler::EmitOpcode(
               this,
               op: &idCompiler::opcodes[8],
               var_b: __SPAIR64__((unsigned int)v11, (unsigned int)v16),
               a4: v41,
               a5: v40,
               a6: v39);
    }
  }
}


// ========================================================================
// ?ParseValue@idCompiler@@AAAPAVidVarDef@@XZ
// EA  : 0x82E8E668
// RVA : 0x00E8E668
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::ParseValue(idCompiler *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v5; // r10
  idTypeDef *immediateType; // r11
  idToken *p_token; // r27
  idStr *v8; // r3
  idVarDef *Def; // r29
  idStr *v10; // r3
  idVarDef *v11; // r30
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  idVarDef *v16; // r3
  const idVarDef *basetype; // r11
  char *data; // r30
  int Name; // r3
  __int64 v20; // r10
  __int64 v21; // r8
  bfx::Planner3D *typeDef; // r3
  bfx::Planner3D *v23; // r3
  __int64 v24; // r10
  __int64 v25; // r8
  __int64 v26; // r10
  __int64 v27; // r8
  __int64 v28; // r6
  idStr *v29; // r27
  __int64 v30; // r6
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  int v34; // [sp+8h] [-138h]
  int v35; // [sp+Ch] [-134h]
  int v36; // [sp+10h] [-130h]
  int v37; // [sp+14h] [-12Ch]
  int v38; // [sp+18h] [-128h]
  int v39; // [sp+1Ch] [-124h]
  idStr v40; // [sp+70h] [-D0h] BYREF
  idStr v41; // [sp+90h] [-B0h] BYREF
  idStr v42; // [sp+B0h] [-90h] BYREF
  idVarDef v43[3]; // [sp+D0h] [-70h] BYREF

  HIDWORD(v5) = v40.baseBuffer;
  v40.len = 0;
  v40.allocedAndFlag = 20;
  v40.data = v40.baseBuffer;
  v40.baseBuffer[0] = 0;
  LODWORD(v5) = &pb_ss_UpdateAfterPhysics.name;
  immediateType = this->immediateType;
  if ( immediateType == &type_entity )
  {
    p_token = &this->token;
    v8 = operator+(result: &v41, a: "$", b: &this->token);
    Def = idProgram::GetDef(this: &gameLocal->program, type: &type_entity, name: v8->data, scope: &def_namespace);
    idStr::FreeData(this: &v41);
    if ( Def == nullptr )
    {
      v10 = operator+(result: &v42, a: "$", b: p_token);
      Def = idProgram::AllocDef(
              this: &gameLocal->program,
              type: &type_entity,
              name: v10->data,
              scope: &def_namespace,
              size: 1,
              constant: true,
              isTypeDeclaration: false);
      idStr::FreeData(this: &v42);
    }
    idCompiler::NextToken(this);
  }
  else
  {
    if ( immediateType != nullptr )
    {
      v11 = idCompiler::ParseImmediate(this);
      idStr::FreeData(this: &v40);
      return v11;
    }
    idCompiler::ParseName(this, name: &v40, a3, a4, a5: v5);
    v16 = idCompiler::LookupDef(this, name: v40.data, baseobj: (idVarDef *)this->basetype);
    Def = v16;
    if ( v16 == nullptr )
    {
      basetype = this->basetype;
      if ( basetype != nullptr )
      {
        data = v40.data;
        Name = idFile_MTP::GetName(pObstacle: (bfx::ObstacleImpl *)basetype->typeDef);
        idCompiler::Error(
          this,
          message: "%s is not a member of %s",
          a3: __SPAIR64__((unsigned int)data, Name),
          a4: v21,
          a5: v20,
          a6: v34,
          a7: v35,
          a8: v36,
          a9: v37,
          a10: v38,
          a11: v39);
      }
      HIDWORD(v15) = v40.data;
      idCompiler::Error(
        this,
        message: "Unknown value \"%s\"",
        a3: v15,
        a4: v14,
        a5: v13,
        a6: v34,
        a7: v35,
        a8: v36,
        a9: v37,
        a10: v38,
        a11: v39);
    }
    typeDef = (bfx::Planner3D *)v16->typeDef;
    if ( typeDef != nullptr && idScriptObject::GetTypeDef(this: typeDef) == (bfx::Space *)2 )
    {
      while ( 1 )
      {
        v23 = (bfx::Planner3D *)Def->typeDef;
        if ( v23 == nullptr || idScriptObject::GetTypeDef(this: v23) != (bfx::Space *)2 )
          break;
        if ( idStr::Cmp(s1: this->token.data, s2: "::") != 0 )
        {
          LODWORD(v33) = this->token.data;
          HIDWORD(v33) = "::";
          idCompiler::Error(
            this,
            message: "expected '%s', found '%s'",
            a3: v33,
            a4: v25,
            a5: v24,
            a6: v34,
            a7: v35,
            a8: v36,
            a9: v37,
            a10: v38,
            a11: v39);
        }
        idCompiler::NextToken(this);
        idCompiler::ParseName(this, name: &v40, a3: v28, a4: v27, a5: v26);
        v29 = (idStr *)Def;
        Def = idProgram::GetDef(this: &gameLocal->program, type: nullptr, name: v40.data, scope: Def);
        if ( Def == nullptr )
        {
          HIDWORD(v30) = idVarDef::GlobalName(this: v43, result: v29)->data;
          LODWORD(v30) = v40.data;
          idCompiler::Error(
            this,
            message: "Unknown value \"%s::%s\"",
            a3: v30,
            a4: v32,
            a5: v31,
            a6: v34,
            a7: v35,
            a8: v36,
            a9: v37,
            a10: v38,
            a11: v39);
        }
      }
    }
  }
  idStr::FreeData(this: &v40);
  return Def;
}


// ========================================================================
// $LN86
// EA  : 0x82E8E8C8
// RVA : 0x00E8E8C8
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _LN86()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 112));
}


// ========================================================================
// __unwind$494062_0
// EA  : 0x82E8E8F0
// RVA : 0x00E8E8F0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_494062_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 144));
}


// ========================================================================
// __unwind$494063_0
// EA  : 0x82E8E918
// RVA : 0x00E8E918
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_494063_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 176));
}


// ========================================================================
// __unwind$494064
// EA  : 0x82E8E940
// RVA : 0x00E8E940
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_494064()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 208));
}


// ========================================================================
// ?GetTerm@idCompiler@@AAAPAVidVarDef@@XZ
// EA  : 0x82E8E968
// RVA : 0x00E8E968
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::GetTerm(idCompiler *this)
{
  char v2; // r11
  idVarDef *Expression; // r30
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  bfx::Planner3D *typeDef; // r3
  bfx::Space *v8; // r3
  long double v9; // fp4
  double v10; // fp2
  double v11; // fp1
  int v12; // r11
  __int64 v13; // r6
  char v15; // r11
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  bfx::Planner3D *v19; // r3
  bfx::Space *v20; // r3
  idTypeDef *immediateType; // r11
  double v22; // fp13
  double v23; // fp11
  __int64 v24; // r10
  __int64 v25; // r8
  __int64 v26; // r6
  bfx::Planner3D *v27; // r3
  bfx::Space *v28; // r3
  char v29; // r11
  idVarDef *v30; // r30
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  bfx::Planner3D *v34; // r3
  __int64 v35; // r6
  long double v36; // fp4
  double v37; // fp2
  double v38; // fp1
  idVarDef *v39; // r30
  __int64 v40; // r10
  __int64 v41; // r8
  __int64 v42; // r6
  bfx::Planner3D *v43; // r3
  __int64 v44; // r6
  long double v45; // fp4
  double v46; // fp2
  double v47; // fp1
  __int64 v48; // r8
  __int64 v49; // r6
  int v50; // r4
  __int64 v51; // r10
  __int64 v52; // r8
  __int64 v53; // r6
  idVarDef *v54; // r30
  int v55; // [sp+8h] [-78h]
  int v56; // [sp+Ch] [-74h]
  int v57; // [sp+10h] [-70h]
  int v58; // [sp+14h] [-6Ch]
  int v59; // [sp+18h] [-68h]
  int v60; // [sp+1Ch] [-64h]

  if ( this->immediateType == nullptr )
  {
    if ( idStr::Cmp(s1: this->token.data, s2: "~") != 0 )
    {
      v2 = 0;
    }
    else
    {
      idCompiler::NextToken(this);
      v2 = 1;
    }
    if ( v2 != 0 )
    {
      Expression = idCompiler::GetExpression(this, priority: 2);
      typeDef = (bfx::Planner3D *)Expression->typeDef;
      if ( typeDef == nullptr )
        goto LABEL_9;
      v8 = idScriptObject::GetTypeDef(this: typeDef);
      if ( v8 == (bfx::Space *)4 )
      {
        v12 = 9;
      }
      else
      {
        if ( v8 != (bfx::Space *)5 )
LABEL_9:
          idCompiler::Error(
            this,
            message: "type mismatch for ~",
            a3: v6,
            a4: v5,
            a5: v4,
            a6: v55,
            a7: v56,
            a8: v57,
            a9: v58,
            a10: v59,
            a11: v60);
        v12 = 10;
      }
      goto LABEL_12;
    }
  }
  if ( this->immediateType == nullptr )
  {
    if ( idStr::Cmp(s1: this->token.data, s2: "!") != 0 )
    {
      v15 = 0;
    }
    else
    {
      idCompiler::NextToken(this);
      v15 = 1;
    }
    if ( v15 != 0 )
    {
      Expression = idCompiler::GetExpression(this, priority: 8);
      v19 = (bfx::Planner3D *)Expression->typeDef;
      if ( v19 != nullptr )
        v20 = idScriptObject::GetTypeDef(this: v19);
      else
        v20 = nullptr;
      switch ( (unsigned int)v20 )
      {
        case 3u:
          v12 = 179;
          break;
        case 4u:
          v12 = 177;
          break;
        case 5u:
          v12 = 176;
          break;
        case 6u:
          v12 = 178;
          break;
        case 8u:
        case 0xDu:
          v12 = 180;
          break;
        default:
          idCompiler::Error(
            this,
            message: "type mismatch for !",
            a3: v18,
            a4: v17,
            a5: v16,
            a6: v55,
            a7: v56,
            a8: v57,
            a9: v58,
            a10: v59,
            a11: v60);
      }
      goto LABEL_12;
    }
  }
  if ( this->immediateType == nullptr && (unsigned __int8)idCompiler::CheckToken(this, string: "-") != 0 )
  {
    immediateType = this->immediateType;
    if ( immediateType == &type_float )
    {
      this->immediate._float = -this->immediate._float;
      return idCompiler::ParseImmediate(this);
    }
    if ( immediateType == &type_vector )
    {
      v22 = this->immediate.vector[2];
      v23 = this->immediate._float;
      this->immediate.vector[1] = -this->immediate.vector[1];
      this->immediate.vector[2] = -v22;
      this->immediate._float = -v23;
      return idCompiler::ParseImmediate(this);
    }
    Expression = idCompiler::GetExpression(this, priority: 8);
    v27 = (bfx::Planner3D *)Expression->typeDef;
    if ( v27 != nullptr )
    {
      v28 = idScriptObject::GetTypeDef(this: v27);
      if ( v28 == (bfx::Space *)4 )
      {
        v12 = 182;
      }
      else if ( v28 == (bfx::Space *)5 )
      {
        v12 = 184;
      }
      else
      {
        if ( v28 != (bfx::Space *)6 )
          goto LABEL_39;
        v12 = 183;
      }
LABEL_12:
      LODWORD(v13) = 0;
      HIDWORD(v13) = Expression;
      return idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[v12], var_b: v13, a4: v11, a5: v10, a6: v9);
    }
LABEL_39:
    idCompiler::Error(
      this,
      message: "type mismatch for -",
      a3: v26,
      a4: v25,
      a5: v24,
      a6: v55,
      a7: v56,
      a8: v57,
      a9: v58,
      a10: v59,
      a11: v60);
  }
  if ( idStr::Cmp(s1: this->token.data, s2: "ftoi") != 0 )
  {
    v29 = 0;
  }
  else
  {
    idCompiler::NextToken(this);
    v29 = 1;
  }
  if ( v29 != 0 )
  {
    idCompiler::ExpectToken(this, string: "(");
    v30 = idCompiler::GetExpression(this, priority: 15);
    v34 = (bfx::Planner3D *)v30->typeDef;
    if ( v34 == nullptr || idScriptObject::GetTypeDef(this: v34) != (bfx::Space *)4 )
      idCompiler::Error(
        this,
        message: "type mismatch for ftoi()",
        a3: v33,
        a4: v32,
        a5: v31,
        a6: v55,
        a7: v56,
        a8: v57,
        a9: v58,
        a10: v59,
        a11: v60);
    idCompiler::ExpectToken(this, string: ")");
    LODWORD(v35) = 0;
    HIDWORD(v35) = v30;
    return idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[186], var_b: v35, a4: v38, a5: v37, a6: v36);
  }
  else if ( (unsigned __int8)idCompiler::CheckToken(this, string: "itof") != 0 )
  {
    idCompiler::ExpectToken(this, string: "(");
    v39 = idCompiler::GetExpression(this, priority: 15);
    v43 = (bfx::Planner3D *)v39->typeDef;
    if ( v43 == nullptr || idScriptObject::GetTypeDef(this: v43) != (bfx::Space *)5 )
      idCompiler::Error(
        this,
        message: "type mismatch for itof()",
        a3: v42,
        a4: v41,
        a5: v40,
        a6: v55,
        a7: v56,
        a8: v57,
        a9: v58,
        a10: v59,
        a11: v60);
    idCompiler::ExpectToken(this, string: ")");
    LODWORD(v44) = 0;
    HIDWORD(v44) = v39;
    return idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[185], var_b: v44, a4: v47, a5: v46, a6: v45);
  }
  else if ( (unsigned __int8)idCompiler::CheckToken(this, string: "thread") != 0 )
  {
    this->callthread = true;
    idCompiler::GetExpression(this, priority: 2);
    if ( this->callthread )
    {
      LODWORD(v51) = this->callthread;
      idCompiler::Error(
        this,
        message: "Invalid thread call",
        a3: v53,
        a4: v52,
        a5: v51,
        a6: v55,
        a7: v56,
        a8: v57,
        a9: v58,
        a10: v59,
        a11: v60);
    }
    gameLocal->program.returnDef->typeDef = &type_integer;
    return gameLocal->program.returnDef;
  }
  else if ( this->immediateType != nullptr || (unsigned __int8)idCompiler::CheckToken(this, string: "(") == 0 )
  {
    return idCompiler::ParseValue(this, a2: v50, a3: v49, a4: v48);
  }
  else
  {
    v54 = idCompiler::GetExpression(this, priority: 15);
    idCompiler::ExpectToken(this, string: ")");
    return v54;
  }
}


// ========================================================================
// ?ParseFunction@idCompiler@@AAAPAVidTypeDef@@PAV2@PBD@Z
// EA  : 0x82E8F018
// RVA : 0x00E8F018
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idTypeDef *__fastcall idCompiler::ParseFunction(idCompiler *this, idTypeDef *returnType, const char *name)
{
  const bfx::Vec3 *CachedSize; // r3
  idTypeDef *typeDef; // r3
  char v8; // r25
  char v9; // r11
  int v10; // r27
  idTypeDef *v11; // r28
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  int len; // r29
  char v16; // r11
  idTypeDef *Type; // r30
  int v19; // [sp+8h] [-168h]
  int v20; // [sp+Ch] [-164h]
  int v21; // [sp+10h] [-160h]
  int v22; // [sp+14h] [-15Ch]
  int v23; // [sp+18h] [-158h]
  int v24; // [sp+1Ch] [-154h]
  idStr v25; // [sp+70h] [-100h] BYREF
  idToken *p_token; // [sp+90h] [-E0h]
  idTypeDef v27; // [sp+A0h] [-D0h] BYREF

  CachedSize = idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)&type_function);
  idTypeDef::idTypeDef(
    this: &v27,
    etype: ev_function,
    edef: nullptr,
    ename: name,
    esize: (int)CachedSize,
    aux: returnType);
  typeDef = this->scope->typeDef;
  if ( typeDef == nullptr || idScriptObject::GetTypeDef(this: (bfx::Planner3D *)typeDef) != (bfx::Space *)2 )
    idTypeDef::AddFunctionParm(this: &v27, parmtype: this->scope->typeDef, name: "self");
  v8 = 0;
  if ( idStr::Cmp(s1: this->token.data, s2: ")") != 0 )
  {
    v9 = 0;
  }
  else
  {
    idCompiler::NextToken(this);
    v9 = 1;
  }
  if ( v9 == 0 )
  {
    v25.len = 0;
    v25.baseBuffer[0] = 0;
    v25.allocedAndFlag = 20;
    v25.data = v25.baseBuffer;
    v10 = 0;
    while ( 1 )
    {
      v11 = idCompiler::ParseType(this);
      if ( v11 == &type_void )
        break;
      if ( this->token.type != 4 )
      {
        HIDWORD(v14) = this->token.data;
        idCompiler::Error(
          this,
          message: "'%s' is not a name",
          a3: v14,
          a4: v13,
          a5: v12,
          a6: v19,
          a7: v20,
          a8: v21,
          a9: v22,
          a10: v23,
          a11: v24);
      }
      len = this->token.len;
      p_token = &this->token;
      idStr::EnsureAlloced(this: &v25, amount: len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v25.data, Src: this->token.data, Size: len);
      v25.data[len] = 0;
      v25.len = len;
      idCompiler::NextToken(this);
      idTypeDef::AddFunctionParm(this: &v27, parmtype: v11, name: v25.data);
      ++v10;
      if ( idStr::Cmp(s1: this->token.data, s2: ",") != 0 )
      {
        v16 = 0;
      }
      else
      {
        idCompiler::NextToken(this);
        v16 = 1;
      }
      if ( v16 == 0 )
        goto LABEL_15;
    }
    if ( v10 != 0 || (unsigned __int8)idCompiler::CheckToken(this, string: ")") == 0 )
      idCompiler::Error(
        this,
        message: "'void' cannot be used to define function parameters, except for functions with no parameters",
        a3: v14,
        a4: v13,
        a5: v12,
        a6: v19,
        a7: v20,
        a8: v21,
        a9: v22,
        a10: v23,
        a11: v24);
    v8 = 1;
LABEL_15:
    if ( v8 == 0 )
      idCompiler::ExpectToken(this, string: ")");
    idStr::FreeData(this: &v25);
  }
  Type = idProgram::GetType(this: &gameLocal->program, type: &v27, allocate: true);
  idTypeDef::~idTypeDef(this: &v27);
  return Type;
}


// ========================================================================
// $LN76
// EA  : 0x82E8F248
// RVA : 0x00E8F248
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _LN76()
{
  int v0; // r12

  idTypeDef::~idTypeDef(this: (idTypeDef *)(v0 - 368 + 160));
}


// ========================================================================
// __unwind$494460
// EA  : 0x82E8F270
// RVA : 0x00E8F270
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_494460()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 112));
}


// ========================================================================
// ?ParseEventDef@idCompiler@@AAAXPAVidTypeDef@@PBD@Z
// EA  : 0x82E8F2A0
// RVA : 0x00E8F2A0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ParseEventDef(idCompiler *this, idTypeDef *returnType, const char *name)
{
  int v3; // r29
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  const idEventDef *Event; // r3
  int *v11; // r18
  char v12; // r11
  __int64 v13; // r10
  __int64 v14; // r8
  bfx::ObstacleImpl *TypeForEventArg; // r3
  __int64 v16; // r6
  int v17; // r3
  __int64 v18; // r10
  __int64 v19; // r8
  const bfx::Vec3 *CachedSize; // r3
  int v21; // r26
  _BYTE *v22; // r24
  int i; // r25
  __int64 v24; // r10
  __int64 v25; // r8
  idTypeDef *v26; // r3
  idTypeDef *v27; // r30
  idTypeDef *v28; // r28
  __int64 v29; // r10
  __int64 v30; // r8
  __int64 v31; // r6
  __int64 v32; // r10
  __int64 v33; // r8
  __int64 v34; // r10
  __int64 v35; // r8
  char v36; // r11
  bfx::ObstacleImpl *v37; // r3
  char *data; // r30
  int v39; // r3
  __int64 v40; // r6
  __int64 v41; // r10
  __int64 v42; // r6
  const idTypeDef *Type; // r3
  const idTypeDef *v44; // r25
  __int64 v45; // r10
  __int64 v46; // r8
  __int64 v47; // r6
  idTypeDef *v48; // r27
  idVarDef *v49; // r3
  idList<int,37> *v50; // r3
  idList<int,37> *v51; // r27
  idList<int,37> *v52; // r30
  int v53; // r28
  bfx::SystemInstance *ParmType; // r24
  const bfx::Vec3 *v55; // r3
  int *list; // r25
  int v57; // [sp+8h] [-198h]
  int v58; // [sp+Ch] [-194h]
  int v59; // [sp+10h] [-190h]
  int v60; // [sp+14h] [-18Ch]
  int v61; // [sp+18h] [-188h]
  int v62; // [sp+1Ch] [-184h]
  idStr v63; // [sp+80h] [-120h] BYREF
  idTypeDef v64[2]; // [sp+A0h] [-100h] BYREF

  v3 = 0;
  v63.len = 0;
  v63.allocedAndFlag = 20;
  v63.data = v63.baseBuffer;
  v63.baseBuffer[0] = 0;
  Event = idEventDef::FindEvent(name);
  v11 = (int *)Event;
  if ( Event != nullptr )
  {
    TypeForEventArg = (bfx::ObstacleImpl *)idCompiler::GetTypeForEventArg(this, argType: Event->returnType);
    if ( TypeForEventArg == nullptr )
    {
      LODWORD(v16) = name;
      HIDWORD(v16) = (char)v13;
      idCompiler::Error(
        this,
        message: "Invalid return type '%c' in definition of '%s' event.",
        a3: v16,
        a4: v14,
        a5: v13,
        a6: v57,
        a7: v58,
        a8: v59,
        a9: v60,
        a10: v61,
        a11: v62);
    }
    if ( returnType != (idTypeDef *)TypeForEventArg )
    {
      v17 = idFile_MTP::GetName(pObstacle: TypeForEventArg);
      idCompiler::Error(
        this,
        message: "Return type doesn't match internal return type '%s' for '%s' event",
        a3: __SPAIR64__(v17, (unsigned int)name),
        a4: v19,
        a5: v18,
        a6: v57,
        a7: v58,
        a8: v59,
        a9: v60,
        a10: v61,
        a11: v62);
    }
    CachedSize = idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)&type_function);
    idTypeDef::idTypeDef(
      this: v64,
      etype: ev_function,
      edef: nullptr,
      ename: name,
      esize: (int)CachedSize,
      aux: returnType);
    idCompiler::ExpectToken(this, string: "(");
    v21 = 0;
    v22 = (_BYTE *)v11[1];
    if ( *v22 != 0 )
    {
      do
        ++v21;
      while ( v22[v21] != 0 );
    }
    for ( i = 0; i < v21; ++i )
    {
      v26 = idCompiler::GetTypeForEventArg(this, argType: v22[i]);
      v27 = v26;
      if ( v26 == nullptr || v26 == &type_void )
      {
        LODWORD(v42) = name;
        HIDWORD(v42) = (char)v24;
        idCompiler::Error(
          this,
          message: "Invalid parameter '%c' in definition of '%s' event.",
          a3: v42,
          a4: v25,
          a5: v24,
          a6: v57,
          a7: v58,
          a8: v59,
          a9: v60,
          a10: v61,
          a11: v62);
      }
      v28 = idCompiler::ParseType(this);
      idCompiler::ParseName(this, name: &v63, a3: v31, a4: v30, a5: v29);
      if ( v28 != v27 )
      {
        v37 = (bfx::ObstacleImpl *)v27;
        data = v63.data;
        v39 = idFile_MTP::GetName(pObstacle: v37);
        LODWORD(v40) = data;
        HIDWORD(v40) = i + 1;
        idCompiler::Error(
          this,
          message: "The type of parm %d ('%s') does not match the internal type '%s' in definition of '%s' event.",
          a3: v40,
          a4: __SPAIR64__(v39, (unsigned int)name),
          a5: v41,
          a6: v57,
          a7: v58,
          a8: v59,
          a9: v60,
          a10: v61,
          a11: v62);
      }
      idTypeDef::AddFunctionParm(this: v64, parmtype: v28, name: &byte_8200D768);
      if ( i < v21 - 1 )
      {
        if ( (unsigned __int8)idCompiler::CheckToken(this, string: ")") != 0 )
          idCompiler::Error(
            this,
            message: "Too few parameters for event definition of '%s' event.  Internal definition has %d parameters.",
            a3: __SPAIR64__((unsigned int)name, v21),
            a4: v33,
            a5: v32,
            a6: v57,
            a7: v58,
            a8: v59,
            a9: v60,
            a10: v61,
            a11: v62);
        idCompiler::ExpectToken(this, string: ",");
      }
    }
    if ( idStr::Cmp(s1: this->token.data, s2: ")") != 0 )
    {
      v36 = 0;
    }
    else
    {
      idCompiler::NextToken(this);
      v36 = 1;
    }
    if ( v36 == 0 )
      idCompiler::Error(
        this,
        message: "Too many parameters for event definition of '%s' event.  Internal definition has %d parameters.",
        a3: __SPAIR64__((unsigned int)name, v21),
        a4: v35,
        a5: v34,
        a6: v57,
        a7: v58,
        a8: v59,
        a9: v60,
        a10: v61,
        a11: v62);
    idCompiler::ExpectToken(this, string: ";");
    Type = idProgram::FindType(this: &gameLocal->program, name);
    v44 = Type;
    if ( Type != nullptr )
    {
      if ( !idTypeDef::MatchesType(this: v64, matchtype: Type)
        || (LODWORD(v45) = v44->def->value.value.cp, HIDWORD(v45) = *(_DWORD *)v45, *(int **)v45 != v11) )
      {
        HIDWORD(v47) = name;
        idCompiler::Error(
          this,
          message: "Type mismatch on redefinition of '%s'",
          a3: v47,
          a4: v46,
          a5: v45,
          a6: v57,
          a7: v58,
          a8: v59,
          a9: v60,
          a10: v61,
          a11: v62);
      }
    }
    else
    {
      v48 = idProgram::AllocType(this: &gameLocal->program, type: v64);
      v49 = idProgram::AllocDef(
              this: &gameLocal->program,
              type: v48,
              name,
              scope: &def_namespace,
              size: 1,
              constant: true,
              isTypeDeclaration: false);
      v48->def = v49;
      v50 = (idList<int,37> *)idProgram::AllocFunction(this: &gameLocal->program, def: v49);
      v50->list = v11;
      v51 = v50 + 2;
      v52 = v50;
      idList<idObstacleBuffers *,5>::SetNum(this: v50 + 2, newNum: v21);
      if ( v21 > 0 )
      {
        v53 = 0;
        do
        {
          ParmType = (bfx::SystemInstance *)idTypeDef::GetParmType(this: v64, parmNumber: v3);
          v55 = idreports::MapWarning::GetCachedSize(this: ParmType);
          list = v51->list;
          v52[1].num += (int)v55;
          ++v3;
          list[v53++] = (int)idreports::MapWarning::GetCachedSize(this: ParmType);
        }
        while ( v3 < v21 );
      }
      v52[1].size = v52[1].num;
    }
    idTypeDef::~idTypeDef(this: v64);
  }
  else
  {
    HIDWORD(v9) = name;
    idCompiler::Warning(
      this,
      message: "Unknown event '%s'",
      a3: v9,
      a4: v8,
      a5: v7,
      a6: v57,
      a7: v58,
      a8: v59,
      a9: v60,
      a10: v61,
      a11: v62);
    idCompiler::ExpectToken(this, string: "(");
    while ( 1 )
    {
      if ( idStr::Cmp(s1: this->token.data, s2: ")") != 0 )
      {
        v12 = 0;
      }
      else
      {
        idCompiler::NextToken(this);
        v12 = 1;
      }
      if ( v12 != 0 )
        break;
      idCompiler::NextToken(this);
    }
    idCompiler::ExpectToken(this, string: ";");
  }
  idStr::FreeData(this: &v63);
}


// ========================================================================
// $LN80_5
// EA  : 0x82E8F6C4
// RVA : 0x00E8F6C4
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _LN80_5()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 128));
}


// ========================================================================
// __unwind$494599
// EA  : 0x82E8F6EC
// RVA : 0x00E8F6EC
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_494599()
{
  int v0; // r12

  idTypeDef::~idTypeDef(this: (idTypeDef *)(v0 - 416 + 160));
}


// ========================================================================
// ?ParseFunctionCall@idCompiler@@AAAPAVidVarDef@@PAV2@@Z
// EA  : 0x82E8F720
// RVA : 0x00E8F720
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::ParseFunctionCall(idCompiler *this, idVarDef *funcDef)
{
  idTypeDef *typeDef; // r3
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  __int64 v8; // r6
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  __int64 v12; // r10
  __int64 v13; // r8
  int v14; // r4
  idTypeDef *v15; // r3
  bfx::Planner3D *v16; // r3
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  int v21; // [sp+8h] [-A8h]
  int v22; // [sp+Ch] [-A4h]
  int v23; // [sp+10h] [-A0h]
  int v24; // [sp+14h] [-9Ch]
  int v25; // [sp+18h] [-98h]
  int v26; // [sp+1Ch] [-94h]
  idVarDef v27[2]; // [sp+70h] [-40h] BYREF

  typeDef = funcDef->typeDef;
  if ( typeDef == nullptr || idScriptObject::GetTypeDef(this: (bfx::Planner3D *)typeDef) != (bfx::Space *)10 )
  {
    HIDWORD(v8) = idVarDef::Name(this: funcDef);
    idCompiler::Error(
      this,
      message: "'%s' is not a function",
      a3: v8,
      a4: v10,
      a5: v9,
      a6: v21,
      a7: v22,
      a8: v23,
      a9: v24,
      a10: v25,
      a11: v26);
  }
  if ( funcDef->initialized == uninitialized )
  {
    HIDWORD(v11) = idVarDef::GlobalName(this: v27, result: (idStr *)funcDef)->data;
    idCompiler::Error(
      this,
      message: "Function '%s' has not been defined yet",
      a3: v11,
      a4: v13,
      a5: v12,
      a6: v21,
      a7: v22,
      a8: v23,
      a9: v24,
      a10: v25,
      a11: v26);
  }
  if ( this->callthread )
  {
    LODWORD(v5) = *funcDef->value.value.ip;
    if ( (_DWORD)v5 != 0 )
      idCompiler::Error(
        this,
        message: "Built-in functions cannot be called as threads",
        a3: v7,
        a4: v6,
        a5: v5,
        a6: v21,
        a7: v22,
        a8: v23,
        a9: v24,
        a10: v25,
        a11: v26);
    v14 = 190;
    this->callthread = false;
    return idCompiler::EmitFunctionParms(this, op: v14, func: funcDef, startarg: nullptr, startsize: 0, object: nullptr);
  }
  if ( *funcDef->value.value.ip == 0 )
  {
    v14 = 189;
    return idCompiler::EmitFunctionParms(this, op: v14, func: funcDef, startarg: nullptr, startsize: 0, object: nullptr);
  }
  v15 = this->scope->typeDef;
  if ( v15 != nullptr && idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v15) == (bfx::Space *)2
    || (LODWORD(v5) = this->scope->scope, (v16 = *(bfx::Planner3D **)(v5 + 20)) == nullptr)
    || idScriptObject::GetTypeDef(this: v16) != (bfx::Space *)13 )
  {
    idCompiler::Error(
      this,
      message: "Built-in functions cannot be called without an object",
      a3: v7,
      a4: v6,
      a5: v5,
      a6: v21,
      a7: v22,
      a8: v23,
      a9: v24,
      a10: v25,
      a11: v26);
  }
  HIDWORD(v19) = idProgram::GetDef(
                   this: &gameLocal->program,
                   type: this->scope->scope->typeDef,
                   name: "self",
                   scope: this->scope);
  if ( HIDWORD(v19) == 0 )
    idCompiler::Error(
      this,
      message: "No 'self' within scope",
      a3: (unsigned int)v19,
      a4: v18,
      a5: v17,
      a6: v21,
      a7: v22,
      a8: v23,
      a9: v24,
      a10: v25,
      a11: v26);
  LODWORD(v19) = funcDef;
  return idCompiler::ParseEventCall(this, op: 96, funcDef: v19, a4: v18, a5: v17);
}


// ========================================================================
// $LN37_1
// EA  : 0x82E8F8A8
// RVA : 0x00E8F8A8
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _LN37_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// ?GetExpression@idCompiler@@AAAPAVidVarDef@@H@Z
// EA  : 0x82E8F8D0
// RVA : 0x00E8F8D0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

idVarDef *__fastcall idCompiler::GetExpression(idCompiler *this, int priority)
{
  idVarDef *Expression; // r24
  char v5; // r11
  opcode_t *v6; // r29
  __int64 v7; // r8
  __int64 v8; // r6
  long double v9; // fp4
  double v10; // fp2
  double v11; // fp1
  char v12; // r11
  const idVarDef *basetype; // r30
  int num; // r10
  statement_t *v15; // r11
  statement_t *v16; // r31
  unsigned int op; // r11
  idVarDef *FreeResultDef; // r3
  int v19; // r4
  idVarDef *v20; // r27
  __int64 v21; // r8
  __int64 v22; // r6
  long double v23; // fp4
  double v24; // fp2
  double v25; // fp1
  bfx::Planner3D *typeDef; // r3
  bfx::Space *v27; // r28
  bfx::Planner3D *v28; // r3
  bfx::Space *v29; // r30
  bfx::Planner3D *v30; // r3
  bfx::Planner3D *v31; // r3
  bfx::Space *v32; // r26
  bfx::Planner3D *v33; // r3
  opcode_t *v34; // r31
  bfx::Planner3D *v35; // r3
  bfx::Space *v36; // r3
  __int64 v37; // r10
  bfx::Planner3D *v38; // r3
  bfx::Space *v39; // r3
  bfx::Planner3D *v40; // r3
  bfx::Space *v41; // r3
  bfx::Planner3D *v42; // r3
  bfx::Space *v43; // r3
  bfx::Planner3D *v44; // r3
  bfx::Space *v45; // r3
  const char *name; // r11
  bool v47; // zf
  int v48; // r31
  __int64 v49; // r10
  __int64 v50; // r8
  __int64 v51; // r6
  __int64 v52; // r10
  __int64 v53; // r8
  long double v54; // fp4
  double v55; // fp2
  double v56; // fp1
  __int64 v57; // r10
  __int64 v58; // r8
  bfx::Planner3D *v59; // r3
  __int64 v60; // r10
  __int64 v61; // r8
  __int64 v62; // r6
  bfx::Planner3D *v63; // r3
  bfx::Planner3D *v64; // r3
  bfx::Planner3D *v65; // r3
  bfx::Planner3D *v66; // r3
  bfx::Planner3D *v67; // r3
  bfx::Planner3D *v68; // r3
  __int64 v69; // r6
  statement_t *v70; // r31
  opcode_t *v71; // r30
  const char *v72; // r11
  __int64 v73; // r10
  bfx::Planner3D *v74; // r3
  bfx::Space *v75; // r31
  bfx::Planner3D *v76; // r3
  bfx::Space *v77; // r3
  __int64 v78; // r6
  int v79; // [sp+8h] [-F8h]
  int v80; // [sp+Ch] [-F4h]
  int v81; // [sp+10h] [-F0h]
  int v82; // [sp+14h] [-ECh]
  int v83; // [sp+18h] [-E8h]
  int v84; // [sp+1Ch] [-E4h]

  if ( priority == 0 )
    return idCompiler::GetTerm(this);
  Expression = idCompiler::GetExpression(this, priority: priority - 1);
  if ( idStr::Cmp(s1: this->token.data, s2: ";") == 0 )
    return Expression;
  while ( 1 )
  {
    if ( priority == 2 )
    {
      if ( idStr::Cmp(s1: this->token.data, s2: "(") != 0 )
      {
        v5 = 0;
      }
      else
      {
        idCompiler::NextToken(this);
        v5 = 1;
      }
      if ( v5 != 0 )
        return idCompiler::ParseFunctionCall(this, funcDef: Expression);
    }
    if ( this->immediateType != nullptr )
      return Expression;
    v6 = idCompiler::opcodes;
    if ( idCompiler::opcodes[0].name == nullptr )
      return Expression;
    while ( 1 )
    {
      if ( v6->priority == priority )
      {
        if ( idStr::Cmp(s1: this->token.data, s2: v6->name) != 0 )
        {
          v12 = 0;
        }
        else
        {
          idCompiler::NextToken(this);
          v12 = 1;
        }
        if ( v12 != 0 )
          break;
      }
      ++v6;
      if ( v6->name == nullptr )
        return Expression;
    }
    if ( v6->name == nullptr )
      return Expression;
    if ( v6->type_b == &def_void )
      break;
    basetype = this->basetype;
    if ( *v6->name == 46 && idTypeDef::Inherits(this: Expression->typeDef, basetype: &type_object) )
      this->basetype = Expression->typeDef->def;
    if ( v6->rightAssociative )
    {
      num = gameLocal->program.statements.num;
      if ( num > 0 )
      {
        v15 = &gameLocal->program.statements.list[num];
        v16 = v15 - 1;
        op = v15[-1].op;
        if ( op >= 0x57 && op < 0x5F )
        {
          v16->op = 95;
          idTypeDef::SetPointerType(this: &type_pointer, pointertype: Expression->typeDef);
          ++v16->c->numUsers;
          FreeResultDef = idCompiler::FindFreeResultDef(
                            this,
                            type: &type_pointer,
                            scope: this->scope,
                            a: v16->a,
                            b: v16->b);
          v16->c = FreeResultDef;
          Expression = FreeResultDef;
        }
      }
      v19 = priority;
    }
    else
    {
      v19 = priority - 1;
    }
    v20 = idCompiler::GetExpression(this, priority: v19);
    this->basetype = basetype;
    typeDef = (bfx::Planner3D *)Expression->typeDef;
    if ( typeDef != nullptr )
      v27 = idScriptObject::GetTypeDef(this: typeDef);
    else
      v27 = nullptr;
    v28 = (bfx::Planner3D *)v20->typeDef;
    if ( v28 != nullptr )
      v29 = idScriptObject::GetTypeDef(this: v28);
    else
      v29 = nullptr;
    if ( *v6->name == 46 )
    {
      v30 = (bfx::Planner3D *)v20->typeDef;
      if ( v30 != nullptr
        && idScriptObject::GetTypeDef(this: v30) == (bfx::Space *)10
        && idTypeDef::ReturnType(this: v20->typeDef) != nullptr )
      {
        v31 = (bfx::Planner3D *)idTypeDef::ReturnType(this: v20->typeDef);
        v32 = idScriptObject::GetTypeDef(this: v31);
      }
      else if ( idTypeDef::FieldType(this: v20->typeDef) != nullptr )
      {
        v33 = (bfx::Planner3D *)idTypeDef::FieldType(this: v20->typeDef);
        v32 = idScriptObject::GetTypeDef(this: v33);
      }
      else
      {
        v32 = (bfx::Space *)-1;
      }
    }
    else
    {
      v32 = nullptr;
    }
    v34 = v6;
    while ( 1 )
    {
      v35 = (bfx::Planner3D *)v6->type_a->typeDef;
      v36 = v35 != nullptr ? idScriptObject::GetTypeDef(this: v35) : nullptr;
      LODWORD(v37) = _cntlzw((char *)v36 - (char *)v27);
      HIDWORD(v37) = (v37 & 0x20) != 0;
      if ( (v37 & 0x20) != 0 )
      {
        v38 = (bfx::Planner3D *)v6->type_b->typeDef;
        v39 = v38 != nullptr ? idScriptObject::GetTypeDef(this: v38) : nullptr;
        LODWORD(v37) = _cntlzw((char *)v39 - (char *)v29);
        HIDWORD(v37) = (v37 & 0x20) != 0;
        if ( (v37 & 0x20) != 0 )
        {
          if ( v32 == nullptr )
            break;
          v40 = (bfx::Planner3D *)v6->type_c->typeDef;
          v41 = v40 != nullptr ? idScriptObject::GetTypeDef(this: v40) : nullptr;
          LODWORD(v37) = _cntlzw((char *)v41 - (char *)v32);
          HIDWORD(v37) = (v37 & 0x20) != 0;
          if ( (v37 & 0x20) != 0 )
            break;
        }
      }
      if ( v6->priority == 2 )
      {
        v42 = (bfx::Planner3D *)v6->type_a->typeDef;
        v43 = v42 != nullptr ? idScriptObject::GetTypeDef(this: v42) : nullptr;
        LODWORD(v37) = _cntlzw((char *)v43 - (char *)v27);
        HIDWORD(v37) = (v37 & 0x20) != 0;
        if ( (v37 & 0x20) != 0 )
        {
          v44 = (bfx::Planner3D *)v6->type_b->typeDef;
          v45 = v44 != nullptr ? idScriptObject::GetTypeDef(this: v44) : nullptr;
          LODWORD(v37) = _cntlzw((char *)v45 - (char *)v29);
          HIDWORD(v37) = (v37 & 0x20) != 0;
          if ( (v37 & 0x20) != 0 )
            break;
        }
      }
      ++v6;
      name = v6->name;
      if ( v6->name != nullptr )
      {
        LODWORD(v37) = v34->name;
        do
        {
          HIDWORD(v37) = *(unsigned __int8 *)name;
          LODWORD(v21) = *(unsigned __int8 *)v37;
          v47 = HIDWORD(v37) == 0;
          HIDWORD(v37) -= v21;
          if ( v47 )
            break;
          ++name;
          LODWORD(v37) = v37 + 1;
        }
        while ( HIDWORD(v37) == 0 );
        if ( HIDWORD(v37) == 0 )
          continue;
      }
      HIDWORD(v22) = v34->name;
      idCompiler::Error(
        this,
        message: "type mismatch for '%s'",
        a3: v22,
        a4: v21,
        a5: v37,
        a6: v79,
        a7: v80,
        a8: v81,
        a9: v82,
        a10: v83,
        a11: v84);
    }
    v48 = v6 - idCompiler::opcodes;
    switch ( v48 )
    {
      case '`':
      case 'c':
        idCompiler::ExpectToken(this, string: "(");
        if ( v20->initialized == uninitialized )
          goto LABEL_80;
        LODWORD(v57) = *v20->value.value.ip;
        if ( (_DWORD)v57 == 0 )
          goto LABEL_80;
        Expression = idCompiler::ParseEventCall(
                       this,
                       op: v6 - idCompiler::opcodes,
                       funcDef: __SPAIR64__((unsigned int)Expression, (unsigned int)v20),
                       a4: v58,
                       a5: v57);
        break;
      case 'a':
        idCompiler::ExpectToken(this, string: "(");
        if ( v20->initialized != uninitialized && (LODWORD(v52) = *v20->value.value.ip, (_DWORD)v52 != 0) )
          Expression = idCompiler::ParseEventCall(
                         this,
                         op: 96,
                         funcDef: __SPAIR64__((unsigned int)Expression, (unsigned int)v20),
                         a4: v53,
                         a5: v52);
        else
LABEL_80:
          Expression = idCompiler::ParseObjectCall(this, object: Expression, func: v20, a4: v56, a5: v55, a6: v54);
        break;
      case 'b':
        idCompiler::ExpectToken(this, string: "(");
        Expression = idCompiler::ParseSysObjectCall(this, funcDef: v20, a3: v51, a4: v50, a5: v49);
        break;
      case 'd':
      case 'e':
      case 'f':
      case 'g':
      case 'h':
      case 'i':
      case 'k':
      case 'l':
      case 'm':
      case 'n':
      case 'o':
      case 'p':
        Expression = idCompiler::EmitOpcode(
                       this,
                       op: &idCompiler::opcodes[v48],
                       var_b: __SPAIR64__((unsigned int)Expression, (unsigned int)v20),
                       a4: v25,
                       a5: v24,
                       a6: v23);
        idCompiler::ExpectToken(this, string: "]");
        break;
      default:
        if ( this->callthread )
          idCompiler::Error(
            this,
            message: "Expecting function call after 'thread'",
            a3: v22,
            a4: v21,
            a5: v37,
            a6: v79,
            a7: v80,
            a8: v81,
            a9: v82,
            a10: v83,
            a11: v84);
        if ( v27 == (bfx::Space *)12 )
        {
          v59 = (bfx::Planner3D *)idTypeDef::PointerType(this: Expression->typeDef);
          if ( v29 != idScriptObject::GetTypeDef(this: v59) )
          {
            if ( v48 == 131
              && (v63 = (bfx::Planner3D *)idTypeDef::PointerType(this: Expression->typeDef),
                  idScriptObject::GetTypeDef(this: v63) == (bfx::Space *)5) )
            {
              v6 = &idCompiler::opcodes[141];
            }
            else if ( v48 == 134
                   && (v64 = (bfx::Planner3D *)idTypeDef::PointerType(this: Expression->typeDef),
                       idScriptObject::GetTypeDef(this: v64) == (bfx::Space *)4) )
            {
              v6 = &idCompiler::opcodes[142];
            }
            else if ( v48 == 131
                   && (v65 = (bfx::Planner3D *)idTypeDef::PointerType(this: Expression->typeDef),
                       idScriptObject::GetTypeDef(this: v65) == (bfx::Space *)3) )
            {
              v6 = &idCompiler::opcodes[144];
            }
            else if ( v48 == 134
                   && (v66 = (bfx::Planner3D *)idTypeDef::PointerType(this: Expression->typeDef),
                       idScriptObject::GetTypeDef(this: v66) == (bfx::Space *)3) )
            {
              v6 = &idCompiler::opcodes[143];
            }
            else if ( v48 == 132
                   && (v67 = (bfx::Planner3D *)idTypeDef::PointerType(this: Expression->typeDef),
                       idScriptObject::GetTypeDef(this: v67) == (bfx::Space *)3) )
            {
              v6 = &idCompiler::opcodes[145];
            }
            else
            {
              if ( v48 != 135
                || (v68 = (bfx::Planner3D *)idTypeDef::PointerType(this: Expression->typeDef),
                    idScriptObject::GetTypeDef(this: v68) != (bfx::Space *)13) )
              {
                HIDWORD(v62) = v6->name;
                idCompiler::Error(
                  this,
                  message: "type mismatch for '%s'",
                  a3: v62,
                  a4: v61,
                  a5: v60,
                  a6: v79,
                  a7: v80,
                  a8: v81,
                  a9: v82,
                  a10: v83,
                  a11: v84);
              }
              v6 = &idCompiler::opcodes[140];
            }
          }
        }
        if ( v6->rightAssociative )
          v69 = __PAIR64__((unsigned int)v20, (unsigned int)Expression);
        else
          v69 = __PAIR64__((unsigned int)Expression, (unsigned int)v20);
        Expression = idCompiler::EmitOpcode(this, op: v6, var_b: v69, a4: v25, a5: v24, a6: v23);
        if ( (((char *)v6 - (char *)idCompiler::opcodes) & 0xFFFFFFE0) == 0x1180 )
        {
          v70 = &gameLocal->program.statements.list[gameLocal->program.statements.num];
          v70[-1].c = idTypeDef::PointerType(this: &type_pointer)->def;
        }
        if ( v32 != nullptr )
          Expression->typeDef = idTypeDef::FieldType(this: v20->typeDef);
        break;
    }
  }
  v71 = v6;
  while ( 1 )
  {
    v72 = v6->name;
    if ( v6->name == nullptr )
    {
      LODWORD(v73) = v71->name;
      do
      {
        HIDWORD(v73) = *(unsigned __int8 *)v72;
        LODWORD(v7) = *(unsigned __int8 *)v73;
        v47 = HIDWORD(v73) == 0;
        HIDWORD(v73) -= v7;
        if ( v47 )
          break;
        ++v72;
        LODWORD(v73) = v73 + 1;
      }
      while ( HIDWORD(v73) == 0 );
      if ( HIDWORD(v73) != 0 )
      {
        HIDWORD(v8) = v71->name;
        idCompiler::Error(
          this,
          message: "type mismatch for '%s'",
          a3: v8,
          a4: v7,
          a5: v73,
          a6: v79,
          a7: v80,
          a8: v81,
          a9: v82,
          a10: v83,
          a11: v84);
      }
    }
    v74 = (bfx::Planner3D *)v6->type_a->typeDef;
    v75 = v74 != nullptr ? idScriptObject::GetTypeDef(this: v74) : nullptr;
    v76 = (bfx::Planner3D *)Expression->typeDef;
    v77 = v76 != nullptr ? idScriptObject::GetTypeDef(this: v76) : nullptr;
    if ( v75 == v77 )
      break;
    ++v6;
  }
  LODWORD(v78) = 0;
  HIDWORD(v78) = Expression;
  return idCompiler::EmitOpcode(this, op: v6, var_b: v78, a4: v11, a5: v10, a6: v9);
}


// ========================================================================
// ?ParseReturnStatement@idCompiler@@AAAXXZ
// EA  : 0x82E900E0
// RVA : 0x00E900E0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ParseReturnStatement(idCompiler *this)
{
  char v2; // r11
  bfx::Planner3D *v3; // r3
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  long double v7; // fp4
  double v8; // fp2
  double v9; // fp1
  idVarDef *Expression; // r26
  bfx::Planner3D *typeDef; // r3
  bfx::Space *v12; // r30
  bfx::Planner3D *v13; // r3
  bfx::Space *v14; // r25
  __int64 v15; // r6
  long double v16; // fp4
  double v17; // fp2
  double v18; // fp1
  char v19; // r9
  __int64 v20; // r8
  __int64 v21; // r6
  const char *i; // r11
  opcode_t *v23; // r29
  const char *v24; // r10
  int v25; // r9
  int v26; // r9
  bool v27; // zf
  bfx::Planner3D *v28; // r3
  bfx::Space *v29; // r3
  __int64 v30; // r10
  bfx::Planner3D *v31; // r3
  bfx::Space *v32; // r3
  const char *name; // r11
  bfx::Planner3D *v34; // r30
  bfx::Space *v35; // r3
  long double v36; // fp4
  double v37; // fp2
  double v38; // fp1
  __int64 v39; // r6
  long double v40; // fp4
  double v41; // fp2
  double v42; // fp1
  __int64 v43; // r6
  int v44; // [sp+8h] [-98h]
  int v45; // [sp+Ch] [-94h]
  int v46; // [sp+10h] [-90h]
  int v47; // [sp+14h] [-8Ch]
  int v48; // [sp+18h] [-88h]
  int v49; // [sp+1Ch] [-84h]

  if ( idStr::Cmp(s1: this->token.data, s2: ";") != 0 )
  {
    v2 = 0;
  }
  else
  {
    idCompiler::NextToken(this);
    v2 = 1;
  }
  if ( v2 != 0 )
  {
    v3 = (bfx::Planner3D *)idTypeDef::ReturnType(this: this->scope->typeDef);
    if ( idScriptObject::GetTypeDef(this: v3) != nullptr )
      idCompiler::Error(
        this,
        message: "expecting return value",
        a3: v6,
        a4: v5,
        a5: v4,
        a6: v44,
        a7: v45,
        a8: v46,
        a9: v47,
        a10: v48,
        a11: v49);
    idCompiler::CleanUpLists(this, excludeVar: nullptr);
    idCompiler::EmitOpcode(this, op: idCompiler::opcodes, var_b: 0, a4: v9, a5: v8, a6: v7);
  }
  else
  {
    Expression = idCompiler::GetExpression(this, priority: 15);
    idCompiler::CleanUpLists(this, excludeVar: Expression);
    idCompiler::ExpectToken(this, string: ";");
    typeDef = (bfx::Planner3D *)Expression->typeDef;
    if ( typeDef != nullptr )
      v12 = idScriptObject::GetTypeDef(this: typeDef);
    else
      v12 = nullptr;
    v13 = (bfx::Planner3D *)idTypeDef::ReturnType(this: this->scope->typeDef);
    v14 = idScriptObject::GetTypeDef(this: v13);
    v19 = _cntlzw((char *)v12 - (char *)v14);
    LODWORD(v20) = (v19 & 0x20) != 0;
    if ( (v19 & 0x20) != 0 )
    {
      LODWORD(v21) = 0;
      HIDWORD(v21) = Expression;
      idCompiler::EmitOpcode(this, op: idCompiler::opcodes, var_b: v21, a4: v18, a5: v17, a6: v16);
    }
    else
    {
      v23 = idCompiler::opcodes;
      for ( i = idCompiler::opcodes[0].name; v23->name != nullptr; i = v23->name )
      {
        v24 = "=";
        do
        {
          v25 = *(unsigned __int8 *)i;
          LODWORD(v20) = *(unsigned __int8 *)v24;
          v27 = v25 == 0;
          v26 = v25 - v20;
          if ( v27 )
            break;
          ++i;
          ++v24;
        }
        while ( v26 == 0 );
        if ( v26 == 0 )
          break;
        ++v23;
      }
      while ( 1 )
      {
        v28 = (bfx::Planner3D *)v23->type_a->typeDef;
        v29 = v28 != nullptr ? idScriptObject::GetTypeDef(this: v28) : nullptr;
        LODWORD(v30) = _cntlzw((char *)v29 - (char *)v14);
        HIDWORD(v30) = (v30 & 0x20) != 0;
        if ( (v30 & 0x20) != 0 )
        {
          v31 = (bfx::Planner3D *)v23->type_b->typeDef;
          v32 = v31 != nullptr ? idScriptObject::GetTypeDef(this: v31) : nullptr;
          LODWORD(v30) = _cntlzw((char *)v32 - (char *)v12);
          HIDWORD(v30) = (v30 & 0x20) != 0;
          if ( (v30 & 0x20) != 0 )
            break;
        }
        ++v23;
        name = v23->name;
        if ( v23->name != nullptr )
        {
          LODWORD(v30) = "=";
          do
          {
            HIDWORD(v30) = *(unsigned __int8 *)name;
            LODWORD(v20) = *(unsigned __int8 *)v30;
            v27 = HIDWORD(v30) == 0;
            HIDWORD(v30) -= v20;
            if ( v27 )
              break;
            ++name;
            LODWORD(v30) = v30 + 1;
          }
          while ( HIDWORD(v30) == 0 );
          if ( HIDWORD(v30) == 0 )
            continue;
        }
        idCompiler::Error(
          this,
          message: "type mismatch for return value",
          a3: v15,
          a4: v20,
          a5: v30,
          a6: v44,
          a7: v45,
          a8: v46,
          a9: v47,
          a10: v48,
          a11: v49);
      }
      v34 = (bfx::Planner3D *)idTypeDef::ReturnType(this: this->scope->typeDef);
      v35 = idScriptObject::GetTypeDef(this: v34);
      HIDWORD(v39) = Expression;
      if ( v35 == (bfx::Space *)3 )
      {
        LODWORD(v39) = gameLocal->program.returnStringDef;
        idCompiler::EmitOpcode(this, op: v23, var_b: v39, a4: v38, a5: v37, a6: v36);
        LODWORD(v43) = 0;
        HIDWORD(v43) = gameLocal->program.returnStringDef;
      }
      else
      {
        gameLocal->program.returnDef->typeDef = (idTypeDef *)v34;
        LODWORD(v39) = gameLocal->program.returnDef;
        idCompiler::EmitOpcode(this, op: v23, var_b: v39, a4: v38, a5: v37, a6: v36);
        HIDWORD(v43) = gameLocal->program.returnDef;
        LODWORD(v43) = 0;
      }
      idCompiler::EmitOpcode(this, op: idCompiler::opcodes, var_b: v43, a4: v42, a5: v41, a6: v40);
    }
  }
}


// ========================================================================
// ?ParseWhileStatement@idCompiler@@AAAXXZ
// EA  : 0x82E903B0
// RVA : 0x00E903B0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ParseWhileStatement(idCompiler *this)
{
  char *data; // r3
  int loopDepth; // r11
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  int num; // r26
  idVarDef *Expression; // r28
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  long double v12; // fp4
  double v13; // fp2
  double v14; // fp1
  __int64 v15; // r6
  long double v16; // fp4
  double v17; // fp2
  double v18; // fp1
  __int64 v19; // r6
  __int64 v20; // r28
  int v21; // r25
  __int64 v22; // r6
  long double v23; // fp4
  double v24; // fp2
  double v25; // fp1
  int v26; // r8
  int v27; // [sp+8h] [-C8h]
  int v28; // [sp+Ch] [-C4h]
  int v29; // [sp+10h] [-C0h]
  int v30; // [sp+14h] [-BCh]
  int v31; // [sp+18h] [-B8h]
  int v32; // [sp+1Ch] [-B4h]
  eval_s v33; // [sp+70h] [-60h] BYREF

  loopDepth = this->loopDepth;
  data = this->token.data;
  this->loopDepth = loopDepth + 1;
  if ( idStr::Cmp(s1: data, s2: "(") != 0 )
  {
    LODWORD(v6) = this->token.data;
    HIDWORD(v6) = "(";
    idCompiler::Error(
      this,
      message: "expected '%s', found '%s'",
      a3: v6,
      a4: v5,
      a5: v4,
      a6: v27,
      a7: v28,
      a8: v29,
      a9: v30,
      a10: v31,
      a11: v32);
  }
  idCompiler::NextToken(this);
  num = gameLocal->program.statements.num;
  Expression = idCompiler::GetExpression(this, priority: 15);
  if ( idStr::Cmp(s1: this->token.data, s2: ")") != 0 )
  {
    LODWORD(v11) = this->token.data;
    HIDWORD(v11) = ")";
    idCompiler::Error(
      this,
      message: "expected '%s', found '%s'",
      a3: v11,
      a4: v10,
      a5: v9,
      a6: v27,
      a7: v28,
      a8: v29,
      a9: v30,
      a10: v31,
      a11: v32);
  }
  idCompiler::NextToken(this);
  if ( Expression->initialized == initializedConstant && *Expression->value.value.ip != 0 )
  {
    idCompiler::ParseStatement(this);
    HIDWORD(v15) = idCompiler::JumpTo(this, jumpto: num);
    LODWORD(v15) = 0;
    idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[208], var_b: v15, a4: v18, a5: v17, a6: v16);
  }
  else
  {
    LODWORD(v19) = 0;
    HIDWORD(v20) = idCompiler::opcodes;
    HIDWORD(v19) = Expression;
    v21 = gameLocal->program.statements.num;
    idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[188], var_b: v19, a4: v14, a5: v13, a6: v12);
    idCompiler::ParseStatement(this);
    LODWORD(v20) = 0;
    *(_QWORD *)&v33.stringPtr = v20;
    *((_QWORD *)&v33._int + 1) = v20;
    v33._int = num - gameLocal->program.statements.num;
    HIDWORD(v22) = idCompiler::FindImmediate(
                     this,
                     type: (bfx::Planner3D *)&type_jumpoffset,
                     eval: &v33,
                     string: &byte_8200D768);
    LODWORD(v22) = 0;
    idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[208], var_b: v22, a4: v25, a5: v24, a6: v23);
    v26 = gameLocal->program.statements.num;
    v33.vector[1] = 0.0;
    *((_QWORD *)&v33._int + 1) = v20;
    v33._int = v26 - v21;
    gameLocal->program.statements.list[v21].b = idCompiler::FindImmediate(
                                                  this,
                                                  type: (bfx::Planner3D *)&type_jumpoffset,
                                                  eval: &v33,
                                                  string: &byte_8200D768);
  }
  idCompiler::PatchLoop(this, start: num, continuePos: num);
  --this->loopDepth;
}


// ========================================================================
// ?ParseForStatement@idCompiler@@AAAXXZ
// EA  : 0x82E905B0
// RVA : 0x00E905B0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ParseForStatement(idCompiler *this)
{
  int loopDepth; // r10
  char *data; // r3
  int num; // r19
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  __int64 v8; // r21
  char v9; // r11
  char v10; // r11
  int v11; // r25
  idVarDef *Expression; // r26
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  __int64 v16; // r6
  int v17; // r22
  long double v18; // fp4
  double v19; // fp2
  double v20; // fp1
  long double v21; // fp4
  double v22; // fp2
  double v23; // fp1
  char v24; // r11
  __int64 v25; // r6
  int v26; // r26
  int v27; // r24
  char v28; // r11
  __int64 v29; // r6
  long double v30; // fp4
  double v31; // fp2
  double v32; // fp1
  int v33; // r4
  statement_t *v34; // r26
  int v35; // r7
  __int64 v36; // r6
  long double v37; // fp4
  double v38; // fp2
  double v39; // fp1
  int v40; // r9
  int v41; // [sp+8h] [-E8h]
  int v42; // [sp+Ch] [-E4h]
  int v43; // [sp+10h] [-E0h]
  int v44; // [sp+14h] [-DCh]
  int v45; // [sp+18h] [-D8h]
  int v46; // [sp+1Ch] [-D4h]
  eval_s v47; // [sp+70h] [-80h] BYREF

  loopDepth = this->loopDepth;
  data = this->token.data;
  this->loopDepth = loopDepth + 1;
  num = gameLocal->program.statements.num;
  if ( idStr::Cmp(s1: data, s2: "(") != 0 )
  {
    LODWORD(v7) = this->token.data;
    HIDWORD(v7) = "(";
    idCompiler::Error(
      this,
      message: "expected '%s', found '%s'",
      a3: v7,
      a4: v6,
      a5: v5,
      a6: v41,
      a7: v42,
      a8: v43,
      a9: v44,
      a10: v45,
      a11: v46);
  }
  idCompiler::NextToken(this);
  LODWORD(v8) = 0;
  if ( idStr::Cmp(s1: this->token.data, s2: ";") != 0 )
  {
    v9 = 0;
  }
  else
  {
    idCompiler::NextToken(this);
    v9 = 1;
  }
  HIDWORD(v8) = ",";
  if ( v9 == 0 )
  {
    do
    {
      idCompiler::GetExpression(this, priority: 15);
      if ( idStr::Cmp(s1: this->token.data, s2: ",") != 0 )
      {
        v10 = 0;
      }
      else
      {
        idCompiler::NextToken(this);
        v10 = 1;
      }
    }
    while ( v10 != 0 );
    idCompiler::ExpectToken(this, string: ";");
  }
  v11 = gameLocal->program.statements.num;
  Expression = idCompiler::GetExpression(this, priority: 15);
  if ( idStr::Cmp(s1: this->token.data, s2: ";") != 0 )
  {
    LODWORD(v15) = this->token.data;
    HIDWORD(v15) = ";";
    idCompiler::Error(
      this,
      message: "expected '%s', found '%s'",
      a3: v15,
      a4: v14,
      a5: v13,
      a6: v41,
      a7: v42,
      a8: v43,
      a9: v44,
      a10: v45,
      a11: v46);
  }
  idCompiler::NextToken(this);
  LODWORD(v16) = 0;
  HIDWORD(v16) = Expression;
  v17 = gameLocal->program.statements.num;
  idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[188], var_b: v16, a4: v20, a5: v19, a6: v18);
  if ( idStr::Cmp(s1: this->token.data, s2: ")") != 0 )
  {
    v24 = 0;
  }
  else
  {
    idCompiler::NextToken(this);
    v24 = 1;
  }
  if ( v24 == 0 )
  {
    HIDWORD(v25) = Expression;
    LODWORD(v25) = 0;
    v26 = gameLocal->program.statements.num;
    idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[187], var_b: v25, a4: v23, a5: v22, a6: v21);
    v27 = v11;
    v11 = gameLocal->program.statements.num;
    do
    {
      idCompiler::GetExpression(this, priority: 15);
      if ( idStr::Cmp(s1: this->token.data, s2: ",") != 0 )
      {
        v28 = 0;
      }
      else
      {
        idCompiler::NextToken(this);
        v28 = 1;
      }
    }
    while ( v28 != 0 );
    idCompiler::ExpectToken(this, string: ")");
    HIDWORD(v29) = idCompiler::JumpTo(this, jumpto: v27);
    LODWORD(v29) = 0;
    idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[208], var_b: v29, a4: v32, a5: v31, a6: v30);
    v33 = v26;
    v34 = &gameLocal->program.statements.list[v26];
    v34->b = idCompiler::JumpFrom(this, jumpfrom: v33);
  }
  idCompiler::ParseStatement(this);
  v35 = gameLocal->program.statements.num;
  v47.vector[1] = 0.0;
  *((_QWORD *)&v47._int + 1) = v8;
  v47._int = v11 - v35;
  HIDWORD(v36) = idCompiler::FindImmediate(
                   this,
                   type: (bfx::Planner3D *)&type_jumpoffset,
                   eval: &v47,
                   string: &byte_8200D768);
  LODWORD(v36) = 0;
  idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[208], var_b: v36, a4: v39, a5: v38, a6: v37);
  v40 = gameLocal->program.statements.num;
  v47.vector[1] = 0.0;
  *((_QWORD *)&v47._int + 1) = v8;
  v47._int = v40 - v17;
  gameLocal->program.statements.list[v17].b = idCompiler::FindImmediate(
                                                this,
                                                type: (bfx::Planner3D *)&type_jumpoffset,
                                                eval: &v47,
                                                string: &byte_8200D768);
  idCompiler::PatchLoop(this, start: num, continuePos: v11);
  --this->loopDepth;
}


// ========================================================================
// ?ParseDoWhileStatement@idCompiler@@AAAXXZ
// EA  : 0x82E908E0
// RVA : 0x00E908E0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ParseDoWhileStatement(idCompiler *this)
{
  int num; // r30
  __int64 v3; // r10
  __int64 v4; // r8
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  idVarDef *Expression; // r26
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  __int64 v16; // r11
  idVarDef *Immediate; // r3
  long double v18; // fp4
  double v19; // fp2
  double v20; // fp1
  int v21; // [sp+8h] [-B8h]
  int v22; // [sp+Ch] [-B4h]
  int v23; // [sp+10h] [-B0h]
  int v24; // [sp+14h] [-ACh]
  int v25; // [sp+18h] [-A8h]
  int v26; // [sp+1Ch] [-A4h]
  eval_s v27[5]; // [sp+70h] [-50h] BYREF

  ++this->loopDepth;
  num = gameLocal->program.statements.num;
  idCompiler::ParseStatement(this);
  if ( idStr::Cmp(s1: this->token.data, s2: "while") != 0 )
  {
    LODWORD(v5) = this->token.data;
    HIDWORD(v5) = "while";
    idCompiler::Error(
      this,
      message: "expected '%s', found '%s'",
      a3: v5,
      a4: v4,
      a5: v3,
      a6: v21,
      a7: v22,
      a8: v23,
      a9: v24,
      a10: v25,
      a11: v26);
  }
  idCompiler::NextToken(this);
  if ( idStr::Cmp(s1: this->token.data, s2: "(") != 0 )
  {
    LODWORD(v8) = this->token.data;
    HIDWORD(v8) = "(";
    idCompiler::Error(
      this,
      message: "expected '%s', found '%s'",
      a3: v8,
      a4: v7,
      a5: v6,
      a6: v21,
      a7: v22,
      a8: v23,
      a9: v24,
      a10: v25,
      a11: v26);
  }
  idCompiler::NextToken(this);
  Expression = idCompiler::GetExpression(this, priority: 15);
  if ( idStr::Cmp(s1: this->token.data, s2: ")") != 0 )
  {
    LODWORD(v12) = this->token.data;
    HIDWORD(v12) = ")";
    idCompiler::Error(
      this,
      message: "expected '%s', found '%s'",
      a3: v12,
      a4: v11,
      a5: v10,
      a6: v21,
      a7: v22,
      a8: v23,
      a9: v24,
      a10: v25,
      a11: v26);
  }
  idCompiler::NextToken(this);
  if ( idStr::Cmp(s1: this->token.data, s2: ";") != 0 )
  {
    LODWORD(v15) = this->token.data;
    HIDWORD(v15) = ";";
    idCompiler::Error(
      this,
      message: "expected '%s', found '%s'",
      a3: v15,
      a4: v14,
      a5: v13,
      a6: v21,
      a7: v22,
      a8: v23,
      a9: v24,
      a10: v25,
      a11: v26);
  }
  idCompiler::NextToken(this);
  HIDWORD(v16) = v27;
  LODWORD(v16) = 0;
  *(_QWORD *)HIDWORD(v16) = v16;
  *(_QWORD *)(HIDWORD(v16) + 8) = v16;
  v27[0]._int = num - gameLocal->program.statements.num;
  Immediate = idCompiler::FindImmediate(
                this,
                type: (bfx::Planner3D *)&type_jumpoffset,
                eval: v27,
                string: &byte_8200D768);
  idCompiler::EmitOpcode(
    this,
    op: &idCompiler::opcodes[187],
    var_b: __SPAIR64__((unsigned int)Expression, (unsigned int)Immediate),
    a4: v20,
    a5: v19,
    a6: v18);
  idCompiler::PatchLoop(this, start: num, continuePos: num);
  --this->loopDepth;
}


// ========================================================================
// ?ParseIfStatement@idCompiler@@AAAXXZ
// EA  : 0x82E90A90
// RVA : 0x00E90A90
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ParseIfStatement(idCompiler *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  idVarDef *Expression; // r28
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  __int64 v9; // r6
  int num; // r28
  long double v11; // fp4
  double v12; // fp2
  double v13; // fp1
  long double v14; // fp4
  double v15; // fp2
  double v16; // fp1
  char v17; // r11
  idCompiler *v18; // r3
  int v19; // r27
  int v20; // r4
  statement_t *v21; // r28
  idCompiler *v22; // r3
  statement_t *list; // r31
  statement_t *v24; // r31
  int v25; // [sp+8h] [-98h]
  int v26; // [sp+Ch] [-94h]
  int v27; // [sp+10h] [-90h]
  int v28; // [sp+14h] [-8Ch]
  int v29; // [sp+18h] [-88h]
  int v30; // [sp+1Ch] [-84h]

  if ( idStr::Cmp(s1: this->token.data, s2: "(") != 0 )
  {
    LODWORD(v4) = this->token.data;
    HIDWORD(v4) = "(";
    idCompiler::Error(
      this,
      message: "expected '%s', found '%s'",
      a3: v4,
      a4: v3,
      a5: v2,
      a6: v25,
      a7: v26,
      a8: v27,
      a9: v28,
      a10: v29,
      a11: v30);
  }
  idCompiler::NextToken(this);
  Expression = idCompiler::GetExpression(this, priority: 15);
  if ( idStr::Cmp(s1: this->token.data, s2: ")") != 0 )
  {
    LODWORD(v8) = this->token.data;
    HIDWORD(v8) = ")";
    idCompiler::Error(
      this,
      message: "expected '%s', found '%s'",
      a3: v8,
      a4: v7,
      a5: v6,
      a6: v25,
      a7: v26,
      a8: v27,
      a9: v28,
      a10: v29,
      a11: v30);
  }
  idCompiler::NextToken(this);
  HIDWORD(v9) = Expression;
  LODWORD(v9) = 0;
  num = gameLocal->program.statements.num;
  idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[188], var_b: v9, a4: v13, a5: v12, a6: v11);
  idCompiler::ParseStatement(this);
  if ( idStr::Cmp(s1: this->token.data, s2: "else") != 0 )
  {
    v17 = 0;
  }
  else
  {
    idCompiler::NextToken(this);
    v17 = 1;
  }
  v18 = this;
  if ( v17 != 0 )
  {
    v19 = gameLocal->program.statements.num;
    idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[208], var_b: 0, a4: v16, a5: v15, a6: v14);
    v20 = num;
    v21 = &gameLocal->program.statements.list[num];
    v21->b = idCompiler::JumpFrom(this, jumpfrom: v20);
    idCompiler::ParseStatement(this);
    v22 = this;
    list = gameLocal->program.statements.list;
    list[v19].a = idCompiler::JumpFrom(this: v22, jumpfrom: v19);
  }
  else
  {
    v24 = &gameLocal->program.statements.list[num];
    v24->b = idCompiler::JumpFrom(this: v18, jumpfrom: num);
  }
}


// ========================================================================
// ?ParseStatement@idCompiler@@AAAXXZ
// EA  : 0x82E90C38
// RVA : 0x00E90C38
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ParseStatement(idCompiler *this)
{
  char v2; // r11
  char v3; // r11
  char v4; // r11
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  long double v8; // fp4
  double v9; // fp2
  double v10; // fp1
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  long double v14; // fp4
  double v15; // fp2
  double v16; // fp1
  int v17; // [sp+8h] [-78h]
  int v18; // [sp+Ch] [-74h]
  int v19; // [sp+10h] [-70h]
  int v20; // [sp+14h] [-6Ch]
  int v21; // [sp+18h] [-68h]
  int v22; // [sp+1Ch] [-64h]

  if ( idStr::Cmp(s1: this->token.data, s2: ";") != 0 )
  {
    v2 = 0;
  }
  else
  {
    idCompiler::NextToken(this);
    v2 = 1;
  }
  if ( v2 == 0 )
  {
    if ( idStr::Cmp(s1: this->token.data, s2: "{") != 0 )
    {
      v3 = 0;
    }
    else
    {
      idCompiler::NextToken(this);
      v3 = 1;
    }
    if ( v3 != 0 )
    {
      do
      {
        idCompiler::ParseStatement(this);
        if ( idStr::Cmp(s1: this->token.data, s2: "}") != 0 )
        {
          v4 = 0;
        }
        else
        {
          idCompiler::NextToken(this);
          v4 = 1;
        }
      }
      while ( v4 == 0 );
    }
    else if ( (unsigned __int8)idCompiler::CheckToken(this, string: "return") != 0 )
    {
      idCompiler::ParseReturnStatement(this);
    }
    else if ( (unsigned __int8)idCompiler::CheckToken(this, string: "while") != 0 )
    {
      idCompiler::ParseWhileStatement(this);
    }
    else if ( (unsigned __int8)idCompiler::CheckToken(this, string: "for") != 0 )
    {
      idCompiler::ParseForStatement(this);
    }
    else if ( (unsigned __int8)idCompiler::CheckToken(this, string: "do") != 0 )
    {
      idCompiler::ParseDoWhileStatement(this);
    }
    else if ( (unsigned __int8)idCompiler::CheckToken(this, string: "break") != 0 )
    {
      idCompiler::ExpectToken(this, string: ";");
      if ( this->loopDepth == 0 )
        idCompiler::Error(
          this,
          message: "cannot break outside of a loop",
          a3: v7,
          a4: v6,
          a5: v5,
          a6: v17,
          a7: v18,
          a8: v19,
          a9: v20,
          a10: v21,
          a11: v22);
      idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[209], var_b: 0, a4: v10, a5: v9, a6: v8);
    }
    else if ( (unsigned __int8)idCompiler::CheckToken(this, string: "continue") != 0 )
    {
      idCompiler::ExpectToken(this, string: ";");
      if ( this->loopDepth == 0 )
        idCompiler::Error(
          this,
          message: "cannot contine outside of a loop",
          a3: v13,
          a4: v12,
          a5: v11,
          a6: v17,
          a7: v18,
          a8: v19,
          a9: v20,
          a10: v21,
          a11: v22);
      idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[210], var_b: 0, a4: v16, a5: v15, a6: v14);
    }
    else if ( idCompiler::CheckType(this) != nullptr )
    {
      idCompiler::ParseDefs(this);
    }
    else if ( (unsigned __int8)idCompiler::CheckToken(this, string: "if") != 0 )
    {
      idCompiler::ParseIfStatement(this);
    }
    else
    {
      idCompiler::GetExpression(this, priority: 15);
      idCompiler::ExpectToken(this, string: ";");
    }
  }
}


// ========================================================================
// ?ParseFunctionDef@idCompiler@@AAAXPAVidTypeDef@@PBD@Z
// EA  : 0x82E90EC8
// RVA : 0x00E90EC8
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ParseFunctionDef(idCompiler *this, idTypeDef *returnType, const char *name)
{
  idTypeDef *typeDef; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  idTypeDef *v10; // r20
  idStr *Def; // r3
  idVarDef *v12; // r18
  idVarDef *v13; // r3
  function_t *data; // r15
  idDeclSource *v15; // r3
  idList<int,58> *p_parmSize; // r27
  int v17; // r23
  int v18; // r29
  int v19; // r30
  bfx::SystemInstance *ParmType; // r26
  int *list; // r26
  __int64 v22; // r6
  __int64 v23; // r10
  __int64 v24; // r8
  int *v25; // r24
  int v26; // r10
  char v27; // r11
  __int64 v28; // r10
  __int64 v29; // r8
  __int64 v30; // r6
  int i; // r30
  const char *ParmName; // r29
  const idTypeDef *v33; // r3
  const char *v34; // r29
  idTypeDef *v35; // r3
  idVarDef *scope; // r16
  const char *v37; // r3
  idTypeDef *v38; // r29
  __int64 v39; // r6
  __int64 v40; // r10
  __int64 v41; // r8
  va *v42; // r3
  function_t *Function; // r30
  __int64 v44; // r6
  __int64 v45; // r10
  __int64 v46; // r8
  const char *v47; // r29
  const idTypeDef *v48; // r3
  idVarDef *v49; // r3
  long double v50; // fp4
  double v51; // fp2
  double v52; // fp1
  __int64 v53; // r6
  long double v54; // fp4
  double v55; // fp2
  double v56; // fp1
  char v57; // r11
  idTypeDef *v58; // r30
  __int64 v59; // r6
  __int64 v60; // r10
  __int64 v61; // r8
  va *v62; // r3
  function_t *v63; // r21
  idGameLocal *v64; // r11
  int firstStatement; // r29
  statement_t *v66; // r30
  __int64 v67; // r10
  idGameLocal *v68; // r11
  const char *v69; // r30
  const idTypeDef *v70; // r3
  idVarDef *v71; // r3
  long double v72; // fp4
  double v73; // fp2
  double v74; // fp1
  __int64 v75; // r6
  long double v76; // fp4
  double v77; // fp2
  double v78; // fp1
  long double v79; // fp4
  double v80; // fp2
  double v81; // fp1
  const char *v82; // r3
  int v83; // [sp+8h] [-1138h]
  int v84; // [sp+Ch] [-1134h]
  int v85; // [sp+10h] [-1130h]
  int v86; // [sp+14h] [-112Ch]
  int v87; // [sp+18h] [-1128h]
  int v88; // [sp+1Ch] [-1124h]
  eval_s v89; // [sp+70h] [-10D0h] BYREF
  idVarDef v90; // [sp+80h] [-10C0h] BYREF
  va v91; // [sp+A0h] [-10A0h] BYREF

  typeDef = this->scope->typeDef;
  if ( typeDef == nullptr || idScriptObject::GetTypeDef(this: (bfx::Planner3D *)typeDef) != (bfx::Space *)2 )
  {
    LODWORD(v7) = idTypeDef::Inherits(this: this->scope->typeDef, basetype: &type_object);
    if ( (_DWORD)v7 == 0 )
      idCompiler::Error(
        this,
        message: "Functions may not be defined within other functions",
        a3: v9,
        a4: v8,
        a5: v7,
        a6: v83,
        a7: v84,
        a8: v85,
        a9: v86,
        a10: v87,
        a11: v88);
  }
  v10 = idCompiler::ParseFunction(this, returnType, name);
  Def = (idStr *)idProgram::GetDef(this: &gameLocal->program, type: v10, name, scope: this->scope);
  v12 = (idVarDef *)Def;
  if ( Def != nullptr )
  {
    data = (function_t *)Def->data;
    if ( data->firstStatement != 0 )
    {
      HIDWORD(v22) = idVarDef::GlobalName(this: &v90, result: Def)->data;
      idCompiler::Error(
        this,
        message: "%s redeclared",
        a3: v22,
        a4: v24,
        a5: v23,
        a6: v83,
        a7: v84,
        a8: v85,
        a9: v86,
        a10: v87,
        a11: v88);
    }
  }
  else
  {
    v13 = idProgram::AllocDef(
            this: &gameLocal->program,
            type: v10,
            name,
            scope: this->scope,
            size: 1,
            constant: true,
            isTypeDeclaration: false);
    v10->def = v13;
    v12 = v13;
    data = idProgram::AllocFunction(this: &gameLocal->program, def: v13);
    if ( idTypeDef::Inherits(this: this->scope->typeDef, basetype: &type_object) )
      idTypeDef::AddFunction(this: this->scope->typeDef, func: data);
  }
  v15 = function_t::Name(this: (idDecl *)v10);
  p_parmSize = &data->parmSize;
  data->parmTotal = 0;
  v17 = (int)v15;
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&data->parmSize, newNum: (int)v15);
  v18 = 0;
  if ( v17 > 0 )
  {
    v19 = 0;
    do
    {
      ParmType = (bfx::SystemInstance *)idTypeDef::GetParmType(this: v10, parmNumber: v18);
      if ( idTypeDef::Inherits(this: (idTypeDef *)ParmType, basetype: &type_object) )
      {
        list = p_parmSize->list;
        list[v19] = (int)idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)&type_object);
      }
      else
      {
        v25 = p_parmSize->list;
        v25[v19] = (int)idreports::MapWarning::GetCachedSize(this: ParmType);
      }
      ++v18;
      v26 = p_parmSize->list[v19++];
      data->parmTotal += v26;
    }
    while ( v18 < v17 );
  }
  if ( idStr::Cmp(s1: this->token.data, s2: "{") != 0 )
  {
    v27 = 0;
  }
  else
  {
    idCompiler::NextToken(this);
    v27 = 1;
  }
  if ( v27 != 0 )
  {
    for ( i = 0; i < v17; ++i )
    {
      ParmName = idTypeDef::GetParmName(this: v10, parmNumber: i);
      v33 = idTypeDef::GetParmType(this: v10, parmNumber: i);
      if ( idProgram::GetDef(this: &gameLocal->program, type: v33, name: ParmName, scope: v12) != nullptr )
      {
        HIDWORD(v44) = idTypeDef::GetParmName(this: v10, parmNumber: i);
        idCompiler::Error(
          this,
          message: "'%s' defined more than once in function parameters",
          a3: v44,
          a4: v46,
          a5: v45,
          a6: v83,
          a7: v84,
          a8: v85,
          a9: v86,
          a10: v87,
          a11: v88);
      }
      v34 = idTypeDef::GetParmName(this: v10, parmNumber: i);
      v35 = idTypeDef::GetParmType(this: v10, parmNumber: i);
      idProgram::AllocDef(
        this: &gameLocal->program,
        type: v35,
        name: v34,
        scope: v12,
        size: 1,
        constant: false,
        isTypeDeclaration: false);
    }
    scope = this->scope;
    this->scope = v12;
    if ( g_debugScript.valueInteger != 0 )
    {
      v37 = idVarDef::Name(this: v12);
      idLib::Printf(fmt: "Function: %s\n", v37);
    }
    data->firstStatement = gameLocal->program.statements.num;
    if ( idTypeDef::Inherits(this: scope->typeDef, basetype: &type_object) && idStr::Icmp(s1: name, s2: "init") == 0 )
    {
      v38 = idTypeDef::SuperClass(this: scope->typeDef);
      if ( v38 != &type_object )
      {
        while ( 1 )
        {
          HIDWORD(v39) = idFile_MTP::GetName(pObstacle: (bfx::ObstacleImpl *)v38);
          v42 = va::va(
                  this: &v91,
                  fmt: "%s::init",
                  a3: v39,
                  a4: v41,
                  a5: v40,
                  a6: v83,
                  a7: v84,
                  a8: v85,
                  a9: v86,
                  a10: v87,
                  a11: v88);
          Function = idProgram::FindFunction(this: &gameLocal->program, name: v42->buffer);
          if ( Function != nullptr )
            break;
          v38 = idTypeDef::SuperClass(this: v38);
          if ( v38 == &type_object )
            goto LABEL_36;
        }
        v47 = idTypeDef::GetParmName(this: v10, parmNumber: 0);
        v48 = idTypeDef::GetParmType(this: v10, parmNumber: 0);
        v49 = idProgram::GetDef(this: &gameLocal->program, type: v48, name: v47, scope: v12);
        idCompiler::EmitPush(this, expression: v49, funcArg: (bfx::Planner3D *)v49->typeDef, a4: v52, a5: v51, a6: v50);
        LODWORD(v53) = 0;
        HIDWORD(v53) = Function->def;
        idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[189], var_b: v53, a4: v56, a5: v55, a6: v54);
      }
    }
LABEL_36:
    while ( 1 )
    {
      if ( idStr::Cmp(s1: this->token.data, s2: "}") != 0 )
      {
        v57 = 0;
      }
      else
      {
        idCompiler::NextToken(this);
        v57 = 1;
      }
      if ( v57 != 0 )
        break;
      idCompiler::ParseStatement(this);
    }
    if ( idTypeDef::Inherits(this: scope->typeDef, basetype: &type_object) && idStr::Icmp(s1: name, s2: "destroy") == 0 )
    {
      v58 = idTypeDef::SuperClass(this: scope->typeDef);
      if ( v58 != &type_object )
      {
        while ( 1 )
        {
          HIDWORD(v59) = idFile_MTP::GetName(pObstacle: (bfx::ObstacleImpl *)v58);
          v62 = va::va(
                  this: &v91,
                  fmt: "%s::destroy",
                  a3: v59,
                  a4: v61,
                  a5: v60,
                  a6: v83,
                  a7: v84,
                  a8: v85,
                  a9: v86,
                  a10: v87,
                  a11: v88);
          v63 = idProgram::FindFunction(this: &gameLocal->program, name: v62->buffer);
          if ( v63 != nullptr )
            break;
          v58 = idTypeDef::SuperClass(this: v58);
          if ( v58 == &type_object )
            goto LABEL_53;
        }
        v64 = gameLocal;
        firstStatement = data->firstStatement;
        if ( firstStatement < gameLocal->program.statements.num )
        {
          v66 = &gameLocal->program.statements.list[firstStatement];
          do
          {
            if ( v66->op == 0 )
            {
              v66->op = -48;
              HIDWORD(v67) = &v89;
              v68 = gameLocal;
              LODWORD(v67) = 0;
              *(_QWORD *)HIDWORD(v67) = v67;
              *(_QWORD *)(HIDWORD(v67) + 8) = v67;
              v89._int = v68->program.statements.num - firstStatement;
              v66->a = idCompiler::FindImmediate(
                         this,
                         type: (bfx::Planner3D *)&type_jumpoffset,
                         eval: &v89,
                         string: &byte_8200D768);
              v64 = gameLocal;
            }
            ++firstStatement;
            ++v66;
          }
          while ( firstStatement < v64->program.statements.num );
        }
        v69 = idTypeDef::GetParmName(this: v10, parmNumber: 0);
        v70 = idTypeDef::GetParmType(this: v10, parmNumber: 0);
        v71 = idProgram::GetDef(this: &gameLocal->program, type: v70, name: v69, scope: v12);
        idCompiler::EmitPush(this, expression: v71, funcArg: (bfx::Planner3D *)v71->typeDef, a4: v74, a5: v73, a6: v72);
        LODWORD(v75) = 0;
        HIDWORD(v75) = v63->def;
        idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[189], var_b: v75, a4: v78, a5: v77, a6: v76);
      }
    }
LABEL_53:
    idCompiler::CleanUpLists(this, excludeVar: nullptr);
    idCompiler::EmitOpcode(this, op: idCompiler::opcodes, var_b: 0, a4: v81, a5: v80, a6: v79);
    data->numStatements = gameLocal->program.statements.num - data->firstStatement;
    if ( g_debugScript.valueInteger != 0 )
    {
      v82 = idVarDef::Name(this: this->scope);
      idLib::Printf(fmt: "Function END: %s\n", v82);
    }
    this->scope = scope;
  }
  else
  {
    if ( idStr::Cmp(s1: this->token.data, s2: ";") != 0 )
    {
      LODWORD(v30) = this->token.data;
      HIDWORD(v30) = ";";
      idCompiler::Error(
        this,
        message: "expected '%s', found '%s'",
        a3: v30,
        a4: v29,
        a5: v28,
        a6: v83,
        a7: v84,
        a8: v85,
        a9: v86,
        a10: v87,
        a11: v88);
    }
    idCompiler::NextToken(this);
  }
}


// ========================================================================
// $LN165_0
// EA  : 0x82E9155C
// RVA : 0x00E9155C
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _LN165_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4416 + 128));
}


// ========================================================================
// ?ParseVariableDef@idCompiler@@AAAXPAVidTypeDef@@PBD@Z
// EA  : 0x82E91588
// RVA : 0x00E91588
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ParseVariableDef(idCompiler *this, idTypeDef *type, const char *name)
{
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  int v9; // r28
  char v10; // r11
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  idVarDef *v14; // r3
  idTypeDef *typeDef; // r11
  idVarDef *v16; // r3
  long double v17; // fp4
  double v18; // fp2
  double v19; // fp1
  idVarDef *v20; // r22
  __int64 v21; // r10
  __int64 v22; // r8
  __int64 v23; // r6
  char v24; // r11
  idTypeDef *v25; // r3
  idVarDef *Expression; // r3
  long double v27; // fp4
  double v28; // fp2
  double v29; // fp1
  idVarDef *v30; // r30
  idTypeDef *v31; // r3
  long double v32; // fp4
  double v33; // fp2
  double v34; // fp1
  __int64 v35; // r10
  __int64 v36; // r8
  __int64 v37; // r6
  long double v38; // fp4
  double v39; // fp2
  double v40; // fp1
  idTypeDef *v41; // r11
  char v42; // r30
  const char *stringPtr; // r11
  char v44; // r30
  double v45; // fp0
  idTypeDef *v46; // r3
  int v47; // [sp+8h] [-E8h]
  int v48; // [sp+Ch] [-E4h]
  int v49; // [sp+10h] [-E0h]
  int v50; // [sp+14h] [-DCh]
  int v51; // [sp+18h] [-D8h]
  int v52; // [sp+1Ch] [-D4h]

  if ( idProgram::GetDef(this: &gameLocal->program, type, name, scope: this->scope) != nullptr )
  {
    HIDWORD(v8) = name;
    idCompiler::Error(
      this,
      message: "%s redeclared",
      a3: v8,
      a4: v7,
      a5: v6,
      a6: v47,
      a7: v48,
      a8: v49,
      a9: v50,
      a10: v51,
      a11: v52);
  }
  v9 = 1;
  if ( idStr::Cmp(s1: this->token.data, s2: "[") != 0 )
  {
    v10 = 0;
  }
  else
  {
    idCompiler::NextToken(this);
    v10 = 1;
  }
  if ( v10 != 0 )
  {
    v14 = idCompiler::ParseImmediate(this);
    typeDef = v14->typeDef;
    if ( typeDef == &type_integer )
    {
      v9 = *v14->value.value.ip;
    }
    else
    {
      if ( typeDef != &type_float )
      {
        HIDWORD(v13) = name;
        idCompiler::Error(
          this,
          message: "Wrong type for array size of '%s'",
          a3: v13,
          a4: v12,
          a5: v11,
          a6: v47,
          a7: v48,
          a8: v49,
          a9: v50,
          a10: v51,
          a11: v52);
      }
      v9 = (int)*v14->value.value.fp;
    }
    idCompiler::ExpectToken(this, string: "]");
  }
  v16 = idProgram::AllocDef(
          this: &gameLocal->program,
          type,
          name,
          scope: this->scope,
          size: v9,
          constant: false,
          isTypeDeclaration: false);
  v20 = v16;
  if ( type == &type_list )
    idCompiler::EmitOpcode(this, op: &idCompiler::opcodes[192], var_b: (unsigned int)v16, a4: v19, a5: v18, a6: v17);
  if ( idStr::Cmp(s1: this->token.data, s2: "=") != 0 )
  {
    v24 = 0;
  }
  else
  {
    idCompiler::NextToken(this);
    v24 = 1;
  }
  if ( v24 != 0 )
  {
    v25 = this->scope->typeDef;
    if ( v25 != nullptr && idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v25) == (bfx::Space *)10 )
    {
      Expression = idCompiler::GetExpression(this, priority: 15);
      v30 = Expression;
      if ( type == &type_float && Expression->typeDef == &type_float )
      {
        idCompiler::EmitOpcode(
          this,
          op: &idCompiler::opcodes[114],
          var_b: __SPAIR64__((unsigned int)Expression, (unsigned int)v20),
          a4: v29,
          a5: v28,
          a6: v27);
        return;
      }
      if ( type == &type_vector && Expression->typeDef == &type_vector )
      {
        idCompiler::EmitOpcode(
          this,
          op: &idCompiler::opcodes[115],
          var_b: __SPAIR64__((unsigned int)Expression, (unsigned int)v20),
          a4: v29,
          a5: v28,
          a6: v27);
        return;
      }
      if ( type == &type_string && Expression->typeDef == &type_string )
      {
        idCompiler::EmitOpcode(
          this,
          op: &idCompiler::opcodes[117],
          var_b: __SPAIR64__((unsigned int)Expression, (unsigned int)v20),
          a4: v29,
          a5: v28,
          a6: v27);
        return;
      }
      if ( type == &type_integer && Expression->typeDef == &type_integer )
      {
        idCompiler::EmitOpcode(
          this,
          op: &idCompiler::opcodes[118],
          var_b: __SPAIR64__((unsigned int)Expression, (unsigned int)v20),
          a4: v29,
          a5: v28,
          a6: v27);
        return;
      }
      if ( type == &type_entity )
      {
        v31 = Expression->typeDef;
        if ( v31 == &type_entity || idTypeDef::Inherits(this: v31, basetype: &type_object) )
        {
          idCompiler::EmitOpcode(
            this,
            op: &idCompiler::opcodes[119],
            var_b: __SPAIR64__((unsigned int)v30, (unsigned int)v20),
            a4: v29,
            a5: v28,
            a6: v27);
          return;
        }
      }
      if ( idTypeDef::Inherits(this: type, basetype: &type_object) && v30->typeDef == &type_entity )
      {
        idCompiler::EmitOpcode(
          this,
          op: &idCompiler::opcodes[123],
          var_b: __SPAIR64__((unsigned int)v30, (unsigned int)v20),
          a4: v34,
          a5: v33,
          a6: v32);
        return;
      }
      if ( idTypeDef::Inherits(this: type, basetype: &type_object)
        && idTypeDef::Inherits(this: v30->typeDef, basetype: type) )
      {
        idCompiler::EmitOpcode(
          this,
          op: &idCompiler::opcodes[121],
          var_b: __SPAIR64__((unsigned int)v30, (unsigned int)v20),
          a4: v40,
          a5: v39,
          a6: v38);
        return;
      }
      if ( type != &type_string )
        goto LABEL_51;
      v41 = v30->typeDef;
      if ( v41 == &type_float )
      {
        idCompiler::EmitOpcode(
          this,
          op: &idCompiler::opcodes[126],
          var_b: __SPAIR64__((unsigned int)v30, (unsigned int)v20),
          a4: v40,
          a5: v39,
          a6: v38);
        return;
      }
      if ( v41 == &type_integer )
      {
        idCompiler::EmitOpcode(
          this,
          op: &idCompiler::opcodes[129],
          var_b: __SPAIR64__((unsigned int)v30, (unsigned int)v20),
          a4: v40,
          a5: v39,
          a6: v38);
        return;
      }
      if ( v41 == &type_vector )
      {
        idCompiler::EmitOpcode(
          this,
          op: &idCompiler::opcodes[127],
          var_b: __SPAIR64__((unsigned int)v30, (unsigned int)v20),
          a4: v40,
          a5: v39,
          a6: v38);
      }
      else
      {
LABEL_51:
        if ( type == &type_list && v30->typeDef == &type_list )
        {
          idCompiler::EmitOpcode(
            this,
            op: &idCompiler::opcodes[120],
            var_b: __SPAIR64__((unsigned int)v30, (unsigned int)v20),
            a4: v40,
            a5: v39,
            a6: v38);
        }
        else if ( type == &type_float && v30->typeDef == &type_integer )
        {
          idCompiler::EmitOpcode(
            this,
            op: &idCompiler::opcodes[130],
            var_b: __SPAIR64__((unsigned int)v30, (unsigned int)v20),
            a4: v40,
            a5: v39,
            a6: v38);
        }
        else if ( type == &type_integer && v30->typeDef == &type_float )
        {
          idCompiler::EmitOpcode(
            this,
            op: &idCompiler::opcodes[125],
            var_b: __SPAIR64__((unsigned int)v30, (unsigned int)v20),
            a4: v40,
            a5: v39,
            a6: v38);
        }
        else
        {
          if ( type != &type_decl || (LODWORD(v35) = v30->typeDef, (idTypeDef *)v35 != &type_decl) )
          {
            HIDWORD(v37) = name;
            idCompiler::Error(
              this,
              message: "bad initialization for '%s'",
              a3: v37,
              a4: v36,
              a5: v35,
              a6: v47,
              a7: v48,
              a8: v49,
              a9: v50,
              a10: v51,
              a11: v52);
          }
          idCompiler::EmitOpcode(
            this,
            op: &idCompiler::opcodes[122],
            var_b: __SPAIR64__((unsigned int)v30, (unsigned int)v20),
            a4: v40,
            a5: v39,
            a6: v38);
        }
      }
    }
    else if ( type == &type_string )
    {
      LODWORD(v21) = this->immediateType;
      if ( (idTypeDef *)v21 != &type_string )
      {
        HIDWORD(v23) = name;
        idCompiler::Error(
          this,
          message: "global string '%s' not initialized with a string",
          a3: v23,
          a4: v22,
          a5: v21,
          a6: v47,
          a7: v48,
          a8: v49,
          a9: v50,
          a10: v51,
          a11: v52);
      }
      idVarDef::SetString(this: v20, string: this->token.data, constant: false);
      idCompiler::NextToken(this);
    }
    else
    {
      if ( type == &type_float )
      {
        v42 = 0;
        if ( this->token.type == 5 && idStr::Cmp(s1: this->token.data, s2: "-") == 0 )
        {
          v42 = 1;
          idCompiler::NextToken(this);
        }
        if ( this->immediateType == &type_integer )
        {
          stringPtr = this->immediate.stringPtr;
          this->immediateType = &type_float;
          LODWORD(v21) = stringPtr;
          this->immediate._float = (float)v21;
        }
        if ( this->immediateType != &type_float )
        {
          HIDWORD(v23) = name;
          idCompiler::Error(
            this,
            message: "global float '%s' not initialized with a float",
            a3: v23,
            a4: v22,
            a5: v21,
            a6: v47,
            a7: v48,
            a8: v49,
            a9: v50,
            a10: v51,
            a11: v52);
        }
        if ( v42 != 0 )
          this->immediate._float = -this->immediate._float;
      }
      else if ( type == &type_integer )
      {
        v44 = 0;
        if ( this->token.type == 5 && idStr::Cmp(s1: this->token.data, s2: "-") == 0 )
        {
          v44 = 1;
          idCompiler::NextToken(this);
        }
        if ( this->immediateType == &type_float )
        {
          v45 = this->immediate._float;
          LODWORD(v21) = (int)v45;
          if ( v45 == (float)v21 )
          {
            this->immediate._int = (int)v45;
            this->immediateType = &type_integer;
          }
        }
        if ( this->immediateType != &type_integer )
        {
          HIDWORD(v23) = name;
          idCompiler::Error(
            this,
            message: "global integer '%s' not initialized with an integer",
            a3: v23,
            a4: v22,
            a5: v21,
            a6: v47,
            a7: v48,
            a8: v49,
            a9: v50,
            a10: v51,
            a11: v52);
        }
        if ( v44 != 0 )
          this->immediate._int = -this->immediate._int;
      }
      else
      {
        if ( type != &type_decl )
        {
          HIDWORD(v23) = name;
          idCompiler::Error(
            this,
            message: "global '%s' is a type which cannot be initialized",
            a3: v23,
            a4: v22,
            a5: v21,
            a6: v47,
            a7: v48,
            a8: v49,
            a9: v50,
            a10: v51,
            a11: v52);
        }
        LODWORD(v21) = this->immediateType;
        if ( (idTypeDef *)v21 != &type_decl )
        {
          HIDWORD(v23) = name;
          idCompiler::Error(
            this,
            message: "global decl '%s' not initialized with a decl",
            a3: v23,
            a4: v22,
            a5: v21,
            a6: v47,
            a7: v48,
            a8: v49,
            a9: v50,
            a10: v51,
            a11: v52);
        }
      }
      idVarDef::SetValue(this: v20, _value: &this->immediate, constant: false);
      idCompiler::NextToken(this);
    }
  }
  else if ( type == &type_string )
  {
    v46 = this->scope->typeDef;
    if ( v46 == nullptr || idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v46) != (bfx::Space *)10 )
      idVarDef::SetString(this: v20, string: &byte_8200D768, constant: false);
  }
}


// ========================================================================
// ?ParseObjectDef@idCompiler@@AAAXPBD@Z
// EA  : 0x82E91CA0
// RVA : 0x00E91CA0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ParseObjectDef(idCompiler *this, const char *objname)
{
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  idTypeDef *typeDef; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  const bfx::Vec3 *CachedSize; // r7
  idTypeDef *v12; // r29
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  idTypeDef *v16; // r23
  idVarDef *v17; // r3
  int v18; // r28
  const function_t *Function; // r3
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  char v23; // r11
  unsigned __int8 v24; // r11
  bool v25; // r27
  idTypeDef *v26; // r29
  __int64 v27; // r6
  __int64 v28; // r10
  __int64 v29; // r8
  va *v30; // r3
  __int64 v31; // r8
  __int64 v32; // r6
  __int64 v33; // r10
  int len; // r29
  char v35; // r11
  char *data; // r29
  idTypeDef *v37; // r3
  idTypeDef *Type; // r28
  int v39; // r29
  char v40; // r11
  idVarDef *Immediate; // r29
  __int64 v42; // r10
  __int64 v43; // r8
  __int64 v44; // r6
  __int64 v45; // r10
  __int64 v46; // r8
  __int64 v47; // r10
  __int64 v48; // r8
  char v49; // r11
  __int64 v50; // r6
  __int64 v51; // r6
  int v52; // [sp+8h] [-11D8h]
  int v53; // [sp+Ch] [-11D4h]
  int v54; // [sp+10h] [-11D0h]
  int v55; // [sp+14h] [-11CCh]
  int v56; // [sp+18h] [-11C8h]
  int v57; // [sp+1Ch] [-11C4h]
  idTypeDef *v58; // [sp+70h] [-1170h]
  idVarDef *scope; // [sp+78h] [-1168h]
  idStr v60; // [sp+80h] [-1160h] BYREF
  idStr v61; // [sp+A0h] [-1140h] BYREF
  idTypeDef v62; // [sp+C0h] [-1120h] BYREF
  va v63; // [sp+140h] [-10A0h] BYREF

  v60.len = 0;
  v60.allocedAndFlag = 20;
  v60.data = v60.baseBuffer;
  v60.baseBuffer[0] = 0;
  v61.allocedAndFlag = 20;
  v61.data = v61.baseBuffer;
  v61.len = 0;
  v61.baseBuffer[0] = 0;
  idTypeDef::idTypeDef(this: &v62, etype: ev_field, edef: nullptr, ename: &byte_8200D768, esize: 0, aux: nullptr);
  typeDef = this->scope->typeDef;
  scope = this->scope;
  if ( typeDef == nullptr || idScriptObject::GetTypeDef(this: (bfx::Planner3D *)typeDef) != (bfx::Space *)2 )
    idCompiler::Error(
      this,
      message: "Objects cannot be defined within functions or other objects",
      a3: v6,
      a4: v5,
      a5: v4,
      a6: v52,
      a7: v53,
      a8: v54,
      a9: v55,
      a10: v56,
      a11: v57);
  if ( idProgram::FindType(this: &gameLocal->program, name: objname) != nullptr )
  {
    HIDWORD(v10) = objname;
    idCompiler::Error(
      this,
      message: "'%s' : redefinition; different basic types",
      a3: v10,
      a4: v9,
      a5: v8,
      a6: v52,
      a7: v53,
      a8: v54,
      a9: v55,
      a10: v56,
      a11: v57);
  }
  if ( (unsigned __int8)idCompiler::CheckToken(this, string: ":") != 0 )
  {
    v12 = idCompiler::ParseType(this);
    if ( !idTypeDef::Inherits(this: v12, basetype: &type_object) )
      idCompiler::Error(
        this,
        message: "Objects may only inherit from objects.",
        a3: v15,
        a4: v14,
        a5: v13,
        a6: v52,
        a7: v53,
        a8: v54,
        a9: v55,
        a10: v56,
        a11: v57);
    if ( v12 == &type_object )
      CachedSize = nullptr;
    else
      CachedSize = idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)v12);
  }
  else
  {
    CachedSize = nullptr;
    v12 = &type_object;
  }
  v16 = idProgram::AllocType(
          this: &gameLocal->program,
          etype: ev_object,
          edef: nullptr,
          ename: objname,
          esize: (int)CachedSize,
          aux: v12);
  v17 = idProgram::AllocDef(
          this: &gameLocal->program,
          type: v16,
          name: objname,
          scope: this->scope,
          size: 1,
          constant: true,
          isTypeDeclaration: true);
  v16->def = v17;
  v18 = 0;
  for ( this->scope = v17; v18 < (int)idTypeDef::NumFunctions(hSSMDev: v12); ++v18 )
  {
    Function = idTypeDef::GetFunction(this: v12, funcNumber: v18);
    idTypeDef::AddFunction(this: v16, func: Function);
  }
  if ( idStr::Cmp(s1: this->token.data, s2: "{") != 0 )
  {
    LODWORD(v22) = this->token.data;
    HIDWORD(v22) = "{";
    idCompiler::Error(
      this,
      message: "expected '%s', found '%s'",
      a3: v22,
      a4: v21,
      a5: v20,
      a6: v52,
      a7: v53,
      a8: v54,
      a9: v55,
      a10: v56,
      a11: v57);
  }
  idCompiler::NextToken(this);
  do
  {
    if ( idStr::Cmp(s1: this->token.data, s2: ";") != 0 )
    {
      v23 = 0;
    }
    else
    {
      idCompiler::NextToken(this);
      v23 = 1;
    }
    if ( v23 == 0 )
    {
      if ( idStr::Cmp(s1: this->token.data, s2: "__noedit") != 0 )
      {
        v24 = 0;
      }
      else
      {
        idCompiler::NextToken(this);
        v24 = 1;
      }
      v25 = (_cntlzw(v24) & 0x20) != 0;
      v26 = idCompiler::ParseType(this);
      idTypeDef::SetFieldType(this: &v62, fieldtype: v26);
      HIDWORD(v27) = idFile_MTP::GetName(pObstacle: (bfx::ObstacleImpl *)v26);
      v30 = va::va(
              this: &v63,
              fmt: "%s field",
              a3: v27,
              a4: v29,
              a5: v28,
              a6: v52,
              a7: v53,
              a8: v54,
              a9: v55,
              a10: v56,
              a11: v57);
      idTypeDef::SetName(this: &v62, newname: v30->buffer);
      HIDWORD(v33) = this->token.type;
      if ( HIDWORD(v33) != 4 )
      {
        HIDWORD(v32) = this->token.data;
        idCompiler::Error(
          this,
          message: "'%s' is not a name",
          a3: v32,
          a4: v31,
          a5: v33,
          a6: v52,
          a7: v53,
          a8: v54,
          a9: v55,
          a10: v56,
          a11: v57);
      }
      len = this->token.len;
      idStr::EnsureAlloced(this: &v60, amount: len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v60.data, Src: this->token.data, Size: len);
      v60.data[len] = 0;
      v60.len = len;
      idCompiler::NextToken(this);
      if ( idStr::Cmp(s1: this->token.data, s2: "(") != 0 )
      {
        v35 = 0;
      }
      else
      {
        idCompiler::NextToken(this);
        v35 = 1;
      }
      if ( v35 != 0 )
      {
        data = v60.data;
        v37 = idTypeDef::FieldType(this: &v62);
        idCompiler::ParseFunctionDef(this, returnType: v37, name: data);
      }
      else
      {
        Type = idProgram::GetType(this: &gameLocal->program, type: &v62, allocate: true);
        v39 = 1;
        if ( idStr::Cmp(s1: this->token.data, s2: "[") != 0 )
        {
          v40 = 0;
        }
        else
        {
          idCompiler::NextToken(this);
          v40 = 1;
        }
        if ( v40 != 0 )
        {
          Immediate = idCompiler::FindImmediate(
                        this,
                        type: (bfx::Planner3D *)this->immediateType,
                        eval: &this->immediate,
                        string: this->token.data);
          idCompiler::NextToken(this);
          v58 = Immediate->typeDef;
          if ( v58 == &type_integer )
          {
            v39 = *Immediate->value.value.ip;
          }
          else
          {
            if ( v58 != &type_float )
            {
              HIDWORD(v44) = v60.data;
              idCompiler::Error(
                this,
                message: "Wrong type for array size of '%s'",
                a3: v44,
                a4: v43,
                a5: v42,
                a6: v52,
                a7: v53,
                a8: v54,
                a9: v55,
                a10: v56,
                a11: v57);
            }
            v39 = (int)*Immediate->value.value.fp;
          }
          if ( idStr::Cmp(s1: this->token.data, s2: "]") != 0 )
          {
            LODWORD(v50) = this->token.data;
            HIDWORD(v50) = "]";
            idCompiler::Error(
              this,
              message: "expected '%s', found '%s'",
              a3: v50,
              a4: v46,
              a5: v45,
              a6: v52,
              a7: v53,
              a8: v54,
              a9: v55,
              a10: v56,
              a11: v57);
          }
          idCompiler::NextToken(this);
        }
        if ( idStr::Cmp(s1: this->token.data, s2: ";") != 0 )
        {
          LODWORD(v51) = this->token.data;
          HIDWORD(v51) = ";";
          idCompiler::Error(
            this,
            message: "expected '%s', found '%s'",
            a3: v51,
            a4: v48,
            a5: v47,
            a6: v52,
            a7: v53,
            a8: v54,
            a9: v55,
            a10: v56,
            a11: v57);
        }
        idCompiler::NextToken(this);
        idCompiler::ReadComment(this, comment: &v61);
        idProgram::AllocDef(
          this: &gameLocal->program,
          type: Type,
          name: v60.data,
          scope: this->scope,
          size: v39,
          constant: true,
          isTypeDeclaration: false);
        idTypeDef::AddField(this: v16, fieldtype: Type, name: v60.data, editable: v25, comment: v61.data);
      }
    }
    if ( idStr::Cmp(s1: this->token.data, s2: "}") != 0 )
    {
      v49 = 0;
    }
    else
    {
      idCompiler::NextToken(this);
      v49 = 1;
    }
  }
  while ( v49 == 0 );
  this->scope = scope;
  idCompiler::ExpectToken(this, string: ";");
  idTypeDef::~idTypeDef(this: &v62);
  idStr::FreeData(this: &v61);
  idStr::FreeData(this: &v60);
}


// ========================================================================
// $LN187
// EA  : 0x82E9223C
// RVA : 0x00E9223C
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _LN187()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4576 + 128));
}


// ========================================================================
// __unwind$496915
// EA  : 0x82E92264
// RVA : 0x00E92264
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_496915()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4576 + 160));
}


// ========================================================================
// __unwind$496916
// EA  : 0x82E9228C
// RVA : 0x00E9228C
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_496916()
{
  int v0; // r12

  idTypeDef::~idTypeDef(this: (idTypeDef *)(v0 - 4576 + 192));
}


// ========================================================================
// ?ParseDefs@idCompiler@@AAAXXZ
// EA  : 0x82E922C0
// RVA : 0x00E922C0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ParseDefs(idCompiler *this)
{
  char v1; // r29
  idTypeDef *v3; // r29
  __int64 v4; // r8
  __int64 v5; // r6
  __int64 v6; // r10
  idTypeDef *v7; // r29
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  idVarDef *Def; // r3
  idVarDef *v12; // r28
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  idVarDef *scope; // r27
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  int v20; // [sp+8h] [-B8h]
  int v21; // [sp+Ch] [-B4h]
  int v22; // [sp+10h] [-B0h]
  int v23; // [sp+14h] [-ACh]
  int v24; // [sp+18h] [-A8h]
  int v25; // [sp+1Ch] [-A4h]
  idStr v26[2]; // [sp+70h] [-50h] BYREF

  v1 = 0;
  v26[0].len = 0;
  v26[0].allocedAndFlag = 20;
  v26[0].data = v26[0].baseBuffer;
  v26[0].baseBuffer[0] = 0;
  if ( idStr::Cmp(s1: this->token.data, s2: ";") == 0 )
  {
    idCompiler::NextToken(this);
    v1 = 1;
  }
  if ( v1 == 0 )
  {
    v3 = idCompiler::ParseType(this);
    LODWORD(v6) = &type_scriptevent;
    if ( v3 == &type_scriptevent )
    {
      v7 = idCompiler::ParseType(this);
      idCompiler::ParseName(this, name: v26, a3: v10, a4: v9, a5: v8);
      idCompiler::ParseEventDef(this, returnType: v7, name: v26[0].data);
    }
    else
    {
      idCompiler::ParseName(this, name: v26, a3: v5, a4: v4, a5: v6);
      if ( v3 == &type_namespace )
      {
        Def = idProgram::GetDef(this: &gameLocal->program, type: v3, name: v26[0].data, scope: this->scope);
        if ( Def == nullptr )
          Def = idProgram::AllocDef(
                  this: &gameLocal->program,
                  type: v3,
                  name: v26[0].data,
                  scope: this->scope,
                  size: 1,
                  constant: true,
                  isTypeDeclaration: false);
        idCompiler::ParseNamespace(this, newScope: Def);
      }
      else if ( (unsigned __int8)idCompiler::CheckToken(this, string: "::") != 0 )
      {
        v12 = idProgram::GetDef(this: &gameLocal->program, type: nullptr, name: v26[0].data, scope: this->scope);
        if ( v12 == nullptr )
        {
          HIDWORD(v15) = v26[0].data;
          idCompiler::Error(
            this,
            message: "Unknown object name '%s'",
            a3: v15,
            a4: v14,
            a5: v13,
            a6: v20,
            a7: v21,
            a8: v22,
            a9: v23,
            a10: v24,
            a11: v25);
        }
        idCompiler::ParseName(this, name: v26, a3: v15, a4: v14, a5: v13);
        scope = this->scope;
        this->scope = v12;
        idCompiler::ExpectToken(this, string: "(");
        idCompiler::ParseFunctionDef(this, returnType: v3, name: v26[0].data);
        this->scope = scope;
      }
      else if ( v3 == &type_object )
      {
        idCompiler::ParseObjectDef(this, objname: v26[0].data);
      }
      else if ( (unsigned __int8)idCompiler::CheckToken(this, string: "(") != 0 )
      {
        idCompiler::ParseFunctionDef(this, returnType: v3, name: v26[0].data);
      }
      else
      {
        idCompiler::ParseVariableDef(this, type: v3, name: v26[0].data);
        while ( (unsigned __int8)idCompiler::CheckToken(this, string: ",") != 0 )
        {
          idCompiler::ParseName(this, name: v26, a3: v19, a4: v18, a5: v17);
          idCompiler::ParseVariableDef(this, type: v3, name: v26[0].data);
        }
        idCompiler::ExpectToken(this, string: ";");
      }
    }
  }
  idStr::FreeData(this: v26);
}


// ========================================================================
// $LN82_0
// EA  : 0x82E92540
// RVA : 0x00E92540
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _LN82_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// ?ParseNamespace@idCompiler@@AAAXPAVidVarDef@@@Z
// EA  : 0x82E92568
// RVA : 0x00E92568
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::ParseNamespace(idCompiler *this, idVarDef *newScope)
{
  idVarDef *scope; // r26
  char v5; // r11

  scope = this->scope;
  if ( newScope != &def_namespace )
    idCompiler::ExpectToken(this, string: "{");
  while ( !this->eof )
  {
    this->scope = newScope;
    this->callthread = false;
    if ( newScope != &def_namespace )
    {
      if ( idStr::Cmp(s1: this->token.data, s2: "}") != 0 )
      {
        v5 = 0;
      }
      else
      {
        idCompiler::NextToken(this);
        v5 = 1;
      }
      if ( v5 != 0 )
        break;
    }
    idCompiler::ParseDefs(this);
  }
  this->scope = scope;
}


// ========================================================================
// ?CompileFile@idCompiler@@QAAXPBD0H@Z
// EA  : 0x82E92620
// RVA : 0x00E92620
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __fastcall idCompiler::CompileFile(idCompiler *this, const char *text, const char *filename, int flags)
{
  __int64 v4; // r29
  __int64 v9; // r3
  int v10; // r4
  int v11; // r5
  int len; // r10
  int v13; // r8
  int v14; // r5
  int v15; // r11
  double clockTicks; // fp31
  __int64 v17; // r3
  idTimer v18; // [sp+80h] [-A0h] BYREF

  LODWORD(v4) = 0;
  v18.clockTicks = v4;
  v18.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  v18.state = TS_STARTED;
  LODWORD(v9) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  this->compileFlags = flags;
  this->basetype = nullptr;
  this->callthread = false;
  v10 = 0x2000;
  this->scope = &def_namespace;
  this->loopDepth = 0;
  this->eof = false;
  this->braceDepth = 0;
  this->immediateType = nullptr;
  this->currentLineNumber = 0;
  this->immediate._int = 0;
  this->immediate.vector[1] = 0.0;
  this->immediate.vector[2] = 0.0;
  this->immediate.quat[3] = 0.0;
  v18.start = v9;
  if ( (flags & 1) != 0 )
    v10 = 8196;
  idParser::SetFlags(this: &this->parser, flags: v10);
  v11 = 0;
  if ( *text != 0 )
  {
    do
      ++v11;
    while ( text[v11] != 0 );
  }
  idParser::LoadMemory(this: &this->parser, ptr: text, length: v11, name: filename);
  this->parserPtr = &this->parser;
  idStr::operator=(this: &this->token, text: "/script/script_events.script");
  len = this->token.len;
  this->token.linesCrossed = 0;
  this->token.line = 0;
  this->token.type = 1;
  this->token.subtype = len;
  idParser::UnreadToken(this: &this->parser, token: &this->token);
  idStr::operator=(this: &this->token, text: "include");
  v13 = this->token.len;
  this->token.linesCrossed = 0;
  this->token.line = 0;
  this->token.type = 4;
  this->token.subtype = v13;
  idParser::UnreadToken(this: &this->parser, token: &this->token);
  idStr::operator=(this: &this->token, text: "#");
  this->token.linesCrossed = 0;
  this->token.type = 5;
  this->token.subtype = 51;
  this->token.line = 0;
  idParser::UnreadToken(this: &this->parser, token: &this->token);
  idStr::operator=(this: &this->token, text: "/script/script_defs.script");
  v14 = this->token.len;
  this->token.type = 1;
  this->token.linesCrossed = 0;
  this->token.line = 0;
  this->token.subtype = v14;
  idParser::UnreadToken(this: &this->parser, token: &this->token);
  idStr::operator=(this: &this->token, text: "include");
  v15 = this->token.len;
  this->token.type = 4;
  this->token.linesCrossed = 0;
  this->token.line = 0;
  this->token.subtype = v15;
  idParser::UnreadToken(this: &this->parser, token: &this->token);
  idStr::operator=(this: &this->token, text: "#");
  this->token.type = 5;
  this->token.subtype = 51;
  this->token.linesCrossed = 0;
  this->token.line = 0;
  idParser::UnreadToken(this: &this->parser, token: &this->token);
  this->token.line = 1;
  idCompiler::NextToken(this);
  while ( !this->eof )
    idCompiler::ParseNamespace(this, newScope: &def_namespace);
  idParser::FreeSource(this: &this->parser);
  idTimer::Stop(this: &v18);
  if ( (this->compileFlags & 4) == 0 )
  {
    clockTicks = (float)v18.clockTicks;
    LODWORD(v17) = Sys_ClockTicksPerSecond();
    idLib::Printf(
      fmt: "Compiled '%s': %.1f ms\n",
      (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)clockTicks
                                                                      / (float)((float)v17 * (float)0.001)))),
      (float)((float)clockTicks / (float)((float)v17 * (float)0.001)));
  }
}


// ========================================================================
// $M497598
// EA  : 0x82E928E0
// RVA : 0x00E928E0
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void __noreturn _M497598()
{
  int v0; // r12
  idStr *v1; // r31
  idParser *v2; // r29

  v1 = (idStr *)(v0 - 288);
  v1[3].len = 0;
  v1[3].allocedAndFlag = 20;
  v1[3].data = (char *)(v0 - 288 + 108);
  v1[3].baseBuffer[0] = 0;
  v2 = *(idParser **)(v0 - 288 + 308);
  if ( ((int)v2[1].definehash[2] & 8) != 0 )
    idStr::Format(this: v1 + 3, fmt: "Error: %s\n", idException::error);
  else
    idStr::Format(
      this: v1 + 3,
      fmt: "Error: file %s, line %d: %s\n",
      gameLocal->program.fileList.list[(int)v2[1].definehash[7]].fileName.data,
      v2[1].definehash[6],
      idException::error);
  idParser::FreeSource(this: v2);
  strncpy(dest: idException::error, source: v1[3].data, count: 0x800u);
  v1[2].baseBuffer[4] = v1[2].baseBuffer[5];
  CxxThrowException(pExceptionObject: &v1[2].baseBuffer[4], pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidCompileError__);
}


// ========================================================================
// $LN99_1
// EA  : 0x82E929BC
// RVA : 0x00E929BC
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _LN99_1()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$497453
// EA  : 0x82E929E4
// RVA : 0x00E929E4
// PDB : w:\tech5\tungsten\game\script\compiler.cpp
// ========================================================================

void _unwind_497453()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 96));
}

