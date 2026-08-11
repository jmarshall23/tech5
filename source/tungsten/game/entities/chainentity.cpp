#include "game/entities/chainentity.h"

#include <algorithm>
#include <cmath>
#include <cstdio>

namespace {
constexpr float kEpsilon = 1.1920929e-7f;
constexpr unsigned int kLaserCuttingDamage = 0x80u;

idFuncChainServices defaultChainServices;
idFuncChainServices* chainServices = &defaultChainServices;

float ClampFloat(const float value, const float minimum,
        const float maximum) {
    return (std::max)(minimum, (std::min)(maximum, value));
}

bool InPlaneRanges(const idVerletChain::plane_t& collision,
        const int pointIndex) {
    for (int range = 0; range < 2; ++range) {
        if (pointIndex >= collision.startIndex[range]
                && pointIndex < collision.startIndex[range]
                    + collision.numPoints[range]) {
            return true;
        }
    }
    return false;
}

idMat3 SafeInverse(const idMat3& axis) {
    idMat3 inverse = axis;
    if (!inverse.InverseSelf()) {
        inverse = axis.Transpose();
    }
    return inverse;
}

idMat3 LinkAxis(idVec3 forward, const idVec3& referenceLeft) {
    if (forward.NormalizeFast() <= kEpsilon) {
        forward.Set(1.0f, 0.0f, 0.0f);
    }
    idVec3 left = referenceLeft;
    if (left.NormalizeFast() <= kEpsilon
            || std::fabs(left.Dot(forward)) > 0.999f) {
        left = std::fabs(forward.z) < 0.9f
            ? idVec3(0.0f, 0.0f, 1.0f)
            : idVec3(0.0f, 1.0f, 0.0f);
    }
    idVec3 down = forward.Cross(left);
    down.NormalizeFast();
    left = down.Cross(forward);
    left.NormalizeFast();
    return idMat3(forward.x, forward.y, forward.z,
        left.x, left.y, left.z, down.x, down.y, down.z);
}
}

damageMorph_t::damageMorph_t()
    : amount{0.0f, 0.0f, 0.0f, 0.0f}
    , index{-1, -1, -1, -1} {
}

idVerletChain::particle_t::particle_t()
    : oldPos(0.0f, 0.0f, 0.0f)
    , currentPos(0.0f, 0.0f, 0.0f)
    , health(0.0f)
    , healthStamp(0.0f)
    , timeStamp(0)
    , anchor(false)
    , padding{0, 0, 0} {
}

idVerletChain::particle_t::particle_t(const idVec3& position)
    : oldPos(position)
    , currentPos(position)
    , health(0.0f)
    , healthStamp(0.0f)
    , timeStamp(0)
    , anchor(false)
    , padding{0, 0, 0} {
}

idVerletChain::force_t::force_t()
    : force(0.0f, 0.0f, 0.0f), numSteps(0), pointId(-1) {
}

idVerletChain::force_t::force_t(const idVec3& value, const int steps,
        const int point)
    : force(value), numSteps(steps), pointId(point) {
}

idVerletChain::plane_t::plane_t()
    : plane(0.0f, 0.0f, 1.0f, 0.0f)
    , startIndex{0, 0}
    , numPoints{0, 0} {
}

idVerletChain::settings_t::settings_t()
    : gravity(0.0f, 0.0f, -1066.0f)
    , frictionAir(0.02f)
    , frictionFloor(0.25f)
    , floorFrictionDistance(2.0f)
    , linkRadius(0.5f)
    , stiffness(1.0f)
    , lengthAdjustment(1.0f)
    , frameSeconds(1.0f / 60.0f)
    , iterations(4)
    , maximumDynamicIterations(16)
    , dynamicIterationError(0.01f)
    , anchorStart(true)
    , anchorEnd(true)
    , enabled(true)
    , dynamicIterations(false) {
}

// Retail: 0x82C0F650 ?GetNormal@idVerletChain@@QBA?AVidVec3@@H@Z
idVec3 idVerletChain::GetNormal(const int pointId) const {
    if (pointId < 0 || pointId >= orientations.Num()) {
        return idVec3(0.0f, 0.0f, 0.0f);
    }
    const orientation_t& orientation = orientations[pointId];
    if (orientation.index1 >= points.Num()
            || orientation.index2 >= points.Num()) {
        return idVec3(0.0f, 0.0f, 0.0f);
    }
    idVec3 normal = points[orientation.index2].currentPos
        - points[orientation.index1].currentPos;
    normal.NormalizeFast();
    return normal;
}

// Retail: 0x82C0F730 ?UpdateCooldown@idVerletChain@@QAA_NHHAAM@Z
bool idVerletChain::UpdateCooldown(const int pointId, const int gameTime,
        float& health) {
    if (pointId < 0 || pointId >= points.Num()) {
        return false;
    }
    particle_t& point = points[pointId];
    if (point.timeStamp == 0 || point.timeStamp > gameTime) {
        return false;
    }
    const float time = ClampFloat(
        static_cast<float>(gameTime - point.timeStamp) * 0.00025f,
        0.0f, 1.0f);
    const float recovered = point.healthStamp
        + (maxHealth - point.healthStamp)
            * cooldownTable.TableLookupNormalized(time, pointId != 0);
    if (std::fabs(recovered - point.health) <= kEpsilon) {
        return false;
    }
    point.health = recovered;
    health = recovered;
    if (std::fabs(recovered - maxHealth) <= kEpsilon) {
        point.timeStamp = 0;
    }
    return true;
}

