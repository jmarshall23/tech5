#include "gamelib/physics/physics_player.h"

#include "gamelib/physics/clipmodel.h"
#include "idlib/geometry/tracemodel.h"
#include "idlib/math/rotation.h"

#include <algorithm>
#include <cmath>
#include <cstring>

bool GameLib_GetMasterPhysicsTransform(idPhysicsCallbacks* callbacks,
    idVec3& origin, idMat3& axis);
void GameLib_NotifyPhysicsActivated(idPhysicsCallbacks* callbacks,
    int physicsId);
void GameLib_NotifyPhysicsDeactivated(idPhysicsCallbacks* callbacks,
    int physicsId);
void GameLib_NotifyPhysicsCollision(idPhysicsCallbacks* callbacks,
    int physicsId, const trace_t& collision, const idVec3& velocity);
void GameLib_SerializePlayerState(idSerializer* serializer,
    playerPState_t& state, playerPState_t* catchupStart);
void GameLib_SerializePlayerNonPredictive(idSerializer* serializer,
    idPhysics_Player& physics);

namespace {

constexpr int ENTITYNUM_NONE = 0x1FFF;
constexpr int PMF_JUMPED = 0x0001;
constexpr int PMF_DUCKED = 0x0002;
constexpr int PMF_STEPPED_UP = 0x0004;
constexpr int PMF_SPRINT_SLIDE = 0x0100;
constexpr float MIN_FLOOR_COSINE = 0.70f;

const idVec3 kZeroVector(0.0f, 0.0f, 0.0f);
const idMat3 kIdentityAxis(1.0f);

float AxisYaw(const idMat3& axis) {
    return std::atan2(axis[0].y, axis[0].x) * 57.29577951308232f;
}

void ProjectOntoPlane(idVec3& vector, const idVec3& normal,
        const float overBounce = 1.0f) {
    const float backoff = vector.Dot(normal) * overBounce;
    vector = vector - normal * backoff;
}

idBounds ScaledHeightBounds(const idBounds& source, const float scale) {
    idBounds result = source;
    const float height = source[1].z - source[0].z;
    result[1].z = source[0].z + height * scale;
    return result;
}

idClipModel* MakePlayerClipModel(idClip* owner, const idBounds& bounds,
        const int contents, const idMaterial* material) {
    idTraceModel traceModel;
    traceModel.SetupCylinder(bounds, 8);
    idClipModel* const model = new idClipModel(owner, &traceModel, -1,
        material);
    model->SetContents(contents);
    return model;
}

} // namespace

idPhysics_Player::idPhysics_Player()
    : idPhysics_Actor()
    , explicitMove{}
    , explicitMove2{}
    , current{}
    , previous{}
    , saved{}
    , clipModel_standing(nullptr)
    , clipModel_crouched(nullptr)
    , clipModel_sprintSlide(nullptr)
    , clipModel_dead(nullptr)
    , overrideClipMaterial(nullptr)
    , pusher(nullptr)
    , slideMoveQuery{}
    , ladderQuery1{}
    , ladderQuery2{}
    , contentsQuery{}
    , lastContents(0)
    , walkSpeed(0.0f)
    , crouchSpeed(0.0f)
    , maxStepHeight(0.0f)
    , maxJumpHeight(0.0f)
    , debugLevel(0)
    , walkAccelerate(10.0f)
    , airAccelerate(1.0f)
    , flyAccelerate(8.0f)
    , waterAccelerate(4.0f)
    , walkFriction(6.0f)
    , airFriction(0.0f)
    , flyFriction(3.0f)
    , waterFriction(3.0f)
    , slideFriction(1.5f)
    , command{}
    , prevcmd{}
    , viewAngles{}
    , framemsec(0)
    , frametime(0.0f)
    , playerSpeed(0.0f)
    , viewForward(1.0f, 0.0f, 0.0f)
    , viewRight(0.0f, -1.0f, 0.0f)
    , walking(false)
    , startedOnGround(false)
    , groundPlane(false)
    , groundTrace{}
    , groundSurfaceFlags(0)
    , inhibitSprint(false)
    , inhibitJump(false)
    , toggleCrouch(false)
    , ladder(false)
    , ladderNormal(0.0f, 0.0f, 0.0f)
    , canLadder(true)
    , currentSwimDepthState(SWIMDEPTH_STATE_NONE)
    , swimStrokeVelocity(0.0f, 0.0f, 0.0f)
    , swimStrokeTimeLeft(-1000)
    , swimStrokeTime(-1000)
    , swimStrokeAltCurve(false)
    , swimStrokeIgnoreInput(false)
    , currentWaterEnt(-1)
    , currentWaterSurfaceHeight(0.0f)
    , blockedAccelerationPercent(0.0f)
    , blockedAccelerationVec(0.0f, 0.0f, 0.0f)
    , modifiedMovementMaxPercent(1.0f)
    , modifiedMovementAngle(90.0f)
    , modifiedAccelerationVec(0.0f, 0.0f, 0.0f)
    , canCrouchSprint(false)
    , lastJumpChance(0)
    , perfectOriginPosition(0.0f, 0.0f, 0.0f)
    , perfectOriginDuration(0)
    , perfectOriginTime(0)
    , externalVelocity(0.0f, 0.0f, 0.0f)
    , clientOriginSet(false)
    , nextClientOrigin(0.0f, 0.0f, 0.0f)
    , forcedClientCrouchState(false)
    , clientPusherLocked(false)
    , pushDeltaZ(0.0f)
    , ownerJumpHandler(nullptr)
    , ownerCrouchHandler(nullptr)
    , ownerCrouchJumpHandler(nullptr) {
    type = PHYSICS_PLAYER;
    current.movementType = PM_NORMAL;
    previous.movementType = PM_NORMAL;
    saved.movementType = PM_NORMAL;
    explicitMove.clipMove = true;
    explicitMove.velocityType = playerExplicitMove_t::VEL_EXPLICIT;
    explicitMove.ignoreEntityNum = ENTITYNUM_NONE;
    explicitMove2.clipMove = true;
    explicitMove2.velocityType = playerExplicitMove_t::VEL_EXPLICIT;
    explicitMove2.ignoreEntityNum = ENTITYNUM_NONE;
    groundTrace.fraction = 1.0f;
    groundTrace.endAxis = kIdentityAxis;
}

