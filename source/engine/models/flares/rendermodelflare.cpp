#include "models/flares/rendermodelflare.h"

idRenderModelFlare::UpdateCallback idRenderModelFlare::updateCallback = nullptr;

idRenderModelFlare::idRenderModelFlare(const idDeclFlare* declaration)
    : flareDecl(declaration), quadModelIndex(-1), isSunFlare(false) {
    g.noInteractions = 1;
    g.noShadow = 1;
}

void idRenderModelFlare::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

bool idRenderModelFlare::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}

void idRenderModelFlare::SetSunFlare(bool enabled) {
    isSunFlare = enabled;
    g.mvpIsSunFlare = enabled ? 1 : 0;
}
