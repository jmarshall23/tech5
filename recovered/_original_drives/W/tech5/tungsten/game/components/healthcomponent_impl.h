
// ========================================================================
// ?Damage_Impl@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@MAA_NM_NAAM@Z
// EA  : 0x829F6180
// RVA : 0x009F6180
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

BOOL __fastcall idHealthT<enum aiHealthComponent_t,2,0>::Damage_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        double d,
        const bool allowDeath,
        float *remainingDamage,
        int a5)
{
  return ((bool (__fastcall *)(idHealthT<enum aiHealthComponent_t,2,0> *, int, float *, float *, int, int, double))this->DamageComponent_Impl)(
           a1: this,
           a2: 1,
           a3: remainingDamage,
           a4: remainingDamage,
           a5: 1,
           a6: a5,
           a7: d);
}


// ========================================================================
// ?Heal_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MAAXM@Z
// EA  : 0x829F61A0
// RVA : 0x009F61A0
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::Heal_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        double h,
        int a3,
        int a4)
{
  ((void (__fastcall *)(idHealthT<enum aiHealthComponent_t,2,0> *, _DWORD, int, int, double))this->HealComponent_Impl)(
    a1: this,
    a2: 0,
    a3: a4,
    a4: 1,
    a5: h);
}


// ========================================================================
// ?Kill_Impl@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@MAAXM@Z
// EA  : 0x829F61B8
// RVA : 0x009F61B8
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum aiHealthComponent_t,2,0>::Kill_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        double d)
{
  if ( !this->isDead )
  {
    this->killingBlowDamage = d;
    this->isDead = true;
  }
}


// ========================================================================
// ?Reset_Impl@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@MAAXXZ
// EA  : 0x829F61D8
// RVA : 0x009F61D8
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum aiHealthComponent_t,2,0>::Reset_Impl(idHealthT<enum aiHealthComponent_t,2,0> *this)
{
  double max; // fp13

  max = this->components[1].max;
  this->components[0].cur = this->components[0].max;
  this->components[1].cur = max;
  this->isDead = false;
  this->killingBlowDamage = 0.0;
}


// ========================================================================
// ?HealComponent_Impl@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@MAAXHM_N@Z
// EA  : 0x829F6200
// RVA : 0x009F6200
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum aiHealthComponent_t,2,0>::HealComponent_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        const int type,
        double h,
        bool overflow,
        char a5)
{
  double v5; // fp13
  double max; // fp0
  double v7; // fp12
  double v8; // fp11

  if ( h >= 0.0 )
  {
    if ( type == 1 )
    {
      v5 = (float)(this->components[1].cur + (float)h);
      max = this->components[1].max;
      this->components[1].cur = this->components[1].cur + (float)h;
      if ( v5 >= max )
        this->components[1].cur = max;
    }
    else
    {
      v7 = (float)(this->components[type].cur + (float)h);
      v8 = this->components[type].max;
      this->components[type].cur = this->components[type].cur + (float)h;
      this->isDead = false;
      if ( (float)((float)v7 - (float)v8) > 0.0 )
      {
        this->components[type].cur = this->components[type].max;
        if ( a5 != 0 )
          ((void (__fastcall *)(idHealthT<enum aiHealthComponent_t,2,0> *, int, bool))this->HealComponent_Impl)(
            a1: this,
            a2: type + 1,
            a3: overflow);
      }
    }
  }
}


// ========================================================================
// ?GetTotalCurHealth_Impl@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@MBAMXZ
// EA  : 0x829F6298
// RVA : 0x009F6298
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

