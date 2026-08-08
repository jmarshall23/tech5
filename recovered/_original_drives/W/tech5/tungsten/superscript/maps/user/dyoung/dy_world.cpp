
// ========================================================================
// ?Update@dy_world@@QAAXXZ
// EA  : 0x82EE8CD8
// RVA : 0x00EE8CD8
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void __fastcall dy_world::Update(dy_world *this)
{
  XGRAPHICS::Compiler *v1; // r3
  char v2; // [sp+50h] [-10h] BYREF

  v1 = (XGRAPHICS::Compiler *)gameInterface->SpawnFromDecl(this: gameInterface, a2: this->speakerDecl);
  ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v2, context: v1);
  ssUtil::SetWorkingResolution(this: &ssUtil, screenX: 1680.0, screenY: 1050.0);
}


// ========================================================================
// ?Init@aiObjectTest@@UAAXXZ
// EA  : 0x82EE8D40
// RVA : 0x00EE8D40
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void __fastcall aiObjectTest::Init(aiObjectTest *this)
{
  ssEntity *p_self; // r30
  ssEntity *v2; // r29
  ssString *v3; // r3
  ssEntity *v4; // r30
  ssString *v5; // r3
  ssString v6; // [sp+50h] [-90h] BYREF
  ssString v7; // [sp+60h] [-80h] BYREF
  ssString v8; // [sp+70h] [-70h] BYREF
  ssString v9; // [sp+80h] [-60h] BYREF
  ssString v10; // [sp+90h] [-50h] BYREF
  ssString v11[4]; // [sp+A0h] [-40h] BYREF

  p_self = &this->self;
  v2 = ssEntity::Name(this: (ssEntity *)&v9, result: (ssString *)&this->self);
  ssString::Init(this: &v6);
  ssString::operator=(this: &v6, text: "Starting aiObjectTest on ");
  v3 = operator+(result: &v8, a: &v6, b: (const ssString *)v2);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v3->data);
  ssString::Empty(this: &v8);
  ssString::Empty(this: &v6);
  ssString::Empty(this: &v9);
  v4 = ssEntity::Name(this: (ssEntity *)v11, result: (ssString *)p_self);
  ssString::Init(this: &v7);
  ssString::operator=(this: &v7, text: "Completed aiObjectTest on ");
  v5 = operator+(result: &v10, a: &v7, b: (const ssString *)v4);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v5->data);
  ssString::Empty(this: &v10);
  ssString::Empty(this: &v7);
  ssString::Empty(this: v11);
}


// ========================================================================
// __unwind$19502
// EA  : 0x82EE8E44
// RVA : 0x00EE8E44
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void _unwind_19502()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 128));
}


// ========================================================================
// __unwind$19503
// EA  : 0x82EE8E6C
// RVA : 0x00EE8E6C
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void _unwind_19503()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$19504
// EA  : 0x82EE8E94
// RVA : 0x00EE8E94
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void _unwind_19504()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 112));
}


// ========================================================================
// __unwind$19505
// EA  : 0x82EE8EBC
// RVA : 0x00EE8EBC
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void _unwind_19505()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 160));
}


// ========================================================================
// __unwind$19506
// EA  : 0x82EE8EE4
// RVA : 0x00EE8EE4
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void _unwind_19506()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$19507
// EA  : 0x82EE8F0C
// RVA : 0x00EE8F0C
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void _unwind_19507()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 144));
}


