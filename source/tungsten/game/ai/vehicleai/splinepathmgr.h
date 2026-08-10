#pragma once

#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

class idEntity;
class idVehicleAI;

enum navSplineType_t : int {
    NAV_SPLINE_TYPE_DEFAULT = 0,
    NAV_SPLINE_TYPE_VEHICLE_AI = 1,
    NAV_SPLINE_TYPE_QUEST = 2
};

struct idAISplineNavSpline {
    idStr name;
    navSplineType_t type = NAV_SPLINE_TYPE_DEFAULT;
    bool hasSplinePath = true;
    bool hasStartNode = false;
    bool hasEndNode = false;
    float length = 0.0f;
    idVec3 boundsMins = idVec3(0.0f, 0.0f, 0.0f);
    idVec3 boundsMaxs = idVec3(0.0f, 0.0f, 0.0f);
    int drawTime = 0;
};

struct idAISplinePathPosition {
    idAISplineNavSpline* navSpline = nullptr;
    float distance = 0.0f;
    float rightDistance = 0.0f;
};

struct idAISplineTracker {
    idEntity* owner = nullptr;
    idAISplinePathPosition pathPosition;
    idAISplinePathPosition goalPathPosition;
    navSplineType_t navSplineType = NAV_SPLINE_TYPE_DEFAULT;
};

struct idAISplineDormancyRef {
    int spawnId = 0x1FFF;
};

enum idAISplineTrackerOwnerKind : int {
    AI_SPLINE_OWNER_NONE = 0,
    AI_SPLINE_OWNER_VEHICLE = 1,
    AI_SPLINE_OWNER_PICKUP = 2,
    AI_SPLINE_OWNER_OTHER = 3
};

struct idAISplinePathDebugInfo {
    idAISplineNavSpline* spline = nullptr;
};

struct idAISplineStatsPathEntry {
    idStr name;
    float distance = 0.0f;
};

struct idAISplineVehicleStats {
    bool valid = false;
    idStr name;
    idStr ownerName;
    int entityNumber = -1;
    float desiredSteering = 0.0f;
    int desiredBraking = 0;
    float speedLimit = 0.0f;
    float desiredSpeed = 0.0f;
    float actualSpeed = 0.0f;
    float rightDistance = 0.0f;
    float splineDistance = 0.0f;
    int obstacleFlags = 0;
    int speedFlags = 0;
    int steerFlags = 0;
    float turnSpeedRatio = 0.0f;
    idStr idObstacles;
    bool dormant = false;
    bool aiSpecificDormancy = false;
    bool hasVehicleCar = false;
    float health = 0.0f;
    int difficultyLevel = -1;
    float difficultyAttackScale = 0.0f;
    float difficultyDamageScale = 0.0f;
    float difficultySpeedRate = 0.0f;
    float difficultyAccuracy = 0.0f;
    float difficultyDamageTakenScale = 0.0f;
    float stopDistance = 0.0f;
    float moveDistance = 0.0f;
    float decelDistance = 0.0f;
    float maxCurveSpeed = 0.0f;
    float maxCurveCosine = 1.0f;
    float maxStepCosine = 1.0f;
    int avoidanceType = 3;
    float powerTurnSpeed = 0.0f;
    float powerTurnTime = 0.0f;
    float stopPowerTurnSpeed = 0.0f;
    float traversalStepSize = 0.0f;
    float backupSpeed = 0.0f;
    idStr decisionState;
    idStr movementState;
    idStr attackState;
    idStr commandState;
    idStr enemyName;
    bool hasPathToGoal = false;
    float distanceToGoal = 0.0f;
    float pathDistanceToGoal = 0.0f;
    idList<idAISplineStatsPathEntry, 5> path;
};

struct idAISplineRuntimeOptions {
    idStr follow;
    bool next = false;
    bool previous = false;
    bool reset = false;
    bool debug = false;
    bool timer = false;
    int stats = 0;
    float showAllPaths = 0.0f;
    bool showPathBounds = false;
    float pathStepSize = 300.0f;
    bool position = false;
    bool graph = false;
    bool waypoints = false;
    bool disablePathing = false;
    int trace = 0;
};

