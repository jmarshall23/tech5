#pragma once

#include "gamelib/animstack/animator_base.h"
#include "gamelib/physics/physics_af.h"
#include "idlib/containers/list.h"
#include "idlib/text/str.h"

class idAFConstraint;
class idAnimatedEntityPhysicsCallbacksFake;
class idDeclAF;
class idDeclAF_Body;
class idDeclAF_Constraint;
class idDeclImpactParticle;
class idDeclImpactSound;
class idImpactManager;
class idMaterial;
class idPhysicsCallbacks;
class idSoundEmitter;
struct trace_t;
enum invalidJointHandle_t : int;
using idJointHandle = idHandle<unsigned short, invalidJointHandle_t, 65535>;
enum AFJointModType_t : int {
    AF_JOINTMOD_AXIS = 0,
    AF_JOINTMOD_ORIGIN,
    AF_JOINTMOD_BOTH
};

class alignas(8) idAnimator_AF : public idAnimator_Base {
public:
    enum testSolidResult_t : int {
        TESTSOLID_NOT_IN_SOLID = 0,
        TESTSOLID_IN_SOLID_NOCLIP = 1,
        TESTSOLID_IN_SOLID = 2,
        TESTSOLID_MAX = 3
    };
    struct idBindConstraint {
        enum bindConstraint_t : int { Fixed = 0, BallAndSocket, Universal };
        bindConstraint_t type;
        idStr name;
        idStr bodyName;
        idStr jointName;
        bool shouldClamp;
    };
    struct idAFJointMod {
        int bodyId;
        idVec3 jointBodyOrigin;
        idMat3 jointBodyAxis;
        idJointIndex jointIndex;
        AFJointModType_t jointMod;
    };
    struct idSyncConstraint {
        idJointHandle jointHandle;
        idAFConstraint* constraint;
    };
    struct afImpulse_t {
        int physId;
        int bodyId;
        idVec3 point;
        idVec3 impulse;
    };

    idAnimator_AF();
    ~idAnimator_AF() override;

    priority_t GetStackPriority() override { return PRIORITY_AF; }
    serializeType_t GetSerializeType() override { return STYPE_AF; }
    void SerializeSnapshot(idSerializer* serializer) override;
    void PreBlendSnapshot(idAnimStack* stack, int currentTime,
        int ticksPerSecond, float fraction) override;
    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalShutdown(idAnimStack* stack) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    bool InternalIsContributing() const override;
    const idMD6Branch* InternalGetMergeBranch() const override {
        return mergeBranch;
    }
    idMD6Branch* InternalGetMergeBranch() override { return mergeBranch; }

    idBounds GetBounds() const;
    int BodyForJoint(idJointIndex joint) const;
    void GetModelTransform(idVec3& origin, idMat3& axis) const;
    void Start();
    void Stop();
    void AddBindConstraints();
    void RemoveBindConstraints();
    void ZeroAllImpulses();
    void EndSync();
    void ShutdownAF();
    int Collide(int bodyId, trace_t& collision, const idVec3& velocity);
    void AddDynamicBindConstraint(int type, const idStr& name);
    bool UpdateAnimation();
    void SetupPose(int currentTime);
    void DrivePoseWithForces();
    testSolidResult_t TestSolid(bool noClip) const;
    void Sync(int currentTime, bool force);
    void BreakConstraint(const char* name, const idVec3& impulse);
    void UnattachBones(const idVec3& impulse);
    bool InitAF(idAnimStack* stack, idClip* collisionClip,
        idImpactManager* impactManager, idSoundEmitter* emitter,
        int soundChannel, const idVec3& gravity, int currentTime,
        idPhysicsCallbacks* callbacks);
    void ApplyImpulse(int entityNumber, int bodyId, int impulseId,
        const idVec3& point, const idVec3& impulse);
    void ApplyForce(int entityNumber, int bodyId, const idVec3& point,
        const idVec3& force);
    testSolidResult_t StartFromCurrentPose(int currentTime, bool inherit,
        bool noClip, const idVec3& velocity);

    const idDeclAF* articulatedFigure;
    const idDeclImpactSound* sndBounceTable;
    const idDeclImpactParticle* prtBounceTable;
    idList<idBindConstraint, 71> bindConstraints;
    bool canDeattachBones;
    idStr afName;
    idClip* clip;
    idTreeAnimator* treeAnimator;
    const idMD6Anim* modifiedAnim;
    idVec3 baseOrigin;
    idMat3 baseAxis;
    idList<idAFJointMod, 71> jointMods;
    idList<int, 71> jointBody;
    idVec3 lastRenderModelOrigin;
    idMat3 lastRenderModelAxis;
    idVec3 gravityBeforeSync;
    int poseTime;
    int restStartTime;
    bool modifiesOrigin;
    bool isLoaded;
    bool isRunningPhysics;
    bool isActive;
    bool isClientAuthoritativeActive;
    bool isSyncing;
    bool hasBindConstraints;
    bool walkIKDisabled;
    idList<idSyncConstraint, 71> syncConstraints;
    idPhysics_AF physicsObj;
    idPhysicsCallbacks* physicsCallbacks;
    idMD6LeafPause AFLeaf;
    idMD6Branch* mergeBranch;
    idSoundEmitter* soundEmitter;
    int bounceChannel;
    int nextSoundTime;
    idImpactManager* impactMgr;
    bool oldIsActive;
    idAnimatedEntityPhysicsCallbacksFake* fakeCB;
    const idDeclAF* storedDeclAF;
    int lastTime;
    int initCount;
    int lastImpulseTime;
    afImpulse_t serializeImpulseBuffer[8];
    int numSerializedImpulses;
    bool inheritAnimationVelocity;
    bool inheritOverrideVelocity;
    idVec3 overrideVelocity;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_AF::idBindConstraint) == 104,
    "Recovered AF bind-constraint ABI changed");
static_assert(sizeof(idAnimator_AF::idAFJointMod) == 60,
    "Recovered AF joint-mod ABI changed");
static_assert(sizeof(idAnimator_AF::idSyncConstraint) == 8,
    "Recovered AF sync-constraint ABI changed");
static_assert(sizeof(idAnimator_AF::afImpulse_t) == 32,
    "Recovered AF impulse ABI changed");
static_assert(sizeof(idAnimator_AF) == 1608,
    "Recovered idAnimator_AF ABI changed");
#endif
