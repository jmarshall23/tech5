
// ========================================================================
// ?GetExitAnimation@idScenePoint_Combat@@QBAABVidAnimWebPath@@W4scenePointArcSector_t@@@Z
// EA  : 0x82CB4478
// RVA : 0x00CB4478
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

idScenePoint_Combat::scenePointExitAnim_t *__fastcall idScenePoint_Combat::GetExitAnimation(
        idScenePoint_Combat *this,
        scenePointArcSector_t arcSector)
{
  switch ( arcSector )
  {
    case ARC_SECTOR_NEAR:
      return (idScenePoint_Combat::scenePointExitAnim_t *)&this->exitAnimSet.exitAnim_SectorNear;
    case ARC_SECTOR_LEFT:
      return (idScenePoint_Combat::scenePointExitAnim_t *)&this->exitAnimSet.exitAnim_SectorLeft;
    case ARC_SECTOR_RIGHT:
      return (idScenePoint_Combat::scenePointExitAnim_t *)&this->exitAnimSet.exitAnim_SectorRight;
    case ARC_SECTOR_FAR:
      return (idScenePoint_Combat::scenePointExitAnim_t *)&this->exitAnimSet.exitAnim_SectorFar;
    default:
      break;
  }
  return &this->exitAnimSet;
}


// ========================================================================
// ?RequestScenePoint@idScenePoint@@QAA_NPBVidAI2@@H@Z
// EA  : 0x82CB44C0
// RVA : 0x00CB44C0
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

int __fastcall idScenePoint::RequestScenePoint(idScenePoint *this, const idAI2 *user, int curTime)
{
  const idAI2 *currentUser; // r11
  scenePointType_t type; // r8

  if ( (*(_BYTE *)&this->flags & 8) == 0 || user == nullptr )
    return 0;
  currentUser = this->currentUser;
  if ( currentUser == nullptr )
  {
    if ( this->requestTime < curTime )
      goto LABEL_8;
    return 0;
  }
  if ( currentUser != user && this->requestTime >= curTime )
    return 0;
LABEL_8:
  this->currentUser = user;
  type = this->type;
  this->requestTime = curTime - (int)(float)((float)1000.0 * (float)-0.5);
  if ( type != LOOK )
    idAIMemory::SetTakeScenePointTimeStamp(this: &user->aiVolatile.memory, curTime);
  return 1;
}


// ========================================================================
// ?ReleaseScenePoint@idScenePoint@@QAAXPBVidAI2@@@Z
// EA  : 0x82CB4590
// RVA : 0x00CB4590
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void __fastcall idScenePoint::ReleaseScenePoint(idScenePoint *this, const idAI2 *user)
{
  const idAI2 *currentUser; // r11

  if ( user != nullptr )
  {
    currentUser = this->currentUser;
    if ( currentUser == user )
    {
      idAIMemory::ClearScenePointTimeStamps(this: &currentUser->aiVolatile.memory);
      this->currentUser = nullptr;
      this->requestTime = -1;
    }
  }
}


// ========================================================================
// ?IsInArc@idScenePoint@@UBA_NABVidAIPos@@@Z
// EA  : 0x82CB45E8
// RVA : 0x00CB45E8
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

BOOL __fastcall idScenePoint::IsInArc(idScenePoint *this, const idAIPos *point)
{
  return point->bValid && ((bool (__fastcall *)(idScenePoint *))this->IsInArc_2)(a1: this);
}


// ========================================================================
// ?GetArcSector@idScenePoint_Arc@@QBA?AW4scenePointArcSector_t@@ABVidVec3@@@Z
// EA  : 0x82CB4610
// RVA : 0x00CB4610
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

scenePointArcSector_t __fastcall idScenePoint_Arc::GetArcSector(idScenePoint_Arc *this, const idVec3 *point)
{
  idPhysics *Physics; // r3
  float *v5; // r3
  float v6; // r3
  float v7; // r11
  double v9; // fp9
  double v10; // fp30
  double v12; // fp6
  long double v13; // fp4
  double v14; // fp10
  double v15; // fp9
  long double v16; // fp2
  scenePointArcSector_t result; // r3
  long double v18; // fp2
  double v19; // fp29
  long double v20; // fp4
  long double v21; // fp2
  double v22; // fp0
  float v23; // [sp+54h] [-3Ch]

  Physics = idEntity::GetPhysics(this);
  v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v23 = point->y - v5[1];
  v7 = point->x - *v5;
  v6 = point->z - v5[2];
  _FP10 = (float)((float)((float)(v7 * v7) + (float)((float)(v6 * v6) + (float)(v23 * v23)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  v9 = (float)((float)((float)(v7 * v7) + (float)((float)(v6 * v6) + (float)(v23 * v23))) * (float)0.5);
  v10 = __fsqrts((float)((float)(v7 * v7) + (float)((float)(v6 * v6) + (float)(v23 * v23))));
  __asm { fsel      f7, f10, f11, f12 }
  v12 = __frsqrte(_FP7);
  v14 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12 * (float)v9)
                                                                              * (float)v12)
                                                                      - (float)1.5)
                                                      * (float)v12)
                                              * (float)v9)
                                      * (float)((float)-(float)((float)((float)((float)v12 * (float)v9) * (float)v12)
                                                              - (float)1.5)
                                              * (float)v12))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v12 * (float)v9) * (float)v12) - (float)1.5) * (float)v12));
  v15 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12 * (float)v9)
                                                                                      * (float)v12)
                                                                              - (float)1.5)
                                                              * (float)v12)
                                                      * (float)v9)
                                              * (float)((float)-(float)((float)((float)((float)v12 * (float)v9)
                                                                              * (float)v12)
                                                                      - (float)1.5)
                                                      * (float)v12))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v12 * (float)v9) * (float)v12) - (float)1.5)
                              * (float)v12))
              * (float)v9);
  if ( v10 < this->minRange )
    return ARC_SECTOR_NEAR;
  *(double *)&v16 = (float)((float)((float)-(float)((float)((float)v15 * (float)v14) - (float)1.5) * (float)v14) * v23);
  *((double *)&v16 + 1) = (float)(v7
                                * (float)((float)-(float)((float)((float)v15 * (float)v14) - (float)1.5) * (float)v14));
  *(double *)&v13 = (float)-(float)((float)((float)((float)v12
                                                  * (float)((float)((float)(v7 * v7)
                                                                  + (float)((float)(v6 * v6) + (float)(v23 * v23)))
                                                          * (float)0.5))
                                          * (float)v12)
                                  - (float)1.5);
  *((double *)&v13 + 1) = (float)((float)v12
                                * (float)((float)((float)(v7 * v7) + (float)((float)(v6 * v6) + (float)(v23 * v23)))
                                        * (float)0.5));
  v18 = atan2(v: v16, u: v13);
  v19 = (float)*(double *)&v18;
  *((double *)&v18 + 1) = this->arcDir.x;
  *(double *)&v18 = this->arcDir.y;
  v21 = atan2(v: v18, u: v20);
  v22 = (float)((float)((float)v19 - (float)*(double *)&v21) * idMath::M_RAD2DEG);
  if ( (float)(this->arcAngle * (float)0.5) >= __fabs(v22) )
  {
    result = ARC_SECTOR_FAR;
    if ( v10 <= this->maxRange )
      return ARC_SECTOR_INSIDE;
  }
  else if ( v22 <= 0.0 )
  {
    return ARC_SECTOR_RIGHT;
  }
  else
  {
    return ARC_SECTOR_LEFT;
  }
  return result;
}


