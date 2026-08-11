#pragma once

#include "game/gamesys/eventarg.h"
#include "gamelib/animstack/animstacktypes.h"
#include "idlib/containers/list.h"
#include "idlib/geometry/jointtransform.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

class idAnimatedEntity;
class idAnimStack;
class idDeclDamage;
class idDeclFX;
class idDeclParticle;
class idDeclSkins;
class idEntity;
class idGame;
class idMD6Anim;
class idMD6Node;
class idPresentable;
class idRenderModel;
class idSoundShader;
class idTreeAnimator;
struct trace_t;

enum collide_t : int;
enum fxCondition_t : int;
enum meshKitComponents_t : int;
enum soundShaderGroups_t : int;
enum surfTypes_t : int;

enum idAnimatedSoundChannel : int {
    ANIMATED_SOUND_ANY = 0,
    ANIMATED_SOUND_MUSIC1,
    ANIMATED_SOUND_WEAPON,
    ANIMATED_SOUND_VOICE2,
    ANIMATED_SOUND_VOICE,
    ANIMATED_SOUND_BODY,
    ANIMATED_SOUND_BODY2,
    ANIMATED_SOUND_BODY3,
    ANIMATED_SOUND_ITEM
};

struct idAnimatedSoundOverrideParms {
    float pitchMin = 1.0f;
    float pitchMax = 1.0f;
};

struct idAnimatedDamageEffect {
    idAnimatedDamageEffect* next = nullptr;
    const idDeclParticle* type = nullptr;
    idJointIndex jointNum;
    idVec3 localOrigin{0.0f, 0.0f, 0.0f};
    int time = 0;
};

class idAnimatedEntityServices {
public:
    virtual ~idAnimatedEntityServices() = default;

    virtual int GetGameMilliseconds() const { return 0; }
    virtual bool HasArticulatedFigure(const idAnimatedEntity&) const {
        return false;
    }
    virtual bool IsArticulatedFigureLoaded(const idAnimatedEntity&) const {
        return false;
    }
    virtual bool IsArticulatedFigureActive(const idAnimatedEntity&) const {
        return false;
    }
    virtual collide_t CollideArticulatedFigure(idAnimatedEntity&, int,
        trace_t&, const idVec3&) { return static_cast<collide_t>(0); }
    virtual void ApplyArticulatedFigureForce(idAnimatedEntity&, int, int,
        const idVec3&, const idVec3&) {}
    virtual void ApplyArticulatedFigureImpulse(idAnimatedEntity&, int, int,
        const idVec3&, const idVec3&, int) {}
    virtual void ApplyArticulatedFigureWaterSplash(
        idAnimatedEntity&, int, int, surfTypes_t, int) {}
    virtual void ActivateArticulatedFigure(idAnimatedEntity&, int, bool) {}

    virtual void UpdateAttachments(idAnimatedEntity&) {}
    virtual void FreePresentable(idAnimatedEntity&) {}
    virtual void AddBindConstraints(idAnimatedEntity&) {}
    virtual void RemoveBindConstraints(idAnimatedEntity&) {}
    virtual idAnimStack* GetAnimStack(idAnimatedEntity&) const {
        return nullptr;
    }
    virtual idTreeAnimator* GetTreeAnimator(idAnimatedEntity&) const {
        return nullptr;
    }
    virtual idTreeAnimator* GetTreeAnimator(
        idAnimatedEntity&, int) const { return nullptr; }
    virtual void ShutdownFX(idAnimatedEntity&) {}
    virtual void ShutdownImpacts(idAnimatedEntity&) {}
    virtual void JobSync(idAnimatedEntity&) {}
    virtual void SetModel(idAnimatedEntity&, idRenderModel*) {}
    virtual idPresentable* AllocPresentable(
        idAnimatedEntity&, idRenderModel*) { return nullptr; }
    virtual bool GetTagPosition(idAnimatedEntity&, const char*, const char*,
        idVec3&, idMat3&) const { return false; }
    virtual bool GetTagPosition(idAnimatedEntity&, int, int,
        idVec3&, idMat3&) const { return false; }
    virtual void GetFallbackTransform(
        const idAnimatedEntity&, idVec3& origin, idMat3& axis) const {
        origin.Zero();
        axis = idMat3(1.0f);
    }
    virtual void UpdateImpacts(idAnimatedEntity&) {}
    virtual void ApplyBaseImpulse(idAnimatedEntity&, int, int,
        const idVec3&, const idVec3&) {}
    virtual void ApplyBaseForce(idAnimatedEntity&, int, int,
        const idVec3&, const idVec3&) {}
    virtual bool GetArticulatedFigureModelTransform(
        const idAnimatedEntity&, idVec3&, idMat3&) const { return false; }
    virtual void GetPhysicsTransform(
        const idAnimatedEntity&, idVec3& origin, idMat3& axis) const {
        origin.Zero();
        axis = idMat3(1.0f);
    }
    virtual idJointIndex GetJointIndex(
        const idAnimatedEntity&, const char*) const { return {}; }
    virtual bool GetJointLocalTransform(const idAnimatedEntity&,
        idJointIndex, idVec3&, idMat3&) const { return false; }
    virtual bool GetJointWorldTransform(const idAnimatedEntity&,
        idJointIndex, idVec3&, idMat3&) const { return false; }
    virtual bool CalculateDamageImpulse(const idAnimatedEntity&, idEntity*,
        const idEntity*, const idDeclDamage*, float, const idVec3&,
        const trace_t*, const idVec3*, idVec3&, idVec3&) const {
        return false;
    }

