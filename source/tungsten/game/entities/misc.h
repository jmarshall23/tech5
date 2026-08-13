#pragma once

#include "game/entities/entity.h"
#include "game/player/crosshairinfo.h"

class idDeclCloth;
class idDeclElectricBolt;
class idDeclEnv;
class idDeclFlare;
class idDeclInventory;
class idDeclJob;
class idDeclParticle;
class idDeclRibbon;
class idDeclTable;
class idDeclVoiceOver;
class idDynamicEntity;
class idElectricBoltEmitter;
class idFuncCloth;
class idGodRays;
class idGuiEntity;
class idLensFlare;
class idMaterial;
class idParticleEmitter;
class idPlayer;
class idRegimeTile;
class idRenderModelCloth;
class idRenderModelGui;
class idRibbonEmitter;
class idSplinePath;
class idSWF;
struct trace_t;

enum idGuiEntityInitialState : int {
    INIT_STATE_INVALID = -1,
    INIT_STATE_READY = 0,
    INIT_STATE_ONLINE = 1,
    INIT_STATE_STANDBY = 2,
    INIT_STATE_OFFLINE = 3
};

enum idClothType : int {
    CLOTH_INVALID = -1,
    CLOTH_GENERATED = 0,
    CLOTH_MODELED = 1
};

enum idRegimeTileType : int {
    REGIME_TILE_CHILD = 0,
    REGIME_TILE_MASTER = 1
};

struct idMiscFadeState {
    float from = 0.0f;
    float to = 0.0f;
    int startTime = 0;
    int endTime = 0;
    bool noStipple = false;

    void Start(float newFrom, float newTo, int duration,
        int currentTime, bool disableStipple);
    float Evaluate(int currentTime) const;
    bool IsActive(int currentTime) const;
};

struct idMiscWindInterpolation {
    float startValue = 0.0f;
    float endValue = 0.0f;
    int startTime = 0;
    int duration = 0;

    float Evaluate(int currentTime) const;
    bool IsDone(int currentTime) const;
};

struct idMiscInventoryEntry {
    const idDeclInventory* item = nullptr;
    int count = 0;
    bool forSale = false;
    bool lootable = true;
};

struct idMiscRegimeChild {
    idPresentable* presentable = nullptr;
    idEntity* childEntity = nullptr;
    int index = 0;
    const idSoundShader* sndPowerDown = nullptr;
    const idSoundShader* sndReactivate = nullptr;
};

class idMiscServices {
public:
    virtual ~idMiscServices() = default;

    virtual int GetGameMilliseconds() const;
    virtual int GetGameFrame() const;
    virtual int GetGameMillisecondsPerFrame() const;
    virtual float RandomFloat();
    virtual int RandomInt(int minimum, int maximum);
    virtual float SampleTable(const idDeclTable* table, float time) const;
    virtual bool IsEntityVisible(const idEntity& entity) const;
    virtual bool IsRendered(const idEntity& entity) const;
    virtual bool IsMultiplayer() const;

    virtual void MarkDynamicSceneModel(idEntity& entity);
    virtual void SetBinaryModelState(const char* name, bool visible);
    virtual idPlayer* PlayerFromEntity(idEntity* entity) const;
    virtual idPlayer* GetPrimaryPlayer() const;
    virtual void ActivateDynamicJob(idPlayer& player,
        const idDeclJob* job, bool endJob);
    virtual void ConfigureInformationClip(idEntity& entity);
    virtual void ConfigureStaticEntity(idEntity& entity, bool bsp, bool aas);

