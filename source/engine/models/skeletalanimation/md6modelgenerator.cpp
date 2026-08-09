#include "models/skeletalanimation/md6modelgenerator.h"

#include "idlib/filesystem/filesystem.h"
#include "idlib/text/lexer.h"
#include "models/skeletalanimation/md6mesh.h"
#include "models/skeletalanimation/md6model.h"
#include "models/skeletalanimation/md6skel.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <new>
#include <vector>

namespace {

constexpr int MD6_MODEL_VERSION = 5;
constexpr int MAX_JOINTS = 256;
constexpr float MORPH_MATCH_DISTANCE_SQUARED = 0.1f;

int Pad8(const int value) { return (value + 7) & ~7; }

int ClampByte(const int value) { return (std::max)(0, (std::min)(255, value)); }

idVec3 Normalized(const idVec3& value) {
    const float lengthSquared = value.LengthSqr();
    return lengthSquared > 1.0e-30f
        ? value * (1.0f / std::sqrt(lengthSquared))
        : idVec3(0.0f, 0.0f, 0.0f);
}

void ClearProcessSurfaces(idList<idProcessSurface*, 5>& surfaces) {
    for (int index = 0; index < surfaces.Num(); ++index)
        delete surfaces[index];
    surfaces.ClearFree();
}

int FindBaseUvSet(const idProcessMesh& mesh) {
    for (int index = 0; index < mesh.uvs.Num(); ++index)
        if (mesh.uvs[index].slot == 0) return index;
    return mesh.uvs.Num() > 0 ? 0 : -1;
}

void DeriveSurfaceVectors(idProcessMesh& mesh, const bool keepNormals) {
    std::vector<idVec3> normalSums(mesh.vertexes.Num(),
        idVec3(0.0f, 0.0f, 0.0f));
    std::vector<idVec3> tangentSums(mesh.vertexes.Num(),
        idVec3(0.0f, 0.0f, 0.0f));
    std::vector<idVec3> bitangentSums(mesh.vertexes.Num(),
        idVec3(0.0f, 0.0f, 0.0f));
    const int baseUv = FindBaseUvSet(mesh);
    for (int index = 0; index + 2 < mesh.indexes.Num(); index += 3) {
        const int ia = mesh.indexes[index];
        const int ib = mesh.indexes[index + 1];
        const int ic = mesh.indexes[index + 2];
        if (ia < 0 || ib < 0 || ic < 0 || ia >= mesh.vertexes.Num() ||
                ib >= mesh.vertexes.Num() || ic >= mesh.vertexes.Num())
            continue;
        const idVec3 edge1 = mesh.vertexes[ib].xyz - mesh.vertexes[ia].xyz;
        const idVec3 edge2 = mesh.vertexes[ic].xyz - mesh.vertexes[ia].xyz;
        const idVec3 faceNormal = Normalized(edge1.Cross(edge2));
        idVec3 tangent(1.0f, 0.0f, 0.0f);
        idVec3 bitangent(0.0f, 1.0f, 0.0f);
        if (baseUv >= 0 && mesh.uvs[baseUv].st.Num() == mesh.vertexes.Num()) {
            const idVec2 delta1(
                mesh.uvs[baseUv].st[ib].x - mesh.uvs[baseUv].st[ia].x,
                mesh.uvs[baseUv].st[ib].y - mesh.uvs[baseUv].st[ia].y);
            const idVec2 delta2(
                mesh.uvs[baseUv].st[ic].x - mesh.uvs[baseUv].st[ia].x,
                mesh.uvs[baseUv].st[ic].y - mesh.uvs[baseUv].st[ia].y);
            const float determinant = delta1.x * delta2.y -
                delta1.y * delta2.x;
            if (std::fabs(determinant) > 1.0e-20f) {
                const float inverse = 1.0f / determinant;
                tangent = (edge1 * delta2.y - edge2 * delta1.y) * inverse;
                bitangent = (edge2 * delta1.x - edge1 * delta2.x) * inverse;
            }
        }
        const int triangle[3] = { ia, ib, ic };
        for (const int vertex : triangle) {
            normalSums[vertex] = normalSums[vertex] + faceNormal;
            tangentSums[vertex] = tangentSums[vertex] + tangent;
            bitangentSums[vertex] = bitangentSums[vertex] + bitangent;
        }
    }
    for (int index = 0; index < mesh.vertexes.Num(); ++index) {
        processVert_t& vertex = mesh.vertexes[index];
        if (!keepNormals || vertex.normal.LengthSqr() <= 1.0e-30f)
            vertex.normal = Normalized(normalSums[index]);
        else
            vertex.normal = Normalized(vertex.normal);
        idVec3 tangent = tangentSums[index] - vertex.normal *
            vertex.normal.Dot(tangentSums[index]);
        tangent = Normalized(tangent);
        if (tangent.LengthSqr() <= 1.0e-30f) {
            const idVec3 helper = std::fabs(vertex.normal.z) < 0.9f
                ? idVec3(0.0f, 0.0f, 1.0f)
                : idVec3(0.0f, 1.0f, 0.0f);
            tangent = Normalized(helper.Cross(vertex.normal));
        }
        vertex.tangent.Set(tangent.x, tangent.y, tangent.z,
            vertex.normal.Cross(tangent).Dot(bitangentSums[index]) >= 0.0f
                ? 1.0f : -1.0f);
    }
}

void UpdateJointRange(idProcessMesh& mesh) {
    int minimum = 255, maximum = 0;
    bool found = false;
    for (int vertexIndex = 0; vertexIndex < mesh.vertexes.Num(); ++vertexIndex) {
        const processVert_t& vertex = mesh.vertexes[vertexIndex];
        for (int weight = 0; weight < 4; ++weight) {
            if (vertex.weights[weight] == 0) continue;
            found = true;
            minimum = (std::min)(minimum,
                static_cast<int>(vertex.jointIdxs[weight]));
            maximum = (std::max)(maximum,
                static_cast<int>(vertex.jointIdxs[weight]));
        }
    }
    mesh.minJoint = found ? minimum & ~3 : 0;
    mesh.maxJoint = found ? maximum : 0;
}

idProcessSurface* CopyTriangleRange(const idProcessSurface& source,
        const std::vector<int>& triangleNumbers) {
    idProcessSurface* result = new (std::nothrow) idProcessSurface;
    if (result == nullptr) return nullptr;
    result->name = source.name;
    result->material = source.material;
    result->discrete = source.discrete;
    result->allowSkinRemapping = source.allowSkinRemapping;
    result->numTexCoordSets = source.numTexCoordSets;
    result->sourceOrdinal = source.sourceOrdinal;
    result->mesh.uvs.SetNum(source.mesh.uvs.Num());
    for (int uv = 0; uv < source.mesh.uvs.Num(); ++uv)
        result->mesh.uvs[uv].slot = source.mesh.uvs[uv].slot;
    std::vector<int> remap(source.mesh.vertexes.Num(), -1);
    for (const int triangle : triangleNumbers) {
        for (int corner = 0; corner < 3; ++corner) {
            const int oldIndex = source.mesh.indexes[triangle * 3 + corner];
            if (oldIndex < 0 || oldIndex >= source.mesh.vertexes.Num()) continue;
            if (remap[oldIndex] < 0) {
                remap[oldIndex] = result->mesh.vertexes.Append(
                    source.mesh.vertexes[oldIndex]);
                for (int uv = 0; uv < source.mesh.uvs.Num(); ++uv)
                    result->mesh.uvs[uv].st.Append(
                        source.mesh.uvs[uv].st[oldIndex]);
            }
            result->mesh.indexes.Append(remap[oldIndex]);
        }
    }
    result->mesh.hashST = source.mesh.hashST;
    UpdateJointRange(result->mesh);
    return result;
}

bool ReadStringToken(idLexer& lexer, idStr& output) {
    idToken token;
    if (!lexer.ReadToken(token)) return false;
    output = token.c_str();
    return true;
}

} // namespace

