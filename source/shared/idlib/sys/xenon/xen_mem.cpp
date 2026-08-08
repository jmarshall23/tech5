#include "idlib/sys/sys_alloc.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <psapi.h>

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <limits>

namespace {

unsigned int ClampToUInt64(const unsigned long long value) {
    return value > (std::numeric_limits<unsigned int>::max)()
        ? (std::numeric_limits<unsigned int>::max)()
        : static_cast<unsigned int>(value);
}

int AlignUp(const int value, const int alignment) {
    const int safeAlignment = alignment <= 0 ? 16 : alignment;
    return (value + safeAlignment - 1) & ~(safeAlignment - 1);
}

} // namespace

void MapVirtualAddressSpace() {
    // Win32 already supplies a flat virtual address space. Logical map/system
    // heap selection remains handled by idMem.
}

unsigned int Sys_GetStreamFileCacheUsage() {
    // The PC filesystem owns its cache allocations through idMem rather than
    // a carved physical-memory range.
    return 0;
}

unsigned int Sys_GetMemoryUsage() {
    PROCESS_MEMORY_COUNTERS_EX counters = {};
    counters.cb = sizeof(counters);
    if (!GetProcessMemoryInfo(GetCurrentProcess(),
            reinterpret_cast<PROCESS_MEMORY_COUNTERS*>(&counters),
            sizeof(counters))) {
        return static_cast<unsigned int>(mem.BytesCurrentlyAllocated());
    }
    return ClampToUInt64(counters.PrivateUsage);
}

unsigned int Sys_GetFreeMemory() {
    MEMORYSTATUSEX status = {};
    status.dwLength = sizeof(status);
    return GlobalMemoryStatusEx(&status) ? ClampToUInt64(status.ullAvailPhys) : 0;
}

void Sys_WriteMemoryReport(const char* mapName, const char* version) {
    char fileName[192] = {};
    std::snprintf(fileName, sizeof(fileName), "memory_%s_%s.txt",
        mapName == nullptr || mapName[0] == '\0' ? "nomap" : mapName,
        version == nullptr || version[0] == '\0' ? "unknown" : version);
    for (char* cursor = fileName; *cursor != '\0'; ++cursor) {
        if (*cursor == '\\' || *cursor == '/' || *cursor == ':'
                || *cursor == '*' || *cursor == '?' || *cursor == '"'
                || *cursor == '<' || *cursor == '>' || *cursor == '|') {
            *cursor = '_';
        }
    }
    mem.WriteMemoryReport(".", fileName);
}

void Sys_DumpMemory() {
    mem.WriteMemoryReport(".", "memory_dump.txt");
}

void AddTagStats(int, int, int, int) {
    // idMem records tags per allocation, so a second accounting table would
    // double count on PC.
}

void SubtractTagStats(int, int, int, int) {
}

void* XMemAlloc(const unsigned int size, const int) {
    return mem.AllocWithLocation("XMemAlloc PC replacement", size, TAG_IDLIB,
        false, ALIGN_16, HEAP_DEFAULTHEAP);
}

void XMemFree(unsigned char* pointer, const unsigned int) {
    mem.Free(pointer);
}

void* Sys_Alloc(const unsigned int size, const memTag_t tag,
        const align_t alignment, const heapType_t heap) {
    return mem.AllocWithLocation("Sys_Alloc PC replacement", size, tag,
        false, alignment, heap);
}

void Sys_Free(void* pointer) {
    mem.Free(pointer);
}

idPhysicalMemoryBlock::idPhysicalMemoryBlock()
    : reservedPhysicalMemoryBlock(nullptr), totalBlockSize(0), commonBytes(0),
      overlayBytes(0), cacheBytes(0), insideResourceBlockLoad(false),
      physicalBytesAllocated(0), imageBytesAllocated(0), bufferBytesAllocated(0),
      otherBytesAllocated(0), alignmentWaste(0), bytesForcedOutsideBlock(0) {
}

void idPhysicalMemoryBlock::Init(const int bytesToAllocate) {
    if (reservedPhysicalMemoryBlock != nullptr || bytesToAllocate <= 0) return;
    totalBlockSize = AlignUp(bytesToAllocate, 65536);
    reservedPhysicalMemoryBlock = static_cast<unsigned char*>(
        mem.AllocWithLocation("idPhysicalMemoryBlock PC reserve",
            totalBlockSize, TAG_PHYSICAL_BLOCK, true, ALIGN_16,
            HEAP_SYSTEMHEAP));
    if (reservedPhysicalMemoryBlock == nullptr) totalBlockSize = 0;
}

