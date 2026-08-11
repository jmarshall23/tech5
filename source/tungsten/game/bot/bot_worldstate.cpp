#include "bot_worldstate.h"

#include <algorithm>
#include <cmath>
#include <cfloat>

namespace {
idBotWorldStateServices* g_worldServices = nullptr;
constexpr int INVALID_ENTITY_SPAWN_ID = 0x1FFF;

void SetFlag(idBitFlag32& flags, const unsigned int flag,
        const bool enabled) {
    if (enabled) flags.flags |= flag;
    else flags.flags &= ~flag;
}
} // namespace

void Tungsten_SetBotWorldStateServices(
        idBotWorldStateServices* const services) {
    g_worldServices = services;
}

idLeakyIntegrator01::idLeakyIntegrator01()
    : value(0.0f), decayRate(0.0f), lastUpdateMS(-1),
      triggerState(0), padding{ 0, 0, 0 } {
}

void idLeakyIntegrator01::SetTriggered(const bool triggered) {
    triggerState = static_cast<std::uint8_t>(
        (triggerState & 0x7FU) | (triggered ? 0x80U : 0U));
}

bool idLeakyIntegrator01::Update(const int, const float seconds) {
    if (seconds > 0.0f) {
        value = (std::max)(0.0f,
            (std::min)(1.0f, value + decayRate * seconds));
    }
    if (WasTriggered()) return true;
    SetTriggered(value >= 1.0f);
    return WasTriggered();
}

bool idLeakyIntegrator01::Update(const int currentTime) {
    const float seconds = static_cast<float>(currentTime - lastUpdateMS)
        * 0.001f;
    lastUpdateMS = currentTime;
    return Update(currentTime, seconds);
}

bool idLeakyIntegrator01::AddStimulus(const int currentTime,
        const float stimulus) {
    Update(currentTime);
    value = (std::max)(0.0f, (std::min)(1.0f, value + stimulus));
    if (!WasTriggered()) SetTriggered(value >= 1.0f);
    return WasTriggered();
}

bool idLeakyIntegrator01::IsStillTriggered() {
    value = (std::max)(0.0f, (std::min)(1.0f, value + decayRate));
    if (WasTriggered() && value <= 0.0f) SetTriggered(false);
    return WasTriggered();
}

// Header retail symbol: ?Clear@volatileData_t@idBotTargetRecord@@QAAXXZ
// EA: 0x82B449F8, RVA: 0x00B449F8
void idBotTargetRecord::volatileData_t::Clear() {
    visibleTracker.SetTriggered(false);
    visibleTracker.value = 0.0f;
    audibleTracker.SetTriggered(false);
    audibleTracker.value = 0.0f;
    targetFlags.flags = 0U;
    timeLastVisible = 0;
    health = 0.0f;
    timeLastAttackedBy = 0;
    distToTarget = 0.0f;
    dotToTarget = 0.0f;
    heightOfTarget = 0.0f;
    lastAttackedLocation.Zero();
    lastSeenLocation.Zero();
    lastHeardLocation.Zero();
    positionLastSawTarget.Zero();
    positionLastAttackedByTarget.Zero();
}

// Header retail symbol: ??0volatileData_t@idBotTargetRecord@@QAA@XZ
// EA: 0x82B44CB8, RVA: 0x00B44CB8
idBotTargetRecord::volatileData_t::volatileData_t()
    : timeLastVisible(0), timeLastAttackedBy(0), targetFlags(), health(0.0f),
      distToTarget(0.0f), dotToTarget(0.0f), heightOfTarget(0.0f),
      visibleTracker(), audibleTracker(),
      lastSeenLocation(0.0f, 0.0f, 0.0f),
      lastHeardLocation(0.0f, 0.0f, 0.0f),
      lastAttackedLocation(0.0f, 0.0f, 0.0f),
      positionLastSawTarget(0.0f, 0.0f, 0.0f),
      positionLastAttackedByTarget(0.0f, 0.0f, 0.0f) {
    targetFlags.flags = 0U;
    Clear();
}

