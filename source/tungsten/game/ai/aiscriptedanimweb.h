#pragma once

#include "../../../shared/idlib/containers/list.h"
#include "../../../shared/idlib/text/str.h"
#include "../entities/entityptr.h"

class idAI2;
class idEntity;

class idAIScriptedAnimWeb {
public:
    enum stateMarker_t : int {
        STATE_RANDOM = -2,
        STATE_EXIT = -3
    };

    enum loopTriggerType_t : int {
        TRIGGERTYPE_ONCOUNT = 0,
        TRIGGERTYPE_EVERYCOUNT = 1
    };

    // The state payload is consumed by idAction_ScriptedAnimWeb.  These
    // translation-unit routines only require stable list identity/count.
    struct animWebState_t {
        int recoveredMarker;
    };

    struct animState_t {
        idList<animWebState_t, 5>* animWebStates;
        int currentState;

        animState_t() : animWebStates(nullptr), currentState(-1) {}
        void SetcurrentState(int state);
    };

    idAIScriptedAnimWeb();

    void Spawn();
    void StartAIAction(idEntity* activator);
    virtual void OnActivate(idEntity* activator);

    void SetName(const char* value) { name = value; }
    void AddState(int marker = 0) { animWebStates.Append({ marker }); }
    void AddTargetSpawnId(int spawnId) {
        targets.Append(idEntityPtr<idEntity>(spawnId));
    }

    idList<animWebState_t, 5> animWebStates;
    animState_t stateInfo;

private:
    idStr name;
    idList<idEntityPtr<idEntity>, 5> targets;
};
