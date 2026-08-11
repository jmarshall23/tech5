#include "game/decls/declfaction.h"

#include <algorithm>

namespace {

class MissingFactionServices final : public idFactionServices {
public:
    std::int32_t GetSpawnId(const idEntity*) const override {
        return 0x1FFF;
    }
    const idEntity* ResolveSpawnId(std::int32_t) const override {
        return nullptr;
    }
    bool IsDead(const idEntity*) const override { return true; }
    const idFaction* GetFaction(const idEntity*) const override {
        return nullptr;
    }
    const idEntity* GetPresentableEntity(
        const idPresentable*) const override { return nullptr; }
    bool IsPlayer(const idEntity*) const override { return false; }
    int GetPlayerAttitudeOverride() const override { return -2; }
    int GetOtherFactionAttitudeOverride() const override { return -2; }
};

MissingFactionServices missingServices;
idFactionServices* factionServices = &missingServices;

} // namespace

void Tungsten_SetFactionServices(idFactionServices* services) {
    factionServices = services != nullptr ? services : &missingServices;
}

idFactionServices& Tungsten_FactionServices() {
    return *factionServices;
}

idDeclFaction::idDeclFaction()
    : factionNameId()
    , parentFaction(nullptr)
    , relationships() {
}

// EA 0x82BBDD40
idRelationship::attitude_t idRelationship::AttitudeForFloat(float value) {
    if (value < 0.0f) return ATTITUDE_NEUTRAL;
    if (value >= 6.0f) return ATTITUDE_IDOLIZE;
    if (value >= 5.0f) return ATTITUDE_LOVE;
    if (value >= 4.0f) return ATTITUDE_LIKE;
    if (value >= 3.0f) return ATTITUDE_NEUTRAL;
    if (value >= 2.0f) return ATTITUDE_DISLIKE;
    if (value >= 1.0f) return ATTITUDE_HATE;
    return ATTITUDE_DESPISE;
}

// EA 0x82BBDDE8
float idRelationship::FloatForAttitude(attitude_t value) {
    return static_cast<float>(value);
}

// EA 0x82BBDE00
void idRelationship::AdjustAttitude(float amount) {
    if (curAttitude == -1.0f) curAttitude = FloatForAttitude(attitude);
    curAttitude = (std::max)(0.0f, (std::min)(6.0f,
        curAttitude + amount));
}

// EA 0x82BBDE68
idRelationship::attitudeStage_t idRelationship::AttitudeToAttitudeStage(
        attitude_t value) {
    if (value <= ATTITUDE_NEUTRAL) return ATTITUDESTAGE_OUTSIDER;
    if (value == ATTITUDE_LIKE) return ATTITUDESTAGE_ACCEPTED;
    return ATTITUDESTAGE_HEROIC;
}

// EA 0x82BBDE90
bool idRelationshipList::GetAttitudeTowards(
        const idDeclFaction* otherFaction, float& attitude) const {
    attitude = 3.0f;
    if (otherFaction == nullptr) return false;
    for (int index = 0; index < relationships.Num(); ++index) {
        const idRelationship& relationship = relationships[index];
        if (relationship.otherFaction != otherFaction) continue;
        if (relationship.curAttitude == -1.0f) {
            relationship.curAttitude = idRelationship::FloatForAttitude(
                relationship.attitude);
        }
        attitude = relationship.curAttitude;
        return true;
    }
    return false;
}

// EA 0x82BBDF28
bool idDeclFaction::GetAttitudeTowards(const idDeclFaction* otherFaction,
        idRelationship::attitude_t& attitude) const {
    if (otherFaction == nullptr) {
        attitude = idRelationship::ATTITUDE_NEUTRAL;
        return false;
    }
    float value = 3.0f;
    if (relationships.GetAttitudeTowards(otherFaction, value)) {
        attitude = idRelationship::AttitudeForFloat(value);
        return true;
    }
    if (parentFaction != nullptr
            && parentFaction->GetAttitudeTowards(otherFaction, attitude)) {
        return true;
    }
    if (otherFaction->parentFaction != nullptr
            && GetAttitudeTowards(otherFaction->parentFaction, attitude)) {
        return true;
    }
    attitude = otherFaction == this
        ? idRelationship::ATTITUDE_LIKE
        : idRelationship::ATTITUDE_NEUTRAL;
    return false;
}

// EA 0x82BBDFF8
idRelationship::attitude_t idFaction::GetAttitudeTowards(
        const idFaction* otherFaction) const {
    if (otherFaction == nullptr) return idRelationship::ATTITUDE_NEUTRAL;
    const int overrideValue = Tungsten_FactionServices()
        .GetOtherFactionAttitudeOverride();
    if (overrideValue > -2) {
        return static_cast<idRelationship::attitude_t>(overrideValue);
    }
    float value = 3.0f;
    if (relationships.GetAttitudeTowards(otherFaction->myFaction, value)) {
        return idRelationship::AttitudeForFloat(value);
    }
    if (myFaction == nullptr) return idRelationship::ATTITUDE_NEUTRAL;
    idRelationship::attitude_t attitude = idRelationship::ATTITUDE_NEUTRAL;
    myFaction->GetAttitudeTowards(otherFaction->myFaction, attitude);
    return attitude;
}

