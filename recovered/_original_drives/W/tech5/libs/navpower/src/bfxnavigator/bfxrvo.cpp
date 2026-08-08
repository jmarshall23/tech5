
// ========================================================================
// ?CalcTangentFromPointToCircle@bfx@@YAHABVVec3@1@0M0AAV21@1@Z
// EA  : 0x832BD8E0
// RVA : 0x012BD8E0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrvo.cpp
// ========================================================================

int __fastcall bfx::CalcTangentFromPointToCircle(
        const bfx::Vec3 *point,
        const bfx::Vec3 *circleCenter,
        double circleRadius,
        const bfx::Vec3 *circleNorm,
        bfx::Vec3 *vTouch1,
        bfx::Vec3 *vTouch2,
        float *a7)
{
  double v7; // fp0
  double v8; // fp13
  double v9; // fp3
  double v10; // fp2
  double v11; // fp8
  double v12; // fp8
  double v14; // fp7
  double v15; // fp6
  double v16; // fp8
  double v17; // fp9
  double v18; // fp10
  double v19; // fp6
  double v20; // fp3
  double v21; // fp12
  double v22; // fp2
  double v23; // fp9
  double v24; // fp7
  double v25; // fp1

  v8 = (float)(circleCenter->m_z
             - (float)(vTouch1->m_z
                     * (float)((float)(vTouch1->m_z * (float)(circleCenter->m_z - point->m_z))
                             + (float)((float)(vTouch1->m_x * (float)(circleCenter->m_x - point->m_x))
                                     + (float)(vTouch1->m_y * (float)(circleCenter->m_y - point->m_y))))));
  v9 = (float)(point->m_y
             - (float)(circleCenter->m_y
                     - (float)(vTouch1->m_y
                             * (float)((float)(vTouch1->m_z * (float)(circleCenter->m_z - point->m_z))
                                     + (float)((float)(vTouch1->m_x * (float)(circleCenter->m_x - point->m_x))
                                             + (float)(vTouch1->m_y * (float)(circleCenter->m_y - point->m_y)))))));
  v10 = (float)(point->m_z
              - (float)(circleCenter->m_z
                      - (float)(vTouch1->m_z
                              * (float)((float)(vTouch1->m_z * (float)(circleCenter->m_z - point->m_z))
                                      + (float)((float)(vTouch1->m_x * (float)(circleCenter->m_x - point->m_x))
                                              + (float)(vTouch1->m_y * (float)(circleCenter->m_y - point->m_y)))))));
  v11 = (float)(point->m_x
              - (float)(circleCenter->m_x
                      - (float)(vTouch1->m_x
                              * (float)((float)(vTouch1->m_z * (float)(circleCenter->m_z - point->m_z))
                                      + (float)((float)(vTouch1->m_x * (float)(circleCenter->m_x - point->m_x))
                                              + (float)(vTouch1->m_y * (float)(circleCenter->m_y - point->m_y)))))));
  v12 = (float)((float)((float)v11 * (float)v11)
              + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)));
  if ( v12 < (float)((float)circleRadius * (float)circleRadius) )
    return 0;
  v14 = (float)((float)v12 - (float)((float)circleRadius * (float)circleRadius));
  if ( v14 > 0.00000095367432 )
  {
    v15 = __fsqrts(v12);
    v16 = (float)((float)1.0 / (float)v15);
    v17 = (float)((float)((float)1.0 / (float)v15) * (float)((float)circleRadius * (float)circleRadius));
    v20 = (float)((float)(vTouch1->m_x
                        * (float)((float)((float)1.0 / (float)v15)
                                * (float)((float)(circleCenter->m_z
                                                - (float)(vTouch1->m_z
                                                        * (float)((float)(vTouch1->m_z
                                                                        * (float)(circleCenter->m_z - point->m_z))
                                                                + (float)((float)(vTouch1->m_x
                                                                                * (float)(circleCenter->m_x - point->m_x))
                                                                        + (float)(vTouch1->m_y
                                                                                * (float)(circleCenter->m_y - point->m_y))))))
                                        - point->m_z)))
                - (float)(vTouch1->m_z
                        * (float)((float)((float)1.0 / (float)v15)
                                * (float)((float)(circleCenter->m_x
                                                - (float)(vTouch1->m_x
                                                        * (float)((float)(vTouch1->m_z
                                                                        * (float)(circleCenter->m_z - point->m_z))
                                                                + (float)((float)(vTouch1->m_x
                                                                                * (float)(circleCenter->m_x - point->m_x))
                                                                        + (float)(vTouch1->m_y
                                                                                * (float)(circleCenter->m_y - point->m_y))))))
                                        - point->m_x))));
    v18 = (float)((float)__fsqrts(v14) * (float)((float)((float)1.0 / (float)v15) * (float)circleRadius));
    v21 = (float)((float)(circleCenter->m_x
                        - (float)(vTouch1->m_x
                                * (float)((float)(vTouch1->m_z * (float)(circleCenter->m_z - point->m_z))
                                        + (float)((float)(vTouch1->m_x * (float)(circleCenter->m_x - point->m_x))
                                                + (float)(vTouch1->m_y * (float)(circleCenter->m_y - point->m_y))))))
                - (float)((float)((float)((float)1.0 / (float)v15)
                                * (float)((float)(circleCenter->m_x
                                                - (float)(vTouch1->m_x
                                                        * (float)((float)(vTouch1->m_z
                                                                        * (float)(circleCenter->m_z - point->m_z))
                                                                + (float)((float)(vTouch1->m_x
                                                                                * (float)(circleCenter->m_x - point->m_x))
                                                                        + (float)(vTouch1->m_y
                                                                                * (float)(circleCenter->m_y - point->m_y))))))
                                        - point->m_x))
                        * (float)((float)((float)1.0 / (float)v15) * (float)((float)circleRadius * (float)circleRadius))));
    v7 = (float)(circleCenter->m_y
               - (float)(vTouch1->m_y
                       * (float)((float)(vTouch1->m_z * (float)(circleCenter->m_z - point->m_z))
                               + (float)((float)(vTouch1->m_x * (float)(circleCenter->m_x - point->m_x))
                                       + (float)(vTouch1->m_y * (float)(circleCenter->m_y - point->m_y))))));
    v22 = (float)((float)v7
                - (float)((float)((float)((float)1.0 / (float)v15) * (float)((float)v7 - point->m_y))
                        * (float)((float)((float)1.0 / (float)v15) * (float)((float)circleRadius * (float)circleRadius))));
    v24 = (float)((float)((float)(vTouch1->m_z
                                * (float)((float)((float)1.0 / (float)v15)
                                        * (float)((float)(circleCenter->m_y
                                                        - (float)(vTouch1->m_y
                                                                * (float)((float)(vTouch1->m_z
                                                                                * (float)(circleCenter->m_z - point->m_z))
                                                                        + (float)((float)(vTouch1->m_x
                                                                                        * (float)(circleCenter->m_x
                                                                                                - point->m_x))
                                                                                + (float)(vTouch1->m_y
                                                                                        * (float)(circleCenter->m_y
                                                                                                - point->m_y))))))
                                                - point->m_y)))
                        - (float)(vTouch1->m_y
                                * (float)((float)((float)1.0 / (float)v15)
                                        * (float)((float)(circleCenter->m_z
                                                        - (float)(vTouch1->m_z
                                                                * (float)((float)(vTouch1->m_z
                                                                                * (float)(circleCenter->m_z - point->m_z))
                                                                        + (float)((float)(vTouch1->m_x
                                                                                        * (float)(circleCenter->m_x
                                                                                                - point->m_x))
                                                                                + (float)(vTouch1->m_y
                                                                                        * (float)(circleCenter->m_y
                                                                                                - point->m_y))))))
                                                - point->m_z))))
                * (float)v18);
    v19 = (float)((float)(vTouch1->m_y
                        * (float)((float)((float)1.0 / (float)v15)
                                * (float)((float)(circleCenter->m_x
                                                - (float)(vTouch1->m_x
                                                        * (float)((float)(vTouch1->m_z
                                                                        * (float)(circleCenter->m_z - point->m_z))
                                                                + (float)((float)(vTouch1->m_x
                                                                                * (float)(circleCenter->m_x - point->m_x))
                                                                        + (float)(vTouch1->m_y
                                                                                * (float)(circleCenter->m_y - point->m_y))))))
                                        - point->m_x)))
                - (float)(vTouch1->m_x
                        * (float)((float)((float)1.0 / (float)v15)
                                * (float)((float)(circleCenter->m_y
                                                - (float)(vTouch1->m_y
                                                        * (float)((float)(vTouch1->m_z
                                                                        * (float)(circleCenter->m_z - point->m_z))
                                                                + (float)((float)(vTouch1->m_x
                                                                                * (float)(circleCenter->m_x - point->m_x))
                                                                        + (float)(vTouch1->m_y
                                                                                * (float)(circleCenter->m_y - point->m_y))))))
                                        - point->m_y))));
    v25 = (float)((float)((float)v8 - (float)((float)((float)v16 * (float)((float)v8 - point->m_z)) * (float)v17))
                - (float)((float)v19 * (float)v18));
    v23 = (float)((float)v8 - (float)((float)((float)v16 * (float)((float)v8 - point->m_z)) * (float)v17));
    vTouch2->m_z = v25;
    vTouch2->m_x = (float)v21 - (float)v24;
    vTouch2->m_y = (float)v22 - (float)((float)v20 * (float)v18);
    *a7 = (float)v24 + (float)v21;
    a7[1] = (float)((float)v20 * (float)v18) + (float)v22;
    a7[2] = (float)((float)v19 * (float)v18) + (float)v23;
    return 2;
  }
  else
  {
    *vTouch2 = *point;
    return 1;
  }
}


