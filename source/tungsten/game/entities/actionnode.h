#pragma once

#include "game/ai/aiactionscript.h"
#include "game/ai/aimoveparms.h"
#include "game/ai/aistates.h"
#include "game/entities/entityptr.h"
#include "game/gamesys/eventarg.h"
#include "aas2file/aastraversalchaindata.h"
#include "gamelib/animstack/animweb/animwebpath.h"
#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

class idAnimatedEntity;
class idEntity;

enum actionNodeAASResult_t : int {
    ACTIONNODE_AAS_VALID = 0,
    ACTIONNODE_AAS_LOAD_FAILED = 1,
    ACTIONNODE_AAS_OUTSIDE = 2
};

class idActionNode;

// Runtime-owned entity tables, AAS instances, and physics clip objects are
// not reconstructed in this leaf translation unit.  This boundary preserves
// the recovered decisions while allowing the central owners to be connected
// without inventing duplicate engine state.
class idActionNodeServices {
public:
    virtual ~idActionNodeServices() = default;

    virtual int GetSpawnId(const idEntity*) const { return 0x1FFF; }
    virtual idEntity* ResolveEntity(int) const { return nullptr; }
    virtual idAnimatedEntity* ResolveAnimatedEntity(int) const {
        return nullptr;
    }
    virtual bool IsPlayer(const idEntity*) const { return false; }
    virtual bool IsAI(const idEntity*) const { return false; }
    virtual bool IsDead(const idEntity*) const { return false; }

    virtual actionNodeAASResult_t ValidateAAS(aasType_t,
        const idVec3&, idStr& aasName) const {
        aasName.Clear();
        return ACTIONNODE_AAS_VALID;
    }

    virtual void ConfigureClip(idActionNode&, const idBounds&,
        const idVec3&, const idMat3&, float, int, int) {}
    virtual void SetClipEnabled(idActionNode&, bool, int) {}
};

class idActionNode {
public:
    struct anim_t {
        idAnimWebPath animWebNode;
        idEntityPtr<idEntity> trigger;
        float minLoopTime = 0.0f;
        float maxLoopTime = 0.0f;
        float timeBetween = 0.0f;
        int weight = 0;
        bool enableHeadTracking = false;
        int nextPlayTime = 0;
    };

    struct clipModelInfo_t {
        idVec3 size;
    };

    idActionNode();
    virtual ~idActionNode();

    static void SetServices(idActionNodeServices* services);
    static idActionNodeServices& Services();

    bool IsActionNodeAvailable(const idEntity* user) const;
    eventVoid Event_Untouch(idEntity* toucher, int clipModelId);
    bool ReserveActionNode(idAnimatedEntity* user);
    bool LeaveActionNode(idAnimatedEntity* user);
    void OnActivate(idEntity* activator);
    void Spawn();
    eventVoid Event_Touch(idEntity* toucher, int clipModelId);

    idStr name;
    idVec3 spawnPosition;
    idMat3 spawnOrientation;
    clipModelInfo_t clipModelInfo;
    idEntityPtr<idAnimatedEntity> reservingEntity;
    idStr groupName;
    idList<idScriptAction, 5> actionScript;
    standState_t standState;
    sitState_t sitState;
    posture_t posture;
    idList<anim_t, 5> anims;
    bool shouldCheckAAS;
    bool canBeBlockedByAI;
    aasType_t aasType;
    bool startOff;
    bool isActive;
    float reachedPointTolerance;
    idList<idEntityPtr<idEntity>, 5> touching;

private:
    void DisableClip();
};
