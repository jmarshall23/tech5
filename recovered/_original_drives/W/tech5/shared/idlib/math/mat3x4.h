
// ========================================================================
// ?LeftTransposeMultiply@idMat3x4@@QAAXABVidMat3@@@Z
// EA  : 0x825E6FF0
// RVA : 0x005E6FF0
// PDB : w:\tech5\shared\idlib\math\mat3x4.h
// ========================================================================

void __fastcall idMat3x4::LeftTransposeMultiply(idMat3x4 *this, const idMat3 *m)
{
  double v2; // fp11
  double v3; // fp10
  double y; // fp1
  double z; // fp0
  double v6; // fp12
  double v7; // fp5
  double v8; // fp13
  double v9; // fp7
  double v10; // fp6
  double v11; // fp8
  double v12; // fp4
  double v13; // fp31
  double v14; // fp30
  double v15; // fp29
  double v16; // fp28
  double x; // fp5
  double v18; // fp3
  double v19; // fp1
  double v20; // fp0
  double v21; // fp3
  double v22; // fp1
  double v23; // fp10
  double v24; // fp7
  double v25; // fp9
  double v26; // fp6
  double v27; // fp3
  double v28; // fp4

  v2 = this->mat[8];
  v3 = this->mat[4];
  y = m->mat[1].y;
  z = m->mat[2].z;
  v6 = this->mat[5];
  v7 = (float)((float)(m->mat[1].x * this->mat[0]) + (float)(this->mat[8] * m->mat[1].z));
  v8 = this->mat[9];
  v9 = this->mat[1];
  v10 = (float)((float)(this->mat[0] * m->mat[2].x) + (float)(this->mat[4] * m->mat[2].y));
  v11 = this->mat[10];
  v12 = this->mat[6];
  v13 = this->mat[2];
  v14 = this->mat[11];
  v15 = this->mat[7];
  v16 = this->mat[3];
  this->mat[0] = (float)(this->mat[0] * m->mat[0].x)
               + (float)((float)(this->mat[4] * m->mat[0].y) + (float)(this->mat[8] * m->mat[0].z));
  this->mat[4] = (float)((float)v3 * (float)y) + (float)v7;
  this->mat[8] = (float)((float)v2 * (float)z) + (float)v10;
  x = m->mat[0].x;
  v18 = m->mat[1].y;
  v19 = (float)((float)(m->mat[1].x * (float)v9) + (float)((float)v8 * m->mat[1].z));
  v20 = (float)((float)((float)v6 * m->mat[0].y) + (float)((float)v8 * m->mat[0].z));
  this->mat[9] = (float)((float)v8 * m->mat[2].z)
               + (float)((float)((float)v9 * m->mat[2].x) + (float)((float)v6 * m->mat[2].y));
  this->mat[5] = (float)((float)v6 * (float)v18) + (float)v19;
  this->mat[1] = (float)((float)v9 * (float)x) + (float)v20;
  v21 = m->mat[0].x;
  v22 = m->mat[2].z;
  v23 = (float)((float)((float)v12 * m->mat[0].y) + (float)((float)v11 * m->mat[0].z));
  v24 = (float)((float)((float)v13 * m->mat[2].x) + (float)((float)v12 * m->mat[2].y));
  this->mat[6] = (float)((float)v12 * m->mat[1].y)
               + (float)((float)(m->mat[1].x * (float)v13) + (float)((float)v11 * m->mat[1].z));
  this->mat[2] = (float)((float)v13 * (float)v21) + (float)v23;
  this->mat[10] = (float)((float)v11 * (float)v22) + (float)v24;
  v25 = m->mat[0].x;
  v26 = m->mat[2].z;
  v27 = (float)((float)((float)v16 * m->mat[2].x) + (float)((float)v15 * m->mat[2].y));
  v28 = (float)((float)((float)v15 * m->mat[0].y) + (float)((float)v14 * m->mat[0].z));
  this->mat[7] = (float)((float)v15 * m->mat[1].y)
               + (float)((float)(m->mat[1].x * (float)v16) + (float)((float)v14 * m->mat[1].z));
  this->mat[11] = (float)((float)v14 * (float)v26) + (float)v27;
  this->mat[3] = (float)((float)v16 * (float)v25) + (float)v28;
}


// ========================================================================
// ?Transform@idMat3x4@@QBAXAAVidVec3@@ABV2@@Z
// EA  : 0x825E7198
// RVA : 0x005E7198
// PDB : w:\tech5\shared\idlib\math\mat3x4.h
// ========================================================================

