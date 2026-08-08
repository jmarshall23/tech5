
// ========================================================================
// ?SetNoLimit@idAFConstraint_BallAndSocketJoint@@QAAXXZ
// EA  : 0x8271B420
// RVA : 0x0071B420
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_BallAndSocketJoint::SetNoLimit(idAFConstraint_BallAndSocketJoint *this)
{
  idAFConstraint_ConeLimit *coneLimit; // r3
  idAFConstraint_PyramidLimit *pyramidLimit; // r3

  coneLimit = this->coneLimit;
  if ( coneLimit != nullptr )
  {
    ((void (__fastcall *)(idAFConstraint_ConeLimit *, int))coneLimit->dtr_idAFConstraint)(a1: coneLimit, a2: 1);
    this->coneLimit = nullptr;
  }
  pyramidLimit = this->pyramidLimit;
  if ( pyramidLimit != nullptr )
  {
    ((void (__fastcall *)(idAFConstraint_PyramidLimit *, int))pyramidLimit->dtr_idAFConstraint)(a1: pyramidLimit, a2: 1);
    this->pyramidLimit = nullptr;
  }
}


// ========================================================================
// ?SetNoLimit@idAFConstraint_UniversalJoint@@QAAXXZ
// EA  : 0x8271B4A0
// RVA : 0x0071B4A0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_UniversalJoint::SetNoLimit(idAFConstraint_UniversalJoint *this)
{
  idAFConstraint_ConeLimit *coneLimit; // r3
  idAFConstraint_PyramidLimit *pyramidLimit; // r3

  coneLimit = this->coneLimit;
  if ( coneLimit != nullptr )
  {
    ((void (__fastcall *)(idAFConstraint_ConeLimit *, int))coneLimit->dtr_idAFConstraint)(a1: coneLimit, a2: 1);
    this->coneLimit = nullptr;
  }
  pyramidLimit = this->pyramidLimit;
  if ( pyramidLimit != nullptr )
  {
    ((void (__fastcall *)(idAFConstraint_PyramidLimit *, int))pyramidLimit->dtr_idAFConstraint)(a1: pyramidLimit, a2: 1);
    this->pyramidLimit = nullptr;
  }
}


// ========================================================================
// ?SetNoLimit@idAFConstraint_Hinge@@QAAXXZ
// EA  : 0x8271B520
// RVA : 0x0071B520
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Hinge::SetNoLimit(idAFConstraint_Hinge *this)
{
  idAFConstraint_ConeLimit *coneLimit; // r3

  coneLimit = this->coneLimit;
  if ( coneLimit != nullptr )
  {
    ((void (__fastcall *)(idAFConstraint_ConeLimit *, int))coneLimit->dtr_idAFConstraint)(a1: coneLimit, a2: 1);
    this->coneLimit = nullptr;
  }
}


// ========================================================================
// ?SetSpring@idAFConstraint_Spring@@QAAXMMMM@Z
// EA  : 0x8271B570
// RVA : 0x0071B570
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Spring::SetSpring(
        idAFConstraint_Spring *this,
        double stretch,
        double compress,
        double damping,
        double restLength)
{
  this->kstretch = stretch;
  this->kcompress = compress;
  this->damping = damping;
  this->restLength = restLength;
}


// ========================================================================
// ?SetLimit@idAFConstraint_Spring@@QAAXMM@Z
// EA  : 0x8271B588
// RVA : 0x0071B588
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Spring::SetLimit(idAFConstraint_Spring *this, double minLength, double maxLength)
{
  this->minLength = minLength;
  this->maxLength = maxLength;
}


// ========================================================================
// ?SetSuspension@idAFConstraint_Suspension@@QAAXMMMM@Z
// EA  : 0x8271B598
// RVA : 0x0071B598
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Suspension::SetSuspension(
        idAFConstraint_Suspension *this,
        double up,
        double down,
        double compress,
        double damping)
{
  this->suspensionUp = up;
  this->suspensionDown = down;
  this->suspensionCompress = compress;
  this->suspensionDamping = damping;
}


// ========================================================================
// ?GetContactEntity@idAFConstraint_Suspension@@QBAHXZ
// EA  : 0x8271B5B0
// RVA : 0x0071B5B0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

int __fastcall idAFConstraint_Suspension::GetContactEntity(idAFConstraint_Suspension *this)
{
  if ( this->lastOnGround )
    return this->traceEntityNum;
  else
    return 0x1FFF;
}


// ========================================================================
// ??1idAFConstraint@@UAA@XZ
// EA  : 0x8271BAD8
// RVA : 0x0071BAD8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint::~idAFConstraint(idAFConstraint *this)
{
  float *mat; // r4
  float *v3; // r4
  float *p; // r4
  float *v5; // r4
  float *v6; // r4
  float *v7; // r4
  float *v8; // r4
  float *v9; // r4
  float *v10; // r4
  float *v11; // r4

  this->__vftable = (idAFConstraint_vtbl *)&idAFConstraint::`vftable';
  this->body1 = nullptr;
  this->body2 = nullptr;
  this->physics = nullptr;
  this->boxConstraint = nullptr;
  mat = this->J.mat;
  if ( mat != nullptr && this->J.allocatedRows > 0 )
    idMem::Free(this: &mem, ptr: mat, align: ALIGN_16);
  v3 = this->invI.mat;
  if ( v3 != nullptr && this->invI.allocatedRows > 0 )
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
  p = this->e.p;
  if ( p != nullptr && this->e.allocated > 0 )
    idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
  v5 = this->hi.p;
  if ( v5 != nullptr && this->hi.allocated > 0 )
    idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
  v6 = this->lo.p;
  if ( v6 != nullptr && this->lo.allocated > 0 )
    idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
  v7 = this->c2.p;
  if ( v7 != nullptr && this->c2.allocated > 0 )
    idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
  v8 = this->c1.p;
  if ( v8 != nullptr && this->c1.allocated > 0 )
    idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
  v9 = this->J2.mat;
  if ( v9 != nullptr && this->J2.allocatedRows > 0 )
    idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
  v10 = this->J1.mat;
  if ( v10 != nullptr && this->J1.allocatedRows > 0 )
    idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
  v11 = this->lm.p;
  if ( v11 != nullptr && this->lm.allocated > 0 )
    idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
}


// ========================================================================
// __unwind$251229
// EA  : 0x8271BCA0
// RVA : 0x0071BCA0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_251229()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// __unwind$251230
// EA  : 0x8271BCCC
// RVA : 0x0071BCCC
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_251230()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 112 + 132) + 96));
}


// ========================================================================
// __unwind$251231
// EA  : 0x8271BCF8
// RVA : 0x0071BCF8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_251231()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 112 + 132) + 112));
}


// ========================================================================
// __unwind$251232
// EA  : 0x8271BD24
// RVA : 0x0071BD24
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_251232()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 112 + 132) + 128));
}


// ========================================================================
// __unwind$251233
// EA  : 0x8271BD50
// RVA : 0x0071BD50
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_251233()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 112 + 132) + 176));
}


// ========================================================================
// __unwind$251234
// EA  : 0x8271BD7C
// RVA : 0x0071BD7C
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_251234()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 112 + 132) + 224));
}


// ========================================================================
// __unwind$251235
// EA  : 0x8271BDA8
// RVA : 0x0071BDA8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_251235()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 112 + 132) + 272));
}


// ========================================================================
// __unwind$251236
// EA  : 0x8271BDD4
// RVA : 0x0071BDD4
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_251236()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 112 + 132) + 320));
}


// ========================================================================
// __unwind$251237
// EA  : 0x8271BE00
// RVA : 0x0071BE00
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_251237()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 112 + 132) + 420));
}


// ========================================================================
// ?SetBody1@idAFConstraint@@UAAXPAVidAFBody@@@Z
// EA  : 0x8271BE30
// RVA : 0x0071BE30
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint::SetBody1(idAFConstraint *this, idAFBody *body)
{
  idPhysics_AF *physics; // r11

  if ( this->body1 != body )
  {
    physics = this->physics;
    this->body1 = body;
    if ( physics != nullptr )
      physics->changedAF = true;
  }
}


// ========================================================================
// ?SetBody2@idAFConstraint@@UAAXPAVidAFBody@@@Z
// EA  : 0x8271BE58
// RVA : 0x0071BE58
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint::SetBody2(idAFConstraint *this, idAFBody *body)
{
  idPhysics_AF *physics; // r11

  if ( this->body2 != body )
  {
    physics = this->physics;
    this->body2 = body;
    if ( physics != nullptr )
      physics->changedAF = true;
  }
}


// ========================================================================
// ?GetCenter@idAFConstraint@@UAAXAAVidVec3@@@Z
// EA  : 0x8271BE80
// RVA : 0x0071BE80
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint::GetCenter(idAFConstraint *this, idVec3 *center)
{
  center->z = 0.0;
  center->y = 0.0;
  center->x = 0.0;
}


// ========================================================================
// ?InitOffset@idAFConstraint_Fixed@@IAAXXZ
// EA  : 0x8271BE98
// RVA : 0x0071BE98
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Fixed::InitOffset(idAFConstraint_Fixed *this)
{
  idAFBody *body1; // r11
  idAFBody *body2; // r10
  float *clipModel; // r10
  float *v4; // r11
  double v5; // fp2
  double v6; // fp7
  double v7; // fp11
  double v8; // fp1
  double v9; // fp0
  float *v10; // r11
  idMat3 *p_axis; // r4
  double v12; // fp9
  double v13; // fp8
  double v14; // fp7
  double v15; // fp6
  double v16; // fp5
  double v17; // fp4
  double v18; // fp3
  double v19; // fp2
  idMat3 v20; // [sp+50h] [-70h] BYREF
  idMat3 v21; // [sp+80h] [-40h] BYREF

  body1 = this->body1;
  if ( body1 != nullptr )
  {
    body2 = this->body2;
    if ( body2 != nullptr )
    {
      clipModel = (float *)body2->clipModel;
      v4 = (float *)body1->clipModel;
      v5 = (float)(v4[8] - clipModel[8]);
      v6 = clipModel[14];
      v7 = clipModel[17];
      v8 = (float)((float)((float)(v4[9] - clipModel[9]) * clipModel[15])
                 + (float)((float)(v4[10] - clipModel[10]) * clipModel[16]));
      v9 = (float)((float)((float)(v4[9] - clipModel[9]) * clipModel[18])
                 + (float)((float)(v4[10] - clipModel[10]) * clipModel[19]));
      this->offset.x = (float)((float)(v4[8] - clipModel[8]) * clipModel[11])
                     + (float)((float)((float)(v4[9] - clipModel[9]) * clipModel[12])
                             + (float)((float)(v4[10] - clipModel[10]) * clipModel[13]));
      this->offset.y = (float)((float)v5 * (float)v6) + (float)v8;
      this->offset.z = (float)((float)v5 * (float)v7) + (float)v9;
      v10 = (float *)this->body2->clipModel;
      p_axis = &this->body1->clipModel->axis;
      v12 = v10[18];
      v13 = v10[15];
      v14 = v10[12];
      v15 = v10[17];
      v16 = v10[14];
      v17 = v10[11];
      v18 = v10[19];
      v19 = v10[16];
      v20.mat[2].x = v10[13];
      v20.mat[2].y = v19;
      v20.mat[2].z = v18;
      v20.mat[1].z = v12;
      v20.mat[1].y = v13;
      v20.mat[1].x = v14;
      v20.mat[0].z = v15;
      v20.mat[0].y = v16;
      v20.mat[0].x = v17;
      this->relAxis = *idMat3::operator*(this: &v21, result: p_axis, a: &v20);
    }
    else
    {
      this->offset = this->body1->clipModel->origin;
      this->relAxis = this->body1->clipModel->axis;
    }
  }
}


// ========================================================================
// ?SetBody1@idAFConstraint_Fixed@@UAAXPAVidAFBody@@@Z
// EA  : 0x8271C088
// RVA : 0x0071C088
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Fixed::SetBody1(idAFConstraint_Fixed *this, idAFBody *body)
{
  idPhysics_AF *physics; // r11

  if ( this->body1 != body )
  {
    this->body1 = body;
    idAFConstraint_Fixed::InitOffset(this);
    physics = this->physics;
    if ( physics != nullptr )
      physics->changedAF = true;
  }
}


// ========================================================================
// ?SetBody2@idAFConstraint_Fixed@@UAAXPAVidAFBody@@@Z
// EA  : 0x8271C0D8
// RVA : 0x0071C0D8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Fixed::SetBody2(idAFConstraint_Fixed *this, idAFBody *body)
{
  idPhysics_AF *physics; // r11

  if ( this->body2 != body )
  {
    this->body2 = body;
    idAFConstraint_Fixed::InitOffset(this);
    physics = this->physics;
    if ( physics != nullptr )
      physics->changedAF = true;
  }
}


// ========================================================================
// ?Rotate@idAFConstraint_Fixed@@UAAXABVidRotation@@@Z
// EA  : 0x8271C128
// RVA : 0x0071C128
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Fixed::Rotate(idAFConstraint_Fixed *this, idRotation *rotation)
{
  const idMat3 *v4; // r3
  char v5; // [sp+50h] [-30h] BYREF

  if ( this->body2 == nullptr )
  {
    this->offset = idRotation::operator*(this: (idRotation *)&v5, result: rotation, v: &this->offset)->origin;
    v4 = idRotation::ToMat3(this: rotation);
    idMat3::operator*=(this: &this->relAxis, a: v4);
  }
}


// ========================================================================
// ?GetCenter@idAFConstraint_Fixed@@UAAXAAVidVec3@@@Z
// EA  : 0x8271C1A8
// RVA : 0x0071C1A8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Fixed::GetCenter(idAFConstraint_Fixed *this, idVec3 *center)
{
  idAFBody *body1; // r11

  body1 = this->body1;
  if ( body1 != nullptr )
  {
    *center = body1->clipModel->origin;
  }
  else
  {
    center->z = 0.0;
    center->y = 0.0;
    center->x = 0.0;
  }
}


// ========================================================================
// ?DebugDraw@idAFConstraint_Fixed@@UAAXXZ
// EA  : 0x8271C1F0
// RVA : 0x0071C1F0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Fixed::DebugDraw(idAFConstraint_Fixed *this)
{
  idAFBody *body2; // r31
  idPhysics_AF *physics; // r11
  idRenderWorld *v4; // r3
  idVec3 *p_origin; // r6
  idClipModel *clipModel; // r11

  if ( this->body1 != nullptr )
  {
    body2 = this->body2;
    if ( body2 != nullptr || (physics = this->physics) != nullptr && (body2 = physics->masterBody) != nullptr )
    {
      v4 = common->RW(this: common);
      p_origin = &body2->clipModel->origin;
      clipModel = this->body1->clipModel;
    }
    else
    {
      v4 = common->RW(this: common);
      p_origin = &vec3_origin;
      clipModel = this->body1->clipModel;
    }
    v4->DebugLine(
      this: v4,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: &clipModel->origin,
      a4: p_origin,
      a5: 0,
      a6: false);
  }
}


// ========================================================================
// ??1idAFConstraint_BallAndSocketJoint@@UAA@XZ
// EA  : 0x8271C2D8
// RVA : 0x0071C2D8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_BallAndSocketJoint::~idAFConstraint_BallAndSocketJoint(
        idAFConstraint_BallAndSocketJoint *this)
{
  idAFConstraint_ConeLimit *coneLimit; // r3
  idAFConstraint_PyramidLimit *pyramidLimit; // r3
  idAFConstraint_BallAndSocketJointFriction *fc; // r3

  this->__vftable = (idAFConstraint_BallAndSocketJoint_vtbl *)&idAFConstraint_BallAndSocketJoint::`vftable';
  coneLimit = this->coneLimit;
  if ( coneLimit != nullptr )
    ((void (__fastcall *)(idAFConstraint_ConeLimit *, int))coneLimit->dtr_idAFConstraint)(a1: coneLimit, a2: 1);
  pyramidLimit = this->pyramidLimit;
  if ( pyramidLimit != nullptr )
    ((void (__fastcall *)(idAFConstraint_PyramidLimit *, int))pyramidLimit->dtr_idAFConstraint)(a1: pyramidLimit, a2: 1);
  fc = this->fc;
  if ( fc != nullptr )
    ((void (__fastcall *)(idAFConstraint_BallAndSocketJointFriction *, int))fc->dtr_idAFConstraint)(a1: fc, a2: 1);
  idAFConstraint::~idAFConstraint(this);
}


// ========================================================================
// __unwind$252029
// EA  : 0x8271C390
// RVA : 0x0071C390
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_252029()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 112 + 132));
}


// ========================================================================
// ?SetWorldPosition@idAFConstraint_BallAndSocketJoint@@QAAXABVidVec3@@@Z
// EA  : 0x8271C3B8
// RVA : 0x0071C3B8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_BallAndSocketJoint::SetWorldPosition(
        idAFConstraint_BallAndSocketJoint *this,
        const idVec3 *worldPosition)
{
  this->anchor2 = *worldPosition;
}


// ========================================================================
// ?GetFriction@idAFConstraint_BallAndSocketJoint@@QBAMXZ
// EA  : 0x8271C3D8
// RVA : 0x0071C3D8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

float __fastcall idAFConstraint_BallAndSocketJoint::GetFriction(idAFConstraint_BallAndSocketJoint *this)
{
  idPhysics_AF *physics; // r3
  double valueFloat; // fp1

  physics = this->physics;
  if ( physics != nullptr )
  {
    valueFloat = af_forceFriction.valueFloat;
    if ( af_forceFriction.valueFloat <= 0.0 )
      valueFloat = (float)(idPhysics_AF::GetJointFrictionScale(this: physics) * this->friction);
  }
  else
  {
    valueFloat = 0.0;
  }
  return *((float *)&valueFloat + 1);
}


// ========================================================================
// ?Translate@idAFConstraint_BallAndSocketJoint@@UAAXABVidVec3@@@Z
// EA  : 0x8271C450
// RVA : 0x0071C450
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_BallAndSocketJoint::Translate(
        idAFConstraint_BallAndSocketJoint *this,
        const idVec3 *translation)
{
  double y; // fp11
  double z; // fp8
  void *coneLimit; // r11

  if ( this->body2 == nullptr )
  {
    y = this->anchor2.y;
    this->anchor2.x = this->anchor2.x + translation->x;
    z = this->anchor2.z;
    this->anchor2.y = translation->y + (float)y;
    this->anchor2.z = translation->z + (float)z;
  }
  coneLimit = this->coneLimit;
  if ( coneLimit != nullptr || (coneLimit = this->pyramidLimit) != nullptr )
    (*(void (**)(void))(*(_DWORD *)coneLimit + 16))();
}


// ========================================================================
// ?Rotate@idAFConstraint_BallAndSocketJoint@@UAAXABVidRotation@@@Z
// EA  : 0x8271C4D8
// RVA : 0x0071C4D8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_BallAndSocketJoint::Rotate(
        idAFConstraint_BallAndSocketJoint *this,
        idRotation *rotation)
{
  void *coneLimit; // r3
  char v5; // [sp+50h] [-30h] BYREF

  if ( this->body2 == nullptr )
    this->anchor2 = idRotation::operator*(this: (idRotation *)&v5, result: rotation, v: &this->anchor2)->origin;
  if ( this->coneLimit != nullptr )
  {
    coneLimit = this->coneLimit;
  }
  else
  {
    if ( this->pyramidLimit == nullptr )
      return;
    coneLimit = this->pyramidLimit;
  }
  (*(void (__fastcall **)(void *, idRotation *))(*(_DWORD *)coneLimit + 20))(a1: coneLimit, a2: rotation);
}


// ========================================================================
// ?GetCenter@idAFConstraint_UniversalJoint@@UAAXAAVidVec3@@@Z
// EA  : 0x8271C578
// RVA : 0x0071C578
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_UniversalJoint::GetCenter(idAFConstraint_Hinge *this, idVec3 *center)
{
  float *clipModel; // r10
  double v3; // fp8
  double v4; // fp13
  double v5; // fp5
  double v6; // fp4

  if ( this->body1 != nullptr )
  {
    clipModel = (float *)this->body1->clipModel;
    v3 = clipModel[9];
    v4 = clipModel[10];
    v5 = (float)((float)(clipModel[18] * this->anchor1.z)
               + (float)((float)(clipModel[12] * this->anchor1.x) + (float)(clipModel[15] * this->anchor1.y)));
    v6 = (float)((float)(clipModel[19] * this->anchor1.z)
               + (float)((float)(clipModel[13] * this->anchor1.x) + (float)(clipModel[16] * this->anchor1.y)));
    center->x = clipModel[8]
              + (float)((float)(clipModel[11] * this->anchor1.x)
                      + (float)((float)(clipModel[14] * this->anchor1.y) + (float)(clipModel[17] * this->anchor1.z)));
    center->y = (float)v3 + (float)v5;
    center->z = (float)v4 + (float)v6;
  }
  else
  {
    center->z = 0.0;
    center->y = 0.0;
    center->x = 0.0;
  }
}


// ========================================================================
// ?DebugDraw@idAFConstraint_BallAndSocketJoint@@UAAXXZ
// EA  : 0x8271C620
// RVA : 0x0071C620
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_BallAndSocketJoint::DebugDraw(idAFConstraint_BallAndSocketJoint *this)
{
  idAFBody *body1; // r11
  float *clipModel; // r10
  double v4; // fp30
  double v5; // fp29
  double v6; // fp28
  int v7; // r3
  idRenderWorld *v8; // r3
  idRenderWorld *v9; // r3
  idAFConstraint_ConeLimit *coneLimit; // r11
  idAFConstraint_PyramidLimit *pyramidLimit; // r11
  float v12[4]; // [sp+50h] [-A0h] BYREF
  float v13[4]; // [sp+60h] [-90h] BYREF
  float v14[4]; // [sp+70h] [-80h] BYREF
  float v15[4]; // [sp+80h] [-70h] BYREF
  float v16[4]; // [sp+90h] [-60h] BYREF
  float v17[12]; // [sp+A0h] [-50h] BYREF

  body1 = this->body1;
  if ( body1 != nullptr )
  {
    clipModel = (float *)body1->clipModel;
    v4 = (float)(clipModel[8]
               + (float)((float)(this->anchor1.x * clipModel[11])
                       + (float)((float)(clipModel[14] * this->anchor1.y) + (float)(clipModel[17] * this->anchor1.z))));
    v5 = (float)(clipModel[9]
               + (float)((float)(clipModel[18] * this->anchor1.z)
                       + (float)((float)(clipModel[12] * this->anchor1.x) + (float)(clipModel[15] * this->anchor1.y))));
    v6 = (float)(clipModel[10]
               + (float)((float)(clipModel[19] * this->anchor1.z)
                       + (float)((float)(clipModel[13] * this->anchor1.x) + (float)(clipModel[16] * this->anchor1.y))));
    v7 = ((int (*)(void))common->RW)();
    v12[1] = v5;
    v12[2] = v6;
    v13[1] = v5;
    v13[2] = v6;
    v12[0] = (float)v4 + (float)5.0;
    v13[0] = (float)v4 - (float)5.0;
    (*(void (__fastcall **)(int, idColor *, float *, float *, _DWORD, _DWORD))(*(_DWORD *)v7 + 176))(
      a1: v7,
      a2: &idColor::colorBlue,
      a3: v13,
      a4: v12,
      a5: 0,
      a6: 0);
    v8 = common->RW(this: common);
    v14[0] = v4;
    v14[1] = (float)v5 + (float)5.0;
    v14[2] = v6;
    v15[0] = v4;
    v15[1] = (float)v5 - (float)5.0;
    v15[2] = v6;
    v8->DebugLine(
      this: v8,
      a2: (const idVec4 *)&idColor::colorBlue,
      a3: (const idVec3 *)v15,
      a4: (const idVec3 *)v14,
      a5: 0,
      a6: false);
    v9 = common->RW(this: common);
    v16[0] = v4;
    v16[1] = v5;
    v16[2] = (float)v6 + (float)5.0;
    v17[0] = v4;
    v17[1] = v5;
    v17[2] = (float)v6 - (float)5.0;
    v9->DebugLine(
      this: v9,
      a2: (const idVec4 *)&idColor::colorBlue,
      a3: (const idVec3 *)v17,
      a4: (const idVec3 *)v16,
      a5: 0,
      a6: false);
    if ( af_showLimits.valueInteger != 0 )
    {
      coneLimit = this->coneLimit;
      if ( coneLimit != nullptr )
        ((void (*)(void))coneLimit->DebugDraw)();
      pyramidLimit = this->pyramidLimit;
      if ( pyramidLimit != nullptr )
        ((void (*)(void))pyramidLimit->DebugDraw)();
    }
  }
}


// ========================================================================
// ?Add@idAFConstraint_BallAndSocketJointFriction@@QAA_NPAVidPhysics_AF@@M@Z
// EA  : 0x8271C838
// RVA : 0x0071C838
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

int __fastcall idAFConstraint_BallAndSocketJointFriction::Add(
        idAFConstraint_BallAndSocketJointFriction *this,
        idPhysics_AF *phys,
        double invTimeStep)
{
  idAFConstraint_BallAndSocketJoint *joint; // r3
  idSpatialVec *p_lm; // r30
  double Friction; // fp31
  double v8; // fp1
  double v9; // fp0

  joint = this->joint;
  this->physics = phys;
  if ( joint == nullptr )
    return 0;
  p_lm = &joint->lm;
  Friction = idAFConstraint_BallAndSocketJoint::GetFriction(this: joint);
  v8 = idSpatialVec::Length(this: p_lm);
  v9 = (float)((float)Friction * (float)v8);
  if ( v9 == 0.0 || this->physics == nullptr )
    return 0;
  this->lo.p[2] = -v9;
  this->lo.p[1] = -v9;
  *this->lo.p = -v9;
  this->hi.p[2] = (float)Friction * (float)v8;
  this->hi.p[1] = (float)Friction * (float)v8;
  *this->hi.p = (float)Friction * (float)v8;
  idSpatialMat::Zero(this: &this->J1, rows: 3, columns: 6);
  this->J1.mat[21] = 1.0;
  this->J1.mat[12] = 1.0;
  this->J1.mat[3] = 1.0;
  if ( this->body2 != nullptr )
  {
    idSpatialMat::Zero(this: &this->J2, rows: 3, columns: 6);
    this->J2.mat[21] = 1.0;
    this->J2.mat[12] = 1.0;
    this->J2.mat[3] = 1.0;
  }
  idPhysics_AF::AddFrameConstraint(this: this->physics, constraint: this);
  return 1;
}


// ========================================================================
// ??1idAFConstraint_UniversalJoint@@UAA@XZ
// EA  : 0x8271C970
// RVA : 0x0071C970
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_UniversalJoint::~idAFConstraint_UniversalJoint(idAFConstraint_UniversalJoint *this)
{
  idAFConstraint_ConeLimit *coneLimit; // r3
  idAFConstraint_PyramidLimit *pyramidLimit; // r3
  idAFConstraint_UniversalJointFriction *fc; // r3

  this->__vftable = (idAFConstraint_UniversalJoint_vtbl *)&idAFConstraint_UniversalJoint::`vftable';
  coneLimit = this->coneLimit;
  if ( coneLimit != nullptr )
    ((void (__fastcall *)(idAFConstraint_ConeLimit *, int))coneLimit->dtr_idAFConstraint)(a1: coneLimit, a2: 1);
  pyramidLimit = this->pyramidLimit;
  if ( pyramidLimit != nullptr )
    ((void (__fastcall *)(idAFConstraint_PyramidLimit *, int))pyramidLimit->dtr_idAFConstraint)(a1: pyramidLimit, a2: 1);
  fc = this->fc;
  if ( fc != nullptr )
    ((void (__fastcall *)(idAFConstraint_UniversalJointFriction *, int))fc->dtr_idAFConstraint)(a1: fc, a2: 1);
  idAFConstraint::~idAFConstraint(this);
}


// ========================================================================
// __unwind$252452
// EA  : 0x8271CA28
// RVA : 0x0071CA28
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_252452()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetFriction@idAFConstraint_UniversalJoint@@QBAMXZ
// EA  : 0x8271CA50
// RVA : 0x0071CA50
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

float __fastcall idAFConstraint_UniversalJoint::GetFriction(idAFConstraint_UniversalJoint *this)
{
  double valueFloat; // fp1
  idPhysics_AF *physics; // r3

  valueFloat = 0.0;
  if ( af_forceFriction.valueFloat <= 0.0 )
  {
    physics = this->physics;
    if ( physics != nullptr )
      valueFloat = (float)(idPhysics_AF::GetJointFrictionScale(this: physics) * this->friction);
  }
  else
  {
    valueFloat = af_forceFriction.valueFloat;
  }
  return *((float *)&valueFloat + 1);
}


// ========================================================================
// ?Translate@idAFConstraint_UniversalJoint@@UAAXABVidVec3@@@Z
// EA  : 0x8271CAC8
// RVA : 0x0071CAC8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_UniversalJoint::Translate(
        idAFConstraint_UniversalJoint *this,
        const idVec3 *translation)
{
  double y; // fp11
  double z; // fp8
  void *coneLimit; // r11

  if ( this->body2 == nullptr )
  {
    y = this->anchor2.y;
    this->anchor2.x = this->anchor2.x + translation->x;
    z = this->anchor2.z;
    this->anchor2.y = translation->y + (float)y;
    this->anchor2.z = translation->z + (float)z;
  }
  coneLimit = this->coneLimit;
  if ( coneLimit != nullptr || (coneLimit = this->pyramidLimit) != nullptr )
    (*(void (**)(void))(*(_DWORD *)coneLimit + 16))();
}


// ========================================================================
// ?Rotate@idAFConstraint_UniversalJoint@@UAAXABVidRotation@@@Z
// EA  : 0x8271CB50
// RVA : 0x0071CB50
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_UniversalJoint::Rotate(idAFConstraint_UniversalJoint *this, idRotation *rotation)
{
  float *v4; // r3
  double z; // fp11
  double v6; // fp12
  double v7; // fp8
  double v8; // fp6
  double v9; // fp5
  float *v10; // r3
  double v11; // fp1
  double v12; // fp2
  double v13; // fp12
  double v14; // fp10
  double v15; // fp9
  void *coneLimit; // r3
  char v17; // [sp+50h] [-30h] BYREF

  if ( this->body2 == nullptr )
  {
    this->anchor2 = idRotation::operator*(this: (idRotation *)&v17, result: rotation, v: &this->anchor2)->origin;
    v4 = (float *)idRotation::ToMat3(this: rotation);
    z = this->shaft2.z;
    v6 = v4[7];
    v7 = v4[8];
    v8 = (float)((float)(v4[1] * this->shaft2.x) + (float)(v4[4] * this->shaft2.y));
    v9 = (float)((float)(v4[2] * this->shaft2.x) + (float)(v4[5] * this->shaft2.y));
    this->shaft2.x = (float)(*v4 * this->shaft2.x)
                   + (float)((float)(v4[3] * this->shaft2.y) + (float)(v4[6] * this->shaft2.z));
    this->shaft2.y = (float)((float)v6 * (float)z) + (float)v8;
    this->shaft2.z = (float)((float)v7 * (float)z) + (float)v9;
    v10 = (float *)idRotation::ToMat3(this: rotation);
    v11 = this->axis2.z;
    v12 = v10[7];
    v13 = v10[8];
    v14 = (float)((float)(v10[1] * this->axis2.x) + (float)(v10[4] * this->axis2.y));
    v15 = (float)((float)(v10[2] * this->axis2.x) + (float)(v10[5] * this->axis2.y));
    this->axis2.x = (float)(this->axis2.x * *v10)
                  + (float)((float)(v10[3] * this->axis2.y) + (float)(v10[6] * this->axis2.z));
    this->axis2.y = (float)((float)v12 * (float)v11) + (float)v14;
    this->axis2.z = (float)((float)v13 * (float)v11) + (float)v15;
  }
  if ( this->coneLimit != nullptr )
  {
    coneLimit = this->coneLimit;
  }
  else
  {
    if ( this->pyramidLimit == nullptr )
      return;
    coneLimit = this->pyramidLimit;
  }
  (*(void (__fastcall **)(void *, idRotation *))(*(_DWORD *)coneLimit + 20))(a1: coneLimit, a2: rotation);
}


// ========================================================================
// ?DebugDraw@idAFConstraint_UniversalJoint@@UAAXXZ
// EA  : 0x8271CCD0
// RVA : 0x0071CCD0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_UniversalJoint::DebugDraw(idAFConstraint_UniversalJoint *this)
{
  idAFBody *body2; // r10
  idPhysics_AF *physics; // r11
  idAFBody *body1; // r11
  double z; // fp11
  double y; // fp10
  float *clipModel; // r9
  double v8; // fp9
  double v9; // fp8
  double x; // fp7
  double v11; // fp6
  double v12; // fp4
  double v13; // fp12
  double v14; // fp3
  float *p_axis; // r11
  double v16; // fp13
  double v17; // fp24
  double v18; // fp22
  double v19; // fp20
  double v20; // fp21
  double v21; // fp19
  double v22; // fp23
  float *v23; // r11
  double v24; // fp11
  double v25; // fp10
  double v26; // fp29
  double v27; // fp31
  double v28; // fp5
  double v29; // fp4
  double v30; // fp8
  double v31; // fp13
  double v32; // fp9
  float *v33; // r11
  double v34; // fp27
  double v35; // fp25
  double v36; // fp29
  double v37; // fp28
  double v38; // fp26
  double v39; // fp30
  double v40; // fp12
  double v41; // fp7
  double v42; // fp6
  double v43; // fp5
  double v46; // fp9
  double v47; // fp9
  float *v48; // r3
  double v49; // fp6
  double v50; // fp0
  idRenderWorld *v51; // r3
  idRenderWorld *v52; // r3
  idRenderWorld *v53; // r3
  idRenderWorld *v54; // r3
  idAFConstraint_ConeLimit *coneLimit; // r11
  idAFConstraint_PyramidLimit *pyramidLimit; // r11
  float v57; // [sp+50h] [-190h] BYREF
  float v58; // [sp+54h] [-18Ch]
  float v59; // [sp+58h] [-188h]
  float v60; // [sp+60h] [-180h] BYREF
  float v61; // [sp+64h] [-17Ch]
  float v62; // [sp+68h] [-178h]
  float v63[4]; // [sp+70h] [-170h] BYREF
  float v64[4]; // [sp+80h] [-160h] BYREF
  float v65[4]; // [sp+90h] [-150h] BYREF
  float v66[4]; // [sp+A0h] [-140h] BYREF
  idMat3 v67; // [sp+B0h] [-130h] BYREF
  idMat3 v68; // [sp+E0h] [-100h] BYREF
  idMat3 v69[4]; // [sp+110h] [-D0h] BYREF

  if ( this->body1 != nullptr )
  {
    body2 = this->body2;
    if ( body2 == nullptr )
    {
      physics = this->physics;
      if ( physics != nullptr )
        body2 = physics->masterBody;
    }
    body1 = this->body1;
    z = this->shaft1.z;
    y = this->shaft1.y;
    clipModel = (float *)body1->clipModel;
    v8 = this->axis1.y;
    v9 = this->axis1.z;
    x = this->shaft1.x;
    v11 = this->axis1.x;
    v12 = clipModel[10];
    v13 = (float)((float)(clipModel[19] * this->anchor1.z)
                + (float)((float)(clipModel[13] * this->anchor1.x) + (float)(clipModel[16] * this->anchor1.y)));
    v14 = (float)(clipModel[9]
                + (float)((float)(clipModel[18] * this->anchor1.z)
                        + (float)((float)(clipModel[12] * this->anchor1.x) + (float)(clipModel[15] * this->anchor1.y))));
    v60 = clipModel[8]
        + (float)((float)(clipModel[11] * this->anchor1.x)
                + (float)((float)(clipModel[14] * this->anchor1.y) + (float)(clipModel[17] * this->anchor1.z)));
    v61 = v14;
    v62 = (float)v12 + (float)v13;
    p_axis = (float *)&body1->clipModel->axis;
    v16 = this->anchor2.y;
    v17 = (float)((float)(*p_axis * (float)x) + (float)((float)(p_axis[3] * (float)y) + (float)(p_axis[6] * (float)z)));
    v18 = (float)((float)(p_axis[8] * (float)z) + (float)((float)(p_axis[2] * (float)x) + (float)(p_axis[5] * (float)y)));
    v19 = (float)((float)(p_axis[7] * (float)v9)
                + (float)((float)(p_axis[1] * (float)v11) + (float)(p_axis[4] * (float)v8)));
    v20 = (float)((float)((float)v11 * *p_axis)
                + (float)((float)(p_axis[3] * (float)v8) + (float)(p_axis[6] * (float)v9)));
    v21 = (float)((float)(p_axis[8] * (float)v9)
                + (float)((float)(p_axis[2] * (float)v11) + (float)(p_axis[5] * (float)v8)));
    v22 = (float)((float)(p_axis[7] * (float)z) + (float)((float)(p_axis[1] * (float)x) + (float)(p_axis[4] * (float)y)));
    if ( body2 != nullptr )
    {
      v23 = (float *)body2->clipModel;
      v24 = this->shaft2.z;
      v25 = this->shaft2.y;
      v26 = this->shaft2.x;
      v27 = v23[10];
      v28 = this->axis2.y;
      v29 = this->axis2.z;
      v30 = this->axis2.x;
      v32 = (float)((float)((float)(this->anchor2.x * v23[11])
                          + (float)((float)(v23[14] * this->anchor2.y) + (float)(v23[17] * this->anchor2.z)))
                  + v23[8]);
      v31 = (float)((float)(v23[19] * this->anchor2.z)
                  + (float)((float)(v23[13] * this->anchor2.x) + (float)(v23[16] * this->anchor2.y)));
      v58 = v23[9]
          + (float)((float)(v23[18] * this->anchor2.z)
                  + (float)((float)(v23[12] * this->anchor2.x) + (float)(v23[15] * this->anchor2.y)));
      v57 = v32;
      v59 = (float)v27 + (float)v31;
      v33 = (float *)&body2->clipModel->axis;
      v34 = (float)((float)(*v33 * (float)v26)
                  + (float)((float)(body2->clipModel->axis.mat[1].x * (float)v25)
                          + (float)(body2->clipModel->axis.mat[2].x * (float)v24)));
      v35 = (float)((float)(body2->clipModel->axis.mat[2].z * (float)v24)
                  + (float)((float)(body2->clipModel->axis.mat[0].z * (float)v26)
                          + (float)(body2->clipModel->axis.mat[1].z * (float)v25)));
      v37 = (float)((float)(body2->clipModel->axis.mat[2].y * (float)v29)
                  + (float)((float)(body2->clipModel->axis.mat[0].y * (float)v30)
                          + (float)(body2->clipModel->axis.mat[1].y * (float)v28)));
      v38 = (float)((float)(body2->clipModel->axis.mat[2].y * (float)v24)
                  + (float)((float)(body2->clipModel->axis.mat[0].y * (float)v26)
                          + (float)(body2->clipModel->axis.mat[1].y * (float)v25)));
      v36 = (float)((float)(*v33 * (float)v30)
                  + (float)((float)(body2->clipModel->axis.mat[1].x * (float)v28)
                          + (float)(body2->clipModel->axis.mat[2].x * (float)v29)));
      v39 = (float)((float)(body2->clipModel->axis.mat[2].z * (float)v29)
                  + (float)((float)(body2->clipModel->axis.mat[0].z * (float)v30)
                          + (float)(body2->clipModel->axis.mat[1].z * (float)v28)));
    }
    else
    {
      v40 = this->anchor2.z;
      v34 = this->shaft2.x;
      v38 = this->shaft2.y;
      v35 = this->shaft2.z;
      v36 = this->axis2.x;
      v37 = this->axis2.y;
      v39 = this->axis2.z;
      v57 = this->anchor2.x;
      v58 = v16;
      v59 = v40;
    }
    v41 = (float)((float)((float)v18 * (float)v34) - (float)((float)v35 * (float)v17));
    v42 = (float)((float)((float)v38 * (float)v17) - (float)((float)v22 * (float)v34));
    v43 = (float)((float)((float)v35 * (float)v22) - (float)((float)v38 * (float)v18));
    _FP1 = (float)((float)((float)((float)v43 * (float)v43)
                         + (float)((float)((float)v42 * (float)v42) + (float)((float)v41 * (float)v41)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f10, f1, f2, f13 }
    v46 = __frsqrte(_FP10);
    v47 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v46
                                                                                        * (float)((float)((float)((float)v43 * (float)v43) + (float)((float)((float)v42 * (float)v42) + (float)((float)v41 * (float)v41)))
                                                                                                * (float)0.5))
                                                                                * (float)v46)
                                                                        - (float)1.5)
                                                        * (float)v46)
                                                * (float)((float)((float)((float)v43 * (float)v43)
                                                                + (float)((float)((float)v42 * (float)v42)
                                                                        + (float)((float)v41 * (float)v41)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v46
                                                                                * (float)((float)((float)((float)v43 * (float)v43)
                                                                                                + (float)((float)((float)v42 * (float)v42) + (float)((float)v41 * (float)v41)))
                                                                                        * (float)0.5))
                                                                        * (float)v46)
                                                                - (float)1.5)
                                                * (float)v46))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v46
                                                        * (float)((float)((float)((float)v43 * (float)v43)
                                                                        + (float)((float)((float)v42 * (float)v42)
                                                                                + (float)((float)v41 * (float)v41)))
                                                                * (float)0.5))
                                                * (float)v46)
                                        - (float)1.5)
                        * (float)v46));
    if ( (float)((float)((float)-(float)((float)((float)((float)v47
                                                       * (float)((float)((float)((float)v43 * (float)v43)
                                                                       + (float)((float)((float)v42 * (float)v42)
                                                                               + (float)((float)v41 * (float)v41)))
                                                               * (float)0.5))
                                               * (float)v47)
                                       - (float)1.5)
                       * (float)v47)
               * (float)((float)((float)v43 * (float)v43)
                       + (float)((float)((float)v42 * (float)v42) + (float)((float)v41 * (float)v41)))) != 0.0 )
    {
      v67.mat[0].x = v17;
      v67.mat[0].y = v22;
      v67.mat[0].z = v18;
      v67.mat[1].x = (float)v43
                   * (float)((float)-(float)((float)((float)((float)v47
                                                           * (float)((float)((float)((float)v43 * (float)v43)
                                                                           + (float)((float)((float)v42 * (float)v42)
                                                                                   + (float)((float)v41 * (float)v41)))
                                                                   * (float)0.5))
                                                   * (float)v47)
                                           - (float)1.5)
                           * (float)v47);
      v67.mat[1].y = (float)v41
                   * (float)((float)-(float)((float)((float)((float)v47
                                                           * (float)((float)((float)((float)v43 * (float)v43)
                                                                           + (float)((float)((float)v42 * (float)v42)
                                                                                   + (float)((float)v41 * (float)v41)))
                                                                   * (float)0.5))
                                                   * (float)v47)
                                           - (float)1.5)
                           * (float)v47);
      v67.mat[1].z = (float)v42
                   * (float)((float)-(float)((float)((float)((float)v47
                                                           * (float)((float)((float)((float)v43 * (float)v43)
                                                                           + (float)((float)((float)v42 * (float)v42)
                                                                                   + (float)((float)v41 * (float)v41)))
                                                                   * (float)0.5))
                                                   * (float)v47)
                                           - (float)1.5)
                           * (float)v47);
      v68.mat[0].y = v67.mat[1].x;
      v68.mat[1].y = v67.mat[1].y;
      v68.mat[2].y = v67.mat[1].z;
      v68.mat[0].x = -v34;
      v68.mat[1].x = -v38;
      v68.mat[2].x = -v35;
      v67.mat[2].x = (float)(v67.mat[1].y * (float)v18) - (float)(v67.mat[1].z * (float)v22);
      v67.mat[2].y = (float)(v67.mat[1].z * (float)v17) - (float)((float)v18 * v67.mat[1].x);
      v67.mat[2].z = (float)((float)v22 * v67.mat[1].x) - (float)(v67.mat[1].y * (float)v17);
      v68.mat[2].z = (float)(v68.mat[1].x * v67.mat[1].x) - (float)(v67.mat[1].y * v68.mat[0].x);
      v68.mat[0].z = (float)(v68.mat[2].x * v67.mat[1].y) - (float)(v68.mat[1].x * v67.mat[1].z);
      v68.mat[1].z = (float)(v67.mat[1].z * v68.mat[0].x) - (float)(v68.mat[2].x * v67.mat[1].x);
      v48 = (float *)idMat3::operator*(this: v69, result: &v68, a: &v67);
      v49 = (float)((float)(v48[6] * (float)v39) + (float)(v48[3] * (float)v37));
      v50 = (float)((float)(v48[4] * (float)v37) + (float)((float)(v48[1] * (float)v36) + (float)(v48[7] * (float)v39)));
      v39 = (float)((float)(v48[5] * (float)v37) + (float)((float)(v48[2] * (float)v36) + (float)(v48[8] * (float)v39)));
      v36 = (float)((float)((float)v36 * *v48) + (float)v49);
      v37 = v50;
    }
    v51 = common->RW(this: common);
    v65[0] = (float)((float)v17 * (float)5.0) + v60;
    v65[1] = (float)((float)v22 * (float)5.0) + v61;
    v65[2] = (float)((float)v18 * (float)5.0) + v62;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v51->DebugArrow)(
      a1: v51,
      a2: &idColor::colorCyan,
      a3: &v60,
      a4: v65,
      a5: 1.0);
    v52 = common->RW(this: common);
    v66[0] = (float)((float)v34 * (float)5.0) + v57;
    v66[1] = (float)((float)v38 * (float)5.0) + v58;
    v66[2] = (float)((float)v35 * (float)5.0) + v59;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, char *, _DWORD, _DWORD, double))v52->DebugArrow)(
      a1: v52,
      a2: &idColor::colorBlue,
      a3: &v57,
      a4: v66,
      a5: &aAvSsobjectVCom[20],
      a6: 0,
      a7: 0,
      a8: 1.0);
    v53 = common->RW(this: common);
    v63[0] = (float)((float)v20 * (float)5.0) + v60;
    v63[1] = (float)((float)v19 * (float)5.0) + v61;
    v63[2] = (float)((float)v21 * (float)5.0) + v62;
    v53->DebugLine(
      this: v53,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idVec3 *)&v60,
      a4: (const idVec3 *)v63,
      a5: 0,
      a6: false);
    v54 = common->RW(this: common);
    v64[0] = (float)((float)v36 * (float)5.0) + v57;
    v64[1] = (float)((float)v37 * (float)5.0) + v58;
    v64[2] = (float)((float)v39 * (float)5.0) + v59;
    v54->DebugLine(
      this: v54,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idVec3 *)&v57,
      a4: (const idVec3 *)v64,
      a5: 0,
      a6: false);
    if ( af_showLimits.valueInteger != 0 )
    {
      coneLimit = this->coneLimit;
      if ( coneLimit != nullptr )
        ((void (*)(void))coneLimit->DebugDraw)();
      pyramidLimit = this->pyramidLimit;
      if ( pyramidLimit != nullptr )
        ((void (*)(void))pyramidLimit->DebugDraw)();
    }
  }
}


// ========================================================================
// ?Add@idAFConstraint_UniversalJointFriction@@QAA_NPAVidPhysics_AF@@M@Z
// EA  : 0x8271D348
// RVA : 0x0071D348
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

int __fastcall idAFConstraint_UniversalJointFriction::Add(
        idAFConstraint_UniversalJointFriction *this,
        idPhysics_AF *phys,
        double invTimeStep)
{
  idAFConstraint_UniversalJoint *joint; // r3
  idSpatialVec *p_lm; // r30
  double Friction; // fp31
  double v8; // fp0
  idAFConstraint_UniversalJoint *v9; // r10
  float *clipModel; // r11
  double v11; // fp5
  double x; // fp2
  double v13; // fp9
  double v14; // fp7
  float *mat; // r6
  double v16; // fp30
  double y; // fp29
  double z; // fp28
  double v19; // fp27
  float *v20; // r11
  float *v21; // r11
  float *v22; // r11
  double v23; // fp26
  double v24; // fp25
  float *v25; // r11
  float *v26; // r11
  float *v27; // r11
  float *v28; // r11
  idVec3 v29; // [sp+50h] [-80h] BYREF
  idVec3 v30; // [sp+60h] [-70h] BYREF
  idVec3 v31; // [sp+70h] [-60h] BYREF

  if ( this->body1 == nullptr )
    return 0;
  if ( phys == nullptr )
    return 0;
  joint = this->joint;
  this->physics = phys;
  if ( joint == nullptr )
    return 0;
  p_lm = &joint->lm;
  Friction = idAFConstraint_UniversalJoint::GetFriction(this: joint);
  v8 = (float)((float)Friction * idSpatialVec::Length(this: p_lm));
  if ( v8 == 0.0 )
    return 0;
  this->lo.p[1] = -v8;
  *this->lo.p = -v8;
  this->hi.p[1] = v8;
  *this->hi.p = v8;
  v9 = this->joint;
  clipModel = (float *)this->body1->clipModel;
  v11 = clipModel[13];
  x = v9->shaft1.x;
  v13 = (float)((float)(clipModel[19] * v9->shaft1.z) + (float)(clipModel[16] * v9->shaft1.y));
  v14 = (float)((float)(clipModel[11] * v9->shaft1.x)
              + (float)((float)(clipModel[17] * v9->shaft1.z) + (float)(clipModel[14] * v9->shaft1.y)));
  v29.y = (float)(clipModel[12] * v9->shaft1.x)
        + (float)((float)(clipModel[18] * v9->shaft1.z) + (float)(clipModel[15] * v9->shaft1.y));
  v29.x = v14;
  v29.z = (float)((float)v11 * (float)x) + (float)v13;
  idVec3::NormalVectors(this: &v29, left: &v30, down: &v31);
  idSpatialMat::SetSize(this: &this->J1, rows: 2, columns: 6);
  mat = this->J1.mat;
  v16 = v30.x;
  y = v30.y;
  z = v30.z;
  v19 = v31.x;
  mat[2] = 0.0;
  mat[1] = 0.0;
  *mat = 0.0;
  v20 = this->J1.mat;
  v20[3] = v16;
  v20[4] = y;
  v20[5] = z;
  v21 = this->J1.mat;
  v21[10] = 0.0;
  v21[9] = 0.0;
  v21[8] = 0.0;
  v22 = this->J1.mat;
  v23 = v31.y;
  v24 = v31.z;
  v22[11] = v19;
  v22[12] = v23;
  v22[13] = v24;
  if ( this->body2 != nullptr )
  {
    idSpatialMat::SetSize(this: &this->J2, rows: 2, columns: 6);
    v25 = this->J2.mat;
    *v25 = 0.0;
    v25[2] = 0.0;
    v25[1] = 0.0;
    v26 = this->J2.mat;
    v26[3] = -v16;
    v26[4] = -y;
    v26[5] = -z;
    v27 = this->J2.mat;
    v27[10] = 0.0;
    v27[9] = 0.0;
    v27[8] = 0.0;
    v28 = this->J2.mat;
    v28[11] = -v19;
    v28[12] = -v23;
    v28[13] = -v24;
  }
  idPhysics_AF::AddFrameConstraint(this: this->physics, constraint: this);
  return 1;
}


// ========================================================================
// ??1idAFConstraint_Hinge@@UAA@XZ
// EA  : 0x8271D570
// RVA : 0x0071D570
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Hinge::~idAFConstraint_Hinge(idAFConstraint_Hinge *this)
{
  idAFConstraint_ConeLimit *coneLimit; // r3
  idAFConstraint_HingeFriction *fc; // r3
  idAFConstraint_HingeSteering *steering; // r3

  this->__vftable = (idAFConstraint_Hinge_vtbl *)&idAFConstraint_Hinge::`vftable';
  coneLimit = this->coneLimit;
  if ( coneLimit != nullptr )
    ((void (__fastcall *)(idAFConstraint_ConeLimit *, int))coneLimit->dtr_idAFConstraint)(a1: coneLimit, a2: 1);
  fc = this->fc;
  if ( fc != nullptr )
    ((void (__fastcall *)(idAFConstraint_HingeFriction *, int))fc->dtr_idAFConstraint)(a1: fc, a2: 1);
  steering = this->steering;
  if ( steering != nullptr )
    ((void (__fastcall *)(idAFConstraint_HingeSteering *, int))steering->dtr_idAFConstraint)(a1: steering, a2: 1);
  idAFConstraint::~idAFConstraint(this);
}


// ========================================================================
// __unwind$253511
// EA  : 0x8271D628
// RVA : 0x0071D628
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_253511()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 112 + 132));
}


// ========================================================================
// ?SetAxis@idAFConstraint_Hinge@@QAAXABVidVec3@@@Z
// EA  : 0x8271D650
// RVA : 0x0071D650
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Hinge::SetAxis(idAFConstraint_Hinge *this, const idVec3 *axis)
{
  idAFBody *body1; // r11
  double v5; // fp2
  double v6; // fp5
  double v7; // fp3
  double v8; // fp2
  double v9; // fp0
  double v10; // fp13
  double v11; // fp12
  float *clipModel; // r11
  double v13; // fp1
  double v14; // fp11
  double v15; // fp9
  double v16; // fp8
  idAFBody *body2; // r11
  float *v18; // r11
  double v19; // fp1
  double v20; // fp13
  double v21; // fp10
  double v22; // fp9
  double v23; // fp8

  body1 = this->body1;
  _FP5 = (float)((float)((float)(axis->x * axis->x) + (float)((float)(axis->z * axis->z) + (float)(axis->y * axis->y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v5 = __frsqrte(_FP3);
  v6 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5
                                                                                     * (float)((float)((float)(axis->x * axis->x) + (float)((float)(axis->z * axis->z) + (float)(axis->y * axis->y)))
                                                                                             * (float)0.5))
                                                                             * (float)v5)
                                                                     - (float)1.5)
                                                     * (float)v5)
                                             * (float)((float)((float)(axis->x * axis->x)
                                                             + (float)((float)(axis->z * axis->z)
                                                                     + (float)(axis->y * axis->y)))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v5
                                                                             * (float)((float)((float)(axis->x * axis->x)
                                                                                             + (float)((float)(axis->z * axis->z) + (float)(axis->y * axis->y)))
                                                                                     * (float)0.5))
                                                                     * (float)v5)
                                                             - (float)1.5)
                                             * (float)v5))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v5
                                                     * (float)((float)((float)(axis->x * axis->x)
                                                                     + (float)((float)(axis->z * axis->z)
                                                                             + (float)(axis->y * axis->y)))
                                                             * (float)0.5))
                                             * (float)v5)
                                     - (float)1.5)
                     * (float)v5));
  v7 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)(axis->x * axis->x) + (float)((float)(axis->z * axis->z) + (float)(axis->y * axis->y))) * (float)0.5)) * (float)v5) - (float)1.5)
                                                                                     * (float)v5)
                                                                             * (float)((float)((float)(axis->x * axis->x)
                                                                                             + (float)((float)(axis->z * axis->z) + (float)(axis->y * axis->y)))
                                                                                     * (float)0.5))
                                                                     * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)(axis->x * axis->x) + (float)((float)(axis->z * axis->z) + (float)(axis->y * axis->y))) * (float)0.5)) * (float)v5)
                                                                                             - (float)1.5)
                                                                             * (float)v5))
                                                             - (float)1.5)
                                             * (float)((float)-(float)((float)((float)((float)v5
                                                                                     * (float)((float)((float)(axis->x * axis->x) + (float)((float)(axis->z * axis->z) + (float)(axis->y * axis->y)))
                                                                                             * (float)0.5))
                                                                             * (float)v5)
                                                                     - (float)1.5)
                                                     * (float)v5))
                                     * (float)((float)((float)(axis->x * axis->x)
                                                     + (float)((float)(axis->z * axis->z) + (float)(axis->y * axis->y)))
                                             * (float)0.5))
                             * (float)v6)
                     - (float)1.5);
  v8 = (float)((float)v7
             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5
                                                                                             * (float)((float)((float)(axis->x * axis->x) + (float)((float)(axis->z * axis->z) + (float)(axis->y * axis->y))) * (float)0.5))
                                                                                     * (float)v5)
                                                                             - (float)1.5)
                                                             * (float)v5)
                                                     * (float)((float)((float)(axis->x * axis->x)
                                                                     + (float)((float)(axis->z * axis->z)
                                                                             + (float)(axis->y * axis->y)))
                                                             * (float)0.5))
                                             * (float)((float)-(float)((float)((float)((float)v5
                                                                                     * (float)((float)((float)(axis->x * axis->x) + (float)((float)(axis->z * axis->z) + (float)(axis->y * axis->y)))
                                                                                             * (float)0.5))
                                                                             * (float)v5)
                                                                     - (float)1.5)
                                                     * (float)v5))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)v5
                                                             * (float)((float)((float)(axis->x * axis->x)
                                                                             + (float)((float)(axis->z * axis->z)
                                                                                     + (float)(axis->y * axis->y)))
                                                                     * (float)0.5))
                                                     * (float)v5)
                                             - (float)1.5)
                             * (float)v5)));
  v9 = (float)((float)v8 * axis->x);
  v10 = (float)(axis->y * (float)v8);
  v11 = (float)(axis->z * (float)v8);
  if ( body1 != nullptr )
  {
    clipModel = (float *)body1->clipModel;
    v13 = clipModel[14];
    v14 = clipModel[11];
    v15 = (float)((float)((float)(axis->z * (float)v8) * clipModel[16])
                + (float)(clipModel[15] * (float)(axis->y * (float)v8)));
    v16 = (float)((float)((float)(axis->z * (float)v8) * clipModel[13])
                + (float)(clipModel[12] * (float)(axis->y * (float)v8)));
    this->axis1.z = (float)(clipModel[17] * (float)((float)v8 * axis->x))
                  + (float)((float)((float)(axis->z * (float)v8) * clipModel[19])
                          + (float)(clipModel[18] * (float)(axis->y * (float)v8)));
    this->axis1.y = (float)((float)v13 * (float)v9) + (float)v15;
    this->axis1.x = (float)((float)v14 * (float)v9) + (float)v16;
    body2 = this->body2;
    if ( body2 != nullptr )
    {
      v18 = (float *)body2->clipModel;
      v19 = v18[14];
      v21 = (float)((float)((float)v11 * v18[16]) + (float)(v18[15] * (float)v10));
      v22 = (float)((float)((float)v11 * v18[13]) + (float)(v18[12] * (float)v10));
      v23 = (float)((float)(v18[17] * (float)v9) + (float)((float)((float)v11 * v18[19]) + (float)(v18[18] * (float)v10)));
      v20 = v18[11];
      this->axis2.z = v23;
      this->axis2.y = (float)((float)v19 * (float)v9) + (float)v21;
      this->axis2.x = (float)((float)v20 * (float)v9) + (float)v22;
    }
    else
    {
      this->axis2.x = v9;
      this->axis2.y = v10;
      this->axis2.z = v11;
    }
  }
}


// ========================================================================
// ?GetFriction@idAFConstraint_Hinge@@QBAMXZ
// EA  : 0x8271D7A0
// RVA : 0x0071D7A0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

float __fastcall idAFConstraint_Hinge::GetFriction(idAFConstraint_Hinge *this)
{
  idPhysics_AF *physics; // r3
  double valueFloat; // fp1

  physics = this->physics;
  if ( physics != nullptr )
  {
    valueFloat = af_forceFriction.valueFloat;
    if ( af_forceFriction.valueFloat <= 0.0 )
      valueFloat = (float)(idPhysics_AF::GetJointFrictionScale(this: physics) * this->friction);
  }
  else
  {
    valueFloat = 0.0;
  }
  return *((float *)&valueFloat + 1);
}


// ========================================================================
// ?GetAngle@idAFConstraint_Hinge@@QBAMXZ
// EA  : 0x8271D818
// RVA : 0x0071D818
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

float __fastcall idAFConstraint_Hinge::GetAngle(idAFConstraint_Hinge *this)
{
  idAFBody *body1; // r10
  idAFBody *body2; // r11
  float *clipModel; // r11
  double z; // fp0
  idMat3 *p_axis; // r4
  double v7; // fp13
  double v8; // fp12
  double v9; // fp10
  double v10; // fp9
  double v11; // fp8
  double v12; // fp7
  double v13; // fp6
  double v14; // fp5
  double v15; // fp4
  double v16; // fp3
  double y; // fp2
  double v18; // fp1
  double v19; // fp11
  double x; // fp9
  double v21; // fp8
  idMat3 *v22; // r3
  float *v23; // r3
  const idRotation *v24; // r3
  double angle; // fp1
  idRotation v27; // [sp+50h] [-140h] BYREF
  float v28; // [sp+94h] [-FCh]
  float v29; // [sp+98h] [-F8h]
  float v30; // [sp+9Ch] [-F4h]
  float v31; // [sp+A0h] [-F0h]
  idMat3 v32[2]; // [sp+B0h] [-E0h] BYREF
  idRotation v33; // [sp+100h] [-90h] BYREF
  idMat3 v34; // [sp+150h] [-40h] BYREF

  body1 = this->body1;
  if ( body1 != nullptr && (body2 = this->body2) != nullptr )
  {
    clipModel = (float *)body2->clipModel;
    z = this->initialAxis.mat[2].z;
    p_axis = &body1->clipModel->axis;
    v7 = this->initialAxis.mat[1].z;
    v8 = this->initialAxis.mat[0].z;
    v9 = clipModel[16];
    v10 = clipModel[13];
    v11 = clipModel[18];
    v12 = clipModel[15];
    v13 = clipModel[12];
    v14 = clipModel[17];
    v15 = clipModel[14];
    v16 = clipModel[11];
    v31 = clipModel[19];
    v30 = v9;
    v29 = v10;
    v28 = v11;
    *(float *)&v27.axisValid = v12;
    v27.axis.mat[2].z = v13;
    v27.axis.mat[2].y = v14;
    v27.axis.mat[2].x = v15;
    v27.axis.mat[1].z = v16;
    y = this->initialAxis.mat[2].y;
    v18 = this->initialAxis.mat[1].y;
    v19 = this->initialAxis.mat[0].y;
    x = this->initialAxis.mat[1].x;
    v21 = this->initialAxis.mat[0].x;
    v32[0].mat[0].z = this->initialAxis.mat[2].x;
    v32[0].mat[0].y = x;
    v32[0].mat[0].x = v21;
    v32[0].mat[1].x = v19;
    v32[0].mat[1].y = v18;
    v32[0].mat[1].z = y;
    v32[0].mat[2].x = v8;
    v32[0].mat[2].y = v7;
    v32[0].mat[2].z = z;
    v22 = idMat3::operator*(this: &v34, result: p_axis, a: (const idMat3 *)&v27.axis.mat[1].z);
    v23 = (float *)idMat3::operator*(this: (idMat3 *)&v33, result: v22, a: v32);
    v27.origin.x = *v23;
    v27.origin.y = v23[1];
    v27.origin.z = v23[2];
    v27.vec.x = v23[3];
    v27.vec.y = v23[4];
    v27.vec.z = v23[5];
    v27.angle = v23[6];
    v27.axis.mat[0].x = v23[7];
    v27.axis.mat[0].y = v23[8];
    v24 = idMat3::ToRotation(this: v32, result: &v27);
    idRotation::operator=(this: &v33, __that: v24);
    if ( (float)((float)(v33.vec.x * this->axis1.x)
               + (float)((float)(this->axis1.y * v33.vec.y) + (float)(this->axis1.z * v33.vec.z))) >= 0.0 )
      angle = v33.angle;
    else
      angle = -v33.angle;
  }
  else
  {
    angle = 0.0;
  }
  return *((float *)&angle + 1);
}


// ========================================================================
// ?Translate@idAFConstraint_Hinge@@UAAXABVidVec3@@@Z
// EA  : 0x8271D9E8
// RVA : 0x0071D9E8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Hinge::Translate(idAFConstraint_Hinge *this, const idVec3 *translation)
{
  double y; // fp11
  double z; // fp8
  idAFConstraint_ConeLimit *coneLimit; // r11

  if ( this->body2 == nullptr )
  {
    y = this->anchor2.y;
    this->anchor2.x = this->anchor2.x + translation->x;
    z = this->anchor2.z;
    this->anchor2.y = translation->y + (float)y;
    this->anchor2.z = translation->z + (float)z;
  }
  coneLimit = this->coneLimit;
  if ( coneLimit != nullptr )
    ((void (*)(void))coneLimit->Translate)();
}


// ========================================================================
// ?Rotate@idAFConstraint_Hinge@@UAAXABVidRotation@@@Z
// EA  : 0x8271DA50
// RVA : 0x0071DA50
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Hinge::Rotate(idAFConstraint_Hinge *this, idRotation *rotation)
{
  float *v4; // r3
  double z; // fp11
  double v6; // fp12
  double v7; // fp8
  double v8; // fp6
  double v9; // fp5
  idAFConstraint_ConeLimit *coneLimit; // r11
  char v11; // [sp+50h] [-30h] BYREF

  if ( this->body2 == nullptr )
  {
    this->anchor2 = idRotation::operator*(this: (idRotation *)&v11, result: rotation, v: &this->anchor2)->origin;
    v4 = (float *)idRotation::ToMat3(this: rotation);
    z = this->axis2.z;
    v6 = v4[7];
    v7 = v4[8];
    v8 = (float)((float)(v4[1] * this->axis2.x) + (float)(v4[4] * this->axis2.y));
    v9 = (float)((float)(v4[2] * this->axis2.x) + (float)(v4[5] * this->axis2.y));
    this->axis2.x = (float)(*v4 * this->axis2.x)
                  + (float)((float)(v4[3] * this->axis2.y) + (float)(v4[6] * this->axis2.z));
    this->axis2.y = (float)((float)v6 * (float)z) + (float)v8;
    this->axis2.z = (float)((float)v7 * (float)z) + (float)v9;
  }
  coneLimit = this->coneLimit;
  if ( coneLimit != nullptr )
    ((void (*)(void))coneLimit->Rotate)();
}


// ========================================================================
// ?DebugDraw@idAFConstraint_Hinge@@UAAXXZ
// EA  : 0x8271DB48
// RVA : 0x0071DB48
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Hinge::DebugDraw(idAFConstraint_Hinge *this)
{
  idAFBody *body1; // r11
  double z; // fp0
  double v4; // fp12
  float *clipModel; // r11
  double x; // fp9
  double v7; // fp28
  double v8; // fp26
  double v9; // fp25
  double v10; // fp24
  double v11; // fp5
  double v12; // fp1
  double v13; // fp29
  double v14; // fp13
  double v15; // fp7
  double v16; // fp2
  double v17; // fp4
  double v18; // fp3
  double v19; // fp11
  double v20; // fp31
  double v21; // fp30
  double v22; // fp29
  double v23; // fp13
  double v24; // fp12
  double v25; // fp28
  double v26; // fp27
  double v27; // fp26
  idRenderWorld *v28; // r3
  idRenderWorld *v29; // r3
  idRenderWorld *v30; // r3
  idAFConstraint_ConeLimit *coneLimit; // r11
  idVec3 v32; // [sp+50h] [-E0h] BYREF
  float v33[4]; // [sp+60h] [-D0h] BYREF
  idVec3 v34; // [sp+70h] [-C0h] BYREF
  float v35[4]; // [sp+80h] [-B0h] BYREF
  float v36[4]; // [sp+90h] [-A0h] BYREF
  idVec3 v37; // [sp+A0h] [-90h] BYREF
  float v38[4]; // [sp+B0h] [-80h] BYREF
  float v39[20]; // [sp+C0h] [-70h] BYREF

  body1 = this->body1;
  if ( body1 != nullptr )
  {
    z = this->axis1.z;
    v4 = this->anchor1.z;
    clipModel = (float *)body1->clipModel;
    x = this->anchor1.x;
    v7 = clipModel[19];
    v8 = clipModel[8];
    v9 = clipModel[9];
    v10 = clipModel[10];
    v11 = (float)(clipModel[15] * this->anchor1.y);
    v12 = (float)(clipModel[16] * this->anchor1.y);
    v13 = clipModel[12];
    v14 = (float)((float)(clipModel[12] * this->axis1.x) + (float)(clipModel[15] * this->axis1.y));
    v15 = clipModel[11];
    v16 = clipModel[13];
    v17 = (float)((float)(clipModel[13] * this->axis1.x) + (float)(clipModel[16] * this->axis1.y));
    v18 = clipModel[18];
    v19 = (float)((float)(clipModel[14] * this->anchor1.y) + (float)(clipModel[17] * this->anchor1.z));
    v20 = (float)((float)(clipModel[11] * this->axis1.x)
                + (float)((float)(clipModel[14] * this->axis1.y) + (float)(clipModel[17] * this->axis1.z)));
    v21 = (float)((float)(clipModel[18] * this->axis1.z)
                + (float)((float)(clipModel[12] * this->axis1.x) + (float)(clipModel[15] * this->axis1.y)));
    v32.x = (float)(clipModel[11] * this->axis1.x)
          + (float)((float)(clipModel[14] * this->axis1.y) + (float)(clipModel[17] * this->axis1.z));
    v32.y = (float)((float)v18 * (float)z) + (float)v14;
    v32.z = (float)((float)v7 * (float)z) + (float)v17;
    v23 = (float)((float)((float)v18 * (float)v4) + (float)((float)((float)v13 * (float)x) + (float)v11));
    v22 = v32.z;
    v24 = (float)((float)((float)v7 * (float)v4) + (float)((float)((float)v16 * (float)x) + (float)v12));
    v25 = (float)((float)v8 + (float)((float)((float)x * (float)v15) + (float)v19));
    v26 = (float)((float)v9 + (float)v23);
    v27 = (float)((float)v10 + (float)v24);
    idVec3::OrthogonalBasis(this: &v32, left: &v34, up: &v37);
    v28 = common->RW(this: common);
    v32.x = (float)((float)v20 * (float)4.0) + (float)v25;
    v32.y = (float)((float)v21 * (float)4.0) + (float)v26;
    v32.z = (float)((float)v22 * (float)4.0) + (float)v27;
    v33[0] = (float)v25 - (float)((float)v20 * (float)4.0);
    v33[1] = (float)v26 - (float)((float)v21 * (float)4.0);
    v33[2] = (float)v27 - (float)((float)v22 * (float)4.0);
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idVec3 *, double))v28->DebugArrow)(
      a1: v28,
      a2: &idColor::colorBlue,
      a3: v33,
      a4: &v32,
      a5: 1.0);
    v29 = common->RW(this: common);
    v35[0] = (float)(v34.x * (float)2.0) + (float)v25;
    v35[1] = (float)(v34.y * (float)2.0) + (float)v26;
    v35[2] = (float)(v34.z * (float)2.0) + (float)v27;
    v36[0] = (float)v25 - (float)(v34.x * (float)2.0);
    v36[1] = (float)v26 - (float)(v34.y * (float)2.0);
    v36[2] = (float)v27 - (float)(v34.z * (float)2.0);
    v29->DebugLine(
      this: v29,
      a2: (const idVec4 *)&idColor::colorBlue,
      a3: (const idVec3 *)v36,
      a4: (const idVec3 *)v35,
      a5: 0,
      a6: false);
    v30 = common->RW(this: common);
    v38[0] = (float)(v37.x * (float)2.0) + (float)v25;
    v38[1] = (float)(v37.y * (float)2.0) + (float)v26;
    v38[2] = (float)(v37.z * (float)2.0) + (float)v27;
    v39[0] = (float)v25 - (float)(v37.x * (float)2.0);
    v39[2] = (float)v27 - (float)(v37.z * (float)2.0);
    v39[1] = (float)v26 - (float)(v37.y * (float)2.0);
    v30->DebugLine(
      this: v30,
      a2: (const idVec4 *)&idColor::colorBlue,
      a3: (const idVec3 *)v39,
      a4: (const idVec3 *)v38,
      a5: 0,
      a6: false);
    if ( af_showLimits.valueInteger != 0 )
    {
      coneLimit = this->coneLimit;
      if ( coneLimit != nullptr )
        ((void (*)(void))coneLimit->DebugDraw)();
    }
  }
}


// ========================================================================
// ?Add@idAFConstraint_HingeFriction@@QAA_NPAVidPhysics_AF@@M@Z
// EA  : 0x8271DE30
// RVA : 0x0071DE30
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

int __fastcall idAFConstraint_HingeFriction::Add(
        idAFConstraint_HingeFriction *this,
        idPhysics_AF *phys,
        double invTimeStep)
{
  idAFConstraint_Hinge *hinge; // r3
  idSpatialVec *p_lm; // r30
  double Friction; // fp31
  double v8; // fp0
  idAFConstraint_Hinge *v9; // r8
  float *clipModel; // r11
  double x; // fp30
  double y; // fp29
  double z; // fp28
  double v14; // fp27
  double v15; // fp26
  double v16; // fp25
  float *mat; // r7
  float *v18; // r11
  idAFBody *body2; // r11
  float *v20; // r11
  double v21; // fp1
  double v22; // fp0
  double v23; // fp29
  double v24; // fp28
  double v25; // fp30
  float *v26; // r11
  float *v27; // r11

  this->physics = phys;
  if ( phys == nullptr )
    return 0;
  hinge = this->hinge;
  if ( hinge == nullptr )
    return 0;
  p_lm = &hinge->lm;
  Friction = idAFConstraint_Hinge::GetFriction(this: hinge);
  v8 = (float)((float)Friction * idSpatialVec::Length(this: p_lm));
  if ( v8 == 0.0 || this->body1 == nullptr )
    return 0;
  *this->lo.p = -v8;
  *this->hi.p = v8;
  v9 = this->hinge;
  clipModel = (float *)this->body1->clipModel;
  x = v9->axis2.x;
  y = v9->axis2.y;
  z = v9->axis2.z;
  v14 = (float)((float)(clipModel[11] * v9->axis1.x)
              + (float)((float)(clipModel[17] * v9->axis1.z) + (float)(clipModel[14] * v9->axis1.y)));
  v15 = (float)((float)(clipModel[12] * v9->axis1.x)
              + (float)((float)(clipModel[18] * v9->axis1.z) + (float)(clipModel[15] * v9->axis1.y)));
  v16 = (float)((float)(clipModel[13] * v9->axis1.x)
              + (float)((float)(clipModel[19] * v9->axis1.z) + (float)(clipModel[16] * v9->axis1.y)));
  idSpatialMat::SetSize(this: &this->J1, rows: 1, columns: 6);
  mat = this->J1.mat;
  mat[2] = 0.0;
  mat[1] = 0.0;
  *mat = 0.0;
  v18 = this->J1.mat;
  v18[3] = v14;
  v18[4] = v15;
  v18[5] = v16;
  body2 = this->body2;
  if ( body2 != nullptr )
  {
    v20 = (float *)body2->clipModel;
    v21 = (float)((float)(v20[18] * (float)z) + (float)(v20[15] * (float)y));
    v22 = (float)((float)(v20[19] * (float)z) + (float)(v20[16] * (float)y));
    v23 = (float)((float)(v20[11] * (float)x) + (float)((float)(v20[17] * (float)z) + (float)(v20[14] * (float)y)));
    v24 = (float)((float)(v20[12] * (float)x) + (float)v21);
    v25 = (float)((float)(v20[13] * (float)x) + (float)v22);
    idSpatialMat::SetSize(this: &this->J2, rows: 1, columns: 6);
    v26 = this->J2.mat;
    v26[2] = 0.0;
    *v26 = 0.0;
    v26[1] = 0.0;
    v27 = this->J2.mat;
    v27[3] = -v23;
    v27[4] = -v24;
    v27[5] = -v25;
  }
  idPhysics_AF::AddFrameConstraint(this: this->physics, constraint: this);
  return 1;
}


// ========================================================================
// ?Add@idAFConstraint_HingeSteering@@QAA_NPAVidPhysics_AF@@M@Z
// EA  : 0x8271E018
// RVA : 0x0071E018
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

int __fastcall idAFConstraint_HingeSteering::Add(
        idAFConstraint_HingeSteering *this,
        idPhysics_AF *phys,
        double invTimeStep)
{
  idAFBody *body1; // r11
  idAFConstraint_Hinge *hinge; // r3
  double x; // fp31
  double y; // fp25
  double z; // fp24
  double v11; // fp30
  double v12; // fp29
  double v13; // fp28
  double Angle; // fp27
  float *clipModel; // r11
  double v16; // fp1
  double v17; // fp0
  double v18; // fp25
  double v19; // fp24
  double v20; // fp23
  float *mat; // r9
  float *v22; // r11
  idAFBody *body2; // r11
  float *v24; // r11
  double v25; // fp1
  double v26; // fp0
  double v27; // fp29
  double v28; // fp28
  double v29; // fp30
  float *v30; // r11
  float *v31; // r11
  double steerSpeed; // fp13
  double v33; // fp0

  body1 = this->body1;
  this->physics = phys;
  if ( body1 == nullptr )
    return 0;
  if ( phys == nullptr )
    return 0;
  hinge = this->hinge;
  if ( hinge == nullptr )
    return 0;
  x = hinge->axis1.x;
  y = hinge->axis1.y;
  z = hinge->axis1.z;
  v11 = hinge->axis2.x;
  v12 = hinge->axis2.y;
  v13 = hinge->axis2.z;
  Angle = idAFConstraint_Hinge::GetAngle(this: hinge);
  clipModel = (float *)this->body1->clipModel;
  v16 = (float)((float)(clipModel[18] * (float)z) + (float)(clipModel[15] * (float)y));
  v17 = (float)((float)(clipModel[19] * (float)z) + (float)(clipModel[16] * (float)y));
  v18 = (float)((float)(clipModel[11] * (float)x)
              + (float)((float)(clipModel[17] * (float)z) + (float)(clipModel[14] * (float)y)));
  v19 = (float)((float)(clipModel[12] * (float)x) + (float)v16);
  v20 = (float)((float)(clipModel[13] * (float)x) + (float)v17);
  idSpatialMat::SetSize(this: &this->J1, rows: 1, columns: 6);
  mat = this->J1.mat;
  mat[2] = 0.0;
  mat[1] = 0.0;
  *mat = 0.0;
  v22 = this->J1.mat;
  v22[3] = v18;
  v22[4] = v19;
  v22[5] = v20;
  body2 = this->body2;
  if ( body2 != nullptr )
  {
    v24 = (float *)body2->clipModel;
    v25 = (float)((float)(v24[18] * (float)v13) + (float)(v24[15] * (float)v12));
    v26 = (float)((float)(v24[19] * (float)v13) + (float)(v24[16] * (float)v12));
    v27 = (float)((float)(v24[11] * (float)v11) + (float)((float)(v24[17] * (float)v13) + (float)(v24[14] * (float)v12)));
    v28 = (float)((float)(v24[12] * (float)v11) + (float)v25);
    v29 = (float)((float)(v24[13] * (float)v11) + (float)v26);
    idSpatialMat::SetSize(this: &this->J2, rows: 1, columns: 6);
    v30 = this->J2.mat;
    v30[2] = 0.0;
    v30[1] = 0.0;
    *v30 = 0.0;
    v31 = this->J2.mat;
    v31[3] = -v27;
    v31[4] = -v28;
    v31[5] = -v29;
  }
  steerSpeed = this->steerSpeed;
  v33 = (float)(this->steerAngle - (float)Angle);
  if ( steerSpeed != 0.0 )
  {
    if ( v33 > steerSpeed || (steerSpeed = -steerSpeed, v33 < steerSpeed) )
      v33 = steerSpeed;
  }
  *this->c1.p = (float)(idMath::M_DEG2RAD * (float)v33) * (float)invTimeStep;
  idPhysics_AF::AddFrameConstraint(this: this->physics, constraint: this);
  return 1;
}


// ========================================================================
// ?SetAxis@idAFConstraint_Slider@@QAAXABVidVec3@@@Z
// EA  : 0x8271E210
// RVA : 0x0071E210
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Slider::SetAxis(idAFConstraint_Slider *this, const idVec3 *ax)
{
  idAFBody *body2; // r11
  double v5; // fp2
  double v6; // fp5
  double v7; // fp3
  double v8; // fp2
  double v9; // fp0
  double v10; // fp13
  double v11; // fp12
  float *clipModel; // r11
  double v13; // fp1
  double v14; // fp13
  double v15; // fp10
  double v16; // fp9

  body2 = this->body2;
  _FP5 = (float)((float)((float)(ax->x * ax->x) + (float)((float)(ax->z * ax->z) + (float)(ax->y * ax->y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v5 = __frsqrte(_FP3);
  v6 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5
                                                                                     * (float)((float)((float)(ax->x * ax->x) + (float)((float)(ax->z * ax->z) + (float)(ax->y * ax->y)))
                                                                                             * (float)0.5))
                                                                             * (float)v5)
                                                                     - (float)1.5)
                                                     * (float)v5)
                                             * (float)((float)((float)(ax->x * ax->x)
                                                             + (float)((float)(ax->z * ax->z) + (float)(ax->y * ax->y)))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v5
                                                                             * (float)((float)((float)(ax->x * ax->x)
                                                                                             + (float)((float)(ax->z * ax->z) + (float)(ax->y * ax->y)))
                                                                                     * (float)0.5))
                                                                     * (float)v5)
                                                             - (float)1.5)
                                             * (float)v5))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v5
                                                     * (float)((float)((float)(ax->x * ax->x)
                                                                     + (float)((float)(ax->z * ax->z)
                                                                             + (float)(ax->y * ax->y)))
                                                             * (float)0.5))
                                             * (float)v5)
                                     - (float)1.5)
                     * (float)v5));
  v7 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)(ax->x * ax->x) + (float)((float)(ax->z * ax->z) + (float)(ax->y * ax->y))) * (float)0.5)) * (float)v5) - (float)1.5)
                                                                                     * (float)v5)
                                                                             * (float)((float)((float)(ax->x * ax->x)
                                                                                             + (float)((float)(ax->z * ax->z) + (float)(ax->y * ax->y)))
                                                                                     * (float)0.5))
                                                                     * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)(ax->x * ax->x) + (float)((float)(ax->z * ax->z) + (float)(ax->y * ax->y))) * (float)0.5)) * (float)v5)
                                                                                             - (float)1.5)
                                                                             * (float)v5))
                                                             - (float)1.5)
                                             * (float)((float)-(float)((float)((float)((float)v5
                                                                                     * (float)((float)((float)(ax->x * ax->x) + (float)((float)(ax->z * ax->z) + (float)(ax->y * ax->y)))
                                                                                             * (float)0.5))
                                                                             * (float)v5)
                                                                     - (float)1.5)
                                                     * (float)v5))
                                     * (float)((float)((float)(ax->x * ax->x)
                                                     + (float)((float)(ax->z * ax->z) + (float)(ax->y * ax->y)))
                                             * (float)0.5))
                             * (float)v6)
                     - (float)1.5);
  v8 = (float)((float)v7
             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5
                                                                                             * (float)((float)((float)(ax->x * ax->x) + (float)((float)(ax->z * ax->z) + (float)(ax->y * ax->y))) * (float)0.5))
                                                                                     * (float)v5)
                                                                             - (float)1.5)
                                                             * (float)v5)
                                                     * (float)((float)((float)(ax->x * ax->x)
                                                                     + (float)((float)(ax->z * ax->z)
                                                                             + (float)(ax->y * ax->y)))
                                                             * (float)0.5))
                                             * (float)((float)-(float)((float)((float)((float)v5
                                                                                     * (float)((float)((float)(ax->x * ax->x) + (float)((float)(ax->z * ax->z) + (float)(ax->y * ax->y)))
                                                                                             * (float)0.5))
                                                                             * (float)v5)
                                                                     - (float)1.5)
                                                     * (float)v5))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)v5
                                                             * (float)((float)((float)(ax->x * ax->x)
                                                                             + (float)((float)(ax->z * ax->z)
                                                                                     + (float)(ax->y * ax->y)))
                                                                     * (float)0.5))
                                                     * (float)v5)
                                             - (float)1.5)
                             * (float)v5)));
  v9 = (float)((float)v8 * ax->x);
  v10 = (float)(ax->y * (float)v8);
  v11 = (float)(ax->z * (float)v8);
  if ( body2 != nullptr )
  {
    clipModel = (float *)body2->clipModel;
    v13 = clipModel[14];
    v15 = (float)((float)((float)(ax->z * (float)v8) * clipModel[16])
                + (float)(clipModel[15] * (float)(ax->y * (float)v8)));
    v16 = (float)((float)((float)(ax->z * (float)v8) * clipModel[13])
                + (float)(clipModel[12] * (float)(ax->y * (float)v8)));
    v14 = clipModel[11];
    this->axis.z = (float)(clipModel[17] * (float)((float)v8 * ax->x))
                 + (float)((float)((float)(ax->z * (float)v8) * clipModel[19])
                         + (float)(clipModel[18] * (float)(ax->y * (float)v8)));
    this->axis.y = (float)((float)v13 * (float)v9) + (float)v15;
    this->axis.x = (float)((float)v14 * (float)v9) + (float)v16;
  }
  else
  {
    this->axis.x = (float)v8 * ax->x;
    this->axis.y = v10;
    this->axis.z = v11;
  }
}


// ========================================================================
// ?Translate@idAFConstraint_Spring@@UAAXABVidVec3@@@Z
// EA  : 0x8271E300
// RVA : 0x0071E300
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Spring::Translate(idAFConstraint_Spring *this, const idVec3 *translation)
{
  double y; // fp11
  double z; // fp8

  if ( this->body2 == nullptr )
  {
    y = this->anchor2.y;
    this->anchor2.x = this->anchor2.x + translation->x;
    z = this->anchor2.z;
    this->anchor2.y = translation->y + (float)y;
    this->anchor2.z = translation->z + (float)z;
  }
}


// ========================================================================
// ?Rotate@idAFConstraint_Spring@@UAAXABVidRotation@@@Z
// EA  : 0x8271E348
// RVA : 0x0071E348
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Spring::Rotate(idAFConstraint_Spring *this, idRotation *rotation)
{
  char v2; // [sp+50h] [-20h] BYREF

  if ( this->body2 == nullptr )
    this->anchor2 = idRotation::operator*(this: (idRotation *)&v2, result: rotation, v: &this->anchor2)->origin;
}


// ========================================================================
// ?GetCenter@idAFConstraint_Slider@@UAAXAAVidVec3@@@Z
// EA  : 0x8271E3A0
// RVA : 0x0071E3A0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Slider::GetCenter(idAFConstraint_Slider *this, idVec3 *center)
{
  idAFBody *body1; // r10
  idAFBody *body2; // r11
  idPhysics_AF *physics; // r11
  float *clipModel; // r9
  float *v6; // r11
  double v7; // fp4
  double v8; // fp3
  double v9; // fp11
  double v10; // fp10
  float *v11; // r11
  double v12; // fp9
  double v13; // fp6

  body1 = this->body1;
  if ( body1 != nullptr )
  {
    body2 = this->body2;
    if ( body2 != nullptr || (physics = this->physics) != nullptr && (body2 = physics->masterBody) != nullptr )
    {
      clipModel = (float *)body2->clipModel;
      v6 = (float *)body1->clipModel;
      v7 = v6[9];
      v8 = v6[10];
      v9 = (float)(clipModel[9]
                 + (float)((float)(clipModel[18] * this->offset.z)
                         + (float)((float)(clipModel[12] * this->offset.x) + (float)(clipModel[15] * this->offset.y))));
      v10 = (float)(clipModel[10]
                  + (float)((float)(clipModel[19] * this->offset.z)
                          + (float)((float)(clipModel[13] * this->offset.x) + (float)(clipModel[16] * this->offset.y))));
      center->x = (float)(clipModel[8]
                        + (float)((float)(this->offset.x * clipModel[11])
                                + (float)((float)(clipModel[14] * this->offset.y)
                                        + (float)(clipModel[17] * this->offset.z))))
                - v6[8];
      center->y = (float)v9 - (float)v7;
      center->z = (float)v10 - (float)v8;
    }
    else
    {
      v11 = (float *)body1->clipModel;
      v12 = (float)(this->offset.x - v11[8]);
      v13 = (float)(this->offset.z - v11[10]);
      center->y = this->offset.y - v11[9];
      center->z = v13;
      center->x = v12;
    }
  }
  else
  {
    center->z = 0.0;
    center->y = 0.0;
    center->x = 0.0;
  }
}


// ========================================================================
// ?DebugDraw@idAFConstraint_Slider@@UAAXXZ
// EA  : 0x8271E4C0
// RVA : 0x0071E4C0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Slider::DebugDraw(idAFConstraint_Slider *this)
{
  idAFBody *body1; // r10
  idAFBody *body2; // r11
  idPhysics_AF *physics; // r11
  float *clipModel; // r9
  float *v6; // r11
  double v7; // fp9
  double v8; // fp7
  float *v9; // r11
  double v10; // fp6
  idRenderWorld *v11; // r3
  float *v12; // r11
  double v13; // fp7
  double v14; // fp5
  float v15; // [sp+50h] [-40h] BYREF
  float v16; // [sp+54h] [-3Ch]
  float v17; // [sp+58h] [-38h]
  float v18[6]; // [sp+60h] [-30h] BYREF

  body1 = this->body1;
  if ( body1 != nullptr )
  {
    body2 = this->body2;
    if ( body2 != nullptr || (physics = this->physics) != nullptr && (body2 = physics->masterBody) != nullptr )
    {
      clipModel = (float *)body2->clipModel;
      v6 = (float *)body1->clipModel;
      v7 = (float)((float)(clipModel[8]
                         + (float)((float)(this->offset.x * clipModel[11])
                                 + (float)((float)(clipModel[14] * this->offset.y)
                                         + (float)(clipModel[17] * this->offset.z))))
                 - v6[8]);
      v8 = (float)((float)(clipModel[10]
                         + (float)((float)(clipModel[19] * this->offset.z)
                                 + (float)((float)(clipModel[13] * this->offset.x)
                                         + (float)(clipModel[16] * this->offset.y))))
                 - v6[10]);
      v16 = (float)(clipModel[9]
                  + (float)((float)(clipModel[18] * this->offset.z)
                          + (float)((float)(clipModel[12] * this->offset.x) + (float)(clipModel[15] * this->offset.y))))
          - v6[9];
      v17 = v8;
    }
    else
    {
      v9 = (float *)body1->clipModel;
      v10 = (float)(this->offset.z - v9[10]);
      v7 = (float)(this->offset.x - v9[8]);
      v16 = this->offset.y - v9[9];
      v17 = v10;
    }
    v15 = v7;
    v11 = common->RW(this: common);
    v12 = (float *)this->body1->clipModel;
    v13 = (float)((float)(v12[19] * this->axis.z)
                + (float)((float)(v12[13] * this->axis.x) + (float)(v12[16] * this->axis.y)));
    v14 = (float)((float)((float)(v12[18] * this->axis.z)
                        + (float)((float)(v12[12] * this->axis.x) + (float)(v12[15] * this->axis.y)))
                + v16);
    v18[0] = (float)((float)(v12[11] * this->axis.x)
                   + (float)((float)(v12[14] * this->axis.y) + (float)(v12[17] * this->axis.z)))
           + v15;
    v18[1] = v14;
    v18[2] = (float)v13 + v17;
    v11->DebugLine(
      this: v11,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idVec3 *)&v15,
      a4: (const idVec3 *)v18,
      a5: 0,
      a6: false);
  }
}


// ========================================================================
// ?SetAnchor@idAFConstraint_Spring@@QAAXABVidVec3@@0@Z
// EA  : 0x8271E6B0
// RVA : 0x0071E6B0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Spring::SetAnchor(
        idAFConstraint_Spring *this,
        const idVec3 *worldAnchor1,
        const idVec3 *worldAnchor2)
{
  idAFBody *body1; // r11
  float *clipModel; // r11
  double v5; // fp2
  double v6; // fp13
  double v7; // fp12
  double v8; // fp1
  double v9; // fp0
  idAFBody *body2; // r11
  float *v11; // r11
  double v12; // fp2
  double v13; // fp13
  double v14; // fp12
  double v15; // fp1
  double v16; // fp0

  body1 = this->body1;
  if ( body1 != nullptr )
  {
    clipModel = (float *)body1->clipModel;
    v5 = (float)(worldAnchor1->x - clipModel[8]);
    v6 = clipModel[17];
    v7 = clipModel[14];
    v8 = (float)((float)((float)(worldAnchor1->y - clipModel[9]) * clipModel[15])
               + (float)((float)(worldAnchor1->z - clipModel[10]) * clipModel[16]));
    v9 = (float)((float)((float)(worldAnchor1->y - clipModel[9]) * clipModel[18])
               + (float)((float)(worldAnchor1->z - clipModel[10]) * clipModel[19]));
    this->anchor1.x = (float)((float)(worldAnchor1->x - clipModel[8]) * clipModel[11])
                    + (float)((float)((float)(worldAnchor1->y - clipModel[9]) * clipModel[12])
                            + (float)((float)(worldAnchor1->z - clipModel[10]) * clipModel[13]));
    this->anchor1.y = (float)((float)v5 * (float)v7) + (float)v8;
    this->anchor1.z = (float)((float)v5 * (float)v6) + (float)v9;
    body2 = this->body2;
    if ( body2 != nullptr )
    {
      v11 = (float *)body2->clipModel;
      v12 = (float)(worldAnchor2->x - v11[8]);
      v13 = v11[17];
      v14 = v11[14];
      v15 = (float)((float)((float)(worldAnchor2->y - v11[9]) * v11[15])
                  + (float)((float)(worldAnchor2->z - v11[10]) * v11[16]));
      v16 = (float)((float)((float)(worldAnchor2->y - v11[9]) * v11[18])
                  + (float)((float)(worldAnchor2->z - v11[10]) * v11[19]));
      this->anchor2.x = (float)((float)(worldAnchor2->x - v11[8]) * v11[11])
                      + (float)((float)((float)(worldAnchor2->y - v11[9]) * v11[12])
                              + (float)((float)(worldAnchor2->z - v11[10]) * v11[13]));
      this->anchor2.y = (float)((float)v12 * (float)v14) + (float)v15;
      this->anchor2.z = (float)((float)v12 * (float)v13) + (float)v16;
    }
    else
    {
      this->anchor2 = *worldAnchor2;
    }
  }
}


// ========================================================================
// ?Evaluate@idAFConstraint_Spring@@MAAXPBVidPhysics_AF@@M@Z
// EA  : 0x8271E7E0
// RVA : 0x0071E7E0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Spring::Evaluate(
        idAFConstraint_Spring *this,
        const idPhysics_AF *phys,
        double invTimeStep)
{
  double LcpEpsilon; // fp1
  float *p; // r11
  idAFBody *body2; // r30
  idPhysics_AF *physics; // r11
  idAFBody *body1; // r4
  float *clipModel; // r11
  double v12; // fp13
  double v13; // fp4
  double v14; // fp2
  float *PointVelocity; // r3
  double v16; // fp31
  double v17; // fp30
  double v18; // fp29
  double y; // fp13
  float *v20; // r11
  double v21; // fp13
  double v22; // fp4
  double v23; // fp3
  float *v24; // r3
  double v25; // fp7
  double v26; // fp9
  double v27; // fp10
  double z; // fp12
  double v29; // fp0
  double v30; // fp7
  double restLength; // fp9
  double v34; // fp3
  double v35; // fp6
  double v36; // fp3
  double v37; // fp28
  double v38; // fp31
  double v39; // fp30
  double v40; // fp29
  double kstretch; // fp0
  idAFBody *v42; // r3
  const idVec3 *v43; // r5
  double kcompress; // fp0
  idAFBody *v45; // r3
  char v46; // r11
  double v47; // fp28
  double maxLength; // fp0
  idSpatialMat *p_J1; // r3
  idClipModel *v50; // r11
  float *mat; // r10
  float *v52; // r11
  double v53; // fp12
  double x; // fp13
  double v55; // fp5
  double v56; // fp3
  idAFBody *v57; // r11
  float *v58; // r11
  float *v59; // r11
  double v60; // fp0
  float *v61; // r11
  double v62; // fp13
  double v63; // fp1
  double v64; // fp11
  float *v65; // r30
  double ErrorReductionMax; // fp31
  double v67; // fp1
  idVec3 v68; // [sp+50h] [-C0h] BYREF
  idVec3 v69; // [sp+60h] [-B0h] BYREF
  idVec3 v70; // [sp+70h] [-A0h] BYREF
  idVec3 v71; // [sp+80h] [-90h] BYREF
  float v72[4]; // [sp+90h] [-80h] BYREF
  float v73[4]; // [sp+A0h] [-70h] BYREF
  _BYTE v74[64]; // [sp+B0h] [-60h] BYREF

  if ( this->body1 == nullptr )
    return;
  LcpEpsilon = idPhysics_AF::GetLcpEpsilon(this: phys);
  p = this->e.p;
  *p = LcpEpsilon;
  p[1] = LcpEpsilon;
  p[2] = LcpEpsilon;
  p[3] = LcpEpsilon;
  p[4] = LcpEpsilon;
  p[5] = LcpEpsilon;
  body2 = this->body2;
  if ( body2 == nullptr )
  {
    physics = this->physics;
    if ( physics != nullptr )
      body2 = physics->masterBody;
  }
  body1 = this->body1;
  clipModel = (float *)body1->clipModel;
  v12 = clipModel[10];
  v13 = (float)((float)(clipModel[19] * this->anchor1.z)
              + (float)((float)(clipModel[13] * this->anchor1.x) + (float)(clipModel[16] * this->anchor1.y)));
  v14 = (float)(clipModel[9]
              + (float)((float)(clipModel[18] * this->anchor1.z)
                      + (float)((float)(clipModel[12] * this->anchor1.x) + (float)(clipModel[15] * this->anchor1.y))));
  v69.x = clipModel[8]
        + (float)((float)(this->anchor1.x * clipModel[11])
                + (float)((float)(clipModel[14] * this->anchor1.y) + (float)(clipModel[17] * this->anchor1.z)));
  v69.y = v14;
  v69.z = (float)v12 + (float)v13;
  PointVelocity = (float *)idAFBody::GetPointVelocity(this: (idAFBody *)v74, result: (const idVec3 *)body1, point: &v69);
  v16 = *PointVelocity;
  v17 = PointVelocity[1];
  v18 = PointVelocity[2];
  y = this->anchor2.y;
  if ( body2 != nullptr )
  {
    v20 = (float *)body2->clipModel;
    v22 = (float)((float)(v20[19] * this->anchor2.z)
                + (float)((float)(v20[13] * this->anchor2.x) + (float)(v20[16] * this->anchor2.y)));
    v23 = (float)(v20[8]
                + (float)((float)(v20[11] * this->anchor2.x)
                        + (float)((float)(v20[14] * this->anchor2.y) + (float)(v20[17] * this->anchor2.z))));
    v21 = v20[10];
    v68.y = v20[9]
          + (float)((float)(v20[18] * this->anchor2.z)
                  + (float)((float)(v20[12] * this->anchor2.x) + (float)(v20[15] * this->anchor2.y)));
    v68.x = v23;
    v68.z = (float)v21 + (float)v22;
    v24 = (float *)idAFBody::GetPointVelocity(this: (idAFBody *)v74, result: (const idVec3 *)body2, point: &v68);
    v25 = *v24;
    v26 = v24[1];
    v27 = v24[2];
  }
  else
  {
    v27 = 0.0;
    z = this->anchor2.z;
    v26 = 0.0;
    v68.x = this->anchor2.x;
    v25 = 0.0;
    v68.y = y;
    v68.z = z;
  }
  v29 = (float)((float)((float)(v68.y - v69.y) * (float)(v68.y - v69.y))
              + (float)((float)((float)(v68.x - v69.x) * (float)(v68.x - v69.x))
                      + (float)((float)(v68.z - v69.z) * (float)(v68.z - v69.z))));
  if ( __fabs(v29) <= idMath::FLT_SMALLEST_NON_DENORMAL )
    v30 = 0.0;
  else
    v30 = (float)((float)__fabs((float)((float)((float)((float)v26 - (float)v17) * (float)(v68.y - v69.y))
                                      + (float)((float)((float)((float)v25 - (float)v16) * (float)(v68.x - v69.x))
                                              + (float)((float)((float)v27 - (float)v18) * (float)(v68.z - v69.z)))))
                * (float)(this->damping
                        / (float)((float)((float)(v68.y - v69.y) * (float)(v68.y - v69.y))
                                + (float)((float)((float)(v68.x - v69.x) * (float)(v68.x - v69.x))
                                        + (float)((float)(v68.z - v69.z) * (float)(v68.z - v69.z))))));
  _FP6 = (float)((float)((float)((float)(v68.y - v69.y) * (float)(v68.y - v69.y))
                       + (float)((float)((float)(v68.x - v69.x) * (float)(v68.x - v69.x))
                               + (float)((float)(v68.z - v69.z) * (float)(v68.z - v69.z))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  restLength = this->restLength;
  __asm { fsel      f4, f6, f0, f8 }
  v34 = __frsqrte(_FP4);
  v35 = (float)((float)-(float)((float)((float)((float)v34
                                              * (float)((float)((float)((float)(v68.y - v69.y) * (float)(v68.y - v69.y))
                                                              + (float)((float)((float)(v68.x - v69.x)
                                                                              * (float)(v68.x - v69.x))
                                                                      + (float)((float)(v68.z - v69.z)
                                                                              * (float)(v68.z - v69.z))))
                                                      * (float)0.5))
                                      * (float)v34)
                              - (float)1.5)
              * (float)v34);
  v36 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v34
                                                                              * (float)((float)v29 * (float)0.5))
                                                                      * (float)v34)
                                                              - (float)1.5)
                                              * (float)v34)
                                      * (float)((float)v29 * (float)0.5))
                              * (float)((float)-(float)((float)((float)((float)v34 * (float)((float)v29 * (float)0.5))
                                                              * (float)v34)
                                                      - (float)1.5)
                                      * (float)v34))
                      - (float)1.5);
  v37 = (float)((float)((float)-(float)((float)((float)((float)((float)v36 * (float)v35)
                                                      * (float)((float)v29 * (float)0.5))
                                              * (float)((float)v36 * (float)v35))
                                      - (float)1.5)
                      * (float)((float)v36 * (float)v35))
              * (float)v29);
  v38 = (float)((float)((float)-(float)((float)((float)((float)((float)v36 * (float)v35)
                                                      * (float)((float)((float)((float)(v68.y - v69.y)
                                                                              * (float)(v68.y - v69.y))
                                                                      + (float)((float)((float)(v68.x - v69.x)
                                                                                      * (float)(v68.x - v69.x))
                                                                              + (float)((float)(v68.z - v69.z)
                                                                                      * (float)(v68.z - v69.z))))
                                                              * (float)0.5))
                                              * (float)((float)v36 * (float)v35))
                                      - (float)1.5)
                      * (float)((float)v36 * (float)v35))
              * (float)(v68.x - v69.x));
  v39 = (float)((float)(v68.y - v69.y)
              * (float)((float)-(float)((float)((float)((float)((float)v36 * (float)v35)
                                                      * (float)((float)((float)((float)(v68.y - v69.y)
                                                                              * (float)(v68.y - v69.y))
                                                                      + (float)((float)((float)(v68.x - v69.x)
                                                                                      * (float)(v68.x - v69.x))
                                                                              + (float)((float)(v68.z - v69.z)
                                                                                      * (float)(v68.z - v69.z))))
                                                              * (float)0.5))
                                              * (float)((float)v36 * (float)v35))
                                      - (float)1.5)
                      * (float)((float)v36 * (float)v35)));
  v40 = (float)((float)(v68.z - v69.z)
              * (float)((float)-(float)((float)((float)((float)((float)v36 * (float)v35)
                                                      * (float)((float)((float)((float)(v68.y - v69.y)
                                                                              * (float)(v68.y - v69.y))
                                                                      + (float)((float)((float)(v68.x - v69.x)
                                                                                      * (float)(v68.x - v69.x))
                                                                              + (float)((float)(v68.z - v69.z)
                                                                                      * (float)(v68.z - v69.z))))
                                                              * (float)0.5))
                                              * (float)((float)v36 * (float)v35))
                                      - (float)1.5)
                      * (float)((float)v36 * (float)v35)));
  if ( v37 <= restLength )
  {
    kcompress = this->kcompress;
    if ( kcompress <= 0.0 )
      goto LABEL_19;
    v45 = this->body1;
    v71.x = (float)-(float)((float)((float)((float)(this->restLength - (float)v37)
                                          * (float)(this->restLength - (float)v37))
                                  * this->kcompress)
                          - (float)v30)
          * (float)((float)((float)-(float)((float)((float)((float)((float)v36 * (float)v35)
                                                          * (float)((float)((float)((float)(v68.y - v69.y)
                                                                                  * (float)(v68.y - v69.y))
                                                                          + (float)((float)((float)(v68.x - v69.x)
                                                                                          * (float)(v68.x - v69.x))
                                                                                  + (float)((float)(v68.z - v69.z)
                                                                                          * (float)(v68.z - v69.z))))
                                                                  * (float)0.5))
                                                  * (float)((float)v36 * (float)v35))
                                          - (float)1.5)
                          * (float)((float)v36 * (float)v35))
                  * (float)(v68.x - v69.x));
    v71.y = (float)((float)(v68.y - v69.y)
                  * (float)((float)-(float)((float)((float)((float)((float)v36 * (float)v35)
                                                          * (float)((float)((float)((float)(v68.y - v69.y)
                                                                                  * (float)(v68.y - v69.y))
                                                                          + (float)((float)((float)(v68.x - v69.x)
                                                                                          * (float)(v68.x - v69.x))
                                                                                  + (float)((float)(v68.z - v69.z)
                                                                                          * (float)(v68.z - v69.z))))
                                                                  * (float)0.5))
                                                  * (float)((float)v36 * (float)v35))
                                          - (float)1.5)
                          * (float)((float)v36 * (float)v35)))
          * (float)-(float)((float)((float)((float)((float)restLength - (float)v37)
                                          * (float)((float)restLength - (float)v37))
                                  * (float)kcompress)
                          - (float)v30);
    v71.z = (float)((float)(v68.z - v69.z)
                  * (float)((float)-(float)((float)((float)((float)((float)v36 * (float)v35)
                                                          * (float)((float)((float)((float)(v68.y - v69.y)
                                                                                  * (float)(v68.y - v69.y))
                                                                          + (float)((float)((float)(v68.x - v69.x)
                                                                                          * (float)(v68.x - v69.x))
                                                                                  + (float)((float)(v68.z - v69.z)
                                                                                          * (float)(v68.z - v69.z))))
                                                                  * (float)0.5))
                                                  * (float)((float)v36 * (float)v35))
                                          - (float)1.5)
                          * (float)((float)v36 * (float)v35)))
          * (float)-(float)((float)((float)((float)((float)restLength - (float)v37)
                                          * (float)((float)restLength - (float)v37))
                                  * (float)kcompress)
                          - (float)v30);
    idAFBody::AddForce(this: v45, point: &v69, force: &v71);
    if ( body2 == nullptr )
      goto LABEL_19;
    v43 = (const idVec3 *)v73;
    v73[0] = -v71.x;
    v73[1] = -v71.y;
    v73[2] = -v71.z;
  }
  else
  {
    kstretch = this->kstretch;
    if ( kstretch <= 0.0 )
      goto LABEL_19;
    v42 = this->body1;
    v70.x = (float)((float)((float)((float)((float)v37 - this->restLength) * (float)((float)v37 - this->restLength))
                          * this->kstretch)
                  - (float)v30)
          * (float)((float)((float)-(float)((float)((float)((float)((float)v36 * (float)v35)
                                                          * (float)((float)((float)((float)(v68.y - v69.y)
                                                                                  * (float)(v68.y - v69.y))
                                                                          + (float)((float)((float)(v68.x - v69.x)
                                                                                          * (float)(v68.x - v69.x))
                                                                                  + (float)((float)(v68.z - v69.z)
                                                                                          * (float)(v68.z - v69.z))))
                                                                  * (float)0.5))
                                                  * (float)((float)v36 * (float)v35))
                                          - (float)1.5)
                          * (float)((float)v36 * (float)v35))
                  * (float)(v68.x - v69.x));
    v70.y = (float)((float)(v68.y - v69.y)
                  * (float)((float)-(float)((float)((float)((float)((float)v36 * (float)v35)
                                                          * (float)((float)((float)((float)(v68.y - v69.y)
                                                                                  * (float)(v68.y - v69.y))
                                                                          + (float)((float)((float)(v68.x - v69.x)
                                                                                          * (float)(v68.x - v69.x))
                                                                                  + (float)((float)(v68.z - v69.z)
                                                                                          * (float)(v68.z - v69.z))))
                                                                  * (float)0.5))
                                                  * (float)((float)v36 * (float)v35))
                                          - (float)1.5)
                          * (float)((float)v36 * (float)v35)))
          * (float)((float)((float)((float)((float)v37 - (float)restLength) * (float)((float)v37 - (float)restLength))
                          * (float)kstretch)
                  - (float)v30);
    v70.z = (float)((float)(v68.z - v69.z)
                  * (float)((float)-(float)((float)((float)((float)((float)v36 * (float)v35)
                                                          * (float)((float)((float)((float)(v68.y - v69.y)
                                                                                  * (float)(v68.y - v69.y))
                                                                          + (float)((float)((float)(v68.x - v69.x)
                                                                                          * (float)(v68.x - v69.x))
                                                                                  + (float)((float)(v68.z - v69.z)
                                                                                          * (float)(v68.z - v69.z))))
                                                                  * (float)0.5))
                                                  * (float)((float)v36 * (float)v35))
                                          - (float)1.5)
                          * (float)((float)v36 * (float)v35)))
          * (float)((float)((float)((float)((float)v37 - (float)restLength) * (float)((float)v37 - (float)restLength))
                          * (float)kstretch)
                  - (float)v30);
    idAFBody::AddForce(this: v42, point: &v69, force: &v70);
    if ( body2 == nullptr )
      goto LABEL_19;
    v43 = (const idVec3 *)v72;
    v72[0] = -v70.x;
    v72[1] = -v70.y;
    v72[2] = -v70.z;
  }
  idAFBody::AddForce(this: body2, point: &v68, force: v43);
LABEL_19:
  if ( v37 >= this->minLength )
  {
    maxLength = this->maxLength;
    if ( maxLength <= 0.0 || v37 <= maxLength )
    {
      v47 = 0.0;
      v46 = 0;
    }
    else
    {
      v47 = (float)((float)v37 - this->maxLength);
      v46 = 1;
    }
  }
  else
  {
    v38 = -v38;
    v46 = 1;
    v39 = -v39;
    v40 = -v40;
    v47 = (float)(this->minLength - (float)v37);
  }
  p_J1 = &this->J1;
  if ( v46 != 0 )
  {
    v50 = this->body1->clipModel;
    v69.x = v69.x - v50->origin.x;
    v69.y = v69.y - v50->origin.y;
    v69.z = v69.z - v50->origin.z;
    idSpatialMat::SetSize(this: p_J1, rows: 1, columns: 6);
    mat = this->J1.mat;
    *mat = v38;
    mat[1] = v39;
    mat[2] = v40;
    v52 = this->J1.mat;
    v53 = v69.y;
    x = v69.x;
    v55 = (float)((float)v39 * v69.z);
    v56 = (float)(v69.y * (float)v38);
    v52[4] = (float)(v69.z * (float)v38) - (float)((float)v40 * v69.x);
    v52[3] = (float)((float)v40 * (float)v53) - (float)v55;
    v52[5] = (float)((float)v39 * (float)x) - (float)v56;
    v57 = this->body2;
    if ( v57 != nullptr )
    {
      v58 = (float *)v57->clipModel;
      v68.x = v68.x - v58[8];
      v68.y = v68.y - v58[9];
      v68.z = v68.z - v58[10];
      idSpatialMat::SetSize(this: &this->J2, rows: 1, columns: 6);
      v59 = this->J2.mat;
      v59[2] = -v40;
      v59[1] = -v39;
      *v59 = -v38;
      v60 = v68.z;
      v61 = this->J2.mat;
      v62 = v68.x;
      v63 = (float)(v68.x * (float)-v40);
      v64 = (float)(v68.y * (float)-v38);
      v61[3] = (float)(v68.y * (float)-v40) - (float)(v68.z * (float)-v39);
      v61[4] = (float)((float)v60 * (float)-v38) - (float)v63;
      v61[5] = (float)((float)v62 * (float)-v39) - (float)v64;
    }
    v65 = this->c1.p;
    *v65 = -(float)((float)(idPhysics_AF::GetErrorReduction(this: phys) * (float)invTimeStep) * (float)v47);
    *this->lo.p = 0.0;
  }
  else
  {
    idSpatialMat::Zero(this: p_J1, rows: 0, columns: 0);
    idSpatialMat::Zero(this: &this->J2, rows: 0, columns: 0);
  }
  ErrorReductionMax = idPhysics_AF::GetErrorReductionMax(this: phys);
  v67 = idPhysics_AF::GetErrorReductionMax(this: phys);
  idSpatialVec::Clamp(this: &this->c1, min: -v67, max: ErrorReductionMax);
}


// ========================================================================
// ?GetCenter@idAFConstraint_Spring@@UAAXAAVidVec3@@@Z
// EA  : 0x8271ED78
// RVA : 0x0071ED78
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Spring::GetCenter(idAFConstraint_Spring *this, idVec3 *center)
{
  void *body2; // r11
  float *clipModel; // r9
  double y; // fp13
  float *v5; // r11
  double x; // fp0
  double z; // fp12
  double v8; // fp10
  double v9; // fp9

  if ( this->body1 != nullptr )
  {
    body2 = this->body2;
    if ( body2 == nullptr )
    {
      body2 = (void *)this->physics;
      if ( body2 != nullptr )
        body2 = *((void **)body2 + 190);
    }
    clipModel = (float *)this->body1->clipModel;
    y = this->anchor2.y;
    if ( body2 != nullptr )
    {
      v5 = *((float **)body2 + 5);
      x = (float)(v5[8]
                + (float)((float)(this->anchor2.x * v5[11])
                        + (float)((float)(v5[14] * this->anchor2.y) + (float)(v5[17] * this->anchor2.z))));
      z = (float)(v5[10]
                + (float)((float)(v5[19] * this->anchor2.z)
                        + (float)((float)(v5[13] * this->anchor2.x) + (float)(v5[16] * this->anchor2.y))));
      y = (float)(v5[9]
                + (float)((float)(v5[18] * this->anchor2.z)
                        + (float)((float)(v5[12] * this->anchor2.x) + (float)(v5[15] * this->anchor2.y))));
    }
    else
    {
      x = this->anchor2.x;
      z = this->anchor2.z;
    }
    v8 = (float)((float)y
               + (float)(clipModel[9]
                       + (float)((float)(clipModel[18] * this->anchor1.z)
                               + (float)((float)(clipModel[12] * this->anchor1.x)
                                       + (float)(clipModel[15] * this->anchor1.y)))));
    v9 = (float)((float)z
               + (float)(clipModel[10]
                       + (float)((float)(clipModel[19] * this->anchor1.z)
                               + (float)((float)(clipModel[13] * this->anchor1.x)
                                       + (float)(clipModel[16] * this->anchor1.y)))));
    center->x = (float)((float)x
                      + (float)(clipModel[8]
                              + (float)((float)(clipModel[11] * this->anchor1.x)
                                      + (float)((float)(clipModel[14] * this->anchor1.y)
                                              + (float)(clipModel[17] * this->anchor1.z)))))
              * (float)0.5;
    center->y = (float)v8 * (float)0.5;
    center->z = (float)v9 * (float)0.5;
  }
  else
  {
    center->z = 0.0;
    center->y = 0.0;
    center->x = 0.0;
  }
}


// ========================================================================
// ?DebugDraw@idAFConstraint_Spring@@UAAXXZ
// EA  : 0x8271EF00
// RVA : 0x0071EF00
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Spring::DebugDraw(idAFConstraint_Spring *this)
{
  void *body2; // r11
  float *clipModel; // r9
  double v4; // fp13
  double v5; // fp4
  double v6; // fp12
  double v7; // fp11
  double v8; // fp10
  double y; // fp13
  float *v10; // r11
  double x; // fp0
  double z; // fp9
  double v13; // fp9
  double v14; // fp8
  double v15; // fp7
  double v16; // fp28
  double v17; // fp29
  double v18; // fp30
  double v19; // fp20
  double v21; // fp12
  double v23; // fp10
  double v24; // fp13
  double v25; // fp12
  double v26; // fp19
  idRenderWorld *v27; // r3
  double v28; // fp23
  double v29; // fp22
  double v30; // fp21
  idRenderWorld *v31; // r3
  double v32; // fp26
  double v33; // fp25
  double v34; // fp24
  idRenderWorld *v35; // r3
  double v36; // fp23
  double v37; // fp22
  double v38; // fp21
  idRenderWorld *v39; // r3
  idRenderWorld *v40; // r3
  idRenderWorld *v41; // r3
  double v42; // fp8
  double v43; // fp6
  idRenderWorld *v44; // r3
  double v45; // fp9
  double v46; // fp7
  idRenderWorld *v47; // r3
  double v48; // fp7
  double v49; // fp5
  idRenderWorld *v50; // r3
  double v51; // fp9
  double v52; // fp7
  float v53; // [sp+50h] [-140h] BYREF
  float v54; // [sp+54h] [-13Ch]
  float v55; // [sp+58h] [-138h]
  float v56[4]; // [sp+60h] [-130h] BYREF
  float v57[4]; // [sp+70h] [-120h] BYREF
  float v58[4]; // [sp+80h] [-110h] BYREF
  float v59[4]; // [sp+90h] [-100h] BYREF
  float v60[4]; // [sp+A0h] [-F0h] BYREF
  float v61[4]; // [sp+B0h] [-E0h] BYREF
  float v62[4]; // [sp+C0h] [-D0h] BYREF
  float v63[4]; // [sp+D0h] [-C0h] BYREF
  float v64[4]; // [sp+E0h] [-B0h] BYREF
  float v65[32]; // [sp+F0h] [-A0h] BYREF

  if ( this->body1 != nullptr )
  {
    body2 = this->body2;
    if ( body2 == nullptr )
    {
      body2 = (void *)this->physics;
      if ( body2 != nullptr )
        body2 = *((void **)body2 + 190);
    }
    clipModel = (float *)this->body1->clipModel;
    v4 = clipModel[10];
    v5 = (float)((float)(clipModel[19] * this->anchor1.z)
               + (float)((float)(clipModel[13] * this->anchor1.x) + (float)(clipModel[16] * this->anchor1.y)));
    v6 = (float)(clipModel[8]
               + (float)((float)(this->anchor1.x * clipModel[11])
                       + (float)((float)(clipModel[14] * this->anchor1.y) + (float)(clipModel[17] * this->anchor1.z))));
    v7 = (float)(clipModel[9]
               + (float)((float)(clipModel[18] * this->anchor1.z)
                       + (float)((float)(clipModel[12] * this->anchor1.x) + (float)(clipModel[15] * this->anchor1.y))));
    v57[0] = clipModel[8]
           + (float)((float)(this->anchor1.x * clipModel[11])
                   + (float)((float)(clipModel[14] * this->anchor1.y) + (float)(clipModel[17] * this->anchor1.z)));
    v57[1] = v7;
    v8 = (float)((float)v4 + (float)v5);
    y = this->anchor2.y;
    v57[2] = v8;
    if ( body2 != nullptr )
    {
      v10 = *((float **)body2 + 5);
      x = (float)(v10[8]
                + (float)((float)(this->anchor2.x * v10[11])
                        + (float)((float)(v10[14] * (float)y) + (float)(v10[17] * this->anchor2.z))));
      z = (float)(v10[10]
                + (float)((float)(v10[19] * this->anchor2.z)
                        + (float)((float)(v10[13] * this->anchor2.x) + (float)(v10[16] * (float)y))));
      y = (float)(v10[9]
                + (float)((float)(v10[18] * this->anchor2.z)
                        + (float)((float)(v10[12] * this->anchor2.x) + (float)(v10[15] * (float)y))));
    }
    else
    {
      x = this->anchor2.x;
      z = this->anchor2.z;
    }
    v56[2] = z;
    v13 = (float)((float)z - (float)v8);
    v14 = (float)((float)x - (float)v6);
    v15 = (float)((float)y - (float)v7);
    v56[1] = y;
    v56[0] = x;
    v16 = (float)((float)((float)v13 * (float)0.5) + (float)v8);
    v17 = (float)((float)((float)((float)y - (float)v7) * (float)0.5) + (float)v7);
    v18 = (float)((float)((float)((float)x - (float)v6) * (float)0.5) + (float)v6);
    v19 = (float)((float)((float)((float)y - (float)v7) * (float)((float)y - (float)v7))
                + (float)((float)((float)((float)x - (float)v6) * (float)((float)x - (float)v6))
                        + (float)((float)v13 * (float)v13)));
    _FP1 = (float)((float)((float)((float)((float)y - (float)v7) * (float)((float)y - (float)v7))
                         + (float)((float)((float)((float)x - (float)v6) * (float)((float)x - (float)v6))
                                 + (float)((float)v13 * (float)v13)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v21 = (float)((float)((float)((float)((float)y - (float)v7) * (float)((float)y - (float)v7))
                        + (float)((float)((float)((float)x - (float)v6) * (float)((float)x - (float)v6))
                                + (float)((float)v13 * (float)v13)))
                * (float)0.5);
    __asm { fsel      f11, f1, f20, f13 }
    v23 = __frsqrte(_FP11);
    v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)v21)
                                                                                * (float)v23)
                                                                        - (float)1.5)
                                                        * (float)v23)
                                                * (float)v21)
                                        * (float)((float)-(float)((float)((float)((float)v23 * (float)v21) * (float)v23)
                                                                - (float)1.5)
                                                * (float)v23))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v23 * (float)v21) * (float)v23) - (float)1.5)
                        * (float)v23));
    v25 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23 * (float)v21)
                                                                                        * (float)v23)
                                                                                - (float)1.5)
                                                                * (float)v23)
                                                        * (float)v21)
                                                * (float)((float)-(float)((float)((float)((float)v23 * (float)v21)
                                                                                * (float)v23)
                                                                        - (float)1.5)
                                                        * (float)v23))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v23 * (float)v21) * (float)v23) - (float)1.5)
                                * (float)v23))
                * (float)v21);
    v26 = (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5) * (float)v24);
    v53 = (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5) * (float)v24) * (float)v14;
    v54 = (float)v15 * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5) * (float)v24);
    v55 = (float)v13 * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5) * (float)v24);
    v27 = common->RW(this: common);
    v27->DebugLine(
      this: v27,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idVec3 *)v57,
      a4: (const idVec3 *)v56,
      a5: 0,
      a6: false);
    v28 = (float)((float)(this->restLength * (float)0.5) * v53);
    v29 = (float)(v54 * (float)(this->restLength * (float)0.5));
    v30 = (float)(v55 * (float)(this->restLength * (float)0.5));
    v32 = (float)((float)((float)(this->restLength * (float)0.5) * v53) + (float)v18);
    v33 = (float)((float)(v54 * (float)(this->restLength * (float)0.5)) + (float)v17);
    v31 = common->RW(this: common);
    v64[0] = (float)v28 + (float)v18;
    v34 = (float)((float)v30 + (float)v16);
    v64[1] = (float)v29 + (float)v17;
    v64[2] = (float)v30 + (float)v16;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v31->DebugCircle)(
      a1: v31,
      a2: &idColor::colorWhite,
      a3: v64,
      a4: &v53,
      a5: 1.0);
    v35 = common->RW(this: common);
    v36 = (float)((float)v18 - (float)v28);
    v60[0] = v36;
    v37 = (float)((float)v17 - (float)v29);
    v60[1] = v37;
    v38 = (float)((float)v16 - (float)v30);
    v60[2] = v38;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v35->DebugCircle)(
      a1: v35,
      a2: &idColor::colorWhite,
      a3: v60,
      a4: &v53,
      a5: 1.0);
    if ( this->restLength > (double)(float)((float)v26 * (float)v19) )
    {
      v39 = common->RW(this: common);
      v58[0] = v32;
      v58[1] = v33;
      v58[2] = v34;
      v39->DebugLine(
        this: v39,
        a2: (const idVec4 *)&idColor::colorWhite,
        a3: (const idVec3 *)v56,
        a4: (const idVec3 *)v58,
        a5: 0,
        a6: false);
      v40 = common->RW(this: common);
      v62[0] = v36;
      v62[1] = v37;
      v62[2] = v38;
      v40->DebugLine(
        this: v40,
        a2: (const idVec4 *)&idColor::colorWhite,
        a3: (const idVec3 *)v57,
        a4: (const idVec3 *)v62,
        a5: 0,
        a6: false);
    }
    if ( this->minLength > 0.0 )
    {
      v41 = common->RW(this: common);
      v42 = (float)(v54 * (float)(this->minLength * (float)0.5));
      v43 = (float)((float)(v53 * (float)(this->minLength * (float)0.5)) + (float)v18);
      v59[2] = (float)(v55 * (float)(this->minLength * (float)0.5)) + (float)v16;
      v59[0] = v43;
      v59[1] = (float)v42 + (float)v17;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v41->DebugCircle)(
        a1: v41,
        a2: &idColor::colorBlue,
        a3: v59,
        a4: &v53,
        a5: 2.0);
      v44 = common->RW(this: common);
      v45 = (float)(v55 * (float)(this->minLength * (float)0.5));
      v46 = (float)((float)v17 - (float)(v54 * (float)(this->minLength * (float)0.5)));
      v61[0] = (float)v18 - (float)((float)(this->minLength * (float)0.5) * v53);
      v61[1] = v46;
      v61[2] = (float)v16 - (float)v45;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v44->DebugCircle)(
        a1: v44,
        a2: &idColor::colorBlue,
        a3: v61,
        a4: &v53,
        a5: 2.0);
    }
    if ( this->maxLength > 0.0 )
    {
      v47 = common->RW(this: common);
      v48 = (float)(v55 * (float)(this->maxLength * (float)0.5));
      v49 = (float)((float)(v54 * (float)(this->maxLength * (float)0.5)) + (float)v17);
      v63[0] = (float)((float)(this->maxLength * (float)0.5) * v53) + (float)v18;
      v63[1] = v49;
      v63[2] = (float)v48 + (float)v16;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v47->DebugCircle)(
        a1: v47,
        a2: &idColor::colorRed,
        a3: v63,
        a4: &v53,
        a5: 2.0);
      v50 = common->RW(this: common);
      v51 = (float)(v55 * (float)(this->maxLength * (float)0.5));
      v52 = (float)((float)v17 - (float)(v54 * (float)(this->maxLength * (float)0.5)));
      v65[0] = (float)v18 - (float)((float)(this->maxLength * (float)0.5) * v53);
      v65[1] = v52;
      v65[2] = (float)v16 - (float)v51;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v50->DebugCircle)(
        a1: v50,
        a2: &idColor::colorRed,
        a3: v65,
        a4: &v53,
        a5: 2.0);
    }
  }
}


// ========================================================================
// ??1idAFConstraint_Contact@@UAA@XZ
// EA  : 0x8271F4D0
// RVA : 0x0071F4D0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Contact::~idAFConstraint_Contact(idAFConstraint_Contact *this)
{
  idAFConstraint_ContactFriction *fc; // r3

  this->__vftable = (idAFConstraint_Contact_vtbl *)&idAFConstraint_Contact::`vftable';
  fc = this->fc;
  if ( fc != nullptr )
    ((void (__fastcall *)(idAFConstraint_ContactFriction *, int))fc->dtr_idAFConstraint)(a1: fc, a2: 1);
  idAFConstraint::~idAFConstraint(this);
}


// ========================================================================
// __unwind$258082
// EA  : 0x8271F540
// RVA : 0x0071F540
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_258082()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 112 + 132));
}


// ========================================================================
// ?Evaluate@idAFConstraint_UniversalJointFriction@@MAAXPBVidPhysics_AF@@M@Z
// EA  : 0x8271F568
// RVA : 0x0071F568
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_UniversalJointFriction::Evaluate(
        idAFConstraint_Contact *this,
        const idPhysics_AF *phys,
        double invTimeStep)
{
  double LcpEpsilon; // fp1
  float *p; // r11

  LcpEpsilon = idPhysics_AF::GetLcpEpsilon(this: phys);
  p = this->e.p;
  *p = LcpEpsilon;
  p[1] = LcpEpsilon;
  p[2] = LcpEpsilon;
  p[3] = LcpEpsilon;
  p[4] = LcpEpsilon;
  p[5] = LcpEpsilon;
}


// ========================================================================
// ?GetCenter@idAFConstraint_Contact@@UAAXAAVidVec3@@@Z
// EA  : 0x8271F5B8
// RVA : 0x0071F5B8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Contact::GetCenter(idAFConstraint_Contact *this, idVec3 *center)
{
  *center = this->contact.point;
}


// ========================================================================
// ?DebugDraw@idAFConstraint_Contact@@UAAXXZ
// EA  : 0x8271F5D8
// RVA : 0x0071F5D8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Contact::DebugDraw(idAFConstraint_Contact *this)
{
  idRenderWorld *v2; // r3
  double z; // fp7
  double v4; // fp5
  double v5; // fp3
  idRenderWorld *v6; // r3
  double x; // fp12
  double y; // fp11
  double v9; // fp9
  double v10; // fp5
  idRenderWorld *v11; // r3
  double v12; // fp8
  double v13; // fp7
  double v14; // fp6
  double v15; // fp4
  float v16[4]; // [sp+50h] [-A0h] BYREF
  idVec3 v17; // [sp+60h] [-90h] BYREF
  float v18[4]; // [sp+70h] [-80h] BYREF
  float v19[4]; // [sp+80h] [-70h] BYREF
  idVec3 v20; // [sp+90h] [-60h] BYREF
  float v21[4]; // [sp+A0h] [-50h] BYREF
  float v22[6]; // [sp+B0h] [-40h] BYREF

  idVec3::NormalVectors(this: &this->contact.normal, left: &v17, down: &v20);
  v2 = common->RW(this: common);
  z = this->contact.point.z;
  v4 = (float)(this->contact.normal.z * (float)6.0);
  v5 = (float)((float)(this->contact.normal.y * (float)6.0) + this->contact.point.y);
  v16[0] = this->contact.point.x + (float)(this->contact.normal.x * (float)6.0);
  v16[1] = v5;
  v16[2] = (float)v4 + (float)z;
  v2->DebugLine(
    this: v2,
    a2: (const idVec4 *)&idColor::colorWhite,
    a3: &this->contact.point,
    a4: (const idVec3 *)v16,
    a5: 0,
    a6: false);
  v6 = common->RW(this: common);
  x = this->contact.point.x;
  y = this->contact.point.y;
  v9 = this->contact.point.z;
  v10 = (float)(this->contact.point.y + (float)(v17.y * (float)2.0));
  v18[0] = this->contact.point.x + (float)(v17.x * (float)2.0);
  v18[1] = v10;
  v18[2] = (float)v9 + (float)(v17.z * (float)2.0);
  v19[0] = (float)x - (float)(v17.x * (float)2.0);
  v19[1] = (float)y - (float)(v17.y * (float)2.0);
  v19[2] = (float)v9 - (float)(v17.z * (float)2.0);
  v6->DebugLine(
    this: v6,
    a2: (const idVec4 *)&idColor::colorWhite,
    a3: (const idVec3 *)v19,
    a4: (const idVec3 *)v18,
    a5: 0,
    a6: false);
  v11 = common->RW(this: common);
  v12 = this->contact.point.x;
  v13 = this->contact.point.y;
  v14 = this->contact.point.z;
  v15 = (float)(this->contact.point.y + (float)(v20.y * (float)2.0));
  v21[0] = this->contact.point.x + (float)(v20.x * (float)2.0);
  v21[1] = v15;
  v22[0] = (float)v12 - (float)(v20.x * (float)2.0);
  v22[1] = (float)v13 - (float)(v20.y * (float)2.0);
  v21[2] = (float)v14 + (float)(v20.z * (float)2.0);
  v22[2] = (float)v14 - (float)(v20.z * (float)2.0);
  v11->DebugLine(
    this: v11,
    a2: (const idVec4 *)&idColor::colorWhite,
    a3: (const idVec3 *)v22,
    a4: (const idVec3 *)v21,
    a5: 0,
    a6: false);
}


// ========================================================================
// ?Setup@idAFConstraint_ConeLimit@@QAAXPAVidAFBody@@0ABVidVec3@@1M1@Z
// EA  : 0x8271F7B0
// RVA : 0x0071F7B0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_ConeLimit::Setup(
        idAFConstraint_ConeLimit *this,
        idAFBody *b1,
        idAFBody *b2,
        const idVec3 *coneAnchor,
        const idVec3 *coneAxis,
        double coneAngle,
        const idVec3 *body1Axis,
        float *a8)
{
  double x; // fp0
  double y; // fp13
  double v10; // fp8
  double z; // fp10
  double v12; // fp6
  double v17; // fp2
  double v18; // fp3
  double v19; // fp1
  double v20; // fp3
  double v21; // fp8
  double v22; // fp2
  double v23; // fp10
  double v26; // fp5
  double v27; // fp3
  double v28; // fp8
  long double v29; // fp2
  long double v30; // fp2
  double v31; // fp31
  long double v32; // fp2
  long double v33; // fp2

  this->body2 = b2;
  this->body1 = b1;
  x = coneAxis->x;
  this->coneAxis.x = coneAxis->x;
  y = coneAxis->y;
  v10 = (float)(coneAxis->y * coneAxis->y);
  this->coneAxis.y = coneAxis->y;
  z = coneAxis->z;
  v12 = (float)((float)(coneAxis->z * coneAxis->z) + (float)((float)((float)x * (float)x) + (float)v10));
  this->coneAxis.z = coneAxis->z;
  _FP5 = (float)((float)v12 - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f12 }
  v17 = __frsqrte(_FP3);
  v18 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)v12 * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17)
                                              * (float)((float)v12 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                              * (float)((float)v12 * (float)0.5))
                                                                      * (float)v17)
                                                              - (float)1.5)
                                              * (float)v17))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17)
                                      - (float)1.5)
                      * (float)v17));
  this->coneAxis.z = (float)z
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17) * (float)((float)v12 * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17)
                                                                                           - (float)1.5)
                                                                           * (float)v17))
                                                           * (float)((float)v12 * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17)
                                                                                           * (float)((float)v12 * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                           * (float)v17))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5))
                                                                                           * (float)v17)
                                                                                   - (float)1.5)
                                                                   * (float)v17)))
                                           - (float)1.5)
                           * (float)v18);
  this->coneAxis.y = (float)y
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17) * (float)((float)v12 * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17)
                                                                                           - (float)1.5)
                                                                           * (float)v17))
                                                           * (float)((float)v12 * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17)
                                                                                           * (float)((float)v12 * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                           * (float)v17))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5))
                                                                                           * (float)v17)
                                                                                   - (float)1.5)
                                                                   * (float)v17)))
                                           - (float)1.5)
                           * (float)v18);
  this->coneAxis.x = (float)x
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17) * (float)((float)v12 * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17)
                                                                                           - (float)1.5)
                                                                           * (float)v17))
                                                           * (float)((float)v12 * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17)
                                                                                           * (float)((float)v12 * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                           * (float)v17))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)v12 * (float)0.5))
                                                                                           * (float)v17)
                                                                                   - (float)1.5)
                                                                   * (float)v17)))
                                           - (float)1.5)
                           * (float)v18);
  this->coneAnchor = *coneAnchor;
  v19 = *a8;
  this->body1Axis.x = *a8;
  v20 = a8[1];
  v21 = (float)((float)((float)v19 * (float)v19) + (float)(a8[1] * a8[1]));
  this->body1Axis.y = a8[1];
  v22 = a8[2];
  v23 = v20;
  this->body1Axis.z = a8[2];
  _FP6 = (float)((float)((float)((float)v22 * (float)v22) + (float)v21) - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f12 }
  v26 = (float)((float)((float)((float)v22 * (float)v22) + (float)v21) * (float)0.5);
  v27 = __frsqrte(_FP4);
  v28 = (float)((float)-(float)((float)((float)((float)v27
                                              * (float)((float)((float)((float)v22 * (float)v22) + (float)v21)
                                                      * (float)0.5))
                                      * (float)v27)
                              - (float)1.5)
              * (float)v27);
  this->body1Axis.x = (float)v19
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)v26)
                                                                                            * (float)v28)
                                                                                    - (float)1.5)
                                                                    * (float)v28)
                                                            * (float)v26)
                                                    * (float)((float)-(float)((float)((float)((float)v28 * (float)v26)
                                                                                    * (float)v28)
                                                                            - (float)1.5)
                                                            * (float)v28))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v28 * (float)v26) * (float)v28) - (float)1.5)
                                    * (float)v28));
  this->body1Axis.y = (float)v23
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)v26)
                                                                                            * (float)v28)
                                                                                    - (float)1.5)
                                                                    * (float)v28)
                                                            * (float)v26)
                                                    * (float)((float)-(float)((float)((float)((float)v28 * (float)v26)
                                                                                    * (float)v28)
                                                                            - (float)1.5)
                                                            * (float)v28))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v28 * (float)v26) * (float)v28) - (float)1.5)
                                    * (float)v28));
  this->body1Axis.z = (float)v22
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)v26)
                                                                                            * (float)v28)
                                                                                    - (float)1.5)
                                                                    * (float)v28)
                                                            * (float)v26)
                                                    * (float)((float)-(float)((float)((float)((float)v28 * (float)v26)
                                                                                    * (float)v28)
                                                                            - (float)1.5)
                                                            * (float)v28))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v28 * (float)v26) * (float)v28) - (float)1.5)
                                    * (float)v28));
  *((double *)&v29 + 1) = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)v26)
                                                                                        * (float)v28)
                                                                                - (float)1.5)
                                                                * (float)v28)
                                                        * (float)v26)
                                                * (float)((float)-(float)((float)((float)((float)v28 * (float)v26)
                                                                                * (float)v28)
                                                                        - (float)1.5)
                                                        * (float)v28))
                                        - (float)1.5);
  *(double *)&v29 = (float)((float)((float)coneAngle * (float)0.5) * idMath::M_DEG2RAD);
  v30 = cos(x: v29);
  this->cosAngle = *(double *)&v30;
  v31 = (float)((float)coneAngle * (float)0.25);
  *(double *)&v30 = (float)((float)v31 * idMath::M_DEG2RAD);
  v32 = sin(x: v30);
  this->sinHalfAngle = *(double *)&v32;
  *(double *)&v32 = (float)((float)v31 * idMath::M_DEG2RAD);
  v33 = cos(x: v32);
  this->cosHalfAngle = *(double *)&v33;
}


// ========================================================================
// ?Add@idAFConstraint_ConeLimit@@QAA_NPAVidPhysics_AF@@M@Z
// EA  : 0x8271F980
// RVA : 0x0071F980
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

int __fastcall idAFConstraint_ConeLimit::Add(idAFConstraint_ConeLimit *this, idPhysics_AF *phys, double invTimeStep)
{
  idAFBody *body1; // r9
  idAFBody *body2; // r30
  float *clipModel; // r11
  double x; // fp31
  double y; // fp30
  double z; // fp29
  double v16; // fp20
  double v17; // fp21
  double v18; // fp19
  float *v19; // r11
  double v20; // fp27
  double v21; // fp26
  double v22; // fp25
  double v26; // fp4
  double v27; // fp2
  double v28; // fp1
  float *v29; // r3
  double v30; // fp28
  double v31; // fp23
  double v32; // fp22
  double v33; // fp10
  double v34; // fp9
  double v35; // fp6
  double v36; // fp5
  double v37; // fp24
  idClipModel *v38; // r11
  double v39; // fp23
  double v40; // fp22
  double v41; // fp17
  double v42; // fp16
  double v43; // fp15
  double v44; // fp30
  double v45; // fp29
  double v46; // fp9
  double v47; // fp28
  double v48; // fp8
  double v49; // fp7
  float *mat; // r8
  float *v51; // r11
  float *p; // r29
  double v53; // fp31
  double LimitErrorReductionMax; // fp27
  double v55; // fp0
  float *v56; // r11
  double v57; // fp27
  double v58; // fp26
  double v59; // fp25
  float *v60; // r11
  float *v61; // r11
  float *v62; // r30
  idVec3 v63; // [sp+50h] [-F0h] BYREF
  idMat3 v64[5]; // [sp+60h] [-E0h] BYREF

  if ( af_skipLimits.valueInteger != 0 )
  {
    __asm { vspltisw128 v63, 0 }
    _R10 = this->lm.p;
    _R9 = 16;
    __asm { stvx128   v63, r0, r10 }
    _R8 = _R10;
    __asm { stvx128   v63, r8, r9 }
    return 0;
  }
  else
  {
    body1 = this->body1;
    if ( body1 != nullptr && (this->physics = phys, phys != nullptr) )
    {
      body2 = this->body2;
      if ( body2 != nullptr || (body2 = phys->masterBody) != nullptr )
      {
        clipModel = (float *)body2->clipModel;
        x = (float)((float)(this->coneAxis.x * clipModel[11])
                  + (float)((float)(clipModel[14] * this->coneAxis.y) + (float)(clipModel[17] * this->coneAxis.z)));
        y = (float)((float)(clipModel[18] * this->coneAxis.z)
                  + (float)((float)(clipModel[12] * this->coneAxis.x) + (float)(clipModel[15] * this->coneAxis.y)));
        z = (float)((float)(clipModel[19] * this->coneAxis.z)
                  + (float)((float)(clipModel[13] * this->coneAxis.x) + (float)(clipModel[16] * this->coneAxis.y)));
        v16 = (float)(clipModel[9]
                    + (float)((float)(clipModel[18] * this->coneAnchor.z)
                            + (float)((float)(clipModel[12] * this->coneAnchor.x)
                                    + (float)(clipModel[15] * this->coneAnchor.y))));
        v17 = (float)(clipModel[8]
                    + (float)((float)(clipModel[11] * this->coneAnchor.x)
                            + (float)((float)(clipModel[14] * this->coneAnchor.y)
                                    + (float)(clipModel[17] * this->coneAnchor.z))));
        v18 = (float)(clipModel[10]
                    + (float)((float)(clipModel[19] * this->coneAnchor.z)
                            + (float)((float)(clipModel[13] * this->coneAnchor.x)
                                    + (float)(clipModel[16] * this->coneAnchor.y))));
      }
      else
      {
        x = this->coneAxis.x;
        y = this->coneAxis.y;
        z = this->coneAxis.z;
        v17 = this->coneAnchor.x;
        v16 = this->coneAnchor.y;
        v18 = this->coneAnchor.z;
      }
      v19 = (float *)body1->clipModel;
      v20 = (float)((float)(v19[19] * this->body1Axis.z)
                  + (float)((float)(v19[13] * this->body1Axis.x) + (float)(v19[16] * this->body1Axis.y)));
      v21 = (float)((float)(v19[11] * this->body1Axis.x)
                  + (float)((float)(v19[14] * this->body1Axis.y) + (float)(v19[17] * this->body1Axis.z)));
      v22 = (float)((float)(v19[18] * this->body1Axis.z)
                  + (float)((float)(v19[12] * this->body1Axis.x) + (float)(v19[15] * this->body1Axis.y)));
      if ( (float)((float)((float)((float)(v19[18] * this->body1Axis.z)
                                 + (float)((float)(v19[12] * this->body1Axis.x) + (float)(v19[15] * this->body1Axis.y)))
                         * (float)y)
                 + (float)((float)((float)((float)(v19[11] * this->body1Axis.x)
                                         + (float)((float)(v19[14] * this->body1Axis.y)
                                                 + (float)(v19[17] * this->body1Axis.z)))
                                 * (float)x)
                         + (float)((float)((float)(v19[19] * this->body1Axis.z)
                                         + (float)((float)(v19[13] * this->body1Axis.x)
                                                 + (float)(v19[16] * this->body1Axis.y)))
                                 * (float)z))) <= (double)this->cosAngle )
      {
        v63.x = (float)((float)((float)(v19[18] * this->body1Axis.z)
                              + (float)((float)(v19[12] * this->body1Axis.x) + (float)(v19[15] * this->body1Axis.y)))
                      * (float)z)
              - (float)((float)((float)(v19[19] * this->body1Axis.z)
                              + (float)((float)(v19[13] * this->body1Axis.x) + (float)(v19[16] * this->body1Axis.y)))
                      * (float)y);
        v63.y = (float)((float)v20 * (float)x) - (float)((float)z * (float)v21);
        v63.z = (float)((float)y * (float)v21) - (float)((float)v22 * (float)x);
        idVec3::NormalizeFast(this: &v63);
        v26 = (float)(this->sinHalfAngle * v63.x);
        v27 = (float)(this->sinHalfAngle * v63.y);
        v28 = (float)(this->sinHalfAngle * v63.z);
        v64[0].mat[1].x = this->cosHalfAngle;
        v64[0].mat[0].x = v26;
        v64[0].mat[0].y = v27;
        v64[0].mat[0].z = v28;
        v29 = (float *)idQuat::ToMat3(this: (idQuat *)&v64[0].mat[1].y, result: v64);
        v30 = (float)((float)(*v29 * (float)x) + (float)((float)(v29[6] * (float)z) + (float)(v29[3] * (float)y)));
        v31 = (float)((float)(v29[4] * (float)y) + (float)((float)(v29[1] * (float)x) + (float)(v29[7] * (float)z)));
        v32 = (float)((float)(v29[5] * (float)y) + (float)((float)(v29[2] * (float)x) + (float)(v29[8] * (float)z)));
        v33 = (float)((float)((float)((float)(v29[5] * (float)y)
                                    + (float)((float)(v29[2] * (float)x) + (float)(v29[8] * (float)z)))
                            * (float)x)
                    - (float)((float)z
                            * (float)((float)(*v29 * (float)x)
                                    + (float)((float)(v29[6] * (float)z) + (float)(v29[3] * (float)y)))));
        v34 = (float)((float)((float)y
                            * (float)((float)(*v29 * (float)x)
                                    + (float)((float)(v29[6] * (float)z) + (float)(v29[3] * (float)y))))
                    - (float)((float)((float)(v29[4] * (float)y)
                                    + (float)((float)(v29[1] * (float)x) + (float)(v29[7] * (float)z)))
                            * (float)x));
        v35 = (float)((float)((float)((float)y
                                    * (float)((float)(*v29 * (float)x)
                                            + (float)((float)(v29[6] * (float)z) + (float)(v29[3] * (float)y))))
                            - (float)((float)((float)(v29[4] * (float)y)
                                            + (float)((float)(v29[1] * (float)x) + (float)(v29[7] * (float)z)))
                                    * (float)x))
                    * (float)((float)(v29[4] * (float)y)
                            + (float)((float)(v29[1] * (float)x) + (float)(v29[7] * (float)z))));
        v36 = (float)((float)((float)(v29[5] * (float)y)
                            + (float)((float)(v29[2] * (float)x) + (float)(v29[8] * (float)z)))
                    * (float)((float)((float)((float)(v29[4] * (float)y)
                                            + (float)((float)(v29[1] * (float)x) + (float)(v29[7] * (float)z)))
                                    * (float)z)
                            - (float)((float)((float)(v29[5] * (float)y)
                                            + (float)((float)(v29[2] * (float)x) + (float)(v29[8] * (float)z)))
                                    * (float)y)));
        v63.z = (float)((float)((float)(v29[4] * (float)y)
                              + (float)((float)(v29[1] * (float)x) + (float)(v29[7] * (float)z)))
                      * (float)((float)((float)((float)(v29[4] * (float)y)
                                              + (float)((float)(v29[1] * (float)x) + (float)(v29[7] * (float)z)))
                                      * (float)z)
                              - (float)((float)((float)(v29[5] * (float)y)
                                              + (float)((float)(v29[2] * (float)x) + (float)(v29[8] * (float)z)))
                                      * (float)y)))
              - (float)((float)((float)((float)((float)(v29[5] * (float)y)
                                              + (float)((float)(v29[2] * (float)x) + (float)(v29[8] * (float)z)))
                                      * (float)x)
                              - (float)((float)z
                                      * (float)((float)(*v29 * (float)x)
                                              + (float)((float)(v29[6] * (float)z) + (float)(v29[3] * (float)y)))))
                      * (float)((float)(*v29 * (float)x)
                              + (float)((float)(v29[6] * (float)z) + (float)(v29[3] * (float)y))));
        v63.x = (float)((float)v33 * (float)v32) - (float)v35;
        v63.y = (float)((float)v34 * (float)v30) - (float)v36;
        idVec3::NormalizeFast(this: &v63);
        v37 = (float)((float)v30 * (float)32.0);
        v38 = this->body1->clipModel;
        v39 = (float)((float)v31 * (float)32.0);
        v40 = (float)((float)v32 * (float)32.0);
        v41 = (float)((float)((float)((float)v30 * (float)32.0) + (float)v17) - v38->origin.x);
        v42 = (float)((float)((float)v39 + (float)v16) - v38->origin.y);
        v43 = (float)((float)((float)v40 + (float)v18) - v38->origin.z);
        idSpatialMat::SetSize(this: &this->J1, rows: 1, columns: 6);
        v44 = v63.x;
        v45 = v63.y;
        v46 = (float)((float)v42 * v63.x);
        v47 = v63.z;
        v48 = (float)((float)v43 * v63.y);
        v49 = (float)((float)v41 * v63.z);
        mat = this->J1.mat;
        *mat = v63.x;
        mat[1] = v45;
        mat[2] = v47;
        v51 = this->J1.mat;
        v51[5] = (float)((float)v41 * (float)v45) - (float)v46;
        v51[3] = (float)((float)v42 * (float)v47) - (float)v48;
        v51[4] = (float)((float)v43 * (float)v44) - (float)v49;
        p = this->c1.p;
        *p = (float)(idPhysics_AF::GetLimitErrorReduction(this: this->physics) * (float)invTimeStep)
           * (float)((float)((float)((float)v21 * (float)32.0) * (float)v44)
                   + (float)((float)((float)((float)v20 * (float)32.0) * (float)v47)
                           + (float)((float)((float)v22 * (float)32.0) * (float)v45)));
        v53 = *this->c1.p;
        LimitErrorReductionMax = idPhysics_AF::GetLimitErrorReductionMax(this: this->physics);
        v55 = -idPhysics_AF::GetLimitErrorReductionMax(this: this->physics);
        if ( v53 >= v55 )
        {
          if ( v53 <= LimitErrorReductionMax )
            v55 = v53;
          else
            v55 = LimitErrorReductionMax;
        }
        *this->c1.p = v55;
        if ( this->body2 != nullptr && body2 != nullptr )
        {
          v56 = (float *)body2->clipModel;
          v57 = (float)((float)((float)v37 + (float)v17) - v56[8]);
          v58 = (float)((float)((float)v39 + (float)v16) - v56[9]);
          v59 = (float)((float)((float)v40 + (float)v18) - v56[10]);
          idSpatialMat::SetSize(this: &this->J2, rows: 1, columns: 6);
          v60 = this->J2.mat;
          *v60 = -v44;
          v60[1] = -v45;
          v60[2] = -v47;
          v61 = this->J2.mat;
          v61[5] = (float)((float)-v45 * (float)v57) - (float)((float)v58 * (float)-v44);
          v61[3] = (float)((float)-v47 * (float)v58) - (float)((float)-v45 * (float)v59);
          v61[4] = (float)((float)v59 * (float)-v44) - (float)((float)-v47 * (float)v57);
          *this->c2.p = 0.0;
        }
        *this->lo.p = 0.0;
        v62 = this->e.p;
        *v62 = idPhysics_AF::GetLimitLcpEpsilon(this: this->physics);
        idPhysics_AF::AddFrameConstraint(this: this->physics, constraint: this);
        return 1;
      }
      else
      {
        __asm { vspltisw128 v62, 0 }
        _R10 = this->lm.p;
        _R9 = 16;
        __asm { stvx128   v62, r0, r10 }
        _R8 = _R10;
        __asm { stvx128   v62, r8, r9 }
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
}


// ========================================================================
// ?Rotate@idAFConstraint_ConeLimit@@UAAXABVidRotation@@@Z
// EA  : 0x8271FE88
// RVA : 0x0071FE88
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_ConeLimit::Rotate(idAFConstraint_ConeLimit *this, idRotation *rotation)
{
  float *v4; // r3
  double z; // fp11
  double v6; // fp12
  double v7; // fp8
  double v8; // fp6
  double v9; // fp5
  char v10; // [sp+50h] [-30h] BYREF

  if ( this->body2 == nullptr )
  {
    this->coneAnchor = idRotation::operator*(this: (idRotation *)&v10, result: rotation, v: &this->coneAnchor)->origin;
    v4 = (float *)idRotation::ToMat3(this: rotation);
    z = this->coneAxis.z;
    v6 = v4[7];
    v7 = v4[8];
    v8 = (float)((float)(v4[1] * this->coneAxis.x) + (float)(v4[4] * this->coneAxis.y));
    v9 = (float)((float)(v4[2] * this->coneAxis.x) + (float)(v4[5] * this->coneAxis.y));
    this->coneAxis.x = (float)(*v4 * this->coneAxis.x)
                     + (float)((float)(v4[3] * this->coneAxis.y) + (float)(v4[6] * this->coneAxis.z));
    this->coneAxis.y = (float)((float)v6 * (float)z) + (float)v8;
    this->coneAxis.z = (float)((float)v7 * (float)z) + (float)v9;
  }
}


// ========================================================================
// ?Setup@idAFConstraint_PyramidLimit@@QAAXPAVidAFBody@@0ABVidVec3@@11MM1@Z
// EA  : 0x8271FF60
// RVA : 0x0071FF60
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_PyramidLimit::Setup(
        idAFConstraint_PyramidLimit *this,
        idAFBody *b1,
        idAFBody *b2,
        const idVec3 *pyramidAnchor,
        const idVec3 *pyramidAxis,
        const idVec3 *baseAxis,
        double pyramidAngle1,
        double pyramidAngle2,
        const idVec3 *body1Axis,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        idVec3 *a30)
{
  double x; // fp0
  double z; // fp12
  double v34; // fp10
  double y; // fp9
  double v38; // fp4
  double v40; // fp2
  double v41; // fp12
  double v42; // fp2
  double v43; // fp12
  double v44; // fp11
  double v45; // fp1
  double v46; // fp9
  double v47; // fp7
  double v48; // fp6
  double v49; // fp3
  double v50; // fp2
  double v51; // fp1
  double v52; // fp10
  double v55; // fp6
  double v56; // fp7
  double v57; // fp13
  double v58; // fp12
  double v59; // fp11
  double v60; // fp5
  double v61; // fp10
  long double v62; // fp2
  double v63; // fp1
  double v64; // fp6
  long double v65; // fp2
  long double v66; // fp2
  double v67; // fp30
  long double v68; // fp2
  long double v69; // fp2
  long double v70; // fp2
  long double v71; // fp2

  this->body2 = b2;
  this->body1 = b1;
  x = pyramidAxis->x;
  this->pyramidBasis.mat[2].x = pyramidAxis->x;
  this->pyramidBasis.mat[2].y = pyramidAxis->y;
  z = pyramidAxis->z;
  this->pyramidBasis.mat[2].z = pyramidAxis->z;
  v34 = z;
  y = this->pyramidBasis.mat[2].y;
  _FP5 = (float)((float)((float)((float)z * (float)z)
                       + (float)((float)((float)x * (float)x)
                               + (float)(this->pyramidBasis.mat[2].y * this->pyramidBasis.mat[2].y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v38 = (float)((float)((float)((float)z * (float)z)
                      + (float)((float)((float)x * (float)x)
                              + (float)(this->pyramidBasis.mat[2].y * this->pyramidBasis.mat[2].y)))
              * (float)0.5);
  __asm { fsel      f3, f5, f6, f13 }
  v40 = __frsqrte(_FP3);
  v41 = (float)-(float)((float)((float)((float)v40
                                      * (float)((float)((float)((float)z * (float)z)
                                                      + (float)((float)((float)x * (float)x)
                                                              + (float)(this->pyramidBasis.mat[2].y
                                                                      * this->pyramidBasis.mat[2].y)))
                                              * (float)0.5))
                              * (float)v40)
                      - (float)1.5);
  v42 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)v41 * (float)v40)
                                                                                      * (float)v38)
                                                                              * (float)((float)v41 * (float)v40))
                                                                      - (float)1.5)
                                                      * (float)((float)v41 * (float)v40))
                                              * (float)v38)
                                      * (float)((float)-(float)((float)((float)((float)((float)v41 * (float)v40)
                                                                              * (float)v38)
                                                                      * (float)((float)v41 * (float)v40))
                                                              - (float)1.5)
                                              * (float)((float)v41 * (float)v40)))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)((float)v41 * (float)v40) * (float)v38)
                                              * (float)((float)v41 * (float)v40))
                                      - (float)1.5)
                      * (float)((float)v41 * (float)v40)));
  this->pyramidBasis.mat[2].x = (float)x * (float)v42;
  this->pyramidBasis.mat[2].y = (float)y * (float)v42;
  this->pyramidBasis.mat[2].z = (float)v34 * (float)v42;
  v43 = baseAxis->x;
  this->pyramidBasis.mat[0].x = baseAxis->x;
  v44 = baseAxis->y;
  this->pyramidBasis.mat[0].y = baseAxis->y;
  v45 = baseAxis->z;
  this->pyramidBasis.mat[0].z = baseAxis->z;
  v46 = (float)(this->pyramidBasis.mat[2].x
              * (float)((float)(this->pyramidBasis.mat[2].x * baseAxis->x)
                      + (float)((float)(this->pyramidBasis.mat[2].y * baseAxis->y)
                              + (float)(this->pyramidBasis.mat[2].z * baseAxis->z))));
  v47 = (float)(this->pyramidBasis.mat[2].z
              * (float)((float)(this->pyramidBasis.mat[2].x * baseAxis->x)
                      + (float)((float)(this->pyramidBasis.mat[2].y * baseAxis->y)
                              + (float)(this->pyramidBasis.mat[2].z * baseAxis->z))));
  v48 = (float)((float)v44
              - (float)(this->pyramidBasis.mat[2].y
                      * (float)((float)(this->pyramidBasis.mat[2].x * baseAxis->x)
                              + (float)((float)(this->pyramidBasis.mat[2].y * baseAxis->y)
                                      + (float)(this->pyramidBasis.mat[2].z * baseAxis->z)))));
  this->pyramidBasis.mat[0].y = (float)v44
                              - (float)(this->pyramidBasis.mat[2].y
                                      * (float)((float)(this->pyramidBasis.mat[2].x * baseAxis->x)
                                              + (float)((float)(this->pyramidBasis.mat[2].y * baseAxis->y)
                                                      + (float)(this->pyramidBasis.mat[2].z * baseAxis->z))));
  this->pyramidBasis.mat[0].x = (float)v43 - (float)v46;
  this->pyramidBasis.mat[0].z = (float)v45 - (float)v47;
  v49 = (float)((float)v43 - (float)v46);
  v50 = (float)((float)v45 - (float)v47);
  v52 = (float)((float)((float)((float)v45 - (float)v47) * (float)((float)v45 - (float)v47))
              + (float)((float)((float)((float)v43 - (float)v46) * (float)((float)v43 - (float)v46))
                      + (float)((float)v48 * (float)v48)));
  _FP9 = (float)((float)((float)((float)((float)v45 - (float)v47) * (float)((float)v45 - (float)v47))
                       + (float)((float)((float)((float)v43 - (float)v46) * (float)((float)v43 - (float)v46))
                               + (float)((float)v48 * (float)v48)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v51 = v48;
  __asm { fsel      f7, f9, f10, f13 }
  v55 = __frsqrte(_FP7);
  v56 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55
                                                                                      * (float)((float)v52 * (float)0.5))
                                                                              * (float)v55)
                                                                      - (float)1.5)
                                                      * (float)v55)
                                              * (float)((float)v52 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v55
                                                                              * (float)((float)v52 * (float)0.5))
                                                                      * (float)v55)
                                                              - (float)1.5)
                                              * (float)v55))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55)
                                      - (float)1.5)
                      * (float)v55));
  v57 = (float)((float)v51
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55)
                                                                                              * (float)((float)v52 * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                              * (float)v55))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5))
                                                                                              * (float)v55)
                                                                                      - (float)1.5)
                                                                      * (float)v55))
                                                      * (float)((float)v52 * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                              * (float)v55)
                                                                                      * (float)((float)v52 * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                      * (float)v55))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v55
                                                                                              * (float)((float)v52 * (float)0.5))
                                                                                      * (float)v55)
                                                                              - (float)1.5)
                                                              * (float)v55)))
                                      - (float)1.5)
                      * (float)v56));
  this->pyramidBasis.mat[0].y = (float)v51
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55) * (float)((float)v52 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55))
                                                                                              - (float)1.5)
                                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                      * (float)v55))
                                                                      * (float)((float)v52 * (float)0.5))
                                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55) * (float)((float)v52 * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55)
                                                                                              - (float)1.5)
                                                                              * (float)v55)))
                                                      - (float)1.5)
                                      * (float)v56);
  v58 = (float)((float)v50
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55)
                                                                                              * (float)((float)v52 * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                              * (float)v55))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5))
                                                                                              * (float)v55)
                                                                                      - (float)1.5)
                                                                      * (float)v55))
                                                      * (float)((float)v52 * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                              * (float)v55)
                                                                                      * (float)((float)v52 * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                      * (float)v55))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v55
                                                                                              * (float)((float)v52 * (float)0.5))
                                                                                      * (float)v55)
                                                                              - (float)1.5)
                                                              * (float)v55)))
                                      - (float)1.5)
                      * (float)v56));
  this->pyramidBasis.mat[0].z = (float)v50
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55) * (float)((float)v52 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55))
                                                                                              - (float)1.5)
                                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                      * (float)v55))
                                                                      * (float)((float)v52 * (float)0.5))
                                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55) * (float)((float)v52 * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55)
                                                                                              - (float)1.5)
                                                                              * (float)v55)))
                                                      - (float)1.5)
                                      * (float)v56);
  v59 = (float)((float)v49
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55)
                                                                                              * (float)((float)v52 * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                              * (float)v55))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5))
                                                                                              * (float)v55)
                                                                                      - (float)1.5)
                                                                      * (float)v55))
                                                      * (float)((float)v52 * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                              * (float)v55)
                                                                                      * (float)((float)v52 * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                      * (float)v55))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v55
                                                                                              * (float)((float)v52 * (float)0.5))
                                                                                      * (float)v55)
                                                                              - (float)1.5)
                                                              * (float)v55)))
                                      - (float)1.5)
                      * (float)v56));
  this->pyramidBasis.mat[0].x = (float)v49
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55) * (float)((float)v52 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55))
                                                                                              - (float)1.5)
                                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                      * (float)v55))
                                                                      * (float)((float)v52 * (float)0.5))
                                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55) * (float)((float)v52 * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55)
                                                                                              - (float)1.5)
                                                                              * (float)v55)))
                                                      - (float)1.5)
                                      * (float)v56);
  v60 = this->pyramidBasis.mat[2].z;
  *((double *)&v62 + 1) = (float)((float)((float)v51
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55) * (float)((float)v52 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55)) - (float)1.5)
                                                                                        * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                                * (float)v55))
                                                                                * (float)((float)v52 * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55) * (float)((float)v52 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55))
                                                                                                - (float)1.5)
                                                                                * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                        * (float)v55)))
                                                                - (float)1.5)
                                                * (float)v56))
                                * this->pyramidBasis.mat[2].x);
  v63 = (float)((float)((float)v49
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55) * (float)((float)v52 * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55)
                                                                                              - (float)1.5)
                                                                              * (float)v55))
                                                              * (float)((float)v52 * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55)
                                                                                              * (float)((float)v52 * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                              * (float)v55))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5))
                                                                                              * (float)v55)
                                                                                      - (float)1.5)
                                                                      * (float)v55)))
                                              - (float)1.5)
                              * (float)v56))
              * this->pyramidBasis.mat[2].z);
  v61 = this->pyramidBasis.mat[2].x;
  v64 = (float)((float)v58 * this->pyramidBasis.mat[2].y);
  this->pyramidBasis.mat[1].z = (float)((float)v59 * this->pyramidBasis.mat[2].y)
                              - (float)((float)v57 * this->pyramidBasis.mat[2].x);
  this->pyramidBasis.mat[1].y = (float)((float)v58 * (float)v61) - (float)v63;
  this->pyramidBasis.mat[1].x = (float)((float)v57 * (float)v60) - (float)v64;
  this->pyramidAnchor = *pyramidAnchor;
  *(double *)&v62 = (float)((float)((float)pyramidAngle1 * (float)0.5) * idMath::M_DEG2RAD);
  v65 = cos(x: v62);
  this->cosAngle[0] = *(double *)&v65;
  *(double *)&v65 = (float)((float)((float)pyramidAngle2 * (float)0.5) * idMath::M_DEG2RAD);
  v66 = cos(x: v65);
  this->cosAngle[1] = *(double *)&v66;
  v67 = (float)((float)pyramidAngle1 * (float)0.25);
  *(double *)&v66 = (float)((float)v67 * idMath::M_DEG2RAD);
  v68 = sin(x: v66);
  this->sinHalfAngle[0] = *(double *)&v68;
  *(double *)&v68 = (float)((float)((float)pyramidAngle2 * (float)0.25) * idMath::M_DEG2RAD);
  v69 = sin(x: v68);
  this->sinHalfAngle[1] = *(double *)&v69;
  *(double *)&v69 = (float)((float)v67 * idMath::M_DEG2RAD);
  v70 = cos(x: v69);
  this->cosHalfAngle[0] = *(double *)&v70;
  *(double *)&v70 = (float)((float)((float)pyramidAngle2 * (float)0.25) * idMath::M_DEG2RAD);
  v71 = cos(x: v70);
  this->cosHalfAngle[1] = *(double *)&v71;
  this->body1Axis = *a30;
}


// ========================================================================
// ?Add@idAFConstraint_PyramidLimit@@QAA_NPAVidPhysics_AF@@M@Z
// EA  : 0x82720238
// RVA : 0x00720238
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

int __fastcall idAFConstraint_PyramidLimit::Add(
        idAFConstraint_PyramidLimit *this,
        idPhysics_AF *phys,
        double invTimeStep)
{
  idAFBody *body1; // r9
  idAFBody *body2; // r11
  idAFBody *masterBody; // r24
  float *clipModel; // r11
  double z; // fp11
  double v16; // fp3
  double v17; // fp27
  double v18; // fp28
  double v19; // fp23
  double x; // fp29
  double v21; // fp26
  double v22; // fp25
  double v23; // fp7
  double v24; // fp9
  double v25; // fp24
  double v26; // fp4
  double v27; // fp10
  double v28; // fp5
  double v29; // fp1
  double v30; // fp13
  double v31; // fp8
  double v32; // fp0
  double v33; // fp31
  double v34; // fp5
  double v35; // fp11
  double v36; // fp2
  double v37; // fp4
  double v38; // fp10
  double v39; // fp6
  double v40; // fp5
  double v41; // fp1
  double y; // fp13
  double v43; // fp19
  double v44; // fp18
  double v45; // fp17
  double v46; // fp13
  double v47; // fp12
  double v48; // fp11
  double v49; // fp10
  double v50; // fp9
  float *v51; // r10
  double v52; // fp0
  double v53; // fp13
  double v54; // fp12
  float *v55; // r8
  unsigned int v56; // r9
  int v57; // ctr
  idVec3 *v58; // r11
  double v59; // fp22
  double v60; // fp21
  double v61; // fp20
  double v62; // fp0
  char v63; // r10
  float *v64; // r10
  double v65; // fp7
  double v66; // fp6
  double v67; // fp2
  double v68; // fp1
  double v69; // fp13
  double v71; // fp7
  double v73; // fp5
  double v74; // fp8
  double v75; // fp7
  double v79; // fp30
  float *v80; // r27
  double v81; // fp29
  float *sinHalfAngle; // r30
  double v83; // fp31
  float *p_z; // r29
  int v85; // r28
  double v86; // fp13
  double v87; // fp12
  double v88; // fp11
  double v89; // fp10
  double v90; // fp9
  double v91; // fp8
  double v92; // fp7
  double v93; // fp5
  double v94; // fp4
  double v95; // fp3
  double v98; // fp9
  double v99; // fp12
  double v100; // fp9
  double v101; // fp3
  float *v102; // r3
  double v103; // fp12
  double v104; // fp13
  idClipModel *v105; // r11
  double v106; // fp7
  double v107; // fp6
  double v108; // fp4
  double v109; // fp25
  double v110; // fp24
  double v111; // fp26
  double v112; // fp18
  double v113; // fp17
  double v114; // fp19
  double v115; // fp11
  double v116; // fp10
  double v117; // fp9
  double v120; // fp2
  double v121; // fp6
  double v122; // fp31
  double v123; // fp30
  double v124; // fp29
  float *mat; // r9
  float *v126; // r11
  float *p; // r30
  double v128; // fp28
  double LimitErrorReductionMax; // fp27
  double v130; // fp0
  float *v131; // r11
  double v132; // fp27
  double v133; // fp26
  double v134; // fp25
  float *v135; // r11
  float *v136; // r11
  float *v137; // r30
  char v138; // [sp+4Ch] [-134h] BYREF
  float v139[4]; // [sp+50h] [-130h] BYREF
  idMat3 v140; // [sp+60h] [-120h] BYREF
  idQuat v141; // [sp+90h] [-F0h] BYREF
  float v142; // [sp+A0h] [-E0h]
  float v143; // [sp+A4h] [-DCh]
  float v144; // [sp+A8h] [-D8h]
  float v145; // [sp+ACh] [-D4h]
  float v146; // [sp+B0h] [-D0h]

  if ( af_skipLimits.valueInteger != 0 )
  {
    __asm { vspltisw128 v63, 0 }
    _R10 = this->lm.p;
    _R9 = 16;
    __asm { stvx128   v63, r0, r10 }
    _R8 = _R10;
    __asm { stvx128   v63, r8, r9 }
    return 0;
  }
  else if ( phys != nullptr && (body1 = this->body1) != nullptr )
  {
    body2 = this->body2;
    this->physics = phys;
    masterBody = body2;
    if ( body2 == nullptr )
      masterBody = phys->masterBody;
    if ( masterBody != nullptr )
    {
      clipModel = (float *)masterBody->clipModel;
      z = this->pyramidBasis.mat[0].z;
      v16 = this->pyramidBasis.mat[1].z;
      v17 = clipModel[18];
      v18 = clipModel[11];
      v19 = clipModel[12];
      x = this->pyramidBasis.mat[1].x;
      v21 = (float)((float)(this->pyramidBasis.mat[2].x * clipModel[11])
                  + (float)((float)(clipModel[14] * this->pyramidBasis.mat[2].y)
                          + (float)(clipModel[17] * this->pyramidBasis.mat[2].z)));
      v22 = (float)((float)(clipModel[18] * this->pyramidBasis.mat[2].z)
                  + (float)((float)(clipModel[12] * this->pyramidBasis.mat[2].x)
                          + (float)(clipModel[15] * this->pyramidBasis.mat[2].y)));
      v23 = (float)(clipModel[16] * this->pyramidBasis.mat[1].y);
      v24 = clipModel[13];
      v25 = (float)((float)(clipModel[19] * this->pyramidBasis.mat[2].z)
                  + (float)((float)(clipModel[13] * this->pyramidBasis.mat[2].x)
                          + (float)(clipModel[16] * this->pyramidBasis.mat[2].y)));
      v26 = (float)((float)(clipModel[13] * this->pyramidBasis.mat[0].x)
                  + (float)(clipModel[16] * this->pyramidBasis.mat[0].y));
      v27 = (float)((float)(clipModel[14] * this->pyramidBasis.mat[1].y)
                  + (float)(clipModel[17] * this->pyramidBasis.mat[1].z));
      v28 = (float)((float)(clipModel[12] * this->pyramidBasis.mat[0].x)
                  + (float)(clipModel[15] * this->pyramidBasis.mat[0].y));
      v29 = (float)((float)(clipModel[12] * this->pyramidBasis.mat[1].x)
                  + (float)(clipModel[15] * this->pyramidBasis.mat[1].y));
      v30 = clipModel[19];
      v141.x = (float)(clipModel[11] * this->pyramidBasis.mat[0].x)
             + (float)((float)(clipModel[14] * this->pyramidBasis.mat[0].y)
                     + (float)(clipModel[17] * this->pyramidBasis.mat[0].z));
      v31 = this->pyramidAnchor.z;
      v32 = clipModel[17];
      v33 = v30;
      v141.y = (float)((float)v17 * (float)z) + (float)v28;
      v34 = (float)((float)((float)v30 * (float)z) + (float)v26);
      v35 = clipModel[15];
      v36 = (float)((float)((float)v17 * (float)v16) + (float)v29);
      v141.z = v34;
      v37 = (float)((float)((float)x * (float)v18) + (float)v27);
      v38 = clipModel[16];
      v39 = this->pyramidAnchor.x;
      v40 = clipModel[14];
      v41 = (float)((float)((float)v30 * (float)v16) + (float)((float)((float)v24 * (float)x) + (float)v23));
      y = this->pyramidAnchor.y;
      v141.w = v37;
      v142 = v36;
      v143 = v41;
      v43 = (float)((float)((float)((float)v18 * (float)v39)
                          + (float)((float)((float)v40 * (float)y) + (float)((float)v32 * (float)v31)))
                  + clipModel[8]);
      v44 = (float)(clipModel[9]
                  + (float)((float)((float)v17 * (float)v31)
                          + (float)((float)((float)v19 * (float)v39) + (float)((float)v35 * (float)y))));
      v45 = (float)(clipModel[10]
                  + (float)((float)((float)v33 * (float)v31)
                          + (float)((float)(clipModel[13] * (float)v39) + (float)((float)v38 * (float)y))));
    }
    else
    {
      v46 = this->pyramidBasis.mat[0].y;
      v47 = this->pyramidBasis.mat[0].z;
      v48 = this->pyramidBasis.mat[1].x;
      v49 = this->pyramidBasis.mat[1].y;
      v50 = this->pyramidBasis.mat[1].z;
      v21 = this->pyramidBasis.mat[2].x;
      v22 = this->pyramidBasis.mat[2].y;
      v25 = this->pyramidBasis.mat[2].z;
      v43 = this->pyramidAnchor.x;
      v44 = this->pyramidAnchor.y;
      v45 = this->pyramidAnchor.z;
      v141.x = this->pyramidBasis.mat[0].x;
      v141.y = v46;
      v141.z = v47;
      v141.w = v48;
      v142 = v49;
      v143 = v50;
    }
    v51 = (float *)body1->clipModel;
    v52 = this->body1Axis.z;
    v53 = this->body1Axis.y;
    v54 = this->body1Axis.x;
    v146 = v25;
    v55 = (float *)&v138;
    v145 = v22;
    v56 = 0;
    v57 = 2;
    v58 = &v140.mat[1];
    v59 = (float)((float)((float)v54 * v51[11]) + (float)((float)(v51[14] * (float)v53) + (float)(v51[17] * (float)v52)));
    v60 = (float)((float)(v51[18] * (float)v52) + (float)((float)(v51[12] * (float)v54) + (float)(v51[15] * (float)v53)));
    v61 = (float)((float)(v51[19] * (float)v52) + (float)((float)(v51[13] * (float)v54) + (float)(v51[16] * (float)v53)));
    v144 = v21;
    v62 = idMath::FLT_SMALLEST_NON_DENORMAL;
    do
    {
      v63 = _cntlzw(v56++);
      v64 = &v141.x + 3 * ((v63 & 0x20) != 0);
      v65 = (float)(*v64
                  * (float)((float)(*v64 * (float)v59)
                          + (float)((float)((float)v60 * v64[1]) + (float)((float)v61 * v64[2]))));
      v66 = (float)(v64[1]
                  * (float)((float)(*v64 * (float)v59)
                          + (float)((float)((float)v60 * v64[1]) + (float)((float)v61 * v64[2]))));
      v67 = (float)((float)v61
                  - (float)(v64[2]
                          * (float)((float)(*v64 * (float)v59)
                                  + (float)((float)((float)v60 * v64[1]) + (float)((float)v61 * v64[2])))));
      v58[1].x = (float)v61
               - (float)(v64[2]
                       * (float)((float)(*v64 * (float)v59)
                               + (float)((float)((float)v60 * v64[1]) + (float)((float)v61 * v64[2]))));
      v58->y = (float)v59 - (float)v65;
      v58->z = (float)v60 - (float)v66;
      v68 = (float)((float)v59 - (float)v65);
      v69 = (float)((float)v60 - (float)v66);
      _FP8 = (float)((float)((float)((float)((float)v60 - (float)v66) * (float)((float)v60 - (float)v66))
                           + (float)((float)((float)((float)v59 - (float)v65) * (float)((float)v59 - (float)v65))
                                   + (float)((float)v67 * (float)v67)))
                   - (float)v62);
      v71 = (float)((float)((float)((float)((float)v60 - (float)v66) * (float)((float)v60 - (float)v66))
                          + (float)((float)((float)((float)v59 - (float)v65) * (float)((float)v59 - (float)v65))
                                  + (float)((float)v67 * (float)v67)))
                  * (float)0.5);
      __asm { fsel      f6, f8, f9, f0 }
      v73 = __frsqrte(_FP6);
      v74 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v73 * (float)v71)
                                                                                  * (float)v73)
                                                                          - (float)1.5)
                                                          * (float)v73)
                                                  * (float)v71)
                                          * (float)((float)-(float)((float)((float)((float)v73 * (float)v71) * (float)v73)
                                                                  - (float)1.5)
                                                  * (float)v73))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v73 * (float)v71) * (float)v73) - (float)1.5)
                          * (float)v73));
      v75 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v73
                                                                                                  * (float)v71)
                                                                                          * (float)v73)
                                                                                  - (float)1.5)
                                                                  * (float)v73)
                                                          * (float)v71)
                                                  * (float)((float)-(float)((float)((float)((float)v73 * (float)v71)
                                                                                  * (float)v73)
                                                                          - (float)1.5)
                                                          * (float)v73))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v73 * (float)v71) * (float)v73) - (float)1.5)
                                  * (float)v73))
                  * (float)v71);
      v58->z = (float)((float)-(float)((float)((float)v75 * (float)v74) - (float)1.5) * (float)v74) * (float)v69;
      v58[1].x = (float)((float)-(float)((float)((float)v75 * (float)v74) - (float)1.5) * (float)v74) * (float)v67;
      v58->y = (float)((float)-(float)((float)((float)v75 * (float)v74) - (float)1.5) * (float)v74) * (float)v68;
      ++v58;
      *++v55 = (float)((float)((float)((float)-(float)((float)((float)v75 * (float)v74) - (float)1.5) * (float)v74)
                             * (float)v68)
                     * (float)v21)
             + (float)((float)(v58->x * (float)v25)
                     + (float)((float)((float)((float)-(float)((float)((float)v75 * (float)v74) - (float)1.5)
                                             * (float)v74)
                                     * (float)v69)
                             * (float)v22));
      --v57;
    }
    while ( v57 != 0 );
    if ( v139[0] <= (double)this->cosAngle[0] || v139[1] <= (double)this->cosAngle[1] )
    {
      v79 = v21;
      v80 = v139;
      v81 = v22;
      sinHalfAngle = this->sinHalfAngle;
      v83 = v25;
      p_z = &v140.mat[1].z;
      v85 = 2;
      do
      {
        if ( *v80 <= (double)*(sinHalfAngle - 2) )
        {
          v86 = *p_z;
          v87 = (float)(*p_z * (float)v21);
          v88 = p_z[1];
          v89 = *(p_z - 1);
          v90 = (float)(p_z[1] * (float)v22);
          v91 = (float)(*(p_z - 1) * (float)v25);
          v140.mat[1].x = sinHalfAngle[2];
          v92 = *sinHalfAngle;
          v93 = (float)((float)((float)v89 * (float)v22) - (float)v87);
          v94 = (float)((float)((float)v86 * (float)v25) - (float)v90);
          v95 = (float)((float)((float)v88 * (float)v21) - (float)v91);
          _FP12 = (float)((float)((float)((float)v95 * (float)v95)
                                + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93)))
                        - (float)v62);
          __asm { fsel      f10, f12, f13, f0 }
          v98 = __frsqrte(_FP10);
          v99 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v98
                                                                                              * (float)((float)((float)((float)v95 * (float)v95) + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93))) * (float)0.5))
                                                                                      * (float)v98)
                                                                              - (float)1.5)
                                                              * (float)v98)
                                                      * (float)((float)((float)((float)v95 * (float)v95)
                                                                      + (float)((float)((float)v94 * (float)v94)
                                                                              + (float)((float)v93 * (float)v93)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v98
                                                                                      * (float)((float)((float)((float)v95 * (float)v95) + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93)))
                                                                                              * (float)0.5))
                                                                              * (float)v98)
                                                                      - (float)1.5)
                                                      * (float)v98))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v98
                                                              * (float)((float)((float)((float)v95 * (float)v95)
                                                                              + (float)((float)((float)v94 * (float)v94)
                                                                                      + (float)((float)v93 * (float)v93)))
                                                                      * (float)0.5))
                                                      * (float)v98)
                                              - (float)1.5)
                              * (float)v98));
          v100 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)v95 * (float)v95) + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93))) * (float)0.5)) * (float)v98) - (float)1.5) * (float)v98)
                                                                                               * (float)((float)((float)((float)v95 * (float)v95) + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93))) * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)v95 * (float)v95) + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93))) * (float)0.5)) * (float)v98) - (float)1.5)
                                                                                               * (float)v98))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v98 * (float)((float)((float)((float)v95 * (float)v95) + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93))) * (float)0.5))
                                                                                               * (float)v98)
                                                                                       - (float)1.5)
                                                                       * (float)v98))
                                                       * (float)((float)((float)((float)v95 * (float)v95)
                                                                       + (float)((float)((float)v94 * (float)v94)
                                                                               + (float)((float)v93 * (float)v93)))
                                                               * (float)0.5))
                                               * (float)v99)
                                       - (float)1.5)
                       * (float)v99);
          v101 = (float)(*sinHalfAngle * (float)((float)((float)((float)v88 * (float)v21) - (float)v91) * (float)v100));
          v140.mat[0].x = *sinHalfAngle * (float)((float)v100 * (float)v94);
          v140.mat[0].y = v101;
          v140.mat[0].z = (float)v92 * (float)((float)v93 * (float)v100);
          v102 = (float *)idQuat::ToMat3(this: &v141, result: &v140);
          v62 = idMath::FLT_SMALLEST_NON_DENORMAL;
          v103 = (float)((float)(v102[8] * (float)v83) + (float)(v102[5] * (float)v81));
          v104 = (float)((float)((float)v79 * *v102)
                       + (float)((float)(v102[6] * (float)v83) + (float)(v102[3] * (float)v81)));
          v81 = (float)((float)(v102[1] * (float)v79)
                      + (float)((float)(v102[7] * (float)v83) + (float)(v102[4] * (float)v81)));
          v83 = (float)((float)(v102[2] * (float)v79) + (float)v103);
          v79 = v104;
        }
        --v85;
        ++v80;
        ++sinHalfAngle;
        p_z += 3;
      }
      while ( v85 != 0 );
      v105 = this->body1->clipModel;
      v106 = (float)((float)((float)v83 * (float)v21) - (float)((float)v79 * (float)v25));
      v107 = (float)((float)((float)v81 * (float)v25) - (float)((float)v83 * (float)v22));
      v108 = (float)((float)((float)v79 * (float)v22) - (float)((float)v81 * (float)v21));
      v109 = (float)((float)v44 + (float)((float)v81 * (float)32.0));
      v110 = (float)((float)v45 + (float)((float)v83 * (float)32.0));
      v111 = (float)((float)v43 + (float)((float)v79 * (float)32.0));
      v112 = (float)((float)((float)v44 + (float)((float)v81 * (float)32.0)) - v105->origin.y);
      v113 = (float)((float)((float)v45 + (float)((float)v83 * (float)32.0)) - v105->origin.z);
      v114 = (float)((float)((float)v43 + (float)((float)v79 * (float)32.0)) - v105->origin.x);
      v115 = (float)((float)((float)v81 * (float)v107) - (float)((float)v106 * (float)v79));
      v116 = (float)((float)((float)v108 * (float)v79) - (float)((float)v83 * (float)v107));
      v117 = (float)((float)((float)v106 * (float)v83) - (float)((float)v108 * (float)v81));
      _FP5 = (float)((float)((float)((float)v116 * (float)v116)
                           + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115)))
                   - (float)v62);
      __asm { fsel      f3, f5, f6, f0 }
      v120 = __frsqrte(_FP3);
      v121 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v120
                                                                                           * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115))) * (float)0.5))
                                                                                   * (float)v120)
                                                                           - (float)1.5)
                                                           * (float)v120)
                                                   * (float)((float)((float)((float)v116 * (float)v116)
                                                                   + (float)((float)((float)v117 * (float)v117)
                                                                           + (float)((float)v115 * (float)v115)))
                                                           * (float)0.5))
                                           * (float)((float)-(float)((float)((float)((float)v120
                                                                                   * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115)))
                                                                                           * (float)0.5))
                                                                           * (float)v120)
                                                                   - (float)1.5)
                                                   * (float)v120))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)v120
                                                           * (float)((float)((float)((float)v116 * (float)v116)
                                                                           + (float)((float)((float)v117 * (float)v117)
                                                                                   + (float)((float)v115 * (float)v115)))
                                                                   * (float)0.5))
                                                   * (float)v120)
                                           - (float)1.5)
                           * (float)v120));
      v122 = (float)((float)v117
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v120 * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115))) * (float)0.5)) * (float)v120) - (float)1.5) * (float)v120) * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v120 * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115))) * (float)0.5)) * (float)v120) - (float)1.5) * (float)v120))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v120 * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115))) * (float)0.5)) * (float)v120)
                                                                                           - (float)1.5)
                                                                           * (float)v120))
                                                           * (float)((float)((float)((float)v116 * (float)v116)
                                                                           + (float)((float)((float)v117 * (float)v117)
                                                                                   + (float)((float)v115 * (float)v115)))
                                                                   * (float)0.5))
                                                   * (float)v121)
                                           - (float)1.5)
                           * (float)v121));
      v123 = (float)((float)v116
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v120 * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115))) * (float)0.5)) * (float)v120) - (float)1.5) * (float)v120) * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v120 * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115))) * (float)0.5)) * (float)v120) - (float)1.5) * (float)v120))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v120 * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115))) * (float)0.5)) * (float)v120)
                                                                                           - (float)1.5)
                                                                           * (float)v120))
                                                           * (float)((float)((float)((float)v116 * (float)v116)
                                                                           + (float)((float)((float)v117 * (float)v117)
                                                                                   + (float)((float)v115 * (float)v115)))
                                                                   * (float)0.5))
                                                   * (float)v121)
                                           - (float)1.5)
                           * (float)v121));
      v124 = (float)((float)v115
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v120 * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115))) * (float)0.5)) * (float)v120) - (float)1.5) * (float)v120) * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v120 * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115))) * (float)0.5)) * (float)v120) - (float)1.5) * (float)v120))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v120 * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115))) * (float)0.5)) * (float)v120)
                                                                                           - (float)1.5)
                                                                           * (float)v120))
                                                           * (float)((float)((float)((float)v116 * (float)v116)
                                                                           + (float)((float)((float)v117 * (float)v117)
                                                                                   + (float)((float)v115 * (float)v115)))
                                                                   * (float)0.5))
                                                   * (float)v121)
                                           - (float)1.5)
                           * (float)v121));
      idSpatialMat::SetSize(this: &this->J1, rows: 1, columns: 6);
      mat = this->J1.mat;
      mat[1] = v123;
      mat[2] = v124;
      *mat = v122;
      v126 = this->J1.mat;
      v126[3] = (float)((float)v112 * (float)v124) - (float)((float)v113 * (float)v123);
      v126[4] = (float)((float)v113 * (float)v122) - (float)((float)v124 * (float)v114);
      v126[5] = (float)((float)v123 * (float)v114) - (float)((float)v112 * (float)v122);
      p = this->c1.p;
      *p = (float)(idPhysics_AF::GetLimitErrorReduction(this: phys) * (float)invTimeStep)
         * (float)((float)((float)((float)v60 * (float)32.0) * (float)v123)
                 + (float)((float)((float)((float)v59 * (float)32.0) * (float)v122)
                         + (float)((float)((float)v61 * (float)32.0) * (float)v124)));
      v128 = *this->c1.p;
      LimitErrorReductionMax = idPhysics_AF::GetLimitErrorReductionMax(this: phys);
      v130 = -idPhysics_AF::GetLimitErrorReductionMax(this: phys);
      if ( v128 >= v130 )
      {
        if ( v128 <= LimitErrorReductionMax )
          v130 = v128;
        else
          v130 = LimitErrorReductionMax;
      }
      *this->c1.p = v130;
      if ( this->body2 != nullptr && masterBody != nullptr )
      {
        v131 = (float *)masterBody->clipModel;
        v132 = (float)((float)v111 - v131[8]);
        v133 = (float)((float)v109 - v131[9]);
        v134 = (float)((float)v110 - v131[10]);
        idSpatialMat::SetSize(this: &this->J2, rows: 1, columns: 6);
        v135 = this->J2.mat;
        v135[1] = -v123;
        *v135 = -v122;
        v135[2] = -v124;
        v136 = this->J2.mat;
        v136[3] = (float)((float)v133 * (float)-v124) - (float)((float)v134 * (float)-v123);
        v136[4] = (float)((float)v134 * (float)-v122) - (float)((float)v132 * (float)-v124);
        v136[5] = (float)((float)v132 * (float)-v123) - (float)((float)v133 * (float)-v122);
        *this->c2.p = 0.0;
      }
      *this->lo.p = 0.0;
      v137 = this->e.p;
      *v137 = idPhysics_AF::GetLimitLcpEpsilon(this: this->physics);
      idPhysics_AF::AddFrameConstraint(this: this->physics, constraint: this);
      return 1;
    }
    else
    {
      __asm { vspltisw128 v62, 0 }
      _R10 = this->lm.p;
      _R9 = 16;
      __asm { stvx128   v62, r0, r10 }
      _R8 = _R10;
      __asm { stvx128   v62, r8, r9 }
      return 0;
    }
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?Translate@idAFConstraint_ConeLimit@@UAAXABVidVec3@@@Z
// EA  : 0x82720A00
// RVA : 0x00720A00
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_ConeLimit::Translate(idAFConstraint_PyramidLimit *this, const idVec3 *translation)
{
  double y; // fp11
  double z; // fp8

  if ( this->body2 == nullptr )
  {
    y = this->pyramidAnchor.y;
    this->pyramidAnchor.x = this->pyramidAnchor.x + translation->x;
    z = this->pyramidAnchor.z;
    this->pyramidAnchor.y = translation->y + (float)y;
    this->pyramidAnchor.z = translation->z + (float)z;
  }
}


// ========================================================================
// ?Rotate@idAFConstraint_PyramidLimit@@UAAXABVidRotation@@@Z
// EA  : 0x82720A48
// RVA : 0x00720A48
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_PyramidLimit::Rotate(idAFConstraint_PyramidLimit *this, idRotation *rotation)
{
  float *v4; // r3
  double z; // fp11
  double v6; // fp12
  double v7; // fp8
  double v8; // fp6
  double v9; // fp5
  float *v10; // r3
  double v11; // fp1
  double v12; // fp2
  double v13; // fp12
  double v14; // fp10
  double v15; // fp9
  float *v16; // r3
  double v17; // fp5
  double v18; // fp2
  double v19; // fp1
  double v20; // fp4
  double v21; // fp3
  char v22; // [sp+50h] [-30h] BYREF

  if ( this->body2 == nullptr )
  {
    this->pyramidAnchor = idRotation::operator*(this: (idRotation *)&v22, result: rotation, v: &this->pyramidAnchor)->origin;
    v4 = (float *)idRotation::ToMat3(this: rotation);
    z = this->pyramidBasis.mat[0].z;
    v6 = v4[7];
    v7 = v4[8];
    v8 = (float)((float)(v4[1] * this->pyramidBasis.mat[0].x) + (float)(v4[4] * this->pyramidBasis.mat[0].y));
    v9 = (float)((float)(v4[2] * this->pyramidBasis.mat[0].x) + (float)(v4[5] * this->pyramidBasis.mat[0].y));
    this->pyramidBasis.mat[0].x = (float)(*v4 * this->pyramidBasis.mat[0].x)
                                + (float)((float)(v4[3] * this->pyramidBasis.mat[0].y)
                                        + (float)(v4[6] * this->pyramidBasis.mat[0].z));
    this->pyramidBasis.mat[0].y = (float)((float)v6 * (float)z) + (float)v8;
    this->pyramidBasis.mat[0].z = (float)((float)v7 * (float)z) + (float)v9;
    v10 = (float *)idRotation::ToMat3(this: rotation);
    v11 = this->pyramidBasis.mat[1].z;
    v12 = v10[7];
    v13 = v10[8];
    v14 = (float)((float)(v10[1] * this->pyramidBasis.mat[1].x) + (float)(v10[4] * this->pyramidBasis.mat[1].y));
    v15 = (float)((float)(v10[2] * this->pyramidBasis.mat[1].x) + (float)(v10[5] * this->pyramidBasis.mat[1].y));
    this->pyramidBasis.mat[1].x = (float)(*v10 * this->pyramidBasis.mat[1].x)
                                + (float)((float)(v10[3] * this->pyramidBasis.mat[1].y)
                                        + (float)(v10[6] * this->pyramidBasis.mat[1].z));
    this->pyramidBasis.mat[1].y = (float)((float)v12 * (float)v11) + (float)v14;
    this->pyramidBasis.mat[1].z = (float)((float)v13 * (float)v11) + (float)v15;
    v16 = (float *)idRotation::ToMat3(this: rotation);
    v17 = this->pyramidBasis.mat[2].z;
    v18 = (float)((float)(v16[1] * this->pyramidBasis.mat[2].x) + (float)(v16[4] * this->pyramidBasis.mat[2].y));
    v19 = (float)((float)(v16[2] * this->pyramidBasis.mat[2].x) + (float)(v16[5] * this->pyramidBasis.mat[2].y));
    v20 = v16[7];
    v21 = v16[8];
    this->pyramidBasis.mat[2].x = (float)(*v16 * this->pyramidBasis.mat[2].x)
                                + (float)((float)(v16[3] * this->pyramidBasis.mat[2].y)
                                        + (float)(v16[6] * this->pyramidBasis.mat[2].z));
    this->pyramidBasis.mat[2].y = (float)((float)v20 * (float)v17) + (float)v18;
    this->pyramidBasis.mat[2].z = (float)((float)v21 * (float)v17) + (float)v19;
  }
}


// ========================================================================
// ?Setup@idAFConstraint_Suspension@@QAAXPBDPAVidAFBody@@ABVidVec3@@PAVidClip@@PAVidClipModel@@HM@Z
// EA  : 0x82720C00
// RVA : 0x00720C00
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Suspension::Setup(
        idAFConstraint_Suspension *this,
        const char *name,
        idAFBody *body,
        const idVec3 *localOrigin,
        idClip *clip,
        idClipModel *clipModel,
        int clipMask,
        double radius)
{
  float *v15; // r10
  double v16; // fp13
  double v17; // fp12
  double v18; // fp5
  double v19; // fp3

  idAtomicString::Set(this: &this->name, str_: name);
  this->body1 = body;
  this->body2 = nullptr;
  this->localOrigin = *localOrigin;
  this->clip = clip;
  this->wheelRadius = radius;
  this->wheelModel = clipModel;
  this->clipMask = clipMask;
  v15 = (float *)body->clipModel;
  v16 = v15[10];
  v17 = v15[8];
  v18 = (float)((float)(v15[13] * localOrigin->x)
              + (float)((float)(v15[19] * localOrigin->z) + (float)(v15[16] * localOrigin->y)));
  v19 = (float)((float)(v15[11] * localOrigin->x)
              + (float)((float)(v15[17] * localOrigin->z) + (float)(v15[14] * localOrigin->y)));
  this->traceEndPos.y = v15[9]
                      + (float)((float)(v15[12] * localOrigin->x)
                              + (float)((float)(v15[18] * localOrigin->z) + (float)(v15[15] * localOrigin->y)));
  this->traceEndPos.z = (float)v16 + (float)v18;
  this->traceEndPos.x = (float)v17 + (float)v19;
}


// ========================================================================
// ?Translate@idAFConstraint_Suspension@@UAAXABVidVec3@@@Z
// EA  : 0x82720CF0
// RVA : 0x00720CF0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Suspension::Translate(idAFConstraint_Suspension *this, const idRotation *rotation)
{
  idClip *clip; // r3
  idAFBody *body1; // r10
  float *clipModel; // r9
  double v6; // fp3
  double v7; // fp1
  double v8; // fp7
  double v9; // fp6

  if ( this->body1 != nullptr )
  {
    clip = this->clip;
    if ( clip != nullptr )
    {
      idClip::CancelQuery(this: clip, clipQuery: &this->traceQuery);
      body1 = this->body1;
      this->traceFraction = 1.0;
      clipModel = (float *)body1->clipModel;
      v6 = clipModel[9];
      v7 = clipModel[8];
      v8 = (float)((float)(clipModel[18] * this->localOrigin.z)
                 + (float)((float)(clipModel[12] * this->localOrigin.x) + (float)(clipModel[15] * this->localOrigin.y)));
      v9 = (float)((float)(clipModel[11] * this->localOrigin.x)
                 + (float)((float)(clipModel[14] * this->localOrigin.y) + (float)(clipModel[17] * this->localOrigin.z)));
      this->traceEndPos.z = clipModel[10]
                          + (float)((float)(clipModel[19] * this->localOrigin.z)
                                  + (float)((float)(clipModel[13] * this->localOrigin.x)
                                          + (float)(clipModel[16] * this->localOrigin.y)));
      this->traceEndPos.y = (float)v6 + (float)v8;
      this->traceEndPos.x = (float)v7 + (float)v9;
    }
  }
}


// ========================================================================
// ?IssueCollisionQueries@idAFConstraint_Suspension@@UAAXXZ
// EA  : 0x82720DD0
// RVA : 0x00720DD0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Suspension::IssueCollisionQueries(idAFConstraint_Suspension *this)
{
  idAFBody *body1; // r5
  idClip *clip; // r4
  int clipMask; // r10
  double suspensionUp; // fp13
  double v5; // fp12
  double z; // fp11
  double v7; // fp9
  double y; // fp8
  idClipModel *wheelModel; // r8
  int v10; // [sp+8h] [-A8h]
  bool v11; // [sp+Fh] [-A1h]
  const char *v12; // [sp+10h] [-A0h]
  char v13; // [sp+70h] [-40h] BYREF
  idVec3 v14; // [sp+78h] [-38h] BYREF
  idVec3 v15; // [sp+88h] [-28h] BYREF

  body1 = this->body1;
  if ( body1 != nullptr )
  {
    clip = this->clip;
    if ( clip != nullptr && this->physics != nullptr )
    {
      clipMask = this->clipMask;
      if ( clipMask != 0 && LODWORD(body1->motionQuery.index) > LODWORD(clip->collisionQueryLastSubmittedIndex) )
      {
        suspensionUp = this->suspensionUp;
        v5 = (float)(this->suspensionUp + this->suspensionDown);
        z = this->localOrigin.z;
        v7 = (float)(this->localOrigin.z - this->suspensionDown);
        y = this->localOrigin.y;
        v15.x = this->localOrigin.x;
        v15.y = y;
        v14.x = v15.x;
        v14.y = y;
        v14.z = v7;
        wheelModel = this->wheelModel;
        v15.z = (float)z + (float)((float)((float)v5 * (float)0.25) + (float)suspensionUp);
        this->traceQuery = (idClipQuery)idClip::LocalTranslation(
                                          this: (idClip *)&v13,
                                          result: (idClipQuery *)HIDWORD(body1->motionQuery.index),
                                          localSpace: (idClipQuery *)body1->motionQuery.index,
                                          start: &v15,
                                          end: &v14,
                                          clipModel: wheelModel,
                                          startAxis: &mat3_identity,
                                          clipMask,
                                          passEntityNumber: v10,
                                          moveClipModel: v11,
                                          userName: v12)->index;
      }
    }
  }
}


// ========================================================================
// ?CancelCollisionQueries@idAFConstraint_Suspension@@UAAXXZ
// EA  : 0x82720EE8
// RVA : 0x00720EE8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Suspension::CancelCollisionQueries(idAFConstraint_Suspension *this)
{
  unsigned __int64 index; // r11

  if ( this->clip != nullptr )
  {
    index = this->traceQuery.index;
    if ( (unsigned int)index >= *(_DWORD *)(HIDWORD(index) + 377212)
      && (unsigned int)index <= *(_DWORD *)(HIDWORD(index) + 377236) )
    {
      *(_DWORD *)(24 * ((index & 0xFFF) + 11621) + HIDWORD(index)) = 1;
    }
    LODWORD(index) = 0;
    this->traceQuery.index = index;
  }
}


// ========================================================================
// ?DebugDraw@idAFConstraint_Suspension@@UAAXXZ
// EA  : 0x82720F48
// RVA : 0x00720F48
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Suspension::DebugDraw(idAFConstraint_Suspension *this)
{
  idAFBody *body1; // r11
  char *v3; // r10
  idClipModel *p_z; // r11
  int i; // ctr
  float x; // r11
  float y; // r10
  float z; // r9
  const idMat3 *v9; // r3
  idClipModel *clipModel; // r11
  double v11; // fp1
  double v12; // fp11
  double v13; // fp9
  idRenderWorld *v14; // r3
  double v15; // fp0
  double v16; // fp13
  idRenderWorld *v17; // r3
  double v18; // fp5
  double v19; // fp4
  idRenderWorld *v20; // r3
  double v21; // fp12
  double v22; // fp9
  idRenderWorld *v23; // r27
  __int64 v24; // r8
  __int128 v25; // r6
  __int64 v26; // r10
  va *v27; // r3
  idRenderWorld *v28; // r3
  double v29; // fp8
  double v30; // fp7
  double v31; // fp1
  int v32; // [sp+8h] [-11B8h]
  int v33; // [sp+Ch] [-11B4h]
  int v34; // [sp+10h] [-11B0h]
  int v35; // [sp+14h] [-11ACh]
  int v36; // [sp+18h] [-11A8h]
  int v37; // [sp+1Ch] [-11A4h]
  double debugf2; // [sp+28h] [-1198h]
  double debugf3; // [sp+30h] [-1190h]
  double debugf4; // [sp+38h] [-1188h]
  idVec3 v41; // [sp+60h] [-1160h] BYREF
  float v42; // [sp+70h] [-1150h] BYREF
  float v43; // [sp+74h] [-114Ch]
  float v44; // [sp+78h] [-1148h]
  char v45; // [sp+7Ch] [-1144h] BYREF
  idMat3 v46; // [sp+80h] [-1140h] BYREF
  float v47[4]; // [sp+A8h] [-1118h] BYREF
  float v48[4]; // [sp+B8h] [-1108h] BYREF
  float v49[4]; // [sp+C8h] [-10F8h] BYREF
  float v50[6]; // [sp+D8h] [-10E8h] BYREF
  float v51[4]; // [sp+F0h] [-10D0h] BYREF
  idMat3 v52; // [sp+100h] [-10C0h] BYREF
  idRotation v53; // [sp+130h] [-1090h] BYREF
  va v54; // [sp+180h] [-1040h] BYREF

  body1 = this->body1;
  if ( body1 != nullptr && this->clip != nullptr )
  {
    v3 = &v45;
    p_z = (idClipModel *)&body1->clipModel->origin.z;
    for ( i = 9; i != 0; --i )
    {
      p_z = (idClipModel *)((char *)p_z + 4);
      v3 += 4;
      *(_DWORD *)v3 = p_z->__vftable;
    }
    x = this->traceEndPos.x;
    y = this->traceEndPos.y;
    z = this->traceEndPos.z;
    v53.angle = this->steerAngle;
    v53.axisValid = false;
    v41.x = x;
    v53.vec.x = v46.mat[2].x;
    v41.y = y;
    v53.vec.y = v46.mat[2].y;
    v41.z = z;
    v53.vec.z = v46.mat[2].z;
    v9 = idRotation::ToMat3(this: &v53);
    idMat3::operator*(this: &v52, result: &v46, a: v9);
    clipModel = this->body1->clipModel;
    v11 = clipModel->origin.x;
    v12 = (float)((float)(this->cgLocation.x * v46.mat[0].x)
                + (float)((float)(this->cgLocation.z * v46.mat[2].x) + (float)(this->cgLocation.y * v46.mat[1].x)));
    v13 = (float)(clipModel->origin.z
                + (float)((float)(this->cgLocation.y * v46.mat[1].z)
                        + (float)((float)(this->cgLocation.x * v46.mat[0].z) + (float)(this->cgLocation.z * v46.mat[2].z))));
    v43 = clipModel->origin.y
        + (float)((float)(this->cgLocation.y * v46.mat[1].y)
                + (float)((float)(this->cgLocation.x * v46.mat[0].y) + (float)(this->cgLocation.z * v46.mat[2].y)));
    v44 = v13;
    v42 = (float)v12 + (float)v11;
    v14 = common->RW(this: common);
    v15 = (float)(this->debugv1.y + v41.y);
    v16 = (float)(this->debugv1.z + v41.z);
    v50[0] = this->debugv1.x + v41.x;
    v50[1] = v15;
    v50[2] = v16;
    v14->DebugLine(
      this: v14,
      a2: (const idVec4 *)&idColor::colorWhite,
      a3: &v41,
      a4: (const idVec3 *)v50,
      a5: 0,
      a6: false);
    v17 = common->RW(this: common);
    v18 = (float)(this->debugv2.y + v41.y);
    v19 = (float)(this->debugv2.z + v41.z);
    v48[0] = this->debugv2.x + v41.x;
    v48[1] = v18;
    v48[2] = v19;
    v17->DebugLine(
      this: v17,
      a2: (const idVec4 *)&idColor::colorBlue,
      a3: &v41,
      a4: (const idVec3 *)v48,
      a5: 0,
      a6: false);
    v20 = common->RW(this: common);
    v21 = (float)(this->debugv3.x + v42);
    v22 = (float)(this->debugv3.y + v43);
    v49[2] = this->debugv3.z + v44;
    v49[0] = v21;
    v49[1] = v22;
    v20->DebugLine(
      this: v20,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: (const idVec3 *)&v42,
      a4: (const idVec3 *)v49,
      a5: 0,
      a6: false);
    idClip::DrawSingleClipModel(this: this->clip, clipModel: this->wheelModel, origin: &v41, axis: &v52, lifeTime: 0);
    v51[0] = this->debugf1;
    v51[1] = 1.0;
    v51[2] = 0.0;
    v51[3] = 1.0;
    v23 = common->RW(this: common);
    debugf4 = this->debugf4;
    LODWORD(v24) = LODWORD(debugf4);
    debugf3 = this->debugf3;
    HIDWORD(v24) = LODWORD(debugf3);
    debugf2 = this->debugf2;
    LODWORD(v25) = LODWORD(debugf2);
    *(double *)((char *)&v25 + 4) = this->debugf1;
    v27 = va::va(
            this: &v54,
            fmt: (const char *)DWORD1(v25),
            a3: v25,
            a4: v24,
            a5: v26,
            a6: v32,
            a7: v33,
            a8: v34,
            a9: v35,
            a10: v36,
            a11: v37);
    ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const idMat3 *, const int, const int, const bool, const bool), float *, idMat3 *, int, _DWORD, double))v23->DebugText_2)(
      a1: v23,
      a2: v27,
      a3: &v41,
      a4: v23->DebugText_2,
      a5: v51,
      a6: &v46,
      a7: 1,
      a8: 0,
      a9: (float)(this->wheelRadius * (float)0.02));
    if ( *this->hi.p >= (double)BOX_SCALE_MAX )
    {
      v28 = common->RW(this: common);
      v29 = (float)(v52.mat[2].x * this->wheelRadius);
      v30 = (float)(v52.mat[2].y * this->wheelRadius);
      v31 = (float)(this->wheelRadius * (float)0.02);
      v47[2] = (float)(v52.mat[2].z * this->wheelRadius) + v41.z;
      v47[0] = (float)v29 + v41.x;
      v47[1] = (float)v30 + v41.y;
      ((void (__fastcall *)(idRenderWorld *, const char *, float *, idRenderWorld_vtbl *, idColor *, idMat3 *, int, _DWORD, double))v28->DebugText_2)(
        a1: v28,
        a2: "!!",
        a3: v47,
        a4: v28->__vftable,
        a5: &idColor::colorWhite,
        a6: &v46,
        a7: 1,
        a8: 0,
        a9: v31);
    }
  }
}


// ========================================================================
// ?Evaluate@idAFConstraint_Fixed@@MAAXPBVidPhysics_AF@@M@Z
// EA  : 0x82721630
// RVA : 0x00721630
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Fixed::Evaluate(
        idAFConstraint_Fixed *this,
        const idPhysics_AF *phys,
        double invTimeStep)
{
  double LcpEpsilon; // fp1
  float *p; // r11
  idAFBody *body2; // r11
  idPhysics_AF *physics; // r11
  idClipModel *clipModel; // r10
  double v11; // fp28
  double v12; // fp29
  double v13; // fp30
  double v14; // fp27
  double v15; // fp26
  double v16; // fp25
  float *v17; // r3
  double v18; // fp4
  double v19; // fp3
  double v20; // fp2
  double v21; // fp1
  double v22; // fp0
  double v23; // fp13
  double v24; // fp12
  double v25; // fp11
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v29; // fp10
  double v30; // fp9
  double v31; // fp8
  double v32; // fp7
  double v33; // fp6
  idClipModel *v34; // r11
  double v35; // fp31
  double v36; // fp30
  double v37; // fp29
  double ErrorReduction; // fp1
  float *v39; // r10
  double v40; // fp10
  float *v41; // r11
  double v42; // fp5
  double v43; // fp4
  double v44; // fp3
  double v45; // fp2
  double v46; // fp1
  double v47; // fp0
  double v48; // fp13
  double v49; // fp12
  idRotation *v50; // r3
  idRotation *v51; // r3
  double v52; // fp10
  double v53; // fp31
  double v54; // fp30
  double v55; // fp29
  double v56; // fp1
  float *v57; // r11
  double v58; // fp4
  double ErrorReductionMax; // fp31
  double v60; // fp1
  idMat3 v61; // [sp+50h] [-140h] BYREF
  idMat3 v62; // [sp+80h] [-110h] BYREF
  idMat3 v63; // [sp+B0h] [-E0h] BYREF
  idMat3 v64[3]; // [sp+E0h] [-B0h] BYREF

  if ( this->body1 != nullptr )
  {
    LcpEpsilon = idPhysics_AF::GetLcpEpsilon(this: phys);
    p = this->e.p;
    *p = LcpEpsilon;
    p[1] = LcpEpsilon;
    p[2] = LcpEpsilon;
    p[3] = LcpEpsilon;
    p[4] = LcpEpsilon;
    p[5] = LcpEpsilon;
    body2 = this->body2;
    if ( body2 != nullptr || (physics = this->physics) != nullptr && (body2 = physics->masterBody) != nullptr )
    {
      clipModel = body2->clipModel;
      v11 = (float)((float)(this->offset.x * clipModel->axis.mat[0].x)
                  + (float)((float)(clipModel->axis.mat[1].x * this->offset.y)
                          + (float)(clipModel->axis.mat[2].x * this->offset.z)));
      v12 = (float)((float)(clipModel->axis.mat[2].y * this->offset.z)
                  + (float)((float)(clipModel->axis.mat[0].y * this->offset.x)
                          + (float)(clipModel->axis.mat[1].y * this->offset.y)));
      v13 = (float)((float)(clipModel->axis.mat[2].z * this->offset.z)
                  + (float)((float)(clipModel->axis.mat[0].z * this->offset.x)
                          + (float)(clipModel->axis.mat[1].z * this->offset.y)));
      v14 = (float)(clipModel->origin.x
                  + (float)((float)(this->offset.x * clipModel->axis.mat[0].x)
                          + (float)((float)(clipModel->axis.mat[1].x * this->offset.y)
                                  + (float)(clipModel->axis.mat[2].x * this->offset.z))));
      v15 = (float)(clipModel->origin.y
                  + (float)((float)(clipModel->axis.mat[2].y * this->offset.z)
                          + (float)((float)(clipModel->axis.mat[0].y * this->offset.x)
                                  + (float)(clipModel->axis.mat[1].y * this->offset.y))));
      v16 = (float)(clipModel->origin.z
                  + (float)((float)(clipModel->axis.mat[2].z * this->offset.z)
                          + (float)((float)(clipModel->axis.mat[0].z * this->offset.x)
                                  + (float)(clipModel->axis.mat[1].z * this->offset.y))));
      v17 = (float *)idMat3::operator*(this: &v61, result: &this->relAxis, a: &clipModel->axis);
      v18 = v17[1];
      v19 = v17[2];
      v20 = v17[3];
      v21 = v17[4];
      v22 = v17[5];
      v23 = v17[6];
      v24 = v17[7];
      v25 = v17[8];
      v62.mat[0].x = *v17;
      v62.mat[0].y = v18;
      v62.mat[0].z = v19;
      v62.mat[1].x = v20;
      v62.mat[1].y = v21;
      v62.mat[1].z = v22;
      v62.mat[2].x = v23;
      v62.mat[2].y = v24;
      v62.mat[2].z = v25;
    }
    else
    {
      v13 = 0.0;
      y = this->relAxis.mat[0].y;
      v12 = 0.0;
      z = this->relAxis.mat[0].z;
      v11 = 0.0;
      x = this->relAxis.mat[1].x;
      v29 = this->relAxis.mat[1].y;
      v30 = this->relAxis.mat[1].z;
      v31 = this->relAxis.mat[2].x;
      v32 = this->relAxis.mat[2].y;
      v33 = this->relAxis.mat[2].z;
      v14 = this->offset.x;
      v15 = this->offset.y;
      v16 = this->offset.z;
      v62.mat[0].x = this->relAxis.mat[0].x;
      v62.mat[0].y = y;
      v62.mat[0].z = z;
      v62.mat[1].x = x;
      v62.mat[1].y = v29;
      v62.mat[1].z = v30;
      v62.mat[2].x = v31;
      v62.mat[2].y = v32;
      v62.mat[2].z = v33;
    }
    idSpatialMat::Set(this: &this->J1, m1: &mat3_identity, m2: &mat3_zero, m3: &mat3_zero, m4: &mat3_identity);
    if ( this->body2 != nullptr )
    {
      v64[0].mat[0].x = -mat3_identity.mat[0].x;
      v64[0].mat[0].y = -mat3_identity.mat[0].y;
      v64[0].mat[0].z = -mat3_identity.mat[0].z;
      v64[0].mat[1].x = -mat3_identity.mat[1].x;
      v64[0].mat[1].y = -mat3_identity.mat[1].y;
      v64[0].mat[1].z = -mat3_identity.mat[1].z;
      v64[0].mat[2].x = -mat3_identity.mat[2].x;
      v64[0].mat[2].y = -mat3_identity.mat[2].y;
      v64[0].mat[2].z = -mat3_identity.mat[2].z;
      v63.mat[0].x = 0.0;
      v63.mat[0].y = -v13;
      v63.mat[0].z = v12;
      v63.mat[1].x = v13;
      v63.mat[1].y = 0.0;
      v63.mat[1].z = -v11;
      v63.mat[2].x = -v12;
      v63.mat[2].y = v11;
      v63.mat[2].z = 0.0;
      v61 = v64[0];
      idSpatialMat::Set(this: &this->J2, m1: &v61, m2: &v63, m3: &mat3_zero, m4: v64);
    }
    else
    {
      idSpatialMat::Zero(this: &this->J2, rows: 6, columns: 6);
    }
    v34 = this->body1->clipModel;
    v35 = (float)((float)v14 - v34->origin.x);
    v36 = (float)((float)v15 - v34->origin.y);
    v37 = (float)((float)v16 - v34->origin.z);
    ErrorReduction = idPhysics_AF::GetErrorReduction(this: phys);
    v39 = this->c1.p;
    v40 = -(float)((float)ErrorReduction * (float)invTimeStep);
    v39[2] = (float)v37 * (float)v40;
    *v39 = (float)v35 * (float)v40;
    v39[1] = (float)v36 * (float)v40;
    v41 = (float *)this->body1->clipModel;
    v42 = v41[18];
    v43 = v41[15];
    v44 = v41[12];
    v45 = v41[17];
    v46 = v41[14];
    v47 = v41[11];
    v48 = v41[19];
    v49 = v41[16];
    v61.mat[2].x = v41[13];
    v61.mat[2].y = v49;
    v61.mat[2].z = v48;
    v61.mat[1].z = v42;
    v61.mat[1].y = v43;
    v61.mat[1].x = v44;
    v61.mat[0].z = v45;
    v61.mat[0].y = v46;
    v61.mat[0].x = v47;
    v50 = (idRotation *)idMat3::operator*(this: &v63, result: &v61, a: &v62);
    v51 = idMat3::ToRotation(this: v64, result: v50);
    v52 = (float)(v51->angle * idMath::M_DEG2RAD);
    v53 = (float)(v51->vec.x * (float)-v52);
    v54 = (float)(v51->vec.y * (float)-v52);
    v55 = (float)(v51->vec.z * (float)-v52);
    v56 = idPhysics_AF::GetErrorReduction(this: phys);
    v57 = this->c1.p;
    v58 = -(float)((float)v56 * (float)invTimeStep);
    v57[3] = (float)v53 * (float)v58;
    v57[4] = (float)v54 * (float)v58;
    v57[5] = (float)v55 * (float)v58;
    if ( this->shouldClamp )
    {
      ErrorReductionMax = idPhysics_AF::GetErrorReductionMax(this: phys);
      v60 = idPhysics_AF::GetErrorReductionMax(this: phys);
      idSpatialVec::Clamp(this: &this->c1, min: -v60, max: ErrorReductionMax);
    }
  }
}


// ========================================================================
// ?SetAnchor@idAFConstraint_BallAndSocketJoint@@QAAXABVidVec3@@@Z
// EA  : 0x82721AB0
// RVA : 0x00721AB0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_BallAndSocketJoint::SetAnchor(
        idAFConstraint_BallAndSocketJoint *this,
        const idVec3 *worldPosition)
{
  idAFBody *body1; // r11
  float *clipModel; // r11
  double v4; // fp2
  double v5; // fp13
  double v6; // fp12
  double v7; // fp1
  double v8; // fp0
  idAFBody *body2; // r11
  float *v10; // r10
  double v11; // fp2
  double v12; // fp13
  double v13; // fp12
  double v14; // fp1
  double v15; // fp0
  idAFConstraint_ConeLimit *coneLimit; // r10
  idVec3 *p_anchor2; // r11
  idAFConstraint_PyramidLimit *pyramidLimit; // r10

  body1 = this->body1;
  if ( body1 != nullptr )
  {
    clipModel = (float *)body1->clipModel;
    v4 = (float)(worldPosition->x - clipModel[8]);
    v5 = clipModel[17];
    v6 = clipModel[14];
    v7 = (float)((float)((float)(worldPosition->y - clipModel[9]) * clipModel[15])
               + (float)((float)(worldPosition->z - clipModel[10]) * clipModel[16]));
    v8 = (float)((float)((float)(worldPosition->y - clipModel[9]) * clipModel[18])
               + (float)((float)(worldPosition->z - clipModel[10]) * clipModel[19]));
    this->anchor1.x = (float)((float)(worldPosition->x - clipModel[8]) * clipModel[11])
                    + (float)((float)((float)(worldPosition->y - clipModel[9]) * clipModel[12])
                            + (float)((float)(worldPosition->z - clipModel[10]) * clipModel[13]));
    this->anchor1.y = (float)((float)v4 * (float)v6) + (float)v7;
    this->anchor1.z = (float)((float)v4 * (float)v5) + (float)v8;
    body2 = this->body2;
    if ( body2 != nullptr )
    {
      v10 = (float *)body2->clipModel;
      v11 = (float)(worldPosition->x - v10[8]);
      v12 = v10[17];
      v13 = v10[14];
      v14 = (float)((float)((float)(worldPosition->y - v10[9]) * v10[15])
                  + (float)((float)(worldPosition->z - v10[10]) * v10[16]));
      v15 = (float)((float)((float)(worldPosition->y - v10[9]) * v10[18])
                  + (float)((float)(worldPosition->z - v10[10]) * v10[19]));
      this->anchor2.x = (float)((float)(worldPosition->x - v10[8]) * v10[11])
                      + (float)((float)((float)(worldPosition->y - v10[9]) * v10[12])
                              + (float)((float)(worldPosition->z - v10[10]) * v10[13]));
      this->anchor2.y = (float)((float)v11 * (float)v13) + (float)v14;
      this->anchor2.z = (float)((float)v11 * (float)v12) + (float)v15;
    }
    else
    {
      this->anchor2 = *worldPosition;
    }
    coneLimit = this->coneLimit;
    p_anchor2 = &this->anchor2;
    if ( coneLimit != nullptr )
    {
      coneLimit->coneAnchor.x = p_anchor2->x;
      coneLimit->coneAnchor.y = this->anchor2.y;
      coneLimit->coneAnchor.z = this->anchor2.z;
    }
    pyramidLimit = this->pyramidLimit;
    if ( pyramidLimit != nullptr )
    {
      pyramidLimit->pyramidAnchor.x = p_anchor2->x;
      pyramidLimit->pyramidAnchor.y = this->anchor2.y;
      pyramidLimit->pyramidAnchor.z = this->anchor2.z;
    }
  }
}


// ========================================================================
// ?Evaluate@idAFConstraint_BallAndSocketJoint@@MAAXPBVidPhysics_AF@@M@Z
// EA  : 0x82721C30
// RVA : 0x00721C30
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_BallAndSocketJoint::Evaluate(
        idAFConstraint_BallAndSocketJoint *this,
        const idPhysics_AF *phys,
        double invTimeStep)
{
  double LcpEpsilon; // fp1
  float *p; // r11
  idAFBody *body2; // r10
  idPhysics_AF *physics; // r11
  float *clipModel; // r11
  double v11; // fp30
  double v12; // fp29
  double v13; // fp28
  double v14; // fp27
  double v15; // fp26
  double v16; // fp25
  float *v17; // r10
  double v18; // fp21
  double v19; // fp23
  double v20; // fp22
  double ErrorReduction; // fp1
  float *v22; // r9
  double v23; // fp12
  double v24; // fp23
  double v25; // fp22
  double v26; // fp21
  double v27; // fp1
  float *v28; // r11
  double v29; // fp4
  double ErrorReductionMax; // fp23
  double v31; // fp1
  idSpatialMat *p_J2; // r3
  idAFConstraint_ConeLimit *coneLimit; // r3
  idAFConstraint_PyramidLimit *pyramidLimit; // r3
  idMat3 v35; // [sp+50h] [-D0h] BYREF
  idMat3 v36; // [sp+80h] [-A0h] BYREF

  if ( this->body1 != nullptr )
  {
    LcpEpsilon = idPhysics_AF::GetLcpEpsilon(this: phys);
    p = this->e.p;
    *p = LcpEpsilon;
    p[1] = LcpEpsilon;
    p[2] = LcpEpsilon;
    p[3] = LcpEpsilon;
    p[4] = LcpEpsilon;
    p[5] = LcpEpsilon;
    body2 = this->body2;
    if ( body2 == nullptr )
    {
      physics = this->physics;
      if ( physics != nullptr )
        body2 = physics->masterBody;
    }
    clipModel = (float *)this->body1->clipModel;
    v11 = 0.0;
    v12 = 0.0;
    v13 = 0.0;
    v14 = (float)((float)(this->anchor1.x * clipModel[11])
                + (float)((float)(clipModel[14] * this->anchor1.y) + (float)(clipModel[17] * this->anchor1.z)));
    v15 = (float)((float)(clipModel[18] * this->anchor1.z)
                + (float)((float)(clipModel[12] * this->anchor1.x) + (float)(clipModel[15] * this->anchor1.y)));
    v16 = (float)((float)(clipModel[19] * this->anchor1.z)
                + (float)((float)(clipModel[13] * this->anchor1.x) + (float)(clipModel[16] * this->anchor1.y)));
    if ( body2 != nullptr )
    {
      v17 = (float *)body2->clipModel;
      v12 = (float)((float)(v17[18] * this->anchor2.z)
                  + (float)((float)(v17[12] * this->anchor2.x) + (float)(v17[15] * this->anchor2.y)));
      v11 = (float)((float)(v17[11] * this->anchor2.x)
                  + (float)((float)(v17[14] * this->anchor2.y) + (float)(v17[17] * this->anchor2.z)));
      v13 = (float)((float)(v17[19] * this->anchor2.z)
                  + (float)((float)(v17[13] * this->anchor2.x) + (float)(v17[16] * this->anchor2.y)));
      v18 = (float)((float)(v17[9]
                          + (float)((float)(v17[18] * this->anchor2.z)
                                  + (float)((float)(v17[12] * this->anchor2.x) + (float)(v17[15] * this->anchor2.y))))
                  - (float)(clipModel[9]
                          + (float)((float)(clipModel[18] * this->anchor1.z)
                                  + (float)((float)(clipModel[12] * this->anchor1.x)
                                          + (float)(clipModel[15] * this->anchor1.y)))));
      v19 = (float)((float)(v17[8]
                          + (float)((float)(v17[11] * this->anchor2.x)
                                  + (float)((float)(v17[14] * this->anchor2.y) + (float)(v17[17] * this->anchor2.z))))
                  - (float)(clipModel[8]
                          + (float)((float)(this->anchor1.x * clipModel[11])
                                  + (float)((float)(clipModel[14] * this->anchor1.y)
                                          + (float)(clipModel[17] * this->anchor1.z)))));
      v20 = (float)((float)(v17[10]
                          + (float)((float)(v17[19] * this->anchor2.z)
                                  + (float)((float)(v17[13] * this->anchor2.x) + (float)(v17[16] * this->anchor2.y))))
                  - (float)(clipModel[10]
                          + (float)((float)(clipModel[19] * this->anchor1.z)
                                  + (float)((float)(clipModel[13] * this->anchor1.x)
                                          + (float)(clipModel[16] * this->anchor1.y)))));
      ErrorReduction = idPhysics_AF::GetErrorReduction(this: phys);
      v22 = this->c1.p;
      v23 = -(float)((float)ErrorReduction * (float)invTimeStep);
      *v22 = (float)v19 * (float)v23;
      v22[1] = (float)v18 * (float)v23;
      v22[2] = (float)v20 * (float)v23;
    }
    else
    {
      v24 = (float)(this->anchor2.x
                  - (float)((float)((float)(this->anchor1.x * clipModel[11])
                                  + (float)((float)(clipModel[14] * this->anchor1.y)
                                          + (float)(clipModel[17] * this->anchor1.z)))
                          + clipModel[8]));
      v25 = (float)(this->anchor2.y
                  - (float)(clipModel[9]
                          + (float)((float)(clipModel[18] * this->anchor1.z)
                                  + (float)((float)(clipModel[12] * this->anchor1.x)
                                          + (float)(clipModel[15] * this->anchor1.y)))));
      v26 = (float)(this->anchor2.z
                  - (float)(clipModel[10]
                          + (float)((float)(clipModel[19] * this->anchor1.z)
                                  + (float)((float)(clipModel[13] * this->anchor1.x)
                                          + (float)(clipModel[16] * this->anchor1.y)))));
      v27 = idPhysics_AF::GetErrorReduction(this: phys);
      v28 = this->c1.p;
      v29 = -(float)((float)v27 * (float)invTimeStep);
      *v28 = (float)v24 * (float)v29;
      v28[1] = (float)v25 * (float)v29;
      v28[2] = (float)v26 * (float)v29;
    }
    ErrorReductionMax = idPhysics_AF::GetErrorReductionMax(this: phys);
    v31 = idPhysics_AF::GetErrorReductionMax(this: phys);
    idSpatialVec::Clamp(this: &this->c1, min: -v31, max: ErrorReductionMax);
    v35.mat[0].z = -v15;
    v35.mat[1].x = -v16;
    v35.mat[2].y = -v14;
    v35.mat[0].x = -0.0;
    v35.mat[1].y = -0.0;
    v35.mat[2].z = -0.0;
    v35.mat[2].x = --v15;
    v35.mat[1].z = --v14;
    v35.mat[0].y = --v16;
    idSpatialMat::Set(this: &this->J1, m1: &mat3_identity, m2: &v35);
    p_J2 = &this->J2;
    if ( this->body2 != nullptr )
    {
      v35.mat[0].x = 0.0;
      v35.mat[0].z = v12;
      v35.mat[1].x = v13;
      v35.mat[1].y = 0.0;
      v35.mat[2].y = v11;
      v35.mat[2].z = 0.0;
      v36.mat[0].x = -mat3_identity.mat[0].x;
      v35.mat[2].x = -v12;
      v35.mat[1].z = -v11;
      v35.mat[0].y = -v13;
      v36.mat[0].y = -mat3_identity.mat[0].y;
      v36.mat[0].z = -mat3_identity.mat[0].z;
      v36.mat[1].x = -mat3_identity.mat[1].x;
      v36.mat[1].y = -mat3_identity.mat[1].y;
      v36.mat[1].z = -mat3_identity.mat[1].z;
      v36.mat[2].x = -mat3_identity.mat[2].x;
      v36.mat[2].y = -mat3_identity.mat[2].y;
      v36.mat[2].z = -mat3_identity.mat[2].z;
      idSpatialMat::Set(this: p_J2, m1: &v36, m2: &v35);
    }
    else
    {
      idSpatialMat::Zero(this: p_J2, rows: 3, columns: 6);
    }
    coneLimit = this->coneLimit;
    if ( coneLimit != nullptr )
    {
      idAFConstraint_ConeLimit::Add(this: coneLimit, phys: this->physics, invTimeStep);
    }
    else
    {
      pyramidLimit = this->pyramidLimit;
      if ( pyramidLimit != nullptr )
        idAFConstraint_PyramidLimit::Add(this: pyramidLimit, phys: this->physics, invTimeStep);
    }
  }
}


// ========================================================================
// ?SetAnchor@idAFConstraint_UniversalJoint@@QAAXABVidVec3@@@Z
// EA  : 0x82722038
// RVA : 0x00722038
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_UniversalJoint::SetAnchor(
        idAFConstraint_UniversalJoint *this,
        const idVec3 *worldPosition)
{
  idAFBody *body1; // r11
  float *clipModel; // r11
  double v4; // fp2
  double v5; // fp13
  double v6; // fp12
  double v7; // fp1
  double v8; // fp0
  idAFBody *body2; // r11
  float *v10; // r10
  double v11; // fp2
  double v12; // fp13
  double v13; // fp12
  double v14; // fp1
  double v15; // fp0
  idAFConstraint_ConeLimit *coneLimit; // r10
  idVec3 *p_anchor2; // r11
  idAFConstraint_PyramidLimit *pyramidLimit; // r10

  body1 = this->body1;
  if ( body1 != nullptr )
  {
    clipModel = (float *)body1->clipModel;
    v4 = (float)(worldPosition->x - clipModel[8]);
    v5 = clipModel[17];
    v6 = clipModel[14];
    v7 = (float)((float)((float)(worldPosition->y - clipModel[9]) * clipModel[15])
               + (float)((float)(worldPosition->z - clipModel[10]) * clipModel[16]));
    v8 = (float)((float)((float)(worldPosition->y - clipModel[9]) * clipModel[18])
               + (float)((float)(worldPosition->z - clipModel[10]) * clipModel[19]));
    this->anchor1.x = (float)((float)(worldPosition->x - clipModel[8]) * clipModel[11])
                    + (float)((float)((float)(worldPosition->y - clipModel[9]) * clipModel[12])
                            + (float)((float)(worldPosition->z - clipModel[10]) * clipModel[13]));
    this->anchor1.y = (float)((float)v4 * (float)v6) + (float)v7;
    this->anchor1.z = (float)((float)v4 * (float)v5) + (float)v8;
    body2 = this->body2;
    if ( body2 != nullptr )
    {
      v10 = (float *)body2->clipModel;
      v11 = (float)(worldPosition->x - v10[8]);
      v12 = v10[17];
      v13 = v10[14];
      v14 = (float)((float)((float)(worldPosition->y - v10[9]) * v10[15])
                  + (float)((float)(worldPosition->z - v10[10]) * v10[16]));
      v15 = (float)((float)((float)(worldPosition->y - v10[9]) * v10[18])
                  + (float)((float)(worldPosition->z - v10[10]) * v10[19]));
      this->anchor2.x = (float)((float)(worldPosition->x - v10[8]) * v10[11])
                      + (float)((float)((float)(worldPosition->y - v10[9]) * v10[12])
                              + (float)((float)(worldPosition->z - v10[10]) * v10[13]));
      this->anchor2.y = (float)((float)v11 * (float)v13) + (float)v14;
      this->anchor2.z = (float)((float)v11 * (float)v12) + (float)v15;
    }
    else
    {
      this->anchor2 = *worldPosition;
    }
    coneLimit = this->coneLimit;
    p_anchor2 = &this->anchor2;
    if ( coneLimit != nullptr )
    {
      coneLimit->coneAnchor.x = p_anchor2->x;
      coneLimit->coneAnchor.y = this->anchor2.y;
      coneLimit->coneAnchor.z = this->anchor2.z;
    }
    pyramidLimit = this->pyramidLimit;
    if ( pyramidLimit != nullptr )
    {
      pyramidLimit->pyramidAnchor.x = p_anchor2->x;
      pyramidLimit->pyramidAnchor.y = this->anchor2.y;
      pyramidLimit->pyramidAnchor.z = this->anchor2.z;
    }
  }
}


// ========================================================================
// ?SetShafts@idAFConstraint_UniversalJoint@@QAAXABVidVec3@@0@Z
// EA  : 0x827221B8
// RVA : 0x007221B8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_UniversalJoint::SetShafts(
        idAFConstraint_UniversalJoint *this,
        const idVec3 *cardanShaft1,
        const idVec3 *cardanShaft2)
{
  double x; // fp0
  double y; // fp13
  double v6; // fp8
  double z; // fp10
  double v8; // fp6
  idVec3 *p_shaft1; // r31
  idVec3 *p_shaft2; // r30
  double v13; // fp2
  double v14; // fp3
  double v15; // fp4
  double v16; // fp6
  double v17; // fp11
  double v18; // fp5
  double v19; // fp2
  double v22; // fp8
  double v23; // fp6
  double v24; // fp11
  double v25; // fp1
  double v26; // fp12
  double v27; // fp11
  double v28; // fp2
  double v29; // fp10
  double v30; // fp6
  double v33; // fp12
  double v34; // fp12
  double v35; // fp7
  double v36; // fp5
  double v37; // fp12
  double v38; // fp13
  double v39; // fp0
  double v40; // fp9
  float *clipModel; // r11
  double v42; // fp7
  double v43; // fp5
  double v44; // fp1
  double v45; // fp11
  float *v46; // r11
  double v47; // fp1
  double v48; // fp10
  double v49; // fp4
  double v50; // fp3
  idAFBody *body2; // r11
  float *v52; // r11
  double v53; // fp9
  double v54; // fp7
  double v55; // fp5
  double v56; // fp1
  double v57; // fp11
  float *v58; // r11
  double v59; // fp7
  double v60; // fp4
  double v61; // fp5
  double v62; // fp3
  idAFConstraint_ConeLimit *coneLimit; // r11
  idAFConstraint_PyramidLimit *pyramidLimit; // r11
  idVec3 v65; // [sp+50h] [-40h] BYREF
  idVec3 v66[4]; // [sp+60h] [-30h] BYREF

  if ( this->body1 != nullptr )
  {
    x = cardanShaft1->x;
    this->shaft1.x = cardanShaft1->x;
    y = cardanShaft1->y;
    v6 = (float)(cardanShaft1->y * cardanShaft1->y);
    this->shaft1.y = cardanShaft1->y;
    z = cardanShaft1->z;
    v8 = (float)((float)(cardanShaft1->z * cardanShaft1->z) + (float)((float)((float)x * (float)x) + (float)v6));
    this->shaft1.z = cardanShaft1->z;
    p_shaft1 = &this->shaft1;
    p_shaft2 = &this->shaft2;
    _FP5 = (float)((float)v8 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f5, f6, f12 }
    v13 = __frsqrte(_FP3);
    v14 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13
                                                                                        * (float)((float)v8 * (float)0.5))
                                                                                * (float)v13)
                                                                        - (float)1.5)
                                                        * (float)v13)
                                                * (float)((float)v8 * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v13
                                                                                * (float)((float)v8 * (float)0.5))
                                                                        * (float)v13)
                                                                - (float)1.5)
                                                * (float)v13))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13)
                                        - (float)1.5)
                        * (float)v13));
    this->shaft1.z = (float)z
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13) - (float)1.5) * (float)v13) * (float)((float)v8 * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13) - (float)1.5) * (float)v13))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13)
                                                                                           - (float)1.5)
                                                                           * (float)v13))
                                                           * (float)((float)v8 * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13) - (float)1.5) * (float)v13)
                                                                                           * (float)((float)v8 * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13) - (float)1.5)
                                                                                           * (float)v13))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5))
                                                                                           * (float)v13)
                                                                                   - (float)1.5)
                                                                   * (float)v13)))
                                           - (float)1.5)
                           * (float)v14);
    this->shaft1.x = (float)x
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13) - (float)1.5) * (float)v13) * (float)((float)v8 * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13) - (float)1.5) * (float)v13))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13)
                                                                                           - (float)1.5)
                                                                           * (float)v13))
                                                           * (float)((float)v8 * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13) - (float)1.5) * (float)v13)
                                                                                           * (float)((float)v8 * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13) - (float)1.5)
                                                                                           * (float)v13))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5))
                                                                                           * (float)v13)
                                                                                   - (float)1.5)
                                                                   * (float)v13)))
                                           - (float)1.5)
                           * (float)v14);
    this->shaft1.y = (float)y
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13) - (float)1.5) * (float)v13) * (float)((float)v8 * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13) - (float)1.5) * (float)v13))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13)
                                                                                           - (float)1.5)
                                                                           * (float)v13))
                                                           * (float)((float)v8 * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13) - (float)1.5) * (float)v13)
                                                                                           * (float)((float)v8 * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5)) * (float)v13) - (float)1.5)
                                                                                           * (float)v13))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)v8 * (float)0.5))
                                                                                           * (float)v13)
                                                                                   - (float)1.5)
                                                                   * (float)v13)))
                                           - (float)1.5)
                           * (float)v14);
    v15 = cardanShaft2->x;
    this->shaft2.x = cardanShaft2->x;
    v16 = cardanShaft2->y;
    v17 = (float)((float)((float)v15 * (float)v15) + (float)(cardanShaft2->y * cardanShaft2->y));
    this->shaft2.y = cardanShaft2->y;
    v18 = cardanShaft2->z;
    v19 = v16;
    this->shaft2.z = cardanShaft2->z;
    _FP9 = (float)((float)((float)((float)v18 * (float)v18) + (float)v17) - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f7, f9, f10, f12 }
    v22 = (float)((float)((float)((float)v18 * (float)v18) + (float)v17) * (float)0.5);
    v23 = __frsqrte(_FP7);
    v24 = (float)((float)-(float)((float)((float)((float)v23
                                                * (float)((float)((float)((float)v18 * (float)v18) + (float)v17)
                                                        * (float)0.5))
                                        * (float)v23)
                                - (float)1.5)
                * (float)v23);
    v25 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)v22)
                                                                                * (float)v24)
                                                                        - (float)1.5)
                                                        * (float)v24)
                                                * (float)v22)
                                        * (float)((float)-(float)((float)((float)((float)v24 * (float)v22) * (float)v24)
                                                                - (float)1.5)
                                                * (float)v24))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v24 * (float)v22) * (float)v24) - (float)1.5)
                        * (float)v24));
    v26 = (float)((float)v15
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)v22)
                                                                                        * (float)v24)
                                                                                - (float)1.5)
                                                                * (float)v24)
                                                        * (float)v22)
                                                * (float)((float)-(float)((float)((float)((float)v24 * (float)v22)
                                                                                * (float)v24)
                                                                        - (float)1.5)
                                                        * (float)v24))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v24 * (float)v22) * (float)v24) - (float)1.5)
                                * (float)v24)));
    this->shaft2.x = (float)v15
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)v22)
                                                                                           * (float)v24)
                                                                                   - (float)1.5)
                                                                   * (float)v24)
                                                           * (float)v22)
                                                   * (float)((float)-(float)((float)((float)((float)v24 * (float)v22)
                                                                                   * (float)v24)
                                                                           - (float)1.5)
                                                           * (float)v24))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v24 * (float)v22) * (float)v24) - (float)1.5)
                                   * (float)v24));
    v27 = (float)((float)v19
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)v22)
                                                                                        * (float)v24)
                                                                                - (float)1.5)
                                                                * (float)v24)
                                                        * (float)v22)
                                                * (float)((float)-(float)((float)((float)((float)v24 * (float)v22)
                                                                                * (float)v24)
                                                                        - (float)1.5)
                                                        * (float)v24))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v24 * (float)v22) * (float)v24) - (float)1.5)
                                * (float)v24)));
    this->shaft2.y = v27;
    this->shaft2.z = (float)v18 * (float)v25;
    v28 = (float)((float)(this->shaft1.x * (float)v27) - (float)((float)v26 * this->shaft1.y));
    v29 = (float)((float)(this->shaft1.y * (float)((float)v18 * (float)v25)) - (float)(this->shaft1.z * (float)v27));
    v30 = (float)((float)((float)v26 * this->shaft1.z) - (float)(this->shaft1.x * (float)((float)v18 * (float)v25)));
    _FP3 = (float)((float)((float)((float)v30 * (float)v30)
                         + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f13, f3, f4, f12 }
    v33 = __frsqrte(_FP13);
    v34 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33
                                                                                        * (float)((float)((float)((float)v30 * (float)v30) + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28)))
                                                                                                * (float)0.5))
                                                                                * (float)v33)
                                                                        - (float)1.5)
                                                        * (float)v33)
                                                * (float)((float)((float)((float)v30 * (float)v30)
                                                                + (float)((float)((float)v29 * (float)v29)
                                                                        + (float)((float)v28 * (float)v28)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v33
                                                                                * (float)((float)((float)((float)v30 * (float)v30)
                                                                                                + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28)))
                                                                                        * (float)0.5))
                                                                        * (float)v33)
                                                                - (float)1.5)
                                                * (float)v33))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v33
                                                        * (float)((float)((float)((float)v30 * (float)v30)
                                                                        + (float)((float)((float)v29 * (float)v29)
                                                                                + (float)((float)v28 * (float)v28)))
                                                                * (float)0.5))
                                                * (float)v33)
                                        - (float)1.5)
                        * (float)v33));
    v35 = (float)((float)-(float)((float)((float)((float)v34
                                                * (float)((float)((float)((float)v30 * (float)v30)
                                                                + (float)((float)((float)v29 * (float)v29)
                                                                        + (float)((float)v28 * (float)v28)))
                                                        * (float)0.5))
                                        * (float)v34)
                                - (float)1.5)
                * (float)v34);
    v36 = (float)((float)((float)-(float)((float)((float)((float)v34
                                                        * (float)((float)((float)((float)v30 * (float)v30)
                                                                        + (float)((float)((float)v29 * (float)v29)
                                                                                + (float)((float)v28 * (float)v28)))
                                                                * (float)0.5))
                                                * (float)v34)
                                        - (float)1.5)
                        * (float)v34)
                * (float)((float)((float)v30 * (float)v30)
                        + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28))));
    v37 = (float)((float)((float)-(float)((float)((float)((float)v34
                                                        * (float)((float)((float)((float)v30 * (float)v30)
                                                                        + (float)((float)((float)v29 * (float)v29)
                                                                                + (float)((float)v28 * (float)v28)))
                                                                * (float)0.5))
                                                * (float)v34)
                                        - (float)1.5)
                        * (float)v34)
                * (float)v29);
    v65.x = v37;
    v38 = (float)((float)v30 * (float)v35);
    v65.y = (float)v30 * (float)v35;
    v39 = (float)((float)v28 * (float)v35);
    v65.z = (float)v28 * (float)v35;
    if ( v36 == 0.0 )
    {
      idVec3::OrthogonalBasis(this: &this->shaft1, left: &v65, up: v66);
      idVec3::NormalizeFast(this: &v65);
      v39 = v65.z;
      v38 = v65.y;
      v37 = v65.x;
    }
    v40 = p_shaft1->y;
    clipModel = (float *)this->body1->clipModel;
    v42 = clipModel[15];
    v43 = clipModel[12];
    v44 = (float)((float)(p_shaft1->z * clipModel[16]) + (float)(p_shaft1->x * clipModel[14]));
    v45 = (float)((float)(p_shaft1->z * clipModel[13]) + (float)(p_shaft1->x * clipModel[11]));
    p_shaft1->z = (float)(p_shaft1->y * clipModel[18])
                + (float)((float)(p_shaft1->z * clipModel[19]) + (float)(p_shaft1->x * clipModel[17]));
    p_shaft1->y = (float)((float)v40 * (float)v42) + (float)v44;
    p_shaft1->x = (float)((float)v40 * (float)v43) + (float)v45;
    v46 = (float *)this->body1->clipModel;
    v47 = v46[17];
    v48 = v46[11];
    v49 = (float)((float)((float)v38 * v46[18]) + (float)((float)v39 * v46[19]));
    v50 = (float)((float)((float)v38 * v46[12]) + (float)((float)v39 * v46[13]));
    this->axis1.y = (float)(v46[14] * (float)v37)
                  + (float)((float)((float)v38 * v46[15]) + (float)((float)v39 * v46[16]));
    this->axis1.z = (float)((float)v47 * (float)v37) + (float)v49;
    this->axis1.x = (float)((float)v48 * (float)v37) + (float)v50;
    body2 = this->body2;
    if ( body2 != nullptr )
    {
      v52 = (float *)body2->clipModel;
      v53 = p_shaft2->z;
      v54 = v52[16];
      v55 = v52[13];
      v56 = (float)((float)(p_shaft2->x * v52[14]) + (float)(p_shaft2->y * v52[15]));
      v57 = (float)((float)(p_shaft2->x * v52[11]) + (float)(p_shaft2->y * v52[12]));
      p_shaft2->z = (float)(p_shaft2->z * v52[19])
                  + (float)((float)(p_shaft2->x * v52[17]) + (float)(p_shaft2->y * v52[18]));
      p_shaft2->y = (float)((float)v53 * (float)v54) + (float)v56;
      p_shaft2->x = (float)((float)v53 * (float)v55) + (float)v57;
      v58 = (float *)this->body2->clipModel;
      v59 = v58[15];
      v60 = v58[12];
      v61 = (float)((float)((float)v39 * v58[16]) + (float)(v58[14] * (float)v37));
      v62 = (float)((float)((float)v39 * v58[13]) + (float)(v58[11] * (float)v37));
      this->axis2.z = (float)(v58[17] * (float)v37)
                    + (float)((float)((float)v38 * v58[18]) + (float)((float)v39 * v58[19]));
      this->axis2.y = (float)((float)v38 * (float)v59) + (float)v61;
      this->axis2.x = (float)((float)v38 * (float)v60) + (float)v62;
    }
    else
    {
      this->axis2.x = v37;
      this->axis2.y = v38;
      this->axis2.z = v39;
    }
    coneLimit = this->coneLimit;
    if ( coneLimit != nullptr )
    {
      coneLimit->body1Axis.x = p_shaft1->x;
      coneLimit->body1Axis.y = p_shaft1->y;
      coneLimit->body1Axis.z = p_shaft1->z;
    }
    pyramidLimit = this->pyramidLimit;
    if ( pyramidLimit != nullptr )
    {
      pyramidLimit->body1Axis.x = p_shaft1->x;
      pyramidLimit->body1Axis.y = p_shaft1->y;
      pyramidLimit->body1Axis.z = p_shaft1->z;
    }
  }
}


// ========================================================================
// ?Evaluate@idAFConstraint_UniversalJoint@@MAAXPBVidPhysics_AF@@M@Z
// EA  : 0x827225B0
// RVA : 0x007225B0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_UniversalJoint::Evaluate(
        idAFConstraint_UniversalJoint *this,
        const idPhysics_AF *phys,
        double invTimeStep)
{
  double LcpEpsilon; // fp1
  float *p; // r11
  idAFBody *body2; // r10
  idPhysics_AF *physics; // r11
  idMat3 *p_axis; // r11
  double v10; // fp21
  double v11; // fp20
  double v12; // fp19
  double v13; // fp31
  double v14; // fp18
  double v15; // fp17
  float *clipModel; // r11
  float *v17; // r10
  double z; // fp25
  double y; // fp26
  double x; // fp27
  double v21; // fp30
  double v22; // fp23
  double v23; // fp29
  double v24; // fp22
  double v25; // fp28
  double v26; // fp24
  double v27; // fp15
  double v28; // fp14
  double ErrorReduction; // fp1
  double v30; // fp16
  float *v31; // r8
  double v32; // fp12
  float *v33; // r11
  double v34; // fp15
  double v35; // fp14
  double v36; // fp1
  float *v37; // r10
  double v38; // fp7
  double v39; // fp8
  double v40; // fp7
  double v41; // fp6
  double v44; // fp12
  double v45; // fp13
  double v46; // fp10
  double v47; // fp9
  double v48; // fp0
  double v49; // fp13
  float *v50; // r3
  double v51; // fp6
  double v52; // fp0
  float *v53; // r30
  float *v54; // r30
  double ErrorReductionMax; // fp31
  double v56; // fp1
  idAFConstraint_ConeLimit *coneLimit; // r3
  idAFConstraint_PyramidLimit *pyramidLimit; // r3
  float v59; // [sp+50h] [-170h]
  float v60; // [sp+50h] [-170h]
  float v61; // [sp+58h] [-168h]
  float v62; // [sp+5Ch] [-164h]
  float v63; // [sp+60h] [-160h]
  idMat3 v64; // [sp+70h] [-150h] BYREF
  idMat3 v65; // [sp+A0h] [-120h] BYREF
  idMat3 v66[5]; // [sp+D0h] [-F0h] BYREF
  float v67; // [sp+1E4h] [+24h]

  v67 = invTimeStep;
  if ( this->body1 != nullptr )
  {
    LcpEpsilon = idPhysics_AF::GetLcpEpsilon(this: phys);
    p = this->e.p;
    *p = LcpEpsilon;
    p[1] = LcpEpsilon;
    p[2] = LcpEpsilon;
    p[3] = LcpEpsilon;
    p[4] = LcpEpsilon;
    p[5] = LcpEpsilon;
    body2 = this->body2;
    if ( body2 == nullptr )
    {
      physics = this->physics;
      if ( physics != nullptr )
        body2 = physics->masterBody;
    }
    p_axis = &this->body1->clipModel->axis;
    v10 = (float)((float)(p_axis->mat[0].x * this->shaft1.x)
                + (float)((float)(this->body1->clipModel->axis.mat[1].x * this->shaft1.y)
                        + (float)(this->body1->clipModel->axis.mat[2].x * this->shaft1.z)));
    v11 = (float)((float)(this->body1->clipModel->axis.mat[2].y * this->shaft1.z)
                + (float)((float)(this->body1->clipModel->axis.mat[0].y * this->shaft1.x)
                        + (float)(this->body1->clipModel->axis.mat[1].y * this->shaft1.y)));
    v12 = (float)((float)(this->body1->clipModel->axis.mat[2].z * this->shaft1.z)
                + (float)((float)(this->body1->clipModel->axis.mat[0].z * this->shaft1.x)
                        + (float)(this->body1->clipModel->axis.mat[1].z * this->shaft1.y)));
    v13 = (float)((float)(this->anchor1.x * p_axis->mat[0].x)
                + (float)((float)(this->body1->clipModel->axis.mat[1].x * this->anchor1.y)
                        + (float)(this->body1->clipModel->axis.mat[2].x * this->anchor1.z)));
    v14 = (float)((float)(this->body1->clipModel->axis.mat[2].y * this->anchor1.z)
                + (float)((float)(this->body1->clipModel->axis.mat[0].y * this->anchor1.x)
                        + (float)(this->body1->clipModel->axis.mat[1].y * this->anchor1.y)));
    v61 = (float)((float)((float)(this->body1->clipModel->axis.mat[2].z * this->axis1.z)
                        + (float)((float)(this->body1->clipModel->axis.mat[0].z * this->axis1.x)
                                + (float)(this->body1->clipModel->axis.mat[1].z * this->axis1.y)))
                * (float)((float)(this->body1->clipModel->axis.mat[2].y * this->shaft1.z)
                        + (float)((float)(this->body1->clipModel->axis.mat[0].y * this->shaft1.x)
                                + (float)(this->body1->clipModel->axis.mat[1].y * this->shaft1.y))))
        - (float)((float)((float)(this->body1->clipModel->axis.mat[2].y * this->axis1.z)
                        + (float)((float)(this->body1->clipModel->axis.mat[0].y * this->axis1.x)
                                + (float)(this->body1->clipModel->axis.mat[1].y * this->axis1.y)))
                * (float)((float)(this->body1->clipModel->axis.mat[2].z * this->shaft1.z)
                        + (float)((float)(this->body1->clipModel->axis.mat[0].z * this->shaft1.x)
                                + (float)(this->body1->clipModel->axis.mat[1].z * this->shaft1.y))));
    v63 = (float)((float)((float)(this->body1->clipModel->axis.mat[2].y * this->axis1.z)
                        + (float)((float)(this->body1->clipModel->axis.mat[0].y * this->axis1.x)
                                + (float)(this->body1->clipModel->axis.mat[1].y * this->axis1.y)))
                * (float)((float)(p_axis->mat[0].x * this->shaft1.x)
                        + (float)((float)(this->body1->clipModel->axis.mat[1].x * this->shaft1.y)
                                + (float)(this->body1->clipModel->axis.mat[2].x * this->shaft1.z))))
        - (float)((float)((float)(this->body1->clipModel->axis.mat[2].y * this->shaft1.z)
                        + (float)((float)(this->body1->clipModel->axis.mat[0].y * this->shaft1.x)
                                + (float)(this->body1->clipModel->axis.mat[1].y * this->shaft1.y)))
                * (float)((float)(this->axis1.x * p_axis->mat[0].x)
                        + (float)((float)(this->body1->clipModel->axis.mat[1].x * this->axis1.y)
                                + (float)(this->body1->clipModel->axis.mat[2].x * this->axis1.z))));
    v62 = (float)((float)((float)(this->body1->clipModel->axis.mat[2].z * this->shaft1.z)
                        + (float)((float)(this->body1->clipModel->axis.mat[0].z * this->shaft1.x)
                                + (float)(this->body1->clipModel->axis.mat[1].z * this->shaft1.y)))
                * (float)((float)(this->axis1.x * p_axis->mat[0].x)
                        + (float)((float)(this->body1->clipModel->axis.mat[1].x * this->axis1.y)
                                + (float)(this->body1->clipModel->axis.mat[2].x * this->axis1.z))))
        - (float)((float)((float)(this->body1->clipModel->axis.mat[2].z * this->axis1.z)
                        + (float)((float)(this->body1->clipModel->axis.mat[0].z * this->axis1.x)
                                + (float)(this->body1->clipModel->axis.mat[1].z * this->axis1.y)))
                * (float)((float)(p_axis->mat[0].x * this->shaft1.x)
                        + (float)((float)(this->body1->clipModel->axis.mat[1].x * this->shaft1.y)
                                + (float)(this->body1->clipModel->axis.mat[2].x * this->shaft1.z))));
    v15 = (float)((float)(this->body1->clipModel->axis.mat[2].z * this->anchor1.z)
                + (float)((float)(this->body1->clipModel->axis.mat[0].z * this->anchor1.x)
                        + (float)(this->body1->clipModel->axis.mat[1].z * this->anchor1.y)));
    if ( body2 != nullptr )
    {
      clipModel = (float *)body2->clipModel;
      v17 = (float *)this->body1->clipModel;
      z = (float)((float)(clipModel[19] * this->anchor2.z)
                + (float)((float)(clipModel[13] * this->anchor2.x) + (float)(clipModel[16] * this->anchor2.y)));
      y = (float)((float)(clipModel[18] * this->anchor2.z)
                + (float)((float)(clipModel[12] * this->anchor2.x) + (float)(clipModel[15] * this->anchor2.y)));
      x = (float)((float)(this->anchor2.x * clipModel[11])
                + (float)((float)(clipModel[14] * this->anchor2.y) + (float)(clipModel[17] * this->anchor2.z)));
      v21 = (float)((float)(clipModel[11] * this->shaft2.x)
                  + (float)((float)(clipModel[14] * this->shaft2.y) + (float)(clipModel[17] * this->shaft2.z)));
      v22 = (float)((float)(this->axis2.x * clipModel[11])
                  + (float)((float)(clipModel[14] * this->axis2.y) + (float)(clipModel[17] * this->axis2.z)));
      v23 = (float)((float)(clipModel[18] * this->shaft2.z)
                  + (float)((float)(clipModel[12] * this->shaft2.x) + (float)(clipModel[15] * this->shaft2.y)));
      v24 = (float)((float)(clipModel[18] * this->axis2.z)
                  + (float)((float)(clipModel[12] * this->axis2.x) + (float)(clipModel[15] * this->axis2.y)));
      v25 = (float)((float)(clipModel[19] * this->shaft2.z)
                  + (float)((float)(clipModel[13] * this->shaft2.x) + (float)(clipModel[16] * this->shaft2.y)));
      v26 = (float)((float)(clipModel[19] * this->axis2.z)
                  + (float)((float)(clipModel[13] * this->axis2.x) + (float)(clipModel[16] * this->axis2.y)));
      v27 = (float)((float)((float)((float)(this->anchor2.x * clipModel[11])
                                  + (float)((float)(clipModel[14] * this->anchor2.y)
                                          + (float)(clipModel[17] * this->anchor2.z)))
                          + clipModel[8])
                  - (float)((float)v13 + v17[8]));
      v28 = (float)((float)(clipModel[9]
                          + (float)((float)(clipModel[18] * this->anchor2.z)
                                  + (float)((float)(clipModel[12] * this->anchor2.x)
                                          + (float)(clipModel[15] * this->anchor2.y))))
                  - (float)(v17[9]
                          + (float)((float)(v17[18] * this->anchor1.z)
                                  + (float)((float)(v17[12] * this->anchor1.x) + (float)(v17[15] * this->anchor1.y)))));
      v59 = (float)(clipModel[10]
                  + (float)((float)(clipModel[19] * this->anchor2.z)
                          + (float)((float)(clipModel[13] * this->anchor2.x) + (float)(clipModel[16] * this->anchor2.y))))
          - (float)(v17[10]
                  + (float)((float)(v17[19] * this->anchor1.z)
                          + (float)((float)(v17[13] * this->anchor1.x) + (float)(v17[16] * this->anchor1.y))));
      ErrorReduction = idPhysics_AF::GetErrorReduction(this: phys);
      v30 = v67;
      v31 = this->c1.p;
      v32 = -(float)((float)ErrorReduction * v67);
      *v31 = (float)v27 * (float)v32;
      v31[1] = (float)v28 * (float)v32;
      v31[2] = v59 * (float)v32;
    }
    else
    {
      z = this->anchor2.z;
      x = this->anchor2.x;
      y = this->anchor2.y;
      v21 = this->shaft2.x;
      v23 = this->shaft2.y;
      v33 = (float *)this->body1->clipModel;
      v25 = this->shaft2.z;
      v22 = this->axis2.x;
      v24 = this->axis2.y;
      v26 = this->axis2.z;
      v34 = (float)(this->anchor2.x - (float)((float)v13 + v33[8]));
      v35 = (float)(this->anchor2.y
                  - (float)(v33[9]
                          + (float)((float)(v33[18] * this->anchor1.z)
                                  + (float)((float)(v33[12] * this->anchor1.x) + (float)(v33[15] * this->anchor1.y)))));
      v60 = this->anchor2.z
          - (float)(v33[10]
                  + (float)((float)(v33[19] * this->anchor1.z)
                          + (float)((float)(v33[13] * this->anchor1.x) + (float)(v33[16] * this->anchor1.y))));
      v36 = idPhysics_AF::GetErrorReduction(this: phys);
      v30 = v67;
      v37 = this->c1.p;
      v38 = -(float)((float)v36 * v67);
      *v37 = (float)v34 * (float)v38;
      v37[1] = (float)v35 * (float)v38;
      v37[2] = v60 * (float)v38;
    }
    v64.mat[0].x = v10;
    v64.mat[0].y = v11;
    v64.mat[0].z = v12;
    v64.mat[1].x = 0.0;
    v64.mat[1].y = 0.0;
    v64.mat[1].z = 0.0;
    v64.mat[2].x = 0.0;
    v64.mat[2].y = 0.0;
    v64.mat[2].z = 0.0;
    v65.mat[0].x = -0.0;
    v65.mat[0].y = --v15;
    v65.mat[0].z = -v14;
    v65.mat[1].x = -v15;
    v65.mat[1].y = -0.0;
    v65.mat[1].z = --v13;
    v65.mat[2].x = --v14;
    v65.mat[2].y = -v13;
    v65.mat[2].z = -0.0;
    idSpatialMat::Set(this: &this->J1, m1: &mat3_identity, m2: &v65, m3: &mat3_zero, m4: &v64);
    idSpatialMat::ChangeNumRows(this: &this->J1, rows: 4);
    if ( this->body2 != nullptr )
    {
      v65.mat[0].x = v21;
      v65.mat[0].y = v23;
      v65.mat[0].z = v25;
      v65.mat[1].x = 0.0;
      v65.mat[1].y = 0.0;
      v65.mat[1].z = 0.0;
      v65.mat[2].x = 0.0;
      v65.mat[2].y = 0.0;
      v65.mat[2].z = 0.0;
      v64.mat[0].x = 0.0;
      v64.mat[0].y = -z;
      v64.mat[0].z = y;
      v64.mat[1].x = z;
      v64.mat[1].y = 0.0;
      v64.mat[1].z = -x;
      v64.mat[2].x = -y;
      v64.mat[2].y = x;
      v64.mat[2].z = 0.0;
      v66[0].mat[0].x = -mat3_identity.mat[0].x;
      v66[0].mat[0].y = -mat3_identity.mat[0].y;
      v66[0].mat[0].z = -mat3_identity.mat[0].z;
      v66[0].mat[1].x = -mat3_identity.mat[1].x;
      v66[0].mat[1].y = -mat3_identity.mat[1].y;
      v66[0].mat[1].z = -mat3_identity.mat[1].z;
      v66[0].mat[2].x = -mat3_identity.mat[2].x;
      v66[0].mat[2].y = -mat3_identity.mat[2].y;
      v66[0].mat[2].z = -mat3_identity.mat[2].z;
      idSpatialMat::Set(this: &this->J2, m1: v66, m2: &v64, m3: &mat3_zero, m4: &v65);
      idSpatialMat::ChangeNumRows(this: &this->J2, rows: 4);
    }
    else
    {
      idSpatialMat::Zero(this: &this->J2, rows: 4, columns: 6);
    }
    v39 = (float)((float)((float)v23 * (float)v10) - (float)((float)v11 * (float)v21));
    v40 = (float)((float)((float)v25 * (float)v11) - (float)((float)v23 * (float)v12));
    v41 = (float)((float)((float)v12 * (float)v21) - (float)((float)v25 * (float)v10));
    _FP2 = (float)((float)((float)((float)v41 * (float)v41)
                         + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f13, f2, f3, f13 }
    v44 = __frsqrte(_FP13);
    v45 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44
                                                                                        * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)))
                                                                                                * (float)0.5))
                                                                                * (float)v44)
                                                                        - (float)1.5)
                                                        * (float)v44)
                                                * (float)((float)((float)((float)v41 * (float)v41)
                                                                + (float)((float)((float)v40 * (float)v40)
                                                                        + (float)((float)v39 * (float)v39)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v44
                                                                                * (float)((float)((float)((float)v41 * (float)v41)
                                                                                                + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)))
                                                                                        * (float)0.5))
                                                                        * (float)v44)
                                                                - (float)1.5)
                                                * (float)v44))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v44
                                                        * (float)((float)((float)((float)v41 * (float)v41)
                                                                        + (float)((float)((float)v40 * (float)v40)
                                                                                + (float)((float)v39 * (float)v39)))
                                                                * (float)0.5))
                                                * (float)v44)
                                        - (float)1.5)
                        * (float)v44));
    v46 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                                * (float)v44)
                                                                                        * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                        * (float)v44))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v44
                                                                                                * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5))
                                                                                        * (float)v44)
                                                                                - (float)1.5)
                                                                * (float)v44))
                                                * (float)((float)((float)((float)v41 * (float)v41)
                                                                + (float)((float)((float)v40 * (float)v40)
                                                                        + (float)((float)v39 * (float)v39)))
                                                        * (float)0.5))
                                        * (float)v45)
                                - (float)1.5)
                * (float)v45);
    v47 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5)) * (float)v44) - (float)1.5) * (float)v44)
                                                                                                * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                                * (float)v44))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5))
                                                                                                * (float)v44)
                                                                                        - (float)1.5)
                                                                        * (float)v44))
                                                        * (float)((float)((float)((float)v41 * (float)v41)
                                                                        + (float)((float)((float)v40 * (float)v40)
                                                                                + (float)((float)v39 * (float)v39)))
                                                                * (float)0.5))
                                                * (float)v45)
                                        - (float)1.5)
                        * (float)v45)
                * (float)((float)((float)v41 * (float)v41)
                        + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))));
    v48 = (float)((float)v40
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5)) * (float)v44) - (float)1.5) * (float)v44)
                                                                                                * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                                * (float)v44))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5))
                                                                                                * (float)v44)
                                                                                        - (float)1.5)
                                                                        * (float)v44))
                                                        * (float)((float)((float)((float)v41 * (float)v41)
                                                                        + (float)((float)((float)v40 * (float)v40)
                                                                                + (float)((float)v39 * (float)v39)))
                                                                * (float)0.5))
                                                * (float)v45)
                                        - (float)1.5)
                        * (float)v45));
    v49 = (float)((float)v41
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5)) * (float)v44) - (float)1.5) * (float)v44)
                                                                                                * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                                * (float)v44))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v41 * (float)v41) + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) * (float)0.5))
                                                                                                * (float)v44)
                                                                                        - (float)1.5)
                                                                        * (float)v44))
                                                        * (float)((float)((float)((float)v41 * (float)v41)
                                                                        + (float)((float)((float)v40 * (float)v40)
                                                                                + (float)((float)v39 * (float)v39)))
                                                                * (float)0.5))
                                                * (float)v45)
                                        - (float)1.5)
                        * (float)v45));
    if ( v47 != 0.0 )
    {
      v66[0].mat[0].x = v10;
      v66[0].mat[0].y = v11;
      v66[0].mat[0].z = v12;
      v66[0].mat[1].x = v48;
      v66[0].mat[1].y = v49;
      v66[0].mat[1].z = (float)((float)((float)v23 * (float)v10) - (float)((float)v11 * (float)v21)) * (float)v46;
      v65.mat[0].y = v48;
      v65.mat[1].y = v49;
      v65.mat[2].y = v66[0].mat[1].z;
      v65.mat[0].x = -v21;
      v65.mat[1].x = -v23;
      v65.mat[2].x = -v25;
      v66[0].mat[2].x = (float)((float)v49 * (float)v12) - (float)(v66[0].mat[1].z * (float)v11);
      v66[0].mat[2].y = (float)(v66[0].mat[1].z * (float)v10) - (float)((float)v12 * (float)v48);
      v66[0].mat[2].z = (float)((float)v11 * (float)v48) - (float)((float)v49 * (float)v10);
      v65.mat[2].z = (float)(v65.mat[1].x * (float)v48) - (float)((float)v49 * v65.mat[0].x);
      v65.mat[0].z = (float)(v65.mat[2].x * (float)v49) - (float)(v65.mat[1].x * v66[0].mat[1].z);
      v65.mat[1].z = (float)(v66[0].mat[1].z * v65.mat[0].x) - (float)(v65.mat[2].x * (float)v48);
      v50 = (float *)idMat3::operator*(this: &v64, result: &v65, a: v66);
      v51 = (float)((float)(v50[6] * (float)v26) + (float)(v50[3] * (float)v24));
      v52 = (float)((float)(v50[4] * (float)v24) + (float)((float)(v50[1] * (float)v22) + (float)(v50[7] * (float)v26)));
      v26 = (float)((float)(v50[5] * (float)v24) + (float)((float)(v50[2] * (float)v22) + (float)(v50[8] * (float)v26)));
      v22 = (float)((float)(*v50 * (float)v22) + (float)v51);
      v24 = v52;
    }
    v53 = this->c1.p;
    v53[3] = -(float)((float)(idPhysics_AF::GetUniversalErrorReduction(this: phys) * (float)v30)
                    * (float)((float)((float)v22 * v61) + (float)((float)((float)v26 * v63) + (float)((float)v24 * v62))));
    v54 = this->e.p;
    v54[3] = idPhysics_AF::GetUniversalTorsionLcpEpsilon(this: phys);
    ErrorReductionMax = idPhysics_AF::GetErrorReductionMax(this: phys);
    v56 = idPhysics_AF::GetErrorReductionMax(this: phys);
    idSpatialVec::Clamp(this: &this->c1, min: -v56, max: ErrorReductionMax);
    coneLimit = this->coneLimit;
    if ( coneLimit != nullptr )
    {
      idAFConstraint_ConeLimit::Add(this: coneLimit, phys: this->physics, invTimeStep: v30);
    }
    else
    {
      pyramidLimit = this->pyramidLimit;
      if ( pyramidLimit != nullptr )
        idAFConstraint_PyramidLimit::Add(this: pyramidLimit, phys: this->physics, invTimeStep: v30);
    }
  }
}


// ========================================================================
// ?SetAnchor@idAFConstraint_Hinge@@QAAXABVidVec3@@@Z
// EA  : 0x82722D80
// RVA : 0x00722D80
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Hinge::SetAnchor(idAFConstraint_Hinge *this, const idVec3 *worldPosition)
{
  idAFBody *body1; // r11
  float *clipModel; // r11
  double v4; // fp2
  double v5; // fp13
  double v6; // fp12
  double v7; // fp1
  double v8; // fp0
  idAFBody *body2; // r11
  float *v10; // r10
  double v11; // fp2
  double v12; // fp13
  double v13; // fp12
  double v14; // fp1
  double v15; // fp0
  idAFConstraint_ConeLimit *coneLimit; // r10

  body1 = this->body1;
  if ( body1 != nullptr )
  {
    clipModel = (float *)body1->clipModel;
    v4 = (float)(worldPosition->x - clipModel[8]);
    v5 = clipModel[17];
    v6 = clipModel[14];
    v7 = (float)((float)((float)(worldPosition->y - clipModel[9]) * clipModel[15])
               + (float)((float)(worldPosition->z - clipModel[10]) * clipModel[16]));
    v8 = (float)((float)((float)(worldPosition->y - clipModel[9]) * clipModel[18])
               + (float)((float)(worldPosition->z - clipModel[10]) * clipModel[19]));
    this->anchor1.x = (float)((float)(worldPosition->x - clipModel[8]) * clipModel[11])
                    + (float)((float)((float)(worldPosition->y - clipModel[9]) * clipModel[12])
                            + (float)((float)(worldPosition->z - clipModel[10]) * clipModel[13]));
    this->anchor1.y = (float)((float)v4 * (float)v6) + (float)v7;
    this->anchor1.z = (float)((float)v4 * (float)v5) + (float)v8;
    body2 = this->body2;
    if ( body2 != nullptr )
    {
      v10 = (float *)body2->clipModel;
      v11 = (float)(worldPosition->x - v10[8]);
      v12 = v10[17];
      v13 = v10[14];
      v14 = (float)((float)((float)(worldPosition->y - v10[9]) * v10[15])
                  + (float)((float)(worldPosition->z - v10[10]) * v10[16]));
      v15 = (float)((float)((float)(worldPosition->y - v10[9]) * v10[18])
                  + (float)((float)(worldPosition->z - v10[10]) * v10[19]));
      this->anchor2.x = (float)((float)(worldPosition->x - v10[8]) * v10[11])
                      + (float)((float)((float)(worldPosition->y - v10[9]) * v10[12])
                              + (float)((float)(worldPosition->z - v10[10]) * v10[13]));
      this->anchor2.y = (float)((float)v11 * (float)v13) + (float)v14;
      this->anchor2.z = (float)((float)v11 * (float)v12) + (float)v15;
    }
    else
    {
      this->anchor2 = *worldPosition;
    }
    coneLimit = this->coneLimit;
    if ( coneLimit != nullptr )
      coneLimit->coneAnchor = this->anchor2;
  }
}


// ========================================================================
// ?Evaluate@idAFConstraint_Hinge@@MAAXPBVidPhysics_AF@@M@Z
// EA  : 0x82722ED8
// RVA : 0x00722ED8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Hinge::Evaluate(
        idAFConstraint_Hinge *this,
        const idPhysics_AF *phys,
        double invTimeStep)
{
  double LcpEpsilon; // fp1
  float *p; // r11
  idAFBody *body2; // r29
  idPhysics_AF *physics; // r11
  double z; // fp0
  float *clipModel; // r30
  double v12; // fp11
  double v13; // fp8
  double v14; // fp17
  double v15; // fp16
  double v16; // fp15
  double v17; // fp31
  double v18; // fp27
  double v19; // fp23
  float *v20; // r11
  double v21; // fp28
  double x; // fp30
  double y; // fp29
  double v24; // fp21
  double v25; // fp20
  double v26; // fp19
  double v27; // fp24
  double v28; // fp26
  double v29; // fp25
  double ErrorReduction; // fp1
  float *v31; // r11
  double v32; // fp3
  double v33; // fp26
  double v34; // fp25
  double v35; // fp24
  double v36; // fp1
  float *v37; // r11
  double v38; // fp7
  double v39; // fp27
  double v40; // fp26
  double v41; // fp25
  double v42; // fp24
  double v43; // fp23
  double v44; // fp22
  double v45; // fp10
  float *v46; // r30
  float *v47; // r30
  double ErrorReductionMax; // fp31
  double v49; // fp1
  idAFConstraint_HingeSteering *steering; // r3
  idAFConstraint_ConeLimit *coneLimit; // r3
  idMat3 v52; // [sp+50h] [-180h] BYREF
  idMat3 v53; // [sp+80h] [-150h] BYREF
  float v54; // [sp+A8h] [-128h]
  float v55; // [sp+ACh] [-124h]
  float v56; // [sp+B0h] [-120h]
  idVec3 v57; // [sp+B8h] [-118h] BYREF
  idVec3 v58; // [sp+C8h] [-108h] BYREF
  idVec3 v59; // [sp+D8h] [-F8h] BYREF
  idMat3 v60; // [sp+F0h] [-E0h] BYREF

  if ( this->body1 != nullptr )
  {
    LcpEpsilon = idPhysics_AF::GetLcpEpsilon(this: phys);
    p = this->e.p;
    *p = LcpEpsilon;
    p[1] = LcpEpsilon;
    p[2] = LcpEpsilon;
    p[3] = LcpEpsilon;
    p[4] = LcpEpsilon;
    p[5] = LcpEpsilon;
    body2 = this->body2;
    if ( body2 == nullptr )
    {
      physics = this->physics;
      if ( physics != nullptr )
        body2 = physics->masterBody;
    }
    z = this->axis1.z;
    clipModel = (float *)this->body1->clipModel;
    v12 = clipModel[19];
    v13 = (float)((float)(clipModel[13] * this->axis1.x) + (float)(clipModel[16] * this->axis1.y));
    v14 = (float)((float)(this->axis1.x * clipModel[11])
                + (float)((float)(clipModel[14] * this->axis1.y) + (float)(clipModel[17] * this->axis1.z)));
    v15 = (float)((float)(clipModel[18] * this->axis1.z)
                + (float)((float)(clipModel[12] * this->axis1.x) + (float)(clipModel[15] * this->axis1.y)));
    v58.y = (float)(clipModel[18] * this->axis1.z)
          + (float)((float)(clipModel[12] * this->axis1.x) + (float)(clipModel[15] * this->axis1.y));
    v58.x = v14;
    v16 = (float)((float)((float)v12 * (float)z) + (float)v13);
    v58.z = (float)((float)v12 * (float)z) + (float)v13;
    v54 = v14;
    v55 = v15;
    v56 = v58.z;
    idVec3::OrthogonalBasis(this: &v58, left: &v59, up: &v57);
    v17 = (float)((float)(clipModel[11] * this->anchor1.x)
                + (float)((float)(clipModel[14] * this->anchor1.y) + (float)(clipModel[17] * this->anchor1.z)));
    v18 = (float)((float)(clipModel[18] * this->anchor1.z)
                + (float)((float)(clipModel[12] * this->anchor1.x) + (float)(clipModel[15] * this->anchor1.y)));
    v19 = (float)((float)(clipModel[19] * this->anchor1.z)
                + (float)((float)(clipModel[13] * this->anchor1.x) + (float)(clipModel[16] * this->anchor1.y)));
    if ( body2 != nullptr )
    {
      v20 = (float *)body2->clipModel;
      v21 = (float)((float)(v20[19] * this->anchor2.z)
                  + (float)((float)(v20[13] * this->anchor2.x) + (float)(v20[16] * this->anchor2.y)));
      x = (float)((float)(v20[11] * this->anchor2.x)
                + (float)((float)(v20[14] * this->anchor2.y) + (float)(v20[17] * this->anchor2.z)));
      y = (float)((float)(v20[18] * this->anchor2.z)
                + (float)((float)(v20[12] * this->anchor2.x) + (float)(v20[15] * this->anchor2.y)));
      v24 = (float)((float)(this->axis2.x * v20[11])
                  + (float)((float)(v20[17] * this->axis2.z) + (float)(v20[14] * this->axis2.y)));
      v25 = (float)((float)(v20[15] * this->axis2.y)
                  + (float)((float)(v20[18] * this->axis2.z) + (float)(v20[12] * this->axis2.x)));
      v26 = (float)((float)(v20[16] * this->axis2.y)
                  + (float)((float)(v20[19] * this->axis2.z) + (float)(v20[13] * this->axis2.x)));
      v27 = (float)((float)(v20[10]
                          + (float)((float)(v20[19] * this->anchor2.z)
                                  + (float)((float)(v20[13] * this->anchor2.x) + (float)(v20[16] * this->anchor2.y))))
                  - (float)(clipModel[10]
                          + (float)((float)(clipModel[19] * this->anchor1.z)
                                  + (float)((float)(clipModel[13] * this->anchor1.x)
                                          + (float)(clipModel[16] * this->anchor1.y)))));
      v28 = (float)((float)(v20[8]
                          + (float)((float)(v20[11] * this->anchor2.x)
                                  + (float)((float)(v20[14] * this->anchor2.y) + (float)(v20[17] * this->anchor2.z))))
                  - (float)(clipModel[8]
                          + (float)((float)(clipModel[11] * this->anchor1.x)
                                  + (float)((float)(clipModel[14] * this->anchor1.y)
                                          + (float)(clipModel[17] * this->anchor1.z)))));
      v29 = (float)((float)(v20[9]
                          + (float)((float)(v20[18] * this->anchor2.z)
                                  + (float)((float)(v20[12] * this->anchor2.x) + (float)(v20[15] * this->anchor2.y))))
                  - (float)(clipModel[9]
                          + (float)((float)(clipModel[18] * this->anchor1.z)
                                  + (float)((float)(clipModel[12] * this->anchor1.x)
                                          + (float)(clipModel[15] * this->anchor1.y)))));
      ErrorReduction = idPhysics_AF::GetErrorReduction(this: phys);
      v31 = this->c1.p;
      v32 = -(float)((float)ErrorReduction * (float)invTimeStep);
      *v31 = (float)v28 * (float)v32;
      v31[1] = (float)v29 * (float)v32;
      v31[2] = (float)v27 * (float)v32;
    }
    else
    {
      x = this->anchor2.x;
      y = this->anchor2.y;
      v21 = this->anchor2.z;
      v24 = this->axis2.x;
      v25 = this->axis2.y;
      v26 = this->axis2.z;
      v33 = (float)(this->anchor2.x
                  - (float)(clipModel[8]
                          + (float)((float)(clipModel[11] * this->anchor1.x)
                                  + (float)((float)(clipModel[14] * this->anchor1.y)
                                          + (float)(clipModel[17] * this->anchor1.z)))));
      v34 = (float)(this->anchor2.y
                  - (float)(clipModel[9]
                          + (float)((float)(clipModel[18] * this->anchor1.z)
                                  + (float)((float)(clipModel[12] * this->anchor1.x)
                                          + (float)(clipModel[15] * this->anchor1.y)))));
      v35 = (float)(this->anchor2.z
                  - (float)(clipModel[10]
                          + (float)((float)(clipModel[19] * this->anchor1.z)
                                  + (float)((float)(clipModel[13] * this->anchor1.x)
                                          + (float)(clipModel[16] * this->anchor1.y)))));
      v36 = idPhysics_AF::GetErrorReduction(this: phys);
      v37 = this->c1.p;
      v38 = -(float)((float)v36 * (float)invTimeStep);
      *v37 = (float)v33 * (float)v38;
      v37[1] = (float)v34 * (float)v38;
      v37[2] = (float)v35 * (float)v38;
    }
    v40 = v59.y;
    v41 = v59.z;
    v42 = v57.x;
    v44 = v57.z;
    v45 = --v18;
    v52.mat[0].x = v59.x;
    v52.mat[0].y = v59.y;
    v52.mat[0].z = v59.z;
    v52.mat[1].x = v57.x;
    v52.mat[1].y = v57.y;
    v52.mat[1].z = v57.z;
    v52.mat[2].x = 0.0;
    v52.mat[2].y = 0.0;
    v52.mat[2].z = 0.0;
    v53.mat[0].x = -0.0;
    v53.mat[0].y = --v19;
    v53.mat[0].z = -v18;
    v39 = v59.x;
    v53.mat[1].x = -v19;
    v43 = v57.y;
    v53.mat[1].y = -0.0;
    v53.mat[1].z = --v17;
    v53.mat[2].x = v45;
    v53.mat[2].y = -v17;
    v53.mat[2].z = -0.0;
    idSpatialMat::Set(this: &this->J1, m1: &mat3_identity, m2: &v53, m3: &mat3_zero, m4: &v52);
    idSpatialMat::ChangeNumRows(this: &this->J1, rows: 5);
    if ( this->body2 != nullptr )
    {
      v53.mat[1].z = -v44;
      v53.mat[1].y = -v43;
      v53.mat[1].x = -v42;
      v53.mat[0].z = -v41;
      v53.mat[2].x = 0.0;
      v53.mat[0].y = -v40;
      v53.mat[0].x = -v39;
      v53.mat[2].y = 0.0;
      v53.mat[2].z = 0.0;
      v52.mat[0].x = 0.0;
      v52.mat[0].y = -v21;
      v52.mat[0].z = y;
      v52.mat[1].x = v21;
      v52.mat[1].y = 0.0;
      v52.mat[1].z = -x;
      v52.mat[2].x = -y;
      v52.mat[2].y = x;
      v52.mat[2].z = 0.0;
      v60.mat[0].x = -mat3_identity.mat[0].x;
      v60.mat[0].y = -mat3_identity.mat[0].y;
      v60.mat[0].z = -mat3_identity.mat[0].z;
      v60.mat[1].x = -mat3_identity.mat[1].x;
      v60.mat[1].y = -mat3_identity.mat[1].y;
      v60.mat[1].z = -mat3_identity.mat[1].z;
      v60.mat[2].x = -mat3_identity.mat[2].x;
      v60.mat[2].y = -mat3_identity.mat[2].y;
      v60.mat[2].z = -mat3_identity.mat[2].z;
      idSpatialMat::Set(this: &this->J2, m1: &v60, m2: &v52, m3: &mat3_zero, m4: &v53);
      idSpatialMat::ChangeNumRows(this: &this->J2, rows: 5);
      v16 = v56;
      v15 = v55;
      v14 = v54;
    }
    else
    {
      idSpatialMat::Zero(this: &this->J2, rows: 5, columns: 6);
    }
    v46 = this->c1.p;
    v46[3] = -(float)((float)(idPhysics_AF::GetErrorReduction(this: phys) * (float)invTimeStep)
                    * (float)((float)((float)((float)((float)v26 * (float)v15) - (float)((float)v25 * (float)v16))
                                    * (float)v39)
                            + (float)((float)((float)v41
                                            * (float)((float)((float)v25 * (float)v14) - (float)((float)v15 * (float)v24)))
                                    + (float)((float)v40
                                            * (float)((float)((float)v16 * (float)v24) - (float)((float)v26 * (float)v14))))));
    v47 = this->c1.p;
    v47[4] = -(float)((float)(idPhysics_AF::GetErrorReduction(this: phys) * (float)invTimeStep)
                    * (float)((float)((float)v42
                                    * (float)((float)((float)v26 * (float)v15) - (float)((float)v25 * (float)v16)))
                            + (float)((float)((float)v44
                                            * (float)((float)((float)v25 * (float)v14) - (float)((float)v15 * (float)v24)))
                                    + (float)((float)v43
                                            * (float)((float)((float)v16 * (float)v24) - (float)((float)v26 * (float)v14))))));
    ErrorReductionMax = idPhysics_AF::GetErrorReductionMax(this: phys);
    v49 = idPhysics_AF::GetErrorReductionMax(this: phys);
    idSpatialVec::Clamp(this: &this->c1, min: -v49, max: ErrorReductionMax);
    steering = this->steering;
    if ( steering != nullptr )
    {
      idAFConstraint_HingeSteering::Add(this: steering, phys: this->physics, invTimeStep);
    }
    else
    {
      coneLimit = this->coneLimit;
      if ( coneLimit != nullptr )
        idAFConstraint_ConeLimit::Add(this: coneLimit, phys: this->physics, invTimeStep);
    }
  }
}


// ========================================================================
// ?Evaluate@idAFConstraint_Slider@@MAAXPBVidPhysics_AF@@M@Z
// EA  : 0x82723470
// RVA : 0x00723470
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Slider::Evaluate(
        idAFConstraint_Slider *this,
        const idPhysics_AF *phys,
        double invTimeStep)
{
  double LcpEpsilon; // fp1
  float *p; // r11
  idAFBody *body2; // r29
  idPhysics_AF *physics; // r11
  float *clipModel; // r11
  double z; // fp0
  const idMat3 *v12; // r30
  double v13; // fp11
  double v14; // fp8
  double v15; // fp6
  float *v16; // r9
  float *v17; // r10
  double v18; // fp0
  double v19; // fp12
  double v20; // fp3
  double v21; // fp11
  double v22; // fp8
  double v23; // fp7
  double v24; // fp31
  double v25; // fp30
  double v26; // fp29
  double v27; // fp28
  double v28; // fp27
  double v29; // fp6
  double v30; // fp9
  double v31; // fp5
  double v32; // fp4
  double v33; // fp10
  double v34; // fp25
  double v35; // fp24
  double v36; // fp23
  idMat3 *p_relAxis; // r5
  float *v38; // r11
  double v39; // fp9
  double v40; // fp8
  double v41; // fp7
  double v42; // fp6
  double v43; // fp5
  double v44; // fp4
  double v45; // fp3
  double v46; // fp2
  idRotation *v47; // r3
  const idRotation *v48; // r3
  double x; // fp31
  double y; // fp30
  double v51; // fp29
  double v52; // fp28
  double v53; // fp27
  double v54; // fp26
  double v55; // fp9
  double v56; // fp21
  double v57; // fp20
  double v58; // fp19
  double v59; // fp7
  float *v60; // r10
  float *v61; // r30
  float *v62; // r30
  double ErrorReductionMax; // fp31
  double v64; // fp1
  idMat3 v65; // [sp+50h] [-200h] BYREF
  idVec3 v66; // [sp+78h] [-1D8h] BYREF
  idVec3 v67; // [sp+88h] [-1C8h] BYREF
  idVec3 v68; // [sp+98h] [-1B8h] BYREF
  idMat3 v69; // [sp+B0h] [-1A0h] BYREF
  idRotation v70; // [sp+E0h] [-170h] BYREF
  idMat3 v71; // [sp+130h] [-120h] BYREF
  idMat3 v72[5]; // [sp+160h] [-F0h] BYREF

  if ( this->body1 != nullptr )
  {
    LcpEpsilon = idPhysics_AF::GetLcpEpsilon(this: phys);
    p = this->e.p;
    *p = LcpEpsilon;
    p[1] = LcpEpsilon;
    p[2] = LcpEpsilon;
    p[3] = LcpEpsilon;
    p[4] = LcpEpsilon;
    p[5] = LcpEpsilon;
    body2 = this->body2;
    if ( body2 != nullptr || (physics = this->physics) != nullptr && (body2 = physics->masterBody) != nullptr )
    {
      clipModel = (float *)body2->clipModel;
      z = this->axis.z;
      v12 = (const idMat3 *)(clipModel + 11);
      v13 = clipModel[19];
      v14 = (float)((float)(clipModel[13] * this->axis.x) + (float)(clipModel[16] * this->axis.y));
      v15 = (float)((float)(clipModel[18] * this->axis.z)
                  + (float)((float)(clipModel[12] * this->axis.x) + (float)(clipModel[15] * this->axis.y)));
      v68.x = (float)(this->axis.x * clipModel[11])
            + (float)((float)(clipModel[14] * this->axis.y) + (float)(clipModel[17] * this->axis.z));
      v68.y = v15;
      v68.z = (float)((float)v13 * (float)z) + (float)v14;
      idVec3::OrthogonalBasis(this: &v68, left: &v66, up: &v67);
      v16 = (float *)body2->clipModel;
      v17 = (float *)this->body1->clipModel;
      v18 = v16[8];
      v19 = v16[9];
      v20 = v16[10];
      v21 = v17[8];
      v22 = v17[9];
      v23 = v17[10];
      v24 = v17[19];
      v25 = v17[16];
      v26 = v17[13];
      v27 = v17[18];
      v28 = v17[15];
      v29 = (float)((float)(this->offset.x * v16[11])
                  + (float)((float)(v16[14] * this->offset.y) + (float)(v16[17] * this->offset.z)));
      v30 = v17[11];
      v31 = (float)((float)(v16[18] * this->offset.z)
                  + (float)((float)(v16[12] * this->offset.x) + (float)(v16[15] * this->offset.y)));
      v32 = (float)((float)(v16[19] * this->offset.z)
                  + (float)((float)(v16[13] * this->offset.x) + (float)(v16[16] * this->offset.y)));
      v65.mat[1].x = v17[12];
      v33 = v17[14];
      v34 = (float)((float)((float)v18 + (float)v29) - (float)v21);
      v65.mat[0].z = v17[17];
      v35 = (float)((float)((float)v19 + (float)v31) - (float)v22);
      v36 = (float)((float)((float)v20 + (float)v32) - (float)v23);
      v65.mat[0].y = v33;
      v65.mat[0].x = v30;
      v65.mat[1].y = v28;
      v65.mat[1].z = v27;
      v65.mat[2].x = v26;
      v65.mat[2].y = v25;
      v65.mat[2].z = v24;
      p_relAxis = idMat3::operator*(this: &v69, result: &this->relAxis, a: v12);
    }
    else
    {
      idVec3::OrthogonalBasis(this: &this->axis, left: &v66, up: &v67);
      p_relAxis = &this->relAxis;
      v38 = (float *)this->body1->clipModel;
      v34 = (float)(this->offset.x - v38[8]);
      v35 = (float)(this->offset.y - v38[9]);
      v36 = (float)(this->offset.z - v38[10]);
      v39 = v38[16];
      v40 = v38[13];
      v41 = v38[18];
      v42 = v38[15];
      v43 = v38[12];
      v44 = v38[17];
      v45 = v38[14];
      v46 = v38[11];
      v65.mat[2].z = v38[19];
      v65.mat[2].y = v39;
      v65.mat[2].x = v40;
      v65.mat[1].z = v41;
      v65.mat[1].y = v42;
      v65.mat[1].x = v43;
      v65.mat[0].z = v44;
      v65.mat[0].y = v45;
      v65.mat[0].x = v46;
    }
    v47 = (idRotation *)idMat3::operator*(this: &v71, result: &v65, a: p_relAxis);
    v48 = idMat3::ToRotation(this: v72, result: v47);
    idRotation::operator=(this: &v70, __that: v48);
    x = v66.x;
    y = v66.y;
    v51 = v66.z;
    v52 = v67.x;
    v53 = v67.y;
    v54 = v67.z;
    v65.mat[0].x = v66.x;
    v65.mat[0].y = v66.y;
    v65.mat[0].z = v66.z;
    v65.mat[1].x = v67.x;
    v65.mat[1].y = v67.y;
    v65.mat[1].z = v67.z;
    v65.mat[2].x = vec3_origin.x;
    v65.mat[2].y = vec3_origin.y;
    v65.mat[2].z = vec3_origin.z;
    idSpatialMat::Set(this: &this->J1, m1: &mat3_zero, m2: &mat3_identity, m3: &v65, m4: &mat3_zero);
    idSpatialMat::ChangeNumRows(this: &this->J1, rows: 5);
    if ( this->body2 != nullptr )
    {
      v69.mat[2].x = vec3_origin.x;
      v69.mat[2].y = vec3_origin.y;
      v69.mat[2].z = vec3_origin.z;
      v65.mat[0].x = -mat3_identity.mat[0].x;
      v65.mat[0].y = -mat3_identity.mat[0].y;
      v65.mat[0].z = -mat3_identity.mat[0].z;
      v65.mat[1].x = -mat3_identity.mat[1].x;
      v65.mat[1].y = -mat3_identity.mat[1].y;
      v65.mat[1].z = -mat3_identity.mat[1].z;
      v65.mat[2].x = -mat3_identity.mat[2].x;
      v65.mat[2].y = -mat3_identity.mat[2].y;
      v65.mat[2].z = -mat3_identity.mat[2].z;
      v69.mat[1].x = -v52;
      v69.mat[1].y = -v53;
      v69.mat[1].z = -v54;
      v69.mat[0].x = -x;
      v69.mat[0].y = -y;
      v69.mat[0].z = -v51;
      idSpatialMat::Set(this: &this->J2, m1: &mat3_zero, m2: &v65, m3: &v69, m4: &mat3_zero);
      idSpatialMat::ChangeNumRows(this: &this->J2, rows: 5);
    }
    else
    {
      idSpatialMat::Zero(this: &this->J2, rows: 5, columns: 6);
    }
    v55 = (float)(v70.angle * idMath::M_DEG2RAD);
    v56 = (float)(v70.vec.x * (float)-v55);
    v57 = (float)(v70.vec.y * (float)-v55);
    v58 = (float)(v70.vec.z * (float)-v55);
    v59 = (float)(idPhysics_AF::GetErrorReduction(this: phys) * (float)invTimeStep);
    v60 = this->c1.p;
    v60[2] = (float)v58 * (float)-v59;
    *v60 = (float)v56 * (float)-v59;
    v60[1] = (float)v57 * (float)-v59;
    v61 = this->c1.p;
    v61[3] = -(float)((float)(idPhysics_AF::GetErrorReduction(this: phys) * (float)invTimeStep)
                    * (float)((float)((float)y * (float)v35)
                            + (float)((float)((float)x * (float)v34) + (float)((float)v51 * (float)v36))));
    v62 = this->c1.p;
    v62[4] = -(float)((float)(idPhysics_AF::GetErrorReduction(this: phys) * (float)invTimeStep)
                    * (float)((float)((float)v53 * (float)v35)
                            + (float)((float)((float)v52 * (float)v34) + (float)((float)v54 * (float)v36))));
    ErrorReductionMax = idPhysics_AF::GetErrorReductionMax(this: phys);
    v64 = idPhysics_AF::GetErrorReductionMax(this: phys);
    idSpatialVec::Clamp(this: &this->c1, min: -v64, max: ErrorReductionMax);
  }
}


// ========================================================================
// ?Setup@idAFConstraint_Contact@@QAAXPAVidAFBody@@0AAUcontactInfo_t@@MM@Z
// EA  : 0x827239C0
// RVA : 0x007239C0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Contact::Setup(
        idAFConstraint_Contact *this,
        idAFBody *b1,
        idAFBody *b2,
        contactInfo_t *c,
        double separation,
        double invTimeStep)
{
  idAFBody *body1; // r10
  float *clipModel; // r11
  double v12; // fp25
  double v13; // fp30
  double v14; // fp26
  idVec3 *p_normal; // r30
  float *mat; // r11
  double z; // fp4
  double x; // fp5
  double v19; // fp2
  double v20; // fp1
  double v21; // fp31
  idAFBody *v22; // r7
  float *v23; // r6
  idAFBody *body2; // r11
  double v25; // fp30
  float *v26; // r11
  double v27; // fp31
  double v28; // fp26
  double v29; // fp25
  float *v30; // r11
  double v31; // fp4
  double v32; // fp3
  double v33; // fp1
  float *v34; // r11
  double v35; // fp11
  double v36; // fp10
  idAFBody *v37; // r10
  float *v38; // r9
  idPhysics *PhysicsForId; // r3
  idPhysics_AF *physics; // r3
  double v41; // fp31
  double ContactErrorReduction; // fp1
  float *p; // r30
  double v44; // fp31
  double ContactErrorReductionMax; // fp30
  double v46; // fp0
  float *v47; // r30
  char v48; // [sp+50h] [-A0h] BYREF
  float v49; // [sp+84h] [-6Ch]
  float v50; // [sp+88h] [-68h]
  float v51; // [sp+8Ch] [-64h]

  this->body1 = b1;
  this->body2 = b2;
  contactInfo_t::operator=(this: &this->contact, __that: c);
  body1 = this->body1;
  this->separation = separation;
  clipModel = (float *)body1->clipModel;
  v12 = (float)(c->point.x - clipModel[8]);
  v13 = (float)(c->point.z - clipModel[10]);
  v14 = (float)(c->point.y - clipModel[9]);
  idSpatialMat::SetSize(this: &this->J1, rows: 1, columns: 6);
  p_normal = &c->normal;
  *(idVec3 *)this->J1.mat = c->normal;
  mat = this->J1.mat;
  z = c->normal.z;
  x = c->normal.x;
  v19 = (float)((float)v13 * c->normal.y);
  v20 = (float)(c->normal.z * (float)v12);
  mat[5] = (float)(c->normal.y * (float)v12) - (float)((float)v14 * c->normal.x);
  v21 = 0.0;
  mat[3] = (float)((float)v14 * (float)z) - (float)v19;
  mat[4] = (float)((float)v13 * (float)x) - (float)v20;
  v22 = this->body1;
  v23 = this->J1.mat;
  body2 = this->body2;
  v25 = (float)((float)(v23[3] * v22->current.spatialVelocity.p[3])
              + (float)((float)(v22->current.spatialVelocity.p[0] * *v23)
                      + (float)((float)(v22->current.spatialVelocity.p[1] * v23[1])
                              + (float)((float)(v22->current.spatialVelocity.p[2] * v23[2])
                                      + (float)((float)(v22->current.spatialVelocity.p[5] * v23[5])
                                              + (float)(v22->current.spatialVelocity.p[4] * v23[4]))))));
  if ( body2 != nullptr )
  {
    v26 = (float *)body2->clipModel;
    v27 = (float)(c->point.x - v26[8]);
    v28 = (float)(c->point.y - v26[9]);
    v29 = (float)(c->point.z - v26[10]);
    idSpatialMat::SetSize(this: &this->J2, rows: 1, columns: 6);
    v30 = this->J2.mat;
    v31 = -c->normal.z;
    v32 = -p_normal->x;
    v30[1] = -c->normal.y;
    v30[2] = v31;
    *v30 = v32;
    v33 = -c->normal.y;
    v34 = this->J2.mat;
    v35 = -c->normal.z;
    v36 = -p_normal->x;
    v34[4] = (float)((float)v29 * (float)v36) - (float)((float)v35 * (float)v27);
    v34[3] = (float)((float)v35 * (float)v28) - (float)((float)v33 * (float)v29);
    v34[5] = (float)((float)v33 * (float)v27) - (float)((float)v28 * (float)v36);
    v37 = this->body2;
    v38 = this->J2.mat;
    v21 = (float)((float)(*v38 * v37->current.spatialVelocity.p[0])
                + (float)((float)(v38[3] * v37->current.spatialVelocity.p[3])
                        + (float)((float)(v37->current.spatialVelocity.p[1] * v38[1])
                                + (float)((float)(v37->current.spatialVelocity.p[2] * v38[2])
                                        + (float)((float)(v37->current.spatialVelocity.p[5] * v38[5])
                                                + (float)(v37->current.spatialVelocity.p[4] * v38[4]))))));
  }
  else
  {
    PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: c->physicsId);
    if ( PhysicsForId != nullptr )
    {
      PhysicsForId->GetImpactInfo(this: PhysicsForId, a2: c->bodyId, a3: &c->point, a4: (impactInfo_t *)&v48);
      v21 = (float)-(float)((float)(c->normal.z * v51) + (float)((float)(v49 * c->normal.x) + (float)(v50 * c->normal.y)));
    }
  }
  *this->c1.p = v21;
  *this->c2.p = v25;
  if ( (c->flags & 8) == 0 && -(float)((float)v21 + (float)v25) > 2.0 && this->body1->bouncyness > 0.0 )
  {
    *this->c1.p = (float)(this->body1->bouncyness * (float)((float)v21 + (float)v25)) + *this->c1.p;
    *this->c2.p = -(float)((float)(this->body1->bouncyness * (float)((float)v21 + (float)v25)) - *this->c2.p);
  }
  physics = this->physics;
  if ( physics != nullptr )
  {
    v41 = (float)((float)separation - c->separation);
    if ( v41 > 0.0 )
    {
      ContactErrorReduction = idPhysics_AF::GetContactErrorReduction(this: physics);
      p = this->c1.p;
      v44 = -(float)((float)((float)ContactErrorReduction * (float)invTimeStep) * (float)v41);
      ContactErrorReductionMax = idPhysics_AF::GetContactErrorReductionMax(this: this->physics);
      v46 = -idPhysics_AF::GetContactErrorReductionMax(this: this->physics);
      if ( v44 >= v46 )
      {
        if ( v44 <= ContactErrorReductionMax )
          v46 = v44;
        else
          v46 = ContactErrorReductionMax;
      }
      *p = *p + (float)v46;
    }
    v47 = this->e.p;
    *v47 = idPhysics_AF::GetContactLcpEpsilon(this: this->physics);
    *this->lo.p = 0.0;
    *this->hi.p = 1.0e30;
    this->boxConstraint = nullptr;
    this->boxScale[0] = 0.0;
    this->boxIndex[0] = -1;
  }
}


// ========================================================================
// ?DebugDraw@idAFConstraint_ConeLimit@@UAAXXZ
// EA  : 0x82723D78
// RVA : 0x00723D78
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_ConeLimit::DebugDraw(idAFConstraint_ConeLimit *this)
{
  idAFBody *body2; // r11
  idPhysics_AF *physics; // r11
  float *clipModel; // r11
  double x; // fp27
  double v6; // fp25
  double v7; // fp24
  double v8; // fp4
  double v9; // fp13
  double z; // fp28
  double v11; // fp29
  double v12; // fp12
  double v13; // fp30
  double y; // fp13
  float *p; // r10
  idRenderWorld *v16; // r3
  float *v17; // r11
  double v18; // fp12
  double v19; // fp4
  long double v20; // fp2
  double v21; // fp30
  double v22; // fp29
  double v23; // fp25
  double v24; // fp28
  double v25; // fp27
  double v26; // fp26
  double v27; // fp0
  double v28; // fp24
  double v29; // fp23
  double v30; // fp22
  double v31; // fp31
  long double v32; // fp2
  double v33; // fp19
  double v34; // fp18
  double v35; // fp17
  long double v36; // fp2
  idRenderWorld *v37; // r3
  idRenderWorld *v38; // r3
  idRenderWorld *v39; // r3
  idVec3 v40; // [sp+58h] [-678h] BYREF
  idVec3 v41; // [sp+68h] [-668h] BYREF
  idVec3 v42; // [sp+78h] [-658h] BYREF
  idVec3 v43; // [sp+88h] [-648h] BYREF
  float v44[4]; // [sp+98h] [-638h] BYREF
  idVec3 v45; // [sp+A8h] [-628h] BYREF
  idVec3 v46; // [sp+B8h] [-618h] BYREF
  float v47[4]; // [sp+D0h] [-600h] BYREF
  idColor v48; // [sp+E0h] [-5F0h] BYREF
  idWinding v49; // [sp+F0h] [-5E0h] BYREF
  int v50; // [sp+100h] [-5D0h] BYREF

  if ( this->body1 != nullptr )
  {
    body2 = this->body2;
    if ( body2 != nullptr || (physics = this->physics) != nullptr && (body2 = physics->masterBody) != nullptr )
    {
      clipModel = (float *)body2->clipModel;
      x = this->coneAxis.x;
      v6 = clipModel[9];
      v7 = clipModel[11];
      v8 = (float)((float)(clipModel[18] * this->coneAnchor.z)
                 + (float)((float)(clipModel[12] * this->coneAnchor.x) + (float)(clipModel[15] * this->coneAnchor.y)));
      v9 = (float)((float)(clipModel[14] * this->coneAxis.y) + (float)(clipModel[17] * this->coneAxis.z));
      z = (float)((float)(clipModel[19] * this->coneAxis.z)
                + (float)((float)(clipModel[13] * this->coneAxis.x) + (float)(clipModel[16] * this->coneAxis.y)));
      v11 = (float)((float)(clipModel[18] * this->coneAxis.z)
                  + (float)((float)(clipModel[12] * this->coneAxis.x) + (float)(clipModel[15] * this->coneAxis.y)));
      v12 = (float)(clipModel[10]
                  + (float)((float)(clipModel[19] * this->coneAnchor.z)
                          + (float)((float)(clipModel[13] * this->coneAnchor.x)
                                  + (float)(clipModel[16] * this->coneAnchor.y))));
      v40.x = clipModel[8]
            + (float)((float)(clipModel[11] * this->coneAnchor.x)
                    + (float)((float)(clipModel[14] * this->coneAnchor.y) + (float)(clipModel[17] * this->coneAnchor.z)));
      v40.y = (float)v6 + (float)v8;
      v13 = (float)((float)((float)x * (float)v7) + (float)v9);
    }
    else
    {
      y = this->coneAnchor.y;
      v13 = this->coneAxis.x;
      v11 = this->coneAxis.y;
      z = this->coneAxis.z;
      v12 = this->coneAnchor.z;
      v40.x = this->coneAnchor.x;
      v40.y = y;
    }
    p = this->lm.p;
    v40.z = v12;
    v43.z = z;
    v43.y = v11;
    v43.x = v13;
    v48 = idColor::colorGreen;
    if ( *p != 0.0 )
      v48 = idColor::colorOrange;
    v16 = common->RW(this: common);
    v17 = (float *)this->body1->clipModel;
    v18 = (float)((float)(this->body1Axis.x * v17[11])
                + (float)((float)(v17[14] * this->body1Axis.y) + (float)(v17[17] * this->body1Axis.z)));
    v19 = (float)((float)((float)(v17[18] * this->body1Axis.z)
                        + (float)((float)(v17[12] * this->body1Axis.x) + (float)(v17[15] * this->body1Axis.y)))
                * (float)10.0);
    v44[2] = v40.z
           + (float)((float)((float)(v17[19] * this->body1Axis.z)
                           + (float)((float)(v17[13] * this->body1Axis.x) + (float)(v17[16] * this->body1Axis.y)))
                   * (float)10.0);
    v44[0] = (float)((float)v18 * (float)10.0) + v40.x;
    v44[1] = v40.y + (float)v19;
    v16->DebugLine(this: v16, a2: (const idVec4 *)&v48, a3: &v40, a4: (const idVec3 *)v44, a5: 0, a6: false);
    idVec3::NormalVectors(this: &v43, left: &v45, down: &v46);
    *((double *)&v20 + 1) = (float)((float)((float)v13 * (float)10.0) * this->cosAngle);
    *(double *)&v20 = __fsqrts((float)-(float)((float)(this->cosAngle * this->cosAngle) - (float)1.0));
    v21 = (float)(v40.y + (float)((float)((float)v11 * (float)10.0) * this->cosAngle));
    v22 = (float)(v40.z + (float)((float)((float)z * (float)10.0) * this->cosAngle));
    v23 = (float)((float)*((double *)&v20 + 1) + v40.x);
    v24 = (float)(v45.y * (float)((float)*(double *)&v20 * (float)10.0));
    v25 = (float)((float)((float)*(double *)&v20 * (float)10.0) * v45.x);
    v26 = (float)(v45.z * (float)((float)*(double *)&v20 * (float)10.0));
    v47[0] = 1.0;
    v47[2] = 1.0;
    v27 = 0.0;
    v47[1] = 0.0;
    v28 = (float)(v46.x * (float)((float)*(double *)&v20 * (float)10.0));
    v29 = (float)(v46.y * (float)((float)*(double *)&v20 * (float)10.0));
    v47[3] = 0.40000001;
    v30 = (float)(v46.z * (float)((float)*(double *)&v20 * (float)10.0));
    v41.y = (float)(v45.y * (float)((float)*(double *)&v20 * (float)10.0)) + (float)v21;
    v41.z = (float)(v45.z * (float)((float)*(double *)&v20 * (float)10.0)) + (float)v22;
    v41.x = (float)((float)*((double *)&v20 + 1) + v40.x)
          + (float)((float)((float)*(double *)&v20 * (float)10.0) * v45.x);
    do
    {
      v31 = (float)((float)v27 + (float)45.0);
      *(double *)&v20 = (float)((float)((float)v27 + (float)45.0) * idMath::M_DEG2RAD);
      v32 = sin(x: v20);
      v33 = (float)((float)v30 * (float)*(double *)&v32);
      v34 = (float)((float)v29 * (float)*(double *)&v32);
      v35 = (float)((float)*(double *)&v32 * (float)v28);
      *(double *)&v32 = (float)((float)v31 * idMath::M_DEG2RAD);
      v36 = cos(x: v32);
      v49.__vftable = (idWinding_vtbl *)&idFixedWinding::`vftable';
      v49.numPoints = 0;
      v49.p = (idVec5 *)&v50;
      v49.allocedSize = 64;
      v42.x = (float)((float)((float)*(double *)&v36 * (float)v25) + (float)v35) + (float)v23;
      v42.z = (float)((float)((float)v26 * (float)*(double *)&v36) + (float)v33) + (float)v22;
      v42.y = (float)((float)((float)v24 * (float)*(double *)&v36) + (float)v34) + (float)v21;
      idWinding::AddPoint(this: &v49, v: &v42);
      idWinding::AddPoint(this: &v49, v: &v41);
      idWinding::AddPoint(this: &v49, v: &v40);
      v37 = common->RW(this: common);
      v37->DebugFilledPolygon(this: v37, a2: (const idVec4 *)v47, a3: &v49, a4: 0, a5: false);
      v38 = common->RW(this: common);
      v38->DebugLine(this: v38, a2: (const idVec4 *)&idColor::colorMagenta, a3: &v40, a4: &v41, a5: 0, a6: false);
      v39 = common->RW(this: common);
      v39->DebugLine(this: v39, a2: (const idVec4 *)&idColor::colorMagenta, a3: &v41, a4: &v42, a5: 0, a6: false);
      v41.x = v42.x;
      v41.y = v42.y;
      v41.z = v42.z;
      v49.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
      v49.p = nullptr;
      idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
      v27 = v31;
      v49.p = nullptr;
    }
    while ( v31 < 360.0 );
  }
}


// ========================================================================
// __unwind$267714
// EA  : 0x827242B0
// RVA : 0x007242B0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_267714()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 1744 + 240));
}


// ========================================================================
// ?DebugDraw@idAFConstraint_PyramidLimit@@UAAXXZ
// EA  : 0x827242E0
// RVA : 0x007242E0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_PyramidLimit::DebugDraw(idAFConstraint_PyramidLimit *this)
{
  idAFBody *body2; // r11
  idPhysics_AF *physics; // r11
  float *clipModel; // r11
  double y; // fp13
  double z; // fp12
  double v7; // fp11
  double x; // fp10
  double v9; // fp27
  double v10; // fp28
  double v11; // fp3
  double v12; // fp29
  double v13; // fp9
  double v14; // fp31
  double v15; // fp1
  double v16; // fp2
  double v17; // fp30
  double v18; // fp7
  double v19; // fp0
  double v20; // fp8
  double v21; // fp6
  double v22; // fp4
  double v23; // fp1
  double v24; // fp2
  double v25; // fp29
  double v26; // fp3
  double v27; // fp30
  double v28; // fp13
  double v29; // fp26
  double v30; // fp3
  double v31; // fp29
  double v32; // fp31
  double v33; // fp8
  double v34; // fp10
  double v35; // fp28
  double v36; // fp29
  double v37; // fp13
  double v38; // fp30
  double v39; // fp4
  double v40; // fp31
  double v41; // fp9
  double v42; // fp8
  double v43; // fp7
  double v44; // fp13
  double v45; // fp12
  double v46; // fp11
  double v47; // fp10
  double v48; // fp9
  double v49; // fp8
  double v50; // fp7
  double v51; // fp6
  float *p; // r10
  idRenderWorld *v53; // r3
  float *v54; // r11
  double v55; // fp12
  double v56; // fp4
  float *v57; // r28
  signed int v58; // r29
  float *v59; // r30
  double v60; // fp0
  BOOL v61; // r11
  double v62; // fp8
  double v63; // fp7
  float *v64; // r3
  double v65; // fp5
  double v66; // fp4
  double v67; // fp2
  double v68; // fp1
  double v69; // fp0
  double v70; // fp13
  double v71; // fp12
  double v72; // fp28
  double v73; // fp29
  double v74; // fp30
  double v75; // fp3
  double v76; // fp26
  double v77; // fp1
  double v78; // fp24
  double v79; // fp29
  double v80; // fp2
  double v81; // fp31
  double v82; // fp3
  double v83; // fp28
  double v84; // fp24
  double v85; // fp18
  double v86; // fp22
  int v87; // r11
  const idVec3 *p_y; // r29
  int v89; // r30
  const idVec3 *v90; // r28
  idRenderWorld *v91; // r3
  idRenderWorld *v92; // r3
  idRenderWorld *v93; // r3
  idVec3 v94[2]; // [sp+58h] [-728h] BYREF
  float v95; // [sp+70h] [-710h] BYREF
  float v96; // [sp+74h] [-70Ch] BYREF
  float v97; // [sp+78h] [-708h] BYREF
  float v98; // [sp+7Ch] [-704h]
  float v99; // [sp+80h] [-700h]
  float v100; // [sp+84h] [-6FCh]
  float v101; // [sp+88h] [-6F8h]
  float v102; // [sp+8Ch] [-6F4h]
  float v103; // [sp+90h] [-6F0h]
  float v104[4]; // [sp+A0h] [-6E0h] BYREF
  float v105[4]; // [sp+B0h] [-6D0h] BYREF
  idMat3 v106; // [sp+C0h] [-6C0h] BYREF
  float v107; // [sp+E4h] [-69Ch]
  float v108; // [sp+E8h] [-698h]
  float v109; // [sp+ECh] [-694h]
  float v110; // [sp+F0h] [-690h]
  float v111; // [sp+F4h] [-68Ch]
  float v112; // [sp+F8h] [-688h]
  float v113; // [sp+FCh] [-684h] BYREF
  float v114; // [sp+100h] [-680h]
  float v115; // [sp+104h] [-67Ch]
  float v116; // [sp+108h] [-678h]
  float v117; // [sp+10Ch] [-674h]
  float v118; // [sp+110h] [-670h]
  float v119; // [sp+114h] [-66Ch]
  float v120; // [sp+118h] [-668h]
  float v121; // [sp+11Ch] [-664h]
  float v122; // [sp+120h] [-660h]
  float v123; // [sp+124h] [-65Ch]
  float v124; // [sp+128h] [-658h]
  float v125; // [sp+12Ch] [-654h]
  float v126; // [sp+130h] [-650h]
  float v127; // [sp+134h] [-64Ch]
  float v128; // [sp+138h] [-648h]
  float v129; // [sp+13Ch] [-644h]
  float v130; // [sp+140h] [-640h]
  float v131; // [sp+144h] [-63Ch]
  idColor v132; // [sp+150h] [-630h] BYREF
  idQuat v133; // [sp+160h] [-620h] BYREF
  idWinding v134; // [sp+190h] [-5F0h] BYREF
  int v135; // [sp+1A0h] [-5E0h] BYREF

  if ( this->body1 != nullptr )
  {
    body2 = this->body2;
    if ( body2 != nullptr || (physics = this->physics) != nullptr && (body2 = physics->masterBody) != nullptr )
    {
      clipModel = (float *)body2->clipModel;
      y = this->pyramidBasis.mat[1].y;
      z = this->pyramidBasis.mat[0].z;
      v7 = this->pyramidBasis.mat[2].y;
      x = this->pyramidBasis.mat[0].x;
      v9 = this->pyramidBasis.mat[2].x;
      v10 = clipModel[18];
      v11 = (float)(clipModel[16] * this->pyramidBasis.mat[1].y);
      v12 = clipModel[12];
      v13 = this->pyramidBasis.mat[1].x;
      v15 = (float)((float)(clipModel[12] * this->pyramidBasis.mat[1].x)
                  + (float)(clipModel[15] * this->pyramidBasis.mat[1].y));
      v14 = this->pyramidBasis.mat[1].z;
      v16 = (float)(clipModel[15] * this->pyramidBasis.mat[2].y);
      v17 = clipModel[13];
      v18 = (float)((float)(clipModel[13] * this->pyramidBasis.mat[0].x)
                  + (float)(clipModel[16] * this->pyramidBasis.mat[0].y));
      v19 = (float)((float)(clipModel[14] * this->pyramidBasis.mat[0].y)
                  + (float)(clipModel[17] * this->pyramidBasis.mat[0].z));
      v20 = (float)(clipModel[17] * this->pyramidBasis.mat[1].z);
      v21 = (float)((float)(clipModel[13] * this->pyramidBasis.mat[2].x)
                  + (float)(clipModel[16] * this->pyramidBasis.mat[2].y));
      v96 = (float)(clipModel[18] * this->pyramidBasis.mat[0].z)
          + (float)((float)(clipModel[12] * this->pyramidBasis.mat[0].x)
                  + (float)(clipModel[15] * this->pyramidBasis.mat[0].y));
      v22 = clipModel[17];
      v99 = (float)((float)v10 * (float)v14) + (float)v15;
      v23 = clipModel[15];
      v24 = (float)((float)((float)v12 * (float)v9) + (float)v16);
      v25 = clipModel[19];
      v26 = (float)((float)((float)v17 * (float)v13) + (float)v11);
      v27 = this->pyramidBasis.mat[2].z;
      v97 = (float)(clipModel[19] * (float)z) + (float)v18;
      v28 = (float)((float)(clipModel[14] * (float)y) + (float)v20);
      v29 = clipModel[14];
      v30 = (float)((float)((float)v25 * (float)v14) + (float)v26);
      v31 = clipModel[11];
      v32 = v10;
      v33 = v31;
      v34 = (float)((float)((float)x * clipModel[11]) + (float)v19);
      v100 = v30;
      v35 = (float)((float)(clipModel[19] * (float)v27) + (float)v21);
      v95 = v34;
      v37 = (float)((float)((float)v31 * (float)v13) + (float)v28);
      v36 = (float)((float)((float)v32 * (float)v27) + (float)v24);
      v38 = (float)((float)((float)v9 * (float)v33)
                  + (float)((float)((float)v29 * (float)v7) + (float)((float)v22 * (float)v27)));
      v39 = clipModel[10];
      v41 = (float)((float)(this->pyramidAnchor.x * (float)v33)
                  + (float)((float)((float)v29 * this->pyramidAnchor.y) + (float)(clipModel[17] * this->pyramidAnchor.z)));
      v42 = (float)((float)(clipModel[19] * this->pyramidAnchor.z)
                  + (float)((float)(clipModel[13] * this->pyramidAnchor.x)
                          + (float)(clipModel[16] * this->pyramidAnchor.y)));
      v43 = (float)((float)((float)v32 * this->pyramidAnchor.z)
                  + (float)((float)(clipModel[12] * this->pyramidAnchor.x) + (float)((float)v23 * this->pyramidAnchor.y)));
      v40 = clipModel[9];
      v98 = v37;
      v94[0].x = (float)v41 + clipModel[8];
      v94[0].z = (float)v39 + (float)v42;
      v94[0].y = (float)v40 + (float)v43;
    }
    else
    {
      v44 = this->pyramidBasis.mat[0].y;
      v45 = this->pyramidBasis.mat[0].z;
      v46 = this->pyramidBasis.mat[1].x;
      v47 = this->pyramidBasis.mat[1].y;
      v48 = this->pyramidBasis.mat[1].z;
      v49 = this->pyramidAnchor.x;
      v50 = this->pyramidAnchor.y;
      v51 = this->pyramidAnchor.z;
      v38 = this->pyramidBasis.mat[2].x;
      v36 = this->pyramidBasis.mat[2].y;
      v35 = this->pyramidBasis.mat[2].z;
      v95 = this->pyramidBasis.mat[0].x;
      v96 = v44;
      v97 = v45;
      v98 = v46;
      v99 = v47;
      v100 = v48;
      v94[0].x = v49;
      v94[0].y = v50;
      v94[0].z = v51;
    }
    p = this->lm.p;
    v103 = v35;
    v102 = v36;
    v101 = v38;
    v132 = idColor::colorGreen;
    if ( *p != 0.0 )
      v132 = idColor::colorOrange;
    v53 = common->RW(this: common);
    v54 = (float *)this->body1->clipModel;
    v55 = (float)((float)(this->body1Axis.x * v54[11])
                + (float)((float)(v54[14] * this->body1Axis.y) + (float)(v54[17] * this->body1Axis.z)));
    v56 = (float)((float)((float)(v54[18] * this->body1Axis.z)
                        + (float)((float)(v54[12] * this->body1Axis.x) + (float)(v54[15] * this->body1Axis.y)))
                * (float)10.0);
    v105[2] = v94[0].z
            + (float)((float)((float)(v54[19] * this->body1Axis.z)
                            + (float)((float)(v54[13] * this->body1Axis.x) + (float)(v54[16] * this->body1Axis.y)))
                    * (float)10.0);
    v105[0] = (float)((float)v55 * (float)10.0) + v94[0].x;
    v105[1] = v94[0].y + (float)v56;
    v53->DebugLine(this: v53, a2: (const idVec4 *)&v132, a3: v94, a4: (const idVec3 *)v105, a5: 0, a6: false);
    v57 = &this->sinHalfAngle[1];
    v58 = 0;
    v59 = &v113;
    do
    {
      v60 = *(v57++ - 1);
      v61 = (_cntlzw(v58) & 0x20) != 0;
      v106.mat[1].x = *v57;
      v62 = (float)(*(&v96 + 3 * v61) * (float)v60);
      v63 = (float)(*(&v97 + 3 * v61) * (float)v60);
      v106.mat[0].x = *(&v95 + 3 * v61) * (float)v60;
      v106.mat[0].y = v62;
      v106.mat[0].z = v63;
      v64 = (float *)idQuat::ToMat3(this: &v133, result: &v106);
      v59[1] = *v64;
      v65 = v64[1];
      ++v58;
      v66 = v64[2];
      v59[4] = v64[3];
      v67 = v64[4];
      v59[2] = v65;
      v59[3] = v66;
      v68 = v64[5];
      v59[5] = v67;
      v69 = v64[6];
      v59[6] = v68;
      v70 = v64[7];
      v59[7] = v69;
      v71 = v64[8];
      v59[8] = v70;
      v59 += 9;
      *v59 = v71;
    }
    while ( v58 < 2 );
    v72 = (float)((float)v35 * (float)10.0);
    v73 = (float)((float)v36 * (float)10.0);
    v74 = (float)((float)v38 * (float)10.0);
    v75 = (float)((float)(v131 * (float)v72) + (float)(v130 * (float)v73));
    v76 = (float)((float)(v123 * (float)v74) + (float)(v124 * (float)v73));
    v77 = (float)((float)((float)(v125 * (float)v74) + (float)(v128 * (float)v73)) + (float)(v131 * (float)v72));
    v78 = (float)((float)((float)(v127 * (float)v73) + (float)(v128 * (float)v72)) + (float)(v126 * (float)v74));
    v80 = (float)((float)((float)(v124 * (float)v74) + (float)(v130 * (float)v72)) + (float)(v127 * (float)v73));
    v81 = (float)((float)((float)(v126 * (float)v73) + (float)(v129 * (float)v72)) + (float)(v123 * (float)v74));
    v79 = v78;
    v83 = (float)((float)v76 + (float)(v125 * (float)v72));
    v85 = (float)((float)(v122 * (float)((float)v75 + (float)(v129 * (float)v74)))
                + (float)((float)(v116 * (float)v83) + (float)(v119 * (float)v78)));
    v86 = (float)((float)(v121 * (float)((float)v75 + (float)(v129 * (float)v74)))
                + (float)((float)(v115 * (float)v83) + (float)(v118 * (float)v78)));
    v84 = (float)((float)(v117 * (float)v78) + (float)(v120 * (float)((float)v75 + (float)(v129 * (float)v74))));
    v82 = (float)((float)v75 + (float)(v129 * (float)v74));
    v104[3] = -1.0;
    v104[2] = -1.0;
    v104[1] = -1.0;
    v104[0] = -1.0;
    v106.mat[2].x = v94[0].z
                  + (float)((float)(v122 * (float)v77) + (float)((float)(v116 * (float)v81) + (float)(v119 * (float)v80)));
    v106.mat[1].z = v94[0].y
                  + (float)((float)(v121 * (float)v77) + (float)((float)(v115 * (float)v81) + (float)(v118 * (float)v80)));
    v109 = v94[0].y
         + (float)((float)(v119 * (float)v82) + (float)((float)(v117 * (float)v83) + (float)(v118 * (float)v79)));
    v107 = v94[0].z + (float)v85;
    v110 = v94[0].z
         + (float)((float)(v122 * (float)v82) + (float)((float)(v120 * (float)v83) + (float)(v121 * (float)v79)));
    v106.mat[1].y = (float)((float)(v114 * (float)v81) + (float)((float)(v117 * (float)v80) + (float)(v120 * (float)v77)))
                  + v94[0].x;
    v106.mat[2].z = v94[0].y + (float)v86;
    v106.mat[2].y = (float)((float)((float)v83 * v114) + (float)v84) + v94[0].x;
    v87 = 0;
    v108 = (float)((float)((float)v83 * v114) + (float)((float)(v115 * (float)v79) + (float)(v116 * (float)v82)))
         + v94[0].x;
    v113 = v94[0].z
         + (float)((float)(v122 * (float)v77) + (float)((float)(v120 * (float)v81) + (float)(v121 * (float)v80)));
    p_y = (const idVec3 *)&v106.mat[1].y;
    v112 = v94[0].y
         + (float)((float)(v119 * (float)v77) + (float)((float)(v117 * (float)v81) + (float)(v118 * (float)v80)));
    v111 = (float)((float)((float)v81 * v114) + (float)((float)(v115 * (float)v80) + (float)(v116 * (float)v77)))
         + v94[0].x;
    do
    {
      v134.__vftable = (idWinding_vtbl *)&idFixedWinding::`vftable';
      v134.numPoints = 0;
      v134.p = (idVec5 *)&v135;
      v134.allocedSize = 64;
      v89 = v87 + 1;
      v90 = (const idVec3 *)(&v106.mat[1].y + ((v87 + 1) & 3) + ((2 * (v87 + 1)) & 6));
      idWinding::AddPoint(this: &v134, v: v90);
      idWinding::AddPoint(this: &v134, v: p_y);
      idWinding::AddPoint(this: &v134, v: v94);
      v104[3] = 0.40000001;
      v104[0] = 1.0;
      v104[1] = 0.0;
      v104[2] = 1.0;
      v91 = common->RW(this: common);
      v91->DebugFilledPolygon(this: v91, a2: (const idVec4 *)v104, a3: &v134, a4: 0, a5: false);
      v92 = common->RW(this: common);
      v92->DebugLine(this: v92, a2: (const idVec4 *)&idColor::colorMagenta, a3: v94, a4: p_y, a5: 0, a6: false);
      v93 = common->RW(this: common);
      v93->DebugLine(this: v93, a2: (const idVec4 *)&idColor::colorMagenta, a3: p_y, a4: v90, a5: 0, a6: false);
      v134.p = nullptr;
      v134.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
      idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
      v87 = v89;
      v134.p = nullptr;
      ++p_y;
    }
    while ( v89 < 4 );
  }
}


// ========================================================================
// __unwind$268162
// EA  : 0x82724AEC
// RVA : 0x00724AEC
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_268162()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 1920 + 400));
}


// ========================================================================
// ?Evaluate@idAFConstraint_Suspension@@MAAXPBVidPhysics_AF@@M@Z
// EA  : 0x82724B18
// RVA : 0x00724B18
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Suspension::Evaluate(
        idAFConstraint_Suspension *this,
        const idPhysics_AF *phys,
        double invTimeStep)
{
  float *p; // r9
  unsigned __int64 v5; // r28
  char *v6; // r10
  double valueFloat; // fp0
  int v8; // ctr
  double v9; // fp27
  double v10; // fp28
  float *p_z; // r11
  const idMat3 *v12; // r3
  idClipQuery *p_traceQuery; // r30
  double x; // fp20
  idClipModel *clipModel; // r11
  double y; // fp19
  double z; // fp18
  double v18; // fp17
  double v19; // fp16
  idClip *clip; // r29
  double v21; // fp15
  double v22; // fp14
  double v23; // fp23
  double v24; // fp22
  double v25; // fp31
  double v26; // fp30
  double v27; // fp29
  double v28; // fp26
  double v29; // fp25
  double v30; // fp24
  char IsValid; // r3
  unsigned __int64 index; // r11
  double fraction; // fp11
  double v34; // fp10
  double v35; // fp9
  double v36; // fp8
  double v37; // fp6
  double v38; // fp2
  double v39; // fp12
  int surfaceFlags; // r11
  int entityNum; // r10
  double v42; // fp13
  double v43; // fp12
  double v44; // fp10
  double v45; // fp9
  double traceFraction; // fp0
  int traceSurfaceFlags; // r10
  double v48; // fp5
  double v49; // fp6
  double v50; // fp0
  double v51; // fp13
  double v52; // fp12
  double v53; // fp21
  double v54; // fp18
  double v55; // fp22
  idAFBody *body2; // r10
  double v57; // fp23
  double v58; // fp9
  idClipModel *v59; // r11
  double v60; // fp8
  double v61; // fp7
  double v62; // fp15
  double v63; // fp16
  double v64; // fp17
  double v65; // fp11
  double v66; // fp2
  double v67; // fp1
  double v68; // fp0
  double v69; // fp13
  double v70; // fp12
  double v71; // fp2
  double v72; // fp1
  double v73; // fp0
  double v74; // fp13
  double v75; // fp12
  double v76; // fp25
  double v77; // fp24
  double v78; // fp20
  float *v79; // r11
  double v80; // fp12
  double v81; // fp0
  double v82; // fp13
  double lastTorque; // fp12
  float *v84; // r11
  double v85; // fp13
  double lastMotorVelocity; // fp0
  idAFBody *v87; // r11
  idAFBody *body1; // r11
  idAFBody *v89; // r9
  double v90; // fp12
  double v91; // fp10
  double v96; // fp0
  double v97; // fp13
  float *mat; // r11
  double v99; // fp11
  double v100; // fp3
  double v101; // fp31
  double v102; // fp6
  float *v103; // r11
  float *v104; // r11
  double v105; // fp13
  float *v106; // r11
  double v107; // fp0
  float *v108; // r11
  float *v109; // r30
  double v110; // fp19
  double v111; // fp0
  double v112; // fp5
  double v113; // fp3
  double v114; // fp2
  double v115; // fp0
  double v116; // fp9
  idAFBody *v117; // r11
  double v118; // fp7
  double v119; // fp3
  double v120; // fp29
  double v121; // fp30
  double v122; // fp31
  double v123; // fp11
  double v124; // fp12
  double v125; // fp13
  double v126; // fp0
  double v127; // fp4
  double v128; // fp3
  double v129; // fp31
  double v130; // fp30
  double v131; // fp0
  double wheelVelocity; // fp11
  idPhysics_AF *physics; // r3
  bool v134; // r4
  long double v135; // fp4
  double ContactFrictionScale; // fp1
  const idDeclTable *friction_lateral; // r11
  double v138; // fp28
  double v139; // fp26
  bool v140; // r4
  double v141; // fp28
  long double v142; // fp4
  long double v143; // fp2
  long double v144; // fp2
  const idDeclTable *friction_longitudinal; // r11
  double v146; // fp26
  long double v147; // fp2
  long double v148; // fp2
  float *v149; // r11
  float *v150; // r11
  float *v151; // r11
  double v152; // fp17
  float *v153; // r11
  idSpatialMat *p_J1; // r3
  double v155; // fp0
  BOOL motorEnabled; // r7
  float *v157; // r11
  double v158; // fp31
  double v159; // fp30
  double v160; // fp29
  float *v161; // r11
  float *v162; // r11
  float *v163; // r11
  float *v164; // r30
  float *v165; // r30
  float *v166; // r11
  float *v167; // r10
  float v170; // [sp+50h] [-220h]
  float v171; // [sp+54h] [-21Ch]
  float v172; // [sp+58h] [-218h]
  float v173; // [sp+5Ch] [-214h]
  idMat3 v174; // [sp+60h] [-210h] BYREF
  idVec3 v175; // [sp+88h] [-1E8h] BYREF
  char v176; // [sp+9Ch] [-1D4h] BYREF
  idMat3 v177; // [sp+A0h] [-1D0h] BYREF
  float v178; // [sp+C4h] [-1ACh]
  idVec3 v179; // [sp+C8h] [-1A8h]
  float v180; // [sp+D4h] [-19Ch]
  trace_t v181; // [sp+E0h] [-190h] BYREF
  idRotation v182; // [sp+160h] [-110h] BYREF
  float v183; // [sp+294h] [+24h]

  v183 = invTimeStep;
  if ( this->body1 != nullptr && this->clip != nullptr && this->physics != nullptr )
  {
    p = this->e.p;
    HIDWORD(v5) = &af_suspensionLcpEpsilon;
    v6 = &v176;
    valueFloat = af_suspensionLcpEpsilon.valueFloat;
    *p = af_suspensionLcpEpsilon.valueFloat;
    v8 = 9;
    p[1] = valueFloat;
    p[2] = valueFloat;
    p[3] = valueFloat;
    p[4] = valueFloat;
    p[5] = valueFloat;
    v9 = (float)(this->suspensionDown + this->suspensionUp);
    v10 = (float)((float)(this->suspensionDown + this->suspensionUp) * (float)0.25);
    v173 = this->suspensionDown + this->suspensionUp;
    p_z = &this->body1->clipModel->origin.z;
    do
    {
      ++p_z;
      v6 += 4;
      *(float *)v6 = *p_z;
      --v8;
    }
    while ( v8 != 0 );
    LODWORD(v5) = 0;
    v182.angle = this->steerAngle;
    v182.axisValid = false;
    v182.vec.x = v177.mat[2].x;
    v182.vec.y = v177.mat[2].y;
    v182.vec.z = v177.mat[2].z;
    v12 = idRotation::ToMat3(this: &v182);
    idMat3::operator*(this: &v174, result: &v177, a: v12);
    p_traceQuery = &this->traceQuery;
    x = v177.mat[2].x;
    clipModel = this->body1->clipModel;
    y = v177.mat[2].y;
    z = v177.mat[2].z;
    v18 = v177.mat[1].x;
    v19 = v177.mat[1].y;
    clip = this->clip;
    v21 = v177.mat[1].z;
    v22 = v174.mat[2].x;
    v23 = v174.mat[2].y;
    v24 = v174.mat[2].z;
    v25 = (float)((float)((float)(this->localOrigin.y * v177.mat[1].x)
                        + (float)((float)(this->localOrigin.x * v177.mat[0].x)
                                + (float)(this->localOrigin.z * v177.mat[2].x)))
                + clipModel->origin.x);
    v26 = (float)(clipModel->origin.y
                + (float)((float)(this->localOrigin.y * v177.mat[1].y)
                        + (float)((float)(this->localOrigin.x * v177.mat[0].y)
                                + (float)(this->localOrigin.z * v177.mat[2].y))));
    v27 = (float)(clipModel->origin.z
                + (float)((float)(this->localOrigin.y * v177.mat[1].z)
                        + (float)((float)(this->localOrigin.x * v177.mat[0].z)
                                + (float)(this->localOrigin.z * v177.mat[2].z))));
    v28 = (float)((float)((float)(this->suspensionUp + (float)v10) * v174.mat[2].x)
                + (float)((float)((float)(this->localOrigin.y * v177.mat[1].x)
                                + (float)((float)(this->localOrigin.x * v177.mat[0].x)
                                        + (float)(this->localOrigin.z * v177.mat[2].x)))
                        + clipModel->origin.x));
    v29 = (float)((float)((float)(this->suspensionUp + (float)v10) * v174.mat[2].y)
                + (float)(clipModel->origin.y
                        + (float)((float)(this->localOrigin.y * v177.mat[1].y)
                                + (float)((float)(this->localOrigin.x * v177.mat[0].y)
                                        + (float)(this->localOrigin.z * v177.mat[2].y)))));
    v30 = (float)((float)((float)(this->suspensionUp + (float)v10) * v174.mat[2].z)
                + (float)(clipModel->origin.z
                        + (float)((float)(this->localOrigin.y * v177.mat[1].z)
                                + (float)((float)(this->localOrigin.x * v177.mat[0].z)
                                        + (float)(this->localOrigin.z * v177.mat[2].z)))));
    IsValid = idClip::QueryIsValid(this: clip, clipQuery: &this->traceQuery);
    v178 = 1.0;
    if ( IsValid != 0 )
    {
      index = p_traceQuery->index;
      p_traceQuery->index = v5;
      idCollisionModelManager::GetContentsResult(
        this: collisionModelManager,
        result: &v181,
        query: &clip->collisionQueries[index & 0xFFF].query,
        peek: false);
      fraction = v181.fraction;
      v34 = v181.c.normal.z;
      v35 = v181.c.normal.y;
      v36 = v181.c.normal.x;
      if ( v181.fraction < 1.0
        && __fabs((float)((float)(v181.c.normal.x * (float)v22)
                        + (float)((float)((float)v23 * v181.c.normal.y) + (float)((float)v24 * v181.c.normal.z)))) < 0.2 )
      {
        v37 = (float)(this->lastWheelHeight * (float)v22);
        v38 = (float)((float)(this->suspensionUp - this->lastWheelHeight) + (float)v10);
        v39 = (float)((float)(this->lastWheelHeight * (float)v24) + (float)v27);
        v181.endpos.y = (float)(this->lastWheelHeight * (float)v23) + (float)v26;
        v181.endpos.z = v39;
        v181.endpos.x = (float)v37 + (float)v25;
        fraction = (float)((float)v38 / (float)((float)v10 + (float)v9));
        v181.fraction = (float)v38 / (float)((float)v10 + (float)v9);
      }
      surfaceFlags = v181.c.surfaceFlags;
      this->traceFraction = fraction;
      entityNum = v181.c.entityNum;
      v42 = v181.endpos.y;
      v43 = v181.endpos.z;
      this->traceEndPos.x = v181.endpos.x;
      this->traceEndPos.y = v42;
      this->traceEndPos.z = v43;
      this->traceNormal.y = v35;
      this->traceNormal.z = v34;
      this->traceNormal.x = v36;
      v44 = v181.c.point.y;
      v45 = v181.c.point.z;
      this->tracePoint.x = v181.c.point.x;
      this->tracePoint.y = v44;
      this->tracePoint.z = v45;
      this->traceSurfaceFlags = surfaceFlags;
      this->traceEntityNum = entityNum;
    }
    traceFraction = this->traceFraction;
    traceSurfaceFlags = this->traceSurfaceFlags;
    this->lastOnGround = traceFraction < 1.0;
    if ( (traceSurfaceFlags & 0x20) != 0 )
    {
      this->frictionLatMultiplier = 0.0;
      this->frictionLongMultiplier = 0.0;
    }
    v48 = (float)((float)((float)((float)v10 + v173) * (float)traceFraction) - (float)v10);
    v49 = (float)(this->suspensionUp - (float)((float)((float)((float)v10 + v173) * (float)traceFraction) - (float)v10));
    v180 = this->suspensionUp - (float)((float)((float)((float)v10 + v173) * (float)traceFraction) - (float)v10);
    if ( traceFraction < 1.0 )
    {
      v50 = this->tracePoint.x;
      v51 = this->tracePoint.y;
      v52 = this->tracePoint.z;
    }
    else
    {
      v50 = (float)(this->traceEndPos.x - (float)(this->wheelRadius * (float)v22));
      v51 = (float)(this->traceEndPos.y - (float)(this->wheelRadius * (float)v23));
      v52 = (float)(this->traceEndPos.z - (float)(this->wheelRadius * (float)v24));
    }
    v53 = v174.mat[0].x;
    v55 = v174.mat[0].y;
    body2 = this->body2;
    v57 = v174.mat[0].z;
    v58 = 0.0;
    v170 = 0.0;
    v171 = 0.0;
    v59 = this->body1->clipModel;
    v172 = 0.0;
    v60 = 0.0;
    v61 = 0.0;
    v65 = (float)(v59->origin.z
                + (float)((float)(this->cgLocation.y * (float)v21)
                        + (float)((float)(this->cgLocation.x * v177.mat[0].z) + (float)(this->cgLocation.z * (float)z))));
    v54 = v177.mat[0].x;
    v62 = v174.mat[1].x;
    v66 = (float)((float)((float)((float)((float)v52 - (float)v30) * v174.mat[0].z)
                        + (float)((float)((float)((float)v51 - (float)v29) * v174.mat[0].y)
                                + (float)((float)((float)v50 - (float)v28) * v174.mat[0].x)))
                * v174.mat[0].y);
    v67 = (float)((float)((float)((float)((float)v52 - (float)v30) * v174.mat[0].z)
                        + (float)((float)((float)((float)v51 - (float)v29) * v174.mat[0].y)
                                + (float)((float)((float)v50 - (float)v28) * v174.mat[0].x)))
                * v174.mat[0].z);
    v68 = (float)((float)v50
                - (float)((float)((float)((float)((float)v52 - (float)v30) * v174.mat[0].z)
                                + (float)((float)((float)((float)v51 - (float)v29) * v174.mat[0].y)
                                        + (float)((float)((float)v50 - (float)v28) * v174.mat[0].x)))
                        * v174.mat[0].x));
    v69 = (float)((float)v51 - (float)v66);
    v70 = (float)((float)v52 - (float)v67);
    v71 = (float)((float)((float)((float)((float)v70 - (float)v30) * v174.mat[1].z)
                        + (float)((float)((float)((float)v69 - (float)v29) * v174.mat[1].y)
                                + (float)((float)((float)v68 - (float)v28) * v174.mat[1].x)))
                * v174.mat[1].y);
    v72 = (float)((float)((float)((float)((float)v70 - (float)v30) * v174.mat[1].z)
                        + (float)((float)((float)((float)v69 - (float)v29) * v174.mat[1].y)
                                + (float)((float)((float)v68 - (float)v28) * v174.mat[1].x)))
                * v174.mat[1].z);
    v73 = (float)((float)v68
                - (float)((float)((float)((float)((float)v70 - (float)v30) * v174.mat[1].z)
                                + (float)((float)((float)((float)v69 - (float)v29) * v174.mat[1].y)
                                        + (float)((float)((float)v68 - (float)v28) * v174.mat[1].x)))
                        * v174.mat[1].x));
    v74 = (float)((float)v69 - (float)v71);
    v75 = (float)((float)v70 - (float)v72);
    v76 = (float)((float)v73
                - (float)((float)((float)(this->cgLocation.y * (float)v18)
                                + (float)((float)(this->cgLocation.x * v177.mat[0].x)
                                        + (float)(this->cgLocation.z * (float)x)))
                        + v59->origin.x));
    v64 = v174.mat[1].z;
    v77 = (float)((float)v74
                - (float)(v59->origin.y
                        + (float)((float)(this->cgLocation.y * (float)v19)
                                + (float)((float)(this->cgLocation.x * v177.mat[0].y)
                                        + (float)(this->cgLocation.z * (float)y)))));
    v63 = v174.mat[1].y;
    v78 = (float)((float)v75 - (float)v65);
    if ( body2 != nullptr )
    {
      v79 = (float *)body2->clipModel;
      v80 = (float)((float)v75 - v79[10]);
      v81 = (float)((float)v73 - v79[8]);
      v82 = (float)((float)v74 - v79[9]);
      v170 = v81;
      v171 = v82;
      v172 = v80;
      v61 = v80;
      v58 = v81;
      v60 = v82;
    }
    this->debugv3.x = v76;
    this->debugv3.y = v77;
    this->debugv3.z = v78;
    lastTorque = this->lastTorque;
    if ( lastTorque <= 0.0 )
    {
      body1 = this->body1;
      v85 = *this->lm.p;
      lastMotorVelocity = (float)((float)((float)((float)((float)v57 * (float)v77) - (float)((float)v55 * (float)v78))
                                        * body1->current.spatialVelocity.p[3])
                                + (float)((float)(body1->current.spatialVelocity.p[4]
                                                * (float)((float)((float)v53 * (float)v78)
                                                        - (float)((float)v76 * (float)v57)))
                                        + (float)((float)(body1->current.spatialVelocity.p[5]
                                                        * (float)((float)((float)v76 * (float)v55)
                                                                - (float)((float)v53 * (float)v77)))
                                                + (float)((float)(body1->current.spatialVelocity.p[0] * (float)v53)
                                                        + (float)((float)(body1->current.spatialVelocity.p[1]
                                                                        * (float)v55)
                                                                + (float)(body1->current.spatialVelocity.p[2]
                                                                        * (float)v57))))));
    }
    else
    {
      v84 = this->lm.p;
      v85 = (float)(this->lastGrip * *v84);
      if ( lastTorque > v85 && (v85 == 0.0 || __fabs((float)(v84[2] / (float)(this->lastGrip * *v84))) > 0.94999999) )
      {
        lastMotorVelocity = this->lastMotorVelocity;
        v85 = (float)(this->lastTorque - (float)(this->lastGrip * *v84));
      }
      else
      {
        v87 = this->body1;
        lastMotorVelocity = (float)((float)((float)((float)((float)v57 * (float)v77) - (float)((float)v55 * (float)v78))
                                          * v87->current.spatialVelocity.p[3])
                                  + (float)((float)(v87->current.spatialVelocity.p[4]
                                                  * (float)((float)((float)v53 * (float)v78)
                                                          - (float)((float)v76 * (float)v57)))
                                          + (float)((float)(v87->current.spatialVelocity.p[5]
                                                          * (float)((float)((float)v76 * (float)v55)
                                                                  - (float)((float)v53 * (float)v77)))
                                                  + (float)((float)(v87->current.spatialVelocity.p[0] * (float)v53)
                                                          + (float)((float)(v87->current.spatialVelocity.p[1]
                                                                          * (float)v55)
                                                                  + (float)(v87->current.spatialVelocity.p[2]
                                                                          * (float)v57))))));
      }
    }
    v89 = this->body1;
    v90 = (float)(this->wheelVelocity * (float)0.99000001);
    this->wheelVelocity = this->wheelVelocity * (float)0.99000001;
    v91 = v183;
    if ( lastMotorVelocity <= v90 )
    {
      _FP1 = (float)((float)lastMotorVelocity
                   - (float)((float)v90 - (float)((float)v85 / (float)((float)(v89->mass * (float)0.1) * v183))));
      v91 = v183;
      __asm { fsel      f0, f1, f0, f2 }
      this->wheelVelocity = _FP0;
    }
    else
    {
      _FP2 = (float)((float)lastMotorVelocity
                   - (float)((float)((float)v85 / (float)((float)(v89->mass * (float)0.1) * v183)) + (float)v90));
      __asm { fsel      f1, f2, f3, f0 }
      this->wheelVelocity = _FP1;
    }
    v96 = v174.mat[2].y;
    v97 = v174.mat[2].z;
    mat = this->J1.mat;
    v99 = (float)((float)((float)v76 * v174.mat[2].y) - (float)((float)v22 * (float)v77));
    v100 = (float)((float)(v174.mat[2].z * (float)v77) - (float)(v174.mat[2].y * (float)v78));
    v101 = (float)((float)(this->lastWheelHeight - (float)v49) * (float)v91);
    v102 = (float)((float)((float)v22 * (float)v78) - (float)((float)v76 * v174.mat[2].z));
    this->wheelAngle = (float)(this->wheelVelocity / (float)(this->wheelRadius * (float)v91)) + this->wheelAngle;
    mat[2] = v97;
    *mat = v22;
    mat[1] = v96;
    v103 = this->J1.mat;
    v103[3] = v100;
    v103[4] = v102;
    v103[5] = v99;
    *this->c1.p = 0.0;
    if ( this->body2 != nullptr )
    {
      v104 = this->J2.mat;
      v105 = -v97;
      *v104 = -v22;
      v104[1] = -v96;
      v104[2] = v105;
      v106 = this->J2.mat;
      v106[4] = (float)((float)v61 * (float)-v22) - (float)((float)v58 * (float)v105);
      v106[5] = (float)((float)v58 * (float)-v96) - (float)((float)v60 * (float)-v22);
      v106[3] = (float)((float)v105 * (float)v60) - (float)((float)-v96 * (float)v61);
      *this->c2.p = 0.0;
    }
    if ( v_compress.valueFloat >= 0.0 )
      this->suspensionCompress = v_compress.valueFloat;
    if ( v_damping.valueFloat >= 0.0 )
      this->suspensionDamping = v_damping.valueFloat;
    if ( v48 < v173 )
    {
      v108 = this->c1.p;
      if ( v48 < -1.0 )
      {
        *v108 = (float)((float)v48 * (float)v91) * (float)2.0;
        v107 = 1.0e30;
      }
      else
      {
        *v108 = -(float)((float)((float)(v173 - (float)v48) * (float)(v173 - (float)v48)) * (float)v91);
        v107 = (float)(this->physics->GetMass(this: this->physics, a2: -1)
                     * (float)((float)(this->suspensionCompress * (float)(v173 - (float)v48))
                             - (float)(this->suspensionDamping * (float)v101)));
        if ( v107 < 0.0 )
          v107 = 0.0;
      }
    }
    else
    {
      v107 = 0.0;
      *this->c1.p = 0.0;
    }
    *this->lo.p = 0.0;
    *this->hi.p = v107;
    v109 = this->e.p;
    *v109 = idPhysics_AF::GetLimitLcpEpsilon(this: this->physics);
    v110 = v178;
    v111 = this->traceFraction;
    this->boxConstraint = nullptr;
    this->boxScale[0] = 0.0;
    this->boxIndex[0] = -1;
    if ( v111 < v110 )
    {
      v112 = (float)(this->traceNormal.x
                   * (float)((float)(this->traceNormal.z * (float)v57)
                           + (float)((float)(this->traceNormal.x * (float)v53)
                                   + (float)(this->traceNormal.y * (float)v55))));
      v113 = (float)(this->traceNormal.z
                   * (float)((float)(this->traceNormal.z * (float)v57)
                           + (float)((float)(this->traceNormal.x * (float)v53)
                                   + (float)(this->traceNormal.y * (float)v55))));
      v114 = (float)(this->traceNormal.x
                   * (float)((float)(this->traceNormal.z * (float)v64)
                           + (float)((float)(this->traceNormal.x * (float)v62)
                                   + (float)(this->traceNormal.y * (float)v63))));
      v115 = (float)(this->traceNormal.z
                   * (float)((float)(this->traceNormal.z * (float)v64)
                           + (float)((float)(this->traceNormal.x * (float)v62)
                                   + (float)(this->traceNormal.y * (float)v63))));
      v116 = (float)((float)v63
                   - (float)(this->traceNormal.y
                           * (float)((float)(this->traceNormal.z * (float)v64)
                                   + (float)((float)(this->traceNormal.x * (float)v62)
                                           + (float)(this->traceNormal.y * (float)v63)))));
      v174.mat[0].y = (float)v55
                    - (float)(this->traceNormal.y
                            * (float)((float)(this->traceNormal.z * (float)v57)
                                    + (float)((float)(this->traceNormal.x * (float)v53)
                                            + (float)(this->traceNormal.y * (float)v55))));
      v174.mat[1].y = v116;
      v174.mat[0].x = (float)v53 - (float)v112;
      v174.mat[0].z = (float)v57 - (float)v113;
      v174.mat[1].x = (float)v62 - (float)v114;
      v174.mat[1].z = (float)v64 - (float)v115;
      idVec3::NormalizeFast(this: v174.mat);
      idVec3::NormalizeFast(this: &v174.mat[1]);
      v64 = v174.mat[1].z;
      v63 = v174.mat[1].y;
      v62 = v174.mat[1].x;
      v57 = v174.mat[0].z;
      v55 = v174.mat[0].y;
      v53 = v174.mat[0].x;
    }
    v117 = this->body1;
    v118 = v117->current.spatialVelocity.p[2];
    v119 = (float)((float)(v117->current.spatialVelocity.p[3] * (float)v77)
                 - (float)((float)v76 * v117->current.spatialVelocity.p[4]));
    v120 = (float)(v117->current.spatialVelocity.p[1]
                 + (float)((float)((float)v76 * v117->current.spatialVelocity.p[5])
                         - (float)(v117->current.spatialVelocity.p[3] * (float)v78)));
    v121 = (float)(v117->current.spatialVelocity.p[0]
                 + (float)((float)(v117->current.spatialVelocity.p[4] * (float)v78)
                         - (float)(v117->current.spatialVelocity.p[5] * (float)v77)));
    v179.y = v117->current.spatialVelocity.p[1]
           + (float)((float)((float)v76 * v117->current.spatialVelocity.p[5])
                   - (float)(v117->current.spatialVelocity.p[3] * (float)v78));
    v179.x = v121;
    v122 = (float)((float)v118 + (float)v119);
    v179.z = (float)v118 + (float)v119;
    v175 = v179;
    idVec3::NormalizeFast(this: &v175);
    v123 = v175.z;
    v124 = v175.y;
    v125 = v175.x;
    if ( (float)((float)((float)v54 * v175.x)
               + (float)((float)(v175.y * v177.mat[0].y) + (float)(v175.z * v177.mat[0].z))) < 0.0 )
    {
      v125 = -v125;
      v124 = -v124;
      v123 = -v123;
    }
    this->debugv1.y = (float)v120 * (float)0.1;
    this->debugv1.z = (float)v122 * (float)0.1;
    this->debugv1.x = (float)v121 * (float)0.1;
    v126 = (float)((float)((float)v53 * (float)v121)
                 + (float)((float)((float)v57 * (float)v122) + (float)((float)v55 * (float)v120)));
    v127 = (float)((float)v55 * this->wheelVelocity);
    v128 = (float)((float)v57 * this->wheelVelocity);
    this->debugv2.x = (float)((float)v53 * this->wheelVelocity) * (float)0.1;
    this->debugv2.y = (float)v127 * (float)0.1;
    this->debugv2.z = (float)v128 * (float)0.1;
    if ( __fabs(v126) >= v110 )
    {
      v129 = __fabs((float)((float)((float)v126 - this->wheelVelocity) / (float)v126));
      v130 = (float)(idMath::ACos16(a: (float)((float)((float)v53 * (float)v125)
                                             + (float)((float)((float)v55 * (float)v124)
                                                     + (float)((float)v57 * (float)v123))))
                   * (float)((float)2.0 / (float)3.1415927));
      if ( v129 > v110 )
        v129 = v110;
      if ( v130 > v110 )
        v130 = v110;
    }
    else
    {
      v129 = 0.0;
      v130 = 0.0;
    }
    v131 = __fsqrts((float)((float)((float)v130 * (float)v130) + (float)((float)v129 * (float)v129)));
    if ( v131 > v110 )
    {
      v130 = (float)((float)v131 * (float)v130);
      v129 = (float)((float)v131 * (float)v129);
    }
    wheelVelocity = this->wheelVelocity;
    this->debugf2 = v129;
    this->debugf3 = v131;
    physics = this->physics;
    this->debugf1 = (float)v130 * (float)90.0;
    this->debugf4 = (float)wheelVelocity * (float)0.056818184;
    ContactFrictionScale = idPhysics_AF::GetContactFrictionScale(this: physics);
    friction_lateral = this->friction_lateral;
    v139 = (float)(this->frictionLongMultiplier * (float)ContactFrictionScale);
    if ( friction_lateral != nullptr )
    {
      v138 = (float)(this->frictionLatMultiplier * (float)ContactFrictionScale);
      v141 = (float)(idLookupTable::TableLookup(this: friction_lateral->table, time: v130, fastSearch: v134)
                   * (float)v138);
    }
    else
    {
      *((double *)&v143 + 1) = 5.0;
      *(double *)&v143 = (float)((float)v110 - (float)v130);
      v144 = pow(x: v143, y: v135);
      v141 = (float)((float)v110 - (float)*(double *)&v144);
    }
    friction_longitudinal = this->friction_longitudinal;
    if ( friction_longitudinal != nullptr )
    {
      v146 = (float)(idLookupTable::TableLookup(this: friction_longitudinal->table, time: v129, fastSearch: v140)
                   * (float)v139);
    }
    else
    {
      *((double *)&v147 + 1) = 5.0;
      *(double *)&v147 = (float)((float)v110 - (float)v129);
      v148 = pow(x: v147, y: v142);
      v146 = (float)((float)v110 - (float)*(double *)&v148);
    }
    if ( af_showTableResults.valueInteger != 0 )
    {
      this->debugf2 = v146;
      this->debugf3 = v141;
    }
    v149 = this->J1.mat;
    this->lateralSlip = v130;
    this->longitudinalSlip = v129;
    v149[8] = v62;
    v149[9] = v63;
    v149[10] = v64;
    v150 = this->J1.mat;
    v150[11] = (float)((float)v64 * (float)v77) - (float)((float)v63 * (float)v78);
    v150[12] = (float)((float)v62 * (float)v78) - (float)((float)v76 * (float)v64);
    v150[13] = (float)((float)v76 * (float)v63) - (float)((float)v62 * (float)v77);
    this->c1.p[1] = 0.0;
    if ( this->body2 != nullptr )
    {
      v151 = this->J2.mat;
      v151[8] = -v62;
      v151[9] = -v63;
      v151[10] = -v64;
      v153 = this->J2.mat;
      v153[12] = (float)(v172 * (float)-v62) - (float)(v170 * (float)-v64);
      v153[13] = (float)(v170 * (float)-v63) - (float)(v171 * (float)-v62);
      v153[11] = (float)((float)-v64 * v171) - (float)((float)-v63 * v172);
      v152 = v172;
      this->c2.p[1] = 0.0;
    }
    else
    {
      v152 = v172;
    }
    p_J1 = &this->J1;
    this->e.p[1] = af_suspensionLcpEpsilon.valueFloat;
    v155 = BOX_SCALE_MAX;
    this->lo.p[1] = -BOX_SCALE_MAX;
    this->hi.p[1] = v155;
    motorEnabled = this->motorEnabled;
    this->boxScale[1] = v141;
    this->boxConstraint = this;
    this->boxIndex[1] = 0;
    if ( motorEnabled )
    {
      idSpatialMat::ChangeNumRows(this: p_J1, rows: 3);
      idSpatialVec::ChangeSize(this: &this->c1, newSize: 3);
      v157 = this->J1.mat;
      v158 = -v55;
      v159 = -v57;
      v160 = -v53;
      v157[16] = -v53;
      v157[17] = -v55;
      v157[18] = -v57;
      v161 = this->J1.mat;
      v161[19] = (float)((float)-v57 * (float)v77) - (float)((float)-v55 * (float)v78);
      v161[20] = (float)((float)v78 * (float)-v53) - (float)((float)v76 * (float)-v57);
      v161[21] = (float)((float)v76 * (float)-v55) - (float)((float)v77 * (float)-v53);
      this->c1.p[2] = this->motorVelocity;
      if ( this->body2 != nullptr )
      {
        idSpatialMat::ChangeNumRows(this: &this->J2, rows: 3);
        idSpatialVec::ChangeSize(this: &this->c2, newSize: 3);
        v162 = this->J2.mat;
        v162[16] = v160;
        v162[17] = v158;
        v162[18] = v159;
        v163 = this->J2.mat;
        v163[21] = (float)(v170 * (float)v158) - (float)(v171 * (float)v160);
        v163[19] = (float)((float)v159 * v171) - (float)((float)v158 * (float)v152);
        v163[20] = (float)((float)v152 * (float)v160) - (float)(v170 * (float)v159);
        this->c2.p[2] = 0.0;
      }
      v164 = this->lo.p;
      v164[2] = -(float)(this->physics->GetMass(this: this->physics, a2: -1) * this->motorForce);
      v165 = this->hi.p;
      v165[2] = this->physics->GetMass(this: this->physics, a2: -1) * this->motorForce;
      this->e.p[2] = af_suspensionLcpEpsilon.valueFloat;
      this->boxIndex[2] = 0;
      this->boxScale[2] = v146;
    }
    else
    {
      idSpatialMat::ChangeNumRows(this: p_J1, rows: 2);
      idSpatialVec::ChangeSize(this: &this->c1, newSize: 2);
      if ( this->body2 != nullptr )
      {
        idSpatialMat::ChangeNumRows(this: &this->J2, rows: 2);
        idSpatialVec::ChangeSize(this: &this->c2, newSize: 2);
      }
      this->lo.p[2] = 0.0;
      this->hi.p[2] = 0.0;
      this->lm.p[2] = 0.0;
      this->boxScale[2] = 0.0;
      this->boxIndex[2] = -1;
    }
    v166 = this->lo.p;
    this->lastMotorVelocity = this->motorVelocity;
    v167 = this->hi.p;
    this->lastWheelHeight = v180;
    _FP8 = (float)(v167[2] - (float)-v166[2]);
    this->lastGrip = this->boxScale[2];
    __asm { fsel      f7, f8, f9, f10 }
    this->lastTorque = _FP7;
  }
}


// ========================================================================
// ?Serialize@idAFConstraint_Suspension@@UAAXAAVidSerializer@@@Z
// EA  : 0x82725898
// RVA : 0x00725898
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Suspension::Serialize(idAFConstraint_Suspension *this, idSerializer *ser)
{
  bool motorEnabled; // r29
  idBitMsg *msg; // r3
  bool lastOnGround; // r29
  idBitMsg *v7; // r3
  idBitMsg *v8; // r3
  idBitMsg *v9; // r3
  idBitMsg *v10; // r3
  idBitMsg *v11; // r3
  idBitMsg *v12; // r3
  idBitMsg *v13; // r3
  idBitMsg *v14; // r3
  idBitMsg *v15; // r3
  idBitMsg *v16; // r3
  idBitMsg *v17; // r3
  float *p; // r29
  idBitMsg *v19; // r3
  float *v20; // r29
  idBitMsg *v21; // r3
  float *v22; // r30
  idBitMsg *v23; // r3

  motorEnabled = this->motorEnabled;
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: motorEnabled, numBits: 1);
  else
    motorEnabled = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->motorEnabled = motorEnabled;
  lastOnGround = this->lastOnGround;
  v7 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v7, value: this->lastOnGround, numBits: 1);
  else
    lastOnGround = (_cntlzw(idBitMsg::ReadBits(this: v7, numBits: 1) - 1) & 0x20) != 0;
  this->lastOnGround = lastOnGround;
  v8 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v8, value: COERCE_INT(this->steerAngle), numBits: 32);
  else
    LODWORD(this->steerAngle) = idBitMsg::ReadBits(this: v8, numBits: 32);
  v9 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v9, value: COERCE_INT(this->motorForce), numBits: 32);
  else
    LODWORD(this->motorForce) = idBitMsg::ReadBits(this: v9, numBits: 32);
  v10 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v10, value: COERCE_INT(this->motorVelocity), numBits: 32);
  else
    LODWORD(this->motorVelocity) = idBitMsg::ReadBits(this: v10, numBits: 32);
  idSerializer::Serialize(this: ser, value: &this->cgLocation);
  v11 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v11, value: COERCE_INT(this->frictionLatMultiplier), numBits: 32);
  else
    LODWORD(this->frictionLatMultiplier) = idBitMsg::ReadBits(this: v11, numBits: 32);
  v12 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v12, value: COERCE_INT(this->frictionLongMultiplier), numBits: 32);
  else
    LODWORD(this->frictionLongMultiplier) = idBitMsg::ReadBits(this: v12, numBits: 32);
  v13 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v13, value: COERCE_INT(this->wheelVelocity), numBits: 32);
  else
    LODWORD(this->wheelVelocity) = idBitMsg::ReadBits(this: v13, numBits: 32);
  v14 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v14, value: COERCE_INT(this->lastWheelHeight), numBits: 32);
  else
    LODWORD(this->lastWheelHeight) = idBitMsg::ReadBits(this: v14, numBits: 32);
  v15 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v15, value: COERCE_INT(this->lastMotorVelocity), numBits: 32);
  else
    LODWORD(this->lastMotorVelocity) = idBitMsg::ReadBits(this: v15, numBits: 32);
  v16 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v16, value: COERCE_INT(this->lastTorque), numBits: 32);
  else
    LODWORD(this->lastTorque) = idBitMsg::ReadBits(this: v16, numBits: 32);
  v17 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v17, value: COERCE_INT(this->lastGrip), numBits: 32);
  else
    LODWORD(this->lastGrip) = idBitMsg::ReadBits(this: v17, numBits: 32);
  p = this->lm.p;
  v19 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v19, value: COERCE_INT(*p), numBits: 32);
  else
    *(_DWORD *)p = idBitMsg::ReadBits(this: v19, numBits: 32);
  v20 = this->lm.p;
  v21 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v21, value: COERCE_INT(v20[1]), numBits: 32);
  else
    *((_DWORD *)v20 + 1) = idBitMsg::ReadBits(this: v21, numBits: 32);
  v22 = this->lm.p;
  v23 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v23, value: COERCE_INT(v22[2]), numBits: 32);
  else
    *((_DWORD *)v22 + 2) = idBitMsg::ReadBits(this: v23, numBits: 32);
}


// ========================================================================
// ??0idAFConstraint@@QAA@XZ
// EA  : 0x82725BF8
// RVA : 0x00725BF8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint *__fastcall idAFConstraint::idAFConstraint(
        idAFConstraint *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        idAFConstraint *a12)
{
  idAtomicString *p_name; // r25
  float *v17; // r10
  int v19; // ctr
  float *v21; // r9
  float *p_z; // r10
  int v23; // ctr
  float *v27; // r11
  double valueFloat; // fp12
  float v34[29]; // [sp+5Ch] [-74h] BYREF

  _R12 = -80;
  __asm { stvx128   v127, r1, r12 }
  a12 = this;
  this->__vftable = (idAFConstraint_vtbl *)&idAFConstraint::`vftable';
  p_name = &this->name;
  this->name.str = &byte_8200D768;
  this->lm.allocated = 0;
  this->lm.size = 0;
  this->lm.p = nullptr;
  idSpatialVec::SetData(this: &this->lm, length: 0, data: this->lm.data);
  this->J1.allocatedRows = 0;
  this->J1.numColumns = 0;
  this->J1.numRows = 0;
  this->J1.mat = nullptr;
  this->J2.allocatedRows = 0;
  this->J2.numColumns = 0;
  this->J2.numRows = 0;
  this->J2.mat = nullptr;
  this->c1.allocated = 0;
  this->c1.size = 0;
  this->c1.p = nullptr;
  idSpatialVec::SetData(this: &this->c1, length: 0, data: this->c1.data);
  this->c2.allocated = 0;
  this->c2.size = 0;
  this->c2.p = nullptr;
  idSpatialVec::SetData(this: &this->c2, length: 0, data: this->c2.data);
  this->lo.allocated = 0;
  this->lo.size = 0;
  this->lo.p = nullptr;
  idSpatialVec::SetData(this: &this->lo, length: 0, data: this->lo.data);
  this->hi.allocated = 0;
  this->hi.size = 0;
  this->hi.p = nullptr;
  idSpatialVec::SetData(this: &this->hi, length: 0, data: this->hi.data);
  this->e.allocated = 0;
  this->e.size = 0;
  this->e.p = nullptr;
  idSpatialVec::SetData(this: &this->e, length: 0, data: this->e.data);
  this->invI.allocatedRows = 0;
  this->invI.numColumns = 0;
  this->invI.numRows = 0;
  this->invI.mat = nullptr;
  this->J.allocatedRows = 0;
  this->J.numColumns = 0;
  this->J.numRows = 0;
  this->J.mat = nullptr;
  this->type = CONSTRAINT_INVALID;
  idAtomicString::Set(this: p_name, str_: "noname");
  this->body1 = nullptr;
  this->body2 = nullptr;
  this->physics = nullptr;
  idSpatialVec::SetSize(this: &this->lo, newSize: 6);
  __asm { vspltisw128 v127, 0 }
  _R3 = this->lo.p;
  _R25 = 16;
  v17 = v34;
  __asm { stvx128   v127, r0, r3 }
  v19 = 6;
  _R11 = _R3;
  __asm { stvx128   v127, r11, r25 }
  v34[2] = -vec6_infinity.p[1];
  v34[3] = -vec6_infinity.p[2];
  v21 = _R3 - 1;
  v34[4] = -vec6_infinity.p[3];
  v34[5] = -vec6_infinity.p[4];
  v34[6] = -vec6_infinity.p[5];
  v34[1] = -vec6_infinity.p[0];
  do
  {
    *++v21 = *++v17;
    --v19;
  }
  while ( v19 != 0 );
  idSpatialVec::SetSize(this: &this->hi, newSize: 6);
  p_z = &vec3_infinity.z;
  v23 = 6;
  _R11 = this->hi.p;
  __asm { stvx128   v127, r0, r11 }
  _R9 = _R11;
  __asm { stvx128   v127, r9, r25 }
  v27 = _R11 - 1;
  do
  {
    *++v27 = *++p_z;
    --v23;
  }
  while ( v23 != 0 );
  idSpatialVec::SetSize(this: &this->e, newSize: 6);
  _R8 = this->e.p;
  __asm { stvx128   v127, r0, r8 }
  _R7 = _R8;
  __asm { stvx128   v127, r7, r25 }
  valueFloat = af_lcpEpsilon.valueFloat;
  *_R8 = af_lcpEpsilon.valueFloat;
  _R8[1] = valueFloat;
  _R8[2] = valueFloat;
  _R8[3] = valueFloat;
  _R8[4] = valueFloat;
  _R8[5] = valueFloat;
  this->boxConstraint = nullptr;
  this->boxScale[5] = 0.0;
  this->boxIndex[5] = -1;
  this->boxScale[4] = 0.0;
  this->boxIndex[4] = -1;
  this->boxScale[3] = 0.0;
  this->boxIndex[3] = -1;
  this->boxScale[2] = 0.0;
  this->boxIndex[2] = -1;
  this->boxScale[1] = 0.0;
  this->boxIndex[1] = -1;
  this->boxScale[0] = 0.0;
  this->boxIndex[0] = -1;
  this->firstIndex = 0;
  this->fl = 0;
  _R0 = -80;
  __asm { lvx128    v127, r1, r0 }
  return this;
}


// ========================================================================
// __unwind$270999
// EA  : 0x82725F00
// RVA : 0x00725F00
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_270999()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 208 + 228) + 48));
}


// ========================================================================
// __unwind$271000
// EA  : 0x82725F2C
// RVA : 0x00725F2C
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271000()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 208 + 228) + 96));
}


// ========================================================================
// __unwind$271001
// EA  : 0x82725F58
// RVA : 0x00725F58
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271001()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 208 + 228) + 112));
}


// ========================================================================
// __unwind$271002
// EA  : 0x82725F84
// RVA : 0x00725F84
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271002()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 208 + 228) + 128));
}


// ========================================================================
// __unwind$271003
// EA  : 0x82725FB0
// RVA : 0x00725FB0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271003()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 208 + 228) + 176));
}


// ========================================================================
// __unwind$271004
// EA  : 0x82725FDC
// RVA : 0x00725FDC
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271004()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 208 + 228) + 224));
}


// ========================================================================
// __unwind$271005
// EA  : 0x82726008
// RVA : 0x00726008
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271005()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 208 + 228) + 272));
}


// ========================================================================
// __unwind$271006
// EA  : 0x82726034
// RVA : 0x00726034
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271006()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(*(_DWORD *)(v0 - 208 + 228) + 320));
}


// ========================================================================
// __unwind$271007
// EA  : 0x82726060
// RVA : 0x00726060
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271007()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 208 + 228) + 420));
}


// ========================================================================
// __unwind$271008
// EA  : 0x8272608C
// RVA : 0x0072608C
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271008()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(*(_DWORD *)(v0 - 208 + 228) + 436));
}


// ========================================================================
// ?InitSize@idAFConstraint@@IAAXH@Z
// EA  : 0x827260B8
// RVA : 0x007260B8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint::InitSize(idAFConstraint *this, int size)
{
  _R12 = -48;
  __asm { stvx128   v127, r1, r12 }
  idSpatialMat::Zero(this: &this->J1, rows: size, columns: 6);
  idSpatialMat::Zero(this: &this->J2, rows: size, columns: 6);
  idSpatialVec::SetSize(this: &this->c1, newSize: size);
  __asm { vspltisw128 v127, 0 }
  _R11 = this->c1.p;
  _R30 = 16;
  __asm { stvx128   v127, r0, r11 }
  _R10 = _R11;
  __asm { stvx128   v127, r10, r30 }
  idSpatialVec::SetSize(this: &this->c2, newSize: size);
  _R9 = this->c2.p;
  __asm { stvx128   v127, r0, r9 }
  _R8 = _R9;
  __asm { stvx128   v127, r8, r30 }
  idSpatialVec::SetSize(this: &this->lm, newSize: size);
  _R7 = this->lm.p;
  __asm { stvx128   v127, r0, r7 }
  _R6 = _R7;
  __asm { stvx128   v127, r6, r30 }
  _R0 = -48;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// ??0idAFConstraint_Fixed@@QAA@PBDPAVidAFBody@@1@Z
// EA  : 0x82726168
// RVA : 0x00726168
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint_Fixed *__fastcall idAFConstraint_Fixed::idAFConstraint_Fixed(
        idAFConstraint_Fixed *this,
        const char *name,
        idAFBody *body1,
        idAFBody *body2,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int v13; // [sp+8h] [-78h]
  int v14; // [sp+Ch] [-74h]
  int v15; // [sp+10h] [-70h]
  idAFConstraint *v16; // [sp+14h] [-6Ch]

  idAFConstraint::idAFConstraint(
    this,
    a2: (int)name,
    a3: (int)body1,
    a4: (int)body2,
    a5,
    a6,
    a7,
    a8,
    a9: v13,
    a10: v14,
    a11: v15,
    a12: v16);
  this->type = CONSTRAINT_FIXED;
  this->__vftable = (idAFConstraint_Fixed_vtbl *)&idAFConstraint_Fixed::`vftable';
  idAtomicString::Set(this: &this->name, str_: name);
  this->body1 = body1;
  this->body2 = body2;
  idAFConstraint::InitSize(this, size: 6);
  *(_BYTE *)&this->fl |= 0xA0u;
  idAFConstraint_Fixed::InitOffset(this);
  return this;
}


// ========================================================================
// __unwind$271418
// EA  : 0x827261E4
// RVA : 0x007261E4
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271418()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idAFConstraint_BallAndSocketJoint@@QAA@PBDPAVidAFBody@@1@Z
// EA  : 0x82726218
// RVA : 0x00726218
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint_BallAndSocketJoint *__fastcall idAFConstraint_BallAndSocketJoint::idAFConstraint_BallAndSocketJoint(
        idAFConstraint_BallAndSocketJoint *this,
        const char *name,
        idAFBody *body1,
        idAFBody *body2,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idAFConstraint::constraintFlags_s fl; // r7
  int v14; // [sp+8h] [-78h]
  int v15; // [sp+Ch] [-74h]
  int v16; // [sp+10h] [-70h]
  idAFConstraint *v17; // [sp+14h] [-6Ch]

  idAFConstraint::idAFConstraint(
    this,
    a2: (int)name,
    a3: (int)body1,
    a4: (int)body2,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v15,
    a11: v16,
    a12: v17);
  this->type = CONSTRAINT_BALLANDSOCKETJOINT;
  this->__vftable = (idAFConstraint_BallAndSocketJoint_vtbl *)&idAFConstraint_BallAndSocketJoint::`vftable';
  idAtomicString::Set(this: &this->name, str_: name);
  this->body1 = body1;
  this->body2 = body2;
  idAFConstraint::InitSize(this, size: 3);
  fl = this->fl;
  this->coneLimit = nullptr;
  this->pyramidLimit = nullptr;
  this->fc = nullptr;
  this->friction = 0.0;
  this->fl = (idAFConstraint::constraintFlags_s)(*(_BYTE *)&fl | 0xA0);
  return this;
}


// ========================================================================
// __unwind$271462
// EA  : 0x827262A8
// RVA : 0x007262A8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271462()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idAFConstraint_BallAndSocketJointFriction@@QAA@XZ
// EA  : 0x827262D8
// RVA : 0x007262D8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint_BallAndSocketJointFriction *__fastcall idAFConstraint_BallAndSocketJointFriction::idAFConstraint_BallAndSocketJointFriction(
        idAFConstraint_BallAndSocketJointFriction *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idAFConstraint::constraintFlags_s v9; // r5
  int v11; // [sp+8h] [-68h]
  int v12; // [sp+Ch] [-64h]
  int v13; // [sp+10h] [-60h]
  idAFConstraint *v14; // [sp+14h] [-5Ch]

  idAFConstraint::idAFConstraint(this, a2, a3, a4, a5, a6, a7, a8, a9: v11, a10: v12, a11: v13, a12: v14);
  this->type = CONSTRAINT_FRICTION;
  this->__vftable = (idAFConstraint_BallAndSocketJointFriction_vtbl *)&idAFConstraint_BallAndSocketJointFriction::`vftable';
  idAtomicString::Set(this: &this->name, str_: "ballAndSocketJointFriction");
  idAFConstraint::InitSize(this, size: 3);
  v9 = (idAFConstraint::constraintFlags_s)(*(_BYTE *)&this->fl & 0x3F | 0x40);
  this->joint = nullptr;
  this->fl = v9;
  return this;
}


// ========================================================================
// __unwind$271488
// EA  : 0x82726360
// RVA : 0x00726360
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271488()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idAFConstraint_UniversalJoint@@QAA@PBDPAVidAFBody@@1@Z
// EA  : 0x827263F0
// RVA : 0x007263F0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint_UniversalJoint *__fastcall idAFConstraint_UniversalJoint::idAFConstraint_UniversalJoint(
        idAFConstraint_UniversalJoint *this,
        const char *name,
        idAFBody *body1,
        idAFBody *body2,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idAFConstraint::constraintFlags_s fl; // r7
  int v14; // [sp+8h] [-78h]
  int v15; // [sp+Ch] [-74h]
  int v16; // [sp+10h] [-70h]
  idAFConstraint *v17; // [sp+14h] [-6Ch]

  idAFConstraint::idAFConstraint(
    this,
    a2: (int)name,
    a3: (int)body1,
    a4: (int)body2,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v15,
    a11: v16,
    a12: v17);
  this->type = CONSTRAINT_UNIVERSALJOINT;
  this->__vftable = (idAFConstraint_UniversalJoint_vtbl *)&idAFConstraint_UniversalJoint::`vftable';
  idAtomicString::Set(this: &this->name, str_: name);
  this->body1 = body1;
  this->body2 = body2;
  idAFConstraint::InitSize(this, size: 4);
  fl = this->fl;
  this->coneLimit = nullptr;
  this->pyramidLimit = nullptr;
  this->fc = nullptr;
  this->friction = 0.0;
  this->fl = (idAFConstraint::constraintFlags_s)(*(_BYTE *)&fl | 0xA0);
  return this;
}


// ========================================================================
// __unwind$271574
// EA  : 0x82726480
// RVA : 0x00726480
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271574()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idAFConstraint_UniversalJointFriction@@QAA@XZ
// EA  : 0x827264B0
// RVA : 0x007264B0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint_UniversalJointFriction *__fastcall idAFConstraint_UniversalJointFriction::idAFConstraint_UniversalJointFriction(
        idAFConstraint_UniversalJointFriction *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idAFConstraint::constraintFlags_s v9; // r5
  int v11; // [sp+8h] [-68h]
  int v12; // [sp+Ch] [-64h]
  int v13; // [sp+10h] [-60h]
  idAFConstraint *v14; // [sp+14h] [-5Ch]

  idAFConstraint::idAFConstraint(this, a2, a3, a4, a5, a6, a7, a8, a9: v11, a10: v12, a11: v13, a12: v14);
  this->type = CONSTRAINT_FRICTION;
  this->__vftable = (idAFConstraint_UniversalJointFriction_vtbl *)&idAFConstraint_UniversalJointFriction::`vftable';
  idAtomicString::Set(this: &this->name, str_: "universalJointFriction");
  idAFConstraint::InitSize(this, size: 2);
  v9 = (idAFConstraint::constraintFlags_s)(*(_BYTE *)&this->fl & 0x3F | 0x40);
  this->joint = nullptr;
  this->fl = v9;
  return this;
}


// ========================================================================
// __unwind$271612
// EA  : 0x82726538
// RVA : 0x00726538
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271612()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idAFConstraint_Hinge@@QAA@PBDPAVidAFBody@@1@Z
// EA  : 0x82726568
// RVA : 0x00726568
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint_Hinge *__fastcall idAFConstraint_Hinge::idAFConstraint_Hinge(
        idAFConstraint_Hinge *this,
        const char *name,
        idAFBody *body1,
        idAFBody *body2,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idAFConstraint::constraintFlags_s fl; // r5
  float *clipModel; // r11
  double v14; // fp13
  double v15; // fp12
  double v16; // fp11
  double v17; // fp10
  double v18; // fp9
  double v19; // fp8
  double v20; // fp7
  double v21; // fp6
  int v23; // [sp+8h] [-B8h]
  int v24; // [sp+Ch] [-B4h]
  int v25; // [sp+10h] [-B0h]
  idAFConstraint *v26; // [sp+14h] [-ACh]
  idMat3 v27; // [sp+60h] [-60h] BYREF

  idAFConstraint::idAFConstraint(
    this,
    a2: (int)name,
    a3: (int)body1,
    a4: (int)body2,
    a5,
    a6,
    a7,
    a8,
    a9: v23,
    a10: v24,
    a11: v25,
    a12: v26);
  this->type = CONSTRAINT_HINGE;
  this->__vftable = (idAFConstraint_Hinge_vtbl *)&idAFConstraint_Hinge::`vftable';
  idAtomicString::Set(this: &this->name, str_: name);
  this->body1 = body1;
  this->body2 = body2;
  idAFConstraint::InitSize(this, size: 5);
  fl = this->fl;
  this->coneLimit = nullptr;
  this->steering = nullptr;
  this->fc = nullptr;
  this->friction = 0.0;
  this->fl = (idAFConstraint::constraintFlags_s)(*(_BYTE *)&fl | 0xA0);
  this->initialAxis = body1->clipModel->axis;
  if ( body2 != nullptr )
  {
    clipModel = (float *)body2->clipModel;
    v14 = clipModel[16];
    v15 = clipModel[13];
    v16 = clipModel[18];
    v17 = clipModel[15];
    v18 = clipModel[12];
    v19 = clipModel[17];
    v20 = clipModel[14];
    v21 = clipModel[11];
    v27.mat[2].z = clipModel[19];
    v27.mat[2].y = v14;
    v27.mat[2].x = v15;
    v27.mat[1].z = v16;
    v27.mat[1].y = v17;
    v27.mat[1].x = v18;
    v27.mat[0].z = v19;
    v27.mat[0].y = v20;
    v27.mat[0].x = v21;
    idMat3::operator*=(this: &this->initialAxis, a: &v27);
  }
  return this;
}


// ========================================================================
// __unwind$271737
// EA  : 0x827266D0
// RVA : 0x007266D0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271737()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 192 + 212));
}


// ========================================================================
// ??0idAFConstraint_HingeFriction@@QAA@XZ
// EA  : 0x82726700
// RVA : 0x00726700
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint_HingeFriction *__fastcall idAFConstraint_HingeFriction::idAFConstraint_HingeFriction(
        idAFConstraint_HingeFriction *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idAFConstraint::constraintFlags_s v9; // r5
  int v11; // [sp+8h] [-68h]
  int v12; // [sp+Ch] [-64h]
  int v13; // [sp+10h] [-60h]
  idAFConstraint *v14; // [sp+14h] [-5Ch]

  idAFConstraint::idAFConstraint(this, a2, a3, a4, a5, a6, a7, a8, a9: v11, a10: v12, a11: v13, a12: v14);
  this->type = CONSTRAINT_FRICTION;
  this->__vftable = (idAFConstraint_HingeFriction_vtbl *)&idAFConstraint_HingeFriction::`vftable';
  idAtomicString::Set(this: &this->name, str_: "hingeFriction");
  idAFConstraint::InitSize(this, size: 1);
  v9 = (idAFConstraint::constraintFlags_s)(*(_BYTE *)&this->fl & 0x3F | 0x40);
  this->hinge = nullptr;
  this->fl = v9;
  return this;
}


// ========================================================================
// __unwind$271961
// EA  : 0x82726788
// RVA : 0x00726788
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_271961()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idAFConstraint_Slider@@QAA@PBDPAVidAFBody@@1@Z
// EA  : 0x827267B8
// RVA : 0x007267B8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint_Slider *__fastcall idAFConstraint_Slider::idAFConstraint_Slider(
        idAFConstraint_Slider *this,
        const char *name,
        idAFBody *body1,
        idAFBody *body2,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idClipModel *clipModel; // r11
  float *v13; // r10
  double y; // fp9
  double v15; // fp12
  double v16; // fp8
  double v17; // fp1
  double x; // fp5
  double z; // fp11
  double v20; // fp6
  double v21; // fp3
  double v22; // fp11
  double v23; // fp10
  double v24; // fp9
  double v25; // fp8
  double v26; // fp7
  double v27; // fp6
  double v28; // fp5
  double v29; // fp4
  int v31; // [sp+8h] [-E8h]
  int v32; // [sp+Ch] [-E4h]
  int v33; // [sp+10h] [-E0h]
  idAFConstraint *v34; // [sp+14h] [-DCh]
  idMat3 v35; // [sp+60h] [-90h] BYREF
  idMat3 v36[2]; // [sp+90h] [-60h] BYREF

  idAFConstraint::idAFConstraint(
    this,
    a2: (int)name,
    a3: (int)body1,
    a4: (int)body2,
    a5,
    a6,
    a7,
    a8,
    a9: v31,
    a10: v32,
    a11: v33,
    a12: v34);
  this->type = CONSTRAINT_SLIDER;
  this->__vftable = (idAFConstraint_Slider_vtbl *)&idAFConstraint_Slider::`vftable';
  idAtomicString::Set(this: &this->name, str_: name);
  this->body1 = body1;
  this->body2 = body2;
  idAFConstraint::InitSize(this, size: 5);
  *(_BYTE *)&this->fl |= 0xA0u;
  clipModel = body1->clipModel;
  if ( body2 != nullptr )
  {
    v13 = (float *)body2->clipModel;
    y = clipModel->axis.mat[0].y;
    v15 = (float)(clipModel->origin.y - v13[9]);
    v16 = (float)(clipModel->origin.x - v13[8]);
    v17 = (float)(clipModel->origin.z - v13[10]);
    x = clipModel->axis.mat[0].x;
    z = clipModel->axis.mat[0].z;
    v21 = (float)((float)((float)(clipModel->origin.x - v13[8]) * clipModel->axis.mat[1].x)
                + (float)((float)(clipModel->origin.y - v13[9]) * clipModel->axis.mat[1].y));
    v20 = clipModel->axis.mat[1].z;
    this->offset.z = (float)((float)(clipModel->origin.z - v13[10]) * clipModel->axis.mat[2].z)
                   + (float)((float)((float)(clipModel->origin.x - v13[8]) * clipModel->axis.mat[2].x)
                           + (float)((float)(clipModel->origin.y - v13[9]) * clipModel->axis.mat[2].y));
    this->offset.x = (float)((float)v17 * (float)z)
                   + (float)((float)((float)v16 * (float)x) + (float)((float)v15 * (float)y));
    this->offset.y = (float)((float)v17 * (float)v20) + (float)v21;
    v22 = v13[18];
    v23 = v13[15];
    v24 = v13[12];
    v25 = v13[17];
    v26 = v13[14];
    v27 = v13[11];
    v28 = v13[19];
    v29 = v13[16];
    v35.mat[2].x = v13[13];
    v35.mat[2].y = v29;
    v35.mat[2].z = v28;
    v35.mat[1].z = v22;
    v35.mat[1].y = v23;
    v35.mat[1].x = v24;
    v35.mat[0].z = v25;
    v35.mat[0].y = v26;
    v35.mat[0].x = v27;
    this->relAxis = *idMat3::operator*(this: v36, result: &clipModel->axis, a: &v35);
  }
  else
  {
    this->offset.x = clipModel->origin.x;
    this->offset.y = clipModel->origin.y;
    this->offset.z = clipModel->origin.z;
    this->relAxis.mat[0].x = clipModel->axis.mat[0].x;
    this->relAxis.mat[0].y = clipModel->axis.mat[0].y;
    this->relAxis.mat[0].z = clipModel->axis.mat[0].z;
    this->relAxis.mat[1].x = clipModel->axis.mat[1].x;
    this->relAxis.mat[1].y = clipModel->axis.mat[1].y;
    this->relAxis.mat[1].z = clipModel->axis.mat[1].z;
    this->relAxis.mat[2].x = clipModel->axis.mat[2].x;
    this->relAxis.mat[2].y = clipModel->axis.mat[2].y;
    this->relAxis.mat[2].z = clipModel->axis.mat[2].z;
  }
  return this;
}


// ========================================================================
// __unwind$272103
// EA  : 0x82726A3C
// RVA : 0x00726A3C
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_272103()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 240 + 260));
}


// ========================================================================
// ??0idAFConstraint_Spring@@QAA@PBDPAVidAFBody@@1@Z
// EA  : 0x82726A70
// RVA : 0x00726A70
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint_Spring *__fastcall idAFConstraint_Spring::idAFConstraint_Spring(
        idAFConstraint_Spring *this,
        const char *name,
        idAFBody *body1,
        idAFBody *body2,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int v13; // [sp+8h] [-78h]
  int v14; // [sp+Ch] [-74h]
  int v15; // [sp+10h] [-70h]
  idAFConstraint *v16; // [sp+14h] [-6Ch]

  idAFConstraint::idAFConstraint(
    this,
    a2: (int)name,
    a3: (int)body1,
    a4: (int)body2,
    a5,
    a6,
    a7,
    a8,
    a9: v13,
    a10: v14,
    a11: v15,
    a12: v16);
  this->type = CONSTRAINT_SPRING;
  this->__vftable = (idAFConstraint_Spring_vtbl *)&idAFConstraint_Spring::`vftable';
  idAtomicString::Set(this: &this->name, str_: name);
  this->body1 = body1;
  this->body2 = body2;
  idAFConstraint::InitSize(this, size: 1);
  *(_BYTE *)&this->fl &= ~0x80u;
  this->damping = 1.0;
  this->kcompress = 1.0;
  this->kstretch = 1.0;
  this->restLength = 0.0;
  this->maxLength = 0.0;
  this->minLength = 0.0;
  return this;
}


// ========================================================================
// __unwind$272718
// EA  : 0x82726B0C
// RVA : 0x00726B0C
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_272718()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idAFConstraint_Contact@@QAA@XZ
// EA  : 0x82726B40
// RVA : 0x00726B40
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint_Contact *__fastcall idAFConstraint_Contact::idAFConstraint_Contact(
        idAFConstraint_Contact *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idAFConstraint::constraintFlags_s *p_fl; // r11
  int i; // ctr
  idAFConstraint::constraintFlags_s fl; // r7
  int v13; // [sp+8h] [-68h]
  int v14; // [sp+Ch] [-64h]
  int v15; // [sp+10h] [-60h]
  idAFConstraint *v16; // [sp+14h] [-5Ch]

  idAFConstraint::idAFConstraint(this, a2, a3, a4, a5, a6, a7, a8, a9: v13, a10: v14, a11: v15, a12: v16);
  this->__vftable = (idAFConstraint_Contact_vtbl *)&idAFConstraint_Contact::`vftable';
  idAtomicString::Set(this: &this->name, str_: "contact");
  this->type = CONSTRAINT_CONTACT;
  idAFConstraint::InitSize(this, size: 1);
  p_fl = &this->fl;
  for ( i = 9; i != 0; --i )
  {
    p_fl += 8;
    *(_QWORD *)p_fl = 0x900000000LL;
  }
  *(_DWORD *)&p_fl[8] = 0;
  fl = this->fl;
  this->fc = nullptr;
  this->fl = (idAFConstraint::constraintFlags_s)(*(_BYTE *)&fl & 0x3F | 0x40);
  this->separation = 0.0;
  return this;
}


// ========================================================================
// __unwind$272744
// EA  : 0x82726BEC
// RVA : 0x00726BEC
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_272744()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idAFConstraint_ContactFriction@@QAA@XZ
// EA  : 0x82726C20
// RVA : 0x00726C20
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint_ContactFriction *__fastcall idAFConstraint_ContactFriction::idAFConstraint_ContactFriction(
        idAFConstraint_ContactFriction *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idAFConstraint::constraintFlags_s v9; // r5
  int v11; // [sp+8h] [-68h]
  int v12; // [sp+Ch] [-64h]
  int v13; // [sp+10h] [-60h]
  idAFConstraint *v14; // [sp+14h] [-5Ch]

  idAFConstraint::idAFConstraint(this, a2, a3, a4, a5, a6, a7, a8, a9: v11, a10: v12, a11: v13, a12: v14);
  this->type = CONSTRAINT_FRICTION;
  this->__vftable = (idAFConstraint_ContactFriction_vtbl *)&idAFConstraint_ContactFriction::`vftable';
  idAtomicString::Set(this: &this->name, str_: "contactFriction");
  idAFConstraint::InitSize(this, size: 2);
  v9 = (idAFConstraint::constraintFlags_s)(*(_BYTE *)&this->fl & 0x3F | 0x40);
  this->cc = nullptr;
  this->fl = v9;
  return this;
}


// ========================================================================
// __unwind$272765
// EA  : 0x82726CA8
// RVA : 0x00726CA8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_272765()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 112 + 132));
}


// ========================================================================
// ?Add@idAFConstraint_ContactFriction@@QAA_NPAVidPhysics_AF@@M@Z
// EA  : 0x82726CD0
// RVA : 0x00726CD0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

int __fastcall idAFConstraint_ContactFriction::Add(
        idAFConstraint_ContactFriction *this,
        idPhysics_AF *phys,
        double invTimeStep)
{
  idAFBody *body1; // r11
  double contactFriction; // fp31
  double v7; // fp27
  char FrictionDirection; // r3
  idAFConstraint_Contact *cc; // r30
  double v10; // fp11
  double v11; // fp9
  idSpatialMat *p_J1; // r29
  idClipModel *clipModel; // r11
  double v14; // fp31
  double v15; // fp30
  double v16; // fp29
  idStaticSpatialVec *p_c1; // r27
  float *mat; // r11
  double y; // fp0
  double z; // fp13
  double v21; // fp11
  double v22; // fp9
  double v23; // fp31
  idAFBody *body2; // r11
  float *v25; // r11
  idAFConstraint_Contact *v26; // r10
  double v27; // fp30
  double v28; // fp29
  double v29; // fp28
  float *v30; // r11
  double v31; // fp4
  double v32; // fp3
  double v33; // fp11
  double v34; // fp13
  float *v35; // r11
  double v36; // fp12
  double v37; // fp0
  idAFConstraint_Contact *v38; // r7
  idClipModel *v39; // r11
  double v40; // fp31
  double v41; // fp26
  double v42; // fp25
  double v43; // fp30
  double v44; // fp8
  double v45; // fp29
  double x; // fp28
  double v47; // fp7
  double v48; // fp6
  double v49; // fp5
  float *v50; // r11
  double v51; // fp13
  double v52; // fp12
  double v53; // fp11
  double v54; // fp8
  float *v55; // r11
  float *v56; // r11
  idAFBody *v57; // r11
  float *v58; // r11
  idAFConstraint_Contact *v59; // r10
  double v60; // fp26
  double v61; // fp25
  double v62; // fp24
  float *v63; // r11
  double v64; // fp11
  double v65; // fp12
  double v66; // fp11
  float *v67; // r11
  double v68; // fp0
  double v69; // fp13
  float *v70; // r11
  float *v71; // r11
  idAFBody *v72; // r8
  double v73; // fp0
  double v74; // fp13
  idAFConstraint_Contact *v75; // r6
  idAFBody *v76; // r26
  idAFConstraint_Contact *v77; // r30
  double v78; // fp11
  double v79; // fp9
  float *v80; // r11
  int numRows; // r28
  idSpatialMat *v82; // r3
  int v83; // r29
  double v84; // fp30
  double v85; // fp29
  double v86; // fp28
  int v87; // r30
  float *v88; // r11
  double v89; // fp11
  double v90; // fp10
  double v91; // fp5
  double v92; // fp4
  double v93; // fp7
  float *v94; // r11
  int v95; // r27
  idAFBody *v96; // r11
  float *v97; // r11
  idAFConstraint_Contact *v98; // r10
  double v99; // fp30
  double v100; // fp29
  double v101; // fp28
  float *v102; // r11
  double v103; // fp6
  double v104; // fp4
  double v105; // fp11
  double v106; // fp13
  double v107; // fp12
  float *v108; // r11
  idVec3 v109; // [sp+50h] [-A0h] BYREF
  idVec3 v110; // [sp+60h] [-90h] BYREF

  body1 = this->body1;
  this->physics = phys;
  if ( body1 == nullptr || phys == nullptr || this->cc == nullptr )
    return 0;
  contactFriction = body1->contactFriction;
  v7 = (float)(idPhysics_AF::GetContactFrictionScale(this: phys) * (float)contactFriction);
  FrictionDirection = idAFBody::GetFrictionDirection(this: this->body1, dir: &v109);
  cc = this->cc;
  if ( FrictionDirection != 0 )
  {
    v10 = (float)(cc->contact.normal.z
                * (float)((float)(cc->contact.normal.x * v109.x)
                        + (float)((float)(cc->contact.normal.y * v109.y) + (float)(cc->contact.normal.z * v109.z))));
    v11 = (float)(v109.y
                - (float)(cc->contact.normal.y
                        * (float)((float)(cc->contact.normal.x * v109.x)
                                + (float)((float)(cc->contact.normal.y * v109.y) + (float)(cc->contact.normal.z * v109.z)))));
    v109.x = v109.x
           - (float)((float)((float)(cc->contact.normal.x * v109.x)
                           + (float)((float)(cc->contact.normal.y * v109.y) + (float)(cc->contact.normal.z * v109.z)))
                   * cc->contact.normal.x);
    v109.y = v11;
    v109.z = v109.z - (float)v10;
    idVec3::NormalizeFast(this: &v109);
    p_J1 = &this->J1;
    clipModel = this->body1->clipModel;
    v14 = (float)(cc->contact.point.x - clipModel->origin.x);
    v15 = (float)(cc->contact.point.y - clipModel->origin.y);
    v16 = (float)(cc->contact.point.z - clipModel->origin.z);
    idSpatialMat::SetSize(this: &this->J1, rows: 1, columns: 6);
    p_c1 = &this->c1;
    *(idVec3 *)this->J1.mat = v109;
    mat = this->J1.mat;
    y = v109.y;
    z = v109.z;
    v21 = (float)((float)v16 * v109.y);
    v22 = (float)((float)v15 * v109.x);
    mat[4] = (float)((float)v16 * v109.x) - (float)(v109.z * (float)v14);
    mat[3] = (float)((float)v15 * (float)z) - (float)v21;
    mat[5] = (float)((float)y * (float)v14) - (float)v22;
    idSpatialVec::SetSize(this: &this->c1, newSize: 1);
    v23 = 0.0;
    *this->c1.p = 0.0;
    body2 = this->body2;
    if ( body2 != nullptr )
    {
      v25 = (float *)body2->clipModel;
      v26 = this->cc;
      v27 = (float)(v26->contact.point.x - v25[8]);
      v28 = (float)(v26->contact.point.y - v25[9]);
      v29 = (float)(v26->contact.point.z - v25[10]);
      idSpatialMat::SetSize(this: &this->J2, rows: 1, columns: 6);
      v30 = this->J2.mat;
      v31 = -v109.y;
      v32 = -v109.z;
      *v30 = -v109.x;
      v30[1] = v31;
      v30[2] = v32;
      v33 = -v109.z;
      v34 = -v109.y;
      v35 = this->J2.mat;
      v36 = -v109.x;
      v35[4] = (float)((float)v29 * (float)v36) - (float)((float)v33 * (float)v27);
      v35[3] = (float)((float)v33 * (float)v28) - (float)((float)v34 * (float)v29);
      v35[5] = (float)((float)v34 * (float)v27) - (float)((float)v28 * (float)v36);
      idSpatialVec::SetSize(this: &this->c2, newSize: 1);
      *this->c2.p = 0.0;
    }
    v37 = BOX_SCALE_MAX;
    *this->lo.p = -BOX_SCALE_MAX;
    *this->hi.p = v37;
    v38 = this->cc;
    this->boxScale[0] = v7;
    this->boxConstraint = v38;
    this->boxIndex[0] = 0;
  }
  else
  {
    idVec3::NormalVectors(this: &cc->contact.normal, left: &v109, down: &v110);
    p_J1 = &this->J1;
    v39 = this->body1->clipModel;
    v40 = (float)(cc->contact.point.x - v39->origin.x);
    v41 = (float)(cc->contact.point.y - v39->origin.y);
    v42 = (float)(cc->contact.point.z - v39->origin.z);
    idSpatialMat::SetSize(this: &this->J1, rows: 2, columns: 6);
    v43 = v110.y;
    p_c1 = &this->c1;
    v44 = (float)(v110.y * (float)v42);
    v45 = v110.z;
    x = v110.x;
    v47 = (float)(v110.z * (float)v40);
    v48 = (float)((float)v41 * v110.x);
    *(idVec3 *)this->J1.mat = v109;
    v49 = (float)((float)((float)v45 * (float)v41) - (float)v44);
    v50 = this->J1.mat;
    v51 = v109.z;
    v52 = v109.x;
    v53 = (float)((float)v42 * v109.y);
    v54 = (float)(v109.z * (float)v40);
    v50[5] = (float)(v109.y * (float)v40) - (float)((float)v41 * v109.x);
    v50[3] = (float)((float)v41 * (float)v51) - (float)v53;
    v50[4] = (float)((float)v42 * (float)v52) - (float)v54;
    v55 = this->J1.mat;
    v55[8] = x;
    v55[9] = v43;
    v55[10] = v45;
    v56 = this->J1.mat;
    v56[11] = v49;
    v56[12] = (float)((float)v42 * (float)x) - (float)v47;
    v56[13] = (float)((float)v43 * (float)v40) - (float)v48;
    idSpatialVec::SetSize(this: &this->c1, newSize: 2);
    v23 = 0.0;
    this->c1.p[1] = 0.0;
    *this->c1.p = 0.0;
    v57 = this->body2;
    if ( v57 != nullptr )
    {
      v58 = (float *)v57->clipModel;
      v59 = this->cc;
      v60 = (float)(v59->contact.point.x - v58[8]);
      v61 = (float)(v59->contact.point.y - v58[9]);
      v62 = (float)(v59->contact.point.z - v58[10]);
      idSpatialMat::SetSize(this: &this->J2, rows: 2, columns: 6);
      v63 = this->J2.mat;
      v64 = -v109.y;
      v65 = -v109.x;
      v63[2] = -v109.z;
      v63[1] = v64;
      *v63 = v65;
      v66 = -v109.x;
      v67 = this->J2.mat;
      v68 = -v109.y;
      v69 = -v109.z;
      v67[5] = (float)((float)v68 * (float)v60) - (float)((float)v61 * (float)v66);
      v67[3] = (float)((float)v69 * (float)v61) - (float)((float)v68 * (float)v62);
      v67[4] = (float)((float)v62 * (float)v66) - (float)((float)v69 * (float)v60);
      v70 = this->J2.mat;
      v70[8] = -x;
      v70[9] = -v43;
      v70[10] = -v45;
      v71 = this->J2.mat;
      v71[11] = (float)((float)-v45 * (float)v61) - (float)((float)-v43 * (float)v62);
      v71[12] = (float)((float)v62 * (float)-x) - (float)((float)-v45 * (float)v60);
      v71[13] = (float)((float)-v43 * (float)v60) - (float)((float)v61 * (float)-x);
      idSpatialVec::SetSize(this: &this->c2, newSize: 2);
      this->c2.p[1] = 0.0;
      *this->c2.p = 0.0;
      v72 = this->body2;
      if ( v72->contactFriction < v7 )
        v7 = v72->contactFriction;
    }
    v73 = BOX_SCALE_MAX;
    v74 = -BOX_SCALE_MAX;
    *this->lo.p = v74;
    *this->hi.p = v73;
    v75 = this->cc;
    this->boxScale[0] = v7;
    this->boxIndex[0] = 0;
    this->boxConstraint = v75;
    this->lo.p[1] = v74;
    this->hi.p[1] = v73;
    this->boxIndex[1] = 0;
    this->boxScale[1] = v7;
  }
  if ( (unsigned __int8)idAFBody::GetContactMotorDirection(this: this->body1, dir: &v109) != 0 )
  {
    v76 = this->body1;
    if ( v76->contactMotorForce > v23 )
    {
      v77 = this->cc;
      v78 = (float)(v77->contact.normal.z
                  * (float)((float)(v77->contact.normal.x * v109.x)
                          + (float)((float)(v77->contact.normal.y * v109.y) + (float)(v77->contact.normal.z * v109.z))));
      v79 = (float)(v109.y
                  - (float)(v77->contact.normal.y
                          * (float)((float)(v77->contact.normal.x * v109.x)
                                  + (float)((float)(v77->contact.normal.y * v109.y)
                                          + (float)(v77->contact.normal.z * v109.z)))));
      v109.x = v109.x
             - (float)(v77->contact.normal.x
                     * (float)((float)(v77->contact.normal.x * v109.x)
                             + (float)((float)(v77->contact.normal.y * v109.y) + (float)(v77->contact.normal.z * v109.z))));
      v109.y = v79;
      v109.z = v109.z - (float)v78;
      idVec3::NormalizeFast(this: &v109);
      v80 = (float *)v76->clipModel;
      numRows = p_J1->numRows;
      v82 = p_J1;
      v83 = p_J1->numRows + 1;
      v84 = (float)(v77->contact.point.x - v80[8]);
      v85 = (float)(v77->contact.point.y - v80[9]);
      v86 = (float)(v77->contact.point.z - v80[10]);
      idSpatialMat::ChangeNumRows(this: v82, rows: v83);
      v87 = 8 * numRows;
      v88 = &this->J1.mat[8 * numRows];
      v89 = -v109.z;
      v90 = -v109.x;
      v88[1] = -v109.y;
      v88[2] = v89;
      *v88 = v90;
      v91 = -v109.x;
      v92 = -v109.y;
      v93 = -v109.z;
      v94 = &this->J1.mat[8 * numRows];
      v94[5] = (float)((float)v92 * (float)v84) - (float)((float)v85 * (float)v91);
      v94[4] = (float)((float)v86 * (float)v91) - (float)((float)v93 * (float)v84);
      v94[3] = (float)((float)v93 * (float)v85) - (float)((float)v92 * (float)v86);
      idSpatialVec::ChangeSize(this: p_c1, newSize: v83);
      v95 = numRows;
      this->c1.p[numRows] = this->body1->contactMotorVelocity;
      v96 = this->body2;
      if ( v96 != nullptr )
      {
        v97 = (float *)v96->clipModel;
        v98 = this->cc;
        v99 = (float)(v98->contact.point.x - v97[8]);
        v100 = (float)(v98->contact.point.y - v97[9]);
        v101 = (float)(v98->contact.point.z - v97[10]);
        idSpatialMat::ChangeNumRows(this: &this->J2, rows: v83);
        v102 = &this->J2.mat[v87];
        v103 = -v109.y;
        v104 = -v109.z;
        *v102 = -v109.x;
        v102[1] = v103;
        v102[2] = v104;
        v105 = -v109.z;
        v106 = -v109.y;
        v107 = -v109.x;
        v108 = &this->J2.mat[v87];
        v108[4] = (float)((float)v101 * (float)v107) - (float)((float)v105 * (float)v99);
        v108[3] = (float)((float)v105 * (float)v100) - (float)((float)v106 * (float)v101);
        v108[5] = (float)((float)v106 * (float)v99) - (float)((float)v100 * (float)v107);
        idSpatialVec::ChangeSize(this: &this->c2, newSize: v83);
        this->c2.p[numRows] = v23;
      }
      this->lo.p[v95] = -this->body1->contactMotorForce;
      this->hi.p[v95] = this->body1->contactMotorForce;
      this->boxIndex[numRows] = -1;
      this->boxScale[numRows] = v23;
    }
  }
  idPhysics_AF::AddFrameConstraint(this: this->physics, constraint: this);
  return 1;
}


// ========================================================================
// ??0idAFConstraint_ConeLimit@@QAA@XZ
// EA  : 0x82727478
// RVA : 0x00727478
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint_ConeLimit *__fastcall idAFConstraint_ConeLimit::idAFConstraint_ConeLimit(
        idAFConstraint_ConeLimit *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+10h] [-60h]
  idAFConstraint *v13; // [sp+14h] [-5Ch]

  idAFConstraint::idAFConstraint(this, a2, a3, a4, a5, a6, a7, a8, a9: v10, a10: v11, a11: v12, a12: v13);
  this->type = CONSTRAINT_CONELIMIT;
  this->__vftable = (idAFConstraint_ConeLimit_vtbl *)&idAFConstraint_ConeLimit::`vftable';
  idAtomicString::Set(this: &this->name, str_: "coneLimit");
  idAFConstraint::InitSize(this, size: 1);
  this->fl = (idAFConstraint::constraintFlags_s)(*(_BYTE *)&this->fl & 0x3F | 0x40);
  this->coneAnchor.z = 0.0;
  this->coneAnchor.y = 0.0;
  this->coneAnchor.x = 0.0;
  this->coneAxis.z = 0.0;
  this->coneAxis.y = 0.0;
  this->coneAxis.x = 0.0;
  this->body1Axis.z = 0.0;
  this->body1Axis.y = 0.0;
  this->body1Axis.x = 0.0;
  this->cosAngle = 0.0;
  this->sinHalfAngle = 0.0;
  this->cosHalfAngle = 0.0;
  this->epsilon = af_lcpEpsilon.valueFloat;
  return this;
}


// ========================================================================
// __unwind$273507
// EA  : 0x82727558
// RVA : 0x00727558
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_273507()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idAFConstraint_PyramidLimit@@QAA@XZ
// EA  : 0x82727588
// RVA : 0x00727588
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint_PyramidLimit *__fastcall idAFConstraint_PyramidLimit::idAFConstraint_PyramidLimit(
        idAFConstraint_PyramidLimit *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+10h] [-60h]
  idAFConstraint *v13; // [sp+14h] [-5Ch]

  idAFConstraint::idAFConstraint(this, a2, a3, a4, a5, a6, a7, a8, a9: v10, a10: v11, a11: v12, a12: v13);
  this->type = CONSTRAINT_PYRAMIDLIMIT;
  this->__vftable = (idAFConstraint_PyramidLimit_vtbl *)&idAFConstraint_PyramidLimit::`vftable';
  idAtomicString::Set(this: &this->name, str_: "pyramidLimit");
  idAFConstraint::InitSize(this, size: 1);
  this->fl = (idAFConstraint::constraintFlags_s)(*(_BYTE *)&this->fl & 0x3F | 0x40);
  this->pyramidAnchor.z = 0.0;
  this->pyramidAnchor.y = 0.0;
  this->pyramidAnchor.x = 0.0;
  this->pyramidBasis.mat[2].z = 1.0;
  this->pyramidBasis.mat[1].y = 1.0;
  this->pyramidBasis.mat[0].x = 1.0;
  this->pyramidBasis.mat[1].z = 0.0;
  this->pyramidBasis.mat[0].z = 0.0;
  this->pyramidBasis.mat[0].y = 0.0;
  this->pyramidBasis.mat[2].y = 0.0;
  this->pyramidBasis.mat[2].x = 0.0;
  this->pyramidBasis.mat[1].x = 0.0;
  this->body1Axis.z = 0.0;
  this->body1Axis.y = 0.0;
  this->body1Axis.x = 0.0;
  this->cosAngle[0] = 0.0;
  this->cosAngle[1] = 0.0;
  this->sinHalfAngle[0] = 0.0;
  this->sinHalfAngle[1] = 0.0;
  this->cosHalfAngle[0] = 0.0;
  this->cosHalfAngle[1] = 0.0;
  this->epsilon = af_lcpEpsilon.valueFloat;
  return this;
}


// ========================================================================
// __unwind$273569
// EA  : 0x82727694
// RVA : 0x00727694
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_273569()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idAFConstraint_Suspension@@QAA@XZ
// EA  : 0x827276C8
// RVA : 0x007276C8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

idAFConstraint_Suspension *__fastcall idAFConstraint_Suspension::idAFConstraint_Suspension(
        idAFConstraint_Suspension *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  unsigned __int64 v8; // r29
  int v11; // [sp+8h] [-78h]
  int v12; // [sp+Ch] [-74h]
  int v13; // [sp+10h] [-70h]
  idAFConstraint *v14; // [sp+14h] [-6Ch]

  idAFConstraint::idAFConstraint(this, a2, a3, a4, a5, a6, a7, a8, a9: v11, a10: v12, a11: v13, a12: v14);
  LODWORD(v8) = 0;
  this->__vftable = (idAFConstraint_Suspension_vtbl *)&idAFConstraint_Suspension::`vftable';
  this->traceQuery.index = v8;
  this->type = CONSTRAINT_SUSPENSION;
  idAtomicString::Set(this: &this->name, str_: "suspension");
  idAFConstraint::InitSize(this, size: 3);
  this->fl = (idAFConstraint::constraintFlags_s)(*(_BYTE *)&this->fl & 0x3F | 0x40);
  this->localOrigin.z = 0.0;
  this->localOrigin.y = 0.0;
  this->localOrigin.x = 0.0;
  this->friction_lateral = nullptr;
  this->friction_longitudinal = nullptr;
  this->suspensionUp = 0.0;
  this->clip = nullptr;
  this->suspensionDown = 0.0;
  this->wheelModel = nullptr;
  this->suspensionCompress = 0.0;
  this->motorEnabled = false;
  this->suspensionDamping = 0.0;
  this->frictionLatMultiplier = 1.0;
  this->frictionLongMultiplier = 1.0;
  this->steerAngle = 0.0;
  this->motorForce = 0.0;
  this->motorVelocity = 0.0;
  this->traceFraction = 1.0;
  this->traceEndPos.z = 0.0;
  this->traceEndPos.y = 0.0;
  this->traceEndPos.x = 0.0;
  this->traceNormal.z = 0.0;
  this->traceNormal.y = 0.0;
  this->traceNormal.x = 0.0;
  this->tracePoint.z = 0.0;
  this->tracePoint.y = 0.0;
  this->tracePoint.x = 0.0;
  this->traceSurfaceFlags = 0;
  this->wheelVelocity = 0.0;
  this->traceEntityNum = 0x1FFF;
  this->wheelAngle = 0.0;
  this->limitLateralGrip = false;
  this->lastWheelHeight = 0.0;
  this->clipMask = 0;
  this->lastMotorVelocity = 0.0;
  this->lastOnGround = false;
  this->lastTorque = 0.0;
  this->lastGrip = 0.0;
  this->wheelRadius = 0.0;
  this->lateralSlip = 0.0;
  this->longitudinalSlip = 0.0;
  this->debugSpringForce = 0.0;
  this->debugf1 = 0.0;
  this->debugf2 = 0.0;
  this->debugf3 = 0.0;
  this->debugf4 = 0.0;
  return this;
}


// ========================================================================
// __unwind$273885
// EA  : 0x8272782C
// RVA : 0x0072782C
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_273885()
{
  int v0; // r12

  idAFConstraint::~idAFConstraint(this: *(idAFConstraint **)(v0 - 128 + 148));
}


// ========================================================================
// ?SetConeLimit@idAFConstraint_BallAndSocketJoint@@QAAXABVidVec3@@M0@Z
// EA  : 0x82727860
// RVA : 0x00727860
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_BallAndSocketJoint::SetConeLimit(
        idAFConstraint_BallAndSocketJoint *this,
        const idVec3 *coneAxis,
        double coneAngle,
        const idVec3 *body1Axis,
        float *a5,
        int a6,
        const idVec3 *a7)
{
  idAFConstraint_PyramidLimit *pyramidLimit; // r3
  int v12; // r10
  int v13; // r9
  int v14; // r7
  int v15; // r6
  int v16; // r5
  int v17; // r4
  idAFConstraint_ConeLimit *v18; // r3
  idAFConstraint_ConeLimit *v19; // r3
  idPhysics_AF *physics; // r11
  idAFBody *body2; // r5
  idAFBody *body1; // r4
  idAFConstraint_ConeLimit *coneLimit; // r3
  float *clipModel; // r11
  double y; // fp13
  float *v26; // r10
  const idVec3 *v27; // r7
  double z; // fp10
  double v29; // fp1
  double v30; // fp4
  double v31; // fp9
  double v32; // fp3
  double v33; // fp12
  double v34; // fp0
  double v35; // fp8
  double v36; // fp30
  double v37; // fp5
  double v38; // fp11
  double v39; // fp2
  double v40; // fp31
  float *v41; // r11
  double v42; // fp13
  double v43; // fp12
  double v44; // fp11
  double v45; // fp10
  double v46; // fp9
  double v47; // fp7
  float v48[4]; // [sp+58h] [-68h] BYREF
  float v49[12]; // [sp+68h] [-58h] BYREF

  if ( this->body1 != nullptr )
  {
    pyramidLimit = this->pyramidLimit;
    if ( pyramidLimit != nullptr )
    {
      ((void (__fastcall *)(idAFConstraint_PyramidLimit *, int))pyramidLimit->dtr_idAFConstraint)(
        a1: pyramidLimit,
        a2: 1);
      this->pyramidLimit = nullptr;
    }
    if ( this->coneLimit == nullptr )
    {
      v18 = (idAFConstraint_ConeLimit *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                          size: 0x210u,
                                          tag: TAG_AF,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
      if ( v18 != nullptr )
        v19 = idAFConstraint_ConeLimit::idAFConstraint_ConeLimit(
                this: v18,
                a2: v17,
                a3: v16,
                a4: v15,
                a5: v14,
                a6: (int)a7,
                a7: v13,
                a8: v12);
      else
        v19 = nullptr;
      physics = this->physics;
      this->coneLimit = v19;
      v19->physics = physics;
    }
    body2 = this->body2;
    body1 = this->body1;
    coneLimit = this->coneLimit;
    if ( body2 != nullptr )
    {
      clipModel = (float *)body2->clipModel;
      y = coneAxis->y;
      v26 = (float *)body1->clipModel;
      v27 = (const idVec3 *)v48;
      z = coneAxis->z;
      v29 = coneAngle;
      v30 = (float)((float)(coneAxis->x * clipModel[11]) + (float)(coneAxis->y * clipModel[12]));
      v31 = a5[2];
      v32 = (float)((float)(coneAxis->z * clipModel[16]) + (float)(coneAxis->x * clipModel[14]));
      v33 = v26[19];
      v34 = (float)((float)(*a5 * v26[17]) + (float)(a5[1] * v26[18]));
      v35 = (float)((float)(*a5 * v26[14]) + (float)(a5[1] * v26[15]));
      v36 = clipModel[13];
      v37 = (float)((float)(*a5 * v26[11]) + (float)(a5[1] * v26[12]));
      v38 = clipModel[15];
      v39 = v26[16];
      v40 = v26[13];
      v48[2] = (float)(coneAxis->z * clipModel[19])
             + (float)((float)(coneAxis->x * clipModel[17]) + (float)(coneAxis->y * clipModel[18]));
      v48[0] = (float)((float)z * (float)v36) + (float)v30;
      v48[1] = (float)((float)y * (float)v38) + (float)v32;
      v49[2] = (float)((float)v31 * (float)v33) + (float)v34;
      v49[1] = (float)((float)v31 * (float)v39) + (float)v35;
      v49[0] = (float)((float)v31 * (float)v40) + (float)v37;
    }
    else
    {
      v41 = (float *)body1->clipModel;
      v42 = a5[1];
      v27 = coneAxis;
      v43 = *a5;
      body2 = nullptr;
      v29 = coneAngle;
      v44 = v41[15];
      v45 = v41[17];
      v46 = (float)((float)(a5[1] * v41[18]) + (float)(a5[2] * v41[19]));
      v47 = (float)((float)(a5[2] * v41[16]) + (float)(*a5 * v41[14]));
      v49[0] = (float)(a5[2] * v41[13]) + (float)((float)(*a5 * v41[11]) + (float)(a5[1] * v41[12]));
      v49[2] = (float)((float)v43 * (float)v45) + (float)v46;
      v49[1] = (float)((float)v42 * (float)v44) + (float)v47;
    }
    idAFConstraint_ConeLimit::Setup(
      this: coneLimit,
      b1: body1,
      b2: body2,
      coneAnchor: &this->anchor2,
      coneAxis: v27,
      coneAngle: v29,
      body1Axis: a7,
      a8: v49);
  }
}


// ========================================================================
// __unwind$273980
// EA  : 0x82727A8C
// RVA : 0x00727A8C
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_273980()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 80), tag: TAG_AF);
}


// ========================================================================
// ?SetPyramidLimit@idAFConstraint_BallAndSocketJoint@@QAAXABVidVec3@@0MM0@Z
// EA  : 0x82727AC0
// RVA : 0x00727AC0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_BallAndSocketJoint::SetPyramidLimit(
        idAFConstraint_BallAndSocketJoint *this,
        const idVec3 *pyramidAxis,
        const idVec3 *baseAxis,
        double angle1,
        double angle2,
        const idVec3 *body1Axis,
        int a7,
        float *a8,
        const idVec3 *a9)
{
  idAFConstraint_ConeLimit *coneLimit; // r3
  int v16; // r10
  int v17; // r8
  int v18; // r7
  int v19; // r6
  int v20; // r5
  int v21; // r4
  idAFConstraint_PyramidLimit *v22; // r3
  idAFConstraint_PyramidLimit *v23; // r3
  idPhysics_AF *physics; // r11
  idAFBody *body1; // r4
  idAFBody *body2; // r5
  double v27; // fp0
  double v28; // fp13
  idAFConstraint_PyramidLimit *pyramidLimit; // r3
  float *clipModel; // r10
  double y; // fp12
  double v32; // fp29
  float *p_axis; // r11
  double z; // fp28
  double x; // fp10
  double v36; // fp9
  double v37; // fp2
  double v38; // fp6
  double v39; // fp8
  double v40; // fp27
  double v41; // fp5
  double v42; // fp0
  double v43; // fp11
  double v44; // fp3
  double v45; // fp1
  double v46; // fp6
  double v47; // fp5
  double v48; // fp13
  double v49; // fp10
  double v50; // fp26
  double v51; // fp12
  double v52; // fp11
  double v53; // fp8
  float *v54; // r11
  double v55; // fp11
  double v56; // fp12
  double v57; // fp10
  int v58; // [sp+8h] [-F8h]
  int v59; // [sp+Ch] [-F4h]
  int v60; // [sp+10h] [-F0h]
  int v61; // [sp+14h] [-ECh]
  int v62; // [sp+18h] [-E8h]
  int v63; // [sp+1Ch] [-E4h]
  int v64; // [sp+20h] [-E0h]
  int v65; // [sp+24h] [-DCh]
  int v66; // [sp+28h] [-D8h]
  int v67; // [sp+2Ch] [-D4h]
  int v68; // [sp+30h] [-D0h]
  int v69; // [sp+34h] [-CCh]
  int v70; // [sp+38h] [-C8h]
  int v71; // [sp+3Ch] [-C4h]
  int v72; // [sp+40h] [-C0h]
  int v73; // [sp+44h] [-BCh]
  int v74; // [sp+48h] [-B8h]
  int v75; // [sp+4Ch] [-B4h]
  int v76; // [sp+50h] [-B0h]
  idVec3 v77; // [sp+68h] [-98h] BYREF
  idVec3 v78; // [sp+78h] [-88h] BYREF
  idVec3 v79[6]; // [sp+88h] [-78h] BYREF

  coneLimit = this->coneLimit;
  if ( coneLimit != nullptr )
  {
    ((void (__fastcall *)(idAFConstraint_ConeLimit *, int))coneLimit->dtr_idAFConstraint)(a1: coneLimit, a2: 1);
    a9 = nullptr;
    this->coneLimit = nullptr;
  }
  if ( this->pyramidLimit == nullptr )
  {
    v22 = (idAFConstraint_PyramidLimit *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                           size: 0x230u,
                                           tag: TAG_AF,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
    if ( v22 != nullptr )
      v23 = idAFConstraint_PyramidLimit::idAFConstraint_PyramidLimit(
              this: v22,
              a2: v21,
              a3: v20,
              a4: v19,
              a5: v18,
              a6: v17,
              a7: (int)a9,
              a8: v16);
    else
      v23 = nullptr;
    physics = this->physics;
    this->pyramidLimit = v23;
    v23->physics = physics;
  }
  body1 = this->body1;
  if ( body1 != nullptr )
  {
    body2 = this->body2;
    v27 = a8[2];
    v28 = *a8;
    pyramidLimit = this->pyramidLimit;
    if ( body2 != nullptr )
    {
      clipModel = (float *)body1->clipModel;
      y = baseAxis->y;
      v32 = a8[1];
      p_axis = (float *)&body2->clipModel->axis;
      z = baseAxis->z;
      x = pyramidAxis->x;
      v36 = pyramidAxis->y;
      v37 = (float)((float)(a8[2] * clipModel[13]) + (float)(*a8 * clipModel[11]));
      v38 = (float)((float)(a8[1] * clipModel[18]) + (float)(a8[2] * clipModel[19]));
      v39 = (float)((float)(baseAxis->x * body2->clipModel->axis.mat[2].x)
                  + (float)(baseAxis->y * body2->clipModel->axis.mat[2].y));
      v40 = pyramidAxis->z;
      v41 = (float)((float)(baseAxis->x * *p_axis) + (float)(baseAxis->y * body2->clipModel->axis.mat[0].y));
      v43 = (float)((float)(baseAxis->z * body2->clipModel->axis.mat[1].z)
                  + (float)(baseAxis->x * body2->clipModel->axis.mat[1].x));
      v42 = body2->clipModel->axis.mat[2].y;
      v44 = (float)((float)(pyramidAxis->z * body2->clipModel->axis.mat[1].z)
                  + (float)(pyramidAxis->x * body2->clipModel->axis.mat[1].x));
      v45 = (float)((float)(pyramidAxis->x * *p_axis) + (float)(pyramidAxis->y * body2->clipModel->axis.mat[0].y));
      v77.y = (float)(*a8 * clipModel[14]) + (float)((float)(a8[1] * clipModel[15]) + (float)(a8[2] * clipModel[16]));
      v46 = (float)((float)((float)v28 * clipModel[17]) + (float)v38);
      v47 = (float)((float)((float)z * p_axis[2]) + (float)v41);
      v48 = p_axis[4];
      v49 = (float)((float)((float)x * p_axis[6]) + (float)((float)v36 * (float)v42));
      v50 = p_axis[8];
      v51 = (float)((float)((float)y * p_axis[4]) + (float)v43);
      v52 = p_axis[2];
      v53 = (float)((float)((float)z * p_axis[8]) + (float)v39);
      v77.x = (float)((float)v32 * clipModel[12]) + (float)v37;
      v78.y = v51;
      v77.z = v46;
      v78.x = v47;
      v78.z = v53;
      v79[0].y = (float)((float)v36 * (float)v48) + (float)v44;
      v79[0].x = (float)((float)v40 * (float)v52) + (float)v45;
      v79[0].z = (float)((float)v40 * (float)v50) + (float)v49;
      idAFConstraint_PyramidLimit::Setup(
        this: pyramidLimit,
        b1: body1,
        b2: body2,
        pyramidAnchor: &this->anchor2,
        pyramidAxis: v79,
        baseAxis: &v78,
        pyramidAngle1: angle1,
        pyramidAngle2: angle2,
        body1Axis: &v77,
        a10: (int)clipModel,
        a11: v58,
        a12: v59,
        a13: v60,
        a14: v61,
        a15: v62,
        a16: v63,
        a17: v64,
        a18: v65,
        a19: v66,
        a20: v67,
        a21: v68,
        a22: v69,
        a23: v70,
        a24: v71,
        a25: v72,
        a26: v73,
        a27: v74,
        a28: v75,
        a29: v76,
        a30: &v77);
    }
    else
    {
      v54 = (float *)body1->clipModel;
      v55 = v54[16];
      v57 = (float)((float)(*a8 * v54[17]) + (float)((float)(a8[1] * v54[18]) + (float)(a8[2] * v54[19])));
      v56 = (float)((float)(a8[1] * v54[15]) + (float)(*a8 * v54[14]));
      v79[0].x = (float)(*a8 * v54[11]) + (float)((float)(a8[1] * v54[12]) + (float)(a8[2] * v54[13]));
      v79[0].z = v57;
      v79[0].y = (float)((float)v27 * (float)v55) + (float)v56;
      idAFConstraint_PyramidLimit::Setup(
        this: pyramidLimit,
        b1: body1,
        b2: nullptr,
        pyramidAnchor: &this->anchor2,
        pyramidAxis,
        baseAxis,
        pyramidAngle1: angle1,
        pyramidAngle2: angle2,
        body1Axis: a9,
        a10: (int)v79,
        a11: v58,
        a12: v59,
        a13: v60,
        a14: v61,
        a15: v62,
        a16: v63,
        a17: v64,
        a18: v65,
        a19: v66,
        a20: v67,
        a21: v68,
        a22: v69,
        a23: v70,
        a24: v71,
        a25: v72,
        a26: v73,
        a27: v74,
        a28: v75,
        a29: v76,
        a30: v79);
    }
  }
}


// ========================================================================
// __unwind$274555
// EA  : 0x82727D78
// RVA : 0x00727D78
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_274555()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 96), tag: TAG_AF);
}


// ========================================================================
// ?ApplyFriction@idAFConstraint_BallAndSocketJoint@@MAAXM@Z
// EA  : 0x82727DB0
// RVA : 0x00727DB0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_BallAndSocketJoint::ApplyFriction(
        idAFConstraint_BallAndSocketJoint *this,
        double invTimeStep)
{
  double Friction; // fp1
  idAFBody *body1; // r11
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r7
  int v10; // r6
  int v11; // r5
  int v12; // r4
  idAFConstraint_BallAndSocketJointFriction *v13; // r3
  idAFConstraint_BallAndSocketJointFriction *v14; // r3
  double invMass; // fp0
  float *v16; // r11
  idAFBody *body2; // r10
  double v18; // fp10
  double v19; // fp13
  double v20; // fp12
  double v21; // fp11
  double v22; // fp10
  double v23; // fp8
  double v24; // fp7
  double v25; // fp13
  double v26; // fp12
  double v27; // fp11
  idAFBody *v28; // r11
  double v29; // fp9
  double v30; // fp8
  double v31; // fp7
  double v32; // fp6

  Friction = idAFConstraint_BallAndSocketJoint::GetFriction(this);
  if ( Friction > 0.0 )
  {
    body1 = this->body1;
    if ( body1 != nullptr )
    {
      if ( af_useImpulseFriction.valueInteger != 0 || af_useJointImpulseFriction.valueInteger != 0 )
      {
        invMass = body1->invMass;
        body2 = this->body2;
        v18 = invMass;
        v16 = &body1->current.spatialVelocity.p[3];
        v19 = *v16;
        v20 = v16[1];
        v21 = v16[2];
        if ( body2 != nullptr )
        {
          v19 = (float)(*v16 - body2->current.spatialVelocity.p[3]);
          v20 = (float)(v16[1] - body2->current.spatialVelocity.p[4]);
          v21 = (float)(v16[2] - body2->current.spatialVelocity.p[5]);
          v18 = (float)(body2->invMass + (float)invMass);
        }
        v22 = (float)((float)Friction / (float)v18);
        v23 = v16[1];
        v24 = v16[2];
        v25 = (float)((float)v22 * (float)v19);
        v26 = (float)((float)v20 * (float)v22);
        v27 = (float)((float)v21 * (float)v22);
        *v16 = *v16 - (float)((float)invMass * (float)v25);
        v16[1] = (float)v23 - (float)((float)v26 * (float)invMass);
        v16[2] = (float)v24 - (float)((float)v27 * (float)invMass);
        v28 = this->body2;
        if ( v28 != nullptr )
        {
          v29 = (float)((float)v26 * v28->invMass);
          v30 = v28->current.spatialVelocity.p[4];
          v31 = (float)((float)v27 * v28->invMass);
          v32 = v28->current.spatialVelocity.p[5];
          v28->current.spatialVelocity.p[3] = v28->current.spatialVelocity.p[3] + (float)(v28->invMass * (float)v25);
          v28->current.spatialVelocity.p[4] = (float)v30 + (float)v29;
          v28->current.spatialVelocity.p[5] = (float)v32 + (float)v31;
        }
      }
      else
      {
        if ( this->fc == nullptr )
        {
          v13 = (idAFConstraint_BallAndSocketJointFriction *)idMem::AllocWithLocation(
                                                               this: &mem,
                                                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                               size: 0x1E0u,
                                                               tag: TAG_AF,
                                                               zeroBuffer: false,
                                                               align: ALIGN_16,
                                                               heap: HEAP_DEFAULTHEAP);
          if ( v13 != nullptr )
            v14 = idAFConstraint_BallAndSocketJointFriction::idAFConstraint_BallAndSocketJointFriction(
                    this: v13,
                    a2: v12,
                    a3: v11,
                    a4: v10,
                    a5: v9,
                    a6: v8,
                    a7: v7,
                    a8: v6);
          else
            v14 = nullptr;
          this->fc = v14;
          v14->joint = this;
          v14->body1 = this->body1;
          v14->body2 = this->body2;
        }
        idAFConstraint_BallAndSocketJointFriction::Add(this: this->fc, phys: this->physics, invTimeStep);
      }
    }
  }
}


// ========================================================================
// __unwind$275299
// EA  : 0x82727F98
// RVA : 0x00727F98
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_275299()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_AF);
}


// ========================================================================
// ?SetConeLimit@idAFConstraint_UniversalJoint@@QAAXABVidVec3@@M@Z
// EA  : 0x82727FD0
// RVA : 0x00727FD0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_UniversalJoint::SetConeLimit(
        idAFConstraint_UniversalJoint *this,
        const idVec3 *coneAxis,
        double coneAngle,
        int a4,
        int a5,
        int a6,
        const idVec3 *a7)
{
  idAFConstraint_PyramidLimit *pyramidLimit; // r3
  int v11; // r10
  int v12; // r9
  int v13; // r7
  int v14; // r6
  int v15; // r5
  int v16; // r4
  idAFConstraint_ConeLimit *v17; // r3
  idAFConstraint_ConeLimit *v18; // r3
  idPhysics_AF *physics; // r11
  idAFBody *body2; // r5
  idAFBody *body1; // r4
  idAFConstraint_ConeLimit *coneLimit; // r3
  float *clipModel; // r11
  const idVec3 *v24; // r7
  double z; // fp12
  double v26; // fp0
  double v27; // fp11
  double v28; // fp9
  double v29; // fp8
  float v30[4]; // [sp+58h] [-38h] BYREF

  pyramidLimit = this->pyramidLimit;
  if ( pyramidLimit != nullptr )
  {
    ((void (__fastcall *)(idAFConstraint_PyramidLimit *, int))pyramidLimit->dtr_idAFConstraint)(a1: pyramidLimit, a2: 1);
    this->pyramidLimit = nullptr;
  }
  if ( this->coneLimit == nullptr )
  {
    v17 = (idAFConstraint_ConeLimit *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                        size: 0x210u,
                                        tag: TAG_AF,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
    if ( v17 != nullptr )
      v18 = idAFConstraint_ConeLimit::idAFConstraint_ConeLimit(
              this: v17,
              a2: v16,
              a3: v15,
              a4: v14,
              a5: v13,
              a6: (int)a7,
              a7: v12,
              a8: v11);
    else
      v18 = nullptr;
    physics = this->physics;
    this->coneLimit = v18;
    v18->physics = physics;
  }
  body2 = this->body2;
  body1 = this->body1;
  coneLimit = this->coneLimit;
  if ( body2 != nullptr )
  {
    clipModel = (float *)body2->clipModel;
    v24 = (const idVec3 *)v30;
    z = coneAxis->z;
    v26 = clipModel[16];
    v27 = clipModel[13];
    v28 = (float)((float)(coneAxis->x * clipModel[14]) + (float)(coneAxis->y * clipModel[15]));
    v29 = (float)((float)(coneAxis->x * clipModel[11]) + (float)(coneAxis->y * clipModel[12]));
    v30[2] = (float)(coneAxis->z * clipModel[19])
           + (float)((float)(coneAxis->x * clipModel[17]) + (float)(coneAxis->y * clipModel[18]));
    v30[1] = (float)((float)z * (float)v26) + (float)v28;
    v30[0] = (float)((float)z * (float)v27) + (float)v29;
  }
  else
  {
    v24 = coneAxis;
    body2 = nullptr;
  }
  idAFConstraint_ConeLimit::Setup(
    this: coneLimit,
    b1: body1,
    b2: body2,
    coneAnchor: &this->anchor2,
    coneAxis: v24,
    coneAngle,
    body1Axis: a7,
    a8: &this->shaft1.x);
}


// ========================================================================
// __unwind$275489
// EA  : 0x82728118
// RVA : 0x00728118
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_275489()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_AF);
}


// ========================================================================
// ?SetPyramidLimit@idAFConstraint_UniversalJoint@@QAAXABVidVec3@@0MM@Z
// EA  : 0x82728150
// RVA : 0x00728150
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_UniversalJoint::SetPyramidLimit(
        idAFConstraint_UniversalJoint *this,
        const idVec3 *pyramidAxis,
        const idVec3 *baseAxis,
        double angle1,
        double angle2,
        int a6,
        int a7,
        int a8,
        const idVec3 *a9,
        int a10)
{
  idAFConstraint_ConeLimit *coneLimit; // r3
  int v16; // r8
  int v17; // r7
  int v18; // r6
  int v19; // r5
  int v20; // r4
  idAFConstraint_PyramidLimit *v21; // r3
  idAFConstraint_PyramidLimit *v22; // r3
  idPhysics_AF *physics; // r11
  idAFBody *body2; // r5
  idVec3 *p_anchor2; // r6
  idAFBody *body1; // r4
  idAFConstraint_PyramidLimit *pyramidLimit; // r3
  double z; // fp10
  double v29; // fp9
  double v30; // fp13
  double v31; // fp12
  double v32; // fp7
  double v33; // fp8
  double v34; // fp5
  double v35; // fp3
  double v36; // fp29
  double v37; // fp4
  int v38; // [sp+8h] [-C8h]
  int v39; // [sp+Ch] [-C4h]
  int v40; // [sp+10h] [-C0h]
  int v41; // [sp+14h] [-BCh]
  int v42; // [sp+18h] [-B8h]
  int v43; // [sp+1Ch] [-B4h]
  int v44; // [sp+20h] [-B0h]
  int v45; // [sp+24h] [-ACh]
  int v46; // [sp+28h] [-A8h]
  int v47; // [sp+2Ch] [-A4h]
  int v48; // [sp+30h] [-A0h]
  int v49; // [sp+34h] [-9Ch]
  int v50; // [sp+38h] [-98h]
  int v51; // [sp+3Ch] [-94h]
  int v52; // [sp+40h] [-90h]
  int v53; // [sp+44h] [-8Ch]
  int v54; // [sp+48h] [-88h]
  int v55; // [sp+4Ch] [-84h]
  int v56; // [sp+50h] [-80h]
  idVec3 v57; // [sp+68h] [-68h] BYREF
  idVec3 v58; // [sp+78h] [-58h] BYREF

  coneLimit = this->coneLimit;
  if ( coneLimit != nullptr )
  {
    ((void (__fastcall *)(idAFConstraint_ConeLimit *, int))coneLimit->dtr_idAFConstraint)(a1: coneLimit, a2: 1);
    a9 = nullptr;
    this->coneLimit = nullptr;
  }
  if ( this->pyramidLimit == nullptr )
  {
    v21 = (idAFConstraint_PyramidLimit *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                           size: 0x230u,
                                           tag: TAG_AF,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
    if ( v21 != nullptr )
      v22 = idAFConstraint_PyramidLimit::idAFConstraint_PyramidLimit(
              this: v21,
              a2: v20,
              a3: v19,
              a4: v18,
              a5: v17,
              a6: v16,
              a7: (int)a9,
              a8: a10);
    else
      v22 = nullptr;
    physics = this->physics;
    this->pyramidLimit = v22;
    v22->physics = physics;
  }
  body2 = this->body2;
  p_anchor2 = &this->anchor2;
  body1 = this->body1;
  pyramidLimit = this->pyramidLimit;
  if ( body2 != nullptr )
  {
    z = baseAxis->z;
    v29 = pyramidAxis->z;
    v32 = body2->clipModel->axis.mat[0].z;
    v33 = (float)((float)(pyramidAxis->x * body2->clipModel->axis.mat[2].x)
                + (float)(pyramidAxis->y * body2->clipModel->axis.mat[2].y));
    v34 = (float)((float)(pyramidAxis->x * body2->clipModel->axis.mat[1].x)
                + (float)(pyramidAxis->y * body2->clipModel->axis.mat[1].y));
    v35 = (float)((float)(pyramidAxis->x * body2->clipModel->axis.mat[0].x)
                + (float)(pyramidAxis->y * body2->clipModel->axis.mat[0].y));
    v30 = (float)((float)(baseAxis->x * body2->clipModel->axis.mat[0].x)
                + (float)(baseAxis->y * body2->clipModel->axis.mat[0].y));
    v36 = body2->clipModel->axis.mat[2].z;
    v37 = (float)((float)(baseAxis->z * body2->clipModel->axis.mat[1].z)
                + (float)((float)(baseAxis->x * body2->clipModel->axis.mat[1].x)
                        + (float)(baseAxis->y * body2->clipModel->axis.mat[1].y)));
    v31 = body2->clipModel->axis.mat[1].z;
    v57.z = (float)(baseAxis->z * body2->clipModel->axis.mat[2].z)
          + (float)((float)(baseAxis->x * body2->clipModel->axis.mat[2].x)
                  + (float)(baseAxis->y * body2->clipModel->axis.mat[2].y));
    v57.y = v37;
    v57.x = (float)((float)z * (float)v32) + (float)v30;
    v58.y = (float)((float)v29 * (float)v31) + (float)v34;
    v58.x = (float)((float)v29 * (float)v32) + (float)v35;
    v58.z = (float)((float)v29 * (float)v36) + (float)v33;
    idAFConstraint_PyramidLimit::Setup(
      this: pyramidLimit,
      b1: body1,
      b2: body2,
      pyramidAnchor: p_anchor2,
      pyramidAxis: &v58,
      baseAxis: &v57,
      pyramidAngle1: angle1,
      pyramidAngle2: angle2,
      body1Axis: a9,
      a10: (int)&this->shaft1,
      a11: v38,
      a12: v39,
      a13: v40,
      a14: v41,
      a15: v42,
      a16: v43,
      a17: v44,
      a18: v45,
      a19: v46,
      a20: v47,
      a21: v48,
      a22: v49,
      a23: v50,
      a24: v51,
      a25: v52,
      a26: v53,
      a27: v54,
      a28: v55,
      a29: v56,
      a30: &this->shaft1);
  }
  else
  {
    idAFConstraint_PyramidLimit::Setup(
      this: pyramidLimit,
      b1: body1,
      b2: nullptr,
      pyramidAnchor: p_anchor2,
      pyramidAxis,
      baseAxis,
      pyramidAngle1: angle1,
      pyramidAngle2: angle2,
      body1Axis: a9,
      a10,
      a11: v38,
      a12: v39,
      a13: v40,
      a14: v41,
      a15: v42,
      a16: v43,
      a17: v44,
      a18: v45,
      a19: v46,
      a20: v47,
      a21: v48,
      a22: v49,
      a23: v50,
      a24: v51,
      a25: v52,
      a26: v53,
      a27: v54,
      a28: v55,
      a29: v56,
      a30: &this->shaft1);
  }
}


// ========================================================================
// __unwind$275704
// EA  : 0x82728338
// RVA : 0x00728338
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_275704()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 208 + 96), tag: TAG_AF);
}


// ========================================================================
// ?ApplyFriction@idAFConstraint_UniversalJoint@@MAAXM@Z
// EA  : 0x82728370
// RVA : 0x00728370
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_UniversalJoint::ApplyFriction(idAFConstraint_UniversalJoint *this, double invTimeStep)
{
  double Friction; // fp1
  idAFBody *body1; // r11
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r7
  int v10; // r6
  int v11; // r5
  int v12; // r4
  idAFConstraint_UniversalJointFriction *v13; // r3
  idAFConstraint_UniversalJointFriction *v14; // r3
  double invMass; // fp0
  float *v16; // r11
  idAFBody *body2; // r10
  double v18; // fp10
  double v19; // fp13
  double v20; // fp12
  double v21; // fp11
  double v22; // fp10
  double v23; // fp8
  double v24; // fp7
  double v25; // fp13
  double v26; // fp12
  double v27; // fp11
  idAFBody *v28; // r11
  double v29; // fp9
  double v30; // fp8
  double v31; // fp7
  double v32; // fp6

  Friction = idAFConstraint_UniversalJoint::GetFriction(this);
  if ( Friction > 0.0 )
  {
    body1 = this->body1;
    if ( body1 != nullptr )
    {
      if ( af_useImpulseFriction.valueInteger != 0 || af_useJointImpulseFriction.valueInteger != 0 )
      {
        invMass = body1->invMass;
        body2 = this->body2;
        v18 = invMass;
        v16 = &body1->current.spatialVelocity.p[3];
        v19 = *v16;
        v20 = v16[1];
        v21 = v16[2];
        if ( body2 != nullptr )
        {
          v19 = (float)(*v16 - body2->current.spatialVelocity.p[3]);
          v20 = (float)(v16[1] - body2->current.spatialVelocity.p[4]);
          v21 = (float)(v16[2] - body2->current.spatialVelocity.p[5]);
          v18 = (float)(body2->invMass + (float)invMass);
        }
        v22 = (float)((float)Friction / (float)v18);
        v23 = v16[1];
        v24 = v16[2];
        v25 = (float)((float)v22 * (float)v19);
        v26 = (float)((float)v20 * (float)v22);
        v27 = (float)((float)v21 * (float)v22);
        *v16 = *v16 - (float)((float)invMass * (float)v25);
        v16[1] = (float)v23 - (float)((float)v26 * (float)invMass);
        v16[2] = (float)v24 - (float)((float)v27 * (float)invMass);
        v28 = this->body2;
        if ( v28 != nullptr )
        {
          v29 = (float)((float)v26 * v28->invMass);
          v30 = v28->current.spatialVelocity.p[4];
          v31 = (float)((float)v27 * v28->invMass);
          v32 = v28->current.spatialVelocity.p[5];
          v28->current.spatialVelocity.p[3] = v28->current.spatialVelocity.p[3] + (float)(v28->invMass * (float)v25);
          v28->current.spatialVelocity.p[4] = (float)v30 + (float)v29;
          v28->current.spatialVelocity.p[5] = (float)v32 + (float)v31;
        }
      }
      else
      {
        if ( this->fc == nullptr )
        {
          v13 = (idAFConstraint_UniversalJointFriction *)idMem::AllocWithLocation(
                                                           this: &mem,
                                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                           size: 0x1E0u,
                                                           tag: TAG_AF,
                                                           zeroBuffer: false,
                                                           align: ALIGN_16,
                                                           heap: HEAP_DEFAULTHEAP);
          if ( v13 != nullptr )
            v14 = idAFConstraint_UniversalJointFriction::idAFConstraint_UniversalJointFriction(
                    this: v13,
                    a2: v12,
                    a3: v11,
                    a4: v10,
                    a5: v9,
                    a6: v8,
                    a7: v7,
                    a8: v6);
          else
            v14 = nullptr;
          this->fc = v14;
          v14->joint = this;
          v14->body1 = this->body1;
          v14->body2 = this->body2;
        }
        idAFConstraint_UniversalJointFriction::Add(this: this->fc, phys: this->physics, invTimeStep);
      }
    }
  }
}


// ========================================================================
// __unwind$276092
// EA  : 0x82728558
// RVA : 0x00728558
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_276092()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_AF);
}


// ========================================================================
// ?SetLimit@idAFConstraint_Hinge@@QAAXABVidVec3@@M0@Z
// EA  : 0x82728590
// RVA : 0x00728590
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Hinge::SetLimit(
        idAFConstraint_Hinge *this,
        const idVec3 *axis,
        double angle,
        const idVec3 *body1Axis,
        float *a5,
        int a6,
        const idVec3 *a7)
{
  int v11; // r10
  int v12; // r9
  int v13; // r7
  int v14; // r6
  int v15; // r5
  int v16; // r4
  idAFConstraint_ConeLimit *v17; // r3
  idAFConstraint_ConeLimit *v18; // r3
  idPhysics_AF *physics; // r11
  idAFBody *body1; // r4
  idAFBody *body2; // r5
  float *clipModel; // r11
  idAFConstraint_ConeLimit *coneLimit; // r3
  double v24; // fp1
  float *v25; // r10
  float *v26; // r9
  const idVec3 *v27; // r7
  double v28; // fp0
  double v29; // fp12
  double z; // fp4
  double v31; // fp8
  double v32; // fp6
  double v33; // fp11
  double v34; // fp31
  double v35; // fp5
  double v36; // fp3
  double v37; // fp13
  double v38; // fp0
  double v39; // fp11
  double v40; // fp10
  double v41; // fp9
  double v42; // fp7
  float v43[4]; // [sp+58h] [-58h] BYREF
  float v44[4]; // [sp+68h] [-48h] BYREF

  if ( this->coneLimit == nullptr )
  {
    v17 = (idAFConstraint_ConeLimit *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                        size: 0x210u,
                                        tag: TAG_AF,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
    if ( v17 != nullptr )
      v18 = idAFConstraint_ConeLimit::idAFConstraint_ConeLimit(
              this: v17,
              a2: v16,
              a3: v15,
              a4: v14,
              a5: v13,
              a6: (int)a7,
              a7: v12,
              a8: v11);
    else
      v18 = nullptr;
    physics = this->physics;
    this->coneLimit = v18;
    v18->physics = physics;
  }
  body1 = this->body1;
  if ( body1 != nullptr )
  {
    body2 = this->body2;
    clipModel = (float *)body1->clipModel;
    coneLimit = this->coneLimit;
    v24 = angle;
    if ( body2 != nullptr )
    {
      v25 = (float *)body2->clipModel;
      v26 = v43;
      v27 = (const idVec3 *)v44;
      v28 = (float)((float)(axis->x * v25[17]) + (float)(axis->y * v25[18]));
      z = axis->z;
      v31 = (float)((float)(axis->x * v25[11]) + (float)(axis->y * v25[12]));
      v32 = v25[19];
      v33 = v25[16];
      v34 = v25[13];
      v35 = (float)((float)(a5[2] * clipModel[16])
                  + (float)((float)(*a5 * clipModel[14]) + (float)(a5[1] * clipModel[15])));
      v29 = (float)((float)(axis->x * v25[14]) + (float)(axis->y * v25[15]));
      v36 = (float)((float)(a5[2] * clipModel[13])
                  + (float)((float)(*a5 * clipModel[11]) + (float)(a5[1] * clipModel[12])));
      v43[2] = (float)(a5[2] * clipModel[19]) + (float)((float)(*a5 * clipModel[17]) + (float)(a5[1] * clipModel[18]));
      v43[1] = v35;
      v43[0] = v36;
      v44[2] = (float)((float)z * (float)v32) + (float)v28;
      v44[1] = (float)((float)z * (float)v33) + (float)v29;
      v44[0] = (float)((float)z * (float)v34) + (float)v31;
    }
    else
    {
      v37 = a5[1];
      v26 = v44;
      v27 = axis;
      v38 = a5[2];
      body2 = nullptr;
      v39 = clipModel[13];
      v40 = clipModel[15];
      v41 = (float)((float)(*a5 * clipModel[14]) + (float)(a5[2] * clipModel[16]));
      v42 = (float)((float)(*a5 * clipModel[11]) + (float)(a5[1] * clipModel[12]));
      v44[2] = (float)(a5[2] * clipModel[19]) + (float)((float)(*a5 * clipModel[17]) + (float)(a5[1] * clipModel[18]));
      v44[1] = (float)((float)v37 * (float)v40) + (float)v41;
      v44[0] = (float)((float)v38 * (float)v39) + (float)v42;
    }
    idAFConstraint_ConeLimit::Setup(
      this: coneLimit,
      b1: body1,
      b2: body2,
      coneAnchor: &this->anchor2,
      coneAxis: v27,
      coneAngle: v24,
      body1Axis: a7,
      a8: v26);
  }
}


// ========================================================================
// __unwind$276282
// EA  : 0x82728784
// RVA : 0x00728784
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_276282()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 80), tag: TAG_AF);
}


// ========================================================================
// ?ApplyFriction@idAFConstraint_Hinge@@MAAXM@Z
// EA  : 0x827287B8
// RVA : 0x007287B8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Hinge::ApplyFriction(idAFConstraint_Hinge *this, double invTimeStep)
{
  double Friction; // fp1
  idAFBody *body1; // r11
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r7
  int v10; // r6
  int v11; // r5
  int v12; // r4
  idAFConstraint_HingeFriction *v13; // r3
  idAFConstraint_HingeFriction *v14; // r3
  double invMass; // fp0
  float *v16; // r11
  idAFBody *body2; // r10
  double v18; // fp10
  double v19; // fp13
  double v20; // fp12
  double v21; // fp11
  double v22; // fp10
  double v23; // fp8
  double v24; // fp7
  double v25; // fp13
  double v26; // fp12
  double v27; // fp11
  idAFBody *v28; // r11
  double v29; // fp9
  double v30; // fp8
  double v31; // fp7
  double v32; // fp6

  Friction = idAFConstraint_Hinge::GetFriction(this);
  if ( Friction > 0.0 )
  {
    body1 = this->body1;
    if ( body1 != nullptr )
    {
      if ( af_useImpulseFriction.valueInteger != 0 || af_useJointImpulseFriction.valueInteger != 0 )
      {
        invMass = body1->invMass;
        body2 = this->body2;
        v18 = invMass;
        v16 = &body1->current.spatialVelocity.p[3];
        v19 = *v16;
        v20 = v16[1];
        v21 = v16[2];
        if ( body2 != nullptr )
        {
          v19 = (float)(*v16 - body2->current.spatialVelocity.p[3]);
          v20 = (float)(v16[1] - body2->current.spatialVelocity.p[4]);
          v21 = (float)(v16[2] - body2->current.spatialVelocity.p[5]);
          v18 = (float)(body2->invMass + (float)invMass);
        }
        v22 = (float)((float)Friction / (float)v18);
        v23 = v16[1];
        v24 = v16[2];
        v25 = (float)((float)v22 * (float)v19);
        v26 = (float)((float)v20 * (float)v22);
        v27 = (float)((float)v21 * (float)v22);
        *v16 = *v16 - (float)((float)invMass * (float)v25);
        v16[1] = (float)v23 - (float)((float)v26 * (float)invMass);
        v16[2] = (float)v24 - (float)((float)v27 * (float)invMass);
        v28 = this->body2;
        if ( v28 != nullptr )
        {
          v29 = (float)((float)v26 * v28->invMass);
          v30 = v28->current.spatialVelocity.p[4];
          v31 = (float)((float)v27 * v28->invMass);
          v32 = v28->current.spatialVelocity.p[5];
          v28->current.spatialVelocity.p[3] = v28->current.spatialVelocity.p[3] + (float)(v28->invMass * (float)v25);
          v28->current.spatialVelocity.p[4] = (float)v30 + (float)v29;
          v28->current.spatialVelocity.p[5] = (float)v32 + (float)v31;
        }
      }
      else
      {
        if ( this->fc == nullptr )
        {
          v13 = (idAFConstraint_HingeFriction *)idMem::AllocWithLocation(
                                                  this: &mem,
                                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                  size: 0x1E0u,
                                                  tag: TAG_AF,
                                                  zeroBuffer: false,
                                                  align: ALIGN_16,
                                                  heap: HEAP_DEFAULTHEAP);
          if ( v13 != nullptr )
            v14 = idAFConstraint_HingeFriction::idAFConstraint_HingeFriction(
                    this: v13,
                    a2: v12,
                    a3: v11,
                    a4: v10,
                    a5: v9,
                    a6: v8,
                    a7: v7,
                    a8: v6);
          else
            v14 = nullptr;
          this->fc = v14;
          v14->hinge = this;
          v14->body1 = this->body1;
          v14->body2 = this->body2;
        }
        idAFConstraint_HingeFriction::Add(this: this->fc, phys: this->physics, invTimeStep);
      }
    }
  }
}


// ========================================================================
// __unwind$276897
// EA  : 0x827289A0
// RVA : 0x007289A0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_276897()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_AF);
}


// ========================================================================
// ?ApplyFriction@idAFConstraint_Contact@@MAAXM@Z
// EA  : 0x827289D8
// RVA : 0x007289D8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __fastcall idAFConstraint_Contact::ApplyFriction(idAFConstraint_Contact *this, double invTimeStep)
{
  idAFBody *body1; // r11
  idPhysics_AF *physics; // r3
  double contactFriction; // fp31
  idAFBody *body2; // r11
  double v8; // fp28
  double z; // fp0
  double y; // fp13
  double x; // fp12
  double v12; // fp11
  idAFBody *v13; // r30
  float *clipModel; // r11
  double v15; // fp9
  double v16; // fp8
  double v17; // fp27
  double v18; // fp26
  double v19; // fp25
  double v20; // fp5
  double v21; // fp1
  double v22; // fp0
  double v23; // fp13
  double v24; // fp1
  double v25; // fp31
  double v26; // fp30
  double v27; // fp29
  double invMass; // fp24
  double v29; // fp28
  double v30; // fp23
  double v31; // fp22
  double v32; // fp21
  float *InverseWorldInertia; // r3
  float *p; // r8
  double v35; // fp6
  float *v36; // r11
  double v37; // fp0
  double v38; // fp1
  double v39; // fp12
  double v40; // fp11
  idAFBody *v41; // r11
  double v42; // fp7
  double v43; // fp4
  double v44; // fp0
  idAFBody *v45; // r11
  double v46; // fp5
  double v47; // fp4
  int v48; // r10
  int v49; // r9
  int v50; // r8
  int v51; // r7
  int v52; // r6
  int v53; // r5
  int v54; // r4
  idAFConstraint_ContactFriction *v55; // r3
  idAFConstraint_ContactFriction *v56; // r3
  idAFConstraint_ContactFriction *fc; // r11
  idVec3 v58; // [sp+58h] [-118h] BYREF
  idSpatialVec v59[2]; // [sp+70h] [-100h] BYREF
  float v60; // [sp+80h] [-F0h] BYREF
  idSpatialVec v61[2]; // [sp+A0h] [-D0h] BYREF
  float v62; // [sp+B0h] [-C0h] BYREF
  int v63; // [sp+D0h] [-A0h] BYREF

  body1 = this->body1;
  if ( body1 != nullptr )
  {
    physics = this->physics;
    if ( physics != nullptr && (this->contact.flags & 0x10) == 0 )
    {
      contactFriction = body1->contactFriction;
      body2 = this->body2;
      if ( body2 != nullptr && body2->contactFriction < contactFriction )
        contactFriction = body2->contactFriction;
      v8 = (float)(idPhysics_AF::GetContactFrictionScale(this: physics) * (float)contactFriction);
      if ( v8 > 0.0 )
      {
        if ( af_useImpulseFriction.valueInteger != 0 )
        {
          v59[0].allocated = 0;
          v59[0].size = 0;
          v59[0].p = nullptr;
          idSpatialVec::SetData(this: v59, length: 6, data: &v60);
          v61[0].allocated = 0;
          v61[0].size = 0;
          v61[0].p = nullptr;
          idSpatialVec::SetData(this: v61, length: 6, data: &v62);
          z = this->contact.point.z;
          y = this->contact.point.y;
          x = this->contact.point.x;
          v12 = this->contact.normal.y;
          v13 = this->body1;
          clipModel = (float *)v13->clipModel;
          v15 = v13->current.spatialVelocity.p[3];
          v16 = v13->current.spatialVelocity.p[5];
          v17 = (float)(this->contact.point.z - clipModel[10]);
          v18 = (float)(this->contact.point.y - clipModel[9]);
          v19 = (float)(this->contact.point.x - clipModel[8]);
          v20 = (float)((float)(this->contact.normal.z
                              * (float)(v13->current.spatialVelocity.p[2]
                                      + (float)((float)((float)v15 * (float)((float)y - clipModel[9]))
                                              - (float)(v13->current.spatialVelocity.p[4]
                                                      * (float)((float)x - clipModel[8])))))
                      + (float)((float)(this->contact.normal.x
                                      * (float)(v13->current.spatialVelocity.p[0]
                                              + (float)((float)(v13->current.spatialVelocity.p[4]
                                                              * (float)((float)z - clipModel[10]))
                                                      - (float)((float)v16 * (float)((float)y - clipModel[9])))))
                              + (float)(this->contact.normal.y
                                      * (float)(v13->current.spatialVelocity.p[1]
                                              + (float)((float)((float)v16 * (float)((float)x - clipModel[8]))
                                                      - (float)((float)v15 * (float)((float)z - clipModel[10])))))));
          v21 = (float)((float)(v13->current.spatialVelocity.p[2]
                              + (float)((float)((float)v15 * (float)((float)y - clipModel[9]))
                                      - (float)(v13->current.spatialVelocity.p[4] * (float)((float)x - clipModel[8]))))
                      - (float)(this->contact.normal.z
                              * (float)((float)(this->contact.normal.z
                                              * (float)(v13->current.spatialVelocity.p[2]
                                                      + (float)((float)((float)v15 * (float)((float)y - clipModel[9]))
                                                              - (float)(v13->current.spatialVelocity.p[4]
                                                                      * (float)((float)x - clipModel[8])))))
                                      + (float)((float)(this->contact.normal.x
                                                      * (float)(v13->current.spatialVelocity.p[0]
                                                              + (float)((float)(v13->current.spatialVelocity.p[4]
                                                                              * (float)((float)z - clipModel[10]))
                                                                      - (float)((float)v16
                                                                              * (float)((float)y - clipModel[9])))))
                                              + (float)(this->contact.normal.y
                                                      * (float)(v13->current.spatialVelocity.p[1]
                                                              + (float)((float)((float)v16
                                                                              * (float)((float)x - clipModel[8]))
                                                                      - (float)((float)v15
                                                                              * (float)((float)z - clipModel[10])))))))));
          v22 = (float)((float)(v13->current.spatialVelocity.p[1]
                              + (float)((float)((float)v16 * (float)((float)x - clipModel[8]))
                                      - (float)((float)v15 * (float)((float)z - clipModel[10]))))
                      - (float)((float)v12
                              * (float)((float)(this->contact.normal.z
                                              * (float)(v13->current.spatialVelocity.p[2]
                                                      + (float)((float)((float)v15 * (float)((float)y - clipModel[9]))
                                                              - (float)(v13->current.spatialVelocity.p[4]
                                                                      * (float)((float)x - clipModel[8])))))
                                      + (float)((float)(this->contact.normal.x
                                                      * (float)(v13->current.spatialVelocity.p[0]
                                                              + (float)((float)(v13->current.spatialVelocity.p[4]
                                                                              * (float)((float)z - clipModel[10]))
                                                                      - (float)((float)v16
                                                                              * (float)((float)y - clipModel[9])))))
                                              + (float)((float)v12
                                                      * (float)(v13->current.spatialVelocity.p[1]
                                                              + (float)((float)((float)v16
                                                                              * (float)((float)x - clipModel[8]))
                                                                      - (float)((float)v15
                                                                              * (float)((float)z - clipModel[10])))))))));
          v23 = (float)((float)(v13->current.spatialVelocity.p[0]
                              + (float)((float)(v13->current.spatialVelocity.p[4]
                                              * (float)(this->contact.point.z - clipModel[10]))
                                      - (float)(v13->current.spatialVelocity.p[5]
                                              * (float)(this->contact.point.y - clipModel[9]))))
                      - (float)(this->contact.normal.x * (float)v20));
          v58.z = -v21;
          v58.y = -v22;
          v58.x = -v23;
          v24 = idVec3::NormalizeFast(this: &v58);
          v25 = v58.x;
          v26 = v58.z;
          v27 = v58.y;
          invMass = v13->invMass;
          v29 = (float)((float)v24 * (float)v8);
          v30 = (float)((float)(v58.y * (float)v19) - (float)(v58.x * (float)v18));
          v31 = (float)((float)(v58.x * (float)v17) - (float)(v58.z * (float)v19));
          v32 = (float)((float)(v58.z * (float)v18) - (float)(v58.y * (float)v17));
          InverseWorldInertia = (float *)idAFBody::GetInverseWorldInertia(
                                           this: (idAFBody *)&v63,
                                           result: (const idMat3 *)v13);
          p = v59[0].p;
          v35 = (float)((float)v29
                      / (float)((float)((float)((float)((float)((float)((float)(InverseWorldInertia[7] * (float)v30)
                                                                      + (float)((float)(InverseWorldInertia[1]
                                                                                      * (float)v32)
                                                                              + (float)(InverseWorldInertia[4]
                                                                                      * (float)v31)))
                                                              * (float)v17)
                                                      - (float)((float)((float)(InverseWorldInertia[8] * (float)v30)
                                                                      + (float)((float)(InverseWorldInertia[2]
                                                                                      * (float)v32)
                                                                              + (float)(InverseWorldInertia[5]
                                                                                      * (float)v31)))
                                                              * (float)v18))
                                              * (float)v25)
                                      + (float)((float)((float)v27
                                                      * (float)((float)((float)((float)(InverseWorldInertia[8]
                                                                                      * (float)v30)
                                                                              + (float)((float)(InverseWorldInertia[2]
                                                                                              * (float)v32)
                                                                                      + (float)(InverseWorldInertia[5]
                                                                                              * (float)v31)))
                                                                      * (float)v19)
                                                              - (float)((float)((float)((float)v32 * *InverseWorldInertia)
                                                                              + (float)((float)(InverseWorldInertia[3]
                                                                                              * (float)v31)
                                                                                      + (float)(InverseWorldInertia[6]
                                                                                              * (float)v30)))
                                                                      * (float)v17)))
                                              + (float)((float)v26
                                                      * (float)((float)((float)((float)((float)v32 * *InverseWorldInertia)
                                                                              + (float)((float)(InverseWorldInertia[3]
                                                                                              * (float)v31)
                                                                                      + (float)(InverseWorldInertia[6]
                                                                                              * (float)v30)))
                                                                      * (float)v18)
                                                              - (float)((float)((float)(InverseWorldInertia[7]
                                                                                      * (float)v30)
                                                                              + (float)((float)(InverseWorldInertia[1]
                                                                                              * (float)v32)
                                                                                      + (float)(InverseWorldInertia[4]
                                                                                              * (float)v31)))
                                                                      * (float)v19)))))
                              + (float)invMass));
          *v59[0].p = (float)((float)v29
                            / (float)((float)((float)((float)((float)((float)((float)(InverseWorldInertia[7] * (float)v30)
                                                                            + (float)((float)(InverseWorldInertia[1]
                                                                                            * (float)v32)
                                                                                    + (float)(InverseWorldInertia[4]
                                                                                            * (float)v31)))
                                                                    * (float)v17)
                                                            - (float)((float)((float)(InverseWorldInertia[8] * (float)v30)
                                                                            + (float)((float)(InverseWorldInertia[2]
                                                                                            * (float)v32)
                                                                                    + (float)(InverseWorldInertia[5]
                                                                                            * (float)v31)))
                                                                    * (float)v18))
                                                    * (float)v25)
                                            + (float)((float)((float)v27
                                                            * (float)((float)((float)((float)(InverseWorldInertia[8]
                                                                                            * (float)v30)
                                                                                    + (float)((float)(InverseWorldInertia[2] * (float)v32)
                                                                                            + (float)(InverseWorldInertia[5] * (float)v31)))
                                                                            * (float)v19)
                                                                    - (float)((float)((float)((float)v32
                                                                                            * *InverseWorldInertia)
                                                                                    + (float)((float)(InverseWorldInertia[3] * (float)v31)
                                                                                            + (float)(InverseWorldInertia[6] * (float)v30)))
                                                                            * (float)v17)))
                                                    + (float)((float)v26
                                                            * (float)((float)((float)((float)((float)v32
                                                                                            * *InverseWorldInertia)
                                                                                    + (float)((float)(InverseWorldInertia[3] * (float)v31)
                                                                                            + (float)(InverseWorldInertia[6] * (float)v30)))
                                                                            * (float)v18)
                                                                    - (float)((float)((float)(InverseWorldInertia[7]
                                                                                            * (float)v30)
                                                                                    + (float)((float)(InverseWorldInertia[1] * (float)v32)
                                                                                            + (float)(InverseWorldInertia[4] * (float)v31)))
                                                                            * (float)v19)))))
                                    + (float)invMass))
                    * (float)v25;
          p[2] = (float)v26 * (float)v35;
          p[1] = (float)v27 * (float)v35;
          v36 = v59[0].p;
          v37 = *v59[0].p;
          v38 = v59[0].p[1];
          v39 = (float)(v59[0].p[2] * (float)v19);
          v40 = (float)(*v59[0].p * (float)v18);
          v59[0].p[3] = (float)(v59[0].p[2] * (float)v18) - (float)(v59[0].p[1] * (float)v17);
          v36[4] = (float)((float)v37 * (float)v17) - (float)v39;
          v36[5] = (float)((float)v38 * (float)v19) - (float)v40;
          idAFBody::InverseWorldSpatialInertiaMultiply(this: this->body1, dst: v61, vec: v59);
          v41 = this->body1;
          v42 = v41->current.spatialVelocity.p[0];
          v43 = *v61[0].p;
          v44 = (float)(v61[0].p[2] + v41->current.spatialVelocity.p[2]);
          v41->current.spatialVelocity.p[1] = v61[0].p[1] + v41->current.spatialVelocity.p[1];
          v41->current.spatialVelocity.p[2] = v44;
          v41->current.spatialVelocity.p[0] = (float)v43 + (float)v42;
          v45 = this->body1;
          v46 = (float)(v61[0].p[5] + v45->current.spatialVelocity.p[5]);
          v47 = (float)(v61[0].p[4] + v45->current.spatialVelocity.p[4]);
          v45->current.spatialVelocity.p[3] = v61[0].p[3] + v45->current.spatialVelocity.p[3];
          v45->current.spatialVelocity.p[4] = v47;
          v45->current.spatialVelocity.p[5] = v46;
          if ( v61[0].p != nullptr && v61[0].allocated > 0 )
            idMem::Free(this: &mem, ptr: v61[0].p, align: ALIGN_16);
          if ( v59[0].p != nullptr && v59[0].allocated > 0 )
            idMem::Free(this: &mem, ptr: v59[0].p, align: ALIGN_16);
        }
        else
        {
          if ( this->fc == nullptr )
          {
            v55 = (idAFConstraint_ContactFriction *)idMem::AllocWithLocation(
                                                      this: &mem,
                                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                      size: 0x1E0u,
                                                      tag: TAG_AF,
                                                      zeroBuffer: false,
                                                      align: ALIGN_16,
                                                      heap: HEAP_DEFAULTHEAP);
            if ( v55 != nullptr )
              v56 = idAFConstraint_ContactFriction::idAFConstraint_ContactFriction(
                      this: v55,
                      a2: v54,
                      a3: v53,
                      a4: v52,
                      a5: v51,
                      a6: v50,
                      a7: v49,
                      a8: v48);
            else
              v56 = nullptr;
            this->fc = v56;
          }
          fc = this->fc;
          fc->cc = this;
          fc->body1 = this->body1;
          fc->body2 = this->body2;
          idAFConstraint_ContactFriction::Add(this: this->fc, phys: this->physics, invTimeStep);
        }
      }
    }
  }
}


// ========================================================================
// __unwind$277091
// EA  : 0x82728E14
// RVA : 0x00728E14
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_277091()
{
  int v0; // r12

  idSpatialVec::~idSpatialVec(this: (idStaticSpatialVec *)(v0 - 368 + 112));
}


// ========================================================================
// __unwind$277093
// EA  : 0x82728E3C
// RVA : 0x00728E3C
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _unwind_277093()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 368 + 80), tag: TAG_AF);
}


// ========================================================================
// `dynamic initializer for 'af_errorReduction''
// EA  : 0x8333FAE8
// RVA : 0x0133FAE8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_errorReduction__()
{
  idCVar::idCVar(
    this: &af_errorReduction,
    name: "af_errorReduction",
    value: "0.5",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_errorReduction__);
}


// ========================================================================
// `dynamic initializer for 'af_errorReductionMax''
// EA  : 0x8333FB40
// RVA : 0x0133FB40
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_errorReductionMax__()
{
  idCVar::idCVar(
    this: &af_errorReductionMax,
    name: "af_errorReductionMax",
    value: "256.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_errorReductionMax__);
}


// ========================================================================
// `dynamic initializer for 'af_lcpEpsilon''
// EA  : 0x8333FB98
// RVA : 0x0133FB98
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_lcpEpsilon__()
{
  idCVar::idCVar(
    this: &af_lcpEpsilon,
    name: "af_lcpEpsilon",
    value: "0.00001",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_lcpEpsilon__);
}


// ========================================================================
// `dynamic initializer for 'af_limitErrorReduction''
// EA  : 0x8333FBF0
// RVA : 0x0133FBF0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_limitErrorReduction__()
{
  idCVar::idCVar(
    this: &af_limitErrorReduction,
    name: "af_limitErrorReduction",
    value: "0.3",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_limitErrorReduction__);
}


// ========================================================================
// `dynamic initializer for 'af_limitErrorReductionMax''
// EA  : 0x8333FC48
// RVA : 0x0133FC48
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_limitErrorReductionMax__()
{
  idCVar::idCVar(
    this: &af_limitErrorReductionMax,
    name: "af_limitErrorReductionMax",
    value: "256.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_limitErrorReductionMax__);
}


// ========================================================================
// `dynamic initializer for 'af_limitLcpEpsilon''
// EA  : 0x8333FCA0
// RVA : 0x0133FCA0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_limitLcpEpsilon__()
{
  idCVar::idCVar(
    this: &af_limitLcpEpsilon,
    name: "af_limitLcpEpsilon",
    value: "0.0001",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_limitLcpEpsilon__);
}


// ========================================================================
// `dynamic initializer for 'af_contactErrorReduction''
// EA  : 0x8333FCF8
// RVA : 0x0133FCF8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_contactErrorReduction__()
{
  idCVar::idCVar(
    this: &af_contactErrorReduction,
    name: "af_contactErrorReduction",
    value: "0.2",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_contactErrorReduction__);
}


// ========================================================================
// `dynamic initializer for 'af_contactErrorReductionMax''
// EA  : 0x8333FD50
// RVA : 0x0133FD50
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_contactErrorReductionMax__()
{
  idCVar::idCVar(
    this: &af_contactErrorReductionMax,
    name: "af_contactErrorReductionMax",
    value: "256.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_contactErrorReductionMax__);
}


// ========================================================================
// `dynamic initializer for 'af_contactLcpEpsilon''
// EA  : 0x8333FDA8
// RVA : 0x0133FDA8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_contactLcpEpsilon__()
{
  idCVar::idCVar(
    this: &af_contactLcpEpsilon,
    name: "af_contactLcpEpsilon",
    value: "0.000001",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_contactLcpEpsilon__);
}


// ========================================================================
// `dynamic initializer for 'af_universalErrorReduction''
// EA  : 0x8333FE00
// RVA : 0x0133FE00
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_universalErrorReduction__()
{
  idCVar::idCVar(
    this: &af_universalErrorReduction,
    name: "af_universalErrorReduction",
    value: "0.5",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_universalErrorReduction__);
}


// ========================================================================
// `dynamic initializer for 'af_universalErrorReductionMax''
// EA  : 0x8333FE58
// RVA : 0x0133FE58
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_universalErrorReductionMax__()
{
  idCVar::idCVar(
    this: &af_universalErrorReductionMax,
    name: "af_universalErrorReductionMax",
    value: "256.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_universalErrorReductionMax__);
}


// ========================================================================
// `dynamic initializer for 'af_universalTorsionLcpEpsilon''
// EA  : 0x8333FEB0
// RVA : 0x0133FEB0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_universalTorsionLcpEpsilon__()
{
  idCVar::idCVar(
    this: &af_universalTorsionLcpEpsilon,
    name: "af_universalTorsionLcpEpsilon",
    value: "0.1",
    flags: 4,
    description: "amount of elasticity about the shaft of a universal joint",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_universalTorsionLcpEpsilon__);
}


// ========================================================================
// `dynamic initializer for 'af_suspensionLcpEpsilon''
// EA  : 0x8333FF08
// RVA : 0x0133FF08
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_suspensionLcpEpsilon__()
{
  idCVar::idCVar(
    this: &af_suspensionLcpEpsilon,
    name: "af_suspensionLcpEpsilon",
    value: "0.0000001",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_suspensionLcpEpsilon__);
}


// ========================================================================
// `dynamic initializer for 'af_forceFriction''
// EA  : 0x8333FF60
// RVA : 0x0133FF60
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_forceFriction__()
{
  idCVar::idCVar(
    this: &af_forceFriction,
    name: "af_forceFriction",
    value: "-1",
    flags: 4,
    description: "force the given friction value",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_forceFriction__);
}


// ========================================================================
// `dynamic initializer for 'af_useImpulseFriction''
// EA  : 0x8333FFB8
// RVA : 0x0133FFB8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_useImpulseFriction__()
{
  idCVar::idCVar(
    this: &af_useImpulseFriction,
    name: "af_useImpulseFriction",
    value: "0",
    flags: 1,
    description: "use impulse based contact friction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_useImpulseFriction__);
}


// ========================================================================
// `dynamic initializer for 'af_useJointImpulseFriction''
// EA  : 0x83340010
// RVA : 0x01340010
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_useJointImpulseFriction__()
{
  idCVar::idCVar(
    this: &af_useJointImpulseFriction,
    name: "af_useJointImpulseFriction",
    value: "0",
    flags: 1,
    description: "use impulse based joint friction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_useJointImpulseFriction__);
}


// ========================================================================
// `dynamic initializer for 'af_skipLimits''
// EA  : 0x83340068
// RVA : 0x01340068
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_skipLimits__()
{
  idCVar::idCVar(
    this: &af_skipLimits,
    name: "af_skipLimits",
    value: "0",
    flags: 1,
    description: "skip joint limits",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_skipLimits__);
}


// ========================================================================
// `dynamic initializer for 'af_showLimits''
// EA  : 0x833400C0
// RVA : 0x013400C0
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showLimits__()
{
  idCVar::idCVar(
    this: &af_showLimits,
    name: "af_showLimits",
    value: "0",
    flags: 1,
    description: "show joint limits",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showLimits__);
}


// ========================================================================
// `dynamic initializer for 'BOX_SCALE_MAX''
// EA  : 0x83340118
// RVA : 0x01340118
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void _dynamic_initializer_for__BOX_SCALE_MAX__()
{
  BOX_SCALE_MAX = (float)1.0e30 * (float)0.5;
}


// ========================================================================
// `dynamic initializer for 'af_showTableResults''
// EA  : 0x83340138
// RVA : 0x01340138
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showTableResults__()
{
  idCVar::idCVar(
    this: &af_showTableResults,
    name: "af_showTableResults",
    value: "0",
    flags: 1,
    description: "Show constraint values pulled from tables.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showTableResults__);
}


// ========================================================================
// `dynamic initializer for 'v_compress''
// EA  : 0x83340190
// RVA : 0x01340190
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__v_compress__()
{
  idCVar::idCVar(
    this: &v_compress,
    name: "v_compress",
    value: "-1",
    flags: 4,
    description: "Vehicle spring compress (-1 for default)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__v_compress__);
}


// ========================================================================
// `dynamic initializer for 'v_damping''
// EA  : 0x833401E8
// RVA : 0x013401E8
// PDB : w:\tech5\engine\gamelib\physics\afconstraint.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__v_damping__()
{
  idCVar::idCVar(
    this: &v_damping,
    name: "v_damping",
    value: "-1",
    flags: 4,
    description: "Vehicle spring damping (-1 for default)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__v_damping__);
}

