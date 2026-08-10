#include "sys_alloc.h"

#include <algorithm>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <malloc.h>

#include <Windows.h>

namespace {
struct allocationRecord_t {
    allocationRecord_t* next;
    void* pointer;
    unsigned int bytes;
    memTag_t tag;
    heapType_t heap;
    const char* location;
};

SRWLOCK allocationLock = SRWLOCK_INIT;
allocationRecord_t* allocations = nullptr;
std::atomic<unsigned long long> allocatedBytes(0);
std::atomic<idOutOfMemoryCallback> outOfMemoryCallback(nullptr);
thread_local heapType_t currentHeap = HEAP_SYSTEMHEAP;
thread_local heapType_t pushedHeap = HEAP_SYSTEMHEAP;
thread_local int heapStackDepth = 0;

const char* const tagNames[TAG_NUM_TAGS] = {
    "UNSET", "STATIC_EXE", "RESOURCE_GRAPH", "DEBUG", "NEW", "IDLIST",
    "TEMP", "STRING", "ATOMIC_STRING", "BITARRAY", "MATH", "LEXER",
    "COMPILER", "COLLISION", "COLLISION_QUERY", "CLIPMODEL", "MORPH",
    "MD6_MISC", "MD6_NODES", "MD6", "MD6_ANIMS", "MD6_LIPSYNC",
    "MD6_JOINTCACHE", "MD6_MESHES", "MD6_JOINTBUFFERS", "MD6_BLENDSTACK",
    "MD6_JOINTMODS", "MD6_COLLISION", "MD6_ANIMEVENTS", "MD6_PHASE_TRACK",
    "ANIMATION", "ANIMATION_DEBUG", "DECL_ANIMWEB", "ANIMWEB", "IMAGE",
    "DXIMAGE", "VIRTUALTEXTURE", "AAS", "SOUND", "SOUND_BSP", "SOUND_DATA",
    "SOUND_STREAM", "SOUND_MULTISTREAM", "SOUND_SAMPLETABLES", "IDLIB",
    "TRIANGLES", "DECL", "DECLTEXT", "FILE", "CVAR", "PAGEFILECACHE",
    "IDCLASS", "PRESENTABLE", "FOLIAGE", "WATER", "MEMORY_MAPPED_FILE",
    "RENDERPARM", "NETWORKING", "SCRIPT", "FXPHYSICS", "LWO", "RENDERWORLD",
    "RENDERER", "AI_GAMESTATE", "EVENTS", "VOICEOVER", "VOICETRACK_EVENTS",
    "VOICETRACK_FRAMEREFS", "VOICETRACK_PHONEMES", "VISEMESET_VISEMES",
    "VISEMESET_PHONEMES", "AF", "SWF", "GUI", "GUI_MODEL", "FUNC_CALLBACK",
    "MENU", "GAME", "HASHINDEX", "PARTICLE", "EFFECT_PARTICLE", "CLOTH",
    "ANIMTAGS", "IK", "STATICMODEL", "RENDERMODEL", "DXBUFFER", "TOOLS",
    "CLOUD", "AMQP", "RENDERPROG", "HASHTABLE", "AI_FSM", "AI_VISCACHE",
    "AI_SEARCH", "AI_OBSTACLE", "JOBLIST", "TRANSPARENCY", "DETAIL",
    "RESOURCE", "FILE_RESOURCE", "RESOURCE_BGL", "RESOURCE_BGL_RING",
    "RESOURCE_BGL_OVERSIZE", "RESOURCE_MGR", "PVS", "DEFERRED_VIS", "FIBER",
    "SUPERSCRIPT", "FX", "SAVEGAMES", "AI_TRANSITIONS", "AI_STATEDATA",
    "AI_COMBATANIM", "TYPEINFO", "DAMAGEDECAL", "TABLE", "VIDEO", "NAVPOWER",
    "LANGDICT", "SPLINE", "BINK", "FONTS", "EVENT_LISTENER", "PHYSICAL_BLOCK",
    "DXOBJECT"
};

void AddRecord(void* pointer, const unsigned int bytes, const memTag_t tag,
    const heapType_t heap, const char* location) {
    allocationRecord_t* const record = static_cast<allocationRecord_t*>(
        std::malloc(sizeof(allocationRecord_t))
    );
    if (record == nullptr) {
        return;
    }
    record->pointer = pointer;
    record->bytes = bytes;
    record->tag = tag;
    record->heap = heap;
    record->location = location;
    AcquireSRWLockExclusive(&allocationLock);
    record->next = allocations;
    allocations = record;
    ReleaseSRWLockExclusive(&allocationLock);
    allocatedBytes.fetch_add(bytes, std::memory_order_relaxed);
}

unsigned int RemoveRecord(void* pointer) {
    unsigned int bytes = 0;
    AcquireSRWLockExclusive(&allocationLock);
    allocationRecord_t** link = &allocations;
    while (*link != nullptr) {
        if ((*link)->pointer == pointer) {
            allocationRecord_t* const record = *link;
            *link = record->next;
            bytes = record->bytes;
            std::free(record);
            break;
        }
        link = &(*link)->next;
    }
    ReleaseSRWLockExclusive(&allocationLock);
    if (bytes != 0) {
        allocatedBytes.fetch_sub(bytes, std::memory_order_relaxed);
    }
    return bytes;
}
}