void __fastcall idMat3x4::Transform(idMat3x4 *this, idVec3 *result, const idVec3 *v)
{
  result->x = (float)((float)(v->x * this->mat[0]) + (float)((float)(this->mat[1] * v->y) + (float)(this->mat[2] * v->z)))
            + this->mat[3];
  result->y = (float)((float)(this->mat[6] * v->z) + (float)((float)(this->mat[5] * v->y) + (float)(this->mat[4] * v->x)))
            + this->mat[7];
  result->z = (float)((float)(this->mat[10] * v->z)
                    + (float)((float)(this->mat[9] * v->y) + (float)(this->mat[8] * v->x)))
            + this->mat[11];
}


// ========================================================================
// ?Invert@idMat3x4@@QAAXXZ
// EA  : 0x825EB9E0
// RVA : 0x005EB9E0
// PDB : w:\tech5\shared\idlib\math\mat3x4.h
// ========================================================================

void __fastcall idMat3x4::Invert(idMat3x4 *this)
{
  double v1; // fp0
  double v2; // fp13
  double v3; // fp12
  double v4; // fp11
  double v5; // fp10
  double v6; // fp9
  double v7; // fp8
  double v8; // fp7
  double v9; // fp6
  double v10; // fp5
  double v11; // fp4
  double v12; // fp3
  double v13; // fp2
  double v14; // fp1
  double v15; // fp31

  v1 = this->mat[11];
  v2 = this->mat[3];
  v3 = this->mat[8];
  v4 = this->mat[1];
  v5 = (float)(this->mat[8] * this->mat[11]);
  v6 = this->mat[2];
  v7 = (float)(this->mat[1] * this->mat[3]);
  v8 = (float)(this->mat[2] * this->mat[3]);
  v9 = this->mat[7];
  v10 = this->mat[4];
  v11 = this->mat[5];
  v12 = this->mat[10];
  v13 = this->mat[9];
  v14 = this->mat[6];
  v15 = this->mat[0];
  this->mat[1] = this->mat[4];
  this->mat[6] = v13;
  this->mat[9] = v14;
  this->mat[2] = v3;
  this->mat[4] = v4;
  this->mat[8] = v6;
  this->mat[3] = -(float)((float)((float)v2 * (float)v15) + (float)((float)((float)v10 * (float)v9) + (float)v5));
  this->mat[7] = -(float)((float)((float)v13 * (float)v1) + (float)((float)((float)v11 * (float)v9) + (float)v7));
  this->mat[11] = -(float)((float)((float)v14 * (float)v9) + (float)((float)((float)v12 * (float)v1) + (float)v8));
}


// ========================================================================
// ?Rotate@idMat3x4@@QBAXAAVidMat3@@ABV2@@Z
// EA  : 0x825EBA70
// RVA : 0x005EBA70
// PDB : w:\tech5\shared\idlib\math\mat3x4.h
// ========================================================================

void __fastcall idMat3x4::Rotate(idMat3x4 *this, idMat3 *result, const idMat3 *m)
{
  result->mat[0].x = (float)(m->mat[0].y * this->mat[1])
                   + (float)((float)(m->mat[0].x * this->mat[0]) + (float)(m->mat[0].z * this->mat[2]));
  result->mat[1].x = (float)(this->mat[0] * m->mat[1].x)
                   + (float)((float)(m->mat[1].y * this->mat[1]) + (float)(m->mat[1].z * this->mat[2]));
  result->mat[2].x = (float)(m->mat[2].x * this->mat[0])
                   + (float)((float)(m->mat[2].y * this->mat[1]) + (float)(m->mat[2].z * this->mat[2]));
  result->mat[0].y = (float)(m->mat[0].x * this->mat[4])
                   + (float)((float)(this->mat[6] * m->mat[0].z) + (float)(this->mat[5] * m->mat[0].y));
  result->mat[1].y = (float)(m->mat[1].x * this->mat[4])
                   + (float)((float)(this->mat[5] * m->mat[1].y) + (float)(this->mat[6] * m->mat[1].z));
  result->mat[2].y = (float)(this->mat[5] * m->mat[2].y)
                   + (float)((float)(this->mat[6] * m->mat[2].z) + (float)(m->mat[2].x * this->mat[4]));
  result->mat[0].z = (float)(this->mat[8] * m->mat[0].x)
                   + (float)((float)(this->mat[10] * m->mat[0].z) + (float)(this->mat[9] * m->mat[0].y));
  result->mat[1].z = (float)(m->mat[1].y * this->mat[9])
                   + (float)((float)(m->mat[1].z * this->mat[10]) + (float)(this->mat[8] * m->mat[1].x));
  result->mat[2].z = (float)(this->mat[10] * m->mat[2].z)
                   + (float)((float)(m->mat[2].y * this->mat[9]) + (float)(m->mat[2].x * this->mat[8]));
}

