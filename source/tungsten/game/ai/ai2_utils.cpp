#include "ai2_utils.h"

#include <cmath>

namespace {

constexpr float kRadiansToDegrees = 57.29577951308232f;

idMat3 DirectionToAxis(idVec3 direction) {
    if (direction.NormalizeFast() == 0.0f) {
        return idMat3(1.0f);
    }
    const float yaw = std::atan2(direction.y, direction.x)
        * kRadiansToDegrees;
    const float horizontal = std::sqrt(
        direction.x * direction.x + direction.y * direction.y);
    const float pitch = -std::atan2(direction.z, horizontal)
        * kRadiansToDegrees;
    return idAngles(pitch, yaw, 0.0f).ToMat3();
}

idVec3 TransformPoint(const idVec3& origin, const idMat3& axis,
        const idVec3& localPoint) {
    return origin + axis * localPoint;
}

bool GetWeaponPoint(const idAI2& ai, idWeapon* const weapon,
        const idAI2WeaponPoint_t point, idVec3& position,
        idMat3& axis) {
    if (weapon == nullptr) {
        return false;
    }
    idAI2WeaponPointRuntime runtime = {};
    if (!Tungsten_GetAI2WeaponPointRuntime(
            ai, *weapon, point, runtime)) {
        return false;
    }
    if (runtime.attachmentExists) {
        if (!runtime.attachmentValid) {
            return false;
        }
        if (!runtime.attachmentHasModel) {
            Tungsten_WarnAI2Utils(point == AI2_WEAPON_POINT_MUZZLE
                ? "GetMuzzlePoint - attachment has no model"
                : "GetLaserSightPoint - attachment has no model");
            return false;
        }
        if (!runtime.tagResolved) {
            position = runtime.modelOrigin;
            axis = runtime.modelAxis;
            return true;
        }
    } else if (!runtime.tagResolved) {
        return false;
    }
    position = runtime.tagOrigin;
    axis = runtime.tagAxis;
    return true;
}

} // namespace

// Retail symbol: ?CalcTrajectories@idAI2@@QAAXABVidVec3@@0PBV?$idTypesafeNumber@MW4secondUnique_t@@@@HPAVidTrajectory_Parabolic@@_N@Z
// EA: 0x82A39898, RVA: 0x00A39898
void idAI2::CalcTrajectories(const idVec3& start,
        const idVec3& destination,
        const idTypesafeNumber<float, secondUnique_t>* const travelTimes,
        const int numTravelTimes,
        idTrajectory_Parabolic* const trajectories,
        const bool deferred) {
    if (travelTimes == nullptr || numTravelTimes <= 0) {
        return;
    }
    const float gravityMagnitude =
        std::fabs(Tungsten_GetAI2GravityMagnitude());
    const float timeStep =
        Tungsten_GetAI2GameMillisecondsPerFrame() * 0.001f;
    for (int index = 0; index < numTravelTimes; ++index) {
        idTrajectory_Parabolic& trajectory =
            Tungsten_GetAI2TrajectoryElement(trajectories, index);
        Tungsten_CalculateAI2Trajectory(trajectory, start, destination,
            gravityMagnitude, travelTimes[index].value);
        Tungsten_TestAI2Trajectory(
            trajectory, timeStep, *this, deferred);
    }
}

// Retail symbol: ?CanThrowGrenade@idAI2@@QBA_NW4aiSelectCondition_t@@@Z
// EA: 0x82A39980, RVA: 0x00A39980
bool idAI2::CanThrowGrenade(const aiSelectCondition_t condition) const {
    idAI2ThrowAvailabilityRuntime runtime = {};
    if (condition < AISELECTCONDITION_ADVANCE
            || condition >= AISELECTCONDITION_MAX
            || !Tungsten_GetAI2ThrowAvailabilityRuntime(
                *this, runtime)) {
        return false;
    }
    return runtime.grenadesEnabled
        && (runtime.conditionFlags & 0x400) != 0
        && (runtime.conditionFlags & 0x8) == 0
        && runtime.conditionSelections[condition] != AIITEMSELECT_NONE
        && runtime.currentTime >= runtime.nextThrowTime;
}

