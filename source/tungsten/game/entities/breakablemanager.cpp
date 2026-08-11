#include "game/entities/breakablemanager.h"

namespace {
idBreakableManagerServices defaultBreakableManagerServices;
idBreakableManagerServices* breakableManagerServices =
    &defaultBreakableManagerServices;

idMat3 SafeOrientation(const idMat3& orientation) {
    if (orientation[2].LengthSqr() == 0.0f) {
        return idMat3(1.0f);
    }
    return orientation;
}
}

void idBreakableManager::SetServices(
        idBreakableManagerServices* const services) {
    breakableManagerServices = services == nullptr
        ? &defaultBreakableManagerServices : services;
}

idBreakableManagerServices& idBreakableManager::Services() {
    return *breakableManagerServices;
}

// Retail: 0x82C0EB38 ?FindBreakable@idBreakableManager@@AAAHPBVidDeclEntityDef@@@Z
int idBreakableManager::FindBreakable(
        const idDeclEntityDef* const declaration) const {
    for (int index = 0; index < breakable.Num(); ++index) {
        const breakables_t& group = breakable[index];
        if (group.entity.Num() > 0
                && Services().GetDeclaration(group.entity[0])
                    == declaration) {
            return index;
        }
    }
    return -1;
}

// Retail: 0x82C0EB90 ?UseBreakable@idBreakableManager@@QAAPAVidBreakable@@...
idBreakable* idBreakableManager::UseBreakable(
        const idDeclEntityDef* const declaration, const idVec3& origin,
        const idMat3& axis, const idVec3& direction,
        const idVec3* const position, const float impulse,
        const float fadeTime) {
    const int groupIndex = FindBreakable(declaration);
    if (groupIndex < 0) {
        Services().Warn("requested breakable declaration is not pooled");
        return nullptr;
    }
    breakables_t& group = breakable[groupIndex];
    if (group.entity.Num() == 0) {
        return nullptr;
    }
    idBreakable* const entity = group.entity[group.next];
    if (entity == nullptr) {
        Services().Warn("null breakable in pool");
        return nullptr;
    }
    Services().PrepareForUse(*entity, origin, axis);
    entity->Show();
    entity->Reset();
    if (position != nullptr) {
        entity->AddExplosion(*position - direction, impulse);
    } else {
        entity->OnActivate(nullptr);
    }
    if (fadeTime > 0.0f) {
        entity->fadeTime = fadeTime;
    }
    group.next = (group.next + 1) % group.entity.Num();
    return entity;
}

// Retail: 0x82C0EDA8 ?ReactToMover@idBreakableManager@@QAAXXZ
void idBreakableManager::ReactToMover() {
    for (int groupIndex = 0; groupIndex < breakable.Num(); ++groupIndex) {
        breakables_t& group = breakable[groupIndex];
        for (int entityIndex = 0; entityIndex < group.entity.Num();
                ++entityIndex) {
            idBreakable* const entity = group.entity[entityIndex];
            if (entity != nullptr
                    && !Services().IsRelaxedChatterEnabled(*entity)) {
                entity->Hide();
            }
        }
    }
}

