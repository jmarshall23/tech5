#include "game/entities/entity.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {
idEntityServices defaultEntityServices;
idEntityServices* entityServices = &defaultEntityServices;

float Clamp(const float value, const float minimum, const float maximum) {
    return std::max(minimum, std::min(maximum, value));
}

idVec3 TransformPoint(const idVec3& point, const idVec3& origin,
        const idMat3& axis) {
    return origin + axis[0] * point.x + axis[1] * point.y
        + axis[2] * point.z;
}

idVec3 TransformVector(const idVec3& vector, const idMat3& axis) {
    return axis[0] * vector.x + axis[1] * vector.y + axis[2] * vector.z;
}

idVec3 InverseTransformVector(const idVec3& vector, const idMat3& axis) {
    return idVec3(vector.Dot(axis[0]), vector.Dot(axis[1]),
        vector.Dot(axis[2]));
}

bool BoundsTouch(const idBounds& left, const idBounds& right) {
    return left[0].x <= right[1].x && left[1].x >= right[0].x
        && left[0].y <= right[1].y && left[1].y >= right[0].y
        && left[0].z <= right[1].z && left[1].z >= right[0].z;
}

float NormalizeAngle180(float angle) {
    while (angle > 180.0f) angle -= 360.0f;
    while (angle < -180.0f) angle += 360.0f;
    return angle;
}
} // namespace

int idEntityServices::GetGameMilliseconds() const { return 0; }
int idEntityServices::GetGameMillisecondsPerFrame() const { return 16; }
float idEntityServices::RandomFloat(const float maximum) {
    return maximum * 0.5f;
}
bool idEntityServices::IsEntityInPlayerPVS(const idEntity&) const { return true; }
bool idEntityServices::IsEntityNearPlayer(const idEntity&, float) const {
    return true;
}
bool idEntityServices::UsesRelaxedChatter(const idEntity&) const { return false; }
idEntity* idEntityServices::FindEntity(const char*) const { return nullptr; }
bool idEntityServices::IsEntityValid(const idEntity* entity) const {
    return entity != nullptr;
}
bool idEntityServices::IsSpecificClass(const idEntity& entity,
        const char* requested) const {
    return requested != nullptr
        && std::strcmp(entity.className.c_str(), requested) == 0;
}
bool idEntityServices::HasScriptFunction(const idEntity&, const char*) const {
    return false;
}
float idEntityServices::GetScriptFloat(const idEntity&, const char*) const {
    return 0.0f;
}
bool idEntityServices::GetScriptBool(const idEntity&, const char*) const {
    return false;
}
const char* idEntityServices::GetScriptString(const idEntity&,
        const char*) const { return ""; }
void idEntityServices::SetScriptType(idEntity&, const char*) {}
void idEntityServices::ConstructScriptObject(idEntity&) {}
void idEntityServices::DeconstructScriptObject(idEntity&) {}
void idEntityServices::ExecuteThread(idEntity&, idThread*) {}
void idEntityServices::CallScriptFunction(idEntity&, const char*) {}
void idEntityServices::WaitThreadFrame(idEntity&) {}
void idEntityServices::WaitThreadSeconds(idEntity&, float) {}
void idEntityServices::SignalThread(idEntity&, idThread*, const function_t*) {}
idPresentable* idEntityServices::AllocatePresentable(idEntity&,
        idRenderModel*) { return nullptr; }
void idEntityServices::FreePresentable(idPresentable*) {}
idRenderModel* idEntityServices::ResolveRenderModel(const char*) { return nullptr; }
void idEntityServices::ReleaseRenderModel(idRenderModel*) {}
const idMaterial* idEntityServices::GetRenderModelMaterial(
        const idRenderModel*) const { return nullptr; }
void idEntityServices::UpdatePresentableTransform(idEntity&,
        idPresentable*, const idVec3&, const idMat3&) {}
void idEntityServices::SetPresentableColor(idEntity&, const idVec4&) {}
void idEntityServices::SetPresentableScale(idEntity&, const idVec3&) {}
void idEntityServices::SetPresentableHidden(idEntity&, bool) {}
void idEntityServices::SetPresentableNoShadows(idEntity&, bool) {}
void idEntityServices::SetPresentablePrivateLightOnly(idEntity&, bool) {}
void idEntityServices::SetPresentableSkin(idEntity&, const char*) {}
void idEntityServices::SetPresentableHighlight(idEntity&, int) {}
void idEntityServices::ProjectOverlay(idEntity&, const idVec3&,
        const idVec3&, float, const char*) {}
void idEntityServices::UpdateVisuals(idEntity&) {}
void idEntityServices::UpdateDeferredVisuals(idEntity&) {}
void idEntityServices::UpdateFX(idEntity&) {}
void idEntityServices::UpdateSound(idEntity&) {}
void idEntityServices::UpdatePVSAreas(idEntity&, const idBounds&,
        int*, int& count) { count = 0; }
idPhysics* idEntityServices::AllocateDefaultPhysics(idEntity&) { return nullptr; }
void idEntityServices::ReleaseDefaultPhysics(idPhysics*) {}
idClipModel* idEntityServices::CreateMoveableClipModel(idEntity&, bool,
        float) { return nullptr; }
void idEntityServices::ReleaseClipModel(idClipModel*) {}
bool idEntityServices::EvaluatePhysics(idEntity&, idPhysics*, int,
        bool) { return false; }
void idEntityServices::ActivatePhysics(idEntity&, idPhysics*, int) {}
void idEntityServices::DeactivatePhysics(idEntity&, idPhysics*, int) {}
void idEntityServices::ApplyImpulse(idEntity&, idPhysics*, int, int,
        const idVec3&, const idVec3&) {}
void idEntityServices::ApplyForce(idEntity&, idPhysics*, int, int,
        const idVec3&, const idVec3&) {}
int idEntityServices::GetPhysicsContents(const idEntity& entity,
        const idPhysics*) const { return entity.contents; }
int idEntityServices::GetPhysicsClipMask(const idEntity& entity,
        const idPhysics*) const { return entity.clipMask; }
void idEntityServices::SetPhysicsContents(idEntity& entity, idPhysics*,
        const int value) { entity.contents = value; }
void idEntityServices::SetPhysicsClipMask(idEntity& entity, idPhysics*,
        const int value) { entity.clipMask = value; }
idBounds idEntityServices::GetPhysicsBounds(const idEntity& entity,
        const idPhysics*) const { return entity.bounds; }
void idEntityServices::OnEntityCollide(idEntity&, int, trace_t*,
        const idVec3&) {}
void idEntityServices::OnEntityContact(idEntity&, int, contactInfo_t*) {}
bool idEntityServices::OnEntityCrush(idEntity&, int) { return false; }
void idEntityServices::OnEntityDamage(idEntity&, int, int,
        const idDeclDamage*) {}
void idEntityServices::OnWaterEffects(idEntity&, int, int, int, int) {}
idSoundEmitter* idEntityServices::AllocateSoundEmitter(idEntity&) {
    return nullptr;
}
void idEntityServices::FreeSoundEmitter(idSoundEmitter*, bool) {}
int idEntityServices::StartSound(idEntity&, idSoundEmitter*, int,
        const idSoundShader*, const idEntitySoundParms&, int) { return 0; }
void idEntityServices::StopSound(idEntity&, idSoundEmitter*, int, bool) {}
void idEntityServices::ModifySound(idEntity&, idSoundEmitter*, int,
        const idSoundShader*, const idEntitySoundParms&) {}
void idEntityServices::FadeSound(idEntity&, idSoundEmitter*, int,
        float, float, bool) {}
void idEntityServices::SetSoundVolume(idEntity&, idSoundEmitter*, int,
        float) {}
void idEntityServices::SetSoundPitch(idEntity&, idSoundEmitter*, int,
        float) {}
void idEntityServices::SetVolumeAdjustment(idEntity&, idSoundEmitter*,
        float) {}
void idEntityServices::ActivateEntity(idEntity& target,
        idEntity* activator) { target.Activate(activator); }
void idEntityServices::NotifyMakeActivatable(idEntity&, bool) {}
void idEntityServices::NotifyProgressionOwner(idEntity&, idEntity*) {}
void idEntityServices::RegisterEntityName(idEntity&, const char*,
        const char*) {}
void idEntityServices::QueueRemove(idEntity&) {}
void idEntityServices::TouchTriggers(idEntity&,
        idList<idEntity*, 5>&) {}
bool idEntityServices::EntitiesTouch(const idEntity& left,
        const idEntity& right) const {
    idBounds leftWorld;
    idBounds rightWorld;
    leftWorld.FromTransformedBounds(left.bounds, left.origin, left.axis);
    rightWorld.FromTransformedBounds(right.bounds, right.origin, right.axis);
    return BoundsTouch(leftWorld, rightWorld);
}
void idEntityServices::OnTriggerTouch(idEntity&, idEntity&) {}
void idEntityServices::OnTriggerUntouch(idEntity&, idEntity&) {}
void idEntityServices::ShowEditingDialog(idEntity&) {}
void idEntityServices::UpdateEditingDialog(idEntity&) {}
void idEntityServices::SerializeEntity(idEntity&, idSerializer*) {}
idEntityInterface* idEntityServices::CreateEntityInterface(idEntity&,
        idGame*) { return nullptr; }
const idDeclVoiceOver* idEntityServices::GetLocationVoiceOver(
        const idEntity&, const idAI2*) const { return nullptr; }
const idSoundShader* idEntityServices::GetLocationSound(
        const idEntity&, const idAI2*) const { return nullptr; }
void idEntityServices::ForceVoiceOver(idEntity&, const idMD6Anim*,
        const char*, float) {}
void idEntityServices::PlayVoiceOver(idEntity&, const idDeclVoiceOver*,
        int, const char*) {}
void idEntityServices::ReportError(const idEntity&, const char*) {}
void idEntityServices::ReleaseRuntime(idEntity&) {}

void idEntity::SetServices(idEntityServices* const services) {
    entityServices = services == nullptr ? &defaultEntityServices : services;
}

idEntityServices& idEntity::Services() { return *entityServices; }

idEntityPhysicsCallbacks::idEntityPhysicsCallbacks(idEntity* const entity)
    : owner(entity) {}

// Retail: 0x82C38E90 ?Collide@idEntityPhysicsCallbacks@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
int idEntityPhysicsCallbacks::Collide(const int body, trace_t* const trace,
        const idVec3& velocity) {
    if (owner == nullptr) return ENTITY_COLLIDE_NONE;
    idEntity::Services().OnEntityCollide(*owner, body, trace, velocity);
    return ENTITY_COLLIDE;
}

// Retail: 0x82C38EA8 ?Contact@idEntityPhysicsCallbacks@@UAA?AW4collide_t@@HAAUcontactInfo_t@@@Z
int idEntityPhysicsCallbacks::Contact(const int body,
        contactInfo_t* const contact) {
    if (owner == nullptr) return ENTITY_COLLIDE_NONE;
    idEntity::Services().OnEntityContact(*owner, body, contact);
    return ENTITY_COLLIDE;
}

// Retail: 0x82C38EC0 ?ApplyImpulse@idEntityPhysicsCallbacks@@UAAXHHABVidVec3@@0@Z
void idEntityPhysicsCallbacks::ApplyImpulse(const int id, const int body,
        const idVec3& point, const idVec3& impulse) {
    if (owner != nullptr) owner->ApplyImpulse(id, body, point, impulse);
}

// Retail: 0x82C38ED8 ?ApplyForce@idEntityPhysicsCallbacks@@UAAXHHABVidVec3@@0@Z
void idEntityPhysicsCallbacks::ApplyForce(const int id, const int body,
        const idVec3& point, const idVec3& force) {
    if (owner != nullptr) owner->ApplyForce(id, body, point, force);
}

