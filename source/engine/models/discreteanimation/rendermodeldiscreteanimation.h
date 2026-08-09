#pragma once

#include "idlib/geometry/jointtransform.h"
#include "models/discreteanimation/discreteanimationmodeldata.h"
#include "models/rendermodel.h"

class idDeclBreakable;

class alignas(16) idRenderModelDiscreteAnimation : public idRenderModel {
public:
    using UpdateCallback = bool (*)(idRenderModelDiscreteAnimation* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);

    idRenderModelDiscreteAnimation();
    ~idRenderModelDiscreteAnimation() override = default;
    static void SetUpdateCallback(UpdateCallback callback);
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    const idList<sourceSurface_t, 5>* GetSourceSurfaces() const override;

    const idDiscreteAnimationModelData* modelData;
    const idDeclBreakable* declBreakable;
    unsigned int modelTimestamp;
    idJointBuffer jointBuffers[2];
    int currentJointBuffer;
    idList<idJointMat, 59> transforms;
    idList<bool, 59> collapsed;
    bool changed;

private:
    static UpdateCallback updateCallback;
};
