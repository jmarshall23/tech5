
// ========================================================================
// ?ManualDelete@idThread@@QAAXXZ
// EA  : 0x82EA1EE0
// RVA : 0x00EA1EE0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::ManualDelete(idThread *this)
{
  this->interpreter.terminateOnExit = false;
}


// ========================================================================
// ?SetThreadName@idThread@@QAAXPBD@Z
// EA  : 0x82EA1EF0
// RVA : 0x00EA1EF0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::SetThreadName(idThread *this, const char *name)
{
  idStr::operator=(this: &this->threadName, text: name);
}


// ========================================================================
// ?ClearWaitFor@idThread@@QAAXXZ
// EA  : 0x82EA1EF8
// RVA : 0x00EA1EF8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::ClearWaitFor(idThread *this)
{
  this->waitingForThread = nullptr;
  this->waitingFor = 0x1FFF;
  this->waitingUntil = 0;
  this->waitingForEventId = 0;
  this->waitingForFlags = 0;
  this->waitingForFSM = false;
}


// ========================================================================
// ?IsWaitingForFlags@idThread@@QBA_NH@Z
// EA  : 0x82EA1F20
// RVA : 0x00EA1F20
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

BOOL __fastcall idThread::IsWaitingForFlags(idThread *this, const int flags)
{
  return (this->waitingForFlags & flags) != 0;
}


// ========================================================================
// ?IsDead_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MBA_NXZ
// EA  : 0x82EA1F38
// RVA : 0x00EA1F38
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

BOOL __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::IsDead_Impl(
        idHealthT<enum simpleHealthComponent_t,1,0> *this)
{
  return this->isDead;
}


// ========================================================================
// ?Error@idThread@@QBAXPBDZZ
// EA  : 0x82EA1F40
// RVA : 0x00EA1F40
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idThread::Error(
        idThread *this,
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
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
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
  idStr::vsnPrintf(dest: v21, size: 1024, fmt, argptr: va);
  idInterpreter::Error(
    this: &this->interpreter,
    fmt: v21,
    a3: v14,
    a4: v13,
    a5: v12,
    a6: v15,
    a7: v16,
    a8: v17,
    a9: v18,
    a10: v19,
    a11: v20);
}


// ========================================================================
// ?Warning@idThread@@QBAXPBDZZ
// EA  : 0x82EA1FB0
// RVA : 0x00EA1FB0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idThread::Warning(
        idThread *this,
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
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
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
  idStr::vsnPrintf(dest: v21, size: 1024, fmt, argptr: va);
  idInterpreter::Warning(
    this: &this->interpreter,
    fmt: v21,
    a3: v14,
    a4: v13,
    a5: v12,
    a6: v15,
    a7: v16,
    a8: v17,
    a9: v18,
    a10: v19,
    a11: v20);
}


// ========================================================================
// ?WaitForFSM@idThread@@QAAX_N@Z
// EA  : 0x82EA2020
// RVA : 0x00EA2020
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::WaitForFSM(idThread *this, bool waiting)
{
  this->waitingForFSM = waiting;
  this->waitingForThread = nullptr;
  this->waitingFor = 0x1FFF;
  this->waitingUntil = 0;
  this->waitingForEventId = 0;
  this->waitingForFlags = 0;
  this->interpreter.doneProcessing = true;
}


// ========================================================================
// ?Event_Getcvar@idThread@@ABA?AVeventString@@PBD@Z
// EA  : 0x82EA2050
// RVA : 0x00EA2050
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Getcvar(idThread *this, eventString *result, const char *name)
{
  const char *v4; // r3

  v4 = cvarSystem->GetCVarString(this: cvarSystem, a2: name, a3: &byte_8200D768);
  eventString::eventString((eventString *)this, s: v4);
  return this;
}


// ========================================================================
// ?Event_AngToForward@idThread@@AAA?AVeventVector@@ABVidAngles@@@Z
// EA  : 0x82EA20B0
// RVA : 0x00EA20B0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_AngToForward(idThread *this, eventVector *result, idVec3 *ang)
{
  eventVector *v4; // r3
  idAngles v6; // [sp+50h] [-20h] BYREF

  v4 = (eventVector *)idAngles::ToForward(this: &v6, result: ang);
  eventVector::eventVector((eventVector *)this, v: v4);
  return this;
}


// ========================================================================
// ?Event_GetTraceBody@idThread@@AAA?AVeventString@@XZ
// EA  : 0x82EA20F8
// RVA : 0x00EA20F8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_GetTraceBody(idThread *this, eventString *result)
{
  eventString::eventString((eventString *)this, s: &byte_8200D768);
  return this;
}


// ========================================================================
// ?Event_StrToFloat@idThread@@AAA?AVeventFloat@@PBD@Z
// EA  : 0x82EA2130
// RVA : 0x00EA2130
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_StrToFloat(idThread *this, eventFloat *result, const char *string)
{
  long double v4; // fp2

  v4 = atof(nptr: string);
  eventFloat::eventFloat((eventFloat *)this, f: (float)*(double *)&v4);
  return this;
}


// ========================================================================
// ?Event_StrToInt@idThread@@AAA?AVeventInt@@PBD@Z
// EA  : 0x82EA2170
// RVA : 0x00EA2170
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_StrToInt(idThread *this, eventInt *result, const char *string)
{
  int v4; // r3

  v4 = atol(nptr: string);
  eventInt::eventInt((eventInt *)this, i: v4);
  return this;
}


// ========================================================================
// ?Event_GetTicsPerSecond@idThread@@AAA?AVeventFloat@@XZ
// EA  : 0x82EA21B0
// RVA : 0x00EA21B0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_GetTicsPerSecond(idThread *this, eventFloat *result)
{
  __int64 v3; // r8

  LODWORD(v3) = gameLocal->GetGameHz(this: gameLocal, a2: GAMETIME_SCALED);
  eventFloat::eventFloat((eventFloat *)this, f: (float)v3);
  return this;
}


// ========================================================================
// ?Event_CreateArray@idThread@@AAA?AVeventEntity@@XZ
// EA  : 0x82EA2218
// RVA : 0x00EA2218
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_CreateArray(idThread *this, eventEntity *result)
{
  idEntity *v3; // r30

  v3 = gameLocal->CreateClass(this: gameLocal, a2: "idScriptList");
  gameLocal->SpawnEntity(this: gameLocal, a2: v3, a3: -1, a4: -1, a5: -1);
  eventEntity::eventEntity((eventEntity *)this, e: v3);
  return this;
}


// ========================================================================
// ?Event_IsValidDecl@idThread@@AAA?AVeventBool@@PBVidDecl@@@Z
// EA  : 0x82EA22A8
// RVA : 0x00EA22A8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_IsValidDecl(idThread *this, eventBool *result, const idDecl *decl)
{
  eventBool::eventBool((eventBool *)this, b: decl != nullptr);
  return this;
}


// ========================================================================
// ?Event_NumActiveAIs@idThread@@AAA?AVeventInt@@XZ
// EA  : 0x82EA22E0
// RVA : 0x00EA22E0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_NumActiveAIs(idThread *this, eventInt *result)
{
  int active; // r3

  active = idGameLocal::NumActiveAI(this: gameLocal);
  eventInt::eventInt((eventInt *)this, i: active);
  return this;
}


