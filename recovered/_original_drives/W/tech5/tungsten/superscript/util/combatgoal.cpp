
// ========================================================================
// ?Init@_combatGoal@@UAAXXZ
// EA  : 0x82EED6A8
// RVA : 0x00EED6A8
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void __fastcall _combatGoal::Init(_combatGoal *this)
{
  ssUtil::Init(this: &ssUtil);
  this->state = !this->bTriggerFirst;
}


// ========================================================================
// ?Complete@_combatGoal@@QAAXXZ
// EA  : 0x82EED6F8
// RVA : 0x00EED6F8
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void __fastcall _combatGoal::Complete(_combatGoal *this)
{
  double delay; // fp1
  ssEntity *p_self; // r31
  ssEntity *v4; // r3
  ssEntity v5; // [sp+50h] [-20h] BYREF

  if ( this->state == COMBAT_GOAL_READY )
  {
    delay = this->delay;
    this->state = COMBAT_GOAL_SUCCESS;
    if ( delay > 0.0 )
      ((void (__fastcall *)(idGameSuperInterface *))gameInterface->Wait)(a1: gameInterface);
    p_self = &this->self;
    ssEntity::ssEntity(this: &v5, e: p_self);
    ssEntity::ActivateTargets(this: p_self, activator: v4);
  }
}


// ========================================================================
// ?OnActivate@_combatGoal@@MAAXVssEntity@@@Z
// EA  : 0x82EED780
// RVA : 0x00EED780
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void __fastcall _combatGoal::OnActivate(_combatGoal *this, ssEntity *__formal)
{
  if ( this->state == COMBAT_GOAL_WAITING )
    this->state = COMBAT_GOAL_READY;
}


// ========================================================================
// ?DebugDrawStatus@_goalKillCounter@@UAAXXZ
// EA  : 0x82EED7A0
// RVA : 0x00EED7A0
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void __fastcall _goalKillCounter::DebugDrawStatus(_goalKillCounter *this)
{
  int v2; // r3
  _combatGoal::state_t state; // r11
  double v4; // fp30
  const ssString *v5; // r3
  ssString *v6; // r3
  const ssString *v7; // r3
  ssString *v8; // r3
  char *v9; // r4
  ssEntity *WorldOrigin; // r3
  unsigned __int64 v11; // [sp+60h] [-A0h] BYREF
  float v12[4]; // [sp+70h] [-90h] BYREF
  ssString v13; // [sp+80h] [-80h] BYREF
  ssString v14; // [sp+90h] [-70h] BYREF
  ssString v15; // [sp+A0h] [-60h] BYREF
  ssString v16; // [sp+B0h] [-50h] BYREF
  ssString v17; // [sp+C0h] [-40h] BYREF

  ssString::Init(this: &v13);
  v2 = gameInterface->GetFrameTime(this: gameInterface);
  state = this->state;
  v11 = __PAIR64__(&off_82040000, v2);
  v4 = (float)((float)__SPAIR64__(&off_82040000, v2) * (float)0.001);
  if ( (unsigned int)state <= COMBAT_GOAL_FAILURE )
  {
    if ( state != COMBAT_GOAL_READY )
    {
      if ( state == COMBAT_GOAL_SUCCESS )
      {
        v9 = "Complete - SUCCESS";
      }
      else
      {
        if ( state == COMBAT_GOAL_WAITING )
        {
          ssString::ssString(this: &v15, i: this->nCount);
          v6 = operator+(result: &v14, a: "Waiting - Count: ", b: v5);
          ssString::operator=(this: &v13, text: v6);
          ssString::Empty(this: &v14);
          ssString::Empty(this: &v15);
          goto LABEL_10;
        }
        v9 = "Complete - FAILURE";
      }
      ssString::operator=(this: &v13, text: v9);
      goto LABEL_10;
    }
    ssString::ssString(this: &v17, i: this->nCount);
    v8 = operator+(result: &v16, a: "Running - Count: ", b: v7);
    ssString::operator=(this: &v13, text: v8);
    ssString::Empty(this: &v16);
    ssString::Empty(this: &v17);
  }
LABEL_10:
  v12[0] = 0.5;
  v12[1] = 0.5;
  v12[2] = 1.0;
  WorldOrigin = ssEntity::GetWorldOrigin(this: (ssEntity *)&v11, result: (ssString *)&this->self);
  ((void (__fastcall *)(idGameSuperInterface *, char *, float *, ssEntity *, double, double))gameInterface->DebugText)(
    a1: gameInterface,
    a2: v13.data,
    a3: v12,
    a4: WorldOrigin,
    a5: 0.5,
    a6: v4);
  ssString::Empty(this: &v13);
}


