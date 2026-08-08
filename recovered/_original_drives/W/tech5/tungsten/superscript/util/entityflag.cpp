
// ========================================================================
// ?SetDeferredThread@util_entityFlag@@QAAXVssString@@M@Z
// EA  : 0x82EEE418
// RVA : 0x00EEE418
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::SetDeferredThread(util_entityFlag *this, ssString *name, double delay)
{
  ((void (__fastcall *)(idGameSuperInterface *))gameInterface->Wait)(a1: gameInterface);
  util_entityFlag::Set(this, name, delay: 0.0);
  ssString::Empty(this: name);
}


// ========================================================================
// __unwind$20293
// EA  : 0x82EEE470
// RVA : 0x00EEE470
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_20293()
{
  int v0; // r12

  ssString::~ssString(this: *(ssString **)(v0 - 112 + 140));
}


// ========================================================================
// ?ClearDeferredThread@util_entityFlag@@QAAXVssString@@M@Z
// EA  : 0x82EEE4A0
// RVA : 0x00EEE4A0
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::ClearDeferredThread(util_entityFlag *this, ssString *name, double delay)
{
  ((void (__fastcall *)(idGameSuperInterface *))gameInterface->Wait)(a1: gameInterface);
  util_entityFlag::Clear(this, name, delay: 0.0);
  ssString::Empty(this: name);
}


// ========================================================================
// __unwind$20423
// EA  : 0x82EEE4F8
// RVA : 0x00EEE4F8
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_20423()
{
  int v0; // r12

  ssString::~ssString(this: *(ssString **)(v0 - 112 + 140));
}


// ========================================================================
// ?OnTrigger@util_entityFlagActivate@@UAAXVssEntity@@@Z
// EA  : 0x82EEE520
// RVA : 0x00EEE520
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlagActivate::OnTrigger(util_entityFlagActivate *this, ssEntity *activator)
{
  util_entityFlagActivate_vtbl *v3; // r30
  ssEntity *v4; // r3
  ssEntity v5; // [sp+50h] [-20h] BYREF

  v3 = this->__vftable;
  ssEntity::ssEntity(this: &v5, e: activator);
  v3->OnActivate(this, a2: v4);
}


// ========================================================================
// ?Init@util_entityFlagVolume@@UAAXXZ
// EA  : 0x82EEE570
// RVA : 0x00EEE570
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlagVolume::Init(util_entityFlagVolume *this)
{
  ssEntity *v2; // r3
  ssEntity v3; // [sp+50h] [-20h] BYREF

  ssUtil::Init(this: &ssUtil);
  ssEntity::ssEntity(this: &v3, e: &this->self);
  ssUtil::DefineFlag(ent: v2, name: &this->flag);
}


// ========================================================================
// ?OnExit@util_entityFlagVolume@@UAAXVssEntity@@@Z
// EA  : 0x82EEE5C0
// RVA : 0x00EEE5C0
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlagVolume::OnExit(util_entityFlagVolume *this, ssEntity *__formal)
{
  ssString *p_flag; // r30
  ssEntity *v4; // r3
  ssEntity v5; // [sp+50h] [-40h] BYREF
  ssString v6; // [sp+60h] [-30h] BYREF

  p_flag = &this->flag;
  ssEntity::ssEntity(this: &v5, e: &this->self);
  ssUtil::ClearFlag(ent: v4, name: p_flag, delay: 0.0);
  ssString::Init(this: &v6);
  ssString::operator=(this: &v6, text: &this->callExit);
  ssUtil::CreateNamedThreadOnEntity(callFunction: &v6);
}


// ========================================================================
// ?GetIndex@util_entityFlag@@QAAHABVssString@@@Z
// EA  : 0x82EEE898
// RVA : 0x00EEE898
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

int __fastcall util_entityFlag::GetIndex(util_entityFlag *this, const ssString *name)
{
  int v4; // r28
  int i; // r29
  ssString v7[5]; // [sp+50h] [-50h] BYREF

  v4 = 0;
  if ( this->flags.num <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    if ( v4 < 0 || v4 >= this->flags.num )
    {
      ssString::Init(this: v7);
      ssString::operator=(this: v7, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
      Error(msg: v7);
      ssString::Empty(this: v7);
    }
    if ( ssString::Cmp(this: &this->flags.data[i].name, text: name->data) == 0 )
      break;
    if ( ++v4 >= this->flags.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// $M20805
// EA  : 0x82EEE944
// RVA : 0x00EEE944
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _M20805()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 80));
}


// ========================================================================
// ?Init@util_entityFlagActivate@@UAAXXZ
// EA  : 0x82EEE978
// RVA : 0x00EEE978
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlagActivate::Init(util_entityFlagActivate *this)
{
  ssString *p_targetEntity; // r28
  ssEntity *p_target; // r26
  const ssEntity *v4; // r3
  char v5; // r3
  char v6; // r11
  const ssString *v7; // r3
  const ssString *v8; // r29
  ssString *v9; // r3
  const ssString *v10; // r3
  const ssString *v11; // r3
  const ssString *v12; // r3
  const ssString *v13; // r3
  const ssString *v14; // r3
  ssString *v15; // r3
  int v16; // r30
  int v17; // r28
  const ssString *v18; // r27
  ssEntity *v19; // r3
  ssObject<ssWorldUtil> v20[2]; // [sp+50h] [-100h] BYREF
  ssString v21; // [sp+60h] [-F0h] BYREF
  ssString v22; // [sp+70h] [-E0h] BYREF
  cvarInt_ v23; // [sp+80h] [-D0h] BYREF
  ssString v24; // [sp+90h] [-C0h] BYREF
  ssString v25; // [sp+A0h] [-B0h] BYREF
  ssString v26; // [sp+B0h] [-A0h] BYREF
  ssString v27; // [sp+C0h] [-90h] BYREF
  ssString v28; // [sp+D0h] [-80h] BYREF
  ssString v29; // [sp+E0h] [-70h] BYREF
  ssString v30; // [sp+F0h] [-60h] BYREF
  ssString v31[5]; // [sp+100h] [-50h] BYREF

  p_targetEntity = &this->targetEntity;
  if ( this->targetEntity.len <= 0 )
  {
    ssObject<ssWorldUtil>::GetWorld(this: v20, result: (ssEntity *)&worldUtil);
    p_target = &this->target;
    ssEntity::ssEntity(this: &this->target, e: (const ssEntity *)v20);
  }
  else
  {
    p_target = &this->target;
    v4 = ssEntity::ssEntity(this: (ssEntity *)&v20[0].objectId, name: &this->targetEntity);
    ssEntity::ssEntity(this: &this->target, e: v4);
    if ( this->target.spawnId == 0
      || (v5 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
          v6 = 1,
          v5 == 0) )
    {
      v6 = 0;
    }
    if ( v6 == 0 )
    {
      cvarInt_::cvarInt_(this: &v23, name_: "ss_debugPrint", default_: 1);
      if ( gameInterface->GetCVarInteger(this: gameInterface, a2: v23.name, a3: v23.defValue) > 0 )
      {
        ssString::ssString(this: v31, i: 590);
        v8 = v7;
        ssString::Init(this: &v21);
        ssString::operator=(this: &v21, text: "util_entityFlagActivate::Init");
        v9 = operator+(result: &v29, a: "^3", b: &v21);
        v10 = operator+(result: &v27, a: v9, b: "::");
        v11 = operator+(result: &v25, a: v10, b: v8);
        v12 = operator+(result: &v28, a: v11, b: "^0 : ");
        v13 = operator+(result: &v30, a: v12, b: "Entity: ");
        v14 = operator+(result: &v24, a: v13, b: p_targetEntity);
        v15 = operator+(result: &v26, a: v14, b: " could not be found.");
        gameInterface->Printf(this: gameInterface, a2: "%s\n", v15->data);
        ssString::Empty(this: &v26);
        ssString::Empty(this: &v24);
        ssString::Empty(this: &v30);
        ssString::Empty(this: &v28);
        ssString::Empty(this: &v25);
        ssString::Empty(this: &v27);
        ssString::Empty(this: &v29);
        ssString::Empty(this: &v21);
        ssString::Empty(this: v31);
      }
      return;
    }
  }
  v16 = 0;
  if ( this->defineFlags.num > 0 )
  {
    v17 = 0;
    do
    {
      if ( v16 < 0 || v16 >= this->defineFlags.num )
      {
        ssString::Init(this: &v22);
        ssString::operator=(this: &v22, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
        Error(msg: &v22);
        ssString::Empty(this: &v22);
      }
      v18 = &this->defineFlags.data[v17];
      ssEntity::ssEntity(this: (ssEntity *)&v20[0].objectId, e: p_target);
      ssUtil::DefineFlag(ent: v19, name: v18);
      ++v16;
      ++v17;
    }
    while ( v16 < this->defineFlags.num );
  }
}


// ========================================================================
// __unwind$20831
// EA  : 0x82EEEBFC
// RVA : 0x00EEEBFC
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_20831()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 336 + 256));
}


