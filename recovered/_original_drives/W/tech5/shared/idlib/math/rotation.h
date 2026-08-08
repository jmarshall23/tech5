
// ========================================================================
// ?RotatePoint@idRotation@@QBAXAAVidVec3@@@Z
// EA  : 0x825D3F48
// RVA : 0x005D3F48
// PDB : w:\tech5\shared\idlib\math\rotation.h
// ========================================================================

void __fastcall idRotation::RotatePoint(idRotation *this, idVec3 *point)
{
  double y; // fp0
  double z; // fp13
  double v6; // fp9
  double v7; // fp7

  if ( !this->axisValid )
    idRotation::ToMat3(this);
  y = this->origin.y;
  z = this->origin.z;
  v6 = (float)((float)(this->axis.mat[1].y * (float)(point->y - this->origin.y))
             + (float)((float)(this->axis.mat[0].y * (float)(point->x - this->origin.x))
                     + (float)(this->axis.mat[2].y * (float)(point->z - this->origin.z))));
  v7 = (float)((float)(this->axis.mat[1].z * (float)(point->y - this->origin.y))
             + (float)((float)(this->axis.mat[0].z * (float)(point->x - this->origin.x))
                     + (float)(this->axis.mat[2].z * (float)(point->z - this->origin.z))));
  point->x = this->origin.x
           + (float)((float)(this->axis.mat[0].x * (float)(point->x - this->origin.x))
                   + (float)((float)(this->axis.mat[2].x * (float)(point->z - this->origin.z))
                           + (float)(this->axis.mat[1].x * (float)(point->y - this->origin.y))));
  point->y = (float)y + (float)v6;
  point->z = (float)z + (float)v7;
}


// ========================================================================
// ?RotateAxis@idRotation@@QBAXAAVidMat3@@@Z
// EA  : 0x825D4018
// RVA : 0x005D4018
// PDB : w:\tech5\shared\idlib\math\rotation.h
// ========================================================================

void __fastcall idRotation::RotateAxis(idRotation *this, idMat3 *axis)
{
  if ( !this->axisValid )
    idRotation::ToMat3(this);
  idMat3::operator*=(this: axis, a: &this->axis);
}


// ========================================================================
// ??0idRotation@@QAA@ABVidVec3@@0M@Z
// EA  : 0x825D9A98
// RVA : 0x005D9A98
// PDB : w:\tech5\shared\idlib\math\rotation.h
// ========================================================================

idRotation *__fastcall idRotation::idRotation(
        idRotation *this,
        const idVec3 *rotationOrigin,
        const idVec3 *rotationVec,
        double rotationAngle)
{
  this->origin = *rotationOrigin;
  this->vec = *rotationVec;
  this->axisValid = false;
  this->angle = rotationAngle;
  this->axis = mat3_identity;
  return this;
}


// ========================================================================
// ??DidRotation@@QBA?AVidVec3@@ABV1@@Z
// EA  : 0x826C91D8
// RVA : 0x006C91D8
// PDB : w:\tech5\shared\idlib\math\rotation.h
// ========================================================================

idRotation *__fastcall idRotation::operator*(idRotation *this, idRotation *result, const idVec3 *v)
{
  double z; // fp13
  double x; // fp8
  double v9; // fp4
  double v10; // fp5

  if ( !result->axisValid )
    idRotation::ToMat3(this: result);
  z = result->origin.z;
  x = result->origin.x;
  v9 = (float)((float)(result->axis.mat[2].z * (float)(v->z - result->origin.z))
             + (float)((float)(result->axis.mat[0].z * (float)(v->x - result->origin.x))
                     + (float)(result->axis.mat[1].z * (float)(v->y - result->origin.y))));
  v10 = (float)((float)(result->axis.mat[0].x * (float)(v->x - result->origin.x))
              + (float)((float)(result->axis.mat[1].x * (float)(v->y - result->origin.y))
                      + (float)(result->axis.mat[2].x * (float)(v->z - result->origin.z))));
  this->origin.y = result->origin.y
                 + (float)((float)(result->axis.mat[2].y * (float)(v->z - result->origin.z))
                         + (float)((float)(result->axis.mat[0].y * (float)(v->x - result->origin.x))
                                 + (float)(result->axis.mat[1].y * (float)(v->y - result->origin.y))));
  this->origin.z = (float)z + (float)v9;
  this->origin.x = (float)x + (float)v10;
  return this;
}


// ========================================================================
// ??X@YAAAVidVec3@@AAV0@ABVidRotation@@@Z
// EA  : 0x8271B5D0
// RVA : 0x0071B5D0
// PDB : w:\tech5\shared\idlib\math\rotation.h
// ========================================================================

idVec3 *__fastcall operator*=(idVec3 *v, idRotation *r)
{
  char v4; // [sp+50h] [-20h] BYREF

  *v = idRotation::operator*(this: (idRotation *)&v4, result: r, v)->origin;
  return v;
}


// ========================================================================
// ??GidRotation@@QBA?AV0@XZ
// EA  : 0x82765A90
// RVA : 0x00765A90
// PDB : w:\tech5\shared\idlib\math\rotation.h
// ========================================================================

idRotation *__fastcall idRotation::operator-(idRotation *this, idRotation *result)
{
  double angle; // fp0

  angle = result->angle;
  this->origin = result->origin;
  this->vec = result->vec;
  this->axisValid = false;
  this->angle = -angle;
  this->axis = mat3_identity;
  return this;
}

