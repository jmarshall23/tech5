#pragma once

#include "ai2_debug.h"

struct idAI2ThrowAvailabilityRuntime {
    bool grenadesEnabled;
    int conditionFlags;
    aiItemSelect_t conditionSelections[AISELECTCONDITION_MAX];
    int currentTime;
    int nextThrowTime;
};

struct idAI2ItemTarget {
    idVec3 position;
    idVec3 offsetFromOwner;
    float distanceSquared;
};

enum idAI2WeaponPoint_t : int {
    AI2_WEAPON_POINT_MUZZLE = 0,
    AI2_WEAPON_POINT_LASER = 1
};

struct idAI2WeaponPointRuntime {
    bool attachmentExists;
    bool attachmentValid;
    bool attachmentHasModel;
    bool tagResolved;
    idVec3 tagOrigin;
    idMat3 tagAxis;
    idVec3 modelOrigin;
    idMat3 modelAxis;
};

struct idAI2ProjectileDeclRuntime {
    const idDeclProjectile* projectileDecl;
    bool throwable;
    bool parabolicFlight;
    float speed;
    float minimumTrajectoryTime;
    float maximumTrajectoryTime;
    float minimumRange;
    float minimumOptimalRange;
    float maximumOptimalRange;
    float maximumRange;
};

struct idAI2LaunchProjectileRuntime {
    idWeapon* equippedWeapon;
    const idDeclInventory* equippedThrowable;
    idVec3 ownerOrigin;
    idVec3 confirmedOrigin;
    idVec3 confirmedEyePosition;
    idVec3 confirmedVelocity;
    bool crouching;
    float forwardVelocity;
    float movingThrowSpeed;
    float throwLagMilliseconds;
};

enum idAI2ProjectileAnimEvent_t : int {
    AI2_PROJECTILE_EVENT_LAUNCH_ITEM = 0,
    AI2_PROJECTILE_EVENT_LAUNCH_ITEM_FROM_WEAPON = 1,
    AI2_PROJECTILE_EVENT_THROW_GRENADE = 2
};

float Tungsten_GetAI2GravityMagnitude();
int Tungsten_GetAI2GameMillisecondsPerFrame();
idTrajectory_Parabolic& Tungsten_GetAI2Trajectory(
    idAI2& ai, int index);
const idTrajectory_Parabolic& Tungsten_GetAI2Trajectory(
    const idAI2& ai, int index);
idTrajectory_Parabolic& Tungsten_GetAI2TrajectoryElement(
    idTrajectory_Parabolic* trajectories, int index);
void Tungsten_CalculateAI2Trajectory(idTrajectory_Parabolic& trajectory,
    const idVec3& start, const idVec3& destination,
    float gravityMagnitude, float travelTime);
void Tungsten_TestAI2Trajectory(idTrajectory_Parabolic& trajectory,
    float timeStep, const idAI2& owner, bool deferred);
bool Tungsten_AI2TrajectoryWaiting(const idTrajectory_Parabolic& trajectory);
bool Tungsten_AI2TrajectoryHasResults(
    const idTrajectory_Parabolic& trajectory);
void Tungsten_ClearAI2TrajectoryResults(
    idTrajectory_Parabolic& trajectory);

bool Tungsten_GetAI2ThrowAvailabilityRuntime(const idAI2& ai,
    idAI2ThrowAvailabilityRuntime& runtime);
bool Tungsten_GetAI2OwnerOrigin(const idAI2& ai, idVec3& origin);
const idDeclInventory* Tungsten_SelectAI2ProjectileItem(
    const idAI2& ai, aiItemSelect_t selector,
    const idWeapon* weapon, const idAI2ItemTarget& target);
const idWeapon* Tungsten_GetAI2EquippedWeapon(const idAI2& ai);
bool Tungsten_GetAI2EquippedWeaponRanges(const idAI2& ai,
    idAI2ProjectileDeclRuntime& runtime);
bool Tungsten_GetAI2ProjectileDeclRuntime(
    const idDeclInventory& item,
    idAI2ProjectileDeclRuntime& runtime);

const idMD6Anim* Tungsten_GetAI2AnimForOverride(
    const idAI2& ai, overrideAnim_t overrideAnimation);
bool Tungsten_GetAI2WeaponPointRuntime(const idAI2& ai,
    const idWeapon& weapon, idAI2WeaponPoint_t point,
    idAI2WeaponPointRuntime& runtime);
void Tungsten_WarnAI2Utils(const char* text);

const idCachedJoint* Tungsten_GetAI2CachedJoint(
    const idAI2& ai, const idEventDef& eventDefinition,
    const idMD6Anim& animation, int cachedIndex, int& frameRate);
bool Tungsten_GetAI2ModelTransform(const idAI2& ai,
    idVec3& origin, idMat3& axis);
bool Tungsten_GetAI2MuzzleTagData(const idAI2& ai,
    const idWeapon& weapon, idVec3& origin, idMat3& axis);

bool Tungsten_ShowAI2Trajectories();
void Tungsten_DrawAI2ParabolicTrajectory(const idVec3& start,
    const idVec3& target,
    const idTrajectory_Parabolic::parabolicParms_t& trajectory,
    float timeStep);
bool Tungsten_LaunchAI2ProjectileEntity(idAI2& owner,
    const idDeclProjectile& projectileDecl, const idVec3& start,
    const idMat3& fireAxis, bool hasPointTarget,
    const idVec3& targetPosition, float initialSpeed,
    int startTime);

bool Tungsten_GetAI2LaunchProjectileRuntime(const idAI2& ai,
    const aiSenseState_t& senseState,
    idAI2LaunchProjectileRuntime& runtime);
float Tungsten_GetAI2ThrowLagSeconds(const idAI2& ai);
bool Tungsten_ExtrapolateAI2SensePosition(
    const aiSenseState_t& senseState, float seconds,
    idVec3& futurePosition);
const idEventDef* Tungsten_GetAI2ProjectileEventDef(
    idAI2ProjectileAnimEvent_t eventType);
int Tungsten_GetAI2EntitySpawnId(const idEntity* entity);
void Tungsten_StoreAI2ProjectileInfo(
    idAI2& ai, const idAIProjectileInfo& info);

bool Tungsten_GetAI2GrenadeAnimation(const idAI2& ai,
    coverAction_t coverAction,
    idIndex<short, invalidAIAnimNodeIndex_t>& nodeIndex,
    const idMD6Anim*& animation);
bool Tungsten_AI2GrenadeOriginOverlapsGroupMember(
    const idAI2& ai, const idVec3& origin);
