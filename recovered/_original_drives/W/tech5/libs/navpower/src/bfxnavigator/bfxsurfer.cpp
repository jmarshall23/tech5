
// ========================================================================
// ?GetAreaNormal@Surfer@bfx@@QBA_NAAVVec3@2@@Z
// EA  : 0x832BF388
// RVA : 0x012BF388
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxsurfer.cpp
// ========================================================================

int __fastcall bfx::Surfer::GetAreaNormal(bfx::Surfer *this, bfx::Vec3 *normalOut)
{
  bfx::AreaProxy *m_pProxy; // r10
  char v3; // r10
  bool v4; // zf

  m_pProxy = this->m_area.m_pProxy;
  if ( m_pProxy == nullptr || (v4 = m_pProxy->m_pArea != nullptr, v3 = 1, !v4) )
    v3 = 0;
  if ( v3 == 0 )
    return 0;
  *normalOut = this->m_areaNormal;
  return 1;
}


// ========================================================================
// ?CalcEdgeNormal@Surfer@bfx@@QAA?AVVec3@2@XZ
// EA  : 0x832BF3E0
// RVA : 0x012BF3E0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxsurfer.cpp
// ========================================================================

bfx::Surfer *__fastcall bfx::Surfer::CalcEdgeNormal(bfx::Surfer *this, bfx::Vec3 *result)
{
  float v4; // r11
  double v5; // fp2
  double v6; // fp1
  double v7; // fp0
  double v10; // fp1
  bfx::Area *m_pArea; // r7
  float m_y; // r8
  float m_z; // r7
  bfx::EdgeCursor v15; // [sp+50h] [-30h] BYREF
  float v16; // [sp+58h] [-28h]

  if ( LODWORD(result[3].m_y) == 1 && (v4 = result[1].m_y) != 0.0 && *(_DWORD *)LODWORD(v4) != 0 )
  {
    bfx::EdgeCursor::GetEdgeVec(this: &v15, result: (bfx::Vec3 *)((char *)result + 32));
    v5 = (float)((float)(result[1].m_z * v16) - (float)(result[2].m_y * *(float *)&v15.m_pArea));
    v6 = (float)((float)(result[2].m_x * *(float *)&v15.m_pArea) - (float)(result[1].m_z * *(float *)&v15.m_i));
    v7 = (float)((float)(result[2].m_y * *(float *)&v15.m_i) - (float)(result[2].m_x * v16));
    _FP6 = (float)((float)__fsqrts((float)((float)((float)v7 * (float)v7)
                                         + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))))
                 - (float)1.0842022e-19);
    __asm { fsel      f4, f6, f5, f9 }
    v10 = (float)((float)_FP4 * (float)((float)(result[2].m_y * *(float *)&v15.m_i) - (float)(result[2].m_x * v16)));
    v16 = (float)((float)(result[2].m_x * *(float *)&v15.m_pArea) - (float)(result[1].m_z * *(float *)&v15.m_i))
        * (float)_FP4;
    *(float *)&v15.m_pArea = v10;
    *(float *)&v15.m_i = (float)v5 * (float)_FP4;
    m_pArea = v15.m_pArea;
    this->m_pos.m_y = v16;
    this->m_pos.m_x = (float)v5 * (float)_FP4;
    this->__vftable = (bfx::Surfer_vtbl *)m_pArea;
  }
  else
  {
    m_y = bfx::ZERO_VEC.m_y;
    m_z = bfx::ZERO_VEC.m_z;
    this->__vftable = (bfx::Surfer_vtbl *)LODWORD(bfx::ZERO_VEC.m_x);
    this->m_pos.m_x = m_y;
    this->m_pos.m_y = m_z;
  }
  return this;
}


// ========================================================================
// ?UpdateArea@Surfer@bfx@@AAAXPAVArea@2@ABVVec3@2@@Z
// EA  : 0x832BF508
// RVA : 0x012BF508
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxsurfer.cpp
// ========================================================================

void __fastcall bfx::Surfer::UpdateArea(bfx::Surfer *this, bfx::Area *pNewArea, const bfx::Vec3 *edgeVec)
{
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Handle<bfx::Area> *p_m_area; // r25
  bfx::Area *m_pArea; // r27
  float m_y; // r10
  float m_z; // r9
  bfx::Vec3 *p_m_pos; // r30
  const bfx::Handle<bfx::Area> *v12; // r3
  float *v13; // r3
  bfx::Area *v14; // r11
  int v15; // r7
  signed int v16; // r25
  int v17; // r24
  float v18; // r10
  float v19; // r8
  float v20; // r9
  bfx::AreaProxy **v21; // r11
  bfx::AreaProxy *v22; // r8
  char *v23; // r7
  bfx::HalfLink *v24; // r11
  bfx::Vec3 *ClosestPtOnLineSeg; // r3
  double m_x; // fp0
  double v27; // fp13
  double v28; // fp12
  double v29; // fp10
  double v30; // fp8
  double v31; // fp6
  double v32; // fp5
  double v33; // fp3
  bfx::Handle<bfx::Area> v34[2]; // [sp+50h] [-A0h] BYREF
  bfx::EdgeCursor v35; // [sp+58h] [-98h] BYREF
  bfx::Vec3 v36; // [sp+60h] [-90h] BYREF
  bfx::Area v37[2]; // [sp+70h] [-80h] BYREF

  m_pProxy = this->m_area.m_pProxy;
  p_m_area = &this->m_area;
  if ( m_pProxy != nullptr )
  {
    m_pArea = m_pProxy->m_pArea;
    v34[0] = this->m_area;
  }
  else
  {
    m_pArea = nullptr;
  }
  m_y = this->m_pos.m_y;
  m_z = this->m_pos.m_z;
  p_m_pos = &this->m_pos;
  v37[0].m_pos.m_x = this->m_pos.m_x;
  v37[0].m_pos.m_y = m_y;
  v37[0].m_pos.m_z = m_z;
  v12 = bfx::Handle<bfx::Area>::Handle<bfx::Area>(this: v34, pArea: pNewArea);
  bfx::Handle<bfx::Area>::operator=(this: p_m_area, rhs: v12);
  bfx::Handle<bfx::Area>::Release(this: v34);
  if ( pNewArea != nullptr )
  {
    v13 = (float *)bfx::Area::CalcNormal(this: v37, result: (bfx::Vec3 *)pNewArea);
    this->m_areaNormal.m_x = *v13;
    this->m_areaNormal.m_y = v13[1];
    this->m_areaNormal.m_z = v13[2];
  }
  bfx::EdgeCursor::GetSibling(this: &v35, result: &this->m_edgeCursor);
  v14 = v35.m_pArea;
  v15 = v35.m_i + 1;
  v16 = v35.m_pArea->m_flags.m_flags1 & 0x7F;
  v17 = (v35.m_i + 1) / v16 * v16;
  v19 = *((float *)&v35.m_pArea[1].m_pFirstLink + 6 * v35.m_i);
  v18 = *((float *)&v35.m_pArea[1].m_dynAreaData.m_data + 6 * v35.m_i);
  v20 = *((float *)&v35.m_pArea[1].m_pSearchParent + 6 * v35.m_i);
  __twllei(v16, 0);
  v36.m_x = v18;
  v36.m_y = v19;
  v36.m_z = v20;
  v21 = &(&v14->m_pProxy)[6 * (v15 - v17)];
  __twlgei(v16 & ~(__ROL4__(v15, 1) - 1), 0xFFFFFFFF);
  v22 = v21[15];
  v23 = (char *)v21[16];
  v24 = (bfx::HalfLink *)v21[17];
  v37[0].m_pProxy = v22;
  v37[0].m_dynAreaData.m_data = v23;
  v37[0].m_pFirstLink = v24;
  ClosestPtOnLineSeg = bfx::GetClosestPtOnLineSeg(
                         result: (bfx::Vec3 *)&v37[0].m_searchCost,
                         start: &v36,
                         end: (const bfx::Vec3 *)v37,
                         pos: &this->m_pos);
  m_x = ClosestPtOnLineSeg->m_x;
  p_m_pos->m_x = ClosestPtOnLineSeg->m_x;
  v27 = ClosestPtOnLineSeg->m_y;
  this->m_pos.m_y = ClosestPtOnLineSeg->m_y;
  v28 = ClosestPtOnLineSeg->m_z;
  v34[1].m_pProxy = (bfx::AreaProxy *)&this->m_areaNormal;
  this->m_pos.m_z = v28;
  v29 = this->m_areaNormal.m_z;
  v36.m_z = pNewArea->m_pos.m_z;
  v30 = this->m_areaNormal.m_y;
  v31 = this->m_areaNormal.m_x;
  v36.m_y = pNewArea->m_pos.m_y;
  v36.m_x = pNewArea->m_pos.m_x;
  v32 = (float)((float)((float)v31 * (float)((float)m_x - v36.m_x))
              + (float)((float)((float)v30 * (float)((float)v27 - v36.m_y))
                      + (float)((float)v29 * (float)((float)v28 - v36.m_z))));
  v33 = (float)((float)v30
              * (float)((float)((float)v31 * (float)((float)m_x - v36.m_x))
                      + (float)((float)((float)v30 * (float)((float)v27 - v36.m_y))
                              + (float)((float)v29 * (float)((float)v28 - v36.m_z)))));
  p_m_pos->m_x = (float)m_x
               - (float)((float)v31
                       * (float)((float)((float)v31 * (float)((float)m_x - v36.m_x))
                               + (float)((float)((float)v30 * (float)((float)v27 - v36.m_y))
                                       + (float)((float)v29 * (float)((float)v28 - v36.m_z)))));
  this->m_pos.m_y = (float)v27 - (float)v33;
  this->m_pos.m_z = (float)v28 - (float)((float)v29 * (float)v32);
  this->MovedOntoArea(this, a2: &v37[0].m_pos, a3: m_pArea, a4: &this->m_pos, a5: pNewArea, a6: edgeVec);
}