// ========================================================================
// __unwind$19593
// EA  : 0x82EED930
// RVA : 0x00EED930
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19593()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$19594
// EA  : 0x82EED958
// RVA : 0x00EED958
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19594()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 160));
}


// ========================================================================
// __unwind$19595
// EA  : 0x82EED980
// RVA : 0x00EED980
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19595()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 144));
}


// ========================================================================
// __unwind$19596
// EA  : 0x82EED9A8
// RVA : 0x00EED9A8
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19596()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 192));
}


// ========================================================================
// __unwind$19597
// EA  : 0x82EED9D0
// RVA : 0x00EED9D0
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19597()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 176));
}


// ========================================================================
// ?DebugDrawStatus@_goalRemainingCounter@@UAAXXZ
// EA  : 0x82EEDA00
// RVA : 0x00EEDA00
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void __fastcall _goalRemainingCounter::DebugDrawStatus(_goalRemainingCounter *this)
{
  int v2; // r3
  _combatGoal::state_t state; // r11
  double v4; // fp30
  const ssString *v5; // r3
  ssString *v6; // r3
  const ssString *v7; // r3
  const ssString *v8; // r28
  const ssString *v9; // r3
  ssString *v10; // r3
  const ssString *v11; // r3
  const ssString *v12; // r3
  char *v13; // r4
  ssEntity *WorldOrigin; // r3
  ssString v15; // [sp+60h] [-E0h] BYREF
  float v16[4]; // [sp+70h] [-D0h] BYREF
  unsigned __int64 v17; // [sp+80h] [-C0h] BYREF
  ssString v18; // [sp+90h] [-B0h] BYREF
  ssString v19; // [sp+A0h] [-A0h] BYREF
  ssString v20; // [sp+B0h] [-90h] BYREF
  ssString v21; // [sp+C0h] [-80h] BYREF
  ssString v22; // [sp+D0h] [-70h] BYREF
  ssString v23; // [sp+E0h] [-60h] BYREF
  ssString v24; // [sp+F0h] [-50h] BYREF

  ssString::Init(this: &v15);
  v2 = gameInterface->GetFrameTime(this: gameInterface);
  state = this->state;
  v17 = __PAIR64__(&off_82040000, v2);
  v4 = (float)((float)__SPAIR64__(&off_82040000, v2) * (float)0.001);
  if ( (unsigned int)state <= COMBAT_GOAL_FAILURE )
  {
    if ( state != COMBAT_GOAL_READY )
    {
      if ( state == COMBAT_GOAL_SUCCESS )
      {
        v13 = "Complete - SUCCESS";
      }
      else
      {
        if ( state == COMBAT_GOAL_WAITING )
        {
          ssString::ssString(this: &v18, i: this->nCount);
          v6 = operator+(result: &v23, a: "Waiting - Count: ", b: v5);
          ssString::operator=(this: &v15, text: v6);
          ssString::Empty(this: &v23);
          ssString::Empty(this: &v18);
          goto LABEL_10;
        }
        v13 = "Complete - FAILURE";
      }
      ssString::operator=(this: &v15, text: v13);
      goto LABEL_10;
    }
    ssString::ssString(this: &v24, i: this->nCount);
    v8 = v7;
    ssString::ssString(this: &v22, i: this->numRemaining);
    v10 = operator+(result: &v20, a: "Running - Remaining: ", b: v9);
    v11 = operator+(result: &v19, a: v10, b: ", Count: ");
    v12 = operator+(result: &v21, a: v11, b: v8);
    ssString::operator=(this: &v15, text: v12);
    ssString::Empty(this: &v21);
    ssString::Empty(this: &v19);
    ssString::Empty(this: &v20);
    ssString::Empty(this: &v22);
    ssString::Empty(this: &v24);
  }
LABEL_10:
  v16[0] = 0.5;
  v16[1] = 0.5;
  v16[2] = 1.0;
  WorldOrigin = ssEntity::GetWorldOrigin(this: (ssEntity *)&v17, result: (ssString *)&this->self);
  ((void (__fastcall *)(idGameSuperInterface *, char *, float *, ssEntity *, double, double))gameInterface->DebugText)(
    a1: gameInterface,
    a2: v15.data,
    a3: v16,
    a4: WorldOrigin,
    a5: 0.5,
    a6: v4);
  ssString::Empty(this: &v15);
}


