
// ========================================================================
// ??1idPhysics_RigidBody3DOF@@UAA@XZ
// EA  : 0x8275F7F0
// RVA : 0x0075F7F0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::~idPhysics_RigidBody3DOF(idPhysics_RigidBody3DOF *this)
{
  idClipModel *clipModel; // r3

  this->__vftable = (idPhysics_RigidBody3DOF_vtbl *)&idPhysics_RigidBody3DOF::`vftable';
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
  {
    idClipModel::Delete(this: clipModel);
    this->clipModel = nullptr;
  }
  idPhysics_DynamicBase::~idPhysics_DynamicBase(this);
}


// ========================================================================
// __unwind$246286
// EA  : 0x8275F854
// RVA : 0x0075F854
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void _unwind_246286()
{
  int v0; // r12

  idPhysics_DynamicBase::~idPhysics_DynamicBase(this: *(idPhysics_DynamicBase **)(v0 - 112 + 132));
}


// ========================================================================
// ?SetCoefficientOfRestitution@idPhysics_RigidBody3DOF@@QAAXM@Z
// EA  : 0x8275F880
// RVA : 0x0075F880
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SetCoefficientOfRestitution(idPhysics_RigidBody3DOF *this, double cor)
{
  this->coefficientOfRestitution = cor;
}


// ========================================================================
// ?GetObjectListFactory@XGRAPHICS@@YAPAU_OBJECT_LIST_FACTORY@1@PAX@Z
// EA  : 0x8275F888
// RVA : 0x0075F888
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

XGRAPHICS::_OBJECT_LIST_FACTORY *__fastcall XGRAPHICS::GetObjectListFactory(_DWORD *hSSMDev)
{
  return (XGRAPHICS::_OBJECT_LIST_FACTORY *)hSSMDev[30];
}


// ========================================================================
// ?SetMass@idPhysics_RigidBody3DOF@@UAAXMH@Z
// EA  : 0x8275F890
// RVA : 0x0075F890
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SetMass(idPhysics_RigidBody3DOF *this, double mass_, int id)
{
  this->mass = mass_;
  this->inverseMass = (float)1.0 / (float)mass_;
}


// ========================================================================
// ?GetMass@idPhysics_RigidBody3DOF@@UBAMH@Z
// EA  : 0x8275F8A8
// RVA : 0x0075F8A8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

float __fastcall idPhysics_RigidBody3DOF::GetMass(idPhysics_RigidBody3DOF *this, int id)
{
  double mass; // fp1

  mass = this->mass;
  return *((float *)&mass + 1);
}


// ========================================================================
// ?SetContents@idPhysics_RigidBody3DOF@@UAAXHH@Z
// EA  : 0x8275F8B0
// RVA : 0x0075F8B0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SetContents(idPhysics_RigidBody3DOF *this, int contents, int id)
{
  idClipModel::SetContents(this: this->clipModel, newContents: contents);
}


// ========================================================================
// ?Activate@idPhysics_RigidBody3DOF@@UAAXXZ
// EA  : 0x8275F8B8
// RVA : 0x0075F8B8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::Activate(idPhysics_RigidBody3DOF *this)
{
  this->current.atRest = -1;
}


// ========================================================================
// ?IsAtRest@idPhysics_RigidBody3DOF@@UBA_NXZ
// EA  : 0x8275F8C8
// RVA : 0x0075F8C8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

BOOL __fastcall idPhysics_RigidBody3DOF::IsAtRest(idPhysics_RigidBody3DOF *this)
{
  return this->current.atRest >= 0;
}


// ========================================================================
// ?IsPushable@idPhysics_RigidBody3DOF@@UBA_NH@Z
// EA  : 0x8275F8D8
// RVA : 0x0075F8D8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

BOOL __fastcall idPhysics_RigidBody3DOF::IsPushable(idPhysics_RigidBody3DOF *this, int sourceContentType)
{
  return (~*(_BYTE *)&this->flags & 0x20) != 0;
}


// ========================================================================
// ?GetOrigin@idPhysics_RigidBody3DOF@@UBAABVidVec3@@H@Z
// EA  : 0x8275F8E8
// RVA : 0x0075F8E8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

idPhysics_RigidBody3DOF::bodyIntState_t *__fastcall idPhysics_RigidBody3DOF::GetOrigin(
        idPhysics_RigidBody3DOF *this,
        int id)
{
  return &this->current.i;
}


// ========================================================================
// ?GetAxis@idPhysics_RigidBody3DOF@@UBAABVidMat3@@H@Z
// EA  : 0x8275F8F0
// RVA : 0x0075F8F0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

const idMat3 *__fastcall idPhysics_RigidBody3DOF::GetAxis(idPhysics_RigidBody3DOF *this, int id)
{
  return &this->current.i.orientation;
}


// ========================================================================
// ?GetLinearVelocity@idPhysics_RigidBody3DOF@@UBA?AVidVec3@@H@Z
// EA  : 0x8275F8F8
// RVA : 0x0075F8F8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

idPhysics_RigidBody3DOF *__fastcall idPhysics_RigidBody3DOF::GetLinearVelocity(
        idPhysics_RigidBody3DOF *this,
        idVec3 *result,
        int id)
{
  float x; // r10
  float y; // r9

  x = result[25].x;
  y = result[25].y;
  this->__vftable = (idPhysics_RigidBody3DOF_vtbl *)LODWORD(result[24].z);
  *((float *)&this->__vftable + 1) = x;
  *(float *)&this->type = y;
  return this;
}


// ========================================================================
// ?GetAngularVelocity@idPhysics_RigidBody3DOF@@UBA?AVidVec3@@H@Z
// EA  : 0x8275F918
// RVA : 0x0075F918
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

idPhysics_RigidBody3DOF *__fastcall idPhysics_RigidBody3DOF::GetAngularVelocity(
        idPhysics_RigidBody3DOF *this,
        idVec3 *result,
        int id)
{
  float x; // r10
  float y; // r9

  x = result[26].x;
  y = result[26].y;
  this->__vftable = (idPhysics_RigidBody3DOF_vtbl *)LODWORD(result[25].z);
  *((float *)&this->__vftable + 1) = x;
  *(float *)&this->type = y;
  return this;
}


// ========================================================================
// ?UnlinkClip@idPhysics_RigidBody3DOF@@UAAXXZ
// EA  : 0x8275F938
// RVA : 0x0075F938
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::UnlinkClip(idPhysics_RigidBody3DOF *this)
{
  idClipModel::Unlink(this: this->clipModel);
}


// ========================================================================
// ?GetPushedLinearVelocity@idPhysics_RigidBody3DOF@@UBA?AVidVec3@@H@Z
// EA  : 0x8275F940
// RVA : 0x0075F940
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

idPhysics_RigidBody3DOF *__fastcall idPhysics_RigidBody3DOF::GetPushedLinearVelocity(
        idPhysics_RigidBody3DOF *this,
        idVec3 *result,
        const int id)
{
  float x; // r10
  float y; // r9

  x = result[18].x;
  y = result[18].y;
  this->__vftable = (idPhysics_RigidBody3DOF_vtbl *)LODWORD(result[17].z);
  *((float *)&this->__vftable + 1) = x;
  *(float *)&this->type = y;
  return this;
}


// ========================================================================
// ?GetPushedAngularVelocity@idPhysics_RigidBody3DOF@@UBA?AVidVec3@@H@Z
// EA  : 0x8275F960
// RVA : 0x0075F960
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

idPhysics_RigidBody3DOF *__fastcall idPhysics_RigidBody3DOF::GetPushedAngularVelocity(
        idPhysics_RigidBody3DOF *this,
        idVec3 *result,
        const int id)
{
  float x; // r10
  float y; // r9

  x = result[19].x;
  y = result[19].y;
  this->__vftable = (idPhysics_RigidBody3DOF_vtbl *)LODWORD(result[18].z);
  *((float *)&this->__vftable + 1) = x;
  *(float *)&this->type = y;
  return this;
}


// ========================================================================
// ??0bodyState_t@idPhysics_RigidBody3DOF@@QAA@XZ
// EA  : 0x8275F980
// RVA : 0x0075F980
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

idPhysics_RigidBody3DOF::bodyState_t *__fastcall idPhysics_RigidBody3DOF::bodyState_t::bodyState_t(
        idPhysics_RigidBody3DOF::bodyState_t *this)
{
  float *p_z; // r9
  float *p_y; // r11
  int v3; // ctr
  float *v4; // r10
  float *v5; // r9
  int v6; // ctr

  this->atRest = -1;
  this->lastTimeStep = 0.0;
  p_z = &this->localOrigin.z;
  this->localOrigin.x = 0.0;
  p_y = &mat2_identity.mat[1].y;
  this->localOrigin.y = 0.0;
  v3 = 9;
  this->localOrigin.z = 0.0;
  do
  {
    *++p_z = *++p_y;
    --v3;
  }
  while ( v3 != 0 );
  this->linearPushVelocity.x = 0.0;
  this->linearPushVelocity.y = 0.0;
  this->linearPushVelocity.z = 0.0;
  v4 = &mat2_identity.mat[1].y;
  this->angularPushVelocity.x = 0.0;
  v5 = &this->i.position.z;
  this->angularPushVelocity.y = 0.0;
  this->angularPushVelocity.z = 0.0;
  v6 = 9;
  this->externalForce.x = 0.0;
  this->externalForce.y = 0.0;
  this->externalForce.z = 0.0;
  this->i.position.x = 0.0;
  this->i.position.y = 0.0;
  this->i.position.z = 0.0;
  do
  {
    *++v5 = *++v4;
    --v6;
  }
  while ( v6 != 0 );
  this->i.linearVelocity.x = 0.0;
  this->i.linearVelocity.y = 0.0;
  this->i.linearVelocity.z = 0.0;
  this->i.angularVelocity.x = 0.0;
  this->i.angularVelocity.y = 0.0;
  this->i.angularVelocity.z = 0.0;
  return this;
}


// ========================================================================
// ??0idPhysics_RigidBody3DOF@@QAA@XZ
// EA  : 0x8275FA30
// RVA : 0x0075FA30
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

idPhysics_RigidBody3DOF *__fastcall idPhysics_RigidBody3DOF::idPhysics_RigidBody3DOF(idPhysics_RigidBody3DOF *this)
{
  unsigned __int64 v2; // r6

  idPhysics_DynamicBase::idPhysics_DynamicBase(this);
  this->clipModel = nullptr;
  this->__vftable = (idPhysics_RigidBody3DOF_vtbl *)&idPhysics_RigidBody3DOF::`vftable';
  this->mass = 1.0;
  this->inverseMass = 1.0;
  this->linearFriction = 1.0;
  this->angularFriction = 1.0;
  this->contactFriction = 1.0;
  this->linearFrictionWater = 1.0;
  this->angularFrictionWater = 1.0;
  this->coefficientOfRestitution = 1.0;
  idPhysics_RigidBody3DOF::bodyState_t::bodyState_t(this: &this->current);
  idPhysics_RigidBody3DOF::bodyState_t::bodyState_t(this: &this->saved);
  this->random.seed = v2;
  this->translationQuery.index = v2;
  *(_BYTE *)&this->flags &= 7u;
  this->type = PHYSICS_RIGIDBODY3DOF;
  this->random.seed = v2;
  return this;
}


