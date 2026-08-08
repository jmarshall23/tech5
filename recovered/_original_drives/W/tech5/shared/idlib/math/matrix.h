
// ========================================================================
// ??XidMat3@@QAAAAV0@ABV0@@Z
// EA  : 0x825D3E20
// RVA : 0x005D3E20
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

idMat3 *__fastcall idMat3::operator*=(idMat3 *this, const idMat3 *a)
{
  double y; // fp13
  double z; // fp0
  double v4; // fp1
  double v5; // fp11
  double v6; // fp9
  double v7; // fp8
  double v8; // fp4
  double v9; // fp1
  double x; // fp11
  double v11; // fp10
  double v12; // fp13
  double v13; // fp12
  double v14; // fp3
  double v15; // fp12
  double v16; // fp11
  double v17; // fp10
  double v18; // fp2
  double v19; // fp1

  y = this->mat[0].y;
  z = this->mat[0].z;
  v4 = a->mat[2].y;
  v5 = a->mat[1].z;
  v6 = (float)((float)(this->mat[0].y * a->mat[1].y) + (float)(this->mat[0].x * a->mat[0].y));
  v7 = (float)((float)(this->mat[0].x * a->mat[0].z) + (float)(this->mat[0].z * a->mat[2].z));
  this->mat[0].x = (float)(this->mat[0].z * a->mat[2].x)
                 + (float)((float)(this->mat[0].x * a->mat[0].x) + (float)(this->mat[0].y * a->mat[1].x));
  this->mat[0].y = (float)((float)z * (float)v4) + (float)v6;
  this->mat[0].z = (float)((float)y * (float)v5) + (float)v7;
  v8 = this->mat[1].y;
  v9 = this->mat[1].z;
  x = a->mat[2].x;
  v11 = a->mat[1].y;
  v12 = (float)((float)(a->mat[2].y * this->mat[1].z) + (float)(a->mat[0].y * this->mat[1].x));
  v13 = (float)((float)(a->mat[0].x * this->mat[1].x) + (float)(a->mat[1].x * this->mat[1].y));
  this->mat[1].z = (float)(a->mat[2].z * this->mat[1].z)
                 + (float)((float)(a->mat[1].z * this->mat[1].y) + (float)(a->mat[0].z * this->mat[1].x));
  this->mat[1].y = (float)((float)v8 * (float)v11) + (float)v12;
  this->mat[1].x = (float)((float)x * (float)v9) + (float)v13;
  v14 = this->mat[2].z;
  v15 = a->mat[1].y;
  v16 = a->mat[2].z;
  v17 = this->mat[2].y;
  v18 = (float)((float)(a->mat[2].y * this->mat[2].z) + (float)(a->mat[0].y * this->mat[2].x));
  v19 = (float)((float)(a->mat[1].z * this->mat[2].y) + (float)(a->mat[0].z * this->mat[2].x));
  this->mat[2].x = (float)(a->mat[2].x * this->mat[2].z)
                 + (float)((float)(a->mat[0].x * this->mat[2].x) + (float)(a->mat[1].x * this->mat[2].y));
  this->mat[2].y = (float)((float)v17 * (float)v15) + (float)v18;
  this->mat[2].z = (float)((float)v16 * (float)v14) + (float)v19;
  return this;
}


// ========================================================================
// ?OrthoNormalizeSelf@idMat3@@QAAAAV1@XZ
// EA  : 0x825DCBC0
// RVA : 0x005DCBC0
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

