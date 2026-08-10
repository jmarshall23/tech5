#include "animfsm_deltacorrection.h"

#include <algorithm>
#include <cmath>

namespace {

constexpr float kEpsilon = 1.0e-20f;

bool HasMagnitude(const idVec3& value) {
    return value.LengthSqr() > kEpsilon;
}

float ClampSymmetric(const float value, const float maximum) {
    if (std::fabs(maximum) < kEpsilon) {
        return value;
    }
    const float limit = std::fabs(maximum);
    return (std::max)(-limit, (std::min)(limit, value));
}

idVec3 ClampComponents(idVec3 value, const idVec3& maximum) {
    value.x = ClampSymmetric(value.x, maximum.x);
    value.y = ClampSymmetric(value.y, maximum.y);
    value.z = ClampSymmetric(value.z, maximum.z);
    return value;
}

idVec3 LocalToWorld(const idMat3& axis, const idVec3& value) {
    return axis.Transpose() * value;
}

idVec3 WorldToLocal(const idMat3& axis, const idVec3& value) {
    return axis * value;
}

idVec3 ScaleComponents(const idVec3& value, const idVec3& scale) {
    return idVec3(value.x * scale.x,
        value.y * scale.y, value.z * scale.z);
}

idMat3 DirectionToAxis(idVec3 direction) {
    if (direction.NormalizeFast() == 0.0f) {
        return idMat3(1.0f);
    }
    constexpr float radiansToDegrees = 57.29577951308232f;
    const float yaw = std::atan2(direction.y, direction.x)
        * radiansToDegrees;
    const float horizontal = std::sqrt(direction.x * direction.x
        + direction.y * direction.y);
    const float pitch = std::atan2(-direction.z, horizontal)
        * radiansToDegrees;
    return idAngles(pitch, yaw, 0.0f).ToMat3();
}

idAngles MatrixToAngles(const idMat3& matrix) {
    constexpr float radiansToDegrees = 57.29577951308232f;
    const float horizontal = std::sqrt(matrix[0].x * matrix[0].x
        + matrix[0].y * matrix[0].y);
    const float pitch = std::atan2(-matrix[0].z, horizontal)
        * radiansToDegrees;
    const float yaw = std::atan2(matrix[0].y, matrix[0].x)
        * radiansToDegrees;
    const float roll = std::atan2(-matrix[1].z, matrix[2].z)
        * radiansToDegrees;
    return idAngles(pitch, yaw, roll);
}

idMat3 InverseRotation(const idMat3& matrix) {
    return matrix.Transpose();
}

bool ResolveAnimTransform(const idMD6Anim& anim, const bool end,
        const int requestedFrame, const idCachedJoint* const joint,
        idAnimDeltaTransform& transform, int& resolvedFrame) {
    int numFrames = 0;
    idAnimDeltaTransform animationTransform;
    const bool hasAnimationTransform = Tungsten_GetAnimDeltaTransform(
        anim, end, animationTransform, numFrames);
    if (requestedFrame > -1 && joint != nullptr
        && Tungsten_GetCachedJointAnimDeltaTransform(*joint, transform)) {
        resolvedFrame = requestedFrame;
        return true;
    }
    resolvedFrame = end ? numFrames : 0;
    transform = animationTransform;
    return hasAnimationTransform;
}

int FrameToMilliseconds(const idAnimBaseFSM& fsm,
        const idMD6Anim& anim, const int frame) {
    int frameTime = 0;
    int frameRate = 0;
    int millisecondsPerSecond = 0;
    if (!Tungsten_GetAnimDeltaTiming(fsm, anim, frameTime,
            frameRate, millisecondsPerSecond) || frameRate <= 0) {
        return 0;
    }
    return millisecondsPerSecond * frame / frameRate;
}

float RemainingScale(const float frames, const bool ignoreFrames) {
    if (ignoreFrames) {
        return 1.0f;
    }
    return frames < 1.0f ? 1.0f : frames;
}

} // namespace

// Retail symbol: ?SameSignRelaxed@@YA_NMMM@Z
// EA: 0x82A798E0, RVA: 0x00A798E0
bool SameSignRelaxed(const float x, const float y,
        const float tolerance) {
    return (x >= -tolerance) == (y >= -tolerance)
        || (x < tolerance) == (y < tolerance);
}

idAnimBaseFSM::idAnimBaseFSM()
    : ai(nullptr)
    , currentStateFlags(0)
    , animDeltaCorrection()
    , navNextPos(0.0f, 0.0f, 0.0f)
    , nextArrivalPos(0.0f, 0.0f, 0.0f)
    , nextArrivalAxis(1.0f)
    , intermediateMoveDestination(0.0f, 0.0f, 0.0f)
    , traversalEndpoint(0.0f, 0.0f, 0.0f)
    , firstCachedCorner(0.0f, 0.0f, 0.0f)
    , cachedCornerCount(0)
    , orientMoveIdealDir(1.0f, 0.0f, 0.0f)
    , orientMoveAxis(1.0f)
    , orientBodyIdealDir(1.0f, 0.0f, 0.0f)
    , orientBodyAxis(1.0f)
    , moveOrientationOnPath(false)
    , animDeltaMode(0) {
}