// Retail symbol: ?GetRecordForIndex@idBotWorldState@@QAAPAVidBotTargetRecord@@H@Z
// EA: 0x82B44B38, RVA: 0x00B44B38
idBotTargetRecord* idBotWorldState::GetRecordForIndex(const int index) {
    return &targetRecords[index];
}

// Retail symbol: ??0idBotTargetRecord@@QAA@XZ
// EA: 0x82B44D38, RVA: 0x00B44D38
idBotTargetRecord::idBotTargetRecord()
    : volatileData(), targetEntity() {
    const int currentTime = g_worldServices != nullptr
        ? g_worldServices->GetScaledGameTime() : 0;
    volatileData.visibleTracker.lastUpdateMS = currentTime;
    volatileData.visibleTracker.value = 0.0f;
    volatileData.visibleTracker.SetTriggered(false);
    volatileData.visibleTracker.decayRate = -0.05f;
    volatileData.audibleTracker.lastUpdateMS = currentTime;
    volatileData.audibleTracker.value = 0.0f;
    volatileData.audibleTracker.SetTriggered(false);
    volatileData.audibleTracker.decayRate = -0.05f;
}

// Retail symbol: ?GetRecordForEntity@idBotWorldState@@QAAPAVidBotTargetRecord@@PBVidEntity@@@Z
// EA: 0x82B44DD0, RVA: 0x00B44DD0
idBotTargetRecord* idBotWorldState::GetRecordForEntity(
        const idEntity* const entity) {
    const int index = GetRecordIndexForEntity(entity);
    return index >= 0 ? &targetRecords[index] : nullptr;
}

// Retail symbol: ?GetRecordIndexForEntity@idBotWorldState@@QBAHPBVidEntity@@@Z
// EA: 0x82B44EA8, RVA: 0x00B44EA8
int idBotWorldState::GetRecordIndexForEntity(
        const idEntity* const entity) const {
    if (entity == nullptr || g_worldServices == nullptr) return -1;
    for (int index = 0; index < targetRecords.Num(); ++index) {
        if (g_worldServices->ResolveEntitySpawnId(
                targetRecords[index].targetEntity.GetSpawnId()) == entity) {
            return index;
        }
    }
    return -1;
}

// Retail symbol: ?DrawDebugInfo@idBotWorldState@@QAAXXZ
// EA: 0x82B44F70, RVA: 0x00B44F70
void idBotWorldState::DrawDebugInfo() {
    if (g_worldServices != nullptr) g_worldServices->DrawDebugInfo(*this);
}

// Retail symbol: ?Reset@idBotTargetFilter@@UAAXXZ
// EA: 0x82B462E0, RVA: 0x00B462E0
const char* idBotTargetFilter::GetDebugName() {
    return "idBotTargetFilter";
}

void idBotTargetFilter::PreCheckTargets(int) {
}

void idBotTargetFilter::CheckTarget(int, idBotTargetRecord*) {
}

void idBotTargetFilter::SortTargets() {
}

void idBotTargetFilter::Reset() {
    bestTargetIndex = -1;
    bestTarget.Invalidate();
}

idBotClosestVisibleTargetFilter::idBotClosestVisibleTargetFilter()
    : closestDistance(FLT_MAX) {
    Reset();
}

// Header retail symbol: ?GetDebugName@idBotClosestVisibleTargetFilter@@UAAPBDXZ
// EA: 0x82B46CA8, RVA: 0x00B46CA8
const char* idBotClosestVisibleTargetFilter::GetDebugName() {
    return "ClosestVisibleTarget";
}

