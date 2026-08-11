#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/color.h"
#include "idlib/containers/list.h"
#include "idlib/text/str.h"

#include <cstdint>

class idAI2;
class idClipModel;
class idDeclDamage;
class idDeclEntityDef;
class idDeclVoiceOver;
class idEntity;
class idEntityInterface;
class idGame;
class idInventoryItem;
class idMaterial;
class idMD6Anim;
class idPhysics;
class idPresentable;
class idRenderLight;
class idRenderModel;
class idSerializer;
class idSoundEmitter;
class idSoundShader;
class idThread;
class function_t;
struct contactInfo_t;
struct trace_t;

enum idEntityCollideResult {
    ENTITY_COLLIDE_NONE = 0,
    ENTITY_COLLIDE = 1
};

struct idEntitySoundParms {
    float minDistance = 0.0f;
    float maxDistance = 0.0f;
    float volume = 0.0f;
    float pitch = 0.0f;
    int flags = 0;
};

struct idEntitySoundChannelState {
    const idSoundShader* shader = nullptr;
    float volume = 0.0f;
    float pitch = 0.0f;
    bool playing = false;
};

struct idEntitySignalBinding {
    int signal = 0;
    idThread* thread = nullptr;
    const function_t* function = nullptr;
};

struct idEntityDormancyState {
    float delay = 5.0f;
    float distance = 4096.0f;
    int lastTimeInPlayerPVS = 0;
    int becomeDormantTime = 0;
    int endForceTime = 0;
    bool forceDormant = false;
};

struct idEntityFlags {
    bool selected = false;
    bool takesDamage = false;
    bool noKnockback = false;
    bool isActivatable = false;
    bool noFlood = false;
    bool forcePhysicsUpdate = false;
    bool canBecomeDormant = true;
    bool hidden = false;
    bool dynamicClipReplicationAxis = false;
    bool dynamicClipReplication = false;
    bool skipReplication = false;
    bool afTouchesTriggers = false;
    bool touchesTriggers = false;
    bool enableStaticSpecular = false;
    bool noSightStimulus = false;
    bool isDormant = false;
    bool isAimAssistTarget = false;
};

class idEntityServices {
public:
    virtual ~idEntityServices() = default;
    virtual int GetGameMilliseconds() const;
    virtual int GetGameMillisecondsPerFrame() const;
    virtual float RandomFloat(float maximum);
    virtual bool IsEntityInPlayerPVS(const idEntity& entity) const;
    virtual bool IsEntityNearPlayer(const idEntity& entity,
        float distance) const;
    virtual bool UsesRelaxedChatter(const idEntity& entity) const;
    virtual idEntity* FindEntity(const char* name) const;
    virtual bool IsEntityValid(const idEntity* entity) const;
    virtual bool IsSpecificClass(const idEntity& entity,
        const char* className) const;
    virtual bool HasScriptFunction(const idEntity& entity,
        const char* functionName) const;
    virtual float GetScriptFloat(const idEntity& entity,
        const char* fieldName) const;
    virtual bool GetScriptBool(const idEntity& entity,
        const char* fieldName) const;
    virtual const char* GetScriptString(const idEntity& entity,
        const char* fieldName) const;
    virtual void SetScriptType(idEntity& entity, const char* typeName);
    virtual void ConstructScriptObject(idEntity& entity);
    virtual void DeconstructScriptObject(idEntity& entity);
    virtual void ExecuteThread(idEntity& entity, idThread* thread);
    virtual void CallScriptFunction(idEntity& entity,
        const char* functionName);
    virtual void WaitThreadFrame(idEntity& entity);
    virtual void WaitThreadSeconds(idEntity& entity, float seconds);
    virtual void SignalThread(idEntity& entity, idThread* thread,
        const function_t* function);

