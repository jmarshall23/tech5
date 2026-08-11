#include "presentablelasergate.h"

#include <algorithm>
#include <cmath>

namespace {

idPresentableLaserGateServices defaultLaserGateServices;
idPresentableLaserGateServices* laserGateServices =
    &defaultLaserGateServices;

const idDeclFX* ResolveFXDeclaration(const idDeclLaserGate* declaration,
        const idDeclFX* overrideDeclaration) {
    return overrideDeclaration != nullptr
        ? overrideDeclaration
        : laserGateServices->GetFXDeclaration(declaration);
}

idVec3 TransformPoint(const idVec3& origin, const idMat3& axis,
        const idVec3& localPoint) {
    return origin + idVec3(
        axis[0].x * localPoint.x + axis[1].x * localPoint.y
            + axis[2].x * localPoint.z,
        axis[0].y * localPoint.x + axis[1].y * localPoint.y
            + axis[2].y * localPoint.z,
        axis[0].z * localPoint.x + axis[1].z * localPoint.y
            + axis[2].z * localPoint.z);
}

void AddPointToBounds(idBounds& bounds, const idVec3& point) {
    for (int component = 0; component < 3; ++component) {
        bounds[0][component] = std::min(bounds[0][component], point[component]);
        bounds[1][component] = std::max(bounds[1][component], point[component]);
    }
}

void StartBeamFX(idPresentableLaserGate* gate, int beamNumber) {
    idLaserGateBeam& beam = gate->laserBeams[beamNumber];
    const idVec3 direction = beam.point2 - beam.point1;
    laserGateServices->StartEndpointFX(gate, beamNumber, 1,
        beam.point2, direction);
    laserGateServices->StartEndpointFX(gate, beamNumber, 0,
        beam.point1, direction * -1.0f);
}

void StopBeamFX(idPresentableLaserGate* gate, int beamNumber) {
    laserGateServices->StopEndpointFX(gate, beamNumber, 1);
    laserGateServices->StopEndpointFX(gate, beamNumber, 0);
}

} // namespace

void Tungsten_SetPresentableLaserGateServices(
        idPresentableLaserGateServices* services) {
    laserGateServices = services != nullptr ? services
        : &defaultLaserGateServices;
}

idPresentableLaserGateServices*
Tungsten_GetPresentableLaserGateServices() {
    return laserGateServices;
}

idLaserGateBeam::idLaserGateBeam()
    : point1(0.0f, 0.0f, 0.0f)
    , point2(0.0f, 0.0f, 0.0f)
    , state(LASERGATE_OPENED) {
}

void idLaserGateBeam::UpdateLaserBeams(laserGateState_t parentState,
        unsigned int beamPowerUpTime, int startTime,
        float maxBeamHeight) {
    bool updateHeight = true;
    if ((parentState <= LASERGATE_OPENED && state == LASERGATE_OPENED)
            || (parentState >= LASERGATE_CLOSING
                && state == LASERGATE_CLOSED)) {
        updateHeight = false;
    } else if (parentState == LASERGATE_OPENING) {
        if (state > LASERGATE_OPENED) {
            if (laserGateServices->GetScaledGameTime() <= startTime) {
                updateHeight = false;
            } else {
                state = parentState;
            }
        }
    } else if (parentState == LASERGATE_CLOSING
            && state < LASERGATE_CLOSING) {
        if (laserGateServices->GetScaledGameTime() <= startTime) {
            updateHeight = false;
        } else {
            state = parentState;
        }
    }

    if (updateHeight) {
        const float duration = beamPowerUpTime > 0
            ? static_cast<float>(beamPowerUpTime) : 1.0f;
        float fraction = static_cast<float>(
            laserGateServices->GetScaledGameTime() - startTime) / duration;
        fraction = std::max(0.0f, std::min(1.0f, fraction));
        if (state == LASERGATE_OPENING) {
            fraction = 1.0f - fraction;
            if (fraction < 0.0001f) {
                state = LASERGATE_OPENED;
                fraction = 0.0f;
            }
        } else if (state == LASERGATE_CLOSING && fraction > 0.999f) {
            state = LASERGATE_CLOSED;
            fraction = 1.0f;
        }
        beam.height = fraction * maxBeamHeight;
    }

    if (state != LASERGATE_OPENED) {
        laserGateServices->RenderBeam(*this);
    }
}

