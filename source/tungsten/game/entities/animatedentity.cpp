#include "game/entities/animatedentity.h"

#include <algorithm>

namespace {
idAnimatedEntityServices defaultAnimatedEntityServices;
idAnimatedEntityServices* animatedEntityServices =
    &defaultAnimatedEntityServices;
}

void idAnimatedEntity::SetServices(idAnimatedEntityServices* services) {
    animatedEntityServices = services == nullptr
        ? &defaultAnimatedEntityServices : services;
}

idAnimatedEntityServices& idAnimatedEntity::Services() {
    return *animatedEntityServices;
}

// Retail: 0x82BF76F0 ?Collide@idAnimatedEntityPhysicsCallbacks@@...
collide_t idAnimatedEntityPhysicsCallbacks::Collide(const int physId,
        trace_t& collision, const idVec3& velocity) {
    if (ent == nullptr || !idAnimatedEntity::Services().
            HasArticulatedFigure(*ent)) {
        return static_cast<collide_t>(0);
    }
    return idAnimatedEntity::Services().CollideArticulatedFigure(
        *ent, physId, collision, velocity);
}

// Retail: 0x82BF7708 ?ApplyForce@idAnimatedEntityPhysicsCallbacks@@...
void idAnimatedEntityPhysicsCallbacks::ApplyForce(const int physId,
        const int bodyId, const idVec3& point, const idVec3& force) {
    if (ent != nullptr && idAnimatedEntity::Services().
            HasArticulatedFigure(*ent)) {
        idAnimatedEntity::Services().ApplyArticulatedFigureForce(
            *ent, physId, bodyId, point, force);
    }
}

// Retail: 0x82BF7720 ?ApplyWaterSplashEffects@idAnimatedEntityPhysicsCallbacks@@...
void idAnimatedEntityPhysicsCallbacks::ApplyWaterSplashEffects(
        const int physId, const int bodyId, const surfTypes_t surface,
        const int splashState) {
    if (ent != nullptr && idAnimatedEntity::Services().
            HasArticulatedFigure(*ent)) {
        idAnimatedEntity::Services().ApplyArticulatedFigureWaterSplash(
            *ent, physId, bodyId, surface, splashState);
    }
}

// Retail: 0x82BF7748 ?UpdateAttachments@idAnimatedEntity@@UAAXXZ
void idAnimatedEntity::UpdateAttachments() {
    Services().UpdateAttachments(*this);
}

// Retail: 0x82BF77A8 ?FreePresentable@idAnimatedEntity@@QAAXXZ
void idAnimatedEntity::FreePresentable() {
    Services().FreePresentable(*this);
}

// Retail: 0x82BF7810 ?PreBind@idAnimatedEntity@@UAAXXZ
void idAnimatedEntity::PreBind() {
    if (Services().HasArticulatedFigure(*this)) {
        Services().AddBindConstraints(*this);
    }
}

// Retail: 0x82BF7848 ?PreUnbind@idAnimatedEntity@@UAAXXZ
void idAnimatedEntity::PreUnbind() {
    if (Services().HasArticulatedFigure(*this)) {
        Services().RemoveBindConstraints(*this);
    }
}

// Retail: 0x82BF7880 ??0idAnimatedEntityInterface@@QAA@PAVidGame@@PAVidAnimatedEntity@@@Z
idAnimatedEntityInterface::idAnimatedEntityInterface(
        idGame* const game_, idAnimatedEntity* const entity_)
    : game(game_)
    , entity(entity_) {
}

// Retail: 0x82BF78C0 ?GetAnimStack@idAnimatedEntityInterface@@UAAPAVidAnimStack@@XZ
idAnimStack* idAnimatedEntityInterface::GetAnimStack() {
    return entity == nullptr
        ? nullptr : idAnimatedEntity::Services().GetAnimStack(*entity);
}

// Retail: 0x82BF7970 ?GetName@idAnimatedEntityPhysicsCallbacks@@UAAPBDXZ
const char* idAnimatedEntityPhysicsCallbacks::GetName() const {
    return ent != nullptr && idAnimatedEntity::Services().
        HasArticulatedFigure(*ent) ? "<unknown>" : "NULL";
}

