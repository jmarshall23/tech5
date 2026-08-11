#include "game/entities/actormodifiermanager.h"

// EA 0x82BEC198
void idActorModifierManager::PostSerializeRead(const bool firstClientFrame) {
    for (int index = 0; index < modifiers.Num(); ++index) {
        idActorModifier& modifier = modifiers[index];
        modifier.PostSerializeRead(firstClientFrame);
        if (modifier.added.Consume()) {
            modifier.manager = this;
            modifier.SetDefaults();
        }
    }
}

// EA 0x82BEC218
void idActorModifierManager::InventoryItemRemoved(
        idActorModifierItem* item, idEntity*) {
    if (item == nullptr) return;
    for (int index = 0; index < modifiers.Num(); ++index) {
        if (modifiers[index].item == item) {
            modifiers[index].SetValid(false);
            modifiers[index].manager = nullptr;
            return;
        }
    }
}

// EA 0x82BEC2E8
idActorModifier* idActorModifierManager::AssignAvailableModifier() {
    for (int index = 0; index < modifiers.Num(); ++index) {
        if (!modifiers[index].valid) {
            modifiers[index].index = static_cast<unsigned char>(index);
            modifiers[index].uid = modifierUIDCounter++;
            return &modifiers[index];
        }
    }
    return nullptr;
}

// EA 0x82BEC340
float idActorModifierManager::GetSpeedModifier() const {
    return modValues[idDeclActorModifier::SPEED_MODIFICATION].value;
}

// EA 0x82BEC348
float idActorModifierManager::GetDamageModifier() const {
    return modValues[idDeclActorModifier::DAMAGE_MODIFICATION].value;
}

// EA 0x82BEC350
bool idActorModifierManager::IsOverdriveDisabled() const {
    return modValues[idDeclActorModifier::OVERDRIVE_DISABLE_MODIFICATION]
        .integer == 0;
}

// EA 0x82BEC360
void idActorModifierManager::HandleButtonPress(idUCmdTracker* tracker) {
    for (int index = 0; index < modifiers.Num(); ++index) {
        if (modifiers[index].valid) {
            modifiers[index].HandleButtonPress(tracker);
        }
    }
}

// EA 0x82BEC3A8
void idActorModifierManager::HandleActorModifierMessage(
        const unsigned int uid, const unsigned char index) {
    if (index >= modifiers.Num()) return;
    idActorModifier& modifier = modifiers[index];
    if (modifier.valid && modifier.uid == uid && modifier.index == index) {
        modifier.Activate(true);
    }
}

// EA 0x82BEC3F0
void idActorModifierManager::RecalculateModValue(
        const idDeclActorModifier::ActorModifierAttribute_t attrib) {
    if (attrib <= idDeclActorModifier::NULL_MODIFICATION
            || attrib >= idDeclActorModifier::MODIFIER_ATTRIB_COUNT) {
        return;
    }
    float multiply = 1.0f;
    float add = 0.0f;
    for (int modifierIndex = 0; modifierIndex < modifiers.Num();
            ++modifierIndex) {
        const idActorModifier& modifier = modifiers[modifierIndex];
        if (!modifier.valid || !modifier.active || modifier.decl == nullptr) {
            continue;
        }
        for (int outputIndex = 0;
                outputIndex < modifier.decl->outputs.Num(); ++outputIndex) {
            const auto& output = modifier.decl->outputs[outputIndex];
            if (output.attrib != attrib) continue;
            if (output.operation == idDeclActorModifier::ADD_VALUE) {
                add += output.value;
            } else {
                multiply *= output.value;
            }
        }
    }
    modValues[attrib].Set(multiply + add);
}

// EA 0x82BEC4D0
void idActorModifierManager::OnDamageDealt(idActor* attacker,
        idActor* victim, idEntity* inflictor,
        const idDeclDamage* damageDecl, const float damage,
        const bool isDead) {
    for (int index = 0; index < modifiers.Num(); ++index) {
        if (modifiers[index].valid) {
            modifiers[index].OnDamageDealt(attacker, victim, inflictor,
                damageDecl, damage, isDead);
        }
    }
}

// EA 0x82BEC548
void idActorModifierManager::OnDamageTaken(idEntity* attacker,
        idActor* victim, idEntity* inflictor,
        const idDeclDamage* damageDecl, const float damage,
        const bool isDead) {
    for (int index = 0; index < modifiers.Num(); ++index) {
        if (modifiers[index].valid) {
            modifiers[index].OnDamageTaken(attacker, victim, inflictor,
                damageDecl, damage, isDead);
        }
    }
}

// EA 0x82BEC6E0
void idActorModifierManager::Serialize(idSerializer& serializer) {
    for (int index = 0; index < modValues.Num(); ++index) {
        idActorModifier::Services().SerializeModifierValue(serializer,
            index, modValues[index].value, modValues[index].integer);
    }
    for (int index = 0; index < modifiers.Num(); ++index) {
        modifiers[index].Serialize(serializer);
    }
}