idMD6BinaryGenerator::SkeletonResolver
    idMD6BinaryGenerator::skeletonResolverCallback = nullptr;
idMD6BinaryGenerator::MaterialResolver
    idMD6BinaryGenerator::materialResolverCallback = nullptr;
idMD6BinaryGenerator::MaterialNameCallback
    idMD6BinaryGenerator::materialNameCallback = nullptr;
idMD6BinaryGenerator::MaterialChecksumCallback
    idMD6BinaryGenerator::materialChecksumCallback = nullptr;
idMD6BinaryGenerator::MaterialDiscreteCallback
    idMD6BinaryGenerator::materialDiscreteCallback = nullptr;
idMD6BinaryGenerator::MaterialMergeCallback
    idMD6BinaryGenerator::materialMergeCallback = nullptr;
idMD6BinaryGenerator::MorphMapLoader
    idMD6BinaryGenerator::morphMapLoaderCallback = nullptr;

idMD6BinaryGenerator::idMD6BinaryGenerator()
    : timestamp(0), skelTimestamp(0), remapForSkinning(false),
      minBoundsExpansion(0.0f, 0.0f, 0.0f),
      maxBoundsExpansion(0.0f, 0.0f, 0.0f), skeleton(nullptr) {
    defaultBounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    defaultBounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
}

idMD6BinaryGenerator::~idMD6BinaryGenerator() { Clear(); }

void idMD6BinaryGenerator::Clear() {
    ClearProcessSurfaces(surfaces);
    jointRemap.ClearFree();
    sourceSurfaces.ClearFree();
    sourceFileName.Clear();
    morphSkinName.Clear();
    skeleton = nullptr;
    timestamp = skelTimestamp = 0;
}

void idMD6BinaryGenerator::SetCallbacks(SkeletonResolver skeletonResolver,
        MaterialResolver materialResolver, MaterialNameCallback materialName,
        MaterialChecksumCallback materialChecksum,
        MaterialDiscreteCallback materialDiscrete,
        MaterialMergeCallback materialMerge, MorphMapLoader morphLoader) {
    skeletonResolverCallback = skeletonResolver;
    materialResolverCallback = materialResolver;
    materialNameCallback = materialName;
    materialChecksumCallback = materialChecksum;
    materialDiscreteCallback = materialDiscrete;
    materialMergeCallback = materialMerge;
    morphMapLoaderCallback = morphLoader;
}

