
// ========================================================================
// ?Normalize360@idAngles@@QAAAAV1@XZ
// EA  : 0x82F2FB58
// RVA : 0x00F2FB58
// PDB : w:\tech5\shared\idlib\math\angles.cpp
// ========================================================================

idAngles *__fastcall idAngles::Normalize360(idAngles *this, long double a2)
{
  idAngles *v3; // r31
  int i; // r30
  double pitch; // fp0

  v3 = this;
  for ( i = 3; i != 0; --i )
  {
    pitch = v3->pitch;
    if ( pitch >= 360.0 || pitch < 0.0 )
    {
      *(double *)&a2 = (float)(v3->pitch * (float)0.0027777778);
      a2 = floor(x: a2);
      v3->pitch = -(float)((float)((float)*(double *)&a2 * (float)360.0) - v3->pitch);
    }
    if ( v3->pitch >= 360.0 )
      v3->pitch = v3->pitch - (float)360.0;
    if ( v3->pitch < 0.0 )
      v3->pitch = v3->pitch + (float)360.0;
    v3 = (idAngles *)((char *)v3 + 4);
  }
  return this;
}


// ========================================================================
// ?Normalize180@idAngles@@QAAAAV1@XZ
// EA  : 0x82F2FC10
// RVA : 0x00F2FC10
// PDB : w:\tech5\shared\idlib\math\angles.cpp
// ========================================================================

idAngles *__fastcall idAngles::Normalize180(idAngles *this, long double a2)
{
  idAngles::Normalize360(this, a2);
  if ( this->pitch > 180.0 )
    this->pitch = this->pitch - (float)360.0;
  if ( this->yaw > 180.0 )
    this->yaw = this->yaw - (float)360.0;
  if ( this->roll > 180.0 )
    this->roll = this->roll - (float)360.0;
  return this;
}


// ========================================================================
// ?ToVectors@idAngles@@QBAXPAVidVec3@@00@Z
// EA  : 0x82F2FC90
// RVA : 0x00F2FC90
// PDB : w:\tech5\shared\idlib\math\angles.cpp
// ========================================================================

void __fastcall idAngles::ToVectors(idAngles *this, idVec3 *forward, idVec3 *right, idVec3 *up, long double a5)
{
  double v9; // fp30
  long double v10; // fp2
  double v11; // fp31
  long double v12; // fp2
  double v13; // fp30
  double v14; // fp29
  long double v15; // fp2
  double v16; // fp27
  long double v17; // fp2
  double v18; // fp29
  double v19; // fp26
  long double v20; // fp2
  double v21; // fp28
  long double v22; // fp2

  v9 = (float)(this->yaw * idMath::M_DEG2RAD);
  *(double *)&a5 = v9;
  v10 = sin(x: a5);
  v11 = (float)*(double *)&v10;
  *(double *)&v10 = v9;
  v12 = cos(x: v10);
  v13 = (float)*(double *)&v12;
  v14 = (float)(this->pitch * idMath::M_DEG2RAD);
  *(double *)&v12 = v14;
  v15 = sin(x: v12);
  v16 = (float)*(double *)&v15;
  *(double *)&v15 = v14;
  v17 = cos(x: v15);
  v18 = (float)*(double *)&v17;
  v19 = (float)(this->roll * idMath::M_DEG2RAD);
  *(double *)&v17 = v19;
  v20 = sin(x: v17);
  v21 = (float)*(double *)&v20;
  *(double *)&v20 = v19;
  v22 = cos(x: v20);
  if ( forward != nullptr )
  {
    forward->x = (float)v18 * (float)v13;
    forward->y = (float)v18 * (float)v11;
    forward->z = -v16;
  }
  if ( right != nullptr )
  {
    right->y = -(float)((float)((float)((float)v21 * (float)v16) * (float)v11)
                      + (float)((float)*(double *)&v22 * (float)v13));
    right->z = -(float)((float)v21 * (float)v18);
    right->x = (float)((float)*(double *)&v22 * (float)v11) - (float)((float)((float)v21 * (float)v16) * (float)v13);
  }
  if ( up != nullptr )
  {
    up->z = (float)*(double *)&v22 * (float)v18;
    up->x = (float)((float)((float)*(double *)&v22 * (float)v16) * (float)v13) + (float)((float)v21 * (float)v11);
    up->y = (float)((float)((float)*(double *)&v22 * (float)v16) * (float)v11) - (float)((float)v21 * (float)v13);
  }
}