    virtual idPresentable* AllocatePresentable(idEntity& entity,
        idRenderModel* model);
    virtual void FreePresentable(idPresentable* presentable);
    virtual idRenderModel* ResolveRenderModel(const char* modelName);
    virtual void ReleaseRenderModel(idRenderModel* model);
    virtual const idMaterial* GetRenderModelMaterial(
        const idRenderModel* model) const;
    virtual void UpdatePresentableTransform(idEntity& entity,
        idPresentable* presentable, const idVec3& origin,
        const idMat3& axis);
    virtual void SetPresentableColor(idEntity& entity,
        const idVec4& color);
    virtual void SetPresentableScale(idEntity& entity,
        const idVec3& scale);
    virtual void SetPresentableHidden(idEntity& entity, bool hidden);
    virtual void SetPresentableNoShadows(idEntity& entity, bool noShadows);
    virtual void SetPresentablePrivateLightOnly(idEntity& entity,
        bool privateOnly);
    virtual void SetPresentableSkin(idEntity& entity, const char* skinName);
    virtual void SetPresentableHighlight(idEntity& entity, int color);
    virtual void ProjectOverlay(idEntity& entity, const idVec3& origin,
        const idVec3& direction, float size, const char* materialName);
    virtual void UpdateVisuals(idEntity& entity);
    virtual void UpdateDeferredVisuals(idEntity& entity);
    virtual void UpdateFX(idEntity& entity);
    virtual void UpdateSound(idEntity& entity);
    virtual void UpdatePVSAreas(idEntity& entity, const idBounds& bounds,
        int* areas, int& count);

    virtual idPhysics* AllocateDefaultPhysics(idEntity& entity);
    virtual void ReleaseDefaultPhysics(idPhysics* physics);
    virtual idClipModel* CreateMoveableClipModel(idEntity& entity,
        bool allowRenderModel, float shrink);
    virtual void ReleaseClipModel(idClipModel* clipModel);
    virtual bool EvaluatePhysics(idEntity& entity, idPhysics* physics,
        int timeStep, bool forceUpdate);
    virtual void ActivatePhysics(idEntity& entity, idPhysics* physics,
        int flags);
    virtual void DeactivatePhysics(idEntity& entity, idPhysics* physics,
        int flags);
    virtual void ApplyImpulse(idEntity& entity, idPhysics* physics,
        int id, int body, const idVec3& point, const idVec3& impulse);
    virtual void ApplyForce(idEntity& entity, idPhysics* physics,
        int id, int body, const idVec3& point, const idVec3& force);
    virtual int GetPhysicsContents(const idEntity& entity,
        const idPhysics* physics) const;
    virtual int GetPhysicsClipMask(const idEntity& entity,
        const idPhysics* physics) const;
    virtual void SetPhysicsContents(idEntity& entity, idPhysics* physics,
        int contents);
    virtual void SetPhysicsClipMask(idEntity& entity, idPhysics* physics,
        int clipMask);
    virtual idBounds GetPhysicsBounds(const idEntity& entity,
        const idPhysics* physics) const;
    virtual void OnEntityCollide(idEntity& entity, int body,
        trace_t* trace, const idVec3& velocity);
    virtual void OnEntityContact(idEntity& entity, int body,
        contactInfo_t* contact);
    virtual bool OnEntityCrush(idEntity& entity, int body);
    virtual void OnEntityDamage(idEntity& entity, int inflictor,
        int attacker, const idDeclDamage* damage);
    virtual void OnWaterEffects(idEntity& entity, int body, int waterBody,
        int surfaceType, int splashState);

    virtual idSoundEmitter* AllocateSoundEmitter(idEntity& entity);
    virtual void FreeSoundEmitter(idSoundEmitter* emitter, bool immediate);
    virtual int StartSound(idEntity& entity, idSoundEmitter* emitter,
        int channel, const idSoundShader* shader,
        const idEntitySoundParms& parms, int flags);
    virtual void StopSound(idEntity& entity, idSoundEmitter* emitter,
        int channel, bool broadcast);
    virtual void ModifySound(idEntity& entity, idSoundEmitter* emitter,
        int channel, const idSoundShader* shader,
        const idEntitySoundParms& parms);
    virtual void FadeSound(idEntity& entity, idSoundEmitter* emitter,
        int channel, float target, float seconds, bool pitch);
    virtual void SetSoundVolume(idEntity& entity, idSoundEmitter* emitter,
        int channel, float volume);
    virtual void SetSoundPitch(idEntity& entity, idSoundEmitter* emitter,
        int channel, float pitch);
    virtual void SetVolumeAdjustment(idEntity& entity,
        idSoundEmitter* emitter, float adjustment);

