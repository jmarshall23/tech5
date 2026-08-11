#include "game/entities/actor.h"

#include "idlib/lib_print.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {
idActorServices defaultActorServices;
idActorServices* activeActorServices = &defaultActorServices;

idVec3 ComponentMultiply(const idVec3& left, const idVec3& right) {
    return idVec3(left.x * right.x, left.y * right.y,
        left.z * right.z);
}

idVec3 BoundsCenter(const idBounds& bounds) {
    return (bounds[0] + bounds[1]) * 0.5f;
}
}

const idAASPosition& idActorServices::GetAASPosition(
        const idActor& actor, const idAAS2*) const {
    return actor.actorVolatile.aasPosition;
}

void idActor::SetServices(idActorServices* services) {
    activeActorServices = services == nullptr
        ? &defaultActorServices : services;
}

idActorServices& idActor::Services() {
    return *activeActorServices;
}

// EA 0x82BE2558
void idActor::Hide() {
    Services().SetActorVisible(*this, false);
    Services().SetAllAttachmentsVisible(*this, false);
}

// EA 0x82BE25F0
void idActor::Show() {
    Services().SetActorVisible(*this, true);
    Services().SetAllAttachmentsVisible(*this, true);
}

// EA 0x82BE2688
void idActor::ProjectOverlay(const idVec3& origin, const idVec3& direction,
        const float size, const char* material) {
    Services().ProjectActorOverlay(*this, origin, direction, size, material);
}

// EA 0x82BE2740
void idActor::UpdateAttachments() {
    Services().UpdateBaseAttachments(*this);
    GetViewTransform(actorVolatile.modelInfo.eyePos,
        actorVolatile.modelInfo.eyeAxis);
}

// EA 0x82BE2788
int idActor::GetAreaNum(const idAAS2* aas) const {
    return GetAASPosition(aas).GetAreaNum();
}

// EA 0x82BE27E0
const idAASPosition& idActor::GetAASPosition(const idAAS2* aas) const {
    return Services().GetAASPosition(*this, aas);
}

// EA 0x82BE2830
idWeapon* idActor::GetEquippedWeapon(const equipSlot_t slot) const {
    return Services().CastWeapon(GetEquipped(slot));
}

// EA 0x82BE2878
idWeapon* idActor::GetEquippedWeapon() const {
    return GetEquippedWeapon(Services().GetWeaponSlot(*this));
}

// EA 0x82BE28E8
void idActor::InventoryRemoved(idInventoryItem* item) {
    ClearEquipped(item);
    Services().BaseInventoryRemoved(*this, item);
}

// EA 0x82BE2928
void idActor::DropAttachment(const equipSlot_t slot) {
    DropAttachment(GetEquipped(slot));
}

// EA 0x82BE2978
idInventoryItem* idActor::GetEquipped(const equipSlot_t slot) const {
    return slot >= EQUIP_NONE && slot < EQUIP_MAX
        ? equipped[slot] : nullptr;
}

// EA 0x82BE2988
void idActor::ClearEquipped(const equipSlot_t slot) {
    if (slot >= EQUIP_NONE && slot < EQUIP_MAX) {
        equipped[slot] = nullptr;
    }
}

// EA 0x82BE29A0
void idActor::ClearEquipped(idInventoryItem* item) {
    for (int slot = 0; slot < EQUIP_MAX; ++slot) {
        if (equipped[slot] == item) {
            equipped[slot] = nullptr;
            return;
        }
    }
}

// EA 0x82BE29E0
void idActor::SetFaction(const idDeclFaction* factionDecl) {
    faction.SetDeclFaction(factionDecl, false);
}

// EA 0x82BE29F0
bool idActor::IsCrouching() const {
    return GetPosture() == POSTURE_CROUCHED;
}

// EA 0x82BE2A28
bool idActor::IsSitting() const {
    return GetPosture() == POSTURE_SITTING;
}

// EA 0x82BE2A60
idVehicle* idActor::GetVehicle() {
    return Services().GetBoundVehicle(*this);
}

const idVehicle* idActor::GetVehicle() const {
    return Services().GetBoundVehicle(*this);
}

// EA 0x82BE2A88
bool idActor::IsDrivingVehicle() const {
    const idVehicle* vehicle = GetVehicle();
    return vehicle != nullptr && Services().GetVehicleDriver(vehicle) == this;
}

// EA 0x82BE2AE0
eventBool idActor::Event_ItemInInventory(
        const char* internalName, const float count) {
    idLibPrint::Warning(
        "itemInInventory() is DEPRECATED. Use "
        "numOfItemTypeInInventory() instead.");
    return eventBool(Services().GetInventoryCountByName(
        *this, internalName) >= count);
}

// EA 0x82BE2B68
eventInt idActor::Event_NumOfItemTypeInInventory(
        const char* declName) {
    return eventInt(Services().GetInventoryCountByName(*this, declName));
}

// EA 0x82BE2BE8
eventString idActor::Event_CurrentNPC() const {
    return eventString(npcName.c_str());
}

// EA 0x82BE2C38
eventBool idActor::Event_IsDead() const {
    return eventBool(Services().IsDead(*this));
}

// EA 0x82BE2C88
eventFloat idActor::Event_GetWalkState() const {
    return eventFloat(static_cast<float>(GetWalkState()));
}

// EA 0x82BE2CE8
eventFloat idActor::Event_GetWeaponReadyState() const {
    return eventFloat(static_cast<float>(GetWeaponReadyState()));
}

// EA 0x82BE2D48
idDisassembleLoot* idActor::GetDisassembleLoot() {
    return &disassembleLoot;
}

// EA 0x82BE2D50
eventVoid idActor::Event_PostSpawn() {
    if (!Services().HasActorPhysics(*this)) {
        idLibPrint::Warning(
            "Entity '%s' does not have physics derived from idPhysics_Actor "
            "but the idActor entity assumes this to be true. Removing entity "
            "to prevent crashes.", name.c_str());
        Services().RemoveEntity(reinterpret_cast<idEntity*>(this));
    }
    return {};
}

// EA 0x82BE2DE0
bool idActor::CanBeHealed() const {
    const float maximum = Services().GetMaxHealth(*this);
    return maximum > 0.0f && Services().GetHealth(*this) < maximum;
}

// EA 0x82BE2E68
void idActor::SetAxis(const idMat3& axis) {
    actorVolatile.modelInfo.modelAxis = axis;
}