idPhysics_Player::~idPhysics_Player() {
    UnlinkClip();
    idClipModel* models[] = {clipModel_standing, clipModel_crouched,
        clipModel_sprintSlide, clipModel_dead};
    for (int i = 0; i < 4; ++i) {
        if (models[i] == nullptr) continue;
        bool duplicate = false;
        for (int j = 0; j < i; ++j) duplicate |= models[j] == models[i];
        if (!duplicate) models[i]->Delete();
    }
    clipModels[0] = nullptr;
    clipModels[1] = nullptr;
}

void idPhysics_Player::SelectClipModel(idClipModel* const model) {
    if (model == nullptr || model == clipModels[0]) return;
    if (clipModels[0] != nullptr) clipModels[0]->Unlink();
    clipModels[0] = model;
    idPhysics_Actor::LinkClip(current.worldOrigin, clipModelAxis);
}

void idPhysics_Player::SetClipModel(idClipModel* const model,
        const float density, const int id, const bool freeOld) {
    if (id != 0 || model == nullptr) {
        idPhysics_Actor::SetClipModel(model, density, id, freeOld);
        return;
    }
    const idBounds sourceBounds = model->GetBounds();
    const int contents = model->GetContents();
    const idVec3 oldOrigin = model->GetOrigin();
    if (freeOld) model->Delete();

    idClipModel* oldModels[] = {clipModel_standing, clipModel_crouched,
        clipModel_sprintSlide, clipModel_dead};
    for (int i = 0; i < 4; ++i) {
        if (oldModels[i] == nullptr || oldModels[i] == model) continue;
        bool duplicate = false;
        for (int j = 0; j < i; ++j) duplicate |= oldModels[j] == oldModels[i];
        if (!duplicate) oldModels[i]->Delete();
    }

    clipModel_standing = MakePlayerClipModel(clip, sourceBounds, contents,
        overrideClipMaterial);
    clipModel_crouched = MakePlayerClipModel(clip,
        ScaledHeightBounds(sourceBounds, 0.65f), contents,
        overrideClipMaterial);
    clipModel_sprintSlide = MakePlayerClipModel(clip,
        ScaledHeightBounds(sourceBounds, 0.45f), contents,
        overrideClipMaterial);
    clipModel_dead = MakePlayerClipModel(clip,
        ScaledHeightBounds(sourceBounds, 0.35f), contents,
        overrideClipMaterial);
    clipModels[0] = nullptr;
    SelectClipModel(clipModel_standing);
    current.worldOrigin = oldOrigin;
    current.localOrigin = oldOrigin;
    LinkClip(current.worldOrigin, clipModelAxis);
    if (density > 0.0f) SetMass(density, 0);
}

void idPhysics_Player::SetClipModelStanding(idClipModel* const model) {
    if (model == nullptr) return;
    if (clipModel_standing != nullptr && clipModel_standing != model)
        clipModel_standing->Delete();
    clipModel_standing = model;
    if (!IsCrouching()) SelectClipModel(model);
}

void idPhysics_Player::SetOrigin(const idVec3* const origin, int) {
    if (origin == nullptr) return;
    slideMoveQuery.index = 0;
    current.localOrigin = *origin;
    current.worldOrigin = *origin;
    if (hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis))
            current.worldOrigin = masterOrigin + masterAxis * *origin;
    }
    LinkClip(current.worldOrigin, clipModelAxis);
    Activate();
}

