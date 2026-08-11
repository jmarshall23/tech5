#include "game/entities/door_laser.h"

#include <algorithm>

namespace {
idDoorLaserServices defaultDoorLaserServices;
idDoorLaserServices* doorLaserServices = &defaultDoorLaserServices;

float Clamp01(const float value) {
    return std::max(0.0f, std::min(1.0f, value));
}

idVec3 Lerp(const idVec3& from, const idVec3& to,
        const float fraction) {
    return from * (1.0f - fraction) + to * fraction;
}

idVec3 TransformRelative(const idVec3& relative, const float halfWidth,
        const float height, const idVec3& origin, const idMat3& axis) {
    const idVec3 local(relative.y, relative.x * halfWidth,
        relative.z * height);
    return origin + axis[0] * local.x
        + axis[1] * local.y + axis[2] * local.z;
}
}

int idDoorLaserServices::GetGameMilliseconds() const { return 0; }
int idDoorLaserServices::GetGameMillisecondsPerFrame() const { return 16; }
bool idDoorLaserServices::UpdateDormant(idDoor_Laser&) { return false; }
float idDoorLaserServices::RandomFloat() { return 0.0f; }
float idDoorLaserServices::RandomFloat(const float minimum,
        float) { return minimum; }
int idDoorLaserServices::RandomInt(int) { return 0; }
void idDoorLaserServices::GetTransform(const idDoor_Laser& door,
        idVec3& resultOrigin, idMat3& resultAxis) const {
    resultOrigin = door.origin;
    resultAxis = door.axis;
}
void idDoorLaserServices::SetPhysicsAxis(idDoor_Laser&,
        const idMat3&) {}
void idDoorLaserServices::BecomeActive(idDoor_Laser&, int) {}
void idDoorLaserServices::StopWeaponSound(idDoor_Laser&) {}
void idDoorLaserServices::PlayWeaponSound(idDoor_Laser&,
        const idSoundShader*) {}
bool idDoorLaserServices::IsTranslationReady(std::uint64_t) const {
    return false;
}
float idDoorLaserServices::GetTranslationFraction(std::uint64_t) {
    return 1.0f;
}
std::uint64_t idDoorLaserServices::SubmitTranslation(
        const idDoor_Laser&, const idVec3&, const idVec3&, int) {
    return ~0ULL;
}
void idDoorLaserServices::EmitSpark(idDoor_Laser&,
        const idDeclParticle*, int, int, float, const idVec3&) {}
void idDoorLaserServices::UpdateBeam(idDoor_Laser&,
        const idMaterial*, float, const idVec3&, const idVec3&, float) {}
void idDoorLaserServices::ShowEntity(idDoor_Laser&) {}

void idDoor_Laser::SetServices(idDoorLaserServices* const services) {
    doorLaserServices = services == nullptr
        ? &defaultDoorLaserServices : services;
}

idDoorLaserServices& idDoor_Laser::Services() {
    return *doorLaserServices;
}

// Retail: 0x82C23570 ?Spawn@idDoor_Laser@@QAAXXZ
void idDoor_Laser::Spawn() {
    shouldBeOpenFlag = startDoorOpenFlag;
    const float initialOpen = startDoorOpenFlag ? 1.0f : 0.0f;
    idVec3 physicsOrigin;
    idMat3 physicsAxis;
    Services().GetTransform(*this, physicsOrigin, physicsAxis);
    origin = physicsOrigin;
    axis = physicsAxis;
    const float halfWidth = doorWidth * 0.5f;
    for (int index = 0; index < bars.Num(); ++index) {
        idDoorLaserBar& bar = bars[index];
        bar.startPosition = TransformRelative(bar.startRelativePosition,
            halfWidth, doorHeight, physicsOrigin, physicsAxis);
        bar.endPosition = TransformRelative(bar.endRelativePosition,
            halfWidth, doorHeight, physicsOrigin, physicsAxis);
        bar.startOpenCloseTime = 0;
        bar.numParts = bar.behavior == 1 ? 2 : 1;
        for (int part = 0; part < bar.numParts; ++part) {
            bar.openPercent[part] = initialOpen;
            bar.clipQuery[part] = ~0ULL;
        }
    }
    axis = idMat3(1.0f);
    Services().SetPhysicsAxis(*this, axis);
    thinkFlags |= 1;
    Services().BecomeActive(*this, 1);
}

