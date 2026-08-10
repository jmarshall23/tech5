#include "sys/sys_precompiled.h"

idSWFScriptFunction::~idSWFScriptFunction() = default;

idSWFScriptVar* idSWFScriptFunction::Call(idSWFScriptVar* result,
        idSWFScriptObject*, const idSWFParmList*) {
    if (result != nullptr) *result = idSWFScriptVar();
    return result;
}

void idSWFScriptFunction::AddRef() {}
void idSWFScriptFunction::Release() {}
idSWFScriptObject* idSWFScriptFunction::GetPrototype() { return nullptr; }
void idSWFScriptFunction::SetPrototype(idSWFScriptObject*) {}

idSWFScriptFunction_RefCounted::~idSWFScriptFunction_RefCounted() = default;

idSWFScriptVar* idSWFScriptFunction_RefCounted::Call(idSWFScriptVar* result,
        idSWFScriptObject* object, const idSWFParmList* parms) {
    return idSWFScriptFunction::Call(result, object, parms);
}

void idSWFScriptFunction_RefCounted::AddRef() { ++refCount; }

void idSWFScriptFunction_RefCounted::Release() {
    if (--refCount <= 0) delete this;
}

idSWFScriptObject* idSWFScriptFunction_RefCounted::GetPrototype() {
    return nullptr;
}

void idSWFScriptFunction_RefCounted::SetPrototype(idSWFScriptObject*) {}
