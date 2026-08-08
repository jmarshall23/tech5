
// ========================================================================
// ?InternalPostFilterItems@idAmmoFilter@@MAAXXZ
// EA  : 0x82EB4668
// RVA : 0x00EB4668
// PDB : w:\tech5\tungsten\game\weapons\ammofilter.cpp
// ========================================================================

void __fastcall idAmmoFilter::InternalPostFilterItems(idAmmoFilter *this)
{
  idThrowableFilter::InternalPostFilterItems((bfx::Orienter *)this);
  this->weapon = nullptr;
}


// ========================================================================
// ??0idAmmoFilter@@QAA@XZ
// EA  : 0x82EB46A0
// RVA : 0x00EB46A0
// PDB : w:\tech5\tungsten\game\weapons\ammofilter.cpp
// ========================================================================

idAmmoFilter *__fastcall idAmmoFilter::idAmmoFilter(idAmmoFilter *this)
{
  idThrowableFilter::idThrowableFilter(this);
  this->weapon = nullptr;
  this->__vftable = (idAmmoFilter_vtbl *)&idAmmoFilter::`vftable';
  return this;
}


// ========================================================================
// ??0idAmmoSelector@@QAA@XZ
// EA  : 0x82EB46E8
// RVA : 0x00EB46E8
// PDB : w:\tech5\tungsten\game\weapons\ammofilter.cpp
// ========================================================================

idAmmoSelector *__fastcall idAmmoSelector::idAmmoSelector(idAmmoSelector *this)
{
  idThrowableSelector::idThrowableSelector(this);
  this->__vftable = (idAmmoSelector_vtbl *)&idAmmoSelector::`vftable';
  this->weapon = nullptr;
  this->dirToTarget.x = 0.0;
  this->dirToTarget.y = 0.0;
  this->dirToTarget.z = 0.0;
  this->distToTarget = -1.0;
  return this;
}


// ========================================================================
// ?InternalPreSelectItem@idAmmoSelector@@MAAXXZ
// EA  : 0x82EB4750
// RVA : 0x00EB4750
// PDB : w:\tech5\tungsten\game\weapons\ammofilter.cpp
// ========================================================================

void __fastcall idAmmoSelector::InternalPreSelectItem(idAmmoSelector *this)
{
  idPhysics *Physics; // r3
  const idItemTarget *target; // r30
  float *v4; // r3
  double v5; // fp9
  double v6; // fp6
  double v7; // fp7
  double v8; // fp3
  double v9; // fp4
  double v10; // fp11
  double v13; // fp9
  double v14; // fp7
  double v15; // fp8
  double v16; // fp7

  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  Physics = idEntity::GetPhysics(this: (idEntity *)this->owner);
  target = this->target;
  v4 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v5 = (float)(target->pos.x - *v4);
  v6 = (float)(target->pos.z - v4[2]);
  v7 = (float)(target->pos.y - v4[1]);
  this->dirToTarget.y = target->pos.y - v4[1];
  this->dirToTarget.z = v6;
  this->dirToTarget.x = v5;
  v8 = v5;
  v9 = v7;
  v10 = (float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)));
  _FP10 = (float)((float)((float)((float)v7 * (float)v7)
                        + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f8, f10, f11, f13 }
  v13 = (float)((float)((float)((float)v7 * (float)v7)
                      + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
              * (float)0.5);
  v14 = __frsqrte(_FP8);
  v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)v13)
                                                                              * (float)v14)
                                                                      - (float)1.5)
                                                      * (float)v14)
                                              * (float)v13)
                                      * (float)((float)-(float)((float)((float)((float)v14 * (float)v13) * (float)v14)
                                                              - (float)1.5)
                                              * (float)v14))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v14 * (float)v13) * (float)v14) - (float)1.5) * (float)v14));
  v16 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)v13)
                                                                                      * (float)v14)
                                                                              - (float)1.5)
                                                              * (float)v14)
                                                      * (float)v13)
                                              * (float)((float)-(float)((float)((float)((float)v14 * (float)v13)
                                                                              * (float)v14)
                                                                      - (float)1.5)
                                                      * (float)v14))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v14 * (float)v13) * (float)v14) - (float)1.5)
                              * (float)v14))
              * (float)v13);
  this->dirToTarget.x = (float)v8 * (float)((float)-(float)((float)((float)v16 * (float)v15) - (float)1.5) * (float)v15);
  this->dirToTarget.y = (float)v9 * (float)((float)-(float)((float)((float)v16 * (float)v15) - (float)1.5) * (float)v15);
  this->dirToTarget.z = (float)v6 * (float)((float)-(float)((float)((float)v16 * (float)v15) - (float)1.5) * (float)v15);
  this->distToTarget = (float)((float)-(float)((float)((float)v16 * (float)v15) - (float)1.5) * (float)v15) * (float)v10;
}


// ========================================================================
// ?InternalPostSelectItem@idAmmoSelector@@MAAXXZ
// EA  : 0x82EB4860
// RVA : 0x00EB4860
// PDB : w:\tech5\tungsten\game\weapons\ammofilter.cpp
// ========================================================================