// ========================================================================
// ?MakeWedgeHelper@bfx@@YA?AVRVOWedge@1@ABVVec3@1@0000@Z
// EA  : 0x832BDAA8
// RVA : 0x012BDAA8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrvo.cpp
// ========================================================================

bfx::RVOWedge *__fastcall bfx::MakeWedgeHelper(
        bfx::RVOWedge *result,
        const bfx::Vec3 *velCircPtLeft,
        const bfx::Vec3 *velCircPtRight,
        const bfx::Vec3 *velocityCircleCenter,
        const bfx::Vec3 *myForward,
        const bfx::Vec3 *myLeft)
{
  long double v7; // fp4
  long double v8; // fp2
  double v9; // fp31
  double v10; // fp30
  long double v11; // fp2
  double v12; // fp29
  long double v13; // fp4
  long double v14; // fp2

  *((double *)&v7 + 1) = (float)((float)(myForward->m_x * (float)(velCircPtRight->m_x - velocityCircleCenter->m_x))
                               + (float)(myForward->m_y * (float)(velCircPtRight->m_y - velocityCircleCenter->m_y)));
  *(double *)&v7 = (float)((float)(myLeft->m_x * (float)(velCircPtRight->m_x - velocityCircleCenter->m_x))
                         + (float)(myLeft->m_y * (float)(velCircPtRight->m_y - velocityCircleCenter->m_y)));
  *((double *)&v8 + 1) = (float)((float)(myForward->m_z * (float)(velCircPtLeft->m_z - velocityCircleCenter->m_z))
                               + (float)((float)(myForward->m_x * (float)(velCircPtLeft->m_x - velocityCircleCenter->m_x))
                                       + (float)(myForward->m_y * (float)(velCircPtLeft->m_y - velocityCircleCenter->m_y))));
  *(double *)&v8 = (float)((float)(myLeft->m_z * (float)(velCircPtLeft->m_z - velocityCircleCenter->m_z))
                         + (float)((float)(myLeft->m_x * (float)(velCircPtLeft->m_x - velocityCircleCenter->m_x))
                                 + (float)(myLeft->m_y * (float)(velCircPtLeft->m_y - velocityCircleCenter->m_y))));
  v9 = (float)((float)(myForward->m_z * (float)(velCircPtRight->m_z - velocityCircleCenter->m_z))
             + (float)((float)(myForward->m_x * (float)(velCircPtRight->m_x - velocityCircleCenter->m_x))
                     + (float)(myForward->m_y * (float)(velCircPtRight->m_y - velocityCircleCenter->m_y))));
  v10 = (float)((float)(myLeft->m_z * (float)(velCircPtRight->m_z - velocityCircleCenter->m_z))
              + (float)((float)(myLeft->m_x * (float)(velCircPtRight->m_x - velocityCircleCenter->m_x))
                      + (float)(myLeft->m_y * (float)(velCircPtRight->m_y - velocityCircleCenter->m_y))));
  v11 = atan2(v: v8, u: v7);
  v12 = (float)*(double *)&v11;
  *((double *)&v11 + 1) = v9;
  *(double *)&v11 = v10;
  v14 = atan2(v: v11, u: v13);
  result->m_leftAngle = v12;
  result->m_rightAngle = *(double *)&v14;
  return result;
}


// ========================================================================
// ?CollideLineAndSphere2Results@bfx@@YA_NABVVec3@1@00MAAM1@Z
// EA  : 0x832BDB90
// RVA : 0x012BDB90
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrvo.cpp
// ========================================================================

int __fastcall bfx::CollideLineAndSphere2Results(
        const bfx::Vec3 *lineStart,
        const bfx::Vec3 *normalizedLineDir,
        const bfx::Vec3 *spherePos,
        double radius,
        float *retvalDist1,
        float *retvalDist2,
        float *a7)
{
  double v7; // fp13
  double v8; // fp0
  double v9; // fp3
  double v10; // fp1
  double v11; // fp2
  double v13; // fp12

  v7 = (float)((float)radius * (float)radius);
  *retvalDist2 = 3.4028235e38;
  *a7 = 3.4028235e38;
  v8 = (float)((float)(normalizedLineDir->m_z * (float)(spherePos->m_z - lineStart->m_z))
             + (float)((float)(normalizedLineDir->m_x * (float)(spherePos->m_x - lineStart->m_x))
                     + (float)(normalizedLineDir->m_y * (float)(spherePos->m_y - lineStart->m_y))));
  v9 = (float)((float)(lineStart->m_y
                     + (float)(normalizedLineDir->m_y
                             * (float)((float)(normalizedLineDir->m_z * (float)(spherePos->m_z - lineStart->m_z))
                                     + (float)((float)(normalizedLineDir->m_x * (float)(spherePos->m_x - lineStart->m_x))
                                             + (float)(normalizedLineDir->m_y * (float)(spherePos->m_y - lineStart->m_y))))))
             - spherePos->m_y);
  v10 = (float)((float)(lineStart->m_x
                      + (float)(normalizedLineDir->m_x
                              * (float)((float)(normalizedLineDir->m_z * (float)(spherePos->m_z - lineStart->m_z))
                                      + (float)((float)(normalizedLineDir->m_x * (float)(spherePos->m_x - lineStart->m_x))
                                              + (float)(normalizedLineDir->m_y * (float)(spherePos->m_y - lineStart->m_y))))))
              - spherePos->m_x);
  v11 = (float)((float)(lineStart->m_z
                      + (float)(normalizedLineDir->m_z
                              * (float)((float)(normalizedLineDir->m_z * (float)(spherePos->m_z - lineStart->m_z))
                                      + (float)((float)(normalizedLineDir->m_x * (float)(spherePos->m_x - lineStart->m_x))
                                              + (float)(normalizedLineDir->m_y * (float)(spherePos->m_y - lineStart->m_y))))))
              - spherePos->m_z);
  if ( (float)((float)((float)v10 * (float)v10)
             + (float)((float)((float)v11 * (float)v11) + (float)((float)v9 * (float)v9))) > v7 )
    return 0;
  v13 = __fsqrts((float)((float)v7
                       - (float)((float)((float)v10 * (float)v10)
                               + (float)((float)((float)v11 * (float)v11) + (float)((float)v9 * (float)v9)))));
  *retvalDist2 = (float)v13
               + (float)((float)(normalizedLineDir->m_z * (float)(spherePos->m_z - lineStart->m_z))
                       + (float)((float)(normalizedLineDir->m_x * (float)(spherePos->m_x - lineStart->m_x))
                               + (float)(normalizedLineDir->m_y * (float)(spherePos->m_y - lineStart->m_y))));
  *a7 = (float)v8 - (float)v13;
  return 1;
}