// ========================================================================
// ?IsTactical@idScenePoint_Combat@@QBA_NXZ
// EA  : 0x82CB47C8
// RVA : 0x00CB47C8
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

BOOL __fastcall idScenePoint_Combat::IsTactical(idScenePoint_Combat *this)
{
  return (this->tacFlags & 0xFFFF7FFC) != 0;
}


// ========================================================================
// ?Spawn@idScenePoint_Look@@QAAXXZ
// EA  : 0x82CB47E0
// RVA : 0x00CB47E0
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void __fastcall idScenePoint_Look::Spawn(idScenePoint_Look *this)
{
  this->lookFlags &= ~0x400u;
}


// ========================================================================
// ?Spawn@idScenePoint_Arc@@QAAXXZ
// EA  : 0x82CB47F0
// RVA : 0x00CB47F0
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void __fastcall idScenePoint_Arc::Spawn(idScenePoint_Arc *this)
{
  double minRange; // fp1
  double maxRange; // fp1
  double arcOffset; // fp13
  double v5; // fp0
  double arcAngle; // fp0
  idPresentable *presentable; // r30
  float *v8; // r3
  double z; // fp13
  double x; // fp11
  double v11; // fp1
  double v12; // fp9
  double v13; // fp8
  double v14; // fp6
  long double v15; // fp2
  long double v16; // fp2
  idRotation v17; // [sp+50h] [-70h] BYREF

  minRange = this->minRange;
  if ( minRange < 0.0 )
  {
    idLib::Warning(fmt: "idScenePoint_Arc '%s' minRange is out of bounds (%f), setting to 0", this->name.data, minRange);
    this->minRange = 0.0;
  }
  maxRange = this->maxRange;
  if ( maxRange < 0.0 && maxRange != -1.0 )
  {
    idLib::Warning(
      fmt: "idScenePoint_Arc '%s' maxRange is out of bounds (%f), setting to -1",
      this->name.data,
      maxRange);
    this->maxRange = -1.0;
  }
  arcOffset = this->arcOffset;
  if ( __fabs(arcOffset) > 180.0 )
  {
    if ( arcOffset >= 0.0 )
      v5 = (float)(this->arcOffset - (float)360.0);
    else
      v5 = (float)(this->arcOffset + (float)360.0);
    this->arcOffset = v5;
  }
  arcAngle = this->arcAngle;
  if ( arcAngle >= 0.0 )
  {
    if ( arcAngle > 360.0 )
      arcAngle = 360.0;
  }
  else
  {
    arcAngle = 0.0;
  }
  this->arcAngle = arcAngle;
  v17.angle = this->arcOffset;
  presentable = this->presentable;
  v17.vec.x = 0.0;
  v17.axisValid = false;
  v17.origin.x = vec3_origin.x;
  v17.vec.y = 0.0;
  v17.vec.z = 1.0;
  v17.origin.y = vec3_origin.y;
  v17.origin.z = vec3_origin.z;
  v17.axis.mat[0].x = mat3_identity.mat[0].x;
  v17.axis.mat[0].y = mat3_identity.mat[0].y;
  v17.axis.mat[0].z = mat3_identity.mat[0].z;
  v17.axis.mat[1].x = mat3_identity.mat[1].x;
  v17.axis.mat[1].y = mat3_identity.mat[1].y;
  v17.axis.mat[1].z = mat3_identity.mat[1].z;
  v17.axis.mat[2].x = mat3_identity.mat[2].x;
  v17.axis.mat[2].y = mat3_identity.mat[2].y;
  v17.axis.mat[2].z = mat3_identity.mat[2].z;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v8 = (float *)idRotation::ToMat3(this: &v17);
  z = presentable->axis.mat[0].z;
  x = presentable->axis.mat[0].x;
  v11 = *v8;
  v12 = v8[8];
  v13 = (float)((float)(v8[3] * presentable->axis.mat[0].y) + (float)(v8[6] * presentable->axis.mat[0].z));
  v14 = (float)((float)(v8[2] * presentable->axis.mat[0].x) + (float)(v8[5] * presentable->axis.mat[0].y));
  this->arcDir.y = (float)(v8[7] * presentable->axis.mat[0].z)
                 + (float)((float)(v8[1] * presentable->axis.mat[0].x) + (float)(v8[4] * presentable->axis.mat[0].y));
  this->arcDir.x = (float)((float)v11 * (float)x) + (float)v13;
  this->arcDir.z = (float)((float)v12 * (float)z) + (float)v14;
  *((double *)&v15 + 1) = this->arcAngle;
  *(double *)&v15 = (float)((float)(this->arcAngle * (float)0.5) * idMath::M_DEG2RAD);
  v16 = cos(x: v15);
  this->arcCosAngle = *(double *)&v16;
}


