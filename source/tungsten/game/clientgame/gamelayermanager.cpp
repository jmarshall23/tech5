#include "gamelayermanager.h"

#include <algorithm>
#include <cstdarg>
#include <cstdio>

namespace {
idGameLayerManagerServices* g_gameLayerServices = nullptr;

void OutputFormatted(const bool warning, const char* format, ...) {
    if (g_gameLayerServices == nullptr) return;
    char message[2048];
    va_list arguments;
    va_start(arguments, format);
    _vsnprintf_s(message, sizeof(message), _TRUNCATE, format, arguments);
    va_end(arguments);
    if (warning) g_gameLayerServices->Warning(message);
    else g_gameLayerServices->Print(message);
}

bool IsValidCount(const int count) {
    // Save counts are authored by the game and normally tiny.  Keep damaged
    // files from turning a four-byte value into an unbounded allocation.
    return count >= 0 && count <= 1024 * 1024;
}
} // namespace

void Tungsten_SetGameLayerManagerServices(
        idGameLayerManagerServices* const services) {
    g_gameLayerServices = services;
}

idEntityRetainedState::idEntityRetainedState()
    : entityName(), state(-1), targetState(-1), timeStarted(0),
      entity(nullptr) {}

idLayer::idLayer()
    : layerDeclName(), layerState(LAYERSTATE_DEACTIVE) {}

idLayer::idLayer(const char* const declarationName,
        const layerState_t state)
    : layerDeclName(declarationName), layerState(state) {}

// Retail symbol: ?FindRetainedEntityState@idGameLayerManager@@QAAPAVidEntityRetainedState@@PBD@Z
// EA: 0x82B5CF00, RVA: 0x00B5CF00
idEntityRetainedState* idGameLayerManager::FindRetainedEntityState(
        const char* const entityName) {
    for (int index = 0; index < entityRetainedStates.Num(); ++index) {
        if (idStr::Cmp(entityRetainedStates[index].entityName.c_str(),
                entityName) == 0) {
            return &entityRetainedStates[index];
        }
    }
    return nullptr;
}

// Retail symbol: ?PrintItemMemoryInfo@idGameLayerManager@@QAAXXZ
// EA: 0x82B5CF78, RVA: 0x00B5CF78
void idGameLayerManager::PrintItemMemoryInfo() {
    for (int mapIndex = 0; mapIndex < retainedItemMemoryForMap.Num();
            ++mapIndex) {
        const idRetainedItemMemoryForMap& memory =
            retainedItemMemoryForMap[mapIndex];
        OutputFormatted(true, "%d: %s", mapIndex, memory.mapName.c_str());
        for (int itemIndex = 0; itemIndex < memory.itemsList.Num();
                ++itemIndex) {
            OutputFormatted(false, "%d: \t%d: %s\n", mapIndex, itemIndex,
                memory.itemsList[itemIndex].c_str());
        }
    }
}

// Retail symbol: ?WriteToFile@idGameLayerManager@@QBAXPAVidFile@@@Z
// EA: 0x82B5D198, RVA: 0x00B5D198
void idGameLayerManager::WriteToFile(idFile* const file) const {
    if (file == nullptr) return;

    file->WriteLittle(playerLayers.num);
    for (int index = 0; index < playerLayers.Num(); ++index) {
        file->WriteString(playerLayers[index].layerDeclName);
        const int state = static_cast<int>(playerLayers[index].layerState);
        file->WriteLittle(state);
    }

    file->WriteLittle(layers_ToMarkActiveNextMapLoad.num);
    for (int index = 0; index < layers_ToMarkActiveNextMapLoad.Num();
            ++index) {
        file->WriteString(layers_ToMarkActiveNextMapLoad[index]);
    }
    file->WriteLittle(layers_ToMarkDeactiveNextMapLoad.num);
    for (int index = 0; index < layers_ToMarkDeactiveNextMapLoad.Num();
            ++index) {
        file->WriteString(layers_ToMarkDeactiveNextMapLoad[index]);
    }

    file->WriteLittle(entityRetainedStates.num);
    for (int index = 0; index < entityRetainedStates.Num(); ++index) {
        const idEntityRetainedState& retained = entityRetainedStates[index];
        file->WriteString(retained.entityName);
        file->WriteLittle(retained.state);
        file->WriteLittle(retained.targetState);
        file->WriteLittle(retained.timeStarted);
    }

    file->WriteLittle(retainedItemMemoryForMap.num);
    for (int mapIndex = 0; mapIndex < retainedItemMemoryForMap.Num();
            ++mapIndex) {
        const idRetainedItemMemoryForMap& memory =
            retainedItemMemoryForMap[mapIndex];
        file->WriteString(memory.mapName);
        file->WriteLittle(memory.itemsList.num);
        for (int itemIndex = 0; itemIndex < memory.itemsList.Num();
                ++itemIndex) {
            file->WriteString(memory.itemsList[itemIndex]);
        }
    }
}