// ========================================================================
// ?MakeWedge@bfx@@YAHAAVRVOWedge@1@0ABVVec3@1@111111MPAURVODebugDrawInfo@1@@Z
// EA  : 0x832BDC40
// RVA : 0x012BDC40
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrvo.cpp
// ========================================================================

int __fastcall bfx::MakeWedge(
        bfx::RVOWedge *wedgeOut1,
        bfx::RVOWedge *wedgeOut2,
        const bfx::Vec3 *startPos1,
        const bfx::Vec3 *startPos2,
        const bfx::Vec3 *myPos,
        const bfx::Vec3 *myNorm,
        const bfx::Vec3 *myForward,
        const bfx::Vec3 *myLeft,
        double velocityCircleRadius,
        const bfx::Vec3 *velocityCircleCenter,
        bfx::RVODebugDrawInfo *pDebugInfo,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        const bfx::Vec3 *a29,
        int a30,
        int a31,
        int a32,
        int a33)
{
  double m_x; // fp30
  float m_y; // r9
  double v41; // fp7
  double v42; // fp6
  float v43; // r10
  double v44; // fp13
  double v45; // fp1
  double v46; // fp9
  double v47; // fp4
  double v48; // fp1
  double v49; // fp0
  double v50; // fp27
  double v51; // fp12
  double v52; // fp13
  double v53; // fp29
  double v54; // fp11
  double v55; // fp0
  double v56; // fp1
  double v57; // fp29
  double v59; // fp13
  double v60; // fp11
  double v61; // fp12
  double v62; // fp11
  double v63; // fp12
  double v64; // fp9
  double v65; // fp10
  double v66; // fp8
  double v70; // fp29
  double v71; // fp28
  double v72; // fp27
  double v74; // fp25
  double v75; // fp24
  double v76; // fp23
  float *v77; // r3
  const bfx::Vec3 *v78; // r5
  int v79; // r10
  char v80; // r6
  char v81; // r3
  double v82; // fp7
  double v83; // fp6
  double v84; // fp5
  double v85; // fp10
  double m_z; // fp8
  double v87; // fp20
  double v88; // fp21
  double v89; // fp22
  double v90; // fp17
  double v91; // fp18
  double v92; // fp19
  double m_leftAngle; // fp8
  double v94; // fp4
  double v95; // fp10
  double v96; // fp12
  double v97; // fp29
  double v98; // fp25
  double v99; // fp28
  double v100; // fp30
  double v101; // fp27
  double v102; // fp31
  bfx::RVOWedge *WedgeHelper; // r3
  bfx::RVOWedge *v104; // r3
  bfx::RVOWedge *v105; // r3
  bfx::RVOWedge *v106; // r3
  float v107; // [sp+50h] [-110h] BYREF
  float v108; // [sp+54h] [-10Ch] BYREF
  float v109[2]; // [sp+58h] [-108h] BYREF
  bfx::RVOWedge v110; // [sp+60h] [-100h] BYREF
  bfx::Vec3 v111; // [sp+68h] [-F8h] BYREF
  bfx::Vec3 v112; // [sp+78h] [-E8h] BYREF
  bfx::Vec3 v113; // [sp+88h] [-D8h] BYREF
  bfx::Vec3 v114[11]; // [sp+98h] [-C8h] BYREF

  if ( a33 != 0 )
  {
    *(_DWORD *)(a33 + 112) = 0;
    *(bfx::Vec3 *)(a33 + 8) = *startPos1;
    *(bfx::Vec3 *)(a33 + 20) = *startPos2;
    *(bfx::Vec3 *)(a33 + 32) = *myPos;
    *(float *)(a33 + 44) = a29->m_x;
    *(float *)(a33 + 48) = a29->m_y;
    *(float *)(a33 + 52) = a29->m_z;
    *(_DWORD *)(a33 + 60) = 0;
    *(float *)(a33 + 56) = velocityCircleRadius;
  }
  m_x = myPos->m_x;
  m_y = myPos->m_y;
  v41 = (float)(startPos1->m_x - myPos->m_x);
  v42 = startPos1->m_y;
  v43 = myPos->m_x;
  v44 = myNorm->m_y;
  v45 = (float)(startPos1->m_y - m_y);
  v114[0].m_z = myPos->m_z;
  v114[0].m_y = m_y;
  v46 = (float)(a29->m_x - v43);
  v114[0].m_x = v43;
  v47 = (float)(startPos2->m_x - (float)m_x);
  v49 = (float)((float)((float)(startPos1->m_z - myPos->m_z) * (float)v44) - (float)((float)v45 * myNorm->m_z));
  v48 = (float)((float)((float)v45 * myNorm->m_x) - (float)((float)v41 * (float)v44));
  v50 = (float)((float)((float)v41 * myNorm->m_z) - (float)((float)(startPos1->m_z - myPos->m_z) * myNorm->m_x));
  v51 = (float)((float)((float)(startPos2->m_y - m_y) * myNorm->m_z)
              - (float)((float)(startPos2->m_z - myPos->m_z) * (float)v44));
  v52 = (float)((float)((float)(startPos2->m_x - (float)m_x) * (float)v44)
              - (float)((float)(startPos2->m_y - m_y) * myNorm->m_x));
  v53 = (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48));
  v55 = (float)((float)((float)(a29->m_y - m_y)
                      * (float)((float)((float)v41 * myNorm->m_z)
                              - (float)((float)(startPos1->m_z - myPos->m_z) * myNorm->m_x)))
              + (float)((float)((float)v46 * (float)v49) + (float)((float)(a29->m_z - v114[0].m_z) * (float)v48)));
  v56 = (float)((float)v55 * (float)v55);
  v57 = (float)((float)((float)((float)((float)v50 * (float)v50) + (float)v53) * (float)velocityCircleRadius)
              * (float)velocityCircleRadius);
  if ( v55 <= 0.0 || v56 <= v57 )
  {
    v54 = (float)((float)((float)(startPos2->m_z - myPos->m_z) * myNorm->m_x)
                - (float)((float)(startPos2->m_x - (float)m_x) * myNorm->m_z));
    v60 = (float)((float)((float)((float)v54 * (float)v54)
                        + (float)((float)((float)v51 * (float)v51) + (float)((float)v52 * (float)v52)))
                * (float)velocityCircleRadius);
    v59 = (float)((float)((float)(a29->m_y - m_y)
                        * (float)((float)((float)(startPos2->m_z - myPos->m_z) * myNorm->m_x)
                                - (float)((float)(startPos2->m_x - (float)m_x) * myNorm->m_z)))
                + (float)((float)((float)v46 * (float)v51) + (float)((float)(a29->m_z - v114[0].m_z) * (float)v52)));
    v61 = (float)((float)v59 * (float)v59);
    v62 = (float)((float)v60 * (float)velocityCircleRadius);
    if ( v59 <= 0.0 || v61 <= v62 )
    {
      if ( v55 < 0.0 && v56 > v57 && v59 < 0.0 && v61 > v62 )
      {
        wedgeOut1->m_leftAngle = 3.1415927;
        wedgeOut1->m_rightAngle = -3.1415927;
        return 1;
      }
      v63 = (float)(startPos1->m_z - myPos->m_z);
      v64 = (float)((float)v42 - myPos->m_y);
      v65 = (float)(startPos2->m_z - myPos->m_z);
      v66 = (float)(startPos2->m_y - myPos->m_y);
      _FP3 = (float)((float)__fsqrts((float)((float)((float)v64 * (float)v64)
                                           + (float)((float)((float)v41 * (float)v41) + (float)((float)v63 * (float)v63))))
                   - (float)1.0842022e-19);
      __asm { fsel      f6, f3, f2, f26 }
      _FP5 = (float)((float)__fsqrts((float)((float)((float)v66 * (float)v66)
                                           + (float)((float)((float)(startPos2->m_x - (float)m_x)
                                                           * (float)(startPos2->m_x - (float)m_x))
                                                   + (float)((float)v65 * (float)v65))))
                   - (float)1.0842022e-19);
      v70 = (float)((float)v41 * (float)_FP6);
      v114[0].m_x = (float)v41 * (float)_FP6;
      v71 = (float)((float)v64 * (float)_FP6);
      v114[0].m_y = (float)v64 * (float)_FP6;
      v72 = (float)((float)v63 * (float)_FP6);
      v114[0].m_z = (float)v63 * (float)_FP6;
      __asm { fsel      f2, f5, f3, f26 }
      v74 = (float)((float)v47 * (float)_FP2);
      v113.m_x = (float)v47 * (float)_FP2;
      v75 = (float)((float)v66 * (float)_FP2);
      v113.m_y = (float)v66 * (float)_FP2;
      v76 = (float)((float)v65 * (float)_FP2);
      v113.m_z = (float)v65 * (float)_FP2;
      v77 = (float *)bfx::CollideLineAndSphere2Results(
                       lineStart: myPos,
                       normalizedLineDir: v114,
                       spherePos: a29,
                       radius: velocityCircleRadius,
                       retvalDist1: &startPos2->m_x,
                       retvalDist2: &v107,
                       a7: v109);
      v81 = bfx::CollideLineAndSphere2Results(
              lineStart: myPos,
              normalizedLineDir: &v113,
              spherePos: v78,
              radius: velocityCircleRadius,
              retvalDist1: v77,
              retvalDist2: &v108,
              a7: &v110.m_leftAngle);
      if ( v80 != 0 || v81 != 0 )
      {
        v82 = v107;
        v83 = v108;
        if ( v80 == 0 || v81 == 0 || v82 >= 0.0 || v83 >= 0.0 )
        {
          v84 = v109[0];
          if ( v80 != 0 )
          {
            v85 = myPos->m_y;
            m_z = myPos->m_z;
            v87 = (float)((float)m_x + (float)((float)v70 * v107));
            v88 = (float)((float)((float)v71 * v107) + myPos->m_y);
            v111.m_y = (float)((float)v71 * v107) + myPos->m_y;
            v111.m_x = (float)m_x + (float)((float)v70 * v107);
            v89 = (float)((float)((float)v72 * v107) + (float)m_z);
            v111.m_z = (float)((float)v72 * v107) + (float)m_z;
            v90 = (float)((float)m_x + (float)((float)v70 * v109[0]));
            v113.m_x = (float)m_x + (float)((float)v70 * v109[0]);
            v91 = (float)((float)((float)v71 * v109[0]) + (float)v85);
            v113.m_y = (float)((float)v71 * v109[0]) + (float)v85;
            v92 = (float)((float)((float)v72 * v109[0]) + (float)m_z);
            v113.m_z = (float)((float)v72 * v109[0]) + (float)m_z;
          }
          else
          {
            v89 = v111.m_z;
            v88 = v111.m_y;
            v87 = v111.m_x;
            v92 = v113.m_z;
            v91 = v113.m_y;
            v90 = v113.m_x;
          }
          m_leftAngle = v110.m_leftAngle;
          if ( v81 != 0 )
          {
            v94 = myPos->m_z;
            v95 = myPos->m_y;
            v96 = (float)((float)((float)v76 * v108) + myPos->m_z);
            v112.m_z = (float)((float)v76 * v108) + myPos->m_z;
            v97 = (float)((float)m_x + (float)((float)v74 * v108));
            v112.m_x = (float)m_x + (float)((float)v74 * v108);
            v98 = (float)((float)m_x + (float)((float)v74 * v110.m_leftAngle));
            v114[0].m_x = v98;
            v99 = (float)((float)((float)v76 * v110.m_leftAngle) + (float)v94);
            v114[0].m_z = (float)((float)v76 * v110.m_leftAngle) + (float)v94;
            v100 = (float)((float)((float)v75 * v108) + (float)v95);
            v112.m_y = (float)((float)v75 * v108) + (float)v95;
            v101 = (float)((float)((float)v75 * v110.m_leftAngle) + (float)v95);
            v114[0].m_y = (float)((float)v75 * v110.m_leftAngle) + (float)v95;
            v102 = v96;
          }
          else
          {
            v102 = v112.m_z;
            v100 = v112.m_y;
            v97 = v112.m_x;
            v99 = v114[0].m_z;
            v101 = v114[0].m_y;
            v98 = v114[0].m_x;
          }
          if ( v80 != 0 )
          {
            if ( v81 != 0 && v82 > 0.0 && v84 > 0.0 && v83 > 0.0 && m_leftAngle > 0.0 )
            {
              *wedgeOut1 = *bfx::MakeWedgeHelper(
                              result: &v110,
                              velCircPtLeft: &v111,
                              velCircPtRight: &v112,
                              velocityCircleCenter: a29,
                              myForward,
                              myLeft);
              if ( a33 != 0 )
              {
                ++*(_DWORD *)(a33 + 60);
                *(float *)(a33 + 64) = v87;
                *(float *)(a33 + 68) = v88;
                *(float *)(a33 + 72) = v89;
                *(float *)(a33 + 76) = v97;
                *(float *)(a33 + 80) = v100;
                *(float *)(a33 + 84) = v102;
                *(_BYTE *)(a33 + 113) = 1;
                *(_BYTE *)(a33 + 112) = 1;
              }
              WedgeHelper = bfx::MakeWedgeHelper(
                              result: &v110,
                              velCircPtLeft: v114,
                              velCircPtRight: &v113,
                              velocityCircleCenter: a29,
                              myForward,
                              myLeft);
              v79 = 2;
              *wedgeOut2 = *WedgeHelper;
              if ( a33 == 0 )
                return v79;
              ++*(_DWORD *)(a33 + 60);
              *(float *)(a33 + 64) = v90;
              *(float *)(a33 + 68) = v91;
              *(float *)(a33 + 72) = v92;
LABEL_49:
              *(float *)(a33 + 76) = v98;
              *(float *)(a33 + 80) = v101;
              *(float *)(a33 + 84) = v99;
              goto LABEL_50;
            }
            if ( v81 != 0 && v82 > 0.0 && v83 > 0.0 )
            {
              v104 = bfx::MakeWedgeHelper(
                       result: &v110,
                       velCircPtLeft: &v111,
                       velCircPtRight: &v112,
                       velocityCircleCenter: a29,
                       myForward,
                       myLeft);
              v79 = 1;
              *wedgeOut1 = *v104;
              if ( a33 != 0 )
              {
                ++*(_DWORD *)(a33 + 60);
                *(float *)(a33 + 64) = v87;
                *(float *)(a33 + 68) = v88;
                *(float *)(a33 + 72) = v89;
                *(float *)(a33 + 76) = v97;
                *(float *)(a33 + 80) = v100;
                *(float *)(a33 + 84) = v102;
LABEL_50:
                *(_BYTE *)(a33 + 112) = 1;
                *(_BYTE *)(a33 + 113) = 1;
                return v79;
              }
              return v79;
            }
            if ( v82 > 0.0 && v84 > 0.0 )
            {
              v105 = bfx::MakeWedgeHelper(
                       result: &v110,
                       velCircPtLeft: &v111,
                       velCircPtRight: &v113,
                       velocityCircleCenter: a29,
                       myForward,
                       myLeft);
              v79 = 1;
              *wedgeOut1 = *v105;
              if ( a33 != 0 )
              {
                ++*(_DWORD *)(a33 + 60);
                *(float *)(a33 + 64) = v87;
                *(float *)(a33 + 68) = v88;
                *(float *)(a33 + 72) = v89;
                *(float *)(a33 + 76) = v90;
                *(float *)(a33 + 80) = v91;
                *(float *)(a33 + 84) = v92;
                goto LABEL_50;
              }
              return v79;
            }
          }
          if ( v81 == 0 )
            return v79;
          if ( v83 <= 0.0 )
            return v79;
          if ( m_leftAngle <= 0.0 )
            return v79;
          v106 = bfx::MakeWedgeHelper(
                   result: &v110,
                   velCircPtLeft: v114,
                   velCircPtRight: &v112,
                   velocityCircleCenter: a29,
                   myForward,
                   myLeft);
          v79 = 1;
          *wedgeOut1 = *v106;
          if ( a33 == 0 )
            return v79;
          ++*(_DWORD *)(a33 + 60);
          *(float *)(a33 + 64) = v97;
          *(float *)(a33 + 68) = v100;
          *(float *)(a33 + 72) = v102;
          goto LABEL_49;
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?MakeWedgeForOverlapped@bfx@@YAHAAVRVOWedge@1@ABVVec3@1@111PAURVODebugDrawInfo@1@@Z
// EA  : 0x832BE300
// RVA : 0x012BE300
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrvo.cpp
// ========================================================================

int __fastcall bfx::MakeWedgeForOverlapped(
        bfx::RVOWedge *wedgeOut1,
        const bfx::Vec3 *myPos,
        const bfx::Vec3 *myForward,
        const bfx::Vec3 *myLeft,
        const bfx::Vec3 *yourPos,
        bfx::RVODebugDrawInfo *pDebugInfo)
{
  double v7; // fp0
  double v8; // fp13
  double v9; // fp11
  double v10; // fp10
  long double v11; // fp4
  long double v12; // fp2
  long double v13; // fp2

  if ( pDebugInfo != nullptr )
    pDebugInfo->m_overlapped = true;
  v7 = (float)(myPos->m_z - yourPos->m_z);
  v8 = (float)(myPos->m_y - yourPos->m_y);
  v9 = (float)((float)((float)(myPos->m_x - yourPos->m_x) * (float)(myPos->m_x - yourPos->m_x))
             + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)));
  if ( v9 >= 0.00000095367432 )
  {
    v10 = __fsqrts(v9);
    *((double *)&v11 + 1) = myForward->m_x;
    *(double *)&v11 = (float)((float)1.0 / (float)v10);
    *(double *)&v12 = (float)((float)(myForward->m_x
                                    * (float)((float)((float)1.0 / (float)v10) * (float)(myPos->m_x - yourPos->m_x)))
                            + (float)((float)(myForward->m_z
                                            * (float)((float)((float)1.0 / (float)v10)
                                                    * (float)(myPos->m_z - yourPos->m_z)))
                                    + (float)(myForward->m_y
                                            * (float)((float)((float)1.0 / (float)v10)
                                                    * (float)(myPos->m_y - yourPos->m_y)))));
    *((double *)&v12 + 1) = -(float)((float)(myLeft->m_x
                                           * (float)((float)((float)1.0 / (float)v10)
                                                   * (float)(myPos->m_x - yourPos->m_x)))
                                   + (float)((float)(myLeft->m_z
                                                   * (float)((float)((float)1.0 / (float)v10)
                                                           * (float)(myPos->m_z - yourPos->m_z)))
                                           + (float)(myLeft->m_y
                                                   * (float)((float)((float)1.0 / (float)v10)
                                                           * (float)(myPos->m_y - yourPos->m_y)))));
    v13 = atan2(v: v12, u: v11);
    wedgeOut1->m_rightAngle = *(double *)&v13;
    wedgeOut1->m_leftAngle = (float)*(double *)&v13 + (float)3.1415927;
  }
  else
  {
    wedgeOut1->m_leftAngle = 3.1415927;
    wedgeOut1->m_rightAngle = -3.1415927;
  }
  return 1;
}


// ========================================================================
// ?Reserve@RepulsorsForRVO@bfx@@QAAXH@Z
// EA  : 0x832BE408
// RVA : 0x012BE408
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrvo.cpp
// ========================================================================

void __fastcall bfx::RepulsorsForRVO::Reserve(bfx::RepulsorsForRVO *this, int count)
{
  if ( count > this->m_cap )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_pRecs);
    this->m_pRecs = (bfx::RVOEntityRecord *)bfx::MemoryManager::Malloc(
                                              this: bfx::g_pCurInstance->m_pMemoryManager,
                                              size: 40 * count,
                                              tag: bfx::MEM_BFXNAVIGATOR);
    this->m_cap = count;
  }
}


