
// ========================================================================
// ??1idPhysics_RigidBody@@UAA@XZ
// EA  : 0x8275B238
// RVA : 0x0075B238
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::~idPhysics_RigidBody(idPhysics_RigidBody *this)
{
  idClipModel *clipModel; // r3

  this->__vftable = (idPhysics_RigidBody_vtbl *)&idPhysics_RigidBody::`vftable';
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
  {
    idClipModel::Delete(this: clipModel);
    this->clipModel = nullptr;
  }
  idPhysics_DynamicBase::~idPhysics_DynamicBase(this);
}


// ========================================================================
// __unwind$246927
// EA  : 0x8275B29C
// RVA : 0x0075B29C
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void _unwind_246927()
{
  int v0; // r12

  idPhysics_DynamicBase::~idPhysics_DynamicBase(this: *(idPhysics_DynamicBase **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetMass@idPhysics_RigidBody@@UBAMH@Z
// EA  : 0x8275B2C8
// RVA : 0x0075B2C8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

float __fastcall idPhysics_RigidBody::GetMass(idPhysics_RigidBody *this, int id)
{
  double mass; // fp1

  mass = this->mass;
  return *((float *)&mass + 1);
}


// ========================================================================
// ?SetFriction@idPhysics_RigidBody@@QAAXMMM@Z
// EA  : 0x8275B2D0
// RVA : 0x0075B2D0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetFriction(
        idPhysics_RigidBody *this,
        double linear,
        double angular,
        double contact)
{
  if ( linear >= 0.0 && linear <= 1.0 && angular >= 0.0 && angular <= 1.0 && contact >= 0.0 && contact <= 1.0 )
  {
    this->linearFriction = linear;
    this->angularFriction = angular;
    this->contactFriction = contact;
  }
}


// ========================================================================
// ?SetBouncyness@idPhysics_RigidBody@@QAAXM@Z
// EA  : 0x8275B320
// RVA : 0x0075B320
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetBouncyness(idPhysics_RigidBody *this, double b)
{
  if ( b >= 0.0 && b <= 1.0 )
    this->bouncyness = b;
}


// ========================================================================
// ?SetContents@idPhysics_RigidBody@@UAAXHH@Z
// EA  : 0x8275B348
// RVA : 0x0075B348
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetContents(idPhysics_RigidBody *this, int contents, int id)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::SetContents(this: clipModel, newContents: contents);
}


// ========================================================================
// ?Activate@idPhysics_RigidBody@@UAAXXZ
// EA  : 0x8275B360
// RVA : 0x0075B360
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::Activate(idPhysics_RigidBody *this)
{
  this->current.atRest = -1;
}


// ========================================================================
// ?IsAtRest@idPhysics_RigidBody@@UBA_NXZ
// EA  : 0x8275B370
// RVA : 0x0075B370
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

BOOL __fastcall idPhysics_RigidBody::IsAtRest(idPhysics_RigidBody *this)
{
  return this->current.atRest >= 0;
}


// ========================================================================
// ?IsPushable@idPhysics_RigidBody@@UBA_NH@Z
// EA  : 0x8275B380
// RVA : 0x0075B380
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

int __fastcall idPhysics_RigidBody::IsPushable(idPhysics_RigidBody *this, int sourceContentType)
{
  unsigned __int8 v2; // r11

  if ( (this->fl.noPushMask & sourceContentType) != 0 )
    return 0;
  if ( (*((_BYTE *)&this->fl + 4) & 0x20) != 0 )
    return 0;
  v2 = 1;
  if ( (*((_BYTE *)&this->fl + 4) & 0x10) != 0 )
    return 0;
  return v2;
}


// ========================================================================
// ?UnlinkClip@idPhysics_RigidBody@@UAAXXZ
// EA  : 0x8275B3C0
// RVA : 0x0075B3C0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::UnlinkClip(idPhysics_RigidBody *this)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Unlink(this: clipModel);
}


// ========================================================================
// ?LinkClip@idPhysics_RigidBody@@UAAXXZ
// EA  : 0x8275B3D8
// RVA : 0x0075B3D8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::LinkClip(idPhysics_RigidBody *this)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(this: clipModel);
}


// ========================================================================
// ?CapVelocity@idPhysics_RigidBody@@AAAXXZ
// EA  : 0x8275B450
// RVA : 0x0075B450
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::CapVelocity(idPhysics_RigidBody *this)
{
  double v1; // fp13
  double v3; // fp6
  double v4; // fp5
  double v6; // fp3
  double v7; // fp3
  double v8; // fp13
  double v9; // fp11
  double v11; // fp7
  double v12; // fp6
  double v14; // fp4
  double v15; // fp5
  double v16; // fp4
  double v17; // fp1

  v1 = (float)((float)(this->current.spatialVelocity.p[2] * this->current.spatialVelocity.p[2])
             + (float)((float)(this->current.spatialVelocity.p[0] * this->current.spatialVelocity.p[0])
                     + (float)(this->current.spatialVelocity.p[1] * this->current.spatialVelocity.p[1])));
  if ( v1 > 25000000.0 )
  {
    _FP8 = (float)((float)((float)(this->current.spatialVelocity.p[2] * this->current.spatialVelocity.p[2])
                         + (float)((float)(this->current.spatialVelocity.p[0] * this->current.spatialVelocity.p[0])
                                 + (float)(this->current.spatialVelocity.p[1] * this->current.spatialVelocity.p[1])))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v3 = this->current.spatialVelocity.p[1];
    v4 = this->current.spatialVelocity.p[2];
    __asm { fsel      f4, f8, f13, f12 }
    v6 = __frsqrte(_FP4);
    v7 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6
                                                                                       * (float)((float)v1 * (float)0.5))
                                                                               * (float)v6)
                                                                       - (float)1.5)
                                                       * (float)v6)
                                               * (float)((float)v1 * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v6
                                                                               * (float)((float)v1 * (float)0.5))
                                                                       * (float)v6)
                                                               - (float)1.5)
                                               * (float)v6))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v6 * (float)((float)v1 * (float)0.5)) * (float)v6)
                                       - (float)1.5)
                       * (float)v6));
    v8 = (float)((float)-(float)((float)((float)((float)v7
                                               * (float)((float)((float)(this->current.spatialVelocity.p[2]
                                                                       * this->current.spatialVelocity.p[2])
                                                               + (float)((float)(this->current.spatialVelocity.p[0]
                                                                               * this->current.spatialVelocity.p[0])
                                                                       + (float)(this->current.spatialVelocity.p[1]
                                                                               * this->current.spatialVelocity.p[1])))
                                                       * (float)0.5))
                                       * (float)v7)
                               - (float)1.5)
               * (float)v7);
    this->current.spatialVelocity.p[0] = (float)((float)((float)-(float)((float)((float)((float)v7
                                                                                       * (float)((float)((float)(this->current.spatialVelocity.p[2] * this->current.spatialVelocity.p[2]) + (float)((float)(this->current.spatialVelocity.p[0] * this->current.spatialVelocity.p[0]) + (float)(this->current.spatialVelocity.p[1] * this->current.spatialVelocity.p[1])))
                                                                                               * (float)0.5))
                                                                               * (float)v7)
                                                                       - (float)1.5)
                                                       * (float)v7)
                                               * (float)5000.0)
                                       * this->current.spatialVelocity.p[0];
    this->current.spatialVelocity.p[1] = (float)v3 * (float)((float)v8 * (float)5000.0);
    this->current.spatialVelocity.p[2] = (float)((float)v8 * (float)5000.0) * (float)v4;
  }
  if ( (float)((float)(this->current.spatialVelocity.p[5] * this->current.spatialVelocity.p[5])
             + (float)((float)(this->current.spatialVelocity.p[3] * this->current.spatialVelocity.p[3])
                     + (float)(this->current.spatialVelocity.p[4] * this->current.spatialVelocity.p[4]))) > (double)(float)(MAX_ANGULAR_VELOCITY * MAX_ANGULAR_VELOCITY) )
  {
    v9 = (float)((float)((float)(this->current.spatialVelocity.p[5] * this->current.spatialVelocity.p[5])
                       + (float)((float)(this->current.spatialVelocity.p[3] * this->current.spatialVelocity.p[3])
                               + (float)(this->current.spatialVelocity.p[4] * this->current.spatialVelocity.p[4])))
               * (float)0.5);
    _FP9 = (float)((float)((float)(this->current.spatialVelocity.p[5] * this->current.spatialVelocity.p[5])
                         + (float)((float)(this->current.spatialVelocity.p[3] * this->current.spatialVelocity.p[3])
                                 + (float)(this->current.spatialVelocity.p[4] * this->current.spatialVelocity.p[4])))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v11 = this->current.spatialVelocity.p[4];
    v12 = this->current.spatialVelocity.p[5];
    __asm { fsel      f5, f9, f13, f12 }
    v14 = __frsqrte(_FP5);
    v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)v9)
                                                                                * (float)v14)
                                                                        - (float)1.5)
                                                        * (float)v14)
                                                * (float)v9)
                                        * (float)((float)-(float)((float)((float)((float)v14 * (float)v9) * (float)v14)
                                                                - (float)1.5)
                                                * (float)v14))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v14 * (float)v9) * (float)v14) - (float)1.5)
                        * (float)v14));
    v16 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)v9)
                                                                                        * (float)v14)
                                                                                - (float)1.5)
                                                                * (float)v14)
                                                        * (float)v9)
                                                * (float)((float)-(float)((float)((float)((float)v14 * (float)v9)
                                                                                * (float)v14)
                                                                        - (float)1.5)
                                                        * (float)v14))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v14 * (float)v9) * (float)v14) - (float)1.5)
                                * (float)v14))
                * (float)v9);
    v17 = (float)((float)((float)-(float)((float)((float)v16 * (float)v15) - (float)1.5) * (float)v15)
                * MAX_ANGULAR_VELOCITY);
    this->current.spatialVelocity.p[3] = this->current.spatialVelocity.p[3]
                                       * (float)((float)((float)-(float)((float)((float)v16 * (float)v15) - (float)1.5)
                                                       * (float)v15)
                                               * MAX_ANGULAR_VELOCITY);
    this->current.spatialVelocity.p[4] = (float)v11 * (float)v17;
    this->current.spatialVelocity.p[5] = (float)v12 * (float)v17;
  }
}


// ========================================================================
// ?TestIfAtRest@idPhysics_RigidBody@@ABA_NXZ
// EA  : 0x8275B5A0
// RVA : 0x0075B5A0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

int __fastcall idPhysics_RigidBody::TestIfAtRest(idPhysics_RigidBody *this)
{
  int num; // r9
  int v3; // r6
  int v4; // r8
  double v5; // fp9
  double v6; // fp8
  double v7; // fp7
  contactInfo_t *list; // r7
  idVec3 *p_gravityNormal; // r30
  int v10; // r10
  float *p_x; // r11
  double v12; // fp1
  double v13; // fp12
  double v14; // fp9
  double v17; // fp7
  double v18; // fp2
  double v19; // fp8
  double v20; // fp3
  int v21; // r26
  int v22; // r28
  double x; // fp12
  contactInfo_t *v24; // r11
  double z; // fp11
  double v26; // fp8
  double v27; // fp3
  double v28; // fp2
  float *clipModel; // r11
  double y; // fp11
  double v31; // fp10
  double v32; // fp12
  double v33; // fp8
  double v34; // fp0
  double v35; // fp2
  double v36; // fp0
  double v37; // fp1
  double v38; // fp12
  double v39; // fp11
  float v41; // [sp+50h] [-5A0h]
  float v42; // [sp+54h] [-59Ch]
  float v43; // [sp+58h] [-598h]
  idVec3 v44; // [sp+60h] [-590h] BYREF
  idVec3 v45; // [sp+70h] [-580h] BYREF
  idFixedWinding v46; // [sp+80h] [-570h] BYREF

  if ( this->current.atRest >= 0 )
    return 1;
  v3 = 0;
  v4 = 0;
  num = this->contacts.num;
  v5 = 0.0;
  v6 = 0.0;
  v7 = 0.0;
  if ( num <= 0 )
    return 0;
  list = this->contacts.list;
  p_gravityNormal = &this->gravityNormal;
  v10 = 0;
  do
  {
    p_x = &list[v10].normal.x;
    if ( (float)((float)(this->gravityNormal.x * *p_x)
               + (float)((float)(list[v10].normal.y * this->gravityNormal.y)
                       + (float)(list[v10].normal.z * this->gravityNormal.z))) < 0.0 )
    {
      v5 = (float)(*p_x + (float)v5);
      ++v3;
      v7 = (float)(list[v10].normal.z + (float)v7);
      v6 = (float)(list[v10].normal.y + (float)v6);
    }
    ++v4;
    ++v10;
  }
  while ( v4 < num );
  if ( v3 < 3 )
    return 0;
  v12 = (float)((float)v6 * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, num)));
  v13 = (float)((float)v7 * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, num)));
  v14 = (float)((float)((float)1.0 / (float)__SPAIR64__(0x82000000, num)) * (float)v5);
  _FP2 = (float)((float)((float)((float)v14 * (float)v14)
                       + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f8, f2, f3, f13 }
  v17 = __frsqrte(_FP8);
  v18 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))
                                                                                              * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17)
                                              * (float)((float)((float)((float)v14 * (float)v14)
                                                              + (float)((float)((float)v13 * (float)v13)
                                                                      + (float)((float)v12 * (float)v12)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                              * (float)((float)((float)((float)v14 * (float)v14)
                                                                                              + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))
                                                                                      * (float)0.5))
                                                                      * (float)v17)
                                                              - (float)1.5)
                                              * (float)v17))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v17
                                                      * (float)((float)((float)((float)v14 * (float)v14)
                                                                      + (float)((float)((float)v13 * (float)v13)
                                                                              + (float)((float)v12 * (float)v12)))
                                                              * (float)0.5))
                                              * (float)v17)
                                      - (float)1.5)
                      * (float)v17));
  v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                              * (float)v17)
                                                                                      * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                      * (float)v17))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                                              * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5))
                                                                                      * (float)v17)
                                                                              - (float)1.5)
                                                              * (float)v17))
                                              * (float)((float)((float)((float)v14 * (float)v14)
                                                              + (float)((float)((float)v13 * (float)v13)
                                                                      + (float)((float)v12 * (float)v12)))
                                                      * (float)0.5))
                                      * (float)v18)
                              - (float)1.5)
              * (float)v18);
  v20 = (float)((float)v12
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17)
                                                                                              * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                              * (float)v17))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5))
                                                                                              * (float)v17)
                                                                                      - (float)1.5)
                                                                      * (float)v17))
                                                      * (float)((float)((float)((float)v14 * (float)v14)
                                                                      + (float)((float)((float)v13 * (float)v13)
                                                                              + (float)((float)v12 * (float)v12)))
                                                              * (float)0.5))
                                              * (float)v18)
                                      - (float)1.5)
                      * (float)v18));
  if ( (float)((float)(this->gravityNormal.x * (float)((float)v19 * (float)v14))
             + (float)((float)((float)v20 * this->gravityNormal.y)
                     + (float)((float)((float)v13
                                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17) * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5)) * (float)v17) - (float)1.5) * (float)v17)) - (float)1.5)
                                                                                     * (float)((float)-(float)((float)((float)((float)v17 * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) * (float)0.5)) * (float)v17) - (float)1.5)
                                                                                             * (float)v17))
                                                                             * (float)((float)((float)((float)v14 * (float)v14)
                                                                                             + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))
                                                                                     * (float)0.5))
                                                                     * (float)v18)
                                                             - (float)1.5)
                                             * (float)v18))
                             * this->gravityNormal.z))) > -0.69999999 )
    return 0;
  v46.p = v46.data;
  v46.__vftable = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
  v46.allocedSize = 64;
  v21 = 0;
  v46.numPoints = 0;
  v22 = 0;
  do
  {
    x = p_gravityNormal->x;
    if ( (float)((float)(this->contacts.list[v22].normal.x * p_gravityNormal->x)
               + (float)((float)(this->contacts.list[v22].normal.y * p_gravityNormal->y)
                       + (float)(this->contacts.list[v22].normal.z * p_gravityNormal->z))) < 0.0 )
    {
      v24 = &this->contacts.list[v22];
      z = v24->point.z;
      v26 = v24->point.x;
      v27 = (float)((float)(p_gravityNormal->x * v24->point.x)
                  + (float)((float)(v24->point.y * p_gravityNormal->y) + (float)(v24->point.z * p_gravityNormal->z)));
      v28 = (float)((float)((float)(p_gravityNormal->x * v24->point.x)
                          + (float)((float)(v24->point.y * p_gravityNormal->y)
                                  + (float)(v24->point.z * p_gravityNormal->z)))
                  * p_gravityNormal->z);
      v44.y = v24->point.y
            - (float)((float)((float)(p_gravityNormal->x * v24->point.x)
                            + (float)((float)(v24->point.y * p_gravityNormal->y)
                                    + (float)(v24->point.z * p_gravityNormal->z)))
                    * p_gravityNormal->y);
      v44.z = (float)z - (float)v28;
      v44.x = (float)v26 - (float)((float)x * (float)v27);
      idWinding::AddToConvexHull(this: &v46, point: &v44, normal: p_gravityNormal, epsilon: 0.1);
    }
    ++v21;
    ++v22;
  }
  while ( v21 < this->contacts.num );
  if ( v46.numPoints >= 3 )
  {
    clipModel = (float *)this->clipModel;
    y = p_gravityNormal->y;
    v31 = p_gravityNormal->x;
    v33 = (float)(clipModel[10]
                + (float)((float)(clipModel[19] * this->centerOfMass.z)
                        + (float)((float)(clipModel[13] * this->centerOfMass.x)
                                + (float)(clipModel[16] * this->centerOfMass.y))));
    v34 = (float)((float)((float)((float)(clipModel[10]
                                        + (float)((float)(clipModel[19] * this->centerOfMass.z)
                                                + (float)((float)(clipModel[13] * this->centerOfMass.x)
                                                        + (float)(clipModel[16] * this->centerOfMass.y))))
                                * p_gravityNormal->z)
                        + (float)((float)((float)(clipModel[8]
                                                + (float)((float)(this->centerOfMass.x * clipModel[11])
                                                        + (float)((float)(clipModel[14] * this->centerOfMass.y)
                                                                + (float)(clipModel[17] * this->centerOfMass.z))))
                                        * p_gravityNormal->x)
                                + (float)((float)(clipModel[9]
                                                + (float)((float)(clipModel[18] * this->centerOfMass.z)
                                                        + (float)((float)(clipModel[12] * this->centerOfMass.x)
                                                                + (float)(clipModel[15] * this->centerOfMass.y))))
                                        * (float)y)))
                * (float)y);
    v32 = (float)(clipModel[9]
                + (float)((float)(clipModel[18] * this->centerOfMass.z)
                        + (float)((float)(clipModel[12] * this->centerOfMass.x)
                                + (float)(clipModel[15] * this->centerOfMass.y))));
    v35 = (float)((float)((float)((float)(clipModel[10]
                                        + (float)((float)(clipModel[19] * this->centerOfMass.z)
                                                + (float)((float)(clipModel[13] * this->centerOfMass.x)
                                                        + (float)(clipModel[16] * this->centerOfMass.y))))
                                * p_gravityNormal->z)
                        + (float)((float)((float)(clipModel[8]
                                                + (float)((float)(this->centerOfMass.x * clipModel[11])
                                                        + (float)((float)(clipModel[14] * this->centerOfMass.y)
                                                                + (float)(clipModel[17] * this->centerOfMass.z))))
                                        * p_gravityNormal->x)
                                + (float)((float)(clipModel[9]
                                                + (float)((float)(clipModel[18] * this->centerOfMass.z)
                                                        + (float)((float)(clipModel[12] * this->centerOfMass.x)
                                                                + (float)(clipModel[15] * this->centerOfMass.y))))
                                        * p_gravityNormal->y)))
                * p_gravityNormal->z);
    v45.x = (float)(clipModel[8]
                  + (float)((float)(this->centerOfMass.x * clipModel[11])
                          + (float)((float)(clipModel[14] * this->centerOfMass.y)
                                  + (float)(clipModel[17] * this->centerOfMass.z))))
          - (float)((float)((float)((float)(clipModel[10]
                                          + (float)((float)(clipModel[19] * this->centerOfMass.z)
                                                  + (float)((float)(clipModel[13] * this->centerOfMass.x)
                                                          + (float)(clipModel[16] * this->centerOfMass.y))))
                                  * p_gravityNormal->z)
                          + (float)((float)((float)(clipModel[8]
                                                  + (float)((float)(this->centerOfMass.x * clipModel[11])
                                                          + (float)((float)(clipModel[14] * this->centerOfMass.y)
                                                                  + (float)(clipModel[17] * this->centerOfMass.z))))
                                          * (float)v31)
                                  + (float)((float)(clipModel[9]
                                                  + (float)((float)(clipModel[18] * this->centerOfMass.z)
                                                          + (float)((float)(clipModel[12] * this->centerOfMass.x)
                                                                  + (float)(clipModel[15] * this->centerOfMass.y))))
                                          * p_gravityNormal->y)))
                  * (float)v31);
    v45.y = (float)v32 - (float)v34;
    v45.z = (float)v33 - (float)v35;
    if ( idWinding::PointInside(this: &v46, normal: p_gravityNormal, point: &v45, epsilon: 0.0) )
    {
      v42 = this->current.spatialVelocity.p[1];
      v41 = this->current.spatialVelocity.p[0];
      v43 = this->current.spatialVelocity.p[2];
      v36 = (float)((float)(v41 * p_gravityNormal->x)
                  + (float)((float)(v42 * p_gravityNormal->y) + (float)(v43 * p_gravityNormal->z)));
      v37 = (float)(v42
                  - (float)(p_gravityNormal->y
                          * (float)((float)(v41 * p_gravityNormal->x)
                                  + (float)((float)(v42 * p_gravityNormal->y) + (float)(v43 * p_gravityNormal->z)))));
      v38 = (float)(v41
                  - (float)(p_gravityNormal->x
                          * (float)((float)(v41 * p_gravityNormal->x)
                                  + (float)((float)(v42 * p_gravityNormal->y) + (float)(v43 * p_gravityNormal->z)))));
      v39 = (float)(v43
                  - (float)(p_gravityNormal->z
                          * (float)((float)(v41 * p_gravityNormal->x)
                                  + (float)((float)(v42 * p_gravityNormal->y) + (float)(v43 * p_gravityNormal->z)))));
      if ( __fsqrts((float)((float)((float)v39 * (float)v39)
                          + (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)))) > 20.0
        || v36 > 40.0
        || v36 < -40.0
        || (float)((float)(this->current.spatialVelocity.p[5] * this->current.spatialVelocity.p[5])
                 + (float)((float)(this->current.spatialVelocity.p[3] * this->current.spatialVelocity.p[3])
                         + (float)(this->current.spatialVelocity.p[4] * this->current.spatialVelocity.p[4]))) > 20.0 )
      {
        idFixedWinding::~idFixedWinding(this: &v46);
        return 0;
      }
      idFixedWinding::~idFixedWinding(this: &v46);
      return 1;
    }
  }
  v46.p = nullptr;
  v46.__vftable = (idFixedWinding_vtbl *)&idWinding::`vftable';
  idMem::Free(this: &mem, ptr: nullptr, align: ALIGN_16);
  return 0;
}