// ========================================================================
// ?SetFriction@idPhysics_RigidBody3DOF@@QAAXMMM@Z
// EA  : 0x8275FB30
// RVA : 0x0075FB30
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SetFriction(
        idPhysics_RigidBody3DOF *this,
        double linear,
        double angular,
        double contact)
{
  double v4; // fp0

  v4 = angular;
  if ( linear >= 0.0 )
  {
    if ( linear > 1.0 )
      linear = 1.0;
  }
  else
  {
    linear = 0.0;
  }
  this->linearFriction = linear;
  if ( angular >= 0.0 )
  {
    if ( angular > 1.0 )
      v4 = 1.0;
  }
  else
  {
    v4 = 0.0;
  }
  this->angularFriction = v4;
  if ( contact >= 0.0 )
  {
    if ( contact <= 1.0 )
      this->contactFriction = contact;
    else
      this->contactFriction = 1.0;
  }
  else
  {
    this->contactFriction = 0.0;
  }
}


// ========================================================================
// ?SetWaterFriction@idPhysics_RigidBody3DOF@@QAAXMM@Z
// EA  : 0x8275FBB0
// RVA : 0x0075FBB0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SetWaterFriction(idPhysics_RigidBody3DOF *this, double linear, double angular)
{
  if ( linear >= 0.0 )
  {
    if ( linear > 1.0 )
      linear = 1.0;
  }
  else
  {
    linear = 0.0;
  }
  this->linearFrictionWater = linear;
  if ( angular >= 0.0 )
  {
    if ( angular <= 1.0 )
      this->angularFrictionWater = angular;
    else
      this->angularFrictionWater = 1.0;
  }
  else
  {
    this->angularFrictionWater = 0.0;
  }
}


// ========================================================================
// ?SetClipModel@idPhysics_RigidBody3DOF@@UAAXPAVidClipModel@@MH_N@Z
// EA  : 0x8275FC08
// RVA : 0x0075FC08
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SetClipModel(
        idPhysics_RigidBody3DOF *this,
        idClipModel *model,
        double density,
        int id,
        int freeOld,
        char a6)
{
  idClipModel *clipModel; // r3
  float *v11; // r11
  double v12; // fp0
  const char *v13; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr && clipModel != model && a6 != 0 )
    idClipModel::Delete(this: clipModel);
  this->clipModel = model;
  idClipModel::Link(
    this: model,
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: freeOld,
    newOrigin: &this->current.i.position,
    newAxis: &this->current.i.orientation);
  v11 = (float *)this->clipModel;
  if ( v11[20] >= (double)v11[23] || v11[21] >= (double)v11[24] || v11[22] >= (double)v11[25] )
    v12 = 0.0;
  else
    v12 = (float)((float)((float)(v11[25] - v11[22]) * (float)(v11[24] - v11[21])) * (float)(v11[23] - v11[20]));
  ((void (__fastcall *)(idPhysics_RigidBody3DOF *, double))this->SetMass)(
    a1: this,
    a2: (float)((float)v12 * (float)density));
  if ( this->mass <= 0.0 )
  {
    v13 = this->callbacks->GetName(this: this->callbacks);
    idLib::Warning(fmt: "idPhysics_RigidBody3DOF::SetClipModel - invalid mass for entity '%s'.", v13);
    this->mass = 1.0;
  }
  this->current.i.linearVelocity.z = 0.0;
  this->current.i.linearVelocity.y = 0.0;
  this->current.i.linearVelocity.x = 0.0;
  this->current.i.angularVelocity.z = 0.0;
  this->current.i.angularVelocity.y = 0.0;
  this->current.i.angularVelocity.x = 0.0;
}


// ========================================================================
// ?GetContents@idPhysics_RigidBody3DOF@@UBAHH@Z
// EA  : 0x8275FD68
// RVA : 0x0075FD68
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

int __fastcall idPhysics_RigidBody3DOF::GetContents(idPhysics_RigidBody3DOF *this, int id)
{
  return this->clipModel->contents;
}


// ========================================================================
// ?GetBounds@idPhysics_RigidBody3DOF@@UBAABVidBounds@@H@Z
// EA  : 0x8275FD78
// RVA : 0x0075FD78
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_RigidBody3DOF::GetBounds(idPhysics_RigidBody3DOF *this, int id)
{
  return &this->clipModel->bounds;
}


// ========================================================================
// ?GetAbsBounds@idPhysics_RigidBody3DOF@@UBAABVidBounds@@H@Z
// EA  : 0x8275FD88
// RVA : 0x0075FD88
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_RigidBody3DOF::GetAbsBounds(idPhysics_RigidBody3DOF *this, int id)
{
  return &this->clipModel->absBounds;
}


// ========================================================================
// ?CheckForCollisions@idPhysics_RigidBody3DOF@@AAA_NMABUbodyState_t@1@AAU21@AAUtrace_t@@@Z
// EA  : 0x8275FD98
// RVA : 0x0075FD98
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

int __fastcall idPhysics_RigidBody3DOF::CheckForCollisions(
        idPhysics_RigidBody3DOF *this,
        double deltaTime,
        const idPhysics_RigidBody3DOF::bodyState_t *cur,
        idPhysics_RigidBody3DOF::bodyState_t *next,
        trace_t *collision,
        trace_t *a6)
{
  float *p_surfaceFlags; // r27
  double fraction; // fp31
  double x; // fp30
  double y; // fp29
  double z; // fp28
  double v16; // fp11
  double v17; // fp9
  __int64 v18; // r6
  double v19; // fp1
  double v20; // fp0
  double v21; // fp31
  int v22; // r10
  int v23; // r5
  __int64 v24; // r7
  int v25; // r11
  __int64 v26; // r4
  __int64 v27; // r11
  int v28; // r11
  double v29; // fp9
  double v30; // fp8
  int v31; // [sp+8h] [-C8h]
  bool v32; // [sp+Fh] [-C1h]
  const char *v33; // [sp+10h] [-C0h]
  int v34; // [sp+14h] [-BCh]
  int v35; // [sp+18h] [-B8h]
  int v36; // [sp+1Ch] [-B4h]
  int v37; // [sp+20h] [-B0h]
  int v38; // [sp+24h] [-ACh]
  int v39; // [sp+28h] [-A8h]
  int v40; // [sp+2Ch] [-A4h]
  int v41; // [sp+30h] [-A0h]
  int v42; // [sp+34h] [-9Ch]
  int v43; // [sp+38h] [-98h]
  int v44; // [sp+3Ch] [-94h]
  int v45; // [sp+40h] [-90h]
  int v46; // [sp+44h] [-8Ch]
  int v47; // [sp+48h] [-88h]
  int v48; // [sp+4Ch] [-84h]
  int v49; // [sp+50h] [-80h]
  int v50; // [sp+58h] [-78h]
  int v51; // [sp+60h] [-70h]
  idVec3 v52[4]; // [sp+70h] [-60h] BYREF

  p_surfaceFlags = (float *)&collision->c.surfaceFlags;
  idClip::Translation(
    this: (idClip *)v52,
    result: this->clip,
    a3: a6,
    start: &this->current.i.position,
    end: (const idVec3 *)&collision->c.surfaceFlags,
    clipModel: this->clipModel,
    startAxis: &mat3_identity,
    clipMask: this->clipMask,
    passEntityNumber: v31,
    moveClipModel: v32,
    userName: v33,
    a12: v34,
    a13: v35,
    a14: v36,
    a15: v37,
    a16: v38,
    a17: v39,
    a18: v40,
    a19: v41,
    a20: v42,
    a21: v43,
    a22: v44,
    a23: v45,
    a24: v46,
    a25: v47,
    a26: v48,
    a27: v49,
    a28: this->entityNumber,
    a29: v50,
    a30: false,
    a31: v51,
    a32: 0);
  fraction = a6->fraction;
  if ( fraction == 1.0 )
    return 0;
  x = next->i.linearVelocity.x;
  y = next->i.linearVelocity.y;
  z = next->i.linearVelocity.z;
  v16 = (float)(collision[1].endAxis.mat[0].x - next->i.linearVelocity.y);
  v17 = (float)(collision[1].endAxis.mat[0].y - next->i.linearVelocity.z);
  v52[0].x = collision[1].endpos.z - next->i.linearVelocity.x;
  v52[0].y = v16;
  v52[0].z = v17;
  idVec3::FixDenormals(this: v52);
  *p_surfaceFlags = a6->endpos.x;
  p_surfaceFlags[1] = a6->endpos.y;
  p_surfaceFlags[2] = a6->endpos.z;
  v19 = (float)(v52[0].y * (float)fraction);
  v20 = (float)(v52[0].z * (float)fraction);
  collision[1].endpos.z = (float)x + (float)(v52[0].x * (float)fraction);
  collision[1].endAxis.mat[0].x = (float)y + (float)v19;
  collision[1].endAxis.mat[0].y = (float)z + (float)v20;
  if ( (*(_BYTE *)&this->flags & 8) == 0 )
  {
    v21 = __fsqrts((float)((float)(next->i.angularVelocity.z * next->i.angularVelocity.z)
                         + (float)((float)(next->i.angularVelocity.x * next->i.angularVelocity.x)
                                 + (float)(next->i.angularVelocity.y * next->i.angularVelocity.y))));
    if ( v21 <= 0.1 )
    {
      v22 = 1103515245 * this->random.seed + 12345;
      this->random.seed = v22;
      LODWORD(v18) = (v22 >> 16) & 0x7FFF;
      *(_QWORD *)&v52[0].x = v18;
      v21 = (float)((float)v18 * (float)0.0030518509);
    }
    v23 = 1103515245 * this->random.seed + 12345;
    this->random.seed = v23;
    HIDWORD(v24) = v23 >> 16;
    v25 = 1103515245 * v23 + 12345;
    LODWORD(v26) = (v23 >> 16) & 0x7FFF;
    HIDWORD(v26) = v25 >> 16;
    this->random.seed = v25;
    HIDWORD(v27) = this->random.seed;
    LODWORD(v24) = (v25 >> 16) & 0x7FFF;
    v28 = 1103515245 * HIDWORD(v27) + 12345;
    this->random.seed = v28;
    LODWORD(v27) = (v28 >> 16) & 0x7FFF;
    v52[0].z = (float)((float)v26 * (float)0.000030518509) - (float)0.5;
    v52[0].x = (float)((float)v27 * (float)0.000030518509) - (float)0.5;
    v52[0].y = (float)((float)v24 * (float)0.000030518509) - (float)0.5;
    idVec3::NormalizeFast(this: v52);
    v29 = (float)(v52[0].y * (float)v21);
    v30 = (float)(v52[0].z * (float)v21);
    collision[1].endAxis.mat[0].z = v52[0].x * (float)v21;
    collision[1].endAxis.mat[1].x = v29;
    collision[1].endAxis.mat[1].y = v30;
  }
  return 1;
}


