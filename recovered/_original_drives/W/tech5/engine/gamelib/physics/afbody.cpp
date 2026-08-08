
// ========================================================================
// ?SetClipModel@idAFBody@@QAAXPAVidClipModel@@@Z
// EA  : 0x82719A78
// RVA : 0x00719A78
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void __fastcall idAFBody::SetClipModel(idAFBody *this, idClipModel *clipModel)
{
  idClipModel *v3; // r3

  v3 = this->clipModel;
  if ( v3 != nullptr && v3 != clipModel )
    idClipModel::Delete(this: v3);
  this->clipModel = clipModel;
}


// ========================================================================
// ?SetBouncyness@idAFBody@@QAAXM@Z
// EA  : 0x82719AC8
// RVA : 0x00719AC8
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void __fastcall idAFBody::SetBouncyness(idAFBody *this, double bounce)
{
  if ( bounce < 0.0 || bounce > 1.0 )
    idLib::Warning(fmt: "idAFBody::SetBouncyness: bouncyness out of range, bounce = %.1f", bounce);
  else
    this->bouncyness = bounce;
}


// ========================================================================
// ?SetFriction@idAFBody@@QAAXMMM@Z
// EA  : 0x82719DF8
// RVA : 0x00719DF8
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void __fastcall idAFBody::SetFriction(idAFBody *this, double linear, double angular, double contact)
{
  double v4; // fp0
  double v5; // fp13
  double v6; // fp12
  double v7; // fp13

  v4 = 0.0;
  if ( linear < 0.0 || linear > 1.0 || angular < 0.0 || angular > 1.0 || contact < 0.0 )
  {
    idLib::Warning(
      fmt: "idAFBody::SetFriction: friction out of range, linear = %.1f, angular = %.1f, contact = %.1f",
      linear,
      angular,
      contact);
  }
  else
  {
    this->linearFriction = linear;
    v5 = (float)((float)linear * (float)1.2);
    if ( v5 >= 0.0 )
    {
      if ( v5 <= 1.0 )
        v6 = (float)((float)linear * (float)1.2);
      else
        v6 = 1.0;
    }
    else
    {
      v6 = 0.0;
    }
    v7 = (float)((float)angular * (float)1.2);
    this->linearFrictionWater = v6;
    this->angularFriction = angular;
    if ( v7 >= 0.0 )
    {
      if ( v7 > 1.0 )
      {
        this->angularFrictionWater = 1.0;
        this->contactFriction = contact;
        return;
      }
      v4 = (float)((float)angular * (float)1.2);
    }
    this->angularFrictionWater = v4;
    this->contactFriction = contact;
  }
}