// ========================================================================
// __unwind$248026
// EA  : 0x8275BA6C
// RVA : 0x0075BA6C
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void _unwind_248026()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 1520 + 128));
}


// ========================================================================
// ?DebugDraw@idPhysics_RigidBody@@AAAXXZ
// EA  : 0x8275BA98
// RVA : 0x0075BA98
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::DebugDraw(idPhysics_RigidBody *this)
{
  idRenderWorld *v2; // r3
  __int64 v3; // r10
  __int64 v4; // r6
  idRenderWorld *v5; // r26
  idVec3 *p_origin; // r28
  __int64 v7; // r8
  va *v8; // r3
  idRenderWorld *v9; // r28
  idVec3 *v10; // r29
  __int64 v11; // r8
  __int128 v12; // r6
  va *v13; // r3
  int v14; // [sp+8h] [-10A8h]
  int v15; // [sp+Ch] [-10A4h]
  int v16; // [sp+10h] [-10A0h]
  int v17; // [sp+14h] [-109Ch]
  int v18; // [sp+18h] [-1098h]
  int v19; // [sp+1Ch] [-1094h]
  double mass; // [sp+20h] [-1090h]
  double y; // [sp+28h] [-1088h]
  double z; // [sp+30h] [-1080h]
  double x; // [sp+38h] [-1078h]
  va v24; // [sp+70h] [-1040h] BYREF

  if ( rb_showBodies.valueInteger != 0 || rb_showActive.valueInteger != 0 && this->current.atRest < 0 )
    idClip::DrawSingleClipModel(
      this: this->clip,
      clipModel: this->clipModel,
      origin: &this->clipModel->origin,
      axis: &this->clipModel->axis,
      lifeTime: 0);
  if ( rb_showMass.valueInteger != 0 )
  {
    v2 = common->RW(this: common);
    HIDWORD(v3) = &unk_821F0000;
    mass = this->mass;
    HIDWORD(v4) = LODWORD(mass);
    v5 = v2;
    p_origin = &this->clipModel->origin;
    v8 = va::va(
           this: &v24,
           fmt: "\n%1.2f",
           a3: v4,
           a4: v7,
           a5: v3,
           a6: v14,
           a7: v15,
           a8: v16,
           a9: v17,
           a10: v18,
           a11: v19);
    ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v5->DebugText)(
      a1: v5,
      a2: v8,
      a3: p_origin,
      a4: v5->DebugText,
      a5: &idColor::colorCyan,
      a6: 1,
      a7: 0,
      a8: 0,
      a9: 0.079999998);
  }
  if ( rb_showInertia.valueInteger != 0 )
  {
    v9 = common->RW(this: common);
    v10 = &this->clipModel->origin;
    x = this->inertiaTensor.mat[1].x;
    LODWORD(v11) = LODWORD(x);
    z = this->inertiaTensor.mat[0].z;
    HIDWORD(v11) = LODWORD(z);
    y = this->inertiaTensor.mat[0].y;
    LODWORD(v12) = LODWORD(y);
    *(double *)((char *)&v12 + 4) = this->inertiaTensor.mat[0].x;
    v13 = va::va(
            this: &v24,
            fmt: (const char *)DWORD1(v12),
            a3: v12,
            a4: v11,
            a5: COERCE__INT64(this->inertiaTensor.mat[1].z),
            a6: v14,
            a7: v15,
            a8: v16,
            a9: v17,
            a10: v18,
            a11: v19);
    ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v9->DebugText)(
      a1: v9,
      a2: v13,
      a3: v10,
      a4: v9->DebugText,
      a5: &idColor::colorCyan,
      a6: 1,
      a7: 0,
      a8: 0,
      a9: 0.050000001);
  }
  if ( rb_showVelocity.valueInteger != 0 )
    idPhysics_DynamicBase::DrawVelocity(this, id: this->clipModel->bodyId, linearScale: 0.1, angularScale: 4.0);
}


// ========================================================================
// ?SetClipModel@idPhysics_RigidBody@@UAAXPAVidClipModel@@MH_N@Z
// EA  : 0x8275BE30
// RVA : 0x0075BE30
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetClipModel(
        idPhysics_RigidBody *this,
        idClipModel *model,
        double density,
        int id,
        int freeOld,
        char a6)
{
  idClipModel *clipModel; // r3
  idMat3 *p_inertiaTensor; // r30
  float *p_mass; // r28
  float *v13; // r4
  double y; // fp12
  double x; // fp11
  double z; // fp13
  int v17; // r8
  int i; // r7
  int v19; // r11
  int j; // ctr
  int v21; // r6
  double v22; // fp9
  float *v23; // r9
  double v24; // fp8
  double v25; // fp4
  double v26; // fp3
  double v27; // fp13
  double v28; // fp12
  int v29; // r10
  double v30; // fp10
  float *v31; // r3
  double v32; // fp6
  double v33; // fp3
  double v34; // fp1
  double v35; // fp8
  double v36; // fp12
  double v37; // fp4
  double v38; // fp9
  double v39; // fp2
  idMat3 v40; // [sp+50h] [-60h] BYREF

  clipModel = this->clipModel;
  if ( clipModel != nullptr && clipModel != model && a6 != 0 )
    idClipModel::Delete(this: clipModel);
  this->clipModel = model;
  idClipModel::Link(
    this: model,
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: freeOld,
    newOrigin: &model->origin,
    newAxis: &model->axis);
  p_inertiaTensor = &this->inertiaTensor;
  p_mass = &this->mass;
  idClipModel::GetMassProperties(
    this: this->clipModel,
    density,
    mass: v13,
    centerOfMass: (idVec3 *)&this->mass,
    inertiaTensor: (idMat3 *)&this->centerOfMass,
    a6: (float *)&this->inertiaTensor);
  if ( this->mass <= 0.0 || (unsigned __int8)IsValid<float>(f: &this->mass) == 0 )
  {
    *p_mass = 1.0;
    this->centerOfMass.z = 0.0;
    this->centerOfMass.y = 0.0;
    this->centerOfMass.x = 0.0;
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
  y = this->inertiaTensor.mat[1].y;
  x = p_inertiaTensor->mat[0].x;
  z = this->inertiaTensor.mat[2].z;
  if ( x >= y )
  {
    v17 = 1;
    if ( y < z )
      goto LABEL_13;
LABEL_12:
    v17 = 2;
    goto LABEL_13;
  }
  if ( x >= z )
    goto LABEL_12;
  v17 = 0;
LABEL_13:
  for ( i = 0; i < 9; i += 3 )
  {
    v19 = 0;
    for ( j = 3; j != 0; --j )
    {
      v21 = 4 * (i + v19++);
      *(float *)((char *)&v40.mat[0].x + v21) = 0.0;
    }
  }
  v22 = this->inertiaScale.y;
  v23 = (float *)((char *)this + 16 * v17);
  v24 = this->inertiaScale.z;
  v25 = (float)((float)((float)1.0 / v23[45]) * (float)z);
  v26 = (float)((float)((float)1.0 / v23[45]) * (float)y);
  v27 = (float)((float)((float)((float)1.0 / v23[45]) * (float)x) * this->inertiaScale.x);
  v40.mat[0].x = (float)((float)((float)1.0 / v23[45]) * (float)x) * this->inertiaScale.x;
  v40.mat[2].z = (float)v25 * (float)v24;
  v40.mat[1].y = (float)v26 * (float)v22;
  if ( v27 > 10.0 || (float)((float)v26 * (float)v22) > 10.0 || (float)((float)v25 * (float)v24) > 10.0 )
  {
    v28 = (float)(v23[45] * (float)10.0);
    v29 = 16 * ((v17 + 2) % 3);
    v30 = *(float *)((char *)&this->inertiaTensor.mat[0].x + v29);
    *(&v40.mat[0].x + 4 * ((v17 + 1) % 3)) = (float)(v23[45] * (float)10.0)
                                           / *(&this->inertiaTensor.mat[0].x + 4 * ((v17 + 1) % 3));
    *(float *)((char *)&v40.mat[0].x + v29) = (float)v28 / (float)v30;
    idMat3::operator*=(this: &this->inertiaTensor, a: &v40);
  }
  this->inverseMass = (float)1.0 / *p_mass;
  v31 = (float *)idMat3::Inverse(this: &v40, result: &this->inertiaTensor);
  v32 = (float)(v31[2] * (float)0.16666667);
  v33 = v31[7];
  v34 = v31[6];
  v35 = (float)(v31[3] * (float)0.16666667);
  v36 = v31[5];
  v37 = (float)(v31[1] * (float)0.16666667);
  v38 = v31[4];
  v39 = (float)(v31[8] * (float)0.16666667);
  this->inverseInertiaTensor.mat[0].x = *v31 * (float)0.16666667;
  this->inverseInertiaTensor.mat[1].x = v35;
  this->inverseInertiaTensor.mat[0].y = v37;
  this->inverseInertiaTensor.mat[0].z = v32;
  this->inverseInertiaTensor.mat[1].y = (float)v38 * (float)0.16666667;
  this->inverseInertiaTensor.mat[1].z = (float)v36 * (float)0.16666667;
  this->inverseInertiaTensor.mat[2].x = (float)v34 * (float)0.16666667;
  this->inverseInertiaTensor.mat[2].y = (float)v33 * (float)0.16666667;
  this->inverseInertiaTensor.mat[2].z = v39;
  this->current.spatialVelocity.p[5] = 0.0;
  this->current.spatialVelocity.p[4] = 0.0;
  this->current.spatialVelocity.p[3] = 0.0;
  this->current.spatialVelocity.p[2] = 0.0;
  this->current.spatialVelocity.p[1] = 0.0;
  this->current.spatialVelocity.p[0] = 0.0;
}


// ========================================================================
// ?SetMass@idPhysics_RigidBody@@UAAXMH@Z
// EA  : 0x8275C128
// RVA : 0x0075C128
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetMass(idPhysics_RigidBody *this, double mass_, int id)
{
  double v4; // fp13
  double y; // fp11
  double z; // fp10
  double x; // fp9
  double v9; // fp8
  double v10; // fp7
  double v11; // fp6
  double v12; // fp5
  double v13; // fp4
  float *v14; // r3
  double v15; // fp11
  double v16; // fp1
  double v17; // fp9
  double v18; // fp3
  double v19; // fp7
  double v20; // fp12
  double v21; // fp4
  double v22; // fp10
  idMat3 v23; // [sp+50h] [-40h] BYREF

  v4 = (float)((float)mass_ / this->mass);
  y = this->inertiaTensor.mat[0].y;
  z = this->inertiaTensor.mat[0].z;
  x = this->inertiaTensor.mat[1].x;
  v9 = this->inertiaTensor.mat[1].y;
  v10 = this->inertiaTensor.mat[1].z;
  v11 = this->inertiaTensor.mat[2].x;
  v12 = this->inertiaTensor.mat[2].y;
  v13 = this->inertiaTensor.mat[2].z;
  this->inertiaTensor.mat[0].x = this->inertiaTensor.mat[0].x * (float)((float)mass_ / this->mass);
  this->inertiaTensor.mat[0].y = (float)y * (float)v4;
  this->inertiaTensor.mat[0].z = (float)z * (float)v4;
  this->inertiaTensor.mat[1].x = (float)x * (float)v4;
  this->inertiaTensor.mat[1].y = (float)v9 * (float)v4;
  this->inertiaTensor.mat[1].z = (float)v10 * (float)v4;
  this->inertiaTensor.mat[2].x = (float)v11 * (float)v4;
  this->inertiaTensor.mat[2].y = (float)v12 * (float)v4;
  this->inertiaTensor.mat[2].z = (float)v13 * (float)v4;
  v14 = (float *)idMat3::Inverse(this: &v23, result: &this->inertiaTensor);
  v15 = v14[7];
  v16 = (float)(v14[2] * (float)0.16666667);
  v17 = v14[6];
  v18 = (float)(v14[3] * (float)0.16666667);
  v19 = v14[5];
  v20 = (float)(v14[1] * (float)0.16666667);
  v21 = v14[4];
  v22 = (float)(v14[8] * (float)0.16666667);
  this->inverseInertiaTensor.mat[0].x = *v14 * (float)0.16666667;
  this->inverseInertiaTensor.mat[1].x = v18;
  this->inverseInertiaTensor.mat[0].y = v20;
  this->inverseInertiaTensor.mat[0].z = v16;
  this->inverseInertiaTensor.mat[1].y = (float)v21 * (float)0.16666667;
  this->inverseInertiaTensor.mat[1].z = (float)v19 * (float)0.16666667;
  this->inverseInertiaTensor.mat[2].x = (float)v17 * (float)0.16666667;
  this->inverseInertiaTensor.mat[2].y = (float)v15 * (float)0.16666667;
  this->inverseInertiaTensor.mat[2].z = v22;
  this->mass = mass_;
  this->inverseMass = (float)1.0 / (float)mass_;
}


// ========================================================================
// ?SetWaterFriction@idPhysics_RigidBody@@QAAXMM@Z
// EA  : 0x8275C268
// RVA : 0x0075C268
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetWaterFriction(idPhysics_RigidBody *this, double linear, double angular)
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
// ?SetInertiaScale@idPhysics_RigidBody@@QAAXABVidVec3@@@Z
// EA  : 0x8275C2C0
// RVA : 0x0075C2C0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetInertiaScale(idPhysics_RigidBody *this, const idVec3 *v)
{
  this->inertiaScale = *v;
}


// ========================================================================
// ?GetContents@idPhysics_RigidBody@@UBAHH@Z
// EA  : 0x8275C2E0
// RVA : 0x0075C2E0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

int __fastcall idPhysics_RigidBody::GetContents(idPhysics_RigidBody *this, int id)
{
  idClipModel *clipModel; // r11
  int result; // r3

  clipModel = this->clipModel;
  result = 0;
  if ( clipModel != nullptr )
    return clipModel->contents;
  return result;
}


// ========================================================================
// ?GetBounds@idPhysics_RigidBody@@UBAABVidBounds@@H@Z
// EA  : 0x8275C2F8
// RVA : 0x0075C2F8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_RigidBody::GetBounds(idPhysics_RigidBody *this, int id)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    return &clipModel->bounds;
  else
    return &bounds_zero;
}


// ========================================================================
// ?GetAbsBounds@idPhysics_RigidBody@@UBAABVidBounds@@H@Z
// EA  : 0x8275C318
// RVA : 0x0075C318
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_RigidBody::GetAbsBounds(idPhysics_RigidBody *this, int id)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    return &clipModel->absBounds;
  else
    return &bounds_zero;
}


// ========================================================================
// ?GetImpactInfo@idPhysics_RigidBody@@UBAXHABVidVec3@@AAUimpactInfo_t@@@Z
// EA  : 0x8275C338
// RVA : 0x0075C338
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::GetImpactInfo(
        idPhysics_RigidBody *this,
        const int id,
        const idVec3 *point,
        impactInfo_t *info)
{
  float *clipModel; // r11
  double v8; // fp11
  double v9; // fp10
  const idMat3 *v10; // r29
  double v11; // fp9
  double v12; // fp8
  double v13; // fp7
  double v14; // fp6
  double v15; // fp5
  double v16; // fp12
  idMat3 *v17; // r3
  float *v18; // r10
  double v19; // fp12
  double v20; // fp7
  double x; // fp6
  double v22; // fp4
  double v23; // fp0
  double v24; // fp13
  double v25; // fp4
  double v26; // fp2
  double v27; // fp3
  idMat3 v28; // [sp+50h] [-C0h] BYREF
  idMat3 v29; // [sp+80h] [-90h] BYREF
  idMat3 v30; // [sp+B0h] [-60h] BYREF

  if ( this->clipModel != nullptr )
  {
    info->invMass = this->inverseMass;
    clipModel = (float *)this->clipModel;
    v8 = clipModel[15];
    v9 = clipModel[12];
    v10 = (const idMat3 *)(clipModel + 11);
    v11 = clipModel[17];
    v12 = clipModel[14];
    v13 = clipModel[11];
    v14 = clipModel[19];
    v15 = clipModel[13];
    v16 = clipModel[18];
    v28.mat[2].y = clipModel[16];
    v28.mat[1].z = v16;
    v28.mat[2].x = v15;
    v28.mat[2].z = v14;
    v28.mat[1].y = v8;
    v28.mat[1].x = v9;
    v28.mat[0].z = v11;
    v28.mat[0].y = v12;
    v28.mat[0].x = v13;
    v17 = idMat3::operator*(this: &v29, result: &v28, a: &this->inverseInertiaTensor);
    info->invInertiaTensor = *idMat3::operator*(this: &v30, result: v17, a: v10);
    v18 = (float *)this->clipModel;
    v19 = (float)(v18[8]
                + (float)((float)(v18[11] * this->centerOfMass.x)
                        + (float)((float)(v18[14] * this->centerOfMass.y) + (float)(v18[17] * this->centerOfMass.z))));
    v20 = (float)(point->y
                - (float)(v18[9]
                        + (float)((float)(v18[12] * this->centerOfMass.x)
                                + (float)((float)(v18[15] * this->centerOfMass.y)
                                        + (float)(v18[18] * this->centerOfMass.z)))));
    x = point->x;
    v22 = (float)(point->z
                - (float)(v18[10]
                        + (float)((float)(v18[13] * this->centerOfMass.x)
                                + (float)((float)(v18[16] * this->centerOfMass.y)
                                        + (float)(v18[19] * this->centerOfMass.z)))));
    info->position.z = point->z
                     - (float)(v18[10]
                             + (float)((float)(v18[13] * this->centerOfMass.x)
                                     + (float)((float)(v18[16] * this->centerOfMass.y)
                                             + (float)(v18[19] * this->centerOfMass.z))));
    info->position.y = v20;
    info->position.x = (float)x - (float)v19;
    v23 = this->current.spatialVelocity.p[1];
    v24 = this->current.spatialVelocity.p[2];
    v26 = (float)((float)((float)((float)x - (float)v19) * this->current.spatialVelocity.p[5])
                - (float)((float)v22 * this->current.spatialVelocity.p[3]));
    v27 = (float)(this->current.spatialVelocity.p[0]
                + (float)((float)((float)v22 * this->current.spatialVelocity.p[4])
                        - (float)((float)v20 * this->current.spatialVelocity.p[5])));
    v25 = (float)((float)((float)v20 * this->current.spatialVelocity.p[3])
                - (float)((float)((float)x - (float)v19) * this->current.spatialVelocity.p[4]));
    info->velocity.x = v27;
    info->velocity.z = (float)v24 + (float)v25;
    info->velocity.y = (float)v23 + (float)v26;
  }
}


// ========================================================================
// ?ApplyImpulse@idPhysics_RigidBody@@UAAXHABVidVec3@@0@Z
// EA  : 0x8275C520
// RVA : 0x0075C520
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::ApplyImpulse(
        idPhysics_RigidBody *this,
        const int id,
        const idVec3 *point,
        const idVec3 *impulse)
{
  float *clipModel; // r11
  const idMat3 *v8; // r30
  double v9; // fp13
  double v10; // fp12
  double v11; // fp11
  double v12; // fp10
  double v13; // fp9
  double v14; // fp8
  double v15; // fp7
  double v16; // fp6
  idMat3 *v17; // r3
  double v18; // fp0
  double v19; // fp13
  double v20; // fp11
  double v21; // fp10
  float *v22; // r10
  double v23; // fp28
  double v24; // fp27
  double v25; // fp6
  double v26; // fp13
  double v27; // fp12
  idMat3 v28; // [sp+50h] [-B0h] BYREF
  idMat3 v29[2]; // [sp+80h] [-80h] BYREF

  if ( this->clipModel != nullptr && (*((_BYTE *)&this->fl + 4) & 0x20) == 0 )
  {
    clipModel = (float *)this->clipModel;
    v8 = (const idMat3 *)(clipModel + 11);
    v9 = clipModel[16];
    v10 = clipModel[13];
    v11 = clipModel[18];
    v12 = clipModel[15];
    v13 = clipModel[12];
    v14 = clipModel[17];
    v15 = clipModel[14];
    v16 = clipModel[11];
    v28.mat[2].z = clipModel[19];
    v28.mat[2].y = v9;
    v28.mat[2].x = v10;
    v28.mat[1].z = v11;
    v28.mat[1].y = v12;
    v28.mat[1].x = v13;
    v28.mat[0].z = v14;
    v28.mat[0].y = v15;
    v28.mat[0].x = v16;
    v17 = idMat3::operator*(this: v29, result: &v28, a: &this->inverseInertiaTensor);
    idMat3::operator*(this: &v28, result: v17, a: v8);
    v18 = (float)(impulse->y * this->inverseMass);
    v19 = (float)(impulse->z * this->inverseMass);
    v20 = this->current.spatialVelocity.p[1];
    v21 = this->current.spatialVelocity.p[2];
    this->current.spatialVelocity.p[0] = this->current.spatialVelocity.p[0] + (float)(impulse->x * this->inverseMass);
    this->current.spatialVelocity.p[1] = (float)v20 + (float)v18;
    this->current.spatialVelocity.p[2] = (float)v21 + (float)v19;
    v22 = (float *)this->clipModel;
    v23 = this->current.spatialVelocity.p[4];
    v24 = this->current.spatialVelocity.p[5];
    v25 = (float)((float)(impulse->z
                        * (float)(point->y
                                - (float)(v22[9]
                                        + (float)((float)(v22[18] * this->centerOfMass.z)
                                                + (float)((float)(v22[12] * this->centerOfMass.x)
                                                        + (float)(v22[15] * this->centerOfMass.y))))))
                - (float)(impulse->y
                        * (float)(point->z
                                - (float)(v22[10]
                                        + (float)((float)(v22[19] * this->centerOfMass.z)
                                                + (float)((float)(v22[13] * this->centerOfMass.x)
                                                        + (float)(v22[16] * this->centerOfMass.y)))))));
    v26 = (float)((float)(v28.mat[0].y * (float)v25)
                + (float)((float)(v28.mat[2].y
                                * (float)((float)(impulse->y
                                                * (float)(point->x
                                                        - (float)(v22[8]
                                                                + (float)((float)(this->centerOfMass.x * v22[11])
                                                                        + (float)((float)(v22[14] * this->centerOfMass.y)
                                                                                + (float)(v22[17] * this->centerOfMass.z))))))
                                        - (float)(impulse->x
                                                * (float)(point->y
                                                        - (float)(v22[9]
                                                                + (float)((float)(v22[18] * this->centerOfMass.z)
                                                                        + (float)((float)(v22[12] * this->centerOfMass.x)
                                                                                + (float)(v22[15] * this->centerOfMass.y))))))))
                        + (float)(v28.mat[1].y
                                * (float)((float)(impulse->x
                                                * (float)(point->z
                                                        - (float)(v22[10]
                                                                + (float)((float)(v22[19] * this->centerOfMass.z)
                                                                        + (float)((float)(v22[13] * this->centerOfMass.x)
                                                                                + (float)(v22[16] * this->centerOfMass.y))))))
                                        - (float)(impulse->z
                                                * (float)(point->x
                                                        - (float)(v22[8]
                                                                + (float)((float)(this->centerOfMass.x * v22[11])
                                                                        + (float)((float)(v22[14] * this->centerOfMass.y)
                                                                                + (float)(v22[17] * this->centerOfMass.z))))))))));
    v27 = (float)((float)(v28.mat[0].z * (float)v25)
                + (float)((float)(v28.mat[2].z
                                * (float)((float)(impulse->y
                                                * (float)(point->x
                                                        - (float)(v22[8]
                                                                + (float)((float)(this->centerOfMass.x * v22[11])
                                                                        + (float)((float)(v22[14] * this->centerOfMass.y)
                                                                                + (float)(v22[17] * this->centerOfMass.z))))))
                                        - (float)(impulse->x
                                                * (float)(point->y
                                                        - (float)(v22[9]
                                                                + (float)((float)(v22[18] * this->centerOfMass.z)
                                                                        + (float)((float)(v22[12] * this->centerOfMass.x)
                                                                                + (float)(v22[15] * this->centerOfMass.y))))))))
                        + (float)(v28.mat[1].z
                                * (float)((float)(impulse->x
                                                * (float)(point->z
                                                        - (float)(v22[10]
                                                                + (float)((float)(v22[19] * this->centerOfMass.z)
                                                                        + (float)((float)(v22[13] * this->centerOfMass.x)
                                                                                + (float)(v22[16] * this->centerOfMass.y))))))
                                        - (float)(impulse->z
                                                * (float)(point->x
                                                        - (float)(v22[8]
                                                                + (float)((float)(this->centerOfMass.x * v22[11])
                                                                        + (float)((float)(v22[14] * this->centerOfMass.y)
                                                                                + (float)(v22[17] * this->centerOfMass.z))))))))));
    this->current.spatialVelocity.p[3] = this->current.spatialVelocity.p[3]
                                       + (float)((float)((float)v25 * v28.mat[0].x)
                                               + (float)((float)(v28.mat[2].x
                                                               * (float)((float)(impulse->y
                                                                               * (float)(point->x
                                                                                       - (float)(v22[8]
                                                                                               + (float)((float)(this->centerOfMass.x * v22[11]) + (float)((float)(v22[14] * this->centerOfMass.y) + (float)(v22[17] * this->centerOfMass.z))))))
                                                                       - (float)(impulse->x
                                                                               * (float)(point->y
                                                                                       - (float)(v22[9]
                                                                                               + (float)((float)(v22[18] * this->centerOfMass.z) + (float)((float)(v22[12] * this->centerOfMass.x) + (float)(v22[15] * this->centerOfMass.y))))))))
                                                       + (float)(v28.mat[1].x
                                                               * (float)((float)(impulse->x
                                                                               * (float)(point->z
                                                                                       - (float)(v22[10]
                                                                                               + (float)((float)(v22[19] * this->centerOfMass.z) + (float)((float)(v22[13] * this->centerOfMass.x) + (float)(v22[16] * this->centerOfMass.y))))))
                                                                       - (float)(impulse->z
                                                                               * (float)(point->x
                                                                                       - (float)(v22[8]
                                                                                               + (float)((float)(this->centerOfMass.x * v22[11]) + (float)((float)(v22[14] * this->centerOfMass.y) + (float)(v22[17] * this->centerOfMass.z))))))))));
    this->current.spatialVelocity.p[4] = (float)v23 + (float)v26;
    this->current.spatialVelocity.p[5] = (float)v24 + (float)v27;
    idPhysics_RigidBody::CapVelocity(this);
    this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
  }
}