// Retail: 0x82BF7998 ?ApplyImpulse@idAnimatedEntityPhysicsCallbacks@@...
void idAnimatedEntityPhysicsCallbacks::ApplyImpulse(const int physId,
        const int bodyId, const idVec3& point, const idVec3& impulse) {
    if (ent != nullptr && idAnimatedEntity::Services().
            HasArticulatedFigure(*ent)) {
        idAnimatedEntity::Services().ApplyArticulatedFigureImpulse(*ent,
            physId, bodyId, point, impulse,
            idAnimatedEntity::Services().GetGameMilliseconds());
    }
}

// Retail: 0x82BF7A00 ?ActivatePhysics@idAnimatedEntityPhysicsCallbacks@@UAAXH@Z
void idAnimatedEntityPhysicsCallbacks::ActivatePhysics(const int physId) {
    if (ent != nullptr && idAnimatedEntity::Services().
            HasArticulatedFigure(*ent)) {
        idAnimatedEntity::Services().ActivateArticulatedFigure(
            *ent, physId, true);
    }
}

// Retail: 0x82BF7A28 ?DeactivatePhysics@idAnimatedEntityPhysicsCallbacks@@UAAXH@Z
void idAnimatedEntityPhysicsCallbacks::DeactivatePhysics(const int physId) {
    if (ent != nullptr && idAnimatedEntity::Services().
            HasArticulatedFigure(*ent)) {
        idAnimatedEntity::Services().ActivateArticulatedFigure(
            *ent, physId, false);
    }
}

// Retail: 0x82BF7A50 ?KillFX@idAnimatedEntity@@QAAXXZ
void idAnimatedEntity::KillFX() {
    Services().ShutdownFX(*this);
    Services().ShutdownImpacts(*this);
}

// Retail: 0x82BF7AA0 ?JobSync@idAnimatedEntity@@UAAXXZ
void idAnimatedEntity::JobSync() {
    Services().JobSync(*this);
}

// Retail: 0x82BF7B58 ?SetModel@idAnimatedEntity@@UAAXPAVidRenderModel@@@Z
void idAnimatedEntity::SetModel(idRenderModel* const model) {
    Services().SetModel(*this, model);
}

// Retail: 0x82BF7C00 ?AllocPresentable@idAnimatedEntity@@...
idPresentable* idAnimatedEntity::AllocPresentable(idRenderModel* const model) {
    return Services().AllocPresentable(*this, model);
}

// Retail: 0x82BF7D30 ?GetTagPosition@idAnimatedEntity@@QBA_NPBD0...
bool idAnimatedEntity::GetTagPosition(const char* const propName,
        const char* const tagName, idVec3& origin, idMat3& axis) const {
    idAnimatedEntity& self = const_cast<idAnimatedEntity&>(*this);
    if (Services().GetTreeAnimator(self) != nullptr) {
        return Services().GetTagPosition(
            self, propName, tagName, origin, axis);
    }
    Services().GetFallbackTransform(*this, origin, axis);
    return false;
}

// Retail: 0x82BF7E60 ?GetTagPosition@idAnimatedEntity@@QBA_NHH...
bool idAnimatedEntity::GetTagPosition(const int propIndex,
        const int tagIndex, idVec3& origin, idMat3& axis) const {
    if (propIndex < 0 || tagIndex < 0) {
        return false;
    }
    idAnimatedEntity& self = const_cast<idAnimatedEntity&>(*this);
    if (Services().GetTreeAnimator(self) != nullptr) {
        return Services().GetTagPosition(
            self, propIndex, tagIndex, origin, axis);
    }
    Services().GetFallbackTransform(*this, origin, axis);
    return false;
}

// Retail: 0x82BF7FA0 ?UpdateImpacts@idAnimatedEntity@@QAAXXZ
void idAnimatedEntity::UpdateImpacts() {
    Services().UpdateImpacts(*this);
}

// Retail: 0x82BF8038 ?ApplyImpulse@idAnimatedEntity@@UAAXHH...
void idAnimatedEntity::ApplyImpulse(const int physId, const int bodyId,
        const idVec3& point, const idVec3& impulse) {
    if (Services().HasArticulatedFigure(*this)) {
        if (Services().IsArticulatedFigureLoaded(*this)) {
            Services().ApplyArticulatedFigureImpulse(*this, physId, bodyId,
                point, impulse, Services().GetGameMilliseconds());
        }
        if (Services().IsArticulatedFigureActive(*this)) {
            return;
        }
    }
    Services().ApplyBaseImpulse(*this, physId, bodyId, point, impulse);
}

