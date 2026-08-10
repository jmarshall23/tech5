#include "framework/playteststorage.h"

#include "framework/buildversion.h"
#include "framework/framework_runtime_internal.h"
#include "idlib/csystems/cvarsystem.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/lib_print.h"
#include "idlib/sys/sys_utils.h"

#include <algorithm>
#include <cstdint>
#include <vector>

namespace {

idCVar playtest_save_useSavePath(
    "playtest_save_useSavePath", "1", CVAR_BOOL,
    "if true we save to FSPATH_SAVE else we save to FSPATH_BASE");

class playtestBinaryReader_t {
public:
    explicit playtestBinaryReader_t(idFile& source) : file(source), valid(true) {}

    template<class type_t>
    bool Read(type_t& value) {
        if (!valid || file.Read(&value,
                static_cast<unsigned int>(sizeof(value))) != sizeof(value)) {
            valid = false;
        }
        return valid;
    }

    bool ReadBytes(void* destination, const unsigned int length) {
        if (!valid || (length != 0
                && file.Read(destination, length) != length)) {
            valid = false;
        }
        return valid;
    }

    bool ReadString(idStr& value) {
        std::uint32_t length = 0;
        if (!Read(length) || length > 1024u * 1024u) {
            valid = false;
            return false;
        }
        if (length == 0) {
            value.Clear();
            return true;
        }
        std::vector<char> text(static_cast<std::size_t>(length) + 1u, 0);
        if (!ReadBytes(text.data(), length)) return false;
        value = text.data();
        return true;
    }

    bool ReadCount(int& count) {
        if (!Read(count) || count < 0 || count > 1024 * 1024) {
            valid = false;
        }
        return valid;
    }

