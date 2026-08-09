#include "models/morphskingen.h"

#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/math/mat3x4.h"
#include "models/skeletalanimation/declmd6.h"
#include "models/skeletalanimation/md6mesh.h"
#include "models/skeletalanimation/md6model.h"
#include "models/skeletalanimation/md6skel.h"
#include "models/static/staticmodel.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <limits>
#include <new>
#include <string>
#include <vector>

namespace {

constexpr int MORPH_MAGIC = 88625229;
constexpr int MAX_MORPH_SETS = 1 << 20;
constexpr int MAX_MORPH_VERTICES = 1 << 16;
constexpr float SKIN_MESH_POINT_THRESHOLD_SQR = 0.01f;

bool ReadExact(idFile* file, void* data, const unsigned int size) {
    return size == 0 || (file != nullptr && file->Read(data, size) == size);
}

bool WriteExact(idFile* file, const void* data, const unsigned int size) {
    return size == 0 || (file != nullptr && file->Write(data, size) == size);
}

idVec3 Normalize(const idVec3& value) {
    const float lengthSquared = value.LengthSqr();
    return lengthSquared > 1.0e-30f
        ? value * (1.0f / std::sqrt(lengthSquared))
        : idVec3(0.0f, 0.0f, 1.0f);
}

void ClearBounds(idBounds& bounds) {
    bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
}

void AddPoint(idBounds& bounds, const idVec3& point) {
    for (int axis = 0; axis < 3; ++axis) {
        bounds[0][axis] = (std::min)(bounds[0][axis], point[axis]);
        bounds[1][axis] = (std::max)(bounds[1][axis], point[axis]);
    }
}

const idDrawVert* CPUVertices(const idTriangles* triangles) {
    if (triangles == nullptr) return nullptr;
    if (triangles->verts != nullptr) return triangles->verts;
    if ((triangles->vertexMask & 0x1Fu) == 0x1Fu &&
        triangles->vertexBuffer.apiObject != nullptr)
        return static_cast<const idDrawVert*>(
            triangles->vertexBuffer.apiObject);
    return nullptr;
}

const std::uint16_t* CPUIndexes(const idTriangles* triangles) {
    if (triangles == nullptr) return nullptr;
    return triangles->indexes != nullptr ? triangles->indexes
        : static_cast<const std::uint16_t*>(
            triangles->indexBuffer.apiObject);
}

const idDeclMD6* FindDeclaration(const char* name) {
    if (name == nullptr || *name == '\0') return nullptr;
    return static_cast<const idDeclMD6*>(
        idDeclMD6::resourceList.FindWithInheritance(name, false));
}

bool BinaryFileName(const idDeclMD6* declaration, idStr& result) {
    if (declaration == nullptr || declaration->model == nullptr ||
        declaration->model->filename.Length() == 0) return false;
    result = "generated/skins/morphVertices/";
    result.Append(declaration->model->filename);
    result.SetFileExtension("morph");
    return true;
}

void TransformMorphCenter(const idDeclMD6* declaration,
        const idMorphDef& definition, int& jointGroupIndex,
        idVec3& center) {
    jointGroupIndex = 0;
    center.Zero();
    if (declaration == nullptr || declaration->model == nullptr ||
        std::strcmp(definition.jointName.c_str(), "none") == 0) return;
    jointGroupIndex = declaration->jointGroupCollection.GetJointGroupIndex(
        idJointGroup::JOINTGROUP_HITTEST, definition.jointName.c_str());
    if (jointGroupIndex < 0) return;
    const idJointGroup* group = declaration->jointGroupCollection
        .GetJointGroupForIndex(idJointGroup::JOINTGROUP_HITTEST,
            jointGroupIndex);
    if (group == nullptr || group->joints.Num() == 0 ||
        group->joints[0].Get() < 0 || declaration->model->skeleton == nullptr)
        return;
    const idJointMat* inversePose = declaration->model->skeleton
        ->InverseBasePose();
    if (inversePose == nullptr) return;
    idMat3x4 jointTransform;
    std::memcpy(jointTransform.mat,
        inversePose[group->joints[0].Get()].mat, sizeof(jointTransform.mat));
    jointTransform.Invert();
    jointTransform.Transform(center, definition.pos);
}

std::uint8_t EncodeMorphDirection(const float value) {
    const int encoded = static_cast<int>(
        ((value * (1.0f / 32.0f)) * 0.5f + 0.5f) * 255.0f);
    return static_cast<std::uint8_t>((std::max)(0,
        (std::min)(255, encoded)));
}

class morphShape_t {
public:
    enum shapeType_t {
        SHAPE_NONE = 0,
        SKIN_MESH,
        CLIP_SPHERE,
        SKIN_SPHERE,
        CLIP_ELLIPSOID
    };

