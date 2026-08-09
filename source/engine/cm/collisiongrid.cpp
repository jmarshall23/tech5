#include "cm/collisiongrid.h"

#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/lib_print.h"

#include <algorithm>
#include <cstdint>
#include <cstring>

namespace {

constexpr std::uint32_t COLLISION_GRID_MAGIC = 0x42434703u;

bool ReadBytes(idFile* const file, void* const data,
    const unsigned int size) {
    return file != nullptr && file->Read(data, size) == size;
}

bool ReadU8(idFile* const file, std::uint8_t& value) {
    return ReadBytes(file, &value, sizeof(value));
}

bool ReadU16BE(idFile* const file, std::uint16_t& value) {
    std::uint8_t bytes[2];
    if (!ReadBytes(file, bytes, sizeof(bytes))) {
        return false;
    }
    value = static_cast<std::uint16_t>(
        (static_cast<std::uint16_t>(bytes[0]) << 8) | bytes[1]);
    return true;
}

bool ReadI16BE(idFile* const file, std::int16_t& value) {
    std::uint16_t bits;
    if (!ReadU16BE(file, bits)) {
        return false;
    }
    value = static_cast<std::int16_t>(bits);
    return true;
}

bool ReadU32BE(idFile* const file, std::uint32_t& value) {
    std::uint8_t bytes[4];
    if (!ReadBytes(file, bytes, sizeof(bytes))) {
        return false;
    }
    value = (static_cast<std::uint32_t>(bytes[0]) << 24) |
        (static_cast<std::uint32_t>(bytes[1]) << 16) |
        (static_cast<std::uint32_t>(bytes[2]) << 8) |
        static_cast<std::uint32_t>(bytes[3]);
    return true;
}

bool ReadI32BE(idFile* const file, int& value) {
    std::uint32_t bits;
    if (!ReadU32BE(file, bits)) {
        return false;
    }
    value = static_cast<int>(bits);
    return true;
}

bool ReadFloatBE(idFile* const file, float& value) {
    std::uint32_t bits;
    if (!ReadU32BE(file, bits)) {
        return false;
    }
    std::memcpy(&value, &bits, sizeof(value));
    return true;
}

bool ReadBoundsShortBE(idFile* const file, idBoundsShort& bounds) {
    for (int side = 0; side < 2; ++side) {
        for (int axis = 0; axis < 3; ++axis) {
            if (!ReadI16BE(file, bounds.b[side][axis])) {
                return false;
            }
        }
    }
    return true;
}

bool ReadBoundsBE(idFile* const file, idBounds& bounds) {
    for (int side = 0; side < 2; ++side) {
        for (int axis = 0; axis < 3; ++axis) {
            if (!ReadFloatBE(file, bounds[side][axis])) {
                return false;
            }
        }
    }
    return true;
}

int FloorDivide(const int numerator, const int denominator) {
    const int quotient = numerator / denominator;
    const int remainder = numerator % denominator;
    return remainder < 0 ? quotient - 1 : quotient;
}

std::int64_t Cross(const idVec2i& a, const idVec2i& b,
    const idVec2i& c) {
    return static_cast<std::int64_t>(b.x - a.x) * (c.y - a.y) -
        static_cast<std::int64_t>(b.y - a.y) * (c.x - a.x);
}

bool PointOnSegment(const idVec2i& point, const idVec2i& start,
    const idVec2i& end) {
    return Cross(start, end, point) == 0 &&
        point.x >= (std::min)(start.x, end.x) &&
        point.x <= (std::max)(start.x, end.x) &&
        point.y >= (std::min)(start.y, end.y) &&
        point.y <= (std::max)(start.y, end.y);
}

bool SegmentsIntersect(const idVec2i& a, const idVec2i& b,
    const idVec2i& c, const idVec2i& d) {
    const std::int64_t abC = Cross(a, b, c);
    const std::int64_t abD = Cross(a, b, d);
    const std::int64_t cdA = Cross(c, d, a);
    const std::int64_t cdB = Cross(c, d, b);
    if (((abC < 0 && abD > 0) || (abC > 0 && abD < 0)) &&
        ((cdA < 0 && cdB > 0) || (cdA > 0 && cdB < 0))) {
        return true;
    }
    return (abC == 0 && PointOnSegment(c, a, b)) ||
        (abD == 0 && PointOnSegment(d, a, b)) ||
        (cdA == 0 && PointOnSegment(a, c, d)) ||
        (cdB == 0 && PointOnSegment(b, c, d));
}

bool PointInPolygon(const idVec2i& point, const idVec2i* const positions,
    const int num) {
    bool inside = false;
    for (int current = 0, previous = num - 1; current < num;
         previous = current++) {
        const idVec2i& a = positions[previous];
        const idVec2i& b = positions[current];
        if (PointOnSegment(point, a, b)) {
            return true;
        }
        if ((a.y > point.y) != (b.y > point.y)) {
            const double intersectionX = static_cast<double>(b.x - a.x) *
                    static_cast<double>(point.y - a.y) /
                    static_cast<double>(b.y - a.y) +
                static_cast<double>(a.x);
            if (static_cast<double>(point.x) < intersectionX) {
                inside = !inside;
            }
        }
    }
    return inside;
}

bool PolygonTouchesCell(const idVec2i* const positions, const int num,
    const int minX, const int minY, const int maxX, const int maxY) {
    for (int index = 0; index < num; ++index) {
        if (positions[index].x >= minX && positions[index].x <= maxX &&
            positions[index].y >= minY && positions[index].y <= maxY) {
            return true;
        }
    }

    const idVec2i corners[4] = {
        idVec2i(minX, minY), idVec2i(maxX, minY),
        idVec2i(maxX, maxY), idVec2i(minX, maxY)};
    for (const idVec2i& corner : corners) {
        if (PointInPolygon(corner, positions, num)) {
            return true;
        }
    }
    for (int current = 0, previous = num - 1; current < num;
         previous = current++) {
        for (int edge = 0; edge < 4; ++edge) {
            if (SegmentsIntersect(positions[previous], positions[current],
                    corners[edge], corners[(edge + 1) & 3])) {
                return true;
            }
        }
    }
    return false;
}

} // namespace