    virtual void ActivateEntity(idEntity& target, idEntity* activator);
    virtual void NotifyMakeActivatable(idEntity& entity, bool activatable);
    virtual void NotifyProgressionOwner(idEntity& entity,
        idEntity* progressionOwner);
    virtual void RegisterEntityName(idEntity& entity, const char* oldName,
        const char* newName);
    virtual void QueueRemove(idEntity& entity);
    virtual void TouchTriggers(idEntity& entity,
        idList<idEntity*, 5>& touching);
    virtual bool EntitiesTouch(const idEntity& left,
        const idEntity& right) const;
    virtual void OnTriggerTouch(idEntity& trigger, idEntity& entity);
    virtual void OnTriggerUntouch(idEntity& trigger, idEntity& entity);
    virtual void ShowEditingDialog(idEntity& entity);
    virtual void UpdateEditingDialog(idEntity& entity);
    virtual void SerializeEntity(idEntity& entity,
        idSerializer* serializer);
    virtual idEntityInterface* CreateEntityInterface(idEntity& entity,
        idGame* game);
    virtual const idDeclVoiceOver* GetLocationVoiceOver(
        const idEntity& entity, const idAI2* ai) const;
    virtual const idSoundShader* GetLocationSound(
        const idEntity& entity, const idAI2* ai) const;
    virtual void ForceVoiceOver(idEntity& entity, const idMD6Anim* animation,
        const char* key, float offset);
    virtual void PlayVoiceOver(idEntity& entity,
        const idDeclVoiceOver* voiceOver, int channel, const char* key);
    virtual void ReportError(const idEntity& entity, const char* message);
    virtual void ReleaseRuntime(idEntity& entity);
};

class idEntityPhysicsCallbacks {
public:
    explicit idEntityPhysicsCallbacks(idEntity* owner = nullptr);
    int Collide(int body, trace_t* trace, const idVec3& velocity);
    int Contact(int body, contactInfo_t* contact);
    void ApplyImpulse(int id, int body, const idVec3& point,
        const idVec3& impulse);
    void ApplyForce(int id, int body, const idVec3& point,
        const idVec3& force);
    bool Crush(int body);
    void ApplyDamage(int inflictor, int attacker,
        const idDeclDamage* damage);
    void ActivatePhysics(int flags);
    void DeactivatePhysics(int flags);
    void ApplyWaterEffects(int body, int waterBody);
    void ApplyWaterSplashEffects(int body, int waterBody,
        int surfaceType, int splashState);
    const char* GetName() const;
    bool GetMasterPosition(idVec3& origin, idMat3& axis);
    idEntity* owner;
};

class idEntity {
public:
    idEntity();
    virtual ~idEntity();
    static void SetServices(idEntityServices* services);
    static idEntityServices& Services();

    void CleanRenderParms();
    void UpdatePVSAreas(const idBounds& bounds);
    void UpdatePVSAreas();
    bool GetForceDormant() const;
    virtual void GetColor(idVec3& color) const;
    virtual void GetColor(idColor& color) const;
    virtual void GetColor(idVec4& color) const;
    const idMaterial* GetRenderModelMaterial() const;
    virtual void GetScale(idVec3& scale) const;
    virtual void SetScale(const idVec3& scale);
    bool IsBound() const;
    bool IsBoundTo(const idEntity* master) const;
    bool IsBoundOriented() const;
    idEntity* GetBindMaster() const;
    idEntity* GetTeamMaster() const;
    idEntity* GetNextTeamEntity() const;
    void QuitTeam();
    void RestorePhysics(idPhysics* restoredPhysics);
    idPhysics* GetPhysics() const;
    void SetAngles(const idAngles& angles);
    virtual void ApplyImpulse(int id, int body, const idVec3& point,
        const idVec3& impulse);
    virtual void ApplyForce(int id, int body, const idVec3& point,
        const idVec3& force);
    virtual void InventoryRemoved(idInventoryItem* item);
    virtual void ExecuteThread(idThread* thread);
    virtual bool IsCurrentlyUsable(const idEntity* user) const;
    virtual bool ModifyCrosshairInfo(const idEntity* user,
        const void* focusTrace, int usableState, void* crosshairInfo) const;
    void SetIsActivatable(bool activatable);
    virtual void ShowEditingDialog();
    virtual void UpdateEditingDialog();

