
// ========================================================================
// ?Init@util_triggerVisibility@@UAAXXZ
// EA  : 0x82EF2C68
// RVA : 0x00EF2C68
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void __fastcall util_triggerVisibility::Init(util_triggerVisibility *this)
{
  ssEntity *v2; // r3
  util_triggerVisibility_vtbl *v3; // r28
  ssEntity *v4; // r3
  ssEntity v5[4]; // [sp+50h] [-50h] BYREF
  ssString v6[4]; // [sp+60h] [-40h] BYREF

  ssString::Init(this: v6);
  ssString::operator=(this: v6, text: "PlayerSawTrigger");
  ssEntity::ssEntity(this: v5, e: &this->self);
  ssUtil::DefineFlag(ent: v2, name: v6);
  ssString::Empty(this: v6);
  if ( this->active )
  {
    v3 = this->__vftable;
    this->active = false;
    ssEntity::ssEntity(this: v5, e: &this->self);
    v3->OnActivate(this, a2: v4);
  }
}


// ========================================================================
// __unwind$19898
// EA  : 0x82EF2CF4
// RVA : 0x00EF2CF4
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_19898()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?Think@util_triggerVisibility@@QAAXXZ
// EA  : 0x82EF2D28
// RVA : 0x00EF2D28
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void __fastcall util_triggerVisibility::Think(util_triggerVisibility *this)
{
  ssEntity *p_self; // r28
  double v3; // fp30
  bool v4; // r29
  ssString *v5; // r3
  ssEntity *v6; // r3
  ssEntity *p_triggerOnHidden; // r29
  int v8; // r9
  char v9; // r11
  ssEntity *v10; // r3
  double tolerance; // fp30
  bool testLOS; // r29
  ssString *v13; // r3
  int v14; // r9
  char v15; // r11
  ssEntity *v16; // r3
  ssObject<ssWorldUtil> v17; // [sp+50h] [-90h] BYREF
  ssEntity v18; // [sp+58h] [-88h] BYREF
  ssEntity v19; // [sp+5Ch] [-84h] BYREF
  int v20; // [sp+60h] [-80h] BYREF
  ssEntity v21; // [sp+64h] [-7Ch] BYREF
  int v22; // [sp+68h] [-78h] BYREF
  ssString v23; // [sp+70h] [-70h] BYREF

  if ( !this->active )
  {
    this->active = true;
    do
    {
      if ( this->visible
        || (ssObject<ssWorldUtil>::GetPlayer1(this: &v17, result: (ssEntity *)&worldUtil),
            p_self = &this->self,
            v3 = this->tolerance,
            v4 = this->testLOS,
            ssEntity::ssEntity(this: &v18, e: &this->self),
            (unsigned __int8)ssUtil::IsPlayerLookingAtEntity(
                               player: (ssEntity *)&v17,
                               ent: v5,
                               testLOS: v4,
                               tolerance: v3) == 0) )
      {
        if ( !this->visible )
          goto LABEL_18;
        ssObject<ssWorldUtil>::GetPlayer1(this: (ssObject<ssWorldUtil> *)&v17.objectId, result: (ssEntity *)&worldUtil);
        p_self = &this->self;
        tolerance = this->tolerance;
        testLOS = this->testLOS;
        ssEntity::ssEntity(this: &v21, e: &this->self);
        if ( (unsigned __int8)ssUtil::IsPlayerLookingAtEntity(
                                player: (ssEntity *)&v17.objectId,
                                ent: v13,
                                testLOS,
                                tolerance) != 0 )
          goto LABEL_18;
        this->visible = false;
        p_triggerOnHidden = &this->triggerOnHidden;
        if ( this->triggerOnHidden.spawnId == 0
          || (v14 = ((unsigned __int8 (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
              v15 = 1,
              v14 == 0) )
        {
          v15 = 0;
        }
        if ( v15 == 0 )
          goto LABEL_18;
        v10 = (ssEntity *)&v22;
      }
      else
      {
        this->visible = true;
        ssString::Init(this: &v23);
        ssString::operator=(this: &v23, text: "PlayerSawTrigger");
        ssEntity::ssEntity(this: &v19, e: &this->self);
        ssUtil::SetFlag(ent: v6, name: &v23, delay: 0.0);
        ssString::Empty(this: &v23);
        p_triggerOnHidden = &this->triggerOnVisible;
        if ( this->triggerOnVisible.spawnId == 0
          || (v8 = ((unsigned __int8 (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
              v9 = 1,
              v8 == 0) )
        {
          v9 = 0;
        }
        if ( v9 == 0 )
          goto LABEL_18;
        v10 = (ssEntity *)&v20;
      }
      ssEntity::ssEntity(this: v10, e: p_self);
      ssEntity::Activate(this: p_triggerOnHidden, activator: v16);
LABEL_18:
      gameInterface->Wait(this: gameInterface, a2: this->testFrequency);
    }
    while ( this->active );
  }
}


// ========================================================================
// __unwind$19949_0
// EA  : 0x82EF2F30
// RVA : 0x00EF2F30
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_19949_0()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 112));
}


// ========================================================================
// ?OnActivate@util_triggerLookAt@@UAAXVssEntity@@@Z
// EA  : 0x82EF2F60
// RVA : 0x00EF2F60
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void __fastcall util_triggerLookAt::OnActivate(util_triggerLookAt *this, ssEntity *activator)
{
  __int64 v4; // r9
  double v5; // fp31
  double v6; // fp28
  double v7; // fp27
  bool v8; // r29
  ssString *v9; // r3
  double tolerance; // fp27
  bool testLOS; // r29
  ssString *v12; // r3
  __int64 v13; // r9
  double lookTime; // fp0
  __int64 v15; // r9
  ssEntity *v16; // r3
  ssEntity *v17; // r3
  ssObject<ssWorldUtil> v18; // [sp+50h] [-B0h] BYREF
  ssObject<ssWorldUtil> v19; // [sp+58h] [-A8h] BYREF
  _QWORD v20[4]; // [sp+60h] [-A0h] BYREF
  ssString v21[4]; // [sp+80h] [-80h] BYREF

  if ( this->active || this->triggerOnce && this->triggered )
    return;
  this->active = true;
  LODWORD(v4) = gameInterface->GetTime(this: gameInterface);
  v20[0] = v4;
  v5 = 0.0;
  v6 = (float)(this->activePeriod + (float)((float)v4 * (float)0.001));
  if ( !this->active )
    goto LABEL_20;
  while ( 1 )
  {
    if ( !this->safetyTriggerHit )
    {
      if ( this->inverse
        || (ssObject<ssWorldUtil>::GetPlayer1(this: &v18, result: (ssEntity *)&worldUtil),
            v7 = this->tolerance,
            v8 = this->testLOS,
            ssEntity::ssEntity(this: (ssEntity *)&v19.objectId, e: &this->self),
            (unsigned __int8)ssUtil::IsPlayerLookingAtEntity(
                               player: (ssEntity *)&v18,
                               ent: v9,
                               testLOS: v8,
                               tolerance: v7) == 0) )
      {
        if ( !this->inverse
          || (ssObject<ssWorldUtil>::GetPlayer1(
                this: (ssObject<ssWorldUtil> *)&v18.objectId,
                result: (ssEntity *)&worldUtil),
              tolerance = this->tolerance,
              testLOS = this->testLOS,
              ssEntity::ssEntity(this: (ssEntity *)v20, e: &this->self),
              (unsigned __int8)ssUtil::IsPlayerLookingAtEntity(
                                 player: (ssEntity *)&v18.objectId,
                                 ent: v12,
                                 testLOS,
                                 tolerance) != 0) )
        {
          v5 = 0.0;
          goto LABEL_13;
        }
      }
    }
    LODWORD(v13) = gameInterface->GetFrameTime(this: gameInterface);
    lookTime = this->lookTime;
    v20[1] = v13;
    v5 = (float)((float)((float)v13 * (float)0.001) + (float)v5);
    if ( lookTime == 0.0 || v5 >= lookTime )
      break;
LABEL_13:
    if ( this->activePeriod < 0.0
      || (LODWORD(v15) = gameInterface->GetTime(this: gameInterface),
          v20[2] = v15,
          (float)((float)v15 * (float)0.001) <= v6) )
    {
      gameInterface->WaitFrame(this: gameInterface);
      if ( this->active )
        continue;
    }
    goto LABEL_20;
  }
  gameInterface->Wait(this: gameInterface, a2: this->delay);
  ssString::Init(this: v21);
  ssString::operator=(this: v21, text: "PlayerSawTrigger");
  ssEntity::ssEntity(this: (ssEntity *)v20, e: &this->self);
  ssUtil::SetFlag(ent: v16, name: v21, delay: 0.0);
  ssString::Empty(this: v21);
  ssEntity::ssEntity(this: (ssEntity *)v20, e: activator);
  ssEntity::ActivateTargets(this: &this->self, activator: v17);
  if ( this->call.len > 0 )
  {
    ssObject<ssWorldUtil>::GetWorld(this: &v19, result: (ssEntity *)&worldUtil);
    gameInterface->CreateNamedThread(this: gameInterface, a2: v19.spawnId, a3: this->call.data);
  }
  this->triggered = true;
LABEL_20:
  this->active = false;
}


// ========================================================================
// __unwind$20022
// EA  : 0x82EF3218
// RVA : 0x00EF3218
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_20022()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 128));
}


