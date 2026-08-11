#include "game/entities/explodable.h"

namespace {
idExplodableServices defaultExplodableServices;
idExplodableServices* explodableServices = &defaultExplodableServices;

constexpr int EXPLODABLE_FX_EXPLODE = 187;
constexpr int explodableSteamConditions[4] = {188, 189, 190, 191};
} // namespace

idBounds idExplodableServices::GetRenderModelBounds(
        const idExplodable& entity) const {
    return entity.bounds;
}
void idExplodableServices::InstallBoxClip(idExplodable& entity,
        const idBounds& bounds, const int contents) {
    entity.bounds = bounds;
    entity.contents = contents;
}
void idExplodableServices::DisablePhysics(idExplodable& entity) {
    entity.contents = 0;
    entity.DeactivatePhysics(7);
}
void idExplodableServices::SetBrokenModel(idExplodable& entity,
        idRenderModel* model) {
    entity.SetModel(model);
}
void idExplodableServices::UpdateVisuals(idExplodable& entity) {
    entity.idEntity::UpdateVisuals();
}
void idExplodableServices::PlayExplosionSound(idExplodable&,
        const idSoundShader*) {}
void idExplodableServices::StartEffect(idExplodable&, int,
        const idVec3&, const idMat3&, int) {}
void idExplodableServices::RadiusDamage(const idVec3&, idExplodable&,
        idEntity&, const idDeclDamage&, float) {}
bool idExplodableServices::HasScriptObject(const idExplodable&) const {
    return false;
}
bool idExplodableServices::HasOnExplodeFunction(
        const idExplodable&) const {
    return false;
}
void idExplodableServices::CallOnExplode(idExplodable&, idEntity&, bool) {}
idPresentable* idExplodableServices::AllocatePresentable(idExplodable&,
        idRenderModel*, int, const idDeclFX*) {
    return nullptr;
}
bool idExplodableServices::GetImpactTransform(const idExplodable& entity,
        const idVec3& direction, const trace_t*, idVec3& origin,
        idMat3& axis) const {
    origin = entity.origin;
    axis = entity.axis;
    idVec3 normal = direction;
    if (normal.NormalizeFast() > 0.0f) {
        axis[2] = normal;
        axis.OrthoNormalizeSelf();
    }
    return true;
}
void idExplodableServices::DamageFeedback(idEntity&, idExplodable&,
        idEntity*, const idDeclDamage&, float&) {}
void idExplodableServices::Warning(const char*) {}
int idExplodableServices::GetGameMilliseconds() const {
    return idEntity::Services().GetGameMilliseconds();
}

void idExplodable::SetServices(idExplodableServices* services) {
    explodableServices = services != nullptr ? services
        : &defaultExplodableServices;
}

idExplodableServices& idExplodable::Services() {
    return *explodableServices;
}

// Retail: 0x82C49F60 ?Spawn@idExplodable@@QAAXXZ
void idExplodable::Spawn() {
    contents = 128;
    if (clipModelInfo.type == idExplodableClipModelInfo::CLIPMODEL_BOX
            && clipModelInfo.offset.LengthSqr() > 0.0f) {
        idBounds clipBounds;
        const bool explicitSize = clipModelInfo.size.x != 0.0f
            || clipModelInfo.size.y != 0.0f
            || clipModelInfo.size.z != 0.0f;
        if (!explicitSize) {
            clipBounds = Services().GetRenderModelBounds(*this);
            clipBounds[0] = clipBounds[0] + clipModelInfo.offset;
            clipBounds[1] = clipBounds[1] + clipModelInfo.offset;
        } else {
            idVec3 size = clipModelInfo.size;
            for (int component = 0; component < 3; ++component) {
                if (size[component] <= 0.0f) {
                    size[component] = 1.0f;
                }
            }
            clipBounds[0] = clipModelInfo.offset - size * 0.5f;
            clipBounds[1] = clipModelInfo.offset + size * 0.5f;
        }
        Services().InstallBoxClip(*this, clipBounds, 128);
    }
    BecomeActive(1);
}