// Retail symbol: ?AnimEvent_AnimDeltaCorrectionSetFlags@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4aiAnimDCFlags_t@@@Z
// EA: 0x82A799D8, RVA: 0x00A799D8
eventVoid idAI2::AnimEvent_AnimDeltaCorrectionSetFlags(
        const idMD6Anim*, const aiAnimDCFlags_t flags) {
    animDeltaCorrectionInput_t& input =
        Tungsten_GetAnimDeltaFSM(*this).animDeltaCorrection.in;
    if ((flags & DC_ROTATION_IGNORES_REMAINING_FRAMES) != 0) {
        input.rotationIgnoresRemainingFrames =
            !input.rotationIgnoresRemainingFrames;
    }
    if ((flags & DC_NO_RESTRICT_ROTATION_DIRECTION_YAW) != 0) {
        input.restrictRotationDirectionYaw =
            !input.restrictRotationDirectionYaw;
    }
    if ((flags & DC_RESTRICT_ROTATION_DIRECTION_PITCH) != 0) {
        input.restrictRotationDirectionPitch =
            !input.restrictRotationDirectionPitch;
    }
    if ((flags & DC_RESTRICT_ROTATION_DIRECTION_ROLL) != 0) {
        input.restrictRotationDirectionRoll =
            !input.restrictRotationDirectionRoll;
    }
    if ((flags & DC_NO_REVERSE_ROTATION) != 0) {
        input.noReverseRotation = !input.noReverseRotation;
    }
    if ((flags & DC_TRANSLATION_IGNORES_REMAINING_FRAMES) != 0) {
        input.translationIgnoresRemainingFrames =
            !input.translationIgnoresRemainingFrames;
    }
    if ((flags & DC_LERP_ONLY_MODEL_SPACE_X) != 0) {
        input.lerpOnlyModelSpaceX = !input.lerpOnlyModelSpaceX;
    }
    if ((flags & DC_LERP_ONLY_MODEL_SPACE_Y) != 0) {
        input.lerpOnlyModelSpaceY = !input.lerpOnlyModelSpaceY;
    }
    if ((flags & DC_LERP_ONLY_MODEL_SPACE_Z) != 0) {
        input.lerpOnlyModelSpaceZ = !input.lerpOnlyModelSpaceZ;
    }
    if ((flags & DC_CORRECT_TRANSLATED_ROTATION) != 0) {
        input.correctTranslatedRotation = !input.correctTranslatedRotation;
    }
    if ((flags & DC_NO_DELTA_REBUILD) != 0) {
        input.noDeltaRebuild = !input.noDeltaRebuild;
    }
    return eventVoid();
}

// Retail symbol: ?AnimEvent_AnimDeltaCorrectionRotationRate@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@MMM@Z
// EA: 0x82A79B70, RVA: 0x00A79B70
eventVoid idAI2::AnimEvent_AnimDeltaCorrectionRotationRate(
        const idMD6Anim*, const float rotationRateMax,
        const float rotationMinScale, const float rotationMaxScale) {
    animDeltaCorrectionInput_t& input =
        Tungsten_GetAnimDeltaFSM(*this).animDeltaCorrection.in;
    input.rotationRateMax = rotationRateMax;
    input.rotationMaxScale = rotationMaxScale;
    input.rotationMinScale = rotationMinScale;
    return eventVoid();
}

// Retail symbol: ?GetRemainingFramesToTime@idAnimBaseFSM@@IAAMH@Z
// EA: 0x82A79B98, RVA: 0x00A79B98
float idAnimBaseFSM::GetRemainingFramesToTime(const int time) const {
    if (animDeltaCorrection.anim == nullptr) {
        return 0.0f;
    }
    int frameTime = 0;
    int frameRate = 0;
    int millisecondsPerSecond = 0;
    if (!Tungsten_GetAnimDeltaTiming(*this, *animDeltaCorrection.anim,
            frameTime, frameRate, millisecondsPerSecond)
        || millisecondsPerSecond == 0) {
        return 0.0f;
    }
    return static_cast<float>(frameRate * (time - frameTime))
        / static_cast<float>(millisecondsPerSecond);
}

// Retail symbol: ?ResetAnimDeltaCorrection@idAnimBaseFSM@@QAAXXZ
// EA: 0x82A79C70, RVA: 0x00A79C70
void idAnimBaseFSM::ResetAnimDeltaCorrection() {
    const aiAnimDCIdealPoint_t pointOverride =
        animDeltaCorrection.idealPointOverride;
    const aiAnimDCIdealDir_t directionOverride =
        animDeltaCorrection.idealDirOverride;
    animDeltaCorrection = animDeltaCorrection_t();
    animDeltaCorrection.idealPointOverride = pointOverride;
    animDeltaCorrection.idealDirOverride = directionOverride;
    animDeltaCorrection.in.allowYawCorrection = true;
    idVec3 origin;
    idMat3 axis;
    if (Tungsten_GetAnimDeltaAnimatorPose(*this, origin, axis)) {
        animDeltaCorrection.uncorrectedAxis = axis;
        animDeltaCorrection.startOrigin = origin;
    }
}

