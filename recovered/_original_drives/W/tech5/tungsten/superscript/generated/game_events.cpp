
// ========================================================================
// ?Remove@ssEntity@@QAAXXZ
// EA  : 0x82EDE8E8
// RVA : 0x00EDE8E8
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void __fastcall ssEntity::Remove(ssEntity *this)
{
  ssEntity *v2; // r3
  const ssString *v3; // r3
  ssString v4; // [sp+50h] [-40h] BYREF
  ssString v5; // [sp+60h] [-30h] BYREF

  if ( !gameInterface->EventCall(this: gameInterface, a2: this->spawnId, a3: 0, a4: &byte_8200D768, a5: nullptr) )
  {
    v2 = ssEntity::Name(this: (ssEntity *)&v5, result: (ssString *)this);
    v3 = operator+(result: &v4, a: (const ssString *)v2, b: ".Remove failed.");
    Warning(msg: v3);
    ssString::Empty(this: &v4);
    ssString::Empty(this: &v5);
  }
}


// ========================================================================
// __unwind$25959
// EA  : 0x82EDE988
// RVA : 0x00EDE988
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_25959()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$25960
// EA  : 0x82EDE9B0
// RVA : 0x00EDE9B0
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_25960()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 144 + 80));
}


// ========================================================================
// ?Activate@ssEntity@@QBAXV1@@Z
// EA  : 0x82EDE9E0
// RVA : 0x00EDE9E0
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void __fastcall ssEntity::Activate(ssEntity *this, ssEntity *activator)
{
  int spawnId; // r11
  int v3; // r4
  ssEntity *v5; // r3
  const ssString *v6; // r3
  int v7[4]; // [sp+50h] [-50h] BYREF
  ssString v8; // [sp+60h] [-40h] BYREF
  ssString v9; // [sp+70h] [-30h] BYREF

  spawnId = activator->spawnId;
  v3 = this->spawnId;
  v7[0] = spawnId;
  if ( !gameInterface->EventCall(this: gameInterface, a2: v3, a3: 71, a4: "e", a5: (ssVarg_t *)v7) )
  {
    v5 = ssEntity::Name(this: (ssEntity *)&v9, result: (ssString *)this);
    v6 = operator+(result: &v8, a: (const ssString *)v5, b: ".Activate failed.");
    Warning(msg: v6);
    ssString::Empty(this: &v8);
    ssString::Empty(this: &v9);
  }
}


// ========================================================================
// __unwind$26148
// EA  : 0x82EDEA88
// RVA : 0x00EDEA88
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_26148()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$26149
// EA  : 0x82EDEAB0
// RVA : 0x00EDEAB0
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_26149()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?ActivateTargets@ssEntity@@QBAXV1@@Z
// EA  : 0x82EDEAE0
// RVA : 0x00EDEAE0
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void __fastcall ssEntity::ActivateTargets(ssEntity *this, ssEntity *activator)
{
  int spawnId; // r11
  int v3; // r4
  ssEntity *v5; // r3
  const ssString *v6; // r3
  int v7[4]; // [sp+50h] [-50h] BYREF
  ssString v8; // [sp+60h] [-40h] BYREF
  ssString v9; // [sp+70h] [-30h] BYREF

  spawnId = activator->spawnId;
  v3 = this->spawnId;
  v7[0] = spawnId;
  if ( !gameInterface->EventCall(this: gameInterface, a2: v3, a3: 72, a4: "e", a5: (ssVarg_t *)v7) )
  {
    v5 = ssEntity::Name(this: (ssEntity *)&v9, result: (ssString *)this);
    v6 = operator+(result: &v8, a: (const ssString *)v5, b: ".ActivateTargets failed.");
    Warning(msg: v6);
    ssString::Empty(this: &v8);
    ssString::Empty(this: &v9);
  }
}


// ========================================================================
// __unwind$26187
// EA  : 0x82EDEB88
// RVA : 0x00EDEB88
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_26187()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$26188
// EA  : 0x82EDEBB0
// RVA : 0x00EDEBB0
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_26188()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?NumTargets@ssEntity@@QAAMXZ
// EA  : 0x82EDEBE0
// RVA : 0x00EDEBE0
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

float __fastcall ssEntity::NumTargets(ssEntity *this)
{
  double v2; // fp1
  ssEntity *v3; // r3
  const ssString *v4; // r3
  ssString v6; // [sp+50h] [-40h] BYREF
  ssString v7[3]; // [sp+60h] [-30h] BYREF

  if ( gameInterface->EventCall(this: gameInterface, a2: this->spawnId, a3: 75, a4: &byte_8200D768, a5: nullptr) )
  {
    gameInterface->EventGetReturnFloat(this: gameInterface);
  }
  else
  {
    v3 = ssEntity::Name(this: (ssEntity *)v7, result: (ssString *)this);
    v4 = operator+(result: &v6, a: (const ssString *)v3, b: ".NumTargets failed.");
    Warning(msg: v4);
    ssString::Empty(this: &v6);
    ssString::Empty(this: v7);
    v2 = 0.0;
  }
  return *((float *)&v2 + 1);
}


// ========================================================================
// __unwind$26294
// EA  : 0x82EDEC88
// RVA : 0x00EDEC88
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_26294()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$26295
// EA  : 0x82EDECB0
// RVA : 0x00EDECB0
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_26295()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 144 + 80));
}


