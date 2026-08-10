#include "models/static/staticmodelgenerator.h"

#include "idlib/filesystem/filesystem.h"
#include "models/static/staticmodel.h"
#include "models/static/staticmodelimport.h"
#include "models/static/staticmodeltristrips.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <limits>
#include <new>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace {

constexpr float DEFAULT_VERTEX_SLOP = 0.01f;
constexpr float DEFAULT_TEXCOORD_SLOP = 0.0001f;
constexpr float DEFAULT_NORMAL_SLOP = 0.0001f;
constexpr unsigned int TRIANGLE_STRIP_VERTEX_MASK = 0x200u;

idVec3 Normalize(const idVec3& value) {
    const float lengthSquared = value.LengthSqr();
    return lengthSquared > 1.0e-30f
        ? value * (1.0f / std::sqrt(lengthSquared))
        : idVec3(0.0f, 0.0f, 1.0f);
}

idVec3 FaceNormal(const idImportModel& model,
        const idImportTriangle& triangle) {
    const int a = triangle.corners[0].position;
    const int b = triangle.corners[1].position;
    const int c = triangle.corners[2].position;
    if (a < 0 || b < 0 || c < 0 ||
        a >= static_cast<int>(model.positions.size()) ||
        b >= static_cast<int>(model.positions.size()) ||
        c >= static_cast<int>(model.positions.size()))
        return idVec3(0.0f, 0.0f, 1.0f);
    return Normalize((model.positions[b] - model.positions[a]).Cross(
        model.positions[c] - model.positions[a]));
}

bool ValidTriangle(const idImportModel& model,
        const idImportTriangle& triangle) {
    for (const idImportCorner& corner : triangle.corners) {
        if (corner.position < 0 ||
            corner.position >= static_cast<int>(model.positions.size()))
            return false;
    }
    return triangle.corners[0].position != triangle.corners[1].position &&
        triangle.corners[0].position != triangle.corners[2].position &&
        triangle.corners[1].position != triangle.corners[2].position;
}

template<class Vector>
float DistanceSquared(const Vector& a, const Vector& b) {
    float result = 0.0f;
    for (int component = 0;
         component < static_cast<int>(sizeof(Vector) / sizeof(float));
         ++component) {
        const float delta = a[component] - b[component];
        result += delta * delta;
    }
    return result;
}

struct WeldCell {
    long long x;
    long long y;
    long long z;

    bool operator==(const WeldCell& rhs) const {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }
};

struct WeldCellHash {
    std::size_t operator()(const WeldCell& value) const {
        std::size_t hash = std::hash<long long>{}(value.x);
        hash ^= std::hash<long long>{}(value.y) + 0x9e3779b9u +
            (hash << 6) + (hash >> 2);
        hash ^= std::hash<long long>{}(value.z) + 0x9e3779b9u +
            (hash << 6) + (hash >> 2);
        return hash;
    }
};

template<class Vector>
void BuildRemapTablePortable(idList<int, 5>& remap,
        const idList<Vector, 5>& vectors, const float epsilon) {
    remap.SetNum(vectors.Num());
    if (epsilon <= 0.0f) {
        for (int index = 0; index < vectors.Num(); ++index)
            remap[index] = index;
        return;
    }
    const float epsilonSquared = epsilon * epsilon;
    constexpr int dimensions = static_cast<int>(
        sizeof(Vector) / sizeof(float));
    std::unordered_map<WeldCell, std::vector<int>, WeldCellHash> cells;
    cells.reserve(static_cast<std::size_t>(vectors.Num()));
    for (int index = 0; index < vectors.Num(); ++index) {
        int match = index;
        const WeldCell cell{
            static_cast<long long>(std::floor(vectors[index][0] / epsilon)),
            static_cast<long long>(std::floor(vectors[index][1] / epsilon)),
            dimensions > 2 ? static_cast<long long>(std::floor(
                vectors[index][2] / epsilon)) : 0
        };
        for (int z = dimensions > 2 ? -1 : 0;
             z <= (dimensions > 2 ? 1 : 0); ++z) {
            for (int y = -1; y <= 1; ++y) {
                for (int x = -1; x <= 1; ++x) {
                    const auto found = cells.find({cell.x + x, cell.y + y,
                        cell.z + z});
                    if (found == cells.end()) continue;
                    for (const int candidate : found->second) {
                        if (candidate >= match) continue;
                        if (DistanceSquared(vectors[index],
                                vectors[candidate]) <= epsilonSquared)
                            match = remap[candidate];
                    }
                }
            }
        }
        remap[index] = match;
        cells[cell].push_back(index);
    }
}

