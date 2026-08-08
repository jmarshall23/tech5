
// ========================================================================
// ??0idAICover@@QAA@ABV0@@Z
// EA  : 0x82A88710
// RVA : 0x00A88710
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

idAICover *__fastcall idAICover::idAICover(idAICover *this, const idAICover *other)
{
  *this = *other;
  return this;
}


// ========================================================================
// ??4idAICover@@QAAAAV0@ABV0@@Z
// EA  : 0x82A88730
// RVA : 0x00A88730
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

idAICover *__fastcall idAICover::operator=(idAICover *this, const idAICover *other)
{
  if ( this != other )
    *this = *other;
  return this;
}


// ========================================================================
// ?Init@idAICover@@QAAXPBVidEntity@@PBVidAAS2@@H@Z
// EA  : 0x82A88758
// RVA : 0x00A88758
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void __fastcall idAICover::Init(idAICover *this, const idEntity *ent, const idAAS2 *aas, __int16 index)
{
  int value; // r10
  char v8; // [sp+50h] [-30h] BYREF

  value = idGameLocal::GetSpawnId(this: (idGameLocal *)&v8, result: (idSpawnId *)gameLocal, ent)->value;
  this->aas = aas;
  this->coverIndex = index;
  this->spawnId.value = value;
}


// ========================================================================
// ?GetEntity@idEventArg@@QBAPBVidEntity@@XZ
// EA  : 0x82A887A0
// RVA : 0x00A887A0
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

const idEntity *__fastcall idEventArg::GetEntity(idAICover *this)
{
  return gameLocal->GetEntityForSpawnId(this: gameLocal, a2: (const idSpawnId *)this->spawnId.value);
}


// ========================================================================
// ??8idAICover@@QBA_NABV0@@Z
// EA  : 0x82A88888
// RVA : 0x00A88888
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

int __fastcall idAICover::operator==(idAICover *this, const idAICover *other)
{
  unsigned __int8 v2; // r11

  if ( this->spawnId.value != other->spawnId.value )
    return 0;
  if ( this->aas != other->aas )
    return 0;
  v2 = 1;
  if ( this->coverIndex != other->coverIndex )
    return 0;
  return v2;
}


// ========================================================================
// ??0idAICover@@QAA@PBVidAAS2@@H@Z
// EA  : 0x82A888C8
// RVA : 0x00A888C8
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

idAICover *__fastcall idAICover::idAICover(idAICover *this, const idAAS2 *aas, __int16 index)
{
  this->aas = aas;
  this->spawnId.value = 0x1FFF;
  this->coverIndex = index;
  return this;
}


// ========================================================================
// ?GetCoverPoint@idAICover@@QBAPBUaas2Cover_t@@XZ
// EA  : 0x82A888E0
// RVA : 0x00A888E0
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

const aas2Cover_t *__fastcall idAICover::GetCoverPoint(idAICover *this)
{
  idEntity *v3; // r3
  int v4; // r3

  if ( this->coverIndex < 0 )
    return nullptr;
  if ( this->spawnId.value == 0x1FFF )
    return ((const aas2Cover_t *(*)(void))this->aas->GetCoverPoint)();
  v3 = gameLocal->GetEntityForSpawnId(this: gameLocal, a2: this->spawnId.value);
  if ( v3 == nullptr )
    return nullptr;
  v4 = (int)v3->GetDynamicCoverMgr_2(this: v3);
  if ( v4 == 0 )
    return nullptr;
  return (*(const aas2Cover_t *(__fastcall **)(int, const idAAS2 *, _DWORD))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: this->aas,
           a3: this->coverIndex);
}


// ========================================================================
// ?Init@idAICover@@QAAXPBVidAAS2@@H@Z
// EA  : 0x82A889C0
// RVA : 0x00A889C0
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void __fastcall idAICover::Init(idAICover *this, const idAAS2 *aas, __int16 index)
{
  this->aas = aas;
  this->coverIndex = index;
  this->spawnId.value = 0x1FFF;
}


// ========================================================================
// ??0idAICover@@QAA@XZ
// EA  : 0x82A889D8
// RVA : 0x00A889D8
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void __fastcall idAICover::idAICover(idAICover *this)
{
  this->aas = nullptr;
  this->spawnId.value = 0x1FFF;
  this->coverIndex = -1;
}


// ========================================================================
// ?IsValid@idAICover@@QBA_NXZ
// EA  : 0x82A889F8
// RVA : 0x00A889F8
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

int __fastcall idAICover::IsValid(idAICover *this)
{
  const aas2Cover_t *CoverPoint; // r3
  unsigned __int8 v4; // r11

  if ( this->spawnId.value == 0x1FFF )
  {
    if ( this->aas == nullptr )
      return 0;
    v4 = 1;
    if ( this->coverIndex <= 0 )
      return 0;
    return v4;
  }
  else
  {
    return gameLocal->GetEntityForSpawnId(this: gameLocal, a2: this->spawnId.value) != nullptr
        && (CoverPoint = idAICover::GetCoverPoint(this)) != nullptr
        && (~CoverPoint->flags & 0x2000) != 0;
  }
}


// ========================================================================
// ?GetCoverPosture@idAICover@@QBA?AW4posture_t@@XZ
// EA  : 0x82A88AC8
// RVA : 0x00A88AC8
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

int __fastcall idAICover::GetCoverPosture(idAICover *this)
{
  const aas2Cover_t *CoverPoint; // r3

  CoverPoint = idAICover::GetCoverPoint(this);
  if ( CoverPoint != nullptr )
    return ((_cntlzw(CoverPoint->flags & 1) & 0x20) == 0) + 1;
  else
    return 1;
}


// ========================================================================
// ?GetAreaNum@idAICover@@QBAHXZ
// EA  : 0x82A88B20
// RVA : 0x00A88B20
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

const aas2Cover_t *__fastcall idAICover::GetAreaNum(idAICover *this)
{
  const aas2Cover_t *result; // r3

  result = idAICover::GetCoverPoint(this);
  if ( result != nullptr )
    return (const aas2Cover_t *)result->areaNum;
  return result;
}


// ========================================================================
// ?GetOrigin@idAICover@@QBAABVidVec3@@XZ
// EA  : 0x82A88B60
// RVA : 0x00A88B60
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

const aas2Cover_t *__fastcall idAICover::GetOrigin(idAICover *this)
{
  const aas2Cover_t *result; // r3

  result = idAICover::GetCoverPoint(this);
  if ( result == nullptr )
    return (const aas2Cover_t *)&vec3_origin;
  return result;
}


// ========================================================================
// ?GetDir@idAICover@@QBAABVidVec3@@XZ
// EA  : 0x82A88B90
// RVA : 0x00A88B90
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

const idVec3 *__fastcall idAICover::GetDir(idAICover *this)
{
  const aas2Cover_t *CoverPoint; // r3

  CoverPoint = idAICover::GetCoverPoint(this);
  if ( CoverPoint != nullptr )
    return &CoverPoint->dir;
  else
    return &vec3_origin;
}


