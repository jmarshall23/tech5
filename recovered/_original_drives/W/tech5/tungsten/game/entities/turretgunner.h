
// ========================================================================
// ?GetFaction@idTurretGunner@@UBAPBVidFaction@@XZ
// EA  : 0x82D00AC8
// RVA : 0x00D00AC8
// PDB : w:\tech5\tungsten\game\entities\turretgunner.h
// ========================================================================

idFaction *__fastcall idTurretGunner::GetFaction(idTurretGunner *this)
{
  return &this->faction;
}


// ========================================================================
// ?IsDead@idTurretGunner@@UBA_NXZ
// EA  : 0x82D00AD0
// RVA : 0x00D00AD0
// PDB : w:\tech5\tungsten\game\entities\turretgunner.h
// ========================================================================

BOOL __fastcall idTurretGunner::IsDead(idTurretGunner *this)
{
  return this->health <= 0.0;
}


// ========================================================================
// ?GetHealth@idTurretGunner@@UBAMXZ
// EA  : 0x82D00AF8
// RVA : 0x00D00AF8
// PDB : w:\tech5\tungsten\game\entities\turretgunner.h
// ========================================================================

float __fastcall idTurretGunner::GetHealth(idTurretGunner *this)
{
  double health; // fp1

  health = this->health;
  return *((float *)&health + 1);
}


// ========================================================================
// ?SetHealth@idTurretGunner@@UAAXM@Z
// EA  : 0x82D00B00
// RVA : 0x00D00B00
// PDB : w:\tech5\tungsten\game\entities\turretgunner.h
// ========================================================================

void __fastcall idTurretGunner::SetHealth(idTurretGunner *this, double h)
{
  _FP13 = (float)((float)h - this->maxHealth);
  __asm { fsel      f12, f13, f0, f1 }
  this->health = _FP12;
}


// ========================================================================
// ?GetMaxBaseHealth@idTurretGunner@@UBAMXZ
// EA  : 0x82D00B18
// RVA : 0x00D00B18
// PDB : w:\tech5\tungsten\game\entities\turretgunner.h
// ========================================================================

float __fastcall idTurretGunner::GetMaxBaseHealth(idTurretGunner *this)
{
  double maxHealth; // fp1

  maxHealth = this->maxHealth;
  return *((float *)&maxHealth + 1);
}


// ========================================================================
// ?SetMaxHealth@idTurretGunner@@UAAXM@Z
// EA  : 0x82D00B20
// RVA : 0x00D00B20
// PDB : w:\tech5\tungsten\game\entities\turretgunner.h
// ========================================================================

void __fastcall idTurretGunner::SetMaxHealth(idTurretGunner *this, double mh)
{
  this->maxHealth = mh;
}