void CopyToIdList(const std::vector<idVec3>& source,
        idList<idVec3, 5>& destination) {
    destination.SetNum(static_cast<int>(source.size()));
    for (int index = 0; index < destination.Num(); ++index)
        destination[index] = source[static_cast<std::size_t>(index)];
}

void CopyToIdList(const std::vector<idVec2>& source,
        idList<idVec2, 5>& destination) {
    destination.SetNum(static_cast<int>(source.size()));
    for (int index = 0; index < destination.Num(); ++index)
        destination[index] = source[static_cast<std::size_t>(index)];
}

void DeleteGeneratedGeometry(idTriangles* geometry) {
    if (geometry == nullptr) return;
    delete[] geometry->verts;
    delete[] geometry->indexes;
    geometry->verts = nullptr;
    geometry->indexes = nullptr;
    delete geometry;
}

void ClearModelGeometry(idStaticModel& model) {
    model.FreeSurfaces();
}

std::vector<idVec3> BuildCornerNormals(const idImportModel& source) {
    const std::size_t triangleCount = source.triangles.size();
    std::vector<idVec3> faceNormals(triangleCount);
    std::vector<std::vector<int>> adjacency(source.positions.size());
    for (std::size_t triangle = 0; triangle < triangleCount; ++triangle) {
        faceNormals[triangle] = FaceNormal(source, source.triangles[triangle]);
        if (!ValidTriangle(source, source.triangles[triangle])) continue;
        for (const idImportCorner& corner : source.triangles[triangle].corners)
            adjacency[static_cast<std::size_t>(corner.position)].push_back(
                static_cast<int>(triangle));
    }

    std::vector<idVec3> result(triangleCount * 3);
    for (std::size_t triangle = 0; triangle < triangleCount; ++triangle) {
        const idImportTriangle& current = source.triangles[triangle];
        for (int cornerIndex = 0; cornerIndex < 3; ++cornerIndex) {
            const idImportCorner& corner = current.corners[cornerIndex];
            if (corner.normal >= 0 &&
                corner.normal < static_cast<int>(source.normals.size())) {
                result[triangle * 3 + cornerIndex] = Normalize(
                    source.normals[static_cast<std::size_t>(corner.normal)]);
                continue;
            }
            if (corner.position < 0 ||
                corner.position >= static_cast<int>(adjacency.size()) ||
                current.smoothingGroup == 0) {
                result[triangle * 3 + cornerIndex] = faceNormals[triangle];
                continue;
            }
            idVec3 accumulated(0.0f, 0.0f, 0.0f);
            for (const int adjacent :
                    adjacency[static_cast<std::size_t>(corner.position)]) {
                const unsigned int group = source.triangles[
                    static_cast<std::size_t>(adjacent)].smoothingGroup;
                if (group != 0 && (group & current.smoothingGroup) != 0)
                    accumulated = accumulated + faceNormals[
                        static_cast<std::size_t>(adjacent)];
            }
            result[triangle * 3 + cornerIndex] = Normalize(accumulated);
        }
    }
    return result;
}

int SafeMaterialIndex(const idImportModel& source, const int index) {
    return index >= 0 && index < static_cast<int>(source.materials.size())
        ? index : 0;
}

int StripMaterialNumber(std::string& name) {
    const std::size_t separator = name.find('&');
    if (separator == std::string::npos || separator + 1 >= name.size())
        return -1;
    char* end = nullptr;
    const long number = std::strtol(name.c_str() + separator + 1, &end, 10);
    if (end == name.c_str() + separator + 1 || *end != '\0' ||
        number < (std::numeric_limits<int>::min)() ||
        number > (std::numeric_limits<int>::max)()) return -1;
    name.erase(separator);
    return static_cast<int>(number);
}

