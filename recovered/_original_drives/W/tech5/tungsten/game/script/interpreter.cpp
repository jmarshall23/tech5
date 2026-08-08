
// ========================================================================
// ?SetThread@idInterpreter@@QAAXPAVidThread@@@Z
// EA  : 0x82E92A10
// RVA : 0x00E92A10
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void __fastcall idInterpreter::SetThread(idInterpreter *this, idThread *pThread)
{
  this->thread = pThread;
}


// ========================================================================
// ?MultiFrameEventInProgress@idInterpreter@@QBA_NXZ
// EA  : 0x82E92A18
// RVA : 0x00E92A18
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

BOOL __fastcall idInterpreter::MultiFrameEventInProgress(idInterpreter *this)
{
  return this->multiFrameEvent != nullptr;
}


// ========================================================================
// ?Reset@idInterpreter@@QAAXXZ
// EA  : 0x82E92B18
// RVA : 0x00E92B18
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void __fastcall idInterpreter::Reset(idInterpreter *this)
{
  this->localstack.callStackDepth = 0;
  this->localstack.stackUsed = 0;
  this->localstack.stackBase = 0;
  this->localstack.maxStackUsed = 0;
  this->localstack.maxCallStackDepth = 0;
  this->popParms = 0;
  this->multiFrameEvent = nullptr;
  this->eventEntity = nullptr;
  this->localstack.currentFunction = nullptr;
  this->localstack.instructionPointer = -1;
  this->threadDying = false;
  this->doneProcessing = true;
}


// ========================================================================
// ?SafeReturn@idInterpreter@@IAAXH@Z
// EA  : 0x82E92B58
// RVA : 0x00E92B58
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void __fastcall idInterpreter::SafeReturn(idInterpreter *this, int returnType)
{
  if ( returnType > 105 )
  {
    switch ( returnType )
    {
      case 'l':
        idProgram::ReturnList(this: &gameLocal->program, list: nullptr);
        return;
      case 's':
        goto LABEL_16;
      case 'v':
        *gameLocal->program.returnDef->value.value.vp = vec3_origin;
        break;
      default:
        break;
    }
  }
  else
  {
    if ( returnType == 105 )
      goto LABEL_11;
    if ( returnType <= 101 )
    {
      if ( returnType == 101 )
      {
        idProgram::ReturnEntity(this: &gameLocal->program, ent: nullptr);
        return;
      }
      if ( returnType != 49 )
      {
        if ( returnType != 98 )
          return;
LABEL_11:
        *gameLocal->program.returnDef->value.value.ip = 0;
        return;
      }
LABEL_16:
      idStr::Copynz(dest: gameLocal->program.returnStringDef->value.value.cp, src: &byte_8200D768, destsize: 256);
      return;
    }
    if ( returnType == 102 )
      *gameLocal->program.returnDef->value.value.fp = 0.0;
  }
}


// ========================================================================
// ??0idInterpreter@@QAA@XZ
// EA  : 0x82E92C88
// RVA : 0x00E92C88
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

idInterpreter *__fastcall idInterpreter::idInterpreter(idInterpreter *this)
{
  idScriptStack *p_localstack; // r29

  p_localstack = &this->localstack;
  this->debug = false;
  this->terminateOnExit = true;
  this->localstack.currentFunction = nullptr;
  this->localstack.instructionPointer = 0;
  this->localstack.callStackDepth = 0;
  this->localstack.maxCallStackDepth = 0;
  this->localstack.stackBase = 0;
  this->localstack.stackUsed = 0;
  this->localstack.maxStackUsed = 0;
  memset(Dst: this->localstack.callStack, Val: 0, Size: sizeof(this->localstack.callStack));
  memset(Dst: p_localstack->stack, Val: 0, Size: sizeof(p_localstack->stack));
  this->localstack.callStackDepth = 0;
  this->localstack.stackUsed = 0;
  this->localstack.stackBase = 0;
  this->localstack.maxStackUsed = 0;
  this->localstack.maxCallStackDepth = 0;
  this->popParms = 0;
  this->multiFrameEvent = nullptr;
  this->eventEntity = nullptr;
  this->localstack.currentFunction = nullptr;
  this->localstack.instructionPointer = -1;
  this->threadDying = false;
  this->doneProcessing = true;
  return this;
}


// ========================================================================
// ?CurrentLine@idInterpreter@@QBAHXZ
// EA  : 0x82E92D28
// RVA : 0x00E92D28
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

int __fastcall idInterpreter::CurrentLine(idInterpreter *this)
{
  int instructionPointer; // r11

  instructionPointer = this->localstack.instructionPointer;
  if ( instructionPointer >= 0 )
    return gameLocal->program.statements.list[instructionPointer].linenumber;
  else
    return 0;
}


// ========================================================================
// ?CurrentFile@idInterpreter@@QBAPBDXZ
// EA  : 0x82E92D60
// RVA : 0x00E92D60
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

char *__fastcall idInterpreter::CurrentFile(idInterpreter *this)
{
  int instructionPointer; // r11
  int file; // r11

  instructionPointer = this->localstack.instructionPointer;
  if ( instructionPointer < 0 )
    return &byte_8200D768;
  file = gameLocal->program.statements.list[instructionPointer].file;
  return *(&gameLocal->program.fileList.list->fileName.data + file + __ROL4__(file, 3));
}


// ========================================================================
// ?StackTrace@idInterpreter@@QBAXXZ
// EA  : 0x82E92DC0
// RVA : 0x00E92DC0
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void __fastcall idInterpreter::StackTrace(idInterpreter *this)
{
  int callStackDepth; // r11
  int v3; // r27
  idDecl *currentFunction; // r3
  char *data; // r25
  const char *v6; // r3
  const function_t **p_function; // r30
  idDecl *v8; // r3
  char *v9; // r25
  const char *v10; // r3

  callStackDepth = this->localstack.callStackDepth;
  if ( callStackDepth != 0 )
  {
    v3 = this->localstack.callStackDepth;
    if ( callStackDepth >= 64 )
      v3 = 63;
    if ( this->localstack.currentFunction != nullptr )
    {
      currentFunction = (idDecl *)this->localstack.currentFunction;
      data = gameLocal->program.fileList.list[currentFunction->staleCount].fileName.data;
      v6 = (const char *)function_t::Name(this: currentFunction);
      idLib::Printf(fmt: "%12s : %s\n", data, v6);
    }
    else
    {
      idLib::Printf(fmt: "<NO FUNCTION>\n");
    }
    if ( v3 >= 0 )
    {
      p_function = &this->localstack.callStack[v3].function;
      do
      {
        v8 = (idDecl *)*p_function;
        if ( *p_function != nullptr )
        {
          v9 = gameLocal->program.fileList.list[v8->staleCount].fileName.data;
          v10 = (const char *)function_t::Name(this: v8);
          idLib::Printf(fmt: "%12s : %s\n", v9, v10);
        }
        else
        {
          idLib::Printf(fmt: "<NO FUNCTION>\n");
        }
        --v3;
        p_function -= 3;
      }
      while ( v3 >= 0 );
    }
  }
  else
  {
    idLib::Printf(fmt: "<NO STACK>\n");
  }
}


// ========================================================================
// ?Error@idInterpreter@@QBAXPBDZZ
// EA  : 0x82E92EE8
// RVA : 0x00E92EE8
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idInterpreter::Error(
        idInterpreter *this,
        const char *fmt,
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
  int instructionPointer; // r11
  char v13[1024]; // [sp+60h] [-410h] BYREF
  __int64 v14; // [sp+490h] [+20h] BYREF
  va_list va; // [sp+490h] [+20h]
  __int64 v16; // [sp+498h] [+28h]
  __int64 v17; // [sp+4A0h] [+30h]
  __int64 v18; // [sp+4A8h] [+38h]
  __int64 v19; // [sp+4B0h] [+40h]
  __int64 v20; // [sp+4B8h] [+48h]
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
  v14 = *(__int64 *)((char *)&a3 + 4);
  v16 = a3;
  v17 = *(__int64 *)((char *)&a4 + 4);
  v18 = a4;
  v19 = *(__int64 *)((char *)&a5 + 4);
  v20 = a5;
  idStr::vsnPrintf(dest: v13, size: 1024, fmt, argptr: va);
  idInterpreter::StackTrace(this);
  instructionPointer = this->localstack.instructionPointer;
  if ( instructionPointer >= 0 && instructionPointer < gameLocal->program.statements.num )
    idLib::Error(
      fmt: "%s(%d): Thread '%s': %s\n",
      *((const char **)&gameLocal->program.fileList.list->fileName.data
      + gameLocal->program.statements.list[instructionPointer].file
      + __ROL4__(gameLocal->program.statements.list[instructionPointer].file, 3)),
      gameLocal->program.statements.list[instructionPointer].linenumber,
      this->thread->threadName.data,
      v13);
  idLib::Error(fmt: "Thread '%s': %s\n", this->thread->threadName.data, v13);
  JUMPOUT(0x82E92FD4);
}


// ========================================================================
// ?Warning@idInterpreter@@QBAXPBDZZ
// EA  : 0x82E92FD8
// RVA : 0x00E92FD8
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idInterpreter::Warning(
        idInterpreter *this,
        const char *fmt,
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
  int instructionPointer; // r11
  char v13[1024]; // [sp+60h] [-410h] BYREF
  __int64 v14; // [sp+490h] [+20h] BYREF
  va_list va; // [sp+490h] [+20h]
  __int64 v16; // [sp+498h] [+28h]
  __int64 v17; // [sp+4A0h] [+30h]
  __int64 v18; // [sp+4A8h] [+38h]
  __int64 v19; // [sp+4B0h] [+40h]
  __int64 v20; // [sp+4B8h] [+48h]
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
  v14 = *(__int64 *)((char *)&a3 + 4);
  v16 = a3;
  v17 = *(__int64 *)((char *)&a4 + 4);
  v18 = a4;
  v19 = *(__int64 *)((char *)&a5 + 4);
  v20 = a5;
  idStr::vsnPrintf(dest: v13, size: 1024, fmt, argptr: va);
  instructionPointer = this->localstack.instructionPointer;
  if ( instructionPointer < 0 || instructionPointer >= gameLocal->program.statements.num )
    idLib::Warning(fmt: "Thread '%s' : %s", this->thread->threadName.data, v13);
  else
    idLib::Warning(
      fmt: "%s(%d): Thread '%s': %s",
      *((const char **)&gameLocal->program.fileList.list->fileName.data
      + gameLocal->program.statements.list[instructionPointer].file
      + __ROL4__(gameLocal->program.statements.list[instructionPointer].file, 3)),
      gameLocal->program.statements.list[instructionPointer].linenumber,
      this->thread->threadName.data,
      v13);
}


// ========================================================================
// ?EnterFunction@idInterpreter@@QAAXPBVfunction_t@@_N@Z
// EA  : 0x82E93478
// RVA : 0x00E93478
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void __fastcall idInterpreter::EnterFunction(
        idInterpreter *this,
        idDecl *func,
        __int64 clearStack,
        __int64 a4,
        __int64 a5)
{
  int v7; // r11
  int callStackDepth; // r11
  prstack_s *v9; // r11
  __int64 v10; // r10
  int v11; // r11
  const char *v12; // r29
  statement_t *v13; // r30
  int GameMs; // r27
  int linenumber; // r30
  const char *v16; // r26
  const char *v17; // r3
  const char *v18; // r30
  int v19; // r29
  const char *v20; // r3
  __int64 v21; // r10
  size_t v22; // r30
  int stackUsed; // r11
  int maxStackUsed; // r8
  int v25; // r11
  int v26; // [sp+8h] [-98h]
  int v27; // [sp+Ch] [-94h]
  int v28; // [sp+10h] [-90h]
  int v29; // [sp+14h] [-8Ch]
  int v30; // [sp+18h] [-88h]
  int v31; // [sp+1Ch] [-84h]

  LODWORD(a4) = BYTE3(clearStack);
  v7 = 0;
  if ( BYTE3(clearStack) != 0 )
  {
    this->localstack.callStackDepth = 0;
    HIDWORD(a5) = 1;
    this->localstack.stackUsed = 0;
    this->localstack.stackBase = 0;
    this->localstack.maxStackUsed = 0;
    this->localstack.maxCallStackDepth = 0;
    this->popParms = 0;
    this->multiFrameEvent = nullptr;
    this->eventEntity = nullptr;
    this->localstack.currentFunction = nullptr;
    this->localstack.instructionPointer = -1;
    this->threadDying = false;
    this->doneProcessing = true;
  }
  LODWORD(a5) = this->popParms;
  if ( (_DWORD)a5 != 0 )
  {
    HIDWORD(a5) = this->localstack.stackUsed;
    if ( SHIDWORD(a5) < (int)a5 )
      idInterpreter::Error(
        this,
        fmt: "locals stack underflow\n",
        a3: clearStack,
        a4,
        a5,
        a6: v26,
        a7: v27,
        a8: v28,
        a9: v29,
        a10: v30,
        a11: v31);
    LODWORD(a5) = HIDWORD(a5) - a5;
    this->popParms = v7;
    this->localstack.stackUsed = a5;
  }
  callStackDepth = this->localstack.callStackDepth;
  if ( callStackDepth >= 64 )
    idInterpreter::Error(
      this,
      fmt: "call stack overflow",
      a3: clearStack,
      a4,
      a5,
      a6: v26,
      a7: v27,
      a8: v28,
      a9: v29,
      a10: v30,
      a11: v31);
  LODWORD(v10) = this->localstack.instructionPointer + 1;
  v9 = &this->localstack.callStack[callStackDepth];
  v9->nextInstruction = v10;
  HIDWORD(v10) = this->localstack.currentFunction;
  v9->function = (const function_t *)HIDWORD(v10);
  HIDWORD(a4) = this->localstack.stackBase;
  v9->stackBase = HIDWORD(a4);
  LODWORD(clearStack) = this->localstack.maxCallStackDepth;
  v11 = this->localstack.callStackDepth + 1;
  this->localstack.callStackDepth = v11;
  if ( v11 > (int)clearStack )
    this->localstack.maxCallStackDepth = v11;
  if ( func == nullptr )
    idInterpreter::Error(
      this,
      fmt: "NULL function",
      a3: clearStack,
      a4,
      a5: v10,
      a6: v26,
      a7: v27,
      a8: v28,
      a9: v29,
      a10: v30,
      a11: v31);
  if ( this->debug )
  {
    if ( this->localstack.currentFunction != nullptr )
    {
      if ( (_DWORD)a4 != 0 )
        v12 = " clear stack";
      else
        v12 = &byte_8200D768;
      v13 = &gameLocal->program.statements.list[this->localstack.instructionPointer];
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      linenumber = v13->linenumber;
      v16 = (const char *)function_t::Name(this: (idDecl *)this->localstack.currentFunction);
      v17 = (const char *)function_t::Name(this: func);
      idLib::Printf(fmt: "%d: call '%s' from '%s'(line %d)%s\n", GameMs, v17, v16, linenumber, v12);
    }
    else
    {
      if ( (_DWORD)a4 != 0 )
        v18 = " clear stack";
      else
        v18 = &byte_8200D768;
      v19 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v20 = (const char *)function_t::Name(this: func);
      idLib::Printf(fmt: "%d: call '%s'%s\n", v19, v20, v18);
    }
  }
  this->localstack.currentFunction = (const function_t *)func;
  this->localstack.instructionPointer = (int)&func->nextOnHashChain[-1] + 35;
  v21 = *(_QWORD *)&func->resourceError;
  v22 = v21 - HIDWORD(v21);
  stackUsed = this->localstack.stackUsed;
  LODWORD(a4) = stackUsed + v21 - HIDWORD(v21);
  if ( (int)a4 > 6144 )
    idInterpreter::Error(
      this,
      fmt: "EnterFuncton: locals stack overflow\n",
      a3: clearStack,
      a4,
      a5: v21,
      a6: v26,
      a7: v27,
      a8: v28,
      a9: v29,
      a10: v30,
      a11: v31);
  memset(Dst: &this->localstack.stack[stackUsed], Val: 0, Size: v22);
  maxStackUsed = this->localstack.maxStackUsed;
  v25 = v22 + this->localstack.stackUsed;
  this->localstack.stackUsed = v25;
  this->localstack.stackBase = v25 - func->networkID;
  if ( v25 > maxStackUsed )
    this->localstack.maxStackUsed = v25;
}


// ========================================================================
// ?LeaveFunction@idInterpreter@@IAAXPAVidVarDef@@@Z
// EA  : 0x82E93710
// RVA : 0x00E93710
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void __fastcall idInterpreter::LeaveFunction(
        idInterpreter *this,
        idVarDef *returnDef,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  idTypeDef *v7; // r3
  bfx::Space *v8; // r3
  varEval_t *Variable; // r3
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  varEval_t *v13; // r3
  const char *v14; // r4
  char *cp; // r3
  bfx::Planner3D *v16; // r3
  bfx::Space *TypeDef; // r3
  int stackUsed; // r11
  statement_t *v19; // r29
  const char *v20; // r26
  int GameMs; // r25
  const char *v22; // r3
  int callStackDepth; // r11
  idDecl **v24; // r11
  int linenumber; // r30
  const char *v26; // r3
  int v27; // r11
  bool v28; // cr34
  prstack_s *v29; // r11
  int v30; // [sp+8h] [-A8h]
  int v31; // [sp+Ch] [-A4h]
  int v32; // [sp+10h] [-A0h]
  int v33; // [sp+14h] [-9Ch]
  int v34; // [sp+18h] [-98h]
  int v35; // [sp+1Ch] [-94h]
  varEval_t v36; // [sp+60h] [-50h] BYREF
  varEval_t v37; // [sp+64h] [-4Ch] BYREF

  if ( this->localstack.callStackDepth <= 0 )
    idInterpreter::Error(
      this,
      fmt: "prog stack underflow",
      a3,
      a4,
      a5,
      a6: v30,
      a7: v31,
      a8: v32,
      a9: v33,
      a10: v34,
      a11: v35);
  if ( returnDef == nullptr )
  {
    v16 = (bfx::Planner3D *)idTypeDef::ReturnType(this: (idTypeDef *)this->localstack.currentFunction->type);
    TypeDef = idScriptObject::GetTypeDef(this: v16);
    if ( TypeDef == nullptr )
      goto LABEL_21;
    if ( TypeDef != (bfx::Space *)3 )
    {
      if ( TypeDef == (bfx::Space *)6 )
      {
        LODWORD(v11) = 154024;
        HIDWORD(v10) = allocationCurrent[242];
        HIDWORD(v11) = &vec3_origin;
        LODWORD(v12) = gameLocal->program.returnDef;
        HIDWORD(v12) = *(_DWORD *)(v12 + 4);
        *(idVec3 *)HIDWORD(v12) = vec3_origin;
      }
      else
      {
        HIDWORD(v10) = 154024;
        LODWORD(v11) = gameLocal->program.returnDef;
        HIDWORD(v11) = *(_DWORD *)(v11 + 4);
        *(_DWORD *)HIDWORD(v11) = 0;
      }
      goto LABEL_21;
    }
    v14 = &byte_8200D768;
    cp = gameLocal->program.returnStringDef->value.value.cp;
LABEL_20:
    idStr::Copynz(dest: cp, src: v14, destsize: 256);
    goto LABEL_21;
  }
  v7 = returnDef->typeDef;
  if ( v7 == nullptr )
  {
LABEL_7:
    Variable = idInterpreter::GetVariable(retstr: &v36, this, def: returnDef);
    HIDWORD(v10) = 154024;
    LODWORD(v11) = (varEval_t)Variable->value.cp;
    HIDWORD(v11) = gameLocal->program.returnDef;
    LODWORD(v12) = *Variable->value.ip;
    HIDWORD(v12) = *(_DWORD *)(HIDWORD(v11) + 4);
    *(_DWORD *)HIDWORD(v12) = v12;
    goto LABEL_21;
  }
  v8 = idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v7);
  if ( v8 == (bfx::Space *)3 )
  {
    if ( returnDef->initialized == stackVariable )
      v14 = (const char *)&this->localstack.stack[this->localstack.stackBase + returnDef->value.value.i];
    else
      v14 = returnDef->value.value.cp;
    cp = gameLocal->program.returnStringDef->value.value.cp;
    if ( v14 == nullptr )
      v14 = &byte_8200D768;
    goto LABEL_20;
  }
  if ( v8 != (bfx::Space *)6 )
    goto LABEL_7;
  v13 = idInterpreter::GetVariable(retstr: &v37, this, def: returnDef);
  HIDWORD(v10) = 154024;
  LODWORD(v11) = (varEval_t)v13->value.cp;
  HIDWORD(v11) = gameLocal->program.returnDef;
  LODWORD(v12) = *(_DWORD *)(HIDWORD(v11) + 4);
  *(float *)v12 = *v13->value.fp;
  *(float *)(v12 + 4) = *(float *)(v11 + 4);
  *(float *)(v12 + 8) = *(float *)(v11 + 8);
LABEL_21:
  stackUsed = this->localstack.stackUsed;
  LODWORD(v10) = this->localstack.currentFunction->locals;
  if ( stackUsed < (int)v10 )
    idInterpreter::Error(
      this,
      fmt: "locals stack underflow\n",
      a3: v12,
      a4: v11,
      a5: v10,
      a6: v30,
      a7: v31,
      a8: v32,
      a9: v33,
      a10: v34,
      a11: v35);
  HIDWORD(v10) = this->debug;
  this->localstack.stackUsed = stackUsed - v10;
  if ( HIDWORD(v10) != 0 )
  {
    v19 = &gameLocal->program.statements.list[this->localstack.instructionPointer];
    v20 = *((const char **)&gameLocal->program.fileList.list->fileName.data + v19->file + __ROL4__(v19->file, 3));
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v22 = (const char *)function_t::Name(this: (idDecl *)this->localstack.currentFunction);
    idLib::Printf(fmt: "%d: %s(%d): exit %s", GameMs, v20, v19->linenumber, v22);
    callStackDepth = this->localstack.callStackDepth;
    if ( callStackDepth <= 1 )
    {
      idLib::Printf(fmt: " done\n");
    }
    else
    {
      v24 = (idDecl **)((char *)this + 12 * callStackDepth);
      linenumber = gameLocal->program.statements.list[(_DWORD)*v24].linenumber;
      v26 = (const char *)function_t::Name(this: v24[1]);
      idLib::Printf(fmt: " return to %s(line %d)\n", v26, linenumber);
    }
  }
  v27 = this->localstack.callStackDepth - 1;
  v28 = this->localstack.callStackDepth == 1;
  this->localstack.callStackDepth = v27;
  v29 = &this->localstack.callStack[v27];
  this->localstack.currentFunction = v29->function;
  this->localstack.stackBase = v29->stackBase;
  this->localstack.instructionPointer = v29->nextInstruction - 1;
  if ( v28 )
  {
    this->localstack.currentFunction = nullptr;
    this->doneProcessing = true;
    this->threadDying = true;
  }
}


// ========================================================================
// ?CallEvent@idInterpreter@@IAAXPBVfunction_t@@H@Z
// EA  : 0x82E93A40
// RVA : 0x00E93A40
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void __fastcall idInterpreter::CallEvent(
        idInterpreter *this,
        const function_t *func,
        __int64 argsize,
        __int64 a4,
        __int64 a5)
{
  idInterpreter *v5; // r27
  const char *formatspec; // r29
  const idEventDef *eventdef; // r30
  unsigned __int8 *v8; // r26
  __int64 v9; // r10
  __int64 v10; // r8
  idEntity *v11; // r3
  idEntity *v12; // r3
  const bfx::Vec3 *CachedSize; // r3
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  idAICover *v17; // r28
  unsigned int v18; // r11
  _DWORD *v19; // r10
  int v20; // ctr
  __int16 *v21; // r11
  float *v22; // r9
  __int16 *v23; // r8
  double v24; // fp12
  int v25; // ctr
  const idEntity *v26; // r3
  int *v27; // r10
  __int16 *v28; // r9
  int n; // ctr
  const idIndex<int,enum invalidScriptDecl_t> *v30; // r4
  const idDecl *v31; // r3
  _DWORD *v32; // r10
  __int16 *v33; // r9
  int m; // ctr
  float *v35; // r10
  __int16 *v36; // r9
  int k; // ctr
  char *v38; // r10
  __int16 *v39; // r9
  int v40; // ctr
  float *v41; // r9
  __int16 *v42; // r8
  double v43; // fp12
  int v44; // ctr
  int v45; // r4
  _DWORD *v46; // r10
  __int16 *p_coverIndex; // r9
  int i; // ctr
  _DWORD *v49; // r10
  int v50; // ctr
  __int16 *v51; // r11
  int j; // r27
  idTypeDef *v53; // r3
  idEventReceiver *eventEntity; // r4
  __int64 v55; // r10
  __int64 v56; // r8
  __int64 v57; // r6
  int popParms; // r11
  idEntity *v59; // r11
  __int64 v60; // r6
  __int64 v61; // r10
  __int64 v62; // r8
  __int64 v63; // r6
  int stackUsed; // r11
  int v65; // [sp+8h] [-318h]
  int v66; // [sp+Ch] [-314h]
  int v67; // [sp+10h] [-310h]
  int v68; // [sp+14h] [-30Ch]
  int v69; // [sp+18h] [-308h]
  int v70; // [sp+1Ch] [-304h]
  int v71; // [sp+70h] [-2B0h]
  const idEventDef *v72; // [sp+74h] [-2ACh]
  float v73[8]; // [sp+7Ch] [-2A4h] BYREF
  float v74[9]; // [sp+9Ch] [-284h] BYREF
  idStr v75; // [sp+C0h] [-260h] BYREF
  idStr v76; // [sp+E0h] [-240h] BYREF
  char v77; // [sp+100h] [-220h]
  int v78; // [sp+104h] [-21Ch]
  int v79; // [sp+11Ch] [-204h] BYREF
  idEventArg v80; // [sp+120h] [-200h] BYREF
  _DWORD v81[8]; // [sp+13Ch] [-1E4h] BYREF
  float v82[8]; // [sp+15Ch] [-1C4h] BYREF
  _DWORD v83[8]; // [sp+17Ch] [-1A4h] BYREF
  _DWORD v84[8]; // [sp+19Ch] [-184h] BYREF
  _DWORD v85[9]; // [sp+1BCh] [-164h] BYREF
  idAICover v86; // [sp+1E0h] [-140h] BYREF
  char v87; // [sp+1F4h] [-12Ch]
  int v88; // [sp+1F8h] [-128h]
  char v89; // [sp+208h] [-118h]
  int v90; // [sp+20Ch] [-114h]
  char v91; // [sp+21Ch] [-104h]
  int v92; // [sp+220h] [-100h]
  char v93; // [sp+230h] [-F0h]
  int v94; // [sp+234h] [-ECh]
  char v95; // [sp+244h] [-DCh]
  int v96; // [sp+248h] [-D8h]
  char v97; // [sp+258h] [-C8h]
  int v98; // [sp+25Ch] [-C4h]
  char v99; // [sp+26Ch] [-B4h]
  int v100; // [sp+270h] [-B0h]
  int v103; // [sp+344h] [+24h]

  LODWORD(a5) = v75.baseBuffer;
  v103 = HIDWORD(argsize);
  v5 = this;
  v75.len = 0;
  formatspec = (const char *)HIDWORD(argsize);
  v75.allocedAndFlag = 20;
  v75.data = v75.baseBuffer;
  v75.baseBuffer[0] = 0;
  if ( func == nullptr )
    idInterpreter::Error(
      this,
      fmt: "NULL function in CallEvent",
      a3: argsize,
      a4,
      a5,
      a6: v65,
      a7: v66,
      a8: v67,
      a9: v68,
      a10: v69,
      a11: v70);
  eventdef = func->eventdef;
  v8 = &v5->localstack.stack[v5->localstack.stackUsed - (_DWORD)formatspec];
  v72 = func->eventdef;
  HIDWORD(v9) = *(_DWORD *)v8;
  LODWORD(v10) = *(int *)v8 >> 13;
  HIDWORD(v10) = (*(_DWORD *)v8 & 0x1FFF) + 29755;
  if ( *((_DWORD *)&gameLocal->__vftable + HIDWORD(v10)) == (_DWORD)v10
    && (HIDWORD(v9) = 4 * ((*(_DWORD *)v8 & 0x1FFF) + 21563),
        (v11 = *(idEntity **)((char *)&gameLocal->__vftable + HIDWORD(v9))) != nullptr) )
  {
    v12 = idEntity::CastTo(c: v11);
  }
  else
  {
    v12 = nullptr;
  }
  v5->eventEntity = v12;
  if ( v12 != nullptr && (HIDWORD(v9) = v12->RespondsTo(this: v12, a2: eventdef), HIDWORD(v9) != 0) )
  {
    HIBYTE(v86.aas) = 0;
    v86.spawnId.value = 0;
    v87 = 0;
    v88 = 0;
    v89 = 0;
    v90 = 0;
    v91 = 0;
    v92 = 0;
    v93 = 0;
    v94 = 0;
    v95 = 0;
    v96 = 0;
    v97 = 0;
    v98 = 0;
    v99 = 0;
    v100 = 0;
    formatspec = eventdef->formatspec;
    CachedSize = idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)&type_object);
    LODWORD(v14) = 0x20000;
    v71 = 0;
    HIDWORD(v15) = &pb_ss_UpdateAfterPhysics.name;
    LODWORD(v16) = &pb_ss_UpdateAfterPhysics.name;
    HIDWORD(v16) = &pb_ss_UpdateAfterPhysics.name;
    eventdef = (const idEventDef *)CachedSize;
    v17 = &v86;
    while ( (int)eventdef < v103 || *formatspec != 0 )
    {
      v18 = *(unsigned __int8 *)formatspec;
      if ( v18 > 0x66 )
      {
        switch ( *formatspec )
        {
          case 'i':
            goto LABEL_39;
          case 'l':
            v45 = *(int *)((char *)&eventdef->name + (_DWORD)v8);
            HIBYTE(v85[1]) = 108;
            v85[2] = idGameLocal::GetScriptList(this: gameLocal, idToGet: v45);
            v46 = v85;
            p_coverIndex = &v17[-1].coverIndex;
            for ( i = 5; i != 0; --i )
            {
              ++v46;
              p_coverIndex += 2;
              *(_DWORD *)p_coverIndex = *v46;
            }
            goto _M490941_1;
          case 's':
            goto LABEL_20;
          case 'v':
            v74[2] = *(float *)((char *)&eventdef->name + (_DWORD)v8);
            v41 = v74;
            HIBYTE(v74[1]) = 118;
            v42 = &v17[-1].coverIndex;
            v43 = *(float *)((char *)&eventdef->argTypes + (_DWORD)v8);
            v44 = 5;
            v74[3] = *(float *)((char *)&eventdef->formatspec + (_DWORD)v8);
            v74[4] = v43;
            do
            {
              ++v41;
              v42 += 2;
              *(float *)v42 = *v41;
              --v44;
            }
            while ( v44 != 0 );
            goto _M490941_1;
          case 'x':
            HIBYTE(v83[1]) = 120;
            v83[2] = (char *)eventdef + (_DWORD)v8;
            v49 = v83;
            v50 = 5;
            v51 = &v17[-1].coverIndex;
            do
            {
              ++v49;
              v51 += 2;
              *(_DWORD *)v51 = *v49;
              --v50;
            }
            while ( v50 != 0 );
            eventdef = (const idEventDef *)((char *)eventdef
                                          + (_DWORD)idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)&type_string));
            idStr::idStr(this: &v76, text: (const char *)v17->spawnId.value);
            for ( j = 0; j < v76.len; ++j )
            {
              switch ( v76.data[j] )
              {
                case 'd':
                case 'e':
                  v53 = &type_integer;
                  goto LABEL_57;
                case 'f':
                  v53 = &type_float;
                  goto LABEL_57;
                case 'l':
                  v53 = &type_list;
                  goto LABEL_57;
                case 's':
                  v53 = &type_string;
                  goto LABEL_57;
                case 'v':
                  v53 = &type_vector;
LABEL_57:
                  eventdef = (const idEventDef *)((char *)eventdef
                                                + (_DWORD)idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)v53));
                  break;
                default:
                  continue;
              }
            }
            idStr::FreeData(this: &v76);
            v5 = this;
            goto _M490941_1;
          default:
            goto LABEL_69;
        }
      }
      if ( v18 == 102 )
      {
        v82[2] = *(float *)((char *)&eventdef->name + (_DWORD)v8);
        v35 = v82;
        HIBYTE(v82[1]) = 102;
        v36 = &v17[-1].coverIndex;
        for ( k = 5; k != 0; --k )
        {
          ++v35;
          v36 += 2;
          *(float *)v36 = *v35;
        }
      }
      else if ( v18 > 0x62 )
      {
        if ( v18 == 100 )
        {
          v30 = *(const idIndex<int,enum invalidScriptDecl_t> **)((char *)&eventdef->name + (_DWORD)v8);
          HIBYTE(v84[1]) = 100;
          v31 = idProgram::DeclForId(this: &gameLocal->program, declId: v30);
          v32 = v84;
          v84[2] = v31;
          v33 = &v17[-1].coverIndex;
          for ( m = 5; m != 0; --m )
          {
            ++v32;
            v33 += 2;
            *(_DWORD *)v33 = *v32;
          }
        }
        else
        {
          if ( v18 != 101 )
            goto LABEL_69;
          v26 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)((char *)eventdef + (_DWORD)v8));
          idEventArg::idEventArg(this: &v80, data: v26);
          v27 = &v79;
          v28 = &v17[-1].coverIndex;
          for ( n = 5; n != 0; --n )
          {
            ++v27;
            v28 += 2;
            *(_DWORD *)v28 = *v27;
          }
        }
      }
      else if ( v18 == 98 )
      {
LABEL_39:
        v38 = &v76.baseBuffer[16];
        HIDWORD(v16) = 105;
        v39 = &v17[-1].coverIndex;
        v40 = 5;
        v78 = *(int *)((char *)&eventdef->name + (_DWORD)v8);
        v77 = 105;
        do
        {
          v38 += 4;
          v39 += 2;
          *(_DWORD *)v39 = *(_DWORD *)v38;
          --v40;
        }
        while ( v40 != 0 );
      }
      else if ( v18 > 0x35 )
      {
        if ( v18 != 97 )
          goto LABEL_69;
        v73[2] = *(float *)((char *)&eventdef->name + (_DWORD)v8);
        v22 = v73;
        HIBYTE(v73[1]) = 97;
        v23 = &v17[-1].coverIndex;
        v24 = *(float *)((char *)&eventdef->argTypes + (_DWORD)v8);
        v25 = 5;
        v73[3] = *(float *)((char *)&eventdef->formatspec + (_DWORD)v8);
        v73[4] = v24;
        do
        {
          ++v22;
          v23 += 2;
          *(float *)v23 = *v22;
          --v25;
        }
        while ( v25 != 0 );
      }
      else
      {
        if ( v18 != 53 && (v18 < 0x31 || v18 > 0x32) )
        {
LABEL_69:
          LODWORD(v15) = &off_822E0000;
          HIDWORD(v14) = v72->name;
          idInterpreter::Error(
            this: v5,
            fmt: "Invalid arg format string for '%s' event.",
            a3: v14,
            a4: v16,
            a5: v15,
            a6: v65,
            a7: v66,
            a8: v67,
            a9: v68,
            a10: v69,
            a11: v70);
          goto _LN220;
        }
LABEL_20:
        HIBYTE(v81[1]) = 115;
        v81[2] = (char *)eventdef + (_DWORD)v8;
        v19 = v81;
        v20 = 5;
        v21 = &v17[-1].coverIndex;
        do
        {
          ++v19;
          v21 += 2;
          *(_DWORD *)v21 = *v19;
          --v20;
        }
        while ( v20 != 0 );
        HIBYTE(v17->aas) = *formatspec;
      }
