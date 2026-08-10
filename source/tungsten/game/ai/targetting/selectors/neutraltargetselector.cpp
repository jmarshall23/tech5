#include "neutraltargetselector.h"
#include "../targetfilter.h"

namespace {

constexpr float MAX_DISTANCE_SQR_RECIPROCAL = 0.00000023841858f;
constexpr float REAR_ANGLE_COSINE = -0.96592599f;

float DistanceFraction(const float distanceSqr) {
    const float fraction = distanceSqr * MAX_DISTANCE_SQR_RECIPROCAL;
    return fraction < 1.0f ? fraction : 1.0f;
}

} // namespace

// Retail symbol:
// ?GetWeight@idNeutralTargetSelector@@UBAMPBVidEntity@@ABVidTargetInfo@@@Z
// EA: 0x82B032F0, RVA: 0x00B032F0
float idNeutralTargetSelector::GetWeight(
        const idEntity* const owner, const idTargetInfo* const target) const {
    (void)owner;
    if (target->es == nullptr || Tungsten_IsDeadAIEntityState(target->es)) {
        return 0.0f;
    }

    const int awareness = Tungsten_GetAIAwareness(target->es);
    if (awareness < AIAWARE_SUSPECTED) {
        return 0.0f;
    }

    const float facing = ownerDir.Dot(target->dirTo);
    const float angle = facing <= REAR_ANGLE_COSINE
        ? 0.0f : (facing + 1.0f) * 0.5f;
    const float visibility = Tungsten_IsVisibleAIEntityState(target->es)
        ? 1.0f : 0.5f;
    const float distance = DistanceFraction(target->distSqr);
    float weight = (angle * 0.2f + (1.0f - distance) * 0.8f)
        * visibility;
    if (awareness == AIAWARE_SUSPECTED) {
        weight *= 0.5f;
    }
    return weight;
}
