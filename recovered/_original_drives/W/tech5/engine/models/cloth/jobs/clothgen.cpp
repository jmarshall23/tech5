
// ========================================================================
// ?SphereLineIntersection@@YA_NABVidVec3@@M00@Z
// EA  : 0x827AD058
// RVA : 0x007AD058
// PDB : w:\tech5\engine\models\cloth\jobs\clothgen.cpp
// ========================================================================

BOOL __fastcall SphereLineIntersection(
        const idVec3 *origin,
        double radiusSqr,
        const idVec3 *start,
        const idVec3 *end,
        float *a5)
{
  double v5; // fp0
  double v6; // fp7
  double v7; // fp13
  double v8; // fp6
  double v9; // fp12
  double v10; // fp11
  double v11; // fp10
  double v12; // fp9
  double v13; // fp8
  double v15; // fp12
  double v16; // fp4
  double v17; // fp3
  double v18; // fp2

  v5 = (float)(end->y - origin->y);
  v7 = (float)(end->z - origin->z);
  v9 = (float)(end->x - origin->x);
  v10 = (float)((float)(a5[1] - origin->y) - (float)(end->y - origin->y));
  v11 = (float)((float)(a5[2] - origin->z) - (float)(end->z - origin->z));
  v12 = (float)((float)(*a5 - origin->x) - (float)(end->x - origin->x));
  v13 = (float)((float)((float)-v9 * (float)((float)(*a5 - origin->x) - (float)(end->x - origin->x)))
              + (float)((float)((float)-v7 * (float)((float)(a5[2] - origin->z) - (float)(end->z - origin->z)))
                      + (float)((float)-v5 * (float)((float)(a5[1] - origin->y) - (float)(end->y - origin->y)))));
  if ( v13 > 0.0 )
  {
    if ( v13 < (float)((float)((float)v12 * (float)v12)
                     + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10))) )
    {
      v16 = (float)((float)((float)((float)(a5[1] - origin->y) - (float)(end->y - origin->y))
                          * (float)((float)((float)((float)-v9
                                                  * (float)((float)(*a5 - origin->x) - (float)(end->x - origin->x)))
                                          + (float)((float)((float)-v7
                                                          * (float)((float)(a5[2] - origin->z)
                                                                  - (float)(end->z - origin->z)))
                                                  + (float)((float)-v5
                                                          * (float)((float)(a5[1] - origin->y)
                                                                  - (float)(end->y - origin->y)))))
                                  / (float)((float)((float)v12 * (float)v12)
                                          + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)))))
                  + (float)(end->y - origin->y));
      v17 = (float)((float)((float)((float)(a5[2] - origin->z) - (float)(end->z - origin->z))
                          * (float)((float)((float)((float)-v9
                                                  * (float)((float)(*a5 - origin->x) - (float)(end->x - origin->x)))
                                          + (float)((float)((float)-v7
                                                          * (float)((float)(a5[2] - origin->z)
                                                                  - (float)(end->z - origin->z)))
                                                  + (float)((float)-v5
                                                          * (float)((float)(a5[1] - origin->y)
                                                                  - (float)(end->y - origin->y)))))
                                  / (float)((float)((float)v12 * (float)v12)
                                          + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)))))
                  + (float)(end->z - origin->z));
      v18 = (float)((float)((float)((float)(*a5 - origin->x) - (float)(end->x - origin->x))
                          * (float)((float)((float)((float)-v9
                                                  * (float)((float)(*a5 - origin->x) - (float)(end->x - origin->x)))
                                          + (float)((float)((float)-v7
                                                          * (float)((float)(a5[2] - origin->z)
                                                                  - (float)(end->z - origin->z)))
                                                  + (float)((float)-v5
                                                          * (float)((float)(a5[1] - origin->y)
                                                                  - (float)(end->y - origin->y)))))
                                  / (float)((float)((float)v12 * (float)v12)
                                          + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)))))
                  + (float)(end->x - origin->x));
      v15 = (float)((float)((float)v18 * (float)v18)
                  + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)));
    }
    else
    {
      v6 = (float)(a5[1] - origin->y);
      v8 = (float)(a5[2] - origin->z);
      v15 = (float)((float)((float)(*a5 - origin->x) * (float)(*a5 - origin->x))
                  + (float)((float)((float)v8 * (float)v8) + (float)((float)v6 * (float)v6)));
    }
    return v15 < radiusSqr;
  }
  else
  {
    return (float)((float)((float)v7 * (float)v7)
                 + (float)((float)((float)v5 * (float)v5)
                         + (float)((float)(end->x - origin->x) * (float)(end->x - origin->x)))) < radiusSqr;
  }
}


// ========================================================================
// ?MakeRotationMat@@YAXAAVidMat3@@ABVidVec3@@M@Z
// EA  : 0x827AD140
// RVA : 0x007AD140
// PDB : w:\tech5\engine\models\cloth\jobs\clothgen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall MakeRotationMat(idMat3 *axis, const idVec3 *rotationVec, double angle)
{
  double v5; // fp31
  long double v6; // fp2
  long double v7; // fp2
  double v8; // fp30
  long double v9; // fp2
  double v10; // fp0
  double v11; // fp12
  double v12; // fp9
  double v13; // fp10
  double v14; // fp11
  double v15; // fp8
  double v16; // fp7
  double v17; // fp6
  double v18; // fp3

  v5 = (float)((float)angle * (float)0.5);
  *(double *)&v6 = v5;
  v7 = sin(x: v6);
  v8 = (float)*(double *)&v7;
  *(double *)&v7 = v5;
  v9 = cos(x: v7);
  v10 = (float)((float)((float)(rotationVec->z * (float)v8) * (float)2.0) * (float)(rotationVec->x * (float)v8));
  v11 = (float)((float)((float)(rotationVec->z * (float)v8) * (float)2.0) * (float)(rotationVec->y * (float)v8));
  v12 = (float)((float)((float)(rotationVec->z * (float)v8) * (float)2.0) * (float)*(double *)&v9);
  v13 = (float)((float)((float)(rotationVec->y * (float)v8) * (float)2.0) * (float)*(double *)&v9);
  v14 = (float)((float)((float)(rotationVec->x * (float)v8) * (float)2.0) * (float)*(double *)&v9);
  v15 = (float)((float)((float)((float)(rotationVec->y * (float)v8) * (float)2.0) * (float)(rotationVec->y * (float)v8))
              + (float)((float)((float)(rotationVec->x * (float)v8) * (float)2.0) * (float)(rotationVec->x * (float)v8)));
  v16 = (float)((float)((float)((float)(rotationVec->z * (float)v8) * (float)2.0) * (float)(rotationVec->z * (float)v8))
              + (float)((float)((float)(rotationVec->y * (float)v8) * (float)2.0) * (float)(rotationVec->y * (float)v8)));
  v17 = (float)((float)((float)((float)(rotationVec->z * (float)v8) * (float)2.0) * (float)(rotationVec->z * (float)v8))
              + (float)((float)((float)(rotationVec->x * (float)v8) * (float)2.0) * (float)(rotationVec->x * (float)v8)));
  v18 = (float)((float)((float)((float)(rotationVec->y * (float)v8) * (float)2.0) * (float)(rotationVec->x * (float)v8))
              - (float)((float)((float)(rotationVec->z * (float)v8) * (float)2.0) * (float)*(double *)&v9));
  *(double *)&v9 = (float)((float)((float)(rotationVec->y * (float)v8) * (float)2.0)
                         * (float)(rotationVec->x * (float)v8));
  axis->mat[0].y = v18;
  axis->mat[1].x = (float)v12 + (float)*(double *)&v9;
  axis->mat[0].z = (float)v13 + (float)v10;
  axis->mat[2].x = (float)v10 - (float)v13;
  axis->mat[1].z = (float)v11 - (float)v14;
  axis->mat[2].y = (float)v14 + (float)v11;
  axis->mat[0].x = (float)1.0 - (float)v16;
  axis->mat[1].y = (float)1.0 - (float)v17;
  axis->mat[2].z = (float)1.0 - (float)v15;
}


// ========================================================================
// ?Reset@idClothParticle@@QAAXXZ
// EA  : 0x827AD258
// RVA : 0x007AD258
// PDB : w:\tech5\engine\models\cloth\jobs\clothgen.cpp
// ========================================================================

void __fastcall idClothParticle::Reset(idClothParticle *this)
{
  this->origin.z = 0.0;
  this->origin.y = 0.0;
  this->origin.x = 0.0;
  this->lastOrigin.z = 0.0;
  this->lastOrigin.y = 0.0;
  this->lastOrigin.x = 0.0;
  this->axis.mat[2].z = 1.0;
  this->axis.mat[1].y = 1.0;
  this->axis.mat[0].x = 1.0;
  this->axis.mat[1].z = 0.0;
  this->axis.mat[0].z = 0.0;
  this->axis.mat[0].y = 0.0;
  this->axis.mat[2].y = 0.0;
  this->axis.mat[2].x = 0.0;
  this->axis.mat[1].x = 0.0;
  this->mass = 0.0;
  this->velocity.z = 0.0;
  this->velocity.y = 0.0;
  this->velocity.x = 0.0;
  this->force.z = 0.0;
  this->force.y = 0.0;
  this->force.x = 0.0;
  this->anchored = 0;
  this->state = 0;
}


// ========================================================================
// ?Update@idClothParticle@@QAA_NMABVidVec3@@ABVidMat3@@ABM@Z
// EA  : 0x827AD2D0
// RVA : 0x007AD2D0
// PDB : w:\tech5\engine\models\cloth\jobs\clothgen.cpp
// ========================================================================

int __fastcall idClothParticle::Update(
        idClothParticle *this,
        double timeDeltaSqr,
        const idVec3 *org,
        const idMat3 *axis,
        const float *friction,
        float *a6)
{
  int result; // r3
  double x; // fp12
  double y; // fp11
  double v10; // fp9
  double v11; // fp6
  double v12; // fp8
  double v13; // fp7
  double v14; // fp8
  double v15; // fp2
  double v16; // fp12
  double v17; // fp11
  double v18; // fp9
  double v19; // fp0
  double v20; // fp12
  float v21; // [sp+0h] [-20h]
  float v22; // [sp+4h] [-1Ch]
  float z; // [sp+8h] [-18h]

  if ( this->anchored != 0 )
  {
    result = 0;
  }
  else
  {
    x = this->force.x;
    y = this->force.y;
    v10 = (float)((float)1.0 / this->mass);
    v21 = this->origin.x;
    v22 = this->origin.y;
    result = 1;
    v11 = (float)(this->force.z * (float)((float)1.0 / this->mass));
    z = this->origin.z;
    this->velocity.z = this->force.z * (float)((float)1.0 / this->mass);
    v12 = (float)((float)x * (float)v10);
    this->velocity.x = (float)x * (float)v10;
    this->velocity.y = (float)v10 * (float)y;
    v15 = (float)((float)(friction[1] * (float)((float)x * (float)v10))
                + (float)(friction[4] * (float)((float)v10 * (float)y)));
    v16 = (float)((float)(friction[2] * (float)((float)x * (float)v10))
                + (float)(friction[5] * (float)((float)v10 * (float)y)));
    v17 = (float)((float)((float)v12 * *friction)
                + (float)((float)(friction[3] * (float)((float)v10 * (float)y)) + (float)(friction[6] * (float)v11)));
    v14 = friction[7];
    v13 = friction[8];
    this->velocity.x = v17;
    this->velocity.y = (float)((float)v14 * (float)v11) + (float)v15;
    v18 = (float)((float)((float)v13 * (float)v11) + (float)v16);
    this->velocity.z = (float)((float)v13 * (float)v11) + (float)v16;
    v19 = (float)((float)(this->origin.z * (float)((float)2.0 - *a6))
                - (float)(this->lastOrigin.z * (float)((float)1.0 - *a6)));
    v20 = (float)((float)((float)(this->origin.y * (float)((float)2.0 - *a6))
                        - (float)(this->lastOrigin.y * (float)((float)1.0 - *a6)))
                + (float)((float)((float)((float)v14 * (float)v11) + (float)v15) * (float)timeDeltaSqr));
    this->origin.x = (float)((float)(this->origin.x * (float)((float)2.0 - *a6))
                           - (float)(this->lastOrigin.x * (float)((float)1.0 - *a6)))
                   + (float)((float)timeDeltaSqr * (float)v17);
    this->origin.y = v20;
    this->origin.z = (float)v19 + (float)((float)v18 * (float)timeDeltaSqr);
    this->lastOrigin.x = v21;
    this->lastOrigin.y = v22;
    this->lastOrigin.z = z;
  }
  this->force.x = 0.0;
  this->force.y = 0.0;
  this->force.z = 0.0;
  return result;
}


// ========================================================================
// ?Collide@idClothParticle@@QAAXPBVidSphere@@M@Z
// EA  : 0x827AD458
// RVA : 0x007AD458
// PDB : w:\tech5\engine\models\cloth\jobs\clothgen.cpp
// ========================================================================

void __fastcall idClothParticle::Collide(idClothParticle *this, const idSphere *s, double radSqr)
{
  double v3; // fp10
  double v4; // fp9
  double v5; // fp0
  double v8; // fp1
  double v9; // fp12
  double v10; // fp2
  double v11; // fp1
  double v12; // fp13
  double v13; // fp12

  v3 = (float)(this->origin.z - s->origin.z);
  v4 = (float)(this->origin.y - s->origin.y);
  v5 = (float)((float)((float)v4 * (float)v4)
             + (float)((float)((float)v3 * (float)v3)
                     + (float)((float)(this->origin.x - s->origin.x) * (float)(this->origin.x - s->origin.x))));
  if ( v5 < radSqr )
  {
    _FP4 = (float)((float)((float)((float)v4 * (float)v4)
                         + (float)((float)((float)v3 * (float)v3)
                                 + (float)((float)(this->origin.x - s->origin.x) * (float)(this->origin.x - s->origin.x))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f2, f4, f0, f12 }
    v8 = __frsqrte(_FP2);
    v9 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8
                                                                                       * (float)((float)v5 * (float)0.5))
                                                                               * (float)v8)
                                                                       - (float)1.5)
                                                       * (float)v8)
                                               * (float)((float)v5 * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v8
                                                                               * (float)((float)v5 * (float)0.5))
                                                                       * (float)v8)
                                                               - (float)1.5)
                                               * (float)v8))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8)
                                       - (float)1.5)
                       * (float)v8));
    v10 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8) - (float)1.5)
                                                                                                * (float)v8)
                                                                                        * (float)((float)v5 * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8) - (float)1.5)
                                                                                        * (float)v8))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v8
                                                                                                * (float)((float)v5 * (float)0.5))
                                                                                        * (float)v8)
                                                                                - (float)1.5)
                                                                * (float)v8))
                                                * (float)((float)v5 * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8) - (float)1.5)
                                                                                        * (float)v8)
                                                                                * (float)((float)v5 * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8)
                                                                                                - (float)1.5)
                                                                                * (float)v8))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v8
                                                                                        * (float)((float)v5 * (float)0.5))
                                                                                * (float)v8)
                                                                        - (float)1.5)
                                                        * (float)v8)))
                                - (float)1.5)
                * (float)v9);
    v12 = (float)(s->origin.y
                + (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8) - (float)1.5) * (float)v8) * (float)((float)v5 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8) - (float)1.5) * (float)v8))
                                                                                                - (float)1.5)
                                                                                * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8) - (float)1.5)
                                                                                        * (float)v8))
                                                                        * (float)((float)v5 * (float)0.5))
                                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8) - (float)1.5) * (float)v8) * (float)((float)v5 * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8) - (float)1.5) * (float)v8))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8)
                                                                                                - (float)1.5)
                                                                                * (float)v8)))
                                                        - (float)1.5)
                                        * (float)v9)
                                * (float)(this->origin.y - s->origin.y))
                        * s->radius));
    v11 = (float)((float)(this->origin.x - s->origin.x)
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8) - (float)1.5) * (float)v8)
                                                                                                * (float)((float)v5 * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8) - (float)1.5)
                                                                                                * (float)v8))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5))
                                                                                                * (float)v8)
                                                                                        - (float)1.5)
                                                                        * (float)v8))
                                                        * (float)((float)v5 * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8) - (float)1.5)
                                                                                                * (float)v8)
                                                                                        * (float)((float)v5 * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)v5 * (float)0.5)) * (float)v8) - (float)1.5)
                                                                                        * (float)v8))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v8
                                                                                                * (float)((float)v5 * (float)0.5))
                                                                                        * (float)v8)
                                                                                - (float)1.5)
                                                                * (float)v8)))
                                        - (float)1.5)
                        * (float)v9));
    v13 = (float)(s->origin.z + (float)((float)((float)(this->origin.z - s->origin.z) * (float)v10) * s->radius));
    if ( this->anchored == 0 )
    {
      this->origin.x = s->origin.x + (float)((float)v11 * s->radius);
      this->origin.y = v12;
      this->origin.z = v13;
    }
  }
}


