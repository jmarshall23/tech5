#include "models/static/rendermodelstatic.h"

#include "models/static/staticmodel.h"

#include <new>

idRenderModelStatic::TransparencyUpdateCallback
    idRenderModelStatic::transparencyUpdateCallback = nullptr;

idRenderModelStatic::idRenderModelStatic(const idStaticModel* model)
    : staticModel(model), skin(-1), reloadCount(0) {
    g.isStatic = 1;
    if (model != nullptr) {
        SetName(model->GetName());
        referenceBounds = model->referenceBounds;
        g.noGPUocclusionTest = model->usesTransparencySort ? 1 : 0;
    }
}

idRenderModelStatic::~idRenderModelStatic() {
    for (int index = 0; index < transparencyGenParms.Num(); ++index)
        delete transparencyGenParms[index];
    transparencyGenParms.ClearFree();
}

void idRenderModelStatic::SetTransparencyUpdateCallback(
    TransparencyUpdateCallback callback) {
    transparencyUpdateCallback = callback;
}

bool idRenderModelStatic::CommitSubclass() {
    if (staticModel == nullptr) return false;

    for (int index = decalData.Num() - 1; index >= 0; --index) {
        decalData_t& decal = decalData[index];
        idVec3 worldPosition;
        LocalPointToGlobal(decal.relativePos, worldPosition);
        const idMat3 worldAxis = decal.relativeAxis * g.axis;
        if (!SetDecalPosition(decal.handle, worldPosition, worldAxis))
            decalData.RemoveIndexFast(index);
    }

    const bool reloaded = reloadCount != staticModel->reloadCount;
    if (reloaded) {
        FreeSurfaces();
        for (int index = 0; index < transparencyGenParms.Num(); ++index)
            delete transparencyGenParms[index];
        transparencyGenParms.ClearFree();

        SetMaxSurfaces(staticModel->surfaces.Num());
        for (int index = 0; index < staticModel->surfaces.Num(); ++index) {
            const idStaticModelSurface& source = staticModel->surfaces[index];
            idStaticModel::materialGenerationTraits_t traits;
            const bool transparencySort =
                idStaticModel::GetMaterialTraits(source.material, traits) &&
                traits.transparencySort;
            if (transparencySort) {
                transparencyGenParms.Append(new (std::nothrow)
                    staticTransparencyGenParms_t());
                continue;
            }

            idRenderModelSurface surface =
                static_cast<const idRenderModelSurface&>(source);
            surface.geometryIsReference = true;
            surface.referenceMask = 3;
            AddSurface(surface);
        }
        FinishSurfaces();
        if (!staticModel->modelIsAutosprite)
            referenceBounds = staticModel->referenceBounds;
        if (staticModel->usesTransparencySort) {
            g.noGPUocclusionTest = 1;
            SetLitTransSortFlag();
        }
        reloadCount = staticModel->reloadCount;
    }

    if (skin != g.customSkin || reloaded) {
        skin = g.customSkin;
        int renderSurface = 0;
        for (int index = 0; index < staticModel->surfaces.Num(); ++index) {
            const idStaticModelSurface& source = staticModel->surfaces[index];
            idStaticModel::materialGenerationTraits_t traits;
            if (idStaticModel::GetMaterialTraits(source.material, traits) &&
                    traits.transparencySort) {
                continue;
            }
            if (renderSurface >= surfaces.Num()) break;
            idRenderModelSurface& destination = surfaces[renderSurface++];
            destination.material = source.material;
            destination.skinOffsets = source.skinOffsets;
            if (skin >= 0 && skin < source.skinRemaps.Num()) {
                const skinRemap_t& remap = source.skinRemaps[skin];
                destination.material = remap.mtr;
                destination.skinOffsets.Set(remap.texOffset.x,
                    remap.texOffset.y, remap.texOffset.x, remap.texOffset.y);
            }
        }
    }
    return reloaded;
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