void idPhysics_Player::SetAxis(const idMat3* const axis, int) {
    if (axis == nullptr) return;
    clipModelAxis = *axis;
    LinkClip(current.worldOrigin, clipModelAxis);
}

void idPhysics_Player::Translate(const idVec3* const translation, int) {
    if (translation == nullptr) return;
    current.localOrigin = current.localOrigin + *translation;
    current.worldOrigin = current.worldOrigin + *translation;
    LinkClip(current.worldOrigin, clipModelAxis);
    Activate();
}

void idPhysics_Player::Rotate(const idRotation* const rotation, int) {
    if (rotation == nullptr) return;
    current.worldOrigin = *rotation * current.worldOrigin;
    current.localOrigin = *rotation * current.localOrigin;
    clipModelAxis *= rotation->ToMat3();
    LinkClip(current.worldOrigin, clipModelAxis);
    Activate();
}

const idVec3* idPhysics_Player::GetLocalOrigin(int) {
    return &current.localOrigin;
}

const idMat3* idPhysics_Player::GetLocalAxis(int) {
    return &clipModelAxis;
}

void idPhysics_Player::SetLinearVelocity(const idVec3* const velocity, int) {
    if (velocity == nullptr) return;
    current.velocity = *velocity;
    Activate();
}

void idPhysics_Player::SetAngularVelocity(const idVec3*, int) {}

idVec3* idPhysics_Player::GetLinearVelocity(idVec3* const result, int) {
    if (result != nullptr) *result = current.velocity;
    return result;
}

idVec3* idPhysics_Player::GetAngularVelocity(idVec3* const result, int) {
    if (result != nullptr) result->Zero();
    return result;
}

void idPhysics_Player::SetWaterLevel(const float level, const int id) {
    idPhysics_DynamicBase::SetWaterLevel(level, id);
    if (waterLevel <= 0.0f) currentSwimDepthState = SWIMDEPTH_STATE_NONE;
    else if (waterLevel < 1.0f)
        currentSwimDepthState = SWIMDEPTH_STATE_ON_SURFACE;
    else currentSwimDepthState = SWIMDEPTH_STATE_UNDER_SURFACE;
}

void idPhysics_Player::SetWaterEntNum(const int entityNumber_) {
    currentWaterEnt = entityNumber_;
}
int idPhysics_Player::GetWaterEntNum() { return currentWaterEnt; }
void idPhysics_Player::SetWaterSurfaceWrldHeight(const float height) {
    currentWaterSurfaceHeight = height;
}
float idPhysics_Player::GetWaterSurfaceWrldHeight() {
    return currentWaterSurfaceHeight;
}

void idPhysics_Player::GetImpactInfo(int, const idVec3*,
        impactInfo_t* const info) {
    if (info == nullptr) return;
    info->Zero();
    info->invMass = invMass;
    info->velocity = current.velocity + current.pushVelocity;
    info->position = current.worldOrigin;
}

void idPhysics_Player::ApplyImpulse(int, const idVec3*,
        const idVec3* const impulse) {
    if (impulse == nullptr) return;
    current.velocity = current.velocity + *impulse * invMass;
    Activate();
}

void idPhysics_Player::ApplyForce(int, const idVec3*,
        const idVec3* const force) {
    if (force == nullptr) return;
    const float time = frametime > 0.0f ? frametime : 0.016f;
    current.velocity = current.velocity + *force * (invMass * time);
    Activate();
}

void idPhysics_Player::Activate() {
    if (callbacks != nullptr)
        GameLib_NotifyPhysicsActivated(callbacks, GetPhysicsId());
}
void idPhysics_Player::PutToRest() { current.velocity.Zero(); }
bool idPhysics_Player::IsAtRest() { return false; }
bool idPhysics_Player::IsPushable(int) { return true; }

void idPhysics_Player::SaveState() { saved = current; }
void idPhysics_Player::RestoreState() { RestoreStateFromState(&saved); }
void idPhysics_Player::RestoreStateFromState(playerPState_t* const state) {
    if (state == nullptr) return;
    current = *state;
    LinkClip(current.worldOrigin, clipModelAxis);
}

void idPhysics_Player::Serialize(idSerializer* const serializer,
        playerPState_t* const catchupStart) {
    if (serializer != nullptr)
        GameLib_SerializePlayerState(serializer, current, catchupStart);
}

void idPhysics_Player::SerializeNonPredictiveState(
        idSerializer* const serializer) {
    if (serializer != nullptr)
        GameLib_SerializePlayerNonPredictive(serializer, *this);
}

void idPhysics_Player::UpdateTime(int) {}

void idPhysics_Player::SetPushed(const int deltaTime) {
    if (deltaTime <= 0) {
        current.pushVelocity.Zero();
        return;
    }
    current.pushVelocity = (current.worldOrigin - saved.worldOrigin)
        * (1000.0f / static_cast<float>(deltaTime));
    pushDeltaZ = current.worldOrigin.z - saved.worldOrigin.z;
}

