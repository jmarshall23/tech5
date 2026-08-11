#include "game/decls/decldamage.h"

#include <cstdint>

namespace {

class DefaultDamageServices final : public idDeclDamageServices {
public:
    float RandomFloat() override {
        seed = 1664525u * seed + 1013904223u;
        return static_cast<float>((seed >> 10) & 0x7FFFu)
            * (1.0f / 32767.0f);
    }
private:
    std::uint32_t seed{0};
};

DefaultDamageServices defaultServices;
idDeclDamageServices* damageServices = &defaultServices;

} // namespace

// Retail registration storage is initialized by gamedecls.cpp in the
// original binary and lives beside its owning declarations in this recovery.
idDeclInfoTemplate<idDeclDamage> idDeclDamage::resourceList(
    "damage", "idDeclDamage", "tdef");
idDeclInfoTemplate<idDeclVisionDamage> idDeclVisionDamage::resourceList(
    "visionDamage", "idDeclVisionDamage", "tdef");

void Tungsten_SetDeclDamageServices(idDeclDamageServices* services) {
    damageServices = services != nullptr ? services : &defaultServices;
}

idDeclDamageServices& Tungsten_DeclDamageServices() {
    return *damageServices;
}

// EA 0x82BBD598
void idDeclDamage::Parse(idParser* parser) {
    idDeclTypeInfo::Parse(parser);
}

// EA 0x82BBD860
idDeclDamage::~idDeclDamage() = default;

// EA 0x82BBD8F0
float idDeclDamage::DamageAmount() const {
    return minDamage + Tungsten_DeclDamageServices().RandomFloat()
        * (maxDamage - minDamage);
}

// EA 0x82BBD958
idDeclDamage::idDeclDamage()
    : damageName("default")
    , damageTypes(DAMAGETYPE_GENERIC)
    , goreTypes(GORETYPE_NONE)
    , damageSource(DAMAGESRC_UNKNOWN)
    , handsHitReactionType(HITREACTION_GENERIC)
    , playerBodyReactionDescriptor()
    , visionDamage(nullptr)
    , minDamage(1.0f)
    , maxDamage(1.0f)
    , vehicleDamageScale(1.0f)
    , selfDamageScale(1.0f)
    , playerDamageScale(1.0f)
    , damageIsCurrentHealth(false)
    , ignoreGodMode(false)
    , ignoreArmor(false)
    , ignorePlayer(false)
    , ignoreArmoredBreakables(false)
    , ignoreFriendlyFire(false)
    , isMelee(false)
    , burning(false)
    , noSound(false)
    , stuns(false)
    , instantRagdoll(false)
    , ragdollOnDeath(false)
    , coopSpecial(false)
    , simplifiedRadiusDamage(false)
    , knockBack(0)
    , knockUp(0)
    , selfKnockbackScale(1.0f)
    , absoluteknockBack(false)
    , kickTime(150.0f)
    , kickAmplitude(0.8f)
    , kickDir(0.0f, 1.0f, 0.0f)
    , radius(0.0f)
    , radiusInner(0)
    , radiusOuterDamageStrength(0)
    , ragdollImpulseMag(0.0f)
    , vehicleImpulseMag(0.0f)
    , blur(1.5f)
    , blurTime(150.0f)
    , doubleVision(0.1f)
    , doubleVisionTime(130.0f)
    , hitFXStartCondition(static_cast<fxCondition_t>(198))
    , intensity(DAMAGEINTENSITY_NONE)
    , damageSound(nullptr)
    , isStealthy(false)
    , specialDeathType(DEATH_INSTANT)
    , friendlyFire(true)
    , knocksOffArmor(true)
    , feedbackScreenEffects()
    , playerDamageScreenEffects()
    , damageIcon(nullptr)
    , declGoreBehavior(nullptr) {
    feedbackScreenEffects.feedbackSmall.damagePct = 0.1f;
    feedbackScreenEffects.feedbackMedium.damagePct = 0.2f;
    feedbackScreenEffects.feedbackLarge.damagePct = 0.3f;
}
