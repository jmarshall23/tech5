#include "framework/framework_runtime_internal.h"

#include "framework/framework_hooks.h"
#include "framework/framework_runtime.h"
#include "framework/rendermanager.h"

#include "idlib/lib_print.h"

#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>

namespace {
struct renderManagerState_t {
    unsigned int frameNumber = 0;
    std::vector<idRenderModelGui*> globalGuis;
    std::unordered_map<int, std::vector<idRenderModelGui*>> localGuis;
};
renderManagerState_t renderManagerState;
}

namespace tech5Framework {
void RenderFrame() { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); (void)state; }
} // namespace tech5Framework

idRenderManager renderManager;

idRenderManager::idRenderManager() : renderFrameInfo{}, currentViewDef(nullptr) {
    SetScreenViewDef("single");
}

void idRenderManager::SetScreenViewDef(const char* const name) {
    currentViewDef = frameworkHooks.resolveScreenViewDef != nullptr
        ? frameworkHooks.resolveScreenViewDef(
            name != nullptr && *name != '\0' ? name : "single")
        : nullptr;
}

void idRenderManager::RenderFrame() {
    ++renderManagerState.frameNumber;
    if (frameworkHooks.renderFrame != nullptr) {
        frameworkHooks.renderFrame(&renderFrameInfo);
    }
    tech5Framework::RenderFrame();
}

void idRenderManager::ClearAllGuiModels() {
    if (frameworkHooks.clearGui == nullptr) return;
    for (idRenderModelGui* gui : renderManagerState.globalGuis) {
        frameworkHooks.clearGui(gui);
    }
    for (auto& local : renderManagerState.localGuis) {
        for (idRenderModelGui* gui : local.second) frameworkHooks.clearGui(gui);
    }
}

void idRenderManager::RenderFrameAndBeginAutomaticBackgroundSwaps() {
    RenderFrame();
    if (frameworkHooks.beginAutomaticBackgroundSwaps != nullptr) {
        frameworkHooks.beginAutomaticBackgroundSwaps(&renderFrameInfo);
    }
}

void idRenderManager::Clear() {
    renderManagerState = {};
    std::memset(&renderFrameInfo, 0, sizeof(renderFrameInfo));
}

void idRenderManager::BuildGuiFrame(idRenderModelGui* const gui,
        const bool loading) {
    renderManagerState.globalGuis.clear();
    renderManagerState.localGuis.clear();
    if (gui != nullptr) AddGlobalGui(gui);
    if (frameworkHooks.buildGuiFrame != nullptr) {
        frameworkHooks.buildGuiFrame(&renderFrameInfo, gui, loading);
    }
}

void idRenderManager::BuildGameFrame(const gameReturn_t& result,
        idGame& game, const int localClient) {
    renderManagerState.globalGuis.clear();
    renderManagerState.localGuis.clear();
    if (frameworkHooks.buildGameFrame != nullptr) {
        frameworkHooks.buildGameFrame(&renderFrameInfo, result, game,
            localClient);
    }
}

void idRenderManager::UpdateConsole() {
    BuildGuiFrame(nullptr, false);
    if (frameworkHooks.updateConsole != nullptr) frameworkHooks.updateConsole();
    RenderFrame();
}

void idRenderManager::AddGlobalGui(idRenderModelGui* const gui) {
    if (gui == nullptr) return;
    if (std::find(renderManagerState.globalGuis.begin(),
            renderManagerState.globalGuis.end(), gui)
        == renderManagerState.globalGuis.end()) {
        renderManagerState.globalGuis.push_back(gui);
    }
}

void idRenderManager::AddLocalGui(idRenderModelGui* const gui,
        const int viewIndex) {
    if (gui == nullptr) return;
    auto& guis = renderManagerState.localGuis[viewIndex];
    if (std::find(guis.begin(), guis.end(), gui) == guis.end()) {
        guis.push_back(gui);
    }
}

void RegisterRenderManagerCommands() {
    tech5Framework::RegisterCommand("setViewDef",
        [](const std::vector<idStr>& args) {
            if (args.size() == 1) {
                idLibPrint::Printf("single\n");
            } else {
                renderManager.SetScreenViewDef(args[1].c_str());
            }
        });
}