struct idAISplineDebugCameraState {
    int scaledTime = 0;
    int frameMilliseconds = 1;
    bool forceFrameStep = false;
    bool freeCamera = false;
    idVec3 vehicleOrigin = idVec3(0.0f, 0.0f, 0.0f);
    idAngles vehicleAngles = idAngles(0.0f, 0.0f, 0.0f);
    idAngles freeAngles = idAngles(0.0f, 0.0f, 0.0f);
    idVec3 gravityNormal = idVec3(0.0f, 0.0f, -1.0f);
    float placementPitch = 0.0f;
    float placementYaw = 0.0f;
    float cameraYaw = 0.0f;
    float cameraPitch = 0.0f;
    float cameraRange = 0.0f;
    float cameraHeight = 0.0f;
    float minimumPitch = -89.0f;
    float wildYaw = 180.0f;
    float wildPitch = 180.0f;
    float wildRoll = 180.0f;
    float recoverRate = 0.01f;
};

struct idAISplineCameraTrace {
    float fraction = 1.0f;
    bool startSolid = false;
    idVec3 endPosition = idVec3(0.0f, 0.0f, 0.0f);
};

class idAISplinePathMgr {
public:
    idAISplinePathMgr();
    virtual ~idAISplinePathMgr() = default;

    virtual void Update();
    virtual void SpecialSetup();

    void CycleFollow();
    void UpdateTrackersPeriodic(const idList<int, 5>& indexList,
        int frequencyInFrames, bool fastUpdateOthers);
    bool GetDebugAiView(idVec3& origin, idMat3& axis, float& fovX);
    void ShowVehicleAiStats();
    void DrawWaypoints();
    void SetupWaypoints();
    bool CanFindEnemy(idVehicleAI* vehicleAI);
    void RemoveFromDormancyList(idVehicleAI* vehicleAI);
    void AddToDormancyList(idVehicleAI* vehicleAI);

    float updatetime;
    int nextRecalcTime;
    idList<idAISplineTracker, 5> trackerPool;
    idList<int, 5> usedTrackers;
    idAISplineTracker null_splineTracker;
    idAISplineNavSpline tempNavSpline;
    idList<idAISplineDormancyRef, 5> dormancyList;
    navSplineType_t navSplineType;
    idStr tempNavSplinePathName;
    bool trackPickups;
    int numVehiclePickups;
    idAISplineTracker* debugTracker;
    idAngles currentViewAngles;
    idAngles lastCarAngles;
    int wildSpinTime;
    float viewAnglesDeltaPerc;
    int lastDrawTime;
    long long navSplinePathTimerTicks;
    int navSplinePathCount;
    int navSplinePathCount2;
    long long navSplineTrackerTimerTicks;
    int navSplineTrackerCount;
    long long navSplineClosestPosTimerTicks;
    int navSplineClosestPosCount;
    long long navSplineClosestPosSectionTimerTicks;
    int navSplineClosestPosSectionCount;
};

bool Tungsten_IsAISplineRuntimeAvailable();
int Tungsten_GetAISplineScaledTime();
int Tungsten_GetAISplineGameFrame();
int Tungsten_GetAISplineGameFlags();
void Tungsten_GetAISplineRuntimeOptions(idAISplineRuntimeOptions& options);
void Tungsten_SetAISplineFollowName(const char* name);
void Tungsten_ClearAISplineNext();
void Tungsten_ClearAISplinePrevious();
void Tungsten_ClearAISplineReset();
void Tungsten_ClearAISplinePosition();
void Tungsten_SetAISplineTrace(int value);

int Tungsten_GetVehicleAICount();
idVehicleAI* Tungsten_GetVehicleAI(int index);
idVehicleAI* Tungsten_FindVehicleAI(const char* name);
bool Tungsten_IsVehicleAIValid(const idVehicleAI& vehicleAI);
const char* Tungsten_GetVehicleAIName(const idVehicleAI& vehicleAI);
const char* Tungsten_GetVehicleAIOwnerName(const idVehicleAI& vehicleAI);
void Tungsten_GetAISplineVehicleStats(const idVehicleAI& vehicleAI,
    idAISplineVehicleStats& stats);

