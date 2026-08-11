#include "game/entities/actormodifier.h"

#include "game/entities/actormodifiermanager.h"
#include "idlib/lib_print.h"

#include <algorithm>

namespace {
idActorModifierServices defaultModifierServices;
idActorModifierServices* activeModifierServices = &defaultModifierServices;

void GiveDamageScaledOverdrive(idActor* actor,
        const idDeclActorModifier::ActorModifierOutput_t& output,
        const float damage) {
    idActorModifierServices& services = idActorModifier::Services();
    idPresentableActor* presentable = services.ActorPresentable(actor);
    if (presentable == nullptr) return;
    const float required = services.GetOverdrivePointsRequired();
    const float points = services.GetOverdrivePoints(presentable)
        + output.value * damage;
    services.SetOverdrivePoints(presentable, std::min(points, required));
}
}

void idActorModifier::SetServices(idActorModifierServices* services) {
    activeModifierServices = services == nullptr
        ? &defaultModifierServices : services;
}

idActorModifierServices& idActorModifier::Services() {
    return *activeModifierServices;
}

// EA 0x82BEAA80
void idActorModifier::SetValid(const bool value) {
    valid = value;
}

// EA 0x82BEAA88
void idActorModifier::OnDamageTaken(idEntity*, idActor* victim,
        idEntity*, const idDeclDamage*, const float damage, const bool) {
    if (!valid || decl == nullptr) return;
    for (int triggerIndex = 0; triggerIndex < decl->triggers.Num();
            ++triggerIndex) {
        if (decl->triggers[triggerIndex].type
                != idDeclActorModifier::TRIGGER_TYPE_DAMAGE_TAKEN) {
            continue;
        }
        for (int outputIndex = 0; outputIndex < decl->outputs.Num();
                ++outputIndex) {
            const auto& output = decl->outputs[outputIndex];
            if (output.action
                    == idDeclActorModifier::ACTION_GIVE_OVERDRIVE_POINTS) {
                GiveDamageScaledOverdrive(victim, output, damage);
            }
        }
    }
}

// EA 0x82BEAC40
void idActorModifier::SetParent(idPresentableActor* value) {
    parentSpawnId = value == nullptr
        ? 0 : Services().GetPresentableSpawnId(value);
}

// EA 0x82BEAC58
void idActorModifier::OnDamageDealt(idActor* attacker, idActor* victim,
        idEntity*, const idDeclDamage*, const float damage, const bool) {
    if (!valid || decl == nullptr) return;
    for (int triggerIndex = 0; triggerIndex < decl->triggers.Num();
            ++triggerIndex) {
        if (decl->triggers[triggerIndex].type
                != idDeclActorModifier::TRIGGER_TYPE_DAMAGE_DEALT) {
            continue;
        }
        for (int outputIndex = 0; outputIndex < decl->outputs.Num();
                ++outputIndex) {
            const auto& output = decl->outputs[outputIndex];
            if (output.action == idDeclActorModifier::ACTION_APPLY_MODIFIER
                    && output.decl != nullptr
                    && output.target == idDeclActorModifier::TARGET_VICTIM) {
                idPresentableActor* victimPresentable =
                    Services().ActorPresentable(victim);
                idActorModifierManager* victimManager =
                    Services().ModifierManager(victimPresentable);
                if (victimManager != nullptr) {
                    victimManager->AddModifierUnique(output.decl, nullptr,
                        Services().ResolvePresentable(parentSpawnId));
                }
            } else if (output.action
                    == idDeclActorModifier::ACTION_GIVE_OVERDRIVE_POINTS) {
                GiveDamageScaledOverdrive(attacker, output, damage);
            }
        }
    }
}

// EA 0x82BEAFF8
idActorModifier::~idActorModifier() {
    Services().ShutdownFX(*this);
    timers.Clear();
}

// EA 0x82BEB0C8
void idActorModifier::Serialize(idSerializer& serializer) {
    Services().SerializeModifier(serializer, *this);
}

// EA 0x82BEB200
void idActorModifier::Deactivate(const bool activatedByServer) {
    if (!active) return;
    active = false;
    idPresentableActor* parent = Services().ResolvePresentable(parentSpawnId);
    if (Services().IsLocallyControlled(parent)) {
        Services().StopFX(*this, 196, true);
    }
    if (Services().IsServer()) {
        deactivated.Signal();
        Services().BroadcastModifierEvent(*this, false, false);
        if (manager != nullptr) {
            manager->Notice_ModifierEvent(this, false, false);
        }
    } else if (!activatedByServer) {
        Services().BroadcastModifierEvent(*this, false, true);
        if (manager != nullptr) {
            manager->Notice_ModifierEvent(this, false, true);
        }
    }
}

// EA 0x82BEB388
void idActorModifier::TriggerFX(const int condition) {
    if (Services().ResolvePresentable(parentSpawnId) == nullptr) return;
    Services().StopFX(*this, condition, false);
    Services().StartFX(*this, condition, false);
}

// EA 0x82BEB440
void idActorModifier::TriggerLocalFX(const int condition) {
    idPresentableActor* parent = Services().ResolvePresentable(parentSpawnId);
    if (parent == nullptr || !Services().IsLocallyControlled(parent)) return;
    Services().StopFX(*this, condition, true);
    Services().StartFX(*this, condition, true);
}