_M490941_1:
      ++formatspec;
      v17 = (idAICover *)((char *)v17 + 20);
      HIDWORD(v15) = v71 + 4;
      LODWORD(v16) = func->parmSize.list;
      eventdef = (const idEventDef *)((char *)eventdef + *(_DWORD *)(v16 + v71));
      v71 += 4;
    }
    eventEntity = v5->eventEntity;
    v5->popParms = v103;
    idEventReceiver::ProcessEventArgPtr(this: (idEventReceiver *)&v80, result: eventEntity, ev: v72, args: &v86);
    if ( v5->multiFrameEvent != nullptr )
    {
      v5->doneProcessing = true;
    }
    else
    {
      popParms = v5->popParms;
      if ( popParms != 0 )
      {
        LODWORD(v55) = v5->localstack.stackUsed;
        if ( (int)v55 < popParms )
          idInterpreter::Error(
            this: v5,
            fmt: "locals stack underflow\n",
            a3: v57,
            a4: v56,
            a5: v55,
            a6: v65,
            a7: v66,
            a8: v67,
            a9: v68,
            a10: v69,
            a11: v70);
        v5->localstack.stackUsed = v55 - popParms;
      }
      v5->eventEntity = nullptr;
    }
    v5->popParms = 0;
  }
  else
  {
_LN220:
    v59 = v5->eventEntity;
    if ( v59 != nullptr )
    {
      LODWORD(v9) = &unk_82360000;
      LODWORD(v60) = v59->name.data;
      HIDWORD(v60) = eventdef->name;
      idInterpreter::Warning(
        this: v5,
        fmt: "Function '%s' not supported on entity '%s'",
        a3: v60,
        a4: v10,
        a5: v9,
        a6: v65,
        a7: v66,
        a8: v67,
        a9: v68,
        a10: v69,
        a11: v70);
    }
    idInterpreter::SafeReturn(this: v5, returnType: (char)eventdef->returnType);
    stackUsed = v5->localstack.stackUsed;
    if ( stackUsed < (int)formatspec )
      idInterpreter::Error(
        this: v5,
        fmt: "locals stack underflow\n",
        a3: v63,
        a4: v62,
        a5: v61,
        a6: v65,
        a7: v66,
        a8: v67,
        a9: v68,
        a10: v69,
        a11: v70);
    v5->eventEntity = nullptr;
    v5->localstack.stackUsed = stackUsed - (_DWORD)formatspec;
  }
  idStr::FreeData(this: &v75);
}


// ========================================================================
// $LN200
// EA  : 0x82E94078
// RVA : 0x00E94078
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void _LN200()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 800 + 192));
}


// ========================================================================
// __unwind$490644
// EA  : 0x82E940A0
// RVA : 0x00E940A0
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void _unwind_490644()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 800 + 224));
}


// ========================================================================
// ?CallSysEvent@idInterpreter@@IAAXPBVfunction_t@@H@Z
// EA  : 0x82E940D0
// RVA : 0x00E940D0
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void __fastcall idInterpreter::CallSysEvent(
        idInterpreter *this,
        const function_t *func,
        __int64 argsize,
        __int64 a4,
        __int64 a5)
{
  __int64 v6; // r6
  int v7; // r27
  __int64 v8; // r10
  idAICover *v9; // r29
  int v10; // r30
  int v11; // r26
  _BYTE *v12; // r14
  unsigned int v13; // r11
  int v14; // ctr
  _DWORD *v15; // r11
  __int16 *v16; // r10
  float *v17; // r11
  float *v18; // r9
  int v19; // ctr
  __int16 *v20; // r10
  double v21; // fp13
  double v22; // fp12
  const idEntity *v23; // r3
  int *v24; // r10
  __int16 *v25; // r9
  int m; // ctr
  _DWORD *v27; // r10
  __int16 *v28; // r9
  int k; // ctr
  float *v30; // r9
  int v31; // ctr
  __int16 *v32; // r11
  char *v33; // r9
  int v34; // ctr
  __int16 *v35; // r11
  float *v36; // r11
  float *v37; // r9
  int v38; // ctr
  __int16 *v39; // r10
  double v40; // fp13
  double v41; // fp12
  _DWORD *v42; // r10
  __int16 *p_coverIndex; // r9
  int i; // ctr
  int v45; // ctr
  _DWORD *v46; // r11
  __int16 *v47; // r10
  int j; // r26
  idTypeDef *v49; // r3
  int v50; // r11
  __int64 v51; // r10
  __int64 v52; // r8
  __int64 v53; // r6
  int popParms; // r11
  int v55; // r10
  int v56; // r9
  int v57; // r8
  int v58; // r7
  int v59; // r6
  int v60; // r5
  int v61; // r4
  int v62; // r3
  int v63; // [sp+8h] [-2F8h]
  int v64; // [sp+Ch] [-2F4h]
  int v65; // [sp+10h] [-2F0h]
  int v66; // [sp+14h] [-2ECh]
  int v67; // [sp+18h] [-2E8h]
  int v68; // [sp+1Ch] [-2E4h]
  int v69; // [sp+70h] [-290h]
  int v70; // [sp+74h] [-28Ch]
  float v71[8]; // [sp+7Ch] [-284h] BYREF
  float v72[9]; // [sp+9Ch] [-264h] BYREF
  idStr v73; // [sp+C0h] [-240h] BYREF
  char v74; // [sp+E0h] [-220h]
  int v75; // [sp+E4h] [-21Ch]
  _DWORD v76[8]; // [sp+FCh] [-204h] BYREF
  _DWORD v77[8]; // [sp+11Ch] [-1E4h] BYREF
  int v78; // [sp+13Ch] [-1C4h] BYREF
  idEventArg v79; // [sp+140h] [-1C0h] BYREF
  _DWORD v80[8]; // [sp+15Ch] [-1A4h] BYREF
  float v81[8]; // [sp+17Ch] [-184h] BYREF
  _DWORD v82[9]; // [sp+19Ch] [-164h] BYREF
  idAICover v83; // [sp+1C0h] [-140h] BYREF
  char v84; // [sp+1D4h] [-12Ch]
  int v85; // [sp+1D8h] [-128h]
  char v86; // [sp+1E8h] [-118h]
  int v87; // [sp+1ECh] [-114h]
  char v88; // [sp+1FCh] [-104h]
  int v89; // [sp+200h] [-100h]
  char v90; // [sp+210h] [-F0h]
  int v91; // [sp+214h] [-ECh]
  char v92; // [sp+224h] [-DCh]
  int v93; // [sp+228h] [-D8h]
  char v94; // [sp+238h] [-C8h]
  int v95; // [sp+23Ch] [-C4h]
  char v96; // [sp+24Ch] [-B4h]
  int v97; // [sp+250h] [-B0h]
  int v99; // [sp+324h] [+24h]

  HIDWORD(a4) = HIDWORD(argsize);
  v99 = HIDWORD(argsize);
  if ( func == nullptr )
    idInterpreter::Error(
      this,
      fmt: "NULL function in CallSysEvent",
      a3: argsize,
      a4,
      a5,
      a6: v63,
      a7: v64,
      a8: v65,
      a9: v66,
      a10: v67,
      a11: v68);
  HIBYTE(v83.aas) = 0;
  LODWORD(v6) = 0x20000;
  HIDWORD(v6) = func->eventdef;
  LODWORD(v8) = &pb_ss_UpdateAfterPhysics.name;
  v7 = this->localstack.stackUsed - HIDWORD(a4);
  v83.spawnId.value = 0;
  v84 = 0;
  HIDWORD(v8) = &pb_ss_UpdateAfterPhysics.name;
  v85 = 0;
  LODWORD(a4) = &pb_ss_UpdateAfterPhysics.name;
  v86 = 0;
  v87 = 0;
  v9 = &v83;
  v88 = 0;
  v10 = 0;
  v89 = 0;
  v11 = 0;
  v90 = 0;
  v91 = 0;
  v92 = 0;
  v93 = 0;
  v94 = 0;
  v95 = 0;
  v96 = 0;
  v97 = 0;
  v70 = HIDWORD(v6);
  v69 = 0;
  v12 = *(_BYTE **)(HIDWORD(v6) + 4);
  while ( 1 )
  {
    if ( v10 >= SHIDWORD(a4) )
    {
      LODWORD(v8) = (unsigned __int8)*v12;
      if ( *v12 == 0 )
        break;
    }
    v13 = (unsigned __int8)*v12;
    if ( v13 > 0x66 )
    {
      switch ( *v12 )
      {
        case 'i':
          goto LABEL_33;
        case 'l':
          HIBYTE(v80[1]) = 108;
          v80[2] = idGameLocal::GetScriptList(this: gameLocal, idToGet: *(_DWORD *)&this->localstack.stack[v10 + v7]);
          v42 = v80;
          p_coverIndex = &v9[-1].coverIndex;
          for ( i = 5; i != 0; --i )
          {
            ++v42;
            p_coverIndex += 2;
            *(_DWORD *)p_coverIndex = *v42;
          }
          goto _M491153_2;
        case 's':
          goto LABEL_14;
        case 'v':
          v36 = (float *)(&this->doneProcessing + v10 + v7);
          v37 = v72;
          LODWORD(a4) = 118;
          v38 = 5;
          HIBYTE(v72[1]) = 118;
          v39 = &v9[-1].coverIndex;
          v40 = v36[201];
          v41 = v36[202];
          v72[2] = v36[200];
          v72[3] = v40;
          v72[4] = v41;
          do
          {
            ++v37;
            v39 += 2;
            *(float *)v39 = *v37;
            --v38;
          }
          while ( v38 != 0 );
          goto _M491153_2;
        case 'x':
          HIBYTE(v76[1]) = 120;
          v76[2] = &this->localstack.stack[v10 + v7];
          v45 = 5;
          v46 = v76;
          v47 = &v9[-1].coverIndex;
          do
          {
            ++v46;
            v47 += 2;
            *(_DWORD *)v47 = *v46;
            --v45;
          }
          while ( v45 != 0 );
          v10 += (int)idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)&type_string);
          idStr::idStr(this: &v73, text: (const char *)v9->spawnId.value);
          for ( j = 0; j < v73.len; ++j )
          {
            switch ( v73.data[j] )
            {
              case 'd':
              case 'e':
              case 'l':
                v49 = &type_integer;
                goto LABEL_50;
              case 'f':
                v49 = &type_float;
                goto LABEL_50;
              case 's':
                v49 = &type_string;
                goto LABEL_50;
              case 'v':
                v49 = &type_vector;
LABEL_50:
                v10 += (int)idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)v49);
                break;
              default:
                continue;
            }
          }
          idStr::FreeData(this: &v73);
          v11 = v69;
          goto _M491153_2;
        default:
          goto LABEL_59;
      }
    }
    if ( v13 == 102 )
    {
      v30 = v81;
      LODWORD(a4) = 102;
      v31 = 5;
      HIBYTE(v81[1]) = 102;
      v32 = &v9[-1].coverIndex;
      v81[2] = *(float *)&this->localstack.stack[v10 + v7];
      do
      {
        ++v30;
        v32 += 2;
        *(float *)v32 = *v30;
        --v31;
      }
      while ( v31 != 0 );
    }
    else if ( v13 > 0x62 )
    {
      if ( v13 == 100 )
      {
        HIBYTE(v77[1]) = 100;
        v77[2] = idProgram::DeclForId(
                   this: &gameLocal->program,
                   declId: *(const idIndex<int,enum invalidScriptDecl_t> **)&this->localstack.stack[v10 + v7]);
        v27 = v77;
        v28 = &v9[-1].coverIndex;
        for ( k = 5; k != 0; --k )
        {
          ++v27;
          v28 += 2;
          *(_DWORD *)v28 = *v27;
        }
      }
      else
      {
        if ( v13 != 101 )
          goto LABEL_59;
        v23 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&this->localstack.stack[v10 + v7]);
        idEventArg::idEventArg(this: &v79, data: v23);
        v24 = &v78;
        v25 = &v9[-1].coverIndex;
        for ( m = 5; m != 0; --m )
        {
          ++v24;
          v25 += 2;
          *(_DWORD *)v25 = *v24;
        }
      }
    }
    else if ( v13 == 98 )
    {
LABEL_33:
      v33 = &v73.baseBuffer[16];
      LODWORD(a4) = 105;
      v34 = 5;
      v74 = 105;
      v35 = &v9[-1].coverIndex;
      v75 = *(_DWORD *)&this->localstack.stack[v10 + v7];
      do
      {
        v33 += 4;
        v35 += 2;
        *(_DWORD *)v35 = *(_DWORD *)v33;
        --v34;
      }
      while ( v34 != 0 );
    }
    else if ( v13 > 0x35 )
    {
      if ( v13 != 97 )
        goto LABEL_59;
      v17 = (float *)(&this->doneProcessing + v10 + v7);
      v18 = v71;
      LODWORD(a4) = 97;
      v19 = 5;
      HIBYTE(v71[1]) = 97;
      v20 = &v9[-1].coverIndex;
      v21 = v17[201];
      v22 = v17[202];
      v71[2] = v17[200];
      v71[3] = v21;
      v71[4] = v22;
      do
      {
        ++v18;
        v20 += 2;
        *(float *)v20 = *v18;
        --v19;
      }
      while ( v19 != 0 );
    }
    else
    {
      if ( v13 != 53 && (v13 < 0x31 || v13 > 0x32) )
      {
LABEL_59:
        HIDWORD(v6) = *(_DWORD *)HIDWORD(v6);
        idInterpreter::Error(
          this,
          fmt: "Invalid arg format string for '%s' event.",
          a3: v6,
          a4,
          a5: v8,
          a6: v63,
          a7: v64,
          a8: v65,
          a9: v66,
          a10: v67,
          a11: v68);
        _LN160(a1: v62, a2: v61, a3: v60, a4: v59, a5: v58, a6: v57, a7: v56, a8: v55);
        return;
      }
LABEL_14:
      HIBYTE(v82[1]) = 115;
      v82[2] = &this->localstack.stack[v10 + v7];
      v14 = 5;
      v15 = v82;
      v16 = &v9[-1].coverIndex;
      do
      {
        ++v15;
        v16 += 2;
        *(_DWORD *)v16 = *v15;
        --v14;
      }
      while ( v14 != 0 );
      HIBYTE(v9->aas) = *v12;
    }
_M491153_2:
    LODWORD(v8) = v11 + 4;
    HIDWORD(a4) = v99;
    ++v12;
    HIDWORD(v6) = v70;
    v9 = (idAICover *)((char *)v9 + 20);
    v69 = v11 + 4;
    HIDWORD(v8) = func->parmSize.list;
    v50 = *(_DWORD *)(HIDWORD(v8) + v11);
    v11 += 4;
    v10 += v50;
  }
  this->popParms = HIDWORD(a4);
  idEventReceiver::ProcessEventArgPtr(
    this: (idEventReceiver *)&v79,
    result: this->thread,
    ev: (const idEventDef *)HIDWORD(v6),
    args: &v83);
  popParms = this->popParms;
  if ( popParms != 0 )
  {
    LODWORD(v51) = this->localstack.stackUsed;
    if ( (int)v51 < popParms )
      idInterpreter::Error(
        this,
        fmt: "locals stack underflow\n",
        a3: v53,
        a4: v52,
        a5: v51,
        a6: v63,
        a7: v64,
        a8: v65,
        a9: v66,
        a10: v67,
        a11: v68);
    this->localstack.stackUsed = v51 - popParms;
  }
  this->popParms = 0;
}


// ========================================================================
// $LN160
// EA  : 0x82E94610
// RVA : 0x00E94610
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void _LN160()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 768 + 192));
}


// ========================================================================
// ?CallScriptEvent@idInterpreter@@IAAXPBVfunction_t@@H@Z
// EA  : 0x82E94640
// RVA : 0x00E94640
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void __fastcall idInterpreter::CallScriptEvent(
        idInterpreter *this,
        const function_t *func,
        __int64 argsize,
        __int64 a4,
        __int64 a5)
{
  idInterpreter *v5; // r27
  idAICover *v7; // r28
  const idEventDef *eventdef; // r30
  int *v9; // r26
  idScriptList *ScriptList; // r3
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  const char *formatspec; // r29
  __int64 v15; // r6
  const bfx::Vec3 *CachedSize; // r3
  __int64 v17; // r10
  __int64 v18; // r8
  int v19; // r15
  unsigned int v20; // r11
  int v21; // ctr
  __int16 *v22; // r11
  double v23; // fp12
  int v24; // ctr
  const idEntity *v25; // r3
  int m; // ctr
  int k; // ctr
  int v28; // ctr
  double v29; // fp12
  int v30; // ctr
  int v31; // r4
  int i; // ctr
  _DWORD *v33; // r10
  int v34; // ctr
  __int16 *p_coverIndex; // r11
  int j; // r27
  idTypeDef *v37; // r3
  int v38; // r11
  __int64 v39; // r10
  __int64 v40; // r8
  __int64 v41; // r6
  int popParms; // r11
  int v43; // r26
  const char *v44; // r3
  __int64 v45; // r10
  __int64 v46; // r8
  __int64 v47; // r10
  __int64 v48; // r8
  __int64 v49; // r6
  int stackUsed; // r11
  int v51; // [sp+8h] [-2F8h]
  int v52; // [sp+8h] [-2F8h]
  int v53; // [sp+Ch] [-2F4h]
  int v54; // [sp+Ch] [-2F4h]
  int v55; // [sp+10h] [-2F0h]
  int v56; // [sp+10h] [-2F0h]
  int v57; // [sp+14h] [-2ECh]
  int v58; // [sp+14h] [-2ECh]
  int v59; // [sp+18h] [-2E8h]
  int v60; // [sp+18h] [-2E8h]
  int v61; // [sp+1Ch] [-2E4h]
  int v62; // [sp+1Ch] [-2E4h]
  const idEventDef *v63; // [sp+70h] [-290h]
  idEventReceiver *v64; // [sp+74h] [-28Ch]
  float v65[8]; // [sp+7Ch] [-284h] BYREF
  float v66[9]; // [sp+9Ch] [-264h] BYREF
  idStr v67; // [sp+C0h] [-240h] BYREF
  idStr v68; // [sp+E0h] [-220h] BYREF
  char v69; // [sp+100h] [-200h]
  char *v70; // [sp+104h] [-1FCh]
  int v71; // [sp+11Ch] [-1E4h] BYREF
  idEventArg v72; // [sp+120h] [-1E0h] BYREF
  _DWORD v73[8]; // [sp+13Ch] [-1C4h] BYREF
  _DWORD v74[8]; // [sp+15Ch] [-1A4h] BYREF
  float v75[8]; // [sp+17Ch] [-184h] BYREF
  _DWORD v76[9]; // [sp+19Ch] [-164h] BYREF
  idAICover v77; // [sp+1C0h] [-140h] BYREF
  char v78; // [sp+1D4h] [-12Ch]
  int v79; // [sp+1D8h] [-128h]
  char v80; // [sp+1E8h] [-118h]
  int v81; // [sp+1ECh] [-114h]
  char v82; // [sp+1FCh] [-104h]
  int v83; // [sp+200h] [-100h]
  char v84; // [sp+210h] [-F0h]
  int v85; // [sp+214h] [-ECh]
  char v86; // [sp+224h] [-DCh]
  int v87; // [sp+228h] [-D8h]
  char v88; // [sp+238h] [-C8h]
  int v89; // [sp+23Ch] [-C4h]
  char v90; // [sp+24Ch] [-B4h]
  int v91; // [sp+250h] [-B0h]
  int v94; // [sp+324h] [+24h]

  LODWORD(a5) = v67.baseBuffer;
  v94 = HIDWORD(argsize);
  v5 = this;
  v67.len = 0;
  v67.allocedAndFlag = 20;
  v7 = (idAICover *)HIDWORD(argsize);
  v67.data = v67.baseBuffer;
  v67.baseBuffer[0] = 0;
  if ( func == nullptr )
    idInterpreter::Error(
      this,
      fmt: "NULL function in CallScriptEvent",
      a3: argsize,
      a4,
      a5,
      a6: v51,
      a7: v53,
      a8: v55,
      a9: v57,
      a10: v59,
      a11: v61);
  eventdef = func->eventdef;
  v63 = func->eventdef;
  v9 = (int *)&v5->localstack.stack[v5->localstack.stackUsed - (_DWORD)v7];
  ScriptList = idGameLocal::GetScriptList(this: gameLocal, idToGet: *v9);
  v64 = &ScriptList->idEventReceiver;
  if ( ScriptList == nullptr )
  {
    v43 = *v9;
    v44 = idVarDef::Name(this: func->def);
    idInterpreter::Warning(
      this: v5,
      fmt: "Attempted to call %s on a list %d it is NULL",
      a3: __SPAIR64__((unsigned int)v44, v43),
      a4: v46,
      a5: v45,
      a6: v51,
      a7: v53,
      a8: v55,
      a9: v57,
      a10: v59,
      a11: v61);
    goto LABEL_59;
  }
  HIDWORD(v11) = ScriptList->RespondsTo(this: ScriptList, a2: eventdef);
  if ( HIDWORD(v11) == 0 )
  {
_LN186_1:
    HIDWORD(v13) = eventdef->name;
    idInterpreter::Warning(
      this: v5,
      fmt: "Function '%s' not supported on this list",
      a3: v13,
      a4: v12,
      a5: v11,
      a6: v51,
      a7: v53,
      a8: v55,
      a9: v57,
      a10: v59,
      a11: v61);
LABEL_59:
    idInterpreter::SafeReturn(this: v5, returnType: (char)eventdef->returnType);
    stackUsed = v5->localstack.stackUsed;
    if ( stackUsed < (int)v7 )
      idInterpreter::Error(
        this: v5,
        fmt: "locals stack underflow\n",
        a3: v49,
        a4: v48,
        a5: v47,
        a6: v52,
        a7: v54,
        a8: v56,
        a9: v58,
        a10: v60,
        a11: v62);
    v5->localstack.stackUsed = stackUsed - (_DWORD)v7;
    goto LABEL_62;
  }
  HIBYTE(v77.aas) = 0;
  v77.spawnId.value = 0;
  v78 = 0;
  v79 = 0;
  v80 = 0;
  v81 = 0;
  v82 = 0;
  v83 = 0;
  v84 = 0;
  v85 = 0;
  v86 = 0;
  v87 = 0;
  v88 = 0;
  v89 = 0;
  v90 = 0;
  v91 = 0;
  formatspec = eventdef->formatspec;
  CachedSize = idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)&type_object);
  HIDWORD(v17) = &pb_ss_UpdateAfterPhysics.name;
  LODWORD(v18) = &pb_ss_UpdateAfterPhysics.name;
  eventdef = (const idEventDef *)CachedSize;
  v19 = 0;
  v7 = &v77;
  while ( 1 )
  {
    if ( (int)eventdef >= v94 )
    {
      HIDWORD(v17) = *(unsigned __int8 *)formatspec;
      if ( *formatspec == 0 )
        break;
    }
    v20 = *(unsigned __int8 *)formatspec;
    if ( v20 > 0x66 )
    {
      switch ( *formatspec )
      {
        case 'i':
          goto LABEL_30;
        case 'l':
          v31 = *(int *)((char *)&eventdef->name + (_DWORD)v9);
          HIBYTE(v76[1]) = 108;
          v76[2] = idGameLocal::GetScriptList(this: gameLocal, idToGet: v31);
          LODWORD(v17) = v76;
          HIDWORD(v17) = (char *)v7 - 4;
          for ( i = 5; i != 0; --i )
          {
            LODWORD(v17) = v17 + 4;
            HIDWORD(v17) += 4;
            *(_DWORD *)HIDWORD(v17) = *(_DWORD *)v17;
          }
          goto _M491400_2;
        case 's':
          goto LABEL_15;
        case 'v':
          v66[2] = *(float *)((char *)&eventdef->name + (_DWORD)v9);
          HIDWORD(v17) = v66;
          HIBYTE(v66[1]) = 118;
          LODWORD(v18) = (char *)v7 - 4;
          v29 = *(float *)((char *)&eventdef->argTypes + (_DWORD)v9);
          v30 = 5;
          v66[3] = *(float *)((char *)&eventdef->formatspec + (_DWORD)v9);
          v66[4] = v29;
          do
          {
            HIDWORD(v17) += 4;
            LODWORD(v18) = v18 + 4;
            *(_DWORD *)v18 = *(_DWORD *)HIDWORD(v17);
            --v30;
          }
          while ( v30 != 0 );
          goto _M491400_2;
        case 'x':
          HIBYTE(v74[1]) = 120;
          v74[2] = (char *)eventdef + (_DWORD)v9;
          v33 = v74;
          v34 = 5;
          p_coverIndex = &v7[-1].coverIndex;
          do
          {
            ++v33;
            p_coverIndex += 2;
            *(_DWORD *)p_coverIndex = *v33;
            --v34;
          }
          while ( v34 != 0 );
          eventdef = (const idEventDef *)((char *)eventdef
                                        + (_DWORD)idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)&type_string));
          idStr::idStr(this: &v68, text: (const char *)v7->spawnId.value);
          for ( j = 0; j < v68.len; ++j )
          {
            switch ( v68.data[j] )
            {
              case 'd':
              case 'e':
              case 'l':
                v37 = &type_integer;
                goto LABEL_47;
              case 'f':
                v37 = &type_float;
                goto LABEL_47;
              case 's':
                v37 = &type_string;
                goto LABEL_47;
              case 'v':
                v37 = &type_vector;
LABEL_47:
                eventdef = (const idEventDef *)((char *)eventdef
                                              + (_DWORD)idreports::MapWarning::GetCachedSize(this: (bfx::SystemInstance *)v37));
                break;
              default:
                continue;
            }
          }
          idStr::FreeData(this: &v68);
          v5 = this;
          goto _M491400_2;
        default:
          goto LABEL_56;
      }
    }
    if ( v20 == 102 )
    {
      v75[2] = *(float *)((char *)&eventdef->name + (_DWORD)v9);
      LODWORD(v17) = v75;
      HIBYTE(v75[1]) = 102;
      HIDWORD(v17) = (char *)v7 - 4;
      for ( k = 5; k != 0; --k )
      {
        LODWORD(v17) = v17 + 4;
        HIDWORD(v17) += 4;
        *(_DWORD *)HIDWORD(v17) = *(_DWORD *)v17;
      }
    }
    else if ( v20 > 0x61 )
    {
      if ( v20 == 98 )
      {
LABEL_30:
        LODWORD(v18) = *(const char **)((char *)&eventdef->name + (_DWORD)v9);
        LODWORD(v17) = v73;
        HIDWORD(v18) = 105;
        HIDWORD(v17) = (char *)v7 - 4;
        v28 = 5;
        v73[2] = v18;
        HIBYTE(v73[1]) = 105;
        do
        {
          LODWORD(v17) = v17 + 4;
          HIDWORD(v17) += 4;
          *(_DWORD *)HIDWORD(v17) = *(_DWORD *)v17;
          --v28;
        }
        while ( v28 != 0 );
      }
      else
      {
        if ( v20 != 101 )
          goto LABEL_56;
        v25 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)((char *)eventdef + (_DWORD)v9));
        idEventArg::idEventArg(this: &v72, data: v25);
        LODWORD(v17) = &v71;
        HIDWORD(v17) = (char *)v7 - 4;
        for ( m = 5; m != 0; --m )
        {
          LODWORD(v17) = v17 + 4;
          HIDWORD(v17) += 4;
          *(_DWORD *)HIDWORD(v17) = *(_DWORD *)v17;
        }
      }
    }
    else if ( v20 == 97 )
    {
      v65[2] = *(float *)((char *)&eventdef->name + (_DWORD)v9);
      HIDWORD(v17) = v65;
      HIBYTE(v65[1]) = 97;
      LODWORD(v18) = (char *)v7 - 4;
      v23 = *(float *)((char *)&eventdef->argTypes + (_DWORD)v9);
      v24 = 5;
      v65[3] = *(float *)((char *)&eventdef->formatspec + (_DWORD)v9);
      v65[4] = v23;
      do
      {
        HIDWORD(v17) += 4;
        LODWORD(v18) = v18 + 4;
        *(_DWORD *)v18 = *(_DWORD *)HIDWORD(v17);
        --v24;
      }
      while ( v24 != 0 );
    }
    else
    {
      if ( v20 < 0x31 || v20 > 0x32 && v20 != 53 )
      {
LABEL_56:
        LODWORD(v17) = &off_822E0000;
        HIDWORD(v15) = v63->name;
        idInterpreter::Error(
          this: v5,
          fmt: "Invalid arg format string for '%s' event.",
          a3: v15,
          a4: v18,
          a5: v17,
          a6: v51,
          a7: v53,
          a8: v55,
          a9: v57,
          a10: v59,
          a11: v61);
        goto _LN186_1;
      }
LABEL_15:
      v69 = 115;
      v70 = (char *)eventdef + (_DWORD)v9;
      LODWORD(v17) = &v68.baseBuffer[16];
      v21 = 5;
      v22 = &v7[-1].coverIndex;
      do
      {
        LODWORD(v17) = v17 + 4;
        HIDWORD(v17) = *(_DWORD *)v17;
        v22 += 2;
        *(_DWORD *)v22 = *(_DWORD *)v17;
        --v21;
      }
      while ( v21 != 0 );
      HIBYTE(v7->aas) = *formatspec;
    }
_M491400_2:
    ++formatspec;
    v7 = (idAICover *)((char *)v7 + 20);
    v38 = func->parmSize.list[v19++];
    eventdef = (const idEventDef *)((char *)eventdef + v38);
  }
  v5->popParms = v94;
  idEventReceiver::ProcessEventArgPtr(this: (idEventReceiver *)&v72, result: v64, ev: v63, args: &v77);
  popParms = v5->popParms;
  if ( popParms != 0 )
  {
    LODWORD(v39) = v5->localstack.stackUsed;
    if ( (int)v39 < popParms )
      idInterpreter::Error(
        this: v5,
        fmt: "locals stack underflow\n",
        a3: v41,
        a4: v40,
        a5: v39,
        a6: v51,
        a7: v53,
        a8: v55,
        a9: v57,
        a10: v59,
        a11: v61);
    v5->localstack.stackUsed = v39 - popParms;
  }
  v5->popParms = 0;
LABEL_62:
  idStr::FreeData(this: &v67);
}


// ========================================================================
// $LN166
// EA  : 0x82E94BD0
// RVA : 0x00E94BD0
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void _LN166()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 768 + 192));
}