    virtual void PauseAnimation(idAnimatedEntity&, int) {}
    virtual void OffsetAnimEventTimes(idAnimatedEntity&, int) {}
    virtual void UnpauseAnimation(idAnimatedEntity&, int) {}
    virtual void UpdateModelTransform(idAnimatedEntity&) {}
    virtual void SetJointPosition(idAnimatedEntity&, idJointIndex,
        jointModTransform_t, const idVec3&) {}
    virtual void SetJointAngles(idAnimatedEntity&, idJointIndex,
        jointModTransform_t, const idAngles&) {}
    virtual bool GetJointAngles(const idAnimatedEntity&, idJointIndex,
        idAngles&) const { return false; }

    virtual void StopFX(idAnimatedEntity&, fxCondition_t) {}
    virtual void StartFX(idAnimatedEntity&, fxCondition_t) {}
    virtual void SpawnParticle(idAnimatedEntity&, const idDeclParticle*,
        const char*) {}
    virtual void TriggerEntity(idAnimatedEntity&, const char*) {}
    virtual void DamageByName(idAnimatedEntity&, const idDeclDamage*,
        const char*, const char*) {}
    virtual void RadiusDamage(idAnimatedEntity&, const idDeclDamage*,
        const char*) {}
    virtual void Notify(idAnimatedEntity&, const char*) {}
    virtual void AddPlayerWhiplash(
        idAnimatedEntity&, const idAngles&) {}
    virtual void ShowKit(idAnimatedEntity&, meshKitComponents_t,
        const char*) {}
    virtual void SetSkin(idAnimatedEntity&, const char*) {}
    virtual void CallFrameCommand(idAnimatedEntity&, const char*, bool) {}
    virtual bool SuppressWeaponSound(const idAnimatedEntity&) const {
        return false;
    }
    virtual bool SuppressVoiceSound(const idAnimatedEntity&) const {
        return false;
    }
    virtual void PlaySound(idAnimatedEntity&, idAnimatedSoundChannel,
        const idSoundShader*, float) {}
    virtual void FadeSoundGroup(
        soundShaderGroups_t, float, int) {}
    virtual void AttachEntity(
        idAnimatedEntity&, const char*, const char*) {}
    virtual void DetachEntity(idAnimatedEntity&, const char*) {}
    virtual void WarnDefaultAnimEvent(
        const idAnimatedEntity&, const idMD6Anim*) {}

