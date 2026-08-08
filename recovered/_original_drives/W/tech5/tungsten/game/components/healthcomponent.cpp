
// ========================================================================
// ?Reset_Impl@idTungstenHealth@@MAAXXZ
// EA  : 0x82BB56B0
// RVA : 0x00BB56B0
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void __fastcall idTungstenHealth::Reset_Impl(idTungstenHealth *this)
{
  this->lastUpdateTime = 0;
  this->lastDamageTime = 0;
  this->isDead = false;
  this->components[0].cur = 0.0;
  this->components[1].cur = 0.0;
  this->components[0].cur = 100.0;
}


// ========================================================================
// ?DamageComponent_Impl@idTungstenHealth@@MAA_NHM_N0AAM@Z
// EA  : 0x82BB56E0
// RVA : 0x00BB56E0
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

int __fastcall idTungstenHealth::DamageComponent_Impl(
        idTungstenHealth *this,
        const int type,
        double d,
        const bool allowDeath,
        const bool overflow,
        float *remainingDamage,
        float *a7)
{
  *a7 = 0.0;
  return 0;
}


// ========================================================================
// ?HealComponent_Impl@idTungstenHealth@@MAAXHM_N@Z
// EA  : 0x82BB56F8
// RVA : 0x00BB56F8
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void __fastcall idTungstenHealth::HealComponent_Impl(
        idTungstenHealth *this,
        const int type,
        double h,
        const bool overflow)
{
  this->components[type].cur = this->components[type].cur + (float)h;
}


// ========================================================================
// ?GetTotalCurHealth_Impl@idTungstenHealth@@MBAMXZ
// EA  : 0x82BB5718
// RVA : 0x00BB5718
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

