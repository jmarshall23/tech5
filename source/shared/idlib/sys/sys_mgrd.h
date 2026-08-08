#pragma once

void RD_Init();
void RD_CreateGPUHeaps(void* gpuMemory, unsigned int gpuBytes,
    void* systemMemory, unsigned int systemBytes);
void RD_DestroyGPUHeaps();
void RD_CreateMapHeap();
void RD_DestroyMapHeap();
void RD_MemAlloc(void* pointer, unsigned int size, unsigned int waste, int heap);
void RD_MemFree(void* pointer, int heap);
void RD_EventBegin(const char* name);
void RD_EventEnd();
void RD_Syncpoint(const char* name);

class idRDScopedEvent {
public:
    explicit idRDScopedEvent(const char* name) { RD_EventBegin(name); }
    ~idRDScopedEvent() { RD_EventEnd(); }
};
