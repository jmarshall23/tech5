#include "gamelib/animstack/animator_af.h"

#include <cstring>

idMD6Branch* GameLib_AllocMD6Branch(idAnimStack* stack);
void GameLib_FreeMD6Branch(idAnimStack* stack, idMD6Branch* branch);
idTreeAnimator* GameLib_GetTreeAnimator(idAnimStack* stack);
bool GameLib_InitAFAnimator(idAnimator_AF& animator, idAnimStack* stack);
void GameLib_ShutdownAFAnimator(idAnimator_AF& animator);
void GameLib_UpdateAFAnimator(idAnimator_AF& animator,
    const idAnimStack* stack, int currentTime, int ticksPerSecond);
void GameLib_SerializeAFAnimator(idSerializer* serializer,
    idAnimator_AF& animator);
void GameLib_PreBlendAFSnapshot(idAnimator_AF& animator,
    idAnimStack* stack, int currentTime, int ticksPerSecond,
    float fraction);
idBounds GameLib_GetAFAnimatorBounds(const idAnimator_AF& animator);
int GameLib_AFBodyForJoint(const idAnimator_AF& animator,
    idJointIndex joint);
void GameLib_GetAFModelTransform(const idAnimator_AF& animator,
    idVec3& origin, idMat3& axis);
void GameLib_SetAFRunning(idAnimator_AF& animator, bool running);
void GameLib_AddAFBindConstraints(idAnimator_AF& animator);
void GameLib_RemoveAFBindConstraints(idAnimator_AF& animator);
void GameLib_ZeroAFImpulses(idAnimator_AF& animator);
void GameLib_EndAFSync(idAnimator_AF& animator);
int GameLib_CollideAFAnimator(idAnimator_AF& animator, int bodyId,
    trace_t& collision, const idVec3& velocity);
void GameLib_AddDynamicAFBindConstraint(idAnimator_AF& animator,
    int type, const idStr& name);
bool GameLib_UpdateAFAnimation(idAnimator_AF& animator);
void GameLib_SetupAFPose(idAnimator_AF& animator, int currentTime);
void GameLib_DriveAFPoseWithForces(idAnimator_AF& animator);
idAnimator_AF::testSolidResult_t GameLib_TestAFSolid(
    const idAnimator_AF& animator, bool noClip);
void GameLib_SyncAFAnimator(idAnimator_AF& animator, int currentTime,
    bool force);
void GameLib_BreakAFConstraint(idAnimator_AF& animator,
    const char* name, const idVec3& impulse);
void GameLib_UnattachAFBones(idAnimator_AF& animator,
    const idVec3& impulse);
bool GameLib_ConfigureAFAnimator(idAnimator_AF& animator,
    int currentTime, const idVec3& gravity);
void GameLib_ApplyAFImpulse(idAnimator_AF& animator, int entityNumber,
    int bodyId, int impulseId, const idVec3& point,
    const idVec3& impulse);
void GameLib_ApplyAFForce(idAnimator_AF& animator, int entityNumber,
    int bodyId, const idVec3& point, const idVec3& force);
idAnimator_AF::testSolidResult_t GameLib_StartAFFromCurrentPose(
    idAnimator_AF& animator, int currentTime, bool inherit, bool noClip,
    const idVec3& velocity);

namespace {
void InitBranch(idMD6Branch& branch, idMD6Node* const right) {
    std::memset(&branch, 0, sizeof(branch));
    branch.type = idMD6Node::NODE_BRANCH;
    branch.right = right;
    branch.leftTimeOverride = -1;
    branch.rightTimeOverride = -1;
    branch.filterGroup = MD6_WEIGHTGROUP_ALL;
    branch.currentAlpha = 1.0f;
    branch.targetAlpha = 1.0f;
    branch.blendType = idMD6Branch::BLEND_LINEAR;
}
}