// ========================================================================
// ?GetImpactInfo@idPhysics_RigidBody3DOF@@UBAXHABVidVec3@@AAUimpactInfo_t@@@Z
// EA  : 0x82760018
// RVA : 0x00760018
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::GetImpactInfo(
        idPhysics_RigidBody3DOF *this,
        const int id,
        const idVec3 *point,
        impactInfo_t *info)
{
  info->invMass = this->inverseMass;
  info->invInertiaTensor.mat[2].z = 1.0;
  info->invInertiaTensor.mat[1].y = 1.0;
  info->invInertiaTensor.mat[0].x = 1.0;
  info->invInertiaTensor.mat[1].z = 0.0;
  info->invInertiaTensor.mat[0].z = 0.0;
  info->invInertiaTensor.mat[0].y = 0.0;
  info->invInertiaTensor.mat[2].y = 0.0;
  info->invInertiaTensor.mat[2].x = 0.0;
  info->invInertiaTensor.mat[1].x = 0.0;
  info->position = this->current.i.position;
  info->velocity = this->current.i.linearVelocity;
}


// ========================================================================
// ?ApplyImpulse@idPhysics_RigidBody3DOF@@UAAXHABVidVec3@@0@Z
// EA  : 0x82760088
// RVA : 0x00760088
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::ApplyImpulse(
        idPhysics_RigidBody3DOF *this,
        const int id,
        const idVec3 *point,
        const idVec3 *impulse)
{
  double y; // fp11
  double z; // fp8

  y = this->current.i.linearVelocity.y;
  this->current.i.linearVelocity.x = this->current.i.linearVelocity.x + impulse->x;
  z = this->current.i.linearVelocity.z;
  this->current.i.linearVelocity.y = impulse->y + (float)y;
  this->current.i.linearVelocity.z = impulse->z + (float)z;
  ((void (__fastcall *)(idPhysicsCallbacks *, int, const idVec3 *))this->callbacks->ActivatePhysics)(
    a1: this->callbacks,
    a2: this->physicsId,
    a3: point);
}


// ========================================================================
// ?ApplyForce@idPhysics_RigidBody3DOF@@UAAXHABVidVec3@@0@Z
// EA  : 0x827600D8
// RVA : 0x007600D8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::ApplyForce(
        idPhysics_RigidBody3DOF *this,
        const int id,
        const idVec3 *point,
        const idVec3 *force)
{
  double y; // fp11
  double z; // fp8

  y = this->current.externalForce.y;
  this->current.externalForce.x = this->current.externalForce.x + force->x;
  z = this->current.externalForce.z;
  this->current.externalForce.y = force->y + (float)y;
  this->current.externalForce.z = force->z + (float)z;
  ((void (__fastcall *)(idPhysicsCallbacks *, int, const idVec3 *))this->callbacks->ActivatePhysics)(
    a1: this->callbacks,
    a2: this->physicsId,
    a3: point);
}


// ========================================================================
// ?PutToRest@idPhysics_RigidBody3DOF@@UAAXXZ
// EA  : 0x82760128
// RVA : 0x00760128
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::PutToRest(idPhysics_RigidBody3DOF *this)
{
  this->current.atRest = 1;
  this->current.i.linearVelocity.z = 0.0;
  this->current.i.linearVelocity.y = 0.0;
  this->current.i.linearVelocity.x = 0.0;
  this->current.i.angularVelocity.z = 0.0;
  this->current.i.angularVelocity.y = 0.0;
  this->current.i.angularVelocity.x = 0.0;
}


// ========================================================================
// ?SetOrigin@idPhysics_RigidBody3DOF@@UAAXABVidVec3@@H@Z
// EA  : 0x82760158
// RVA : 0x00760158
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SetOrigin(idPhysics_RigidBody3DOF *this, const idVec3 *newOrigin, int id)
{
  idPhysics_RigidBody3DOF::bodyIntState_t *p_i; // r29
  double v6; // fp2
  double v7; // fp9
  double v8; // fp6
  double v9; // fp4
  double v10; // fp3
  float v11; // [sp+50h] [-60h] BYREF
  float v12; // [sp+54h] [-5Ch]
  float v13; // [sp+58h] [-58h]
  float v14[20]; // [sp+60h] [-50h] BYREF

  this->current.i.position = *newOrigin;
  p_i = &this->current.i;
  if ( (*(_BYTE *)&this->flags & 0x20) != 0 )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v11, a3: (idMat3 *)v14);
    v6 = (float)(newOrigin->x - v11);
    v7 = v14[3];
    v8 = v14[6];
    v9 = (float)((float)(v14[4] * (float)(newOrigin->y - v12)) + (float)(v14[5] * (float)(newOrigin->z - v13)));
    v10 = (float)((float)(v14[7] * (float)(newOrigin->y - v12)) + (float)(v14[8] * (float)(newOrigin->z - v13)));
    this->current.localOrigin.x = (float)(v14[0] * (float)(newOrigin->x - v11))
                                + (float)((float)(v14[1] * (float)(newOrigin->y - v12))
                                        + (float)(v14[2] * (float)(newOrigin->z - v13)));
    this->current.localOrigin.y = (float)((float)v7 * (float)v6) + (float)v9;
    this->current.localOrigin.z = (float)((float)v8 * (float)v6) + (float)v10;
  }
  else
  {
    this->current.localOrigin = *newOrigin;
  }
  idClipModel::Link(
    this: this->clipModel,
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: this->clipModel->bodyId,
    newOrigin: &p_i->position,
    newAxis: &this->clipModel->axis);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetAxis@idPhysics_RigidBody3DOF@@UAAXABVidMat3@@H@Z
// EA  : 0x82760288
// RVA : 0x00760288
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SetAxis(
        idPhysics_RigidBody3DOF *this,
        idMat3 *newAxis,
        int id,
        int a4,
        int a5)
{
  _BYTE v7[16]; // [sp+50h] [-B0h] BYREF
  float v8[12]; // [sp+60h] [-A0h] BYREF
  idMat3 v9; // [sp+90h] [-70h] BYREF
  idMat3 v10; // [sp+C0h] [-40h] BYREF

  this->current.i.orientation = *newAxis;
  if ( (*(_BYTE *)&this->flags & 0x20) != 0 && (*(_BYTE *)&this->flags & 0x10) != 0 )
  {
    ((void (__fastcall *)(idPhysicsCallbacks *, _BYTE *, float *, int, int))this->callbacks->GetMasterPosition)(
      a1: this->callbacks,
      a2: v7,
      a3: v8,
      a4,
      a5);
    v9.mat[0].x = v8[0];
    v9.mat[0].y = v8[3];
    v9.mat[0].z = v8[6];
    v9.mat[1].x = v8[1];
    v9.mat[1].y = v8[4];
    v9.mat[1].z = v8[7];
    v9.mat[2].x = v8[2];
    v9.mat[2].y = v8[5];
    v9.mat[2].z = v8[8];
    this->current.localAxis = *idMat3::operator*(this: &v10, result: newAxis, a: &v9);
  }
  else
  {
    this->current.localAxis = *newAxis;
  }
}


// ========================================================================
// ?Translate@idPhysics_RigidBody3DOF@@UAAXABVidVec3@@H@Z
// EA  : 0x82760438
// RVA : 0x00760438
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::Translate(idPhysics_RigidBody3DOF *this, const idVec3 *translation, int id)
{
  idClipModel *clipModel; // r11
  double x; // fp0
  float v6; // r8
  double y; // fp13
  float v8; // r10
  double z; // fp12
  double v10; // fp10
  double v11; // fp13
  double v12; // fp0
  double v13; // fp12
  int v14; // r6
  double v15; // fp2
  double v16; // fp9
  double v17; // fp6
  double v18; // fp4
  double v19; // fp3
  idVec3 v20; // [sp+50h] [-60h] BYREF
  float v21; // [sp+60h] [-50h] BYREF
  float v22; // [sp+64h] [-4Ch]
  float v23; // [sp+68h] [-48h]
  float v24[12]; // [sp+70h] [-40h] BYREF

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
  {
    x = translation->x;
    v6 = clipModel->origin.x;
    y = translation->y;
    v8 = clipModel->origin.y;
    z = translation->z;
    v20.z = clipModel->origin.z;
    v10 = v20.z;
    v20.x = v6;
    v20.y = v8;
    v11 = (float)((float)y + v8);
    this->current.i.position.y = v11;
    v12 = (float)((float)x + v6);
    this->current.i.position.x = v12;
    v13 = (float)((float)z + (float)v10);
    this->current.i.position.z = v13;
    v14 = *(_BYTE *)&this->flags & 0x20;
    v20.x = v12;
    v20.y = v11;
    v20.z = v13;
    if ( v14 != 0 )
    {
      this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v21, a3: (idMat3 *)v24);
      v15 = (float)(v20.x - v21);
      v16 = v24[3];
      v17 = v24[6];
      v18 = (float)((float)(v24[4] * (float)(v20.y - v22)) + (float)(v24[5] * (float)(v20.z - v23)));
      v19 = (float)((float)(v24[7] * (float)(v20.y - v22)) + (float)(v24[8] * (float)(v20.z - v23)));
      this->current.localOrigin.x = (float)(v24[0] * (float)(v20.x - v21))
                                  + (float)((float)(v24[1] * (float)(v20.y - v22))
                                          + (float)(v24[2] * (float)(v20.z - v23)));
      this->current.localOrigin.y = (float)((float)v16 * (float)v15) + (float)v18;
      this->current.localOrigin.z = (float)((float)v17 * (float)v15) + (float)v19;
    }
    else
    {
      this->current.localOrigin.x = v12;
      this->current.localOrigin.y = v11;
      this->current.localOrigin.z = v13;
    }
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: this->clipModel->bodyId,
      newOrigin: &v20,
      newAxis: &this->clipModel->axis);
  }
}


