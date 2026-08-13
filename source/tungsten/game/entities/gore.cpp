#include "game/entities/gore.h"

#include "game/entities/entity.h"

#include <algorithm>
#include <cmath>

namespace {
idGoreComponentServices defaultGoreServices;
idGoreComponentServices* goreServices = &defaultGoreServices;

idVec3 ZeroVector() { return idVec3(0.0f, 0.0f, 0.0f); }

idVec3 Add(const idVec3& a, const idVec3& b) {
    return idVec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

idVec3 Scale(const idVec3& value, const float scale) {
    return idVec3(value.x * scale, value.y * scale, value.z * scale);
}

idVec3 Normalize(const idVec3& value) {
    const float lengthSquared = value.x * value.x
        + value.y * value.y + value.z * value.z;
    if (lengthSquared <= 1.0e-12f) return ZeroVector();
    return Scale(value, 1.0f / std::sqrt(lengthSquared));
}

bool AtomicEqual(const idAtomicString& first,
        const idAtomicString& second) {
    return first == second;
}

bool Contains(const idList<idAtomicString, 5>& list,
        const idAtomicString& value) {
    for (int i = 0; i < list.Num(); ++i) {
        if (AtomicEqual(list[i], value)) return true;
    }
    return false;
}
} // namespace

int idGoreComponentServices::GetGameMilliseconds() const {
    return idEntity::Services().GetGameMilliseconds();
}
bool idGoreComponentServices::IsGoreEnabled() const { return true; }
bool idGoreComponentServices::IsMultiplayer() const { return false; }
bool idGoreComponentServices::IsPresentableValid(
        const idPresentableAnimatedEntity* value) const {
    return value != nullptr;
}
bool idGoreComponentServices::IsPresentableDead(
        const idPresentableAnimatedEntity*) const { return false; }
float idGoreComponentServices::GetPresentableFade(
        const idPresentableAnimatedEntity*) const { return 1.0f; }
void idGoreComponentServices::GetPresentableTransform(
        const idPresentableAnimatedEntity*, idVec3& origin,
        idMat3& axis) const {
    origin = ZeroVector();
    axis = idMat3(1.0f);
}
void idGoreComponentServices::SetDeathFadeOpacity(
        idPresentableAnimatedEntity*, float) {}
void idGoreComponentServices::SetClipSphere(
        idPresentableAnimatedEntity*, int, const idVec4&) {}
void idGoreComponentServices::SetClipEllipsoid(
        idPresentableAnimatedEntity*, const idVec3&, const idMat3&) {}
void idGoreComponentServices::ClearClipShape(
        idPresentableAnimatedEntity*, int) {}
void idGoreComponentServices::MarkClipParmsChanged(
        idPresentableAnimatedEntity*) {}
bool idGoreComponentServices::TraceFloor(
        const idVec3&, const idVec3&, idGoreFloorTraceResult&) {
    return false;
}
void idGoreComponentServices::SetClothFloor(
        void*, const idVec3&, const idVec3&) {}
void* idGoreComponentServices::AllocateCloth(
        idPresentableAnimatedEntity*, int, const idAtomicString&) {
    return nullptr;
}
void idGoreComponentServices::FreeCloth(void*) {}
bool idGoreComponentServices::ValidateGorePiece(
        idPresentableAnimatedEntity*, const idGorePieceInfo_t&,
        int) const { return true; }
void idGoreComponentServices::RegisterSpawnable(
        const void*, bool, idPresentableAnimatedEntity*) {}
void idGoreComponentServices::SetMeshKit(
        idPresentableAnimatedEntity*, goreKitComponent_t,
        const idAtomicString&, bool) {}
void idGoreComponentServices::ZeroJoint(
        idPresentableAnimatedEntity*, const idAtomicString&, bool) {}
void idGoreComponentServices::BreakConstraint(
        idPresentableAnimatedEntity*, const idAtomicString&) {}
void idGoreComponentServices::StopVoice(idPresentableAnimatedEntity*) {}
void idGoreComponentServices::StartGoreFX(
        idPresentableAnimatedEntity*, int, const idAtomicString&) {}
void idGoreComponentServices::StopGoreFX(
        idPresentableAnimatedEntity*, int) {}
void idGoreComponentServices::SpawnGoreEntity(
        const void*, bool, const idVec3&, const idMat3&, const idVec3&,
        goreSpawnImpulseBehavior_t) {}
void idGoreComponentServices::ApplyMorph(
        idPresentableAnimatedEntity*, int, bool) {}
int idGoreComponentServices::GetDamageGoreTypes(
        const idDeclDamage*) const { return GORETYPE_NONE; }
float idGoreComponentServices::GetDamageRagdollImpulse(
        const idDeclDamage*) const { return 0.0f; }
bool idGoreComponentServices::HasBodyExplosion(
        const idDeclDamage*) const { return false; }
int idGoreComponentServices::GetBodyExplosionMaxPieces(
        const idDeclDamage*) const { return 0; }
int idGoreComponentServices::GetBodyExplosionMaxWounds(
        const idDeclDamage*) const { return 0; }
idAtomicString idGoreComponentServices::GetDamageGroupName(
        const idDamageGroup*) const { return idAtomicString(); }
int idGoreComponentServices::GetTestGoreIndex() { return -1; }
int idGoreComponentServices::RandomInt(const int maximum) {
    return maximum > 0 ? 0 : -1;
}
void idGoreComponentServices::ActivateBFGBreakable(
        const idDeclGore&, idPresentableAnimatedEntity*,
        const idDeclDamage*, const idVec3&, const idVec3&) {}

void idGoreComponent::SetServices(idGoreComponentServices* services) {
    goreServices = services != nullptr ? services : &defaultGoreServices;
}

idGoreComponentServices& idGoreComponent::Services() {
    return *goreServices;
}

// Retail: 0x82C5DA50
idGoreComponent::idGoreComponent()
    : presentable(nullptr), goreDecl(nullptr), deathTime(-1) {}

// Retail: 0x82C5DBB8
idGoreComponent::~idGoreComponent() {
    for (int i = 0; i < goredPiecesInUse.Num(); ++i) {
        if (goredPiecesInUse[i].clothSim != nullptr) {
            Services().FreeCloth(goredPiecesInUse[i].clothSim);
            goredPiecesInUse[i].clothSim = nullptr;
        }
    }
}

// Retail: 0x82C5B748
void idGoreComponent::UpdateDeathFade() {
    if (goreDecl == nullptr || !Services().IsPresentableValid(presentable)) {
        return;
    }
    const float fadeStartSeconds =
        goreDecl->deathFadeInfo.deathFadeStartTime;
    if (fadeStartSeconds < 0.0f) return;
    if (deathTime < 0) {
        if (Services().IsPresentableDead(presentable)) {
            deathTime = Services().GetGameMilliseconds();
        }
        return;
    }
    const float fadeBegin = static_cast<float>(deathTime)
        + fadeStartSeconds * 1000.0f;
    const float now = static_cast<float>(Services().GetGameMilliseconds());
    if (now <= fadeBegin) return;
    const float fadeLength = goreDecl->deathFadeInfo.deathFadeLength * 1000.0f;
    const float amount = fadeLength > 0.0f
        ? (std::min)(1.0f, (std::max)(0.0f, (now - fadeBegin) / fadeLength))
        : 1.0f;
    Services().SetDeathFadeOpacity(presentable, 1.0f - amount);
}

// Retail: 0x82C5B8E0
void idGoreComponent::SetClipSphereRenderParms(
        const idVec4& woundSphere, const int clipSphereIndex) {
    if (wounds.Num() == 0) {
        wounds.SetNum(11);
        for (int i = 0; i < wounds.Num(); ++i) wounds[i] = -1;
    }
    int slot = -1;
    for (int i = 0; i < 10; ++i) {
        if (wounds[i] == -1) { slot = i; break; }
    }
    if (slot < 0) return;
    wounds[slot] = clipSphereIndex;
    Services().SetClipSphere(presentable, slot, woundSphere);
    Services().MarkClipParmsChanged(presentable);
}

// Retail: 0x82C5BB20
void idGoreComponent::SetClipEllipsoidRenderParms(
        const idVec3& position, const idMat3& axis,
        const int clipEllipsoidIndex) {
    if (wounds.Num() == 0) {
        wounds.SetNum(11);
        for (int i = 0; i < wounds.Num(); ++i) wounds[i] = -1;
    }
    if (wounds[10] != -1) return;
    wounds[10] = clipEllipsoidIndex;
    Services().SetClipEllipsoid(presentable, position, axis);
    Services().MarkClipParmsChanged(presentable);
}

// Retail: 0x82C5BD30
void idGoreComponent::UpdateFloorTrace() {
    bool hasCloth = false;
    for (int i = 0; i < goredPiecesInUse.Num(); ++i) {
        hasCloth = hasCloth || goredPiecesInUse[i].clothSim != nullptr;
    }
    if (!hasCloth || !Services().IsPresentableValid(presentable)) return;

    idVec3 origin;
    idMat3 axis;
    Services().GetPresentableTransform(presentable, origin, axis);
    const idVec3 directions[5] = {
        idVec3(-1.0f, -1.0f, -1.0f), idVec3(1.0f, -1.0f, -1.0f),
        idVec3(-1.0f, 1.0f, -1.0f), idVec3(1.0f, 1.0f, -1.0f),
        idVec3(0.0f, 0.0f, -1.0f)
    };
    idVec3 averagePosition = ZeroVector();
    idVec3 averageNormal = ZeroVector();
    int hits = 0;
    for (int i = 0; i < 5; ++i) {
        idGoreFloorTraceResult result;
        const idVec3 end = Add(origin, Scale(directions[i], 128.0f));
        if (Services().TraceFloor(origin, end, result) && result.hit) {
            averagePosition = Add(averagePosition, result.position);
            averageNormal = Add(averageNormal, result.normal);
            ++hits;
        }
    }
    if (hits == 0) return;
    averagePosition = Scale(averagePosition, 1.0f / static_cast<float>(hits));
    averageNormal = Normalize(averageNormal);
    for (int i = 0; i < goredPiecesInUse.Num(); ++i) {
        if (goredPiecesInUse[i].clothSim != nullptr) {
            Services().SetClothFloor(goredPiecesInUse[i].clothSim,
                averagePosition, averageNormal);
        }
    }
}

// Retail: 0x82C5C268
void idGoreComponent::DisableCloth(const int pieceInUse,
        const idVec3& position, const idVec3& impulse) {
    if (pieceInUse < 0 || pieceInUse >= goredPiecesInUse.Num()) return;
    goredPiecesInUse_t& runtime = goredPiecesInUse[pieceInUse];
    if (runtime.clothSim == nullptr) return;
    if (goreDecl != nullptr && runtime.goreIndex >= 0
            && runtime.goreIndex < goreDecl->gorePieces.Num()) {
        const idGorePieceInfo_t& piece =
            goreDecl->gorePieces[runtime.goreIndex];
        if (piece.cloth.gibEntity != nullptr) {
            idVec3 origin;
            idMat3 axis;
            Services().GetPresentableTransform(presentable, origin, axis);
            Services().SpawnGoreEntity(piece.cloth.gibEntity,
                piece.cloth.EntityToSpawnIsABreakable(), position, axis,
                impulse, piece.spawnedEntityImpulseBehavior);
        }
    }
    Services().FreeCloth(runtime.clothSim);
    runtime.clothSim = nullptr;
}

// Retail: 0x82C5C668
void idGoreComponent::DisableGorePiece(const int goreIndex,
        const idVec3& position, const idVec3& impulse) {
    if (goreDecl == nullptr || goreIndex < 0
            || goreIndex >= goreDecl->gorePieces.Num()) return;
    const idGorePieceInfo_t& piece = goreDecl->gorePieces[goreIndex];
    for (int runtimeIndex = goredPiecesInUse.Num() - 1;
            runtimeIndex >= 0; --runtimeIndex) {
        goredPiecesInUse_t& runtime = goredPiecesInUse[runtimeIndex];
        if (runtime.goreIndex < 0
                || runtime.goreIndex >= goreDecl->gorePieces.Num()) continue;
        const idGorePieceInfo_t& activePiece =
            goreDecl->gorePieces[runtime.goreIndex];
        if (runtime.goreIndex != goreIndex
                && !AtomicEqual(activePiece.name, piece.name)) continue;

        for (int i = 0; i < activePiece.hideKitInfo.Num(); ++i) {
            const goreKitInfo_t& kit = activePiece.hideKitInfo[i];
            Services().SetMeshKit(presentable, kit.kitType,
                kit.meshKit, true);
        }
        for (int i = 0; i < activePiece.showKitInfo.Num(); ++i) {
            const goreKitInfo_t& kit = activePiece.showKitInfo[i];
            Services().SetMeshKit(presentable, kit.kitType,
                kit.meshKit, false);
        }
        for (int i = 0; i < activePiece.fxToPlay.Num(); ++i) {
            Services().StopGoreFX(presentable, activePiece.fxToPlay[i]);
        }
        for (int i = 0; i < activePiece.morphVertIndex.Num(); ++i) {
            Services().ApplyMorph(presentable,
                activePiece.morphVertIndex[i], false);
        }
        for (int i = 0; i < activePiece.clipSphereIndex.Num(); ++i) {
            for (int slot = 0; slot < wounds.Num(); ++slot) {
                if (wounds[slot] == activePiece.clipSphereIndex[i]) {
                    wounds[slot] = -1;
                    Services().ClearClipShape(presentable, slot);
                }
            }
        }
        if (activePiece.clipShape.type == CLIPSHAPETYPE_SPHERE) {
            for (int slot = 0; slot < wounds.Num() && slot < 10; ++slot) {
                if (wounds[slot] == runtime.goreIndex) {
                    wounds[slot] = -1;
                    Services().ClearClipShape(presentable, slot);
                }
            }
        }
        if (activePiece.clipShape.type == CLIPSHAPETYPE_ELLIPSOID
                && wounds.Num() > 10 && wounds[10] == goreIndex) {
            wounds[10] = -1;
            Services().ClearClipShape(presentable, 10);
        }
        DisableCloth(runtimeIndex, position, impulse);
        Services().ZeroJoint(presentable,
            activePiece.jointToZeroOut, false);
        goredPiecesInUse.RemoveIndex(runtimeIndex);
    }
    Services().MarkClipParmsChanged(presentable);
}

// Retail: 0x82C5D250
void idGoreComponent::Init(idPresentableAnimatedEntity* inPresentable,
        const idDeclGore* inGoreDecl) {
    presentable = inPresentable;
    goreDecl = inGoreDecl;
    deathTime = -1;
    frameDamage.Clear();
    jointsGoredThisFrame.Clear();
    wounds.Clear();
    if (goreDecl == nullptr || !Services().IsPresentableValid(presentable)) {
        return;
    }
    for (int i = 0; i < goreDecl->gorePieces.Num(); ++i) {
        const idGorePieceInfo_t& piece = goreDecl->gorePieces[i];
        Services().ValidateGorePiece(presentable, piece, i);
        if (piece.entityToSpawn != nullptr) {
            Services().RegisterSpawnable(piece.entityToSpawn,
                piece.EntityToSpawnIsABreakable(), presentable);
        }
        if (piece.cloth.gibEntity != nullptr) {
            Services().RegisterSpawnable(piece.cloth.gibEntity,
                piece.cloth.EntityToSpawnIsABreakable(), presentable);
        }
    }
    for (int i = 0; i < goreDecl->fullBodyBreakableGibs.Num(); ++i) {
        Services().RegisterSpawnable(goreDecl->fullBodyBreakableGibs[i],
            true, presentable);
    }
}

// Retail: 0x82C5D600
void idGoreInitScopeCleanup() {}

// Retail: 0x82C5D658
void idGoreComponent::ActivateBFGExplosion(
        const idDeclDamage* damageDecl, const idVec3& impactPoint,
        const idVec3& direction) {
    if (goreDecl == nullptr || goreDecl->fullBodyBreakableGibs.Num() == 0
            || damageDecl == nullptr) return;
    Services().ActivateBFGBreakable(*goreDecl, presentable, damageDecl,
        impactPoint, direction);
}

// Retail: 0x82C5DDD8
bool idGoreComponent::EnableGorePiece(
        const int goreIndex, const idVec3& impulse) {
    if (!Services().IsGoreEnabled() || Services().IsMultiplayer()
            || goreDecl == nullptr || goreIndex < 0
            || goreIndex >= goreDecl->gorePieces.Num()
            || !Services().IsPresentableValid(presentable)) {
        return false;
    }
    const idGorePieceInfo_t& candidate = goreDecl->gorePieces[goreIndex];
    for (int i = 0; i < goredPiecesInUse.Num(); ++i) {
        const int activeIndex = goredPiecesInUse[i].goreIndex;
        if (activeIndex < 0 || activeIndex >= goreDecl->gorePieces.Num()) {
            continue;
        }
        const idGorePieceInfo_t& active = goreDecl->gorePieces[activeIndex];
        if (AtomicEqual(active.name, candidate.name)
                || Contains(active.exclusionList, candidate.name)) {
            return false;
        }
    }

    for (int i = goredPiecesInUse.Num() - 1; i >= 0; --i) {
        const int activeIndex = goredPiecesInUse[i].goreIndex;
        if (activeIndex < 0 || activeIndex >= goreDecl->gorePieces.Num()) {
            continue;
        }
        const idGorePieceInfo_t& active = goreDecl->gorePieces[activeIndex];
        if (Contains(candidate.overrideList, active.name)) {
            DisableGorePiece(activeIndex, ZeroVector(), impulse);
        }
    }

    goredPiecesInUse_t runtime;
    runtime.goreIndex = static_cast<short>(goreIndex);
    runtime.impulse = impulse;
    idMat3 presentableAxis(1.0f);
    Services().GetPresentableTransform(presentable,
        runtime.initialGibJointPos, presentableAxis);
    // The retail object captures a joint transform here; the runtime service
    // applies the actual joint/tag transform during the first update frame.
    runtime.activated = false;
    runtime.frameCountSinceSpawn = 0;
    goredPiecesInUse.Append(runtime);
    if (candidate.jointToZeroOut == "head"
            || candidate.jointToZeroOut == "neck") {
        Services().StopVoice(presentable);
    }
    return true;
}

// Retail: 0x82C5E4C0
void idGoreComponent::UpdateKillshot(idGoreJointIndex hitJoint,
        const idDeclDamage* damageDecl, const float damage,
        const idVec3& impulse, const idVec3& position,
        const idVec3& normal, const idDamageGroup* damageGroup,
        const bool allowGore) {
    if (Services().IsMultiplayer() || !allowGore || goreDecl == nullptr) {
        return;
    }
    for (int i = 0; i < goredPiecesInUse.Num(); ++i) {
        const int activeIndex = goredPiecesInUse[i].goreIndex;
        if (activeIndex >= 0 && activeIndex < goreDecl->gorePieces.Num()
                && goreDecl->gorePieces[activeIndex].goreLevel
                    > GORELEVEL_HEAVY_DAMAGE) {
            return;
        }
    }

    const int damageTypes = Services().GetDamageGoreTypes(damageDecl);
    const idAtomicString groupName =
        Services().GetDamageGroupName(damageGroup);
    int chosenWound = -1;
    for (int i = 0; i < goreDecl->gorePieces.Num(); ++i) {
        const idGorePieceInfo_t& piece = goreDecl->gorePieces[i];
        if (piece.goreType != GORETYPE_NONE
                && (piece.goreType & damageTypes) == 0) continue;
        if (damage < piece.damageRequiredToGore
                || !Contains(piece.damageGroups, groupName)) continue;
        if (piece.clipSphereIndex.Num() > 0
                || piece.goreType == GORETYPE_SMALL_WOUND
                || piece.goreType == GORETYPE_BIG_WOUND) {
            if (chosenWound < 0) chosenWound = i;
        } else {
            EnableGorePiece(i, Normalize(impulse));
        }
    }
    if (chosenWound >= 0 && EnableGorePiece(
            chosenWound, Normalize(impulse))) {
        const idGorePieceInfo_t& piece = goreDecl->gorePieces[chosenWound];
        const int clipIndex = piece.clipSphereIndex.Num() > 0
            ? piece.clipSphereIndex[0] : chosenWound;
        SetClipSphereRenderParms(
            idVec4(position.x, position.y, position.z,
                piece.goreType == GORETYPE_BIG_WOUND ? 12.0f : 6.0f),
            clipIndex);
        jointsGoredThisFrame.AddUnique(hitJoint);
    }
    (void)normal;
}

// Retail: 0x82C5EAD8
bool idGoreComponent::CheckForGoreByDamageGroup(
        const idAtomicString& name, const goreLevel_t level,
        const idVec3& direction) {
    if (!Services().IsGoreEnabled() || Services().IsMultiplayer()
            || goreDecl == nullptr || goreDecl->gorePieces.Num() == 0
            || !Services().IsPresentableValid(presentable)
            || Services().GetPresentableFade(presentable) < 0.75f
            || name.IsEmpty()) return false;
    for (int i = 0; i < goreDecl->gorePieces.Num(); ++i) {
        const idGorePieceInfo_t& piece = goreDecl->gorePieces[i];
        if (piece.goreLevel == level && Contains(piece.damageGroups, name)
                && EnableGorePiece(i, direction)) return true;
    }
    return false;
}

// Retail: 0x82C5ED48
bool idGoreComponent::CheckForGoreByName(const idAtomicString& name) {
    if (!Services().IsGoreEnabled() || Services().IsMultiplayer()
            || goreDecl == nullptr || goreDecl->gorePieces.Num() == 0
            || !Services().IsPresentableValid(presentable)
            || Services().GetPresentableFade(presentable) < 0.75f
            || name.IsEmpty()) return false;
    for (int i = 0; i < goreDecl->gorePieces.Num(); ++i) {
        if (AtomicEqual(goreDecl->gorePieces[i].name, name)
                && EnableGorePiece(i, ZeroVector())) return true;
    }
    return false;
}

// Retail: 0x82C5EF78
void idGoreComponent::ActivateFullBodyExplosion(
        const idDeclDamage* damageDecl, const float damage,
        const idVec3& impactPoint, const idVec3& impulse) {
    if (damageDecl == nullptr || goreDecl == nullptr
            || !Services().HasBodyExplosion(damageDecl)
            || !Services().IsPresentableValid(presentable)) return;
    int remainingPieces = (std::max)(0,
        Services().GetBodyExplosionMaxPieces(damageDecl));
    int remainingWounds = (std::min)(10, (std::max)(0,
        Services().GetBodyExplosionMaxWounds(damageDecl)));
    int remainingHeads = 1;
    if (damage <= 0.0f) return;
    const int count = goreDecl->gorePieces.Num();
    const int start = count > 0 ? Services().RandomInt(count) : 0;
    for (int offset = 0; offset < count; ++offset) {
        const int i = (start + offset) % count;
        const idGorePieceInfo_t& piece = goreDecl->gorePieces[i];
        const bool wound = (piece.goreType
            & (GORETYPE_SMALL_WOUND | GORETYPE_BIG_WOUND)) != 0;
        const bool head = (piece.goreType & GORETYPE_HEAD_EXPLODE) != 0;
        if (wound && remainingWounds > 0) {
            if (EnableGorePiece(i, impulse)) --remainingWounds;
        } else if (head && remainingHeads > 0) {
            if (EnableGorePiece(i, impulse)) --remainingHeads;
        } else if (!wound && !head && remainingPieces > 0) {
            if (EnableGorePiece(i, impulse)) --remainingPieces;
        }
        if (remainingPieces == 0 && remainingWounds == 0
                && remainingHeads == 0) break;
    }
    (void)impactPoint;
}

// Retail: 0x82C5F2D8
void idGoreComponent::AddDamage(idGoreJointIndex,
        const idDeclDamage*, float, const idVec3&, const idVec3& position,
        const idVec3&, const idDamageGroup* damageGroup,
        const bool allowGore) {
    if (!Services().IsMultiplayer() && allowGore && damageGroup != nullptr) {
        CheckForGoreByDamageGroup(
            Services().GetDamageGroupName(damageGroup),
            GORELEVEL_BLOOD, position);
    }
}

// Retail: 0x82C5F348
void idGoreComponent::TestGoreCheat() {
    const int testIndex = Services().GetTestGoreIndex();
    if (testIndex == -1 || goreDecl == nullptr
            || !Services().IsPresentableValid(presentable)) return;
    for (int i = goredPiecesInUse.Num() - 1; i >= 0; --i) {
        DisableGorePiece(goredPiecesInUse[i].goreIndex,
            ZeroVector(), ZeroVector());
    }
    if (testIndex >= 0 && testIndex < goreDecl->gorePieces.Num()) {
        CheckForGoreByName(goreDecl->gorePieces[testIndex].name);
    }
}

// Retail: 0x82C5F460
bool idGoreComponent::UpdateGore() {
    if (!Services().IsPresentableValid(presentable) || goreDecl == nullptr) {
        return false;
    }
    TestGoreCheat();
    bool updated = false;
    idVec3 origin;
    idMat3 axis;
    Services().GetPresentableTransform(presentable, origin, axis);
    for (int i = 0; i < goredPiecesInUse.Num(); ++i) {
        goredPiecesInUse_t& runtime = goredPiecesInUse[i];
        if (runtime.goreIndex < 0
                || runtime.goreIndex >= goreDecl->gorePieces.Num()) continue;
        const idGorePieceInfo_t& piece =
            goreDecl->gorePieces[runtime.goreIndex];
        if (!runtime.activated) {
            for (int kitIndex = 0;
                    kitIndex < piece.hideKitInfo.Num(); ++kitIndex) {
                const goreKitInfo_t& kit = piece.hideKitInfo[kitIndex];
                Services().SetMeshKit(presentable, kit.kitType,
                    kit.meshKit, false);
            }
            for (int kitIndex = 0;
                    kitIndex < piece.showKitInfo.Num(); ++kitIndex) {
                const goreKitInfo_t& kit = piece.showKitInfo[kitIndex];
                Services().SetMeshKit(presentable, kit.kitType,
                    kit.meshKit, true);
            }
            if (!piece.jointToZeroOut.IsEmpty()) {
                Services().ZeroJoint(presentable,
                    piece.jointToZeroOut, true);
            }
            if (!piece.constraintToBreak.IsEmpty()) {
                Services().BreakConstraint(presentable,
                    piece.constraintToBreak);
            }
            for (int effectIndex = 0;
                    effectIndex < piece.fxToPlay.Num(); ++effectIndex) {
                Services().StartGoreFX(presentable,
                    piece.fxToPlay[effectIndex], piece.fxTagJoint);
            }
            for (int morphIndex = 0;
                    morphIndex < piece.morphVertIndex.Num(); ++morphIndex) {
                Services().ApplyMorph(presentable,
                    piece.morphVertIndex[morphIndex], true);
            }
            if (piece.entityToSpawn != nullptr && !runtime.gibMeshSpawned) {
                Services().SpawnGoreEntity(piece.entityToSpawn,
                    piece.EntityToSpawnIsABreakable(), origin, axis,
                    runtime.impulse, piece.spawnedEntityImpulseBehavior);
                runtime.gibMeshSpawned = true;
            }
            if (piece.clipShape.type == CLIPSHAPETYPE_SPHERE) {
                const idVec3& row = piece.clipShape.axis[0];
                const float radius = std::sqrt(row.x * row.x
                    + row.y * row.y + row.z * row.z);
                SetClipSphereRenderParms(idVec4(piece.clipShape.origin.x,
                    piece.clipShape.origin.y, piece.clipShape.origin.z,
                    radius), runtime.goreIndex);
            } else if (piece.clipShape.type == CLIPSHAPETYPE_ELLIPSOID) {
                SetClipEllipsoidRenderParms(piece.clipShape.origin,
                    piece.clipShape.axis, runtime.goreIndex);
            }
            if (piece.cloth.clothDecl != nullptr
                    && runtime.clothSim == nullptr) {
                runtime.clothSim = Services().AllocateCloth(presentable,
                    runtime.goreIndex, piece.cloth.clothAttachTag);
            }
            runtime.activated = true;
            updated = true;
        }
        ++runtime.frameCountSinceSpawn;
    }
    UpdateFloorTrace();
    UpdateDeathFade();
    jointsGoredThisFrame.Clear();
    return updated || goredPiecesInUse.Num() > 0;
}

// Retail: 0x82C608A0
bool idGoreComponent::CheckForGore() {
    if (!Services().IsGoreEnabled() || Services().IsMultiplayer()
            || goreDecl == nullptr || goreDecl->gorePieces.Num() == 0
            || !Services().IsPresentableValid(presentable)
            || Services().GetPresentableFade(presentable) < 0.75f) {
        frameDamage.Clear();
        return false;
    }

    bool activatedExplosion = false;
    for (int i = 0; i < frameDamage.Num(); ++i) {
        const goreFrameDamage_t& hit = frameDamage[i];
        const int types = Services().GetDamageGoreTypes(hit.damageDecl);
        if ((types & GORETYPE_BFG) != 0) {
            ActivateBFGExplosion(hit.damageDecl, hit.position,
                Normalize(hit.impulse));
            activatedExplosion = true;
        }
        if ((types & GORETYPE_GIB) != 0
                && Services().HasBodyExplosion(hit.damageDecl)) {
            ActivateFullBodyExplosion(hit.damageDecl, hit.damage,
                hit.position, Normalize(hit.impulse));
            activatedExplosion = true;
        }
    }

    const int pieceCount = goreDecl->gorePieces.Num();
    const int start = pieceCount > 0 ? Services().RandomInt(pieceCount) : 0;
    for (int offset = 0; offset < pieceCount; ++offset) {
        const int pieceIndex = (start + offset) % pieceCount;
        const idGorePieceInfo_t& piece = goreDecl->gorePieces[pieceIndex];
        bool alreadyActive = false;
        for (int activeIndex = 0;
                activeIndex < goredPiecesInUse.Num(); ++activeIndex) {
            const int current = goredPiecesInUse[activeIndex].goreIndex;
            if (current < 0 || current >= pieceCount) continue;
            if (current == pieceIndex || AtomicEqual(
                    goreDecl->gorePieces[current].name, piece.name)) {
                alreadyActive = true;
                break;
            }
        }
        if (alreadyActive) continue;

        float accumulatedDamage = 0.0f;
        idVec3 accumulatedImpulse = ZeroVector();
        for (int groupIndex = 0;
                groupIndex < piece.damageGroups.Num(); ++groupIndex) {
            const idAtomicString& requiredGroup =
                piece.damageGroups[groupIndex];
            for (int hitIndex = 0;
                    hitIndex < frameDamage.Num(); ++hitIndex) {
                const goreFrameDamage_t& hit = frameDamage[hitIndex];
                const int damageTypes =
                    Services().GetDamageGoreTypes(hit.damageDecl);
                const idAtomicString hitGroup =
                    Services().GetDamageGroupName(hit.damageGroup);
                if ((piece.goreType == GORETYPE_NONE
                        || (damageTypes & piece.goreType & ~GORETYPE_GIB) != 0)
                        && AtomicEqual(requiredGroup, hitGroup)) {
                    accumulatedDamage += hit.damage;
                    accumulatedImpulse = Add(
                        accumulatedImpulse, hit.impulse);
                }
            }
        }
        if (accumulatedDamage >= piece.damageRequiredToGore
                && EnableGorePiece(pieceIndex,
                    Normalize(accumulatedImpulse))) {
            frameDamage.Clear();
            return true;
        }
    }
    frameDamage.Clear();
    return activatedExplosion;
}
