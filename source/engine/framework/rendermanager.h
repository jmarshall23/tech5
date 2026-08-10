#pragma once

#include <cstdint>

class idGame;
class idRenderModelGui;
struct gameReturn_t;
struct screenViewDef_t;

// The renderer-owned members of idRenderFrameInfo are kept opaque here until
// the renderer module installs its typed bridge.  The recovered 32-bit object
// is 0x1790 bytes and remains embedded in idRenderManager.
struct alignas(16) idRenderFrameInfo {
    std::uint8_t recoveredStorage[0x1790];
};

class alignas(16) idRenderManager {
public:
    idRenderManager();
    void SetScreenViewDef(const char* name);
    void RenderFrame();
    void ClearAllGuiModels();
    void RenderFrameAndBeginAutomaticBackgroundSwaps();
    void Clear();
    void BuildGuiFrame(idRenderModelGui*, bool loading);
    void BuildGameFrame(const gameReturn_t&, idGame&, int localClient);
    void UpdateConsole();
    void AddGlobalGui(idRenderModelGui* gui);
    void AddLocalGui(idRenderModelGui* gui, int viewIndex);
    idRenderFrameInfo renderFrameInfo;
    const screenViewDef_t* currentViewDef;
};

extern idRenderManager renderManager;

void RegisterRenderManagerCommands();

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idRenderFrameInfo) == 0x1790,
    "Recovered idRenderFrameInfo ABI changed");
static_assert(sizeof(idRenderManager) == 0x17A0,
    "Recovered idRenderManager ABI changed");
#endif