    virtual void UpdateDynamicEntity(idDynamicEntity& entity,
        const idVec4& color, float fade, const idVec3& windDirection,
        float windStrength);
    virtual void OpenParticleEditor(idParticleEmitter& emitter);
    virtual void UpdateParticleEditor(idParticleEmitter& emitter);
    virtual idPresentable* AllocateParticlePresentable(
        idParticleEmitter& emitter, idRenderModel* model);
    virtual void ConfigureParticle(idParticleEmitter& emitter,
        const idDeclParticle* particle);
    virtual void UpdateParticle(idParticleEmitter& emitter);
    virtual void TriggerParticle(idParticleEmitter& emitter, bool show);
    virtual void EmitSmokeParticle(idParticleEmitter& emitter,
        const idDeclParticle* particle, int time, const idVec3& velocity,
        float diversity);

    virtual idPresentable* AllocateElectricBoltPresentable(
        idElectricBoltEmitter& emitter, idRenderModel* model);
    virtual void AllocateElectricBolt(idElectricBoltEmitter& emitter,
        const idDeclElectricBolt* declaration);
    virtual void FreeElectricBolt(idElectricBoltEmitter& emitter);
    virtual void StartElectricBolt(idElectricBoltEmitter& emitter,
        int time, const idVec3& start, const idVec3& end,
        float diversity);
    virtual void StartElectricBoltPath(idElectricBoltEmitter& emitter,
        idSplinePath* path, int time, float diversity);
    virtual void UpdateElectricBolt(idElectricBoltEmitter& emitter,
        idSplinePath* path, int time, bool loop);
    virtual void StopElectricBolt(idElectricBoltEmitter& emitter);

    virtual void StartRibbon(idRibbonEmitter& emitter,
        const idDeclRibbon* declaration, int time);
    virtual void UpdateRibbon(idRibbonEmitter& emitter, int time);
    virtual void StopRibbon(idRibbonEmitter& emitter);
    virtual void StartFlare(idLensFlare& flare,
        const idDeclFlare* declaration);
    virtual void UpdateFlare(idLensFlare& flare, int time);
    virtual void StopFlare(idLensFlare& flare);
    virtual void SetGodRays(idGodRays& rays, bool enabled);

    virtual void UpdateWind(idEntity& emitter, const idVec3& direction,
        float strength, int gustOverlay);
    virtual void EnableWindInfluence(idEntity& emitter, bool enable);
    virtual void GiveStoredInventory(idEntity& owner,
        const idMiscInventoryEntry& entry);
    virtual void ClearPlayerInventory(idPlayer& player);
    virtual void GivePlayerInventory(idPlayer& player,
        const idDeclInventory* item, int count);
    virtual void RegisterCoopStartingInventory(idEntity* entity);

    virtual void ConfigureDebrisModel(idEntity& debris,
        idRenderModel* model);
    virtual void ConfigureDebrisScale(idEntity& debris,
        const idVec3& scale);
    virtual void MimicEntity(idEntity& imposter, idEntity& original,
        bool animated);

    virtual void PlayAnnouncement(idEntity& manager,
        const idSoundShader* sound);
    virtual void PlayAnnouncementVoiceOver(idEntity& manager,
        const idDeclVoiceOver* voiceOver, const idStrId& talker);
    virtual void StopAnnouncements(idEntity& manager);

    virtual bool SetupGui(idGuiEntity& gui);
    virtual void ReleaseGui(idGuiEntity& gui);
    virtual void UpdateGuiModel(idGuiEntity& gui, int time);
    virtual void InvokeGui(idGuiEntity& gui, const char* function,
        const char* argument);
    virtual void ChangeGuiState(idGuiEntity& gui,
        idGuiEntityInitialState from, idGuiEntityInitialState to);
    virtual void SetGuiFloat(idGuiEntity& gui, const char* name,
        float value);
    virtual void SetGuiString(idGuiEntity& gui, const char* name,
        const char* value);
    virtual bool PostGuiEvent(idGuiEntity& gui, const char* entityName,
        const char* eventName, const idList<idStr, 5>& arguments);
    virtual void PlayGuiSound(idGuiEntity& gui,
        const idSoundShader* sound);

