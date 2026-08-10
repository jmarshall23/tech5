#pragma once

#include "superscript/lib/entity.h"
#include "superscript/lib/string.h"

class idSSObject;
using ssThreadFunction_t = void (__fastcall *)(idSSObject*, void*);

// Clean source-facing form of the recovered SuperScript object ABI.  The
// generated reflection translation units will replace these default event
// handlers as they are recovered.
class idSuperScriptObject {
public:
    virtual void Init() {}
    virtual void Destroy() {}
    virtual void _OnActivate(int) {}
    virtual void _OnTrigger(int) {}
    virtual void _OnActivateTargets(int) {}
    virtual void _OnActionReached(int, int, bool) {}
    virtual void _OnGoalReach(int) {}
    virtual void _OnGoalAssigned(int) {}
    virtual void _OnDamage(int, float) {}
    virtual void _OnDeath(int) {}
    virtual void _OnLeftGoal(int) {}
    virtual void _OnReachGoal(int) {}
    virtual void _OnLeaveAction(int) {}
    virtual void _OnReachAction(int) {}
    virtual void _OnAssignedGoal(int) {}
    virtual void _OnAnimNotify(const char*) {}
    virtual void _OnAnimEnd() {}
    virtual void _OnAnimStart() {}
    virtual void _OnMoverNotify(const char*) {}
    virtual void _OnTargetSpawn(int) {}
    virtual void _OnEnter(int) {}
    virtual void _OnExit(int) {}
    virtual void _OnUse(int) {}
    virtual const char* _name() { return "idSuperScriptObject"; }
    virtual bool _isTypeOf(const char*) { return false; }
    virtual int _getEntity() { return self.spawnId; }
    virtual void _setEntity(const int spawnId) { self.spawnId = spawnId; }
    virtual ssThreadFunction_t _getThreadFunction(const char*) {
        return nullptr;
    }
    virtual bool _isNotifyFunction(const char*) { return false; }
    virtual void* _getDeclPtr() { return nullptr; }
    virtual ~idSuperScriptObject() = default;
    virtual void OnActivate(ssEntity) {}
    virtual void OnTrigger(ssEntity) {}
    virtual void OnActivateTargets(ssEntity) {}
    virtual void OnActionReached(ssEntity, ssEntity, bool) {}
    virtual void OnGoalReach(ssEntity) {}
    virtual void OnGoalAssigned(ssEntity) {}
    virtual void OnDamage(ssEntity, float) {}
    virtual void OnDeath(ssEntity) {}
    virtual void OnLeftGoal(ssEntity) {}
    virtual void OnReachGoal(ssEntity) {}
    virtual void OnLeaveAction(ssEntity) {}
    virtual void OnReachAction(ssEntity) {}
    virtual void OnAssignedGoal(ssEntity) {}
    virtual void OnAnimNotify(ssString) {}
    virtual void OnAnimEnd() {}
    virtual void OnAnimStart() {}
    virtual void OnMoverNotify(ssString) {}
    virtual void OnTargetSpawn(ssEntity) {}
    virtual void OnEnter(ssEntity) {}
    virtual void OnExit(ssEntity) {}
    virtual void OnUse(ssEntity) {}

    ssEntity self;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idSuperScriptObject) == 8,
    "Recovered idSuperScriptObject ABI changed");
#endif
