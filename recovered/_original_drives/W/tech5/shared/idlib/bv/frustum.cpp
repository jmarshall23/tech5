
// ========================================================================
// ?ToPoints@idFrustum@@QBAXQAVidVec3@@@Z
// EA  : 0x82EFA3D0
// RVA : 0x00EFA3D0
// PDB : w:\tech5\shared\idlib\bv\frustum.cpp
// ========================================================================

void __fastcall idFrustum::ToPoints(idFrustum *this, idVec3 *points)
{
  double v2; // fp6
  double v3; // fp9
  double v4; // fp2
  double v5; // fp3
  double v6; // fp1
  double v7; // fp0
  double v8; // fp11
  double v9; // fp13
  double v10; // fp12
  double v11; // fp6
  double z; // fp7
  double x; // fp6
  double v14; // fp1
  double v15; // fp9
  double v16; // fp7
  double y; // fp6
  double v18; // fp12
  double v19; // fp2
  double v20; // fp0
  double v21; // fp4
  double v22; // fp7
  double v23; // fp1
  double dUp; // fp6
  double v25; // fp5
  double v26; // fp9
  double v27; // fp13
  double v28; // fp11
  double v29; // fp7
  double v30; // fp12
  double v31; // fp11
  double v32; // fp12
  double v33; // fp9
  double v34; // fp5
  double v35; // fp12
  double v36; // fp11

  v2 = (float)(this->origin.x + (float)(this->axis.mat[0].x * this->dNear));
  v3 = (float)(this->origin.z + (float)(this->dNear * this->axis.mat[0].z));
  v4 = (float)(this->origin.y + (float)(this->dNear * this->axis.mat[0].y));
  v5 = (float)((float)((float)(this->invFar * this->dNear) * this->dLeft) * this->axis.mat[1].x);
  v6 = (float)(this->axis.mat[1].y * (float)((float)(this->invFar * this->dNear) * this->dLeft));
  v7 = (float)(this->axis.mat[1].z * (float)((float)(this->invFar * this->dNear) * this->dLeft));
  v8 = (float)(this->axis.mat[2].z * (float)((float)(this->invFar * this->dNear) * this->dUp));
  v9 = (float)(this->axis.mat[2].x * (float)((float)(this->invFar * this->dNear) * this->dUp));
  v10 = (float)(this->axis.mat[2].y * (float)((float)(this->invFar * this->dNear) * this->dUp));
  points->x = (float)((float)((float)(this->invFar * this->dNear) * this->dLeft) * this->axis.mat[1].x)
            + (float)(this->origin.x + (float)(this->axis.mat[0].x * this->dNear));
  v11 = (float)((float)v2 - (float)v5);
  points->y = (float)v6 + (float)v4;
  points->z = (float)v7 + (float)v3;
  points[1].z = (float)v3 - (float)v7;
  points[1].y = (float)v4 - (float)v6;
  points[1].x = v11;
  points[2].y = (float)((float)v4 - (float)v6) - (float)v10;
  points[2].z = (float)((float)v3 - (float)v7) - (float)v8;
  points[2].x = (float)v11 - (float)v9;
  z = points->z;
  x = points->x;
  points[3].y = points->y - (float)v10;
  points[3].x = (float)x - (float)v9;
  points[3].z = (float)z - (float)v8;
  v14 = points->z;
  v15 = (float)((float)v10 + points->y);
  points->x = points->x + (float)v9;
  points->y = v15;
  points->z = (float)v14 + (float)v8;
  v16 = points[1].x;
  y = points[1].y;
  points[1].z = points[1].z + (float)v8;
  points[1].y = (float)y + (float)v10;
  points[1].x = (float)v16 + (float)v9;
  v18 = this->origin.x;
  v19 = this->axis.mat[2].z;
  v20 = this->axis.mat[2].x;
  v21 = (float)(this->origin.z + (float)(this->dFar * this->axis.mat[0].z));
  v22 = (float)(this->axis.mat[1].z * this->dLeft);
  v23 = (float)(this->axis.mat[0].x * this->dFar);
  dUp = this->dUp;
  v25 = (float)(this->axis.mat[1].y * this->dLeft);
  v26 = (float)(this->dLeft * this->axis.mat[1].x);
  v27 = (float)(this->axis.mat[2].y * this->dUp);
  v28 = (float)(this->origin.y + (float)(this->dFar * this->axis.mat[0].y));
  points[4].z = (float)(this->axis.mat[1].z * this->dLeft)
              + (float)(this->origin.z + (float)(this->dFar * this->axis.mat[0].z));
  v29 = (float)((float)v21 - (float)v22);
  points[4].y = (float)v25 + (float)v28;
  points[4].x = (float)v26 + (float)((float)v23 + (float)v18);
  v30 = (float)((float)((float)v23 + (float)v18) - (float)v26);
  points[5].z = v29;
  points[5].x = v30;
  points[5].y = (float)v28 - (float)v25;
  points[6].y = (float)((float)v28 - (float)v25) - (float)v27;
  points[6].x = (float)v30 - (float)((float)v20 * (float)dUp);
  points[6].z = (float)v29 - (float)((float)v19 * (float)dUp);
  v31 = (float)(points[4].z - (float)((float)v19 * (float)dUp));
  v32 = (float)(points[4].x - (float)((float)v20 * (float)dUp));
  points[7].y = points[4].y - (float)v27;
  points[7].z = v31;
  points[7].x = v32;
  v33 = points[4].y;
  v34 = (float)((float)((float)v19 * (float)dUp) + points[4].z);
  points[4].x = points[4].x + (float)((float)v20 * (float)dUp);
  points[4].y = (float)v27 + (float)v33;
  points[4].z = v34;
  v35 = points[5].z;
  v36 = (float)(points[5].y + (float)v27);
  points[5].x = points[5].x + (float)((float)v20 * (float)dUp);
  points[5].y = v36;
  points[5].z = (float)v35 + (float)((float)v19 * (float)dUp);
}

