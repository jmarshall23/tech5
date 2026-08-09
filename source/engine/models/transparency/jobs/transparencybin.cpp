#include "models/transparency/jobs/transparencybin.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {

constexpr float BIN_SPLIT_EPSILON = 0.1f;
constexpr float BIN_VIEW_DISTANCE = 128.0f;
constexpr int BIN_WIDTH_PIXELS = 32;
constexpr int BIN_HEIGHT_PIXELS = 16;
constexpr int BIN_SCREEN_WIDTH =
    TRANSPARENCY_BIN_COLUMNS * BIN_WIDTH_PIXELS;
constexpr int BIN_SCREEN_HEIGHT =
    TRANSPARENCY_BIN_ROWS * BIN_HEIGHT_PIXELS;
constexpr int MAX_SPLIT_VERTS_PER_QUAD = 1724;

enum polygonSide_t {
    SIDE_FRONT = 0,
    SIDE_BACK = 1,
    SIDE_ON = 2
};

idPlane PlaneFromPoints(const idVec3& p1, const idVec3& p2,
    const idVec3& p3) {
    idVec3 normal = (p1 - p2).Cross(p3 - p2);
    if (normal.NormalizeFast() == 0.0f) {
        return idPlane(0.0f, 0.0f, 0.0f, 0.0f);
    }
    return idPlane(normal.x, normal.y, normal.z, -normal.Dot(p2));
}

polygonSide_t ClassifyPoint(float distance) {
    if (distance > BIN_SPLIT_EPSILON) {
        return SIDE_FRONT;
    }
    if (distance < -BIN_SPLIT_EPSILON) {
        return SIDE_BACK;
    }
    return SIDE_ON;
}

std::int16_t LerpShort(std::int16_t a, std::int16_t b, float fraction) {
    return static_cast<std::int16_t>(static_cast<int>(
        static_cast<float>(a) +
        static_cast<float>(static_cast<int>(b) - static_cast<int>(a)) *
            fraction));
}

idTransparencyVert InterpolateVertex(const idTransparencyVert& a,
    const idTransparencyVert& b, float fraction) {
    idTransparencyVert result = a;
    result.xyz = a.xyz + (b.xyz - a.xyz) * fraction;
    result.st[0] = LerpShort(a.st[0], b.st[0], fraction);
    result.st[1] = LerpShort(a.st[1], b.st[1], fraction);
    result.st1[0] = LerpShort(a.st1[0], b.st1[0], fraction);
    result.st1[1] = LerpShort(a.st1[1], b.st1[1], fraction);
    return result;
}

bool AppendPoint(polygon_t& polygon, std::uint16_t point) {
    if (polygon.numPoints >= 15) {
        return false;
    }
    polygon.points[polygon.numPoints++] = point;
    return true;
}

// Return values preserve the recovered routine: 0 is entirely on the
// positive side, 1 is entirely on the negative side, 2 is coplanar, and 3
// produced polygons on both sides.
int SplitPolygon(const polygon_t& polygon, const idPlane& plane,
    deferredTransparencyBinParms_t* parms, polygon_t& front,
    polygon_t& back) {
    if (polygon.numPoints == 0 || polygon.numPoints > 15) {
        return 2;
    }

    float distances[16] = {};
    polygonSide_t sides[16] = {};
    int counts[3] = {};
    for (int index = 0; index < polygon.numPoints; ++index) {
        const std::uint16_t vertexIndex = polygon.points[index];
        if (vertexIndex >= parms->numBinVerts) {
            return 2;
        }
        distances[index] = plane.Distance(
            parms->tempBinVerts[vertexIndex].xyz);
        sides[index] = ClassifyPoint(distances[index]);
        ++counts[sides[index]];
    }
    distances[polygon.numPoints] = distances[0];
    sides[polygon.numPoints] = sides[0];

    if (counts[SIDE_BACK] == 0) {
        if (counts[SIDE_FRONT] == 0) {
            return 2;
        }
        front = polygon;
        return 0;
    }
    if (counts[SIDE_FRONT] == 0) {
        back = polygon;
        return 1;
    }

    front.numPoints = 0;
    back.numPoints = 0;
    for (int index = 0; index < polygon.numPoints; ++index) {
        const std::uint16_t point = polygon.points[index];
        const polygonSide_t side = sides[index];
        const polygonSide_t nextSide = sides[index + 1];

        if (side == SIDE_ON) {
            if (!AppendPoint(front, point) || !AppendPoint(back, point)) {
                return 2;
            }
        } else if (side == SIDE_FRONT) {
            if (!AppendPoint(front, point)) {
                return 2;
            }
        } else if (!AppendPoint(back, point)) {
            return 2;
        }

        if (nextSide == SIDE_ON || nextSide == side) {
            continue;
        }
        if (parms->numBinVerts >= parms->maxBinVerts) {
            return 2;
        }

        const std::uint16_t nextPoint =
            polygon.points[(index + 1) % polygon.numPoints];
        const float fraction = distances[index] /
            (distances[index] - distances[index + 1]);
        const int splitIndex = parms->numBinVerts++;
        parms->tempBinVerts[splitIndex] = InterpolateVertex(
            parms->tempBinVerts[point], parms->tempBinVerts[nextPoint],
            fraction);
        if (!AppendPoint(front, static_cast<std::uint16_t>(splitIndex)) ||
            !AppendPoint(back, static_cast<std::uint16_t>(splitIndex))) {
            return 2;
        }
    }
    return 3;
}