    virtual void CreateCloth(idFuncCloth& cloth,
        const idDeclCloth* declaration);
    virtual void InitializeCloth(idFuncCloth& cloth,
        const idVec3& wind);
    virtual void UpdateClothCollisions(idFuncCloth& cloth,
        bool players, bool ai, bool bullets);
    virtual void UpdateCloth(idFuncCloth& cloth, const idVec3& wind,
        int time);
    virtual void ReleaseCloth(idFuncCloth& cloth);

    virtual float GetDamageAmount(const idDeclDamage* damage) const;
    virtual bool IsTriggerDamage(const idEntity* inflictor) const;
    virtual idPresentable* PrepareRegimeChild(idRegimeTile& parent,
        idRegimeTile& child);
    virtual void SetRegimeChildPowered(idRegimeTile& parent,
        idMiscRegimeChild& child, bool powered);
    virtual void ScheduleRegimePropagation(idRegimeTile& tile,
        bool powered, int delayMilliseconds);
};

void Tungsten_SetMiscServices(idMiscServices* services);
idMiscServices& Tungsten_MiscServices();

class idDynamicSceneEntity : public idEntity {
public:
    idDynamicSceneEntity();
    void Spawn() override;
};

class idBinaryModel : public idEntity {
public:
    idBinaryModel();
    bool IsVisible() const;
    int Event_IsHidden() const;
    void Spawn() override;
    void OnActivate(idEntity* activator) override;
    void Hide() override;
    void Show() override;

    bool invisible;
};

class idFuncShadowCaster : public idEntity {
public:
    ~idFuncShadowCaster() override;
    idStr shadowModelName;
};

class idReferenceMap : public idEntity {
public:
    idReferenceMap();
    ~idReferenceMap() override;
    void Spawn() override;

    idStr mapname;
    bool zeroTransform;
};

class idDynamicJob : public idEntity {
public:
    idDynamicJob();
    void OnActivate(idEntity* activator) override;

    const idDeclJob* jobDecl;
    bool endJob;
    bool forceActivateOnPlayer;
};

class idInformationEntity : public idEntity {
public:
    idInformationEntity();
    void Spawn() override;
    bool ModifyCrosshairInfo(const idEntity* activator,
        const void* focusTrace, int usableState,
        void* crosshairInfo) const override;

    idStrId message;
    const idMaterial* customIcon;
};

class idWorldClipBounds : public idEntity {
public:
    void Spawn() override;
};

class idHorizonScale : public idEntity {
public:
    idHorizonScale();
    void Spawn() override;
    void Think() override;

    float radiusInner;
    float radiusOuter;
};

class idStaticEntity : public idEntity {
public:
    idStaticEntity();
    void Spawn() override;

    bool bsp;
    bool aas;
};

class idDynamicEntity : public idEntity {
public:
    idDynamicEntity();
    ~idDynamicEntity() override;

    void Spawn() override;
    void Think() override;
    void Hide() override;
    void Show() override;
    void OnActivate(idEntity* activator) override;
    void SetColor(float red, float green, float blue,
        float alpha) override;
    void SetColor(float red, float green, float blue) override;
    void SetColor(const idVec3& newColor) override;
    void SetColor(const idVec4& newColor) override;
    void SetColor(const idColor& newColor) override;
    void GetColor(idVec3& out) const override;
    void GetColor(idVec4& out) const override;
    void GetColor(idColor& out) const override;

    void UpdateColorModulate();
    void Event_Fade(float from, float to, float seconds);
    void Event_FadeNoStipple(float from, float to, float seconds);
    void Event_ActivateColorModulate();
    void Event_DeactivateColorModulate();

    bool hide;
    bool castsDimShadows;
    bool solid;
    idVec3 megaModelSpawnPosition;
    int highlightColor;
    const idDeclTable* colorModulateTable;
    float colorModulateTimeScale;
    bool colorModulateActive;
    int spawnTime;
    bool active;
    bool runGui;
    idMiscFadeState fade;
    idVec4 colorPreModulate;
};