// ========================================================================
// __unwind$20832
// EA  : 0x82EEEC24
// RVA : 0x00EEEC24
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_20832()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 336 + 96));
}


// ========================================================================
// __unwind$20833
// EA  : 0x82EEEC4C
// RVA : 0x00EEEC4C
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_20833()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 336 + 224));
}


// ========================================================================
// __unwind$20834
// EA  : 0x82EEEC74
// RVA : 0x00EEEC74
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_20834()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 336 + 192));
}


// ========================================================================
// __unwind$20835
// EA  : 0x82EEEC9C
// RVA : 0x00EEEC9C
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_20835()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 336 + 160));
}


// ========================================================================
// __unwind$20836
// EA  : 0x82EEECC4
// RVA : 0x00EEECC4
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_20836()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 336 + 208));
}


// ========================================================================
// __unwind$20837
// EA  : 0x82EEECEC
// RVA : 0x00EEECEC
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_20837()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 336 + 240));
}


// ========================================================================
// __unwind$20838
// EA  : 0x82EEED14
// RVA : 0x00EEED14
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_20838()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 336 + 144));
}


// ========================================================================
// __unwind$20839
// EA  : 0x82EEED3C
// RVA : 0x00EEED3C
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_20839()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 336 + 176));
}


// ========================================================================
// __unwind$20915
// EA  : 0x82EEED64
// RVA : 0x00EEED64
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_20915()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 336 + 112));
}


// ========================================================================
// ?OnEnter@util_entityFlagVolume@@UAAXVssEntity@@@Z
// EA  : 0x82EEED98
// RVA : 0x00EEED98
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlagVolume::OnEnter(util_entityFlagVolume *this, ssString *ent)
{
  char v4; // r24
  int v5; // r29
  int v6; // r28
  ssEntity *v7; // r27
  BOOL v8; // r27
  ssEntity *v9; // r3
  ssEntity v10; // [sp+50h] [-90h] BYREF
  ssString v11; // [sp+60h] [-80h] BYREF
  ssString v12; // [sp+70h] [-70h] BYREF
  ssString v13[6]; // [sp+80h] [-60h] BYREF

  v10.spawnId = this->filter.num;
  if ( v10.spawnId <= 0 )
    goto LABEL_11;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  while ( 1 )
  {
    v7 = ssEntity::Name(this: (ssEntity *)v13, result: ent);
    if ( v5 < 0 || v5 >= this->filter.num )
    {
      ssString::Init(this: &v11);
      ssString::operator=(this: &v11, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
      Error(msg: &v11);
      ssString::Empty(this: &v11);
    }
    v8 = (_cntlzw(ssString::Cmp(this: (ssString *)v7, text: this->filter.data[v6].data)) & 0x20) != 0;
    ssString::Empty(this: v13);
    if ( v8 )
      break;
    ++v5;
    ++v6;
    if ( v5 >= this->filter.num )
      goto LABEL_10;
  }
  v4 = 1;
LABEL_10:
  if ( v4 != 0 )
  {
LABEL_11:
    ++this->enteredCount;
    ssEntity::ssEntity(this: &v10, e: &this->self);
    ssUtil::SetFlag(ent: v9, name: &this->flag, delay: 0.0);
    ssString::Init(this: &v12);
    ssString::operator=(this: &v12, text: &this->callEnter);
    ssUtil::CreateNamedThreadOnEntity(callFunction: &v12);
  }
}


// ========================================================================
// __unwind$21023
// EA  : 0x82EEEEC4
// RVA : 0x00EEEEC4
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21023()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 128));
}


// ========================================================================
// __unwind$21036
// EA  : 0x82EEEEEC
// RVA : 0x00EEEEEC
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21036()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 96));
}


// ========================================================================
// ?IsDefined@util_entityFlag@@QAA_NABVssString@@@Z
// EA  : 0x82EEF100
// RVA : 0x00EEF100
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

BOOL __fastcall util_entityFlag::IsDefined(util_entityFlag *this, const ssString *name)
{
  return util_entityFlag::GetIndex(this, name) != -1;
}


// ========================================================================
// ?IsSet@util_entityFlag@@QAA_NABVssString@@@Z
// EA  : 0x82EEF138
// RVA : 0x00EEF138
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

