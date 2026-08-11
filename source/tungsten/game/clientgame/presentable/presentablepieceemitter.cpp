#include "presentablepieceemitter.h"

namespace {

idPresentablePieceEmitterServices defaultPieceEmitterServices;
idPresentablePieceEmitterServices* pieceEmitterServices =
    &defaultPieceEmitterServices;

void InitializeBuffer(idPresentablePieceEmitter::emitPieceItem_t* buffer) {
    for (int index = 0; index < 10; ++index) {
        buffer[index].pos.Set(0.0f, 0.0f, 0.0f);
        buffer[index].axis = idMat3(1.0f);
        buffer[index].impulsePoint.Set(0.0f, 0.0f, 0.0f);
        buffer[index].impulse.Set(0.0f, 0.0f, 0.0f);
    }
}

} // namespace

void Tungsten_SetPresentablePieceEmitterServices(
        idPresentablePieceEmitterServices* services) {
    pieceEmitterServices = services != nullptr ? services
        : &defaultPieceEmitterServices;
}

idPresentablePieceEmitter::idPresentablePieceEmitter()
    : impactTable(nullptr)
    , pieceMinBounceVelocity(1.0f)
    , pieceLifeSpan(0)
    , pieceFriction(15.0f)
    , emitFovScale(1.0f)
    , emitModelDepthHack(0.0f)
    , pieceCollisionAgeDecay(0.0f)
    , pieceCollisionVolumeDecay(0.0f)
    , emitPieceBufferPos(0) {
    InitializeBuffer(emitPieceBuffer);
}

idPresentablePieceEmitter::idPresentablePieceEmitter(idPieceEmitter* entity_,
        idRenderModel* renderModel)
    : idPresentable(reinterpret_cast<idEntity*>(entity_), renderModel,
        ENTITYNUM_NONE, nullptr)
    , impactTable(nullptr)
    , pieceMinBounceVelocity(1.0f)
    , pieceLifeSpan(0)
    , pieceFriction(15.0f)
    , emitFovScale(1.0f)
    , emitModelDepthHack(0.0f)
    , pieceCollisionAgeDecay(0.0f)
    , pieceCollisionVolumeDecay(0.0f)
    , emitPieceBufferPos(0) {
    InitializeBuffer(emitPieceBuffer);
}

idPresentablePieceEmitter::~idPresentablePieceEmitter() {
    pieceEmitterServices->RemoveSimulatingPhysics(piecePhysics);
}

void idPresentablePieceEmitter::SetInitProperties(
        const idDeclImpactSound* impactTable_,
        float pieceMinBounceVelocity_, int pieceLifeSpan_,
        float pieceFriction_, float emitFovScale_,
        float emitModelDepthHack_, float pieceCollisionAgeDecay_,
        float pieceCollisionVolumeDecay_) {
    pieceMinBounceVelocity = pieceMinBounceVelocity_;
    impactTable = impactTable_;
    pieceFriction = pieceFriction_;
    pieceLifeSpan = pieceLifeSpan_;
    pieceCollisionAgeDecay = pieceCollisionAgeDecay_;
    pieceCollisionVolumeDecay = pieceCollisionVolumeDecay_;
    emitFovScale = emitFovScale_;
    emitModelDepthHack = emitModelDepthHack_;
}

void idPresentablePieceEmitter::Present() {
    idPresentable::Present();
    const int collisionSetting =
        pieceEmitterServices->GetShowPieceCollision();
    if (collisionSetting == 0) {
        return;
    }
    idVec3 playerOrigin;
    if (!pieceEmitterServices->GetLocalPlayerOrigin(playerOrigin)
            || (playerOrigin - origin).LengthSqr() >= 1000000.0f) {
        return;
    }
    const int single = collisionSetting >= 0
        ? -1 : -1 - collisionSetting;
    pieceEmitterServices->DrawCollisionModels(piecePhysics, single,
        origin, axis);
}