    virtual void Spawn(idAnimatedEntity&) {}
    virtual bool GetRepairBotTetherPoint(const idAnimatedEntity&, int,
        int, idVec3&) const { return false; }
    virtual bool GetMasterPosition(
        const idAnimatedEntity&, idVec3&, idMat3&) const { return false; }
    virtual idMD6Node* ResolveAnimationMasterTree(
        idAnimatedEntity&, idAnimatedEntity*) const { return nullptr; }
    virtual void SetProxyTree(idAnimatedEntity&, idMD6Node*) {}
    virtual idJointIndex ResolveRadiusDamageJoint(
        const idAnimatedEntity&, const char*) const { return {}; }
    virtual bool UseRelaxedChatter(const idAnimatedEntity&) const {
        return false;
    }
    virtual void UpdateFrameCommands(idAnimatedEntity&, idMD6Node*) {}
    virtual void UpdateCloth(idAnimatedEntity&) {}
    virtual void BlendAnimation(idAnimatedEntity&, bool) {}
    virtual void UpdateVisuals(idAnimatedEntity&) {}
    virtual void ClearJointMods(idAnimatedEntity&) {}
    virtual bool BloodEffectsEnabled() const { return true; }
    virtual bool UpdateDamageEffect(
        idAnimatedEntity&, idAnimatedDamageEffect&) { return true; }
    virtual void DestroyDamageEffect(idAnimatedDamageEffect* effect) {
        delete effect;
    }
    virtual void RunPhysics(idAnimatedEntity&) {}
    virtual void UpdateFX(idAnimatedEntity&) {}
    virtual void Shutdown(idAnimatedEntity&) {}
};

class idAnimatedEntityPhysicsCallbacks {
public:
    explicit idAnimatedEntityPhysicsCallbacks(
        idAnimatedEntity* entity = nullptr) : ent(entity) {}

    collide_t Collide(int physId, trace_t& collision,
        const idVec3& velocity);
    void ApplyForce(int physId, int bodyId,
        const idVec3& point, const idVec3& force);
    void ApplyWaterSplashEffects(int physId, int bodyId,
        surfTypes_t surface, int splashState);
    const char* GetName() const;
    void ApplyImpulse(int physId, int bodyId,
        const idVec3& point, const idVec3& impulse);
    void ActivatePhysics(int physId);
    void DeactivatePhysics(int physId);
    bool GetMasterPosition(idVec3& origin, idMat3& axis) const;

    idAnimatedEntity* ent;
};

class idAnimatedEntityInterface {
public:
    idAnimatedEntityInterface(idGame* game, idAnimatedEntity* entity);
    virtual ~idAnimatedEntityInterface() = default;

    virtual idAnimStack* GetAnimStack();
    virtual idTreeAnimator* GetTreeAnimator(int id);

    idGame* game;
    idAnimatedEntity* entity;
};

class idAnimatedEntity {
public:
    enum { TH_ANIMATE = 4 };

    idAnimatedEntity();
    virtual ~idAnimatedEntity();

    static void SetServices(idAnimatedEntityServices* services);
    static idAnimatedEntityServices& Services();

    virtual void UpdateAttachments();
    void FreePresentable();
    virtual void PreBind();
    virtual void PreUnbind();
    virtual void JobSync();
    virtual void SetModel(idRenderModel* model);
    virtual idPresentable* AllocPresentable(idRenderModel* model);
    bool GetTagPosition(const char* propName, const char* tagName,
        idVec3& origin, idMat3& axis) const;
    bool GetTagPosition(int propIndex, int tagIndex,
        idVec3& origin, idMat3& axis) const;
    void KillFX();
    void UpdateImpacts();
    virtual void ApplyImpulse(int physId, int bodyId,
        const idVec3& point, const idVec3& impulse);
    virtual void ApplyForce(int physId, int bodyId,
        const idVec3& point, const idVec3& force);
    virtual void GetModelTransform(idVec3& origin, idMat3& axis) const;
    bool GetJointLocalTransform(const char* jointName,
        idVec3& origin, idMat3& axis) const;
    bool GetWorldSpaceJointTransform(idJointIndex jointIndex,
        idVec3& origin, idMat3& axis) const;
    bool GetWorldSpaceJointTransform(const char* jointName,
        idVec3& origin, idMat3& axis) const;
    virtual bool CalcDamageImpulse(idEntity* inflictor,
        const idEntity* attacker, const idDeclDamage* damageDef,
        float damageScale, const idVec3& direction, const trace_t* trace,
        const idVec3* impulsePoint, idVec3& point, idVec3& impulse) const;
    void PauseAnimation();
    void UnpauseAnimation();
    virtual bool IsAnimating() const;

