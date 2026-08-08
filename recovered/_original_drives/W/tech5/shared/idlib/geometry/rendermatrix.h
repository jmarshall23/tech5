
// ========================================================================
// ?TransformPoint@idRenderMatrix@@QBAXABVidVec3@@AAVidVec4@@@Z
// EA  : 0x827D2BC8
// RVA : 0x007D2BC8
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.h
// ========================================================================

void __fastcall idRenderMatrix::TransformPoint(idRenderMatrix *this, const idVec3 *in, idVec4 *out)
{
  out->x = (float)((float)(in->x * this->m[0]) + (float)((float)(this->m[2] * in->z) + (float)(this->m[1] * in->y)))
         + this->m[3];
  out->y = (float)((float)(this->m[5] * in->y) + (float)((float)(this->m[4] * in->x) + (float)(this->m[6] * in->z)))
         + this->m[7];
  out->z = (float)((float)(this->m[9] * in->y) + (float)((float)(this->m[8] * in->x) + (float)(this->m[10] * in->z)))
         + this->m[11];
  out->w = (float)((float)(this->m[13] * in->y) + (float)((float)(this->m[12] * in->x) + (float)(this->m[14] * in->z)))
         + this->m[15];
}


// ========================================================================
// ?FromOriginAxisScale@idRenderMatrix@@SAXABVidVec3@@ABVidMat3@@0AAV1@@Z
// EA  : 0x827F2950
// RVA : 0x007F2950
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.h
// ========================================================================

void __fastcall idRenderMatrix::FromOriginAxisScale(
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *scale,
        idRenderMatrix *out)
{
  out->m[0] = axis->mat[0].x * scale->x;
  out->m[1] = axis->mat[1].x * scale->y;
  out->m[2] = axis->mat[2].x * scale->z;
  out->m[3] = origin->x;
  out->m[4] = axis->mat[0].y * scale->x;
  out->m[5] = axis->mat[1].y * scale->y;
  out->m[6] = axis->mat[2].y * scale->z;
  out->m[7] = origin->y;
  out->m[8] = axis->mat[0].z * scale->x;
  out->m[9] = axis->mat[1].z * scale->y;
  out->m[10] = axis->mat[2].z * scale->z;
  out->m[11] = origin->z;
  out->m[12] = 0.0;
  out->m[13] = 0.0;
  out->m[14] = 0.0;
  out->m[15] = 1.0;
}


// ========================================================================
// ?TransformPoint@idRenderMatrix@@QBAXABVidVec4@@AAV2@@Z
// EA  : 0x828BFB58
// RVA : 0x008BFB58
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.h
// ========================================================================

void __fastcall idRenderMatrix::TransformPoint(idRenderMatrix *this, const idVec4 *in, idVec4 *out)
{
  out->x = (float)(in->x * this->m[0])
         + (float)((float)(this->m[2] * in->z) + (float)((float)(this->m[1] * in->y) + (float)(this->m[3] * in->w)));
  out->y = (float)(this->m[6] * in->z)
         + (float)((float)(this->m[7] * in->w) + (float)((float)(this->m[4] * in->x) + (float)(this->m[5] * in->y)));
  out->z = (float)(this->m[10] * in->z)
         + (float)((float)(this->m[11] * in->w) + (float)((float)(this->m[8] * in->x) + (float)(this->m[9] * in->y)));
  out->w = (float)(this->m[14] * in->z)
         + (float)((float)(this->m[15] * in->w) + (float)((float)(this->m[12] * in->x) + (float)(this->m[13] * in->y)));
}


// ========================================================================
// ?TransformDir@idRenderMatrix@@QBAXABVidVec3@@AAV2@_N@Z
// EA  : 0x828DB8B0
// RVA : 0x008DB8B0
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.h
// ========================================================================