void idPhysics_Player::ClearPushedVelocity() {
    current.pushVelocity.Zero();
    pushDeltaZ = 0.0f;
}

idVec3* idPhysics_Player::GetPushedLinearVelocity(idVec3* const result,
        int) {
    if (result != nullptr) *result = current.pushVelocity;
    return result;
}

idVec3* idPhysics_Player::GetPushedAngularVelocity(idVec3* const result,
        int) {
    if (result != nullptr) result->Zero();
    return result;
}

void idPhysics_Player::SetMaster(const bool enable,
        const idVec3* const masterOrigin, const idMat3* const masterAxis,
        bindFlags_t) {
    slideMoveQuery.index = 0;
    if (enable && masterOrigin != nullptr && masterAxis != nullptr) {
        if (!hasMaster) {
            current.localOrigin = masterAxis->Transpose()
                * (current.worldOrigin - *masterOrigin);
            masterYaw = AxisYaw(*masterAxis);
        }
        hasMaster = true;
        ClearContacts();
    } else if (hasMaster) {
        hasMaster = false;
        Activate();
    }
}

void idPhysics_Player::SetLocalOrigin(const idVec3* const origin, int) {
    if (origin == nullptr) return;
    current.localOrigin = *origin;
    if (hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis))
            current.worldOrigin = masterOrigin + masterAxis * *origin;
    } else current.worldOrigin = *origin;
    LinkClip(current.worldOrigin, clipModelAxis);
}

void idPhysics_Player::SetLocalAxis(const idMat3* const axis, int) {
    if (axis == nullptr) return;
    clipModelAxis = *axis;
    LinkClip(current.worldOrigin, clipModelAxis);
}

int idPhysics_Player::GetBlockingEntityNum() {
    return groundTrace.fraction < 1.0f ? groundTrace.c.entityNum
        : ENTITYNUM_NONE;
}
int idPhysics_Player::GetLinearEndTime() { return 0; }
int idPhysics_Player::GetAngularEndTime() { return 0; }

void idPhysics_Player::SetSlideFriction(const float value) {
    slideFriction = (std::max)(0.0f, value);
}
bool idPhysics_Player::HasJumped() const {
    return (current.movementFlags & PMF_JUMPED) != 0;
}
bool idPhysics_Player::HasCrouched() const {
    return (previous.movementFlags & PMF_DUCKED) == 0 && IsCrouching();
}
bool idPhysics_Player::HasStoodUp() const {
    return (previous.movementFlags & PMF_DUCKED) != 0 && !IsCrouching();
}
bool idPhysics_Player::HasSteppedUp() const {
    return (current.movementFlags & PMF_STEPPED_UP) != 0;
}
float idPhysics_Player::GetStepUp() const { return current.stepUp; }
bool idPhysics_Player::IsCrouching() const {
    return (current.movementFlags & PMF_DUCKED) != 0;
}
void idPhysics_Player::SetClientCrouch(const bool crouch) {
    forcedClientCrouchState = crouch;
    SetCrouch(crouch);
}
void idPhysics_Player::SetSprintSliding(const bool sliding) {
    if (sliding) current.movementFlags |= PMF_SPRINT_SLIDE;
    else current.movementFlags &= ~PMF_SPRINT_SLIDE;
    CheckDuck();
}
void idPhysics_Player::SetWalkFriction(const float friction) {
    walkFriction = (std::max)(0.0f, friction);
}
void idPhysics_Player::SetSpeed(const float walkingSpeed,
        const float crouchingSpeed) {
    walkSpeed = (std::max)(0.0f, walkingSpeed);
    crouchSpeed = (std::max)(0.0f, crouchingSpeed);
}
void idPhysics_Player::SetMaxStepHeight(const float value) {
    maxStepHeight = (std::max)(0.0f, value);
}
void idPhysics_Player::SetMaxJumpHeight(const float value) {
    maxJumpHeight = (std::max)(0.0f, value);
}
void idPhysics_Player::SetMovementType(const pmtype_t movementType) {
    current.movementType = movementType >= PM_NORMAL && movementType < PM_MAX
        ? movementType : PM_NORMAL;
}
void idPhysics_Player::SetKnockBack(const int knockBackTime,
        const bool absoluteKnockBack) {
    current.movementTime = absoluteKnockBack
        ? knockBackTime : (std::max)(current.movementTime, knockBackTime);
}
void idPhysics_Player::SetDebugLevel(const bool set) { debugLevel = set; }

void idPhysics_Player::SetSwimStroke(const idVec3& velocity,
        const int duration, const bool alternateCurve,
        const bool ignoreInput) {
    swimStrokeVelocity = velocity;
    swimStrokeTimeLeft = duration;
    swimStrokeTime = duration;
    swimStrokeAltCurve = alternateCurve;
    swimStrokeIgnoreInput = ignoreInput;
}

bool idPhysics_Player::GetIsUnderWater() const {
    return currentSwimDepthState == SWIMDEPTH_STATE_UNDER_SURFACE;
}