class idParticleEmitter : public idDynamicEntity {
public:
    idParticleEmitter();
    ~idParticleEmitter() override;

    void ShowEditingDialog() override;
    void UpdateEditingDialog() override;
    idPresentable* AllocPresentable(idRenderModel* model) override;
    void Hide() override;
    void Show() override;
    void GetScale(idVec3& out) const override;
    void SetScale(const idVec3& newScale) override;
    void OnActivate(idEntity* activator) override;
    void Spawn() override;
    void Think() override;

    void UpdatePresentable();
    void SetParticle(const idDeclParticle* particle);
    void Event_TriggerShow();
    void UpdateModifiedProperties();

    float fadeIn;
    bool hidden;
    float fadeOut;
    bool startOff;
    float alphaScale;
    bool cycleTrigger;
    bool useGlobalShadows;
    bool useSmokeSystem;
    int startDelay;
    idVec3 distributionScale;
    int smokeSystemRate;
    bool inheritMasterVelocity;
    float masterVelocityScale;
    const idDeclParticle* particleSystem;
    bool particleConfigured;
};

class idElectricBoltEmitter : public idDynamicEntity {
public:
    idElectricBoltEmitter();
    ~idElectricBoltEmitter() override;

    idPresentable* AllocPresentable(idRenderModel* model) override;
    void Hide() override;
    void Show() override;
    void OnActivate(idEntity* activator) override;
    void Spawn() override;
    void Think() override;

    idVec3 GetNextEndPos(idEntity* target);
    void Event_Deactivate();
    void SetControlPath(idSplinePath* path);
    idEntity* GetNextTarget();
    void ResetTarget();
    void TurnOn();
    void UpdateControlPath(idSplinePath* path);

    float maxConeAngle;
    int minResetTime;
    int maxResetTime;
    bool startOff;
    const idDeclElectricBolt* electricBoltSystem;
    const idSoundShader* sndPowerDown;
    const idSoundShader* sndPowerUp;
    idVec2 length;
    idSplinePath* controlPath;
    bool loopControlPath;
    int controlPathGrowTime;
    bool electricBoltAllocated;
    int nextResetTime;
};

class idRibbonEmitter : public idDynamicEntity {
public:
    idRibbonEmitter();
    ~idRibbonEmitter() override;
    void Spawn() override;
    void Show() override;
    void Hide() override;
    void OnActivate(idEntity* activator) override;
    void Think() override;

    bool hidden;
    bool startOff;
    bool cycleTrigger;
    const idDeclRibbon* declRibbon;
    bool ribbonActive;
};

class idLensFlare : public idDynamicEntity {
public:
    idLensFlare();
    ~idLensFlare() override;
    void Hide() override;
    void Show() override;
    void OnActivate(idEntity* activator) override;
    void Spawn() override;
    void Think() override;
    void SetFlare();

    bool startOff;
    bool cycleTrigger;
    const idDeclFlare* declFlare;
    float quadSize;
    float fadeStart;
    float fadeEnd;
    idVec3 sunDirection;
    const idSoundShader* sunGlareSnd;
    const idDeclTable* sunGlareSndVolumeTbl;
    const idDeclTable* sunGlareSndPitchTbl;
    const idDeclEnv* sunGlareEnv;
    int sunGlareEnvFadeOutTime;
    float sunGlareEnvDotThreshold;
    const idDeclTable* colorModulateTbl;
    float modulateTimeScale;
    idVec3 occlusionQuadOffset;
    bool autospriteOcclusionQuad;
    float maxSunGlareScale;
    bool sunGlareEnvActive;
    bool flareInitialized;
};

class idGodRays : public idEntity {
public:
    idGodRays();
    ~idGodRays() override;
    void OnActivate(idEntity* activator) override;
    void Spawn() override;

    bool isRelativeToCamera;
    idVec3 direction;
    int sourceSize;
    int size;
    idColor raysColor;
    float colorScale;
    const idMaterial* texture;
    bool enabled;
};