void __fastcall idAmmoSelector::InternalPostSelectItem(idAmmoSelector *this)
{
  idThrowableFilter::InternalPostFilterItems((bfx::Orienter *)this);
  this->weapon = nullptr;
  this->dirToTarget = vec3_origin;
  this->distToTarget = -1.0;
}


// ========================================================================
// ??0idAmmoSelector_LargeRangedMutant@@QAA@XZ
// EA  : 0x82EB48C0
// RVA : 0x00EB48C0
// PDB : w:\tech5\tungsten\game\weapons\ammofilter.cpp
// ========================================================================

idAmmoSelector_LargeRangedMutant *__fastcall idAmmoSelector_LargeRangedMutant::idAmmoSelector_LargeRangedMutant(
        idAmmoSelector_LargeRangedMutant *this)
{
  idThrowableSelector::idThrowableSelector(this);
  this->weapon = nullptr;
  this->dirToTarget.x = 0.0;
  this->dirToTarget.y = 0.0;
  this->dirToTarget.z = 0.0;
  this->__vftable = (idAmmoSelector_LargeRangedMutant_vtbl *)&idAmmoSelector_LargeRangedMutant::`vftable';
  this->distToTarget = -1.0;
  return this;
}


// ========================================================================
// ??0idAmmoSelector_ScoopMutant@@QAA@XZ
// EA  : 0x82EB4928
// RVA : 0x00EB4928
// PDB : w:\tech5\tungsten\game\weapons\ammofilter.cpp
// ========================================================================

idAmmoSelector_ScoopMutant *__fastcall idAmmoSelector_ScoopMutant::idAmmoSelector_ScoopMutant(
        idAmmoSelector_ScoopMutant *this)
{
  idThrowableSelector::idThrowableSelector(this);
  this->weapon = nullptr;
  this->dirToTarget.x = 0.0;
  this->dirToTarget.y = 0.0;
  this->dirToTarget.z = 0.0;
  this->__vftable = (idAmmoSelector_ScoopMutant_vtbl *)&idAmmoSelector_ScoopMutant::`vftable';
  this->distToTarget = -1.0;
  return this;
}


// ========================================================================
// ??0idAmmoSelector_DualMutant@@QAA@XZ
// EA  : 0x82EB4990
// RVA : 0x00EB4990
// PDB : w:\tech5\tungsten\game\weapons\ammofilter.cpp
// ========================================================================

idAmmoSelector_DualMutant *__fastcall idAmmoSelector_DualMutant::idAmmoSelector_DualMutant(
        idAmmoSelector_DualMutant *this)
{
  idThrowableSelector::idThrowableSelector(this);
  this->weapon = nullptr;
  this->dirToTarget.x = 0.0;
  this->dirToTarget.y = 0.0;
  this->dirToTarget.z = 0.0;
  this->__vftable = (idAmmoSelector_DualMutant_vtbl *)&idAmmoSelector_DualMutant::`vftable';
  this->distToTarget = -1.0;
  return this;
}


// ========================================================================
// ??0idAmmoSelector_ClubMutant@@QAA@XZ
// EA  : 0x82EB49F8
// RVA : 0x00EB49F8
// PDB : w:\tech5\tungsten\game\weapons\ammofilter.cpp
// ========================================================================

idAmmoSelector_ClubMutant *__fastcall idAmmoSelector_ClubMutant::idAmmoSelector_ClubMutant(
        idAmmoSelector_ClubMutant *this)
{
  idThrowableSelector::idThrowableSelector(this);
  this->weapon = nullptr;
  this->dirToTarget.x = 0.0;
  this->dirToTarget.y = 0.0;
  this->dirToTarget.z = 0.0;
  this->__vftable = (idAmmoSelector_ClubMutant_vtbl *)&idAmmoSelector_ClubMutant::`vftable';
  this->distToTarget = -1.0;
  return this;
}


// ========================================================================
// ??0idAmmoSelector_PipeBandit@@QAA@XZ
// EA  : 0x82EB4A60
// RVA : 0x00EB4A60
// PDB : w:\tech5\tungsten\game\weapons\ammofilter.cpp
// ========================================================================

idAmmoSelector_PipeBandit *__fastcall idAmmoSelector_PipeBandit::idAmmoSelector_PipeBandit(
        idAmmoSelector_PipeBandit *this)
{
  idThrowableSelector::idThrowableSelector(this);
  this->weapon = nullptr;
  this->dirToTarget.x = 0.0;
  this->dirToTarget.y = 0.0;
  this->dirToTarget.z = 0.0;
  this->__vftable = (idAmmoSelector_PipeBandit_vtbl *)&idAmmoSelector_PipeBandit::`vftable';
  this->distToTarget = -1.0;
  return this;
}


// ========================================================================
// ??0idAmmoSelector_HeavyBandit@@QAA@XZ
// EA  : 0x82EB4AC8
// RVA : 0x00EB4AC8
// PDB : w:\tech5\tungsten\game\weapons\ammofilter.cpp
// ========================================================================

idAmmoSelector_HeavyBandit *__fastcall idAmmoSelector_HeavyBandit::idAmmoSelector_HeavyBandit(
        idAmmoSelector_HeavyBandit *this)
{
  idThrowableSelector::idThrowableSelector(this);
  this->weapon = nullptr;
  this->dirToTarget.x = 0.0;
  this->dirToTarget.y = 0.0;
  this->dirToTarget.z = 0.0;
  this->__vftable = (idAmmoSelector_HeavyBandit_vtbl *)&idAmmoSelector_HeavyBandit::`vftable';
  this->distToTarget = -1.0;
  return this;
}