BOOL __fastcall util_entityFlag::IsSet(util_entityFlag *this, const ssString *name)
{
  int Index; // r3
  int v5; // r29
  ssEntity *v6; // r30
  ssString *v7; // r3
  const ssString *v8; // r3
  const ssString *v9; // r3
  ssString v11; // [sp+50h] [-70h] BYREF
  ssString v12; // [sp+60h] [-60h] BYREF
  ssString v13; // [sp+70h] [-50h] BYREF
  ssString v14[4]; // [sp+80h] [-40h] BYREF

  Index = util_entityFlag::GetIndex(this, name);
  v5 = Index;
  if ( Index == -1 )
  {
    v6 = ssEntity::Name(this: (ssEntity *)v14, result: (ssString *)&this->self);
    v7 = operator+(result: &v13, a: "Flag name: ", b: name);
    v8 = operator+(result: &v12, a: v7, b: " is not defined on entity: ");
    v9 = operator+(result: &v11, a: v8, b: (const ssString *)v6);
    Warning(msg: v9);
    ssString::Empty(this: &v11);
    ssString::Empty(this: &v12);
    ssString::Empty(this: &v13);
    ssString::Empty(this: v14);
    return false;
  }
  else
  {
    if ( Index < 0 || Index >= this->flags.num )
      AssertionFailed(msg: "Assertion failed: ( index >= 0 ) && ( index < num )");
    return this->flags.data[v5].state;
  }
}


// ========================================================================
// __unwind$21261
// EA  : 0x82EEF20C
// RVA : 0x00EEF20C
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21261()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 128));
}


// ========================================================================
// __unwind$21262
// EA  : 0x82EEF234
// RVA : 0x00EEF234
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21262()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$21263
// EA  : 0x82EEF25C
// RVA : 0x00EEF25C
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21263()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$21264
// EA  : 0x82EEF284
// RVA : 0x00EEF284
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21264()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 80));
}


// ========================================================================
// ?Set@util_entityFlag@@QAAXABVssString@@M@Z
// EA  : 0x82EEF2B8
// RVA : 0x00EEF2B8
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::Set(
        util_entityFlag *this,
        const ssString *name,
        double delay,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        float a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17,
        float a18)
{
  int Index; // r4
  ssEntity *v20; // r30
  ssString *v21; // r3
  const ssString *v22; // r3
  const ssString *v23; // r3
  util_entityFlag::flagDef_t *v24; // r3
  int count; // r11
  util_entityFlag::flagDef_t *v26; // r30
  double Time; // fp1
  int num; // r8
  int v29; // r29
  int v30; // r28
  int v31; // r29
  int v32; // r28
  _DWORD v33[4]; // [sp+50h] [-B0h] BYREF
  ssString v34; // [sp+60h] [-A0h] BYREF
  ssString v35; // [sp+70h] [-90h] BYREF
  ssString v36; // [sp+80h] [-80h] BYREF
  ssString v37; // [sp+90h] [-70h] BYREF
  ssString v38; // [sp+A0h] [-60h] BYREF
  ssString v39[5]; // [sp+B0h] [-50h] BYREF

  a18 = delay;
  Index = util_entityFlag::GetIndex(this, name);
  if ( Index == -1 )
  {
    v20 = ssEntity::Name(this: (ssEntity *)v39, result: (ssString *)&this->self);
    v21 = operator+(result: &v38, a: "Flag name: ", b: name);
    v22 = operator+(result: &v37, a: v21, b: " is not defined on entity: ");
    v23 = operator+(result: &v36, a: v22, b: (const ssString *)v20);
    Warning(msg: v23);
    ssString::Empty(this: &v36);
    ssString::Empty(this: &v37);
    ssString::Empty(this: &v38);
    ssString::Empty(this: v39);
  }
  else if ( a18 <= 0.0 )
  {
    v24 = ssList<util_entityFlag::flagDef_t>::Get(this: &this->flags, index: Index);
    count = v24->count;
    v24->state = true;
    v26 = v24;
    v24->count = count + 1;
    Time = GetTime();
    num = v26->terminateThreads.num;
    v26->lastTime = Time;
    v29 = 0;
    if ( num > 0 )
    {
      v30 = 0;
      do
      {
        if ( v29 < 0 || v29 >= v26->terminateThreads.num )
          AssertionFailed(msg: "Assertion failed: ( index >= 0 ) && ( index < num )");
        gameInterface->TerminateThread_2(this: gameInterface, a2: v26->terminateThreads.data[v30]);
        ++v29;
        ++v30;
      }
      while ( v29 < v26->terminateThreads.num );
    }
    ssList<ssEntity>::Clear(this: (ssList<float> *)&v26->terminateThreads);
    v31 = 0;
    if ( v26->callFunctions.num > 0 )
    {
      v32 = 0;
      do
      {
        if ( v31 < 0 || v31 >= v26->callFunctions.num )
        {
          ssString::Init(this: &v35);
          ssString::operator=(this: &v35, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
          Error(msg: &v35);
          ssString::Empty(this: &v35);
        }
        gameInterface->CreateNamedThread(
          this: gameInterface,
          a2: v26->callFunctions.data[v32].target.spawnId,
          a3: v26->callFunctions.data[v32].function.data);
        ++v31;
        ++v32;
      }
      while ( v31 < v26->callFunctions.num );
    }
    ssList<util_entityFlag::callFunction_t>::Clear(this: &v26->callFunctions);
  }
  else
  {
    ssString::Init(this: &v34);
    ssString::operator=(this: &v34, text: "SetDeferredThread");
    v33[1] = name;
    v33[2] = &a18;
    v33[0] = util_entityFlag::SetDeferredThread;
    gameInterface->CreateThread(
      this: gameInterface,
      a2: v34.data,
      a3: this,
      a4: (void (__fastcall *)(idSSObject *, void *))idSuperScriptObject::threadData2_t<ssString,float>::proxyFunc,
      a5: v33);
    ssString::Empty(this: &v34);
  }
}


// ========================================================================
// __unwind$21323
// EA  : 0x82EEF500
// RVA : 0x00EEF500
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21323()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 176));
}


// ========================================================================
// __unwind$21324
// EA  : 0x82EEF528
// RVA : 0x00EEF528
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21324()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 160));
}


// ========================================================================
// __unwind$21325
// EA  : 0x82EEF550
// RVA : 0x00EEF550
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21325()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 144));
}


// ========================================================================
// __unwind$21326
// EA  : 0x82EEF578
// RVA : 0x00EEF578
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21326()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$21327
// EA  : 0x82EEF5A0
// RVA : 0x00EEF5A0
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21327()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$21377
// EA  : 0x82EEF5C8
// RVA : 0x00EEF5C8
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21377()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 112));
}