    bool IsValid() const { return valid; }

private:
    idFile& file;
    bool valid;
};

bool ReadVec3(playtestBinaryReader_t& reader, idVec3& value) {
    return reader.ReadBytes(&value, sizeof(value));
}

bool ReadPlayerButtons(playtestBinaryReader_t& reader,
        idPlaytestStorage::playerButtonInfo_t& value) {
    value = {};
    return reader.Read(value.buttons) && reader.Read(value.forwardmove)
        && reader.Read(value.rightmove) && reader.Read(value.upmove)
        && reader.Read(value.timestamp) && reader.Read(value.lastTimestamp);
}

bool ReadPlayerNormal(playtestBinaryReader_t& reader,
        idPlaytestStorage::playerNormalBreadCrumbInfo_t& value) {
    value = {};
    value.count = 1;
    return ReadVec3(reader, value.loc) && ReadVec3(reader, value.dir)
        && reader.Read(value.health) && reader.Read(value.healthPercent)
        && reader.Read(value.speed) && reader.Read(value.mainAmmoCount)
        && reader.Read(value.combatHud) && reader.Read(value.isCrouching)
        && reader.Read(value.isZooming) && reader.Read(value.isCooking)
        && reader.Read(value.count) && reader.Read(value.timestamp)
        && reader.Read(value.lastTimeStamp);
}

bool ReadPlayerMisc(playtestBinaryReader_t& reader,
        idPlaytestStorage::playerMiscControlBreadCrumbInfo_t& value) {
    value = {};
    value.count = 1;
    return ReadVec3(reader, value.loc) && ReadVec3(reader, value.dir)
        && reader.Read(value.speed) && reader.Read(value.count)
        && reader.Read(value.timestamp) && reader.Read(value.lastTimeStamp);
}

bool ReadPlayerVehicle(playtestBinaryReader_t& reader,
        idPlaytestStorage::playerVehicleBreadCrumbInfo_t& value) {
    value = {};
    value.healthPercent = 1.0f;
    value.count = 1;
    return ReadVec3(reader, value.loc) && ReadVec3(reader, value.dir)
        && reader.Read(value.health) && reader.Read(value.healthPercent)
        && reader.Read(value.speed) && reader.Read(value.boost)
        && reader.Read(value.ammo) && reader.Read(value.count)
        && reader.Read(value.timestamp) && reader.Read(value.lastTimeStamp)
        && reader.Read(value.combatHud);
}

bool ReadAI2BreadCrumb(playtestBinaryReader_t& reader,
        idPlaytestStorage::ai2BreadCrumbInfo_t& value) {
    value = {};
    value.count = 1;
    value.healthPercent = 1.0f;
    return reader.Read(value.timestamp) && reader.Read(value.lastTimeStamp)
        && reader.Read(value.count) && reader.Read(value.isHostile)
        && reader.Read(value.isTalking) && reader.Read(value.health)
        && reader.Read(value.healthPercent) && reader.Read(value.speed)
        && ReadVec3(reader, value.loc) && ReadVec3(reader, value.dir);
}

bool ReadAIVehicleBreadCrumb(playtestBinaryReader_t& reader,
        idPlaytestStorage::aiVehicleBreadCrumbInfo_t& value) {
    value = {};
    value.count = 1;
    value.healthPercent = 1.0f;
    return ReadVec3(reader, value.loc) && ReadVec3(reader, value.dir)
        && reader.Read(value.health) && reader.Read(value.healthPercent)
        && reader.Read(value.speed) && reader.Read(value.boost)
        && reader.Read(value.ammo) && reader.Read(value.count)
        && reader.Read(value.timestamp) && reader.Read(value.lastTimeStamp)
        && reader.Read(value.hasCar) && reader.Read(value.isRCBomb);
}

bool ReadItem(playtestBinaryReader_t& reader,
        idPlaytestStorage::itemInfo_t& value) {
    value.count = 0;
    value.timestamp = 0;
    return reader.Read(value.timestamp) && reader.Read(value.count)
        && reader.ReadString(value.itemName)
        && reader.ReadString(value.materialName)
        && ReadVec3(reader, value.loc);
}

bool ReadUseFocus(playtestBinaryReader_t& reader,
        idPlaytestStorage::useFocusInfo_t& value) {
    value.timestamp = 0;
    return reader.Read(value.timestamp) && ReadVec3(reader, value.loc)
        && ReadVec3(reader, value.dir) && reader.ReadString(value.focusName);
}

template<class item_t>
bool ReadNamedItem(playtestBinaryReader_t& reader, item_t& value,
        idStr& itemName, idStr& materialName) {
    value.timestamp = 0;
    return reader.Read(value.timestamp) && ReadVec3(reader, value.loc)
        && reader.ReadString(itemName) && reader.ReadString(materialName);
}

bool ReadDeath(playtestBinaryReader_t& reader,
        idPlaytestStorage::deathInfo_t& value, const bool includeEntityName) {
    value.entityNum = value.killerEntityNum = -1;
    value.timestamp = 0;
    return reader.Read(value.timestamp) && reader.Read(value.entityNum)
        && (!includeEntityName || reader.ReadString(value.entityName))
        && ReadVec3(reader, value.loc) && reader.Read(value.killerEntityNum)
        && ReadVec3(reader, value.killerLoc)
        && reader.ReadString(value.killerName)
        && reader.ReadString(value.damageName);
}

bool ReadWeaponFire(playtestBinaryReader_t& reader,
        idPlaytestStorage::weaponFireInfo_t& value,
        const bool includeAttackerName) {
    value.attackerNum = value.targetNum = -1;
    value.spread = 0.0f;
    value.timestamp = 0;
    return reader.Read(value.timestamp) && reader.Read(value.attackerNum)
        && (!includeAttackerName || reader.ReadString(value.attackerName))
        && reader.Read(value.targetNum) && reader.Read(value.spread)
        && ReadVec3(reader, value.start) && ReadVec3(reader, value.dir)
        && reader.ReadString(value.weaponName)
        && reader.ReadString(value.projectileName);
}

void PrintVec3(idFile& file, const idVec3& value) {
    file.Printf("%.1f %.1f %.1f", value.x, value.y, value.z);
}

void PrintDeath(idFile& file, const idPlaytestStorage::deathInfo_t& value) {
    file.Printf("%d\t%d\t%s\t", value.timestamp, value.entityNum,
        value.entityName.c_str());
    PrintVec3(file, value.loc);
    file.Printf("\t%d\t%s\t", value.killerEntityNum,
        value.killerName.c_str());
    PrintVec3(file, value.killerLoc);
    file.Printf("\t%s\n", value.damageName.c_str());
}

void PrintWeaponFire(idFile& file,
        const idPlaytestStorage::weaponFireInfo_t& value) {
    file.Printf("%d\t%d\t%s\t%d\t%s\t%s\t%.3f\t", value.timestamp,
        value.attackerNum, value.attackerName.c_str(), value.targetNum,
        value.weaponName.c_str(), value.projectileName.c_str(), value.spread);
    PrintVec3(file, value.start);
    file.Printf("\t");
    PrintVec3(file, value.dir);
    file.Printf("\n");
}

} // namespace