// Retail: 0x82BF8100 ?ApplyForce@idAnimatedEntity@@UAAXHH...
void idAnimatedEntity::ApplyForce(const int physId, const int bodyId,
        const idVec3& point, const idVec3& force) {
    if (Services().HasArticulatedFigure(*this)) {
        if (Services().IsArticulatedFigureLoaded(*this)) {
            Services().ApplyArticulatedFigureForce(
                *this, physId, bodyId, point, force);
        }
        if (Services().IsArticulatedFigureActive(*this)) {
            return;
        }
    }
    Services().ApplyBaseForce(*this, physId, bodyId, point, force);
}

// Retail: 0x82BF81A8 ?GetModelTransform@idAnimatedEntity@@UBAX...
void idAnimatedEntity::GetModelTransform(
        idVec3& origin, idMat3& axis) const {
    if (!Services().IsArticulatedFigureActive(*this)
            || !Services().GetArticulatedFigureModelTransform(
                *this, origin, axis)) {
        Services().GetPhysicsTransform(*this, origin, axis);
    }
}

// Retail: 0x82BF82C0 ?GetJointLocalTransform@idAnimatedEntity@@...
bool idAnimatedEntity::GetJointLocalTransform(const char* const jointName,
        idVec3& origin, idMat3& axis) const {
    idAnimatedEntity& self = const_cast<idAnimatedEntity&>(*this);
    if (Services().GetTreeAnimator(self) == nullptr) {
        return false;
    }
    return Services().GetJointLocalTransform(
        *this, Services().GetJointIndex(*this, jointName), origin, axis);
}

// Retail: 0x82BF8360 ?GetWorldSpaceJointTransform@idAnimatedEntity@@...
bool idAnimatedEntity::GetWorldSpaceJointTransform(
        const idJointIndex jointIndex, idVec3& origin, idMat3& axis) const {
    idAnimatedEntity& self = const_cast<idAnimatedEntity&>(*this);
    return Services().GetTreeAnimator(self) != nullptr
        && Services().GetJointWorldTransform(
            *this, jointIndex, origin, axis);
}

// Retail: 0x82BF83E8 ?CalcDamageImpulse@idAnimatedEntity@@UBA_N...
bool idAnimatedEntity::CalcDamageImpulse(idEntity* const inflictor,
        const idEntity* const attacker, const idDeclDamage* const damageDef,
        const float damageScale, const idVec3& direction,
        const trace_t* const trace, const idVec3* const impulsePoint,
        idVec3& point, idVec3& impulse) const {
    point.Zero();
    impulse.Zero();
    if (damageDef == nullptr) {
        return false;
    }
    return Services().CalculateDamageImpulse(*this, inflictor, attacker,
        damageDef, damageScale, direction, trace, impulsePoint,
        point, impulse);
}

// Retail: 0x82BF8698 ?PauseAnimation@idAnimatedEntity@@QAAXXZ
void idAnimatedEntity::PauseAnimation() {
    animationPauseTime = Services().GetGameMilliseconds();
    Services().PauseAnimation(*this, animationPauseTime);
}

// Retail: 0x82BF86F0 ?IsAnimating@idAnimatedEntity@@UBA_NXZ
bool idAnimatedEntity::IsAnimating() const {
    idAnimatedEntity& self = const_cast<idAnimatedEntity&>(*this);
    return Services().GetTreeAnimator(self) != nullptr
        && (thinkFlags & TH_ANIMATE) != 0;
}

// Retail: 0x82BF8740 ?Event_GetJointHandle@idAnimatedEntity@@...
eventInt idAnimatedEntity::Event_GetJointHandle(const char* jointName) {
    if (Services().GetTreeAnimator(*this) == nullptr) {
        return eventInt(-1);
    }
    return eventInt(static_cast<int>(
        Services().GetJointIndex(*this, jointName).Get()));
}