// ========================================================================
// ??1idThread@@UAA@XZ
// EA  : 0x82EA2330
// RVA : 0x00EA2330
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::~idThread(idThread *this)
{
  char *data; // r29
  int GameMs; // r3

  this->__vftable = (idThread_vtbl *)&idThread::`vftable';
  if ( g_debugScript.valueInteger != 0 )
  {
    data = this->threadName.data;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "%d: end thread (%d) '%s'\n", GameMs, this->threadHandle.value, data);
  }
  idThreadManager::RemoveThread(this: &gameLocal->program.threadManager, thread: this);
  idStr::FreeData(this: &this->threadName);
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$489397
// EA  : 0x82EA23CC
// RVA : 0x00EA23CC
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void _unwind_489397()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489398_0
// EA  : 0x82EA23F4
// RVA : 0x00EA23F4
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void _unwind_489398_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// ?DelayedStart@idThread@@QAAXH@Z
// EA  : 0x82EA2420
// RVA : 0x00EA2420
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::DelayedStart(idThread *this, int delay)
{
  __int64 v4; // r10
  __int64 v5; // r8
  int v6; // r6

  idEventReceiver::CancelEvents(this, ev: &EV_Execute);
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) <= 0 )
    ++delay;
  idEventReceiver::PostEventMS(this, ev: &EV_Execute, time: delay, a4: v6, a5: v5, a6: v4);
}


// ========================================================================
// ?End@idThread@@QAAXXZ
// EA  : 0x82EA2480
// RVA : 0x00EA2480
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::End(idThread *this)
{
  int GameMsPerFrame; // r3
  __int64 v3; // r10
  __int64 v4; // r8
  int v5; // r6

  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  LODWORD(v3) = &s_memTag[218];
  idEventReceiver::PostEventMS(this, ev: &EV_Execute, time: GameMsPerFrame, a4: v5, a5: v4, a6: v3);
  this->waitingForThread = nullptr;
  this->waitingUntil = 0;
  this->waitingFor = 0x1FFF;
  this->waitingForEventId = 0;
  this->waitingForFlags = 0;
  this->waitingForFSM = false;
  this->interpreter.doneProcessing = true;
  this->interpreter.threadDying = true;
}


// ========================================================================
// ?Execute@idThread@@QAA_NXZ
// EA  : 0x82EA2500
// RVA : 0x00EA2500
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

int __fastcall idThread::Execute(idThread *this)
{
  idThread *currentThread; // r24
  int v4; // r26
  __int64 v5; // r8
  int v6; // r6
  __int64 v7; // r10
  int GameMsPerFrame; // r5
  const idEventDef *v9; // r4
  int waitingUntil; // r11

  if ( this->manualControl
    && this->waitingUntil > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
  {
    return 0;
  }
  currentThread = gameLocal->program.threadManager.currentThread;
  gameLocal->program.threadManager.currentThread = this;
  this->lastExecuteTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->waitingForThread = nullptr;
  this->waitingFor = 0x1FFF;
  this->waitingUntil = 0;
  this->waitingForEventId = 0;
  this->waitingForFlags = 0;
  this->waitingForFSM = false;
  v4 = idInterpreter::Execute(this: &this->interpreter);
  if ( (_BYTE)v4 != 0 )
  {
    idThread::End(this);
    if ( this->interpreter.terminateOnExit )
    {
      GameMsPerFrame = 0;
      v9 = &EV_Remove;
LABEL_12:
      idEventReceiver::PostEventMS(this, ev: v9, time: GameMsPerFrame, a4: v6, a5: v5, a6: v7);
    }
  }
  else if ( !this->manualControl )
  {
    waitingUntil = this->waitingUntil;
    LODWORD(v7) = this->lastExecuteTime;
    if ( waitingUntil > (int)v7 )
    {
      HIDWORD(v7) = &s_memTag[218];
      GameMsPerFrame = waitingUntil - v7;
      v9 = &EV_Execute;
      goto LABEL_12;
    }
    if ( idInterpreter::MultiFrameEventInProgress(this: &this->interpreter) )
    {
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v9 = &EV_Execute;
      goto LABEL_12;
    }
  }
  gameLocal->program.threadManager.currentThread = currentThread;
  return v4;
}


// ========================================================================
// ?IsWaiting@idThread@@QBA_NXZ
// EA  : 0x82EA2658
// RVA : 0x00EA2658
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

int __fastcall idThread::IsWaiting(idThread *this)
{
  int result; // r3

  if ( this->waitingForThread != nullptr
    || this->waitingFor != 0x1FFF
    || this->waitingUntil != 0
    && this->waitingUntil > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
  {
    return 1;
  }
  if ( this->waitingForFlags != 0 )
    return 1;
  result = 0;
  if ( this->waitingForFSM )
    return 1;
  return result;
}


// ========================================================================
// ?CallFunction@idThread@@QAAXPBVfunction_t@@_N@Z
// EA  : 0x82EA26E8
// RVA : 0x00EA26E8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::CallFunction(idThread *this, idDecl *func, __int64 clearStack, __int64 a4, __int64 a5)
{
  LODWORD(a5) = 0x1FFF;
  this->waitingForThread = nullptr;
  this->waitingFor = 0x1FFF;
  this->waitingUntil = 0;
  this->waitingForEventId = 0;
  this->waitingForFlags = 0;
  this->waitingForFSM = false;
  idInterpreter::EnterFunction(this: &this->interpreter, func, clearStack, a4, a5);
}


// ========================================================================
// ?CallObjectFunction@idThread@@QAAXPAVidEntity@@PBVfunction_t@@_N@Z
// EA  : 0x82EA2710
// RVA : 0x00EA2710
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::CallObjectFunction(idThread *this, idEntity *self, __int64 clearStack, __int64 a4)
{
  this->waitingForThread = nullptr;
  this->waitingFor = 0x1FFF;
  this->waitingUntil = 0;
  this->waitingForEventId = 0;
  this->waitingForFlags = 0;
  this->waitingForFSM = false;
  idInterpreter::EnterObjectFunction(this: &this->interpreter, self, clearStack, a4);
}


// ========================================================================
// ?CallFunctionWithParms@idThread@@QAA_NPBVfunction_t@@HPAVidEventArg@@_N@Z
// EA  : 0x82EA2738
// RVA : 0x00EA2738
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

int __fastcall idThread::CallFunctionWithParms(
        idThread *this,
        idDecl *func,
        idDeclSource *numArgs,
        idAICover *args,
        bool clearStack)
{
  this->waitingForThread = nullptr;
  this->waitingFor = 0x1FFF;
  this->waitingUntil = 0;
  this->waitingForEventId = 0;
  this->waitingForFlags = 0;
  this->waitingForFSM = false;
  return idInterpreter::EnterFunctionWithParms(this: &this->interpreter, func, numArgs, args, clearStack);
}


// ========================================================================
// ?CallFunctionFromInterpreter@idThread@@QAAXPAVidInterpreter@@PBVfunction_t@@H@Z
// EA  : 0x82EA2760
// RVA : 0x00EA2760
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::CallFunctionFromInterpreter(idThread *this, idInterpreter *source, idDecl *func, size_t args)
{
  this->waitingForThread = nullptr;
  this->waitingFor = 0x1FFF;
  this->waitingUntil = 0;
  this->waitingForEventId = 0;
  this->waitingForFlags = 0;
  this->waitingForFSM = false;
  idInterpreter::ThreadCall(this: &this->interpreter, source, func, args);
}


// ========================================================================
// ?ObjectMoveDone@idThread@@QAAXPAVidEntity@@@Z
// EA  : 0x82EA2788
// RVA : 0x00EA2788
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::ObjectMoveDone(idThread *this, idEntity *obj)
{
  BOOL v3; // r29
  __int64 v4; // r10
  __int64 v5; // r8
  int v6; // r6

  if ( this->waitingFor == obj->entityNumber )
  {
    this->waitingForThread = nullptr;
    this->waitingUntil = 0;
    this->waitingForEventId = 0;
    this->waitingForFlags = 0;
    this->waitingForFSM = false;
    this->waitingFor = 0x1FFF;
    idEventReceiver::CancelEvents(this, ev: &EV_Execute);
    v3 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) <= 0;
    idEventReceiver::PostEventMS(this, ev: &EV_Execute, time: v3, a4: v6, a5: v5, a6: v4);
  }
}


// ========================================================================
// ?ThreadCallback@idThread@@QAAXPAV1@@Z
// EA  : 0x82EA2818
// RVA : 0x00EA2818
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::ThreadCallback(idThread *this, idThread *thread)
{
  if ( !this->interpreter.threadDying && thread == this->waitingForThread )
  {
    this->waitingForThread = nullptr;
    this->waitingFor = 0x1FFF;
    this->waitingUntil = 0;
    this->waitingForEventId = 0;
    this->waitingForFlags = 0;
    this->waitingForFSM = false;
    idThread::DelayedStart(this, delay: 0);
  }
}


// ========================================================================
// ?Event_SetThreadName@idThread@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82EA2860
// RVA : 0x00EA2860
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_SetThreadName(idThread *this, eventVoid *result, const char *name)
{
  idStr::operator=(this: (idStr *)&result[40], text: name);
  return this;
}


// ========================================================================
// ?Event_GetThreadName@idThread@@AAA?AVeventString@@XZ
// EA  : 0x82EA28A0
// RVA : 0x00EA28A0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_GetThreadName(idThread *this, eventString *result)
{
  eventString::eventString((eventString *)this, s: result[11].value);
  return this;
}


// ========================================================================
// ?Event_GetThreadHandle@idThread@@AAA?AVeventInt@@XZ
// EA  : 0x82EA28D8
// RVA : 0x00EA28D8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_GetThreadHandle(idThread *this, eventInt *result)
{
  eventInt::eventInt((eventInt *)this, i: result[9].value);
  return this;
}


// ========================================================================
// ?Event_Execute@idThread@@AAA?AVeventVoid@@XZ
// EA  : 0x82EA2910
// RVA : 0x00EA2910
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Execute(idThread *this, idThread *result)
{
  idThread::Execute(this: result);
  return this;
}


// ========================================================================
// ?WaitSec@idThread@@QAAXM@Z
// EA  : 0x82EA2948
// RVA : 0x00EA2948
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::WaitSec(idThread *this, double time)
{
  __int128 v4; // r5

  if ( time > 0.0 )
  {
    this->waitingForThread = nullptr;
    this->waitingFor = 0x1FFF;
    this->waitingUntil = 0;
    this->waitingForEventId = 0;
    this->waitingForFlags = 0;
    this->waitingForFSM = false;
    this->interpreter.doneProcessing = true;
    *(_QWORD *)((char *)&v4 + 4) = ((__int64 (__fastcall *)(idGameLocal *))gameLocal->GetGameMsPerRealSec)(a1: gameLocal);
    LODWORD(v4) = DWORD1(v4);
    this->waitingUntil = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                       + (int)(float)((float)(__int64)v4 * (float)time);
  }
}


// ========================================================================
// ?WaitFrame@idThread@@QAAXXZ
// EA  : 0x82EA2A18
// RVA : 0x00EA2A18
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::WaitFrame(idThread *this)
{
  BOOL manualControl; // r10
  int GameMs; // r29

  manualControl = this->manualControl;
  this->waitingForThread = nullptr;
  this->waitingFor = 0x1FFF;
  this->waitingUntil = 0;
  this->waitingForEventId = 0;
  this->waitingForFlags = 0;
  this->waitingForFSM = false;
  this->interpreter.doneProcessing = true;
  if ( !manualControl )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->waitingUntil = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                       + GameMs;
  }
}


// ========================================================================
// ?WaitThread@idThread@@QAAXV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@@Z
// EA  : 0x82EA2AA0
// RVA : 0x00EA2AA0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::WaitThread(idThread *this, const idHandle<int,enum invalidThreadHandle_t,0> *threadHandle)
{
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  idThread *Thread; // r3
  int v8; // [sp+8h] [-78h]
  int v9; // [sp+Ch] [-74h]
  int v10; // [sp+10h] [-70h]
  int v11; // [sp+14h] [-6Ch]
  int v12; // [sp+18h] [-68h]
  int v13; // [sp+1Ch] [-64h]

  Thread = idThreadManager::GetThread(this: &gameLocal->program.threadManager, threadHandle);
  if ( Thread != nullptr )
  {
    this->waitingForThread = Thread;
    this->waitingUntil = 0;
    this->waitingFor = 0x1FFF;
    this->waitingForEventId = 0;
    this->waitingForFlags = 0;
    this->waitingForFSM = false;
    this->interpreter.doneProcessing = true;
  }
  else
  {
    LODWORD(v4) = &g_debugScript;
    if ( g_debugScript.valueInteger != 0 )
    {
      HIDWORD(v6) = threadHandle;
      idThread::Warning(
        this,
        fmt: "Thread %d not running",
        a3: v6,
        a4: v5,
        a5: v4,
        a6: v8,
        a7: v9,
        a8: v10,
        a9: v11,
        a10: v12,
        a11: v13);
    }
  }
}


// ========================================================================
// ?Event_EndThread@idThread@@AAA?AVeventVoid@@XZ
// EA  : 0x82EA2B48
// RVA : 0x00EA2B48
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_EndThread(idThread *this, eventVoid *result)
{
  idThreadManager::KillThread(
    this: &gameLocal->program.threadManager,
    threadHandle: *(const idHandle<int,enum invalidThreadHandle_t,0> **)&result[36]);
  return this;
}


// ========================================================================
// ?Event_Terminate@idThread@@AAA?AVeventVoid@@H@Z
// EA  : 0x82EA2B90
// RVA : 0x00EA2B90
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Terminate(
        idThread *this,
        eventVoid *result,
        const idHandle<int,enum invalidThreadHandle_t,0> *handle)
{
  idThreadManager::KillThread(this: &gameLocal->program.threadManager, threadHandle: handle);
  return this;
}


// ========================================================================
// ?Event_Pause@idThread@@AAA?AVeventVoid@@XZ
// EA  : 0x82EA2BD8
// RVA : 0x00EA2BD8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idThread::Event_Pause(idThread *this)
{
  __int64 result; // r4 OVERLAPPED

  *(_DWORD *)(result + 12) = 0;
  *(_DWORD *)(result + 16) = 0x1FFF;
  *(_DWORD *)(result + 20) = 0;
  *(_DWORD *)(result + 24) = 0;
  *(_DWORD *)(result + 28) = 0;
  *(_BYTE *)(result + 32) = 0;
  *(_BYTE *)(result + 84) = 1;
  return result;
}


// ========================================================================
// ?Event_Wait@idThread@@AAA?AVeventVoid@@M@Z
// EA  : 0x82EA2C08
// RVA : 0x00EA2C08
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Wait(idThread *this, idThread *result, double time)
{
  idThread::WaitSec(this: result, time);
  return this;
}


// ========================================================================
// ?Event_WaitFrame@idThread@@AAA?AVeventVoid@@XZ
// EA  : 0x82EA2C40
// RVA : 0x00EA2C40
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_WaitFrame(idThread *this, idThread *result)
{
  idThread::WaitFrame(this: result);
  return this;
}


// ========================================================================
// ?Event_WaitFor@idThread@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82EA2C78
// RVA : 0x00EA2C78
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_WaitFor(idThread *this, eventVoid *result, idEntity *ent)
{
  __int64 v6; // r10
  __int64 v7; // r8
  int v8; // r6
  idThread *v9; // r3
  idEventReceiver v10[5]; // [sp+50h] [-40h] BYREF

  if ( ent == nullptr )
    return this;
  LODWORD(v7) = ent->RespondsTo(this: ent, a2: &EV_SetCallback);
  if ( (_DWORD)v7 == 0 )
    return this;
  idEventReceiver::ProcessEvent(this: v10, result: ent, ev: &EV_SetCallback, a4: v8, a5: v7, a6: v6);
  v9 = this;
  if ( *gameLocal->program.returnDef->value.value.ip != 0 )
  {
    *(_DWORD *)&result[12] = 0;
    *(_DWORD *)&result[16] = 0x1FFF;
    *(_DWORD *)&result[20] = 0;
    *(_DWORD *)&result[24] = 0;
    *(_DWORD *)&result[28] = 0;
    result[32] = 0;
    result[84] = (eventVoid)1;
    *(_DWORD *)&result[16] = ent->entityNumber;
  }
  return v9;
}


// ========================================================================
// ?Event_WaitForThread@idThread@@AAA?AVeventVoid@@H@Z
// EA  : 0x82EA2D40
// RVA : 0x00EA2D40
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_WaitForThread(
        idThread *this,
        idThread *result,
        const idHandle<int,enum invalidThreadHandle_t,0> *threadHandle)
{
  idThread::WaitThread(this: result, threadHandle);
  return this;
}


// ========================================================================
// ?Event_WaitForEvent@idThread@@AAA?AVeventVoid@@H@Z
// EA  : 0x82EA2D78
// RVA : 0x00EA2D78
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idThread::Event_WaitForEvent@<r4>(idThread *this@<r3>, int result@<r4>, const int eventId@<r5>)
{
  *(_DWORD *)(result + 24) = eventId;
  *(_DWORD *)(result + 12) = 0;
  *(_DWORD *)(result + 16) = 0x1FFF;
  *(_DWORD *)(result + 20) = 0;
  *(_DWORD *)(result + 28) = 0;
  *(_BYTE *)(result + 32) = 0;
  *(_BYTE *)(result + 84) = 1;
  return result;
}


// ========================================================================
// ?Event_WaitForFlags@idThread@@AAA?AVeventVoid@@H@Z
// EA  : 0x82EA2DA8
// RVA : 0x00EA2DA8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idThread::Event_WaitForFlags@<r4>(idThread *this@<r3>, int result@<r4>, const int flags@<r5>)
{
  *(_DWORD *)(result + 28) = flags;
  *(_DWORD *)(result + 12) = 0;
  *(_DWORD *)(result + 16) = 0x1FFF;
  *(_DWORD *)(result + 20) = 0;
  *(_DWORD *)(result + 24) = 0;
  *(_BYTE *)(result + 32) = 0;
  *(_BYTE *)(result + 84) = 1;
  return result;
}


// ========================================================================
// ?Event_Print@idThread@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82EA2DD8
// RVA : 0x00EA2DD8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Print(idThread *this, eventVoid *result, const char *text)
{
  idLib::Printf(fmt: "%s", text);
  return this;
}


// ========================================================================
// ?Event_Println@idThread@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82EA2E18
// RVA : 0x00EA2E18
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Println(idThread *this, eventVoid *result, const char *text)
{
  idLib::Printf(fmt: "%s\n", text);
  return this;
}


// ========================================================================
// ?Event_Say@idThread@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82EA2E58
// RVA : 0x00EA2E58
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Say(idThread *this, eventVoid *result, __int64 text, __int64 a4, __int64 a5)
{
  va *v6; // r3
  int v8; // [sp+8h] [-1058h]
  int v9; // [sp+Ch] [-1054h]
  int v10; // [sp+10h] [-1050h]
  int v11; // [sp+14h] [-104Ch]
  int v12; // [sp+18h] [-1048h]
  int v13; // [sp+1Ch] [-1044h]
  va v14; // [sp+50h] [-1010h] BYREF

  v6 = va::va(this: &v14, fmt: "say \"%s\"", a3: text, a4, a5, a6: v8, a7: v9, a8: v10, a9: v11, a10: v12, a11: v13);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: v6->buffer);
  return this;
}


// ========================================================================
// ?Event_Trigger@idThread@@AAA?AVeventVoid@@PAVidEntity@@0@Z
// EA  : 0x82EA2EB8
// RVA : 0x00EA2EB8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Trigger(idThread *this, eventVoid *result, idEntity *ent, idEntity *activator)
{
  if ( ent != nullptr )
    idEntity::Activate(this: ent, activator);
  return this;
}


// ========================================================================
// ?Event_Setcvar@idThread@@ABA?AVeventVoid@@PBD0@Z
// EA  : 0x82EA2EF8
// RVA : 0x00EA2EF8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Setcvar(idThread *this, eventVoid *result, const char *name, const char *value)
{
  cvarSystem->SetCVarString(this: cvarSystem, a2: name, a3: value, a4: 0);
  return this;
}


// ========================================================================
// ?Event_Random@idThread@@ABA?AVeventFloat@@M@Z
// EA  : 0x82EA2F48
// RVA : 0x00EA2F48
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Random(idThread *this, eventFloat *result, double range)
{
  __int64 v3; // r10
  unsigned int v5; // r6

  HIDWORD(v3) = "plode - unlink clip";
  v5 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v5 + 1013904223;
  LODWORD(v3) = ((v5 + 1013904223) >> 10) & 0x7FFF;
  eventFloat::eventFloat((eventFloat *)this, f: (float)((float)((float)v3 * (float)0.000030518509) * (float)range));
  return this;
}


// ========================================================================
// ?Event_GetTime@idThread@@AAA?AVeventFloat@@XZ
// EA  : 0x82EA2FC8
// RVA : 0x00EA2FC8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_GetTime(idThread *this, eventFloat *result)
{
  __int64 v4; // [sp+50h] [-20h]

  v4 = __PAIR64__(
         &unk_82390000,
         idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
  eventFloat::eventFloat((eventFloat *)this, f: (float)((float)v4 * (float)0.001));
  return this;
}


// ========================================================================
// ?Event_KillThread@idThread@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82EA3038
// RVA : 0x00EA3038
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_KillThread(idThread *this, eventVoid *result, const char *name)
{
  idThreadManager::KillThread(this: &gameLocal->program.threadManager, name);
  return this;
}


// ========================================================================
// ?Event_ThreadCall@idThread@@AAA?AVeventVoid@@PAVidEntity@@PBD@Z
// EA  : 0x82EA3080
// RVA : 0x00EA3080
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_ThreadCall(
        idThread *this,
        eventVoid *result,
        idHandle<int,enum invalidThreadHandle_t,0> *ent,
        const char *functionName)
{
  idThread *Thread; // r31
  idScriptObject *v9; // r29
  __int64 v10; // r8
  __int64 v11; // r6
  char *TypeName; // r3
  const idHandle<int,enum invalidThreadHandle_t,0> *v13; // [sp+50h] [-40h] BYREF

  if ( ent != nullptr && functionName != nullptr )
  {
    (*(void (__fastcall **)(const idHandle<int,enum invalidThreadHandle_t,0> **, idHandle<int,enum invalidThreadHandle_t,0> *, _DWORD))(ent->value + 356))(
      a1: &v13,
      a2: ent,
      a3: 0);
    Thread = idThreadManager::GetThread(this: &gameLocal->program.threadManager, threadHandle: v13);
    if ( Thread == nullptr )
    {
      idLib::Warning(fmt: "Entity '%s' has no script thread", (const char *)ent[4].value);
      return this;
    }
    v9 = (idScriptObject *)(*(int (__fastcall **)(idHandle<int,enum invalidThreadHandle_t,0> *))(ent->value + 336))(a1: ent);
    HIDWORD(v11) = idScriptObject::GetFunction(this: v9, name: functionName);
    if ( HIDWORD(v11) == 0 )
    {
      TypeName = idScriptObject::GetTypeName(this: v9);
      idLib::Error(fmt: "Function '%s' not found on script object '%s'", functionName, TypeName);
    }
    Thread->waitingForThread = nullptr;
    LODWORD(v11) = 1;
    Thread->waitingFor = 0x1FFF;
    Thread->waitingUntil = 0;
    Thread->waitingForEventId = 0;
    Thread->waitingForFlags = 0;
    Thread->waitingForFSM = false;
    idInterpreter::EnterObjectFunction(this: &Thread->interpreter, self: (idEntity *)ent, clearStack: v11, a4: v10);
    (*(void (__fastcall **)(idHandle<int,enum invalidThreadHandle_t,0> *, idThread *))(ent->value + 372))(
      a1: ent,
      a2: Thread);
    idThread::DelayedStart(this: Thread, delay: 0);
  }
  return this;
}


// ========================================================================
// ?Event_GetEntity@idThread@@AAA?AVeventEntity@@PBD@Z
// EA  : 0x82EA31B0
// RVA : 0x00EA31B0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_GetEntity(idThread *this, idThread *result, const char *name)
{
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  unsigned int v9; // r3
  idEntity *v11; // r29
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  int v15; // [sp+8h] [-88h]
  int v16; // [sp+Ch] [-84h]
  int v17; // [sp+10h] [-80h]
  int v18; // [sp+14h] [-7Ch]
  int v19; // [sp+18h] [-78h]
  int v20; // [sp+1Ch] [-74h]

  if ( *name == 42 )
  {
    v9 = atol(nptr: name + 1);
    if ( v9 >= 0x2000 )
    {
      idThread::Error(
        this: result,
        fmt: "getEntity() - Entity number in string out of range.",
        a3: v8,
        a4: v7,
        a5: v6,
        a6: v15,
        a7: v16,
        a8: v17,
        a9: v18,
        a10: v19,
        a11: v20);
      eventEntity::eventEntity((eventEntity *)this);
    }
    else
    {
      eventEntity::eventEntity((eventEntity *)this, e: gameLocal->entities.ptr[v9]);
    }
    return this;
  }
  else
  {
    v11 = gameLocal->FindEntity(this: gameLocal, a2: name);
    if ( v11 == nullptr )
    {
      if ( *name != 0 )
        HIDWORD(v14) = name;
      else
        HIDWORD(v14) = "<null>";
      idThread::Warning(
        this: result,
        fmt: "getEntity() - Entity name not found! '%s'",
        a3: v14,
        a4: v13,
        a5: v12,
        a6: v15,
        a7: v16,
        a8: v17,
        a9: v18,
        a10: v19,
        a11: v20);
    }
    eventEntity::eventEntity((eventEntity *)this, e: v11);
    return this;
  }
}


// ========================================================================
// ?Event_AngToRight@idThread@@AAA?AVeventVector@@ABVidAngles@@@Z
// EA  : 0x82EA32A8
// RVA : 0x00EA32A8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_AngToRight(idThread *this, eventVector *result, idAngles *ang)
{
  eventVector v5; // [sp+50h] [-20h] BYREF

  idAngles::ToVectors(this: ang, forward: nullptr, right: &v5.value, up: nullptr);
  eventVector::eventVector((eventVector *)this, v: &v5);
  return this;
}


// ========================================================================
// ?Event_AngToUp@idThread@@AAA?AVeventVector@@ABVidAngles@@@Z
// EA  : 0x82EA32F8
// RVA : 0x00EA32F8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_AngToUp(idThread *this, eventVector *result, idAngles *ang)
{
  eventVector v5; // [sp+50h] [-20h] BYREF

  idAngles::ToVectors(this: ang, forward: nullptr, right: nullptr, up: &v5.value);
  eventVector::eventVector((eventVector *)this, v: &v5);
  return this;
}


// ========================================================================
// ?Event_Sin@idThread@@AAA?AVeventFloat@@M@Z
// EA  : 0x82EA3348
// RVA : 0x00EA3348
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idThread *__fastcall idThread::Event_Sin(idThread *this, eventFloat *result, double angle)
{
  long double v4; // fp2
  long double v5; // fp2

  *(double *)&v4 = (float)(idMath::M_DEG2RAD * (float)angle);
  v5 = sin(x: v4);
  eventFloat::eventFloat((eventFloat *)this, f: (float)*(double *)&v5);
  return this;
}


// ========================================================================
// ?Event_Cos@idThread@@AAA?AVeventFloat@@M@Z
// EA  : 0x82EA3390
// RVA : 0x00EA3390
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idThread *__fastcall idThread::Event_Cos(idThread *this, eventFloat *result, double angle)
{
  long double v4; // fp2
  long double v5; // fp2

  *(double *)&v4 = (float)(idMath::M_DEG2RAD * (float)angle);
  v5 = cos(x: v4);
  eventFloat::eventFloat((eventFloat *)this, f: (float)*(double *)&v5);
  return this;
}


// ========================================================================
// ?Event_Tan@idThread@@AAA?AVeventFloat@@M@Z
// EA  : 0x82EA33D8
// RVA : 0x00EA33D8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idThread *__fastcall idThread::Event_Tan(idThread *this, eventFloat *result, double angle)
{
  long double v4; // fp2
  long double v5; // fp2

  *(double *)&v4 = (float)(idMath::M_DEG2RAD * (float)angle);
  v5 = tan(x: v4);
  eventFloat::eventFloat((eventFloat *)this, f: (float)*(double *)&v5);
  return this;
}


// ========================================================================
// ?Event_ArcSin@idThread@@AAA?AVeventFloat@@M@Z
// EA  : 0x82EA3420
// RVA : 0x00EA3420
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_ArcSin(idThread *this, eventFloat *result, long double value)
{
  double v4; // fp1

  v4 = idMath::ASin(a: value);
  eventFloat::eventFloat((eventFloat *)this, f: (float)((float)v4 * idMath::M_RAD2DEG));
  return this;
}


// ========================================================================
// ?Event_ArcCos@idThread@@AAA?AVeventFloat@@M@Z
// EA  : 0x82EA3468
// RVA : 0x00EA3468
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_ArcCos(idThread *this, eventFloat *result, long double value)
{
  double v4; // fp1

  v4 = idMath::ACos(a: value);
  eventFloat::eventFloat((eventFloat *)this, f: (float)((float)v4 * idMath::M_RAD2DEG));
  return this;
}


// ========================================================================
// ?Event_ArcTan@idThread@@AAA?AVeventFloat@@M@Z
// EA  : 0x82EA34B0
// RVA : 0x00EA34B0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_ArcTan(idThread *this, eventFloat *result, long double value)
{
  long double v4; // fp2

  v4 = atan(x: value);
  eventFloat::eventFloat((eventFloat *)this, f: (float)(idMath::M_RAD2DEG * (float)*(double *)&v4));
  return this;
}


// ========================================================================
// ?Event_ArcTan2@idThread@@AAA?AVeventFloat@@MM@Z
// EA  : 0x82EA34F8
// RVA : 0x00EA34F8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

eventFloat *__fastcall idThread::Event_ArcTan2(eventFloat *a1, long double x, long double a3)
{
  long double v4; // fp2

  v4 = atan2(v: x, u: a3);
  eventFloat::eventFloat(this: a1, f: (float)(idMath::M_RAD2DEG * (float)*(double *)&v4));
  return a1;
}


// ========================================================================
// ?Event_Sqrt@idThread@@AAA?AVeventFloat@@M@Z
// EA  : 0x82EA3540
// RVA : 0x00EA3540
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Sqrt(idThread *this, eventFloat *result, double theSquare)
{
  eventFloat::eventFloat((eventFloat *)this, f: __fsqrts(theSquare));
  return this;
}


// ========================================================================
// ?Event_VecNormalize@idThread@@AAA?AVeventVector@@ABVidVec3@@@Z
// EA  : 0x82EA3578
// RVA : 0x00EA3578
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_VecNormalize(idThread *this, eventVector *result, const idVec3 *vec)
{
  double z; // fp9
  double v7; // fp2
  double v8; // fp5
  double v9; // fp3
  double v10; // fp2
  double v11; // fp0
  eventVector v13; // [sp+50h] [-20h] BYREF

  z = vec->z;
  _FP5 = (float)((float)((float)(vec->y * vec->y) + (float)((float)(vec->z * vec->z) + (float)(vec->x * vec->x)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v7 = __frsqrte(_FP3);
  v8 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v7
                                                                                     * (float)((float)((float)(vec->y * vec->y) + (float)((float)(vec->z * vec->z) + (float)(vec->x * vec->x)))
                                                                                             * (float)0.5))
                                                                             * (float)v7)
                                                                     - (float)1.5)
                                                     * (float)v7)
                                             * (float)((float)((float)(vec->y * vec->y)
                                                             + (float)((float)(vec->z * vec->z)
                                                                     + (float)(vec->x * vec->x)))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v7
                                                                             * (float)((float)((float)(vec->y * vec->y)
                                                                                             + (float)((float)(vec->z * vec->z) + (float)(vec->x * vec->x)))
                                                                                     * (float)0.5))
                                                                     * (float)v7)
                                                             - (float)1.5)
                                             * (float)v7))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v7
                                                     * (float)((float)((float)(vec->y * vec->y)
                                                                     + (float)((float)(vec->z * vec->z)
                                                                             + (float)(vec->x * vec->x)))
                                                             * (float)0.5))
                                             * (float)v7)
                                     - (float)1.5)
                     * (float)v7));
  v9 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v7 * (float)((float)((float)(vec->y * vec->y) + (float)((float)(vec->z * vec->z) + (float)(vec->x * vec->x))) * (float)0.5)) * (float)v7) - (float)1.5)
                                                                                     * (float)v7)
                                                                             * (float)((float)((float)(vec->y * vec->y)
                                                                                             + (float)((float)(vec->z * vec->z) + (float)(vec->x * vec->x)))
                                                                                     * (float)0.5))
                                                                     * (float)((float)-(float)((float)((float)((float)v7 * (float)((float)((float)(vec->y * vec->y) + (float)((float)(vec->z * vec->z) + (float)(vec->x * vec->x))) * (float)0.5)) * (float)v7)
                                                                                             - (float)1.5)
                                                                             * (float)v7))
                                                             - (float)1.5)
                                             * (float)((float)-(float)((float)((float)((float)v7
                                                                                     * (float)((float)((float)(vec->y * vec->y) + (float)((float)(vec->z * vec->z) + (float)(vec->x * vec->x)))
                                                                                             * (float)0.5))
                                                                             * (float)v7)
                                                                     - (float)1.5)
                                                     * (float)v7))
                                     * (float)((float)((float)(vec->y * vec->y)
                                                     + (float)((float)(vec->z * vec->z) + (float)(vec->x * vec->x)))
                                             * (float)0.5))
                             * (float)v8)
                     - (float)1.5);
  v10 = (float)((float)v9
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v7
                                                                                              * (float)((float)((float)(vec->y * vec->y) + (float)((float)(vec->z * vec->z) + (float)(vec->x * vec->x))) * (float)0.5))
                                                                                      * (float)v7)
                                                                              - (float)1.5)
                                                              * (float)v7)
                                                      * (float)((float)((float)(vec->y * vec->y)
                                                                      + (float)((float)(vec->z * vec->z)
                                                                              + (float)(vec->x * vec->x)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v7
                                                                                      * (float)((float)((float)(vec->y * vec->y) + (float)((float)(vec->z * vec->z) + (float)(vec->x * vec->x)))
                                                                                              * (float)0.5))
                                                                              * (float)v7)
                                                                      - (float)1.5)
                                                      * (float)v7))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v7
                                                              * (float)((float)((float)(vec->y * vec->y)
                                                                              + (float)((float)(vec->z * vec->z)
                                                                                      + (float)(vec->x * vec->x)))
                                                                      * (float)0.5))
                                                      * (float)v7)
                                              - (float)1.5)
                              * (float)v7)));
  v11 = (float)((float)v10 * vec->y);
  v13.value.x = (float)v10 * vec->x;
  v13.value.y = v11;
  v13.value.z = (float)z * (float)v10;
  eventVector::eventVector((eventVector *)this, v: &v13);
  return this;
}


// ========================================================================
// ?Event_VecLength@idThread@@AAA?AVeventFloat@@ABVidVec3@@@Z
// EA  : 0x82EA3630
// RVA : 0x00EA3630
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_VecLength(idThread *this, eventFloat *result, const idVec3 *vec)
{
  eventFloat::eventFloat(
    (eventFloat *)this,
    f: __fsqrts((float)((float)(vec->z * vec->z) + (float)((float)(vec->x * vec->x) + (float)(vec->y * vec->y)))));
  return this;
}


// ========================================================================
// ?Event_VecDotProduct@idThread@@AAA?AVeventFloat@@ABVidVec3@@0@Z
// EA  : 0x82EA3680
// RVA : 0x00EA3680
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_VecDotProduct(
        idThread *this,
        eventFloat *result,
        const idVec3 *vec1,
        const idVec3 *vec2)
{
  eventFloat::eventFloat(
    (eventFloat *)this,
    f: (float)((float)(vec1->x * vec2->x) + (float)((float)(vec1->z * vec2->z) + (float)(vec1->y * vec2->y))));
  return this;
}


// ========================================================================
// ?Event_VecCrossProduct@idThread@@AAA?AVeventVector@@ABVidVec3@@0@Z
// EA  : 0x82EA36D8
// RVA : 0x00EA36D8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_VecCrossProduct(
        idThread *this,
        eventVector *result,
        const idVec3 *vec1,
        const idVec3 *vec2)
{
  double z; // fp12
  double x; // fp10
  double v7; // fp6
  double v8; // fp4
  eventVector v10; // [sp+50h] [-20h] BYREF

  z = vec1->z;
  x = vec2->x;
  v7 = (float)(vec1->x * vec2->z);
  v8 = (float)((float)(vec1->x * vec2->y) - (float)(vec2->x * vec1->y));
  v10.value.x = (float)(vec2->z * vec1->y) - (float)(vec2->y * vec1->z);
  v10.value.z = v8;
  v10.value.y = (float)((float)x * (float)z) - (float)v7;
  eventVector::eventVector((eventVector *)this, v: &v10);
  return this;
}


// ========================================================================
// ?Event_VecToAngles@idThread@@AAA?AVeventVector@@ABVidVec3@@@Z
// EA  : 0x82EA3748
// RVA : 0x00EA3748
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_VecToAngles(idThread *this, eventVector *result, idAngles *vec)
{
  idVec3 v5; // [sp+50h] [-30h] BYREF
  eventVector v6; // [sp+60h] [-20h] BYREF

  idVec3::ToAngles(this: &v5, result: vec);
  v6.value.x = v5.x;
  v6.value.y = v5.y;
  v6.value.z = v5.z;
  eventVector::eventVector((eventVector *)this, v: &v6);
  return this;
}


// ========================================================================
// ?Event_OnSignal@idThread@@AAA?AVeventVoid@@HPAVidEntity@@PBD@Z
// EA  : 0x82EA37A8
// RVA : 0x00EA37A8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_OnSignal(idThread *this, idThread *result, __int64 ent, __int64 func, __int64 a5)
{
  int v8; // r27
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  int v13; // [sp+8h] [-A8h]
  int v14; // [sp+Ch] [-A4h]
  int v15; // [sp+10h] [-A0h]
  int v16; // [sp+14h] [-9Ch]
  int v17; // [sp+18h] [-98h]
  int v18; // [sp+1Ch] [-94h]

  v8 = HIDWORD(func);
  if ( (_DWORD)ent != 0 )
  {
    if ( HIDWORD(ent) >= 0xC )
    {
      idThread::Error(
        this: result,
        fmt: "Signal out of range",
        a3: ent,
        a4: func,
        a5,
        a6: v13,
        a7: v14,
        a8: v15,
        a9: v16,
        a10: v17,
        a11: v18);
      return this;
    }
    else
    {
      LODWORD(v12) = idProgram::FindFunction(this: &gameLocal->program, name: (const char *)HIDWORD(func));
      if ( (_DWORD)v12 != 0 )
      {
        idEntity::SetSignal(
          this: (idEntity *)ent,
          signalnum: SHIDWORD(ent),
          thread: result,
          function: (const function_t *)v12);
      }
      else
      {
        HIDWORD(v12) = v8;
        idThread::Error(
          this: result,
          fmt: "Function '%s' not found",
          a3: v12,
          a4: v11,
          a5: v10,
          a6: v13,
          a7: v14,
          a8: v15,
          a9: v16,
          a10: v17,
          a11: v18);
      }
      return this;
    }
  }
  else
  {
    idThread::Error(
      this: result,
      fmt: "Entity not found",
      a3: ent,
      a4: func,
      a5,
      a6: v13,
      a7: v14,
      a8: v15,
      a9: v16,
      a10: v17,
      a11: v18);
    return this;
  }
}


// ========================================================================
// ?Event_ClearSignalThread@idThread@@AAA?AVeventVoid@@HPAVidEntity@@@Z
// EA  : 0x82EA3878
// RVA : 0x00EA3878
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_ClearSignalThread(
        idThread *this,
        idThread *result,
        __int64 ent,
        __int64 a4,
        __int64 a5)
{
  const char *v7; // r4
  int v9; // [sp+8h] [-78h]
  int v10; // [sp+Ch] [-74h]
  int v11; // [sp+10h] [-70h]
  int v12; // [sp+14h] [-6Ch]
  int v13; // [sp+18h] [-68h]
  int v14; // [sp+1Ch] [-64h]

  if ( (_DWORD)ent == 0 )
  {
    v7 = "Entity not found";
LABEL_6:
    idThread::Error(this: result, fmt: v7, a3: ent, a4, a5, a6: v9, a7: v10, a8: v11, a9: v12, a10: v13, a11: v14);
    return this;
  }
  if ( HIDWORD(ent) >= 0xC )
  {
    v7 = "Signal out of range";
    goto LABEL_6;
  }
  idEntity::ClearSignalThread(this: (idEntity *)ent, signalnum: SHIDWORD(ent), thread: result);
  return this;
}


// ========================================================================
// ?Event_Trace@idThread@@AAA?AVeventFloat@@ABVidVec3@@000HPAVidEntity@@@Z
// EA  : 0x82EA38F0
// RVA : 0x00EA38F0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Trace(
        idThread *this,
        eventFloat *result,
        const idVec3 *start,
        const idVec3 *end,
        const idVec3 *mins,
        const idVec3 *maxs,
        int contents_mask,
        idEntity *passEntity)
{
  double z; // fp12
  double y; // fp13
  char v11; // r11
  char v12; // r11
  int entityNumber; // r8

  z = vec3_origin.z;
  y = vec3_origin.y;
  if ( mins->x != vec3_origin.x || mins->y != y || (v11 = 1, mins->z != z) )
    v11 = 0;
  if ( v11 != 0 )
  {
    if ( maxs->x != vec3_origin.x || maxs->y != y || (v12 = 1, maxs->z != z) )
      v12 = 0;
    if ( v12 != 0 )
    {
      if ( passEntity != nullptr )
        entityNumber = passEntity->entityNumber;
      else
        entityNumber = 0x1FFF;
      idClip::TracePoint(
        this: &clientGame->clip,
        result: &gameLocal->program.threadManager.trace,
        start,
        end,
        clipMask: contents_mask,
        passEntityNumber: entityNumber);
    }
  }
  eventFloat::eventFloat((eventFloat *)this, f: gameLocal->program.threadManager.trace.fraction);
  return this;
}


// ========================================================================
// ?Event_TracePoint@idThread@@AAA?AVeventFloat@@ABVidVec3@@0HPAVidEntity@@@Z
// EA  : 0x82EA39E0
// RVA : 0x00EA39E0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_TracePoint(
        idThread *this,
        eventFloat *result,
        const idVec3 *start,
        const idVec3 *end,
        int contents_mask,
        idEntity *passEntity)
{
  int entityNumber; // r8

  if ( passEntity != nullptr )
    entityNumber = passEntity->entityNumber;
  else
    entityNumber = 0x1FFF;
  idClip::TracePoint(
    this: &clientGame->clip,
    result: &gameLocal->program.threadManager.trace,
    start,
    end,
    clipMask: contents_mask,
    passEntityNumber: entityNumber);
  eventFloat::eventFloat((eventFloat *)this, f: gameLocal->program.threadManager.trace.fraction);
  return this;
}


// ========================================================================
// ?Event_GetTraceFraction@idThread@@AAA?AVeventFloat@@XZ
// EA  : 0x82EA3A48
// RVA : 0x00EA3A48
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_GetTraceFraction(idThread *this, eventFloat *result)
{
  eventFloat::eventFloat((eventFloat *)this, f: gameLocal->program.threadManager.trace.fraction);
  return this;
}


// ========================================================================
// ?Event_GetTraceEndPos@idThread@@AAA?AVeventVector@@XZ
// EA  : 0x82EA3A90
// RVA : 0x00EA3A90
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_GetTraceEndPos(idThread *this, eventVector *result)
{
  eventVector::eventVector((eventVector *)this, v: (eventVector *)&gameLocal->program.threadManager.trace.endpos);
  return this;
}


// ========================================================================
// ?Event_GetTraceNormal@idThread@@AAA?AVeventVector@@XZ
// EA  : 0x82EA3AD0
// RVA : 0x00EA3AD0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_GetTraceNormal(idThread *this, eventVector *result)
{
  eventVector *p_normal; // r4

  if ( gameLocal->program.threadManager.trace.fraction >= 1.0 )
    p_normal = (eventVector *)&vec3_origin;
  else
    p_normal = (eventVector *)&gameLocal->program.threadManager.trace.c.normal;
  eventVector::eventVector((eventVector *)this, v: p_normal);
  return this;
}


// ========================================================================
// ?Event_GetTraceEntity@idThread@@AAA?AVeventEntity@@XZ
// EA  : 0x82EA3B38
// RVA : 0x00EA3B38
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_GetTraceEntity(idThread *this, eventEntity *result)
{
  idEntity *v3; // r4

  if ( gameLocal->program.threadManager.trace.fraction >= 1.0 )
    v3 = nullptr;
  else
    v3 = gameLocal->entities.ptr[gameLocal->program.threadManager.trace.c.entityNum];
  eventEntity::eventEntity((eventEntity *)this, e: v3);
  return this;
}


// ========================================================================
// ?Event_DisableSaves@idThread@@AAA?AVeventVoid@@XZ
// EA  : 0x82EA3BB0
// RVA : 0x00EA3BB0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::Event_DisableSaves(idThread *this, eventVoid *result)
{
  gameLocal->savesEnabled = false;
}


// ========================================================================
// ?Event_EnableSaves@idThread@@AAA?AVeventVoid@@XZ
// EA  : 0x82EA3BD0
// RVA : 0x00EA3BD0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::Event_EnableSaves(idThread *this, eventVoid *result)
{
  gameLocal->savesEnabled = true;
}


// ========================================================================
// ?Event_Warning@idThread@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82EA3BF0
// RVA : 0x00EA3BF0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Warning(idThread *this, idThread *result, __int64 text, __int64 a4, __int64 a5)
{
  int v7; // [sp+8h] [-78h]
  int v8; // [sp+Ch] [-74h]
  int v9; // [sp+10h] [-70h]
  int v10; // [sp+14h] [-6Ch]
  int v11; // [sp+18h] [-68h]
  int v12; // [sp+1Ch] [-64h]

  idThread::Warning(this: result, fmt: "%s", a3: text, a4, a5, a6: v7, a7: v8, a8: v9, a9: v10, a10: v11, a11: v12);
  return this;
}


// ========================================================================
// ?Event_Error@idThread@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82EA3C30
// RVA : 0x00EA3C30
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Error(idThread *this, idThread *result, __int64 text, __int64 a4, __int64 a5)
{
  int v7; // [sp+8h] [-78h]
  int v8; // [sp+Ch] [-74h]
  int v9; // [sp+10h] [-70h]
  int v10; // [sp+14h] [-6Ch]
  int v11; // [sp+18h] [-68h]
  int v12; // [sp+1Ch] [-64h]

  idThread::Error(this: result, fmt: "%s", a3: text, a4, a5, a6: v7, a7: v8, a8: v9, a9: v10, a10: v11, a11: v12);
  return this;
}


// ========================================================================
// ?Event_StrLength@idThread@@AAA?AVeventInt@@PBD@Z
// EA  : 0x82EA3C70
// RVA : 0x00EA3C70
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_StrLength(idThread *this, eventInt *result, const char *string)
{
  int v4; // r4

  v4 = 0;
  if ( *string != 0 )
  {
    do
      ++v4;
    while ( string[v4] != 0 );
  }
  eventInt::eventInt((eventInt *)this, i: v4);
  return this;
}


// ========================================================================
// ?Event_StrLeft@idThread@@AAA?AVeventString@@PBDH@Z
// EA  : 0x82EA3CD0
// RVA : 0x00EA3CD0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_StrLeft(idThread *this, eventString *result, const char *string, int num)
{
  int v5; // r11
  idStr v7; // [sp+50h] [-40h] BYREF

  if ( num >= 0 )
  {
    v5 = 0;
    if ( *string != 0 )
    {
      do
        ++v5;
      while ( string[v5] != 0 );
    }
    if ( v5 >= num )
    {
      v7.len = 0;
      v7.baseBuffer[0] = 0;
      v7.allocedAndFlag = 20;
      v7.data = v7.baseBuffer;
      idStr::CopyRange(this: &v7, text: string, start: 0, end: num);
      eventString::eventString((eventString *)this, s: v7.data);
      idStr::FreeData(this: &v7);
    }
    else
    {
      eventString::eventString((eventString *)this, s: string);
    }
  }
  else
  {
    eventString::eventString((eventString *)this, s: &byte_8200D768);
  }
  return this;
}


// ========================================================================
// __unwind$490570
// EA  : 0x82EA3D94
// RVA : 0x00EA3D94
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void _unwind_490570()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?Event_StrRight@idThread@@AAA?AVeventString@@PBDH@Z
// EA  : 0x82EA3DC0
// RVA : 0x00EA3DC0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_StrRight(idThread *this, eventString *result, const char *string, int num)
{
  const char *v5; // r4
  int v6; // r11

  if ( num >= 0 )
  {
    v6 = 0;
    if ( *string != 0 )
    {
      do
        ++v6;
      while ( string[v6] != 0 );
    }
    if ( v6 >= num )
      v5 = &string[v6 - num];
    else
      v5 = string;
  }
  else
  {
    v5 = &byte_8200D768;
  }
  eventString::eventString((eventString *)this, s: v5);
  return this;
}


// ========================================================================
// ?Event_StrSkip@idThread@@AAA?AVeventString@@PBDH@Z
// EA  : 0x82EA3E40
// RVA : 0x00EA3E40
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_StrSkip(idThread *this, eventString *result, const char *string, int num)
{
  const char *v5; // r4
  int v6; // r11

  if ( num >= 0 )
  {
    v6 = 0;
    if ( *string != 0 )
    {
      do
        ++v6;
      while ( string[v6] != 0 );
    }
    if ( v6 >= num )
      v5 = &string[num];
    else
      v5 = &byte_8200D768;
  }
  else
  {
    v5 = string;
  }
  eventString::eventString((eventString *)this, s: v5);
  return this;
}


// ========================================================================
// ?Event_StrMid@idThread@@AAA?AVeventString@@PBDHH@Z
// EA  : 0x82EA3EC8
// RVA : 0x00EA3EC8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_StrMid(
        idThread *this,
        eventString *result,
        const char *string,
        unsigned int start,
        int num)
{
  signed int v7; // r11
  signed int v8; // r5
  idStr v10; // [sp+50h] [-40h] BYREF

  if ( num >= 0 )
  {
    v7 = 0;
    v8 = ((start >> 31) - 1) & start;
    if ( *string != 0 )
    {
      do
        ++v7;
      while ( string[v7] != 0 );
    }
    if ( v8 > v7 )
      v8 = v7;
    if ( v8 + num > v7 )
      num = v7 - v8;
    v10.len = 0;
    v10.baseBuffer[0] = 0;
    v10.allocedAndFlag = 20;
    v10.data = v10.baseBuffer;
    idStr::CopyRange(this: &v10, text: string, start: v8, end: v8 + num);
    eventString::eventString((eventString *)this, s: v10.data);
    idStr::FreeData(this: &v10);
  }
  else
  {
    eventString::eventString((eventString *)this, s: &byte_8200D768);
  }
  return this;
}


// ========================================================================
// __unwind$490658_0
// EA  : 0x82EA3FA0
// RVA : 0x00EA3FA0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void _unwind_490658_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?Event_KillByType@idThread@@AAA?AVeventVoid@@PBVidEntity@@W4entityTypeFlags_t@1@@Z
// EA  : 0x82EA3FC8
// RVA : 0x00EA3FC8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

eventVoid *__fastcall idThread::Event_KillByType(
        idThread *this,
        eventVoid *result,
        const idEntity *boundsEntity,
        idThread::entityTypeFlags_t flags,
        int a5,
        int a6,
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
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        idClipModel *a27)
{
  int v27; // r19
  int v28; // r6
  idEntity *v29; // r5
  char v30; // r11
  char v31; // r23
  char v32; // r22
  char v33; // r24
  char v34; // r21
  bool v35; // r20
  idPhysics *Physics; // r3
  const idBounds *v37; // r3
  __int64 v38; // r8
  int v39; // r6
  const char *ClipModelsTouchingBounds; // r3
  idClipModel **v41; // r27
  const char *v42; // r26
  __int64 v43; // r10
  idAI2 *v44; // r30
  char v45; // r31
  idAI2 *v46; // r3
  idAIHealth_vtbl *v47; // r11
  idAIHealth *p_aiHealth; // r3
  float (__fastcall *GetCurBaseHealth_Impl)(struct idAIHealth *); // ctr

  v27 = ((int (*)(void))RtlCheckStack12)();
  if ( v29 != nullptr && v28 != 0 )
  {
    v30 = 0;
    v31 = 0;
    v32 = 0;
    v33 = 0;
    v34 = 0;
    v35 = (v28 & 1) != 0;
    if ( (v28 & 2) != 0 )
    {
      v30 = 1;
      v33 = 1;
    }
    if ( (v28 & 4) != 0 )
    {
      v31 = 1;
      v32 = v30;
      v33 = 1;
    }
    if ( (v28 & 8) != 0 )
      v34 = 1;
    Physics = idEntity::GetPhysics(this: v29);
    v37 = Physics->GetAbsBounds(this: Physics, a2: -1);
    ClipModelsTouchingBounds = idClip::GetClipModelsTouchingBounds(
                                 this: &clientGame->clip,
                                 bounds: v37,
                                 clipMask: 0x7FFFFFFF,
                                 clipModelList: &a27,
                                 maxCount: (const char *)0x2000);
    if ( (int)ClipModelsTouchingBounds > 0 )
    {
      v41 = &a27;
      v42 = ClipModelsTouchingBounds;
      while ( 1 )
      {
        if ( *v41 != nullptr )
        {
          LODWORD(v43) = gameLocal;
          HIDWORD(v43) = (*v41)->entityNumber + 21563;
          LODWORD(v38) = 4 * HIDWORD(v43);
          v44 = *((idAI2 **)&gameLocal->__vftable + HIDWORD(v43));
          if ( v44 != nullptr )
            break;
        }
LABEL_30:
        --v42;
        ++v41;
        if ( v42 == nullptr )
          return (eventVoid *)v27;
      }
      v45 = 0;
      if ( v33 == 0 || idAI2::CastTo(c: *(idAI2 **)((char *)&gameLocal->__vftable + v38)) == nullptr )
        goto LABEL_21;
      if ( v32 == 0 )
      {
        v46 = idAI2::CastTo(c: v44);
        v47 = v46->aiHealth.__vftable;
        p_aiHealth = &v46->aiHealth;
        GetCurBaseHealth_Impl = v47->GetCurBaseHealth_Impl;
        if ( v31 != 0 )
        {
          if ( ((double (__fastcall *)(idAIHealth *))GetCurBaseHealth_Impl)(a1: p_aiHealth) <= 0.0 )
            goto LABEL_20;
LABEL_21:
          if ( v34 != 0 && idTurret::CastTo(c: (idTurret *)v44) != nullptr
            || v35
            && idAI2::CastTo(c: v44) == nullptr
            && idTurret::CastTo(c: (idTurret *)v44) == nullptr
            && idPlayer::CastTo(c: (idPlayer *)v44) == nullptr )
          {
            v45 = 1;
          }
          if ( v45 != 0 )
            idEventReceiver::PostEventMS(this: v44, ev: &EV_Remove, time: 0, a4: v39, a5: v38, a6: v43);
          goto LABEL_30;
        }
        if ( ((double (__fastcall *)(idAIHealth *))GetCurBaseHealth_Impl)(a1: p_aiHealth) <= 0.0 )
          goto LABEL_21;
      }
LABEL_20:
      v45 = 1;
      goto LABEL_21;
    }
  }
  return (eventVoid *)v27;
}


// ========================================================================
// ?Event_GetFrameTime@idThread@@AAA?AVeventFloat@@XZ
// EA  : 0x82EA41F8
// RVA : 0x00EA41F8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_GetFrameTime(idThread *this, eventFloat *result)
{
  __int64 v4; // [sp+50h] [-20h]

  v4 = __PAIR64__(
         &unk_82390000,
         idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
  eventFloat::eventFloat((eventFloat *)this, f: (float)((float)v4 * (float)0.001));
  return this;
}


// ========================================================================
// ?Event_FadeSoundGroup@idThread@@AAA?AVeventVoid@@W4soundShaderGroups_t@@MM@Z
// EA  : 0x82EA4268
// RVA : 0x00EA4268
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_FadeSoundGroup(
        idThread *this,
        eventVoid *result,
        soundShaderGroups_t groupNum,
        double toDB,
        double overSec)
{
  ((void (__fastcall *)(idSoundWorld *, soundShaderGroups_t, soundShaderGroups_t, int, double))clientGame->soundWorld->Fade)(
    a1: clientGame->soundWorld,
    a2: groupNum,
    a3: groupNum,
    a4: (int)(float)((float)1000.0 * (float)overSec),
    a5: toDB);
  return this;
}


// ========================================================================
// ?Event_DebugLine@idThread@@AAA?AVeventVoid@@ABVidVec3@@00M@Z
// EA  : 0x82EA42D0
// RVA : 0x00EA42D0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_DebugLine(
        idThread *this,
        eventVoid *result,
        const idVec3 *color,
        const idVec3 *start,
        const idVec3 *end,
        double lifetime)
{
  double z; // fp12
  float v9[4]; // [sp+60h] [-20h] BYREF

  v9[0] = color->x;
  z = color->z;
  v9[1] = color->y;
  v9[3] = 0.0;
  v9[2] = z;
  clientGame->renderWorld->DebugLine(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)v9,
    a3: start,
    a4: end,
    a5: (int)(float)((float)1000.0 * (float)lifetime),
    a6: false);
  return this;
}


// ========================================================================
// ?Event_DebugArrow@idThread@@AAA?AVeventVoid@@ABVidVec3@@00HM@Z
// EA  : 0x82EA4368
// RVA : 0x00EA4368
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_DebugArrow(
        idThread *this,
        eventVoid *result,
        const idVec3 *color,
        const idVec3 *start,
        const idVec3 *end,
        const int size,
        double lifetime,
        __int64 a8)
{
  double z; // fp12
  float v11[4]; // [sp+60h] [-20h] BYREF

  LODWORD(a8) = size;
  v11[0] = color->x;
  z = color->z;
  v11[1] = color->y;
  v11[3] = 0.0;
  v11[2] = z;
  ((void (__fastcall *)(idRenderWorld *, float *, const idVec3 *, const idVec3 *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: v11,
    a3: start,
    a4: end,
    a5: (float)a8);
  return this;
}


// ========================================================================
// ?Event_DebugCircle@idThread@@AAA?AVeventVoid@@ABVidVec3@@00MHM@Z
// EA  : 0x82EA4418
// RVA : 0x00EA4418
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_DebugCircle(
        idThread *this,
        eventVoid *result,
        const idVec3 *color,
        const idVec3 *origin,
        const idVec3 *dir,
        double radius,
        const int numSteps,
        double lifetime)
{
  double z; // fp12
  float v11[4]; // [sp+60h] [-20h] BYREF

  v11[0] = color->x;
  z = color->z;
  v11[1] = color->y;
  v11[3] = 0.0;
  v11[2] = z;
  ((void (__fastcall *)(idRenderWorld *, float *, const idVec3 *, const idVec3 *, double))clientGame->renderWorld->DebugCircle)(
    a1: clientGame->renderWorld,
    a2: v11,
    a3: origin,
    a4: dir,
    a5: radius);
  return this;
}


// ========================================================================
// ?Event_DebugBounds@idThread@@AAA?AVeventVoid@@ABVidVec3@@00M@Z
// EA  : 0x82EA44B8
// RVA : 0x00EA44B8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_DebugBounds(
        idThread *this,
        eventVoid *result,
        const idVec3 *color,
        const idVec3 *mins,
        const idVec3 *maxs,
        double lifetime)
{
  double y; // fp12
  double z; // fp11
  double x; // fp10
  double v10; // fp9
  double v11; // fp7
  double v12; // fp6
  double v13; // fp5
  double v14; // fp4
  float v16[4]; // [sp+60h] [-40h] BYREF
  float v17[8]; // [sp+70h] [-30h] BYREF

  y = mins->y;
  z = mins->z;
  x = maxs->x;
  v10 = maxs->y;
  v11 = maxs->z;
  v12 = color->x;
  v13 = color->y;
  v14 = color->z;
  v17[0] = mins->x;
  v16[3] = 0.0;
  v17[1] = y;
  v17[2] = z;
  v17[3] = x;
  v17[4] = v10;
  v17[5] = v11;
  v16[0] = v12;
  v16[1] = v13;
  v16[2] = v14;
  clientGame->renderWorld->DebugBounds(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)v16,
    a3: (const idBounds *)v17,
    a4: &vec3_origin,
    a5: (int)(float)((float)1000.0 * (float)lifetime),
    a6: false);
  return this;
}


// ========================================================================
// ?Event_DrawText@idThread@@AAA?AVeventVoid@@PBDABVidVec3@@M1HM@Z
// EA  : 0x82EA4588
// RVA : 0x00EA4588
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_DrawText(
        idThread *this,
        eventVoid *result,
        const char *text,
        const idVec3 *origin,
        double scale,
        const idVec3 *color,
        float *align,
        double lifetime,
        int a9)
{
  double v10; // fp12
  float v12[4]; // [sp+70h] [-20h] BYREF

  v12[0] = *align;
  v10 = align[2];
  v12[1] = align[1];
  v12[2] = v10;
  v12[3] = 0.0;
  ((void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), float *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
    a1: clientGame->renderWorld,
    a2: text,
    a3: origin,
    a4: clientGame->renderWorld->DebugText,
    a5: v12,
    a6: a9,
    a7: (int)(float)((float)1000.0 * (float)lifetime),
    a8: 0,
    a9: scale);
  return this;
}


// ========================================================================
// ?Event_DestroyArray@idThread@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82EA4630
// RVA : 0x00EA4630
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_DestroyArray(idThread *this, eventVoid *result, idEntity *entity)
{
  gameLocal->DeleteEntity(this: gameLocal, a2: entity);
  return this;
}


// ========================================================================
// ?Event_RandomInt@idThread@@ABA?AVeventInt@@H@Z
// EA  : 0x82EA4678
// RVA : 0x00EA4678
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_RandomInt(idThread *this, eventInt *result, int range)
{
  unsigned int v4; // r6
  int v5; // r3
  int v6; // r4

  if ( range <= 0 )
  {
    v6 = 0;
  }
  else
  {
    __twllei(range, 0);
    v4 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v4;
    v5 = (v4 >> 10) & 0x7FFF;
    v6 = v5 % range;
    __twlgei(range & ~(__ROL4__(v5, 1) - 1), 0xFFFFFFFF);
  }
  eventInt::eventInt((eventInt *)this, i: v6);
  return this;
}


// ========================================================================
// ?Event_GetDeclName@idThread@@AAA?AVeventString@@PBVidDecl@@@Z
// EA  : 0x82EA4708
// RVA : 0x00EA4708
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_GetDeclName(idThread *this, eventString *result, const idDecl *decl)
{
  char *str; // r4

  if ( decl != nullptr )
    str = (char *)decl->name.str;
  else
    str = &byte_8200D768;
  eventString::eventString((eventString *)this, s: str);
  return this;
}


// ========================================================================
// ?Event_ExecuteCommandText@idThread@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82EA4750
// RVA : 0x00EA4750
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_ExecuteCommandText(idThread *this, eventVoid *result, const char *command)
{
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: command);
  return this;
}


// ========================================================================
// ?Event_PlayerIsIncapacitated@idThread@@AAA?AVeventBool@@XZ
// EA  : 0x82EA4798
// RVA : 0x00EA4798
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_PlayerIsIncapacitated(idThread *this, eventBool *result)
{
  unsigned int v3; // r31
  idPlayer *Player; // r3
  idPresentable *presentable; // r3
  int v6; // r3

  v3 = 0;
  while ( 1 )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: v3);
    if ( Player != nullptr )
    {
      presentable = Player->presentable;
      v6 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
      if ( (*(_BYTE *)(v6 + 47032) & 4) != 0 )
        break;
    }
    if ( (int)++v3 >= 2 )
    {
      eventBool::eventBool((eventBool *)this, b: false);
      return this;
    }
  }
  eventBool::eventBool((eventBool *)this, b: true);
  return this;
}


// ========================================================================
// ??0idThread@@QAA@XZ
// EA  : 0x82EA4848
// RVA : 0x00EA4848
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::idThread(idThread *this)
{
  __int64 v2; // r6
  __int64 v3; // r10
  __int64 v4; // r8
  va *v5; // r3
  char *data; // r28
  int GameMs; // r3
  int v9; // [sp+8h] [-1098h]
  int v10; // [sp+Ch] [-1094h]
  int v11; // [sp+10h] [-1090h]
  int v12; // [sp+14h] [-108Ch]
  int v13; // [sp+18h] [-1088h]
  int v14; // [sp+1Ch] [-1084h]
  idThreadManager v15[27]; // [sp+50h] [-1050h] BYREF

  idEventReceiver::idEventReceiver(this);
  this->waitingForThread = nullptr;
  this->__vftable = (idThread_vtbl *)&idThread::`vftable';
  this->waitingFor = 0x1FFF;
  this->waitingUntil = 0;
  this->waitingForEventId = 0;
  this->waitingForFlags = 0;
  this->waitingForFSM = false;
  this->threadHandle.value = 0;
  this->threadName.data = this->threadName.baseBuffer;
  this->threadName.allocedAndFlag = 20;
  this->threadName.len = 0;
  v15[0].currentThread = (idThread *)&this->threadHandle;
  this->threadName.baseBuffer[0] = 0;
  this->lastExecuteTime = 0;
  this->creationTime = 0;
  this->manualControl = false;
  idInterpreter::idInterpreter(this: &this->interpreter);
  this->threadEntity.spawnId.value = 0x1FFF;
  v15[0].currentThread = (idThread *)&this->threadEntity;
  this->threadHandle = (idHandle<int,enum invalidThreadHandle_t,0>)idThreadManager::AddThread(
                                                                     this: v15,
                                                                     result: (idHandle<int,enum invalidThreadHandle_t,0> *)&gameLocal->program.threadManager,
                                                                     thread: this)->value;
  this->creationTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idInterpreter::SetThread(this: &this->interpreter, pThread: this);
  HIDWORD(v2) = this->threadHandle.value;
  v5 = va::va(
         this: (va *)&v15[0].threadList.size,
         fmt: "thread_%d",
         a3: v2,
         a4: v4,
         a5: v3,
         a6: v9,
         a7: v10,
         a8: v11,
         a9: v12,
         a10: v13,
         a11: v14);
  idStr::operator=(this: &this->threadName, text: v5->buffer);
  if ( g_debugScript.valueInteger != 0 )
  {
    data = this->threadName.data;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "%d: create thread (%d) '%s'\n", GameMs, this->threadHandle.value, data);
  }
  return this;
}