bool idPlaytestStorage::ReadBinaryFile(const idStr& inputFileName) {
    FullClear();
    fileName = inputFileName;
    if (fileSystem == nullptr) return false;
    idFileLocal source(fileSystem->OpenFileRead(inputFileName.c_str(), true,
        false));
    if (source.file == nullptr) return false;
    playtestBinaryReader_t reader(*source.file);

    if (!reader.Read(version) || version < 1 || version > 3) {
        FullClear();
        return false;
    }
    if (version >= 3) {
        reader.ReadString(buildVersionString);
        reader.Read(buildNumberMajor);
        reader.Read(buildNumberMinor);
        reader.ReadString(machineName);
    }
    reader.ReadCount(numPlayers);
    reader.Read(beginTime);
    reader.Read(lastTime);
    reader.ReadString(playMapName);
    if (version >= 2) {
        reader.ReadCount(numActiveLayers);
        for (int index = 0; reader.IsValid() && index < numActiveLayers;
                ++index) {
            idStr layer;
            reader.ReadString(layer);
            if (activeLayers.FindIndex(layer) < 0) activeLayers.Append(layer);
        }
    }

    for (int player = 0; reader.IsValid() && player < numPlayers; ++player) {
        idList<playerButtonInfo_t> buttons;
        int count = 0;
        reader.ReadCount(count);
        for (int index = 0; reader.IsValid() && index < count; ++index) {
            playerButtonInfo_t value;
            ReadPlayerButtons(reader, value);
            if (reader.IsValid()) buttons.Append(value);
        }
        playerButtonInfo.Append(buttons);
    }

    for (int player = 0; reader.IsValid() && player < numPlayers; ++player) {
        playerMainBreadCrumbInfo_t mainInfo;
        reader.Read(mainInfo.state);
        int count = 0;
        reader.ReadCount(count);
        for (int index = 0; reader.IsValid() && index < count; ++index) {
            playerNormalBreadCrumbList_t path;
            reader.Read(path.inInteraction);
            reader.ReadString(path.interactionName);
            reader.ReadString(path.interactionEntity);
            int crumbs = 0;
            reader.ReadCount(crumbs);
            for (int crumb = 0; reader.IsValid() && crumb < crumbs; ++crumb) {
                playerNormalBreadCrumbInfo_t value;
                ReadPlayerNormal(reader, value);
                if (reader.IsValid()) path.breadCrumbs.Append(value);
            }
            if (reader.IsValid()) mainInfo.normalBreadCrumbs.Append(path);
        }
        reader.ReadCount(count);
        for (int index = 0; reader.IsValid() && index < count; ++index) {
            playerMiscControlBreadCrumbList_t path;
            reader.Read(path.isInteraction);
            reader.ReadString(path.controlName);
            int crumbs = 0;
            reader.ReadCount(crumbs);
            for (int crumb = 0; reader.IsValid() && crumb < crumbs; ++crumb) {
                playerMiscControlBreadCrumbInfo_t value;
                ReadPlayerMisc(reader, value);
                if (reader.IsValid()) path.breadCrumbs.Append(value);
            }
            if (reader.IsValid()) mainInfo.miscBreadCrumbs.Append(path);
        }
        reader.ReadCount(count);
        for (int index = 0; reader.IsValid() && index < count; ++index) {
            playerVehicleBreadCrumbList_t path;
            reader.Read(path.isRCBomb);
            reader.ReadString(path.vehicleName);
            int crumbs = 0;
            reader.ReadCount(crumbs);
            for (int crumb = 0; reader.IsValid() && crumb < crumbs; ++crumb) {
                playerVehicleBreadCrumbInfo_t value;
                ReadPlayerVehicle(reader, value);
                if (reader.IsValid()) path.breadCrumbs.Append(value);
            }
            if (reader.IsValid()) mainInfo.vehicleBreadCrumbs.Append(path);
        }
        if (reader.IsValid()) playerBreadCrumbs.Append(mainInfo);
    }

    int count = 0;
    reader.ReadCount(count);
    for (int index = 0; reader.IsValid() && index < count; ++index) {
        ai2Info_t info;
        reader.Read(info.creationTimeStamp);
        reader.Read(info.entNum);
        reader.Read(info.isDormant);
        reader.ReadString(info.entName);
        int paths = 0;
        reader.ReadCount(paths);
        for (int pathIndex = 0; reader.IsValid() && pathIndex < paths;
                ++pathIndex) {
            idList<ai2BreadCrumbInfo_t> path;
            int crumbs = 0;
            reader.ReadCount(crumbs);
            for (int crumb = 0; reader.IsValid() && crumb < crumbs; ++crumb) {
                ai2BreadCrumbInfo_t value;
                ReadAI2BreadCrumb(reader, value);
                if (reader.IsValid()) path.Append(value);
            }
            if (reader.IsValid()) info.breadCrumbs.Append(path);
        }
        int stateCount = 0;
        reader.ReadCount(stateCount);
        for (int stateIndex = 0; reader.IsValid() && stateIndex < stateCount;
                ++stateIndex) {
            ai2StateInfo_t stateInfo;
            stateInfo.timestamp = stateInfo.lastTimeStamp = -1;
            stateInfo.count = 1;
            reader.Read(stateInfo.timestamp);
            reader.Read(stateInfo.lastTimeStamp);
            reader.Read(stateInfo.count);
            int fsmCount = 0;
            reader.ReadCount(fsmCount);
            for (int fsm = 0; reader.IsValid() && fsm < fsmCount; ++fsm) {
                ai2FSMStateInfo_t fsmInfo;
                reader.ReadString(fsmInfo.fsmName);
                reader.ReadString(fsmInfo.stateName);
                reader.ReadString(fsmInfo.lastTransition);
                if (reader.IsValid()) stateInfo.states.Append(fsmInfo);
            }
            if (reader.IsValid()) info.stateLog.Append(stateInfo);
        }
        int dormantCount = 0;
        reader.ReadCount(dormantCount);
        for (int dormant = 0; reader.IsValid() && dormant < dormantCount;
                ++dormant) {
            int timestamp = 0;
            reader.Read(timestamp);
            if (reader.IsValid()) info.dormantTimeStamps.Append(timestamp);
        }
        if (reader.IsValid()) ai2Info.Append(info);
    }

    reader.ReadCount(count);
    for (int index = 0; reader.IsValid() && index < count; ++index) {
        aiVehicleInfo_t info;
        reader.Read(info.creationTimeStamp);
        reader.Read(info.entNum);
        reader.ReadString(info.entName);
        int crumbs = 0;
        reader.ReadCount(crumbs);
        for (int crumb = 0; reader.IsValid() && crumb < crumbs; ++crumb) {
            aiVehicleBreadCrumbInfo_t value;
            ReadAIVehicleBreadCrumb(reader, value);
            if (reader.IsValid()) info.breadCrumbs.Append(value);
        }
        if (reader.IsValid()) aiVehicleInfo.Append(info);
    }

    for (int player = 0; reader.IsValid() && player < numPlayers; ++player) {
        idList<itemInfo_t> values;
        reader.ReadCount(count);
        for (int index = 0; reader.IsValid() && index < count; ++index) {
            itemInfo_t value;
            ReadItem(reader, value);
            if (reader.IsValid()) values.Append(value);
        }
        playerItemInfo.Append(values);
    }
    for (int player = 0; reader.IsValid() && player < numPlayers; ++player) {
        idList<useFocusInfo_t> values;
        reader.ReadCount(count);
        for (int index = 0; reader.IsValid() && index < count; ++index) {
            useFocusInfo_t value;
            ReadUseFocus(reader, value);
            if (reader.IsValid()) values.Append(value);
        }
        playerUseFocusInfo.Append(values);
    }
    for (int player = 0; reader.IsValid() && player < numPlayers; ++player) {
        idList<quickItemInfo_t> values;
        reader.ReadCount(count);
        for (int index = 0; reader.IsValid() && index < count; ++index) {
            quickItemInfo_t value;
            ReadNamedItem(reader, value, value.quickItemName,
                value.quickItemMaterial);
            if (reader.IsValid()) values.Append(value);
        }
        playerUseQuickItemInfo.Append(values);
    }
    for (int player = 0; reader.IsValid() && player < numPlayers; ++player) {
        idList<equipItemInfo_t> values;
        reader.ReadCount(count);
        for (int index = 0; reader.IsValid() && index < count; ++index) {
            equipItemInfo_t value;
            ReadNamedItem(reader, value, value.equipedItemName,
                value.equipedItemMaterial);
            if (reader.IsValid()) values.Append(value);
        }
        playerEquipItemInfo.Append(values);
    }
    for (int player = 0; reader.IsValid() && player < numPlayers; ++player) {
        idList<inventoryInfo_t> values;
        reader.ReadCount(count);
        for (int index = 0; reader.IsValid() && index < count; ++index) {
            inventoryInfo_t value;
            value.timestamp = -1;
            reader.Read(value.timestamp);
            ReadVec3(reader, value.loc);
            int items = 0;
            reader.ReadCount(items);
            for (int item = 0; reader.IsValid() && item < items; ++item) {
                inventoryElement_t element;
                element.count = 1;
                reader.Read(element.count);
                reader.ReadString(element.itemName);
                reader.ReadString(element.materialName);
                if (reader.IsValid()) value.inventoryList.Append(element);
            }
            if (reader.IsValid()) values.Append(value);
        }
        playerInventoryInfo.Append(values);
    }
    for (int player = 0; reader.IsValid() && player < numPlayers; ++player) {
        idList<deathInfo_t> values;
        reader.ReadCount(count);
        for (int index = 0; reader.IsValid() && index < count; ++index) {
            deathInfo_t value;
            ReadDeath(reader, value, false);
            if (reader.IsValid()) values.Append(value);
        }
        playerDeathInfo.Append(values);
    }
    for (int player = 0; reader.IsValid() && player < numPlayers; ++player) {
        idList<weaponFireInfo_t> values;
        reader.ReadCount(count);
        for (int index = 0; reader.IsValid() && index < count; ++index) {
            weaponFireInfo_t value;
            ReadWeaponFire(reader, value, false);
            if (reader.IsValid()) values.Append(value);
        }
        playerWeaponFireInfo.Append(values);
    }

    reader.ReadCount(count);
    for (int index = 0; reader.IsValid() && index < count; ++index) {
        radiusDamageInfo_t value;
        value.radius = 1.0f;
        value.minDamage = value.maxDamage = value.playerDamageScale = 0.0f;
        ReadVec3(reader, value.loc);
        reader.Read(value.radius);
        reader.Read(value.minDamage);
        reader.Read(value.maxDamage);
        reader.Read(value.playerDamageScale);
        reader.ReadString(value.inflictorName);
        reader.ReadString(value.attackerName);
        reader.ReadString(value.damageDefName);
        reader.Read(value.timestamp);
        if (reader.IsValid()) radiusDamageInfo.Append(value);
    }
    reader.ReadCount(count);
    for (int index = 0; reader.IsValid() && index < count; ++index) {
        deathInfo_t value;
        ReadDeath(reader, value, true);
        if (reader.IsValid()) otherDeathInfo.Append(value);
    }
    reader.ReadCount(count);
    for (int index = 0; reader.IsValid() && index < count; ++index) {
        weaponFireInfo_t value;
        ReadWeaponFire(reader, value, true);
        if (reader.IsValid()) otherWeaponFireInfo.Append(value);
    }

    if (!reader.IsValid()) {
        idLibPrint::Warning("ReadBinaryFile: truncated or invalid %s",
            inputFileName.c_str());
        FullClear();
        return false;
    }
    return true;
}

