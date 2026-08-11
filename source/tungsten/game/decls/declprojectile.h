#pragma once

#include "decls/decltypeinfo.h"
#include "game/effects/influencetrail_types.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"
#include "sound/soundworld.h"

class idDeclAiEvent;
class idDeclDamage;
class idDeclEntityDef;
class idDeclFX;
class idDeclParticle;
class idMaterial;
class idSoundShader;

struct projectileEnvSound {
    soundEnvType_t envType;
    int loopInterVal;
    const idSoundShader* sound0;
    const idSoundShader* sound0LoopingEndSound;
    const idSoundShader* sound1;
    const idSoundShader* sound2;
};

class idDeclProjectileServices {
public:
    virtual ~idDeclProjectileServices() = default;
    virtual bool UseDebugImpactEffect() const { return false; }
    virtual int GetGoreMode() const { return 1; }
    virtual const idDeclAiEvent* ResolveAIEvent(const char*) const {
        return nullptr;
    }
};

idDeclProjectileServices& Tungsten_DeclProjectileServices();
void Tungsten_SetDeclProjectileServices(idDeclProjectileServices* services);

class idDeclProjectileImpactEffect : public idDeclTypeInfo {
public:
    struct alignas(4) projectileImpactEffect_t {
        projectileImpactEffect_t();

        idList<const idMaterial*, 5> decalMaterial;
        float decalSize;
        int decalLifetime;
        float decalDepth;
        float decalAngle;
        bool decalQuad;
        const idDeclParticle* particleImpact;
        const idSoundShader* sndImpact;
        bool useSmokeSystem;
        bool isBloody;
    };

    idDeclProjectileImpactEffect();
    ~idDeclProjectileImpactEffect() override = default;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    const projectileImpactEffect_t* GetImpactEffectForMaterial(
        int materialID) const;

    projectileImpactEffect_t debugDefaultEffect;
    projectileImpactEffect_t defaultEffect;
    projectileImpactEffect_t metalEffect;
    projectileImpactEffect_t metalHollow;
    projectileImpactEffect_t metalSheet;
    projectileImpactEffect_t stoneEffect;
    projectileImpactEffect_t fleshEffect;
    projectileImpactEffect_t fleshPlayerEffect;
    projectileImpactEffect_t woodEffect;
    projectileImpactEffect_t cardboardEffect;
    projectileImpactEffect_t liquidEffect;
    projectileImpactEffect_t glassEffect;
    projectileImpactEffect_t plasticEffect;
    projectileImpactEffect_t asphaltEffect;
    projectileImpactEffect_t dirtEffect;
    projectileImpactEffect_t concreteEffect;
    projectileImpactEffect_t foilageEffect;
    projectileImpactEffect_t linoleumEffect;
    projectileImpactEffect_t fabricEffect;
    projectileImpactEffect_t rubberEffect;
    projectileImpactEffect_t rockEffect;
    projectileImpactEffect_t steamPipeEffect;
    projectileImpactEffect_t waterPipeEffect;
    projectileImpactEffect_t armorEffect;
    projectileImpactEffect_t sludgeEffect;
    projectileImpactEffect_t bloodPoolEffect;
    projectileImpactEffect_t mutantFleshEffect;
    projectileImpactEffect_t thickPaddingEffect;
    projectileImpactEffect_t ricketyMetal;
    projectileImpactEffect_t ricketyWood;
    projectileImpactEffect_t bloodReplacementEffect;

    static idDeclInfoTemplate<idDeclProjectileImpactEffect> resourceList;
};

class idDeclProjectile : public idDeclTypeInfo {
public:
    enum projectileClientPredictive_t : int {
        PROJCLIENT_NONE = 0,
        PROJCLIENT_GRENADE = 1,
        PROJCLIENT_ROCKET = 2,
        PROJCLIENT_HOMING = 3
    };

    enum aiDodgeType_t : int {
        AI_DODGE_TYPE_MELEE = 0,
        AI_DODGE_TYPE_LIGHT = 1,
        AI_DODGE_TYPE_MEDIUM = 2,
        AI_DODGE_TYPE_HEAVY_CLOSE_RANGE = 3,
        AI_DODGE_TYPE_HEAVY_MEDIUM_RANGE = 4,
        AI_DODGE_TYPE_HEAVY_LONG_RANGE = 5
    };

    enum projectileSoundEvent_t : int {
        PROJSOUND_NONE = 0,
        PROJSOUND_NORMAL = 1,
        PROJSOUND_SILENCED = 2
    };

    struct notHitscanInfo_t {
        struct alignas(4) physicsProperties_t {
            float density;
            float linearFriction;
            float angularFriction;
            float contactFriction;
            float linearFrictionWater;
            float angularFrictionWater;
            float bounciness;
            bool noGravity;
        };

        struct explosion_t {
            int minDetonationDelay;
            int maxDetonationDelay;
            bool countDownOnThrow;
            bool cookable;
            bool inheritParentSpeed;
            const idSoundShader* warningSound;
            const idSoundShader* bounceSound;
            float minSpeed;
            float maxSpeed;
        };

        struct homingInfo_t {
            enum attackStyle_t : int {
                CLUSTER_BOMB = 0,
                GUIDED_RPG = 1,
                JAVELIN = 2
            };