// Retail: 0x82C38EF0 ?Crush@idEntityPhysicsCallbacks@@UAA_NH@Z
bool idEntityPhysicsCallbacks::Crush(const int body) {
    return owner != nullptr && owner->Crush(body);
}

// Retail: 0x82C38F08 ?ApplyDamage@idEntityPhysicsCallbacks@@UAAXHHPBVidDeclDamage@@@Z
void idEntityPhysicsCallbacks::ApplyDamage(const int inflictor,
        const int attacker, const idDeclDamage* const damage) {
    if (owner != nullptr) idEntity::Services().OnEntityDamage(*owner,
        inflictor, attacker, damage);
}

// Retail: 0x82C38F20 ?ActivatePhysics@idEntityPhysicsCallbacks@@UAAXH@Z
void idEntityPhysicsCallbacks::ActivatePhysics(const int flags) {
    if (owner != nullptr) owner->ActivatePhysics(flags);
}

// Retail: 0x82C38F38 ?DeactivatePhysics@idEntityPhysicsCallbacks@@UAAXH@Z
void idEntityPhysicsCallbacks::DeactivatePhysics(const int flags) {
    if (owner != nullptr) owner->DeactivatePhysics(flags);
}

// Retail: 0x82C38F50 ?ApplyWaterEffects@idEntityPhysicsCallbacks@@UAAXHH@Z
void idEntityPhysicsCallbacks::ApplyWaterEffects(const int body,
        const int waterBody) {
    if (owner != nullptr) idEntity::Services().OnWaterEffects(*owner,
        body, waterBody, 0, 0);
}

// Retail: 0x82C38F68 ?ApplyWaterSplashEffects@idEntityPhysicsCallbacks@@UAAXHHW4surfTypes_t@@W4splashState_t@idPhysicsCallbacks@@@Z
void idEntityPhysicsCallbacks::ApplyWaterSplashEffects(const int body,
        const int waterBody, const int surfaceType, const int splashState) {
    if (owner != nullptr) idEntity::Services().OnWaterEffects(*owner,
        body, waterBody, surfaceType, splashState);
}

// Retail: 0x82C38F80 ?CleanRenderParms@idEntity@@QAAXXZ
void idEntity::CleanRenderParms() {
    color = idVec4(1.0f, 1.0f, 1.0f, 1.0f);
    scale.Set(1.0f, 1.0f, 1.0f);
    noShadows = false;
    privateLightOnly = false;
    highlightColor = 0;
}

// Retail: 0x82C38FB8 ?UpdatePVSAreas@idEntity@@QAAXABVidBounds@@@Z
void idEntity::UpdatePVSAreas(const idBounds& worldBounds) {
    numPVSAreas = 0;
    Services().UpdatePVSAreas(*this, worldBounds, pvsAreas, numPVSAreas);
    numPVSAreas = std::max(0, std::min(4, numPVSAreas));
}

// Retail: 0x82C39000 ?GetForceDormant@idEntity@@QBA_NXZ
bool idEntity::GetForceDormant() const { return dormancy.forceDormant; }

// Retail: 0x82C39060 ?GetColor@idEntity@@UBAXAAVidVec3@@@Z
void idEntity::GetColor(idVec3& result) const {
    result.Set(color.x, color.y, color.z);
}

// Retail: 0x82C390A8 ?GetColor@idEntity@@UBAXAAVidColor@@@Z
void idEntity::GetColor(idColor& result) const {
    result.Set(color.x, color.y, color.z, color.w);
}

// Retail: 0x82C390F0 ?GetColor@idEntity@@UBAXAAVidVec4@@@Z
void idEntity::GetColor(idVec4& result) const { result = color; }

// Retail: 0x82C39138 ?GetRenderModelMaterial@idEntity@@QBAPBVidMaterial@@XZ
const idMaterial* idEntity::GetRenderModelMaterial() const {
    return renderModel != nullptr
        ? Services().GetRenderModelMaterial(renderModel) : nullptr;
}

// Retail: 0x82C39188 ?Get_idCombatStage_useRelaxedChatterVO@@YAHPAX@Z
int Get_idCombatStage_useRelaxedChatterVO(void* const entity) {
    if (entity == nullptr) return 0;
    return idEntity::Services().UsesRelaxedChatter(
        *reinterpret_cast<idEntity*>(entity)) ? 1 : 0;
}

// Retail: 0x82C39198 ?GetScale@idEntity@@UBAXAAVidVec3@@@Z
void idEntity::GetScale(idVec3& result) const { result = scale; }

// Retail: 0x82C391E0 ?SetScale@idEntity@@UAAXABVidVec3@@@Z
void idEntity::SetScale(const idVec3& newScale) {
    scale = newScale;
    Services().SetPresentableScale(*this, scale);
    UpdateVisuals();
}

// Retail: 0x82C39228 ?IsBound@idEntity@@QBA_NXZ
bool idEntity::IsBound() const { return bindMaster != nullptr; }

// Retail: 0x82C39238 ?IsBoundTo@idEntity@@QBA_NPBV1@@Z
bool idEntity::IsBoundTo(const idEntity* master) const {
    for (const idEntity* current = bindMaster; current != nullptr;
            current = current->bindMaster) {
        if (current == master) return true;
        if (current == this) break;
    }
    return false;
}

// Retail: 0x82C39268 ?IsBoundOriented@idEntity@@QBA_NXZ
bool idEntity::IsBoundOriented() const {
    return bindMaster != nullptr && bindOrientated;
}

// Retail: 0x82C39288 ?GetBindMaster@idEntity@@QBAPAV1@XZ
idEntity* idEntity::GetBindMaster() const { return bindMaster; }

// Retail: 0x82C39290 ?GetTeamMaster@idEntity@@QBAPAV1@XZ
idEntity* idEntity::GetTeamMaster() const { return teamMaster; }

// Retail: 0x82C39298 ?GetNextTeamEntity@idEntity@@QBAPAV1@XZ
idEntity* idEntity::GetNextTeamEntity() const { return teamChain; }

// Retail: 0x82C392A0 ?QuitTeam@idEntity@@QAAXXZ
void idEntity::QuitTeam() {
    if (teamMaster == nullptr) return;
    idEntity* previous = teamMaster;
    while (previous != nullptr && previous->teamChain != this) {
        previous = previous->teamChain;
    }
    if (previous != nullptr) previous->teamChain = teamChain;
    if (teamMaster == this) {
        idEntity* const newMaster = teamChain;
        for (idEntity* member = newMaster; member != nullptr;
                member = member->teamChain) member->teamMaster = newMaster;
    }
    teamMaster = nullptr;
    teamChain = nullptr;
}

// Retail: 0x82C39340 ?RestorePhysics@idEntity@@QAAXPAVidPhysics@@@Z
void idEntity::RestorePhysics(idPhysics* const restoredPhysics) {
    SetPhysics(restoredPhysics);
}

// Retail: 0x82C39348 ?GetPhysics@idEntity@@QBAPAVidPhysics@@XZ
idPhysics* idEntity::GetPhysics() const { return physics; }

// Retail: 0x82C39350 ?SetAngles@idEntity@@QAAXABVidAngles@@@Z
void idEntity::SetAngles(const idAngles& angles) { SetAxis(angles.ToMat3()); }

// Retail: 0x82C393A0 ?ApplyImpulse@idEntity@@UAAXHHABVidVec3@@0@Z
void idEntity::ApplyImpulse(const int id, const int body,
        const idVec3& point, const idVec3& impulse) {
    Services().ApplyImpulse(*this, physics, id, body, point, impulse);
}

// Retail: 0x82C393C0 ?ApplyForce@idEntity@@UAAXHHABVidVec3@@0@Z
void idEntity::ApplyForce(const int id, const int body,
        const idVec3& point, const idVec3& force) {
    Services().ApplyForce(*this, physics, id, body, point, force);
}

// Retail: 0x82C393E0 ?InventoryRemoved@idEntity@@UAAXPAVidInventoryItem@@@Z
void idEntity::InventoryRemoved(idInventoryItem*) {}

// Retail: 0x82C39428 ?ExecuteThread@idEntity@@UAAXPAVidThread@@@Z
void idEntity::ExecuteThread(idThread* const thread) {
    Services().ExecuteThread(*this, thread);
}

// Retail: 0x82C39430 ?IsCurrentlyUsable@idEntity@@UBA_NPBV1@@Z
bool idEntity::IsCurrentlyUsable(const idEntity*) const {
    return flags.isActivatable && !flags.hidden && !removed;
}

// Retail: 0x82C39440 ?ModifyCrosshairInfo@idEntity@@UBA_NPBV1@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
bool idEntity::ModifyCrosshairInfo(const idEntity*, const void*,
        const int usableState, void*) const {
    return usableState != 0 && flags.isActivatable;
}

// Retail: 0x82C39518 ?SetIsActivatable@idEntity@@QAAX_N@Z
void idEntity::SetIsActivatable(const bool activatable) {
    if (flags.isActivatable == activatable) return;
    flags.isActivatable = activatable;
    Services().NotifyMakeActivatable(*this, activatable);
}

// Retail: 0x82C39538 ?ShowEditingDialog@idEntity@@UAAXXZ
void idEntity::ShowEditingDialog() { Services().ShowEditingDialog(*this); }

// Retail: 0x82C39558 ?UpdateEditingDialog@idEntity@@UAAXXZ
void idEntity::UpdateEditingDialog() {
    Services().UpdateEditingDialog(*this);
}

// Retail: 0x82C39578 ?Event_FindEntity@idEntity@@AAA?AVeventEntity@@PBD@Z
idEntity* idEntity::Event_FindEntity(const char* entityName) const {
    return Services().FindEntity(entityName);
}

// Retail: 0x82C395D0 ?Event_TargetsReady@idEntity@@AAA?AVeventBool@@XZ
bool idEntity::Event_TargetsReady() const {
    for (int index = 0; index < targets.Num(); ++index) {
        if (!Services().IsEntityValid(targets[index])) return false;
    }
    return true;
}

// Retail: 0x82C39608 ?Event_IsHidden@idEntity@@AAA?AVeventInt@@XZ
int idEntity::Event_IsHidden() const { return flags.hidden ? 1 : 0; }

// Retail: 0x82C39640 ?Event_GetWorldOrigin@idEntity@@AAA?AVeventVector@@XZ
idVec3 idEntity::Event_GetWorldOrigin() const { return origin; }

// Retail: 0x82C39690 ?Event_GetLinearVelocity@idEntity@@AAA?AVeventVector@@XZ
idVec3 idEntity::Event_GetLinearVelocity() const { return linearVelocity; }

// Retail: 0x82C396E8 ?Event_GetAngularVelocity@idEntity@@AAA?AVeventVector@@XZ
idVec3 idEntity::Event_GetAngularVelocity() const { return angularVelocity; }

// Retail: 0x82C39740 ?Event_HasFunction@idEntity@@AAA?AVeventInt@@PBD@Z
int idEntity::Event_HasFunction(const char* functionName) const {
    return Services().HasScriptFunction(*this, functionName) ? 1 : 0;
}

// Retail: 0x82C39790 ?Event_GetScriptObject@idEntity@@AAA?AVeventString@@XZ
const char* idEntity::Event_GetScriptObject() const {
    return scriptObjectType.c_str();
}

// Retail: 0x82C397D0 ?Event_GetClass@idEntity@@AAA?AVeventString@@XZ
const char* idEntity::Event_GetClass() const { return className.c_str(); }

// Retail: 0x82C39810 ?Event_IsSpecificClass@idEntity@@AAA?AVeventBool@@PBD@Z
bool idEntity::Event_IsSpecificClass(const char* requested) const {
    return Services().IsSpecificClass(*this, requested);
}

