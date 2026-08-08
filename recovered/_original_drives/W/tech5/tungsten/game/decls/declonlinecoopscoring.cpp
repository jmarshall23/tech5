
// ========================================================================
// ??0idDeclOnlineScoringCallout@@QAA@XZ
// EA  : 0x82BC9410
// RVA : 0x00BC9410
// PDB : w:\tech5\tungsten\game\decls\declonlinecoopscoring.cpp
// ========================================================================

idDeclOnlineScoringCallout *__fastcall idDeclOnlineScoringCallout::idDeclOnlineScoringCallout(
        idDeclOnlineScoringCallout *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->sound = nullptr;
  this->__vftable = (idDeclOnlineScoringCallout_vtbl *)&idDeclOnlineScoringCallout::`vftable';
  this->text.index = -1;
  this->icon = nullptr;
  this->priority = 0;
  return this;
}


// ========================================================================
// ?LoadAllDecls@idDeclOnlineCoopScoring@@SAXXZ
// EA  : 0x82BC94E0
// RVA : 0x00BC94E0
// PDB : w:\tech5\tungsten\game\decls\declonlinecoopscoring.cpp
// ========================================================================

static void __fastcall idDeclOnlineCoopScoring::LoadAllDecls()
{
  int v0; // r31
  int num; // r29
  const char *str; // r4

  if ( idDeclOnlineCoopScoring::resourceList.declSources.num > 0 )
  {
    v0 = 0;
    num = idDeclOnlineCoopScoring::resourceList.declSources.num;
    do
    {
      str = idDeclOnlineCoopScoring::resourceList.declSources.list[v0]->name.str;
      if ( str != nullptr )
        idDeclInfo::FindWithInheritance(this: &idDeclOnlineCoopScoring::resourceList, name: str, makeDefault: false);
      --num;
      ++v0;
    }
    while ( num != 0 );
  }
}


// ========================================================================
// ??0idDeclOnlineCoopScoring@@QAA@XZ
// EA  : 0x82BC9610
// RVA : 0x00BC9610
// PDB : w:\tech5\tungsten\game\decls\declonlinecoopscoring.cpp
// ========================================================================

idDeclOnlineCoopScoring *__fastcall idDeclOnlineCoopScoring::idDeclOnlineCoopScoring(idDeclOnlineCoopScoring *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->__vftable = (idDeclOnlineCoopScoring_vtbl *)&idDeclOnlineCoopScoring::`vftable';
  this->events.enemyHeadhshotKill = 50;
  this->events.enemyKill = 25;
  this->events.assistPct = 0.1;
  this->events.enemySpecialKill = 75;
  this->events.heavyKill = 75;
  this->events.heavyHeadhshotKill = 150;
  this->events.heavySpecialKill = 175;
  this->events.doubleKill = 100;
  this->events.tripleKill = 200;
  this->events.quadKill = 300;
  this->events.killingSpree = 500;
  this->events.collectiableBonus = 50;
  idDeclOnlineCoopScoring::coopScoring_Multiplier_t::coopScoring_Multiplier_t(this: &this->multiplier);
  this->multiplierPointsLevelBuffer = 100;
  this->multiplierUpCallout = nullptr;
  this->multiplierPointsPerLevel = 1000;
  this->maxMultiplierPoints = 3000;
  this->multiplierDownCallout = nullptr;
  this->headshotCallout = nullptr;
  this->defendCallout = nullptr;
  this->assistCallout = nullptr;
  this->revengeCallout = nullptr;
  this->comboCallout = nullptr;
  this->brutalCallout = nullptr;
  this->covertCallout = nullptr;
  this->doubleKillCallout = nullptr;
  this->tripleKillCallout = nullptr;
  this->quadKillCallout = nullptr;
  this->killingSpreeCallout = nullptr;
  this->collectableCallout = nullptr;
  return this;
}


// ========================================================================
// __unwind$487498
// EA  : 0x82BC9700
// RVA : 0x00BC9700
// PDB : w:\tech5\tungsten\game\decls\declonlinecoopscoring.cpp
// ========================================================================

void _unwind_487498()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 128 + 148));
}