float __fastcall idHealthT<enum aiHealthComponent_t,2,0>::GetTotalCurHealth_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this)
{
  double v1; // fp1

  v1 = (float)(this->components[1].cur + this->components[0].cur);
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?GetTotalMaxHealth_Impl@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@MBAMXZ
// EA  : 0x829F62A8
// RVA : 0x009F62A8
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

float __fastcall idHealthT<enum aiHealthComponent_t,2,0>::GetTotalMaxHealth_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this)
{
  double v1; // fp1

  v1 = (float)(this->components[1].max + this->components[0].max);
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?AccumulateDamage@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@ABAXM@Z
// EA  : 0x829F62B8
// RVA : 0x009F62B8
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum aiHealthComponent_t,2,0>::AccumulateDamage(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        double d)
{
  if ( gameLocal->GetGameFrame(this: gameLocal) == this->accumulatedDamageFrame )
  {
    this->accumulatedFrameDamage = this->accumulatedFrameDamage + (float)d;
  }
  else
  {
    this->accumulatedFrameDamage = d;
    this->accumulatedDamageFrame = gameLocal->GetGameFrame(this: gameLocal);
  }
}


// ========================================================================
// ?ApplyDamageWithOverflow@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@ABAXAAM0@Z
// EA  : 0x829F6348
// RVA : 0x009F6348
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum aiHealthComponent_t,2,0>::ApplyDamageWithOverflow(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        float *d,
        float *healthComponent)
{
  if ( *d < (double)*healthComponent )
  {
    *healthComponent = *healthComponent - *d;
    idHealthT<enum aiHealthComponent_t,2,0>::AccumulateDamage(this, d: *d);
    *d = 0.0;
  }
  else
  {
    *d = *d - *healthComponent;
    idHealthT<enum aiHealthComponent_t,2,0>::AccumulateDamage(this, d: *healthComponent);
    *healthComponent = 0.0;
  }
}


// ========================================================================
// ?ApplyDamageAndClampToZero@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@ABAXAAM0@Z
// EA  : 0x829F63C8
// RVA : 0x009F63C8
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum aiHealthComponent_t,2,0>::ApplyDamageAndClampToZero(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        float *d,
        float *healthComponent)
{
  double v4; // fp1
  double v6; // fp0

  v4 = *healthComponent;
  if ( *d < v4 )
  {
    idHealthT<enum aiHealthComponent_t,2,0>::AccumulateDamage(this, d: *d);
    *healthComponent = *healthComponent - *d;
    v6 = 0.0;
  }
  else
  {
    idHealthT<enum aiHealthComponent_t,2,0>::AccumulateDamage(this, d: v4);
    v6 = 0.0;
    *healthComponent = 0.0;
  }
  *d = v6;
}


// ========================================================================
// ?DamageComponent_Impl@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@MAA_NHM_N0AAM@Z
// EA  : 0x829F6448
// RVA : 0x009F6448
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

int __fastcall idHealthT<enum aiHealthComponent_t,2,0>::DamageComponent_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        const int type,
        double d,
        const bool allowDeath,
        const bool overflow,
        float *remainingDamage,
        float *a7)
{
  idHealthT<enum aiHealthComponent_t,2,0>::component_t *v12; // r28
  double v13; // fp0
  double v14; // fp12
  float *p_cur; // r5

  v12 = &this->components[type];
  if ( type == 0 )
  {
    idHealthT<enum aiHealthComponent_t,2,0>::AccumulateDamage(this, d);
    *a7 = d;
    if ( !this->isDead )
    {
      v13 = (float)((float)d - v12->cur);
      if ( v13 >= 0.0 )
      {
        if ( v13 > d )
          v13 = d;
      }
      else
      {
        v13 = 0.0;
      }
      *a7 = v13;
      v14 = (float)(v12->cur - (float)d);
      v12->cur = v12->cur - (float)d;
      if ( v14 <= 0.0 )
      {
        if ( overflow && d >= this->killThreshold )
        {
          idBaseHealth::Kill(this, d);
          return 1;
        }
        v12->cur = 1.0;
      }
    }
    return 0;
  }
  *a7 = d;
  p_cur = &this->components[type].cur;
  if ( (_BYTE)remainingDamage != 0 )
  {
    idHealthT<enum aiHealthComponent_t,2,0>::ApplyDamageWithOverflow(this, d: a7, healthComponent: p_cur);
    if ( *a7 <= 0.0 )
      return 0;
    return ((int (__fastcall *)(idHealthT<enum aiHealthComponent_t,2,0> *, int))this->DamageComponent_Impl)(
             a1: this,
             a2: type - 1);
  }
  else
  {
    idHealthT<enum aiHealthComponent_t,2,0>::ApplyDamageAndClampToZero(this, d: a7, healthComponent: p_cur);
    return 0;
  }
}


// ========================================================================
// ?WriteComponents_Impl@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@MBAXPAVidFile@@@Z
// EA  : 0x829F65A8
// RVA : 0x009F65A8
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum aiHealthComponent_t,2,0>::WriteComponents_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        idFile *file)
{
  float *p_cur; // r30
  int i; // r29

  p_cur = &this->components[0].cur;
  for ( i = 2; i != 0; --i )
  {
    file->Write(this: file, a2: p_cur - 1, a3: 4u);
    file->Write(this: file, a2: p_cur, a3: 4u);
    p_cur += 3;
  }
  file->Write(this: file, a2: &this->killingBlowDamage, a3: 4u);
  file->Write(this: file, a2: &this->accumulatedFrameDamage, a3: 4u);
  file->Write(this: file, a2: &this->accumulatedDamageFrame, a3: 4u);
  file->Write(this: file, a2: &this->isDead, a3: 1u);
}