// ========================================================================
// __unwind$19701
// EA  : 0x82EEDBDC
// RVA : 0x00EEDBDC
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19701()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$19702
// EA  : 0x82EEDC04
// RVA : 0x00EEDC04
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19702()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 144));
}


// ========================================================================
// __unwind$19703
// EA  : 0x82EEDC2C
// RVA : 0x00EEDC2C
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19703()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 224));
}


// ========================================================================
// __unwind$19704
// EA  : 0x82EEDC54
// RVA : 0x00EEDC54
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19704()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 240));
}


// ========================================================================
// __unwind$19705
// EA  : 0x82EEDC7C
// RVA : 0x00EEDC7C
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19705()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 208));
}


// ========================================================================
// __unwind$19706
// EA  : 0x82EEDCA4
// RVA : 0x00EEDCA4
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19706()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 176));
}


// ========================================================================
// __unwind$19707
// EA  : 0x82EEDCCC
// RVA : 0x00EEDCCC
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19707()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 160));
}


// ========================================================================
// __unwind$19708
// EA  : 0x82EEDCF4
// RVA : 0x00EEDCF4
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19708()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 320 + 192));
}


// ========================================================================
// ?InitWatchActors@_goalKillCounter@@QAAXXZ
// EA  : 0x82EEDE98
// RVA : 0x00EEDE98
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void __fastcall _goalKillCounter::InitWatchActors(_goalKillCounter *this)
{
  int v2; // r23
  int v3; // r27
  int spawnId; // r30
  idGameSuperInterface_vtbl *v5; // r10
  int *v6; // r3
  void *v7; // r3
  ssEntity *v8; // r3
  ssEntity v9; // [sp+50h] [-80h] BYREF
  ssEntity v10; // [sp+54h] [-7Ch] BYREF
  ssObject<_goalKillCountActor> v11; // [sp+58h] [-78h] BYREF
  ssString v12[7]; // [sp+60h] [-70h] BYREF

  v2 = 0;
  if ( this->actorList.num > 0 )
  {
    v3 = 0;
    do
    {
      if ( v2 < 0 || v2 >= this->actorList.num )
      {
        ssString::Init(this: v12);
        ssString::operator=(this: v12, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
        Error(msg: v12);
        ssString::Empty(this: v12);
      }
      ssEntity::ssEntity(this: &v9, e: &this->actorList.data[v3]);
      v5 = gameInterface->__vftable;
      v11.spawnId = *v6;
      spawnId = v11.spawnId;
      v11.objectId = ((int (*)(void))v5->FindObject)();
      v7 = (void *)((int (__fastcall *)(idGameSuperInterface *, int))gameInterface->GetScriptObject)(
                     a1: gameInterface,
                     a2: spawnId);
      if ( _RTDynamicCast(
             inptr: v7,
             VfDelta: 0,
             SrcType: &idSSObject `RTTI Type Descriptor',
             TargetType: &idSuperScriptObject `RTTI Type Descriptor',
             isReference: 0) != nullptr )
      {
        ssEntity::ssEntity(this: &v10, e: &this->self);
        ssObject<_goalKillCountActor>::SetManager(this: &v11, manager_: v8);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->actorList.num );
  }
}


// ========================================================================
// __unwind$19884
// EA  : 0x82EEDFC8
// RVA : 0x00EEDFC8
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19884()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 208 + 96));
}


