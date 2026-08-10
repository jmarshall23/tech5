#pragma once

#include "idlib/text/atomicstring.h"

#include <cstdint>

class idFile;
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

    struct resourceHeader_t {
        enum resourcePlatform_t : std::uint8_t {
            RESOURCEPLATFORM_WINDOWS = 0,
            RESOURCEPLATFORM_360 = 1,
            RESOURCEPLATFORM_PS3 = 2,
            RESOURCEPLATFORM_MAC = 3,
            RESOURCEPLATFORM_MAX = 4
        };

        std::uint16_t headerVersionHi;
        std::uint16_t headerVersionLo;
        std::uint32_t resourceId;
        std::uint16_t versionHi;
        std::uint16_t versionLo;
        std::uint32_t sourceTimestamp;
        std::uint16_t sourceFileNameLen;
        std::uint16_t uniqueIdNameLen;
        std::uint8_t platform;
        std::uint8_t pad[3];
        std::uint64_t uniqueId;
        std::uint64_t hash;
        std::uint64_t dataOffset;
        std::uint64_t totalSize;
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
    void SetResourceError(const char* format, ...);
    void ClearResourceError();
    void Load();
    const char* GetName() const { return name.c_str(); }
    const char* GetResourceTypeName() const;
    int InitNetworkID() const;
    int GetNetworkID(bool alloc) const;

    static const char* GetLocalizedName(const char* sourceLanguage,
        const char* destLanguage, const char* inName, char* outName,
        int sizeOfOutName);
    static const char* GetLocalizedName(const char* inName, char* outName,
        int sizeOfOutName);
    static bool WriteBinaryHeader(idFile* file,
        const resourceHeader_t& header, const void* data, int dataLength,
        const char* uniqueIdName, const char* sourceFileName);
    static bool WriteBinary(const char* uniqueIdName,
        const char* sourceFileName, const char* fileExtension,
        const resourceHeader_t& header, const void* data,
        unsigned int dataLength);
    static resourceError_t ReadBinaryHeader(idFile* file,
        std::uint32_t expectedResourceId, std::uint16_t expectedVersionHi,
        std::uint16_t expectedVersionLo, resourceHeader_t& header,
        char* sourceFileName, char* uniqueIdName);

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

static_assert(sizeof(idResource::resourceHeader_t) == 56,
    "Recovered binary-resource header layout changed");

class idBaseCodeResource {
public:
    idBaseCodeResource(const char* resourceName, idResourceList* list);

    static void AllocateCodeResources();
    static void LoadCodeResources(const char* ofType = nullptr);

    const char* name;
    idBaseCodeResource* next;
    idResource* r;
    idResourceList* rl;

private:
    static idBaseCodeResource* codeResourceList;
    static bool allocCodeResourcesHasBeenCalled;
};

template<class resourceType>
class idCodeResource : public idBaseCodeResource {
public:
    idCodeResource(const char* resourceName, idResourceList* list)
        : idBaseCodeResource(resourceName, list) {
    }

    const resourceType* Get() const {
        return static_cast<const resourceType*>(r);
    }

    const resourceType* operator->() const { return Get(); }
    operator const resourceType*() const { return Get(); }
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idResource) == 36, "Recovered idResource ABI changed");
#endif
