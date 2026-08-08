
// ========================================================================
// ?FromMat4@idJointQuat@@QAAXABVidMat4@@@Z
// EA  : 0x828535E0
// RVA : 0x008535E0
// PDB : w:\tech5\shared\idlib\geometry\jointtransform.h
// ========================================================================

void __fastcall idJointQuat::FromMat4(idJointQuat *this, const idMat4 *mat)
{
  double v2; // fp0
  double v5; // fp6
  double v6; // fp9
  double v7; // fp5
  int v8; // r9
  int v9; // r7
  int v10; // r11
  int v11; // r10
  int v12; // r5
  int v13; // r31
  double v16; // fp7
  double v17; // fp12
  double v18; // fp13

  v2 = (float)((float)(mat->mat[0].x + mat->mat[1].y) + mat->mat[2].z);
  if ( v2 <= 0.0 )
  {
    v8 = mat->mat[1].y > (double)mat->mat[0].x;
    if ( mat->mat[2].z > (double)*(&mat->mat[0].x + 5 * v8) )
      v8 = 2;
    v9 = v8;
    v10 = `idJointQuat::FromMat4'::`2'::next[v8];
    v11 = `idJointQuat::FromMat4'::`2'::next[v10];
    v12 = 4 * (4 * v11 + v10);
    v13 = 4 * (4 * v10 + v11);
    _FP1 = (float)((float)((float)(*(&mat->mat[0].x + 5 * v8)
                                 - (float)(*(&mat->mat[0].x + 5 * v11) + *(&mat->mat[0].x + 5 * v10)))
                         + (float)1.0)
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f8, f1, f0, f12 }
    v16 = __frsqrte(_FP8);
    v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16
                                                                                        * (float)((float)((float)(*(&mat->mat[0].x + 5 * v8) - (float)(*(&mat->mat[0].x + 5 * v11) + *(&mat->mat[0].x + 5 * v10))) + (float)1.0)
                                                                                                * (float)0.5))
                                                                                * (float)v16)
                                                                        - (float)1.5)
                                                        * (float)v16)
                                                * (float)((float)((float)(*(&mat->mat[0].x + 5 * v8)
                                                                        - (float)(*(&mat->mat[0].x + 5 * v11)
                                                                                + *(&mat->mat[0].x + 5 * v10)))
                                                                + (float)1.0)
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v16
                                                                                * (float)((float)((float)(*(&mat->mat[0].x + 5 * v8) - (float)(*(&mat->mat[0].x + 5 * v11) + *(&mat->mat[0].x + 5 * v10)))
                                                                                                + (float)1.0)
                                                                                        * (float)0.5))
                                                                        * (float)v16)
                                                                - (float)1.5)
                                                * (float)v16))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v16
                                                        * (float)((float)((float)(*(&mat->mat[0].x + 5 * v8)
                                                                                - (float)(*(&mat->mat[0].x + 5 * v11)
                                                                                        + *(&mat->mat[0].x + 5 * v10)))
                                                                        + (float)1.0)
                                                                * (float)0.5))
                                                * (float)v16)
                                        - (float)1.5)
                        * (float)v16));
    v18 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)(*(&mat->mat[0].x + 5 * v8) - (float)(*(&mat->mat[0].x + 5 * v11) + *(&mat->mat[0].x + 5 * v10))) + (float)1.0) * (float)0.5)) * (float)v16) - (float)1.5) * (float)v16)
                                                                                                * (float)((float)((float)(*(&mat->mat[0].x + 5 * v8) - (float)(*(&mat->mat[0].x + 5 * v11) + *(&mat->mat[0].x + 5 * v10))) + (float)1.0) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)(*(&mat->mat[0].x + 5 * v8) - (float)(*(&mat->mat[0].x + 5 * v11) + *(&mat->mat[0].x + 5 * v10))) + (float)1.0) * (float)0.5)) * (float)v16) - (float)1.5)
                                                                                                * (float)v16))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v16 * (float)((float)((float)(*(&mat->mat[0].x + 5 * v8) - (float)(*(&mat->mat[0].x + 5 * v11) + *(&mat->mat[0].x + 5 * v10))) + (float)1.0) * (float)0.5))
                                                                                                * (float)v16)
                                                                                        - (float)1.5)
                                                                        * (float)v16))
                                                        * (float)((float)((float)(*(&mat->mat[0].x + 5 * v8)
                                                                                - (float)(*(&mat->mat[0].x + 5 * v11)
                                                                                        + *(&mat->mat[0].x + 5 * v10)))
                                                                        + (float)1.0)
                                                                * (float)0.5))
                                                * (float)v17)
                                        - (float)1.5)
                        * (float)v17)
                * (float)0.5);
    if ( (float)(*(float *)((char *)&mat->mat[0].x + v12) - *(float *)((char *)&mat->mat[0].x + v13)) < 0.0 )
      v18 = -v18;
    this->jointQuat[v9] = (float)v18
                        * (float)((float)(*(&mat->mat[0].x + 5 * v8)
                                        - (float)(*(&mat->mat[0].x + 5 * v11) + *(&mat->mat[0].x + 5 * v10)))
                                + (float)1.0);
    this->jointQuat[3] = (float)(*(float *)((char *)&mat->mat[0].x + v12) - *(float *)((char *)&mat->mat[0].x + v13))
                       * (float)v18;
    this->jointQuat[v10] = (float)(*(&mat->mat[v10].x + v8) + *(&mat->mat[v9].x + v10)) * (float)v18;
    this->jointQuat[v11] = (float)(*(&mat->mat[v11].x + v8) + *(&mat->mat[v9].x + v11)) * (float)v18;
  }
  else
  {
    _FP9 = (float)((float)((float)((float)(mat->mat[0].x + mat->mat[1].y) + mat->mat[2].z) + (float)1.0)
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f7, f9, f11, f13 }
    v5 = __frsqrte(_FP7);
    v6 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5
                                                                                       * (float)((float)((float)v2 + (float)1.0)
                                                                                               * (float)0.5))
                                                                               * (float)v5)
                                                                       - (float)1.5)
                                                       * (float)v5)
                                               * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v5
                                                                               * (float)((float)((float)v2 + (float)1.0)
                                                                                       * (float)0.5))
                                                                       * (float)v5)
                                                               - (float)1.5)
                                               * (float)v5))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v5
                                                       * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                               * (float)v5)
                                       - (float)1.5)
                       * (float)v5));
    v7 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)v5) - (float)1.5) * (float)v5)
                                                                                               * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)v5) - (float)1.5)
                                                                                               * (float)v5))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                                                                               * (float)v5)
                                                                                       - (float)1.5)
                                                                       * (float)v5))
                                                       * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)v5) - (float)1.5)
                                                                                               * (float)v5)
                                                                                       * (float)((float)((float)v2 + (float)1.0)
                                                                                               * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)v5) - (float)1.5)
                                                                                       * (float)v5))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v5
                                                                                               * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                                                                       * (float)v5)
                                                                               - (float)1.5)
                                                               * (float)v5)))
                                       - (float)1.5)
                       * (float)v6)
               * (float)0.5);
    this->jointQuat[3] = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)v5) - (float)1.5) * (float)v5) * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)v5) - (float)1.5) * (float)v5))
                                                                                               - (float)1.5)
                                                                               * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)v5) - (float)1.5)
                                                                                       * (float)v5))
                                                                       * (float)((float)((float)v2 + (float)1.0)
                                                                               * (float)0.5))
                                                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)v5) - (float)1.5) * (float)v5) * (float)((float)((float)v2 + (float)1.0) * (float)0.5))
                                                                                               * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)v5) - (float)1.5) * (float)v5))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)v2 + (float)1.0) * (float)0.5)) * (float)v5)
                                                                                               - (float)1.5)
                                                                               * (float)v5)))
                                                       - (float)1.5)
                                       * (float)v6)
                               * (float)0.5)
                       * (float)((float)v2 + (float)1.0);
    this->jointQuat[0] = (float)(mat->mat[2].y - mat->mat[1].z) * (float)v7;
    this->jointQuat[1] = (float)(mat->mat[0].z - mat->mat[2].x) * (float)v7;
    this->jointQuat[2] = (float)(mat->mat[1].x - mat->mat[0].y) * (float)v7;
  }
  this->jointQuat[4] = mat->mat[0].w;
  this->jointQuat[5] = mat->mat[1].w;
  this->jointQuat[6] = mat->mat[2].w;
  this->jointQuat[7] = 0.0;
}