// ========================================================================
// ?OnActivate@util_triggerVisibility@@UAAXVssEntity@@@Z
// EA  : 0x82EF34E8
// RVA : 0x00EF34E8
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void __fastcall util_triggerVisibility::OnActivate(util_triggerVisibility *this, ssEntity *activator)
{
  ssString v3; // [sp+50h] [-20h] BYREF

  if ( this->active )
  {
    this->active = false;
  }
  else
  {
    ssString::Init(this: &v3);
    ssString::operator=(this: &v3, text: "Think");
    idSuperScriptObject::CreateThreadNamed(this, threadName: &v3, f: util_triggerVisibility::Think);
  }
}


// ========================================================================
// ?Init@util_triggerLookAt@@UAAXXZ
// EA  : 0x82EF3570
// RVA : 0x00EF3570
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void __fastcall util_triggerLookAt::Init(util_triggerLookAt *this)
{
  ssEntity *v2; // r3
  int v3; // r29
  int v4; // r27
  int v5; // r9
  char v6; // r11
  idGameSuperInterface_vtbl *v7; // r10
  int *v8; // r3
  ssEntity *v9; // r3
  util_triggerLookAt_vtbl *v10; // r29
  ssEntity *v11; // r3
  ssEntity v12; // [sp+50h] [-90h] BYREF
  ssEntity v13; // [sp+54h] [-8Ch] BYREF
  ssEntity v14[2]; // [sp+58h] [-88h] BYREF
  ssObject<util_triggerLookAtSafety> v15; // [sp+60h] [-80h] BYREF
  ssString v16; // [sp+70h] [-70h] BYREF
  ssString v17[6]; // [sp+80h] [-60h] BYREF

  ssUtil::Init(this: &ssUtil);
  ssString::Init(this: &v16);
  ssString::operator=(this: &v16, text: "PlayerSawTrigger");
  ssEntity::ssEntity(this: &v13, e: &this->self);
  ssUtil::DefineFlag(ent: v2, name: &v16);
  ssString::Empty(this: &v16);
  v3 = 0;
  if ( this->safetyTriggers.num > 0 )
  {
    v4 = 0;
    do
    {
      if ( v3 < 0 || v3 >= this->safetyTriggers.num )
      {
        ssString::Init(this: v17);
        ssString::operator=(this: v17, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
        Error(msg: v17);
        ssString::Empty(this: v17);
      }
      ssEntity::ssEntity(this: &v12, e: &this->safetyTriggers.data[v4]);
      if ( v12.spawnId == 0
        || (v5 = ((unsigned __int8 (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
            v6 = 1,
            v5 == 0) )
      {
        v6 = 0;
      }
      if ( v6 != 0 )
      {
        ssEntity::ssEntity(this: &v13, e: &v12);
        v7 = gameInterface->__vftable;
        v15.spawnId = *v8;
        v15.objectId = ((int (*)(void))v7->FindObject)();
        ssEntity::ssEntity(this: v14, e: &this->self);
        ssObject<util_triggerLookAtSafety>::SetLookAtEntity(this: &v15, ent: v9);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->safetyTriggers.num );
  }
  if ( this->active )
  {
    gameInterface->WaitFrame(this: gameInterface);
    this->active = false;
    v10 = this->__vftable;
    ssEntity::ssEntity(this: v14, e: &this->self);
    v10->OnActivate(this, a2: v11);
  }
}


// ========================================================================
// __unwind$20350
// EA  : 0x82EF3730
// RVA : 0x00EF3730
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_20350()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 112));
}


// ========================================================================
// __unwind$20364
// EA  : 0x82EF3758
// RVA : 0x00EF3758
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_20364()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 128));
}