    morphShape_t(idTriangles* triangles, const idDrawVert* vertices,
        const char* materialName) : type(SHAPE_NONE),
        center(0.0f, 0.0f, 0.0f), xAxis(0.0f, 0.0f, 0.0f),
        yAxis(0.0f, 0.0f, 0.0f), zAxis(0.0f, 0.0f, 0.0f),
        length(0.0f), radius(0.0f), radiusSqr(0.0f) {
        const char* name = materialName != nullptr ? materialName : "";
        if (std::strstr(name, "skinmesh") != nullptr) {
            if (MakeSkinMesh(triangles, vertices)) type = SKIN_MESH;
        } else if (std::strstr(name, "clipsphere") != nullptr) {
            if (MakeSphere(triangles, vertices)) type = CLIP_SPHERE;
        } else if (std::strstr(name, "skinsphere") != nullptr) {
            if (MakeSphere(triangles, vertices)) type = SKIN_SPHERE;
        } else if (std::strstr(name, "clipellipsoid") != nullptr) {
            if (MakeEllipsoid(triangles, vertices)) type = CLIP_ELLIPSOID;
        }
    }

    bool SkinMeshMorphPoint(const idVec3& input, idVec3& output) const {
        output.Zero();
        float best = SKIN_MESH_POINT_THRESHOLD_SQR;
        bool found = false;
        for (int index = 0; index < points.Num(); ++index) {
            const float distance = (points[index] - input).LengthSqr();
            if (distance < best) {
                best = distance;
                found = true;
            }
        }
        return found;
    }

    bool SphereContainsPoint(const idVec3& input, idVec3& output) const {
        output.Zero();
        return (input - center).LengthSqr() <= radiusSqr;
    }

    shapeType_t type;
    idVec3 center;
    idVec3 xAxis;
    idVec3 yAxis;
    idVec3 zAxis;
    float length;
    float radius;
    float radiusSqr;
    idList<idVec3, 5> points;

private:
    bool MakeSkinMesh(const idTriangles* triangles,
            const idDrawVert* vertices) {
        if (triangles == nullptr || vertices == nullptr ||
            triangles->numVerts <= 0) return false;
        points.SetNum(triangles->numVerts);
        for (int index = 0; index < triangles->numVerts; ++index)
            points[index] = vertices[index].xyz;
        return true;
    }

    bool MakeSphere(const idTriangles* triangles,
            const idDrawVert* vertices) {
        if (triangles == nullptr || vertices == nullptr ||
            triangles->numVerts < 16) return false;
        idBounds bounds;
        ClearBounds(bounds);
        for (int index = 0; index < triangles->numVerts; ++index)
            AddPoint(bounds, vertices[index].xyz);
        center = (bounds[0] + bounds[1]) * 0.5f;
        const idVec3 dimensions = bounds[1] - bounds[0];
        radius = 0.5f * (std::max)(dimensions.x,
            (std::max)(dimensions.y, dimensions.z));
        radiusSqr = radius * radius;
        return radius > 0.0f;
    }