// Retail symbol: ?ContainsItemMemory@idGameLayerManager@@QBA_NPBD@Z
// EA: 0x82B5D6A0, RVA: 0x00B5D6A0
bool idGameLayerManager::ContainsItemMemory(
        const char* const itemName) const {
    if (g_gameLayerServices == nullptr || itemName == nullptr) return false;
    const char* const mapName = g_gameLayerServices->GetCurrentMapName();
    if (mapName == nullptr) return false;
    for (int mapIndex = 0; mapIndex < retainedItemMemoryForMap.Num();
            ++mapIndex) {
        const idRetainedItemMemoryForMap& memory =
            retainedItemMemoryForMap[mapIndex];
        if (idStr::Icmp(memory.mapName.c_str(), mapName) != 0) continue;
        for (int itemIndex = 0; itemIndex < memory.itemsList.Num();
                ++itemIndex) {
            if (idStr::Icmp(memory.itemsList[itemIndex].c_str(), itemName)
                    == 0) return true;
        }
        return false;
    }
    return false;
}

// Retail symbol: ?GameLayerActiveItemMemories_f@idGameLayerManager@@SAXABVidCmdArgs@@@Z
// EA: 0x82B5D7D8, RVA: 0x00B5D7D8
void idGameLayerManager::GameLayerActiveItemMemories_f(
        const idCmdArgs&) {
    OutputFormatted(true, "Active item memories in the game layer manager:");
    if (g_gameLayerServices != nullptr) {
        idGameLayerManager* const manager =
            g_gameLayerServices->GetDebugLayerManager();
        if (manager != nullptr) manager->PrintItemMemoryInfo();
    }
    OutputFormatted(true, "---");
}

// Retail symbol: ?PrintLayerInfo@idGameLayerManager@@QAAXXZ
// EA: 0x82B5D840, RVA: 0x00B5D840
void idGameLayerManager::PrintLayerInfo() {
    if (g_gameLayerServices == nullptr ||
            g_gameLayerServices->GetDebugLayerManager() == nullptr) return;
    for (int index = 0; index < playerLayers.Num(); ++index) {
        OutputFormatted(false,
            playerLayers[index].layerState == LAYERSTATE_ACTIVE
                ? "\t%d: %s\n" : "^5\t%d: %s\n",
            index, playerLayers[index].GetName().c_str());
    }
}

// Retail symbol: ?ClearLayers@idGameLayerManager@@QAAXXZ
// EA: 0x82B5DBA0, RVA: 0x00B5DBA0
void idGameLayerManager::ClearLayers() {
    playerLayers.ClearFree();
    layers_DeactiveToActive.ClearFree();
    layers_ActiveToDeactivate.ClearFree();
    layers_ToRemove.ClearFree();
    layers_ToRemoveFromGameLocalLists.ClearFree();
}

// Retail symbol: ?GameLayerActiveLayers_f@idGameLayerManager@@SAXABVidCmdArgs@@@Z
// EA: 0x82B5DCD8, RVA: 0x00B5DCD8
void idGameLayerManager::GameLayerActiveLayers_f(const idCmdArgs&) {
    OutputFormatted(true, "Active Layers in the game layer manager:");
    if (g_gameLayerServices != nullptr) {
        idGameLayerManager* const manager =
            g_gameLayerServices->GetDebugLayerManager();
        if (manager != nullptr) manager->PrintLayerInfo();
    }
    OutputFormatted(true, "---");
    OutputFormatted(true, "Deactive Layers in the current map:");
    if (g_gameLayerServices != nullptr) {
        for (int index = 0;
                index < g_gameLayerServices->GetRuntimeDeactiveLayerCount();
                ++index) {
            OutputFormatted(false, "\t%d: %s\n", index,
                g_gameLayerServices->GetRuntimeDeactiveLayerName(index));
        }
    }
    OutputFormatted(true, "---");
    OutputFormatted(true, "Active Layers in the current map:");
    if (g_gameLayerServices != nullptr) {
        for (int index = 0;
                index < g_gameLayerServices->GetRuntimeActiveLayerCount();
                ++index) {
            OutputFormatted(false, "\t%d: %s\n", index,
                g_gameLayerServices->GetRuntimeActiveLayerName(index));
        }
    }
}