// Retail: 0x82BF87D8 ?Event_SetJointPos@idAnimatedEntity@@...
eventVoid idAnimatedEntity::Event_SetJointPos(const idJointIndex joint,
        const jointModTransform_t transform, const idVec3& position) {
    if (Services().GetTreeAnimator(*this) != nullptr) {
        Services().SetJointPosition(*this, joint, transform, position);
        thinkFlags |= TH_ANIMATE;
    }
    return {};
}

// Retail: 0x82BF8860 ?Event_SetJointAngle@idAnimatedEntity@@...
eventVoid idAnimatedEntity::Event_SetJointAngle(const idJointIndex joint,
        const jointModTransform_t transform, const idAngles& angles) {
    if (Services().GetTreeAnimator(*this) != nullptr) {
        Services().SetJointAngles(*this, joint, transform, angles);
        thinkFlags |= TH_ANIMATE;
    }
    return {};
}

// Retail: 0x82BF8940 ?Event_GetJointPos@idAnimatedEntity@@...
eventVector idAnimatedEntity::Event_GetJointPos(const idJointIndex joint) {
    idVec3 origin(0.0f, 0.0f, 0.0f);
    idMat3 axis(1.0f);
    GetWorldSpaceJointTransform(joint, origin, axis);
    return eventVector(origin);
}

// Retail: 0x82BF89B0 ?Event_GetJointAngle@idAnimatedEntity@@...
eventVector idAnimatedEntity::Event_GetJointAngle(const idJointIndex joint) {
    idAngles angles(0.0f, 0.0f, 0.0f);
    Services().GetJointAngles(*this, joint, angles);
    return eventVector(idVec3(angles.pitch, angles.yaw, angles.roll));
}

// Retail: 0x82BF8A40 ?StopFX@idAnimatedEntity@@QAAXW4fxCondition_t@@@Z
void idAnimatedEntity::StopFX(const fxCondition_t condition) {
    Services().StopFX(*this, condition);
}

// Retail: 0x82BF8A98 ?AnimEvent_DeclParticle@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_DeclParticle(const idMD6Anim*,
        const idDeclParticle* const particle, const char* const jointName) {
    if (particle != nullptr && Services().GetTreeAnimator(*this) != nullptr) {
        Services().SpawnParticle(*this, particle, jointName);
    }
    return {};
}

// Retail: 0x82BF8C60 ?AnimEvent_StopFX@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_StopFX(
        const idMD6Anim*, const fxCondition_t condition) {
    StopFX(condition);
    return {};
}

// Retail: 0x82BF8CB0 ?AnimEvent_Trigger@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_Trigger(
        const idMD6Anim*, const char* const entityName) {
    Services().TriggerEntity(*this, entityName);
    return {};
}

// Retail: 0x82BF8D20 ?AnimEvent_Damage@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_Damage(const idMD6Anim*,
        const idDeclDamage* const damage, const char* const attacker,
        const char* const inflictor) {
    Services().DamageByName(*this, damage, attacker, inflictor);
    return {};
}

// Retail: 0x82BF8E30 ?AnimEvent_RadiusDamage@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_RadiusDamage(const idMD6Anim*,
        const idDeclDamage* const damage, const char* const tagName) {
    Services().RadiusDamage(*this, damage, tagName);
    return {};
}

// Retail: 0x82BF8E98 ?AnimEvent_Notify@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_Notify(
        const idMD6Anim*, const char* const message) {
    Services().Notify(*this, message);
    return {};
}

// Retail: 0x82BF8ED0 ?AnimEvent_AddPlayerWhiplash@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_AddPlayerWhiplash(const idMD6Anim*,
        const float pitch, const float yaw, const float roll) {
    Services().AddPlayerWhiplash(*this, idAngles(pitch, yaw, roll));
    return {};
}

// Retail: 0x82BF8F78 ?AnimEvent_ShowKit@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_ShowKit(const idMD6Anim*,
        const meshKitComponents_t type, const char* const kitName) {
    if (Services().GetTreeAnimator(*this) != nullptr) {
        Services().ShowKit(*this, type, kitName);
    }
    return {};
}

// Retail: 0x82BF8FB8 ?AnimEvent_SetSkin@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_SetSkin(
        const idMD6Anim*, const char* const skinName) {
    if (Services().GetTreeAnimator(*this) != nullptr) {
        Services().SetSkin(*this, skinName);
    }
    return {};
}

