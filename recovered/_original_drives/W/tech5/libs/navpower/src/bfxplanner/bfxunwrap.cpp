
// ========================================================================
// ??0Unwrapper@bfx@@QAA@PAVArea@1@@Z
// EA  : 0x832DC518
// RVA : 0x012DC518
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxunwrap.cpp
// ========================================================================

bfx::Unwrapper *__fastcall bfx::Unwrapper::Unwrapper(bfx::Unwrapper *this, bfx::Area *pArea)
{
  float v2; // r5
  double v4; // fp28
  bfx::Area *m_pSearchParent; // r9
  double v6; // fp26
  double v7; // fp27
  double v10; // fp25
  double v11; // fp24
  double v12; // fp23
  double v13; // fp0
  double v14; // fp13
  double v15; // fp12
  double v16; // fp9
  double v17; // fp8
  double v18; // fp7
  double v21; // fp10
  double v22; // fp9
  double v23; // fp8
  double v24; // fp2
  double v25; // fp0
  double v26; // fp12
  bfx::Unwrapper *result; // r3
  double m_y; // fp10
  double v33; // fp12
  double m_x; // fp13
  double m_z; // fp9
  double v36; // fp7
  double v37; // fp6
  bfx::Area v38; // [sp+50h] [-80h] BYREF

  this->m_pArea = pArea;
  v2 = *(float *)&pArea[1].m_searchCost;
  v38.m_dynAreaData.m_data = (char *)pArea[1].m_pFirstLink;
  v38.m_pos.m_y = v2;
  v4 = *(float *)&v38.m_dynAreaData.m_data;
  v38.m_pProxy = (bfx::AreaProxy *)pArea[1].m_dynAreaData.m_data;
  m_pSearchParent = pArea[1].m_pSearchParent;
  LODWORD(v38.m_pos.m_z) = pArea[1].m_usageFlags;
  v6 = *(float *)&v38.m_pProxy;
  v38.m_pFirstLink = (bfx::HalfLink *)m_pSearchParent;
  v38.m_pos.m_x = pArea[1].m_radius;
  v7 = *(float *)&m_pSearchParent;
  _FP4 = (float)((float)__fsqrts((float)((float)((float)(v38.m_pos.m_x - *(float *)&v38.m_pProxy)
                                               * (float)(v38.m_pos.m_x - *(float *)&v38.m_pProxy))
                                       + (float)((float)((float)(v38.m_pos.m_z - *(float *)&m_pSearchParent)
                                                       * (float)(v38.m_pos.m_z - *(float *)&m_pSearchParent))
                                               + (float)((float)(v2 - *(float *)&v38.m_dynAreaData.m_data)
                                                       * (float)(v2 - *(float *)&v38.m_dynAreaData.m_data)))))
               - (float)1.0842022e-19);
  __asm { fsel      f2, f4, f3, f31 }
  v10 = (float)((float)(v38.m_pos.m_x - *(float *)&v38.m_pProxy) * (float)_FP2);
  v11 = (float)((float)(v2 - *(float *)&v38.m_dynAreaData.m_data) * (float)_FP2);
  v12 = (float)((float)(v38.m_pos.m_z - *(float *)&m_pSearchParent) * (float)_FP2);
  bfx::Area::CalcNormal(this: &v38, result: (bfx::Vec3 *)pArea);
  v13 = *(float *)&v38.m_pProxy;
  v14 = *(float *)&v38.m_dynAreaData.m_data;
  v15 = *(float *)&v38.m_pFirstLink;
  v16 = (float)((float)(*(float *)&v38.m_pFirstLink * (float)v10) - (float)((float)v12 * *(float *)&v38.m_pProxy));
  v17 = (float)((float)((float)v11 * *(float *)&v38.m_pProxy) - (float)(*(float *)&v38.m_dynAreaData.m_data * (float)v10));
  v18 = (float)((float)(*(float *)&v38.m_dynAreaData.m_data * (float)v12)
              - (float)(*(float *)&v38.m_pFirstLink * (float)v11));
  _FP2 = (float)((float)__fsqrts((float)((float)((float)v18 * (float)v18)
                                       + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))))
               - (float)1.0842022e-19);
  __asm { fsel      f11, f2, f1, f31 }
  v21 = (float)((float)((float)(*(float *)&v38.m_dynAreaData.m_data * (float)v12)
                      - (float)(*(float *)&v38.m_pFirstLink * (float)v11))
              * (float)_FP11);
  this->m_yG.m_x = (float)((float)(*(float *)&v38.m_dynAreaData.m_data * (float)v12)
                         - (float)(*(float *)&v38.m_pFirstLink * (float)v11))
                 * (float)_FP11;
  v22 = (float)((float)v16 * (float)_FP11);
  this->m_yG.m_y = v22;
  v23 = (float)((float)v17 * (float)_FP11);
  this->m_yG.m_z = v23;
  v24 = (float)((float)((float)v23 * (float)v13) - (float)((float)v21 * (float)v15));
  v25 = (float)((float)((float)v21 * (float)v14) - (float)((float)v22 * (float)v13));
  v26 = (float)((float)((float)v22 * (float)v15) - (float)((float)v23 * (float)v14));
  _FP8 = (float)((float)__fsqrts((float)((float)((float)v26 * (float)v26)
                                       + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))))
               - (float)1.0842022e-19);
  __asm { fsel      f6, f8, f7, f31 }
  this->m_xG.m_y = (float)v24 * (float)_FP6;
  this->m_xG.m_x = (float)_FP6 * (float)v26;
  this->m_xG.m_z = (float)v25 * (float)_FP6;
  this->m_oG.m_x = v6;
  this->m_oG.m_y = v4;
  this->m_oG.m_z = v7;
  if ( this->m_xG.m_x == 0.0 && this->m_xG.m_y == 0.0 )
  {
    this->m_xU.m_x = 1.0;
    result = this;
    this->m_xU.m_y = 0.0;
    this->m_xU.m_z = 0.0;
    this->m_yU.m_x = 0.0;
    this->m_yU.m_y = 1.0;
    this->m_yU.m_z = 0.0;
  }
  else
  {
    this->m_xU.m_x = this->m_xG.m_x;
    result = this;
    this->m_xU.m_y = this->m_xG.m_y;
    this->m_xU.m_z = this->m_xG.m_z;
    this->m_xU.m_z = 0.0;
    m_y = this->m_xU.m_y;
    _FP2 = (float)((float)__fsqrts((float)((float)((float)0.0 * (float)0.0)
                                         + (float)((float)(this->m_xU.m_x * this->m_xU.m_x)
                                                 + (float)(this->m_xU.m_y * this->m_xU.m_y))))
                 - (float)1.0842022e-19);
    __asm { fsel      f0, f2, f1, f31 }
    this->m_xU.m_x = this->m_xU.m_x * (float)_FP0;
    this->m_xU.m_y = (float)_FP0 * (float)m_y;
    this->m_xU.m_z = (float)_FP0 * (float)0.0;
    v33 = UNWRAP_UP_VEC_3.m_y;
    m_x = UNWRAP_UP_VEC_3.m_x;
    m_z = this->m_xU.m_z;
    v36 = (float)(this->m_xU.m_x * UNWRAP_UP_VEC_3.m_y);
    v37 = (float)((float)((float)_FP0 * (float)m_y) * UNWRAP_UP_VEC_3.m_z);
    this->m_yU.m_y = (float)(this->m_xU.m_x * UNWRAP_UP_VEC_3.m_z) - (float)(this->m_xU.m_z * UNWRAP_UP_VEC_3.m_x);
    this->m_yU.m_z = (float)((float)((float)_FP0 * (float)m_y) * (float)m_x) - (float)v36;
    this->m_yU.m_x = (float)((float)m_z * (float)v33) - (float)v37;
  }
  this->m_oU.m_z = v7;
  this->m_oU.m_y = v4;
  this->m_oU.m_x = v6;
  return result;
}