// ========================================================================
// ?SortedInsertIntoArray@RVOWedge@bfx@@SAXAAV?$Array@VRVOWedge@bfx@@@2@ABV12@@Z
// EA  : 0x832BE960
// RVA : 0x012BE960
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrvo.cpp
// ========================================================================

void __fastcall bfx::RVOWedge::SortedInsertIntoArray(
        bfx::Array<bfx::ReplayLogListenerEntry> *theArray,
        const bfx::RVOWedge *wedgeIn)
{
  bfx::RVOWedge *m_data; // r11
  bfx::RVOWedge *v3; // r10
  bfx::Array<bfx::RVOWedge>::iterator v4; // [sp+50h] [-20h] BYREF
  bfx::Array<bfx::RVOWedge> v5; // [sp+54h] [-1Ch] BYREF

  *(bfx::RVOWedge *)&v5.m_size = *wedgeIn;
  if ( *(float *)&v5.m_cap > (double)*(float *)&v5.m_size )
    *(float *)&v5.m_size = *(float *)&v5.m_size + (float)6.2831855;
  m_data = (bfx::RVOWedge *)theArray->m_data;
  v3 = (bfx::RVOWedge *)&theArray->m_data[theArray->m_size];
  v4.m_ptr = (bfx::RVOWedge *)theArray->m_data;
  if ( v4.m_ptr == v3 )
  {
LABEL_7:
    bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
      this: theArray,
      val: (const bfx::ReplayLogListenerEntry *)&v5.m_size);
  }
  else
  {
    while ( *(float *)&v5.m_cap >= (double)m_data->m_rightAngle )
    {
      if ( ++m_data == v3 )
      {
        v4.m_ptr = m_data;
        goto LABEL_7;
      }
    }
    v4.m_ptr = m_data;
    bfx::Array<bfx::RVOWedge>::insert(this: &v5, result: theArray, iter: &v4, val: (const bfx::RVOWedge *)&v5.m_size);
  }
}