void AppendImportModel(idImportModel& destination,
        const idImportModel& source) {
    const int positionBase = static_cast<int>(destination.positions.size());
    const int texCoordBase = static_cast<int>(destination.texCoords.size());
    const int normalBase = static_cast<int>(destination.normals.size());
    const int colorBase = static_cast<int>(destination.colors.size());
    const int materialBase = static_cast<int>(destination.materials.size());
    destination.positions.insert(destination.positions.end(),
        source.positions.begin(), source.positions.end());
    destination.texCoords.insert(destination.texCoords.end(),
        source.texCoords.begin(), source.texCoords.end());
    destination.normals.insert(destination.normals.end(),
        source.normals.begin(), source.normals.end());
    destination.colors.insert(destination.colors.end(),
        source.colors.begin(), source.colors.end());
    destination.materials.insert(destination.materials.end(),
        source.materials.begin(), source.materials.end());
    for (idImportTriangle triangle : source.triangles) {
        triangle.material = triangle.material >= 0
            ? triangle.material + materialBase : triangle.material;
        for (idImportCorner& corner : triangle.corners) {
            if (corner.position >= 0) corner.position += positionBase;
            if (corner.texCoord >= 0) corner.texCoord += texCoordBase;
            if (corner.normal >= 0) corner.normal += normalBase;
            if (corner.color >= 0) corner.color += colorBase;
        }
        destination.triangles.push_back(triangle);
    }
}

bool GeometryCanMerge(const idStaticModelSurface& a,
        const idStaticModelSurface& b) {
    if (a.material != b.material || a.materialNum != b.materialNum ||
        a.geometry == nullptr || b.geometry == nullptr) return false;
    const idTriangles& ga = *a.geometry;
    const idTriangles& gb = *b.geometry;
    return ga.verts != nullptr && ga.indexes != nullptr &&
        gb.verts != nullptr && gb.indexes != nullptr &&
        ga.numVerts + gb.numVerts <= 0x7FFF;
}

void AppendGeometry(idStaticModelSurface& destination,
        idStaticModelSurface& source) {
    idTriangles* a = destination.geometry;
    idTriangles* b = source.geometry;
    const int oldVerts = a->numVerts;
    const int oldIndexes = a->numIndexes;
    idDrawVert* vertices = new idDrawVert[oldVerts + b->numVerts];
    std::uint16_t* indexes = new std::uint16_t[oldIndexes + b->numIndexes];
    std::memcpy(vertices, a->verts, oldVerts * sizeof(idDrawVert));
    std::memcpy(vertices + oldVerts, b->verts,
        b->numVerts * sizeof(idDrawVert));
    std::memcpy(indexes, a->indexes,
        oldIndexes * sizeof(std::uint16_t));
    for (int index = 0; index < b->numIndexes; ++index)
        indexes[oldIndexes + index] = static_cast<std::uint16_t>(
            b->indexes[index] + oldVerts);
    delete[] a->verts;
    delete[] a->indexes;
    a->verts = vertices;
    a->indexes = indexes;
    a->numVerts += b->numVerts;
    a->numIndexes += b->numIndexes;
    for (int axis = 0; axis < 3; ++axis) {
        a->bounds[0][axis] = (std::min)(a->bounds[0][axis],
            b->bounds[0][axis]);
        a->bounds[1][axis] = (std::max)(a->bounds[1][axis],
            b->bounds[1][axis]);
    }
    DeleteGeneratedGeometry(b);
    source.geometry = nullptr;
}

} // namespace

void BuildRemapTable(idList<int, 5>& remap,
        const idList<idVec3, 5>& vectors, const float epsilon) {
    BuildRemapTablePortable(remap, vectors, epsilon);
}

void BuildRemapTable(idList<int, 5>& remap,
        const idList<idVec2, 5>& vectors, const float epsilon) {
    BuildRemapTablePortable(remap, vectors, epsilon);
}

