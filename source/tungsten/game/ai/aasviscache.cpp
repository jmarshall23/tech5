#include "aasviscache.h"

#include <cstdio>
#include <new>

namespace {

constexpr std::uint32_t MAX_CACHE_BYTES = 0x7D000u;
constexpr int VISIBILITY_CLIP_MASK = 3;

bool SamePoint(const idVec3& lhs, const idVec3& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

} // namespace

idAASVisArea::idAASVisArea()
    : areaNum(0)
    , xcells(0)
    , ycells(0)
    , visRatio(0.0f)
    , cellVis(93) {
}

// Retail symbol: ?Init@idAASVisCache@@QAAXPBVidAAS2@@HM@Z
// EA: 0x829EE968, RVA: 0x009EE968
void idAASVisCache::Init(const idAAS2* const newAAS,
        const int newSubDivisionSize, const float newEyeHeight) {
    eyeHeight = newEyeHeight;
    aas = newAAS;
    subDivisionSize = newSubDivisionSize;
}

// Retail symbol: ?FindVisPoint@idAASVisCache@@AAAPAVidAASVisPoint@@ABVidVec3@@@Z
// EA: 0x829EE978, RVA: 0x009EE978
idAASVisPoint* idAASVisCache::FindVisPoint(const idVec3& eyePoint) {
    for (int index = 0; index < visPoints.Num(); ++index) {
        if (SamePoint(visPoints[index]->eyePoint, eyePoint)) {
            return visPoints[index];
        }
    }
    return nullptr;
}

// Retail symbol: ?FindOldest@idAASVisCache@@ABAHXZ
// EA: 0x829EEA00, RVA: 0x009EEA00
int idAASVisCache::FindOldest() const {
    if (visPoints.IsEmpty()) {
        return -1;
    }

    int oldest = 0;
    int oldestTime = visPoints[0]->cacheTime;
    for (int index = 1; index < visPoints.Num(); ++index) {
        if (visPoints[index]->cacheTime < oldestTime) {
            oldest = index;
            oldestTime = visPoints[index]->cacheTime;
        }
    }
    return oldest;
}

// Retail symbol: ?GetNumCachedAreas@idAASVisCache@@QBAHXZ
// EA: 0x829EEA68, RVA: 0x009EEA68
int idAASVisCache::GetNumCachedAreas() const {
    int total = 0;
    for (int index = 0; index < visPoints.Num(); ++index) {
        total += visPoints[index]->visAreas.Num();
    }
    return total;
}

// Retail symbol:
// ?IsPointVisible@idAASVisArea@@QAA_NPBVidAASVisCache@@PBVidAASVisPoint@@ABVidVec3@@@Z
// EA: 0x829EEAF0, RVA: 0x009EEAF0
bool idAASVisArea::IsPointVisible(const idAASVisCache* const visCache,
        const idAASVisPoint* const visPoint, const idVec3& testPoint) {
    (void)visPoint;
    if (areaNum <= 0 || cellVis.Num() == 0) {
        return false;
    }

    int x = 0;
    int y = 0;
    Tungsten_AASVisCacheWorldPosToCellPos(*visCache->aas, areaNum,
        visCache->subDivisionSize, testPoint, x, y);
    return cellVis.Get(static_cast<unsigned int>(xcells * y + x));
}

// Retail symbol: ??0idAASVisPoint@@QAA@ABVidVec3@@H@Z
// EA: 0x829EEB88, RVA: 0x009EEB88
idAASVisPoint::idAASVisPoint(const idVec3& newEyePoint, const int time)
    : eyePoint(newEyePoint)
    , visAreas(0)
    , cacheTime(time) {
}

// Retail symbol: ?Free@idAASVisPoint@@AAAXXZ
// EA: 0x829EEC08, RVA: 0x009EEC08
void idAASVisPoint::Free() {
    for (int index = 0; index < visAreas.Num(); ++index) {
        delete visAreas[index];
    }
}

// Retail symbol: ??0idAASVisCache@@QAA@XZ
// EA: 0x829EECA8, RVA: 0x009EECA8
idAASVisCache::idAASVisCache()
    : aas(nullptr)
    , eyeHeight(0.0f)
    , subDivisionSize(0)
    , visPoints(0) {
}

// Retail symbol: ?Size@idAASVisCache@@QBAIXZ
// EA: 0x829EED10, RVA: 0x009EED10
std::uint32_t idAASVisCache::Size() const {
    std::uint32_t total = 28;
    for (int pointIndex = 0; pointIndex < visPoints.Num(); ++pointIndex) {
        const idAASVisPoint* const point = visPoints[pointIndex];
        total += 32;
        for (int areaIndex = 0; areaIndex < point->visAreas.Num();
                ++areaIndex) {
            const unsigned int bits = point->visAreas[areaIndex]->cellVis.Num();
            total += 40u + ((bits + 7u) >> 3);
        }
    }
    return total;
}

// Retail symbol: ?Cmd_VisCacheInfo_f@idAASVisCache@@SAXABVidCmdArgs@@@Z
// EA: 0x829EED90, RVA: 0x009EED90
void idAASVisCache::Cmd_VisCacheInfo_f(const idCmdArgs& args) {
    (void)args;
    const idAASVisCache& cache = Tungsten_GetGameAASVisCache();
    char text[128];
    Tungsten_AASVisCachePrint("AAS Visibility Cache info:\n");
    std::snprintf(text, sizeof(text), "  eyeHeight: %.2f\n", cache.eyeHeight);
    Tungsten_AASVisCachePrint(text);
    std::snprintf(text, sizeof(text), "  bytes: %u\n", cache.Size());
    Tungsten_AASVisCachePrint(text);
    std::snprintf(text, sizeof(text), "  cached points: %d\n",
        cache.visPoints.Num());
    Tungsten_AASVisCachePrint(text);
    std::snprintf(text, sizeof(text), "  cached areas: %d\n",
        cache.GetNumCachedAreas());
    Tungsten_AASVisCachePrint(text);
}

// Retail symbol: ??1idAASVisPoint@@QAA@XZ
// EA: 0x829EEE30, RVA: 0x009EEE30
idAASVisPoint::~idAASVisPoint() {
    Free();
    visAreas.ClearFree();
}

// Retail symbol: ?RemoveOldest@idAASVisCache@@AAAXXZ
// EA: 0x829EEEA0, RVA: 0x009EEEA0
void idAASVisCache::RemoveOldest() {
    const int oldest = FindOldest();
    if (oldest < 0) {
        return;
    }

    delete visPoints[oldest];
    visPoints.RemoveIndexFast(oldest);
    char text[96];
    std::snprintf(text, sizeof(text),
        "idAASVisCache::RemoveOldest - removed index %d\n", oldest);
    Tungsten_AASVisCachePrint(text);
}

// Retail symbol: ?AddVisArea@idAASVisPoint@@AAAPAVidAASVisArea@@H@Z
// EA: 0x829EEF38, RVA: 0x009EEF38
idAASVisArea* idAASVisPoint::AddVisArea(const int newAreaNum) {
    idAASVisArea* const area = new (std::nothrow) idAASVisArea;
    if (area == nullptr) {
        Tungsten_AASVisCacheWarning(
            "idAASVisPoint::AddVisArea - failed to allocate idAASVisArea");
        return nullptr;
    }

    int insertion = 0;
    int high = visAreas.Num() - 1;
    while (insertion < high) {
        const int middle = (insertion + high) >> 1;
        if (visAreas[middle]->areaNum >= newAreaNum) {
            high = middle;
        } else {
            insertion = middle + 1;
        }
    }
    visAreas.Insert(area, insertion);
    return area;
}

// Retail symbol: ?Free@idAASVisCache@@AAAXXZ
// EA: 0x829EF040, RVA: 0x009EF040
void idAASVisCache::Free() {
    for (int index = 0; index < visPoints.Num(); ++index) {
        delete visPoints[index];
    }
    visPoints.ClearFree();
}

// Retail symbol: ?Shutdown@idAASVisCache@@QAAXXZ
// EA: 0x829EF160, RVA: 0x009EF160
void idAASVisCache::Shutdown() {
    aas = nullptr;
    Free();
}

// Retail symbol: ?AddVisPoint@idAASVisCache@@AAAPAVidAASVisPoint@@ABVidVec3@@@Z
// EA: 0x829EF178, RVA: 0x009EF178
idAASVisPoint* idAASVisCache::AddVisPoint(const idVec3& eyePoint) {
    const std::uint32_t bytes = Size();
    if (bytes > MAX_CACHE_BYTES) {
        RemoveOldest();
        char text[96];
        std::snprintf(text, sizeof(text),
            "AddVisPoint - num %d, size = %u\n", visPoints.Num(), bytes);
        Tungsten_AASVisCachePrint(text);
    }

    idAASVisPoint* const point = new (std::nothrow) idAASVisPoint(
        eyePoint, Tungsten_GetAASVisCacheGameMilliseconds());
    if (point == nullptr) {
        Tungsten_AASVisCacheWarning(
            "idAASVisCache::AddVisPoint - Failed to allocate idAASVisPoint");
        return nullptr;
    }
    if (visPoints.Append(point) < 0) {
        delete point;
        Tungsten_AASVisCacheWarning(
            "idAASVisCache::AddVisPoint - Failed to allocate idAASVisPoint");
        return nullptr;
    }
    return point;
}

// Retail symbol:
// ?CacheVisibilities@idAASVisArea@@QAAXPBVidAASVisCache@@PBVidAASVisPoint@@H@Z
// EA: 0x829EF2A0, RVA: 0x009EF2A0
void idAASVisArea::CacheVisibilities(const idAASVisCache* const visCache,
        const idAASVisPoint* const visPoint, const int newAreaNum) {
    const idAAS2* const areaSystem = visCache->aas;
    if (areaSystem == nullptr) {
        return;
    }

    cellVis.Alloc(0);
    const int cellSize = visCache->subDivisionSize;
    if (!Tungsten_AASVisCacheGetAreaCells(
            *areaSystem, newAreaNum, cellSize, xcells, ycells)) {
        areaNum = newAreaNum;
        return;
    }

    cellVis.Alloc(static_cast<unsigned int>(xcells * ycells));
    visRatio = 0.0f;
    int visibleCells = 0;
    const float halfCell = static_cast<float>(cellSize) * 0.5f;
    for (int y = 0; y < ycells; ++y) {
        for (int x = 0; x < xcells; ++x) {
            idVec3 testPoint;
            Tungsten_AASVisCacheCellPosToWorldPos(*areaSystem, newAreaNum,
                cellSize, x, y, testPoint, true);
            testPoint.x += halfCell;
            testPoint.y += halfCell;
            testPoint.z += visCache->eyeHeight;
            if (Tungsten_AASVisCacheTraceVisible(
                    visPoint->eyePoint, testPoint, VISIBILITY_CLIP_MASK)) {
                cellVis.Set(static_cast<unsigned int>(xcells * y + x));
                ++visibleCells;
            }
        }
    }

    const int totalCells = xcells * ycells;
    if (totalCells > 0) {
        visRatio = static_cast<float>(visibleCells)
            / static_cast<float>(totalCells);
    }
    if (visibleCells == 0) {
        cellVis.Alloc(0);
    }
    areaNum = newAreaNum;
}

// Retail symbol: ?GetVisArea@idAASVisPoint@@AAAPAVidAASVisArea@@H@Z
// EA: 0x829EF628, RVA: 0x009EF628
idAASVisArea* idAASVisPoint::GetVisArea(const int searchAreaNum) {
    int low = 0;
    int high = visAreas.Num() - 1;
    while (low < high) {
        const int middle = (low + high) >> 1;
        if (visAreas[middle]->areaNum >= searchAreaNum) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }
    if (low == high && visAreas[low]->areaNum == searchAreaNum) {
        return visAreas[low];
    }
    return nullptr;
}

// Retail symbol: ??1idAASVisCache@@QAA@XZ
// EA: 0x829EF758, RVA: 0x009EF758
idAASVisCache::~idAASVisCache() {
    Free();
}

// Retail symbol:
// ?IsPointVisible@idAASVisPoint@@QAA_NPBVidAASVisCache@@ABVidVec3@@H@Z
// EA: 0x829EF7C8, RVA: 0x009EF7C8
bool idAASVisPoint::IsPointVisible(const idAASVisCache* const visCache,
        const idVec3& testPoint, const int testPointAreaNum) {
    if (visCache->aas == nullptr) {
        return false;
    }

    idVec3 pushedPoint = testPoint;
    Tungsten_AASVisCachePushPointIntoAreaNum(
        *visCache->aas, testPointAreaNum, pushedPoint);
    idAASVisArea* area = GetVisArea(testPointAreaNum);
    if (area == nullptr) {
        area = AddVisArea(testPointAreaNum);
        if (area == nullptr) {
            return false;
        }
        area->CacheVisibilities(visCache, this, testPointAreaNum);
    }
    return area->IsPointVisible(visCache, this, pushedPoint);
}

// Retail symbol: ?VisibilityRatio@idAASVisPoint@@QAAMPBVidAASVisCache@@H@Z
// EA: 0x829EF888, RVA: 0x009EF888
float idAASVisPoint::VisibilityRatio(
        const idAASVisCache* const visCache, const int searchAreaNum) {
    if (visCache->aas == nullptr) {
        return 0.0f;
    }

    idAASVisArea* area = GetVisArea(searchAreaNum);
    if (area == nullptr) {
        area = AddVisArea(searchAreaNum);
        if (area == nullptr) {
            return 0.0f;
        }
        area->CacheVisibilities(visCache, this, searchAreaNum);
    }
    return searchAreaNum > 0 && area->cellVis.Num() != 0
        ? area->visRatio : 0.0f;
}

// Retail symbol:
// ?IsPointVisible@idAASVisCache@@QAA_NABVidVec3@@0PBVidAAS2@@H@Z
// EA: 0x829EF928, RVA: 0x009EF928
bool idAASVisCache::IsPointVisible(const idVec3& eyePoint,
        const idVec3& destPoint, const idAAS2* const requestedAAS,
        const int destAreaNum) {
    if (requestedAAS == nullptr || aas != requestedAAS) {
        return true;
    }
    idAASVisPoint* point = FindVisPoint(eyePoint);
    if (point == nullptr) {
        point = AddVisPoint(eyePoint);
    }
    return point == nullptr
        || point->IsPointVisible(this, destPoint, destAreaNum);
}

// Retail symbol: ?VisibilityRatio@idAASVisCache@@QAAMABVidVec3@@PBVidAAS2@@H@Z
// EA: 0x829EFA70, RVA: 0x009EFA70
float idAASVisCache::VisibilityRatio(const idVec3& eyePoint,
        const idAAS2* const requestedAAS, const int searchAreaNum) {
    if (requestedAAS == nullptr || aas != requestedAAS) {
        return 0.0f;
    }
    idAASVisPoint* point = FindVisPoint(eyePoint);
    if (point == nullptr) {
        point = AddVisPoint(eyePoint);
    }
    return point != nullptr
        ? point->VisibilityRatio(this, searchAreaNum) : 0.0f;
}