void __fastcall idRenderMatrix::TransformDir(idRenderMatrix *this, const idVec3 *in, idVec3 *out, bool normalize)
{
  double v4; // fp0
  double v5; // fp13
  double v6; // fp12
  double v9; // fp2
  double v10; // fp5
  double v11; // fp2

  v4 = (float)((float)(in->x * this->m[0]) + (float)((float)(this->m[1] * in->y) + (float)(this->m[2] * in->z)));
  v5 = (float)((float)(this->m[6] * in->z) + (float)((float)(this->m[4] * in->x) + (float)(this->m[5] * in->y)));
  v6 = (float)((float)(this->m[10] * in->z) + (float)((float)(this->m[8] * in->x) + (float)(this->m[9] * in->y)));
  if ( normalize )
  {
    _FP5 = (float)((float)((float)((float)v4 * (float)v4)
                         + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f5, f6, f10 }
    v9 = __frsqrte(_FP3);
    v10 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v9
                                                                                        * (float)((float)((float)((float)v4 * (float)v4) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                                * (float)0.5))
                                                                                * (float)v9)
                                                                        - (float)1.5)
                                                        * (float)v9)
                                                * (float)((float)((float)((float)v4 * (float)v4)
                                                                + (float)((float)((float)v6 * (float)v6)
                                                                        + (float)((float)v5 * (float)v5)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v9
                                                                                * (float)((float)((float)((float)v4 * (float)v4)
                                                                                                + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                        * (float)0.5))
                                                                        * (float)v9)
                                                                - (float)1.5)
                                                * (float)v9))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v9
                                                        * (float)((float)((float)((float)v4 * (float)v4)
                                                                        + (float)((float)((float)v6 * (float)v6)
                                                                                + (float)((float)v5 * (float)v5)))
                                                                * (float)0.5))
                                                * (float)v9)
                                        - (float)1.5)
                        * (float)v9));
    v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v9 * (float)((float)((float)((float)v4 * (float)v4) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5)) * (float)v9) - (float)1.5)
                                                                                                * (float)v9)
                                                                                        * (float)((float)((float)((float)v4 * (float)v4) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v9 * (float)((float)((float)((float)v4 * (float)v4) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5)) * (float)v9) - (float)1.5)
                                                                                        * (float)v9))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v9
                                                                                                * (float)((float)((float)((float)v4 * (float)v4) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5))
                                                                                        * (float)v9)
                                                                                - (float)1.5)
                                                                * (float)v9))
                                                * (float)((float)((float)((float)v4 * (float)v4)
                                                                + (float)((float)((float)v6 * (float)v6)
                                                                        + (float)((float)v5 * (float)v5)))
                                                        * (float)0.5))
                                        * (float)v10)
                                - (float)1.5)
                * (float)v10);
    v4 = (float)((float)v11
               * (float)((float)(in->x * this->m[0]) + (float)((float)(this->m[1] * in->y) + (float)(this->m[2] * in->z))));
    v5 = (float)((float)v11
               * (float)((float)(this->m[6] * in->z) + (float)((float)(this->m[4] * in->x) + (float)(this->m[5] * in->y))));
    v6 = (float)((float)v11
               * (float)((float)(this->m[10] * in->z)
                       + (float)((float)(this->m[8] * in->x) + (float)(this->m[9] * in->y))));
  }
  out->x = v4;
  out->y = v5;
  out->z = v6;
}


// ========================================================================
// ?InverseTransformPlane@idRenderMatrix@@QBAXABVidPlane@@AAV2@_N@Z
// EA  : 0x828DB988
// RVA : 0x008DB988
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.h
// ========================================================================