// Retail symbol: ?SelectThrowable@idAI2@@QBA_NW4aiItemSelect_t@@ABVidVec3@@W4coverAction_t@@AAVidAIProjectileInfo@@@Z
// EA: 0x82A39A48, RVA: 0x00A39A48
bool idAI2::SelectThrowable(const aiItemSelect_t selectorType,
        const idVec3& targetPosition, const coverAction_t coverAction,
        idAIProjectileInfo& info) const {
    info.coverAction = coverAction;
    info.predictedTargetPos = targetPosition;
    idVec3 ownerOrigin;
    if (!Tungsten_GetAI2OwnerOrigin(*this, ownerOrigin)) {
        return false;
    }
    idAI2ItemTarget target;
    target.position = targetPosition;
    target.offsetFromOwner = targetPosition - ownerOrigin;
    target.distanceSquared = target.offsetFromOwner.LengthSqr();
    info.itemDecl = Tungsten_SelectAI2ProjectileItem(
        *this, selectorType, nullptr, target);
    return info.itemDecl != nullptr;
}

// Retail symbol: ?SelectAmmo@idAI2@@QBA_NW4aiItemSelect_t@@PBVidWeapon@@ABVidVec3@@W4coverAction_t@@AAVidAIProjectileInfo@@@Z
// EA: 0x82A39B88, RVA: 0x00A39B88
bool idAI2::SelectAmmo(const aiItemSelect_t selectorType,
        const idWeapon* const weapon, const idVec3& targetPosition,
        const coverAction_t coverAction,
        idAIProjectileInfo& info) const {
    info.coverAction = coverAction;
    info.predictedTargetPos = targetPosition;
    idVec3 ownerOrigin;
    if (weapon == nullptr
            || !Tungsten_GetAI2OwnerOrigin(*this, ownerOrigin)) {
        return false;
    }
    idAI2ItemTarget target;
    target.position = targetPosition;
    target.offsetFromOwner = targetPosition - ownerOrigin;
    target.distanceSquared = target.offsetFromOwner.LengthSqr();
    info.itemDecl = Tungsten_SelectAI2ProjectileItem(
        *this, selectorType, weapon, target);
    return info.itemDecl != nullptr;
}

// Retail symbol: ?WaitingOnTrajectoryTest@idAI2@@QBA_NXZ
// EA: 0x82A39CD0, RVA: 0x00A39CD0
bool idAI2::WaitingOnTrajectoryTest() const {
    for (int index = 0; index < 4; ++index) {
        if (Tungsten_AI2TrajectoryWaiting(
                Tungsten_GetAI2Trajectory(*this, index))) {
            return true;
        }
    }
    return false;
}

// Retail symbol: ?HasWaitingTrajectoryResults@idAI2@@QBA_NXZ
// EA: 0x82A39D48, RVA: 0x00A39D48
bool idAI2::HasWaitingTrajectoryResults() const {
    for (int index = 0; index < 4; ++index) {
        if (Tungsten_AI2TrajectoryHasResults(
                Tungsten_GetAI2Trajectory(*this, index))) {
            return true;
        }
    }
    return false;
}

// Retail symbol: ?ClearTrajectoryResults@idAI2@@QAAXXZ
// EA: 0x82A39DC0, RVA: 0x00A39DC0
void idAI2::ClearTrajectoryResults() {
    for (int index = 0; index < 4; ++index) {
        Tungsten_ClearAI2TrajectoryResults(
            Tungsten_GetAI2Trajectory(*this, index));
    }
}

// Retail symbol: ?GetAnimForOverride@idAI2@@QBAPBVidMD6Anim@@W4overrideAnim_t@@@Z
// EA: 0x82A39E18, RVA: 0x00A39E18
const idMD6Anim* idAI2::GetAnimForOverride(
        const overrideAnim_t overrideAnimation) const {
    return Tungsten_GetAI2AnimForOverride(*this, overrideAnimation);
}

// Retail symbol: ?GetMuzzlePoint@idAI2@@QBA_NPAVidWeapon@@AAVidVec3@@AAVidMat3@@@Z
// EA: 0x82A39E90, RVA: 0x00A39E90
bool idAI2::GetMuzzlePoint(idWeapon* const weapon,
        idVec3& muzzlePosition, idMat3& muzzleAxis) const {
    return GetWeaponPoint(*this, weapon, AI2_WEAPON_POINT_MUZZLE,
        muzzlePosition, muzzleAxis);
}