// ========================================================================
// ?Set@util_entityFlag@@QAAXABV?$ssList@VssString@@@@M@Z
// EA  : 0x82EEF5F8
// RVA : 0x00EEF5F8
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::Set(
        util_entityFlag *this,
        const ssList<ssString> *names,
        double delay,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int num; // r11
  int v14; // r30
  int v15; // r29
  float v16; // [sp+8h] [-A8h]
  float v17; // [sp+Ch] [-A4h]
  float v18; // [sp+10h] [-A0h]
  float v19; // [sp+14h] [-9Ch]
  float v20; // [sp+18h] [-98h]
  float v21; // [sp+1Ch] [-94h]
  float v22; // [sp+20h] [-90h]
  float v23; // [sp+24h] [-8Ch]
  ssString v24; // [sp+60h] [-50h] BYREF

  v14 = 0;
  num = names->num;
  if ( num > 0 )
  {
    v15 = 0;
    do
    {
      if ( v14 < 0 || v14 >= num )
      {
        ssString::Init(this: &v24);
        ssString::operator=(this: &v24, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
        Error(msg: &v24);
        ssString::Empty(this: &v24);
      }
      util_entityFlag::Set(
        this,
        name: &names->data[v15],
        delay,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11: v16,
        a12: v17,
        a13: v18,
        a14: v19,
        a15: v20,
        a16: v21,
        a17: v22,
        a18: v23);
      num = names->num;
      ++v14;
      ++v15;
    }
    while ( v14 < num );
  }
}


// ========================================================================
// __unwind$21474
// EA  : 0x82EEF6A0
// RVA : 0x00EEF6A0
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21474()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?Clear@util_entityFlag@@QAAXABVssString@@M@Z
// EA  : 0x82EEF6D0
// RVA : 0x00EEF6D0
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::Clear(
        util_entityFlag *this,
        const ssString *name,
        double delay,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        float a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17,
        float a18)
{
  int Index; // r4
  ssEntity *v20; // r30
  ssString *v21; // r3
  const ssString *v22; // r3
  const ssString *v23; // r3
  _DWORD v24[4]; // [sp+50h] [-80h] BYREF
  ssString v25; // [sp+60h] [-70h] BYREF
  ssString v26; // [sp+70h] [-60h] BYREF
  ssString v27; // [sp+80h] [-50h] BYREF
  ssString v28; // [sp+90h] [-40h] BYREF
  ssString v29[3]; // [sp+A0h] [-30h] BYREF

  a18 = delay;
  Index = util_entityFlag::GetIndex(this, name);
  if ( Index == -1 )
  {
    v20 = ssEntity::Name(this: (ssEntity *)v29, result: (ssString *)&this->self);
    v21 = operator+(result: &v28, a: "Flag name: ", b: name);
    v22 = operator+(result: &v27, a: v21, b: " is not defined on entity: ");
    v23 = operator+(result: &v26, a: v22, b: (const ssString *)v20);
    Warning(msg: v23);
    ssString::Empty(this: &v26);
    ssString::Empty(this: &v27);
    ssString::Empty(this: &v28);
    ssString::Empty(this: v29);
  }
  else if ( a18 <= 0.0 )
  {
    ssList<util_entityFlag::flagDef_t>::Get(this: &this->flags, index: Index)->state = false;
  }
  else
  {
    ssString::Init(this: &v25);
    ssString::operator=(this: &v25, text: "ClearDeferredThread");
    v24[1] = name;
    v24[2] = &a18;
    v24[0] = util_entityFlag::ClearDeferredThread;
    gameInterface->CreateThread(
      this: gameInterface,
      a2: v25.data,
      a3: this,
      a4: (void (__fastcall *)(idSSObject *, void *))idSuperScriptObject::threadData2_t<ssString,float>::proxyFunc,
      a5: v24);
    ssString::Empty(this: &v25);
  }
}


// ========================================================================
// __unwind$21523
// EA  : 0x82EEF800
// RVA : 0x00EEF800
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21523()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 208 + 160));
}


// ========================================================================
// __unwind$21524
// EA  : 0x82EEF828
// RVA : 0x00EEF828
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21524()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 208 + 144));
}


// ========================================================================
// __unwind$21525
// EA  : 0x82EEF850
// RVA : 0x00EEF850
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21525()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 208 + 128));
}


// ========================================================================
// __unwind$21526
// EA  : 0x82EEF878
// RVA : 0x00EEF878
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21526()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 208 + 112));
}


// ========================================================================
// __unwind$21527
// EA  : 0x82EEF8A0
// RVA : 0x00EEF8A0
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21527()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 208 + 96));
}


