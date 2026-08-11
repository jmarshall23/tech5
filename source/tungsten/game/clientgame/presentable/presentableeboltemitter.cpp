#include "presentableeboltemitter.h"

namespace {

idPresentableEBoltEmitterServices defaultEBoltEmitterServices;
idPresentableEBoltEmitterServices* eboltEmitterServices =
    &defaultEBoltEmitterServices;

} // namespace

void Tungsten_SetPresentableEBoltEmitterServices(
        idPresentableEBoltEmitterServices* services) {
    eboltEmitterServices = services != nullptr ? services
                                               : &defaultEBoltEmitterServices;
}

idPresentableEBoltEmitter::idPresentableEBoltEmitter()
    : minResetTime(0)
    , maxResetTime(0)
    , electricBoltSystem(nullptr)
    , sndPowerDown(nullptr)
    , sndPowerUp(nullptr)
    , maxConeAngle(0.0f)
    , length(0.0f, 0.0f)
    , ebolt(nullptr)
    , nextResetTime(0)
    , startOff(false)
    , firstSerialize(true) {
}

idPresentableEBoltEmitter::idPresentableEBoltEmitter(idEntity* newEntity,
        idRenderModel* renderModel, int minimumResetTime,
        int maximumResetTime, bool startsOff,
        const idDeclElectricBolt* boltSystem,
        const idSoundShader* powerDownSound,
        const idSoundShader* powerUpSound, float maximumConeAngle,
        const idVec2& boltLength,
        const idList<std::uint32_t, 5>& targetSpawnIds)
    : idPresentable(newEntity, renderModel, ENTITYNUM_NONE, nullptr)
    , minResetTime(minimumResetTime)
    , maxResetTime(maximumResetTime)
    , electricBoltSystem(boltSystem)
    , sndPowerDown(powerDownSound)
    , sndPowerUp(powerUpSound)
    , maxConeAngle(maximumConeAngle)
    , length(boltLength)
    , ebolt(nullptr)
    , targets(targetSpawnIds)
    , nextResetTime(0)
    , startOff(startsOff)
    , firstSerialize(true) {
}

idPresentableEBoltEmitter::~idPresentableEBoltEmitter() {
    if (ebolt != nullptr) {
        eboltEmitterServices->DeleteElectricBolt(ebolt);
        ebolt = nullptr;
    }
    targets.Clear();
    targetPoints.Clear();
}

void idPresentableEBoltEmitter::ResetTarget() {
    if (targetPoints.IsEmpty() || ebolt == nullptr) {
        return;
    }
    const int targetIndex = eboltEmitterServices->RandomIndex(
        targetPoints.Num());
    if (targetIndex < 0 || targetIndex >= targetPoints.Num()) {
        return;
    }
    const int gameTime = eboltEmitterServices->GetScaledGameTime();
    eboltEmitterServices->StartElectricBolt(ebolt, gameTime, origin,
        targetPoints[targetIndex], eboltEmitterServices->RandomUnitFloat());
    nextResetTime = gameTime + eboltEmitterServices->RandomRange(
        minResetTime, maxResetTime);
}

void idPresentableEBoltEmitter::ClientThink(int currentTime,
        float fraction, bool predict) {
    idPresentable::ClientThink(currentTime, fraction, predict);
    const int gameTime = eboltEmitterServices->GetScaledGameTime();
    if (ebolt != nullptr) {
        eboltEmitterServices->UpdateElectricBolt(ebolt, gameTime);
    }
    if (nextResetTime > 0 && gameTime > nextResetTime) {
        ResetTarget();
    }
}

void idPresentableEBoltEmitter::Serialize(idSerializer& serializer) {
    const bool wasHidden = hidden;
    idPresentable::Serialize(serializer);
    const bool poweredUp = wasHidden && !hidden;
    const bool poweredDown = !wasHidden && hidden;

    serializer.Serialize(minResetTime);
    serializer.Serialize(maxResetTime);
    serializer.Serialize(startOff);
    const void* boltDeclaration = electricBoltSystem;
    eboltEmitterServices->SerializeDeclaration(serializer, boltDeclaration);
    const void* downSound = sndPowerDown;
    eboltEmitterServices->SerializeDeclaration(serializer, downSound);
    const void* upSound = sndPowerUp;
    eboltEmitterServices->SerializeDeclaration(serializer, upSound);
    if (serializer.IsReading()) {
        electricBoltSystem = static_cast<const idDeclElectricBolt*>(
            boltDeclaration);
        sndPowerDown = static_cast<const idSoundShader*>(downSound);
        sndPowerUp = static_cast<const idSoundShader*>(upSound);
    }
    serializer.Serialize(maxConeAngle);
    serializer.Serialize(length);

    if (firstSerialize && eboltEmitterServices->IsServer()) {
        targetPoints.Clear();
        for (int targetNumber = 0; targetNumber < targets.Num();
                ++targetNumber) {
            idVec3 position;
            if (eboltEmitterServices->ResolveTargetPosition(
                    targets[targetNumber], position)) {
                targetPoints.Append(position);
            }
        }
    }

    int targetCount = targetPoints.Num();
    serializer.Serialize(targetCount);
    if (serializer.IsReading()) {
        targetPoints.SetNum(targetCount);
    }
    for (int targetNumber = 0; targetNumber < targetCount; ++targetNumber) {
        serializer.Serialize(targetPoints[targetNumber]);
    }

    bool startNow = poweredUp;
    if (firstSerialize && eboltEmitterServices->IsClient()
            && electricBoltSystem != nullptr) {
        ebolt = eboltEmitterServices->CreateElectricBolt(electricBoltSystem);
        if (!startOff) {
            startNow = true;
        }
    }
    firstSerialize = false;

    if (startNow) {
        ResetTarget();
        if (sndPowerUp != nullptr) {
            StartSoundShader(SND_CHANNEL_AMBIENT, sndPowerUp, 0, 0);
        }
    } else if (poweredDown && sndPowerDown != nullptr) {
        StartSoundShader(SND_CHANNEL_ANY, sndPowerDown, 0, 0);
    }
}
