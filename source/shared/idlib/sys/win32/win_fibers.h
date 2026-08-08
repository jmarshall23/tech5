#pragma once

#include <Windows.h>

class idSysFiber {
public:
    explicit idSysFiber(const char* name);
    virtual ~idSysFiber();

    idSysFiber(const idSysFiber&) = delete;
    idSysFiber& operator=(const idSysFiber&) = delete;

    bool Execute();
    virtual void Run() = 0;

protected:
    void YieldFiber();

private:
    static void WINAPI FiberRoutine(void* data);

    char* name;
    bool alive;
    void* fiber;
    void* parent;
};

static_assert(sizeof(idSysFiber) == 20, "Recovered idSysFiber ABI changed");
