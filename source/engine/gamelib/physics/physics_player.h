#pragma once

#include "gamelib/physics/clip.h"
#include "gamelib/physics/physics_actor.h"
#include "idlib/math/angles.h"

#include <cstdint>

class idMaterial;
class idPush;
class idSerializer;

enum pmtype_t : int {
    PM_NORMAL = 0,
    PM_DEAD = 1,
    PM_SPECTATOR = 2,
    PM_FREEZE = 3,
    PM_NOCLIP = 4,
    PM_VEHICLE_NOCLIP = 5,
    PM_PERFECTORIGIN = 6,
    PM_EXPLICIT = 7,
    PM_SLIDE = 8,
    PM_MAX = 9
};

enum swimdepthstate_t : int {
    SWIMDEPTH_STATE_NONE = 0,
    SWIMDEPTH_STATE_ON_SURFACE = 1,
    SWIMDEPTH_STATE_UNDER_SURFACE = 2
};

struct playerExplicitMove_t {
    enum velocityType_t : int {
        VEL_EXPLICIT = 0,
        VEL_OVERRIDE = 1,
        VEL_CURRENT = 2
    };

    idVec3 delta;
    bool clipMove;
    velocityType_t velocityType;
    idVec3 overrideVelocity;
    int ignoreEntityNum;
};

struct playerPState_t {
    idVec3 localOrigin;
    idVec3 worldOrigin;
    idVec3 velocity;
    idVec3 pushVelocity;
    idAngles deltaViewAngles;
    float stepUp;
    pmtype_t movementType;
    int movementFlags;
    int movementTime;
};

#ifndef ID_USERCMD_T_DEFINED
#define ID_USERCMD_T_DEFINED
struct alignas(4) usercmd_t {
    int buttons;
    std::int16_t buttons2;
    char forwardmove;
    char rightmove;
    char upmove;
    std::uint8_t reserved : 6;
    std::uint8_t fromBot : 1;
    std::uint8_t inhibited : 1;
    std::int16_t angles[3];
    int clientGameFrame;
    float pos[3];
    std::int16_t pitch;
    std::int16_t yaw;
    std::int16_t roll;
    std::uint8_t predictionStateBits;
    int serverGameTime;
    std::uint16_t fireCount;
    std::int16_t fireAngles[2];
    std::int16_t firePos[3];
    std::uint8_t vehicleThrottle;
    std::uint8_t speed;
};
#endif

class idPhysics_Player : public idPhysics_Actor {
public:
    using playerMoveHandler_t = bool (*)(int, const idVec3*,
        const idVec3*, const idVec3*, const idVec3*, const usercmd_t*);

    idPhysics_Player();
    ~idPhysics_Player() override;

    void SetClipModel(idClipModel*, float, int, bool) override;
    void SetOrigin(const idVec3*, int) override;
    void SetAxis(const idMat3*, int) override;
    void Translate(const idVec3*, int) override;
    void Rotate(const idRotation*, int) override;
    const idVec3* GetLocalOrigin(int) override;
    const idMat3* GetLocalAxis(int) override;
    void SetLinearVelocity(const idVec3*, int) override;
    void SetAngularVelocity(const idVec3*, int) override;
    idVec3* GetLinearVelocity(idVec3*, int) override;
    idVec3* GetAngularVelocity(idVec3*, int) override;
    void SetWaterLevel(float, int) override;
    void SetWaterEntNum(int) override;
    int GetWaterEntNum() override;
    void SetWaterSurfaceWrldHeight(float) override;
    float GetWaterSurfaceWrldHeight() override;
    void GetImpactInfo(int, const idVec3*, impactInfo_t*) override;
    void ApplyImpulse(int, const idVec3*, const idVec3*) override;
    void ApplyForce(int, const idVec3*, const idVec3*) override;
    void Activate() override;
    void PutToRest() override;
    bool IsAtRest() override;
    bool IsPushable(int) override;
    void SaveState() override;
    void RestoreState() override;
    bool Evaluate(int, int) override;
    void UpdateTime(int) override;
    void SetPushed(int) override;
    idVec3* GetPushedLinearVelocity(idVec3*, int) override;
    idVec3* GetPushedAngularVelocity(idVec3*, int) override;
    void SetMaster(bool, const idVec3*, const idMat3*, bindFlags_t) override;
    void SetLocalOrigin(const idVec3*, int) override;
    void SetLocalAxis(const idMat3*, int) override;
    int GetBlockingEntityNum() override;
    int GetLinearEndTime() override;
    int GetAngularEndTime() override;

    void RestoreStateFromState(playerPState_t*);
    void ClearPushedVelocity();
    void Serialize(idSerializer*, playerPState_t*);
    void SerializeNonPredictiveState(idSerializer*);

