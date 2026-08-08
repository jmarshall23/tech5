
// ========================================================================
// ?GetHealth@idDamageableEntity@@UBAMXZ
// EA  : 0x82C1C538
// RVA : 0x00C1C538
// PDB : w:\tech5\tungsten\game\entities\damageableentity.h
// ========================================================================

float __fastcall idDamageableEntity::GetHealth(idDamageableEntity *this)
{
  double health; // fp1

  health = this->health;
  return *((float *)&health + 1);
}


// ========================================================================
// ?SetHealth@idDamageableEntity@@UAAXM@Z
// EA  : 0x82C1C540
// RVA : 0x00C1C540
// PDB : w:\tech5\tungsten\game\entities\damageableentity.h
// ========================================================================

void __fastcall idDamageableEntity::SetHealth(idDamageableEntity *this, double h)
{
  _FP13 = (float)((float)h - this->healthMax);
  __asm { fsel      f12, f13, f0, f1 }
  this->health = _FP12;
}


// ========================================================================
// ?GetMaxBaseHealth@idDamageableEntity@@UBAMXZ
// EA  : 0x82C1C558
// RVA : 0x00C1C558
// PDB : w:\tech5\tungsten\game\entities\damageableentity.h
// ========================================================================

float __fastcall idDamageableEntity::GetMaxBaseHealth(idDamageableEntity *this)
{
  double healthMax; // fp1

  healthMax = this->healthMax;
  return *((float *)&healthMax + 1);
}


// ========================================================================
// ?SetMaxHealth@idDamageableEntity@@UAAXM@Z
// EA  : 0x82C1C560
// RVA : 0x00C1C560
// PDB : w:\tech5\tungsten\game\entities\damageableentity.h
// ========================================================================

void __fastcall idDamageableEntity::SetMaxHealth(idDamageableEntity *this, double mh)
{
  this->healthMax = mh;
}


// ========================================================================
// ?IsDead@idDamageableEntity@@UBA_NXZ
// EA  : 0x82C1C568
// RVA : 0x00C1C568
// PDB : w:\tech5\tungsten\game\entities\damageableentity.h
// ========================================================================

BOOL __fastcall idDamageableEntity::IsDead(idDamageableEntity *this)
{
  return ((double (__fastcall *)(idDamageableEntity *))this->GetHealth)(a1: this) <= 0.0;
}

