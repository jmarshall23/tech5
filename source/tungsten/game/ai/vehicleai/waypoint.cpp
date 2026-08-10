#include "waypoint.h"

#include <algorithm>

namespace {

constexpr int kInvalidSeat = 0;
constexpr int kArrivalSpacingMilliseconds = 15000;
constexpr int kExpiredArrivalToleranceMilliseconds = 100;
constexpr float kMillisecondsPerSecond = 1000.0f;

} // namespace

idWaypoint::idWaypoint()
    : waypointNode(this) {
}

idSplineWaypoint::idSplineWaypoint()
    : voiceOver(nullptr)
    , voSeat(kInvalidSeat)
    , voiceOver2(nullptr)
    , voSeat2(kInvalidSeat)
    , sound(nullptr) {
}

idDroneSplineWaypoint::idDroneSplineWaypoint()
    : imminentArrivals()
    , imminentEta() {
}

// Retail symbol: ?Spawn@idWaypoint@@QAAXXZ
// EA: 0x82B2B448, RVA: 0x00B2B448
void idWaypoint::Spawn() {
    Tungsten_GetWaypointListHead().AddToEnd(waypointNode);
}

// Retail symbol: ?AiReachedWaypoint@idSplineWaypoint@@QAAXPAVidVehicleAI@@@Z
// EA: 0x82B2B4A8, RVA: 0x00B2B4A8
void idSplineWaypoint::AiReachedWaypoint(idVehicleAI* const ai) {
    if (ai == nullptr) {
        return;
    }
    Tungsten_ApplySplineWaypointControlAndActions(*ai, *this);
    if (voiceOver != nullptr) {
        Tungsten_PlaySplineWaypointVoiceOver(*ai, *voiceOver, voSeat);
    }
    if (voiceOver2 != nullptr) {
        Tungsten_PlaySplineWaypointVoiceOver(*ai, *voiceOver2, voSeat2);
    }
    if (sound != nullptr) {
        Tungsten_PlaySplineWaypointSoundForPlayer(*ai, *sound);
    }
}

// Retail symbol: ?ScheduleDrone@idDroneSplineWaypoint@@QAAMPAVidDrone@@M@Z
// EA: 0x82B2B6F8, RVA: 0x00B2B6F8
float idDroneSplineWaypoint::ScheduleDrone(
        idDrone* const drone, const float eta) {
    const int now = Tungsten_GetWaypointGameMilliseconds();
    const int requestedArrival = now
        + static_cast<int>(eta * kMillisecondsPerSecond);

    int droneIndex = imminentArrivals.FindIndex(drone);
    if (droneIndex < 0) {
        imminentArrivals.Append(drone);
        imminentEta.Append(requestedArrival);
    } else {
        imminentEta[droneIndex] = requestedArrival;
    }

    // The retail code bubble-sorts the paired arrays.  Preserve stable order
    // for equal ETAs because it determines which drone receives a correction.
    bool swapped;
    do {
        swapped = false;
        for (int index = 1; index < imminentEta.Num(); ++index) {
            if (imminentEta[index - 1] > imminentEta[index]) {
                std::swap(imminentEta[index - 1], imminentEta[index]);
                std::swap(imminentArrivals[index - 1],
                    imminentArrivals[index]);
                swapped = true;
            }
        }
    } while (swapped);

    // Exactly one stale head entry is discarded per call in the executable.
    if (imminentEta.Num() > 0
        && imminentEta[0] < now - kExpiredArrivalToleranceMilliseconds) {
        imminentEta.RemoveIndex(0);
        imminentArrivals.RemoveIndex(0);
    }

    const int count = imminentArrivals.Num();
    if (count <= 1) {
        return 0.0f;
    }
    droneIndex = imminentArrivals.FindIndex(drone);
    if (droneIndex < 0 || droneIndex >= count) {
        return 0.0f;
    }

    if (droneIndex == 0) {
        const int nextGap = imminentEta[1] - imminentEta[0] + 1;
        return nextGap < kArrivalSpacingMilliseconds
            ? static_cast<float>(kArrivalSpacingMilliseconds - nextGap)
                / kMillisecondsPerSecond
            : 0.0f;
    }
    if (droneIndex == count - 1) {
        const int previousGap = imminentEta[droneIndex]
            - imminentEta[droneIndex - 1] + 1;
        return previousGap < kArrivalSpacingMilliseconds
            ? -static_cast<float>(kArrivalSpacingMilliseconds - previousGap)
                / kMillisecondsPerSecond
            : 0.0f;
    }

    const int previousGap = imminentEta[droneIndex]
        - imminentEta[droneIndex - 1] + 1;
    const int nextGap = imminentEta[droneIndex + 1]
        - imminentEta[droneIndex] + 1;
    if (nextGap >= previousGap) {
        return previousGap < kArrivalSpacingMilliseconds
            ? -static_cast<float>(
                kArrivalSpacingMilliseconds - previousGap)
                    / kMillisecondsPerSecond
            : 0.0f;
    }
    return nextGap < kArrivalSpacingMilliseconds
        ? static_cast<float>(kArrivalSpacingMilliseconds - nextGap)
            / kMillisecondsPerSecond
        : 0.0f;
}