// Retail: 0x82C0F830 ?GetBestPoint@idVerletChain@@QBAHABVidVec3@@@Z
int idVerletChain::GetBestPoint(const idVec3& position) const {
    int bestPoint = -1;
    float bestDistance = 1.0e30f;
    for (int index = 0; index < points.Num(); ++index) {
        const float distance =
            (points[index].currentPos - position).LengthSqr();
        if (distance < bestDistance) {
            bestDistance = distance;
            bestPoint = index;
        }
    }
    return bestPoint;
}

// Retail: 0x82C0F9C0 ?GetBestConstraint@idVerletChain@@ABAHHABVidVec3@@@Z
int idVerletChain::GetBestConstraint(const int id,
        const idVec3& position) const {
    if (constraints.Num() == 0 || id < 0 || id >= points.Num()) {
        return -1;
    }
    if (id == 0) {
        return 0;
    }
    if (id == points.Num() - 1) {
        return (std::min)(id - 1, constraints.Num() - 1);
    }
    if (id >= constraints.Num()) {
        return constraints.Num() - 1;
    }
    const int previous = id - 1;
    const int previousOuter = constraints[previous].index1;
    const int nextOuter = constraints[id].index2;
    if (previousOuter < 0 || previousOuter >= points.Num()) {
        return id;
    }
    if (nextOuter < 0 || nextOuter >= points.Num()) {
        return previous;
    }
    const float previousDistance =
        (points[previousOuter].currentPos - position).LengthSqr();
    const float nextDistance =
        (points[nextOuter].currentPos - position).LengthSqr();
    return previousDistance < nextDistance ? previous : id;
}

// Retail: 0x82C0FAB0 ?Constrain@idVerletChain@@AAAXXZ
void idVerletChain::Constrain() {
    int remaining = (std::max)(0, settings.iterations);
    int iteration = 0;
    while (remaining > 0) {
        for (int order = 0; order < constraints.Num(); ++order) {
            const int index = (order & 1) != 0
                ? constraints.Num() - (order >> 1) - 1
                : order >> 1;
            constraint_t& constraint = constraints[index];
            if (constraint.index1 < 0 || constraint.index2 < 0
                    || constraint.index1 >= points.Num()
                    || constraint.index2 >= points.Num()) {
                continue;
            }
            particle_t& point1 = points[constraint.index1];
            particle_t& point2 = points[constraint.index2];
            const idVec3 difference = point1.currentPos - point2.currentPos;
            const float differenceSquared = difference.LengthSqr();
            const float denominator = differenceSquared
                + constraint.lengthSquared;
            if (denominator <= kEpsilon) {
                continue;
            }
            const float scale = (constraint.lengthSquared / denominator
                - 0.5f) * (settings.stiffness * 0.5f);
            const idVec3 correction = difference * scale;
            if (!point1.anchor) {
                point1.currentPos = point1.currentPos
                    + correction * constraint.ratio1;
            }
            if (!point2.anchor) {
                point2.currentPos = point2.currentPos
                    - correction * constraint.ratio2;
            }
        }

        for (int sphereIndex = 0;
                sphereIndex < sphereCollisions.Num(); ++sphereIndex) {
            const idSphere& sphere = sphereCollisions[sphereIndex];
            const float radius = sphere.radius + settings.linkRadius;
            const float radiusSquared = radius * radius;
            for (int pointIndex = 0; pointIndex < points.Num(); ++pointIndex) {
                particle_t& point = points[pointIndex];
                if (point.anchor) {
                    continue;
                }
                idVec3 direction = point.currentPos - sphere.origin;
                if (direction.LengthSqr() >= radiusSquared) {
                    continue;
                }
                if (direction.NormalizeFast() <= kEpsilon) {
                    direction = refDown;
                    if (direction.NormalizeFast() <= kEpsilon) {
                        direction.Set(0.0f, 0.0f, 1.0f);
                    }
                }
                point.currentPos = sphere.origin + direction * radius;
            }
        }

        for (int planeIndex = 0;
                planeIndex < planeCollisions.Num(); ++planeIndex) {
            const plane_t& collision = planeCollisions[planeIndex];
            const idVec3 offset = collision.plane.Normal()
                * (settings.linkRadius * 2.0f);
            for (int pointIndex = 0; pointIndex < points.Num(); ++pointIndex) {
                particle_t& point = points[pointIndex];
                if (point.anchor || !InPlaneRanges(collision, pointIndex)) {
                    continue;
                }
                const float distance = collision.plane.Distance(
                    point.currentPos - offset);
                if (distance < 0.0f) {
                    point.currentPos = point.currentPos
                        - collision.plane.Normal() * distance;
                }
            }
        }

        ++iteration;
        if (settings.dynamicIterations) {
            float totalError = 0.0f;
            for (int index = 0; index < constraints.Num(); ++index) {
                const constraint_t& constraint = constraints[index];
                if (constraint.index1 >= 0 && constraint.index2 >= 0
                        && constraint.index1 < points.Num()
                        && constraint.index2 < points.Num()) {
                    totalError += std::fabs(constraint.lengthSquared
                        - (points[constraint.index1].currentPos
                            - points[constraint.index2].currentPos)
                                .LengthSqr());
                }
            }
            if (totalError <= settings.dynamicIterationError
                    * settings.dynamicIterationError
                    || iteration >= settings.maximumDynamicIterations) {
                break;
            }
        } else {
            --remaining;
        }
    }
}

