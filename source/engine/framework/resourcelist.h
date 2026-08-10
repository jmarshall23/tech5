#pragma once

#include "framework/resource.h"
#include "idlib/containers/list.h"

class idResourceList {
public:
    explicit idResourceList(const char* typeName = nullptr);
    virtual ~idResourceList();
    virtual idResource* Alloc(const char* name);
    virtual int AllocSize();

    const char* GetResourceTypeName() const;
    idResource* Load(const char* name, bool makeDefault,
        bool skipStaleCheck = false);
    void Add(idResource* resource);
    void ClearHashTable();
    idResource* FindExisting(const char* name,
        bool skipStaleCheck = false);
    idResource* Lookup(const char* canonicalName) const;
    idResource* Index(int index) const;
    void Remove(idResource* resource);
    bool ReloadStaleResources() const;
    void GetLoadedResources(idList<idResource*>& resources) const;

    static unsigned int GetNetworkChecksum();
    static idResourceList* ForTypeName(const char* typeName);
    static idResourceList* ForStaticID(int id);
    static int GetNumNetworkResources();
    static const idResource* GetNetworkResource(int networkID);
    static bool ShouldPerformNetworkResourceExchange();
    static void MarkAllStaticResources();
    static void FreeAllDynamicResources();
    static void ForceAllResourcesToReload();
    static int AddNetworkResource(const idResource* resource);
    static void ResetNetworkResources();
    static void RegisterNetworkResource(const char* typeName,
        const char* name, int networkID);
    static void UnRegisterNetworkResource(idResource* resource);

    const char* resourceTypeName;
    idResourceList* nextResourceList;
    int num;
    int staticID;
    idResource* hashTable[256];

private:
    void RemoveLocked(idResource* resource);
};

void RegisterResourceListCommands();

template<class resourceType>
class idTypedResourceList final : public idResourceList {
public:
    explicit idTypedResourceList(const char* const typeName)
        : idResourceList(typeName) {
    }

    idResource* Alloc(const char* const name) override {
        resourceType* const resource = new resourceType();
        resource->SetName(name);
        return resource;
    }

    int AllocSize() override { return sizeof(resourceType); }
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idResourceList) == 1044,
    "Recovered idResourceList ABI changed");
#endif
