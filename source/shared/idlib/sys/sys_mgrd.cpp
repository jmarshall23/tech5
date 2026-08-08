#include "sys_mgrd.h"

// MGRD was an optional external memory-profiler transport selected with the
// Xbox-era -mgrd switch. The PC recovery keeps the instrumentation API intact
// while making it a no-op until a desktop profiler backend is selected.
void RD_Init() {}
void RD_CreateGPUHeaps(void*, unsigned int, void*, unsigned int) {}
void RD_DestroyGPUHeaps() {}
void RD_CreateMapHeap() {}
void RD_DestroyMapHeap() {}
void RD_MemAlloc(void*, unsigned int, unsigned int, int) {}
void RD_MemFree(void*, int) {}
void RD_EventBegin(const char*) {}
void RD_EventEnd() {}
void RD_Syncpoint(const char*) {}
