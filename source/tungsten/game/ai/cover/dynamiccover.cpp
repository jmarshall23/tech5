#include "dynamiccover.h"

#include <algorithm>

namespace {

constexpr int kInvalidSpawnId = 0x1FFF;
constexpr int kInvalidCoverFlag = 0x2000;

bool BoundsEqual(const idBounds& lhs, const idBounds& rhs) {
    for (int corner = 0; corner < 2; ++corner) {
        for (int axis = 0; axis < 3; ++axis) {
            if (lhs[corner][axis] != rhs[corner][axis]) {
                return false;
            }
        }
    }
    return true;
}

idBounds HullBounds(const float halfWidth) {
    idBounds bounds;
    bounds[0].Set(-halfWidth, -halfWidth, 0.0f);
    bounds[1].Set(halfWidth, halfWidth, 96.0f);
    return bounds;
}

} // namespace

// Materialized constructor semantics needed by the dynamic cover records.
aas2Cover_t::aas2Cover_t()
    : origin(0.0f, 0.0f, 0.0f)
    , dir(0.0f, 0.0f, 0.0f)
    , areaNum(0)
    , flags(0)
    , numTouching(0)
    , firstTouching(0)
    , durationSec(0.0f)
    , minRange(0.0f)
    , maxRange(0.0f)
    , reservedBy(kInvalidSpawnId)
    , usableTime(0) {
}

// Retail symbol: ?GetClipForAAS@idDynamicCover@@KAPBVidClipModel@@PBVidAAS2@@@Z
// EA: 0x82A8E428, RVA: 0x00A8E428
const idClipModel* idDynamicCover::GetClipForAAS(const idAAS2* const aas) {
    if (aas == nullptr) {
        return nullptr;
    }
    idBounds bounds;
    if (!Tungsten_GetDynamicCoverAASBounds(*aas, bounds)) {
        return nullptr;
    }
    if (BoundsEqual(bounds, HullBounds(12.0f))) {
        return Tungsten_GetDynamicCoverClipModel(24);
    }
    if (BoundsEqual(bounds, HullBounds(16.0f))) {
        return Tungsten_GetDynamicCoverClipModel(32);
    }
    if (BoundsEqual(bounds, HullBounds(24.0f))) {
        return Tungsten_GetDynamicCoverClipModel(48);
    }
    return nullptr;
}

// Retail symbol: ?GetPropNameForAAS@idDynamicCover@@KAPBDPBVidAAS2@@@Z
// EA: 0x82A8E4D8, RVA: 0x00A8E4D8
const char* idDynamicCover::GetPropNameForAAS(const idAAS2* const aas) {
    if (aas == nullptr) {
        return "_info";
    }
    idBounds bounds;
    if (!Tungsten_GetDynamicCoverAASBounds(*aas, bounds)) {
        return "_info";
    }
    if (BoundsEqual(bounds, HullBounds(12.0f))) return "_cover24";
    if (BoundsEqual(bounds, HullBounds(16.0f))) return "_cover32";
    if (BoundsEqual(bounds, HullBounds(24.0f))) return "_cover48";
    return "_info";
}

// Retail symbol: ?GetCoverPoint@idDynamicCover@@QAAPAUaas2Cover_t@@H@Z
// EA: 0x82A8E620, RVA: 0x00A8E620
aas2Cover_t* idDynamicCover::GetCoverPoint(const int index) {
    return index >= 0 && index < numCover
        ? &coverInfo[index].cover : nullptr;
}

const aas2Cover_t* idDynamicCover::GetCoverPoint(const int index) const {
    return index >= 0 && index < numCover
        ? &coverInfo[index].cover : nullptr;
}

// Retail symbol: ?MarkAllUsable@idDynamicCover@@MAAXXZ
// EA: 0x82A8E658, RVA: 0x00A8E658
void idDynamicCover::MarkAllUsable() {
    for (int index = 0; index < numCover; ++index) {
        coverInfo[index].cover.flags = static_cast<std::int16_t>(
            coverInfo[index].cover.flags & ~kInvalidCoverFlag);
    }
}