// EA 0x82BEB518
bool idActorModifier::CheckDeps() {
    if (!valid || decl == nullptr) return true;
    idPresentableActor* parent = Services().ResolvePresentable(parentSpawnId);
    if (!Services().IsLocallyControlled(parent) || decl->deps.IsEmpty()) {
        return true;
    }
    for (int index = 0; index < decl->deps.Num(); ++index) {
        if (decl->deps[index].type
                == idDeclActorModifier::OVERDRIVE_FULL_DEPTYPE
                && Services().GetOverdrivePoints(parent)
                    < Services().GetOverdrivePointsRequired()) {
            return false;
        }
    }
    return true;
}

// EA 0x82BEB5E8
idActorModifier::idActorModifier()
    : timers(),
      parentSpawnId(0),
      instigatorSpawnId(0),
      decl(nullptr),
      item(nullptr),
      added(),
      activated(),
      deactivated(),
      uid(0),
      creationTime(0),
      activationTime(0),
      index(0),
      valid(false),
      active(false),
      nextTimerTick(0),
      manager(nullptr) {
    for (int timerIndex = 0; timerIndex < timers.Max(); ++timerIndex) {
        timers.staticList[timerIndex] = {};
    }
}

// EA 0x82BEB790
void idActorModifier::Activate(const bool activatedByServer) {
    if (active || !CheckDeps()) return;
    active = true;
    activationTime = Services().GetGameMilliseconds();
    idPresentableActor* parent = Services().ResolvePresentable(parentSpawnId);
    if (activatedByServer) {
        if (Services().IsServer()) activated.Signal();
        Services().BroadcastModifierEvent(*this, true, false);
        if (manager != nullptr) {
            manager->Notice_ModifierEvent(this, true, false);
        }
        if (Services().IsLocallyControlled(parent)) TriggerLocalFX(195);
        else TriggerFX(193);
    } else if (Services().IsClient()) {
        Services().SendActivationMessage(*this);
        Services().BroadcastModifierEvent(*this, true, true);
        if (manager != nullptr) {
            manager->Notice_ModifierEvent(this, true, true);
        }
        TriggerLocalFX(195);
    }
}

// EA 0x82BEBA50
void idActorModifier::PostSerializeRead(const bool) {
    const bool wasActivated = activated.Consume();
    const bool wasDeactivated = deactivated.Consume();
    if (!valid) return;
    if (active && wasDeactivated) Deactivate(true);
    else if (wasActivated) Activate(true);
}

// EA 0x82BEBAE0
void idActorModifier::Update(const int gameTime) {
    if (!valid) return;
    Services().UpdateFX(*this, gameTime, Services().GetGameFrame(),
        Services().GetGameMillisecondsPerFrame());
    if (decl == nullptr) return;

    for (int timerIndex = 0; timerIndex < timers.Num(); ++timerIndex) {
        idActorModifierTimer& timer = timers[timerIndex];
        if (gameTime < timer.expire_time) continue;
        Activate(true);
        if (timer.index >= 0 && timer.index < decl->triggers.Num()) {
            timer.expire_time = gameTime
                + decl->triggers[timer.index].timerDelay;
        }
    }
    if (active && gameTime >= activationTime + decl->lifetime) {
        Deactivate(Services().IsServer());
    }
    if (decl->removeAfter > 0
            && gameTime >= creationTime + decl->removeAfter) {
        valid = false;
    }
    idPresentableActor* parent = Services().ResolvePresentable(parentSpawnId);
    if (parent != nullptr && decl->removeOnDeath
            && Services().IsPresentableDead(parent)) {
        valid = false;
    }
}

// EA 0x82BEBDC8
bool idActorModifier::HandleButtonPress(idUCmdTracker* tracker) {
    if (!valid || decl == nullptr) return false;
    for (int index = 0; index < decl->triggers.Num(); ++index) {
        const auto& trigger = decl->triggers[index];
        if (trigger.type == idDeclActorModifier::TRIGGER_TYPE_BUTTON
                && Services().WasButtonPressed(tracker, trigger.button)) {
            Activate(Services().IsServer());
            return true;
        }
    }
    return false;
}

// EA 0x82BEBF00
void idActorModifier::SetDefaults() {
    if (decl == nullptr) return;
    Services().ShutdownFX(*this);
    if (Services().ResolvePresentable(parentSpawnId) != nullptr) {
        Services().InitFX(*this, decl->fxDecl);
    }
    creationTime = Services().GetGameMilliseconds();
    if (!Services().IsServer()) return;

    timers.Clear();
    for (int index = 0; index < decl->triggers.Num(); ++index) {
        if (decl->triggers[index].type
                != idDeclActorModifier::TRIGGER_TYPE_TIMER) {
            continue;
        }
        if (timers.Num() == timers.Max()) {
            idLibPrint::Warning("idActorModifier %s is over the limit of 4 timers",
                decl->internalName.c_str());
            continue;
        }
        idActorModifierTimer timer;
        timer.index = index;
        timer.expire_time = creationTime + decl->triggers[index].timerDelay;
        timers.Append(timer);
    }
}
