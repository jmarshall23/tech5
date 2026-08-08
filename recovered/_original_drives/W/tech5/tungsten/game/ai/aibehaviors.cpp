
// ========================================================================
// ??0idAIBehaviors@@QAA@XZ
// EA  : 0x82A3F278
// RVA : 0x00A3F278
// PDB : w:\tech5\tungsten\game\ai\aibehaviors.cpp
// ========================================================================

idAIBehaviors *__fastcall idAIBehaviors::idAIBehaviors(idAIBehaviors *this)
{
  this->decl = nullptr;
  this->__vftable = (idAIBehaviors_vtbl *)&idAIBehaviors::`vftable';
  this->avoidRadius = 0.0;
  this->declBehaviorVo = nullptr;
  this->declBehaviorVoChains = nullptr;
  this->declBehaviorEvents = nullptr;
  this->aimTrackingParms = nullptr;
  this->lookTrackingParms = nullptr;
  return this;
}


// ========================================================================
// ?GetWeaponCoverCapabilities@idAIBehaviors@@QBA_NPBVidWeapon@@W4posture_t@@W4coverOrientation_t@@AAVidCoverCapabilities@@@Z
// EA  : 0x82A3F520
// RVA : 0x00A3F520
// PDB : w:\tech5\tungsten\game\ai\aibehaviors.cpp
// ========================================================================

int __fastcall idAIBehaviors::GetWeaponCoverCapabilities(
        idAIBehaviors *this,
        const idWeapon *weapon,
        const posture_t coverPosture,
        const coverOrientation_t coverOrientation,
        idCoverCapabilities *caps)
{
  const idDeclAIBehavior *decl; // r11
  _DWORD *v6; // r10
  const idCoverCapabilities *v7; // r4
  _DWORD v9[4]; // [sp+50h] [-30h] BYREF
  _DWORD v10[6]; // [sp+60h] [-20h] BYREF

  if ( weapon == nullptr )
    return 0;
  decl = this->decl;
  v9[0] = 0;
  v10[0] = 0;
  v9[1] = &decl->forwardCoverCaps;
  v9[2] = &decl->forwardCoverCaps.pistolCoverCaps;
  v9[3] = &decl->forwardCoverCaps.rifleCoverCaps;
  v10[1] = &decl->backwardCoverCaps;
  v10[2] = &decl->backwardCoverCaps.pistolCoverCaps;
  v10[3] = &decl->backwardCoverCaps.rifleCoverCaps;
  if ( coverOrientation == COVERORIENT_FORWARD )
  {
    v6 = v9;
  }
  else
  {
    if ( coverOrientation != COVERORIENT_BACKWARD )
      return 0;
    v6 = v10;
  }
  v7 = (const idCoverCapabilities *)v6[*(_DWORD *)&weapon->decl[2].usable];
  if ( v7 == nullptr )
    return 0;
  if ( coverPosture == POSTURE_STANDING )
  {
    ++v7;
  }
  else if ( coverPosture != POSTURE_CROUCHED )
  {
    return 0;
  }
  idCoverCapabilities::operator=(this: caps, __that: v7);
  return 1;
}


// ========================================================================
// ?HasCoverCapability@idAIBehaviors@@QBA_NPBVidAI2@@W4posture_t@@W4coverOrientation_t@@ABVidCoverCapabilities@@@Z
// EA  : 0x82A3F5F8
// RVA : 0x00A3F5F8
// PDB : w:\tech5\tungsten\game\ai\aibehaviors.cpp
// ========================================================================

BOOL __fastcall idAIBehaviors::HasCoverCapability(
        idAIBehaviors *this,
        const idAI2 *ai,
        posture_t coverPosture,
        coverOrientation_t coverOrientation,
        const idCoverCapabilities *coverCaps)
{
  const idWeapon *v9; // r3
  idCoverCapabilities v11[5]; // [sp+50h] [-40h] BYREF

  *((_BYTE *)&v11[0].idCoverActions + 4) &= 7u;
  v11[0].__vftable = (idCoverCapabilities_vtbl *)&idCoverCapabilities::`vftable';
  *((_BYTE *)v11 + 8) &= 1u;
  v9 = ai->GetEquippedWeapon(this: ai);
  idAIBehaviors::GetWeaponCoverCapabilities(this, weapon: v9, coverPosture, coverOrientation, caps: v11);
  return idCoverCapabilities::HasCapability(this: v11, other: coverCaps);
}


// ========================================================================
// __unwind$487482
// EA  : 0x82A3F67C
// RVA : 0x00A3F67C
// PDB : w:\tech5\tungsten\game\ai\aibehaviors.cpp
// ========================================================================

void _unwind_487482()
{
  int v0; // r12

  idCoverActions::~idCoverActions(this: (idCoverActions *)(v0 - 144 + 80));
}


// ========================================================================
// ?FindBestCoverOrientation@idAIBehaviors@@QBA?AW4coverOrientation_t@@PBVidAI2@@ABVidAICover@@@Z
// EA  : 0x82A3F6B0
// RVA : 0x00A3F6B0
// PDB : w:\tech5\tungsten\game\ai\aibehaviors.cpp
// ========================================================================

