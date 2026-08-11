#pragma once

#include "game/decls/declactormodifier.h"
#include "game/gamesys/eventarg.h"
#include "idlib/containers/staticlist.h"

#include <cstdint>

class idActor;
class idActorModifier;
class idActorModifierManager;
class idDeclDamage;
class idEntity;
class idInventoryCollection;
class idPresentableActor;
class idSerializer;
class idUCmdTracker;

struct netBoolEvent_t {
    int count = 0;
    int lastCount = 0;

    bool Consume() {
        if (count == lastCount) return false;
        lastCount = count;
        return true;
    }
    void Signal() { count = (count + 1) % 7; }
};

struct idActorModifierTimer {
    int expire_time = 0;
    int index = 0;
};

class idActorModifierItem {
public:
    const idDeclActorModifier* decl = nullptr;
};

class idActorModifierServices {
public:
    virtual ~idActorModifierServices() = default;
    virtual std::uint32_t GetPresentableSpawnId(
        const idPresentableActor*) const { return 0; }
    virtual idPresentableActor* ResolvePresentable(std::uint32_t) const {
        return nullptr;
    }
    virtual bool IsLocallyControlled(const idPresentableActor*) const {
        return false;
    }
    virtual bool IsPresentableDead(const idPresentableActor*) const {
        return false;
    }
    virtual int GetGameMilliseconds() const { return 0; }
    virtual int GetGameFrame() const { return 0; }
    virtual int GetGameMillisecondsPerFrame() const { return 16; }
    virtual bool IsServer() const { return true; }
    virtual bool IsClient() const { return false; }
    virtual bool WasButtonPressed(const idUCmdTracker*, int) const {
        return false;
    }
    virtual float GetOverdrivePoints(const idPresentableActor*) const {
        return 0.0f;
    }
    virtual float GetOverdrivePointsRequired() const { return 200.0f; }
    virtual void SetOverdrivePoints(idPresentableActor*, float) {}
    virtual idPresentableActor* ActorPresentable(idActor*) const {
        return nullptr;
    }
    virtual idActorModifierManager* ModifierManager(
        idPresentableActor*) const { return nullptr; }
    virtual void StartFX(idActorModifier&, int, bool) {}
    virtual void StopFX(idActorModifier&, int, bool) {}
    virtual void UpdateFX(idActorModifier&, int, int, int) {}
    virtual void InitFX(idActorModifier&, const idDeclFX*) {}
    virtual void ShutdownFX(idActorModifier&) {}
    virtual void SerializeModifier(idSerializer&, idActorModifier&) {}
    virtual void SerializeModifierValue(
        idSerializer&, int, float&, int&) {}
    virtual void BroadcastModifierEvent(
        idActorModifier&, bool, bool) {}
    virtual void SendActivationMessage(
        const idActorModifier&) {}
    virtual void DropPointOfInterest(
        idPresentableActor*, const idDeclActorModifier::ActorModifierOutput_t&) {}
};

class idActorModifier {
public:
    idActorModifier();
    virtual ~idActorModifier();

    static void SetServices(idActorModifierServices* services);
    static idActorModifierServices& Services();

    void SetValid(bool valid);
    void OnDamageTaken(idEntity* attacker, idActor* victim,
        idEntity* inflictor, const idDeclDamage* damageDecl,
        float damage, bool isDead);
    void SetParent(idPresentableActor* parent);
    void OnDamageDealt(idActor* attacker, idActor* victim,
        idEntity* inflictor, const idDeclDamage* damageDecl,
        float damage, bool isDead);
    void Serialize(idSerializer& serializer);
    void Deactivate(bool activatedByServer);
    void TriggerFX(int condition);
    void TriggerLocalFX(int condition);
    bool CheckDeps();
    void Activate(bool activatedByServer);
    void PostSerializeRead(bool firstClientFrame);
    void Update(int gameTime);
    bool HandleButtonPress(idUCmdTracker* tracker);
    void SetDefaults();

    idStaticList<idActorModifierTimer, 4> timers;
    std::uint32_t parentSpawnId;
    std::uint32_t instigatorSpawnId;
    const idDeclActorModifier* decl;
    const idActorModifierItem* item;
    netBoolEvent_t added;
    netBoolEvent_t activated;
    netBoolEvent_t deactivated;
    unsigned int uid;
    int creationTime;
    int activationTime;
    unsigned char index;
    bool valid;
    bool active;
    int nextTimerTick;
    idActorModifierManager* manager;
};