void idPhysics_Player::StartPerfectOrigin(const idVec3& idealPosition,
        const int lerpTimeMS) {
    perfectOriginPosition = idealPosition;
    perfectOriginDuration = (std::max)(0, lerpTimeMS);
    perfectOriginTime = 0;
    current.movementType = PM_PERFECTORIGIN;
}

void idPhysics_Player::SetClientDeferredOrigin(const idVec3& origin) {
    nextClientOrigin = origin;
    clientOriginSet = true;
}

void idPhysics_Player::SetPlayerInput(const usercmd_t& cmd,
        const idAngles& newViewAngles) {
    prevcmd = command;
    command = cmd;
    viewAngles = newViewAngles;
}

bool idPhysics_Player::ClientPusherLocked(bool* const justUnlocked) {
    const bool wasLocked = clientPusherLocked;
    if (justUnlocked != nullptr) *justUnlocked = false;
    if (clientOriginSet) {
        clientPusherLocked = false;
        if (justUnlocked != nullptr) *justUnlocked = wasLocked;
    }
    return clientPusherLocked;
}

void idPhysics_Player::UpdateNonPredictiveClip() {
    if (!clientOriginSet) return;
    current.worldOrigin = nextClientOrigin;
    current.localOrigin = nextClientOrigin;
    LinkClip(current.worldOrigin, clipModelAxis);
    clientOriginSet = false;
}

float idPhysics_Player::CmdScale(const usercmd_t& cmd) const {
    const int forward = std::abs(static_cast<int>(cmd.forwardmove));
    const int right = std::abs(static_cast<int>(cmd.rightmove));
    const int up = std::abs(static_cast<int>(cmd.upmove));
    const int maximum = (std::max)(forward, (std::max)(right, up));
    if (maximum == 0) return 0.0f;
    const float total = std::sqrt(static_cast<float>(forward * forward
        + right * right + up * up));
    return total > 0.0f ? playerSpeed * maximum / (127.0f * total) : 0.0f;
}

void idPhysics_Player::Accelerate(const idVec3& wishDirection,
        const float wishSpeed, const float acceleration) {
    const float currentSpeed = current.velocity.Dot(wishDirection);
    const float addSpeed = wishSpeed - currentSpeed;
    if (addSpeed <= 0.0f) return;
    const float accelerationSpeed = (std::min)(addSpeed,
        acceleration * frametime * wishSpeed);
    current.velocity = current.velocity + wishDirection * accelerationSpeed;
}

void idPhysics_Player::UpdateExternalVelocity() {
    current.velocity = current.velocity + externalVelocity;
    externalVelocity.Zero();
}

void idPhysics_Player::Friction() {
    idVec3 velocity = current.velocity;
    if (walking) ProjectOntoPlane(velocity, gravityNormal);
    const float speed = velocity.Length();
    if (speed < 1.0f) {
        if (walking) ProjectOntoPlane(current.velocity, -gravityNormal);
        return;
    }
    float coefficient = walking ? walkFriction : airFriction;
    if (current.movementType == PM_SPECTATOR
            || current.movementType == PM_NOCLIP)
        coefficient = flyFriction;
    if (waterLevel > 0.0f) coefficient = waterFriction * waterLevel;
    if (current.movementType == PM_SLIDE) coefficient = slideFriction;
    const float newSpeed = (std::max)(0.0f,
        speed - speed * coefficient * frametime);
    if (newSpeed != speed) current.velocity = current.velocity
        * (newSpeed / speed);
}

bool idPhysics_Player::CheckJump() {
    if (inhibitJump || !walking || command.upmove < 10) return false;
    if (prevcmd.upmove >= 10 && current.movementTime <= 0) return false;
    const float gravity = gravityVector.Length();
    const float jumpSpeed = std::sqrt((std::max)(0.0f,
        2.0f * gravity * maxJumpHeight));
    ProjectOntoPlane(current.velocity, gravityNormal);
    current.velocity = current.velocity - gravityNormal * jumpSpeed;
    current.movementFlags |= PMF_JUMPED;
    walking = false;
    groundPlane = false;
    if (ownerJumpHandler != nullptr)
        ownerJumpHandler(GetEntityNumber(), &current.worldOrigin,
            &current.velocity, &viewForward, &viewRight, &command);
    return true;
}

void idPhysics_Player::CorrectAllSolid(trace_t& trace, int) {
    trace.fraction = 0.0f;
    trace.endpos = current.worldOrigin;
    current.velocity.Zero();
}

void idPhysics_Player::SlideMoveDeferred(const bool gravity,
        const bool stepUp, const bool stepDown, const bool push) {
    SlideMoveNonDeferred(gravity, stepUp, stepDown, push);
}