// ========================================================================
// ?GetAxis@idAICover@@QBAXAAVidMat3@@@Z
// EA  : 0x82A88BD8
// RVA : 0x00A88BD8
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void __fastcall idAICover::GetAxis(idAICover *this, idMat3 *axis)
{
  const aas2Cover_t *CoverPoint; // r3
  const idAAS2Settings *v5; // r3
  double x; // fp11
  double v7; // fp5
  double y; // fp10
  double v9; // fp4
  double z; // fp9
  double v13; // fp1
  double v14; // fp11
  double v15; // fp4
  double v16; // fp6
  double v17; // fp5
  double v18; // fp4
  double v19; // fp1
  double v20; // fp10
  double v21; // fp3
  double v22; // fp8
  double v23; // fp4
  double v24; // fp9
  double v25; // fp5
  double v26; // fp6
  double v27; // fp3
  double v28; // fp2
  double v29; // fp9
  double v32; // fp7
  double v33; // fp5
  double v34; // fp11
  double v35; // fp9
  double v36; // fp7

  CoverPoint = idAICover::GetCoverPoint(this);
  if ( CoverPoint != nullptr )
  {
    axis->mat[0].x = CoverPoint->dir.x;
    axis->mat[0].y = CoverPoint->dir.y;
    axis->mat[0].z = CoverPoint->dir.z;
    v5 = this->aas->GetSettings(this: this->aas);
    x = v5->gravityDir.x;
    axis->mat[2].x = v5->gravityDir.x;
    v7 = x;
    y = v5->gravityDir.y;
    v9 = (float)((float)((float)x * (float)x) + (float)(v5->gravityDir.y * v5->gravityDir.y));
    axis->mat[2].y = v5->gravityDir.y;
    z = v5->gravityDir.z;
    axis->mat[2].z = v5->gravityDir.z;
    _FP2 = (float)((float)((float)((float)z * (float)z) + (float)v9) - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f13, f2, f3, f13 }
    v13 = (float)((float)((float)((float)z * (float)z) + (float)v9) * (float)0.5);
    v14 = __frsqrte(_FP13);
    v15 = (float)((float)-(float)((float)((float)((float)v14
                                                * (float)((float)((float)((float)z * (float)z) + (float)v9) * (float)0.5))
                                        * (float)v14)
                                - (float)1.5)
                * (float)v14);
    v16 = (float)((float)v7
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)v13)
                                                                                        * (float)v15)
                                                                                - (float)1.5)
                                                                * (float)v15)
                                                        * (float)v13)
                                                * (float)((float)-(float)((float)((float)((float)v15 * (float)v13)
                                                                                * (float)v15)
                                                                        - (float)1.5)
                                                        * (float)v15))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v15 * (float)v13) * (float)v15) - (float)1.5)
                                * (float)v15)));
    axis->mat[2].x = (float)v7
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)v13)
                                                                                           * (float)v15)
                                                                                   - (float)1.5)
                                                                   * (float)v15)
                                                           * (float)v13)
                                                   * (float)((float)-(float)((float)((float)((float)v15 * (float)v13)
                                                                                   * (float)v15)
                                                                           - (float)1.5)
                                                           * (float)v15))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v15 * (float)v13) * (float)v15) - (float)1.5)
                                   * (float)v15));
    v17 = (float)((float)y
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)v13)
                                                                                        * (float)v15)
                                                                                - (float)1.5)
                                                                * (float)v15)
                                                        * (float)v13)
                                                * (float)((float)-(float)((float)((float)((float)v15 * (float)v13)
                                                                                * (float)v15)
                                                                        - (float)1.5)
                                                        * (float)v15))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v15 * (float)v13) * (float)v15) - (float)1.5)
                                * (float)v15)));
    axis->mat[2].y = (float)y
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)v13)
                                                                                           * (float)v15)
                                                                                   - (float)1.5)
                                                                   * (float)v15)
                                                           * (float)v13)
                                                   * (float)((float)-(float)((float)((float)((float)v15 * (float)v13)
                                                                                   * (float)v15)
                                                                           - (float)1.5)
                                                           * (float)v15))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v15 * (float)v13) * (float)v15) - (float)1.5)
                                   * (float)v15));
    v18 = (float)((float)z
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)v13)
                                                                                        * (float)v15)
                                                                                - (float)1.5)
                                                                * (float)v15)
                                                        * (float)v13)
                                                * (float)((float)-(float)((float)((float)((float)v15 * (float)v13)
                                                                                * (float)v15)
                                                                        - (float)1.5)
                                                        * (float)v15))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v15 * (float)v13) * (float)v15) - (float)1.5)
                                * (float)v15)));
    axis->mat[2].z = v18;
    v19 = axis->mat[0].y;
    v20 = axis->mat[0].x;
    v21 = axis->mat[0].z;
    v22 = (float)((float)v18 * axis->mat[0].y);
    v23 = (float)((float)(axis->mat[0].x * (float)v18) - (float)((float)v16 * axis->mat[0].z));
    axis->mat[1].y = v23;
    v24 = (float)((float)v20 * (float)v17);
    v25 = (float)((float)((float)v17 * (float)v21) - (float)v22);
    axis->mat[1].x = v25;
    v26 = (float)((float)((float)v16 * (float)v19) - (float)v24);
    axis->mat[1].z = v26;
    v27 = v25;
    v28 = v26;
    v29 = (float)((float)((float)v26 * (float)v26)
                + (float)((float)((float)v25 * (float)v25) + (float)((float)v23 * (float)v23)));
    _FP8 = (float)((float)((float)((float)v26 * (float)v26)
                         + (float)((float)((float)v25 * (float)v25) + (float)((float)v23 * (float)v23)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f6, f8, f9, f13 }
    v32 = (float)((float)v29 * (float)0.5);
    v33 = __frsqrte(_FP6);
    v34 = (float)((float)-(float)((float)((float)((float)v33 * (float)((float)v29 * (float)0.5)) * (float)v33)
                                - (float)1.5)
                * (float)v33);
    v35 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33
                                                                                * (float)((float)v29 * (float)0.5))
                                                                        * (float)v33)
                                                                - (float)1.5)
                                                * (float)v33)
                                        * (float)((float)v29 * (float)0.5))
                                * (float)((float)-(float)((float)((float)((float)v33 * (float)((float)v29 * (float)0.5))
                                                                * (float)v33)
                                                        - (float)1.5)
                                        * (float)v33))
                        - (float)1.5);
    v36 = (float)((float)((float)v35 * (float)v34) * (float)v32);
    axis->mat[1].x = (float)v27
                   * (float)((float)-(float)((float)((float)v36 * (float)((float)v35 * (float)v34)) - (float)1.5)
                           * (float)((float)v35 * (float)v34));
    axis->mat[1].y = (float)v23
                   * (float)((float)-(float)((float)((float)v36 * (float)((float)v35 * (float)v34)) - (float)1.5)
                           * (float)((float)v35 * (float)v34));
    axis->mat[1].z = (float)v28
                   * (float)((float)-(float)((float)((float)v36 * (float)((float)v35 * (float)v34)) - (float)1.5)
                           * (float)((float)v35 * (float)v34));
  }
  else
  {
    *axis = mat3_identity;
  }
}


