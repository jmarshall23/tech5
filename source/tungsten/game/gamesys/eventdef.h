#pragma once

#include "../../../shared/idlib/text/str.h"

enum eventType_t : int {
    EVENT_GAME = 0,
    EVENT_ACTION = 1,
    EVENT_ANIMEVENT = 2,
    EVENT_FSMEVENT = 3,
    EVENT_NOTICE = 4
};

class idEventDef {
public:
    static constexpr int MAX_EVENTS = 4096;

    idEventDef() = default;
    idEventDef(eventType_t type, const char* command, bool canSkip,
        bool isClientSafe, const char* formatspec, const char* argTypes,
        const char* argNames, char returnType,
        const idEventDef* noticeEventDef);

    static int GetNumEvents();
    static const idEventDef* GetEventCommand(int eventNum);
    static const idEventDef* FindEvent(const char* name);
    static int GetEventNumForName(const char* name);
    static const char* GetEventNameForNum(int eventNum);
    static bool GetEventArgTypeName(
        int eventNum, int argNum, idStr& argType);
    static void InvalidDeclWarning(const char* eventName,
        const class idDecl* decl, const class idDeclInfo& expectedDeclInfo);

    bool GetArgTypeName(int arg, idStr& typeName) const;

    const char* name;
    const char* formatspec;
    const char* argTypes;
    const char* argNames;
    int returnType;
    int numargs;
    int numstrings;
    int eventnum;
    bool canSkip;
    bool isClientSafe;
    eventType_t type;
    const idEventDef* noticeEvent;

    static int numEventDefs;
    static idEventDef* eventDefList[MAX_EVENTS];
};

class idDecl;
class idDeclInfo;

class eventDecl {
public:
    const idDecl* value;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idEventDef) == 44,
    "Recovered event-definition ABI changed");
static_assert(sizeof(eventDecl) == 4,
    "Recovered event-declaration result ABI changed");
#endif
