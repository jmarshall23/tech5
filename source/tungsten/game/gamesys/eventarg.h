#pragma once

#include "../../../engine/gamelib/effects/weapontracemanager.h"
#include "../../../shared/idlib/containers/array.h"
#include "../../../shared/idlib/math/vector.h"
#include "../../../shared/idlib/text/str.h"

class idDecl;
class idEntity;
class idEventReceiver;
class idMD6Anim;
class idScriptList;

#ifndef TUNGSTEN_EVENT_VOID_DEFINED
#define TUNGSTEN_EVENT_VOID_DEFINED
struct eventVoid {};
#endif

struct eventInt {
    int value;
    explicit eventInt(int value_ = 0) : value(value_) {}
};

struct eventBool {
    bool value;
    explicit eventBool(bool value_ = false) : value(value_) {}
};

struct eventFloat {
    float value;
    explicit eventFloat(float value_ = 0.0f) : value(value_) {}
};

struct eventVector {
    idVec3 value;
    eventVector() : value(0.0f, 0.0f, 0.0f) {}
    explicit eventVector(const idVec3& value_) : value(value_) {}
};

struct eventString {
    idStr value;
    explicit eventString(const char* value_ = "") : value(value_) {}
};

struct eventEntity {
    idEntity* value;
    explicit eventEntity(idEntity* value_ = nullptr) : value(value_) {}
};

enum eventArgType_t : int {
    D_EVENT_VOID = 0,
    D_EVENT_INTEGER = 'i',
    D_EVENT_FLOAT = 'f',
    D_EVENT_VECTOR = 'v',
    D_EVENT_QUAT = 'q',
    D_EVENT_COLOR = 'c',
    D_EVENT_ANGLES = 'a',
    D_EVENT_STRING = 's',
    D_EVENT_ENTITY = 'e',
    D_EVENT_DECL = 'd',
    D_EVENT_ANIMWEBPATH = '1',
    D_EVENT_JOINTNAME = '2',
    D_EVENT_ANIMALIAS = '3',
    D_EVENT_ANIM = '4',
    D_EVENT_JOINTTAG = '5',
    D_EVENT_FSM = '6',
    D_EVENT_TRACE = 't',
    D_EVENT_VARIABLEARGS = 'x',
    D_EVENT_BOOLEAN = 'b',
    D_EVENT_SCRIPTLIST = 'l',
    D_EVENT_RECEIVER = 'r'
};

class idEventArg {
public:
    union value_t {
        int i;
        float f;
        float v[3];
        float q[4];
        float c[4];
        const char* s;
        const unsigned char* x;
        const idDecl* d;
        const idMD6Anim* anim;
        unsigned int h;
        const idScriptList* l;
        idEventReceiver* er;
    };

    idEventArg() : type(D_EVENT_VOID), value{} {}
    explicit idEventArg(const idSpawnId& data);
    idSpawnId GetEntitySpawnId() const;
    const idEntity* GetEntity() const;

    char type;
    value_t value;
};

class idEventArgs {
public:
    idEventArgs();
    idEventArgs(int numberOfParams, const idEventArg* params);

    void AddArg(const idEventArg& arg);
    void operator=(const idEventArgs& other);

    idArray<idEventArg, 8> args;
    idArray<idStr, 8> strings;
    int argsNumber;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idEventArg) == 20,
    "Recovered event-argument ABI changed");
static_assert(sizeof(idEventArgs) == 420,
    "Recovered event-argument array ABI changed");
#endif