// EA 0x82BE2EB8
int idActor::GetDefaultSurfaceType() const {
    return actorConstants.actorClass == ACTORCLASS_MUTANT ? 27 : 3;
}

// EA 0x82BE2ED8
idPresentable* idActor::AllocPresentable(idRenderModel* renderModel) {
    // The retail allocation-failure cleanup is represented by the service's
    // transactional ownership of the presentable construction.
    return Services().AllocActorPresentable(*this, renderModel);
}

// EA 0x82BE2FD0
void idActor::GetModelTransform(idVec3& origin, idMat3& axis) const {
    if (Services().GetRagdollModelTransform(*this, origin, axis)) {
        return;
    }
    const idActorPhysicsState physics = Services().GetPhysicsState(*this);
    axis = actorVolatile.modelInfo.modelAxis * physics.axis;
    origin = physics.origin + axis * actorConstants.modelInfo.modelOffset;
}

// EA 0x82BE3170
void idActor::GetSoundTransform(idVec3& origin, idMat3& axis) const {
    if (Services().GetRagdollSoundTransform(*this, origin, axis)) {
        return;
    }
    if (actorVolatile.modelInfo.soundJoint.IsValid()
            && Services().GetSoundJointTransform(*this, origin, axis)) {
        const idActorPhysicsState physics = Services().GetPhysicsState(*this);
        origin = physics.origin + actorVolatile.modelInfo.modelAxis
            * (actorConstants.modelInfo.modelOffset + origin);
        axis = physics.axis;
        return;
    }
    const idActorPhysicsState physics = Services().GetPhysicsState(*this);
    origin = physics.origin
        - physics.gravityNormal * GetEyeOffset().z;
    axis = physics.axis;
}

// EA 0x82BE3530
idVec3 idActor::GetEyeOffset() const {
    idVec3 offset = actorConstants.perception.eyeOffset;
    if ((IsCrouching() || IsSitting())
            && !Services().UseStandingEyeOffsetWhenCrouched(*this)) {
        offset = actorConstants.perception.crouchedEyeOffset;
    }
    offset = Services().GetPresentableAxis(*this) * offset;
    return ComponentMultiply(offset, Services().GetScale(*this));
}

// EA 0x82BE36D0
void idActor::GetViewTransform(idVec3& origin, idMat3& axis) const {
    const idActorPhysicsState physics = Services().GetPhysicsState(*this);
    origin = physics.origin
        - physics.gravityNormal * GetEyeOffset().z;
    axis = actorVolatile.modelInfo.modelAxis;
}

// EA 0x82BE37F0
void idActor::GetEyePos(idVec3& eyePos) const {
    idVec3 baseOrigin;
    if (!Services().GetAnimatedModelOrigin(*this, baseOrigin)) {
        baseOrigin = Services().GetPhysicsState(*this).origin;
    }
    eyePos = baseOrigin + GetEyeOffset();
}

// EA 0x82BE3908
void idActor::GetAimPoint(const aimPoint_t type, idVec3& position) const {
    if (Services().GetBindMasterAimPoint(*this, type, position)) {
        return;
    }
    const idActorPhysicsState physics = Services().GetPhysicsState(*this);
    switch (type) {
        case AIMPOINT_HEAD:
        case AIMPOINT_EYELEVEL:
            GetEyePos(position);
            return;
        case AIMPOINT_TORSO: {
            idVec3 eye;
            GetEyePos(eye);
            position = eye * 0.65f + BoundsCenter(physics.absBounds) * 0.35f;
            return;
        }
        case AIMPOINT_CENTER:
        case AIMPOINT_BEST:
            position = BoundsCenter(physics.absBounds);
            return;
        case AIMPOINT_LEGS:
            position = physics.origin;
            position.z += (physics.absBounds[1].z
                - physics.absBounds[0].z) * 0.25f;
            return;
        case AIMPOINT_LOOKAHEAD: {
            GetEyePos(position);
            idVec3 direction = physics.linearVelocity;
            direction.NormalizeFast();
            position = position + direction * 64.0f;
            return;
        }
        case AIMPOINT_ORIGIN:
        case AIMPOINT_FEET:
        default:
            position = physics.origin;
            return;
    }
}

// EA 0x82BE3C40
actorRagdollResult_t idActor::StartRagdoll(const idRagdollInfo& info) {
    return Services().StartRagdoll(*this, info);
}

// EA 0x82BE3ED8
void idActor::StopRagdoll() {
    if (Services().IsRagdollActive(*this)) {
        Services().StopRagdoll(*this);
    }
}

// EA 0x82BE3F10
void idActor::Teleport(const idVec3& requestedOrigin,
        const idAngles& angles) {
    idVec3 origin = requestedOrigin;
    origin.z += 0.25f;
    Services().SetPhysicsOrigin(*this, origin);
    Services().SetPhysicsVelocity(*this, idVec3(0.0f, 0.0f, 0.0f));
    actorVolatile.modelInfo.modelAxis = angles.ToMat3();
    Services().UpdateVisuals(*this);
    Services().ForceAwake(*this, 30000);
    Services().KillBox(*this);
}

// EA 0x82BE4040
int idActor::GetLastValidAreaNum(const idAAS2* aas) const {
    return GetAASPosition(aas).areaNum;
}

// EA 0x82BE4098
const idVec3& idActor::GetLastValidAASOrigin(const idAAS2* aas) const {
    return GetAASPosition(aas).validOrigin;
}

// EA 0x82BE40F0
const idVec3& idActor::GetAASOrigin(const idAAS2* aas) const {
    return GetAASPosition(aas).origin;
}

