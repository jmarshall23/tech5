
// ========================================================================
// ??0_combatGoal@@QAA@XZ
// EA  : 0x82EE2BF0
// RVA : 0x00EE2BF0
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

_combatGoal *__fastcall _combatGoal::_combatGoal(_combatGoal *this)
{
  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (_combatGoal_vtbl *)&_combatGoal::`vftable';
  ssString::Init(this: &this->call);
  this->bTriggerFirst = false;
  this->state = COMBAT_GOAL_WAITING;
  this->delay = 0.0;
  return this;
}


// ========================================================================
// __unwind$22313
// EA  : 0x82EE2C5C
// RVA : 0x00EE2C5C
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void _unwind_22313()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 112 + 132));
}


// ========================================================================
// ?_name@_combatGoal@@UBAPBDXZ
// EA  : 0x82EE2C88
// RVA : 0x00EE2C88
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

const char *__fastcall _combatGoal::_name(_combatGoal *this)
{
  return "_combatGoal";
}


// ========================================================================
// ?_isTypeOf@_combatGoal@@UAA_NPBD@Z
// EA  : 0x82EE2C98
// RVA : 0x00EE2C98
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

BOOL __fastcall _combatGoal::_isTypeOf(_combatGoal *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "_combatGoal")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@_combatGoal@@UAAPAXXZ
// EA  : 0x82EE2CD0
// RVA : 0x00EE2CD0
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

ssDeclInfo_t *__fastcall _combatGoal::_getDeclPtr(_combatGoal *this)
{
  return `_combatGoal::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ??0_goalRemainingCountActor@@QAA@XZ
// EA  : 0x82EE2D50
// RVA : 0x00EE2D50
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

_goalRemainingCountActor *__fastcall _goalRemainingCountActor::_goalRemainingCountActor(_goalRemainingCountActor *this)
{
  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (_goalRemainingCountActor_vtbl *)&_goalRemainingCountActor::`vftable';
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->manager);
  return this;
}


// ========================================================================
// __unwind$22361
// EA  : 0x82EE2DA4
// RVA : 0x00EE2DA4
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void _unwind_22361()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 112 + 132));
}


// ========================================================================
// ?_name@_goalRemainingCountActor@@UBAPBDXZ
// EA  : 0x82EE2DD0
// RVA : 0x00EE2DD0
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

const char *__fastcall _goalRemainingCountActor::_name(_goalRemainingCountActor *this)
{
  return "_goalRemainingCountActor";
}


// ========================================================================
// ?_isTypeOf@_goalRemainingCountActor@@UAA_NPBD@Z
// EA  : 0x82EE2DE0
// RVA : 0x00EE2DE0
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

BOOL __fastcall _goalRemainingCountActor::_isTypeOf(_goalRemainingCountActor *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "_goalRemainingCountActor")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@_goalRemainingCountActor@@UAAPAXXZ
// EA  : 0x82EE2E18
// RVA : 0x00EE2E18
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

ssDeclInfo_t *__fastcall _goalRemainingCountActor::_getDeclPtr(_goalRemainingCountActor *this)
{
  return `_goalRemainingCountActor::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?_isNotifyFunction@_goalKillCountActor@@UBA_NPBD@Z
// EA  : 0x82EE2E28
// RVA : 0x00EE2E28
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

BOOL __fastcall _goalKillCountActor::_isNotifyFunction(_goalKillCountActor *this, const char *name)
{
  return ssString::Icmp(text: "OnDeath", text2: name) == 0
      || (_cntlzw(ssString::Icmp(text: "OnRemove", text2: name)) & 0x20) != 0;
}


// ========================================================================
// ??0_goalKillCountActor@@QAA@XZ
// EA  : 0x82EE2EA0
// RVA : 0x00EE2EA0
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

_goalKillCountActor *__fastcall _goalKillCountActor::_goalKillCountActor(_goalKillCountActor *this)
{
  idSuperScriptObject::idSuperScriptObject(this);
  this->__vftable = (_goalKillCountActor_vtbl *)&_goalKillCountActor::`vftable';
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->manager);
  return this;
}


// ========================================================================
// __unwind$22430
// EA  : 0x82EE2EF4
// RVA : 0x00EE2EF4
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void _unwind_22430()
{
  int v0; // r12

  idSSObject::~idSSObject(this: *(idSuperScriptObject **)(v0 - 112 + 132));
}


// ========================================================================
// ?_name@_goalKillCountActor@@UBAPBDXZ
// EA  : 0x82EE2F20
// RVA : 0x00EE2F20
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

const char *__fastcall _goalKillCountActor::_name(_goalKillCountActor *this)
{
  return "_goalKillCountActor";
}


// ========================================================================
// ?_isTypeOf@_goalKillCountActor@@UAA_NPBD@Z
// EA  : 0x82EE2F30
// RVA : 0x00EE2F30
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

BOOL __fastcall _goalKillCountActor::_isTypeOf(_goalKillCountActor *this, const char *parentClass)
{
  return (_cntlzw(ssString::Icmp(text: parentClass, text2: "_goalKillCountActor")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@_goalKillCountActor@@UAAPAXXZ
// EA  : 0x82EE2F68
// RVA : 0x00EE2F68
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

ssDeclInfo_t *__fastcall _goalKillCountActor::_getDeclPtr(_goalKillCountActor *this)
{
  return `_goalKillCountActor::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?_isNotifyFunction@musicModifier@@UBA_NPBD@Z
// EA  : 0x82EE3228
// RVA : 0x00EE3228
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

BOOL __fastcall musicModifier::_isNotifyFunction(util_distanceTrigger *this, const char *name)
{
  return (_cntlzw(ssString::Icmp(text: "OnActivate", text2: name)) & 0x20) != 0;
}


// ========================================================================
// ??0_goalKillCounter@@QAA@XZ
// EA  : 0x82EE3B58
// RVA : 0x00EE3B58
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

_goalKillCounter *__fastcall _goalKillCounter::_goalKillCounter(_goalKillCounter *this)
{
  int v2; // r3
  int v3; // r3

  _combatGoal::_combatGoal(this);
  this->__vftable = (_goalKillCounter_vtbl *)&_goalKillCounter::`vftable';
  this->actorList.data = nullptr;
  this->actorList.num = 0;
  this->actorList.size = 0;
  if ( gameInterface != nullptr )
    v2 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v2 = 0;
  this->actorList.threadId = v2;
  this->spawnerList.data = nullptr;
  this->spawnerList.num = 0;
  this->spawnerList.size = 0;
  if ( gameInterface != nullptr )
    v3 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v3 = 0;
  this->spawnerList.threadId = v3;
  this->nCount = 0;
  this->bRepeat = false;
  this->bKillingBlows = false;
  this->killCount = 0;
  this->fPlayerContributionThreshold = 0.0;
  return this;
}


// ========================================================================
// __unwind$23259
// EA  : 0x82EE3C18
// RVA : 0x00EE3C18
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void _unwind_23259()
{
  int v0; // r12

  _combatGoal::~_combatGoal(this: *(_combatGoal **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$23260
// EA  : 0x82EE3C40
// RVA : 0x00EE3C40
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void _unwind_23260()
{
  int v0; // r12

  ssList<util_debugMetaData::lineInfo_t>::~ssList<util_debugMetaData::lineInfo_t>(this: (ssList<int> *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// ?_name@_goalKillCounter@@UBAPBDXZ
// EA  : 0x82EE3C70
// RVA : 0x00EE3C70
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

const char *__fastcall _goalKillCounter::_name(_goalKillCounter *this)
{
  return "_goalKillCounter";
}


// ========================================================================
// ?_isTypeOf@_goalKillCounter@@UAA_NPBD@Z
// EA  : 0x82EE3C80
// RVA : 0x00EE3C80
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

BOOL __fastcall _goalKillCounter::_isTypeOf(_goalKillCounter *this, const char *parentClass)
{
  return ssString::Icmp(text: parentClass, text2: "_goalKillCounter") == 0
      || (_cntlzw(ssString::Icmp(text: parentClass, text2: "_combatGoal")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@_goalKillCounter@@UAAPAXXZ
// EA  : 0x82EE3CF0
// RVA : 0x00EE3CF0
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

ssDeclInfo_t *__fastcall _goalKillCounter::_getDeclPtr(_goalKillCounter *this)
{
  return `_goalKillCounter::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ??0_goalRemainingCounter@@QAA@XZ
// EA  : 0x82EE3DB8
// RVA : 0x00EE3DB8
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

_goalRemainingCounter *__fastcall _goalRemainingCounter::_goalRemainingCounter(_goalRemainingCounter *this)
{
  int v2; // r3
  int v3; // r3

  _combatGoal::_combatGoal(this);
  this->__vftable = (_goalRemainingCounter_vtbl *)&_goalRemainingCounter::`vftable';
  this->actorList.data = nullptr;
  this->actorList.num = 0;
  this->actorList.size = 0;
  if ( gameInterface != nullptr )
    v2 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v2 = 0;
  this->actorList.threadId = v2;
  this->spawnerList.data = nullptr;
  this->spawnerList.num = 0;
  this->spawnerList.size = 0;
  if ( gameInterface != nullptr )
    v3 = gameInterface->GetAllocThread(this: gameInterface);
  else
    v3 = 0;
  this->spawnerList.threadId = v3;
  this->nCount = 0;
  this->numRemaining = 0;
  return this;
}


// ========================================================================
// __unwind$23346
// EA  : 0x82EE3E64
// RVA : 0x00EE3E64
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void _unwind_23346()
{
  int v0; // r12

  _combatGoal::~_combatGoal(this: *(_combatGoal **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$23347
// EA  : 0x82EE3E8C
// RVA : 0x00EE3E8C
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void _unwind_23347()
{
  int v0; // r12

  ssList<util_debugMetaData::lineInfo_t>::~ssList<util_debugMetaData::lineInfo_t>(this: (ssList<int> *)(*(_DWORD *)(v0 - 128 + 148) + 40));
}


// ========================================================================
// ?_name@_goalRemainingCounter@@UBAPBDXZ
// EA  : 0x82EE3EB8
// RVA : 0x00EE3EB8
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

const char *__fastcall _goalRemainingCounter::_name(_goalRemainingCounter *this)
{
  return "_goalRemainingCounter";
}


// ========================================================================
// ?_isTypeOf@_goalRemainingCounter@@UAA_NPBD@Z
// EA  : 0x82EE3EC8
// RVA : 0x00EE3EC8
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

BOOL __fastcall _goalRemainingCounter::_isTypeOf(_goalRemainingCounter *this, const char *parentClass)
{
  return ssString::Icmp(text: parentClass, text2: "_goalRemainingCounter") == 0
      || (_cntlzw(ssString::Icmp(text: parentClass, text2: "_combatGoal")) & 0x20) != 0;
}


// ========================================================================
// ?_getDeclPtr@_goalRemainingCounter@@UAAPAXXZ
// EA  : 0x82EE3F38
// RVA : 0x00EE3F38
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

ssDeclInfo_t *__fastcall _goalRemainingCounter::_getDeclPtr(_goalRemainingCounter *this)
{
  return `_goalRemainingCounter::_getDeclPtr'::`2'::varInfo;
}


// ========================================================================
// ?Init@?$ssObject@V_goalKillCounter@@@@UAAXXZ
// EA  : 0x82EED328
// RVA : 0x00EED328
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void __fastcall ssObject<_goalKillCounter>::Init(ssObject<_goalKillCounter> *this)
{
  idSSObject *v1; // r3
  void (__fastcall ***v2)(_DWORD); // r3

  v1 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v2 = (void (__fastcall ***)(_DWORD))_RTDynamicCast(
                                        inptr: v1,
                                        VfDelta: 0,
                                        SrcType: &idSSObject `RTTI Type Descriptor',
                                        TargetType: &_goalKillCounter `RTTI Type Descriptor',
                                        isReference: 0);
  if ( v2 != nullptr )
    (**v2)(a1: v2);
  else
    AssertionFailed(msg: "Assertion failed: 0");
}


// ========================================================================
// ?DebugDrawStatus@?$ssObject@V_goalKillCounter@@@@UAAXXZ
// EA  : 0x82EED3B8
// RVA : 0x00EED3B8
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void __fastcall ssObject<_goalKillCounter>::DebugDrawStatus(ssObject<_goalKillCounter> *this)
{
  idSSObject *v1; // r3
  void *v2; // r3

  v1 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v2 = _RTDynamicCast(
         inptr: v1,
         VfDelta: 0,
         SrcType: &idSSObject `RTTI Type Descriptor',
         TargetType: &_goalKillCounter `RTTI Type Descriptor',
         isReference: 0);
  if ( v2 != nullptr )
    (*(void (__fastcall **)(void *))(*(_DWORD *)v2 + 208))(a1: v2);
  else
    AssertionFailed(msg: "Assertion failed: 0");
}


// ========================================================================
// ?Init@?$ssObject@V_goalRemainingCounter@@@@UAAXXZ
// EA  : 0x82EED448
// RVA : 0x00EED448
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void __fastcall ssObject<_goalRemainingCounter>::Init(ssObject<_goalRemainingCounter> *this)
{
  idSSObject *v1; // r3
  void (__fastcall ***v2)(_DWORD); // r3

  v1 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v2 = (void (__fastcall ***)(_DWORD))_RTDynamicCast(
                                        inptr: v1,
                                        VfDelta: 0,
                                        SrcType: &idSSObject `RTTI Type Descriptor',
                                        TargetType: &_goalRemainingCounter `RTTI Type Descriptor',
                                        isReference: 0);
  if ( v2 != nullptr )
    (**v2)(a1: v2);
  else
    AssertionFailed(msg: "Assertion failed: 0");
}


// ========================================================================
// ?DebugDrawStatus@?$ssObject@V_goalRemainingCounter@@@@UAAXXZ
// EA  : 0x82EED4D8
// RVA : 0x00EED4D8
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void __fastcall ssObject<_goalRemainingCounter>::DebugDrawStatus(ssObject<_goalRemainingCounter> *this)
{
  idSSObject *v1; // r3
  void *v2; // r3

  v1 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v2 = _RTDynamicCast(
         inptr: v1,
         VfDelta: 0,
         SrcType: &idSSObject `RTTI Type Descriptor',
         TargetType: &_goalRemainingCounter `RTTI Type Descriptor',
         isReference: 0);
  if ( v2 != nullptr )
    (*(void (__fastcall **)(void *))(*(_DWORD *)v2 + 208))(a1: v2);
  else
    AssertionFailed(msg: "Assertion failed: 0");
}


// ========================================================================
// ?SetManager@?$ssObject@V_goalRemainingCountActor@@@@QAAXVssEntity@@@Z
// EA  : 0x82EED568
// RVA : 0x00EED568
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void __fastcall ssObject<_goalRemainingCountActor>::SetManager(
        ssObject<_goalRemainingCountActor> *this,
        ssEntity *manager_)
{
  idSSObject *v3; // r3
  ssEntity *v4; // r31
  const ssEntity *v5; // r3
  ssEntity v6; // [sp+50h] [-20h] BYREF

  v3 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v4 = (ssEntity *)_RTDynamicCast(
                     inptr: v3,
                     VfDelta: 0,
                     SrcType: &idSSObject `RTTI Type Descriptor',
                     TargetType: &_goalRemainingCountActor `RTTI Type Descriptor',
                     isReference: 0);
  if ( v4 != nullptr )
  {
    ssEntity::ssEntity(this: &v6, e: manager_);
    ssEntity::ssEntity(this: v4 + 2, e: v5);
  }
  else
  {
    AssertionFailed(msg: "Assertion failed: 0");
  }
}


// ========================================================================
// ?SetManager@?$ssObject@V_goalKillCountActor@@@@QAAXVssEntity@@@Z
// EA  : 0x82EED608
// RVA : 0x00EED608
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void __fastcall ssObject<_goalKillCountActor>::SetManager(ssObject<_goalKillCountActor> *this, ssEntity *manager_)
{
  idSSObject *v3; // r3
  ssEntity *v4; // r31
  const ssEntity *v5; // r3
  ssEntity v6; // [sp+50h] [-20h] BYREF

  v3 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v4 = (ssEntity *)_RTDynamicCast(
                     inptr: v3,
                     VfDelta: 0,
                     SrcType: &idSSObject `RTTI Type Descriptor',
                     TargetType: &_goalKillCountActor `RTTI Type Descriptor',
                     isReference: 0);
  if ( v4 != nullptr )
  {
    ssEntity::ssEntity(this: &v6, e: manager_);
    ssEntity::ssEntity(this: v4 + 2, e: v5);
  }
  else
  {
    AssertionFailed(msg: "Assertion failed: 0");
  }
}


// ========================================================================
// ?CountActorDeath@?$ssObject@V_goalKillCounter@@@@QAAXVssEntity@@@Z
// EA  : 0x82EEDD20
// RVA : 0x00EEDD20
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void __fastcall ssObject<_goalKillCounter>::CountActorDeath(ssObject<_goalKillCounter> *this, ssEntity *deadActor)
{
  idSSObject *v3; // r3
  _combatGoal *v4; // r31
  int v5; // r10
  int v6; // r11
  ssEntity v7; // [sp+50h] [-20h] BYREF

  v3 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v4 = (_combatGoal *)_RTDynamicCast(
                        inptr: v3,
                        VfDelta: 0,
                        SrcType: &idSSObject `RTTI Type Descriptor',
                        TargetType: &_goalKillCounter `RTTI Type Descriptor',
                        isReference: 0);
  if ( v4 != nullptr )
  {
    ssEntity::ssEntity(this: &v7, e: deadActor);
    v5 = (int)v4[1].__vftable;
    v6 = *(_DWORD *)&v4[2].bTriggerFirst + 1;
    *(_DWORD *)&v4[2].bTriggerFirst = v6;
    if ( v6 >= v5 )
      _combatGoal::Complete(this: v4);
  }
  else
  {
    AssertionFailed(msg: "Assertion failed: 0");
  }
}


// ========================================================================
// ?CountActorDeath@?$ssObject@V_goalRemainingCounter@@@@QAAXVssEntity@@@Z
// EA  : 0x82EEDDD8
// RVA : 0x00EEDDD8
// PDB : w:\tech5\tungsten\superscript\generated\util\combatgoal.h
// ========================================================================

void __fastcall ssObject<_goalRemainingCounter>::CountActorDeath(
        ssObject<_goalRemainingCounter> *this,
        ssEntity *deadActor)
{
  idSSObject *v3; // r3
  _combatGoal *v4; // r31
  _combatGoal_vtbl *v5; // r10
  int v6; // r11
  ssEntity v7; // [sp+50h] [-20h] BYREF

  v3 = gameInterface->GetScriptObject(this: gameInterface, a2: this->spawnId, a3: this->objectId);
  v4 = (_combatGoal *)_RTDynamicCast(
                        inptr: v3,
                        VfDelta: 0,
                        SrcType: &idSSObject `RTTI Type Descriptor',
                        TargetType: &_goalRemainingCounter `RTTI Type Descriptor',
                        isReference: 0);
  if ( v4 != nullptr )
  {
    ssEntity::ssEntity(this: &v7, e: deadActor);
    v5 = v4[1].__vftable;
    v6 = (int)&v4[2].__vftable[-1].DebugDrawStatus + 3;
    v4[2].__vftable = (_combatGoal_vtbl *)v6;
    if ( v6 <= (int)v5 )
      _combatGoal::Complete(this: v4);
  }
  else
  {
    AssertionFailed(msg: "Assertion failed: 0");
  }
}