// Retail: 0x82C10388 ?GetMovement@idVerletChain@@QBAXHHAAM0@Z
void idVerletChain::GetMovement(int start, int end, float& maxMovement,
        float& avgMovement) const {
    maxMovement = 0.0f;
    avgMovement = 0.0f;
    start = (std::max)(0, start);
    end = (std::min)(end, points.Num());
    if (end <= start) {
        return;
    }
    for (int index = start; index < end; ++index) {
        const float movement =
            (points[index].oldPos - points[index].currentPos).LengthSqr();
        maxMovement = (std::max)(maxMovement, movement);
        avgMovement += movement;
    }
    avgMovement /= static_cast<float>(end - start);
}

// Retail: 0x82C105D0 ?GetConstraint@idVerletChain@@QBAXHAAVidVec3@@0AAM@Z
void idVerletChain::GetConstraint(const int id, idVec3& pos1,
        idVec3& pos2, float& restLengthDiff) const {
    pos1.Zero();
    pos2.Zero();
    restLengthDiff = 0.0f;
    if (id < 0 || id >= constraints.Num()) {
        return;
    }
    const constraint_t& constraint = constraints[id];
    if (constraint.index1 >= 0 && constraint.index1 < points.Num()) {
        pos1 = points[constraint.index1].currentPos;
    }
    if (constraint.index2 >= 0 && constraint.index2 < points.Num()) {
        pos2 = points[constraint.index2].currentPos;
    }
    restLengthDiff = std::fabs(constraint.length
        - (pos2 - pos1).Length());
}

// Retail: 0x82C10760 ?GetSoundTransform@idFuncChain@@UBAXAAVidVec3@@AAVidMat3@@@Z
void idFuncChain::GetSoundTransform(idVec3& soundOrigin,
        idMat3& soundAxis) const {
    soundAxis = idMat3(1.0f);
    soundOrigin = breakPosition;
}

// Retail: 0x82C107D8 ?buildChainClipModel_f@@YAXABVidCmdArgs@@@Z
void buildChainClipModel_f(const idCmdArgs& args) {
    if (args.Argc() < 2) {
        idFuncChain::Services().Print(
            "Usage: buildChainClipModel <entity name> <optional output name>\n");
        return;
    }
    idFuncChain* const chain =
        idFuncChain::Services().FindChain(args.Argv(1));
    if (chain == nullptr) {
        char message[256];
        std::snprintf(message, sizeof(message),
            "Couldn't find chain entity '%s'", args.Argv(1));
        idFuncChain::Services().Print(message);
        return;
    }
    idFuncChain::Services().BuildChainClipModel(
        *chain, args.Argc() > 2 ? args.Argv(2) : "");
}

// Retail: 0x82C10950 SetupCollisionSpherePtrsFromEntity
int SetupCollisionSpherePtrsFromEntity(idAnimatedEntity* const entity,
        cm_sphereModelPtrs_t* const spherePointers, idVec3* const origin,
        idMat3* const axis, const idJointMat** const modelJoints) {
    if (entity == nullptr || spherePointers == nullptr || origin == nullptr
            || axis == nullptr || modelJoints == nullptr) {
        return 0;
    }
    return idFuncChain::Services().SetupCollisionSpherePtrs(entity,
        spherePointers, *origin, *axis, *modelJoints);
}

// Retail: 0x82C10AE0 ?OnActivate@idFuncChainGroup@@UAAXPAVidEntity@@@Z
void idFuncChainGroup::OnActivate(idEntity* const activator) {
    const int entityNumber =
        idFuncChain::Services().GetEntityNumber(activator);
    bool wasActive = false;
    const int count = (std::min)(chains.Num(), activeChains.Num());
    for (int index = 0; index < count; ++index) {
        idFuncChain* const chain = idFuncChain::Services().ResolveChain(
            chains[index].GetSpawnId());
        if (chain != nullptr
                && idFuncChain::Services().GetEntityNumber(
                    reinterpret_cast<idEntity*>(chain)) == entityNumber) {
            wasActive = activeChains[index];
            activeChains[index] = false;
        }
    }
    if (!wasActive) {
        return;
    }
    for (int index = 0; index < activeChains.Num(); ++index) {
        if (activeChains[index]) {
            return;
        }
    }
    idFuncChain::Services().ActivateTargets(*this);
}

// Retail: 0x82C10B90 ?DisableChain@idFuncChain@@AAAXXZ
void idFuncChain::DisableChain() {
    Services().DisablePhysics(*this);
    Services().ActivateTargets(*this);
    idFuncChainGroup* const group =
        Services().ResolveChainGroup(chainGroup.GetSpawnId());
    if (group != nullptr) {
        Services().ActivateChainGroup(*group, *this);
    }
}