// EA 0x82BE4148
void idActor::DoLocationDamage(const idDeclDamage* damageDecl,
        idDamageGroup* group, const float baseDamage,
        float& bodyDamage, float& limbDamage, float& armorDamage,
        float& armorDamageScale, float& armoredHealthDamageScale,
        float& bleedThroughDamage, float& excessDamage,
        const idDeclDamage::damageType_t damageTypes) {
    bodyDamage = 0.0f;
    limbDamage = 0.0f;
    armorDamage = 0.0f;
    armorDamageScale = 0.0f;
    armoredHealthDamageScale = 1.0f;
    bleedThroughDamage = 0.0f;
    excessDamage = 0.0f;
    if (group == nullptr) {
        limbDamage = baseDamage;
        return;
    }

    float armorPenetration = 0.0f;
    if ((damageTypes & idDeclDamage::DAMAGETYPE_EXPLOSION) != 0) {
        armorPenetration = 0.3f;
        armoredHealthDamageScale *= 2.0f;
    }
    bodyDamage = (std::max)(0.0f, 1.0f
        - (armorPenetration * group->damageScale
            + group->armoredDamageScale));
    armorDamageScale = (std::max)(0.0f,
        armoredHealthDamageScale * baseDamage - group->locationArmor);
    bleedThroughDamage = (std::max)(0.0f,
        group->locationArmor - baseDamage) * bodyDamage;
    armorDamage = (std::min)(baseDamage,
        group->locationArmor / armoredHealthDamageScale);
    excessDamage = armorDamage * group->damageScale;
    group->locationArmor = (std::max)(0.0f,
        group->locationArmor - armorDamageScale);
    if (group->locationArmor < 0.1f) {
        group->locationArmor = 0.0f;
    }
    if (group->affectsOverallHealth) {
        limbDamage = bleedThroughDamage + excessDamage;
    }
    if (damageDecl != nullptr && damageDecl->ignoreArmor) {
        armorDamage = baseDamage;
        limbDamage = baseDamage;
    }
    group->health -= armorDamage;
}

// EA 0x82BE42B0
idDamageGroup* idActor::GetDamageGroup(const idActorJointIndex joint) {
    const char* groupName = Services().GetJointGroupName(*this, 0, joint);
    return groupName == nullptr ? nullptr : GetDamageGroup(groupName);
}

// EA 0x82BE4388
idJointGroupHandle idActor::GetDamageGroupHandle(
        const idActorJointIndex joint) const {
    return Services().GetJointGroupHandle(*this, 0, joint);
}

// EA 0x82BE4418
idDamageGroup* idActor::GetDamageGroup(
        const idJointGroupHandle& handle) {
    const char* groupName = Services().GetJointGroupNameForHandle(
        *this, handle);
    return groupName == nullptr ? nullptr : GetDamageGroup(groupName);
}

// EA 0x82BE44E8
idDamageGroup* idActor::GetDamageGroup(const char* groupName) {
    if (groupName == nullptr) return nullptr;
    for (int index = 0; index < actorEditable.damageGroups.Num(); ++index) {
        if (idStr::Icmp(actorEditable.damageGroups[index].groupName.c_str(),
                groupName) == 0) {
            return &actorEditable.damageGroups[index];
        }
    }
    return nullptr;
}

// EA 0x82BE4560
idJointGroupHandle idActor::GetPainGroupHandle(
        const idActorJointIndex joint) const {
    return Services().GetJointGroupHandle(*this, 1, joint);
}

// EA 0x82BE45F8
idJointGroupHandle idActor::GetDeathGroupHandle(
        const idActorJointIndex joint) const {
    return Services().GetJointGroupHandle(*this, 3, joint);
}

// EA 0x82BE4690
damageDirection_t idActor::GetDamageDirection(const idMat3& axis,
        const idVec3& direction, const int numDirections) {
    const float side = axis[1].x * direction.x
        + axis[1].y * direction.y + axis[1].z * direction.z;
    const float front = axis[0].x * direction.x
        + axis[0].y * direction.y + axis[0].z * direction.z;
    if (numDirections == 1) return DAMAGEDIR_FRONT;
    if (numDirections == 2) {
        return front > 0.0f ? DAMAGEDIR_BACK : DAMAGEDIR_FRONT;
    }
    if (numDirections == 4) {
        if (front >= 0.70710677f) return DAMAGEDIR_BACK;
        if (front <= -0.70710677f) return DAMAGEDIR_FRONT;
        return side <= -0.70710677f
            ? DAMAGEDIR_LEFT : DAMAGEDIR_RIGHT;
    }
    if (numDirections != 8) return DAMAGEDIR_NONE;
    if (side >= 0.0f) {
        if (front < -0.92387003f) return DAMAGEDIR_FRONT;
        if (front < -0.38262999f) return DAMAGEDIR_FRONTRIGHT;
        if (front < 0.38262999f) return DAMAGEDIR_RIGHT;
        if (front < 0.92387003f) return DAMAGEDIR_BACKRIGHT;
        return DAMAGEDIR_BACK;
    }
    if (front < -0.92387003f) return DAMAGEDIR_FRONT;
    if (front < -0.38262999f) return DAMAGEDIR_FRONTLEFT;
    if (front < 0.38262999f) return DAMAGEDIR_LEFT;
    if (front < 0.92387003f) return DAMAGEDIR_BACKLEFT;
    return DAMAGEDIR_BACK;
}

// EA 0x82BE47F0
damageIntensity_t idActor::GetDamageIntensity(
        const idDeclDamage* damageDef, const float damage) const {
    if (damageDef != nullptr
            && damageDef->intensity != DAMAGEINTENSITY_NONE) {
        return damageDef->intensity;
    }
    const float maximum = Services().GetMaxHealth(*this);
    if (maximum <= 0.0f) return DAMAGEINTENSITY_HEAVY;
    const float ratio = damage / maximum;
    if (ratio < 0.26f) return DAMAGEINTENSITY_LIGHT;
    return ratio < 0.66f
        ? DAMAGEINTENSITY_MEDIUM : DAMAGEINTENSITY_HEAVY;
}

// EA 0x82BE48C0
void idActor::ApplyWaterEffects(const int physicsId, const int id) {
    (void)physicsId;
    (void)id;
    const idActorPhysicsState physics = Services().GetPhysicsState(*this);
    const float speed = physics.linearVelocity.Length();
    const bool fast = speed > actorConstants.waterInteraction.moveSpeedSlow;
    const idDeclParticle* particle = fast
        ? actorConstants.waterInteraction.waterPrtFast
        : actorConstants.waterInteraction.waterPrtSlow;
    if (particle != nullptr && Services().RandomFloat()
            < actorConstants.waterInteraction.emissionRate) {
        Services().EmitWaterParticle(*this, particle, physics.origin,
            Services().RandomFloat());
    }
}

