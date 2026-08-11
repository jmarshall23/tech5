#pragma once

#include "../../../shared/idlib/containers/list.h"
#include "../../../shared/idlib/filesystem/file.h"
#include "../../../shared/idlib/text/str.h"

#include <cstdint>

class idCmdArgs;
class idDeclLayer;
class idEntity;
class idPlayer;
class idGameLayerManager;

enum layerState_t : int {
    LAYERSTATE_DEACTIVE = 0,
    LAYERSTATE_ACTIVE = 1
};

struct idEntityRetainedState {
    idEntityRetainedState();

    idStr entityName;
    int state;
    int targetState;
    std::uint64_t timeStarted;
    idEntity* entity;
};

struct idRetainedItemMemoryForMap {
    idStr mapName;
    idList<idStr, 5> itemsList;
};

class idLayer {
public:
    idLayer();
    idLayer(const char* declarationName, layerState_t state);

    const idStr& GetName() const { return layerDeclName; }

    idStr layerDeclName;
    layerState_t layerState;
};

// The retail translation unit reached these operations through gameLocal,
// the debug player, and declaration objects.  This interface keeps that
// engine-owned state outside the recovered manager while retaining the
// original ordering and queue transitions.
class idGameLayerManagerServices {
public:
    virtual ~idGameLayerManagerServices() = default;

    virtual const char* GetCurrentMapName() const { return nullptr; }
    virtual const char* GetDeclLayerName(const idDeclLayer*) const {
        return nullptr;
    }
    virtual idGameLayerManager* GetDebugLayerManager() const {
        return nullptr;
    }
    virtual int GetInitialActiveLayerCount() const { return 0; }
    virtual const char* GetInitialActiveLayerName(int) const {
        return nullptr;
    }
    virtual int GetInitialDeactiveLayerCount() const { return 0; }
    virtual const char* GetInitialDeactiveLayerName(int) const {
        return nullptr;
    }
    virtual int GetRuntimeActiveLayerCount() const { return 0; }
    virtual const char* GetRuntimeActiveLayerName(int) const {
        return nullptr;
    }
    virtual int GetRuntimeDeactiveLayerCount() const { return 0; }
    virtual const char* GetRuntimeDeactiveLayerName(int) const {
        return nullptr;
    }

    virtual void PrepareGameFlags() {}
    virtual void SpawnEntitiesForLayers(const idList<idStr, 5>&,
        bool, bool) {}
    virtual void RemoveEntitiesForLayers(const idList<idStr, 5>&,
        bool) {}
    virtual void MoveLayersFromActiveToDeactiveLists(
        const idList<idStr, 5>&) {}
    virtual void RemoveLayersFromActiveLayerList(
        const idList<idStr, 5>&) {}
    virtual void RemoveLayersFromLayerLists(const idList<idStr, 5>&) {}

    virtual void Print(const char*) const {}
    virtual void Warning(const char*) const {}
};

void Tungsten_SetGameLayerManagerServices(
    idGameLayerManagerServices* services);

class idGameLayerManager {
public:
    idGameLayerManager();
    ~idGameLayerManager();

    idEntityRetainedState* FindRetainedEntityState(const char* entityName);
    void PrintItemMemoryInfo();
    void WriteToFile(idFile* file) const;
    bool ContainsItemMemory(const char* itemName) const;
    static void GameLayerActiveItemMemories_f(const idCmdArgs& args);
    void PrintLayerInfo();
    void ClearLayers();
    static void GameLayerActiveLayers_f(const idCmdArgs& args);
    void RemoveLayerFromTransientLists(const char* layerName);

    bool ActivateDeactiveLayer(const char* layerName);
    void DeactivateActiveLayer(const char* layerName);
    void RemoveActiveLayer(const char* layerName);
    void RemoveActiveLayerFromMap(const char* layerName);
    void RemoveLayerMarkActiveNextMapLoad(const char* layerName);
    void RemoveLayerMarkDeactiveNextMapLoad(const char* layerName);

    void ActivateDeactiveLayers(
        const idList<const idDeclLayer*, 5>& layerList);
    void DeactiveateActiveLayers(
        const idList<const idDeclLayer*, 5>& layerList);
    void RemoveLayers(const idList<const idDeclLayer*, 5>& layerList);
    void RemoveLayersMarkActiveNextMapLoad(
        const idList<const idDeclLayer*, 5>& layerList);
    void RemoveLayersMarkDeactiveNextMapLoad(
        const idList<const idDeclLayer*, 5>& layerList);
    void RemoveLayersFromGame(
        const idList<const idDeclLayer*, 5>& layerList);

    void AddActiveLayer(const char* layerName);
    void AddDeactiveLayer(const char* layerName);
    void GetLayerStrings(idStr& activeLayerString,
        idStr& deactiveLayerString, bool propagateTheNextMapLayers);
    void Init(idPlayer* player, bool firstLoad);
    void Think();
    void AddActiveLayers(const idList<const idDeclLayer*, 5>& layerList);
    void AddDeactiveLayers(const idList<const idDeclLayer*, 5>& layerList);
    void ReadFromFile(idFile* file);
    void AddItemMemory(const char* itemName);

    const idList<idLayer, 5>& GetPlayerLayers() const { return playerLayers; }
    const idList<idStr, 5>& GetLayersToActivate() const {
        return layers_DeactiveToActive;
    }
    const idList<idStr, 5>& GetLayersToDeactivate() const {
        return layers_ActiveToDeactivate;
    }
    const idList<idStr, 5>& GetLayersToRemoveFromMap() const {
        return layers_ToRemove;
    }
    const idList<idStr, 5>& GetLayersToRemoveFromGame() const {
        return layers_ToRemoveFromGameLocalLists;
    }
    const idList<idStr, 5>& GetLayersToMarkActive() const {
        return layers_ToMarkActiveNextMapLoad;
    }
    const idList<idStr, 5>& GetLayersToMarkDeactive() const {
        return layers_ToMarkDeactiveNextMapLoad;
    }
    const idList<idRetainedItemMemoryForMap, 5>& GetItemMemories() const {
        return retainedItemMemoryForMap;
    }

    idList<idEntityRetainedState, 5> entityRetainedStates;
    idList<idRetainedItemMemoryForMap, 5> retainedItemMemoryForMap;
    idPlayer* owner;
    idList<idLayer, 5> playerLayers;
    idList<idStr, 5> layers_DeactiveToActive;
    idList<idStr, 5> layers_ActiveToDeactivate;
    idList<idStr, 5> layers_ToRemove;
    idList<idStr, 5> layers_ToRemoveFromGameLocalLists;
    idList<idStr, 5> layers_ToMarkActiveNextMapLoad;
    idList<idStr, 5> layers_ToMarkDeactiveNextMapLoad;
    bool inDebug;
    bool inInitState;

private:
    int FindLayerIndex(const char* layerName) const;
    void AppendUnique(idList<idStr, 5>& list, const char* layerName);
    void RemoveLayerAndQueue(const char* layerName,
        idList<idStr, 5>& destination);
    const char* DeclLayerName(const idDeclLayer* declaration) const;
};
