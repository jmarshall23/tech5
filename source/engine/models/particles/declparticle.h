#pragma once

#include "decls/decl.h"
#include "decls/decltable.h"
#include "idlib/bv/bounds.h"
#include "idlib/lookuptable.h"
#include "models/particles/jobs/particlestage.h"

class idFile;
class idSphere;

class idDeclParticle : public idDecl {
public:
    using MaterialResolver = const idMaterial* (*)(const char* name);
    using MaterialNameResolver = const char* (*)(const idMaterial* material);
    using StaticMeshResolver = const idStaticParticleModelData* (*)(
        const char* name);

    idDeclParticle();
    ~idDeclParticle() override;

    bool RebuildTextSource() override;
    const char* DefaultDefinition() const override;
    void LogMissingDecl() const override;
    void Parse(idParser* parser) override;
    void FreeData() override;
    unsigned int Size() const override;

    static void SetMaterialResolver(MaterialResolver resolver,
        MaterialNameResolver nameResolver = nullptr);
    static void SetStaticMeshResolver(StaticMeshResolver resolver);

    idParticleStage* CreateNewStage();
    idParticleStage* FindStageByName(const char* stageName);
    const idParticleStage* FindStageByName(const char* stageName) const;
    int CalcLodForDistance(float distanceSquared) const;
    const idLookupTable* GetTables() const;
    void UpdateBounds();
    void UpdateMaxSystemDuration();

    idList<idParticleStage*, 79> stages;
    idList<idAtomicString, 79> stageNames;
    idList<idAtomicString, 79> stageInheritNames;
    idList<const idDeclTable*, 79> tableDecls;
    idList<idLookupTable, 79> tables;
    idBounds bounds;
    int maxSystemDuration;
    int lodRadius;

private:
    idParticleStage* ParseParticleStage(idParser* parser,
        const char* stageName, idStr& inheritFrom);
    void WriteStage(idFile* file, const idParticleStage& stage,
        const char* stageName, const idParticleStage& parent,
        const char* parentName) const;

    static MaterialResolver materialResolver;
    static MaterialNameResolver materialNameResolver;
    static StaticMeshResolver staticMeshResolver;
};

int ParticleDistributionNameToType(const char* name);
int ParticleDirectionNameToType(const char* name);
int ParticleOrientationNameToType(const char* name);
int ParticleCustomNameToType(const char* name);
int ParticleTextureFlipNameToType(const char* name);
int ParticleAnimationNameToType(const char* name);
int ParticleSortNameToType(const char* name);

class idClothParticle {
public:
    void Reset();
    bool Update(float timeDeltaSqr, const idVec3& origin,
        const idMat3& orientation, const float& friction);
    void Collide(const idSphere* sphere, float radiusSquared);
    bool Simulate(float timeDelta, float frictionFactor);

    idVec3 origin;
    idVec3 lastOrigin;
    idVec3 velocity;
    idVec3 force;
    idMat3 axis;
    float mass;
    std::uint8_t neighbors[4];
    std::uint8_t anchored;
    std::uint16_t state;
};