// ========================================================================
// ?OnActivate@util_distanceTrigger@@UAAXVssEntity@@@Z
// EA  : 0x82EF3788
// RVA : 0x00EF3788
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void __fastcall util_distanceTrigger::OnActivate(util_distanceTrigger *this, ssEntity *__formal)
{
  int v3; // r29
  ssEntity *p_self; // r26
  int v5; // r27
  double ramp; // fp0
  ssEntity *v7; // r28
  ssEntity *v8; // r3
  ssEntity v9; // [sp+50h] [-90h] BYREF
  ssString v10; // [sp+60h] [-80h] BYREF
  ssString v11; // [sp+70h] [-70h] BYREF
  ssString v12[6]; // [sp+80h] [-60h] BYREF

  v3 = 0;
  if ( this->targets.num > 0 )
  {
    p_self = &this->self;
    v5 = 0;
    do
    {
      while ( 1 )
      {
        if ( this->reverse )
          goto LABEL_20;
        if ( v3 < 0 || v3 >= this->distances.num )
        {
          ssString::Init(this: &v10);
          ssString::operator=(this: &v10, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
          Error(msg: &v10);
          ssString::Empty(this: &v10);
        }
        ramp = this->ramp;
        if ( ramp >= this->distances.data[v5] )
        {
LABEL_20:
          if ( !this->reverse )
            break;
          if ( v3 < 0 || v3 >= this->distances.num )
          {
            ssString::Init(this: &v11);
            ssString::operator=(this: &v11, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
            Error(msg: &v11);
            ssString::Empty(this: &v11);
          }
          ramp = this->ramp;
          if ( ramp <= this->distances.data[v5] )
            break;
        }
        this->ramp = this->frameSpeed + (float)ramp;
        gameInterface->WaitFrame(this: gameInterface);
      }
      if ( v3 < 0 || v3 >= this->targets.num )
      {
        ssString::Init(this: v12);
        ssString::operator=(this: v12, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
        Error(msg: v12);
        ssString::Empty(this: v12);
      }
      v7 = &this->targets.data[v5];
      ssEntity::ssEntity(this: &v9, e: p_self);
      ssEntity::Activate(this: v7, activator: v8);
      ++v3;
      ++v5;
    }
    while ( v3 < this->targets.num );
  }
}


// ========================================================================
// __unwind$20504
// EA  : 0x82EF3908
// RVA : 0x00EF3908
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_20504()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$20533_0
// EA  : 0x82EF3930
// RVA : 0x00EF3930
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_20533_0()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 112));
}


