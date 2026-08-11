#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

#include <cstdint>

class idClipModel;
class idDeclBreakable;
class idDeclDamage;
class idDeclParticle;
class idDeclProjectileImpactEffect;
class idDeclTrackingParms;
class idEntity;
class idMaterial;
class idRenderModel;
class idSoundShader;
class idSplineWaypoint;
class idDrone;
struct trace_t;

struct idDroneBlendedSound {
    const idSoundShader* sound = nullptr;
    float minSpeedPitch = 0.0f;
    float maxSpeedPitch = 0.0f;
    float minThrustPitch = 0.0f;
    float maxThrustPitch = 0.0f;
    float minThrustVolume = 0.0f;
    float maxThrustVolume = 0.0f;
};

struct idDroneBehaviorPoint {
    idEntity* entityToScan = nullptr;
    int minTriggerCount = 0;
    int maxTriggerCount = 0;
    float distanceToScan = 0.0f;
    float slowDistance = 0.0f;
    float forcedCuriosity = 0.0f;
    float scanChance = 0.0f;
    int maxNumScans = 0;
    idEntity* startScanTrigger = nullptr;
    idEntity* endScanTrigger = nullptr;
    int exitScanState = 0;
    idSplineWaypoint* endScanWaypoint = nullptr;
    float endScanDesiredSpeedMultiplier = 0.0f;
    bool wasDroneWithinRange = false;
    int numScansDone = 0;
    int nextScanTime = 0;
};

struct idDroneDamageBehavior {
    int minTriggerCount = 0;
    int maxTriggerCount = 0;
    float healthPercent = 0.0f;
    idEntity* trigger = nullptr;
    bool scanAttackerFlag = false;
    idEntity* scanEntity = nullptr;
    float forcedCuriosity = 0.0f;
    float desiredSpeedMultiplier = 0.0f;
    bool hasBehaviorTriggered = false;
};

struct idDroneFocusCandidate {
    idEntity* entity = nullptr;
    idVec3 aimPoint{0.0f, 0.0f, 0.0f};
    float attitudeWeight = 1.0f;
    float visibilityWeight = 1.0f;
    float mutualFocusWeight = 0.4f;
    bool visible = false;
    bool recentlyConfirmed = false;
    bool isPlayer = false;
    bool isAI = false;
};

struct idDroneTraceResult {
    float fraction = 1.0f;
    idVec3 endPosition{0.0f, 0.0f, 0.0f};
    idVec3 normal{0.0f, 0.0f, 1.0f};
};

class idDroneServices {
public:
    virtual ~idDroneServices() = default;

    virtual int GetGameMilliseconds() const;
    virtual int GetGameMillisecondsPerFrame() const;
    virtual float RandomFloat(float maximum);
    virtual float RandomFloat(float minimum, float maximum);
    virtual int RandomInt(int maximum);
    virtual float MoveStateScaler(int row, int moveState) const;
    virtual float MoveStateTransitionTime(int oldState,
        int newState) const;
    virtual float MoveStateFacingAllowance(int oldState,
        int newState) const;
    virtual float MoveStateSpeedAllowance(int oldState,
        int newState) const;
    virtual float MoveStateRollAllowance(int oldState,
        int newState) const;
    virtual float StateFacingAllowance(int oldState,
        int newState) const;
    virtual float StateSpeedAllowance(int oldState,
        int newState) const;
    virtual float StateRollAllowance(int oldState,
        int newState) const;

    virtual idVec3 GetOrigin(const idDrone& drone) const;
    virtual idMat3 GetAxis(const idDrone& drone) const;
    virtual idVec3 GetEntityOrigin(const idEntity* entity) const;
    virtual idBounds GetEntityBounds(const idEntity* entity) const;
    virtual idVec3 GetEntityAimPoint(const idEntity* entity) const;
    virtual bool IsValidEntity(const idEntity* entity) const;
    virtual bool IsPlayer(const idEntity* entity) const;
    virtual bool IsAI(const idEntity* entity) const;
    virtual bool PlayerSubstituteMatches(const idEntity* configured,
        const idEntity* candidate) const;