// ========================================================================
// __unwind$19894
// EA  : 0x832BF724
// RVA : 0x012BF724
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxsurfer.cpp
// ========================================================================

void _unwind_19894()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(v0 - 240 + 80));
}


// ========================================================================
// ?MoveOnce@Surfer@bfx@@QAAMAAVVec3@2@MAAV?$Array@PAVArea@bfx@@@2@AAV?$Array@PAVEdge@bfx@@@2@@Z
// EA  : 0x832BF750
// RVA : 0x012BF750
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxsurfer.cpp
// ========================================================================

float __fastcall bfx::Surfer::MoveOnce(
        bfx::Surfer *this,
        bfx::Vec3 *vel,
        double time,
        bfx::Array<bfx::Area *> *areasTraversed,
        bfx::Array<bfx::Space *> *edgesTraversed,
        bfx::Array<bfx::Space *> *a6)
{
  bfx::AreaProxy *m_pProxy; // r11
  double v7; // fp13
  double m_x; // fp12
  double m_z; // fp11
  double v10; // fp10
  double v11; // fp9
  double v12; // fp8
  double v18; // fp30
  double v19; // fp29
  bfx::Area *m_pArea; // r5
  bfx::EdgeCursor *v21; // r29
  bfx::Vec3 *v22; // r31
  double v23; // fp9
  double v24; // fp10
  double v25; // fp13
  double v26; // fp12
  double v27; // fp8
  bfx::Area *v28; // r10
  int v29; // r11
  int m_size; // r28
  bfx::Space **v31; // r9
  bfx::EdgeCursor *v32; // r21
  bfx::Area **v33; // r8
  signed int v34; // r3
  bfx::Area *v35; // r31
  bfx::Area **v36; // r8
  int v37; // r20
  double v38; // fp4
  double v39; // fp2
  double v40; // fp1
  char *v41; // r11
  bfx::Space **v42; // r7
  double v43; // fp31
  double v44; // fp8
  double v47; // fp12
  double v48; // fp13
  double v49; // fp0
  char v50; // r28
  bfx::Edge **v51; // r11
  bfx::Edge **v52; // r10
  char v53; // r11
  bfx::Area *v54; // r3
  bfx::Edge **v55; // r11
  bfx::Edge **v56; // r10
  double v57; // fp1
  double v58; // fp6
  bfx::Area *v59; // r10
  bfx::Space **v60; // r11
  int v61; // r9
  bool v62; // zf
  double v63; // fp7
  double v64; // fp6
  int m_i; // r9
  double v66; // fp7
  bfx::Area *v67; // r11
  double m_y; // fp5
  double v69; // fp6
  bfx::EdgeCursor *p_m_edgeCursor; // r31
  float *v71; // r8
  signed int v72; // r3
  float v73; // r4
  float v74; // r10
  float v75; // r8
  double v76; // fp23
  double v77; // fp21
  double v78; // fp25
  float *v79; // r10
  float v80; // r8
  float v81; // r7
  double v82; // fp24
  double v83; // fp22
  double v84; // fp26
  double v87; // fp11
  double v88; // fp6
  double v89; // fp5
  bfx::Area *v92; // r29
  bfx::Edge **m_data; // r11
  bfx::Edge **v94; // r10
  char v95; // r11
  bfx::Area *v96; // r3
  bfx::Edge **v97; // r11
  bfx::Edge **v98; // r10
  double v99; // fp29
  double v100; // fp30
  double v101; // fp28
  double v102; // fp3
  double v103; // fp27
  double v104; // fp2
  bfx::Vec3 *p_m_pos; // r11
  double v106; // fp25
  double v107; // fp11
  double v108; // fp9
  bfx::Area *v109; // r10
  int v110; // r11
  bfx::Area *v111; // r29
  bfx::Edge **v112; // r11
  bfx::Edge **v113; // r10
  char v114; // r11
  bool v115; // r3
  unsigned __int8 v116; // r11
  int v117; // r28
  int v118; // r11
  bfx::Surfer_vtbl *v119; // r11
  bfx::Area *v120; // r10
  bfx::Space **v121; // r11
  int v122; // r9
  bfx::Area *v123; // r10
  int v124; // r11
  signed int v125; // r6
  bfx::EdgeCursor *v126; // r7
  unsigned int v127; // r9
  float v128; // r8
  float *v129; // r11
  bfx::EdgeCursor v130; // r6
  double v131; // fp13
  float v132; // r8
  float v133; // r10
  float v134; // r9
  bfx::Area *v137; // r3
  bfx::Edge **v138; // r11
  bfx::Edge **v139; // r10
  bfx::Space *v140; // r10
  bfx::Space **v141; // r11
  int v142; // r9
  double v143; // fp26
  int v144; // r11
  bfx::Vec3 *v145; // r29
  bfx::Edge **v146; // r11
  bfx::Edge **v147; // r10
  char v148; // r11
  bool v149; // r3
  unsigned __int8 v150; // r11
  int v151; // r28
  double v152; // fp0
  double v153; // fp13
  double v154; // fp12
  bfx::Area *v155; // r10
  int v156; // r11
  bfx::Space *v157; // r10
  bfx::Space **v158; // r11
  int v159; // r9
  bfx::Area *v160; // r10
  int v161; // r11
  signed int v162; // r6
  float *v163; // r7
  unsigned int v164; // r9
  int v165; // r11
  char *v166; // r8
  float v167; // r6
  float *v168; // r11
  float v169; // r5
  float v170; // r8
  float v171; // r9
  bfx::Area *v174; // r3
  bfx::Edge **v175; // r11
  bfx::Edge **v176; // r10
  bfx::Space *v177; // r10
  bfx::Space **v178; // r11
  int v179; // r9
  bfx::Space *v181[2]; // [sp+50h] [-1D0h] BYREF
  bfx::Vec3 v182; // [sp+58h] [-1C8h] BYREF
  bfx::EdgeCursor v183; // [sp+68h] [-1B8h] BYREF
  float v184; // [sp+70h] [-1B0h]
  bfx::Vec3 v185; // [sp+78h] [-1A8h] BYREF
  bfx::EdgeCursor v186; // [sp+88h] [-198h] BYREF
  bfx::Vec3 v187; // [sp+90h] [-190h] BYREF
  bfx::Area v188; // [sp+A0h] [-180h] BYREF
  float v189; // [sp+D8h] [-148h]
  bfx::Vec3 v190; // [sp+E0h] [-140h] BYREF
  float v191; // [sp+F0h] [-130h] BYREF
  float v192; // [sp+F4h] [-12Ch]
  float v193; // [sp+F8h] [-128h]
  float v194[4]; // [sp+100h] [-120h] BYREF
  bfx::Vec3 v195; // [sp+110h] [-110h] BYREF
  float v196[4]; // [sp+120h] [-100h] BYREF
  bfx::Area v197[2]; // [sp+130h] [-F0h] BYREF

  m_pProxy = this->m_area.m_pProxy;
  v7 = (float)(vel->m_y * vel->m_y);
  m_x = vel->m_x;
  m_z = vel->m_z;
  v10 = (float)(vel->m_x * (float)time);
  v11 = (float)(vel->m_y * (float)time);
  v12 = (float)(vel->m_z * (float)time);
  v188.m_pos.m_x = vel->m_x * (float)time;
  v188.m_pos.m_y = v11;
  v188.m_pos.m_z = v12;
  v18 = __fsqrts((float)((float)((float)m_z * (float)m_z) + (float)((float)((float)m_x * (float)m_x) + (float)v7)));
  v19 = (float)((float)v18 * (float)time);
  if ( m_pProxy != nullptr )
    m_pArea = m_pProxy->m_pArea;
  else
    m_pArea = nullptr;
  if ( this->m_state != ON_AREA )
  {
    m_i = this->m_edgeCursor.m_i;
    v66 = this->m_areaNormal.m_z;
    v67 = this->m_edgeCursor.m_pArea;
    m_y = this->m_areaNormal.m_y;
    v69 = this->m_areaNormal.m_x;
    p_m_edgeCursor = &this->m_edgeCursor;
    v71 = (float *)((char *)v67 + 24 * m_i);
    v72 = v67->m_flags.m_flags1 & 0x7F;
    __twllei(v72, 0);
    v73 = v71[17];
    v74 = v71[15];
    v75 = v71[16];
    v185.m_z = v73;
    v76 = v73;
    v185.m_x = v74;
    v77 = v74;
    v185.m_y = v75;
    v78 = v75;
    v79 = (float *)((char *)v67 + 24 * ((m_i + 1) % v72));
    __twlgei(v72 & ~(__ROL4__(m_i + 1, 1) - 1), 0xFFFFFFFF);
    v80 = v79[15];
    v81 = v79[16];
    v185.m_z = v79[17];
    v82 = v185.m_z;
    v185.m_x = v80;
    v83 = v80;
    v185.m_y = v81;
    v84 = v81;
    _FP12 = (float)((float)__fsqrts((float)((float)((float)(v80 - (float)v77) * (float)(v80 - (float)v77))
                                          + (float)((float)((float)(v185.m_z - v73) * (float)(v185.m_z - v73))
                                                  + (float)((float)(v81 - (float)v78) * (float)(v81 - (float)v78)))))
                  - (float)1.0842022e-19);
    __asm { fsel      f1, f12, f11, f31 }
    v182.m_x = (float)(v80 - (float)v77) * (float)_FP1;
    v182.m_y = (float)(v81 - (float)v78) * (float)_FP1;
    v182.m_z = (float)(v185.m_z - v73) * (float)_FP1;
    v87 = (float)((float)(v182.m_z * (float)v69) - (float)(v182.m_x * (float)v66));
    v88 = (float)((float)(v182.m_x * (float)m_y) - (float)(v182.m_y * (float)v69));
    v89 = (float)((float)(v182.m_y * (float)v66) - (float)(v182.m_z * (float)m_y));
    _FP12 = (float)((float)__fsqrts((float)((float)((float)v89 * (float)v89)
                                          + (float)((float)((float)v88 * (float)v88) + (float)((float)v87 * (float)v87))))
                  - (float)1.0842022e-19);
    __asm { fsel      f3, f12, f7, f31 }
    v192 = (float)v87 * (float)_FP3;
    v191 = (float)_FP3 * (float)v89;
    v193 = (float)v88 * (float)_FP3;
    if ( (float)((float)(v193 * (float)v12) + (float)((float)(v191 * (float)v10) + (float)(v192 * (float)v11))) < (double)(float)((float)v18 * (float)-0.000099999997) )
    {
LABEL_48:
      this->m_state = ON_AREA;
      goto LABEL_49;
    }
    v92 = (bfx::Area *)(&v67[1].m_pProxy)[6 * m_i];
    v186.m_pArea = v92;
    if ( v92 != nullptr )
    {
      m_data = (bfx::Edge **)edgesTraversed->m_data;
      v94 = (bfx::Edge **)&edgesTraversed->m_data[edgesTraversed->m_size];
      if ( (bfx::Edge **)edgesTraversed->m_data == v94 )
      {
LABEL_41:
        v95 = 0;
      }
      else
      {
        while ( *m_data != (bfx::Edge *)v92 )
        {
          if ( ++m_data == v94 )
            goto LABEL_41;
        }
        v95 = 1;
      }
      if ( v95 == 0 && this->OkToMoveOntoArea(this, a2: v92) )
      {
        v96 = bfx::Area::CalcNormal(this: &v188, result: (bfx::Vec3 *)v92);
        *vel = *bfx::RotateVecIntoNewArea(
                  result: &v187,
                  vec: vel,
                  edgeUnitVec: &v182,
                  oldAreaNormal: &this->m_areaNormal,
                  newAreaNormal: (const bfx::Vec3 *)v96);
        bfx::Surfer::UpdateArea(this, pNewArea: v92, edgeVec: &v182);
        v97 = (bfx::Edge **)edgesTraversed->m_data;
        v98 = (bfx::Edge **)&edgesTraversed->m_data[edgesTraversed->m_size];
        if ( (bfx::Edge **)edgesTraversed->m_data == v98 )
        {
LABEL_47:
          bfx::Array<bfx::Portal *>::push_back(this: edgesTraversed, val: (bfx::Space **)&v186);
        }
        else
        {
          while ( *v97 != (bfx::Edge *)v92 )
          {
            if ( ++v97 == v98 )
              goto LABEL_47;
          }
        }
        goto LABEL_48;
      }
    }
    this->OnEdge(this, a2: (const bfx::Vec3 *)&v191);
    v99 = v182.m_y;
    v100 = v182.m_z;
    v101 = v182.m_x;
    v102 = (float)((float)(vel->m_x * v182.m_x) + (float)((float)(v182.m_z * vel->m_z) + (float)(v182.m_y * vel->m_y)));
    v103 = (float)((float)(v182.m_z * v188.m_pos.m_z)
                 + (float)((float)(v182.m_x * v188.m_pos.m_x) + (float)(v182.m_y * v188.m_pos.m_y)));
    v104 = (float)(v182.m_z
                 * (float)((float)(vel->m_x * v182.m_x)
                         + (float)((float)(v182.m_z * vel->m_z) + (float)(v182.m_y * vel->m_y))));
    vel->m_z = v182.m_z
             * (float)((float)(vel->m_x * v182.m_x)
                     + (float)((float)(v182.m_z * vel->m_z) + (float)(v182.m_y * vel->m_y)));
    vel->m_x = (float)v102 * (float)v101;
    vel->m_y = (float)v99 * (float)v102;
    if ( __fsqrts((float)((float)((float)((float)v99 * (float)v102) * (float)((float)v99 * (float)v102))
                        + (float)((float)((float)((float)v102 * (float)v101) * (float)((float)v102 * (float)v101))
                                + (float)((float)v104 * (float)v104)))) < 1.0e-10 )
    {
      v57 = 0.0;
      *vel = bfx::ZERO_VEC;
      return *((float *)&v57 + 1);
    }
    p_m_pos = &this->m_pos;
    if ( v103 <= 0.0 )
    {
      v143 = (float)((float)((float)((float)v78 - this->m_pos.m_y) * (float)v99)
                   + (float)((float)((float)((float)v77 - this->m_pos.m_x) * (float)v101)
                           + (float)((float)((float)v76 - this->m_pos.m_z) * (float)v100)));
      if ( v103 > v143 && v143 < 0.0 )
        goto LABEL_56;
      this->m_pos.m_y = v78;
      p_m_pos->m_x = v77;
      this->m_pos.m_z = v76;
      v144 = this->m_edgeCursor.m_i - 1;
      this->m_edgeCursor.m_i = v144;
      if ( v144 < 0 )
        this->m_edgeCursor.m_i = (p_m_edgeCursor->m_pArea->m_flags.m_flags1 & 0x7F) - 1;
      v186.m_pArea = (bfx::Area *)(&p_m_edgeCursor->m_pArea[1].m_pProxy)[6 * this->m_edgeCursor.m_i];
      v145 = (bfx::Vec3 *)v186.m_pArea;
      if ( v186.m_pArea == nullptr )
        goto LABEL_105;
      v146 = (bfx::Edge **)edgesTraversed->m_data;
      v147 = (bfx::Edge **)&edgesTraversed->m_data[edgesTraversed->m_size];
      if ( (bfx::Edge **)edgesTraversed->m_data == v147 )
      {
LABEL_102:
        v148 = 0;
      }
      else
      {
        while ( *v146 != (bfx::Edge *)v186.m_pArea )
        {
          if ( ++v146 == v147 )
            goto LABEL_102;
        }
        v148 = 1;
      }
      if ( v148 != 0
        || (v149 = this->OkToMoveOntoArea(this, a2: v186.m_pArea),
            v100 = v182.m_z,
            v99 = v182.m_y,
            v150 = 1,
            v101 = v182.m_x,
            !v149) )
      {
LABEL_105:
        v150 = 0;
      }
      v151 = v150;
      if ( v150 == 0 )
      {
        bfx::EdgeCursor::GetEdgeVec(this: (bfx::EdgeCursor *)&v188, result: (bfx::Vec3 *)&this->m_edgeCursor);
        v152 = *(float *)&v188.m_pFirstLink;
        v153 = *(float *)&v188.m_pProxy;
        v154 = *(float *)&v188.m_dynAreaData.m_data;
        if ( (float)((float)(*(float *)&v188.m_dynAreaData.m_data * (float)v99)
                   + (float)((float)(*(float *)&v188.m_pProxy * (float)v101)
                           + (float)(*(float *)&v188.m_pFirstLink * (float)v100))) < 0.0 )
        {
          v155 = p_m_edgeCursor->m_pArea;
          v156 = this->m_edgeCursor.m_i + 1;
          this->m_edgeCursor.m_i = v156;
          if ( v156 >= (signed int)(v155->m_flags.m_flags1 & 0x7F) )
            this->m_edgeCursor.m_i = 0;
          vel->m_x = 0.0;
          vel->m_y = 0.0;
          vel->m_z = 0.0;
          v194[0] = -v153;
          v194[1] = -v154;
          v194[2] = -v152;
          this->PushingIntoCorner(this, a2: &v182, a3: (const bfx::Vec3 *)v194);
          v57 = 0.0;
          return *((float *)&v57 + 1);
        }
      }
      if ( p_m_edgeCursor->m_pArea != nullptr )
        v157 = (bfx::Space *)((char *)&p_m_edgeCursor->m_pArea[1] + 24 * this->m_edgeCursor.m_i);
      else
        v157 = nullptr;
      v158 = a6->m_data;
      v159 = (int)&a6->m_data[a6->m_size];
      v62 = a6->m_data == (bfx::Space **)v159;
      v181[0] = v157;
      if ( v62 )
      {
LABEL_118:
        bfx::Array<bfx::Portal *>::push_back(this: a6, val: v181);
      }
      else
      {
        while ( *v158 != v157 )
        {
          if ( ++v158 == (bfx::Space **)v159 )
            goto LABEL_118;
        }
      }
      if ( v151 != 0 )
      {
        v160 = p_m_edgeCursor->m_pArea;
        v161 = this->m_edgeCursor.m_i;
        v162 = p_m_edgeCursor->m_pArea->m_flags.m_flags1 & 0x7F;
        v163 = (float *)(&p_m_edgeCursor->m_pArea[1].m_dynAreaData + 6 * v161);
        v164 = v162 & ~(__ROL4__(v161 + 1, 1) - 1);
        v166 = *((char **)&p_m_edgeCursor->m_pArea[1].m_pFirstLink + 6 * v161);
        v165 = 24 * ((v161 + 1) % v162);
        __twllei(v162, 0);
        v167 = *v163;
        v168 = (float *)((char *)v160 + v165);
        v169 = v163[2];
        __twlgei(v164, 0xFFFFFFFF);
        v188.m_dynAreaData.m_data = v166;
        *(float *)&v188.m_pProxy = v167;
        v170 = v168[17];
        v171 = v168[15];
        v187.m_y = v168[16];
        *(float *)&v188.m_pFirstLink = v169;
        v187.m_z = v170;
        v187.m_x = v171;
        _FP0 = (float)((float)__fsqrts((float)((float)((float)(v171 - v167) * (float)(v171 - v167))
                                             + (float)((float)((float)(v170 - v169) * (float)(v170 - v169))
                                                     + (float)((float)(v187.m_y - *(float *)&v188.m_dynAreaData.m_data)
                                                             * (float)(v187.m_y - *(float *)&v188.m_dynAreaData.m_data)))))
                     - (float)1.0842022e-19);
        __asm { fsel      f12, f0, f13, f31 }
        v190.m_x = (float)(v171 - v167) * (float)_FP12;
        v190.m_y = (float)(v187.m_y - *(float *)&v188.m_dynAreaData.m_data) * (float)_FP12;
        v190.m_z = (float)(v170 - v169) * (float)_FP12;
        v174 = bfx::Area::CalcNormal(this: v197, result: v145);
        *vel = *bfx::RotateVecIntoNewArea(
                  result: &v197[0].m_pos,
                  vec: vel,
                  edgeUnitVec: &v190,
                  oldAreaNormal: &this->m_areaNormal,
                  newAreaNormal: (const bfx::Vec3 *)v174);
        bfx::Surfer::UpdateArea(this, pNewArea: (bfx::Area *)v145, edgeVec: &v190);
        v175 = (bfx::Edge **)edgesTraversed->m_data;
        v176 = (bfx::Edge **)&edgesTraversed->m_data[edgesTraversed->m_size];
        if ( (bfx::Edge **)edgesTraversed->m_data == v176 )
        {
LABEL_123:
          bfx::Array<bfx::Portal *>::push_back(this: edgesTraversed, val: (bfx::Space **)&v186);
        }
        else
        {
          while ( *v175 != (bfx::Edge *)v145 )
          {
            if ( ++v175 == v176 )
              goto LABEL_123;
          }
        }
        bfx::EdgeCursor::GetSibling(this: &v183, result: &this->m_edgeCursor);
        *p_m_edgeCursor = v183;
        if ( p_m_edgeCursor->m_pArea != nullptr )
          v177 = (bfx::Space *)((char *)&p_m_edgeCursor->m_pArea[1] + 24 * this->m_edgeCursor.m_i);
        else
          v177 = nullptr;
        v178 = a6->m_data;
        v179 = (int)&a6->m_data[a6->m_size];
        v62 = a6->m_data == (bfx::Space **)v179;
        v181[0] = v177;
        if ( v62 )
        {
LABEL_130:
          bfx::Array<bfx::Portal *>::push_back(this: a6, val: v181);
        }
        else
        {
          while ( *v178 != v177 )
          {
            if ( ++v178 == (bfx::Space **)v179 )
              goto LABEL_130;
          }
        }
      }
      if ( v143 <= 0.0 )
      {
        v57 = (float)((float)((float)((float)v103 - (float)v143) / (float)v103) * (float)time);
        return *((float *)&v57 + 1);
      }
    }
    else
    {
      v106 = (float)((float)((float)((float)v83 - this->m_pos.m_x) * (float)v101)
                   + (float)((float)((float)((float)v82 - this->m_pos.m_z) * (float)v100)
                           + (float)((float)((float)v84 - this->m_pos.m_y) * (float)v99)));
      if ( v103 < v106 && v106 > 0.0 )
      {
LABEL_56:
        v107 = this->m_pos.m_y;
        v108 = this->m_pos.m_z;
        v57 = 0.0;
        p_m_pos->m_x = (float)((float)v101 * (float)v103) + p_m_pos->m_x;
        this->m_pos.m_y = (float)((float)v99 * (float)v103) + (float)v107;
        this->m_pos.m_z = (float)((float)v100 * (float)v103) + (float)v108;
        return *((float *)&v57 + 1);
      }
      p_m_pos->m_x = v83;
      this->m_pos.m_y = v84;
      this->m_pos.m_z = v82;
      v109 = p_m_edgeCursor->m_pArea;
      v110 = this->m_edgeCursor.m_i + 1;
      this->m_edgeCursor.m_i = v110;
      if ( v110 >= (signed int)(v109->m_flags.m_flags1 & 0x7F) )
        this->m_edgeCursor.m_i = 0;
      v181[0] = (bfx::Space *)(&p_m_edgeCursor->m_pArea[1].m_pProxy)[6 * this->m_edgeCursor.m_i];
      v111 = (bfx::Area *)v181[0];
      if ( v181[0] == nullptr )
        goto LABEL_66;
      v112 = (bfx::Edge **)edgesTraversed->m_data;
      v113 = (bfx::Edge **)&edgesTraversed->m_data[edgesTraversed->m_size];
      if ( (bfx::Edge **)edgesTraversed->m_data == v113 )
      {
LABEL_63:
        v114 = 0;
      }
      else
      {
        while ( *v112 != (bfx::Edge *)v181[0] )
        {
          if ( ++v112 == v113 )
            goto LABEL_63;
        }
        v114 = 1;
      }
      if ( v114 != 0
        || (v115 = this->OkToMoveOntoArea(this, a2: (bfx::Area *)v181[0]),
            v100 = v182.m_z,
            v99 = v182.m_y,
            v116 = 1,
            v101 = v182.m_x,
            !v115) )
      {
LABEL_66:
        v116 = 0;
      }
      v117 = v116;
      if ( v116 == 0 )
      {
        bfx::EdgeCursor::GetEdgeVec(
          this: (bfx::EdgeCursor *)&v188.m_searchCost,
          result: (bfx::Vec3 *)&this->m_edgeCursor);
        if ( (float)((float)(*(float *)&v188.m_searchCost * (float)v101)
                   + (float)((float)(*(float *)&v188.m_flags.m_flags1 * (float)v100)
                           + (float)(*(float *)&v188.m_usageFlags * (float)v99))) < 0.0 )
        {
          v118 = this->m_edgeCursor.m_i - 1;
          this->m_edgeCursor.m_i = v118;
          if ( v118 < 0 )
            this->m_edgeCursor.m_i = (p_m_edgeCursor->m_pArea->m_flags.m_flags1 & 0x7F) - 1;
          vel->m_z = 0.0;
          vel->m_y = 0.0;
          vel->m_x = 0.0;
          v119 = this->__vftable;
          v196[0] = -v101;
          v196[1] = -v99;
          v196[2] = -v100;
          v119->PushingIntoCorner(this, a2: (const bfx::Vec3 *)v196, a3: (const bfx::Vec3 *)&v188.m_searchCost);
          v57 = 0.0;
          return *((float *)&v57 + 1);
        }
      }
      if ( p_m_edgeCursor->m_pArea != nullptr )
        v120 = (bfx::Area *)((char *)p_m_edgeCursor->m_pArea + 24 * this->m_edgeCursor.m_i + 56);
      else
        v120 = nullptr;
      v121 = a6->m_data;
      v122 = (int)&a6->m_data[a6->m_size];
      v62 = a6->m_data == (bfx::Space **)v122;
      v186.m_pArea = v120;
      if ( v62 )
      {
LABEL_79:
        bfx::Array<bfx::Portal *>::push_back(this: a6, val: (bfx::Space **)&v186);
      }
      else
      {
        while ( *v121 != (bfx::Space *)v120 )
        {
          if ( ++v121 == (bfx::Space **)v122 )
            goto LABEL_79;
        }
      }
      if ( v117 != 0 )
      {
        v123 = p_m_edgeCursor->m_pArea;
        v124 = this->m_edgeCursor.m_i;
        v125 = p_m_edgeCursor->m_pArea->m_flags.m_flags1 & 0x7F;
        v126 = (bfx::EdgeCursor *)(&p_m_edgeCursor->m_pArea[1].m_dynAreaData + 6 * v124);
        v127 = v125 & ~(__ROL4__(v124 + 1, 1) - 1);
        v128 = *((float *)&p_m_edgeCursor->m_pArea[1].m_pSearchParent + 6 * v124);
        __twllei(v125, 0);
        v129 = (float *)((char *)v123 + 24 * ((v124 + 1) % v125));
        v130 = *v126;
        __twlgei(v127, 0xFFFFFFFF);
        v184 = v128;
        v131 = v128;
        v132 = v129[15];
        v133 = v129[17];
        v183 = v130;
        v134 = v129[16];
        v187.m_x = v132;
        v187.m_z = v133;
        v187.m_y = v134;
        _FP0 = (float)((float)__fsqrts((float)((float)((float)(v134 - *(float *)&v130.m_i)
                                                     * (float)(v134 - *(float *)&v130.m_i))
                                             + (float)((float)((float)(v132 - *(float *)&v130.m_pArea)
                                                             * (float)(v132 - *(float *)&v130.m_pArea))
                                                     + (float)((float)(v133 - (float)v131) * (float)(v133 - (float)v131)))))
                     - (float)1.0842022e-19);
        __asm { fsel      f12, f0, f13, f31 }
        *(float *)&v188.m_flags.m_flags3 = (float)(v132 - *(float *)&v130.m_pArea) * (float)_FP12;
        *(float *)&v188.m_flags.m_flags4 = (float)(v134 - *(float *)&v130.m_i) * (float)_FP12;
        v189 = (float)(v133 - (float)v131) * (float)_FP12;
        v137 = bfx::Area::CalcNormal(this: &v188, result: (bfx::Vec3 *)v181[0]);
        *vel = *bfx::RotateVecIntoNewArea(
                  result: (bfx::Vec3 *)v197,
                  vec: vel,
                  edgeUnitVec: (const bfx::Vec3 *)&v188.m_flags.m_flags3,
                  oldAreaNormal: &this->m_areaNormal,
                  newAreaNormal: (const bfx::Vec3 *)v137);
        bfx::Surfer::UpdateArea(this, pNewArea: v111, edgeVec: (const bfx::Vec3 *)&v188.m_flags.m_flags3);
        v138 = (bfx::Edge **)edgesTraversed->m_data;
        v139 = (bfx::Edge **)&edgesTraversed->m_data[edgesTraversed->m_size];
        if ( (bfx::Edge **)edgesTraversed->m_data == v139 )
        {
LABEL_84:
          bfx::Array<bfx::Portal *>::push_back(this: edgesTraversed, val: v181);
        }
        else
        {
          while ( *v138 != (bfx::Edge *)v111 )
          {
            if ( ++v138 == v139 )
              goto LABEL_84;
          }
        }
        bfx::EdgeCursor::GetSibling(this: &v186, result: &this->m_edgeCursor);
        *p_m_edgeCursor = v186;
        if ( p_m_edgeCursor->m_pArea != nullptr )
          v140 = (bfx::Space *)((char *)&p_m_edgeCursor->m_pArea[1] + 24 * this->m_edgeCursor.m_i);
        else
          v140 = nullptr;
        v141 = a6->m_data;
        v142 = (int)&a6->m_data[a6->m_size];
        v62 = a6->m_data == (bfx::Space **)v142;
        v181[0] = v140;
        if ( v62 )
        {
LABEL_91:
          bfx::Array<bfx::Portal *>::push_back(this: a6, val: v181);
        }
        else
        {
          while ( *v141 != v140 )
          {
            if ( ++v141 == (bfx::Space **)v142 )
              goto LABEL_91;
          }
        }
      }
      if ( v106 >= 0.0 )
      {
        v57 = (float)((float)((float)((float)v103 - (float)v106) / (float)v103) * (float)time);
        return *((float *)&v57 + 1);
      }
    }
LABEL_49:
    v57 = time;
    return *((float *)&v57 + 1);
  }
  v21 = &this->m_edgeCursor;
  v22 = &this->m_pos;
  if ( (unsigned __int8)bfx::MoveThroughArea(
                          origLineStart: &this->m_pos,
                          origLineDelta: &v188.m_pos,
                          pArea: m_pArea,
                          areaNormal: &this->m_areaNormal,
                          endPos: &v195,
                          exitEdgeCursor: &this->m_edgeCursor) == 0 )
  {
    v63 = (float)(v188.m_pos.m_y + this->m_pos.m_y);
    v64 = (float)(v188.m_pos.m_z + this->m_pos.m_z);
    v57 = 0.0;
    v22->m_x = v188.m_pos.m_x + v22->m_x;
    this->m_pos.m_y = v63;
    this->m_pos.m_z = v64;
    return *((float *)&v57 + 1);
  }
  v23 = (float)(v195.m_x - v22->m_x);
  v24 = this->m_pos.m_z;
  v25 = v195.m_y;
  v26 = v195.m_z;
  v27 = (float)(v195.m_y - this->m_pos.m_y);
  v22->m_x = v195.m_x;
  this->m_pos.m_y = v25;
  this->m_pos.m_z = v26;
  v28 = v21->m_pArea;
  v29 = this->m_edgeCursor.m_i;
  m_size = a6->m_size;
  v31 = a6->m_data;
  v32 = (bfx::EdgeCursor *)(&v21->m_pArea[1].m_dynAreaData + 6 * v29);
  v33 = (bfx::Area **)((char *)&v21->m_pArea[1] + 24 * v29);
  v34 = v21->m_pArea->m_flags.m_flags1 & 0x7F;
  v35 = *v33;
  v36 = v21->m_pArea == nullptr ? nullptr : v33;
  v184 = *((float *)&v21->m_pArea[1].m_pSearchParent + 6 * v29);
  v37 = __ROL4__(v29 + 1, 1) - 1;
  v183 = *v32;
  v38 = *(float *)&v183.m_i;
  v39 = v184;
  v40 = *(float *)&v183.m_pArea;
  __twllei(v34, 0);
  v186.m_pArea = v35;
  v41 = (char *)v28 + 24 * ((v29 + 1) % v34);
  __twlgei(v34 & ~v37, 0xFFFFFFFF);
  v42 = &v31[m_size];
  v183.m_i = *((_DWORD *)v41 + 16);
  v184 = *((float *)v41 + 17);
  v183.m_pArea = *((bfx::Area **)v41 + 15);
  v43 = __fsqrts((float)((float)((float)v27 * (float)v27)
                       + (float)((float)((float)v23 * (float)v23)
                               + (float)((float)((float)v26 - (float)v24) * (float)((float)v26 - (float)v24)))));
  v44 = (float)(*(float *)&v183.m_pArea - (float)v40);
  _FP3 = (float)((float)__fsqrts((float)((float)((float)(*(float *)&v183.m_pArea - (float)v40)
                                               * (float)(*(float *)&v183.m_pArea - (float)v40))
                                       + (float)((float)((float)(v184 - (float)v39) * (float)(v184 - (float)v39))
                                               + (float)((float)(*(float *)&v183.m_i - (float)v38)
                                                       * (float)(*(float *)&v183.m_i - (float)v38)))))
               - (float)1.0842022e-19);
  __asm { fsel      f1, f3, f2, f12 }
  v47 = (float)((float)v44 * (float)_FP1);
  v185.m_x = (float)v44 * (float)_FP1;
  v48 = (float)((float)(*(float *)&v183.m_i - (float)v38) * (float)_FP1);
  v185.m_y = (float)(*(float *)&v183.m_i - (float)v38) * (float)_FP1;
  v49 = (float)((float)(v184 - (float)v39) * (float)_FP1);
  v185.m_z = (float)(v184 - (float)v39) * (float)_FP1;
  if ( v31 == v42 )
  {
LABEL_9:
    v50 = 0;
  }
  else
  {
    while ( *v31 != (bfx::Space *)v36 )
    {
      if ( ++v31 == v42 )
        goto LABEL_9;
    }
    v50 = 1;
  }
  if ( v35 == nullptr || v50 != 0 )
    goto LABEL_25;
  v51 = (bfx::Edge **)edgesTraversed->m_data;
  v52 = (bfx::Edge **)&edgesTraversed->m_data[edgesTraversed->m_size];
  if ( (bfx::Edge **)edgesTraversed->m_data == v52 )
  {
LABEL_15:
    v53 = 0;
  }
  else
  {
    while ( *v51 != (bfx::Edge *)v35 )
    {
      if ( ++v51 == v52 )
        goto LABEL_15;
    }
    v53 = 1;
  }
  if ( v53 != 0 )
    goto LABEL_25;
  if ( !this->OkToMoveOntoArea(this, a2: v35) )
  {
    v49 = v185.m_z;
    v48 = v185.m_y;
    v47 = v185.m_x;
LABEL_25:
    v58 = (float)((float)(vel->m_x * (float)v47)
                + (float)((float)((float)v49 * vel->m_z) + (float)((float)v48 * vel->m_y)));
    vel->m_x = (float)((float)(vel->m_x * (float)v47)
                     + (float)((float)((float)v49 * vel->m_z) + (float)((float)v48 * vel->m_y)))
             * (float)v47;
    vel->m_y = (float)v48 * (float)v58;
    vel->m_z = (float)v49 * (float)v58;
    if ( v50 == 0 )
    {
      if ( v21->m_pArea != nullptr )
        v59 = (bfx::Area *)((char *)v21->m_pArea + 24 * this->m_edgeCursor.m_i + 56);
      else
        v59 = nullptr;
      v60 = a6->m_data;
      v61 = (int)&a6->m_data[a6->m_size];
      v62 = a6->m_data == (bfx::Space **)v61;
      v186.m_pArea = v59;
      if ( v62 )
      {
LABEL_32:
        bfx::Array<bfx::Portal *>::push_back(this: a6, val: (bfx::Space **)&v186);
      }
      else
      {
        while ( *v60 != (bfx::Space *)v59 )
        {
          if ( ++v60 == (bfx::Space **)v61 )
            goto LABEL_32;
        }
      }
    }
    this->m_state = 1;
    goto LABEL_34;
  }
  v54 = bfx::Area::CalcNormal(this: &v188, result: (bfx::Vec3 *)v35);
  *vel = *bfx::RotateVecIntoNewArea(
            result: &v187,
            vec: vel,
            edgeUnitVec: &v185,
            oldAreaNormal: &this->m_areaNormal,
            newAreaNormal: (const bfx::Vec3 *)v54);
  bfx::Surfer::UpdateArea(this, pNewArea: v35, edgeVec: &v185);
  v55 = (bfx::Edge **)edgesTraversed->m_data;
  v56 = (bfx::Edge **)&edgesTraversed->m_data[edgesTraversed->m_size];
  if ( (bfx::Edge **)edgesTraversed->m_data != v56 )
  {
    while ( *v55 != (bfx::Edge *)v35 )
    {
      if ( ++v55 == v56 )
        goto LABEL_21;
    }
LABEL_34:
    v57 = (float)((float)((float)v19 - (float)v43) / (float)v18);
    return *((float *)&v57 + 1);
  }
LABEL_21:
  bfx::Array<bfx::Portal *>::push_back(this: edgesTraversed, val: (bfx::Space **)&v186);
  v57 = (float)((float)((float)v19 - (float)v43) / (float)v18);
  return *((float *)&v57 + 1);
}


