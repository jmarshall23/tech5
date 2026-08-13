#pragma once

#include "game/entities/animatedsimple.h"
#include "game/entities/entityptr.h"

class idModifiedPlayerMovement;
class idPlayer;

class idModifiedPlayerMovementServices {
public:
    virtual ~idModifiedPlayerMovementServices() = default;
    virtual void BaseThink(idModifiedPlayerMovement& modifier);
    virtual void BaseHide(idModifiedPlayerMovement& modifier,
        bool stopEffects);
    virtual idPlayer* ResolvePlayer(int spawnId) const;
    virtual int GetPrimaryPlayerSpawnId() const;
    virtual void GetModifierAxis(const idModifiedPlayerMovement& modifier,
        idMat3& axis) const;
    virtual void PreparePlayerMovement(idPlayer& player);
    virtual void ApplyPlayerMovement(idPlayer& player,
        const idVec3& acceleration, float maximumSpeedDifference,
        float baseAngle);
    virtual void ResetPlayerMovement(idPlayer& player);
    virtual void QueueRemove(idModifiedPlayerMovement& modifier);
};

void Tungsten_SetModifiedPlayerMovementServices(
    idModifiedPlayerMovementServices* services);
idModifiedPlayerMovementServices&
    Tungsten_ModifiedPlayerMovementServices();

class idModifiedPlayerMovement : public idAnimatedSimple {
public:
    idModifiedPlayerMovement();

    void Think() override;
    void Hide() override;
    void Hide(bool stopEffects) override;
    virtual void OnActivate(idEntity* activator);
    void Event_Remove();

    float strengthModifier;
    float maxSpeedDiff;
    float baseAngle;
    bool useFixedDirection;
    idEntityPtr<idPlayer> playerEntity;

private:
    idPlayer* ResolvePlayer() const;
    void ResetPlayer();
};
