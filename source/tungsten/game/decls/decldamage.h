#pragma once

#include "decls/declfxtypes.h"
#include "decls/decltypeinfo.h"
#include "idlib/color.h"
#include "idlib/math/vector.h"

class idDeclGoreBehavior;
class idDeclInventory;
class idDeclTable;
class idMaterial;
class idSoundShader;

enum damageIntensity_t : int {
    DAMAGEINTENSITY_NONE = 0,
    DAMAGEINTENSITY_LIGHT = 1,
    DAMAGEINTENSITY_MEDIUM = 2,
    DAMAGEINTENSITY_HEAVY = 3,
    DAMAGEINTENSITY_MAX = 4
};

enum specialDeath_t : int {
    DEATH_INSTANT = 0,
    DEATH_IMPULSE_1 = 1,
    DEATH_PULL_FROM_CAMERA = 2
};

enum idHandsHitReactionType_t : int {
    HITREACTION_NONE = 0,
    HITREACTION_GENERIC = 1,
    HITREACTION_MELEE = 2,
    HITREACTION_EXPLOSIVE = 3,
    HITREACTION_FIRE = 4
};

enum idPlayerBodyReactionType_t : int {
    PLAYER_BODY_REACTION_NONE = 0,
    PLAYER_BODY_REACTION_DEATH = 1,
    PLAYER_BODY_REACTION_BULLET = 2,
    PLAYER_BODY_REACTION_MELEE = 3,
    PLAYER_BODY_REACTION_FIRE = 4,
    PLAYER_BODY_REACTION_ELECTRICAL = 5,
    PLAYER_BODY_REACTION_FALL = 6,
    PLAYER_BODY_REACTION_CRUSH = 7,
    PLAYER_BODY_REACTION_EXPLOSIVE = 8,
    PLAYER_BODY_REACTION_CHAINSAW = 9,
    PLAYER_BODY_REACTION_ACID = 10,
    PLAYER_BODY_REACTION_HELLSPIKE = 11,
    PLAYER_BODY_REACTION_PLASMA = 12,
    PLAYER_BODY_REACTION_BFG = 13,
    PLAYER_BODY_REACTION_SPIRITWEB = 14,
    PLAYER_BODY_REACTION_POISON_GAS = 15,
    PLAYER_BODY_REACTION_SUCCUBUS_TAKEOFF = 16,
    PLAYER_BODY_REACTION_MAP_SPECIFIC = 17
};

struct idPlayerBodyReactionDescriptor_t {
    idAtomicString name;
    idPlayerBodyReactionType_t type{PLAYER_BODY_REACTION_NONE};
    bool useAlive{false};
    bool useDead{false};
    bool throwsPlayer{false};
};

struct idVisionDamageElement {
    float impulseScale{0.0f};
    float impulseScaleY{0.0f};
    float impulseScaleZ{0.0f};
    float duration{0.0f};
    float damageMax{0.0f};
    const idDeclTable* table{nullptr};
    idColor color;
};

class idDeclVisionDamage : public idDeclTypeInfo {
public:
    ~idDeclVisionDamage() override = default;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    idVisionDamageElement contrast;
    idVisionDamageElement brightness;
    idVisionDamageElement brightnessAdd;
    idVisionDamageElement saturation;
    idVisionDamageElement tintRed;
    idVisionDamageElement tintGreen;
    idVisionDamageElement tintBlue;
    idVisionDamageElement doubleVision;
    idVisionDamageElement blur;
    idVisionDamageElement negative;
    idVisionDamageElement chromaticAberration;
    idVisionDamageElement radialBlur;
    idVisionDamageElement distortion;
    idVisionDamageElement colorDodge;
    idVisionDamageElement colorBurn;
    bool interruptible{false};
    bool applyAfterDeath{false};
    static idDeclInfoTemplate<idDeclVisionDamage> resourceList;
};

class idDeclDamageServices {
public:
    virtual ~idDeclDamageServices() = default;
    virtual float RandomFloat() = 0;
};

void Tungsten_SetDeclDamageServices(idDeclDamageServices* services);
idDeclDamageServices& Tungsten_DeclDamageServices();