void idPlaytestStorage::WriteTextFile(const idStr& outputFileName,
        const idStr& mapName, const idList<idStr>& mapLayersSpawned) {
    if (fileSystem == nullptr) return;
    const fsPath_t path = playtest_save_useSavePath.GetBool()
        ? FSPATH_SAVE : FSPATH_BASE;
    idFileLocal output(fileSystem->OpenFileWrite(outputFileName.c_str(), path));
    if (output.file == nullptr) {
        idLibPrint::Warning("WriteTextFile: couldn't open %s",
            outputFileName.c_str());
        return;
    }
    idFile& file = *output.file;
    file.Printf("PLAYTEST FILE:\n---\n");
    file.Printf("PT VERSION:\t%d\n", version);
    file.Printf("BUILD VERSION: %s\n", buildVersionString.Length() == 0
        ? versionInfo.fullVersion : buildVersionString.c_str());
    file.Printf("MACHINE NAME: %s\n", machineName.Length() == 0
        ? Sys_GetMachineName() : machineName.c_str());
    file.Printf("MAP:\t\t\t%s\n", mapName.c_str());
    file.Printf("LAYERS:\t\t%d\n", mapLayersSpawned.Num());
    for (int index = 0; index < mapLayersSpawned.Num(); ++index) {
        file.Printf("\t\t\t\t%s\n", mapLayersSpawned[index].c_str());
    }
    file.Printf("BeginTime: %d ms\nLastTime: %d ms\nTotal Time: %s\n",
        beginTime, lastTime,
        CreateReadableTimeString(lastTime - beginTime + 1).c_str());

    file.Printf("PLAYER BUTTON INFO\n---\n");
    for (int player = 0; player < playerButtonInfo.Num(); ++player) {
        const idList<playerButtonInfo_t>& values = playerButtonInfo[player];
        if (values.Num() == 0) continue;
        file.Printf("PLAYER : %d\nNUM BUTTON LOGS: %d\n", player,
            values.Num());
        file.Printf("time\tlastTime\tbutton\tup\tright\tforward\n---\n");
        for (int index = 0; index < values.Num(); ++index) {
            const playerButtonInfo_t& value = values[index];
            file.Printf("%d\t%d\t%d\t%d\t%d\t%d\n", value.timestamp,
                value.lastTimestamp, value.buttons, value.upmove,
                value.rightmove, value.forwardmove);
        }
    }

    file.Printf("PLAYER BREAD CRUMB INFORMATION:\n---\n");
    for (int player = 0; player < playerBreadCrumbs.Num(); ++player) {
        const playerMainBreadCrumbInfo_t& main = playerBreadCrumbs[player];
        file.Printf("PLAYER : %d\nNUM NORMAL PATHS: %d\nNUM MISC PATHS: "
            "%d\nNUM VEHICLE PATHS: %d\n---\n", player,
            main.normalBreadCrumbs.Num(), main.miscBreadCrumbs.Num(),
            main.vehicleBreadCrumbs.Num());
        for (int pathIndex = 0; pathIndex < main.normalBreadCrumbs.Num();
                ++pathIndex) {
            const playerNormalBreadCrumbList_t& pathInfo =
                main.normalBreadCrumbs[pathIndex];
            file.Printf("PLAYER NORMAL PATH INFO %d\n", pathIndex);
            if (pathInfo.inInteraction) {
                file.Printf("In interaction %s with entity %s\n",
                    pathInfo.interactionName.c_str(),
                    pathInfo.interactionEntity.c_str());
            }
            for (int index = 0; index < pathInfo.breadCrumbs.Num(); ++index) {
                const playerNormalBreadCrumbInfo_t& value =
                    pathInfo.breadCrumbs[index];
                file.Printf("%d\t%d\t%d\t%.1f\t%g\t%.1f\t%d\t%d\t%d\t%d\t%d\t",
                    value.timestamp, value.count, value.lastTimeStamp,
                    value.health, value.healthPercent, value.speed,
                    value.mainAmmoCount, value.combatHud, value.isCrouching,
                    value.isZooming, value.isCooking);
                PrintVec3(file, value.loc); file.Printf("\t");
                PrintVec3(file, value.dir); file.Printf("\n");
            }
        }
        for (int pathIndex = 0; pathIndex < main.miscBreadCrumbs.Num();
                ++pathIndex) {
            const playerMiscControlBreadCrumbList_t& pathInfo =
                main.miscBreadCrumbs[pathIndex];
            file.Printf("PLAYER MISC PATH INFO %d\nCONTROL: %s INTERACTION: %d\n",
                pathIndex, pathInfo.controlName.c_str(),
                pathInfo.isInteraction);
            for (int index = 0; index < pathInfo.breadCrumbs.Num(); ++index) {
                const playerMiscControlBreadCrumbInfo_t& value =
                    pathInfo.breadCrumbs[index];
                file.Printf("%d\t%d\t%d\t%.1f\t", value.timestamp,
                    value.count, value.lastTimeStamp, value.speed);
                PrintVec3(file, value.loc); file.Printf("\t");
                PrintVec3(file, value.dir); file.Printf("\n");
            }
        }
        for (int pathIndex = 0; pathIndex < main.vehicleBreadCrumbs.Num();
                ++pathIndex) {
            const playerVehicleBreadCrumbList_t& pathInfo =
                main.vehicleBreadCrumbs[pathIndex];
            file.Printf("PLAYER VEHICLE PATH INFO %d\nVEHICLE: %s bomb?: %d\n",
                pathIndex, pathInfo.vehicleName.c_str(), pathInfo.isRCBomb);
            for (int index = 0; index < pathInfo.breadCrumbs.Num(); ++index) {
                const playerVehicleBreadCrumbInfo_t& value =
                    pathInfo.breadCrumbs[index];
                file.Printf("%d\t%d\t%d\t%.1f\t%g\t%.1f\t%d\t%.1f\t%d\t",
                    value.timestamp, value.count, value.lastTimeStamp,
                    value.health, value.healthPercent, value.speed, value.ammo,
                    value.boost, value.combatHud);
                PrintVec3(file, value.loc); file.Printf("\t");
                PrintVec3(file, value.dir); file.Printf("\n");
            }
        }
    }

    file.Printf("AI2 BREADCRUMB INFORMATION:\n---\nNUMBER OF AI2 LOGS:\t%d\n",
        ai2Info.Num());
    for (int ai = 0; ai < ai2Info.Num(); ++ai) {
        const ai2Info_t& info = ai2Info[ai];
        file.Printf("AI2 %d:\t%s\t%d\nCreation Time:\t%s\nNUM PATHS: %d\n",
            ai, info.entName.c_str(), info.entNum,
            CreateReadableTimeString(info.creationTimeStamp).c_str(),
            info.breadCrumbs.Num());
        for (int path = 0; path < info.breadCrumbs.Num(); ++path) {
            for (int index = 0; index < info.breadCrumbs[path].Num(); ++index) {
                const ai2BreadCrumbInfo_t& value =
                    info.breadCrumbs[path][index];
                file.Printf("%d\t%d\t%d\t%d\t%d\t%.1f\t%g\t%.1f\t",
                    value.timestamp, value.count, value.lastTimeStamp,
                    value.isHostile, value.isTalking, value.health,
                    value.healthPercent, value.speed);
                PrintVec3(file, value.loc); file.Printf("\t");
                PrintVec3(file, value.dir); file.Printf("\n");
            }
        }
        file.Printf("STATE LOGS: %d\n", info.stateLog.Num());
        for (int state = 0; state < info.stateLog.Num(); ++state) {
            const ai2StateInfo_t& stateInfo = info.stateLog[state];
            file.Printf("%d\t%d\t%d", stateInfo.timestamp,
                stateInfo.lastTimeStamp, stateInfo.count);
            for (int fsm = 0; fsm < stateInfo.states.Num(); ++fsm) {
                file.Printf("\t%s:%s:%s", stateInfo.states[fsm].fsmName.c_str(),
                    stateInfo.states[fsm].stateName.c_str(),
                    stateInfo.states[fsm].lastTransition.c_str());
            }
            file.Printf("\n");
        }
        file.Printf("DORMANT TIMESTAMPS:");
        for (int index = 0; index < info.dormantTimeStamps.Num(); ++index) {
            file.Printf(" %d", info.dormantTimeStamps[index]);
        }
        file.Printf("\n");
    }

    file.Printf("AI VEHICLE INFORMATION: %d\n", aiVehicleInfo.Num());
    for (int ai = 0; ai < aiVehicleInfo.Num(); ++ai) {
        const aiVehicleInfo_t& info = aiVehicleInfo[ai];
        file.Printf("AI VEHICLE %d: %s %d created %d\n", ai,
            info.entName.c_str(), info.entNum, info.creationTimeStamp);
        for (int index = 0; index < info.breadCrumbs.Num(); ++index) {
            const aiVehicleBreadCrumbInfo_t& value = info.breadCrumbs[index];
            file.Printf("%d\t%d\t%d\t%.1f\t%g\t%.1f\t%.1f\t%d\t%d\t%d\t",
                value.timestamp, value.count, value.lastTimeStamp,
                value.health, value.healthPercent, value.speed, value.boost,
                value.ammo, value.hasCar, value.isRCBomb);
            PrintVec3(file, value.loc); file.Printf("\t");
            PrintVec3(file, value.dir); file.Printf("\n");
        }
    }

    for (int player = 0; player < numPlayers; ++player) {
        file.Printf("PLAYER %d ITEMS\n", player);
        if (player < playerItemInfo.Num()) {
            for (int index = 0; index < playerItemInfo[player].Num(); ++index) {
                const itemInfo_t& value = playerItemInfo[player][index];
                file.Printf("%d\t%d\t%s\t%s\t", value.timestamp,
                    value.count, value.itemName.c_str(),
                    value.materialName.c_str());
                PrintVec3(file, value.loc); file.Printf("\n");
            }
        }
        file.Printf("PLAYER %d USE FOCUS\n", player);
        if (player < playerUseFocusInfo.Num()) {
            for (int index = 0; index < playerUseFocusInfo[player].Num(); ++index) {
                const useFocusInfo_t& value = playerUseFocusInfo[player][index];
                file.Printf("%d\t%s\t", value.timestamp,
                    value.focusName.c_str());
                PrintVec3(file, value.loc); file.Printf("\t");
                PrintVec3(file, value.dir); file.Printf("\n");
            }
        }
        file.Printf("PLAYER %d QUICK ITEMS\n", player);
        if (player < playerUseQuickItemInfo.Num()) {
            for (int index = 0; index < playerUseQuickItemInfo[player].Num();
                    ++index) {
                const quickItemInfo_t& value =
                    playerUseQuickItemInfo[player][index];
                file.Printf("%d\t%s\t%s\t", value.timestamp,
                    value.quickItemName.c_str(),
                    value.quickItemMaterial.c_str());
                PrintVec3(file, value.loc); file.Printf("\n");
            }
        }
        file.Printf("PLAYER %d EQUIPPED ITEMS\n", player);
        if (player < playerEquipItemInfo.Num()) {
            for (int index = 0; index < playerEquipItemInfo[player].Num();
                    ++index) {
                const equipItemInfo_t& value = playerEquipItemInfo[player][index];
                file.Printf("%d\t%s\t%s\t", value.timestamp,
                    value.equipedItemName.c_str(),
                    value.equipedItemMaterial.c_str());
                PrintVec3(file, value.loc); file.Printf("\n");
            }
        }
        file.Printf("PLAYER %d INVENTORY\n", player);
        if (player < playerInventoryInfo.Num()) {
            for (int index = 0; index < playerInventoryInfo[player].Num();
                    ++index) {
                const inventoryInfo_t& value = playerInventoryInfo[player][index];
                file.Printf("%d\t", value.timestamp); PrintVec3(file, value.loc);
                for (int item = 0; item < value.inventoryList.Num(); ++item) {
                    const inventoryElement_t& element = value.inventoryList[item];
                    file.Printf("\t%s:%s:%d", element.itemName.c_str(),
                        element.materialName.c_str(), element.count);
                }
                file.Printf("\n");
            }
        }
        file.Printf("PLAYER %d DEATHS\n", player);
        if (player < playerDeathInfo.Num()) {
            for (int index = 0; index < playerDeathInfo[player].Num(); ++index) {
                PrintDeath(file, playerDeathInfo[player][index]);
            }
        }
        file.Printf("PLAYER %d WEAPON FIRE\n", player);
        if (player < playerWeaponFireInfo.Num()) {
            for (int index = 0; index < playerWeaponFireInfo[player].Num();
                    ++index) {
                PrintWeaponFire(file, playerWeaponFireInfo[player][index]);
            }
        }
    }

    file.Printf("RADIUS DAMAGE\n");
    for (int index = 0; index < radiusDamageInfo.Num(); ++index) {
        const radiusDamageInfo_t& value = radiusDamageInfo[index];
        file.Printf("%d\t%s\t%s\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t",
            value.timestamp, value.inflictorName.c_str(),
            value.attackerName.c_str(), value.damageDefName.c_str(),
            value.radius, value.minDamage, value.maxDamage,
            value.playerDamageScale);
        PrintVec3(file, value.loc); file.Printf("\n");
    }
    file.Printf("OTHER DEATHS\n");
    for (int index = 0; index < otherDeathInfo.Num(); ++index) {
        PrintDeath(file, otherDeathInfo[index]);
    }
    file.Printf("OTHER WEAPON FIRE\n");
    for (int index = 0; index < otherWeaponFireInfo.Num(); ++index) {
        PrintWeaponFire(file, otherWeaponFireInfo[index]);
    }
    file.ForceFlush();
}

namespace tech5Framework {
idStr BuildPlaytestReport() {
    runtimeState_t& state = State();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    idStr report;
    report.Format("playtest events: %d\n",
        static_cast<int>(state.playtestEvents.size()));
    for (const playtestEvent_t& event : state.playtestEvents) {
        idStr line;
        line.Format("%llu,%s,%s,%.3f,%.3f,%.3f,%.3f\n",
            event.microseconds, event.category.c_str(), event.name.c_str(),
            event.values[0], event.values[1], event.values[2], event.values[3]);
        report.Append(line);
    }
    return report;
}
} // namespace tech5Framework

idPlaytestMetaStorage::idPlaytestMetaStorage()
    : version(-1), beginTime(-1), lastTime(0), buildNumberMajor(-1),
      buildNumberMinor(-1) {
}

idStr idPlaytestMetaStorage::BuildReport() const {
    idStr report;
    report.Format("playtest sessions: %d\n", storageList.Num());
    for (int index = 0; index < storageList.Num(); ++index) {
        idStr storageReport = storageList[index].BuildReport();
        report.Append(storageReport);
    }
    return report;
}