// Retail: 0x82BF9038 ?AnimEvent_ScriptFunction@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_ScriptFunction(
        const idMD6Anim*, const char* const name_) {
    Services().CallFrameCommand(*this, name_, false);
    return {};
}

// Retail: 0x82BF9078 ?AnimEvent_ScriptFunctionObject@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_ScriptFunctionObject(
        const idMD6Anim*, const char* const name_) {
    Services().CallFrameCommand(*this, name_, true);
    return {};
}

// Retail: 0x82BF90B8 ?AnimEvent_Sound@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_Sound(
        const idMD6Anim*, const idSoundShader* const shader) {
    Services().PlaySound(*this, ANIMATED_SOUND_ANY, shader, 1.0f);
    return {};
}

// Retail: 0x82BF9100 ?AnimEvent_SoundMusic@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_SoundMusic(
        const idMD6Anim*, const idSoundShader* const shader) {
    Services().PlaySound(*this, ANIMATED_SOUND_MUSIC1, shader, 1.0f);
    return {};
}

// Retail: 0x82BF9148 ?AnimEvent_PitchedSound@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_PitchedSound(const idMD6Anim*,
        const idSoundShader* const shader, const float pitch) {
    Services().PlaySound(*this, ANIMATED_SOUND_ANY, shader, pitch);
    return {};
}

// Retail: 0x82BF91A8 ?AnimEvent_SoundWeapon@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_SoundWeapon(
        const idMD6Anim*, const idSoundShader* const shader) {
    if (!Services().SuppressWeaponSound(*this)) {
        Services().PlaySound(
            *this, ANIMATED_SOUND_WEAPON, shader, 1.0f);
    }
    return {};
}

// Retail: 0x82BF9240 ?AnimEvent_SoundVoice2@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_SoundVoice2(
        const idMD6Anim*, const idSoundShader* const shader) {
    Services().PlaySound(*this, ANIMATED_SOUND_VOICE2, shader, 1.0f);
    return {};
}

// Retail: 0x82BF9288 ?AnimEvent_SoundVoiceHighPrio@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_SoundVoiceHighPrio(
        const idMD6Anim*, const idSoundShader* const shader) {
    Services().PlaySound(*this, ANIMATED_SOUND_VOICE, shader, 1.0f);
    return {};
}

// Retail: 0x82BF92D0 ?AnimEvent_SoundBody@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_SoundBody(
        const idMD6Anim*, const idSoundShader* const shader) {
    Services().PlaySound(*this, ANIMATED_SOUND_BODY, shader, 1.0f);
    return {};
}

// Retail: 0x82BF9318 ?AnimEvent_SoundBody2@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_SoundBody2(
        const idMD6Anim*, const idSoundShader* const shader) {
    Services().PlaySound(*this, ANIMATED_SOUND_BODY2, shader, 1.0f);
    return {};
}

// Retail: 0x82BF9360 ?AnimEvent_SoundBody3@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_SoundBody3(
        const idMD6Anim*, const idSoundShader* const shader) {
    Services().PlaySound(*this, ANIMATED_SOUND_BODY3, shader, 1.0f);
    return {};
}

// Retail: 0x82BF93A8 ?AnimEvent_SoundItem@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_SoundItem(
        const idMD6Anim*, const idSoundShader* const shader) {
    Services().PlaySound(*this, ANIMATED_SOUND_ITEM, shader, 1.0f);
    return {};
}

// Retail: 0x82BF93F0 ?AnimEvent_FadeSoundGroup@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_FadeSoundGroup(const idMD6Anim*,
        const soundShaderGroups_t group, const float toDB,
        const float overSeconds) {
    Services().FadeSoundGroup(group, toDB,
        static_cast<int>(1000.0f * overSeconds));
    return {};
}

// Retail: 0x82BF9460 ?AnimEvent_AttachEntity@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_AttachEntity(const idMD6Anim*,
        const char* const entityName, const char* const tagName) {
    Services().AttachEntity(*this, entityName, tagName);
    return {};
}

// Retail: 0x82BF94E0 ?AnimEvent_DetachEntity@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_DetachEntity(
        const idMD6Anim*, const char* const entityName) {
    Services().DetachEntity(*this, entityName);
    return {};
}