// ========================================================================
// ?ActivateScenePoint@idScenePoint@@QAAXPBVidAI2@@H@Z
// EA  : 0x82CB4AA8
// RVA : 0x00CB4AA8
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void __fastcall idScenePoint::ActivateScenePoint(idScenePoint *this, const idAI2 *user, int curTime)
{
  const idAI2 *currentUser; // r11
  int v5; // r29
  int v6; // r30
  int value; // r9
  idEntity *v8; // r3
  idEntity *v9; // r3

  if ( (*(_BYTE *)&this->flags & 8) != 0 && user != nullptr )
  {
    currentUser = this->currentUser;
    if ( currentUser == user )
    {
      if ( this->type != LOOK )
        idAIMemory::SetActivateScenePointTimeStamp(this: &currentUser->aiVolatile.memory, curTime);
      v5 = 0;
      if ( this->targets.num > 0 )
      {
        v6 = 0;
        do
        {
          value = this->targets.list[v6].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v9 = idEntity::CastTo(c: v8);
          }
          else
          {
            v9 = nullptr;
          }
          idEntity::Activate(this: v9, activator: this);
          ++v5;
          ++v6;
        }
        while ( v5 < this->targets.num );
      }
    }
  }
}


// ========================================================================
// ?IsInArc@idScenePoint_Arc@@UBA_NABVidVec3@@@Z
// EA  : 0x82CB4B90
// RVA : 0x00CB4B90
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

BOOL __fastcall idScenePoint_Arc::IsInArc(idScenePoint_Arc *this, const idVec3 *point)
{
  int value; // r10
  idVolume *v5; // r3
  int v6; // r9
  idVolume *v7; // r3
  idVolume *v8; // r3
  idPhysics *Physics; // r3
  float *v11; // r3
  double v12; // fp30
  double v13; // fp29
  double v14; // fp31
  idPhysics *v15; // r3
  double v16; // fp0
  double maxAbove; // fp13
  double maxBelow; // fp13
  double v21; // fp6
  double v22; // fp9
  double v23; // fp6

  value = this->arcVolume.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = (idVolume *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idVolume::CastTo(c: v5) != nullptr )
  {
    v6 = this->arcVolume.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13
      && (v7 = (idVolume *)gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
    {
      v8 = idVolume::CastTo(c: v7);
      return idVolume_ItemGroup::Contains(this: v8, pos: point);
    }
    else
    {
      return idVolume_ItemGroup::Contains(this: nullptr, pos: point);
    }
  }
  else
  {
    Physics = idEntity::GetPhysics(this);
    v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v12 = (float)(point->x - *v11);
    v13 = (float)(point->y - v11[1]);
    v14 = (float)((float)((float)v13 * (float)v13) + (float)((float)(point->x - *v11) * (float)(point->x - *v11)));
    if ( v14 < (float)(this->minRange * this->minRange)
      || this->maxRange > 0.0 && v14 > (float)(this->maxRange * this->maxRange) )
    {
      return false;
    }
    v15 = idEntity::GetPhysics(this);
    v16 = (float)(point->z - v15->GetOrigin(this: v15, a2: 0)->z);
    maxAbove = this->maxAbove;
    if ( maxAbove < 65535.0 && v16 > maxAbove )
      return false;
    maxBelow = this->maxBelow;
    if ( maxBelow > -65535.0 && v16 < maxBelow )
      return false;
    if ( (float)((float)v16 * (float)v16) > v14 )
    {
      return false;
    }
    else
    {
      _FP9 = (float)((float)v14 - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f7, f9, f31, f13 }
      v21 = __frsqrte(_FP7);
      v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                                          * (float)((float)v14
                                                                                                  * (float)0.5))
                                                                                  * (float)v21)
                                                                          - (float)1.5)
                                                          * (float)v21)
                                                  * (float)((float)v14 * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v21
                                                                                  * (float)((float)v14 * (float)0.5))
                                                                          * (float)v21)
                                                                  - (float)1.5)
                                                  * (float)v21))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v14 * (float)0.5)) * (float)v21)
                                          - (float)1.5)
                          * (float)v21));
      v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)v14 * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                                  * (float)v21)
                                                                                          * (float)((float)v14
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v14 * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                          * (float)v21))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v21
                                                                                                  * (float)((float)v14 * (float)0.5))
                                                                                          * (float)v21)
                                                                                  - (float)1.5)
                                                                  * (float)v21))
                                                  * (float)((float)v14 * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)v14 * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                          * (float)v21)
                                                                                  * (float)((float)v14 * (float)0.5))
                                                                          * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v14 * (float)0.5)) * (float)v21)
                                                                                                  - (float)1.5)
                                                                                  * (float)v21))
                                                                  - (float)1.5)
                                                  * (float)((float)-(float)((float)((float)((float)v21
                                                                                          * (float)((float)v14
                                                                                                  * (float)0.5))
                                                                                  * (float)v21)
                                                                          - (float)1.5)
                                                          * (float)v21)))
                                  - (float)1.5)
                  * (float)v22);
      return (float)((float)(this->arcDir.y * (float)((float)v13 * (float)v23))
                   + (float)(this->arcDir.x * (float)((float)v23 * (float)v12))) >= (double)this->arcCosAngle;
    }
  }
}