// Retail symbol: ?BeginAnimDeltaCorrectionRotation@idAnimBaseFSM@@QAAXPBVidMD6Anim@@PBVidDeclAnimWebNode@@W4aiAnimDCIdealDir_t@@HHHPBVidCachedJoint@@3@Z
// EA: 0x82A79E18, RVA: 0x00A79E18
void idAnimBaseFSM::BeginAnimDeltaCorrectionRotation(
        const idMD6Anim* const anim, const idDeclAnimWebNode* const node,
        const aiAnimDCIdealDir_t requestedIdealDir,
        const int startFrame, int endFrame, int goalFrame,
        const idCachedJoint* const endJoint,
        const idCachedJoint* const goalJoint) {
    if (anim == nullptr || (currentStateFlags & 2u) != 0) {
        return;
    }
    animDeltaCorrection.idealDir =
        animDeltaCorrection.idealDirOverride != IDEALDIR_NONE
        ? animDeltaCorrection.idealDirOverride : requestedIdealDir;
    if (animDeltaCorrection.idealDir == IDEALDIR_NOOP) {
        return;
    }
    animDeltaCorrection.correctRotation = true;
    animDeltaCorrection.useDeltaCorrection = true;
    animDeltaCorrection.animHasRemainingDelta = true;
    Tungsten_GetAnimDeltaAIOrigin(*this, animDeltaCorrection.startOrigin);

    idVec3 origin;
    Tungsten_GetAnimDeltaAIOrigin(*this, origin);
    switch (animDeltaCorrection.idealDir) {
        case IDEALDIR_MOVEORIENTATION:
            animDeltaCorrection.endDir = orientMoveIdealDir;
            break;
        case IDEALDIR_GOALORIENTATION:
            animDeltaCorrection.endDir = nextArrivalAxis[0];
            break;
        case IDEALDIR_TONEXTPOINT:
        case IDEALDIR_TOGOALPOINT:
            animDeltaCorrection.endDir = navNextPos - origin;
            if (!HasMagnitude(animDeltaCorrection.endDir)) {
                animDeltaCorrection.endDir = orientBodyAxis[0];
            }
            break;
        case IDEALDIR_CURRENT_ANIMNODE:
            animDeltaCorrection.endDir =
                animDeltaCorrection.currentAnimnodeAxis[0];
            break;
        case IDEALDIR_CURRENT_REF_AXIS:
            animDeltaCorrection.endDir = animDeltaCorrection.currentRefAxis[0];
            break;
        default:
            animDeltaCorrection.endDir = orientBodyIdealDir;
            break;
    }

    idAnimDeltaTransform endTransform;
    ResolveAnimTransform(*anim, true, endFrame, endJoint,
        endTransform, endFrame);
    animDeltaCorrection.animSpaceEndRotation = endJoint != nullptr
        ? InverseRotation(endTransform.rotation) : endTransform.rotation;
    animDeltaCorrection.animSpaceEndRotationTranslation =
        endTransform.translation;

    if (animDeltaCorrection.idealDir
            == IDEALDIR_DEPARTURE_PATH_DIRECTION) {
        animDeltaCorrection.animSpaceGoalRotation = endTransform.rotation;
        if (goalFrame > -1 && goalJoint != nullptr) {
            idAnimDeltaTransform goalTransform;
            Tungsten_GetCachedJointAnimDeltaTransform(
                *goalJoint, goalTransform);
            animDeltaCorrection.animSpaceGoalRotationTranslation =
                goalTransform.translation;
        } else {
            goalFrame = endFrame;
            animDeltaCorrection.animSpaceGoalRotationTranslation =
                animDeltaCorrection.animSpaceEndRotationTranslation;
        }
    } else if (goalFrame > -1 && goalJoint != nullptr) {
        idAnimDeltaTransform goalTransform;
        Tungsten_GetCachedJointAnimDeltaTransform(*goalJoint, goalTransform);
        animDeltaCorrection.animSpaceGoalRotation =
            InverseRotation(goalTransform.rotation);
        animDeltaCorrection.animSpaceGoalRotationTranslation =
            goalTransform.translation;
    } else {
        const bool useStart = animDeltaCorrection.idealDir
            == IDEALDIR_CURRENT_ANIMNODE;
        idAnimDeltaTransform goalTransform;
        int numFrames = 0;
        Tungsten_GetAnimDeltaTransform(
            *anim, !useStart, goalTransform, numFrames);
        goalFrame = useStart ? 0 : numFrames;
        animDeltaCorrection.animSpaceGoalRotation = goalTransform.rotation;
        animDeltaCorrection.animSpaceGoalRotationTranslation =
            goalTransform.translation;
    }

    animDeltaCorrection.rotationGoalPriorToEnd = goalFrame < endFrame;
    animDeltaCorrection.anim = anim;
    animDeltaCorrection.node = node;
    animDeltaCorrection.rotationEndTime =
        FrameToMilliseconds(*this, *anim, endFrame);
    animDeltaCorrection.rotationGoalTime =
        FrameToMilliseconds(*this, *anim, goalFrame);
    animDeltaCorrection.previousRemainingRotationFrames =
        GetRemainingFramesToTime(animDeltaCorrection.rotationEndTime);
    animDeltaCorrection.previousRemainingRotationFramesToGoal =
        GetRemainingFramesToTime(animDeltaCorrection.rotationGoalTime);
    if (startFrame == 0) {
        animDeltaCorrection.skipFirstFrame = true;
    }
}

