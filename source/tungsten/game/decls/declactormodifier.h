#pragma once

#include "idlib/containers/list.h"
#include "idlib/text/str.h"

class idDeclFX;
class idMaterial;
class idSoundShader;

class idDeclActorModifier {
public:
    enum ActorModifierAction_t : int {
        ACTION_MODIFY_VALUE = 0,
        ACTION_APPLY_MODIFIER = 1,
        ACTION_DROP_POI = 2,
        ACTION_GIVE_OVERDRIVE_POINTS = 3,
        ACTION_CLEAR_OVERDRIVE_POINTS = 4,
        MODIFIER_ACTION_COUNT = 5
    };
    enum ActorModifierAttribute_t : int {
        NULL_MODIFICATION = 0,
        SPEED_MODIFICATION = 1,
        DAMAGE_MODIFICATION = 2,
        OVERDRIVE_DISABLE_MODIFICATION = 3,
        MODIFIER_ATTRIB_COUNT = 4
    };
    enum ActorModifierAttributeOperation_t : int {
        MULTIPLY_VALUE = 0,
        ADD_VALUE = 1
    };
    enum ActorModifierTarget_t : int {
        TARGET_SELF = 0,
        TARGET_VICTIM = 1,
        TARGET_ATTACKER = 2
    };
    enum ActorModifierDepType_t : int {
        NULL_DEPTYPE = 0,
        OVERDRIVE_FULL_DEPTYPE = 1,
        DEPTYPE_COUNT = 2
    };
    enum TriggerType_t : int {
        TRIGGER_TYPE_BUTTON = 0,
        TRIGGER_TYPE_ALWAYS_ON = 1,
        TRIGGER_TYPE_EVENT = 2,
        TRIGGER_TYPE_DAMAGE_DEALT = 3,
        TRIGGER_TYPE_DAMAGE_TAKEN = 4,
        TRIGGER_TYPE_TIMER = 5
    };
    enum ActorModifierUISlot_t : int {
        SLOT_HIDDEN = 0,
        SLOT_ACTIVE = 1,
        SLOT_PASSIVE = 2,
        SLOT_OVERDRIVE = 3
    };

    struct ActorModifierSounds_t {
        const idSoundShader* attackSound = nullptr;
        const idSoundShader* activeSound = nullptr;
        const idSoundShader* startSound = nullptr;
        const idSoundShader* stopSound = nullptr;
        const idSoundShader* almostDoneSound = nullptr;
    };
    struct ActorModifierOutput_t {
        ActorModifierAction_t action = ACTION_MODIFY_VALUE;
        ActorModifierAttribute_t attrib = NULL_MODIFICATION;
        ActorModifierAttributeOperation_t operation = MULTIPLY_VALUE;
        ActorModifierTarget_t target = TARGET_SELF;
        float value = 0.0f;
        const idDeclActorModifier* decl = nullptr;
        const idMaterial* customMaterial = nullptr;
        const idMaterial* customWeaponMaterial = nullptr;
        const idMaterial* customMaterial3rdPerson = nullptr;
        const idMaterial* customWeaponMaterial3rdPerson = nullptr;
        ActorModifierSounds_t sounds;
        bool predicted = false;
    };
    struct ActorModifierTrigger_t {
        TriggerType_t type = TRIGGER_TYPE_EVENT;
        int button = 0;
        int timerDelay = 0;
    };
    struct ActorModifierDeps_t {
        ActorModifierDepType_t type = NULL_DEPTYPE;
    };

    idStr internalName;
    idList<ActorModifierOutput_t, 5> outputs{0};
    idList<ActorModifierTrigger_t, 5> triggers{0};
    idList<ActorModifierDeps_t, 5> deps{0};
    int lifetime = 0;
    int removeAfter = 0;
    int cooldown = 0;
    const idDeclFX* fxDecl = nullptr;
    ActorModifierUISlot_t uiSlot = SLOT_HIDDEN;
    bool removeOnDeath = false;
};