// ========================================================================
// ?GetMatU2G@Unwrapper@bfx@@QBA?AVMatrix@2@XZ
// EA  : 0x832DC7B0
// RVA : 0x012DC7B0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxunwrap.cpp
// ========================================================================

bfx::Unwrapper *__fastcall bfx::Unwrapper::GetMatU2G(bfx::Unwrapper *this, bfx::Matrix *result)
{
  double v4; // fp12
  double v5; // fp11
  double v6; // fp10
  double v7; // fp8
  double v8; // fp7
  double v9; // fp6
  double v10; // fp13
  double v11; // fp12
  double v12; // fp8
  double v13; // fp6
  bfx::Vec3 v15; // [sp+50h] [-100h] BYREF
  bfx::Vec3 v16; // [sp+60h] [-F0h] BYREF
  bfx::Matrix v17; // [sp+70h] [-E0h] BYREF
  bfx::Matrix v18; // [sp+B0h] [-A0h] BYREF
  bfx::Matrix v19; // [sp+F0h] [-60h] BYREF

  v4 = result->m_data[5];
  v5 = result->m_data[3];
  v6 = result->m_data[4];
  v7 = result->m_data[1];
  v8 = (float)(result->m_data[4] * result->m_data[2]);
  v9 = (float)(result->m_data[1] * result->m_data[6]);
  v15.m_x = (float)(result->m_data[2] * result->m_data[6]) - (float)(result->m_data[3] * result->m_data[5]);
  v15.m_z = (float)((float)v7 * (float)v4) - (float)v8;
  v15.m_y = (float)((float)v6 * (float)v5) - (float)v9;
  bfx::Matrix::Build(
    this: &v19,
    xAxis: (const bfx::Vec3 *)&result->m_data[1],
    yAxis: (const bfx::Vec3 *)&result->m_data[4],
    zAxis: &v15,
    trans: (const bfx::Vec3 *)&result->m_data[7]);
  v10 = result->m_data[12];
  v11 = result->m_data[13];
  v12 = (float)(result->m_data[10] * result->m_data[15]);
  v13 = (float)((float)(result->m_data[10] * result->m_data[14]) - (float)(result->m_data[13] * result->m_data[11]));
  v16.m_x = (float)(result->m_data[11] * result->m_data[15]) - (float)(result->m_data[12] * result->m_data[14]);
  v16.m_z = v13;
  v16.m_y = (float)((float)v11 * (float)v10) - (float)v12;
  bfx::Matrix::Build(
    this: &v18,
    xAxis: (const bfx::Vec3 *)&result->m_data[10],
    yAxis: (const bfx::Vec3 *)&result->m_data[13],
    zAxis: &v16,
    trans: (const bfx::Vec3 *)&result[1]);
  v17 = v18;
  bfx::Matrix::OrthoInvert(this: &v17);
  bfx::Matrix::operator*((bfx::Matrix *)this, result: &v19, rhs: &v17);
  return this;
}