idMat3 *__fastcall idMat3::OrthoNormalizeSelf(idMat3 *this)
{
  double x; // fp9
  double z; // fp8
  double v5; // fp2
  double v6; // fp3
  double v7; // fp1
  double v8; // fp12
  double v9; // fp11
  double v10; // fp11
  double v11; // fp5
  double v12; // fp4
  double v13; // fp2
  double v15; // fp8
  double v17; // fp6
  double v18; // fp11
  double v19; // fp1
  double v20; // fp11
  double v21; // fp10
  double v22; // fp4
  double v23; // fp1
  double v24; // fp10
  double v26; // fp8
  double v28; // fp6
  double v29; // fp12
  double v30; // fp10
  double v31; // fp8

  x = this->mat[0].x;
  z = this->mat[0].z;
  _FP5 = (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                       + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f12 }
  v5 = __frsqrte(_FP3);
  v6 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5
                                                                                     * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y)))
                                                                                             * (float)0.5))
                                                                             * (float)v5)
                                                                     - (float)1.5)
                                                     * (float)v5)
                                             * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                             + (float)((float)(this->mat[0].x * this->mat[0].x)
                                                                     + (float)(this->mat[0].y * this->mat[0].y)))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v5
                                                                             * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                                                             + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y)))
                                                                                     * (float)0.5))
                                                                     * (float)v5)
                                                             - (float)1.5)
                                             * (float)v5))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v5
                                                     * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                                     + (float)((float)(this->mat[0].x * this->mat[0].x)
                                                                             + (float)(this->mat[0].y * this->mat[0].y)))
                                                             * (float)0.5))
                                             * (float)v5)
                                     - (float)1.5)
                     * (float)v5));
  v7 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y))) * (float)0.5)) * (float)v5) - (float)1.5)
                                                                                     * (float)v5)
                                                                             * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                                                             + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y)))
                                                                                     * (float)0.5))
                                                                     * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y))) * (float)0.5)) * (float)v5)
                                                                                             - (float)1.5)
                                                                             * (float)v5))
                                                             - (float)1.5)
                                             * (float)((float)-(float)((float)((float)((float)v5
                                                                                     * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y)))
                                                                                             * (float)0.5))
                                                                             * (float)v5)
                                                                     - (float)1.5)
                                                     * (float)v5))
                                     * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                     + (float)((float)(this->mat[0].x * this->mat[0].x)
                                                             + (float)(this->mat[0].y * this->mat[0].y)))
                                             * (float)0.5))
                             * (float)v6)
                     - (float)1.5);
  v8 = (float)((float)v7
             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5
                                                                                             * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y))) * (float)0.5))
                                                                                     * (float)v5)
                                                                             - (float)1.5)
                                                             * (float)v5)
                                                     * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                                     + (float)((float)(this->mat[0].x * this->mat[0].x)
                                                                             + (float)(this->mat[0].y * this->mat[0].y)))
                                                             * (float)0.5))
                                             * (float)((float)-(float)((float)((float)((float)v5
                                                                                     * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y)))
                                                                                             * (float)0.5))
                                                                             * (float)v5)
                                                                     - (float)1.5)
                                                     * (float)v5))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)v5
                                                             * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                                             + (float)((float)(this->mat[0].x
                                                                                             * this->mat[0].x)
                                                                                     + (float)(this->mat[0].y
                                                                                             * this->mat[0].y)))
                                                                     * (float)0.5))
                                                     * (float)v5)
                                             - (float)1.5)
                             * (float)v5)));
  v9 = (float)(this->mat[0].y
             * (float)((float)v7
                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y))) * (float)0.5))
                                                                                             * (float)v5)
                                                                                     - (float)1.5)
                                                                     * (float)v5)
                                                             * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                                             + (float)((float)(this->mat[0].x
                                                                                             * this->mat[0].x)
                                                                                     + (float)(this->mat[0].y
                                                                                             * this->mat[0].y)))
                                                                     * (float)0.5))
                                                     * (float)((float)-(float)((float)((float)((float)v5
                                                                                             * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y))) * (float)0.5))
                                                                                     * (float)v5)
                                                                             - (float)1.5)
                                                             * (float)v5))
                                             - (float)1.5)
                             * (float)((float)-(float)((float)((float)((float)v5
                                                                     * (float)((float)((float)(this->mat[0].z
                                                                                             * this->mat[0].z)
                                                                                     + (float)((float)(this->mat[0].x * this->mat[0].x)
                                                                                             + (float)(this->mat[0].y * this->mat[0].y)))
                                                                             * (float)0.5))
                                                             * (float)v5)
                                                     - (float)1.5)
                                     * (float)v5))));
  this->mat[0].y = this->mat[0].y
                 * (float)((float)v7
                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y))) * (float)0.5))
                                                                                                 * (float)v5)
                                                                                         - (float)1.5)
                                                                         * (float)v5)
                                                                 * (float)((float)((float)(this->mat[0].z
                                                                                         * this->mat[0].z)
                                                                                 + (float)((float)(this->mat[0].x
                                                                                                 * this->mat[0].x)
                                                                                         + (float)(this->mat[0].y
                                                                                                 * this->mat[0].y)))
                                                                         * (float)0.5))
                                                         * (float)((float)-(float)((float)((float)((float)v5
                                                                                                 * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y))) * (float)0.5))
                                                                                         * (float)v5)
                                                                                 - (float)1.5)
                                                                 * (float)v5))
                                                 - (float)1.5)
                                 * (float)((float)-(float)((float)((float)((float)v5
                                                                         * (float)((float)((float)(this->mat[0].z
                                                                                                 * this->mat[0].z)
                                                                                         + (float)((float)(this->mat[0].x * this->mat[0].x)
                                                                                                 + (float)(this->mat[0].y * this->mat[0].y)))
                                                                                 * (float)0.5))
                                                                 * (float)v5)
                                                         - (float)1.5)
                                         * (float)v5)));
  this->mat[0].z = (float)z * (float)v8;
  this->mat[0].x = (float)x * (float)v8;
  this->mat[2].x = (float)(this->mat[1].z * (float)v9) - (float)(this->mat[1].y * (float)((float)z * (float)v8));
  v10 = (float)((float)(this->mat[1].x * this->mat[0].z) - (float)(this->mat[1].z * this->mat[0].x));
  this->mat[2].y = (float)(this->mat[1].x * this->mat[0].z) - (float)(this->mat[1].z * this->mat[0].x);
  v11 = (float)((float)(this->mat[1].y * this->mat[0].x) - (float)(this->mat[1].x * this->mat[0].y));
  this->mat[2].z = (float)(this->mat[1].y * this->mat[0].x) - (float)(this->mat[1].x * this->mat[0].y);
  v12 = this->mat[2].x;
  v13 = v10;
  _FP9 = (float)((float)((float)((float)v11 * (float)v11)
                       + (float)((float)(this->mat[2].x * this->mat[2].x) + (float)((float)v10 * (float)v10)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v15 = (float)((float)((float)((float)v11 * (float)v11)
                      + (float)((float)(this->mat[2].x * this->mat[2].x) + (float)((float)v10 * (float)v10)))
              * (float)0.5);
  __asm { fsel      f7, f9, f10, f12 }
  v17 = __frsqrte(_FP7);
  v18 = (float)((float)-(float)((float)((float)((float)v17
                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                              + (float)((float)(this->mat[2].x * this->mat[2].x)
                                                                      + (float)((float)v10 * (float)v10)))
                                                      * (float)0.5))
                                      * (float)v17)
                              - (float)1.5)
              * (float)v17);
  v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)v15)
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18)
                                              * (float)v15)
                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)v15) * (float)v18)
                                                              - (float)1.5)
                                              * (float)v18))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v18 * (float)v15) * (float)v18) - (float)1.5) * (float)v18));
  v20 = (float)((float)v13
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)v15)
                                                                                      * (float)v18)
                                                                              - (float)1.5)
                                                              * (float)v18)
                                                      * (float)v15)
                                              * (float)((float)-(float)((float)((float)((float)v18 * (float)v15)
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v18 * (float)v15) * (float)v18) - (float)1.5)
                              * (float)v18)));
  this->mat[2].y = v20;
  this->mat[2].x = (float)v12 * (float)v19;
  this->mat[2].z = (float)v11 * (float)v19;
  this->mat[1].x = (float)((float)v20 * this->mat[0].z) - (float)((float)((float)v11 * (float)v19) * this->mat[0].y);
  v21 = (float)((float)(this->mat[2].z * this->mat[0].x) - (float)(this->mat[2].x * this->mat[0].z));
  this->mat[1].y = (float)(this->mat[2].z * this->mat[0].x) - (float)(this->mat[2].x * this->mat[0].z);
  v22 = (float)((float)(this->mat[2].x * this->mat[0].y) - (float)(this->mat[2].y * this->mat[0].x));
  this->mat[1].z = (float)(this->mat[2].x * this->mat[0].y) - (float)(this->mat[2].y * this->mat[0].x);
  v23 = v21;
  v24 = (float)((float)((float)v22 * (float)v22)
              + (float)((float)(this->mat[1].x * this->mat[1].x) + (float)((float)v21 * (float)v21)));
  _FP9 = (float)((float)v24 - idMath::FLT_SMALLEST_NON_DENORMAL);
  v26 = (float)((float)v24 * (float)0.5);
  __asm { fsel      f7, f9, f10, f12 }
  v28 = __frsqrte(_FP7);
  v29 = (float)((float)-(float)((float)((float)((float)v28 * (float)((float)v24 * (float)0.5)) * (float)v28) - (float)1.5)
              * (float)v28);
  v30 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28
                                                                              * (float)((float)v24 * (float)0.5))
                                                                      * (float)v28)
                                                              - (float)1.5)
                                              * (float)v28)
                                      * (float)((float)v24 * (float)0.5))
                              * (float)((float)-(float)((float)((float)((float)v28 * (float)((float)v24 * (float)0.5))
                                                              * (float)v28)
                                                      - (float)1.5)
                                      * (float)v28))
                      - (float)1.5);
  v31 = (float)((float)((float)v30 * (float)v29) * (float)v26);
  this->mat[1].x = this->mat[1].x
                 * (float)((float)-(float)((float)((float)v31 * (float)((float)v30 * (float)v29)) - (float)1.5)
                         * (float)((float)v30 * (float)v29));
  this->mat[1].y = (float)v23
                 * (float)((float)-(float)((float)((float)v31 * (float)((float)v30 * (float)v29)) - (float)1.5)
                         * (float)((float)v30 * (float)v29));
  this->mat[1].z = (float)v22
                 * (float)((float)-(float)((float)((float)v31 * (float)((float)v30 * (float)v29)) - (float)1.5)
                         * (float)((float)v30 * (float)v29));
  return this;
}