    eventInt Event_GetJointHandle(const char* jointName);
    eventVoid Event_SetJointPos(idJointIndex joint,
        jointModTransform_t transform, const idVec3& position);
    eventVoid Event_SetJointAngle(idJointIndex joint,
        jointModTransform_t transform, const idAngles& angles);
    eventVector Event_GetJointPos(idJointIndex joint);
    eventVector Event_GetJointAngle(idJointIndex joint);
    eventVoid Event_StartFX(fxCondition_t condition);
    eventVoid Event_StopFX(fxCondition_t condition);
    void StopFX(fxCondition_t condition);

    eventVoid AnimEvent_DeclParticle(const idMD6Anim*,
        const idDeclParticle* particle, const char* jointName);
    eventVoid AnimEvent_StopFX(const idMD6Anim*, fxCondition_t condition);
    eventVoid AnimEvent_Trigger(const idMD6Anim*, const char* entityName);
    eventVoid AnimEvent_Damage(const idMD6Anim*,
        const idDeclDamage*, const char* attacker, const char* inflictor);
    eventVoid AnimEvent_RadiusDamage(const idMD6Anim*,
        const idDeclDamage*, const char* tagName);
    eventVoid AnimEvent_Notify(const idMD6Anim*, const char* message);
    eventVoid AnimEvent_AddPlayerWhiplash(
        const idMD6Anim*, float pitch, float yaw, float roll);
    eventVoid AnimEvent_ShowKit(
        const idMD6Anim*, meshKitComponents_t, const char*);
    eventVoid AnimEvent_SetSkin(const idMD6Anim*, const char* skinName);
    eventVoid AnimEvent_ScriptFunction(const idMD6Anim*, const char* name);
    eventVoid AnimEvent_ScriptFunctionObject(
        const idMD6Anim*, const char* name);
    eventVoid AnimEvent_Sound(const idMD6Anim*, const idSoundShader*);
    eventVoid AnimEvent_SoundMusic(const idMD6Anim*, const idSoundShader*);
    eventVoid AnimEvent_PitchedSound(
        const idMD6Anim*, const idSoundShader*, float pitch);
    eventVoid AnimEvent_SoundWeapon(const idMD6Anim*, const idSoundShader*);
    eventVoid AnimEvent_SoundVoice(const idMD6Anim*, const idSoundShader*);
    eventVoid AnimEvent_SoundVoice2(const idMD6Anim*, const idSoundShader*);
    eventVoid AnimEvent_SoundVoiceHighPrio(
        const idMD6Anim*, const idSoundShader*);
    eventVoid AnimEvent_SoundBody(const idMD6Anim*, const idSoundShader*);
    eventVoid AnimEvent_SoundBody2(const idMD6Anim*, const idSoundShader*);
    eventVoid AnimEvent_SoundBody3(const idMD6Anim*, const idSoundShader*);
    eventVoid AnimEvent_SoundItem(const idMD6Anim*, const idSoundShader*);
    eventVoid AnimEvent_FadeSoundGroup(const idMD6Anim*,
        soundShaderGroups_t group, float toDB, float overSeconds);
    eventVoid AnimEvent_AttachEntity(
        const idMD6Anim*, const char* entityName, const char* tagName);
    eventVoid AnimEvent_DetachEntity(
        const idMD6Anim*, const char* entityName);
    eventVoid AnimEvent_Pause(const idMD6Anim*);
    eventVoid AnimEvent_StartFX(const idMD6Anim*, fxCondition_t condition);
    eventVoid AnimEvent_Default(const idMD6Anim* anim);

    virtual bool GetRepairBotTetherPoint(
        int pointIndex, int clipMask, idVec3& outPosition) const;
    void UpdateProxyAnimator();
    void SetRadiusDamageJointIndices(const idList<idStr, 5>& jointNames);
    void UpdateFrameCommands();
    void UpdateAnimation(bool forceNonDeferredBlend);
    void UpdateDamageEffects();
    virtual void Think();
    void Spawn();

    idStr name;
    int entityNumber;
    int thinkFlags;
    int animationPauseTime;
    idAnimatedDamageEffect* damageEffects;
    const idDeclSkins* skinPreload;
    const idDeclFX* fxDecl;
    idStr damageSwapSkin;
    float initialMorphValue;
    idAnimatedSoundOverrideParms soundOverrideParms;
    idAnimatedEntity* animationMaster;
    idList<idJointIndex, 5> radiusDamageJointIndices;
    idAnimatedEntityPhysicsCallbacks defaultPhysicsCallbacks;
};
