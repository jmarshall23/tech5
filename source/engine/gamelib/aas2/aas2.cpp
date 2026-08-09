#include "gamelib/aas2/aas2_local.h"

#include "framework/resourcelist.h"
#include "idlib/lib_print.h"

#include <cstdlib>

idAAS2::~idAAS2() = default;

idAAS2* idAAS2::Alloc() {
    return new idAAS2Local();
}

idAAS2Local::idAAS2Local()
    : file(nullptr), name(), defaulted(false), areaCacheIndex(nullptr),
      areaCacheIndexSize(0), portalCacheIndex(nullptr),
      portalCacheIndexSize(0), areaUpdate(nullptr), portalUpdate(nullptr),
      goalAreaTravelTimes(nullptr), areaTravelTimes(nullptr),
      numAreaTravelTimes(0), cacheListStart(nullptr), cacheListEnd(nullptr),
      totalCacheMemory(0), groundSpeedMultiplier(1.0f),
      waterSpeedMultiplier(1.0f), numObstaclePVSBytes(0),
      obstaclePVS(nullptr), obstaclePVSAreaNum(0), areaClipModels(nullptr),
      clipModelLinkAllocator(), obstacleAvoidance() {
}

idAAS2Local::~idAAS2Local() {
    Shutdown();
}

void idAAS2Local::Shutdown() {
    if (file == nullptr) return;
    ShutdownRouting();
    ShutdownObstaclePVS();
    file = nullptr;
    areaCacheIndex = nullptr;
    portalCacheIndex = nullptr;
    areaUpdate = nullptr;
    portalUpdate = nullptr;
    goalAreaTravelTimes = nullptr;
    areaTravelTimes = nullptr;
    cacheListStart = nullptr;
    cacheListEnd = nullptr;
    obstaclePVS = nullptr;
    areaClipModels = nullptr;
}

bool idAAS2Local::Init(const char* const mapName,
        const unsigned int mapFileCRC) {
    if (file != nullptr && mapName != nullptr
        && _stricmp(mapName, file->GetName()) == 0
        && mapFileCRC == file->crc && mapFileCRC != 0) {
        idLibPrint::Printf("Keeping %s\n", file->GetName());
        return true;
    }
    Shutdown();
    file = static_cast<idAAS2File*>(idAAS2File::resourceList.Load(
        mapName, true, false));
    if (file == nullptr) return false;
    name = mapName;
    defaulted = file->resourceError != nullptr;
    if (defaulted) {
        idLibPrint::Warning("Couldn't load AAS file: '%s'", mapName);
    }
    file->ResetCover();
    SetupRouting();
    SetupObstaclePVS();
    return true;
}

void idAAS2Local::Stats() const {
    if (file == nullptr) return;
    idLibPrint::Printf("[%s]\n", file->GetName());
    idLibPrint::Printf("%6d areas\n", file->areas.Num() - 1);
    idLibPrint::Printf("%6u kB file size\n", file->MemorySize() >> 10);
    RoutingStats();
}

const idAAS2Settings* idAAS2Local::GetSettings() const {
    return file != nullptr ? &file->settings : nullptr;
}

int idAAS2Local::PointAreaNum(
        const idIndex<int, invalidAASTree_t> tree,
        const idVec3& origin) const {
    return file != nullptr ? file->PointAreaNum(tree.Get(), origin) : 0;
}

int idAAS2Local::PointReachableAreaNum(
        const idIndex<int, invalidAASTree_t> tree, const idVec3& origin,
        const idBounds&, const int areaFlags,
        const int excludeTravelFlags) const {
    return file != nullptr ? file->PointReachableAreaNum(tree, origin,
        areaFlags, excludeTravelFlags) : 0;
}

int idAAS2Local::BoundsReachableAreaNum(
        const idIndex<int, invalidAASTree_t> tree, const idBounds& bounds,
        const int areaFlags, const int excludeTravelFlags) const {
    return file != nullptr ? file->BoundsReachableAreaNum(tree.Get(), bounds,
        static_cast<std::uint16_t>(areaFlags), excludeTravelFlags) : 0;
}

int idAAS2Local::BoundsReachableAreaNum(
        const idIndex<int, invalidAASTree_t> tree, const idVec3& origin,
        const idBounds& bounds, const int areaFlags,
        const int excludeTravelFlags) const {
    idBounds translated(bounds);
    translated[0] = translated[0] + origin;
    translated[1] = translated[1] + origin;
    return BoundsReachableAreaNum(tree, translated, areaFlags,
        excludeTravelFlags);
}