// ========================================================================
// ?Spawn@idScenePoint_Combat@@QAAXXZ
// EA  : 0x82CB4DF0
// RVA : 0x00CB4DF0
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void __fastcall idScenePoint_Combat::Spawn(idScenePoint_Combat *this)
{
  int v2; // r29
  int v3; // r31
  int value; // r9
  idEntity *v5; // r3
  idProp_WeaponStatic *v6; // r3
  idProp_WeaponStatic *v7; // r3
  idAnimWebPath *p_enterAnim; // r31
  char *data; // r11
  idScenePoint_Combat::scenePointExitAnim_t *p_exitAnimSet; // r31
  char *v11; // r11
  idAnimWebPath *p_exitAnim_SectorNear; // r31
  char *v13; // r11
  idAnimWebPath *p_exitAnim_SectorLeft; // r31
  char *v15; // r11
  char *v16; // r11
  idAnimWebPath *p_exitAnim_SectorRight; // r31
  char *v18; // r11
  idAnimWebPath *p_exitAnim_SectorFar; // r31
  char *v20; // r11
  idScenePoint_Combat::scenePointCustomSet_t *p_customSet; // r31
  char *v22; // r11

  v2 = 0;
  this->tacFlags &= ~0x8000u;
  if ( this->targets.num > 0 )
  {
    v3 = 0;
    while ( 1 )
    {
      if ( v2 < this->targets.num
        && (value = this->targets.list[v3].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v6 = (idProp_WeaponStatic *)idEntity::CastTo(c: v5);
      }
      else
      {
        v6 = nullptr;
      }
      v7 = idProp_WeaponStatic::CastTo(c: v6);
      if ( v7 != nullptr )
        break;
      ++v2;
      ++v3;
      if ( v2 >= this->targets.num )
        goto LABEL_12;
    }
    this->scenePointTurret = v7;
    idEntity::RemoveTargetIndex(this, i: v2);
  }
LABEL_12:
  p_enterAnim = &this->enterAnimSet.enterAnim;
  if ( idStr::Find(
         searchIn: this->enterAnimSet.enterAnim.data,
         searchFor: "ENTER_ANIMATION",
         casesensitive: false,
         start: 0,
         end: this->enterAnimSet.enterAnim.len) != -1 )
  {
    if ( this->enterAnimSet.enterAnim.allocedAndFlag >= 0 )
    {
      idStr::FreeData(this: &this->enterAnimSet.enterAnim);
      this->enterAnimSet.enterAnim.allocedAndFlag = 20;
      this->enterAnimSet.enterAnim.data = this->enterAnimSet.enterAnim.baseBuffer;
      p_enterAnim->len = 0;
      this->enterAnimSet.enterAnim.baseBuffer[0] = 0;
    }
    else
    {
      data = this->enterAnimSet.enterAnim.data;
      p_enterAnim->len = 0;
      *data = 0;
    }
  }
  p_exitAnimSet = &this->exitAnimSet;
  if ( idStr::Find(
         searchIn: this->exitAnimSet.exitAnim_Timeout.data,
         searchFor: "EXIT_ANIMATION",
         casesensitive: false,
         start: 0,
         end: this->exitAnimSet.exitAnim_Timeout.len) != -1 )
  {
    if ( this->exitAnimSet.exitAnim_Timeout.allocedAndFlag >= 0 )
    {
      idStr::FreeData(this: &this->exitAnimSet.exitAnim_Timeout);
      this->exitAnimSet.exitAnim_Timeout.allocedAndFlag = 20;
      this->exitAnimSet.exitAnim_Timeout.data = this->exitAnimSet.exitAnim_Timeout.baseBuffer;
      p_exitAnimSet->exitAnim_Timeout.len = 0;
      this->exitAnimSet.exitAnim_Timeout.baseBuffer[0] = 0;
    }
    else
    {
      v11 = this->exitAnimSet.exitAnim_Timeout.data;
      p_exitAnimSet->exitAnim_Timeout.len = 0;
      *v11 = 0;
    }
  }
  p_exitAnim_SectorNear = &this->exitAnimSet.exitAnim_SectorNear;
  if ( idStr::Find(
         searchIn: this->exitAnimSet.exitAnim_SectorNear.data,
         searchFor: "EXIT_ANIMATION",
         casesensitive: false,
         start: 0,
         end: this->exitAnimSet.exitAnim_SectorNear.len) != -1 )
  {
    if ( this->exitAnimSet.exitAnim_SectorNear.allocedAndFlag >= 0 )
    {
      idStr::FreeData(this: &this->exitAnimSet.exitAnim_SectorNear);
      this->exitAnimSet.exitAnim_SectorNear.allocedAndFlag = 20;
      this->exitAnimSet.exitAnim_SectorNear.data = this->exitAnimSet.exitAnim_SectorNear.baseBuffer;
      p_exitAnim_SectorNear->len = 0;
      this->exitAnimSet.exitAnim_SectorNear.baseBuffer[0] = 0;
    }
    else
    {
      v13 = this->exitAnimSet.exitAnim_SectorNear.data;
      p_exitAnim_SectorNear->len = 0;
      *v13 = 0;
    }
  }
  p_exitAnim_SectorLeft = &this->exitAnimSet.exitAnim_SectorLeft;
  if ( idStr::Find(
         searchIn: this->exitAnimSet.exitAnim_SectorLeft.data,
         searchFor: "EXIT_ANIMATION",
         casesensitive: false,
         start: 0,
         end: this->exitAnimSet.exitAnim_SectorLeft.len) != -1 )
  {
    if ( this->exitAnimSet.exitAnim_SectorLeft.allocedAndFlag >= 0 )
    {
      idStr::FreeData(this: &this->exitAnimSet.exitAnim_SectorLeft);
      this->exitAnimSet.exitAnim_SectorLeft.allocedAndFlag = 20;
      this->exitAnimSet.exitAnim_SectorLeft.data = this->exitAnimSet.exitAnim_SectorLeft.baseBuffer;
      p_exitAnim_SectorLeft->len = 0;
      this->exitAnimSet.exitAnim_SectorLeft.baseBuffer[0] = 0;
    }
    else
    {
      v15 = this->exitAnimSet.exitAnim_SectorLeft.data;
      p_exitAnim_SectorLeft->len = 0;
      *v15 = 0;
    }
  }
  if ( idStr::Find(
         searchIn: this->exitAnimSet.exitAnim_SectorLeft.data,
         searchFor: "EXIT_ANIMATION",
         casesensitive: false,
         start: 0,
         end: p_exitAnim_SectorLeft->len) != -1 )
  {
    if ( this->exitAnimSet.exitAnim_SectorLeft.allocedAndFlag >= 0 )
    {
      idStr::FreeData(this: &this->exitAnimSet.exitAnim_SectorLeft);
      this->exitAnimSet.exitAnim_SectorLeft.allocedAndFlag = 20;
      this->exitAnimSet.exitAnim_SectorLeft.data = this->exitAnimSet.exitAnim_SectorLeft.baseBuffer;
      p_exitAnim_SectorLeft->len = 0;
      this->exitAnimSet.exitAnim_SectorLeft.baseBuffer[0] = 0;
    }
    else
    {
      v16 = this->exitAnimSet.exitAnim_SectorLeft.data;
      p_exitAnim_SectorLeft->len = 0;
      *v16 = 0;
    }
  }
  p_exitAnim_SectorRight = &this->exitAnimSet.exitAnim_SectorRight;
  if ( idStr::Find(
         searchIn: this->exitAnimSet.exitAnim_SectorRight.data,
         searchFor: "EXIT_ANIMATION",
         casesensitive: false,
         start: 0,
         end: this->exitAnimSet.exitAnim_SectorRight.len) != -1 )
  {
    if ( this->exitAnimSet.exitAnim_SectorRight.allocedAndFlag >= 0 )
    {
      idStr::FreeData(this: &this->exitAnimSet.exitAnim_SectorRight);
      this->exitAnimSet.exitAnim_SectorRight.allocedAndFlag = 20;
      this->exitAnimSet.exitAnim_SectorRight.data = this->exitAnimSet.exitAnim_SectorRight.baseBuffer;
      p_exitAnim_SectorRight->len = 0;
      this->exitAnimSet.exitAnim_SectorRight.baseBuffer[0] = 0;
    }
    else
    {
      v18 = this->exitAnimSet.exitAnim_SectorRight.data;
      p_exitAnim_SectorRight->len = 0;
      *v18 = 0;
    }
  }
  p_exitAnim_SectorFar = &this->exitAnimSet.exitAnim_SectorFar;
  if ( idStr::Find(
         searchIn: this->exitAnimSet.exitAnim_SectorFar.data,
         searchFor: "EXIT_ANIMATION",
         casesensitive: false,
         start: 0,
         end: this->exitAnimSet.exitAnim_SectorFar.len) != -1 )
  {
    if ( this->exitAnimSet.exitAnim_SectorFar.allocedAndFlag >= 0 )
    {
      idStr::FreeData(this: &this->exitAnimSet.exitAnim_SectorFar);
      this->exitAnimSet.exitAnim_SectorFar.allocedAndFlag = 20;
      this->exitAnimSet.exitAnim_SectorFar.data = this->exitAnimSet.exitAnim_SectorFar.baseBuffer;
      p_exitAnim_SectorFar->len = 0;
      this->exitAnimSet.exitAnim_SectorFar.baseBuffer[0] = 0;
    }
    else
    {
      v20 = this->exitAnimSet.exitAnim_SectorFar.data;
      p_exitAnim_SectorFar->len = 0;
      *v20 = 0;
    }
  }
  p_customSet = &this->customSet;
  if ( idStr::Find(
         searchIn: this->customSet.customCoverSet.data,
         searchFor: "CUSTOM_COVER",
         casesensitive: false,
         start: 0,
         end: this->customSet.customCoverSet.len) != -1 )
  {
    if ( this->customSet.customCoverSet.allocedAndFlag >= 0 )
    {
      idStr::FreeData(this: &this->customSet.customCoverSet);
      this->customSet.customCoverSet.allocedAndFlag = 20;
      this->customSet.customCoverSet.data = this->customSet.customCoverSet.baseBuffer;
      p_customSet->customCoverSet.len = 0;
      this->customSet.customCoverSet.baseBuffer[0] = 0;
    }
    else
    {
      v22 = this->customSet.customCoverSet.data;
      p_customSet->customCoverSet.len = 0;
      *v22 = 0;
    }
  }
}


// ========================================================================
// ?PostSpawn@idScenePoint_UserGroup@@UAAXXZ
// EA  : 0x82CB51D0
// RVA : 0x00CB51D0
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void __fastcall idScenePoint_UserGroup::PostSpawn(idScenePoint_UserGroup *this)
{
  int num; // r26
  int v3; // r27
  int v4; // r29
  int value; // r9
  idEntity *v6; // r3
  idAI2 *v7; // r3
  idAI2 *v8; // r3

  num = this->targets.num;
  v3 = 0;
  if ( num > 0 )
  {
    v4 = 0;
    do
    {
      if ( v3 < this->targets.num
        && (value = this->targets.list[v4].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v7 = (idAI2 *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idAI2::CastTo(c: v7);
      if ( v8 != nullptr )
        idAIMemory::SetScenePointUserGroup(
          this: &v8->aiVolatile.memory,
          group: (idEntityPtr<idScenePoint_UserGroup> *)((gameLocal->spawnIds.ptr[this->entityNumber] << 13)
                                                | this->entityNumber));
      ++v3;
      ++v4;
    }
    while ( v3 < num );
  }
}


// ========================================================================
// ??0idScenePoint@@QAA@XZ
// EA  : 0x82CB52A8
// RVA : 0x00CB52A8
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

idScenePoint *__fastcall idScenePoint::idScenePoint(idScenePoint *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idScenePoint_vtbl *)&idScenePoint::`vftable';
  this->userGroup.spawnId.value = 0x1FFF;
  this->duration = -1.0;
  this->radius = 25.0;
  this->scriptFlags = SCRIPTFLAG_ID_STUDIO_RENDER;
  this->type = 0;
  this->currentUser = nullptr;
  this->requestTime = -1;
  this->relatedScenePoints.list = nullptr;
  this->relatedScenePoints.granularity = 0;
  this->relatedScenePoints.memTag = 5;
  this->relatedScenePoints.listStatic = 0;
  this->relatedScenePoints.size = 0;
  this->relatedScenePoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->relatedScenePoints);
  return this;
}


// ========================================================================
// __unwind$490992
// EA  : 0x82CB5360
// RVA : 0x00CB5360
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void _unwind_490992()
{
  int v0; // r12

  idSpawnNode::~idSpawnNode(this: *(idAIHint **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idScenePoint_Roam@@QAA@XZ
// EA  : 0x82CB5388
// RVA : 0x00CB5388
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

idScenePoint_Roam *__fastcall idScenePoint_Roam::idScenePoint_Roam(idScenePoint_Roam *this)
{
  idScenePoint::idScenePoint(this);
  this->__vftable = (idScenePoint_Roam_vtbl *)&idScenePoint_Roam::`vftable';
  this->scenePointAnimation.len = 0;
  this->scenePointAnimation.allocedAndFlag = 20;
  this->scenePointAnimation.data = this->scenePointAnimation.baseBuffer;
  this->scenePointAnimation.baseBuffer[0] = 0;
  this->duration = 8.0;
  this->type = ROAM;
  this->radius = 25.0;
  return this;
}


// ========================================================================
// ??0idScenePoint_Arc@@QAA@XZ
// EA  : 0x82CB54E0
// RVA : 0x00CB54E0
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

idScenePoint_Arc *__fastcall idScenePoint_Arc::idScenePoint_Arc(idScenePoint_Arc *this)
{
  float z; // r4

  idScenePoint::idScenePoint(this);
  this->__vftable = (idScenePoint_Arc_vtbl *)&idScenePoint_Arc::`vftable';
  this->arcDir.x = vec3_origin.x;
  this->arcDir.y = vec3_origin.y;
  z = vec3_origin.z;
  this->arcCosAngle = 0.5;
  this->minRange = 50.0;
  this->arcDir.z = z;
  this->maxRange = 200.0;
  this->arcAngle = 60.0;
  this->arcOffset = 0.0;
  this->maxAbove = 65535.0;
  this->maxBelow = -65535.0;
  this->arcVolume.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ??0idScenePoint_Combat@@QAA@XZ
// EA  : 0x82CB55A0
// RVA : 0x00CB55A0
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

idScenePoint_Combat *__fastcall idScenePoint_Combat::idScenePoint_Combat(idScenePoint_Combat *this)
{
  int len; // r26
  int v3; // r28
  int v4; // r28
  int v5; // r28
  int v6; // r28
  int v7; // r28
  int v8; // r28
  idStr v10; // [sp+60h] [-120h] BYREF
  idStr v11; // [sp+80h] [-100h] BYREF
  idStr v12; // [sp+A0h] [-E0h] BYREF
  idStr v13; // [sp+C0h] [-C0h] BYREF
  idStr v14; // [sp+E0h] [-A0h] BYREF
  idStr v15; // [sp+100h] [-80h] BYREF
  idStr v16[3]; // [sp+120h] [-60h] BYREF

  idScenePoint_Arc::idScenePoint_Arc(this);
  this->scenePointTurret = nullptr;
  this->__vftable = (idScenePoint_Combat_vtbl *)&idScenePoint_Combat::`vftable';
  this->tacFlags = TACFLAG_ID_STUDIO_RENDER;
  this->customSet.customCoverSet.len = 0;
  this->customSet.customCoverSet.allocedAndFlag = 20;
  this->customSet.customCoverSet.data = this->customSet.customCoverSet.baseBuffer;
  this->customSet.customCoverSet.baseBuffer[0] = 0;
  this->customSet.hurtAnim.data = this->customSet.hurtAnim.baseBuffer;
  this->customSet.hurtAnim.allocedAndFlag = 20;
  this->customSet.hurtAnim.len = 0;
  this->customSet.hurtAnim.baseBuffer[0] = 0;
  this->customSet.deathAnim.allocedAndFlag = 20;
  this->customSet.deathAnim.data = this->customSet.deathAnim.baseBuffer;
  this->customSet.deathAnim.len = 0;
  this->customSet.deathAnim.baseBuffer[0] = 0;
  this->enterAnimSet.enterAnim.allocedAndFlag = 20;
  this->enterAnimSet.enterAnim.len = 0;
  this->enterAnimSet.enterAnim.data = this->enterAnimSet.enterAnim.baseBuffer;
  this->enterAnimSet.enterAnim.baseBuffer[0] = 0;
  this->exitAnimSet.exitAnim_Timeout.allocedAndFlag = 20;
  this->exitAnimSet.exitAnim_Timeout.len = 0;
  this->exitAnimSet.exitAnim_Timeout.data = this->exitAnimSet.exitAnim_Timeout.baseBuffer;
  this->exitAnimSet.exitAnim_Timeout.baseBuffer[0] = 0;
  this->exitAnimSet.exitAnim_SectorNear.allocedAndFlag = 20;
  this->exitAnimSet.exitAnim_SectorNear.data = this->exitAnimSet.exitAnim_SectorNear.baseBuffer;
  this->exitAnimSet.exitAnim_SectorNear.len = 0;
  this->exitAnimSet.exitAnim_SectorNear.baseBuffer[0] = 0;
  this->exitAnimSet.exitAnim_SectorLeft.data = this->exitAnimSet.exitAnim_SectorLeft.baseBuffer;
  this->exitAnimSet.exitAnim_SectorLeft.allocedAndFlag = 20;
  this->exitAnimSet.exitAnim_SectorLeft.len = 0;
  this->exitAnimSet.exitAnim_SectorLeft.baseBuffer[0] = 0;
  this->exitAnimSet.exitAnim_SectorRight.data = this->exitAnimSet.exitAnim_SectorRight.baseBuffer;
  this->exitAnimSet.exitAnim_SectorRight.allocedAndFlag = 20;
  this->exitAnimSet.exitAnim_SectorRight.len = 0;
  this->exitAnimSet.exitAnim_SectorRight.baseBuffer[0] = 0;
  this->exitAnimSet.exitAnim_SectorFar.allocedAndFlag = 20;
  this->exitAnimSet.exitAnim_SectorFar.data = this->exitAnimSet.exitAnim_SectorFar.baseBuffer;
  this->exitAnimSet.exitAnim_SectorFar.len = 0;
  this->exitAnimSet.exitAnim_SectorFar.baseBuffer[0] = 0;
  this->type = 4;
  this->enterAnimSet.forced = true;
  idStr::idStr(this: &v13, text: "ENTER_ANIMATION");
  len = v13.len;
  idStr::EnsureAlloced(this: &this->enterAnimSet.enterAnim, amount: v13.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->enterAnimSet.enterAnim.data, Src: v13.data, Size: len);
  this->enterAnimSet.enterAnim.data[len] = 0;
  this->enterAnimSet.enterAnim.len = len;
  idStr::FreeData(this: &v13);
  idStr::idStr(this: &v15, text: "EXIT_ANIMATION");
  v3 = v15.len;
  idStr::EnsureAlloced(
    this: &this->exitAnimSet.exitAnim_Timeout,
    amount: v15.len + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->exitAnimSet.exitAnim_Timeout.data, Src: v15.data, Size: v3);
  this->exitAnimSet.exitAnim_Timeout.data[v3] = 0;
  this->exitAnimSet.exitAnim_Timeout.len = v3;
  idStr::FreeData(this: &v15);
  idStr::idStr(this: &v10, text: "EXIT_ANIMATION");
  v4 = v10.len;
  idStr::EnsureAlloced(
    this: &this->exitAnimSet.exitAnim_SectorNear,
    amount: v10.len + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->exitAnimSet.exitAnim_SectorNear.data, Src: v10.data, Size: v4);
  this->exitAnimSet.exitAnim_SectorNear.data[v4] = 0;
  this->exitAnimSet.exitAnim_SectorNear.len = v4;
  idStr::FreeData(this: &v10);
  idStr::idStr(this: &v11, text: "EXIT_ANIMATION");
  v5 = v11.len;
  idStr::EnsureAlloced(
    this: &this->exitAnimSet.exitAnim_SectorLeft,
    amount: v11.len + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->exitAnimSet.exitAnim_SectorLeft.data, Src: v11.data, Size: v5);
  this->exitAnimSet.exitAnim_SectorLeft.data[v5] = 0;
  this->exitAnimSet.exitAnim_SectorLeft.len = v5;
  idStr::FreeData(this: &v11);
  idStr::idStr(this: &v12, text: "EXIT_ANIMATION");
  v6 = v12.len;
  idStr::EnsureAlloced(
    this: &this->exitAnimSet.exitAnim_SectorRight,
    amount: v12.len + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->exitAnimSet.exitAnim_SectorRight.data, Src: v12.data, Size: v6);
  this->exitAnimSet.exitAnim_SectorRight.data[v6] = 0;
  this->exitAnimSet.exitAnim_SectorRight.len = v6;
  idStr::FreeData(this: &v12);
  idStr::idStr(this: &v14, text: "EXIT_ANIMATION");
  v7 = v14.len;
  idStr::EnsureAlloced(
    this: &this->exitAnimSet.exitAnim_SectorFar,
    amount: v14.len + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->exitAnimSet.exitAnim_SectorFar.data, Src: v14.data, Size: v7);
  this->exitAnimSet.exitAnim_SectorFar.data[v7] = 0;
  this->exitAnimSet.exitAnim_SectorFar.len = v7;
  idStr::FreeData(this: &v14);
  idStr::idStr(this: v16, text: "CUSTOM_COVER");
  v8 = v16[0].len;
  idStr::EnsureAlloced(
    this: &this->customSet.customCoverSet,
    amount: v16[0].len + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->customSet.customCoverSet.data, Src: v16[0].data, Size: v8);
  this->customSet.customCoverSet.data[v8] = 0;
  this->customSet.customCoverSet.len = v8;
  idStr::FreeData(this: v16);
  return this;
}


// ========================================================================
// __unwind$491246
// EA  : 0x82CB5910
// RVA : 0x00CB5910
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void _unwind_491246()
{
  int v0; // r12

  idScenePoint_Arc::~idScenePoint_Arc(this: *(idScenePoint_Arc **)(v0 - 384 + 404));
}


// ========================================================================
// __unwind$491247
// EA  : 0x82CB5938
// RVA : 0x00CB5938
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void _unwind_491247()
{
  int v0; // r12

  keyBindings_t::~keyBindings_t(this: (testReportField_t *)(*(_DWORD *)(v0 - 384 + 404) + 904));
}


// ========================================================================
// __unwind$491248
// EA  : 0x82CB5964
// RVA : 0x00CB5964
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void _unwind_491248()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(*(_DWORD *)(v0 - 384 + 404) + 1000));
}


// ========================================================================
// __unwind$491249
// EA  : 0x82CB5990
// RVA : 0x00CB5990
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void _unwind_491249()
{
  int v0; // r12

  idScenePoint_Combat::scenePointExitAnim_t::~scenePointExitAnim_t(this: (idScenePoint_Combat::scenePointExitAnim_t *)(*(_DWORD *)(v0 - 384 + 404) + 1036));
}


// ========================================================================
// __unwind$491250
// EA  : 0x82CB59BC
// RVA : 0x00CB59BC
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void _unwind_491250()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 192));
}