// ========================================================================
// ??DidMat3@@QBA?AV0@ABV0@@Z
// EA  : 0x825E5250
// RVA : 0x005E5250
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

idMat3 *__fastcall idMat3::operator*(idMat3 *this, idMat3 *result, const idMat3 *a)
{
  this->mat[0].x = (float)(a->mat[0].x * result->mat[0].x)
                 + (float)((float)(a->mat[2].x * result->mat[0].z) + (float)(a->mat[1].x * result->mat[0].y));
  this->mat[0].y = (float)(a->mat[1].y * result->mat[0].y)
                 + (float)((float)(a->mat[2].y * result->mat[0].z) + (float)(a->mat[0].y * result->mat[0].x));
  this->mat[0].z = (float)(a->mat[2].z * result->mat[0].z)
                 + (float)((float)(a->mat[1].z * result->mat[0].y) + (float)(result->mat[0].x * a->mat[0].z));
  this->mat[1].x = (float)(a->mat[2].x * result->mat[1].z)
                 + (float)((float)(a->mat[1].x * result->mat[1].y) + (float)(a->mat[0].x * result->mat[1].x));
  this->mat[1].y = (float)(a->mat[1].y * result->mat[1].y)
                 + (float)((float)(a->mat[0].y * result->mat[1].x) + (float)(a->mat[2].y * result->mat[1].z));
  this->mat[1].z = (float)(a->mat[1].z * result->mat[1].y)
                 + (float)((float)(result->mat[1].z * a->mat[2].z) + (float)(result->mat[1].x * a->mat[0].z));
  this->mat[2].x = (float)(a->mat[2].x * result->mat[2].z)
                 + (float)((float)(a->mat[1].x * result->mat[2].y) + (float)(result->mat[2].x * a->mat[0].x));
  this->mat[2].y = (float)(a->mat[2].y * result->mat[2].z)
                 + (float)((float)(result->mat[2].y * a->mat[1].y) + (float)(result->mat[2].x * a->mat[0].y));
  this->mat[2].z = (float)(result->mat[2].y * a->mat[1].z)
                 + (float)((float)(result->mat[2].z * a->mat[2].z) + (float)(result->mat[2].x * a->mat[0].z));
  return this;
}


// ========================================================================
// ?Compare@idMat3@@QBA_NABV1@@Z
// EA  : 0x8260D430
// RVA : 0x0060D430
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

int __fastcall idMat3::Compare(idMat3 *this, const idMat3 *a)
{
  char v2; // r11
  char v3; // r11
  char v4; // r11
  int result; // r3

  if ( this->mat[0].x != a->mat[0].x || this->mat[0].y != a->mat[0].y || (v2 = 1, this->mat[0].z != a->mat[0].z) )
    v2 = 0;
  if ( v2 == 0 )
    return 0;
  if ( this->mat[1].x != a->mat[1].x || this->mat[1].y != a->mat[1].y || (v3 = 1, this->mat[1].z != a->mat[1].z) )
    v3 = 0;
  if ( v3 == 0 )
    return 0;
  if ( this->mat[2].x != a->mat[2].x || this->mat[2].y != a->mat[2].y || (v4 = 1, this->mat[2].z != a->mat[2].z) )
    v4 = 0;
  result = 1;
  if ( v4 == 0 )
    return 0;
  return result;
}


// ========================================================================
// ?Inverse@idMat3@@QBA?AV1@XZ
// EA  : 0x826B1DE0
// RVA : 0x006B1DE0
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

idMat3 *__fastcall idMat3::Inverse(idMat3 *this, idMat3 *result)
{
  *this = *result;
  idMat3::InverseSelf(this);
  return this;
}


// ========================================================================
// ?Compare@idMat3@@QBA_NABV1@M@Z
// EA  : 0x826C8FB8
// RVA : 0x006C8FB8
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

int __fastcall idMat3::Compare(idMat3 *this, const idMat3 *a, double epsilon)
{
  bool v3; // r11
  bool v4; // r11
  bool v5; // r11
  int result; // r3

  v3 = false;
  if ( __fabs((float)(this->mat[0].x - a->mat[0].x)) <= epsilon
    && __fabs((float)(this->mat[0].y - a->mat[0].y)) <= epsilon )
  {
    v3 = __fabs((float)(this->mat[0].z - a->mat[0].z)) <= epsilon;
  }
  if ( !v3 )
    return 0;
  v4 = false;
  if ( __fabs((float)(this->mat[1].x - a->mat[1].x)) <= epsilon
    && __fabs((float)(this->mat[1].y - a->mat[1].y)) <= epsilon )
  {
    v4 = __fabs((float)(this->mat[1].z - a->mat[1].z)) <= epsilon;
  }
  if ( !v4 )
    return 0;
  v5 = false;
  if ( __fabs((float)(this->mat[2].x - a->mat[2].x)) <= epsilon
    && __fabs((float)(this->mat[2].y - a->mat[2].y)) <= epsilon )
  {
    v5 = __fabs((float)(this->mat[2].z - a->mat[2].z)) <= epsilon;
  }
  result = 1;
  if ( !v5 )
    return 0;
  return result;
}