// ========================================================================
// ?IsPartiallyExposed@idAICover@@QBA_NXZ
// EA  : 0x82A88DE8
// RVA : 0x00A88DE8
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

BOOL __fastcall idAICover::IsPartiallyExposed(idAICover *this)
{
  const aas2Cover_t *CoverPoint; // r3

  CoverPoint = idAICover::GetCoverPoint(this);
  return CoverPoint == nullptr || (CoverPoint->flags & 0x400) != 0;
}


// ========================================================================
// ?IsFullyExposed@idAICover@@QBA_NXZ
// EA  : 0x82A88E30
// RVA : 0x00A88E30
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

BOOL __fastcall idAICover::IsFullyExposed(idAICover *this)
{
  const aas2Cover_t *CoverPoint; // r3

  CoverPoint = idAICover::GetCoverPoint(this);
  return CoverPoint == nullptr || (_cntlzw(CoverPoint->flags & 0x3E0) & 0x20) != 0;
}


// ========================================================================
// ?IsReserved@idAICover@@QBA_NXZ
// EA  : 0x82A88E80
// RVA : 0x00A88E80
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

const aas2Cover_t *__fastcall idAICover::IsReserved(idAICover *this)
{
  const aas2Cover_t *result; // r3

  result = idAICover::GetCoverPoint(this);
  if ( result != nullptr )
    return (const aas2Cover_t *)(result->reservedBy
                               - 0x1FFF
                               - (result->reservedBy
                                - 0x2000
                                + (result->reservedBy == 0x1FFF)));
  return result;
}


// ========================================================================
// ?GetReserver@idAICover@@QBAPBVidEntity@@XZ
// EA  : 0x82A88EC8
// RVA : 0x00A88EC8
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

const idEntity *__fastcall idAICover::GetReserver(idAICover *this)
{
  const idEntity *result; // r3

  result = (const idEntity *)idAICover::GetCoverPoint(this);
  if ( result != nullptr )
    return gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: LODWORD(result->spawnPosition.y));
  return result;
}


// ========================================================================
// ?Reserve@idAICover@@QBAXPBVidEntity@@@Z
// EA  : 0x82A88F20
// RVA : 0x00A88F20
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void __fastcall idAICover::Reserve(idAICover *this, const idEntity *reserver)
{
  idSpawnId *CoverPoint; // r31
  char v4; // [sp+50h] [-20h] BYREF

  CoverPoint = (idSpawnId *)idAICover::GetCoverPoint(this);
  if ( CoverPoint != nullptr )
    CoverPoint[12].value = idGameLocal::GetSpawnId(
                             this: (idGameLocal *)&v4,
                             result: (idSpawnId *)gameLocal,
                             ent: reserver)->value;
}


// ========================================================================
// ?Unreserve@idAICover@@QBAXXZ
// EA  : 0x82A88F80
// RVA : 0x00A88F80
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void __fastcall idAICover::Unreserve(idAICover *this)
{
  const aas2Cover_t *CoverPoint; // r3

  CoverPoint = idAICover::GetCoverPoint(this);
  if ( CoverPoint != nullptr )
    CoverPoint->reservedBy = 0x1FFF;
}


// ========================================================================
// ?GetCoverActions@idAICover@@QBAXAAVidCoverActions@@@Z
// EA  : 0x82A88FB0
// RVA : 0x00A88FB0
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void __fastcall idAICover::GetCoverActions(idAICover *this, idCoverActions *actions)
{
  const aas2Cover_t *CoverPoint; // r4

  CoverPoint = idAICover::GetCoverPoint(this);
  if ( CoverPoint != nullptr )
    idCoverActions::Init(this: actions, cover: CoverPoint);
}


// ========================================================================
// ?GetOrientation@idAICover@@QBAXW4coverOrientation_t@@AAVidMat3@@@Z
// EA  : 0x82A88FF0
// RVA : 0x00A88FF0
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void __fastcall idAICover::GetOrientation(idAICover *this, const coverOrientation_t orient, idMat3 *axis)
{
  double v5; // fp10
  double v6; // fp9
  double y; // fp7
  double v8; // fp5

  idAICover::GetAxis(this, axis);
  if ( orient == COVERORIENT_BACKWARD )
  {
    v5 = -axis->mat[0].y;
    v6 = -axis->mat[0].z;
    axis->mat[0].x = -axis->mat[0].x;
    axis->mat[0].y = v5;
    axis->mat[0].z = v6;
    y = axis->mat[1].y;
    v8 = -axis->mat[1].z;
    axis->mat[1].x = -axis->mat[1].x;
    axis->mat[1].y = -y;
    axis->mat[1].z = v8;
  }
}


// ========================================================================
// ?IsPointInFrontOf@idAICover@@QBA_NABVidVec3@@@Z
// EA  : 0x82A89080
// RVA : 0x00A89080
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

BOOL __fastcall idAICover::IsPointInFrontOf(idAICover *this, const idVec3 *point)
{
  const aas2Cover_t *CoverPoint; // r3
  idVec3 *p_dir; // r30
  const aas2Cover_t *v6; // r11
  double v7; // fp0
  unsigned int v9; // r11

  CoverPoint = idAICover::GetCoverPoint(this);
  p_dir = &vec3_origin;
  if ( CoverPoint != nullptr )
    p_dir = &CoverPoint->dir;
  v6 = idAICover::GetCoverPoint(this);
  if ( v6 == nullptr )
    v6 = (const aas2Cover_t *)&vec3_origin;
  v7 = (float)((float)((float)(point->x * p_dir->x)
                     + (float)((float)(point->y * p_dir->y) + (float)(point->z * p_dir->z)))
             - (float)((float)(v6->origin.x * p_dir->x)
                     + (float)((float)(v6->origin.z * p_dir->z) + (float)(v6->origin.y * p_dir->y))));
  if ( v7 > 0.0 )
    return (_cntlzw(0) & 0x20) != 0;
  v9 = 1;
  if ( v7 >= -0.0 )
    v9 = 2;
  return (_cntlzw(v9) & 0x20) != 0;
}


// ========================================================================
// ?IsPointInArc@idAICover@@QBA_NABVidVec3@@M@Z
// EA  : 0x82A89158
// RVA : 0x00A89158
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

