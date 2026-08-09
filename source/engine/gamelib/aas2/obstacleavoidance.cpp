#include "gamelib/aas2/obstacleavoidance.h"

#include "gamelib/aas2/obstacleavoidancemanagerlocal.h"
#include "gamelib/effects/weapontracemanager.h"
#include "idlib/bv/box.h"
#include "idlib/filesystem/filesystem.h"

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <vector>

namespace {

constexpr int MAX_OBSTACLES = 128;
constexpr int MAX_VERTICES = 0x300;
constexpr int MAX_EDGES = 0x200;
constexpr int MAX_CORNERS = 16;
constexpr int MAX_TRACES = 256;
constexpr int TEMP_MEMORY_SIZE = 0x10000;
constexpr char QUERY_IDENTIFIER[] = "ObstacleAvoidanceQuery";

struct obstacleTestQuery_t {
    int time;
    int gameMsPerFrame;
    idBounds bbox;
    idVec3 gravity;
    float obstacleRadius;
    float frameMoveDist;
    float circleCornerRadius;
    int flags;
};

obstacleTestQuery_t testQuery{};

template<typename type_t>
bool WriteValue(idFile& file, const type_t& value) {
    return file.Write(&value, static_cast<unsigned int>(sizeof(value)))
        == sizeof(value);
}

template<typename type_t>
bool ReadValue(idFile& file, type_t& value) {
    return file.Read(&value, static_cast<unsigned int>(sizeof(value)))
        == sizeof(value);
}

bool WriteArray(idFile& file, const void* const data,
        const std::size_t elementSize, const int count) {
    const std::size_t byteCount = elementSize * static_cast<std::size_t>(count);
    return byteCount == 0 || file.Write(data,
        static_cast<unsigned int>(byteCount)) == byteCount;
}

bool ReadArray(idFile& file, void* const data,
        const std::size_t elementSize, const int count) {
    const std::size_t byteCount = elementSize * static_cast<std::size_t>(count);
    return byteCount == 0 || file.Read(data,
        static_cast<unsigned int>(byteCount)) == byteCount;
}

void RunObstacleAvoidanceJob(obstacleParms_t& parms) {
    std::vector<std::uint8_t> scratch(TEMP_MEMORY_SIZE);
    idObstacleAvoidanceCore core;
    core.FindPathAroundObstacles(*parms.path,
        parms.debugLines, parms.maxDebugLines,
        parms.debugText, parms.maxDebugText,
        scratch.data(), static_cast<int>(scratch.size()),
        parms.bbox, parms.gravity, parms.lastDir, parms.lastCorner,
        parms.obstacleRadius, parms.frameMoveDist, parms.cornerCircleRadius,
        parms.flags, *parms.route, parms.obstacles, parms.numObstacles,
        parms.vertices, parms.numVertices, parms.edges, parms.numEdges,
        parms.corners, parms.numCorners, parms.traces, parms.numTraces,
        parms.traceFractions);
    parms.path->done = true;
}

} // namespace

idObstacleAvoidance::idObstacleAvoidance()
    : buffers(nullptr), lastDir(), lastCorner(), lastUpdateTime(-1) {
}

idObstacleAvoidance::~idObstacleAvoidance() {
    obstacleAvoidanceManagerLocal.FreeObstacleBuffers(this);
}

void idObstacleAvoidance::AllocBuffers() {
    obstacleAvoidanceManagerLocal.AllocObstacleBuffers(this);
}

obstacleVertex_t* idObstacleAvoidance::GetVertexArray() {
    return buffers != nullptr ? buffers->vertices : nullptr;
}

int idObstacleAvoidance::GetMaxVertices() const {
    return buffers != nullptr ? MAX_VERTICES : 0;
}

void idObstacleAvoidance::SetNumVertices(const int num) {
    if (buffers != nullptr) buffers->numVertices = num;
}

obstacleEdge_t* idObstacleAvoidance::GetEdgeArray() {
    return buffers != nullptr ? buffers->edges : nullptr;
}

int idObstacleAvoidance::GetMaxEdges() const {
    return buffers != nullptr ? MAX_EDGES : 0;
}

void idObstacleAvoidance::SetNumEdges(const int num) {
    if (buffers != nullptr) buffers->numEdges = num;
}

void idObstacleAvoidance::AddObstacle(const idBox& box,
        const idSpawnId id, const bool soft) {
    if (buffers == nullptr || buffers->numObstacles >= MAX_OBSTACLES) return;
    obstacleBox_t& obstacle = buffers->obstacles[buffers->numObstacles++];
    obstacle.axis = box.axis;
    obstacle.center = box.center;
    obstacle.extents = box.extents;
    obstacle.id = id.Get();
    obstacle.soft = soft;
}

void idObstacleAvoidance::AddObstacle(const idBounds& bounds,
        const idVec3& origin, const idMat3& axis, const idSpawnId id,
        const bool soft) {
    AddObstacle(idBox(bounds, origin, axis), id, soft);
}