// ========================================================================
// ?Clear@util_entityFlag@@QAAXABV?$ssList@VssString@@@@M@Z
// EA  : 0x82EEF8D0
// RVA : 0x00EEF8D0
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::Clear(
        util_entityFlag *this,
        const ssList<ssString> *names,
        double delay,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int num; // r11
  int v14; // r30
  int v15; // r29
  float v16; // [sp+8h] [-A8h]
  float v17; // [sp+Ch] [-A4h]
  float v18; // [sp+10h] [-A0h]
  float v19; // [sp+14h] [-9Ch]
  float v20; // [sp+18h] [-98h]
  float v21; // [sp+1Ch] [-94h]
  float v22; // [sp+20h] [-90h]
  float v23; // [sp+24h] [-8Ch]
  ssString v24; // [sp+60h] [-50h] BYREF

  v14 = 0;
  num = names->num;
  if ( num > 0 )
  {
    v15 = 0;
    do
    {
      if ( v14 < 0 || v14 >= num )
      {
        ssString::Init(this: &v24);
        ssString::operator=(this: &v24, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
        Error(msg: &v24);
        ssString::Empty(this: &v24);
      }
      util_entityFlag::Clear(
        this,
        name: &names->data[v15],
        delay,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11: v16,
        a12: v17,
        a13: v18,
        a14: v19,
        a15: v20,
        a16: v21,
        a17: v22,
        a18: v23);
      num = names->num;
      ++v14;
      ++v15;
    }
    while ( v14 < num );
  }
}


// ========================================================================
// __unwind$21604
// EA  : 0x82EEF978
// RVA : 0x00EEF978
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21604()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?Toggle@util_entityFlag@@QAAXABV?$ssList@VssString@@@@M@Z
// EA  : 0x82EEF9A8
// RVA : 0x00EEF9A8
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::Toggle(util_entityFlag *this, const ssList<ssString> *names, double delay)
{
  int num; // r11
  int v7; // r29
  int v8; // r28
  const ssString *v9; // r30
  double v10; // fp8
  double v11; // fp7
  double v12; // fp6
  double v13; // fp5
  double v14; // fp4
  double v15; // fp3
  double v16; // fp2
  float v17; // [sp+8h] [-B8h]
  float v18; // [sp+Ch] [-B4h]
  float v19; // [sp+10h] [-B0h]
  float v20; // [sp+14h] [-ACh]
  float v21; // [sp+18h] [-A8h]
  float v22; // [sp+1Ch] [-A4h]
  float v23; // [sp+20h] [-A0h]
  float v24; // [sp+24h] [-9Ch]
  ssString v25; // [sp+60h] [-60h] BYREF

  v7 = 0;
  num = names->num;
  if ( num > 0 )
  {
    v8 = 0;
    do
    {
      if ( v7 < 0 || v7 >= num )
      {
        ssString::Init(this: &v25);
        ssString::operator=(this: &v25, text: "Assertion failed: ( index >= 0 ) && ( index < num )");
        Error(msg: &v25);
        ssString::Empty(this: &v25);
      }
      v9 = &names->data[v8];
      if ( util_entityFlag::IsSet(this, name: v9) )
        util_entityFlag::Clear(
          this,
          name: v9,
          delay,
          a4: v16,
          a5: v15,
          a6: v14,
          a7: v13,
          a8: v12,
          a9: v11,
          a10: v10,
          a11: v17,
          a12: v18,
          a13: v19,
          a14: v20,
          a15: v21,
          a16: v22,
          a17: v23,
          a18: v24);
      else
        util_entityFlag::Set(
          this,
          name: v9,
          delay,
          a4: v16,
          a5: v15,
          a6: v14,
          a7: v13,
          a8: v12,
          a9: v11,
          a10: v10,
          a11: v17,
          a12: v18,
          a13: v19,
          a14: v20,
          a15: v21,
          a16: v22,
          a17: v23,
          a18: v24);
      num = names->num;
      ++v7;
      ++v8;
    }
    while ( v7 < num );
  }
}


// ========================================================================
// __unwind$21663
// EA  : 0x82EEFA74
// RVA : 0x00EEFA74
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_21663()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 96));
}


// ========================================================================
// ?OnActivate@util_entityFlag@@UAAXVssEntity@@@Z
// EA  : 0x82EEFAA8
// RVA : 0x00EEFAA8
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::OnActivate(util_entityFlag *this, ssEntity *__formal)
{
  bool v3; // r28
  double v4; // fp8
  double v5; // fp7
  double v6; // fp6
  double v7; // fp5
  double v8; // fp4
  double v9; // fp3
  double v10; // fp2
  float v11; // [sp+8h] [-98h]
  float v12; // [sp+Ch] [-94h]
  float v13; // [sp+10h] [-90h]
  float v14; // [sp+14h] [-8Ch]
  float v15; // [sp+18h] [-88h]
  float v16; // [sp+1Ch] [-84h]
  float v17; // [sp+20h] [-80h]
  float v18; // [sp+24h] [-7Ch]
  ssString v19; // [sp+50h] [-50h] BYREF
  ssString v20[4]; // [sp+60h] [-40h] BYREF

  ssString::Init(this: &v19);
  ssString::operator=(this: &v19, text: "Activate");
  v3 = util_entityFlag::GetIndex(this, name: &v19) != -1;
  ssString::Empty(this: &v19);
  if ( v3 )
  {
    ssString::Init(this: v20);
    ssString::operator=(this: v20, text: "Activate");
    util_entityFlag::Set(
      this,
      name: v20,
      delay: 0.0,
      a4: v10,
      a5: v9,
      a6: v8,
      a7: v7,
      a8: v6,
      a9: v5,
      a10: v4,
      a11: v11,
      a12: v12,
      a13: v13,
      a14: v14,
      a15: v15,
      a16: v16,
      a17: v17,
      a18: v18);
    ssString::Empty(this: v20);
  }
}


// ========================================================================
// __unwind$22113
// EA  : 0x82EEFB3C
// RVA : 0x00EEFB3C
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22113()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$22114
// EA  : 0x82EEFB64
// RVA : 0x00EEFB64
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22114()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?OnTrigger@util_entityFlag@@UAAXVssEntity@@@Z
// EA  : 0x82EEFB98
// RVA : 0x00EEFB98
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::OnTrigger(util_entityFlag *this, ssEntity *__formal)
{
  bool v3; // r28
  double v4; // fp8
  double v5; // fp7
  double v6; // fp6
  double v7; // fp5
  double v8; // fp4
  double v9; // fp3
  double v10; // fp2
  float v11; // [sp+8h] [-98h]
  float v12; // [sp+Ch] [-94h]
  float v13; // [sp+10h] [-90h]
  float v14; // [sp+14h] [-8Ch]
  float v15; // [sp+18h] [-88h]
  float v16; // [sp+1Ch] [-84h]
  float v17; // [sp+20h] [-80h]
  float v18; // [sp+24h] [-7Ch]
  ssString v19; // [sp+50h] [-50h] BYREF
  ssString v20[4]; // [sp+60h] [-40h] BYREF

  ssString::Init(this: &v19);
  ssString::operator=(this: &v19, text: "Trigger");
  v3 = util_entityFlag::GetIndex(this, name: &v19) != -1;
  ssString::Empty(this: &v19);
  if ( v3 )
  {
    ssString::Init(this: v20);
    ssString::operator=(this: v20, text: "Trigger");
    util_entityFlag::Set(
      this,
      name: v20,
      delay: 0.0,
      a4: v10,
      a5: v9,
      a6: v8,
      a7: v7,
      a8: v6,
      a9: v5,
      a10: v4,
      a11: v11,
      a12: v12,
      a13: v13,
      a14: v14,
      a15: v15,
      a16: v16,
      a17: v17,
      a18: v18);
    ssString::Empty(this: v20);
  }
}