void idMD6BinaryGenerator::LoadMorphMap(const char* fileName,
        const idVec3& offset,
        idList<vertexMorphOffset_t, 5>& offsets) const {
    offsets.Clear();
    if (fileName != nullptr && fileName[0] != '\0' &&
            morphMapLoaderCallback != nullptr)
        morphMapLoaderCallback(fileName, offset, offsets);
}

bool idMD6BinaryGenerator::MatchMorphVerts(
        const idList<vertexMorphOffset_t, 5>& offsets,
        idList<processVert_t, 5>& vertices) {
    int matched = 0;
    for (int vertexIndex = 0; vertexIndex < vertices.Num(); ++vertexIndex) {
        processVert_t& vertex = vertices[vertexIndex];
        int nearest = -1;
        float nearestDistance = std::numeric_limits<float>::max();
        for (int offsetIndex = 0; offsetIndex < offsets.Num(); ++offsetIndex) {
            const float distance =
                (offsets[offsetIndex].xyz - vertex.xyz).LengthSqr();
            if (distance < nearestDistance) {
                nearestDistance = distance;
                nearest = offsetIndex;
            }
        }
        vertex.morph[3] = 0;
        if (nearest >= 0 && nearestDistance <= MORPH_MATCH_DISTANCE_SQUARED) {
            const idVec3& value = offsets[nearest].offset;
            vertex.morph[0] = static_cast<std::uint8_t>(ClampByte(
                static_cast<int>(value.x * 4.0f + 128.0f)));
            vertex.morph[1] = static_cast<std::uint8_t>(ClampByte(
                static_cast<int>(value.y * 4.0f + 128.0f)));
            vertex.morph[2] = static_cast<std::uint8_t>(ClampByte(
                static_cast<int>(value.z * 4.0f + 128.0f)));
            ++matched;
        } else {
            vertex.morph[0] = vertex.morph[1] = vertex.morph[2] = 128;
        }
    }
    return matched == vertices.Num();
}