bool ConvertImportModelToStaticModel(idStaticModel& destination,
        const idImportModel& source, const float vertexSlop,
        const float texCoordSlop, const bool append) {
    if (source.positions.empty() || source.triangles.empty()) return false;
    if (!append) ClearModelGeometry(destination);

    idList<idVec3, 5> positions;
    idList<idVec2, 5> texCoords;
    CopyToIdList(source.positions, positions);
    CopyToIdList(source.texCoords, texCoords);
    if (texCoords.Num() == 0) texCoords.Append(idVec2(0.0f, 0.0f));
    idList<idVec3, 5> morphPositions;
    morphPositions.Append(idVec3(0.0f, 0.0f, 0.0f));
    idList<int, 5> positionRemap;
    idList<int, 5> texCoordRemap;
    BuildRemapTable(positionRemap, positions, vertexSlop);
    BuildRemapTable(texCoordRemap, texCoords, texCoordSlop);

    const int materialCount = (std::max)(1,
        static_cast<int>(source.materials.size()));
    idList<idStr, 5> materialNames;
    materialNames.SetNum(materialCount);
    for (int material = 0; material < materialCount; ++material) {
        materialNames[material] = material <
                static_cast<int>(source.materials.size())
            ? source.materials[static_cast<std::size_t>(material)].name.c_str()
            : "_default";
    }
    idList<const idMaterial*, 5> resolvedMaterials;
    idList<int, 5> mergeTo;
    idList<const idMaterial*, 5> uniqueMaterials;
    idList<int, 5> uniqueMaterialNumbers;
    destination.BuildMergeList(materialNames, resolvedMaterials, mergeTo,
        uniqueMaterials, uniqueMaterialNumbers);
    idList<idRawSurface, 5> rawSurfaces;
    rawSurfaces.SetNum(uniqueMaterials.Num());
    for (int material = 0; material < uniqueMaterials.Num(); ++material) {
        idRawSurface& raw = rawSurfaces[material];
        raw.material = uniqueMaterials[material];
        raw.materialNum = uniqueMaterialNumbers[material];
        raw.generateNormals = false;
        raw.normalEpsilon = 1.0f - DEFAULT_NORMAL_SLOP;
        raw.InitHash(positions, texCoords, morphPositions);
        raw.InitIndex(static_cast<int>(source.triangles.size() * 3));
    }

    const std::vector<idVec3> cornerNormals = BuildCornerNormals(source);
    int validTriangles = 0;
    for (std::size_t triangleIndex = 0;
         triangleIndex < source.triangles.size(); ++triangleIndex) {
        const idImportTriangle& triangle = source.triangles[triangleIndex];
        if (!ValidTriangle(source, triangle)) continue;
        const int material = SafeMaterialIndex(source, triangle.material);
        const int mergedMaterial = material >= 0 && material < mergeTo.Num()
            ? mergeTo[material] : 0;
        idRawSurface& raw = rawSurfaces[(std::max)(0,
            (std::min)(mergedMaterial, rawSurfaces.Num() - 1))];
        for (int cornerIndex = 0; cornerIndex < 3; ++cornerIndex) {
            const idImportCorner& corner = triangle.corners[cornerIndex];
            const int position = positionRemap[corner.position];
            int texCoord = 0;
            if (corner.texCoord >= 0 && corner.texCoord < texCoordRemap.Num())
                texCoord = texCoordRemap[corner.texCoord];
            const unsigned int color = corner.color >= 0 &&
                    corner.color < static_cast<int>(source.colors.size())
                ? source.colors[static_cast<std::size_t>(corner.color)]
                : 0xFFFFFFFFu;
            raw.AddVert(position, texCoord,
                cornerNormals[triangleIndex * 3 + cornerIndex], color, 0);
        }
        ++validTriangles;
    }
    if (validTriangles == 0) return false;
    EmitRawSurfacesToStaticModel(rawSurfaces, destination);
    return destination.surfaces.Num() > 0;
}

void idStaticModel::BuildMergeList(
        const idList<idStr, 5>& materialNames,
        idList<const idMaterial*, 5>& resolvedMaterials,
        idList<int, 5>& mergeTo,
        idList<const idMaterial*, 5>& uniqueMaterials,
        idList<int, 5>& uniqueMaterialNumbers) {
    const int count = materialNames.Num();
    resolvedMaterials.SetNum(count);
    mergeTo.SetNum(count);
    uniqueMaterials.SetNum(count);
    uniqueMaterialNumbers.SetNum(count);
    std::vector<std::string> strippedNames(static_cast<std::size_t>(count));
    bool hasNumberedMaterial = false;
    for (int index = 0; index < count; ++index) {
        strippedNames[static_cast<std::size_t>(index)] =
            materialNames[index].c_str();
        const int number = StripMaterialNumber(
            strippedNames[static_cast<std::size_t>(index)]);
        const idMaterial* const material = ResolveMaterial(
            strippedNames[static_cast<std::size_t>(index)].c_str());
        resolvedMaterials[index] = material;
        uniqueMaterials[index] = material;
        uniqueMaterialNumbers[index] = number;
        mergeTo[index] = index;
        hasNumberedMaterial = hasNumberedMaterial || number >= 0;
    }
    if (hasNumberedMaterial) {
        std::vector<int> order(static_cast<std::size_t>(count));
        for (int index = 0; index < count; ++index)
            order[static_cast<std::size_t>(index)] = index;
        std::stable_sort(order.begin(), order.end(),
            [&](const int left, const int right) {
                const std::string& a =
                    strippedNames[static_cast<std::size_t>(left)];
                const std::string& b =
                    strippedNames[static_cast<std::size_t>(right)];
                if (a != b) return a < b;
                return uniqueMaterialNumbers[left]
                    < uniqueMaterialNumbers[right];
            });
        idList<const idMaterial*, 5> sortedMaterials;
        idList<int, 5> sortedNumbers;
        sortedMaterials.SetNum(count);
        sortedNumbers.SetNum(count);
        for (int sortedIndex = 0; sortedIndex < count; ++sortedIndex) {
            const int original = order[static_cast<std::size_t>(sortedIndex)];
            mergeTo[original] = sortedIndex;
            sortedMaterials[sortedIndex] = resolvedMaterials[original];
            sortedNumbers[sortedIndex] = uniqueMaterialNumbers[original];
        }
        uniqueMaterials.Swap(sortedMaterials);
        uniqueMaterialNumbers.Swap(sortedNumbers);
        return;
    }

    uniqueMaterials.Clear();
    uniqueMaterialNumbers.Clear();
    for (int index = 0; index < count; ++index) {
        materialGenerationTraits_t traits;
        const bool discreteMaterial = materialTraitsCallback != nullptr
            && materialTraitsCallback(resolvedMaterials[index], traits)
            && traits.discrete;
        int destination = -1;
        if (!discreteMaterial) {
            for (int unique = 0; unique < uniqueMaterials.Num(); ++unique) {
                if (uniqueMaterials[unique] == resolvedMaterials[index]) {
                    destination = unique;
                    break;
                }
            }
        }
        if (destination < 0) {
            destination = uniqueMaterials.Append(resolvedMaterials[index]);
            uniqueMaterialNumbers.Append(-1);
        }
        mergeTo[index] = destination;
    }
}

