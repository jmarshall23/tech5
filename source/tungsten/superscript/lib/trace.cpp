#include "trace.h"

#include <cmath>

// ?Resolve@ssTrace@@AAAXXZ (0x82EE8958)
void ssTrace::Resolve() {
    if (resolved) {
        return;
    }

    int hitSpawnId = 0;
    Tungsten_GetSuperScriptTraceResults(
        clipQueryId, hitFraction, hitNormal, hitSpawnId);
    hitEnt = ssEntity(hitSpawnId);
    hitLength = length * hitFraction;
    hitPos.x = startPos.x + rayDir.x * hitLength;
    hitPos.y = startPos.y + rayDir.y * hitLength;
    hitPos.z = startPos.z + rayDir.z * hitLength;
    resolved = true;
}

// ??0ssTrace@@QAA@VssVector@@0HVssEntity@@@Z (0x82EE8A20)
ssTrace::ssTrace(const ssVector start, const ssVector end,
        const int traceContentMask, const ssEntity ignoredEntity)
    : startPos(start), endPos(end), rayDir{0.0f, 0.0f, 0.0f},
      contentMask(traceContentMask), ignoreEnt(ignoredEntity), length(0.0f),
      clipQueryId(0), resolved(false), hitEnt(),
      hitPos{0.0f, 0.0f, 0.0f}, hitNormal{0.0f, 0.0f, 0.0f} {
    rayDir.x = endPos.x - startPos.x;
    rayDir.y = endPos.y - startPos.y;
    rayDir.z = endPos.z - startPos.z;
    length = std::sqrt(rayDir.x * rayDir.x + rayDir.y * rayDir.y
        + rayDir.z * rayDir.z);
    const float inverseLength = 1.0f / length;
    rayDir.x *= inverseLength;
    rayDir.y *= inverseLength;
    rayDir.z *= inverseLength;
    clipQueryId = Tungsten_TraceSuperScriptPoints(
        startPos, endPos, contentMask, ignoreEnt.spawnId);
}