idPresentableLaserGate::idPresentableLaserGate()
    : gateActivationTime(0)
    , shutdownTime(-1)
    , currentGateState(LASERGATE_OPENED)
    , requestedGateState(LASERGATE_OPENED)
    , laserGateDecl(nullptr)
    , collisionLastFrame(false)
    , gatherQuery(0) {
}

idPresentableLaserGate::idPresentableLaserGate(idEntity* entity_,
        idRenderModel* renderModel, int entityNumber_,
        const idDeclLaserGate* laserGateInfo,
        const idList<laserGateBeamInfo_t, 5>& laserEndPoints_,
        const idDeclFX* overrideFXDecl)
    : idPresentable(entity_, renderModel, entityNumber_,
        ResolveFXDeclaration(laserGateInfo, overrideFXDecl))
    , gateActivationTime(0)
    , shutdownTime(-1)
    , currentGateState(LASERGATE_OPENED)
    , requestedGateState(LASERGATE_OPENED)
    , laserGateDecl(laserGateInfo)
    , laserEndPoints(laserEndPoints_)
    , collisionLastFrame(false)
    , gatherQuery(0) {
    laserGateServices->GetEntitySpawnTransform(entity_, origin, axis);
    BuildBeams();
}

idPresentableLaserGate::~idPresentableLaserGate() {
    laserEndPoints.Clear();
    laserBeams.Clear();
}

void idPresentableLaserGate::PowerUp() {
    requestedGateState = LASERGATE_CLOSING;
    gateActivationTime = laserGateServices->GetScaledGameTime();
}

void idPresentableLaserGate::PowerDown() {
    requestedGateState = LASERGATE_OPENING;
    gateActivationTime = laserGateServices->GetScaledGameTime();
    shutdownTime = gateActivationTime;
}

void idPresentableLaserGate::UpdateBeams() {
    const int beamCount = std::min(laserBeams.Num(), laserEndPoints.Num());
    for (int beamNumber = 0; beamNumber < beamCount; ++beamNumber) {
        laserBeams[beamNumber].point1 = TransformPoint(origin, axis,
            laserEndPoints[beamNumber].point1);
        laserBeams[beamNumber].point2 = TransformPoint(origin, axis,
            laserEndPoints[beamNumber].point2);
    }
    UpdateFX(1.0f, 0.0f);
}

void idPresentableLaserGate::EnterDormancy() {
    const int beamCount = std::min(7, laserBeams.Num());
    for (int beamNumber = 0; beamNumber < beamCount; ++beamNumber) {
        StopBeamFX(this, beamNumber);
    }
}

void idPresentableLaserGate::LeaveDormancy() {
    if (requestedGateState != LASERGATE_CLOSED
            && requestedGateState != LASERGATE_CLOSING) {
        return;
    }
    const int beamCount = std::min(7, laserBeams.Num());
    for (int beamNumber = 0; beamNumber < beamCount; ++beamNumber) {
        StartBeamFX(this, beamNumber);
    }
}

void idPresentableLaserGate::BuildBeams() {
    laserBeams.SetNum(laserEndPoints.Num());
    const idMaterial* material = laserGateServices->GetBeamMaterial(
        laserGateDecl);
    const float beamHeight = laserGateServices->GetBeamHeight(laserGateDecl);
    for (int beamNumber = 0; beamNumber < laserBeams.Num(); ++beamNumber) {
        idLaserGateBeam& beam = laserBeams[beamNumber];
        beam.beam.material = material;
        beam.beam.height = beamHeight;
        beam.point1 = TransformPoint(origin, axis,
            laserEndPoints[beamNumber].point1);
        beam.point2 = TransformPoint(origin, axis,
            laserEndPoints[beamNumber].point2);
    }
}