// EA 0x82BE4AD0
idTreeAnimator* idActor::GetEquippedWeaponAnimator() {
    idWeapon* weapon = GetEquippedWeapon();
    if (weapon == nullptr) {
        idLibPrint::Warning(
            "idActor::GetEquippedWeaponAnimator - no equipped weapon");
        return nullptr;
    }
    idInventoryItem* item = reinterpret_cast<idInventoryItem*>(weapon);
    if (!Services().HasItemAttachment(*this, item)) {
        idLibPrint::Warning(
            "idActor::GetEquippedWeaponAnimator - could not find weapon "
            "attachment");
        return nullptr;
    }
    idTreeAnimator* animator = Services().GetItemAttachmentAnimator(
        *this, item);
    if (animator == nullptr) {
        idLibPrint::Warning(
            "idActor::GetEquippedWeaponAnimator - attachment has no model");
    }
    return animator;
}

// EA 0x82BE4BE0
bool idActor::GetMeleeTagData(const char* tagName, tagData_t& tag,
        idVec3& origin, bool& useWeaponAnimator) {
    useWeaponAnimator = false;
    idTreeAnimator* animator = GetEquippedWeaponAnimator();
    if (animator != nullptr
            && Services().GetAnimatorTag(animator, tagName, tag, origin)
            && tag.parentJoint != 0xFFFFu) {
        useWeaponAnimator = true;
        return true;
    }
    return Services().GetAnimatorTag(nullptr, tagName, tag, origin)
        && tag.parentJoint != 0xFFFFu;
}

// EA 0x82BE4DB0
bool idActor::IsEquippedWeaponOneHanded() const {
    idWeapon* weapon = GetEquippedWeapon();
    if (weapon == nullptr) return false;
    const idActorItemInfo item = Services().GetItemInfo(
        reinterpret_cast<idInventoryItem*>(weapon));
    return item.numHands == 1;
}

// EA 0x82BE4E28
bool idActor::EquipItem(idInventoryItem* item, equipSlot_t slot) {
    if (item == nullptr) return false;
    const idActorItemInfo info = Services().GetItemInfo(item);
    if (info.holsterSlot > EQUIP_NONE && info.holsterSlot < EQUIP_MAX
            && equipped[info.holsterSlot] == item) {
        Services().RemoveItemAttachment(*this, item);
        ClearEquipped(info.holsterSlot);
    }
    if (slot == EQUIP_NONE) {
        slot = info.equipSlot;
    }
    if (slot <= EQUIP_NONE || slot >= EQUIP_MAX) return false;
    if (equipped[slot] == item) return false;
    if (equipped[slot] != nullptr) {
        idInventoryItem* previous = equipped[slot];
        Services().RemoveItemAttachment(*this, previous);
        ClearEquipped(slot);
        HolsterItem(previous, true);
    }
    if (!info.noAttachment && Services().IsServer()) {
        Services().AddItemAttachment(*this, item, slot);
    }
    equipped[slot] = item;
    Services().OnItemEquipped(*this, item);
    return true;
}

// EA 0x82BE5090
void idActor::ShowAttachment(idInventoryItem* item) {
    if (item == nullptr || !Services().HasItemAttachment(*this, item)) {
        const idActorItemInfo info = Services().GetItemInfo(item);
        idLibPrint::Warning("ShowAttachment - no attachment for item '%s'.",
            info.internalName);
        return;
    }
    Services().ActOnItemAttachment(
        *this, item, ACTOR_ATTACHMENT_SHOW);
}

// EA 0x82BE5108
void idActor::HideAttachment(idInventoryItem* item) {
    if (item == nullptr || !Services().HasItemAttachment(*this, item)) {
        const idActorItemInfo info = Services().GetItemInfo(item);
        idLibPrint::Warning("ShowAttachment - no attachment for item '%s'.",
            info.internalName);
        return;
    }
    Services().ActOnItemAttachment(
        *this, item, ACTOR_ATTACHMENT_HIDE);
}

// EA 0x82BE5180
eventVoid idActor::Event_UnequipAndDeleteDroppedItem(
        const equipSlot_t slot) {
    idInventoryItem* item = GetEquipped(slot);
    if (item != nullptr) {
        UnequipItem(item);
        Services().DeleteInventoryItem(*this, item, 1);
    }
    return {};
}

// EA 0x82BE51F8
idFXManager* idActor::GetFXMgrForAttachment(idInventoryItem* item) {
    return Services().GetAttachmentFXManager(*this, item);
}

// EA 0x82BE52A8
void idActor::RepairShield(const float value) {
    Services().RepairShield(*this, value);
}

// EA 0x82BE5300
bool idActor::HolsterItem(idInventoryItem* item,
        const bool showHolstered) {
    if (item == nullptr) return false;
    const idActorItemInfo info = Services().GetItemInfo(item);
    const equipSlot_t slot = info.holsterSlot;
    if (slot <= EQUIP_NONE || slot >= EQUIP_MAX
            || equipped[slot] == item) {
        return false;
    }
    if (equipped[slot] != nullptr) {
        idLibPrint::Warning(
            "Tried to holster item '%s' in slot '%s' when it is already "
            "occupied",
            info.name, idDeclInventory::equipSlotTagNames[slot]);
        return false;
    }
    if (showHolstered) {
        Services().AddItemAttachment(*this, item, slot);
    }
    equipped[slot] = item;
    return true;
}

// EA 0x82BE53C0
bool idActor::UnequipItem(idInventoryItem* item) {
    if (item == nullptr) return false;
    int slot = EQUIP_NONE;
    while (slot < EQUIP_MAX && equipped[slot] != item) {
        ++slot;
    }
    if (slot >= EQUIP_MAX) return false;
    Services().OnItemUnequipped(*this, item);
    Services().RemoveItemAttachment(*this, item);
    ClearEquipped(static_cast<equipSlot_t>(slot));
    return true;
}

// EA 0x82BE5498
void idActor::SetLooted(const bool value) {
    looted = value;
    if (value) {
        Services().ClearLootHighlight(*this);
    }
}

// EA 0x82BE54F8
bool idActor::HasLootableItems() const {
    for (int index = 0; index < Services().GetNumInventoryItems(*this);
            ++index) {
        idInventoryItem* item = Services().GetInventoryItem(*this, index);
        if (item != nullptr && Services().GetItemInfo(item).lootable) {
            return true;
        }
    }
    return false;
}

// EA 0x82BE5588
idFaction* idActor::GetFaction() {
    UpdateTempFaction();
    return &faction;
}