void BinPolygon_r(deferredTransparencyBinParms_t* parms, int nodeNum,
    const polygon_t& polygon) {
    if (nodeNum == -1 || polygon.numPoints < 3) {
        return;
    }
    if (nodeNum < -1) {
        const int binIndex = -nodeNum - 2;
        if (binIndex < 0 || binIndex >= parms->numBins) {
            return;
        }
        bin_t& bin = parms->bins[binIndex];
        for (int index = 2; index < polygon.numPoints; ++index) {
            const int ringOffset =
                bin.numIndices % TRANSPARENCY_BIN_RING_INDICES;
            bin.indices[ringOffset] = polygon.points[0];
            bin.indices[ringOffset + 1] = polygon.points[index - 1];
            bin.indices[ringOffset + 2] = polygon.points[index];
            bin.numIndices += 3;
        }
        return;
    }
    if (nodeNum >= parms->numNodes) {
        return;
    }

    const node_t& node = parms->nodes[nodeNum];
    polygon_t front = {};
    polygon_t back = {};
    switch (SplitPolygon(polygon, node.plane, parms, front, back)) {
        case 0:
            BinPolygon_r(parms, node.children[0], front);
            break;
        case 1:
            BinPolygon_r(parms, node.children[1], back);
            break;
        case 3:
            BinPolygon_r(parms, node.children[0], front);
            BinPolygon_r(parms, node.children[1], back);
            break;
        default:
            break;
    }
}

int BuildBinTree_r(deferredTransparencyBinParms_t* parms,
    const idVec3 screenVerts[4], int offsetX, int partitionsX,
    int offsetY, int partitionsY) {
    if (partitionsX <= 1 && partitionsY <= 1) {
        const int binIndex = (offsetY / BIN_HEIGHT_PIXELS) *
            TRANSPARENCY_BIN_COLUMNS + offsetX / BIN_WIDTH_PIXELS;
        if (binIndex < 0 || binIndex >= TRANSPARENCY_BIN_COUNT) {
            return -1;
        }
        parms->bins[binIndex].numIndices = 0;
        return -2 - binIndex;
    }
    if (parms->numNodes >= TRANSPARENCY_BIN_NODE_COUNT) {
        return -1;
    }

    const int nodeIndex = parms->numNodes++;
    node_t& node = parms->nodes[nodeIndex];
    if (partitionsX > 1) {
        const int leftPartitions = partitionsX / 2;
        const int splitX = offsetX + leftPartitions * BIN_WIDTH_PIXELS;
        const float fraction = static_cast<float>(splitX) /
            static_cast<float>(BIN_SCREEN_WIDTH);
        const idVec3 bottom = screenVerts[0] +
            (screenVerts[1] - screenVerts[0]) * fraction;
        const idVec3 top = bottom + (screenVerts[2] - screenVerts[0]);
        node.plane = PlaneFromPoints(parms->viewOrigin, bottom, top);
        node.children[0] = BuildBinTree_r(parms, screenVerts, splitX,
            partitionsX - leftPartitions, offsetY, partitionsY);
        node.children[1] = BuildBinTree_r(parms, screenVerts, offsetX,
            leftPartitions, offsetY, partitionsY);
    } else {
        const int lowerPartitions = partitionsY / 2;
        const int splitY = offsetY + lowerPartitions * BIN_HEIGHT_PIXELS;
        const float fraction = static_cast<float>(splitY) /
            static_cast<float>(BIN_SCREEN_HEIGHT);
        const idVec3 left = screenVerts[0] +
            (screenVerts[2] - screenVerts[0]) * fraction;
        const idVec3 right = left + (screenVerts[1] - screenVerts[0]);
        node.plane = PlaneFromPoints(parms->viewOrigin, right, left);
        node.children[0] = BuildBinTree_r(parms, screenVerts, offsetX,
            partitionsX, splitY, partitionsY - lowerPartitions);
        node.children[1] = BuildBinTree_r(parms, screenVerts, offsetX,
            partitionsX, offsetY, lowerPartitions);
    }
    return nodeIndex;
}

bool InstallOuterNode(deferredTransparencyBinParms_t* parms,
    const idPlane& plane) {
    if (parms->numNodes >= TRANSPARENCY_BIN_NODE_COUNT) {
        return false;
    }
    node_t& node = parms->nodes[parms->numNodes++];
    node.plane = plane;
    node.children[0] = parms->numNodes;
    node.children[1] = -1;
    return true;
}

} // namespace

