#include "gamelib/physics/tracemodelcache.h"

#include "cm/collisionmodel.h"
#include "cm/collisionmodelmanager.h"
#include "idlib/lib_print.h"

#include <cmath>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <limits>
#include <vector>

bool GameLib_IsMultiplayer();

namespace {

std::uint32_t FloatBits(const float value) {
    std::uint32_t bits = 0;
    std::memcpy(&bits, &value, sizeof(bits));
    return bits;
}

int TraceModelHashKey(const idTraceModel& traceModel) {
    const std::uint32_t key =
        (4u * ((4u * ((16u * static_cast<std::uint32_t>(traceModel.type)) ^
            traceModel.numVerts)) ^ traceModel.numEdges)) ^
        traceModel.numPolys ^ FloatBits(traceModel.bounds[0].z) ^
        FloatBits(traceModel.bounds[0].y) ^ FloatBits(traceModel.bounds[0].x);
    return static_cast<int>(key);
}

struct waterPointBuild_t {
    idVec3 xyz;
    float weight;
    float weightSquared;
};

} // namespace

void idTraceModelCache::FreeTraceModel(const int traceModelIndex) {
    trmCache_t* const entry = GetEntry(traceModelIndex);
    if (entry == nullptr || entry->refCount <= 0) {
        idLibPrint::Warning(
            "idClipModel::FreeTraceModel: tried to free uncached trace model");
        return;
    }
    --entry->refCount;
}

int idTraceModelCache::CopyTraceModel(const int traceModelIndex) {
    trmCache_t* const entry = GetEntry(traceModelIndex);
    if (entry == nullptr || entry->refCount <= 0) {
        idLibPrint::Warning(
            "idClipModel::CopyTraceModel: tried to copy an uncached trace "
            "model");
        return -1;
    }
    ++entry->refCount;
    return traceModelIndex;
}

void idTraceModelCache::ClearTraceModelCache() {
    for (int index = 0; index < cache.Num(); ++index) {
        trmCache_t* const entry = cache[index];
        if (entry == nullptr) {
            continue;
        }
        if (entry->collisionModel != nullptr) {
            delete entry->collisionModel;
            entry->collisionModel = nullptr;
        }
        entry->waterPoints.ClearFree();
        delete entry->trm;
        entry->trm = nullptr;
        entry->~trmCache_t();
    }
    cacheAllocator.Shutdown();
    cache.ClearFree();
    hash.Free();
}