// ========================================================================
// ?TransposeMultiply@idMat3@@QBA?AV1@ABV1@@Z
// EA  : 0x826C90D8
// RVA : 0x006C90D8
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

idMat3 *__fastcall idMat3::TransposeMultiply(idMat3 *this, idMat3 *result, const idMat3 *b)
{
  double x; // fp10
  double v4; // fp5
  double v5; // fp29
  double v6; // fp27
  double v7; // fp9
  double v8; // fp7
  double z; // fp0
  double v10; // fp4
  double v11; // fp26
  double v12; // fp2
  double y; // fp25
  double v14; // fp1
  double v15; // fp24
  double v16; // fp13
  double v17; // fp8
  double v18; // fp12

  x = b->mat[1].x;
  v4 = result->mat[1].x;
  v5 = b->mat[2].x;
  v6 = result->mat[2].x;
  v7 = (float)((float)(b->mat[0].y * result->mat[0].z) + (float)(b->mat[1].y * result->mat[1].z));
  v8 = (float)((float)(b->mat[0].x * result->mat[0].z) + (float)(b->mat[1].x * result->mat[1].z));
  z = b->mat[2].z;
  v10 = (float)((float)(result->mat[0].y * b->mat[0].z) + (float)(result->mat[1].y * b->mat[1].z));
  v11 = result->mat[2].z;
  v12 = (float)((float)(result->mat[0].y * b->mat[0].y) + (float)(result->mat[1].y * b->mat[1].y));
  y = b->mat[2].y;
  v14 = (float)((float)(result->mat[0].y * b->mat[0].x) + (float)(result->mat[1].y * b->mat[1].x));
  v15 = result->mat[2].y;
  v16 = (float)((float)(result->mat[0].x * b->mat[0].z) + (float)(result->mat[1].x * b->mat[1].z));
  v17 = (float)((float)(result->mat[2].x * b->mat[2].x) + (float)(result->mat[0].x * b->mat[0].x));
  v18 = (float)((float)(result->mat[0].x * b->mat[0].y) + (float)(result->mat[1].x * b->mat[1].y));
  this->mat[2].z = (float)(result->mat[2].z * b->mat[2].z)
                 + (float)((float)(result->mat[0].z * b->mat[0].z) + (float)(result->mat[1].z * b->mat[1].z));
  this->mat[2].y = (float)((float)y * (float)v11) + (float)v7;
  this->mat[2].x = (float)((float)v5 * (float)v11) + (float)v8;
  this->mat[1].z = (float)((float)v15 * (float)z) + (float)v10;
  this->mat[1].y = (float)((float)v15 * (float)y) + (float)v12;
  this->mat[1].x = (float)((float)v15 * (float)v5) + (float)v14;
  this->mat[0].z = (float)((float)v6 * (float)z) + (float)v16;
  this->mat[0].x = (float)((float)v4 * (float)x) + (float)v17;
  this->mat[0].y = (float)((float)v6 * (float)y) + (float)v18;
  return this;
}


// ========================================================================
// ?IsOrthoNormal@idMat3@@QBA_NM@Z
// EA  : 0x8270BA40
// RVA : 0x0070BA40
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

int __fastcall idMat3::IsOrthoNormal(idMat3 *this, double epsilon)
{
  double v2; // fp12
  double v3; // fp0
  double v4; // fp13
  double v5; // fp11
  double v6; // fp10
  double v7; // fp9
  double v8; // fp8
  double v9; // fp7
  unsigned __int8 v10; // r11

  v2 = (float)((float)((float)epsilon + (float)1.0) * (float)((float)epsilon + (float)1.0));
  v3 = (float)((float)((float)1.0 - (float)epsilon) * (float)((float)1.0 - (float)epsilon));
  v4 = (float)((float)(this->mat[0].z * this->mat[0].z)
             + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y)));
  v5 = (float)((float)(this->mat[1].z * this->mat[1].z)
             + (float)((float)(this->mat[1].x * this->mat[1].x) + (float)(this->mat[1].y * this->mat[1].y)));
  v6 = (float)((float)(this->mat[2].z * this->mat[2].z)
             + (float)((float)(this->mat[2].x * this->mat[2].x) + (float)(this->mat[2].y * this->mat[2].y)));
  v7 = (float)((float)(this->mat[2].x * this->mat[2].x)
             + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[1].x * this->mat[1].x)));
  v8 = (float)((float)(this->mat[2].y * this->mat[2].y)
             + (float)((float)(this->mat[0].y * this->mat[0].y) + (float)(this->mat[1].y * this->mat[1].y)));
  v9 = (float)((float)(this->mat[2].z * this->mat[2].z)
             + (float)((float)(this->mat[0].z * this->mat[0].z) + (float)(this->mat[1].z * this->mat[1].z)));
  if ( v4 <= v3 )
    return 0;
  if ( v5 <= v3 )
    return 0;
  if ( v6 <= v3 )
    return 0;
  if ( v4 >= v2 )
    return 0;
  if ( v5 >= v2 )
    return 0;
  if ( v6 >= v2 )
    return 0;
  if ( v7 <= v3 )
    return 0;
  if ( v8 <= v3 )
    return 0;
  if ( v9 <= v3 )
    return 0;
  if ( v7 >= v2 )
    return 0;
  if ( v8 >= v2 )
    return 0;
  v10 = 1;
  if ( v9 >= v2 )
    return 0;
  return v10;
}


// ========================================================================
// ?IsDiagonal@idMat3@@QBA_NM@Z
// EA  : 0x82719B30
// RVA : 0x00719B30
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

int __fastcall idMat3::IsDiagonal(idMat3 *this, double epsilon)
{
  double y; // fp0
  int result; // r3

  if ( __fabs(this->mat[0].y) > epsilon )
    return 0;
  if ( __fabs(this->mat[0].z) > epsilon )
    return 0;
  if ( __fabs(this->mat[1].x) > epsilon )
    return 0;
  if ( __fabs(this->mat[1].z) > epsilon )
    return 0;
  if ( __fabs(this->mat[2].x) > epsilon )
    return 0;
  y = this->mat[2].y;
  result = 1;
  if ( __fabs(y) > epsilon )
    return 0;
  return result;
}