int __fastcall idAIBehaviors::FindBestCoverOrientation(idAIBehaviors *this, idAI2 *ai, idAICover *cover)
{
  bool IsPartiallyExposed; // r25
  idSkillSetting<bool> *p_usesForwardCover; // r27
  aiSkill_t ModifiedSkill; // r3
  idSkillSetting<bool> *p_usesBackwardCover; // r26
  bool v10; // r27
  char v11; // r11
  idWeapon *v13; // r29
  posture_t CoverPosture; // r3
  posture_t v15; // r3
  const idDeclInventory *decl; // r10
  const idDeclAIBehavior *v17; // r11
  int v18; // r5
  const idCoverCapabilities *v19; // r4
  int v20; // r30
  idCoverActions v21; // [sp+50h] [-90h] BYREF
  idCoverCapabilities v22; // [sp+58h] [-88h] BYREF
  idCoverCapabilities v23; // [sp+68h] [-78h] BYREF
  idCoverCapabilities v24[2]; // [sp+78h] [-68h] BYREF
  _DWORD v25[20]; // [sp+90h] [-50h] BYREF

  IsPartiallyExposed = idAICover::IsPartiallyExposed(this: cover);
  p_usesForwardCover = &this->decl->takeCoverBehaviors.usesForwardCover;
  ModifiedSkill = idAI2::GetModifiedSkill(this: ai);
  p_usesBackwardCover = &this->decl->takeCoverBehaviors.usesBackwardCover;
  v10 = p_usesForwardCover->setting[ModifiedSkill];
  if ( !p_usesBackwardCover->setting[idAI2::GetModifiedSkill(this: ai)] || (v11 = 1, IsPartiallyExposed) )
    v11 = 0;
  if ( !v10 && v11 != 0 )
    return 3;
  if ( v11 == 0 )
  {
    if ( v10 )
      return 2;
    else
      return 0;
  }
  *((_BYTE *)&v21 + 4) &= 7u;
  v21.__vftable = (idCoverActions_vtbl *)&idCoverActions::`vftable';
  idAICover::GetCoverActions(this: cover, actions: &v21);
  *((_BYTE *)&v23.idCoverActions + 4) &= 7u;
  v23.__vftable = (idCoverCapabilities_vtbl *)&idCoverCapabilities::`vftable';
  *((_BYTE *)&v23 + 8) &= 1u;
  idCoverCapabilities::Promote(this: &v23, actions: &v21);
  v13 = ai->GetEquippedWeapon(this: ai);
  v24[0].__vftable = (idCoverCapabilities_vtbl *)&idCoverCapabilities::`vftable';
  *((_BYTE *)&v24[0].idCoverActions + 4) &= 7u;
  *((_BYTE *)v24 + 8) &= 1u;
  CoverPosture = idAICover::GetCoverPosture(this: cover);
  idAIBehaviors::GetWeaponCoverCapabilities(
    this,
    weapon: v13,
    coverPosture: CoverPosture,
    coverOrientation: COVERORIENT_FORWARD,
    caps: v24);
  v22.__vftable = (idCoverCapabilities_vtbl *)&idCoverCapabilities::`vftable';
  *((_BYTE *)&v22.idCoverActions + 4) &= 7u;
  *((_BYTE *)&v22 + 8) &= 1u;
  v15 = idAICover::GetCoverPosture(this: cover);
  if ( v13 != nullptr )
  {
    decl = v13->decl;
    v17 = this->decl;
    v25[0] = 0;
    v18 = *(_DWORD *)&decl[2].usable;
    v25[1] = &v17->backwardCoverCaps;
    v25[2] = &v17->backwardCoverCaps.pistolCoverCaps;
    v25[3] = &v17->backwardCoverCaps.rifleCoverCaps;
    v19 = (const idCoverCapabilities *)v25[v18];
    if ( v19 != nullptr )
    {
      if ( v15 == POSTURE_STANDING )
      {
        ++v19;
      }
      else if ( v15 != POSTURE_CROUCHED )
      {
        goto LABEL_18;
      }
      idCoverCapabilities::operator=(this: &v22, __that: v19);
    }
  }
LABEL_18:
  v20 = idCoverCapabilities::NumMatchingCapabilities(this: &v23, other: v24);
  if ( v20 > idCoverCapabilities::NumMatchingCapabilities(this: &v23, other: &v22) )
    return 2;
  else
    return 3;
}


// ========================================================================
// __unwind$487553
// EA  : 0x82A3F8E4
// RVA : 0x00A3F8E4
// PDB : w:\tech5\tungsten\game\ai\aibehaviors.cpp
// ========================================================================

void _unwind_487553()
{
  int v0; // r12

  idCoverActions::~idCoverActions(this: (idCoverActions *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$487554
// EA  : 0x82A3F90C
// RVA : 0x00A3F90C
// PDB : w:\tech5\tungsten\game\ai\aibehaviors.cpp
// ========================================================================

void _unwind_487554()
{
  int v0; // r12

  idCoverActions::~idCoverActions(this: (idCoverActions *)(v0 - 224 + 104));
}


// ========================================================================
// __unwind$487555
// EA  : 0x82A3F934
// RVA : 0x00A3F934
// PDB : w:\tech5\tungsten\game\ai\aibehaviors.cpp
// ========================================================================

void _unwind_487555()
{
  int v0; // r12

  idCoverActions::~idCoverActions(this: (idCoverActions *)(v0 - 224 + 120));
}


// ========================================================================
// __unwind$487556
// EA  : 0x82A3F95C
// RVA : 0x00A3F95C
// PDB : w:\tech5\tungsten\game\ai\aibehaviors.cpp
// ========================================================================

void _unwind_487556()
{
  int v0; // r12

  idCoverActions::~idCoverActions(this: (idCoverActions *)(v0 - 224 + 88));
}

