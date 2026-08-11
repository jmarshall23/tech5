#pragma once

#include "decls/decltypeinfo.h"
#include "game/decls/relationship_core.h"

#include <cstdint>

class idEntity;
class idPresentable;

class idRelationshipList {
public:
    bool GetAttitudeTowards(const idDeclFaction* otherFaction,
        float& attitude) const;
    const idRelationship* GetRelationship(const idEntity* otherEntity) const;
    bool GetAttitudeTowards(const idEntity* otherEntity,
        float& attitude) const;
    void CullEntityRelationships();
    void AdjustAttitudeTowards(const idDeclFaction* myFaction,
        const idEntity* otherEntity, float adjust);

    idList<idRelationship, 5> relationships;
};

class idDeclFaction : public idDeclTypeInfo {
public:
    idDeclFaction();
    ~idDeclFaction() override = default;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    bool GetAttitudeTowards(const idDeclFaction* otherFaction,
        idRelationship::attitude_t& attitude) const;

    idStr factionNameId;
    const idDeclFaction* parentFaction;
    idRelationshipList relationships;
    static idDeclInfoTemplate<idDeclFaction> resourceList;
};

class idFactionServices {
public:
    virtual ~idFactionServices() = default;
    virtual std::int32_t GetSpawnId(const idEntity* entity) const = 0;
    virtual const idEntity* ResolveSpawnId(std::int32_t spawnId) const = 0;
    virtual bool IsDead(const idEntity* entity) const = 0;
    virtual const class idFaction* GetFaction(const idEntity* entity) const = 0;
    virtual const idEntity* GetPresentableEntity(
        const idPresentable* presentable) const = 0;
    virtual bool IsPlayer(const idEntity* entity) const = 0;
    virtual int GetPlayerAttitudeOverride() const = 0;
    virtual int GetOtherFactionAttitudeOverride() const = 0;
};

void Tungsten_SetFactionServices(idFactionServices* services);
idFactionServices& Tungsten_FactionServices();

class idFaction {
public:
    idFaction();

    idRelationship::attitude_t GetAttitudeTowards(
        const idFaction* otherFaction) const;
    idRelationship::attitude_t GetAttitudeTowards(
        const idEntity* otherEntity) const;
    idRelationship::attitude_t GetAttitudeTowards(
        const idPresentable* otherPresentable) const;
    idRelationship::attitude_t GetAttitudeTowards(
        std::int32_t spawnId) const;
    void SetDeclFaction(const idDeclFaction* faction,
        bool clearRelationships);
    void CullEntityRelationships();
    void AdjustAttitudeTowards(const idEntity* otherEntity, float adjust);

    const idDeclFaction* myFaction;
    idRelationshipList relationships;
};