// ========================================================================
// __unwind$491180_0
// EA  : 0x82EA49A4
// RVA : 0x00EA49A4
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void _unwind_491180_0()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 4256 + 4276));
}


// ========================================================================
// __unwind$491181_0
// EA  : 0x82EA49CC
// RVA : 0x00EA49CC
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void _unwind_491181_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 4256 + 4276) + 40));
}


// ========================================================================
// ?Start@idThread@@QAA_NXZ
// EA  : 0x82EA4A58
// RVA : 0x00EA4A58
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

int __fastcall idThread::Start(idThread *this)
{
  idEventReceiver::CancelEvents(this, ev: &EV_Execute);
  return idThread::Execute(this);
}


// ========================================================================
// ?Event_Spawn@idThread@@AAA?AVeventEntity@@PBD@Z
// EA  : 0x82EA4A98
// RVA : 0x00EA4A98
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Spawn(idThread *this, idThread *result, __int64 classname, __int64 a4, __int64 a5)
{
  _BYTE *v7; // r31
  const idDeclEntityDef *v8; // r30
  idEntity *v9; // r3
  int v11; // [sp+8h] [-88h]
  int v12; // [sp+Ch] [-84h]
  int v13; // [sp+10h] [-80h]
  int v14; // [sp+14h] [-7Ch]
  int v15; // [sp+18h] [-78h]
  int v16; // [sp+1Ch] [-74h]

  v7 = (_BYTE *)HIDWORD(classname);
  if ( HIDWORD(classname) != 0 )
  {
    v8 = (const idDeclEntityDef *)idDeclInfo::FindWithInheritance(
                                    this: &idDeclEntityDef::resourceList,
                                    name: (const char *)HIDWORD(classname),
                                    makeDefault: false);
    if ( v8 != nullptr )
      goto LABEL_5;
    if ( *v7 != 0 )
    {
      HIDWORD(classname) = v7;
      goto LABEL_4;
    }
  }
  else
  {
    v8 = nullptr;
  }
  HIDWORD(classname) = "<null>";
LABEL_4:
  idThread::Warning(
    this: result,
    fmt: "spawn() - Entity def name not found! '%s'",
    a3: classname,
    a4,
    a5,
    a6: v11,
    a7: v12,
    a8: v13,
    a9: v14,
    a10: v15,
    a11: v16);
LABEL_5:
  v9 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: v8, a3: -1, a4: -1, a5: -1);
  eventEntity::eventEntity((eventEntity *)this, e: v9);
  return this;
}