// ========================================================================
// ?ToForward@idAngles@@QBA?AVidVec3@@XZ
// EA  : 0x82F2FDB0
// RVA : 0x00F2FDB0
// PDB : w:\tech5\shared\idlib\math\angles.cpp
// ========================================================================

idAngles *__fastcall idAngles::ToForward(idAngles *this, idVec3 *result, long double a3)
{
  double v5; // fp31
  long double v6; // fp2
  double v7; // fp30
  long double v8; // fp2
  double v9; // fp31
  double v10; // fp29
  long double v11; // fp2
  double v12; // fp28
  long double v13; // fp2

  v5 = (float)(result->y * idMath::M_DEG2RAD);
  *(double *)&a3 = v5;
  v6 = sin(x: a3);
  v7 = (float)*(double *)&v6;
  *(double *)&v6 = v5;
  v8 = cos(x: v6);
  v9 = (float)*(double *)&v8;
  v10 = (float)(result->x * idMath::M_DEG2RAD);
  *(double *)&v8 = v10;
  v11 = sin(x: v8);
  v12 = (float)*(double *)&v11;
  *(double *)&v11 = v10;
  v13 = cos(x: v11);
  this->roll = -v12;
  this->pitch = (float)*(double *)&v13 * (float)v9;
  this->yaw = (float)*(double *)&v13 * (float)v7;
  return this;
}


// ========================================================================
// ?ToQuat@idAngles@@QBA?AVidQuat@@XZ
// EA  : 0x82F2FE48
// RVA : 0x00F2FE48
// PDB : w:\tech5\shared\idlib\math\angles.cpp
// ========================================================================

idAngles *__fastcall idAngles::ToQuat(idAngles *this, idQuat *result, long double a3)
{
  double v5; // fp30
  long double v6; // fp2
  double v7; // fp29
  long double v8; // fp2
  double v9; // fp30
  double v10; // fp28
  long double v11; // fp2
  double v12; // fp27
  long double v13; // fp2
  double v14; // fp28
  double v15; // fp31
  long double v16; // fp2
  double v17; // fp26
  long double v18; // fp2

  v5 = (float)((float)(result->y * idMath::M_DEG2RAD) * (float)0.5);
  *(double *)&a3 = v5;
  v6 = sin(x: a3);
  v7 = (float)*(double *)&v6;
  *(double *)&v6 = v5;
  v8 = cos(x: v6);
  v9 = (float)*(double *)&v8;
  v10 = (float)((float)(result->x * idMath::M_DEG2RAD) * (float)0.5);
  *(double *)&v8 = v10;
  v11 = sin(x: v8);
  v12 = (float)*(double *)&v11;
  *(double *)&v11 = v10;
  v13 = cos(x: v11);
  v14 = (float)*(double *)&v13;
  v15 = (float)((float)(result->z * idMath::M_DEG2RAD) * (float)0.5);
  *(double *)&v13 = v15;
  v16 = sin(x: v13);
  v17 = (float)*(double *)&v16;
  *(double *)&v16 = v15;
  v18 = cos(x: v16);
  this->pitch = (float)((float)((float)*(double *)&v18 * (float)v12) * (float)v7)
              - (float)((float)((float)v17 * (float)v14) * (float)v9);
  this->roll = (float)((float)((float)v17 * (float)v12) * (float)v9)
             - (float)((float)((float)*(double *)&v18 * (float)v14) * (float)v7);
  *((float *)this + 3) = (float)((float)((float)v17 * (float)v12) * (float)v7)
                       + (float)((float)((float)*(double *)&v18 * (float)v14) * (float)v9);
  this->yaw = -(float)((float)((float)((float)v17 * (float)v14) * (float)v7)
                     - (float)-(float)((float)((float)*(double *)&v18 * (float)v12) * (float)v9));
  return this;
}


