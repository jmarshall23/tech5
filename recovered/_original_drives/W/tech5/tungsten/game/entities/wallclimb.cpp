
// ========================================================================
// ?GetUsableState@idUseWallClimb@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82D4C518
// RVA : 0x00D4C518
// PDB : w:\tech5\tungsten\game\entities\wallclimb.cpp
// ========================================================================

int __fastcall idUseWallClimb::GetUsableState(idUseWallClimb *this, idPlayer *activator, const idFocusTrace *ft)
{
  idPlayer *v6; // r3

  v6 = idPlayer::CastTo(c: activator);
  if ( v6 == nullptr || idPlayer::PlayerBehavior_WallClimb_IsInWallClimb(this: v6) )
    return 0;
  else
    return idUse::GetUsableState(this, activator, ft);
}


// ========================================================================
// ?Spawn@idWallClimb@@QAAXXZ
// EA  : 0x82D4C578
// RVA : 0x00D4C578
// PDB : w:\tech5\tungsten\game\entities\wallclimb.cpp
// ========================================================================

void __fastcall idWallClimb::Spawn(idWallClimb *this, long double a2)
{
  long double v3; // fp2

  *(double *)&a2 = (float)(this->maxMoveAngle * idMath::M_DEG2RAD);
  v3 = tan(x: a2);
  this->tanMaxMoveAngle = *(double *)&v3;
}


// ========================================================================
// ??0idWallClimb@@QAA@XZ
// EA  : 0x82D4C5C8
// RVA : 0x00D4C5C8
// PDB : w:\tech5\tungsten\game\entities\wallclimb.cpp
// ========================================================================