bool idStaticModel::ConvertASEToModelSurfaces(const idASEModel* ase) {
    return ase != nullptr && ConvertImportModelToStaticModel(*this, *ase,
        pristine ? 0.0f : DEFAULT_VERTEX_SLOP,
        pristine ? 0.0f : DEFAULT_TEXCOORD_SLOP);
}

bool idStaticModel::ConvertOBJToModelSurfaces(const idOBJModel* obj) {
    return obj != nullptr && ConvertImportModelToStaticModel(*this, *obj,
        pristine ? 0.0f : DEFAULT_VERTEX_SLOP,
        pristine ? 0.0f : DEFAULT_TEXCOORD_SLOP);
}

bool idStaticModel::ConvertLWOToModelSurfaces(const lwObject* lwo,
        const lwLayer* layer, const float vertexSlop,
        const float texCoordSlop) {
    if (lwo == nullptr || layer == nullptr) return false;
    return ConvertImportModelToStaticModel(*this, layer->model,
        pristine ? 0.0f : vertexSlop,
        pristine ? 0.0f : texCoordSlop);
}

bool idStaticModel::ConvertToOBJ(const char* groupName,
        idOBJModel* obj) const {
    if (obj == nullptr) return false;
    idList<idTriangles*, 5> geometry;
    idList<const idMaterial*, 5> modelMaterials;
    for (int surface = 0; surface < surfaces.Num(); ++surface) {
        if (surfaces[surface].geometry == nullptr ||
            surfaces[surface].geometry->verts == nullptr ||
            surfaces[surface].geometry->indexes == nullptr) continue;
        geometry.Append(surfaces[surface].geometry);
        modelMaterials.Append(surfaces[surface].material);
    }
    return geometry.Num() > 0 && obj->AddGroupGeometry(groupName,
        geometry, modelMaterials);
}

