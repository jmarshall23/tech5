#pragma once

#include "encountergroups.h"
#include "idlib/containers/hashindex.h"

class idEncounterGroupManager {
public:
    idEncounterGroupManager();
    virtual ~idEncounterGroupManager();

    void Init();
    void Update();
    idEncounterGroup* GroupForHandle(
        const encounterGroupHandle_t& handle);
    int FindIndex(const char* groupName) const;
    int FindIndex(const encounterGroupHandle_t& handle) const;
    encounterGroupHandle_t FindGroup(const char* groupName);
    encounterGroupHandle_t HandleForName(const char* groupName) const;
    bool SendGroupMessage(const encounterGroupHandle_t& handle,
        aiGroupMessage_t message, idEntity* entity);
    void Shutdown();
    void GetActiveHintNodeCoverIndices(
        idList<int, 5>& coverIndices) const;
    encounterGroupHandle_t AddGroup(const idEncounterGroup& otherGroup);
    encounterGroupHandle_t AddGroup(const char* groupName);

    encounterGroupList_t groups;
    int nextThinkTime;
    idHashIndex hashIndex;
    short curHandle;
};

// Runtime owners not yet safe to include in the standalone recovery target.
int Tungsten_GetEncounterGroupScaledTime();
void Tungsten_EncounterGroupDuplicateWarning(const char* format,
    const char* groupName);