// ========================================================================
// ?SetDensity@idAFBody@@QAAXMABVidMat3@@@Z
// EA  : 0x82719EF8
// RVA : 0x00719EF8
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void __fastcall idAFBody::SetDensity(idAFBody *this, double density, idMat3 *inertiaScale, idMat3 *a4)
{
  idClipModel *clipModel; // r3
  idMat3 *p_inertiaTensor; // r30
  idVec3 *p_centerOfMass; // r29
  float *p_mass; // r28
  double y; // fp13
  double v11; // fp11
  idMat3 v12; // [sp+50h] [-70h] BYREF

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
  {
    p_inertiaTensor = &this->inertiaTensor;
    p_centerOfMass = &this->centerOfMass;
    p_mass = &this->mass;
    idClipModel::GetMassProperties(
      this: clipModel,
      density,
      mass: (float *)inertiaScale,
      centerOfMass: (idVec3 *)&this->mass,
      inertiaTensor: (idMat3 *)&this->centerOfMass);
    if ( this->mass <= 0.0 )
    {
      idLib::Warning(fmt: "idAFBody::SetDensity: invalid mass for body '%s'", this->name.str);
      *p_mass = 1.0;
      this->centerOfMass.z = 0.0;
      this->centerOfMass.y = 0.0;
      p_centerOfMass->x = 0.0;
      this->inertiaTensor.mat[2].z = 1.0;
      this->inertiaTensor.mat[1].y = 1.0;
      p_inertiaTensor->mat[0].x = 1.0;
      this->inertiaTensor.mat[1].z = 0.0;
      this->inertiaTensor.mat[0].z = 0.0;
      this->inertiaTensor.mat[0].y = 0.0;
      this->inertiaTensor.mat[2].y = 0.0;
      this->inertiaTensor.mat[2].x = 0.0;
      this->inertiaTensor.mat[1].x = 0.0;
    }
    this->centerOfMass.z = 0.0;
    this->centerOfMass.y = 0.0;
    p_centerOfMass->x = 0.0;
    this->invMass = (float)1.0 / *p_mass;
    if ( (unsigned __int8)idMat3::Compare(this: a4, a: &mat3_identity) == 0 )
      idMat3::operator*=(this: &this->inertiaTensor, a: a4);
    if ( (unsigned __int8)idMat3::IsDiagonal(this: &this->inertiaTensor, epsilon: 0.001) != 0 )
    {
      this->inertiaTensor.mat[0].z = 0.0;
      this->inertiaTensor.mat[0].y = 0.0;
      this->inertiaTensor.mat[1].z = 0.0;
      this->inertiaTensor.mat[1].x = 0.0;
      this->inertiaTensor.mat[2].y = 0.0;
      this->inertiaTensor.mat[2].x = 0.0;
      this->inverseInertiaTensor.mat[2].z = 1.0;
      this->inverseInertiaTensor.mat[1].y = 1.0;
      this->inverseInertiaTensor.mat[0].x = 1.0;
      this->inverseInertiaTensor.mat[1].z = 0.0;
      this->inverseInertiaTensor.mat[0].z = 0.0;
      this->inverseInertiaTensor.mat[0].y = 0.0;
      this->inverseInertiaTensor.mat[2].y = 0.0;
      this->inverseInertiaTensor.mat[2].x = 0.0;
      this->inverseInertiaTensor.mat[1].x = 0.0;
      y = this->inertiaTensor.mat[1].y;
      v11 = (float)((float)1.0 / this->inertiaTensor.mat[2].z);
      this->inverseInertiaTensor.mat[0].x = (float)1.0 / p_inertiaTensor->mat[0].x;
      this->inverseInertiaTensor.mat[1].y = (float)1.0 / (float)y;
      this->inverseInertiaTensor.mat[2].z = v11;
    }
    else
    {
      this->inverseInertiaTensor = *idMat3::Inverse(this: &v12, result: &this->inertiaTensor);
    }
  }
}


// ========================================================================
// ?SetFrictionDirection@idAFBody@@QAAXABVidVec3@@@Z
// EA  : 0x8271A0F0
// RVA : 0x0071A0F0
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void __fastcall idAFBody::SetFrictionDirection(idAFBody *this, const idVec3 *dir)
{
  float *clipModel; // r11
  double z; // fp12
  double v4; // fp1
  double v5; // fp0
  double v6; // fp10
  double v7; // fp9

  clipModel = (float *)this->clipModel;
  z = dir->z;
  v4 = clipModel[16];
  v5 = clipModel[13];
  v6 = (float)((float)(dir->x * clipModel[14]) + (float)(dir->y * clipModel[15]));
  v7 = (float)((float)(dir->x * clipModel[11]) + (float)(dir->y * clipModel[12]));
  this->frictionDir.z = (float)(dir->z * clipModel[19])
                      + (float)((float)(dir->x * clipModel[17]) + (float)(dir->y * clipModel[18]));
  this->frictionDir.y = (float)((float)z * (float)v4) + (float)v6;
  this->frictionDir.x = (float)((float)z * (float)v5) + (float)v7;
  *(_BYTE *)&this->fl |= 0x10u;
}


// ========================================================================
// ?GetFrictionDirection@idAFBody@@QBA_NAAVidVec3@@@Z
// EA  : 0x8271A168
// RVA : 0x0071A168
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

int __fastcall idAFBody::GetFrictionDirection(idAFBody *this, idVec3 *dir)
{
  float *clipModel; // r11
  double z; // fp0
  double v5; // fp1
  double v6; // fp11
  double v7; // fp9
  double v8; // fp8

  if ( (*(_BYTE *)&this->fl & 0x10) == 0 )
    return 0;
  clipModel = (float *)this->clipModel;
  z = this->frictionDir.z;
  v5 = clipModel[18];
  v6 = clipModel[19];
  v7 = (float)((float)(clipModel[12] * this->frictionDir.x) + (float)(clipModel[15] * this->frictionDir.y));
  v8 = (float)((float)(clipModel[13] * this->frictionDir.x) + (float)(clipModel[16] * this->frictionDir.y));
  dir->x = (float)(clipModel[11] * this->frictionDir.x)
         + (float)((float)(clipModel[14] * this->frictionDir.y) + (float)(clipModel[17] * this->frictionDir.z));
  dir->y = (float)((float)v5 * (float)z) + (float)v7;
  dir->z = (float)((float)v6 * (float)z) + (float)v8;
  return 1;
}