BOOL __fastcall idAICover::IsPointInArc(idAICover *this, const idVec3 *point, double arcAcos)
{
  const aas2Cover_t *CoverPoint; // r3
  idVec3 *p_dir; // r27
  const aas2Cover_t *v8; // r11
  double v9; // fp30
  double v10; // fp29
  double v11; // fp31
  const aas2Cover_t *v12; // r30
  const aas2Cover_t *v13; // r3
  double v17; // fp7
  double v18; // fp13
  double v19; // fp6

  CoverPoint = idAICover::GetCoverPoint(this);
  p_dir = &vec3_origin;
  if ( CoverPoint != nullptr )
    p_dir = &CoverPoint->dir;
  v8 = idAICover::GetCoverPoint(this);
  if ( v8 == nullptr )
    v8 = (const aas2Cover_t *)&vec3_origin;
  v9 = (float)(point->x - v8->origin.x);
  v10 = (float)(point->y - v8->origin.y);
  v11 = (float)((float)((float)v10 * (float)v10)
              + (float)((float)(point->x - v8->origin.x) * (float)(point->x - v8->origin.x)));
  v12 = idAICover::GetCoverPoint(this);
  v13 = idAICover::GetCoverPoint(this);
  if ( v13 == nullptr )
    v13 = (const aas2Cover_t *)&vec3_origin;
  if ( v12 != nullptr
    && (v11 < (float)(v12->minRange * v12->minRange)
     || v12->maxRange != 0.0 && v11 > (float)(v12->maxRange * v12->maxRange)) )
  {
    return false;
  }
  _FP10 = (float)((float)v11 - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f8, f10, f31, f13 }
  v17 = __frsqrte(_FP8);
  v18 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)v11 * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17)
                                              * (float)((float)v11 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                              * (float)((float)v11 * (float)0.5))
                                                                      * (float)v17)
                                                              - (float)1.5)
                                              * (float)v17))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v11 * (float)0.5)) * (float)v17)
                                      - (float)1.5)
                      * (float)v17));
  v19 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)v11 * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17)
                                                                                              * (float)((float)v11 * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v11 * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                              * (float)v17))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v11 * (float)0.5))
                                                                                              * (float)v17)
                                                                                      - (float)1.5)
                                                                      * (float)v17))
                                                      * (float)((float)v11 * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)v11 * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                              * (float)v17)
                                                                                      * (float)((float)v11 * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v11 * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                      * (float)v17))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                                              * (float)((float)v11 * (float)0.5))
                                                                                      * (float)v17)
                                                                              - (float)1.5)
                                                              * (float)v17)))
                                      - (float)1.5)
                      * (float)v18)
              * (float)v10);
  return (float)((float)(p_dir->y * (float)v19)
               + (float)(p_dir->x
                       * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)v11 * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17) * (float)((float)v11 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v11 * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17))
                                                                                               - (float)1.5)
                                                                               * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v11 * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                       * (float)v17))
                                                                       * (float)((float)v11 * (float)0.5))
                                                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)v11 * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17) * (float)((float)v11 * (float)0.5))
                                                                                               * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v11 * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v11 * (float)0.5)) * (float)v17)
                                                                                               - (float)1.5)
                                                                               * (float)v17)))
                                                       - (float)1.5)
                                       * (float)v18)
                               * (float)v9))) >= arcAcos
      && (float)((float)(point->z - v13->origin.z) * (float)(point->z - v13->origin.z)) <= v11;
}


// ========================================================================
// ?IsPointOnLeanSide@idAICover@@QBA_NABVidVec3@@@Z
// EA  : 0x82A892F0
// RVA : 0x00A892F0
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

const aas2Cover_t *__fastcall idAICover::IsPointOnLeanSide(idAICover *this, const idVec3 *point)
{
  const aas2Cover_t *result; // r3
  const aas2Cover_t *v5; // r29
  const aas2Cover_t *CoverPoint; // r3
  idVec3 *p_dir; // r11
  double v8; // fp29
  double v9; // fp30
  double v10; // fp28
  const aas2Cover_t *v11; // r11
  __int16 flags; // r11
  double v13; // fp2
  int v14; // r10

  result = idAICover::GetCoverPoint(this);
  v5 = result;
  if ( result != nullptr )
  {
    if ( (result->flags & 0x3C0) != 0 )
    {
      CoverPoint = idAICover::GetCoverPoint(this);
      p_dir = &vec3_origin;
      if ( CoverPoint != nullptr )
        p_dir = &CoverPoint->dir;
      v8 = (float)(p_dir->y - (float)(p_dir->z * (float)0.0));
      v9 = (float)((float)(p_dir->x * (float)0.0) - (float)(p_dir->y * (float)0.0));
      v10 = (float)((float)(p_dir->z * (float)0.0) - p_dir->x);
      v11 = idAICover::GetCoverPoint(this);
      if ( v11 == nullptr )
        v11 = (const aas2Cover_t *)&vec3_origin;
      v13 = (float)((float)((float)(point->x * (float)v8)
                          + (float)((float)(point->z * (float)v9) + (float)(point->y * (float)v10)))
                  - (float)((float)(v11->origin.x * (float)v8)
                          + (float)((float)(v11->origin.z * (float)v9) + (float)(v11->origin.y * (float)v10))));
      flags = v5->flags;
      if ( v13 <= 0.0 )
        v14 = flags & 0x140;
      else
        v14 = flags & 0x280;
      return (const aas2Cover_t *)(v14 != 0);
    }
    else
    {
      return (const aas2Cover_t *)1;
    }
  }
  return result;
}


// ========================================================================
// ?GetEyePoint@idAICover@@QBAXPBVidActor@@AAVidVec3@@@Z
// EA  : 0x82A89420
// RVA : 0x00A89420
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void __fastcall idAICover::GetEyePoint(idAICover *this, const idActor *user, idVec3 *eyePoint)
{
  const aas2Cover_t *CoverPoint; // r3
  const aas2Cover_t *v7; // r11
  double x; // fp0
  double v9; // fp13
  double y; // fp12
  double z; // fp9
  double v12; // fp8

  CoverPoint = idAICover::GetCoverPoint(this);
  if ( CoverPoint != nullptr && (_cntlzw(CoverPoint->flags & 1) & 0x20) == 0 )
  {
    v7 = idAICover::GetCoverPoint(this);
    if ( v7 == nullptr )
      v7 = (const aas2Cover_t *)&vec3_origin;
    x = user->actorConstants.perception.crouchedEyeOffset.x;
    v9 = v7->origin.x;
    y = user->actorConstants.perception.crouchedEyeOffset.y;
    z = user->actorConstants.perception.crouchedEyeOffset.z;
  }
  else
  {
    v7 = idAICover::GetCoverPoint(this);
    if ( v7 == nullptr )
      v7 = (const aas2Cover_t *)&vec3_origin;
    x = v7->origin.x;
    v9 = user->actorConstants.perception.eyeOffset.x;
    y = user->actorConstants.perception.eyeOffset.y;
    z = user->actorConstants.perception.eyeOffset.z;
  }
  v12 = (float)((float)y + v7->origin.y);
  eyePoint->z = (float)z + v7->origin.z;
  eyePoint->y = v12;
  eyePoint->x = (float)x + (float)v9;
}


