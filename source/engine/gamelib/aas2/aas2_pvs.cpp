#include "gamelib/aas2/aas2_local.h"

#include "gamelib/physics/clipmodel.h"

#include <algorithm>
#include <cstring>
#include <vector>

namespace {

constexpr int MAX_OBSTACLE_VERTICES = 0x300;
constexpr int MAX_OBSTACLE_EDGES = 0x200;
constexpr int MAX_OBSTACLE_MODELS = 128;

bool PVSIncludes(const std::uint8_t* const pvs, const int areaNum) {
    return pvs != nullptr && areaNum >= 0
        && (pvs[areaNum >> 3] & (1u << (areaNum & 7))) != 0;
}

} // namespace

void idAAS2Local::ShutdownObstaclePVS() {
    FreeClipLinks();
    delete[] obstaclePVS;
    delete[] areaClipModels;
    numObstaclePVSBytes = 0;
    obstaclePVS = nullptr;
    areaClipModels = nullptr;
    obstaclePVSAreaNum = 0;
}

int idAAS2Local::GetObstaclePVSWallEdges(const int areaNum,
        const int edgeFlags, int* const edges, const int maxEdges) const {
    return file != nullptr ? file->GetObstaclePVSWallEdges(areaNum,
        edgeFlags, edges, maxEdges) : 0;
}

void idAAS2Local::SetupObstaclePVS() {
    ShutdownObstaclePVS();
    if (file == nullptr || file->areas.IsEmpty()) return;
    numObstaclePVSBytes = (file->areas.Num() + 7) / 8;
    obstaclePVS = new std::uint8_t[numObstaclePVSBytes];
    std::memset(obstaclePVS, 0, numObstaclePVSBytes);
    areaClipModels = new idAASClipLink*[file->areas.Num()]();
}

void idAAS2Local::DecompressObstaclePVS(const int areaNum,
        std::uint8_t* const pvs, const int pvsSize) const {
    if (pvs == nullptr || pvsSize <= 0) return;
    std::memset(pvs, 0, pvsSize);
    if (file == nullptr || areaNum <= 0 || areaNum >= file->areas.Num())
        return;
    std::uint32_t offset = file->areas[areaNum].obstaclePVSOffset;
    int visibleArea = 0;
    while (offset < static_cast<std::uint32_t>(file->obstaclePVS.Num())
            && visibleArea < file->areas.Num()) {
        const std::uint8_t encoded = file->obstaclePVS[offset++];
        if ((encoded & 0x80u) != 0) {
            int skip = encoded & 0x3Fu;
            if ((encoded & 0x40u) != 0
                    && offset < static_cast<std::uint32_t>(
                        file->obstaclePVS.Num())) {
                skip |= static_cast<int>(file->obstaclePVS[offset++]) << 6;
            }
            visibleArea += skip + 1;
            continue;
        }
        for (int bit = 0; bit < 7 && visibleArea < file->areas.Num();
             ++bit, ++visibleArea) {
            if ((encoded & (1u << bit)) != 0
                    && (visibleArea >> 3) < pvsSize) {
                pvs[visibleArea >> 3] |= static_cast<std::uint8_t>(
                    1u << (visibleArea & 7));
            }
        }
    }
}

const std::uint8_t* idAAS2Local::GetObstaclePVS(const int areaNum) {
    if (obstaclePVS == nullptr) return nullptr;
    if (areaNum != obstaclePVSAreaNum) {
        DecompressObstaclePVS(areaNum, obstaclePVS, numObstaclePVSBytes);
        obstaclePVSAreaNum = areaNum;
    }
    return obstaclePVS;
}

void idAAS2Local::FreeClipLinks() {
    if (areaClipModels != nullptr && file != nullptr) {
        for (int areaNum = 0; areaNum < file->areas.Num(); ++areaNum)
            areaClipModels[areaNum] = nullptr;
    }
    clipModelLinkAllocator.Shutdown();
}

idAASClipLink* idAAS2Local::UnLinkClipModel(idAASClipLink* link) {
    while (link != nullptr) {
        idAASClipLink* const nextArea = link->nextArea;
        if (link->prevClip != nullptr)
            link->prevClip->nextClip = link->nextClip;
        else if (areaClipModels != nullptr && link->areaNum >= 0)
            areaClipModels[link->areaNum] = link->nextClip;
        if (link->nextClip != nullptr)
            link->nextClip->prevClip = link->prevClip;
        clipModelLinkAllocator.Free(link);
        link = nextArea;
    }
    return nullptr;
}