void idPresentableLaserGate::SerializeBeams(idSerializer& serializer,
        bool firstTimeIn) {
    int beamCount = laserEndPoints.Num();
    serializer.Serialize(beamCount);
    if (serializer.IsReading()) {
        laserEndPoints.SetNum(beamCount);
    }
    for (int beamNumber = 0; beamNumber < beamCount; ++beamNumber) {
        serializer.SerializeQ<32768, 17>(laserEndPoints[beamNumber].point1);
        serializer.SerializeQ<32768, 17>(laserEndPoints[beamNumber].point2);
    }
    if (firstTimeIn) {
        BuildBeams();
    }
}

void idPresentableLaserGate::UpdateGateLogic() {
    const int gameTime = laserGateServices->GetScaledGameTime();
    if (requestedGateState != currentGateState) {
        currentGateState = requestedGateState;
        gateActivationTime = gameTime;
    }

    idBounds gateBounds;
    gateBounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    gateBounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
    const int beamSpacing = laserGateServices->GetBeamSpacing(laserGateDecl);
    const int powerUpTime = laserGateServices->GetBeamPowerUpTime(
        laserGateDecl);
    const float beamHeight = laserGateServices->GetBeamHeight(laserGateDecl);
    const bool suppressFX = laserGateServices->SuppressEndpointFX(entity);

    for (int beamNumber = 0; beamNumber < laserBeams.Num(); ++beamNumber) {
        idLaserGateBeam& beam = laserBeams[beamNumber];
        const laserGateState_t oldState = beam.state;
        beam.UpdateLaserBeams(currentGateState,
            static_cast<unsigned int>(std::max(0, powerUpTime)),
            gateActivationTime + beamSpacing * beamNumber, beamHeight);
        if (!suppressFX && beamNumber < 7) {
            if (oldState == LASERGATE_OPENED
                    && beam.state != LASERGATE_OPENED) {
                StartBeamFX(this, beamNumber);
            } else if (oldState != LASERGATE_OPENED
                    && beam.state == LASERGATE_OPENED) {
                StopBeamFX(this, beamNumber);
            }
        }
        AddPointToBounds(gateBounds, beam.point1);
        AddPointToBounds(gateBounds, beam.point2);
    }

    if (currentGateState == LASERGATE_CLOSED
            || currentGateState == LASERGATE_CLOSING) {
        const bool collision = laserGateServices->PollGather(gatherQuery);
        gatherQuery = laserGateServices->SubmitGather(gateBounds, 1024,
            entityNumber);
        const idSoundShader* passThroughSound =
            laserGateServices->GetPassThroughSound(laserGateDecl);
        if (passThroughSound != nullptr && !collisionLastFrame && collision) {
            StartSoundShader(SND_CHANNEL_WEAPON, passThroughSound, 0, 0);
        }
        collisionLastFrame = collision;
    } else {
        collisionLastFrame = false;
    }

    if (shutdownTime != -1 && currentGateState <= LASERGATE_OPENED
            && gameTime > 7 * beamSpacing + shutdownTime + 500) {
        shutdownTime = -1;
        const int beamCount = std::min(7, laserBeams.Num());
        for (int beamNumber = 0; beamNumber < beamCount; ++beamNumber) {
            StopBeamFX(this, beamNumber);
        }
    }
}

void idPresentableLaserGate::Serialize(idSerializer& serializer) {
    idPresentable::Serialize(serializer);
    const bool firstTimeIn = laserGateDecl == nullptr;
    const void* declaration = laserGateDecl;
    laserGateServices->SerializeDeclaration(serializer, declaration);
    if (serializer.IsReading()) {
        laserGateDecl = static_cast<const idDeclLaserGate*>(declaration);
    }
    int requestedState = static_cast<int>(requestedGateState);
    serializer.SerializeUMax(requestedState, LASERGATE_CLOSED);
    requestedGateState = static_cast<laserGateState_t>(requestedState);
    SerializeBeams(serializer, firstTimeIn);
}

void idPresentableLaserGate::ClientThink(int currentTime, float fraction,
        bool predict) {
    idPresentable::ClientThink(currentTime, fraction, predict);
    UpdateGateLogic();
}
