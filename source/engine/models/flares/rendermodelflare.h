#pragma once

#include "models/rendermodel.h"

class idDeclFlare;

class alignas(16) idRenderModelFlare : public idRenderModel {
public:
    using UpdateCallback = bool (*)(idRenderModelFlare* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);

    explicit idRenderModelFlare(const idDeclFlare* declaration = nullptr);
    ~idRenderModelFlare() override = default;

    static void SetUpdateCallback(UpdateCallback callback);

    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    void SetFlareDeclaration(const idDeclFlare* declaration) {
        flareDecl = declaration;
    }
    void SetSunFlare(bool enabled);

    const idDeclFlare* flareDecl;
    int quadModelIndex;
    bool isSunFlare;

private:
    static UpdateCallback updateCallback;
};
