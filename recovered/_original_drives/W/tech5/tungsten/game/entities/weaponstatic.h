
// ========================================================================
// ?GetUser@idProp_WeaponStatic@@QBAPAVidEntity@@XZ
// EA  : 0x82AC9B80
// RVA : 0x00AC9B80
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.h
// ========================================================================

idActor *__fastcall idProp_WeaponStatic::GetUser(idProp_WeaponStatic *this)
{
  int value; // r10
  idActor *v2; // r3

  value = this->user.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idActor *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idActor::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?IsDead@idProp_WeaponStatic@@UBA_NXZ
// EA  : 0x82D51688
// RVA : 0x00D51688
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.h
// ========================================================================

BOOL __fastcall idProp_WeaponStatic::IsDead(idProp_WeaponStatic *this)
{
  return (_cntlzw(this->enabled) & 0x20) != 0;
}


// ========================================================================
// ?GetHealth@idProp_WeaponStatic@@UBAMXZ
// EA  : 0x82D51698
// RVA : 0x00D51698
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.h
// ========================================================================

float __fastcall idProp_WeaponStatic::GetHealth(idProp_WeaponStatic *this)
{
  double currentHealth; // fp1

  currentHealth = this->currentHealth;
  return *((float *)&currentHealth + 1);
}


// ========================================================================
// ?SetHealth@idProp_WeaponStatic@@UAAXM@Z
// EA  : 0x82D516A0
// RVA : 0x00D516A0
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.h
// ========================================================================

void __fastcall idProp_WeaponStatic::SetHealth(idProp_WeaponStatic *this, double h)
{
  double v4; // fp1

  this->GetMaxHealth(this);
  if ( h >= 0.0 )
  {
    if ( h <= v4 )
      this->currentHealth = h;
    else
      this->currentHealth = v4;
  }
  else
  {
    this->currentHealth = 0.0;
  }
}


// ========================================================================
// ?GetMaxHealth@idProp_WeaponStatic@@UBAMXZ
// EA  : 0x82D51710
// RVA : 0x00D51710
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.h
// ========================================================================

float __fastcall idProp_WeaponStatic::GetMaxHealth(idProp_WeaponStatic *this)
{
  double health; // fp1

  health = this->health;
  return *((float *)&health + 1);
}


// ========================================================================
// ?SetMaxHealth@idProp_WeaponStatic@@UAAXM@Z
// EA  : 0x82D51718
// RVA : 0x00D51718
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.h
// ========================================================================

void __fastcall idProp_WeaponStatic::SetMaxHealth(idProp_WeaponStatic *this, double mh)
{
  this->health = mh;
  _FP13 = (float)(this->currentHealth - this->GetMaxHealth(this));
  __asm { fsel      f12, f13, f1, f0 }
  this->currentHealth = _FP12;
}

