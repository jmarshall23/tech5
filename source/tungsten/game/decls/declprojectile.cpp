#include "game/decls/declprojectile.h"

namespace {
idDeclProjectileServices defaultProjectileServices;
idDeclProjectileServices* projectileServices = &defaultProjectileServices;
}

idDeclProjectileServices& Tungsten_DeclProjectileServices() {
    return *projectileServices;
}

void Tungsten_SetDeclProjectileServices(
        idDeclProjectileServices* const services) {
    projectileServices = services != nullptr
        ? services : &defaultProjectileServices;
}

idDeclInfoTemplate<idDeclProjectile> idDeclProjectile::resourceList(
    "projectile", "idDeclProjectile", "tdef");
idDeclInfoTemplate<idDeclProjectileImpactEffect>
    idDeclProjectileImpactEffect::resourceList(
        "projectileImpactEffect", "idDeclProjectileImpactEffect", "tdef");

// EA 0x82BD2FA8
idDeclProjectileImpactEffect::projectileImpactEffect_t::
        projectileImpactEffect_t()
    : decalMaterial()
    , decalSize(8.0f)
    , decalLifetime(8000)
    , decalDepth(4.0f)
    , decalAngle(0.0f)
    , decalQuad(false)
    , particleImpact(nullptr)
    , sndImpact(nullptr)
    , useSmokeSystem(false)
    , isBloody(false) {
}

// EA 0x82BD4520
idDeclProjectileImpactEffect::idDeclProjectileImpactEffect() = default;

// EA 0x82BCAD20
const idDeclProjectileImpactEffect::projectileImpactEffect_t*
idDeclProjectileImpactEffect::GetImpactEffectForMaterial(
        const int materialID) const {
    const projectileImpactEffect_t* result = &defaultEffect;
    if (Tungsten_DeclProjectileServices().UseDebugImpactEffect()) {
        result = &debugDefaultEffect;
    }

    switch (materialID) {
        case 1: result = &metalEffect; break;
        case 2: result = &stoneEffect; break;
        case 3: result = &fleshEffect; break;
        case 4: result = &woodEffect; break;
        case 5: result = &cardboardEffect; break;
        case 6: result = &liquidEffect; break;
        case 7: result = &glassEffect; break;
        case 8: result = &plasticEffect; break;
        case 9: result = &asphaltEffect; break;
        case 10: result = &dirtEffect; break;
        case 11: result = &concreteEffect; break;
        case 12: result = &foilageEffect; break;
        case 13: result = &linoleumEffect; break;
        case 14: result = &fabricEffect; break;
        case 15: result = &rubberEffect; break;
        case 16: result = &rockEffect; break;
        case 17: result = &steamPipeEffect; break;
        case 18: result = &waterPipeEffect; break;
        case 19: result = &armorEffect; break;
        case 20: result = &sludgeEffect; break;
        case 22: result = &metalHollow; break;
        case 23: result = &fleshPlayerEffect; break;
        case 25: result = &bloodPoolEffect; break;
        case 27: result = &mutantFleshEffect; break;
        case 28: result = &thickPaddingEffect; break;
        case 30: result = &ricketyMetal; break;
        case 31: result = &ricketyWood; break;
        case 32: result = &metalSheet; break;
        default: break;
    }

    const int goreMode = Tungsten_DeclProjectileServices().GetGoreMode();
    if (goreMode == 0 && result->isBloody) {
        return &bloodReplacementEffect;
    }
    if (goreMode == 2 && materialID == 3) {
        return &bloodReplacementEffect;
    }
    return result;
}