idAASClipLink* idAAS2Local::LinkClipModel(idClipModel* const model) {
    if (model == nullptr || file == nullptr || areaClipModels == nullptr)
        return nullptr;
    idBounds expanded = model->GetAbsBounds();
    expanded[0].x -= file->settings.boundingBox[1].x;
    expanded[0].y -= file->settings.boundingBox[1].y;
    expanded[0].z -= file->settings.boundingBox[1].z;
    expanded[1].x -= file->settings.boundingBox[0].x;
    expanded[1].y -= file->settings.boundingBox[0].y;
    expanded[1].z -= file->settings.boundingBox[0].z;

    std::vector<int> areas;
    int areaBuffer[128];
    for (int tree = 0; tree < file->trees.Num(); ++tree) {
        const int count = file->BoundsAreaNums(tree, expanded,
            areaBuffer, 128);
        for (int index = 0; index < count; ++index) {
            const int areaNum = areaBuffer[index];
            if (areaNum > 0 && areaNum < file->areas.Num()
                && std::find(areas.begin(), areas.end(), areaNum)
                    == areas.end()) areas.push_back(areaNum);
        }
    }
    std::sort(areas.begin(), areas.end(), std::greater<int>());
    idAASClipLink* first = nullptr;
    for (const int areaNum : areas) {
        idAASClipLink* const link = clipModelLinkAllocator.Alloc();
        if (link == nullptr) break;
        link->clipModel = model;
        link->areaNum = areaNum;
        link->prevArea = nullptr;
        link->nextArea = first;
        if (first != nullptr) first->prevArea = link;
        first = link;
        link->prevClip = nullptr;
        link->nextClip = areaClipModels[areaNum];
        if (link->nextClip != nullptr) link->nextClip->prevClip = link;
        areaClipModels[areaNum] = link;
    }
    return first;
}

int idAAS2Local::GetObstaclePVSClipModels(const int areaNum,
        idClipModel** const models, const int maxModels) {
    if (models == nullptr || maxModels <= 0 || areaClipModels == nullptr)
        return 0;
    const std::uint8_t* const pvs = GetObstaclePVS(areaNum);
    if (pvs == nullptr) return 0;
    int count = 0;
    for (int visibleArea = 1; visibleArea < file->areas.Num()
            && count < maxModels; ++visibleArea) {
        if (!PVSIncludes(pvs, visibleArea)) continue;
        for (idAASClipLink* link = areaClipModels[visibleArea];
             link != nullptr && count < maxModels; link = link->nextClip) {
            bool duplicate = false;
            for (int index = 0; index < count; ++index)
                if (models[index] == link->clipModel) duplicate = true;
            if (!duplicate) models[count++] = link->clipModel;
        }
    }
    return count;
}

void idAAS2Local::GetObstaclePVSObstaclesInternal(const int areaNum,
        const int edgeFlags, obstacleVertex_t* const vertices,
        int& numVertices, obstacleEdge_t* const edges, int& numEdges,
        idClipModel** const models, int& numModels,
        obstacleRoute_t* const route) const {
    numVertices = 0;
    numEdges = 0;
    numModels = 0;
    if (file == nullptr) return;
    int wallEdges[MAX_OBSTACLE_EDGES];
    const int wallCount = file->GetObstaclePVSWallEdges(areaNum,
        edgeFlags, wallEdges, MAX_OBSTACLE_EDGES);
    for (int index = 0; index < wallCount
            && numVertices + 2 <= MAX_OBSTACLE_VERTICES
            && numEdges < MAX_OBSTACLE_EDGES; ++index) {
        idVec3 start;
        idVec3 end;
        GetEdge(wallEdges[index], start, end);
        vertices[numVertices].position = start;
        vertices[numVertices + 1].position = end;
        obstacleEdge_t& edge = edges[numEdges++];
        edge.flags = GetEdgeFlags(wallEdges[index]);
        edge.verts[0] = static_cast<std::int16_t>(numVertices);
        edge.verts[1] = static_cast<std::int16_t>(numVertices + 1);
        edge.vertNums[0] = numVertices;
        edge.vertNums[1] = numVertices + 1;
        numVertices += 2;
    }
    numModels = const_cast<idAAS2Local*>(this)->GetObstaclePVSClipModels(
        areaNum, models, MAX_OBSTACLE_MODELS);
    if (route != nullptr && route->numAreas == 0) {
        route->numAreas = 1;
        route->areas[0].areaNum = areaNum;
        route->areas[0].start = AreaCenter(areaNum);
        route->areas[0].end = route->areas[0].start;
    }
}

void idAAS2Local::GetObstaclePVSObstacles(const int startAreaNum,
        const int edgeFlags, obstacleVertex_t* const vertices,
        int* const numVertices, obstacleEdge_t* const edges,
        int* const numEdges, idClipModel** const models,
        int* const numModels, obstacleRoute_t* const route) {
    if (numVertices == nullptr || numEdges == nullptr
        || numModels == nullptr) return;
    GetObstaclePVSObstaclesInternal(startAreaNum, edgeFlags, vertices,
        *numVertices, edges, *numEdges, models, *numModels, route);
}
