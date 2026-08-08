
// ========================================================================
// ?NavProbe3D@idNpMover3D@@SA?AW4navProbeResult_t@@ABUidProbeInput3D@1@ABVidVec3@@1AAUidProbeResults3D@1@@Z
// EA  : 0x82DEE058
// RVA : 0x00DEE058
// PDB : w:\tech5\tungsten\game\navpower\navpowermover3d.cpp
// ========================================================================

BOOL __fastcall idNpMover3D::NavProbe3D(
        const idNpMover3D::idProbeInput3D *input,
        const idVec3 *start,
        const idVec3 *end,
        idNpMover3D::idProbeResults3D *results)
{
  double v9; // fp10
  double v10; // fp7
  double v11; // fp4
  double v14; // fp5
  double v15; // fp5
  double v16; // fp30
  double v17; // fp29
  double v18; // fp28
  double v19; // fp31
  double x; // fp13
  double y; // fp12
  double z; // fp11
  const bfx::Path3DSpec *v23; // r6
  bool v24; // r10
  double v25; // fp9
  unsigned int v26; // r11
  double v27; // fp8
  bool v28; // cr58
  double v29; // fp7
  double v30; // fp6
  double v31; // fp5
  double v32; // fp0
  double v33; // fp0
  bfx::Probe3DResults v34; // [sp+50h] [-A0h] BYREF
  float v35; // [sp+70h] [-80h]
  float v36; // [sp+80h] [-70h]
  float v37; // [sp+84h] [-6Ch]
  float v38; // [sp+88h] [-68h]
  float v39; // [sp+8Ch] [-64h]
  float v40; // [sp+90h] [-60h]
  float v41; // [sp+94h] [-5Ch]
  bool v42; // [sp+98h] [-58h]
  float v43; // [sp+9Ch] [-54h]

  if ( !bfx::AnyVolumesLoaded() )
    return false;
  v9 = (float)(end->x - start->x);
  v10 = (float)(end->z - start->z);
  v11 = (float)(end->y - start->y);
  LODWORD(v34.m_endPos.m_x) = (idNpMover3D::idProbeInput3D)input->useVolumes;
  v42 = false;
  _FP9 = (float)((float)((float)((float)v11 * (float)v11)
                       + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f6, f9, f1, f13 }
  v14 = __frsqrte(_FP6);
  v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                      * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                              * (float)0.5))
                                                                              * (float)v14)
                                                                      - (float)1.5)
                                                      * (float)v14)
                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                              + (float)((float)((float)v10 * (float)v10)
                                                                      + (float)((float)v9 * (float)v9)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                                                              + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                      * (float)0.5))
                                                                      * (float)v14)
                                                              - (float)1.5)
                                              * (float)v14))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v14
                                                      * (float)((float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)((float)v10 * (float)v10)
                                                                              + (float)((float)v9 * (float)v9)))
                                                              * (float)0.5))
                                              * (float)v14)
                                      - (float)1.5)
                      * (float)v14));
  v16 = (float)((float)v9
              * (float)((float)-(float)((float)((float)((float)v15
                                                      * (float)((float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)((float)v10 * (float)v10)
                                                                              + (float)((float)v9 * (float)v9)))
                                                              * (float)0.5))
                                              * (float)v15)
                                      - (float)1.5)
                      * (float)v15));
  v17 = (float)((float)((float)-(float)((float)((float)((float)v15
                                                      * (float)((float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)((float)v10 * (float)v10)
                                                                              + (float)((float)v9 * (float)v9)))
                                                              * (float)0.5))
                                              * (float)v15)
                                      - (float)1.5)
                      * (float)v15)
              * (float)v11);
  v18 = (float)((float)v10
              * (float)((float)-(float)((float)((float)((float)v15
                                                      * (float)((float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)((float)v10 * (float)v10)
                                                                              + (float)((float)v9 * (float)v9)))
                                                              * (float)0.5))
                                              * (float)v15)
                                      - (float)1.5)
                      * (float)v15));
  v19 = (float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                                              + (float)((float)((float)v10 * (float)v10)
                                                                                      + (float)((float)v9 * (float)v9)))
                                                                      * (float)0.5))
                                                      * (float)v15)
                                              - (float)1.5)
                              * (float)v15)
                      * (float)((float)((float)v11 * (float)v11)
                              + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))))
              - (float)1.0);
  idNavigationSpace::SetActiveSpace(this: &defaultSpace);
  x = start->x;
  y = start->y;
  z = start->z;
  v34.m_endPos.m_z = v16;
  v34.m_endNorm.m_x = v17;
  v34.m_endNorm.m_y = v18;
  *(float *)&v34.m_collided = x;
  v34.m_distTravelled = y;
  v35 = z;
  bfx::NavProbe3D(
    spaceHandle: &activeSpaceHandle,
    startPos: (const bfx::Vector3 *)&v34.m_collided,
    dir: (const bfx::Vector3 *)&v34.m_endPos.m_z,
    dist: v19,
    pathSpec: v23,
    clientResults: &v34);
  bfx::VolumeHandle::Release(this: &activeSpaceHandle);
  v24 = v42;
  v25 = v37;
  v26 = v42;
  v27 = v38;
  v28 = !v42;
  v29 = v39;
  v30 = v40;
  v31 = v41;
  results->endPos.x = v36;
  results->endPos.y = v25;
  results->endPos.z = v27;
  v32 = v43;
  results->endNorm.x = v29;
  results->endNorm.y = v30;
  results->endNorm.z = v31;
  results->distTotal = v19;
  results->distTravelled = v32;
  if ( v28 )
    v33 = 1.0;
  else
    v33 = (float)((float)v32 / (float)v19);
  results->distFraction = v33;
  results->collided = v24;
  return (_cntlzw(v26) & 0x20) != 0;
}