// ========================================================================
// ?ApplyForce@idPhysics_RigidBody@@UAAXHABVidVec3@@0@Z
// EA  : 0x8275C760
// RVA : 0x0075C760
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::ApplyForce(
        idPhysics_RigidBody *this,
        const int id,
        const idVec3 *point,
        const idVec3 *force)
{
  float *clipModel; // r11
  double v5; // fp9
  double v6; // fp8
  double v7; // fp13
  double v8; // fp12

  if ( this->clipModel != nullptr && (*((_BYTE *)&this->fl + 4) & 0x20) == 0 )
  {
    this->current.externalForce.p[0] = this->current.externalForce.p[0] + force->x;
    this->current.externalForce.p[1] = this->current.externalForce.p[1] + force->y;
    this->current.externalForce.p[2] = force->z + this->current.externalForce.p[2];
    clipModel = (float *)this->clipModel;
    v5 = this->current.externalForce.p[4];
    v6 = this->current.externalForce.p[5];
    v7 = (float)((float)(force->y
                       * (float)(point->x
                               - (float)(clipModel[8]
                                       + (float)((float)(this->centerOfMass.x * clipModel[11])
                                               + (float)((float)(clipModel[14] * this->centerOfMass.y)
                                                       + (float)(clipModel[17] * this->centerOfMass.z))))))
               - (float)(force->x
                       * (float)(point->y
                               - (float)(clipModel[9]
                                       + (float)((float)(clipModel[18] * this->centerOfMass.z)
                                               + (float)((float)(clipModel[12] * this->centerOfMass.x)
                                                       + (float)(clipModel[15] * this->centerOfMass.y)))))));
    v8 = (float)((float)(force->x
                       * (float)(point->z
                               - (float)(clipModel[10]
                                       + (float)((float)(clipModel[19] * this->centerOfMass.z)
                                               + (float)((float)(clipModel[13] * this->centerOfMass.x)
                                                       + (float)(clipModel[16] * this->centerOfMass.y))))))
               - (float)(force->z
                       * (float)(point->x
                               - (float)(clipModel[8]
                                       + (float)((float)(this->centerOfMass.x * clipModel[11])
                                               + (float)((float)(clipModel[14] * this->centerOfMass.y)
                                                       + (float)(clipModel[17] * this->centerOfMass.z)))))));
    this->current.externalForce.p[3] = this->current.externalForce.p[3]
                                     + (float)((float)(force->z
                                                     * (float)(point->y
                                                             - (float)(clipModel[9]
                                                                     + (float)((float)(clipModel[18]
                                                                                     * this->centerOfMass.z)
                                                                             + (float)((float)(clipModel[12]
                                                                                             * this->centerOfMass.x)
                                                                                     + (float)(clipModel[15]
                                                                                             * this->centerOfMass.y))))))
                                             - (float)(force->y
                                                     * (float)(point->z
                                                             - (float)(clipModel[10]
                                                                     + (float)((float)(clipModel[19]
                                                                                     * this->centerOfMass.z)
                                                                             + (float)((float)(clipModel[13]
                                                                                             * this->centerOfMass.x)
                                                                                     + (float)(clipModel[16]
                                                                                             * this->centerOfMass.y)))))));
    this->current.externalForce.p[5] = (float)v6 + (float)v7;
    this->current.externalForce.p[4] = (float)v5 + (float)v8;
  }
}


// ========================================================================
// ?PutToRest@idPhysics_RigidBody@@UAAXXZ
// EA  : 0x8275C8A8
// RVA : 0x0075C8A8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::PutToRest(idPhysics_RigidBody *this)
{
  this->current.atRest = 1;
  this->current.spatialVelocity.p[5] = 0.0;
  this->current.spatialVelocity.p[4] = 0.0;
  this->current.spatialVelocity.p[3] = 0.0;
  this->current.spatialVelocity.p[2] = 0.0;
  this->current.spatialVelocity.p[1] = 0.0;
  this->current.spatialVelocity.p[0] = 0.0;
}


// ========================================================================
// ?SaveState@idPhysics_RigidBody@@UAAXXZ
// EA  : 0x8275C8D8
// RVA : 0x0075C8D8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SaveState(idPhysics_RigidBody *this)
{
  idClipModel *clipModel; // r11
  float *v3; // r11

  if ( this->clipModel != nullptr )
  {
    rigidBodyPState_t::operator=(this: &this->saved, __that: &this->current);
    clipModel = this->clipModel;
    this->saved.worldOrigin.x = clipModel->origin.x;
    this->saved.worldOrigin.y = clipModel->origin.y;
    this->saved.worldOrigin.z = clipModel->origin.z;
    v3 = (float *)this->clipModel;
    this->saved.worldAxis.mat[0].x = v3[11];
    this->saved.worldAxis.mat[0].y = v3[12];
    this->saved.worldAxis.mat[0].z = v3[13];
    this->saved.worldAxis.mat[1].x = v3[14];
    this->saved.worldAxis.mat[1].y = v3[15];
    this->saved.worldAxis.mat[1].z = v3[16];
    this->saved.worldAxis.mat[2].x = v3[17];
    this->saved.worldAxis.mat[2].y = v3[18];
    this->saved.worldAxis.mat[2].z = v3[19];
  }
}


// ========================================================================
// ?RestoreState@idPhysics_RigidBody@@UAAXXZ
// EA  : 0x8275C988
// RVA : 0x0075C988
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::RestoreState(idPhysics_RigidBody *this)
{
  if ( this->clipModel != nullptr )
  {
    rigidBodyPState_t::operator=(this: &this->current, __that: &this->saved);
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: this->clipModel->bodyId,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->current.worldAxis);
    this->EvaluateContacts(this);
  }
}


// ========================================================================
// ?SetOrigin@idPhysics_RigidBody@@UAAXABVidVec3@@H@Z
// EA  : 0x8275C9F8
// RVA : 0x0075C9F8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetOrigin(idPhysics_RigidBody *this, const idVec3 *newOrigin, int id)
{
  unsigned __int64 index; // r11
  double v6; // fp2
  double v7; // fp11
  double v8; // fp7
  double v9; // fp4
  double v10; // fp3
  float v11; // [sp+50h] [-50h] BYREF
  float v12; // [sp+54h] [-4Ch]
  float v13; // [sp+58h] [-48h]
  float v14[10]; // [sp+60h] [-40h] BYREF

  if ( this->clipModel != nullptr )
  {
    index = this->motionQuery.index;
    if ( (unsigned int)index >= *(_DWORD *)(HIDWORD(index) + 377212)
      && (unsigned int)index <= *(_DWORD *)(HIDWORD(index) + 377236) )
    {
      *(_DWORD *)(24 * ((index & 0xFFF) + 11621) + HIDWORD(index)) = 1;
    }
    LODWORD(index) = 0;
    this->motionQuery.index = index;
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: this->clipModel->bodyId,
      newOrigin,
      newAxis: &this->clipModel->axis);
    if ( (*((_BYTE *)&this->fl + 4) & 0x10) != 0 )
    {
      this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v11, a3: (idMat3 *)v14);
      v6 = (float)(newOrigin->z - v13);
      v7 = v14[5];
      v8 = v14[8];
      v9 = (float)((float)(v14[3] * (float)(newOrigin->x - v11)) + (float)(v14[4] * (float)(newOrigin->y - v12)));
      v10 = (float)((float)(v14[6] * (float)(newOrigin->x - v11)) + (float)(v14[7] * (float)(newOrigin->y - v12)));
      this->current.localOrigin.x = (float)(v14[2] * (float)(newOrigin->z - v13))
                                  + (float)((float)(v14[1] * (float)(newOrigin->y - v12))
                                          + (float)(v14[0] * (float)(newOrigin->x - v11)));
      this->current.localOrigin.y = (float)((float)v7 * (float)v6) + (float)v9;
      this->current.localOrigin.z = (float)((float)v8 * (float)v6) + (float)v10;
    }
    this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
  }
}


// ========================================================================
// ?SetAxis@idPhysics_RigidBody@@UAAXABVidMat3@@H@Z
// EA  : 0x8275CB68
// RVA : 0x0075CB68
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetAxis(idPhysics_RigidBody *this, idMat3 *newAxis, int id)
{
  unsigned __int64 index; // r11
  _BYTE v6[16]; // [sp+50h] [-B0h] BYREF
  float v7[12]; // [sp+60h] [-A0h] BYREF
  idMat3 v8; // [sp+90h] [-70h] BYREF
  idMat3 v9; // [sp+C0h] [-40h] BYREF

  if ( this->clipModel != nullptr )
  {
    index = this->motionQuery.index;
    if ( (unsigned int)index >= *(_DWORD *)(HIDWORD(index) + 377212)
      && (unsigned int)index <= *(_DWORD *)(HIDWORD(index) + 377236) )
    {
      *(_DWORD *)(24 * ((index & 0xFFF) + 11621) + HIDWORD(index)) = 1;
    }
    LODWORD(index) = 0;
    this->motionQuery.index = index;
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: this->clipModel->bodyId,
      newOrigin: &this->clipModel->origin,
      newAxis);
    if ( (*((_BYTE *)&this->fl + 4) & 0x10) != 0 && (*((_BYTE *)&this->fl + 4) & 8) != 0 )
    {
      this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v6, a3: (idMat3 *)v7);
      v8.mat[0].x = v7[0];
      v8.mat[0].y = v7[3];
      v8.mat[0].z = v7[6];
      v8.mat[1].x = v7[1];
      v8.mat[1].y = v7[4];
      v8.mat[1].z = v7[7];
      v8.mat[2].x = v7[2];
      v8.mat[2].y = v7[5];
      v8.mat[2].z = v7[8];
      this->current.localAxis = *idMat3::operator*(this: &v9, result: newAxis, a: &v8);
    }
    this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
  }
}


// ========================================================================
// ?GetOrigin@idPhysics_RigidBody@@UBAABVidVec3@@H@Z
// EA  : 0x8275CD10
// RVA : 0x0075CD10
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

const idVec3 *__fastcall idPhysics_RigidBody::GetOrigin(idPhysics_RigidBody *this, int id)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    return &clipModel->origin;
  else
    return &vec3_origin;
}


// ========================================================================
// ?GetAxis@idPhysics_RigidBody@@UBAABVidMat3@@H@Z
// EA  : 0x8275CD30
// RVA : 0x0075CD30
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

const idMat3 *__fastcall idPhysics_RigidBody::GetAxis(idPhysics_RigidBody *this, int id)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    return &clipModel->axis;
  else
    return &mat3_identity;
}


// ========================================================================
// ?SetLinearVelocity@idPhysics_RigidBody@@UAAXABVidVec3@@H@Z
// EA  : 0x8275CD50
// RVA : 0x0075CD50
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetLinearVelocity(
        idPhysics_RigidBody *this,
        const idVec3 *newLinearVelocity,
        int id)
{
  this->current.spatialVelocity.p[0] = newLinearVelocity->x;
  this->current.spatialVelocity.p[1] = newLinearVelocity->y;
  this->current.spatialVelocity.p[2] = newLinearVelocity->z;
  ((void (__fastcall *)(idPhysicsCallbacks *, int, int))this->callbacks->ActivatePhysics)(
    a1: this->callbacks,
    a2: this->physicsId,
    a3: id);
}


// ========================================================================
// ?SetAngularVelocity@idPhysics_RigidBody@@UAAXABVidVec3@@H@Z
// EA  : 0x8275CD80
// RVA : 0x0075CD80
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetAngularVelocity(
        idPhysics_RigidBody *this,
        const idVec3 *newAngularVelocity,
        int id)
{
  *(idVec3 *)&this->current.spatialVelocity.p[3] = *newAngularVelocity;
  ((void (__fastcall *)(idPhysicsCallbacks *, int, int))this->callbacks->ActivatePhysics)(
    a1: this->callbacks,
    a2: this->physicsId,
    a3: id);
}


// ========================================================================
// ?GetLinearVelocity@idPhysics_RigidBody@@UBA?AVidVec3@@H@Z
// EA  : 0x8275CDB0
// RVA : 0x0075CDB0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

idPhysics_RigidBody *__fastcall idPhysics_RigidBody::GetLinearVelocity(
        idPhysics_RigidBody *this,
        idVec3 *result,
        int id)
{
  float y; // r10
  float z; // r9

  y = result[30].y;
  z = result[30].z;
  this->__vftable = (idPhysics_RigidBody_vtbl *)LODWORD(result[30].x);
  *((float *)&this->__vftable + 1) = y;
  *(float *)&this->type = z;
  return this;
}


// ========================================================================
// ?GetAngularVelocity@idPhysics_RigidBody@@UBA?AVidVec3@@H@Z
// EA  : 0x8275CDD0
// RVA : 0x0075CDD0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

idPhysics_RigidBody *__fastcall idPhysics_RigidBody::GetAngularVelocity(
        idPhysics_RigidBody *this,
        idVec3 *result,
        int id)
{
  float y; // r10
  float z; // r9

  y = result[31].y;
  z = result[31].z;
  this->__vftable = (idPhysics_RigidBody_vtbl *)LODWORD(result[31].x);
  *((float *)&this->__vftable + 1) = y;
  *(float *)&this->type = z;
  return this;
}


// ========================================================================
// ?ClipTranslation@idPhysics_RigidBody@@UBAXAAUtrace_t@@ABVidVec3@@PBVidClipModel@@@Z
// EA  : 0x8275CDF0
// RVA : 0x0075CDF0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::ClipTranslation(
        idPhysics_RigidBody *this,
        trace_t *results,
        const idVec3 *translation,
        idClipModel *model)
{
  idClipModel *clipModel; // r9
  double z; // fp0
  idClipModel *v7; // r7
  double y; // fp13
  int clipMask; // r9
  const idVec3 *p_origin; // r5
  idClip *clip; // r3
  double v12; // fp8
  double v13; // fp7
  double x; // fp13
  double v15; // fp12
  idClipModel *v16; // r8
  int v18; // r10
  idClip *v19; // r4
  double v20; // fp9
  double v21; // fp6
  const idVec3 *v22; // [sp+8h] [-A8h]
  const idMat3 *v23; // [sp+Ch] [-A4h]
  const char *v24; // [sp+10h] [-A0h]
  int v25; // [sp+14h] [-9Ch]
  int v26; // [sp+18h] [-98h]
  int v27; // [sp+1Ch] [-94h]
  int v28; // [sp+20h] [-90h]
  int v29; // [sp+24h] [-8Ch]
  int v30; // [sp+28h] [-88h]
  int v31; // [sp+2Ch] [-84h]
  int v32; // [sp+30h] [-80h]
  int v33; // [sp+34h] [-7Ch]
  int v34; // [sp+38h] [-78h]
  int v35; // [sp+3Ch] [-74h]
  int v36; // [sp+40h] [-70h]
  int v37; // [sp+44h] [-6Ch]
  int v38; // [sp+48h] [-68h]
  int v39; // [sp+4Ch] [-64h]
  int v40; // [sp+50h] [-60h]
  int entityNumber; // [sp+54h] [-5Ch]
  int v42; // [sp+58h] [-58h]
  int v43; // [sp+60h] [-50h]
  char v44; // [sp+70h] [-40h] BYREF
  idVec3 v45; // [sp+78h] [-38h] BYREF
  idVec3 v46; // [sp+88h] [-28h] BYREF

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
  {
    z = translation->z;
    if ( model != nullptr )
    {
      v7 = this->clipModel;
      y = translation->y;
      p_origin = &clipModel->origin;
      clipMask = this->clipMask;
      clip = this->clip;
      v12 = (float)(v7->origin.z + (float)z);
      v13 = (float)(v7->origin.y + (float)y);
      v45.x = translation->x + v7->origin.x;
      v45.z = v12;
      v45.y = v13;
      idClip::TranslationModel(
        this: clip,
        result: results,
        start: p_origin,
        end: &v45,
        trm: v7,
        trmAxis: &v7->axis,
        clipMask,
        model,
        modelOrigin: v22,
        modelAxis: v23,
        a11: (int)v24,
        a12: v25,
        a13: v26,
        a14: v27,
        a15: v28,
        a16: v29,
        a17: v30,
        a18: v31,
        a19: v32,
        a20: v33,
        a21: v34,
        a22: v35,
        a23: v36,
        a24: v37,
        a25: v38,
        a26: v39,
        a27: v40,
        a28: &model->origin.x,
        a29: v42,
        a30: (float *)&model->axis);
    }
    else
    {
      x = translation->x;
      v15 = translation->y;
      v16 = this->clipModel;
      v18 = this->clipMask;
      v19 = this->clip;
      entityNumber = this->entityNumber;
      v20 = (float)(v16->origin.z + (float)z);
      v21 = (float)(v16->origin.y + (float)v15);
      v46.x = v16->origin.x + (float)x;
      v46.z = v20;
      v46.y = v21;
      idClip::Translation(
        this: (idClip *)&v44,
        result: v19,
        a3: results,
        start: &v16->origin,
        end: &v46,
        clipModel: v16,
        startAxis: &v16->axis,
        clipMask: v18,
        passEntityNumber: (int)v22,
        moveClipModel: (bool)v23,
        userName: v24,
        a12: v25,
        a13: v26,
        a14: v27,
        a15: v28,
        a16: v29,
        a17: v30,
        a18: v31,
        a19: v32,
        a20: v33,
        a21: v34,
        a22: v35,
        a23: v36,
        a24: v37,
        a25: v38,
        a26: v39,
        a27: v40,
        a28: entityNumber,
        a29: v42,
        a30: false,
        a31: v43,
        a32: 0);
    }
  }
}


// ========================================================================
// ?ClipRotation@idPhysics_RigidBody@@UBAXAAUtrace_t@@ABVidRotation@@PBVidClipModel@@@Z
// EA  : 0x8275CF00
// RVA : 0x0075CF00
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::ClipRotation(
        idPhysics_RigidBody *this,
        trace_t *results,
        idRotation *rotation,
        idClipModel *model)
{
  idClipModel *clipModel; // r9
  const idVec3 *v5; // [sp+8h] [-88h]
  const idMat3 *v6; // [sp+Ch] [-84h]
  const char *v7; // [sp+10h] [-80h]
  int v8; // [sp+14h] [-7Ch]
  int v9; // [sp+18h] [-78h]
  int v10; // [sp+1Ch] [-74h]
  int v11; // [sp+20h] [-70h]
  int v12; // [sp+24h] [-6Ch]
  int v13; // [sp+28h] [-68h]
  int v14; // [sp+2Ch] [-64h]
  int v15; // [sp+30h] [-60h]
  int v16; // [sp+34h] [-5Ch]
  int v17; // [sp+38h] [-58h]
  int v18; // [sp+3Ch] [-54h]
  int v19; // [sp+40h] [-50h]
  int v20; // [sp+44h] [-4Ch]
  int v21; // [sp+48h] [-48h]
  int v22; // [sp+4Ch] [-44h]
  int v23; // [sp+50h] [-40h]
  int v24; // [sp+58h] [-38h]
  int v25; // [sp+60h] [-30h]
  char v26; // [sp+70h] [-20h] BYREF

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
  {
    if ( model != nullptr )
      idClip::RotationModel(
        this: this->clip,
        result: results,
        start: (const idMat3 *)&clipModel->origin,
        rotation,
        trm: this->clipModel,
        trmAxis: &clipModel->axis,
        clipMask: (const idVec3 *)this->clipMask,
        model,
        modelOrigin: v5,
        modelAxis: v6,
        a11: (int)v7,
        a12: v8,
        a13: v9,
        a14: v10,
        a15: v11,
        a16: v12,
        a17: v13,
        a18: v14,
        a19: v15,
        a20: v16,
        a21: v17,
        a22: v18,
        a23: v19,
        a24: v20,
        a25: v21,
        a26: v22,
        a27: v23,
        a28: &model->origin.x,
        a29: v24,
        a30: (float *)&model->axis);
    else
      idClip::Rotation(
        this: (idClip *)&v26,
        result: this->clip,
        a3: results,
        start: (const idMat3 *)&this->clipModel->origin,
        rotation,
        clipModel: this->clipModel,
        startAxis: &this->clipModel->axis,
        clipMask: this->clipMask,
        passEntityNumber: (int)v5,
        moveClipModel: (bool)v6,
        userName: v7,
        a12: v8,
        a13: v9,
        a14: v10,
        a15: v11,
        a16: v12,
        a17: v13,
        a18: v14,
        a19: v15,
        a20: v16,
        a21: v17,
        a22: v18,
        a23: v19,
        a24: v20,
        a25: v21,
        a26: v22,
        a27: v23,
        a28: this->entityNumber,
        a29: v24,
        a30: false,
        a31: v25,
        a32: 0);
  }
}