// ========================================================================
// ?ToRotation@idAngles@@QBA?AVidRotation@@XZ
// EA  : 0x82F2FF40
// RVA : 0x00F2FF40
// PDB : w:\tech5\shared\idlib\math\angles.cpp
// ========================================================================

idAngles *__fastcall idAngles::ToRotation(idAngles *this, idRotation *result, long double a3)
{
  double x; // fp1
  double y; // fp13
  double v7; // fp30
  double z; // fp1
  double v10; // fp29
  long double v11; // fp2
  double v12; // fp28
  long double v13; // fp2
  double v14; // fp29
  double v15; // fp27
  long double v16; // fp2
  double v17; // fp26
  long double v18; // fp2
  double v19; // fp27
  double v20; // fp31
  long double v21; // fp2
  double v22; // fp25
  long double v23; // fp2
  double v24; // fp3
  double v25; // fp31
  double v26; // fp12
  double v27; // fp13
  idVec3 v28[6]; // [sp+50h] [-70h] BYREF

  x = result->origin.x;
  y = result->origin.y;
  v7 = 0.0;
  if ( x == 0.0 )
  {
    if ( y == 0.0 )
    {
      v28[0].y = 0.0;
      v28[0].z = 0.0;
      z = result->origin.z;
      v28[0].x = -1.0;
      idRotation::idRotation((idRotation *)this, rotationOrigin: &vec3_origin, rotationVec: v28, rotationAngle: z);
      return this;
    }
    if ( result->origin.z == 0.0 )
    {
      v28[0].x = 0.0;
      v28[0].y = 0.0;
      v28[0].z = -1.0;
      idRotation::idRotation((idRotation *)this, rotationOrigin: &vec3_origin, rotationVec: v28, rotationAngle: y);
      return this;
    }
  }
  else if ( y == 0.0 && result->origin.z == 0.0 )
  {
    v28[0].x = 0.0;
    v28[0].z = 0.0;
    v28[0].y = -1.0;
    idRotation::idRotation((idRotation *)this, rotationOrigin: &vec3_origin, rotationVec: v28, rotationAngle: x);
    return this;
  }
  v10 = (float)((float)(result->origin.y * idMath::M_DEG2RAD) * (float)0.5);
  *(double *)&a3 = v10;
  v11 = sin(x: a3);
  v12 = (float)*(double *)&v11;
  *(double *)&v11 = v10;
  v13 = cos(x: v11);
  v14 = (float)*(double *)&v13;
  v15 = (float)((float)(result->origin.x * idMath::M_DEG2RAD) * (float)0.5);
  *(double *)&v13 = v15;
  v16 = sin(x: v13);
  v17 = (float)*(double *)&v16;
  *(double *)&v16 = v15;
  v18 = cos(x: v16);
  v19 = (float)*(double *)&v18;
  v20 = (float)((float)(result->origin.z * idMath::M_DEG2RAD) * (float)0.5);
  *(double *)&v18 = v20;
  v21 = sin(x: v18);
  v22 = (float)*(double *)&v21;
  *(double *)&v21 = v20;
  v23 = cos(x: v21);
  v24 = (float)((float)((float)*(double *)&v23 * (float)v17) * (float)v14);
  *((double *)&v23 + 1) = (float)((float)((float)*(double *)&v23 * (float)v19) * (float)v12);
  v28[0].x = (float)((float)((float)*(double *)&v23 * (float)v17) * (float)v12)
           - (float)((float)((float)v22 * (float)v19) * (float)v14);
  v28[0].z = (float)((float)((float)v22 * (float)v17) * (float)v14)
           - (float)((float)((float)*(double *)&v23 * (float)v19) * (float)v12);
  *(double *)&v23 = (float)((float)((float)((float)v22 * (float)v17) * (float)v12)
                          + (float)((float)((float)*(double *)&v23 * (float)v19) * (float)v14));
  v28[0].y = -(float)((float)((float)((float)v22 * (float)v19) * (float)v12) - (float)-v24);
  v25 = idMath::ACos(a: v23);
  if ( v25 == 0.0 )
  {
    v26 = 0.0;
    v27 = 1.0;
  }
  else
  {
    idVec3::NormalizeFast(this: v28);
    idVec3::FixDegenerateNormal(this: v28);
    v27 = v28[0].z;
    v26 = v28[0].x;
    v25 = (float)((float)(idMath::M_RAD2DEG * (float)v25) * (float)2.0);
    v7 = v28[0].y;
  }
  *(idVec3 *)this = vec3_origin;
  *((float *)this + 3) = v26;
  *((float *)this + 4) = v7;
  *((float *)this + 5) = v27;
  *((_BYTE *)this + 64) = 0;
  *((float *)this + 6) = v25;
  *(idMat3 *)((char *)this + 28) = mat3_identity;
  return this;
}