// ========================================================================
// ??0idClothSpring@@QAA@XZ
// EA  : 0x827AD528
// RVA : 0x007AD528
// PDB : w:\tech5\engine\models\cloth\jobs\clothgen.cpp
// ========================================================================

idClothSpring *__fastcall idClothSpring::idClothSpring(idClothSpring *this)
{
  this->p1 = 0;
  this->p2 = 0;
  this->band = false;
  this->friction = 0.0;
  this->edge = false;
  return this;
}


// ========================================================================
// ?Init@idClothSpring@@QAAXMPAVidClothParticle@@HH_N1@Z
// EA  : 0x827AD550
// RVA : 0x007AD550
// PDB : w:\tech5\engine\models\cloth\jobs\clothgen.cpp
// ========================================================================

void __fastcall idClothSpring::Init(
        idClothSpring *this,
        double friction,
        idClothParticle *cloth,
        int p1,
        int p2,
        int band,
        bool edge,
        bool a8)
{
  float *v8; // r11
  float *v9; // r10
  double v10; // fp7
  double v11; // fp5
  double v12; // fp13

  this->edge = a8;
  this->friction = friction;
  this->p1 = p2;
  this->p2 = band;
  this->band = edge;
  v8 = (float *)(96 * band + p1);
  v9 = (float *)(96 * p2 + p1);
  v10 = (float)(v9[2] - v8[2]);
  v11 = (float)(v9[1] - v8[1]);
  v12 = __fsqrts((float)((float)((float)v11 * (float)v11)
                       + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v9 - *v8) * (float)(*v9 - *v8)))));
  this->springLength = v12;
  if ( edge )
    this->springLength = (float)v12 * (float)1.15;
  this->slSquared = this->springLength * this->springLength;
}


// ========================================================================
// ?Init2@idClothSpring@@QAAXHHMMM@Z
// EA  : 0x827AD5E8
// RVA : 0x007AD5E8
// PDB : w:\tech5\engine\models\cloth\jobs\clothgen.cpp
// ========================================================================

void __fastcall idClothSpring::Init2(
        idClothSpring *this,
        int p1,
        int p2,
        double springLength,
        double springFriction,
        double springLengthMultiplier)
{
  this->springLength = springLength;
  this->friction = springFriction;
  this->p1 = p1;
  this->maxLengthMultiplier = springLengthMultiplier;
  this->p2 = p2;
  this->band = false;
  this->edge = false;
}


// ========================================================================
// ?Constrain@idClothSpring@@QAAXPAVidClothParticle@@@Z
// EA  : 0x827AD610
// RVA : 0x007AD610
// PDB : w:\tech5\engine\models\cloth\jobs\clothgen.cpp
// ========================================================================

void __fastcall idClothSpring::Constrain(idClothSpring *this, idClothParticle *cloth)
{
  idClothParticle *v2; // r10
  idClothParticle *v3; // r11
  double v4; // fp8
  double v5; // fp3
  double v6; // fp13
  double v7; // fp12
  double v8; // fp0
  double v9; // fp10
  double v10; // fp9
  double v11; // fp13
  double v12; // fp12
  double v13; // fp0

  v3 = &cloth[this->p2];
  v2 = &cloth[this->p1];
  v4 = (float)(v2->origin.z - v3->origin.z);
  v5 = (float)(v2->origin.y - v3->origin.y);
  v6 = (float)(forceAmt
             * (float)((float)(v2->origin.x - v3->origin.x)
                     * (float)((float)(this->slSquared
                                     / (float)((float)((float)((float)v5 * (float)v5)
                                                     + (float)((float)((float)(v2->origin.x - v3->origin.x)
                                                                     * (float)(v2->origin.x - v3->origin.x))
                                                             + (float)((float)v4 * (float)v4)))
                                             + this->slSquared))
                             - (float)0.5)));
  v7 = (float)(forceAmt
             * (float)((float)((float)(this->slSquared
                                     / (float)((float)((float)((float)v5 * (float)v5)
                                                     + (float)((float)((float)(v2->origin.x - v3->origin.x)
                                                                     * (float)(v2->origin.x - v3->origin.x))
                                                             + (float)((float)v4 * (float)v4)))
                                             + this->slSquared))
                             - (float)0.5)
                     * (float)v5));
  v8 = (float)(forceAmt
             * (float)((float)v4
                     * (float)((float)(this->slSquared
                                     / (float)((float)((float)((float)v5 * (float)v5)
                                                     + (float)((float)((float)(v2->origin.x - v3->origin.x)
                                                                     * (float)(v2->origin.x - v3->origin.x))
                                                             + (float)((float)v4 * (float)v4)))
                                             + this->slSquared))
                             - (float)0.5)));
  v9 = (float)(v3->origin.y
             - (float)(forceAmt
                     * (float)((float)((float)(this->slSquared
                                             / (float)((float)((float)((float)v5 * (float)v5)
                                                             + (float)((float)((float)(v2->origin.x - v3->origin.x)
                                                                             * (float)(v2->origin.x - v3->origin.x))
                                                                     + (float)((float)v4 * (float)v4)))
                                                     + this->slSquared))
                                     - (float)0.5)
                             * (float)v5)));
  v10 = (float)(v3->origin.z
              - (float)(forceAmt
                      * (float)((float)v4
                              * (float)((float)(this->slSquared
                                              / (float)((float)((float)((float)v5 * (float)v5)
                                                              + (float)((float)((float)(v2->origin.x - v3->origin.x)
                                                                              * (float)(v2->origin.x - v3->origin.x))
                                                                      + (float)((float)v4 * (float)v4)))
                                                      + this->slSquared))
                                      - (float)0.5))));
  if ( v3->anchored == 0 )
  {
    v3->origin.x = v3->origin.x
                 - (float)(forceAmt
                         * (float)((float)(v2->origin.x - v3->origin.x)
                                 * (float)((float)(this->slSquared
                                                 / (float)((float)((float)((float)v5 * (float)v5)
                                                                 + (float)((float)((float)(v2->origin.x - v3->origin.x)
                                                                                 * (float)(v2->origin.x - v3->origin.x))
                                                                         + (float)((float)v4 * (float)v4)))
                                                         + this->slSquared))
                                         - (float)0.5)));
    v3->origin.y = v9;
    v3->origin.z = v10;
  }
  v11 = (float)(v2->origin.x + (float)v6);
  v12 = (float)(v2->origin.y + (float)v7);
  v13 = (float)(v2->origin.z + (float)v8);
  if ( v2->anchored == 0 )
  {
    v2->origin.x = v11;
    v2->origin.y = v12;
    v2->origin.z = v13;
  }
}


// ========================================================================
// ?Constrain2@idClothSpring@@QAAXPAVidClothParticle@@@Z
// EA  : 0x827AD6F8
// RVA : 0x007AD6F8
// PDB : w:\tech5\engine\models\cloth\jobs\clothgen.cpp
// ========================================================================

void __fastcall idClothSpring::Constrain2(idClothSpring *this, idClothParticle *cloth)
{
  idClothParticle *v2; // r11
  idClothParticle *v3; // r10
  double v4; // fp5
  double v5; // fp2
  double v8; // fp9
  double v9; // fp3
  double v10; // fp13
  double v11; // fp11
  double v12; // fp6
  double v13; // fp5
  double v14; // fp3
  double v15; // fp0
  double v16; // fp10
  double v17; // fp9
  double v18; // fp12
  double v19; // fp0

  v2 = &cloth[this->p1];
  v3 = &cloth[this->p2];
  v4 = (float)(v3->origin.y - v2->origin.y);
  v5 = (float)(v3->origin.z - v2->origin.z);
  _FP3 = (float)((float)((float)((float)v5 * (float)v5)
                       + (float)((float)((float)v4 * (float)v4)
                               + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f12, f3, f6, f12 }
  v8 = __frsqrte(_FP12);
  v9 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8
                                                                                     * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
                                                                                             * (float)0.5))
                                                                             * (float)v8)
                                                                     - (float)1.5)
                                                     * (float)v8)
                                             * (float)((float)((float)((float)v5 * (float)v5)
                                                             + (float)((float)((float)v4 * (float)v4)
                                                                     + (float)((float)(v3->origin.x - v2->origin.x)
                                                                             * (float)(v3->origin.x - v2->origin.x))))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v8
                                                                             * (float)((float)((float)((float)v5 * (float)v5)
                                                                                             + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
                                                                                     * (float)0.5))
                                                                     * (float)v8)
                                                             - (float)1.5)
                                             * (float)v8))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v8
                                                     * (float)((float)((float)((float)v5 * (float)v5)
                                                                     + (float)((float)((float)v4 * (float)v4)
                                                                             + (float)((float)(v3->origin.x
                                                                                             - v2->origin.x)
                                                                                     * (float)(v3->origin.x
                                                                                             - v2->origin.x))))
                                                             * (float)0.5))
                                             * (float)v8)
                                     - (float)1.5)
                     * (float)v8));
  v10 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5)) * (float)v8) - (float)1.5)
                                                                                      * (float)v8)
                                                                              * (float)((float)((float)((float)v5 * (float)v5)
                                                                                              + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5)) * (float)v8)
                                                                                              - (float)1.5)
                                                                              * (float)v8))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v8
                                                                                      * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
                                                                                              * (float)0.5))
                                                                              * (float)v8)
                                                                      - (float)1.5)
                                                      * (float)v8))
                                      * (float)((float)((float)((float)v5 * (float)v5)
                                                      + (float)((float)((float)v4 * (float)v4)
                                                              + (float)((float)(v3->origin.x - v2->origin.x)
                                                                      * (float)(v3->origin.x - v2->origin.x))))
                                              * (float)0.5))
                              * (float)v9)
                      - (float)1.5);
  v11 = (float)((float)((float)((float)v10
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5)) * (float)v8)
                                                                                              - (float)1.5)
                                                                              * (float)v8)
                                                                      * (float)((float)((float)((float)v5 * (float)v5)
                                                                                      + (float)((float)((float)v4 * (float)v4)
                                                                                              + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
                                                                              * (float)0.5))
                                                              * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5))
                                                                                              * (float)v8)
                                                                                      - (float)1.5)
                                                                      * (float)v8))
                                                      - (float)1.5)
                                      * (float)((float)-(float)((float)((float)((float)v8
                                                                              * (float)((float)((float)((float)v5 * (float)v5)
                                                                                              + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
                                                                                      * (float)0.5))
                                                                      * (float)v8)
                                                              - (float)1.5)
                                              * (float)v8)))
                      * (float)((float)((float)v5 * (float)v5)
                              + (float)((float)((float)v4 * (float)v4)
                                      + (float)((float)(v3->origin.x - v2->origin.x)
                                              * (float)(v3->origin.x - v2->origin.x)))))
              - this->springLength);
  v12 = (float)((float)v5
              * (float)((float)v10
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5))
                                                                                              * (float)v8)
                                                                                      - (float)1.5)
                                                                      * (float)v8)
                                                              * (float)((float)((float)((float)v5 * (float)v5)
                                                                              + (float)((float)((float)v4 * (float)v4)
                                                                                      + (float)((float)(v3->origin.x - v2->origin.x)
                                                                                              * (float)(v3->origin.x - v2->origin.x))))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v8
                                                                                              * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5))
                                                                                      * (float)v8)
                                                                              - (float)1.5)
                                                              * (float)v8))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v8
                                                                      * (float)((float)((float)((float)v5 * (float)v5)
                                                                                      + (float)((float)((float)v4 * (float)v4)
                                                                                              + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
                                                                              * (float)0.5))
                                                              * (float)v8)
                                                      - (float)1.5)
                                      * (float)v8))));
  v14 = (float)((float)((float)v4
                      * (float)((float)v10
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5)) * (float)v8)
                                                                                              - (float)1.5)
                                                                              * (float)v8)
                                                                      * (float)((float)((float)((float)v5 * (float)v5)
                                                                                      + (float)((float)((float)v4 * (float)v4)
                                                                                              + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
                                                                              * (float)0.5))
                                                              * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5))
                                                                                              * (float)v8)
                                                                                      - (float)1.5)
                                                                      * (float)v8))
                                                      - (float)1.5)
                                      * (float)((float)-(float)((float)((float)((float)v8
                                                                              * (float)((float)((float)((float)v5 * (float)v5)
                                                                                              + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
                                                                                      * (float)0.5))
                                                                      * (float)v8)
                                                              - (float)1.5)
                                              * (float)v8))))
              * (float)v11);
  v15 = (float)((float)((float)v11
                      * (float)((float)v5
                              * (float)((float)v10
                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5)) * (float)v8) - (float)1.5)
                                                                                      * (float)v8)
                                                                              * (float)((float)((float)((float)v5 * (float)v5)
                                                                                              + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5)) * (float)v8)
                                                                                              - (float)1.5)
                                                                              * (float)v8))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v8
                                                                                      * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
                                                                                              * (float)0.5))
                                                                              * (float)v8)
                                                                      - (float)1.5)
                                                      * (float)v8)))))
              * (float)0.5);
  v16 = (float)(v2->origin.y
              + (float)((float)((float)((float)v4
                                      * (float)((float)v10
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5)) * (float)v8) - (float)1.5)
                                                                                              * (float)v8)
                                                                                      * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5)) * (float)v8) - (float)1.5)
                                                                                      * (float)v8))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v8
                                                                                              * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5))
                                                                                      * (float)v8)
                                                                              - (float)1.5)
                                                              * (float)v8))))
                              * (float)v11)
                      * (float)0.5));
  v13 = (float)((float)v11
              * (float)((float)(v3->origin.x - v2->origin.x)
                      * (float)((float)v10
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5)) * (float)v8)
                                                                                              - (float)1.5)
                                                                              * (float)v8)
                                                                      * (float)((float)((float)((float)v5 * (float)v5)
                                                                                      + (float)((float)((float)v4 * (float)v4)
                                                                                              + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
                                                                              * (float)0.5))
                                                              * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x)))) * (float)0.5))
                                                                                              * (float)v8)
                                                                                      - (float)1.5)
                                                                      * (float)v8))
                                                      - (float)1.5)
                                      * (float)((float)-(float)((float)((float)((float)v8
                                                                              * (float)((float)((float)((float)v5 * (float)v5)
                                                                                              + (float)((float)((float)v4 * (float)v4) + (float)((float)(v3->origin.x - v2->origin.x) * (float)(v3->origin.x - v2->origin.x))))
                                                                                      * (float)0.5))
                                                                      * (float)v8)
                                                              - (float)1.5)
                                              * (float)v8)))));
  v17 = (float)(v2->origin.z + (float)((float)((float)v11 * (float)v12) * (float)0.5));
  if ( v2->anchored == 0 )
  {
    v2->origin.x = v2->origin.x + (float)((float)v13 * (float)0.5);
    v2->origin.y = v16;
    v2->origin.z = v17;
  }
  v18 = (float)(v3->origin.y - (float)((float)v14 * (float)0.5));
  v19 = (float)(v3->origin.z - (float)v15);
  if ( v3->anchored == 0 )
  {
    v3->origin.x = v3->origin.x - (float)((float)v13 * (float)0.5);
    v3->origin.y = v18;
    v3->origin.z = v19;
  }
}


// ========================================================================
// ?Simulate@idClothParticle@@QAA_NMM@Z
// EA  : 0x827AD828
// RVA : 0x007AD828
// PDB : w:\tech5\engine\models\cloth\jobs\clothgen.cpp
// ========================================================================

