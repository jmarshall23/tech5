#include "ai2_script.h"

// Retail symbol: ?ExecuteThread@idAI2@@UAAXPAVidThread@@@Z
// EA: 0x82A39200, RVA: 0x00A39200
void idAI2::ExecuteThread(idThread* const thread) {
    if (thread == nullptr) {
        return;
    }
    ResetFSMWaitThreadIfPossible(thread);
    Tungsten_ExecuteAI2BaseThread(*this, *thread);
}

// Retail symbol: ?AllThreadsAreFinished@idAI2@@QBA_NXZ
// EA: 0x82A39250, RVA: 0x00A39250
bool idAI2::AllThreadsAreFinished() const {
    const idAI2ScriptRuntime& runtime =
        Tungsten_GetAI2ScriptRuntime(*this);
    for (int index = 0; index < runtime.threads.Num(); ++index) {
        if (Tungsten_IsAI2ThreadAlive(runtime.threads[index])) {
            return false;
        }
    }
    for (int index = 0; index < runtime.fibers.Num(); ++index) {
        if (Tungsten_IsAI2FiberValid(runtime.fibers[index])) {
            return false;
        }
    }
    return true;
}

// Retail symbol: ?IsExecutingScript@idAI2@@QBA_NXZ
// EA: 0x82A39348, RVA: 0x00A39348
bool idAI2::IsExecutingScript() const {
    const idAI2ScriptRuntime& runtime =
        Tungsten_GetAI2ScriptRuntime(*this);
    return (runtime.threads.Num() != 0 || runtime.fibers.Num() != 0)
        && !AllThreadsAreFinished();
}

// Retail symbol: ?RemoveFiber@idAI2@@UAAXV?$idHandle@HW4invalidFiberId_t@@$0A@@@@Z
// EA: 0x82A393B0, RVA: 0x00A393B0
void idAI2::RemoveFiber(const idFiberHandle fiberHandle) {
    idAI2ScriptRuntime& runtime = Tungsten_GetAI2ScriptRuntime(*this);
    const int index = runtime.fibers.FindIndex(fiberHandle);
    if (index >= 0) {
        runtime.fibers.RemoveIndexFast(index);
    }
}

// Retail symbol:
// ?RemoveThread@idAI2@@UAAXV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@@Z
// EA: 0x82A39438, RVA: 0x00A39438
void idAI2::RemoveThread(const idThreadHandle threadHandle) {
    idAI2ScriptRuntime& runtime = Tungsten_GetAI2ScriptRuntime(*this);
    const int index = runtime.threads.FindIndex(threadHandle);
    if (index >= 0) {
        runtime.threads.RemoveIndexFast(index);
    }
}

// Retail symbol:
// ?GetThread@idAI2@@UBA?AV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@H@Z
// EA: 0x82A394C0, RVA: 0x00A394C0
idThreadHandle idAI2::GetThread(const int index) const {
    return Tungsten_GetAI2ScriptRuntime(*this).threads[index];
}

// Retail symbol: ?NumThreads@idAI2@@UBAHXZ
// EA: 0x82A394E0, RVA: 0x00A394E0
int idAI2::NumThreads() const {
    return Tungsten_GetAI2ScriptRuntime(*this).threads.Num();
}

// Retail symbol: ?ResetFSMWaitThreadIfPossible@idAI2@@UAAXPAVidThread@@@Z
// EA: 0x82A394F0, RVA: 0x00A394F0
void idAI2::ResetFSMWaitThreadIfPossible(idThread* const thread) {
    if (thread == nullptr) {
        return;
    }
    idAI2ScriptRuntime& runtime = Tungsten_GetAI2ScriptRuntime(*this);
    if (runtime.legsFSMWaitThread == Tungsten_GetAI2ThreadHandle(*thread)) {
        runtime.legsFSMWaitThread.Invalidate();
    }
}

// Retail symbol: ?ForceFSMIntoExecutingCodeAction@idAI2@@QAA_NABVidEventDef@@@Z
// EA: 0x82A395E0, RVA: 0x00A395E0
bool idAI2::ForceFSMIntoExecutingCodeAction(
        const idEventDef& action) {
    idAI2CodeActionRuntime runtime{};
    if (!Tungsten_GetAI2CodeActionRuntime(*this, action, runtime)
        || !runtime.hasAlertCycleFSM
        || !runtime.isMoveToPointEnterEvent
        || runtime.currentStateExecutesCodeMove) {
        return false;
    }
    Tungsten_SetAI2ExecuteCodeFSMStack(*this);
    return true;
}

// Retail symbol:
// ?AddThread@idAI2@@UAAHV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@@Z
// EA: 0x82A396B8, RVA: 0x00A396B8
int idAI2::AddThread(const idThreadHandle threadHandle) {
    idAI2ScriptRuntime& runtime = Tungsten_GetAI2ScriptRuntime(*this);
    for (int index = runtime.threads.Num() - 1; index >= 0; --index) {
        const idThreadHandle stored = runtime.threads[index];
        if (Tungsten_IsAI2ThreadPresent(stored)) {
            if (stored == threadHandle) {
                return index;
            }
            continue;
        }
        runtime.threads.RemoveIndexFast(index);
        if (stored == threadHandle) {
            return -1;
        }
    }
    return runtime.threads.Append(threadHandle);
}

// Retail symbol: ?AddFiber@idAI2@@UAAHV?$idHandle@HW4invalidFiberId_t@@$0A@@@@Z
// EA: 0x82A397A8, RVA: 0x00A397A8
int idAI2::AddFiber(const idFiberHandle fiberHandle) {
    idAI2ScriptRuntime& runtime = Tungsten_GetAI2ScriptRuntime(*this);
    for (int index = runtime.fibers.Num() - 1; index >= 0; --index) {
        const idFiberHandle stored = runtime.fibers[index];
        if (Tungsten_IsAI2FiberValid(stored)) {
            if (stored == fiberHandle) {
                return index;
            }
            continue;
        }
        runtime.fibers.RemoveIndexFast(index);
        if (stored == fiberHandle) {
            return -1;
        }
    }
    runtime.fibers.Append(fiberHandle);
    return runtime.fibers.Num();
}