const idFaction* idActor::GetFaction() const {
    const_cast<idActor*>(this)->UpdateTempFaction();
    return &faction;
}

// EA 0x82BE5600
void idActor::UpdateTempFaction() {
    if (tempFactionTime > 0
            && Services().GetGameMilliseconds() > tempFactionTime) {
        faction.SetDeclFaction(tempFaction, false);
        tempFaction = nullptr;
        tempFactionTime = 0;
    }
}

// EA 0x82BE5678
void idActor::SetPosture(const posture_t state) {
    if (state <= POSTURE_NONE || state >= POSTURE_MAX
            || actorEditable.forceBodyState) {
        return;
    }
    const posture_t previous = actorEditable.bodyState;
    actorEditable.bodyState = state;
    if (previous != state) {
        actorVolatile.postureChangeTime =
            Services().GetGameMilliseconds();
        Services().UpdatePostureClip(*this, state == POSTURE_SITTING);
    }
}

// EA 0x82BE5778
void idActor::DamageFeedback(idEntity* victim, idEntity* inflictor,
        const idDeclDamage* damageDef, float& damage) {
    if (Services().IsMultiplayer()) {
        Services().DamageFeedback(
            *this, victim, inflictor, damageDef, damage);
    }
}

// EA 0x82BE5898
void idActor::GetViewStateFOV(idVec3& forward,
        std::uint8_t& horizontal, std::uint8_t& vertical) const {
    forward = actorVolatile.modelInfo.eyeAxis[0];
    horizontal = Services().FovDotToByte(
        Services().GetAIFovDot(*this));
    vertical = 0;
}

// EA 0x82BE5920
eventVoid idActor::Event_SetPosture(const posture_t posture) {
    SetPosture(posture);
    return {};
}

// EA 0x82BE5968
eventBool idActor::Event_NeedsHealth() const {
    return eventBool(CanBeHealed());
}

// EA 0x82BE5A08
eventVoid idActor::Event_IncreaseHealth(const float amount) {
    Services().IncreaseHealth(*this, amount);
    return {};
}

// EA 0x82BE5A70
eventVoid idActor::Event_DecreaseHealth(const float amount) {
    Services().DecreaseHealth(*this, amount);
    return {};
}

// EA 0x82BE5AD8
eventVoid idActor::Event_SetHealth(const float health) {
    if (health > 0.0f) {
        Services().SetHealth(*this, health);
    }
    return {};
}

// EA 0x82BE5B78
eventVoid idActor::Event_EnableWalkIK() {
    Services().SetWalkIKEnabled(*this, true);
    return {};
}

// EA 0x82BE5BB0
eventVoid idActor::Event_DisableWalkIK() {
    Services().SetWalkIKEnabled(*this, false);
    return {};
}

// EA 0x82BE5BE8
eventVoid idActor::Event_EnableLegIK(const int leg) {
    Services().SetLegIKEnabled(*this, leg, true);
    return {};
}

// EA 0x82BE5C28
eventVoid idActor::Event_DisableLegIK(const int leg) {
    Services().SetLegIKEnabled(*this, leg, false);
    return {};
}

// EA 0x82BE5C68
eventVoid idActor::Event_RemoveAllInventoryItems() {
    for (int slot = 0; slot < EQUIP_MAX; ++slot) {
        if (equipped[slot] != nullptr) {
            UnequipItem(equipped[slot]);
        }
    }
    Services().FreeInventory(*this);
    return {};
}

eventVoid idActor::AttachmentEvent(const char* slotName,
        const actorAttachmentAction_t action, const char* source) {
    const equipSlot_t slot = idDeclInventory::EquipSlotForName(slotName);
    if (slot < EQUIP_NONE || slot >= EQUIP_MAX) {
        idLibPrint::Warning("%s - Invalid equip slot", source);
        return {};
    }
    idInventoryItem* item = GetEquipped(slot);
    if (item == nullptr) {
        idLibPrint::Warning("%s - Tried to modify an item in an empty slot.",
            source);
        return {};
    }
    if (!Services().HasItemAttachment(*this, item)) {
        idLibPrint::Warning("%s - no attachment for item '%s'.", source,
            Services().GetItemInfo(item).internalName);
        return {};
    }
    Services().ActOnItemAttachment(*this, item, action);
    return {};
}

// EA 0x82BE5CF0
eventVoid idActor::Event_HideAttachment(const char* slotName) {
    return AttachmentEvent(slotName, ACTOR_ATTACHMENT_HIDE,
        "Event_HideAttachment");
}

// EA 0x82BE5DE0
eventVoid idActor::Event_ShowAttachment(const char* slotName) {
    return AttachmentEvent(slotName, ACTOR_ATTACHMENT_SHOW,
        "Event_ShowAttachment");
}

// EA 0x82BE5EC8
eventVoid idActor::Event_RemoveAttachment(const idEntity* entity) {
    Services().RemoveEntityAttachment(*this, entity);
    return {};
}

// EA 0x82BE5F08
eventFloat idActor::Event_WeaponBurstMode(const int slot) const {
    idWeapon* weapon = slot >= 0 && slot < EQUIP_MAX
        ? Services().CastWeapon(equipped[slot]) : nullptr;
    return eventFloat(weapon == nullptr
        ? 3.0f
        : static_cast<float>(Services().GetWeaponBurstMode(weapon)));
}

// EA 0x82BE5F90
eventVoid idActor::AnimEvent_StartRagdoll(const idMD6Anim*,
        const int velocityTime, const int slomoStartTime,
        const int slomoEndTime) {
    idRagdollInfo info = ragdollInfo;
    info.velocityTime = velocityTime;
    info.slomoStart = slomoStartTime * 0.001f;
    info.slomoEnd = slomoEndTime * 0.001f;
    StartRagdoll(info);
    return {};
}

// EA 0x82BE6040
eventVoid idActor::AnimEvent_HideAttachment(
        const idMD6Anim*, const char* slot) {
    return AttachmentEvent(slot, ACTOR_ATTACHMENT_HIDE,
        "AnimEvent_HideAttachment");
}

// EA 0x82BE6130
eventVoid idActor::AnimEvent_ShowAttachment(
        const idMD6Anim*, const char* slot) {
    return AttachmentEvent(slot, ACTOR_ATTACHMENT_SHOW,
        "AnimEvent_ShowAttachment");
}