void idStaticModel::BuildAutospriteData() {
    modelIsAutosprite = false;
    usesTransparencySort = false;
    if (surfaces.Num() == 0 || materialTraitsCallback == nullptr) return;

    int commonAutospriteType = 0;
    for (int surface = 0; surface < surfaces.Num(); ++surface) {
        materialGenerationTraits_t traits;
        if (surfaces[surface].material == nullptr ||
                !materialTraitsCallback(surfaces[surface].material, traits))
            return;
        usesTransparencySort = usesTransparencySort ||
            traits.transparencySort;
        if (traits.autospriteType == 0) return;
        if (surface == 0) commonAutospriteType = traits.autospriteType;
        else if (traits.autospriteType != commonAutospriteType) return;
    }
    modelIsAutosprite = true;
    referenceBounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    referenceBounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
    bool haveReferenceBounds = false;

    const auto byte = [](const float value) {
        return static_cast<std::uint8_t>((std::max)(0,
            (std::min)(255, static_cast<int>(value))));
    };
    const auto createBounds = [](idTriangles& geometry) {
        geometry.bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
        geometry.bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
        for (int vertex = 0; vertex < geometry.numVerts; ++vertex) {
            for (int axis = 0; axis < 3; ++axis) {
                geometry.bounds[0][axis] = (std::min)(
                    geometry.bounds[0][axis], geometry.verts[vertex].xyz[axis]);
                geometry.bounds[1][axis] = (std::max)(
                    geometry.bounds[1][axis], geometry.verts[vertex].xyz[axis]);
            }
        }
    };
    const int edgeVertices[6][2] = {
        {0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 3}
    };
    for (int surface = 0; surface < surfaces.Num(); ++surface) {
        idTriangles* geometry = surfaces[surface].geometry;
        if (geometry == nullptr || geometry->verts == nullptr ||
                geometry->indexes == nullptr || geometry->numVerts <= 0 ||
                (geometry->numVerts & 3) != 0 ||
                geometry->numIndexes != 6 * (geometry->numVerts / 4))
            continue;
        createBounds(*geometry);
        float maximumRadius = 0.0f;
        if (commonAutospriteType == 1) {
            for (int first = 0; first < geometry->numVerts; first += 4) {
                idVec3 center(0.0f, 0.0f, 0.0f);
                for (int corner = 0; corner < 4; ++corner)
                    center = center + geometry->verts[first + corner].xyz;
                center = center * 0.25f;
                float radius = std::sqrt(
                    (geometry->verts[first].xyz - center).LengthSqr() * 0.5f);
                radius = (std::min)(255.0f, radius);
                maximumRadius = (std::max)(maximumRadius, radius);
                static constexpr std::uint8_t corners[4][2] = {
                    {255, 255}, {0, 255}, {0, 0}, {255, 0}
                };
                static constexpr float texCoords[4][2] = {
                    {0.0f, 0.0f}, {1.0f, 0.0f},
                    {1.0f, 1.0f}, {0.0f, 1.0f}
                };
                for (int corner = 0; corner < 4; ++corner) {
                    idDrawVert& vertex = geometry->verts[first + corner];
                    vertex.xyz = center;
                    vertex.st.Set(texCoords[corner][0], texCoords[corner][1]);
                    vertex.tangent[0] = byte(radius);
                    vertex.tangent[1] = corners[corner][0];
                    vertex.tangent[2] = corners[corner][1];
                    vertex.tangent[3] = 0;
                }
                const int index = 6 * (first / 4);
                geometry->indexes[index + 0] =
                    static_cast<std::uint16_t>(first + 0);
                geometry->indexes[index + 1] =
                    static_cast<std::uint16_t>(first + 1);
                geometry->indexes[index + 2] =
                    static_cast<std::uint16_t>(first + 2);
                geometry->indexes[index + 3] =
                    static_cast<std::uint16_t>(first + 0);
                geometry->indexes[index + 4] =
                    static_cast<std::uint16_t>(first + 2);
                geometry->indexes[index + 5] =
                    static_cast<std::uint16_t>(first + 3);
            }
        } else if (commonAutospriteType == 2) {
            for (int index = 0; index < geometry->numIndexes; index += 6) {
                struct edge_t { int a; int b; float lengthSquared; } edges[6];
                for (int edge = 0; edge < 6; ++edge) {
                    edges[edge].a = geometry->indexes[index +
                        edgeVertices[edge][0]];
                    edges[edge].b = geometry->indexes[index +
                        edgeVertices[edge][1]];
                    if (edges[edge].a < 0 ||
                            edges[edge].a >= geometry->numVerts ||
                            edges[edge].b < 0 ||
                            edges[edge].b >= geometry->numVerts) {
                        edges[edge].lengthSquared =
                            std::numeric_limits<float>::max();
                    } else {
                        edges[edge].lengthSquared =
                            (geometry->verts[edges[edge].a].xyz -
                             geometry->verts[edges[edge].b].xyz).LengthSqr();
                    }
                }
                int shortest = 0;
                int secondShortest = 1;
                if (edges[secondShortest].lengthSquared <
                        edges[shortest].lengthSquared)
                    std::swap(shortest, secondShortest);
                for (int edge = 2; edge < 6; ++edge) {
                    if (edges[edge].lengthSquared <
                            edges[shortest].lengthSquared) {
                        secondShortest = shortest;
                        shortest = edge;
                    } else if (edges[edge].lengthSquared <
                            edges[secondShortest].lengthSquared) {
                        secondShortest = edge;
                    }
                }
                if (!std::isfinite(edges[shortest].lengthSquared) ||
                        !std::isfinite(edges[secondShortest].lengthSquared))
                    continue;
                const idVec3 centers[2] = {
                    (geometry->verts[edges[shortest].a].xyz +
                        geometry->verts[edges[shortest].b].xyz) * 0.5f,
                    (geometry->verts[edges[secondShortest].a].xyz +
                        geometry->verts[edges[secondShortest].b].xyz) * 0.5f
                };
                const idVec3 axis = Normalize(centers[1] - centers[0]);
                const edge_t selected[2] = {
                    edges[shortest], edges[secondShortest]
                };
                for (int end = 0; end < 2; ++end) {
                    const float radius = 0.5f * std::sqrt(
                        selected[end].lengthSquared);
                    maximumRadius = (std::max)(maximumRadius, radius);
                    const int vertices[2] = {
                        selected[end].a, selected[end].b
                    };
                    for (int side = 0; side < 2; ++side) {
                        idDrawVert& vertex = geometry->verts[vertices[side]];
                        vertex.xyz = centers[end];
                        vertex.SetNormal(axis);
                        vertex.normal[3] = side == end ? 255 : 0;
                        vertex.color[0] = byte((std::min)(255.0f, radius));
                        vertex.color[1] = 0;
                        vertex.color[2] = 0;
                        vertex.color[3] = 0;
                    }
                }
            }
        }
        for (int axis = 0; axis < 3; ++axis) {
            geometry->bounds[0][axis] -= maximumRadius;
            geometry->bounds[1][axis] += maximumRadius;
        }
        for (int axis = 0; axis < 3; ++axis) {
            referenceBounds[0][axis] = (std::min)(referenceBounds[0][axis],
                geometry->bounds[0][axis]);
            referenceBounds[1][axis] = (std::max)(referenceBounds[1][axis],
                geometry->bounds[1][axis]);
        }
        haveReferenceBounds = true;
    }
    if (!haveReferenceBounds) {
        referenceBounds[0].Zero();
        referenceBounds[1].Zero();
    }
    referencePosition = (referenceBounds[0] + referenceBounds[1]) * 0.5f;
}