// ========================================================================
// ?GetFiringPoint@idAICover@@QBA_NPBVidActor@@W4firePoint_t@@AAVidVec3@@@Z
// EA  : 0x82A894F0
// RVA : 0x00A894F0
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

int __fastcall idAICover::GetFiringPoint(idAICover *this, const idActor *user, unsigned int fp, idVec3 *firePoint)
{
  const aas2Cover_t *CoverPoint; // r3
  idVec3 *p_origin; // r27
  float *v10; // r3
  double y; // fp30
  double z; // fp29
  double x; // fp28
  double v14; // fp31
  double v15; // fp13
  double v16; // fp31
  const aas2Cover_t *v17; // r4
  const aas2Cover_t *v18; // r3
  int v19; // r11
  double v21; // fp12
  double v22; // fp11
  double v23; // fp10
  double v24; // fp11
  double v25; // fp9
  double v26; // fp11
  double v27; // fp9
  idCoverActions v28; // [sp+58h] [-88h] BYREF
  idMat3 v29; // [sp+60h] [-80h] BYREF

  CoverPoint = idAICover::GetCoverPoint(this);
  if ( CoverPoint != nullptr )
    p_origin = &CoverPoint->origin;
  else
    p_origin = &vec3_origin;
  idAICover::GetAxis(this, axis: &v29);
  v10 = (float *)this->aas->GetSettings(this: this->aas);
  y = v29.mat[1].y;
  z = v29.mat[1].z;
  x = v29.mat[1].x;
  v14 = (float)((float)((float)((float)__fabs((float)(v29.mat[1].z
                                                    * (float)(v10[30] - (float)((float)(v10[27] + v10[30]) * (float)0.5))))
                              + (float)__fabs((float)(v29.mat[1].y
                                                    * (float)(v10[29] - (float)((float)(v10[26] + v10[29]) * (float)0.5)))))
                      + (float)__fabs((float)(v29.mat[1].x
                                            * (float)(v10[28] - (float)((float)(v10[28] + v10[25]) * (float)0.5)))))
              + (float)((float)(v29.mat[1].z * (float)((float)(v10[27] + v10[30]) * (float)0.5))
                      + (float)((float)(v29.mat[1].x * (float)((float)(v10[28] + v10[25]) * (float)0.5))
                              + (float)(v29.mat[1].y * (float)((float)(v10[26] + v10[29]) * (float)0.5)))));
  v15 = (float)(*(float *)(((int (*)(void))this->aas->GetSettings)() + 240) + (float)v14);
  *((_BYTE *)&v28 + 4) &= 7u;
  v28.__vftable = (idCoverActions_vtbl *)&idCoverActions::`vftable';
  v16 = (float)((float)v15 + (float)4.0);
  v17 = idAICover::GetCoverPoint(this);
  if ( v17 != nullptr )
    idCoverActions::Init(this: &v28, cover: v17);
  firePoint->x = 0.0;
  firePoint->z = 0.0;
  firePoint->y = 0.0;
  idAICover::GetEyePoint(this, user, eyePoint: firePoint);
  v18 = idAICover::GetCoverPoint(this);
  if ( v18 != nullptr )
    v19 = ((_cntlzw(v18->flags & 1) & 0x20) == 0) + 1;
  else
    v19 = 1;
  if ( fp != 0 )
  {
    if ( fp == 1 )
    {
      if ( v19 == 2 && (*((_BYTE *)&v28 + 4) & 0x10) == 0 )
        return 0;
      if ( (*((_BYTE *)&v28 + 4) & 0x10) == 0 && (*((_BYTE *)&v28 + 4) & 8) == 0 )
        return 0;
      v24 = firePoint->y;
      v25 = firePoint->z;
      firePoint->x = firePoint->x + (float)((float)x * (float)v16);
      firePoint->z = (float)v25 + (float)((float)z * (float)v16);
      firePoint->y = (float)v24 + (float)((float)y * (float)v16);
    }
    else
    {
      if ( fp >= 3 )
        return 0;
      if ( v19 != 2 || (*((_BYTE *)&v28 + 4) & 0x80) == 0 )
        return 0;
      v21 = user->actorConstants.perception.eyeOffset.y;
      v22 = (float)(user->actorConstants.perception.eyeOffset.z + p_origin->z);
      v23 = p_origin->y;
      firePoint->x = user->actorConstants.perception.eyeOffset.x + p_origin->x;
      firePoint->y = (float)v21 + (float)v23;
      firePoint->z = v22;
    }
  }
  else
  {
    if ( v19 == 2 && (*((_BYTE *)&v28 + 4) & 0x40) == 0 )
      return 0;
    if ( (*((_BYTE *)&v28 + 4) & 0x40) == 0 && (*((_BYTE *)&v28 + 4) & 0x20) == 0 )
      return 0;
    v26 = firePoint->y;
    v27 = firePoint->z;
    firePoint->x = firePoint->x - (float)((float)x * (float)v16);
    firePoint->z = (float)v27 - (float)((float)z * (float)v16);
    firePoint->y = (float)v26 - (float)((float)y * (float)v16);
  }
  return 1;
}


// ========================================================================
// __unwind$488917
// EA  : 0x82A89800
// RVA : 0x00A89800
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void _unwind_488917()
{
  int v0; // r12

  idCoverActions::~idCoverActions(this: (idCoverActions *)(v0 - 224 + 88));
}


// ========================================================================
// ?GetExposedPoint@idAICover@@QBA_NW4firePoint_t@@AAVidVec3@@@Z
// EA  : 0x82A89830
// RVA : 0x00A89830
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

int __fastcall idAICover::GetExposedPoint(idAICover *this, unsigned int fp, idVec3 *exposedPoint)
{
  const aas2Cover_t *CoverPoint; // r3
  idVec3 *p_origin; // r28
  const aas2Cover_t *v8; // r4
  const aas2Cover_t *v9; // r3
  int v10; // r11
  double z; // fp10
  double y; // fp9
  double v14; // fp6
  double v15; // fp5
  double v16; // fp10
  double v17; // fp9
  double v18; // fp6
  double v19; // fp5
  idCoverActions v20; // [sp+50h] [-70h] BYREF
  idMat3 v21; // [sp+60h] [-60h] BYREF

  CoverPoint = idAICover::GetCoverPoint(this);
  if ( CoverPoint != nullptr )
    p_origin = &CoverPoint->origin;
  else
    p_origin = &vec3_origin;
  idAICover::GetAxis(this, axis: &v21);
  *((_BYTE *)&v20 + 4) &= 7u;
  v20.__vftable = (idCoverActions_vtbl *)&idCoverActions::`vftable';
  v8 = idAICover::GetCoverPoint(this);
  if ( v8 != nullptr )
    idCoverActions::Init(this: &v20, cover: v8);
  exposedPoint->x = 0.0;
  exposedPoint->z = 0.0;
  exposedPoint->y = 0.0;
  v9 = idAICover::GetCoverPoint(this);
  if ( v9 != nullptr )
    v10 = ((_cntlzw(v9->flags & 1) & 0x20) == 0) + 1;
  else
    v10 = 1;
  if ( fp != 0 )
  {
    if ( fp == 1 )
    {
      if ( v10 == 2 && (*((_BYTE *)&v20 + 4) & 0x10) == 0 )
        return 0;
      if ( (*((_BYTE *)&v20 + 4) & 0x10) == 0 && (*((_BYTE *)&v20 + 4) & 8) == 0 )
        return 0;
      z = p_origin->z;
      y = p_origin->y;
      v14 = (float)(v21.mat[1].z * (float)50.0);
      v15 = (float)(v21.mat[1].y * (float)50.0);
      exposedPoint->x = p_origin->x + (float)(v21.mat[1].x * (float)50.0);
      exposedPoint->z = (float)z + (float)v14;
      exposedPoint->y = (float)y + (float)v15;
    }
    else
    {
      if ( fp >= 3 )
        return 0;
      if ( v10 != 2 || (*((_BYTE *)&v20 + 4) & 0x80) == 0 )
        return 0;
      exposedPoint->x = p_origin->x;
      exposedPoint->y = p_origin->y;
      exposedPoint->z = p_origin->z;
    }
  }
  else
  {
    if ( v10 == 2 && (*((_BYTE *)&v20 + 4) & 0x40) == 0 )
      return 0;
    if ( (*((_BYTE *)&v20 + 4) & 0x40) == 0 && (*((_BYTE *)&v20 + 4) & 0x20) == 0 )
      return 0;
    v16 = p_origin->z;
    v17 = p_origin->y;
    v18 = (float)(v21.mat[1].z * (float)50.0);
    v19 = (float)(v21.mat[1].y * (float)50.0);
    exposedPoint->x = p_origin->x - (float)(v21.mat[1].x * (float)50.0);
    exposedPoint->z = (float)v16 - (float)v18;
    exposedPoint->y = (float)v17 - (float)v19;
  }
  return 1;
}