// ========================================================================
// __unwind$491251
// EA  : 0x82CB59E4
// RVA : 0x00CB59E4
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void _unwind_491251()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 256));
}


// ========================================================================
// __unwind$491252
// EA  : 0x82CB5A0C
// RVA : 0x00CB5A0C
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void _unwind_491252()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 96));
}


// ========================================================================
// __unwind$491253_0
// EA  : 0x82CB5A34
// RVA : 0x00CB5A34
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void _unwind_491253_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 128));
}


// ========================================================================
// __unwind$491254
// EA  : 0x82CB5A5C
// RVA : 0x00CB5A5C
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void _unwind_491254()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 160));
}


// ========================================================================
// __unwind$491255
// EA  : 0x82CB5A84
// RVA : 0x00CB5A84
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void _unwind_491255()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 224));
}


// ========================================================================
// __unwind$491256
// EA  : 0x82CB5AAC
// RVA : 0x00CB5AAC
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void _unwind_491256()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 288));
}


// ========================================================================
// ??0idScenePoint_Search@@QAA@XZ
// EA  : 0x82CB5C20
// RVA : 0x00CB5C20
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

idScenePoint_Search *__fastcall idScenePoint_Search::idScenePoint_Search(idScenePoint_Search *this)
{
  idScenePoint_Arc::idScenePoint_Arc(this);
  this->searchFlags = SEARCHFLAG_ID_STUDIO_RENDER;
  this->duration = 8.0;
  this->__vftable = (idScenePoint_Search_vtbl *)&idScenePoint_Search::`vftable';
  this->radius = 25.0;
  this->type = ROAM|LOOK;
  return this;
}


// ========================================================================
// ??0idScenePoint_Look@@QAA@XZ
// EA  : 0x82CB5CE8
// RVA : 0x00CB5CE8
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

idScenePoint_Look *__fastcall idScenePoint_Look::idScenePoint_Look(idScenePoint_Look *this)
{
  idScenePoint_Arc::idScenePoint_Arc(this);
  this->lookFlags = LOOKFLAG_ID_STUDIO_RENDER;
  this->duration = -1.0;
  this->__vftable = (idScenePoint_Look_vtbl *)&idScenePoint_Look::`vftable';
  this->radius = 0.0;
  this->type = LOOK;
  return this;
}


