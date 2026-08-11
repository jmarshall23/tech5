#pragma once

#include "game/entities/actormodifier.h"
#include "idlib/containers/array.h"
#include "idlib/containers/list.h"

class idActorModifierManager {
public:
    struct ActorModifierVar_s {
        netBoolEvent_t event;
        float netValue = 0.0f;
        float value = 1.0f;
        int integer = 1;

        void Set(float newValue) {
            value = newValue;
            integer = static_cast<int>(newValue);
            netValue = newValue;
            event.Signal();
        }
    };

    idActorModifierManager();
    virtual ~idActorModifierManager();

    void PostSerializeRead(bool firstClientFrame);
    void InventoryItemRemoved(idActorModifierItem* item, idEntity* owner);
    idActorModifier* AssignAvailableModifier();
    float GetSpeedModifier() const;
    float GetDamageModifier() const;
    bool IsOverdriveDisabled() const;
    void HandleButtonPress(idUCmdTracker* tracker);
    virtual void HandleActorModifierMessage(
        unsigned int uid, unsigned char index);
    void RecalculateModValue(
        idDeclActorModifier::ActorModifierAttribute_t attrib);
    void OnDamageDealt(idActor* attacker, idActor* victim,
        idEntity* inflictor, const idDeclDamage* damageDecl,
        float damage, bool isDead);
    void OnDamageTaken(idEntity* attacker, idActor* victim,
        idEntity* inflictor, const idDeclDamage* damageDecl,
        float damage, bool isDead);
    void Serialize(idSerializer& serializer);
    void Update();
    void ServerThink();
    idActorModifier* AddModifier(const idDeclActorModifier* decl,
        const idActorModifierItem* item);
    idActorModifier* FindModifierByInstigator(
        const idDeclActorModifier* decl, idPresentableActor* instigator);
    eventVoid Notice_ModifierEvent(idActorModifier* modifier,
        bool activating, bool predicted);
    void InventoryItemAdded(idActorModifierItem* item, idEntity* owner);
    idActorModifier* AddModifierUnique(const idDeclActorModifier* decl,
        const idActorModifierItem* item, idPresentableActor* instigator);

    idPresentableActor* parentPtr;
    std::uint32_t parentSpawnId;
    idInventoryCollection* inventory;
    idList<idActorModifierItem*, 5> items;
    idArray<idActorModifier, 16> modifiers;
    unsigned int modifierUIDCounter;
    idArray<ActorModifierVar_s, 4> modValues;
};