idAnimator_AF::idAnimator_AF()
    : idAnimator_Base()
    , articulatedFigure(nullptr)
    , sndBounceTable(nullptr)
    , prtBounceTable(nullptr)
    , bindConstraints(16)
    , canDeattachBones(false)
    , afName()
    , clip(nullptr)
    , treeAnimator(nullptr)
    , modifiedAnim(nullptr)
    , baseOrigin(0.0f, 0.0f, 0.0f)
    , baseAxis(1.0f)
    , jointMods(16)
    , jointBody(16)
    , lastRenderModelOrigin(0.0f, 0.0f, 0.0f)
    , lastRenderModelAxis(1.0f)
    , gravityBeforeSync(0.0f, 0.0f, 0.0f)
    , poseTime(0)
    , restStartTime(0)
    , modifiesOrigin(false)
    , isLoaded(false)
    , isRunningPhysics(false)
    , isActive(false)
    , isClientAuthoritativeActive(false)
    , isSyncing(false)
    , hasBindConstraints(false)
    , walkIKDisabled(false)
    , syncConstraints(16)
    , physicsObj()
    , physicsCallbacks(nullptr)
    , AFLeaf{}
    , mergeBranch(nullptr)
    , soundEmitter(nullptr)
    , bounceChannel(0)
    , nextSoundTime(0)
    , impactMgr(nullptr)
    , oldIsActive(false)
    , fakeCB(nullptr)
    , storedDeclAF(nullptr)
    , lastTime(0)
    , initCount(0)
    , lastImpulseTime(0)
    , serializeImpulseBuffer{}
    , numSerializedImpulses(0)
    , inheritAnimationVelocity(false)
    , inheritOverrideVelocity(false)
    , overrideVelocity(0.0f, 0.0f, 0.0f) {
}

idAnimator_AF::~idAnimator_AF() { ShutdownAF(); }

bool idAnimator_AF::InternalInit(const idAnimatorParms_Base& parameters) {
    mergeBranch = GameLib_AllocMD6Branch(parameters.animStack);
    if (mergeBranch == nullptr) return false;
    treeAnimator = GameLib_GetTreeAnimator(parameters.animStack);
    AFLeaf.Init(modifiedAnim, 0.0f, idMD6Leaf::WRAP_CLAMP,
        MD6_WEIGHTGROUP_ALL);
    InitBranch(*mergeBranch, &AFLeaf);
    return GameLib_InitAFAnimator(*this, parameters.animStack);
}

void idAnimator_AF::InternalShutdown(idAnimStack* const stack) {
    GameLib_ShutdownAFAnimator(*this);
    if (mergeBranch != nullptr) {
        GameLib_FreeMD6Branch(stack, mergeBranch);
        mergeBranch = nullptr;
    }
}

bool idAnimator_AF::InternalIsContributing() const {
    return isLoaded && (isActive || isRunningPhysics || isSyncing);
}

void idAnimator_AF::InternalPreBlendTree(const idAnimStack* const stack,
        const int currentTime, const int ticksPerSecond) {
    if (isLoaded) GameLib_UpdateAFAnimator(*this, stack, currentTime,
        ticksPerSecond);
}

void idAnimator_AF::SerializeSnapshot(idSerializer* const serializer) {
    if (serializer != nullptr) GameLib_SerializeAFAnimator(serializer, *this);
}

void idAnimator_AF::PreBlendSnapshot(idAnimStack* const stack,
        const int currentTime, const int ticksPerSecond,
        const float fraction) {
    GameLib_PreBlendAFSnapshot(*this, stack, currentTime, ticksPerSecond,
        fraction);
}