// Retail symbol: ?RemoveLayerFromTransientLists@idGameLayerManager@@QAAXPBD@Z
// EA: 0x82B5E278, RVA: 0x00B5E278
void idGameLayerManager::RemoveLayerFromTransientLists(
        const char* const layerName) {
    const idStr name(layerName);
    idList<idStr, 5>* const lists[] = {
        &layers_DeactiveToActive, &layers_ActiveToDeactivate,
        &layers_ToRemove, &layers_ToRemoveFromGameLocalLists,
        &layers_ToMarkActiveNextMapLoad,
        &layers_ToMarkDeactiveNextMapLoad
    };
    for (idList<idStr, 5>* const list : lists) {
        const int index = list->FindIndex(name);
        if (index >= 0) list->RemoveIndex(index);
    }
}

int idGameLayerManager::FindLayerIndex(const char* const layerName) const {
    for (int index = 0; index < playerLayers.Num(); ++index) {
        if (idStr::Icmp(playerLayers[index].layerDeclName.c_str(),
                layerName) == 0) return index;
    }
    return -1;
}

void idGameLayerManager::AppendUnique(idList<idStr, 5>& list,
        const char* const layerName) {
    const idStr name(layerName);
    if (list.FindIndex(name) < 0) list.Append(name);
}

void idGameLayerManager::RemoveLayerAndQueue(const char* const layerName,
        idList<idStr, 5>& destination) {
    const int index = FindLayerIndex(layerName);
    if (index >= 0) playerLayers.RemoveIndex(index);
    RemoveLayerFromTransientLists(layerName);
    AppendUnique(destination, layerName);
}

// Retail symbol: ?ActivateDeactiveLayer@idGameLayerManager@@QAA_NPBD@Z
// EA: 0x82B5E4F8, RVA: 0x00B5E4F8
bool idGameLayerManager::ActivateDeactiveLayer(
        const char* const layerName) {
    const int index = FindLayerIndex(layerName);
    if (index < 0) {
        OutputFormatted(false, "idGameLayerManager::ActivateDeactiveLayer "
            "not activating %s because it is not on the player\n", layerName);
        return false;
    }
    if (playerLayers[index].layerState == LAYERSTATE_ACTIVE) {
        OutputFormatted(false, "idGameLayerManager::ActivateDeactiveLayer "
            "not activating %s because it is already active\n", layerName);
        return false;
    }
    playerLayers[index].layerState = LAYERSTATE_ACTIVE;
    RemoveLayerFromTransientLists(layerName);
    AppendUnique(layers_DeactiveToActive, layerName);
    return true;
}

// Retail compiler cleanup $M491970 at EA 0x82B5E640 is represented by
// ordinary idStr automatic-storage destruction in ActivateDeactiveLayer.

// Retail symbol: ?DeactivateActiveLayer@idGameLayerManager@@QAAXPBD@Z
// EA: 0x82B5E698, RVA: 0x00B5E698
void idGameLayerManager::DeactivateActiveLayer(
        const char* const layerName) {
    const int index = FindLayerIndex(layerName);
    if (index < 0) {
        OutputFormatted(false, "idGameLayerManager::DeactivateActiveLayer "
            "not deactivating %s because it is not on the player\n", layerName);
    } else if (playerLayers[index].layerState == LAYERSTATE_ACTIVE) {
        playerLayers[index].layerState = LAYERSTATE_DEACTIVE;
    } else {
        OutputFormatted(false, "idGameLayerManager::DeactivateActiveLayer "
            "not deactivating %s because it is not active\n", layerName);
    }
    RemoveLayerFromTransientLists(layerName);
    AppendUnique(layers_ActiveToDeactivate, layerName);
}