void idPresentablePieceEmitter::Interpolate(int currentTime,
        float fraction) {
    idPresentable::Interpolate(currentTime, fraction);
    pieceEmitterServices->UpdateSimulation(piecePhysics, origin, axis,
        pieceEmitterServices->GetScaledGameTime(),
        pieceEmitterServices->GetScaledFrameTime());
    pieceEmitterServices->UpdateModel(piecePhysics,
        idVec3(1.0f, 1.0f, 1.0f));
    pieceEmitterServices->AddSimulatingPhysics(piecePhysics);
    if (piecePhysics.numPiecesInUse == 0) {
        pieceEmitterServices->ResetPhysics(piecePhysics);
    }
}

void idPresentablePieceEmitter::GetWorldTransform(idVec3& outOrigin,
        idMat3& outAxis) {
    outOrigin.Set(0.0f, 0.0f, 0.0f);
    outAxis = idMat3(1.0f);
}

void idPresentablePieceEmitter::EmitPiece(int, const idVec3& position,
        const idMat3& pieceAxis, const idVec3& impulsePoint_,
        const idVec3& impulse_) {
    emitPieceItem_t& item = emitPieceBuffer[emitPieceBufferPos];
    item.pos = position;
    item.axis = pieceAxis;
    item.impulsePoint = impulsePoint_;
    item.impulse = impulse_;
    emitPieceBufferPos = (emitPieceBufferPos + 1) % 10;
}

void idPresentablePieceEmitter::Serialize(idSerializer& serializer) {
    idRenderModel* oldModel = model;
    idPresentable::Serialize(serializer);
    const void* impactDeclaration = impactTable;
    pieceEmitterServices->SerializeDeclaration(serializer,
        impactDeclaration);
    if (serializer.IsReading()) {
        impactTable = static_cast<const idDeclImpactSound*>(impactDeclaration);
    }
    serializer.Serialize(pieceMinBounceVelocity);
    serializer.Serialize(pieceCollisionAgeDecay);
    serializer.Serialize(pieceCollisionVolumeDecay);
    serializer.Serialize(pieceLifeSpan);
    serializer.Serialize(pieceFriction);
    serializer.Serialize(emitFovScale);
    serializer.Serialize(emitModelDepthHack);

    if (serializer.IsReading()
            && (oldModel != model || serializeCount == 1)) {
        pieceEmitterServices->InitializePhysics(piecePhysics, model,
            impactTable, pieceMinBounceVelocity * pieceMinBounceVelocity,
            pieceLifeSpan, pieceFriction, pieceCollisionAgeDecay,
            pieceCollisionVolumeDecay);
        pieceEmitterServices->UpdateModel(piecePhysics,
            idVec3(1.0f, 1.0f, 1.0f));
        pieceEmitterServices->ConfigureEmitterModel(model, emitFovScale,
            emitModelDepthHack);
        Hide(true);
        pieceEmitterServices->ResetPhysics(piecePhysics);
    }

    int serializedBufferPos = emitPieceBufferPos;
    serializer.SerializeUMax(serializedBufferPos, 9);
    for (int bufferIndex = 0; bufferIndex < 10; ++bufferIndex) {
        serializer.SerializeQ<32768, 12>(emitPieceBuffer[bufferIndex].pos);
        serializer.SerializeQ(emitPieceBuffer[bufferIndex].axis, 15);
        serializer.SerializeQ<32768, 12>(
            emitPieceBuffer[bufferIndex].impulsePoint);
        serializer.SerializeQ<4096, 8>(emitPieceBuffer[bufferIndex].impulse);
    }

    if (emitPieceBufferPos != serializedBufferPos) {
        do {
            const emitPieceItem_t& item =
                emitPieceBuffer[emitPieceBufferPos];
            pieceEmitterServices->EmitPiece(piecePhysics,
                pieceEmitterServices->GetScaledGameTime(), item.pos,
                item.axis, item.impulsePoint, item.impulse);
            emitPieceBufferPos = (emitPieceBufferPos + 1) % 10;
        } while (emitPieceBufferPos != serializedBufferPos);
    }
    emitPieceBufferPos = serializedBufferPos;
}
