#pragma once

#include "framework/resource.h"

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
    idResource* FindExisting(const char* name,
        bool skipStaleCheck = false);
    idResource* Index(int index) const;
    void Remove(idResource* resource);
    static void UnRegisterNetworkResource(idResource* resource);

    const char* resourceTypeName;
    idResourceList* nextResourceList;
    int num;
    int staticID;
    idResource* hashTable[256];
};

template<class resourceType>
class idTypedResourceList final : public idResourceList {
public:
    explicit idTypedResourceList(const char* const typeName)
        : idResourceList(typeName) {
    }

    idResource* Alloc(const char* const name) override {
        resourceType* const resource = new resourceType();
        resource->SetName(name);
        Add(resource);
        return resource;
    }

    int AllocSize() override { return sizeof(resourceType); }
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idResourceList) == 1044,
    "Recovered idResourceList ABI changed");
#endif