// ========================================================================
// ?ToMat3@idAngles@@QBA?AVidMat3@@XZ
// EA  : 0x82F30208
// RVA : 0x00F30208
// PDB : w:\tech5\shared\idlib\math\angles.cpp
// ========================================================================

idAngles *__fastcall idAngles::ToMat3(idAngles *this, idMat3 *result, long double a3)
{
  double v5; // fp31
  long double v6; // fp2
  double v7; // fp30
  long double v8; // fp2
  double v9; // fp31
  double v10; // fp29
  long double v11; // fp2
  double v12; // fp28
  long double v13; // fp2
  double v14; // fp29
  double v15; // fp27
  long double v16; // fp2
  double v17; // fp26
  long double v18; // fp2

  v5 = (float)(result->mat[0].y * idMath::M_DEG2RAD);
  *(double *)&a3 = v5;
  v6 = sin(x: a3);
  v7 = (float)*(double *)&v6;
  *(double *)&v6 = v5;
  v8 = cos(x: v6);
  v9 = (float)*(double *)&v8;
  v10 = (float)(result->mat[0].x * idMath::M_DEG2RAD);
  *(double *)&v8 = v10;
  v11 = sin(x: v8);
  v12 = (float)*(double *)&v11;
  *(double *)&v11 = v10;
  v13 = cos(x: v11);
  v14 = (float)*(double *)&v13;
  v15 = (float)(result->mat[0].z * idMath::M_DEG2RAD);
  *(double *)&v13 = v15;
  v16 = sin(x: v13);
  v17 = (float)*(double *)&v16;
  *(double *)&v16 = v15;
  v18 = cos(x: v16);
  this->pitch = (float)v14 * (float)v9;
  this->yaw = (float)v14 * (float)v7;
  this->roll = -v12;
  *((float *)this + 5) = (float)v17 * (float)v14;
  *((float *)this + 3) = (float)((float)((float)v17 * (float)v12) * (float)v9)
                       - (float)((float)*(double *)&v18 * (float)v7);
  *((float *)this + 4) = (float)((float)((float)v17 * (float)v12) * (float)v7)
                       + (float)((float)*(double *)&v18 * (float)v9);
  *((float *)this + 6) = (float)((float)((float)*(double *)&v18 * (float)v12) * (float)v9)
                       + (float)((float)v17 * (float)v7);
  *((float *)this + 7) = (float)((float)((float)*(double *)&v18 * (float)v12) * (float)v7)
                       - (float)((float)v17 * (float)v9);
  *((float *)this + 8) = (float)*(double *)&v18 * (float)v14;
  return this;
}


// ========================================================================
// ?ToAngularVelocity@idAngles@@QBA?AVidVec3@@XZ
// EA  : 0x82F30308
// RVA : 0x00F30308
// PDB : w:\tech5\shared\idlib\math\angles.cpp
// ========================================================================

idAngles *__fastcall idAngles::ToAngularVelocity(idAngles *this, idRotation *result, long double a3)
{
  idVec3 *v4; // r3
  idAngles v6[6]; // [sp+50h] [-60h] BYREF

  v4 = (idVec3 *)idAngles::ToRotation(this: v6, result, a3);
  idRotation::ToAngularVelocity((idRotation *)this, result: v4);
  return this;
}