// Retail: 0x82BF9550 ?AnimEvent_Pause@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_Pause(const idMD6Anim*) {
    PauseAnimation();
    return {};
}

// Retail: 0x82BF95B8 ?GetTreeAnimator@idAnimatedEntityInterface@@...
idTreeAnimator* idAnimatedEntityInterface::GetTreeAnimator(const int id) {
    return entity == nullptr ? nullptr
        : idAnimatedEntity::Services().GetTreeAnimator(*entity, id);
}

// Retail: 0x82BF9640 ??1idAnimatedEntity@@UAA@XZ
idAnimatedEntity::~idAnimatedEntity() {
    Services().Shutdown(*this);
    while (damageEffects != nullptr) {
        idAnimatedDamageEffect* const effect = damageEffects;
        damageEffects = effect->next;
        Services().DestroyDamageEffect(effect);
    }
}

// Retail: 0x82BF98A8 ?Spawn@idAnimatedEntity@@QAAXXZ
void idAnimatedEntity::Spawn() {
    Services().Spawn(*this);
}

// Retail: 0x82BF9C28 ?GetWorldSpaceJointTransform@idAnimatedEntity@@QBA_NPBD...
bool idAnimatedEntity::GetWorldSpaceJointTransform(
        const char* const jointName, idVec3& origin, idMat3& axis) const {
    idAnimatedEntity& self = const_cast<idAnimatedEntity&>(*this);
    if (Services().GetTreeAnimator(self) == nullptr) {
        return false;
    }
    return GetWorldSpaceJointTransform(
        Services().GetJointIndex(*this, jointName), origin, axis);
}

// Retail: 0x82BF9CA0 ?UnpauseAnimation@idAnimatedEntity@@QAAXXZ
void idAnimatedEntity::UnpauseAnimation() {
    const int now = Services().GetGameMilliseconds();
    if (animationPauseTime >= 0) {
        Services().OffsetAnimEventTimes(*this, now - animationPauseTime);
    }
    Services().UnpauseAnimation(*this, now);
    animationPauseTime = -1;
}

// Retail: 0x82BF9D30 ?Event_StartFX@idAnimatedEntity@@...
eventVoid idAnimatedEntity::Event_StartFX(const fxCondition_t condition) {
    Services().StartFX(*this, condition);
    return {};
}

// Retail: 0x82BF9D88 ?Event_StopFX@idAnimatedEntity@@...
eventVoid idAnimatedEntity::Event_StopFX(const fxCondition_t condition) {
    StopFX(condition);
    return {};
}

// Retail: 0x82BF9DD8 ?GetRepairBotTetherPoint@idAnimatedEntity@@...
bool idAnimatedEntity::GetRepairBotTetherPoint(const int pointIndex,
        const int clipMask, idVec3& outPosition) const {
    const int clampedIndex = (std::max)(0, (std::min)(4, pointIndex));
    outPosition.Zero();
    return Services().GetRepairBotTetherPoint(
        *this, clampedIndex, clipMask, outPosition);
}

// Retail: 0x82BF9EE8 ?AnimEvent_StartFX@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_StartFX(
        const idMD6Anim*, const fxCondition_t condition) {
    Services().StartFX(*this, condition);
    return {};
}

// Retail: 0x82BFA0F8 ?AnimEvent_Default@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_Default(const idMD6Anim* const anim) {
    Services().WarnDefaultAnimEvent(*this, anim);
    return {};
}

// Retail: 0x82BFA1B0 ?AnimEvent_SoundVoice@idAnimatedEntity@@...
eventVoid idAnimatedEntity::AnimEvent_SoundVoice(
        const idMD6Anim*, const idSoundShader* const shader) {
    if (!Services().SuppressVoiceSound(*this)) {
        Services().PlaySound(
            *this, ANIMATED_SOUND_VOICE, shader, 1.0f);
    }
    return {};
}

// Retail: 0x82BFA270 ?GetMasterPosition@idAnimatedEntityPhysicsCallbacks@@...
bool idAnimatedEntityPhysicsCallbacks::GetMasterPosition(
        idVec3& origin, idMat3& axis) const {
    if (ent != nullptr
            && idAnimatedEntity::Services().GetMasterPosition(
                *ent, origin, axis)) {
        return true;
    }
    origin.Zero();
    axis = idMat3(1.0f);
    return false;
}