// ========================================================================
// ?Transform@Unwrapper@bfx@@QBA?AVVec3@2@ABV32@@Z
// EA  : 0x832DC8B8
// RVA : 0x012DC8B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxunwrap.cpp
// ========================================================================

bfx::Unwrapper *__fastcall bfx::Unwrapper::Transform(bfx::Unwrapper *this, bfx::Vec3 *result, const bfx::Vec3 *pos)
{
  double v3; // fp3
  double v4; // fp2
  double v5; // fp0
  double v6; // fp13

  v3 = (float)(result[4].m_z
             * (float)((float)(result[1].m_y * (float)(pos->m_x - result[2].m_y))
                     + (float)((float)(result[1].m_z * (float)(pos->m_y - result[2].m_z))
                             + (float)(result[2].m_x * (float)(pos->m_z - result[3].m_x)))));
  v4 = (float)(result[5].m_x
             * (float)((float)(result[1].m_y * (float)(pos->m_x - result[2].m_y))
                     + (float)((float)(result[1].m_z * (float)(pos->m_y - result[2].m_z))
                             + (float)(result[2].m_x * (float)(pos->m_z - result[3].m_x)))));
  v5 = (float)(result[5].m_z
             + (float)(result[3].m_z
                     * (float)((float)(result->m_y * (float)(pos->m_x - result[2].m_y))
                             + (float)((float)(result->m_z * (float)(pos->m_y - result[2].m_z))
                                     + (float)(result[1].m_x * (float)(pos->m_z - result[3].m_x))))));
  v6 = (float)(result[6].m_x
             + (float)(result[4].m_x
                     * (float)((float)(result->m_y * (float)(pos->m_x - result[2].m_y))
                             + (float)((float)(result->m_z * (float)(pos->m_y - result[2].m_z))
                                     + (float)(result[1].m_x * (float)(pos->m_z - result[3].m_x))))));
  *(float *)&this->m_pArea = (float)(result[5].m_y
                                   + (float)((float)((float)(result->m_y * (float)(pos->m_x - result[2].m_y))
                                                   + (float)((float)(result->m_z * (float)(pos->m_y - result[2].m_z))
                                                           + (float)(result[1].m_x * (float)(pos->m_z - result[3].m_x))))
                                           * result[3].m_y))
                           + (float)(result[4].m_y
                                   * (float)((float)(result[1].m_y * (float)(pos->m_x - result[2].m_y))
                                           + (float)((float)(result[1].m_z * (float)(pos->m_y - result[2].m_z))
                                                   + (float)(result[2].m_x * (float)(pos->m_z - result[3].m_x)))));
  this->m_xG.m_x = (float)v5 + (float)v3;
  this->m_xG.m_y = (float)v6 + (float)v4;
  return this;
}


// ========================================================================
// ?CrossEdge@Unwrapper@bfx@@QAAXABVEdgeCursor@2@@Z
// EA  : 0x832DC988
// RVA : 0x012DC988
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxunwrap.cpp
// ========================================================================