// Retail symbol: ?RemoveActiveLayer@idGameLayerManager@@QAAXPBD@Z
// EA: 0x82B5E840, RVA: 0x00B5E840
void idGameLayerManager::RemoveActiveLayer(const char* const layerName) {
    RemoveLayerAndQueue(layerName, layers_ToRemoveFromGameLocalLists);
}

// Retail symbol: ?RemoveActiveLayerFromMap@idGameLayerManager@@QAAXPBD@Z
// EA: 0x82B5E970, RVA: 0x00B5E970
void idGameLayerManager::RemoveActiveLayerFromMap(
        const char* const layerName) {
    RemoveLayerAndQueue(layerName, layers_ToRemove);
}

// Retail symbol: ?RemoveLayerMarkActiveNextMapLoad@idGameLayerManager@@QAAXPBD@Z
// EA: 0x82B5EAA0, RVA: 0x00B5EAA0
void idGameLayerManager::RemoveLayerMarkActiveNextMapLoad(
        const char* const layerName) {
    RemoveLayerAndQueue(layerName, layers_ToRemoveFromGameLocalLists);
    AppendUnique(layers_ToMarkActiveNextMapLoad, layerName);
}

// Retail symbol: ?RemoveLayerMarkDeactiveNextMapLoad@idGameLayerManager@@QAAXPBD@Z
// EA: 0x82B5EC38, RVA: 0x00B5EC38
void idGameLayerManager::RemoveLayerMarkDeactiveNextMapLoad(
        const char* const layerName) {
    RemoveLayerAndQueue(layerName, layers_ToRemoveFromGameLocalLists);
    AppendUnique(layers_ToMarkDeactiveNextMapLoad, layerName);
}

// Retail symbol: ??0idGameLayerManager@@QAA@XZ
// EA: 0x82B5F010, RVA: 0x00B5F010
idGameLayerManager::idGameLayerManager()
    : entityRetainedStates(), retainedItemMemoryForMap(), owner(nullptr),
      playerLayers(), layers_DeactiveToActive(),
      layers_ActiveToDeactivate(), layers_ToRemove(),
      layers_ToRemoveFromGameLocalLists(),
      layers_ToMarkActiveNextMapLoad(),
      layers_ToMarkDeactiveNextMapLoad(), inDebug(false),
      inInitState(false) {}

// Retail symbol: ??1idGameLayerManager@@QAA@XZ
// EA: 0x82B5F2B8, RVA: 0x00B5F2B8
idGameLayerManager::~idGameLayerManager() {
    ClearLayers();
}

const char* idGameLayerManager::DeclLayerName(
        const idDeclLayer* const declaration) const {
    return declaration != nullptr && g_gameLayerServices != nullptr
        ? g_gameLayerServices->GetDeclLayerName(declaration) : nullptr;
}

// Retail symbol: ?ActivateDeactiveLayers@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA: 0x82B5F648, RVA: 0x00B5F648
void idGameLayerManager::ActivateDeactiveLayers(
        const idList<const idDeclLayer*, 5>& layerList) {
    for (int index = 0; index < layerList.Num(); ++index) {
        const char* const name = DeclLayerName(layerList[index]);
        if (name != nullptr) ActivateDeactiveLayer(name);
        else OutputFormatted(true, "NULL layerDecl");
    }
}

// Retail compiler cleanup $M493228_0 at EA 0x82B5F80C is represented by
// ordinary idStr automatic-storage destruction in ActivateDeactiveLayers.

// Retail symbol: ?DeactiveateActiveLayers@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA: 0x82B5F868, RVA: 0x00B5F868
void idGameLayerManager::DeactiveateActiveLayers(
        const idList<const idDeclLayer*, 5>& layerList) {
    for (int index = 0; index < layerList.Num(); ++index) {
        const char* const name = DeclLayerName(layerList[index]);
        if (name != nullptr) DeactivateActiveLayer(name);
        else OutputFormatted(true, "NULL layerDecl");
    }
}

// Retail symbol: ?RemoveLayers@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA: 0x82B5FA90, RVA: 0x00B5FA90
void idGameLayerManager::RemoveLayers(
        const idList<const idDeclLayer*, 5>& layerList) {
    for (int index = 0; index < layerList.Num(); ++index) {
        const char* const name = DeclLayerName(layerList[index]);
        if (name != nullptr) RemoveActiveLayer(name);
        else OutputFormatted(true, "NULL layerDecl");
    }
}

