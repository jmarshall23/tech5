
// ========================================================================
// ?InverseWorldSpatialInertiaMultiply@idAFBody@@QBAXAAVidSpatialVec@@ABV2@@Z
// EA  : 0x8271BA30
// RVA : 0x0071BA30
// PDB : w:\tech5\engine\gamelib\physics\afbody.h
// ========================================================================

void __fastcall idAFBody::InverseWorldSpatialInertiaMultiply(
        idAFBody *this,
        idSpatialVec *dst,
        const idSpatialVec *vec)
{
  float *mat; // r11
  float *p; // r10
  float *v5; // r9
  double v6; // fp3
  double v7; // fp12
  double v8; // fp10
  double v9; // fp6
  double v10; // fp8
  double v11; // fp5
  double v12; // fp4
  double v13; // fp2
  double v14; // fp1

  mat = this->inverseWorldSpatialInertia.mat;
  p = vec->p;
  v5 = dst->p;
  v6 = p[5];
  v7 = (float)((float)(mat[27] * p[3]) + (float)(mat[28] * p[4]));
  v8 = (float)((float)(mat[35] * p[3]) + (float)(mat[36] * p[4]));
  v9 = mat[29];
  v10 = (float)((float)(mat[43] * p[3]) + (float)(mat[44] * p[4]));
  v11 = (float)(mat[9] * p[1]);
  v12 = mat[37];
  v13 = (float)(mat[18] * p[2]);
  v14 = mat[45];
  *v5 = *p * *mat;
  v5[1] = v11;
  v5[2] = v13;
  v5[3] = (float)((float)v9 * (float)v6) + (float)v7;
  v5[4] = (float)((float)v12 * (float)v6) + (float)v8;
  v5[5] = (float)((float)v14 * (float)v6) + (float)v10;
}


// ========================================================================
// ?GetInverseWorldInertia@idAFBody@@QBA?BVidMat3@@XZ
// EA  : 0x82721588
// RVA : 0x00721588
// PDB : w:\tech5\engine\gamelib\physics\afbody.h
// ========================================================================

idAFBody *__fastcall idAFBody::GetInverseWorldInertia(idAFBody *this, const idMat3 *result)
{
  float z; // r11
  const idMat3 *v4; // r31
  double v5; // fp13
  double v6; // fp12
  double v7; // fp11
  double v8; // fp10
  double v9; // fp9
  double v10; // fp8
  double v11; // fp7
  double v12; // fp6
  idMat3 *v13; // r3
  idMat3 v15; // [sp+50h] [-70h] BYREF
  idMat3 v16; // [sp+80h] [-40h] BYREF

  z = result->mat[1].z;
  v4 = (const idMat3 *)(LODWORD(z) + 44);
  v5 = *(float *)(LODWORD(z) + 64);
  v6 = *(float *)(LODWORD(z) + 52);
  v7 = *(float *)(LODWORD(z) + 72);
  v8 = *(float *)(LODWORD(z) + 60);
  v9 = *(float *)(LODWORD(z) + 48);
  v10 = *(float *)(LODWORD(z) + 68);
  v11 = *(float *)(LODWORD(z) + 56);
  v12 = *(float *)(LODWORD(z) + 44);
  v15.mat[2].z = *(float *)(LODWORD(z) + 76);
  v15.mat[2].y = v5;
  v15.mat[2].x = v6;
  v15.mat[1].z = v7;
  v15.mat[1].y = v8;
  v15.mat[1].x = v9;
  v15.mat[0].z = v10;
  v15.mat[0].y = v11;
  v15.mat[0].x = v12;
  v13 = idMat3::operator*(this: &v16, result: &v15, a: (const idMat3 *)((char *)result + 140));
  idMat3::operator*((idMat3 *)this, result: v13, a: v4);
  return this;
}