    virtual void StartSound(idDrone& drone, int channel,
        const idSoundShader* sound);
    virtual void StopSound(idDrone& drone, int channel);
    virtual bool IsPlayingSound(const idDrone& drone, int channel) const;
    virtual void SetSoundVolume(idDrone& drone, int channel, float volume);
    virtual void SetSoundPitch(idDrone& drone, int channel, float pitch);
    virtual void UpdateSound(idDrone& drone);
    virtual void StartConditionFX(idDrone& drone, int condition);
    virtual void StopConditionFX(idDrone& drone, int condition);
    virtual void UpdateBaseFX(idDrone& drone);
    virtual void EmitGroundParticles(idDrone& drone,
        const idDeclParticle* particle, const idVec3& origin,
        const idVec3& velocity, float diversity);
    virtual bool TraceDown(const idDrone& drone, const idVec3& start,
        float distance, idDroneTraceResult& result);
    virtual void UpdateInfluenceTrail(idDrone& drone,
        const idVec3& position, float angle);
    virtual void AddInfluenceExplosion(idDrone& drone,
        const idVec3& origin, float radius);
    virtual void UpdateThrusterBeam(idDrone& drone, int thruster,
        const idVec3& start, const idVec3& end, float width,
        float power);
    virtual void UpdateFocusBeam(idDrone& drone, idEntity* focus,
        float width, float length, float power, float bob);
    virtual void EmitHealthParticles(idDrone& drone,
        const idDeclParticle* particle, const idVec3& origin,
        const idMat3& axis);

    virtual void RegisterWorldStateUser(idDrone& drone);
    virtual void UnregisterWorldStateUser(idDrone& drone);
    virtual void RegisterDrone(idDrone& drone);
    virtual void UnregisterDrone(idDrone& drone);
    virtual bool UsesRelaxedChatter(const idDrone& drone) const;
    virtual bool HasFaction(const idDrone& drone) const;
    virtual void ReportMissingFaction(const idDrone& drone);
    virtual int AddAttachment(idDrone& drone, const char* model,
        const char* tag);
    virtual void HideAttachments(idDrone& drone);
    virtual void ShowAttachments(idDrone& drone);
    virtual void ShowAttachment(idDrone& drone, int handle);
    virtual void HideAttachment(idDrone& drone, int handle);
    virtual void ConfigureSpawnPhysics(idDrone& drone,
        int contents, const idVec3& size);
    virtual void ConfigureRigidPhysics(idDrone& drone,
        int contents, int clipMask);
    virtual void SetRigidPhysicsEnabled(idDrone& drone, bool enabled);
    virtual void BecomeActive(idDrone& drone, int flags);
    virtual void HideEntity(idDrone& drone);
    virtual void ShowEntity(idDrone& drone);
    virtual void DormantBegin(idDrone& drone);
    virtual void DormantEnd(idDrone& drone, int timeDormant);
    virtual void UpdateAnimation(idDrone& drone);
    virtual void TouchTriggers(idDrone& drone);
    virtual void BaseThink(idDrone& drone);
    virtual void Present(idDrone& drone);

    virtual bool BuildPatrolWaypoints(idDrone& drone,
        idSplineWaypoint* initial,
        idList<idSplineWaypoint*, 5>& waypoints);
    virtual bool BuildInitialPath(idDrone& drone,
        const idList<idSplineWaypoint*, 5>& goals,
        float searchDirection, float& pathLength);
    virtual bool RebuildPath(idDrone& drone,
        const idList<idSplineWaypoint*, 5>& goals,
        const idList<float, 5>& searchDirections,
        float& pathLength);
    virtual idVec3 GetWorldPosAlongPath(const idDrone& drone,
        float distance) const;
    virtual void StepPath(idDrone& drone, float distance);
    virtual void GatherFocusCandidates(const idDrone& drone,
        idList<idDroneFocusCandidate, 5>& candidates) const;
    virtual void GatherObstacleEntities(const idDrone& drone,
        idList<idEntity*, 5>& entities) const;
    virtual void GatherPlayers(const idDrone& drone,
        idList<idEntity*, 5>& players) const;
    virtual void UpdateAIWorldState(idDrone& drone);