// ========================================================================
// ?SetContactMotorDirection@idAFBody@@QAAXABVidVec3@@@Z
// EA  : 0x8271A1F0
// RVA : 0x0071A1F0
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void __fastcall idAFBody::SetContactMotorDirection(idAFBody *this, const idVec3 *dir)
{
  float *clipModel; // r11
  double z; // fp12
  double v4; // fp1
  double v5; // fp0
  double v6; // fp10
  double v7; // fp9

  clipModel = (float *)this->clipModel;
  z = dir->z;
  v4 = clipModel[16];
  v5 = clipModel[13];
  v6 = (float)((float)(dir->x * clipModel[14]) + (float)(dir->y * clipModel[15]));
  v7 = (float)((float)(dir->x * clipModel[11]) + (float)(dir->y * clipModel[12]));
  this->contactMotorDir.z = (float)(dir->z * clipModel[19])
                          + (float)((float)(dir->x * clipModel[17]) + (float)(dir->y * clipModel[18]));
  this->contactMotorDir.y = (float)((float)z * (float)v4) + (float)v6;
  this->contactMotorDir.x = (float)((float)z * (float)v5) + (float)v7;
  *(_BYTE *)&this->fl |= 8u;
}


// ========================================================================
// ?GetContactMotorDirection@idAFBody@@QBA_NAAVidVec3@@@Z
// EA  : 0x8271A268
// RVA : 0x0071A268
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

int __fastcall idAFBody::GetContactMotorDirection(idAFBody *this, idVec3 *dir)
{
  float *clipModel; // r11
  double z; // fp0
  double v5; // fp1
  double v6; // fp11
  double v7; // fp9
  double v8; // fp8

  if ( (*(_BYTE *)&this->fl & 8) == 0 )
    return 0;
  clipModel = (float *)this->clipModel;
  z = this->contactMotorDir.z;
  v5 = clipModel[18];
  v6 = clipModel[19];
  v7 = (float)((float)(clipModel[12] * this->contactMotorDir.x) + (float)(clipModel[15] * this->contactMotorDir.y));
  v8 = (float)((float)(clipModel[13] * this->contactMotorDir.x) + (float)(clipModel[16] * this->contactMotorDir.y));
  dir->x = (float)(clipModel[11] * this->contactMotorDir.x)
         + (float)((float)(clipModel[14] * this->contactMotorDir.y) + (float)(clipModel[17] * this->contactMotorDir.z));
  dir->y = (float)((float)v5 * (float)z) + (float)v7;
  dir->z = (float)((float)v6 * (float)z) + (float)v8;
  return 1;
}


// ========================================================================
// ?GetPointVelocity@idAFBody@@QBA?BVidVec3@@ABV2@@Z
// EA  : 0x8271A2F0
// RVA : 0x0071A2F0
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

idAFBody *__fastcall idAFBody::GetPointVelocity(idAFBody *this, const idVec3 *result, const idVec3 *point)
{
  float z; // r11
  double v4; // fp2
  double x; // fp1
  double v6; // fp6
  double v7; // fp5

  z = result[1].z;
  v4 = result[26].z;
  x = result[27].x;
  v6 = (float)((float)(result[28].x * (float)(point->z - *(float *)(LODWORD(z) + 40)))
             - (float)(result[28].y * (float)(point->y - *(float *)(LODWORD(z) + 36))));
  v7 = (float)((float)(result[28].y * (float)(point->x - *(float *)(LODWORD(z) + 32)))
             - (float)(result[27].z * (float)(point->z - *(float *)(LODWORD(z) + 40))));
  *((float *)&this->__vftable + 2) = result[27].y
                                   + (float)((float)(result[27].z * (float)(point->y - *(float *)(LODWORD(z) + 36)))
                                           - (float)(result[28].x * (float)(point->x - *(float *)(LODWORD(z) + 32))));
  *(float *)&this->__vftable = (float)v4 + (float)v6;
  *((float *)&this->__vftable + 1) = (float)x + (float)v7;
  return this;
}