// Retail symbol: ?RemoveLayersMarkActiveNextMapLoad@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA: 0x82B5FC38, RVA: 0x00B5FC38
void idGameLayerManager::RemoveLayersMarkActiveNextMapLoad(
        const idList<const idDeclLayer*, 5>& layerList) {
    for (int index = 0; index < layerList.Num(); ++index) {
        const char* const name = DeclLayerName(layerList[index]);
        if (name != nullptr) RemoveLayerMarkActiveNextMapLoad(name);
        else OutputFormatted(true, "NULL layerDecl");
    }
}

// Retail symbol: ?RemoveLayersMarkDeactiveNextMapLoad@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA: 0x82B5FE48, RVA: 0x00B5FE48
void idGameLayerManager::RemoveLayersMarkDeactiveNextMapLoad(
        const idList<const idDeclLayer*, 5>& layerList) {
    for (int index = 0; index < layerList.Num(); ++index) {
        const char* const name = DeclLayerName(layerList[index]);
        if (name != nullptr) RemoveLayerMarkDeactiveNextMapLoad(name);
        else OutputFormatted(true, "NULL layerDecl");
    }
}

// Retail symbol: ?RemoveLayersFromGame@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA: 0x82B60058, RVA: 0x00B60058
void idGameLayerManager::RemoveLayersFromGame(
        const idList<const idDeclLayer*, 5>& layerList) {
    for (int index = 0; index < layerList.Num(); ++index) {
        const char* const name = DeclLayerName(layerList[index]);
        if (name != nullptr) RemoveActiveLayerFromMap(name);
        else OutputFormatted(true, "NULL layerDecl");
    }
}

// Retail symbol: ?AddActiveLayer@idGameLayerManager@@QAAXPBD@Z
// EA: 0x82B60200, RVA: 0x00B60200
void idGameLayerManager::AddActiveLayer(const char* const layerName) {
    const int index = FindLayerIndex(layerName);
    if (index < 0) {
        playerLayers.Append(idLayer(layerName, LAYERSTATE_ACTIVE));
    } else {
        if (playerLayers[index].layerState == LAYERSTATE_ACTIVE) {
            OutputFormatted(true, "idLayer SetState for %s, already %d",
                playerLayers[index].layerDeclName.c_str(), 1);
        }
        playerLayers[index].layerState = LAYERSTATE_ACTIVE;
    }
    RemoveLayerFromTransientLists(layerName);
    AppendUnique(layers_DeactiveToActive, layerName);
}

// Retail symbol: ?AddDeactiveLayer@idGameLayerManager@@QAAXPBD@Z
// EA: 0x82B604A8, RVA: 0x00B604A8
void idGameLayerManager::AddDeactiveLayer(const char* const layerName) {
    const int index = FindLayerIndex(layerName);
    if (index < 0) {
        playerLayers.Append(idLayer(layerName, LAYERSTATE_DEACTIVE));
    } else {
        if (playerLayers[index].layerState == LAYERSTATE_DEACTIVE) {
            OutputFormatted(true, "idLayer SetState for %s, already %d",
                playerLayers[index].layerDeclName.c_str(), 0);
        }
        playerLayers[index].layerState = LAYERSTATE_DEACTIVE;
    }
    RemoveLayerFromTransientLists(layerName);
}

