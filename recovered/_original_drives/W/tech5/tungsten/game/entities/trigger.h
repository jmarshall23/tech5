
// ========================================================================
// ?GetFacingTarget@idTrigger_Facing@@QBAPAVidInfo_Trigger_Facing_Target@@XZ
// EA  : 0x82CEE830
// RVA : 0x00CEE830
// PDB : w:\tech5\tungsten\game\entities\trigger.h
// ========================================================================

idInfo_Trigger_Facing_Target *__fastcall idTrigger_Facing::GetFacingTarget(idTrigger_Facing *this)
{
  int value; // r10
  idInfo_Trigger_Facing_Target *v2; // r3

  value = this->facingTarget.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idInfo_Trigger_Facing_Target::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetHealth@idTrigger_DamageType@@UBAMXZ
// EA  : 0x82CEFE28
// RVA : 0x00CEFE28
// PDB : w:\tech5\tungsten\game\entities\trigger.h
// ========================================================================

float __fastcall idTrigger_DamageType::GetHealth(idTrigger_DamageType *this)
{
  double health; // fp1

  health = this->health;
  return *((float *)&health + 1);
}


// ========================================================================
// ?SetHealth@idTrigger_DamageType@@UAAXM@Z
// EA  : 0x82CEFE30
// RVA : 0x00CEFE30
// PDB : w:\tech5\tungsten\game\entities\trigger.h
// ========================================================================

void __fastcall idTrigger_DamageType::SetHealth(idTrigger_DamageType *this, double h)
{
  this->health = h;
}