// Retail symbol: ?GetLaserSightPoint@idAI2@@QBA_NPAVidWeapon@@AAVidVec3@@AAVidMat3@@@Z
// EA: 0x82A3A040, RVA: 0x00A3A040
bool idAI2::GetLaserSightPoint(idWeapon* const weapon,
        idVec3& laserPosition, idMat3& laserAxis) const {
    return GetWeaponPoint(*this, weapon, AI2_WEAPON_POINT_LASER,
        laserPosition, laserAxis);
}

// Retail symbol: ?GetMinMaxRangedAttackDistancesForTargetPos@idAI2@@QBA_NW4aiItemSelect_t@@ABVidVec3@@AAVidAIProjectileInfo@@AAM333@Z
// EA: 0x82A3A298, RVA: 0x00A3A298
bool idAI2::GetMinMaxRangedAttackDistancesForTargetPos(
        const aiItemSelect_t selector, const idVec3& targetPosition,
        idAIProjectileInfo& projectileInfo, float& minimumRange,
        float& minimumOptimalRange, float& maximumOptimalRange,
        float& maximumRange) const {
    minimumRange = 0.0f;
    minimumOptimalRange = 0.0f;
    maximumOptimalRange = 0.0f;
    maximumRange = 0.0f;

    idAI2ProjectileDeclRuntime runtime = {};
    if (selector == AIITEMSELECT_IMP) {
        SelectThrowable(selector, targetPosition,
            COVERACTION_NONE, projectileInfo);
        if (projectileInfo.itemDecl == nullptr) {
            return false;
        }
        if (Tungsten_GetAI2ProjectileDeclRuntime(
                *projectileInfo.itemDecl, runtime)) {
            minimumRange = runtime.minimumRange;
            minimumOptimalRange = runtime.minimumOptimalRange;
            maximumOptimalRange = runtime.maximumOptimalRange;
            maximumRange = runtime.maximumRange;
        }
        // The retail path returns success once an item is selected even if
        // its declaration cannot be interpreted as throwable/ammo.
        return true;
    }
    if (Tungsten_GetAI2EquippedWeapon(*this) == nullptr
            || !Tungsten_GetAI2EquippedWeaponRanges(*this, runtime)) {
        return false;
    }
    minimumRange = runtime.minimumRange;
    minimumOptimalRange = runtime.minimumOptimalRange;
    maximumOptimalRange = runtime.maximumOptimalRange;
    maximumRange = runtime.maximumRange;
    return true;
}

// Retail symbol: ?TestParabolicTrajectories@idAI2@@QAA_NAAVidAIProjectileInfo@@PBVidCachedJoint@@ABVidVec3@@ABVidMat3@@V?$idTypesafeNumber@MW4secondUnique_t@@@@4@Z
// EA: 0x82A3A4A8, RVA: 0x00A3A4A8
bool idAI2::TestParabolicTrajectories(idAIProjectileInfo& info,
        const idCachedJoint* const cachedJoint, const idVec3& origin,
        const idMat3& axis,
        const idTypesafeNumber<float, secondUnique_t> minimumTime,
        const idTypesafeNumber<float, secondUnique_t> maximumTime) {
    (void)cachedJoint;
    (void)axis;
    const float interval = maximumTime.value - minimumTime.value;
    const idTypesafeNumber<float, secondUnique_t> travelTimes[4] = {
        maximumTime,
        idTypesafeNumber<float, secondUnique_t>(
            minimumTime.value + interval * 0.66000003f),
        idTypesafeNumber<float, secondUnique_t>(
            minimumTime.value + interval * 0.33000001f),
        minimumTime
    };
    idTrajectory_Parabolic* const trajectories =
        &Tungsten_GetAI2Trajectory(*this, 0);
    CalcTrajectories(origin, info.predictedTargetPos,
        travelTimes, 4, trajectories, true);
    return true;
}

// Retail symbol: ?TargetMovingPoint@idAI2@@SAXABVidVec3@@M00V?$idTypesafeNumber@MW4secondUnique_t@@@@1AAV2@2@Z
// EA: 0x82A3A568, RVA: 0x00A3A568
void idAI2::TargetMovingPoint(const idVec3& launchPoint,
        const float launchSpeed, const idVec3& targetPosition,
        const idVec3& targetVelocity,
        const idTypesafeNumber<float, secondUnique_t> lagTime,
        const idTypesafeNumber<float, secondUnique_t> animationDelay,
        idVec3& launchDirection, idVec3& predictedTargetPosition) {
    const float distance = (targetPosition - launchPoint).Length();
    const float flightTime = launchSpeed > 0.0f
        ? distance / launchSpeed : 0.0f;
    const float predictionTime =
        flightTime + lagTime.value + animationDelay.value;
    predictedTargetPosition =
        targetPosition + targetVelocity * predictionTime;
    launchDirection = predictedTargetPosition - launchPoint;
    launchDirection.NormalizeFast();
}