bool Tungsten_GetAISplineDebugCameraState(const idVehicleAI& vehicleAI,
    idAISplineDebugCameraState& state);
void Tungsten_TraceAISplineCamera(const idVec3& start,
    const idVec3& end, idAISplineCameraTrace& trace);

void Tungsten_PrepareAISplineDebugHUD();
void Tungsten_PrintAISplineDebugHUD(const char* format, ...);
void Tungsten_BeginAISplineTraceRecording(unsigned long lastError);
unsigned long Tungsten_GetAISplineLastError();
void Tungsten_ResetAISplineVehicles();
void Tungsten_CleanupAISplineEntities(idAISplinePathMgr& manager);
void Tungsten_CycleVehicleFollow();

int Tungsten_GetAISplineDebugPathCount();
void Tungsten_GetAISplineDebugPath(int index,
    idAISplineNavSpline& path);
void Tungsten_DrawAISplinePath(int index, const idVec4& color,
    float startDistance, float endDistance, float stepSize);
void Tungsten_SetAISplinePathDrawTime(int index, int drawTime);
bool Tungsten_GetAISplineDebugPlayerOrigin(idVec3& origin);
void Tungsten_DrawAISplineBounds(int index, const idVec4& color);
idAISplineTracker* Tungsten_FindAISplineDebugTracker(
    idAISplinePathMgr& manager);
void Tungsten_SetAISplineTrackerGoalToCurrent(
    idAISplineTracker& tracker, bool doPathSearch);
void Tungsten_DrawAISplineDebugTracker(idAISplinePathMgr& manager,
    idAISplineTracker& tracker, float pathStepSize,
    bool pathingDisabled);
void Tungsten_DrawAISplineGraph(idAISplinePathMgr& manager);

idAISplineTrackerOwnerKind Tungsten_GetAISplineTrackerOwnerKind(
    const idEntity* owner);
bool Tungsten_GetAISplineEntityOrigin(const idEntity& entity,
    idVec3& origin);
void Tungsten_SetAISplineTrackerWorldPosition(
    idAISplineTracker& tracker, const idVec3& position);
void Tungsten_UpdateAISplineTracker(
    idAISplineTracker& tracker, bool fullUpdate);
void Tungsten_ReleaseAISplineTracker(idAISplinePathMgr& manager,
    idAISplineTracker* tracker);

int Tungsten_GetAISplineWaypointCount();
bool Tungsten_IsAISplineWaypoint(int index);
const char* Tungsten_GetAISplineWaypointName(int index);
bool Tungsten_GetAISplineWaypointOrigin(int index, idVec3& origin);
int Tungsten_GetAISplineWaypointTargetCount(int index);
bool Tungsten_GetAISplineWaypointTargetPathName(int waypointIndex,
    int targetIndex, idStr& pathName);
bool Tungsten_GetAISplineWaypointTargetPosition(int waypointIndex,
    int targetIndex, idAISplinePathPosition& position);
bool Tungsten_GetAISplineWaypointPosition(int waypointIndex,
    idAISplinePathPosition& position);
idAISplineNavSpline* Tungsten_FindAISplineNavSpline(
    const char* name, bool exact);
idAISplinePathPosition Tungsten_GetClosestAISplinePathPosition(
    const idVec3& origin, idAISplineNavSpline* spline,
    float maximumDistance, float tolerance);
void Tungsten_SetAISplineWaypointPosition(int waypointIndex,
    const idAISplinePathPosition& position);
idVec3 Tungsten_GetAISplinePositionWorldPoint(
    const idAISplinePathPosition& position, bool centerLine);
void Tungsten_DrawAISplineWaypointArrow(
    const idVec3& start, const idVec3& end);
void Tungsten_DrawAISplineWaypointSphere(const idVec3& origin,
    float radius);
void Tungsten_WarnUnassociatedAISplineWaypoint(const char* name);

int Tungsten_MakeAISplineVehicleSpawnId(const idVehicleAI* vehicleAI);
idVehicleAI* Tungsten_ResolveAISplineVehicleSpawnId(int spawnId);

void Tungsten_PrintAISplineTimerStats(const idAISplinePathMgr& manager);