// EA 0x82BEC748
idActorModifierManager::idActorModifierManager()
    : parentPtr(nullptr),
      parentSpawnId(0),
      inventory(nullptr),
      items(0),
      modifiers(),
      modifierUIDCounter(0),
      modValues() {
    for (int index = 0; index < modifiers.Num(); ++index) {
        modifiers[index].manager = this;
    }
}

// EA 0x82BEC8A8
idActorModifierManager::~idActorModifierManager() {
    items.Clear();
    for (int index = 0; index < modifiers.Num(); ++index) {
        modifiers[index].manager = nullptr;
    }
}

// EA 0x82BEC968
void idActorModifierManager::Update() {
    const int gameTime = idActorModifier::Services().GetGameMilliseconds();
    for (int index = 0; index < modifiers.Num(); ++index) {
        idActorModifier& modifier = modifiers[index];
        if (idActorModifier::Services().ResolvePresentable(
                modifier.parentSpawnId) == nullptr) {
            modifier.SetParent(idActorModifier::Services().ResolvePresentable(
                parentSpawnId));
        }
        modifier.Update(gameTime);
    }
}

// EA 0x82BECA60
void idActorModifierManager::ServerThink() {
    Update();
}

// EA 0x82BECA68
idActorModifier* idActorModifierManager::AddModifier(
        const idDeclActorModifier* modifierDecl,
        const idActorModifierItem* modifierItem) {
    idActorModifier* modifier = AssignAvailableModifier();
    if (modifier == nullptr) return nullptr;
    modifier->SetParent(idActorModifier::Services().ResolvePresentable(
        parentSpawnId));
    modifier->item = modifierItem;
    modifier->decl = modifierDecl;
    modifier->manager = this;
    modifier->SetValid(true);
    modifier->SetDefaults();
    modifier->added.Signal();
    return modifier;
}

// EA 0x82BECB20
idActorModifier* idActorModifierManager::FindModifierByInstigator(
        const idDeclActorModifier* modifierDecl,
        idPresentableActor* instigator) {
    for (int index = 0; index < modifiers.Num(); ++index) {
        idActorModifier& modifier = modifiers[index];
        if (!modifier.valid || modifier.decl != modifierDecl) continue;
        if (idActorModifier::Services().ResolvePresentable(
                modifier.instigatorSpawnId) == instigator) {
            return &modifier;
        }
    }
    return nullptr;
}

// EA 0x82BECBE0
eventVoid idActorModifierManager::Notice_ModifierEvent(
        idActorModifier* modifier, const bool activating,
        const bool predicted) {
    if (modifier == nullptr || modifier->decl == nullptr) return {};
    unsigned int changedAttributes = 0;
    idPresentableActor* parent =
        idActorModifier::Services().ResolvePresentable(parentSpawnId);
    for (int index = 0; index < modifier->decl->outputs.Num(); ++index) {
        const auto& output = modifier->decl->outputs[index];
        if (idActorModifier::Services().IsServer() && activating
                && output.action == idDeclActorModifier::ACTION_DROP_POI) {
            idActorModifier::Services().DropPointOfInterest(parent, output);
            continue;
        }
        if (idActorModifier::Services().IsServer() && activating
                && output.action
                    == idDeclActorModifier::ACTION_CLEAR_OVERDRIVE_POINTS) {
            if (parent != nullptr) {
                idActorModifier::Services().SetOverdrivePoints(parent, 0.0f);
            }
            continue;
        }
        if ((!predicted || output.predicted)
                && (!idActorModifier::Services().IsClient()
                    || predicted || !output.predicted)) {
            changedAttributes |= 1u << output.attrib;
        }
    }
    for (int attrib = idDeclActorModifier::SPEED_MODIFICATION;
            attrib < idDeclActorModifier::MODIFIER_ATTRIB_COUNT; ++attrib) {
        if ((changedAttributes & (1u << attrib)) != 0) {
            RecalculateModValue(static_cast<
                idDeclActorModifier::ActorModifierAttribute_t>(attrib));
        }
    }
    return {};
}

// EA 0x82BECDF8
void idActorModifierManager::InventoryItemAdded(
        idActorModifierItem* item, idEntity*) {
    if (item != nullptr && item->decl != nullptr) {
        items.Append(item);
        AddModifier(item->decl, item);
    }
}

// EA 0x82BECEC8
idActorModifier* idActorModifierManager::AddModifierUnique(
        const idDeclActorModifier* modifierDecl,
        const idActorModifierItem* modifierItem,
        idPresentableActor* instigator) {
    idActorModifier* modifier =
        FindModifierByInstigator(modifierDecl, instigator);
    if (modifier != nullptr) {
        modifier->activationTime =
            idActorModifier::Services().GetGameMilliseconds();
        return modifier;
    }
    modifier = AddModifier(modifierDecl, modifierItem);
    if (modifier != nullptr) {
        modifier->instigatorSpawnId = instigator == nullptr
            ? 0
            : idActorModifier::Services().GetPresentableSpawnId(instigator);
    }
    return modifier;
}