void idPhysics_Player::SlideMoveNonDeferred(const bool applyGravity,
        const bool allowStepUp, const bool allowStepDown, bool) {
    idClipModel* const model = clipModels[0];
    if (clip == nullptr || model == nullptr) {
        if (applyGravity)
            current.velocity = current.velocity + gravityVector * frametime;
        current.worldOrigin = current.worldOrigin
            + current.velocity * frametime;
        current.localOrigin = current.worldOrigin;
        return;
    }
    if (applyGravity)
        current.velocity = current.velocity + gravityVector * frametime;
    const idVec3 start = current.worldOrigin;
    const idVec3 end = start + current.velocity * frametime;
    trace_t collision{};
    collision.fraction = 1.0f;
    collision.endpos = end;
    collision.endAxis = clipModelAxis;
    contactsResult_t result{};
    const float up = allowStepUp ? maxStepHeight : 0.0f;
    const float down = allowStepDown ? maxStepHeight * 2.0f : 0.0f;
    slideMoveQuery = allowStepUp
        ? clip->StepMoveContacts(&collision, &result, start, end,
            gravityNormal, up, down, model, clipModelAxis, clipMasks[0],
            GetEntityNumber(), false,
            "idPhysics_Player::SlideMoveNonDeferred")
        : clip->SlideMoveContacts(&collision, &result, start, end,
            gravityNormal, up, model, clipModelAxis, clipMasks[0],
            GetEntityNumber(), false,
            "idPhysics_Player::SlideMoveNonDeferred");
    current.worldOrigin = collision.endpos;
    current.localOrigin = current.worldOrigin;
    ClearContacts();
    const int count = (std::min)(12, result.numContacts);
    for (int i = 0; i < count; ++i) {
        contacts.Append(result.contacts[i]);
        UpdateCollisionResidency(result.contacts[i]);
    }
    AddContactPhysicsForContacts();
    if (collision.fraction < 1.0f) {
        ProjectOntoPlane(current.velocity, collision.c.normal, 1.001f);
        if (callbacks != nullptr)
            GameLib_NotifyPhysicsCollision(callbacks, GetPhysicsId(),
                collision, current.velocity);
    }
    const float stepped = (collision.endpos - start).Dot(-gravityNormal);
    current.stepUp = stepped > 0.0f ? stepped : 0.0f;
    if (current.stepUp > 0.0f) current.movementFlags |= PMF_STEPPED_UP;
    LinkClip(current.worldOrigin, clipModelAxis);
}

void idPhysics_Player::SlideMove(const bool gravity, const bool stepUp,
        const bool stepDown, const bool push) {
    SlideMoveDeferred(gravity, stepUp, stepDown, push);
}

void idPhysics_Player::CheckGround() {
    walking = false;
    groundPlane = false;
    groundTrace = {};
    groundTrace.fraction = 1.0f;
    groundTrace.endpos = current.worldOrigin;
    groundTrace.endAxis = clipModelAxis;
    idClipModel* const model = clipModels[0];
    if (clip == nullptr || model == nullptr) return;
    const idVec3 end = current.worldOrigin + gravityNormal
        * (maxStepHeight > 0.0f ? maxStepHeight : 2.0f);
    clip->Translation(&groundTrace, current.worldOrigin, end, model,
        clipModelAxis, clipMasks[0], GetEntityNumber(), false,
        "idPhysics_Player::CheckGround");
    if (groundTrace.fraction < 1.0f) {
        groundPlane = true;
        walking = groundTrace.c.normal.Dot(-gravityNormal)
            >= MIN_FLOOR_COSINE;
        groundSurfaceFlags = groundTrace.c.surfaceFlags;
        UpdateCollisionResidency(groundTrace.c);
        if (walking) {
            bool present = false;
            for (int i = 0; i < contacts.Num(); ++i)
                present |= contacts[i].entityNum == groundTrace.c.entityNum;
            if (!present) contacts.Append(groundTrace.c);
        }
    }
}

bool idPhysics_Player::CanStand() {
    return CanStand(current.worldOrigin);
}

bool idPhysics_Player::CanStand(const idVec3& position) {
    if (clip == nullptr || clipModel_standing == nullptr) return true;
    trace_t result{};
    contentsQuery = clip->Contents(&result, position, clipModel_standing,
        clipModelAxis, clipMasks[0], GetEntityNumber(),
        "idPhysics_Player::CanStand");
    return result.c.contentFlags == 0 && result.fraction != 0.0f;
}

void idPhysics_Player::CheckLadder(const bool oldLadder) {
    if (!canLadder || clip == nullptr || clipModels[0] == nullptr) {
        ladder = false;
        return;
    }
    trace_t result{};
    const idVec3 end = current.worldOrigin + viewForward * 2.0f;
    ladderQuery1 = clip->Translation(&result, current.worldOrigin, end,
        clipModels[0], clipModelAxis, clipMasks[0], GetEntityNumber(),
        false, "idPhysics_Player::CheckLadder");
    ladder = result.fraction < 1.0f
        && std::fabs(result.c.normal.Dot(gravityNormal)) < 0.5f;
    if (ladder) ladderNormal = result.c.normal;
    else if (oldLadder) ladderNormal.Zero();
}