// EA 0x82BE6218
eventVoid idActor::AnimEvent_DetachAttachment(
        const idMD6Anim*, const char* slot) {
    return AttachmentEvent(slot, ACTOR_ATTACHMENT_DETACH,
        "AnimEvent_DetachAttachment");
}

// EA 0x82BE6300
eventVoid idActor::AnimEvent_ReattachAttachment(
        const idMD6Anim*, const char* slot) {
    return AttachmentEvent(slot, ACTOR_ATTACHMENT_REATTACH,
        "AnimEvent_ReattachAttachment");
}

// EA 0x82BE63E8
eventVoid idActor::AnimEvent_HideModel(
        const idMD6Anim*, const idDeclMD6* model) {
    if (model != nullptr) Services().RemoveModelAttachment(*this, model);
    return {};
}

// EA 0x82BE6428
eventVoid idActor::AnimEvent_ShowModel(const idMD6Anim*,
        const idDeclMD6* model, const char* tag) {
    if (model != nullptr) Services().AddModelAttachment(*this, model, tag);
    return {};
}

// EA 0x82BE6478
eventVoid idActor::AnimEvent_AttachEntity(const idMD6Anim*,
        const char* entityName, const char* tagName) {
    idEntity* entity = Services().FindEntity(entityName);
    if (entity != nullptr) {
        Services().AddEntityAttachment(*this, entity, tagName);
    }
    return {};
}

// EA 0x82BE64D8
eventVoid idActor::AnimEvent_DetachEntity(const idMD6Anim*,
        const char* entityName) {
    idEntity* entity = Services().FindEntity(entityName);
    if (entity != nullptr) {
        Services().RemoveEntityAttachment(*this, entity);
    }
    return {};
}

// EA 0x82BE6540
eventVoid idActor::AnimEvent_DisableTwoLegIKBlend(const idMD6Anim*) {
    Services().SetLegIKEnabled(*this, 0, false);
    Services().SetLegIKEnabled(*this, 1, false);
    Services().BlendTwoLegIK(*this, false, 0);
    return {};
}

// EA 0x82BE65C8
eventVoid idActor::AnimEvent_EnableTwoLegIKBlend(const idMD6Anim*) {
    Services().SetLegIKEnabled(*this, 0, true);
    Services().SetLegIKEnabled(*this, 1, true);
    Services().BlendTwoLegIK(*this, true, 3000);
    return {};
}

// EA 0x82BE6660
eventVoid idActor::AnimEvent_ModifyDamageGroupScale(const idMD6Anim*,
        const char* damageGroupName, const float scale) {
    idDamageGroup* group = GetDamageGroup(damageGroupName);
    if (group != nullptr) group->damageScale = scale;
    return {};
}

// EA 0x82BE66B0
void idActor::SetModel(idRenderModel* model) {
    Services().InitActorModel(*this, model);
}

// EA 0x82BE6770
float idActor::GetDamageForJoint(const idActorJointIndex joint) {
    const idDamageGroup* group = GetDamageGroup(joint);
    if (group == nullptr) return 1.0f;
    return group->locationArmor <= 0.0f
        ? group->damageScale : group->armoredDamageScale;
}

// EA 0x82BE67E0
idEntity* idActor::GetAttachedLoot() const {
    return Services().ResolveEntity(attachedLoot.GetSpawnId());
}

// EA 0x82BE6828
eventVoid idActor::Event_GiveInventoryItem(
        const char* declName, const float count) {
    if (declName != nullptr) {
        const idDeclInventory* decl = Services().FindInventoryDecl(declName);
        if (decl != nullptr) {
            Services().GiveInventoryItem(
                *this, decl, static_cast<int>(count));
        }
    }
    return {};
}

// EA 0x82BE68C8
eventVoid idActor::Event_RemoveInventoryItem(
        const char* declName, const float count) {
    if (declName != nullptr) {
        const idDeclInventory* decl = Services().FindInventoryDecl(declName);
        idInventoryItem* item = decl == nullptr
            ? nullptr : Services().FindInventoryItem(*this, decl);
        if (item != nullptr) {
            Services().DeleteInventoryItem(
                *this, item, static_cast<int>(count));
        }
    }
    return {};
}

// EA 0x82BE6988
bool idActorPhysicsCallbacks::Crush(const int physicsId) {
    return owner != nullptr
        && idActor::Services().ApplyCrushDamage(*owner, physicsId);
}

// EA 0x82BE6A78
void idActor::DeleteSubEntities() {
    Services().DeleteAttachedEntities(*this);
}

// EA 0x82BE6B78
idEntity* idActor::DropItem(idInventoryItem* item, const bool dropToGround,
        const bool deleteOnDrop, const int count, const idVec3& offset,
        const idVec3& velocity) {
    if (item == nullptr) {
        return nullptr;
    }

    const idActorItemInfo itemInfo = Services().GetItemInfo(item);
    if (!itemInfo.dropable) {
        return nullptr;
    }

    idEntity* droppedEntity = nullptr;
    if (dropToGround) {
        idActorDropRequest request;
        request.item = item;
        request.entityDef = itemInfo.entityDef;
        request.offset = offset;
        request.velocity = velocity;
        request.dropToGround = true;
        request.fromAttachment = false;

        droppedEntity = Services().SpawnDroppedEntity(*this, request);
        if (droppedEntity == nullptr) {
            return nullptr;
        }
        if (!Services().PlaceDroppedEntity(*this, droppedEntity, request)) {
            Services().RemoveEntity(droppedEntity);
            Services().PlayDropFailureSound(*this);
            return nullptr;
        }
        Services().ConfigureDroppedEntity(
            *this, droppedEntity, item, IsLootable());
    }

    if (itemInfo.dropSound != nullptr) {
        Services().PlayItemDropSound(*this, itemInfo.dropSound);
    }
    if (itemInfo.dropEventDecl != nullptr) {
        Services().EmitAIEvent(*this, itemInfo.dropEventDecl,
            droppedEntity, 0);
    }
    if (deleteOnDrop) {
        Services().DeleteInventoryItem(*this, item, count);
    }
    return droppedEntity;
}

// EA 0x82BE7580
bool idActor::HasLootableProjectiles() const {
    return Services().HasLootableProjectile(*this);
}

// EA 0x82BE7760
void idActor::SetAttachedLoot(idEntity* object) {
    attachedLoot.SetSpawnId(object == nullptr
        ? 0x1FFF : Services().GetSpawnId(object));
}