// Retail symbol: ?CheckTarget@idBotClosestVisibleTargetFilter@@UAAXHAAVidBotTargetRecord@@@Z
// EA: 0x82B463B8, RVA: 0x00B463B8
void idBotClosestVisibleTargetFilter::CheckTarget(const int index,
        idBotTargetRecord* const targetRecord) {
    if (targetRecord == nullptr) return;
    const unsigned int flags = targetRecord->volatileData.targetFlags.flags;
    const int currentTime = g_worldServices != nullptr
        ? g_worldServices->GetScaledGameTime() : 0;
    if ((flags & TARGET_RECORD_FLAG_ISALLY) == 0U
            && (flags & TARGET_RECORD_FLAG_ISNOTARGET) == 0U
            && targetRecord->volatileData.health > 0.0f
            && targetRecord->volatileData.timeLastVisible != 0
            && (targetRecord->volatileData.timeLastVisible + 10000 >= currentTime
                || (flags & TARGET_RECORD_FLAG_CAN_HEAR) != 0U)
            && targetRecord->volatileData.distToTarget < closestDistance) {
        bestTargetIndex = index;
        bestTarget.SetSpawnId(targetRecord->targetEntity.GetSpawnId());
        closestDistance = targetRecord->volatileData.distToTarget;
    }
}

// Retail symbol: ?Reset@idBotClosestVisibleTargetFilter@@UAAXXZ
// EA: 0x82B464E0, RVA: 0x00B464E0
void idBotClosestVisibleTargetFilter::Reset() {
    idBotTargetFilter::Reset();
    closestDistance = FLT_MAX;
}

// Retail symbol: ?FindBestTarget@idBotWorldState@@QAAXXZ
// EA: 0x82B451D8, RVA: 0x00B451D8
void idBotWorldState::FindBestTarget() {
    if (owner == nullptr || targetFilter == nullptr
            || g_worldServices == nullptr) return;
    const int currentTime = g_worldServices->GetScaledGameTime();
    if (lastEnemyUpdateTime + enemyCheckDebounce > currentTime) return;
    lastEnemyUpdateTime = currentTime;
    if (g_worldServices->IsGoalEnemyLocked(*owner)) return;
    targetFilter->Reset();
    targetFilter->PreCheckTargets(targetRecords.Num());
    for (int index = 0; index < targetRecords.Num(); ++index) {
        targetFilter->CheckTarget(index, &targetRecords[index]);
    }
    targetFilter->SortTargets();
    g_worldServices->SetGoalEnemy(*owner,
        g_worldServices->ResolveEntitySpawnId(
            targetFilter->bestTarget.GetSpawnId()));
}

// Retail symbol: ?UpdateBotGUI@idBotWorldState@@QBAXAAVidGuiListBox@@@Z
// EA: 0x82B45320, RVA: 0x00B45320
void idBotWorldState::UpdateBotGUI(idGuiListBox& infoList) const {
    if (g_worldServices != nullptr)
        g_worldServices->UpdateBotGUI(*this, infoList);
}

// Retail symbol: ?RenderWorldInfo@idBotWorldState@@QBAXAAVidGuiListBox@@@Z
// EA: 0x82B45590, RVA: 0x00B45590
void idBotWorldState::RenderWorldInfo(idGuiListBox& infoList) const {
    if (g_worldServices != nullptr)
        g_worldServices->RenderWorldInfo(*this, infoList);
}

// Retail symbol: ?ClearVolatileData@idBotWorldState@@QAAXXZ
// EA: 0x82B462F8, RVA: 0x00B462F8
void idBotWorldState::ClearVolatileData() {
    for (int index = 0; index < targetRecords.Num(); ++index)
        targetRecords[index].volatileData.Clear();
    if (targetFilter != nullptr) targetFilter->Reset();
    enemyCheckDebounce = 0;
    lastEnemyUpdateTime = 0;
    lastAttackerTime = 0;
    lastAttacker.Invalidate();
}

// Retail symbol: ?SetLastAttacker@idBotWorldState@@QAAXPBVidEntity@@H@Z
// EA: 0x82B46370, RVA: 0x00B46370
void idBotWorldState::SetLastAttacker(const idEntity* const attacker,
        const int time) {
    lastAttacker.SetSpawnId(attacker != nullptr && g_worldServices != nullptr
        ? g_worldServices->GetEntitySpawnId(attacker)
        : INVALID_ENTITY_SPAWN_ID);
    lastAttackerTime = time;
}