// ========================================================================
// ?Event_SpawnDecal@idThread@@AAA?AVeventVoid@@PBVidEntity@@ABVidVec3@@11MPBVidMaterial@@@Z
// EA  : 0x82EA4B48
// RVA : 0x00EA4B48
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_SpawnDecal(
        idThread *this,
        idThread *result,
        __int64 pos,
        __int64 size,
        double lifeTime,
        __int64 material)
{
  idEntity *v9; // r31
  const idVec3 *v10; // r26
  const idVec3 *v11; // r25
  float *v12; // r30
  float v13; // r29
  idPresentable *presentable; // r11
  double v15; // fp12
  idRenderModel *model; // r31
  int GameMs; // r3
  int v19; // [sp+8h] [-108h]
  int v20; // [sp+Ch] [-104h]
  int v21; // [sp+10h] [-100h]
  int v22; // [sp+14h] [-FCh]
  int v23; // [sp+18h] [-F8h]
  int v24; // [sp+1Ch] [-F4h]
  int v25; // [sp+90h] [-80h] BYREF
  int v26; // [sp+94h] [-7Ch]
  float v27[8]; // [sp+A0h] [-70h] BYREF
  char v28; // [sp+C0h] [-50h]

  v9 = (idEntity *)HIDWORD(pos);
  v10 = (const idVec3 *)pos;
  v11 = (const idVec3 *)HIDWORD(size);
  v12 = (float *)size;
  v13 = *((float *)&material + 1);
  if ( HIDWORD(pos) == 0 )
    goto LABEL_9;
  presentable = *(idPresentable **)(HIDWORD(pos) + 488);
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: (idEntity *)HIDWORD(pos));
    presentable = v9->presentable;
  }
  LODWORD(material) = presentable->model;
  if ( (_DWORD)material != 0 && v13 != 0.0 )
  {
    v27[1] = v12[2];
    v15 = v12[1];
    v27[2] = *v12;
    v27[7] = 0.0;
    LODWORD(v27[6]) = 2000;
    v27[3] = v15;
    v27[0] = v13;
    v27[4] = 0.0;
    v28 = 0;
    v26 = (int)(float)((float)lifeTime * (float)1000.0);
    LODWORD(v27[5]) = v26;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: v9);
      presentable = v9->presentable;
    }
    model = presentable->model;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    model->AddDecalFromPoint(
      this: (idRenderModel *)&v25,
      result: (idHandle<int,enum invalidDecalHandle_t,-1> *)model,
      a3: (const decalParams_t *)v27,
      a4: GameMs,
      a5: v10,
      a6: v11,
      a7: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)NULL_JOINT_INDEX.value);
    return this;
  }
  else
  {
LABEL_9:
    idThread::Error(
      this: result,
      fmt: "Event_SpawnDecal() - bad entity or material",
      a3: pos,
      a4: size,
      a5: material,
      a6: v19,
      a7: v20,
      a8: v21,
      a9: v22,
      a10: v23,
      a11: v24);
    return this;
  }
}