void BinQuads(deferredTransparencyBinParms_t* parms) {
    if (parms == nullptr || parms->verts == nullptr ||
        parms->indices == nullptr || parms->bins == nullptr ||
        parms->nodes == nullptr || parms->tempBinVerts == nullptr ||
        parms->vertexRemap == nullptr || parms->binVerts == nullptr ||
        parms->binIndices == nullptr || parms->numVerts <= 0 ||
        parms->numIndices <= 0 || parms->maxBinVerts <= 0 ||
        parms->maxBinIndices <= 0) {
        return;
    }

    parms->numNodes = 0;
    parms->numBins = TRANSPARENCY_BIN_COUNT;
    parms->numBinVerts = 0;
    parms->numBinIndices = 0;

    const idVec3 center = parms->viewOrigin +
        parms->viewAxis[0] * BIN_VIEW_DISTANCE;
    const idVec3 horizontal = parms->viewAxis[1] *
        (parms->fovX * BIN_VIEW_DISTANCE);
    const idVec3 vertical = parms->viewAxis[2] *
        (parms->fovY * BIN_VIEW_DISTANCE);
    idVec3 screenVerts[4];
    screenVerts[0] = center - horizontal - vertical;
    screenVerts[1] = center + horizontal - vertical;
    screenVerts[2] = center - horizontal + vertical;
    screenVerts[3] = center + horizontal + vertical;

    if (!InstallOuterNode(parms, PlaneFromPoints(parms->viewOrigin,
            screenVerts[1], screenVerts[0])) ||
        !InstallOuterNode(parms, PlaneFromPoints(parms->viewOrigin,
            screenVerts[0], screenVerts[2])) ||
        !InstallOuterNode(parms, PlaneFromPoints(parms->viewOrigin,
            screenVerts[2], screenVerts[3])) ||
        !InstallOuterNode(parms, PlaneFromPoints(parms->viewOrigin,
            screenVerts[3], screenVerts[1]))) {
        return;
    }
    parms->nodes[3].children[0] = BuildBinTree_r(parms, screenVerts,
        0, TRANSPARENCY_BIN_COLUMNS, 0, TRANSPARENCY_BIN_ROWS);

    for (int indexOffset = 0; indexOffset + 5 < parms->numIndices;
         indexOffset += 6) {
        if (parms->numBinVerts + 4 > parms->maxBinVerts) {
            break;
        }
        const int firstVertex = parms->indices[indexOffset];
        if (firstVertex < 0 || firstVertex + 3 >= parms->numVerts) {
            continue;
        }

        polygon_t polygon = {};
        polygon.numPoints = 4;
        const int sourceOrder[4] = {
            firstVertex + 2, firstVertex + 3,
            firstVertex + 1, firstVertex
        };
        for (int point = 0; point < 4; ++point) {
            const int destination = parms->numBinVerts++;
            parms->tempBinVerts[destination] =
                parms->verts[sourceOrder[point]];
            polygon.points[point] = static_cast<std::uint16_t>(destination);
        }
        BinPolygon_r(parms, 0, polygon);
        if (parms->numBinVerts >=
            parms->maxBinVerts - MAX_SPLIT_VERTS_PER_QUAD) {
            break;
        }
    }

    std::fill(parms->vertexRemap,
        parms->vertexRemap + parms->numBinVerts, -1);
    int compactVertexCount = 0;
    for (int binIndex = 0; binIndex < parms->numBins; ++binIndex) {
        const bin_t& bin = parms->bins[binIndex];
        const int firstRetained = std::max(0,
            bin.numIndices - TRANSPARENCY_BIN_RING_INDICES);
        for (int source = bin.numIndices - 3;
             source >= firstRetained; source -= 3) {
            if (parms->numBinIndices + 3 > parms->maxBinIndices) {
                break;
            }
            const int ringOffset =
                source % TRANSPARENCY_BIN_RING_INDICES;
            std::uint16_t compactTriangle[3];
            bool valid = true;
            for (int corner = 0; corner < 3; ++corner) {
                const int original = bin.indices[ringOffset + corner];
                if (original < 0 || original >= parms->numBinVerts) {
                    valid = false;
                    break;
                }
                int& remapped = parms->vertexRemap[original];
                if (remapped == -1) {
                    remapped = compactVertexCount++;
                }
                compactTriangle[corner] =
                    static_cast<std::uint16_t>(remapped);
            }
            if (!valid) {
                continue;
            }
            for (int corner = 0; corner < 3; ++corner) {
                parms->binIndices[parms->numBinIndices++] =
                    compactTriangle[corner];
            }
        }
        if (parms->numBinIndices >= parms->maxBinIndices) {
            break;
        }
    }

    for (int original = 0; original < parms->numBinVerts; ++original) {
        const int remapped = parms->vertexRemap[original];
        if (remapped >= 0) {
            parms->binVerts[remapped] = parms->tempBinVerts[original];
        }
    }
}