idMem mem;
idMemLocal memLocal;

const char* GetMemTagName(const int tag) {
    return tag >= 0 && tag < TAG_NUM_TAGS ? tagNames[tag] : "<BAD TAG NAME>";
}

void* idMem::AllocWithLocation(const char* const location,
    const unsigned int size, const memTag_t tag, const bool zeroBuffer,
    const align_t alignment, const heapType_t requestedHeap) {
    const std::size_t allocationSize = size == 0 ? 1u : size;
    const std::size_t requestedAlignment = static_cast<std::size_t>(alignment);
    const std::size_t safeAlignment = requestedAlignment < sizeof(void*)
        ? sizeof(void*) : requestedAlignment;

    void* pointer = _aligned_malloc(allocationSize, safeAlignment);
    if (pointer == nullptr) {
        idOutOfMemoryCallback callback = outOfMemoryCallback.load(
            std::memory_order_acquire
        );
        if (callback != nullptr && callback()) {
            pointer = _aligned_malloc(allocationSize, safeAlignment);
        }
    }
    if (pointer == nullptr) {
        return nullptr;
    }
    if (zeroBuffer) {
        std::memset(pointer, 0, allocationSize);
    }
    const heapType_t usedHeap = requestedHeap == HEAP_DEFAULTHEAP
        ? currentHeap : requestedHeap;
    AddRecord(pointer, size, tag, usedHeap, location);
    return pointer;
}

void idMem::Free(void* const pointer, const align_t) {
    if (pointer == nullptr) {
        return;
    }
    RemoveRecord(pointer);
    _aligned_free(pointer);
}

int idMem::BytesCurrentlyAllocated() const {
    const unsigned long long bytes = allocatedBytes.load(std::memory_order_relaxed);
    return bytes > static_cast<unsigned long long>((std::numeric_limits<int>::max)())
        ? (std::numeric_limits<int>::max)() : static_cast<int>(bytes);
}

void idMem::InitMapHeap() {
}

void idMem::ResetMapHeap() {
    // The PC port uses the process CRT heap for both logical heaps. Allocations
    // remain individually tracked so stale map allocations can still be found.
}

void idMem::PushHeap(const heapType_t heapType) {
    if (heapStackDepth++ == 0) {
        pushedHeap = currentHeap;
        currentHeap = heapType == HEAP_DEFAULTHEAP ? HEAP_MAPHEAP : heapType;
    }
}

void idMem::PopHeap() {
    if (heapStackDepth <= 0) {
        heapStackDepth = 0;
        return;
    }
    if (--heapStackDepth == 0) {
        currentHeap = pushedHeap;
    }
}

bool idMem::IsGlobalHeap() const {
    return currentHeap == HEAP_SYSTEMHEAP;
}

void idMem::SetOutOfMemoryCallback(const idOutOfMemoryCallback callback) {
    outOfMemoryCallback.store(callback, std::memory_order_release);
}

idOutOfMemoryCallback idMem::GetOutOfMemoryCallback() const {
    return outOfMemoryCallback.load(std::memory_order_acquire);
}

void* Sys_Alloc(const unsigned int size, const memTag_t tag,
        const align_t alignment, const heapType_t heap) {
    return mem.AllocWithLocation("Sys_Alloc PC replacement", size, tag,
        false, alignment, heap);
}

void Sys_Free(void* const pointer) {
    mem.Free(pointer);
}

void idMem::WriteMemoryReport(const char* const directory,
    const char* const fileName) const {
    char path[MAX_PATH];
    const char* const safeDirectory = directory == nullptr ? "." : directory;
    const char* const safeFile = fileName == nullptr ? "memory_report.txt" : fileName;
    std::snprintf(path, sizeof(path), "%s\\%s", safeDirectory, safeFile);
    FILE* report = nullptr;
    if (fopen_s(&report, path, "w") != 0 || report == nullptr) {
        return;
    }
    std::fprintf(report, "bytes currently allocated: %d\n", BytesCurrentlyAllocated());
    AcquireSRWLockShared(&allocationLock);
    for (allocationRecord_t* record = allocations; record != nullptr;
        record = record->next) {
        std::fprintf(report, "%p %10u %-24s heap=%d %s\n", record->pointer,
            record->bytes, GetMemTagName(record->tag), record->heap,
            record->location == nullptr ? "<unknown>" : record->location);
    }
    ReleaseSRWLockShared(&allocationLock);
    std::fclose(report);
}