// Retail symbol: ??1idBotTargetRecord@@QAA@XZ
// EA: 0x82B46500, RVA: 0x00B46500
idBotTargetRecord::~idBotTargetRecord() {
    volatileData.Clear();
    targetEntity.Invalidate();
}

// Retail symbol: ?UpdateTargetsInfo@idBotWorldState@@QAAXXZ
// EA: 0x82B46538, RVA: 0x00B46538
void idBotWorldState::UpdateTargetsInfo() {
    if (owner == nullptr || g_worldServices == nullptr) return;
    const int currentTime = g_worldServices->GetScaledGameTime();
    const idVec3 ownerEye = g_worldServices->GetOwnerEyePosition(*owner);
    idVec3 ownerForward = g_worldServices->GetOwnerForward(*owner);
    ownerForward.NormalizeFast();
    for (int index = 0; index < targetRecords.Num(); ++index) {
        idBotTargetRecord& record = targetRecords[index];
        const idEntity* const entity = g_worldServices->ResolveEntitySpawnId(
            record.targetEntity.GetSpawnId());
        if (entity == nullptr) continue;
        idBotTargetSnapshot snapshot;
        if (!g_worldServices->GetTargetSnapshot(*owner, *entity, snapshot)
                || !snapshot.valid) continue;

        idVec3 toTarget = snapshot.eyePosition - ownerEye;
        const float distance = toTarget.NormalizeFast();
        const float ownerDot = ownerForward.Dot(toTarget);
        idVec3 toOwner = ownerEye - snapshot.eyePosition;
        toOwner.NormalizeFast();
        idVec3 targetForward = snapshot.forward;
        targetForward.NormalizeFast();
        const float targetDot = targetForward.Dot(toOwner);
        const bool recentlyAttacked =
            record.volatileData.timeLastAttackedBy + 5000 > currentTime;
        const bool inFov = ownerDot > fov;

        SetFlag(record.volatileData.targetFlags,
            TARGET_RECORD_FLAG_IN_TARGETS_FOV, targetDot > fov);
        SetFlag(record.volatileData.targetFlags,
            TARGET_RECORD_FLAG_ISCROUCHING, snapshot.crouching);
        SetFlag(record.volatileData.targetFlags,
            TARGET_RECORD_FLAG_ISNOTARGET, snapshot.noTarget);
        SetFlag(record.volatileData.targetFlags,
            TARGET_RECORD_FLAG_INFOV, inFov);
        SetFlag(record.volatileData.targetFlags,
            TARGET_RECORD_FLAG_ISALLY, !snapshot.hostile);
        SetFlag(record.volatileData.targetFlags,
            TARGET_RECORD_FLAG_ISVISIBLE_THIS_FRAME, snapshot.visible);
        SetFlag(record.volatileData.targetFlags,
            TARGET_RECORD_FLAG_ISAUDIBLE_THIS_FRAME, snapshot.isAI);
        record.volatileData.distToTarget = distance;
        record.volatileData.dotToTarget = ownerDot;
        record.volatileData.heightOfTarget =
            snapshot.eyePosition.z - ownerEye.z;

        bool canSee;
        if (snapshot.visible && (inFov || recentlyAttacked || snapshot.isAI)) {
            canSee = record.volatileData.visibleTracker.AddStimulus(
                currentTime, (recentlyAttacked ? 2.0f : 1.0f) * 0.3f);
        } else {
            canSee = record.volatileData.visibleTracker.IsStillTriggered();
        }
        SetFlag(record.volatileData.targetFlags,
            TARGET_RECORD_FLAG_CAN_SEE, canSee);
        if (canSee) {
            record.volatileData.timeLastVisible = currentTime;
            record.volatileData.lastSeenLocation = snapshot.eyePosition;
            record.volatileData.positionLastSawTarget = ownerEye;
        }

        const bool canHear = snapshot.isAI
            ? record.volatileData.audibleTracker.AddStimulus(currentTime, 0.2f)
            : record.volatileData.audibleTracker.IsStillTriggered();
        SetFlag(record.volatileData.targetFlags,
            TARGET_RECORD_FLAG_CAN_HEAR, canHear);
        if (canHear) record.volatileData.lastHeardLocation = snapshot.eyePosition;
        record.volatileData.health = snapshot.health;
    }
}