    bool MakeEllipsoid(const idTriangles* triangles,
            const idDrawVert* vertices) {
        if (triangles == nullptr || vertices == nullptr ||
            triangles->numVerts < 4) return false;
        idBounds bounds;
        ClearBounds(bounds);
        for (int index = 0; index < triangles->numVerts; ++index)
            AddPoint(bounds, vertices[index].xyz);
        center = (bounds[0] + bounds[1]) * 0.5f;

        // Jacobi diagonalization of the covariance matrix gives a stable
        // oriented basis. The stored axes are unit-axis / radius, matching
        // the recovered clip-ellipsoid representation.
        float covariance[3][3]{};
        for (int index = 0; index < triangles->numVerts; ++index) {
            const idVec3 d = vertices[index].xyz - center;
            for (int row = 0; row < 3; ++row)
                for (int column = 0; column < 3; ++column)
                    covariance[row][column] += d[row] * d[column];
        }
        float eigenvectors[3][3]{{1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}};
        for (int iteration = 0; iteration < 24; ++iteration) {
            int p = 0, q = 1;
            float largest = std::fabs(covariance[0][1]);
            for (int row = 0; row < 3; ++row) {
                for (int column = row + 1; column < 3; ++column) {
                    const float value = std::fabs(covariance[row][column]);
                    if (value > largest) {
                        largest = value;
                        p = row;
                        q = column;
                    }
                }
            }
            if (largest < 1.0e-8f) break;
            const float angle = 0.5f * std::atan2(
                2.0f * covariance[p][q],
                covariance[q][q] - covariance[p][p]);
            const float c = std::cos(angle), s = std::sin(angle);
            for (int column = 0; column < 3; ++column) {
                const float ap = covariance[p][column];
                const float aq = covariance[q][column];
                covariance[p][column] = c * ap - s * aq;
                covariance[q][column] = s * ap + c * aq;
            }
            for (int row = 0; row < 3; ++row) {
                const float ap = covariance[row][p];
                const float aq = covariance[row][q];
                covariance[row][p] = c * ap - s * aq;
                covariance[row][q] = s * ap + c * aq;
                const float vp = eigenvectors[row][p];
                const float vq = eigenvectors[row][q];
                eigenvectors[row][p] = c * vp - s * vq;
                eigenvectors[row][q] = s * vp + c * vq;
            }
        }
        idVec3 axes[3] = {
            Normalize(idVec3(eigenvectors[0][0], eigenvectors[1][0],
                eigenvectors[2][0])),
            Normalize(idVec3(eigenvectors[0][1], eigenvectors[1][1],
                eigenvectors[2][1])),
            Normalize(idVec3(eigenvectors[0][2], eigenvectors[1][2],
                eigenvectors[2][2]))
        };
        float extent[3]{};
        for (int index = 0; index < triangles->numVerts; ++index) {
            const idVec3 d = vertices[index].xyz - center;
            for (int axis = 0; axis < 3; ++axis)
                extent[axis] = (std::max)(extent[axis],
                    std::fabs(d.Dot(axes[axis])));
        }
        if (extent[0] <= 1.0e-6f || extent[1] <= 1.0e-6f ||
            extent[2] <= 1.0e-6f) return false;
        xAxis = axes[0] * (1.0f / extent[0]);
        yAxis = axes[1] * (1.0f / extent[1]);
        zAxis = axes[2] * (1.0f / extent[2]);
        return true;
    }
};

} // namespace

idTypedResourceList<idMorphVertices> idMorphVertices::resourceList(
    "morphVertices");

idMorphVertices::vertSet::vertSet()
    : meshNum(-1), jointGroupIndex(-1), flags(0),
      pos(0.0f, 0.0f, 0.0f), size(0.0f, 0.0f, 0.0f), axis(1.0f) {
}

idMorphVertices::idMorphVertices()
    : timestampDecl(~0u), timestampModel(~0u) {
}

idResourceList* idMorphVertices::GetResourceList() {
    return &resourceList;
}