// ========================================================================
// ?MergeOverlaps@RVOWedge@bfx@@SAXAAV?$Array@VRVOWedge@bfx@@@2@@Z
// EA  : 0x832BEA18
// RVA : 0x012BEA18
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrvo.cpp
// ========================================================================

void __fastcall bfx::RVOWedge::MergeOverlaps(bfx::Array<bfx::RVOWedge> *theArray)
{
  int m_size; // r10
  char *v3; // r29
  bfx::RVOWedge *m_data; // r30
  bfx::RVOWedge *v5; // r11
  int v6; // r10
  int v11; // r8
  bfx::ReplayLogListenerEntry *v12; // r11
  double v13; // fp12
  unsigned int v15; // r11
  float *v16; // r10
  bfx::ReplayLogListenerEntry v18; // [sp+58h] [-58h] BYREF
  bfx::Array<bfx::ReplayLogListenerEntry> v19; // [sp+60h] [-50h] BYREF

  m_size = theArray->m_size;
  if ( m_size != 0 )
  {
    v3 = nullptr;
    memset(&v19, 0, 12);
    v19.m_tag = bfx::MEM_BFXNAVIGATOR;
    m_data = theArray->m_data;
    v5 = &theArray->m_data[m_size];
    v6 = 0;
    _FP13 = 3.4028235e38;
    _FP0 = -3.4028235e38;
    if ( theArray->m_data != v5 )
    {
      do
      {
        if ( v6 != 0 )
        {
          if ( m_data->m_rightAngle <= _FP0 )
          {
            _FP10 = (float)((float)_FP13 - m_data->m_rightAngle);
            _FP9 = (float)((float)_FP0 - m_data->m_leftAngle);
            ++v6;
            __asm
            {
              fsel      f13, f10, f12, f13
              fsel      f0, f9, f0, f11
            }
          }
          else
          {
            *(float *)&v18.m_pListener = _FP0;
            *(float *)&v18.m_clientOwned = _FP13;
            bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: &v19, val: &v18);
            _FP0 = m_data->m_leftAngle;
            _FP13 = m_data->m_rightAngle;
            v6 = 1;
          }
        }
        else
        {
          _FP0 = m_data->m_leftAngle;
          v6 = 1;
          _FP13 = m_data->m_rightAngle;
        }
        ++m_data;
      }
      while ( m_data != &theArray->m_data[theArray->m_size] );
      if ( v6 != 0 )
      {
        *(float *)&v18.m_pListener = _FP0;
        *(float *)&v18.m_clientOwned = _FP13;
        bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: &v19, val: &v18);
      }
      v11 = v19.m_size;
      v3 = (char *)v19.m_data;
      if ( v19.m_size > 1u )
      {
        v12 = &v19.m_data[v19.m_size];
        v13 = *(float *)&v12[-1].m_pListener;
        if ( v13 >= 3.1415927 )
        {
          _FP31 = *(float *)&v12[-1].m_pListener;
          v15 = 0;
          v16 = (float *)&v19.m_data[-1];
          do
          {
            if ( v13 < (float)(v16[3] + 6.2831855) )
              break;
            v16 += 2;
            ++v15;
            _FP11 = (float)((float)_FP31 - (float)(*v16 + 6.2831855));
            __asm { fsel      f31, f11, f31, f0 }
          }
          while ( v15 < v19.m_size - 1 );
          if ( v15 != 0 )
          {
            bfx::Array<bfx::RVOWedge>::erase_section(
              this: (bfx::Array<bfx::RVOWedge> *)&v19,
              sectionStartIndex: 0,
              sectionEndIndex: v15 - 1);
            v11 = v19.m_size;
            v3 = (char *)v19.m_data;
          }
          *(float *)&v3[8 * v11 - 8] = _FP31;
        }
      }
    }
    bfx::Array<bfx::RVOWedge>::operator=(this: theArray, rhs: (const bfx::Array<bfx::RVOWedge> *)&v19);
    if ( v3 != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v3);
  }
}