// ========================================================================
// __unwind$491183_0
// EA  : 0x82E94BF8
// RVA : 0x00E94BF8
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void _unwind_491183_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 768 + 224));
}


// ========================================================================
// ?ThreadCall@idInterpreter@@QAAXPAV1@PBVfunction_t@@H@Z
// EA  : 0x82E94C20
// RVA : 0x00E94C20
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void __fastcall idInterpreter::ThreadCall(idInterpreter *this, idInterpreter *source, idDecl *func, size_t args)
{
  __int64 v7; // r10
  __int64 v8; // r8
  unsigned int v9; // r6
  const char *v10; // r3

  this->localstack.callStackDepth = 0;
  this->localstack.stackUsed = 0;
  this->localstack.instructionPointer = -1;
  this->localstack.stackBase = 0;
  this->localstack.maxStackUsed = 0;
  this->localstack.maxCallStackDepth = 0;
  this->popParms = 0;
  this->multiFrameEvent = nullptr;
  this->eventEntity = nullptr;
  this->localstack.currentFunction = nullptr;
  this->threadDying = false;
  this->doneProcessing = true;
  memcpy(Dst: this->localstack.stack, Src: &source->localstack.stack[source->localstack.stackUsed - args], Size: args);
  this->localstack.stackUsed = args;
  this->localstack.maxStackUsed = args;
  this->localstack.stackBase = 0;
  idInterpreter::EnterFunction(this, func, clearStack: v9, a4: v8, a5: v7);
  v10 = (const char *)function_t::Name(this: (idDecl *)this->localstack.currentFunction);
  idThread::SetThreadName(this: this->thread, name: v10);
}


// ========================================================================
// ?EnterObjectFunction@idInterpreter@@QAAXPAVidEntity@@PBVfunction_t@@_N@Z
// EA  : 0x82E94CC8
// RVA : 0x00E94CC8
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void __fastcall idInterpreter::EnterObjectFunction(idInterpreter *this, idEntity *self, __int64 clearStack, __int64 a4)
{
  idDecl *v5; // r30
  int v6; // r11
  __int64 v7; // r10
  __int64 v8; // r10
  __int64 v9; // r8
  unsigned int v10; // r6
  int v11; // [sp+8h] [-88h]
  int v12; // [sp+Ch] [-84h]
  int v13; // [sp+10h] [-80h]
  int v14; // [sp+14h] [-7Ch]
  int v15; // [sp+18h] [-78h]
  int v16; // [sp+1Ch] [-74h]

  v5 = (idDecl *)HIDWORD(clearStack);
  v6 = 0;
  if ( (_BYTE)clearStack != 0 )
  {
    this->localstack.callStackDepth = 0;
    this->localstack.stackUsed = 0;
    this->localstack.stackBase = 0;
    this->localstack.maxStackUsed = 0;
    this->localstack.maxCallStackDepth = 0;
    this->popParms = 0;
    this->multiFrameEvent = nullptr;
    this->eventEntity = nullptr;
    this->localstack.currentFunction = nullptr;
    this->localstack.instructionPointer = -1;
    this->threadDying = false;
    this->doneProcessing = true;
  }
  LODWORD(v7) = this->popParms;
  if ( (_DWORD)v7 != 0 )
  {
    HIDWORD(v7) = this->localstack.stackUsed;
    if ( SHIDWORD(v7) < (int)v7 )
      idInterpreter::Error(
        this,
        fmt: "locals stack underflow\n",
        a3: clearStack,
        a4,
        a5: v7,
        a6: v11,
        a7: v12,
        a8: v13,
        a9: v14,
        a10: v15,
        a11: v16);
    this->popParms = v6;
    this->localstack.stackUsed = HIDWORD(v7) - v7;
  }
  idInterpreter::PushEntity(this, ent: self);
  idInterpreter::EnterFunction(this, func: v5, clearStack: v10, a4: v9, a5: v8);
}


// ========================================================================
// ?EnterFunctionWithParms@idInterpreter@@QAA_NPBVfunction_t@@HPAVidEventArg@@_N@Z
// EA  : 0x82E94D90
// RVA : 0x00E94D90
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

int __fastcall idInterpreter::EnterFunctionWithParms(
        idInterpreter *this,
        idDecl *func,
        idDeclSource *numArgs,
        idAICover *args,
        bool clearStack)
{
  __int64 v9; // r10
  __int64 v10; // r8
  unsigned int v11; // r6
  int v13; // r29
  bfx::Planner3D *ParmType; // r3
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  int v18; // r4
  int aas_high; // r11
  char v20; // r11
  bool v21; // zf
  double v22; // fp13
  const idEntity *Entity; // r3
  int v24; // r11
  int value; // r4
  int v26; // [sp+50h] [-60h] BYREF
  idInterpreter *v27; // [sp+58h] [-58h]
  float v28; // [sp+5Ch] [-54h]
  float v29; // [sp+60h] [-50h]

  if ( clearStack )
  {
    this->localstack.callStackDepth = 0;
    this->localstack.stackUsed = 0;
    this->localstack.stackBase = 0;
    this->localstack.maxStackUsed = 0;
    this->localstack.maxCallStackDepth = 0;
    this->popParms = 0;
    this->multiFrameEvent = nullptr;
    this->eventEntity = nullptr;
    this->localstack.currentFunction = nullptr;
    this->localstack.instructionPointer = -1;
    this->threadDying = false;
    this->doneProcessing = true;
  }
  if ( numArgs != function_t::Name(this: (idDecl *)func->name.str) )
    return 0;
  v13 = 0;
  if ( (int)numArgs > 0 )
  {
    while ( 2 )
    {
      ParmType = (bfx::Planner3D *)idTypeDef::GetParmType(this: (idTypeDef *)func->name.str, parmNumber: v13);
      switch ( (unsigned int)idScriptObject::GetTypeDef(this: ParmType) )
      {
        case 3u:
          aas_high = SHIBYTE(args->aas);
          if ( aas_high == 115 || aas_high == 49 || aas_high == 50 || (v21 = aas_high != 53, v20 = 0, !v21) )
            v20 = 1;
          if ( v20 == 0 )
            return 0;
          idInterpreter::PushString(this, string: (const char *)args->spawnId.value, a3: v17, a4: v16, a5: v15);
          goto LABEL_28;
        case 4u:
          if ( HIBYTE(args->aas) != 102 )
            return 0;
          idInterpreter::PushFloat(this, value: *(float *)&args->spawnId.value, a3: v18, a4: v17, a5: v16, a6: v15);
          goto LABEL_28;
        case 5u:
          v24 = SHIBYTE(args->aas);
          if ( v24 != 105 && v24 != 98 )
            return 0;
          value = args->spawnId.value;
          goto LABEL_27;
        case 6u:
          if ( HIBYTE(args->aas) != 118 )
            return 0;
          v22 = *(float *)&args->coverIndex;
          v27 = (idInterpreter *)args->spawnId.value;
          v28 = v22;
          v29 = *(float *)&args[1].aas;
          HIDWORD(v17) = __ROL4__(LODWORD(v29), 32);
          idInterpreter::PushVec3(this: v27, value: (idVec3 *)LODWORD(v28), a3: v17, a4: v16, a5: v15);
          goto LABEL_28;
        case 8u:
        case 0xDu:
          if ( HIBYTE(args->aas) != 101 )
            return 0;
          Entity = idEventArg::GetEntity(this: args);
          idInterpreter::PushEntity(this, ent: Entity);
          goto LABEL_28;
        case 0x10u:
          if ( HIBYTE(args->aas) != 108 )
            return 0;
          idInterpreter::PushScriptType(
            this,
            scriptTypeID: *(_DWORD *)(args->spawnId.value + 28),
            a3: v17,
            a4: v16,
            a5: v15);
          goto LABEL_28;
        case 0x12u:
          if ( HIBYTE(args->aas) != 100 )
            return 0;
          idProgram::RegisterDecl(
            this: (idProgram *)&v26,
            result: (idIndex<int,enum invalidScriptDecl_t> *)&gameLocal->program,
            decl: (const idDecl *)args->spawnId.value);
          value = v26;
LABEL_27:
          idInterpreter::PushInt(this, value, a3: v17, a4: v16, a5: v15);
LABEL_28:
          ++v13;
          args = (idAICover *)((char *)args + 20);
          if ( v13 >= (int)numArgs )
            break;
          continue;
        default:
          return 0;
      }
      break;
    }
  }
  idInterpreter::EnterFunction(this, func, clearStack: v11, a4: v10, a5: v9);
  return 1;
}