// Retail symbol: ?GetDeltaCorrectionGoalOrigin@idAnimBaseFSM@@IBA?AVidVec3@@XZ
// EA: 0x82A7A4E8, RVA: 0x00A7A4E8
idVec3 idAnimBaseFSM::GetDeltaCorrectionGoalOrigin() const {
    switch (animDeltaCorrection.idealPoint) {
        case IDEALPOINT_CURRENT_REF_PT:
        case IDEALPOINT_FLIGHT_ANIM:
            return animDeltaCorrection.currentRefOrigin;
        case IDEALPOINT_ENEMYORIGIN: {
            idVec3 enemyOrigin;
            if (Tungsten_GetAnimDeltaEnemyOrigin(*this, enemyOrigin)) {
                return enemyOrigin;
            }
            idVec3 ownOrigin;
            Tungsten_GetAnimDeltaAIOrigin(*this, ownOrigin);
            return ownOrigin;
        }
        default:
            return animDeltaCorrection.endPoint;
    }
}

// Retail symbol: ?GetDeltaCorrectionGoalRotation@idAnimBaseFSM@@IBA?AVidMat3@@PBUdeltaCorrectionGoalRotationParms_t@1@@Z
// EA: 0x82A7A5F0, RVA: 0x00A7A5F0
idMat3 idAnimBaseFSM::GetDeltaCorrectionGoalRotation(
        const deltaCorrectionGoalRotationParms_t* const parms) const {
    const idVec3 source = parms != nullptr
        ? parms->sourcePosition : animDeltaCorrection.startOrigin;
    switch (animDeltaCorrection.idealDir) {
        case IDEALDIR_BODYORIENTATION:
            return DirectionToAxis(orientBodyIdealDir);
        case IDEALDIR_MOVEORIENTATION:
            return DirectionToAxis(orientMoveIdealDir);
        case IDEALDIR_TONEXTPOINT:
            return cachedCornerCount > 0
                ? DirectionToAxis(navNextPos - source)
                : DirectionToAxis(orientMoveIdealDir);
        case IDEALDIR_TOENEMY: {
            idVec3 enemyOrigin;
            return Tungsten_GetAnimDeltaEnemyOrigin(*this, enemyOrigin)
                ? DirectionToAxis(enemyOrigin - source)
                : DirectionToAxis(animDeltaCorrection.endDir);
        }
        case IDEALDIR_CURRENT_REF_AXIS:
            return animDeltaCorrection.currentRefAxis;
        case IDEALDIR_DEPARTURE_PATH_DIRECTION:
            if (parms != nullptr) {
                idVec3 closest;
                idVec3 direction;
                if (Tungsten_GetAnimDeltaPathDirection(*this,
                        parms->sourcePosition,
                        parms->worldSpaceAnimGoalOrigin,
                        closest, direction)) {
                    return DirectionToAxis(direction);
                }
            }
            return DirectionToAxis(orientMoveIdealDir);
        default:
            return DirectionToAxis(animDeltaCorrection.endDir);
    }
}

// Retail symbol: ?CheckResetAnimDeltaCorrection@idAnimBaseFSM@@QAAXPBVidDeclAnimWebNode@@@Z
// EA: 0x82A7AB00, RVA: 0x00A7AB00
void idAnimBaseFSM::CheckResetAnimDeltaCorrection(
        const idDeclAnimWebNode* const node) {
    if ((!animDeltaCorrection.correctRotation
            && !animDeltaCorrection.correctTranslation)
        || animDeltaCorrection.node == node) {
        ResetAnimDeltaCorrection();
    }
}

