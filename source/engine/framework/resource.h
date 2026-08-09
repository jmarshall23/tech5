#pragma once

#include "idlib/text/atomicstring.h"

#include <cstdint>

class idResourceList;

class alignas(4) idResource {
public:
    // Recovered from idResource's PDB type information.  The executable
    // stores the printable error text in resourceError, while this enum is
    // the stable result vocabulary used by binary-resource loaders.
    enum resourceError_t : int {
        RESOURCE_ERROR_NONE = 0,
        RESOURCE_ERROR_FILE_NOT_FOUND = 1,
        RESOURCE_ERROR_WRONG_TYPE = 2,
        RESOURCE_ERROR_INVALID_NAME = 3,
        RESOURCE_ERROR_HEADER_VERSION_MISMATCH = 4,
        RESOURCE_ERROR_RESOURCE_VERSION_MISMATCH = 5,
        RESOURCE_ERROR_FATAL = 6,
        RESOURCE_ERROR_TRUNCATED = 7,
        RESOURCE_ERROR_MAX = 8
    };

    enum referenceType_t : int {
        REF_UNKNOWN = 0,
        REF_FREED = 1,
        REF_WEAK = 2,
        REF_STRONG = 3
    };

    idResource();
    virtual ~idResource();

    virtual void LoadResource();
    virtual bool ReloadIfStale();
    virtual void WriteResourceFile();
    virtual idResourceList* GetResourceList();
    virtual void Print();
    virtual void List();

    void SetName(const char* newName);
    const char* GetName() const { return name.c_str(); }

    int trackedMemory;
    idAtomicString name;
    idResource* nextOnHashChain;
    idResourceList* resourceListPtr;
    const char* resourceError;
    int networkID;
    int staleCount;
    std::uint8_t resourceFlags;
    std::uint8_t pad[3];
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idResource) == 36, "Recovered idResource ABI changed");
#endif