            int arcMinAngle;
            int arcMaxAngle;
            float heightLimit;
            attackStyle_t attackStyle;
        };

        bool fireFromMuzzle;
        const idDeclEntityDef* entityDef;
        physicsProperties_t physicsProperties;
        const idSoundShader* explodeSound;
        const idSoundShader* flySound;
        int thrustDelay;
        int thrustDelayVariance;
        bool useLocking;
        bool fireAtPoint;
        float speed;
        bool explodeOnImpact;
        bool isRetrievable;
        bool allowOnlyOne;
        bool followDeployableRules;
        bool inheritParentSpeed;
        bool adjustStartForCollision;
        float adjustFireAngle;
        const idSoundShader* breakAwaySnd;
        explosion_t grenadeInfo;
        bool parabolicFlight;
        float minTrajectoryTime;
        float maxTrajectoryTime;
        homingInfo_t homingInfo;
    };

    struct tracerInfo_t {
        const idMaterial* tracerMtr;
        const idMaterial* tracerMtrQuad;
        int tracers;
        bool doRandomTracers;
        float tracerSpeed;
        float tracerLength;
        float tracerHeight;
        idVec3 tracerZoomedOffset;
        const idSoundShader* sndTracer;
    };

    struct waterInteraction_t {
        bool allowWaterInteraction;
        float waterHitMagnitude;
        float waterHitRadius;
        bool shouldIlluminateWater;
        float waterIlluminationRadius;
        int waterIlluminateTime;
    };

    struct weaponFeedBack_t {
        struct weaponKikInfo_t {
            float kick;
            float maxKick;
            float recoilSpeed;
            float recoverySpeed;
        };

        weaponKikInfo_t weaponKickInfo[5];
        float controllerShakeHighMag;
        int controllerShakeHighTime;
        float controllerShakeLowMag;
        int controllerShakeLowTime;
        float spreadAdditionPerShot;
        float spreadAdditionMax;
        float spreadRecoveryDelay;
    };

    struct laserDotInfo_t {
        const idMaterial* laserDotMtr;
        float laserDotSize;
        float laserDotDepth;
        float laserDotMinSizeScale;
        float laserDotMaxSizeScale;
        float laserDotMaxDistance;
    };

    idDeclProjectile();
    ~idDeclProjectile() override = default;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    projectileClientPredictive_t clientType;
    idStr clientModelName;
    idVec3 clientMinAngularVelocity;
    idVec3 clientMaxAngularVelocity;
    float clientMaxSpeed;
    float clientMinSpeed;
    bool hitscan;
    bool hitscan_till_solid;
    bool hitscan_through_vehicles;
    bool hitscan_through_water;
    float deviation;
    bool ribbonEffect;
    idList<projectileEnvSound, 5> envFireSounds;
    idList<projectileEnvSound, 5> envOnlineFireSounds;
    idList<projectileEnvSound, 5> envLastShotSound;
    idList<projectileEnvSound, 5> envOnlineLastShotSound;
    const idSoundShader* fireSound;
    const idSoundShader* onlineFireSound;
    const idSoundShader* lastShotSound;
    const idSoundShader* onlineLastShotSound;
    bool skipEndSoundOnEarlyRelease;
    aiDodgeType_t aiDodgeType;
    const idDeclAiEvent* aiEventDecl;
    const idDeclAiEvent* playerAIEventDecl;
    const idDeclAiEvent* explodeAIEventDecl;
    const idDeclAiEvent* collideAIEventDecl;
    const idDeclProjectileImpactEffect* impactEffectTable;
    const idDeclFX* fxDecl;
    const idDeclFX* fxDeclQuad;
    idEntityInfluenceTrail impactInfluence;
    idEntityInfluenceTrail influence;
    notHitscanInfo_t notHitscanInfo;
    const idDeclDamage* damageDecl;
    float damageFalloff;
    const idDeclDamage* splashDamageDecl;
    const idDeclDamage* electricDamageDecl;
    const idDeclProjectile* delayedProjectile;
    int delayedProjectileDelayMS;
    int maxRange;
    int minRange;
    int optimalRange;
    int maxOptimalRange;
    int aimAssistRange;
    float aimAssistZoomSnapScale;
    float spread;
    int spawnCount;
    tracerInfo_t tracerInfo;
    waterInteraction_t waterInteraction;
    weaponFeedBack_t weaponFeedBack;
    laserDotInfo_t laserDotInfo;

    static idDeclInfoTemplate<idDeclProjectile> resourceList;
};

static_assert(sizeof(projectileEnvSound) == 24,
    "Recovered projectile environment-sound ABI changed");
static_assert(sizeof(idDeclProjectileImpactEffect::projectileImpactEffect_t)
        == 48, "Recovered projectile impact-effect payload ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclProjectileImpactEffect) == 1552,
    "Recovered projectile impact-effect declaration ABI changed");
static_assert(sizeof(idDeclProjectile::notHitscanInfo_t) == 136,
    "Recovered non-hitscan projectile ABI changed");
static_assert(sizeof(idDeclProjectile::weaponFeedBack_t) == 108,
    "Recovered projectile weapon-feedback ABI changed");
static_assert(sizeof(idDeclProjectile) == 700,
    "Recovered projectile declaration ABI changed");
#endif