void __fastcall bfx::Unwrapper::CrossEdge(bfx::Unwrapper *this, const bfx::EdgeCursor *cc)
{
  bfx::Area *m_pArea; // r9
  int m_i; // r10
  signed int v5; // r30
  float *v6; // r8
  float v7; // r7
  float *v8; // r11
  float v9; // r30
  float v10; // r6
  float v11; // r8
  float v12; // r7
  float v13; // r11
  bfx::Vec3 *v14; // r4
  int v15; // r10
  double m_x; // fp31
  double m_y; // fp30
  double v18; // fp28
  int v19; // r9
  double m_z; // fp29
  double v21; // fp27
  double v22; // fp26
  bfx::Area *v23; // r4
  double v24; // fp13
  double v25; // fp12
  double v26; // fp11
  double v27; // fp5
  double v28; // fp4
  double v29; // fp3
  double v31; // fp8
  double v32; // fp28
  double v33; // fp7
  double v35; // fp27
  double v36; // fp6
  double v37; // fp26
  double v38; // fp1
  double v39; // fp5
  double v40; // fp3
  double v41; // fp4
  double v43; // fp1
  double v44; // fp13
  double v45; // fp12
  bfx::Vec3 v49; // [sp+50h] [-C0h] BYREF
  bfx::Vec3 v50; // [sp+60h] [-B0h] BYREF
  bfx::Area v51[2]; // [sp+70h] [-A0h] BYREF

  m_pArea = cc->m_pArea;
  m_i = cc->m_i;
  v5 = cc->m_pArea->m_flags.m_flags1 & 0x7F;
  v6 = (float *)((char *)cc->m_pArea + 24 * m_i);
  v7 = v6[15];
  __twlgei(v5 & ~(__ROL4__(m_i + 1, 1) - 1), 0xFFFFFFFF);
  v8 = (float *)((char *)m_pArea + 24 * ((m_i + 1) % v5));
  __twllei(v5, 0);
  v9 = v6[16];
  v10 = v6[17];
  v49.m_x = v7;
  v11 = v8[15];
  v12 = v8[16];
  v13 = v8[17];
  v49.m_y = v9;
  v49.m_z = v10;
  v50.m_x = v11;
  v50.m_y = v12;
  v50.m_z = v13;
  bfx::Unwrapper::Transform(this: (bfx::Unwrapper *)&v51[0].m_searchCost, result: (bfx::Vec3 *)this, pos: &v50);
  bfx::Unwrapper::Transform(this: (bfx::Unwrapper *)&v51[0].m_pos, result: v14, pos: &v49);
  m_x = v49.m_x;
  m_y = v49.m_y;
  v18 = (float)(v50.m_x - v49.m_x);
  m_z = v49.m_z;
  v21 = (float)(v50.m_y - v49.m_y);
  v22 = (float)(v50.m_z - v49.m_z);
  v23 = *(bfx::Area **)(24 * v15 + v19 + 56);
  this->m_pArea = v23;
  bfx::Area::CalcNormal(this: v51, result: (bfx::Vec3 *)v23);
  v24 = *(float *)&v51[0].m_pProxy;
  v25 = *(float *)&v51[0].m_dynAreaData.m_data;
  v26 = *(float *)&v51[0].m_pFirstLink;
  v27 = (float)((float)(*(float *)&v51[0].m_pFirstLink * (float)v18) - (float)((float)v22 * *(float *)&v51[0].m_pProxy));
  v28 = (float)((float)((float)v21 * *(float *)&v51[0].m_pProxy)
              - (float)(*(float *)&v51[0].m_dynAreaData.m_data * (float)v18));
  v29 = (float)((float)(*(float *)&v51[0].m_dynAreaData.m_data * (float)v22)
              - (float)(*(float *)&v51[0].m_pFirstLink * (float)v21));
  _FP2 = (float)((float)__fsqrts((float)((float)((float)v29 * (float)v29)
                                       + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27))))
               - (float)1.0842022e-19);
  v31 = v51[0].m_pos.m_y;
  v32 = (float)(*(float *)&v51[0].m_usageFlags - v51[0].m_pos.m_y);
  v33 = v51[0].m_pos.m_z;
  __asm { fsel      f2, f2, f1, f0 }
  v35 = (float)(*(float *)&v51[0].m_flags.m_flags1 - v51[0].m_pos.m_z);
  v36 = v51[0].m_pos.m_x;
  v37 = (float)(*(float *)&v51[0].m_searchCost - v51[0].m_pos.m_x);
  v38 = (float)((float)(*(float *)&v51[0].m_usageFlags - v51[0].m_pos.m_y)
              * (float)(*(float *)&v51[0].m_usageFlags - v51[0].m_pos.m_y));
  v39 = (float)((float)v27 * (float)_FP2);
  this->m_yG.m_y = v39;
  v40 = (float)((float)v29 * (float)_FP2);
  this->m_yG.m_x = v40;
  v41 = (float)((float)v28 * (float)_FP2);
  this->m_yG.m_z = v41;
  _FP23 = (float)((float)__fsqrts((float)((float)((float)v37 * (float)v37)
                                        + (float)((float)((float)v35 * (float)v35) + (float)v38)))
                - (float)1.0842022e-19);
  v43 = (float)((float)((float)v41 * (float)v24) - (float)((float)v40 * (float)v26));
  v44 = (float)((float)((float)v40 * (float)v25) - (float)((float)v39 * (float)v24));
  v45 = (float)((float)((float)v39 * (float)v26) - (float)((float)v41 * (float)v25));
  __asm { fsel      f11, f23, f2, f0 }
  _FP10 = (float)((float)__fsqrts((float)((float)((float)v45 * (float)v45)
                                        + (float)((float)((float)v44 * (float)v44) + (float)((float)v43 * (float)v43))))
                - (float)1.0842022e-19);
  __asm { fsel      f5, f10, f9, f0 }
  this->m_xG.m_y = (float)v43 * (float)_FP5;
  this->m_xG.m_z = (float)v44 * (float)_FP5;
  this->m_xG.m_x = (float)_FP5 * (float)v45;
  this->m_oG.m_x = m_x;
  this->m_oG.m_y = m_y;
  this->m_oG.m_z = m_z;
  this->m_xU.m_y = (float)v32 * (float)_FP11;
  this->m_xU.m_z = (float)v35 * (float)_FP11;
  this->m_xU.m_x = (float)v37 * (float)_FP11;
  this->m_yU.m_z = (float)((float)((float)v32 * (float)_FP11) * (float)0.0)
                 - (float)((float)((float)v37 * (float)_FP11) * (float)0.0);
  this->m_yU.m_x = (float)((float)((float)v35 * (float)_FP11) * (float)0.0) - (float)((float)v32 * (float)_FP11);
  this->m_yU.m_y = (float)((float)v37 * (float)_FP11) - (float)((float)((float)v35 * (float)_FP11) * (float)0.0);
  this->m_oU.m_x = v36;
  this->m_oU.m_y = v31;
  this->m_oU.m_z = v33;
}