// ========================================================================
// ?Execute@idInterpreter@@QAA_NXZ
// EA  : 0x82E95008
// RVA : 0x00E95008
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idInterpreter::Execute(idInterpreter *this)
{
  __int64 v2; // r8 OVERLAPPED
  __int64 v3; // r6 OVERLAPPED
  _BYTE v4[12]; // r11 OVERLAPPED
  int v5; // r4
  int v6; // r27
  int v7; // r29
  idThread *currentThread; // r27
  idThread *v9; // r3
  idThread *v10; // r28
  bfx::Planner3D *v11; // r3
  int v12; // r28
  idTypeDef *v13; // r3
  const function_t *v14; // r27
  idThread *v15; // r26
  idThread *v16; // r3
  idThread *v17; // r28
  idScriptList *v18; // r28
  varEval_t *v19; // r3
  idScriptList *v20; // r3
  bfx::Planner3D *v21; // r3
  int v22; // r29
  idTypeDef *TypeDef; // r3
  idDecl *Function; // r3
  __int64 v25; // r10
  __int64 v26; // r8
  unsigned int v27; // r6
  char *v28; // r3
  bfx::Planner3D *v29; // r3
  bfx::Planner3D *v30; // r3
  float *v31; // r28
  varEval_t *v32; // r3
  idVarDef *v33; // r5
  float *v34; // r29
  varEval_t *v35; // r3
  _DWORD *v36; // r28
  varEval_t *v37; // r3
  idVarDef *v38; // r5
  _DWORD *v39; // r29
  varEval_t *v40; // r3
  float *v41; // r28
  varEval_t *v42; // r3
  idVarDef *v43; // r5
  float *v44; // r29
  double v45; // fp8
  double v46; // fp6
  idVarDef *v47; // r11
  const char *cp; // r4
  int v49; // r11
  char *v50; // r3
  int v51; // r11
  const char *v52; // r5
  int v53; // r11
  varEval_t *v54; // r3
  char *v55; // r3
  __int64 v56; // r8
  char *v57; // r3
  varEval_t *v58; // r3
  idVarDef *v59; // r11
  float *v60; // r28
  const char *v61; // r4
  int v62; // r11
  char *v63; // r3
  char *v64; // r3
  varEval_t *v65; // r3
  idVarDef *v66; // r11
  _DWORD *v67; // r28
  const char *v68; // r4
  int v69; // r11
  char *v70; // r3
  __int64 v71; // r10
  char *v72; // r3
  idAngles **v73; // r3
  const char *v74; // r3
  idAngles **v75; // r3
  idVarDef *v76; // r11
  idAngles *v77; // r28
  const char *v78; // r4
  int v79; // r11
  char *v80; // r3
  const char *v81; // r3
  float *v82; // r28
  varEval_t *v83; // r3
  idVarDef *v84; // r5
  float *v85; // r29
  varEval_t *v86; // r3
  _DWORD *v87; // r28
  varEval_t *v88; // r3
  idVarDef *v89; // r5
  _DWORD *v90; // r29
  varEval_t *v91; // r3
  float *v92; // r28
  varEval_t *v93; // r3
  idVarDef *v94; // r5
  float *v95; // r29
  double v96; // fp8
  double v97; // fp6
  float *v98; // r28
  varEval_t *v99; // r3
  idVarDef *v100; // r5
  float *v101; // r29
  varEval_t *v102; // r3
  _DWORD *v103; // r28
  varEval_t *v104; // r3
  idVarDef *v105; // r5
  _DWORD *v106; // r29
  varEval_t *v107; // r3
  float *v108; // r28
  varEval_t *v109; // r3
  idVarDef *v110; // r5
  float *v111; // r29
  varEval_t *v112; // r3
  float *v113; // r28
  varEval_t *v114; // r3
  idVarDef *v115; // r5
  float *v116; // r29
  double v117; // fp9
  double v118; // fp8
  float *v119; // r28
  varEval_t *v120; // r3
  idVarDef *v121; // r5
  float *v122; // r29
  double v123; // fp9
  double v124; // fp8
  _DWORD *v125; // r28
  varEval_t *v126; // r3
  idVarDef *v127; // r5
  float *v128; // r29
  varEval_t *v129; // r3
  double v130; // fp0
  double v131; // fp13
  double v132; // fp12
  float *v133; // r28
  varEval_t *v134; // r3
  idVarDef *v135; // r5
  _DWORD *v136; // r29
  varEval_t *v137; // r3
  double v138; // fp0
  double v139; // fp13
  double v140; // fp12
  float *v141; // r28
  varEval_t *v142; // r3
  idVarDef *v143; // r5
  float *v144; // r29
  varEval_t *v145; // r3
  double v146; // fp0
  float *v147; // r29
  _DWORD *v148; // r28
  varEval_t *v149; // r3
  idVarDef *v150; // r5
  signed int *v151; // r29
  __int64 v152; // r10
  __int64 v153; // r8
  varEval_t *v154; // r3
  signed int v155; // r11
  int *v156; // r29
  bool v157; // zf
  float *v158; // r28
  varEval_t *v159; // r3
  idVarDef *v160; // r5
  float *v161; // r29
  __int64 v162; // r10
  __int64 v163; // r8
  __int64 v164; // r6
  varEval_t *v165; // r3
  long double v166; // fp4
  long double v167; // fp2
  float *v168; // r29
  long double v169; // fp2
  varEval_t *v170; // r3
  idVarDef *v171; // r5
  signed int *v172; // r29
  varEval_t *v173; // r3
  signed int v174; // r11
  _DWORD *v175; // r28
  varEval_t *v176; // r3
  idVarDef *v177; // r5
  _DWORD *v178; // r29
  varEval_t *v179; // r3
  _DWORD *v180; // r28
  varEval_t *v181; // r3
  idVarDef *v182; // r5
  _DWORD *v183; // r29
  varEval_t *v184; // r3
  float *v185; // r28
  varEval_t *v186; // r3
  idVarDef *v187; // r5
  float *v188; // r29
  _DWORD *v189; // r28
  varEval_t *v190; // r3
  idVarDef *v191; // r5
  _DWORD *v192; // r29
  varEval_t *v193; // r3
  float *v194; // r28
  varEval_t *v195; // r3
  idVarDef *v196; // r5
  _DWORD *v197; // r29
  varEval_t *v198; // r3
  double v199; // fp0
  _DWORD *v200; // r28
  varEval_t *v201; // r3
  idVarDef *v202; // r5
  float *v203; // r29
  varEval_t *v204; // r3
  double v205; // fp0
  float *v206; // r28
  varEval_t *v207; // r3
  idVarDef *v208; // r5
  float *v209; // r29
  _DWORD *v210; // r28
  varEval_t *v211; // r3
  idVarDef *v212; // r5
  _DWORD *v213; // r29
  varEval_t *v214; // r3
  float *v215; // r28
  varEval_t *v216; // r3
  idVarDef *v217; // r5
  _DWORD *v218; // r29
  varEval_t *v219; // r3
  double v220; // fp0
  _DWORD *v221; // r28
  varEval_t *v222; // r3
  idVarDef *v223; // r5
  float *v224; // r29
  varEval_t *v225; // r3
  double v226; // fp0
  float *v227; // r28
  varEval_t *v228; // r3
  idVarDef *v229; // r5
  float *v230; // r29
  _DWORD *v231; // r28
  varEval_t *v232; // r3
  idVarDef *v233; // r5
  _DWORD *v234; // r29
  varEval_t *v235; // r3
  float *v236; // r28
  varEval_t *v237; // r3
  idVarDef *v238; // r5
  _DWORD *v239; // r29
  varEval_t *v240; // r3
  double v241; // fp0
  _DWORD *v242; // r28
  varEval_t *v243; // r3
  idVarDef *v244; // r5
  float *v245; // r29
  varEval_t *v246; // r3
  double v247; // fp0
  float *v248; // r28
  varEval_t *v249; // r3
  idVarDef *v250; // r5
  float *v251; // r29
  _DWORD *v252; // r28
  varEval_t *v253; // r3
  idVarDef *v254; // r5
  _DWORD *v255; // r29
  varEval_t *v256; // r3
  float *v257; // r28
  varEval_t *v258; // r3
  idVarDef *v259; // r5
  _DWORD *v260; // r29
  varEval_t *v261; // r3
  double v262; // fp0
  _DWORD *v263; // r28
  varEval_t *v264; // r3
  idVarDef *v265; // r5
  float *v266; // r29
  varEval_t *v267; // r3
  double v268; // fp0
  _DWORD *v269; // r28
  varEval_t *v270; // r3
  idVarDef *v271; // r5
  _DWORD *v272; // r29
  varEval_t *v273; // r3
  int v274; // r11
  _DWORD *v275; // r28
  varEval_t *v276; // r3
  idVarDef *v277; // r5
  _DWORD *v278; // r29
  varEval_t *v279; // r3
  int v280; // r11
  unsigned int **v281; // r3
  idVarDef *v282; // r5
  unsigned int *v283; // r29
  varEval_t *v284; // r3
  varEval_t *v285; // r3
  idVarDef *v286; // r5
  float *v287; // r29
  varEval_t *v288; // r3
  idVarDef *v289; // r5
  float *v290; // r29
  float *v291; // r10
  unsigned __int8 v292; // r11
  float *v293; // r28
  bfx::Planner3D *v294; // r3
  unsigned int **v295; // r3
  idVarDef *v296; // r5
  unsigned int *v297; // r29
  varEval_t *v298; // r3
  varEval_t *v299; // r3
  idVarDef *v300; // r5
  float *v301; // r29
  varEval_t *v302; // r3
  idVarDef *v303; // r5
  float *v304; // r29
  double v305; // fp10
  double v306; // fp9
  varEval_t *v307; // r3
  idVarDef *v308; // r5
  _DWORD *v309; // r29
  varEval_t *v310; // r3
  varEval_t *v311; // r3
  idVarDef *v312; // r5
  float *v313; // r29
  varEval_t *v314; // r3
  idVarDef *v315; // r5
  _DWORD *v316; // r29
  float *v317; // r28
  varEval_t *v318; // r3
  idVarDef *v319; // r5
  float *v320; // r29
  float *v321; // r28
  varEval_t *v322; // r3
  idVarDef *v323; // r5
  float *v324; // r29
  varEval_t *v325; // r3
  unsigned __int8 v326; // r11
  varEval_t *v327; // r3
  int v328; // r11
  _DWORD *v329; // r28
  const char *v330; // r4
  idVarDef *v331; // r11
  _DWORD *v332; // r28
  varEval_t *v333; // r3
  idVarDef *v334; // r5
  _DWORD *v335; // r29
  varEval_t *v336; // r3
  _DWORD *v337; // r28
  varEval_t *v338; // r3
  idVarDef *v339; // r5
  float *v340; // r29
  varEval_t *v341; // r3
  double v342; // fp0
  float *v343; // r28
  varEval_t *v344; // r3
  idVarDef *v345; // r5
  _DWORD *v346; // r29
  varEval_t *v347; // r3
  double v348; // fp0
  varEval_t *v349; // r3
  idVarDef *v350; // r5
  varEval_t *v351; // r3
  idVarDef *v352; // r5
  _DWORD *v353; // r29
  idEntity *Entity; // r28
  varEval_t *v355; // r3
  idVarDef *v356; // r5
  varEval_t *v357; // r3
  idVarDef *v358; // r5
  varEval_t *v359; // r3
  idVarDef *v360; // r4
  _DWORD *v361; // r29
  varEval_t *v362; // r3
  idEntity *v363; // r28
  varEval_t *v364; // r3
  idVarDef *v365; // r5
  varEval_t *v366; // r3
  idVarDef *v367; // r5
  varEval_t *v368; // r3
  idVarDef *v369; // r4
  _DWORD *v370; // r28
  bfx::Planner3D *v371; // r27
  _DWORD *v372; // r28
  varEval_t *v373; // r3
  idVarDef *v374; // r5
  _DWORD *v375; // r29
  varEval_t *v376; // r3
  float *v377; // r28
  varEval_t *v378; // r3
  idVarDef *v379; // r5
  float *v380; // r29
  float *v381; // r28
  varEval_t *v382; // r3
  idVarDef *v383; // r5
  float *v384; // r29
  varEval_t *v385; // r3
  unsigned __int8 v386; // r11
  _DWORD *v387; // r28
  varEval_t *v388; // r3
  idVarDef *v389; // r5
  _DWORD *v390; // r29
  varEval_t *v391; // r3
  _DWORD *v392; // r28
  varEval_t *v393; // r3
  idVarDef *v394; // r5
  float *v395; // r29
  varEval_t *v396; // r3
  double v397; // fp0
  float *v398; // r28
  varEval_t *v399; // r3
  idVarDef *v400; // r5
  _DWORD *v401; // r29
  varEval_t *v402; // r3
  double v403; // fp0
  varEval_t *v404; // r3
  int v405; // r11
  _DWORD *v406; // r28
  const char *v407; // r4
  idVarDef *v408; // r11
  varEval_t *v409; // r3
  idVarDef *v410; // r5
  varEval_t *v411; // r3
  idVarDef *v412; // r5
  _DWORD *v413; // r29
  idEntity *v414; // r28
  varEval_t *v415; // r3
  idVarDef *v416; // r5
  varEval_t *v417; // r3
  idVarDef *v418; // r5
  varEval_t *v419; // r3
  idVarDef *v420; // r4
  float *v421; // r29
  idEntity *v422; // r28
  varEval_t *v423; // r3
  idVarDef *v424; // r5
  varEval_t *v425; // r3
  idVarDef *v426; // r5
  varEval_t *v427; // r3
  idVarDef *v428; // r4
  _DWORD *v429; // r29
  idEntity *v430; // r28
  _DWORD *v431; // r28
  bfx::Planner3D *v432; // r27
  bfx::Planner3D *v433; // r3
  _DWORD *v434; // r28
  varEval_t *v435; // r3
  idVarDef *v436; // r5
  _DWORD *v437; // r29
  varEval_t *v438; // r3
  varEval_t *v439; // r3
  idVarDef *v440; // r5
  float *v441; // r29
  varEval_t *v442; // r3
  varEval_t *v443; // r3
  idVarDef *v444; // r5
  _DWORD *v445; // r29
  varEval_t *v446; // r3
  varEval_t *v447; // r3
  idVarDef *v448; // r5
  float *v449; // r29
  varEval_t *v450; // r3
  double v451; // fp10
  varEval_t *v452; // r3
  idVarDef *v453; // r5
  _DWORD *v454; // r29
  varEval_t *v455; // r3
  idVarDef *v456; // r5
  float *v457; // r29
  varEval_t *v458; // r3
  idVarDef *v459; // r5
  float *v460; // r29
  varEval_t *v461; // r3
  varEval_t *v462; // r3
  idVarDef *v463; // r5
  _DWORD *v464; // r29
  varEval_t *v465; // r3
  varEval_t *v466; // r3
  idVarDef *v467; // r5
  float *v468; // r29
  varEval_t *v469; // r3
  double v470; // fp8
  varEval_t *v471; // r3
  idVarDef *v472; // r5
  _DWORD *v473; // r29
  varEval_t *v474; // r3
  idVarDef *v475; // r5
  float *v476; // r29
  varEval_t *v477; // r3
  idVarDef *v478; // r5
  float *v479; // r29
  varEval_t *v480; // r3
  varEval_t *v481; // r3
  idVarDef *v482; // r5
  _DWORD *v483; // r29
  varEval_t *v484; // r3
  varEval_t *v485; // r3
  idVarDef *v486; // r5
  _DWORD *v487; // r29
  varEval_t *v488; // r3
  idVarDef *v489; // r5
  float *v490; // r29
  varEval_t *v491; // r3
  double v492; // fp9
  double v493; // fp8
  varEval_t *v494; // r3
  idVarDef *v495; // r5
  _DWORD *v496; // r29
  double v497; // fp13
  double v498; // fp12
  varEval_t *v499; // r3
  idVarDef *v500; // r5
  float *v501; // r29
  varEval_t *v502; // r3
  double v503; // fp0
  varEval_t *v504; // r3
  idVarDef *v505; // r5
  signed int *v506; // r29
  varEval_t *v507; // r3
  signed int v508; // r11
  varEval_t *v509; // r3
  idVarDef *v510; // r5
  _DWORD *v511; // r29
  varEval_t *v512; // r3
  double v513; // fp0
  varEval_t *v514; // r3
  idVarDef *v515; // r5
  float *v516; // r29
  varEval_t *v517; // r3
  double v518; // fp0
  float *v519; // r29
  double v520; // fp0
  double v521; // fp12
  double v522; // fp11
  varEval_t *v523; // r3
  idVarDef *v524; // r5
  _DWORD *v525; // r29
  varEval_t *v526; // r3
  double v527; // fp0
  double v528; // fp13
  double v529; // fp12
  varEval_t::<unnamed_type_value> **v530; // r3
  idVarDef *v531; // r5
  varEval_t::<unnamed_type_value> *v532; // r29
  __int64 v533; // r10
  __int64 v534; // r8
  __int64 v535; // r6
  varEval_t *v536; // r3
  long double v537; // fp4
  long double v538; // fp2
  float *v539; // r28
  long double v540; // fp2
  varEval_t *v541; // r3
  float v542; // r11
  varEval_t *v543; // r3
  idVarDef *v544; // r5
  float *v545; // r29
  varEval_t *v546; // r3
  idVarDef *v547; // r5
  _DWORD *v548; // r29
  varEval_t *v549; // r3
  varEval_t *v550; // r3
  idVarDef *v551; // r5
  _DWORD *v552; // r29
  varEval_t *v553; // r3
  varEval_t *v554; // r3
  idVarDef *v555; // r5
  float *v556; // r29
  varEval_t *v557; // r3
  idVarDef *v558; // r5
  float *v559; // r29
  varEval_t *v560; // r3
  idVarDef *v561; // r5
  _DWORD *v562; // r29
  varEval_t *v563; // r3
  varEval_t *v564; // r3
  idVarDef *v565; // r5
  _DWORD *v566; // r29
  varEval_t *v567; // r3
  varEval_t *v568; // r3
  idVarDef *v569; // r5
  float *v570; // r29
  varEval_t *Variable; // r3
  bfx::Planner3D *ScriptObject; // r3
  varEval_t *v573; // r3
  bfx::Planner3D *v574; // r3
  varEval_t *v575; // r3
  bfx::Planner3D *v576; // r3
  varEval_t *v577; // r3
  bfx::Planner3D *v578; // r3
  varEval_t *v579; // r3
  idVarDef *v580; // r5
  float *i; // r29
  varEval_t *v582; // r3
  idVarDef *v583; // r5
  _DWORD *v584; // r29
  varEval_t *v585; // r3
  varEval_t *v586; // r3
  idVarDef *v587; // r5
  float *v588; // r29
  varEval_t *v589; // r3
  idVarDef *v590; // r5
  int *v591; // r29
  varEval_t *v592; // r3
  varEval_t *v593; // r3
  idVarDef *v594; // r5
  int *v595; // r29
  varEval_t *v596; // r3
  int *v597; // r26
  varEval_t *v598; // r3
  int *v599; // r27
  idScriptList *ScriptList; // r28
  const char *v601; // r3
  int v602; // r3
  _DWORD *v603; // r28
  bfx::Planner3D *v604; // r3
  const idTypeDef *v605; // r27
  idTypeDef *v606; // r3
  _DWORD *v607; // r28
  bfx::Planner3D *v608; // r28
  _DWORD *v609; // r27
  bfx::Planner3D *v610; // r3
  const idTypeDef *v611; // r28
  idTypeDef *v612; // r3
  varEval_t *v613; // r3
  idVarDef *v614; // r5
  int *v615; // r29
  varEval_t *v616; // r3
  idVarDef *v617; // r11
  const char *v618; // r4
  int v619; // r11
  varEval_t *v620; // r3
  idVarDef *v621; // r5
  float *v622; // r29
  varEval_t *v623; // r3
  char *v624; // r3
  varEval_t *v625; // r3
  __int64 v626; // r10
  __int64 v627; // r6
  __int64 v628; // r8
  va *v629; // r3
  idAngles **v630; // r3
  const char *v631; // r3
  varEval_t *v632; // r3
  idVarDef *v633; // r5
  float *v634; // r29
  varEval_t *v635; // r3
  idVarDef *v636; // r5
  _DWORD *v637; // r29
  float **v638; // r28
  _DWORD **v639; // r28
  _DWORD **v640; // r28
  varEval_t::<unnamed_type_value> *v641; // r27
  int *v642; // r26
  int v643; // r4
  idScriptList *v644; // r28
  const char *v645; // r3
  int v646; // r3
  _DWORD **v647; // r28
  char *v648; // r3
  idVarDef *v649; // r11
  _DWORD *v650; // r28
  varEval_t *v651; // r3
  char **v652; // r28
  varEval_t *v653; // r3
  char *v654; // r29
  char *v655; // r3
  char **v656; // r28
  varEval_t *v657; // r3
  char **v658; // r28
  idAngles **v659; // r3
  char *v660; // r29
  const char *v661; // r3
  _DWORD **v662; // r28
  _DWORD *v663; // r28
  varEval_t *v664; // r3
  _DWORD **v665; // r28
  bfx::Planner3D *v666; // r3
  const idTypeDef *v667; // r27
  idTypeDef *v668; // r3
  _DWORD **v669; // r28
  _DWORD *v670; // r28
  bfx::Planner3D *v671; // r3
  float *v672; // r28
  bfx::Planner3D *v673; // r3
  bfx::Planner3D *v674; // r3
  _DWORD *v675; // r28
  bfx::Planner3D *v676; // r3
  bfx::Planner3D *v677; // r3
  bfx::Planner3D *v678; // r3
  float *v679; // r11
  _DWORD *v680; // r28
  bfx::Planner3D *v681; // r3
  bfx::Planner3D *v682; // r3
  varEval_t *v683; // r3
  __int64 v684; // r10
  __int64 v685; // r8
  __int64 v686; // r6
  varEval_t *v687; // r3
  __int64 v688; // r10
  __int64 v689; // r8
  __int64 v690; // r6
  int v691; // r4
  varEval_t *v692; // r3
  __int64 v693; // r10
  __int64 v694; // r8
  __int64 v695; // r6
  varEval_t *v696; // r3
  char *v697; // r3
  __int64 v698; // r10
  __int64 v699; // r8
  __int64 v700; // r6
  varEval_t *v701; // r3
  __int64 v702; // r10
  __int64 v703; // r8
  __int64 v704; // r6
  int v705; // r4
  varEval_t *v706; // r3
  __int64 v707; // r10
  __int64 v708; // r8
  __int64 v709; // r6
  idAngles **v710; // r3
  const char *v711; // r3
  __int64 v712; // r10
  __int64 v713; // r8
  __int64 v714; // r6
  varEval_t *v715; // r3
  __int64 v716; // r10
  __int64 v717; // r6
  __int64 v718; // r8
  va *v719; // r3
  __int64 v720; // r10
  __int64 v721; // r8
  __int64 v722; // r6
  const idEntityPtr<idEntity> **v723; // r3
  __int64 v724; // r10
  __int64 v725; // r8
  __int64 v726; // r6
  idInterpreter ***v727; // r3
  __int64 v728; // r10
  __int64 v729; // r6
  __int64 v730; // r8
  const idEntityPtr<idEntity> **v731; // r3
  __int64 v732; // r10
  __int64 v733; // r8
  __int64 v734; // r6
  const idEntityPtr<idEntity> **v735; // r3
  __int64 v736; // r10
  __int64 v737; // r8
  __int64 v738; // r6
  varEval_t *v739; // r3
  __int64 v740; // r10
  __int64 v741; // r8
  __int64 v742; // r6
  float *v743; // r28
  varEval_t *v744; // r3
  idVarDef *v745; // r5
  _DWORD *v746; // r29
  varEval_t *v747; // r3
  double v748; // fp0
  _DWORD *v749; // r28
  varEval_t *v750; // r3
  idVarDef *v751; // r5
  float *v752; // r29
  varEval_t *v753; // r3
  double v754; // fp0
  float *v755; // r28
  varEval_t *v756; // r3
  idVarDef *v757; // r5
  _DWORD *v758; // r29
  varEval_t *v759; // r3
  double v760; // fp0
  double v761; // fp13
  double v762; // fp12
  float *v763; // r28
  varEval_t *v764; // r3
  idVarDef *v765; // r5
  float *v766; // r29
  double v767; // fp13
  double v768; // fp11
  double v769; // fp10
  float *v770; // r28
  varEval_t *v771; // r3
  idVarDef *v772; // r5
  _DWORD *v773; // r29
  varEval_t *v774; // r3
  double v775; // fp0
  _DWORD *v776; // r28
  varEval_t *v777; // r3
  idVarDef *v778; // r5
  float *v779; // r29
  varEval_t *v780; // r3
  double v781; // fp0
  float *v782; // r28
  varEval_t *v783; // r3
  idVarDef *v784; // r5
  _DWORD *v785; // r29
  varEval_t *v786; // r3
  double v787; // fp0
  _DWORD *v788; // r28
  varEval_t *v789; // r3
  idVarDef *v790; // r5
  float *v791; // r29
  varEval_t *v792; // r3
  double v793; // fp0
  float *v794; // r28
  varEval_t *v795; // r3
  idVarDef *v796; // r5
  _DWORD *v797; // r29
  varEval_t *v798; // r3
  double v799; // fp0
  _DWORD *v800; // r28
  varEval_t *v801; // r3
  idVarDef *v802; // r5
  float *v803; // r29
  varEval_t *v804; // r3
  double v805; // fp0
  varEval_t::<unnamed_type_value> v806; // r26
  float *v807; // r28
  _DWORD *v808; // r27
  bfx::SystemInstance *v809; // r3
  unsigned int v810; // r29
  const bfx::Vec3 *CachedSize; // r3
  double v812; // fp0
  const bfx::Vec3 *v813; // r3
  double v814; // fp0
  varEval_t::<unnamed_type_value> v815; // r26
  _DWORD *v816; // r28
  _DWORD *v817; // r27
  bfx::SystemInstance *v818; // r3
  int v819; // r29
  const bfx::Vec3 *v820; // r3
  int v822; // [sp+B0h] [-2988h]
  int v823; // [sp+B4h] [-2984h]
  int v824; // [sp+B8h] [-2980h]
  int v825; // [sp+BCh] [-297Ch]
  int v826; // [sp+C0h] [-2978h]
  int v827; // [sp+C4h] [-2974h]
  varEval_t v828; // [sp+118h] [-2920h] BYREF
  int v829; // [sp+11Ch] [-291Ch]
  varEval_t v830; // [sp+120h] [-2918h] BYREF
  int v831; // [sp+124h] [-2914h]
  const char *v832; // [sp+128h] [-2910h]
  int v833; // [sp+12Ch] [-290Ch]
  varEval_t v834; // [sp+130h] [-2908h] BYREF
  varEval_t v835; // [sp+134h] [-2904h] BYREF
  varEval_t v836; // [sp+138h] [-2900h] BYREF
  varEval_t v837; // [sp+13Ch] [-28FCh] BYREF
  varEval_t v838; // [sp+140h] [-28F8h] BYREF
  varEval_t v839; // [sp+144h] [-28F4h] BYREF
  varEval_t v840; // [sp+148h] [-28F0h] BYREF
  varEval_t v841; // [sp+14Ch] [-28ECh] BYREF
  varEval_t v842; // [sp+150h] [-28E8h] BYREF
  varEval_t v843; // [sp+154h] [-28E4h] BYREF
  varEval_t v844; // [sp+158h] [-28E0h] BYREF
  varEval_t v845; // [sp+15Ch] [-28DCh] BYREF
  varEval_t v846; // [sp+160h] [-28D8h] BYREF
  varEval_t v847; // [sp+164h] [-28D4h] BYREF
  varEval_t v848; // [sp+168h] [-28D0h] BYREF
  varEval_t v849; // [sp+16Ch] [-28CCh] BYREF
  varEval_t v850; // [sp+170h] [-28C8h] BYREF
  varEval_t v851; // [sp+174h] [-28C4h] BYREF
  varEval_t v852; // [sp+178h] [-28C0h] BYREF
  varEval_t v853; // [sp+17Ch] [-28BCh] BYREF
  varEval_t v854; // [sp+180h] [-28B8h] BYREF
  varEval_t v855; // [sp+184h] [-28B4h] BYREF
  varEval_t v856; // [sp+188h] [-28B0h] BYREF
  varEval_t v857; // [sp+18Ch] [-28ACh] BYREF
  varEval_t v858; // [sp+190h] [-28A8h] BYREF
  varEval_t v859; // [sp+194h] [-28A4h] BYREF
  varEval_t v860; // [sp+198h] [-28A0h] BYREF
  varEval_t v861; // [sp+19Ch] [-289Ch] BYREF
  varEval_t v862; // [sp+1A0h] [-2898h] BYREF
  varEval_t v863; // [sp+1A4h] [-2894h] BYREF
  varEval_t v864; // [sp+1A8h] [-2890h] BYREF
  varEval_t v865; // [sp+1ACh] [-288Ch] BYREF
  varEval_t v866; // [sp+1B0h] [-2888h] BYREF
  varEval_t v867; // [sp+1B4h] [-2884h] BYREF
  varEval_t v868; // [sp+1B8h] [-2880h] BYREF
  varEval_t v869; // [sp+1BCh] [-287Ch] BYREF
  varEval_t v870; // [sp+1C0h] [-2878h] BYREF
  varEval_t v871; // [sp+1C4h] [-2874h] BYREF
  varEval_t v872; // [sp+1C8h] [-2870h] BYREF
  varEval_t v873; // [sp+1CCh] [-286Ch] BYREF
  varEval_t v874; // [sp+1D0h] [-2868h] BYREF
  varEval_t v875; // [sp+1D4h] [-2864h] BYREF
  varEval_t v876; // [sp+1D8h] [-2860h] BYREF
  varEval_t v877; // [sp+1DCh] [-285Ch] BYREF
  varEval_t v878; // [sp+1E0h] [-2858h] BYREF
  varEval_t v879; // [sp+1E4h] [-2854h] BYREF
  varEval_t v880; // [sp+1E8h] [-2850h] BYREF
  varEval_t v881; // [sp+1ECh] [-284Ch] BYREF
  varEval_t v882; // [sp+1F0h] [-2848h] BYREF
  varEval_t v883; // [sp+1F4h] [-2844h] BYREF
  varEval_t v884; // [sp+1F8h] [-2840h] BYREF
  varEval_t v885; // [sp+1FCh] [-283Ch] BYREF
  varEval_t v886; // [sp+200h] [-2838h] BYREF
  varEval_t v887; // [sp+204h] [-2834h] BYREF
  varEval_t v888; // [sp+208h] [-2830h] BYREF
  varEval_t v889; // [sp+20Ch] [-282Ch] BYREF
  varEval_t v890; // [sp+210h] [-2828h] BYREF
  varEval_t v891; // [sp+214h] [-2824h] BYREF
  varEval_t v892; // [sp+218h] [-2820h] BYREF
  varEval_t v893; // [sp+21Ch] [-281Ch] BYREF
  varEval_t v894; // [sp+220h] [-2818h] BYREF
  varEval_t v895; // [sp+224h] [-2814h] BYREF
  varEval_t v896; // [sp+228h] [-2810h] BYREF
  varEval_t v897; // [sp+22Ch] [-280Ch] BYREF
  varEval_t v898; // [sp+230h] [-2808h] BYREF
  varEval_t v899; // [sp+234h] [-2804h] BYREF
  varEval_t v900; // [sp+238h] [-2800h] BYREF
  varEval_t v901; // [sp+23Ch] [-27FCh] BYREF
  varEval_t v902; // [sp+240h] [-27F8h] BYREF
  varEval_t v903; // [sp+244h] [-27F4h] BYREF
  varEval_t v904; // [sp+248h] [-27F0h] BYREF
  varEval_t v905; // [sp+24Ch] [-27ECh] BYREF
  varEval_t v906; // [sp+250h] [-27E8h] BYREF
  varEval_t v907; // [sp+254h] [-27E4h] BYREF
  varEval_t v908; // [sp+258h] [-27E0h] BYREF
  varEval_t v909; // [sp+25Ch] [-27DCh] BYREF
  varEval_t v910; // [sp+260h] [-27D8h] BYREF
  varEval_t v911; // [sp+264h] [-27D4h] BYREF
  varEval_t v912; // [sp+268h] [-27D0h] BYREF
  varEval_t v913; // [sp+26Ch] [-27CCh] BYREF
  varEval_t v914; // [sp+270h] [-27C8h] BYREF
  varEval_t v915; // [sp+274h] [-27C4h] BYREF
  varEval_t v916; // [sp+278h] [-27C0h] BYREF
  varEval_t v917; // [sp+27Ch] [-27BCh] BYREF
  varEval_t v918; // [sp+280h] [-27B8h] BYREF
  varEval_t v919; // [sp+284h] [-27B4h] BYREF
  varEval_t v920; // [sp+288h] [-27B0h] BYREF
  varEval_t v921; // [sp+28Ch] [-27ACh] BYREF
  varEval_t v922; // [sp+290h] [-27A8h] BYREF
  varEval_t v923; // [sp+294h] [-27A4h] BYREF
  varEval_t v924; // [sp+298h] [-27A0h] BYREF
  varEval_t v925; // [sp+29Ch] [-279Ch] BYREF
  varEval_t v926; // [sp+2A0h] [-2798h] BYREF
  varEval_t v927; // [sp+2A4h] [-2794h] BYREF
  varEval_t v928; // [sp+2A8h] [-2790h] BYREF
  varEval_t v929; // [sp+2ACh] [-278Ch] BYREF
  varEval_t v930; // [sp+2B0h] [-2788h] BYREF
  varEval_t v931; // [sp+2B4h] [-2784h] BYREF
  varEval_t v932; // [sp+2B8h] [-2780h] BYREF
  varEval_t v933; // [sp+2BCh] [-277Ch] BYREF
  varEval_t v934; // [sp+2C0h] [-2778h] BYREF
  varEval_t v935; // [sp+2C4h] [-2774h] BYREF
  varEval_t v936; // [sp+2C8h] [-2770h] BYREF
  varEval_t v937; // [sp+2CCh] [-276Ch] BYREF
  varEval_t v938; // [sp+2D0h] [-2768h] BYREF
  varEval_t v939; // [sp+2D4h] [-2764h] BYREF
  varEval_t v940; // [sp+2D8h] [-2760h] BYREF
  varEval_t v941; // [sp+2DCh] [-275Ch] BYREF
  varEval_t v942; // [sp+2E0h] [-2758h] BYREF
  varEval_t v943; // [sp+2E4h] [-2754h] BYREF
  varEval_t v944; // [sp+2E8h] [-2750h] BYREF
  varEval_t v945; // [sp+2ECh] [-274Ch] BYREF
  varEval_t v946; // [sp+2F0h] [-2748h] BYREF
  varEval_t v947; // [sp+2F4h] [-2744h] BYREF
  varEval_t v948; // [sp+2F8h] [-2740h] BYREF
  varEval_t v949; // [sp+2FCh] [-273Ch] BYREF
  varEval_t v950; // [sp+300h] [-2738h] BYREF
  varEval_t v951; // [sp+304h] [-2734h] BYREF
  varEval_t v952; // [sp+308h] [-2730h] BYREF
  varEval_t v953; // [sp+30Ch] [-272Ch] BYREF
  varEval_t v954; // [sp+310h] [-2728h] BYREF
  varEval_t v955; // [sp+314h] [-2724h] BYREF
  varEval_t v956; // [sp+318h] [-2720h] BYREF
  varEval_t v957; // [sp+31Ch] [-271Ch] BYREF
  varEval_t v958; // [sp+320h] [-2718h] BYREF
  varEval_t v959; // [sp+324h] [-2714h] BYREF
  varEval_t v960; // [sp+328h] [-2710h] BYREF
  varEval_t v961; // [sp+32Ch] [-270Ch] BYREF
  varEval_t v962; // [sp+330h] [-2708h] BYREF
  varEval_t v963; // [sp+334h] [-2704h] BYREF
  varEval_t v964; // [sp+338h] [-2700h] BYREF
  varEval_t v965; // [sp+33Ch] [-26FCh] BYREF
  varEval_t v966; // [sp+340h] [-26F8h] BYREF
  varEval_t v967; // [sp+344h] [-26F4h] BYREF
  varEval_t v968; // [sp+348h] [-26F0h] BYREF
  varEval_t v969; // [sp+34Ch] [-26ECh] BYREF
  varEval_t v970; // [sp+350h] [-26E8h] BYREF
  varEval_t v971; // [sp+354h] [-26E4h] BYREF
  varEval_t v972; // [sp+358h] [-26E0h] BYREF
  varEval_t v973; // [sp+35Ch] [-26DCh] BYREF
  varEval_t v974; // [sp+360h] [-26D8h] BYREF
  varEval_t v975; // [sp+364h] [-26D4h] BYREF
  varEval_t v976; // [sp+368h] [-26D0h] BYREF
  varEval_t v977; // [sp+36Ch] [-26CCh] BYREF
  varEval_t v978; // [sp+370h] [-26C8h] BYREF
  varEval_t v979; // [sp+374h] [-26C4h] BYREF
  varEval_t v980; // [sp+378h] [-26C0h] BYREF
  varEval_t v981; // [sp+37Ch] [-26BCh] BYREF
  varEval_t v982; // [sp+380h] [-26B8h] BYREF
  varEval_t v983; // [sp+384h] [-26B4h] BYREF
  varEval_t v984; // [sp+388h] [-26B0h] BYREF
  varEval_t v985; // [sp+38Ch] [-26ACh] BYREF
  varEval_t v986; // [sp+390h] [-26A8h] BYREF
  varEval_t v987; // [sp+394h] [-26A4h] BYREF
  varEval_t v988; // [sp+398h] [-26A0h] BYREF
  varEval_t v989; // [sp+39Ch] [-269Ch] BYREF
  varEval_t v990; // [sp+3A0h] [-2698h] BYREF
  varEval_t v991; // [sp+3A4h] [-2694h] BYREF
  varEval_t v992; // [sp+3A8h] [-2690h] BYREF
  varEval_t v993; // [sp+3ACh] [-268Ch] BYREF
  varEval_t v994; // [sp+3B0h] [-2688h] BYREF
  varEval_t v995; // [sp+3B4h] [-2684h] BYREF
  varEval_t v996; // [sp+3B8h] [-2680h] BYREF
  varEval_t v997; // [sp+3BCh] [-267Ch] BYREF
  varEval_t v998; // [sp+3C0h] [-2678h] BYREF
  varEval_t v999; // [sp+3C4h] [-2674h] BYREF
  varEval_t v1000; // [sp+3C8h] [-2670h] BYREF
  varEval_t v1001; // [sp+3CCh] [-266Ch] BYREF
  varEval_t v1002; // [sp+3D0h] [-2668h] BYREF
  varEval_t v1003; // [sp+3D4h] [-2664h] BYREF
  varEval_t v1004; // [sp+3D8h] [-2660h] BYREF
  varEval_t v1005; // [sp+3DCh] [-265Ch] BYREF
  varEval_t v1006; // [sp+3E0h] [-2658h] BYREF
  varEval_t v1007; // [sp+3E4h] [-2654h] BYREF
  varEval_t v1008; // [sp+3E8h] [-2650h] BYREF
  varEval_t v1009; // [sp+3ECh] [-264Ch] BYREF
  varEval_t v1010; // [sp+3F0h] [-2648h] BYREF
  varEval_t v1011; // [sp+3F4h] [-2644h] BYREF
  varEval_t v1012; // [sp+3F8h] [-2640h] BYREF
  varEval_t v1013; // [sp+3FCh] [-263Ch] BYREF
  varEval_t v1014; // [sp+400h] [-2638h] BYREF
  varEval_t v1015; // [sp+404h] [-2634h] BYREF
  varEval_t v1016; // [sp+408h] [-2630h] BYREF
  varEval_t v1017; // [sp+40Ch] [-262Ch] BYREF
  varEval_t v1018; // [sp+410h] [-2628h] BYREF
  varEval_t v1019; // [sp+414h] [-2624h] BYREF
  varEval_t v1020; // [sp+418h] [-2620h] BYREF
  varEval_t v1021; // [sp+41Ch] [-261Ch] BYREF
  varEval_t v1022; // [sp+420h] [-2618h] BYREF
  varEval_t v1023; // [sp+424h] [-2614h] BYREF
  varEval_t v1024; // [sp+428h] [-2610h] BYREF
  varEval_t v1025; // [sp+42Ch] [-260Ch] BYREF
  varEval_t v1026; // [sp+430h] [-2608h] BYREF
  varEval_t v1027; // [sp+434h] [-2604h] BYREF
  varEval_t v1028; // [sp+438h] [-2600h] BYREF
  varEval_t v1029; // [sp+43Ch] [-25FCh] BYREF
  varEval_t v1030; // [sp+440h] [-25F8h] BYREF
  varEval_t v1031; // [sp+444h] [-25F4h] BYREF
  varEval_t v1032; // [sp+448h] [-25F0h] BYREF
  varEval_t v1033; // [sp+44Ch] [-25ECh] BYREF
  varEval_t v1034; // [sp+450h] [-25E8h] BYREF
  varEval_t v1035; // [sp+454h] [-25E4h] BYREF
  varEval_t v1036; // [sp+458h] [-25E0h] BYREF
  varEval_t v1037; // [sp+45Ch] [-25DCh] BYREF
  varEval_t v1038; // [sp+460h] [-25D8h] BYREF
  varEval_t v1039; // [sp+464h] [-25D4h] BYREF
  varEval_t v1040; // [sp+468h] [-25D0h] BYREF
  varEval_t v1041; // [sp+46Ch] [-25CCh] BYREF
  varEval_t v1042; // [sp+470h] [-25C8h] BYREF
  varEval_t v1043; // [sp+474h] [-25C4h] BYREF
  varEval_t v1044; // [sp+478h] [-25C0h] BYREF
  varEval_t v1045; // [sp+47Ch] [-25BCh] BYREF
  varEval_t v1046; // [sp+480h] [-25B8h] BYREF
  varEval_t v1047; // [sp+484h] [-25B4h] BYREF
  varEval_t v1048; // [sp+488h] [-25B0h] BYREF
  varEval_t v1049; // [sp+48Ch] [-25ACh] BYREF
  varEval_t v1050; // [sp+490h] [-25A8h] BYREF
  varEval_t v1051; // [sp+494h] [-25A4h] BYREF
  varEval_t v1052; // [sp+498h] [-25A0h] BYREF
  varEval_t v1053; // [sp+49Ch] [-259Ch] BYREF
  varEval_t v1054; // [sp+4A0h] [-2598h] BYREF
  varEval_t v1055; // [sp+4A4h] [-2594h] BYREF
  varEval_t v1056; // [sp+4A8h] [-2590h] BYREF
  varEval_t v1057; // [sp+4ACh] [-258Ch] BYREF
  varEval_t v1058; // [sp+4B0h] [-2588h] BYREF
  varEval_t v1059; // [sp+4B4h] [-2584h] BYREF
  varEval_t v1060; // [sp+4B8h] [-2580h] BYREF
  varEval_t v1061; // [sp+4BCh] [-257Ch] BYREF
  varEval_t v1062; // [sp+4C0h] [-2578h] BYREF
  varEval_t v1063; // [sp+4C4h] [-2574h] BYREF
  varEval_t v1064; // [sp+4C8h] [-2570h] BYREF
  varEval_t v1065; // [sp+4CCh] [-256Ch] BYREF
  varEval_t v1066; // [sp+4D0h] [-2568h] BYREF
  varEval_t v1067; // [sp+4D4h] [-2564h] BYREF
  varEval_t v1068; // [sp+4D8h] [-2560h] BYREF
  varEval_t v1069; // [sp+4DCh] [-255Ch] BYREF
  varEval_t v1070; // [sp+4E0h] [-2558h] BYREF
  varEval_t v1071; // [sp+4E4h] [-2554h] BYREF
  varEval_t v1072; // [sp+4E8h] [-2550h] BYREF
  varEval_t v1073; // [sp+4ECh] [-254Ch] BYREF
  varEval_t v1074; // [sp+4F0h] [-2548h] BYREF
  varEval_t v1075; // [sp+4F4h] [-2544h] BYREF
  varEval_t v1076; // [sp+4F8h] [-2540h] BYREF
  varEval_t v1077; // [sp+4FCh] [-253Ch] BYREF
  varEval_t v1078; // [sp+500h] [-2538h] BYREF
  varEval_t v1079; // [sp+504h] [-2534h] BYREF
  varEval_t v1080; // [sp+508h] [-2530h] BYREF
  varEval_t v1081; // [sp+50Ch] [-252Ch] BYREF
  varEval_t v1082; // [sp+510h] [-2528h] BYREF
  varEval_t v1083; // [sp+514h] [-2524h] BYREF
  varEval_t v1084; // [sp+518h] [-2520h] BYREF
  varEval_t v1085; // [sp+51Ch] [-251Ch] BYREF
  varEval_t v1086; // [sp+520h] [-2518h] BYREF
  varEval_t v1087; // [sp+524h] [-2514h] BYREF
  varEval_t v1088; // [sp+528h] [-2510h] BYREF
  varEval_t v1089; // [sp+52Ch] [-250Ch] BYREF
  varEval_t v1090; // [sp+530h] [-2508h] BYREF
  varEval_t v1091; // [sp+534h] [-2504h] BYREF
  varEval_t v1092; // [sp+538h] [-2500h] BYREF
  varEval_t v1093; // [sp+53Ch] [-24FCh] BYREF
  varEval_t v1094; // [sp+540h] [-24F8h] BYREF
  varEval_t v1095; // [sp+544h] [-24F4h] BYREF
  varEval_t v1096; // [sp+548h] [-24F0h] BYREF
  varEval_t v1097; // [sp+54Ch] [-24ECh] BYREF
  varEval_t v1098; // [sp+550h] [-24E8h] BYREF
  varEval_t v1099; // [sp+554h] [-24E4h] BYREF
  varEval_t v1100; // [sp+558h] [-24E0h] BYREF
  varEval_t v1101; // [sp+55Ch] [-24DCh] BYREF
  varEval_t v1102; // [sp+560h] [-24D8h] BYREF
  varEval_t v1103; // [sp+564h] [-24D4h] BYREF
  varEval_t v1104; // [sp+568h] [-24D0h] BYREF
  varEval_t v1105; // [sp+56Ch] [-24CCh] BYREF
  varEval_t v1106; // [sp+570h] [-24C8h] BYREF
  varEval_t v1107; // [sp+574h] [-24C4h] BYREF
  varEval_t v1108; // [sp+578h] [-24C0h] BYREF
  varEval_t v1109; // [sp+57Ch] [-24BCh] BYREF
  varEval_t v1110; // [sp+580h] [-24B8h] BYREF
  varEval_t v1111; // [sp+584h] [-24B4h] BYREF
  varEval_t v1112; // [sp+588h] [-24B0h] BYREF
  varEval_t v1113; // [sp+58Ch] [-24ACh] BYREF
  varEval_t v1114; // [sp+590h] [-24A8h] BYREF
  varEval_t v1115; // [sp+594h] [-24A4h] BYREF
  varEval_t v1116; // [sp+598h] [-24A0h] BYREF
  varEval_t v1117; // [sp+59Ch] [-249Ch] BYREF
  varEval_t v1118; // [sp+5A0h] [-2498h] BYREF
  varEval_t v1119; // [sp+5A4h] [-2494h] BYREF
  varEval_t v1120; // [sp+5A8h] [-2490h] BYREF
  varEval_t v1121; // [sp+5ACh] [-248Ch] BYREF
  varEval_t v1122; // [sp+5B0h] [-2488h] BYREF
  varEval_t v1123; // [sp+5B4h] [-2484h] BYREF
  varEval_t v1124; // [sp+5B8h] [-2480h] BYREF
  varEval_t v1125; // [sp+5BCh] [-247Ch] BYREF
  varEval_t v1126; // [sp+5C0h] [-2478h] BYREF
  varEval_t v1127; // [sp+5C4h] [-2474h] BYREF
  varEval_t v1128; // [sp+5C8h] [-2470h] BYREF
  varEval_t v1129; // [sp+5CCh] [-246Ch] BYREF
  varEval_t v1130; // [sp+5D0h] [-2468h] BYREF
  varEval_t v1131; // [sp+5D4h] [-2464h] BYREF
  varEval_t v1132; // [sp+5D8h] [-2460h] BYREF
  varEval_t v1133; // [sp+5DCh] [-245Ch] BYREF
  varEval_t v1134; // [sp+5E0h] [-2458h] BYREF
  varEval_t v1135; // [sp+5E4h] [-2454h] BYREF
  varEval_t v1136; // [sp+5E8h] [-2450h] BYREF
  varEval_t v1137; // [sp+5ECh] [-244Ch] BYREF
  varEval_t v1138; // [sp+5F0h] [-2448h] BYREF
  varEval_t v1139; // [sp+5F4h] [-2444h] BYREF
  varEval_t v1140; // [sp+5F8h] [-2440h] BYREF
  varEval_t v1141; // [sp+5FCh] [-243Ch] BYREF
  varEval_t v1142; // [sp+600h] [-2438h] BYREF
  varEval_t v1143; // [sp+604h] [-2434h] BYREF
  varEval_t v1144; // [sp+608h] [-2430h] BYREF
  varEval_t v1145; // [sp+60Ch] [-242Ch] BYREF
  varEval_t v1146; // [sp+610h] [-2428h] BYREF
  varEval_t v1147; // [sp+614h] [-2424h] BYREF
  varEval_t v1148; // [sp+618h] [-2420h] BYREF
  varEval_t v1149; // [sp+61Ch] [-241Ch] BYREF
  varEval_t v1150; // [sp+620h] [-2418h] BYREF
  varEval_t v1151; // [sp+624h] [-2414h] BYREF
  varEval_t v1152; // [sp+628h] [-2410h] BYREF
  varEval_t v1153; // [sp+62Ch] [-240Ch] BYREF
  varEval_t v1154; // [sp+630h] [-2408h] BYREF
  varEval_t v1155; // [sp+634h] [-2404h] BYREF
  varEval_t v1156; // [sp+638h] [-2400h] BYREF
  varEval_t v1157; // [sp+63Ch] [-23FCh] BYREF
  varEval_t v1158; // [sp+640h] [-23F8h] BYREF
  varEval_t v1159; // [sp+644h] [-23F4h] BYREF
  varEval_t v1160; // [sp+648h] [-23F0h] BYREF
  varEval_t v1161; // [sp+64Ch] [-23ECh] BYREF
  varEval_t v1162; // [sp+650h] [-23E8h] BYREF
  __int64 v1163; // [sp+658h] [-23E0h]
  varEval_t v1164; // [sp+660h] [-23D8h] BYREF
  __int64 v1165; // [sp+668h] [-23D0h]
  varEval_t v1166; // [sp+670h] [-23C8h] BYREF
  __int64 v1167; // [sp+678h] [-23C0h]
  varEval_t v1168; // [sp+680h] [-23B8h] BYREF
  __int64 v1169; // [sp+688h] [-23B0h]
  varEval_t v1170; // [sp+690h] [-23A8h] BYREF
  __int64 v1171; // [sp+698h] [-23A0h]
  varEval_t v1172; // [sp+6A0h] [-2398h] BYREF
  __int64 v1173; // [sp+6A8h] [-2390h]
  varEval_t v1174; // [sp+6B0h] [-2388h] BYREF
  __int64 v1175; // [sp+6B8h] [-2380h]
  varEval_t v1176; // [sp+6C0h] [-2378h] BYREF
  __int64 v1177; // [sp+6C8h] [-2370h]
  varEval_t v1178; // [sp+6D0h] [-2368h] BYREF
  __int64 v1179; // [sp+6D8h] [-2360h]
  varEval_t v1180; // [sp+6E0h] [-2358h] BYREF
  __int64 v1181; // [sp+6E8h] [-2350h]
  varEval_t v1182; // [sp+6F0h] [-2348h] BYREF
  __int64 v1183; // [sp+6F8h] [-2340h]
  varEval_t v1184; // [sp+700h] [-2338h] BYREF
  __int64 v1185; // [sp+708h] [-2330h]
  varEval_t v1186; // [sp+710h] [-2328h] BYREF
  __int64 v1187; // [sp+718h] [-2320h]
  varEval_t v1188; // [sp+720h] [-2318h] BYREF
  __int64 v1189; // [sp+728h] [-2310h]
  varEval_t v1190; // [sp+730h] [-2308h] BYREF
  __int64 v1191; // [sp+738h] [-2300h]
  varEval_t v1192; // [sp+740h] [-22F8h] BYREF
  __int64 v1193; // [sp+748h] [-22F0h]
  varEval_t v1194; // [sp+750h] [-22E8h] BYREF
  __int64 v1195; // [sp+758h] [-22E0h]
  varEval_t v1196; // [sp+760h] [-22D8h] BYREF
  __int64 v1197; // [sp+768h] [-22D0h]
  varEval_t v1198; // [sp+770h] [-22C8h] BYREF
  __int64 v1199; // [sp+778h] [-22C0h]
  varEval_t v1200; // [sp+780h] [-22B8h] BYREF
  __int64 v1201; // [sp+788h] [-22B0h]
  varEval_t v1202; // [sp+790h] [-22A8h] BYREF
  __int64 v1203; // [sp+798h] [-22A0h]
  varEval_t v1204; // [sp+7A0h] [-2298h] BYREF
  __int64 v1205; // [sp+7A8h] [-2290h]
  varEval_t v1206; // [sp+7B0h] [-2288h] BYREF
  __int64 v1207; // [sp+7B8h] [-2280h]
  varEval_t v1208; // [sp+7C0h] [-2278h] BYREF
  __int64 v1209; // [sp+7C8h] [-2270h]
  varEval_t v1210; // [sp+7D0h] [-2268h] BYREF
  __int64 v1211; // [sp+7D8h] [-2260h]
  varEval_t v1212; // [sp+7E0h] [-2258h] BYREF
  __int64 v1213; // [sp+7E8h] [-2250h]
  varEval_t v1214; // [sp+7F0h] [-2248h] BYREF
  __int64 v1215; // [sp+7F8h] [-2240h]
  varEval_t v1216; // [sp+800h] [-2238h] BYREF
  __int64 v1217; // [sp+808h] [-2230h]
  varEval_t v1218; // [sp+810h] [-2228h] BYREF
  __int64 v1219; // [sp+818h] [-2220h]
  varEval_t v1220; // [sp+820h] [-2218h] BYREF
  __int64 v1221; // [sp+828h] [-2210h]
  varEval_t v1222; // [sp+830h] [-2208h] BYREF
  __int64 v1223; // [sp+838h] [-2200h]
  varEval_t v1224; // [sp+840h] [-21F8h] BYREF
  __int64 v1225; // [sp+848h] [-21F0h]
  varEval_t v1226; // [sp+850h] [-21E8h] BYREF
  __int64 v1227; // [sp+858h] [-21E0h]
  varEval_t v1228; // [sp+860h] [-21D8h] BYREF
  __int64 v1229; // [sp+868h] [-21D0h]
  varEval_t v1230; // [sp+870h] [-21C8h] BYREF
  __int64 v1231; // [sp+878h] [-21C0h]
  varEval_t v1232; // [sp+880h] [-21B8h] BYREF
  __int64 v1233; // [sp+888h] [-21B0h]
  varEval_t v1234; // [sp+890h] [-21A8h] BYREF
  __int64 v1235; // [sp+898h] [-21A0h]
  varEval_t v1236; // [sp+8A0h] [-2198h] BYREF
  __int64 v1237; // [sp+8A8h] [-2190h]
  varEval_t v1238; // [sp+8B0h] [-2188h] BYREF
  __int64 v1239; // [sp+8B8h] [-2180h]
  varEval_t v1240; // [sp+8C0h] [-2178h] BYREF
  __int64 v1241; // [sp+8C8h] [-2170h]
  varEval_t v1242; // [sp+8D0h] [-2168h] BYREF
  __int64 v1243; // [sp+8D8h] [-2160h]
  varEval_t v1244; // [sp+8E0h] [-2158h] BYREF
  __int64 v1245; // [sp+8E8h] [-2150h]
  varEval_t v1246; // [sp+8F0h] [-2148h] BYREF
  __int64 v1247; // [sp+8F8h] [-2140h]
  varEval_t v1248; // [sp+900h] [-2138h] BYREF
  __int64 v1249; // [sp+908h] [-2130h]
  varEval_t v1250; // [sp+910h] [-2128h] BYREF
  __int64 v1251; // [sp+918h] [-2120h]
  varEval_t v1252; // [sp+920h] [-2118h] BYREF
  __int64 v1253; // [sp+928h] [-2110h]
  varEval_t v1254; // [sp+930h] [-2108h] BYREF
  __int64 v1255; // [sp+938h] [-2100h]
  varEval_t v1256; // [sp+940h] [-20F8h] BYREF
  unsigned __int64 v1257; // [sp+948h] [-20F0h]
  varEval_t v1258; // [sp+950h] [-20E8h] BYREF
  __int64 v1259; // [sp+958h] [-20E0h]
  varEval_t v1260; // [sp+960h] [-20D8h] BYREF
  unsigned __int64 v1261; // [sp+968h] [-20D0h]
  varEval_t v1262; // [sp+970h] [-20C8h] BYREF
  __int64 v1263; // [sp+978h] [-20C0h]
  varEval_t v1264; // [sp+980h] [-20B8h] BYREF
  varEval_t v1265; // [sp+984h] [-20B4h] BYREF
  va v1266; // [sp+988h] [-20B0h] BYREF
  va v1267; // [sp+1988h] [-10B0h] BYREF

  if ( !this->threadDying && this->localstack.currentFunction != nullptr )
  {
    if ( this->multiFrameEvent != nullptr )
      --this->localstack.instructionPointer;
    this->doneProcessing = false;
    LODWORD(v2) = 0x82000000;
    HIDWORD(v2) = &unk_82360000;
    LODWORD(v3) = off_82010000;
    HIDWORD(v3) = allocationCurrent[242];
    *(_DWORD *)v4 = "<RESULT>";
    v5 = 5000000;
    v832 = "<RESULT>";
    while ( 1 )
    {
      if ( this->threadDying )
        return this->threadDying;
      v6 = v5 - 1;
      *(_DWORD *)&v4[4] = this->localstack.instructionPointer + 1;
      v833 = v5 - 1;
      this->localstack.instructionPointer = *(_DWORD *)&v4[4];
      if ( v5 == 1 )
        break;
      *(_DWORD *)v4 = 16 * *(_DWORD *)&v4[4];
      HIDWORD(v2) = 531104;
      LODWORD(v2) = gameLocal->program.statements.list;
      v7 = v2 + 16 * *(_DWORD *)&v4[4];
      HIDWORD(v3) = *(unsigned __int8 *)(v7 + 12);
      switch ( *(_BYTE *)(v7 + 12) )
      {
        case 0:
          idInterpreter::LeaveFunction(this, returnDef: *(idVarDef **)v7, a3: v3, a4: v2, a5: *(__int64 *)v4);
          goto LABEL_437;
        case 1:
          Variable = idInterpreter::GetVariable(retstr: &v925, this, def: *(idVarDef **)v7);
          *Variable->value.fp = *Variable->value.fp + (float)1.0;
          goto LABEL_437;
        case 2:
          v573 = idInterpreter::GetVariable(retstr: &v927, this, def: *(idVarDef **)v7);
          *(_DWORD *)v4 = *v573->value.ip + 1;
          *v573->value.ip = *(_DWORD *)v4;
          goto LABEL_437;
        case 3:
          ScriptObject = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( ScriptObject != nullptr )
            *(float *)((char *)ScriptObject->m_graphs.m_data + *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4)) = *(float *)((char *)ScriptObject->m_graphs.m_data + *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4)) + (float)1.0;
          goto LABEL_437;
        case 4:
          v574 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( v574 != nullptr )
          {
            *(_DWORD *)&v4[8] = v574->m_graphs.m_data;
            *(_DWORD *)&v4[4] = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4);
            *(_DWORD *)v4 = *(_DWORD *)(*(_DWORD *)&v4[4] + *(_DWORD *)&v4[8]) + 1;
            *(_DWORD *)(*(_DWORD *)&v4[4] + *(_DWORD *)&v4[8]) = *(_DWORD *)v4;
          }
          goto LABEL_437;
        case 5:
          v575 = idInterpreter::GetVariable(retstr: &v929, this, def: *(idVarDef **)v7);
          *v575->value.fp = *v575->value.fp - (float)1.0;
          goto LABEL_437;
        case 6:
          v577 = idInterpreter::GetVariable(retstr: &v931, this, def: *(idVarDef **)v7);
          *(_DWORD *)v4 = *v577->value.ip - 1;
          *v577->value.ip = *(_DWORD *)v4;
          goto LABEL_437;
        case 7:
          v576 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( v576 != nullptr )
            *(float *)((char *)v576->m_graphs.m_data + *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4)) = *(float *)((char *)v576->m_graphs.m_data + *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4))
                                                                                             - (float)1.0;
          goto LABEL_437;
        case 8:
          v578 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( v578 != nullptr )
          {
            *(_DWORD *)&v4[8] = v578->m_graphs.m_data;
            *(_DWORD *)&v4[4] = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4);
            *(_DWORD *)v4 = *(_DWORD *)(*(_DWORD *)&v4[4] + *(_DWORD *)&v4[8]) - 1;
            *(_DWORD *)(*(_DWORD *)&v4[4] + *(_DWORD *)&v4[8]) = *(_DWORD *)v4;
          }
          goto LABEL_437;
        case 9:
          v579 = idInterpreter::GetVariable(retstr: &v933, this, def: *(idVarDef **)v7);
          v580 = *(idVarDef **)(v7 + 8);
          i = (float *)v579->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v935, this, def: v580)->value.cp;
          v829 = (int)*i;
          *(_DWORD *)v4 = v829;
          LODWORD(v2) = ~v829;
          HIDWORD(v2) = ~v829;
          v1231 = *(__int64 *)((char *)&v2 + 4);
          **(float **)&v4[4] = (float)*(__int64 *)((char *)&v2 + 4);
          goto LABEL_437;
        case 0xA:
          v582 = idInterpreter::GetVariable(retstr: &v937, this, def: *(idVarDef **)v7);
          v583 = *(idVarDef **)(v7 + 8);
          v584 = (_DWORD *)v582->value.i;
          v585 = idInterpreter::GetVariable(retstr: &v939, this, def: v583);
          *(varEval_t *)v4 = (varEval_t)v585->value.cp;
          LODWORD(v2) = ~*v584;
          *v585->value.ip = v2;
          goto LABEL_437;
        case 0xB:
          v158 = (float *)idInterpreter::GetVariable(retstr: &v890, this, def: *(idVarDef **)v7)->value.i;
          v159 = idInterpreter::GetVariable(retstr: &v1220, this, def: *(idVarDef **)(v7 + 4));
          v160 = *(idVarDef **)(v7 + 8);
          v161 = (float *)v159->value.i;
          v165 = idInterpreter::GetVariable(retstr: &v892, this, def: v160);
          *((double *)&v167 + 1) = *v161;
          v168 = (float *)v165->value.i;
          if ( *((double *)&v167 + 1) == 0.0 )
            goto LABEL_260;
          *(double *)&v167 = *v158;
          *(float *)&v828.value.cp = *((double *)&v167 + 1);
          v169 = fmod(dX: v167, dY: v166);
          *v168 = *(double *)&v169;
          goto LABEL_437;
        case 0xC:
          v158 = (float *)idInterpreter::GetVariable(retstr: &v1080, this, def: *(idVarDef **)v7)->value.i;
          v170 = idInterpreter::GetVariable(retstr: &v894, this, def: *(idVarDef **)(v7 + 4));
          v171 = *(idVarDef **)(v7 + 8);
          v172 = (signed int *)v170->value.i;
          v173 = idInterpreter::GetVariable(retstr: &v1174, this, def: v171);
          v174 = *v172;
          v157 = *v172 != 0;
          v168 = (float *)v173->value.i;
          if ( !v157 )
            goto LABEL_260;
          *(float *)v4 = *v158;
          __twllei(v174, 0);
          LODWORD(v2) = *(_DWORD *)v4 / v174;
          HIDWORD(v2) = *(_DWORD *)v4 / v174 * v174;
          LODWORD(v3) = __ROL4__(*(_DWORD *)v4, 1) - 1;
          HIDWORD(v3) = *(_DWORD *)v4 % v174;
          *(_DWORD *)v168 = *(_DWORD *)v4 % v174;
          __twlgei(v174 & ~(_DWORD)v3, 0xFFFFFFFF);
          goto LABEL_437;
        case 0xD:
          v98 = (float *)idInterpreter::GetVariable(retstr: &v1166, this, def: *(idVarDef **)v7)->value.i;
          v99 = idInterpreter::GetVariable(retstr: &v864, this, def: *(idVarDef **)(v7 + 4));
          v100 = *(idVarDef **)(v7 + 8);
          v101 = (float *)v99->value.i;
          v102 = idInterpreter::GetVariable(retstr: &v1066, this, def: v100);
          *(varEval_t *)v4 = (varEval_t)v102->value.cp;
          *v102->value.fp = *v98 * *v101;
          goto LABEL_437;
        case 0xE:
          v108 = (float *)idInterpreter::GetVariable(retstr: &v1068, this, def: *(idVarDef **)v7)->value.i;
          v109 = idInterpreter::GetVariable(retstr: &v870, this, def: *(idVarDef **)(v7 + 4));
          v110 = *(idVarDef **)(v7 + 8);
          v111 = (float *)v109->value.i;
          v112 = idInterpreter::GetVariable(retstr: &v1168, this, def: v110);
          *(varEval_t *)v4 = (varEval_t)v112->value.cp;
          *v112->value.fp = (float)(*v108 * *v111) + (float)((float)(v108[2] * v111[2]) + (float)(v108[1] * v111[1]));
          goto LABEL_437;
        case 0xF:
          v103 = (_DWORD *)idInterpreter::GetVariable(retstr: &v866, this, def: *(idVarDef **)v7)->value.i;
          v104 = idInterpreter::GetVariable(retstr: &v1242, this, def: *(idVarDef **)(v7 + 4));
          v105 = *(idVarDef **)(v7 + 8);
          v106 = (_DWORD *)v104->value.i;
          v107 = idInterpreter::GetVariable(retstr: &v868, this, def: v105);
          *(_DWORD *)v4 = *v103;
          LODWORD(v2) = *v106;
          HIDWORD(v2) = (varEval_t)v107->value.cp;
          LODWORD(v3) = *v103 * *v106;
          *v107->value.ip = v3;
          goto LABEL_437;
        case 0x10:
          v113 = (float *)idInterpreter::GetVariable(retstr: &v872, this, def: *(idVarDef **)v7)->value.i;
          v114 = idInterpreter::GetVariable(retstr: &v1070, this, def: *(idVarDef **)(v7 + 4));
          v115 = *(idVarDef **)(v7 + 8);
          v116 = (float *)v114->value.i;
          *(varEval_t *)v4 = (varEval_t)idInterpreter::GetVariable(retstr: &v874, this, def: v115)->value.cp;
          v117 = (float)(v116[1] * *v113);
          v118 = (float)(v116[2] * *v113);
          **(float **)v4 = *v113 * *v116;
          *(float *)(*(_DWORD *)v4 + 4) = v117;
          *(float *)(*(_DWORD *)v4 + 8) = v118;
          goto LABEL_437;
        case 0x11:
          v119 = (float *)idInterpreter::GetVariable(retstr: &v1218, this, def: *(idVarDef **)v7)->value.i;
          v120 = idInterpreter::GetVariable(retstr: &v876, this, def: *(idVarDef **)(v7 + 4));
          v121 = *(idVarDef **)(v7 + 8);
          v122 = (float *)v120->value.i;
          *(varEval_t *)v4 = (varEval_t)idInterpreter::GetVariable(retstr: &v1072, this, def: v121)->value.cp;
          v123 = (float)(v119[1] * *v122);
          v124 = (float)(v119[2] * *v122);
          **(float **)v4 = *v122 * *v119;
          *(float *)(*(_DWORD *)v4 + 4) = v123;
          *(float *)(*(_DWORD *)v4 + 8) = v124;
          goto LABEL_437;
        case 0x12:
          v125 = (_DWORD *)idInterpreter::GetVariable(retstr: &v878, this, def: *(idVarDef **)v7)->value.i;
          v126 = idInterpreter::GetVariable(retstr: &v1170, this, def: *(idVarDef **)(v7 + 4));
          v127 = *(idVarDef **)(v7 + 8);
          v128 = (float *)v126->value.i;
          v129 = idInterpreter::GetVariable(retstr: &v880, this, def: v127);
          *(_DWORD *)v4 = *v125;
          v130 = *v128;
          LODWORD(v2) = (varEval_t)v129->value.cp;
          v131 = v128[1];
          HIDWORD(v2) = *v125;
          v132 = v128[2];
          v1167 = *(__int64 *)((char *)&v2 + 4);
          *(float *)v2 = (float)*(__int64 *)((char *)&v2 + 4) * (float)v130;
          *(float *)(v2 + 4) = (float)v131 * (float)*(__int64 *)((char *)&v2 + 4);
          *(float *)(v2 + 8) = (float)v132 * (float)*(__int64 *)((char *)&v2 + 4);
          goto LABEL_437;
        case 0x13:
          v133 = (float *)idInterpreter::GetVariable(retstr: &v1074, this, def: *(idVarDef **)v7)->value.i;
          v134 = idInterpreter::GetVariable(retstr: &v882, this, def: *(idVarDef **)(v7 + 4));
          v135 = *(idVarDef **)(v7 + 8);
          v136 = (_DWORD *)v134->value.i;
          v137 = idInterpreter::GetVariable(retstr: &v1264, this, def: v135);
          *(_DWORD *)v4 = *v136;
          v138 = *v133;
          LODWORD(v2) = (varEval_t)v137->value.cp;
          v139 = v133[1];
          HIDWORD(v2) = *v136;
          v140 = v133[2];
          v1169 = *(__int64 *)((char *)&v2 + 4);
          *(float *)v2 = (float)*(__int64 *)((char *)&v2 + 4) * (float)v138;
          *(float *)(v2 + 4) = (float)v139 * (float)*(__int64 *)((char *)&v2 + 4);
          *(float *)(v2 + 8) = (float)v140 * (float)*(__int64 *)((char *)&v2 + 4);
          goto LABEL_437;
        case 0x14:
          v794 = (float *)idInterpreter::GetVariable(retstr: &v1139, this, def: *(idVarDef **)v7)->value.i;
          v795 = idInterpreter::GetVariable(retstr: &v1141, this, def: *(idVarDef **)(v7 + 4));
          v796 = *(idVarDef **)(v7 + 8);
          v797 = (_DWORD *)v795->value.i;
          v798 = idInterpreter::GetVariable(retstr: &v1143, this, def: v796);
          *(_DWORD *)v4 = *v797;
          v799 = *v794;
          LODWORD(v2) = (varEval_t)v798->value.cp;
          HIDWORD(v2) = *v797;
          v1253 = *(__int64 *)((char *)&v2 + 4);
          *(float *)v2 = (float)*(__int64 *)((char *)&v2 + 4) * (float)v799;
          goto LABEL_437;
        case 0x15:
          v800 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1145, this, def: *(idVarDef **)v7)->value.i;
          v801 = idInterpreter::GetVariable(retstr: &v1147, this, def: *(idVarDef **)(v7 + 4));
          v802 = *(idVarDef **)(v7 + 8);
          v803 = (float *)v801->value.i;
          v804 = idInterpreter::GetVariable(retstr: &v1149, this, def: v802);
          *(_DWORD *)v4 = *v800;
          v805 = *v803;
          LODWORD(v2) = (varEval_t)v804->value.cp;
          HIDWORD(v2) = *v800;
          v1255 = *(__int64 *)((char *)&v2 + 4);
          *(float *)v2 = (float)*(__int64 *)((char *)&v2 + 4) * (float)v805;
          goto LABEL_437;
        case 0x16:
          v31 = (float *)idInterpreter::GetVariable(retstr: &v1160, this, def: *(idVarDef **)v7)->value.i;
          v32 = idInterpreter::GetVariable(retstr: &v840, this, def: *(idVarDef **)(v7 + 4));
          v33 = *(idVarDef **)(v7 + 8);
          v34 = (float *)v32->value.i;
          v35 = idInterpreter::GetVariable(retstr: &v1054, this, def: v33);
          *(varEval_t *)v4 = (varEval_t)v35->value.cp;
          *v35->value.fp = *v31 + *v34;
          goto LABEL_437;
        case 0x17:
          v41 = (float *)idInterpreter::GetVariable(retstr: &v1056, this, def: *(idVarDef **)v7)->value.i;
          v42 = idInterpreter::GetVariable(retstr: &v846, this, def: *(idVarDef **)(v7 + 4));
          v43 = *(idVarDef **)(v7 + 8);
          v44 = (float *)v42->value.i;
          *(varEval_t *)v4 = (varEval_t)idInterpreter::GetVariable(retstr: &v1162, this, def: v43)->value.cp;
          v45 = (float)(v41[1] + v44[1]);
          v46 = (float)(v41[2] + v44[2]);
          **(float **)v4 = *v41 + *v44;
          *(float *)(*(_DWORD *)v4 + 4) = v45;
          *(float *)(*(_DWORD *)v4 + 8) = v46;
          goto LABEL_437;
        case 0x18:
          v36 = (_DWORD *)idInterpreter::GetVariable(retstr: &v842, this, def: *(idVarDef **)v7)->value.i;
          v37 = idInterpreter::GetVariable(retstr: &v1214, this, def: *(idVarDef **)(v7 + 4));
          v38 = *(idVarDef **)(v7 + 8);
          v39 = (_DWORD *)v37->value.i;
          v40 = idInterpreter::GetVariable(retstr: &v844, this, def: v38);
          *(varEval_t *)v4 = (varEval_t)v40->value.cp;
          LODWORD(v2) = *v36 + *v39;
          *v40->value.ip = v2;
          goto LABEL_437;
        case 0x19:
          v47 = *(idVarDef **)v7;
          if ( *(_DWORD *)(*(_DWORD *)v7 + 16) == 3 )
            cp = (const char *)&this->localstack.stack[v47->value.value.i + this->localstack.stackBase];
          else
            cp = v47->value.value.cp;
          v49 = *(_DWORD *)(v7 + 8);
          if ( *(_DWORD *)(v49 + 16) != 3 )
            goto LABEL_57;
          v50 = (char *)&this->localstack.stack[*(_DWORD *)(v49 + 4) + this->localstack.stackBase];
          goto LABEL_58;
        case 0x1A:
          v54 = idInterpreter::GetVariable(retstr: &v848, this, def: *(idVarDef **)v7);
          v55 = idInterpreter::FloatToString(this, value: *v54->value.fp);
          v49 = *(_DWORD *)(v7 + 8);
          cp = v55;
          if ( *(_DWORD *)(v49 + 16) != 3 )
            goto LABEL_57;
          v50 = (char *)&this->localstack.stack[*(_DWORD *)(v49 + 4) + this->localstack.stackBase];
          goto LABEL_58;
        case 0x1B:
          v58 = idInterpreter::GetVariable(retstr: &v850, this, def: *(idVarDef **)(v7 + 4));
          v59 = *(idVarDef **)v7;
          v60 = (float *)v58->value.i;
          if ( *(_DWORD *)(*(_DWORD *)v7 + 16) == 3 )
            v61 = (const char *)&this->localstack.stack[v59->value.value.i + this->localstack.stackBase];
          else
            v61 = v59->value.value.cp;
          v62 = *(_DWORD *)(v7 + 8);
          if ( *(_DWORD *)(v62 + 16) == 3 )
            v63 = (char *)&this->localstack.stack[*(_DWORD *)(v62 + 4) + this->localstack.stackBase];
          else
            v63 = *(char **)(v62 + 4);
          idStr::Copynz(dest: v63, src: v61, destsize: 256);
          v64 = idInterpreter::FloatToString(this, value: *v60);
          v53 = *(_DWORD *)(v7 + 8);
          v52 = v64;
          if ( *(_DWORD *)(v53 + 16) == 3 )
            goto LABEL_92;
          goto LABEL_62;
        case 0x1C:
          LODWORD(v56) = *idInterpreter::GetVariable(retstr: &v1058, this, def: *(idVarDef **)v7)->value.ip;
          v1163 = v56;
          v57 = idInterpreter::FloatToString(this, value: (float)v56);
          v49 = *(_DWORD *)(v7 + 8);
          cp = v57;
          if ( *(_DWORD *)(v49 + 16) != 3 )
            goto LABEL_57;
          v50 = (char *)&this->localstack.stack[*(_DWORD *)(v49 + 4) + this->localstack.stackBase];
          goto LABEL_58;
        case 0x1D:
          v65 = idInterpreter::GetVariable(retstr: &v1254, this, def: *(idVarDef **)(v7 + 4));
          v66 = *(idVarDef **)v7;
          v67 = (_DWORD *)v65->value.i;
          if ( *(_DWORD *)(*(_DWORD *)v7 + 16) == 3 )
            v68 = (const char *)&this->localstack.stack[v66->value.value.i + this->localstack.stackBase];
          else
            v68 = v66->value.value.cp;
          v69 = *(_DWORD *)(v7 + 8);
          if ( *(_DWORD *)(v69 + 16) == 3 )
            v70 = (char *)&this->localstack.stack[*(_DWORD *)(v69 + 4) + this->localstack.stackBase];
          else
            v70 = *(char **)(v69 + 4);
          idStr::Copynz(dest: v70, src: v68, destsize: 256);
          LODWORD(v71) = *v67;
          v1165 = v71;
          v72 = idInterpreter::FloatToString(this, value: (float)v71);
          v53 = *(_DWORD *)(v7 + 8);
          v52 = v72;
          if ( *(_DWORD *)(v53 + 16) == 3 )
            goto LABEL_92;
          goto LABEL_62;
        case 0x1E:
          v73 = (idAngles **)idInterpreter::GetVariable(retstr: &v852, this, def: *(idVarDef **)v7);
          v74 = idVec3::ToString(this: *v73, precision: 2);
          v49 = *(_DWORD *)(v7 + 8);
          cp = v74;
          if ( *(_DWORD *)(v49 + 16) == 3 )
            v50 = (char *)&this->localstack.stack[*(_DWORD *)(v49 + 4) + this->localstack.stackBase];
          else
