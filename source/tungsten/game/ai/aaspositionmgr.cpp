#include "aaspositionmgr.h"

namespace {

constexpr int MAX_AAS_POSITIONS = 2;
constexpr int REACHABLE_AREA_FLAGS = 2;
constexpr int EXCLUDED_TRAVEL_FLAGS = 1;

bool SamePoint(const idVec3& lhs, const idVec3& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

} // namespace

// Retail symbol: ?GetAreaNum@idAASPosition@@QBAHXZ
// EA: 0x829EE4C0, RVA: 0x009EE4C0
int idAASPosition::GetAreaNum() const {
    return valid ? static_cast<int>(areaNum) : 0;
}

// Retail symbol: ?Initialize@idAASPosition@@QAAXPBVidAAS2@@HABVidVec3@@@Z
// EA: 0x829EE4E0, RVA: 0x009EE4E0
void idAASPosition::Initialize(
        const idAAS2* const newAAS, const int newAreaNum,
        const idVec3& newOrigin) {
    aas = newAAS;
    areaNum = static_cast<std::uint16_t>(newAreaNum);
    origin = newOrigin;
    validOrigin = newOrigin;
    valid = true;
}

// Retail symbol: ?Update@idAASPosition@@QAAXPBVidAAS2@@ABVidVec3@@@Z
// EA: 0x829EE528, RVA: 0x009EE528
void idAASPosition::Update(
        const idAAS2* const newAAS, const idVec3& newOrigin) {
    if (newAAS == nullptr) {
        valid = false;
        return;
    }

    if (Tungsten_DebugAASPositionEnabled()) {
        Tungsten_DebugAASPositionPoint(origin, false);
        Tungsten_DebugAASPositionPoint(validOrigin, true);
    }

    if (areaNum != 0 && SamePoint(origin, newOrigin) && aas == newAAS) {
        return;
    }

    aas = newAAS;
    origin = newOrigin;
    int newAreaNum = Tungsten_AASPositionPointAreaNum(*newAAS, newOrigin);
    valid = newAreaNum != 0;
    if (valid) {
        validOrigin = newOrigin;
    } else {
        newAreaNum = Tungsten_AASPositionPointReachableAreaNum(
            *newAAS, newOrigin, REACHABLE_AREA_FLAGS,
            EXCLUDED_TRAVEL_FLAGS);
        if (newAreaNum == 0) {
            return;
        }

        Tungsten_AASPositionPushPointIntoAreaNum(
            *newAAS, newAreaNum, origin);
        validOrigin = origin;
        valid = true;
    }

    areaNum = static_cast<std::uint16_t>(newAreaNum);
}

// Retail symbol: ?Update@idAASPosition@@QAAXPBVidAAS2@@PBVidEntity@@@Z
// EA: 0x829EE760, RVA: 0x009EE760
void idAASPosition::Update(
        const idAAS2* const newAAS, const idEntity* const entity) {
    Update(newAAS, Tungsten_GetAASPositionEntityOrigin(*entity));
}

// Retail symbol: ??0idAASPositionMgr@@QAA@XZ
// EA: 0x829EE7C0, RVA: 0x009EE7C0
idAASPositionMgr::idAASPositionMgr()
    : aasPosition{}
    , lastUpdateFrame{-1, -1}
    , numAASPositions(0) {
    for (int index = 0; index < MAX_AAS_POSITIONS; ++index) {
        aasPosition[index].valid = false;
        aasPosition[index].areaNum = 0;
        aasPosition[index].origin.Zero();
        aasPosition[index].validOrigin.Zero();
        aasPosition[index].aas = nullptr;
    }
}

// Retail symbol: ?AllocAASPositionIndex@idAASPositionMgr@@AAAHPBVidAAS2@@@Z
// EA: 0x829EE828, RVA: 0x009EE828
int idAASPositionMgr::AllocAASPositionIndex(const idAAS2* const newAAS) {
    if (numAASPositions < MAX_AAS_POSITIONS) {
        return numAASPositions++;
    }

    int result = -1;
    int oldestFrame = 0x7FFFFFFF;
    for (int index = 0; index < numAASPositions; ++index) {
        if (aasPosition[index].aas == newAAS) {
            return index;
        }
        if (lastUpdateFrame[index] < oldestFrame) {
            oldestFrame = lastUpdateFrame[index];
            result = index;
        }
    }
    return result;
}

// Retail symbol:
// ?GetAASPosition@idAASPositionMgr@@QAAABVidAASPosition@@PBVidAAS2@@PBVidEntity@@@Z
// EA: 0x829EE8B8, RVA: 0x009EE8B8
const idAASPosition& idAASPositionMgr::GetAASPosition(
        const idAAS2* const newAAS, const idEntity* const entity) {
    int index = -1;
    for (int candidate = 0; candidate < numAASPositions; ++candidate) {
        if (aasPosition[candidate].aas == newAAS) {
            index = candidate;
            break;
        }
    }

    if (index < 0) {
        index = AllocAASPositionIndex(newAAS);
        if (index < 0) {
            index = 0;
        }
    }

    aasPosition[index].Update(
        newAAS, Tungsten_GetAASPositionEntityOrigin(*entity));
    return aasPosition[index];
}