// Retail symbol: ?BeginAnimDeltaCorrectionTranslation@idAnimBaseFSM@@QAAXPBVidMD6Anim@@PBVidDeclAnimWebNode@@W4aiAnimDCIdealPoint_t@@HHHPBVidCachedJoint@@3_N@Z
// EA: 0x82A7AB30, RVA: 0x00A7AB30
void idAnimBaseFSM::BeginAnimDeltaCorrectionTranslation(
        const idMD6Anim* const anim, const idDeclAnimWebNode* const node,
        const aiAnimDCIdealPoint_t requestedIdealPoint,
        const int startFrame, int endFrame, int goalFrame,
        const idCachedJoint* const endJoint,
        const idCachedJoint* const goalJoint, const bool correctGravity) {
    if (anim == nullptr || (currentStateFlags & 2u) != 0) {
        return;
    }
    animDeltaCorrection.idealPoint =
        animDeltaCorrection.idealPointOverride != IDEALPOINT_NONE
        ? animDeltaCorrection.idealPointOverride : requestedIdealPoint;
    if (animDeltaCorrection.idealPoint == IDEALPOINT_NOOP) {
        return;
    }
    animDeltaCorrection.correctTranslation = true;
    animDeltaCorrection.useDeltaCorrection = true;
    animDeltaCorrection.animHasRemainingDelta = true;
    Tungsten_SetAnimDeltaCorrectGravity(*this, correctGravity);

    idAnimDeltaTransform endTransform;
    ResolveAnimTransform(*anim, true, endFrame, endJoint,
        endTransform, endFrame);
    animDeltaCorrection.animSpaceEndTranslation = endTransform.translation;
    if (goalFrame > -1 && goalJoint != nullptr) {
        idAnimDeltaTransform goalTransform;
        Tungsten_GetCachedJointAnimDeltaTransform(*goalJoint, goalTransform);
        animDeltaCorrection.animSpaceGoalTranslation =
            goalTransform.translation;
    } else {
        const bool useStart = animDeltaCorrection.idealPoint
            == IDEALPOINT_CURRENT_ANIMNODE;
        idAnimDeltaTransform goalTransform;
        int numFrames = 0;
        Tungsten_GetAnimDeltaTransform(
            *anim, !useStart, goalTransform, numFrames);
        goalFrame = useStart ? 0 : numFrames;
        animDeltaCorrection.animSpaceGoalTranslation =
            goalTransform.translation;
    }
    animDeltaCorrection.translationGoalPriorToEnd = goalFrame < endFrame;
    animDeltaCorrection.anim = anim;
    animDeltaCorrection.node = node;
    animDeltaCorrection.translationEndTime =
        FrameToMilliseconds(*this, *anim, endFrame);
    animDeltaCorrection.previousRemainingTranslationFrames =
        GetRemainingFramesToTime(animDeltaCorrection.translationEndTime);
    if (startFrame == 0) {
        animDeltaCorrection.skipFirstFrame = true;
    }

    idVec3 origin;
    idMat3 axis;
    Tungsten_GetAnimDeltaAnimatorPose(*this, origin, axis);
    idVec3 direction = GetDeltaCorrectionGoalOrigin() - origin;
    direction.NormalizeFast();
    animDeltaCorrection.useUncorrectedAxis =
        axis[0].Dot(direction) > 0.95f;
    animDeltaCorrection.uncorrectedAxis = axis;

    switch (animDeltaCorrection.idealPoint) {
        case IDEALPOINT_GOALPOINT:
            animDeltaCorrection.endPoint = nextArrivalPos;
            break;
        case IDEALPOINT_NEXTPOINT:
            animDeltaCorrection.endPoint = navNextPos;
            break;
        case IDEALPOINT_CURRENT_ANIMNODE:
            animDeltaCorrection.endPoint =
                animDeltaCorrection.currentAnimnodeOrigin;
            break;
        case IDEALPOINT_CURRENT_REF_PT:
            animDeltaCorrection.endPoint = animDeltaCorrection.currentRefOrigin;
            break;
        case IDEALPOINT_ENEMYORIGIN:
            if (!Tungsten_GetAnimDeltaEnemyOrigin(
                    *this, animDeltaCorrection.endPoint)) {
                Tungsten_GetAnimDeltaAIOrigin(
                    *this, animDeltaCorrection.endPoint);
            }
            break;
        case IDEALPOINT_NEXTGROUNDPOINT: {
            const idVec3 start = intermediateMoveDestination
                + idVec3(0.0f, 0.0f, 32.0f);
            const idVec3 end = start - idVec3(0.0f, 0.0f, 1024.0f);
            animDeltaCorrection.endPoint = end;
            idVec3 hit;
            if (Tungsten_TraceAnimDeltaGround(*this, start, end, hit)) {
                animDeltaCorrection.endPoint = hit;
            }
            break;
        }
        case IDEALPOINT_FLIGHT_ANIM: {
            idVec3 animationTranslation;
            animDeltaCorrection.in.translationCorrectionMaxScale = 1.5f;
            if (!Tungsten_GetAnimDeltaAnimationTranslation(
                    *anim, animationTranslation)) {
                animationTranslation.Zero();
            }
            idVec3 aiOrigin;
            Tungsten_GetAnimDeltaAIOrigin(*this, aiOrigin);
            animDeltaCorrection.currentRefOrigin = aiOrigin
                + LocalToWorld(axis, animationTranslation);
            if (cachedCornerCount > 0) {
                animDeltaCorrection.currentRefOrigin = firstCachedCorner;
            }
            break;
        }
        case IDEALPOINT_TRAVERSAL_ENDPOINT:
            animDeltaCorrection.endPoint = traversalEndpoint;
            break;
        default:
            Tungsten_GetAnimDeltaAIOrigin(*this,
                animDeltaCorrection.endPoint);
            break;
    }
}

// Retail symbol: ?CheckDeltaCorrectionAbortConditions@idAnimBaseFSM@@QBA_NXZ
// EA: 0x82A7B268, RVA: 0x00A7B268
bool idAnimBaseFSM::CheckDeltaCorrectionAbortConditions() const {
    const aiAnimDCIdealPoint_t point = animDeltaCorrection.idealPoint;
    if (point <= IDEALPOINT_NONE
        || (point > IDEALPOINT_CURRENT_ANIMNODE
            && point != IDEALPOINT_NEXTGROUNDPOINT)) {
        return false;
    }
    return Tungsten_HasAnimDeltaGoalChanged(
        *this, GetDeltaCorrectionGoalOrigin(), 20.0f);
}