bool idMD6BinaryGenerator::ParseMesh(idLexer& lexer, const int version,
        const int numModelJoints, const bool exportedNormals,
        const idList<short, 5>& modelToSkeleton) {
    if (!lexer.ExpectTokenString("{")) return false;
    if (!lexer.ExpectTokenString("name")) return false;
    idStr meshName;
    if (!ReadStringToken(lexer, meshName)) return false;

    idList<const idMaterial*, 5> shaders;
    if (version < 5) {
        idStr materialName;
        if (!lexer.ExpectTokenString("shader") ||
                !ReadStringToken(lexer, materialName)) return false;
        shaders.Append(materialResolverCallback != nullptr
            ? materialResolverCallback(materialName.c_str()) : nullptr);
    } else {
        if (!lexer.ExpectTokenString("shaders")) return false;
        const int shaderCount = lexer.ParseInt();
        if (shaderCount <= 0 || shaderCount > 4096 ||
                !lexer.ExpectTokenString("{")) return false;
        for (int index = 0; index < shaderCount; ++index) {
            idStr materialName;
            if (!lexer.ExpectTokenString("shader")) return false;
            lexer.ParseInt();
            if (!ReadStringToken(lexer, materialName)) return false;
            shaders.Append(materialResolverCallback != nullptr
                ? materialResolverCallback(materialName.c_str()) : nullptr);
        }
        if (!lexer.ExpectTokenString("}")) return false;
    }

    const bool discrete = lexer.CheckTokenString("discrete") ||
        lexer.CheckTokenString("nomerge");
    const bool allowSkinRemapping =
        !lexer.CheckTokenString("noSkinRemapping");
    idProcessMesh parsed;
    int uvSetCount = 1;
    if (lexer.CheckTokenString("uvsets")) {
        uvSetCount = lexer.ParseInt();
        if (uvSetCount < 0 || uvSetCount > 64 ||
                !lexer.ExpectTokenString("{")) return false;
        parsed.uvs.SetNum(uvSetCount);
        for (int index = 0; index < uvSetCount; ++index) {
            idToken ignored;
            if (!lexer.ExpectTokenString("name")) return false;
            parsed.uvs[index].slot = static_cast<std::uint8_t>(
                ClampByte(lexer.ParseInt()));
            if (!lexer.ReadToken(ignored)) return false;
        }
        if (!lexer.ExpectTokenString("}")) return false;
    } else {
        parsed.uvs.SetNum(1);
        parsed.uvs[0].slot = 0;
    }

    if (!lexer.ExpectTokenString("verts")) return false;
    const int vertexCount = lexer.ParseInt();
    if (vertexCount < 0 || vertexCount > (1 << 24) ||
            !lexer.ExpectTokenString("{")) return false;
    parsed.vertexes.SetNum(vertexCount);
    for (int uv = 0; uv < uvSetCount; ++uv)
        parsed.uvs[uv].st.SetNum(vertexCount);
    for (int vertexIndex = 0; vertexIndex < vertexCount; ++vertexIndex) {
        processVert_t& vertex = parsed.vertexes[vertexIndex];
        std::memset(&vertex, 0, sizeof(vertex));
        if (!lexer.ExpectTokenString("vert")) return false;
        lexer.ParseInt();
        if (!lexer.Parse1DMatrix(3, &vertex.xyz.x)) return false;
        if (exportedNormals &&
                !lexer.Parse1DMatrix(3, &vertex.normal.x)) return false;
        for (int uv = 0; uv < uvSetCount; ++uv)
            if (!lexer.Parse1DMatrix(2, &parsed.uvs[uv].st[vertexIndex].x))
                return false;
        float influences[8];
        if (!lexer.Parse1DMatrix(8, influences)) return false;
        struct influence_t { int joint; int weight; } influence[4];
        for (int index = 0; index < 4; ++index) {
            const int modelJoint = ClampByte(static_cast<int>(influences[index]));
            if (modelJoint >= numModelJoints ||
                    modelJoint >= modelToSkeleton.Num()) {
                lexer.Error("Joint index out of range(%d): %d",
                    numModelJoints, modelJoint);
                return false;
            }
            influence[index].joint = modelToSkeleton[modelJoint];
            influence[index].weight = ClampByte(static_cast<int>(
                influences[index + 4] * 255.0f));
        }
        std::sort(influence, influence + 4,
            [](const influence_t& first, const influence_t& second) {
                return first.weight > second.weight;
            });
        int remaining = 255;
        for (int index = 1; index < 4; ++index) {
            vertex.weights[index] = static_cast<std::uint8_t>(
                (std::min)(remaining, influence[index].weight));
            remaining -= vertex.weights[index];
        }
        vertex.weights[0] = static_cast<std::uint8_t>(remaining);
        for (int index = 0; index < 4; ++index)
            vertex.jointIdxs[index] = static_cast<std::uint8_t>(
                influence[index].joint);
    }
    if (!lexer.ExpectTokenString("}")) return false;

    if (!lexer.ExpectTokenString("tris")) return false;
    const int triangleCount = lexer.ParseInt();
    if (triangleCount < 0 || triangleCount > (1 << 23) ||
            !lexer.ExpectTokenString("{")) return false;
    parsed.indexes.SetNum(triangleCount * 3);
    parsed.faceMaterialIndex.SetNum(triangleCount);
    for (int triangle = 0; triangle < triangleCount; ++triangle) {
        if (!lexer.ExpectTokenString("tri")) return false;
        lexer.ParseInt();
        const int material = version >= 5 ? lexer.ParseInt() : 0;
        if (material < 0 || material >= shaders.Num()) return false;
        parsed.faceMaterialIndex[triangle] = material;
        for (int corner = 0; corner < 3; ++corner) {
            const int vertex = lexer.ParseInt();
            if (vertex < 0 || vertex >= vertexCount) return false;
            parsed.indexes[triangle * 3 + corner] = vertex;
        }
    }
    if (!lexer.ExpectTokenString("}") || !lexer.ExpectTokenString("}"))
        return false;
    DeriveSurfaceVectors(parsed, exportedNormals);

    for (int materialIndex = 0; materialIndex < shaders.Num(); ++materialIndex) {
        std::vector<int> triangles;
        for (int triangle = 0; triangle < triangleCount; ++triangle)
            if (parsed.faceMaterialIndex[triangle] == materialIndex)
                triangles.push_back(triangle);
        if (triangles.empty()) continue;
        idProcessSurface templateSurface;
        templateSurface.name = meshName;
        templateSurface.material = shaders[materialIndex];
        templateSurface.discrete = discrete ||
            (materialDiscreteCallback != nullptr &&
                materialDiscreteCallback(templateSurface.material));
        templateSurface.allowSkinRemapping = allowSkinRemapping;
        templateSurface.numTexCoordSets = uvSetCount;
        templateSurface.sourceOrdinal = surfaces.Num();
        templateSurface.mesh = parsed;
        idProcessSurface* surface = CopyTriangleRange(
            templateSurface, triangles);
        if (surface == nullptr) return false;
        surfaces.Append(surface);
    }
    return true;
}

void idMD6BinaryGenerator::CreateHashST() {
    for (int surfaceIndex = 0; surfaceIndex < surfaces.Num(); ++surfaceIndex) {
        idProcessMesh& mesh = surfaces[surfaceIndex]->mesh;
        unsigned int hash = 2166136261u;
        for (int uv = 0; uv < mesh.uvs.Num(); ++uv) {
            hash ^= mesh.uvs[uv].slot;
            hash *= 16777619u;
        }
        mesh.hashST = static_cast<int>(hash);
    }
}