// Retail symbol: ?GetLayerStrings@idGameLayerManager@@QAAXAAVidStr@@0_N@Z
// EA: 0x82B606F0, RVA: 0x00B606F0
void idGameLayerManager::GetLayerStrings(idStr& activeLayerString,
        idStr& deactiveLayerString, const bool propagateTheNextMapLayers) {
    if (propagateTheNextMapLayers) {
        for (int index = 0; index < layers_ToMarkActiveNextMapLoad.Num();
                ++index) {
            const char* const name =
                layers_ToMarkActiveNextMapLoad[index].c_str();
            const int existing = FindLayerIndex(name);
            if (existing < 0) {
                playerLayers.Append(idLayer(name, LAYERSTATE_ACTIVE));
            } else {
                playerLayers[existing].layerState = LAYERSTATE_ACTIVE;
            }
        }
        layers_ToMarkActiveNextMapLoad.ClearFree();
        for (int index = 0; index < layers_ToMarkDeactiveNextMapLoad.Num();
                ++index) {
            const char* const name =
                layers_ToMarkDeactiveNextMapLoad[index].c_str();
            const int existing = FindLayerIndex(name);
            if (existing < 0) {
                playerLayers.Append(idLayer(name, LAYERSTATE_DEACTIVE));
            } else {
                playerLayers[existing].layerState = LAYERSTATE_DEACTIVE;
            }
        }
        layers_ToMarkDeactiveNextMapLoad.ClearFree();
    }

    if (playerLayers.Num() > 1) {
        std::sort(playerLayers.Ptr(), playerLayers.Ptr() + playerLayers.Num(),
            [](const idLayer& left, const idLayer& right) {
                return idStr::Icmp(left.layerDeclName.c_str(),
                    right.layerDeclName.c_str()) < 0;
            });
    }
    activeLayerString.Clear();
    deactiveLayerString.Clear();
    for (int index = 0; index < playerLayers.Num(); ++index) {
        idStr& output = playerLayers[index].layerState == LAYERSTATE_ACTIVE
            ? activeLayerString : deactiveLayerString;
        if (!output.IsEmpty()) output.Append(",");
        output.Append(playerLayers[index].GetName());
    }
}

// Retail symbol: ?Init@idGameLayerManager@@QAAXPAVidPlayer@@_N@Z
// EA: 0x82B61280, RVA: 0x00B61280
void idGameLayerManager::Init(idPlayer* const player,
        const bool firstLoad) {
    owner = player;
    if (g_gameLayerServices != nullptr) {
        g_gameLayerServices->PrepareGameFlags();
        if (firstLoad) {
            for (int index = 0;
                    index < g_gameLayerServices->GetInitialActiveLayerCount();
                    ++index) {
                const char* const name =
                    g_gameLayerServices->GetInitialActiveLayerName(index);
                if (name != nullptr && name[0] != '\0') AddActiveLayer(name);
            }
            for (int index = 0;
                    index < g_gameLayerServices->GetInitialDeactiveLayerCount();
                    ++index) {
                const char* const name =
                    g_gameLayerServices->GetInitialDeactiveLayerName(index);
                if (name != nullptr && name[0] != '\0') AddDeactiveLayer(name);
            }
        }
    }
    layers_DeactiveToActive.ClearFree();
    layers_ActiveToDeactivate.ClearFree();
    layers_ToRemove.ClearFree();
    layers_ToRemoveFromGameLocalLists.ClearFree();
}

// Retail symbol: ?Think@idGameLayerManager@@QAAXXZ
// EA: 0x82B616E0, RVA: 0x00B616E0
void idGameLayerManager::Think() {
    if (g_gameLayerServices == nullptr) return;
    if (!layers_DeactiveToActive.IsEmpty()) {
        g_gameLayerServices->SpawnEntitiesForLayers(
            layers_DeactiveToActive, false, false);
        layers_DeactiveToActive.ClearFree();
    }
    if (!layers_ActiveToDeactivate.IsEmpty()) {
        g_gameLayerServices->RemoveEntitiesForLayers(
            layers_ActiveToDeactivate, false);
        g_gameLayerServices->MoveLayersFromActiveToDeactiveLists(
            layers_ActiveToDeactivate);
        layers_ActiveToDeactivate.ClearFree();
    }
    if (!layers_ToRemove.IsEmpty()) {
        g_gameLayerServices->RemoveEntitiesForLayers(
            layers_ToRemove, false);
        g_gameLayerServices->RemoveLayersFromActiveLayerList(layers_ToRemove);
        layers_ToRemove.ClearFree();
    }
    if (!layers_ToRemoveFromGameLocalLists.IsEmpty()) {
        g_gameLayerServices->RemoveLayersFromLayerLists(
            layers_ToRemoveFromGameLocalLists);
        layers_ToRemoveFromGameLocalLists.ClearFree();
    }
}

// Retail symbol: ?AddActiveLayers@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA: 0x82B61850, RVA: 0x00B61850
void idGameLayerManager::AddActiveLayers(
        const idList<const idDeclLayer*, 5>& layerList) {
    for (int index = 0; index < layerList.Num(); ++index) {
        const char* const name = DeclLayerName(layerList[index]);
        if (name != nullptr) AddActiveLayer(name);
        else OutputFormatted(true, "NULL layerDecl");
    }
}

