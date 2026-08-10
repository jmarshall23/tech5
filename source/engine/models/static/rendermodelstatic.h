#pragma once

#include "models/rendermodel.h"
#include "models/static/jobs/statictransparencygen.h"

class idStaticModel;

class alignas(16) idRenderModelStatic : public idRenderModel {
public:
    using TransparencyUpdateCallback = bool (*)(idRenderModelStatic* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);

    explicit idRenderModelStatic(const idStaticModel* staticModel = nullptr);
    ~idRenderModelStatic() override;

    static void SetTransparencyUpdateCallback(
        TransparencyUpdateCallback callback);

    bool CommitSubclass() override;
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    const idList<sourceSurface_t, 5>* GetSourceSurfaces() const override;

    const idStaticModel* staticModel;
    int skin;
    int reloadCount;
    idList<staticTransparencyGenParms_t*, 5> transparencyGenParms;

private:
    static TransparencyUpdateCallback transparencyUpdateCallback;
};