void idMD6BinaryGenerator::SetupJointRemap() {
    if (skeleton == nullptr || skeleton->data == nullptr) return;
    const int jointCount = skeleton->data->numJoints;
    std::vector<bool> used(jointCount, false);
    for (int surface = 0; surface < surfaces.Num(); ++surface) {
        for (int vertex = 0; vertex < surfaces[surface]->mesh.vertexes.Num();
                ++vertex) {
            const processVert_t& value = surfaces[surface]->mesh.vertexes[vertex];
            for (int weight = 0; weight < 4; ++weight)
                if (value.weights[weight] != 0 &&
                        value.jointIdxs[weight] < jointCount)
                    used[value.jointIdxs[weight]] = true;
        }
    }
    if (jointCount > 0) used[0] = true;
    jointRemap.SetNum(Pad8(jointCount));
    for (int index = 0; index < jointRemap.Num(); ++index)
        jointRemap[index] = static_cast<unsigned char>(index);
    if (remapForSkinning) {
        int compact = 0;
        for (int joint = 0; joint < jointCount; ++joint)
            if (used[joint]) jointRemap[joint] =
                static_cast<unsigned char>(compact++);
        for (int surface = 0; surface < surfaces.Num(); ++surface) {
            idProcessMesh& mesh = surfaces[surface]->mesh;
            for (int vertex = 0; vertex < mesh.vertexes.Num(); ++vertex)
                for (int weight = 0; weight < 4; ++weight)
                    mesh.vertexes[vertex].jointIdxs[weight] =
                        jointRemap[mesh.vertexes[vertex].jointIdxs[weight]];
        }
    }
    for (int surface = 0; surface < surfaces.Num(); ++surface)
        UpdateJointRange(surfaces[surface]->mesh);
}

void idMD6BinaryGenerator::SplitMeshesForJointLimit(
        const int maxJointsPerSurface) {
    if (maxJointsPerSurface <= 0) return;
    idList<idProcessSurface*, 5> replacements;
    for (int surfaceIndex = 0; surfaceIndex < surfaces.Num(); ++surfaceIndex) {
        idProcessSurface* source = surfaces[surfaceIndex];
        if (source == nullptr || source->mesh.maxJoint -
                source->mesh.minJoint + 1 <= maxJointsPerSurface) {
            replacements.Append(source);
            surfaces[surfaceIndex] = nullptr;
            continue;
        }
        std::vector<int> group;
        int groupMin = 255, groupMax = 0;
        const int triangleCount = source->mesh.indexes.Num() / 3;
        for (int triangle = 0; triangle < triangleCount; ++triangle) {
            int triangleMin = 255, triangleMax = 0;
            for (int corner = 0; corner < 3; ++corner) {
                const processVert_t& vertex = source->mesh.vertexes[
                    source->mesh.indexes[triangle * 3 + corner]];
                for (int weight = 0; weight < 4; ++weight) {
                    if (vertex.weights[weight] == 0) continue;
                    triangleMin = (std::min)(triangleMin,
                        static_cast<int>(vertex.jointIdxs[weight]));
                    triangleMax = (std::max)(triangleMax,
                        static_cast<int>(vertex.jointIdxs[weight]));
                }
            }
            const int combinedMin = group.empty() ? triangleMin :
                (std::min)(groupMin, triangleMin);
            const int combinedMax = group.empty() ? triangleMax :
                (std::max)(groupMax, triangleMax);
            if (!group.empty() && combinedMax - (combinedMin & ~3) + 1 >
                    maxJointsPerSurface) {
                replacements.Append(CopyTriangleRange(*source, group));
                group.clear();
                groupMin = 255;
                groupMax = 0;
            }
            group.push_back(triangle);
            groupMin = (std::min)(groupMin, triangleMin);
            groupMax = (std::max)(groupMax, triangleMax);
        }
        if (!group.empty()) replacements.Append(CopyTriangleRange(*source, group));
        delete source;
        surfaces[surfaceIndex] = nullptr;
    }
    surfaces.ClearFree();
    surfaces.Swap(replacements);
}

void idMD6BinaryGenerator::SplitMeshesForIndexLimit(
        const int maxIndexesPerSurface) {
    if (maxIndexesPerSurface < 3) return;
    const int maxTriangles = maxIndexesPerSurface / 3;
    idList<idProcessSurface*, 5> replacements;
    for (int surfaceIndex = 0; surfaceIndex < surfaces.Num(); ++surfaceIndex) {
        idProcessSurface* source = surfaces[surfaceIndex];
        const int triangleCount = source->mesh.indexes.Num() / 3;
        if (triangleCount <= maxTriangles &&
                source->mesh.vertexes.Num() <= 65535) {
            replacements.Append(source);
            surfaces[surfaceIndex] = nullptr;
            continue;
        }
        for (int first = 0; first < triangleCount; first += maxTriangles) {
            std::vector<int> group;
            const int end = (std::min)(triangleCount, first + maxTriangles);
            for (int triangle = first; triangle < end; ++triangle)
                group.push_back(triangle);
            replacements.Append(CopyTriangleRange(*source, group));
        }
        delete source;
        surfaces[surfaceIndex] = nullptr;
    }
    surfaces.ClearFree();
    surfaces.Swap(replacements);
}

