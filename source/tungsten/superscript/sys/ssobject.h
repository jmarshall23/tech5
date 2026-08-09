#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\superscript\sys\ssobject.h
// Recovered logical types: 33
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13278; PDB kind: class.
class ssObjectBase
{
public:
  int spawnId;
  int objectId;
};

// IDA Local Type ordinal 13279; PDB kind: class.
class ssObject<ssWorldUtil> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13281; PDB kind: class.
class ssObject<idSSObject> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13282; PDB kind: class.
class idSSObject
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13283.
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
  virtual ~idSSObject();

};

// IDA Local Type ordinal 13823; PDB kind: class.
class ssObject<action_moveToGoalEntity> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13846; PDB kind: class.
class ssObject<musicManagerSwitch> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13852; PDB kind: class.
class ssObject<phook_test1_derrived> : public ssObjectBase
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13853.
  virtual void Destroy();

};

// IDA Local Type ordinal 13865; PDB kind: class.
class ssObject<util_replaceTargets> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13867; PDB kind: class.
class ssObject<dy_world> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13870; PDB kind: class.
class ssObject<ssComment> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13879; PDB kind: class.
class ssObject<util_entityFlagActivate> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13883; PDB kind: class.
class ssObject<util_triggerVisibility> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13887; PDB kind: class.
class ssObject<util_nodeModifierTrigger> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13934; PDB kind: class.
class ssObject<util_entityFlagVolume> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13938; PDB kind: class.
class ssObject<util_entityFlag> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13941; PDB kind: class.
class ssObject<util_triggerLookAtManagerVolume> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13946; PDB kind: class.
class ssObject<aiObjectTest> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13955; PDB kind: class.
class ssObject<_combatGoal> : public ssObjectBase
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13956.
  virtual void Init();
  virtual void DebugDrawStatus();

};

// IDA Local Type ordinal 13958; PDB kind: class.
class ssObject<_goalKillCounter> : public ssObject<_combatGoal>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13957.
  virtual void Init();
  virtual void DebugDrawStatus();

};

// IDA Local Type ordinal 13959; PDB kind: class.
class ssObject<musicModifier> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13962; PDB kind: class.
class ssObject<jake_test1> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13976; PDB kind: class.
class ssObject<musicManager> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13979; PDB kind: class.
class ssObject<util_triggerTeleport> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13982; PDB kind: class.
class ssObject<_goalRemainingCountActor> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13984; PDB kind: class.
class ssObject<util_triggerLookAtSafety> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13985; PDB kind: class.
class ssObject<ssDebugUtil> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13986; PDB kind: class.
class ssObject<util_distanceTrigger> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13987; PDB kind: class.
class ssObject<util_removeActorOnTriggerTouched> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13989; PDB kind: class.
class ssObject<_goalRemainingCounter> : public ssObject<_combatGoal>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13988.
  virtual void Init();
  virtual void DebugDrawStatus();

};

// IDA Local Type ordinal 13993; PDB kind: class.
class ssObject<util_debugMetaData> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13994; PDB kind: class.
class ssObject<_goalKillCountActor> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13995; PDB kind: class.
class ssObject<util_triggerLookAt> : public ssObjectBase
{
public:
};

// IDA Local Type ordinal 13996; PDB kind: class.
class ssObject<phook_test1> : public ssObjectBase
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13997.
  virtual void Destroy();

};
