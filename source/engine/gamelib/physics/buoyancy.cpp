#include "gamelib/physics/buoyancy.h"

#include "gamelib/physics/physics.h"

#include <algorithm>
#include <cmath>

struct idBuoyancySample {
    idVec3 position;
    float weight;
};

int GameLib_GetBuoyancySamples(const idClipModel* clipModel,
    idBuoyancySample* samples, int maxSamples);
void GameLib_TransformBuoyancySample(const idClipModel* clipModel,
    const idVec3& localPosition, idVec3& worldPosition);
int GameLib_EvaluateBuoyantBodies(idClip* clip, idPhysics* physics,
    int clipMask, surfTypes_t surfaceOverride, idBuoyancyResult* results,
    int maxResults);
void GameLib_ApplyWaterDamage(const idDeclDamage* damage,
    idPhysics* physics, int bodyId, float waterLevel);

idBuoyancy::idBuoyancy()
    : buoyantClipModels() {
}

void idBuoyancy::CalculateBuoyancyWeights(
    const int* const polytopeNumPlanes,
    const idPlane* const polytopePlanes, const int numPolytopes,
    const idClipModel* const clipModel, float* const weights) {
    if (weights == nullptr || numPolytopes <= 0) {
        return;
    }
    for (int polytope = 0; polytope < numPolytopes; ++polytope) {
        weights[polytope] = 0.0f;
    }
    if (polytopeNumPlanes == nullptr || polytopePlanes == nullptr ||
        clipModel == nullptr) {
        return;
    }

    idBuoyancySample samples[64]{};
    const int sampleCount = (std::max)(0, (std::min)(64,
        GameLib_GetBuoyancySamples(clipModel, samples, 64)));
    int firstPlane = 0;
    for (int polytope = 0; polytope < numPolytopes; ++polytope) {
        const int planeCount = (std::max)(0,
            polytopeNumPlanes[polytope]);
        for (int sampleIndex = 0; sampleIndex < sampleCount;
             ++sampleIndex) {
            idVec3 worldPosition;
            GameLib_TransformBuoyancySample(clipModel,
                samples[sampleIndex].position, worldPosition);
            bool inside = true;
            for (int planeIndex = 0; planeIndex < planeCount;
                 ++planeIndex) {
                const idPlane& plane = polytopePlanes[
                    firstPlane + planeIndex];
                if (plane.Distance(worldPosition) > 0.0f) {
                    inside = false;
                    break;
                }
            }
            if (inside) {
                weights[polytope] += samples[sampleIndex].weight;
            }
        }
        firstPlane += planeCount;
    }
}

void idBuoyancy::ApplyBuoyancy(idClip* const clip,
    idPhysics* const physics, const float timeStep,
    const idDeclDamage* const waterDamage, const idVec3& waterCurrent,
    const float waterDensity, const float waterViscosity,
    const int clipMask, const surfTypes_t surfaceOverride) {
    buoyantClipModels.Clear();
    if (clip == nullptr || physics == nullptr || timeStep <= 0.0f) {
        return;
    }

    idBuoyancyResult results[128]{};
    const int resultCount = (std::max)(0, (std::min)(128,
        GameLib_EvaluateBuoyantBodies(clip, physics, clipMask,
            surfaceOverride, results, 128)));
    float maximumWaterLevel = 0.0f;
    for (int index = 0; index < resultCount; ++index) {
        const idBuoyancyResult& result = results[index];
        if (result.displacedVolume <= 0.0f) {
            continue;
        }
        buoyantClipModel_t body{};
        body.physicsId = physics->GetPhysicsId();
        body.bodyId = result.bodyId;
        buoyantClipModels.Append(body);

        const idVec3 gravity = *physics->GetGravity();
        const idVec3 buoyancyForce = gravity *
            (-waterDensity * result.displacedVolume);
        const idVec3 relativeVelocity = waterCurrent -
            result.linearVelocity;
        const idVec3 dragForce = relativeVelocity *
            (waterViscosity * result.displacedVolume);
        const idVec3 totalForce = buoyancyForce + dragForce;
        physics->ApplyForce(result.bodyId, &result.centerOfBuoyancy,
            &totalForce);
        maximumWaterLevel = (std::max)(maximumWaterLevel,
            result.waterLevel);
        if (waterDamage != nullptr && result.waterLevel > 0.0f) {
            GameLib_ApplyWaterDamage(waterDamage, physics, result.bodyId,
                result.waterLevel);
        }
    }
    physics->SetWaterLevel(maximumWaterLevel, -1);
    physics->SetWaterViscosity(waterViscosity, -1);
}
