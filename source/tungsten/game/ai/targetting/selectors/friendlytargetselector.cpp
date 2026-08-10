#include "friendlytargetselector.h"
#include "../targetfilter.h"

namespace {

constexpr float MAX_DISTANCE_SQR_RECIPROCAL = 0.00000023841858f;

float DistanceFraction(const float distanceSqr) {
    const float fraction = distanceSqr * MAX_DISTANCE_SQR_RECIPROCAL;
    return fraction < 1.0f ? fraction : 1.0f;
}

} // namespace

// Retail symbol:
// ?GetWeight@idFriendlyTargetSelector@@UBAMPBVidEntity@@ABVidTargetInfo@@@Z
// EA: 0x82B031C0, RVA: 0x00B031C0
float idFriendlyTargetSelector::GetWeight(
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
    const float relationship = Tungsten_FloatForTargetAttitude(
        static_cast<int>(target->attitude));
    const float visibility = Tungsten_IsVisibleAIEntityState(target->es)
        ? 1.0f : 0.5f;
    const float distance = DistanceFraction(target->distSqr);
    const float angle = (facing + 1.0f) * 0.5f;
    float weight = (relationship * (1.0f / 6.0f) * 0.5f
        + (1.0f - distance) * 0.25f + angle * 0.25f) * visibility;
    if (awareness == AIAWARE_SUSPECTED) {
        weight *= 0.5f;
    }
    return weight;
}