// ========================================================================
// ?Spawn@idScenePoint@@QAAXXZ
// EA  : 0x82CB5D50
// RVA : 0x00CB5D50
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void __fastcall idScenePoint::Spawn(idScenePoint *this)
{
  idAAS2 *AAS; // r3
  idAAS2 *v3; // r31
  idAAS2_vtbl *v4; // r25
  int v5; // r3
  int v6; // r3
  int v7; // r31
  int v8; // r29
  int value; // r9
  idEntity *v10; // r3
  idScenePoint *v11; // r3
  idScenePoint *v12; // r3
  int num; // r8
  int v14; // r10
  int v15; // r11
  idScenePoint *v16; // [sp+50h] [-70h] BYREF
  char v17; // [sp+60h] [-60h] BYREF

  AAS = idGameLocal::LoadAAS(this: gameLocal, type: AAS_MONSTER48);
  v3 = AAS;
  if ( AAS == nullptr || AAS->IsDefault(this: AAS) )
  {
    idLib::Warning(fmt: "idScenePoint '%s' - failed to load appropriate AAS.", this->name.data);
  }
  else
  {
    v4 = v3->__vftable;
    v5 = (int)v3->DefaultSearchBounds(this: (idAAS2 *)&v17, result: (idBounds *)v3);
    if ( v4->PointReachableAreaNum(
           this: v3,
           a2: nullptr,
           a3: &this->spawnPosition,
           a4: (const idBounds *)v5,
           a5: 2,
           a6: 1) <= 0 )
    {
      v6 = (int)v3->GetSettings(this: v3);
      idLib::Warning(fmt: "idScenePoint '%s' is outside of aas %s'", this->name.data, *(const char **)(v6 + 8));
    }
  }
  this->scriptFlags &= ~0x8000u;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->relatedScenePoints);
  v7 = this->targets.num - 1;
  if ( v7 >= 0 )
  {
    v8 = v7;
    do
    {
      if ( v7 < this->targets.num
        && (value = this->targets.list[v8].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v10 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v11 = (idScenePoint *)idEntity::CastTo(c: v10);
      }
      else
      {
        v11 = nullptr;
      }
      v12 = idScenePoint::CastTo(c: v11);
      v16 = v12;
      if ( v12 != nullptr )
      {
        num = this->relatedScenePoints.num;
        v14 = 0;
        if ( num <= 0 )
          goto LABEL_20;
        v15 = 0;
        while ( this->relatedScenePoints.list[v15] != v12 )
        {
          ++v14;
          ++v15;
          if ( v14 >= num )
            goto LABEL_20;
        }
        if ( v14 < 0 )
LABEL_20:
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->relatedScenePoints,
            obj: (encounterGroupRole_t *)&v16);
        idEntity::RemoveTargetIndex(this, i: v7);
      }
      --v7;
      --v8;
    }
    while ( v7 >= 0 );
  }
}