// ========================================================================
// ?Rotate@idPhysics_RigidBody3DOF@@UAAXABVidRotation@@H@Z
// EA  : 0x82760590
// RVA : 0x00760590
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::Rotate(idPhysics_RigidBody3DOF *this, idRotation *rotation, int id)
{
  idClipModel *clipModel; // r11
  char *v6; // r9
  idClipModel *p_z; // r10
  int i; // ctr
  float y; // r9
  float z; // r8
  const idMat3 *v11; // r3
  idRotation *v12; // r3
  double x; // fp0
  double v14; // fp13
  double v15; // fp12
  double v16; // fp11
  double v17; // fp10
  double v18; // fp9
  double v19; // fp8
  double v20; // fp7
  double v21; // fp6
  double v22; // fp5
  double v23; // fp4
  double v24; // fp3
  idPhysics_RigidBody3DOF::simpleBodyFlags_t flags; // r11
  idVec3 *v26; // r3
  double v27; // fp3
  double v28; // fp13
  double v29; // fp6
  double v30; // fp2
  double v31; // fp1
  double v32; // fp9
  double v33; // fp0
  double v34; // fp7
  double v35; // fp8
  double v36; // fp5
  double v37; // fp2
  double v38; // fp6
  double v39; // fp4
  double v40; // fp0
  double v41; // fp3
  double v42; // fp13
  idVec3 v43; // [sp+50h] [-100h] BYREF
  float v44; // [sp+60h] [-F0h] BYREF
  float v45; // [sp+64h] [-ECh]
  float v46; // [sp+68h] [-E8h]
  float v47; // [sp+6Ch] [-E4h]
  float v48; // [sp+70h] [-E0h]
  float v49; // [sp+74h] [-DCh]
  float v50; // [sp+78h] [-D8h]
  float v51; // [sp+7Ch] [-D4h]
  float v52; // [sp+80h] [-D0h]
  char v53; // [sp+8Ch] [-C4h] BYREF
  idMat3 v54; // [sp+90h] [-C0h] BYREF
  float v55[6]; // [sp+B8h] [-98h] BYREF
  idMat3 v56; // [sp+D0h] [-80h] BYREF
  idRotation v57; // [sp+F8h] [-58h] BYREF

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
  {
    v6 = &v53;
    p_z = (idClipModel *)&clipModel->origin.z;
    for ( i = 9; i != 0; --i )
    {
      p_z = (idClipModel *)((char *)p_z + 4);
      v6 += 4;
      *(_DWORD *)v6 = p_z->__vftable;
    }
    y = clipModel->origin.y;
    z = clipModel->origin.z;
    v43.x = clipModel->origin.x;
    v43.y = y;
    v43.z = z;
    v11 = idRotation::ToMat3(this: rotation);
    idMat3::operator*=(this: &v54, a: v11);
    v12 = idRotation::operator*(this: &v57, result: rotation, v: &v43);
    x = v12->origin.x;
    v43.x = v12->origin.x;
    v14 = v12->origin.y;
    v43.y = v12->origin.y;
    v15 = v12->origin.z;
    v16 = v54.mat[0].x;
    this->current.i.orientation.mat[0].x = v54.mat[0].x;
    v17 = v54.mat[1].x;
    v18 = v54.mat[0].y;
    v19 = v54.mat[0].z;
    this->current.i.orientation.mat[1].x = v54.mat[1].x;
    this->current.i.orientation.mat[0].y = v18;
    this->current.i.orientation.mat[0].z = v19;
    v20 = v54.mat[1].y;
    this->current.i.orientation.mat[1].y = v54.mat[1].y;
    v21 = v54.mat[1].z;
    this->current.i.orientation.mat[1].z = v54.mat[1].z;
    v22 = v54.mat[2].x;
    this->current.i.orientation.mat[2].x = v54.mat[2].x;
    v23 = v54.mat[2].y;
    this->current.i.orientation.mat[2].y = v54.mat[2].y;
    v24 = v54.mat[2].z;
    this->current.i.orientation.mat[2].z = v54.mat[2].z;
    this->current.i.position.x = x;
    this->current.i.position.y = v14;
    this->current.i.position.z = v15;
    flags = this->flags;
    v43.z = v15;
    if ( (*(_BYTE *)&flags & 0x20) != 0 && (*(_BYTE *)&flags & 0x10) != 0 )
    {
      this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v55, a3: (idMat3 *)&v44);
      v56.mat[0].x = v44;
      v56.mat[0].y = v47;
      v56.mat[0].z = v50;
      v56.mat[1].x = v45;
      v56.mat[1].y = v48;
      v56.mat[1].z = v51;
      v56.mat[2].x = v46;
      v56.mat[2].y = v49;
      v56.mat[2].z = v52;
      v26 = (idVec3 *)idMat3::operator*(this: (idMat3 *)&v57.angle, result: &v54, a: &v56);
      this->current.localAxis.mat[0].x = v26->x;
      this->current.localAxis.mat[0].y = v26->y;
      this->current.localAxis.mat[0].z = v26->z;
      this->current.localAxis.mat[1] = v26[1];
      this->current.localAxis.mat[2].x = v26[2].x;
      v27 = (float)(v43.z - v55[2]);
      v28 = (float)(v43.y - v55[1]);
      v29 = v46;
      v30 = v49;
      v31 = v52;
      this->current.localAxis.mat[2].y = v26[2].y;
      v32 = v45;
      v33 = (float)((float)v30 * (float)v27);
      v34 = v48;
      v35 = (float)(v43.x - v55[0]);
      v36 = v51;
      v37 = v44;
      this->current.localAxis.mat[2].z = v26[2].z;
      v38 = (float)((float)((float)v32 * (float)v28) + (float)((float)v29 * (float)v27));
      v39 = (float)((float)((float)v34 * (float)v28) + (float)v33);
      v40 = v47;
      v41 = (float)((float)((float)v36 * (float)v28) + (float)((float)v31 * (float)v27));
      v42 = v50;
      this->current.localOrigin.x = (float)((float)v37 * (float)v35) + (float)v38;
      this->current.localOrigin.y = (float)((float)v40 * (float)v35) + (float)v39;
      this->current.localOrigin.z = (float)((float)v42 * (float)v35) + (float)v41;
    }
    else
    {
      this->current.localAxis.mat[0].x = v16;
      this->current.localAxis.mat[1].x = v17;
      this->current.localAxis.mat[0].y = v18;
      this->current.localAxis.mat[0].z = v19;
      this->current.localAxis.mat[1].y = v20;
      this->current.localAxis.mat[1].z = v21;
      this->current.localAxis.mat[2].x = v22;
      this->current.localAxis.mat[2].y = v23;
      this->current.localAxis.mat[2].z = v24;
      this->current.localOrigin.x = x;
      this->current.localOrigin.y = v14;
      this->current.localOrigin.z = v15;
    }
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: this->clipModel->bodyId,
      newOrigin: &v43,
      newAxis: &v54);
  }
}


// ========================================================================
// ?SetLinearVelocity@idPhysics_RigidBody3DOF@@UAAXABVidVec3@@H@Z
// EA  : 0x82760840
// RVA : 0x00760840
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SetLinearVelocity(idPhysics_RigidBody3DOF *this, const idVec3 *lv, int id)
{
  this->current.i.linearVelocity = *lv;
  ((void (__fastcall *)(idPhysicsCallbacks *, int, int))this->callbacks->ActivatePhysics)(
    a1: this->callbacks,
    a2: this->physicsId,
    a3: id);
}


// ========================================================================
// ?SetAngularVelocity@idPhysics_RigidBody3DOF@@UAAXABVidVec3@@H@Z
// EA  : 0x82760870
// RVA : 0x00760870
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SetAngularVelocity(idPhysics_RigidBody3DOF *this, const idVec3 *av, int id)
{
  this->current.i.angularVelocity = *av;
  ((void (__fastcall *)(idPhysicsCallbacks *, int, int))this->callbacks->ActivatePhysics)(
    a1: this->callbacks,
    a2: this->physicsId,
    a3: id);
}


// ========================================================================
// ?DisableClip@idPhysics_RigidBody3DOF@@UAAXXZ
// EA  : 0x827608A0
// RVA : 0x007608A0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::DisableClip(idPhysics_RigidBody3DOF *this)
{
  this->clipModel->enabled = false;
}


// ========================================================================
// ?EnableClip@idPhysics_RigidBody3DOF@@UAAXXZ
// EA  : 0x827608B0
// RVA : 0x007608B0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::EnableClip(idPhysics_RigidBody3DOF *this)
{
  this->clipModel->enabled = true;
}


// ========================================================================
// ?LinkClip@idPhysics_RigidBody3DOF@@UAAXXZ
// EA  : 0x827608C0
// RVA : 0x007608C0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::LinkClip(idPhysics_RigidBody3DOF *this)
{
  idClipModel::Link(
    this: this->clipModel,
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: this->clipModel->bodyId,
    newOrigin: &this->current.i.position,
    newAxis: &this->current.i.orientation);
}


// ========================================================================
// ?SetMaster@idPhysics_RigidBody3DOF@@UAAX_NABVidVec3@@ABVidMat3@@W4bindFlags_t@@@Z
// EA  : 0x827608E0
// RVA : 0x007608E0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SetMaster(
        idPhysics_RigidBody3DOF *this,
        bool enable,
        const idVec3 *masterOrigin,
        const idMat3 *masterAxis,
        const bindFlags_t bflags)
{
  idPhysics_RigidBody3DOF::simpleBodyFlags_t flags; // r11
  char v7; // r30
  double v8; // fp2
  double x; // fp7
  double v10; // fp5
  double v11; // fp1
  double v12; // fp0
  double z; // fp13
  double v14; // fp12
  double y; // fp11
  double v16; // fp10
  double v17; // fp9
  double v18; // fp8
  double v19; // fp7
  double v20; // fp6
  void (__fastcall *ClearContacts)(struct idPhysics_RigidBody3DOF *); // r6
  idPhysicsCallbacks *callbacks; // r3
  int physicsId; // r4
  idMat3 v24; // [sp+50h] [-70h] BYREF
  idMat3 v25; // [sp+80h] [-40h] BYREF

  flags = this->flags;
  v7 = bflags;
  if ( enable )
  {
    if ( (*(_BYTE *)&this->flags & 0x20) == 0 )
    {
      v8 = (float)(this->current.i.position.x - masterOrigin->x);
      x = masterAxis->mat[2].x;
      v10 = masterAxis->mat[1].x;
      v11 = (float)((float)((float)(this->current.i.position.y - masterOrigin->y) * masterAxis->mat[1].y)
                  + (float)((float)(this->current.i.position.z - masterOrigin->z) * masterAxis->mat[1].z));
      v12 = (float)((float)((float)(this->current.i.position.y - masterOrigin->y) * masterAxis->mat[2].y)
                  + (float)((float)(this->current.i.position.z - masterOrigin->z) * masterAxis->mat[2].z));
      this->current.localOrigin.x = (float)((float)(this->current.i.position.x - masterOrigin->x) * masterAxis->mat[0].x)
                                  + (float)((float)((float)(this->current.i.position.y - masterOrigin->y)
                                                  * masterAxis->mat[0].y)
                                          + (float)((float)(this->current.i.position.z - masterOrigin->z)
                                                  * masterAxis->mat[0].z));
      this->current.localOrigin.y = (float)((float)v8 * (float)v10) + (float)v11;
      this->current.localOrigin.z = (float)((float)v8 * (float)x) + (float)v12;
      if ( (bflags & 4) != 0 )
      {
        z = masterAxis->mat[1].z;
        v14 = masterAxis->mat[0].z;
        y = masterAxis->mat[2].y;
        v16 = masterAxis->mat[1].y;
        v17 = masterAxis->mat[0].y;
        v18 = masterAxis->mat[2].x;
        v19 = masterAxis->mat[1].x;
        v20 = masterAxis->mat[0].x;
        v24.mat[2].z = masterAxis->mat[2].z;
        v24.mat[2].y = z;
        v24.mat[2].x = v14;
        v24.mat[1].z = y;
        v24.mat[1].y = v16;
        v24.mat[1].x = v17;
        v24.mat[0].z = v18;
        v24.mat[0].y = v19;
        v24.mat[0].x = v20;
        this->current.localAxis = *idMat3::operator*(this: &v25, result: &this->current.i.orientation, a: &v24);
      }
      else
      {
        this->current.localAxis = this->current.i.orientation;
      }
      ClearContacts = this->ClearContacts;
      this->flags = (idPhysics_RigidBody3DOF::simpleBodyFlags_t)((16 * v7) & 0x10 | 0x20 | *(_BYTE *)&this->flags & 0xEF);
      ClearContacts(this);
    }
  }
  else if ( (*(_BYTE *)&this->flags & 0x20) != 0 )
  {
    callbacks = this->callbacks;
    physicsId = this->physicsId;
    this->flags = (idPhysics_RigidBody3DOF::simpleBodyFlags_t)(*(_BYTE *)&flags & 0xDF);
    ((void (__fastcall *)(idPhysicsCallbacks *, int, const idVec3 *, const idMat3 *))callbacks->ActivatePhysics)(
      a1: callbacks,
      a2: physicsId,
      a3: masterOrigin,
      a4: masterAxis);
  }
}