LABEL_57:
            v50 = *(char **)(v49 + 4);
LABEL_58:
          idStr::Copynz(dest: v50, src: cp, destsize: 256);
          v51 = *(_DWORD *)(v7 + 4);
          if ( *(_DWORD *)(v51 + 16) == 3 )
            v52 = (const char *)&this->localstack.stack[*(_DWORD *)(v51 + 4) + this->localstack.stackBase];
          else
            v52 = *(const char **)(v51 + 4);
          v53 = *(_DWORD *)(v7 + 8);
          if ( *(_DWORD *)(v53 + 16) != 3 )
            goto LABEL_62;
          goto LABEL_92;
        case 0x1F:
          v75 = (idAngles **)idInterpreter::GetVariable(retstr: &v1060, this, def: *(idVarDef **)(v7 + 4));
          v76 = *(idVarDef **)v7;
          v77 = *v75;
          if ( *(_DWORD *)(*(_DWORD *)v7 + 16) == 3 )
            v78 = (const char *)&this->localstack.stack[v76->value.value.i + this->localstack.stackBase];
          else
            v78 = v76->value.value.cp;
          v79 = *(_DWORD *)(v7 + 8);
          if ( *(_DWORD *)(v79 + 16) == 3 )
            v80 = (char *)&this->localstack.stack[*(_DWORD *)(v79 + 4) + this->localstack.stackBase];
          else
            v80 = *(char **)(v79 + 4);
          idStr::Copynz(dest: v80, src: v78, destsize: 256);
          v81 = idVec3::ToString(this: v77, precision: 2);
          v53 = *(_DWORD *)(v7 + 8);
          v52 = v81;
          if ( *(_DWORD *)(v53 + 16) == 3 )
LABEL_92:
            idStr::Append(
              dest: (char *)&this->localstack.stack[*(_DWORD *)(v53 + 4) + this->localstack.stackBase],
              size: 256,
              src: v52);
          else