// ========================================================================
// ?GetUnwrapSection@bfx@@YA_NABV?$Array@PAVArea@bfx@@@1@HHAAH1@Z
// EA  : 0x832DCC00
// RVA : 0x012DCC00
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxunwrap.cpp
// ========================================================================

BOOL __fastcall bfx::GetUnwrapSection(
        const bfx::Array<bfx::Area *> *areas,
        int origStartIndex,
        int origEndIndex,
        int *numBefore,
        int *numAfter)
{
  BOOL v9; // r21
  int v10; // r25
  int v11; // r27
  int v12; // r26
  int v13; // r24
  signed int v14; // r31
  int v15; // r23

  v9 = origStartIndex == origEndIndex;
  *numBefore = 0;
  *numAfter = 0;
  v10 = origStartIndex;
  v11 = origStartIndex;
  v12 = origStartIndex;
  v13 = origStartIndex;
  v14 = 24 * (areas->m_data[origStartIndex]->m_flags.m_flags1 & 0x7F) + 56;
  while ( 1 )
  {
    v15 = *numBefore + *numAfter + 1;
    if ( v10 != 0
      && *numBefore < 5
      && bfx::GetSharedEdgeIdx(pArea0: areas->m_data[v12 - 1], pArea1: areas->m_data[v12]) >= 0 )
    {
      break;
    }
LABEL_8:
    if ( v13 != origEndIndex
      && *numAfter < 9
      && bfx::GetSharedEdgeIdx(pArea0: areas->m_data[v11], pArea1: areas->m_data[v11 + 1]) >= 0 )
    {
      if ( *numBefore + *numAfter + 1 >= 15 )
        return v9;
      ++v11;
      ++v13;
      v14 += 24 * (areas->m_data[v11]->m_flags.m_flags1 & 0x7F) + 56;
      if ( v14 > 3000 )
        return v9;
      if ( v13 == origEndIndex )
        v9 = true;
      ++*numAfter;
    }
    if ( *numBefore + *numAfter + 1 == v15 )
      return v9;
  }
  if ( *numBefore + *numAfter + 1 < 15 )
  {
    --v12;
    --v10;
    v14 += 24 * (areas->m_data[v12]->m_flags.m_flags1 & 0x7F) + 56;
    if ( v14 <= 3000 )
    {
      ++*numBefore;
      goto LABEL_8;
    }
  }
  return v9;
}


// ========================================================================
// ?BuildUnwrappedArea@bfx@@YAPAVArea@1@PAV21@000ABVUnwrapper@1@AAPAD@Z
// EA  : 0x832DCDB8
// RVA : 0x012DCDB8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxunwrap.cpp
// ========================================================================