void idPhysics_Player::NoclipMove() {
    Friction();
    const float scale = CmdScale(command);
    idVec3 up = -gravityNormal;
    idVec3 wish = viewForward * static_cast<float>(command.forwardmove)
        + viewRight * static_cast<float>(command.rightmove)
        + up * static_cast<float>(command.upmove);
    const float length = wish.NormalizeFast();
    if (length > 0.0f) Accelerate(wish, scale * length, flyAccelerate);
    current.worldOrigin = current.worldOrigin + current.velocity * frametime;
    current.localOrigin = current.worldOrigin;
    LinkClip(current.worldOrigin, clipModelAxis);
}

void idPhysics_Player::WaterJumpMove() {
    SlideMove(true, true, true, false);
}

void idPhysics_Player::SwimMove() {
    Friction();
    idVec3 up = -gravityNormal;
    idVec3 wish = viewForward * static_cast<float>(command.forwardmove)
        + viewRight * static_cast<float>(command.rightmove)
        + up * static_cast<float>(command.upmove);
    float wishSpeed = CmdScale(command) * wish.NormalizeFast();
    if (!swimStrokeIgnoreInput) Accelerate(wish, wishSpeed, waterAccelerate);
    if (swimStrokeTimeLeft > 0) {
        current.velocity = current.velocity + swimStrokeVelocity
            * frametime;
        swimStrokeTimeLeft -= framemsec;
    }
    current.velocity = current.velocity
        + gravityVector * (frametime * (1.0f - waterLevel));
    SlideMove(false, false, false, false);
}

void idPhysics_Player::AirMove() {
    Friction();
    idVec3 forward = viewForward;
    idVec3 right = viewRight;
    ProjectOntoPlane(forward, gravityNormal);
    ProjectOntoPlane(right, gravityNormal);
    forward.NormalizeFast();
    right.NormalizeFast();
    idVec3 wish = forward * static_cast<float>(command.forwardmove)
        + right * static_cast<float>(command.rightmove);
    const float length = wish.NormalizeFast();
    Accelerate(wish, CmdScale(command) * length, airAccelerate);
    SlideMove(true, false, false, false);
}

void idPhysics_Player::WalkMove() {
    if (CheckJump()) {
        AirMove();
        return;
    }
    Friction();
    idVec3 forward = viewForward;
    idVec3 right = viewRight;
    ProjectOntoPlane(forward, groundTrace.c.normal);
    ProjectOntoPlane(right, groundTrace.c.normal);
    forward.NormalizeFast();
    right.NormalizeFast();
    idVec3 wish = forward * static_cast<float>(command.forwardmove)
        + right * static_cast<float>(command.rightmove);
    const float length = wish.NormalizeFast();
    playerSpeed = IsCrouching() ? crouchSpeed : walkSpeed;
    Accelerate(wish, CmdScale(command) * length, walkAccelerate);
    ProjectOntoPlane(current.velocity, groundTrace.c.normal);
    SlideMove(false, true, true, true);
}

void idPhysics_Player::PerfectOriginMove(const int deltaMS) {
    perfectOriginTime += deltaMS;
    const float fraction = perfectOriginDuration > 0
        ? (std::min)(1.0f, static_cast<float>(perfectOriginTime)
            / static_cast<float>(perfectOriginDuration)) : 1.0f;
    const idVec3 start = current.worldOrigin;
    current.worldOrigin = start
        + (perfectOriginPosition - start) * fraction;
    current.localOrigin = current.worldOrigin;
    current.velocity = deltaMS > 0
        ? (current.worldOrigin - start) * (1000.0f / deltaMS)
        : kZeroVector;
    LinkClip(current.worldOrigin, clipModelAxis);
    if (fraction >= 1.0f) current.movementType = PM_NORMAL;
}

void idPhysics_Player::DeadMove() {
    Friction();
    SlideMove(true, false, true, false);
}

void idPhysics_Player::SpectatorMove() { NoclipMove(); }

void idPhysics_Player::LadderMove() {
    Friction();
    idVec3 up = -gravityNormal;
    idVec3 side = up.Cross(ladderNormal);
    side.NormalizeFast();
    idVec3 wish = up * static_cast<float>(command.forwardmove
        + command.upmove) + side * static_cast<float>(command.rightmove);
    const float length = wish.NormalizeFast();
    Accelerate(wish, CmdScale(command) * length, flyAccelerate);
    ProjectOntoPlane(current.velocity, ladderNormal, 1.001f);
    SlideMove(false, false, false, false);
}