// ========================================================================
// ?OnDamage@aiObjectTest@@UAAXVssEntity@@M@Z
// EA  : 0x82EE8F40
// RVA : 0x00EE8F40
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void __fastcall aiObjectTest::OnDamage(aiObjectTest *this, ssString *attacker, double damage)
{
  ssString *v5; // r28
  ssEntity *v6; // r30
  const ssString *v7; // r3
  const ssString *v8; // r3
  ssString *v9; // r3
  ssEntity *p_goalEnt; // r28
  char v11; // r3
  char v12; // r11
  ssEntity *p_self; // r29
  ssEntity *v14; // r3
  ssString v15; // [sp+50h] [-C0h] BYREF
  ssString v16; // [sp+60h] [-B0h] BYREF
  ssEntity v17; // [sp+70h] [-A0h] BYREF
  ssString v18; // [sp+80h] [-90h] BYREF
  ssString v19; // [sp+90h] [-80h] BYREF
  ssString v20; // [sp+A0h] [-70h] BYREF
  ssString v21; // [sp+B0h] [-60h] BYREF
  ssString v22; // [sp+C0h] [-50h] BYREF
  ssString v23[4]; // [sp+D0h] [-40h] BYREF

  v5 = ssString::ssString(this: v23, f: damage, precision: (int)attacker, a4: 3);
  ssString::Init(this: &v16);
  ssString::operator=(this: &v16, text: " did ");
  v6 = ssEntity::Name(this: (ssEntity *)&v21, result: attacker);
  ssString::Init(this: &v15);
  ssString::operator=(this: &v15, text: "OMG it hurt!!! ");
  v7 = operator+(result: &v20, a: &v15, b: (const ssString *)v6);
  v8 = operator+(result: &v22, a: v7, b: &v16);
  v9 = operator+(result: &v19, a: v8, b: v5);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v9->data);
  ssString::Empty(this: &v19);
  ssString::Empty(this: &v22);
  ssString::Empty(this: &v20);
  ssString::Empty(this: &v15);
  ssString::Empty(this: &v21);
  ssString::Empty(this: &v16);
  ssString::Empty(this: v23);
  p_goalEnt = &this->goalEnt;
  if ( this->goalEnt.spawnId == 0
    || (v11 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
        v12 = 1,
        v11 == 0) )
  {
    v12 = 0;
  }
  if ( v12 != 0 )
  {
    p_self = &this->self;
    ssEntity::Action_EnablePain(this: p_self, enabled: 0);
    ssEntity::ssEntity(this: &v17, e: p_goalEnt);
    ssEntity::Action_MoveToPathPointNoFail(this: p_self, pathPoint: v14, declVoiceOver: nullptr);
  }
  ssString::Init(this: &v18);
  ssString::operator=(this: &v18, text: "Done avoiding damage");
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v18.data);
  ssString::Empty(this: &v18);
}


// ========================================================================
// __unwind$19631
// EA  : 0x82EE90EC
// RVA : 0x00EE90EC
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void _unwind_19631()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 272 + 208));
}


// ========================================================================
// __unwind$19632
// EA  : 0x82EE9114
// RVA : 0x00EE9114
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void _unwind_19632()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$19633
// EA  : 0x82EE913C
// RVA : 0x00EE913C
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void _unwind_19633()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 272 + 176));
}


// ========================================================================
// __unwind$19634
// EA  : 0x82EE9164
// RVA : 0x00EE9164
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void _unwind_19634()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$19635
// EA  : 0x82EE918C
// RVA : 0x00EE918C
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void _unwind_19635()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 272 + 160));
}


// ========================================================================
// __unwind$19636
// EA  : 0x82EE91B4
// RVA : 0x00EE91B4
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void _unwind_19636()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 272 + 192));
}


// ========================================================================
// __unwind$19637
// EA  : 0x82EE91DC
// RVA : 0x00EE91DC
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void _unwind_19637()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 272 + 144));
}


// ========================================================================
// __unwind$19638
// EA  : 0x82EE9204
// RVA : 0x00EE9204
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void _unwind_19638()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 272 + 128));
}


// ========================================================================
// ?Init@dy_world@@UAAXXZ
// EA  : 0x82EE9230
// RVA : 0x00EE9230
// PDB : w:\tech5\tungsten\superscript\maps\user\dyoung\dy_world.cpp
// ========================================================================

void __fastcall dy_world::Init(dy_world *this)
{
  ssString v2; // [sp+50h] [-20h] BYREF

  ssUtil::Init(this: &ssUtil);
  gameInterface->Wait(this: gameInterface, a2: 1.0);
  ssString::Init(this: &v2);
  ssString::operator=(this: &v2, text: "Update");
  idSuperScriptObject::CreateThreadNamed(this, threadName: &v2, f: dy_world::Update);
}