// ========================================================================
// __unwind$20565
// EA  : 0x82EF3958
// RVA : 0x00EF3958
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_20565()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 128));
}


// ========================================================================
// ?OnActivate@util_nodeModifierTrigger@@UAAXVssEntity@@@Z
// EA  : 0x82EF3A98
// RVA : 0x00EF3A98
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void __fastcall util_nodeModifierTrigger::OnActivate(util_nodeModifierTrigger *this, ssEntity *__formal)
{
  ssEntity v3; // [sp+50h] [-50h] BYREF
  ssList<float> v4; // [sp+60h] [-40h] BYREF
  ssString v5; // [sp+70h] [-30h] BYREF

  memset(&v4, 0, 12);
  if ( gameInterface != nullptr )
    v4.threadId = ((int (__fastcall *)(idGameSuperInterface *, ssEntity *))gameInterface->GetAllocThread)(
                    a1: gameInterface,
                    a2: __formal);
  else
    v4.threadId = 0;
  ssString::Init(this: &v5);
  ssString::operator=(this: &v5, text: "idDoomAction");
  ssEntity::ssEntity(this: &v3, e: &this->self);
  idCamera::InhibitButtons(this: (idCamera *)&v4);
  ssString::Empty(this: &v5);
  ssList<ssEntity>::Clear(this: &v4);
}


// ========================================================================
// __unwind$20753
// EA  : 0x82EF3B50
// RVA : 0x00EF3B50
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_20753()
{
  int v0; // r12

  ssList<util_debugMetaData::lineInfo_t>::~ssList<util_debugMetaData::lineInfo_t>(this: (ssList<int> *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$20754
// EA  : 0x82EF3B78
// RVA : 0x00EF3B78
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_20754()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 112));
}