class idFuncWind : public idEntity {
public:
    idFuncWind();
    void Show() override;
    void Hide() override;
    void OnActivate(idEntity* activator) override;
    void Spawn() override;
    void Think() override;

    idVec3 GetCurrentWindDirection() const;
    float GetCurrentWindStrength() const;
    void StartWind();

    const idSoundShader* sndWindLevel1;
    const idSoundShader* sndWindLevel2;
    const idSoundShader* sndWindLevel3;
    float minWindVolume;
    float maxWindVolume;
    int minGustDuration;
    int maxGustDuration;
    float minDistance;
    float maxDistance;
    float windStrengthStartVal;
    float windStrengthEndVal;
    float windAngle;
    bool startOff;
    bool cycleTrigger;
    bool globalWind;
    int fadeOut;
    idMiscWindInterpolation windStrength;
};

class idWindEmitter : public idEntity {
public:
    idWindEmitter();
    ~idWindEmitter() override;
    void OnActivate(idEntity* activator) override;
    void Spawn() override;
    void Think() override;

    int GetNextGustOverlay() const;
    idVec3 GetCurrentWindDirection() const;
    float GetCurrentWindStrength() const;
    void StartWind();

    const idSoundShader* sndBaseWind;
    const idSoundShader* sndGustOverlay[3];
    float gustWeight;
    float minWindVolume;
    float maxWindVolume;
    float minDistance;
    float maxDistance;
    int minGustDuration;
    int maxGustDuration;
    float windStrengthStartVal;
    float windStrengthEndVal;
    float windAngle;
    int gustCrossFadeTime;
    bool startOff;
    float fadeOut;
    bool cycleTrigger;
    idMiscWindInterpolation windStrength;
    int currGustOverlayIdx;
};

class idInventoryStorage : public idEntity {
public:
    idInventoryStorage();
    ~idInventoryStorage() override;
    void Spawn() override;

    idList<idMiscInventoryEntry, 5> inventory;
    idList<idMiscInventoryEntry, 5> startingInventory;
};

class idDebrisEntity : public idDynamicEntity {
public:
    idDebrisEntity();
    ~idDebrisEntity() override;
    void Spawn() override;
    void SetModelByName(const char* modelName) override;
    void SetModel(idRenderModel* model) override;
    void SetScale(const idVec3& newScale) override;
    void Think() override;

    int dieTime;
};

class idAnnouncementManager : public idEntity {
public:
    idAnnouncementManager();
    ~idAnnouncementManager() override;
    void Show() override;
    void Hide() override;
    void OnActivate(idEntity* activator) override;
    void Spawn() override;
    void Think() override;

    void Activate();
    void Deactivate();
    void PlayVoiceOver();
    void PlaySound();

    float startDelay;
    float startDelayVariance;
    bool startActive;
    float iterationDelay;
    float iterationVariance;
    float chancePerIteration;
    bool doVoiceOver;
    const idSoundShader* firstAnnouncement;
    idList<const idSoundShader*, 5> announcements;
    const idDeclVoiceOver* firstAnnouncementVO;
    idList<const idDeclVoiceOver*, 5> announcementsVO;
    idStrId talkerName;
    bool active;
    bool playedFirst;
    int nextPlayTime;
    int lastAnnouncement;
};

class idGuiEntity : public idDynamicEntity {
public:
    idGuiEntity();
    ~idGuiEntity() override;

    bool IsEverUsable(const idEntity* activator) const override;
    bool ModifyCrosshairInfo(const idEntity* activator,
        const void* focusTrace, int usableState,
        void* crosshairInfo) const override;
    bool Use(idEntity* activator, int usableState) override;
    void OnActivate(idEntity* activator) override;
    void Spawn() override;
    void Think() override;

