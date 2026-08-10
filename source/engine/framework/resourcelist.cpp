#include "framework/resourcelist.h"

#include "framework/common.h"
#include "framework/framework_runtime.h"
#include "framework/resource.h"
#include "idlib/hashing/crc32.h"
#include "idlib/lib_print.h"
#include "idlib/text/str.h"

#include <algorithm>
#include <cstring>
#include <mutex>
#include <vector>

namespace {

struct resourceRegistry_t {
    std::recursive_mutex mutex;
    idResourceList* lists = nullptr;
    int nextStaticID = 0;
    std::vector<const idResource*> networkResources;
    int firstDynamicNetworkResource = 0;
    unsigned int staticNetworkChecksum = 0;
    unsigned int networkChecksum = 0;
};

resourceRegistry_t& Registry() {
    static resourceRegistry_t registry;
    return registry;
}

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
    ClearHashTable();
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    nextResourceList = registry.lists;
    registry.lists = this;
    staticID = registry.nextStaticID++;
}

idResourceList::~idResourceList() {
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    idResourceList** link = &registry.lists;
    while (*link != nullptr && *link != this) {
        link = &(*link)->nextResourceList;
    }
    if (*link == this) {
        *link = nextResourceList;
    }
    nextResourceList = nullptr;
}

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
    Add(resource);
    resource->resourceFlags |= 0xA0u;
    resource->Load();
    resource->resourceFlags &= ~0x20u;
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
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    if (resource->nextOnHashChain != nullptr) {
        idLibPrint::FatalError(
            "Resource with a set link added to a list: %s",
            resource->GetName());
    }
    idResource*& head = hashTable[ResourceHash(resource->GetName())];
    for (idResource* current = head; current != nullptr;) {
        idResource* const next = current->nextOnHashChain;
        if (idStr::Cmp(current->GetName(), resource->GetName()) == 0) {
            RemoveLocked(current);
            break;
        }
        current = next;
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
    idStr canonicalName(name);
    canonicalName.MakeNameCanonical();
    idResource* const result = Lookup(canonicalName.c_str());
    if (result != nullptr && !skipStaleCheck) {
        bool needsLoad = (result->resourceFlags & 0x08u) != 0;
        needsLoad |= (result->resourceFlags & 0x90u) == 0x90u;
        if (needsLoad) {
            result->resourceFlags &= ~0x18u;
            result->resourceFlags |= 0x80u;
            result->Load();
        } else if ((result->resourceFlags & 0x80u) != 0) {
            result->ReloadIfStale();
        }
    }
    return result;
}

idResource* idResourceList::Lookup(const char* const canonicalName) const {
    if (canonicalName == nullptr) return nullptr;
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    for (idResource* current = hashTable[ResourceHash(canonicalName)];
         current != nullptr; current = current->nextOnHashChain) {
        if (idStr::Cmp(current->GetName(), canonicalName) == 0) {
            return current;
        }
    }
    return nullptr;
}

idResource* idResourceList::Index(const int index) const {
    if (index < 0 || index >= num) {
        return nullptr;
    }
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
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
    if (resource == nullptr) return;
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    RemoveLocked(resource);
}