// ========================================================================
// __unwind$489234
// EA  : 0x82A89A64
// RVA : 0x00A89A64
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void _unwind_489234()
{
  int v0; // r12

  idCoverActions::~idCoverActions(this: (idCoverActions *)(v0 - 192 + 80));
}


// ========================================================================
// ?VisibilityRatioFromFirePoints@idAICover@@QBAMPBVidActor@@PBVidAAS2@@H@Z
// EA  : 0x82A89A98
// RVA : 0x00A89A98
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

float __fastcall idAICover::VisibilityRatioFromFirePoints(
        idAICover *this,
        const idActor *user,
        const idAAS2 *aas,
        int areaNum)
{
  int i; // r24
  const aas2Cover_t *CoverPoint; // r3
  idVec3 *p_origin; // r30
  float *v12; // r3
  double y; // fp30
  double z; // fp29
  double x; // fp28
  double v16; // fp31
  double v17; // fp1
  double v18; // fp31
  const aas2Cover_t *v19; // r4
  const aas2Cover_t *v20; // r3
  int v21; // r11
  char v22; // r11
  double v23; // fp9
  double v24; // fp7
  double v26; // fp1
  idCoverActions v28; // [sp+58h] [-E8h] BYREF
  idVec3 v29; // [sp+60h] [-E0h] BYREF
  idMat3 v30; // [sp+70h] [-D0h] BYREF

  _FP24 = 0.0;
  for ( i = 0; i < 3; ++i )
  {
    CoverPoint = idAICover::GetCoverPoint(this);
    p_origin = &vec3_origin;
    if ( CoverPoint != nullptr )
      p_origin = &CoverPoint->origin;
    idAICover::GetAxis(this, axis: &v30);
    v12 = (float *)this->aas->GetSettings(this: this->aas);
    y = v30.mat[1].y;
    z = v30.mat[1].z;
    x = v30.mat[1].x;
    v16 = (float)((float)((float)((float)__fabs((float)(v30.mat[1].z
                                                      * (float)(v12[30]
                                                              - (float)((float)(v12[27] + v12[30]) * (float)0.5))))
                                + (float)__fabs((float)(v30.mat[1].y
                                                      * (float)(v12[29]
                                                              - (float)((float)(v12[26] + v12[29]) * (float)0.5)))))
                        + (float)__fabs((float)(v30.mat[1].x
                                              * (float)(v12[28] - (float)((float)(v12[28] + v12[25]) * (float)0.5)))))
                + (float)((float)(v30.mat[1].z * (float)((float)(v12[27] + v12[30]) * (float)0.5))
                        + (float)((float)(v30.mat[1].x * (float)((float)(v12[28] + v12[25]) * (float)0.5))
                                + (float)(v30.mat[1].y * (float)((float)(v12[26] + v12[29]) * (float)0.5)))));
    v17 = (float)(*(float *)(((int (*)(void))this->aas->GetSettings)() + 240) + (float)v16);
    v28.__vftable = (idCoverActions_vtbl *)&idCoverActions::`vftable';
    *((_BYTE *)&v28 + 4) &= 7u;
    v18 = (float)((float)v17 + (float)4.0);
    v19 = idAICover::GetCoverPoint(this);
    if ( v19 != nullptr )
      idCoverActions::Init(this: &v28, cover: v19);
    v29.z = 0.0;
    v29.y = 0.0;
    v29.x = 0.0;
    idAICover::GetEyePoint(this, user, eyePoint: &v29);
    v20 = idAICover::GetCoverPoint(this);
    if ( v20 != nullptr )
      v21 = ((_cntlzw(v20->flags & 1) & 0x20) == 0) + 1;
    else
      v21 = 1;
    if ( i != 0 )
    {
      if ( i == 1 )
      {
        if ( v21 == 2 )
        {
          v22 = *((_BYTE *)&v28 + 4) & 0x10;
          if ( (*((_BYTE *)&v28 + 4) & 0x10) == 0 )
            goto LABEL_28;
        }
        if ( (*((_BYTE *)&v28 + 4) & 0x10) == 0 )
        {
          v22 = *((_BYTE *)&v28 + 4) & 8;
          if ( (*((_BYTE *)&v28 + 4) & 8) == 0 )
            goto LABEL_28;
        }
        v29.x = (float)((float)x * (float)v18) + v29.x;
        v29.z = v29.z + (float)((float)z * (float)v18);
        v29.y = v29.y + (float)((float)y * (float)v18);
      }
      else
      {
        if ( (unsigned int)i >= 3 )
        {
          v22 = 0;
          goto LABEL_28;
        }
        if ( v21 != 2 || (*((_BYTE *)&v28 + 4) & 0x80) == 0 )
        {
          v22 = 0;
          goto LABEL_28;
        }
        v23 = (float)(user->actorConstants.perception.eyeOffset.z + p_origin->z);
        v24 = (float)(user->actorConstants.perception.eyeOffset.y + p_origin->y);
        v29.x = user->actorConstants.perception.eyeOffset.x + p_origin->x;
        v29.z = v23;
        v29.y = v24;
      }
    }
    else
    {
      if ( v21 == 2 )
      {
        v22 = *((_BYTE *)&v28 + 4) & 0x40;
        if ( (*((_BYTE *)&v28 + 4) & 0x40) == 0 )
          goto LABEL_28;
      }
      if ( (*((_BYTE *)&v28 + 4) & 0x40) == 0 )
      {
        v22 = *((_BYTE *)&v28 + 4) & 0x20;
        if ( (*((_BYTE *)&v28 + 4) & 0x20) == 0 )
          goto LABEL_28;
      }
      v29.x = v29.x - (float)((float)x * (float)v18);
      v29.z = v29.z - (float)((float)z * (float)v18);
      v29.y = v29.y - (float)((float)y * (float)v18);
    }
    v22 = 1;
LABEL_28:
    v28.__vftable = (idCoverActions_vtbl *)&idCoverActions::`vftable';
    if ( v22 != 0 )
    {
      _FP0 = (float)((float)_FP24
                   - idAASVisCache::VisibilityRatio(this: &gameLocal->aasVisCache, eyePoint: &v29, aas, areaNum));
      __asm { fsel      f24, f0, f24, f1 }
    }
  }
  v26 = _FP24;
  return *((float *)&v26 + 1);
}


