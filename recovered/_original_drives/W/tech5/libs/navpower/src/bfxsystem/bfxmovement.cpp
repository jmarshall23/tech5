
// ========================================================================
// ?InterpretCrowdCollision@bfx@@YAXABVVec3@1@0AAUSteeringCollisionType@1@0M@Z
// EA  : 0x832C1A70
// RVA : 0x012C1A70
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmovement.cpp
// ========================================================================

void __fastcall bfx::InterpretCrowdCollision(
        const bfx::Vec3 *myVel,
        const bfx::Vec3 *neighborVel,
        bfx::SteeringCollisionType *colData,
        const bfx::Vec3 *vToNeighbor,
        double mySpeed)
{
  bool v5; // r30
  double v9; // fp13
  long double v14; // fp2
  double v15; // fp31
  double v16; // fp12
  long double v17; // fp2
  long double v18; // fp2
  double v19; // fp31
  double v20; // fp29
  double v21; // fp28
  bfx::UpAxis UpAxis; // r3
  bfx::Vec3 *UpVec; // r3
  BOOL m_bCrossPaths; // r11
  bfx::Vec3 v25[4]; // [sp+50h] [-60h] BYREF

  v5 = false;
  colData->m_bHaveRightOfWay = false;
  colData->m_bIsFaster = false;
  colData->m_bHeadOn = false;
  colData->m_bOvertaking = false;
  colData->m_bCrossPaths = false;
  colData->m_bNeighborIsToRight = false;
  v9 = __fsqrts((float)((float)(neighborVel->m_z * neighborVel->m_z)
                      + (float)((float)(neighborVel->m_x * neighborVel->m_x)
                              + (float)(neighborVel->m_y * neighborVel->m_y))));
  if ( v9 == 0.0 )
  {
    if ( mySpeed != 0.0 )
      goto LABEL_14;
  }
  else if ( mySpeed != 0.0 )
  {
    goto LABEL_11;
  }
  if ( v9 != 0.0 )
  {
    if ( mySpeed == 0.0 )
    {
LABEL_7:
      colData->m_bHaveRightOfWay = true;
      goto LABEL_8;
    }
LABEL_14:
    colData->m_bIsFaster = true;
    goto LABEL_8;
  }
LABEL_11:
  v16 = (float)((float)v9 * 1.2);
  if ( mySpeed >= v16 || v9 >= (float)((float)mySpeed * 1.2) )
  {
    if ( mySpeed < v16 )
      goto LABEL_7;
    goto LABEL_14;
  }
LABEL_8:
  _FP3 = (float)((float)__fsqrts((float)((float)(neighborVel->m_x * neighborVel->m_x)
                                       + (float)((float)(neighborVel->m_y * neighborVel->m_y)
                                               + (float)(neighborVel->m_z * neighborVel->m_z))))
               - 1.0842022e-19);
  _FP0 = (float)((float)__fsqrts((float)((float)(myVel->m_z * myVel->m_z)
                                       + (float)((float)(myVel->m_x * myVel->m_x) + (float)(myVel->m_y * myVel->m_y))))
               - 1.0842022e-19);
  __asm
  {
    fsel      f12, f3, f1, f30
    fsel      f11, f0, f13, f30
  }
  *((double *)&v14 + 1) = (float)((float)(myVel->m_y * (float)_FP11) * (float)(neighborVel->m_y * (float)_FP12));
  v15 = (float)((float)((float)(myVel->m_x * (float)_FP11) * (float)(neighborVel->m_x * (float)_FP12))
              + (float)((float)((float)(myVel->m_z * (float)_FP11) * (float)(neighborVel->m_z * (float)_FP12))
                      + (float)((float)(myVel->m_y * (float)_FP11) * (float)(neighborVel->m_y * (float)_FP12))));
  if ( v15 >= 0.0 || (*(_QWORD *)&v14 = 0x3FC6571855555556LL, v14 = cos(x: v14), -v15 <= (float)*(double *)&v14) )
  {
    if ( v15 <= 0.0 || (*(_QWORD *)&v14 = 0x3FD6571855555556LL, v14 = cos(x: v14), v15 <= (float)*(double *)&v14) )
    {
      *(_QWORD *)&v14 = 0x3FF0C15240000000LL;
      v17 = cos(x: v14);
      if ( v15 <= (float)*(double *)&v17 )
      {
        *(_QWORD *)&v17 = 0x4000C15240000000LL;
        v18 = cos(x: v17);
        if ( v15 >= (float)*(double *)&v18 )
          colData->m_bCrossPaths = true;
      }
    }
    else
    {
      colData->m_bOvertaking = true;
    }
  }
  else
  {
    colData->m_bHeadOn = true;
  }
  v19 = (float)((float)(vToNeighbor->m_z * myVel->m_x) - (float)(vToNeighbor->m_x * myVel->m_z));
  v20 = (float)((float)(vToNeighbor->m_x * myVel->m_y) - (float)(vToNeighbor->m_y * myVel->m_x));
  v21 = (float)((float)(vToNeighbor->m_y * myVel->m_z) - (float)(vToNeighbor->m_z * myVel->m_y));
  UpAxis = bfx::GetUpAxis();
  UpVec = bfx::GetUpVec(result: v25, upAxis: UpAxis);
  if ( (float)((float)(UpVec->m_x * (float)v21)
             + (float)((float)(UpVec->m_z * (float)v20) + (float)(UpVec->m_y * (float)v19))) > 0.0 )
    v5 = true;
  m_bCrossPaths = colData->m_bCrossPaths;
  colData->m_bNeighborIsToRight = v5;
  if ( m_bCrossPaths && !v5 && !colData->m_bIsFaster
    || colData->m_bOvertaking
    && (float)((float)(myVel->m_x * vToNeighbor->m_x)
             + (float)((float)(myVel->m_z * vToNeighbor->m_z) + (float)(myVel->m_y * vToNeighbor->m_y))) < 0.0 )
  {
    colData->m_bHaveRightOfWay = true;
  }
}

