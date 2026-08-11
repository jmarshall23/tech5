#pragma once

#include "../entities/entityptr.h"
#include "../ai/targetting/targetfilter.h"
#include "../../../shared/idlib/containers/bitflag.h"
#include "../../../shared/idlib/containers/list.h"
#include "../../../shared/idlib/math/vector.h"

#include <cstdint>
#include <vector>

class idBot;
class idBotWorldState;
class idEntity;
class idGuiListBox;

enum botTargetRecordFlags_t : unsigned int {
    TARGET_RECORD_FLAG_INFOV = 0x001,
    TARGET_RECORD_FLAG_ISALLY = 0x002,
    TARGET_RECORD_FLAG_ISNOTARGET = 0x004,
    TARGET_RECORD_FLAG_ISVISIBLE_THIS_FRAME = 0x008,
    TARGET_RECORD_FLAG_ISAUDIBLE_THIS_FRAME = 0x010,
    TARGET_RECORD_FLAG_CAN_SEE = 0x020,
    TARGET_RECORD_FLAG_CAN_HEAR = 0x040,
    TARGET_RECORD_FLAG_ISCROUCHING = 0x080,
    TARGET_RECORD_FLAG_IN_TARGETS_FOV = 0x100
};

enum botEntityFlags_t : int {
    BOT_ENTITY_FLAGS_NULL = 0,
    BOT_ENTITY_FLAGS_HEALTH = 0x01,
    BOT_ENTITY_FLAGS_ARMOR = 0x02,
    BOT_ENTITY_FLAGS_AMMO = 0x04,
    BOT_ENTITY_FLAGS_WEAPON = 0x08,
    BOT_ENTITY_FLAGS_EXPLOSIVE = 0x10,
    BOT_ENTITY_FLAGS_SHOOTABLE = 0x20,
    BOT_ENTITY_FLAGS_NAV_OBSTACLE = 0x40,
    BOT_ENTITY_FLAGS_OBJECTIVE = 0x80,
    BOT_ENTITY_FLAGS_AVOID = 0x100,
    BOT_ENTITY_FLAGS_TRACABLE = 0x200
};

enum botEntityType_t : int {
    BOT_ENTITY_TYPE_NULL = 0,
    BOT_ENTITY_TYPE_PLAYER = 0x01,
    BOT_ENTITY_TYPE_PROJECTILE = 0x02,
    BOT_ENTITY_TYPE_PICKUP = 0x04,
    BOT_ENTITY_TYPE_DISPENSER = 0x08,
    BOT_ENTITY_TYPE_PROP = 0x10,
    BOT_ENTITY_TYPE_AI = 0x20,
    BOT_ENTITY_TYPE_TURRET = 0x40,
    BOT_ENTITY_TYPE_MAX = 0x41
};

class idLeakyIntegrator01 {
public:
    idLeakyIntegrator01();
    bool Update(int currentTime, float seconds);
    bool Update(int currentTime);
    bool AddStimulus(int currentTime, float stimulus);
    bool IsStillTriggered();
    bool WasTriggered() const { return (triggerState & 0x80U) != 0U; }
    void SetTriggered(bool triggered);

    float value;
    float decayRate;
    int lastUpdateMS;
    std::uint8_t triggerState;
    std::uint8_t padding[3];
};

class idBotTargetRecord {
public:
    struct volatileData_t {
        volatileData_t();
        void Clear();

        int timeLastVisible;
        int timeLastAttackedBy;
        idBitFlag32 targetFlags;
        float health;
        float distToTarget;
        float dotToTarget;
        float heightOfTarget;
        idLeakyIntegrator01 visibleTracker;
        idLeakyIntegrator01 audibleTracker;
        idVec3 lastSeenLocation;
        idVec3 lastHeardLocation;
        idVec3 lastAttackedLocation;
        idVec3 positionLastSawTarget;
        idVec3 positionLastAttackedByTarget;
    };

    idBotTargetRecord();
    ~idBotTargetRecord();

    volatileData_t volatileData;
    idEntityPtr<const idEntity> targetEntity;
};

class idBotClosestVisibleTargetFilter final : public idBotTargetFilter {
public:
    idBotClosestVisibleTargetFilter();
    const char* GetDebugName() override;
    void CheckTarget(int index, idBotTargetRecord* targetRecord) override;
    void Reset() override;

    float closestDistance;
};

struct entInfo_t {
    bool active;
    int entityFlags;
    int entityType;
    idEntityPtr<const idEntity> entity;
};