idResourceList idCollisionGridLocal::resourceList("cg");

idCollisionGridLocal::idCollisionGridLocal()
    : binaryTimeStamp(-1), sourceTimeStamp(-1) {
    grid.numX = 0;
    grid.numY = 0;
    grid.offset.Zero();
    grid.dimension = 0;
}

idCollisionGridLocal::~idCollisionGridLocal() {
    FreeData();
}

idResourceList* idCollisionGridLocal::GetResourceList() {
    return &resourceList;
}

void idCollisionGridLocal::CreateState(idCollisionGridState& state) {
    state.Create(grid.indices.Num(), nullptr);
    for (int index = 0; index < grid.indices.Num(); ++index) {
        if (grid.indices[index] == idGenGridModel::INVALID_INDEX) {
            state.Inactivate(static_cast<unsigned int>(index));
        } else {
            state.Activate(static_cast<unsigned int>(index));
        }
    }
}

bool idCollisionGridLocal::IsValid() const {
    return grid.parts.Num() != 0;
}

idStr idCollisionGridLocal::GetBinaryFileName(
    const char* const modelName) const {
    idStr result;
    if (modelName == nullptr) {
        return result;
    }
    if (_strnicmp(modelName, "maps/", 5) != 0) {
        char generatedName[256] = {};
        fileSystem->FixLongFilename("generated", "bcg", modelName,
            generatedName, sizeof(generatedName));
        result = generatedName;
    } else {
        result = modelName;
        result.SetFileExtension("bcg");
    }
    return result;
}

bool idCollisionGridLocal::ReloadIfStale() {
    const idStr binaryName = GetBinaryFileName(GetName());
    if (static_cast<int>(fileSystem->GetTimestamp(
            binaryName.c_str(), false)) == binaryTimeStamp) {
        if (_strnicmp(binaryName.c_str(), "maps/", 5) == 0 ||
            static_cast<int>(fileSystem->GetTimestamp(
                GetName(), false)) == sourceTimeStamp) {
            return false;
        }
        fileSystem->RemoveFile(binaryName.c_str(), FSPATH_BASE);
    }
    LoadResource();
    return true;
}

void idCollisionGridLocal::FreeData() {
    grid.indices.ClearFree();
    grid.vertices.ClearFree();
    grid.edges.ClearFree();
    grid.polygonEdges.ClearFree();
    grid.polygons.ClearFree();
    grid.parts.ClearFree();
    grid.nodes.ClearFree();
    grid.numX = 0;
    grid.numY = 0;
    grid.offset.Zero();
    grid.dimension = 0;
    binaryTimeStamp = -1;
    sourceTimeStamp = -1;
}

void idGridRasterize::RasterizePolygon(const idGenGridModel& grid,
    idCollisionGridState& state, const idVec2i* const positions,
    const int num) {
    if (positions == nullptr || num < 3 || grid.numX <= 0 ||
        grid.numY <= 0 || grid.dimension <= 0) {
        return;
    }

    int polygonMinX = positions[0].x;
    int polygonMaxX = positions[0].x;
    int polygonMinY = positions[0].y;
    int polygonMaxY = positions[0].y;
    for (int index = 1; index < num; ++index) {
        polygonMinX = (std::min)(polygonMinX, positions[index].x);
        polygonMaxX = (std::max)(polygonMaxX, positions[index].x);
        polygonMinY = (std::min)(polygonMinY, positions[index].y);
        polygonMaxY = (std::max)(polygonMaxY, positions[index].y);
    }

    const int firstX = (std::max)(0, FloorDivide(
        polygonMinX - grid.offset.x, grid.dimension));
    const int lastX = (std::min)(grid.numX - 1, FloorDivide(
        polygonMaxX - grid.offset.x, grid.dimension));
    const int firstY = (std::max)(0, FloorDivide(
        polygonMinY - grid.offset.y, grid.dimension));
    const int lastY = (std::min)(grid.numY - 1, FloorDivide(
        polygonMaxY - grid.offset.y, grid.dimension));

    for (int y = firstY; y <= lastY; ++y) {
        const int cellMinY = grid.offset.y + y * grid.dimension;
        const int cellMaxY = cellMinY + grid.dimension;
        for (int x = firstX; x <= lastX; ++x) {
            const int cellMinX = grid.offset.x + x * grid.dimension;
            const int cellMaxX = cellMinX + grid.dimension;
            if (PolygonTouchesCell(positions, num, cellMinX, cellMinY,
                    cellMaxX, cellMaxY)) {
                state.Inactivate(static_cast<unsigned int>(
                    x + y * grid.numX));
            }
        }
    }
}

