#include "framework/resource.h"

#include "framework/resourcelist.h"
#include "idlib/lib_print.h"
#include "idlib/text/str.h"

idResource::idResource()
    : trackedMemory(0), name("unnamed"), nextOnHashChain(nullptr),
      resourceListPtr(nullptr), resourceError(nullptr), networkID(-1),
      staleCount(0), resourceFlags(0), pad{} {
}

idResource::~idResource() {
    if ((resourceFlags & 0x40u) != 0) {
        idLibPrint::FatalError("Resource deleted with staticResource set: %s",
            name.c_str());
    }
    if (resourceListPtr != nullptr) {
        resourceListPtr->Remove(this);
    }
    idResourceList::UnRegisterNetworkResource(this);
}

void idResource::LoadResource() {
    const idResourceList* const list = GetResourceList();
    idLibPrint::FatalError("idResource::Load() for %s not implemented.\n",
        list != nullptr ? list->GetResourceTypeName() : "resource");
}

bool idResource::ReloadIfStale() {
    return false;
}

void idResource::WriteResourceFile() {
    const idResourceList* const list = GetResourceList();
    idLibPrint::FatalError(
        "resource type '%s' has not implemented WriteResourceFile()",
        list != nullptr ? list->GetResourceTypeName() : "resource");
}

idResourceList* idResource::GetResourceList() {
    return resourceListPtr;
}

void idResource::Print() {
    const idResourceList* const list = GetResourceList();
    const char* const typeName =
        list != nullptr ? list->GetResourceTypeName() : "resource";
    if (resourceError != nullptr) {
        idLibPrint::Printf("%s:%s:%s\n", typeName, name.c_str(),
            resourceError);
    } else {
        idLibPrint::Printf("%s:%s\n", typeName, name.c_str());
    }
}

void idResource::List() {
    Print();
}

void idResource::SetName(const char* const newName) {
    idStr canonicalName(newName);
    canonicalName.MakeNameCanonical();
    if (idStr::Cmp(canonicalName.c_str(), name.c_str()) != 0) {
        name.Set(canonicalName.c_str());
    }
}