int __fastcall idClothParticle::Simulate(idClothParticle *this, double dt, double frictionFactor)
{
  int anchored; // r10
  int result; // r3
  double z; // fp12
  double v7; // fp9
  double v8; // fp8
  double v9; // fp7
  double y; // fp12
  double v11; // fp11
  double v12; // fp8
  double v13; // fp3
  double v14; // fp4

  anchored = this->anchored;
  result = 1;
  if ( anchored == 0 )
  {
    z = this->lastOrigin.z;
    v7 = (float)(this->origin.x - this->lastOrigin.x);
    v8 = this->origin.z;
    v9 = (float)(this->origin.y - this->lastOrigin.y);
    this->lastOrigin.x = this->origin.x;
    this->lastOrigin.y = this->origin.y;
    this->lastOrigin.z = this->origin.z;
    v11 = this->origin.z;
    v12 = (float)((float)((float)v8 - (float)z) * (float)((float)1.0 - (float)frictionFactor));
    y = this->origin.y;
    v13 = (float)((float)((float)v9 * (float)((float)1.0 - (float)frictionFactor))
                + (float)((float)(this->force.y * (float)dt) * (float)dt));
    v14 = (float)((float)v12 + (float)((float)(this->force.z * (float)dt) * (float)dt));
    this->origin.x = this->origin.x
                   + (float)((float)((float)v7 * (float)((float)1.0 - (float)frictionFactor))
                           + (float)((float)(this->force.x * (float)dt) * (float)dt));
    this->origin.y = (float)y + (float)v13;
    this->origin.z = (float)v11 + (float)v14;
  }
  return result;
}


// ========================================================================
// ?RopeGen@@YAXAAUclothParms_t@@@Z
// EA  : 0x827AD988
// RVA : 0x007AD988
// PDB : w:\tech5\engine\models\cloth\jobs\clothgen.cpp
// ========================================================================