float __fastcall idTungstenHealth::GetTotalCurHealth_Impl(idTungstenHealth *this)
{
  double v1; // fp1

  v1 = (float)(this->components[1].cur + this->components[0].cur);
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?GetTotalMaxHealth_Impl@idTungstenHealth@@MBAMXZ
// EA  : 0x82BB5728
// RVA : 0x00BB5728
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

float __fastcall idTungstenHealth::GetTotalMaxHealth_Impl(idTungstenHealth *this)
{
  double v1; // fp1

  v1 = (float)(this->components[1].max + this->components[0].max);
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?ReportDamage@@YAXAAVidTungstenHealth@@M_N@Z
// EA  : 0x82BB5738
// RVA : 0x00BB5738
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void __fastcall ReportDamage(idTungstenHealth *hc, double damage, bool allowDeath, int a4)
{
  double v7; // fp30
  int v8; // r4
  double v9; // fp31
  const char *v10; // r4
  double v11; // [sp+20h] [-60h]
  float v12[2]; // [sp+50h] [-30h] BYREF

  v7 = ((double (__fastcall *)(idTungstenHealth *, bool))hc->GetCurBaseHealth_Impl)(a1: hc, a2: allowDeath);
  ((void (__fastcall *)(idTungstenHealth *, int, int, float *, double))hc->Damage_Impl)(
    a1: hc,
    a2: v8,
    a3: a4,
    a4: v12,
    a5: damage);
  LOBYTE(a4) = BYTE3(damage);
  idLib::Printf(fmt: "Took %.1f damage:\n", damage);
  v9 = ((double (__fastcall *)(idTungstenHealth *))hc->GetMaxBaseHealth_Impl)(a1: hc);
  v11 = ((double (__fastcall *)(idTungstenHealth *))hc->GetCurBaseHealth_Impl)(a1: hc);
  idLib::Printf(fmt: "  health: %.1f -> %.1f (%.1f)\n", v7, v11, v9);
  if ( (_BYTE)a4 != 0 )
    v10 = "WAS";
  else
    v10 = "WAS NOT";
  idLib::Printf(fmt: "  %s killed.\n", v10);
  idLib::Printf(fmt: "  %.1f remaining damage.\n", v12[0]);
}


// ========================================================================
// ??0idTungstenHealth@@QAA@XZ
// EA  : 0x82BB5878
// RVA : 0x00BB5878
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

idTungstenHealth *__fastcall idTungstenHealth::idTungstenHealth(idTungstenHealth *this)
{
  this->__vftable = (idTungstenHealth_vtbl *)&idTungstenHealth::`vftable';
  idTungstenHealth::Reset_Impl(this);
  return this;
}


// ========================================================================
// __unwind$487545
// EA  : 0x82BB58CC
// RVA : 0x00BB58CC
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void _unwind_487545()
{
  int v0; // r12

  idSimpleHealth::~idSimpleHealth(this: *(idAIHealth **)(v0 - 112 + 132));
}


// ========================================================================
// ?SetDeadFlag@idTungstenHealth@@MAAXXZ
// EA  : 0x82BB5A38
// RVA : 0x00BB5A38
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void __fastcall idTungstenHealth::SetDeadFlag(idTungstenHealth *this)
{
  this->isDead = true;
}


// ========================================================================
// ??0idTungstenHealth@@QAA@MM@Z
// EA  : 0x82BB5AA8
// RVA : 0x00BB5AA8
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

idTungstenHealth *__fastcall idTungstenHealth::idTungstenHealth(idTungstenHealth *this, double health, double armor)
{
  this->__vftable = (idTungstenHealth_vtbl *)&idTungstenHealth::`vftable';
  idTungstenHealth::Reset_Impl(this);
  this->components[0].cur = health;
  this->components[1].cur = armor;
  return this;
}


// ========================================================================
// __unwind$487626
// EA  : 0x82BB5B1C
// RVA : 0x00BB5B1C
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void _unwind_487626()
{
  int v0; // r12

  idSimpleHealth::~idSimpleHealth(this: *(idAIHealth **)(v0 - 128 + 148));
}


// ========================================================================
// ?Update_Impl@idTungstenHealth@@MAAXXZ
// EA  : 0x82BB5B48
// RVA : 0x00BB5B48
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void __fastcall idTungstenHealth::Update_Impl(idTungstenHealth *this)
{
  __int64 v2; // r9
  int v3; // r3
  long double v4; // fp2
  int lastUpdateTime; // r11
  int v6; // r30
  double cur; // fp31
  double v8; // fp30
  __int64 v9; // r9
  double v10; // fp29
  long double v11; // fp2

  v3 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  lastUpdateTime = this->lastUpdateTime;
  v6 = v3;
  if ( lastUpdateTime != -1 )
  {
    cur = this->components[0].cur;
    LODWORD(v2) = v3 - lastUpdateTime;
    v8 = (float)((float)v2 * (float)0.001);
    if ( cur < this->components[0].max )
    {
      HIDWORD(v9) = &g_playerHealthRegenDelay;
      if ( v3 > (int)(float)(g_playerHealthRegenDelay.valueFloat * (float)1000.0) + this->lastDamageTime )
      {
        LODWORD(v9) = g_playerHealthRegenSteps.valueInteger;
        v10 = (float)v9;
        *(double *)&v4 = (float)(this->components[0].cur / (float)v9);
        v11 = ceil(x: v4);
        if ( cur < (float)((float)*(double *)&v11 * (float)v10) )
        {
          _FP12 = (float)((float)((float)(g_playerHealthRegenSpeed.valueFloat * (float)v8) + (float)cur)
                        - (float)((float)*(double *)&v11 * (float)v10));
          __asm { fsel      f11, f12, f0, f13 }
          this->components[0].cur = _FP11;
        }
      }
    }
    if ( this->components[0].cur > (double)this->components[0].max )
    {
      _FP12 = (float)((float)-(float)((float)(g_playerHealthDecaySpeed.valueFloat * (float)v8) - this->components[0].cur)
                    - this->components[0].max);
      __asm { fsel      f11, f12, f13, f0 }
      this->components[0].cur = _FP11;
    }
    if ( this->components[1].cur > (double)this->components[1].max )
    {
      _FP12 = (float)((float)-(float)((float)(g_playerHealthDecaySpeed.valueFloat * (float)v8) - this->components[1].cur)
                    - this->components[1].max);
      __asm { fsel      f11, f12, f13, f0 }
      this->components[1].cur = _FP11;
    }
  }
  this->lastUpdateTime = v6;
}


// ========================================================================
// ?Damage_Impl@idTungstenHealth@@MAA_NM_NAAM@Z
// EA  : 0x82BB5CD0
// RVA : 0x00BB5CD0
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

int __fastcall idTungstenHealth::Damage_Impl(
        idTungstenHealth *this,
        double d,
        const bool allowDeath,
        float *remainingDamage,
        float *a5)
{
  char v7; // r29
  double v9; // fp0
  idTungstenHealth_vtbl *v12; // r11

  v7 = (char)remainingDamage;
  this->lastDamageTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  *a5 = d;
  if ( d <= this->components[1].cur )
  {
    this->components[1].cur = this->components[1].cur - (float)d;
    *a5 = *a5 * 0.2;
  }
  else
  {
    v9 = (float)((float)d - this->components[1].cur);
    *a5 = (float)d - this->components[1].cur;
    *a5 = (float)(this->components[1].cur * 0.2) + (float)v9;
    this->components[1].cur = 0.0;
  }
  if ( v7 == 0 )
  {
    _FP9 = (float)(*a5 - (float)(this->components[0].cur - (float)1.0));
    __asm { fsel      f8, f9, f10, f11 }
    *a5 = _FP8;
  }
  if ( *a5 <= (double)this->components[0].cur )
  {
    this->components[0].cur = this->components[0].cur - *a5;
    return 0;
  }
  else
  {
    *a5 = *a5 - this->components[0].cur;
    v12 = this->__vftable;
    this->components[0].cur = 0.0;
    v12->Kill_Impl(this, a2: d);
    this->SetDeadFlag(this);
    return 1;
  }
}


// ========================================================================
// ?WriteComponents_Impl@idTungstenHealth@@MBAXPAVidFile@@@Z
// EA  : 0x82BB5E08
// RVA : 0x00BB5E08
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void __fastcall idTungstenHealth::WriteComponents_Impl(idTungstenHealth *this, idFile *file)
{
  idTungstenHealth::component_t *components; // r30
  int i; // r29

  components = this->components;
  for ( i = 2; i != 0; --i )
  {
    file->Write(this: file, a2: &components->max, a3: 4u);
    file->Write(this: file, a2: components++, a3: 4u);
  }
  file->Write(this: file, a2: &this->isDead, a3: 1u);
}


// ========================================================================
// ?testHealthComponent_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82BB5E98
// RVA : 0x00BB5E98
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void __fastcall testHealthComponent_f(const idCmdArgs *args)
{
  bool v1; // r4
  bool v2; // r4
  bool v3; // r4
  bool v4; // r4
  bool v5; // r4
  idTungstenHealth v6; // [sp+50h] [-C0h] BYREF
  idTungstenHealth v7; // [sp+70h] [-A0h] BYREF
  idTungstenHealth v8; // [sp+90h] [-80h] BYREF
  idTungstenHealth v9; // [sp+B0h] [-60h] BYREF
  idTungstenHealth v10; // [sp+D0h] [-40h] BYREF

  idTungstenHealth::idTungstenHealth(this: &v7, health: 100.0, armor: 100.0);
  ReportDamage(hc: &v7, damage: 200.0, allowDeath: v1, a4: 1);
  idTungstenHealth::idTungstenHealth(this: &v9, health: 100.0, armor: 100.0);
  ReportDamage(hc: &v9, damage: 200.10001, allowDeath: v2, a4: 1);
  idTungstenHealth::idTungstenHealth(this: &v6, health: 100.0, armor: 100.0);
  ReportDamage(hc: &v6, damage: 201.0, allowDeath: v3, a4: 1);
  idTungstenHealth::idTungstenHealth(this: &v8, health: 100.0, armor: 100.0);
  ReportDamage(hc: &v8, damage: 50.0, allowDeath: v4, a4: 1);
  idTungstenHealth::idTungstenHealth(this: &v10, health: 100.0, armor: 100.0);
  ReportDamage(hc: &v10, damage: 150.0, allowDeath: v5, a4: 1);
}


// ========================================================================
// __unwind$487794
// EA  : 0x82BB5F84
// RVA : 0x00BB5F84
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void _unwind_487794()
{
  int v0; // r12

  idSimpleHealth::~idSimpleHealth(this: (idAIHealth *)(v0 - 272 + 112));
}


// ========================================================================
// __unwind$487795
// EA  : 0x82BB5FAC
// RVA : 0x00BB5FAC
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void _unwind_487795()
{
  int v0; // r12

  idSimpleHealth::~idSimpleHealth(this: (idAIHealth *)(v0 - 272 + 176));
}


// ========================================================================
// __unwind$487796
// EA  : 0x82BB5FD4
// RVA : 0x00BB5FD4
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void _unwind_487796()
{
  int v0; // r12

  idSimpleHealth::~idSimpleHealth(this: (idAIHealth *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$487797
// EA  : 0x82BB5FFC
// RVA : 0x00BB5FFC
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void _unwind_487797()
{
  int v0; // r12

  idSimpleHealth::~idSimpleHealth(this: (idAIHealth *)(v0 - 272 + 144));
}


// ========================================================================
// __unwind$487798
// EA  : 0x82BB6024
// RVA : 0x00BB6024
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void _unwind_487798()
{
  int v0; // r12

  idSimpleHealth::~idSimpleHealth(this: (idAIHealth *)(v0 - 272 + 208));
}


// ========================================================================
// ?ReadComponents_Impl@idTungstenHealth@@MAAXPAVidFile@@@Z
// EA  : 0x82BB6050
// RVA : 0x00BB6050
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

void __fastcall idTungstenHealth::ReadComponents_Impl(idTungstenHealth *this, idFile *file)
{
  idTungstenHealth::component_t *components; // r30
  int i; // r29

  components = this->components;
  for ( i = 2; i != 0; --i )
  {
    file->Read(this: file, a2: &components->max, a3: 4u);
    file->Read(this: file, a2: components++, a3: 4u);
  }
  file->Read(this: file, a2: &this->isDead, a3: 1u);
}


// ========================================================================
// `dynamic initializer for 'testHealthComponent_v''
// EA  : 0x83372368
// RVA : 0x01372368
// PDB : w:\tech5\tungsten\game\components\healthcomponent.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testHealthComponent_v__()
{
  return idCommandLink::idCommandLink(
           this: &testHealthComponent_v,
           cmdName: "testHealthComponent",
           function: testHealthComponent_f,
           description: "tests health component",
           argCompletion: nullptr);
}