// ========================================================================
// __unwind$22157
// EA  : 0x82EEFC2C
// RVA : 0x00EEFC2C
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22157()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$22158
// EA  : 0x82EEFC54
// RVA : 0x00EEFC54
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22158()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?OnAnimNotify@util_entityFlag@@UAAXVssString@@@Z
// EA  : 0x82EEFC88
// RVA : 0x00EEFC88
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::OnAnimNotify(util_entityFlag *this, ssString *message)
{
  int Index; // r3
  double v5; // fp8
  double v6; // fp7
  double v7; // fp6
  double v8; // fp5
  double v9; // fp4
  double v10; // fp3
  double v11; // fp2
  int v12; // r29
  float v13; // [sp+8h] [-78h]
  float v14; // [sp+Ch] [-74h]
  float v15; // [sp+10h] [-70h]
  float v16; // [sp+14h] [-6Ch]
  float v17; // [sp+18h] [-68h]
  float v18; // [sp+1Ch] [-64h]
  float v19; // [sp+20h] [-60h]
  float v20; // [sp+24h] [-5Ch]

  Index = util_entityFlag::GetIndex(this, name: message);
  v12 = Index;
  if ( Index != -1 )
  {
    if ( Index < 0 || Index >= this->flags.num )
      AssertionFailed(msg: "Assertion failed: ( index >= 0 ) && ( index < num )");
    if ( this->flags.data[v12].animNotify )
      util_entityFlag::Set(
        this,
        name: message,
        delay: 0.0,
        a4: v11,
        a5: v10,
        a6: v9,
        a7: v8,
        a8: v7,
        a9: v6,
        a10: v5,
        a11: v13,
        a12: v14,
        a13: v15,
        a14: v16,
        a15: v17,
        a16: v18,
        a17: v19,
        a18: v20);
  }
  ssString::Empty(this: message);
}


// ========================================================================
// __unwind$22198
// EA  : 0x82EEFD14
// RVA : 0x00EEFD14
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22198()
{
  int v0; // r12

  ssString::~ssString(this: *(ssString **)(v0 - 128 + 156));
}


// ========================================================================
// ?OnAnimEnd@util_entityFlag@@UAAXXZ
// EA  : 0x82EEFD48
// RVA : 0x00EEFD48
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::OnAnimEnd(util_entityFlag *this)
{
  bool v2; // r28
  double v3; // fp8
  double v4; // fp7
  double v5; // fp6
  double v6; // fp5
  double v7; // fp4
  double v8; // fp3
  double v9; // fp2
  float v10; // [sp+8h] [-98h]
  float v11; // [sp+Ch] [-94h]
  float v12; // [sp+10h] [-90h]
  float v13; // [sp+14h] [-8Ch]
  float v14; // [sp+18h] [-88h]
  float v15; // [sp+1Ch] [-84h]
  float v16; // [sp+20h] [-80h]
  float v17; // [sp+24h] [-7Ch]
  ssString v18; // [sp+50h] [-50h] BYREF
  ssString v19[4]; // [sp+60h] [-40h] BYREF

  ssString::Init(this: &v18);
  ssString::operator=(this: &v18, text: "AnimEnd");
  v2 = util_entityFlag::GetIndex(this, name: &v18) != -1;
  ssString::Empty(this: &v18);
  if ( v2 )
  {
    ssString::Init(this: v19);
    ssString::operator=(this: v19, text: "AnimEnd");
    util_entityFlag::Set(
      this,
      name: v19,
      delay: 0.0,
      a4: v9,
      a5: v8,
      a6: v7,
      a7: v6,
      a8: v5,
      a9: v4,
      a10: v3,
      a11: v10,
      a12: v11,
      a13: v12,
      a14: v13,
      a15: v14,
      a16: v15,
      a17: v16,
      a18: v17);
    ssString::Empty(this: v19);
  }
}


// ========================================================================
// __unwind$22234
// EA  : 0x82EEFDDC
// RVA : 0x00EEFDDC
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22234()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$22235
// EA  : 0x82EEFE04
// RVA : 0x00EEFE04
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22235()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?OnAnimStart@util_entityFlag@@UAAXXZ
// EA  : 0x82EEFE38
// RVA : 0x00EEFE38
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::OnAnimStart(util_entityFlag *this)
{
  bool v2; // r28
  double v3; // fp8
  double v4; // fp7
  double v5; // fp6
  double v6; // fp5
  double v7; // fp4
  double v8; // fp3
  double v9; // fp2
  float v10; // [sp+8h] [-98h]
  float v11; // [sp+Ch] [-94h]
  float v12; // [sp+10h] [-90h]
  float v13; // [sp+14h] [-8Ch]
  float v14; // [sp+18h] [-88h]
  float v15; // [sp+1Ch] [-84h]
  float v16; // [sp+20h] [-80h]
  float v17; // [sp+24h] [-7Ch]
  ssString v18; // [sp+50h] [-50h] BYREF
  ssString v19[4]; // [sp+60h] [-40h] BYREF

  ssString::Init(this: &v18);
  ssString::operator=(this: &v18, text: "AnimStart");
  v2 = util_entityFlag::GetIndex(this, name: &v18) != -1;
  ssString::Empty(this: &v18);
  if ( v2 )
  {
    ssString::Init(this: v19);
    ssString::operator=(this: v19, text: "AnimStart");
    util_entityFlag::Set(
      this,
      name: v19,
      delay: 0.0,
      a4: v9,
      a5: v8,
      a6: v7,
      a7: v6,
      a8: v5,
      a9: v4,
      a10: v3,
      a11: v10,
      a12: v11,
      a13: v12,
      a14: v13,
      a15: v14,
      a16: v15,
      a17: v16,
      a18: v17);
    ssString::Empty(this: v19);
  }
}


// ========================================================================
// __unwind$22278
// EA  : 0x82EEFECC
// RVA : 0x00EEFECC
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22278()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$22279
// EA  : 0x82EEFEF4
// RVA : 0x00EEFEF4
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22279()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?OnDamage@util_entityFlag@@UAAXVssEntity@@M@Z
// EA  : 0x82EEFF28
// RVA : 0x00EEFF28
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::OnDamage(util_entityFlag *this, ssEntity *__formal, double a3)
{
  bool v4; // r28
  double v5; // fp8
  double v6; // fp7
  double v7; // fp6
  double v8; // fp5
  double v9; // fp4
  double v10; // fp3
  double v11; // fp2
  float v12; // [sp+8h] [-98h]
  float v13; // [sp+Ch] [-94h]
  float v14; // [sp+10h] [-90h]
  float v15; // [sp+14h] [-8Ch]
  float v16; // [sp+18h] [-88h]
  float v17; // [sp+1Ch] [-84h]
  float v18; // [sp+20h] [-80h]
  float v19; // [sp+24h] [-7Ch]
  ssString v20; // [sp+50h] [-50h] BYREF
  ssString v21[4]; // [sp+60h] [-40h] BYREF

  ssString::Init(this: &v20);
  ssString::operator=(this: &v20, text: "Damage");
  v4 = util_entityFlag::GetIndex(this, name: &v20) != -1;
  ssString::Empty(this: &v20);
  if ( v4 )
  {
    ssString::Init(this: v21);
    ssString::operator=(this: v21, text: "Damage");
    util_entityFlag::Set(
      this,
      name: v21,
      delay: 0.0,
      a4: v11,
      a5: v10,
      a6: v9,
      a7: v8,
      a8: v7,
      a9: v6,
      a10: v5,
      a11: v12,
      a12: v13,
      a13: v14,
      a14: v15,
      a15: v16,
      a16: v17,
      a17: v18,
      a18: v19);
    ssString::Empty(this: v21);
  }
}