// Retail: 0x82C39870 ?Event_GetContents@idEntity@@AAA?AVeventInt@@XZ
int idEntity::Event_GetContents() const {
    return Services().GetPhysicsContents(*this, physics);
}

// Retail: 0x82C398D0 ?Event_GetClipMask@idEntity@@AAA?AVeventInt@@XZ
int idEntity::Event_GetClipMask() const {
    return Services().GetPhysicsClipMask(*this, physics);
}

// Retail: 0x82C39930 ?SetTeam@idEntity@@QAAXW4gameTeam_t@@@Z
void idEntity::SetTeam(const int newTeam) { team = newTeam; }

// Retail: 0x82C39948 ?SetClipReplicationFlags@idEntity@@IAAX_N0@Z
void idEntity::SetClipReplicationFlags(const bool dynamicClip,
        const bool dynamicAxis) {
    flags.dynamicClipReplication = dynamicClip;
    flags.dynamicClipReplicationAxis = dynamicClip && dynamicAxis;
}

// Retail: 0x82C39960 ?IsFirstPostSerializeRead@idEntity@@QAA_NXZ
bool idEntity::IsFirstPostSerializeRead() {
    const bool result = firstPostSerializeRead;
    firstPostSerializeRead = false;
    return result;
}

// Retail: 0x82C39C70 ?GetName@idEntityPhysicsCallbacks@@UAAPBDXZ
const char* idEntityPhysicsCallbacks::GetName() const {
    return owner != nullptr ? owner->name.c_str() : "<null entity>";
}

// Retail: 0x82C39D38 ?GetEntityRenderLight@idGameLocal@@UAAPAVidRenderLight@@PAVidEntity@@@Z
idRenderLight* GetEntityRenderLightForEntity(idEntity*) { return nullptr; }

// Retail: 0x82C39DE0 ?SpawnTransform@idEntity@@QAAXABVidVec3@@ABVidMat3@@@Z
void idEntity::SpawnTransform(const idVec3& newOrigin,
        const idMat3& newAxis) {
    spawnPosition = newOrigin;
    spawnOrientation = newAxis;
    SetOrigin(newOrigin);
    SetAxis(newAxis);
}

// Retail: 0x82C39E70 ?UpdateDormant@idEntity@@QAA_NXZ
bool idEntity::UpdateDormant() {
    if (!flags.canBecomeDormant) return false;
    const int currentTime = Services().GetGameMilliseconds();
    const bool visible = Services().IsEntityInPlayerPVS(*this)
        || Services().IsEntityNearPlayer(*this, dormancy.distance);
    if (visible && !dormancy.forceDormant) {
        dormancy.lastTimeInPlayerPVS = currentTime;
        if (flags.isDormant) LeaveDormancy();
        return false;
    }
    if (!flags.isDormant && (dormancy.forceDormant
            || currentTime >= dormancy.lastTimeInPlayerPVS
                + static_cast<int>(dormancy.delay * 1000.0f))) {
        flags.isDormant = true;
        dormancy.becomeDormantTime = currentTime;
        DormantBegin();
    }
    return flags.isDormant;
}

// Retail: 0x82C3A010 ?InitComponents@idEntity@@QAAXXZ
void idEntity::InitComponents() {
    physicsCallbacks.owner = this;
    firstPostSerializeRead = true;
}

// Retail: 0x82C3A0A0 ?ShouldEnterDormancy@idEntity@@UAA_NXZ
bool idEntity::ShouldEnterDormancy() {
    if (!flags.canBecomeDormant || flags.isDormant) return false;
    if (dormancy.forceDormant) return true;
    const int currentTime = Services().GetGameMilliseconds();
    return !Services().IsEntityInPlayerPVS(*this)
        && !Services().IsEntityNearPlayer(*this, dormancy.distance)
        && currentTime >= dormancy.lastTimeInPlayerPVS
            + static_cast<int>(dormancy.delay * 1000.0f);
}

// Retail: 0x82C3A190 ?ShouldLeaveDormancy@idEntity@@UAA_NXZ
bool idEntity::ShouldLeaveDormancy() {
    return flags.isDormant && !dormancy.forceDormant
        && (Services().IsEntityInPlayerPVS(*this)
            || Services().IsEntityNearPlayer(*this, dormancy.distance));
}

// Retail: 0x82C3A238 ?DormantBegin@idEntity@@UAAXXZ
void idEntity::DormantBegin() { BecomeInactive(~0); }

// Retail: 0x82C3A260 ?DormantEnd@idEntity@@UAAXH@Z
void idEntity::DormantEnd(int) { BecomeActive(1); }

// Retail: 0x82C3A288 ?ForceDormancy@idEntity@@QAAX_NH@Z
void idEntity::ForceDormancy(const bool force,
        const int delayMilliseconds) {
    dormancy.forceDormant = force;
    dormancy.endForceTime = force && delayMilliseconds > 0
        ? Services().GetGameMilliseconds() + delayMilliseconds : 0;
    if (force && !flags.isDormant) {
        flags.isDormant = true;
        DormantBegin();
    } else if (!force && flags.isDormant) {
        LeaveDormancy();
    }
}

// Retail: 0x82C3A340 ?LeaveDormancy@idEntity@@QAAXXZ
void idEntity::LeaveDormancy() {
    if (!flags.isDormant) return;
    const int dormantTime = Services().GetGameMilliseconds()
        - dormancy.becomeDormantTime;
    flags.isDormant = false;
    dormancy.forceDormant = false;
    dormancy.lastTimeInPlayerPVS = Services().GetGameMilliseconds();
    DormantEnd(std::max(0, dormantTime));
}

// Retail: 0x82C3A400 ?BecomeInactive@idEntity@@QAAXH@Z
void idEntity::BecomeInactive(const int flagsToClear) {
    thinkFlags &= ~flagsToClear;
    if (physics != nullptr && (flagsToClear & 1) != 0) {
        Services().DeactivatePhysics(*this, physics, flagsToClear);
    }
}

// Retail: 0x82C3A520 ?IsMegaModel@idEntity@@QBA_NXZ
bool idEntity::IsMegaModel() const { return megaModel; }

// Retail: 0x82C3A570 ?SetPrivateLightOnly@idEntity@@QAAX_N@Z
void idEntity::SetPrivateLightOnly(const bool privateOnly) {
    privateLightOnly = privateOnly;
    Services().SetPresentablePrivateLightOnly(*this, privateOnly);
}

// Retail: 0x82C3A5C0 ?GetCustomMaterial@idEntity@@UBAPBVidMaterial@@XZ
const idMaterial* idEntity::GetCustomMaterial() const {
    return customMaterial;
}

// Retail: 0x82C3A610 ?GetModelTransform@idEntity@@UBAXAAVidVec3@@AAVidMat3@@@Z
void idEntity::GetModelTransform(idVec3& modelOrigin,
        idMat3& modelAxis) const {
    modelOrigin = origin;
    modelAxis = axis;
}

// Retail: 0x82C3A6C8 ?UpdateModelTransform@idEntity@@UAAXXZ
void idEntity::UpdateModelTransform() {
    if (presentable == nullptr) return;
    idVec3 modelOrigin;
    idMat3 modelAxis;
    GetModelTransform(modelOrigin, modelAxis);
    Services().UpdatePresentableTransform(*this, presentable,
        modelOrigin, modelAxis);
}

// Retail: 0x82C3A7A0 ?InitPresentableInternal@idEntity@@QAAXXZ
void idEntity::InitPresentableInternal() {
    if (presentable != nullptr) return;
    if (renderModel == nullptr && !modelName.IsEmpty()) {
        renderModel = Services().ResolveRenderModel(modelName.c_str());
    }
    presentable = AllocPresentable(renderModel);
    if (presentable == nullptr) return;
    Services().SetPresentableColor(*this, color);
    Services().SetPresentableScale(*this, scale);
    Services().SetPresentableHidden(*this, flags.hidden);
    Services().SetPresentableNoShadows(*this, noShadows);
    Services().SetPresentablePrivateLightOnly(*this, privateLightOnly);
    UpdateModelTransform();
}

// Retail: 0x82C3AC58 ?AllocPresentable@idEntity@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
idPresentable* idEntity::AllocPresentable(idRenderModel* const model) {
    return Services().AllocatePresentable(*this, model);
}

// Retail: 0x82C3ACF8 ?FreePresentable@idEntity@@QAAXXZ
void idEntity::FreePresentable() {
    if (presentable != nullptr) Services().FreePresentable(presentable);
    presentable = nullptr;
}

// Retail: 0x82C3AD70 ?GetRenderModelFromPresentable@idEntity@@QBAPAVidRenderModel@@XZ
idRenderModel* idEntity::GetRenderModelFromPresentable() const {
    return renderModel;
}

// Retail: 0x82C3AD90 ?GetSoundTransform@idEntity@@UBAXAAVidVec3@@AAVidMat3@@@Z
void idEntity::GetSoundTransform(idVec3& soundOrigin,
        idMat3& soundAxis) const {
    soundOrigin = origin;
    soundAxis = axis;
    if (bindMaster != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GetMasterPosition(masterOrigin, masterAxis)) {
            soundOrigin = TransformPoint(bindLocalOrigin,
                masterOrigin, masterAxis);
            if (bindOrientated) soundAxis = masterAxis * bindLocalAxis;
        }
    }
}

// Retail: 0x82C3AF70 ?ConvertLocalToWorldTransform@idEntity@@QBAXAAVidVec3@@AAVidMat3@@@Z
void idEntity::ConvertLocalToWorldTransform(idVec3& localOrigin,
        idMat3& localAxis) const {
    localOrigin = TransformPoint(localOrigin, origin, axis);
    localAxis = axis * localAxis;
}

// Retail: 0x82C3B040 ?JoinTeam@idEntity@@QAAXPAV1@@Z
void idEntity::JoinTeam(idEntity* const member) {
    if (member == nullptr || member == this) return;
    QuitTeam();
    idEntity* master = member->teamMaster != nullptr
        ? member->teamMaster : member;
    idEntity* tail = master;
    while (tail->teamChain != nullptr) tail = tail->teamChain;
    tail->teamChain = this;
    teamMaster = master;
    teamChain = nullptr;
}

// Retail: 0x82C3B1A0 ?ReferenceDefaultPhysics@idEntity@@QAAXXZ
void idEntity::ReferenceDefaultPhysics() {
    if (defaultPhysics == nullptr) {
        defaultPhysics = Services().AllocateDefaultPhysics(*this);
    }
    physics = defaultPhysics;
}

// Retail: 0x82C3B4B8 ?InitDefaultPhysics@idEntity@@AAAXABVidVec3@@ABVidMat3@@@Z
void idEntity::InitDefaultPhysics(const idVec3& initialOrigin,
        const idMat3& initialAxis) {
    ReferenceDefaultPhysics();
    origin = initialOrigin;
    axis = initialAxis;
    clipModel = CreateMoveableClipModel(true, 0.0f);
    Services().SetPhysicsContents(*this, physics, contents);
    Services().SetPhysicsClipMask(*this, physics, clipMask);
}

// Retail: 0x82C3BBD4 $LN293
void idEntityDefaultPhysicsCleanup(idClipModel* const model) {
    idEntity::Services().ReleaseClipModel(model);
}

// Retail: 0x82C3BCB0 ?GetDistanceSqrTo@idEntity@@QBAMABVidVec3@@@Z
float idEntity::GetDistanceSqrTo(const idVec3& point) const {
    return (origin - point).LengthSqr();
}

// Retail: 0x82C3BD20 ?CanDisablePhysics@idEntity@@UBA_NPBV1@@Z
bool idEntity::CanDisablePhysics(const idEntity*) const { return true; }