// Retail: 0x82C237D8 ?Think@idDoor_Laser@@UAAXXZ
void idDoor_Laser::Think() {
    if (Services().UpdateDormant(*this)) {
        return;
    }
    const int currentTime = Services().GetGameMilliseconds();
    const float target = shouldBeOpenFlag ? 1.0f : 0.0f;
    if (barsAnimatingFlag) {
        barsAnimatingFlag = false;
        for (int index = 0; index < bars.Num(); ++index) {
            idDoorLaserBar& bar = bars[index];
            if (bar.startOpenCloseTime > currentTime) {
                barsAnimatingFlag = true;
                continue;
            }
            bool needsMovement = false;
            for (int part = 0; part < bar.numParts; ++part) {
                needsMovement |= bar.openPercent[part] != target;
            }
            if (!needsMovement) {
                continue;
            }
            barsAnimatingFlag = true;
            if (bar.numParts == 1) {
                if (bar.openPercent[0] < target) {
                    bar.openPercent[0] = std::min(1.0f,
                        bar.openPercent[0] + bar.openSpeed);
                } else if (bar.openPercent[0] > target) {
                    bar.openPercent[0] = std::max(0.0f,
                        bar.openPercent[0] - bar.closeSpeed);
                }
            } else {
                for (int part = 0; part < 2; ++part) {
                    if (bar.openPercent[part] < target) {
                        bar.openPercent[part] += bar.openSpeed;
                    } else if (bar.openPercent[part] > target) {
                        bar.openPercent[part] -= bar.closeSpeed;
                    }
                }
                const float sum = bar.openPercent[0]
                    + bar.openPercent[1];
                if (sum > 1.0f) {
                    if (sum < 2.0f) {
                        bar.openPercent[0] = Clamp01(bar.openPercent[0]);
                        bar.openPercent[1] = Clamp01(bar.openPercent[1]);
                    } else {
                        bar.openPercent[0] = 1.0f;
                        bar.openPercent[1] = 1.0f;
                    }
                } else if (target >= 0.5f) {
                    bar.openPercent[0] = 0.501f;
                    bar.openPercent[1] = 0.501f;
                } else {
                    bar.openPercent[0] = 0.0f;
                    bar.openPercent[1] = 0.0f;
                }
            }
        }
    }

    bool collisionWhileClosing = false;
    if (touchingCount != 0
            && (!shouldBeOpenFlag || barsAnimatingFlag)) {
        for (int index = 0; index < bars.Num(); ++index) {
            idDoorLaserBar& bar = bars[index];
            for (int part = 0; part < bar.numParts; ++part) {
                const std::uint64_t previousQuery = bar.clipQuery[part];
                if (Services().IsTranslationReady(previousQuery)) {
                    bar.clipQuery[part] = ~0ULL;
                    const float fraction =
                        Services().GetTranslationFraction(previousQuery);
                    if (fraction < 0.999f) {
                        const float forcedOpen = Clamp01(
                            barOpenExtraPercent + 1.0f - fraction);
                        const float sparkPercent = Clamp01(
                            sparkBackExtraPercent + 1.0f - fraction);
                        if (forcedOpen > bar.openPercent[part]) {
                            bar.openPercent[part] = forcedOpen;
                            if (currentTime >= bar.nextSparkTime
                                    && sparkParticles.Num() > 0) {
                                const int particleIndex = std::max(0,
                                    std::min(sparkParticles.Num() - 1,
                                        Services().RandomInt(
                                            sparkParticles.Num())));
                                const idVec3 from = part == 0
                                    ? bar.startPosition : bar.endPosition;
                                const idVec3 to = part == 0
                                    ? bar.endPosition : bar.startPosition;
                                Services().EmitSpark(*this,
                                    sparkParticles[particleIndex],
                                    currentTime,
                                    Services().GetGameMillisecondsPerFrame(),
                                    Services().RandomFloat(),
                                    Lerp(from, to, sparkPercent));
                                bar.nextSparkTime = currentTime
                                    + static_cast<int>(
                                        Services().RandomFloat(
                                            sparkDelayMin, sparkDelayMax)
                                        * 1000.0f);
                            }
                        }
                        if (!shouldBeOpenFlag) {
                            collisionWhileClosing = true;
                        }
                        if (!barsAnimatingFlag) {
                            barsAnimatingFlag = true;
                            if (passThroughSound != nullptr) {
                                Services().StopWeaponSound(*this);
                                Services().PlayWeaponSound(
                                    *this, passThroughSound);
                            }
                        }
                    }
                }
                const idVec3& start = part == 0
                    ? bar.startPosition : bar.endPosition;
                const idVec3& end = part == 0
                    ? bar.endPosition : bar.startPosition;
                bar.clipQuery[part] = Services().SubmitTranslation(
                    *this, start, end, 103552);
            }
        }
        if (collisionWhileClosing) {
            for (int index = 0; index < bars.Num(); ++index) {
                bars[index].startOpenCloseTime = currentTime
                    + static_cast<int>(
                        bars[index].recloseDelay * 1000.0f);
            }
        }
    }

    if (barsAnimatingFlag || !shouldBeOpenFlag) {
        for (int index = 0; index < bars.Num(); ++index) {
            idDoorLaserBar& bar = bars[index];
            for (int part = 0; part < bar.numParts; ++part) {
                const float amount = Clamp01(bar.openPercent[part]);
                if (amount >= 1.0f) {
                    continue;
                }
                const idVec3& fixed = part == 0
                    ? bar.startPosition : bar.endPosition;
                const idVec3& opposite = part == 0
                    ? bar.endPosition : bar.startPosition;
                Services().UpdateBeam(*this, barMaterial, barSize,
                    fixed, Lerp(opposite, fixed, amount), 1.0f);
            }
        }
    }
}