void __fastcall idRenderMatrix::InverseTransformPlane(
        idRenderMatrix *this,
        const idPlane *in,
        idPlane *out,
        bool normalize)
{
  double v4; // fp0
  double v5; // fp13
  double v6; // fp12
  double v7; // fp10
  double v10; // fp1
  double v11; // fp2
  double v12; // fp1

  v4 = (float)((float)(in->a * this->m[0])
             + (float)((float)(this->m[12] * in->d) + (float)((float)(this->m[4] * in->b) + (float)(this->m[8] * in->c))));
  v5 = (float)((float)(this->m[13] * in->d)
             + (float)((float)(this->m[9] * in->c) + (float)((float)(this->m[1] * in->a) + (float)(this->m[5] * in->b))));
  v6 = (float)((float)(this->m[14] * in->d)
             + (float)((float)(this->m[10] * in->c) + (float)((float)(this->m[2] * in->a) + (float)(this->m[6] * in->b))));
  v7 = (float)((float)(this->m[15] * in->d)
             + (float)((float)(this->m[11] * in->c) + (float)((float)(this->m[3] * in->a) + (float)(this->m[7] * in->b))));
  if ( normalize )
  {
    _FP4 = (float)((float)((float)((float)v4 * (float)v4)
                         + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f2, f4, f5, f9 }
    v10 = __frsqrte(_FP2);
    v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                        * (float)((float)((float)((float)v4 * (float)v4) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                                * (float)0.5))
                                                                                * (float)v10)
                                                                        - (float)1.5)
                                                        * (float)v10)
                                                * (float)((float)((float)((float)v4 * (float)v4)
                                                                + (float)((float)((float)v6 * (float)v6)
                                                                        + (float)((float)v5 * (float)v5)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v10
                                                                                * (float)((float)((float)((float)v4 * (float)v4)
                                                                                                + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                        * (float)0.5))
                                                                        * (float)v10)
                                                                - (float)1.5)
                                                * (float)v10))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v10
                                                        * (float)((float)((float)((float)v4 * (float)v4)
                                                                        + (float)((float)((float)v6 * (float)v6)
                                                                                + (float)((float)v5 * (float)v5)))
                                                                * (float)0.5))
                                                * (float)v10)
                                        - (float)1.5)
                        * (float)v10));
    v12 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                                * (float)((float)((float)((float)v4 * (float)v4) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5))
                                                                                        * (float)v10)
                                                                                - (float)1.5)
                                                                * (float)v10)
                                                        * (float)((float)((float)((float)v4 * (float)v4)
                                                                        + (float)((float)((float)v6 * (float)v6)
                                                                                + (float)((float)v5 * (float)v5)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v10
                                                                                        * (float)((float)((float)((float)v4 * (float)v4) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                                * (float)0.5))
                                                                                * (float)v10)
                                                                        - (float)1.5)
                                                        * (float)v10))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v10
                                                                * (float)((float)((float)((float)v4 * (float)v4)
                                                                                + (float)((float)((float)v6 * (float)v6)
                                                                                        + (float)((float)v5 * (float)v5)))
                                                                        * (float)0.5))
                                                        * (float)v10)
                                                - (float)1.5)
                                * (float)v10))
                * (float)((float)((float)((float)v4 * (float)v4)
                                + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                        * (float)0.5));
    v4 = (float)((float)((float)-(float)((float)((float)v12 * (float)v11) - (float)1.5) * (float)v11)
               * (float)((float)(in->a * this->m[0])
                       + (float)((float)(this->m[12] * in->d)
                               + (float)((float)(this->m[4] * in->b) + (float)(this->m[8] * in->c)))));
    v5 = (float)((float)((float)-(float)((float)((float)v12 * (float)v11) - (float)1.5) * (float)v11)
               * (float)((float)(this->m[13] * in->d)
                       + (float)((float)(this->m[9] * in->c)
                               + (float)((float)(this->m[1] * in->a) + (float)(this->m[5] * in->b)))));
    v6 = (float)((float)((float)-(float)((float)((float)v12 * (float)v11) - (float)1.5) * (float)v11)
               * (float)((float)(this->m[14] * in->d)
                       + (float)((float)(this->m[10] * in->c)
                               + (float)((float)(this->m[2] * in->a) + (float)(this->m[6] * in->b)))));
    v7 = (float)((float)((float)-(float)((float)((float)v12 * (float)v11) - (float)1.5) * (float)v11)
               * (float)((float)(this->m[15] * in->d)
                       + (float)((float)(this->m[11] * in->c)
                               + (float)((float)(this->m[3] * in->a) + (float)(this->m[7] * in->b)))));
  }
  out->a = v4;
  out->b = v5;
  out->c = v6;
  out->d = v7;
}


// ========================================================================
// ?ModelViewFromOriginAxis@idRenderMatrix@@SAXABVidVec3@@ABVidMat3@@AAV1@@Z
// EA  : 0x82956398
// RVA : 0x00956398
// PDB : w:\tech5\shared\idlib\geometry\rendermatrix.h
// ========================================================================

void __fastcall idRenderMatrix::ModelViewFromOriginAxis(const idVec3 *origin, const idMat3 *axis, idRenderMatrix *out)
{
  double v3; // fp13
  double v4; // fp10
  double v5; // fp8
  double x; // fp12
  double y; // fp11
  double z; // fp10
  double v9; // fp12
  double v10; // fp9
  double v11; // fp6
  double v12; // fp12

  v3 = -axis->mat[1].x;
  out->m[0] = v3;
  v4 = -axis->mat[1].y;
  out->m[1] = v4;
  v5 = -axis->mat[1].z;
  out->m[2] = v5;
  out->m[3] = -(float)((float)((float)v5 * origin->z)
                     + (float)((float)((float)v4 * origin->y) + (float)(origin->x * (float)v3)));
  x = axis->mat[2].x;
  out->m[4] = axis->mat[2].x;
  y = axis->mat[2].y;
  out->m[5] = axis->mat[2].y;
  z = axis->mat[2].z;
  out->m[6] = axis->mat[2].z;
  out->m[7] = -(float)((float)((float)x * origin->x)
                     + (float)((float)((float)y * origin->y) + (float)((float)z * origin->z)));
  v9 = -axis->mat[0].x;
  out->m[8] = v9;
  v10 = -axis->mat[0].y;
  out->m[9] = v10;
  v11 = -axis->mat[0].z;
  out->m[10] = v11;
  v12 = (float)-(float)((float)(origin->y * (float)v10)
                      + (float)((float)((float)v11 * origin->z) + (float)((float)v9 * origin->x)));
  out->m[12] = 0.0;
  out->m[13] = 0.0;
  out->m[14] = 0.0;
  out->m[15] = 1.0;
  out->m[11] = v12;
}

