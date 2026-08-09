#pragma once

#include "models/static/staticmodel.h"

class idStaticModelManager {
public:
    struct idStats {
        int totalCPUMem;
        int totalGPUMem;
        int inUse;
        int totalVerts;
        int totalTriangles;
        int totalSurfaces;
    };

    virtual ~idStaticModelManager() = default;
    virtual void Init() {}
    virtual const idStaticModel* FindStaticModel(const char*, bool) {
        return nullptr;
    }
    virtual void AddStaticModel(idStaticModel*) {}
    virtual void ReloadModels() {}
    virtual void CalculateStats(idStats* stats) {
        if (stats != nullptr) {
            *stats = {};
        }
    }
};

class idStaticModelManagerLocal : public idStaticModelManager {
public:
    void Init() override;
    const idStaticModel* FindStaticModel(const char* name,
        bool makeDefault) override;
    void AddStaticModel(idStaticModel* model) override;
    void ReloadModels() override;
    void CalculateStats(idStats* stats) override;
};

extern idStaticModelManagerLocal localModelManager;
extern idStaticModelManager* staticModelManager;

static_assert(sizeof(idStaticModelManager::idStats) == 24,
    "Recovered static-model statistics ABI changed");