// ========================================================================
// ?OnActivate@_goalKillCounter@@UAAXVssEntity@@@Z
// EA  : 0x82EEDFF0
// RVA : 0x00EEDFF0
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void __fastcall _goalKillCounter::OnActivate(_goalKillCounter *this, ssEntity *__formal)
{
  if ( this->state == COMBAT_GOAL_WAITING )
  {
    this->state = COMBAT_GOAL_READY;
    _goalKillCounter::InitWatchActors(this);
  }
}


// ========================================================================
// ?InitWatchActors@_goalRemainingCounter@@QAAXXZ
// EA  : 0x82EEE018
// RVA : 0x00EEE018
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void __fastcall _goalRemainingCounter::InitWatchActors(_goalRemainingCounter *this)
{
  int v2; // r23
  int v3; // r27
  int spawnId; // r30
  idGameSuperInterface_vtbl *v5; // r10
  int *v6; // r3
  void *v7; // r3
  ssEntity *v8; // r3
  ssEntity v9; // [sp+50h] [-80h] BYREF
  ssEntity v10; // [sp+54h] [-7Ch] BYREF
  ssObject<_goalRemainingCountActor> v11; // [sp+58h] [-78h] BYREF
  ssString v12[7]; // [sp+60h] [-70h] BYREF

  v2 = 0;
  if ( this->actorList.num > 0 )
  {
    v3 = 0;
    do
    {
      if ( v2 < 0 || v2 >= this->actorList.num )
      {
        ssString::Init(this: v12);
        ssString::operator=(this: v12, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
        Error(msg: v12);
        ssString::Empty(this: v12);
      }
      ssEntity::ssEntity(this: &v9, e: &this->actorList.data[v3]);
      v5 = gameInterface->__vftable;
      v11.spawnId = *v6;
      spawnId = v11.spawnId;
      v11.objectId = ((int (*)(void))v5->FindObject)();
      v7 = (void *)((int (__fastcall *)(idGameSuperInterface *, int))gameInterface->GetScriptObject)(
                     a1: gameInterface,
                     a2: spawnId);
      if ( _RTDynamicCast(
             inptr: v7,
             VfDelta: 0,
             SrcType: &idSSObject `RTTI Type Descriptor',
             TargetType: &idSuperScriptObject `RTTI Type Descriptor',
             isReference: 0) != nullptr )
      {
        ssEntity::ssEntity(this: &v10, e: &this->self);
        ssObject<_goalRemainingCountActor>::SetManager(this: &v11, manager_: v8);
        ++this->numRemaining;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->actorList.num );
  }
}


// ========================================================================
// __unwind$19968
// EA  : 0x82EEE154
// RVA : 0x00EEE154
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void _unwind_19968()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 208 + 96));
}


