
// ========================================================================
// ?GetEntityType@idAIGameState@@SA?AW4aiEntity_t@@PBVidEntity@@@Z
// EA  : 0x82AFBE58
// RVA : 0x00AFBE58
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate_impl.h
// ========================================================================

int __fastcall idAIGameState::GetEntityType(idAI2 *ent)
{
  if ( (unsigned __int8)idPlayer::IsTypeOf(c: ent) != 0 )
    return 1;
  if ( idAI2::CastTo(c: ent) != nullptr )
    return 0;
  if ( (unsigned __int8)idVehicle::IsTypeOf(c: ent) != 0 )
    return 2;
  if ( (unsigned __int8)idProjectile::IsTypeOf(c: ent) != 0 )
    return 3;
  if ( (unsigned __int8)idTurret::IsTypeOf(c: ent) != 0 )
    return 5;
  return (unsigned __int8)idProp::IsTypeOf(c: ent) == 0 ? 6 : 4;
}

