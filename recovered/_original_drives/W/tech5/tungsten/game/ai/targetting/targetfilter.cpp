
// ========================================================================
// ?Filter@idTargetFilter@@QBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA  : 0x82B03F58
// RVA : 0x00B03F58
// PDB : w:\tech5\tungsten\game\ai\targetting\targetfilter.cpp
// ========================================================================

int __fastcall idTargetFilter::Filter(idTargetFilter *this, idTurret *owner, const idTargetInfo *ti)
{
  idAIEntityState *es; // r3
  idPlayer *Entity; // r3
  idPlayer *v8; // r29
  idPlayer *v9; // r3
  idPlayer *v10; // r3
  idTurret *v12; // r3
  idVehicleMountedTurret *v13; // r3
  idTarget_FakeEnemy *v14; // r3
  idLobbyBase *v15; // r3
  idTurret *v16; // r3
  idTurret *v17; // r30
  idVehicle *v18; // r3
  idVehicle *v19; // r31
  idVehicle *v20; // r3
  idEntity *turretOwner; // r31

  es = (idAIEntityState *)ti->es;
  if ( ti->es == nullptr )
    return 0;
  if ( es->curAwareness < this->minAwareness )
    return 0;
  Entity = (idPlayer *)idAIEntityState::GetEntity(this: es);
  v8 = Entity;
  if ( Entity == nullptr
    || idPlayer::CastTo(c: Entity) != nullptr && (*((_BYTE *)idPlayer::CastTo(c: v8) + 12824) & 8) != 0 )
  {
    return 0;
  }
  v9 = (idPlayer *)idActor::CastTo(c: v8);
  if ( v9 != nullptr )
  {
    v10 = idPlayer::CastTo(c: v9);
    if ( v10 != nullptr && (*((_BYTE *)v10 + 12824) & 8) != 0 )
      return 0;
  }
  else
  {
    v12 = idTurret::CastTo(c: (idTurret *)v8);
    if ( v12 != nullptr )
    {
      if ( v12->IsDead(this: v12) )
        return 0;
    }
    else
    {
      v13 = idVehicleMountedTurret::CastTo(c: (idVehicleMountedTurret *)v8);
      if ( v13 != nullptr )
      {
        if ( v13->IsDead(this: v13) )
          return 0;
        v14 = idTarget_FakeEnemy::CastTo(c: (idTarget_FakeEnemy *)v8);
        if ( v14 != nullptr && (*(_BYTE *)&v14->flags & 8) == 0 )
          return 0;
      }
    }
  }
  if ( common->IsMultiplayer(this: common) )
  {
    v15 = session->GetGameLobbyBase(this: session);
    if ( v15->GetMatchParms(this: v15)->gameType == 2 )
    {
      v16 = idTurret::CastTo(c: owner);
      v17 = v16;
      if ( v16 != nullptr && v16->turretOwner != nullptr )
      {
        v18 = idVehicle::CastTo(c: (idVehicle *)v8);
        v19 = v18;
        if ( v18 != nullptr && idVehicle::GetDriver(this: v18) != nullptr )
        {
          v20 = v19;
          turretOwner = v17->turretOwner;
          if ( idVehicle::GetDriver(this: v20) == turretOwner )
            return 0;
        }
        if ( v8 == v17->turretOwner )
          return 0;
      }
    }
  }
  return ((int (__fastcall *)(idTargetFilter *, idTurret *, const idTargetInfo *))this->InternalFilter)(
           a1: this,
           a2: owner,
           a3: ti);
}