    virtual float DamageAmount(const idDeclDamage* damage) const;
    virtual bool GetTraceImpactPoint(const trace_t* trace,
        idVec3& point) const;
    virtual void ActivateEntity(idEntity* target, idEntity* activator);
    virtual bool HasExplosionFX(const idDrone& drone) const;
    virtual void StartExplosion(idDrone& drone);
    virtual void BeginSpinningDeath(idDrone& drone,
        const idVec3& linearVelocity,
        const idVec3& angularVelocity);
    virtual void ApplyDeathVelocity(idDrone& drone,
        const idVec3& velocity);
    virtual idDroneTraceResult TraceMotion(const idDrone& drone,
        const idVec3& start, const idVec3& end,
        const idMat3& startAxis, const idMat3& endAxis);
    virtual void EmitWallImpact(idDrone& drone,
        const idDeclProjectileImpactEffect* effect,
        const idDroneTraceResult& trace);
    virtual void QueueRemove(idDrone& drone);
    virtual void ReleaseRuntime(idDrone& drone);
    virtual void DeleteTemporaryClip(idClipModel* clipModel);
};

class idDrone {
public:
    enum attachment_t {
        BOTTOM_ATTACHMENT = 0,
        TOP_ATTACHMENT,
        LEFT_ATTACHMENT,
        RIGHT_ATTACHMENT,
        NUM_ATTACHMENTS
    };
    enum droneState_t {
        DS_WAITING = 0,
        DS_SEARCHING,
        DS_MOVING,
        DS_SCANNING,
        DS_RETREATING,
        DS_HIDE,
        DS_DEATH,
        DS_SET_SPEED,
        DS_ADJUST_SPEED,
        DS_NUM_DRONE_STATES
    };
    enum droneMoveState_t {
        DMS_STOPPED = 0,
        DMS_SEARCHING,
        DMS_SLOW,
        DMS_NORMAL,
        DMS_FAST,
        DMS_NUM_DRONE_MOVE_STATES
    };
    enum dronePathType_t {
        DPT_MOVE_TO = 0,
        DPT_PATROL,
        DPT_SEARCH,
        DPT_GOAL,
        DPT_AVOID,
        DPT_NUM_DRONE_PATH_TYPES
    };
    enum droneDeath_t {
        DD_EXPLOSION = 0,
        DD_SPINNING_OUT_OF_CONTROL,
        DD_RANDOM_DRONE_DEATH
    };

    using blendedSounds_t = idDroneBlendedSound;
    using behaviorPoint_t = idDroneBehaviorPoint;
    using damageBehavior_t = idDroneDamageBehavior;

    idDrone();
    virtual ~idDrone();
    static void SetServices(idDroneServices* services);
    static idDroneServices& Services();