// ========================================================================
// ?OnDeath@_goalKillCountActor@@UAAXVssEntity@@@Z
// EA  : 0x82EEE180
// RVA : 0x00EEE180
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void __fastcall _goalKillCountActor::OnDeath(_goalKillCountActor *this, ssEntity *__formal)
{
  int *v3; // r3
  ssEntity *v4; // r3
  ssEntity v5[2]; // [sp+50h] [-30h] BYREF
  ssObject<_goalKillCounter> v6; // [sp+58h] [-28h] BYREF

  ssEntity::ssEntity(this: v5, e: &this->manager);
  v6.spawnId = *v3;
  v6.__vftable = (ssObject<_goalKillCounter>_vtbl *)&ssObject<_goalKillCounter>::`vftable';
  v6.objectId = gameInterface->FindObject(this: gameInterface, a2: v6.spawnId, a3: "_goalKillCounter", a4: false);
  ssEntity::ssEntity(this: v5, e: &this->self);
  ssObject<_goalKillCounter>::CountActorDeath(this: &v6, deadActor: v4);
}


// ========================================================================
// ?OnDeath@_goalRemainingCountActor@@UAAXVssEntity@@@Z
// EA  : 0x82EEE208
// RVA : 0x00EEE208
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void __fastcall _goalRemainingCountActor::OnDeath(_goalRemainingCountActor *this, ssEntity *__formal)
{
  int *v3; // r3
  ssEntity *v4; // r3
  ssEntity v5[2]; // [sp+50h] [-30h] BYREF
  ssObject<_goalRemainingCounter> v6; // [sp+58h] [-28h] BYREF

  ssEntity::ssEntity(this: v5, e: &this->manager);
  v6.spawnId = *v3;
  v6.__vftable = (ssObject<_goalRemainingCounter>_vtbl *)&ssObject<_goalRemainingCounter>::`vftable';
  v6.objectId = gameInterface->FindObject(this: gameInterface, a2: v6.spawnId, a3: "_goalRemainingCounter", a4: false);
  ssEntity::ssEntity(this: v5, e: &this->self);
  ssObject<_goalRemainingCounter>::CountActorDeath(this: &v6, deadActor: v4);
}


// ========================================================================
// ?Init@_goalRemainingCounter@@UAAXXZ
// EA  : 0x82EEE290
// RVA : 0x00EEE290
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void __fastcall _goalRemainingCounter::Init(_goalRemainingCounter *this)
{
  BOOL bTriggerFirst; // r10
  int nCount; // r8

  ssUtil::Init(this: &ssUtil);
  bTriggerFirst = this->bTriggerFirst;
  this->state = !this->bTriggerFirst;
  nCount = this->nCount;
  this->numRemaining = 0;
  if ( nCount < 0 )
    this->nCount = 0;
  if ( bTriggerFirst )
  {
    this->state = COMBAT_GOAL_WAITING;
  }
  else
  {
    this->state = COMBAT_GOAL_READY;
    _goalRemainingCounter::InitWatchActors(this);
  }
}


// ========================================================================
// ?OnActivate@_goalRemainingCounter@@UAAXVssEntity@@@Z
// EA  : 0x82EEE328
// RVA : 0x00EEE328
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void __fastcall _goalRemainingCounter::OnActivate(_goalRemainingCounter *this, ssEntity *activator)
{
  if ( this->state == COMBAT_GOAL_WAITING )
  {
    this->state = COMBAT_GOAL_READY;
    _goalRemainingCounter::InitWatchActors(this);
  }
}


// ========================================================================
// ?Init@_goalKillCounter@@UAAXXZ
// EA  : 0x82EEE348
// RVA : 0x00EEE348
// PDB : w:\tech5\tungsten\superscript\util\combatgoal.cpp
// ========================================================================

void __fastcall _goalKillCounter::Init(_goalKillCounter *this)
{
  BOOL bTriggerFirst; // r11

  ssUtil::Init(this: &ssUtil);
  bTriggerFirst = this->bTriggerFirst;
  this->state = !this->bTriggerFirst;
  if ( this->nCount < 1 )
    this->nCount = 1;
  if ( this->fPlayerContributionThreshold < 0.0 )
    this->fPlayerContributionThreshold = 0.0;
  if ( this->fPlayerContributionThreshold > 1.0 )
    this->fPlayerContributionThreshold = 1.0;
  this->killCount = 0;
  if ( bTriggerFirst )
  {
    this->state = COMBAT_GOAL_WAITING;
  }
  else
  {
    this->state = COMBAT_GOAL_READY;
    _goalKillCounter::InitWatchActors(this);
  }
}

