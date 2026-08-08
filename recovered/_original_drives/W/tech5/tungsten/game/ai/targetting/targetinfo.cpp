
// ========================================================================
// ??0idTargetInfo@@QAA@XZ
// EA  : 0x82B04158
// RVA : 0x00B04158
// PDB : w:\tech5\tungsten\game\ai\targetting\targetinfo.cpp
// ========================================================================

idTargetInfo *__fastcall idTargetInfo::idTargetInfo(idTargetInfo *this)
{
  this->es = nullptr;
  this->distSqr = 0.0;
  this->distTo = 0.0;
  this->delta.x = 0.0;
  this->delta.y = 0.0;
  this->delta.z = 0.0;
  this->faceDir.x = 1.0;
  this->faceDir.y = 0.0;
  this->faceDir.z = 0.0;
  this->dirTo.x = 1.0;
  this->dirTo.y = 0.0;
  this->dirTo.z = 0.0;
  this->attitude = -1;
  this->healthRatio = -1;
  return this;
}


// ========================================================================
// ?Cache@idTargetInfo@@QAAXPBUaiLatchedState_t@@PBVidAIEntityState@@@Z
// EA  : 0x82B041B0
// RVA : 0x00B041B0
// PDB : w:\tech5\tungsten\game\ai\targetting\targetinfo.cpp
// ========================================================================

void __fastcall idTargetInfo::Cache(idTargetInfo *this, const aiLatchedState_t *ownerState, const idAIEntityState *es_)
{
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double v6; // fp7
  double v7; // fp9
  double v8; // fp6
  double v9; // fp11
  double y; // fp10
  double z; // fp9
  double v14; // fp5
  double v15; // fp4
  double v16; // fp13
  double v17; // fp11
  double v18; // fp5
  const idAIEntityState *es; // r6
  idEntity *v20; // r28
  idEntity *Entity; // r3
  idActor *v22; // r30
  int v23; // r3
  int v24; // r11
  idActor *v25; // r29
  idFaction *v26; // r3
  const idFaction *v27; // r30
  idFaction *v28; // r3

  this->es = es_;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: es_->senses.ptr[es_->lastSense]);
  v6 = (float)(ConfirmedPhysicalSafe->origin.y - ownerState->physical.origin.y);
  v7 = (float)(ConfirmedPhysicalSafe->origin.x - ownerState->physical.origin.x);
  v8 = (float)(ConfirmedPhysicalSafe->origin.z - ownerState->physical.origin.z);
  this->delta.y = ConfirmedPhysicalSafe->origin.y - ownerState->physical.origin.y;
  this->delta.z = v8;
  this->delta.x = v7;
  v9 = (float)((float)((float)v8 * (float)v8) + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)));
  this->distSqr = (float)((float)v8 * (float)v8)
                + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6));
  y = this->delta.y;
  _FP7 = (float)((float)((float)((float)v8 * (float)v8)
                       + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  z = this->delta.z;
  __asm { fsel      f6, f7, f11, f13 }
  v14 = (float)((float)v9 * (float)0.5);
  v15 = __frsqrte(_FP6);
  v16 = (float)((float)-(float)((float)((float)((float)v15 * (float)((float)v9 * (float)0.5)) * (float)v15) - (float)1.5)
              * (float)v15);
  v17 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                              * (float)((float)v9 * (float)0.5))
                                                                      * (float)v15)
                                                              - (float)1.5)
                                              * (float)v15)
                                      * (float)((float)v9 * (float)0.5))
                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)v9 * (float)0.5))
                                                              * (float)v15)
                                                      - (float)1.5)
                                      * (float)v15))
                      - (float)1.5);
  v18 = (float)-(float)((float)((float)((float)((float)v17 * (float)v16) * (float)v14) * (float)((float)v17 * (float)v16))
                      - (float)1.5);
  this->dirTo.x = this->delta.x * (float)((float)v18 * (float)((float)v17 * (float)v16));
  this->dirTo.y = (float)((float)v18 * (float)((float)v17 * (float)v16)) * (float)y;
  this->dirTo.z = (float)((float)v18 * (float)((float)v17 * (float)v16)) * (float)z;
  es = this->es;
  this->distTo = this->distSqr * (float)((float)v18 * (float)((float)v17 * (float)v16));
  this->faceDir = aiSenseState_t::GetConfirmedPhysicalSafe(this: es->senses.ptr[es->lastSense])->viewfwd;
  this->attitude = 3;
  v20 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: ownerState->spawnId.value);
  Entity = idAIEntityState::GetEntity(this: (idAIEntityState *)this->es);
  v22 = (idActor *)Entity;
  if ( Entity != nullptr )
  {
    v23 = (int)Entity->GetHealthComponent_2(this: Entity);
    if ( v23 != 0 )
    {
      v24 = (int)((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v23 + 68))(a1: v23);
      if ( v24 >= 0 )
      {
        if ( v24 > 255 )
          LOBYTE(v24) = -1;
      }
      else
      {
        LOBYTE(v24) = 0;
      }
    }
    else
    {
      LOBYTE(v24) = 0;
    }
    this->healthRatio = v24;
    v25 = idActor::CastTo(c: v22);
    if ( v25 != nullptr )
    {
      v26 = v20->GetFaction(this: v20);
      this->attitude = idFaction::GetAttitudeTowards(this: v26, otherEnt: v25);
    }
    else
    {
      v27 = v22->GetFaction(this: v22);
      if ( v27 != nullptr )
      {
        v28 = v20->GetFaction(this: v20);
        this->attitude = idFaction::GetAttitudeTowards(this: v28, otherFaction: v27);
      }
    }
  }
}