// Retail: 0x82C4A298 ?Explode@idExplodable@@AAAXPAVidEntity@@@Z
void idExplodable::Explode(idEntity* attacker) {
    const idVec3 explosionOrigin = origin;
    const idMat3 explosionAxis = axis;
    const int gameTime = Services().GetGameMilliseconds();
    Services().SetBrokenModel(*this, brokenModel);
    Services().DisablePhysics(*this);
    Services().UpdateVisuals(*this);
    Services().PlayExplosionSound(*this, soundExplosion);
    Services().StartEffect(*this, EXPLODABLE_FX_EXPLODE,
        explosionOrigin, explosionAxis, gameTime);

    idEntity* effectiveAttacker = attacker != nullptr ? attacker : this;
    if (damageDecl != nullptr) {
        Services().RadiusDamage(explosionOrigin, *this,
            *effectiveAttacker, *damageDecl, 1.0f);
    }
    if (callScriptOnExplode && Services().HasScriptObject(*this)
            && Services().HasOnExplodeFunction(*this)) {
        Services().CallOnExplode(*this, *effectiveAttacker, true);
    }
}

// Retail: 0x82C4A4A0 ?AllocPresentable@idExplodable@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
idPresentable* idExplodable::AllocPresentable(idRenderModel* model) {
    return Services().AllocatePresentable(*this, model,
        entityNumber, fxDecl);
}

// Retail: 0x82C4A540 ?Event_DisablePhysics@idExplodable@@AAA?AVeventVoid@@XZ
void idExplodable::Event_DisablePhysics() {
    Services().DisablePhysics(*this);
}

// Retail: 0x82C4AB98 ?Damage@idExplodable@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
float idExplodable::Damage(idEntity* inflictor, idEntity* attacker,
        const idDeclDamage* damageDef, const float damageScale,
        const idVec3& direction, trace_t* trace) {
    if (trace == nullptr || explodableHealth.IsDead_Impl()) {
        return 0.0f;
    }

    const bool explosiveDamage = damageDef != nullptr
        && (static_cast<int>(explodingDamageTypes)
            & static_cast<int>(damageDef->damageTypes)) != 0;
    if (!explosiveDamage || steamOnDamage) {
        idVec3 impactOrigin;
        idMat3 impactAxis(1.0f);
        if (Services().GetImpactTransform(*this, direction, trace,
                impactOrigin, impactAxis)) {
            Services().StartEffect(*this,
                explodableSteamConditions[fxLastSteamIndex],
                impactOrigin, impactAxis,
                Services().GetGameMilliseconds());
            fxLastSteamIndex = (fxLastSteamIndex + 1) % 4;
        }
    }

    if (!explosiveDamage) {
        return 0.0f;
    }

    float damageAmount = damageDef->DamageAmount() * damageScale;
    if (!explodableHealth.IsDead_Impl()) {
        if (attacker != nullptr) {
            Services().DamageFeedback(*attacker, *this, inflictor,
                *damageDef, damageAmount);
        } else {
            Services().Warning("NULL attacker in idExplodable::Damage");
        }
        float remainingDamage = 0.0f;
        if (explodableHealth.Damage_Impl(damageAmount, true,
                remainingDamage)) {
            Explode(attacker);
        }
    }
    return damageAmount;
}

// Retail: 0x82C4AFA8 ??0idExplodable@@QAA@XZ
idExplodable::idExplodable()
    : idEntity(),
      soundExplosion(nullptr),
      impactParticle(nullptr),
      brokenModel(nullptr),
      damageDecl(nullptr),
      fxDecl(nullptr),
      explodingDamageTypes(idDeclDamage::DAMAGETYPE_EXPLOSION),
      explodableHealth(),
      steamOnDamage(false),
      callScriptOnExplode(false),
      fxLastSteamIndex(0),
      clipModelInfo() {
    explodableHealth.components[0].cur = 0.0f;
    explodableHealth.components[0].max = 0.0f;
}

// Retail: 0x82C4B070 ?Think@idExplodable@@UAAXXZ
void idExplodable::Think() {
    idEntity::Think();
}

// Retail: 0x82C4B120 ?Hide@idExplodable@@UAAXXZ
void idExplodable::Hide() {
    idEntity::Hide();
    BecomeInactive(7);
}

// Retail: 0x82C4B1E0 ?Show@idExplodable@@UAAXXZ
void idExplodable::Show() {
    idEntity::Show();
    BecomeActive(1);
}