// ========================================================================
// ?OnActivate@util_replaceTargets@@UAAXVssEntity@@@Z
// EA  : 0x82EF3BA8
// RVA : 0x00EF3BA8
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void __fastcall util_replaceTargets::OnActivate(util_replaceTargets *this, ssEntity *__formal)
{
  ssString *v3; // r3
  int num; // r11
  int v5; // r27
  int v6; // r25
  ssEntity *Target; // r3
  int v8; // r28
  int v9; // r29
  int v10; // r9
  char v11; // r11
  ssEntity *v12; // r3
  ssString v13; // [sp+50h] [-B0h] BYREF
  ssList<ssEntity> v14; // [sp+60h] [-A0h] BYREF
  ssString v15; // [sp+70h] [-90h] BYREF
  ssString v16; // [sp+80h] [-80h] BYREF
  ssString v17; // [sp+90h] [-70h] BYREF

  memset(&v14, 0, 12);
  if ( gameInterface != nullptr )
    v14.threadId = gameInterface->GetAllocThread(this: gameInterface);
  else
    v14.threadId = 0;
  ssEntity::ssEntity(this: (ssEntity *)&v13, e: &this->self);
  ssUtil::FillListFromTargets(dst: &v14, src: v3);
  num = v14.num;
  v5 = 0;
  if ( v14.num > 0 )
  {
    v6 = 0;
    do
    {
      if ( v5 < 0 || v5 >= num )
      {
        ssString::Init(this: &v15);
        ssString::operator=(this: &v15, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
        Error(msg: &v15);
        ssString::Empty(this: &v15);
      }
      ssEntity::ssEntity(this: (ssEntity *)&v13, e: &v14.data[v6]);
      while ( ssEntity::NumTargets(this: (ssEntity *)&v13) > 0.0 )
      {
        Target = ssEntity::GetTarget(this: (ssEntity *)&v13.data, result: &v13, index: 0.0);
        ssEntity::RemoveTarget(this: (ssEntity *)&v13, target: Target);
      }
      v8 = 0;
      if ( this->newTargets.num > 0 )
      {
        v9 = 0;
        do
        {
          if ( v8 < 0 || v8 >= this->newTargets.num )
          {
            ssString::Init(this: &v16);
            ssString::operator=(this: &v16, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
            Error(msg: &v16);
            ssString::Empty(this: &v16);
          }
          if ( this->newTargets.data[v9].spawnId == 0
            || (v10 = ((unsigned __int8 (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
                v11 = 1,
                v10 == 0) )
          {
            v11 = 0;
          }
          if ( v11 != 0 )
          {
            if ( v8 < 0 || v8 >= this->newTargets.num )
            {
              ssString::Init(this: &v17);
              ssString::operator=(this: &v17, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
              Error(msg: &v17);
              ssString::Empty(this: &v17);
            }
            ssEntity::ssEntity(this: (ssEntity *)&v13.alloced, e: &this->newTargets.data[v9]);
            ssEntity::AddTarget(this: (ssEntity *)&v13, target: v12);
          }
          ++v8;
          ++v9;
        }
        while ( v8 < this->newTargets.num );
      }
      num = v14.num;
      ++v5;
      ++v6;
    }
    while ( v5 < v14.num );
  }
  ssList<ssEntity>::Clear(this: (ssList<float> *)&v14);
}


// ========================================================================
// __unwind$20805
// EA  : 0x82EF3DD8
// RVA : 0x00EF3DD8
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_20805()
{
  int v0; // r12

  ssList<util_debugMetaData::lineInfo_t>::~ssList<util_debugMetaData::lineInfo_t>(this: (ssList<int> *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$20820
// EA  : 0x82EF3E00
// RVA : 0x00EF3E00
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_20820()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$20852
// EA  : 0x82EF3E28
// RVA : 0x00EF3E28
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_20852()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$20889
// EA  : 0x82EF3E50
// RVA : 0x00EF3E50
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_20889()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 144));
}


// ========================================================================
// ?Init@util_triggerLookAtManagerVolume@@UAAXXZ
// EA  : 0x82EF3E78
// RVA : 0x00EF3E78
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void __fastcall util_triggerLookAtManagerVolume::Init(util_triggerLookAtManagerVolume *this)
{
  ssEntity *p_self; // r25
  int v3; // r20
  double v4; // fp31
  int *v5; // r3
  int v6; // r31
  int v7; // r29
  idSSObject *v8; // r3
  __int64 v9; // r11
  signed int num; // r5
  ssList<ssEntity> *p_triggers; // r3
  signed int v12; // r10
  int v13; // r11
  idSSObject *v14; // r3
  _BYTE *v15; // r3
  ssEntity v16; // [sp+50h] [-80h] BYREF
  ssEntity v17; // [sp+54h] [-7Ch] BYREF
  __int64 v18; // [sp+58h] [-78h]

  p_self = &this->self;
  v3 = 0;
  v4 = 0.0;
  if ( ssEntity::NumTargets(this: &this->self) > 0.0 )
  {
    do
    {
      ssEntity::GetTarget(this: &v16, result: (ssString *)p_self, index: v4);
      ssEntity::ssEntity(this: &v17, e: &v16);
      v6 = *v5;
      v7 = gameInterface->FindObject(this: gameInterface, a2: *v5, a3: "util_triggerLookAt", a4: false);
      v8 = gameInterface->GetScriptObject(this: gameInterface, a2: v6, a3: v7);
      if ( _RTDynamicCast(
             inptr: v8,
             VfDelta: 0,
             SrcType: &idSSObject `RTTI Type Descriptor',
             TargetType: &idSuperScriptObject `RTTI Type Descriptor',
             isReference: 0) != nullptr )
      {
        num = this->triggers.num;
        p_triggers = &this->triggers;
        v12 = 0;
        if ( num <= 0 )
          goto LABEL_9;
        v13 = 0;
        while ( p_triggers->data[v13].spawnId != v16.spawnId )
        {
          ++v12;
          ++v13;
          if ( v12 >= num )
            goto LABEL_9;
        }
        if ( v12 == -1 )
LABEL_9:
          ssList<ssEntity>::Insert(this: p_triggers, element: &v16, index: num);
        v14 = gameInterface->GetScriptObject(this: gameInterface, a2: v6, a3: v7);
        v15 = _RTDynamicCast(
                inptr: v14,
                VfDelta: 0,
                SrcType: &idSSObject `RTTI Type Descriptor',
                TargetType: &util_triggerLookAt `RTTI Type Descriptor',
                isReference: 0);
        if ( v15 != nullptr )
          v15[8] = 0;
        else
          AssertionFailed(msg: "Assertion failed: 0");
      }
      LODWORD(v9) = ++v3;
      v18 = v9;
      v4 = (float)v9;
    }
    while ( v4 < ssEntity::NumTargets(this: p_self) );
  }
}


// ========================================================================
// ?Init@util_distanceTrigger@@UAAXXZ
// EA  : 0x82EF4030
// RVA : 0x00EF4030
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void __fastcall util_distanceTrigger::Init(util_distanceTrigger *this)
{
  const ssString *v2; // r3
  const ssString *v3; // r22
  ssString *v4; // r3
  const ssString *v5; // r3
  const ssString *v6; // r3
  const ssString *v7; // r3
  ssString *v8; // r3
  const ssString *v9; // r3
  const ssString *v10; // r24
  ssString *v11; // r3
  const ssString *v12; // r3
  const ssString *v13; // r3
  const ssString *v14; // r3
  ssString *v15; // r3
  int v16; // r28
  double v17; // fp31
  __int64 v18; // r11
  char v19; // r3
  double v20; // fp12
  double v21; // fp13
  double v22; // fp0
  unsigned int num; // r5
  int v24; // r25
  int v25; // r27
  int v26; // r26
  int v27; // r28
  float *data; // r29
  float *v29; // r29
  float *v30; // r11
  double v31; // fp0
  double v32; // fp13
  signed int v33; // r3
  double speed; // fp0
  __int64 v35; // r7
  ssString v36; // [sp+50h] [-230h] BYREF
  ssEntity v37; // [sp+60h] [-220h] BYREF
  float v38; // [sp+64h] [-21Ch]
  float v39; // [sp+68h] [-218h]
  ssEntity v40; // [sp+70h] [-210h] BYREF
  float v41; // [sp+74h] [-20Ch]
  float v42; // [sp+78h] [-208h]
  ssString v43; // [sp+80h] [-200h] BYREF
  ssString v44; // [sp+90h] [-1F0h] BYREF
  ssString v45; // [sp+A0h] [-1E0h] BYREF
  ssString v46; // [sp+B0h] [-1D0h] BYREF
  ssString v47; // [sp+C0h] [-1C0h] BYREF
  ssString v48; // [sp+D0h] [-1B0h] BYREF
  ssString v49; // [sp+E0h] [-1A0h] BYREF
  ssString v50; // [sp+F0h] [-190h] BYREF
  ssString v51; // [sp+100h] [-180h] BYREF
  ssString v52; // [sp+110h] [-170h] BYREF
  ssString v53; // [sp+120h] [-160h] BYREF
  cvarInt_ v54; // [sp+130h] [-150h] BYREF
  cvarInt_ v55; // [sp+140h] [-140h] BYREF
  ssString v56; // [sp+150h] [-130h] BYREF
  ssString v57; // [sp+160h] [-120h] BYREF
  ssString v58; // [sp+170h] [-110h] BYREF
  ssString v59; // [sp+180h] [-100h] BYREF
  ssString v60; // [sp+190h] [-F0h] BYREF
  ssString v61; // [sp+1A0h] [-E0h] BYREF
  ssString v62; // [sp+1B0h] [-D0h] BYREF
  ssString v63; // [sp+1C0h] [-C0h] BYREF
  ssString v64; // [sp+1D0h] [-B0h] BYREF
  ssString v65; // [sp+1E0h] [-A0h] BYREF
  ssString v66; // [sp+1F0h] [-90h] BYREF
  ssString v67; // [sp+200h] [-80h] BYREF

  if ( this->ignore.x && this->ignore.y && this->ignore.z )
  {
    cvarInt_::cvarInt_(this: &v55, name_: "ss_debugPrint", default_: 1);
    if ( gameInterface->GetCVarInteger(this: gameInterface, a2: v55.name, a3: v55.defValue) > 0 )
    {
      ssString::ssString(this: &v56, i: 327);
      v3 = v2;
      ssString::Init(this: &v51);
      ssString::operator=(this: &v51, text: "util_distanceTrigger::Init");
      v4 = operator+(result: &v64, a: "^3", b: &v51);
      v5 = operator+(result: &v60, a: v4, b: "::");
      v6 = operator+(result: &v66, a: v5, b: v3);
      v7 = operator+(result: &v58, a: v6, b: "^0 : ");
      v8 = operator+(result: &v62, a: v7, b: "Can't ignore x, y, and z. Defaulting.");
      gameInterface->Printf(this: gameInterface, a2: "%s\n", v8->data);
      ssString::Empty(this: &v62);
      ssString::Empty(this: &v58);
      ssString::Empty(this: &v66);
      ssString::Empty(this: &v60);
      ssString::Empty(this: &v64);
      ssString::Empty(this: &v51);
      ssString::Empty(this: &v56);
    }
    this->ignore.z = false;
    this->ignore.y = false;
    this->ignore.x = false;
  }
  if ( this->speed <= 0.0 )
  {
    cvarInt_::cvarInt_(this: &v54, name_: "ss_debugPrint", default_: 1);
    if ( gameInterface->GetCVarInteger(this: gameInterface, a2: v54.name, a3: v54.defValue) > 0 )
    {
      ssString::ssString(this: &v67, i: 332);
      v10 = v9;
      ssString::Init(this: &v52);
      ssString::operator=(this: &v52, text: "util_distanceTrigger::Init");
      v11 = operator+(result: &v65, a: "^3", b: &v52);
      v12 = operator+(result: &v63, a: v11, b: "::");
      v13 = operator+(result: &v61, a: v12, b: v10);
      v14 = operator+(result: &v59, a: v13, b: "^0 : ");
      v15 = operator+(result: &v57, a: v14, b: "Speed <= 0.0f. Defaulting.");
      gameInterface->Printf(this: gameInterface, a2: "%s\n", v15->data);
      ssString::Empty(this: &v57);
      ssString::Empty(this: &v59);
      ssString::Empty(this: &v61);
      ssString::Empty(this: &v63);
      ssString::Empty(this: &v65);
      ssString::Empty(this: &v52);
      ssString::Empty(this: &v67);
    }
    this->speed = 50.0;
  }
  v16 = 0;
  if ( ssEntity::NumTargets(this: &this->self) > 0.0 )
  {
    v17 = 0.0;
    do
    {
      ssEntity::GetTarget(this: (ssEntity *)&v36, result: (ssString *)&this->self, index: v17);
      if ( v36.len == 0
        || (v19 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
            LOBYTE(v18) = 1,
            v19 == 0) )
      {
        LOBYTE(v18) = 0;
      }
      if ( (_BYTE)v18 != 0 )
      {
        ssEntity::GetWorldOrigin(this: &v37, result: (ssString *)&this->self);
        ssEntity::GetWorldOrigin(this: &v40, result: &v36);
        if ( this->ignore.x )
          v20 = 0.0;
        else
          v20 = (float)((float)(*(float *)&v37.spawnId - *(float *)&v40.spawnId)
                      * (float)(*(float *)&v37.spawnId - *(float *)&v40.spawnId));
        if ( this->ignore.y )
          v21 = 0.0;
        else
          v21 = (float)((float)(v38 - v41) * (float)(v38 - v41));
        if ( this->ignore.z )
          v22 = 0.0;
        else
          v22 = (float)((float)(v39 - v42) * (float)(v39 - v42));
        num = this->distances.num;
        *(float *)&v36.data = __fsqrts((float)((float)((float)v22 + (float)v21) + (float)v20));
        ssList<float>::Insert(this: &this->distances, element: (float *)&v36.data, index: num);
        ssList<ssEntity>::Insert(this: &this->targets, element: (const ssEntity *)&v36, index: this->targets.num);
      }
      LODWORD(v18) = ++v16;
      *(_QWORD *)&v36.alloced = v18;
      v17 = (float)v18;
    }
    while ( v17 < ssEntity::NumTargets(this: &this->self) );
  }
  v24 = 0;
  if ( this->targets.num > 0 )
  {
    v25 = 0;
    do
    {
      v26 = v24;
      if ( v24 < this->targets.num )
      {
        v27 = v25 * 4;
        do
        {
          if ( !this->reverse )
          {
            if ( v24 < 0 || v24 >= this->distances.num )
            {
              ssString::Init(this: &v46);
              ssString::operator=(this: &v46, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
              Error(msg: &v46);
              ssString::Empty(this: &v46);
            }
            data = this->distances.data;
            if ( v26 < 0 || v26 >= this->distances.num )
            {
              ssString::Init(this: &v50);
              ssString::operator=(this: &v50, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
              Error(msg: &v50);
              ssString::Empty(this: &v50);
            }
            if ( data[v25] > (double)*(float *)((char *)this->distances.data + v27) )
              goto LABEL_49;
          }
          if ( this->reverse )
          {
            if ( v24 < 0 || v24 >= this->distances.num )
            {
              ssString::Init(this: &v48);
              ssString::operator=(this: &v48, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
              Error(msg: &v48);
              ssString::Empty(this: &v48);
            }
            v29 = this->distances.data;
            if ( v26 < 0 || v26 >= this->distances.num )
            {
              ssString::Init(this: &v44);
              ssString::operator=(this: &v44, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
              Error(msg: &v44);
              ssString::Empty(this: &v44);
            }
            if ( v29[v25] < (double)*(float *)((char *)this->distances.data + v27) )
            {
LABEL_49:
              if ( v24 < 0 || v24 >= this->distances.num )
              {
                ssString::Init(this: &v45);
                ssString::operator=(this: &v45, text: "Assertion failed: ( a >= 0 ) && ( a < num )");
                Error(msg: &v45);
                ssString::Empty(this: &v45);
              }
              if ( v26 < 0 || v26 >= this->distances.num )
              {
                ssString::Init(this: &v47);
                ssString::operator=(this: &v47, text: "Assertion failed: ( b >= 0 ) && ( b < num )");
                Error(msg: &v47);
                ssString::Empty(this: &v47);
              }
              v30 = this->distances.data;
              v31 = v30[v25];
              v30[v25] = *(float *)((char *)v30 + v27);
              *(float *)((char *)this->distances.data + v27) = v31;
              if ( v24 < 0 || v24 >= this->targets.num )
              {
                ssString::Init(this: &v49);
                ssString::operator=(this: &v49, text: "Assertion failed: ( a >= 0 ) && ( a < num )");
                Error(msg: &v49);
                ssString::Empty(this: &v49);
              }
              if ( v26 < 0 || v26 >= this->targets.num )
              {
                ssString::Init(this: &v43);
                ssString::operator=(this: &v43, text: "Assertion failed: ( b >= 0 ) && ( b < num )");
                Error(msg: &v43);
                ssString::Empty(this: &v43);
              }
              ssEntity::ssEntity(this: (ssEntity *)&v36.data, e: &this->targets.data[v25]);
              ssEntity::ssEntity(
                this: &this->targets.data[v25],
                e: (const ssEntity *)((char *)this->targets.data + v27));
              ssEntity::ssEntity(this: (ssEntity *)((char *)this->targets.data + v27), e: (const ssEntity *)&v36.data);
            }
          }
          ++v26;
          v27 += 4;
        }
        while ( v26 < this->targets.num );
      }
      ++v24;
      ++v25;
    }
    while ( v24 < this->targets.num );
  }
  if ( this->reverse )
  {
    if ( this->distances.num <= 0 )
    {
      ssString::Init(this: &v53);
      ssString::operator=(this: &v53, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
      Error(msg: &v53);
      ssString::Empty(this: &v53);
    }
    v32 = -this->speed;
    this->ramp = *this->distances.data;
    this->speed = v32;
  }
  v33 = gameInterface->GetFrameTime(this: gameInterface);
  speed = this->speed;
  __twllei(v33, 0);
  LODWORD(v35) = 1000 / v33;
  this->frameSpeed = (float)speed / (float)v35;
}


// ========================================================================
// __unwind$21141
// EA  : 0x82EF4780
// RVA : 0x00EF4780
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21141()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 336));
}


// ========================================================================
// __unwind$21142
// EA  : 0x82EF47A8
// RVA : 0x00EF47A8
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21142()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 256));
}


// ========================================================================
// __unwind$21143
// EA  : 0x82EF47D0
// RVA : 0x00EF47D0
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21143()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 464));
}


// ========================================================================
// __unwind$21144
// EA  : 0x82EF47F8
// RVA : 0x00EF47F8
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21144()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 400));
}