    virtual void OnActivate(idEntity* activator);
    void DeployWeaponNow(int gunId);
    void StowWeaponNow(int gunId);
    void UpdateMoveStateMemberships();
    float GetDesiredSpeedForMoving();
    float GetDesiredRollForMoving();
    virtual void GetModelTransform(idVec3& origin, idMat3& axis) const;
    void DeployAndStowWeapon(int gunId, int armDelay, int disarmDelay);
    void UpdateEngineSound(int channel, blendedSounds_t& engineSound,
        float speed, float closure, float thrust,
        float minThrust, float maxThrust);
    void SetEngineSoundVolume(int channel, blendedSounds_t& engineSound,
        float thrust, float minThrust, float maxThrust);
    void ChangeMoveState(int newState, float time);
    float NearestSplinePositionFastGuess(const idVec3& goalPosition,
        idVec3& returnPosition) const;
    idVec3 GetDesiredFacingForMoving();
    virtual void UpdateFX();
    idVec3 Bump(const idVec3& contactPosition,
        const idVec3& forceDirection, float translationalForce,
        float rotationalForce, float reduceZScaler);
    void KillDrone();
    virtual void Hide();
    virtual void DormantBegin();
    idVec3 GetDesiredFacingForScanning();
    float FindAutoFocusEntity(idEntity*& bestEntity);
    void TurnOnScanner();
    void TurnOffScanner();
    bool FirstThink();
    void SetNewStateInternal(int newState);
    idVec3 GetDesiredFacing();
    void Spawn();
    virtual void Show();
    virtual void DormantEnd(int timeDormant);
    void SetStateSetMoveState(int newState, int newMoveState);
    void SetState(int newState);
    bool HandleObstacleAvoidance(const idEntity* ai, idBounds& bounds,
        idVec3& origin, idMat3& otherAxis);
    float GetPlayerAvoidanceDistance(const idEntity* player);
    bool StateThinkForScanning();
    virtual float Damage(idEntity* inflictor, idEntity* attacker,
        const idDeclDamage* damage, float damageScale,
        const idVec3& direction, trace_t* trace);
    bool StateThink();
    virtual void Think();
    float GetHealth() const { return health; }
    float GetHealthPercent() const {
        return startingHealth > 0.0f ? health / startingHealth : 0.0f;
    }