// Retail symbol: ?LaunchParabolicProjectile@idAI2@@QAA_NPBVidDeclProjectile@@ABUparabolicParms_t@idTrajectory_Parabolic@@ABVidVec3@@2H@Z
// EA: 0x82A3A688, RVA: 0x00A3A688
bool idAI2::LaunchParabolicProjectile(
        const idDeclProjectile* const projectileDecl,
        const idTrajectory_Parabolic::parabolicParms_t& trajectory,
        const idVec3& targetPosition, const idVec3& startPosition,
        const int startTime) {
    if (projectileDecl == nullptr) {
        return false;
    }
    const idVec3 direction = targetPosition - startPosition;
    const float yaw = std::atan2(direction.y, direction.x)
        * kRadiansToDegrees;
    const idMat3 fireAxis =
        idAngles(trajectory.angle, yaw, 0.0f).ToMat3();
    if (Tungsten_ShowAI2Trajectories()) {
        Tungsten_DrawAI2ParabolicTrajectory(startPosition,
            targetPosition, trajectory,
            Tungsten_GetAI2GameMillisecondsPerFrame() * 0.001f);
    }
    return Tungsten_LaunchAI2ProjectileEntity(*this, *projectileDecl,
        startPosition, fireAxis, false, idVec3(0.0f, 0.0f, 0.0f),
        trajectory.speed, startTime);
}

// Retail symbol: ?LeadTargetWithLinearProjectile@idAI2@@QBA_NABVidAIProjectileInfo@@ABVidVec3@@11AAV3@2@Z
// EA: 0x82A3A868, RVA: 0x00A3A868
bool idAI2::LeadTargetWithLinearProjectile(
        const idAIProjectileInfo& info,
        const idVec3& currentTargetPosition,
        const idVec3& currentTargetVelocity,
        const idVec3& projectileStartPosition,
        idVec3& extrapolatedPosition,
        idVec3& directionToExtrapolatedPosition) const {
    idVec3 actualDirection = info.actualTargetVel;
    idVec3 currentDirection = currentTargetVelocity;
    const float actualSpeed = actualDirection.NormalizeFast();
    const float currentSpeed = currentDirection.NormalizeFast();
    const bool velocityAligned = actualSpeed * actualSpeed >= 0.5f
        && currentSpeed * currentSpeed >= 0.5f
        && actualDirection.Dot(currentDirection) > -0.000000050005699f;

    const idVec3 targetPosition = velocityAligned
        ? currentTargetPosition
        : (currentTargetPosition + info.actualTargetPos) * 0.5f;
    const idVec3 targetVelocity = velocityAligned
        ? currentTargetVelocity : info.actualTargetVel;

    TargetMovingPoint(projectileStartPosition, info.linearParms.speed,
        targetPosition, targetVelocity,
        idTypesafeNumber<float, secondUnique_t>(
            Tungsten_GetAI2ThrowLagSeconds(*this)),
        idTypesafeNumber<float, secondUnique_t>(0.0f),
        directionToExtrapolatedPosition, extrapolatedPosition);
    return velocityAligned;
}

// Retail symbol: ?LaunchLinearProjectile@idAI2@@QAA_NPBVidDeclProjectile@@MABVidVec3@@11H@Z
// EA: 0x82A3AA88, RVA: 0x00A3AA88
bool idAI2::LaunchLinearProjectile(
        const idDeclProjectile* const projectileDecl, const float speed,
        const idVec3& startPosition, const idVec3& targetPosition,
        const idVec3& launchDirection, const int startTime) {
    if (projectileDecl == nullptr) {
        return false;
    }
    const idMat3 fireAxis = DirectionToAxis(launchDirection);
    return Tungsten_LaunchAI2ProjectileEntity(*this, *projectileDecl,
        startPosition, fireAxis, true, targetPosition, speed, startTime);
}

