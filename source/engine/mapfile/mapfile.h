#pragma once

#include "mapfile/mapmodel.h"

class idDeclEntityDef;
class idGame;

class idGroupState {
public:
    idStr groupName;
    unsigned int state = 0;
};

class idMapEditorStates {
public:
    virtual ~idMapEditorStates() = default;
    idList<idGroupState, TAG_IDLIB> groupStates;
    idList<idGroupState, TAG_IDLIB> layerStates;
    idList<idGroupState, TAG_IDLIB> groupColors;
};

class idRefMapDef {
public:
    idStr mapName;
    idStr worldSpawnText;
};

class idMapEntity : public idMapGroups {
public:
    ~idMapEntity() override = default;
    idDeclEntityDef* entityDef = nullptr;
    idMapModel model;
    idMapEntity* parentReference = nullptr;
    idStr refId;
    idList<idStr, TAG_IDLIB> layerList;
};

class alignas(4) idMapFile {
public:
    virtual ~idMapFile() = default;

    idStr name;
    int version = 0;
    unsigned int fileTime = 0;
    unsigned int geometryCRC = 0;
    bool hasPrimitiveData = false;
    idList<idMapEntity*, TAG_IDLIB> entities;
    idMapEditorStates groupStates;
    idList<idRefMapDef, TAG_IDLIB> referenceMaps;
    idMapEntity* parentReference = nullptr;
    bool expandReferences = false;
    idGame* game = nullptr;
    bool entitiesAreReference = false;
    bool ignoreGroupInfo = false;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idMapEditorStates) == 52,
    "Recovered idMapEditorStates ABI changed");
static_assert(sizeof(idMapEntity) == 124,
    "Recovered idMapEntity ABI changed");
static_assert(sizeof(idMapFile) == 152,
    "Recovered idMapFile ABI changed");
#endif