// ========================================================================
// ?GetTarget@ssEntity@@QBA?AV1@M@Z
// EA  : 0x82EDECE0
// RVA : 0x00EDECE0
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

ssEntity *__fastcall ssEntity::GetTarget(ssEntity *this, ssString *result, double index)
{
  XGRAPHICS::Compiler *v5; // r4
  ssEntity *v6; // r3
  const ssString *v7; // r3
  float v9; // [sp+50h] [-60h] BYREF
  ssString v10; // [sp+60h] [-50h] BYREF
  ssString v11[4]; // [sp+70h] [-40h] BYREF

  v9 = index;
  if ( gameInterface->EventCall(this: gameInterface, a2: result->len, a3: 76, a4: "f", a5: (ssVarg_t *)&v9) )
  {
    v5 = (XGRAPHICS::Compiler *)gameInterface->EventGetReturnInt(this: gameInterface);
  }
  else
  {
    v6 = ssEntity::Name(this: (ssEntity *)v11, result);
    v7 = operator+(result: &v10, a: (const ssString *)v6, b: ".GetTarget failed.");
    Warning(msg: v7);
    ssString::Empty(this: &v10);
    ssString::Empty(this: v11);
    v5 = nullptr;
  }
  ssEntity::ssEntity((XGRAPHICS::VRegTable *)this, context: v5);
  return this;
}


// ========================================================================
// __unwind$26329
// EA  : 0x82EDED9C
// RVA : 0x00EDED9C
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_26329()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$26330
// EA  : 0x82EDEDC4
// RVA : 0x00EDEDC4
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_26330()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?RemoveTarget@ssEntity@@QBA_NV1@@Z
// EA  : 0x82EDEDF8
// RVA : 0x00EDEDF8
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

BOOL __fastcall ssEntity::RemoveTarget(ssEntity *this, ssEntity *target)
{
  int spawnId; // r11
  int v3; // r4
  ssEntity *v6; // r3
  const ssString *v7; // r3
  int v8[4]; // [sp+50h] [-50h] BYREF
  ssString v9; // [sp+60h] [-40h] BYREF
  ssString v10[3]; // [sp+70h] [-30h] BYREF

  spawnId = target->spawnId;
  v3 = this->spawnId;
  v8[0] = spawnId;
  if ( gameInterface->EventCall(this: gameInterface, a2: v3, a3: 77, a4: "e", a5: (ssVarg_t *)v8) )
    return gameInterface->EventGetReturnInt(this: gameInterface) != 0;
  v6 = ssEntity::Name(this: (ssEntity *)v10, result: (ssString *)this);
  v7 = operator+(result: &v9, a: (const ssString *)v6, b: ".RemoveTarget failed.");
  Warning(msg: v7);
  ssString::Empty(this: &v9);
  ssString::Empty(this: v10);
  return false;
}


// ========================================================================
// __unwind$26366
// EA  : 0x82EDEEAC
// RVA : 0x00EDEEAC
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_26366()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$26367
// EA  : 0x82EDEED4
// RVA : 0x00EDEED4
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_26367()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?AddTarget@ssEntity@@QBAXV1@@Z
// EA  : 0x82EDEF08
// RVA : 0x00EDEF08
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void __fastcall ssEntity::AddTarget(ssEntity *this, ssEntity *target)
{
  int spawnId; // r11
  int v3; // r4
  ssEntity *v5; // r3
  const ssString *v6; // r3
  int v7[4]; // [sp+50h] [-50h] BYREF
  ssString v8; // [sp+60h] [-40h] BYREF
  ssString v9; // [sp+70h] [-30h] BYREF

  spawnId = target->spawnId;
  v3 = this->spawnId;
  v7[0] = spawnId;
  if ( !gameInterface->EventCall(this: gameInterface, a2: v3, a3: 78, a4: "e", a5: (ssVarg_t *)v7) )
  {
    v5 = ssEntity::Name(this: (ssEntity *)&v9, result: (ssString *)this);
    v6 = operator+(result: &v8, a: (const ssString *)v5, b: ".AddTarget failed.");
    Warning(msg: v6);
    ssString::Empty(this: &v8);
    ssString::Empty(this: &v9);
  }
}


// ========================================================================
// __unwind$26406
// EA  : 0x82EDEFB0
// RVA : 0x00EDEFB0
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_26406()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$26407
// EA  : 0x82EDEFD8
// RVA : 0x00EDEFD8
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_26407()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?StartSoundShader@ssEntity@@QBAMPAVidSoundShader@@H@Z
// EA  : 0x82EDF008
// RVA : 0x00EDF008
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

float __fastcall ssEntity::StartSoundShader(ssEntity *this, idSoundShader *shader, int channel)
{
  double v4; // fp1
  ssEntity *v5; // r3
  const ssString *v6; // r3
  ssString v8; // [sp+50h] [-60h] BYREF
  ssString v9; // [sp+60h] [-50h] BYREF
  _DWORD v10[16]; // [sp+70h] [-40h] BYREF

  v10[0] = shader;
  v10[4] = channel;
  if ( gameInterface->EventCall(this: gameInterface, a2: this->spawnId, a3: 109, a4: "di", a5: (ssVarg_t *)v10) )
  {
    gameInterface->EventGetReturnFloat(this: gameInterface);
  }
  else
  {
    v5 = ssEntity::Name(this: (ssEntity *)&v9, result: (ssString *)this);
    v6 = operator+(result: &v8, a: (const ssString *)v5, b: ".StartSoundShader failed.");
    Warning(msg: v6);
    ssString::Empty(this: &v8);
    ssString::Empty(this: &v9);
    v4 = 0.0;
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// __unwind$27650
// EA  : 0x82EDF0B8
// RVA : 0x00EDF0B8
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_27650()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$27651
// EA  : 0x82EDF0E0
// RVA : 0x00EDF0E0
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_27651()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 80));
}


