#include "win_fibers.h"

#include <cstdlib>
#include <cstring>

namespace {

char* CopyFiberName(const char* source) {
    const char* const text = source == nullptr ? "" : source;
    const std::size_t length = std::strlen(text);
    char* const copy = static_cast<char*>(std::malloc(length + 1));
    if (copy != nullptr) {
        std::memcpy(copy, text, length + 1);
    }
    return copy;
}

} // namespace

idSysFiber::idSysFiber(const char* fiberName)
    : name(CopyFiberName(fiberName))
    , alive(true)
    , fiber(nullptr)
    , parent(nullptr) {
    fiber = CreateFiber(0x20000u, &idSysFiber::FiberRoutine, this);
    if (fiber == nullptr) {
        alive = false;
    }
}

idSysFiber::~idSysFiber() {
    std::free(name);
    if (fiber != nullptr) {
        DeleteFiber(fiber);
    }
}

bool idSysFiber::Execute() {
    if (alive && fiber != nullptr) {
        parent = GetCurrentFiber();
        SwitchToFiber(fiber);
    }
    return alive;
}

void idSysFiber::YieldFiber() {
    if (parent != nullptr) {
        SwitchToFiber(parent);
    }
}

void WINAPI idSysFiber::FiberRoutine(void* data) {
    idSysFiber* const self = static_cast<idSysFiber*>(data);
    self->Run();
    self->alive = false;
    self->YieldFiber();

    // A finished Windows fiber must never return from its entry routine when
    // its parent is expected to retain control. Match the recovered guard.
    for (;;) {
        self->YieldFiber();
    }
}