LABEL_62:
            idStr::Append(dest: *(char **)(v53 + 4), size: 256, src: v52);
          goto LABEL_437;
        case 0x20:
          v770 = (float *)idInterpreter::GetVariable(retstr: &v1115, this, def: *(idVarDef **)v7)->value.i;
          v771 = idInterpreter::GetVariable(retstr: &v1117, this, def: *(idVarDef **)(v7 + 4));
          v772 = *(idVarDef **)(v7 + 8);
          v773 = (_DWORD *)v771->value.i;
          v774 = idInterpreter::GetVariable(retstr: &v1119, this, def: v772);
          *(_DWORD *)v4 = *v773;
          v775 = *v770;
          LODWORD(v2) = (varEval_t)v774->value.cp;
          HIDWORD(v2) = *v773;
          v1245 = *(__int64 *)((char *)&v2 + 4);
          *(float *)v2 = (float)*(__int64 *)((char *)&v2 + 4) + (float)v775;
          goto LABEL_437;
        case 0x21:
          v776 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1121, this, def: *(idVarDef **)v7)->value.i;
          v777 = idInterpreter::GetVariable(retstr: &v1123, this, def: *(idVarDef **)(v7 + 4));
          v778 = *(idVarDef **)(v7 + 8);
          v779 = (float *)v777->value.i;
          v780 = idInterpreter::GetVariable(retstr: &v1125, this, def: v778);
          *(_DWORD *)v4 = *v776;
          v781 = *v779;
          LODWORD(v2) = (varEval_t)v780->value.cp;
          HIDWORD(v2) = *v776;
          v1247 = *(__int64 *)((char *)&v2 + 4);
          *(float *)v2 = (float)*(__int64 *)((char *)&v2 + 4) + (float)v781;
          goto LABEL_437;
        case 0x22:
          v82 = (float *)idInterpreter::GetVariable(retstr: &v854, this, def: *(idVarDef **)v7)->value.i;
          v83 = idInterpreter::GetVariable(retstr: &v1164, this, def: *(idVarDef **)(v7 + 4));
          v84 = *(idVarDef **)(v7 + 8);
          v85 = (float *)v83->value.i;
          v86 = idInterpreter::GetVariable(retstr: &v856, this, def: v84);
          *(varEval_t *)v4 = (varEval_t)v86->value.cp;
          *v86->value.fp = *v82 - *v85;
          goto LABEL_437;
        case 0x23:
          v92 = (float *)idInterpreter::GetVariable(retstr: &v860, this, def: *(idVarDef **)v7)->value.i;
          v93 = idInterpreter::GetVariable(retstr: &v1064, this, def: *(idVarDef **)(v7 + 4));
          v94 = *(idVarDef **)(v7 + 8);
          v95 = (float *)v93->value.i;
          *(varEval_t *)v4 = (varEval_t)idInterpreter::GetVariable(retstr: &v862, this, def: v94)->value.cp;
          v96 = (float)(v92[1] - v95[1]);
          v97 = (float)(v92[2] - v95[2]);
          **(float **)v4 = *v92 - *v95;
          *(float *)(*(_DWORD *)v4 + 4) = v96;
          *(float *)(*(_DWORD *)v4 + 8) = v97;
          goto LABEL_437;
        case 0x24:
          v87 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1062, this, def: *(idVarDef **)v7)->value.i;
          v88 = idInterpreter::GetVariable(retstr: &v858, this, def: *(idVarDef **)(v7 + 4));
          v89 = *(idVarDef **)(v7 + 8);
          v90 = (_DWORD *)v88->value.i;
          v91 = idInterpreter::GetVariable(retstr: &v1216, this, def: v89);
          *(_DWORD *)v4 = *v87;
          LODWORD(v2) = *v90;
          HIDWORD(v2) = (varEval_t)v91->value.cp;
          LODWORD(v3) = *v87 - *v90;
          *v91->value.ip = v3;
          goto LABEL_437;
        case 0x25:
          v782 = (float *)idInterpreter::GetVariable(retstr: &v1127, this, def: *(idVarDef **)v7)->value.i;
          v783 = idInterpreter::GetVariable(retstr: &v1129, this, def: *(idVarDef **)(v7 + 4));
          v784 = *(idVarDef **)(v7 + 8);
          v785 = (_DWORD *)v783->value.i;
          v786 = idInterpreter::GetVariable(retstr: &v1131, this, def: v784);
          *(_DWORD *)v4 = *v785;
          v787 = *v782;
          LODWORD(v2) = (varEval_t)v786->value.cp;
          HIDWORD(v2) = *v785;
          v1249 = *(__int64 *)((char *)&v2 + 4);
          *(float *)v2 = (float)v787 - (float)*(__int64 *)((char *)&v2 + 4);
          goto LABEL_437;
        case 0x26:
          v788 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1133, this, def: *(idVarDef **)v7)->value.i;
          v789 = idInterpreter::GetVariable(retstr: &v1135, this, def: *(idVarDef **)(v7 + 4));
          v790 = *(idVarDef **)(v7 + 8);
          v791 = (float *)v789->value.i;
          v792 = idInterpreter::GetVariable(retstr: &v1137, this, def: v790);
          *(_DWORD *)v4 = *v788;
          v793 = *v791;
          LODWORD(v2) = (varEval_t)v792->value.cp;
          HIDWORD(v2) = *v788;
          v1251 = *(__int64 *)((char *)&v2 + 4);
          *(float *)v2 = (float)*(__int64 *)((char *)&v2 + 4) - (float)v793;
          goto LABEL_437;
        case 0x27:
          v141 = (float *)idInterpreter::GetVariable(retstr: &v884, this, def: *(idVarDef **)v7)->value.i;
          v142 = idInterpreter::GetVariable(retstr: &v1076, this, def: *(idVarDef **)(v7 + 4));
          v143 = *(idVarDef **)(v7 + 8);
          v144 = (float *)v142->value.i;
          v145 = idInterpreter::GetVariable(retstr: &v886, this, def: v143);
          v146 = *v144;
          v147 = (float *)v145->value.i;
          if ( v146 == 0.0 )
            goto LABEL_248;
          *v147 = *v141 / (float)v146;
          goto LABEL_437;
        case 0x28:
          v148 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1172, this, def: *(idVarDef **)v7)->value.i;
          v149 = idInterpreter::GetVariable(retstr: &v888, this, def: *(idVarDef **)(v7 + 4));
          v150 = *(idVarDef **)(v7 + 8);
          v151 = (signed int *)v149->value.i;
          v154 = idInterpreter::GetVariable(retstr: &v1078, this, def: v150);
          v155 = *v151;
          v157 = *v151 != 0;
          v156 = (int *)v154->value.i;
          if ( !v157 )
            goto LABEL_107;
          *(_DWORD *)v4 = *v148;
          __twllei(v155, 0);
          LODWORD(v2) = *(_DWORD *)v4 / v155;
          HIDWORD(v2) = __ROL4__(*(_DWORD *)v4, 1) - 1;
          *v156 = *(_DWORD *)v4 / v155;
          LODWORD(v3) = v155 & ~HIDWORD(v2);
          __twlgei(v3, 0xFFFFFFFF);
          goto LABEL_437;
        case 0x29:
          v743 = (float *)idInterpreter::GetVariable(retstr: &v1091, this, def: *(idVarDef **)v7)->value.i;
          v744 = idInterpreter::GetVariable(retstr: &v1093, this, def: *(idVarDef **)(v7 + 4));
          v745 = *(idVarDef **)(v7 + 8);
          v746 = (_DWORD *)v744->value.i;
          v747 = idInterpreter::GetVariable(retstr: &v1095, this, def: v745);
          *(_DWORD *)v4 = *v746;
          v748 = *v743;
          LODWORD(v2) = (varEval_t)v747->value.cp;
          HIDWORD(v2) = *v746;
          v1239 = *(__int64 *)((char *)&v2 + 4);
          *(float *)v2 = (float)v748 / (float)*(__int64 *)((char *)&v2 + 4);
          goto LABEL_437;
        case 0x2A:
          v749 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1097, this, def: *(idVarDef **)v7)->value.i;
          v750 = idInterpreter::GetVariable(retstr: &v1099, this, def: *(idVarDef **)(v7 + 4));
          v751 = *(idVarDef **)(v7 + 8);
          v752 = (float *)v750->value.i;
          v753 = idInterpreter::GetVariable(retstr: &v1101, this, def: v751);
          *(_DWORD *)v4 = *v749;
          v754 = *v752;
          LODWORD(v2) = (varEval_t)v753->value.cp;
          HIDWORD(v2) = *v749;
          v1241 = *(__int64 *)((char *)&v2 + 4);
          *(float *)v2 = (float)*(__int64 *)((char *)&v2 + 4) / (float)v754;
          goto LABEL_437;
        case 0x2B:
          v755 = (float *)idInterpreter::GetVariable(retstr: &v1103, this, def: *(idVarDef **)v7)->value.i;
          v756 = idInterpreter::GetVariable(retstr: &v1105, this, def: *(idVarDef **)(v7 + 4));
          v757 = *(idVarDef **)(v7 + 8);
          v758 = (_DWORD *)v756->value.i;
          v759 = idInterpreter::GetVariable(retstr: &v1107, this, def: v757);
          *(_DWORD *)v4 = *v758;
          v760 = *v755;
          LODWORD(v2) = (varEval_t)v759->value.cp;
          v761 = v755[1];
          HIDWORD(v2) = *v758;
          v762 = v755[2];
          v1243 = *(__int64 *)((char *)&v2 + 4);
          *(float *)v2 = (float)((float)1.0 / (float)*(__int64 *)((char *)&v2 + 4)) * (float)v760;
          *(float *)(v2 + 4) = (float)v761 * (float)((float)1.0 / (float)*(__int64 *)((char *)&v2 + 4));
          *(float *)(v2 + 8) = (float)v762 * (float)((float)1.0 / (float)*(__int64 *)((char *)&v2 + 4));
          goto LABEL_437;
        case 0x2C:
          v763 = (float *)idInterpreter::GetVariable(retstr: &v1109, this, def: *(idVarDef **)v7)->value.i;
          v764 = idInterpreter::GetVariable(retstr: &v1111, this, def: *(idVarDef **)(v7 + 4));
          v765 = *(idVarDef **)(v7 + 8);
          v766 = (float *)v764->value.i;
          *(varEval_t *)v4 = (varEval_t)idInterpreter::GetVariable(retstr: &v1113, this, def: v765)->value.cp;
          v767 = (float)((float)1.0 / *v766);
          v768 = v763[1];
          v769 = v763[2];
          **(float **)v4 = (float)((float)1.0 / *v766) * *v763;
          *(float *)(*(_DWORD *)v4 + 4) = (float)v768 * (float)v767;
          *(float *)(*(_DWORD *)v4 + 8) = (float)v769 * (float)v767;
          goto LABEL_437;
        case 0x2D:
          v317 = (float *)idInterpreter::GetVariable(retstr: &v1122, this, def: *(idVarDef **)v7)->value.i;
          v318 = idInterpreter::GetVariable(retstr: &v978, this, def: *(idVarDef **)(v7 + 4));
          v319 = *(idVarDef **)(v7 + 8);
          v320 = (float *)v318->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v1258, this, def: v319)->value.cp;
          *(_DWORD *)&v4[8] = 1;
          if ( *v317 == *v320 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x2E:
          v321 = (float *)idInterpreter::GetVariable(retstr: &v980, this, def: *(idVarDef **)v7)->value.i;
          v322 = idInterpreter::GetVariable(retstr: &v1124, this, def: *(idVarDef **)(v7 + 4));
          v323 = *(idVarDef **)(v7 + 8);
          v324 = (float *)v322->value.i;
          v325 = idInterpreter::GetVariable(retstr: &v982, this, def: v323);
          if ( *v321 != *v324 || v321[1] != v324[1] || (v326 = 1, v321[2] != v324[2]) )
            v326 = 0;
          *v325->value.ip = v326;
          goto LABEL_437;
        case 0x2F:
          idInterpreter::GetVariable(retstr: &v1196, this, def: *(idVarDef **)v7);
          idInterpreter::GetVariable(retstr: &v984, this, def: *(idVarDef **)(v7 + 4));
          v327 = idInterpreter::GetVariable(retstr: &v1126, this, def: *(idVarDef **)(v7 + 8));
          v328 = *(_DWORD *)(v7 + 4);
          v329 = (_DWORD *)v327->value.i;
          if ( *(_DWORD *)(v328 + 16) == 3 )
            v330 = (const char *)&this->localstack.stack[*(_DWORD *)(v328 + 4) + this->localstack.stackBase];
          else
            v330 = *(const char **)(v328 + 4);
          v331 = *(idVarDef **)v7;
          if ( *(_DWORD *)(*(_DWORD *)v7 + 16) == 3 )
            *v329 = (_cntlzw(
                       idStr::Cmp(
                         s1: (const char *)&this->localstack.stack[v331->value.value.i + this->localstack.stackBase],
                         s2: v330))
                   & 0x20) != 0;
          else
            *v329 = (_cntlzw(idStr::Cmp(s1: v331->value.value.cp, s2: v330)) & 0x20) != 0;
          goto LABEL_437;
        case 0x30:
          v332 = (_DWORD *)idInterpreter::GetVariable(retstr: &v986, this, def: *(idVarDef **)v7)->value.i;
          v333 = idInterpreter::GetVariable(retstr: &v1232, this, def: *(idVarDef **)(v7 + 4));
          v334 = *(idVarDef **)(v7 + 8);
          v335 = (_DWORD *)v333->value.i;
          v336 = idInterpreter::GetVariable(retstr: &v988, this, def: v334);
          *(_DWORD *)v4 = *v332;
          LODWORD(v2) = *v335;
          HIDWORD(v2) = (varEval_t)v336->value.cp;
          LODWORD(v3) = *v335 - *v332;
          HIDWORD(v3) = _cntlzw(v3);
          *v336->value.ip = (v3 & 0x2000000000LL) != 0;
          goto LABEL_437;
        case 0x31:
          v343 = (float *)idInterpreter::GetVariable(retstr: &v992, this, def: *(idVarDef **)v7)->value.i;
          v344 = idInterpreter::GetVariable(retstr: &v1130, this, def: *(idVarDef **)(v7 + 4));
          v345 = *(idVarDef **)(v7 + 8);
          v346 = (_DWORD *)v344->value.i;
          v347 = idInterpreter::GetVariable(retstr: &v994, this, def: v345);
          *(_DWORD *)v4 = *v346;
          v348 = *v343;
          *(varEval_t *)&v4[4] = (varEval_t)v347->value.cp;
          *(_DWORD *)&v4[8] = 1;
          LODWORD(v2) = *v346;
          v1201 = v2;
          if ( v348 == (float)v2 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x32:
          v337 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1128, this, def: *(idVarDef **)v7)->value.i;
          v338 = idInterpreter::GetVariable(retstr: &v990, this, def: *(idVarDef **)(v7 + 4));
          v339 = *(idVarDef **)(v7 + 8);
          v340 = (float *)v338->value.i;
          v341 = idInterpreter::GetVariable(retstr: &v1198, this, def: v339);
          *(_DWORD *)v4 = *v337;
          v342 = *v340;
          *(varEval_t *)&v4[4] = (varEval_t)v341->value.cp;
          *(_DWORD *)&v4[8] = 1;
          LODWORD(v2) = *v337;
          v1199 = v2;
          if ( (float)v2 == v342 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x33:
          v349 = idInterpreter::GetVariable(retstr: &v1250, this, def: *(idVarDef **)v7);
          v350 = *(idVarDef **)(v7 + 4);
          v830.value.cp = (char *)v349->value.i;
          v351 = idInterpreter::GetVariable(retstr: &v996, this, def: v350);
          v352 = *(idVarDef **)(v7 + 8);
          v828.value.cp = v351->value.cp;
          v353 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1132, this, def: v352)->value.i;
          Entity = varEval_t::GetEntity(this: &v830);
          LODWORD(v3) = (char *)varEval_t::GetEntity(this: &v828) - (char *)Entity;
          HIDWORD(v3) = _cntlzw(v3);
          *v353 = (v3 & 0x2000000000LL) != 0;
          goto LABEL_437;
        case 0x34:
          v355 = idInterpreter::GetVariable(retstr: &v998, this, def: *(idVarDef **)v7);
          v356 = *(idVarDef **)(v7 + 4);
          v830.value.cp = (char *)v355->value.i;
          v357 = idInterpreter::GetVariable(retstr: &v1200, this, def: v356);
          v358 = *(idVarDef **)(v7 + 8);
          v828.value.cp = v357->value.cp;
          v359 = idInterpreter::GetVariable(retstr: &v1000, this, def: v358);
          v360 = *(idVarDef **)(v7 + 4);
          v361 = (_DWORD *)v359->value.i;
          v157 = idInterpreter::GetScriptObject(this, varDef: v360) == nullptr;
          v362 = &v830;
          if ( !v157 )
            goto LABEL_194;
          goto LABEL_197;
        case 0x35:
          v364 = idInterpreter::GetVariable(retstr: &v1134, this, def: *(idVarDef **)v7);
          v365 = *(idVarDef **)(v7 + 4);
          v830.value.cp = (char *)v364->value.i;
          v366 = idInterpreter::GetVariable(retstr: &v1002, this, def: v365);
          v367 = *(idVarDef **)(v7 + 8);
          v828.value.cp = v366->value.cp;
          v368 = idInterpreter::GetVariable(retstr: &v1234, this, def: v367);
          v369 = *(idVarDef **)v7;
          v361 = (_DWORD *)v368->value.i;
          if ( idInterpreter::GetScriptObject(this, varDef: v369) != nullptr )
          {
LABEL_194:
            v363 = varEval_t::GetEntity(this: &v830);
            *(_DWORD *)v4 = (_cntlzw((char *)varEval_t::GetEntity(this: &v828) - (char *)v363) & 0x20) != 0;
            *v361 = *(_DWORD *)v4;
          }
          else
          {
            v362 = &v828;
LABEL_197:
            *v361 = (_cntlzw((unsigned int)varEval_t::GetEntity(this: v362)) & 0x20) != 0;
          }
          goto LABEL_437;
        case 0x36:
          v370 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1004, this, def: *(idVarDef **)(v7 + 8))->value.i;
          v371 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          *(_DWORD *)v4 = _cntlzw((char *)idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)(v7 + 4)) - (char *)v371);
          LODWORD(v2) = (v4[3] & 0x20) != 0;
          *v370 = v2;
          goto LABEL_437;
        case 0x37:
          v372 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1136, this, def: *(idVarDef **)v7)->value.i;
          v373 = idInterpreter::GetVariable(retstr: &v1006, this, def: *(idVarDef **)(v7 + 4));
          v374 = *(idVarDef **)(v7 + 8);
          v375 = (_DWORD *)v373->value.i;
          v376 = idInterpreter::GetVariable(retstr: &v1202, this, def: v374);
          *(_DWORD *)v4 = *v372;
          LODWORD(v2) = *v375;
          HIDWORD(v2) = (varEval_t)v376->value.cp;
          LODWORD(v3) = *v375 - *v372;
          HIDWORD(v3) = _cntlzw(v3);
          *v376->value.ip = (v3 & 0x2000000000LL) != 0;
          goto LABEL_437;
        case 0x38:
          v377 = (float *)idInterpreter::GetVariable(retstr: &v1008, this, def: *(idVarDef **)v7)->value.i;
          v378 = idInterpreter::GetVariable(retstr: &v1138, this, def: *(idVarDef **)(v7 + 4));
          v379 = *(idVarDef **)(v7 + 8);
          v380 = (float *)v378->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v1010, this, def: v379)->value.cp;
          *(_DWORD *)&v4[8] = 1;
          if ( *v377 != *v380 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x39:
          v381 = (float *)idInterpreter::GetVariable(retstr: &v1265, this, def: *(idVarDef **)v7)->value.i;
          v382 = idInterpreter::GetVariable(retstr: &v1012, this, def: *(idVarDef **)(v7 + 4));
          v383 = *(idVarDef **)(v7 + 8);
          v384 = (float *)v382->value.i;
          v385 = idInterpreter::GetVariable(retstr: &v1140, this, def: v383);
          if ( *v381 != *v384 || v381[1] != v384[1] || (v386 = 1, v381[2] != v384[2]) )
            v386 = 0;
          *(_DWORD *)v4 = _cntlzw(v386);
          LODWORD(v2) = (v4[3] & 0x20) != 0;
          *v385->value.ip = v2;
          goto LABEL_437;
        case 0x3A:
          v404 = idInterpreter::GetVariable(retstr: &v1206, this, def: *(idVarDef **)(v7 + 8));
          v405 = *(_DWORD *)(v7 + 4);
          v406 = (_DWORD *)v404->value.i;
          if ( *(_DWORD *)(v405 + 16) == 3 )
            v407 = (const char *)&this->localstack.stack[*(_DWORD *)(v405 + 4) + this->localstack.stackBase];
          else
            v407 = *(const char **)(v405 + 4);
          v408 = *(idVarDef **)v7;
          if ( *(_DWORD *)(*(_DWORD *)v7 + 16) == 3 )
            *v406 = idStr::Cmp(
                      s1: (const char *)&this->localstack.stack[v408->value.value.i + this->localstack.stackBase],
                      s2: v407) != 0;
          else
            *v406 = idStr::Cmp(s1: v408->value.value.cp, s2: v407) != 0;
          goto LABEL_437;
        case 0x3B:
          v387 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1014, this, def: *(idVarDef **)v7)->value.i;
          v388 = idInterpreter::GetVariable(retstr: &v1204, this, def: *(idVarDef **)(v7 + 4));
          v389 = *(idVarDef **)(v7 + 8);
          v390 = (_DWORD *)v388->value.i;
          v391 = idInterpreter::GetVariable(retstr: &v1016, this, def: v389);
          *(_DWORD *)v4 = *v387;
          LODWORD(v2) = *v390;
          HIDWORD(v2) = (varEval_t)v391->value.cp;
          LODWORD(v3) = *v390 - *v387;
          HIDWORD(v3) = v3 - 1;
          *v391->value.ip = *v390 != *v387;
          goto LABEL_437;
        case 0x3C:
          v392 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1142, this, def: *(idVarDef **)v7)->value.i;
          v393 = idInterpreter::GetVariable(retstr: &v1018, this, def: *(idVarDef **)(v7 + 4));
          v394 = *(idVarDef **)(v7 + 8);
          v395 = (float *)v393->value.i;
          v396 = idInterpreter::GetVariable(retstr: &v1236, this, def: v394);
          *(_DWORD *)v4 = *v392;
          v397 = *v395;
          *(varEval_t *)&v4[4] = (varEval_t)v396->value.cp;
          *(_DWORD *)&v4[8] = 1;
          LODWORD(v2) = *v392;
          v1203 = v2;
          if ( (float)v2 != v397 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x3D:
          v398 = (float *)idInterpreter::GetVariable(retstr: &v1020, this, def: *(idVarDef **)v7)->value.i;
          v399 = idInterpreter::GetVariable(retstr: &v1144, this, def: *(idVarDef **)(v7 + 4));
          v400 = *(idVarDef **)(v7 + 8);
          v401 = (_DWORD *)v399->value.i;
          v402 = idInterpreter::GetVariable(retstr: &v1022, this, def: v400);
          *(_DWORD *)v4 = *v401;
          v403 = *v398;
          *(varEval_t *)&v4[4] = (varEval_t)v402->value.cp;
          *(_DWORD *)&v4[8] = 1;
          LODWORD(v2) = *v401;
          v1205 = v2;
          if ( v403 != (float)v2 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x3E:
          v409 = idInterpreter::GetVariable(retstr: &v1024, this, def: *(idVarDef **)v7);
          v410 = *(idVarDef **)(v7 + 4);
          v830.value.cp = (char *)v409->value.i;
          v411 = idInterpreter::GetVariable(retstr: &v1146, this, def: v410);
          v412 = *(idVarDef **)(v7 + 8);
          v828.value.cp = v411->value.cp;
          v413 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1026, this, def: v412)->value.i;
          v414 = varEval_t::GetEntity(this: &v830);
          LODWORD(v3) = (char *)varEval_t::GetEntity(this: &v828) - (char *)v414;
          HIDWORD(v3) = v3 - 1;
          *v413 = v3 != 0;
          goto LABEL_437;
        case 0x3F:
          v415 = idInterpreter::GetVariable(retstr: &v1252, this, def: *(idVarDef **)v7);
          v416 = *(idVarDef **)(v7 + 4);
          v830.value.cp = (char *)v415->value.i;
          v417 = idInterpreter::GetVariable(retstr: &v1028, this, def: v416);
          v418 = *(idVarDef **)(v7 + 8);
          v828.value.cp = v417->value.cp;
          v419 = idInterpreter::GetVariable(retstr: &v1148, this, def: v418);
          v420 = *(idVarDef **)(v7 + 4);
          v421 = (float *)v419->value.i;
          if ( idInterpreter::GetScriptObject(this, varDef: v420) != nullptr )
          {
            v422 = varEval_t::GetEntity(this: &v830);
            *(_DWORD *)v4 = varEval_t::GetEntity(this: &v828) != v422;
            LODWORD(v2) = *(_DWORD *)v4;
            v1207 = v2;
            *v421 = (float)v2;
          }
          else
          {
            *(_DWORD *)v4 = varEval_t::GetEntity(this: &v830) != nullptr;
            v1209 = *(_QWORD *)&v4[8];
            *v421 = (float)*(__int64 *)&v4[8];
          }
          goto LABEL_437;
        case 0x40:
          v423 = idInterpreter::GetVariable(retstr: &v1030, this, def: *(idVarDef **)v7);
          v424 = *(idVarDef **)(v7 + 4);
          v830.value.cp = (char *)v423->value.i;
          v425 = idInterpreter::GetVariable(retstr: &v1208, this, def: v424);
          v426 = *(idVarDef **)(v7 + 8);
          v828.value.cp = v425->value.cp;
          v427 = idInterpreter::GetVariable(retstr: &v1032, this, def: v426);
          v428 = *(idVarDef **)v7;
          v429 = (_DWORD *)v427->value.i;
          if ( idInterpreter::GetScriptObject(this, varDef: v428) != nullptr )
          {
            v430 = varEval_t::GetEntity(this: &v830);
            *(_DWORD *)v4 = varEval_t::GetEntity(this: &v828) != v430;
            *v429 = *(_DWORD *)v4;
          }
          else
          {
            *v429 = varEval_t::GetEntity(this: &v828) != nullptr;
          }
          goto LABEL_437;
        case 0x41:
          v431 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1150, this, def: *(idVarDef **)(v7 + 8))->value.i;
          v432 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          v433 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)(v7 + 4));
          *(_DWORD *)v4 = (char *)v433 - (char *)v432 - 1;
          LODWORD(v2) = v433 != v432;
          *v431 = v2;
          goto LABEL_437;
        case 0x42:
          v434 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1034, this, def: *(idVarDef **)v7)->value.i;
          v435 = idInterpreter::GetVariable(retstr: &v1238, this, def: *(idVarDef **)(v7 + 4));
          v436 = *(idVarDef **)(v7 + 8);
          v437 = (_DWORD *)v435->value.i;
          v438 = idInterpreter::GetVariable(retstr: &v1036, this, def: v436);
          *(_DWORD *)v4 = *v434;
          LODWORD(v2) = *v437;
          HIDWORD(v2) = (varEval_t)v438->value.cp;
          LODWORD(v3) = *v437 - *v434;
          HIDWORD(v3) = v3 - 1;
          *v438->value.ip = *v437 != *v434;
          goto LABEL_437;
        case 0x43:
          v206 = (float *)idInterpreter::GetVariable(retstr: &v914, this, def: *(idVarDef **)v7)->value.i;
          v207 = idInterpreter::GetVariable(retstr: &v1256, this, def: *(idVarDef **)(v7 + 4));
          v208 = *(idVarDef **)(v7 + 8);
          v209 = (float *)v207->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v916, this, def: v208)->value.cp;
          *(_DWORD *)&v4[8] = 1;
          if ( *v206 <= (double)*v209 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x44:
          v210 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1092, this, def: *(idVarDef **)v7)->value.i;
          v211 = idInterpreter::GetVariable(retstr: &v918, this, def: *(idVarDef **)(v7 + 4));
          v212 = *(idVarDef **)(v7 + 8);
          v213 = (_DWORD *)v211->value.i;
          v214 = idInterpreter::GetVariable(retstr: &v1180, this, def: v212);
          *(_DWORD *)v4 = *v213;
          LODWORD(v2) = *v210;
          HIDWORD(v2) = (int)*v213 >> 31;
          LODWORD(v3) = (varEval_t)v214->value.cp;
          HIDWORD(v3) = *v210 >> 31;
          *v214->value.ip = HIDWORD(v2) + (*v213 >= *v210) + HIDWORD(v3);
          goto LABEL_437;
        case 0x45:
          v215 = (float *)idInterpreter::GetVariable(retstr: &v920, this, def: *(idVarDef **)v7)->value.i;
          v216 = idInterpreter::GetVariable(retstr: &v1094, this, def: *(idVarDef **)(v7 + 4));
          v217 = *(idVarDef **)(v7 + 8);
          v218 = (_DWORD *)v216->value.i;
          v219 = idInterpreter::GetVariable(retstr: &v922, this, def: v217);
          *(_DWORD *)v4 = *v218;
          v220 = *v215;
          *(varEval_t *)&v4[4] = (varEval_t)v219->value.cp;
          *(_DWORD *)&v4[8] = 1;
          LODWORD(v2) = *v218;
          v1175 = v2;
          if ( v220 <= (float)v2 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x46:
          v221 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1224, this, def: *(idVarDef **)v7)->value.i;
          v222 = idInterpreter::GetVariable(retstr: &v924, this, def: *(idVarDef **)(v7 + 4));
          v223 = *(idVarDef **)(v7 + 8);
          v224 = (float *)v222->value.i;
          v225 = idInterpreter::GetVariable(retstr: &v1096, this, def: v223);
          *(_DWORD *)v4 = *v221;
          v226 = *v224;
          *(varEval_t *)&v4[4] = (varEval_t)v225->value.cp;
          *(_DWORD *)&v4[8] = 1;
          LODWORD(v2) = *v221;
          v1177 = v2;
          if ( (float)v2 <= v226 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x47:
          v185 = (float *)idInterpreter::GetVariable(retstr: &v902, this, def: *(idVarDef **)v7)->value.i;
          v186 = idInterpreter::GetVariable(retstr: &v1176, this, def: *(idVarDef **)(v7 + 4));
          v187 = *(idVarDef **)(v7 + 8);
          v188 = (float *)v186->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v904, this, def: v187)->value.cp;
          *(_DWORD *)&v4[8] = *v185 >= (double)*v188;
          goto LABEL_117;
        case 0x48:
          v189 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1086, this, def: *(idVarDef **)v7)->value.i;
          v190 = idInterpreter::GetVariable(retstr: &v906, this, def: *(idVarDef **)(v7 + 4));
          v191 = *(idVarDef **)(v7 + 8);
          v192 = (_DWORD *)v190->value.i;
          v193 = idInterpreter::GetVariable(retstr: &v1222, this, def: v191);
          *(_DWORD *)v4 = *v189;
          LODWORD(v2) = *v192;
          HIDWORD(v2) = (int)*v189 >> 31;
          LODWORD(v3) = (varEval_t)v193->value.cp;
          HIDWORD(v3) = *v192 >> 31;
          *v193->value.ip = HIDWORD(v2) + (*v189 >= *v192) + HIDWORD(v3);
          goto LABEL_437;
        case 0x49:
          v194 = (float *)idInterpreter::GetVariable(retstr: &v908, this, def: *(idVarDef **)v7)->value.i;
          v195 = idInterpreter::GetVariable(retstr: &v1088, this, def: *(idVarDef **)(v7 + 4));
          v196 = *(idVarDef **)(v7 + 8);
          v197 = (_DWORD *)v195->value.i;
          v198 = idInterpreter::GetVariable(retstr: &v910, this, def: v196);
          *(_DWORD *)v4 = *v197;
          v199 = *v194;
          *(varEval_t *)&v4[4] = (varEval_t)v198->value.cp;
          *(_DWORD *)&v4[8] = 1;
          LODWORD(v2) = *v197;
          v1171 = v2;
          if ( v199 >= (float)v2 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x4A:
          v200 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1178, this, def: *(idVarDef **)v7)->value.i;
          v201 = idInterpreter::GetVariable(retstr: &v912, this, def: *(idVarDef **)(v7 + 4));
          v202 = *(idVarDef **)(v7 + 8);
          v203 = (float *)v201->value.i;
          v204 = idInterpreter::GetVariable(retstr: &v1090, this, def: v202);
          *(_DWORD *)v4 = *v200;
          v205 = *v203;
          *(varEval_t *)&v4[4] = (varEval_t)v204->value.cp;
          *(_DWORD *)&v4[8] = 1;
          LODWORD(v2) = *v200;
          v1173 = v2;
          if ( (float)v2 >= v205 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x4B:
          v248 = (float *)idInterpreter::GetVariable(retstr: &v938, this, def: *(idVarDef **)v7)->value.i;
          v249 = idInterpreter::GetVariable(retstr: &v1226, this, def: *(idVarDef **)(v7 + 4));
          v250 = *(idVarDef **)(v7 + 8);
          v251 = (float *)v249->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v940, this, def: v250)->value.cp;
          *(_DWORD *)&v4[8] = 1;
          if ( *v248 < (double)*v251 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x4C:
          v252 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1104, this, def: *(idVarDef **)v7)->value.i;
          v253 = idInterpreter::GetVariable(retstr: &v942, this, def: *(idVarDef **)(v7 + 4));
          v254 = *(idVarDef **)(v7 + 8);
          v255 = (_DWORD *)v253->value.i;
          v256 = idInterpreter::GetVariable(retstr: &v1186, this, def: v254);
          *(_DWORD *)v4 = *v252;
          LODWORD(v2) = *v255;
          HIDWORD(v2) = (varEval_t)v256->value.cp;
          LODWORD(v3) = *v252 - *v255;
          HIDWORD(v3) = ~(*v255 ^ *v252);
          *v256->value.ip = (((*v255 ^ *v252) >= 0) + (*v252 >= *v255)) & 1;
          goto LABEL_437;
        case 0x4D:
          v257 = (float *)idInterpreter::GetVariable(retstr: &v944, this, def: *(idVarDef **)v7)->value.i;
          v258 = idInterpreter::GetVariable(retstr: &v1106, this, def: *(idVarDef **)(v7 + 4));
          v259 = *(idVarDef **)(v7 + 8);
          v260 = (_DWORD *)v258->value.i;
          v261 = idInterpreter::GetVariable(retstr: &v946, this, def: v259);
          *(_DWORD *)v4 = *v260;
          v262 = *v257;
          *(varEval_t *)&v4[4] = (varEval_t)v261->value.cp;
          *(_DWORD *)&v4[8] = 1;
          LODWORD(v2) = *v260;
          v1183 = v2;
          if ( v262 < (float)v2 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x4E:
          v263 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1262, this, def: *(idVarDef **)v7)->value.i;
          v264 = idInterpreter::GetVariable(retstr: &v948, this, def: *(idVarDef **)(v7 + 4));
          v265 = *(idVarDef **)(v7 + 8);
          v266 = (float *)v264->value.i;
          v267 = idInterpreter::GetVariable(retstr: &v1108, this, def: v265);
          *(_DWORD *)v4 = *v263;
          v268 = *v266;
          *(varEval_t *)&v4[4] = (varEval_t)v267->value.cp;
          *(_DWORD *)&v4[8] = 1;
          LODWORD(v2) = *v263;
          v1185 = v2;
          if ( (float)v2 < v268 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x4F:
          v227 = (float *)idInterpreter::GetVariable(retstr: &v926, this, def: *(idVarDef **)v7)->value.i;
          v228 = idInterpreter::GetVariable(retstr: &v1182, this, def: *(idVarDef **)(v7 + 4));
          v229 = *(idVarDef **)(v7 + 8);
          v230 = (float *)v228->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v928, this, def: v229)->value.cp;
          *(_DWORD *)&v4[8] = 1;
          if ( *v227 > (double)*v230 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x50:
          v231 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1098, this, def: *(idVarDef **)v7)->value.i;
          v232 = idInterpreter::GetVariable(retstr: &v930, this, def: *(idVarDef **)(v7 + 4));
          v233 = *(idVarDef **)(v7 + 8);
          v234 = (_DWORD *)v232->value.i;
          v235 = idInterpreter::GetVariable(retstr: &v1246, this, def: v233);
          *(_DWORD *)v4 = *v231;
          LODWORD(v2) = *v234;
          HIDWORD(v2) = (varEval_t)v235->value.cp;
          LODWORD(v3) = *v234 - *v231;
          HIDWORD(v3) = ~(*v231 ^ *v234);
          *v235->value.ip = (((*v231 ^ *v234) >= 0) + (*v234 >= *v231)) & 1;
          goto LABEL_437;
        case 0x51:
          v236 = (float *)idInterpreter::GetVariable(retstr: &v932, this, def: *(idVarDef **)v7)->value.i;
          v237 = idInterpreter::GetVariable(retstr: &v1100, this, def: *(idVarDef **)(v7 + 4));
          v238 = *(idVarDef **)(v7 + 8);
          v239 = (_DWORD *)v237->value.i;
          v240 = idInterpreter::GetVariable(retstr: &v934, this, def: v238);
          *(_DWORD *)v4 = *v239;
          v241 = *v236;
          *(varEval_t *)&v4[4] = (varEval_t)v240->value.cp;
          *(_DWORD *)&v4[8] = 1;
          LODWORD(v2) = *v239;
          v1179 = v2;
          if ( v241 > (float)v2 )
            goto LABEL_117;
          **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x52:
          v242 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1184, this, def: *(idVarDef **)v7)->value.i;
          v243 = idInterpreter::GetVariable(retstr: &v936, this, def: *(idVarDef **)(v7 + 4));
          v244 = *(idVarDef **)(v7 + 8);
          v245 = (float *)v243->value.i;
          v246 = idInterpreter::GetVariable(retstr: &v1102, this, def: v244);
          *(_DWORD *)v4 = *v242;
          v247 = *v245;
          *(varEval_t *)&v4[4] = (varEval_t)v246->value.cp;
          *(_DWORD *)&v4[8] = 1;
          LODWORD(v2) = *v242;
          v1181 = v2;
          if ( (float)v2 > v247 )
LABEL_117:
            **(_DWORD **)&v4[4] = *(_DWORD *)&v4[8];
          else
            **(_DWORD **)&v4[4] = 0;
          goto LABEL_437;
        case 0x53:
          v175 = (_DWORD *)idInterpreter::GetVariable(retstr: &v896, this, def: *(idVarDef **)v7)->value.i;
          v176 = idInterpreter::GetVariable(retstr: &v1082, this, def: *(idVarDef **)(v7 + 4));
          v177 = *(idVarDef **)(v7 + 8);
          v178 = (_DWORD *)v176->value.i;
          v179 = idInterpreter::GetVariable(retstr: &v898, this, def: v177);
          *(_DWORD *)v4 = *v175;
          LODWORD(v2) = *v178;
          HIDWORD(v2) = (varEval_t)v179->value.cp;
          LODWORD(v3) = *v175 & *v178;
          *v179->value.ip = v3;
          goto LABEL_437;
        case 0x54:
          v180 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1244, this, def: *(idVarDef **)v7)->value.i;
          v181 = idInterpreter::GetVariable(retstr: &v900, this, def: *(idVarDef **)(v7 + 4));
          v182 = *(idVarDef **)(v7 + 8);
          v183 = (_DWORD *)v181->value.i;
          v184 = idInterpreter::GetVariable(retstr: &v1084, this, def: v182);
          *(_DWORD *)v4 = *v180;
          LODWORD(v2) = *v183;
          HIDWORD(v2) = (varEval_t)v184->value.cp;
          LODWORD(v3) = *v180 | *v183;
          *v184->value.ip = v3;
          goto LABEL_437;
        case 0x55:
          v269 = (_DWORD *)idInterpreter::GetVariable(retstr: &v950, this, def: *(idVarDef **)v7)->value.i;
          v270 = idInterpreter::GetVariable(retstr: &v1188, this, def: *(idVarDef **)(v7 + 4));
          v271 = *(idVarDef **)(v7 + 8);
          v272 = (_DWORD *)v270->value.i;
          v273 = idInterpreter::GetVariable(retstr: &v952, this, def: v271);
          *(_DWORD *)v4 = *v269;
          if ( *v269 == 0 || (v274 = 1, *v272 == 0) )
            v274 = 0;
          *v273->value.ip = v274;
          goto LABEL_437;
        case 0x56:
          v275 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1110, this, def: *(idVarDef **)v7)->value.i;
          v276 = idInterpreter::GetVariable(retstr: &v954, this, def: *(idVarDef **)(v7 + 4));
          v277 = *(idVarDef **)(v7 + 8);
          v278 = (_DWORD *)v276->value.i;
          v279 = idInterpreter::GetVariable(retstr: &v1228, this, def: v277);
          *(_DWORD *)v4 = *v275;
          if ( *v275 != 0 || (v280 = 0, *v278 != 0) )
            v280 = 1;
          *v279->value.ip = v280;
          goto LABEL_437;
        case 0x57:
          v672 = (float *)idInterpreter::GetVariable(retstr: &v1051, this, def: *(idVarDef **)(v7 + 8))->value.i;
          v673 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( v673 == nullptr )
            goto LABEL_393;
          *(_DWORD *)v4 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4);
          *v672 = *(float *)((char *)v673->m_graphs.m_data + *(_DWORD *)v4);
          goto LABEL_437;
        case 0x58:
          v672 = (float *)idInterpreter::GetVariable(retstr: &v1057, this, def: *(idVarDef **)(v7 + 8))->value.i;
          v678 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( v678 != nullptr )
          {
            v679 = (float *)((char *)v678->m_graphs.m_data + *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4));
            *v672 = *v679;
            v672[1] = v679[1];
            v672[2] = v679[2];
          }
          else
          {
            v672[2] = 0.0;
            v672[1] = 0.0;
LABEL_393:
            *v672 = 0.0;
          }
          goto LABEL_437;
        case 0x59:
          v677 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          v619 = *(_DWORD *)(v7 + 8);
          if ( v677 != nullptr )
          {
            v618 = (char *)v677->m_graphs.m_data + *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4);
            if ( *(_DWORD *)(v619 + 16) != 3 )
              goto LABEL_311;
          }
          else
          {
            v618 = &byte_8200D768;
            if ( *(_DWORD *)(v619 + 16) != 3 )
            {
LABEL_311:
              idStr::Copynz(dest: *(char **)(v619 + 4), src: v618, destsize: 256);
              goto LABEL_437;
            }
          }
LABEL_389:
          idStr::Copynz(
            dest: (char *)&this->localstack.stack[*(_DWORD *)(v619 + 4) + this->localstack.stackBase],
            src: v618,
            destsize: 256);