// Retail symbol: ?GetModelSpaceJointTransformForAnimEvent@idAI2@@QBAPBVidCachedJoint@@PBVidEventDef@@PBVidMD6Anim@@HAAVidVec3@@AAVidMat3@@AAV?$idTypesafeNumber@HW4millisecondUnique_t@@@@@Z
// EA: 0x82A3AB60, RVA: 0x00A3AB60
const idCachedJoint* idAI2::GetModelSpaceJointTransformForAnimEvent(
        const idEventDef* const eventDefinition,
        const idMD6Anim* const animation, const int cachedIndex,
        idVec3& jointOrigin, idMat3& jointAxis,
        idTypesafeNumber<int, millisecondUnique_t>& eventTime) const {
    if (eventDefinition == nullptr || animation == nullptr) {
        return nullptr;
    }
    int frameRate = 30;
    const idCachedJoint* const joint = Tungsten_GetAI2CachedJoint(
        *this, *eventDefinition, *animation, cachedIndex, frameRate);
    if (joint == nullptr) {
        return nullptr;
    }
    jointOrigin = joint->trans;
    jointAxis = joint->rot.ToMat3();
    if (frameRate <= 0) {
        frameRate = 30;
    }
    eventTime = 960 * static_cast<int>(joint->frameNum) / frameRate;
    return joint;
}

// Retail symbol: ?GetWorldSpaceJointTransformForAnimEvent@idAI2@@QBAPBVidCachedJoint@@PBVidEventDef@@PBVidMD6Anim@@HAAVidVec3@@AAVidMat3@@AAV?$idTypesafeNumber@HW4millisecondUnique_t@@@@@Z
// EA: 0x82A3AD50, RVA: 0x00A3AD50
const idCachedJoint* idAI2::GetWorldSpaceJointTransformForAnimEvent(
        const idEventDef* const eventDefinition,
        const idMD6Anim* const animation, const int cachedIndex,
        idVec3& worldOrigin, idMat3& worldAxis,
        idTypesafeNumber<int, millisecondUnique_t>& eventTime) const {
    idVec3 jointOrigin;
    idMat3 jointAxis;
    const idCachedJoint* const joint =
        GetModelSpaceJointTransformForAnimEvent(eventDefinition,
            animation, cachedIndex, jointOrigin, jointAxis, eventTime);
    if (joint == nullptr) {
        return nullptr;
    }
    idVec3 modelOrigin;
    idMat3 modelAxis;
    if (!Tungsten_GetAI2ModelTransform(*this, modelOrigin, modelAxis)) {
        return nullptr;
    }
    worldOrigin = TransformPoint(modelOrigin, modelAxis, jointOrigin);
    worldAxis = modelAxis * jointAxis;
    return joint;
}

// Retail symbol: ?GetCachedMuzzlePointForAnimEvent@idAI2@@QBAPBVidCachedJoint@@PBVidEventDef@@PAVidWeapon@@PBVidMD6Anim@@AAVidVec3@@AAVidMat3@@AAV?$idTypesafeNumber@HW4millisecondUnique_t@@@@@Z
// EA: 0x82A3AEA0, RVA: 0x00A3AEA0
const idCachedJoint* idAI2::GetCachedMuzzlePointForAnimEvent(
        const idEventDef* const eventDefinition, idWeapon* const weapon,
        const idMD6Anim* const animation, idVec3& muzzlePosition,
        idMat3& muzzleAxis,
        idTypesafeNumber<int, millisecondUnique_t>& eventTime) const {
    idVec3 modelOrigin;
    idMat3 modelAxis;
    if (!Tungsten_GetAI2ModelTransform(*this, modelOrigin, modelAxis)) {
        return nullptr;
    }
    muzzlePosition = modelOrigin;
    muzzleAxis = modelAxis;
    if (animation == nullptr || weapon == nullptr) {
        return nullptr;
    }
    idVec3 jointOrigin;
    idMat3 jointAxis;
    const idCachedJoint* const joint =
        GetModelSpaceJointTransformForAnimEvent(eventDefinition,
            animation, 0, jointOrigin, jointAxis, eventTime);
    if (joint == nullptr) {
        return nullptr;
    }
    idVec3 tagOrigin;
    idMat3 tagAxis;
    if (!Tungsten_GetAI2MuzzleTagData(
            *this, *weapon, tagOrigin, tagAxis)) {
        return nullptr;
    }
    const idVec3 localMuzzle =
        TransformPoint(jointOrigin, jointAxis, tagOrigin);
    muzzlePosition = TransformPoint(modelOrigin, modelAxis, localMuzzle);
    muzzleAxis = (tagAxis * jointAxis) * modelAxis;
    return joint;
}