// Retail: 0x82C0EE60 ?OrientBodies@idBreakableManager@@QAA_NPBVidTreeAnimator@@...
bool idBreakableManager::OrientBodies(const idTreeAnimator* const animator,
        idRenderModelDiscreteAnimation* const breakableModel,
        const idVec3& breakableOrigin, const idMat3& breakableAxis,
        const idList<breakableJoint_t, 5>& joints) {
    if (breakableModel == nullptr || joints.Num() < 1
            || !Services().HasAnimatorSkeleton(animator)) {
        return false;
    }
    idVec3 animatorOrigin;
    Services().GetAnimatorOrigin(animator, animatorOrigin);
    const idVec3 modelOffset = breakableAxis
        * (animatorOrigin - breakableOrigin);
    Services().ResetModel(breakableModel);
    const int pieceCount = Services().GetPieceCount(breakableModel);
    for (int index = 0; index < joints.Num(); ++index) {
        const breakableJoint_t& mapping = joints[index];
        if (!mapping.jointIndex.IsValid() || mapping.pieceIndex < 0
                || mapping.pieceIndex >= pieceCount) {
            Services().Warn("breakable joint mapping is invalid");
            return false;
        }
        idVec3 jointOrigin;
        idMat3 jointAxis;
        idVec3 pieceOrigin;
        idMat3 pieceAxis;
        idVec3 inverseOrigin;
        idMat3 inverseAxis;
        if (!Services().GetModelSpaceJointTransform(animator,
                mapping.jointIndex, jointOrigin, jointAxis)
                || !Services().GetPiecePosition(breakableModel,
                    mapping.pieceIndex, pieceOrigin, pieceAxis)
                || !Services().GetInverseBasePose(animator,
                    mapping.jointIndex, inverseOrigin, inverseAxis)) {
            return false;
        }
        const idVec3 orientedPosition = jointOrigin
            + jointAxis * (inverseAxis * pieceOrigin + inverseOrigin)
            + modelOffset;
        const idMat3 orientedAxis = SafeOrientation(
            inverseAxis * jointAxis);
        Services().SetPiecePosition(breakableModel,
            mapping.pieceIndex, orientedPosition, orientedAxis);
    }
    return true;
}

// Retail: 0x82C0F1E0 ?OrientAndUseBreakable@idBreakableManager@@QAAX...
void idBreakableManager::OrientAndUseBreakable(
        const idDeclEntityDef* const declaration, const idVec3& origin,
        const idMat3& axis, const idVec3& explosionOrigin,
        const float impulse, const idTreeAnimator* const animator,
        const idList<breakableJoint_t, 5>& joints) {
    if (declaration == nullptr || animator == nullptr || joints.Num() < 1) {
        Services().Warn("invalid oriented-breakable input");
        return;
    }
    const int groupIndex = FindBreakable(declaration);
    if (groupIndex < 0 || breakable[groupIndex].entity.Num() == 0) {
        Services().Warn("oriented breakable declaration is not pooled");
        return;
    }
    breakables_t& group = breakable[groupIndex];
    idBreakable* const entity = group.entity[group.next];
    if (entity == nullptr) {
        return;
    }
    Services().PrepareForUse(*entity, origin, axis);
    entity->Show();
    idVec3 actualOrigin;
    idMat3 actualAxis;
    entity->GetModelTransform(actualOrigin, actualAxis);
    idRenderModelDiscreteAnimation* const model =
        Services().GetBreakableModel(*entity);
    if (!OrientBodies(animator, model,
            actualOrigin, actualAxis, joints)) {
        Services().Warn("unable to reorient breakable bodies");
        return;
    }
    entity->ResetRigidBodies();
    entity->AddExplosion(explosionOrigin, impulse);
    group.next = (group.next + 1) % group.entity.Num();
}

// Retail: 0x82C0F458 ?AddBreakable@idBreakableManager@@QAAXPBVidDeclEntityDef@@ABVidVec3@@@Z
void idBreakableManager::AddBreakable(
        const idDeclEntityDef* const declaration, const idVec3& origin) {
    if (declaration == nullptr) {
        Services().Warn("null breakable declaration");
        return;
    }
    int groupIndex = FindBreakable(declaration);
    if (groupIndex < 0) {
        if (breakable.Num() >= breakable.Max()) {
            Services().Warn("no free breakable pool slots");
            return;
        }
        groupIndex = breakable.Alloc() - breakable.Ptr();
    }
    breakables_t& group = breakable[groupIndex];
    if (group.entity.Num() >= group.entity.Max()) {
        return;
    }
    idBreakable* const entity = Services().SpawnBreakable(declaration);
    if (entity == nullptr || !Services().HasValidBreakableModel(entity)) {
        Services().Warn("could not spawn a valid pooled breakable");
        Services().RemoveInvalidBreakable(entity);
        return;
    }
    entity->isPooled = true;
    Services().PreparePooledBreakable(*entity, origin);
    entity->Hide();
    group.entity.Append(entity);
}