// ========================================================================
// ?Event_Music@idThread@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82EA4C98
// RVA : 0x00EA4C98
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Music(idThread *this, eventVoid *result, const idSoundShader *text)
{
  const idSoundShader *v4; // r4

  v4 = text;
  if ( text != nullptr )
    v4 = (const idSoundShader *)idDeclInfo::FindWithInheritance(
                                  this: &idSoundShader::resourceList,
                                  name: (const char *)text,
                                  makeDefault: true);
  clientGame->soundWorld->PlayGlobalShaderDirectly(this: clientGame->soundWorld, a2: v4, a3: SND_CHANNEL_ANY, a4: 0.0);
  return this;
}


// ========================================================================
// ?Event_RadiusDamage@idThread@@AAA?AVeventVoid@@ABVidVec3@@PAVidEntity@@11PBDM@Z
// EA  : 0x82EA4D10
// RVA : 0x00EA4D10
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_RadiusDamage(
        idThread *this,
        eventVoid *result,
        const idVec3 *origin,
        idEntity *inflictor,
        idPlayer *attacker,
        idEntity *ignore,
        const char *damageDefName,
        double dmgPower)
{
  __int64 v13; // r10
  int v14; // r8
  const idDeclDamage *v15; // r7

  if ( damageDefName != nullptr )
  {
    v15 = (const idDeclDamage *)idDeclInfo::FindWithInheritance(
                                  this: &idDeclDamage::resourceList,
                                  name: damageDefName,
                                  makeDefault: true);
    if ( v15 != nullptr )
      idGameLocal::RadiusDamage(
        this: gameLocal,
        origin,
        inflictor,
        attacker,
        damageDef: v15,
        dmgPower,
        a7: v14,
        a8: v13);
  }
  return this;
}