void idObstacleAvoidance::Restart(const idVec3& start, const idVec3& goal) {
    if (buffers == nullptr || buffers->path == nullptr) return;
    obstaclePath_t& path = *buffers->path;
    path = obstaclePath_t();
    path.seekPos[0] = goal;
    path.seekPos[1] = goal;
    path.startPosOutsideObstacles = start;
    path.seekPosOutsideObstacles = start;
    path.wallCorners[0] = goal;
    path.wallCorners[1] = goal;
    path.firstObstacle = -1;
    path.startPosObstacle = -1;
    path.seekPosObstacle = -1;
    path.hasValidPath = true;
    path.startPosValid = true;
    path.seekPosValid = true;
    path.done = false;
    for (obstaclePath_t::radar_t& radar : path.radar) {
        radar.direction.Zero();
        radar.obstacle = 0;
    }
}

void idObstacleAvoidance::ProjectTopDown(idVec3& point,
        const idVec3& startPos, const float scale) const {
    // The recovered implementation projects through the local player's view.
    // GameLib has no renderer/game-world dependency, so retain the same local
    // scale operation for callers that provide debug geometry.
    point = startPos + (point - startPos) * scale;
}

void idObstacleAvoidance::DrawBox(const idVec3&, const float) const {
    // Drawing is performed by the engine-facing debug consumer.  Keeping it
    // outside GameLib prevents the recovered navigation code from owning RW.
}

bool idObstacleAvoidance::SaveQuery(const char* const fileName) const {
    if (fileName == nullptr || *fileName == '\0' || buffers == nullptr) {
        return false;
    }
    idFileLocal file(fileSystem->OpenFileWrite(fileName, FSPATH_SAVE));
    if (file.file == nullptr) return false;
    if (file->WriteString(QUERY_IDENTIFIER) == 0) return false;
    return WriteValue(*file.file, testQuery.time)
        && WriteValue(*file.file, testQuery.gameMsPerFrame)
        && WriteValue(*file.file, testQuery.bbox)
        && WriteValue(*file.file, testQuery.gravity)
        && WriteValue(*file.file, testQuery.obstacleRadius)
        && WriteValue(*file.file, testQuery.frameMoveDist)
        && WriteValue(*file.file, testQuery.circleCornerRadius)
        && WriteValue(*file.file, testQuery.flags)
        && WriteValue(*file.file, buffers->numObstacles)
        && WriteValue(*file.file, buffers->numVertices)
        && WriteValue(*file.file, buffers->numEdges)
        && WriteValue(*file.file, buffers->numCorners)
        && WriteValue(*file.file, *buffers->route)
        && WriteArray(*file.file, buffers->obstacles,
            sizeof(*buffers->obstacles), buffers->numObstacles)
        && WriteArray(*file.file, buffers->vertices,
            sizeof(*buffers->vertices), buffers->numVertices)
        && WriteArray(*file.file, buffers->edges,
            sizeof(*buffers->edges), buffers->numEdges)
        && WriteArray(*file.file, buffers->corners,
            sizeof(*buffers->corners), buffers->numCorners);
}

