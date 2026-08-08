
// ========================================================================
// ??0idAIEventProjectile@@QAA@XZ
// EA  : 0x82A45230
// RVA : 0x00A45230
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventprojectile.cpp
// ========================================================================

idAIEventProjectile *__fastcall idAIEventProjectile::idAIEventProjectile(idAIEventProjectile *this)
{
  idAIEventTrace::idAIEventTrace(this);
  this->__vftable = (idAIEventProjectile_vtbl *)&idAIEventProjectile::`vftable';
  return this;
}


// ========================================================================
// ?InternalUpdateAttached@idAIEventProjectile@@MAA?AW4aiEventUpdateResult_t@idAIEvent@@H@Z
// EA  : 0x82A45270
// RVA : 0x00A45270
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventprojectile.cpp
// ========================================================================

idAIEvent::aiEventUpdateResult_t __fastcall idAIEventProjectile::InternalUpdateAttached(
        idAIEventProjectile *this,
        const int curTime)
{
  int value; // r10
  idEntity *v4; // r3
  idEntity *v5; // r3
  idPhysics *Physics; // r3
  float *v7; // r3
  idGameLocal *v8; // r10
  int v9; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3
  idPhysics *v12; // r3
  double v13; // fp11
  double v14; // fp10
  double v18; // fp2
  double v19; // fp5
  double v20; // fp2
  float v21; // [sp+50h] [-30h] BYREF
  float v22; // [sp+54h] [-2Ch]
  float v23; // [sp+58h] [-28h]

  value = this->originator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v4 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v5 = idEntity::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v5);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v8 = gameLocal;
  this->origin.x = *v7;
  this->origin.y = v7[1];
  this->origin.z = v7[2];
  v9 = this->originator.spawnId.value;
  if ( v8->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 && (v10 = v8->entities.ptr[v9 & 0x1FFF]) != nullptr )
    v11 = idEntity::CastTo(c: v10);
  else
    v11 = nullptr;
  v12 = idEntity::GetPhysics(this: v11);
  v12->GetLinearVelocity(this: (idPhysics *)&v21, result: (idVec3 *)v12, a3: 0);
  v13 = v22;
  v14 = v23;
  _FP5 = (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f12 }
  v18 = __frsqrte(_FP3);
  v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                      * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                                              * (float)0.5))
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18)
                                              * (float)((float)((float)(v23 * v23)
                                                              + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v18
                                                                              * (float)((float)((float)(v23 * v23)
                                                                                              + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                                      * (float)0.5))
                                                                      * (float)v18)
                                                              - (float)1.5)
                                              * (float)v18))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v18
                                                      * (float)((float)((float)(v23 * v23)
                                                                      + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                              * (float)0.5))
                                              * (float)v18)
                                      - (float)1.5)
                      * (float)v18));
  v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                              * (float)v18)
                                                                                      * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                      * (float)v18))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v18
                                                                                              * (float)((float)((float)(v23 * v23) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5))
                                                                                      * (float)v18)
                                                                              - (float)1.5)
                                                              * (float)v18))
                                              * (float)((float)((float)(v23 * v23)
                                                              + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                      * (float)0.5))
                                      * (float)v19)
                              - (float)1.5)
              * (float)v19);
  this->dir.x = v21 * (float)v20;
  this->dir.y = (float)v13 * (float)v20;
  this->dir.z = (float)v20 * (float)v14;
  return AIUPDATE_OK;
}


// ========================================================================
// ?GetDistance@idAIEventProjectile@@UBAMXZ
// EA  : 0x82A45408
// RVA : 0x00A45408
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventprojectile.cpp
// ========================================================================

float __fastcall idAIEventProjectile::GetDistance(idAIEventProjectile *this)
{
  int value; // r10
  idEntity *v3; // r3
  idEntity *v4; // r3
  idPhysics *Physics; // r3
  float *v6; // r3
  const idDeclAiEvent *eventDecl; // r11
  double v8; // fp1
  double v9; // fp13
  double lookAheadTime; // fp0
  double v11; // fp0
  char v13; // [sp+50h] [-20h] BYREF

  value = this->originator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v4 = idEntity::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v4);
  v6 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v13, result: (idVec3 *)Physics, a3: 0);
  eventDecl = this->eventDecl;
  v8 = 0.0;
  v9 = __fsqrts((float)((float)(v6[2] * v6[2]) + (float)((float)(*v6 * *v6) + (float)(v6[1] * v6[1]))));
  if ( eventDecl != nullptr )
    lookAheadTime = eventDecl->lookAheadTime;
  else
    lookAheadTime = 0.0;
  v11 = (float)((float)lookAheadTime * (float)v9);
  if ( v11 >= 0.0 )
  {
    v8 = 4096.0;
    if ( v11 <= 4096.0 )
      v8 = v11;
  }
  return *((float *)&v8 + 1);
}