// ========================================================================
// ?GetNextScenePoint@idScenePoint@@QBAPAV1@W4scenePointType_t@@@Z
// EA  : 0x82CB5F30
// RVA : 0x00CB5F30
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

idScenePoint *__fastcall idScenePoint::GetNextScenePoint(idScenePoint *this, scenePointType_t spTypeRequired)
{
  int num; // r30
  signed int v5; // r9
  int v6; // r29
  encounterGroupRole_t *list; // r4
  int v8; // r10
  encounterGroupRole_t *v9; // r11
  unsigned int v11; // r5
  int v12; // r10
  encounterGroupRole_t v13; // r30
  idScenePoint *v14; // [sp+50h] [-60h] BYREF
  idList<enum encounterGroupRole_t,5> v15[5]; // [sp+60h] [-50h] BYREF

  num = this->relatedScenePoints.num;
  if ( num <= 0 )
    return nullptr;
  memset(v15, 0, 14);
  v15[0].memTag = 5;
  v15[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v15);
  v5 = v15[0].num;
  v6 = 0;
  list = v15[0].list;
  do
  {
    v14 = this->relatedScenePoints.list[v6];
    if ( v14 != nullptr && (spTypeRequired == 0 || v14->type == spTypeRequired) )
    {
      v8 = 0;
      if ( v5 <= 0 )
        goto LABEL_12;
      v9 = list;
      while ( *(idScenePoint **)v9 != v14 )
      {
        ++v8;
        ++v9;
        if ( v8 >= v5 )
          goto LABEL_12;
      }
      if ( v8 < 0 )
      {
LABEL_12:
        idList<idAnimWebBlendTree *,5>::Append(this: v15, obj: (encounterGroupRole_t *)&v14);
        v5 = v15[0].num;
        list = v15[0].list;
      }
    }
    --num;
    ++v6;
  }
  while ( num != 0 );
  if ( v5 <= 0 )
  {
    if ( (v15[0].listStatic == 0 || v15[0].listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    return nullptr;
  }
  __twllei(v5, 0);
  v11 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v11;
  v12 = (v11 >> 10) & 0x7FFF;
  __twlgei(v5 & ~(__ROL4__(v12, 1) - 1), 0xFFFFFFFF);
  v13 = list[v12 % v5];
  if ( (v15[0].listStatic == 0 || v15[0].listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  return (idScenePoint *)v13;
}


// ========================================================================
// __unwind$492251
// EA  : 0x82CB60E4
// RVA : 0x00CB60E4
// PDB : w:\tech5\tungsten\game\entities\scenepoint.cpp
// ========================================================================

void _unwind_492251()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 96));
}