// ========================================================================
// ?Move@Surfer@bfx@@QAAXABVVec3@2@M@Z
// EA  : 0x832C0850
// RVA : 0x012C0850
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxsurfer.cpp
// ========================================================================

void __fastcall bfx::Surfer::Move(bfx::Surfer *this, const bfx::Vec3 *origVel, double time)
{
  float m_y; // r10
  float m_z; // r9
  bfx::AreaProxy *m_pProxy; // r11
  int v8; // r30
  bfx::Space *m_pArea; // r11
  bfx::Array<bfx::Area *> *v10; // r5
  bfx::Area *v11; // r9
  bfx::Space *v12; // r11
  double v13; // fp2
  double v14; // fp1
  double v15; // fp0
  double v16; // fp9
  bfx::Space *v17[2]; // [sp+50h] [-70h] BYREF
  bfx::Vec3 v18; // [sp+58h] [-68h] BYREF
  bfx::Vec3 v19[2]; // [sp+68h] [-58h] BYREF

  m_y = origVel->m_y;
  m_z = origVel->m_z;
  v18.m_x = origVel->m_x;
  v18.m_y = m_y;
  v18.m_z = m_z;
  bfx::GetUpVec(result: v19);
  m_pProxy = this->m_area.m_pProxy;
  v8 = 0;
  if ( m_pProxy != nullptr )
    m_pArea = (bfx::Space *)m_pProxy->m_pArea;
  else
    m_pArea = nullptr;
  this->m_areasTraversed.m_size = 0;
  v17[0] = m_pArea;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_areasTraversed.m_data);
  this->m_areasTraversed.m_data = nullptr;
  this->m_areasTraversed.m_cap = 0;
  this->m_edgesTraversed.m_size = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_edgesTraversed.m_data);
  this->m_edgesTraversed.m_data = nullptr;
  this->m_edgesTraversed.m_cap = 0;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_areasTraversed, val: v17);
  if ( this->m_state == 1 )
  {
    v11 = this->m_edgeCursor.m_pArea;
    if ( v11 != nullptr )
      v12 = (bfx::Space *)((char *)&v11[1] + 24 * this->m_edgeCursor.m_i);
    else
      v12 = nullptr;
    v17[0] = v12;
    bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_edgesTraversed, val: v17);
  }
  for ( ; time > 0.0; ++v8 )
  {
    if ( v8 >= 10 )
      break;
    v13 = (float)(this->m_areaNormal.m_x
                * (float)((float)(this->m_areaNormal.m_z * v18.m_z)
                        + (float)((float)(this->m_areaNormal.m_x * v18.m_x) + (float)(this->m_areaNormal.m_y * v18.m_y))));
    v14 = (float)(v18.m_y
                - (float)(this->m_areaNormal.m_y
                        * (float)((float)(this->m_areaNormal.m_z * v18.m_z)
                                + (float)((float)(this->m_areaNormal.m_x * v18.m_x)
                                        + (float)(this->m_areaNormal.m_y * v18.m_y)))));
    v15 = (float)(v18.m_z
                - (float)(this->m_areaNormal.m_z
                        * (float)((float)(this->m_areaNormal.m_z * v18.m_z)
                                + (float)((float)(this->m_areaNormal.m_x * v18.m_x)
                                        + (float)(this->m_areaNormal.m_y * v18.m_y)))));
    v18.m_z = v18.m_z
            - (float)(this->m_areaNormal.m_z
                    * (float)((float)(this->m_areaNormal.m_z * v18.m_z)
                            + (float)((float)(this->m_areaNormal.m_x * v18.m_x)
                                    + (float)(this->m_areaNormal.m_y * v18.m_y))));
    v18.m_y = v14;
    v16 = (float)((float)((float)(v18.m_x - (float)v13) * (float)(v18.m_x - (float)v13))
                + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)));
    v18.m_x = v18.m_x - (float)v13;
    if ( __fsqrts(v16) < 1.0e-10 )
      break;
    time = bfx::Surfer::MoveOnce(
             this,
             vel: &v18,
             time,
             areasTraversed: v10,
             edgesTraversed: (bfx::Array<bfx::Space *> *)&this->m_areasTraversed,
             a6: (bfx::Array<bfx::Space *> *)&this->m_edgesTraversed);
  }
}