// Retail: 0x82C10E68 ??1idVerletChain@@UAA@XZ
idVerletChain::~idVerletChain() {
    constraints.ClearFree();
    points.ClearFree();
    orientations.ClearFree();
    forces.ClearFree();
    sphereCollisions.ClearFree();
    planeCollisions.ClearFree();
    cooldownTable.Clear();
}

// Retail: 0x82C11028 ?Integrate@idVerletChain@@AAAXMM@Z
void idVerletChain::Integrate(const float deltaTime,
        const float gravityScale) {
    const float deltaSquared = deltaTime * deltaTime;
    const idVec3 gravity = settings.gravity
        * (deltaSquared * gravityScale);
    const plane_t* const floor = planeCollisions.Num() > 0
        ? &planeCollisions[0] : nullptr;
    for (int index = 0; index < points.Num(); ++index) {
        particle_t& point = points[index];
        if (point.anchor) {
            continue;
        }
        float friction = settings.frictionAir;
        if (floor != nullptr && InPlaneRanges(*floor, index)
                && floor->plane.Distance(point.currentPos)
                    < settings.floorFrictionDistance) {
            friction = settings.frictionFloor;
        }
        const idVec3 current = point.currentPos;
        const idVec3 velocity = (point.currentPos - point.oldPos)
            * (1.0f - friction);
        point.oldPos = current;
        point.currentPos = current + velocity + gravity;
    }

    for (int index = forces.Num() - 1; index >= 0; --index) {
        force_t& force = forces[index];
        if (force.pointId >= 0 && force.pointId < points.Num()) {
            points[force.pointId].currentPos =
                points[force.pointId].currentPos
                    + force.force * deltaSquared;
        }
        --force.numSteps;
        if (force.numSteps <= 0) {
            forces.RemoveIndexFast(index);
        }
    }
}

// Retail: 0x82C11820 ??0idFuncChainGroup@@QAA@XZ
idFuncChainGroup::idFuncChainGroup()
    : chains(), activeChains() {
}

// Retail: 0x82C118F8 ??1idFuncChainGroup@@UAA@XZ
idFuncChainGroup::~idFuncChainGroup() {
    activeChains.ClearFree();
    chains.ClearFree();
}

// Retail: 0x82C119A8 ?BindEndPoint@idFuncChain@@AAAXABUbinddef_t@1@AAUbind_t@1@@Z
void idFuncChain::BindEndPoint(const binddef_t& bindInfo, bind_t& bind) {
    bind = bind_t();
    if (bindInfo.bindToObject.IsValid()
            && !Services().ResolveBinding(bindInfo, bind)) {
        Services().Warn("idFuncChain::BindEndPoint could not resolve binding");
    }
}

// Retail: 0x82C11C08 ?BuildPhysics@idFuncChain@@AAAXXZ
void idFuncChain::BuildPhysics() {
    if (generatedPhysics) {
        return;
    }
    generatedPhysics = true;
    if (brokenLink >= 0) {
        Services().DisablePhysics(*this);
        return;
    }
    Services().BuildPhysics(*this, false);
}

// Retail: 0x82C125D8 ?GetWorldPosition@idFuncChain@@ABA_NABUorigin_t@1@AAVidVec3@@AAVidMat3@@@Z
bool idFuncChain::GetWorldPosition(const origin_t& origin,
        idVec3& worldOrigin, idMat3& worldAxis) const {
    if (origin.bind.bindMaster.IsValid()) {
        if (Services().ResolveWorldPosition(origin, worldOrigin, worldAxis)) {
            return true;
        }
        worldOrigin.Zero();
        worldAxis = idMat3(1.0f);
        return false;
    }
    worldAxis = spawnOrientation;
    worldOrigin = spawnPosition + spawnOrientation * origin.position;
    return true;
}

// Retail: 0x82C13068 ?Spawn@idFuncChainGroup@@QAAXXZ
void idFuncChainGroup::Spawn() {
    activeChains.SetNum(chains.Num());
    for (int index = 0; index < activeChains.Num(); ++index) {
        activeChains[index] = true;
    }
}

// Retail: 0x82C130A0 ?Event_SpawnBindEndPoints@idFuncChain@@AAA?AVeventVoid@@XZ
eventVoid idFuncChain::Event_SpawnBindEndPoints() {
    BindEndPoint(chainDef.startBindInfo, state.start.bind);
    if (state.start.bind.bindMaster.IsValid()) {
        state.start.position.Zero();
    }
    BindEndPoint(chainDef.endBindInfo, state.end.bind);
    if (state.end.bind.bindMaster.IsValid()) {
        state.end.position.Zero();
    }
    for (int index = 0; index < collisions.Num(); ++index) {
        sphere_t& sphere = collisions[index];
        BindEndPoint(sphere.bindInfo, sphere.origin.bind);
    }
    return eventVoid();
}