// ========================================================================
// ?SetLocalOrigin@idPhysics_RigidBody3DOF@@UAAXABVidVec3@@H@Z
// EA  : 0x82760B08
// RVA : 0x00760B08
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SetLocalOrigin(idPhysics_RigidBody3DOF *this, const idVec3 *newOrigin, int id)
{
  double v5; // fp9
  double v6; // fp5
  double v7; // fp2
  double v8; // fp1
  double z; // fp12
  float v10[4]; // [sp+50h] [-50h] BYREF
  float v11[10]; // [sp+60h] [-40h] BYREF

  this->current.localOrigin = *newOrigin;
  if ( (*(_BYTE *)&this->flags & 0x20) != 0 )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v10, a3: (idMat3 *)v11);
    v5 = v10[1];
    v6 = v10[2];
    v7 = (float)((float)(newOrigin->y * v11[4])
               + (float)((float)(newOrigin->x * v11[1]) + (float)(newOrigin->z * v11[7])));
    v8 = (float)((float)(newOrigin->x * v11[2])
               + (float)((float)(newOrigin->z * v11[8]) + (float)(newOrigin->y * v11[5])));
    this->current.i.position.x = (float)((float)(newOrigin->x * v11[0])
                                       + (float)((float)(newOrigin->z * v11[6]) + (float)(newOrigin->y * v11[3])))
                               + v10[0];
    this->current.i.position.y = (float)v5 + (float)v7;
    z = (float)((float)v6 + (float)v8);
  }
  else
  {
    this->current.i.position.x = newOrigin->x;
    this->current.i.position.y = newOrigin->y;
    z = newOrigin->z;
  }
  this->current.i.position.z = z;
  idClipModel::Link(
    this: this->clipModel,
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: this->clipModel->bodyId,
    newOrigin: &this->current.i.position,
    newAxis: &this->clipModel->axis);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetLocalAxis@idPhysics_RigidBody3DOF@@UAAXABVidMat3@@H@Z
// EA  : 0x82760C48
// RVA : 0x00760C48
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SetLocalAxis(
        idPhysics_RigidBody3DOF *this,
        idMat3 *newAxis,
        int id,
        int a4,
        int a5)
{
  idVec3 *v7; // r3
  double z; // fp6
  _BYTE v9[16]; // [sp+50h] [-80h] BYREF
  idMat3 v10; // [sp+60h] [-70h] BYREF
  idMat3 v11; // [sp+90h] [-40h] BYREF

  this->current.localAxis = *newAxis;
  if ( (*(_BYTE *)&this->flags & 0x20) != 0 && (*(_BYTE *)&this->flags & 0x10) != 0 )
  {
    ((void (__fastcall *)(idPhysicsCallbacks *, _BYTE *, idMat3 *, int, int))this->callbacks->GetMasterPosition)(
      a1: this->callbacks,
      a2: v9,
      a3: &v10,
      a4,
      a5);
    v7 = (idVec3 *)idMat3::operator*(this: &v11, result: newAxis, a: &v10);
    this->current.i.orientation.mat[0] = *v7;
    this->current.i.orientation.mat[1] = v7[1];
    this->current.i.orientation.mat[2].x = v7[2].x;
    this->current.i.orientation.mat[2].y = v7[2].y;
    z = v7[2].z;
  }
  else
  {
    this->current.i.orientation.mat[0] = newAxis->mat[0];
    this->current.i.orientation.mat[1] = newAxis->mat[1];
    this->current.i.orientation.mat[2].x = newAxis->mat[2].x;
    this->current.i.orientation.mat[2].y = newAxis->mat[2].y;
    z = newAxis->mat[2].z;
  }
  this->current.i.orientation.mat[2].z = z;
}


// ========================================================================
// ?ClipTranslation@idPhysics_RigidBody3DOF@@UBAXAAUtrace_t@@ABVidVec3@@PBVidClipModel@@@Z
// EA  : 0x82760DB0
// RVA : 0x00760DB0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::ClipTranslation(
        idPhysics_RigidBody3DOF *this,
        trace_t *results,
        const idVec3 *translation,
        idClipModel *model)
{
  double z; // fp0
  idClipModel *clipModel; // r7
  int clipMask; // r9
  idClip *clip; // r3
  double v8; // fp8
  double v9; // fp7
  double x; // fp13
  double y; // fp12
  idClipModel *v13; // r8
  int v14; // r10
  idClip *v15; // r4
  double v16; // fp9
  double v17; // fp6
  const idVec3 *v18; // [sp+8h] [-A8h]
  const idMat3 *v19; // [sp+Ch] [-A4h]
  const char *v20; // [sp+10h] [-A0h]
  int v21; // [sp+14h] [-9Ch]
  int v22; // [sp+18h] [-98h]
  int v23; // [sp+1Ch] [-94h]
  int v24; // [sp+20h] [-90h]
  int v25; // [sp+24h] [-8Ch]
  int v26; // [sp+28h] [-88h]
  int v27; // [sp+2Ch] [-84h]
  int v28; // [sp+30h] [-80h]
  int v29; // [sp+34h] [-7Ch]
  int v30; // [sp+38h] [-78h]
  int v31; // [sp+3Ch] [-74h]
  int v32; // [sp+40h] [-70h]
  int v33; // [sp+44h] [-6Ch]
  int v34; // [sp+48h] [-68h]
  int v35; // [sp+4Ch] [-64h]
  int v36; // [sp+50h] [-60h]
  int entityNumber; // [sp+54h] [-5Ch]
  int v38; // [sp+58h] [-58h]
  int v39; // [sp+60h] [-50h]
  char v40; // [sp+70h] [-40h] BYREF
  idVec3 v41; // [sp+78h] [-38h] BYREF
  idVec3 v42; // [sp+88h] [-28h] BYREF

  z = translation->z;
  if ( model != nullptr )
  {
    clipModel = this->clipModel;
    clipMask = this->clipMask;
    clip = this->clip;
    v8 = (float)(clipModel->origin.z + translation->z);
    v9 = (float)(clipModel->origin.y + translation->y);
    v41.x = translation->x + clipModel->origin.x;
    v41.z = v8;
    v41.y = v9;
    idClip::TranslationModel(
      this: clip,
      result: results,
      start: &clipModel->origin,
      end: &v41,
      trm: clipModel,
      trmAxis: &clipModel->axis,
      clipMask,
      model,
      modelOrigin: v18,
      modelAxis: v19,
      a11: (int)v20,
      a12: v21,
      a13: v22,
      a14: v23,
      a15: v24,
      a16: v25,
      a17: v26,
      a18: v27,
      a19: v28,
      a20: v29,
      a21: v30,
      a22: v31,
      a23: v32,
      a24: v33,
      a25: v34,
      a26: v35,
      a27: v36,
      a28: &model->origin.x,
      a29: v38,
      a30: (float *)&model->axis);
  }
  else
  {
    x = translation->x;
    y = translation->y;
    v13 = this->clipModel;
    v14 = this->clipMask;
    entityNumber = this->entityNumber;
    v15 = this->clip;
    v16 = (float)(v13->origin.z + (float)z);
    v17 = (float)(v13->origin.y + (float)y);
    v42.x = v13->origin.x + (float)x;
    v42.z = v16;
    v42.y = v17;
    idClip::Translation(
      this: (idClip *)&v40,
      result: v15,
      a3: results,
      start: &v13->origin,
      end: &v42,
      clipModel: v13,
      startAxis: &v13->axis,
      clipMask: v14,
      passEntityNumber: (int)v18,
      moveClipModel: (bool)v19,
      userName: v20,
      a12: v21,
      a13: v22,
      a14: v23,
      a15: v24,
      a16: v25,
      a17: v26,
      a18: v27,
      a19: v28,
      a20: v29,
      a21: v30,
      a22: v31,
      a23: v32,
      a24: v33,
      a25: v34,
      a26: v35,
      a27: v36,
      a28: entityNumber,
      a29: v38,
      a30: false,
      a31: v39,
      a32: 0);
  }
}


// ========================================================================
// ?ClipRotation@idPhysics_RigidBody3DOF@@UBAXAAUtrace_t@@ABVidRotation@@PBVidClipModel@@@Z
// EA  : 0x82760EB8
// RVA : 0x00760EB8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::ClipRotation(
        idPhysics_RigidBody3DOF *this,
        trace_t *results,
        idRotation *rotation,
        idClipModel *model)
{
  const idVec3 *v4; // [sp+8h] [-88h]
  const idMat3 *v5; // [sp+Ch] [-84h]
  const char *v6; // [sp+10h] [-80h]
  int v7; // [sp+14h] [-7Ch]
  int v8; // [sp+18h] [-78h]
  int v9; // [sp+1Ch] [-74h]
  int v10; // [sp+20h] [-70h]
  int v11; // [sp+24h] [-6Ch]
  int v12; // [sp+28h] [-68h]
  int v13; // [sp+2Ch] [-64h]
  int v14; // [sp+30h] [-60h]
  int v15; // [sp+34h] [-5Ch]
  int v16; // [sp+38h] [-58h]
  int v17; // [sp+3Ch] [-54h]
  int v18; // [sp+40h] [-50h]
  int v19; // [sp+44h] [-4Ch]
  int v20; // [sp+48h] [-48h]
  int v21; // [sp+4Ch] [-44h]
  int v22; // [sp+50h] [-40h]
  int v23; // [sp+58h] [-38h]
  int v24; // [sp+60h] [-30h]
  char v25; // [sp+70h] [-20h] BYREF

  if ( model != nullptr )
    idClip::RotationModel(
      this: this->clip,
      result: results,
      start: (const idMat3 *)&this->clipModel->origin,
      rotation,
      trm: this->clipModel,
      trmAxis: &this->clipModel->axis,
      clipMask: (const idVec3 *)this->clipMask,
      model,
      modelOrigin: v4,
      modelAxis: v5,
      a11: (int)v6,
      a12: v7,
      a13: v8,
      a14: v9,
      a15: v10,
      a16: v11,
      a17: v12,
      a18: v13,
      a19: v14,
      a20: v15,
      a21: v16,
      a22: v17,
      a23: v18,
      a24: v19,
      a25: v20,
      a26: v21,
      a27: v22,
      a28: &model->origin.x,
      a29: v23,
      a30: (float *)&model->axis);
  else
    idClip::Rotation(
      this: (idClip *)&v25,
      result: this->clip,
      a3: results,
      start: (const idMat3 *)&this->clipModel->origin,
      rotation,
      clipModel: this->clipModel,
      startAxis: &this->clipModel->axis,
      clipMask: this->clipMask,
      passEntityNumber: (int)v4,
      moveClipModel: (bool)v5,
      userName: v6,
      a12: v7,
      a13: v8,
      a14: v9,
      a15: v10,
      a16: v11,
      a17: v12,
      a18: v13,
      a19: v14,
      a20: v15,
      a21: v16,
      a22: v17,
      a23: v18,
      a24: v19,
      a25: v20,
      a26: v21,
      a27: v22,
      a28: this->entityNumber,
      a29: v23,
      a30: false,
      a31: v24,
      a32: 0);
}