// Retail: 0x82C3BD60 ?ApplyImpulseFromEntity@idEntity@@UAAXPBV1@HABVidVec3@@1@Z
void idEntity::ApplyImpulseFromEntity(const idEntity*, const int body,
        const idVec3& point, const idVec3& impulse) {
    ApplyImpulse(0, body, point, impulse);
}

// Retail: 0x82C3BD88 ?DeactivatePhysics@idEntity@@UAAXH@Z
void idEntity::DeactivatePhysics(const int deactivateFlags) {
    Services().DeactivatePhysics(*this, physics, deactivateFlags);
}

// Retail: 0x82C3BDD0 ?Crush@idEntity@@UAA_NH@Z
bool idEntity::Crush(const int body) {
    return Services().OnEntityCrush(*this, body);
}

// Retail: 0x82C3BEE0 ?CalcDamageImpulse@idEntity@@UBA_NPBV1@0PBVidDeclDamage@@MABVidVec3@@PBUtrace_t@@AAV3@4@Z
bool idEntity::CalcDamageImpulse(const idEntity*, const idEntity*,
        const idDeclDamage* const damage, const float damageScale,
        const idVec3& direction, const trace_t*, idVec3& impulse,
        idVec3& point) const {
    if (damage == nullptr || flags.noKnockback) {
        impulse.Zero();
        point = origin;
        return false;
    }
    idVec3 normalized = direction;
    if (normalized.NormalizeFast() < 0.0001f) normalized = axis[0];
    impulse = normalized * std::max(0.0f, damageScale);
    point = origin;
    return true;
}

// Retail: 0x82C3C010 ?ConstructScriptObject@idEntity@@QAAXXZ
void idEntity::ConstructScriptObject() {
    if (scriptObjectConstructed || scriptObjectType.IsEmpty()) return;
    Services().ConstructScriptObject(*this);
    scriptObjectConstructed = true;
}

// Retail: 0x82C3C188 ?HasSignal@idEntity@@QBA_NW4signalNum_t@@@Z
bool idEntity::HasSignal(const int signal) const {
    for (int index = 0; index < signals.Num(); ++index) {
        if (signals[index].signal == signal) return true;
    }
    return false;
}

// Retail: 0x82C3C1B8 ?ClearSignalThread@idEntity@@QAAXW4signalNum_t@@PAVidThread@@@Z
void idEntity::ClearSignalThread(const int signal, idThread* const thread) {
    for (int index = signals.Num() - 1; index >= 0; --index) {
        if (signals[index].signal == signal
                && (thread == nullptr || signals[index].thread == thread)) {
            signals.RemoveIndex(index);
        }
    }
}

// Retail: 0x82C3C220 ?AddThread@idEntity@@UAAHV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@@Z
int idEntity::AddThread(const int threadHandle) {
    threadHandles.Append(threadHandle);
    return threadHandles.Num() - 1;
}

// Retail: 0x82C3C240 ?RemoveThread@idEntity@@UAAXV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@@Z
void idEntity::RemoveThread(const int threadHandle) {
    for (int index = threadHandles.Num() - 1; index >= 0; --index) {
        if (threadHandles[index] == threadHandle) threadHandles.RemoveIndex(index);
    }
}

// Retail: 0x82C3C258 ?GetThread@idEntity@@UBA?AV?$idHandle@HW4invalidThreadHandle_t@@$0A@@@H@Z
int idEntity::GetThread(const int index) const {
    return index >= 0 && index < threadHandles.Num()
        ? threadHandles[index] : 0;
}

// Retail: 0x82C3C270 ?NumThreads@idEntity@@UBAHXZ
int idEntity::NumThreads() const { return threadHandles.Num(); }

// Retail: 0x82C3C280 ?GetUsableState@idEntity@@UBA?AW4usableState_t@@PBV1@ABVidFocusTrace@@@Z
int idEntity::GetUsableState(const idEntity* user, const void*) const {
    return IsEverUsable(user) && IsCurrentlyUsable(user) ? 3 : 0;
}

// Retail: 0x82C3C408 ?IsCrosshairDisabled@idEntity@@UBA_NPBV1@ABVidFocusTrace@@W4usableState_t@@@Z
bool idEntity::IsCrosshairDisabled(const idEntity*, const void*,
        const int usableState) const {
    return usableState == 1 || flags.hidden || removed;
}

// Retail: 0x82C3C5F0 ?IsCrosshairSubdued@idEntity@@UBA_NPBV1@ABVidFocusTrace@@W4usableState_t@@@Z
bool idEntity::IsCrosshairSubdued(const idEntity*, const void*,
        const int usableState) const {
    return usableState == 0 || !flags.isActivatable;
}

// Retail: 0x82C3C700 ?ClearTargets@idEntity@@QAAXXZ
void idEntity::ClearTargets() { targets.Clear(); }

// Retail: 0x82C3C708 ?IsPusher@idEntity@@UAA_NXZ
bool idEntity::IsPusher() const { return false; }

// Retail: 0x82C3C728 ?Event_GetName@idEntity@@AAA?AVeventString@@XZ
const char* idEntity::Event_GetName() const { return name.c_str(); }

// Retail: 0x82C3C760 ?Event_ActivateTargets@idEntity@@AAA?AVeventVoid@@PAV1@@Z
void idEntity::Event_ActivateTargets(idEntity* activator) {
    ActivateTargets(activator);
}

// Retail: 0x82C3C7A8 ?Event_MakeActivatable@idEntity@@AAA?AVeventVoid@@_N@Z
void idEntity::Event_MakeActivatable(const bool activatable) {
    SetIsActivatable(activatable);
}

// Retail: 0x82C3C800 ?Event_ClearTargets@idEntity@@AAA?AVeventVoid@@XZ
void idEntity::Event_ClearTargets() { ClearTargets(); }

// Retail: 0x82C3C838 ?Event_SetOwner@idEntity@@AAA?AVeventVoid@@PAV1@@Z
void idEntity::Event_SetOwner(idEntity* const newOwner) { owner = newOwner; }

// Retail: 0x82C3C8C0 ?Event_SetProgressionOwner@idEntity@@AAA?AVeventVoid@@PAV1@@Z
void idEntity::Event_SetProgressionOwner(idEntity* const newOwner) {
    progressionEntity = newOwner;
}

// Retail: 0x82C3C8C8 ?Event_NotifyProgressionOwner@idEntity@@AAA?AVeventVoid@@XZ
void idEntity::Event_NotifyProgressionOwner() {
    Services().NotifyProgressionOwner(*this, progressionEntity);
}

// Retail: 0x82C3C908 ?Event_SetModel@idEntity@@AAA?AVeventVoid@@PBD@Z
void idEntity::Event_SetModel(const char* requestedModel) {
    SetModelByName(requestedModel);
}

// Retail: 0x82C3C958 ?Event_SetClipModel@idEntity@@AAA?AVeventVoid@@PBD@Z
void idEntity::Event_SetClipModel(const char* requestedModel) {
    if (clipModel != nullptr) Services().ReleaseClipModel(clipModel);
    modelName = requestedModel == nullptr ? "" : requestedModel;
    clipModel = CreateMoveableClipModel(true, 0.0f);
}

// Retail: 0x82C3CA58 ?Event_SetColorAndAlpha@idEntity@@AAA?AVeventVoid@@MMMM@Z
void idEntity::Event_SetColorAndAlpha(const float red, const float green,
        const float blue, const float alpha) {
    SetColor(red, green, blue, alpha);
}

// Retail: 0x82C3CA98 ?Event_SetColor@idEntity@@AAA?AVeventVoid@@MMM@Z
void idEntity::Event_SetColor(const float red, const float green,
        const float blue) { SetColor(red, green, blue); }

// Retail: 0x82C3CAD8 ?Event_GetColor@idEntity@@AAA?AVeventVector@@XZ
idVec3 idEntity::Event_GetColor() const {
    return idVec3(color.x, color.y, color.z);
}

// Retail: 0x82C3CB30 ?Event_SetAngles@idEntity@@AAA?AVeventVoid@@ABVidAngles@@@Z
void idEntity::Event_SetAngles(const idAngles& newAngles) {
    SetAngles(newAngles);
}

// Retail: 0x82C3CB78 ?Event_GetAngles@idEntity@@AAA?AVeventVector@@XZ
idAngles idEntity::Event_GetAngles() const {
    const float yaw = std::atan2(axis[0].y, axis[0].x) * 57.295779513f;
    const float pitch = std::atan2(-axis[0].z,
        std::sqrt(axis[0].x * axis[0].x + axis[0].y * axis[0].y))
        * 57.295779513f;
    return idAngles(pitch, yaw, 0.0f);
}

// Retail: 0x82C3CBF8 ?Event_GetModelForward@idEntity@@AAA?AVeventVector@@XZ
idVec3 idEntity::Event_GetModelForward() const { return axis[0]; }

// Retail: 0x82C3CC88 ?Event_SetLinearVelocity@idEntity@@AAA?AVeventVoid@@ABVidVec3@@@Z
void idEntity::Event_SetLinearVelocity(const idVec3& velocity) {
    linearVelocity = velocity;
    BecomeActive(1);
}

// Retail: 0x82C3CCD8 ?Event_SetAngularVelocity@idEntity@@AAA?AVeventVoid@@ABVidVec3@@@Z
void idEntity::Event_SetAngularVelocity(const idVec3& velocity) {
    angularVelocity = velocity;
    BecomeActive(1);
}

// Retail: 0x82C3CD28 ?Event_GetSize@idEntity@@AAA?AVeventVector@@XZ
idVec3 idEntity::Event_GetSize() const { return bounds[1] - bounds[0]; }

// Retail: 0x82C3CDB0 ?Event_GetMins@idEntity@@AAA?AVeventVector@@XZ
idVec3 idEntity::Event_GetMins() const { return bounds[0]; }

// Retail: 0x82C3CE00 ?Event_GetMaxs@idEntity@@AAA?AVeventVector@@XZ
idVec3 idEntity::Event_GetMaxs() const { return bounds[1]; }

// Retail: 0x82C3CE58 ?Event_Touches@idEntity@@AAA?AVeventInt@@PAV1@@Z
int idEntity::Event_Touches(idEntity* const other) const {
    return other != nullptr && Services().EntitiesTouch(*this, *other) ? 1 : 0;
}

// Retail: 0x82C3CEF0 ?Event_RestorePosition@idEntity@@AAA?AVeventVoid@@XZ
void idEntity::Event_RestorePosition() { SpawnTransform(spawnPosition,
    spawnOrientation); }

// Retail: 0x82C3CFB0 ?Event_DistanceTo@idEntity@@AAA?AVeventFloat@@PAV1@@Z
float idEntity::Event_DistanceTo(idEntity* const other) const {
    return other != nullptr ? std::sqrt(GetDistanceSqrTo(other->origin))
        : 0.0f;
}

// Retail: 0x82C3D0B8 ?Event_DistanceToPoint@idEntity@@AAA?AVeventFloat@@ABVidVec3@@@Z
float idEntity::Event_DistanceToPoint(const idVec3& point) const {
    return std::sqrt(GetDistanceSqrTo(point));
}

// Retail: 0x82C3D198 ?Event_WaitFrame@idEntity@@AAA?AVeventVoid@@XZ
void idEntity::Event_WaitFrame() { Services().WaitThreadFrame(*this); }

// Retail: 0x82C3D1E8 ?Event_Wait@idEntity@@AAA?AVeventVoid@@M@Z
void idEntity::Event_Wait(const float seconds) {
    Services().WaitThreadSeconds(*this, seconds);
}