// Retail: 0x82C13B10 ??0idVerletChain@@QAA@XZ
idVerletChain::idVerletChain()
    : constraints()
    , points()
    , orientations()
    , forces()
    , sphereCollisions()
    , planeCollisions()
    , refForward(0.0f, 0.0f, 0.0f)
    , refLeft(0.0f, 0.0f, 0.0f)
    , refDown(0.0f, 0.0f, 0.0f)
    , maxHealth(45.0f)
    , brokenPointIndex(-1)
    , settings()
    , cooldownTable() {
    cooldownTable.Clear();
    cooldownTable.SetOutputRange(0.0f, 1.0f);
    cooldownTable.SetClamp(true);
    cooldownTable.SetSpline(true);
    cooldownTable.AddValue(0.0f, 0.0f);
    cooldownTable.AddValue(0.039436601f, 0.081871301f);
    cooldownTable.AddValue(0.132394f, 0.24561401f);
    cooldownTable.AddValue(0.24507f, 0.40935701f);
    cooldownTable.AddValue(0.469484f, 0.654971f);
    cooldownTable.AddValue(0.72018802f, 0.859649f);
    cooldownTable.AddValue(1.0f, 1.0f);
    cooldownTable.Finalize();
}

// Retail: 0x82C13F58 ?BuildConstraints@idVerletChain@@QAAXM@Z
void idVerletChain::BuildConstraints(const float health) {
    constraints.Clear();
    orientations.Clear();
    brokenPointIndex = -1;
    if (points.Num() == 0) {
        maxHealth = health;
        refForward.Zero();
        refLeft.Zero();
        refDown.Zero();
        return;
    }
    if (settings.anchorStart) {
        points[0].anchor = true;
    }
    if (settings.anchorEnd) {
        points[points.Num() - 1].anchor = true;
    }
    for (int index = 0; index + 1 < points.Num(); ++index) {
        constraint_t constraint;
        constraint.index1 = index;
        constraint.index2 = index + 1;
        const float weight1 = points[index].anchor ? 0.0f : 1.0f;
        const float weight2 = points[index + 1].anchor ? 0.0f : 1.0f;
        const float totalWeight = weight1 + weight2;
        constraint.ratio1 = totalWeight > 0.0f
            ? weight1 / totalWeight : 0.0f;
        constraint.ratio2 = totalWeight > 0.0f
            ? weight2 / totalWeight : 0.0f;
        constraint.length = (points[index + 1].currentPos
            - points[index].currentPos).Length()
                * settings.lengthAdjustment;
        constraint.lengthSquared = constraint.length * constraint.length;
        constraints.Append(constraint);

        orientation_t orientation;
        orientation.index1 = static_cast<std::uint16_t>(index);
        orientation.index2 = static_cast<std::uint16_t>(index + 1);
        orientations.Append(orientation);
    }
    if (points.Num() == 1) {
        orientation_t orientation = {0, 0};
        orientations.Append(orientation);
    } else {
        orientations.Append(orientations[orientations.Num() - 1]);
    }
    maxHealth = health;
    for (int index = 0; index < points.Num(); ++index) {
        points[index].health = health;
        points[index].healthStamp = 0.0f;
        points[index].timeStamp = 0;
    }
    if (points.Num() > 1) {
        refForward = points[1].currentPos - points[0].currentPos;
        refForward.NormalizeFast();
        refLeft = std::fabs(refForward.z) < 0.9f
            ? idVec3(0.0f, 0.0f, 1.0f).Cross(refForward)
            : idVec3(0.0f, 1.0f, 0.0f).Cross(refForward);
        refLeft.NormalizeFast();
        refDown = refForward.Cross(refLeft);
        refDown.NormalizeFast();
    }
}