void idTraceModelCache::SetupWaterPoints(trmCache_t* const entry) {
    entry->waterPoints.ClearFree();
    entry->hasWater = false;
    if (entry->trm == nullptr || !entry->trm->isConvex ||
        GameLib_IsMultiplayer()) {
        return;
    }

    const idBounds& bounds = entry->trm->bounds;
    const idVec3 dimensions = bounds[1] - bounds[0];
    if (dimensions.x <= 0.0f || dimensions.y <= 0.0f ||
        dimensions.z <= 0.0f ||
        dimensions.x * dimensions.y * dimensions.z == 0.0f) {
        return;
    }

    const int numVertices = static_cast<int>(entry->trm->numVerts);
    const int desiredInteriorPoints = 64 - numVertices;
    if (desiredInteriorPoints < 0) {
        return;
    }

    std::vector<waterPointBuild_t> interiorPoints;
    float sampleMultiplier = 1.0f;
    for (;;) {
        interiorPoints.clear();
        const float divisions = std::cbrt(
            static_cast<float>(desiredInteriorPoints) * sampleMultiplier);
        if (divisions > 0.0f) {
            const idVec3 step(dimensions.x / divisions,
                dimensions.y / divisions, dimensions.z / divisions);
            for (int x = 0; static_cast<float>(x) < divisions; ++x) {
                for (int y = 0; static_cast<float>(y) < divisions; ++y) {
                    for (int z = 0; static_cast<float>(z) < divisions; ++z) {
                        waterPointBuild_t point{};
                        point.xyz.Set(
                            bounds[0].x + (static_cast<float>(x) + 0.5f) * step.x,
                            bounds[0].y + (static_cast<float>(y) + 0.5f) * step.y,
                            bounds[0].z + (static_cast<float>(z) + 0.5f) * step.z);
                        point.weight = 1.0f;
                        point.weightSquared = 1.0f;
                        if (entry->trm->ContainsPoint(point.xyz)) {
                            interiorPoints.push_back(point);
                        }
                    }
                }
            }
        }

        if (static_cast<int>(interiorPoints.size()) >= desiredInteriorPoints) {
            break;
        }
        sampleMultiplier *= 2.0f;
        if (sampleMultiplier > 16.0f) {
            return;
        }
    }

    const float pointWeight = 1.0f /
        static_cast<float>(interiorPoints.size() + numVertices);
    for (waterPointBuild_t& point : interiorPoints) {
        point.weight = pointWeight;
        point.weightSquared = pointWeight * pointWeight;
    }

    while (static_cast<int>(interiorPoints.size()) > desiredInteriorPoints) {
        float bestMetric = (std::numeric_limits<float>::max)();
        int bestFirst = 0;
        int bestSecond = 1;
        for (int first = 0;
             first < static_cast<int>(interiorPoints.size()); ++first) {
            for (int second = first + 1;
                 second < static_cast<int>(interiorPoints.size()); ++second) {
                const idVec3 delta = interiorPoints[first].xyz -
                    interiorPoints[second].xyz;
                const float metric = delta.LengthSqr() *
                    interiorPoints[first].weight *
                    interiorPoints[second].weight;
                if (metric < bestMetric) {
                    bestMetric = metric;
                    bestFirst = first;
                    bestSecond = second;
                }
            }
        }

        waterPointBuild_t& destination = interiorPoints[bestFirst];
        destination.xyz = (destination.xyz +
            interiorPoints[bestSecond].xyz) * 0.5f;
        destination.weight += interiorPoints[bestSecond].weight;
        destination.weightSquared = destination.weight * destination.weight;
        interiorPoints[bestSecond] = interiorPoints.back();
        interiorPoints.pop_back();
    }

    entry->waterPoints.SetNum(64);
    int outputIndex = 0;
    for (const waterPointBuild_t& point : interiorPoints) {
        entry->waterPoints[outputIndex++] = {point.xyz, point.weight};
    }
    for (int vertex = 0; vertex < numVertices && outputIndex < 64; ++vertex) {
        traceModelWater_t& point = entry->waterPoints[outputIndex++];
        point.xyz.Set(entry->trm->vertsX[vertex],
            entry->trm->vertsY[vertex], entry->trm->vertsZ[vertex]);
        point.weight = pointWeight;
    }
    while (outputIndex < 64) {
        entry->waterPoints[outputIndex++] = {idVec3(0.0f, 0.0f, 0.0f), 0.0f};
    }
    entry->hasWater = true;
}

int idTraceModelCache::AllocTraceModel(const idTraceModel& traceModel,
    const idMaterial* const material) {
    const int key = TraceModelHashKey(traceModel);
    for (int index = hash.First(key); index != -1;
         index = hash.Next(index)) {
        trmCache_t* const entry = GetEntry(index);
        if (entry != nullptr && entry->trm != nullptr &&
            entry->trm->Compare(traceModel) && entry->material == material) {
            ++entry->refCount;
            return index;
        }
    }

    trmCache_t* const entry = cacheAllocator.Alloc();
    if (entry == nullptr) {
        return -1;
    }
    entry->trm = new idTraceModel(traceModel);
    entry->trm->ClearUnused();
    entry->trm->GetMassProperties(1.0f, entry->volume,
        entry->centerOfMass, entry->inertiaTensor);
    entry->refCount = 1;
    entry->material = material;
    const int index = cache.Append(entry);
    hash.Add(key, index);
    char modelName[64];
    std::snprintf(modelName, sizeof(modelName), "traceModel%d", index);
    entry->collisionModel = collisionModelManager.ModelFromTrm(
        modelName, *entry->trm, material);
    SetupWaterPoints(entry);
    return index;
}