// ========================================================================
// ?StopSound@ssEntity@@QBAXHH@Z
// EA  : 0x82EDF110
// RVA : 0x00EDF110
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void __fastcall ssEntity::StopSound(ssEntity *this, int channel, int netSync)
{
  ssEntity *v4; // r3
  const ssString *v5; // r3
  ssString v6; // [sp+50h] [-60h] BYREF
  ssString v7; // [sp+60h] [-50h] BYREF
  _DWORD v8[10]; // [sp+70h] [-40h] BYREF

  v8[0] = channel;
  v8[4] = netSync;
  if ( !gameInterface->EventCall(this: gameInterface, a2: this->spawnId, a3: 110, a4: "ii", a5: (ssVarg_t *)v8) )
  {
    v4 = ssEntity::Name(this: (ssEntity *)&v7, result: (ssString *)this);
    v5 = operator+(result: &v6, a: (const ssString *)v4, b: ".StopSound failed.");
    Warning(msg: v5);
    ssString::Empty(this: &v6);
    ssString::Empty(this: &v7);
  }
}


// ========================================================================
// __unwind$27689
// EA  : 0x82EDF1B8
// RVA : 0x00EDF1B8
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_27689()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$27690
// EA  : 0x82EDF1E0
// RVA : 0x00EDF1E0
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_27690()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 80));
}


// ========================================================================
// ?FadeSound@ssEntity@@QBAXHMM@Z
// EA  : 0x82EDF210
// RVA : 0x00EDF210
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void __fastcall ssEntity::FadeSound(ssEntity *this, int channel, double to, double over)
{
  ssEntity *v5; // r3
  const ssString *v6; // r3
  ssString v7; // [sp+50h] [-70h] BYREF
  ssString v8; // [sp+60h] [-60h] BYREF
  float v9[14]; // [sp+70h] [-50h] BYREF

  LODWORD(v9[0]) = channel;
  v9[4] = to;
  v9[8] = over;
  if ( !gameInterface->EventCall(this: gameInterface, a2: this->spawnId, a3: 111, a4: "iff", a5: (ssVarg_t *)v9) )
  {
    v5 = ssEntity::Name(this: (ssEntity *)&v8, result: (ssString *)this);
    v6 = operator+(result: &v7, a: (const ssString *)v5, b: ".FadeSound failed.");
    Warning(msg: v6);
    ssString::Empty(this: &v7);
    ssString::Empty(this: &v8);
  }
}


// ========================================================================
// __unwind$27727
// EA  : 0x82EDF2BC
// RVA : 0x00EDF2BC
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_27727()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$27728
// EA  : 0x82EDF2E4
// RVA : 0x00EDF2E4
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_27728()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 80));
}


// ========================================================================
// ?GetWorldOrigin@ssEntity@@QAA?AVssVector@@XZ
// EA  : 0x82EDF318
// RVA : 0x00EDF318
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

ssEntity *__fastcall ssEntity::GetWorldOrigin(ssEntity *this, ssString *result)
{
  double v4; // fp12
  double v5; // fp0
  ssEntity *v6; // r3
  const ssString *v7; // r3
  float v9[4]; // [sp+50h] [-60h] BYREF
  ssString v10; // [sp+60h] [-50h] BYREF
  ssString v11[4]; // [sp+70h] [-40h] BYREF

  if ( gameInterface->EventCall(this: gameInterface, a2: result->len, a3: 116, a4: &byte_8200D768, a5: nullptr) )
  {
    gameInterface->EventGetReturnVector(this: gameInterface, a2: (ssVec3_t *)v9);
    v4 = v9[2];
    v5 = v9[0];
    *(this + 1) = LODWORD(v9[1]);
    *((float *)this + 2) = v4;
  }
  else
  {
    v6 = ssEntity::Name(this: (ssEntity *)v11, result);
    v7 = operator+(result: &v10, a: (const ssString *)v6, b: ".GetWorldOrigin failed.");
    Warning(msg: v7);
    ssString::Empty(this: &v10);
    ssString::Empty(this: v11);
    v5 = 0.0;
    *((float *)this + 1) = 0.0;
    *((float *)this + 2) = 0.0;
  }
  *(float *)&this->spawnId = v5;
  return this;
}


// ========================================================================
// __unwind$27910
// EA  : 0x82EDF3EC
// RVA : 0x00EDF3EC
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_27910()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$27911
// EA  : 0x82EDF414
// RVA : 0x00EDF414
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_27911()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?GetOrigin@ssEntity@@QAA?AVssVector@@XZ
// EA  : 0x82EDF448
// RVA : 0x00EDF448
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