bfx::Area *__fastcall bfx::BuildUnwrappedArea(
        bfx::Area *pInputArea,
        bfx::Area *pPrevInputArea,
        bfx::Area *pPrevOutputArea,
        bfx::Area *pNextInputArea,
        bfx::Vec3 *unwrapper,
        float **pEnd)
{
  float m_y; // r8
  float m_z; // r7
  char *v15; // r23
  bfx::Area *v16; // r10
  unsigned int v17; // r9
  bool v18; // r6
  bfx::Area *v19; // r8
  bfx::Area *v20; // r10
  float v21; // r7
  float v22; // r6
  int v23; // r10
  int v24; // r9
  float *v25; // r11
  bfx::Area *m_pArea; // r6
  float m_x; // r5
  int v28; // r4
  float v29; // r3
  int v31; // [sp+8h] [-E8h]
  int v32; // [sp+Ch] [-E4h]
  int v33; // [sp+10h] [-E0h]
  int v34; // [sp+14h] [-DCh]
  int v35; // [sp+18h] [-D8h]
  int v36; // [sp+1Ch] [-D4h]
  int v37; // [sp+20h] [-D0h]
  int v38; // [sp+24h] [-CCh]
  int v39; // [sp+28h] [-C8h]
  int v40; // [sp+2Ch] [-C4h]
  int v41; // [sp+30h] [-C0h]
  int v42; // [sp+34h] [-BCh]
  int v43; // [sp+38h] [-B8h]
  int v44; // [sp+3Ch] [-B4h]
  int v45; // [sp+40h] [-B0h]
  int v46; // [sp+44h] [-ACh]
  int v47; // [sp+48h] [-A8h]
  int v48; // [sp+4Ch] [-A4h]
  int v49; // [sp+50h] [-A0h]
  int v50; // [sp+58h] [-98h]
  bfx::Vec3 v51; // [sp+68h] [-88h] BYREF
  bfx::Unwrapper v52; // [sp+78h] [-78h] BYREF

  m_y = pInputArea->m_pos.m_y;
  m_z = pInputArea->m_pos.m_z;
  v51.m_x = pInputArea->m_pos.m_x;
  v51.m_y = m_y;
  v51.m_z = m_z;
  v15 = (char *)&(*pEnd)[2 * (pInputArea->m_flags.m_flags1 & 0x7F)
                       + 14
                       + 2 * ((2 * pInputArea->m_flags.m_flags1) & 0xFE)];
  bfx::Unwrapper::Transform(this: (bfx::Unwrapper *)&v52.m_yG, result: unwrapper, pos: &v51);
  if ( v16 != nullptr )
    v19 = bfx::Area::Area(
            this: v16,
            pos: &v52.m_yG,
            radius: pInputArea->m_radius,
            numEdges: pInputArea->m_usageFlags,
            full3D: v18,
            island: (pInputArea->m_flags.m_flags3 & 0x80000000) != 0,
            layerIndex: (v17 >> 7) & 0x1FFFF,
            graphIndex: pInputArea->m_flags.m_flags4 >> 27,
            usageFlags: HIWORD(pInputArea->m_flags.m_flags3) & 0x7FF,
            basisVert: v31,
            a11: v32,
            a12: v33,
            a13: v34,
            a14: v35,
            a15: v36,
            a16: v37,
            a17: v38,
            a18: v39,
            a19: v40,
            a20: v41,
            a21: v42,
            a22: v43,
            a23: v44,
            a24: v45,
            a25: v46,
            a26: v47,
            a27: v48,
            a28: v49,
            a29: pInputArea->m_usageFlags,
            a30: v50,
            a31: HIBYTE(pInputArea->m_flags.m_flags2) & 0x7F);
  else
    v19 = nullptr;
  *pEnd += 14;
  if ( (pInputArea->m_flags.m_flags1 & 0x7F) != 0 )
  {
    v20 = pInputArea + 1;
    do
    {
      v21 = *(float *)&v20->m_pFirstLink;
      v22 = *(float *)&v20->m_pSearchParent;
      LODWORD(v51.m_x) = v20->m_dynAreaData.m_data;
      v51.m_y = v21;
      v51.m_z = v22;
      bfx::Unwrapper::Transform(this: &v52, result: unwrapper, pos: &v51);
      v25 = *pEnd;
      if ( *pEnd != nullptr )
      {
        m_pArea = v52.m_pArea;
        m_x = v52.m_xG.m_x;
        v28 = *(_DWORD *)(v23 + 16) & 0xFFF;
        v29 = v52.m_xG.m_y;
        *v25 = 0.0;
        v25[5] = 0.0;
        *((_DWORD *)v25 + 1) = m_pArea;
        v25[2] = m_x;
        v25[3] = v29;
        *((_DWORD *)v25 + 4) = v28 | 0xFFFF0000;
      }
      else
      {
        v25 = nullptr;
      }
      if ( pPrevInputArea != nullptr && *(bfx::Area **)v23 == pPrevInputArea )
        *(_DWORD *)v25 = pPrevOutputArea;
      if ( pNextInputArea != nullptr && *(bfx::Area **)v23 == pNextInputArea )
        *(_DWORD *)v25 = v15;
      v20 = (bfx::Area *)(v23 + 24);
      *pEnd += 6;
    }
    while ( v24 + 1 < (signed int)(pInputArea->m_flags.m_flags1 & 0x7F) );
  }
  return v19;
}


// ========================================================================
// __unwind$16952
// EA  : 0x832DCF78
// RVA : 0x012DCF78
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxunwrap.cpp
// ========================================================================

