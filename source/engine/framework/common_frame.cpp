#include "framework/framework_runtime_internal.h"

#include "framework/common_local.h"
#include "framework/gametimemanager.h"
#include "framework/streamfilecache.h"

namespace tech5Framework {
void RunFrame(const int milliseconds) {
    runtimeState_t& state = State();
    {
        std::lock_guard<std::recursive_mutex> lock(state.mutex);
        if (state.lifecycle != lifecycle_t::running) return;
        ++state.frame; state.milliseconds = milliseconds;
    }
    if (streamFileCache != nullptr) streamFileCache->NewFrame();
    RenderFrame();
}
} // namespace tech5Framework

void idCommonLocal::PurgeOverlays() {
    videoOverlay = nullptr;
}

void idCommonLocal::PrepareSnapshot(idSnapShot*, gameReturn_t*, idSnapShot*) {
    snapshotsStalled = false;
}
