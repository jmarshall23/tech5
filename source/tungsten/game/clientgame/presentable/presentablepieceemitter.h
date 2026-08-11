#pragma once

#include "presentable.h"

class idDeclImpactSound;
class idPieceEmitter;

struct idRecoveredEffectPhysicsPieceEmitter {
    int numPiecesInUse{0};
    bool initialized{false};
};

class idPresentablePieceEmitter;

class idPresentablePieceEmitterServices {
public:
    virtual ~idPresentablePieceEmitterServices() = default;

    virtual int GetScaledGameTime() const { return 0; }
    virtual int GetScaledFrameTime() const { return 0; }
    virtual int GetShowPieceCollision() const { return 0; }
    virtual bool GetLocalPlayerOrigin(idVec3&) const { return false; }
    virtual void RemoveSimulatingPhysics(
        idRecoveredEffectPhysicsPieceEmitter&) {}
    virtual void AddSimulatingPhysics(
        idRecoveredEffectPhysicsPieceEmitter&) {}
    virtual void UpdateSimulation(idRecoveredEffectPhysicsPieceEmitter&,
        const idVec3&, const idMat3&, int, int) {}
    virtual void UpdateModel(idRecoveredEffectPhysicsPieceEmitter&,
        const idVec3&) {}
    virtual void ResetPhysics(idRecoveredEffectPhysicsPieceEmitter& physics) {
        physics.numPiecesInUse = 0;
    }
    virtual void DrawCollisionModels(
        const idRecoveredEffectPhysicsPieceEmitter&, int,
        const idVec3&, const idMat3&) {}
    virtual void InitializePhysics(idRecoveredEffectPhysicsPieceEmitter& physics,
        idRenderModel*, const idDeclImpactSound*, float, int, float, float,
        float) {
        physics.initialized = true;
    }
    virtual void ConfigureEmitterModel(idRenderModel*, float, float) {}
    virtual void EmitPiece(idRecoveredEffectPhysicsPieceEmitter&, int,
        const idVec3&, const idMat3&, const idVec3&, const idVec3&) {}
    virtual void SerializeDeclaration(idSerializer&, const void*&) {}
};

void Tungsten_SetPresentablePieceEmitterServices(
    idPresentablePieceEmitterServices* services);

class idPresentablePieceEmitter : public idPresentable {
public:
    struct emitPieceItem_t {
        idVec3 pos;
        idMat3 axis;
        idVec3 impulsePoint;
        idVec3 impulse;
    };

    idPresentablePieceEmitter();
    idPresentablePieceEmitter(idPieceEmitter* entity,
        idRenderModel* renderModel);
    ~idPresentablePieceEmitter() override;

    void SetInitProperties(const idDeclImpactSound* impactTable,
        float pieceMinBounceVelocity, int pieceLifeSpan, float pieceFriction,
        float emitFovScale, float emitModelDepthHack,
        float pieceCollisionAgeDecay, float pieceCollisionVolumeDecay);
    void Present() override;
    void Interpolate(int currentTime, float fraction) override;
    void GetWorldTransform(idVec3& outOrigin, idMat3& outAxis) override;
    void Serialize(idSerializer& serializer) override;
    presentableType_t GetType() const override {
        return PRESENTABLE_PIECE_EMITTER;
    }
    idPresentablePieceEmitter* GetPieceEmitterInterface() override {
        return this;
    }

    void EmitPiece(int emitTime, const idVec3& position,
        const idMat3& pieceAxis, const idVec3& impulsePoint,
        const idVec3& impulse);

    idRecoveredEffectPhysicsPieceEmitter piecePhysics;
    const idDeclImpactSound* impactTable;
    float pieceMinBounceVelocity;
    int pieceLifeSpan;
    float pieceFriction;
    float emitFovScale;
    float emitModelDepthHack;
    float pieceCollisionAgeDecay;
    float pieceCollisionVolumeDecay;
    emitPieceItem_t emitPieceBuffer[10];
    int emitPieceBufferPos;
};
