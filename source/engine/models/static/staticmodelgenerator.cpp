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
    idList<idRawSurface, 5> rawSurfaces;
    rawSurfaces.SetNum(materialCount);
    for (int material = 0; material < materialCount; ++material) {
        idRawSurface& raw = rawSurfaces[material];
        std::string name = material < static_cast<int>(source.materials.size())
            ? source.materials[static_cast<std::size_t>(material)].name
            : "_default";
        const int materialNumber = StripMaterialNumber(name);
        raw.material = idStaticModel::ResolveMaterial(name.c_str());
        raw.materialNum = materialNumber >= 0 ? materialNumber : material;
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
        idRawSurface& raw = rawSurfaces[(std::min)(material,
            rawSurfaces.Num() - 1)];
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
    int commonAutospriteType = -1;
    for (int surface = 0; surface < surfaces.Num(); ++surface) {
        materialGenerationTraits_t traits;
        if (materialTraitsCallback == nullptr ||
            !materialTraitsCallback(surfaces[surface].material, traits))
            continue;
        usesTransparencySort = usesTransparencySort ||
            traits.transparencySort;
        if (traits.autospriteType == 0) continue;
        if (commonAutospriteType < 0) commonAutospriteType =
            traits.autospriteType;
        if (traits.autospriteType == commonAutospriteType)
            modelIsAutosprite = true;
        else
            modelIsAutosprite = false;
    }
    // Autosprite vertex expansion is consumed by the renderer. The recovered
    // model layer retains the authoring quads and records the material mode;
    // renderer adapters can derive camera-facing axes without corrupting the
    // portable idDrawVert layout.
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
