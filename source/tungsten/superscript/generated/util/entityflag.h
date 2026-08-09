#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\superscript\generated\util\entityflag.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2232; PDB kind: enum.
enum aiEntityFlags_t : __int32
{
  AIENTFLAG_DEAD = 0x1,
  AIENTFLAG_CROUCHED = 0x2,
  AIENTFLAG_LEAN_RIGHT = 0x4,
  AIENTFLAG_LEAN_LEFT = 0x8,
  AIENTFLAG_RUNNING = 0x10,
  AIENTFLAG_NO_SIGHT_STIM = 0x20,
  AIENTFLAG_DRIVING = 0x40,
  AIENTFLAG_DYING = 0x80,
};

// IDA Local Type ordinal 13834; PDB kind: struct.
struct util_entityFlag::callFunction_t
{
  ssEntity target;
  ssString function;
};

// IDA Local Type ordinal 13836; PDB kind: struct.
struct util_entityFlag::flagDef_t
{
  ssString name;
  bool animNotify;
  bool state;
  int count;
  float lastTime;
  ssList<int> terminateThreads;
  ssList<util_entityFlag::callFunction_t> callFunctions;
};

// IDA Local Type ordinal 13838; PDB kind: class.
class util_entityFlag : public idSuperScriptObject
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13839.
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
  virtual ~util_entityFlag();
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

  ssList<util_entityFlag::flagDef_t> flags;
};