void idAAS2Local::PushPointIntoAreaNum(const int areaNum,
        idVec3& origin) const {
    if (file == nullptr || areaNum <= 0 || areaNum >= file->areas.Num()) return;
    if ((file->areas[areaNum].flags & AAS_AREA_NOPUSH) == 0) {
        file->PushPointIntoAreaNum(areaNum, origin);
    }
}

idVec3 idAAS2Local::AreaCenter(const int areaNum) const {
    return file != nullptr ? file->AreaCenter(areaNum) : idVec3();
}

bool idAAS2Local::Trace(const idIndex<int, invalidAASTree_t> tree,
        aas2Trace_t& trace, const idVec3& start, const idVec3& end) const {
    return file != nullptr && file->Trace(tree.Get(), trace, start, end);
}

bool idAAS2Local::TraceHeight(const idIndex<int, invalidAASTree_t> tree,
        aas2TraceHeight_t& trace, const idVec3& start,
        const idVec3& end) const {
    return file != nullptr && file->TraceHeight(tree.Get(), trace, start, end);
}

bool idAAS2Local::TraceFloor(aas2TraceFloor_t& trace,
        const idVec3& start, const int startAreaNum, const idVec3& end,
        const int travelFlags, const bool allowFloorNormalChange,
        const bool ignoreGravityDirectionDistance,
        const bool ignoreSameArea) const {
    return file != nullptr && file->TraceFloor(trace, start, startAreaNum,
        end, 0, travelFlags, allowFloorNormalChange,
        ignoreGravityDirectionDistance, ignoreSameArea);
}

void idAAS2Local::GetEdgeVertexNumbers(const int edgeNum,
        int verts[2]) const {
    if (verts == nullptr || file == nullptr) return;
    const aas2Edge_t& edge = file->edges[std::abs(edgeNum)];
    const int reverse = edgeNum < 0 ? 1 : 0;
    verts[0] = edge.vertexNum[reverse];
    verts[1] = edge.vertexNum[1 - reverse];
}

void idAAS2Local::GetEdge(const int edgeNum, idVec3& start,
        idVec3& end) const {
    int vertices[2] = {};
    GetEdgeVertexNumbers(edgeNum, vertices);
    start = file->vertices[vertices[0]];
    end = file->vertices[vertices[1]];
}

int idAAS2Local::GetEdgeFlags(const int edgeNum) const {
    return file != nullptr ? file->edges[std::abs(edgeNum)].flags : 0;
}

int idAAS2Local::GetAreaFlags(const int areaNum) const {
    return file != nullptr && areaNum >= 0 && areaNum < file->areas.Num()
        ? file->areas[areaNum].flags : 0;
}

void idAAS2Local::ClipGridToAreas(const idVec3& startOrigin,
        const int startAreaNum, const int travelFlags,
        const unsigned int cellSize, const int dimension,
        std::uint8_t* const reachable) const {
    if (file != nullptr) file->ClipGridToAreas(startOrigin, startAreaNum,
        travelFlags, cellSize, dimension, reachable);
}

bool idAAS2Local::GetAASAnim(
        const idIndex<short, invalidAASAnimIndex_t> index,
        const aas2AnimName_t** const value) const {
    return file != nullptr && file->GetAASAnim(index, value);
}

idIndex<short, invalidAASAnimIndex_t>
idAAS2Local::GetAASAnimIndexByName(const char* const value) const {
    return file != nullptr ? file->GetAASAnimIndexByName(value)
        : idIndex<short, invalidAASAnimIndex_t>();
}

bool idAAS2Local::GetAASDependency(
        const idIndex<short, invalidAASDependencyIndex_t> index,
        const aas2DependencyName_t** const value) const {
    return file != nullptr && file->GetAASDependency(index, value);
}

idIndex<short, invalidAASDependencyIndex_t>
idAAS2Local::GetAASDependencyIndexByName(const char* const value) const {
    return file != nullptr ? file->GetAASDependencyIndexByName(value)
        : idIndex<short, invalidAASDependencyIndex_t>();
}

bool idAAS2Local::GetAASInteractionEntity(
        const idIndex<short, invalidAASInteractionEntIndex_t> index,
        const aas2InteractionEntityName_t** const value) const {
    return file != nullptr && file->GetAASInteractionEntity(index, value);
}