// ========================================================================
// ?AddForce@idAFBody@@QAAXABVidVec3@@0@Z
// EA  : 0x8271A368
// RVA : 0x0071A368
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void __fastcall idAFBody::AddForce(idAFBody *this, const idVec3 *point, const idVec3 *force)
{
  idClipModel *clipModel; // r11
  double v4; // fp12
  double v5; // fp10
  double v6; // fp13
  double v7; // fp1

  clipModel = this->clipModel;
  this->current.externalForce.p[0] = this->current.externalForce.p[0] + force->x;
  this->current.externalForce.p[1] = force->y + this->current.externalForce.p[1];
  this->current.externalForce.p[2] = force->z + this->current.externalForce.p[2];
  v4 = this->current.externalForce.p[3];
  v5 = this->current.externalForce.p[4];
  v6 = (float)((float)(force->x * (float)(point->z - clipModel->origin.z))
             - (float)(force->z * (float)(point->x - clipModel->origin.x)));
  v7 = (float)((float)(force->z * (float)(point->y - clipModel->origin.y))
             - (float)(force->y * (float)(point->z - clipModel->origin.z)));
  this->current.externalForce.p[5] = (float)((float)(force->y * (float)(point->x - clipModel->origin.x))
                                           - (float)(force->x * (float)(point->y - clipModel->origin.y)))
                                   + this->current.externalForce.p[5];
  this->current.externalForce.p[4] = (float)v6 + (float)v5;
  this->current.externalForce.p[3] = (float)v4 + (float)v7;
}


// ========================================================================
// ?Serialize@idAFBody@@UAAXAAVidSerializer@@@Z
// EA  : 0x8271A588
// RVA : 0x0071A588
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void __fastcall idAFBody::Serialize(idAFBody *this, idSerializer *ser)
{
  AFBodyPState_t *p_current; // r28

  p_current = &this->current;
  idSerializer::Serialize(this: ser, value: &this->current.worldOrigin);
  idSerializer::Serialize(this: ser, value: this->current.worldAxis.mat);
  idSerializer::Serialize(this: ser, value: &this->current.worldAxis.mat[1]);
  idSerializer::Serialize(this: ser, value: &this->current.worldAxis.mat[2]);
  idSerializer::Serialize(this: ser, value: &this->current.spatialVelocity);
  if ( !ser->writing )
    idClipModel::SetLinkedPosition(
      this: this->clipModel,
      newOrigin: &p_current->worldOrigin,
      newAxis: &this->current.worldAxis);
  idClipModel::Serialize(this: this->clipModel, ser);
}


