#pragma once

#include <cstdint>

enum memTag_t : int {
    TAG_UNSET = 0x00, TAG_STATIC_EXE, TAG_RESOURCE_GRAPH, TAG_DEBUG,
    TAG_NEW, TAG_IDLIST, TAG_TEMP, TAG_STRING, TAG_ATOMIC_STRING,
    TAG_BITARRAY, TAG_MATH, TAG_LEXER, TAG_COMPILER, TAG_COLLISION,
    TAG_COLLISION_QUERY, TAG_CLIPMODEL, TAG_MORPH, TAG_MD6_MISC,
    TAG_MD6_NODES, TAG_MD6, TAG_MD6_ANIMS, TAG_MD6_LIPSYNC,
    TAG_MD6_JOINTCACHE, TAG_MD6_MESHES, TAG_MD6_JOINTBUFFERS,
    TAG_MD6_BLENDSTACK, TAG_MD6_JOINTMODS, TAG_MD6_COLLISION,
    TAG_MD6_ANIMEVENTS, TAG_MD6_PHASE_TRACK, TAG_ANIMATION,
    TAG_ANIMATION_DEBUG, TAG_DECL_ANIMWEB, TAG_ANIMWEB, TAG_IMAGE,
    TAG_DXIMAGE, TAG_VIRTUALTEXTURE, TAG_AAS, TAG_SOUND, TAG_SOUND_BSP,
    TAG_SOUND_DATA, TAG_SOUND_STREAM, TAG_SOUND_MULTISTREAM,
    TAG_SOUND_SAMPLETABLES, TAG_IDLIB, TAG_TRIANGLES, TAG_DECL,
    TAG_DECLTEXT, TAG_FILE, TAG_CVAR, TAG_PAGEFILECACHE, TAG_IDCLASS,
    TAG_PRESENTABLE, TAG_FOLIAGE, TAG_WATER, TAG_MEMORY_MAPPED_FILE,
    TAG_RENDERPARM, TAG_NETWORKING, TAG_SCRIPT, TAG_FXPHYSICS, TAG_LWO,
    TAG_RENDERWORLD, TAG_RENDERER, TAG_AI_GAMESTATE, TAG_EVENTS,
    TAG_VOICEOVER, TAG_VOICETRACK_EVENTS, TAG_VOICETRACK_FRAMEREFS,
    TAG_VOICETRACK_PHONEMES, TAG_VISEMESET_VISEMES,
    TAG_VISEMESET_PHONEMES, TAG_AF, TAG_SWF, TAG_GUI, TAG_GUI_MODEL,
    TAG_FUNC_CALLBACK, TAG_MENU, TAG_GAME, TAG_HASHINDEX, TAG_PARTICLE,
    TAG_EFFECT_PARTICLE, TAG_CLOTH, TAG_ANIMTAGS, TAG_IK, TAG_STATICMODEL,
    TAG_RENDERMODEL, TAG_DXBUFFER, TAG_TOOLS, TAG_CLOUD, TAG_AMQP,
    TAG_RENDERPROG, TAG_HASHTABLE, TAG_AI_FSM, TAG_AI_VISCACHE,
    TAG_AI_SEARCH, TAG_AI_OBSTACLE, TAG_JOBLIST, TAG_TRANSPARENCY,
    TAG_DETAIL, TAG_RESOURCE, TAG_FILE_RESOURCE, TAG_RESOURCE_BGL,
    TAG_RESOURCE_BGL_RING, TAG_RESOURCE_BGL_OVERSIZE, TAG_RESOURCE_MGR,
    TAG_PVS, TAG_DEFERRED_VIS, TAG_FIBER, TAG_SUPERSCRIPT, TAG_FX,
    TAG_SAVEGAMES, TAG_AI_TRANSITIONS, TAG_AI_STATEDATA, TAG_AI_COMBATANIM,
    TAG_TYPEINFO, TAG_DAMAGEDECAL, TAG_TABLE, TAG_VIDEO, TAG_NAVPOWER,
    TAG_LANGDICT, TAG_SPLINE, TAG_BINK, TAG_FONTS, TAG_EVENT_LISTENER,
    TAG_PHYSICAL_BLOCK, TAG_DXOBJECT, TAG_NUM_TAGS
};

enum align_t : int {
    ALIGN_16 = 0x10,
    ALIGN_128 = 0x80,
    ALIGN_1M = 0x100000
};

enum heapType_t : int {
    HEAP_DEFAULTHEAP = -1,
    HEAP_SYSTEMHEAP = 0,
    HEAP_MAPHEAP = 1
};

using idOutOfMemoryCallback = bool (*)();

class idMem {
public:
    void* AllocWithLocation(const char* location, unsigned int size,
        memTag_t tag, bool zeroBuffer = false, align_t alignment = ALIGN_16,
        heapType_t heap = HEAP_DEFAULTHEAP);
    void Free(void* pointer, align_t alignment = ALIGN_16);

    int BytesCurrentlyAllocated() const;
    void InitMapHeap();
    void ResetMapHeap();
    void PushHeap(heapType_t heapType);
    void PopHeap();
    bool IsGlobalHeap() const;

    void SetOutOfMemoryCallback(idOutOfMemoryCallback callback);
    idOutOfMemoryCallback GetOutOfMemoryCallback() const;
    void WriteMemoryReport(const char* directory, const char* fileName) const;
};

class idMemLocal : public idMem {
};

extern idMem mem;
extern idMemLocal memLocal;

const char* GetMemTagName(int tag);
bool Sys_AllocWillUseMapHeap();
void Sys_ReportHeaps();
void ReportGlobalMemoryStatus();

void* Sys_Alloc(unsigned int size, memTag_t tag,
    align_t alignment = ALIGN_16,
    heapType_t heap = HEAP_DEFAULTHEAP);
void Sys_Free(void* pointer);
unsigned int Sys_GetStreamFileCacheUsage();
unsigned int Sys_GetMemoryUsage();
unsigned int Sys_GetFreeMemory();
void Sys_WriteMemoryReport(const char* mapName, const char* version);
void Sys_DumpMemory();

class idPhysicalMemoryBlock {
public:
    idPhysicalMemoryBlock();

    void Init(int bytesToAllocate);
    void RevertToDiscreteAllocations();
    void BeginResourceLoads();
    void EndResourceLoads(bool neverFreeAllocatedData);
    void* PhysicalAlloc(unsigned int bytes, int alignment, memTag_t tag);
    void* OverlayAlloc(unsigned int bytes, const char* name);
    void OverlayFree(void* pointer);
    bool AddressIsInReservedPhysicalMemoryBlock(const void* pointer) const;
    bool AddressIsInOverlayPhysicalMemoryBlock(const void* pointer) const;
    void ReportPhysicalMemoryBlock() const;
    void ReportUntouchedPhysicalMemory() const;

private:
    unsigned char* reservedPhysicalMemoryBlock;
    int totalBlockSize;
    int commonBytes;
    int overlayBytes;
    int cacheBytes;
    bool insideResourceBlockLoad;
    int physicalBytesAllocated;
    int imageBytesAllocated;
    int bufferBytesAllocated;
    int otherBytesAllocated;
    int alignmentWaste;
    int bytesForcedOutsideBlock;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idPhysicalMemoryBlock) == 48,
    "Recovered idPhysicalMemoryBlock ABI changed");
#endif

class idScopedGlobalHeap {
public:
    idScopedGlobalHeap() { mem.PushHeap(HEAP_SYSTEMHEAP); }
    ~idScopedGlobalHeap() { mem.PopHeap(); }
};