void idMD6BinaryGenerator::MergeMeshesAndBuildSourceSurfaces(
        const int maxJointsPerSurface) {
    sourceSurfaces.Clear();
    idList<idProcessSurface*, 5> merged;
    for (int sourceIndex = 0; sourceIndex < surfaces.Num(); ++sourceIndex) {
        idProcessSurface* source = surfaces[sourceIndex];
        int destinationIndex = -1;
        if (!source->discrete) {
            for (int candidate = 0; candidate < merged.Num(); ++candidate) {
                idProcessSurface* destination = merged[candidate];
                const bool materialsCompatible = source->material ==
                    destination->material || (materialMergeCallback != nullptr &&
                    materialMergeCallback(source->material,
                        destination->material));
                const int jointMin = (std::min)(source->mesh.minJoint,
                    destination->mesh.minJoint);
                const int jointMax = (std::max)(source->mesh.maxJoint,
                    destination->mesh.maxJoint);
                if (!destination->discrete && materialsCompatible &&
                        source->mesh.hashST == destination->mesh.hashST &&
                        source->allowSkinRemapping ==
                            destination->allowSkinRemapping &&
                        jointMax - jointMin + 1 <= maxJointsPerSurface &&
                        source->mesh.indexes.Num() +
                            destination->mesh.indexes.Num() <= 65535 &&
                        source->mesh.vertexes.Num() +
                            destination->mesh.vertexes.Num() <= 65535) {
                    destinationIndex = candidate;
                    break;
                }
            }
        }
        if (destinationIndex < 0) {
            destinationIndex = merged.Append(source);
            surfaces[sourceIndex] = nullptr;
            sourceSurface_t mapping{};
            mapping.mtr = source->material;
            mapping.mtrChecksum = materialChecksumCallback != nullptr &&
                    source->material != nullptr
                ? static_cast<int>(materialChecksumCallback(source->material)) : 0;
            mapping.renderSurface = destinationIndex;
            mapping.firstVertex = 0;
            mapping.lastVertex = source->mesh.vertexes.Num() - 1;
            sourceSurfaces.Append(mapping);
            continue;
        }
        idProcessSurface* destination = merged[destinationIndex];
        const int vertexBase = destination->mesh.vertexes.Num();
        for (int vertex = 0; vertex < source->mesh.vertexes.Num(); ++vertex)
            destination->mesh.vertexes.Append(source->mesh.vertexes[vertex]);
        for (int uv = 0; uv < destination->mesh.uvs.Num(); ++uv)
            for (int vertex = 0; vertex < source->mesh.uvs[uv].st.Num(); ++vertex)
                destination->mesh.uvs[uv].st.Append(source->mesh.uvs[uv].st[vertex]);
        for (int index = 0; index < source->mesh.indexes.Num(); ++index)
            destination->mesh.indexes.Append(
                source->mesh.indexes[index] + vertexBase);
        UpdateJointRange(destination->mesh);
        sourceSurface_t mapping{};
        mapping.mtr = source->material;
        mapping.mtrChecksum = materialChecksumCallback != nullptr &&
                source->material != nullptr
            ? static_cast<int>(materialChecksumCallback(source->material)) : 0;
        mapping.renderSurface = destinationIndex;
        mapping.firstVertex = vertexBase;
        mapping.lastVertex = vertexBase + source->mesh.vertexes.Num() - 1;
        sourceSurfaces.Append(mapping);
        delete source;
        surfaces[sourceIndex] = nullptr;
    }
    surfaces.ClearFree();
    surfaces.Swap(merged);
}