// ========================================================================
// ??1idAFBody@@UAA@XZ
// EA  : 0x8271A6B8
// RVA : 0x0071A6B8
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void __fastcall idAFBody::~idAFBody(idAFBody *this)
{
  idClipModel *clipModel; // r3
  float *p; // r4
  float *v4; // r4
  float *v5; // r4
  float *v6; // r4
  float *mat; // r4
  float *v8; // r4
  float *v9; // r4
  float *v10; // r4

  this->__vftable = (idAFBody_vtbl *)&idAFBody::`vftable';
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Delete(this: clipModel);
  p = this->acceleration.p;
  if ( p != nullptr && this->acceleration.allocated > 0 )
    idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
  v4 = this->auxForce.p;
  if ( v4 != nullptr && this->auxForce.allocated > 0 )
    idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
  v5 = this->totalForce.p;
  if ( v5 != nullptr && this->totalForce.allocated > 0 )
    idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
  v6 = this->s.p;
  if ( v6 != nullptr && this->s.allocated > 0 )
    idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
  mat = this->J.mat;
  if ( mat != nullptr && this->J.allocatedRows > 0 )
    idMem::Free(this: &mem, ptr: mat, align: ALIGN_16);
  v8 = this->invI.mat;
  if ( v8 != nullptr && this->invI.allocatedRows > 0 )
    idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
  v9 = this->I.mat;
  if ( v9 != nullptr && this->I.allocatedRows > 0 )
    idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
  v10 = this->inverseWorldSpatialInertia.mat;
  if ( v10 != nullptr && this->inverseWorldSpatialInertia.allocatedRows > 0 )
    idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->children);
}


// ========================================================================
// __unwind$248055_0
// EA  : 0x8271A83C
// RVA : 0x0071A83C
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248055_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 180));
}


// ========================================================================
// __unwind$248056_0
// EA  : 0x8271A868
// RVA : 0x0071A868
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248056_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 200));
}


// ========================================================================
// __unwind$248057
// EA  : 0x8271A894
// RVA : 0x0071A894
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248057()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 112 + 132) + 520));
}


// ========================================================================
// __unwind$248058
// EA  : 0x8271A8C0
// RVA : 0x0071A8C0
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248058()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 112 + 132) + 536));
}


// ========================================================================
// __unwind$248059
// EA  : 0x8271A8EC
// RVA : 0x0071A8EC
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248059()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 112 + 132) + 552));
}


// ========================================================================
// __unwind$248060
// EA  : 0x8271A918
// RVA : 0x0071A918
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248060()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 112 + 132) + 568));
}


// ========================================================================
// __unwind$248061
// EA  : 0x8271A944
// RVA : 0x0071A944
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248061()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 112 + 132) + 592));
}


// ========================================================================
// __unwind$248062
// EA  : 0x8271A970
// RVA : 0x0071A970
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248062()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 112 + 132) + 640));
}


// ========================================================================
// __unwind$248063
// EA  : 0x8271A99C
// RVA : 0x0071A99C
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248063()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 112 + 132) + 688));
}


// ========================================================================
// __unwind$248064
// EA  : 0x8271A9C8
// RVA : 0x0071A9C8
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248064()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 112 + 132) + 736));
}


// ========================================================================
// ?Init@idAFBody@@QAAXXZ
// EA  : 0x8271A9F8
// RVA : 0x0071A9F8
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void __fastcall idAFBody::Init(idAFBody *this)
{
  float *p_z; // r8
  float *p_t; // r9
  int v5; // ctr
  float *v6; // r10
  float *v7; // r11
  int i; // ctr

  _R12 = -64;
  __asm { stvx128   v127, r1, r12 }
  idAtomicString::Set(this: &this->name, str_: "noname");
  this->clipModel = nullptr;
  this->clipMask = 0;
  this->linearFrictionWater = -1.0;
  this->angularFrictionWater = -1.0;
  this->linearFriction = -1.0;
  this->angularFriction = -1.0;
  this->contactFriction = -1.0;
  this->bouncyness = -1.0;
  this->frictionDir = vec3_origin;
  this->contactMotorDir = vec3_origin;
  this->contactMotorVelocity = 0.0;
  this->contactMotorForce = 0.0;
  this->mass = 1.0;
  this->invMass = 1.0;
  this->centerOfMass = vec3_origin;
  this->inertiaTensor = mat3_identity;
  this->inverseInertiaTensor = mat3_identity;
  p_z = &this->current.atRestAxis.mat[2].z;
  p_t = &vec5_origin.t;
  v5 = 6;
  this->parent = nullptr;
  this->primaryConstraint = nullptr;
  this->tree = nullptr;
  this->fl = (idAFBody::afBodyFlags_t)68;
  this->current.worldOrigin = vec3_origin;
  this->current.worldAxis = mat3_identity;
  this->current.atRestOrigin = vec3_origin;
  this->current.atRestAxis = mat3_identity;
  do
  {
    *++p_z = *++p_t;
    --v5;
  }
  while ( v5 != 0 );
  v6 = &this->current.spatialVelocity.p[5];
  v7 = &vec5_origin.t;
  for ( i = 6; i != 0; --i )
    *++v6 = *++v7;
  AFBodyPState_t::operator=(this: &this->saved, __that: &this->current);
  idSpatialVec::SetSize(this: &this->s, newSize: 6);
  __asm { vspltisw128 v127, 0 }
  _R11 = this->s.p;
  _R29 = 16;
  __asm { stvx128   v127, r0, r11 }
  _R10 = _R11;
  __asm { stvx128   v127, r10, r29 }
  idSpatialVec::SetSize(this: &this->totalForce, newSize: 6);
  _R9 = this->totalForce.p;
  __asm { stvx128   v127, r0, r9 }
  _R8 = _R9;
  __asm { stvx128   v127, r8, r29 }
  idSpatialVec::SetSize(this: &this->auxForce, newSize: 6);
  _R7 = this->auxForce.p;
  __asm { stvx128   v127, r0, r7 }
  _R6 = _R7;
  __asm { stvx128   v127, r6, r29 }
  idSpatialVec::SetSize(this: &this->acceleration, newSize: 6);
  _R5 = this->acceleration.p;
  __asm { stvx128   v127, r0, r5 }
  _R4 = _R5;
  __asm { stvx128   v127, r4, r29 }
  this->response = nullptr;
  this->responseIndex = nullptr;
  this->numResponses = 0;
  this->maxAuxiliaryIndex = 0;
  this->maxSubTreeAuxiliaryIndex = 0;
  _R0 = -64;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// ??0idAFBody@@QAA@XZ
// EA  : 0x8271AD28
// RVA : 0x0071AD28
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

idAFBody *__fastcall idAFBody::idAFBody(idAFBody *this)
{
  this->__vftable = (idAFBody_vtbl *)&idAFBody::`vftable';
  this->name.str = &byte_8200D768;
  this->children.list = nullptr;
  this->children.granularity = 0;
  this->children.memTag = 71;
  this->children.listStatic = 0;
  this->children.size = 0;
  this->children.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->children);
  this->constraints.list = nullptr;
  this->constraints.granularity = 0;
  this->constraints.memTag = 71;
  this->constraints.listStatic = 0;
  this->constraints.size = 0;
  this->constraints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constraints);
  this->motionQuery.index = 0x4700000000LL;
  this->inverseWorldSpatialInertia.allocatedRows = 0;
  this->inverseWorldSpatialInertia.numColumns = 0;
  this->inverseWorldSpatialInertia.numRows = 0;
  this->inverseWorldSpatialInertia.mat = nullptr;
  this->I.allocatedRows = 0;
  this->I.numColumns = 0;
  this->I.numRows = 0;
  this->I.mat = nullptr;
  this->invI.allocatedRows = 0;
  this->invI.numColumns = 0;
  this->invI.numRows = 0;
  this->invI.mat = nullptr;
  this->J.allocatedRows = 0;
  this->J.numColumns = 0;
  this->J.numRows = 0;
  this->J.mat = nullptr;
  this->s.allocated = 0;
  this->s.size = 0;
  this->s.p = nullptr;
  idSpatialVec::SetData(this: &this->s, length: 0, data: this->s.data);
  this->totalForce.allocated = 0;
  this->totalForce.size = 0;
  this->totalForce.p = nullptr;
  idSpatialVec::SetData(this: &this->totalForce, length: 0, data: this->totalForce.data);
  this->auxForce.allocated = 0;
  this->auxForce.size = 0;
  this->auxForce.p = nullptr;
  idSpatialVec::SetData(this: &this->auxForce, length: 0, data: this->auxForce.data);
  this->acceleration.allocated = 0;
  this->acceleration.size = 0;
  this->acceleration.p = nullptr;
  idSpatialVec::SetData(this: &this->acceleration, length: 0, data: this->acceleration.data);
  idAFBody::Init(this);
  return this;
}