class idBotEntityFilter {
public:
    idBotEntityFilter();
    virtual ~idBotEntityFilter();
    virtual void CheckEntity(int, const entInfo_t&) {}
    virtual void PreCheckEntities(int) {}
    virtual void Reset();
    virtual void Init(int desiredEntType, int desiredEntFlags,
        int ignoreEntFlags);

    int bestEntityIndex;
    int desiredEntityType;
    int desiredEntityFlags;
    int ignoreEntityFlags;
    idEntityPtr<const idEntity> bestEntity;
};

class idBotEntityListFilter : public idBotEntityFilter {
public:
    idBotEntityListFilter();
    ~idBotEntityListFilter() override;
    void Reset() override;
    const idEntity* GetEntityForIndex(int index) const;
    idList<entInfo_t, 5> entitiesList;
};

class idBotTargetableEntityListFilter final : public idBotEntityListFilter {
public:
    ~idBotTargetableEntityListFilter() override = default;
    void PreCheckEntities(int numEntitiesInMasterList) override;
    void CheckEntity(int index, const entInfo_t& entityInfo) override;
};

struct idBotTargetSnapshot {
    bool valid = false;
    idVec3 eyePosition = idVec3(0.0f, 0.0f, 0.0f);
    idVec3 forward = idVec3(1.0f, 0.0f, 0.0f);
    float health = 0.0f;
    bool hostile = false;
    bool noTarget = false;
    bool crouching = false;
    bool isAI = false;
    bool visible = false;
};

class idBotWorldStateServices {
public:
    virtual ~idBotWorldStateServices() = default;
    virtual int GetScaledGameTime() const = 0;
    virtual float GetFovDotThreshold() const = 0;
    virtual int GetEntitySpawnId(const idEntity* entity) const = 0;
    virtual const idEntity* ResolveEntitySpawnId(int spawnId) const = 0;
    virtual int GetEntityListHandle() const = 0;
    virtual void GetTargetableEntities(
        std::vector<entInfo_t>& entities) const = 0;
    virtual bool IsOwnerEntity(const idBot& bot,
        const idEntity& entity) const = 0;
    virtual idVec3 GetOwnerEyePosition(const idBot& bot) const = 0;
    virtual idVec3 GetOwnerForward(const idBot& bot) const = 0;
    virtual bool GetTargetSnapshot(const idBot& bot,
        const idEntity& entity, idBotTargetSnapshot& snapshot) const = 0;
    virtual bool IsGoalEnemyLocked(const idBot& bot) const = 0;
    virtual void SetGoalEnemy(idBot& bot, const idEntity* entity) = 0;
    virtual void DrawDebugInfo(const idBotWorldState& state) const = 0;
    virtual void UpdateBotGUI(const idBotWorldState& state,
        idGuiListBox& infoList) const = 0;
    virtual void RenderWorldInfo(const idBotWorldState& state,
        idGuiListBox& infoList) const = 0;
};

void Tungsten_SetBotWorldStateServices(idBotWorldStateServices* services);

class idBotWorldState {
public:
    idBotWorldState();
    ~idBotWorldState();

    idBotTargetRecord* GetRecordForIndex(int index);
    idBotTargetRecord* GetRecordForEntity(const idEntity* entity);
    int GetRecordIndexForEntity(const idEntity* entity) const;
    void DrawDebugInfo();
    void FindBestTarget();
    void UpdateBotGUI(idGuiListBox& infoList) const;
    void RenderWorldInfo(idGuiListBox& infoList) const;
    void ClearVolatileData();
    void SetLastAttacker(const idEntity* attacker, int time);
    void UpdateTargetsInfo();
    void UpdateTargets();
    void Update();

    int enemyCheckDebounce;
    int lastEnemyUpdateTime;
    int lastAttackerTime;
    int lastUpdatedEntityListHandle;
    float fov;
    idBotTargetFilter* targetFilter;
    idBot* owner;
    idEntityPtr<const idEntity> lastAttacker;
    idList<idBotTargetRecord, 5> targetRecords;
};

static_assert(sizeof(idLeakyIntegrator01) == 16,
    "Recovered leaky integrator ABI changed");
static_assert(sizeof(idBotTargetRecord::volatileData_t) == 120,
    "Recovered volatile bot target data ABI changed");
static_assert(sizeof(idBotTargetRecord) == 124,
    "Recovered bot target record ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idBotWorldState) == 48,
    "Recovered bot world state ABI changed");
#endif