// EA 0x82BBE098
void idFaction::SetDeclFaction(const idDeclFaction* faction,
        bool clearRelationships) {
    myFaction = faction;
    if (clearRelationships) relationships.relationships.Clear();
}

// EA 0x82BBE0B8
idRelationship::idRelationship()
    : otherFaction(nullptr)
    , attitude(ATTITUDE_UNKNOWN)
    , curAttitude(-1.0f)
    , otherEntity() {
}

// EA 0x82BBE0E0
const idRelationship* idRelationshipList::GetRelationship(
        const idEntity* otherEntity) const {
    if (otherEntity == nullptr) return nullptr;
    idFactionServices& services = Tungsten_FactionServices();
    for (int index = relationships.Num() - 1; index >= 0; --index) {
        if (services.ResolveSpawnId(
                relationships[index].otherEntity.GetSpawnId())
                == otherEntity) {
            return &relationships[index];
        }
    }
    return nullptr;
}

// EA 0x82BBE190
bool idRelationshipList::GetAttitudeTowards(const idEntity* otherEntity,
        float& attitude) const {
    attitude = 3.0f;
    const idRelationship* relationship = GetRelationship(otherEntity);
    if (relationship == nullptr) return false;
    if (relationship->curAttitude == -1.0f) {
        relationship->curAttitude = idRelationship::FloatForAttitude(
            relationship->attitude);
    }
    attitude = relationship->curAttitude;
    return true;
}

// EA 0x82BBE220
void idRelationshipList::CullEntityRelationships() {
    idFactionServices& services = Tungsten_FactionServices();
    for (int index = relationships.Num() - 1; index >= 0; --index) {
        const idRelationship& relationship = relationships[index];
        if (relationship.otherFaction != nullptr) continue;
        const idEntity* entity = services.ResolveSpawnId(
            relationship.otherEntity.GetSpawnId());
        if (entity == nullptr || services.IsDead(entity)) {
            relationships.RemoveIndexFast(index);
        }
    }
}

// EA 0x82BBE328
idRelationship::attitude_t idFaction::GetAttitudeTowards(
        const idEntity* otherEntity) const {
    if (otherEntity == nullptr) return idRelationship::ATTITUDE_NEUTRAL;
    idFactionServices& services = Tungsten_FactionServices();
    const int playerOverride = services.GetPlayerAttitudeOverride();
    if (playerOverride > -2 && services.IsPlayer(otherEntity)) {
        return static_cast<idRelationship::attitude_t>(playerOverride);
    }
    float value = 3.0f;
    if (relationships.GetAttitudeTowards(otherEntity, value)) {
        return idRelationship::AttitudeForFloat(value);
    }
    return GetAttitudeTowards(services.GetFaction(otherEntity));
}

// EA 0x82BBE3D8
idRelationship::attitude_t idFaction::GetAttitudeTowards(
        const idPresentable* otherPresentable) const {
    return GetAttitudeTowards(Tungsten_FactionServices()
        .GetPresentableEntity(otherPresentable));
}

// EA 0x82BBE3F0
idRelationship::attitude_t idFaction::GetAttitudeTowards(
        std::int32_t spawnId) const {
    return GetAttitudeTowards(
        Tungsten_FactionServices().ResolveSpawnId(spawnId));
}

// EA 0x82BBE440
void idFaction::CullEntityRelationships() {
    relationships.CullEntityRelationships();
}

// EA 0x82BBE448
idFaction::idFaction()
    : myFaction(nullptr)
    , relationships() {
}

// EA 0x82BBE6A8
void idRelationshipList::AdjustAttitudeTowards(
        const idDeclFaction* myFaction, const idEntity* otherEntity,
        float adjust) {
    if (otherEntity == nullptr) return;
    idRelationship* relationship = const_cast<idRelationship*>(
        GetRelationship(otherEntity));
    if (relationship == nullptr) {
        relationship = relationships.Alloc();
        if (relationship == nullptr) return;
        relationship->otherEntity.SetSpawnId(
            Tungsten_FactionServices().GetSpawnId(otherEntity));
        relationship->otherFaction = nullptr;
        const idFaction* otherFaction =
            Tungsten_FactionServices().GetFaction(otherEntity);
        idRelationship::attitude_t initial =
            idRelationship::ATTITUDE_NEUTRAL;
        if (myFaction != nullptr) {
            myFaction->GetAttitudeTowards(
                otherFaction != nullptr ? otherFaction->myFaction : nullptr,
                initial);
        }
        relationship->attitude = initial;
        relationship->curAttitude =
            idRelationship::FloatForAttitude(initial);
    }
    relationship->AdjustAttitude(adjust);
}

// EA 0x82BBE778
void idFaction::AdjustAttitudeTowards(const idEntity* otherEntity,
        float adjust) {
    relationships.AdjustAttitudeTowards(myFaction, otherEntity, adjust);
}

