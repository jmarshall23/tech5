
// ========================================================================
// ?Area2d@bfx@@YAMABVVec3@1@00W4UpAxis@1@@Z
// EA  : 0x832924D0
// RVA : 0x012924D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.cpp
// ========================================================================

float __fastcall bfx::Area2d(const bfx::Vec3 *posA, const bfx::Vec3 *posB, const bfx::Vec3 *posC, unsigned int upAxis)
{
  double v4; // fp1

  if ( upAxis > 5 )
  {
    v4 = 0.0;
  }
  else
  {
    switch ( upAxis )
    {
      case 1u:
        v4 = (float)((float)((float)(posC->m_x - posA->m_x) * (float)(posB->m_z - posA->m_z))
                   - (float)((float)(posB->m_x - posA->m_x) * (float)(posC->m_z - posA->m_z)));
        break;
      case 2u:
        v4 = (float)((float)((float)(posB->m_x - posA->m_x) * (float)(posC->m_y - posA->m_y))
                   - (float)((float)(posC->m_x - posA->m_x) * (float)(posB->m_y - posA->m_y)));
        break;
      case 3u:
        v4 = (float)((float)((float)(posC->m_y - posA->m_y) * (float)(posB->m_z - posA->m_z))
                   - (float)((float)(posC->m_z - posA->m_z) * (float)(posB->m_y - posA->m_y)));
        break;
      case 4u:
        v4 = (float)((float)((float)(posB->m_x - posA->m_x) * (float)(posC->m_z - posA->m_z))
                   - (float)((float)(posC->m_x - posA->m_x) * (float)(posB->m_z - posA->m_z)));
        break;
      default:
        if ( upAxis != 0 )
          v4 = (float)((float)((float)(posC->m_x - posA->m_x) * (float)(posB->m_y - posA->m_y))
                     - (float)((float)(posB->m_x - posA->m_x) * (float)(posC->m_y - posA->m_y)));
        else
          v4 = (float)((float)((float)(posC->m_z - posA->m_z) * (float)(posB->m_y - posA->m_y))
                     - (float)((float)(posC->m_y - posA->m_y) * (float)(posB->m_z - posA->m_z)));
        break;
    }
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?GetLinkBetweenAdjAreasIfBetter@bfx@@YAPAVHalfLink@1@PAVArea@1@0ABVVec3@1@1ABVPathSpec@1@@Z
// EA  : 0x83292588
// RVA : 0x01292588
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.cpp
// ========================================================================

bfx::HalfLink *__fastcall bfx::GetLinkBetweenAdjAreasIfBetter(
        bfx::Area *pArea0,
        bfx::Area *pArea1,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *goalPos,
        const bfx::PathSpec *pathSpec)
{
  bfx::HalfLink *m_pFirstLink; // r31
  double v7; // fp12
  double v9; // fp9
  bfx::HalfLink *v12; // r28
  double i; // fp31
  char v14; // r11
  bfx::HalfLink *m_pTwin; // r11
  bfx::Area *m_pArea; // r11
  double v17; // fp0
  bfx::Vec3 v19; // [sp+50h] [-60h] BYREF
  bfx::Vec3 v20; // [sp+60h] [-50h] BYREF

  m_pFirstLink = pArea0->m_pFirstLink;
  v7 = (float)(goalPos->m_y - startPos->m_y);
  v9 = (float)(goalPos->m_z - startPos->m_z);
  v12 = nullptr;
  for ( i = __fsqrts((float)((float)((float)(goalPos->m_x - startPos->m_x) * (float)(goalPos->m_x - startPos->m_x))
                           + (float)((float)((float)v9 * (float)v9) + (float)((float)v7 * (float)v7))));
        m_pFirstLink != nullptr;
        m_pFirstLink = m_pFirstLink->m_pNext )
  {
    if ( (*((_BYTE *)m_pFirstLink + 44) & 0x80) == 0
      || (*((_BYTE *)m_pFirstLink + 44) & 0x40) != 0
      || (v14 = 1, (*((_BYTE *)m_pFirstLink + 44) & 0x20) != 0) )
    {
      v14 = 0;
    }
    if ( v14 != 0 )
    {
      m_pTwin = m_pFirstLink->m_pTwin;
      if ( m_pTwin != nullptr )
        m_pArea = m_pTwin->m_pArea;
      else
        m_pArea = nullptr;
      if ( m_pArea == pArea1
        && (m_pFirstLink->m_pLinkBase->m_linkDat.m_linkUsageFlags & pathSpec->m_linkUsageFlags) != 0 )
      {
        bfx::GetClosestPtOnLineSeg(result: &v19, seg: &m_pFirstLink->m_startSeg, pos: startPos);
        bfx::GetClosestPtOnLineSeg(result: &v20, seg: &m_pFirstLink->m_pTwin->m_startSeg, pos: goalPos);
        v17 = (float)((float)((float)__fsqrts((float)((float)((float)(v20.m_x - v19.m_x) * (float)(v20.m_x - v19.m_x))
                                                    + (float)((float)((float)(v20.m_z - v19.m_z)
                                                                    * (float)(v20.m_z - v19.m_z))
                                                            + (float)((float)(v20.m_y - v19.m_y)
                                                                    * (float)(v20.m_y - v19.m_y)))))
                            * m_pFirstLink->m_pLinkBase->m_linkDat.m_penaltyMult)
                    + (float)((float)__fsqrts((float)((float)((float)(v19.m_x - startPos->m_x)
                                                            * (float)(v19.m_x - startPos->m_x))
                                                    + (float)((float)((float)(v19.m_z - startPos->m_z)
                                                                    * (float)(v19.m_z - startPos->m_z))
                                                            + (float)((float)(v19.m_y - startPos->m_y)
                                                                    * (float)(v19.m_y - startPos->m_y)))))
                            + (float)__fsqrts((float)((float)((float)(goalPos->m_x - v20.m_x)
                                                            * (float)(goalPos->m_x - v20.m_x))
                                                    + (float)((float)((float)(goalPos->m_z - v20.m_z)
                                                                    * (float)(goalPos->m_z - v20.m_z))
                                                            + (float)((float)(goalPos->m_y - v20.m_y)
                                                                    * (float)(goalPos->m_y - v20.m_y)))))));
        if ( v17 < i )
        {
          i = v17;
          v12 = m_pFirstLink;
        }
      }
    }
  }
  return v12;
}


// ========================================================================
// ?GetNextCorner@bfx@@YA_NABVPathCC@1@0ABVVec3@1@ABVLineSeg@1@MW4UpAxis@1@1AAV31@AAV21@AAW4CornerType@1@@Z
// EA  : 0x83292780
// RVA : 0x01292780
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall bfx::GetNextCorner(
        const bfx::PathCC *startCC,
        const bfx::PathCC *goalCC,
        const bfx::Vec3 *startPos,
        const bfx::LineSeg *inputGoalSeg,
        double maxShrinkDist,
        bfx::UpAxis upAxis,
        const bfx::Vec3 *pathStartPos,
        bfx::Vec3 *nextCorner,
        bfx::PathCC *nextCornerCC,
        bfx::CornerType *cornerType,
        int a11,
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
        const bfx::Path **a29,
        int a30,
        _DWORD *a31)
{
  char *v32; // r10
  _DWORD *p_m_z; // r9
  int i; // ctr
  bool v38; // r28
  const bfx::Path *m_pPath; // r11
  double v40; // fp18
  float *v41; // r10
  float v42; // r4
  float v43; // r7
  char v44; // r11
  __int64 v46; // r10
  double v47; // fp25
  double v48; // fp24
  double v49; // fp23
  __int64 v50; // r26
  const bfx::Path *v51; // r22
  int v52; // r30
  int v53; // r24
  double v54; // fp22
  int *v55; // r23
  int v56; // r5
  bfx::Area **m_data; // r6
  double v58; // fp21
  double v59; // fp20
  char v60; // r19
  bfx::Area *v61; // r27
  bfx::Area *v62; // r29
  bfx::Area *v63; // r4
  int SharedEdgeIdx; // r31
  __int64 v65; // r18 OVERLAPPED
  int v66; // r16 OVERLAPPED
  signed int v67; // r7
  float *v68; // r11
  float v69; // r5
  float *v70; // r10
  float v71; // r4
  float v72; // r9
  float v73; // r8
  double m_x; // fp26
  float v75; // r6
  double v76; // fp27
  double v77; // fp28
  double v78; // fp29
  double v79; // fp30
  double v80; // fp31
  bool v81; // r11
  double v82; // fp2
  double v85; // fp13
  double v86; // fp0
  double v87; // fp12
  const bfx::Vec3 *v88; // r15
  const bfx::Vec3 *v89; // r27
  int v90; // r3
  char v91; // r11
  int v92; // r11
  bfx::Area **v93; // r10
  const bfx::Path **v94; // r11
  bool v95; // zf
  double m_z; // fp12
  bool v97; // [sp+50h] [-1B0h] BYREF
  bool v98; // [sp+51h] [-1AFh] BYREF
  __int64 v99; // [sp+58h] [-1A8h]
  bfx::Vec3 v100; // [sp+60h] [-1A0h] BYREF
  bfx::Vec3 v101; // [sp+70h] [-190h] BYREF
  bfx::Vec3 v102; // [sp+80h] [-180h] BYREF
  bfx::Vec3 v103; // [sp+90h] [-170h] BYREF
  float v104; // [sp+A0h] [-160h]
  float v105; // [sp+A4h] [-15Ch]
  float v106; // [sp+A8h] [-158h]
  bfx::Vec3 v107; // [sp+B0h] [-150h] BYREF
  bfx::Vec3 v108; // [sp+C0h] [-140h] BYREF
  char v109; // [sp+CCh] [-134h] BYREF
  bfx::LineSeg v110[6]; // [sp+D0h] [-130h] BYREF

  v32 = &v109;
  p_m_z = (_DWORD *)&inputGoalSeg[-1].m_v1.m_z;
  *a31 = 4;
  for ( i = 6; i != 0; --i )
  {
    ++p_m_z;
    v32 += 4;
    *(_DWORD *)v32 = *p_m_z;
  }
  v38 = maxShrinkDist > 0.0;
  m_pPath = startCC->m_pPath;
  v40 = (float)((float)maxShrinkDist * (float)maxShrinkDist);
  if ( startCC->m_pPath->m_partial )
  {
    v41 = (float *)m_pPath->m_areas.m_data[m_pPath->m_areas.m_size - 1];
    v42 = v41[4];
    v43 = v41[5];
    v103.m_z = v41[6];
    v103.m_x = v42;
    v103.m_y = v43;
    v110[0].m_v0.m_y = v43;
    v110[0].m_v0.m_x = v42;
    v110[0].m_v0.m_z = v103.m_z;
    v110[0].m_v1.m_x = v42;
    v110[0].m_v1.m_y = v43;
    v110[0].m_v1.m_z = v103.m_z;
  }
  if ( m_pPath != goalCC->m_pPath || (v44 = 1, startCC->m_i != goalCC->m_i) )
    v44 = 0;
  if ( v44 != 0 )
  {
    *(bfx::Vec3 *)&nextCornerCC->m_pPath = *bfx::GetClosestPtOnLineSeg(result: &v107, seg: v110, pos: startPos);
    *a29 = goalCC->m_pPath;
    a29[1] = (const bfx::Path *)goalCC->m_i;
    *a31 = ((_cntlzw(startCC->m_pPath->m_partial) & 0x20) == 0) + 2;
    return 1;
  }
  v46 = (__int64)*startCC;
  v102.m_x = 0.0;
  v47 = 0.0;
  v102.m_y = 0.0;
  LODWORD(v50) = v46;
  v102.m_z = 0.0;
  v48 = 0.0;
  v103.m_x = 0.0;
  v49 = 0.0;
  v103.m_y = 0.0;
  HIDWORD(v50) = v46 + 1;
  v51 = (const bfx::Path *)HIDWORD(v46);
  HIDWORD(v46) = v46;
  v52 = v46 + 1;
  v99 = v46;
  v103.m_z = 0.0;
  v53 = v46;
  v54 = 0.0;
  v55 = (int *)(v46 + 4);
  v56 = *(_DWORD *)(v46 + 4);
  m_data = v51->m_areas.m_data;
  v58 = 0.0;
  v59 = 0.0;
  *(_QWORD *)&v100.m_x = 0xFFFFFFFFLL;
  v60 = 1;
  v61 = nullptr;
  v62 = *(bfx::Area **)(4 * v46 + v56);
  v63 = m_data[v52];
  *(_QWORD *)&v101.m_x = 0xFFFFFFFFLL;
  SharedEdgeIdx = bfx::GetSharedEdgeIdx(pArea0: v62, pArea1: v63);
  if ( SharedEdgeIdx == -1 )
    return 0;
  LODWORD(v65) = LODWORD(v100.m_y);
  *(__int64 *)((char *)&v65 + 4) = *(_QWORD *)&v101.m_x;
  while ( 1 )
  {
    v67 = v62->m_flags.m_flags1 & 0x7F;
    v68 = (float *)((char *)v62 + 24 * SharedEdgeIdx);
    v69 = v68[16];
    v70 = (float *)((char *)v62 + 24 * ((SharedEdgeIdx + 1) % v67));
    v71 = v68[17];
    v107.m_x = v68[15];
    __twlgei(v67 & ~(__ROL4__(SharedEdgeIdx + 1, 1) - 1), 0xFFFFFFFF);
    v100.m_x = v107.m_x;
    v72 = v70[15];
    __twllei(v67, 0);
    v73 = v70[16];
    m_x = v100.m_x;
    v75 = v70[17];
    v100.m_y = v69;
    v76 = v69;
    v100.m_z = v71;
    v77 = v71;
    v101.m_x = v72;
    v78 = v72;
    v101.m_y = v73;
    v79 = v73;
    v101.m_z = v75;
    v80 = v75;
    v107.m_y = v69;
    v107.m_z = v71;
    v104 = v72;
    v105 = v73;
    v106 = v75;
    if ( v38 )
    {
      v81 = (float)((float)((float)(v100.m_x - nextCorner->m_x) * (float)(v100.m_x - nextCorner->m_x))
                  + (float)((float)((float)(v71 - nextCorner->m_z) * (float)(v71 - nextCorner->m_z))
                          + (float)((float)(v69 - nextCorner->m_y) * (float)(v69 - nextCorner->m_y)))) > v40;
      v82 = __fsqrts((float)((float)((float)(v104 - v107.m_x) * (float)(v104 - v107.m_x))
                           + (float)((float)((float)(v106 - v107.m_z) * (float)(v106 - v107.m_z))
                                   + (float)((float)(v105 - v107.m_y) * (float)(v105 - v107.m_y)))));
      _FP0 = (float)((float)maxShrinkDist - (float)((float)v82 * (float)0.25));
      __asm { fsel      f13, f0, f1, f17 }
      v86 = (float)((float)(v104 - v107.m_x) * (float)((float)_FP13 / (float)v82));
      v87 = (float)((float)(v106 - v107.m_z) * (float)((float)_FP13 / (float)v82));
      v85 = (float)((float)(v105 - v107.m_y) * (float)((float)_FP13 / (float)v82));
      if ( (float)((float)((float)(v72 - nextCorner->m_x) * (float)(v72 - nextCorner->m_x))
                 + (float)((float)((float)(v75 - nextCorner->m_z) * (float)(v75 - nextCorner->m_z))
                         + (float)((float)(v73 - nextCorner->m_y) * (float)(v73 - nextCorner->m_y)))) > v40 )
      {
        v78 = (float)(v72 - (float)v86);
        v101.m_x = v72 - (float)v86;
        v79 = (float)(v73 - (float)v85);
        v101.m_y = v73 - (float)v85;
        v80 = (float)(v75 - (float)v87);
        v101.m_z = v75 - (float)v87;
      }
      if ( v81 )
      {
        m_x = (float)((float)v86 + v100.m_x);
        v100.m_x = (float)v86 + v100.m_x;
        v76 = (float)((float)v85 + v69);
        v100.m_y = (float)v85 + v69;
        v77 = (float)((float)v87 + v71);
        v100.m_z = (float)v87 + v71;
      }
    }
    if ( v60 != 0 )
    {
      v88 = pathStartPos;
      v102.m_x = v78;
      v89 = startPos;
      v102.m_y = v79;
      v102.m_z = v80;
      v47 = v78;
      v48 = v79;
      LODWORD(v65) = v50;
      v49 = v80;
      v60 = 0;
LABEL_30:
      v103.m_z = v77;
      v59 = v77;
      v103.m_y = v76;
      v58 = v76;
      v103.m_x = m_x;
      v54 = m_x;
      HIDWORD(v65) = v50;
      goto LABEL_31;
    }
    v90 = bfx::GetSharedEdgeIdx(pArea0: v62, pArea1: v61);
    bfx::GetFanitude(pCurArea: v62, entryIndex: v90, exitIndex: SharedEdgeIdx, leftFan: &v97, rightFan: &v98);
    if ( v97 && !v38 )
    {
      v88 = pathStartPos;
      v89 = startPos;
    }
    else
    {
      v88 = pathStartPos;
      v89 = startPos;
      if ( bfx::Area2d(posA: startPos, posB: &v103, posC: &v101, upAxis: (unsigned int)pathStartPos) <= 0.0 )
      {
        v94 = a29;
        goto LABEL_38;
      }
      if ( bfx::Area2d(posA: startPos, posB: &v102, posC: &v101, upAxis: (unsigned int)pathStartPos) <= 0.0 )
      {
        v102.m_x = v78;
        v47 = v78;
        v102.m_y = v79;
        v48 = v79;
        v102.m_z = v80;
        v49 = v80;
        LODWORD(v65) = v50;
      }
    }
    if ( !v98 || v38 )
    {
      if ( bfx::Area2d(posA: v89, posB: &v102, posC: &v100, upAxis: (unsigned int)v88) >= 0.0 )
        goto LABEL_39;
      if ( bfx::Area2d(posA: v89, posB: &v103, posC: &v100, upAxis: (unsigned int)v88) >= 0.0 )
        goto LABEL_30;
    }
LABEL_31:
    if ( v51 != goalCC->m_pPath || (v91 = 1, HIDWORD(v50) != goalCC->m_i) )
      v91 = 0;
    if ( v91 != 0 )
      break;
    ++v53;
    v92 = *v55;
    v93 = v51->m_areas.m_data;
    v61 = v62;
    LODWORD(v99) = v53;
    ++v52;
    v62 = *(bfx::Area **)(4 * v53 + v92);
    SharedEdgeIdx = bfx::GetSharedEdgeIdx(pArea0: v62, pArea1: v93[v52]);
    if ( SharedEdgeIdx == -1 )
      return 0;
    v50 = v99;
  }
  bfx::GetClosestPtOnLineSeg(result: &v108, seg: v110, pos: v89);
  if ( bfx::Area2d(posA: v89, posB: &v102, posC: &v108, upAxis: (unsigned int)v88) >= 0.0 )
  {
LABEL_39:
    *(float *)&nextCornerCC->m_pPath = v47;
    *(float *)&nextCornerCC->m_i = v48;
    *(float *)&nextCornerCC[1].m_pPath = v49;
    *(_QWORD *)a29 = v65;
    *a31 = 0;
    return 1;
  }
  v95 = bfx::Area2d(posA: v89, posB: &v103, posC: &v108, upAxis: (unsigned int)v88) <= 0.0;
  v94 = a29;
  if ( v95 )
  {
LABEL_38:
    *(float *)&nextCornerCC->m_pPath = v54;
    *(float *)&nextCornerCC->m_i = v58;
    *(float *)&nextCornerCC[1].m_pPath = v59;
    *(_QWORD *)v94 = *(__int64 *)((char *)&v65 + 4);
    *a31 = 1;
    return 1;
  }
  m_z = v108.m_z;
  *(float *)&nextCornerCC->m_pPath = v108.m_x;
  *(float *)&nextCornerCC[1].m_pPath = m_z;
  *(float *)&nextCornerCC->m_i = v108.m_y;
  *a29 = goalCC->m_pPath;
  a29[1] = (const bfx::Path *)goalCC->m_i;
  *a31 = ((_cntlzw(*(unsigned __int8 *)(*(_DWORD *)v66 + 20)) & 0x20) == 0) + 2;
  return 1;
}


// ========================================================================
// ?GetBestLinkBetweenNonSurfaceConnectedAreas@bfx@@YAPAVHalfLink@1@PAVArea@1@0ABVVec3@1@ABVPathSpec@1@@Z
// EA  : 0x83292ED0
// RVA : 0x01292ED0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.cpp
// ========================================================================

bfx::HalfLink *__fastcall bfx::GetBestLinkBetweenNonSurfaceConnectedAreas(
        bfx::Area *pArea0,
        bfx::Area *pArea1,
        const bfx::Vec3 *pos,
        const bfx::PathSpec *pathSpec)
{
  bfx::HalfLink *m_pFirstLink; // r29
  double v9; // fp31
  bfx::HalfLink *i; // r24
  char v11; // r11
  bfx::HalfLink *m_pTwin; // r11
  bfx::Area *v13; // r11
  bfx::LinkBase *m_pLinkBase; // r28
  unsigned int m_flags2; // r31
  unsigned int v16; // r30
  double v17; // fp30
  __int64 v18; // r9
  double v19; // fp12
  bfx::Vec3 v21; // [sp+58h] [-88h] BYREF
  float v22; // [sp+68h] [-78h] BYREF
  float v23; // [sp+6Ch] [-74h]
  float v24; // [sp+70h] [-70h]

  m_pFirstLink = pArea0->m_pFirstLink;
  v9 = 3.4028235e38;
  for ( i = nullptr; m_pFirstLink != nullptr; m_pFirstLink = m_pFirstLink->m_pNext )
  {
    if ( (*((_BYTE *)m_pFirstLink + 44) & 0x80) == 0
      || (*((_BYTE *)m_pFirstLink + 44) & 0x40) != 0
      || (v11 = 1, (*((_BYTE *)m_pFirstLink + 44) & 0x20) != 0) )
    {
      v11 = 0;
    }
    if ( v11 != 0 )
    {
      m_pTwin = m_pFirstLink->m_pTwin;
      v13 = m_pTwin != nullptr ? m_pTwin->m_pArea : nullptr;
      if ( v13 == pArea1 )
      {
        m_pLinkBase = m_pFirstLink->m_pLinkBase;
        if ( (m_pLinkBase->m_linkDat.m_linkUsageFlags & pathSpec->m_linkUsageFlags) != 0 )
        {
          bfx::GetClosestPtOnLineSeg(result: &v21, seg: &m_pFirstLink->m_startSeg, pos);
          m_flags2 = pArea0->m_flags.m_flags2;
          v16 = (m_flags2 >> 20) & 0xF;
          v17 = __fsqrts((float)((float)((float)(v21.m_x - pos->m_x) * (float)(v21.m_x - pos->m_x))
                               + (float)((float)((float)(v21.m_z - pos->m_z) * (float)(v21.m_z - pos->m_z))
                                       + (float)((float)(v21.m_y - pos->m_y) * (float)(v21.m_y - pos->m_y)))));
          if ( bfx::IsObstacleAffected(pArea: pArea0, pathSpec) && v16 <= (HIWORD(m_flags2) & 0xF) )
            v16 = HIWORD(m_flags2) & 0xF;
          m_pLinkBase->GetOutputPos(this: (bfx::LinkBase *)&v22, result: (bfx::Vec3 *)m_pLinkBase, a3: &v21);
          LODWORD(v18) = v16;
          v19 = __fsqrts((float)((float)((float)(v22 - v21.m_x) * (float)(v22 - v21.m_x))
                               + (float)((float)((float)(v24 - v21.m_z) * (float)(v24 - v21.m_z))
                                       + (float)((float)(v23 - v21.m_y) * (float)(v23 - v21.m_y)))));
          if ( (float)((float)((float)v18 * (float)v17) + (float)((float)v19 + m_pLinkBase->m_linkDat.m_penaltyMult)) < v9 )
          {
            v9 = (float)((float)((float)v18 * (float)v17) + (float)((float)v19 + m_pLinkBase->m_linkDat.m_penaltyMult));
            i = m_pFirstLink;
          }
        }
      }
    }
  }
  return i;
}


// ========================================================================
// ?GetMaxAreaPenalty@bfx@@YAIPAVArea@1@ABVPathSpec@1@@Z
// EA  : 0x83293098
// RVA : 0x01293098
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.cpp
// ========================================================================

unsigned int __fastcall bfx::GetMaxAreaPenalty(bfx::Area *pArea, const bfx::PathSpec *pathSpec)
{
  unsigned int m_flags2; // r8
  unsigned int result; // r3
  unsigned int m_obstacleBlockageFlags; // r11
  bool v6; // r11
  unsigned int m_usageFlags; // r11
  unsigned int v8; // r9
  char v9; // r11

  m_flags2 = pArea->m_flags.m_flags2;
  m_obstacleBlockageFlags = pathSpec->m_obstacleBlockageFlags;
  result = 1;
  if ( pathSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH )
    v6 = (_cntlzw(m_obstacleBlockageFlags - (m_flags2 & (unsigned __int16)m_obstacleBlockageFlags)) & 0x20) != 0;
  else
    v6 = (m_flags2 & (unsigned __int16)m_obstacleBlockageFlags) != 0;
  if ( v6 )
  {
    if ( (pArea->m_flags.m_flags1 & 0x20000000) != 0 )
      return -1;
    result = HIWORD(m_flags2) & 0xF;
  }
  m_usageFlags = pArea->m_usageFlags;
  if ( m_usageFlags == 0 || (v8 = pathSpec->m_areaUsageFlags & m_usageFlags, v9 = 1, v8 != 0) )
    v9 = 0;
  if ( v9 != 0 )
    return -1;
  if ( result <= ((m_flags2 >> 20) & 0xF) )
    return (m_flags2 >> 20) & 0xF;
  return result;
}


// ========================================================================
// ?AdvanceCursors@bfx@@YAHW4CornerType@1@ABVPathCC@1@MAAV31@@Z
// EA  : 0x83293148
// RVA : 0x01293148
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.cpp
// ========================================================================

int __fastcall bfx::AdvanceCursors(
        bfx::CornerType cornerType,
        const bfx::PathCC *endCC,
        double maxShrinkDist,
        bfx::PathCC *curCC,
        bfx::PathCC *a5)
{
  int m_i; // r11
  int v10; // r30
  int v11; // r27
  bfx::Area *v12; // r28
  int v13; // r11
  bfx::Area *v14; // r29
  bfx::Area *Area; // r30
  int SharedEdgeIdx; // r28
  int v17; // r3
  int v18; // r30
  char v19; // r3
  bool v20; // [sp+50h] [-50h] BYREF
  bool v21; // [sp+51h] [-4Fh] BYREF

  m_i = a5->m_i;
  if ( maxShrinkDist <= 0.0 )
  {
    v10 = m_i + 1;
    v11 = 1;
    v12 = a5->m_pPath->m_areas.m_data[m_i];
    a5->m_i = m_i + 1;
    if ( (unsigned __int8)bfx::PathCC::operator!=(this: a5, rhs: endCC) != 0 )
    {
      v13 = v10;
      do
      {
        v14 = a5->m_pPath->m_areas.m_data[v13];
        Area = bfx::PathCC::NextArea(this: a5);
        SharedEdgeIdx = bfx::GetSharedEdgeIdx(pArea0: v14, pArea1: v12);
        v17 = bfx::GetSharedEdgeIdx(pArea0: v14, pArea1: Area);
        bfx::GetFanitude(pCurArea: v14, entryIndex: SharedEdgeIdx, exitIndex: v17, leftFan: &v20, rightFan: &v21);
        if ( (!v20 || cornerType != LEFT_CORNER) && (!v21 || cornerType != RIGHT_CORNER) )
          break;
        v18 = a5->m_i + 1;
        ++v11;
        a5->m_i = v18;
        v12 = v14;
        v19 = bfx::PathCC::operator!=(this: a5, rhs: endCC);
        v13 = v18;
      }
      while ( v19 != 0 );
    }
    return v11;
  }
  else
  {
    a5->m_i = m_i + 1;
    return 1;
  }
}


// ========================================================================
// ?GetNextNCorners@bfx@@YAHABVPathCC@1@0ABVVec3@1@ABVLineSeg@1@MHPAVSurfaceCornerData@1@@Z
// EA  : 0x83293270
// RVA : 0x01293270
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.cpp
// ========================================================================

int __fastcall bfx::GetNextNCorners(
        const bfx::PathCC *initialCC,
        const bfx::PathCC *goalCC,
        bfx::Vec3 *initialPos,
        const bfx::LineSeg *goalSeg,
        double maxShrinkDist,
        int maxNumCorners,
        bfx::SurfaceCornerData *pCornersOutArray,
        int a8)
{
  bfx::PathCC v9; // r11
  bool v10; // cr57
  float m_y; // r8
  __int64 v12; // r24
  float m_z; // r7
  int v18; // r27
  bfx::SurfaceCornerData *v19; // r28
  int v20; // r31
  bfx::PathCC *v21; // r5
  bfx::CornerType v22; // r3
  double v23; // fp0
  int v24; // r11
  double v25; // fp13
  bfx::PathCC v26; // r10
  double v27; // fp12
  const bfx::Path *m_pPath; // r8
  char v29; // r11
  bool v30; // zf
  bfx::CornerType *v32; // [sp+8h] [-E8h]
  int v33; // [sp+Ch] [-E4h]
  int v34; // [sp+10h] [-E0h]
  int v35; // [sp+14h] [-DCh]
  int v36; // [sp+18h] [-D8h]
  int v37; // [sp+1Ch] [-D4h]
  int v38; // [sp+20h] [-D0h]
  int v39; // [sp+24h] [-CCh]
  int v40; // [sp+28h] [-C8h]
  int v41; // [sp+2Ch] [-C4h]
  int v42; // [sp+30h] [-C0h]
  int v43; // [sp+34h] [-BCh]
  int v44; // [sp+38h] [-B8h]
  int v45; // [sp+3Ch] [-B4h]
  int v46; // [sp+40h] [-B0h]
  int v47; // [sp+44h] [-ACh]
  int v48; // [sp+48h] [-A8h]
  int v49; // [sp+4Ch] [-A4h]
  int v50; // [sp+50h] [-A0h]
  int v51; // [sp+58h] [-98h]
  bfx::CornerType v52[2]; // [sp+60h] [-90h] BYREF
  __int64 v53; // [sp+68h] [-88h] BYREF
  bfx::PathCC v54; // [sp+70h] [-80h] BYREF
  bfx::Vec3 v55; // [sp+78h] [-78h] BYREF
  bfx::PathCC v56; // [sp+88h] [-68h] BYREF
  float v57; // [sp+90h] [-60h]

  v9 = *initialCC;
  v10 = (int)pCornersOutArray > 0;
  m_y = initialPos->m_y;
  HIDWORD(v12) = 0;
  m_z = initialPos->m_z;
  v18 = 0;
  v55.m_x = initialPos->m_x;
  v9.m_pPath = (const bfx::Path *)LODWORD(v55.m_x);
  v54 = v9;
  v19 = nullptr;
  v55.m_y = m_y;
  v55.m_z = m_z;
  if ( v10 )
  {
    v20 = a8 - 4;
    LODWORD(v12) = -1;
    do
    {
      v53 = v12;
      if ( (unsigned __int8)bfx::GetNextCorner(
                              startCC: &v54,
                              goalCC,
                              startPos: &v55,
                              inputGoalSeg: goalSeg,
                              maxShrinkDist,
                              upAxis: SLODWORD(m_z),
                              pathStartPos: (const bfx::Vec3 *)2,
                              nextCorner: initialPos,
                              nextCornerCC: &v56,
                              cornerType: v32,
                              a11: v33,
                              a12: v34,
                              a13: v35,
                              a14: v36,
                              a15: v37,
                              a16: v38,
                              a17: v39,
                              a18: v40,
                              a19: v41,
                              a20: v42,
                              a21: v43,
                              a22: v44,
                              a23: v45,
                              a24: v46,
                              a25: v47,
                              a26: v48,
                              a27: v49,
                              a28: v50,
                              a29: (const bfx::Path **)&v53,
                              a30: v51,
                              a31: v52) == 0 )
        break;
      v22 = v52[0];
      v23 = *(float *)&v56.m_pPath;
      v24 = v53;
      v25 = *(float *)&v56.m_i;
      v26.m_i = v53;
      v27 = v57;
      *(float *)(v20 + 4) = *(float *)&v56.m_pPath;
      v26.m_pPath = (const bfx::Path *)HIDWORD(v53);
      *(float *)(v20 + 8) = v25;
      ++v18;
      *(float *)(v20 + 12) = v27;
      *(_DWORD *)(v20 + 16) = v22;
      v20 += 20;
      *(_DWORD *)v20 = v24;
      v55.m_x = v23;
      m_pPath = goalCC->m_pPath;
      v55.m_y = v25;
      v55.m_z = v27;
      v54 = v26;
      if ( v26.m_pPath == m_pPath )
      {
        v30 = v24 == goalCC->m_i;
        v29 = 1;
        if ( v30 )
          goto LABEL_7;
      }
      v29 = 0;
LABEL_7:
      if ( v29 != 0 )
        break;
      if ( v19 == (bfx::SurfaceCornerData *)((char *)&pCornersOutArray[-1].m_indexOfCornerArea + 3) )
        break;
      bfx::AdvanceCursors(cornerType: v22, endCC: goalCC, maxShrinkDist, curCC: v21, a5: &v54);
      v19 = (bfx::SurfaceCornerData *)((char *)v19 + 1);
    }
    while ( (int)v19 < (int)pCornersOutArray );
  }
  return v18;
}


// ========================================================================
// ?DrawPath@bfx@@YAXPBVSpace@1@PBVPath@1@ABVColor@1@@Z
// EA  : 0x832933C0
// RVA : 0x012933C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.cpp
// ========================================================================

void __fastcall bfx::DrawPath(bfx::Space *pSpace, const bfx::Path *pPath, const bfx::Color *color)
{
  int v6; // r30
  int v7; // r31

  if ( pPath != nullptr )
  {
    v6 = 0;
    if ( pPath->m_areas.m_size > 0 )
    {
      v7 = 0;
      do
      {
        bfx::Area::Draw(this: pPath->m_areas.m_data[v7], pSpace, color);
        ++v6;
        ++v7;
      }
      while ( v6 < pPath->m_areas.m_size );
    }
  }
}


// ========================================================================
// ??0Path@bfx@@QAA@ABV?$Array@PAVArea@bfx@@@1@@Z
// EA  : 0x83293430
// RVA : 0x01293430
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.cpp
// ========================================================================

bfx::Path *__fastcall bfx::Path::Path(bfx::Path *this, const bfx::Array<bfx::Area *> *areas)
{
  bfx::bfxMemTag v3; // r10

  this->__vftable = (bfx::Path_vtbl *)&bfx::Path::`vftable';
  v3 = bfx::MEM_BFXPLANNER;
  this->m_areas.m_data = nullptr;
  this->m_areas.m_size = 0;
  this->m_areas.m_cap = 0;
  this->m_areas.m_tag = v3;
  this->m_partial = false;
  bfx::Array<bfx::Area *>::operator=(this: &this->m_areas, rhs: areas);
  return this;
}


// ========================================================================
// __unwind$19719
// EA  : 0x832934A4
// RVA : 0x012934A4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.cpp
// ========================================================================

void _unwind_19719()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                             + 4));
}

