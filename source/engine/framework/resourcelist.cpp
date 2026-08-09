#include "framework/resourcelist.h"

#include "framework/resource.h"
#include "idlib/lib_print.h"

#include <cstring>
#include <mutex>

namespace {

std::mutex resourceListMutex;

unsigned int ResourceHash(const char* text) {
    unsigned int hash = 0;
    if (text != nullptr) {
        for (const unsigned char* cursor =
                 reinterpret_cast<const unsigned char*>(text);
             *cursor != 0; ++cursor) {
            hash = 31u * hash + *cursor;
        }
    }
    return hash & 255u;
}

} // namespace

idResourceList::idResourceList(const char* const typeName)
    : resourceTypeName(typeName), nextResourceList(nullptr), num(0),
      staticID(-1), hashTable{} {
}

idResourceList::~idResourceList() = default;

idResource* idResourceList::Alloc(const char*) {
    return nullptr;
}

int idResourceList::AllocSize() {
    return 0;
}

const char* idResourceList::GetResourceTypeName() const {
    if (resourceTypeName == nullptr) {
        idLibPrint::FatalError(
            "idResourceList::GetResourceTypeName: not set");
    }
    return resourceTypeName;
}

idResource* idResourceList::Load(const char* const name,
        const bool makeDefault, const bool skipStaleCheck) {
    if (name == nullptr || *name == '\0') return nullptr;
    if (idResource* const existing = FindExisting(name, skipStaleCheck)) {
        return existing;
    }
    idResource* const resource = Alloc(name);
    if (resource == nullptr) return nullptr;
    resource->LoadResource();
    if (resource->resourceError != nullptr && !makeDefault) {
        Remove(resource);
        delete resource;
        return nullptr;
    }
    return resource;
}

void idResourceList::Add(idResource* const resource) {
    if (resource == nullptr || resource->GetName() == nullptr
        || *resource->GetName() == '\0') {
        idLibPrint::FatalError(
            "idResourceList::Add called with unnamed resource");
    }
    std::lock_guard<std::mutex> lock(resourceListMutex);
    idResource*& head = hashTable[ResourceHash(resource->GetName())];
    for (idResource* current = head; current != nullptr;
         current = current->nextOnHashChain) {
        if (current == resource) {
            return;
        }
    }
    resource->nextOnHashChain = head;
    resource->resourceListPtr = this;
    head = resource;
    ++num;
}

idResource* idResourceList::FindExisting(const char* const name,
    const bool skipStaleCheck) {
    if (name == nullptr || *name == '\0') {
        return nullptr;
    }
    idResource* result = nullptr;
    {
        std::lock_guard<std::mutex> lock(resourceListMutex);
        for (idResource* current = hashTable[ResourceHash(name)];
             current != nullptr; current = current->nextOnHashChain) {
            if (_stricmp(current->GetName(), name) == 0) {
                result = current;
                break;
            }
        }
    }
    if (result != nullptr && !skipStaleCheck) {
        result->ReloadIfStale();
    }
    return result;
}

idResource* idResourceList::Index(const int index) const {
    if (index < 0 || index >= num) {
        return nullptr;
    }
    int currentIndex = 0;
    for (int bucket = 0; bucket < 256; ++bucket) {
        for (idResource* current = hashTable[bucket]; current != nullptr;
             current = current->nextOnHashChain) {
            if (currentIndex++ == index) {
                return current;
            }
        }
    }
    return nullptr;
}

void idResourceList::Remove(idResource* const resource) {
    std::lock_guard<std::mutex> lock(resourceListMutex);
    idResource** link = &hashTable[ResourceHash(resource->name.c_str())];
    while (*link != nullptr && *link != resource) {
        link = &(*link)->nextOnHashChain;
    }
    if (*link == nullptr) {
        idLibPrint::FatalError("idResourceList::Remove( %s ) not found",
            resource->name.c_str());
    }
    *link = resource->nextOnHashChain;
    resource->nextOnHashChain = nullptr;
    resource->resourceListPtr = nullptr;
    --num;
}

void idResourceList::UnRegisterNetworkResource(idResource* const resource) {
    // The recovered operation is a no-op for the normal unregistered state;
    // the network resource array itself belongs to the later framework port.
    if (resource->networkID != -1) {
        resource->networkID = -1;
    }
}