// ========================================================================
// __unwind$21848
// EA  : 0x832BEBF0
// RVA : 0x012BEBF0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrvo.cpp
// ========================================================================

void _unwind_21848()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 176 + 96));
}


// ========================================================================
// ?CalcRVOs@bfx@@YAXPAVRVOEntityRecord@1@ABVVec3@1@1MMAAVRepulsorsForRVO@1@AAV?$Array@VRVOWedge@bfx@@@1@PAV?$Array@URVODebugDrawInfo@bfx@@@1@@Z
// EA  : 0x832BEC18
// RVA : 0x012BEC18
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrvo.cpp
// ========================================================================

void __fastcall bfx::CalcRVOs(
        bfx::RVOEntityRecord *pMyRVORec,
        const bfx::Vec3 *myNorm,
        const bfx::Vec3 *myForward,
        double radiusLimit,
        double heightLimit,
        bfx::RepulsorsForRVO *repRecs,
        bfx::Array<bfx::RVOWedge> *wedges,
        bfx::Array<bfx::RVODebugDrawInfo> *pRVODebugData,
        bfx::Array<bfx::ReplayLogListenerEntry> *a9,
        int a10)
{
  int m_cap; // r11
  double m_y; // fp8
  float v20; // r6
  double v21; // fp12
  float m_z; // r5
  double m_x; // fp5
  bfx::RVODebugDrawInfo *m_data; // r31
  double v25; // fp10
  double v26; // fp11
  double v27; // fp6
  double v28; // fp7
  double v29; // fp3
  double v30; // fp1
  double v31; // fp4
  double v32; // fp11
  double v33; // fp8
  double v34; // fp24
  int v37; // r23
  double v38; // fp28
  double v39; // fp27
  double v40; // fp26
  float v41; // r11
  double v42; // fp7
  float v43; // r9
  double v44; // fp3
  double v45; // fp6
  float v46; // r8
  double v47; // fp5
  float v48; // r7
  double v49; // fp4
  double v50; // fp0
  double v51; // fp5
  double v52; // fp8
  double v53; // fp1
  double v54; // fp2
  float v55; // r6
  double v56; // fp0
  double v57; // fp13
  double v58; // fp12
  double v59; // fp31
  double v60; // fp29
  double v61; // fp30
  int v62; // r3
  int Wedge; // r3
  int v64; // r29
  const bfx::Vec3 *v65; // [sp+8h] [-218h]
  bfx::RVODebugDrawInfo *v66; // [sp+Ch] [-214h]
  int v67; // [sp+10h] [-210h]
  int v68; // [sp+14h] [-20Ch]
  int v69; // [sp+18h] [-208h]
  int v70; // [sp+1Ch] [-204h]
  int v71; // [sp+20h] [-200h]
  int v72; // [sp+24h] [-1FCh]
  int v73; // [sp+28h] [-1F8h]
  int v74; // [sp+2Ch] [-1F4h]
  int v75; // [sp+30h] [-1F0h]
  int v76; // [sp+34h] [-1ECh]
  int v77; // [sp+38h] [-1E8h]
  int v78; // [sp+3Ch] [-1E4h]
  int v79; // [sp+40h] [-1E0h]
  int v80; // [sp+44h] [-1DCh]
  int v81; // [sp+48h] [-1D8h]
  int v82; // [sp+4Ch] [-1D4h]
  int v83; // [sp+50h] [-1D0h]
  int v84; // [sp+58h] [-1C8h]
  int v85; // [sp+5Ch] [-1C4h]
  int v86; // [sp+60h] [-1C0h]
  bfx::Vec3 v87; // [sp+70h] [-1B0h] BYREF
  bfx::RVOWedge v88; // [sp+80h] [-1A0h] BYREF
  bfx::RVOWedge v89; // [sp+88h] [-198h] BYREF
  float v90; // [sp+90h] [-190h]
  float v91; // [sp+94h] [-18Ch]
  float v92; // [sp+98h] [-188h]
  bfx::Vec3 v93; // [sp+A0h] [-180h] BYREF
  bfx::Vec3 v94; // [sp+B0h] [-170h] BYREF
  bfx::Vec3 v95; // [sp+C0h] [-160h] BYREF
  bfx::Vec3 v96; // [sp+D0h] [-150h] BYREF
  bfx::Vec3 v97; // [sp+E0h] [-140h] BYREF
  bfx::RVODebugDrawInfo v98; // [sp+F0h] [-130h] BYREF

  m_cap = a9->m_cap;
  a9->m_size = 0;
  if ( m_cap < 32 )
    bfx::Array<bfx::NavWedge>::expand_cap(this: a9, size: 32);
  if ( a10 != 0 )
  {
    *(_DWORD *)(a10 + 4) = 0;
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: *(char **)a10);
    *(_DWORD *)a10 = 0;
    *(_DWORD *)(a10 + 8) = 0;
  }
  bfx::numTimesCallingMakeWedge = 0;
  m_y = myNorm->m_y;
  v20 = pMyRVORec->m_pos.m_y;
  v21 = myForward->m_y;
  m_z = pMyRVORec->m_pos.m_z;
  m_x = pMyRVORec->m_vel.m_x;
  m_data = pRVODebugData->m_data;
  v25 = myForward->m_z;
  v26 = myNorm->m_x;
  v27 = (float)(myForward->m_x * myNorm->m_y);
  v28 = (float)((float)(myForward->m_x * myNorm->m_z) - (float)(myNorm->m_x * myForward->m_z));
  v29 = pMyRVORec->m_vel.m_z;
  v30 = (float)(pMyRVORec->m_vel.m_y * pMyRVORec->m_vel.m_y);
  v31 = (float)(myForward->m_y * myNorm->m_z);
  v87.m_x = pMyRVORec->m_pos.m_x;
  v87.m_y = v20;
  v87.m_z = m_z;
  v32 = (float)((float)((float)v26 * (float)v21) - (float)v27);
  v33 = (float)((float)((float)v25 * (float)m_y) - (float)v31);
  v34 = __fsqrts((float)((float)((float)v29 * (float)v29) + (float)((float)((float)m_x * (float)m_x) + (float)v30)));
  _FP1 = (float)((float)__fsqrts((float)((float)((float)v33 * (float)v33)
                                       + (float)((float)((float)v32 * (float)v32) + (float)((float)v28 * (float)v28))))
               - (float)1.0842022e-19);
  __asm { fsel      f12, f1, f13, f23 }
  v93.m_x = (float)v33 * (float)_FP12;
  v93.m_y = (float)v28 * (float)_FP12;
  v93.m_z = (float)v32 * (float)_FP12;
  if ( v34 >= 0.0009765625 )
  {
    v37 = 0;
    if ( pRVODebugData->m_size > 0 )
    {
      v38 = v87.m_z;
      v39 = v87.m_y;
      v40 = v87.m_x;
      do
      {
        v41 = m_data->m_startPos1.m_z;
        v42 = (float)(*(float *)&m_data->m_yourID - (float)v40);
        v43 = m_data->m_startPos2.m_x;
        v44 = myNorm->m_z;
        v45 = myNorm->m_x;
        v46 = myNorm->m_x;
        v47 = m_data->m_startPos1.m_x;
        v48 = myNorm->m_y;
        v90 = m_data->m_startPos1.m_y;
        v91 = v41;
        v49 = (float)((float)v47 - (float)v38);
        v92 = v43;
        v50 = myNorm->m_y;
        v51 = (float)((float)(myNorm->m_y * v41) + (float)((float)v44 * v43));
        v52 = m_data->m_startPos2.m_y;
        v53 = (float)(*(float *)&m_data->m_overlapped - (float)v39);
        v54 = (float)((float)radiusLimit - m_data->m_startPos2.m_y);
        v55 = myNorm->m_z;
        v94.m_x = v46;
        v94.m_y = v48;
        v94.m_z = v55;
        v57 = (float)((float)v44
                    * (float)((float)((float)v50 * (float)v53)
                            + (float)((float)((float)v44 * (float)v49) + (float)((float)v45 * (float)v42))));
        v58 = (float)((float)v45
                    * (float)((float)((float)v50 * (float)v53)
                            + (float)((float)((float)v44 * (float)v49) + (float)((float)v45 * (float)v42))));
        v59 = (float)(v90 - (float)((float)v45 * (float)((float)((float)v45 * v90) + (float)v51)));
        v60 = (float)(v43 - (float)((float)v44 * (float)((float)((float)v45 * v90) + (float)v51)));
        v61 = (float)(v41 - (float)((float)v50 * (float)((float)((float)v45 * v90) + (float)v51)));
        v56 = (float)((float)v50
                    * (float)((float)((float)v50 * (float)v53)
                            + (float)((float)((float)v44 * (float)v49) + (float)((float)v45 * (float)v42))));
        if ( (float)((float)((float)((float)v42 - (float)v58) * (float)((float)v42 - (float)v58))
                   + (float)((float)((float)((float)v49 - (float)v57) * (float)((float)v49 - (float)v57))
                           + (float)((float)((float)v53 - (float)v56) * (float)((float)v53 - (float)v56)))) <= (double)(float)((float)v54 * (float)v54)
          && (float)((float)((float)v58 * (float)v58)
                   + (float)((float)((float)v57 * (float)v57) + (float)((float)v56 * (float)v56))) <= (double)(float)((float)heightLimit * (float)heightLimit) )
        {
          v62 = bfx::CalcTangentFromPointToCircle(
                  point: &v87,
                  circleCenter: (const bfx::Vec3 *)m_data,
                  circleRadius: (float)(pMyRVORec->m_radiusDat.m_radius + (float)v52),
                  circleNorm: (const bfx::Vec3 *)LODWORD(m_z),
                  vTouch1: &v94,
                  vTouch2: &v97,
                  a7: &v96.m_x);
          v98.m_yourID = -1;
          v98.m_overlapped = false;
          v88.m_leftAngle = 0.0;
          v88.m_rightAngle = 0.0;
          v89.m_leftAngle = 0.0;
          *(_DWORD *)v98.m_isValidVelCircPt = 0;
          v89.m_rightAngle = 0.0;
          v98.m_numWedges = 0;
          if ( v62 == 2 )
          {
            v95.m_x = (float)v40 - (float)v59;
            v95.m_y = (float)v39 - (float)v61;
            v95.m_z = (float)v38 - (float)v60;
            Wedge = bfx::MakeWedge(
                      wedgeOut1: &v88,
                      wedgeOut2: &v89,
                      startPos1: &v97,
                      startPos2: &v96,
                      myPos: &v87,
                      myNorm,
                      myForward,
                      myLeft: &v93,
                      velocityCircleRadius: v34,
                      velocityCircleCenter: v65,
                      pDebugInfo: v66,
                      a12: v67,
                      a13: v68,
                      a14: v69,
                      a15: v70,
                      a16: v71,
                      a17: v72,
                      a18: v73,
                      a19: v74,
                      a20: v75,
                      a21: v76,
                      a22: v77,
                      a23: v78,
                      a24: v79,
                      a25: v80,
                      a26: v81,
                      a27: v82,
                      a28: v83,
                      a29: &v95,
                      a30: v84,
                      a31: v85,
                      a32: v86,
                      a33: a10 == 0 ? 0 : (unsigned int)&v98);
            ++bfx::numTimesCallingMakeWedge;
          }
          else
          {
            Wedge = bfx::MakeWedgeForOverlapped(
                      wedgeOut1: &v88,
                      myPos: &v87,
                      myForward,
                      myLeft: &v93,
                      yourPos: (const bfx::Vec3 *)m_data,
                      pDebugInfo: a10 == 0 ? nullptr : &v98);
          }
          v64 = Wedge;
          if ( a10 != 0 )
          {
            v98.m_yourID = LODWORD(m_data->m_myPos.m_y);
            bfx::Array<bfx::RVODebugDrawInfo>::push_back(this: (bfx::Array<bfx::RVODebugDrawInfo> *)a10, val: &v98);
          }
          if ( v64 > 0 )
            bfx::RVOWedge::SortedInsertIntoArray(theArray: a9, wedgeIn: &v88);
          if ( v64 > 1 )
            bfx::RVOWedge::SortedInsertIntoArray(theArray: a9, wedgeIn: &v89);
        }
        ++v37;
        m_data = (bfx::RVODebugDrawInfo *)((char *)m_data + 40);
      }
      while ( v37 < pRVODebugData->m_size );
    }
    if ( a9->m_size > 1 )
      bfx::RVOWedge::MergeOverlaps(theArray: (bfx::Array<bfx::RVOWedge> *)a9);
  }
}