// Retail: 0x82C3D240 ?Event_CallFunction@idEntity@@AAA?AVeventVoid@@PBD@Z
void idEntity::Event_CallFunction(const char* functionName) {
    if (Services().HasScriptFunction(*this, functionName)) {
        Services().CallScriptFunction(*this, functionName);
    } else {
        Services().ReportError(*this, "entity script function was not found");
    }
}

// Retail: 0x82C3D338 ?Event_SetCanBecomeDormant@idEntity@@AAA?AVeventVoid@@H@Z
void idEntity::Event_SetCanBecomeDormant(const int value) {
    flags.canBecomeDormant = value != 0;
    if (!flags.canBecomeDormant) LeaveDormancy();
}

// Retail: 0x82C3D380 ?Event_Teleport@idEntity@@AAA?AVeventVoid@@ABVidVec3@@ABVidAngles@@@Z
void idEntity::Event_Teleport(const idVec3& newOrigin,
        const idAngles& newAngles) { Teleport(newOrigin, newAngles); }

// Retail: 0x82C3D3D0 ?Event_ClampAngles@idEntity@@AAA?AVeventVector@@ABVidAngles@@00@Z
idAngles idEntity::Event_ClampAngles(const idAngles& input,
        const idAngles& minimum, const idAngles& maximum) const {
    idAngles result;
    for (int index = 0; index < 3; ++index) {
        const float normalized = NormalizeAngle180(input[index]);
        result[index] = Clamp(normalized, minimum[index], maximum[index]);
    }
    return result;
}

// Retail: 0x82C3D520 ?Event_TestFunctionality@idEntity@@AAA?AVeventVoid@@XZ
void idEntity::Event_TestFunctionality() {}

// Retail: 0x82C3D568 ?CreateEntityInterface@idEntity@@UAAPAVidEntityInterface@@PAVidGame@@@Z
idEntityInterface* idEntity::CreateEntityInterface(idGame* const game) {
    return Services().CreateEntityInterface(*this, game);
}

// Retail: 0x82C3D5F8 ?Event_IsClass@idEntity@@AAA?AVeventBool@@PBD@Z
bool idEntity::Event_IsClass(const char* requestedClass) const {
    return Services().IsSpecificClass(*this, requestedClass);
}

// Retail: 0x82C3D6C0 ?Event_PostSpawn@idInfo_TraversalChain@@QAA?AVeventVoid@@XZ
void idInfoTraversalChainPostSpawn(idEntity& entity) {
    entity.Event_SpawnBind();
}

// Retail: 0x82C3D700 ?Event_SetContents@idEntity@@AAA?AVeventVoid@@H@Z
void idEntity::Event_SetContents(const int value) {
    Services().SetPhysicsContents(*this, physics, value);
}

// Retail: 0x82C3D758 ?Event_AddContentsFlag@idEntity@@AAA?AVeventVoid@@H@Z
void idEntity::Event_AddContentsFlag(const int flag) {
    Event_SetContents(Event_GetContents() | flag);
}

// Retail: 0x82C3D7B8 ?Event_RemoveContentsFlag@idEntity@@AAA?AVeventVoid@@H@Z
void idEntity::Event_RemoveContentsFlag(const int flag) {
    Event_SetContents(Event_GetContents() & ~flag);
}

// Retail: 0x82C3D818 ?Event_SetClipMask@idEntity@@AAA?AVeventVoid@@H@Z
void idEntity::Event_SetClipMask(const int mask) {
    Services().SetPhysicsClipMask(*this, physics, mask);
}

// Retail: 0x82C3D870 ?Event_AddClipMaskFlag@idEntity@@AAA?AVeventVoid@@H@Z
void idEntity::Event_AddClipMaskFlag(const int flag) {
    Event_SetClipMask(Event_GetClipMask() | flag);
}

// Retail: 0x82C3D8D0 ?Event_RemoveClipMaskFlag@idEntity@@AAA?AVeventVoid@@H@Z
void idEntity::Event_RemoveClipMaskFlag(const int flag) {
    Event_SetClipMask(Event_GetClipMask() & ~flag);
}

// Retail: 0x82C3D930 ?Event_SetTakesDamage@idEntity@@AAA?AVeventVoid@@_N@Z
void idEntity::Event_SetTakesDamage(const bool value) {
    flags.takesDamage = value;
}

// Retail: 0x82C3D948 ?GetTeam@idEntity@@QBA?AW4gameTeam_t@@XZ
int idEntity::GetTeam() const { return team; }

// Retail: 0x82C3D960 ?GetViewStateFOV@idEntity@@UAAXAAVidVec3@@AAE1@Z
void idEntity::GetViewStateFOV(idVec3& viewOrigin,
        std::uint8_t& horizontalFov, std::uint8_t& verticalFov) {
    viewOrigin = origin;
    horizontalFov = verticalFov = 0;
}

// Retail: 0x82C3DA38 ?GetViewStateFOV@idEntity@@UBAXAAVidVec3@@AAE1@Z
void idEntity::GetViewStateFOV(idVec3& viewOrigin,
        std::uint8_t& horizontalFov, std::uint8_t& verticalFov) const {
    viewOrigin = origin;
    horizontalFov = verticalFov = 0;
}

// Retail: 0x82C3DB10 ?GetRepairBotTetherPoint@idEntity@@UBA_NHHAAVidVec3@@@Z
bool idEntity::GetRepairBotTetherPoint(int, int, idVec3& point) const {
    point = origin;
    return false;
}

// Retail: 0x82C3DBE8 ?InitRenderModel@idEntity@@QAAXXZ
void idEntity::InitRenderModel() {
    if (modelName.IsEmpty()) return;
    if (renderModel != nullptr) Services().ReleaseRenderModel(renderModel);
    renderModel = Services().ResolveRenderModel(modelName.c_str());
    InitPresentableInternal();
}

// Retail: 0x82C3DCA0 ?Remove@idEntity@@UAAXXZ
void idEntity::Remove() {
    if (removed) return;
    removed = true;
    Unbind();
    RemoveBinds();
    UntouchTriggers(idList<idEntity*, 5>());
    BecomeInactive(~0);
    Services().QueueRemove(*this);
}

// Retail: 0x82C3DD50 ?SetName@idEntity@@QAAXPBD@Z
void idEntity::SetName(const char* const newName) {
    const idStr oldName(name);
    name = newName == nullptr ? "" : newName;
    Services().RegisterEntityName(*this, oldName.c_str(), name.c_str());
}

// Retail: 0x82C3E080 $LN122_1
void idEntityNameHashCleanup(idStr& string) { string.Clear(); }

// Retail: 0x82C3E0D0 ?UpdatePVSAreas@idEntity@@QAAXXZ
void idEntity::UpdatePVSAreas() {
    idBounds worldBounds;
    worldBounds.FromTransformedBounds(bounds, origin, axis);
    UpdatePVSAreas(worldBounds);
}

// Retail: 0x82C3E168 ?BecomeActive@idEntity@@QAAXH@Z
void idEntity::BecomeActive(const int flagsToSet) {
    if (flagsToSet == 0) return;
    thinkFlags |= flagsToSet;
    if (physics != nullptr && (flagsToSet & 1) != 0) {
        Services().ActivatePhysics(*this, physics, flagsToSet);
    }
    if (flags.isDormant) LeaveDormancy();
}

// Retail: 0x82C3E2F0 ?UpdateFX@idEntity@@UAAXXZ
void idEntity::UpdateFX() { Services().UpdateFX(*this); }

// Retail: 0x82C3E320 ?StopSound@idEntity@@QAAXW4soundChannel_t@@E@Z
void idEntity::StopSound(const int channel, const bool broadcast) {
    if (channel >= 0 && channel < 32) soundChannels[channel].playing = false;
    if (soundEmitter != nullptr) Services().StopSound(*this, soundEmitter,
        channel, broadcast);
}

// Retail: 0x82C3E338 ?UpdateSound@idEntity@@QAAXXZ
void idEntity::UpdateSound() {
    if (soundEmitter != nullptr) Services().UpdateSound(*this);
}

// Retail: 0x82C3E3C8 ?FreeSoundEmitter@idEntity@@QAAX_N@Z
void idEntity::FreeSoundEmitter(const bool immediate) {
    if (soundEmitter != nullptr) {
        Services().FreeSoundEmitter(soundEmitter, immediate);
        soundEmitter = nullptr;
    }
    for (int channel = 0; channel < 32; ++channel) {
        soundChannels[channel] = idEntitySoundChannelState();
    }
}

// Retail: 0x82C3E3E0 ?IsPlayingSound@idEntity@@QBA_NW4soundChannel_t@@@Z
bool idEntity::IsPlayingSound(const int channel) const {
    return channel >= 0 && channel < 32 && soundChannels[channel].playing;
}

// Retail: 0x82C3E3F8 ?GetCurrentSoundShader@idEntity@@QBAPBVidSoundShader@@W4soundChannel_t@@@Z
const idSoundShader* idEntity::GetCurrentSoundShader(const int channel) const {
    return channel >= 0 && channel < 32 && soundChannels[channel].playing
        ? soundChannels[channel].shader : nullptr;
}

// Retail: 0x82C3E450 ?PostBind@idEntity@@UAAXXZ
void idEntity::PostBind() { UpdateModelTransform(); }

// Retail: 0x82C3E4B8 ?FinishBind@idEntity@@AAAXXZ
void idEntity::FinishBind() {
    if (bindMaster == nullptr) return;
    idVec3 masterOrigin;
    idMat3 masterAxis;
    bindMaster->GetModelTransform(masterOrigin, masterAxis);
    bindLocalOrigin = InverseTransformVector(origin - masterOrigin,
        masterAxis);
    bindLocalAxis = bindOrientated ? masterAxis * axis : axis;
    JoinTeam(bindMaster);
    PostBind();
}

// Retail: 0x82C3E578 ?Unbind@idEntity@@QAAXXZ
void idEntity::Unbind() {
    if (bindMaster == nullptr) return;
    idVec3 worldOrigin = origin;
    idMat3 worldAxis = axis;
    GetModelTransform(worldOrigin, worldAxis);
    QuitTeam();
    bindMaster = nullptr;
    bindJoint = -1;
    bindTag = -1;
    bindOrientated = false;
    bindLocalOrigin.Zero();
    bindLocalAxis = idMat3(1.0f);
    origin = worldOrigin;
    axis = worldAxis;
    PostBind();
}

// Retail: 0x82C3E768 ?RemoveBinds@idEntity@@AAAXXZ
void idEntity::RemoveBinds() {
    idEntity* member = teamChain;
    while (member != nullptr) {
        idEntity* const next = member->teamChain;
        if (member->bindMaster == this || member->IsBoundTo(this)) {
            member->Unbind();
        }
        member = next;
    }
}

// Retail: 0x82C3E980 ?GetMasterPosition@idEntity@@QBA_NAAVidVec3@@AAVidMat3@@@Z
bool idEntity::GetMasterPosition(idVec3& masterOrigin,
        idMat3& masterAxis) const {
    if (bindMaster == nullptr) return false;
    bindMaster->GetModelTransform(masterOrigin, masterAxis);
    return true;
}

// Retail: 0x82C3ED50 ?CreateMoveableClipModel@idEntity@@QAAPAVidClipModel@@_NM@Z
idClipModel* idEntity::CreateMoveableClipModel(const bool allowRenderModel,
        const float shrink) {
    return Services().CreateMoveableClipModel(*this, allowRenderModel,
        shrink);
}

// Retail: 0x82C3EDF0 ?SetPhysics@idEntity@@QAAXPAVidPhysics@@@Z
void idEntity::SetPhysics(idPhysics* const newPhysics) {
    physics = newPhysics != nullptr ? newPhysics : defaultPhysics;
    flags.forcePhysicsUpdate = true;
    BecomeActive(1);
}

