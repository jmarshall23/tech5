#include "models/static/staticmodelimport.h"

#include "idlib/filesystem/filesystem.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

namespace {

constexpr std::uint32_t FourCC(char a, char b, char c, char d) {
    return (static_cast<std::uint32_t>(a) << 24) |
        (static_cast<std::uint32_t>(b) << 16) |
        (static_cast<std::uint32_t>(c) << 8) |
        static_cast<std::uint32_t>(d);
}

std::uint16_t U2(const std::uint8_t* data) {
    return static_cast<std::uint16_t>((data[0] << 8) | data[1]);
}

std::int16_t S2(const std::uint8_t* data) {
    return static_cast<std::int16_t>(U2(data));
}

std::uint32_t U4(const std::uint8_t* data) {
    return (static_cast<std::uint32_t>(data[0]) << 24) |
        (static_cast<std::uint32_t>(data[1]) << 16) |
        (static_cast<std::uint32_t>(data[2]) << 8) |
        static_cast<std::uint32_t>(data[3]);
}

float F4(const std::uint8_t* data) {
    const std::uint32_t integer = U4(data);
    float result;
    std::memcpy(&result, &integer, sizeof(result));
    return result;
}

std::uint32_t VX(const std::uint8_t* data, std::size_t& cursor,
        const std::size_t end) {
    if (cursor + 2 > end) return 0;
    if (data[cursor] != 0xFF) {
        const std::uint32_t result = U2(data + cursor);
        cursor += 2;
        return result;
    }
    if (cursor + 4 > end) return 0;
    const std::uint32_t result = U4(data + cursor) & 0x00FFFFFFu;
    cursor += 4;
    return result;
}

std::string S0(const std::uint8_t* data, std::size_t& cursor,
        const std::size_t end) {
    const std::size_t start = cursor;
    while (cursor < end && data[cursor] != 0) ++cursor;
    std::string result(reinterpret_cast<const char*>(data + start),
        cursor - start);
    if (cursor < end) ++cursor;
    if ((cursor - start) & 1u) ++cursor;
    return result;
}

idVec3 Normalize(const idVec3& value) {
    const float length = value.LengthSqr();
    return length > 1.0e-30f
        ? value * (1.0f / std::sqrt(length))
        : idVec3(0.0f, 0.0f, 1.0f);
}

struct Polygon {
    std::vector<int> points;
    int surface = 0;
    unsigned int smoothingGroup = 0;
};

struct VMap {
    std::uint32_t type = 0;
    int dimension = 0;
    std::string name;
    std::unordered_map<int, std::vector<float>> pointValues;
    std::unordered_map<std::uint64_t, std::vector<float>> cornerValues;
};

struct ParsedLayer {
    int index = 0;
    std::string name;
    idVec3 pivot{0.0f, 0.0f, 0.0f};
    std::vector<idVec3> points;
    std::vector<Polygon> polygons;
    std::vector<VMap> vmaps;
};

struct SurfaceInfo {
    std::string name;
    float smoothingAngle = 0.0f;
    bool twoSided = false;
};

VMap* FindVMap(std::vector<VMap>& maps, const std::uint32_t type,
        const int dimension, const std::string& name) {
    for (VMap& map : maps)
        if (map.type == type && map.dimension == dimension && map.name == name)
            return &map;
    maps.push_back(VMap{});
    VMap& map = maps.back();
    map.type = type;
    map.dimension = dimension;
    map.name = name;
    return &map;
}

void ParseVMap(const std::uint8_t* data, const std::size_t begin,
        const std::size_t end, ParsedLayer& layer, const bool discontinuous) {
    if (begin + 6 > end) return;
    std::size_t cursor = begin;
    const std::uint32_t type = U4(data + cursor); cursor += 4;
    const int dimension = U2(data + cursor); cursor += 2;
    const std::string name = S0(data, cursor, end);
    VMap* map = FindVMap(layer.vmaps, type, dimension, name);
    while (cursor < end) {
        const int point = static_cast<int>(VX(data, cursor, end));
        int polygon = -1;
        if (discontinuous)
            polygon = static_cast<int>(VX(data, cursor, end));
        if (cursor + dimension * 4 > end) break;
        std::vector<float> values(static_cast<std::size_t>(dimension));
        for (int component = 0; component < dimension; ++component) {
            values[component] = F4(data + cursor);
            cursor += 4;
        }
        if (discontinuous) {
            const std::uint64_t key = (static_cast<std::uint64_t>(
                static_cast<unsigned int>(polygon)) << 32) |
                static_cast<unsigned int>(point);
            map->cornerValues[key] = std::move(values);
        } else {
            map->pointValues[point] = std::move(values);
        }
    }
}

const std::vector<float>* MapValue(const ParsedLayer& layer,
        const std::uint32_t type, const int point, const int polygon) {
    const std::uint64_t key = (static_cast<std::uint64_t>(
        static_cast<unsigned int>(polygon)) << 32) |
        static_cast<unsigned int>(point);
    for (const VMap& map : layer.vmaps) {
        if (map.type != type) continue;
        const auto corner = map.cornerValues.find(key);
        if (corner != map.cornerValues.end()) return &corner->second;
        const auto vertex = map.pointValues.find(point);
        if (vertex != map.pointValues.end()) return &vertex->second;
    }
    return nullptr;
}

void BuildImportLayer(const ParsedLayer& parsed,
        const std::vector<std::string>& tags,
        const std::vector<SurfaceInfo>& surfaces, const float scale,
        idImportModel& output) {
    output.materials.resize((std::max)(tags.size(), surfaces.size()));
    for (std::size_t index = 0; index < output.materials.size(); ++index) {
        output.materials[index].name = index < tags.size() ? tags[index]
            : surfaces[index].name;
        if (index < surfaces.size())
            output.materials[index].twoSided = surfaces[index].twoSided;
    }
    if (output.materials.empty())
        output.materials.push_back({"_default", "", false});

    const int positionBase = static_cast<int>(output.positions.size());
    for (const idVec3& point : parsed.points) {
        output.positions.push_back(idVec3(
            (point.x - parsed.pivot.x) * scale,
            (point.z - parsed.pivot.z) * scale,
            (point.y - parsed.pivot.y) * scale));
    }

    std::vector<idVec3> faceNormals(parsed.polygons.size());
    std::vector<std::vector<int>> adjacent(parsed.points.size());
    for (std::size_t polygon = 0; polygon < parsed.polygons.size(); ++polygon) {
        const Polygon& face = parsed.polygons[polygon];
        if (face.points.size() >= 3) {
            const idVec3& a = parsed.points[face.points[0]];
            const idVec3& b = parsed.points[face.points[1]];
            const idVec3& c = parsed.points[face.points[2]];
            const idVec3 sourceNormal = Normalize((b - a).Cross(c - a));
            faceNormals[polygon].Set(sourceNormal.x, sourceNormal.z,
                sourceNormal.y);
        }
        for (const int point : face.points)
            if (point >= 0 && point < static_cast<int>(adjacent.size()))
                adjacent[point].push_back(static_cast<int>(polygon));
    }

    for (std::size_t polygonIndex = 0;
         polygonIndex < parsed.polygons.size(); ++polygonIndex) {
        const Polygon& polygon = parsed.polygons[polygonIndex];
        for (std::size_t fan = 1; fan + 1 < polygon.points.size(); ++fan) {
            const int cornerIndices[3] = {0, static_cast<int>(fan),
                static_cast<int>(fan + 1)};
            idImportTriangle triangle;
            triangle.material = polygon.surface >= 0 &&
                    polygon.surface < static_cast<int>(output.materials.size())
                ? polygon.surface : 0;
            triangle.smoothingGroup = polygon.smoothingGroup;
            for (int corner = 0; corner < 3; ++corner) {
                const int point = polygon.points[cornerIndices[corner]];
                triangle.corners[corner].position = positionBase + point;
                const std::vector<float>* uv = MapValue(parsed,
                    FourCC('T','X','U','V'), point,
                    static_cast<int>(polygonIndex));
                if (uv != nullptr && uv->size() >= 2) {
                    triangle.corners[corner].texCoord =
                        static_cast<int>(output.texCoords.size());
                    output.texCoords.push_back(idVec2((*uv)[0],
                        1.0f - (*uv)[1]));
                }
                const std::vector<float>* color = MapValue(parsed,
                    FourCC('R','G','B','A'), point,
                    static_cast<int>(polygonIndex));
                if (color != nullptr && color->size() >= 3) {
                    const auto byte = [&](const std::size_t component,
                            const float fallback) {
                        const float value = component < color->size()
                            ? (*color)[component] : fallback;
                        return static_cast<std::uint32_t>((std::max)(0,
                            (std::min)(255, static_cast<int>(value * 255.0f +
                                0.5f))));
                    };
                    triangle.corners[corner].color =
                        static_cast<int>(output.colors.size());
                    output.colors.push_back(byte(0, 1.0f) |
                        (byte(1, 1.0f) << 8) | (byte(2, 1.0f) << 16) |
                        (byte(3, 1.0f) << 24));
                }
                const std::vector<float>* explicitNormal = MapValue(parsed,
                    FourCC('N','O','R','M'), point,
                    static_cast<int>(polygonIndex));
                idVec3 normal = faceNormals[polygonIndex];
                if (explicitNormal != nullptr && explicitNormal->size() >= 3) {
                    normal.Set((*explicitNormal)[0], (*explicitNormal)[2],
                        (*explicitNormal)[1]);
                    normal = Normalize(normal);
                } else if (point >= 0 &&
                        point < static_cast<int>(adjacent.size())) {
                    idVec3 average(0.0f, 0.0f, 0.0f);
                    for (const int neighbor : adjacent[point]) {
                        const Polygon& other = parsed.polygons[neighbor];
                        bool smooth = polygon.smoothingGroup != 0 &&
                            (polygon.smoothingGroup & other.smoothingGroup) != 0;
                        float angle = 0.0f;
                        if (polygon.surface >= 0 &&
                            polygon.surface < static_cast<int>(surfaces.size()))
                            angle = surfaces[polygon.surface].smoothingAngle;
                        if (!smooth && angle > 0.0f) {
                            const float cosine = faceNormals[polygonIndex].Dot(
                                faceNormals[neighbor]);
                            smooth = cosine >= std::cos(angle);
                        }
                        if (smooth || neighbor == static_cast<int>(polygonIndex))
                            average = average + faceNormals[neighbor];
                    }
                    normal = Normalize(average);
                }
                triangle.corners[corner].normal =
                    static_cast<int>(output.normals.size());
                output.normals.push_back(normal);
            }
            output.triangles.push_back(triangle);
        }
    }
}

lwObject* ParseObject(const std::uint8_t* data, const std::size_t size,
        const float scale, const bool forceLWOB, int* failId) {
    if (size < 12 || U4(data) != FourCC('F','O','R','M')) {
        if (failId != nullptr) *failId = 1;
        return nullptr;
    }
    const std::uint32_t form = U4(data + 8);
    const bool lwob = forceLWOB || form == FourCC('L','W','O','B') ||
        form == FourCC('L','W','L','O');
    if (!lwob && form != FourCC('L','W','O','2')) {
        if (failId != nullptr) *failId = 2;
        return nullptr;
    }

    std::vector<ParsedLayer> layers(1);
    ParsedLayer* layer = &layers[0];
    std::vector<std::string> tags;
    std::vector<SurfaceInfo> surfaces;
    std::size_t cursor = 12;
    while (cursor + 8 <= size) {
        const std::uint32_t chunk = U4(data + cursor);
        const std::uint32_t length = U4(data + cursor + 4);
        const std::size_t begin = cursor + 8;
        const std::size_t end = (std::min)(size, begin + length);
        if (chunk == FourCC('L','A','Y','R') && !lwob) {
            if (!layer->points.empty() || !layer->polygons.empty()) {
                layers.push_back(ParsedLayer{});
                layer = &layers.back();
            }
            if (begin + 16 <= end) {
                layer->index = U2(data + begin);
                layer->pivot.Set(F4(data + begin + 4),
                    F4(data + begin + 8), F4(data + begin + 12));
                std::size_t nameCursor = begin + 16;
                layer->name = S0(data, nameCursor, end);
            }
        } else if (chunk == FourCC('P','N','T','S')) {
            for (std::size_t point = begin; point + 12 <= end; point += 12)
                layer->points.emplace_back(F4(data + point),
                    F4(data + point + 4), F4(data + point + 8));
        } else if (chunk == FourCC('P','O','L','S')) {
            std::size_t point = begin;
            if (!lwob) {
                if (point + 4 > end) { cursor = end; continue; }
                const std::uint32_t polygonType = U4(data + point);
                point += 4;
                if (polygonType != FourCC('F','A','C','E') &&
                    polygonType != FourCC('P','T','C','H')) {
                    cursor = end + (length & 1u);
                    continue;
                }
            }
            while (point + 2 <= end) {
                const int count = U2(data + point) & 0x03FFu;
                point += 2;
                if (count <= 0) break;
                Polygon polygon;
                for (int vertex = 0; vertex < count; ++vertex) {
                    if (point >= end) break;
                    polygon.points.push_back(lwob
                        ? static_cast<int>(U2(data + point))
                        : static_cast<int>(VX(data, point, end)));
                    if (lwob) point += 2;
                }
                if (lwob && point + 2 <= end) {
                    const int surface = S2(data + point); point += 2;
                    polygon.surface = std::abs(surface) - 1;
                    if (surface < 0 && point + 2 <= end) {
                        const int detailCount = U2(data + point); point += 2;
                        for (int detail = 0; detail < detailCount &&
                             point + 2 <= end; ++detail) {
                            const int detailVertices = U2(data + point); point += 2;
                            point += detailVertices * 2 + 2;
                        }
                    }
                }
                layer->polygons.push_back(std::move(polygon));
            }
        } else if (chunk == FourCC('T','A','G','S') ||
                chunk == FourCC('S','R','F','S')) {
            std::size_t stringCursor = begin;
            while (stringCursor < end) {
                std::string value = S0(data, stringCursor, end);
                if (!value.empty()) tags.push_back(std::move(value));
            }
        } else if (chunk == FourCC('P','T','A','G') && !lwob &&
                begin + 4 <= end) {
            const std::uint32_t tagType = U4(data + begin);
            std::size_t entry = begin + 4;
            while (entry < end) {
                const int polygon = static_cast<int>(VX(data, entry, end));
                if (entry + 2 > end) break;
                const int value = U2(data + entry); entry += 2;
                if (polygon < 0 || polygon >=
                        static_cast<int>(layer->polygons.size())) continue;
                if (tagType == FourCC('S','U','R','F'))
                    layer->polygons[polygon].surface = value;
                else if (tagType == FourCC('S','M','G','P'))
                    layer->polygons[polygon].smoothingGroup = value < 32
                        ? 1u << value : static_cast<unsigned int>(value);
            }
        } else if (chunk == FourCC('V','M','A','P')) {
            ParseVMap(data, begin, end, *layer, false);
        } else if (chunk == FourCC('V','M','A','D')) {
            ParseVMap(data, begin, end, *layer, true);
        } else if (chunk == FourCC('S','U','R','F')) {
            std::size_t sub = begin;
            SurfaceInfo surface;
            surface.name = S0(data, sub, end);
            S0(data, sub, end); // source surface name
            while (sub + 6 <= end) {
                const std::uint32_t id = U4(data + sub);
                const int subLength = U2(data + sub + 4);
                const std::size_t payload = sub + 6;
                const std::size_t subEnd = (std::min)(end,
                    payload + static_cast<std::size_t>(subLength));
                if (id == FourCC('S','M','A','N') && payload + 4 <= subEnd)
                    surface.smoothingAngle = F4(data + payload);
                else if (id == FourCC('S','I','D','E') &&
                        payload + 2 <= subEnd)
                    surface.twoSided = U2(data + payload) == 3;
                sub = subEnd + (subLength & 1);
            }
            surfaces.push_back(std::move(surface));
        }
        cursor = begin + length + (length & 1u);
    }

    auto* object = new lwObject;
    lwLayer** tail = &object->layer;
    for (const ParsedLayer& parsed : layers) {
        if (parsed.points.empty() || parsed.polygons.empty()) continue;
        auto* outputLayer = new lwLayer;
        outputLayer->index = parsed.index;
        outputLayer->name = parsed.name;
        BuildImportLayer(parsed, tags, surfaces, scale, outputLayer->model);
        *tail = outputLayer;
        tail = &outputLayer->next;
        ++object->nlayers;
    }
    if (object->nlayers == 0) {
        delete object;
        if (failId != nullptr) *failId = 3;
        return nullptr;
    }
    if (failId != nullptr) *failId = 0;
    return object;
}

} // namespace