idIndex<short, invalidAASInteractionEntIndex_t>
idAAS2Local::GetAASInteractionEntityIndexByName(
        const char* const value) const {
    return file != nullptr ? file->GetAASInteractionEntityIndexByName(value)
        : idIndex<short, invalidAASInteractionEntIndex_t>();
}

bool idAAS2Local::GetAASTraversalNameIndex(
        const idIndex<short, invalidAASTraversalNameIndex_t> index,
        const aas2TraversalEntityName_t** const value) const {
    return file != nullptr && file->GetAASTraversalNameIndex(index, value);
}

idIndex<short, invalidAASTraversalNameIndex_t>
idAAS2Local::GetAASTraversalNameIndexByName(const char* const value) const {
    return file != nullptr ? file->GetAASTraversalNameIndexByName(value)
        : idIndex<short, invalidAASTraversalNameIndex_t>();
}

int idAAS2Local::GetAASTraversalIndexByNameIndex(
        const idIndex<short, invalidAASTraversalNameIndex_t> index) const {
    return file != nullptr ? file->GetAASTraversalIndexByNameIndex(index) : -1;
}

bool idAAS2Local::SetTraversalFlag(const int index, const int flags) {
    if (file == nullptr || !file->SetTraversalFlag(index, flags)) return false;
    int startArea = 0;
    int goalArea = 0;
    if (file->GetAASTraversalAreas(index, startArea, goalArea)) {
        RemoveRoutingCacheUsingArea(startArea);
        RemoveRoutingCacheUsingArea(goalArea);
    }
    return true;
}

bool idAAS2Local::ClearTraversalFlag(const int index, const int flags) {
    if (file == nullptr || !file->ClearTraversalFlag(index, flags)) return false;
    int startArea = 0;
    int goalArea = 0;
    if (file->GetAASTraversalAreas(index, startArea, goalArea)) {
        RemoveRoutingCacheUsingArea(startArea);
        RemoveRoutingCacheUsingArea(goalArea);
    }
    return true;
}

int idAAS2Local::GetNumAreas() const {
    return file != nullptr ? file->areas.Num() : 0;
}

const idPlane* idAAS2Local::GetPlane(const int index) const {
    return file != nullptr && index >= 0 && index < file->planes.Num()
        ? &file->planes[index] : nullptr;
}

const aas2Area_t* idAAS2Local::GetArea(const int areaNum) const {
    return file != nullptr && areaNum >= 0 && areaNum < file->areas.Num()
        ? &file->areas[areaNum] : nullptr;
}

const aas2Reachability_t* idAAS2Local::GetReachability(
        const idIndex<short, invalidReachability_t> reachability) const {
    const int index = reachability.Get();
    return file != nullptr && index >= 0 && index < file->reachabilities.Num()
        ? &file->reachabilities[index] : nullptr;
}

const aas2Traversal_t* idAAS2Local::GetTraversal(
        const int traversalNum) const {
    return file != nullptr && traversalNum >= 0
        && traversalNum < file->traversalPoints.Num()
        ? &file->traversalPoints[traversalNum] : nullptr;
}

int idAAS2Local::GetNumTrees() const {
    return file != nullptr ? file->trees.Num() : 0;
}

idIndex<int, invalidAASTree_t> idAAS2Local::GetTree(
        const int index) const {
    return index >= 0 && index < GetNumTrees()
        ? idIndex<int, invalidAASTree_t>(index)
        : idIndex<int, invalidAASTree_t>();
}

idIndex<int, invalidAASTree_t> idAAS2Local::GetTreeForFloorNormal(
        const idVec3& floorNormal) const {
    return file != nullptr ? file->GetTreeForFloorNormal(floorNormal)
        : idIndex<int, invalidAASTree_t>();
}

const idVec3* idAAS2Local::GetFloorNormalForArea(const int areaNum) const {
    return file != nullptr ? file->GetFloorNormalForArea(areaNum) : nullptr;
}

const idVec3* idAAS2Local::GetFloorNormalForTree(
        const idIndex<int, invalidAASTree_t> tree) const {
    return file != nullptr ? file->GetFloorNormalForTree(tree) : nullptr;
}

int idAAS2Local::GetNumAreasInTree(
        const idIndex<int, invalidAASTree_t> tree) const {
    return file != nullptr ? file->GetNumAreasInTree(tree) : 0;
}