idWallClimb *__fastcall idWallClimb::idWallClimb(idWallClimb *this)
{
  float z; // r4

  idEntity::idEntity(this);
  this->__vftable = (idWallClimb_vtbl *)&idWallClimb::`vftable';
  this->anchorPoint.spawnId.value = 0x1FFF;
  this->climbOffTarget.spawnId.value = 0x1FFF;
  this->maxMoveAngle = 10.0;
  this->sidewaysSpeed = 50.0;
  this->maxDeltaYaw = -1.0;
  this->maxDeltaPitch = -1.0;
  this->climbOffTriggers.list = nullptr;
  this->climbOffTriggers.granularity = 0;
  this->climbOffTriggers.memTag = 5;
  this->climbOffTriggers.listStatic = 0;
  this->climbOffTriggers.size = 0;
  this->climbOffTriggers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->climbOffTriggers);
  this->direction.x = vec3_up.x;
  this->direction.y = vec3_up.y;
  z = vec3_up.z;
  this->tanMaxMoveAngle = 0.0;
  this->direction.z = z;
  return this;
}


// ========================================================================
// __unwind$487882
// EA  : 0x82D4C6AC
// RVA : 0x00D4C6AC
// PDB : w:\tech5\tungsten\game\entities\wallclimb.cpp
// ========================================================================

void _unwind_487882()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetClosestPoint@idWallClimb@@QBA?AW4wallClimbEndPointType_t@1@PBVidPlayer@@MAAVidVec3@@@Z
// EA  : 0x82D4C7B0
// RVA : 0x00D4C7B0
// PDB : w:\tech5\tungsten\game\entities\wallclimb.cpp
// ========================================================================

idWallClimb::wallClimbEndPointType_t __fastcall idWallClimb::GetClosestPoint(
        idWallClimb *this,
        const idPlayer *player,
        double climbOffDistance,
        idVec3 *point,
        float *a5)
{
  idPhysics *Physics; // r3
  float *v9; // r3
  int value; // r9
  idEntity *v11; // r3
  idEntity *v12; // r3
  idPhysics *v13; // r3
  float *v14; // r3
  idPhysics *v15; // r3
  float *v16; // r3
  double v17; // fp29
  double v18; // fp28
  double v19; // fp27
  idPhysics *v20; // r3
  float *v21; // r3
  double v22; // fp31
  idPhysics *v23; // r3
  float *v24; // r3
  double v25; // fp4
  double v26; // fp3
  double v27; // fp0
  double v28; // fp12
  idWallClimb::wallClimbEndPointType_t result; // r3
  float v30; // [sp+50h] [-60h]
  float v31; // [sp+54h] [-5Ch]
  float v32; // [sp+58h] [-58h]
  float v33; // [sp+60h] [-50h]
  float v34; // [sp+64h] [-4Ch]
  float v35; // [sp+68h] [-48h]

  Physics = idEntity::GetPhysics(this: &player->idActor);
  v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  value = this->anchorPoint.spawnId.value;
  v33 = *v9;
  v34 = v9[1];
  v35 = v9[2];
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v11 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v12 = idEntity::CastTo(c: v11);
  }
  else
  {
    v12 = nullptr;
  }
  v13 = idEntity::GetPhysics(this: v12);
  v14 = (float *)v13->GetOrigin(this: v13, a2: 0);
  v30 = *v14;
  v31 = v14[1];
  v32 = v14[2];
  v15 = idEntity::GetPhysics(this);
  v16 = (float *)v15->GetOrigin(this: v15, a2: 0);
  v17 = (float)(v30 - *v16);
  v18 = (float)(v31 - v16[1]);
  v19 = (float)(v32 - v16[2]);
  v20 = idEntity::GetPhysics(this);
  v21 = (float *)v20->GetOrigin(this: v20, a2: 0);
  v22 = (float)((float)(this->direction.x * (float)(v33 - *v21))
              + (float)((float)(this->direction.y * (float)(v34 - v21[1]))
                      + (float)(this->direction.z * (float)(v35 - v21[2]))));
  v23 = idEntity::GetPhysics(this);
  v24 = (float *)v23->GetOrigin(this: v23, a2: 0);
  v25 = (float)(this->direction.y * (float)v22);
  v26 = (float)(this->direction.z * (float)v22);
  v27 = v24[1];
  v28 = v24[2];
  *a5 = (float)(this->direction.x * (float)v22) + *v24;
  a5[1] = (float)v27 + (float)v25;
  a5[2] = (float)v28 + (float)v26;
  if ( v22 > (float)((float)__fsqrts((float)((float)((float)v17 * (float)v17)
                                           + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))))
                   - (float)climbOffDistance) )
    return WALLCLIMB_ENDPOINT_UP;
  result = WALLCLIMB_ENDPOINT_DOWN;
  if ( v22 > 0.0 )
    return WALLCLIMB_ENDPOINT_NONE;
  return result;
}


// ========================================================================
// ?GetMaxSidewaysDistance@idWallClimb@@QBAMABVidVec3@@@Z
// EA  : 0x82D4C9E0
// RVA : 0x00D4C9E0
// PDB : w:\tech5\tungsten\game\entities\wallclimb.cpp
// ========================================================================

float __fastcall idWallClimb::GetMaxSidewaysDistance(idWallClimb *this, const idVec3 *point)
{
  int value; // r10
  idEntity *v5; // r3
  idEntity *v6; // r3
  idPhysics *Physics; // r3
  float *v8; // r3
  double v9; // fp1

  value = this->anchorPoint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v6);
  v8 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v9 = (float)((float)((float)(this->direction.x * (float)(*v8 - point->x))
                     + (float)((float)(this->direction.z * (float)(v8[2] - point->z))
                             + (float)(this->direction.y * (float)(v8[1] - point->y))))
             * this->tanMaxMoveAngle);
  return *((float *)&v9 + 1);
}


// ========================================================================
// ?GetClimbOffPosition@idWallClimb@@QBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82D4CAB8
// RVA : 0x00D4CAB8
// PDB : w:\tech5\tungsten\game\entities\wallclimb.cpp
// ========================================================================

void __fastcall idWallClimb::GetClimbOffPosition(idWallClimb *this, idVec3 *point, idMat3 *axis)
{
  int value; // r10
  idEntity *v7; // r3
  idEntity *v8; // r3
  idPhysics *Physics; // r3
  float *v10; // r3
  idGameLocal *v11; // r10
  int v12; // r9
  idEntity *v13; // r3
  idEntity *v14; // r3
  idPhysics *v15; // r3
  float *v16; // r3
  double y; // fp4
  double v18; // fp2
  double v19; // fp12
  double v20; // fp10

  value = this->anchorPoint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v8);
  v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v11 = gameLocal;
  point->x = *v10;
  point->y = v10[1];
  point->z = v10[2];
  v12 = this->anchorPoint.spawnId.value;
  if ( v11->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13 && (v13 = v11->entities.ptr[v12 & 0x1FFF]) != nullptr )
    v14 = idEntity::CastTo(c: v13);
  else
    v14 = nullptr;
  v15 = idEntity::GetPhysics(this: v14);
  v16 = (float *)v15->GetAxis(this: v15, a2: 0);
  axis->mat[0].x = *v16;
  axis->mat[0].y = v16[1];
  axis->mat[0].z = v16[2];
  axis->mat[1].x = v16[3];
  axis->mat[1].y = v16[4];
  axis->mat[1].z = v16[5];
  axis->mat[2].x = v16[6];
  axis->mat[2].y = v16[7];
  axis->mat[2].z = v16[8];
  y = axis->mat[0].y;
  v18 = -axis->mat[0].z;
  axis->mat[0].x = -axis->mat[0].x;
  axis->mat[0].y = -y;
  axis->mat[0].z = v18;
  v19 = axis->mat[1].y;
  v20 = -axis->mat[1].z;
  axis->mat[1].x = -axis->mat[1].x;
  axis->mat[1].y = -v19;
  axis->mat[1].z = v20;
}


// ========================================================================
// ?Use@idUseWallClimb@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82D4CC40
// RVA : 0x00D4CC40
// PDB : w:\tech5\tungsten\game\entities\wallclimb.cpp
// ========================================================================

int __fastcall idUseWallClimb::Use(idUseWallClimb *this, idPlayer *activator, usableState_t usable)
{
  idPlayer *v6; // r3
  idPlayer *v7; // r29
  idWallClimb *Target; // r3
  idWallClimb *v9; // r30
  idVec3 *v10; // r5
  idVec3 v12[5]; // [sp+50h] [-40h] BYREF

  v6 = idPlayer::CastTo(c: activator);
  v7 = v6;
  if ( (*(_BYTE *)&this->flags & 8) == 0 )
    return 0;
  if ( v6 == nullptr )
    return 0;
  if ( this->targets.num < 1 )
    return 0;
  Target = (idWallClimb *)idEntity::GetTarget(this, i: 0);
  v9 = idWallClimb::CastTo(c: Target);
  if ( v9 == nullptr )
    return 0;
  idEntity::Use(this, activator, usable);
  idWallClimb::GetClosestPoint(this: v9, player: v7, climbOffDistance: 0.0, point: v10, a5: &v12[0].x);
  idPlayer::PlayerBehavior_WallClimb_MountWall(this: v7, wallClimb: v9, closestPoint: v12);
  return 1;
}