// Retail: 0x82C24230 ?StartAnimatingIfNecessary@idDoor_Laser@@QAAXXZ
void idDoor_Laser::StartAnimatingIfNecessary() {
    if (barsAnimatingFlag) {
        return;
    }
    barsAnimatingFlag = true;
    const int currentTime = Services().GetGameMilliseconds();
    for (int index = 0; index < bars.Num(); ++index) {
        idDoorLaserBar& bar = bars[index];
        const float delay = shouldBeOpenFlag
            ? bar.openDelay : bar.closeDelay;
        bar.startOpenCloseTime = currentTime
            + static_cast<int>(delay * 1000.0f);
    }
}

// Retail: 0x82C243E8 ?Open@idDoor_Laser@@QAAXXZ
void idDoor_Laser::Open() {
    if (shouldBeOpenFlag) {
        return;
    }
    shouldBeOpenFlag = true;
    if (openSound != nullptr) {
        Services().StopWeaponSound(*this);
        Services().PlayWeaponSound(*this, openSound);
    }
    StartAnimatingIfNecessary();
}

// Retail: 0x82C24460 ?Close@idDoor_Laser@@QAAXXZ
void idDoor_Laser::Close() {
    if (!shouldBeOpenFlag) {
        return;
    }
    shouldBeOpenFlag = false;
    if (closeSound != nullptr) {
        Services().StopWeaponSound(*this);
        Services().PlayWeaponSound(*this, closeSound);
    }
    StartAnimatingIfNecessary();
}

// Retail: 0x82C244D8 ?Event_Close@idDoor_Laser@@QAA?AVeventVoid@@PAVidEntity@@@Z
void idDoor_Laser::Event_Close(idEntity*) {
    Close();
}

// Retail: 0x82C24510 ?Event_Disable@idDoor_Laser@@QAA?AVeventVoid@@XZ
void idDoor_Laser::Event_Disable() {
    Open();
}

// Retail: 0x82C24548 ?Event_Activate@idDoor_Laser@@QAA?AVeventVoid@@PAVidEntity@@@Z
void idDoor_Laser::Event_Activate(idEntity*) {
    if (shouldBeOpenFlag) {
        Close();
    } else {
        Open();
    }
}

// Retail: 0x82C24590 ?OnActivate@idDoor_Laser@@UAAXPAVidEntity@@@Z
void idDoor_Laser::OnActivate(idEntity* const activator) {
    Event_Activate(activator);
}

// Retail: 0x82C245B0 ??0idDoor_Laser@@QAA@XZ
idDoor_Laser::idDoor_Laser()
    : doorWidth(100.0f), doorHeight(100.0f), startDoorOpenFlag(false),
      openSound(nullptr), closeSound(nullptr), passThroughSound(nullptr),
      barMaterial(nullptr), barSize(1.0f), sparkParticles(),
      sparkDelayMin(0.25f), sparkDelayMax(0.5f),
      barOpenExtraPercent(0.0f), sparkBackExtraPercent(0.0f), bars(),
      shouldBeOpenFlag(false), barsAnimatingFlag(false),
      touchingCount(0), origin(0.0f, 0.0f, 0.0f), axis(1.0f),
      thinkFlags(0) {
}

// Retail: 0x82C24720 ??1idDoor_Laser@@UAA@XZ
idDoor_Laser::~idDoor_Laser() {
    bars.Clear();
    sparkParticles.Clear();
}

// Retail: 0x82C247D0 ?Hide@idDoor_Laser@@UAAXXZ
void idDoor_Laser::Hide() {
    Open();
}

// Retail: 0x82C247D8 ?Show@idDoor_Laser@@UAAXXZ
void idDoor_Laser::Show() {
    Close();
    Services().ShowEntity(*this);
}