// ========================================================================
// ??0idAmmoSelector_Imp@@QAA@XZ
// EA  : 0x82EB4B30
// RVA : 0x00EB4B30
// PDB : w:\tech5\tungsten\game\weapons\ammofilter.cpp
// ========================================================================

idAmmoSelector_Imp *__fastcall idAmmoSelector_Imp::idAmmoSelector_Imp(idAmmoSelector_Imp *this)
{
  idThrowableSelector::idThrowableSelector(this);
  this->weapon = nullptr;
  this->dirToTarget.x = 0.0;
  this->dirToTarget.y = 0.0;
  this->dirToTarget.z = 0.0;
  this->__vftable = (idAmmoSelector_Imp_vtbl *)&idAmmoSelector_Imp::`vftable';
  this->distToTarget = -1.0;
  return this;
}


// ========================================================================
// ?InternalFilter@idAmmoFilter@@MBA_NPBVidInventoryItem@@@Z
// EA  : 0x82EB4B98
// RVA : 0x00EB4B98
// PDB : w:\tech5\tungsten\game\weapons\ammofilter.cpp
// ========================================================================

BOOL __fastcall idAmmoFilter::InternalFilter(idAmmoFilter *this, const idInventoryItem *item)
{
  const idDeclInventory *decl; // r31
  int v4; // r4

  decl = item->decl;
  return decl != nullptr
      && ((v4 = (&idDeclAmmo::resourceList != decl->GetDeclInfo(this: item->decl)) - 1) & (unsigned int)decl) != 0
      && *(_DWORD *)((v4 & (unsigned int)decl) + 0x1F8) != 0;
}


// ========================================================================
// ?InternalGetWeight@idAmmoSelector@@MBAMPBVidInventoryItem@@@Z
// EA  : 0x82EB4C20
// RVA : 0x00EB4C20
// PDB : w:\tech5\tungsten\game\weapons\ammofilter.cpp
// ========================================================================

float __fastcall idAmmoSelector::InternalGetWeight(idAmmoSelector *this, const idInventoryItem *item)
{
  const idDeclInventory *decl; // r31
  double v4; // fp1
  __int64 v5; // r8
  __int64 v6; // r6
  const idDeclAmmo *v7; // r31
  idWeapon *weapon; // r3
  _DWORD *v9; // r11
  double distToTarget; // fp0
  __int64 v11; // r10
  int v12; // r10
  __int64 v13; // r11
  int v14; // r11
  __int64 v15; // r8

  decl = item->decl;
  if ( decl == nullptr )
    goto LABEL_2;
  HIDWORD(v5) = (char *)&idDeclAmmo::resourceList - (char *)decl->GetDeclInfo(this: item->decl);
  v7 = HIDWORD(v5) != 0 ? nullptr : (const idDeclAmmo *)decl;
  if ( v7 == nullptr )
    goto LABEL_2;
  weapon = (idWeapon *)this->weapon;
  if ( weapon != nullptr && !idWeapon::IsValidAmmo(this: weapon, ammoDecl: v7, secondaryAmmo: false) )
    goto LABEL_2;
  v9 = &v7->projectileDecl->__vftable;
  if ( v9 != nullptr
    && (HIDWORD(v11) = v9[117],
        distToTarget = this->distToTarget,
        LODWORD(v11) = HIDWORD(v11),
        distToTarget <= (float)v11)
    && (LODWORD(v5) = v9[118], distToTarget >= (float)v5) )
  {
    v12 = v9[119];
    LODWORD(v5) = v12;
    if ( distToTarget >= (float)v5 )
    {
      v14 = v9[119];
      HIDWORD(v15) = HIDWORD(v11) - v14;
      LODWORD(v15) = v14;
      LODWORD(v6) = HIDWORD(v11) - v14;
      v4 = (float)((float)1.0 - (float)((float)(this->distToTarget - (float)v15) / (float)v6));
    }
    else
    {
      LODWORD(v13) = v9[118];
      HIDWORD(v13) = v12 - v13;
      LODWORD(v5) = HIDWORD(v13);
      v4 = (float)((float)(this->distToTarget - (float)v13) / (float)v5);
    }
  }
  else
  {
LABEL_2:
    v4 = -1.0;
  }
  return *((float *)&v4 + 1);
}