// EA 0x82BCAF08
idDeclProjectile::idDeclProjectile()
    : clientType(PROJCLIENT_NONE)
    , clientModelName()
    , clientMinAngularVelocity(0.0f, 0.0f, 0.0f)
    , clientMaxAngularVelocity(0.0f, 0.0f, 0.0f)
    , clientMaxSpeed(0.0f)
    , clientMinSpeed(0.0f)
    , hitscan(true)
    , hitscan_till_solid(false)
    , hitscan_through_vehicles(false)
    , hitscan_through_water(false)
    , deviation(0.0f)
    , ribbonEffect(false)
    , envFireSounds()
    , envOnlineFireSounds()
    , envLastShotSound()
    , envOnlineLastShotSound()
    , fireSound(nullptr)
    , onlineFireSound(nullptr)
    , lastShotSound(nullptr)
    , onlineLastShotSound(nullptr)
    , skipEndSoundOnEarlyRelease(false)
    , aiDodgeType(AI_DODGE_TYPE_MEDIUM)
    , aiEventDecl(nullptr)
    , playerAIEventDecl(nullptr)
    , explodeAIEventDecl(nullptr)
    , collideAIEventDecl(nullptr)
    , impactEffectTable(nullptr)
    , fxDecl(nullptr)
    , fxDeclQuad(nullptr)
    , impactInfluence()
    , influence()
    , damageDecl(nullptr)
    , damageFalloff(1.0f)
    , splashDamageDecl(nullptr)
    , electricDamageDecl(nullptr)
    , delayedProjectile(nullptr)
    , delayedProjectileDelayMS(0)
    , maxRange(8192)
    , minRange(0)
    , optimalRange(512)
    , maxOptimalRange(2048)
    , aimAssistRange(8192)
    , aimAssistZoomSnapScale(1.0f)
    , spread(1.0f)
    , spawnCount(1) {
    explodeAIEventDecl = Tungsten_DeclProjectileServices().ResolveAIEvent(
        "base/explosion/explosion");
    collideAIEventDecl = Tungsten_DeclProjectileServices().ResolveAIEvent(
        "base/sound/projectileimpact");

    notHitscanInfo.fireFromMuzzle = true;
    notHitscanInfo.entityDef = nullptr;
    notHitscanInfo.physicsProperties.density = 0.01f;
    notHitscanInfo.physicsProperties.linearFriction = 0.0f;
    notHitscanInfo.physicsProperties.angularFriction = 0.0f;
    notHitscanInfo.physicsProperties.contactFriction = 0.5f;
    notHitscanInfo.physicsProperties.linearFrictionWater = 0.1f;
    notHitscanInfo.physicsProperties.angularFrictionWater = 0.1f;
    notHitscanInfo.physicsProperties.bounciness = 0.6f;
    notHitscanInfo.physicsProperties.noGravity = false;
    notHitscanInfo.explodeSound = nullptr;
    notHitscanInfo.flySound = nullptr;
    notHitscanInfo.thrustDelay = 0;
    notHitscanInfo.thrustDelayVariance = 0;
    notHitscanInfo.useLocking = true;
    notHitscanInfo.fireAtPoint = false;
    notHitscanInfo.speed = 500.0f;
    notHitscanInfo.explodeOnImpact = false;
    notHitscanInfo.isRetrievable = true;
    notHitscanInfo.allowOnlyOne = false;
    notHitscanInfo.followDeployableRules = false;
    notHitscanInfo.inheritParentSpeed = true;
    notHitscanInfo.adjustStartForCollision = false;
    notHitscanInfo.adjustFireAngle = 0.0f;
    notHitscanInfo.breakAwaySnd = nullptr;
    notHitscanInfo.grenadeInfo.minDetonationDelay = 0;
    notHitscanInfo.grenadeInfo.maxDetonationDelay = 0;
    notHitscanInfo.grenadeInfo.countDownOnThrow = true;
    notHitscanInfo.grenadeInfo.cookable = false;
    notHitscanInfo.grenadeInfo.inheritParentSpeed = false;
    notHitscanInfo.grenadeInfo.warningSound = nullptr;
    notHitscanInfo.grenadeInfo.bounceSound = nullptr;
    notHitscanInfo.grenadeInfo.minSpeed = 256.0f;
    notHitscanInfo.grenadeInfo.maxSpeed = 1024.0f;
    notHitscanInfo.parabolicFlight = false;
    notHitscanInfo.minTrajectoryTime = 0.0f;
    notHitscanInfo.maxTrajectoryTime = 0.0f;
    notHitscanInfo.homingInfo.arcMinAngle = 0;
    notHitscanInfo.homingInfo.arcMaxAngle = 0;
    notHitscanInfo.homingInfo.heightLimit = 0.0f;
    notHitscanInfo.homingInfo.attackStyle =
        notHitscanInfo_t::homingInfo_t::GUIDED_RPG;

    tracerInfo.tracerMtr = nullptr;
    tracerInfo.tracerMtrQuad = nullptr;
    tracerInfo.tracers = 5;
    tracerInfo.doRandomTracers = false;
    tracerInfo.tracerSpeed = 2500.0f;
    tracerInfo.tracerLength = 48.0f;
    tracerInfo.tracerHeight = 4.0f;
    tracerInfo.tracerZoomedOffset.Set(10.0f, 0.0f, -5.0f);
    tracerInfo.sndTracer = nullptr;

    waterInteraction.allowWaterInteraction = false;
    waterInteraction.waterHitMagnitude = -30.0f;
    waterInteraction.waterHitRadius = 10.0f;
    waterInteraction.shouldIlluminateWater = false;
    waterInteraction.waterIlluminationRadius = 0.0f;
    waterInteraction.waterIlluminateTime = 0;

    weaponFeedBack.weaponKickInfo[0] = {0.35f, 0.7f, 17.0f, 5.0f};
    weaponFeedBack.weaponKickInfo[1] = {0.5f, 1.0f, 25.0f, 7.5f};
    weaponFeedBack.weaponKickInfo[2] = {0.75f, 25.0f, 25.0f, 14.0f};
    weaponFeedBack.weaponKickInfo[3] = {0.4f, 8.0f, 25.0f, 8.0f};
    // Retail leaves weaponKickInfo[4] untouched.
    weaponFeedBack.controllerShakeHighMag = 0.0f;
    weaponFeedBack.controllerShakeHighTime = 0;
    weaponFeedBack.controllerShakeLowMag = 0.0f;
    weaponFeedBack.controllerShakeLowTime = 0;
    weaponFeedBack.spreadAdditionPerShot = 0.25f;
    weaponFeedBack.spreadAdditionMax = 3.0f;
    weaponFeedBack.spreadRecoveryDelay = 100.0f;

    laserDotInfo.laserDotMtr = nullptr;
    laserDotInfo.laserDotSize = 350.0f;
    laserDotInfo.laserDotDepth = 15.0f;
    laserDotInfo.laserDotMinSizeScale = 0.25f;
    laserDotInfo.laserDotMaxSizeScale = 3.0f;
    laserDotInfo.laserDotMaxDistance = 5000.0f;
}