void _unwind_16952()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 240 + 96));
}


// ========================================================================
// ?UnwrapSection@bfx@@YAXABV?$Array@PAVArea@bfx@@@1@AAV21@PADPAVMatrix@1@@Z
// EA  : 0x832DCFB0
// RVA : 0x012DCFB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxunwrap.cpp
// ========================================================================

void __fastcall bfx::UnwrapSection(
        const bfx::Array<bfx::Area *> *inputAreas,
        bfx::Array<bfx::Space *> *unwrappedAreas,
        float *pOutputBuf,
        bfx::Matrix *u2gArray)
{
  bfx::Area *v7; // r5
  int m_size; // r24
  int v9; // r31
  int v10; // r25
  int v11; // r26
  bfx::Area **v12; // r11
  bfx::Area *v13; // r28
  bfx::Area *v14; // r4
  bfx::Area *v15; // r30
  bfx::Space *v16; // r29
  bfx::Unwrapper *MatU2G; // r3
  float *v18; // [sp+50h] [-100h] BYREF
  bfx::Area *v19; // [sp+54h] [-FCh] BYREF
  bfx::EdgeCursor v20; // [sp+58h] [-F8h] BYREF
  bfx::Unwrapper v21; // [sp+60h] [-F0h] BYREF
  bfx::Unwrapper v22[2]; // [sp+B0h] [-A0h] BYREF

  if ( inputAreas->m_size != 0 )
  {
    v18 = pOutputBuf;
    bfx::Unwrapper::Unwrapper(this: &v21, pArea: *inputAreas->m_data);
    v7 = nullptr;
    m_size = inputAreas->m_size;
    v9 = 0;
    if ( m_size > 0 )
    {
      v10 = m_size - 1;
      v11 = 0;
      do
      {
        v12 = &inputAreas->m_data[v11];
        v13 = *v12;
        if ( v9 <= 0 )
          v14 = nullptr;
        else
          v14 = *(v12 - 1);
        if ( v9 >= v10 )
          v15 = nullptr;
        else
          v15 = v12[1];
        v19 = bfx::BuildUnwrappedArea(
                pInputArea: *v12,
                pPrevInputArea: v14,
                pPrevOutputArea: v7,
                pNextInputArea: v15,
                unwrapper: (bfx::Vec3 *)&v21,
                pEnd: &v18);
        v16 = (bfx::Space *)v19;
        bfx::Array<bfx::Portal *>::push_back(this: unwrappedAreas, val: (bfx::Space **)&v19);
        MatU2G = bfx::Unwrapper::GetMatU2G(this: v22, result: (bfx::Matrix *)&v21);
        memcpy(Dst: u2gArray, Src: MatU2G, Size: sizeof(bfx::Matrix));
        if ( v9 < v10 )
        {
          bfx::GetSharedEdgeCC(result: &v20, pArea0: v13, pArea1: v15);
          bfx::Unwrapper::CrossEdge(this: &v21, cc: &v20);
        }
        ++v9;
        v7 = (bfx::Area *)v16;
        ++v11;
        ++u2gArray;
      }
      while ( v9 < m_size );
    }
  }
}


// ========================================================================
// ?Init@UPath@bfx@@AAAXABV?$Array@PAVArea@bfx@@@2@HH@Z
// EA  : 0x832DD0C0
// RVA : 0x012DD0C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxunwrap.cpp
// ========================================================================

void __fastcall bfx::UPath::Init(bfx::UPath *this, const bfx::Array<bfx::Area *> *areas, int startIndex, int endIndex)
{
  bool UnwrapSection; // r3
  bfx::Space *v8; // r25
  char *v9; // r28
  int v10; // r11
  int v11; // r30
  char *i; // r31
  bfx::Matrix *m_g2u; // r31
  char *j; // r30
  bfx::Space *k; // ctr
  int v16; // [sp+50h] [-90h] BYREF
  bfx::Space *v17[3]; // [sp+54h] [-8Ch] BYREF
  bfx::Matrix v18[2]; // [sp+60h] [-80h] BYREF

  UnwrapSection = bfx::GetUnwrapSection(
                    areas,
                    origStartIndex: startIndex,
                    origEndIndex: endIndex,
                    numBefore: (int *)v17,
                    numAfter: &v16);
  v8 = v17[0];
  v9 = (char *)&v17[0]->__vftable + v16 + 1;
  v10 = startIndex - (unsigned int)v17[0];
  this->m_unwrappedPath.m_partial = (_cntlzw(UnwrapSection) & 0x20) != 0;
  if ( (int)v9 > 0 )
  {
    v11 = v10;
    for ( i = v9; i != nullptr; --i )
    {
      v17[0] = (bfx::Space *)areas->m_data[v11];
      bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_origPath.m_areas, val: v17);
      ++v11;
    }
  }
  bfx::UnwrapSection(
    inputAreas: &this->m_origPath.m_areas,
    unwrappedAreas: (bfx::Array<bfx::Space *> *)&this->m_unwrappedPath.m_areas,
    pOutputBuf: (float *)this->m_pBuf,
    u2gArray: this->m_u2g);
  if ( (int)v9 > 0 )
  {
    m_g2u = this->m_g2u;
    for ( j = v9; j != nullptr; --j )
    {
      memcpy(Dst: v18, Src: &m_g2u[-15], Size: 0x40u);
      bfx::Matrix::OrthoInvert(this: v18);
      memcpy(Dst: m_g2u++, Src: v18, Size: sizeof(bfx::Matrix));
    }
  }
  this->m_curIdx = (int)v8;
  this->m_curCC.m_pPath = &this->m_unwrappedPath;
  this->m_curCC.m_i = 0;
  if ( (int)v8 > 0 )
  {
    for ( k = v8; k != nullptr; k = (bfx::Space *)((char *)k - 1) )
      ++this->m_curCC.m_i;
  }
}