    idEntity* Event_FindEntity(const char* entityName) const;
    bool Event_TargetsReady() const;
    int Event_IsHidden() const;
    idVec3 Event_GetWorldOrigin() const;
    idVec3 Event_GetLinearVelocity() const;
    idVec3 Event_GetAngularVelocity() const;
    int Event_HasFunction(const char* functionName) const;
    const char* Event_GetScriptObject() const;
    const char* Event_GetClass() const;
    bool Event_IsSpecificClass(const char* className) const;
    int Event_GetContents() const;
    int Event_GetClipMask() const;
    void SetTeam(int team);
    void SetClipReplicationFlags(bool dynamicClip, bool dynamicAxis);
    bool IsFirstPostSerializeRead();
    void SpawnTransform(const idVec3& origin, const idMat3& axis);
    bool UpdateDormant();
    void InitComponents();
    virtual bool ShouldEnterDormancy();
    virtual bool ShouldLeaveDormancy();
    virtual void DormantBegin();
    virtual void DormantEnd(int timeDormant);
    void ForceDormancy(bool force, int delayMilliseconds);
    void LeaveDormancy();
    void BecomeInactive(int flagsToClear);
    bool IsMegaModel() const;
    void SetPrivateLightOnly(bool privateOnly);
    virtual const idMaterial* GetCustomMaterial() const;
    virtual void GetModelTransform(idVec3& origin, idMat3& axis) const;
    virtual void UpdateModelTransform();
    void InitPresentableInternal();
    virtual idPresentable* AllocPresentable(idRenderModel* model);
    void FreePresentable();
    idRenderModel* GetRenderModelFromPresentable() const;
    virtual void GetSoundTransform(idVec3& origin, idMat3& axis) const;
    void ConvertLocalToWorldTransform(idVec3& origin, idMat3& axis) const;
    void JoinTeam(idEntity* teamMember);
    void ReferenceDefaultPhysics();
    void InitDefaultPhysics(const idVec3& origin, const idMat3& axis);
    float GetDistanceSqrTo(const idVec3& point) const;
    virtual bool CanDisablePhysics(const idEntity* other) const;
    virtual void ApplyImpulseFromEntity(const idEntity* source, int body,
        const idVec3& point, const idVec3& impulse);
    virtual void DeactivatePhysics(int flags);
    virtual bool Crush(int body);
    virtual bool CalcDamageImpulse(const idEntity* inflictor,
        const idEntity* attacker, const idDeclDamage* damage,
        float damageScale, const idVec3& direction, const trace_t* trace,
        idVec3& impulse, idVec3& point) const;
    void ConstructScriptObject();
    bool HasSignal(int signal) const;
    void ClearSignalThread(int signal, idThread* thread);
    virtual int AddThread(int threadHandle);
    virtual void RemoveThread(int threadHandle);
    virtual int GetThread(int index) const;
    virtual int NumThreads() const;
    virtual int GetUsableState(const idEntity* user,
        const void* focusTrace) const;
    virtual bool IsCrosshairDisabled(const idEntity* user,
        const void* focusTrace, int usableState) const;
    virtual bool IsCrosshairSubdued(const idEntity* user,
        const void* focusTrace, int usableState) const;
    void ClearTargets();
    virtual bool IsPusher() const;

    const char* Event_GetName() const;
    void Event_ActivateTargets(idEntity* activator);
    void Event_MakeActivatable(bool activatable);
    void Event_ClearTargets();
    void Event_SetOwner(idEntity* newOwner);
    void Event_SetProgressionOwner(idEntity* newOwner);
    void Event_NotifyProgressionOwner();
    void Event_SetModel(const char* modelName);
    void Event_SetClipModel(const char* modelName);
    void Event_SetColorAndAlpha(float red, float green, float blue,
        float alpha);
    void Event_SetColor(float red, float green, float blue);
    idVec3 Event_GetColor() const;
    void Event_SetAngles(const idAngles& angles);
    idAngles Event_GetAngles() const;
    idVec3 Event_GetModelForward() const;
    void Event_SetLinearVelocity(const idVec3& velocity);
    void Event_SetAngularVelocity(const idVec3& velocity);
    idVec3 Event_GetSize() const;
    idVec3 Event_GetMins() const;
    idVec3 Event_GetMaxs() const;
    int Event_Touches(idEntity* other) const;
    void Event_RestorePosition();
    float Event_DistanceTo(idEntity* other) const;
    float Event_DistanceToPoint(const idVec3& point) const;
    void Event_WaitFrame();
    void Event_Wait(float seconds);
    void Event_CallFunction(const char* functionName);
    void Event_SetCanBecomeDormant(int canBecomeDormant);
    void Event_Teleport(const idVec3& origin, const idAngles& angles);
    idAngles Event_ClampAngles(const idAngles& angles,
        const idAngles& minimum, const idAngles& maximum) const;
    void Event_TestFunctionality();
    virtual idEntityInterface* CreateEntityInterface(idGame* game);
    bool Event_IsClass(const char* className) const;
    void Event_SetContents(int contents);
    void Event_AddContentsFlag(int flag);
    void Event_RemoveContentsFlag(int flag);
    void Event_SetClipMask(int mask);
    void Event_AddClipMaskFlag(int flag);
    void Event_RemoveClipMaskFlag(int flag);
    void Event_SetTakesDamage(bool takesDamage);
    int GetTeam() const;
    virtual void GetViewStateFOV(idVec3& origin,
        std::uint8_t& horizontalFov, std::uint8_t& verticalFov);
    virtual void GetViewStateFOV(idVec3& origin,
        std::uint8_t& horizontalFov, std::uint8_t& verticalFov) const;
    virtual bool GetRepairBotTetherPoint(int index, int team,
        idVec3& point) const;
    void InitRenderModel();
    virtual void Remove();
    void SetName(const char* newName);
    void BecomeActive(int flagsToSet);
    virtual void UpdateFX();
    void StopSound(int channel, bool broadcast);
    void UpdateSound();
    void FreeSoundEmitter(bool immediate);
    bool IsPlayingSound(int channel) const;
    const idSoundShader* GetCurrentSoundShader(int channel) const;
    virtual void PostBind();
    void FinishBind();
    void Unbind();
    void RemoveBinds();
    bool GetMasterPosition(idVec3& origin, idMat3& axis) const;
    idClipModel* CreateMoveableClipModel(bool allowRenderModel, float shrink);
    void SetPhysics(idPhysics* newPhysics);
    virtual void ActivatePhysics(int flags);
    void DeconstructScriptObject();
    void Signal(int signal);
    void RemoveTargetIndex(int index);
    void UntouchTrigger(idEntity* trigger);