// ========================================================================
// __unwind$21145
// EA  : 0x82EF4820
// RVA : 0x00EF4820
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21145()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 496));
}


// ========================================================================
// __unwind$21146
// EA  : 0x82EF4848
// RVA : 0x00EF4848
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21146()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 368));
}


// ========================================================================
// __unwind$21147
// EA  : 0x82EF4870
// RVA : 0x00EF4870
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21147()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 432));
}


// ========================================================================
// __unwind$21148
// EA  : 0x82EF4898
// RVA : 0x00EF4898
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21148()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 512));
}


// ========================================================================
// __unwind$21149
// EA  : 0x82EF48C0
// RVA : 0x00EF48C0
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21149()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 272));
}


// ========================================================================
// __unwind$21150
// EA  : 0x82EF48E8
// RVA : 0x00EF48E8
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21150()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 480));
}


// ========================================================================
// __unwind$21151
// EA  : 0x82EF4910
// RVA : 0x00EF4910
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21151()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 448));
}


// ========================================================================
// __unwind$21152
// EA  : 0x82EF4938
// RVA : 0x00EF4938
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21152()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 416));
}


// ========================================================================
// __unwind$21153_0
// EA  : 0x82EF4960
// RVA : 0x00EF4960
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21153_0()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 384));
}