LABEL_437:
          if ( this->doneProcessing )
            return this->threadDying;
          v5 = v833;
          break;
        case 0x5A:
          v670 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1053, this, def: *(idVarDef **)(v7 + 8))->value.i;
          v674 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( v674 == nullptr )
            goto LABEL_378;
          *(_DWORD *)v4 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4);
          LODWORD(v2) = *(bfx::VolumeGraph **)((char *)v674->m_graphs.m_data + *(_DWORD *)v4);
          *v670 = v2;
          goto LABEL_437;
        case 0x5B:
          v675 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1055, this, def: *(idVarDef **)(v7 + 8))->value.i;
          v676 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( v676 == nullptr )
            goto LABEL_397;
          *(_DWORD *)v4 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4);
          LODWORD(v2) = *(bfx::VolumeGraph **)((char *)v676->m_graphs.m_data + *(_DWORD *)v4);
          *v675 = v2;
          goto LABEL_437;
        case 0x5C:
          v675 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1059, this, def: *(idVarDef **)(v7 + 8))->value.i;
          *(_DWORD *)&v4[8] = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( *(_DWORD *)&v4[8] != 0 )
          {
            *v675 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v7 + 4) + 4) + *(_DWORD *)(*(_DWORD *)&v4[8] + 8));
            if ( idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)(v7 + 8)) == nullptr )
LABEL_397:
              *v675 = 0x1FFF;
          }
          else
          {
            *v675 = 0x1FFF;
          }
          goto LABEL_437;
        case 0x5D:
          v680 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1061, this, def: *(idVarDef **)(v7 + 8))->value.i;
          v681 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( v681 != nullptr )
          {
            *(_DWORD *)v4 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4);
            LODWORD(v2) = *(bfx::VolumeGraph **)((char *)v681->m_graphs.m_data + *(_DWORD *)v4);
            *v680 = v2;
          }
          goto LABEL_437;
        case 0x5E:
          v670 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1063, this, def: *(idVarDef **)(v7 + 8))->value.i;
          v682 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( v682 == nullptr )
            goto LABEL_378;
          *(_DWORD *)v4 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4);
          LODWORD(v2) = *(bfx::VolumeGraph **)((char *)v682->m_graphs.m_data + *(_DWORD *)v4);
          *v670 = v2;
          goto LABEL_437;
        case 0x5F:
          v670 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1049, this, def: *(idVarDef **)(v7 + 8))->value.i;
          v671 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( v671 != nullptr )
          {
            *(_DWORD *)&v4[4] = *(_DWORD *)(v7 + 4);
            *(_DWORD *)v4 = v6 + 1;
            *(_DWORD *)&v4[8] = v671->m_graphs.m_data;
            v833 = v6 + 1;
            LODWORD(v2) = *(_DWORD *)(*(_DWORD *)&v4[4] + 4) + *(_DWORD *)&v4[8];
            *v670 = v2;
          }
          else
          {
LABEL_378:
            *v670 = 0;
          }
          goto LABEL_437;
        case 0x60:
          *(_DWORD *)&v4[4] = *(_DWORD *)v7;
          HIDWORD(v3) = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4);
          idInterpreter::CallEvent(
            this,
            func: *(const function_t **)(*(_DWORD *)v7 + 4),
            argsize: v3,
            a4: v2,
            a5: *(__int64 *)v4);
          goto LABEL_437;
        case 0x61:
          v21 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( v21 != nullptr )
          {
            v22 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4);
            TypeDef = (idTypeDef *)idScriptObject::GetTypeDef(this: v21);
            Function = (idDecl *)idTypeDef::GetFunction(this: TypeDef, funcNumber: v22);
            idInterpreter::EnterFunction(this, func: Function, clearStack: v27, a4: v26, a5: v25);
          }
          else
          {
            v28 = gameLocal->program.returnStringDef->value.value.cp;
            *gameLocal->program.returnDef->value.value.vp = vec3_origin;
            idStr::Copynz(dest: v28, src: &byte_8200D768, destsize: 256);
            HIDWORD(v3) = *(_DWORD *)(v7 + 8);
            *(_DWORD *)&v4[8] = this->localstack.stackUsed;
            *(_DWORD *)&v4[4] = *(_DWORD *)(HIDWORD(v3) + 4);
            if ( *(int *)&v4[8] < *(int *)&v4[4] )
              goto _LN2438;
            this->localstack.stackUsed = *(_DWORD *)&v4[8] - *(_DWORD *)&v4[4];
          }
          goto LABEL_437;
        case 0x62:
          *(_DWORD *)&v4[4] = *(_DWORD *)v7;
          HIDWORD(v3) = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4);
          idInterpreter::CallSysEvent(
            this,
            func: *(const function_t **)(*(_DWORD *)v7 + 4),
            argsize: v3,
            a4: v2,
            a5: *(__int64 *)v4);
          goto LABEL_437;
        case 0x63:
          *(_DWORD *)&v4[4] = *(_DWORD *)v7;
          HIDWORD(v3) = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4);
          idInterpreter::CallScriptEvent(
            this,
            func: *(const function_t **)(*(_DWORD *)v7 + 4),
            argsize: v3,
            a4: v2,
            a5: *(__int64 *)v4);
          goto LABEL_437;
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:
        case 0x68:
        case 0x69:
        case 0x6A:
          v806.cp = (char *)idInterpreter::GetVariable(retstr: &v1151, this, def: *(idVarDef **)v7)->value;
          v807 = (float *)idInterpreter::GetVariable(retstr: &v1153, this, def: *(idVarDef **)(v7 + 4))->value.i;
          v808 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1155, this, def: *(idVarDef **)(v7 + 8))->value.i;
          if ( *(_DWORD *)(*(_DWORD *)v7 + 16) == 3 )
          {
            *(_DWORD *)(*(_DWORD *)(v7 + 8) + 16) = 4;
            v809 = *(bfx::SystemInstance **)(*(_DWORD *)v7 + 20);
            v810 = *(_DWORD *)(*(_DWORD *)v7 + 4);
            CachedSize = idreports::MapWarning::GetCachedSize(this: v809);
            v2 = __PAIR64__(v810, (unsigned int)CachedSize);
            v812 = *v807;
            v1257 = __PAIR64__(v810, (unsigned int)CachedSize);
            v1259 = *(__int64 *)((char *)&v2 + 4);
            *v808 = (int)(float)((float)((float)__SPAIR64__(v810, (unsigned int)CachedSize) * (float)v812)
                               + (float)*(__int64 *)((char *)&v2 + 4));
          }
          else
          {
            v813 = idreports::MapWarning::GetCachedSize(this: *(bfx::SystemInstance **)(*(_DWORD *)v7 + 20));
            *(_DWORD *)v4 = 5;
            v814 = *v807;
            v1261 = __PAIR64__((unsigned int)v806.cp, (unsigned int)v813);
            v1263 = (unsigned int)v806.cp | 0x500000000LL;
            *v808 = (int)(float)((float)((float)__SPAIR64__((unsigned int)v806.cp, (unsigned int)v813) * (float)v814)
                               + (float)v1263);
            LODWORD(v2) = *(_DWORD *)(v7 + 8);
            *(_DWORD *)(v2 + 16) = 5;
          }
          goto LABEL_437;
        case 0x6B:
        case 0x6C:
        case 0x6D:
        case 0x6E:
        case 0x6F:
        case 0x70:
        case 0x71:
          v815.cp = (char *)idInterpreter::GetVariable(retstr: &v1157, this, def: *(idVarDef **)v7)->value;
          v816 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1159, this, def: *(idVarDef **)(v7 + 4))->value.i;
          v817 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1161, this, def: *(idVarDef **)(v7 + 8))->value.i;
          if ( *(_DWORD *)(*(_DWORD *)v7 + 16) == 3 )
          {
            *(_DWORD *)(*(_DWORD *)(v7 + 8) + 16) = 4;
            v818 = *(bfx::SystemInstance **)(*(_DWORD *)v7 + 20);
            v819 = *(_DWORD *)(*(_DWORD *)v7 + 4);
            v820 = idreports::MapWarning::GetCachedSize(this: v818);
            LODWORD(v2) = *v816;
            HIDWORD(v2) = (_DWORD)v820 * *v816 + v819;
            *v817 = HIDWORD(v2);
          }
          else
          {
            *(_DWORD *)v4 = (_DWORD)idreports::MapWarning::GetCachedSize(this: *(bfx::SystemInstance **)(*(_DWORD *)v7 + 20))
                          * *v816
                          + v815.i;
            *v817 = *(_DWORD *)v4;
            LODWORD(v2) = *(_DWORD *)(v7 + 8);
            *(_DWORD *)(v2 + 16) = 5;
          }
          goto LABEL_437;
        case 0x72:
          v586 = idInterpreter::GetVariable(retstr: &v941, this, def: *(idVarDef **)v7);
          v587 = *(idVarDef **)(v7 + 4);
          v588 = (float *)v586->value.i;
          *idInterpreter::GetVariable(retstr: &v943, this, def: v587)->value.fp = *v588;
          goto LABEL_437;
        case 0x73:
          v620 = idInterpreter::GetVariable(retstr: &v973, this, def: *(idVarDef **)v7);
          v621 = *(idVarDef **)(v7 + 4);
          v622 = (float *)v620->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v975, this, def: v621)->value.cp;
          **(float **)&v4[4] = *v622;
          *(float *)(*(_DWORD *)&v4[4] + 4) = v622[1];
          *(float *)(*(_DWORD *)&v4[4] + 8) = v622[2];
          goto LABEL_437;
        case 0x75:
          v617 = *(idVarDef **)v7;
          if ( *(_DWORD *)(*(_DWORD *)v7 + 16) == 3 )
            v618 = (const char *)&this->localstack.stack[v617->value.value.i + this->localstack.stackBase];
          else
            v618 = v617->value.value.cp;
          v619 = *(_DWORD *)(v7 + 4);
          if ( *(_DWORD *)(v619 + 16) != 3 )
            goto LABEL_311;
          goto LABEL_389;
        case 0x76:
          v589 = idInterpreter::GetVariable(retstr: &v945, this, def: *(idVarDef **)v7);
          v590 = *(idVarDef **)(v7 + 4);
          v591 = (int *)v589->value.i;
          v592 = idInterpreter::GetVariable(retstr: &v947, this, def: v590);
          *(varEval_t *)v4 = (varEval_t)v592->value.cp;
          *v592->value.ip = *v591;
          goto LABEL_437;
        case 0x77:
          v593 = idInterpreter::GetVariable(retstr: &v949, this, def: *(idVarDef **)v7);
          v594 = *(idVarDef **)(v7 + 4);
          v595 = (int *)v593->value.i;
          v596 = idInterpreter::GetVariable(retstr: &v951, this, def: v594);
          *(varEval_t *)v4 = (varEval_t)v596->value.cp;
          *v596->value.ip = *v595;
          goto LABEL_437;
        case 0x78:
          v597 = (int *)idInterpreter::GetVariable(retstr: &v953, this, def: *(idVarDef **)v7)->value.i;
          v598 = idInterpreter::GetVariable(retstr: &v955, this, def: *(idVarDef **)(v7 + 4));
          v599 = (int *)v598->value.i;
          ScriptList = idGameLocal::GetScriptList(this: gameLocal, idToGet: *v598->value.ip);
          if ( ScriptList != nullptr )
          {
            v601 = idVarDef::Name(this: *(idVarDef **)(v7 + 4));
            v602 = idStr::Icmp(s1: v601, s2: v832);
            *(_DWORD *)&v4[8] = ScriptList->isMember;
            if ( v602 != 0 )
            {
              if ( !ScriptList->isMember )
                goto LABEL_292;
              idInterpreter::Error(
                this,
                fmt: "Tried to use = on a member variable.  Use member.copy( list )",
                a3: v3,
                a4: v2,
                a5: *(__int64 *)v4,
                a6: v822,
                a7: v823,
                a8: v824,
                a9: v825,
                a10: v826,
                a11: v827);
            }
            if ( *(_DWORD *)&v4[8] == 0 )
LABEL_292:
              ((void (__fastcall *)(idScriptList *, int))ScriptList->dtr_idClass)(a1: ScriptList, a2: 1);
          }
          *v599 = *v597;
          goto LABEL_437;
        case 0x79:
          v607 = (_DWORD *)idInterpreter::GetVariable(retstr: &v961, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7) != nullptr )
            *v607 = *idInterpreter::GetVariable(retstr: &v963, this, def: *(idVarDef **)v7)->value.ip;
          else
            *v607 = 0x1FFF;
          goto LABEL_437;
        case 0x7A:
          v613 = idInterpreter::GetVariable(retstr: &v969, this, def: *(idVarDef **)v7);
          v614 = *(idVarDef **)(v7 + 4);
          v615 = (int *)v613->value.i;
          v616 = idInterpreter::GetVariable(retstr: &v971, this, def: v614);
          *(varEval_t *)v4 = (varEval_t)v616->value.cp;
          *v616->value.ip = *v615;
          goto LABEL_437;
        case 0x7B:
          v603 = (_DWORD *)idInterpreter::GetVariable(retstr: &v957, this, def: *(idVarDef **)(v7 + 4))->value.i;
          v604 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( v604 != nullptr )
          {
            v605 = *(const idTypeDef **)(*(_DWORD *)(v7 + 4) + 20);
            v606 = (idTypeDef *)idScriptObject::GetTypeDef(this: v604);
            if ( idTypeDef::Inherits(this: v606, basetype: v605) )
              *v603 = *idInterpreter::GetVariable(retstr: &v959, this, def: *(idVarDef **)v7)->value.ip;
            else
              *v603 = 0x1FFF;
          }
          else
          {
            *v603 = 0x1FFF;
          }
          goto LABEL_437;
        case 0x7C:
          v608 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          v609 = (_DWORD *)idInterpreter::GetVariable(retstr: &v965, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( v608 != nullptr
            && (v610 = v608,
                v611 = *(const idTypeDef **)(*(_DWORD *)(v7 + 4) + 20),
                v612 = (idTypeDef *)idScriptObject::GetTypeDef(this: v610),
                idTypeDef::Inherits(this: v612, basetype: v611)) )
          {
            *v609 = *idInterpreter::GetVariable(retstr: &v967, this, def: *(idVarDef **)v7)->value.ip;
          }
          else
          {
            *v609 = 0x1FFF;
          }
          goto LABEL_437;
        case 0x7D:
          v632 = idInterpreter::GetVariable(retstr: &v983, this, def: *(idVarDef **)v7);
          v633 = *(idVarDef **)(v7 + 4);
          v634 = (float *)v632->value.i;
          *idInterpreter::GetVariable(retstr: &v985, this, def: v633)->value.ip = (int)*v634;
          goto LABEL_437;
        case 0x7E:
          v623 = idInterpreter::GetVariable(retstr: &v977, this, def: *(idVarDef **)v7);
          v624 = idInterpreter::FloatToString(this, value: *v623->value.fp);
          v619 = *(_DWORD *)(v7 + 4);
          v618 = v624;
          if ( *(_DWORD *)(v619 + 16) == 3 )
            goto LABEL_389;
          goto LABEL_311;
        case 0x7F:
          v630 = (idAngles **)idInterpreter::GetVariable(retstr: &v981, this, def: *(idVarDef **)v7);
          v631 = idVec3::ToString(this: *v630, precision: 2);
          v619 = *(_DWORD *)(v7 + 4);
          v618 = v631;
          if ( *(_DWORD *)(v619 + 16) == 3 )
            goto LABEL_389;
          goto LABEL_311;
        case 0x81:
          v625 = idInterpreter::GetVariable(retstr: &v979, this, def: *(idVarDef **)v7);
          LODWORD(v626) = (varEval_t)v625->value.cp;
          HIDWORD(v627) = *v625->value.ip;
          v629 = va::va(
                   this: &v1266,
                   fmt: "%d",
                   a3: v627,
                   a4: v628,
                   a5: v626,
                   a6: v822,
                   a7: v823,
                   a8: v824,
                   a9: v825,
                   a10: v826,
                   a11: v827);
          v619 = *(_DWORD *)(v7 + 4);
          v618 = (const char *)v629;
          if ( *(_DWORD *)(v619 + 16) == 3 )
            goto LABEL_389;
          goto LABEL_311;
        case 0x82:
          v635 = idInterpreter::GetVariable(retstr: &v987, this, def: *(idVarDef **)v7);
          v636 = *(idVarDef **)(v7 + 4);
          v637 = (_DWORD *)v635->value.i;
          *(varEval_t *)v4 = (varEval_t)idInterpreter::GetVariable(retstr: &v989, this, def: v636)->value.cp;
          LODWORD(v2) = *v637;
          v1233 = v2;
          **(float **)v4 = (float)v2;
          goto LABEL_437;
        case 0x83:
          v638 = (float **)idInterpreter::GetVariable(retstr: &v991, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( v638 != nullptr && *v638 != nullptr )
            **v638 = *idInterpreter::GetVariable(retstr: &v993, this, def: *(idVarDef **)v7)->value.fp;
          goto LABEL_437;
        case 0x84:
          v650 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1013, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( v650 != nullptr && *v650 != 0 )
          {
            v651 = idInterpreter::GetVariable(retstr: &v1015, this, def: *(idVarDef **)v7);
            *(varEval_t *)&v4[8] = (varEval_t)v651->value.cp;
            *(_DWORD *)&v4[4] = *v650;
            **(float **)&v4[4] = *v651->value.fp;
            *(float *)(*(_DWORD *)&v4[4] + 4) = *(float *)(*(_DWORD *)&v4[8] + 4);
            *(float *)(*(_DWORD *)&v4[4] + 8) = *(float *)(*(_DWORD *)&v4[8] + 8);
          }
          goto LABEL_437;
        case 0x85:
          *(varEval_t *)&v4[8] = (varEval_t)idInterpreter::GetVariable(
                                              retstr: &v1011,
                                              this,
                                              def: *(idVarDef **)(v7 + 4))->value.cp;
          if ( *(_DWORD *)&v4[8] != 0 )
          {
            v648 = **(char ***)&v4[8];
            if ( **(_DWORD **)&v4[8] != 0 )
            {
              v649 = *(idVarDef **)v7;
              if ( *(_DWORD *)(*(_DWORD *)v7 + 16) == 3 )
                idStr::Copynz(
                  dest: v648,
                  src: (const char *)&this->localstack.stack[v649->value.value.i + this->localstack.stackBase],
                  destsize: 256);
              else
                idStr::Copynz(dest: v648, src: v649->value.value.cp, destsize: 256);
            }
          }
          goto LABEL_437;
        case 0x86:
          v639 = (_DWORD **)idInterpreter::GetVariable(retstr: &v995, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( v639 != nullptr && *v639 != nullptr )
          {
            *(_DWORD *)v4 = *idInterpreter::GetVariable(retstr: &v997, this, def: *(idVarDef **)v7)->value.ip;
            **v639 = *(_DWORD *)v4;
          }
          goto LABEL_437;
        case 0x87:
          v640 = (_DWORD **)idInterpreter::GetVariable(retstr: &v999, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( v640 != nullptr )
          {
            *(_DWORD *)v4 = *idInterpreter::GetVariable(retstr: &v1001, this, def: *(idVarDef **)v7)->value.ip;
            **v640 = *(_DWORD *)v4;
          }
          goto LABEL_437;
        case 0x88:
          v641 = (varEval_t::<unnamed_type_value> *)idInterpreter::GetVariable(
                                                      retstr: &v1003,
                                                      this,
                                                      def: *(idVarDef **)(v7 + 4))->value.i;
          v642 = (int *)idInterpreter::GetVariable(retstr: &v1005, this, def: *(idVarDef **)v7)->value.i;
          if ( v641 == nullptr || v641->i == 0 )
            goto LABEL_437;
          v643 = *v641->ip;
          v828.value.cp = v641->cp;
          v644 = idGameLocal::GetScriptList(this: gameLocal, idToGet: v643);
          if ( v644 != nullptr )
          {
            v645 = idVarDef::Name(this: *(idVarDef **)(v7 + 4));
            v646 = idStr::Icmp(s1: v645, s2: v832);
            *(_DWORD *)&v4[8] = v644->isMember;
            if ( v646 != 0 )
            {
              if ( !v644->isMember )
                goto LABEL_336;
              idInterpreter::Error(
                this,
                fmt: "Tried to use = on a member variable.  Use member.copy( list )",
                a3: v3,
                a4: v2,
                a5: *(__int64 *)v4,
                a6: v822,
                a7: v823,
                a8: v824,
                a9: v825,
                a10: v826,
                a11: v827);
            }
            if ( *(_DWORD *)&v4[8] == 0 )
LABEL_336:
              ((void (__fastcall *)(idScriptList *, int))v644->dtr_idClass)(a1: v644, a2: 1);
          }
          *v641->ip = *v642;
          goto LABEL_437;
        case 0x89:
          v647 = (_DWORD **)idInterpreter::GetVariable(retstr: &v1007, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( v647 != nullptr && *v647 != nullptr )
          {
            *(_DWORD *)v4 = *idInterpreter::GetVariable(retstr: &v1009, this, def: *(idVarDef **)v7)->value.ip;
            **v647 = *(_DWORD *)v4;
          }
          goto LABEL_437;
        case 0x8A:
          v665 = (_DWORD **)idInterpreter::GetVariable(retstr: &v1037, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( v665 == nullptr )
            goto LABEL_437;
          if ( idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7) == nullptr )
            goto LABEL_371;
          *(_DWORD *)v4 = *idInterpreter::GetVariable(retstr: &v1039, this, def: *(idVarDef **)v7)->value.ip;
          **v665 = *(_DWORD *)v4;
          goto LABEL_437;
        case 0x8B:
          v669 = (_DWORD **)idInterpreter::GetVariable(retstr: &v1045, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( v669 != nullptr && *v669 != nullptr )
          {
            *(_DWORD *)v4 = *idInterpreter::GetVariable(retstr: &v1047, this, def: *(idVarDef **)v7)->value.ip;
            **v669 = *(_DWORD *)v4;
          }
          goto LABEL_437;
        case 0x8C:
          v665 = (_DWORD **)idInterpreter::GetVariable(retstr: &v1041, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( v665 == nullptr )
            goto LABEL_437;
          v666 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( v666 != nullptr )
          {
            v667 = *(const idTypeDef **)(*(_DWORD *)(v7 + 8) + 20);
            v668 = (idTypeDef *)idScriptObject::GetTypeDef(this: v666);
            if ( idTypeDef::Inherits(this: v668, basetype: v667) )
            {
              *(_DWORD *)v4 = *idInterpreter::GetVariable(retstr: &v1043, this, def: *(idVarDef **)v7)->value.ip;
              **v665 = *(_DWORD *)v4;
            }
            else
            {
LABEL_371:
              **v665 = 0x1FFF;
            }
          }
          else
          {
            **v665 = 0x1FFF;
          }
          goto LABEL_437;
        case 0x8D:
          v662 = (_DWORD **)idInterpreter::GetVariable(retstr: &v1029, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( v662 != nullptr && *v662 != nullptr )
            **v662 = (int)*idInterpreter::GetVariable(retstr: &v1031, this, def: *(idVarDef **)v7)->value.fp;
          goto LABEL_437;
        case 0x8E:
          v663 = (_DWORD *)idInterpreter::GetVariable(retstr: &v1033, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( v663 != nullptr && *v663 != 0 )
          {
            v664 = idInterpreter::GetVariable(retstr: &v1035, this, def: *(idVarDef **)v7);
            *(_DWORD *)&v4[4] = *v663;
            *(_DWORD *)v4 = *v664->value.ip;
            LODWORD(v2) = *(_DWORD *)v4;
            v1235 = v2;
            **(float **)&v4[4] = (float)v2;
          }
          goto LABEL_437;
        case 0x8F:
          v656 = (char **)idInterpreter::GetVariable(retstr: &v1021, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( v656 != nullptr && *v656 != nullptr )
          {
            v657 = idInterpreter::GetVariable(retstr: &v1023, this, def: *(idVarDef **)v7);
            idStr::snPrintf(dest: *v656, size: 256, fmt: "%d", *v657->value.ip);
          }
          goto LABEL_437;
        case 0x90:
          v652 = (char **)idInterpreter::GetVariable(retstr: &v1017, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( v652 != nullptr && *v652 != nullptr )
          {
            v653 = idInterpreter::GetVariable(retstr: &v1019, this, def: *(idVarDef **)v7);
            v654 = *v652;
            v655 = idInterpreter::FloatToString(this, value: *v653->value.fp);
            idStr::Copynz(dest: v654, src: v655, destsize: 256);
          }
          goto LABEL_437;
        case 0x91:
          v658 = (char **)idInterpreter::GetVariable(retstr: &v1025, this, def: *(idVarDef **)(v7 + 4))->value.i;
          if ( v658 != nullptr && *v658 != nullptr )
          {
            v659 = (idAngles **)idInterpreter::GetVariable(retstr: &v1027, this, def: *(idVarDef **)v7);
            v660 = *v658;
            v661 = idVec3::ToString(this: *v659, precision: 2);
            idStr::Copynz(dest: v660, src: v661, destsize: 256);
          }
          goto LABEL_437;
        case 0x92:
          v477 = idInterpreter::GetVariable(retstr: &v845, this, def: *(idVarDef **)v7);
          v478 = *(idVarDef **)(v7 + 4);
          v479 = (float *)v477->value.i;
          v480 = idInterpreter::GetVariable(retstr: &v847, this, def: v478);
          *v480->value.fp = *v479 * *v480->value.fp;
          goto LABEL_437;
        case 0x93:
          v481 = idInterpreter::GetVariable(retstr: &v849, this, def: *(idVarDef **)v7);
          v482 = *(idVarDef **)(v7 + 4);
          v483 = (_DWORD *)v481->value.i;
          v484 = idInterpreter::GetVariable(retstr: &v851, this, def: v482);
          *(_DWORD *)v4 = *v483;
          LODWORD(v2) = *v484->value.ip;
          HIDWORD(v2) = *v483 * v2;
          *v484->value.ip = HIDWORD(v2);
          goto LABEL_437;
        case 0x94:
          v485 = idInterpreter::GetVariable(retstr: &v853, this, def: *(idVarDef **)v7);
          v486 = *(idVarDef **)(v7 + 4);
          v487 = (_DWORD *)v485->value.i;
          *(varEval_t *)v4 = (varEval_t)idInterpreter::GetVariable(retstr: &v855, this, def: v486)->value.cp;
          LODWORD(v2) = *v487;
          v1215 = v2;
          **(float **)v4 = (float)v2 * **(float **)v4;
          goto LABEL_437;
        case 0x95:
          v488 = idInterpreter::GetVariable(retstr: &v857, this, def: *(idVarDef **)v7);
          v489 = *(idVarDef **)(v7 + 4);
          v490 = (float *)v488->value.i;
          v491 = idInterpreter::GetVariable(retstr: &v859, this, def: v489);
          *(varEval_t *)&v4[8] = (varEval_t)v491->value.cp;
          v492 = (float)(*v490 * *(float *)(v491->value.i + 4));
          v493 = (float)(*v490 * *(float *)(v491->value.i + 8));
          **(float **)&v4[8] = *v490 * *v491->value.fp;
          *(float *)(*(_DWORD *)&v4[8] + 4) = v492;
          *(float *)(*(_DWORD *)&v4[8] + 8) = v493;
          goto LABEL_437;
        case 0x96:
          v494 = idInterpreter::GetVariable(retstr: &v861, this, def: *(idVarDef **)v7);
          v495 = *(idVarDef **)(v7 + 4);
          v496 = (_DWORD *)v494->value.i;
          *(varEval_t *)&v4[8] = (varEval_t)idInterpreter::GetVariable(retstr: &v863, this, def: v495)->value.cp;
          *(_DWORD *)v4 = *v496;
          v1217 = *(_QWORD *)&v4[8];
          v497 = *(float *)(*(_DWORD *)&v4[8] + 4);
          v498 = *(float *)(*(_DWORD *)&v4[8] + 8);
          **(float **)&v4[8] = (float)*(__int64 *)&v4[8] * **(float **)&v4[8];
          *(float *)(*(_DWORD *)&v4[8] + 4) = (float)*(__int64 *)&v4[8] * (float)v497;
          *(float *)(*(_DWORD *)&v4[8] + 8) = (float)*(__int64 *)&v4[8] * (float)v498;
          goto LABEL_437;
        case 0x97:
          v499 = idInterpreter::GetVariable(retstr: &v865, this, def: *(idVarDef **)v7);
          v500 = *(idVarDef **)(v7 + 4);
          v501 = (float *)v499->value.i;
          v502 = idInterpreter::GetVariable(retstr: &v867, this, def: v500);
          v503 = *v501;
          v147 = (float *)v502->value.i;
          if ( v503 == 0.0 )
            goto LABEL_248;
          *v147 = *v147 / (float)v503;
          goto LABEL_437;
        case 0x98:
          v504 = idInterpreter::GetVariable(retstr: &v869, this, def: *(idVarDef **)v7);
          v505 = *(idVarDef **)(v7 + 4);
          v506 = (signed int *)v504->value.i;
          v507 = idInterpreter::GetVariable(retstr: &v871, this, def: v505);
          v508 = *v506;
          v157 = *v506 != 0;
          v156 = (int *)v507->value.i;
          if ( v157 )
          {
            *(_DWORD *)v4 = *v156;
            __twllei(v508, 0);
            LODWORD(v2) = *(_DWORD *)v4 / v508;
            HIDWORD(v2) = __ROL4__(*(_DWORD *)v4, 1) - 1;
            *v156 = *(_DWORD *)v4 / v508;
            LODWORD(v3) = v508 & ~HIDWORD(v2);
            __twlgei(v3, 0xFFFFFFFF);
          }
          else
          {
LABEL_107:
            idInterpreter::Warning(
              this,
              fmt: "Divide by zero",
              a3: v3,
              a4: v153,
              a5: v152,
              a6: v822,
              a7: v823,
              a8: v824,
              a9: v825,
              a10: v826,
              a11: v827);
            *v156 = (int)1.0e30;
          }
          goto LABEL_437;
        case 0x99:
          v509 = idInterpreter::GetVariable(retstr: &v873, this, def: *(idVarDef **)v7);
          v510 = *(idVarDef **)(v7 + 4);
          v511 = (_DWORD *)v509->value.i;
          v512 = idInterpreter::GetVariable(retstr: &v875, this, def: v510);
          *(_DWORD *)&v4[8] = *v511;
          v157 = *v511 != 0;
          v147 = (float *)v512->value.i;
          if ( v157 )
          {
            v513 = *v147;
            v1219 = *(_QWORD *)&v4[4];
            *v147 = (float)v513 / (float)*(__int64 *)&v4[4];
          }
          else
          {
LABEL_248:
            idInterpreter::Warning(
              this,
              fmt: "Divide by zero",
              a3: v3,
              a4: v2,
              a5: *(__int64 *)v4,
              a6: v822,
              a7: v823,
              a8: v824,
              a9: v825,
              a10: v826,
              a11: v827);
            *v147 = 1900671690;
          }
          goto LABEL_437;
        case 0x9A:
          v514 = idInterpreter::GetVariable(retstr: &v877, this, def: *(idVarDef **)v7);
          v515 = *(idVarDef **)(v7 + 4);
          v516 = (float *)v514->value.i;
          v517 = idInterpreter::GetVariable(retstr: &v879, this, def: v515);
          v518 = *v516;
          v519 = (float *)v517->value.i;
          if ( v518 == 0.0 )
            goto LABEL_251;
          v520 = (float)((float)1.0 / (float)v518);
          v521 = v519[1];
          v522 = v519[2];
          *v519 = (float)v520 * *v519;
          v519[1] = (float)v520 * (float)v521;
          v519[2] = (float)v520 * (float)v522;
          goto LABEL_437;
        case 0x9B:
          v523 = idInterpreter::GetVariable(retstr: &v881, this, def: *(idVarDef **)v7);
          v524 = *(idVarDef **)(v7 + 4);
          v525 = (_DWORD *)v523->value.i;
          v526 = idInterpreter::GetVariable(retstr: &v883, this, def: v524);
          *(_DWORD *)&v4[8] = *v525;
          v157 = *v525 != 0;
          v519 = (float *)v526->value.i;
          if ( v157 )
          {
            v527 = *v519;
            v528 = v519[1];
            v1221 = *(_QWORD *)&v4[4];
            v529 = v519[2];
            *v519 = (float)((float)1.0 / (float)*(__int64 *)&v4[4]) * (float)v527;
            v519[1] = (float)((float)1.0 / (float)*(__int64 *)&v4[4]) * (float)v528;
            v519[2] = (float)((float)1.0 / (float)*(__int64 *)&v4[4]) * (float)v529;
          }
          else
          {
LABEL_251:
            idInterpreter::Warning(
              this,
              fmt: "Divide by zero",
              a3: v3,
              a4: v2,
              a5: *(__int64 *)v4,
              a6: v822,
              a7: v823,
              a8: v824,
              a9: v825,
              a10: v826,
              a11: v827);
            *v519 = 1900671690;
            v519[1] = 1.0e30;
            v519[2] = 1.0e30;
          }
          goto LABEL_437;
        case 0x9C:
          v530 = (varEval_t::<unnamed_type_value> **)idInterpreter::GetVariable(
                                                       retstr: &v885,
                                                       this,
                                                       def: *(idVarDef **)v7);
          v531 = *(idVarDef **)(v7 + 4);
          v532 = *v530;
          v536 = idInterpreter::GetVariable(retstr: &v887, this, def: v531);
          *((double *)&v538 + 1) = *(float *)&v532->cp;
          v539 = (float *)v536->value.i;
          if ( *((double *)&v538 + 1) == 0.0 )
          {
            idInterpreter::Warning(
              this,
              fmt: "Divide by zero",
              a3: v535,
              a4: v534,
              a5: v533,
              a6: v822,
              a7: v823,
              a8: v824,
              a9: v825,
              a10: v826,
              a11: v827);
            *v539 = *(float *)&v532->cp;
          }
          else
          {
            *(double *)&v538 = *v539;
            v828.value.cp = v532->cp;
            v540 = fmod(dX: v538, dY: v537);
            *v539 = *(double *)&v540;
          }
          goto LABEL_437;
        case 0x9D:
          v158 = (float *)idInterpreter::GetVariable(retstr: &v889, this, def: *(idVarDef **)v7)->value.i;
          v541 = idInterpreter::GetVariable(retstr: &v891, this, def: *(idVarDef **)(v7 + 4));
          v542 = *v158;
          v168 = (float *)v541->value.i;
          if ( *(_DWORD *)v158 != 0 )
          {
            *(float *)v4 = *v168;
            __twllei(LODWORD(v542), 0);
            LODWORD(v2) = *(_DWORD *)v4 / SLODWORD(v542);
            HIDWORD(v2) = *(_DWORD *)v4 / SLODWORD(v542) * LODWORD(v542);
            LODWORD(v3) = __ROL4__(*(_DWORD *)v4, 1) - 1;
            HIDWORD(v3) = *(_DWORD *)v4 % SLODWORD(v542);
            *(_DWORD *)v168 = *(_DWORD *)v4 % SLODWORD(v542);
            __twlgei(LODWORD(v542) & ~(_DWORD)v3, 0xFFFFFFFF);
          }
          else
          {
LABEL_260:
            idInterpreter::Warning(
              this,
              fmt: "Divide by zero",
              a3: v164,
              a4: v163,
              a5: v162,
              a6: v822,
              a7: v823,
              a8: v824,
              a9: v825,
              a10: v826,
              a11: v827);
            *v168 = *v158;
          }
          goto LABEL_437;
        case 0x9E:
          v439 = idInterpreter::GetVariable(retstr: &v1152, this, def: *(idVarDef **)v7);
          v440 = *(idVarDef **)(v7 + 4);
          v441 = (float *)v439->value.i;
          v442 = idInterpreter::GetVariable(retstr: &v1038, this, def: v440);
          *v442->value.fp = *v442->value.fp + *v441;
          goto LABEL_437;
        case 0x9F:
          v443 = idInterpreter::GetVariable(retstr: &v1210, this, def: *(idVarDef **)v7);
          v444 = *(idVarDef **)(v7 + 4);
          v445 = (_DWORD *)v443->value.i;
          v446 = idInterpreter::GetVariable(retstr: &v1040, this, def: v444);
          *(varEval_t *)v4 = (varEval_t)v446->value.cp;
          LODWORD(v2) = *v445 + *v446->value.ip;
          *v446->value.ip = v2;
          goto LABEL_437;
        case 0xA0:
          v447 = idInterpreter::GetVariable(retstr: &v1154, this, def: *(idVarDef **)v7);
          v448 = *(idVarDef **)(v7 + 4);
          v449 = (float *)v447->value.i;
          v450 = idInterpreter::GetVariable(retstr: &v1042, this, def: v448);
          *(varEval_t *)&v4[8] = (varEval_t)v450->value.cp;
          **(float **)&v4[8] = *v449 + *v450->value.fp;
          v451 = *(float *)(*(_DWORD *)&v4[8] + 8);
          *(float *)(*(_DWORD *)&v4[8] + 4) = v449[1] + *(float *)(*(_DWORD *)&v4[8] + 4);
          *(float *)(*(_DWORD *)&v4[8] + 8) = v449[2] + (float)v451;
          goto LABEL_437;
        case 0xA1:
          v452 = idInterpreter::GetVariable(retstr: &v1260, this, def: *(idVarDef **)v7);
          v453 = *(idVarDef **)(v7 + 4);
          v454 = (_DWORD *)v452->value.i;
          *(varEval_t *)v4 = (varEval_t)idInterpreter::GetVariable(retstr: &v1044, this, def: v453)->value.cp;
          LODWORD(v2) = *v454;
          v1211 = v2;
          **(float **)v4 = (float)v2 + **(float **)v4;
          goto LABEL_437;
        case 0xA2:
          v455 = idInterpreter::GetVariable(retstr: &v1156, this, def: *(idVarDef **)v7);
          v456 = *(idVarDef **)(v7 + 4);
          v457 = (float *)v455->value.i;
          *(varEval_t *)v4 = (varEval_t)idInterpreter::GetVariable(retstr: &v1046, this, def: v456)->value.cp;
          v829 = (int)*v457;
          LODWORD(v2) = v829 + **(_DWORD **)v4;
          **(_DWORD **)v4 = v2;
          goto LABEL_437;
        case 0xA3:
          v458 = idInterpreter::GetVariable(retstr: &v1212, this, def: *(idVarDef **)v7);
          v459 = *(idVarDef **)(v7 + 4);
          v460 = (float *)v458->value.i;
          v461 = idInterpreter::GetVariable(retstr: &v1048, this, def: v459);
          *v461->value.fp = *v461->value.fp - *v460;
          goto LABEL_437;
        case 0xA4:
          v462 = idInterpreter::GetVariable(retstr: &v834, this, def: *(idVarDef **)v7);
          v463 = *(idVarDef **)(v7 + 4);
          v464 = (_DWORD *)v462->value.i;
          v465 = idInterpreter::GetVariable(retstr: &v1050, this, def: v463);
          *(_DWORD *)v4 = *v464;
          LODWORD(v2) = *v465->value.ip;
          HIDWORD(v2) = v2 - *v464;
          *v465->value.ip = HIDWORD(v2);
          goto LABEL_437;
        case 0xA5:
          v466 = idInterpreter::GetVariable(retstr: &v1240, this, def: *(idVarDef **)v7);
          v467 = *(idVarDef **)(v7 + 4);
          v468 = (float *)v466->value.i;
          v469 = idInterpreter::GetVariable(retstr: &v835, this, def: v467);
          *(varEval_t *)&v4[8] = (varEval_t)v469->value.cp;
          **(float **)&v4[8] = *v469->value.fp - *v468;
          v470 = *(float *)(*(_DWORD *)&v4[8] + 8);
          *(float *)(*(_DWORD *)&v4[8] + 4) = *(float *)(*(_DWORD *)&v4[8] + 4) - v468[1];
          *(float *)(*(_DWORD *)&v4[8] + 8) = (float)v470 - v468[2];
          goto LABEL_437;
        case 0xA6:
          v471 = idInterpreter::GetVariable(retstr: &v837, this, def: *(idVarDef **)v7);
          v472 = *(idVarDef **)(v7 + 4);
          v473 = (_DWORD *)v471->value.i;
          *(varEval_t *)v4 = (varEval_t)idInterpreter::GetVariable(retstr: &v839, this, def: v472)->value.cp;
          LODWORD(v2) = *v473;
          v1213 = v2;
          **(float **)v4 = **(float **)v4 - (float)v2;
          goto LABEL_437;
        case 0xA7:
          v474 = idInterpreter::GetVariable(retstr: &v841, this, def: *(idVarDef **)v7);
          v475 = *(idVarDef **)(v7 + 4);
          v476 = (float *)v474->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v843, this, def: v475)->value.cp;
          v829 = (int)*v476;
          *(_DWORD *)v4 = **(_DWORD **)&v4[4];
          LODWORD(v2) = v829;
          HIDWORD(v2) = **(_DWORD **)&v4[4] - v829;
          **(_DWORD **)&v4[4] = HIDWORD(v2);
          goto LABEL_437;
        case 0xA8:
          v557 = idInterpreter::GetVariable(retstr: &v909, this, def: *(idVarDef **)v7);
          v558 = *(idVarDef **)(v7 + 4);
          v559 = (float *)v557->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v911, this, def: v558)->value.cp;
          v829 = (int)*v559;
          *(_DWORD *)v4 = v829;
          v831 = (int)**(float **)&v4[4];
          LODWORD(v2) = v831;
          HIDWORD(v2) = v829 & v831;
          LODWORD(v3) = v829 & v831;
          v1227 = v3;
          **(float **)&v4[4] = (float)v3;
          goto LABEL_437;
        case 0xA9:
          v560 = idInterpreter::GetVariable(retstr: &v913, this, def: *(idVarDef **)v7);
          v561 = *(idVarDef **)(v7 + 4);
          v562 = (_DWORD *)v560->value.i;
          v563 = idInterpreter::GetVariable(retstr: &v915, this, def: v561);
          *(_DWORD *)v4 = *v562;
          LODWORD(v2) = *v563->value.ip;
          HIDWORD(v2) = *v562 & v2;
          *v563->value.ip = HIDWORD(v2);
          goto LABEL_437;
        case 0xAA:
          v564 = idInterpreter::GetVariable(retstr: &v917, this, def: *(idVarDef **)v7);
          v565 = *(idVarDef **)(v7 + 4);
          v566 = (_DWORD *)v564->value.i;
          v567 = idInterpreter::GetVariable(retstr: &v919, this, def: v565);
          *(varEval_t *)&v4[4] = (varEval_t)v567->value.cp;
          *(_DWORD *)v4 = *v566;
          v829 = (int)*v567->value.fp;
          LODWORD(v2) = v829;
          HIDWORD(v2) = v829 & *(_DWORD *)v4;
          LODWORD(v3) = v829 & *(_DWORD *)v4;
          v1229 = v3;
          **(float **)&v4[4] = (float)v3;
          goto LABEL_437;
        case 0xAB:
          v568 = idInterpreter::GetVariable(retstr: &v921, this, def: *(idVarDef **)v7);
          v569 = *(idVarDef **)(v7 + 4);
          v570 = (float *)v568->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v923, this, def: v569)->value.cp;
          v829 = (int)*v570;
          *(_DWORD *)v4 = **(_DWORD **)&v4[4];
          LODWORD(v2) = v829;
          HIDWORD(v2) = v829 & **(_DWORD **)&v4[4];
          **(_DWORD **)&v4[4] = HIDWORD(v2);
          goto LABEL_437;
        case 0xAC:
          v543 = idInterpreter::GetVariable(retstr: &v893, this, def: *(idVarDef **)v7);
          v544 = *(idVarDef **)(v7 + 4);
          v545 = (float *)v543->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v895, this, def: v544)->value.cp;
          v829 = (int)*v545;
          *(_DWORD *)v4 = v829;
          v829 = (int)**(float **)&v4[4];
          LODWORD(v2) = v829;
          HIDWORD(v2) = *(_DWORD *)v4 | v829;
          LODWORD(v3) = *(_DWORD *)v4 | v829;
          v1223 = v3;
          **(float **)&v4[4] = (float)v3;
          goto LABEL_437;
        case 0xAD:
          v546 = idInterpreter::GetVariable(retstr: &v897, this, def: *(idVarDef **)v7);
          v547 = *(idVarDef **)(v7 + 4);
          v548 = (_DWORD *)v546->value.i;
          v549 = idInterpreter::GetVariable(retstr: &v899, this, def: v547);
          *(_DWORD *)v4 = *v548;
          LODWORD(v2) = *v549->value.ip;
          HIDWORD(v2) = *v548 | v2;
          *v549->value.ip = HIDWORD(v2);
          goto LABEL_437;
        case 0xAE:
          v550 = idInterpreter::GetVariable(retstr: &v901, this, def: *(idVarDef **)v7);
          v551 = *(idVarDef **)(v7 + 4);
          v552 = (_DWORD *)v550->value.i;
          v553 = idInterpreter::GetVariable(retstr: &v903, this, def: v551);
          *(varEval_t *)&v4[4] = (varEval_t)v553->value.cp;
          *(_DWORD *)v4 = *v552;
          v829 = (int)*v553->value.fp;
          LODWORD(v2) = v829;
          HIDWORD(v2) = v829 | *(_DWORD *)v4;
          LODWORD(v3) = v829 | *(_DWORD *)v4;
          v1225 = v3;
          **(float **)&v4[4] = (float)v3;
          goto LABEL_437;
        case 0xAF:
          v554 = idInterpreter::GetVariable(retstr: &v905, this, def: *(idVarDef **)v7);
          v555 = *(idVarDef **)(v7 + 4);
          v556 = (float *)v554->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v907, this, def: v555)->value.cp;
          v829 = (int)*v556;
          *(_DWORD *)v4 = **(_DWORD **)&v4[4];
          LODWORD(v2) = v829;
          HIDWORD(v2) = v829 | **(_DWORD **)&v4[4];
          **(_DWORD **)&v4[4] = HIDWORD(v2);
          goto LABEL_437;
        case 0xB0:
          v281 = (unsigned int **)idInterpreter::GetVariable(retstr: &v956, this, def: *(idVarDef **)v7);
          v282 = *(idVarDef **)(v7 + 8);
          v283 = *v281;
          v284 = idInterpreter::GetVariable(retstr: &v1112, this, def: v282);
          *(varEval_t *)v4 = (varEval_t)v284->value.cp;
          LODWORD(v2) = _cntlzw(*v283);
          HIDWORD(v2) = (v2 & 0x20) != 0;
          *v284->value.ip = HIDWORD(v2);
          goto LABEL_437;
        case 0xB1:
          v285 = idInterpreter::GetVariable(retstr: &v958, this, def: *(idVarDef **)v7);
          v286 = *(idVarDef **)(v7 + 8);
          v287 = (float *)v285->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v1190, this, def: v286)->value.cp;
          *(_DWORD *)&v4[8] = *v287 == 0.0;
          v1187 = *(_QWORD *)&v4[4];
          **(float **)&v4[4] = (float)*(__int64 *)&v4[4];
          goto LABEL_437;
        case 0xB2:
          v288 = idInterpreter::GetVariable(retstr: &v960, this, def: *(idVarDef **)v7);
          v289 = *(idVarDef **)(v7 + 8);
          v290 = (float *)v288->value.i;
          v291 = (float *)idInterpreter::GetVariable(retstr: &v1114, this, def: v289)->value.i;
          if ( *v290 != vec3_origin.x || v290[1] != vec3_origin.y || (v292 = 1, v290[2] != vec3_origin.z) )
            v292 = 0;
          *(_DWORD *)v4 = v292;
          v1189 = *(_QWORD *)&v4[8];
          *v291 = (float)*(__int64 *)&v4[8];
          goto LABEL_437;
        case 0xB3:
          *(varEval_t *)v4 = (varEval_t)idInterpreter::GetVariable(retstr: &v962, this, def: *(idVarDef **)(v7 + 8))->value.cp;
          *(_DWORD *)&v4[4] = *(_DWORD *)(*(_DWORD *)v7 + 4);
          if ( *(_DWORD *)(*(_DWORD *)v7 + 16) == 3 )
            *(_DWORD *)&v4[4] += &this->localstack.stack[this->localstack.stackBase];
          *(_DWORD *)&v4[8] = 0;
          if ( **(_BYTE **)&v4[4] != 0 )
          {
            do
              ++*(_DWORD *)&v4[8];
            while ( *(_BYTE *)(*(_DWORD *)&v4[8] + *(_DWORD *)&v4[4]) != 0 );
          }
          LODWORD(v2) = (_cntlzw(*(unsigned int *)&v4[8]) & 0x20) != 0;
          v1191 = v2;
          **(float **)v4 = (float)v2;
          goto LABEL_437;
        case 0xB4:
          v293 = (float *)idInterpreter::GetVariable(retstr: &v1248, this, def: *(idVarDef **)(v7 + 8))->value.i;
          v294 = *(bfx::Planner3D **)(*(_DWORD *)v7 + 20);
          if ( v294 != nullptr && idScriptObject::GetTypeDef(this: v294) == (bfx::Space *)13 )
          {
            *(_DWORD *)v4 = (_cntlzw((unsigned int)idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7)) & 0x20) != 0;
            v1193 = *(_QWORD *)&v4[8];
            *v293 = (float)*(__int64 *)&v4[8];
          }
          else
          {
            v830.value.cp = (char *)idInterpreter::GetVariable(retstr: &v964, this, def: *(idVarDef **)v7)->value.i;
            *(_DWORD *)v4 = _cntlzw((unsigned int)varEval_t::GetEntity(this: &v830));
            LODWORD(v2) = (v4[3] & 0x20) != 0;
            HIDWORD(v2) = v2;
            v1195 = *(__int64 *)((char *)&v2 + 4);
            *v293 = (float)*(__int64 *)((char *)&v2 + 4);
          }
          goto LABEL_437;
        case 0xB5:
          v295 = (unsigned int **)idInterpreter::GetVariable(retstr: &v1116, this, def: *(idVarDef **)v7);
          v296 = *(idVarDef **)(v7 + 8);
          v297 = *v295;
          v298 = idInterpreter::GetVariable(retstr: &v966, this, def: v296);
          *(varEval_t *)v4 = (varEval_t)v298->value.cp;
          LODWORD(v2) = _cntlzw(*v297);
          HIDWORD(v2) = (v2 & 0x20) != 0;
          *v298->value.ip = HIDWORD(v2);
          goto LABEL_437;
        case 0xB6:
          v299 = idInterpreter::GetVariable(retstr: &v1192, this, def: *(idVarDef **)v7);
          v300 = *(idVarDef **)(v7 + 8);
          v301 = (float *)v299->value.i;
          *idInterpreter::GetVariable(retstr: &v968, this, def: v300)->value.fp = -*v301;
          goto LABEL_437;
        case 0xB7:
          v302 = idInterpreter::GetVariable(retstr: &v1118, this, def: *(idVarDef **)v7);
          v303 = *(idVarDef **)(v7 + 8);
          v304 = (float *)v302->value.i;
          *(varEval_t *)&v4[4] = (varEval_t)idInterpreter::GetVariable(retstr: &v970, this, def: v303)->value.cp;
          v305 = -v304[1];
          v306 = -v304[2];
          **(float **)&v4[4] = -*v304;
          *(float *)(*(_DWORD *)&v4[4] + 4) = v305;
          *(float *)(*(_DWORD *)&v4[4] + 8) = v306;
          goto LABEL_437;
        case 0xB8:
          v307 = idInterpreter::GetVariable(retstr: &v1230, this, def: *(idVarDef **)v7);
          v308 = *(idVarDef **)(v7 + 8);
          v309 = (_DWORD *)v307->value.i;
          v310 = idInterpreter::GetVariable(retstr: &v972, this, def: v308);
          *(varEval_t *)v4 = (varEval_t)v310->value.cp;
          LODWORD(v2) = -*v309;
          *v310->value.ip = v2;
          goto LABEL_437;
        case 0xB9:
          v314 = idInterpreter::GetVariable(retstr: &v1194, this, def: *(idVarDef **)v7);
          v315 = *(idVarDef **)(v7 + 8);
          v316 = (_DWORD *)v314->value.i;
          *(varEval_t *)v4 = (varEval_t)idInterpreter::GetVariable(retstr: &v976, this, def: v315)->value.cp;
          LODWORD(v2) = *v316;
          v1197 = v2;
          **(float **)v4 = (float)v2;
          goto LABEL_437;
        case 0xBA:
          v311 = idInterpreter::GetVariable(retstr: &v1120, this, def: *(idVarDef **)v7);
          v312 = *(idVarDef **)(v7 + 8);
          v313 = (float *)v311->value.i;
          *idInterpreter::GetVariable(retstr: &v974, this, def: v312)->value.ip = (int)*v313;
          goto LABEL_437;
        case 0xBB:
          v30 = *(bfx::Planner3D **)(*(_DWORD *)v7 + 20);
          if ( v30 != nullptr && idScriptObject::GetTypeDef(this: v30) == (bfx::Space *)13 )
          {
            if ( idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7) != nullptr )
            {
              *(_DWORD *)v4 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4) + this->localstack.instructionPointer - 1;
              this->localstack.instructionPointer = *(_DWORD *)v4;
            }
          }
          else if ( *idInterpreter::GetVariable(retstr: &v838, this, def: *(idVarDef **)v7)->value.ip != 0 )
          {
            *(_DWORD *)v4 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4) + this->localstack.instructionPointer - 1;
            this->localstack.instructionPointer = *(_DWORD *)v4;
          }
          goto LABEL_437;
        case 0xBC:
          v29 = *(bfx::Planner3D **)(*(_DWORD *)v7 + 20);
          if ( v29 != nullptr && idScriptObject::GetTypeDef(this: v29) == (bfx::Space *)13 )
          {
            if ( idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7) == nullptr )
            {
              *(_DWORD *)v4 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4) + this->localstack.instructionPointer - 1;
              this->localstack.instructionPointer = *(_DWORD *)v4;
            }
          }
          else if ( *idInterpreter::GetVariable(retstr: &v1052, this, def: *(idVarDef **)v7)->value.ip == 0 )
          {
            *(_DWORD *)v4 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4) + this->localstack.instructionPointer - 1;
            this->localstack.instructionPointer = *(_DWORD *)v4;
          }
          goto LABEL_437;
        case 0xBD:
          idInterpreter::EnterFunction(
            this,
            func: *(idDecl **)(*(_DWORD *)v7 + 4),
            clearStack: (unsigned int)v3,
            a4: v2,
            a5: *(__int64 *)v4);
          goto LABEL_437;
        case 0xBE:
          currentThread = gameLocal->program.threadManager.currentThread;
          *(float *)&v9 = COERCE_FLOAT(
                            idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x1B94u,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP));
          v828.value.cp = (char *)v9;
          if ( *(float *)&v9 == 0.0 )
            v10 = nullptr;
          else
            v10 = idThread::idThread(this: v9);
          idThread::CallFunctionFromInterpreter(
            this: v10,
            source: this,
            func: *(const function_t **)(*(_DWORD *)v7 + 4),
            args: *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4));
          idThread::Start(this: v10);
          gameLocal->program.threadManager.currentThread = currentThread;
          LODWORD(v2) = v10->threadHandle.value;
          *(_DWORD *)v4 = gameLocal->program.returnDef;
          HIDWORD(v2) = *(_DWORD *)(*(_DWORD *)v4 + 4);
          *(_DWORD *)HIDWORD(v2) = v2;
          LODWORD(v3) = *(_DWORD *)(v7 + 4);
          *(_DWORD *)&v4[8] = this->localstack.stackUsed;
          *(_DWORD *)&v4[4] = *(_DWORD *)(v3 + 4);
          if ( *(int *)&v4[8] < *(int *)&v4[4] )
            goto _LN2436;
          this->localstack.stackUsed = *(_DWORD *)&v4[8] - *(_DWORD *)&v4[4];
          goto LABEL_437;
        case 0xBF:
          v11 = idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7);
          if ( v11 != nullptr )
          {
            v12 = *(_DWORD *)(*(_DWORD *)(v7 + 4) + 4);
            v13 = (idTypeDef *)idScriptObject::GetTypeDef(this: v11);
            v14 = idTypeDef::GetFunction(this: v13, funcNumber: v12);
            v15 = gameLocal->program.threadManager.currentThread;
            *(float *)&v16 = COERCE_FLOAT(
                               idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                 size: 0x1B94u,
                                 tag: TAG_NEW,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP));
            v828.value.cp = (char *)v16;
            if ( *(float *)&v16 == 0.0 )
              v17 = nullptr;
            else
              v17 = idThread::idThread(this: v16);
            idThread::CallFunctionFromInterpreter(this: v17, source: this, func: v14, args: v14->parmTotal);
            idThread::Start(this: v17);
            gameLocal->program.threadManager.currentThread = v15;
            *(_DWORD *)v4 = gameLocal->program.returnDef->value.value.cp;
            **(_DWORD **)v4 = v17->threadHandle.value;
          }
          else
          {
            *gameLocal->program.returnDef->value.value.ip = 0;
          }
          *(_DWORD *)&v4[4] = this->localstack.stackUsed;
          *(_DWORD *)&v4[8] = *(_DWORD *)(*(_DWORD *)(v7 + 8) + 4);
          if ( *(int *)&v4[4] < *(int *)&v4[8] )
            goto _LN2437;
          this->localstack.stackUsed = *(_DWORD *)&v4[4] - *(_DWORD *)&v4[8];
          goto LABEL_437;
        case 0xC0:
          v18 = idGameLocal::CreateScriptList(this: gameLocal);
          *idInterpreter::GetVariable(retstr: &v1158, this, def: *(idVarDef **)(v7 + 4))->value.ip = v18->id;
          goto LABEL_437;
        case 0xC1:
          v19 = idInterpreter::GetVariable(retstr: &v836, this, def: *(idVarDef **)(v7 + 4));
          v20 = idGameLocal::GetScriptList(this: gameLocal, idToGet: *v19->value.ip);
          if ( v20 != nullptr && !v20->isMember )
            ((void (__fastcall *)(idScriptList *, int))v20->dtr_idClass)(a1: v20, a2: 1);
          goto LABEL_437;
        case 0xC2:
          v687 = idInterpreter::GetVariable(retstr: &v1067, this, def: *(idVarDef **)v7);
          LODWORD(v688) = (varEval_t)v687->value.cp;
          idInterpreter::PushFloat(this, value: *v687->value.fp, a3: v691, a4: v690, a5: v689, a6: v688);
          goto LABEL_437;
        case 0xC3:
          v727 = (idInterpreter ***)idInterpreter::GetVariable(retstr: &v1083, this, def: *(idVarDef **)v7);
          LODWORD(v728) = *v727;
          HIDWORD(v728) = (*v727)[2];
          HIDWORD(v729) = __ROL4__(HIDWORD(v728), 32);
          idInterpreter::PushVec3(this: **v727, value: (idVec3 *)(*v727)[1], a3: v729, a4: v730, a5: v728);
          goto LABEL_437;
        case 0xC4:
          *(_DWORD *)&v4[8] = *(_DWORD *)v7;
          *(_DWORD *)&v4[4] = *(_DWORD *)(*(_DWORD *)v7 + 16);
          if ( *(_DWORD *)&v4[4] == 3 )
          {
            *(_DWORD *)&v4[4] = *(_DWORD *)(*(_DWORD *)&v4[8] + 4);
            idInterpreter::PushString(
              this,
              string: (const char *)&this->localstack.stack[*(_DWORD *)&v4[4] + this->localstack.stackBase],
              a3: v3,
              a4: v2,
              a5: *(__int64 *)v4);
          }
          else
          {
            idInterpreter::PushString(
              this,
              string: *(const char **)(*(_DWORD *)&v4[8] + 4),
              a3: v3,
              a4: v2,
              a5: *(__int64 *)v4);
          }
          goto LABEL_437;
        case 0xC5:
          v692 = idInterpreter::GetVariable(retstr: &v1069, this, def: *(idVarDef **)v7);
          LODWORD(v693) = (varEval_t)v692->value.cp;
          idInterpreter::PushInt(this, value: *v692->value.ip, a3: v695, a4: v694, a5: v693);
          goto LABEL_437;
        case 0xC6:
          v723 = (const idEntityPtr<idEntity> **)idInterpreter::GetVariable(retstr: &v1081, this, def: *(idVarDef **)v7);
          idInterpreter::PushEntityPtr(this, entityPtr: *v723, a3: v726, a4: v725, a5: v724);
          goto LABEL_437;
        case 0xC7:
          if ( idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7) == nullptr )
            goto LABEL_417;
          v731 = (const idEntityPtr<idEntity> **)idInterpreter::GetVariable(retstr: &v1085, this, def: *(idVarDef **)v7);
          idInterpreter::PushEntityPtr(this, entityPtr: *v731, a3: v734, a4: v733, a5: v732);
          goto LABEL_437;
        case 0xC8:
          if ( idInterpreter::GetScriptObject(this, varDef: *(idVarDef **)v7) != nullptr )
          {
            v735 = (const idEntityPtr<idEntity> **)idInterpreter::GetVariable(
                                                     retstr: &v1087,
                                                     this,
                                                     def: *(idVarDef **)v7);
            idInterpreter::PushEntityPtr(this, entityPtr: *v735, a3: v738, a4: v737, a5: v736);
          }
          else
          {
LABEL_417:
            idInterpreter::PushEntity(this, ent: nullptr);
          }
          goto LABEL_437;
        case 0xC9:
          v683 = idInterpreter::GetVariable(retstr: &v1065, this, def: *(idVarDef **)v7);
          LODWORD(v684) = (varEval_t)v683->value.cp;
          idInterpreter::PushScriptType(this, scriptTypeID: *v683->value.ip, a3: v686, a4: v685, a5: v684);
          goto LABEL_437;
        case 0xCA:
          v696 = idInterpreter::GetVariable(retstr: &v1071, this, def: *(idVarDef **)v7);
          v697 = idInterpreter::FloatToString(this, value: *v696->value.fp);
          idInterpreter::PushString(this, string: v697, a3: v700, a4: v699, a5: v698);
          goto LABEL_437;
        case 0xCB:
          v715 = idInterpreter::GetVariable(retstr: &v1079, this, def: *(idVarDef **)v7);
          LODWORD(v716) = (varEval_t)v715->value.cp;
          HIDWORD(v717) = *v715->value.ip;
          v719 = va::va(
                   this: &v1267,
                   fmt: "%d",
                   a3: v717,
                   a4: v718,
                   a5: v716,
                   a6: v822,
                   a7: v823,
                   a8: v824,
                   a9: v825,
                   a10: v826,
                   a11: v827);
          idInterpreter::PushString(this, string: v719->buffer, a3: v722, a4: v721, a5: v720);
          goto LABEL_437;
        case 0xCC:
          v701 = idInterpreter::GetVariable(retstr: &v1073, this, def: *(idVarDef **)v7);
          LODWORD(v702) = (varEval_t)v701->value.cp;
          HIDWORD(v702) = *v701->value.ip;
          LODWORD(v703) = HIDWORD(v702);
          v1237 = v703;
          idInterpreter::PushFloat(this, value: (float)v703, a3: v705, a4: v704, a5: v703, a6: v702);
          goto LABEL_437;
        case 0xCD:
          v706 = idInterpreter::GetVariable(retstr: &v1075, this, def: *(idVarDef **)v7);
          LODWORD(v707) = (varEval_t)v706->value.cp;
          v829 = (int)*v706->value.fp;
          idInterpreter::PushInt(this, value: v829, a3: v709, a4: v708, a5: v707);
          goto LABEL_437;
        case 0xCE:
          v710 = (idAngles **)idInterpreter::GetVariable(retstr: &v1077, this, def: *(idVarDef **)v7);
          v711 = idVec3::ToString(this: *v710, precision: 2);
          idInterpreter::PushString(this, string: v711, a3: v714, a4: v713, a5: v712);
          goto LABEL_437;
        case 0xCF:
          v739 = idInterpreter::GetVariable(retstr: &v1089, this, def: *(idVarDef **)v7);
          LODWORD(v740) = (varEval_t)v739->value.cp;
          idInterpreter::PushInt(this, value: *v739->value.ip, a3: v742, a4: v741, a5: v740);
          goto LABEL_437;
        case 0xD0:
          this->localstack.instructionPointer = *(_DWORD *)(*(_DWORD *)v7 + 4) + *(_DWORD *)&v4[4] - 1;
          goto LABEL_437;
        default:
          goto _LN2439;
      }
    }
    idInterpreter::Error(
      this,
      fmt: "runaway loop error",
      a3: v3,
      a4: v2,
      a5: *(__int64 *)v4,
      a6: v822,
      a7: v823,
      a8: v824,
      a9: v825,
      a10: v826,
      a11: v827);