    void Event_SetName(const char* newName);
    float Event_NumTargets() const;
    idEntity* Event_GetTarget(float index) const;
    void Event_RemoveBinds();
    void Event_Unbind();
    void Event_StopSound(int channel, int broadcast);
    void Event_FadeSound(int channel, float target, float seconds);
    void Event_FadePitch(int channel, float target, float seconds);
    void AnimEvent_ForceVoiceOver(const idMD6Anim* animation,
        const char* key, float offset);
    float Event_AngleTo(idEntity* other) const;
    float Event_GetScriptObjectFloat(const char* fieldName) const;
    bool Event_GetScriptObjectBool(const char* fieldName) const;
    const char* Event_GetScriptObjectString(const char* fieldName) const;
    void Event_SetScriptObject(const char* typeName);
    float GetStimulusScale() const;
    float GetStimulusDistanceScale() const;
    const idDeclVoiceOver* GetLocationCallingVO(const idAI2* ai) const;
    const idSoundShader* GetLocationCallingSS(const idAI2* ai) const;
    void Event_SignalEvent(int signal);
    virtual void ClientThink();
    virtual void Serialize(idSerializer* serializer);
    virtual void PostSerializeRead(bool reading);
    virtual void Spawn();
    void FreeRenderModel();
    void UpdateVisuals();
    void UpdateDeferredVisuals();
    virtual void ProjectOverlay(const idVec3& origin,
        const idVec3& direction, float size, const char* materialName);
    void SetNoShadows(bool noShadows);
    bool InitBind(idEntity* master);
    void Bind(idEntity* master, bool orientated);
    void BindToJoint(idEntity* master, const char* jointName,
        const char* bindAnimation, bool orientated);
    void BindToJoint(idEntity* master, int jointIndex, bool orientated);
    void BindToTag(idEntity* master, int tagIndex, bool orientated);
    idVec3 GetLocalCoordinates(const idVec3& worldCoordinates) const;
    idVec3 GetWorldVector(const idVec3& localVector) const;
    void SetOrigin(const idVec3& origin);
    virtual void SetAxis(const idMat3& axis);
    bool IsToLeft(const idVec3& point) const;
    void RemoveNullTargets();
    virtual void Teleport(const idVec3& origin, const idAngles& angles);
    bool Event_RemoveTarget(idEntity* target);
    idEntity* Event_RandomTarget(const char* ignoreName);
    void Event_BindToJoint(idEntity* master, const char* jointName,
        const char* animationName, float orientated);
    void Event_Bind(idEntity* master);
    void Event_BindPosition(idEntity* master);
    const char* Event_GetModel() const;
    void Event_SetSkin(const char* skinName);
    void Event_SetHighlight(int color);
    void Event_SetWorldOrigin(const idVec3& origin);
    void Event_SetOrigin(const idVec3& origin);
    idVec3 Event_GetOrigin() const;
    virtual void SetColor(float red, float green, float blue, float alpha);
    virtual void SetColor(float red, float green, float blue);
    virtual void SetColor(const idVec3& color);
    virtual void SetColor(const idColor& color);
    virtual void SetColor(const idVec4& color);
    virtual void SetModelByName(const char* modelName);
    virtual void SetModel(idRenderModel* model);
    virtual void Hide();
    virtual void Hide(bool hide);
    virtual void Show();
    void BindToTag(idEntity* master, const char* tagName, bool orientated);
    virtual bool IsEverUsable(const idEntity* user) const;
    void Event_SpawnBind();
    virtual void CheckForErrors(idList<idStr, 5>& errors);
    void SetSignal(int signal, idThread* thread, const function_t* function);
    void TouchTrigger(idList<idEntity*, 5>* touched, idEntity* trigger,
        const idClipModel* clipModel);
    bool UntouchTriggers(const idList<idEntity*, 5>& stillTouching);
    idSoundEmitter* GetSoundEmitter(bool create);
    void RunPhysics();
    void AddTarget(idEntity* target);
    bool TouchTriggers();
    void Event_AddTarget(idEntity* target);
    virtual void Think();
    int StartSoundShader(int channel, const idSoundShader* shader,
        const idEntitySoundParms& parms, int flags);
    int StartSoundShader(int channel, const idSoundShader* shader,
        int flags, bool broadcast);
    void SetSoundVolume(int channel, float volume);
    void SetSoundPitch(int channel, float pitch);
    void FadeSound(int channel, float target, float seconds, bool pitch);
    void ModifySound(int channel, const idSoundShader* shader,
        const idEntitySoundParms& parms);
    void SetVolumeAdjustment(float adjustment);
    void ClearVolumeAdjustment();
    void Activate(idEntity* activator);
    virtual void OnActivate(idEntity* activator);
    virtual bool Use(idEntity* user, int usableState);
    virtual void ActivateTargets(idEntity* activator);
    void Event_Activate(idEntity* activator);
    float Event_StartSoundShader(const idSoundShader* shader, int channel);
    float Event_PlayVoiceOver(const idDeclVoiceOver* voiceOver,
        int channel, const char* key);