// EA 0x82BE77A0
void idActor::SetPain(const painType_t type, const idActorJointIndex joint,
        const idEntity* attacker, const idEntity* inflictor,
        const idJointGroupHandle& jointGroup,
        const damageDirection_t direction,
        const damageIntensity_t intensity,
        const idDeclDamage* damageDecl) {
    actorVolatile.pain.type = type;
    actorVolatile.pain.joint = joint;
    actorVolatile.pain.attacker.SetSpawnId(attacker == nullptr
        ? 0x1FFF : Services().GetSpawnId(attacker));
    actorVolatile.pain.inflictor.SetSpawnId(inflictor == nullptr
        ? 0x1FFF : Services().GetSpawnId(inflictor));
    actorVolatile.pain.jointGroupHandle = jointGroup;
    actorVolatile.pain.direction = direction;
    actorVolatile.pain.intensity = intensity;
    actorVolatile.pain.damageDecl = damageDecl;
}

// EA 0x82BE7838
void idActor::ClearPain() {
    actorVolatile.pain.jointGroupHandle.Invalidate();
    actorVolatile.pain.attacker.Invalidate();
    actorVolatile.pain.inflictor.Invalidate();
    actorVolatile.pain.joint.Invalidate();
    actorVolatile.pain.type = PAIN_NONE;
    actorVolatile.pain.direction = DAMAGEDIR_NONE;
    actorVolatile.pain.intensity = DAMAGEINTENSITY_NONE;
    actorVolatile.pain.damageDecl = nullptr;
}

// EA 0x82BE7870
bool idActor::PlayFootStepEffect(const footStepType_t footstepType) {
    if (footstepType != FOOTSTEP_LAND_NO_GROUND_CHECK
            && !Services().HasGroundContacts(*this)) {
        return false;
    }

    const idDeclAiEvent* eventDecl = Services().GetFootstepEvent(
        *this, footstepType, actorVolatile.walkState,
        actorEditable.bodyState);
    if (eventDecl != nullptr) {
        Services().EmitAIEvent(*this, eventDecl,
            reinterpret_cast<idEntity*>(this), 0);
    }

    const idDeclProjectileImpactEffect* effects = nullptr;
    if (footstepType == FOOTSTEP_LAND
            || footstepType == FOOTSTEP_LAND_NO_GROUND_CHECK) {
        effects = actorConstants.footstepEffectTable_Landing;
    } else if (actorVolatile.walkState == WALKSTATE_SPRINTING) {
        effects = actorConstants.footstepEffectTable_Sprint;
        if (effects == nullptr) {
            effects = actorConstants.footstepEffectTable;
        }
    } else if (actorVolatile.walkState == WALKSTATE_WALKING) {
        if (actorEditable.bodyState == POSTURE_CROUCHED) {
            effects = actorConstants.footstepEffectTable_CrouchWalk;
        }
        if (effects == nullptr) {
            effects = actorConstants.footstepEffectTable_SlowWalk;
        }
        if (effects == nullptr) {
            effects = actorConstants.footstepEffectTable;
        }
    } else if (actorVolatile.walkState == WALKSTATE_RUNNING) {
        effects = actorConstants.footstepEffectTable;
    }

    if (effects == nullptr) {
        effects = Services().GetFootstepEffects(*this, footstepType,
            actorVolatile.walkState, actorEditable.bodyState);
    }
    if (effects == nullptr) {
        return true;
    }

    idActorFootstepContact contact =
        Services().GetFootstepContact(*this, footstepType);
    if (!contact.valid) {
        return true;
    }
    if (Services().GetPhysicsState(*this).waterLevel > 0.0f) {
        contact.surfaceType = 6;
    }
    Services().PlayFootstepImpact(*this, effects, contact, footstepType);
    return true;
}

// EA 0x82BE8228
eventVoid idActor::AnimEvent_LeftFoot(const idMD6Anim*) {
    PlayFootStepEffect(FOOTSTEP_LEFT_FOOT);
    return {};
}

// EA 0x82BE8260
eventVoid idActor::AnimEvent_RightFoot(const idMD6Anim*) {
    PlayFootStepEffect(FOOTSTEP_RIGHT_FOOT);
    return {};
}

// EA 0x82BE8298
eventVoid idActor::AnimEvent_LeftRearFoot(const idMD6Anim*) {
    PlayFootStepEffect(FOOTSTEP_LEFT_REAR_FOOT);
    return {};
}

// EA 0x82BE82D0
eventVoid idActor::AnimEvent_RightRearFoot(const idMD6Anim*) {
    PlayFootStepEffect(FOOTSTEP_RIGHT_REAR_FOOT);
    return {};
}

// EA 0x82BE8910
void StringListAddIfUnique(const idList<idStr, 5>& listToAdd,
        idList<idStr, 5>& addToList) {
    for (int index = 0; index < listToAdd.Num(); ++index) {
        if (addToList.FindIndex(listToAdd[index]) < 0) {
            addToList.Append(listToAdd[index]);
        }
    }
}

