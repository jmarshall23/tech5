#include "framework/playteststorage.h"

#include "framework/framework_runtime_internal.h"

#include <algorithm>
#include <map>
#include <string>

namespace tech5Framework {
void RecordPlaytestEvent(const playtestEvent_t& event) { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); state.playtestEvents.push_back(event); }
std::vector<playtestEvent_t> PlaytestSnapshot() { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); return state.playtestEvents; }
void ClearPlaytestEvents() { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); state.playtestEvents.clear(); }
} // namespace tech5Framework

idPlaytestStorage::idPlaytestStorage()
    : numPlayers(0), version(-1), buildNumberMajor(-1),
      buildNumberMinor(-1), numActiveLayers(0), beginTime(-1), lastTime(0),
      offsetTime(0) {
}

idPlaytestStorage::~idPlaytestStorage() = default;

void idPlaytestStorage::Clear() {
    beginTime = -1;
    lastTime = 0;
    offsetTime = 0;
    const int playerCount = (std::min)(numPlayers, playerBreadCrumbs.Num());
    for (int player = 0; player < playerCount; ++player) {
        playerBreadCrumbs[player].state = PLAYERBREADCRUMBSTATE_NONE;
        playerBreadCrumbs[player].normalBreadCrumbs.ClearFree();
        playerBreadCrumbs[player].miscBreadCrumbs.ClearFree();
        playerBreadCrumbs[player].vehicleBreadCrumbs.ClearFree();
    }
    auto clearPlayerLists = [](auto& lists) {
        for (int index = 0; index < lists.Num(); ++index) {
            lists[index].ClearFree();
        }
    };
    clearPlayerLists(playerButtonInfo);
    clearPlayerLists(playerItemInfo);
    clearPlayerLists(playerUseFocusInfo);
    clearPlayerLists(playerUseQuickItemInfo);
    clearPlayerLists(playerEquipItemInfo);
    clearPlayerLists(playerDeathInfo);
    clearPlayerLists(playerWeaponFireInfo);
    clearPlayerLists(playerInventoryInfo);
    radiusDamageInfo.ClearFree();
    otherDeathInfo.ClearFree();
    otherWeaponFireInfo.ClearFree();
    ai2Info.ClearFree();
    aiVehicleInfo.ClearFree();
    tech5Framework::ClearPlaytestEvents();
}

void idPlaytestStorage::FullClear() {
    Clear();
    version = -1;
    numPlayers = 0;
    fileName.Clear();
    playMapName.Clear();
    activeLayers.ClearFree();
    numActiveLayers = 0;
    playerBreadCrumbs.ClearFree();
    playerButtonInfo.ClearFree();
    playerItemInfo.ClearFree();
    playerUseFocusInfo.ClearFree();
    playerUseQuickItemInfo.ClearFree();
    playerEquipItemInfo.ClearFree();
    playerDeathInfo.ClearFree();
    playerWeaponFireInfo.ClearFree();
    playerInventoryInfo.ClearFree();
}

void idPlaytestStorage::Record(
        const tech5Framework::playtestEvent_t& event) {
    tech5Framework::RecordPlaytestEvent(event);
}

idStr idPlaytestStorage::BuildReport() const {
    idStr report;
    report.Format("PLAYTEST FILE:\nmap: %s\nplayers: %d\n"
        "time: %s - %s\n",
        playMapName.c_str(), numPlayers,
        CreateReadableTimeString(beginTime < 0 ? 0 : beginTime).c_str(),
        CreateReadableTimeString(lastTime).c_str());
    idStr eventReport = tech5Framework::BuildPlaytestReport();
    report.Append(eventReport);
    return report;
}

idStr idPlaytestStorage::CreateReadableTimeString(const int timeMS) {
    const int safeTime = (std::max)(timeMS, 0);
    idStr result;
    result.Format("%02d:%02d", safeTime / 60000,
        safeTime % 60000 / 1000);
    return result;
}

void idPlaytestStorage::GenerateWeaponUseInfo(const int playerNum,
        idList<weaponUsageReport_t>& weaponList) const {
    weaponList.Clear();
    if (playerNum < 0 || playerNum >= playerEquipItemInfo.Num()) return;

    std::map<std::string, weaponUsageReport_t> byWeapon;
    const idList<equipItemInfo_t>& equipped = playerEquipItemInfo[playerNum];
    for (int index = 0; index < equipped.Num(); ++index) {
        const equipItemInfo_t& item = equipped[index];
        const int end = index + 1 < equipped.Num()
            ? equipped[index + 1].timestamp : lastTime;
        weaponUsageReport_t& usage = byWeapon[item.equipedItemName.c_str()];
        usage.weaponName = item.equipedItemName;
        usage.time += (std::max)(0, end - item.timestamp);
    }
    if (playerNum < playerWeaponFireInfo.Num()) {
        const idList<weaponFireInfo_t>& fired = playerWeaponFireInfo[playerNum];
        for (int index = 0; index < fired.Num(); ++index) {
            weaponUsageReport_t& usage = byWeapon[fired[index].weaponName.c_str()];
            usage.weaponName = fired[index].weaponName;
            ++usage.projectilesSpawned;
        }
    }
    const float duration = static_cast<float>((std::max)(lastTime, 1));
    for (auto& pair : byWeapon) {
        pair.second.percentage = pair.second.time / duration;
        weaponList.Append(pair.second);
    }
    if (weaponList.Num() > 1) {
        std::sort(weaponList.Ptr(), weaponList.Ptr() + weaponList.Num(),
            [](const weaponUsageReport_t& left,
                    const weaponUsageReport_t& right) {
                return left.time > right.time;
            });
    }
}

void idPlaytestStorage::GenerateKillInfo(const int playerNum,
        idList<killReport_t>& killList) const {
    killList.Clear();
    std::map<std::string, int> counts;
    for (int index = 0; index < otherDeathInfo.Num(); ++index) {
        if (otherDeathInfo[index].killerEntityNum == playerNum) {
            ++counts[otherDeathInfo[index].damageName.c_str()];
        }
    }
    for (const auto& pair : counts) {
        killReport_t report;
        report.damageName = pair.first.c_str();
        report.count = pair.second;
        killList.Append(report);
    }
    if (killList.Num() > 1) {
        std::sort(killList.Ptr(), killList.Ptr() + killList.Num(),
            [](const killReport_t& left, const killReport_t& right) {
                return left.count > right.count;
            });
    }
}

void idPlaytestStorage::GenerateQuickItemInfo(const int playerNum,
        idList<quickItemReport_t>& quickItemList) const {
    quickItemList.Clear();
    if (playerNum < 0 || playerNum >= playerUseQuickItemInfo.Num()) return;
    std::map<std::string, int> counts;
    const idList<quickItemInfo_t>& items = playerUseQuickItemInfo[playerNum];
    for (int index = 0; index < items.Num(); ++index) {
        ++counts[items[index].quickItemName.c_str()];
    }
    for (const auto& pair : counts) {
        quickItemReport_t report;
        report.itemName = pair.first.c_str();
        report.count = pair.second;
        quickItemList.Append(report);
    }
    if (quickItemList.Num() > 1) {
        std::sort(quickItemList.Ptr(),
            quickItemList.Ptr() + quickItemList.Num(),
            [](const quickItemReport_t& left,
                    const quickItemReport_t& right) {
                return left.count > right.count;
            });
    }
}
