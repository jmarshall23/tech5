#pragma once

// Recovered from tungsten.exe types 1119 and 13204.
enum sysEventType_t : int {
    SE_NONE = 0,
    SE_KEY = 1,
    SE_CHAR = 2,
    SE_MOUSE = 3,
    SE_JOYSTICK = 4,
    SE_CONSOLE = 5
};

struct sysEvent_t {
    sysEventType_t evType;
    int evValue;
    int evValue2;
    int evPtrLength;
    void* evPtr;
    int inputDevice;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(sysEvent_t) == 24, "Recovered sysEvent_t ABI changed");
#endif