idBounds idAnimator_AF::GetBounds() const {
    return GameLib_GetAFAnimatorBounds(*this);
}
int idAnimator_AF::BodyForJoint(const idJointIndex joint) const {
    return GameLib_AFBodyForJoint(*this, joint);
}
void idAnimator_AF::GetModelTransform(idVec3& origin, idMat3& axis) const {
    GameLib_GetAFModelTransform(*this, origin, axis);
}
void idAnimator_AF::Start() { GameLib_SetAFRunning(*this, true); }
void idAnimator_AF::Stop() { GameLib_SetAFRunning(*this, false); }
void idAnimator_AF::AddBindConstraints() {
    GameLib_AddAFBindConstraints(*this); hasBindConstraints = true;
}
void idAnimator_AF::RemoveBindConstraints() {
    GameLib_RemoveAFBindConstraints(*this); hasBindConstraints = false;
}
void idAnimator_AF::ZeroAllImpulses() {
    GameLib_ZeroAFImpulses(*this); numSerializedImpulses = 0;
}
void idAnimator_AF::EndSync() {
    GameLib_EndAFSync(*this); isSyncing = false;
}
void idAnimator_AF::ShutdownAF() {
    if (isLoaded || isRunningPhysics) GameLib_ShutdownAFAnimator(*this);
    isLoaded = isRunningPhysics = isActive = isSyncing = false;
}
int idAnimator_AF::Collide(const int bodyId, trace_t& collision,
        const idVec3& velocity) {
    return GameLib_CollideAFAnimator(*this, bodyId, collision, velocity);
}
void idAnimator_AF::AddDynamicBindConstraint(const int type,
        const idStr& name) {
    GameLib_AddDynamicAFBindConstraint(*this, type, name);
}
bool idAnimator_AF::UpdateAnimation() {
    return GameLib_UpdateAFAnimation(*this);
}
void idAnimator_AF::SetupPose(const int currentTime) {
    GameLib_SetupAFPose(*this, currentTime); poseTime = currentTime;
}
void idAnimator_AF::DrivePoseWithForces() {
    GameLib_DriveAFPoseWithForces(*this);
}
idAnimator_AF::testSolidResult_t idAnimator_AF::TestSolid(
        const bool noClip) const { return GameLib_TestAFSolid(*this, noClip); }
void idAnimator_AF::Sync(const int currentTime, const bool force) {
    GameLib_SyncAFAnimator(*this, currentTime, force); isSyncing = true;
}
void idAnimator_AF::BreakConstraint(const char* const name,
        const idVec3& impulse) {
    GameLib_BreakAFConstraint(*this, name, impulse);
}
void idAnimator_AF::UnattachBones(const idVec3& impulse) {
    GameLib_UnattachAFBones(*this, impulse);
}
bool idAnimator_AF::InitAF(idAnimStack* const stack,
        idClip* const collisionClip, idImpactManager* const impactManager,
        idSoundEmitter* const emitter, const int soundChannel,
        const idVec3& gravity, const int currentTime,
        idPhysicsCallbacks* const callbacks) {
    clip = collisionClip; impactMgr = impactManager; soundEmitter = emitter;
    bounceChannel = soundChannel; physicsCallbacks = callbacks;
    treeAnimator = GameLib_GetTreeAnimator(stack);
    isLoaded = GameLib_ConfigureAFAnimator(*this, currentTime, gravity);
    ++initCount;
    return isLoaded;
}
void idAnimator_AF::ApplyImpulse(const int entityNumber, const int bodyId,
        const int impulseId, const idVec3& point, const idVec3& impulse) {
    GameLib_ApplyAFImpulse(*this, entityNumber, bodyId, impulseId, point,
        impulse);
    if (numSerializedImpulses < 8)
        serializeImpulseBuffer[numSerializedImpulses++] =
            afImpulse_t{entityNumber, bodyId, point, impulse};
}
void idAnimator_AF::ApplyForce(const int entityNumber, const int bodyId,
        const idVec3& point, const idVec3& force) {
    GameLib_ApplyAFForce(*this, entityNumber, bodyId, point, force);
}
idAnimator_AF::testSolidResult_t idAnimator_AF::StartFromCurrentPose(
        const int currentTime, const bool inherit, const bool noClip,
        const idVec3& velocity) {
    return GameLib_StartAFFromCurrentPose(*this, currentTime, inherit,
        noClip, velocity);
}