// Retail symbol: ?HandleAnimDeltaCorrection@idAI2@@QAAXPBVidMD6Anim@@W4aiAnimDCIdealPoint_t@@W4aiAnimDCIdealDir_t@@W4animEventBool_t@@H@Z
// EA: 0x82A7B2F0, RVA: 0x00A7B2F0
void idAI2::HandleAnimDeltaCorrection(const idMD6Anim* const anim,
        const aiAnimDCIdealPoint_t idealPoint,
        const aiAnimDCIdealDir_t idealDir,
        const animEventBool_t correctGravity,
        const int thisEventNumber) {
    if (anim == nullptr || !Tungsten_IsAnimDeltaServer()) {
        return;
    }
    idAnimDeltaEventContext context;
    if (!Tungsten_GetAnimDeltaEventContext(
            *this, *anim, thisEventNumber, context)) {
        return;
    }
    idAnimBaseFSM& fsm = Tungsten_GetAnimDeltaFSM(*this);

    int translationEndFrame = -1;
    const idCachedJoint* translationEndJoint = nullptr;
    if (context.end.present && context.end.translationJoint != nullptr) {
        if (context.end.frame > context.currentFrame + 2) {
            translationEndFrame = context.end.frame;
            translationEndJoint = context.end.translationJoint;
        } else {
            Tungsten_AnimDeltaWarning(
                "delta correction end event within 2 frames of start event, DISCARDING END EVENT");
        }
    }
    if (idealPoint != IDEALPOINT_NONE) {
        fsm.BeginAnimDeltaCorrectionTranslation(anim, context.node,
            idealPoint, context.currentFrame, translationEndFrame,
            context.goal.present ? context.goal.frame : -1,
            translationEndJoint, context.goal.translationJoint,
            correctGravity == B_TRUE);
    }

    int rotationEndFrame = -1;
    const idCachedJoint* rotationEndJoint = nullptr;
    if (context.end.present && context.end.rotationJoint != nullptr) {
        if (context.end.frame > context.currentFrame + 2) {
            rotationEndFrame = context.end.frame;
            rotationEndJoint = context.end.rotationJoint;
        } else {
            Tungsten_AnimDeltaWarning(
                "delta correction end event within 2 frames of start event, DISCARDING END EVENT");
        }
    }
    if (idealDir != IDEALDIR_NONE) {
        fsm.BeginAnimDeltaCorrectionRotation(anim, context.node,
            idealDir, context.currentFrame, rotationEndFrame,
            context.goal.present ? context.goal.frame : -1,
            rotationEndJoint, context.goal.rotationJoint);
    }
}

// Retail symbol: ?AnimEvent_AnimDeltaCorrection@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4aiAnimDCIdealPoint_t@@W4aiAnimDCIdealDir_t@@W4animEventBool_t@@@Z
// EA: 0x82A7B998, RVA: 0x00A7B998
eventVoid idAI2::AnimEvent_AnimDeltaCorrection(
        const idMD6Anim* const anim,
        const aiAnimDCIdealPoint_t idealPoint,
        const aiAnimDCIdealDir_t idealDir,
        const animEventBool_t correctGravity) {
    if (Tungsten_IsAnimDeltaCorrectionEnabled()) {
        HandleAnimDeltaCorrection(anim, idealPoint, idealDir,
            correctGravity, Tungsten_GetAnimDeltaEventNumber(0));
    }
    return eventVoid();
}

// Retail symbol: ?AnimEvent_AnimDeltaCorrection_Turn@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A7BA00, RVA: 0x00A7BA00
eventVoid idAI2::AnimEvent_AnimDeltaCorrection_Turn(
        const idMD6Anim* const anim) {
    if (Tungsten_IsAnimDeltaCorrectionEnabled()) {
        HandleAnimDeltaCorrection(anim, IDEALPOINT_NONE,
            IDEALDIR_MOVEORIENTATION, B_FALSE,
            Tungsten_GetAnimDeltaEventNumber(1));
    }
    return eventVoid();
}

// Retail symbol: ?AnimEvent_AnimDeltaCorrection_Land@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA: 0x82A7BA70, RVA: 0x00A7BA70
eventVoid idAI2::AnimEvent_AnimDeltaCorrection_Land(
        const idMD6Anim* const anim) {
    if (Tungsten_IsAnimDeltaCorrectionEnabled() && anim != nullptr) {
        idAnimBaseFSM& fsm = Tungsten_GetAnimDeltaFSM(*this);
        Tungsten_GetAnimDeltaLandOrigin(
            *this, *anim, fsm.animDeltaCorrection.currentRefOrigin);
        HandleAnimDeltaCorrection(anim, IDEALPOINT_CURRENT_REF_PT,
            IDEALDIR_NONE, B_FALSE,
            Tungsten_GetAnimDeltaEventNumber(2));
    }
    return eventVoid();
}

