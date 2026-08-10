#include "encountergroupmanager.h"

namespace {

short AdvanceEncounterGroupHandle(const short handle) {
    const unsigned short bits = static_cast<unsigned short>(handle);
    short next = static_cast<short>(bits + 1u);
    if (next == static_cast<short>(-1)) {
        next = 0;
    }
    return next;
}

} // namespace

// Retail symbol: ??0idEncounterGroupManager@@QAA@XZ
// EA: 0x82A91F70, RVA: 0x00A91F70
idEncounterGroupManager::idEncounterGroupManager()
    : groups(0)
    , nextThinkTime(0)
    , hashIndex(128, 128, TAG_HASHINDEX)
    , curHandle(0) {
}

// Retail symbol: ??1idEncounterGroupManager@@UAA@XZ
// EA: 0x82A92048, RVA: 0x00A92048
idEncounterGroupManager::~idEncounterGroupManager() = default;

// Retail symbol: ?Init@idEncounterGroupManager@@QAAXXZ
// EA: 0x82A91998, RVA: 0x00A91998
void idEncounterGroupManager::Init() {
    nextThinkTime = Tungsten_GetEncounterGroupScaledTime();
}

// Retail symbol: ?Update@idEncounterGroupManager@@QAAXXZ
// EA: 0x82A919E0, RVA: 0x00A919E0
void idEncounterGroupManager::Update() {
    if (Tungsten_GetEncounterGroupScaledTime() < nextThinkTime) {
        return;
    }

    for (int index = 0; index < groups.Num(); ++index) {
        groups[index].Think();
    }
    nextThinkTime = Tungsten_GetEncounterGroupScaledTime() + 512;
}

// Retail symbol: ?GroupForHandle@idEncounterGroupManager@@QAAPAVidEncounterGroup@@ABV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@@Z
// EA: 0x82A91A70, RVA: 0x00A91A70
idEncounterGroup* idEncounterGroupManager::GroupForHandle(
        const encounterGroupHandle_t& handle) {
    const int value = handle.Get();
    for (int index = hashIndex.First(value);
            index != -1; index = hashIndex.Next(index)) {
        if (groups[index].handle.Get() == value) {
            return &groups[index];
        }
    }
    return nullptr;
}

// Retail symbol: ?FindIndex@idEncounterGroupManager@@ABAHPBD@Z
// EA: 0x82A91AE8, RVA: 0x00A91AE8
int idEncounterGroupManager::FindIndex(const char* const groupName) const {
    for (int index = 0; index < groups.Num(); ++index) {
        if (idStr::Icmp(groups[index].groupName.c_str(), groupName) == 0) {
            return index;
        }
    }
    return -1;
}

// Retail symbol: ?FindIndex@idEncounterGroupManager@@ABAHABV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@@Z
// EA: 0x82A91B58, RVA: 0x00A91B58
int idEncounterGroupManager::FindIndex(
        const encounterGroupHandle_t& handle) const {
    const int value = handle.Get();
    for (int index = hashIndex.First(value);
            index != -1; index = hashIndex.Next(index)) {
        if (groups[index].handle.Get() == value) {
            return index;
        }
    }
    return -1;
}

// Retail symbol: ?FindGroup@idEncounterGroupManager@@QAA?AV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@PBD@Z
// EA: 0x82A91BD0, RVA: 0x00A91BD0
encounterGroupHandle_t idEncounterGroupManager::FindGroup(
        const char* const groupName) {
    const int index = FindIndex(groupName);
    return index >= 0
        ? groups[index].handle
        : encounterGroupHandle_t(NULL_ENCOUNTER_GROUP);
}

// Retail symbol: ?HandleForName@idEncounterGroupManager@@QBA?AV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@PBD@Z
// EA: 0x82A91C40, RVA: 0x00A91C40
encounterGroupHandle_t idEncounterGroupManager::HandleForName(
        const char* const groupName) const {
    const int index = FindIndex(groupName);
    return index >= 0
        ? groups[index].handle
        : encounterGroupHandle_t(static_cast<short>(-1));
}

// Retail symbol: ?SendGroupMessage@idEncounterGroupManager@@QAA_NABV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@W4aiGroupMessage_t@@PAVidEntity@@@Z
// EA: 0x82A91CB0, RVA: 0x00A91CB0
bool idEncounterGroupManager::SendGroupMessage(
        const encounterGroupHandle_t& handle,
        const aiGroupMessage_t message, idEntity* const entity) {
    const int index = FindIndex(handle);
    if (index < 0) {
        return false;
    }
    groups[index].OnGroupMessage(message, entity);
    return true;
}

// Retail symbol: ?Shutdown@idEncounterGroupManager@@QAAXXZ
// EA: 0x82A91D70, RVA: 0x00A91D70
void idEncounterGroupManager::Shutdown() {
    groups.ClearFree();
    hashIndex.Clear();
}

// Retail symbol: ?GetActiveHintNodeCoverIndices@idEncounterGroupManager@@QBAXAAV?$idList@H$04@@@Z
// EA: 0x82A91DE8, RVA: 0x00A91DE8
void idEncounterGroupManager::GetActiveHintNodeCoverIndices(
        idList<int, 5>& coverIndices) const {
    coverIndices.Clear();
    for (int groupIndex = 0; groupIndex < groups.Num(); ++groupIndex) {
        const idEncounterGroup& group = groups[groupIndex];
        if (group.NumLivingMembers() <= 0) {
            continue;
        }

        idList<int, 5> groupCoverIndices;
        group.GetCurrentCombatStageCoverIndices(groupCoverIndices);
        for (int coverIndex = 0;
                coverIndex < groupCoverIndices.Num(); ++coverIndex) {
            const int value = groupCoverIndices[coverIndex];
            if (coverIndices.FindIndex(value) < 0) {
                coverIndices.Append(value);
            }
        }
    }
}

// Retail symbol: ?AddGroup@idEncounterGroupManager@@QAA?AV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@ABVidEncounterGroup@@@Z
// EA: 0x82A924E0, RVA: 0x00A924E0
encounterGroupHandle_t idEncounterGroupManager::AddGroup(
        const idEncounterGroup& otherGroup) {
    const idStr groupName(otherGroup.groupName);
    if (FindIndex(groupName.c_str()) >= 0) {
        Tungsten_EncounterGroupDuplicateWarning(
            "Encounter group '%s' is defined more than once. Check for mutliple ai/groupmanager entities with the same group.",
            groupName.c_str());
    }

    const int index = groups.Append(otherGroup);
    const encounterGroupHandle_t assignedHandle(curHandle);
    curHandle = AdvanceEncounterGroupHandle(curHandle);
    groups[index].Init(groupName.c_str(), assignedHandle);
    hashIndex.Add(assignedHandle.Get(), index);
    return assignedHandle;
}

// Retail symbol: ?AddGroup@idEncounterGroupManager@@QAA?AV?$idHandle@FW4invalidEncounterGroup_t@@$0?0@@PBD@Z
// EA: 0x82A92608, RVA: 0x00A92608
encounterGroupHandle_t idEncounterGroupManager::AddGroup(
        const char* const groupName) {
    const int existingIndex = FindIndex(groupName);
    if (existingIndex >= 0) {
        return groups[existingIndex].handle;
    }

    idEncounterGroup* const group = groups.Alloc();
    const encounterGroupHandle_t assignedHandle(curHandle);
    curHandle = AdvanceEncounterGroupHandle(curHandle);
    group->Init(groupName, assignedHandle);
    hashIndex.Add(assignedHandle.Get(), groups.Num() - 1);
    return assignedHandle;
}