// Retail: 0x82BFA500 ?UpdateProxyAnimator@idAnimatedEntity@@QAAXXZ
void idAnimatedEntity::UpdateProxyAnimator() {
    Services().SetProxyTree(*this,
        Services().ResolveAnimationMasterTree(*this, animationMaster));
}

// Retail: 0x82BFA640 ??0idAnimatedEntity@@QAA@XZ
idAnimatedEntity::idAnimatedEntity()
    : name()
    , entityNumber(-1)
    , thinkFlags(0)
    , animationPauseTime(-1)
    , damageEffects(nullptr)
    , skinPreload(nullptr)
    , fxDecl(nullptr)
    , damageSwapSkin()
    , initialMorphValue(0.0f)
    , soundOverrideParms()
    , animationMaster(nullptr)
    , radiusDamageJointIndices(16)
    , defaultPhysicsCallbacks(this) {
}

// Retail: 0x82BFA870 ?SetRadiusDamageJointIndices@idAnimatedEntity@@...
void idAnimatedEntity::SetRadiusDamageJointIndices(
        const idList<idStr, 5>& jointNames) {
    if (jointNames.IsEmpty()) {
        radiusDamageJointIndices.Clear();
        return;
    }
    if (Services().GetTreeAnimator(*this) == nullptr) {
        return;
    }
    radiusDamageJointIndices.PreAllocate(jointNames.Num());
    for (int index = 0; index < jointNames.Num(); ++index) {
        radiusDamageJointIndices.AddUnique(
            Services().ResolveRadiusDamageJoint(
                *this, jointNames[index].c_str()));
    }
}

// Retail: 0x82BFA9C0 ?UpdateFrameCommands@idAnimatedEntity@@QAAXXZ
void idAnimatedEntity::UpdateFrameCommands() {
    if (Services().UseRelaxedChatter(*this) || animationPauseTime >= 0
            || Services().GetTreeAnimator(*this) == nullptr) {
        return;
    }
    idMD6Node* const tree = Services().ResolveAnimationMasterTree(
        *this, animationMaster);
    Services().UpdateFrameCommands(*this, tree);
}

// Retail: 0x82BFAC68 ?UpdateAnimation@idAnimatedEntity@@QAAX_N@Z
void idAnimatedEntity::UpdateAnimation(const bool forceNonDeferredBlend) {
    Services().UpdateModelTransform(*this);
    if (Services().GetTreeAnimator(*this) == nullptr) {
        return;
    }
    if ((thinkFlags & TH_ANIMATE) != 0) {
        Services().UpdateCloth(*this);
        Services().BlendAnimation(*this, forceNonDeferredBlend);
        Services().UpdateVisuals(*this);
        UpdateAttachments();
    } else {
        Services().UpdateVisuals(*this);
        Services().ClearJointMods(*this);
    }
}

// Retail: 0x82BFB428 ?UpdateDamageEffects@idAnimatedEntity@@QAAXXZ
void idAnimatedEntity::UpdateDamageEffects() {
    idAnimatedDamageEffect** link = &damageEffects;
    while (*link != nullptr) {
        idAnimatedDamageEffect* const effect = *link;
        if (effect->time != 0) {
            link = &effect->next;
            continue;
        }
        *link = effect->next;
        Services().DestroyDamageEffect(effect);
    }
    if (!Services().BloodEffectsEnabled()
            || Services().GetTreeAnimator(*this) == nullptr) {
        return;
    }
    for (idAnimatedDamageEffect* effect = damageEffects;
            effect != nullptr; effect = effect->next) {
        if (!Services().UpdateDamageEffect(*this, *effect)) {
            effect->time = 0;
        }
    }
}

// Retail: 0x82BFB7F8 ?Think@idAnimatedEntity@@UAAXXZ
void idAnimatedEntity::Think() {
    UpdateProxyAnimator();
    UpdateFrameCommands();
    Services().RunPhysics(*this);
    UpdateAnimation(false);
    UpdateDamageEffects();
    Services().UpdateFX(*this);
    UpdateImpacts();
}