_LN2436:
    idInterpreter::Error(
      this,
      fmt: "locals stack underflow\n",
      a3: v3,
      a4: v2,
      a5: *(__int64 *)v4,
      a6: v822,
      a7: v823,
      a8: v824,
      a9: v825,
      a10: v826,
      a11: v827);
_LN2437:
    idInterpreter::Error(
      this,
      fmt: "locals stack underflow\n",
      a3: v3,
      a4: v2,
      a5: *(__int64 *)v4,
      a6: v822,
      a7: v823,
      a8: v824,
      a9: v825,
      a10: v826,
      a11: v827);
_LN2438:
    idInterpreter::Error(
      this,
      fmt: "locals stack underflow\n",
      a3: v3,
      a4: v2,
      a5: *(__int64 *)v4,
      a6: v822,
      a7: v823,
      a8: v824,
      a9: v825,
      a10: v826,
      a11: v827);
_LN2439:
    idInterpreter::Error(
      this,
      fmt: "Bad opcode %i",
      a3: v3,
      a4: v2,
      a5: *(__int64 *)v4,
      a6: v822,
      a7: v823,
      a8: v824,
      a9: v825,
      a10: v826,
      a11: v827);
  }
  return 1;
}


// ========================================================================
// $LN2410
// EA  : 0x82E99E5C
// RVA : 0x00E99E5C
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void __fastcall _LN2410(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 10640 + 112), tag: a2);
}


// ========================================================================
// __unwind$492129
// EA  : 0x82E99E84
// RVA : 0x00E99E84
// PDB : w:\tech5\tungsten\game\script\interpreter.cpp
// ========================================================================

void __fastcall _unwind_492129(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 10640 + 112), tag: a2);
}