// EA 0x82BE8A30
void idActor::Spawn() {
    Services().RegisterActor(*this);
    if (!Services().HasAnimatedModel(*this)) {
        idLibPrint::Warning("Actor '%s' has no animated model", name.c_str());
    }

    Services().SetRadiusDamageJoints(
        *this, actorEditable.radiusDamageJoints);
    actorVolatile.modelInfo.modelAxis = Services().GetPhysicsState(*this).axis;
    Services().InitializeActorAnimation(*this);

    if (!actorConstants.modelInfo.soundJoint.IsEmpty()) {
        const int joint = Services().FindSoundJoint(
            *this, actorConstants.modelInfo.soundJoint.c_str());
        actorVolatile.modelInfo.soundJoint =
            idActorJointIndex(static_cast<short>(joint));
        if (joint < 0) {
            idLibPrint::Warning("Actor '%s' has invalid sound joint '%s'",
                name.c_str(), actorConstants.modelInfo.soundJoint.c_str());
        }
    }
    if (actorConstants.perception.eyeOffset.z == 0.0f
            || actorConstants.perception.crouchedEyeOffset.z == 0.0f) {
        idLibPrint::Warning("Actor '%s' has a zero-height eye offset",
            name.c_str());
    }
    Services().SetHighQualityShadows(*this);

    for (int index = 0; index < startingInventory.Num(); ++index) {
        const idInventoryAttachmentDef& attachment = startingInventory[index];
        if (attachment.inventoryDecl == nullptr) {
            continue;
        }
        const idActorItemInfo info =
            Services().GetDeclInfo(attachment.inventoryDecl);
        idInventoryItem* item = info.stackable
            ? Services().FindInventoryItem(*this, attachment.inventoryDecl)
            : nullptr;
        if (item == nullptr) {
            item = Services().GiveInventoryItem(
                *this, attachment.inventoryDecl, attachment.count);
        }
        if (item == nullptr) {
            continue;
        }

        if (attachment.startSlot == idInventoryAttachmentDef::EQUIPPED
                && info.equipSlot != EQUIP_NONE
                && GetEquipped(info.equipSlot) == nullptr) {
            EquipItem(item, EQUIP_NONE);
        } else if (attachment.startSlot
                == idInventoryAttachmentDef::HOLSTERED) {
            HolsterItem(item, attachment.showHolstered);
        }
        Services().SetInventoryFlags(
            item, attachment.forSale, attachment.lootable);
        if (info.initiallyHidden) {
            HideAttachment(item);
        }
    }

    for (int index = 0; index < entityAttachments.Num(); ++index) {
        Services().AddDeclEntityAttachment(*this, entityAttachments[index]);
    }
    Services().InitDeferredVisibility(
        *this, Services().GetPhysicsState(*this).origin);
    Services().AddBehaviorAnimations(takedownTypes.stealthSWFWD);
    Services().AddBehaviorAnimations(takedownTypes.stealthSWREV);
    Services().AddBehaviorAnimations(takedownTypes.stealthDWFWD);
    Services().AddBehaviorAnimations(takedownTypes.stealthDWREV);
    Services().AddBehaviorAnimations(takedownTypes.counterSWFWD);
    Services().AddBehaviorAnimations(takedownTypes.counterSWREV);
    Services().AddBehaviorAnimations(takedownTypes.counterDWFWD);
    Services().AddBehaviorAnimations(takedownTypes.counterDWREV);
    Services().AddBehaviorAnimations(takedownTypes.AITakedowns);
    Services().PostActorSpawn(*this);

    // EA 0x82BE909C: the retail cleanup thunk unwound the temporary
    // behavior-animation list; C++ automatic storage performs that cleanup.
}

// EA 0x82BE90F0
bool idActor::IsLootable() const {
    if (Services().IsMultiplayer() && Services().IsCoopChallenge()
            && !Services().AllowLootingInCoop()) {
        return false;
    }
    return lootable || dropRandomLoot;
}

// EA 0x82BE91A0
void idActor::DropAttachment(idInventoryItem* item) {
    if (item == nullptr) {
        return;
    }
    const idActorItemInfo itemInfo = Services().GetItemInfo(item);
    if (!itemInfo.dropable || Services().IsItemAlreadyDropped(item)
            || !Services().HasItemAttachment(*this, item)) {
        return;
    }

    idActorDropRequest request;
    request.item = item;
    request.entityDef = itemInfo.entityDef;
    request.dropToGround = true;
    request.fromAttachment = true;
    idEntity* droppedEntity = Services().SpawnDroppedEntity(*this, request);
    if (droppedEntity != nullptr) {
        if (Services().PlaceDroppedEntity(*this, droppedEntity, request)) {
            Services().ConfigureDroppedEntity(
                *this, droppedEntity, item, IsLootable());
            if (!droppedItem1.IsValid()) {
                droppedItem1.SetSpawnId(Services().GetSpawnId(droppedEntity));
            } else if (!droppedItem2.IsValid()) {
                droppedItem2.SetSpawnId(Services().GetSpawnId(droppedEntity));
            }
        } else {
            Services().RemoveEntity(droppedEntity);
            droppedEntity = nullptr;
        }
    }

    Services().SetItemAlreadyDropped(item, true);
    equipSlot_t equippedSlot = EQUIP_NONE;
    for (int slot = 0; slot < EQUIP_MAX; ++slot) {
        if (equipped[slot] == item) {
            equippedSlot = static_cast<equipSlot_t>(slot);
            break;
        }
    }
    if (equippedSlot != EQUIP_NONE) {
        if (droppedEntity != nullptr) {
            Services().ScheduleDroppedItemDelete(*this, equippedSlot);
            return;
        }
        UnequipItem(item);
    }
    Services().DeleteInventoryItem(*this, item, 1);
}

// EA 0x82BE9AF0
void idActor::SetRelationshipList(
        const idRelationshipList& relationships) {
    faction.relationships = relationships;
}

// EA 0x82BE9C28
idActor::~idActor() {
    Services().StopAllSounds(*this);
    Services().FreeInventory(*this);
    Services().FreeAttachments(*this);
}

// EA 0x82BEA038
idActor::idActor()
    : name(),
      entityNumber(-1),
      looted(false),
      droppedItem1(),
      droppedItem2(),
      attachedLoot(),
      spawnPending(false),
      ragdollInfo(),
      actorConstants(),
      actorEditable(),
      npcName(),
      faction(),
      tempFaction(nullptr),
      tempFactionTime(0),
      factionType(FACTIONTYPE_NONE),
      weaponProficiency(1.0f),
      armorProficiency(1.0f),
      shieldBleedThrough(0.0f),
      mass(185.0f),
      lootable(true),
      dropRandomLoot(true),
      startingInventory(0),
      entityAttachments(0),
      disassembleLoot(),
      takedownTypes(),
      actorVolatile(),
      walkIKDecl(nullptr),
      equipped{},
      damageGroup(-1),
      touching(0) {
    actorVolatile.modelInfo.soundJoint.Invalidate();
    actorVolatile.modelInfo.modelAxis = idMat3(1.0f);
    actorVolatile.modelInfo.eyeAxis = idMat3(1.0f);
    actorVolatile.modelInfo.eyePos = idVec3(0.0f, 0.0f, 0.0f);
    actorVolatile.aasPosition.valid = false;
    actorVolatile.aasPosition.areaNum = 0;
    actorVolatile.aasPosition.origin = idVec3(0.0f, 0.0f, 0.0f);
    actorVolatile.aasPosition.validOrigin = idVec3(0.0f, 0.0f, 0.0f);
    actorVolatile.aasPosition.aas = nullptr;
    ClearPain();
}
