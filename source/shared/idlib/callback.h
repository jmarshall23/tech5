#pragma once

#include "containers/list.h"
#include "math/vector.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#include <cstdint>

enum gpuCallback_t : int {
    GPUTAG_START_FRAME = 0,
    GPUTAG_END_FRAME = 1
};

struct _XOKERBINFO;
struct _XOTSKERBINFO;

// This Xbox service interface is retained as recovered ABI evidence only. It
// has no PC implementation and is not used by the reconstructed idLib target.
struct IXoCallback {
    virtual int XoKerbBuildApReq(unsigned int, LARGE_INTEGER*,
        unsigned char*, unsigned int, unsigned char*, unsigned int*) = 0;
    virtual int XoKerbCrackApRep(unsigned int, LARGE_INTEGER*, unsigned int,
        unsigned char*, unsigned int, unsigned char*, unsigned int) = 0;
    virtual _XOKERBINFO* XoKerbGetInfo(unsigned int) = 0;
    virtual unsigned int XoGetServiceIpa(unsigned int) = 0;
    virtual int XoKerbCrackApReq(unsigned char*, unsigned int, unsigned char*,
        LARGE_INTEGER*, unsigned int*, _XOTSKERBINFO*) = 0;
    virtual int XoKerbBuildApRep(unsigned char*, LARGE_INTEGER, unsigned int,
        _XOTSKERBINFO*, unsigned char*, unsigned int*) = 0;
};

class idCallback {
public:
    virtual ~idCallback() = default;
    virtual void Call() {}
    virtual idCallback* Clone() const { return new idCallback(*this); }
};

class idCallbackStatic : public idCallback {
public:
    using function_t = void (*)();

    explicit idCallbackStatic(function_t function = nullptr) : f(function) {}
    ~idCallbackStatic() override = default;
    void Call() override { if (f != nullptr) f(); }
    idCallback* Clone() const override { return new idCallbackStatic(*this); }

    function_t f;
};

template<class type_t>
class idCallbackBindMem : public idCallback {
public:
    using function_t = void (type_t::*)();

    idCallbackBindMem(type_t* object = nullptr, function_t function = nullptr)
        : t(object), f(function) {}
    ~idCallbackBindMem() override = default;
    void Call() override { if (t != nullptr && f != nullptr) (t->*f)(); }
    idCallback* Clone() const override { return new idCallbackBindMem(*this); }

    type_t* t;
    function_t f;
};

template<class type_t, class argument_t>
class idCallbackBindMemArg1 : public idCallback {
public:
    using function_t = void (type_t::*)(argument_t);

    idCallbackBindMemArg1(type_t* object = nullptr,
            function_t function = nullptr, argument_t argument = argument_t())
        : t(object), f(function), a1(argument) {}
    ~idCallbackBindMemArg1() override = default;
    void Call() override { if (t != nullptr && f != nullptr) (t->*f)(a1); }
    idCallback* Clone() const override {
        return new idCallbackBindMemArg1(*this);
    }

    type_t* t;
    function_t f;
    argument_t a1;
};

template<class type_t>
idCallbackBindMem<type_t> MakeCallback(type_t* object,
        void (type_t::*function)()) {
    return idCallbackBindMem<type_t>(object, function);
}

template<class type_t, class argument_t>
idCallbackBindMemArg1<type_t, argument_t> MakeCallback(type_t* object,
        void (type_t::*function)(argument_t), argument_t argument) {
    return idCallbackBindMemArg1<type_t, argument_t>(object, function, argument);
}

class idAAS2;
class idFiniteStateMachine;
class idTypeInfo;

class idFSMLogEntry {
public:
    enum fsmLogEntry_t : int {
        LOGENTRY_NONE = 0,
        LOGENTRY_TRANSITION = 1,
        LOGENTRY_RESTART = 2,
        LOGENTRY_ERROR = 3,
        LOGENTRY_MAX = 4
    };

    fsmLogEntry_t type;
    int time;
    const idFiniteStateMachine* fsm;
    const idTypeInfo* curStateType;
    const idTypeInfo* nextStateType;
    const idTypeInfo* transitionType;
    int transCode;
};

class idAAS2Callback {
public:
    virtual ~idAAS2Callback() = default;
    virtual bool PathValid(const idAAS2*, const idVec3*, const idVec3*) {
        return true;
    }
    virtual int AdditionalTravelTimeForPath(
            const idAAS2*, const idVec3*, const idVec3*) {
        return 0;
    }
    virtual bool AreaIsGoal(const idAAS2*, int, const idVec3*) {
        return false;
    }
};

class idFSMCallback {
public:
    virtual ~idFSMCallback() = default;
    virtual void OnTransition(const idFiniteStateMachine*, const idTypeInfo*,
        const idTypeInfo*, const idTypeInfo*, int) {}
    virtual void OnRestart(const idFiniteStateMachine*, const idTypeInfo*) {}
    virtual void OnError(const idFiniteStateMachine*, const idTypeInfo*,
        const idTypeInfo*, int) {}
};

class idFSMLog {
public:
    explicit idFSMLog(int maximumSize);
    ~idFSMLog();

    const idFSMLogEntry* FromLast(int index) const;
    idFSMLogEntry* Alloc();

    void Clear() {
        list.Clear();
        first = 0;
    }

    idList<idFSMLogEntry, 5> list;
    int first;
    int maxSize;
};

class idAIFSMCallback : public idFSMCallback {
public:
    idAIFSMCallback();
    ~idAIFSMCallback() override = default;
    void OnTransition(const idFiniteStateMachine*, const idTypeInfo*,
        const idTypeInfo*, const idTypeInfo*, int) override;
    void OnRestart(const idFiniteStateMachine*, const idTypeInfo*) override;
    void OnError(const idFiniteStateMachine*, const idTypeInfo*,
        const idTypeInfo*, int) override;

    idFSMLog log;
};

using D3DCALLBACK = void (*)(unsigned int);
using guiCallBack_t = void (*)(bool);

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idFSMLogEntry) == 28,
    "Recovered idFSMLogEntry ABI changed");
static_assert(sizeof(idCallback) == 4, "Recovered idCallback ABI changed");
static_assert(sizeof(idCallbackStatic) == 8,
    "Recovered idCallbackStatic ABI changed");
static_assert(sizeof(idFSMLog) == 24, "Recovered idFSMLog ABI changed");
static_assert(sizeof(idAIFSMCallback) == 28,
    "Recovered idAIFSMCallback ABI changed");
#endif
