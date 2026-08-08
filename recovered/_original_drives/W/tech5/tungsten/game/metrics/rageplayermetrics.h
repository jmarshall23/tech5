
// ========================================================================
// ??YweaponStats_t@@QAAXABU0@@Z
// EA  : 0x82DE10A8
// RVA : 0x00DE10A8
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.h
// ========================================================================

void __fastcall weaponStats_t::operator+=(weaponStats_t *this, const weaponStats_t *stats)
{
  double damageEnemy; // fp0
  int accHits; // r10
  double damageFriendly; // fp13
  int hitEnemy; // r7
  int killedEnemy; // r8
  int headshotEnemy; // r9
  int headshotEnemyKills; // r10
  int hitFriendly; // r28
  int killedFriendly; // r29
  int headshotFriendly; // r30
  int headshotFriendlyKills; // r31
  int actorsKilled; // r3
  int v16; // r10
  int vehiclesKilled; // r4
  int breakablesDestroyed; // r5
  int directHit; // r6
  int hitObject; // r7
  int damageGeneral; // r8
  int hitVehicle; // r9
  int hitVehicleInAir; // r10

  damageEnemy = this->damageEnemy;
  accHits = this->accHits;
  damageFriendly = this->damageFriendly;
  hitEnemy = this->hitEnemy;
  killedEnemy = this->killedEnemy;
  this->fired += stats->fired;
  this->accHits = stats->accHits + accHits;
  this->hitEnemy = stats->hitEnemy + hitEnemy;
  this->killedEnemy = stats->killedEnemy + killedEnemy;
  headshotEnemy = this->headshotEnemy;
  this->damageEnemy = stats->damageEnemy + (float)damageEnemy;
  headshotEnemyKills = this->headshotEnemyKills;
  this->headshotEnemy = stats->headshotEnemy + headshotEnemy;
  hitFriendly = this->hitFriendly;
  this->headshotEnemyKills = stats->headshotEnemyKills + headshotEnemyKills;
  killedFriendly = this->killedFriendly;
  this->hitFriendly = stats->hitFriendly + hitFriendly;
  this->killedFriendly = stats->killedFriendly + killedFriendly;
  headshotFriendly = this->headshotFriendly;
  this->damageFriendly = stats->damageFriendly + (float)damageFriendly;
  this->headshotFriendly = stats->headshotFriendly + headshotFriendly;
  headshotFriendlyKills = this->headshotFriendlyKills;
  actorsKilled = this->actorsKilled;
  this->headshotFriendlyKills = stats->headshotFriendlyKills + headshotFriendlyKills;
  v16 = stats->actorsKilled + actorsKilled;
  vehiclesKilled = this->vehiclesKilled;
  this->actorsKilled = v16;
  breakablesDestroyed = this->breakablesDestroyed;
  this->vehiclesKilled = stats->vehiclesKilled + vehiclesKilled;
  directHit = this->directHit;
  this->breakablesDestroyed = stats->breakablesDestroyed + breakablesDestroyed;
  hitObject = this->hitObject;
  this->directHit = stats->directHit + directHit;
  damageGeneral = this->damageGeneral;
  this->hitObject = stats->hitObject + hitObject;
  hitVehicle = this->hitVehicle;
  this->damageGeneral = stats->damageGeneral + damageGeneral;
  hitVehicleInAir = this->hitVehicleInAir;
  this->hitVehicle = stats->hitVehicle + hitVehicle;
  this->hitVehicleInAir = stats->hitVehicleInAir + hitVehicleInAir;
}


// ========================================================================
// ??0idLevelStats@@QAA@XZ
// EA  : 0x82DE5678
// RVA : 0x00DE5678
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.h
// ========================================================================

idLevelStats *__fastcall idLevelStats::idLevelStats(idLevelStats *this)
{
  idStaticList<weaponStats_t,20>::idStaticList<weaponStats_t,20>(this: &this->weaponStats);
  idLevelStats::Clear(this);
  return this;
}


// ========================================================================
// __unwind$494785
// EA  : 0x82DE56C4
// RVA : 0x00DE56C4
// PDB : w:\tech5\tungsten\game\metrics\rageplayermetrics.h
// ========================================================================

void _unwind_494785()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}