bool idObstacleAvoidance::FindPathAroundObstacles(obstaclePath_t& path,
        const int time, const int gameMsPerFrame, const idBounds& bbox,
        const idVec3& gravity, const float obstacleRadius,
        const float frameMoveDist, const float cornerCircleRadius,
        const int queryFlags, const obstacleRoute_t& route,
        obstacleTraceSet_t* const traceSet) {
    const idVec3 start = route.numAreas > 0
        ? route.areas[0].start : idVec3();
    const idVec3 goal = route.numAreas > 0
        ? route.areas[route.numAreas - 1].end : start;
    path = obstaclePath_t();
    path.seekPos[0] = goal;
    path.seekPos[1] = goal;
    path.numSeekPos = 1;
    path.startPosOutsideObstacles = start;
    path.seekPosOutsideObstacles = goal;
    path.wallCorners[0] = goal;
    path.wallCorners[1] = goal;
    path.hasValidPath = true;
    path.startPosValid = true;
    path.seekPosValid = true;
    path.done = true;
    if (buffers == nullptr) return true;

    testQuery.time = time;
    testQuery.gameMsPerFrame = gameMsPerFrame;
    testQuery.bbox = bbox;
    testQuery.gravity = gravity;
    testQuery.obstacleRadius = obstacleRadius;
    testQuery.frameMoveDist = frameMoveDist;
    testQuery.circleCornerRadius = cornerCircleRadius;
    testQuery.flags = queryFlags;

    const int elapsed = time - lastUpdateTime;
    const bool preservePrevious = elapsed > 0
        && elapsed < 3 * gameMsPerFrame;
    if (preservePrevious && buffers->path != nullptr) {
        path = *buffers->path;
        lastDir = path.seekPos[0] - path.startPosOutsideObstacles;
        lastCorner = path.nextCorner;
    } else {
        lastDir.Zero();
        lastCorner.Set(0.0f, 0.0f, 0.0f, 0.0f);
    }
    lastUpdateTime = time;
    *buffers->route = route;

    if (traceSet != nullptr) {
        const int traceCount = (std::max)(0,
            (std::min)(MAX_TRACES, traceSet->numTraces));
        std::memcpy(buffers->traces, traceSet->traces,
            sizeof(obstacleTrace_t) * traceCount);
        buffers->numTraces = traceCount;
        if (preservePrevious) {
            const int previousCount = (std::max)(0,
                (std::min)(MAX_TRACES, traceSet->prevNumTraces));
            std::memcpy(buffers->traceFractions, traceSet->traceFractions,
                sizeof(float) * previousCount);
        }
    }

    obstacleParms_t& parms = *buffers->parms;
    parms.bbox = bbox;
    parms.gravity = gravity;
    parms.lastDir = lastDir;
    parms.lastCorner = lastCorner;
    parms.obstacleRadius = obstacleRadius;
    parms.frameMoveDist = frameMoveDist;
    parms.cornerCircleRadius = cornerCircleRadius;
    parms.flags = queryFlags;
    parms.numObstacles = buffers->numObstacles;
    parms.numVertices = buffers->numVertices;
    parms.numEdges = buffers->numEdges;
    parms.numCorners = buffers->numCorners;
    parms.numTraces = buffers->numTraces;
    parms.route = buffers->route;
    parms.obstacles = buffers->obstacles;
    parms.vertices = buffers->vertices;
    parms.edges = buffers->edges;
    parms.corners = buffers->corners;
    parms.traces = buffers->traces;
    parms.traceFractions = buffers->traceFractions;
    parms.path = buffers->path;

    std::vector<avoidDebugLine_t> debugLines(2048);
    std::vector<avoidDebugText_t> debugText(256);
    parms.debugLines = debugLines.data();
    parms.maxDebugLines = static_cast<int>(debugLines.size());
    parms.debugText = debugText.data();
    parms.maxDebugText = static_cast<int>(debugText.size());
    parms.path->done = false;
    parms.path->useRadarForward = path.useRadarForward;
    parms.path->radarForward = path.radarForward;
    RunObstacleAvoidanceJob(parms);
    parms.debugLines = nullptr;
    parms.debugText = nullptr;

    path = *buffers->path;
    if (traceSet != nullptr) {
        traceSet->prevNumTraces = buffers->numTraces;
        std::memcpy(traceSet->prevTraceNumbers, traceSet->traceNumbers,
            sizeof(int) * buffers->numTraces);
        std::memcpy(traceSet->traceFractions, buffers->traceFractions,
            sizeof(float) * buffers->numTraces);
    }
    return path.hasValidPath;
}

bool idObstacleAvoidance::TestQuery(const char* const fileName) {
    if (fileName == nullptr || *fileName == '\0') return false;
    AllocBuffers();
    if (buffers == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileRead(fileName, true, false));
    if (file.file == nullptr) return false;
    idStr identifier;
    if (file->ReadString(identifier) == 0
        || idStr::Cmp(identifier.c_str(), QUERY_IDENTIFIER) != 0) {
        return false;
    }
    if (!ReadValue(*file.file, testQuery.time)
        || !ReadValue(*file.file, testQuery.gameMsPerFrame)
        || !ReadValue(*file.file, testQuery.bbox)
        || !ReadValue(*file.file, testQuery.gravity)
        || !ReadValue(*file.file, testQuery.obstacleRadius)
        || !ReadValue(*file.file, testQuery.frameMoveDist)
        || !ReadValue(*file.file, testQuery.circleCornerRadius)
        || !ReadValue(*file.file, testQuery.flags)
        || !ReadValue(*file.file, buffers->numObstacles)
        || !ReadValue(*file.file, buffers->numVertices)
        || !ReadValue(*file.file, buffers->numEdges)
        || !ReadValue(*file.file, buffers->numCorners)) {
        return false;
    }
    if (buffers->numObstacles < 0 || buffers->numObstacles > MAX_OBSTACLES
        || buffers->numVertices < 0 || buffers->numVertices > MAX_VERTICES
        || buffers->numEdges < 0 || buffers->numEdges > MAX_EDGES
        || buffers->numCorners < 0 || buffers->numCorners > MAX_CORNERS) {
        return false;
    }
    if (!ReadValue(*file.file, *buffers->route)
        || !ReadArray(*file.file, buffers->obstacles,
            sizeof(*buffers->obstacles), buffers->numObstacles)
        || !ReadArray(*file.file, buffers->vertices,
            sizeof(*buffers->vertices), buffers->numVertices)
        || !ReadArray(*file.file, buffers->edges,
            sizeof(*buffers->edges), buffers->numEdges)
        || !ReadArray(*file.file, buffers->corners,
            sizeof(*buffers->corners), buffers->numCorners)) {
        return false;
    }
    obstaclePath_t path;
    return FindPathAroundObstacles(path, testQuery.time,
        testQuery.gameMsPerFrame, testQuery.bbox, testQuery.gravity,
        testQuery.obstacleRadius, testQuery.frameMoveDist,
        testQuery.circleCornerRadius, testQuery.flags, *buffers->route,
        nullptr);
}
