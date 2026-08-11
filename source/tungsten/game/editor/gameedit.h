#pragma once

#include "game/entities/entityptr.h"
#include "idlib/bv/bounds.h"
#include "idlib/color.h"
#include "idlib/containers/list.h"
#include "idlib/text/str.h"

class idEntity;
class idPlayer;
class idTypeInfo;
class idDragEntity;
class idEditEntities;

struct idSelectedTypeInfo {
    idSelectedTypeInfo()
        : typeInfo(nullptr)
        , typeKey()
        , textKey()
        , entityMustExistInMapFile(false) {
    }

    const idTypeInfo* typeInfo;
    idStr typeKey;
    idStr textKey;
    bool entityMustExistInMapFile;
};

class idGameEditServices {
public:
    virtual ~idGameEditServices() = default;

    virtual int GetGameMilliseconds() const { return 0; }
    virtual int GetEditorMode() const { return 0; }
    virtual bool MouseDragEnabled() const { return false; }
    virtual int GetGridSize() const { return 0; }
    virtual float GetCloneDistance() const { return 128.0f; }
    virtual void GetSpawnedEntities(idList<idEntity*, 5>&) {}
    virtual bool GetEntityOrigin(idEntity*, idVec3& origin) {
        origin.Zero();
        return false;
    }
    virtual bool GetEntityBounds(idEntity*, idBounds&) { return false; }
    virtual void SetEntityOrigin(idEntity*, const idVec3&) {}
    virtual void UpdateEntityMap(idEntity*) {}
    virtual void SetEntitySelected(idEntity*, bool) {}
    virtual bool IsEntityInMap(idEntity*) const { return false; }
    virtual bool IsEntityType(idEntity*, const idTypeInfo*) const {
        return false;
    }
    virtual void ShowEditingDialog(idEntity*) {}
    virtual void UpdateEditingDialog(idEntity*) {}
    virtual void UpdateParticleTool() {}
    virtual void PrintSelectedEntity(idEntity*) {}
    virtual void PopulateSelectableEntityClasses(
        idList<idSelectedTypeInfo, 5>&) {}
    virtual void DisplayEntities(idEditEntities*) {}
    virtual idEntity* DuplicateEntity(idEntity*, const idVec3&,
        const idVec3&, float) { return nullptr; }
    virtual void UpdateDragEntity(idDragEntity*, idPlayer*) {}
    virtual void DeleteSpawnEntity(int) {}
};

class idDragEntity {
public:
    idDragEntity();

    static void SetServices(idGameEditServices* services);
    static idGameEditServices& Services();

    void Update(idPlayer* player);
    void DeleteSelected();

    idEntityPtr<idEntity> selected;
    int physicsId;
    int bodyId;
    idVec3 localPhysicsPoint;
    idVec3 localPlayerPoint;
};

class idEditEntities {
public:
    idEditEntities();

    static void SetServices(idGameEditServices* services) {
        idDragEntity::SetServices(services);
    }
    static idGameEditServices& Services() {
        return idDragEntity::Services();
    }

    bool ZoomEntity(const idVec3& cameraPosition, bool push);
    void ResetDragging();
    void EditSelected();
    void RemoveSelectedEntity(idEntity* entity);
    void ClearSelectedEntities();
    bool EntityIsSelectable(idEntity* entity, idVec4* color = nullptr,
        idStr* text = nullptr, idStr* type = nullptr);
    idEntity* FindEntity(const idVec3& origin, const idVec3& direction,
        const idEntity* skip);
    bool UpdateSelected(const idVec3& origin, const idVec3& direction,
        const idEntity* skip);
    void AddSelectedEntity(idEntity* entity);
    void DisplayEntities();
    bool SelectEntity(const idVec3& origin, const idVec3& direction,
        const idEntity* skip);
    void DuplicateSelected(const idVec3& origin, const idVec3& direction);

    int nextSelectTime;
    bool lastSelectResult;
    idList<idSelectedTypeInfo, 5> selectableEntityClasses;
    idList<idEntity*, 5> selectedEntities;
    bool dragging;
    int dragTime;
    int dragAxis;
    idVec3 lastViewDir;
    idVec3 lastDragPos;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idSelectedTypeInfo) == 72,
    "Recovered selectable editor-entity type ABI changed");
static_assert(sizeof(idDragEntity) == 36,
    "Recovered drag-entity ABI changed");
#endif