bool idMorphVertices::LoadBinaryFile(const char* fileName) {
    if (fileSystem == nullptr || fileName == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileRead(fileName, true, false));
    int magic = 0, setCount = 0;
    unsigned int declarationTimestamp = ~0u, modelTimestamp = ~0u;
    if (file.file == nullptr || !ReadExact(file.file, &magic, 4) ||
        magic != MORPH_MAGIC ||
        !ReadExact(file.file, &declarationTimestamp, 4) ||
        !ReadExact(file.file, &modelTimestamp, 4) ||
        !ReadExact(file.file, &setCount, 4) || setCount < 0 ||
        setCount > MAX_MORPH_SETS) return false;

    idList<vertSet, 5> loaded;
    if (!loaded.SetNum(setCount)) return false;
    for (int index = 0; index < setCount; ++index) {
        vertSet& set = loaded[index];
        int vertexCount = 0, directionCount = 0;
        if (!ReadExact(file.file, &set.meshNum, 4) ||
            !ReadExact(file.file, &set.jointGroupIndex, 4) ||
            !ReadExact(file.file, &set.flags, 4) ||
            !ReadExact(file.file, &set.pos, sizeof(set.pos)) ||
            !ReadExact(file.file, &set.size, sizeof(set.size)) ||
            !ReadExact(file.file, &set.axis, sizeof(set.axis)) ||
            !ReadExact(file.file, &vertexCount, 4) || vertexCount < 0 ||
            vertexCount > MAX_MORPH_VERTICES ||
            !set.vertices.SetNum(vertexCount) ||
            !ReadExact(file.file, set.vertices.Ptr(),
                vertexCount * sizeof(std::uint16_t)) ||
            !ReadExact(file.file, &directionCount, 4) || directionCount < 0 ||
            directionCount > MAX_MORPH_VERTICES * 3 ||
            !set.morphDirection.SetNum(directionCount) ||
            !ReadExact(file.file, set.morphDirection.Ptr(),
                directionCount)) return false;
    }
    if (!ReadExact(file.file, &magic, 4) || magic != MORPH_MAGIC)
        return false;
    morphVertSet.Swap(loaded);
    timestampDecl = declarationTimestamp;
    timestampModel = modelTimestamp;
    return true;
}

bool idMorphVertices::WriteBinaryFile(const char* fileName) const {
    if (fileSystem == nullptr || fileName == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileWrite(fileName, FSPATH_BASE));
    const int setCount = morphVertSet.Num();
    if (file.file == nullptr || !WriteExact(file.file, &MORPH_MAGIC, 4) ||
        !WriteExact(file.file, &timestampDecl, 4) ||
        !WriteExact(file.file, &timestampModel, 4) ||
        !WriteExact(file.file, &setCount, 4)) return false;
    for (int index = 0; index < setCount; ++index) {
        const vertSet& set = morphVertSet[index];
        const int vertexCount = set.vertices.Num();
        const int directionCount = set.morphDirection.Num();
        if (!WriteExact(file.file, &set.meshNum, 4) ||
            !WriteExact(file.file, &set.jointGroupIndex, 4) ||
            !WriteExact(file.file, &set.flags, 4) ||
            !WriteExact(file.file, &set.pos, sizeof(set.pos)) ||
            !WriteExact(file.file, &set.size, sizeof(set.size)) ||
            !WriteExact(file.file, &set.axis, sizeof(set.axis)) ||
            !WriteExact(file.file, &vertexCount, 4) ||
            !WriteExact(file.file, set.vertices.Ptr(),
                vertexCount * sizeof(std::uint16_t)) ||
            !WriteExact(file.file, &directionCount, 4) ||
            !WriteExact(file.file, set.morphDirection.Ptr(),
                directionCount)) return false;
    }
    return WriteExact(file.file, &MORPH_MAGIC, 4);
}

bool idMorphVertices::Load_Binary() {
    const idDeclMD6* declaration = FindDeclaration(GetName());
    idStr fileName;
    return BinaryFileName(declaration, fileName) &&
        LoadBinaryFile(fileName.c_str());
}

bool idMorphVertices::Write_Binary() {
    const idDeclMD6* declaration = FindDeclaration(GetName());
    idStr fileName;
    if (!BinaryFileName(declaration, fileName)) return false;
    morphVertSet.Clear();
    timestampDecl = declaration->GetDeclTimestamp();
    timestampModel = declaration->model != nullptr
        ? declaration->model->timestamp : ~0u;
    idMorphVertGen::GenerateMorphVerts(declaration,
        declaration->morphDefList, *this);
    return WriteBinaryFile(fileName.c_str());
}

void idMorphVertices::LoadResource() {
    if (Load_Binary()) return;
    if (!Write_Binary())
        SetResourceError("idMorphVertices load resource failed '%s'",
            GetName());
}