ssEntity *__fastcall ssEntity::GetOrigin(ssEntity *this, ssString *result)
{
  double v4; // fp12
  double v5; // fp0
  ssEntity *v6; // r3
  const ssString *v7; // r3
  float v9[4]; // [sp+50h] [-60h] BYREF
  ssString v10; // [sp+60h] [-50h] BYREF
  ssString v11[4]; // [sp+70h] [-40h] BYREF

  if ( gameInterface->EventCall(this: gameInterface, a2: result->len, a3: 118, a4: &byte_8200D768, a5: nullptr) )
  {
    gameInterface->EventGetReturnVector(this: gameInterface, a2: (ssVec3_t *)v9);
    v4 = v9[2];
    v5 = v9[0];
    *(this + 1) = LODWORD(v9[1]);
    *((float *)this + 2) = v4;
  }
  else
  {
    v6 = ssEntity::Name(this: (ssEntity *)v11, result);
    v7 = operator+(result: &v10, a: (const ssString *)v6, b: ".GetOrigin failed.");
    Warning(msg: v7);
    ssString::Empty(this: &v10);
    ssString::Empty(this: v11);
    v5 = 0.0;
    *((float *)this + 1) = 0.0;
    *((float *)this + 2) = 0.0;
  }
  *(float *)&this->spawnId = v5;
  return this;
}


// ========================================================================
// __unwind$27993
// EA  : 0x82EDF51C
// RVA : 0x00EDF51C
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_27993()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$27994
// EA  : 0x82EDF544
// RVA : 0x00EDF544
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_27994()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?GetAngles@ssEntity@@QAA?AVssVector@@XZ
// EA  : 0x82EDF578
// RVA : 0x00EDF578
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

ssEntity *__fastcall ssEntity::GetAngles(ssEntity *this, ssString *result)
{
  double v4; // fp12
  double v5; // fp0
  ssEntity *v6; // r3
  const ssString *v7; // r3
  float v9[4]; // [sp+50h] [-60h] BYREF
  ssString v10; // [sp+60h] [-50h] BYREF
  ssString v11[4]; // [sp+70h] [-40h] BYREF

  if ( gameInterface->EventCall(this: gameInterface, a2: result->len, a3: 120, a4: &byte_8200D768, a5: nullptr) )
  {
    gameInterface->EventGetReturnVector(this: gameInterface, a2: (ssVec3_t *)v9);
    v4 = v9[2];
    v5 = v9[0];
    *(this + 1) = LODWORD(v9[1]);
    *((float *)this + 2) = v4;
  }
  else
  {
    v6 = ssEntity::Name(this: (ssEntity *)v11, result);
    v7 = operator+(result: &v10, a: (const ssString *)v6, b: ".GetAngles failed.");
    Warning(msg: v7);
    ssString::Empty(this: &v10);
    ssString::Empty(this: v11);
    v5 = 0.0;
    *((float *)this + 1) = 0.0;
    *((float *)this + 2) = 0.0;
  }
  *(float *)&this->spawnId = v5;
  return this;
}


// ========================================================================
// __unwind$28076
// EA  : 0x82EDF64C
// RVA : 0x00EDF64C
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_28076()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$28077
// EA  : 0x82EDF674
// RVA : 0x00EDF674
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_28077()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?GetMins@ssEntity@@QAA?AVssVector@@XZ
// EA  : 0x82EDF6A8
// RVA : 0x00EDF6A8
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

ssEntity *__fastcall ssEntity::GetMins(ssEntity *this, ssString *result)
{
  double v4; // fp12
  double v5; // fp0
  ssEntity *v6; // r3
  const ssString *v7; // r3
  float v9[4]; // [sp+50h] [-60h] BYREF
  ssString v10; // [sp+60h] [-50h] BYREF
  ssString v11[4]; // [sp+70h] [-40h] BYREF

  if ( gameInterface->EventCall(this: gameInterface, a2: result->len, a3: 128, a4: &byte_8200D768, a5: nullptr) )
  {
    gameInterface->EventGetReturnVector(this: gameInterface, a2: (ssVec3_t *)v9);
    v4 = v9[2];
    v5 = v9[0];
    *(this + 1) = LODWORD(v9[1]);
    *((float *)this + 2) = v4;
  }
  else
  {
    v6 = ssEntity::Name(this: (ssEntity *)v11, result);
    v7 = operator+(result: &v10, a: (const ssString *)v6, b: ".GetMins failed.");
    Warning(msg: v7);
    ssString::Empty(this: &v10);
    ssString::Empty(this: v11);
    v5 = 0.0;
    *((float *)this + 1) = 0.0;
    *((float *)this + 2) = 0.0;
  }
  *(float *)&this->spawnId = v5;
  return this;
}


// ========================================================================
// __unwind$28411
// EA  : 0x82EDF77C
// RVA : 0x00EDF77C
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_28411()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$28412
// EA  : 0x82EDF7A4
// RVA : 0x00EDF7A4
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_28412()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?GetMaxs@ssEntity@@QAA?AVssVector@@XZ
// EA  : 0x82EDF7D8
// RVA : 0x00EDF7D8
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

