#include "sys_threading.h"

#include <cstdint>

idSysMutex::idSysMutex()
    : handle(CreateMutexA(nullptr, FALSE, nullptr)) {
}

idSysMutex::~idSysMutex() {
    if (handle != nullptr) CloseHandle(static_cast<HANDLE>(handle));
    handle = nullptr;
}

bool idSysMutex::Lock(const bool blocking) {
    if (handle == nullptr) return false;
    const DWORD result = WaitForSingleObject(static_cast<HANDLE>(handle),
        blocking ? INFINITE : 0);
    return result == WAIT_OBJECT_0 || result == WAIT_ABANDONED;
}

void idSysMutex::Unlock() {
    if (handle != nullptr) ReleaseMutex(static_cast<HANDLE>(handle));
}

idSysSignal::idSysSignal(const bool manualReset)
    : handle(CreateEventA(nullptr, manualReset ? TRUE : FALSE, FALSE, nullptr)) {
}

idSysSignal::~idSysSignal() {
    if (handle != nullptr) CloseHandle(static_cast<HANDLE>(handle));
    handle = nullptr;
}

void idSysSignal::Raise() {
    if (handle != nullptr) SetEvent(static_cast<HANDLE>(handle));
}

void idSysSignal::Clear() {
    if (handle != nullptr) ResetEvent(static_cast<HANDLE>(handle));
}

bool idSysSignal::Wait(const int timeoutMilliseconds) const {
    if (handle == nullptr) return false;
    const DWORD timeout = timeoutMilliseconds < 0
        ? INFINITE
        : static_cast<DWORD>(timeoutMilliseconds);
    return WaitForSingleObject(static_cast<HANDLE>(handle), timeout)
        == WAIT_OBJECT_0;
}

idSysThread::idSysThread()
    : name(), threadHandle(0), isWorker(false), isRunning(false),
      isTerminating(false), moreWorkToDo(false), signalWorkerDone(true),
      signalMoreWorkToDo(false), signalMutex() {
}

idSysThread::~idSysThread() {
    StopThread(true);
    if (threadHandle != 0) {
        CloseHandle(reinterpret_cast<HANDLE>(
            static_cast<std::uintptr_t>(threadHandle)));
        threadHandle = 0;
    }
}

int idSysThread::Run() {
    return 0;
}

DWORD WINAPI idSysThread::ThreadProc(void* parameter) {
    idSysThread* const thread = static_cast<idSysThread*>(parameter);
    int result = 0;
    if (thread->isWorker) {
        for (;;) {
            thread->signalMutex.Lock();
            if (!thread->moreWorkToDo) {
                thread->signalWorkerDone.Raise();
                thread->signalMutex.Unlock();
                thread->signalMoreWorkToDo.Wait();
                continue;
            }
            thread->moreWorkToDo = false;
            thread->signalMoreWorkToDo.Clear();
            const bool terminate = thread->isTerminating;
            thread->signalMutex.Unlock();
            if (terminate) break;
            result = thread->Run();
        }
        thread->signalWorkerDone.Raise();
    } else {
        result = thread->Run();
    }
    thread->isRunning = false;
    return static_cast<DWORD>(result);
}

bool idSysThread::StartThread(const char* threadName, const core_t core,
        const xthreadPriority priority, const int stackSize) {
    if (isRunning) return false;
    name = threadName;
    isTerminating = false;
    if (threadHandle != 0) {
        HANDLE oldHandle = reinterpret_cast<HANDLE>(
            static_cast<std::uintptr_t>(threadHandle));
        WaitForSingleObject(oldHandle, INFINITE);
        CloseHandle(oldHandle);
        threadHandle = 0;
    }
    HANDLE handle = CreateThread(nullptr, static_cast<SIZE_T>(stackSize),
        ThreadProc, this, 0, nullptr);
    if (handle == nullptr) return false;
    threadHandle = static_cast<unsigned int>(
        reinterpret_cast<std::uintptr_t>(handle));
    static const int priorities[] = {
        THREAD_PRIORITY_LOWEST,
        THREAD_PRIORITY_BELOW_NORMAL,
        THREAD_PRIORITY_NORMAL,
        THREAD_PRIORITY_ABOVE_NORMAL,
        THREAD_PRIORITY_HIGHEST
    };
    const int priorityIndex = static_cast<int>(priority);
    if (priorityIndex >= 0 && priorityIndex < 5)
        SetThreadPriority(handle, priorities[priorityIndex]);
    if (core != CORE_ANY && static_cast<unsigned int>(core) < 32)
        SetThreadAffinityMask(handle, std::uintptr_t(1) << static_cast<int>(core));
    isRunning = true;
    return true;
}

bool idSysThread::StartWorkerThread(const char* threadName, const core_t core,
        const xthreadPriority priority, const int stackSize) {
    if (isRunning) return false;
    isWorker = true;
    signalWorkerDone.Clear();
    if (!StartThread(threadName, core, priority, stackSize)) return false;
    signalWorkerDone.Wait();
    return true;
}

void idSysThread::StopThread(const bool wait) {
    if (!isRunning) return;
    if (isWorker) {
        signalMutex.Lock();
        moreWorkToDo = true;
        signalWorkerDone.Clear();
        isTerminating = true;
        signalMoreWorkToDo.Raise();
        signalMutex.Unlock();
    } else {
        isTerminating = true;
    }
    if (wait) WaitForThread();
}

void idSysThread::WaitForThread() {
    if (isWorker) {
        signalWorkerDone.Wait();
        return;
    }
    if (threadHandle == 0) return;
    HANDLE handle = reinterpret_cast<HANDLE>(
        static_cast<std::uintptr_t>(threadHandle));
    WaitForSingleObject(handle, INFINITE);
    CloseHandle(handle);
    threadHandle = 0;
}

void idSysThread::SignalWork() {
    if (!isWorker) return;
    signalMutex.Lock();
    moreWorkToDo = true;
    signalWorkerDone.Clear();
    signalMoreWorkToDo.Raise();
    signalMutex.Unlock();
}

