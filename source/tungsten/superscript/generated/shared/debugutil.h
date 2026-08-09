#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\superscript\generated\shared\debugutil.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13863; PDB kind: class.
class ssDebugUtil : public idSuperScriptObject
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13864.
  virtual void Init();
  virtual void Destroy();
  virtual void _OnActivate(int);
  virtual void _OnTrigger(int);
  virtual void _OnActivateTargets(int);
  virtual void _OnActionReached(int, int, bool);
  virtual void _OnGoalReach(int);
  virtual void _OnGoalAssigned(int);
  virtual void _OnDamage(int, float);
  virtual void _OnDeath(int);
  virtual void _OnLeftGoal(int);
  virtual void _OnReachGoal(int);
  virtual void _OnLeaveAction(int);
  virtual void _OnReachAction(int);
  virtual void _OnAssignedGoal(int);
  virtual void _OnAnimNotify(const char *);
  virtual void _OnAnimEnd();
  virtual void _OnAnimStart();
  virtual void _OnMoverNotify(const char *);
  virtual void _OnTargetSpawn(int);
  virtual void _OnEnter(int);
  virtual void _OnExit(int);
  virtual void _OnUse(int);
  virtual const char *_name();
  virtual bool _isTypeOf(const char *);
  virtual int _getEntity();
  virtual void _setEntity(int);
  virtual void (__fastcall *_getThreadFunction(const char *))(idSSObject *, void *);
  virtual bool _isNotifyFunction(const char *);
  virtual void *_getDeclPtr();
  virtual ~ssDebugUtil();
  virtual void OnActivate(ssEntity);
  virtual void OnTrigger(ssEntity);
  virtual void OnActivateTargets(ssEntity);
  virtual void OnActionReached(ssEntity, ssEntity, bool);
  virtual void OnGoalReach(ssEntity);
  virtual void OnGoalAssigned(ssEntity);
  virtual void OnDamage(ssEntity, float);
  virtual void OnDeath(ssEntity);
  virtual void OnLeftGoal(ssEntity);
  virtual void OnReachGoal(ssEntity);
  virtual void OnLeaveAction(ssEntity);
  virtual void OnReachAction(ssEntity);
  virtual void OnAssignedGoal(ssEntity);
  virtual void OnAnimNotify(ssString);
  virtual void OnAnimEnd();
  virtual void OnAnimStart();
  virtual void OnMoverNotify(ssString);
  virtual void OnTargetSpawn(ssEntity);
  virtual void OnEnter(ssEntity);
  virtual void OnExit(ssEntity);
  virtual void OnUse(ssEntity);

  int debugActionsThreadId;
  idDeclDamage *suicide;
};
