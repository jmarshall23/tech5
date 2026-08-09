#pragma once

#include "../text/str.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

#include <cstdint>

enum xthreadPriority : int {
    THREAD_LOWEST = 0,
    THREAD_BELOW_NORMAL = 1,
    THREAD_NORMAL = 2,
    THREAD_ABOVE_NORMAL = 3,
    THREAD_HIGHEST = 4
};

enum core_t : int {
    CORE_ANY = -1,
    CORE_0A = 0,
    CORE_0B = 1,
    CORE_1A = 2,
    CORE_1B = 3,
    CORE_2A = 4,
    CORE_2B = 5
};

class idSysMutex {
public:
    void* handle;

    idSysMutex();
    ~idSysMutex();
    bool Lock(bool blocking = true);
    void Unlock();

    idSysMutex(const idSysMutex&) = delete;
    idSysMutex& operator=(const idSysMutex&) = delete;
};

class idSysSignal {
public:
    void* handle;

    explicit idSysSignal(bool manualReset = false);
    ~idSysSignal();
    void Raise();
    void Clear();
    bool Wait(int timeoutMilliseconds = -1) const;

    idSysSignal(const idSysSignal&) = delete;
    idSysSignal& operator=(const idSysSignal&) = delete;
};

class idSysThread {
public:
    idSysThread();
    virtual ~idSysThread();
    virtual int Run();

    bool StartThread(const char* threadName, core_t core = CORE_ANY,
        xthreadPriority priority = THREAD_NORMAL, int stackSize = 0x20000);
    bool StartWorkerThread(const char* threadName, core_t core = CORE_ANY,
        xthreadPriority priority = THREAD_NORMAL, int stackSize = 0x20000);
    void StopThread(bool wait = true);
    void WaitForThread();
    void SignalWork();

    bool IsRunning() const { return isRunning; }
    bool IsTerminating() const { return isTerminating; }
    const char* GetName() const { return name.c_str(); }

    idStr name;
    unsigned int threadHandle;
    bool isWorker;
    bool isRunning;
    volatile bool isTerminating;
    volatile bool moreWorkToDo;
    idSysSignal signalWorkerDone;
    idSysSignal signalMoreWorkToDo;
    idSysMutex signalMutex;

private:
    static DWORD WINAPI ThreadProc(void* parameter);
};

struct ssThreadInfo_t {
    int spawnId;
    int objectId;
    const char* name;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idSysMutex) == 4, "Recovered idSysMutex ABI changed");
static_assert(sizeof(idSysSignal) == 4, "Recovered idSysSignal ABI changed");
static_assert(sizeof(idSysThread) == 56, "Recovered idSysThread ABI changed");
static_assert(sizeof(ssThreadInfo_t) == 12, "Recovered ssThreadInfo_t ABI changed");
#endif