    idStr name;
    idStr className;
    idStr modelName;
    idStr skinName;
    idStr scriptObjectType;
    idVec3 spawnPosition;
    idMat3 spawnOrientation;
    idVec3 origin;
    idMat3 axis;
    idVec3 linearVelocity;
    idVec3 angularVelocity;
    idVec3 scale;
    idVec4 color;
    idBounds bounds;
    idEntityFlags flags;
    idList<idEntity*, 5> targets;
    idList<idEntity*, 5> touchingTriggers;
    idList<int, 5> threadHandles;
    idList<idEntitySignalBinding, 5> signals;
    idEntityDormancyState dormancy;
    idEntity* bindMaster;
    idEntity* teamMaster;
    idEntity* teamChain;
    idEntity* owner;
    idEntity* progressionEntity;
    idVec3 bindLocalOrigin;
    idMat3 bindLocalAxis;
    int bindJoint;
    int bindTag;
    bool bindOrientated;
    bool bindSnapToParent;
    int entityNumber;
    const idDeclEntityDef* entityDef;
    int thinkFlags;
    idPhysics* defaultPhysics;
    idPhysics* physics;
    idClipModel* clipModel;
    idEntityPhysicsCallbacks physicsCallbacks;
    idPresentable* presentable;
    idRenderModel* renderModel;
    const idMaterial* customMaterial;
    idSoundEmitter* soundEmitter;
    idEntitySoundChannelState soundChannels[32];
    float volumeAdjustment;
    int numPVSAreas;
    int pvsAreas[4];
    int team;
    int contents;
    int clipMask;
    int entitiesKilled;
    bool firstPostSerializeRead;
    bool scriptObjectConstructed;
    bool removed;
    bool noShadows;
    bool privateLightOnly;
    bool megaModel;
    int highlightColor;
};

int Get_idCombatStage_useRelaxedChatterVO(void* entity);
idRenderLight* GetEntityRenderLightForEntity(idEntity* entity);
void idEntityDefaultPhysicsCleanup(idClipModel* clipModel);
void idEntityNameHashCleanup(idStr& string);
void idEntityErrorListCleanup(idList<idStr, 5>& errors);