bool idMD6BinaryGenerator::LoadAndProcessText(const char* sourceModel) {
    Clear();
    if (sourceModel == nullptr || fileSystem == nullptr) return false;
    idLexer lexer(LEXFL_NOSTRINGCONCAT | LEXFL_NOSTRINGESCAPECHARS |
        LEXFL_ALLOWPATHNAMES);
    if (!lexer.LoadFile(sourceModel, false)) return false;
    idToken versionToken;
    if (!lexer.ReadToken(versionToken)) return false;
    const int version = lexer.ParseInt();
    if (version != MD6_MODEL_VERSION) {
        lexer.Error("Invalid version %d. Should be version %d", version,
            MD6_MODEL_VERSION);
        return false;
    }
    sourceFileName = sourceModel;
    timestamp = lexer.fileTime;
    bool exportedNormals = false;
    int numMeshes = 0, numModelJoints = 0;
    idStr morphMapName;
    if (!lexer.ExpectTokenString("init") ||
            !lexer.ExpectTokenString("{")) return false;
    idToken token;
    while (lexer.ReadToken(token)) {
        if (idStr::Cmp(token.c_str(), "}") == 0) break;
        if (idStr::Icmp(token.c_str(), "skeleton") == 0) {
            idStr skeletonName;
            if (!ReadStringToken(lexer, skeletonName)) return false;
            skeleton = skeletonResolverCallback != nullptr
                ? skeletonResolverCallback(skeletonName.c_str())
                : static_cast<idMD6Skel*>(idMD6Skel::resourceList.Load(
                    skeletonName.c_str(), false, false));
            if (skeleton == nullptr || skeleton->data == nullptr) return false;
            skelTimestamp = fileSystem->GetTimestamp(
                skeletonName.c_str(), false);
        } else if (idStr::Icmp(token.c_str(), "numMeshes") == 0) {
            numMeshes = lexer.ParseInt();
        } else if (idStr::Icmp(token.c_str(), "numJoints") == 0) {
            numModelJoints = lexer.ParseInt();
        } else if (idStr::Icmp(token.c_str(), "remapForSkinning") == 0) {
            remapForSkinning = lexer.ParseBool();
        } else if (idStr::Icmp(token.c_str(), "exportNormals") == 0) {
            exportedNormals = lexer.ParseBool();
        } else if (idStr::Icmp(token.c_str(), "minExpand") == 0) {
            if (!lexer.Parse1DMatrix(3, &minBoundsExpansion.x)) return false;
        } else if (idStr::Icmp(token.c_str(), "maxExpand") == 0) {
            if (!lexer.Parse1DMatrix(3, &maxBoundsExpansion.x)) return false;
        } else if (idStr::Icmp(token.c_str(), "morphMap") == 0) {
            if (!ReadStringToken(lexer, morphMapName)) return false;
        } else if (idStr::Icmp(token.c_str(), "morphSkin") == 0) {
            if (!ReadStringToken(lexer, morphSkinName)) return false;
        } else if (idStr::Icmp(token.c_str(), "commandLine") == 0 ||
                idStr::Icmp(token.c_str(), "sourceFile") == 0) {
            idStr ignored;
            if (!ReadStringToken(lexer, ignored)) return false;
        } else if (idStr::Icmp(token.c_str(), "numUserChannels") == 0 ||
                idStr::Icmp(token.c_str(), "numWeightSets") == 0) {
            lexer.ParseInt();
        } else {
            lexer.Error("Unknown token: %s", token.c_str());
            return false;
        }
    }
    if (skeleton == nullptr || skeleton->data == nullptr || numMeshes <= 0)
        return false;
    if (numModelJoints == 0) numModelJoints = skeleton->data->numJoints;
    if (numModelJoints < 0 || numModelJoints > MAX_JOINTS) return false;
    idList<short, 5> modelToSkeleton;
    modelToSkeleton.SetNum(numModelJoints);
    if (!lexer.ExpectTokenString("joints") ||
            !lexer.ExpectTokenString("{")) return false;
    for (int joint = 0; joint < numModelJoints; ++joint) {
        idStr name;
        if (!ReadStringToken(lexer, name)) return false;
        const md6JointIndex_t skeletonIndex = skeleton->GetJointIndex(
            name.c_str());
        if (!skeletonIndex.IsValid()) return false;
        modelToSkeleton[joint] = skeletonIndex.Get();
    }
    if (!lexer.ExpectTokenString("}")) return false;
    for (int mesh = 0; mesh < numMeshes; ++mesh)
        if (!lexer.ExpectTokenString("mesh") || !ParseMesh(lexer, version,
                numModelJoints, exportedNormals, modelToSkeleton)) return false;

    idList<vertexMorphOffset_t, 5> morphOffsets;
    const float* translations = skeleton->BaseTranslations();
    const idVec3 offset = translations != nullptr
        ? idVec3(translations[0], translations[1], translations[2])
        : idVec3(0.0f, 0.0f, 0.0f);
    LoadMorphMap(morphMapName.c_str(), offset, morphOffsets);
    if (morphOffsets.Num() > 0)
        for (int surface = 0; surface < surfaces.Num(); ++surface)
            MatchMorphVerts(morphOffsets, surfaces[surface]->mesh.vertexes);
    CreateHashST();
    SetupJointRemap();
    SplitMeshesForJointLimit(145);
    SplitMeshesForIndexLimit(65535);
    MergeMeshesAndBuildSourceSurfaces(145);
    return !lexer.HadError();
}

