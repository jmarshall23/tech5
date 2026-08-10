#include "formationcover.h"

namespace {

constexpr int kInvalidCoverFlag = 0x2000;
constexpr int kFormationCoverFlags = 0x00C7;
constexpr int kBlockingContents = 0x0011;
constexpr float kMinimumUpDot = 0.70709997f;

} // namespace

// Retail symbol: ??0idFormationCover@@QAA@XZ
// EA: 0x82A8FCA0, RVA: 0x00A8FCA0
idFormationCover::idFormationCover()
    : idDynamicCover(1) {
    numCover = 1;
}

// Retail symbol: ?UpdateUsable@idFormationCover@@UAAXPBVidEntity@@PBVidAAS2@@H@Z
// EA: 0x82A8FD48, RVA: 0x00A8FD48
void idFormationCover::UpdateUsable(const idEntity* const owner,
        const idAAS2* const aas, const int currentTime) {
    if (owner == nullptr || Tungsten_IsFormationCoverOwnerDead(*owner)) {
        MarkAllUnusable();
        return;
    }
    if (!updated) {
        MarkAllUnusable();
        InternalUpdateUsable(owner, aas, currentTime);
        updated = true;
        return;
    }

    InternalUpdateCurrent(owner, aas, currentTime);
    for (int index = 0; index < numCover; ++index) {
        if ((coverInfo[index].cover.flags & kInvalidCoverFlag) == 0) {
            updated = true;
            return;
        }
    }
    updated = false;
}

// Retail symbol: ?AllocCover@idFormationCoverMgr@@UAAPAVidDynamicCover@@PBVidAAS2@@@Z
// EA: 0x82A8FE68, RVA: 0x00A8FE68
idDynamicCover* idFormationCoverMgr::AllocCover(const idAAS2*) {
    return new idFormationCover();
}

void idFormationCoverMgr::FreeCover(idDynamicCover* const cover) {
    delete cover;
}

// Retail symbol:
// ?InternalUpdateCurrent@idFormationCover@@MAAXPBVidEntity@@PBVidAAS2@@H@Z
// EA: 0x82A8FF20, RVA: 0x00A8FF20
void idFormationCover::InternalUpdateCurrent(
        const idEntity* const owner, const idAAS2* const aas, const int) {
    if (owner == nullptr || aas == nullptr) {
        return;
    }
    for (int index = 0; index < numCover; ++index) {
        coverInfo_t& info = coverInfo[index];
        idFormationCoverCurrentRuntime runtime{};
        if (!Tungsten_GetFormationCoverCurrentRuntime(*owner, *aas,
                index, info.contentsQuery, info.translationQuery,
                runtime)
            || !runtime.ownerStateValid) {
            return;
        }
        if (!runtime.tagTransformValid) {
            continue;
        }

        info.cover.origin = runtime.origin;
        info.cover.dir = runtime.direction;
        if (runtime.contentsReady) {
            info.contentsQuery.index = 0;
            if ((runtime.contentsFlags & kBlockingContents) != 0) {
                info.cover.flags = static_cast<short>(
                    info.cover.flags | kInvalidCoverFlag);
                info.translationQuery.index = 0;
                Tungsten_DebugFormationCover(*aas, index,
                    FORMATION_DEBUG_CONTENTS_BLOCKED,
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
            Tungsten_DebugFormationCover(*aas, index,
                FORMATION_DEBUG_TRANSLATION_MISSED,
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
            Tungsten_DebugFormationCover(*aas, index,
                FORMATION_DEBUG_INVALID_AREA,
                runtime.translationEndPosition,
                runtime.translationFraction);
            continue;
        }
        info.cover.flags = kFormationCoverFlags;
        Tungsten_DebugFormationCover(*aas, index,
            FORMATION_DEBUG_VALID, runtime.translationEndPosition,
            runtime.translationFraction);
    }
}

// Retail symbol:
// ?InternalUpdateUsable@idFormationCover@@MAAXPBVidEntity@@PBVidAAS2@@H@Z
// EA: 0x82A90690, RVA: 0x00A90690
void idFormationCover::InternalUpdateUsable(
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

        idFormationCoverUsableRuntime runtime{};
        if (!Tungsten_GetFormationCoverUsableRuntime(
                *owner, *aas, index, runtime)
            || !runtime.ownerStateValid) {
            return;
        }
        if (!runtime.tagTransformValid) {
            continue;
        }

        info.cover.origin = runtime.origin;
        info.cover.dir = runtime.direction;
        const float upDot = runtime.up.z;
        if (upDot < kMinimumUpDot || !runtime.clipModelValid) {
            continue;
        }
        info.contentsQuery = runtime.contentsQuery;
        info.translationQuery = runtime.translationQuery;
        Tungsten_DebugFormationCover(*aas, index,
            FORMATION_DEBUG_SUBMITTED,
            runtime.origin + idVec3(0.0f, 0.0f, 48.0f), 0.0f);
    }
}