// ========================================================================
// __unwind$22322
// EA  : 0x82EEFFBC
// RVA : 0x00EEFFBC
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22322()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$22323
// EA  : 0x82EEFFE4
// RVA : 0x00EEFFE4
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22323()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?OnDeath@util_entityFlag@@UAAXVssEntity@@@Z
// EA  : 0x82EF0018
// RVA : 0x00EF0018
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::OnDeath(util_entityFlag *this, ssEntity *__formal)
{
  bool v3; // r28
  double v4; // fp8
  double v5; // fp7
  double v6; // fp6
  double v7; // fp5
  double v8; // fp4
  double v9; // fp3
  double v10; // fp2
  float v11; // [sp+8h] [-98h]
  float v12; // [sp+Ch] [-94h]
  float v13; // [sp+10h] [-90h]
  float v14; // [sp+14h] [-8Ch]
  float v15; // [sp+18h] [-88h]
  float v16; // [sp+1Ch] [-84h]
  float v17; // [sp+20h] [-80h]
  float v18; // [sp+24h] [-7Ch]
  ssString v19; // [sp+50h] [-50h] BYREF
  ssString v20[4]; // [sp+60h] [-40h] BYREF

  ssString::Init(this: &v19);
  ssString::operator=(this: &v19, text: "Death");
  v3 = util_entityFlag::GetIndex(this, name: &v19) != -1;
  ssString::Empty(this: &v19);
  if ( v3 )
  {
    ssString::Init(this: v20);
    ssString::operator=(this: v20, text: "Death");
    util_entityFlag::Set(
      this,
      name: v20,
      delay: 0.0,
      a4: v10,
      a5: v9,
      a6: v8,
      a7: v7,
      a8: v6,
      a9: v5,
      a10: v4,
      a11: v11,
      a12: v12,
      a13: v13,
      a14: v14,
      a15: v15,
      a16: v16,
      a17: v17,
      a18: v18);
    ssString::Empty(this: v20);
  }
}


// ========================================================================
// __unwind$22366
// EA  : 0x82EF00AC
// RVA : 0x00EF00AC
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22366()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$22367
// EA  : 0x82EF00D4
// RVA : 0x00EF00D4
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22367()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?OnLeftGoal@util_entityFlag@@UAAXVssEntity@@@Z
// EA  : 0x82EF0108
// RVA : 0x00EF0108
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::OnLeftGoal(util_entityFlag *this, ssEntity *__formal)
{
  bool v3; // r28
  double v4; // fp8
  double v5; // fp7
  double v6; // fp6
  double v7; // fp5
  double v8; // fp4
  double v9; // fp3
  double v10; // fp2
  float v11; // [sp+8h] [-98h]
  float v12; // [sp+Ch] [-94h]
  float v13; // [sp+10h] [-90h]
  float v14; // [sp+14h] [-8Ch]
  float v15; // [sp+18h] [-88h]
  float v16; // [sp+1Ch] [-84h]
  float v17; // [sp+20h] [-80h]
  float v18; // [sp+24h] [-7Ch]
  ssString v19; // [sp+50h] [-50h] BYREF
  ssString v20[4]; // [sp+60h] [-40h] BYREF

  ssString::Init(this: &v19);
  ssString::operator=(this: &v19, text: "LeftGoal");
  v3 = util_entityFlag::GetIndex(this, name: &v19) != -1;
  ssString::Empty(this: &v19);
  if ( v3 )
  {
    ssString::Init(this: v20);
    ssString::operator=(this: v20, text: "LeftGoal");
    util_entityFlag::Set(
      this,
      name: v20,
      delay: 0.0,
      a4: v10,
      a5: v9,
      a6: v8,
      a7: v7,
      a8: v6,
      a9: v5,
      a10: v4,
      a11: v11,
      a12: v12,
      a13: v13,
      a14: v14,
      a15: v15,
      a16: v16,
      a17: v17,
      a18: v18);
    ssString::Empty(this: v20);
  }
}


// ========================================================================
// __unwind$22410
// EA  : 0x82EF019C
// RVA : 0x00EF019C
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22410()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$22411
// EA  : 0x82EF01C4
// RVA : 0x00EF01C4
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22411()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?OnReachGoal@util_entityFlag@@UAAXVssEntity@@@Z
// EA  : 0x82EF01F8
// RVA : 0x00EF01F8
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::OnReachGoal(util_entityFlag *this, ssEntity *__formal)
{
  bool v3; // r28
  double v4; // fp8
  double v5; // fp7
  double v6; // fp6
  double v7; // fp5
  double v8; // fp4
  double v9; // fp3
  double v10; // fp2
  float v11; // [sp+8h] [-A8h]
  float v12; // [sp+Ch] [-A4h]
  float v13; // [sp+10h] [-A0h]
  float v14; // [sp+14h] [-9Ch]
  float v15; // [sp+18h] [-98h]
  float v16; // [sp+1Ch] [-94h]
  float v17; // [sp+20h] [-90h]
  float v18; // [sp+24h] [-8Ch]
  ssString v19; // [sp+50h] [-60h] BYREF
  ssString v20; // [sp+60h] [-50h] BYREF
  ssString v21[4]; // [sp+70h] [-40h] BYREF

  ssString::Init(this: &v19);
  ssString::operator=(this: &v19, text: "On Goal Reach has been hit");
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v19.data);
  ssString::Empty(this: &v19);
  ssString::Init(this: &v20);
  ssString::operator=(this: &v20, text: "ReachGoal");
  v3 = util_entityFlag::GetIndex(this, name: &v20) != -1;
  ssString::Empty(this: &v20);
  if ( v3 )
  {
    ssString::Init(this: v21);
    ssString::operator=(this: v21, text: "ReachGoal");
    util_entityFlag::Set(
      this,
      name: v21,
      delay: 0.0,
      a4: v10,
      a5: v9,
      a6: v8,
      a7: v7,
      a8: v6,
      a9: v5,
      a10: v4,
      a11: v11,
      a12: v12,
      a13: v13,
      a14: v14,
      a15: v15,
      a16: v16,
      a17: v17,
      a18: v18);
    ssString::Empty(this: v21);
  }
}


