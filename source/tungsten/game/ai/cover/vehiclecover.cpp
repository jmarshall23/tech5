#include "vehiclecover.h"

namespace {

constexpr int kInvalidCoverFlag = 0x2000;
constexpr int kBlockingContents = 0x0011;
constexpr float kMinimumUpDot = 0.70709997f;
constexpr float kMaximumStationaryVelocitySqr = 0.001f;

// Retail vehicleCoverProps, recovered from 0x82290FE0.  The alternating
// values describe the cover direction exposed by each of the eight tags.
constexpr short kVehicleCoverFlags[8] = {
    0x0443, 0x0485, 0x0485, 0x0443,
    0x0485, 0x0443, 0x0443, 0x0485
};

constexpr const char* kVehicleCoverTagNames[8] = {
    "up_front_right_facing_back",
    "up_front_right_facing_left",
    "up_front_left_facing_back",
    "up_front_left_facing_right",
    "up_back_right_facing_front",
    "up_back_right_facing_left",
    "up_back_left_facing_front",
    "up_back_left_facing_right"
};

} // namespace

// Retail symbol: ??0idVehicleCover@@QAA@XZ
// EA: 0x82A90AC0, RVA: 0x00A90AC0
idVehicleCover::idVehicleCover()
    : idDynamicCover(8) {
    numCover = 8;
}

// Retail symbol: ?FreeCover@idVehicleCoverMgr@@UAAXPAVidDynamicCover@@@Z
// EA: 0x82A90B08, RVA: 0x00A90B08
void idVehicleCoverMgr::FreeCover(idDynamicCover* const cover) {
    delete cover;
}

// Retail symbol: ?UpdateUsable@idVehicleCover@@UAAXPBVidEntity@@PBVidAAS2@@H@Z
// EA: 0x82A90B30, RVA: 0x00A90B30
void idVehicleCover::UpdateUsable(const idEntity* const owner,
        const idAAS2* const aas, const int currentTime) {
    if (owner == nullptr) {
        return;
    }

    idVehicleCoverOwnerRuntime runtime{};
    if (!Tungsten_GetVehicleCoverOwnerRuntime(*owner, runtime)
        || (!runtime.forced
            && (!runtime.isVehicle || !runtime.providesDynamicCover))) {
        return;
    }

    if (runtime.linearVelocity.LengthSqr()
            <= kMaximumStationaryVelocitySqr) {
        if (updated) {
            InternalUpdateCurrent(owner, aas, currentTime);
        } else {
            MarkAllUnusable();
            InternalUpdateUsable(owner, aas, currentTime);
            updated = true;
        }
    } else {
        MarkAllUnusable();
        updated = false;
    }
}

// Retail symbol: ?AllocCover@idVehicleCoverMgr@@UAAPAVidDynamicCover@@PBVidAAS2@@@Z
// EA: 0x82A90C68, RVA: 0x00A90C68
idDynamicCover* idVehicleCoverMgr::AllocCover(const idAAS2*) {
    return new idVehicleCover();
}

// Retail symbol:
// ?InternalUpdateCurrent@idVehicleCover@@MAAXPBVidEntity@@PBVidAAS2@@H@Z
// EA: 0x82A90D20, RVA: 0x00A90D20
void idVehicleCover::InternalUpdateCurrent(
        const idEntity* const owner, const idAAS2* const aas, const int) {
    if (owner == nullptr || aas == nullptr) {
        return;
    }

    for (int index = 0; index < numCover; ++index) {
        coverInfo_t& info = coverInfo[index];
        idVehicleCoverCurrentRuntime runtime{};
        if (!Tungsten_GetVehicleCoverCurrentRuntime(*owner, *aas, index,
                info.contentsQuery, info.translationQuery, runtime)) {
            continue;
        }

        if (runtime.contentsReady) {
            info.contentsQuery.index = 0;
            if ((runtime.contentsFlags & kBlockingContents) != 0) {
                info.cover.flags = static_cast<short>(
                    info.cover.flags | kInvalidCoverFlag);
                info.translationQuery.index = 0;
                Tungsten_DebugVehicleCover(*aas, index,
                    VEHICLE_COVER_DEBUG_CONTENTS_BLOCKED,
                    runtime.contentsEndPosition, 0.0f);
                continue;
            }
        }
        if (!runtime.translationReady) {
            continue;
        }

        info.translationQuery.index = 0;
        if (runtime.translationFraction == 1.0f) {
            info.cover.flags = static_cast<short>(
                info.cover.flags | kInvalidCoverFlag);
            Tungsten_DebugVehicleCover(*aas, index,
                VEHICLE_COVER_DEBUG_TRANSLATION_MISSED,
                runtime.translationEndPosition,
                runtime.translationFraction);
            continue;
        }

        info.cover.origin = runtime.translationEndPosition;
        info.cover.areaNum = static_cast<short>(
            runtime.translationAreaNumber);
        if (runtime.translationAreaNumber <= 0) {
            info.cover.flags = static_cast<short>(
                info.cover.flags | kInvalidCoverFlag);
            Tungsten_DebugVehicleCover(*aas, index,
                VEHICLE_COVER_DEBUG_INVALID_AREA,
                runtime.translationEndPosition,
                runtime.translationFraction);
            continue;
        }

        info.cover.flags = kVehicleCoverFlags[index];
        Tungsten_DebugVehicleCover(*aas, index,
            VEHICLE_COVER_DEBUG_VALID, runtime.translationEndPosition,
            runtime.translationFraction);
    }
}

// Retail symbol:
// ?InternalUpdateUsable@idVehicleCover@@MAAXPBVidEntity@@PBVidAAS2@@H@Z
// EA: 0x82A91568, RVA: 0x00A91568
void idVehicleCover::InternalUpdateUsable(
        const idEntity* const owner, const idAAS2* const aas,
        const int currentTime) {
    if (owner == nullptr || aas == nullptr) {
        return;
    }

    for (int index = 0; index < numCover; ++index) {
        coverInfo_t& info = coverInfo[index];
        if (info.cover.usableTime > currentTime) {
            continue;
        }

        idVehicleCoverUsableRuntime runtime{};
        if (!Tungsten_GetVehicleCoverUsableRuntime(
                *owner, *aas, index, kVehicleCoverTagNames[index], runtime)
            || !runtime.ownerStateValid) {
            return;
        }
        if (!runtime.tagTransformValid) {
            continue;
        }

        info.cover.origin = runtime.origin;
        info.cover.dir = runtime.direction;
        if (runtime.up.z < kMinimumUpDot
            || !runtime.clipModelValid) {
            continue;
        }

        info.contentsQuery = runtime.contentsQuery;
        info.translationQuery = runtime.translationQuery;
        Tungsten_DebugVehicleCover(*aas, index,
            VEHICLE_COVER_DEBUG_SUBMITTED,
            runtime.origin + idVec3(0.0f, 0.0f, 48.0f), 0.0f);
    }
}