// Retail: 0x82C3EF10 ?ActivatePhysics@idEntity@@UAAXH@Z
void idEntity::ActivatePhysics(const int activateFlags) {
    Services().ActivatePhysics(*this, physics, activateFlags);
    BecomeActive(1);
}

// Retail: 0x82C3EF60 ?DeconstructScriptObject@idEntity@@QAAXXZ
void idEntity::DeconstructScriptObject() {
    if (!scriptObjectConstructed) return;
    Services().DeconstructScriptObject(*this);
    scriptObjectConstructed = false;
    signals.Clear();
    threadHandles.Clear();
}

// Retail: 0x82C3F108 ?Signal@idEntity@@QAAXW4signalNum_t@@@Z
void idEntity::Signal(const int signal) {
    idList<idEntitySignalBinding, 5> pending;
    for (int index = 0; index < signals.Num(); ++index) {
        if (signals[index].signal == signal) pending.Append(signals[index]);
    }
    for (int index = 0; index < pending.Num(); ++index) {
        Services().SignalThread(*this, pending[index].thread,
            pending[index].function);
    }
}

// Retail: 0x82C3F238 ?RemoveTargetIndex@idEntity@@QAAXH@Z
void idEntity::RemoveTargetIndex(const int index) {
    if (index >= 0 && index < targets.Num()) targets.RemoveIndex(index);
}

// Retail: 0x82C3F240 ?UntouchTrigger@idEntity@@QAAXPAV1@@Z
void idEntity::UntouchTrigger(idEntity* const trigger) {
    for (int index = touchingTriggers.Num() - 1; index >= 0; --index) {
        if (touchingTriggers[index] != trigger) continue;
        if (trigger != nullptr) Services().OnTriggerUntouch(*trigger, *this);
        touchingTriggers.RemoveIndex(index);
    }
}

// Retail: 0x82C3F3B0 ?Event_SetName@idEntity@@AAA?AVeventVoid@@PBD@Z
void idEntity::Event_SetName(const char* newName) { SetName(newName); }

// Retail: 0x82C3F3E8 ?Event_NumTargets@idEntity@@AAA?AVeventFloat@@XZ
float idEntity::Event_NumTargets() const {
    return static_cast<float>(targets.Num());
}

// Retail: 0x82C3F430 ?Event_GetTarget@idEntity@@AAA?AVeventEntity@@M@Z
idEntity* idEntity::Event_GetTarget(const float requestedIndex) const {
    const int index = static_cast<int>(requestedIndex);
    return index >= 0 && index < targets.Num() ? targets[index] : nullptr;
}

// Retail: 0x82C3F4D8 ?Event_RemoveBinds@idEntity@@AAA?AVeventVoid@@XZ
void idEntity::Event_RemoveBinds() { RemoveBinds(); }

// Retail: 0x82C3F510 ?Event_Unbind@idEntity@@AAA?AVeventVoid@@XZ
void idEntity::Event_Unbind() { Unbind(); }

// Retail: 0x82C3F548 ?Event_StopSound@idEntity@@AAA?AVeventVoid@@W4soundChannel_t@@H@Z
void idEntity::Event_StopSound(const int channel, const int broadcast) {
    StopSound(channel, broadcast != 0);
}

// Retail: 0x82C3F598 ?Event_FadeSound@idEntity@@AAA?AVeventVoid@@W4soundChannel_t@@MM@Z
void idEntity::Event_FadeSound(const int channel, const float target,
        const float seconds) { FadeSound(channel, target, seconds, false); }

// Retail: 0x82C3F5D8 ?Event_FadePitch@idEntity@@AAA?AVeventVoid@@W4soundChannel_t@@MM@Z
void idEntity::Event_FadePitch(const int channel, const float target,
        const float seconds) { FadeSound(channel, target, seconds, true); }

// Retail: 0x82C3F620 ?AnimEvent_ForceVoiceOver@idEntity@@AAA?AVeventVoid@@PBVidMD6Anim@@PBDM@Z
void idEntity::AnimEvent_ForceVoiceOver(const idMD6Anim* const animation,
        const char* key, const float offset) {
    Services().ForceVoiceOver(*this, animation, key, offset);
}

// Retail: 0x82C3F6C0 ?Event_AngleTo@idEntity@@AAA?AVeventFloat@@PAV1@@Z
float idEntity::Event_AngleTo(idEntity* const other) const {
    if (other == nullptr) return 0.0f;
    idVec3 direction = other->origin - origin;
    direction.z = 0.0f;
    if (direction.NormalizeFast() < 0.0001f) return 0.0f;
    const float targetYaw = std::atan2(direction.y, direction.x)
        * 57.295779513f;
    const float ownYaw = std::atan2(axis[0].y, axis[0].x)
        * 57.295779513f;
    return NormalizeAngle180(targetYaw - ownYaw);
}

// Retail: 0x82C3F818 ?Event_GetScriptObjectFloat@idEntity@@AAA?AVeventFloat@@PBD@Z
float idEntity::Event_GetScriptObjectFloat(const char* fieldName) const {
    return Services().GetScriptFloat(*this, fieldName);
}

// Retail: 0x82C3F888 ?Event_GetScriptObjectBool@idEntity@@AAA?AVeventBool@@PBD@Z
bool idEntity::Event_GetScriptObjectBool(const char* fieldName) const {
    return Services().GetScriptBool(*this, fieldName);
}

// Retail: 0x82C3F908 ?Event_GetScriptObjectString@idEntity@@AAA?AVeventString@@PBD@Z
const char* idEntity::Event_GetScriptObjectString(const char* fieldName) const {
    return Services().GetScriptString(*this, fieldName);
}

// Retail: 0x82C3F980 ?Event_SetScriptObject@idEntity@@AAA?AVeventVoid@@PBD@Z
void idEntity::Event_SetScriptObject(const char* typeName) {
    DeconstructScriptObject();
    scriptObjectType = typeName == nullptr ? "" : typeName;
    Services().SetScriptType(*this, scriptObjectType.c_str());
    ConstructScriptObject();
}

// Retail: 0x82C3F9C8 ?GetStimulusScale@idEntity@@QBAMXZ
float idEntity::GetStimulusScale() const {
    return flags.hidden || flags.noSightStimulus ? 0.0f : 1.0f;
}

// Retail: 0x82C3FAA8 ?GetStimulusDistanceScale@idEntity@@QBAMXZ
float idEntity::GetStimulusDistanceScale() const {
    if (flags.hidden || flags.noSightStimulus) return 0.0f;
    const float size = (bounds[1] - bounds[0]).Length();
    return Clamp(size / 128.0f, 0.25f, 4.0f);
}

// Retail: 0x82C3FBA0 ?GetLocationCallingVO@idEntity@@QBAPBVidDeclVoiceOver@@PBVidAI2@@@Z
const idDeclVoiceOver* idEntity::GetLocationCallingVO(
        const idAI2* const ai) const {
    return Services().GetLocationVoiceOver(*this, ai);
}

// Retail: 0x82C3FCC0 ?GetLocationCallingSS@idEntity@@QBAPBVidSoundShader@@PBVidAI2@@@Z
const idSoundShader* idEntity::GetLocationCallingSS(
        const idAI2* const ai) const {
    return Services().GetLocationSound(*this, ai);
}

// Retail: 0x82C3FDE0 ?Event_SignalEvent@idEntity@@AAA?AVeventVoid@@W4signalNum_t@@@Z
void idEntity::Event_SignalEvent(const int signal) { Signal(signal); }

// Retail: 0x82C3FE18 ?ClientThink@idEntity@@UAAXXZ
void idEntity::ClientThink() {
    UpdateModelTransform();
    UpdateFX();
    UpdateSound();
}

// Retail: 0x82C3FE98 ?Serialize@idEntity@@UAAXAAVidSerializer@@@Z
void idEntity::Serialize(idSerializer* const serializer) {
    Services().SerializeEntity(*this, serializer);
}

// Retail: 0x82C3FEB8 ?PostSerializeRead@idEntity@@UAAX_N@Z
void idEntity::PostSerializeRead(const bool reading) {
    firstPostSerializeRead = reading;
    physicsCallbacks.owner = this;
    UpdateModelTransform();
}

// Retail: 0x82C3FED8 ?GetMasterPosition@idEntityPhysicsCallbacks@@UAA_NAAVidVec3@@AAVidMat3@@@Z
bool idEntityPhysicsCallbacks::GetMasterPosition(idVec3& origin,
        idMat3& axis) {
    return owner != nullptr && owner->GetMasterPosition(origin, axis);
}

// Retail: 0x82C3FEE0 ?Spawn@idEntity@@QAAXXZ
void idEntity::Spawn() {
    removed = false;
    flags.isDormant = false;
    dormancy.lastTimeInPlayerPVS = Services().GetGameMilliseconds();
    spawnPosition = origin;
    spawnOrientation = axis;
    InitComponents();
    InitRenderModel();
    InitDefaultPhysics(origin, axis);
    UpdatePVSAreas();
    ConstructScriptObject();
    if (flags.hidden) Hide(); else Show();
}

// Retail: 0x82C401D0 ?FreeRenderModel@idEntity@@QAAXXZ
void idEntity::FreeRenderModel() {
    FreePresentable();
    if (renderModel != nullptr) Services().ReleaseRenderModel(renderModel);
    renderModel = nullptr;
}

// Retail: 0x82C40288 ?UpdateVisuals@idEntity@@QAAXXZ
void idEntity::UpdateVisuals() { Services().UpdateVisuals(*this); }

// Retail: 0x82C402C8 ?UpdateDeferredVisuals@idEntity@@QAAXXZ
void idEntity::UpdateDeferredVisuals() {
    UpdateModelTransform();
    Services().UpdateDeferredVisuals(*this);
    UpdatePVSAreas();
}

// Retail: 0x82C40358 ?ProjectOverlay@idEntity@@UAAXABVidVec3@@0MPBD@Z
void idEntity::ProjectOverlay(const idVec3& overlayOrigin,
        const idVec3& direction, const float size,
        const char* materialName) {
    Services().ProjectOverlay(*this, overlayOrigin, direction, size,
        materialName);
}

// Retail: 0x82C40450 ?SetNoShadows@idEntity@@QAAX_N@Z
void idEntity::SetNoShadows(const bool value) {
    noShadows = value;
    Services().SetPresentableNoShadows(*this, value);
    UpdateVisuals();
}

// Retail: 0x82C40500 ?InitBind@idEntity@@AAA_NPAV1@@Z
bool idEntity::InitBind(idEntity* const master) {
    if (master == nullptr || master == this || master->IsBoundTo(this)) {
        Services().ReportError(*this, "invalid or cyclic entity bind");
        return false;
    }
    Unbind();
    bindMaster = master;
    return true;
}

// Retail: 0x82C40578 ?Bind@idEntity@@QAAXPAV1@_N@Z
void idEntity::Bind(idEntity* const master, const bool orientated) {
    if (!InitBind(master)) return;
    bindOrientated = orientated;
    bindJoint = bindTag = -1;
    FinishBind();
}

// Retail: 0x82C40700 ?BindToJoint@idEntity@@QAAXPAV1@PBD1_N@Z
void idEntity::BindToJoint(idEntity* const master, const char* jointName,
        const char*, const bool orientated) {
    if (!InitBind(master)) return;
    bindOrientated = orientated;
    bindJoint = jointName != nullptr && *jointName != '\0' ? 0 : -1;
    bindTag = -1;
    FinishBind();
}

// Retail: 0x82C40C08 ?BindToJoint@idEntity@@QAAXPAV1@V?$idIndex@FW4invalidJointIndex_t@@@@_N@Z
void idEntity::BindToJoint(idEntity* const master, const int jointIndex,
        const bool orientated) {
    if (!InitBind(master)) return;
    bindOrientated = orientated;
    bindJoint = jointIndex;
    bindTag = -1;
    FinishBind();
}