// Retail symbol: ?AddDeactiveLayers@idGameLayerManager@@QAAXABV?$idList@PBVidDeclLayer@@$04@@@Z
// EA: 0x82B61D28, RVA: 0x00B61D28
void idGameLayerManager::AddDeactiveLayers(
        const idList<const idDeclLayer*, 5>& layerList) {
    for (int index = 0; index < layerList.Num(); ++index) {
        const char* const name = DeclLayerName(layerList[index]);
        if (name != nullptr) AddDeactiveLayer(name);
        else OutputFormatted(true, "NULL layerDecl");
    }
}

// Retail symbol: ?ReadFromFile@idGameLayerManager@@QAAXPAVidFile@@@Z
// EA: 0x82B623D0, RVA: 0x00B623D0
void idGameLayerManager::ReadFromFile(idFile* const file) {
    if (file == nullptr) return;
    ClearLayers();

    int count = 0;
    file->ReadLittle(count);
    if (!IsValidCount(count) || !playerLayers.SetNum(count)) return;
    for (int index = 0; index < count; ++index) {
        file->ReadString(playerLayers[index].layerDeclName);
        int state = 0;
        file->ReadLittle(state);
        playerLayers[index].layerState = state == LAYERSTATE_ACTIVE
            ? LAYERSTATE_ACTIVE : LAYERSTATE_DEACTIVE;
        OutputFormatted(false, "Read Layer From File %d %s\n", state,
            playerLayers[index].layerDeclName.c_str());
    }

    file->ReadLittle(count);
    if (!IsValidCount(count) ||
            !layers_ToMarkActiveNextMapLoad.SetNum(count)) return;
    for (int index = 0; index < count; ++index)
        file->ReadString(layers_ToMarkActiveNextMapLoad[index]);

    file->ReadLittle(count);
    if (!IsValidCount(count) ||
            !layers_ToMarkDeactiveNextMapLoad.SetNum(count)) return;
    for (int index = 0; index < count; ++index)
        file->ReadString(layers_ToMarkDeactiveNextMapLoad[index]);

    file->ReadLittle(count);
    if (!IsValidCount(count)) return;
    for (int index = 0; index < count; ++index) {
        idEntityRetainedState retained;
        file->ReadString(retained.entityName);
        file->ReadLittle(retained.state);
        file->ReadLittle(retained.targetState);
        file->ReadLittle(retained.timeStarted);
        entityRetainedStates.Append(retained);
    }

    file->ReadLittle(count);
    if (!IsValidCount(count)) return;
    for (int mapIndex = 0; mapIndex < count; ++mapIndex) {
        idRetainedItemMemoryForMap memory;
        file->ReadString(memory.mapName);
        int itemCount = 0;
        file->ReadLittle(itemCount);
        if (!IsValidCount(itemCount) || !memory.itemsList.SetNum(itemCount))
            return;
        for (int itemIndex = 0; itemIndex < itemCount; ++itemIndex)
            file->ReadString(memory.itemsList[itemIndex]);
        retainedItemMemoryForMap.Append(memory);
    }
}

// Retail symbol: ?AddItemMemory@idGameLayerManager@@QAAXPBD@Z
// EA: 0x82B628D0, RVA: 0x00B628D0
void idGameLayerManager::AddItemMemory(const char* const itemName) {
    if (g_gameLayerServices == nullptr ||
            g_gameLayerServices->GetCurrentMapName() == nullptr) {
        OutputFormatted(true, "AddItemMemory %s, encountered failure",
            itemName);
        return;
    }
    const char* const mapName = g_gameLayerServices->GetCurrentMapName();
    for (int index = 0; index < retainedItemMemoryForMap.Num(); ++index) {
        if (idStr::Icmp(retainedItemMemoryForMap[index].mapName.c_str(),
                mapName) == 0) {
            retainedItemMemoryForMap[index].itemsList.Append(idStr(itemName));
            return;
        }
    }
    idRetainedItemMemoryForMap memory;
    memory.mapName = mapName;
    memory.itemsList.Append(idStr(itemName));
    retainedItemMemoryForMap.Append(memory);
}
