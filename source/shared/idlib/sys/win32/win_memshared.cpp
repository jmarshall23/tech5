#include "../sys_alloc.h"

#include <cstdio>
#include <Windows.h>

bool Sys_AllocWillUseMapHeap() {
    return !mem.IsGlobalHeap();
}

void Sys_ReportHeaps() {
    std::printf("PC logical heap: %s, tracked bytes: %d\n",
        mem.IsGlobalHeap() ? "global" : "map", mem.BytesCurrentlyAllocated());
}

void ReportGlobalMemoryStatus() {
    MEMORYSTATUSEX status = {};
    status.dwLength = sizeof(status);
    if (GlobalMemoryStatusEx(&status)) {
        std::printf("physical memory: %llu / %llu bytes available\n",
            static_cast<unsigned long long>(status.ullAvailPhys),
            static_cast<unsigned long long>(status.ullTotalPhys));
    }
}