// ========================================================================
// ?IsGroundClipModel@idPhysics_RigidBody@@UBA_NHH@Z
// EA  : 0x8275CFB8
// RVA : 0x0075CFB8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

int __fastcall idPhysics_RigidBody::IsGroundClipModel(idPhysics_RigidBody *this, int entityNum, int id)
{
  int num; // r7
  int v4; // r9
  contactInfo_t *list; // r8
  int i; // r10
  contactInfo_t *v7; // r11

  if ( this->clipModel == nullptr )
    return 0;
  if ( this->current.atRest < 0 )
    return 0;
  num = this->contacts.num;
  v4 = 0;
  if ( num <= 0 )
    return 0;
  list = this->contacts.list;
  for ( i = 0; ; ++i )
  {
    v7 = &list[i];
    if ( list[i].entityNum == entityNum
      && v7->bodyId == id
      && (float)((float)(v7->normal.x * this->gravityNormal.x)
               + (float)((float)(v7->normal.z * this->gravityNormal.z) + (float)(v7->normal.y * this->gravityNormal.y))) < -0.98480773 )
    {
      break;
    }
    if ( ++v4 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?SetPushed@idPhysics_RigidBody@@UAAXH@Z
// EA  : 0x8275D058
// RVA : 0x0075D058
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetPushed(idPhysics_RigidBody *this, unsigned int deltaTime)
{
  idClipModel *clipModel; // r11
  double v4; // fp5
  double v5; // fp3
  double v6; // fp2
  double v7; // fp31
  double y; // fp10
  idClipModel *v9; // r11
  double v10; // fp9
  double v11; // fp8
  double x; // fp7
  double v13; // fp6
  double v14; // fp5
  double z; // fp4
  double v16; // fp3
  idMat3 *v17; // r3
  idVec3 *v18; // r3
  double v19; // fp12
  double v20; // fp11
  idMat3 v21; // [sp+50h] [-80h] BYREF
  float v22; // [sp+74h] [-5Ch]
  float v23; // [sp+78h] [-58h]
  float v24; // [sp+7Ch] [-54h]
  float v25; // [sp+80h] [-50h]
  idMat3 v26; // [sp+90h] [-40h] BYREF

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
  {
    v4 = (float)(clipModel->origin.x - this->saved.worldOrigin.x);
    *(_QWORD *)&v21.mat[0].x = __PAIR64__(&unk_82390000, deltaTime);
    v5 = (float)(clipModel->origin.y - this->saved.worldOrigin.y);
    v6 = (float)(clipModel->origin.z - this->saved.worldOrigin.z);
    v7 = (float)((float)1.0 / (float)((float)__SPAIR64__(&unk_82390000, deltaTime) * (float)0.001));
    this->current.pushVelocity.p[0] = (float)v4
                                    * (float)((float)1.0
                                            / (float)((float)__SPAIR64__(&unk_82390000, deltaTime) * (float)0.001));
    this->current.pushVelocity.p[1] = (float)v5
                                    * (float)((float)1.0
                                            / (float)((float)__SPAIR64__(&unk_82390000, deltaTime) * (float)0.001));
    this->current.pushVelocity.p[2] = (float)v6
                                    * (float)((float)1.0
                                            / (float)((float)__SPAIR64__(&unk_82390000, deltaTime) * (float)0.001));
    y = this->saved.worldAxis.mat[2].y;
    v9 = this->clipModel;
    v10 = this->saved.worldAxis.mat[1].y;
    v11 = this->saved.worldAxis.mat[0].y;
    x = this->saved.worldAxis.mat[2].x;
    v13 = this->saved.worldAxis.mat[1].x;
    v14 = this->saved.worldAxis.mat[0].x;
    z = this->saved.worldAxis.mat[2].z;
    v16 = this->saved.worldAxis.mat[1].z;
    v23 = this->saved.worldAxis.mat[0].z;
    v24 = v16;
    v25 = z;
    v22 = y;
    v21.mat[2].z = v10;
    v21.mat[2].y = v11;
    v21.mat[2].x = x;
    v21.mat[1].z = v13;
    v21.mat[1].y = v14;
    v17 = idMat3::operator*(this: &v26, result: &v9->axis, a: (idMat3 *)&v21.mat[1].y);
    v18 = idMat3::ToAngularVelocity(this: &v21, result: v17->mat);
    v19 = (float)(v18->y * (float)v7);
    v20 = (float)(v18->z * (float)v7);
    this->current.pushVelocity.p[3] = v18->x * (float)v7;
    this->current.pushVelocity.p[4] = v19;
    this->current.pushVelocity.p[5] = v20;
  }
}


// ========================================================================
// ?GetPushedLinearVelocity@idPhysics_RigidBody@@UBA?AVidVec3@@H@Z
// EA  : 0x8275D188
// RVA : 0x0075D188
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

idPhysics_RigidBody *__fastcall idPhysics_RigidBody::GetPushedLinearVelocity(
        idPhysics_RigidBody *this,
        idVec3 *result,
        const int id)
{
  float y; // r10
  float z; // r9

  y = result[34].y;
  z = result[34].z;
  this->__vftable = (idPhysics_RigidBody_vtbl *)LODWORD(result[34].x);
  *((float *)&this->__vftable + 1) = y;
  *(float *)&this->type = z;
  return this;
}


// ========================================================================
// ?GetPushedAngularVelocity@idPhysics_RigidBody@@UBA?AVidVec3@@H@Z
// EA  : 0x8275D1A8
// RVA : 0x0075D1A8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

idPhysics_RigidBody *__fastcall idPhysics_RigidBody::GetPushedAngularVelocity(
        idPhysics_RigidBody *this,
        idVec3 *result,
        const int id)
{
  float y; // r10
  float z; // r9

  y = result[35].y;
  z = result[35].z;
  this->__vftable = (idPhysics_RigidBody_vtbl *)LODWORD(result[35].x);
  *((float *)&this->__vftable + 1) = y;
  *(float *)&this->type = z;
  return this;
}


// ========================================================================
// ?SetMaster@idPhysics_RigidBody@@UAAX_NABVidVec3@@ABVidMat3@@W4bindFlags_t@@@Z
// EA  : 0x8275D1C8
// RVA : 0x0075D1C8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetMaster(
        idPhysics_RigidBody *this,
        __int64 masterOrigin,
        const idMat3 *masterAxis,
        const bindFlags_t bflags)
{
  unsigned __int64 index; // r11
  idClipModel *clipModel; // r11
  char v7; // r30
  double v8; // fp2
  double x; // fp9
  double v10; // fp7
  double v11; // fp10
  double v12; // fp8
  double z; // fp13
  double v14; // fp12
  idMat3 *p_axis; // r4
  double y; // fp11
  double v17; // fp10
  double v18; // fp9
  double v19; // fp8
  double v20; // fp7
  double v21; // fp6
  void (__fastcall *ClearContacts)(struct idPhysics_RigidBody *); // r5
  idPhysicsCallbacks *callbacks; // r3
  idMat3 v24; // [sp+50h] [-70h] BYREF
  idMat3 v25; // [sp+80h] [-40h] BYREF

  if ( this->clipModel != nullptr )
  {
    index = this->motionQuery.index;
    if ( (unsigned int)index >= *(_DWORD *)(HIDWORD(index) + 377212)
      && (unsigned int)index <= *(_DWORD *)(HIDWORD(index) + 377236) )
    {
      *(_DWORD *)(24 * ((index & 0xFFF) + 11621) + HIDWORD(index)) = 1;
    }
    this->motionQuery.index = masterOrigin & 0xFF00000000LL;
    if ( (masterOrigin & 0xFF00000000uLL) >> 32 != 0 )
    {
      if ( (*((_BYTE *)&this->fl + 4) & 0x10) == 0 )
      {
        clipModel = this->clipModel;
        v7 = bflags & 1;
        v8 = (float)(clipModel->origin.x - *(float *)masterOrigin);
        x = masterAxis->mat[2].x;
        v10 = masterAxis->mat[1].x;
        v11 = (float)((float)((float)(clipModel->origin.y - *(float *)(masterOrigin + 4)) * masterAxis->mat[1].y)
                    + (float)((float)(clipModel->origin.z - *(float *)(masterOrigin + 8)) * masterAxis->mat[1].z));
        v12 = (float)((float)((float)(clipModel->origin.y - *(float *)(masterOrigin + 4)) * masterAxis->mat[2].y)
                    + (float)((float)(clipModel->origin.z - *(float *)(masterOrigin + 8)) * masterAxis->mat[2].z));
        this->current.localOrigin.x = (float)((float)(clipModel->origin.x - *(float *)masterOrigin)
                                            * masterAxis->mat[0].x)
                                    + (float)((float)((float)(clipModel->origin.y - *(float *)(masterOrigin + 4))
                                                    * masterAxis->mat[0].y)
                                            + (float)((float)(clipModel->origin.z - *(float *)(masterOrigin + 8))
                                                    * masterAxis->mat[0].z));
        this->current.localOrigin.y = (float)((float)v8 * (float)v10) + (float)v11;
        this->current.localOrigin.z = (float)((float)v8 * (float)x) + (float)v12;
        if ( (bflags & 1) != 0 )
        {
          z = masterAxis->mat[1].z;
          v14 = masterAxis->mat[0].z;
          p_axis = &this->clipModel->axis;
          y = masterAxis->mat[2].y;
          v17 = masterAxis->mat[1].y;
          v18 = masterAxis->mat[0].y;
          v19 = masterAxis->mat[2].x;
          v20 = masterAxis->mat[1].x;
          v21 = masterAxis->mat[0].x;
          v24.mat[2].z = masterAxis->mat[2].z;
          v24.mat[2].y = z;
          v24.mat[2].x = v14;
          v24.mat[1].z = y;
          v24.mat[1].y = v17;
          v24.mat[1].x = v18;
          v24.mat[0].z = v19;
          v24.mat[0].y = v20;
          v24.mat[0].x = v21;
          this->current.localAxis = *idMat3::operator*(this: &v25, result: p_axis, a: &v24);
        }
        else
        {
          this->current.localAxis = this->clipModel->axis;
        }
        ClearContacts = this->ClearContacts;
        *((_BYTE *)&this->fl + 4) = (8 * v7) | 0x10 | *((_BYTE *)&this->fl + 4) & 0xF7;
        ClearContacts(this);
      }
    }
    else if ( (*((_BYTE *)&this->fl + 4) & 0x10) != 0 )
    {
      callbacks = this->callbacks;
      HIDWORD(masterOrigin) = this->physicsId;
      *((_BYTE *)&this->fl + 4) &= ~0x10u;
      ((void (__fastcall *)(idPhysicsCallbacks *, _DWORD, _DWORD, const idMat3 *, _BYTE))callbacks->ActivatePhysics)(
        a1: callbacks,
        a2: HIDWORD(masterOrigin),
        a3: masterOrigin,
        a4: masterAxis,
        a5: bflags);
    }
  }
}


// ========================================================================
// ?SetLocalOrigin@idPhysics_RigidBody@@UAAXABVidVec3@@H@Z
// EA  : 0x8275D460
// RVA : 0x0075D460
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetLocalOrigin(idPhysics_RigidBody *this, const idVec3 *newOrigin, int id)
{
  unsigned __int64 index; // r11
  __int64 v6; // r7
  idClipModel *clipModel; // r3
  int entityNumber; // r4
  int physicsId; // r5
  double v10; // fp1
  double v11; // fp13
  float v12[4]; // [sp+50h] [-60h] BYREF
  idVec3 v13; // [sp+60h] [-50h] BYREF
  float v14[10]; // [sp+70h] [-40h] BYREF

  if ( this->clipModel != nullptr )
  {
    index = this->motionQuery.index;
    v6 = *(_QWORD *)(HIDWORD(index) + 377208);
    if ( (unsigned int)index >= (unsigned int)v6 )
    {
      v6 = *(_QWORD *)(HIDWORD(index) + 377232);
      if ( (unsigned int)index <= (unsigned int)v6 )
      {
        HIDWORD(v6) = 24 * ((index & 0xFFF) + 11621);
        *(_DWORD *)(HIDWORD(v6) + HIDWORD(index)) = 1;
      }
    }
    LODWORD(index) = 0;
    this->motionQuery.index = index;
    if ( (*((_BYTE *)&this->fl + 4) & 0x10) != 0 )
    {
      ((void (__fastcall *)(idPhysicsCallbacks *, float *, float *, _DWORD))this->callbacks->GetMasterPosition)(
        a1: this->callbacks,
        a2: v12,
        a3: v14,
        a4: HIDWORD(v6));
      clipModel = this->clipModel;
      entityNumber = this->entityNumber;
      physicsId = this->physicsId;
      v10 = (float)((float)(newOrigin->z * v14[8])
                  + (float)((float)(newOrigin->x * v14[2]) + (float)(newOrigin->y * v14[5])));
      v11 = (float)(v12[1]
                  + (float)((float)(newOrigin->y * v14[4])
                          + (float)((float)(newOrigin->x * v14[1]) + (float)(newOrigin->z * v14[7]))));
      v13.x = (float)((float)(newOrigin->x * v14[0])
                    + (float)((float)(newOrigin->z * v14[6]) + (float)(newOrigin->y * v14[3])))
            + v12[0];
      v13.y = v11;
      v13.z = v12[2] + (float)v10;
      idClipModel::Link(
        this: clipModel,
        newEntityNumber: entityNumber,
        newPhysicsId: physicsId,
        newBodyId: clipModel->bodyId,
        newOrigin: &v13,
        newAxis: &clipModel->axis);
      this->current.localOrigin.x = newOrigin->x;
      this->current.localOrigin.y = newOrigin->y;
      this->current.localOrigin.z = newOrigin->z;
    }
    else
    {
      idClipModel::Link(
        this: this->clipModel,
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: this->clipModel->bodyId,
        newOrigin,
        newAxis: &this->clipModel->axis);
    }
    this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
  }
}


// ========================================================================
// ?SetLocalAxis@idPhysics_RigidBody@@UAAXABVidMat3@@H@Z
// EA  : 0x8275D608
// RVA : 0x0075D608
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::SetLocalAxis(idPhysics_RigidBody *this, idMat3 *newAxis, int id)
{
  unsigned __int64 index; // r11
  __int64 v6; // r7
  int v7; // r11
  idClipModel *clipModel; // r11
  const idVec3 *p_origin; // r29
  int physicsId; // r28
  int entityNumber; // r27
  int bodyId; // r26
  const idMat3 *v13; // r3
  _BYTE v14[16]; // [sp+50h] [-A0h] BYREF
  idMat3 v15; // [sp+60h] [-90h] BYREF
  idMat3 v16[2]; // [sp+90h] [-60h] BYREF

  if ( this->clipModel != nullptr )
  {
    index = this->motionQuery.index;
    v6 = *(_QWORD *)(HIDWORD(index) + 377208);
    if ( (unsigned int)index >= (unsigned int)v6 )
    {
      v6 = *(_QWORD *)(HIDWORD(index) + 377232);
      if ( (unsigned int)index <= (unsigned int)v6 )
      {
        HIDWORD(v6) = 24 * ((index & 0xFFF) + 11621);
        *(_DWORD *)(HIDWORD(v6) + HIDWORD(index)) = 1;
      }
    }
    LODWORD(index) = 0;
    this->motionQuery.index = index;
    v7 = *((unsigned __int8 *)&this->fl + 4);
    if ( (v7 & 0x10) != 0 && (v7 & 8) != 0 )
    {
      ((void (__fastcall *)(idPhysicsCallbacks *, _BYTE *, idMat3 *, _DWORD))this->callbacks->GetMasterPosition)(
        a1: this->callbacks,
        a2: v14,
        a3: &v15,
        a4: HIDWORD(v6));
      clipModel = this->clipModel;
      p_origin = &clipModel->origin;
      physicsId = this->physicsId;
      entityNumber = this->entityNumber;
      bodyId = clipModel->bodyId;
      v13 = idMat3::operator*(this: v16, result: newAxis, a: &v15);
      idClipModel::Link(
        this: this->clipModel,
        newEntityNumber: entityNumber,
        newPhysicsId: physicsId,
        newBodyId: bodyId,
        newOrigin: p_origin,
        newAxis: v13);
      this->current.localAxis.mat[0].x = newAxis->mat[0].x;
      this->current.localAxis.mat[0].y = newAxis->mat[0].y;
      this->current.localAxis.mat[0].z = newAxis->mat[0].z;
      this->current.localAxis.mat[1].x = newAxis->mat[1].x;
      this->current.localAxis.mat[1].y = newAxis->mat[1].y;
      this->current.localAxis.mat[1].z = newAxis->mat[1].z;
      this->current.localAxis.mat[2].x = newAxis->mat[2].x;
      this->current.localAxis.mat[2].y = newAxis->mat[2].y;
      this->current.localAxis.mat[2].z = newAxis->mat[2].z;
    }
    else
    {
      idClipModel::Link(
        this: this->clipModel,
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: this->clipModel->bodyId,
        newOrigin: &this->clipModel->origin,
        newAxis);
    }
    this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
  }
}


// ========================================================================
// ?Evolve@idPhysics_RigidBody@@AAAXMPAUtrace_t@@PAUcontactsResult_t@@@Z
// EA  : 0x8275D780
// RVA : 0x0075D780
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::Evolve(
        idPhysics_RigidBody *this,
        double timeStep,
        trace_t *collisionOverride,
        trace_t *contactOverride,
        contactsResult_t *a5)
{
  double v6; // fp10
  double v7; // fp7
  double v8; // fp4
  double v14; // fp5
  double v15; // fp5
  double v16; // fp1
  idVec3 *v17; // r10
  idClipModel *clipModel; // r11
  double x; // fp5
  double y; // fp4
  double z; // fp3
  idMat3 *p_axis; // r30
  const idMat3 *v23; // r3
  float *v24; // r3
  idClipModel *v25; // r10
  double v26; // fp12
  int entityNumber; // r30
  const idBounds *clipMask; // r29
  double v29; // fp8
  double v30; // fp7
  idClip *clip; // r4
  int v32; // r30
  const idBounds *v33; // r29
  double v34; // fp11
  double v35; // fp6
  idClip *v36; // r4
  unsigned __int64 v37; // r5
  const idMat3 *v38; // [sp+8h] [-188h]
  int v39; // [sp+Ch] [-184h]
  int v40; // [sp+10h] [-180h]
  bool v41; // [sp+17h] [-179h]
  const char *v42; // [sp+18h] [-178h]
  int v43; // [sp+1Ch] [-174h]
  int v44; // [sp+20h] [-170h]
  int v45; // [sp+24h] [-16Ch]
  int v46; // [sp+28h] [-168h]
  int v47; // [sp+2Ch] [-164h]
  int v48; // [sp+30h] [-160h]
  int v49; // [sp+34h] [-15Ch]
  int v50; // [sp+38h] [-158h]
  int v51; // [sp+3Ch] [-154h]
  int v52; // [sp+40h] [-150h]
  int v53; // [sp+44h] [-14Ch]
  int v54; // [sp+48h] [-148h]
  int v55; // [sp+4Ch] [-144h]
  int v56; // [sp+50h] [-140h]
  int v57; // [sp+58h] [-138h]
  int v58; // [sp+60h] [-130h]
  int v59; // [sp+68h] [-128h]
  int v60; // [sp+70h] [-120h]
  int v61; // [sp+78h] [-118h]
  float v62[4]; // [sp+80h] [-110h] BYREF
  idVec3 v63; // [sp+90h] [-100h] BYREF
  idVec3 v64; // [sp+A0h] [-F0h] BYREF
  idRotation v65; // [sp+B0h] [-E0h] BYREF
  idMat3 v66[2]; // [sp+100h] [-90h] BYREF

  v6 = (float)(this->current.spatialVelocity.p[4] - this->current.pushVelocity.p[4]);
  v7 = (float)(this->current.spatialVelocity.p[5] - this->current.pushVelocity.p[5]);
  v8 = (float)(this->current.spatialVelocity.p[3] - this->current.pushVelocity.p[3]);
  _FP9 = (float)((float)((float)((float)v8 * (float)v8)
                       + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f6, f9, f1, f13 }
  v14 = __frsqrte(_FP6);
  v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                      * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)))
                                                                                              * (float)0.5))
                                                                              * (float)v14)
                                                                      - (float)1.5)
                                                      * (float)v14)
                                              * (float)((float)((float)((float)v8 * (float)v8)
                                                              + (float)((float)((float)v7 * (float)v7)
                                                                      + (float)((float)v6 * (float)v6)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                              * (float)((float)((float)((float)v8 * (float)v8)
                                                                                              + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)))
                                                                                      * (float)0.5))
                                                                      * (float)v14)
                                                              - (float)1.5)
                                              * (float)v14))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v14
                                                      * (float)((float)((float)((float)v8 * (float)v8)
                                                                      + (float)((float)((float)v7 * (float)v7)
                                                                              + (float)((float)v6 * (float)v6)))
                                                              * (float)0.5))
                                              * (float)v14)
                                      - (float)1.5)
                      * (float)v14));
  v62[2] = (float)v7
         * (float)((float)-(float)((float)((float)((float)v15
                                                 * (float)((float)((float)((float)v8 * (float)v8)
                                                                 + (float)((float)((float)v7 * (float)v7)
                                                                         + (float)((float)v6 * (float)v6)))
                                                         * (float)0.5))
                                         * (float)v15)
                                 - (float)1.5)
                 * (float)v15);
  v62[0] = (float)((float)-(float)((float)((float)((float)v15
                                                 * (float)((float)((float)((float)v8 * (float)v8)
                                                                 + (float)((float)((float)v7 * (float)v7)
                                                                         + (float)((float)v6 * (float)v6)))
                                                         * (float)0.5))
                                         * (float)v15)
                                 - (float)1.5)
                 * (float)v15)
         * (float)v8;
  v62[1] = (float)v6
         * (float)((float)-(float)((float)((float)((float)v15
                                                 * (float)((float)((float)((float)v8 * (float)v8)
                                                                 + (float)((float)((float)v7 * (float)v7)
                                                                         + (float)((float)v6 * (float)v6)))
                                                         * (float)0.5))
                                         * (float)v15)
                                 - (float)1.5)
                 * (float)v15);
  v16 = idMath::AngleNormalize360(angle: (float)((float)-(float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6))) * (float)0.5)) * (float)v15)
                                                                                               - (float)1.5)
                                                                               * (float)v15)
                                                                       * (float)((float)((float)v8 * (float)v8)
                                                                               + (float)((float)((float)v7 * (float)v7)
                                                                                       + (float)((float)v6 * (float)v6))))
                                                               * idMath::M_RAD2DEG)
                                               * (float)timeStep));
  if ( v16 > 180.0 )
    v16 = (float)((float)v16 - (float)360.0);
  if ( v16 == 0.0 )
    v17 = &vec3_up;
  else
    v17 = (idVec3 *)v62;
  clipModel = this->clipModel;
  x = v17->x;
  y = v17->y;
  z = v17->z;
  p_axis = &clipModel->axis;
  v65.origin.x = clipModel->origin.x;
  v65.origin.y = clipModel->origin.y;
  v65.origin.z = clipModel->origin.z;
  v65.axisValid = false;
  v65.angle = v16;
  v65.vec.x = x;
  v65.vec.y = y;
  v65.axis.mat[0].x = mat3_identity.mat[0].x;
  v65.vec.z = z;
  v65.axis.mat[0].y = mat3_identity.mat[0].y;
  v65.axis.mat[0].z = mat3_identity.mat[0].z;
  v65.axis.mat[1].x = mat3_identity.mat[1].x;
  v65.axis.mat[1].y = mat3_identity.mat[1].y;
  v65.axis.mat[1].z = mat3_identity.mat[1].z;
  v65.axis.mat[2].x = mat3_identity.mat[2].x;
  v65.axis.mat[2].y = mat3_identity.mat[2].y;
  v65.axis.mat[2].z = mat3_identity.mat[2].z;
  v23 = idRotation::ToMat3(this: &v65);
  v24 = (float *)idMat3::operator*(this: v66, result: p_axis, a: v23);
  v25 = this->clipModel;
  v26 = (float)((float)((float)((float)(v25->axis.mat[0].z * this->centerOfMass.x)
                              + (float)((float)(v25->axis.mat[1].z * this->centerOfMass.y)
                                      + (float)(v25->axis.mat[2].z * this->centerOfMass.z)))
                      + (float)((float)(this->current.spatialVelocity.p[2] - this->current.pushVelocity.p[2])
                              * (float)timeStep))
              - (float)((float)(v24[8] * this->centerOfMass.z)
                      + (float)((float)(v24[2] * this->centerOfMass.x) + (float)(v24[5] * this->centerOfMass.y))));
  if ( contactOverride != nullptr && a5 != nullptr )
  {
    entityNumber = this->entityNumber;
    clipMask = (const idBounds *)this->clipMask;
    v29 = (float)(v25->origin.z
                + (float)((float)((float)((float)(v25->axis.mat[0].z * this->centerOfMass.x)
                                        + (float)((float)(v25->axis.mat[1].z * this->centerOfMass.y)
                                                + (float)(v25->axis.mat[2].z * this->centerOfMass.z)))
                                + (float)((float)(this->current.spatialVelocity.p[2] - this->current.pushVelocity.p[2])
                                        * (float)timeStep))
                        - (float)((float)(v24[8] * this->centerOfMass.z)
                                + (float)((float)(v24[2] * this->centerOfMass.x) + (float)(v24[5] * this->centerOfMass.y)))));
    v30 = (float)(v25->origin.y
                + (float)((float)((float)((float)(v25->axis.mat[0].y * this->centerOfMass.x)
                                        + (float)((float)(v25->axis.mat[1].y * this->centerOfMass.y)
                                                + (float)(v25->axis.mat[2].y * this->centerOfMass.z)))
                                + (float)((float)(this->current.spatialVelocity.p[1] - this->current.pushVelocity.p[1])
                                        * (float)timeStep))
                        - (float)((float)(v24[7] * this->centerOfMass.z)
                                + (float)((float)(v24[1] * this->centerOfMass.x) + (float)(v24[4] * this->centerOfMass.y)))));
    clip = this->clip;
    v64.x = v25->origin.x
          + (float)((float)((float)((float)(v25->axis.mat[0].x * this->centerOfMass.x)
                                  + (float)((float)(v25->axis.mat[1].x * this->centerOfMass.y)
                                          + (float)(v25->axis.mat[2].x * this->centerOfMass.z)))
                          + (float)((float)(this->current.spatialVelocity.p[0] - this->current.pushVelocity.p[0])
                                  * (float)timeStep))
                  - (float)((float)(this->centerOfMass.x * *v24)
                          + (float)((float)(v24[3] * this->centerOfMass.y) + (float)(v24[6] * this->centerOfMass.z))));
    v64.z = v29;
    v64.y = v30;
    idClip::MotionContacts(
      this: (idClip *)v62,
      result: clip,
      a3: contactOverride,
      contacts: a5,
      start: &v25->origin,
      end: &v64,
      rotation: &v65,
      depth: CONTACT_GATHERING_DEPTH_0,
      clipModel: v25,
      startAxis: v38,
      clipMask: v39,
      passEntityNumber: v40,
      moveClipModel: v41,
      userName: v42,
      a15: v43,
      a16: v44,
      a17: v45,
      a18: v46,
      a19: v47,
      a20: v48,
      a21: v49,
      a22: v50,
      a23: v51,
      a24: v52,
      a25: v53,
      a26: v54,
      a27: v55,
      a28: v56,
      a29: v25,
      a30: v57,
      a31: (int)&v25->axis,
      a32: v58,
      a33: clipMask,
      a34: v59,
      a35: entityNumber,
      a36: v60,
      clipModel_0_3: true,
      a38: v61,
      startAxisa: (const idMat3 *)"w:\\tech5\\engine\\gamelib\\physics\\Physics_RigidBody.cpp(70) : MotionContacts");
    this->lastTimeStep = timeStep;
  }
  else
  {
    v32 = this->entityNumber;
    v33 = (const idBounds *)this->clipMask;
    v34 = v25->origin.z;
    v35 = (float)(v25->origin.x
                + (float)((float)((float)((float)(v25->axis.mat[0].x * this->centerOfMass.x)
                                        + (float)((float)(v25->axis.mat[1].x * this->centerOfMass.y)
                                                + (float)(v25->axis.mat[2].x * this->centerOfMass.z)))
                                + (float)((float)(this->current.spatialVelocity.p[0] - this->current.pushVelocity.p[0])
                                        * (float)timeStep))
                        - (float)((float)(this->centerOfMass.x * *v24)
                                + (float)((float)(v24[3] * this->centerOfMass.y) + (float)(v24[6] * this->centerOfMass.z)))));
    v63.y = v25->origin.y
          + (float)((float)((float)((float)(v25->axis.mat[0].y * this->centerOfMass.x)
                                  + (float)((float)(v25->axis.mat[1].y * this->centerOfMass.y)
                                          + (float)(v25->axis.mat[2].y * this->centerOfMass.z)))
                          + (float)((float)(this->current.spatialVelocity.p[1] - this->current.pushVelocity.p[1])
                                  * (float)timeStep))
                  - (float)((float)(v24[7] * this->centerOfMass.z)
                          + (float)((float)(v24[1] * this->centerOfMass.x) + (float)(v24[4] * this->centerOfMass.y))));
    v63.x = v35;
    v36 = this->clip;
    v63.z = (float)v34 + (float)v26;
    v37 = *(_QWORD *)&idClip::MotionContacts(
                        this: (idClip *)v62,
                        result: v36,
                        a3: nullptr,
                        contacts: nullptr,
                        start: &v25->origin,
                        end: &v63,
                        rotation: &v65,
                        depth: CONTACT_GATHERING_DEPTH_0,
                        clipModel: v25,
                        startAxis: v38,
                        clipMask: v39,
                        passEntityNumber: v40,
                        moveClipModel: v41,
                        userName: v42,
                        a15: v43,
                        a16: v44,
                        a17: v45,
                        a18: v46,
                        a19: v47,
                        a20: v48,
                        a21: v49,
                        a22: v50,
                        a23: v51,
                        a24: v52,
                        a25: v53,
                        a26: v54,
                        a27: v55,
                        a28: v56,
                        a29: v25,
                        a30: v57,
                        a31: (int)&v25->axis,
                        a32: v58,
                        a33: v33,
                        a34: v59,
                        a35: v32,
                        a36: v60,
                        clipModel_0_3: true,
                        a38: v61,
                        startAxisa: (const idMat3 *)"w:\\tech5\\engine\\gamelib\\physics\\Physics_RigidBody.cpp(75) : MotionContacts")->world;
    this->lastTimeStep = timeStep;
    this->motionQuery.index = v37;
  }
}


