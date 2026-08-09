#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\guis\swf\swf_scriptobject.h
// Recovered logical types: 13
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1433; PDB kind: enum.
enum idSWFScriptObject::swfObjectType_t : __int32
{
  SWF_OBJECT_OBJECT = 0x0,
  SWF_OBJECT_ARRAY = 0x1,
  SWF_OBJECT_SPRITE = 0x2,
  SWF_OBJECT_TEXT = 0x3,
  NUM_SWF_OBJECT_TYPES = 0x4,
};

// IDA Local Type ordinal 2670; PDB kind: enum.
enum idSWFScriptObject::swfNamedVarFlags_t : __int32
{
  SWF_VAR_FLAG_NONE = 0x0,
  SWF_VAR_FLAG_READONLY = 0x2,
  SWF_VAR_FLAG_DONTENUM = 0x4,
};

// IDA Local Type ordinal 13284; PDB kind: class.
class idSuperScriptObject : public idSSObject
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13286.
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
  virtual ~idSuperScriptObject();
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

  ssEntity self;
};

// IDA Local Type ordinal 13488; PDB kind: class.
class idScriptObject : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13489.
  virtual idTypeInfo *GetType();
  virtual ~idScriptObject();

  idTypeDef *type;
  unsigned __int8 *data;
};

// IDA Local Type ordinal 13874; PDB kind: struct.
struct idSuperScriptObject::threadData1_t<ssEntity>
{
  void (__fastcall *realFunc)(idSSObject *, ssEntity);
  const ssEntity *p1;
};

// IDA Local Type ordinal 14000; PDB kind: struct.
struct idSuperScriptObject::threadData2_t<enum musicTensionStates_t,tensionTransition_t>
{
  void (__fastcall *realFunc)(idSSObject *, musicTensionStates_t, tensionTransition_t);
  const musicTensionStates_t *p1;
  const tensionTransition_t *p2;
};

// IDA Local Type ordinal 14001; PDB kind: struct.
struct idSuperScriptObject::threadData2_t<ssEntity,float>
{
  void (__fastcall *realFunc)(idSSObject *, ssEntity, float);
  const ssEntity *p1;
  const float *p2;
};

// IDA Local Type ordinal 14002; PDB kind: struct.
struct idSuperScriptObject::threadData3_t<ssEntity,float,bool>
{
  void (__fastcall *realFunc)(idSSObject *, ssEntity, float, bool);
  const ssEntity *p1;
  const float *p2;
  const bool *p3;
};

// IDA Local Type ordinal 14003; PDB kind: struct.
struct idSuperScriptObject::threadData2_t<ssString,int>
{
  void (__fastcall *realFunc)(idSSObject *, ssString, int);
  const ssString *p1;
  const int *p2;
};

// IDA Local Type ordinal 14004; PDB kind: struct.
struct idSuperScriptObject::threadData2_t<ssString,float>
{
  void (__fastcall *realFunc)(idSSObject *, ssString, float);
  const ssString *p1;
  const float *p2;
};

// IDA Local Type ordinal 14764; PDB kind: class.
class idSWFScriptObject
{
public:
  int refCount;
  idList<idSWFScriptObject::swfNamedVar_t,72> variables;
  int variablesHash[16];
  idSWFScriptObject *prototype;
  idSWFScriptObject::swfObjectType_t objectType;
  idSWFScriptObject::swfObjectData_t data;
};

// IDA Local Type ordinal 14775; PDB kind: struct.
struct idSWFScriptObject::swfNamedVar_t
{
  int index;
  int hashNext;
  idAtomicString name;
  idSWFScriptVar value;
  idSWFScriptNativeVariable *native;
  int flags;
};

// IDA Local Type ordinal 14810; PDB kind: union.
union idSWFScriptObject::swfObjectData_t
{
  idSWFSpriteInstance *sprite;
  idSWFTextInstance *text;
};
