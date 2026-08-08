
// ========================================================================
// ??1SpaceComponent@bfx@@UAA@XZ
// EA  : 0x8323DAD0
// RVA : 0x0123DAD0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.h
// ========================================================================

void __fastcall bfx::SpaceComponent::~SpaceComponent(bfx::SpaceComponent *this)
{
  this->__vftable = (bfx::SpaceComponent_vtbl *)&bfx::SpaceComponent::`vftable';
}


// ========================================================================
// ?TransformWorldToSpace@Space@bfx@@QBA?AVVec3@2@ABVVector3@2@@Z
// EA  : 0x8323DB38
// RVA : 0x0123DB38
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.h
// ========================================================================

bfx::Space *__fastcall bfx::Space::TransformWorldToSpace(
        bfx::Space *this,
        bfx::Vec3 *result,
        const bfx::Vector3 *posIn)
{
  double m_y; // fp13
  bfx::Vec3 v6; // [sp+50h] [-20h] BYREF

  m_y = posIn->m_y;
  v6.m_x = posIn->m_x;
  v6.m_y = m_y;
  v6.m_z = posIn->m_z;
  bfx::Matrix::operator*((bfx::Matrix *)this, result: (bfx::Vec3 *)((char *)result + 124), rhs: &v6);
  return this;
}


// ========================================================================
// ?TransformWorldToSpace@Space@bfx@@QBA?AVLineSeg@2@ABVLineSegment@2@@Z
// EA  : 0x8323DB90
// RVA : 0x0123DB90
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.h
// ========================================================================

bfx::Space *__fastcall bfx::Space::TransformWorldToSpace(
        bfx::Space *this,
        bfx::LineSeg *result,
        const bfx::LineSegment *lineSegIn)
{
  double m_y; // fp13
  bfx::Vec3 *p_m_y; // r31
  double v7; // fp10
  double m_z; // fp9
  bfx::HandleProxy *v9; // r10
  unsigned int v11; // r9
  float v12; // r8
  float v13; // r7
  float v14; // r6
  bfx::Vec3 v15; // [sp+50h] [-60h] BYREF
  bfx::Vec3 v16; // [sp+60h] [-50h] BYREF
  bfx::Matrix v17; // [sp+70h] [-40h] BYREF

  m_y = lineSegIn->m_v1.m_y;
  p_m_y = (bfx::Vec3 *)&result[5].m_v0.m_y;
  v15.m_x = lineSegIn->m_v1.m_x;
  v15.m_y = m_y;
  v15.m_z = lineSegIn->m_v1.m_z;
  bfx::Matrix::operator*(this: (bfx::Matrix *)&v17.m_data[4], result: (bfx::Vec3 *)&result[5].m_v0.m_y, rhs: &v15);
  v7 = lineSegIn->m_v0.m_y;
  m_z = lineSegIn->m_v0.m_z;
  v16.m_x = lineSegIn->m_v0.m_x;
  v16.m_y = v7;
  v16.m_z = m_z;
  bfx::Matrix::operator*(this: &v17, result: p_m_y, rhs: &v16);
  v9 = (bfx::HandleProxy *)LODWORD(v17.m_data[1]);
  v11 = LODWORD(v17.m_data[2]);
  v12 = v17.m_data[4];
  v13 = v17.m_data[5];
  v14 = v17.m_data[6];
  this->__vftable = (bfx::Space_vtbl *)LODWORD(v17.m_data[0]);
  this->m_pProxy = v9;
  this->m_spaceID = v11;
  this->m_pos.m_x = v12;
  this->m_pos.m_y = v13;
  this->m_pos.m_z = v14;
  return this;
}


// ========================================================================
// ?TransformWorldToSpace@Space@bfx@@QBA?AVTri@2@ABVTriangle@2@@Z
// EA  : 0x8323DC38
// RVA : 0x0123DC38
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.h
// ========================================================================

bfx::Space *__fastcall bfx::Space::TransformWorldToSpace(
        bfx::Space *this,
        bfx::Tri *result,
        const bfx::Triangle *triangleIn)
{
  double m_y; // fp13
  bfx::Vec3 *p_m_y; // r31
  double v7; // fp10
  double m_z; // fp9
  double v9; // fp7
  double v10; // fp6
  bfx::HandleProxy *v11; // r10
  unsigned int v13; // r9
  float v14; // r8
  float v15; // r7
  float v16; // r6
  float v17; // r5
  float v18; // r4
  bfx::Vec3 v19; // [sp+50h] [-80h] BYREF
  bfx::Vec3 v20; // [sp+60h] [-70h] BYREF
  bfx::Vec3 v21; // [sp+70h] [-60h] BYREF
  bfx::Matrix v22; // [sp+80h] [-50h] BYREF

  m_y = triangleIn->m_v2.m_y;
  p_m_y = (bfx::Vec3 *)&result[3].m_v1.m_y;
  v19.m_x = triangleIn->m_v2.m_x;
  v19.m_y = m_y;
  v19.m_z = triangleIn->m_v2.m_z;
  bfx::Matrix::operator*(this: (bfx::Matrix *)&v22.m_data[8], result: (bfx::Vec3 *)&result[3].m_v1.m_y, rhs: &v19);
  v7 = triangleIn->m_v1.m_y;
  m_z = triangleIn->m_v1.m_z;
  v20.m_x = triangleIn->m_v1.m_x;
  v20.m_y = v7;
  v20.m_z = m_z;
  bfx::Matrix::operator*(this: (bfx::Matrix *)&v22.m_data[4], result: p_m_y, rhs: &v20);
  v9 = triangleIn->m_v0.m_y;
  v10 = triangleIn->m_v0.m_z;
  v21.m_x = triangleIn->m_v0.m_x;
  v21.m_y = v9;
  v21.m_z = v10;
  bfx::Matrix::operator*(this: &v22, result: p_m_y, rhs: &v21);
  v11 = (bfx::HandleProxy *)LODWORD(v22.m_data[1]);
  v13 = LODWORD(v22.m_data[2]);
  v14 = v22.m_data[4];
  v15 = v22.m_data[5];
  v16 = v22.m_data[6];
  v17 = v22.m_data[8];
  v18 = v22.m_data[9];
  this->__vftable = (bfx::Space_vtbl *)LODWORD(v22.m_data[0]);
  this->m_pProxy = v11;
  this->m_spaceID = v13;
  this->m_pos.m_x = v14;
  this->m_pos.m_y = v15;
  this->m_pos.m_z = v16;
  this->m_rotSpaceToWorld.m_w = v17;
  this->m_rotSpaceToWorld.m_x = v18;
  this->m_rotSpaceToWorld.m_y = v22.m_data[10];
  return this;
}


// ========================================================================
// ?RotateToSpace@Space@bfx@@QBA?AVVec3@2@ABVVector3@2@@Z
// EA  : 0x8323DD20
// RVA : 0x0123DD20
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.h
// ========================================================================

bfx::Space *__fastcall bfx::Space::RotateToSpace(bfx::Space *this, bfx::Vec3 *result, const bfx::Vector3 *vectorIn)
{
  double m_y; // fp13
  bfx::Vec3 v6; // [sp+50h] [-20h] BYREF

  m_y = vectorIn->m_y;
  v6.m_x = vectorIn->m_x;
  v6.m_y = m_y;
  v6.m_z = vectorIn->m_z;
  bfx::Matrix::Rot((bfx::Matrix *)this, result: (bfx::Vec3 *)((char *)result + 124), rhs: &v6);
  return this;
}


// ========================================================================
// ?RotateToSpace@Space@bfx@@QBA?AVQuat@2@ABVQuaternion@2@@Z
// EA  : 0x8323DD78
// RVA : 0x0123DD78
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.h
// ========================================================================

bfx::Space *__fastcall bfx::Space::RotateToSpace(bfx::Space *this, bfx::Quat *result, const bfx::Quaternion *rotIn)
{
  double m_x; // fp13
  double m_y; // fp12
  double m_z; // fp11
  bfx::Quat v9; // [sp+50h] [-30h] BYREF

  m_x = rotIn->m_x;
  m_y = rotIn->m_y;
  m_z = rotIn->m_z;
  v9.m_w = rotIn->m_w;
  v9.m_x = m_x;
  v9.m_y = m_y;
  v9.m_z = m_z;
  bfx::Quat::Normalize(this: &v9);
  bfx::Quat::operator*((bfx::Quat *)this, result: (bfx::Quat *)((char *)result + 40), rhs: &v9);
  return this;
}


// ========================================================================
// ?TransformSpaceToWorld@Space@bfx@@QBA?AVVector3@2@ABVVec3@2@@Z
// EA  : 0x8323DDE8
// RVA : 0x0123DDE8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.h
// ========================================================================

bfx::Space *__fastcall bfx::Space::TransformSpaceToWorld(
        bfx::Space *this,
        bfx::Vector3 *result,
        const bfx::Vec3 *posIn)
{
  bfx::Vec3 *v4; // r3
  double m_y; // fp13
  double m_z; // fp12
  char v8; // [sp+50h] [-20h] BYREF

  v4 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v8, result: (bfx::Vec3 *)&result[5], rhs: posIn);
  m_y = v4->m_y;
  m_z = v4->m_z;
  *(float *)&this->__vftable = v4->m_x;
  *(float *)&this->m_pProxy = m_y;
  *(float *)&this->m_spaceID = m_z;
  return this;
}


// ========================================================================
// ?TransformSpaceToWorld@Space@bfx@@QBA?AVTriangle@2@ABVTri@2@@Z
// EA  : 0x8323DE38
// RVA : 0x0123DE38
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.h
// ========================================================================

bfx::Space *__fastcall bfx::Space::TransformSpaceToWorld(
        bfx::Space *this,
        bfx::Triangle *result,
        const bfx::Tri *triangleIn)
{
  bfx::Vec3 *p_m_v2; // r31
  bfx::Vec3 *v6; // r3
  bfx::Vec3 *v7; // r3
  bfx::Vec3 *v8; // r3
  float v9; // r5
  float v10; // r10
  double v11; // fp8
  float v13; // [sp+50h] [-70h]
  float v14; // [sp+54h] [-6Ch]
  float v15; // [sp+58h] [-68h]
  float m_x; // [sp+60h] [-60h]
  float m_y; // [sp+64h] [-5Ch]
  float v18; // [sp+64h] [-5Ch]
  float m_z; // [sp+68h] [-58h]
  unsigned int v20; // [sp+68h] [-58h]
  bfx::Matrix v21; // [sp+70h] [-50h] BYREF

  p_m_v2 = (bfx::Vec3 *)&result[1].m_v2;
  v6 = bfx::Matrix::operator*(this: &v21, result: (bfx::Vec3 *)&result[1].m_v2, rhs: &triangleIn->m_v2);
  m_x = v6->m_x;
  m_y = v6->m_y;
  m_z = v6->m_z;
  v7 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v21.m_data[4], result: p_m_v2, rhs: &triangleIn->m_v1);
  v13 = v7->m_x;
  v14 = v7->m_y;
  v15 = v7->m_z;
  v8 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v21.m_data[8], result: p_m_v2, rhs: &triangleIn->m_v0);
  v9 = m_y;
  v18 = v8->m_y;
  v10 = v8->m_x;
  v11 = v8->m_z;
  this->m_pos.m_x = v13;
  this->m_rotSpaceToWorld.m_w = m_x;
  this->m_rotSpaceToWorld.m_x = v9;
  this->m_pos.m_y = v14;
  this->m_pos.m_z = v15;
  this->m_rotSpaceToWorld.m_y = m_z;
  *(float *)&v20 = v11;
  this->m_spaceID = v20;
  *(float *)&this->m_pProxy = v18;
  *(float *)&this->__vftable = v10;
  return this;
}


// ========================================================================
// ?RotateToWorld@Space@bfx@@QBA?AVVector3@2@ABVVec3@2@@Z
// EA  : 0x8323DF28
// RVA : 0x0123DF28
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.h
// ========================================================================

bfx::Space *__fastcall bfx::Space::RotateToWorld(bfx::Space *this, bfx::Vector3 *result, const bfx::Vec3 *vecIn)
{
  bfx::Vec3 *v4; // r3
  double m_y; // fp13
  double m_z; // fp12
  char v8; // [sp+50h] [-20h] BYREF

  v4 = bfx::Matrix::Rot(this: (bfx::Matrix *)&v8, result: (bfx::Vec3 *)&result[5], rhs: vecIn);
  m_y = v4->m_y;
  m_z = v4->m_z;
  *(float *)&this->__vftable = v4->m_x;
  *(float *)&this->m_pProxy = m_y;
  *(float *)&this->m_spaceID = m_z;
  return this;
}