// Retail symbol: ?LaunchProjectile@idAI2@@QAA_NPBVidEntity@@ABVaiSenseState_t@@AAVidAIProjectileInfo@@ABW4aiItemSelect_t@@@Z
// EA: 0x82A3B1F8, RVA: 0x00A3B1F8
bool idAI2::LaunchProjectile(const idEntity* const target,
        const aiSenseState_t& senseState,
        idAIProjectileInfo& projectileInfo,
        const aiItemSelect_t& itemSelect) {
    idAI2LaunchProjectileRuntime runtime = {};
    if (!Tungsten_GetAI2LaunchProjectileRuntime(
            *this, senseState, runtime)) {
        return false;
    }
    projectileInfo.itemDecl = nullptr;
    projectileInfo.coverAction = COVERACTION_NONE;
    projectileInfo.overrideAnim = ANIMOVERRIDE_THROW_PROJECTILE;
    projectileInfo.useMuzzleForLaunch = false;

    if (runtime.crouching) {
        projectileInfo.overrideAnim =
            ANIMOVERRIDE_CROUCHED_THROW_PROJECTILE;
    } else if (runtime.forwardVelocity > runtime.movingThrowSpeed) {
        projectileInfo.overrideAnim =
            ANIMOVERRIDE_MOVING_THROW_PROJECTILE;
    }

    const idCachedJoint* cachedJoint = nullptr;
    idTypesafeNumber<int, millisecondUnique_t> eventTime(0);
    idVec3 launchOrigin;
    idMat3 launchAxis;
    idAI2ProjectileDeclRuntime declarationRuntime = {};

    if (runtime.equippedWeapon != nullptr) {
        if (!SelectAmmo(itemSelect, runtime.equippedWeapon,
                runtime.confirmedOrigin, COVERACTION_NONE,
                projectileInfo)
                || projectileInfo.itemDecl == nullptr
                || !Tungsten_GetAI2ProjectileDeclRuntime(
                    *projectileInfo.itemDecl, declarationRuntime)) {
            return false;
        }
        const idMD6Anim* const animation =
            GetAnimForOverride(projectileInfo.overrideAnim);
        const idEventDef* eventDefinition =
            Tungsten_GetAI2ProjectileEventDef(
                AI2_PROJECTILE_EVENT_LAUNCH_ITEM);
        cachedJoint = GetCachedMuzzlePointForAnimEvent(eventDefinition,
            runtime.equippedWeapon, animation, launchOrigin,
            launchAxis, eventTime);
        if (cachedJoint == nullptr) {
            eventDefinition = Tungsten_GetAI2ProjectileEventDef(
                AI2_PROJECTILE_EVENT_LAUNCH_ITEM_FROM_WEAPON);
            cachedJoint = GetCachedMuzzlePointForAnimEvent(
                eventDefinition, runtime.equippedWeapon, animation,
                launchOrigin, launchAxis, eventTime);
        }
        if (itemSelect != AIITEMSELECT_CLUB_MUTANT) {
            projectileInfo.useMuzzleForLaunch = true;
        }
    } else {
        if (runtime.equippedThrowable != nullptr) {
            idAI2ProjectileDeclRuntime equippedRuntime = {};
            if (Tungsten_GetAI2ProjectileDeclRuntime(
                    *runtime.equippedThrowable, equippedRuntime)
                    && equippedRuntime.throwable) {
                projectileInfo.itemDecl = runtime.equippedThrowable;
            }
        }
        if (projectileInfo.itemDecl == nullptr
                && !SelectThrowable(itemSelect, runtime.confirmedOrigin,
                    COVERACTION_NONE, projectileInfo)) {
            return false;
        }
        if (projectileInfo.itemDecl == nullptr
                || !Tungsten_GetAI2ProjectileDeclRuntime(
                    *projectileInfo.itemDecl, declarationRuntime)) {
            return false;
        }
        const idMD6Anim* const animation =
            GetAnimForOverride(projectileInfo.overrideAnim);
        const idEventDef* const eventDefinition =
            Tungsten_GetAI2ProjectileEventDef(
                AI2_PROJECTILE_EVENT_LAUNCH_ITEM);
        cachedJoint = GetWorldSpaceJointTransformForAnimEvent(
            eventDefinition, animation, 0, launchOrigin,
            launchAxis, eventTime);
    }

    if (declarationRuntime.projectileDecl == nullptr
            || cachedJoint == nullptr) {
        Tungsten_WarnAI2Utils(
            "idAI2::LaunchProjectile - can't find cached joint");
        return false;
    }
    projectileInfo.target.SetSpawnId(
        Tungsten_GetAI2EntitySpawnId(target));
    projectileInfo.coverAction = COVERACTION_NONE;
    projectileInfo.actualTargetPos = runtime.confirmedEyePosition;
    projectileInfo.actualTargetVel = runtime.confirmedVelocity;
    projectileInfo.jointIndex = cachedJoint->jointIndex;
    projectileInfo.nodeIndex.Invalidate();

    if (declarationRuntime.parabolicFlight) {
        projectileInfo.predictedTargetPos =
            projectileInfo.actualTargetPos;
        if (itemSelect == AIITEMSELECT_SCOOP_MUTANT) {
            Tungsten_ExtrapolateAI2SensePosition(
                senseState, 1.0f, projectileInfo.predictedTargetPos);
        }
        if (!TestParabolicTrajectories(projectileInfo, cachedJoint,
                launchOrigin, launchAxis,
                idTypesafeNumber<float, secondUnique_t>(
                    declarationRuntime.minimumTrajectoryTime),
                idTypesafeNumber<float, secondUnique_t>(
                    declarationRuntime.maximumTrajectoryTime))) {
            return false;
        }
    } else {
        idVec3 launchDirection;
        TargetMovingPoint(launchOrigin, declarationRuntime.speed,
            runtime.confirmedEyePosition, runtime.confirmedVelocity,
            idTypesafeNumber<float, secondUnique_t>(
                runtime.throwLagMilliseconds * 0.001f),
            idTypesafeNumber<float, secondUnique_t>(
                eventTime.value * 0.001f),
            launchDirection, projectileInfo.predictedTargetPos);
        projectileInfo.linearParms.time = 0.0f;
        projectileInfo.linearParms.speed = declarationRuntime.speed;
        projectileInfo.linearParms.gravity = 0.0f;
    }
    Tungsten_StoreAI2ProjectileInfo(*this, projectileInfo);
    return true;
}