void idResourceList::RemoveLocked(idResource* const resource) {
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

void idResourceList::ClearHashTable() {
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    std::fill(std::begin(hashTable), std::end(hashTable), nullptr);
    num = 0;
}

bool idResourceList::ReloadStaleResources() const {
    idList<idResource*> resources;
    GetLoadedResources(resources);
    bool reloaded = false;
    for (int index = 0; index < resources.Num(); ++index) {
        idResource* const resource = resources[index];
        if ((resource->resourceFlags & 0x80u) != 0
            && resource->ReloadIfStale()) {
            idLibPrint::Printf("reloaded %s\n", resource->GetName());
            reloaded = true;
        }
    }
    return reloaded;
}

void idResourceList::GetLoadedResources(idList<idResource*>& resources) const {
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    resources.Clear();
    for (const idResource* head : hashTable) {
        for (idResource* resource = const_cast<idResource*>(head);
             resource != nullptr; resource = resource->nextOnHashChain) {
            resources.Append(resource);
        }
    }
    if (resources.Num() > 1) {
        std::sort(resources.Ptr(), resources.Ptr() + resources.Num(),
            [](const idResource* left, const idResource* right) {
                return idStr::Icmp(left->GetName(), right->GetName()) < 0;
            });
    }
}

unsigned int idResourceList::GetNetworkChecksum() {
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    return registry.networkChecksum;
}

idResourceList* idResourceList::ForTypeName(const char* const typeName) {
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    for (idResourceList* list = registry.lists; list != nullptr;
         list = list->nextResourceList) {
        if (idStr::Icmp(list->GetResourceTypeName(), typeName) == 0) {
            return list;
        }
    }
    idLibPrint::Printf("Unknown resource type '%s'\n",
        typeName != nullptr ? typeName : "");
    return nullptr;
}

idResourceList* idResourceList::ForStaticID(const int id) {
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    for (idResourceList* list = registry.lists; list != nullptr;
         list = list->nextResourceList) {
        if (list->staticID == id) return list;
    }
    idLibPrint::Printf("Unknown resource type id '%i'\n", id);
    return nullptr;
}

int idResourceList::GetNumNetworkResources() {
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    return static_cast<int>(registry.networkResources.size());
}

const idResource* idResourceList::GetNetworkResource(const int networkID) {
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    if (networkID < 0
        || networkID >= static_cast<int>(registry.networkResources.size())) {
        idLibPrint::FatalError(
            "Network resource %d out of range. Valid range [0-%d]",
            networkID, static_cast<int>(registry.networkResources.size()) - 1);
    }
    return registry.networkResources[networkID];
}

bool idResourceList::ShouldPerformNetworkResourceExchange() {
    // PC recovery builds are development builds and retain the authoritative
    // exchange path. Production policy will be supplied by common later.
    return true;
}

void idResourceList::MarkAllStaticResources() {
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    for (idResourceList* list = registry.lists; list != nullptr;
         list = list->nextResourceList) {
        for (idResource* head : list->hashTable) {
            for (idResource* resource = head; resource != nullptr;
                 resource = resource->nextOnHashChain) {
                resource->resourceFlags |= 0x40u;
            }
        }
    }
    registry.staticNetworkChecksum = registry.networkChecksum;
    registry.firstDynamicNetworkResource =
        static_cast<int>(registry.networkResources.size());
}

void idResourceList::FreeAllDynamicResources() {
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    for (idResourceList* list = registry.lists; list != nullptr;
         list = list->nextResourceList) {
        for (idResource*& head : list->hashTable) {
            idResource** link = &head;
            while (*link != nullptr) {
                idResource* const resource = *link;
                if ((resource->resourceFlags & 0x40u) != 0) {
                    link = &resource->nextOnHashChain;
                    continue;
                }
                *link = resource->nextOnHashChain;
                resource->nextOnHashChain = nullptr;
                resource->resourceListPtr = nullptr;
                --list->num;
                delete resource;
            }
        }
    }
}

void idResourceList::ForceAllResourcesToReload() {
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    for (idResourceList* list = registry.lists; list != nullptr;
         list = list->nextResourceList) {
        for (idResource* head : list->hashTable) {
            for (idResource* resource = head; resource != nullptr;
                 resource = resource->nextOnHashChain) {
                resource->resourceFlags |= 0x10u;
            }
        }
    }
}

int idResourceList::AddNetworkResource(const idResource* const resource) {
    if (resource == nullptr) return -1;
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    if (registry.networkResources.size() >= 0xFFFFu) {
        idLibPrint::FatalError("Too many network resources");
    }
    const int id = static_cast<int>(registry.networkResources.size());
    registry.networkResources.push_back(resource);
    const char* const name = resource->GetName();
    CRC32_UpdateChecksum(registry.networkChecksum, name,
        static_cast<int>(std::strlen(name)));
    const char* const typeName = resource->GetResourceTypeName();
    CRC32_UpdateChecksum(registry.networkChecksum, typeName,
        static_cast<int>(std::strlen(typeName)));
    return id;
}

void idResourceList::ResetNetworkResources() {
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    const int keep = ShouldPerformNetworkResourceExchange()
        ? 0 : registry.firstDynamicNetworkResource;
    for (int index = keep;
         index < static_cast<int>(registry.networkResources.size()); ++index) {
        if (registry.networkResources[index] != nullptr) {
            const_cast<idResource*>(registry.networkResources[index])
                ->networkID = -1;
        }
    }
    registry.networkResources.resize(keep);
    registry.networkChecksum = keep == 0
        ? 0 : registry.staticNetworkChecksum;
}

void idResourceList::RegisterNetworkResource(const char* const typeName,
        const char* const name, const int networkID) {
    if (networkID < 0) return;
    idResourceList* const list = ForTypeName(typeName);
    if (list == nullptr) return;
    idResource* const resource = list->Load(name, true, false);
    if (resource == nullptr) {
        idLibPrint::Warning("RegisterNetworkResource: NULL resource [%s] %s",
            typeName != nullptr ? typeName : "", name != nullptr ? name : "");
        return;
    }
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    if (networkID >= static_cast<int>(registry.networkResources.size())) {
        registry.networkResources.resize(networkID + 1, nullptr);
    }
    registry.networkResources[networkID] = resource;
    resource->networkID = networkID;
}

void idResourceList::UnRegisterNetworkResource(idResource* const resource) {
    if (resource == nullptr || resource->networkID == -1) return;
    resourceRegistry_t& registry = Registry();
    std::lock_guard<std::recursive_mutex> lock(registry.mutex);
    const int id = resource->networkID;
    if (id >= 0 && id < static_cast<int>(registry.networkResources.size())
        && registry.networkResources[id] == resource) {
        registry.networkResources[id] = nullptr;
    }
    resource->networkID = -1;
}

int idResource::InitNetworkID() const {
    idResource* const mutableThis = const_cast<idResource*>(this);
    if (mutableThis->networkID == -1) {
        mutableThis->networkID = idResourceList::AddNetworkResource(this);
    }
    return mutableThis->networkID;
}

int idResource::GetNetworkID(const bool alloc) const {
    if (alloc && networkID == -1) return InitNetworkID();
    return networkID;
}

idBaseCodeResource* idBaseCodeResource::codeResourceList = nullptr;
bool idBaseCodeResource::allocCodeResourcesHasBeenCalled = false;

idBaseCodeResource::idBaseCodeResource(const char* const resourceName,
        idResourceList* const list)
    : name(resourceName), next(codeResourceList), r(nullptr), rl(list) {
    codeResourceList = this;
    if (allocCodeResourcesHasBeenCalled) {
        idStr canonical(resourceName);
        canonical.MakeNameCanonical();
        r = rl != nullptr ? rl->Lookup(canonical.c_str()) : nullptr;
        if (r == nullptr && rl != nullptr) {
            r = rl->Alloc(canonical.c_str());
            if (r != nullptr) {
                rl->Add(r);
                r->resourceFlags |= 0x48u;
            }
        }
    }
}

void idBaseCodeResource::AllocateCodeResources() {
    allocCodeResourcesHasBeenCalled = true;
    for (idBaseCodeResource* code = codeResourceList; code != nullptr;
         code = code->next) {
        if (code->rl == nullptr || code->name == nullptr) continue;
        idStr canonical(code->name);
        canonical.MakeNameCanonical();
        code->r = code->rl->Lookup(canonical.c_str());
        if (code->r == nullptr) {
            code->r = code->rl->Alloc(canonical.c_str());
            if (code->r != nullptr) {
                code->rl->Add(code->r);
                code->r->resourceFlags |= 0x48u;
            }
        }
    }
}

void idBaseCodeResource::LoadCodeResources(const char* const ofType) {
    for (idBaseCodeResource* code = codeResourceList; code != nullptr;
         code = code->next) {
        if (code->r == nullptr || code->rl == nullptr) continue;
        if (ofType != nullptr
            && idStr::Icmp(code->rl->GetResourceTypeName(), ofType) != 0) {
            continue;
        }
        if ((code->r->resourceFlags & 0x08u) == 0) continue;
        code->r->resourceFlags |= 0x80u;
        code->r = code->rl->Load(code->name, false, false);
        if (code->r == nullptr) {
            idLibPrint::Warning(
                "ResolveCodeResources: Resource name not found for %s:%s",
                code->rl->GetResourceTypeName(), code->name);
        }
    }
}

void RegisterResourceListCommands() {
    tech5Framework::RegisterCommand("resources",
        [](const std::vector<idStr>&) {
            resourceRegistry_t& registry = Registry();
            std::lock_guard<std::recursive_mutex> lock(registry.mutex);
            int total = 0;
            for (idResourceList* list = registry.lists; list != nullptr;
                    list = list->nextResourceList) {
                idLibPrint::Printf("%4d : %4d %s\n", list->num,
                    list->AllocSize(), list->GetResourceTypeName());
                total += list->num;
            }
            idLibPrint::Printf("%d total resources\n", total);
        });
    tech5Framework::RegisterCommand("reload",
        [](const std::vector<idStr>& args) {
            if (args.size() > 2) {
                idLibPrint::Printf("Usage: reload [resourceType]\n");
                return;
            }
            if (common != nullptr) common->SyncAllBackgroundOperations(true);
            resourceRegistry_t& registry = Registry();
            std::lock_guard<std::recursive_mutex> lock(registry.mutex);
            for (idResourceList* list = registry.lists; list != nullptr;
                    list = list->nextResourceList) {
                if (args.size() == 2 && idStr::Icmp(args[1].c_str(),
                        list->GetResourceTypeName()) != 0) continue;
                list->ReloadStaleResources();
            }
        });
    tech5Framework::RegisterCommand("resourceErrors",
        [](const std::vector<idStr>&) {
            resourceRegistry_t& registry = Registry();
            std::lock_guard<std::recursive_mutex> lock(registry.mutex);
            for (idResourceList* list = registry.lists; list != nullptr;
                    list = list->nextResourceList) {
                for (int index = 0; index < list->num; ++index) {
                    idResource* const resource = list->Index(index);
                    if (resource != nullptr && resource->resourceError != nullptr) {
                        idLibPrint::Printf("%s:%s:%s\n",
                            list->GetResourceTypeName(), resource->GetName(),
                            resource->resourceError);
                    }
                }
            }
        });
    tech5Framework::RegisterCommand("list",
        [](const std::vector<idStr>& args) {
            if (args.size() < 2 || args.size() > 3) {
                idLibPrint::Printf(
                    "Usage: list <resourceType | all> [memory]\n");
                return;
            }
            const bool all = idStr::Icmp(args[1].c_str(), "all") == 0;
            const bool memory = args.size() == 3
                && idStr::Icmp(args[2].c_str(), "memory") == 0;
            resourceRegistry_t& registry = Registry();
            std::lock_guard<std::recursive_mutex> lock(registry.mutex);
            int total = 0;
            for (idResourceList* list = registry.lists; list != nullptr;
                    list = list->nextResourceList) {
                if (!all && idStr::Icmp(args[1].c_str(),
                        list->GetResourceTypeName()) != 0) continue;
                idList<idResource*> resources;
                list->GetLoadedResources(resources);
                for (int index = 0; index < resources.Num(); ++index) {
                    if (memory) {
                        idLibPrint::Printf("%8d %s:%s\n",
                            resources[index]->trackedMemory,
                            list->GetResourceTypeName(),
                            resources[index]->GetName());
                    } else {
                        resources[index]->List();
                    }
                    ++total;
                }
            }
            idLibPrint::Printf("%d resources listed\n", total);
        });
    tech5Framework::RegisterCommand("resourceInfo",
        [](const std::vector<idStr>& args) {
            if (args.size() != 2) {
                idLibPrint::Printf("Usage: resourceInfo <resourceName>\n");
                return;
            }
            resourceRegistry_t& registry = Registry();
            std::lock_guard<std::recursive_mutex> lock(registry.mutex);
            for (idResourceList* list = registry.lists; list != nullptr;
                    list = list->nextResourceList) {
                idResource* const resource = list->FindExisting(
                    args[1].c_str(), false);
                if (resource == nullptr) continue;
                idLibPrint::Printf("\n%p %s : %s = %dk\n", resource,
                    list->GetResourceTypeName(), resource->GetName(),
                    resource->trackedMemory / 1024);
                resource->Print();
            }
        });
    tech5Framework::RegisterCommand("load",
        [](const std::vector<idStr>& args) {
            if (args.size() != 3) {
                idLibPrint::Printf(
                    "Usage: load <resourceType> <resourceName>\n");
                return;
            }
            idResourceList* const list = idResourceList::ForTypeName(
                args[1].c_str());
            if (list == nullptr || list->Load(args[2].c_str(), false, false)
                    == nullptr) {
                idLibPrint::Printf("Couldn't load %s:%s\n",
                    args[1].c_str(), args[2].c_str());
            }
        });
    tech5Framework::RegisterCommand("renameResource",
        [](const std::vector<idStr>& args) {
            if (args.size() != 4) {
                idLibPrint::Printf("Usage: renameResource <resourceType> "
                    "<oldResource> <newResource>\n");
                return;
            }
            idResourceList* const list = idResourceList::ForTypeName(
                args[1].c_str());
            idResource* const resource = list != nullptr
                ? list->Load(args[2].c_str(), false, false) : nullptr;
            if (resource == nullptr) {
                idLibPrint::Printf("Couldn't load %s:%s\n",
                    args[1].c_str(), args[2].c_str());
                return;
            }
            idLibPrint::Printf("Renaming %s:%s to %s\n", args[1].c_str(),
                args[2].c_str(), args[3].c_str());
            const idStr oldName(resource->GetName());
            resource->name.Set(args[3].c_str());
            resource->Load();
            resource->name.Set(oldName.c_str());
        });
}
