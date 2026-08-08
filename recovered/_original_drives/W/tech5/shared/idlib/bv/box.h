
// ========================================================================
// ??0idBox@@QAA@ABVidBounds@@ABVidVec3@@ABVidMat3@@@Z
// EA  : 0x825D9B30
// RVA : 0x005D9B30
// PDB : w:\tech5\shared\idlib\bv\box.h
// ========================================================================

idBox *__fastcall idBox::idBox(idBox *this, const idBounds *bounds, const idVec3 *origin, const idMat3 *axis)
{
  double v4; // fp8
  double v5; // fp6
  double v6; // fp5
  double y; // fp1
  double z; // fp0
  double x; // fp0
  double v10; // fp13
  double v11; // fp2
  double v12; // fp3

  v4 = (float)(bounds->b[0].y + bounds->b[1].y);
  v5 = (float)(bounds->b[0].z + bounds->b[1].z);
  v6 = (float)((float)(bounds->b[0].x + bounds->b[1].x) * (float)0.5);
  this->center.x = (float)(bounds->b[0].x + bounds->b[1].x) * (float)0.5;
  this->center.y = (float)v4 * (float)0.5;
  this->center.z = (float)v5 * (float)0.5;
  y = bounds->b[1].y;
  z = bounds->b[1].z;
  this->extents.x = bounds->b[1].x - (float)v6;
  this->extents.z = (float)z - (float)((float)v5 * (float)0.5);
  this->extents.y = (float)y - (float)((float)v4 * (float)0.5);
  x = origin->x;
  v10 = origin->y;
  v11 = (float)((float)(axis->mat[0].y * this->center.x)
              + (float)((float)(axis->mat[2].y * this->center.z) + (float)(axis->mat[1].y * this->center.y)));
  v12 = (float)((float)(this->center.y * axis->mat[1].x)
              + (float)((float)(this->center.x * axis->mat[0].x) + (float)(this->center.z * axis->mat[2].x)));
  this->center.z = origin->z
                 + (float)((float)(this->center.x * axis->mat[0].z)
                         + (float)((float)(axis->mat[2].z * this->center.z) + (float)(axis->mat[1].z * this->center.y)));
  this->center.y = (float)v10 + (float)v11;
  this->center.x = (float)x + (float)v12;
  this->axis = *axis;
  return this;
}


// ========================================================================
// ??0idBox@@QAA@ABVidBounds@@@Z
// EA  : 0x829437C8
// RVA : 0x009437C8
// PDB : w:\tech5\shared\idlib\bv\box.h
// ========================================================================

idBox *__fastcall idBox::idBox(idBox *this, const idBounds *bounds)
{
  double v2; // fp8
  double v3; // fp6
  double v4; // fp5
  double y; // fp1
  double z; // fp13

  v2 = (float)(bounds->b[0].y + bounds->b[1].y);
  v3 = (float)(bounds->b[0].z + bounds->b[1].z);
  v4 = (float)((float)(bounds->b[0].x + bounds->b[1].x) * (float)0.5);
  this->center.x = (float)(bounds->b[0].x + bounds->b[1].x) * (float)0.5;
  this->center.y = (float)v2 * (float)0.5;
  this->center.z = (float)v3 * (float)0.5;
  y = bounds->b[1].y;
  z = bounds->b[1].z;
  this->extents.x = bounds->b[1].x - (float)v4;
  this->extents.z = (float)z - (float)((float)v3 * (float)0.5);
  this->extents.y = (float)y - (float)((float)v2 * (float)0.5);
  this->axis.mat[2].z = 1.0;
  this->axis.mat[1].y = 1.0;
  this->axis.mat[0].x = 1.0;
  this->axis.mat[1].z = 0.0;
  this->axis.mat[0].z = 0.0;
  this->axis.mat[0].y = 0.0;
  this->axis.mat[2].y = 0.0;
  this->axis.mat[2].x = 0.0;
  this->axis.mat[1].x = 0.0;
  return this;
}


// ========================================================================
// ?ContainsPoint@idBox@@QBA_NABVidVec3@@@Z
// EA  : 0x82DF98F0
// RVA : 0x00DF98F0
// PDB : w:\tech5\shared\idlib\bv\box.h
// ========================================================================

int __fastcall idBox::ContainsPoint(idBox *this, const idVec3 *p)
{
  double z; // fp7
  int result; // r3
  double v4; // fp5

  if ( __fabs((float)((float)(this->axis.mat[0].x * (float)(p->x - this->center.x))
                    + (float)((float)(this->axis.mat[0].y * (float)(p->y - this->center.y))
                            + (float)(this->axis.mat[0].z * (float)(p->z - this->center.z))))) > this->extents.x )
    return 0;
  if ( __fabs((float)((float)(this->axis.mat[1].x * (float)(p->x - this->center.x))
                    + (float)((float)(this->axis.mat[1].y * (float)(p->y - this->center.y))
                            + (float)(this->axis.mat[1].z * (float)(p->z - this->center.z))))) > this->extents.y )
    return 0;
  z = this->extents.z;
  v4 = (float)((float)((float)(p->x - this->center.x) * this->axis.mat[2].x)
             + (float)((float)(this->axis.mat[2].y * (float)(p->y - this->center.y))
                     + (float)(this->axis.mat[2].z * (float)(p->z - this->center.z))));
  result = 1;
  if ( __fabs(v4) > z )
    return 0;
  return result;
}


// ========================================================================
// ?AxisProjection@idBox@@QBAXABVidMat3@@AAVidBounds@@@Z
// EA  : 0x82EF8648
// RVA : 0x00EF8648
// PDB : w:\tech5\shared\idlib\bv\box.h
// ========================================================================

void __fastcall idBox::AxisProjection(idBox *this, const idMat3 *ax, idBounds *bounds)
{
  float *p_z; // r10
  int v4; // ctr
  float *p_x; // r11
  double v6; // fp12
  double v7; // fp13
  double v8; // fp10
  double v9; // fp8
  double v10; // fp7
  double v11; // fp6

  p_z = &bounds->b[0].z;
  v4 = 3;
  p_x = &ax[-1].mat[2].x;
  do
  {
    v6 = p_x[4];
    v7 = p_x[5];
    p_x += 3;
    v8 = (float)((float)(*p_x * this->center.x)
               + (float)((float)((float)v7 * this->center.z) + (float)(this->center.y * (float)v6)));
    v9 = __fabs((float)((float)((float)((float)v6 * this->axis.mat[0].y)
                              + (float)((float)((float)v7 * this->axis.mat[0].z) + (float)(this->axis.mat[0].x * *p_x)))
                      * this->extents.x));
    v10 = __fabs((float)((float)((float)(*p_x * this->axis.mat[1].x)
                               + (float)((float)((float)v7 * this->axis.mat[1].z)
                                       + (float)((float)v6 * this->axis.mat[1].y)))
                       * this->extents.y));
    v11 = __fabs((float)((float)((float)(this->axis.mat[2].z * (float)v7)
                               + (float)((float)((float)v6 * this->axis.mat[2].y) + (float)(*p_x * this->axis.mat[2].x)))
                       * this->extents.z));
    *(p_z - 2) = (float)((float)(*p_x * this->center.x)
                       + (float)((float)((float)v7 * this->center.z) + (float)(this->center.y * (float)v6)))
               - (float)((float)((float)v9 + (float)v10) + (float)v11);
    *++p_z = (float)((float)((float)v9 + (float)v10) + (float)v11) + (float)v8;
    --v4;
  }
  while ( v4 != 0 );
}