// Retail: 0x82C14290 ?Damage@idVerletChain@@QAA_NHHMAAUdamageMorph_t@@@Z
bool idVerletChain::Damage(const int constraintId, const int gameTime,
        const float damage, damageMorph_t& morph) {
    morph = damageMorph_t();
    if (constraintId < 0 || constraintId >= constraints.Num()
            || damage <= 0.0f || maxHealth <= 0.0f) {
        return false;
    }
    constraint_t& constraint = constraints[constraintId];
    const int index1 = constraint.index1;
    const int index2 = constraint.index2;
    if (index1 < 0 || index2 < 0 || index1 >= points.Num()
            || index2 >= points.Num()) {
        return false;
    }
    const int previous = constraintId > 0
        ? constraints[constraintId - 1].index1 : -1;
    const int next = constraintId + 1 < constraints.Num()
        ? constraints[constraintId + 1].index2 : -1;
    float previousHealth = previous >= 0
        ? points[previous].health : 0.0f;
    float nextHealth = next >= 0 ? points[next].health : 0.0f;
    if (previous >= 0 && previousHealth > 1.0f) {
        previousHealth = ClampFloat(previousHealth - damage * 0.5f,
            1.0f, previousHealth);
    }
    if (next >= 0 && nextHealth > 1.0f) {
        nextHealth = ClampFloat(nextHealth - damage * 0.5f,
            1.0f, nextHealth);
    }
    const float firstHealth = (std::max)(0.0f,
        points[index1].health - damage);
    const float secondHealth = (std::max)(0.0f,
        points[index2].health - damage);
    const bool broken = firstHealth < kEpsilon || secondHealth < kEpsilon;
    int cooldownStart = gameTime + 1000;
    if (broken) {
        brokenPointIndex = index2;
        particle_t duplicate = points[index2];
        duplicate.anchor = false;
        const int duplicateIndex = points.Append(duplicate);
        if (index1 >= 0 && index1 < orientations.Num()) {
            orientations[index1].index2 =
                static_cast<std::uint16_t>(duplicateIndex);
        }
        constraint.index2 = duplicateIndex;
        const float weight1 = points[index1].anchor ? 0.0f : 1.0f;
        const float weight2 = points[duplicateIndex].anchor ? 0.0f : 1.0f;
        const float totalWeight = weight1 + weight2;
        constraint.ratio1 = totalWeight > 0.0f
            ? weight1 / totalWeight : 0.0f;
        constraint.ratio2 = totalWeight > 0.0f
            ? weight2 / totalWeight : 0.0f;
        cooldownStart += 4000;
    }

    morph.amount[0] = 1.0f - previousHealth / maxHealth;
    morph.amount[1] = 1.0f - firstHealth / maxHealth;
    morph.amount[2] = 1.0f - secondHealth / maxHealth;
    morph.amount[3] = 1.0f - nextHealth / maxHealth;
    morph.index[0] = previous;
    morph.index[1] = index1;
    morph.index[2] = index2;
    morph.index[3] = next;

    const int affected[4] = {previous, index1, index2, next};
    const float healthValues[4] = {
        previousHealth, firstHealth, secondHealth, nextHealth};
    for (int slot = 0; slot < 4; ++slot) {
        const int pointIndex = affected[slot];
        if (pointIndex >= 0 && pointIndex < points.Num()) {
            points[pointIndex].health = healthValues[slot];
            points[pointIndex].healthStamp = healthValues[slot];
            points[pointIndex].timeStamp = cooldownStart;
        }
    }
    return broken;
}

// Retail: 0x82C14610 ?Update@idVerletChain@@QAAX_N0M@Z
void idVerletChain::Update(const bool clearCollisionSpheres,
        const bool isStiff, const float gravityScale) {
    if (!isStiff && settings.enabled) {
        Integrate(settings.frameSeconds, gravityScale);
        Constrain();
    }
    if (clearCollisionSpheres) {
        sphereCollisions.Clear();
        planeCollisions.Clear();
    }
}

// Retail: 0x82C146B8 ?AddCollisionPlane@idVerletChain@@QAAXABVidPlane@@_N1@Z
void idVerletChain::AddCollisionPlane(const idPlane& plane,
        const bool skipStart, const bool skipEnd) {
    plane_t collision;
    collision.plane = plane;
    if (!skipStart && !skipEnd) {
        collision.startIndex[0] = 0;
        collision.numPoints[0] = points.Num();
    } else if (skipStart) {
        collision.startIndex[0] = (std::max)(0, brokenPointIndex);
        collision.numPoints[0] = (std::max)(0,
            points.Num() - brokenPointIndex - 1);
    } else {
        collision.startIndex[0] = (std::max)(0, points.Num() - 1);
        collision.numPoints[0] = points.Num() > 0 ? 1 : 0;
        collision.startIndex[1] = 0;
        collision.numPoints[1] = (std::max)(0, brokenPointIndex);
    }
    planeCollisions.Append(collision);
}

// Retail: 0x82C147A0 ?Damage@idFuncChain@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
float idFuncChain::Damage(idEntity*, idEntity*,
        const idDeclDamage* const damageDef, const float damageScale,
        const idVec3& direction, trace_t* const trace) {
    if (damageDef == nullptr) {
        return 0.0f;
    }
    const unsigned int incomingTypes = Services().GetDamageTypes(damageDef);
    const bool fatalCut = Services().GetMaximumDamage(damageDef) >= maxHealth
        && (incomingTypes & kLaserCuttingDamage) != 0;
    if (!fatalCut && (damageTypes & incomingTypes) == 0) {
        return 0.0f;
    }
    float amount = Services().GetDamageAmount(damageDef) * damageScale;
    if (fatalCut) {
        amount = maxHealth + 1.0f;
    }
    idVec3 impact;
    if (!Services().GetTraceImpact(trace, impact)) {
        impact = breakPosition;
    }
    const idMat3 inverse = SafeInverse(spawnOrientation);
    const idVec3 localImpact = inverse * (impact - spawnPosition);
    const int point = verlet.GetBestPoint(localImpact);
    const int constraint = point >= 0
        ? verlet.GetBestConstraint(point, localImpact) : -1;
    if (constraint < 0) {
        return amount;
    }
    damageMorph_t morph;
    const bool broke = verlet.Damage(constraint,
        Services().GetGameTime(), amount, morph);
    for (int slot = 0; slot < 4; ++slot) {
        if (morph.index[slot] >= 0) {
            Services().SetLinkMorphAmount(
                *this, morph.index[slot], morph.amount[slot]);
        }
    }
    if (broke) {
        idVec3 localDirection = inverse * direction;
        if (localDirection.NormalizeFast() <= kEpsilon) {
            localDirection = verlet.refDown;
        }
        const int steps = (std::max)(1, static_cast<int>(
            std::ceil(0.2f / (std::max)(
                verlet.settings.frameSeconds, kEpsilon))));
        const idVec3 impulse = localDirection
            * ((std::max)(1.0f, amount) * 12.0f);
        verlet.forces.Append(idVerletChain::force_t(
            impulse, steps, morph.index[1]));
        verlet.forces.Append(idVerletChain::force_t(
            impulse, steps, morph.index[2]));
        brokenLink = morph.index[1];
        Services().RemoveSmoothSkinning(*this, brokenLink);
        DisableChain();
        breakPosition = impact;
        Services().StartBreakSound(*this);
    }
    return amount;
}