// ========================================================================
// __unwind$489373
// EA  : 0x82A89DF0
// RVA : 0x00A89DF0
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void _unwind_489373()
{
  int v0; // r12

  idCoverActions::~idCoverActions(this: (idCoverActions *)(v0 - 320 + 88));
}


// ========================================================================
// ?MakeUnusable@idAICover@@QBAXH@Z
// EA  : 0x82A89E18
// RVA : 0x00A89E18
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void __fastcall idAICover::MakeUnusable(idAICover *this, const int duration)
{
  const aas2Cover_t *CoverPoint; // r31

  CoverPoint = idAICover::GetCoverPoint(this);
  if ( CoverPoint != nullptr )
    CoverPoint->usableTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                           + duration;
}


// ========================================================================
// ?IsUsable@idAICover@@QBA_NXZ
// EA  : 0x82A89E78
// RVA : 0x00A89E78
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

int __fastcall idAICover::IsUsable(idAICover *this)
{
  const aas2Cover_t *CoverPoint; // r31
  unsigned __int8 v2; // r11

  CoverPoint = idAICover::GetCoverPoint(this);
  if ( CoverPoint == nullptr )
    return 0;
  if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) >= CoverPoint->usableTime )
    return 1;
  v2 = 0;
  if ( (CoverPoint->flags & 0x400000) != 0 )
    return 1;
  return v2;
}


// ========================================================================
// ?ShouldAvoid@idAICover@@QBA_NXZ
// EA  : 0x82A89F10
// RVA : 0x00A89F10
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

int __fastcall idAICover::ShouldAvoid(idAICover *this)
{
  const aas2Cover_t *CoverPoint; // r31
  unsigned __int8 v2; // r11

  CoverPoint = idAICover::GetCoverPoint(this);
  if ( CoverPoint == nullptr )
    return 0;
  if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) > CoverPoint->usableTime )
    return 0;
  v2 = 1;
  if ( (CoverPoint->flags & 0x400000) == 0 )
    return 0;
  return v2;
}


// ========================================================================
// ?IsExplicit@idAICover@@QBA_NXZ
// EA  : 0x82A89FA8
// RVA : 0x00A89FA8
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

const aas2Cover_t *__fastcall idAICover::IsExplicit(idAICover *this)
{
  const aas2Cover_t *result; // r3

  result = idAICover::GetCoverPoint(this);
  if ( result != nullptr )
    return (const aas2Cover_t *)((result->flags & 0x800) != 0);
  return result;
}


// ========================================================================
// ?IsExpired@idAICover@@QBA_NH@Z
// EA  : 0x82A89FE8
// RVA : 0x00A89FE8
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

int __fastcall idAICover::IsExpired(idAICover *this, unsigned int stayTime)
{
  const aas2Cover_t *CoverPoint; // r3
  double durationSec; // fp0
  int result; // r3

  CoverPoint = idAICover::GetCoverPoint(this);
  if ( CoverPoint == nullptr )
    return 0;
  durationSec = CoverPoint->durationSec;
  if ( durationSec <= 0.0 )
    return 0;
  result = 1;
  if ( (float)__SPAIR64__(&unk_82150000, stayTime) <= (double)(float)((float)durationSec * (float)1000.0) )
    return 0;
  return result;
}


// ========================================================================
// ?Spawn@idCoverBlocker@@QAAXXZ
// EA  : 0x82A8A060
// RVA : 0x00A8A060
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void __fastcall idCoverBlocker::Spawn(idCoverBlocker *this)
{
  idLinkList<idCoverBlocker> *head; // r5

  head = gameLocal->coverBlockerEntities.head;
  this->coverBlockerNode.prev->next = this->coverBlockerNode.next;
  this->coverBlockerNode.next->prev = this->coverBlockerNode.prev;
  this->coverBlockerNode.prev = &this->coverBlockerNode;
  this->coverBlockerNode.head = &this->coverBlockerNode;
  this->coverBlockerNode.next = head;
  this->coverBlockerNode.prev = head->prev;
  head->prev = &this->coverBlockerNode;
  this->coverBlockerNode.prev->next = &this->coverBlockerNode;
  this->coverBlockerNode.head = head->head;
}


// ========================================================================
// ?AngleToPoint@idAICover@@QBAMABVidVec3@@_N@Z
// EA  : 0x82A8A0C8
// RVA : 0x00A8A0C8
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