ssEntity *__fastcall ssEntity::GetMaxs(ssEntity *this, ssString *result)
{
  double v4; // fp12
  double v5; // fp0
  ssEntity *v6; // r3
  const ssString *v7; // r3
  float v9[4]; // [sp+50h] [-60h] BYREF
  ssString v10; // [sp+60h] [-50h] BYREF
  ssString v11[4]; // [sp+70h] [-40h] BYREF

  if ( gameInterface->EventCall(this: gameInterface, a2: result->len, a3: 129, a4: &byte_8200D768, a5: nullptr) )
  {
    gameInterface->EventGetReturnVector(this: gameInterface, a2: (ssVec3_t *)v9);
    v4 = v9[2];
    v5 = v9[0];
    *(this + 1) = LODWORD(v9[1]);
    *((float *)this + 2) = v4;
  }
  else
  {
    v6 = ssEntity::Name(this: (ssEntity *)v11, result);
    v7 = operator+(result: &v10, a: (const ssString *)v6, b: ".GetMaxs failed.");
    Warning(msg: v7);
    ssString::Empty(this: &v10);
    ssString::Empty(this: v11);
    v5 = 0.0;
    *((float *)this + 1) = 0.0;
    *((float *)this + 2) = 0.0;
  }
  *(float *)&this->spawnId = v5;
  return this;
}


// ========================================================================
// __unwind$28454
// EA  : 0x82EDF8AC
// RVA : 0x00EDF8AC
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_28454()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$28455
// EA  : 0x82EDF8D4
// RVA : 0x00EDF8D4
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_28455()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?IsClass@ssEntity@@QBA_NVssString@@@Z
// EA  : 0x82EDF908
// RVA : 0x00EDF908
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

BOOL __fastcall ssEntity::IsClass(ssEntity *this, ssString *className)
{
  char *data; // r11
  int spawnId; // r4
  BOOL v6; // r29
  ssEntity *v8; // r3
  const ssString *v9; // r3
  char *v10; // [sp+50h] [-60h] BYREF
  ssString v11; // [sp+60h] [-50h] BYREF
  ssString v12[4]; // [sp+70h] [-40h] BYREF

  data = className->data;
  spawnId = this->spawnId;
  v10 = data;
  if ( gameInterface->EventCall(this: gameInterface, a2: spawnId, a3: 150, a4: "s", a5: (ssVarg_t *)&v10) )
  {
    v6 = gameInterface->EventGetReturnInt(this: gameInterface) != 0;
    ssString::Empty(this: className);
    return v6;
  }
  else
  {
    v8 = ssEntity::Name(this: (ssEntity *)v12, result: (ssString *)this);
    v9 = operator+(result: &v11, a: (const ssString *)v8, b: ".IsClass failed.");
    Warning(msg: v9);
    ssString::Empty(this: &v11);
    ssString::Empty(this: v12);
    ssString::Empty(this: className);
    return false;
  }
}


// ========================================================================
// __unwind$29375
// EA  : 0x82EDF9D8
// RVA : 0x00EDF9D8
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_29375()
{
  int v0; // r12

  ssString::~ssString(this: *(ssString **)(v0 - 176 + 204));
}


// ========================================================================
// __unwind$29376
// EA  : 0x82EDFA00
// RVA : 0x00EDFA00
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_29376()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$29377
// EA  : 0x82EDFA28
// RVA : 0x00EDFA28
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_29377()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?GetJointHandle@ssEntity@@QBAHVssString@@@Z
// EA  : 0x82EDFA58
// RVA : 0x00EDFA58
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

int __fastcall ssEntity::GetJointHandle(ssEntity *this, ssString *jointname)
{
  char *data; // r11
  int spawnId; // r4
  int v6; // r29
  ssEntity *v8; // r3
  const ssString *v9; // r3
  char *v10; // [sp+50h] [-60h] BYREF
  ssString v11; // [sp+60h] [-50h] BYREF
  ssString v12[4]; // [sp+70h] [-40h] BYREF

  data = jointname->data;
  spawnId = this->spawnId;
  v10 = data;
  if ( gameInterface->EventCall(this: gameInterface, a2: spawnId, a3: 277, a4: "s", a5: (ssVarg_t *)&v10) )
  {
    v6 = gameInterface->EventGetReturnInt(this: gameInterface);
    ssString::Empty(this: jointname);
    return v6;
  }
  else
  {
    v8 = ssEntity::Name(this: (ssEntity *)v12, result: (ssString *)this);
    v9 = operator+(result: &v11, a: (const ssString *)v8, b: ".GetJointHandle failed.");
    Warning(msg: v9);
    ssString::Empty(this: &v11);
    ssString::Empty(this: v12);
    ssString::Empty(this: jointname);
    return 0;
  }
}


// ========================================================================
// __unwind$29565
// EA  : 0x82EDFB24
// RVA : 0x00EDFB24
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_29565()
{
  int v0; // r12

  ssString::~ssString(this: *(ssString **)(v0 - 176 + 204));
}


// ========================================================================
// __unwind$29566
// EA  : 0x82EDFB4C
// RVA : 0x00EDFB4C
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_29566()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$29567
// EA  : 0x82EDFB74
// RVA : 0x00EDFB74
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_29567()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?GetJointPos@ssEntity@@QBA?AVssVector@@H@Z
// EA  : 0x82EDFBA8
// RVA : 0x00EDFBA8
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