// Retail: 0x82C40D88 ?BindToTag@idEntity@@QAAXPAV1@ABUtagData_t@@_N@Z
void idEntity::BindToTag(idEntity* const master, const int tagIndex,
        const bool orientated) {
    if (!InitBind(master)) return;
    bindOrientated = orientated;
    bindJoint = -1;
    bindTag = tagIndex;
    FinishBind();
}

// Retail: 0x82C40EC0 ?GetLocalCoordinates@idEntity@@QBA?AVidVec3@@ABV2@@Z
idVec3 idEntity::GetLocalCoordinates(const idVec3& worldCoordinates) const {
    return InverseTransformVector(worldCoordinates - origin, axis);
}

// Retail: 0x82C40FC8 ?GetWorldVector@idEntity@@QBA?AVidVec3@@ABV2@@Z
idVec3 idEntity::GetWorldVector(const idVec3& localVector) const {
    return TransformVector(localVector, axis);
}

// Retail: 0x82C410D0 ?SetOrigin@idEntity@@QAAXABVidVec3@@@Z
void idEntity::SetOrigin(const idVec3& newOrigin) {
    origin = newOrigin;
    flags.forcePhysicsUpdate = true;
    UpdateModelTransform();
    UpdatePVSAreas();
}

// Retail: 0x82C41130 ?SetAxis@idEntity@@UAAXABVidMat3@@@Z
void idEntity::SetAxis(const idMat3& newAxis) {
    axis = newAxis;
    flags.forcePhysicsUpdate = true;
    UpdateModelTransform();
    UpdatePVSAreas();
}

// Retail: 0x82C41190 ?IsToLeft@idEntity@@QBA_NABVidVec3@@@Z
bool idEntity::IsToLeft(const idVec3& point) const {
    idVec3 direction = point - origin;
    direction.z = 0.0f;
    return direction.Dot(axis[1]) < 0.0f;
}

// Retail: 0x82C412C8 ?RemoveNullTargets@idEntity@@QAAXXZ
void idEntity::RemoveNullTargets() {
    for (int index = targets.Num() - 1; index >= 0; --index) {
        if (!Services().IsEntityValid(targets[index])) targets.RemoveIndex(index);
    }
}

// Retail: 0x82C413B0 ?Teleport@idEntity@@UAAXABVidVec3@@ABVidAngles@@@Z
void idEntity::Teleport(const idVec3& newOrigin,
        const idAngles& newAngles) {
    SetOrigin(newOrigin);
    SetAxis(newAngles.ToMat3());
    linearVelocity.Zero();
    angularVelocity.Zero();
    LeaveDormancy();
}

// Retail: 0x82C41468 ?Event_RemoveTarget@idEntity@@AAA?AVeventBool@@PAV1@@Z
bool idEntity::Event_RemoveTarget(idEntity* const target) {
    for (int index = 0; index < targets.Num(); ++index) {
        if (targets[index] == target) {
            targets.RemoveIndex(index);
            return true;
        }
    }
    return false;
}

// Retail: 0x82C41568 ?Event_RandomTarget@idEntity@@AAA?AVeventEntity@@PBD@Z
idEntity* idEntity::Event_RandomTarget(const char* ignoreName) {
    idList<idEntity*, 5> candidates;
    for (int index = 0; index < targets.Num(); ++index) {
        idEntity* const target = targets[index];
        if (!Services().IsEntityValid(target)) continue;
        if (ignoreName != nullptr && *ignoreName != '\0'
                && std::strcmp(target->name.c_str(), ignoreName) == 0) continue;
        candidates.Append(target);
    }
    if (candidates.Num() == 0) return nullptr;
    const int index = std::min(candidates.Num() - 1,
        static_cast<int>(Services().RandomFloat(
            static_cast<float>(candidates.Num()))));
    return candidates[index];
}

// Retail: 0x82C41748 ?Event_BindToJoint@idEntity@@AAA?AVeventVoid@@PAV1@PBD1M@Z
void idEntity::Event_BindToJoint(idEntity* master, const char* jointName,
        const char* animationName, const float orientated) {
    BindToJoint(master, jointName, animationName, orientated != 0.0f);
}

// Retail: 0x82C417A0 ?Event_Bind@idEntity@@AAA?AVeventVoid@@PAV1@@Z
void idEntity::Event_Bind(idEntity* master) { Bind(master, true); }

// Retail: 0x82C417E0 ?Event_BindPosition@idEntity@@AAA?AVeventVoid@@PAV1@@Z
void idEntity::Event_BindPosition(idEntity* master) { Bind(master, false); }

// Retail: 0x82C41820 ?Event_GetModel@idEntity@@AAA?AVeventString@@XZ
const char* idEntity::Event_GetModel() const { return modelName.c_str(); }

// Retail: 0x82C418B8 ?Event_SetSkin@idEntity@@AAA?AVeventVoid@@PBD@Z
void idEntity::Event_SetSkin(const char* const newSkin) {
    skinName = newSkin == nullptr ? "" : newSkin;
    Services().SetPresentableSkin(*this, skinName.c_str());
    UpdateVisuals();
}

// Retail: 0x82C41910 ?Event_SetHighlight@idEntity@@AAA?AVeventVoid@@W4highlightColor_t@@@Z
void idEntity::Event_SetHighlight(const int requestedColor) {
    highlightColor = requestedColor;
    Services().SetPresentableHighlight(*this, requestedColor);
}

// Retail: 0x82C419C8 ?Event_SetWorldOrigin@idEntity@@AAA?AVeventVoid@@ABVidVec3@@@Z
void idEntity::Event_SetWorldOrigin(const idVec3& worldOrigin) {
    SetOrigin(worldOrigin);
}

// Retail: 0x82C41A38 ?Event_SetOrigin@idEntity@@AAA?AVeventVoid@@ABVidVec3@@@Z
void idEntity::Event_SetOrigin(const idVec3& requestedOrigin) {
    if (bindMaster != nullptr) {
        bindLocalOrigin = requestedOrigin;
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GetMasterPosition(masterOrigin, masterAxis)) {
            SetOrigin(TransformPoint(requestedOrigin,
                masterOrigin, masterAxis));
        }
    } else {
        SetOrigin(requestedOrigin);
    }
}

// Retail: 0x82C41AC0 ?Event_GetOrigin@idEntity@@AAA?AVeventVector@@XZ
idVec3 idEntity::Event_GetOrigin() const {
    return bindMaster != nullptr ? bindLocalOrigin : origin;
}

// Retail: 0x82C41DD8 ?SetColor@idEntity@@UAAXMMMM@Z
void idEntity::SetColor(const float red, const float green,
        const float blue, const float alpha) {
    color = idVec4(red, green, blue, alpha);
    Services().SetPresentableColor(*this, color);
    UpdateVisuals();
}

// Retail: 0x82C41E68 ?SetColor@idEntity@@UAAXMMM@Z
void idEntity::SetColor(const float red, const float green,
        const float blue) { SetColor(red, green, blue, color.w); }

// Retail: 0x82C41EF8 ?SetColor@idEntity@@UAAXABVidVec3@@@Z
void idEntity::SetColor(const idVec3& newColor) {
    SetColor(newColor.x, newColor.y, newColor.z, color.w);
}

// Retail: 0x82C41F68 ?SetColor@idEntity@@UAAXABVidColor@@@Z
void idEntity::SetColor(const idColor& newColor) {
    SetColor(newColor.r, newColor.g, newColor.b, newColor.a);
}

// Retail: 0x82C41FD8 ?SetColor@idEntity@@UAAXABVidVec4@@@Z
void idEntity::SetColor(const idVec4& newColor) {
    SetColor(newColor.x, newColor.y, newColor.z, newColor.w);
}

// Retail: 0x82C42048 ?SetModelByName@idEntity@@UAAXPBD@Z
void idEntity::SetModelByName(const char* const newModelName) {
    modelName = newModelName == nullptr ? "" : newModelName;
    idRenderModel* model = modelName.IsEmpty()
        ? nullptr : Services().ResolveRenderModel(modelName.c_str());
    SetModel(model);
}

// Retail: 0x82C42100 ?SetModel@idEntity@@UAAXPAVidRenderModel@@@Z
void idEntity::SetModel(idRenderModel* const model) {
    if (renderModel == model && presentable != nullptr) return;
    FreePresentable();
    if (renderModel != nullptr && renderModel != model) {
        Services().ReleaseRenderModel(renderModel);
    }
    renderModel = model;
    if (renderModel != nullptr) InitPresentableInternal();
    UpdateVisuals();
}

// Retail: 0x82C42200 ?Hide@idEntity@@UAAXXZ
void idEntity::Hide() { Hide(true); }

// Retail: 0x82C42280 ?Hide@idEntity@@UAAX_N@Z
void idEntity::Hide(const bool hide) {
    flags.hidden = hide;
    Services().SetPresentableHidden(*this, hide);
    if (!hide) UpdateVisuals();
}

// Retail: 0x82C42300 ?Show@idEntity@@UAAXXZ
void idEntity::Show() { Hide(false); }

// Retail: 0x82C42380 ?BindToTag@idEntity@@QAAXPAV1@PBD_N@Z
void idEntity::BindToTag(idEntity* const master, const char* tagName,
        const bool orientated) {
    BindToTag(master, tagName != nullptr && *tagName != '\0' ? 0 : -1,
        orientated);
}

// Retail: 0x82C425A0 ?IsEverUsable@idEntity@@UBA_NPBV1@@Z
bool idEntity::IsEverUsable(const idEntity*) const {
    return flags.isActivatable;
}

// Retail: 0x82C42748 ?Event_SpawnBind@idEntity@@AAA?AVeventVoid@@XZ
void idEntity::Event_SpawnBind() {
    if (bindMaster != nullptr) FinishBind();
}

// Retail: 0x82C42840 ?CheckForErrors@idEntity@@UAAXAAV?$idList@VidStr@@$04@@@Z
void idEntity::CheckForErrors(idList<idStr, 5>& errors) {
    if (name.IsEmpty()) errors.Append(idStr("entity has no name"));
    if (bindMaster == this || (bindMaster != nullptr
            && bindMaster->IsBoundTo(this))) {
        errors.Append(idStr("entity has a cyclic bind"));
    }
    for (int index = 0; index < targets.Num(); ++index) {
        if (!Services().IsEntityValid(targets[index])) {
            errors.Append(idStr("entity has an invalid target"));
        }
    }
    if (physics == nullptr) errors.Append(idStr("entity has no physics"));
}

// Retail: 0x82C42A28 $M506935
void idEntityErrorListCleanup(idList<idStr, 5>& errors) { errors.Clear(); }

// Retail: 0x82C42F48 ?SetSignal@idEntity@@QAAXW4signalNum_t@@PAVidThread@@PBVfunction_t@@@Z
void idEntity::SetSignal(const int signal, idThread* const thread,
        const function_t* const function) {
    ClearSignalThread(signal, thread);
    idEntitySignalBinding binding;
    binding.signal = signal;
    binding.thread = thread;
    binding.function = function;
    signals.Append(binding);
}

// Retail: 0x82C43090 ?TouchTrigger@idEntity@@QAAXPAV?$idList@V?$idEntityPtr@VidEntity@@@@$04@@PAV1@PBVidClipModel@@@Z
void idEntity::TouchTrigger(idList<idEntity*, 5>* const touched,
        idEntity* const trigger, const idClipModel*) {
    if (trigger == nullptr || trigger == this) return;
    for (int index = 0; index < touchingTriggers.Num(); ++index) {
        if (touchingTriggers[index] == trigger) {
            if (touched != nullptr) touched->Append(trigger);
            return;
        }
    }
    touchingTriggers.Append(trigger);
    if (touched != nullptr) touched->Append(trigger);
    Services().OnTriggerTouch(*trigger, *this);
}