// ========================================================================
// ?Event_CacheSoundShader@idThread@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82EA4D88
// RVA : 0x00EA4D88
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idEntity *__fastcall idThread::Event_CacheSoundShader(idEntity *this, eventVoid *result, const char *soundName)
{
  if ( soundName != nullptr )
    idDeclInfo::FindWithInheritance(this: &idSoundShader::resourceList, name: soundName, makeDefault: true);
  return this;
}


// ========================================================================
// ?Event_IsLayerActive@idThread@@AAA?AVeventBool@@PBD@Z
// EA  : 0x82EA4DD8
// RVA : 0x00EA4DD8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_IsLayerActive(idThread *this, eventBool *result, const char *layerName)
{
  idStaticList<idStrStatic<128>,256> *p_layersActive; // r29
  int v6; // r28
  int v7; // r30
  idStr v9[2]; // [sp+50h] [-50h] BYREF

  p_layersActive = &gameLocal->GetGameSpawnInfo(this: gameLocal)->layersActive;
  idStr::idStr(this: v9, text: layerName);
  v6 = 0;
  if ( p_layersActive->num <= 0 )
  {
LABEL_5:
    eventBool::eventBool((eventBool *)this, b: false);
  }
  else
  {
    v7 = 0;
    while ( idStr::Cmp(s1: v9[0].data, s2: p_layersActive->list[v7].data) != 0 )
    {
      ++v6;
      ++v7;
      if ( v6 >= p_layersActive->num )
        goto LABEL_5;
    }
    eventBool::eventBool((eventBool *)this, b: true);
  }
  idStr::FreeData(this: v9);
  return this;
}