void __fastcall RopeGen(clothParms_t *clothParms)
{
  int i; // r30
  int v3; // r7
  const idVec3 *v4; // r4
  idClothParticle *cloth; // r8
  int v6; // r10
  float *p_x; // r11
  float v8; // r29
  float v9; // r28
  float v10; // r11
  double v11; // fp13
  float z; // r27
  float x; // r29
  float y; // r9
  int v15; // r30
  idVec3 *p_windDirection; // r5
  idVec3 *p_gravity; // r4
  int v18; // r8
  float *v19; // r10
  float *v20; // r11
  double v21; // fp12
  double v22; // fp9
  double v23; // fp6
  double v24; // fp1
  double v25; // fp13
  double v26; // fp7
  double v27; // fp11
  double v28; // fp13
  double v29; // fp0
  double c; // fp0
  double b; // fp13
  float *v32; // r10
  double a; // fp12
  float v34; // r6
  double v35; // fp8
  float v36; // r3
  double v37; // fp7
  double v38; // fp6
  double v39; // fp5
  double v40; // fp1
  double v41; // fp4
  double v42; // fp0
  int v43; // r8
  int v44; // r7
  double v45; // fp11
  double v46; // fp11
  float *v47; // r11
  double v48; // fp12
  double v49; // fp13
  int v50; // r6
  double v51; // fp7
  int v52; // r7
  idSphere *v53; // r10
  float *v54; // r11
  double v55; // fp13
  double v56; // fp12
  double v57; // fp0
  double v60; // fp2
  double v61; // fp0
  double v62; // fp4
  double v63; // fp11
  double v64; // fp13
  double v65; // fp12
  float *v66; // r11
  int numSprings; // r11
  int v68; // r30
  int v69; // r29
  double v70; // fp10
  int v71; // r5
  int v72; // r8
  idClothParticle *v73; // r9
  idClothSpring *v74; // r11
  int p1; // r10
  idClothParticle *v76; // r11
  float *v77; // r10
  float *v78; // r9
  double v79; // fp9
  double v80; // fp6
  double v83; // fp11
  double v84; // fp11
  double v85; // fp5
  double v86; // fp7
  double v87; // fp11
  double v88; // fp9
  double v89; // fp8
  idClothSpring *v90; // r9
  double v91; // fp0
  double v92; // fp12
  double v93; // fp12
  double v94; // fp13
  idClothParticle *v95; // r11
  int v96; // r29
  bool v97; // cr33
  float v98; // r8
  float v99; // r7
  float v100; // r6
  float v101; // r5
  float v102; // r4
  float v103; // r3
  float v104; // r10
  float v105; // r9
  float v106; // r11
  double v107; // fp25
  double v108; // fp26
  double v109; // fp27
  double v110; // fp12
  double v111; // fp13
  int v112; // r30
  double v113; // fp0
  double v114; // fp7
  double v115; // fp8
  double v116; // fp9
  idClothParticle *v117; // r11
  idClothParticle *v118; // r10
  double v119; // fp31
  double v120; // fp29
  double v121; // fp30
  double v124; // fp1
  double v125; // fp4
  double v126; // fp1
  double v127; // fp4
  double v128; // fp3
  double v129; // fp11
  double v130; // fp12
  double v131; // fp0
  long double v132; // fp2
  double v135; // fp4
  double v136; // fp7
  double v137; // fp4
  double v138; // fp0
  long double v139; // fp2
  float *v140; // r11
  double v141; // fp0
  double v142; // fp11
  double v143; // fp10
  double v144; // fp9
  double v147; // fp2
  double v148; // fp5
  double v149; // fp2
  double v150; // fp1
  double v151; // fp8
  double v152; // fp6
  double v153; // fp7
  double v156; // fp13
  double v157; // fp3
  float *v158; // r11
  int v159; // r10
  idClothParticle *v160; // r11
  float *bounds; // r5
  int v162; // r9
  float *v163; // r8
  idClothParticle *v164; // r11
  double v166; // fp11
  double v167; // fp10
  double v168; // fp9
  double v169; // fp8
  double v170; // fp7
  idVec3 v182; // [sp+50h] [-F0h] BYREF
  idVec3 v183; // [sp+60h] [-E0h] BYREF
  idVec3 v184; // [sp+70h] [-D0h] BYREF
  idMat3 v185; // [sp+80h] [-C0h] BYREF

  for ( i = 0; i < clothParms->numWeaponTraces; ++i )
  {
    v3 = 0;
    v4 = (const idVec3 *)(clothParms->numClothParticles - 1);
    if ( (int)v4 > 0 )
    {
      cloth = clothParms->cloth;
      v6 = 0;
      while ( 1 )
      {
        p_x = &cloth[v6].origin.x;
        if ( cloth[v6 + 1].anchored == 0 )
        {
          v8 = p_x[2];
          v9 = *p_x;
          v10 = p_x[1];
          v182.z = v8;
          v11 = v8;
          z = cloth[v6 + 2].origin.z;
          x = cloth[v6 + 2].origin.x;
          y = cloth[v6 + 2].origin.y;
          v182.y = v10;
          v182.x = v9;
          v183.z = z;
          v183.x = x;
          v183.y = y;
          v184.z = (float)(z + (float)v11) * (float)0.5;
          v184.y = (float)(y + v10) * (float)0.5;
          v184.x = (float)(v9 + x) * (float)0.5;
          if ( SphereLineIntersection(
                 origin: &v184,
                 radiusSqr: (float)((float)((float)(v9 - v184.x) * (float)(v9 - v184.x))
                       + (float)((float)((float)((float)v11 - v184.z) * (float)((float)v11 - v184.z))
                               + (float)((float)(v10 - v184.y) * (float)(v10 - v184.y)))),
                 start: v4,
                 end: &v182,
                 a5: &v183.x) )
          {
            break;
          }
        }
        v3 += 2;
        v6 += 2;
        if ( v3 >= (int)v4 )
          goto LABEL_9;
      }
      cloth->state |= 1u;
    }
LABEL_9:
    ;
  }
  v15 = 0;
  if ( clothParms->numClothParticles > 0 )
  {
    p_windDirection = &clothParms->windDirection;
    p_gravity = &clothParms->gravity;
    v18 = 0;
    do
    {
      v19 = (float *)((char *)&clothParms->cloth->origin.x + v18);
      v20 = v19 + 9;
      v21 = (float)(v19[9] + p_windDirection->x);
      v19[9] = v19[9] + p_windDirection->x;
      v22 = (float)(v19[10] + p_windDirection->y);
      v19[10] = v19[10] + p_windDirection->y;
      v23 = (float)(v19[11] + p_windDirection->z);
      v19[11] = v19[11] + p_windDirection->z;
      v24 = (float)((float)v21 + p_gravity->x);
      v19[9] = (float)v21 + p_gravity->x;
      v25 = (float)((float)v22 + p_gravity->y);
      v19[10] = (float)v22 + p_gravity->y;
      v26 = v25;
      v27 = (float)((float)v23 + p_gravity->z);
      v19[11] = (float)v23 + p_gravity->z;
      v28 = (float)((float)-v19[7] * clothParms->friction);
      v29 = (float)((float)-v19[8] * clothParms->friction);
      v19[9] = (float)((float)-v19[6] * clothParms->friction) + (float)v24;
      v19[10] = (float)v28 + (float)v26;
      v19[11] = (float)v29 + (float)v27;
      if ( clothParms->hasCollisionPlane )
      {
        c = clothParms->collisionPlane.c;
        b = clothParms->collisionPlane.b;
        v32 = (float *)((char *)&clothParms->cloth->origin.x + v18);
        a = clothParms->collisionPlane.a;
        if ( (float)((float)((float)(*v32 * clothParms->collisionPlane.a)
                           + (float)((float)(v32[1] * clothParms->collisionPlane.b)
                                   + (float)(v32[2] * clothParms->collisionPlane.c)))
                   + clothParms->collisionPlane.d) < 0.0000099999997 )
        {
          v34 = v32[6];
          v35 = -clothParms->collisionFriction;
          v36 = v32[7];
          v37 = *v20;
          v38 = v20[1];
          v39 = v20[2];
          v183.z = v32[8];
          v183.x = v34;
          v183.y = v36;
          v40 = (float)((float)((float)(v183.z * (float)c) + (float)((float)(v34 * (float)a) + (float)(v36 * (float)b)))
                      * (float)a);
          v41 = (float)(v36
                      - (float)((float)((float)(v183.z * (float)c)
                                      + (float)((float)(v34 * (float)a) + (float)(v36 * (float)b)))
                              * (float)b));
          v42 = (float)((float)(v183.z
                              - (float)((float)((float)(v183.z * (float)c)
                                              + (float)((float)(v34 * (float)a) + (float)(v36 * (float)b)))
                                      * (float)c))
                      * (float)v35);
          *v20 = (float)((float)v35 * (float)(v34 - (float)v40)) + (float)v37;
          v20[2] = (float)v42 + (float)v39;
          v20[1] = (float)((float)v41 * (float)v35) + (float)v38;
        }
      }
      idClothParticle::Simulate(
        this: (idClothParticle *)((char *)clothParms->cloth + v18),
        dt: clothParms->timeDelta,
        frictionFactor: clothParms->friction);
      if ( v44 != 0 )
      {
        v45 = (float)((float)((float)(*(float *)((char *)&clothParms->cloth->origin.x + v43)
                                    * clothParms->collisionPlane.a)
                            + (float)((float)(*(float *)((char *)&clothParms->cloth->origin.y + v43)
                                            * clothParms->collisionPlane.b)
                                    + (float)(*(float *)((char *)&clothParms->cloth->origin.z + v43)
                                            * clothParms->collisionPlane.c)))
                    + clothParms->collisionPlane.d);
        if ( v45 < 0.0 )
        {
          v46 = -v45;
          v47 = (float *)((char *)&clothParms->cloth->origin.x + v43);
          v48 = (float)(v47[2] + (float)((float)v46 * clothParms->collisionPlane.c));
          v49 = (float)(v47[1] + (float)((float)v46 * clothParms->collisionPlane.b));
          if ( *((_BYTE *)v47 + 92) == 0 )
          {
            *v47 = (float)((float)v46 * clothParms->collisionPlane.a) + *v47;
            v47[1] = v49;
            v47[2] = v48;
          }
        }
      }
      v50 = 0;
      if ( clothParms->numCollisions > 0 )
      {
        v51 = idMath::FLT_SMALLEST_NON_DENORMAL;
        v52 = 0;
        do
        {
          v53 = &clothParms->collisions[v52];
          v54 = (float *)((char *)&clothParms->cloth->origin.x + v43);
          v55 = (float)(v54[1] - v53->origin.y);
          v56 = (float)(v54[2] - v53->origin.z);
          v57 = (float)((float)((float)(*v54 - v53->origin.x) * (float)(*v54 - v53->origin.x))
                      + (float)((float)((float)v56 * (float)v56) + (float)((float)v55 * (float)v55)));
          if ( v57 < (float)(v53->radius * v53->radius) )
          {
            _FP6 = (float)((float)((float)((float)(*v54 - v53->origin.x) * (float)(*v54 - v53->origin.x))
                                 + (float)((float)((float)v56 * (float)v56) + (float)((float)v55 * (float)v55)))
                         - (float)v51);
            __asm { fsel      f3, f6, f0, f7 }
            v60 = __frsqrte(_FP3);
            v61 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60
                                                                                                * (float)((float)v57 * (float)0.5))
                                                                                        * (float)v60)
                                                                                - (float)1.5)
                                                                * (float)v60)
                                                        * (float)((float)v57 * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v60
                                                                                        * (float)((float)v57 * (float)0.5))
                                                                                * (float)v60)
                                                                        - (float)1.5)
                                                        * (float)v60))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)v57 * (float)0.5))
                                                        * (float)v60)
                                                - (float)1.5)
                                * (float)v60));
            v62 = (float)-(float)((float)((float)((float)v61
                                                * (float)((float)((float)((float)(*v54 - v53->origin.x)
                                                                        * (float)(*v54 - v53->origin.x))
                                                                + (float)((float)((float)v56 * (float)v56)
                                                                        + (float)((float)v55 * (float)v55)))
                                                        * (float)0.5))
                                        * (float)v61)
                                - (float)1.5);
            v63 = (float)((float)((float)((float)-(float)((float)((float)((float)v61
                                                                        * (float)((float)((float)((float)(*v54 - v53->origin.x)
                                                                                                * (float)(*v54 - v53->origin.x))
                                                                                        + (float)((float)((float)v56 * (float)v56)
                                                                                                + (float)((float)v55 * (float)v55)))
                                                                                * (float)0.5))
                                                                * (float)v61)
                                                        - (float)1.5)
                                        * (float)v61)
                                * (float)(*v54 - v53->origin.x))
                        * v53->radius);
            v64 = (float)((float)((float)((float)v55
                                        * (float)((float)-(float)((float)((float)((float)v61
                                                                                * (float)((float)((float)((float)(*v54 - v53->origin.x) * (float)(*v54 - v53->origin.x))
                                                                                                + (float)((float)((float)v56 * (float)v56) + (float)((float)v55 * (float)v55)))
                                                                                        * (float)0.5))
                                                                        * (float)v61)
                                                                - (float)1.5)
                                                * (float)v61))
                                * v53->radius)
                        + v53->origin.y);
            v65 = (float)((float)((float)((float)(v54[2] - v53->origin.z) * (float)((float)v62 * (float)v61))
                                * v53->radius)
                        + v53->origin.z);
            if ( *((_BYTE *)v54 + 92) == 0 )
            {
              *v54 = (float)v63 + v53->origin.x;
              v54[1] = v64;
              v54[2] = v65;
              v51 = idMath::FLT_SMALLEST_NON_DENORMAL;
            }
          }
          ++v50;
          ++v52;
        }
        while ( v50 < clothParms->numCollisions );
      }
      ++v15;
      v66 = (float *)((char *)&clothParms->cloth->origin.x + v43);
      v18 = v43 + 96;
      v66[9] = 0.0;
      v66[11] = 0.0;
      v66[10] = 0.0;
    }
    while ( v15 < clothParms->numClothParticles );
  }
  numSprings = clothParms->numSprings;
  v68 = 0;
  if ( numSprings > 0 )
  {
    v69 = 0;
    do
    {
      idClothSpring::Constrain2(this: &clothParms->springs[v69], cloth: clothParms->cloth);
      numSprings = clothParms->numSprings;
      ++v68;
      ++v69;
    }
    while ( v68 < numSprings );
  }
  v70 = idMath::FLT_SMALLEST_NON_DENORMAL;
  v71 = 0;
  if ( numSprings > 0 )
  {
    v72 = 0;
    do
    {
      if ( clothParms->springs[v72].p1 - clothParms->springs[v72].p2 != 1 )
      {
        v73 = clothParms->cloth;
        v74 = &clothParms->springs[v72];
        p1 = v74->p1;
        v76 = &v73[v74->p2];
        v77 = &v73[p1].origin.x;
        if ( v76->anchored != 0 )
        {
          v78 = v77;
          v77 = &v76->origin.x;
          v76 = (idClothParticle *)v78;
        }
        v79 = (float)(v77[1] - v76->origin.y);
        v80 = (float)(v77[2] - v76->origin.z);
        _FP5 = (float)((float)((float)((float)(*v77 - v76->origin.x) * (float)(*v77 - v76->origin.x))
                             + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79)))
                     - (float)v70);
        __asm { fsel      f2, f5, f7, f10 }
        v83 = __frsqrte(_FP2);
        v84 = (float)((float)-(float)((float)((float)((float)v83
                                                    * (float)((float)((float)((float)(*v77 - v76->origin.x)
                                                                            * (float)(*v77 - v76->origin.x))
                                                                    + (float)((float)((float)v80 * (float)v80)
                                                                            + (float)((float)v79 * (float)v79)))
                                                            * (float)0.5))
                                            * (float)v83)
                                    - (float)1.5)
                    * (float)v83);
        v85 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v84
                                                                                            * (float)((float)((float)((float)(*v77 - v76->origin.x) * (float)(*v77 - v76->origin.x)) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))) * (float)0.5))
                                                                                    * (float)v84)
                                                                            - (float)1.5)
                                                            * (float)v84)
                                                    * (float)((float)((float)((float)(*v77 - v76->origin.x)
                                                                            * (float)(*v77 - v76->origin.x))
                                                                    + (float)((float)((float)v80 * (float)v80)
                                                                            + (float)((float)v79 * (float)v79)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v84
                                                                                    * (float)((float)((float)((float)(*v77 - v76->origin.x) * (float)(*v77 - v76->origin.x)) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79)))
                                                                                            * (float)0.5))
                                                                            * (float)v84)
                                                                    - (float)1.5)
                                                    * (float)v84))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v84
                                                            * (float)((float)((float)((float)(*v77 - v76->origin.x)
                                                                                    * (float)(*v77 - v76->origin.x))
                                                                            + (float)((float)((float)v80 * (float)v80)
                                                                                    + (float)((float)v79 * (float)v79)))
                                                                    * (float)0.5))
                                                    * (float)v84)
                                            - (float)1.5)
                            * (float)v84));
        v86 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v84 * (float)((float)((float)((float)(*v77 - v76->origin.x) * (float)(*v77 - v76->origin.x)) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))) * (float)0.5))
                                                                                            * (float)v84)
                                                                                    - (float)1.5)
                                                                    * (float)v84)
                                                            * (float)((float)((float)((float)(*v77 - v76->origin.x)
                                                                                    * (float)(*v77 - v76->origin.x))
                                                                            + (float)((float)((float)v80 * (float)v80)
                                                                                    + (float)((float)v79 * (float)v79)))
                                                                    * (float)0.5))
                                                    * (float)((float)-(float)((float)((float)((float)v84
                                                                                            * (float)((float)((float)((float)(*v77 - v76->origin.x) * (float)(*v77 - v76->origin.x)) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))) * (float)0.5))
                                                                                    * (float)v84)
                                                                            - (float)1.5)
                                                            * (float)v84))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v84
                                                                    * (float)((float)((float)((float)(*v77 - v76->origin.x)
                                                                                            * (float)(*v77 - v76->origin.x))
                                                                                    + (float)((float)((float)v80 * (float)v80)
                                                                                            + (float)((float)v79 * (float)v79)))
                                                                            * (float)0.5))
                                                            * (float)v84)
                                                    - (float)1.5)
                                    * (float)v84))
                    * (float)((float)((float)(*v77 - v76->origin.x) * (float)(*v77 - v76->origin.x))
                            + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))));
        v87 = (float)((float)(*v77 - v76->origin.x)
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v84 * (float)((float)((float)((float)(*v77 - v76->origin.x) * (float)(*v77 - v76->origin.x)) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))) * (float)0.5))
                                                                                            * (float)v84)
                                                                                    - (float)1.5)
                                                                    * (float)v84)
                                                            * (float)((float)((float)((float)(*v77 - v76->origin.x)
                                                                                    * (float)(*v77 - v76->origin.x))
                                                                            + (float)((float)((float)v80 * (float)v80)
                                                                                    + (float)((float)v79 * (float)v79)))
                                                                    * (float)0.5))
                                                    * (float)((float)-(float)((float)((float)((float)v84
                                                                                            * (float)((float)((float)((float)(*v77 - v76->origin.x) * (float)(*v77 - v76->origin.x)) + (float)((float)((float)v80 * (float)v80) + (float)((float)v79 * (float)v79))) * (float)0.5))
                                                                                    * (float)v84)
                                                                            - (float)1.5)
                                                            * (float)v84))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v84
                                                                    * (float)((float)((float)((float)(*v77 - v76->origin.x)
                                                                                            * (float)(*v77 - v76->origin.x))
                                                                                    + (float)((float)((float)v80 * (float)v80)
                                                                                            + (float)((float)v79 * (float)v79)))
                                                                            * (float)0.5))
                                                            * (float)v84)
                                                    - (float)1.5)
                                    * (float)v84)));
        v88 = (float)((float)(v77[1] - v76->origin.y) * (float)v85);
        v89 = (float)((float)(v77[2] - v76->origin.z) * (float)v85);
        if ( v86 > (float)(clothParms->springs[v72].maxLengthMultiplier * clothParms->springs[v72].springLength) )
        {
          v90 = &clothParms->springs[v72];
          v91 = (float)(*v77 - (float)((float)(v90->springLength * (float)v87) * v90->maxLengthMultiplier));
          v92 = (float)(v77[2]
                      - (float)((float)((float)((float)(v77[2] - v76->origin.z) * (float)v85) * v90->springLength)
                              * v90->maxLengthMultiplier));
          if ( v76->anchored == 0 )
          {
            v76->origin.y = v77[1]
                          - (float)((float)((float)((float)(v77[1] - v76->origin.y) * (float)v85) * v90->springLength)
                                  * v90->maxLengthMultiplier);
            v76->origin.x = v91;
            v76->origin.z = v92;
            v70 = idMath::FLT_SMALLEST_NON_DENORMAL;
          }
        }
        if ( v86 < clothParms->springs[v72].springLength )
        {
          v93 = (float)(v77[2] - (float)((float)v89 * clothParms->springs[v72].springLength));
          v94 = (float)(v77[1] - (float)((float)v88 * clothParms->springs[v72].springLength));
          if ( v76->anchored == 0 )
          {
            v76->origin.x = *v77 - (float)(clothParms->springs[v72].springLength * (float)v87);
            v76->origin.y = v94;
            v76->origin.z = v93;
            v70 = idMath::FLT_SMALLEST_NON_DENORMAL;
          }
        }
      }
      ++v71;
      ++v72;
    }
    while ( v71 < clothParms->numSprings );
  }
  v95 = clothParms->cloth;
  v96 = 0;
  v97 = clothParms->numClothParticles - 1 > 0;
  v98 = v95->axis.mat[0].x;
  v99 = v95->axis.mat[0].y;
  v100 = v95->axis.mat[0].z;
  v101 = v95->axis.mat[1].x;
  v102 = v95->axis.mat[1].y;
  v103 = v95->axis.mat[1].z;
  v104 = v95->axis.mat[2].x;
  v105 = v95->axis.mat[2].y;
  v106 = v95->axis.mat[2].z;
  v183.x = v98;
  v183.y = v99;
  v183.z = v100;
  v182.x = v101;
  v182.y = v102;
  v182.z = v103;
  v184.x = v104;
  v184.y = v105;
  v184.z = v106;
  if ( v97 )
  {
    v107 = v183.z;
    v108 = v183.y;
    v109 = v183.x;
    v110 = v182.z;
    v111 = v182.y;
    v112 = 0;
    v113 = v182.x;
    v114 = v184.z;
    v115 = v184.y;
    v116 = v184.x;
    do
    {
      v117 = &clothParms->cloth[v112];
      if ( v117[1].anchored == 0 )
      {
        v118 = &clothParms->cloth[v112];
        v119 = (float)(v118[1].origin.x - v118->origin.x);
        v184.x = v118[1].origin.x - v118->origin.x;
        v120 = (float)(v118[1].origin.z - v118->origin.z);
        v184.z = v118[1].origin.z - v118->origin.z;
        v121 = (float)(v118[1].origin.y - v118->origin.y);
        v184.y = v118[1].origin.y - v118->origin.y;
        if ( ((LODWORD(v184.y) | LODWORD(v184.z) | LODWORD(v184.x)) & 0x7FFFFFFF) != 0 )
        {
          _FP4 = (float)((float)((float)((float)v121 * (float)v121)
                               + (float)((float)((float)v119 * (float)v119) + (float)((float)v120 * (float)v120)))
                       - (float)v70);
          __asm { fsel      f2, f4, f5, f10 }
          v124 = __frsqrte(_FP2);
          v125 = (float)((float)-(float)((float)((float)((float)v124
                                                       * (float)((float)((float)((float)v121 * (float)v121)
                                                                       + (float)((float)((float)v119 * (float)v119)
                                                                               + (float)((float)v120 * (float)v120)))
                                                               * (float)0.5))
                                               * (float)v124)
                                       - (float)1.5)
                       * (float)v124);
          v126 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v124
                                                                                       * (float)((float)((float)((float)v121 * (float)v121) + (float)((float)((float)v119 * (float)v119) + (float)((float)v120 * (float)v120)))
                                                                                               * (float)0.5))
                                                                               * (float)v124)
                                                                       - (float)1.5)
                                                       * (float)v124)
                                               * (float)((float)((float)((float)v121 * (float)v121)
                                                               + (float)((float)((float)v119 * (float)v119)
                                                                       + (float)((float)v120 * (float)v120)))
                                                       * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v124
                                                                               * (float)((float)((float)((float)v121 * (float)v121)
                                                                                               + (float)((float)((float)v119 * (float)v119) + (float)((float)v120 * (float)v120)))
                                                                                       * (float)0.5))
                                                                       * (float)v124)
                                                               - (float)1.5)
                                               * (float)v124))
                               - (float)1.5);
          v127 = (float)((float)-(float)((float)((float)((float)((float)v126 * (float)v125)
                                                       * (float)((float)((float)((float)v121 * (float)v121)
                                                                       + (float)((float)((float)v119 * (float)v119)
                                                                               + (float)((float)v120 * (float)v120)))
                                                               * (float)0.5))
                                               * (float)((float)v126 * (float)v125))
                                       - (float)1.5)
                       * (float)((float)v126 * (float)v125));
          v119 = (float)((float)v127 * (float)v119);
          v121 = (float)((float)v121 * (float)v127);
          v120 = (float)((float)v120 * (float)v127);
        }
        v128 = (float)((float)((float)v113 * (float)v119) + (float)((float)v110 * (float)v120));
        v129 = (float)((float)((float)v111 * (float)v120) - (float)((float)v110 * (float)v121));
        v130 = (float)((float)((float)v110 * (float)v119) - (float)((float)v120 * (float)v113));
        v131 = (float)((float)((float)v121 * (float)v113) - (float)((float)v111 * (float)v119));
        *(double *)&v132 = (float)((float)((float)v111 * (float)v121) + (float)v128);
        if ( *(double *)&v132 <= 0.99998999 )
        {
          if ( *(double *)&v132 >= -0.99998999 )
          {
            _FP7 = (float)((float)((float)((float)v130 * (float)v130)
                                 + (float)((float)((float)v129 * (float)v129) + (float)((float)v131 * (float)v131)))
                         - (float)v70);
            __asm { fsel      f5, f7, f8, f10 }
            v135 = __frsqrte(_FP5);
            v136 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v135
                                                                                                 * (float)((float)((float)((float)v130 * (float)v130) + (float)((float)((float)v129 * (float)v129) + (float)((float)v131 * (float)v131))) * (float)0.5))
                                                                                         * (float)v135)
                                                                                 - (float)1.5)
                                                                 * (float)v135)
                                                         * (float)((float)((float)((float)v130 * (float)v130)
                                                                         + (float)((float)((float)v129 * (float)v129)
                                                                                 + (float)((float)v131 * (float)v131)))
                                                                 * (float)0.5))
                                                 * (float)((float)-(float)((float)((float)((float)v135
                                                                                         * (float)((float)((float)((float)v130 * (float)v130) + (float)((float)((float)v129 * (float)v129) + (float)((float)v131 * (float)v131)))
                                                                                                 * (float)0.5))
                                                                                 * (float)v135)
                                                                         - (float)1.5)
                                                         * (float)v135))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v135
                                                                 * (float)((float)((float)((float)v130 * (float)v130)
                                                                                 + (float)((float)((float)v129
                                                                                                 * (float)v129)
                                                                                         + (float)((float)v131
                                                                                                 * (float)v131)))
                                                                         * (float)0.5))
                                                         * (float)v135)
                                                 - (float)1.5)
                                 * (float)v135));
            v137 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v135 * (float)((float)((float)((float)v130 * (float)v130) + (float)((float)((float)v129 * (float)v129) + (float)((float)v131 * (float)v131))) * (float)0.5)) * (float)v135) - (float)1.5) * (float)v135)
                                                                                                 * (float)((float)((float)((float)v130 * (float)v130) + (float)((float)((float)v129 * (float)v129) + (float)((float)v131 * (float)v131))) * (float)0.5))
                                                                                         * (float)((float)-(float)((float)((float)((float)v135 * (float)((float)((float)((float)v130 * (float)v130) + (float)((float)((float)v129 * (float)v129) + (float)((float)v131 * (float)v131))) * (float)0.5)) * (float)v135) - (float)1.5)
                                                                                                 * (float)v135))
                                                                                 - (float)1.5)
                                                                 * (float)((float)-(float)((float)((float)((float)v135 * (float)((float)((float)((float)v130 * (float)v130) + (float)((float)((float)v129 * (float)v129) + (float)((float)v131 * (float)v131))) * (float)0.5))
                                                                                                 * (float)v135)
                                                                                         - (float)1.5)
                                                                         * (float)v135))
                                                         * (float)((float)((float)((float)v130 * (float)v130)
                                                                         + (float)((float)((float)v129 * (float)v129)
                                                                                 + (float)((float)v131 * (float)v131)))
                                                                 * (float)0.5))
                                                 * (float)v136)
                                         - (float)1.5)
                         * (float)v136);
            v183.x = (float)v137 * (float)v129;
            v183.y = (float)v130 * (float)v137;
            v183.z = (float)v131 * (float)v137;
            if ( *(double *)&v132 > -1.0 )
            {
              if ( *(double *)&v132 < 1.0 )
              {
                *((double *)&v132 + 1) = (float)((float)v130 * (float)v137);
                v139 = acos(x: v132);
                v138 = (float)*(double *)&v139;
              }
              else
              {
                v138 = 0.0;
              }
            }
            else
            {
              v138 = 3.1415927;
            }
            MakeRotationMat(axis: &v185, rotationVec: &v183, angle: -v138);
            v140 = &clothParms->cloth[v112].origin.x;
            v141 = idMath::FLT_SMALLEST_NON_DENORMAL;
            v142 = (float)((float)(v185.mat[1].z * (float)v108)
                         + (float)((float)(v185.mat[0].z * (float)v109) + (float)(v185.mat[2].z * (float)v107)));
            v143 = (float)((float)(v185.mat[1].x * (float)v108)
                         + (float)((float)(v185.mat[0].x * (float)v109) + (float)(v185.mat[2].x * (float)v107)));
            v144 = (float)((float)(v185.mat[1].y * (float)v108)
                         + (float)((float)(v185.mat[0].y * (float)v109) + (float)(v185.mat[2].y * (float)v107)));
            _FP5 = (float)((float)((float)((float)v144 * (float)v144)
                                 + (float)((float)((float)v143 * (float)v143) + (float)((float)v142 * (float)v142)))
                         - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f3, f5, f6, f0 }
            v147 = __frsqrte(_FP3);
            v148 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v147
                                                                                                 * (float)((float)((float)((float)v144 * (float)v144) + (float)((float)((float)v143 * (float)v143) + (float)((float)v142 * (float)v142))) * (float)0.5))
                                                                                         * (float)v147)
                                                                                 - (float)1.5)
                                                                 * (float)v147)
                                                         * (float)((float)((float)((float)v144 * (float)v144)
                                                                         + (float)((float)((float)v143 * (float)v143)
                                                                                 + (float)((float)v142 * (float)v142)))
                                                                 * (float)0.5))
                                                 * (float)((float)-(float)((float)((float)((float)v147
                                                                                         * (float)((float)((float)((float)v144 * (float)v144) + (float)((float)((float)v143 * (float)v143) + (float)((float)v142 * (float)v142)))
                                                                                                 * (float)0.5))
                                                                                 * (float)v147)
                                                                         - (float)1.5)
                                                         * (float)v147))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v147
                                                                 * (float)((float)((float)((float)v144 * (float)v144)
                                                                                 + (float)((float)((float)v143
                                                                                                 * (float)v143)
                                                                                         + (float)((float)v142
                                                                                                 * (float)v142)))
                                                                         * (float)0.5))
                                                         * (float)v147)
                                                 - (float)1.5)
                                 * (float)v147));
            v149 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v147 * (float)((float)((float)((float)v144 * (float)v144) + (float)((float)((float)v143 * (float)v143) + (float)((float)v142 * (float)v142))) * (float)0.5)) * (float)v147) - (float)1.5) * (float)v147)
                                                                                                 * (float)((float)((float)((float)v144 * (float)v144) + (float)((float)((float)v143 * (float)v143) + (float)((float)v142 * (float)v142))) * (float)0.5))
                                                                                         * (float)((float)-(float)((float)((float)((float)v147 * (float)((float)((float)((float)v144 * (float)v144) + (float)((float)((float)v143 * (float)v143) + (float)((float)v142 * (float)v142))) * (float)0.5)) * (float)v147) - (float)1.5)
                                                                                                 * (float)v147))
                                                                                 - (float)1.5)
                                                                 * (float)((float)-(float)((float)((float)((float)v147 * (float)((float)((float)((float)v144 * (float)v144) + (float)((float)((float)v143 * (float)v143) + (float)((float)v142 * (float)v142))) * (float)0.5))
                                                                                                 * (float)v147)
                                                                                         - (float)1.5)
                                                                         * (float)v147))
                                                         * (float)((float)((float)((float)v144 * (float)v144)
                                                                         + (float)((float)((float)v143 * (float)v143)
                                                                                 + (float)((float)v142 * (float)v142)))
                                                                 * (float)0.5))
                                                 * (float)v148)
                                         - (float)1.5)
                         * (float)v148);
            v150 = (float)((float)((float)(v185.mat[1].y * (float)v108)
                                 + (float)((float)(v185.mat[0].y * (float)v109) + (float)(v185.mat[2].y * (float)v107)))
                         * (float)v149);
            v140[13] = (float)((float)(v185.mat[1].y * (float)v108)
                             + (float)((float)(v185.mat[0].y * (float)v109) + (float)(v185.mat[2].y * (float)v107)))
                     * (float)v149;
            v140[14] = (float)v142 * (float)v149;
            v140[12] = (float)v143 * (float)v149;
            v140[15] = v119;
            v140[16] = v121;
            v140[17] = v120;
            v151 = (float)((float)((float)v121 * (float)((float)v143 * (float)v149)) - (float)((float)v150 * (float)v119));
            v152 = (float)((float)((float)v150 * (float)v120) - (float)((float)((float)v142 * (float)v149) * (float)v121));
            v153 = (float)((float)((float)((float)v142 * (float)v149) * (float)v119)
                         - (float)((float)v120 * (float)((float)v143 * (float)v149)));
            _FP2 = (float)((float)((float)((float)v153 * (float)v153)
                                 + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151)))
                         - (float)v141);
            __asm { fsel      f0, f2, f3, f0 }
            v156 = __frsqrte(_FP0);
            v157 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v156
                                                                                                 * (float)((float)((float)((float)v153 * (float)v153) + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151))) * (float)0.5))
                                                                                         * (float)v156)
                                                                                 - (float)1.5)
                                                                 * (float)v156)
                                                         * (float)((float)((float)((float)v153 * (float)v153)
                                                                         + (float)((float)((float)v152 * (float)v152)
                                                                                 + (float)((float)v151 * (float)v151)))
                                                                 * (float)0.5))
                                                 * (float)((float)-(float)((float)((float)((float)v156
                                                                                         * (float)((float)((float)((float)v153 * (float)v153) + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151)))
                                                                                                 * (float)0.5))
                                                                                 * (float)v156)
                                                                         - (float)1.5)
                                                         * (float)v156))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v156
                                                                 * (float)((float)((float)((float)v153 * (float)v153)
                                                                                 + (float)((float)((float)v152
                                                                                                 * (float)v152)
                                                                                         + (float)((float)v151
                                                                                                 * (float)v151)))
                                                                         * (float)0.5))
                                                         * (float)v156)
                                                 - (float)1.5)
                                 * (float)v156));
            v140[18] = (float)v152
                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v156 * (float)((float)((float)((float)v153 * (float)v153) + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151))) * (float)0.5)) * (float)v156) - (float)1.5) * (float)v156) * (float)((float)((float)((float)v153 * (float)v153) + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v156 * (float)((float)((float)((float)v153 * (float)v153) + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151))) * (float)0.5)) * (float)v156) - (float)1.5) * (float)v156))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v156 * (float)((float)((float)((float)v153 * (float)v153) + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151))) * (float)0.5)) * (float)v156)
                                                                                             - (float)1.5)
                                                                             * (float)v156))
                                                             * (float)((float)((float)((float)v153 * (float)v153)
                                                                             + (float)((float)((float)v152 * (float)v152)
                                                                                     + (float)((float)v151 * (float)v151)))
                                                                     * (float)0.5))
                                                     * (float)v157)
                                             - (float)1.5)
                             * (float)v157);
            v140[19] = (float)v153
                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v156 * (float)((float)((float)((float)v153 * (float)v153) + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151))) * (float)0.5)) * (float)v156) - (float)1.5) * (float)v156) * (float)((float)((float)((float)v153 * (float)v153) + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v156 * (float)((float)((float)((float)v153 * (float)v153) + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151))) * (float)0.5)) * (float)v156) - (float)1.5) * (float)v156))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v156 * (float)((float)((float)((float)v153 * (float)v153) + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151))) * (float)0.5)) * (float)v156)
                                                                                             - (float)1.5)
                                                                             * (float)v156))
                                                             * (float)((float)((float)((float)v153 * (float)v153)
                                                                             + (float)((float)((float)v152 * (float)v152)
                                                                                     + (float)((float)v151 * (float)v151)))
                                                                     * (float)0.5))
                                                     * (float)v157)
                                             - (float)1.5)
                             * (float)v157);
            v140[20] = (float)v151
                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v156 * (float)((float)((float)((float)v153 * (float)v153) + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151))) * (float)0.5)) * (float)v156) - (float)1.5) * (float)v156) * (float)((float)((float)((float)v153 * (float)v153) + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v156 * (float)((float)((float)((float)v153 * (float)v153) + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151))) * (float)0.5)) * (float)v156) - (float)1.5) * (float)v156))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v156 * (float)((float)((float)((float)v153 * (float)v153) + (float)((float)((float)v152 * (float)v152) + (float)((float)v151 * (float)v151))) * (float)0.5)) * (float)v156)
                                                                                             - (float)1.5)
                                                                             * (float)v156))
                                                             * (float)((float)((float)((float)v153 * (float)v153)
                                                                             + (float)((float)((float)v152 * (float)v152)
                                                                                     + (float)((float)v151 * (float)v151)))
                                                                     * (float)0.5))
                                                     * (float)v157)
                                             - (float)1.5)
                             * (float)v157);
          }
          else
          {
            v117->axis.mat[0].x = v109;
            v117->axis.mat[1].x = v119;
            v117->axis.mat[0].y = v108;
            v117->axis.mat[0].z = v107;
            v117->axis.mat[1].y = v121;
            v117->axis.mat[1].z = v120;
            v117->axis.mat[2].x = -v116;
            v117->axis.mat[2].y = -v115;
            v117->axis.mat[2].z = -v114;
          }
        }
        else
        {
          v117->axis.mat[0].x = v109;
          v117->axis.mat[1].x = v119;
          v117->axis.mat[0].y = v108;
          v117->axis.mat[0].z = v107;
          v117->axis.mat[1].y = v121;
          v117->axis.mat[1].z = v120;
          v117->axis.mat[2].x = v116;
          v117->axis.mat[2].y = v115;
          v117->axis.mat[2].z = v114;
        }
        v70 = idMath::FLT_SMALLEST_NON_DENORMAL;
        v158 = &clothParms->cloth[v112].origin.x;
        v109 = v158[12];
        v108 = v158[13];
        v107 = v158[14];
        v113 = v158[15];
        v111 = v158[16];
        v110 = v158[17];
        v116 = v158[18];
        v115 = v158[19];
        v114 = v158[20];
      }
      ++v96;
      ++v112;
    }
    while ( v96 < clothParms->numClothParticles - 1 );
  }
  v159 = 0;
  v160 = &clothParms->cloth[clothParms->numClothParticles];
  v160[-1].axis.mat[0].x = v160[-2].axis.mat[0].x;
  v160[-1].axis.mat[0].y = v160[-2].axis.mat[0].y;
  v160[-1].axis.mat[0].z = v160[-2].axis.mat[0].z;
  v160[-1].axis.mat[1].x = v160[-2].axis.mat[1].x;
  v160[-1].axis.mat[1].y = v160[-2].axis.mat[1].y;
  v160[-1].axis.mat[1].z = v160[-2].axis.mat[1].z;
  v160[-1].axis.mat[2].x = v160[-2].axis.mat[2].x;
  v160[-1].axis.mat[2].y = v160[-2].axis.mat[2].y;
  v160[-1].axis.mat[2].z = v160[-2].axis.mat[2].z;
  bounds = (float *)clothParms->bounds;
  bounds[2] = 1.0e30;
  bounds[1] = 1.0e30;
  *bounds = 1.0e30;
  bounds[5] = -1.0e30;
  bounds[4] = -1.0e30;
  bounds[3] = -1.0e30;
  if ( clothParms->numClothParticles > 0 )
  {
    v162 = 0;
    do
    {
      ++v159;
      v163 = (float *)clothParms->bounds;
      v164 = &clothParms->cloth[v162++];
      _FP12 = (float)(*v163 - v164->origin.x);
      v166 = v163[1];
      v167 = v163[2];
      v168 = v163[3];
      v169 = v163[4];
      v170 = v163[5];
      __asm { fsel      f6, f12, f13, f0 }
      *v163 = _FP6;
      _FP4 = (float)((float)v166 - v164->origin.y);
      __asm { fsel      f3, f4, f5, f11 }
      v163[1] = _FP3;
      _FP1 = (float)((float)v167 - v164->origin.z);
      __asm { fsel      f0, f1, f2, f10 }
      v163[2] = _FP0;
      _FP12 = (float)(v164->origin.x - (float)v168);
      __asm { fsel      f11, f12, f13, f9 }
      v163[3] = _FP11;
      _FP9 = (float)(v164->origin.y - (float)v169);
      __asm { fsel      f8, f9, f10, f8 }
      v163[4] = _FP8;
      _FP5 = (float)(v164->origin.z - (float)v170);
      __asm { fsel      f4, f5, f6, f7 }
      v163[5] = _FP4;
    }
    while ( v159 < clothParms->numClothParticles );
  }
}