// Retail symbol: ?GetReserver@idDynamicCover@@QBAPBVidEntity@@H@Z
// EA: 0x82A8E6A8, RVA: 0x00A8E6A8
const idEntity* idDynamicCover::GetReserver(const int index) const {
    const aas2Cover_t* const cover = GetCoverPoint(index);
    return cover != nullptr
        ? Tungsten_ResolveEntitySpawnId(cover->reservedBy) : nullptr;
}

// Retail symbol: ?Reserve@idDynamicCover@@QAAXHPBVidEntity@@@Z
// EA: 0x82A8E6F8, RVA: 0x00A8E6F8
void idDynamicCover::Reserve(
        const int index, const idEntity* const entity) {
    aas2Cover_t* const cover = GetCoverPoint(index);
    if (cover != nullptr) {
        cover->reservedBy = Tungsten_GetEntitySpawnId(entity);
    }
}

// Retail symbol: ?Unreserve@idDynamicCover@@QAAXH@Z
// EA: 0x82A8E758, RVA: 0x00A8E758
void idDynamicCover::Unreserve(const int index) {
    aas2Cover_t* const cover = GetCoverPoint(index);
    if (cover != nullptr) {
        cover->reservedBy = kInvalidSpawnId;
    }
}

// Retail symbol: ?GetUsableTime@idDynamicCover@@QBAHH@Z
// EA: 0x82A8E778, RVA: 0x00A8E778
int idDynamicCover::GetUsableTime(const int index) const {
    const aas2Cover_t* const cover = GetCoverPoint(index);
    return cover != nullptr ? cover->usableTime : -1;
}

// Retail symbol: ?SetUsableTime@idDynamicCover@@QAAXHH@Z
// EA: 0x82A8E7B0, RVA: 0x00A8E7B0
void idDynamicCover::SetUsableTime(const int index, const int time) {
    aas2Cover_t* const cover = GetCoverPoint(index);
    if (cover != nullptr) {
        cover->usableTime = time;
    }
}

// Retail symbol: ?MarkAllUnusable@idDynamicCover@@MAAXXZ
// EA: 0x82A8E7D0, RVA: 0x00A8E7D0
void idDynamicCover::MarkAllUnusable() {
    for (int index = 0; index < numCover; ++index) {
        coverInfo_t& info = coverInfo[index];
        info.cover.flags = static_cast<std::int16_t>(
            info.cover.flags | kInvalidCoverFlag);
        info.cover.reservedBy = kInvalidSpawnId;
        Tungsten_CancelDynamicCoverQuery(info.contentsQuery);
        Tungsten_CancelDynamicCoverQuery(info.translationQuery);
    }
}

// Retail symbol: ??1idDynamicCover@@UAA@XZ
// EA: 0x82A8E978, RVA: 0x00A8E978
idDynamicCover::~idDynamicCover() {
    for (int index = 0; index < coverInfo.Num(); ++index) {
        Tungsten_CancelDynamicCoverQuery(coverInfo[index].contentsQuery);
        Tungsten_CancelDynamicCoverQuery(coverInfo[index].translationQuery);
    }
}

// Retail symbol: ??0idDynamicCover@@QAA@H@Z
// EA: 0x82A8EDD0, RVA: 0x00A8EDD0
idDynamicCover::idDynamicCover(const int numberOfCoverPoints)
    : numCover((std::max)(0, numberOfCoverPoints))
    , updated(false)
    , coverInfo() {
    for (int index = 0; index < numCover; ++index) {
        coverInfo_t info;
        info.contentsQuery.index = 0;
        info.translationQuery.index = 0;
        coverInfo.Append(info);
    }
}

// Retail symbol:
// ?InternalAppendUsableCover@idDynamicCover@@MBAHPBVidEntity@@PBVidAAS2@@AAV?$idList@VidAICover@@$04@@@Z
// EA: 0x82A8F090, RVA: 0x00A8F090
int idDynamicCover::InternalAppendUsableCover(const idEntity* const owner,
        const idAAS2* const aas, idList<idAICover, 5>& coverList) {
    int appended = 0;
    for (int index = 0; index < numCover; ++index) {
        if ((coverInfo[index].cover.flags & kInvalidCoverFlag) != 0) {
            continue;
        }
        idAICover* const cover = coverList.Alloc();
        if (cover == nullptr) {
            break;
        }
        cover->Init(owner, aas, index);
        ++appended;
    }
    return appended;
}