// ========================================================================
// ?CollisionImpulse@idPhysics_RigidBody3DOF@@AAA_NAAUtrace_t@@MAAUbodyState_t@1@AAVidVec3@@@Z
// EA  : 0x827610C0
// RVA : 0x007610C0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

BOOL __fastcall idPhysics_RigidBody3DOF::CollisionImpulse(
        idPhysics_RigidBody3DOF *this,
        trace_t *collision,
        double timeStep,
        idPhysics_RigidBody3DOF::bodyState_t *postImpactState,
        idVec3 *impulse,
        float *a6)
{
  idPhysics_RigidBody3DOF *PhysicsForId; // r3
  float *p_z; // r11
  double v13; // fp9
  double z; // fp13
  double v15; // fp8
  double y; // fp12
  double v17; // fp10
  double x; // fp11
  double v19; // fp4
  double v20; // fp0
  double v21; // fp3
  double contactFriction; // fp1
  double v23; // fp2
  double v24; // fp13
  double v25; // fp10
  double v26; // fp8
  double v27; // fp13
  double v28; // fp0
  double v29; // fp12
  double v30; // fp8
  double v31; // fp6
  double v32; // fp11
  double v33; // fp13
  double v34; // fp6
  double coefficientOfRestitution; // fp5
  double v36; // fp3
  float v38[4]; // [sp+50h] [-80h] BYREF
  impactInfo_t v39; // [sp+60h] [-70h] BYREF

  PhysicsForId = (idPhysics_RigidBody3DOF *)idPhysics::GetPhysicsForId(physicsId_: collision->c.physicsId);
  if ( PhysicsForId == nullptr || PhysicsForId == this )
    impactInfo_t::Zero(this: &v39);
  else
    PhysicsForId->GetImpactInfo(this: PhysicsForId, a2: collision->c.bodyId, a3: &collision->c.point, a4: &v39);
  p_z = &impulse[11].z;
  v13 = (float)(impulse[12].y - v39.velocity.z);
  z = collision->c.normal.z;
  v15 = (float)(impulse[12].x - v39.velocity.y);
  y = collision->c.normal.y;
  v17 = (float)(impulse[11].z - v39.velocity.x);
  x = collision->c.normal.x;
  v38[2] = impulse[12].y - v39.velocity.z;
  v38[0] = v17;
  v38[1] = v15;
  v19 = (float)((float)z
              * (float)-(float)((float)((float)x * (float)v17)
                              + (float)((float)((float)y * (float)v15) + (float)((float)z * (float)v13))));
  if ( (float)-(float)((float)((float)x * (float)v17)
                     + (float)((float)((float)y * (float)v15) + (float)((float)z * (float)v13))) >= 10.0 )
    v20 = (float)((float)(this->coefficientOfRestitution + (float)1.0)
                * (float)-(float)((float)((float)x * (float)v17)
                                + (float)((float)((float)y * (float)v15) + (float)((float)z * (float)v13))));
  else
    v20 = 5.0;
  v21 = (float)((float)z * (float)v20);
  a6[2] = (float)z * (float)v20;
  *a6 = (float)x * (float)v20;
  a6[1] = (float)y * (float)v20;
  contactFriction = this->contactFriction;
  v23 = (float)((float)((float)y
                      * (float)-(float)((float)((float)x * (float)v17)
                                      + (float)((float)((float)y * (float)v15) + (float)((float)z * (float)v13))))
              + (float)v15);
  v24 = -(float)((float)((float)x
                       * (float)-(float)((float)((float)x * (float)v17)
                                       + (float)((float)((float)y * (float)v15) + (float)((float)z * (float)v13))))
               + (float)v17);
  v25 = -(float)((float)v19 + (float)v13);
  v26 = (float)((float)((float)v24 * this->contactFriction) + (float)((float)x * (float)v20));
  *a6 = (float)((float)v24 * this->contactFriction) + (float)((float)x * (float)v20);
  v27 = (float)((float)((float)-v23 * (float)contactFriction) + (float)((float)y * (float)v20));
  a6[1] = (float)((float)-v23 * (float)contactFriction) + (float)((float)y * (float)v20);
  a6[2] = (float)((float)v25 * (float)contactFriction) + (float)v21;
  v28 = idMath::FLT_SMALLEST_NON_DENORMAL;
  if ( __fabs(v26) <= idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    *a6 = 0.0;
    v28 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  if ( __fabs(v27) <= v28 )
  {
    a6[1] = 0.0;
    v28 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  if ( __fabs((float)((float)((float)v25 * (float)contactFriction) + (float)v21)) <= v28 )
    a6[2] = 0.0;
  v29 = (float)(*p_z + *a6);
  *p_z = *p_z + *a6;
  v30 = (float)(impulse[12].x + a6[1]);
  impulse[12].x = impulse[12].x + a6[1];
  v31 = (float)(impulse[12].y + a6[2]);
  impulse[12].y = impulse[12].y + a6[2];
  v32 = (float)(this->gravityVector.x * (float)timeStep);
  v33 = (float)(this->gravityVector.z * (float)timeStep);
  impulse[12].x = (float)v30 + (float)(this->gravityVector.y * (float)timeStep);
  *p_z = (float)v29 + (float)v32;
  impulse[12].y = (float)v31 + (float)v33;
  v34 = impulse[13].x;
  coefficientOfRestitution = this->coefficientOfRestitution;
  v36 = (float)(impulse[13].y * this->coefficientOfRestitution);
  impulse[12].z = impulse[12].z * this->coefficientOfRestitution;
  impulse[13].x = (float)v34 * (float)coefficientOfRestitution;
  impulse[13].y = v36;
  return (_cntlzw(
            this->callbacks->Collide(this: this->callbacks, a2: this->physicsId, a3: collision, a4: (const idVec3 *)v38)
          - 1)
        & 0x20) != 0;
}


// ========================================================================
// ?SaveState@idPhysics_RigidBody3DOF@@UAAXXZ
// EA  : 0x82761320
// RVA : 0x00761320
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SaveState(idPhysics_RigidBody3DOF *this)
{
  idPhysics_RigidBody3DOF::bodyState_t::operator=(this: &this->saved, __that: &this->current);
}


// ========================================================================
// ?RestoreState@idPhysics_RigidBody3DOF@@UAAXXZ
// EA  : 0x82761330
// RVA : 0x00761330
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::RestoreState(idPhysics_RigidBody3DOF *this)
{
  idPhysics_RigidBody3DOF::bodyState_t::operator=(this: &this->current, __that: &this->saved);
  idClipModel::Link(
    this: this->clipModel,
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: this->clipModel->bodyId,
    newOrigin: &this->current.i.position,
    newAxis: &this->current.i.orientation);
}


// ========================================================================
// ?SetPushed@idPhysics_RigidBody3DOF@@UAAXH@Z
// EA  : 0x82761380
// RVA : 0x00761380
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::SetPushed(idPhysics_RigidBody3DOF *this, unsigned int deltaTime)
{
  idRotation *v4; // r3
  idRotation *v5; // r3
  double v6; // fp7
  double y; // fp3
  double z; // fp2
  double v9; // fp5
  double v10; // fp4
  double v11; // fp3
  double x; // fp2
  double v13; // fp9
  double v14; // fp8
  idMat3 v15; // [sp+60h] [-90h] BYREF
  idMat3 v16[2]; // [sp+90h] [-60h] BYREF

  v4 = (idRotation *)idMat3::operator*(this: &v15, result: &this->saved.i.orientation, a: &this->current.i.orientation);
  v5 = idMat3::ToRotation(this: v16, result: v4);
  v6 = (float)(v5->angle * idMath::M_DEG2RAD);
  y = this->current.angularPushVelocity.y;
  z = this->current.angularPushVelocity.z;
  v9 = (float)((float)(v5->vec.y * (float)-v6)
             * (float)((float)1.0 / (float)((float)__SPAIR64__(&si_vector_decode_cat_0[184], deltaTime) * (float)0.001)));
  v10 = (float)((float)(v5->vec.z * (float)-v6)
              * (float)((float)1.0 / (float)((float)__SPAIR64__(&si_vector_decode_cat_0[184], deltaTime) * (float)0.001)));
  this->current.angularPushVelocity.x = this->current.angularPushVelocity.x
                                      + (float)((float)((float)1.0
                                                      / (float)((float)__SPAIR64__(
                                                                         &si_vector_decode_cat_0[184],
                                                                         deltaTime)
                                                              * (float)0.001))
                                              * (float)(v5->vec.x * (float)-v6));
  this->current.angularPushVelocity.y = (float)y + (float)v9;
  this->current.angularPushVelocity.z = (float)z + (float)v10;
  v11 = this->current.linearPushVelocity.z;
  x = this->current.linearPushVelocity.x;
  v13 = (float)((float)((float)1.0 / (float)((float)__SPAIR64__(&si_vector_decode_cat_0[184], deltaTime) * (float)0.001))
              * (float)(this->current.i.position.x - this->saved.i.position.x));
  v14 = (float)((float)(this->current.i.position.z - this->saved.i.position.z)
              * (float)((float)1.0 / (float)((float)__SPAIR64__(&si_vector_decode_cat_0[184], deltaTime) * (float)0.001)));
  this->current.linearPushVelocity.y = this->current.linearPushVelocity.y
                                     + (float)((float)(this->current.i.position.y - this->saved.i.position.y)
                                             * (float)((float)1.0
                                                     / (float)((float)__SPAIR64__(
                                                                        &si_vector_decode_cat_0[184],
                                                                        deltaTime)
                                                             * (float)0.001)));
  this->current.linearPushVelocity.x = (float)x + (float)v13;
  this->current.linearPushVelocity.z = (float)v11 + (float)v14;
}


// ========================================================================
// ?ClipContents@idPhysics_RigidBody3DOF@@UBAHPBVidClipModel@@H@Z
// EA  : 0x827614C0
// RVA : 0x007614C0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

int __fastcall idPhysics_RigidBody3DOF::ClipContents(idPhysics_RigidBody3DOF *this, idClipModel *model, int clipMask_)
{
  int clipMask; // r8
  int v5; // r9
  const idMat3 *v6; // [sp+8h] [-F8h]
  int v7; // [sp+Ch] [-F4h]
  int v8; // [sp+10h] [-F0h]
  int v9; // [sp+14h] [-ECh]
  int v10; // [sp+18h] [-E8h]
  int v11; // [sp+1Ch] [-E4h]
  int v12; // [sp+20h] [-E0h]
  int v13; // [sp+24h] [-DCh]
  int v14; // [sp+28h] [-D8h]
  int v15; // [sp+2Ch] [-D4h]
  int v16; // [sp+30h] [-D0h]
  int v17; // [sp+34h] [-CCh]
  int v18; // [sp+38h] [-C8h]
  int v19; // [sp+3Ch] [-C4h]
  int v20; // [sp+40h] [-C0h]
  int v21; // [sp+44h] [-BCh]
  int v22; // [sp+48h] [-B8h]
  int v23; // [sp+4Ch] [-B4h]
  int v24; // [sp+50h] [-B0h]
  char v25; // [sp+60h] [-A0h] BYREF
  trace_t v26; // [sp+70h] [-90h] BYREF

  if ( model != nullptr )
  {
    clipMask = clipMask_;
    if ( clipMask_ == 0 )
      clipMask = this->clipMask;
    idClip::ContentsModel(
      this: this->clip,
      result: &v26,
      start: &this->clipModel->origin,
      trm: this->clipModel,
      trmAxis: &this->clipModel->axis,
      clipMask,
      model,
      modelOrigin: &model->origin,
      modelAxis: v6,
      a10: v7,
      a11: v8,
      a12: v9,
      a13: v10,
      a14: v11,
      a15: v12,
      a16: v13,
      a17: v14,
      a18: v15,
      a19: v16,
      a20: v17,
      a21: v18,
      a22: v19,
      a23: v20,
      a24: v21,
      a25: v22,
      a26: v23,
      a27: v24,
      a28: (float *)&model->axis);
    return v26.c.contentFlags;
  }
  else
  {
    v5 = clipMask_;
    if ( clipMask_ == 0 )
      v5 = this->clipMask;
    idClip::Contents(
      this: (idClip *)&v25,
      result: this->clip,
      a3: &v26,
      start: &this->clipModel->origin,
      clipModel: this->clipModel,
      startAxis: &this->clipModel->axis,
      clipMask: v5,
      passEntityNumber: 0x1FFF,
      userName: (const char *)v6,
      a10: v7,
      a11: v8,
      a12: v9,
      a13: v10,
      a14: v11,
      a15: v12,
      a16: v13,
      a17: v14,
      a18: v15,
      a19: v16,
      a20: v17,
      a21: v18,
      a22: v19,
      a23: v20,
      a24: v21,
      a25: v22,
      a26: v23,
      a27: v24,
      a28: 0);
    return v26.c.contentFlags;
  }
}


// ========================================================================
// ?Integrate@idPhysics_RigidBody3DOF@@ABAXMABUbodyState_t@1@AAU21@@Z
// EA  : 0x82761570
// RVA : 0x00761570
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody3DOF::Integrate(
        idPhysics_RigidBody3DOF *this,
        double deltaTime,
        const idPhysics_RigidBody3DOF::bodyState_t *cur,
        idPhysics_RigidBody3DOF::bodyState_t *next,
        idPhysics_RigidBody3DOF::bodyState_t *a5)
{
  double x; // fp2
  double y; // fp1
  double v11; // fp13
  double v12; // fp12
  double v13; // fp11
  double z; // fp0
  double v17; // fp7
  double v18; // fp8
  double v19; // fp7
  double v20; // fp31
  double v21; // fp29
  double v22; // fp28
  double v23; // fp27
  const idMat3 *v24; // r3
  double v25; // fp13
  double v26; // fp10
  double v27; // fp9
  double v28; // fp8
  double v29; // fp7
  double v30; // fp6
  double v31; // fp11
  double v32; // fp9
  double v33; // fp4
  idRotation v34; // [sp+60h] [-90h] BYREF
  idVec3 angularVelocity; // 0:^50.12

  idPhysics_RigidBody3DOF::bodyState_t::operator=(this: a5, __that: next);
  x = a5->i.position.x;
  y = a5->i.position.y;
  v11 = (float)((float)((float)deltaTime * next->i.linearVelocity.x)
              + (float)(this->current.externalForce.x * (float)deltaTime));
  v12 = (float)((float)(next->i.linearVelocity.y * (float)deltaTime)
              + (float)(this->current.externalForce.y * (float)deltaTime));
  v13 = (float)((float)(next->i.linearVelocity.z * (float)deltaTime)
              + (float)(this->current.externalForce.z * (float)deltaTime));
  v34.axisValid = false;
  z = a5->i.position.z;
  a5->i.position.x = (float)x + (float)v11;
  a5->i.position.y = (float)y + (float)v12;
  a5->i.position.z = (float)z + (float)v13;
  angularVelocity = next->i.angularVelocity;
  v34.origin.x = vec3_origin.x;
  v34.origin.y = vec3_origin.y;
  v34.axis.mat[0].x = mat3_identity.mat[0].x;
  v34.origin.z = vec3_origin.z;
  _FP10 = (float)((float)((float)(angularVelocity.x * angularVelocity.x)
                        + (float)((float)(angularVelocity.z * angularVelocity.z)
                                + (float)(angularVelocity.y * angularVelocity.y)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  v34.axis.mat[0].y = mat3_identity.mat[0].y;
  v34.axis.mat[0].z = mat3_identity.mat[0].z;
  v34.axis.mat[1].x = mat3_identity.mat[1].x;
  v34.axis.mat[1].y = mat3_identity.mat[1].y;
  v34.axis.mat[1].z = mat3_identity.mat[1].z;
  v34.axis.mat[2].x = mat3_identity.mat[2].x;
  v34.axis.mat[2].y = mat3_identity.mat[2].y;
  v34.axis.mat[2].z = mat3_identity.mat[2].z;
  __asm { fsel      f8, f10, f29, f0 }
  v17 = __frsqrte(_FP8);
  v18 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)((float)(angularVelocity.x * angularVelocity.x) + (float)((float)(angularVelocity.z * angularVelocity.z) + (float)(angularVelocity.y * angularVelocity.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17)
                                              * (float)((float)((float)(angularVelocity.x * angularVelocity.x)
                                                              + (float)((float)(angularVelocity.z * angularVelocity.z)
                                                                      + (float)(angularVelocity.y * angularVelocity.y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                              * (float)((float)((float)(angularVelocity.x * angularVelocity.x)
                                                                                              + (float)((float)(angularVelocity.z * angularVelocity.z) + (float)(angularVelocity.y * angularVelocity.y)))
                                                                                      * (float)0.5))
                                                                      * (float)v17)
                                                              - (float)1.5)
                                              * (float)v17))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v17
                                                      * (float)((float)((float)(angularVelocity.x * angularVelocity.x)
                                                                      + (float)((float)(angularVelocity.z
                                                                                      * angularVelocity.z)
                                                                              + (float)(angularVelocity.y
                                                                                      * angularVelocity.y)))
                                                              * (float)0.5))
                                              * (float)v17)
                                      - (float)1.5)
                      * (float)v17));
  v19 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                              * (float)((float)((float)(angularVelocity.x * angularVelocity.x) + (float)((float)(angularVelocity.z * angularVelocity.z) + (float)(angularVelocity.y * angularVelocity.y))) * (float)0.5))
                                                                                      * (float)v17)
                                                                              - (float)1.5)
                                                              * (float)v17)
                                                      * (float)((float)((float)(angularVelocity.x * angularVelocity.x)
                                                                      + (float)((float)(angularVelocity.z
                                                                                      * angularVelocity.z)
                                                                              + (float)(angularVelocity.y
                                                                                      * angularVelocity.y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)((float)(angularVelocity.x * angularVelocity.x) + (float)((float)(angularVelocity.z * angularVelocity.z) + (float)(angularVelocity.y * angularVelocity.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v17
                                                              * (float)((float)((float)(angularVelocity.x
                                                                                      * angularVelocity.x)
                                                                              + (float)((float)(angularVelocity.z
                                                                                              * angularVelocity.z)
                                                                                      + (float)(angularVelocity.y
                                                                                              * angularVelocity.y)))
                                                                      * (float)0.5))
                                                      * (float)v17)
                                              - (float)1.5)
                              * (float)v17))
              * (float)((float)((float)(angularVelocity.x * angularVelocity.x)
                              + (float)((float)(angularVelocity.z * angularVelocity.z)
                                      + (float)(angularVelocity.y * angularVelocity.y)))
                      * (float)0.5));
  v20 = (float)((float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18)
              * (float)((float)(angularVelocity.x * angularVelocity.x)
                      + (float)((float)(angularVelocity.z * angularVelocity.z)
                              + (float)(angularVelocity.y * angularVelocity.y))));
  v21 = (float)(angularVelocity.x * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18));
  v34.vec.x = angularVelocity.x * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18);
  v22 = (float)(angularVelocity.y * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18));
  v34.vec.y = angularVelocity.y * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18);
  v23 = (float)(angularVelocity.z * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18));
  v34.vec.z = angularVelocity.z * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18);
  v34.angle = (float)(idMath::M_RAD2DEG
                    * (float)((float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18)
                            * (float)((float)(angularVelocity.x * angularVelocity.x)
                                    + (float)((float)(angularVelocity.z * angularVelocity.z)
                                            + (float)(angularVelocity.y * angularVelocity.y)))))
            * (float)deltaTime;
  v24 = idRotation::ToMat3(this: &v34);
  idMat3::operator*=(this: &a5->i.orientation, a: v24);
  v25 = (float)(this->gravityVector.z * (float)deltaTime);
  v26 = (float)(this->gravityVector.x * (float)deltaTime);
  v27 = a5->i.linearVelocity.z;
  v28 = a5->i.linearVelocity.x;
  v29 = (float)(a5->i.linearVelocity.y + (float)(this->gravityVector.y * (float)deltaTime));
  a5->i.linearVelocity.y = a5->i.linearVelocity.y + (float)(this->gravityVector.y * (float)deltaTime);
  v30 = (float)((float)v27 + (float)v25);
  a5->i.linearVelocity.z = (float)v27 + (float)v25;
  a5->i.linearVelocity.x = (float)v28 + (float)v26;
  v31 = (float)((float)((float)v27 + (float)v25) * this->linearFriction);
  v32 = (float)((float)((float)v28 + (float)v26) * this->linearFriction);
  a5->i.linearVelocity.y = (float)v29 - (float)((float)v29 * this->linearFriction);
  a5->i.linearVelocity.z = (float)v30 - (float)v31;
  a5->i.linearVelocity.x = (float)((float)v28 + (float)v26) - (float)v32;
  v33 = (float)-(float)((float)(this->angularFriction * (float)v20) - (float)v20);
  a5->i.angularVelocity.x = (float)v21 * (float)-(float)((float)(this->angularFriction * (float)v20) - (float)v20);
  a5->i.angularVelocity.y = (float)v22 * (float)v33;
  a5->i.angularVelocity.z = (float)v23 * (float)v33;
}