// ========================================================================
// ?DropToFloorAndRest@idPhysics_RigidBody@@AAAXXZ
// EA  : 0x8275DB68
// RVA : 0x0075DB68
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::DropToFloorAndRest(idPhysics_RigidBody *this)
{
  idClipModel *clipModel; // r7
  int entityNumber; // r10
  int clipMask; // r9
  idClip *clip; // r4
  idClipModel *v6; // r11
  void (__fastcall *SetOrigin)(struct idPhysics_RigidBody *, const idVec3 *, int); // r8
  double y; // fp12
  double v9; // fp11
  idClipModel *v10; // r8
  double z; // fp12
  double x; // fp11
  int v13; // r10
  double v14; // fp9
  double v15; // fp5
  idClip *v16; // r4
  idPhysics_RigidBody_vtbl *v17; // r11
  char v18; // r3
  const char *v19; // [sp+8h] [-1C8h]
  int v20; // [sp+Ch] [-1C4h]
  const char *v21; // [sp+10h] [-1C0h]
  int v22; // [sp+14h] [-1BCh]
  int v23; // [sp+18h] [-1B8h]
  int v24; // [sp+1Ch] [-1B4h]
  int v25; // [sp+20h] [-1B0h]
  int v26; // [sp+24h] [-1ACh]
  int v27; // [sp+28h] [-1A8h]
  int v28; // [sp+2Ch] [-1A4h]
  int v29; // [sp+30h] [-1A0h]
  int v30; // [sp+34h] [-19Ch]
  int v31; // [sp+38h] [-198h]
  int v32; // [sp+3Ch] [-194h]
  int v33; // [sp+40h] [-190h]
  int v34; // [sp+44h] [-18Ch]
  int v35; // [sp+48h] [-188h]
  int v36; // [sp+4Ch] [-184h]
  int v37; // [sp+50h] [-180h]
  int v38; // [sp+54h] [-17Ch]
  int v39; // [sp+58h] [-178h]
  int v40; // [sp+60h] [-170h]
  _BYTE v41[8]; // [sp+70h] [-160h] BYREF
  idVec3 v42; // [sp+78h] [-158h] BYREF
  float v43[6]; // [sp+88h] [-148h] BYREF
  trace_t v44; // [sp+A0h] [-130h] BYREF
  trace_t v45; // [sp+120h] [-B0h] BYREF

  if ( !this->IsInNonResidentCollisionArea(this, a2: true) )
  {
    if ( (*((_BYTE *)&this->fl + 4) & 0x40) == 0 )
      goto LABEL_6;
    clipModel = this->clipModel;
    entityNumber = this->entityNumber;
    clipMask = this->clipMask;
    clip = this->clip;
    *((_BYTE *)&this->fl + 4) &= ~0x40u;
    idClip::Contents(
      this: (idClip *)v41,
      result: clip,
      a3: &v44,
      start: &clipModel->origin,
      clipModel,
      startAxis: &clipModel->axis,
      clipMask,
      passEntityNumber: entityNumber,
      userName: v19,
      a10: v20,
      a11: (int)v21,
      a12: v22,
      a13: v23,
      a14: v24,
      a15: v25,
      a16: v26,
      a17: v27,
      a18: v28,
      a19: v29,
      a20: v30,
      a21: v31,
      a22: v32,
      a23: v33,
      a24: v34,
      a25: v35,
      a26: v36,
      a27: v37,
      a28: 0);
    if ( v44.c.contentFlags == 0 )
      goto LABEL_6;
    v6 = this->clipModel;
    SetOrigin = this->SetOrigin;
    y = v6->origin.y;
    v9 = (float)(v6->origin.z + (float)0.5);
    v43[0] = v6->origin.x;
    v43[1] = y;
    v43[2] = v9;
    SetOrigin(this, a2: (const idVec3 *)v43, a3: -1);
    idClip::Contents(
      this: (idClip *)v41,
      result: this->clip,
      a3: &v44,
      start: &this->clipModel->origin,
      clipModel: this->clipModel,
      startAxis: &this->clipModel->axis,
      clipMask: this->clipMask,
      passEntityNumber: this->entityNumber,
      userName: v19,
      a10: v20,
      a11: (int)v21,
      a12: v22,
      a13: v23,
      a14: v24,
      a15: v25,
      a16: v26,
      a17: v27,
      a18: v28,
      a19: v29,
      a20: v30,
      a21: v31,
      a22: v32,
      a23: v33,
      a24: v34,
      a25: v35,
      a26: v36,
      a27: v37,
      a28: 0);
    if ( v44.c.contentFlags != 0 )
    {
      this->callbacks->DeactivatePhysics(this: this->callbacks, a2: this->physicsId);
      *((_BYTE *)&this->fl + 4) &= ~0x80u;
    }
    else
    {
LABEL_6:
      v10 = this->clipModel;
      z = this->gravityNormal.z;
      x = this->gravityNormal.x;
      v13 = this->clipMask;
      v38 = this->entityNumber;
      v14 = v10->origin.z;
      v15 = v10->origin.x;
      v16 = this->clip;
      v42.y = v10->origin.y + (float)(this->gravityNormal.y * (float)128.0);
      v42.z = (float)v14 + (float)((float)z * (float)128.0);
      v42.x = (float)v15 + (float)((float)x * (float)128.0);
      idClip::Translation(
        this: (idClip *)v41,
        result: v16,
        a3: &v45,
        start: &v10->origin,
        end: &v42,
        clipModel: v10,
        startAxis: &v10->axis,
        clipMask: v13,
        passEntityNumber: (int)v19,
        moveClipModel: v20,
        userName: v21,
        a12: v22,
        a13: v23,
        a14: v24,
        a15: v25,
        a16: v26,
        a17: v27,
        a18: v28,
        a19: v29,
        a20: v30,
        a21: v31,
        a22: v32,
        a23: v33,
        a24: v34,
        a25: v35,
        a26: v36,
        a27: v37,
        a28: v38,
        a29: v39,
        a30: false,
        a31: v40,
        a32: 0);
      idClipModel::Link(
        this: this->clipModel,
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: this->clipModel->bodyId,
        newOrigin: &v45.endpos,
        newAxis: &this->clipModel->axis);
      v17 = this->__vftable;
      if ( v45.fraction == 0.0 )
      {
        v17->EvaluateContacts(this);
        v18 = idPhysics_RigidBody::TestIfAtRest(this);
      }
      else
      {
        v18 = v17->IsOutsideWorld(this);
      }
      if ( v18 != 0 )
        this->callbacks->DeactivatePhysics(this: this->callbacks, a2: this->physicsId);
      *((_BYTE *)&this->fl + 4) &= ~0x80u;
      this->current.externalForce.p[5] = 0.0;
      this->current.externalForce.p[4] = 0.0;
      this->current.externalForce.p[3] = 0.0;
      this->current.externalForce.p[2] = 0.0;
      this->current.externalForce.p[1] = 0.0;
      this->current.externalForce.p[0] = 0.0;
    }
  }
}


// ========================================================================
// ??0idPhysics_RigidBody@@QAA@XZ
// EA  : 0x8275DDC8
// RVA : 0x0075DDC8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