// Retail: 0x82C14BC0 ?AddCollisionInfo@idFuncChain@@AAAXXZ
void idFuncChain::AddCollisionInfo() {
    const idMat3 inverse = SafeInverse(spawnOrientation);
    for (int index = 0; index < collisions.Num(); ++index) {
        idVec3 worldOrigin;
        idMat3 worldAxis;
        GetWorldPosition(collisions[index].origin, worldOrigin, worldAxis);
        verlet.sphereCollisions.Append(idSphere(
            inverse * (worldOrigin - spawnPosition),
            collisions[index].radius));
    }
    for (int index = 0; index < collisionPlanes.Num(); ++index) {
        const plane_t& source = collisionPlanes[index];
        idVec3 normal = source.normal;
        normal.NormalizeFast();
        verlet.AddCollisionPlane(idPlane(normal, normal.Dot(source.center)),
            !source.startSegment, !source.endSegment);
    }
    for (int index = 0; index < animCollisions.Num(); ++index) {
        idEntity* const entity = Services().ResolveEntity(
            animCollisions[index].GetSpawnId());
        Services().GatherAnimatedCollisionSpheres(entity,
            spawnPosition, spawnOrientation, verlet.sphereCollisions);
    }
}

// Retail: 0x82C14FF0 ?Think@idFuncChain@@UAAXXZ
void idFuncChain::Think() {
    if (Services().IsDormant(*this)) {
        return;
    }
    const int renderPoints = verlet.orientations.Num();
    if (renderPoints <= 0 || verlet.points.Num() < renderPoints) {
        Services().Present(*this);
        return;
    }
    verlet.settings.frameSeconds = Services().GetFrameSeconds();
    const idMat3 inverse = SafeInverse(spawnOrientation);
    idVec3 startWorld;
    idVec3 endWorld;
    idMat3 endpointAxis;
    GetWorldPosition(state.start, startWorld, endpointAxis);
    GetWorldPosition(state.end, endWorld, endpointAxis);
    const idVec3 startLocal = inverse * (startWorld - spawnPosition);
    const idVec3 endLocal = inverse * (endWorld - spawnPosition);
    verlet.points[0].oldPos = startLocal;
    verlet.points[0].currentPos = startLocal;
    verlet.points[renderPoints - 1].oldPos = endLocal;
    verlet.points[renderPoints - 1].currentPos = endLocal;

    AddCollisionInfo();
    const bool stiff = chainDef.extraLength <= kEpsilon && brokenLink < 0;
    verlet.Update(true, stiff, brokenLink < 0 ? 0.25f : 1.0f);

    for (int index = 0; index < renderPoints; ++index) {
        const idVec3 normal = verlet.GetNormal(index);
        Services().SetLinkPosition(*this, index,
            verlet.points[index].currentPos,
            LinkAxis(normal, verlet.refLeft));
        float health = verlet.points[index].health;
        if (verlet.UpdateCooldown(index, Services().GetGameTime(), health)) {
            Services().SetLinkMorphAmount(*this, index,
                1.0f - ClampFloat(health / maxHealth, 0.0f, 1.0f));
        }
    }

    float maximumMovement = 0.0f;
    float averageMovement = 0.0f;
    if (brokenLink >= 0) {
        verlet.GetMovement(0, brokenLink,
            maximumMovement, averageMovement);
        const int firstSample = (std::max)(0, brokenLink / 2);
        Services().StartOrUpdateRattle(*this, 0,
            spawnPosition + spawnOrientation
                * verlet.points[firstSample].currentPos,
            averageMovement);
        verlet.GetMovement(brokenLink, renderPoints,
            maximumMovement, averageMovement);
        const int secondSample = (std::min)(renderPoints - 1,
            brokenLink + (renderPoints - brokenLink) / 2);
        Services().StartOrUpdateRattle(*this, 1,
            spawnPosition + spawnOrientation
                * verlet.points[secondSample].currentPos,
            averageMovement);
    } else {
        verlet.GetMovement(0, renderPoints,
            maximumMovement, averageMovement);
        Services().StartOrUpdateRattle(*this, 0,
            spawnPosition + spawnOrientation
                * verlet.points[renderPoints / 2].currentPos,
            averageMovement);
    }
    Services().Present(*this);
}