// ========================================================================
// ?Evaluate@idPhysics_RigidBody3DOF@@UAA_NHH@Z
// EA  : 0x827617F0
// RVA : 0x007617F0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody3dof.cpp
// ========================================================================

int __fastcall idPhysics_RigidBody3DOF::Evaluate(
        idPhysics_RigidBody3DOF *this,
        unsigned int timeStepMSec,
        int endTimeMSec)
{
  int flags; // r11
  double v5; // fp31
  float y; // r7
  idMat3 *p_orientation; // r29
  float z; // r6
  char *v9; // r10
  idPhysics_RigidBody3DOF::bodyIntState_t *p_i; // r30
  float *p_z; // r11
  int v12; // ctr
  double v13; // fp9
  double x; // fp5
  double v15; // fp2
  double v16; // fp1
  idVec3 *v17; // r3
  double v18; // fp6
  double v19; // fp30
  double v20; // fp29
  double v21; // fp2
  double v22; // fp28
  double v23; // fp31
  double v24; // fp0
  double v25; // fp13
  idMat3 *v26; // r3
  idVec3 *v27; // r3
  double v28; // fp5
  double v29; // fp4
  char v30; // r11
  char v31; // r3
  unsigned __int8 v32; // r11
  const idPhysics_RigidBody3DOF::bodyState_t *v34; // r4
  const idPhysics_RigidBody3DOF::bodyState_t *v35; // r4
  char v36; // r29
  idPhysics_RigidBody3DOF::bodyState_t *v37; // r5
  double v38; // fp1
  double v39; // fp12
  double v40; // fp11
  idPhysics *PhysicsForId; // r3
  idPhysicsCallbacks *callbacks; // r3
  idMat3 v43; // [sp+50h] [-260h] BYREF
  float v44; // [sp+74h] [-23Ch]
  float v45; // [sp+78h] [-238h]
  char v46; // [sp+7Ch] [-234h] BYREF
  idMat3 v47; // [sp+80h] [-230h] BYREF
  idMat3 v48; // [sp+B0h] [-200h] BYREF
  idMat3 v49; // [sp+E0h] [-1D0h] BYREF
  trace_t v50; // [sp+110h] [-1A0h] BYREF
  idMat3 v51; // [sp+190h] [-120h] BYREF
  idPhysics_RigidBody3DOF::bodyState_t v52; // [sp+1C0h] [-F0h] BYREF

  *(_QWORD *)&v43.mat[0].x = __PAIR64__(&unk_82390000, timeStepMSec);
  flags = (unsigned __int8)this->flags;
  v5 = (float)((float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001);
  this->current.lastTimeStep = (float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001;
  if ( (flags & 0x20) != 0 )
  {
    y = this->current.i.position.y;
    p_orientation = &this->current.i.orientation;
    z = this->current.i.position.z;
    v9 = &v46;
    p_i = &this->current.i;
    p_z = &this->current.i.position.z;
    v12 = 9;
    v43.mat[0].x = this->current.i.position.x;
    v43.mat[0].y = y;
    v43.mat[0].z = z;
    do
    {
      ++p_z;
      v9 += 4;
      *(float *)v9 = *p_z;
      --v12;
    }
    while ( v12 != 0 );
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v43.mat[1].y, a3: &v49);
    v13 = v43.mat[1].z;
    x = v43.mat[2].x;
    v15 = (float)((float)(this->current.localOrigin.y * v49.mat[1].y)
                + (float)((float)(this->current.localOrigin.x * v49.mat[0].y)
                        + (float)(this->current.localOrigin.z * v49.mat[2].y)));
    v16 = (float)((float)(this->current.localOrigin.z * v49.mat[2].z)
                + (float)((float)(this->current.localOrigin.x * v49.mat[0].z)
                        + (float)(this->current.localOrigin.y * v49.mat[1].z)));
    p_i->position.x = (float)((float)(this->current.localOrigin.x * v49.mat[0].x)
                            + (float)((float)(this->current.localOrigin.z * v49.mat[2].x)
                                    + (float)(this->current.localOrigin.y * v49.mat[1].x)))
                    + v43.mat[1].y;
    p_i->position.y = (float)v13 + (float)v15;
    p_i->position.z = (float)x + (float)v16;
    if ( (*(_BYTE *)&this->flags & 0x10) != 0 )
    {
      v17 = (idVec3 *)idMat3::operator*(this: &v48, result: &this->current.localAxis, a: &v49);
      p_orientation->mat[0] = *v17;
      p_orientation->mat[1] = v17[1];
      p_orientation->mat[2].x = v17[2].x;
      p_orientation->mat[2].y = v17[2].y;
      v18 = v17[2].z;
    }
    else
    {
      p_orientation->mat[0].x = this->current.localAxis.mat[0].x;
      p_orientation->mat[0].y = this->current.localAxis.mat[0].y;
      p_orientation->mat[0].z = this->current.localAxis.mat[0].z;
      p_orientation->mat[1].x = this->current.localAxis.mat[1].x;
      p_orientation->mat[1].y = this->current.localAxis.mat[1].y;
      p_orientation->mat[1].z = this->current.localAxis.mat[1].z;
      p_orientation->mat[2].x = this->current.localAxis.mat[2].x;
      p_orientation->mat[2].y = this->current.localAxis.mat[2].y;
      v18 = this->current.localAxis.mat[2].z;
    }
    p_orientation->mat[2].z = v18;
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: this->clipModel->bodyId,
      newOrigin: &p_i->position,
      newAxis: p_orientation);
    v19 = v43.mat[0].x;
    v20 = v43.mat[0].y;
    v21 = (float)(p_i->position.x - v43.mat[0].x);
    v22 = v43.mat[0].z;
    v23 = (float)((float)1.0 / (float)v5);
    v24 = (float)(p_i->position.y - v43.mat[0].y);
    v25 = (float)(p_i->position.z - v43.mat[0].z);
    v48.mat[0].x = v47.mat[0].x;
    v48.mat[0].y = v47.mat[1].x;
    v48.mat[0].z = v47.mat[2].x;
    v48.mat[1].x = v47.mat[0].y;
    v48.mat[1].y = v47.mat[1].y;
    v48.mat[1].z = v47.mat[2].y;
    v48.mat[2].x = v47.mat[0].z;
    v48.mat[2].y = v47.mat[1].z;
    v48.mat[2].z = v47.mat[2].z;
    this->current.i.linearVelocity.x = (float)v23 * (float)v21;
    this->current.i.linearVelocity.y = (float)v24 * (float)v23;
    this->current.i.linearVelocity.z = (float)v25 * (float)v23;
    v26 = idMat3::operator*(this: &v51, result: p_orientation, a: &v48);
    v27 = idMat3::ToAngularVelocity(this: &v43, result: v26->mat);
    v28 = (float)(v27->y * (float)v23);
    v29 = (float)(v27->z * (float)v23);
    this->current.i.angularVelocity.x = v27->x * (float)v23;
    this->current.i.angularVelocity.y = v28;
    this->current.i.angularVelocity.z = v29;
    this->current.externalForce.z = 0.0;
    this->current.externalForce.y = 0.0;
    this->current.externalForce.x = 0.0;
    if ( p_i->position.x != v19 || p_i->position.y != v20 || (v30 = 1, p_i->position.z != v22) )
      v30 = 0;
    if ( v30 == 0 )
      return 1;
    v31 = idMat3::Compare(this: p_orientation, a: &v47);
    v32 = 0;
    if ( v31 == 0 )
      return 1;
    return v32;
  }
  else if ( this->current.atRest >= 0 || v5 <= 0.0 )
  {
    return 0;
  }
  else if ( (flags & 0xFFFFFF80) != 0 )
  {
    this->callbacks->DeactivatePhysics(this: this->callbacks, a2: this->physicsId);
    this->current.externalForce.z = 0.0;
    this->current.externalForce.y = 0.0;
    this->current.externalForce.x = 0.0;
    return 1;
  }
  else
  {
    idClipModel::Unlink(this: this->clipModel);
    idPhysics_RigidBody3DOF::bodyState_t::bodyState_t(this: &v52);
    idPhysics_RigidBody3DOF::Integrate(this, deltaTime: v5, cur: v34, next: &this->current, a5: &v52);
    v36 = idPhysics_RigidBody3DOF::CheckForCollisions(
            this,
            deltaTime: v5,
            cur: v35,
            next: &this->current,
            collision: (trace_t *)&v52,
            a6: &v50);
    idPhysics_RigidBody3DOF::bodyState_t::operator=(this: &this->current, __that: &v52);
    v43.mat[0] = vec3_origin;
    if ( v36 != 0 )
    {
      if ( idPhysics_RigidBody3DOF::CollisionImpulse(
             this,
             collision: &v50,
             timeStep: v5,
             postImpactState: v37,
             impulse: (idVec3 *)&this->current,
             a6: (float *)&v43)
        || (v38 = (float)(this->current.i.linearVelocity.y
                        - (float)(this->gravityNormal.y
                                * (float)((float)(this->current.i.linearVelocity.z * this->gravityNormal.z)
                                        + (float)((float)(this->current.i.linearVelocity.x * this->gravityNormal.x)
                                                + (float)(this->current.i.linearVelocity.y * this->gravityNormal.y))))),
            v39 = (float)(this->current.i.linearVelocity.z
                        - (float)(this->gravityNormal.z
                                * (float)((float)(this->current.i.linearVelocity.z * this->gravityNormal.z)
                                        + (float)((float)(this->current.i.linearVelocity.x * this->gravityNormal.x)
                                                + (float)(this->current.i.linearVelocity.y * this->gravityNormal.y))))),
            v40 = (float)(this->current.i.linearVelocity.x
                        - (float)(this->gravityNormal.x
                                * (float)((float)(this->current.i.linearVelocity.z * this->gravityNormal.z)
                                        + (float)((float)(this->current.i.linearVelocity.x * this->gravityNormal.x)
                                                + (float)(this->current.i.linearVelocity.y * this->gravityNormal.y))))),
            __fsqrts((float)((float)((float)v40 * (float)v40)
                           + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38)))) <= 10.0)
        && __fabs((float)((float)(this->current.i.linearVelocity.z * this->gravityNormal.z)
                        + (float)((float)(this->current.i.linearVelocity.x * this->gravityNormal.x)
                                + (float)(this->current.i.linearVelocity.y * this->gravityNormal.y)))) < 20.0 )
      {
        this->callbacks->DeactivatePhysics(this: this->callbacks, a2: this->physicsId);
      }
    }
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: this->clipModel->bodyId,
      newOrigin: &this->current.i.position,
      newAxis: &this->current.i.orientation);
    if ( v36 != 0 )
    {
      PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: v50.c.physicsId);
      if ( PhysicsForId != nullptr )
      {
        callbacks = PhysicsForId->callbacks;
        v45 = -v43.mat[0].z;
        v44 = -v43.mat[0].y;
        v43.mat[2].z = -v43.mat[0].x;
        callbacks->ApplyImpulse(
          this: callbacks,
          a2: this->physicsId,
          a3: v50.c.bodyId,
          a4: &v50.c.point,
          a5: (const idVec3 *)&v43.mat[2].z);
      }
    }
    this->current.linearPushVelocity.z = 0.0;
    this->current.linearPushVelocity.y = 0.0;
    this->current.linearPushVelocity.x = 0.0;
    this->current.angularPushVelocity.z = 0.0;
    this->current.angularPushVelocity.y = 0.0;
    this->current.angularPushVelocity.x = 0.0;
    this->current.externalForce.z = 0.0;
    this->current.externalForce.y = 0.0;
    this->current.externalForce.x = 0.0;
    if ( this->IsOutsideWorld(this) )
      this->callbacks->DeactivatePhysics(this: this->callbacks, a2: this->physicsId);
    return 1;
  }
}