lwObject* lwGetObject(const char* fileName, const float scale,
        unsigned int* timestamp, int* failId) {
    if (fileSystem == nullptr || fileName == nullptr) return nullptr;
    void* buffer = nullptr;
    const int length = fileSystem->ReadFile(fileName, &buffer, timestamp);
    if (length < 0 || buffer == nullptr) return nullptr;
    lwObject* object = ParseObject(static_cast<const std::uint8_t*>(buffer),
        static_cast<std::size_t>(length), scale, false, failId);
    fileSystem->FreeFile(buffer);
    return object;
}

lwObject* lwGetObject5(const char* fileName, const float scale,
        unsigned int* timestamp, int* failId) {
    if (fileSystem == nullptr || fileName == nullptr) return nullptr;
    void* buffer = nullptr;
    const int length = fileSystem->ReadFile(fileName, &buffer, timestamp);
    if (length < 0 || buffer == nullptr) return nullptr;
    lwObject* object = ParseObject(static_cast<const std::uint8_t*>(buffer),
        static_cast<std::size_t>(length), scale, true, failId);
    fileSystem->FreeFile(buffer);
    return object;
}

void lwFreeLayer(lwLayer* layer) {
    while (layer != nullptr) {
        lwLayer* next = layer->next;
        delete layer;
        layer = next;
    }
}

void lwFreeObject(lwObject* object) {
    if (object == nullptr) return;
    lwFreeLayer(object->layer);
    delete object;
}

void lwForceSmoothSurfaces(lwObject* object, float) {
    if (object == nullptr) return;
    for (lwLayer* layer = object->layer; layer != nullptr;
         layer = layer->next) {
        for (idImportTriangle& triangle : layer->model.triangles)
            triangle.smoothingGroup = 1;
    }
}