// ========================================================================
// __unwind$248436
// EA  : 0x8271AE98
// RVA : 0x0071AE98
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248436()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 180));
}


// ========================================================================
// __unwind$248437_0
// EA  : 0x8271AEC4
// RVA : 0x0071AEC4
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248437_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 200));
}


// ========================================================================
// __unwind$248438_0
// EA  : 0x8271AEF0
// RVA : 0x0071AEF0
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248438_0()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 128 + 148) + 520));
}


// ========================================================================
// __unwind$248439_0
// EA  : 0x8271AF1C
// RVA : 0x0071AF1C
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248439_0()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 128 + 148) + 536));
}


// ========================================================================
// __unwind$248440_0
// EA  : 0x8271AF48
// RVA : 0x0071AF48
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248440_0()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 128 + 148) + 552));
}


// ========================================================================
// __unwind$248441
// EA  : 0x8271AF74
// RVA : 0x0071AF74
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248441()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 128 + 148) + 568));
}


// ========================================================================
// __unwind$248442
// EA  : 0x8271AFA0
// RVA : 0x0071AFA0
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248442()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 128 + 148) + 592));
}


// ========================================================================
// __unwind$248443
// EA  : 0x8271AFCC
// RVA : 0x0071AFCC
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248443()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 128 + 148) + 640));
}


// ========================================================================
// __unwind$248444
// EA  : 0x8271AFF8
// RVA : 0x0071AFF8
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248444()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 128 + 148) + 688));
}


// ========================================================================
// __unwind$248445
// EA  : 0x8271B024
// RVA : 0x0071B024
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248445()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 128 + 148) + 736));
}


// ========================================================================
// ??0idAFBody@@QAA@PBDPAVidClipModel@@M@Z
// EA  : 0x8271B0B8
// RVA : 0x0071B0B8
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

