#pragma once

#include "models/rendermodel.h"

class idDeclFlare;

class alignas(16) idRenderModelFlare : public idRenderModel {
public:
    using UpdateCallback = bool (*)(idRenderModelFlare* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);
    using DeclarationResolver = const idDeclFlare* (*)(const char* name,
        bool makeDefault);
    using SnapshotDeclarationCallback = void (*)(idSerializer* serializer,
        const idDeclFlare*& declaration);

    explicit idRenderModelFlare(const idDeclFlare* declaration = nullptr);
    ~idRenderModelFlare() override;

    static void Init();
    static void Shutdown();
    static void StartFrame();
    static void EndFrame();
    static void SetUpdateCallback(UpdateCallback callback);
    static void SetDeclarationPersistenceCallbacks(
        DeclarationResolver resolver,
        SnapshotDeclarationCallback snapshotCallback);

    void Save(idFile* file) override;
    bool Load(idFile* file) override;
    void SerializeSnapshot(idSerializer* serializer,
        bool serializeParmBlock) override;
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    void SetFlareDeclaration(const idDeclFlare* declaration);
    void SetSunFlare(bool enabled);

    const idDeclFlare* flareDecl;
    int quadModelIndex;
    bool isSunFlare;

private:
    static UpdateCallback updateCallback;
    static DeclarationResolver declarationResolver;
    static SnapshotDeclarationCallback snapshotDeclarationCallback;
    static int mappedBufferIndex;
    static int vertOffset;
    static bool initialized;
};

class alignas(16) idRenderModelFlareOcclusionQuad : public idRenderModel {
public:
    using UpdateCallback = bool (*)(idRenderModelFlareOcclusionQuad* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);
    using AreaCallback = float (*)(const idRenderModelFlareOcclusionQuad* model,
        const idRenderView* currentView, const idRenderView* nextView);

    idRenderModelFlareOcclusionQuad();
    ~idRenderModelFlareOcclusionQuad() override;

    static void Init();
    static void Shutdown();
    static void StartFrame();
    static void SetUpdateCallback(UpdateCallback callback);
    static void SetAreaCallback(AreaCallback callback);

    void Save(idFile* file) override;
    bool Load(idFile* file) override;
    void SerializeSnapshot(idSerializer* serializer,
        bool serializeParmBlock) override;
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    float CalcScreenSpaceAreaForView(const idRenderView* currentView,
        const idRenderView* nextView) const;
    void SetSunFlare(bool enabled);
    float GetPreviousScreenSpaceArea() const {
        return screenSpaceArea[currentIdx ^ 1];
    }

    bool isSunFlare;
    int currentIdx;
    float screenSpaceArea[2];

private:
    static UpdateCallback updateCallback;
    static AreaCallback areaCallback;
    static int vertOffset;
    static bool initialized;
};