    bool slowForPlayer;
    idSplineWaypoint* initialWaypoint;
    void* initialPath;
    droneState_t initialState;
    bool fleeNearEnemyFlag;
    float startingHealth;
    const idDeclParticle* smokeParticle[3];
    const idDeclParticle* sparkParticle[2];
    const idDeclParticle* sputterParticle[3];
    const idDeclParticle* deathParticle[3];
    const idDeclProjectileImpactEffect* declWallSpark;
    const idDeclBreakable* declBreakable;
    int currentState;
    int nextState;
    int changeStateTime;
    int lastNonScanState;
    int moveStates[4];
    float moveStateMemberships[4];
    float moveStateMembershipDeltas[4];
    dronePathType_t currentPathType;
    int currentPathTypeParm;
    int patrolWaypointOn;
    int patrolDirection;
    idList<idSplineWaypoint*, 5> patrolWaypoints;
    float searchDirection;
    int searchNextUpdateTime;
    idList<idSplineWaypoint*, 5> goals;
    idList<float, 5> goalSearchDirections;
    idVec3 splineAheadPositions[4];
    bool firstThinkFlag;
    float health;
    idVec3 currentPosition;
    idVec3 previousOrigin;
    idVec3 desiredFacing;
    idVec3 currentFacing;
    float allowFacingChanges;
    idMat3 currentAxis;
    idMat3 previousAxis;
    float desiredSpeed;
    float desiredSpeedMultiplier;
    float overrideMaxDesiredSpeed;
    int resetSpeedOverrideCounter;
    float currentSpeed;
    float allowSpeedChanges;
    float lastFrameOverMove;
    float desiredRoll;
    float currentRoll;
    float allowRollChanges;
    float pitchToAlterSpeed;
    float lookUpToGoUpAount;
    float lowerNoseWhenAccelerating;
    float emergencyBrakeScaler;
    float obstacleAvoidanceMaxSpeed;
    idVec3 goalAvoidanceOffset;
    idVec3 averageAvoidanceOffset;
    int numActivates;
    int attachmentHandles[4];
    float weaponStatus[4];
    float weaponArmSpeed[4];
    int weaponArmTime[4];
    int weaponDisarmTime[4];
    float pathDistance;
    float splinePathLength;
    float deltaToFinalGoal;
    float distanceToFinalGoal;
    idVec3 immediateGoalPosition;
    idVec3 finalGoalPosition;
    float splineDistanceToFinalGoal;
    float rightDistanceToFinalGoal;
    float nearestPlayerDistance;
    float outOfControl;
    idVec3 additivePosition;
    idVec3 additiveMomentum;
    idQuat additiveFacing;
    idQuat additiveAngularMomentum;
    const idDeclParticle* groundParticlesFromFan;
    float secBetweenAdd;
    float maxAltitude;
    float particlesMultiplier;
    float addedParticleMovement;
    float influenceOuterRadius;
    float controllerShakeHighMag;
    float controllerShakeLowMag;
    int nextGroundFXTime;
    idList<blendedSounds_t, 5> smallEngineSounds;
    idList<blendedSounds_t, 5> largeEngineSounds;
    idList<blendedSounds_t, 5> afterburnerSounds;
    const idSoundShader* scannerSound;
    const idSoundShader* stopScannerSound;
    const idSoundShader* deployWeaponSound;
    const idSoundShader* stowWeaponSound;
    const idSoundShader* scanPlayerSound;
    const idSoundShader* explosionSound;
    float minPitchByClosing;
    float maxPitchByClosing;
    float largeEngineThrustLevel;
    float smallEngineThrustLevel;
    float afterburnerThrustLevel;
    float engineSoundsFade;
    const idDeclTrackingParms* declTrackingParms;
    float visibleSightTime;
    float visibleSightRadius;
    float disengageEnemyDistance;
    float optimalFocusEntityDistance;
    float optimalFocusAICuriosity;
    float optimalFocusPlayerCuriosity;
    const idMaterial* focusEntityMaterial;
    float focusEntityWidth;
    float focusEntityLength;
    idEntity* currentEnemy;
    bool isScannerOn;
    idEntity* currentScanEntity;
    float currentScanEntityCuriosity;
    float currentScanEntityEffectOn;
    idList<idEntity*, 5> previousFocusEntities;
    idList<int, 5> previousFocusEntityTimes;
    float focusEntityScanBob;
    float focusEntityScanBobDelta;
    idEntity* nearestForwardAi;
    int nearestForwardAiTime;
    const idMaterial* thrusterMaterial;
    float thrusterWidth;
    float thrusterLength;
    float lastThrusterPower[10];
    float thrusterShown[10];
    int thrusterFx[10];
    bool wasAfterburnerFxStarted;
    idVec3 lastMovement;
    idVec3 previousNonThrustMovement;
    float thrusterPerceivedFriction;
    float afterburnerAmount;
    int nextAfterburnerSmokeTime;
    idVec3 bobGoal;
    float engineSmokeAmount;
    int nextEngineSmokeTime;
    int nextSputterTime;
    idList<idEntity*, 5> touching;
    idList<behaviorPoint_t, 5> behaviorPoints;
    int nextBehaviorPointToTest;
    idList<damageBehavior_t, 5> damageBehaviors;
    float activateCuriosityOverride;
    int currentBehaviorPoint;
    idVec3 ahead[4];
    float aheadDistance[4];
    idVec3 toAhead[4];
    idVec3 aheadToAhead[4];
    float dot0to1to2;
    float dot1to2to3;
    bool rigidPhysicsEnabled;
    bool wasRemoveEventPosted;
    droneDeath_t deathVarietyDesired;
    int deathDoneTime;
    idEntity* deathTrigger;
    float delayToHideDrone;
    float minDeathThrustDuration;
    float maxDeathThrustDuration;
    idVec3 recentForceApplied;
    idVec3 deathThrust;
    idVec3 physicsOrigin;
    idMat3 physicsAxis;
    idVec3 clipModelSize;
    bool hidden;
    bool registeredWorldState;
    bool registeredDrone;
};

void idDroneSpawnClipCleanup(idClipModel* clipModel);
void idDroneThinkStringCleanup(idStr& string);