// Retail symbol: ?MoveAIDeltaCorrection@idAnimBaseFSM@@IAAXXZ
// EA: 0x82A7BDB0, RVA: 0x00A7BDB0
void idAnimBaseFSM::MoveAIDeltaCorrection() {
    idAnimDeltaMoveRuntime runtime;
    if (!Tungsten_GetAnimDeltaMoveRuntime(*this, runtime)) {
        return;
    }
    if (!runtime.physicsIsAI) {
        Tungsten_SetAnimDeltaNullDestination(*this);
        return;
    }
    Tungsten_SetAnimDeltaRemoveOriginRotation(*this, true);

    idVec3 localDelta = animDeltaCorrection.animSpacePreTranslationCorrection
        * runtime.lastOriginDelta;
    const float previousTranslationFrames =
        animDeltaCorrection.previousRemainingTranslationFrames;
    animDeltaCorrection.previousRemainingTranslationFrames =
        GetRemainingFramesToTime(animDeltaCorrection.translationEndTime);
    const float previousRotationFrames =
        animDeltaCorrection.previousRemainingRotationFrames;
    animDeltaCorrection.previousRemainingRotationFrames =
        GetRemainingFramesToTime(animDeltaCorrection.rotationEndTime);

    bool allowCorrection = true;
    if ((animDeltaCorrection.correctTranslation
            || animDeltaCorrection.correctRotation)
        && runtime.blending
        && (previousTranslationFrames > 4.0f
            || previousRotationFrames > 4.0f)) {
        if (runtime.originBlendOperation != 1) {
            Tungsten_ForceAnimDeltaOriginBlendRight(*this);
            allowCorrection = false;
        }
        if (runtime.lastOriginTranslation.x > 20.0f) {
            allowCorrection = false;
        }
    } else if (runtime.blending
        && animDeltaCorrection.idealDir
            == IDEALDIR_DEPARTURE_PATH_DIRECTION
        && previousRotationFrames <= 4.0f
        && runtime.originBlendOperation != 0) {
        Tungsten_AnimDeltaWarning(
            "delta correction end time is within blend window, aborting delta correction.");
        allowCorrection = false;
    }

    const idVec3 remainingTranslation =
        animDeltaCorrection.animSpaceGoalTranslation
        - runtime.lastOriginTranslation;
    const bool hasTranslation = HasMagnitude(remainingTranslation);
    const idAngles remainingRotation = MatrixToAngles(
        InverseRotation(runtime.lastOriginRotation)
        * animDeltaCorrection.animSpaceGoalRotation);
    const bool hasRotation = std::fabs(remainingRotation.pitch) > 1.0f
        || std::fabs(remainingRotation.yaw) > 1.0f
        || std::fabs(remainingRotation.roll) > 1.0f;
    animDeltaCorrection.animHasRemainingDelta =
        hasTranslation || hasRotation;

    const idMat3 translationAxis = animDeltaCorrection.useUncorrectedAxis
        ? animDeltaCorrection.uncorrectedAxis : runtime.animatorAxis;
    idVec3 worldDelta = LocalToWorld(translationAxis,
        ScaleComponents(localDelta, runtime.animatorScale));
    if (allowCorrection && animDeltaCorrection.correctTranslation
        && previousTranslationFrames >= 0.0f) {
        const idVec3 remainingWorld = LocalToWorld(translationAxis,
            animDeltaCorrection.animSpaceEndTranslation
                - runtime.lastOriginTranslation);
        const idVec3 predictedEnd = runtime.origin + remainingWorld;
        idVec3 correction = GetDeltaCorrectionGoalOrigin() - predictedEnd;
        const float frames = RemainingScale(previousTranslationFrames,
            animDeltaCorrection.in.translationIgnoresRemainingFrames);
        correction = correction * (1.0f / frames);

        if (animDeltaCorrection.in.translationCorrectionMaxScale != 0.0f
            && HasMagnitude(worldDelta) && HasMagnitude(correction)) {
            const float maximum = worldDelta.Length()
                * std::fabs(animDeltaCorrection.in.translationCorrectionMaxScale);
            const float correctionLength = correction.Length();
            if (correctionLength > maximum) {
                correction = correction * (maximum / correctionLength);
            }
        }

        idVec3 modelCorrection = WorldToLocal(translationAxis, correction);
        const animDeltaCorrectionInput_t& input = animDeltaCorrection.in;
        if (input.lerpOnlyModelSpaceX || input.lerpOnlyModelSpaceY
            || input.lerpOnlyModelSpaceZ) {
            if (!input.lerpOnlyModelSpaceX) modelCorrection.x = 0.0f;
            if (!input.lerpOnlyModelSpaceY) modelCorrection.y = 0.0f;
            if (!input.lerpOnlyModelSpaceZ) modelCorrection.z = 0.0f;
        }
        modelCorrection = ClampComponents(modelCorrection,
            input.translationCorrectionPerFrameMax);
        correction = LocalToWorld(translationAxis, modelCorrection);
        worldDelta = worldDelta + correction;
    }
    worldDelta = LocalToWorld(translationAxis,
        ClampComponents(WorldToLocal(translationAxis, worldDelta),
            animDeltaCorrection.in.translationPerFrameMax));

    idAngles deltaAngles = MatrixToAngles(runtime.lastOriginRotation);
    idMat3 correctedAxis = runtime.lastOriginRotation * runtime.animatorAxis;
    if (allowCorrection && animDeltaCorrection.correctRotation
        && previousRotationFrames >= 0.0f) {
        deltaCorrectionGoalRotationParms_t parms;
        parms.sourcePosition = runtime.origin;
        parms.sourceAxis = runtime.animatorAxis;
        parms.worldSpaceAnimGoalOrigin = runtime.origin
            + LocalToWorld(runtime.animatorAxis,
                animDeltaCorrection.animSpaceGoalRotationTranslation
                    - runtime.lastOriginTranslation);
        parms.worldSpaceAnimGoalAxis = runtime.animatorAxis
            * InverseRotation(runtime.lastOriginRotation)
            * animDeltaCorrection.animSpaceGoalRotation;
        const idMat3 goalAxis = GetDeltaCorrectionGoalRotation(&parms);
        idAngles error = MatrixToAngles(
            InverseRotation(runtime.animatorAxis) * goalAxis);
        const float frames = RemainingScale(previousRotationFrames,
            animDeltaCorrection.in.rotationIgnoresRemainingFrames);
        float scale = 1.0f / frames;
        if (animDeltaCorrection.in.rotationMinScale != 0.0f
            || animDeltaCorrection.in.rotationMaxScale != 0.0f) {
            const float minimum = animDeltaCorrection.in.rotationMinScale;
            const float maximum = animDeltaCorrection.in.rotationMaxScale;
            if (maximum >= minimum) {
                scale = (std::max)(minimum, (std::min)(maximum, scale));
            }
        }
        idAngles correction = error * scale;
        const float degreesPerSecond =
            std::fabs(animDeltaCorrection.in.rotationRateMax) < kEpsilon
            ? 360.0f : std::fabs(animDeltaCorrection.in.rotationRateMax);
        const float maximumStep = degreesPerSecond
            * static_cast<float>(runtime.frameMilliseconds) * 0.001f;
        correction.pitch = ClampSymmetric(correction.pitch, maximumStep);
        correction.yaw = ClampSymmetric(correction.yaw, maximumStep);
        correction.roll = ClampSymmetric(correction.roll, maximumStep);

        const animDeltaCorrectionInput_t& input = animDeltaCorrection.in;
        if (!input.allowPitchCorrection) correction.pitch = 0.0f;
        if (!input.allowYawCorrection) correction.yaw = 0.0f;
        if (!input.allowRollCorrection) correction.roll = 0.0f;
        if (input.noReverseRotation) {
            if (input.restrictRotationDirectionPitch
                && !SameSignRelaxed(correction.pitch,
                    deltaAngles.pitch, 5.0f)) correction.pitch = 0.0f;
            if (input.restrictRotationDirectionYaw
                && !SameSignRelaxed(correction.yaw,
                    deltaAngles.yaw, 5.0f)) correction.yaw = 0.0f;
            if (input.restrictRotationDirectionRoll
                && !SameSignRelaxed(correction.roll,
                    deltaAngles.roll, 5.0f)) correction.roll = 0.0f;
        }
        deltaAngles = deltaAngles + correction;
        correctedAxis = deltaAngles.ToMat3() * runtime.animatorAxis;
    }

    if (!animDeltaCorrection.correctTranslation) {
        worldDelta = LocalToWorld(correctedAxis,
            ScaleComponents(localDelta, runtime.animatorScale));
    } else if (animDeltaCorrection.in.correctTranslatedRotation) {
        worldDelta = LocalToWorld(correctedAxis,
            WorldToLocal(translationAxis, worldDelta));
    }

    if ((currentStateFlags & 8u) != 0) {
        idVec3 probedEnd;
        if (Tungsten_ProbeAnimDeltaMovement(*this, runtime.origin,
                runtime.origin + worldDelta, probedEnd)) {
            worldDelta = probedEnd - runtime.origin;
        }
    }
    Tungsten_SetAnimDeltaPhysics(*this, worldDelta,
        runtime.frameMilliseconds, runtime.userChannelUsesGravity);

    if (!animDeltaCorrection.correctTranslation
        && animDeltaCorrection.idealPoint != IDEALPOINT_NOOP
        && animDeltaCorrection.correctRotation && allowCorrection
        && !runtime.animationPaused) {
        const float previousGoalFrames =
            animDeltaCorrection.previousRemainingRotationFramesToGoal;
        const float currentGoalFrames = GetRemainingFramesToTime(
            animDeltaCorrection.rotationGoalTime);
        animDeltaCorrection.previousRemainingRotationFramesToGoal =
            currentGoalFrames;
        if (previousGoalFrames > 0.0f && currentGoalFrames <= 0.0f) {
            if (!Tungsten_RespondsToAnimDeltaDepartureReturn(*this)) {
                Tungsten_AnimDeltaWarning(
                    "State didn't handle departure return-to-move event");
            } else {
                Tungsten_SendAnimDeltaDepartureReturn(*this);
            }
            ResetAnimDeltaCorrection();
        }
    }

    const float elapsedBlend = static_cast<float>(
        (std::max)(1, runtime.gameTime - runtime.lastBlendTime));
    const float turnRate = 1000.0f / elapsedBlend * deltaAngles.yaw;
    const int updateIdeal = deltaAngles.yaw > 1.0f
        ? 1 : (deltaAngles.yaw < -1.0f ? 2 : 0);
    if (!runtime.hasBindMaster) {
        Tungsten_UpdateAnimDeltaBodyOrientation(*this, correctedAxis,
            turnRate, updateIdeal, animDeltaMode == 3);
    }
    if (HasMagnitude(worldDelta)) {
        idVec3 direction = worldDelta;
        direction.NormalizeFast();
        Tungsten_SetAnimDeltaMoveIdealDirection(*this, direction);
        moveOrientationOnPath = true;
    }
    animDeltaCorrection.skipFirstFrame = false;
}
