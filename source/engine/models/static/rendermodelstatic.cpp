#include "models/static/rendermodelstatic.h"

#include "models/static/staticmodel.h"

idRenderModelStatic::TransparencyUpdateCallback
    idRenderModelStatic::transparencyUpdateCallback = nullptr;

idRenderModelStatic::idRenderModelStatic(const idStaticModel* model)
    : staticModel(model), skin(-1), reloadCount(0) {
    g.isStatic = 1;
    if (model != nullptr) {
        SetName(model->GetName());
        referenceBounds = model->referenceBounds;
        reloadCount = model->reloadCount;
        g.noGPUocclusionTest = model->usesTransparencySort ? 1 : 0;
    }
}

void idRenderModelStatic::SetTransparencyUpdateCallback(
    TransparencyUpdateCallback callback) {
    transparencyUpdateCallback = callback;
}

bool idRenderModelStatic::CommitSubclass() {
    if (staticModel != nullptr && reloadCount != staticModel->reloadCount) {
        referenceBounds = staticModel->referenceBounds;
        reloadCount = staticModel->reloadCount;
    }
    return idRenderModel::CommitSubclass();
}

bool idRenderModelStatic::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    if (staticModel == nullptr || !staticModel->usesTransparencySort ||
        transparencyUpdateCallback == nullptr) {
        return false;
    }
    return transparencyUpdateCallback(this, currentView, nextView, tools);
}

const idList<sourceSurface_t, 5>*
idRenderModelStatic::GetSourceSurfaces() const {
    return staticModel != nullptr ? &staticModel->sourceSurfaces : nullptr;
}