ssEntity *__fastcall ssEntity::GetJointPos(ssEntity *this, ssString *result, int jointnum)
{
  double v5; // fp12
  double v6; // fp0
  ssEntity *v7; // r3
  const ssString *v8; // r3
  float v10[4]; // [sp+50h] [-70h] BYREF
  int v11[4]; // [sp+60h] [-60h] BYREF
  ssString v12; // [sp+70h] [-50h] BYREF
  ssString v13[4]; // [sp+80h] [-40h] BYREF

  v11[0] = jointnum;
  if ( gameInterface->EventCall(this: gameInterface, a2: result->len, a3: 280, a4: "i", a5: (ssVarg_t *)v11) )
  {
    gameInterface->EventGetReturnVector(this: gameInterface, a2: (ssVec3_t *)v10);
    v5 = v10[2];
    v6 = v10[0];
    *(this + 1) = LODWORD(v10[1]);
    *((float *)this + 2) = v5;
  }
  else
  {
    v7 = ssEntity::Name(this: (ssEntity *)v13, result);
    v8 = operator+(result: &v12, a: (const ssString *)v7, b: ".GetJointPos failed.");
    Warning(msg: v8);
    ssString::Empty(this: &v12);
    ssString::Empty(this: v13);
    v6 = 0.0;
    *((float *)this + 1) = 0.0;
    *((float *)this + 2) = 0.0;
  }
  *(float *)&this->spawnId = v6;
  return this;
}


// ========================================================================
// __unwind$29715
// EA  : 0x82EDFC80
// RVA : 0x00EDFC80
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_29715()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 128));
}


// ========================================================================
// __unwind$29716
// EA  : 0x82EDFCA8
// RVA : 0x00EDFCA8
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_29716()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 192 + 112));
}


// ========================================================================
// ?StartSpline@ssEntity@@QBAXV1@@Z
// EA  : 0x82EDFCD8
// RVA : 0x00EDFCD8
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void __fastcall ssEntity::StartSpline(ssEntity *this, ssEntity *splineEntity)
{
  int spawnId; // r11
  int v3; // r4
  ssEntity *v5; // r3
  const ssString *v6; // r3
  int v7[4]; // [sp+50h] [-50h] BYREF
  ssString v8; // [sp+60h] [-40h] BYREF
  ssString v9; // [sp+70h] [-30h] BYREF

  spawnId = splineEntity->spawnId;
  v3 = this->spawnId;
  v7[0] = spawnId;
  if ( !gameInterface->EventCall(this: gameInterface, a2: v3, a3: 335, a4: "e", a5: (ssVarg_t *)v7) )
  {
    v5 = ssEntity::Name(this: (ssEntity *)&v9, result: (ssString *)this);
    v6 = operator+(result: &v8, a: (const ssString *)v5, b: ".StartSpline failed.");
    Warning(msg: v6);
    ssString::Empty(this: &v8);
    ssString::Empty(this: &v9);
  }
}


// ========================================================================
// __unwind$30965
// EA  : 0x82EDFD80
// RVA : 0x00EDFD80
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_30965()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$30966
// EA  : 0x82EDFDA8
// RVA : 0x00EDFDA8
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_30966()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?GetViewAngles@ssEntity@@QAA?AVssVector@@XZ
// EA  : 0x82EDFDD8
// RVA : 0x00EDFDD8
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

ssEntity *__fastcall ssEntity::GetViewAngles(ssEntity *this, ssString *result)
{
  double v4; // fp12
  double v5; // fp0
  ssEntity *v6; // r3
  const ssString *v7; // r3
  float v9[4]; // [sp+50h] [-60h] BYREF
  ssString v10; // [sp+60h] [-50h] BYREF
  ssString v11[4]; // [sp+70h] [-40h] BYREF

  if ( gameInterface->EventCall(this: gameInterface, a2: result->len, a3: 547, a4: &byte_8200D768, a5: nullptr) )
  {
    gameInterface->EventGetReturnVector(this: gameInterface, a2: (ssVec3_t *)v9);
    v4 = v9[2];
    v5 = v9[0];
    *(this + 1) = LODWORD(v9[1]);
    *((float *)this + 2) = v4;
  }
  else
  {
    v6 = ssEntity::Name(this: (ssEntity *)v11, result);
    v7 = operator+(result: &v10, a: (const ssString *)v6, b: ".GetViewAngles failed.");
    Warning(msg: v7);
    ssString::Empty(this: &v10);
    ssString::Empty(this: v11);
    v5 = 0.0;
    *((float *)this + 1) = 0.0;
    *((float *)this + 2) = 0.0;
  }
  *(float *)&this->spawnId = v5;
  return this;
}


// ========================================================================
// __unwind$35986
// EA  : 0x82EDFEAC
// RVA : 0x00EDFEAC
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_35986()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$35987
// EA  : 0x82EDFED4
// RVA : 0x00EDFED4
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_35987()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?GetViewPos@ssEntity@@QAA?AVssVector@@XZ
// EA  : 0x82EDFF08
// RVA : 0x00EDFF08
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

ssEntity *__fastcall ssEntity::GetViewPos(ssEntity *this, ssString *result)
{
  double v4; // fp12
  double v5; // fp0
  ssEntity *v6; // r3
  const ssString *v7; // r3
  float v9[4]; // [sp+50h] [-60h] BYREF
  ssString v10; // [sp+60h] [-50h] BYREF
  ssString v11[4]; // [sp+70h] [-40h] BYREF

  if ( gameInterface->EventCall(this: gameInterface, a2: result->len, a3: 549, a4: &byte_8200D768, a5: nullptr) )
  {
    gameInterface->EventGetReturnVector(this: gameInterface, a2: (ssVec3_t *)v9);
    v4 = v9[2];
    v5 = v9[0];
    *(this + 1) = LODWORD(v9[1]);
    *((float *)this + 2) = v4;
  }
  else
  {
    v6 = ssEntity::Name(this: (ssEntity *)v11, result);
    v7 = operator+(result: &v10, a: (const ssString *)v6, b: ".GetViewPos failed.");
    Warning(msg: v7);
    ssString::Empty(this: &v10);
    ssString::Empty(this: v11);
    v5 = 0.0;
    *((float *)this + 1) = 0.0;
    *((float *)this + 2) = 0.0;
  }
  *(float *)&this->spawnId = v5;
  return this;
}