class idDeclDamage : public idDeclTypeInfo {
public:
    enum damageType_t : int {
        DAMAGETYPE_NONE = 0,
        DAMAGETYPE_GENERIC = 1,
        DAMAGETYPE_MELEE = 2,
        DAMAGETYPE_PISTOL = 4,
        DAMAGETYPE_RIFLE = 8,
        DAMAGETYPE_SHOTGUN = 0x10,
        DAMAGETYPE_TURRET = 0x20,
        DAMAGETYPE_VEHICLE_RAM = 0x40,
        DAMAGETYPE_LASER = 0x80,
        DAMAGETYPE_EXPLOSION = 0x100,
        DAMAGETYPE_FIRE = 0x200,
        DAMAGETYPE_ELECTRIC = 0x400,
        DAMAGETYPE_EDGED = 0x1000,
        DAMAGETYPE_BLUNT = 0x2000,
        DAMAGETYPE_LASER_CUTTING = 0x4000,
        DAMAGETYPE_NO_DAMAGE = 0x8000,
        DAMAGETYPE_ALL = 0x7FFFFFFF
    };
    enum goreType_t : int {
        GORETYPE_NONE = 0,
        GORETYPE_DECAPITATION = 1,
        GORETYPE_DISMEMBER_ARMS = 2,
        GORETYPE_DISMEMBER_LEGS = 4,
        GORETYPE_GIB = 8,
        GORETYPE_HEAD_EXPLODE = 0x10,
        GORETYPE_SMALL_WOUND = 0x20,
        GORETYPE_BIG_WOUND = 0x40,
        GORETYPE_TORSO_SAW = 0x80,
        GORETYPE_BFG = 0x100,
        GORETYPE_ANY = 0x7FFFFFFF
    };
    enum damageSource_t : int {
        DAMAGESRC_UNKNOWN = 0,
        DAMAGESRC_BULLET = 1,
        DAMAGESRC_MELEE = 2,
        DAMAGESRC_FIRE = 4,
        DAMAGESRC_ELECTRICAL = 8,
        DAMAGESRC_FALL = 0x10,
        DAMAGESRC_CRUSH = 0x20,
        DAMAGESRC_EXPLOSIVE = 0x40,
        DAMAGESRC_CHAINSAW = 0x80,
        DAMAGESRC_ACID = 0x100,
        DAMAGESRC_HELLSPIKE = 0x200,
        DAMAGESRC_PLASMA = 0x400,
        DAMAGESRC_BFG = 0x800,
        DAMAGESRC_SPIRITWEB = 0x1000,
        DAMAGESRC_POISON_GAS = 0x2000,
        DAMAGESRC_SYNCED_FATALITY = 0x4000
    };
    struct damageScreenEffectParms_t {
        float screenDamageTime{0.0f};
        idMaterial* screenDamageMtr{nullptr};
        idVec2 screenDamageSize{idVec2(0.0f, 0.0f)};
        idVec2 offsetPctX{idVec2(0.0f, 0.0f)};
        idVec2 offsetPctY{idVec2(0.0f, 0.0f)};
        idVec2 distribPctX{idVec2(0.0f, 0.0f)};
        idVec2 distribPctY{idVec2(0.0f, 0.0f)};
        idVec2 driftYAmount{idVec2(0.0f, 0.0f)};
        idVec2 delay{idVec2(0.0f, 0.0f)};
        float fadeOutTime{0.0f};
        int screenDamageFrames{0};
        int numQuads{0};
    };
    struct damageScreenEffect_t {
        damageScreenEffectParms_t parms;
        float damagePct{0.0f};
        float radius{0.0f};
    };
    struct damageFeedbackScreenEffects_t {
        damageScreenEffect_t feedbackSmall;
        damageScreenEffect_t feedbackMedium;
        damageScreenEffect_t feedbackLarge;
        damageScreenEffect_t feedbackGib;
    };
    struct playerDamageScreenEffects_t {
        damageScreenEffect_t damageSmall;
        damageScreenEffect_t damageMedium;
        damageScreenEffect_t damageLarge;
    };

    idDeclDamage();
    ~idDeclDamage() override;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    void Parse(idParser* parser) override;
    float DamageAmount() const;

    idStr damageName;
    damageType_t damageTypes;
    goreType_t goreTypes;
    damageSource_t damageSource;
    idHandsHitReactionType_t handsHitReactionType;
    idPlayerBodyReactionDescriptor_t playerBodyReactionDescriptor;
    const idDeclVisionDamage* visionDamage;
    float minDamage;
    float maxDamage;
    float vehicleDamageScale;
    float selfDamageScale;
    float playerDamageScale;
    bool damageIsCurrentHealth;
    bool ignoreGodMode;
    bool ignoreArmor;
    bool ignorePlayer;
    bool ignoreArmoredBreakables;
    bool ignoreFriendlyFire;
    bool isMelee;
    bool burning;
    bool noSound;
    bool stuns;
    bool instantRagdoll;
    bool ragdollOnDeath;
    bool coopSpecial;
    bool simplifiedRadiusDamage;
    int knockBack;
    int knockUp;
    float selfKnockbackScale;
    bool absoluteknockBack;
    float kickTime;
    float kickAmplitude;
    idVec3 kickDir;
    float radius;
    int radiusInner;
    int radiusOuterDamageStrength;
    float ragdollImpulseMag;
    float vehicleImpulseMag;
    float blur;
    float blurTime;
    float doubleVision;
    float doubleVisionTime;
    fxCondition_t hitFXStartCondition;
    damageIntensity_t intensity;
    idSoundShader* damageSound;
    bool isStealthy;
    specialDeath_t specialDeathType;
    bool friendlyFire;
    bool knocksOffArmor;
    damageFeedbackScreenEffects_t feedbackScreenEffects;
    playerDamageScreenEffects_t playerDamageScreenEffects;
    const idMaterial* damageIcon;
    idDeclGoreBehavior* declGoreBehavior;
    static idDeclInfoTemplate<idDeclDamage> resourceList;
};

class idDeclDamageBoostItem;

