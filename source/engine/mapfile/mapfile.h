#pragma once

#include "mapfile/mapmodel.h"

class idDeclEntityDef;
class idGame;
class idLexer;
class idMapFile;

using mapEntityFilter_t = bool (*)(const idMapFile*, class idMapEntity*,
    idGame*);
using mapPrimitiveFilter_t = bool (*)(idMapPrimitive*, idGame*);
using mapMaterialToolsFlagsResolver_t = unsigned int (*)(const char* material);

class idGroupState {
public:
    bool operator==(const idGroupState& other) const;

    idStr groupName;
    unsigned int state;
};

class idMapEditorStates {
public:
    idMapEditorStates();
    virtual ~idMapEditorStates();

    void Parse(idLexer& lexer);
    void Write(idFile* file) const;

    idList<idGroupState, TAG_IDLIB> groupStates;
    idList<idGroupState, TAG_IDLIB> layerStates;
    idList<idGroupState, TAG_IDLIB> groupColors;
};

class idRefMapDef {
public:
    idRefMapDef() = default;
    idRefMapDef(const char* name, const char* entityText);
    bool operator==(const idRefMapDef& other) const;

    idStr mapName;
    idStr worldSpawnText;
};

class idMapEntity : public idMapGroups {
public:
    idMapEntity();
    ~idMapEntity() override;

    void SetEntityDef(idDeclEntityDef* definition);
    void ClearLayerList();
    void Transform(const idVec3& origin, const idMat3& axis);
    void FixMapModelNames(const char* mapName, const char* entityName);
    void FixTargetNames(const char* baseName);
    bool Write(idFile* file, idGame* game, int entityNumber,
        mapPrimitiveFilter_t shouldWritePrimitive,
        bool entitiesFile) const;

    static idMapEntity* Parse(idMapFile* mapFile, idLexer& lexer,
        int version, idMapEntity* parent);

    idDeclEntityDef* entityDef;
    idMapModel model;
    idMapEntity* parentReference;
    idStr refId;
    idList<idStr, TAG_IDLIB> layerList;
};

class idMapReference : public idMapPrimitive {
public:
    idMapReference();
    ~idMapReference() override;

    unsigned int GetGeometryCRC() const override;
    void Transform(const idVec3&, const idMat3&) override {}
    bool Write(idFile* file, int referenceNumber) const override;

    void ExpandReference(idMapFile* destination, idMapEntity* mapEntity);
    static idMapReference* Parse(idLexer& lexer, int version,
        bool expandReferences, idMapEntity* parent);

    idStr mapName;
    idStr worldSpawnText;
    idMapFile* map;
};

class alignas(4) idMapFile {
public:
    idMapFile();
    virtual ~idMapFile();

    static idStr GetMapModelName(const char* mapName,
        const char* entityName);

    int GetNumEntities() const { return entities.Num(); }
    idMapEntity* GetEntity(int index) const;
    idMapEntity* FindEntity(const char* entityName,
        int* index = nullptr) const;
    int FindReferenceMap(const char* mapName) const;
    int AddEntity(idMapEntity* mapEntity);
    void RemoveEntity(idMapEntity* mapEntity);
    void AddReferenceMap(const char* mapName, const char* worldSpawnText);

    idStr CopyMapEntities(const idMapFile* source, const char* referenceId);
    void ClearCopiedEntities(const idStr& referenceName);

    bool Parse(const char* fileName, bool osPath = false,
        idMapEntity* parent = nullptr);
    bool Reload();
    bool Write(const char* fileName, bool osPath = false);
    bool WriteSounds(const char* fileName, bool osPath = false);
    bool WriteEntities(const char* fileName, bool osPath = false);

    void SetGeometryCRC();
    bool ParseSingle(idLexer& lexer);
    void ConvertMapModelNames();
    void WriteInternal(idFile* file, bool entitiesFile,
        mapEntityFilter_t shouldWriteEntity,
        mapPrimitiveFilter_t shouldWritePrimitive) const;
    bool WriteInternal(const char* path, bool osPath, bool entitiesFile,
        mapEntityFilter_t shouldWriteEntity,
        mapPrimitiveFilter_t shouldWritePrimitive) const;

    idStr name;
    int version;
    unsigned int fileTime;
    unsigned int geometryCRC;
    bool hasPrimitiveData;
    idList<idMapEntity*, TAG_IDLIB> entities;
    idMapEditorStates groupStates;
    idList<idRefMapDef, TAG_IDLIB> referenceMaps;
    idMapEntity* parentReference;
    bool expandReferences;
    idGame* game;
    bool entitiesAreReference;
    bool ignoreGroupInfo;
};

bool IsSoundEntity(const idMapFile* mapFile, idMapEntity* entity,
    idGame* game);
bool IsNotSoundEntity(const idMapFile* mapFile, idMapEntity* entity,
    idGame* game);
bool IsSoundPrimitive(idMapPrimitive* primitive, idGame* game);
bool IsNotSoundPrimitive(idMapPrimitive* primitive, idGame* game);
bool IsProductionEntity(const idMapFile* mapFile, idMapEntity* entity,
    idGame* game);
bool WriteAllMapPrimitives(idMapPrimitive* primitive, idGame* game);

void SetMapMaterialToolsFlagsResolver(
    mapMaterialToolsFlagsResolver_t resolver);
void SetMapProductionEntityFilter(mapEntityFilter_t filter);

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idMapEditorStates) == 52,
    "Recovered idMapEditorStates ABI changed");
static_assert(sizeof(idMapEntity) == 124,
    "Recovered idMapEntity ABI changed");
static_assert(sizeof(idMapReference) == 92,
    "Recovered idMapReference ABI changed");
static_assert(sizeof(idMapFile) == 152,
    "Recovered idMapFile ABI changed");
#endif