void idCollisionGridLocal::InactivateFill(const idVec2i* const positions,
    const int num, idCollisionGridState& state) {
    idGridRasterize::RasterizePolygon(grid, state, positions, num);
}

bool idGenGridModel::LoadBinary(idFile* const file) {
    if (file == nullptr) {
        return false;
    }

    int counts[7] = {};
    for (int& count : counts) {
        if (!ReadI32BE(file, count) || count < 0) {
            return false;
        }
    }

    indices.ClearFree();
    vertices.ClearFree();
    edges.ClearFree();
    polygonEdges.ClearFree();
    polygons.ClearFree();
    parts.ClearFree();
    nodes.ClearFree();
    if (!vertices.SetNum(counts[0]) || !edges.SetNum(counts[1]) ||
        !polygonEdges.SetNum(counts[2]) || !polygons.SetNum(counts[3]) ||
        !parts.SetNum(counts[4]) || !indices.SetNum(counts[5]) ||
        !nodes.SetNum(counts[6])) {
        return false;
    }

    for (int index = 0; index < vertices.Num(); ++index) {
        idVec3& vertex = vertices[index];
        if (!ReadFloatBE(file, vertex.x) ||
            !ReadFloatBE(file, vertex.y) ||
            !ReadFloatBE(file, vertex.z)) {
            return false;
        }
    }
    for (int index = 0; index < edges.Num(); ++index) {
        cm_edge_t& edge = edges[index];
        if (!ReadU16BE(file, edge.vertexNum[0]) ||
            !ReadU16BE(file, edge.vertexNum[1])) {
            return false;
        }
    }
    for (int index = 0; index < polygonEdges.Num(); ++index) {
        if (!ReadU16BE(file, polygonEdges[index])) {
            return false;
        }
    }
    for (int index = 0; index < polygons.Num(); ++index) {
        cm_polygon_t& polygon = polygons[index];
        if (!ReadU8(file, polygon.material) ||
            !ReadU16BE(file, polygon.firstEdge) ||
            !ReadU8(file, polygon.numEdges) ||
            !ReadBoundsShortBE(file, polygon.bounds)) {
            return false;
        }
    }
    for (int index = 0; index < parts.Num(); ++index) {
        cm_gridPart_t& part = parts[index];
        if (!ReadBoundsShortBE(file, part.bounds) ||
            !ReadU16BE(file, part.nodeIndex) ||
            !ReadU16BE(file, part.firstPolygonIndex) ||
            !ReadU16BE(file, part.numPolygons)) {
            return false;
        }
    }
    for (int index = 0; index < indices.Num(); ++index) {
        if (!ReadU16BE(file, indices[index])) {
            return false;
        }
    }
    for (int index = 0; index < nodes.Num(); ++index) {
        cm_gridNodeBSP_t& node = nodes[index];
        std::uint8_t planeType;
        if (!ReadBoundsBE(file, node.bounds) ||
            !ReadFloatBE(file, node.planeDist) ||
            !ReadU16BE(file, node.children[0]) ||
            !ReadU16BE(file, node.children[1]) ||
            !ReadU8(file, planeType)) {
            return false;
        }
        node.planeType = static_cast<char>(planeType);
    }
    return ReadI32BE(file, numX) && ReadI32BE(file, numY) &&
        ReadI32BE(file, dimension) && ReadI32BE(file, offset.x) &&
        ReadI32BE(file, offset.y);
}

bool idCollisionGridLocal::Load_Binary() {
    const idStr binaryName = GetBinaryFileName(GetName());
    idFileLocal file(fileSystem->OpenFileRead(
        binaryName.c_str(), true, false));
    if (file.file == nullptr) {
        return false;
    }

    binaryTimeStamp = static_cast<int>(file->Timestamp());
    std::uint32_t magic;
    if (!ReadU32BE(file.file, magic) || magic != COLLISION_GRID_MAGIC) {
        idLibPrint::Warning("%s is not a binary collision grid file",
            binaryName.c_str());
        FreeData();
        return false;
    }
    if (!ReadI32BE(file.file, sourceTimeStamp) ||
        !grid.LoadBinary(file.file)) {
        return false;
    }
    return true;
}

bool idCollisionGridLocal::LoadBinary() {
    return Load_Binary();
}

void idCollisionGridLocal::LoadResource() {
    FreeData();
    Load_Binary();
}