// ========================================================================
// ??0UPath@bfx@@QAA@ABV?$Array@PAVArea@bfx@@@1@HH@Z
// EA  : 0x832DD1E8
// RVA : 0x012DD1E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxunwrap.cpp
// ========================================================================

bfx::UPath *__fastcall bfx::UPath::UPath(
        bfx::UPath *this,
        const bfx::Array<bfx::Area *> *areas,
        int startIndex,
        int endIndex)
{
  bfx::bfxMemTag v5; // r9
  bfx::bfxMemTag v6; // r9

  this->m_unwrappedPath.__vftable = (bfx::Path_vtbl *)&bfx::Path::`vftable';
  v5 = bfx::MEM_PATH;
  this->m_unwrappedPath.m_areas.m_data = nullptr;
  this->m_unwrappedPath.m_areas.m_size = 0;
  this->m_unwrappedPath.m_areas.m_cap = 0;
  this->m_unwrappedPath.m_areas.m_tag = v5;
  this->m_unwrappedPath.m_partial = false;
  this->m_origPath.__vftable = (bfx::Path_vtbl *)&bfx::Path::`vftable';
  v6 = bfx::MEM_PATH;
  this->m_origPath.m_areas.m_data = nullptr;
  this->m_origPath.m_areas.m_size = 0;
  this->m_origPath.m_areas.m_cap = 0;
  this->m_origPath.m_areas.m_tag = v6;
  this->m_origPath.m_partial = false;
  this->m_curCC.m_pPath = nullptr;
  this->m_curCC.m_i = -1;
  bfx::UPath::Init(this, areas, startIndex, endIndex);
  return this;
}


// ========================================================================
// __unwind$17459
// EA  : 0x832DD2A0
// RVA : 0x012DD2A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxunwrap.cpp
// ========================================================================

void _unwind_17459()
{
  int v0; // r12

  bfx::Path::~Path(this: (bfx::Path *)(*(_DWORD *)(v0 - 112 + 132) + 3000));
}


// ========================================================================
// __unwind$17460
// EA  : 0x832DD2CC
// RVA : 0x012DD2CC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxunwrap.cpp
// ========================================================================

void _unwind_17460()
{
  int v0; // r12

  bfx::Path::~Path(this: (bfx::Path *)(*(_DWORD *)(v0 - 112 + 132) + 3024));
}


// ========================================================================
// ??1UPath@bfx@@QAA@XZ
// EA  : 0x832DD300
// RVA : 0x012DD300
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxunwrap.cpp
// ========================================================================

void __fastcall bfx::UPath::~UPath(bfx::UPath *this)
{
  bfx::Path *p_m_origPath; // r29
  char *m_data; // r4
  char *v4; // r4

  p_m_origPath = &this->m_origPath;
  this->m_origPath.__vftable = (bfx::Path_vtbl *)&bfx::Path::`vftable';
  m_data = (char *)this->m_origPath.m_areas.m_data;
  this->m_origPath.m_areas.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    p_m_origPath->m_areas.m_data = nullptr;
  }
  p_m_origPath->m_areas.m_cap = 0;
  this->m_unwrappedPath.__vftable = (bfx::Path_vtbl *)&bfx::Path::`vftable';
  v4 = (char *)this->m_unwrappedPath.m_areas.m_data;
  this->m_unwrappedPath.m_areas.m_size = 0;
  if ( v4 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v4);
    this->m_unwrappedPath.m_areas.m_data = nullptr;
  }
  this->m_unwrappedPath.m_areas.m_cap = 0;
}


// ========================================================================
// __unwind$17539
// EA  : 0x832DD388
// RVA : 0x012DD388
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxunwrap.cpp
// ========================================================================

void _unwind_17539()
{
  int v0; // r12

  bfx::Path::~Path(this: (bfx::Path *)(*(_DWORD *)(v0 - 144 + 164) + 3000));
}