// ========================================================================
// __unwind$36069
// EA  : 0x82EDFFDC
// RVA : 0x00EDFFDC
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_36069()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$36070
// EA  : 0x82EE0004
// RVA : 0x00EE0004
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_36070()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// ?Action_MoveToPoint@ssEntity@@QBAXVssVector@@HMH0@Z
// EA  : 0x82EE0038
// RVA : 0x00EE0038
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void __fastcall ssEntity::Action_MoveToPoint(
        ssEntity *this,
        ssVector *dest,
        int stopUponArrival,
        double tolerance,
        int align,
        ssVector *alignDir,
        float *a7)
{
  int z_low; // r11
  float v9; // r10
  float v10; // r3
  float x; // r29
  float v12; // r8
  float y; // r11
  ssEntity *v14; // r3
  const ssString *v15; // r3
  ssString v16; // [sp+50h] [-90h] BYREF
  ssString v17; // [sp+60h] [-80h] BYREF
  float v18[28]; // [sp+70h] [-70h] BYREF

  z_low = LODWORD(dest->z);
  v9 = *a7;
  v18[8] = tolerance;
  v10 = a7[1];
  x = dest->x;
  v12 = a7[2];
  v17.alloced = z_low;
  y = dest->y;
  v18[2] = *(float *)&v17.alloced;
  *(float *)&v16.len = v9;
  *(float *)&v16.alloced = v12;
  *(float *)&v17.len = x;
  *(float *)&v17.data = y;
  *(float *)&v16.data = v10;
  LODWORD(v18[4]) = stopUponArrival;
  v18[17] = v10;
  LODWORD(v18[12]) = alignDir;
  v18[1] = y;
  v18[0] = x;
  v18[16] = v9;
  v18[18] = v12;
  if ( !gameInterface->EventCall(this: gameInterface, a2: this->spawnId, a3: 956, a4: "vifiv", a5: (ssVarg_t *)v18) )
  {
    v14 = ssEntity::Name(this: (ssEntity *)&v16, result: (ssString *)this);
    v15 = operator+(result: &v17, a: (const ssString *)v14, b: ".Action_MoveToPoint failed.");
    Warning(msg: v15);
    ssString::Empty(this: &v17);
    ssString::Empty(this: &v16);
  }
}


// ========================================================================
// __unwind$42976
// EA  : 0x82EE012C
// RVA : 0x00EE012C
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_42976()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$42977
// EA  : 0x82EE0154
// RVA : 0x00EE0154
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_42977()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 96));
}


// ========================================================================
// ?Action_MoveToEntity@ssEntity@@QBAXV1@HMHVssVector@@@Z
// EA  : 0x82EE0188
// RVA : 0x00EE0188
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void __fastcall ssEntity::Action_MoveToEntity(
        ssEntity *this,
        ssEntity *ent,
        int stopUponArraival,
        double reachedDistance,
        int align,
        ssVector *alignDir,
        float *a7)
{
  float v7; // r11
  float v8; // r9
  float v9; // r8
  int spawnId; // r4
  ssEntity *v12; // r3
  const ssString *v13; // r3
  ssString v14; // [sp+50h] [-90h] BYREF
  ssString v15; // [sp+60h] [-80h] BYREF
  float v16[22]; // [sp+70h] [-70h] BYREF

  v7 = a7[2];
  v16[8] = reachedDistance;
  v8 = *a7;
  v9 = a7[1];
  spawnId = ent->spawnId;
  LODWORD(v16[4]) = stopUponArraival;
  *(float *)&v14.alloced = v7;
  *(float *)&v14.len = v8;
  *(float *)&v14.data = v9;
  LODWORD(v16[12]) = alignDir;
  v16[18] = v7;
  LODWORD(v16[0]) = spawnId;
  v16[16] = v8;
  v16[17] = v9;
  if ( !gameInterface->EventCall(this: gameInterface, a2: this->spawnId, a3: 958, a4: "eifiv", a5: (ssVarg_t *)v16) )
  {
    v12 = ssEntity::Name(this: (ssEntity *)&v15, result: (ssString *)this);
    v13 = operator+(result: &v14, a: (const ssString *)v12, b: ".Action_MoveToEntity failed.");
    Warning(msg: v13);
    ssString::Empty(this: &v14);
    ssString::Empty(this: &v15);
  }
}


// ========================================================================
// __unwind$43094
// EA  : 0x82EE026C
// RVA : 0x00EE026C
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_43094()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$43095
// EA  : 0x82EE0294
// RVA : 0x00EE0294
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_43095()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 224 + 80));
}