void idStaticModel::MergeSurfacesAndBuildSourceSurfaces() {
    sourceSurfaces.Clear();
    for (int sourceIndex = 0; sourceIndex < surfaces.Num(); ++sourceIndex) {
        idStaticModelSurface& source = surfaces[sourceIndex];
        if (source.geometry == nullptr) continue;
        int renderSurface = -1;
        for (int candidate = 0; candidate < sourceIndex; ++candidate) {
            if (!GeometryCanMerge(surfaces[candidate], source)) continue;
            const int firstVertex = surfaces[candidate].geometry->numVerts;
            AppendGeometry(surfaces[candidate], source);
            sourceSurface_t sourceMapping{};
            sourceMapping.mtr = source.material;
            sourceMapping.mtrChecksum = MaterialChecksum(source.material);
            sourceMapping.renderSurface = candidate;
            sourceMapping.firstVertex = firstVertex;
            sourceMapping.lastVertex = surfaces[candidate].geometry->numVerts - 1;
            sourceSurfaces.Append(sourceMapping);
            renderSurface = candidate;
            break;
        }
        if (renderSurface < 0) {
            sourceSurface_t sourceMapping{};
            sourceMapping.mtr = source.material;
            sourceMapping.mtrChecksum = MaterialChecksum(source.material);
            sourceMapping.renderSurface = sourceIndex;
            sourceMapping.firstVertex = 0;
            sourceMapping.lastVertex = source.geometry->numVerts - 1;
            sourceSurfaces.Append(sourceMapping);
        }
    }

    idList<idStaticModelSurface, 84> compacted;
    idList<int, 5> renderRemap;
    renderRemap.SetNum(surfaces.Num());
    for (int index = 0; index < surfaces.Num(); ++index) {
        if (surfaces[index].geometry == nullptr) {
            renderRemap[index] = -1;
            continue;
        }
        renderRemap[index] = compacted.Num();
        compacted.Append(surfaces[index]);
    }
    for (int index = 0; index < sourceSurfaces.Num(); ++index) {
        const int oldIndex = sourceSurfaces[index].renderSurface;
        if (oldIndex >= 0 && oldIndex < renderRemap.Num())
            sourceSurfaces[index].renderSurface = renderRemap[oldIndex];
    }
    surfaces.Swap(compacted);
    FinishStaticModel(false);
}