// ========================================================================
// __unwind$22455
// EA  : 0x82EF02D0
// RVA : 0x00EF02D0
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22455()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$22456
// EA  : 0x82EF02F8
// RVA : 0x00EF02F8
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22456()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$22457
// EA  : 0x82EF0320
// RVA : 0x00EF0320
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22457()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 112));
}


// ========================================================================
// ?OnGoalReach@util_entityFlag@@UAAXVssEntity@@@Z
// EA  : 0x82EF0350
// RVA : 0x00EF0350
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::OnGoalReach(util_entityFlag *this, ssEntity *__formal)
{
  bool v3; // r28
  double v4; // fp8
  double v5; // fp7
  double v6; // fp6
  double v7; // fp5
  double v8; // fp4
  double v9; // fp3
  double v10; // fp2
  float v11; // [sp+8h] [-98h]
  float v12; // [sp+Ch] [-94h]
  float v13; // [sp+10h] [-90h]
  float v14; // [sp+14h] [-8Ch]
  float v15; // [sp+18h] [-88h]
  float v16; // [sp+1Ch] [-84h]
  float v17; // [sp+20h] [-80h]
  float v18; // [sp+24h] [-7Ch]
  ssString v19; // [sp+50h] [-50h] BYREF
  ssString v20[4]; // [sp+60h] [-40h] BYREF

  ssString::Init(this: &v19);
  ssString::operator=(this: &v19, text: "GoalReach");
  v3 = util_entityFlag::GetIndex(this, name: &v19) != -1;
  ssString::Empty(this: &v19);
  if ( v3 )
  {
    ssString::Init(this: v20);
    ssString::operator=(this: v20, text: "GoalReach");
    util_entityFlag::Set(
      this,
      name: v20,
      delay: 0.0,
      a4: v10,
      a5: v9,
      a6: v8,
      a7: v7,
      a8: v6,
      a9: v5,
      a10: v4,
      a11: v11,
      a12: v12,
      a13: v13,
      a14: v14,
      a15: v15,
      a16: v16,
      a17: v17,
      a18: v18);
    ssString::Empty(this: v20);
  }
}


// ========================================================================
// __unwind$22531
// EA  : 0x82EF03E4
// RVA : 0x00EF03E4
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22531()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$22532
// EA  : 0x82EF040C
// RVA : 0x00EF040C
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_22532()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?OnActivate@util_entityFlagActivate@@UAAXVssEntity@@@Z
// EA  : 0x82EF07E8
// RVA : 0x00EF07E8
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlagActivate::OnActivate(util_entityFlagActivate *this, ssEntity *__formal)
{
  int count; // r10
  int v4; // r11
  int spawnId; // r30
  int *v6; // r3
  void *v7; // r3
  util_entityFlagActivate::activateBehavior_t activateBehavior; // r11
  ssEntity v9; // [sp+50h] [-30h] BYREF
  ssObject<util_entityFlag> v10[5]; // [sp+58h] [-28h] BYREF

  count = this->count;
  if ( count <= 0 || (v4 = this->activatedCount + 1, this->activatedCount = v4, v4 <= count) )
  {
    ssEntity::ssEntity(this: &v9, e: &this->target);
    v10[0].spawnId = *v6;
    spawnId = v10[0].spawnId;
    v10[0].objectId = gameInterface->FindObject(
                        this: gameInterface,
                        a2: v10[0].spawnId,
                        a3: "util_entityFlag",
                        a4: false);
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
      activateBehavior = this->activateBehavior;
      if ( activateBehavior != UNCHANGED )
      {
        if ( activateBehavior == SET )
        {
          ssObject<util_entityFlag>::Clear(this: v10, names: &this->activateFlags, delay: this->delay);
        }
        else if ( (unsigned int)activateBehavior < 3 )
        {
          ssObject<util_entityFlag>::Toggle(this: v10, names: &this->activateFlags, delay: this->delay);
        }
      }
      else
      {
        ssObject<util_entityFlag>::Set(this: v10, names: &this->activateFlags, delay: this->delay);
      }
    }
  }
}


// ========================================================================
// ?Define@util_entityFlag@@QAAXABVssString@@_N1@Z
// EA  : 0x82EF0E48
// RVA : 0x00EF0E48
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void __fastcall util_entityFlag::Define(util_entityFlag *this, const ssString *name, bool animNotify, bool state)
{
  ssEntity *v8; // r30
  ssString *v9; // r3
  const ssString *v10; // r3
  const ssString *v11; // r3
  ssString v12; // [sp+50h] [-B0h] BYREF
  ssString v13; // [sp+60h] [-A0h] BYREF
  ssString v14; // [sp+70h] [-90h] BYREF
  ssString v15; // [sp+80h] [-80h] BYREF
  util_entityFlag::flagDef_t v16; // [sp+90h] [-70h] BYREF

  if ( util_entityFlag::GetIndex(this, name) == -1 )
  {
    util_entityFlag::flagDef_t::flagDef_t(this: &v16);
    ssString::operator=(this: &v16.name, text: name);
    v16.animNotify = animNotify;
    v16.state = state;
    ssList<util_entityFlag::flagDef_t>::Insert(this: &this->flags, element: &v16, index: this->flags.num);
    util_entityFlag::flagDef_t::~flagDef_t(this: &v16);
  }
  else
  {
    v8 = ssEntity::Name(this: (ssEntity *)&v15, result: (ssString *)&this->self);
    v9 = operator+(result: &v14, a: "Flag name: ", b: name);
    v10 = operator+(result: &v13, a: v9, b: " is already defined on entity: ");
    v11 = operator+(result: &v12, a: v10, b: (const ssString *)v8);
    Warning(msg: v11);
    ssString::Empty(this: &v12);
    ssString::Empty(this: &v13);
    ssString::Empty(this: &v14);
    ssString::Empty(this: &v15);
  }
}


// ========================================================================
// __unwind$23544
// EA  : 0x82EF0F20
// RVA : 0x00EF0F20
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_23544()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$23545
// EA  : 0x82EF0F48
// RVA : 0x00EF0F48
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_23545()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$23546
// EA  : 0x82EF0F70
// RVA : 0x00EF0F70
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_23546()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$23547
// EA  : 0x82EF0F98
// RVA : 0x00EF0F98
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_23547()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$23548
// EA  : 0x82EF0FC0
// RVA : 0x00EF0FC0
// PDB : w:\tech5\tungsten\superscript\util\entityflag.cpp
// ========================================================================

void _unwind_23548()
{
  int v0; // r12

  util_entityFlag::flagDef_t::~flagDef_t(this: (util_entityFlag::flagDef_t *)(v0 - 256 + 144));
}