// ========================================================================
// ?IsAngleInRVO@bfx@@YA_NMAAV?$Array@VRVOWedge@bfx@@@1@@Z
// EA  : 0x832BEFC0
// RVA : 0x012BEFC0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrvo.cpp
// ========================================================================

int __fastcall bfx::IsAngleInRVO(double angleToYou, bfx::Array<bfx::RVOWedge> *wedges, int a3)
{
  double v4; // fp1
  float *v5; // r11
  int v6; // r10
  double v7; // fp13
  double v8; // fp0
  double v9; // fp13
  double v10; // fp0
  int result; // r3

  if ( *(_DWORD *)(a3 + 4) == 0 )
    return 0;
  v4 = bfx::Limit180(angle: angleToYou);
  v5 = *(float **)a3;
  v6 = 8 * *(_DWORD *)(a3 + 4) + *(_DWORD *)a3;
  if ( *(_DWORD *)a3 == v6 )
  {
LABEL_7:
    v9 = *(float *)(v6 - 8);
    if ( v9 > 3.1415927 )
    {
      v10 = (float)((float)v4 + 6.2831855);
      if ( v9 >= v10 )
      {
        result = 1;
        if ( v10 >= *(float *)(v6 - 4) )
          return result;
      }
    }
    return 0;
  }
  while ( 1 )
  {
    v7 = v5[1];
    v8 = *v5;
    if ( v7 != v8 && v8 >= v4 && v4 >= v7 )
      return 1;
    v5 += 2;
    if ( v5 == (float *)v6 )
      goto LABEL_7;
  }
}


