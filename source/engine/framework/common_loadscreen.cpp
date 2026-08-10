#include "framework/framework_runtime_internal.h"

#include "framework/common_local.h"
#include "framework/framework_hooks.h"

#include <algorithm>

namespace tech5Framework {
void SetLoadProgress(float progress, const char* phase) {
    runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.loadProgress = std::max(0.0f, std::min(1.0f, progress));
    state.loadPhase = phase != nullptr ? phase : "";
}
float LoadProgress() { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); return state.loadProgress; }
const char* LoadPhase() { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); return state.loadPhase.c_str(); }
} // namespace tech5Framework

int idCommonLocal::PlayLoadSound() {
    return frameworkHooks.playLoadSound != nullptr
        ? frameworkHooks.playLoadSound() : 0;
}

void idCommonLocal::UpdateLevelLoadPacifier(const float progress,
        const pacifierState_t,
        bool, bool) {
    tech5Framework::SetLoadProgress(progress, "level");
}

void idCommonLocal::SetLoadScreenInfo(const idStr* const mapName,
        const idStr* const loadScreen) {
    tech5Framework::SetLoadProgress(tech5Framework::LoadProgress(),
        loadScreen != nullptr ? loadScreen->c_str()
            : mapName != nullptr ? mapName->c_str() : "level");
}

void idCommonLocal::StartLevelLoad(const idStr& mapName, bool) {
    tech5Framework::SetSessionState(tech5Framework::sessionState_t::loading);
    tech5Framework::SetLoadProgress(0.0f, mapName.c_str());
}

void idCommonLocal::StopLevelLoad(bool) {
    tech5Framework::SetLoadProgress(1.0f, "complete");
}
