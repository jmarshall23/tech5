#include "game/entities/bouncesparks.h"

#include <cmath>

namespace {
idBounceSparksServices defaultBounceSparksServices;
idBounceSparksServices* bounceSparksServices = &defaultBounceSparksServices;

int RandomDelayMilliseconds(idBounceSparksServices& services,
        const float minimum, const float maximum) {
    return static_cast<int>((minimum
        + (maximum - minimum) * services.RandomFloat()) * 1000.0f);
}

idMat3 DirectionBasis(const idVec3& direction) {
    idVec3 forward = direction;
    if (forward.NormalizeFast() == 0.0f) {
        forward.Set(0.0f, 0.0f, -1.0f);
    }
    idVec3 reference = std::fabs(forward.z) > 0.7f
        ? idVec3(0.0f, 1.0f, 0.0f)
        : idVec3(0.0f, 0.0f, 1.0f);
    idVec3 left = reference.Cross(forward);
    left.NormalizeFast();
    idVec3 down = forward.Cross(left);
    down.NormalizeFast();
    return idMat3(
        forward.x, forward.y, forward.z,
        left.x, left.y, left.z,
        down.x, down.y, down.z);
}
}

void idBounceSparks::SetServices(idBounceSparksServices* const services) {
    bounceSparksServices = services == nullptr
        ? &defaultBounceSparksServices : services;
}

idBounceSparksServices& idBounceSparks::Services() {
    return *bounceSparksServices;
}

// Retail: 0x82C0BFA8 ?Spawn@idBounceSparks@@QAAXXZ
void idBounceSparks::Spawn() {
    Services().SetThinkActive(*this, true);
    if (declBreakable == nullptr || minTimeBetweenBursts < 0.0f
            || maxTimeBetweenBursts < 0.0f
            || maxTimeBetweenBursts < minTimeBetweenBursts) {
        Services().ReportBadData(*this);
        return;
    }
    idVec3 origin;
    Services().GetOrigin(*this, origin);
    Services().AddBreakable(declBreakable, origin);
    nextSparkTime = Services().GetGameMilliseconds()
        + RandomDelayMilliseconds(Services(),
            minTimeBetweenBursts, maxTimeBetweenBursts);
}

// Retail: 0x82C0C0F8 ??0idBounceSparks@@QAA@XZ
idBounceSparks::idBounceSparks()
    : declBreakable(nullptr), minTimeBetweenBursts(10.0f),
      maxTimeBetweenBursts(10.0f),
      burstDirection(0.0f, 0.0f, -1.0f), impulse(100.0f),
      sparkTimings(), nextSparkTime(0) {
}

// Retail: 0x82C0C1D0 ??1idBounceSparks@@UAA@XZ
idBounceSparks::~idBounceSparks() {
    sparkTimings.Clear();
}

// Retail: 0x82C0C258 ?Think@idBounceSparks@@UAAXXZ
void idBounceSparks::Think() {
    const int currentTime = Services().GetGameMilliseconds();
    if (currentTime <= nextSparkTime) {
        return;
    }
    nextSparkTime = currentTime
        + RandomDelayMilliseconds(Services(),
            minTimeBetweenBursts, maxTimeBetweenBursts);

    const idMat3 axis = DirectionBasis(burstDirection);
    idVec3 origin;
    Services().GetOrigin(*this, origin);
    const idVec3 position(
        origin.x - burstDirection.x,
        origin.y - burstDirection.y,
        origin.z - burstDirection.z);

    idList<int, 5> activationTimes;
    activationTimes.SetNum(sparkTimings.Num());
    for (int index = 0; index < sparkTimings.Num(); ++index) {
        activationTimes[index] = RandomDelayMilliseconds(Services(),
            sparkTimings[index].minDelay,
            sparkTimings[index].maxDelay);
    }
    Services().UseBreakable(declBreakable, origin, axis,
        burstDirection, position, impulse, activationTimes);
}