// ========================================================================
// __unwind$491449
// EA  : 0x82EA4E8C
// RVA : 0x00EA4E8C
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void _unwind_491449()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Event_IsLayerDeactive@idThread@@AAA?AVeventBool@@PBD@Z
// EA  : 0x82EA4EC0
// RVA : 0x00EA4EC0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_IsLayerDeactive(idThread *this, eventBool *result, const char *layerName)
{
  idStaticList<idStrStatic<128>,256> *p_layersDeactive; // r29
  int v6; // r28
  int v7; // r30
  idStr v9[2]; // [sp+50h] [-50h] BYREF

  p_layersDeactive = &gameLocal->GetGameSpawnInfo(this: gameLocal)->layersDeactive;
  idStr::idStr(this: v9, text: layerName);
  v6 = 0;
  if ( p_layersDeactive->num <= 0 )
  {
LABEL_5:
    eventBool::eventBool((eventBool *)this, b: false);
  }
  else
  {
    v7 = 0;
    while ( idStr::Cmp(s1: v9[0].data, s2: p_layersDeactive->list[v7].data) != 0 )
    {
      ++v6;
      ++v7;
      if ( v6 >= p_layersDeactive->num )
        goto LABEL_5;
    }
    eventBool::eventBool((eventBool *)this, b: true);
  }
  idStr::FreeData(this: v9);
  return this;
}