// Retail: 0x82C15F08 ?ForceUpdate@idVerletChain@@QAAXHM@Z
void idVerletChain::ForceUpdate(const int numSimulations,
        const float gravityScale) {
    for (int simulation = 0; simulation < numSimulations; ++simulation) {
        if (settings.enabled) {
            Integrate(settings.frameSeconds, gravityScale);
            Constrain();
        }
        if (simulation + 1 == numSimulations) {
            sphereCollisions.Clear();
            planeCollisions.Clear();
        }
    }
}

idFuncChain::binddef_t::binddef_t()
    : bindToObject(), bindToJoint(), bindToTag() {
}

idFuncChain::chaindef_t::chaindef_t()
    : startPosition(0.0f, 0.0f, 0.0f)
    , endPosition(0.0f, 0.0f, 0.0f)
    , extraLength(0.0f)
    , startBindInfo()
    , endBindInfo()
    , randomRotate(false)
    , smoothSkinning(false)
    , startRotation(0.0f) {
}

idFuncChain::bind_t::bind_t()
    : bindMaster()
    , bindJoint(-1)
    , bindTagParentJoint(0xFFFFu)
    , bindTagTranslation(0.0f, 0.0f, 0.0f)
    , bindTagAxis(1.0f) {
}

idFuncChain::origin_t::origin_t()
    : bind(), position(0.0f, 0.0f, 0.0f) {
}

idFuncChain::sphere_t::sphere_t()
    : bindInfo(), origin(), radius(0.0f) {
}

idFuncChain::plane_t::plane_t()
    : center(0.0f, 0.0f, 0.0f)
    , normal(0.0f, 0.0f, 1.0f)
    , startSegment(true)
    , endSegment(true) {
}

// Retail: 0x82C16020 ??0idFuncChain@@QAA@XZ
idFuncChain::idFuncChain()
    : name()
    , spawnPosition(0.0f, 0.0f, 0.0f)
    , spawnOrientation(1.0f)
    , chainLinkModel(nullptr)
    , chainDef()
    , chainGroup()
    , morphMaterial(nullptr)
    , collisions()
    , collisionPlanes()
    , animCollisions()
    , soundBreak(nullptr)
    , soundRattle(nullptr)
    , highlight(false)
    , damageTypes(kLaserCuttingDamage)
    , maxHealth(45.0f)
    , breakPosition(0.0f, 0.0f, 0.0f)
    , generatedPhysics(false)
    , state()
    , emitter1(nullptr)
    , emitter2(nullptr)
    , brokenLink(-1)
    , verlet()
    , physicsObject(nullptr) {
}

// Retail: 0x82C16230 ??1idFuncChain@@UAA@XZ
idFuncChain::~idFuncChain() {
    if (physicsObject != nullptr) {
        Services().DisablePhysics(*this);
        physicsObject = nullptr;
    }
    animCollisions.ClearFree();
    collisionPlanes.ClearFree();
    collisions.ClearFree();
}

// Retail: 0x82C16400 ?Spawn@idFuncChain@@QAAXXZ
void idFuncChain::Spawn() {
    if (chainLinkModel == nullptr) {
        Services().Warn("idFuncChain has a null chain link model");
        Services().RemoveEntity(*this);
        return;
    }
    idList<idVec3, 5> linkPositions;
    if (!Services().BuildRenderChain(*this, linkPositions)
            || linkPositions.Num() < 2) {
        const idVec3 difference =
            chainDef.endPosition - chainDef.startPosition;
        const float totalLength = difference.Length()
            + (std::max)(0.0f, chainDef.extraLength);
        const int linkCount = (std::max)(2,
            static_cast<int>(std::ceil(totalLength / 8.0f)) + 1);
        linkPositions.SetNum(linkCount);
        for (int index = 0; index < linkCount; ++index) {
            const float fraction = static_cast<float>(index)
                / static_cast<float>(linkCount - 1);
            linkPositions[index] = chainDef.startPosition
                + difference * fraction;
            linkPositions[index].z -= chainDef.extraLength
                * (4.0f * fraction * (1.0f - fraction));
        }
    }
    verlet.points.Clear();
    for (int index = 0; index < linkPositions.Num(); ++index) {
        verlet.points.Append(idVerletChain::particle_t(
            linkPositions[index]));
    }
    verlet.BuildConstraints(maxHealth);
    state.start.position = chainDef.startPosition;
    state.end.position = chainDef.endPosition;
    breakPosition = (chainDef.startPosition + chainDef.endPosition) * 0.5f;
    breakPosition.z -= chainDef.extraLength;
    Services().SetHighlight(*this, highlight);
    Services().Present(*this);
}

// Retail: 0x82C16940 ?InitialSetup@idFuncChain@@QAAXXZ
void idFuncChain::InitialSetup() {
    if (!generatedPhysics) {
        Event_SpawnBindEndPoints();
    }
    if (chainDef.extraLength > kEpsilon) {
        AddCollisionInfo();
        verlet.settings.frameSeconds = Services().GetFrameSeconds();
        verlet.ForceUpdate(16, brokenLink < 0 ? 0.25f : 1.0f);
    }
    BuildPhysics();
    Services().Present(*this);
}

void idFuncChain::SetServices(idFuncChainServices* const services) {
    chainServices = services == nullptr ? &defaultChainServices : services;
}

idFuncChainServices& idFuncChain::Services() {
    return *chainServices;
}