void idPhysicalMemoryBlock::RevertToDiscreteAllocations() {
    if (physicalBytesAllocated != 0) return;
    mem.Free(reservedPhysicalMemoryBlock);
    reservedPhysicalMemoryBlock = nullptr;
    totalBlockSize = 0;
    commonBytes = overlayBytes = cacheBytes = 0;
}

void idPhysicalMemoryBlock::BeginResourceLoads() {
    insideResourceBlockLoad = true;
}

void idPhysicalMemoryBlock::EndResourceLoads(const bool neverFreeAllocatedData) {
    insideResourceBlockLoad = false;
    physicalBytesAllocated = std::min(AlignUp(physicalBytesAllocated, 65536),
        totalBlockSize);
    if (neverFreeAllocatedData) commonBytes = physicalBytesAllocated;
    cacheBytes = std::max(0, totalBlockSize - physicalBytesAllocated);
    overlayBytes = 0;
}

void* idPhysicalMemoryBlock::PhysicalAlloc(const unsigned int bytes,
        const int alignment, const memTag_t tag) {
    const int alignedOffset = AlignUp(physicalBytesAllocated, alignment);
    alignmentWaste += alignedOffset - physicalBytesAllocated;
    if (reservedPhysicalMemoryBlock != nullptr
            && alignedOffset >= 0
            && bytes <= static_cast<unsigned int>(totalBlockSize - alignedOffset)) {
        physicalBytesAllocated = alignedOffset + static_cast<int>(bytes);
        if (tag == TAG_DXIMAGE) imageBytesAllocated += bytes;
        else if (tag == TAG_DXBUFFER) bufferBytesAllocated += bytes;
        else otherBytesAllocated += bytes;
        return reservedPhysicalMemoryBlock + alignedOffset;
    }
    bytesForcedOutsideBlock += bytes;
    return mem.AllocWithLocation("physical allocation fallback", bytes, tag,
        false, alignment >= ALIGN_128 ? ALIGN_128 : ALIGN_16,
        HEAP_SYSTEMHEAP);
}

void* idPhysicalMemoryBlock::OverlayAlloc(const unsigned int bytes,
        const char*) {
    // PC resources are individually reclaimable; keeping overlays discrete
    // avoids the Xenon-only 64 KiB overlay fragmentation rules.
    return mem.AllocWithLocation("overlay allocation PC replacement", bytes,
        TAG_PHYSICAL_BLOCK, false, ALIGN_16, HEAP_SYSTEMHEAP);
}

void idPhysicalMemoryBlock::OverlayFree(void* pointer) {
    if (!AddressIsInReservedPhysicalMemoryBlock(pointer)) mem.Free(pointer);
}

bool idPhysicalMemoryBlock::AddressIsInReservedPhysicalMemoryBlock(
        const void* pointer) const {
    const unsigned char* const address = static_cast<const unsigned char*>(pointer);
    return reservedPhysicalMemoryBlock != nullptr
        && address >= reservedPhysicalMemoryBlock
        && address < reservedPhysicalMemoryBlock + totalBlockSize;
}

bool idPhysicalMemoryBlock::AddressIsInOverlayPhysicalMemoryBlock(
        const void* pointer) const {
    if (!AddressIsInReservedPhysicalMemoryBlock(pointer) || overlayBytes <= 0) {
        return false;
    }
    const unsigned char* const overlayStart =
        reservedPhysicalMemoryBlock + totalBlockSize - overlayBytes;
    return static_cast<const unsigned char*>(pointer) >= overlayStart;
}

void idPhysicalMemoryBlock::ReportPhysicalMemoryBlock() const {
    std::printf("physical block: %d/%d bytes, images=%d buffers=%d other=%d "
        "alignment=%d fallback=%d\n", physicalBytesAllocated, totalBlockSize,
        imageBytesAllocated, bufferBytesAllocated, otherBytesAllocated,
        alignmentWaste, bytesForcedOutsideBlock);
}

void idPhysicalMemoryBlock::ReportUntouchedPhysicalMemory() const {
    std::printf("physical block untouched/available: %d bytes\n",
        std::max(0, totalBlockSize - physicalBytesAllocated));
}
