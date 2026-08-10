#pragma once

#include "ai2_debug.h"
#include "idlib/containers/staticlist.h"

struct idAI2ScriptRuntime {
    idStaticList<idThreadHandle, 4> threads;
    idStaticList<idFiberHandle, 4> fibers;
    idThreadHandle legsFSMWaitThread;
};

struct idAI2CodeActionRuntime {
    bool hasAlertCycleFSM;
    bool isMoveToPointEnterEvent;
    bool currentStateExecutesCodeMove;
};

idAI2ScriptRuntime& Tungsten_GetAI2ScriptRuntime(idAI2& ai);
const idAI2ScriptRuntime& Tungsten_GetAI2ScriptRuntime(
    const idAI2& ai);
idThreadHandle Tungsten_GetAI2ThreadHandle(const idThread& thread);
bool Tungsten_IsAI2ThreadAlive(idThreadHandle handle);
bool Tungsten_IsAI2ThreadPresent(idThreadHandle handle);
bool Tungsten_IsAI2FiberValid(idFiberHandle handle);
void Tungsten_ExecuteAI2BaseThread(idAI2& ai, idThread& thread);
bool Tungsten_GetAI2CodeActionRuntime(const idAI2& ai,
    const idEventDef& action, idAI2CodeActionRuntime& runtime);
void Tungsten_SetAI2ExecuteCodeFSMStack(idAI2& ai);