// Retail symbol: ??0idBotWorldState@@QAA@XZ
// EA: 0x82B47388, RVA: 0x00B47388
idBotWorldState::idBotWorldState()
    : enemyCheckDebounce(1), lastEnemyUpdateTime(static_cast<int>(0x80000000U)),
      lastAttackerTime(0), lastUpdatedEntityListHandle(-1), fov(0.0f),
      targetFilter(new idBotClosestVisibleTargetFilter()), owner(nullptr),
      lastAttacker(), targetRecords(0) {
    fov = g_worldServices != nullptr
        ? g_worldServices->GetFovDotThreshold() : 0.0f;
}

// Retail symbol: ??1idBotWorldState@@QAA@XZ
// EA: 0x82B47500, RVA: 0x00B47500
idBotWorldState::~idBotWorldState() {
    owner = nullptr;
    targetRecords.Clear();
    delete targetFilter;
    targetFilter = nullptr;
}

// Retail symbol: ?UpdateTargets@idBotWorldState@@QAAXXZ
// EA: 0x82B475F0, RVA: 0x00B475F0
void idBotWorldState::UpdateTargets() {
    if (owner == nullptr || g_worldServices == nullptr) return;
    const int entityListHandle = g_worldServices->GetEntityListHandle();
    if (lastUpdatedEntityListHandle == entityListHandle) return;
    targetRecords.SetNum(0);
    std::vector<entInfo_t> masterEntities;
    g_worldServices->GetTargetableEntities(masterEntities);
    idBotTargetableEntityListFilter filter;
    filter.Init(BOT_ENTITY_TYPE_PLAYER | BOT_ENTITY_TYPE_AI
        | BOT_ENTITY_TYPE_TURRET, BOT_ENTITY_FLAGS_SHOOTABLE, 0);
    filter.PreCheckEntities(static_cast<int>(masterEntities.size()));
    for (int index = 0; index < static_cast<int>(masterEntities.size()); ++index)
        filter.CheckEntity(index, masterEntities[index]);
    targetRecords.Resize(filter.entitiesList.Num());
    for (int index = 0; index < filter.entitiesList.Num(); ++index) {
        const idEntity* const entity = g_worldServices->ResolveEntitySpawnId(
            filter.entitiesList[index].entity.GetSpawnId());
        if (entity == nullptr || g_worldServices->IsOwnerEntity(*owner, *entity)
                || GetRecordIndexForEntity(entity) != -1) continue;
        idBotTargetRecord record;
        record.targetEntity.SetSpawnId(
            g_worldServices->GetEntitySpawnId(entity));
        targetRecords.Append(record);
    }
    lastUpdatedEntityListHandle = entityListHandle;
}

// Retail symbol: ?PreCheckEntities@idBotTargetableEntityListFilter@@UAAXH@Z
// EA: 0x82B47830, RVA: 0x00B47830
void idBotTargetableEntityListFilter::PreCheckEntities(
        const int numEntitiesInMasterList) {
    if (numEntitiesInMasterList > entitiesList.NumAllocated())
        entitiesList.Resize(numEntitiesInMasterList);
}

// Retail symbol: ?CheckEntity@idBotTargetableEntityListFilter@@UAAXHABUentInfo_t@@@Z
// EA: 0x82B47848, RVA: 0x00B47848
void idBotTargetableEntityListFilter::CheckEntity(
        const int, const entInfo_t& entityInfo) {
    if (entityInfo.active) entitiesList.Append(entityInfo);
}

// Retail symbol: ?Update@idBotWorldState@@QAAXXZ
// EA: 0x82B47868, RVA: 0x00B47868
void idBotWorldState::Update() {
    UpdateTargets();
    UpdateTargetsInfo();
    FindBestTarget();
    DrawDebugInfo();
}