// ========================================================================
// ?SetPosAndArea@Surfer@bfx@@QAAXABVVec3@2@PAVArea@2@@Z
// EA  : 0x832C0A08
// RVA : 0x012C0A08
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxsurfer.cpp
// ========================================================================

void __fastcall bfx::Surfer::SetPosAndArea(bfx::Surfer *this, const bfx::Vec3 *pos, bfx::Vec3 *pArea)
{
  float *v5; // r3
  double v6; // fp11
  double v7; // fp10
  double v8; // fp9
  double m_y; // fp8
  double m_x; // fp6
  double m_z; // fp4
  double v12; // fp2
  const bfx::Handle<bfx::Area> *v13; // r3
  bfx::Handle<bfx::Area> v14; // [sp+50h] [-50h] BYREF
  float v15; // [sp+54h] [-4Ch]
  bfx::Vec3 v16; // [sp+58h] [-48h] BYREF
  bfx::Area v17; // [sp+68h] [-38h] BYREF

  if ( pArea != nullptr )
  {
    this->m_pos = *bfx::GetClosestPosInArea(result: &v16, pArea, pos, pEdgeIndexOut: nullptr);
    v5 = (float *)bfx::Area::CalcNormal(this: &v17, result: pArea);
    LODWORD(v15) = &this->m_areaNormal;
    v6 = *v5;
    this->m_areaNormal.m_x = *v5;
    v7 = v5[1];
    this->m_areaNormal.m_y = v5[1];
    v8 = v5[2];
    this->m_areaNormal.m_z = v5[2];
    m_y = this->m_pos.m_y;
    v16.m_y = pArea[1].m_z;
    m_x = this->m_pos.m_x;
    m_z = this->m_pos.m_z;
    v16.m_x = pArea[1].m_y;
    v16.m_z = pArea[2].m_x;
    v15 = v8;
    v12 = (float)((float)((float)v8 * (float)((float)m_z - v16.m_z))
                + (float)((float)((float)v6 * (float)((float)m_x - v16.m_x))
                        + (float)((float)v7 * (float)((float)m_y - v16.m_y))));
    this->m_pos.m_x = (float)m_x
                    - (float)((float)v6
                            * (float)((float)((float)v8 * (float)((float)m_z - v16.m_z))
                                    + (float)((float)((float)v6 * (float)((float)m_x - v16.m_x))
                                            + (float)((float)v7 * (float)((float)m_y - v16.m_y)))));
    this->m_pos.m_y = (float)m_y - (float)((float)v7 * (float)v12);
    this->m_pos.m_z = (float)m_z - (float)((float)v8 * (float)v12);
    v13 = bfx::Handle<bfx::Area>::Handle<bfx::Area>(this: &v14, (bfx::Area *)pArea);
    bfx::Handle<bfx::Area>::operator=(this: &this->m_area, rhs: v13);
    bfx::Handle<bfx::Area>::Release(this: &v14);
    this->m_state = ON_AREA;
  }
  else
  {
    this->m_pos = *pos;
  }
}


// ========================================================================
// __unwind$22111
// EA  : 0x832C0B5C
// RVA : 0x012C0B5C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxsurfer.cpp
// ========================================================================

void _unwind_22111()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(v0 - 160 + 80));
}