bool idMorphVertices::ReloadIfStale() {
    const idDeclMD6* declaration = FindDeclaration(GetName());
    if (declaration == nullptr || declaration->model == nullptr) return false;
    if (timestampDecl == declaration->GetDeclTimestamp() &&
        timestampModel == declaration->model->timestamp) return false;
    morphVertSet.Clear();
    LoadResource();
    return true;
}

void idMorphVertices::WriteResourceFile() {
    Write_Binary();
}

void idMorphVertGen::ProcessModel(const idMD6Model& model,
        const idDeclMD6* declaration, const idMorphDef& definition,
        idMorphVertices& output) {
    int jointGroupIndex = 0;
    idVec3 sphereCenter;
    TransformMorphCenter(declaration, definition, jointGroupIndex,
        sphereCenter);
    for (int meshIndex = 0; meshIndex < model.meshes.Num(); ++meshIndex) {
        const idMD6Mesh* mesh = model.meshes[meshIndex];
        if (mesh == nullptr || mesh->tris == nullptr) continue;
        const idDrawVert* vertices = CPUVertices(mesh->tris);
        if (vertices == nullptr) continue;
        idMorphVertices::vertSet set;
        set.meshNum = meshIndex;
        set.jointGroupIndex = jointGroupIndex;
        set.flags = definition.flags;
        set.pos = definition.pos;
        set.size = definition.size;
        for (int vertex = 0; vertex < mesh->tris->numVerts &&
             vertex < MAX_MORPH_VERTICES; ++vertex) {
            bool contained = false;
            if ((definition.flags & idMorphDef::MORPHDEF_ELLIPSOID) != 0) {
                contained = (vertices[vertex].xyz - sphereCenter).LengthSqr()
                    <= definition.size.x * definition.size.x;
            } else {
                const idVec3& point = vertices[vertex].xyz;
                contained = point.x >= definition.pos.x - definition.size.x &&
                    point.x <= definition.pos.x + definition.size.x &&
                    point.y >= definition.pos.y - definition.size.y &&
                    point.y <= definition.pos.y + definition.size.y &&
                    point.z >= definition.pos.z - definition.size.z &&
                    point.z <= definition.pos.z + definition.size.z;
            }
            if (contained)
                set.vertices.Append(static_cast<std::uint16_t>(vertex));
        }
        if (set.vertices.Num() != 0) output.morphVertSet.Append(set);
    }
}

void idMorphVertGen::OptimizeVertices(idMorphVertices& output,
        const idMorphVertices& input) {
    output.morphVertSet.Clear();
    std::vector<bool> consumed(static_cast<std::size_t>(
        input.morphVertSet.Num()));
    std::vector<std::uint8_t> used(MAX_MORPH_VERTICES);
    for (int first = 0; first < input.morphVertSet.Num(); ++first) {
        if (consumed[static_cast<std::size_t>(first)]) continue;
        std::fill(used.begin(), used.end(), 0);
        const idMorphVertices::vertSet& source = input.morphVertSet[first];
        for (int candidate = first; candidate < input.morphVertSet.Num();
             ++candidate) {
            const idMorphVertices::vertSet& other =
                input.morphVertSet[candidate];
            if (other.meshNum != source.meshNum ||
                other.jointGroupIndex != source.jointGroupIndex) continue;
            consumed[static_cast<std::size_t>(candidate)] = true;
            for (int vertex = 0; vertex < other.vertices.Num(); ++vertex)
                used[other.vertices[vertex]] = 1;
        }
        idMorphVertices::vertSet merged = source;
        merged.vertices.Clear();
        merged.morphDirection.Clear();
        for (int vertex = 0; vertex < MAX_MORPH_VERTICES; ++vertex)
            if (used[static_cast<std::size_t>(vertex)] != 0)
                merged.vertices.Append(static_cast<std::uint16_t>(vertex));
        output.morphVertSet.Append(merged);
    }
}