// ========================================================================
// __unwind$21154
// EA  : 0x82EF4988
// RVA : 0x00EF4988
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21154()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 352));
}


// ========================================================================
// __unwind$21294
// EA  : 0x82EF49B0
// RVA : 0x00EF49B0
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21294()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 176));
}


// ========================================================================
// __unwind$21324_0
// EA  : 0x82EF49D8
// RVA : 0x00EF49D8
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21324_0()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 240));
}


// ========================================================================
// __unwind$21353
// EA  : 0x82EF4A00
// RVA : 0x00EF4A00
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21353()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 208));
}


// ========================================================================
// __unwind$21383
// EA  : 0x82EF4A28
// RVA : 0x00EF4A28
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21383()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 144));
}


// ========================================================================
// __unwind$21412
// EA  : 0x82EF4A50
// RVA : 0x00EF4A50
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21412()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 160));
}


// ========================================================================
// __unwind$21428
// EA  : 0x82EF4A78
// RVA : 0x00EF4A78
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21428()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 192));
}


// ========================================================================
// __unwind$21467
// EA  : 0x82EF4AA0
// RVA : 0x00EF4AA0
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21467()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 224));
}


// ========================================================================
// __unwind$21483
// EA  : 0x82EF4AC8
// RVA : 0x00EF4AC8
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21483()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 128));
}


// ========================================================================
// __unwind$21522
// EA  : 0x82EF4AF0
// RVA : 0x00EF4AF0
// PDB : w:\tech5\tungsten\superscript\util\triggerutil.cpp
// ========================================================================

void _unwind_21522()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 640 + 288));
}