// ========================================================================
// ?ClothGenJob@@YAXAAUclothParms_t@@@Z
// EA  : 0x827AE590
// RVA : 0x007AE590
// PDB : w:\tech5\engine\models\cloth\jobs\clothgen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall ClothGenJob(clothParms_t *clothParms, int numClothParticles, int a3, int a4, __int64 a5)
{
  float x; // r24
  clothType_t type; // r11
  double z; // fp2
  double v9; // fp1
  float y; // r23
  double v11; // fp31
  float v12; // r22
  double v13; // fp30
  double v15; // fp28
  double v16; // fp21
  double v17; // fp27
  double v18; // fp26
  double v19; // fp25
  double v20; // fp24
  double friction; // fp13
  char v22; // r25
  int v23; // r29
  int v24; // r6
  clothWeaponTrace_t *v25; // r11
  double v26; // fp4
  double v27; // fp3
  int v28; // r9
  double v29; // fp10
  double v30; // fp9
  double v31; // fp8
  double v32; // fp7
  double v33; // fp6
  double v34; // fp5
  idClothParticle *cloth; // r5
  int v36; // r8
  float *p_x; // r11
  double v38; // fp13
  double v39; // fp0
  double v40; // fp12
  double v41; // fp11
  double v42; // fp11
  double v43; // fp13
  double v44; // fp0
  double v45; // fp0
  double v46; // fp13
  double v47; // fp12
  double v48; // fp11
  double v49; // fp11
  double v50; // fp13
  double v51; // fp0
  int v52; // r10
  idClothParticle *v53; // r11
  double v54; // fp0
  double v55; // fp13
  double v56; // fp12
  double v57; // fp11
  double v58; // fp11
  double v59; // fp13
  double v60; // fp0
  double v61; // fp13
  double v62; // fp0
  double v63; // fp12
  double v64; // fp11
  double v65; // fp11
  double v66; // fp13
  double v67; // fp0
  idClothParticle *v68; // r8
  int v69; // r10
  int v70; // ctr
  double v71; // fp13
  double v72; // fp0
  double v73; // fp12
  double v74; // fp11
  double v75; // fp11
  double v76; // fp13
  double v77; // fp0
  float *v78; // r11
  double v79; // fp12
  double v80; // fp11
  double v81; // fp9
  double v82; // fp8
  int numIterations; // r11
  int v84; // r26
  double v85; // fp30
  int v86; // r28
  int v87; // r30
  idClothParticle *v88; // r11
  double v89; // fp13
  float *v90; // r11
  double v91; // fp11
  double v92; // fp10
  double v93; // fp5
  double v94; // fp3
  double v95; // fp13
  double v96; // fp0
  double v97; // fp12
  int v98; // r29
  int v99; // r30
  int v100; // r30
  int v101; // r11
  int v102; // r5
  double v103; // fp31
  int v104; // r6
  int v105; // r6
  int v106; // r9
  int v107; // r10
  idClothParticle *v108; // r11
  idClothParticle *v109; // r11
  float *bounds; // r10
  int v111; // r25
  int v112; // r9
  float *v113; // r11
  float *v114; // r6
  double v115; // fp0
  double v116; // fp2
  double v117; // fp13
  double v118; // fp11
  double v119; // fp5
  double v122; // fp9
  double v124; // fp6
  idDrawVert *vertices; // r24
  int v135; // r29
  __int64 v136; // r11
  __int128 v137; // r7
  double v138; // fp5
  double v139; // fp4
  double v140; // fp2
  int v141; // r28
  int v142; // r27
  double v146; // fp13
  double v147; // fp6
  idClothParticle *v148; // r30
  int v149; // ctr
  int v150; // r3
  float *v152; // r10
  float *v153; // r8
  float *v154; // r9
  float *v155; // r7
  double v156; // fp26
  double v157; // fp25
  double v158; // fp7
  double v159; // fp1
  double v160; // fp30
  double v165; // fp9
  double v166; // fp8
  double v167; // fp9
  double v168; // fp8
  double v169; // fp9
  double v170; // fp8
  double v171; // fp28
  double v172; // fp27
  double v173; // fp31
  double v174; // fp30
  double v175; // fp1
  double v187; // fp7
  double v188; // fp9
  double v189; // fp7
  double v190; // fp9
  double v191; // fp8
  double v194; // fp28
  char v195; // r10
  double v196; // fp27
  double v197; // fp25
  double v198; // fp28
  double v199; // fp24
  double v201; // fp28
  double v203; // fp23
  double v204; // fp28
  double v205; // fp8
  double v206; // fp7
  double v207; // fp9
  double v208; // fp28
  double v209; // fp28
  double v210; // fp26
  double v211; // fp27
  double v212; // fp28
  double v213; // fp25
  double v214; // fp24
  double hSpacing; // fp2
  __int64 height; // r27
  double v217; // fp4
  double v218; // fp3
  double vSpacing; // fp1
  int v224; // r28
  double v225; // fp13
  double v226; // fp6
  double v227; // fp9
  idClothParticle *v228; // r9
  __int64 v229; // r8
  int v230; // ctr
  int v231; // r30
  double v232; // fp5
  float *v235; // r8
  double v236; // fp9
  float *v237; // r7
  float *v238; // r6
  double v239; // fp7
  double v240; // fp31
  double v241; // fp30
  double v242; // fp27
  double v247; // fp28
  double v248; // fp26
  double v249; // fp28
  double v250; // fp26
  double v251; // fp28
  double v252; // fp26
  double v253; // fp28
  double v254; // fp24
  double v255; // fp23
  double v256; // fp28
  double v257; // fp8
  int v266; // r6
  double v267; // fp7
  int v268; // r6
  double v269; // fp8
  double v270; // fp8
  double v271; // fp9
  double v272; // fp7
  double v275; // fp26
  double v276; // fp31
  double v277; // fp30
  double v278; // fp27
  double v279; // fp31
  double v282; // fp31
  double v283; // fp25
  double v284; // fp31
  double v285; // fp7
  double v286; // fp9
  double v287; // fp8
  double v288; // fp25
  double v289; // fp31
  double v290; // fp30
  double v291; // fp27
  double v292; // fp31
  double v293; // fp25
  int v294; // ctr
  __int64 v299; // [sp+50h] [-1180h] BYREF
  float v300; // [sp+58h] [-1178h] BYREF
  float v301; // [sp+5Ch] [-1174h] BYREF
  float v302; // [sp+60h] [-1170h] BYREF
  __int64 v303; // [sp+68h] [-1168h]
  __int64 v304; // [sp+70h] [-1160h]
  __int64 v305; // [sp+78h] [-1158h] BYREF
  float v306; // [sp+80h] [-1150h] BYREF
  __int64 v307; // [sp+88h] [-1148h] BYREF
  float v308; // [sp+90h] [-1140h] BYREF
  float v309; // [sp+98h] [-1138h] BYREF
  float v310; // [sp+9Ch] [-1134h] BYREF
  float v311; // [sp+A0h] [-1130h] BYREF
  __int64 v312; // [sp+A8h] [-1128h]
  __int64 v313; // [sp+B0h] [-1120h]
  __int64 v314; // [sp+B8h] [-1118h]
  float v315[12]; // [sp+C0h] [-1110h] BYREF
  _BYTE v316[16]; // [sp+F0h] [-10E0h] BYREF
  _BYTE v317[208]; // [sp+100h] [-10D0h] BYREF

  x = clothParms->gravity.x;
  type = clothParms->type;
  z = clothParms->axis.mat[2].z;
  v9 = clothParms->axis.mat[1].z;
  y = clothParms->gravity.y;
  v11 = clothParms->axis.mat[0].z;
  v12 = clothParms->gravity.z;
  v13 = clothParms->axis.mat[2].y;
  v15 = clothParms->axis.mat[1].y;
  v16 = (float)(clothParms->timeDelta * clothParms->timeDelta);
  v17 = clothParms->axis.mat[0].y;
  v300 = x;
  v18 = clothParms->axis.mat[2].x;
  v19 = clothParms->axis.mat[1].x;
  v20 = clothParms->axis.mat[0].x;
  friction = clothParms->friction;
  v315[8] = z;
  v315[7] = v9;
  v315[3] = v17;
  v315[2] = v18;
  v315[1] = v19;
  *(float *)&v299 = friction;
  v315[0] = v20;
  v315[4] = v15;
  v315[5] = v13;
  v315[6] = v11;
  if ( type == CLOTH_FLAG )
  {
    v22 = 0;
    v23 = 0;
    if ( clothParms->numWeaponTraces > 0 )
    {
      v24 = 0;
      do
      {
        numClothParticles = clothParms->numClothParticles;
        v25 = &clothParms->weaponTraces[v24];
        HIDWORD(a5) = -1;
        v26 = 999999.0;
        v27 = 999999.0;
        v28 = 0;
        v29 = (float)((float)((float)v11 * v25->dir.z)
                    + (float)((float)((float)v20 * v25->dir.x) + (float)((float)v17 * v25->dir.y)));
        v30 = (float)((float)((float)v9 * v25->dir.z)
                    + (float)((float)((float)v19 * v25->dir.x) + (float)((float)v15 * v25->dir.y)));
        v31 = (float)((float)((float)z * v25->dir.z)
                    + (float)((float)((float)v18 * v25->dir.x) + (float)((float)v13 * v25->dir.y)));
        v32 = (float)((float)((float)(v25->start.z - clothParms->org.z) * (float)v11)
                    + (float)((float)((float)(v25->start.x - clothParms->org.x) * (float)v20)
                            + (float)((float)(v25->start.y - clothParms->org.y) * (float)v17)));
        v33 = (float)((float)((float)(v25->start.z - clothParms->org.z) * (float)v9)
                    + (float)((float)((float)(v25->start.x - clothParms->org.x) * (float)v19)
                            + (float)((float)(v25->start.y - clothParms->org.y) * (float)v15)));
        v34 = (float)((float)((float)(v25->start.z - clothParms->org.z) * (float)z)
                    + (float)((float)((float)(v25->start.x - clothParms->org.x) * (float)v18)
                            + (float)((float)(v25->start.y - clothParms->org.y) * (float)v13)));
        if ( numClothParticles >= 4 )
        {
          cloth = clothParms->cloth;
          v36 = 0;
          do
          {
            p_x = &cloth[v36].origin.x;
            v41 = (float)((float)((float)(cloth[v36].origin.y - (float)v33) * (float)v30)
                        + (float)((float)((float)(cloth[v36].origin.x - (float)v32) * (float)v29)
                                + (float)((float)(cloth[v36].origin.z - (float)v34) * (float)v31)));
            if ( v41 > 0.0 )
            {
              v40 = (float)(cloth[v36].origin.y - (float)v33);
              v42 = (float)((float)v41 * (float)v41);
              v38 = (float)(cloth[v36].origin.x - (float)v32);
              v39 = (float)(cloth[v36].origin.z - (float)v34);
              v43 = (float)((float)((float)v38 * (float)v38)
                          + (float)((float)((float)v39 * (float)v39) + (float)((float)v40 * (float)v40)));
              v44 = (float)((float)v43 / (float)v42);
              if ( v44 < v26 && v44 < 25.0 )
              {
                HIDWORD(a5) = v28;
                v26 = (float)((float)v43 / (float)v42);
              }
              if ( HIDWORD(a5) != -1 && clothParms->weaponTraces[v24].causesHoles && v44 < v27 )
                v27 = (float)((float)v43 / (float)v42);
            }
            v48 = (float)((float)((float)(p_x[25] - (float)v33) * (float)v30)
                        + (float)((float)((float)(p_x[24] - (float)v32) * (float)v29)
                                + (float)((float)(p_x[26] - (float)v34) * (float)v31)));
            if ( v48 > 0.0 )
            {
              v47 = (float)(p_x[25] - (float)v33);
              v49 = (float)((float)v48 * (float)v48);
              v46 = (float)(p_x[24] - (float)v32);
              v45 = (float)(p_x[26] - (float)v34);
              v50 = (float)((float)((float)v46 * (float)v46)
                          + (float)((float)((float)v45 * (float)v45) + (float)((float)v47 * (float)v47)));
              v51 = (float)((float)v50 / (float)v49);
              if ( v51 < v26 && v51 < 25.0 )
              {
                HIDWORD(a5) = v28 + 1;
                v26 = (float)((float)v50 / (float)v49);
              }
              if ( HIDWORD(a5) != -1 && clothParms->weaponTraces[v24].causesHoles && v51 < v27 )
                v27 = (float)((float)v50 / (float)v49);
            }
            v52 = v36 * 96 + 288;
            v53 = &cloth[v36 + 3];
            v57 = (float)((float)((float)(v53[-1].origin.y - (float)v33) * (float)v30)
                        + (float)((float)((float)(v53[-1].origin.x - (float)v32) * (float)v29)
                                + (float)((float)(v53[-1].origin.z - (float)v34) * (float)v31)));
            if ( v57 > 0.0 )
            {
              v56 = (float)(v53[-1].origin.y - (float)v33);
              v58 = (float)((float)v57 * (float)v57);
              v55 = (float)(v53[-1].origin.x - (float)v32);
              v54 = (float)(v53[-1].origin.z - (float)v34);
              v59 = (float)((float)((float)v55 * (float)v55)
                          + (float)((float)((float)v54 * (float)v54) + (float)((float)v56 * (float)v56)));
              v60 = (float)((float)v59 / (float)v58);
              if ( v60 < v26 && v60 < 25.0 )
              {
                HIDWORD(a5) = v28 + 2;
                v26 = (float)((float)v59 / (float)v58);
              }
              if ( HIDWORD(a5) != -1 && clothParms->weaponTraces[v24].causesHoles && v60 < v27 )
                v27 = (float)((float)v59 / (float)v58);
            }
            v64 = (float)((float)((float)(*(float *)((char *)&cloth->origin.y + v52) - (float)v33) * (float)v30)
                        + (float)((float)((float)(*(float *)((char *)&cloth->origin.x + v52) - (float)v32) * (float)v29)
                                + (float)((float)(*(float *)((char *)&cloth->origin.z + v52) - (float)v34) * (float)v31)));
            if ( v64 > 0.0 )
            {
              v63 = (float)(*(float *)((char *)&cloth->origin.y + v52) - (float)v33);
              v65 = (float)((float)v64 * (float)v64);
              v61 = (float)(*(float *)((char *)&cloth->origin.x + v52) - (float)v32);
              v62 = (float)(*(float *)((char *)&cloth->origin.z + v52) - (float)v34);
              v66 = (float)((float)((float)v61 * (float)v61)
                          + (float)((float)((float)v62 * (float)v62) + (float)((float)v63 * (float)v63)));
              v67 = (float)((float)v66 / (float)v65);
              if ( v67 < v26 && v67 < 25.0 )
              {
                HIDWORD(a5) = v28 + 3;
                v26 = (float)((float)v66 / (float)v65);
              }
              if ( HIDWORD(a5) != -1 && clothParms->weaponTraces[v24].causesHoles && v67 < v27 )
                v27 = (float)((float)v66 / (float)v65);
            }
            v28 += 4;
            v36 += 4;
          }
          while ( v28 < numClothParticles - 3 );
        }
        if ( v28 < numClothParticles )
        {
          v68 = clothParms->cloth;
          v69 = v28;
          v70 = numClothParticles - v28;
          numClothParticles = 3 * v28;
          do
          {
            v74 = (float)((float)((float)(v68[v69].origin.y - (float)v33) * (float)v30)
                        + (float)((float)((float)(v68[v69].origin.x - (float)v32) * (float)v29)
                                + (float)((float)(v68[v69].origin.z - (float)v34) * (float)v31)));
            if ( v74 > 0.0 )
            {
              v73 = (float)(v68[v69].origin.y - (float)v33);
              v75 = (float)((float)v74 * (float)v74);
              v71 = (float)(v68[v69].origin.x - (float)v32);
              v72 = (float)(v68[v69].origin.z - (float)v34);
              v76 = (float)((float)((float)v71 * (float)v71)
                          + (float)((float)((float)v72 * (float)v72) + (float)((float)v73 * (float)v73)));
              v77 = (float)((float)v76 / (float)v75);
              if ( v77 < v26 && v77 < 25.0 )
              {
                HIDWORD(a5) = v28;
                v26 = (float)((float)v76 / (float)v75);
              }
              if ( HIDWORD(a5) != -1 && clothParms->weaponTraces[v24].causesHoles && v77 < v27 )
                v27 = (float)((float)v76 / (float)v75);
            }
            ++v28;
            ++v69;
            --v70;
          }
          while ( v70 != 0 );
        }
        if ( HIDWORD(a5) != -1 )
        {
          LODWORD(a5) = &clothParms->weaponTraces[v24];
          HIDWORD(a5) *= 3;
          v78 = &clothParms->cloth->origin.x + 8 * HIDWORD(a5);
          v79 = (float)((float)v30 * *(float *)(a5 + 24));
          v80 = (float)((float)v31 * *(float *)(a5 + 24));
          v81 = v78[10];
          v82 = v78[11];
          v78[9] = (float)((float)v29 * *(float *)(a5 + 24)) + v78[9];
          v78[10] = (float)v79 + (float)v81;
          v78[11] = (float)v80 + (float)v82;
        }
        ++v23;
        ++v24;
      }
      while ( v23 < clothParms->numWeaponTraces );
    }
    numIterations = clothParms->numIterations;
    v84 = 0;
    if ( numIterations > 0 )
    {
      v85 = v300;
      do
      {
        v86 = 0;
        if ( clothParms->numClothParticles > 0 )
        {
          v87 = 0;
          do
          {
            v301 = y;
            v88 = clothParms->cloth;
            v89 = clothParms->windDirection.x;
            v302 = v12;
            v90 = &v88[v87].origin.x;
            v91 = clothParms->windDirection.y;
            v92 = clothParms->windDirection.z;
            v300 = x;
            v93 = v90[10];
            v94 = v90[11];
            v96 = (float)((float)(y * v90[21]) + (float)v91);
            v97 = (float)(v90[9] + (float)((float)v89 + (float)((float)v85 * v90[21])));
            v95 = (float)((float)(v12 * v90[21]) + (float)v92);
            v90[9] = v97;
            v90[11] = (float)v95 + (float)v94;
            v90[10] = (float)v96 + (float)v93;
            ++v86;
            v22 |= idClothParticle::Update(
                     this: &clothParms->cloth[v87++],
                     timeDeltaSqr: v16,
                     org: (const idVec3 *)numClothParticles,
                     axis: (const idMat3 *)&clothParms->org,
                     friction: v315,
                     a6: (float *)&v299);
          }
          while ( v86 < clothParms->numClothParticles );
        }
        if ( v22 != 0 )
        {
          v98 = 0;
          if ( clothParms->numSprings > 0 )
          {
            v99 = 0;
            do
            {
              idClothSpring::Constrain(this: &clothParms->springs[v99], cloth: clothParms->cloth);
              ++v98;
              ++v99;
            }
            while ( v98 < clothParms->numSprings );
          }
        }
        v100 = 0;
        if ( clothParms->numCollisions > 0 )
        {
          v101 = clothParms->numClothParticles;
          v102 = 0;
          do
          {
            HIDWORD(a5) = 0;
            v103 = (float)(clothParms->collisions[v102].radius * clothParms->collisions[v102].radius);
            if ( v101 > 0 )
            {
              v104 = 0;
              do
              {
                idClothParticle::Collide(
                  this: (idClothParticle *)((char *)clothParms->cloth + v104),
                  s: &clothParms->collisions[v102],
                  radSqr: v103);
                v101 = clothParms->numClothParticles;
                ++HIDWORD(a5);
                v104 = v105 + 96;
              }
              while ( SHIDWORD(a5) < v101 );
            }
            ++v100;
            ++v102;
          }
          while ( v100 < clothParms->numCollisions );
        }
        numIterations = clothParms->numIterations;
        ++v84;
      }
      while ( v84 < numIterations );
    }
    if ( numIterations > 1 )
    {
      v106 = 0;
      if ( clothParms->numClothParticles > 0 )
      {
        v107 = 0;
        do
        {
          v108 = &clothParms->cloth[v107];
          if ( v108->anchored == 2 )
            v108->anchored = 0;
          ++v106;
          v109 = &clothParms->cloth[v107++];
          v109->lastOrigin.x = v109->origin.x;
          v109->lastOrigin.y = v109->origin.y;
          v109->lastOrigin.z = v109->origin.z;
        }
        while ( v106 < clothParms->numClothParticles );
      }
    }
    bounds = (float *)clothParms->bounds;
    LODWORD(a5) = 0;
    bounds[2] = 1.0e30;
    bounds[1] = 1.0e30;
    *bounds = 1.0e30;
    bounds[5] = -1.0e30;
    bounds[4] = -1.0e30;
    bounds[3] = -1.0e30;
    v111 = clothParms->numClothParticles;
    if ( v111 > 0 )
    {
      v112 = 0;
      v113 = (float *)v316;
      do
      {
        HIDWORD(a5) = clothParms->cloth;
        v114 = (float *)clothParms->bounds;
        LODWORD(a5) = a5 + 1;
        v115 = *v114;
        v116 = *(float *)(v112 + HIDWORD(a5) + 4);
        v117 = *(float *)(v112 + HIDWORD(a5));
        v118 = *(float *)(v112 + HIDWORD(a5) + 8);
        v119 = v114[5];
        _FP3 = (float)(v114[2] - *(float *)(v112 + HIDWORD(a5) + 8));
        v113[1] = *(float *)(v112 + HIDWORD(a5) + 4);
        v112 += 96;
        _FP12 = (float)((float)v115 - (float)v117);
        v122 = v114[1];
        _FP1 = (float)((float)v118 - (float)v119);
        v124 = v114[4];
        _FP31 = (float)((float)v117 - v114[3]);
        v113[2] = v118;
        *v113 = v117;
        v113 += 8;
        _FP11 = (float)((float)v122 - (float)v116);
        _FP2 = (float)((float)v116 - (float)v124);
        __asm { fsel      f0, f12, f13, f0 }
        *v114 = _FP0;
        __asm { fsel      f12, f3, f4, f8 }
        v114[2] = _FP12;
        __asm { fsel      f8, f1, f4, f5 }
        v114[5] = _FP8;
        __asm { fsel      f4, f31, f13, f7 }
        v114[3] = _FP4;
        __asm { fsel      f5, f11, f10, f9 }
        v114[1] = _FP5;
        __asm { fsel      f3, f2, f10, f6 }
        v114[4] = _FP3;
        v111 = clothParms->numClothParticles;
      }
      while ( (int)a5 < v111 );
    }
    vertices = clothParms->vertices;
    if ( vertices != nullptr )
    {
      v135 = 0;
      if ( clothParms->rect )
      {
        v136 = *(_QWORD *)&clothParms->width;
        *((_QWORD *)&v137 + 1) = v136;
        v304 = v136;
        DWORD1(v137) = &unk_82200000;
        v299 = *(_QWORD *)((char *)&v137 + 4);
        v138 = 0.0099999998;
        v139 = (float)((float)0.98000002 / (float)((float)*(__int64 *)((char *)&v137 + 4) - (float)1.0));
        v140 = (float)((float)0.98000002 / (float)((float)v136 - (float)1.0));
        if ( (int)v136 > 0 )
        {
          v141 = HIDWORD(v136);
          v142 = v136;
          _R5 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
          _R4 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
          _R3 = &_vmx_3f8000003f8000003f8000003f800000;
          __asm { lvx128    v12, r0, r5 }
          __asm
          {
            lvx128    v13, r0, r4
            lvx128    v62, r0, r3
          }
          v146 = idMath::FLT_SMALLEST_NON_DENORMAL;
          do
          {
            v147 = 0.0099999998;
            if ( v141 > 0 )
            {
              v148 = clothParms->cloth;
              __asm { vspltisw128 v63, 0 }
              v149 = v141;
              v150 = v135;
              _R11 = &v317[32 * v135 + 6];
              v135 += v141;
              do
              {
                *(float *)(_R11 - 6) = v147;
                *(float *)(_R11 - 10) = v138;
                v152 = (float *)&v316[__ROL4__(v148[v150].neighbors[2], 5)];
                v153 = (float *)&v316[__ROL4__(v148[v150].neighbors[1], 5)];
                v154 = (float *)&v316[__ROL4__(v148[v150].neighbors[0], 5)];
                v155 = (float *)&v316[__ROL4__(v148[v150].neighbors[3], 5)];
                v156 = (float)(v152[1] - v154[1]);
                v157 = (float)(v153[1] - v155[1]);
                v158 = (float)(v152[2] - v154[2]);
                v159 = (float)(v153[2] - v155[2]);
                v160 = (float)(*v153 - *v155);
                _FP28 = (float)((float)((float)((float)(*v152 - *v154) * (float)(*v152 - *v154))
                                      + (float)((float)((float)v158 * (float)v158) + (float)((float)v156 * (float)v156)))
                              - (float)v146);
                _FP24 = (float)((float)((float)((float)(*v153 - *v155) * (float)(*v153 - *v155))
                                      + (float)((float)((float)v159 * (float)v159) + (float)((float)v157 * (float)v157)))
                              - (float)v146);
                __asm
                {
                  fsel      f9, f28, f9, f13
                  fsel      f8, f24, f8, f13
                }
                v165 = __frsqrte(_FP9);
                v166 = __frsqrte(_FP8);
                v167 = (float)((float)-(float)((float)((float)((float)v165
                                                             * (float)((float)((float)((float)(*v152 - *v154)
                                                                                     * (float)(*v152 - *v154))
                                                                             + (float)((float)((float)v158 * (float)v158)
                                                                                     + (float)((float)v156 * (float)v156)))
                                                                     * (float)0.5))
                                                     * (float)v165)
                                             - (float)1.5)
                             * (float)v165);
                v168 = (float)((float)-(float)((float)((float)((float)v166
                                                             * (float)((float)((float)((float)(*v153 - *v155)
                                                                                     * (float)(*v153 - *v155))
                                                                             + (float)((float)((float)v159 * (float)v159)
                                                                                     + (float)((float)v157 * (float)v157)))
                                                                     * (float)0.5))
                                                     * (float)v166)
                                             - (float)1.5)
                             * (float)v166);
                v169 = (float)((float)-(float)((float)((float)((float)v167
                                                             * (float)((float)((float)((float)(*v152 - *v154)
                                                                                     * (float)(*v152 - *v154))
                                                                             + (float)((float)((float)v158 * (float)v158)
                                                                                     + (float)((float)v156 * (float)v156)))
                                                                     * (float)0.5))
                                                     * (float)v167)
                                             - (float)1.5)
                             * (float)v167);
                v170 = (float)((float)-(float)((float)((float)((float)v168
                                                             * (float)((float)((float)((float)(*v153 - *v155)
                                                                                     * (float)(*v153 - *v155))
                                                                             + (float)((float)((float)v159 * (float)v159)
                                                                                     + (float)((float)v157 * (float)v157)))
                                                                     * (float)0.5))
                                                     * (float)v168)
                                             - (float)1.5)
                             * (float)v168);
                v171 = (float)((float)-(float)((float)((float)((float)v169
                                                             * (float)((float)((float)((float)(*v152 - *v154)
                                                                                     * (float)(*v152 - *v154))
                                                                             + (float)((float)((float)v158 * (float)v158)
                                                                                     + (float)((float)v156 * (float)v156)))
                                                                     * (float)0.5))
                                                     * (float)v169)
                                             - (float)1.5)
                             * (float)v169);
                v172 = (float)((float)-(float)((float)((float)((float)v170
                                                             * (float)((float)((float)((float)(*v153 - *v155)
                                                                                     * (float)(*v153 - *v155))
                                                                             + (float)((float)((float)v159 * (float)v159)
                                                                                     + (float)((float)v157 * (float)v157)))
                                                                     * (float)0.5))
                                                     * (float)v170)
                                             - (float)1.5)
                             * (float)v170);
                *(float *)&v305 = (float)((float)-(float)((float)((float)((float)v169
                                                                        * (float)((float)((float)((float)(*v152 - *v154)
                                                                                                * (float)(*v152 - *v154))
                                                                                        + (float)((float)((float)v158 * (float)v158)
                                                                                                + (float)((float)v156 * (float)v156)))
                                                                                * (float)0.5))
                                                                * (float)v169)
                                                        - (float)1.5)
                                        * (float)v169)
                                * (float)(*v152 - *v154);
                v306 = (float)v158 * (float)v171;
                v173 = (float)((float)v157 * (float)v172);
                *((float *)&v305 + 1) = (float)v156 * (float)v171;
                v174 = (float)((float)v172 * (float)v160);
                v175 = (float)((float)v159 * (float)v172);
                *(float *)&v307 = (float)(*((float *)&v305 + 1) * (float)v175)
                                - (float)(v306 * (float)((float)v157 * (float)v172));
                _R5 = (char *)&v307 + 4;
                HIDWORD(_R7) = &v308;
                _R26 = &v307;
                __asm { vor128    v61, v95, v63 }
                _R10 = _R11 - 2;
                __asm { vor128    v60, v95, v63 }
                _R9 = _R11 - 1;
                _R22 = &v306;
                _R20 = &v305;
                _R23 = (char *)&v305 + 4;
                HIDWORD(_R9) = _R11 + 2;
                _R7 = _R11 + 3;
                v308 = (float)((float)((float)v157 * (float)v172) * *(float *)&v305)
                     - (float)(*((float *)&v305 + 1) * (float)v174);
                *((float *)&v307 + 1) = (float)(v306 * (float)v174) - (float)((float)v175 * *(float *)&v305);
                __asm { lvlx128   v58, r0, r4 }
                _R6 = _R11 + 4;
                __asm
                {
                  lvlx128   v59, r0, r5
                  lvlx128   v57, r0, r26
                  vrlimi128 v61, v57, 8, 0
                  vrlimi128 v61, v59, 4, 3
                  vrlimi128 v61, v58, 2, 2
                  vaddfp128 v0, v93, v62
                  vmaddfp   v0, v0, v13, v12
                  vcfpsxws128 v56, v0, 0
                  vpkswss128 v55, v88, v56
                  vpkshus128 v0, v87, v55
                  stvebx    v0, 0, r10
                  stvebx    v0, 0, r9
                  stvebx    v0, 0, r11
                  lvlx128   v53, r0, r22
                  lvlx128   v52, r0, r20
                  vrlimi128 v60, v52, 8, 0
                  lvlx128   v54, r0, r23
                  vrlimi128 v60, v54, 4, 3
                  vrlimi128 v60, v53, 2, 2
                  vaddfp128 v0, v92, v62
                  vmaddfp   v0, v0, v13, v12
                  vcfpsxws128 v51, v0, 0
                  vpkswss128 v50, v83, v51
                  vpkshus128 v0, v82, v50
                  stvebx    v0, 0, r8
                  stvebx    v0, 0, r7
                  stvebx    v0, 0, r6
                }
                DWORD2(_R7) = _R11[4];
                DWORD1(_R7) = _R11[2];
                LODWORD(_R7) = _R11[3];
                v304 = _R7;
                v299 = *(_QWORD *)((char *)&_R7 + 4);
                v312 = *(_QWORD *)&_R7;
                v187 = (double)(__int64)_R7;
                LODWORD(_R9) = *_R11;
                LODWORD(_R7) = *(_R11 - 1);
                v313 = _R7;
                v188 = (double)*(__int64 *)((char *)&_R7 + 4);
                DWORD2(_R7) = *(_R11 - 2);
                v314 = _R9;
                v189 = (float)((float)((float)v187 * (float)0.0078431377) - (float)1.0);
                v190 = (float)((float)((float)v188 * (float)0.0078431377) - (float)1.0);
                v191 = (float)((float)((float)*(__int64 *)&_R7 * (float)0.0078431377) - (float)1.0);
                _FP27 = (float)((float)((float)((float)v191 * (float)v191)
                                      + (float)((float)((float)v190 * (float)v190) + (float)((float)v189 * (float)v189)))
                              - (float)v146);
                __asm { fsel      f28, f27, f28, f13 }
                v194 = __frsqrte(_FP28);
                v303 = *(_QWORD *)((char *)&_R7 + 4);
                v195 = 0;
                v196 = (float)((float)((float)v313 * (float)0.0078431377) - (float)1.0);
                v197 = (float)((float)((float)_R9 * (float)0.0078431377) - (float)1.0);
                v198 = (float)((float)-(float)((float)((float)((float)v194
                                                             * (float)((float)((float)((float)v191 * (float)v191)
                                                                             + (float)((float)((float)v190 * (float)v190)
                                                                                     + (float)((float)v189 * (float)v189)))
                                                                     * (float)0.5))
                                                     * (float)v194)
                                             - (float)1.5)
                             * (float)v194);
                v199 = (float)((float)((float)*(__int64 *)((char *)&_R7 + 4) * (float)0.0078431377) - (float)1.0);
                _FP21 = (float)((float)((float)((float)v199 * (float)v199)
                                      + (float)((float)((float)v197 * (float)v197) + (float)((float)v196 * (float)v196)))
                              - (float)v146);
                v201 = (float)((float)-(float)((float)((float)((float)v198
                                                             * (float)((float)((float)((float)v191 * (float)v191)
                                                                             + (float)((float)((float)v190 * (float)v190)
                                                                                     + (float)((float)v189 * (float)v189)))
                                                                     * (float)0.5))
                                                     * (float)v198)
                                             - (float)1.5)
                             * (float)v198);
                __asm { fsel      f23, f21, f23, f13 }
                v203 = __frsqrte(_FP23);
                v204 = (float)((float)-(float)((float)((float)((float)v201
                                                             * (float)((float)((float)((float)v191 * (float)v191)
                                                                             + (float)((float)((float)v190 * (float)v190)
                                                                                     + (float)((float)v189 * (float)v189)))
                                                                     * (float)0.5))
                                                     * (float)v201)
                                             - (float)1.5)
                             * (float)v201);
                v205 = (float)((float)v204 * (float)((float)((float)*(__int64 *)&_R7 * (float)0.0078431377) - (float)1.0));
                v206 = (float)((float)v189 * (float)v204);
                v207 = (float)((float)v190 * (float)v204);
                v208 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v203 * (float)((float)((float)((float)v199 * (float)v199) + (float)((float)((float)v197 * (float)v197) + (float)((float)v196 * (float)v196))) * (float)0.5))
                                                                                             * (float)v203)
                                                                                     - (float)1.5)
                                                                     * (float)v203)
                                                             * (float)((float)((float)((float)v199 * (float)v199)
                                                                             + (float)((float)((float)v197 * (float)v197)
                                                                                     + (float)((float)v196 * (float)v196)))
                                                                     * (float)0.5))
                                                     * (float)((float)-(float)((float)((float)((float)v203
                                                                                             * (float)((float)((float)((float)v199 * (float)v199) + (float)((float)((float)v197 * (float)v197) + (float)((float)v196 * (float)v196))) * (float)0.5))
                                                                                     * (float)v203)
                                                                             - (float)1.5)
                                                             * (float)v203))
                                             - (float)1.5)
                             * (float)((float)-(float)((float)((float)((float)v203
                                                                     * (float)((float)((float)((float)v199 * (float)v199)
                                                                                     + (float)((float)((float)v197 * (float)v197)
                                                                                             + (float)((float)v196 * (float)v196)))
                                                                             * (float)0.5))
                                                             * (float)v203)
                                                     - (float)1.5)
                                     * (float)v203));
                v209 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v203 * (float)((float)((float)((float)v199 * (float)v199) + (float)((float)((float)v197 * (float)v197) + (float)((float)v196 * (float)v196))) * (float)0.5)) * (float)v203) - (float)1.5) * (float)v203) * (float)((float)((float)((float)v199 * (float)v199) + (float)((float)((float)v197 * (float)v197) + (float)((float)v196 * (float)v196))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v203 * (float)((float)((float)((float)v199 * (float)v199) + (float)((float)((float)v197 * (float)v197) + (float)((float)v196 * (float)v196))) * (float)0.5)) * (float)v203) - (float)1.5) * (float)v203))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v203 * (float)((float)((float)((float)v199 * (float)v199) + (float)((float)((float)v197 * (float)v197) + (float)((float)v196 * (float)v196))) * (float)0.5)) * (float)v203)
                                                                                             - (float)1.5)
                                                                             * (float)v203))
                                                             * (float)((float)((float)((float)v199 * (float)v199)
                                                                             + (float)((float)((float)v197 * (float)v197)
                                                                                     + (float)((float)v196 * (float)v196)))
                                                                     * (float)0.5))
                                                     * (float)v208)
                                             - (float)1.5)
                             * (float)v208);
                v210 = (float)((float)v209
                             * (float)((float)((float)*(__int64 *)((char *)&_R7 + 4) * (float)0.0078431377) - (float)1.0));
                v211 = (float)((float)((float)((float)v313 * (float)0.0078431377) - (float)1.0) * (float)v209);
                v213 = (float)((float)v207
                             * (float)((float)v209
                                     * (float)((float)((float)*(__int64 *)((char *)&_R7 + 4) * (float)0.0078431377)
                                             - (float)1.0)));
                v214 = (float)((float)((float)((float)((float)v313 * (float)0.0078431377) - (float)1.0) * (float)v209)
                             * (float)v205);
                v212 = (float)((float)((float)((float)_R9 * (float)0.0078431377) - (float)1.0) * (float)v209);
                if ( (float)((float)((float)((float)((float)v211 * (float)v207) - (float)((float)v212 * (float)v206))
                                   * (float)v174)
                           + (float)((float)((float)((float)((float)v206 * (float)v210) - (float)v214) * (float)v175)
                                   + (float)((float)((float)((float)v212 * (float)v205) - (float)v213) * (float)v173))) >= 0.0 )
                  v195 = -1;
                v147 = (float)((float)v139 + (float)v147);
                ++v150;
                _R11[5] = v195;
                _R11 += 32;
                --v149;
              }
              while ( v149 != 0 );
            }
            --v142;
            v138 = (float)((float)v140 + (float)v138);
          }
          while ( v142 != 0 );
        }
      }
      else
      {
        hSpacing = clothParms->hSpacing;
        height = (unsigned int)clothParms->height;
        LODWORD(a5) = clothParms->width - 1;
        v217 = (float)((float)a5 * clothParms->hSpacing);
        v218 = (float)((float)((float)a5 * clothParms->hSpacing) * (float)0.5);
        v303 = a5;
        if ( (int)height > 0 )
        {
          vSpacing = clothParms->vSpacing;
          HIDWORD(_R11) = &unk_821F0000;
          _R5 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
          _R4 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
          _R3 = &_vmx_3f8000003f8000003f8000003f800000;
          __asm { lvx128    v12, r0, r5 }
          v224 = 1;
          __asm
          {
            lvx128    v13, r0, r4
            lvx128    v62, r0, r3
          }
          v225 = idMath::FLT_SMALLEST_NON_DENORMAL;
          do
          {
            LODWORD(_R11) = HIDWORD(height);
            v226 = v218;
            v303 = _R11;
            v227 = (float)((float)_R11 * (float)vSpacing);
            if ( v224 > 0 )
            {
              v228 = clothParms->cloth;
              __asm { vspltisw128 v63, 0 }
              LODWORD(v229) = height - 1;
              v230 = v224;
              HIDWORD(v229) = 3 * v135;
              v314 = v229;
              v231 = v135;
              LODWORD(_R11) = &v317[32 * v135 + 6];
              v135 += v224;
              v232 = (float)((float)v227 / (float)((float)v229 * (float)vSpacing));
              do
              {
                *(float *)(_R11 - 6) = (float)v226 / (float)v217;
                _R23 = &v300;
                *(float *)(_R11 - 10) = v232;
                __asm { vor128    v49, v95, v63 }
                _R22 = &v301;
                HIDWORD(_R11) = (char *)v228 + 32 * v228[v231].neighbors[3] + 32 * __ROL4__(v228[v231].neighbors[3], 1);
                v235 = &v228->origin.x + 8 * v228[v231].neighbors[1] + 8 * __ROL4__(v228[v231].neighbors[1], 1);
                v236 = (float)(v235[2] - *(float *)(HIDWORD(_R11) + 8));
                v237 = &v228->origin.x + 8 * v228[v231].neighbors[0] + 8 * __ROL4__(v228[v231].neighbors[0], 1);
                v238 = &v228->origin.x + 8 * v228[v231].neighbors[2] + 8 * __ROL4__(v228[v231].neighbors[2], 1);
                v239 = (float)(v235[1] - *(float *)(HIDWORD(_R11) + 4));
                v240 = (float)(v238[2] - v237[2]);
                v241 = (float)(*v238 - *v237);
                v242 = (float)(v238[1] - v237[1]);
                _FP25 = (float)((float)((float)((float)v239 * (float)v239)
                                      + (float)((float)((float)(*v235 - *(float *)HIDWORD(_R11))
                                                      * (float)(*v235 - *(float *)HIDWORD(_R11)))
                                              + (float)((float)v236 * (float)v236)))
                              - (float)v225);
                _FP23 = (float)((float)((float)((float)v242 * (float)v242)
                                      + (float)((float)((float)(*v238 - *v237) * (float)(*v238 - *v237))
                                              + (float)((float)v240 * (float)v240)))
                              - (float)v225);
                __asm { fsel      f28, f25, f28, f13 }
                __asm { fsel      f26, f23, f26, f13 }
                v247 = __frsqrte(_FP28);
                v248 = __frsqrte(_FP26);
                v249 = (float)((float)-(float)((float)((float)((float)v247
                                                             * (float)((float)((float)((float)v239 * (float)v239)
                                                                             + (float)((float)((float)(*v235 - *(float *)HIDWORD(_R11))
                                                                                             * (float)(*v235 - *(float *)HIDWORD(_R11)))
                                                                                     + (float)((float)v236 * (float)v236)))
                                                                     * (float)0.5))
                                                     * (float)v247)
                                             - (float)1.5)
                             * (float)v247);
                v250 = (float)((float)-(float)((float)((float)((float)v248
                                                             * (float)((float)((float)((float)v242 * (float)v242)
                                                                             + (float)((float)((float)(*v238 - *v237)
                                                                                             * (float)(*v238 - *v237))
                                                                                     + (float)((float)v240 * (float)v240)))
                                                                     * (float)0.5))
                                                     * (float)v248)
                                             - (float)1.5)
                             * (float)v248);
                v251 = (float)((float)-(float)((float)((float)((float)v249
                                                             * (float)((float)((float)((float)v239 * (float)v239)
                                                                             + (float)((float)((float)(*v235 - *(float *)HIDWORD(_R11))
                                                                                             * (float)(*v235 - *(float *)HIDWORD(_R11)))
                                                                                     + (float)((float)v236 * (float)v236)))
                                                                     * (float)0.5))
                                                     * (float)v249)
                                             - (float)1.5)
                             * (float)v249);
                v252 = (float)((float)-(float)((float)((float)((float)v250
                                                             * (float)((float)((float)((float)v242 * (float)v242)
                                                                             + (float)((float)((float)(*v238 - *v237)
                                                                                             * (float)(*v238 - *v237))
                                                                                     + (float)((float)v240 * (float)v240)))
                                                                     * (float)0.5))
                                                     * (float)v250)
                                             - (float)1.5)
                             * (float)v250);
                v253 = (float)((float)-(float)((float)((float)((float)v251
                                                             * (float)((float)((float)((float)v239 * (float)v239)
                                                                             + (float)((float)((float)(*v235 - *(float *)HIDWORD(_R11))
                                                                                             * (float)(*v235 - *(float *)HIDWORD(_R11)))
                                                                                     + (float)((float)v236 * (float)v236)))
                                                                     * (float)0.5))
                                                     * (float)v251)
                                             - (float)1.5)
                             * (float)v251);
                v254 = (float)((float)v253 * (float)(*v235 - *(float *)HIDWORD(_R11)));
                v255 = (float)((float)(v235[1] - *(float *)(HIDWORD(_R11) + 4)) * (float)v253);
                v256 = (float)((float)(v235[2] - *(float *)(HIDWORD(_R11) + 8)) * (float)v253);
                v257 = (float)((float)-(float)((float)((float)((float)v252
                                                             * (float)((float)((float)((float)v242 * (float)v242)
                                                                             + (float)((float)((float)(*v238 - *v237)
                                                                                             * (float)(*v238 - *v237))
                                                                                     + (float)((float)v240 * (float)v240)))
                                                                     * (float)0.5))
                                                     * (float)v252)
                                             - (float)1.5)
                             * (float)v252);
                _R4 = &v302;
                HIDWORD(_R11) = _R11 - 2;
                __asm { vor128    v48, v95, v63 }
                _R8 = _R11 - 1;
                _R20 = &v311;
                _R19 = &v309;
                DWORD1(_R5) = &v310;
                HIDWORD(_R8) = _R11 + 2;
                _R6 = _R11 + 3;
                _R5 = _R11 + 4;
                v311 = (float)v240 * (float)v257;
                v309 = (float)v257 * (float)v241;
                v310 = (float)v242 * (float)v257;
                v300 = (float)(v310 * (float)v256) - (float)(v311 * (float)v255);
                v301 = (float)(v311 * (float)v254) - (float)((float)v256 * v309);
                v302 = (float)((float)v255 * v309) - (float)(v310 * (float)v254);
                __asm
                {
                  lvlx128   v45, r0, r22
                  lvlx128   v47, r0, r4
                  lvlx128   v46, r0, r23
                  vrlimi128 v49, v46, 8, 0
                  vrlimi128 v49, v45, 4, 3
                  vrlimi128 v49, v47, 2, 2
                  vaddfp128 v0, v81, v62
                  vmaddfp   v0, v0, v13, v12
                  vcfpsxws128 v44, v0, 0
                  vpkswss128 v43, v76, v44
                  vpkshus128 v0, v75, v43
                  stvebx    v0, 0, r10
                  stvebx    v0, 0, r8
                  stvebx    v0, 0, r11
                  lvlx128   v41, r0, r20
                  lvlx128   v40, r0, r19
                  vrlimi128 v48, v40, 8, 0
                  lvlx128   v42, r0, r3
                  vrlimi128 v48, v42, 4, 3
                  vrlimi128 v48, v41, 2, 2
                  vaddfp128 v0, v80, v62
                  vmaddfp   v0, v0, v13, v12
                  vcfpsxws128 v39, v0, 0
                  vpkswss128 v38, v71, v39
                  vpkshus128 v0, v70, v38
                  stvebx    v0, 0, r7
                  stvebx    v0, 0, r6
                  stvebx    v0, 0, r5
                }
                DWORD2(_R5) = *(unsigned __int8 *)(_R11 + 2);
                v304 = *(_QWORD *)((char *)&_R5 + 4);
                v266 = *(unsigned __int8 *)(_R11 + 3);
                LODWORD(_R5) = *(unsigned __int8 *)(_R11 + 4);
                v312 = _R5;
                v313 = *(_QWORD *)((char *)&_R5 - 4);
                LODWORD(_R8) = *(unsigned __int8 *)(_R11 - 2);
                v267 = (double)(__int64)_R5;
                v269 = (float)*(__int64 *)((char *)&_R5 - 4);
                v268 = *(unsigned __int8 *)_R11;
                v299 = _R8;
                LODWORD(_R5) = *(unsigned __int8 *)(_R11 - 1);
                v305 = *(_QWORD *)((char *)&_R5 - 4);
                v270 = (float)((float)((float)v269 * (float)0.0078431377) - (float)1.0);
                v271 = (float)((float)((float)*(__int64 *)((char *)&_R5 + 4) * (float)0.0078431377) - (float)1.0);
                v272 = (float)((float)((float)v267 * (float)0.0078431377) - (float)1.0);
                v307 = _R5;
                BYTE3(_R11) = 0;
                _FP25 = (float)((float)((float)((float)v271 * (float)v271)
                                      + (float)((float)((float)v272 * (float)v272) + (float)((float)v270 * (float)v270)))
                              - (float)v225);
                __asm { fsel      f31, f25, f31, f13 }
                v275 = (float)((float)((float)*(__int64 *)((char *)&_R5 - 4) * (float)0.0078431377) - (float)1.0);
                v276 = __frsqrte(_FP31);
                v277 = (float)((float)((float)_R8 * (float)0.0078431377) - (float)1.0);
                v278 = (float)((float)((float)(__int64)_R5 * (float)0.0078431377) - (float)1.0);
                v279 = (float)((float)-(float)((float)((float)((float)v276
                                                             * (float)((float)((float)((float)v271 * (float)v271)
                                                                             + (float)((float)((float)v272 * (float)v272)
                                                                                     + (float)((float)v270 * (float)v270)))
                                                                     * (float)0.5))
                                                     * (float)v276)
                                             - (float)1.5)
                             * (float)v276);
                _FP20 = (float)((float)((float)((float)v277 * (float)v277)
                                      + (float)((float)((float)v275 * (float)v275) + (float)((float)v278 * (float)v278)))
                              - (float)v225);
                __asm { fsel      f25, f20, f25, f13 }
                v282 = (float)((float)-(float)((float)((float)((float)v279
                                                             * (float)((float)((float)((float)v271 * (float)v271)
                                                                             + (float)((float)((float)v272 * (float)v272)
                                                                                     + (float)((float)v270 * (float)v270)))
                                                                     * (float)0.5))
                                                     * (float)v279)
                                             - (float)1.5)
                             * (float)v279);
                v283 = (float)__frsqrte(_FP25);
                v284 = (float)((float)-(float)((float)((float)((float)v282
                                                             * (float)((float)((float)((float)v271 * (float)v271)
                                                                             + (float)((float)((float)v272 * (float)v272)
                                                                                     + (float)((float)v270 * (float)v270)))
                                                                     * (float)0.5))
                                                     * (float)v282)
                                             - (float)1.5)
                             * (float)v282);
                v285 = (float)((float)v272 * (float)v284);
                v286 = (float)((float)v284
                             * (float)((float)((float)*(__int64 *)((char *)&_R5 + 4) * (float)0.0078431377) - (float)1.0));
                v287 = (float)((float)v270 * (float)v284);
                v288 = (float)((float)-(float)((float)((float)((float)v283
                                                             * (float)((float)((float)((float)v277 * (float)v277)
                                                                             + (float)((float)((float)v275 * (float)v275)
                                                                                     + (float)((float)v278 * (float)v278)))
                                                                     * (float)0.5))
                                                     * (float)v283)
                                             - (float)1.5)
                             * (float)v283);
                v289 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v288 * (float)((float)((float)((float)v277 * (float)v277) + (float)((float)((float)v275 * (float)v275) + (float)((float)v278 * (float)v278))) * (float)0.5))
                                                                                             * (float)v288)
                                                                                     - (float)1.5)
                                                                     * (float)v288)
                                                             * (float)((float)((float)((float)v277 * (float)v277)
                                                                             + (float)((float)((float)v275 * (float)v275)
                                                                                     + (float)((float)v278 * (float)v278)))
                                                                     * (float)0.5))
                                                     * (float)((float)-(float)((float)((float)((float)v288
                                                                                             * (float)((float)((float)((float)v277 * (float)v277) + (float)((float)((float)v275 * (float)v275) + (float)((float)v278 * (float)v278))) * (float)0.5))
                                                                                     * (float)v288)
                                                                             - (float)1.5)
                                                             * (float)v288))
                                             - (float)1.5)
                             * (float)((float)-(float)((float)((float)((float)v288
                                                                     * (float)((float)((float)((float)v277 * (float)v277)
                                                                                     + (float)((float)((float)v275 * (float)v275)
                                                                                             + (float)((float)v278 * (float)v278)))
                                                                             * (float)0.5))
                                                             * (float)v288)
                                                     - (float)1.5)
                                     * (float)v288));
                v290 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v288 * (float)((float)((float)((float)v277 * (float)v277) + (float)((float)((float)v275 * (float)v275) + (float)((float)v278 * (float)v278))) * (float)0.5)) * (float)v288)
                                                                                             - (float)1.5)
                                                                             * (float)v288)
                                                                     * (float)((float)((float)((float)v277 * (float)v277)
                                                                                     + (float)((float)((float)v275 * (float)v275)
                                                                                             + (float)((float)v278 * (float)v278)))
                                                                             * (float)0.5))
                                                             * (float)((float)-(float)((float)((float)((float)v288 * (float)((float)((float)((float)v277 * (float)v277) + (float)((float)((float)v275 * (float)v275) + (float)((float)v278 * (float)v278))) * (float)0.5))
                                                                                             * (float)v288)
                                                                                     - (float)1.5)
                                                                     * (float)v288))
                                                     - (float)1.5)
                                     * (float)((float)-(float)((float)((float)((float)v288
                                                                             * (float)((float)((float)((float)v277 * (float)v277)
                                                                                             + (float)((float)((float)v275 * (float)v275) + (float)((float)v278 * (float)v278)))
                                                                                     * (float)0.5))
                                                                     * (float)v288)
                                                             - (float)1.5)
                                             * (float)v288))
                             * (float)v277);
                v291 = (float)((float)((float)((float)(__int64)_R5 * (float)0.0078431377) - (float)1.0) * (float)v289);
                v293 = (float)((float)((float)((float)((float)(__int64)_R5 * (float)0.0078431377) - (float)1.0)
                                     * (float)v289)
                             * (float)v286);
                v292 = (float)((float)((float)((float)*(__int64 *)((char *)&_R5 - 4) * (float)0.0078431377) - (float)1.0)
                             * (float)v289);
                if ( (float)((float)((float)((float)((float)v291 * (float)v285) - (float)((float)v292 * (float)v287))
                                   * (float)v254)
                           + (float)((float)((float)((float)((float)v287 * (float)v290) - (float)v293) * (float)v256)
                                   + (float)((float)((float)((float)v292 * (float)v286)
                                                   - (float)((float)v285 * (float)v290))
                                           * (float)v255))) >= 0.0 )
                  BYTE3(_R11) = -1;
                HIDWORD(_R11) = BYTE3(_R11);
                v226 = (float)((float)hSpacing + (float)v226);
                ++v231;
                *(_BYTE *)(_R11 + 5) = BYTE3(_R11);
                LODWORD(_R11) = _R11 + 32;
                --v230;
              }
              while ( v230 != 0 );
            }
            ++HIDWORD(height);
            v218 = (float)((float)v218 - (float)hSpacing);
            v224 += 2;
          }
          while ( SHIDWORD(height) < (int)height );
        }
      }
      if ( v111 > 0 )
      {
        v294 = v111;
        _R11 = vertices;
        _R10 = (_BYTE *)(v316 - (_BYTE *)vertices);
        _R9 = (_BYTE *)(v317 - (_BYTE *)vertices);
        _R8 = 16;
        do
        {
          __asm
          {
            lvx128    v37, r10, r11
            stvx128   v37, r0, r11
            lvx128    v36, r9, r11
            stvx128   v36, r11, r8
          }
          ++_R11;
          --v294;
        }
        while ( v294 != 0 );
      }
    }
  }
  else
  {
    RopeGen(clothParms);
  }
}


// ========================================================================
// `dynamic initializer for 'register_ClothGenJob''
// EA  : 0x83342218
// RVA : 0x01342218
// PDB : w:\tech5\engine\models\cloth\jobs\clothgen.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_ClothGenJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_ClothGenJob,
           function: (void (__fastcall *)(void *))ClothGenJob,
           name: "ClothGenJob");
}