// Retail: 0x82C43190 ?UntouchTriggers@idEntity@@QAA_NABV?$idStaticList@V?$idEntityPtr@VidEntity@@@@$07@@@Z
bool idEntity::UntouchTriggers(const idList<idEntity*, 5>& stillTouching) {
    bool removedAny = false;
    for (int index = touchingTriggers.Num() - 1; index >= 0; --index) {
        bool found = false;
        for (int keep = 0; keep < stillTouching.Num(); ++keep) {
            if (touchingTriggers[index] == stillTouching[keep]) {
                found = true;
                break;
            }
        }
        if (!found) {
            idEntity* const trigger = touchingTriggers[index];
            if (trigger != nullptr) Services().OnTriggerUntouch(*trigger,
                *this);
            touchingTriggers.RemoveIndex(index);
            removedAny = true;
        }
    }
    return removedAny;
}

// Retail: 0x82C434F8 ??0idEntity@@QAA@XZ
idEntity::idEntity()
    : name(), className("idEntity"), modelName(), skinName(),
      scriptObjectType(), spawnPosition(0.0f, 0.0f, 0.0f),
      spawnOrientation(1.0f), origin(0.0f, 0.0f, 0.0f), axis(1.0f),
      linearVelocity(0.0f, 0.0f, 0.0f),
      angularVelocity(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f, 1.0f),
      color(1.0f, 1.0f, 1.0f, 1.0f), bounds(), flags(), targets(),
      touchingTriggers(), threadHandles(), signals(), dormancy(),
      bindMaster(nullptr), teamMaster(nullptr), teamChain(nullptr),
      owner(nullptr), progressionEntity(nullptr),
      bindLocalOrigin(0.0f, 0.0f, 0.0f), bindLocalAxis(1.0f),
      bindJoint(-1), bindTag(-1), bindOrientated(false),
      bindSnapToParent(false), entityNumber(-1), entityDef(nullptr),
      thinkFlags(0), defaultPhysics(nullptr), physics(nullptr),
      clipModel(nullptr), physicsCallbacks(this), presentable(nullptr),
      renderModel(nullptr), customMaterial(nullptr), soundEmitter(nullptr),
      volumeAdjustment(0.0f), numPVSAreas(0), team(-1), contents(0),
      clipMask(0), entitiesKilled(0), firstPostSerializeRead(true),
      scriptObjectConstructed(false), removed(false), noShadows(false),
      privateLightOnly(false), megaModel(false), highlightColor(0) {
    bounds[0].Zero();
    bounds[1].Zero();
    for (int index = 0; index < 4; ++index) pvsAreas[index] = 0;
}

// Retail: 0x82C43978 ??1idEntity@@UAA@XZ
idEntity::~idEntity() {
    RemoveBinds();
    Unbind();
    DeconstructScriptObject();
    FreeSoundEmitter(true);
    FreeRenderModel();
    if (clipModel != nullptr) Services().ReleaseClipModel(clipModel);
    if (defaultPhysics != nullptr) Services().ReleaseDefaultPhysics(
        defaultPhysics);
    clipModel = nullptr;
    defaultPhysics = physics = nullptr;
    Services().ReleaseRuntime(*this);
    signals.Clear();
    threadHandles.Clear();
    touchingTriggers.Clear();
    targets.Clear();
}

// Retail: 0x82C43CE8 ?GetSoundEmitter@idEntity@@QAAPAVidSoundEmitter@@_N@Z
idSoundEmitter* idEntity::GetSoundEmitter(const bool create) {
    if (soundEmitter == nullptr && create) {
        soundEmitter = Services().AllocateSoundEmitter(*this);
    }
    return soundEmitter;
}

// Retail: 0x82C43DE8 ?RunPhysics@idEntity@@QAAXXZ
void idEntity::RunPhysics() {
    if (physics == nullptr || flags.isDormant) return;
    const bool moved = Services().EvaluatePhysics(*this, physics,
        Services().GetGameMillisecondsPerFrame(), flags.forcePhysicsUpdate);
    flags.forcePhysicsUpdate = false;
    if (bindMaster != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GetMasterPosition(masterOrigin, masterAxis)) {
            origin = TransformPoint(bindLocalOrigin, masterOrigin, masterAxis);
            if (bindOrientated) axis = masterAxis * bindLocalAxis;
        }
    } else {
        origin = origin + linearVelocity
            * (Services().GetGameMillisecondsPerFrame() * 0.001f);
    }
    if (moved || flags.forcePhysicsUpdate) {
        UpdateModelTransform();
        UpdatePVSAreas();
    }
    if (flags.touchesTriggers || flags.afTouchesTriggers) TouchTriggers();
}

// Retail: 0x82C44648 ?AddTarget@idEntity@@QAAXPAV1@@Z
void idEntity::AddTarget(idEntity* const target) {
    if (target == nullptr || target == this) return;
    for (int index = 0; index < targets.Num(); ++index) {
        if (targets[index] == target) return;
    }
    targets.Append(target);
}

// Retail: 0x82C446C8 ?TouchTriggers@idEntity@@QAA_NXZ
bool idEntity::TouchTriggers() {
    idList<idEntity*, 5> touched;
    Services().TouchTriggers(*this, touched);
    for (int index = 0; index < touched.Num(); ++index) {
        TouchTrigger(nullptr, touched[index], nullptr);
    }
    return UntouchTriggers(touched) || touched.Num() > 0;
}

// Retail: 0x82C44AF8 ?Event_AddTarget@idEntity@@AAA?AVeventVoid@@PAV1@@Z
void idEntity::Event_AddTarget(idEntity* target) { AddTarget(target); }

// Retail: 0x82C45788 ?Think@idEntity@@UAAXXZ
void idEntity::Think() { RunPhysics(); }

// Retail: 0x82C457D0 ?StartSoundShader@idEntity@@QAAHW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@E@Z
int idEntity::StartSoundShader(const int channel,
        const idSoundShader* const shader,
        const idEntitySoundParms& parms, const int flagsValue) {
    if (shader == nullptr || channel < 0 || channel >= 32) return 0;
    idSoundEmitter* const emitter = GetSoundEmitter(true);
    idEntitySoundChannelState& state = soundChannels[channel];
    state.shader = shader;
    state.volume = parms.volume + volumeAdjustment;
    state.pitch = parms.pitch;
    state.playing = true;
    return Services().StartSound(*this, emitter, channel, shader,
        parms, flagsValue);
}

// Retail: 0x82C458E8 ?StartSoundShader@idEntity@@QAAHW4soundChannel_t@@PBVidSoundShader@@HE@Z
int idEntity::StartSoundShader(const int channel,
        const idSoundShader* const shader, const int flagsValue,
        const bool broadcast) {
    idEntitySoundParms parms;
    parms.pitch = 0.0f;
    parms.volume = 0.0f;
    return StartSoundShader(channel, shader, parms,
        flagsValue | (broadcast ? 1 : 0));
}

// Retail: 0x82C45938 ?SetSoundVolume@idEntity@@QAAXW4soundChannel_t@@M@Z
void idEntity::SetSoundVolume(const int channel, const float volume) {
    if (channel < 0 || channel >= 32) return;
    soundChannels[channel].volume = volume + volumeAdjustment;
    if (soundEmitter != nullptr) Services().SetSoundVolume(*this,
        soundEmitter, channel, soundChannels[channel].volume);
}

// Retail: 0x82C459B0 ?SetSoundPitch@idEntity@@QAAXW4soundChannel_t@@M@Z
void idEntity::SetSoundPitch(const int channel, const float pitch) {
    if (channel < 0 || channel >= 32) return;
    soundChannels[channel].pitch = pitch;
    if (soundEmitter != nullptr) Services().SetSoundPitch(*this,
        soundEmitter, channel, pitch);
}

// Retail: 0x82C45A28 ?FadeSound@idEntity@@QAAXW4soundChannel_t@@MM_N@Z
void idEntity::FadeSound(const int channel, const float target,
        const float seconds, const bool pitch) {
    if (channel < 0 || channel >= 32 || soundEmitter == nullptr) return;
    if (pitch) soundChannels[channel].pitch = target;
    else soundChannels[channel].volume = target;
    Services().FadeSound(*this, soundEmitter, channel, target,
        seconds, pitch);
}

// Retail: 0x82C45AA8 ?ModifySound@idEntity@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@@Z
void idEntity::ModifySound(const int channel,
        const idSoundShader* const shader,
        const idEntitySoundParms& parms) {
    if (channel < 0 || channel >= 32) return;
    soundChannels[channel].shader = shader;
    soundChannels[channel].volume = parms.volume + volumeAdjustment;
    soundChannels[channel].pitch = parms.pitch;
    if (soundEmitter != nullptr) Services().ModifySound(*this,
        soundEmitter, channel, shader, parms);
}

// Retail: 0x82C45B08 ?SetVolumeAdjustment@idEntity@@QAAXM@Z
void idEntity::SetVolumeAdjustment(const float adjustment) {
    volumeAdjustment = adjustment;
    if (soundEmitter != nullptr) Services().SetVolumeAdjustment(*this,
        soundEmitter, adjustment);
}

// Retail: 0x82C45B70 ?ClearVolumeAdjustment@idEntity@@QAAXXZ
void idEntity::ClearVolumeAdjustment() { SetVolumeAdjustment(0.0f); }

// Retail: 0x82C45BC8 ?Activate@idEntity@@QAAXPAV1@@Z
void idEntity::Activate(idEntity* const activator) {
    LeaveDormancy();
    OnActivate(activator);
    Signal(0);
    if (!scriptObjectType.IsEmpty()
            && Services().HasScriptFunction(*this, "activate")) {
        Services().CallScriptFunction(*this, "activate");
    }
}

void idEntity::OnActivate(idEntity*) {}

// Retail: 0x82C45D90 ?Use@idEntity@@UAA_NPAV1@W4usableState_t@@@Z
bool idEntity::Use(idEntity* const user, const int usableState) {
    if (usableState == 0 || !IsCurrentlyUsable(user)) return false;
    Activate(user);
    return true;
}

// Retail: 0x82C45EB0 ?ActivateTargets@idEntity@@UAAXPAV1@@Z
void idEntity::ActivateTargets(idEntity* const activator) {
    RemoveNullTargets();
    idList<idEntity*, 5> snapshot(targets);
    for (int index = 0; index < snapshot.Num(); ++index) {
        if (snapshot[index] != nullptr) {
            Services().ActivateEntity(*snapshot[index], activator);
        }
    }
}

// Retail: 0x82C45F80 ?Event_Activate@idEntity@@AAA?AVeventVoid@@PAV1@@Z
void idEntity::Event_Activate(idEntity* activator) { Activate(activator); }

// Retail: 0x82C45FB8 ?Event_StartSoundShader@idEntity@@AAA?AVeventFloat@@PBVidSoundShader@@W4soundChannel_t@@@Z
float idEntity::Event_StartSoundShader(const idSoundShader* shader,
        const int channel) {
    return static_cast<float>(StartSoundShader(channel, shader, 0, true))
        * 0.001f;
}

// Retail: 0x82C46090 ?Event_PlayVoiceOver@idEntity@@AAA?AVeventFloat@@PBVidDeclVoiceOver@@W4soundChannel_t@@PBD@Z
float idEntity::Event_PlayVoiceOver(const idDeclVoiceOver* const voiceOver,
        const int channel, const char* key) {
    if (voiceOver == nullptr) return 0.0f;
    Services().PlayVoiceOver(*this, voiceOver, channel, key);
    return 0.0f;
}
