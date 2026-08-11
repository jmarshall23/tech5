#include "presentableplayer.h"

#include <cmath>

#define playerServices (Tungsten_GetPresentablePlayerServices())

void idPresentablePlayer::PresentablePlayerBehavior_PostEvent(
        idPlayerBehaviorEvent_t event) {
    if (playerServices->IsServer()) {
        playerServices->PostServerPlayerBehaviorEvent(*this,
            static_cast<int>(event));
    }
}

bool idPresentablePlayer::PlayerBehavior_Shared_CheckBlocked(
        const idVec3& startPosition, const idVec3& endPosition,
        float& blockDistance, int entityNumber, bool debug,
        trace_t* trace, int contentMask) {
    const idVec3 displacement = endPosition - startPosition;
    const float distance = displacement.Length();
    const float fraction = (std::max)(0.0f, (std::min)(1.0f,
        playerServices->TracePlayerBehaviorBlock(startPosition, endPosition,
            entityNumber, contentMask, debug, trace)));
    blockDistance = fraction * distance;
    return fraction < 1.0f;
}