bool idMD6BinaryGenerator::PopulateModel(idMD6Model& model) const {
    if (skeleton == nullptr || skeleton->data == nullptr) return false;
    model.FreeData();
    model.filename = sourceFileName;
    model.timestamp = timestamp;
    model.skelTimestamp = skelTimestamp;
    model.remapForSkinning = remapForSkinning;
    model.morphSkinName = morphSkinName;
    model.skeleton = skeleton;
    if (!model.jointRemap.SetNum(jointRemap.Num())) return false;
    for (int index = 0; index < jointRemap.Num(); ++index)
        model.jointRemap[index] = jointRemap[index];
    model.sourceSurfaces = sourceSurfaces;
    model.numMeshesBeforeSplitting = sourceSurfaces.Num();
    model.minBoundsExpansion = minBoundsExpansion;
    model.maxBoundsExpansion = maxBoundsExpansion;
    model.defaultBounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    model.defaultBounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
    if (!model.meshes.SetNum(surfaces.Num())) return false;
    for (int index = 0; index < surfaces.Num(); ++index) model.meshes[index] = nullptr;
    for (int surfaceIndex = 0; surfaceIndex < surfaces.Num(); ++surfaceIndex) {
        const idProcessSurface& source = *surfaces[surfaceIndex];
        idMD6Mesh* mesh = new (std::nothrow) idMD6Mesh;
        if (mesh == nullptr || mesh->tris == nullptr) {
            delete mesh;
            model.FreeData();
            return false;
        }
        model.meshes[surfaceIndex] = mesh;
        mesh->name = source.name;
        mesh->material = source.material;
        mesh->discrete = source.discrete;
        mesh->allowSkinRemapping = source.allowSkinRemapping;
        mesh->numTexCoordSets = source.mesh.uvs.Num();
        mesh->numVerts = source.mesh.vertexes.Num();
        mesh->numTris = source.mesh.indexes.Num() / 3;
        mesh->jointOffset = source.mesh.minJoint;
        mesh->numJoints = source.mesh.maxJoint - source.mesh.minJoint + 1;
        mesh->hashST = source.mesh.hashST;
        mesh->tris->numVerts = mesh->numVerts;
        mesh->tris->numIndexes = source.mesh.indexes.Num();
        mesh->tris->verts = mesh->numVerts > 0
            ? new (std::nothrow) idDrawVert[mesh->numVerts] : nullptr;
        mesh->tris->indexes = mesh->tris->numIndexes > 0
            ? new (std::nothrow) std::uint16_t[mesh->tris->numIndexes]
            : nullptr;
        if ((mesh->numVerts > 0 && mesh->tris->verts == nullptr) ||
                (mesh->tris->numIndexes > 0 && mesh->tris->indexes == nullptr)) {
            model.FreeData();
            return false;
        }
        mesh->bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
        mesh->bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
        const int baseUv = FindBaseUvSet(source.mesh);
        const bool hasMorph = morphSkinName.Length() > 0;
        if (hasMorph) mesh->morphMap.SetNum(mesh->numVerts * 4);
        for (int vertexIndex = 0; vertexIndex < mesh->numVerts; ++vertexIndex) {
            const processVert_t& sourceVertex = source.mesh.vertexes[vertexIndex];
            idDrawVert& destination = mesh->tris->verts[vertexIndex];
            std::memset(&destination, 0, sizeof(destination));
            destination.xyz = sourceVertex.xyz;
            if (baseUv >= 0) destination.st =
                source.mesh.uvs[baseUv].st[vertexIndex];
            destination.SetNormal(sourceVertex.normal);
            destination.SetTangent(idVec3(sourceVertex.tangent.x,
                sourceVertex.tangent.y, sourceVertex.tangent.z));
            destination.normal[3] = CompressWeightsToByte(sourceVertex.weights);
            destination.tangent[3] = sourceVertex.tangent.w >= 0.0f ? 255 : 0;
            for (int weight = 0; weight < 4; ++weight)
                destination.color[weight] = sourceVertex.weights[weight] != 0
                    ? static_cast<std::uint8_t>(sourceVertex.jointIdxs[weight] -
                        mesh->jointOffset)
                    : destination.color[0];
            if (hasMorph)
                std::memcpy(mesh->morphMap.Ptr() + vertexIndex * 4,
                    sourceVertex.morph, 4);
            for (int component = 0; component < 3; ++component) {
                mesh->bounds[0][component] = (std::min)(
                    mesh->bounds[0][component], sourceVertex.xyz[component]);
                mesh->bounds[1][component] = (std::max)(
                    mesh->bounds[1][component], sourceVertex.xyz[component]);
                model.defaultBounds[0][component] = (std::min)(
                    model.defaultBounds[0][component], sourceVertex.xyz[component]);
                model.defaultBounds[1][component] = (std::max)(
                    model.defaultBounds[1][component], sourceVertex.xyz[component]);
            }
        }
        mesh->tris->bounds = mesh->bounds;
        for (int index = 0; index < mesh->tris->numIndexes; ++index)
            mesh->tris->indexes[index] = static_cast<std::uint16_t>(
                source.mesh.indexes[index]);
        for (int uv = 0; uv < source.mesh.uvs.Num(); ++uv) {
            if (source.mesh.uvs[uv].slot == 0) continue;
            idMD6Mesh::stset_t set;
            set.slot = source.mesh.uvs[uv].slot;
            set.vb = nullptr;
            set.st = source.mesh.uvs[uv].st;
            mesh->stSets.Append(set);
        }
    }
    model.defaultBounds[0] = model.defaultBounds[0] + minBoundsExpansion;
    model.defaultBounds[1] = model.defaultBounds[1] + maxBoundsExpansion;
    return true;
}

bool idMD6BinaryGenerator::WriteBinaryFile(const char* fileName) const {
    idMD6Model model;
    return PopulateModel(model) && model.WriteBinary(fileName);
}

bool idMD6BinaryGenerator::GenerateModel(idMD6Model* model,
        const char* sourceFileName) {
    if (model == nullptr) return false;
    idMD6BinaryGenerator generator;
    return generator.LoadAndProcessText(sourceFileName) &&
        generator.PopulateModel(*model);
}
