#pragma once

#include "idlib/containers/list.h"
#include "idlib/handle.h"
#include "idlib/text/str.h"

class idEntity;

// Retail enum 1718 and typedef 31041 from tungsten.exe.h.
enum invalidEncounterGroup_t : int {
    INVALID_ENCOUNTER_GROUP = -1
};

using encounterGroupHandle_t =
    idHandle<short, invalidEncounterGroup_t, static_cast<short>(-1)>;

constexpr short NULL_ENCOUNTER_GROUP = static_cast<short>(-1);

enum aiGroupMessage_t : int {
    AIGROUPMSG_ENABLE = 0,
    AIGROUPMSG_DISABLE = 1,
    AIGROUPMSG_ADD_ENEMY = 2,
    AIGROUPMSG_SET_ENEMY = 3,
    AIGROUPMSG_MAX = 4
};

// This is the source-facing portion required by encountergroupmanager.cpp.
// The remainder of the recovered retail layout stays owned by the much larger
// encountergroups.cpp translation unit and will be expanded with that unit.
class idEncounterGroup {
public:
    void Init(const char* groupName, encounterGroupHandle_t handle);
    void Think();
    int NumLivingMembers() const;
    void GetCurrentCombatStageCoverIndices(
        idList<int, 5>& coverIndices) const;
    void OnGroupMessage(aiGroupMessage_t message, idEntity* entity);

    idStr groupName;
    int numLivingMembers = 0;
    encounterGroupHandle_t handle;
};

using encounterGroupList_t = idList<idEncounterGroup, 5>;