void idStaticModel::ConvertToTriStrips() {
    for (int surface = 0; surface < surfaces.Num(); ++surface) {
        idStaticModelSurface& modelSurface = surfaces[surface];
        idTriangles* geometry = modelSurface.geometry;
        if (geometry == nullptr || geometry->indexes == nullptr ||
            geometry->numIndexes < 3) continue;
        materialGenerationTraits_t traits;
        if (materialTraitsCallback != nullptr &&
            materialTraitsCallback(modelSurface.material, traits) &&
            traits.disableTriangleStrips) continue;
        idList<std::uint16_t, 5> stripIndexes;
        TriangleStripper(geometry->indexes, geometry->numIndexes,
            stripIndexes);
        if (stripIndexes.Num() <= 0 ||
            stripIndexes.Num() >= geometry->numIndexes) continue;
        std::memcpy(geometry->indexes, stripIndexes.Ptr(),
            stripIndexes.Num() * sizeof(std::uint16_t));
        geometry->numIndexes = stripIndexes.Num();
        geometry->vertexMask |= TRIANGLE_STRIP_VERTEX_MASK;
        geometry->cpuVertexMask |= TRIANGLE_STRIP_VERTEX_MASK;
    }
}

bool idStaticModel::GenerateStaticModel(const char* sourceFile) {
    if (sourceFile == nullptr || *sourceFile == '\0') return false;
    sourceTimeStamp = fileSystem != nullptr
        ? fileSystem->GetTimestamp(sourceFile, false) : ~0u;
    std::string extension(sourceFile);
    const std::size_t dot = extension.find_last_of('.');
    extension = dot == std::string::npos ? std::string() :
        extension.substr(dot + 1);
    std::transform(extension.begin(), extension.end(), extension.begin(),
        [](const unsigned char c) { return static_cast<char>(std::tolower(c)); });

    bool converted = false;
    if (extension == "ase") {
        idASEModel* ase = ASE_Load(sourceFile);
        if (ase != nullptr) {
            if (ase->triangles.size() >= 100000) pristine = true;
            converted = ConvertASEToModelSurfaces(ase);
            ASE_Free(ase);
        }
    } else if (extension == "obj") {
        idOBJModel* obj = OBJ_Load(sourceFile);
        if (obj != nullptr) {
            if (obj->triangles.size() >= 100000) pristine = true;
            converted = ConvertOBJToModelSurfaces(obj);
            delete obj;
        }
    } else if (extension == "lwo" || extension == "lwob") {
        lwObject* object = lwGetObject(sourceFile, 1.0f, &sourceTimeStamp);
        if (object != nullptr) {
            idImportModel combined;
            for (const lwLayer* layer = object->layer; layer != nullptr;
                 layer = layer->next)
                AppendImportModel(combined, layer->model);
            if (combined.triangles.size() >= 100000) pristine = true;
            converted = ConvertImportModelToStaticModel(*this, combined,
                pristine ? 0.0f : DEFAULT_VERTEX_SLOP,
                pristine ? 0.0f : DEFAULT_TEXCOORD_SLOP);
            lwFreeObject(object);
        }
    }
    if (!converted) return false;

    FinishStaticModel(false);
    BuildAutospriteData();
    if (!pristine) {
        MergeSurfacesAndBuildSourceSurfaces();
        ConvertToTriStrips();
    }
    return surfaces.Num() > 0;
}

bool idStaticModel::GenerateBinaryModelFile(const char* sourceFile,
        const char* binaryFile) {
    idStaticModel generated;
    generated.pristine = pristine;
    generated.SetName(sourceFile);
    if (!generated.GenerateStaticModel(sourceFile)) return false;
    return generated.WriteBinaryModel(binaryFile);
}

bool idStaticModel::WriteStaticBModel(const char* fileName,
        const fsPath_t) const {
    return WriteBinaryModel(fileName);
}

bool idStaticModel::WriteStaticBModel(const char* fileName,
        const unsigned int timestamp,
        const idList<idStaticModelSurface, 84>& modelSurfaces,
        const idList<sourceSurface_t, 5>& modelSourceSurfaces,
        const fsPath_t) {
    idStaticModel temporary;
    temporary.sharedSurfaces = true;
    temporary.sourceTimeStamp = timestamp;
    temporary.surfaces = modelSurfaces;
    temporary.sourceSurfaces = modelSourceSurfaces;
    const bool written = temporary.WriteBinaryModel(fileName);
    temporary.surfaces.Clear();
    temporary.sourceSurfaces.Clear();
    return written;
}
