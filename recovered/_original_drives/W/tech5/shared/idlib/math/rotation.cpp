
// ========================================================================
// ?ToMat3@idRotation@@QBAABVidMat3@@XZ
// EA  : 0x82F39B78
// RVA : 0x00F39B78
// PDB : w:\tech5\shared\idlib\math\rotation.cpp
// ========================================================================

const idMat3 *__fastcall idRotation::ToMat3(idRotation *this, long double a2)
{
  double v4; // fp31
  long double v5; // fp2
  double v6; // fp30
  long double v7; // fp2
  double v8; // fp10
  double v9; // fp9
  double v10; // fp8
  double v11; // fp5
  double v12; // fp6
  double v13; // fp7
  double v14; // fp4
  double v15; // fp3

  if ( this->axisValid )
    return &this->axis;
  v4 = (float)((float)(idMath::M_DEG2RAD * (float)0.5) * this->angle);
  *(double *)&a2 = v4;
  v5 = sin(x: a2);
  v6 = (float)*(double *)&v5;
  *(double *)&v5 = v4;
  v7 = cos(x: v5);
  v8 = (float)((float)((float)(this->vec.y * (float)v6) * (float)2.0) * (float)(this->vec.x * (float)v6));
  v9 = (float)((float)((float)(this->vec.z * (float)v6) * (float)2.0) * (float)(this->vec.x * (float)v6));
  v10 = (float)((float)((float)(this->vec.z * (float)v6) * (float)2.0) * (float)(this->vec.y * (float)v6));
  v11 = (float)((float)((float)(this->vec.z * (float)v6) * (float)2.0) * (float)*(double *)&v7);
  v12 = (float)((float)((float)(this->vec.y * (float)v6) * (float)2.0) * (float)*(double *)&v7);
  v13 = (float)((float)((float)(this->vec.x * (float)v6) * (float)2.0) * (float)*(double *)&v7);
  v14 = (float)((float)((float)((float)(this->vec.y * (float)v6) * (float)2.0) * (float)(this->vec.y * (float)v6))
              + (float)((float)((float)(this->vec.x * (float)v6) * (float)2.0) * (float)(this->vec.x * (float)v6)));
  v15 = (float)((float)((float)((float)(this->vec.z * (float)v6) * (float)2.0) * (float)(this->vec.z * (float)v6))
              + (float)((float)((float)(this->vec.y * (float)v6) * (float)2.0) * (float)(this->vec.y * (float)v6)));
  *((double *)&v7 + 1) = (float)((float)((float)((float)(this->vec.z * (float)v6) * (float)2.0)
                                       * (float)(this->vec.z * (float)v6))
                               + (float)((float)((float)(this->vec.x * (float)v6) * (float)2.0)
                                       * (float)(this->vec.x * (float)v6)));
  this->axis.mat[0].y = (float)((float)((float)(this->vec.y * (float)v6) * (float)2.0) * (float)(this->vec.x * (float)v6))
                      - (float)((float)((float)(this->vec.z * (float)v6) * (float)2.0) * (float)*(double *)&v7);
  this->axis.mat[1].x = (float)v11 + (float)v8;
  this->axis.mat[0].z = (float)v12 + (float)v9;
  this->axis.mat[2].x = (float)v9 - (float)v12;
  this->axis.mat[1].z = (float)v10 - (float)v13;
  this->axis.mat[2].y = (float)v13 + (float)v10;
  this->axis.mat[0].x = (float)1.0 - (float)v15;
  this->axis.mat[1].y = (float)1.0 - (float)*((double *)&v7 + 1);
  this->axis.mat[2].z = (float)1.0 - (float)v14;
  this->axisValid = true;
  return &this->axis;
}


// ========================================================================
// ?Normalize180@idRotation@@QAAXXZ
// EA  : 0x82F39CB0
// RVA : 0x00F39CB0
// PDB : w:\tech5\shared\idlib\math\rotation.cpp
// ========================================================================

void __fastcall idRotation::Normalize180(idRotation *this, long double a2)
{
  long double v3; // fp2
  double v4; // fp0
  double v5; // fp0

  *(double *)&a2 = (float)(this->angle * (float)0.0027777778);
  v3 = floor(x: a2);
  v4 = (float)-(float)((float)((float)*(double *)&v3 * (float)360.0) - this->angle);
  this->angle = -(float)((float)((float)*(double *)&v3 * (float)360.0) - this->angle);
  if ( v4 <= 180.0 )
  {
    if ( v4 >= -180.0 )
      return;
    v5 = (float)((float)v4 + (float)360.0);
  }
  else
  {
    v5 = (float)((float)v4 - (float)360.0);
  }
  this->angle = v5;
}


// ========================================================================
// ?ToAngles@idRotation@@QBA?AVidAngles@@XZ
// EA  : 0x82F39D38
// RVA : 0x00F39D38
// PDB : w:\tech5\shared\idlib\math\rotation.cpp
// ========================================================================

idRotation *__fastcall idRotation::ToAngles(idRotation *this, idRotation *result, long double a3)
{
  idAngles *v4; // r3
  long double v5; // fp4
  double v6; // fp2
  double v7; // fp1

  v4 = (idAngles *)idRotation::ToMat3(this: result, a2: a3);
  idMat3::ToAngles((idMat3 *)this, result: v4, a3: v7, a4: v6, a5: v5);
  return this;
}


// ========================================================================
// ?ToAngularVelocity@idRotation@@QBA?AVidVec3@@XZ
// EA  : 0x82F39D78
// RVA : 0x00F39D78
// PDB : w:\tech5\shared\idlib\math\rotation.cpp
// ========================================================================

idRotation *__fastcall idRotation::ToAngularVelocity(idRotation *this, idVec3 *result)
{
  double y; // fp11
  double z; // fp10
  double v4; // fp8

  y = result[1].y;
  z = result[1].z;
  v4 = -(float)(result[2].x * idMath::M_DEG2RAD);
  this->origin.x = result[1].x * (float)v4;
  this->origin.y = (float)y * (float)v4;
  this->origin.z = (float)z * (float)v4;
  return this;
}