// ========================================================================
// __unwind$491491
// EA  : 0x82EA4F78
// RVA : 0x00EA4F78
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void _unwind_491491()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?SetThreadEntity@idThread@@QAAXPAVidEntity@@@Z
// EA  : 0x82EA4FA0
// RVA : 0x00EA4FA0
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void __fastcall idThread::SetThreadEntity(idThread *this, idEntity *ent)
{
  int value; // r10
  idEntity *v5; // r3
  int v6; // r9
  idGameLocal *v7; // r11
  idEntity *v8; // r3
  idEntity *v9; // r3
  int v10; // r9
  idEntity *v11; // r3
  idEntity *v12; // r3
  eventVoid *v13; // r4
  idThread *v14; // r3

  value = this->threadEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr && idEntity::CastTo(c: v5) != nullptr )
    {
      v6 = this->threadEntity.spawnId.value;
      v7 = gameLocal;
      if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13 && (v8 = gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
      {
        v9 = idEntity::CastTo(c: v8);
        v7 = gameLocal;
      }
      else
      {
        v9 = nullptr;
      }
      if ( v9 != ent )
      {
        v10 = this->threadEntity.spawnId.value;
        if ( v7->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13 && (v11 = v7->entities.ptr[v10 & 0x1FFF]) != nullptr )
          v12 = idEntity::CastTo(c: v11);
        else
          v12 = nullptr;
        idLib::Error(fmt: "Thread %d already has a threadEntity '%s'", this->threadHandle.value, v12->name.data);
      }
    }
  }
  if ( ent->AddThread(this: ent, a2: (const idHandle<int,enum invalidThreadHandle_t,0> *)this->threadHandle.value) < 0 )
  {
    idLib::Error(fmt: "Entity '%s' : too many threads.\n", ent->name.data);
    idThread::Event_Remove(this: v14, result: v13);
  }
  else
  {
    this->threadEntity.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  }
}


// ========================================================================
// ?Event_Remove@idThread@@AAA?AVeventVoid@@XZ
// EA  : 0x82EA50F8
// RVA : 0x00EA50F8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_Remove(idThread *this, eventVoid *result)
{
  int v2; // r10
  idEntity *v5; // r3
  idEntity *v6; // r3

  v2 = *(_DWORD *)&result[7056];
  if ( gameLocal->spawnIds.ptr[v2 & 0x1FFF] == v2 >> 13 )
  {
    v5 = gameLocal->entities.ptr[v2 & 0x1FFF];
    if ( v5 != nullptr )
    {
      v6 = idEntity::CastTo(c: v5);
      if ( v6 != nullptr )
        v6->RemoveThread(this: v6, a2: *(const idHandle<int,enum invalidThreadHandle_t,0> **)&result[36]);
    }
  }
  if ( result != nullptr )
    (*(void (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 4))(a1: result, a2: 1);
  return this;
}


// ========================================================================
// ?Event_GetMapPath@idThread@@AAA?AVeventString@@XZ
// EA  : 0x82EA51B8
// RVA : 0x00EA51B8
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_GetMapPath(idThread *this, eventString *result)
{
  const char *v3; // r3
  idStr v5; // [sp+50h] [-40h] BYREF

  v3 = (const char *)((int (__fastcall *)(idGameLocal *, eventString *))gameLocal->GetMapName)(
                       a1: gameLocal,
                       a2: result);
  idStr::idStr(this: &v5, text: v3);
  idStr::Append(this: &v5, text: "/");
  eventString::eventString((eventString *)this, s: v5.data);
  idStr::FreeData(this: &v5);
  return this;
}


// ========================================================================
// __unwind$491868
// EA  : 0x82EA5238
// RVA : 0x00EA5238
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

void _unwind_491868()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?Event_SetThreadEntity@idThread@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82EA5260
// RVA : 0x00EA5260
// PDB : w:\tech5\tungsten\game\script\thread.cpp
// ========================================================================

idThread *__fastcall idThread::Event_SetThreadEntity(idThread *this, idThread *result, idEntity *ent)
{
  idThread::SetThreadEntity(this: result, ent);
  return this;
}