    void SetSlideFriction(float);
    bool HasJumped() const;
    bool HasCrouched() const;
    bool HasStoodUp() const;
    bool HasSteppedUp() const;
    float GetStepUp() const;
    bool IsCrouching() const;
    void SetClientCrouch(bool);
    void SetSprintSliding(bool);
    void SetClipModelStanding(idClipModel*);
    void SetWalkFriction(float);
    void SetSpeed(float, float);
    void SetMaxStepHeight(float);
    void SetMaxJumpHeight(float);
    void SetMovementType(pmtype_t);
    void SetKnockBack(int, bool);
    void SetDebugLevel(bool);
    void SetSwimStroke(const idVec3&, int, bool, bool);
    bool GetIsUnderWater() const;
    void StartPerfectOrigin(const idVec3&, int);
    void SetClientDeferredOrigin(const idVec3&);
    void SetPlayerInput(const usercmd_t&, const idAngles&);
    bool ClientPusherLocked(bool*);
    void UpdateNonPredictiveClip();
    bool CanStand();
    bool CanStand(const idVec3&);
    void CheckGround();
    void CheckLadder(bool);
    void ForcePhysicsQuery();
    void ClearCrouch();
    void SetCrouch(bool);

    playerExplicitMove_t explicitMove;
    playerExplicitMove_t explicitMove2;
    playerPState_t current;
    playerPState_t previous;
    playerPState_t saved;
    idClipModel* clipModel_standing;
    idClipModel* clipModel_crouched;
    idClipModel* clipModel_sprintSlide;
    idClipModel* clipModel_dead;
    const idMaterial* overrideClipMaterial;
    idPush* pusher;
    idClipQuery slideMoveQuery;
    idClipQuery ladderQuery1;
    idClipQuery ladderQuery2;
    idClipQuery contentsQuery;
    int lastContents;
    float walkSpeed;
    float crouchSpeed;
    float maxStepHeight;
    float maxJumpHeight;
    int debugLevel;
    float walkAccelerate;
    float airAccelerate;
    float flyAccelerate;
    float waterAccelerate;
    float walkFriction;
    float airFriction;
    float flyFriction;
    float waterFriction;
    float slideFriction;
    usercmd_t command;
    usercmd_t prevcmd;
    idAngles viewAngles;
    int framemsec;
    float frametime;
    float playerSpeed;
    idVec3 viewForward;
    idVec3 viewRight;
    bool walking;
    bool startedOnGround;
    bool groundPlane;
    trace_t groundTrace;
    int groundSurfaceFlags;
    bool inhibitSprint;
    bool inhibitJump;
    bool toggleCrouch;
    bool ladder;
    idVec3 ladderNormal;
    bool canLadder;
    swimdepthstate_t currentSwimDepthState;
    idVec3 swimStrokeVelocity;
    int swimStrokeTimeLeft;
    int swimStrokeTime;
    bool swimStrokeAltCurve;
    bool swimStrokeIgnoreInput;
    int currentWaterEnt;
    float currentWaterSurfaceHeight;
    float blockedAccelerationPercent;
    idVec3 blockedAccelerationVec;
    float modifiedMovementMaxPercent;
    float modifiedMovementAngle;
    idVec3 modifiedAccelerationVec;
    bool canCrouchSprint;
    int lastJumpChance;
    idVec3 perfectOriginPosition;
    int perfectOriginDuration;
    int perfectOriginTime;
    idVec3 externalVelocity;
    bool clientOriginSet;
    idVec3 nextClientOrigin;
    bool forcedClientCrouchState;
    bool clientPusherLocked;
    float pushDeltaZ;
    playerMoveHandler_t ownerJumpHandler;
    playerMoveHandler_t ownerCrouchHandler;
    playerMoveHandler_t ownerCrouchJumpHandler;

private:
    float CmdScale(const usercmd_t&) const;
    void Accelerate(const idVec3&, float, float);
    void UpdateExternalVelocity();
    void SlideMoveDeferred(bool, bool, bool, bool);
    void SlideMoveNonDeferred(bool, bool, bool, bool);
    void SlideMove(bool, bool, bool, bool);
    void Friction();
    void NoclipMove();
    void CorrectAllSolid(trace_t&, int);
    bool CheckJump();
    void WaterJumpMove();
    void SwimMove();
    void AirMove();
    void WalkMove();
    void PerfectOriginMove(int);
    void DeadMove();
    void SpectatorMove();
    void LadderMove();
    void ExplicitMove(playerExplicitMove_t&);
    void CheckDuck();
    void ResolveSlideMove();
    void MovePlayer(int);
    void SelectClipModel(idClipModel*);
};

static_assert(sizeof(playerExplicitMove_t) == 36,
    "Recovered explicit player movement ABI changed");
static_assert(sizeof(playerPState_t) == 76,
    "Recovered player physics state ABI changed");
static_assert(sizeof(usercmd_t) == 60,
    "Recovered user command ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idPhysics_Player) == 1352,
    "Recovered idPhysics_Player ABI changed");
#endif