// ========================================================================
// ?FindHedgehogRVOMismatch@bfx@@YA_NPAVRVOEntityRecord@1@ABVVec3@1@ABVVec2@1@ABVRepulsorsForRVO@1@AAV?$Array@VRVOWedge@bfx@@@1@AAV?$Array@VHedgehogSpine@bfx@@@1@AAV?$Array@UHedgehogDebugDrawInfo@bfx@@@1@@Z
// EA  : 0x832BF090
// RVA : 0x012BF090
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrvo.cpp
// ========================================================================

BOOL __fastcall bfx::FindHedgehogRVOMismatch(
        bfx::RVOEntityRecord *pMyRepRec,
        const bfx::Vec3 *myUpVec,
        bfx::Vec2 *myHeading,
        const bfx::RepulsorsForRVO *repRecs,
        bfx::Array<bfx::RVOWedge> *wedges,
        bfx::Array<bfx::ReplayLogListenerEntry> *hedgehog,
        bfx::Array<bfx::QueuedTri> *hedgehogDebugArray)
{
  double v14; // fp13
  double m_x; // fp12
  double m_z; // fp11
  double m_y; // fp9
  char v18; // r25
  double v19; // fp31
  bfx::Vec2 *v20; // r3
  double m_w; // fp29
  double v22; // fp28
  bfx::Quat *v23; // r3
  int v24; // r22
  double v25; // fp27
  int m_size; // r11
  bfx::RVOEntityRecord *m_pRecs; // r31
  unsigned __int8 v28; // r28
  int v29; // r30
  double v30; // fp31
  double m_radius; // fp12
  double v32; // fp11
  double v33; // fp10
  double v34; // fp0
  double v35; // fp13
  double v36; // fp12
  double v37; // fp12
  double v38; // fp1
  char IsAngleInRVO; // r3
  bool v40; // r30
  double v41; // fp0
  bfx::Vec2 v43; // [sp+50h] [-140h] BYREF
  bfx::Vec2 v44; // [sp+58h] [-138h] BYREF
  bfx::Vec2 v45; // [sp+60h] [-130h] BYREF
  bfx::Vec2 v46; // [sp+68h] [-128h]
  bfx::Vec2 v47; // [sp+70h] [-120h] BYREF
  bfx::Vec3 v48; // [sp+78h] [-118h] BYREF
  bfx::Quat v49; // [sp+88h] [-108h] BYREF
  bfx::Quat v50; // [sp+A0h] [-F0h] BYREF
  bfx::HedgehogDebugDrawInfo v51; // [sp+B0h] [-E0h] BYREF

  if ( repRecs->m_size == 0 || wedges->m_size == 0 )
    return false;
  bfx::Array<bfx::HoleRecord>::clear(this: hedgehogDebugArray);
  v14 = (float)(pMyRepRec->m_vel.m_y * pMyRepRec->m_vel.m_y);
  m_x = pMyRepRec->m_vel.m_x;
  m_z = pMyRepRec->m_vel.m_z;
  m_y = pMyRepRec->m_pos.m_y;
  v18 = 0;
  v44.m_x = pMyRepRec->m_pos.m_x;
  v44.m_y = m_y;
  v19 = __fsqrts((float)((float)((float)m_z * (float)m_z) + (float)((float)((float)m_x * (float)m_x) + (float)v14)));
  v20 = bfx::Vec2::UnitVec(this: &v47, result: myHeading);
  m_w = (float)(v20->m_x * (float)v19);
  v22 = (float)(v20->m_y * (float)v19);
  v23 = bfx::Quat::Quat(this: &v50, axis: myUpVec, angle: 0.087266468);
  v24 = 0;
  v25 = 0.0;
  do
  {
    m_size = repRecs->m_size;
    v43.m_x = 0.0;
    m_pRecs = repRecs->m_pRecs;
    v43.m_y = 0.0;
    v45.m_x = 0.0;
    v45.m_y = 0.0;
    v28 = 0;
    v29 = 0;
    v30 = 0.0;
    if ( m_size > 0 )
    {
      while ( 1 )
      {
        m_radius = m_pRecs->m_radiusDat.m_radius;
        v32 = m_pRecs->m_pos.m_x;
        v43.m_x = m_pRecs->m_pos.m_x;
        v33 = m_pRecs->m_pos.m_y;
        v43.m_y = m_pRecs->m_pos.m_y;
        v34 = (float)(m_pRecs->m_vel.m_x - (float)m_w);
        v35 = (float)(m_pRecs->m_vel.m_y - (float)v22);
        v30 = (float)((float)m_radius + pMyRepRec->m_radiusDat.m_radius);
        v36 = (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34));
        if ( v36 > 0.0
          && (float)((float)((float)(v44.m_y - (float)v33) * (float)(v44.m_y - (float)v33))
                   + (float)((float)(v44.m_x - (float)v32) * (float)(v44.m_x - (float)v32))) >= (double)(float)((float)v30 * (float)v30) )
        {
          v37 = __fsqrts(v36);
          v46.m_x = (float)((float)1.0 / (float)v37) * (float)(m_pRecs->m_vel.m_x - (float)m_w);
          v46.m_y = (float)((float)1.0 / (float)v37) * (float)v35;
          v45 = v46;
          v38 = bfx::CollideLineAndCircle(lineStart: &v43, normalizedLineDir: &v45, circlePos: &v44, radius: v30);
          if ( v38 < 3.4028235e38 && v38 >= 0.0 )
            break;
        }
        ++v29;
        ++m_pRecs;
        if ( v29 >= repRecs->m_size )
          goto LABEL_12;
      }
      v28 = 1;
    }
LABEL_12:
    IsAngleInRVO = bfx::IsAngleInRVO(
                     angleToYou: (float)((float)v25 * (float)0.017453292),
                     wedges: (bfx::Array<bfx::RVOWedge> *)v23,
                     a3: (int)wedges);
    v47.m_x = (float)v25 * (float)0.017453292;
    v40 = IsAngleInRVO;
    LODWORD(v47.m_y) = (_cntlzw(v28) & 0x20) != 0;
    bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
      this: hedgehog,
      val: (const bfx::ReplayLogListenerEntry *)&v47);
    if ( v28 != v40 )
      ++v24;
    if ( v28 != 0 || v18 == 0 )
    {
      v41 = pMyRepRec->m_pos.m_z;
      v51.m_spineHit = v28;
      v51.m_inRVO = v40;
      v18 = 1;
      v51.m_spineAngleInDegrees = v25;
      v51.m_probeStart.m_x = v43.m_x;
      v51.m_probeStart.m_y = v43.m_y;
      v51.m_probeNormalizedDir.m_x = v45.m_x;
      v51.m_probeNormalizedDir.m_y = v45.m_y;
      v51.m_probeNormalizedDir.m_z = 0.0;
      v51.m_sphereCenter.m_x = v44.m_x;
      v51.m_sphereCenter.m_y = v44.m_y;
      v51.m_sphereRadius = v30;
      v51.m_sphereCenter.m_z = v41;
      v51.m_probeStart.m_z = v41;
      bfx::Array<bfx::HedgehogDebugDrawInfo>::push_back(
        this: (bfx::Array<bfx::HedgehogDebugDrawInfo> *)hedgehogDebugArray,
        val: &v51);
    }
    v48.m_x = m_w;
    v48.m_y = v22;
    v48.m_z = 0.0;
    v23 = bfx::Quat::Apply(this: &v49, result: &v50, v: &v48);
    v25 = (float)((float)v25 + (float)5.0);
    v22 = v23->m_x;
    m_w = v23->m_w;
    v48.m_z = v23->m_y;
  }
  while ( v25 < 360.0 );
  return v24 != 0;
}

