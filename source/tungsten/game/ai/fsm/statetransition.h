#pragma once

#include "idlib/containers/list.h"

class idFile_String;
class idFiniteStateMachine;
class idState;
class idTypeInfo;
class idStateTransition;

const char* Tungsten_GetStateTransitionClassname(
    const idStateTransition* transition);
void Tungsten_AppendStateTransitionText(idFile_String& file, const char* text);

// Source-facing reconstruction of the abstract transition base. Generated
// type-info owns GetType; concrete transition files own Evaluate/InternalSave.
class idStateTransition {
public:
    struct transDest_t {
        const idTypeInfo* nextStateType;
        int transCode;
    };

    explicit idStateTransition(int transitionFlags);
    virtual idTypeInfo* GetType() = 0;
    virtual ~idStateTransition() = default;
    virtual int Evaluate(idFiniteStateMachine*, idState*, int) = 0;
    virtual void InternalSave(idFile_String&, const char*,
        const idList<transDest_t, 5>&) = 0;
    virtual void Save(idFile_String&, const char*,
        const idList<transDest_t, 5>&);

    int flags;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idStateTransition::transDest_t) == 8,
    "Recovered transition destination ABI changed");
static_assert(sizeof(idStateTransition) == 8,
    "Recovered idStateTransition ABI changed");
#endif