// ========================================================================
// ?FixDenormals@idMat3@@QAA_NXZ
// EA  : 0x8273BD50
// RVA : 0x0073BD50
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

int __fastcall idMat3::FixDenormals(idMat3 *this)
{
  char v1; // r8
  double v2; // fp0
  char v3; // r9
  unsigned __int8 v4; // r9
  unsigned __int8 v5; // r8

  v1 = 0;
  v2 = idMath::FLT_SMALLEST_NON_DENORMAL;
  if ( __fabs(this->mat[0].x) <= idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    this->mat[0].x = 0.0;
    v1 = 1;
    v2 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  if ( __fabs(this->mat[0].y) <= v2 )
  {
    this->mat[0].y = 0.0;
    v1 = 1;
    v2 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  if ( __fabs(this->mat[0].z) <= v2 )
  {
    this->mat[0].z = 0.0;
    v1 = 1;
    v2 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  v3 = 0;
  if ( __fabs(this->mat[1].x) <= v2 )
  {
    this->mat[1].x = 0.0;
    v3 = 1;
    v2 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  if ( __fabs(this->mat[1].y) <= v2 )
  {
    this->mat[1].y = 0.0;
    v3 = 1;
    v2 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  if ( __fabs(this->mat[1].z) <= v2 )
  {
    this->mat[1].z = 0.0;
    v3 = 1;
    v2 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  v5 = v3 | v1;
  v4 = 0;
  if ( __fabs(this->mat[2].x) <= v2 )
  {
    this->mat[2].x = 0.0;
    v4 = 1;
    v2 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  if ( __fabs(this->mat[2].y) <= v2 )
  {
    this->mat[2].y = 0.0;
    v4 = 1;
    v2 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  if ( __fabs(this->mat[2].z) <= v2 )
  {
    this->mat[2].z = 0.0;
    v4 = 1;
  }
  return v4 | v5;
}


// ========================================================================
// ?FixDegeneracies@idMat3@@QAA_NXZ
// EA  : 0x82765A30
// RVA : 0x00765A30
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

int __fastcall idMat3::FixDegeneracies(idMat3 *this)
{
  char fixed; // r30
  char v3; // r11

  fixed = idVec3::FixDegenerateNormal(this: this->mat);
  v3 = idVec3::FixDegenerateNormal(this: &this->mat[1]);
  return (unsigned __int8)idVec3::FixDegenerateNormal(this: &this->mat[2]) | (unsigned __int8)(v3 | fixed);
}


// ========================================================================
// ?Inverse@idMat4@@QBA?AV1@XZ
// EA  : 0x82853530
// RVA : 0x00853530
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

idMat4 *__fastcall idMat4::Inverse(idMat4 *this, idMat4 *result)
{
  *this = *result;
  idMat4::InverseSelf(this);
  return this;
}


// ========================================================================
// ??GidMat3@@QBA?AV0@ABV0@@Z
// EA  : 0x82859B50
// RVA : 0x00859B50
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

idMat3 *__fastcall idMat3::operator-(idMat3 *this, idMat3 *result, const idMat3 *a)
{
  double v3; // fp11
  double v4; // fp8
  double v5; // fp5
  double v6; // fp2
  double v7; // fp13
  double v8; // fp9
  double v9; // fp4
  double v10; // fp0

  v3 = (float)(result->mat[2].z - a->mat[2].z);
  v4 = (float)(result->mat[2].y - a->mat[2].y);
  v5 = (float)(result->mat[2].x - a->mat[2].x);
  v6 = (float)(result->mat[1].z - a->mat[1].z);
  v7 = (float)(result->mat[1].y - a->mat[1].y);
  v8 = (float)(result->mat[1].x - a->mat[1].x);
  v9 = (float)(result->mat[0].z - a->mat[0].z);
  v10 = (float)(result->mat[0].y - a->mat[0].y);
  this->mat[0].x = result->mat[0].x - a->mat[0].x;
  this->mat[0].y = v10;
  this->mat[0].z = v9;
  this->mat[1].x = v8;
  this->mat[1].y = v7;
  this->mat[1].z = v6;
  this->mat[2].x = v5;
  this->mat[2].y = v4;
  this->mat[2].z = v3;
  return this;
}


// ========================================================================
// ?OrthoNormalize@idMat3@@QBA?AV1@XZ
// EA  : 0x82CF3F90
// RVA : 0x00CF3F90
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

idMat3 *__fastcall idMat3::OrthoNormalize(idMat3 *this, idMat3 *result)
{
  double z; // fp4
  double y; // fp3
  double v6; // fp7
  double v7; // fp8
  double v8; // fp6
  double v9; // fp2
  double v10; // fp11
  double v11; // fp5
  double v12; // fp2
  double v14; // fp8
  double v16; // fp6
  double v17; // fp11
  double v18; // fp10
  double v19; // fp4
  double v20; // fp1
  double v22; // fp7
  double v24; // fp5
  double v25; // fp11
  double v26; // fp10
  double v27; // fp7

  *this = *result;
  z = this->mat[0].z;
  y = this->mat[0].y;
  _FP10 = (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                        + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f8, f10, f11, f12 }
  v6 = __frsqrte(_FP8);
  v7 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6
                                                                                     * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y)))
                                                                                             * (float)0.5))
                                                                             * (float)v6)
                                                                     - (float)1.5)
                                                     * (float)v6)
                                             * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                             + (float)((float)(this->mat[0].x * this->mat[0].x)
                                                                     + (float)(this->mat[0].y * this->mat[0].y)))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v6
                                                                             * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                                                             + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y)))
                                                                                     * (float)0.5))
                                                                     * (float)v6)
                                                             - (float)1.5)
                                             * (float)v6))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v6
                                                     * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                                     + (float)((float)(this->mat[0].x * this->mat[0].x)
                                                                             + (float)(this->mat[0].y * this->mat[0].y)))
                                                             * (float)0.5))
                                             * (float)v6)
                                     - (float)1.5)
                     * (float)v6));
  v8 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6 * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y))) * (float)0.5)) * (float)v6) - (float)1.5)
                                                                                     * (float)v6)
                                                                             * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                                                             + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y)))
                                                                                     * (float)0.5))
                                                                     * (float)((float)-(float)((float)((float)((float)v6 * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y))) * (float)0.5)) * (float)v6)
                                                                                             - (float)1.5)
                                                                             * (float)v6))
                                                             - (float)1.5)
                                             * (float)((float)-(float)((float)((float)((float)v6
                                                                                     * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y)))
                                                                                             * (float)0.5))
                                                                             * (float)v6)
                                                                     - (float)1.5)
                                                     * (float)v6))
                                     * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                     + (float)((float)(this->mat[0].x * this->mat[0].x)
                                                             + (float)(this->mat[0].y * this->mat[0].y)))
                                             * (float)0.5))
                             * (float)v7)
                     - (float)1.5);
  v9 = (float)((float)v8
             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6
                                                                                             * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y))) * (float)0.5))
                                                                                     * (float)v6)
                                                                             - (float)1.5)
                                                             * (float)v6)
                                                     * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                                     + (float)((float)(this->mat[0].x * this->mat[0].x)
                                                                             + (float)(this->mat[0].y * this->mat[0].y)))
                                                             * (float)0.5))
                                             * (float)((float)-(float)((float)((float)((float)v6
                                                                                     * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y)))
                                                                                             * (float)0.5))
                                                                             * (float)v6)
                                                                     - (float)1.5)
                                                     * (float)v6))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)v6
                                                             * (float)((float)((float)(this->mat[0].z * this->mat[0].z)
                                                                             + (float)((float)(this->mat[0].x
                                                                                             * this->mat[0].x)
                                                                                     + (float)(this->mat[0].y
                                                                                             * this->mat[0].y)))
                                                                     * (float)0.5))
                                                     * (float)v6)
                                             - (float)1.5)
                             * (float)v6)));
  this->mat[0].x = this->mat[0].x
                 * (float)((float)v8
                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6 * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y))) * (float)0.5))
                                                                                                 * (float)v6)
                                                                                         - (float)1.5)
                                                                         * (float)v6)
                                                                 * (float)((float)((float)(this->mat[0].z
                                                                                         * this->mat[0].z)
                                                                                 + (float)((float)(this->mat[0].x
                                                                                                 * this->mat[0].x)
                                                                                         + (float)(this->mat[0].y
                                                                                                 * this->mat[0].y)))
                                                                         * (float)0.5))
                                                         * (float)((float)-(float)((float)((float)((float)v6
                                                                                                 * (float)((float)((float)(this->mat[0].z * this->mat[0].z) + (float)((float)(this->mat[0].x * this->mat[0].x) + (float)(this->mat[0].y * this->mat[0].y))) * (float)0.5))
                                                                                         * (float)v6)
                                                                                 - (float)1.5)
                                                                 * (float)v6))
                                                 - (float)1.5)
                                 * (float)((float)-(float)((float)((float)((float)v6
                                                                         * (float)((float)((float)(this->mat[0].z
                                                                                                 * this->mat[0].z)
                                                                                         + (float)((float)(this->mat[0].x * this->mat[0].x)
                                                                                                 + (float)(this->mat[0].y * this->mat[0].y)))
                                                                                 * (float)0.5))
                                                                 * (float)v6)
                                                         - (float)1.5)
                                         * (float)v6)));
  this->mat[0].y = (float)y * (float)v9;
  this->mat[0].z = (float)z * (float)v9;
  this->mat[2].x = (float)(result->mat[1].z * result->mat[0].y) - (float)(result->mat[0].z * result->mat[1].y);
  v10 = (float)((float)(result->mat[0].z * result->mat[1].x) - (float)(result->mat[1].z * result->mat[0].x));
  this->mat[2].y = (float)(result->mat[0].z * result->mat[1].x) - (float)(result->mat[1].z * result->mat[0].x);
  v11 = (float)((float)(result->mat[0].x * result->mat[1].y) - (float)(result->mat[1].x * result->mat[0].y));
  this->mat[2].z = (float)(result->mat[0].x * result->mat[1].y) - (float)(result->mat[1].x * result->mat[0].y);
  v12 = v10;
  _FP9 = (float)((float)((float)((float)v11 * (float)v11)
                       + (float)((float)(this->mat[2].x * this->mat[2].x) + (float)((float)v10 * (float)v10)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v14 = (float)((float)((float)((float)v11 * (float)v11)
                      + (float)((float)(this->mat[2].x * this->mat[2].x) + (float)((float)v10 * (float)v10)))
              * (float)0.5);
  __asm { fsel      f7, f9, f10, f12 }
  v16 = __frsqrte(_FP7);
  v17 = (float)((float)-(float)((float)((float)((float)v16
                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                              + (float)((float)(this->mat[2].x * this->mat[2].x)
                                                                      + (float)((float)v10 * (float)v10)))
                                                      * (float)0.5))
                                      * (float)v16)
                              - (float)1.5)
              * (float)v16);
  this->mat[2].x = this->mat[2].x
                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                                 * (float)v14)
                                                                                         * (float)v17)
                                                                                 - (float)1.5)
                                                                 * (float)v17)
                                                         * (float)v14)
                                                 * (float)((float)-(float)((float)((float)((float)v17 * (float)v14)
                                                                                 * (float)v17)
                                                                         - (float)1.5)
                                                         * (float)v17))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v17 * (float)v14) * (float)v17) - (float)1.5)
                                 * (float)v17));
  this->mat[2].y = (float)v12
                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                                 * (float)v14)
                                                                                         * (float)v17)
                                                                                 - (float)1.5)
                                                                 * (float)v17)
                                                         * (float)v14)
                                                 * (float)((float)-(float)((float)((float)((float)v17 * (float)v14)
                                                                                 * (float)v17)
                                                                         - (float)1.5)
                                                         * (float)v17))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v17 * (float)v14) * (float)v17) - (float)1.5)
                                 * (float)v17));
  this->mat[2].z = (float)v11
                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                                 * (float)v14)
                                                                                         * (float)v17)
                                                                                 - (float)1.5)
                                                                 * (float)v17)
                                                         * (float)v14)
                                                 * (float)((float)-(float)((float)((float)((float)v17 * (float)v14)
                                                                                 * (float)v17)
                                                                         - (float)1.5)
                                                         * (float)v17))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v17 * (float)v14) * (float)v17) - (float)1.5)
                                 * (float)v17));
  this->mat[1].x = (float)(result->mat[0].z * result->mat[2].y) - (float)(result->mat[2].z * result->mat[0].y);
  v18 = (float)((float)(result->mat[0].x * result->mat[2].z) - (float)(result->mat[0].z * result->mat[2].x));
  this->mat[1].y = (float)(result->mat[0].x * result->mat[2].z) - (float)(result->mat[0].z * result->mat[2].x);
  v19 = (float)((float)(result->mat[2].x * result->mat[0].y) - (float)(result->mat[2].y * result->mat[0].x));
  this->mat[1].z = (float)(result->mat[2].x * result->mat[0].y) - (float)(result->mat[2].y * result->mat[0].x);
  v20 = v18;
  _FP8 = (float)((float)((float)((float)v19 * (float)v19)
                       + (float)((float)(this->mat[1].x * this->mat[1].x) + (float)((float)v18 * (float)v18)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v22 = (float)((float)((float)((float)v19 * (float)v19)
                      + (float)((float)(this->mat[1].x * this->mat[1].x) + (float)((float)v18 * (float)v18)))
              * (float)0.5);
  __asm { fsel      f6, f8, f9, f12 }
  v24 = __frsqrte(_FP6);
  v25 = (float)((float)-(float)((float)((float)((float)v24
                                              * (float)((float)((float)((float)v19 * (float)v19)
                                                              + (float)((float)(this->mat[1].x * this->mat[1].x)
                                                                      + (float)((float)v18 * (float)v18)))
                                                      * (float)0.5))
                                      * (float)v24)
                              - (float)1.5)
              * (float)v24);
  v26 = (float)((float)((float)-(float)((float)((float)((float)v24
                                                      * (float)((float)((float)((float)v19 * (float)v19)
                                                                      + (float)((float)(this->mat[1].x * this->mat[1].x)
                                                                              + (float)((float)v18 * (float)v18)))
                                                              * (float)0.5))
                                              * (float)v24)
                                      - (float)1.5)
                      * (float)v24)
              * (float)((float)((float)((float)v19 * (float)v19)
                              + (float)((float)(this->mat[1].x * this->mat[1].x) + (float)((float)v18 * (float)v18)))
                      * (float)0.5));
  v27 = (float)((float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5) * (float)v25) * (float)v22);
  this->mat[1].x = this->mat[1].x
                 * (float)((float)-(float)((float)((float)v27
                                                 * (float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5)
                                                         * (float)v25))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5) * (float)v25));
  this->mat[1].y = (float)v20
                 * (float)((float)-(float)((float)((float)v27
                                                 * (float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5)
                                                         * (float)v25))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5) * (float)v25));
  this->mat[1].z = (float)v19
                 * (float)((float)-(float)((float)((float)v27
                                                 * (float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5)
                                                         * (float)v25))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5) * (float)v25));
  return this;
}