void idPhysics_Player::ExplicitMove(playerExplicitMove_t& move) {
    if (move.velocityType == playerExplicitMove_t::VEL_OVERRIDE)
        current.velocity = move.overrideVelocity;
    else if (move.velocityType == playerExplicitMove_t::VEL_EXPLICIT
            && frametime > 0.0f)
        current.velocity = move.delta * (1.0f / frametime);
    if (move.clipMove) {
        const idVec3 originalVelocity = current.velocity;
        current.velocity = move.delta * (frametime > 0.0f
            ? 1.0f / frametime : 0.0f);
        SlideMove(false, false, false, false);
        if (move.velocityType == playerExplicitMove_t::VEL_CURRENT)
            current.velocity = originalVelocity;
    } else {
        current.worldOrigin = current.worldOrigin + move.delta;
        current.localOrigin = current.worldOrigin;
        LinkClip(current.worldOrigin, clipModelAxis);
    }
    move.delta.Zero();
}

void idPhysics_Player::CheckDuck() {
    const bool sprint = (current.movementFlags & PMF_SPRINT_SLIDE) != 0;
    bool wantCrouch = forcedClientCrouchState || toggleCrouch
        || command.upmove < 0 || sprint;
    if (!wantCrouch && !CanStand()) wantCrouch = true;
    if (wantCrouch) current.movementFlags |= PMF_DUCKED;
    else current.movementFlags &= ~PMF_DUCKED;
    idClipModel* desired = clipModel_standing;
    if (current.movementType == PM_DEAD) desired = clipModel_dead;
    else if (sprint && clipModel_sprintSlide != nullptr)
        desired = clipModel_sprintSlide;
    else if (wantCrouch) desired = clipModel_crouched;
    SelectClipModel(desired);
}

void idPhysics_Player::ForcePhysicsQuery() {
    slideMoveQuery.index = 0;
    ladderQuery1.index = 0;
    ladderQuery2.index = 0;
    contentsQuery.index = 0;
    CheckGround();
}

void idPhysics_Player::ClearCrouch() {
    forcedClientCrouchState = false;
    toggleCrouch = false;
    if (CanStand()) {
        current.movementFlags &= ~PMF_DUCKED;
        SelectClipModel(clipModel_standing);
    }
}

void idPhysics_Player::SetCrouch(const bool crouch) {
    toggleCrouch = crouch;
    CheckDuck();
    if (ownerCrouchHandler != nullptr)
        ownerCrouchHandler(GetEntityNumber(), &current.worldOrigin,
            &current.velocity, &viewForward, &viewRight, &command);
}

void idPhysics_Player::ResolveSlideMove() {
    if (clientOriginSet) UpdateNonPredictiveClip();
}

void idPhysics_Player::MovePlayer(const int milliseconds) {
    framemsec = (std::max)(0, milliseconds);
    frametime = framemsec * 0.001f;
    previous = current;
    current.stepUp = 0.0f;
    current.movementFlags &= ~(PMF_JUMPED | PMF_STEPPED_UP);
    if (current.movementTime > 0)
        current.movementTime = (std::max)(0,
            current.movementTime - framemsec);
    viewAngles.ToVectors(&viewForward, &viewRight, nullptr);
    UpdateExternalVelocity();
    CheckDuck();
    startedOnGround = walking;
    CheckGround();
    const bool oldLadder = ladder;
    CheckLadder(oldLadder);

    switch (current.movementType) {
    case PM_FREEZE:
        current.velocity.Zero();
        break;
    case PM_NOCLIP:
    case PM_VEHICLE_NOCLIP:
        NoclipMove();
        break;
    case PM_SPECTATOR:
        SpectatorMove();
        break;
    case PM_DEAD:
        DeadMove();
        break;
    case PM_PERFECTORIGIN:
        PerfectOriginMove(milliseconds);
        break;
    case PM_EXPLICIT:
        ExplicitMove(explicitMove);
        ExplicitMove(explicitMove2);
        break;
    case PM_SLIDE:
        Friction();
        SlideMove(true, false, true, false);
        break;
    case PM_NORMAL:
    default:
        if (ladder) LadderMove();
        else if (waterLevel > 0.5f) SwimMove();
        else if (walking) WalkMove();
        else AirMove();
        break;
    }
    ResolveSlideMove();
    CheckGround();
}

bool idPhysics_Player::Evaluate(const int timeStepMSec, int) {
    RememberHistorySample();
    if (hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis)) {
            const idVec3 oldOrigin = current.worldOrigin;
            current.worldOrigin = masterOrigin
                + masterAxis * current.localOrigin;
            LinkClip(current.worldOrigin, clipModelAxis);
            const float seconds = timeStepMSec * 0.001f;
            if (seconds > 0.0f)
                current.velocity = (current.worldOrigin - oldOrigin)
                    * (1.0f / seconds);
            masterDeltaYaw = AxisYaw(masterAxis) - masterYaw;
            masterYaw += masterDeltaYaw;
        }
    } else MovePlayer(timeStepMSec);
    if (IsOutsideWorld() && callbacks != nullptr)
        GameLib_NotifyPhysicsDeactivated(callbacks, GetPhysicsId());
    return true;
}