// ========================================================================
// ?Action_MoveToPathPointNoFail@ssEntity@@QBAXV1@PAVidDeclVoiceOver@@@Z
// EA  : 0x82EE02C8
// RVA : 0x00EE02C8
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void __fastcall ssEntity::Action_MoveToPathPointNoFail(
        ssEntity *this,
        ssEntity *pathPoint,
        idDeclVoiceOver *declVoiceOver)
{
  int spawnId; // r11
  int v5; // r4
  ssEntity *v6; // r3
  const ssString *v7; // r3
  ssString v8; // [sp+50h] [-60h] BYREF
  ssString v9; // [sp+60h] [-50h] BYREF
  _DWORD v10[10]; // [sp+70h] [-40h] BYREF

  spawnId = pathPoint->spawnId;
  v10[4] = declVoiceOver;
  v5 = this->spawnId;
  v10[0] = spawnId;
  if ( !gameInterface->EventCall(this: gameInterface, a2: v5, a3: 961, a4: "ed", a5: (ssVarg_t *)v10) )
  {
    v6 = ssEntity::Name(this: (ssEntity *)&v9, result: (ssString *)this);
    v7 = operator+(result: &v8, a: (const ssString *)v6, b: ".Action_MoveToPathPointNoFail failed.");
    Warning(msg: v7);
    ssString::Empty(this: &v8);
    ssString::Empty(this: &v9);
  }
}


// ========================================================================
// __unwind$43247
// EA  : 0x82EE0374
// RVA : 0x00EE0374
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_43247()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$43248
// EA  : 0x82EE039C
// RVA : 0x00EE039C
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_43248()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 80));
}


// ========================================================================
// ?Action_SetAlertCycle@ssEntity@@QBAXH@Z
// EA  : 0x82EE03D0
// RVA : 0x00EE03D0
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void __fastcall ssEntity::Action_SetAlertCycle(ssEntity *this, int alertCycle)
{
  ssEntity *v3; // r3
  const ssString *v4; // r3
  int v5[4]; // [sp+50h] [-50h] BYREF
  ssString v6; // [sp+60h] [-40h] BYREF
  ssString v7; // [sp+70h] [-30h] BYREF

  v5[0] = alertCycle;
  if ( !gameInterface->EventCall(this: gameInterface, a2: this->spawnId, a3: 1003, a4: "i", a5: (ssVarg_t *)v5) )
  {
    v3 = ssEntity::Name(this: (ssEntity *)&v7, result: (ssString *)this);
    v4 = operator+(result: &v6, a: (const ssString *)v3, b: ".Action_SetAlertCycle failed.");
    Warning(msg: v4);
    ssString::Empty(this: &v6);
    ssString::Empty(this: &v7);
  }
}


// ========================================================================
// __unwind$45035
// EA  : 0x82EE0474
// RVA : 0x00EE0474
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_45035()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$45036
// EA  : 0x82EE049C
// RVA : 0x00EE049C
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_45036()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?Action_SetWalkState@ssEntity@@QBAXH@Z
// EA  : 0x82EE04D0
// RVA : 0x00EE04D0
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void __fastcall ssEntity::Action_SetWalkState(ssEntity *this, int state)
{
  ssEntity *v3; // r3
  const ssString *v4; // r3
  int v5[4]; // [sp+50h] [-50h] BYREF
  ssString v6; // [sp+60h] [-40h] BYREF
  ssString v7; // [sp+70h] [-30h] BYREF

  v5[0] = state;
  if ( !gameInterface->EventCall(this: gameInterface, a2: this->spawnId, a3: 1013, a4: "i", a5: (ssVarg_t *)v5) )
  {
    v3 = ssEntity::Name(this: (ssEntity *)&v7, result: (ssString *)this);
    v4 = operator+(result: &v6, a: (const ssString *)v3, b: ".Action_SetWalkState failed.");
    Warning(msg: v4);
    ssString::Empty(this: &v6);
    ssString::Empty(this: &v7);
  }
}


// ========================================================================
// __unwind$45408
// EA  : 0x82EE0574
// RVA : 0x00EE0574
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_45408()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$45409
// EA  : 0x82EE059C
// RVA : 0x00EE059C
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_45409()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ?Action_EnablePain@ssEntity@@QBAXH@Z
// EA  : 0x82EE05D0
// RVA : 0x00EE05D0
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void __fastcall ssEntity::Action_EnablePain(ssEntity *this, int enabled)
{
  ssEntity *v3; // r3
  const ssString *v4; // r3
  int v5[4]; // [sp+50h] [-50h] BYREF
  ssString v6; // [sp+60h] [-40h] BYREF
  ssString v7; // [sp+70h] [-30h] BYREF

  v5[0] = enabled;
  if ( !gameInterface->EventCall(this: gameInterface, a2: this->spawnId, a3: 1025, a4: "i", a5: (ssVarg_t *)v5) )
  {
    v3 = ssEntity::Name(this: (ssEntity *)&v7, result: (ssString *)this);
    v4 = operator+(result: &v6, a: (const ssString *)v3, b: ".Action_EnablePain failed.");
    Warning(msg: v4);
    ssString::Empty(this: &v6);
    ssString::Empty(this: &v7);
  }
}


// ========================================================================
// __unwind$45864
// EA  : 0x82EE0674
// RVA : 0x00EE0674
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_45864()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$45865
// EA  : 0x82EE069C
// RVA : 0x00EE069C
// PDB : w:\tech5\tungsten\superscript\generated\game_events.cpp
// ========================================================================

void _unwind_45865()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}