void idMorphVertGen::GenerateMorphVertsFromFile(
        const idDeclMD6* declaration, const char* generationFile,
        idMorphVertices& output) {
    if (declaration == nullptr || declaration->model == nullptr ||
        generationFile == nullptr || *generationFile == '\0') return;
    idStaticModel projection;
    projection.SetName(generationFile);
    projection.PristineLoadResource();
    if (!projection.isReloadable) return;

    for (int surfaceIndex = 0; surfaceIndex < projection.surfaces.Num();
         ++surfaceIndex) {
        const idStaticModelSurface& surface =
            projection.surfaces[surfaceIndex];
        idTriangles* geometry = surface.geometry;
        const idDrawVert* projectionVertices = CPUVertices(geometry);
        if (surface.material == nullptr || geometry == nullptr ||
            projectionVertices == nullptr || CPUIndexes(geometry) == nullptr)
            continue;
        morphShape_t shape(geometry, projectionVertices,
            idStaticModel::MaterialName(surface.material));
        if (shape.type == morphShape_t::SHAPE_NONE) continue;
        if (shape.type == morphShape_t::CLIP_SPHERE) {
            idMorphVertices::vertSet set;
            set.flags = idMorphVertices::MORPHVERT_CLIP_SPHERE;
            set.jointGroupIndex = surface.materialNum;
            set.meshNum = -1;
            set.pos = shape.center;
            set.size.Set(shape.radius, 0.0f, 0.0f);
            output.morphVertSet.Append(set);
            continue;
        }
        if (shape.type == morphShape_t::CLIP_ELLIPSOID) {
            idMorphVertices::vertSet set;
            set.flags = idMorphVertices::MORPHVERT_CLIP_ELLIPSOID;
            set.jointGroupIndex = surface.materialNum;
            set.meshNum = -1;
            set.pos = shape.center;
            set.axis[0] = shape.xAxis;
            set.axis[1] = shape.yAxis;
            set.axis[2] = shape.zAxis;
            output.morphVertSet.Append(set);
            continue;
        }

        for (int meshIndex = 0;
             meshIndex < declaration->model->meshes.Num(); ++meshIndex) {
            const idMD6Mesh* mesh = declaration->model->meshes[meshIndex];
            if (mesh == nullptr || mesh->tris == nullptr ||
                std::strstr(idMD6Mesh::MaterialName(mesh->material),
                    "gore") != nullptr) continue;
            const idDrawVert* modelVertices = CPUVertices(mesh->tris);
            if (modelVertices == nullptr) continue;
            idMorphVertices::vertSet set;
            set.meshNum = meshIndex;
            set.jointGroupIndex = surface.materialNum;
            set.flags = idMorphVertices::MORPHVERT_SKIN;
            for (int vertex = 0; vertex < mesh->tris->numVerts &&
                 vertex < MAX_MORPH_VERTICES; ++vertex) {
                idVec3 direction;
                const bool contained = shape.type == morphShape_t::SKIN_MESH
                    ? shape.SkinMeshMorphPoint(modelVertices[vertex].xyz,
                        direction)
                    : shape.SphereContainsPoint(modelVertices[vertex].xyz,
                        direction);
                if (!contained) continue;
                set.vertices.Append(static_cast<std::uint16_t>(vertex));
                if (direction.LengthSqr() > 0.0f) {
                    set.morphDirection.Append(EncodeMorphDirection(
                        direction.x));
                    set.morphDirection.Append(EncodeMorphDirection(
                        direction.y));
                    set.morphDirection.Append(EncodeMorphDirection(
                        direction.z));
                }
            }
            if (set.vertices.Num() != 0) output.morphVertSet.Append(set);
        }
    }
}

void idMorphVertGen::GenerateMorphVerts(const idDeclMD6* declaration,
        const idList<idMorphDef, 115>& definitions,
        idMorphVertices& output) {
    if (declaration == nullptr || declaration->model == nullptr ||
        definitions.Num() == 0) return;
    idMorphVertices unoptimized;
    for (int index = 0; index < definitions.Num(); ++index) {
        const idMorphDef& definition = definitions[index];
        if (definition.fileName.Length() == 0)
            ProcessModel(*declaration->model, declaration, definition,
                unoptimized);
    }
    OptimizeVertices(output, unoptimized);
    for (int index = 0; index < definitions.Num(); ++index) {
        const idMorphDef& definition = definitions[index];
        if (definition.fileName.Length() != 0)
            GenerateMorphVertsFromFile(declaration,
                definition.fileName.c_str(), output);
    }
}