// Retail symbol: ?CheckGrenadeThrow@idAI2@@QAA_NAAVidAIProjectileInfo@@@Z
// EA: 0x82A3B758, RVA: 0x00A3B758
bool idAI2::CheckGrenadeThrow(idAIProjectileInfo& info) {
    if (info.itemDecl == nullptr) {
        return false;
    }
    const idMD6Anim* animation = nullptr;
    if (!Tungsten_GetAI2GrenadeAnimation(
            *this, info.coverAction, info.nodeIndex, animation)
            || animation == nullptr) {
        return false;
    }
    const idEventDef* const eventDefinition =
        Tungsten_GetAI2ProjectileEventDef(
            AI2_PROJECTILE_EVENT_THROW_GRENADE);
    idVec3 throwOrigin;
    idMat3 throwAxis;
    idTypesafeNumber<int, millisecondUnique_t> eventTime(0);
    const idCachedJoint* const cachedJoint =
        GetWorldSpaceJointTransformForAnimEvent(eventDefinition,
            animation, 0, throwOrigin, throwAxis, eventTime);
    if (cachedJoint == nullptr) {
        return false;
    }
    info.jointIndex = cachedJoint->jointIndex;

    idAI2ProjectileDeclRuntime runtime = {};
    if (!Tungsten_GetAI2ProjectileDeclRuntime(
            *info.itemDecl, runtime) || !runtime.throwable) {
        Tungsten_WarnAI2Utils(
            "AI attempted to throw a non-throwable item");
        return false;
    }
    if (Tungsten_AI2GrenadeOriginOverlapsGroupMember(
            *this, throwOrigin)) {
        return false;
    }
    return TestParabolicTrajectories(info, cachedJoint,
        throwOrigin, throwAxis,
        idTypesafeNumber<float, secondUnique_t>(
            runtime.minimumTrajectoryTime),
        idTypesafeNumber<float, secondUnique_t>(
            runtime.maximumTrajectoryTime));
}