// ========================================================================
// ?ReadComponents_Impl@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@MAAXPAVidFile@@@Z
// EA  : 0x829FC5A0
// RVA : 0x009FC5A0
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum aiHealthComponent_t,2,0>::ReadComponents_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this,
        idFile *file)
{
  float *p_cur; // r30
  int i; // r29

  p_cur = &this->components[0].cur;
  for ( i = 2; i != 0; --i )
  {
    file->Read(this: file, a2: p_cur - 1, a3: 4u);
    file->Read(this: file, a2: p_cur, a3: 4u);
    p_cur += 3;
  }
  file->Read(this: file, a2: &this->killingBlowDamage, a3: 4u);
  file->Read(this: file, a2: &this->accumulatedFrameDamage, a3: 4u);
  file->Read(this: file, a2: &this->accumulatedDamageFrame, a3: 4u);
  file->Read(this: file, a2: &this->isDead, a3: 1u);
}


// ========================================================================
// ?Update_Impl@?$idShieldHealthT@W4aiHealthComponent_t@@$01$0A@$00@@UAAXXZ
// EA  : 0x829FC6B0
// RVA : 0x009FC6B0
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idShieldHealthT<enum aiHealthComponent_t,2,0,1>::Update_Impl(
        idShieldHealthT<enum aiHealthComponent_t,2,0,1> *this)
{
  int v2; // r30
  int accumulatedDamageFrame; // r29
  __int64 v4; // r10
  __int64 v5; // r4
  __int64 v6; // r6 OVERLAPPED
  double v7; // fp31
  double v8; // fp1
  int lastShieldIntervalFrame; // r11

  if ( !this->IsDead_Impl(this) && this->components[1].cur < (double)this->components[1].max )
  {
    v2 = gameLocal->GetGameFrame(this: gameLocal);
    accumulatedDamageFrame = this->accumulatedDamageFrame;
    v5 = ((__int64 (__fastcall *)(idGameLocal *, int))gameLocal->GetGameHz)(a1: gameLocal, a2: 1);
    LODWORD(v6) = HIDWORD(v5);
    HIDWORD(v6) = v2 - accumulatedDamageFrame;
    v7 = (float)((float)1.0 / (float)v6);
    v8 = (float)((float)*(__int64 *)((char *)&v6 + 4) * (float)((float)1.0 / (float)v6));
    if ( v8 >= this->shieldRegenDelay )
    {
      if ( this->lastShieldIntervalFrame <= 0 )
      {
        this->lastShieldIntervalFrame = v2 - (int)(float)(this->shieldRegenInterval * (float)v6);
        idLib::Printf(fmt: "Regen started %.2f seconds after last damage.\n", v8);
      }
      lastShieldIntervalFrame = this->lastShieldIntervalFrame;
      if ( lastShieldIntervalFrame >= 0 )
      {
        LODWORD(v4) = v2 - lastShieldIntervalFrame;
        if ( (float)((float)v4 * (float)v7) >= (double)this->shieldRegenInterval )
        {
          this->lastShieldIntervalFrame = v2;
          ((void (__fastcall *)(idShieldHealthT<enum aiHealthComponent_t,2,0,1> *, int, double))this->HealComponent_Impl)(
            a1: this,
            a2: 1,
            a3: (float)(this->shieldRegenRate * (float)((float)v4 * (float)v7)));
        }
      }
    }
    else
    {
      this->lastShieldIntervalFrame = -1;
    }
  }
}


// ========================================================================
// ?Damage_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MAA_NM_NAAM@Z
// EA  : 0x82C4A5D0
// RVA : 0x00C4A5D0
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

BOOL __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::Damage_Impl(
        idHealthT<enum simpleHealthComponent_t,1,0> *this,
        double d,
        const bool allowDeath,
        float *remainingDamage,
        int a5)
{
  return ((bool (__fastcall *)(idHealthT<enum simpleHealthComponent_t,1,0> *, _DWORD, float *, float *, _DWORD, int, double))this->DamageComponent_Impl)(
           a1: this,
           a2: 0,
           a3: remainingDamage,
           a4: remainingDamage,
           a5: 0,
           a6: a5,
           a7: d);
}


// ========================================================================
// ?Kill_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MAAXM@Z
// EA  : 0x82C4A5F0
// RVA : 0x00C4A5F0
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::Kill_Impl(
        idHealthT<enum simpleHealthComponent_t,1,0> *this,
        double d)
{
  if ( !this->isDead )
  {
    this->killingBlowDamage = d;
    this->isDead = true;
  }
}