idAFBody *__fastcall idAFBody::idAFBody(idAFBody *this, const char *name, idClipModel *clipModel, double density)
{
  unsigned __int64 v6; // r29
  idMat3 *v9; // r4

  LODWORD(v6) = 0;
  this->__vftable = (idAFBody_vtbl *)&idAFBody::`vftable';
  HIDWORD(v6) = &this->name;
  this->name.str = &byte_8200D768;
  this->children.list = nullptr;
  this->children.granularity = 0;
  this->children.memTag = 71;
  this->children.listStatic = 0;
  this->children.size = 0;
  this->children.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->children);
  this->constraints.list = nullptr;
  this->constraints.granularity = 0;
  this->constraints.memTag = 71;
  this->constraints.listStatic = 0;
  this->constraints.size = 0;
  this->constraints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constraints);
  this->motionQuery.index = v6;
  this->inverseWorldSpatialInertia.allocatedRows = 0;
  this->inverseWorldSpatialInertia.numColumns = 0;
  this->inverseWorldSpatialInertia.numRows = 0;
  this->inverseWorldSpatialInertia.mat = nullptr;
  this->I.allocatedRows = 0;
  this->I.numColumns = 0;
  this->I.numRows = 0;
  this->I.mat = nullptr;
  this->invI.allocatedRows = 0;
  this->invI.numColumns = 0;
  this->invI.numRows = 0;
  this->invI.mat = nullptr;
  this->J.allocatedRows = 0;
  this->J.numColumns = 0;
  this->J.numRows = 0;
  this->J.mat = nullptr;
  this->s.allocated = 0;
  this->s.size = 0;
  this->s.p = nullptr;
  idSpatialVec::SetData(this: &this->s, length: 0, data: this->s.data);
  this->totalForce.allocated = 0;
  this->totalForce.size = 0;
  this->totalForce.p = nullptr;
  idSpatialVec::SetData(this: &this->totalForce, length: 0, data: this->totalForce.data);
  this->auxForce.allocated = 0;
  this->auxForce.size = 0;
  this->auxForce.p = nullptr;
  idSpatialVec::SetData(this: &this->auxForce, length: 0, data: this->auxForce.data);
  this->acceleration.allocated = 0;
  this->acceleration.size = 0;
  this->acceleration.p = nullptr;
  idSpatialVec::SetData(this: &this->acceleration, length: 0, data: this->acceleration.data);
  idAFBody::Init(this);
  idAtomicString::Set(this: (idAtomicString *)HIDWORD(v6), str_: name);
  this->clipModel = clipModel;
  idAFBody::SetDensity(this, density, inertiaScale: v9, a4: &mat3_identity);
  return this;
}


// ========================================================================
// __unwind$248594
// EA  : 0x8271B264
// RVA : 0x0071B264
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248594()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 180));
}


// ========================================================================
// __unwind$248595
// EA  : 0x8271B290
// RVA : 0x0071B290
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248595()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 200));
}


// ========================================================================
// __unwind$248596_0
// EA  : 0x8271B2BC
// RVA : 0x0071B2BC
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248596_0()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 160 + 180) + 520));
}


// ========================================================================
// __unwind$248597_0
// EA  : 0x8271B2E8
// RVA : 0x0071B2E8
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248597_0()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 160 + 180) + 536));
}


// ========================================================================
// __unwind$248598
// EA  : 0x8271B314
// RVA : 0x0071B314
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248598()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 160 + 180) + 552));
}


// ========================================================================
// __unwind$248599
// EA  : 0x8271B340
// RVA : 0x0071B340
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248599()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 160 + 180) + 568));
}


// ========================================================================
// __unwind$248600
// EA  : 0x8271B36C
// RVA : 0x0071B36C
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248600()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 160 + 180) + 592));
}


// ========================================================================
// __unwind$248601
// EA  : 0x8271B398
// RVA : 0x0071B398
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248601()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 160 + 180) + 640));
}


// ========================================================================
// __unwind$248602
// EA  : 0x8271B3C4
// RVA : 0x0071B3C4
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248602()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 160 + 180) + 688));
}


// ========================================================================
// __unwind$248603
// EA  : 0x8271B3F0
// RVA : 0x0071B3F0
// PDB : w:\tech5\engine\gamelib\physics\afbody.cpp
// ========================================================================

void _unwind_248603()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 160 + 180) + 736));
}