    void UpdateGuiModel();
    void PauseThink();
    bool IsGuiActive() const;
    void Event_ResetGuiEntity();
    void Event_MoveToState(idGuiEntityInitialState state);
    void Event_EnableInteract(bool enable);
    void SetupGuiCallbacks();
    void SetFloat(const char* variableName, float value);
    void SetString(const char* variableName, const char* value);
    void UpdateGuiState();

    void CallbackReactivateUsable();
    bool CallbackTrigger(const char* entityName);
    bool CallbackTriggerTarget();
    void CallbackPlayGuiSound();
    bool CallbackPostEvent(const char* entityName, const char* eventName,
        const idList<idStr, 5>& arguments);

    bool used;
    idGuiEntityInitialState initialState;
    idGuiEntityInitialState activeState;
    idGuiEntityInitialState nextState;
    bool usable;
    idSWF* guiSwf;
    idRenderModelGui* guiModel;
    idEntity* target;
    bool initializedGuis;
    const idSoundShader* triggeredSound;
    bool disableSaves;
    bool guiActive;
};

class idPathCorner : public idEntity {
public:
    static idPathCorner* RandomPath(const idEntity* source,
        const idEntity* ignore);
    idPathCorner* Event_RandomPath();
};

class idFuncCloth : public idEntity {
public:
    struct sphereCollisionInfo_t {
        idVec3 center{0.0f, 0.0f, 0.0f};
        float radius = 0.0f;
    };

    idFuncCloth();
    ~idFuncCloth() override;
    void Spawn() override;
    void Think() override;
    void InitialSetup();

protected:
    void UpdateCloth();
    void UpdateCollisions();

public:
    idClothType clothType;
    idList<int, 5> attachPoints;
    const idDeclCloth* clothSystem;
    int widthOverride;
    int heightOverride;
    float hSpacingOverride;
    float vSpacingOverride;
    idList<sphereCollisionInfo_t, 5> sphereCollision;
    bool collidesWithPlayers;
    bool collidesWithAI;
    bool influencedByWind;
    bool influencedByBullets;
    idRenderModelCloth* clothModel;
    bool clothInitialized;
};

class idRegimeTile : public idDynamicEntity {
public:
    idRegimeTile();
    ~idRegimeTile() override;
    void Spawn() override;
    void OnActivate(idEntity* activator) override;

    float Damage(idEntity* inflictor, idEntity* attacker,
        const idDeclDamage* damage, float damageScale,
        const idVec3& direction, trace_t* trace);
    void TurnOn();
    void TurnOff();
    void Event_PowerDown();
    void Event_PowerUp();
    void Event_PostSpawn();

    int powerDownTime;
    const idSoundShader* sndPowerDown;
    const idSoundShader* sndReactivate;
    int propogationDelay;
    int fadeTime;
    int pulseOnTime;
    int pulseOffTime;
    float maxHealth;
    float nonEMPDamageScale;
    idDynamicEntity* healthReadout;
    bool startOff;
    bool pulseEnabled;
    bool ignoresPulse;
    bool damageable;
    bool takeTriggerDmgOnly;
    bool master;
    bool shouldFadeOnActivate;
    idRegimeTileType tileType;
    idList<idMiscRegimeChild, 5> tileChildren;
    float health;
    int childPropagationDelay;
    int nextActivateIdx;
    bool powered;
};

class idEntityImposter : public idDynamicEntity {
public:
    idEntityImposter();
    void Spawn() override;
    void Think() override;
    void Event_MimicEntity();

    idEntity* original;
    bool animated;
    bool mimicking;
};

class idCoopStartingInventory : public idEntity {
public:
    struct itemListElement_t {
        const idDeclInventory* item = nullptr;
        int count = 0;
    };

    idCoopStartingInventory();
    ~idCoopStartingInventory() override;
    void Spawn() override;
    void GiveItems(idPlayer* player);

    idList<itemListElement_t, 5> playerOneItemList;
    idList<itemListElement_t, 5> playerTwoItemList;
    bool mirrorPlayerOne;
};