// ========================================================================
// ?Reset_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MAAXXZ
// EA  : 0x82C4A610
// RVA : 0x00C4A610
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::Reset_Impl(
        idHealthT<enum simpleHealthComponent_t,1,0> *this)
{
  this->components[0].cur = this->components[0].max;
  this->isDead = false;
  this->killingBlowDamage = 0.0;
}


// ========================================================================
// ?HealComponent_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MAAXHM_N@Z
// EA  : 0x82C4A630
// RVA : 0x00C4A630
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::HealComponent_Impl(
        idHealthT<enum simpleHealthComponent_t,1,0> *this,
        const int type,
        double h,
        bool overflow,
        char a5)
{
  double v5; // fp13
  double v6; // fp0
  double v7; // fp12
  double max; // fp11

  if ( h >= 0.0 )
  {
    if ( type != 0 )
    {
      v7 = (float)(this->components[type].cur + (float)h);
      max = this->components[type].max;
      this->components[type].cur = this->components[type].cur + (float)h;
      this->isDead = false;
      if ( (float)((float)v7 - (float)max) > 0.0 )
      {
        this->components[type].cur = this->components[type].max;
        if ( a5 != 0 )
          ((void (__fastcall *)(idHealthT<enum simpleHealthComponent_t,1,0> *, int, bool))this->HealComponent_Impl)(
            a1: this,
            a2: type + 1,
            a3: overflow);
      }
    }
    else
    {
      v5 = (float)(this->components[0].cur + (float)h);
      v6 = this->components[0].max;
      this->components[0].cur = this->components[0].cur + (float)h;
      if ( v5 >= v6 )
        this->components[0].cur = v6;
    }
  }
}


// ========================================================================
// ?GetBaseHealthRatio_Impl@?$idHealthT@W4aiHealthComponent_t@@$01$0A@@@MBAMXZ
// EA  : 0x82C4A6C8
// RVA : 0x00C4A6C8
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