idPhysics_RigidBody *__fastcall idPhysics_RigidBody::idPhysics_RigidBody(idPhysics_RigidBody *this)
{
  unsigned __int64 v1; // r29

  idPhysics_DynamicBase::idPhysics_DynamicBase(this);
  LODWORD(v1) = 0;
  this->__vftable = (idPhysics_RigidBody_vtbl *)&idPhysics_RigidBody::`vftable';
  this->motionQuery.index = v1;
  this->type = PHYSICS_RIGIDBODY;
  this->linearFriction = 0.0;
  this->angularFriction = 0.0;
  this->contactFriction = 0.0;
  this->linearFrictionWater = 0.0;
  this->angularFrictionWater = 0.0;
  this->bouncyness = 0.0;
  idPhysics_DynamicBase::SetClipMask(this, mask: 1, id: -1);
  this->contactFriction = 0.0;
  this->bouncyness = 0.60000002;
  this->linearFriction = 0.60000002;
  this->angularFriction = 0.60000002;
  this->linearFrictionWater = 1.0;
  this->angularFrictionWater = 1.0;
  this->inertiaScale.x = 1.0;
  this->inertiaScale.y = 1.0;
  this->inertiaScale.z = 1.0;
  this->current.atRest = -1;
  this->waterLevel = 0.0;
  this->clipModel = nullptr;
  this->current.localOrigin.z = 0.0;
  this->current.localOrigin.y = 0.0;
  this->current.localOrigin.x = 0.0;
  this->current.localAxis.mat[2].z = 1.0;
  this->current.localAxis.mat[1].y = 1.0;
  this->current.localAxis.mat[0].x = 1.0;
  this->current.localAxis.mat[1].z = 0.0;
  this->current.localAxis.mat[0].z = 0.0;
  this->current.localAxis.mat[0].y = 0.0;
  this->current.localAxis.mat[2].y = 0.0;
  this->current.localAxis.mat[2].x = 0.0;
  this->current.localAxis.mat[1].x = 0.0;
  this->current.worldOrigin.z = 0.0;
  this->current.worldOrigin.y = 0.0;
  this->current.worldOrigin.x = 0.0;
  this->current.worldAxis.mat[2].z = 1.0;
  this->current.worldAxis.mat[1].y = 1.0;
  this->current.worldAxis.mat[0].x = 1.0;
  this->current.worldAxis.mat[1].z = 0.0;
  this->current.worldAxis.mat[0].z = 0.0;
  this->current.worldAxis.mat[0].y = 0.0;
  this->current.worldAxis.mat[2].y = 0.0;
  this->current.worldAxis.mat[2].x = 0.0;
  this->current.worldAxis.mat[1].x = 0.0;
  this->current.spatialVelocity.p[5] = 0.0;
  this->current.spatialVelocity.p[4] = 0.0;
  this->current.spatialVelocity.p[3] = 0.0;
  this->current.spatialVelocity.p[2] = 0.0;
  this->current.spatialVelocity.p[1] = 0.0;
  this->current.spatialVelocity.p[0] = 0.0;
  this->current.externalForce.p[5] = 0.0;
  this->current.externalForce.p[4] = 0.0;
  this->current.externalForce.p[3] = 0.0;
  this->current.externalForce.p[2] = 0.0;
  this->current.externalForce.p[1] = 0.0;
  this->current.externalForce.p[0] = 0.0;
  this->current.pushVelocity.p[5] = 0.0;
  this->current.pushVelocity.p[4] = 0.0;
  this->current.pushVelocity.p[3] = 0.0;
  this->current.pushVelocity.p[2] = 0.0;
  this->current.pushVelocity.p[1] = 0.0;
  this->current.pushVelocity.p[0] = 0.0;
  rigidBodyPState_t::operator=(this: &this->saved, __that: &this->current);
  this->mass = 1.0;
  this->inverseMass = 1.0;
  this->centerOfMass.z = 0.0;
  this->centerOfMass.y = 0.0;
  this->centerOfMass.x = 0.0;
  this->inertiaTensor.mat[2].z = 1.0;
  this->inertiaTensor.mat[1].y = 1.0;
  this->inertiaTensor.mat[0].x = 1.0;
  this->inertiaTensor.mat[1].z = 0.0;
  this->inertiaTensor.mat[0].z = 0.0;
  this->inertiaTensor.mat[0].y = 0.0;
  this->inertiaTensor.mat[2].y = 0.0;
  this->inertiaTensor.mat[2].x = 0.0;
  this->inertiaTensor.mat[1].x = 0.0;
  this->inverseInertiaTensor.mat[2].z = 1.0;
  this->inverseInertiaTensor.mat[1].y = 1.0;
  this->inverseInertiaTensor.mat[0].x = 1.0;
  this->inverseInertiaTensor.mat[1].z = 0.0;
  this->inverseInertiaTensor.mat[0].z = 0.0;
  this->inverseInertiaTensor.mat[0].y = 0.0;
  this->inverseInertiaTensor.mat[2].y = 0.0;
  this->inverseInertiaTensor.mat[2].x = 0.0;
  this->inverseInertiaTensor.mat[1].x = 0.0;
  this->fl.noPushMask = 0;
  this->lastTimeStep = 0.0;
  *((_BYTE *)&this->fl + 4) &= 7u;
  return this;
}


// ========================================================================
// __unwind$251897
// EA  : 0x8275E014
// RVA : 0x0075E014
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void _unwind_251897()
{
  int v0; // r12

  idPhysics_DynamicBase::~idPhysics_DynamicBase(this: *(idPhysics_DynamicBase **)(v0 - 144 + 164));
}


// ========================================================================
// ?ClipContents@idPhysics_RigidBody@@UBAHPBVidClipModel@@H@Z
// EA  : 0x8275E040
// RVA : 0x0075E040
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

int __fastcall idPhysics_RigidBody::ClipContents(idPhysics_RigidBody *this, idClipModel *model, int clipMask)
{
  int v3; // r8
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

  v3 = clipMask;
  if ( this->clipModel == nullptr )
    return 0;
  if ( model != nullptr )
  {
    if ( clipMask == 0 )
      v3 = this->clipMask;
    idClip::ContentsModel(
      this: this->clip,
      result: &v26,
      start: &this->clipModel->origin,
      trm: this->clipModel,
      trmAxis: &this->clipModel->axis,
      clipMask: v3,
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
    v5 = clipMask;
    if ( clipMask == 0 )
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
// ?ResolveCollisions@idPhysics_RigidBody@@AAAXPAUtrace_t@@PAUcontactsResult_t@@@Z
// EA  : 0x8275E110
// RVA : 0x0075E110
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::ResolveCollisions(
        idPhysics_RigidBody *this,
        trace_t *collisionOverride,
        contactsResult_t *contactOverride)
{
  trace_t *v6; // r28
  contactsResult_t *v7; // r27
  double v8; // fp15
  __int128 v9; // r11
  int v10; // r29
  const contactInfo_t *contacts; // r30
  float *clipModel; // r11
  double v13; // fp18
  double v14; // fp17
  double v15; // fp16
  const idMat3 *v16; // r30
  idPhysics *v17; // r26
  double v18; // fp13
  double v19; // fp12
  double v20; // fp11
  double v21; // fp10
  double v22; // fp9
  double v23; // fp8
  double v24; // fp7
  double v25; // fp6
  idMat3 *v26; // r3
  float *v27; // r9
  bool v28; // mr_fpscr48
  double v29; // fp14
  double v30; // fp4
  double z; // fp27
  double y; // fp26
  double x; // fp25
  double v34; // fp8
  double v35; // fp24
  double v36; // fp23
  double v37; // fp22
  double v38; // fp21
  double v39; // fp20
  double v40; // fp19
  double v41; // fp31
  double v42; // fp30
  double v43; // fp29
  idPhysics_RigidBody *PhysicsForId; // r3
  idPhysicsCallbacks *callbacks; // r3
  double v46; // fp31
  double v47; // fp30
  double v48; // fp29
  int physicsId; // r4
  float *v50; // r29
  idVec6 *p_spatialVelocity; // r30
  double v52; // fp8
  double v53; // fp6
  int v54; // r27
  double v55; // fp12
  double v56; // fp13
  double v57; // fp11
  double inverseMass; // fp0
  double v59; // fp10
  double v60; // fp9
  double v61; // fp10
  double v62; // fp4
  double v63; // fp7
  double v64; // fp5
  double v65; // fp2
  double v66; // fp0
  double v67; // fp0
  double v68; // fp9
  double v69; // fp13
  double v70; // fp12
  double v71; // fp8
  double v72; // fp7
  double v73; // fp3
  double v74; // fp1
  double v75; // fp1
  double waterLevel; // fp31
  double v77; // fp30
  double v78; // fp1
  double v79; // fp13
  double v80; // fp0
  double v81; // fp4
  double v82; // fp2
  double v83; // fp11
  double v84; // fp10
  double v85; // fp5
  double v86; // fp12
  double v87; // fp13
  double v88; // fp11
  idPhysicsCallbacks *v89; // r3
  int v90; // r26
  int v91; // r28
  contactInfo_t *v92; // r11
  double v93; // fp30
  double v94; // fp31
  double v95; // fp29
  double v96; // fp18
  double v97; // fp16
  double v98; // fp17
  idPhysics_RigidBody *v99; // r3
  contactInfo_t *v100; // r11
  double v101; // fp0
  double v102; // fp13
  double v103; // fp12
  double v104; // fp4
  double v105; // fp3
  double v106; // fp2
  double v107; // fp6
  double v110; // fp7
  double v111; // fp5
  double v112; // fp7
  double v113; // fp5
  double v114; // fp4
  double v115; // fp3
  double v116; // fp2
  double v117; // fp1
  double v118; // fp1
  double v119; // fp2
  double v120; // fp11
  double v121; // fp9
  double v122; // fp7
  double v123; // fp6
  double v124; // fp5
  double v125; // fp4
  double v126; // fp3
  double v127; // fp10
  double v128; // fp1
  double v129; // fp11
  double v130; // fp2
  double v131; // fp5
  double v132; // fp4
  double v133; // fp10
  double v134; // fp9
  double v135; // fp3
  double v136; // fp11
  double v137; // fp10
  double v138; // fp8
  double v139; // fp6
  double v140; // fp5
  double v141; // fp2
  double v144; // fp4
  double v145; // fp1
  double v146; // fp12
  double v147; // fp11
  double v148; // fp10
  double v149; // fp4
  double v150; // fp8
  double v151; // fp0
  double v152; // fp13
  double v153; // fp13
  double v154; // fp3
  double v155; // fp2
  double v156; // fp2
  double v157; // fp4
  double v158; // fp3
  double v159; // fp0
  double v160; // fp12
  float v161; // [sp+54h] [-5ACh]
  float v162; // [sp+58h] [-5A8h] BYREF
  float v163; // [sp+5Ch] [-5A4h]
  float v164; // [sp+60h] [-5A0h]
  idMat3 v165; // [sp+70h] [-590h] BYREF
  float v166; // [sp+98h] [-568h]
  float v167; // [sp+9Ch] [-564h]
  float v168; // [sp+A0h] [-560h]
  float v169; // [sp+A4h] [-55Ch]
  float v170; // [sp+A8h] [-558h]
  impactInfo_t v171; // [sp+B0h] [-550h] BYREF
  float v172[4]; // [sp+F0h] [-510h] BYREF
  double v173; // [sp+100h] [-500h]
  trace_t v174; // [sp+110h] [-4F0h] BYREF
  contactsResult_t v175; // [sp+190h] [-470h] BYREF

  if ( collisionOverride != nullptr
    || contactOverride != nullptr
    || (unsigned __int8)idClip::QueryIsValid(this: this->clip, clipQuery: &this->motionQuery) != 0 )
  {
    v6 = &v174;
    v7 = &v175;
    v8 = 0.0;
    v170 = 0.0;
    this->current.pushVelocity.p[5] = 0.0;
    this->current.pushVelocity.p[4] = 0.0;
    this->current.pushVelocity.p[3] = 0.0;
    this->current.pushVelocity.p[2] = 0.0;
    this->current.pushVelocity.p[1] = 0.0;
    this->current.pushVelocity.p[0] = 0.0;
    if ( collisionOverride != nullptr && contactOverride != nullptr )
    {
      v6 = collisionOverride;
      v7 = contactOverride;
      idClipModel::Link(
        this: this->clipModel,
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: this->clipModel->bodyId,
        newOrigin: &collisionOverride->endpos,
        newAxis: &collisionOverride->endAxis);
    }
    else
    {
      LODWORD(v9) = 0;
      *(_QWORD *)((char *)&v9 + 4) = this->motionQuery.index;
      DWORD1(v9) = this->clip;
      this->motionQuery.index = v9;
      idCollisionModelManager::GetMotionContactsResult(
        this: collisionModelManager,
        result: &v174,
        contacts: &v175,
        query: (idCollisionQuery *)(24 * (WORD5(v9) & 0xFFF) + DWORD1(v9) + 278920),
        peek: false);
    }
    idPhysics::UpdateCollisionResidency(this, contact: &v6->c);
    this->ClearContacts(this);
    v10 = 0;
    if ( v7->numContacts > 0 )
    {
      contacts = v7->contacts;
      do
      {
        idList<contactInfo_t,77>::Append(this: &this->contacts, obj: contacts);
        ++v10;
        ++contacts;
      }
      while ( v10 < v7->numContacts );
    }
    idPhysics_DynamicBase::AddContactPhysicsForContacts(this);
    clipModel = (float *)this->clipModel;
    v13 = 0.0;
    v14 = 0.0;
    v15 = 0.0;
    v16 = (const idMat3 *)(clipModel + 11);
    v17 = nullptr;
    v18 = clipModel[16];
    v19 = clipModel[13];
    v20 = clipModel[18];
    v21 = clipModel[15];
    v22 = clipModel[12];
    v23 = clipModel[17];
    v24 = clipModel[14];
    v25 = clipModel[11];
    v165.mat[2].z = clipModel[19];
    v165.mat[2].y = v18;
    v165.mat[2].x = v19;
    v165.mat[1].z = v20;
    v165.mat[1].y = v21;
    v165.mat[1].x = v22;
    v165.mat[0].z = v23;
    v165.mat[0].y = v24;
    v165.mat[0].x = v25;
    v26 = idMat3::operator*(this: (idMat3 *)&v171, result: &v165, a: &this->inverseInertiaTensor);
    idMat3::operator*(this: &v165, result: v26, a: v16);
    v27 = (float *)this->clipModel;
    v28 = v6->fraction < 1.0;
    v29 = 0.5;
    v30 = v27[10];
    z = v165.mat[2].z;
    y = v165.mat[2].y;
    x = v165.mat[2].x;
    v34 = (float)((float)(v27[19] * this->centerOfMass.z)
                + (float)((float)(v27[13] * this->centerOfMass.x) + (float)(v27[16] * this->centerOfMass.y)));
    v35 = v165.mat[1].z;
    v36 = v165.mat[1].y;
    v37 = v165.mat[1].x;
    v38 = v165.mat[0].z;
    v39 = v165.mat[0].y;
    v40 = v165.mat[0].x;
    v41 = (float)((float)((float)(this->centerOfMass.x * v27[11])
                        + (float)((float)(v27[14] * this->centerOfMass.y) + (float)(v27[17] * this->centerOfMass.z)))
                + v27[8]);
    v42 = (float)(v27[9]
                + (float)((float)(v27[18] * this->centerOfMass.z)
                        + (float)((float)(v27[12] * this->centerOfMass.x) + (float)(v27[15] * this->centerOfMass.y))));
    v167 = v27[9]
         + (float)((float)(v27[18] * this->centerOfMass.z)
                 + (float)((float)(v27[12] * this->centerOfMass.x) + (float)(v27[15] * this->centerOfMass.y)));
    v166 = v41;
    v43 = (float)((float)v30 + (float)v34);
    v168 = (float)v30 + (float)v34;
    if ( v28 )
    {
      PhysicsForId = (idPhysics_RigidBody *)idPhysics::GetPhysicsForId(physicsId_: v6->c.physicsId);
      if ( PhysicsForId == nullptr || PhysicsForId == this )
        impactInfo_t::Zero(this: &v171);
      else
        PhysicsForId->GetImpactInfo(this: PhysicsForId, a2: v6->c.bodyId, a3: &v6->c.point, a4: &v171);
      callbacks = this->callbacks;
      v46 = (float)(v6->c.point.x - (float)v41);
      v47 = (float)(v6->c.point.y - (float)v42);
      v48 = (float)(v6->c.point.z - (float)v43);
      physicsId = this->physicsId;
      v50 = &this->current.spatialVelocity.p[3];
      p_spatialVelocity = &this->current.spatialVelocity;
      v52 = (float)(this->current.spatialVelocity.p[1]
                  + (float)((float)(this->current.spatialVelocity.p[5] * (float)v46)
                          - (float)(this->current.spatialVelocity.p[3] * (float)v48)));
      v53 = (float)((float)((float)((float)(this->current.spatialVelocity.p[4] * (float)v48)
                                  - (float)(this->current.spatialVelocity.p[5] * (float)v47))
                          + this->current.spatialVelocity.p[0])
                  - v171.velocity.x);
      v164 = (float)(this->current.spatialVelocity.p[2]
                   + (float)((float)(this->current.spatialVelocity.p[3] * (float)v47)
                           - (float)(this->current.spatialVelocity.p[4] * (float)v46)))
           - v171.velocity.z;
      v162 = v53;
      v163 = (float)v52 - v171.velocity.y;
      v54 = callbacks->Collide(this: callbacks, a2: physicsId, a3: v6, a4: (const idVec3 *)&v162);
      v17 = idPhysics::GetPhysicsForId(physicsId_: v6->c.physicsId);
      if ( v54 == 1 )
      {
        this->current.atRest = 1;
        this->current.spatialVelocity.p[5] = 0.0;
        this->current.spatialVelocity.p[4] = 0.0;
        this->current.spatialVelocity.p[3] = 0.0;
        this->current.spatialVelocity.p[2] = 0.0;
        this->current.spatialVelocity.p[1] = 0.0;
        p_spatialVelocity->p[0] = 0.0;
        this->callbacks->DeactivatePhysics(this: this->callbacks, a2: this->physicsId);
        return;
      }
      if ( v54 == 2 )
      {
        v17 = nullptr;
      }
      else
      {
        v55 = v6->c.normal.x;
        v56 = v6->c.normal.z;
        v57 = v6->c.normal.y;
        if ( (float)((float)(v6->c.normal.y * v163)
                   + (float)((float)(v6->c.normal.z * v164) + (float)(v6->c.normal.x * v162))) <= -20.0 )
          v161 = -(float)((float)(this->bouncyness + (float)1.0)
                        * (float)((float)(v6->c.normal.y * v163)
                                + (float)((float)(v6->c.normal.z * v164) + (float)(v6->c.normal.x * v162))));
        else
          v161 = 20.0;
        inverseMass = this->inverseMass;
        v59 = (float)((float)((float)v46
                            * (float)((float)((float)v35
                                            * (float)((float)((float)v55 * (float)v48) - (float)((float)v56 * (float)v46)))
                                    + (float)((float)((float)((float)((float)v56 * (float)v47)
                                                            - (float)((float)v57 * (float)v48))
                                                    * (float)v38)
                                            + (float)((float)z
                                                    * (float)((float)((float)v57 * (float)v46)
                                                            - (float)((float)v55 * (float)v47))))))
                    - (float)((float)((float)((float)v37
                                            * (float)((float)((float)v55 * (float)v48) - (float)((float)v56 * (float)v46)))
                                    + (float)((float)((float)v40
                                                    * (float)((float)((float)v56 * (float)v47)
                                                            - (float)((float)v57 * (float)v48)))
                                            + (float)((float)x
                                                    * (float)((float)((float)v57 * (float)v46)
                                                            - (float)((float)v55 * (float)v47)))))
                            * (float)v48));
        v60 = (float)((float)((float)((float)((float)v36
                                            * (float)((float)((float)v55 * (float)v48) - (float)((float)v56 * (float)v46)))
                                    + (float)((float)((float)((float)((float)v56 * (float)v47)
                                                            - (float)((float)v57 * (float)v48))
                                                    * (float)v39)
                                            + (float)((float)y
                                                    * (float)((float)((float)v57 * (float)v46)
                                                            - (float)((float)v55 * (float)v47)))))
                            * (float)v48)
                    - (float)((float)((float)((float)v35
                                            * (float)((float)((float)v55 * (float)v48) - (float)((float)v56 * (float)v46)))
                                    + (float)((float)((float)((float)((float)v56 * (float)v47)
                                                            - (float)((float)v57 * (float)v48))
                                                    * (float)v38)
                                            + (float)((float)z
                                                    * (float)((float)((float)v57 * (float)v46)
                                                            - (float)((float)v55 * (float)v47)))))
                            * (float)v47));
        v61 = (float)((float)((float)((float)v55 * (float)v60)
                            + (float)((float)((float)v57 * (float)v59)
                                    + (float)((float)v56
                                            * (float)((float)((float)((float)((float)v37
                                                                            * (float)((float)((float)v55 * (float)v48)
                                                                                    - (float)((float)v56 * (float)v46)))
                                                                    + (float)((float)((float)v40
                                                                                    * (float)((float)((float)v56 * (float)v47)
                                                                                            - (float)((float)v57 * (float)v48)))
                                                                            + (float)((float)x
                                                                                    * (float)((float)((float)v57 * (float)v46)
                                                                                            - (float)((float)v55 * (float)v47)))))
                                                            * (float)v47)
                                                    - (float)((float)v46
                                                            * (float)((float)((float)v36
                                                                            * (float)((float)((float)v55 * (float)v48)
                                                                                    - (float)((float)v56 * (float)v46)))
                                                                    + (float)((float)((float)((float)((float)v56 * (float)v47)
                                                                                            - (float)((float)v57 * (float)v48))
                                                                                    * (float)v39)
                                                                            + (float)((float)y
                                                                                    * (float)((float)((float)v57 * (float)v46)
                                                                                            - (float)((float)v55 * (float)v47))))))))))
                    + this->inverseMass);
        if ( v171.invMass != 0.0 )
        {
          v169 = v171.invInertiaTensor.mat[1].y;
          v29 = (float)0.5;
          v173 = inverseMass;
          v8 = v170;
          v62 = (float)((float)((float)((float)(v171.invInertiaTensor.mat[1].x
                                              * (float)((float)((float)v55 * v171.position.z)
                                                      - (float)((float)v56 * v171.position.x)))
                                      + (float)((float)(v171.invInertiaTensor.mat[0].x
                                                      * (float)((float)((float)v56 * v171.position.y)
                                                              - (float)((float)v57 * v171.position.z)))
                                              + (float)(v171.invInertiaTensor.mat[2].x
                                                      * (float)((float)((float)v57 * v171.position.x)
                                                              - (float)((float)v55 * v171.position.y)))))
                              * v171.position.y)
                      - (float)(v171.position.x
                              * (float)((float)(v171.invInertiaTensor.mat[1].y
                                              * (float)((float)((float)v55 * v171.position.z)
                                                      - (float)((float)v56 * v171.position.x)))
                                      + (float)((float)((float)((float)((float)v56 * v171.position.y)
                                                              - (float)((float)v57 * v171.position.z))
                                                      * v171.invInertiaTensor.mat[0].y)
                                              + (float)(v171.invInertiaTensor.mat[2].y
                                                      * (float)((float)((float)v57 * v171.position.x)
                                                              - (float)((float)v55 * v171.position.y)))))));
          v61 = (float)((float)((float)((float)((float)v56 * (float)v62)
                                      + (float)((float)((float)v55
                                                      * (float)((float)((float)((float)(v171.invInertiaTensor.mat[1].y
                                                                                      * (float)((float)((float)v55 * v171.position.z)
                                                                                              - (float)((float)v56 * v171.position.x)))
                                                                              + (float)((float)((float)((float)((float)v56 * v171.position.y) - (float)((float)v57 * v171.position.z))
                                                                                              * v171.invInertiaTensor.mat[0].y)
                                                                                      + (float)(v171.invInertiaTensor.mat[2].y
                                                                                              * (float)((float)((float)v57 * v171.position.x) - (float)((float)v55 * v171.position.y)))))
                                                                      * v171.position.z)
                                                              - (float)((float)((float)(v171.invInertiaTensor.mat[1].z
                                                                                      * (float)((float)((float)v55 * v171.position.z)
                                                                                              - (float)((float)v56 * v171.position.x)))
                                                                              + (float)((float)((float)((float)((float)v56 * v171.position.y) - (float)((float)v57 * v171.position.z))
                                                                                              * v171.invInertiaTensor.mat[0].z)
                                                                                      + (float)(v171.invInertiaTensor.mat[2].z
                                                                                              * (float)((float)((float)v57 * v171.position.x) - (float)((float)v55 * v171.position.y)))))
                                                                      * v171.position.y)))
                                              + (float)((float)v57
                                                      * (float)((float)(v171.position.x
                                                                      * (float)((float)(v171.invInertiaTensor.mat[1].z
                                                                                      * (float)((float)((float)v55 * v171.position.z)
                                                                                              - (float)((float)v56 * v171.position.x)))
                                                                              + (float)((float)((float)((float)((float)v56 * v171.position.y) - (float)((float)v57 * v171.position.z))
                                                                                              * v171.invInertiaTensor.mat[0].z)
                                                                                      + (float)(v171.invInertiaTensor.mat[2].z
                                                                                              * (float)((float)((float)v57 * v171.position.x) - (float)((float)v55 * v171.position.y))))))
                                                              - (float)((float)((float)(v171.invInertiaTensor.mat[1].x
                                                                                      * (float)((float)((float)v55 * v171.position.z)
                                                                                              - (float)((float)v56 * v171.position.x)))
                                                                              + (float)((float)(v171.invInertiaTensor.mat[0].x
                                                                                              * (float)((float)((float)v56 * v171.position.y) - (float)((float)v57 * v171.position.z)))
                                                                                      + (float)(v171.invInertiaTensor.mat[2].x
                                                                                              * (float)((float)((float)v57 * v171.position.x) - (float)((float)v55 * v171.position.y)))))
                                                                      * v171.position.z)))))
                              + v171.invMass)
                      + (float)v61);
        }
        v63 = p_spatialVelocity->p[0];
        v64 = this->current.spatialVelocity.p[2];
        v14 = (float)((float)v57 * (float)(v161 / (float)v61));
        v13 = (float)((float)v55 * (float)(v161 / (float)v61));
        v15 = (float)((float)v56 * (float)(v161 / (float)v61));
        this->current.spatialVelocity.p[1] = this->current.spatialVelocity.p[1]
                                           + (float)((float)inverseMass
                                                   * (float)((float)v57 * (float)(v161 / (float)v61)));
        p_spatialVelocity->p[0] = (float)((float)((float)v55 * (float)(v161 / (float)v61)) * (float)inverseMass)
                                + (float)v63;
        this->current.spatialVelocity.p[2] = (float)v64
                                           + (float)((float)inverseMass
                                                   * (float)((float)v56 * (float)(v161 / (float)v61)));
        v65 = this->current.spatialVelocity.p[4];
        v66 = this->current.spatialVelocity.p[5];
        *v50 = *v50
             + (float)((float)((float)((float)((float)v46 * (float)((float)v57 * (float)(v161 / (float)v61)))
                                     - (float)((float)((float)v55 * (float)(v161 / (float)v61)) * (float)v47))
                             * (float)x)
                     + (float)((float)((float)((float)((float)((float)v56 * (float)(v161 / (float)v61)) * (float)v47)
                                             - (float)((float)((float)v57 * (float)(v161 / (float)v61)) * (float)v48))
                                     * (float)v40)
                             + (float)((float)((float)((float)((float)v55 * (float)(v161 / (float)v61)) * (float)v48)
                                             - (float)((float)v46 * (float)((float)v56 * (float)(v161 / (float)v61))))
                                     * (float)v37)));
        this->current.spatialVelocity.p[5] = (float)((float)((float)((float)((float)v46
                                                                           * (float)((float)v57
                                                                                   * (float)(v161 / (float)v61)))
                                                                   - (float)((float)((float)v55
                                                                                   * (float)(v161 / (float)v61))
                                                                           * (float)v47))
                                                           * (float)z)
                                                   + (float)((float)((float)((float)((float)((float)v56
                                                                                           * (float)(v161 / (float)v61))
                                                                                   * (float)v47)
                                                                           - (float)((float)((float)v57
                                                                                           * (float)(v161 / (float)v61))
                                                                                   * (float)v48))
                                                                   * (float)v38)
                                                           + (float)((float)((float)((float)((float)v55
                                                                                           * (float)(v161 / (float)v61))
                                                                                   * (float)v48)
                                                                           - (float)((float)v46
                                                                                   * (float)((float)v56
                                                                                           * (float)(v161 / (float)v61))))
                                                                   * (float)v35)))
                                           + (float)v66;
        this->current.spatialVelocity.p[4] = (float)v65
                                           + (float)((float)((float)((float)((float)v46
                                                                           * (float)((float)v57
                                                                                   * (float)(v161 / (float)v61)))
                                                                   - (float)((float)((float)v55
                                                                                   * (float)(v161 / (float)v61))
                                                                           * (float)v47))
                                                           * (float)y)
                                                   + (float)((float)((float)((float)((float)((float)v56
                                                                                           * (float)(v161 / (float)v61))
                                                                                   * (float)v47)
                                                                           - (float)((float)((float)v57
                                                                                           * (float)(v161 / (float)v61))
                                                                                   * (float)v48))
                                                                   * (float)v39)
                                                           + (float)((float)((float)((float)((float)v55
                                                                                           * (float)(v161 / (float)v61))
                                                                                   * (float)v48)
                                                                           - (float)((float)v46
                                                                                   * (float)((float)v56
                                                                                           * (float)(v161 / (float)v61))))
                                                                   * (float)v36)));
        if ( v6->fraction < 0.000099999997 )
        {
          v67 = v171.velocity.x;
          v68 = (float)(p_spatialVelocity->p[0] - v171.velocity.x);
          v69 = v171.velocity.y;
          v70 = v171.velocity.z;
          v71 = (float)(this->current.spatialVelocity.p[1] - v171.velocity.y);
          v72 = (float)(this->current.spatialVelocity.p[2] - v171.velocity.z);
          p_spatialVelocity->p[0] = p_spatialVelocity->p[0] - v171.velocity.x;
          this->current.spatialVelocity.p[1] = v71;
          this->current.spatialVelocity.p[2] = v72;
          v73 = this->current.spatialVelocity.p[4];
          v74 = this->current.spatialVelocity.p[3];
          this->current.spatialVelocity.p[1] = (float)v71 * (float)v29;
          this->current.spatialVelocity.p[2] = (float)v72 * (float)v29;
          p_spatialVelocity->p[0] = (float)v68 * (float)v29;
          this->current.spatialVelocity.p[5] = this->current.spatialVelocity.p[5] * (float)v29;
          this->current.spatialVelocity.p[3] = (float)v74 * (float)v29;
          this->current.spatialVelocity.p[4] = (float)v73 * (float)v29;
          p_spatialVelocity->p[0] = (float)v67 + (float)((float)v68 * (float)v29);
          this->current.spatialVelocity.p[1] = (float)((float)v71 * (float)v29) + (float)v69;
          this->current.spatialVelocity.p[2] = (float)((float)v72 * (float)v29) + (float)v70;
        }
      }
    }
    else
    {
      v75 = ((double (__fastcall *)(idPhysics_RigidBody *, _DWORD))this->GetWaterViscosity)(a1: this, a2: 0);
      waterLevel = this->waterLevel;
      v77 = (float)((float)v75 * (float)(this->linearFrictionWater * this->waterLevel));
      this->GetWaterViscosity(this, a2: 0);
      v79 = (float)((float)(this->linearFriction * (float)((float)1.0 - (float)waterLevel)) + (float)v77);
      if ( v79 >= 0.0 )
      {
        if ( v79 > 1.0 )
          v79 = 1.0;
      }
      else
      {
        v79 = 0.0;
      }
      v80 = (float)((float)(this->angularFriction * (float)((float)1.0 - (float)waterLevel))
                  + (float)((float)v78 * (float)(this->angularFrictionWater * (float)waterLevel)));
      if ( v80 >= 0.0 )
      {
        if ( v80 > 1.0 )
          v80 = 1.0;
      }
      else
      {
        v80 = 0.0;
      }
      p_spatialVelocity = &this->current.spatialVelocity;
      v81 = this->current.spatialVelocity.p[1];
      v82 = this->current.spatialVelocity.p[2];
      v50 = &this->current.spatialVelocity.p[3];
      v83 = (float)(this->lastTimeStep
                  * (float)(this->gravityVector.y
                          + (float)((float)(this->current.externalForce.p[1] * this->inverseMass)
                                  - (float)(this->current.spatialVelocity.p[1] * (float)v79))));
      v84 = (float)(this->lastTimeStep
                  * (float)(this->gravityVector.z
                          + (float)((float)(this->current.externalForce.p[2] * this->inverseMass)
                                  - (float)(this->current.spatialVelocity.p[2] * (float)v79))));
      this->current.spatialVelocity.p[0] = (float)((float)((float)((float)(this->inverseMass
                                                                         * this->current.externalForce.p[0])
                                                                 - (float)(this->current.spatialVelocity.p[0]
                                                                         * (float)v79))
                                                         + this->gravityVector.x)
                                                 * this->lastTimeStep)
                                         + this->current.spatialVelocity.p[0];
      this->current.spatialVelocity.p[1] = (float)v81 + (float)v83;
      this->current.spatialVelocity.p[2] = (float)v82 + (float)v84;
      v85 = this->current.spatialVelocity.p[4];
      v86 = this->current.spatialVelocity.p[5];
      v87 = (float)(this->lastTimeStep
                  * (float)((float)((float)(this->current.externalForce.p[4] * (float)v36)
                                  + (float)((float)(this->current.externalForce.p[3] * (float)v39)
                                          + (float)(this->current.externalForce.p[5] * (float)y)))
                          - (float)(this->current.spatialVelocity.p[4] * (float)v80)));
      v88 = (float)(this->lastTimeStep
                  * (float)((float)((float)(this->current.externalForce.p[4] * (float)v35)
                                  + (float)((float)(this->current.externalForce.p[3] * (float)v38)
                                          + (float)(this->current.externalForce.p[5] * (float)z)))
                          - (float)((float)v80 * this->current.spatialVelocity.p[5])));
      this->current.spatialVelocity.p[3] = (float)((float)((float)((float)(this->current.externalForce.p[3] * (float)v40)
                                                                 + (float)((float)(this->current.externalForce.p[5]
                                                                                 * (float)x)
                                                                         + (float)(this->current.externalForce.p[4]
                                                                                 * (float)v37)))
                                                         - (float)(this->current.spatialVelocity.p[3] * (float)v80))
                                                 * this->lastTimeStep)
                                         + this->current.spatialVelocity.p[3];
      this->current.spatialVelocity.p[4] = (float)v85 + (float)v87;
      this->current.spatialVelocity.p[5] = (float)v88 + (float)v86;
    }
    if ( (unsigned __int8)idPhysics_RigidBody::TestIfAtRest(this) != 0 )
    {
      this->callbacks->DeactivatePhysics(this: this->callbacks, a2: this->physicsId);
      return;
    }
    this->ActivateContactPhysics(this);
    if ( v17 != nullptr && !v17->IsAtRest(this: v17) )
    {
      v89 = v17->callbacks;
      if ( v89 == nullptr )
        return;
      v172[1] = -v14;
      v172[2] = -v15;
      v172[0] = -v13;
      v89->ApplyImpulse(this: v89, a2: this->physicsId, a3: v6->c.bodyId, a4: &v6->c.point, a5: (const idVec3 *)v172);
    }
    v90 = 0;
    if ( this->contacts.num > 0 )
    {
      v91 = 0;
      do
      {
        if ( this->callbacks->Contact(this: this->callbacks, a2: this->physicsId, a3: &this->contacts.list[v91]) != COLLIDE_IGNORE_COLLISION )
        {
          v92 = &this->contacts.list[v91];
          v93 = (float)(v92->point.y - v167);
          v94 = (float)(v92->point.x - v166);
          v95 = (float)(v92->point.z - v168);
          v96 = (float)((float)((float)(v50[1] * (float)(v92->point.z - v168))
                              - (float)(v50[2] * (float)(v92->point.y - v167)))
                      + p_spatialVelocity->p[0]);
          v97 = (float)(p_spatialVelocity->p[2]
                      + (float)((float)(*v50 * (float)(v92->point.y - v167))
                              - (float)((float)(v92->point.x - v166) * v50[1])));
          v98 = (float)(p_spatialVelocity->p[1]
                      + (float)((float)((float)(v92->point.x - v166) * v50[2])
                              - (float)(*v50 * (float)(v92->point.z - v168))));
          v99 = (idPhysics_RigidBody *)idPhysics::GetPhysicsForId(physicsId_: v92->physicsId);
          if ( v99 != nullptr && v99 != this )
          {
            v99->GetImpactInfo(
              this: v99,
              a2: this->contacts.list[v91].bodyId,
              a3: &this->contacts.list[v91].point,
              a4: &v171);
            v96 = (float)((float)v96 - v171.velocity.x);
            v98 = (float)((float)v98 - v171.velocity.y);
            v97 = (float)((float)v97 - v171.velocity.z);
          }
          v100 = &this->contacts.list[v91];
          v101 = (float)(v100->normal.z
                       * (float)((float)((float)v96 * v100->normal.x)
                               + (float)((float)(v100->normal.z * (float)v97) + (float)(v100->normal.y * (float)v98))));
          v102 = (float)((float)((float)((float)v96 * v100->normal.x)
                               + (float)((float)(v100->normal.z * (float)v97) + (float)(v100->normal.y * (float)v98)))
                       * v100->normal.x);
          v103 = (float)(v100->normal.y
                       * (float)((float)((float)v96 * v100->normal.x)
                               + (float)((float)(v100->normal.z * (float)v97) + (float)(v100->normal.y * (float)v98))));
          v104 = -(float)((float)v97
                        - (float)(v100->normal.z
                                * (float)((float)((float)v96 * v100->normal.x)
                                        + (float)((float)(v100->normal.z * (float)v97)
                                                + (float)(v100->normal.y * (float)v98)))));
          v105 = -(float)((float)v96
                        - (float)((float)((float)((float)v96 * v100->normal.x)
                                        + (float)((float)(v100->normal.z * (float)v97)
                                                + (float)(v100->normal.y * (float)v98)))
                                * v100->normal.x));
          v106 = -(float)((float)v98
                        - (float)(v100->normal.y
                                * (float)((float)((float)v96 * v100->normal.x)
                                        + (float)((float)(v100->normal.z * (float)v97)
                                                + (float)(v100->normal.y * (float)v98)))));
          v107 = (float)((float)((float)v106 * (float)v106)
                       + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104)));
          _FP5 = (float)((float)((float)((float)v106 * (float)v106)
                               + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f11, f5, f6, f11 }
          v110 = __frsqrte(_FP11);
          v111 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v110
                                                                                               * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)v29))
                                                                                       * (float)v110)
                                                                               - (float)1.5)
                                                               * (float)v110)
                                                       * (float)((float)((float)((float)v106 * (float)v106)
                                                                       + (float)((float)((float)v105 * (float)v105)
                                                                               + (float)((float)v104 * (float)v104)))
                                                               * (float)v29))
                                               * (float)((float)-(float)((float)((float)((float)v110
                                                                                       * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104)))
                                                                                               * (float)v29))
                                                                               * (float)v110)
                                                                       - (float)1.5)
                                                       * (float)v110))
                                       - (float)1.5)
                       * (float)((float)-(float)((float)((float)((float)v110
                                                               * (float)((float)((float)((float)v106 * (float)v106)
                                                                               + (float)((float)((float)v105
                                                                                               * (float)v105)
                                                                                       + (float)((float)v104
                                                                                               * (float)v104)))
                                                                       * (float)v29))
                                                       * (float)v110)
                                               - (float)1.5)
                               * (float)v110));
          v112 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v110 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)v29)) * (float)v110) - (float)1.5) * (float)v110)
                                                                                               * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)v29))
                                                                                       * (float)((float)-(float)((float)((float)((float)v110 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)v29)) * (float)v110) - (float)1.5)
                                                                                               * (float)v110))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v110 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)v29))
                                                                                               * (float)v110)
                                                                                       - (float)1.5)
                                                                       * (float)v110))
                                                       * (float)((float)((float)((float)v106 * (float)v106)
                                                                       + (float)((float)((float)v105 * (float)v105)
                                                                               + (float)((float)v104 * (float)v104)))
                                                               * (float)v29))
                                               * (float)v111)
                                       - (float)1.5)
                       * (float)v111);
          v113 = (float)((float)v112 * (float)v104);
          v114 = (float)((float)v105 * (float)v112);
          v115 = (float)((float)v112 * (float)v106);
          v116 = (float)((float)((float)v94
                               * (float)((float)((float)((float)((float)v113 * (float)v93)
                                                       - (float)((float)v115 * (float)v95))
                                               * (float)v38)
                                       + (float)((float)((float)((float)((float)v94 * (float)v115)
                                                               - (float)((float)v114 * (float)v93))
                                                       * (float)z)
                                               + (float)((float)((float)((float)v114 * (float)v95)
                                                               - (float)((float)v94 * (float)v113))
                                                       * (float)v35))))
                       - (float)((float)((float)((float)((float)((float)v114 * (float)v95)
                                                       - (float)((float)v94 * (float)v113))
                                               * (float)v37)
                                       + (float)((float)((float)v40
                                                       * (float)((float)((float)v113 * (float)v93)
                                                               - (float)((float)v115 * (float)v95)))
                                               + (float)((float)((float)((float)v94 * (float)v115)
                                                               - (float)((float)v114 * (float)v93))
                                                       * (float)x)))
                               * (float)v95));
          v117 = (float)((float)((float)((float)((float)((float)((float)v113 * (float)v93)
                                                       - (float)((float)v115 * (float)v95))
                                               * (float)v39)
                                       + (float)((float)((float)((float)((float)v94 * (float)v115)
                                                               - (float)((float)v114 * (float)v93))
                                                       * (float)y)
                                               + (float)((float)((float)((float)v114 * (float)v95)
                                                               - (float)((float)v94 * (float)v113))
                                                       * (float)v36)))
                               * (float)v95)
                       - (float)((float)((float)((float)((float)((float)v113 * (float)v93)
                                                       - (float)((float)v115 * (float)v95))
                                               * (float)v38)
                                       + (float)((float)((float)((float)((float)v94 * (float)v115)
                                                               - (float)((float)v114 * (float)v93))
                                                       * (float)z)
                                               + (float)((float)((float)((float)v114 * (float)v95)
                                                               - (float)((float)v94 * (float)v113))
                                                       * (float)v35)))
                               * (float)v93));
          v118 = (float)((float)((float)((float)v112 * (float)v107) * this->contactFriction)
                       / (float)((float)((float)((float)v116 * (float)v115)
                                       + (float)((float)((float)v117 * (float)v114)
                                               + (float)((float)((float)((float)((float)((float)((float)((float)v114 * (float)v95)
                                                                                               - (float)((float)v94 * (float)v113))
                                                                                       * (float)v37)
                                                                               + (float)((float)((float)v40
                                                                                               * (float)((float)((float)v113 * (float)v93) - (float)((float)v115 * (float)v95)))
                                                                                       + (float)((float)((float)((float)v94 * (float)v115) - (float)((float)v114 * (float)v93))
                                                                                               * (float)x)))
                                                                       * (float)v93)
                                                               - (float)((float)v94
                                                                       * (float)((float)((float)((float)((float)v113 * (float)v93)
                                                                                               - (float)((float)v115 * (float)v95))
                                                                                       * (float)v39)
                                                                               + (float)((float)((float)((float)((float)v94 * (float)v115) - (float)((float)v114 * (float)v93))
                                                                                               * (float)y)
                                                                                       + (float)((float)((float)((float)v114 * (float)v95) - (float)((float)v94 * (float)v113))
                                                                                               * (float)v36)))))
                                                       * (float)v113)))
                               + this->inverseMass));
          v119 = p_spatialVelocity->p[1];
          v120 = (float)((float)v118 * (float)v114);
          v121 = (float)((float)v118 * (float)v115);
          v122 = (float)((float)v118 * (float)v113);
          v123 = (float)((float)((float)v118 * (float)v114) * this->inverseMass);
          v125 = (float)((float)v94 * (float)((float)v118 * (float)v113));
          v124 = (float)(this->inverseMass * (float)((float)v118 * (float)v115));
          v126 = (float)((float)v120 * (float)v93);
          v127 = (float)(this->inverseMass * (float)v122);
          v128 = (float)((float)((float)v120 * (float)v95) - (float)v125);
          v129 = p_spatialVelocity->p[2];
          p_spatialVelocity->p[0] = (float)v123 + p_spatialVelocity->p[0];
          p_spatialVelocity->p[1] = (float)v119 + (float)v124;
          p_spatialVelocity->p[2] = (float)v129 + (float)v127;
          v130 = (float)((float)((float)v122 * (float)v93) - (float)((float)v121 * (float)v95));
          v132 = (float)((float)((float)v40
                               * (float)((float)((float)v122 * (float)v93) - (float)((float)v121 * (float)v95)))
                       + (float)((float)((float)((float)v94 * (float)v121) - (float)v126) * (float)x));
          v131 = (float)((float)((float)((float)((float)v94 * (float)v121) - (float)v126) * (float)y)
                       + (float)((float)v128 * (float)v36));
          v133 = *v50;
          v135 = (float)((float)((float)((float)((float)v122 * (float)v93) - (float)((float)v121 * (float)v95))
                               * (float)v38)
                       + (float)((float)((float)((float)((float)v94 * (float)v121) - (float)v126) * (float)z)
                               + (float)((float)v128 * (float)v35)));
          v134 = v50[1];
          v50[2] = (float)v135 + v50[2];
          v50[1] = (float)v134 + (float)((float)((float)v130 * (float)v39) + (float)v131);
          *v50 = (float)((float)((float)v128 * (float)v37) + (float)v132) + (float)v133;
          if ( (float)((float)((float)v102 * this->contacts.list[v91].normal.x)
                     + (float)((float)(this->contacts.list[v91].normal.z * (float)v101)
                             + (float)(this->contacts.list[v91].normal.y * (float)v103))) < v8 )
          {
            v136 = -v101;
            v137 = -v102;
            v138 = -v103;
            v139 = p_spatialVelocity->p[1];
            v140 = p_spatialVelocity->p[2];
            v141 = (float)((float)((float)v138 * (float)v138)
                         + (float)((float)((float)v137 * (float)v137) + (float)((float)v136 * (float)v136)));
            _FP1 = (float)((float)((float)((float)v138 * (float)v138)
                                 + (float)((float)((float)v137 * (float)v137) + (float)((float)v136 * (float)v136)))
                         - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f12, f1, f2, f0 }
            v144 = __frsqrte(_FP12);
            v145 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v144
                                                                                                 * (float)((float)((float)((float)v138 * (float)v138) + (float)((float)((float)v137 * (float)v137) + (float)((float)v136 * (float)v136))) * (float)v29))
                                                                                         * (float)v144)
                                                                                 - (float)1.5)
                                                                 * (float)v144)
                                                         * (float)((float)((float)((float)v138 * (float)v138)
                                                                         + (float)((float)((float)v137 * (float)v137)
                                                                                 + (float)((float)v136 * (float)v136)))
                                                                 * (float)v29))
                                                 * (float)((float)-(float)((float)((float)((float)v144
                                                                                         * (float)((float)((float)((float)v138 * (float)v138) + (float)((float)((float)v137 * (float)v137) + (float)((float)v136 * (float)v136)))
                                                                                                 * (float)v29))
                                                                                 * (float)v144)
                                                                         - (float)1.5)
                                                         * (float)v144))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v144
                                                                 * (float)((float)((float)((float)v138 * (float)v138)
                                                                                 + (float)((float)((float)v137
                                                                                                 * (float)v137)
                                                                                         + (float)((float)v136
                                                                                                 * (float)v136)))
                                                                         * (float)v29))
                                                         * (float)v144)
                                                 - (float)1.5)
                                 * (float)v144));
            v146 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v144 * (float)((float)((float)((float)v138 * (float)v138) + (float)((float)((float)v137 * (float)v137) + (float)((float)v136 * (float)v136))) * (float)v29)) * (float)v144) - (float)1.5) * (float)v144)
                                                                                                 * (float)((float)((float)((float)v138 * (float)v138) + (float)((float)((float)v137 * (float)v137) + (float)((float)v136 * (float)v136))) * (float)v29))
                                                                                         * (float)((float)-(float)((float)((float)((float)v144 * (float)((float)((float)((float)v138 * (float)v138) + (float)((float)((float)v137 * (float)v137) + (float)((float)v136 * (float)v136))) * (float)v29)) * (float)v144) - (float)1.5)
                                                                                                 * (float)v144))
                                                                                 - (float)1.5)
                                                                 * (float)((float)-(float)((float)((float)((float)v144 * (float)((float)((float)((float)v138 * (float)v138) + (float)((float)((float)v137 * (float)v137) + (float)((float)v136 * (float)v136))) * (float)v29))
                                                                                                 * (float)v144)
                                                                                         - (float)1.5)
                                                                         * (float)v144))
                                                         * (float)((float)((float)((float)v138 * (float)v138)
                                                                         + (float)((float)((float)v137 * (float)v137)
                                                                                 + (float)((float)v136 * (float)v136)))
                                                                 * (float)v29))
                                                 * (float)v145)
                                         - (float)1.5)
                         * (float)v145);
            v147 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v144 * (float)((float)((float)((float)v138 * (float)v138) + (float)((float)((float)v137 * (float)v137) + (float)((float)v136 * (float)v136))) * (float)v29)) * (float)v144) - (float)1.5) * (float)v144) * (float)((float)((float)((float)v138 * (float)v138) + (float)((float)((float)v137 * (float)v137) + (float)((float)v136 * (float)v136))) * (float)v29))
                                                                                                 * (float)((float)-(float)((float)((float)((float)v144 * (float)((float)((float)((float)v138 * (float)v138) + (float)((float)((float)v137 * (float)v137) + (float)((float)v136 * (float)v136))) * (float)v29)) * (float)v144) - (float)1.5) * (float)v144))
                                                                                         - (float)1.5)
                                                                         * (float)((float)-(float)((float)((float)((float)v144 * (float)((float)((float)((float)v138 * (float)v138) + (float)((float)((float)v137 * (float)v137) + (float)((float)v136 * (float)v136))) * (float)v29)) * (float)v144)
                                                                                                 - (float)1.5)
                                                                                 * (float)v144))
                                                                 * (float)((float)((float)((float)v138 * (float)v138)
                                                                                 + (float)((float)((float)v137
                                                                                                 * (float)v137)
                                                                                         + (float)((float)v136
                                                                                                 * (float)v136)))
                                                                         * (float)v29))
                                                         * (float)v145)
                                                 - (float)1.5)
                                 * (float)v145)
                         * (float)v136);
            v148 = (float)((float)-v102 * (float)v146);
            v149 = (float)((float)v146 * (float)v141);
            v150 = (float)((float)v146 * (float)v138);
            v151 = (float)((float)((float)((float)-v102 * (float)v146) * (float)v95) - (float)((float)v94 * (float)v147));
            v152 = (float)((float)((float)v94 * (float)v150) - (float)((float)((float)-v102 * (float)v146) * (float)v93));
            v154 = (float)((float)((float)v151 * (float)v37)
                         + (float)((float)((float)v40
                                         * (float)((float)((float)v147 * (float)v93) - (float)((float)v150 * (float)v95)))
                                 + (float)((float)v152 * (float)x)));
            v155 = (float)((float)((float)((float)((float)v147 * (float)v93) - (float)((float)v150 * (float)v95))
                                 * (float)v38)
                         + (float)((float)((float)v152 * (float)z) + (float)((float)v151 * (float)v35)));
            v153 = (float)((float)((float)((float)((float)v147 * (float)v93) - (float)((float)v150 * (float)v95))
                                 * (float)v39)
                         + (float)((float)((float)v152 * (float)y) + (float)((float)v151 * (float)v36)));
            v156 = (float)((float)v149
                         / (float)((float)((float)((float)((float)((float)v94 * (float)v155)
                                                         - (float)((float)v154 * (float)v95))
                                                 * (float)v150)
                                         + (float)((float)((float)((float)((float)v153 * (float)v95)
                                                                 - (float)((float)v155 * (float)v93))
                                                         * (float)v148)
                                                 + (float)((float)((float)((float)v154 * (float)v93)
                                                                 - (float)((float)v94 * (float)v153))
                                                         * (float)v147)))
                                 + this->inverseMass));
            v157 = (float)(this->inverseMass * (float)((float)v156 * (float)v150));
            v158 = (float)(this->inverseMass * (float)((float)v156 * (float)v147));
            p_spatialVelocity->p[0] = p_spatialVelocity->p[0]
                                    + (float)((float)((float)v156 * (float)v148) * this->inverseMass);
            p_spatialVelocity->p[1] = (float)v139 + (float)v157;
            p_spatialVelocity->p[2] = (float)v140 + (float)v158;
            v159 = v50[1];
            v160 = v50[2];
            *v50 = *v50
                 + (float)((float)((float)((float)((float)v94 * (float)((float)v156 * (float)v150))
                                         - (float)((float)((float)v156 * (float)v148) * (float)v93))
                                 * (float)x)
                         + (float)((float)((float)v40
                                         * (float)((float)((float)((float)v156 * (float)v147) * (float)v93)
                                                 - (float)((float)((float)v156 * (float)v150) * (float)v95)))
                                 + (float)((float)((float)((float)((float)v156 * (float)v148) * (float)v95)
                                                 - (float)((float)v94 * (float)((float)v156 * (float)v147)))
                                         * (float)v37)));
            v50[1] = (float)v159
                   + (float)((float)((float)v39
                                   * (float)((float)((float)((float)v156 * (float)v147) * (float)v93)
                                           - (float)((float)((float)v156 * (float)v150) * (float)v95)))
                           + (float)((float)((float)((float)((float)((float)v156 * (float)v148) * (float)v95)
                                                   - (float)((float)v94 * (float)((float)v156 * (float)v147)))
                                           * (float)v36)
                                   + (float)((float)((float)((float)v94 * (float)((float)v156 * (float)v150))
                                                   - (float)((float)((float)v156 * (float)v148) * (float)v93))
                                           * (float)y)));
            v50[2] = (float)((float)((float)v38
                                   * (float)((float)((float)((float)v156 * (float)v147) * (float)v93)
                                           - (float)((float)((float)v156 * (float)v150) * (float)v95)))
                           + (float)((float)((float)((float)((float)((float)v156 * (float)v148) * (float)v95)
                                                   - (float)((float)v94 * (float)((float)v156 * (float)v147)))
                                           * (float)v35)
                                   + (float)((float)((float)((float)v94 * (float)((float)v156 * (float)v150))
                                                   - (float)((float)((float)v156 * (float)v148) * (float)v93))
                                           * (float)z)))
                   + (float)v160;
          }
        }
        ++v90;
        ++v91;
      }
      while ( v90 < this->contacts.num );
    }
    idPhysics_RigidBody::CapVelocity(this);
  }
}


// ========================================================================
// ?Evaluate@idPhysics_RigidBody@@UAA_NHH@Z
// EA  : 0x8275EEC8
// RVA : 0x0075EEC8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

int __fastcall idPhysics_RigidBody::Evaluate(idPhysics_RigidBody *this, unsigned int timeStepMSec, int endTimeMSec)
{
  idClipModel *clipModel; // r11
  int v5; // r10
  double v6; // fp30
  float y; // r7
  float *p_y; // r10
  float z; // r6
  idClipModel *p_z; // r11
  int v11; // ctr
  int v12; // r8
  double v13; // fp5
  double v14; // fp3
  idMat3 *p_localAxis; // r3
  char *v16; // r10
  _DWORD *v17; // r11
  int i; // ctr
  double x; // fp31
  double v20; // fp29
  double v21; // fp28
  double v22; // fp30
  double v23; // fp11
  double v24; // fp10
  idMat3 *v25; // r3
  idVec3 *v26; // r3
  double v27; // fp4
  double v28; // fp3
  bool v29; // mr_fpscr50
  char v30; // r11
  char v31; // r3
  unsigned __int8 v32; // r11
  idGame *v34; // r3
  trace_t *v35; // r4
  trace_t *v36; // r4
  idPhysicsCallbacks *callbacks; // r30
  const char *v38; // r29
  const char *v39; // r3
  idVec3 v40; // [sp+50h] [-580h] BYREF
  idMat3 v41; // [sp+60h] [-570h] BYREF
  float v42; // [sp+84h] [-54Ch]
  float v43; // [sp+88h] [-548h]
  float v44; // [sp+8Ch] [-544h]
  float v45; // [sp+90h] [-540h]
  float v46; // [sp+94h] [-53Ch]
  float v47; // [sp+98h] [-538h]
  float v48; // [sp+9Ch] [-534h]
  float v49; // [sp+A0h] [-530h]
  idMat3 v50; // [sp+B0h] [-520h] BYREF
  idMat3 v51; // [sp+E0h] [-4F0h] BYREF
  char v52; // [sp+10Ch] [-4C4h] BYREF
  idMat3 v53; // [sp+110h] [-4C0h] BYREF
  idMat3 v54; // [sp+140h] [-490h] BYREF
  trace_t v55; // [sp+170h] [-460h] BYREF
  contactsResult_t v56; // [sp+1F0h] [-3E0h] BYREF

  clipModel = this->clipModel;
  if ( clipModel == nullptr )
    return 0;
  v5 = *((unsigned __int8 *)&this->fl + 4);
  *(_QWORD *)&v40.x = __PAIR64__(&unk_82390000, timeStepMSec);
  v6 = (float)((float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001);
  if ( (v5 & 0x10) != 0 )
  {
    y = clipModel->origin.y;
    p_y = &v41.mat[2].y;
    z = clipModel->origin.z;
    v41.mat[0].x = clipModel->origin.x;
    p_z = (idClipModel *)&clipModel->origin.z;
    v11 = 9;
    v41.mat[0].y = y;
    v41.mat[0].z = z;
    do
    {
      p_z = (idClipModel *)((char *)p_z + 4);
      *++p_y = *(float *)&p_z->__vftable;
      --v11;
    }
    while ( v11 != 0 );
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v41.mat[1].y, a3: &v50);
    v12 = *((_BYTE *)&this->fl + 4) & 8;
    v13 = (float)((float)(this->current.localOrigin.y * v50.mat[1].z)
                + (float)((float)(this->current.localOrigin.x * v50.mat[0].z)
                        + (float)(this->current.localOrigin.z * v50.mat[2].z)));
    v14 = (float)(v41.mat[1].z
                + (float)((float)(this->current.localOrigin.y * v50.mat[1].y)
                        + (float)((float)(this->current.localOrigin.x * v50.mat[0].y)
                                + (float)(this->current.localOrigin.z * v50.mat[2].y))));
    v40.x = (float)((float)(this->current.localOrigin.y * v50.mat[1].x)
                  + (float)((float)(this->current.localOrigin.x * v50.mat[0].x)
                          + (float)(this->current.localOrigin.z * v50.mat[2].x)))
          + v41.mat[1].y;
    v40.y = v14;
    v40.z = v41.mat[2].x + (float)v13;
    if ( v12 != 0 )
      p_localAxis = idMat3::operator*(this: &v51, result: &this->current.localAxis, a: &v50);
    else
      p_localAxis = &this->current.localAxis;
    v16 = &v52;
    v17 = (_DWORD *)&p_localAxis[-1].mat[2].z;
    for ( i = 9; i != 0; --i )
    {
      ++v17;
      v16 += 4;
      *(_DWORD *)v16 = *v17;
    }
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: this->clipModel->bodyId,
      newOrigin: &v40,
      newAxis: &v53);
    x = v41.mat[0].x;
    v20 = v41.mat[0].y;
    v21 = v41.mat[0].z;
    v22 = (float)((float)1.0 / (float)v6);
    v51.mat[0].x = v41.mat[2].z;
    v51.mat[0].y = v44;
    v51.mat[0].z = v47;
    v51.mat[1].x = v42;
    v23 = (float)((float)(v40.y - v41.mat[0].y) * (float)v22);
    v24 = (float)((float)(v40.z - v41.mat[0].z) * (float)v22);
    v51.mat[1].y = v45;
    v51.mat[1].z = v48;
    v51.mat[2].x = v43;
    v51.mat[2].y = v46;
    v51.mat[2].z = v49;
    this->current.spatialVelocity.p[0] = (float)(v40.x - v41.mat[0].x) * (float)v22;
    this->current.spatialVelocity.p[1] = v23;
    this->current.spatialVelocity.p[2] = v24;
    v25 = idMat3::operator*(this: &v54, result: &v53, a: &v51);
    v26 = idMat3::ToAngularVelocity(this: &v41, result: v25->mat);
    v27 = (float)(v26->y * (float)v22);
    v28 = (float)(v26->z * (float)v22);
    v29 = v40.x == x;
    this->current.spatialVelocity.p[3] = v26->x * (float)v22;
    this->current.spatialVelocity.p[4] = v27;
    this->current.spatialVelocity.p[5] = v28;
    this->current.externalForce.p[5] = 0.0;
    this->current.externalForce.p[4] = 0.0;
    this->current.externalForce.p[3] = 0.0;
    this->current.externalForce.p[2] = 0.0;
    this->current.externalForce.p[1] = 0.0;
    this->current.externalForce.p[0] = 0.0;
    if ( !v29 || v40.y != v20 || (v30 = 1, v40.z != v21) )
      v30 = 0;
    if ( v30 == 0 )
      return 1;
    v31 = idMat3::Compare(this: &v53, a: (idMat3 *)&v41.mat[2].z);
    v32 = 0;
    if ( v31 == 0 )
      return 1;
    return v32;
  }
  if ( this->current.atRest >= 0 || v6 <= 0.0 )
  {
    idPhysics_RigidBody::DebugDraw(this);
    return 0;
  }
  if ( (v5 & 0xFFFFFF80) != 0 )
  {
    idPhysics_RigidBody::DropToFloorAndRest(this);
    return 1;
  }
  else
  {
    v34 = common->Game(this: common);
    if ( v34->ForceNonDeferred(this: v34) )
    {
      idPhysics_RigidBody::ResolveCollisions(this, collisionOverride: nullptr, contactOverride: nullptr);
      idPhysics_RigidBody::Evolve(this, timeStep: v6, collisionOverride: v35, contactOverride: &v55, a5: &v56);
      idPhysics_RigidBody::ResolveCollisions(this, collisionOverride: &v55, contactOverride: &v56);
    }
    else
    {
      idPhysics_RigidBody::ResolveCollisions(this, collisionOverride: nullptr, contactOverride: nullptr);
      idPhysics_RigidBody::Evolve(this, timeStep: v6, collisionOverride: v36, contactOverride: nullptr, a5: nullptr);
    }
    this->current.externalForce.p[5] = 0.0;
    this->current.externalForce.p[4] = 0.0;
    this->current.externalForce.p[3] = 0.0;
    this->current.externalForce.p[2] = 0.0;
    this->current.externalForce.p[1] = 0.0;
    this->current.externalForce.p[0] = 0.0;
    if ( this->IsOutsideWorld(this) )
    {
      callbacks = this->callbacks;
      v38 = idVec3::ToString(this: (idAngles *)&this->clipModel->origin, precision: 0);
      v39 = (const char *)callbacks->GetName(this: callbacks);
      idLib::Warning(fmt: "rigid body moved outside world bounds for entity '%s' at (%s)", v39, v38);
      this->callbacks->DeactivatePhysics(this: this->callbacks, a2: this->physicsId);
    }
    idPhysics_RigidBody::DebugDraw(this);
    return 1;
  }
}


// ========================================================================
// ?Translate@idPhysics_RigidBody@@UAAXABVidVec3@@H@Z
// EA  : 0x8275F330
// RVA : 0x0075F330
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::Translate(idPhysics_RigidBody *this, const idVec3 *translation, int id)
{
  idClipModel *clipModel; // r3
  int physicsId; // r5
  int entityNumber; // r4
  double v8; // fp9
  double v9; // fp7
  idClipModel *v10; // r11
  double v11; // fp10
  double v12; // fp11
  double v13; // fp7
  double v14; // fp3
  double v15; // fp2
  idVec3 v16; // [sp+50h] [-60h] BYREF
  float v17; // [sp+60h] [-50h] BYREF
  float v18; // [sp+64h] [-4Ch]
  float v19; // [sp+68h] [-48h]
  float v20[10]; // [sp+70h] [-40h] BYREF

  if ( this->clipModel != nullptr )
  {
    idPhysics_RigidBody::ResolveCollisions(this, collisionOverride: nullptr, contactOverride: nullptr);
    clipModel = this->clipModel;
    physicsId = this->physicsId;
    entityNumber = this->entityNumber;
    v8 = (float)(clipModel->origin.z + translation->z);
    v9 = (float)(clipModel->origin.y + translation->y);
    v16.x = clipModel->origin.x + translation->x;
    v16.z = v8;
    v16.y = v9;
    idClipModel::Link(
      this: clipModel,
      newEntityNumber: entityNumber,
      newPhysicsId: physicsId,
      newBodyId: clipModel->bodyId,
      newOrigin: &v16,
      newAxis: &clipModel->axis);
    this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
    if ( (*((_BYTE *)&this->fl + 4) & 0x10) != 0 )
    {
      this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v17, a3: (idMat3 *)v20);
      v10 = this->clipModel;
      v11 = (float)(v10->origin.x - v17);
      v12 = v20[0];
      v13 = v20[3];
      v14 = (float)((float)(v20[1] * (float)(v10->origin.y - v18)) + (float)(v20[2] * (float)(v10->origin.z - v19)));
      v15 = (float)((float)(v20[4] * (float)(v10->origin.y - v18)) + (float)(v20[5] * (float)(v10->origin.z - v19)));
      this->current.localOrigin.z = (float)(v20[8] * (float)(v10->origin.z - v19))
                                  + (float)((float)(v20[7] * (float)(v10->origin.y - v18))
                                          + (float)(v20[6] * (float)(v10->origin.x - v17)));
      this->current.localOrigin.x = (float)((float)v12 * (float)v11) + (float)v14;
      this->current.localOrigin.y = (float)((float)v13 * (float)v11) + (float)v15;
    }
  }
}


// ========================================================================
// ?Rotate@idPhysics_RigidBody@@UAAXABVidRotation@@H@Z
// EA  : 0x8275F488
// RVA : 0x0075F488
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __fastcall idPhysics_RigidBody::Rotate(idPhysics_RigidBody *this, idRotation *rotation, int id)
{
  idClipModel *clipModel; // r11
  idMat3 *p_axis; // r29
  int physicsId; // r28
  int entityNumber; // r27
  int bodyId; // r26
  const idMat3 *v10; // r3
  const idMat3 *v11; // r3
  const idMat3 *v12; // r3
  idClipModel *v13; // r11
  double v14; // fp2
  double z; // fp11
  double v16; // fp7
  double v17; // fp4
  double v18; // fp3
  float v19; // [sp+50h] [-B0h] BYREF
  float v20; // [sp+54h] [-ACh]
  float v21; // [sp+58h] [-A8h]
  idRotation v22[2]; // [sp+60h] [-A0h] BYREF

  if ( this->clipModel != nullptr )
  {
    idPhysics_RigidBody::ResolveCollisions(this, collisionOverride: nullptr, contactOverride: nullptr);
    clipModel = this->clipModel;
    p_axis = &clipModel->axis;
    idRotation::operator*(this: v22, result: rotation, v: &clipModel->origin);
    physicsId = this->physicsId;
    entityNumber = this->entityNumber;
    bodyId = this->clipModel->bodyId;
    v10 = idRotation::ToMat3(this: rotation);
    v11 = idMat3::operator*(this: (idMat3 *)&v22[0].axisValid, result: p_axis, a: v10);
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: entityNumber,
      newPhysicsId: physicsId,
      newBodyId: bodyId,
      newOrigin: &v22[0].origin,
      newAxis: v11);
    this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
    if ( (*((_BYTE *)&this->fl + 4) & 0x10) != 0 )
    {
      this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v19, a3: (idMat3 *)&v22[0].vec.y);
      v12 = idRotation::ToMat3(this: rotation);
      idMat3::operator*=(this: &this->current.localAxis, a: v12);
      v13 = this->clipModel;
      v14 = (float)(v13->origin.z - v21);
      z = v22[0].axis.mat[0].z;
      v16 = v22[0].axis.mat[1].z;
      v17 = (float)((float)(v22[0].axis.mat[0].y * (float)(v13->origin.y - v20))
                  + (float)(v22[0].axis.mat[0].x * (float)(v13->origin.x - v19)));
      v18 = (float)((float)(v22[0].axis.mat[1].x * (float)(v13->origin.x - v19))
                  + (float)(v22[0].axis.mat[1].y * (float)(v13->origin.y - v20)));
      this->current.localOrigin.x = (float)(v22[0].angle * (float)(v13->origin.z - v21))
                                  + (float)((float)(v22[0].vec.z * (float)(v13->origin.y - v20))
                                          + (float)(v22[0].vec.y * (float)(v13->origin.x - v19)));
      this->current.localOrigin.y = (float)((float)z * (float)v14) + (float)v17;
      this->current.localOrigin.z = (float)((float)v16 * (float)v14) + (float)v18;
    }
  }
}


// ========================================================================
// ?EvaluateContacts@idPhysics_RigidBody@@UAA_NXZ
// EA  : 0x8275F5F0
// RVA : 0x0075F5F0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

BOOL __fastcall idPhysics_RigidBody::EvaluateContacts(idPhysics_RigidBody *this)
{
  int v3; // r28
  idList<contactInfo_t,77> *p_contacts; // r31
  contactInfo_t *contacts; // r30
  int granularity; // r4
  int size; // r11
  bool v8; // cr58
  signed int v9; // r10
  int v10; // r4
  int v11; // r11
  int num; // r11
  int v13; // [sp+8h] [-448h]
  const char *v14; // [sp+Ch] [-444h]
  int v15; // [sp+10h] [-440h]
  int v16; // [sp+14h] [-43Ch]
  int v17; // [sp+18h] [-438h]
  int v18; // [sp+1Ch] [-434h]
  int v19; // [sp+20h] [-430h]
  int v20; // [sp+24h] [-42Ch]
  int v21; // [sp+28h] [-428h]
  int v22; // [sp+2Ch] [-424h]
  int v23; // [sp+30h] [-420h]
  int v24; // [sp+34h] [-41Ch]
  int v25; // [sp+38h] [-418h]
  int v26; // [sp+3Ch] [-414h]
  int v27; // [sp+40h] [-410h]
  int v28; // [sp+44h] [-40Ch]
  int v29; // [sp+48h] [-408h]
  int v30; // [sp+4Ch] [-404h]
  int v31; // [sp+50h] [-400h]
  int v32; // [sp+58h] [-3F8h]
  int v33; // [sp+60h] [-3F0h]
  char v34; // [sp+70h] [-3E0h] BYREF
  contactsResult_t v35; // [sp+80h] [-3D0h] BYREF

  if ( this->clipModel == nullptr )
    return false;
  this->ClearContacts(this);
  v3 = 0;
  idClip::Contacts(
    this: (idClip *)&v34,
    result: this->clip,
    a3: &v35,
    start: &this->clipModel->origin,
    dir: &vec3_origin,
    depth: 0.25,
    clipModel: (const idClipModel *)this->clipMask,
    startAxis: (const idMat3 *)this->clipModel,
    clipMask: (int)&this->clipModel->axis,
    passEntityNumber: v13,
    userName: v14,
    a12: v15,
    a13: v16,
    a14: v17,
    a15: v18,
    a16: v19,
    a17: v20,
    a18: v21,
    a19: v22,
    a20: v23,
    a21: v24,
    a22: v25,
    a23: v26,
    a24: v27,
    a25: v28,
    a26: v29,
    a27: v30,
    a28: v31,
    a29: (const idBounds *)this->clipMask,
    a30: v32,
    a31: (const idClipModel *)this->entityNumber,
    a32: v33,
    a33: 0);
  if ( v35.numContacts > 0 )
  {
    p_contacts = &this->contacts;
    contacts = v35.contacts;
    do
    {
      if ( p_contacts->list != nullptr )
        goto LABEL_9;
      granularity = this->contacts.granularity;
      if ( granularity <= 0 )
        granularity = 1;
      if ( (unsigned __int8)idList<contactInfo_t,77>::Resize(this: &this->contacts, newsize: granularity) != 0 )
      {
LABEL_9:
        size = this->contacts.size;
        if ( this->contacts.num != size )
          goto LABEL_20;
        if ( forceIdListsToReallocateEveryAppend )
        {
          v8 = (unsigned __int8)idList<contactInfo_t,77>::Resize(this: &this->contacts, newsize: size + 1) == 0;
        }
        else
        {
          v9 = this->contacts.granularity;
          if ( this->contacts.granularity != 0 )
          {
            v11 = size + v9;
            __twllei(v9, 0);
            __twlgei(v9 & ~(__ROL4__(v11, 1) - 1), 0xFFFFFFFF);
            v8 = (unsigned __int8)idList<contactInfo_t,77>::Resize(this: &this->contacts, newsize: v11 - v11 % v9) == 0;
          }
          else
          {
            v10 = 2 * size;
            if ( 2 * size >= size )
            {
              if ( v10 == 0 )
                v10 = 1;
              v8 = (unsigned __int8)idList<contactInfo_t,77>::Resize(this: &this->contacts, newsize: v10) == 0;
            }
            else
            {
              v8 = (unsigned __int8)idList<contactInfo_t,77>::Resize(this: &this->contacts, newsize: 0x7FFFFFFF) == 0;
            }
          }
        }
        if ( !v8 )
        {
LABEL_20:
          num = this->contacts.num;
          if ( num < this->contacts.size )
          {
            contactInfo_t::operator=(this: &p_contacts->list[num], __that: contacts);
            ++this->contacts.num;
          }
        }
      }
      ++v3;
      ++contacts;
    }
    while ( v3 < v35.numContacts );
  }
  idPhysics_DynamicBase::AddContactPhysicsForContacts(this);
  return this->contacts.num != 0;
}


// ========================================================================
// `dynamic initializer for 'rb_showTimings''
// EA  : 0x83341498
// RVA : 0x01341498
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rb_showTimings__()
{
  idCVar::idCVar(
    this: &rb_showTimings,
    name: "rb_showTimings",
    value: "0",
    flags: 1,
    description: "show rigid body cpu usage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rb_showTimings__);
}


// ========================================================================
// `dynamic initializer for 'rb_showBodies''
// EA  : 0x833414F0
// RVA : 0x013414F0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rb_showBodies__()
{
  idCVar::idCVar(
    this: &rb_showBodies,
    name: "rb_showBodies",
    value: "0",
    flags: 1,
    description: "show rigid bodies",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rb_showBodies__);
}


// ========================================================================
// `dynamic initializer for 'rb_showMass''
// EA  : 0x83341548
// RVA : 0x01341548
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rb_showMass__()
{
  idCVar::idCVar(
    this: &rb_showMass,
    name: "rb_showMass",
    value: "0",
    flags: 1,
    description: "show the mass of each rigid body",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rb_showMass__);
}


// ========================================================================
// `dynamic initializer for 'rb_showInertia''
// EA  : 0x833415A0
// RVA : 0x013415A0
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rb_showInertia__()
{
  idCVar::idCVar(
    this: &rb_showInertia,
    name: "rb_showInertia",
    value: "0",
    flags: 1,
    description: "show the inertia tensor of each rigid body",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rb_showInertia__);
}


// ========================================================================
// `dynamic initializer for 'rb_showVelocity''
// EA  : 0x833415F8
// RVA : 0x013415F8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rb_showVelocity__()
{
  idCVar::idCVar(
    this: &rb_showVelocity,
    name: "rb_showVelocity",
    value: "0",
    flags: 1,
    description: "show the velocity of each rigid body",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rb_showVelocity__);
}


// ========================================================================
// `dynamic initializer for 'rb_showActive''
// EA  : 0x83341650
// RVA : 0x01341650
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rb_showActive__()
{
  idCVar::idCVar(
    this: &rb_showActive,
    name: "rb_showActive",
    value: "0",
    flags: 1,
    description: "show rigid bodies that are not at rest",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rb_showActive__);
}


// ========================================================================
// `dynamic initializer for 'MAX_ANGULAR_VELOCITY''
// EA  : 0x833416A8
// RVA : 0x013416A8
// PDB : w:\tech5\engine\gamelib\physics\physics_rigidbody.cpp
// ========================================================================

void _dynamic_initializer_for__MAX_ANGULAR_VELOCITY__()
{
  MAX_ANGULAR_VELOCITY = (float)3.1415927 * (float)4.0;
}