float __fastcall idAICover::AngleToPoint(idAICover *this, const idVec3 *point, const bool considerFireOver)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  const aas2Cover_t *CoverPoint; // r25
  double v9; // fp1
  const aas2Cover_t *v10; // r3
  idVec3 *p_dir; // r30
  double v12; // fp30
  double v13; // fp31
  double v14; // fp29
  const aas2Cover_t *v15; // r11
  double v16; // fp11
  long double v17; // fp2
  double v18; // fp10
  double v21; // fp13
  double v22; // fp12
  double v23; // fp8
  double v24; // fp6
  double v25; // fp5
  double v26; // fp0
  double v27; // fp31
  double v28; // fp1
  __int16 flags; // r11
  int v30; // r10
  double v31; // fp31
  idPLogScope v33[6]; // [sp+50h] [-70h] BYREF

  RD_EventBegin(name: "idAICover::AngleToPoint");
  LODWORD(v6) = "idAICover::AngleToPoint";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: v33, pl: &pLog, gMask: v6, label: v7);
  CoverPoint = idAICover::GetCoverPoint(this);
  if ( CoverPoint != nullptr )
  {
    v10 = idAICover::GetCoverPoint(this);
    p_dir = &vec3_origin;
    if ( v10 != nullptr )
      p_dir = &v10->dir;
    v12 = (float)((float)(p_dir->z * (float)0.0) - p_dir->x);
    v13 = (float)((float)(p_dir->x * (float)0.0) - (float)(p_dir->y * (float)0.0));
    v14 = (float)(p_dir->y - (float)(p_dir->z * (float)0.0));
    v15 = idAICover::GetCoverPoint(this);
    if ( v15 == nullptr )
      v15 = (const aas2Cover_t *)&vec3_origin;
    v16 = (float)(point->y - v15->origin.y);
    *((double *)&v17 + 1) = p_dir->x;
    v18 = (float)((float)(point->z - v15->origin.z) * (float)0.5);
    _FP7 = (float)((float)((float)((float)v18 * (float)v18)
                         + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x))
                                 + (float)((float)v16 * (float)v16)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f1, f7, f8, f13 }
    v21 = __frsqrte(_FP1);
    v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16)))
                                                                                                * (float)0.5))
                                                                                * (float)v21)
                                                                        - (float)1.5)
                                                        * (float)v21)
                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                + (float)((float)((float)(point->x - v15->origin.x)
                                                                                * (float)(point->x - v15->origin.x))
                                                                        + (float)((float)v16 * (float)v16)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v21
                                                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                                                + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16)))
                                                                                        * (float)0.5))
                                                                        * (float)v21)
                                                                - (float)1.5)
                                                * (float)v21))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v21
                                                        * (float)((float)((float)((float)v18 * (float)v18)
                                                                        + (float)((float)((float)(point->x
                                                                                                - v15->origin.x)
                                                                                        * (float)(point->x
                                                                                                - v15->origin.x))
                                                                                + (float)((float)v16 * (float)v16)))
                                                                * (float)0.5))
                                                * (float)v21)
                                        - (float)1.5)
                        * (float)v21));
    v23 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                        * (float)v21)
                                                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                                                + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16)))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21)
                                                                                                - (float)1.5)
                                                                                * (float)v21))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v21
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16)))
                                                                                                * (float)0.5))
                                                                                * (float)v21)
                                                                        - (float)1.5)
                                                        * (float)v21))
                                        * (float)((float)((float)((float)v18 * (float)v18)
                                                        + (float)((float)((float)(point->x - v15->origin.x)
                                                                        * (float)(point->x - v15->origin.x))
                                                                + (float)((float)v16 * (float)v16)))
                                                * (float)0.5))
                                * (float)v22)
                        - (float)1.5);
    v24 = (float)((float)v16
                * (float)((float)v23
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                                * (float)v21)
                                                                                        - (float)1.5)
                                                                        * (float)v21)
                                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                                + (float)((float)((float)(point->x - v15->origin.x)
                                                                                                * (float)(point->x - v15->origin.x))
                                                                                        + (float)((float)v16 * (float)v16)))
                                                                        * (float)0.5))
                                                        * (float)((float)-(float)((float)((float)((float)v21
                                                                                                * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                        * (float)v21)
                                                                                - (float)1.5)
                                                                * (float)v21))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v21
                                                                        * (float)((float)((float)((float)v18 * (float)v18)
                                                                                        + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x))
                                                                                                + (float)((float)v16 * (float)v16)))
                                                                                * (float)0.5))
                                                                * (float)v21)
                                                        - (float)1.5)
                                        * (float)v21))));
    v25 = (float)((float)(point->x - v15->origin.x)
                * (float)((float)v23
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                                * (float)v21)
                                                                                        - (float)1.5)
                                                                        * (float)v21)
                                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                                + (float)((float)((float)(point->x - v15->origin.x)
                                                                                                * (float)(point->x - v15->origin.x))
                                                                                        + (float)((float)v16 * (float)v16)))
                                                                        * (float)0.5))
                                                        * (float)((float)-(float)((float)((float)((float)v21
                                                                                                * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                        * (float)v21)
                                                                                - (float)1.5)
                                                                * (float)v21))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v21
                                                                        * (float)((float)((float)((float)v18 * (float)v18)
                                                                                        + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x))
                                                                                                + (float)((float)v16 * (float)v16)))
                                                                                * (float)0.5))
                                                                * (float)v21)
                                                        - (float)1.5)
                                        * (float)v21))));
    v26 = (float)((float)((float)v23
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                                * (float)v21)
                                                                                        - (float)1.5)
                                                                        * (float)v21)
                                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                                + (float)((float)((float)(point->x - v15->origin.x)
                                                                                                * (float)(point->x - v15->origin.x))
                                                                                        + (float)((float)v16 * (float)v16)))
                                                                        * (float)0.5))
                                                        * (float)((float)-(float)((float)((float)((float)v21
                                                                                                * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                        * (float)v21)
                                                                                - (float)1.5)
                                                                * (float)v21))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v21
                                                                        * (float)((float)((float)((float)v18 * (float)v18)
                                                                                        + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x))
                                                                                                + (float)((float)v16 * (float)v16)))
                                                                                * (float)0.5))
                                                                * (float)v21)
                                                        - (float)1.5)
                                        * (float)v21)))
                * (float)v18);
    *(double *)&v17 = (float)((float)((float)v25 * p_dir->x)
                            + (float)((float)(p_dir->z * (float)v26)
                                    + (float)(p_dir->y
                                            * (float)((float)v16
                                                    * (float)((float)v23
                                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21) * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21)
                                                                                            - (float)1.5)
                                                                            * (float)v21)))))));
    v27 = (float)((float)((float)v13 * (float)v26)
                + (float)((float)((float)v24 * (float)v12)
                        + (float)((float)((float)(point->x - v15->origin.x)
                                        * (float)((float)v23
                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                                * (float)v21)
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                        * (float)v21))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v21
                                                                                                * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)(point->x - v15->origin.x) * (float)(point->x - v15->origin.x)) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                        * (float)v21)
                                                                                - (float)1.5)
                                                                * (float)v21))))
                                * (float)v14)));
    v28 = idMath::ACos(a: v17);
    if ( !considerFireOver || (CoverPoint->flags & 0x20) == 0 )
    {
      flags = CoverPoint->flags;
      if ( v27 <= 0.0 )
        v30 = flags & 0x140;
      else
        v30 = flags & 0x280;
      if ( v30 == 0 )
        v28 = -v28;
    }
    v31 = (float)(idMath::M_RAD2DEG * (float)v28);
    idPLogScope::~idPLogScope(this: v33);
    RD_EventEnd();
    v9 = v31;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v33);
    RD_EventEnd();
    v9 = 0.0;
  }
  return *((float *)&v9 + 1);
}


// ========================================================================
// __unwind$490052
// EA  : 0x82A8A2CC
// RVA : 0x00A8A2CC
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void _unwind_490052()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$490053
// EA  : 0x82A8A2F4
// RVA : 0x00A8A2F4
// PDB : w:\tech5\tungsten\game\ai\cover\aicover.cpp
// ========================================================================

void _unwind_490053()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 80));
}