// ========================================================================
// ?OrthoNormalizeSelf@idMat3@@QAAAAV1@EE@Z
// EA  : 0x82D4F2A0
// RVA : 0x00D4F2A0
// PDB : w:\tech5\shared\idlib\math\matrix.h
// ========================================================================

idMat3 *__fastcall idMat3::OrthoNormalizeSelf(idMat3 *this, int prio1, int prio2)
{
  float *v3; // r11
  double v4; // fp11
  double v5; // fp8
  float *v6; // r10
  float *v7; // r9
  double v10; // fp2
  double v11; // fp3
  double v12; // fp1
  double v13; // fp12
  double v14; // fp8
  double v15; // fp8
  double v16; // fp2
  double v17; // fp10
  double v19; // fp6
  double v21; // fp3
  double v22; // fp8
  double v23; // fp12
  double v24; // fp8
  double v25; // fp7
  double v26; // fp1
  double v27; // fp9
  double v30; // fp3
  double v31; // fp2
  double v32; // fp8
  double v33; // fp7
  double v34; // fp3

  v3 = (float *)((char *)this + 4 * (unsigned __int8)prio1 + 4 * ((2 * prio1) & 0x1FE));
  v4 = v3[1];
  v5 = v3[2];
  v6 = (float *)((char *)this + 4 * (unsigned __int8)prio2 + 4 * ((2 * prio2) & 0x1FE));
  v7 = (float *)((char *)this
               + 4 * (unsigned __int8)(3 - prio2 - prio1)
               + 4 * ((2 * (unsigned __int8)(3 - prio2 - prio1)) & 0x1FE));
  _FP5 = (float)((float)((float)(v3[2] * v3[2]) + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1])))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f12 }
  v10 = __frsqrte(_FP3);
  v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)(v3[2] * v3[2]) + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1])))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10)
                                              * (float)((float)((float)(v3[2] * v3[2])
                                                              + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1])))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v10
                                                                              * (float)((float)((float)(v3[2] * v3[2])
                                                                                              + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1])))
                                                                                      * (float)0.5))
                                                                      * (float)v10)
                                                              - (float)1.5)
                                              * (float)v10))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v10
                                                      * (float)((float)((float)(v3[2] * v3[2])
                                                                      + (float)((float)(*v3 * *v3)
                                                                              + (float)(v3[1] * v3[1])))
                                                              * (float)0.5))
                                              * (float)v10)
                                      - (float)1.5)
                      * (float)v10));
  v12 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)(v3[2] * v3[2]) + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1]))) * (float)0.5)) * (float)v10) - (float)1.5)
                                                                                      * (float)v10)
                                                                              * (float)((float)((float)(v3[2] * v3[2])
                                                                                              + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1])))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)(v3[2] * v3[2]) + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1]))) * (float)0.5)) * (float)v10)
                                                                                              - (float)1.5)
                                                                              * (float)v10))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)(v3[2] * v3[2]) + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1])))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10))
                                      * (float)((float)((float)(v3[2] * v3[2])
                                                      + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1])))
                                              * (float)0.5))
                              * (float)v11)
                      - (float)1.5);
  v13 = (float)((float)v12
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                              * (float)((float)((float)(v3[2] * v3[2]) + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1]))) * (float)0.5))
                                                                                      * (float)v10)
                                                                              - (float)1.5)
                                                              * (float)v10)
                                                      * (float)((float)((float)(v3[2] * v3[2])
                                                                      + (float)((float)(*v3 * *v3)
                                                                              + (float)(v3[1] * v3[1])))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)(v3[2] * v3[2]) + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1])))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v10
                                                              * (float)((float)((float)(v3[2] * v3[2])
                                                                              + (float)((float)(*v3 * *v3)
                                                                                      + (float)(v3[1] * v3[1])))
                                                                      * (float)0.5))
                                                      * (float)v10)
                                              - (float)1.5)
                              * (float)v10)));
  *v3 = *v3
      * (float)((float)v12
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                              * (float)((float)((float)(v3[2] * v3[2]) + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1]))) * (float)0.5))
                                                                                      * (float)v10)
                                                                              - (float)1.5)
                                                              * (float)v10)
                                                      * (float)((float)((float)(v3[2] * v3[2])
                                                                      + (float)((float)(*v3 * *v3)
                                                                              + (float)(v3[1] * v3[1])))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)(v3[2] * v3[2]) + (float)((float)(*v3 * *v3) + (float)(v3[1] * v3[1])))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v10
                                                              * (float)((float)((float)(v3[2] * v3[2])
                                                                              + (float)((float)(*v3 * *v3)
                                                                                      + (float)(v3[1] * v3[1])))
                                                                      * (float)0.5))
                                                      * (float)v10)
                                              - (float)1.5)
                              * (float)v10)));
  v3[1] = (float)v4 * (float)v13;
  v14 = (float)((float)v5 * (float)v13);
  v3[2] = v14;
  *v7 = (float)((float)((float)v4 * (float)v13) * v6[2]) - (float)((float)v14 * v6[1]);
  v15 = (float)((float)(*v6 * v3[2]) - (float)(v6[2] * *v3));
  v7[1] = (float)(*v6 * v3[2]) - (float)(v6[2] * *v3);
  v16 = (float)((float)(*v3 * v6[1]) - (float)(v3[1] * *v6));
  v7[2] = (float)(*v3 * v6[1]) - (float)(v3[1] * *v6);
  v17 = v15;
  _FP5 = (float)((float)((float)((float)v16 * (float)v16)
                       + (float)((float)(*v7 * *v7) + (float)((float)v15 * (float)v15)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v19 = (float)((float)((float)((float)v16 * (float)v16) + (float)((float)(*v7 * *v7) + (float)((float)v15 * (float)v15)))
              * (float)0.5);
  __asm { fsel      f4, f5, f7, f12 }
  v21 = __frsqrte(_FP4);
  v22 = (float)((float)-(float)((float)((float)((float)v21
                                              * (float)((float)((float)((float)v16 * (float)v16)
                                                              + (float)((float)(*v7 * *v7)
                                                                      + (float)((float)v15 * (float)v15)))
                                                      * (float)0.5))
                                      * (float)v21)
                              - (float)1.5)
              * (float)v21);
  v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)v19)
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22)
                                              * (float)v19)
                                      * (float)((float)-(float)((float)((float)((float)v22 * (float)v19) * (float)v22)
                                                              - (float)1.5)
                                              * (float)v22))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v22 * (float)v19) * (float)v22) - (float)1.5) * (float)v22));
  *v7 = *v7
      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)v19)
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22)
                                              * (float)v19)
                                      * (float)((float)-(float)((float)((float)((float)v22 * (float)v19) * (float)v22)
                                                              - (float)1.5)
                                              * (float)v22))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v22 * (float)v19) * (float)v22) - (float)1.5) * (float)v22));
  v24 = (float)((float)v17
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)v19)
                                                                                      * (float)v22)
                                                                              - (float)1.5)
                                                              * (float)v22)
                                                      * (float)v19)
                                              * (float)((float)-(float)((float)((float)((float)v22 * (float)v19)
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v22 * (float)v19) * (float)v22) - (float)1.5)
                              * (float)v22)));
  v7[1] = v24;
  v7[2] = (float)v16 * (float)v23;
  *v6 = (float)(v3[2] * (float)v24) - (float)((float)((float)v16 * (float)v23) * v3[1]);
  v25 = (float)((float)(v7[2] * *v3) - (float)(v3[2] * *v7));
  v6[1] = (float)(v7[2] * *v3) - (float)(v3[2] * *v7);
  v26 = (float)((float)(v3[1] * *v7) - (float)(*v3 * v7[1]));
  v6[2] = (float)(v3[1] * *v7) - (float)(*v3 * v7[1]);
  v27 = v25;
  _FP5 = (float)((float)((float)((float)v26 * (float)v26)
                       + (float)((float)(*v6 * *v6) + (float)((float)v25 * (float)v25)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f5, f6, f12 }
  v30 = (float)((float)((float)((float)v26 * (float)v26) + (float)((float)(*v6 * *v6) + (float)((float)v25 * (float)v25)))
              * (float)0.5);
  v31 = __frsqrte(_FP4);
  v32 = (float)((float)-(float)((float)((float)((float)v31
                                              * (float)((float)((float)((float)v26 * (float)v26)
                                                              + (float)((float)(*v6 * *v6)
                                                                      + (float)((float)v25 * (float)v25)))
                                                      * (float)0.5))
                                      * (float)v31)
                              - (float)1.5)
              * (float)v31);
  v33 = (float)((float)((float)-(float)((float)((float)((float)v31
                                                      * (float)((float)((float)((float)v26 * (float)v26)
                                                                      + (float)((float)(*v6 * *v6)
                                                                              + (float)((float)v25 * (float)v25)))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31)
              * (float)((float)((float)((float)v26 * (float)v26)
                              + (float)((float)(*v6 * *v6) + (float)((float)v25 * (float)v25)))
                      * (float)0.5));
  v34 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)v33 * (float)v32) - (float)1.5)
                                              * (float)v32)
                                      * (float)v30)
                              * (float)((float)-(float)((float)((float)v33 * (float)v32) - (float)1.5) * (float)v32))
                      - (float)1.5);
  *v6 = *v6 * (float)((float)v34 * (float)((float)-(float)((float)((float)v33 * (float)v32) - (float)1.5) * (float)v32));
  v6[1] = (float)v27
        * (float)((float)v34 * (float)((float)-(float)((float)((float)v33 * (float)v32) - (float)1.5) * (float)v32));
  v6[2] = (float)v26
        * (float)((float)v34 * (float)((float)-(float)((float)((float)v33 * (float)v32) - (float)1.5) * (float)v32));
  return this;
}

