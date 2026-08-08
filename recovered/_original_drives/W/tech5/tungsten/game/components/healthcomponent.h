
// ========================================================================
// ??1idSimpleHealth@@UAA@XZ
// EA  : 0x829F06E8
// RVA : 0x009F06E8
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idSimpleHealth::~idSimpleHealth(idAIHealth *this)
{
  this->__vftable = (idAIHealth_vtbl *)&idBaseHealth::`vftable';
}


// ========================================================================
// ?Kill@idBaseHealth@@QAAXM@Z
// EA  : 0x829F06F8
// RVA : 0x009F06F8
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idBaseHealth::Kill(idBaseHealth *this, double d)
{
  this->Kill_Impl(this, a2: d);
  this->SetDeadFlag(this);
}


// ========================================================================
// ?DamageShield_Impl@idBaseHealth@@MAA_NM_N0AAM@Z
// EA  : 0x829F0748
// RVA : 0x009F0748
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

BOOL __fastcall idBaseHealth::DamageShield_Impl(
        idBaseHealth *this,
        double d,
        bool allowDeath,
        bool overflow,
        float *remainingDamage,
        int a6)
{
  return ((bool (__fastcall *)(idBaseHealth *, bool, bool, int, double))this->Damage_Impl)(
           a1: this,
           a2: allowDeath,
           a3: overflow,
           a4: a6,
           a5: d);
}


// ========================================================================
// ?GetComponentCur_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MBAMH@Z
// EA  : 0x829F60F8
// RVA : 0x009F60F8
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

float __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::GetComponentCur_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        const int type)
{
  double cur; // fp1

  cur = this->components[type].cur;
  return *((float *)&cur + 1);
}


// ========================================================================
// ?GetComponentMax_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MBAMH@Z
// EA  : 0x829F6110
// RVA : 0x009F6110
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

float __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::GetComponentMax_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        const int type)
{
  double max; // fp1

  max = this->components[type].max;
  return *((float *)&max + 1);
}


// ========================================================================
// ?SetComponentCur_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MAAXHM@Z
// EA  : 0x829F6128
// RVA : 0x009F6128
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::SetComponentCur_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        const int type,
        double h)
{
  this->components[type].cur = h;
}


// ========================================================================
// ?SetComponentMax_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MAAXHM@Z
// EA  : 0x829F6140
// RVA : 0x009F6140
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::SetComponentMax_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        const int type,
        double h)
{
  this->components[type].max = h;
}


// ========================================================================
// ?IsDead_Impl@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@MBA_NXZ
// EA  : 0x829F6158
// RVA : 0x009F6158
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

BOOL __fastcall idHealthT<enum aiHealthComponent_t,2,0>::IsDead_Impl(idHealthT<enum aiHealthComponent_t,2,0> *this)
{
  return this->isDead;
}


// ========================================================================
// ?VehicleDied@idVehicle_Jump@@UAAXXZ
// EA  : 0x829F6160
// RVA : 0x009F6160
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idVehicle_Jump::VehicleDied(idHealthT<enum aiHealthComponent_t,2,0> *this)
{
  this->isDead = false;
}


// ========================================================================
// ?SetDeadFlag@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@MAAXXZ
// EA  : 0x829F6170
// RVA : 0x009F6170
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idHealthT<enum aiHealthComponent_t,2,0>::SetDeadFlag(idHealthT<enum aiHealthComponent_t,2,0> *this)
{
  this->isDead = true;
}


// ========================================================================
// ?HealShield_Impl@?$idShieldHealthT@W4aiHealthComponent_t@@$01$0A@$00@@UAAXM@Z
// EA  : 0x829FC678
// RVA : 0x009FC678
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idShieldHealthT<enum aiHealthComponent_t,2,0,1>::HealShield_Impl(
        idShieldHealthT<enum aiHealthComponent_t,2,0,1> *this,
        double h,
        int a3,
        int a4)
{
  ((void (__fastcall *)(idShieldHealthT<enum aiHealthComponent_t,2,0,1> *, int, int, _DWORD, double))this->HealComponent_Impl)(
    a1: this,
    a2: 1,
    a3: a4,
    a4: 0,
    a5: h);
}


// ========================================================================
// ?DamageShield_Impl@?$idShieldHealthT@W4aiHealthComponent_t@@$01$0A@$00@@UAA_NM_N0AAM@Z
// EA  : 0x829FC690
// RVA : 0x009FC690
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

BOOL __fastcall idShieldHealthT<enum aiHealthComponent_t,2,0,1>::DamageShield_Impl(
        idShieldHealthT<enum aiHealthComponent_t,2,0,1> *this,
        double d,
        const bool allowDeath,
        bool overflow,
        float *remainingDamage,
        int a6)
{
  return ((bool (__fastcall *)(idShieldHealthT<enum aiHealthComponent_t,2,0,1> *, int, bool, bool, float *, int, double))this->DamageComponent_Impl)(
           a1: this,
           a2: 1,
           a3: overflow,
           a4: overflow,
           a5: remainingDamage,
           a6,
           a7: d);
}


// ========================================================================
// ?GetActionFlags@idAction_LoopAnimExitAtEnd@@UBAHXZ
// EA  : 0x82BB58F8
// RVA : 0x00BB58F8
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

int __fastcall idAction_LoopAnimExitAtEnd::GetActionFlags(XGRAPHICS::IRKill2 *this)
{
  return 2;
}


// ========================================================================
// ?GetComponentCur_Impl@idTungstenHealth@@MBAMH@Z
// EA  : 0x82BB5900
// RVA : 0x00BB5900
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

float __fastcall idTungstenHealth::GetComponentCur_Impl(idTungstenHealth *this, const int type)
{
  double cur; // fp1

  cur = this->components[type].cur;
  return *((float *)&cur + 1);
}


// ========================================================================
// ?GetComponentMax_Impl@idTungstenHealth@@MBAMH@Z
// EA  : 0x82BB5910
// RVA : 0x00BB5910
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

float __fastcall idTungstenHealth::GetComponentMax_Impl(idTungstenHealth *this, const int type)
{
  double max; // fp1

  max = this->components[type].max;
  return *((float *)&max + 1);
}


// ========================================================================
// ?SetComponentCur_Impl@idTungstenHealth@@MAAXHM@Z
// EA  : 0x82BB5920
// RVA : 0x00BB5920
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idTungstenHealth::SetComponentCur_Impl(idTungstenHealth *this, const int type, double h)
{
  this->components[type].cur = h;
}


// ========================================================================
// ?SetComponentMax_Impl@idTungstenHealth@@MAAXHM@Z
// EA  : 0x82BB5930
// RVA : 0x00BB5930
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idTungstenHealth::SetComponentMax_Impl(idTungstenHealth *this, const int type, double h)
{
  this->components[type].max = h;
}


// ========================================================================
// ?GetValue@?$idBoundedFloat@$0A@$0A@$00$0A@@@UBAMXZ
// EA  : 0x82BB5940
// RVA : 0x00BB5940
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

float __fastcall idBoundedFloat<0,0,1,0>::GetValue(idTungstenHealth *this)
{
  double cur; // fp1

  cur = this->components[0].cur;
  return *((float *)&cur + 1);
}


// ========================================================================
// ?GetTotalMaxHealth_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MBAMXZ
// EA  : 0x82BB5948
// RVA : 0x00BB5948
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

float __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::GetTotalMaxHealth_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this)
{
  double max; // fp1

  max = this->components[0].max;
  return *((float *)&max + 1);
}


// ========================================================================
// ?GetBaseHealthRatio_Impl@idTungstenHealth@@MBAMXZ
// EA  : 0x82BB5950
// RVA : 0x00BB5950
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

float __fastcall idTungstenHealth::GetBaseHealthRatio_Impl(idTungstenHealth *this)
{
  double v2; // fp31
  double v3; // fp1

  v2 = ((double (__fastcall *)(idTungstenHealth *))this->GetCurBaseHealth_Impl)(a1: this);
  v3 = (float)((float)v2 / this->GetMaxBaseHealth_Impl(this));
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?SetCurBaseHealth_Impl@idTungstenHealth@@MAAXM@Z
// EA  : 0x82BB59B0
// RVA : 0x00BB59B0
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idTungstenHealth::SetCurBaseHealth_Impl(idTungstenHealth *this, double h)
{
  this->components[0].cur = 0.0;
}


// ========================================================================
// ?GetTotalHealthRatio_Impl@idTungstenHealth@@MBAMXZ
// EA  : 0x82BB59C0
// RVA : 0x00BB59C0
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

float __fastcall idTungstenHealth::GetTotalHealthRatio_Impl(idTungstenHealth *this)
{
  double v2; // fp31
  double v3; // fp1

  v2 = ((double (__fastcall *)(idTungstenHealth *))this->GetTotalMaxHealth_Impl)(a1: this);
  v3 = (float)((float)v2 + this->GetTotalCurHealth_Impl(this));
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?IsDead_Impl@idTungstenHealth@@MBA_NXZ
// EA  : 0x82BB5A20
// RVA : 0x00BB5A20
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

BOOL __fastcall idTungstenHealth::IsDead_Impl(idTungstenHealth *this)
{
  return this->isDead;
}


// ========================================================================
// ?ClearDeadFlag@idTungstenHealth@@MAAXXZ
// EA  : 0x82BB5A28
// RVA : 0x00BB5A28
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idTungstenHealth::ClearDeadFlag(idTungstenHealth *this)
{
  this->isDead = false;
}


// ========================================================================
// ?SetCurBaseHealth_Impl@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@MAAXM@Z
// EA  : 0x82C4A5A8
// RVA : 0x00C4A5A8
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idHealthT<enum aiHealthComponent_t,2,0>::SetCurBaseHealth_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        double h)
{
  this->components[0].cur = h;
}


// ========================================================================
// ?ClearDeadFlag@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MAAXXZ
// EA  : 0x82C4A5B0
// RVA : 0x00C4A5B0
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::ClearDeadFlag(
        idHealthT<enum simpleHealthComponent_t,1,0> *this)
{
  this->isDead = false;
}


// ========================================================================
// ?SetDeadFlag@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MAAXXZ
// EA  : 0x82C4A5C0
// RVA : 0x00C4A5C0
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::SetDeadFlag(
        idHealthT<enum simpleHealthComponent_t,1,0> *this)
{
  this->isDead = true;
}


// ========================================================================
// ?GetCurBaseHealth_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MBAMXZ
// EA  : 0x82C4A6E8
// RVA : 0x00C4A6E8
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

float __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::GetCurBaseHealth_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this)
{
  double cur; // fp1

  cur = this->components[0].cur;
  return *((float *)&cur + 1);
}


// ========================================================================
// ?HasMaxCurBaseHealth@idBaseHealth@@QBA_NXZ
// EA  : 0x82CF5528
// RVA : 0x00CF5528
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

BOOL __fastcall idBaseHealth::HasMaxCurBaseHealth(idBaseHealth *this)
{
  double v2; // fp31

  v2 = ((double (__fastcall *)(idBaseHealth *))this->GetCurBaseHealth_Impl)(a1: this);
  return v2 >= ((double (__fastcall *)(idBaseHealth *))this->GetMaxBaseHealth_Impl)(a1: this);
}


// ========================================================================
// ?SetCurBaseHealth@idBaseHealth@@QAAXM@Z
// EA  : 0x82E24B08
// RVA : 0x00E24B08
// PDB : w:\tech5\tungsten\game\components\healthcomponent.h
// ========================================================================

void __fastcall idBaseHealth::SetCurBaseHealth(idBaseHealth *this, double h)
{
  if ( h > 0.0 )
  {
    this->ClearDeadFlag(this);
    this->SetCurBaseHealth_Impl(this, a2: h);
  }
}