float __fastcall idHealthT<enum aiHealthComponent_t,2,0>::GetBaseHealthRatio_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this)
{
  double v1; // fp1

  v1 = 0.0;
  if ( this->components[0].max > 0.0 )
    v1 = (float)(this->components[0].cur / this->components[0].max);
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?GetTotalHealthRatio_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MBAMXZ
// EA  : 0x82C4A6F0
// RVA : 0x00C4A6F0
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

float __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::GetTotalHealthRatio_Impl(
        idHealthT<enum aiHealthComponent_t,2,0> *this)
{
  double v2; // fp31
  double v3; // fp1

  v2 = ((double (__fastcall *)(idHealthT<enum aiHealthComponent_t,2,0> *))this->GetTotalCurHealth_Impl)(a1: this);
  v3 = (float)((float)v2 / this->GetTotalMaxHealth_Impl(this));
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?AccumulateDamage@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@ABAXM@Z
// EA  : 0x82C4A750
// RVA : 0x00C4A750
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::AccumulateDamage(
        idHealthT<enum simpleHealthComponent_t,1,0> *this,
        double d)
{
  if ( gameLocal->GetGameFrame(this: gameLocal) == this->accumulatedDamageFrame )
  {
    this->accumulatedFrameDamage = this->accumulatedFrameDamage + (float)d;
  }
  else
  {
    this->accumulatedFrameDamage = d;
    this->accumulatedDamageFrame = gameLocal->GetGameFrame(this: gameLocal);
  }
}


// ========================================================================
// ?ApplyDamageWithOverflow@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@ABAXAAM0@Z
// EA  : 0x82C4A7E0
// RVA : 0x00C4A7E0
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::ApplyDamageWithOverflow(
        idHealthT<enum simpleHealthComponent_t,1,0> *this,
        float *d,
        float *healthComponent)
{
  if ( *d < (double)*healthComponent )
  {
    *healthComponent = *healthComponent - *d;
    idHealthT<enum simpleHealthComponent_t,1,0>::AccumulateDamage(this, d: *d);
    *d = 0.0;
  }
  else
  {
    *d = *d - *healthComponent;
    idHealthT<enum simpleHealthComponent_t,1,0>::AccumulateDamage(this, d: *healthComponent);
    *healthComponent = 0.0;
  }
}


// ========================================================================
// ?ApplyDamageAndClampToZero@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@ABAXAAM0@Z
// EA  : 0x82C4A860
// RVA : 0x00C4A860
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::ApplyDamageAndClampToZero(
        idHealthT<enum simpleHealthComponent_t,1,0> *this,
        float *d,
        float *healthComponent)
{
  double v4; // fp1
  double v6; // fp0

  v4 = *healthComponent;
  if ( *d < v4 )
  {
    idHealthT<enum simpleHealthComponent_t,1,0>::AccumulateDamage(this, d: *d);
    *healthComponent = *healthComponent - *d;
    v6 = 0.0;
  }
  else
  {
    idHealthT<enum simpleHealthComponent_t,1,0>::AccumulateDamage(this, d: v4);
    v6 = 0.0;
    *healthComponent = 0.0;
  }
  *d = v6;
}


// ========================================================================
// ?DamageComponent_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MAA_NHM_N0AAM@Z
// EA  : 0x82C4A8E0
// RVA : 0x00C4A8E0
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

int __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::DamageComponent_Impl(
        idHealthT<enum simpleHealthComponent_t,1,0> *this,
        const int type,
        double d,
        const bool allowDeath,
        const bool overflow,
        float *remainingDamage,
        float *a7)
{
  idHealthT<enum simpleHealthComponent_t,1,0>::component_t *v12; // r28
  double v13; // fp0
  double v14; // fp12
  float *p_cur; // r5

  v12 = &this->components[type];
  if ( type == 0 )
  {
    idHealthT<enum simpleHealthComponent_t,1,0>::AccumulateDamage(this, d);
    *a7 = d;
    if ( !this->isDead )
    {
      v13 = (float)((float)d - v12->cur);
      if ( v13 >= 0.0 )
      {
        if ( v13 > d )
          v13 = d;
      }
      else
      {
        v13 = 0.0;
      }
      *a7 = v13;
      v14 = (float)(v12->cur - (float)d);
      v12->cur = v12->cur - (float)d;
      if ( v14 <= 0.0 )
      {
        if ( overflow && d >= this->killThreshold )
        {
          idBaseHealth::Kill(this, d);
          return 1;
        }
        v12->cur = 1.0;
      }
    }
    return 0;
  }
  *a7 = d;
  p_cur = &this->components[type].cur;
  if ( (_BYTE)remainingDamage != 0 )
  {
    idHealthT<enum simpleHealthComponent_t,1,0>::ApplyDamageWithOverflow(this, d: a7, healthComponent: p_cur);
    if ( *a7 <= 0.0 )
      return 0;
    return ((int (__fastcall *)(idHealthT<enum simpleHealthComponent_t,1,0> *, int))this->DamageComponent_Impl)(
             a1: this,
             a2: type - 1);
  }
  else
  {
    idHealthT<enum simpleHealthComponent_t,1,0>::ApplyDamageAndClampToZero(this, d: a7, healthComponent: p_cur);
    return 0;
  }
}


// ========================================================================
// ?WriteComponents_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MBAXPAVidFile@@@Z
// EA  : 0x82C4AA40
// RVA : 0x00C4AA40
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::WriteComponents_Impl(
        idHealthT<enum simpleHealthComponent_t,1,0> *this,
        idFile *file)
{
  file->Write(this: file, a2: &this->components[0].max, a3: 4u);
  file->Write(this: file, a2: &this->components[0].cur, a3: 4u);
  file->Write(this: file, a2: &this->killingBlowDamage, a3: 4u);
  file->Write(this: file, a2: &this->accumulatedFrameDamage, a3: 4u);
  file->Write(this: file, a2: &this->accumulatedDamageFrame, a3: 4u);
  file->Write(this: file, a2: &this->isDead, a3: 1u);
}


// ========================================================================
// ?ReadComponents_Impl@?$idHealthT@W4simpleHealthComponent_t@@$00$0A@@@MAAXPAVidFile@@@Z
// EA  : 0x82C4AEC8
// RVA : 0x00C4AEC8
// PDB : w:\tech5\tungsten\game\components\healthcomponent_impl.h
// ========================================================================

void __fastcall idHealthT<enum simpleHealthComponent_t,1,0>::ReadComponents_Impl(
        idHealthT<enum simpleHealthComponent_t,1,0> *this,
        idFile *file)
{
  file->Read(this: file, a2: &this->components[0].max, a3: 4u);
  file->Read(this: file, a2: &this->components[0].cur, a3: 4u);
  file->Read(this: file, a2: &this->killingBlowDamage, a3: 4u);
  file->Read(this: file, a2: &this->accumulatedFrameDamage, a3: 4u);
  file->Read(this: file, a2: &this->accumulatedDamageFrame, a3: 4u);
  file->Read(this: file, a2: &this->isDead, a3: 1u);
}

