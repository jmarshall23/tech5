
// ========================================================================
// ?R_DrawBounds@@YAXABVidBounds@@@Z
// EA  : 0x8296FE20
// RVA : 0x0096FE20
// PDB : w:\tech5\engine\renderer\render_tools_d3d_360.cpp
// ========================================================================

void __fastcall R_DrawBounds(const idBounds *bounds)
{
  float *v2; // r3
  float *v3; // r11
  double z; // fp0
  double y; // fp13
  double v6; // fp11
  double v7; // fp10
  double v8; // fp8
  double v9; // fp7
  double v10; // fp5
  double v11; // fp4
  double v12; // fp2
  double v13; // fp1
  double v14; // fp13
  double v15; // fp12
  double v16; // fp10
  double v17; // fp9
  double v18; // fp7
  double v19; // fp6
  double v20; // fp4
  double v21; // fp3
  double v22; // fp1
  double v23; // fp0
  double v24; // fp12
  double v25; // fp11
  double v26; // fp9
  double v27; // fp8
  double v28; // fp6
  double v29; // fp5
  double v30; // fp3
  double v31; // fp2
  D3DDevice *v32; // r3
  double v33; // fp0
  double v34; // fp13
  double v35; // fp11
  double x; // fp9
  double v37; // fp8
  double v38; // fp7
  double v39; // fp5
  double v40; // fp4
  double v41; // fp2
  double v42; // fp1
  double v43; // fp13
  double v44; // fp11
  double v45; // fp10
  double v46; // fp8
  double v47; // fp7
  double v48; // fp5
  double v49; // fp4
  double v50; // fp3
  double v51; // fp1
  double v52; // fp0

  if ( bounds->b[0].x <= (double)bounds->b[1].x )
  {
    v2 = (float *)D3DDevice_BeginVertices(
                    pDevice: d3d,
                    PrimitiveType: D3DPT_LINELIST,
                    VertexCount: 0x18u,
                    VertexStreamZeroStride: 0x20u);
    v3 = v2;
    if ( v2 != nullptr )
    {
      z = bounds->b[0].z;
      y = bounds->b[0].y;
      *v2 = bounds->b[0].x;
      v2[1] = y;
      v2[2] = z;
      v6 = bounds->b[0].z;
      v7 = bounds->b[1].y;
      v2[8] = bounds->b[0].x;
      v2[9] = v7;
      v2[10] = v6;
      v8 = bounds->b[0].z;
      v9 = bounds->b[1].y;
      v2[16] = bounds->b[0].x;
      v2[17] = v9;
      v2[18] = v8;
      v10 = bounds->b[0].z;
      v11 = bounds->b[1].y;
      v2[24] = bounds->b[1].x;
      v2[25] = v11;
      v2[26] = v10;
      v12 = bounds->b[0].z;
      v13 = bounds->b[1].y;
      v2[32] = bounds->b[1].x;
      v2[33] = v13;
      v2[34] = v12;
      v14 = bounds->b[0].z;
      v15 = bounds->b[0].y;
      v2[40] = bounds->b[1].x;
      v2[41] = v15;
      v2[42] = v14;
      v16 = bounds->b[0].z;
      v17 = bounds->b[0].y;
      v2[48] = bounds->b[1].x;
      v2[49] = v17;
      v2[50] = v16;
      v18 = bounds->b[0].z;
      v19 = bounds->b[0].y;
      v2[56] = bounds->b[0].x;
      v2[57] = v19;
      v2[58] = v18;
      v20 = bounds->b[1].z;
      v21 = bounds->b[0].y;
      v2[64] = bounds->b[0].x;
      v2[65] = v21;
      v2[66] = v20;
      v22 = bounds->b[1].z;
      v23 = bounds->b[1].y;
      v2[72] = bounds->b[0].x;
      v2[73] = v23;
      v2[74] = v22;
      v24 = bounds->b[1].z;
      v25 = bounds->b[1].y;
      v2[80] = bounds->b[0].x;
      v2[81] = v25;
      v2[82] = v24;
      v26 = bounds->b[1].z;
      v27 = bounds->b[1].y;
      v2[88] = bounds->b[1].x;
      v2[89] = v27;
      v2[90] = v26;
      v28 = bounds->b[1].z;
      v29 = bounds->b[1].y;
      v2[96] = bounds->b[1].x;
      v2[97] = v29;
      v2[98] = v28;
      v30 = bounds->b[1].z;
      v31 = bounds->b[0].y;
      v2[104] = bounds->b[1].x;
      v32 = d3d;
      v3[105] = v31;
      v3[106] = v30;
      v33 = bounds->b[1].z;
      v34 = bounds->b[0].y;
      v3[112] = bounds->b[1].x;
      v3[113] = v34;
      v3[114] = v33;
      v35 = bounds->b[1].z;
      x = bounds->b[0].x;
      v3[121] = bounds->b[0].y;
      v3[120] = x;
      v3[122] = v35;
      v37 = bounds->b[0].z;
      v38 = bounds->b[0].y;
      v3[128] = bounds->b[0].x;
      v3[129] = v38;
      v3[130] = v37;
      v39 = bounds->b[1].z;
      v40 = bounds->b[0].y;
      v3[136] = bounds->b[0].x;
      v3[137] = v40;
      v3[138] = v39;
      v41 = bounds->b[0].z;
      v42 = bounds->b[1].y;
      v3[144] = bounds->b[0].x;
      v3[145] = v42;
      v3[146] = v41;
      v43 = bounds->b[1].z;
      v44 = bounds->b[1].y;
      v3[152] = bounds->b[0].x;
      v3[153] = v44;
      v3[154] = v43;
      v45 = bounds->b[0].z;
      v46 = bounds->b[0].y;
      v3[160] = bounds->b[1].x;
      v3[161] = v46;
      v3[162] = v45;
      v47 = bounds->b[1].z;
      v48 = bounds->b[0].y;
      v3[168] = bounds->b[1].x;
      v3[169] = v48;
      v3[170] = v47;
      v49 = bounds->b[0].z;
      v50 = bounds->b[1].y;
      v3[176] = bounds->b[1].x;
      v3[177] = v50;
      v3[178] = v49;
      v51 = bounds->b[1].z;
      v52 = bounds->b[1].y;
      v3[184] = bounds->b[1].x;
      v3[185] = v52;
      v3[186] = v51;
      D3DDevice_EndVertices(pDevice: v32);
    }
  }
}


// ========================================================================
// ?InternalDrawText@idRender@@AAAXPBDABVidVec3@@MABVidVec4@@ABVidMat3@@H@Z
// EA  : 0x829700E0
// RVA : 0x009700E0
// PDB : w:\tech5\engine\renderer\render_tools_d3d_360.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRender::InternalDrawText(
        idRender *this,
        const char *text,
        const idVec3 *origin,
        double scale,
        const idVec4 *color,
        const idVec4 *viewAxis,
        float *align,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        idRender *a13,
        int a14,
        int a15,
        int a16,
        const idVec3 *a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25)
{
  idRender *v26; // r30
  const idVec3 *v28; // r29
  int v32; // r27
  unsigned int v33; // r5
  int v34; // r6
  int i; // r7
  unsigned int v36; // r10
  int v37; // r8
  int v38; // r11
  unsigned int v39; // r9
  int v40; // r10
  int v41; // r28
  char *v42; // r20
  __int64 v43; // r6 OVERLAPPED
  int v45; // r22
  int v46; // r16
  int v47; // r19
  double v48; // fp28
  __int64 v49; // r11 OVERLAPPED
  double v50; // fp29
  double v51; // fp30
  const char *v52; // r21
  int v53; // r18
  const char *v55; // r11
  double v56; // fp1
  bool v57; // cr58
  int v58; // r24
  int v59; // r30
  double v60; // fp24
  int v61; // r27
  int v63; // r29
  const int *v64; // r9
  double v65; // fp0
  int v66; // r7
  double v67; // fp12
  double v68; // fp13
  double v69; // fp27
  double v70; // fp26
  double v71; // fp25
  const int *v72; // r9
  int v73; // r7
  double v74; // fp20
  double v75; // fp19
  double v76; // fp18
  unsigned int v77; // r3
  unsigned int v80; // r3
  float v82; // [sp+78h] [-138h]
  float v83; // [sp+7Ch] [-134h]
  float v84; // [sp+80h] [-130h]

  _R12 = -288;
  __asm { stvx128   v127, r1, r12 }
  v26 = this;
  a13 = this;
  a17 = origin;
  v28 = origin;
  a25 = a8;
  v32 = a8;
  if ( text != nullptr && *text != 0 )
  {
    v33 = 0;
    v34 = 0;
    do
      ++v34;
    while ( text[v34] != 0 );
    for ( i = 0; i < v34; ++i )
    {
      v36 = text[i] - 32;
      if ( v36 < 0x60 )
      {
        v37 = 2 * simplex_0[v36][0];
        v38 = 2;
        if ( v37 > 0 )
        {
          v39 = v36;
          v40 = 0;
          do
          {
            if ( simplex_0[v39][v38] >= 0 )
            {
              v38 += 2;
              v40 += 2;
              if ( simplex_0[v39][v38] >= 0 )
              {
                v33 += 2;
              }
              else
              {
                ++v38;
                ++v40;
              }
            }
            else
            {
              ++v38;
              ++v40;
            }
          }
          while ( v40 < v37 );
        }
      }
    }
    v41 = 0;
    v42 = (char *)D3DDevice_BeginVertices(
                    pDevice: d3d,
                    PrimitiveType: D3DPT_LINELIST,
                    VertexCount: v33,
                    VertexStreamZeroStride: 0x20u);
    if ( v42 != nullptr )
    {
      v45 = 0;
      v46 = (_cntlzw(*text - 10) & 0x20) != 0;
      if ( *text != 0 )
      {
        do
          ++v45;
        while ( text[v45] != 0 );
      }
      v47 = 0;
      if ( v45 > 0 )
      {
        v48 = v84;
        HIDWORD(v49) = 0x82000000;
        v50 = v83;
        v51 = v82;
        v52 = text;
        v53 = 1 - (_DWORD)text;
        _R23 = 16;
        do
        {
          if ( v47 == 0 || *v52 == 10 )
          {
            LODWORD(v49) = v46;
            v51 = (float)(v28->x - (float)((float)((float)((float)v49 * (float)scale) * (float)36.0) * align[6]));
            v50 = (float)(v28->y - (float)(align[7] * (float)((float)((float)v49 * (float)scale) * (float)36.0)));
            v48 = (float)(v28->z - (float)(align[8] * (float)((float)((float)v49 * (float)scale) * (float)36.0)));
            if ( v32 != 0 )
            {
              v55 = &v52[v53];
              v56 = 0.0;
              LODWORD(v43) = 1;
              if ( (int)&v52[v53] <= v45 )
              {
                v57 = v55 == (const char *)v45;
                while ( !v57 && v52[v43] != 10 )
                {
                  ++v55;
                  LODWORD(v43) = v43 + 1;
                  v57 = v55 == (const char *)v45;
                  if ( (int)v55 > v45 )
                    goto LABEL_31;
                }
                v56 = idRenderWorldLocal::DrawTextLength(
                        this: (idRenderWorldLocal *)v26->world,
                        text: v52,
                        scale,
                        len: SHIDWORD(v43),
                        a5: v43);
              }
LABEL_31:
              if ( v32 == 2 )
              {
                v48 = (float)((float)(align[5] * (float)v56) + (float)v48);
                v51 = (float)((float)(align[3] * (float)v56) + (float)v51);
                v50 = (float)((float)(align[4] * (float)v56) + (float)v50);
              }
              else
              {
                v51 = (float)((float)(align[3] * (float)((float)v56 * (float)0.5)) + (float)v51);
                v50 = (float)((float)(align[4] * (float)((float)v56 * (float)0.5)) + (float)v50);
                v48 = (float)((float)(align[5] * (float)((float)v56 * (float)0.5)) + (float)v48);
              }
            }
            ++v46;
          }
          HIDWORD(v49) = *v52;
          LODWORD(v49) = HIDWORD(v49) - 32;
          if ( HIDWORD(v49) - 32 >= 0 )
          {
            HIDWORD(v49) = 448 * v49;
            v58 = 2 * simplex_0[v49][0];
            v59 = 2;
            LODWORD(v43) = simplex_0[v49][1];
            v60 = (float)v43;
            if ( v58 > 0 )
            {
              v61 = 112 * v49;
              _R31 = (float *)&v42[32 * v41];
              v63 = 0;
              do
              {
                LODWORD(v49) = 4 * (v61 + v59);
                HIDWORD(v49) = *(const int *)((char *)simplex_0[0] + v49);
                if ( v49 >= 0 )
                {
                  v64 = &simplex_0[0][1];
                  v65 = -align[3];
                  v59 += 2;
                  v66 = *(const int *)((char *)&simplex_0[0][1] + v49);
                  v67 = -align[5];
                  v68 = -align[4];
                  v63 += 2;
                  LODWORD(v49) = 4 * (v61 + v59);
                  v69 = (float)((float)((float)((float)v65
                                              * (float)((float)*(__int64 *)((char *)&v49 + 4) * (float)scale))
                                      + (float)v51)
                              + (float)(align[6] * (float)((float)*(__int64 *)((char *)&v43 - 4) * (float)scale)));
                  v70 = (float)((float)((float)((float)v68
                                              * (float)((float)*(__int64 *)((char *)&v49 + 4) * (float)scale))
                                      + (float)v50)
                              + (float)(align[7] * (float)((float)*(__int64 *)((char *)&v43 - 4) * (float)scale)));
                  v71 = (float)((float)((float)((float)v67
                                              * (float)((float)*(__int64 *)((char *)&v49 + 4) * (float)scale))
                                      + (float)v48)
                              + (float)(align[8] * (float)((float)*(__int64 *)((char *)&v43 - 4) * (float)scale)));
                  HIDWORD(v49) = *(const int *)((char *)simplex_0[0] + v49);
                  LODWORD(v43) = v61 + v59;
                  if ( v49 >= 0 )
                  {
                    __asm { vspltisw128 v127, 0 }
                    v72 = &simplex_0[0][1];
                    __asm { vmr128    v63, v127 }
                    v73 = *(const int *)((char *)&simplex_0[0][1] + v49);
                    __asm { vcmpequw128 v62, v95, v63 }
                    __asm { vsldoi128 v61, v95, v62, 4 }
                    __asm
                    {
                      stvx128   v63, r0, r31
                      stvx128   v61, r31, r23
                    }
                    v74 = (float)((float)((float)((float)v65
                                                * (float)((float)*(__int64 *)((char *)&v49 + 4) * (float)scale))
                                        + (float)v51)
                                + (float)(align[6] * (float)((float)*(__int64 *)((char *)&v43 - 4) * (float)scale)));
                    v75 = (float)((float)((float)((float)v68
                                                * (float)((float)*(__int64 *)((char *)&v49 + 4) * (float)scale))
                                        + (float)v50)
                                + (float)(align[7] * (float)((float)*(__int64 *)((char *)&v43 - 4) * (float)scale)));
                    v76 = (float)((float)((float)((float)v67
                                                * (float)((float)*(__int64 *)((char *)&v49 + 4) * (float)scale))
                                        + (float)v48)
                                + (float)(align[8] * (float)((float)*(__int64 *)((char *)&v43 - 4) * (float)scale)));
                    v77 = idColor::PackColor(color: viewAxis);
                    __asm { vcmpequw128 v60, v127, v127 }
                    *((_BYTE *)_R31 + 28) = v77;
                    *((_BYTE *)_R31 + 31) = HIBYTE(v77);
                    *((_BYTE *)_R31 + 30) = BYTE1(v77);
                    __asm { vsldoi128 v59, v127, v60, 4 }
                    *((_BYTE *)_R31 + 29) = BYTE2(v77);
                    *_R31 = v69;
                    _R31[1] = v70;
                    _R31[2] = v71;
                    _R31 = (char *)(_R31 + 8);
                    __asm
                    {
                      stvx128   v127, r0, r31
                      stvx128   v59, r31, r23
                    }
                    v80 = idColor::PackColor(color: viewAxis);
                    _R31[28] = v80;
                    _R31[31] = HIBYTE(v80);
                    _R31[30] = BYTE1(v80);
                    v41 += 2;
                    _R31[29] = BYTE2(v80);
                    *(float *)_R31 = v74;
                    *((float *)_R31 + 1) = v75;
                    *((float *)_R31 + 2) = v76;
                    _R31 = (float *)(_R31 + 32);
                  }
                  else
                  {
                    ++v59;
                    ++v63;
                  }
                }
                else
                {
                  ++v59;
                  ++v63;
                }
              }
              while ( v63 < v58 );
              v28 = a17;
              v32 = a25;
            }
            v26 = a13;
            v51 = (float)((float)v51 - (float)(align[3] * (float)((float)v60 * (float)scale)));
            v50 = (float)((float)v50 - (float)(align[4] * (float)((float)v60 * (float)scale)));
            v48 = (float)((float)v48 - (float)(align[5] * (float)((float)v60 * (float)scale)));
          }
          ++v47;
          ++v52;
        }
        while ( v47 < v45 );
      }
      D3DDevice_EndVertices(pDevice: d3d);
    }
  }
  _R0 = -288;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// ?ShowDebugText@idRender@@AAAXXZ
// EA  : 0x82970648
// RVA : 0x00970648
// PDB : w:\tech5\engine\renderer\render_tools_d3d_360.cpp
// ========================================================================

void __fastcall idRender::ShowDebugText(idRender *this)
{
  const idRenderWorldLocal **p_world; // r26
  bool v3; // r5
  const idVec4 *v4; // r6
  bool v5; // r5
  int num; // r10
  int v7; // r30
  debugText_t *list; // r31
  idMat3 *p_viewaxis; // r8
  int v10; // [sp+8h] [-88h]
  int v11; // [sp+Ch] [-84h]
  int v12; // [sp+10h] [-80h]
  idRender *v13; // [sp+14h] [-7Ch]
  int v14; // [sp+18h] [-78h]
  int v15; // [sp+1Ch] [-74h]
  int v16; // [sp+20h] [-70h]
  const idVec3 *v17; // [sp+24h] [-6Ch]
  int v18; // [sp+28h] [-68h]
  int v19; // [sp+2Ch] [-64h]
  int v20; // [sp+30h] [-60h]
  int v21; // [sp+34h] [-5Ch]
  int v22; // [sp+38h] [-58h]
  int v23; // [sp+3Ch] [-54h]
  int v24; // [sp+40h] [-50h]
  int v25; // [sp+44h] [-4Ch]

  p_world = &this->world;
  if ( this->world->latchedDebugText.num != 0 )
  {
    idImageManager::BindNull(this: globalImages);
    GL_State(stateBits: 0x80000000000uLL, forceGlState: v3);
    if ( r_debugLineDepthTest.valueInteger == 0 )
      D3DDevice_SetRenderState_ZEnable(pDevice: d3d, Value: 0);
    num = 0x20000;
    v7 = 0;
    list = (*p_world)->latchedDebugText.list;
    if ( (*p_world)->latchedDebugText.num > 0 )
    {
      do
      {
        if ( list->orientToRenderViewAxis )
          p_viewaxis = &this->renderViewObject->r.viewaxis;
        else
          p_viewaxis = &list->viewAxis;
        idRender::InternalDrawText(
          this,
          text: list->text,
          origin: &list->origin,
          scale: list->scale,
          color: v4,
          viewAxis: &list->color,
          align: (float *)p_viewaxis,
          a8: list->align,
          a9: num,
          a10: v10,
          a11: v11,
          a12: v12,
          a13: v13,
          a14: v14,
          a15: v15,
          a16: v16,
          a17: v17,
          a18: v18,
          a19: v19,
          a20: v20,
          a21: v21,
          a22: v22,
          a23: v23,
          a24: v24,
          a25: v25);
        ++v7;
        ++list;
        num = (*p_world)->latchedDebugText.num;
      }
      while ( v7 < num );
    }
    GL_State(stateBits: 0x400000000000uLL, forceGlState: v5);
  }
}


// ========================================================================
// ?ShowDebugLines@idRender@@AAAXXZ
// EA  : 0x82970740
// RVA : 0x00970740
// PDB : w:\tech5\engine\renderer\render_tools_d3d_360.cpp
// ========================================================================

void __fastcall idRender::ShowDebugLines(idRender *this)
{
  const idRenderWorldLocal **p_world; // r25
  bool v3; // r5
  signed int v5; // r5
  bool *p_depthTest; // r10
  int num; // ctr
  float *v8; // r3
  int v10; // r27
  const idVec4 *p_rgb; // r29
  float *p_z; // r30
  unsigned int v14; // r3
  unsigned int v17; // r3
  int v18; // r5
  bool *v19; // r10
  int v20; // ctr
  float *v21; // r3
  int v23; // r27
  const idVec4 *v24; // r29
  float *v26; // r30
  unsigned int v27; // r3
  unsigned int v30; // r3

  _R12 = -112;
  __asm { stvx128   v127, r1, r12 }
  p_world = &this->world;
  if ( this->world->latchedDebugLines.num != 0 )
  {
    idImageManager::BindNull(this: globalImages);
    GL_State(stateBits: 0x80000000000uLL, forceGlState: v3);
    if ( r_debugLineDepthTest.valueInteger == 0 )
      D3DDevice_SetRenderState_ZEnable(pDevice: d3d, Value: 0);
    _R24 = 16;
    v5 = 0;
    if ( (*p_world)->latchedDebugLines.num > 0 )
    {
      p_depthTest = &(*p_world)->latchedDebugLines.list->depthTest;
      num = (*p_world)->latchedDebugLines.num;
      do
      {
        if ( !*p_depthTest )
          v5 += 2;
        p_depthTest += 48;
        --num;
      }
      while ( num != 0 );
      if ( v5 > 0 )
      {
        v8 = (float *)D3DDevice_BeginVertices(
                        pDevice: d3d,
                        PrimitiveType: D3DPT_LINELIST,
                        VertexCount: v5,
                        VertexStreamZeroStride: 0x20u);
        if ( v8 == nullptr )
          goto LABEL_33;
        v10 = 0;
        p_rgb = &(*p_world)->latchedDebugLines.list->rgb;
        if ( (*p_world)->latchedDebugLines.num > 0 )
        {
          _R31 = v8;
          p_z = &p_rgb[1].z;
          do
          {
            if ( *((_BYTE *)p_z + 16) == 0 )
            {
              __asm { vspltisw128 v127, 0 }
              __asm
              {
                vmr128    v63, v127
                vcmpequw128 v62, v95, v63
                stvx128   v63, r0, r31
                vsldoi128 v61, v95, v62, 4
                stvx128   v61, r31, r24
              }
              *_R31 = *(p_z - 2);
              _R31[1] = *(p_z - 1);
              _R31[2] = *p_z;
              v14 = idColor::PackColor(color: p_rgb);
              __asm { vcmpequw128 v60, v127, v127 }
              *((_BYTE *)_R31 + 28) = v14;
              *((_BYTE *)_R31 + 31) = HIBYTE(v14);
              *((_BYTE *)_R31 + 30) = BYTE1(v14);
              __asm { vsldoi128 v59, v127, v60, 4 }
              *((_BYTE *)_R31 + 29) = BYTE2(v14);
              _R31 = _R31 + 8;
              __asm
              {
                stvx128   v127, r0, r31
                stvx128   v59, r31, r24
              }
              *_R31 = p_z[1];
              _R31[1] = p_z[2];
              _R31[2] = p_z[3];
              v17 = idColor::PackColor(color: p_rgb);
              *((_BYTE *)_R31 + 28) = v17;
              *((_BYTE *)_R31 + 31) = HIBYTE(v17);
              *((_BYTE *)_R31 + 30) = BYTE1(v17);
              *((_BYTE *)_R31 + 29) = BYTE2(v17);
              _R31 = _R31 + 8;
            }
            ++v10;
            p_rgb += 3;
            p_z += 12;
          }
          while ( v10 < (*p_world)->latchedDebugLines.num );
        }
        D3DDevice_EndVertices(pDevice: d3d);
      }
    }
    if ( r_debugLineDepthTest.valueInteger == 0 )
      D3DDevice_SetRenderState_ZEnable(pDevice: d3d, Value: 1u);
    v18 = 0;
    if ( (*p_world)->latchedDebugLines.num <= 0 )
      goto LABEL_32;
    v19 = &(*p_world)->latchedDebugLines.list->depthTest;
    v20 = (*p_world)->latchedDebugLines.num;
    do
    {
      if ( *v19 )
        v18 += 2;
      v19 += 48;
      --v20;
    }
    while ( v20 != 0 );
    if ( v18 <= 0 )
      goto LABEL_32;
    v21 = (float *)D3DDevice_BeginVertices(
                     pDevice: d3d,
                     PrimitiveType: D3DPT_LINELIST,
                     VertexCount: v18,
                     VertexStreamZeroStride: 0x20u);
    if ( v21 != nullptr )
    {
      v23 = 0;
      v24 = &(*p_world)->latchedDebugLines.list->rgb;
      if ( (*p_world)->latchedDebugLines.num > 0 )
      {
        _R31 = v21;
        v26 = &v24[1].z;
        do
        {
          if ( *((_BYTE *)v26 + 16) != 0 )
          {
            __asm { vspltisw128 v127, 0 }
            __asm
            {
              vmr128    v58, v127
              stvx128   v58, r0, r31
              vcmpequw128 v57, v90, v58
              vsldoi128 v56, v90, v57, 4
              stvx128   v56, r31, r24
            }
            *_R31 = *(v26 - 2);
            _R31[1] = *(v26 - 1);
            _R31[2] = *v26;
            v27 = idColor::PackColor(color: v24);
            __asm { vcmpequw128 v55, v127, v127 }
            *((_BYTE *)_R31 + 28) = v27;
            *((_BYTE *)_R31 + 31) = HIBYTE(v27);
            *((_BYTE *)_R31 + 30) = BYTE1(v27);
            __asm { vsldoi128 v54, v127, v55, 4 }
            *((_BYTE *)_R31 + 29) = BYTE2(v27);
            _R31 = _R31 + 8;
            __asm
            {
              stvx128   v127, r0, r31
              stvx128   v54, r31, r24
            }
            *_R31 = v26[1];
            _R31[1] = v26[2];
            _R31[2] = v26[3];
            v30 = idColor::PackColor(color: v24);
            *((_BYTE *)_R31 + 28) = v30;
            *((_BYTE *)_R31 + 31) = HIBYTE(v30);
            *((_BYTE *)_R31 + 30) = BYTE1(v30);
            *((_BYTE *)_R31 + 29) = BYTE2(v30);
            _R31 = _R31 + 8;
          }
          ++v23;
          v24 += 3;
          v26 += 12;
        }
        while ( v23 < (*p_world)->latchedDebugLines.num );
      }
      D3DDevice_EndVertices(pDevice: d3d);
LABEL_32:
      GL_State(stateBits: 0x400000000000uLL, forceGlState: v18);
    }
  }
LABEL_33:
  _R0 = -112;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// ?ShowDebugPolygons@idRender@@AAAXXZ
// EA  : 0x82970AA0
// RVA : 0x00970AA0
// PDB : w:\tech5\engine\renderer\render_tools_d3d_360.cpp
// ========================================================================

void __fastcall idRender::ShowDebugPolygons(idRender *this)
{
  const idRenderWorldLocal **p_world; // r24
  bool v4; // r5
  int v5; // r11
  unsigned __int64 v6; // r4
  bool v7; // r3
  bool v8; // r3
  int v9; // r27
  debugPolygon_t *list; // r30
  char *v11; // r3
  int v13; // r28
  int v14; // r29
  float *v15; // r31
  float *p_x; // r10
  unsigned int v19; // r3
  bool v20; // r5

  _R12 = -112;
  __asm { stvx128   v126, r1, r12 }
  _R12 = -96;
  __asm { stvx128   v127, r1, r12 }
  p_world = &this->world;
  if ( this->world->latchedDebugPolygons.num != 0 )
  {
    idImageManager::BindNull(this: globalImages);
    D3DDevice_SetRenderState_StencilEnable(pDevice: d3d, Value: 0);
    D3DDevice_SetRenderState_ZEnable(pDevice: d3d, Value: 0);
    v5 = 0;
    if ( r_debugPolyDepthTest.valueInteger == 0 )
      v5 = 0x4000;
    LODWORD(v6) = 0;
    HIDWORD(v6) = v5 | 0x42C;
    if ( r_debugPolygonFilled.valueInteger == 0 )
      HIDWORD(v6) = v5 | 0xC00;
    GL_State(stateBits: v6, forceGlState: v4);
    GL_PolygonOffset(scale: 1.0, bias: 2.0, fill: v7);
    v9 = 0;
    list = (*p_world)->latchedDebugPolygons.list;
    if ( (*p_world)->latchedDebugPolygons.num <= 0 )
    {
LABEL_12:
      GL_PolygonOffset(scale: 0.0, bias: 0.0, fill: v8);
      GL_State(stateBits: 0x400000000000uLL, forceGlState: v20);
    }
    else
    {
      while ( 1 )
      {
        v11 = (char *)D3DDevice_BeginVertices(
                        pDevice: d3d,
                        PrimitiveType: D3DPT_TRIANGLEFAN,
                        VertexCount: list->winding.numPoints,
                        VertexStreamZeroStride: 0x20u);
        if ( v11 == nullptr )
          break;
        v13 = 0;
        if ( list->winding.numPoints > 0 )
        {
          __asm { vspltisw128 v127, 0 }
          v14 = 0;
          v15 = (float *)(v11 + 8);
          _R10 = 16;
          __asm
          {
            vcmpequw128 v63, v127, v127
            vsldoi128 v126, v127, v63, 4
          }
          do
          {
            _R11 = (char *)(v15 - 2);
            __asm
            {
              stvx128   v127, r0, r11
              stvx128   v126, r11, r10
            }
            p_x = &list->winding.p[v14].x;
            *(v15 - 2) = *p_x;
            *(v15 - 1) = p_x[1];
            *v15 = p_x[2];
            v19 = idColor::PackColor(color: &list->rgb);
            *((_BYTE *)v15 + 22) = BYTE1(v19);
            *((_BYTE *)v15 + 23) = HIBYTE(v19);
            ++v13;
            *((_BYTE *)v15 + 21) = BYTE2(v19);
            *((_BYTE *)v15 + 20) = v19;
            ++v14;
            v15 += 8;
            _R10 = 16;
          }
          while ( v13 < list->winding.numPoints );
        }
        D3DDevice_EndVertices(pDevice: d3d);
        ++v9;
        ++list;
        if ( v9 >= (*p_world)->latchedDebugPolygons.num )
          goto LABEL_12;
      }
    }
  }
  _R0 = -112;
  __asm { lvx128    v126, r1, r0 }
  _R0 = -96;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// ?ShowTestCubeImage@idRender@@AAAXXZ
// EA  : 0x82970C90
// RVA : 0x00970C90
// PDB : w:\tech5\engine\renderer\render_tools_d3d_360.cpp
// ========================================================================

void __fastcall idRender::ShowTestCubeImage(idRender *this)
{
  idImage *testCubeImage; // r29
  const idDecl *v6; // r3
  idDeclRenderProg *v7; // r31
  unsigned int v8; // r7
  unsigned __int64 v9; // r6
  long double v10; // fp2
  int v11; // r7
  idRenderView *renderViewObject; // r3
  float z; // r9
  float x; // r8
  float v15; // r5
  double v16; // fp28
  double v18; // fp20
  double v19; // fp27
  __int64 v21; // r11
  double v29; // fp26
  double v30; // fp25
  long double v31; // fp2
  double v32; // fp30
  long double v33; // fp2
  double v34; // fp26
  long double v35; // fp2
  double v36; // fp29
  long double v37; // fp2
  double v38; // fp25
  char *v39; // r3
  long double v41; // fp2
  double v43; // fp26
  int v44; // r30
  double v45; // fp25
  double v47; // fp19
  long double v48; // fp2
  double v49; // fp18
  double v55; // fp12
  bool v56; // r5
  int v60; // [sp+50h] [-160h]
  float v61; // [sp+54h] [-15Ch] BYREF
  float v62; // [sp+58h] [-158h] BYREF
  float v63; // [sp+5Ch] [-154h] BYREF
  idParmState **v64; // [sp+60h] [-150h]
  const idParmBlock *v65; // [sp+64h] [-14Ch]
  __int64 v66; // [sp+68h] [-148h]
  float v67; // [sp+70h] [-140h]
  __int64 v68; // [sp+78h] [-138h]
  float v69; // [sp+80h] [-130h]

  _R12 = -288;
  __asm { stvx128   v125, r1, r12 }
  _R12 = -272;
  __asm { stvx128   v126, r1, r12 }
  _R12 = -256;
  __asm { stvx128   v127, r1, r12 }
  testCubeImage = tr.testCubeImage;
  if ( tr.testCubeImage != nullptr && tr.testCubeImage->opts.textureType == TT_CUBIC )
  {
    GL_SetDefaultState();
    idRender::SimpleWorldSetup(this);
    idDeclRenderParm::Set(this: rp->Color, x: 1.0, y: 1.0, z: 1.0, w: 1.0);
    v6 = idDeclInfo::FindWithInheritance(
           this: &idDeclRenderProg::resourceList,
           name: "cubeImageOnly",
           makeDefault: true);
    v65 = (const idParmBlock *)((char *)&v6[1].idResource + 32);
    v7 = (idDeclRenderProg *)v6;
    v64 = &renderThreadParmState;
    idParmState::VirtualEvaluateParmBlock(
      this: renderThreadParmState,
      localParmBlock: (const idParmBlock *)((char *)&v6[1].idResource + 32),
      parmBlock: (const idParmBlock *)((char *)&v6[1].idResource + 32));
    idDeclRenderProg::BindForImmediate(this: v7, a2: -2147466176, extraState: v9, a4: v8);
    idDeclRenderProg::BindTexture(image: testCubeImage, texUnit: 0);
    v11 = 0;
    v60 = 0;
    renderViewObject = this->renderViewObject;
    z = renderViewObject->r.vieworg.z;
    x = renderViewObject->r.vieworg.x;
    LODWORD(v21) = LODWORD(renderViewObject->r.viewaxis.mat[0].x);
    LODWORD(v66) = LODWORD(renderViewObject->r.viewaxis.mat[0].y);
    v69 = z;
    *(float *)&v68 = x;
    v15 = renderViewObject->r.viewaxis.mat[0].z;
    LODWORD(v68) = LODWORD(renderViewObject->r.vieworg.y);
    HIDWORD(v66) = v21;
    v67 = v15;
    v16 = (float)((float)(*((float *)&v21 + 1) * (float)125.0) + x);
    _R29 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
    v18 = (float)(*((float *)&v68 + 1) + (float)(*((float *)&v66 + 1) * (float)125.0));
    v19 = (float)((float)(z + (float)(v15 * (float)125.0)) + (float)4.0);
    _R28 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
    HIDWORD(v21) = &unk_82390000;
    _R27 = &_vmx_3f8000003f8000003f8000003f800000;
    _R26 = 16;
    _R20 = -2;
    _R21 = -1;
    _R22 = 30;
    _R23 = 31;
    _R24 = 32;
    while ( 1 )
    {
      LODWORD(v21) = v11;
      v29 = (float)((float)((float)((float)v21 * (float)0.01010101) * 3.1415927) - (float)(3.1415927 * (float)0.5));
      *(double *)&v10 = v29;
      v30 = (float)((float)((float)((float)((float)v21 + (float)1.0) * (float)0.01010101) * 3.1415927)
                  - (float)(3.1415927 * (float)0.5));
      v66 = v21;
      v31 = cos(x: v10);
      v32 = (float)*(double *)&v31;
      *(double *)&v31 = v29;
      v33 = sin(x: v31);
      v34 = (float)*(double *)&v33;
      *(double *)&v33 = v30;
      v35 = cos(x: v33);
      v36 = (float)*(double *)&v35;
      *(double *)&v35 = v30;
      v37 = sin(x: v35);
      v38 = (float)*(double *)&v37;
      v39 = (char *)D3DDevice_BeginVertices(
                      pDevice: d3d,
                      PrimitiveType: D3DPT_TRIANGLESTRIP,
                      VertexCount: 0x190u,
                      VertexStreamZeroStride: 0x20u);
      if ( v39 == nullptr )
        break;
      LODWORD(_R11) = &v61;
      v61 = v34;
      HIDWORD(_R11) = &v62;
      v62 = v38;
      v43 = (float)((float)((float)v34 * (float)20.0) + (float)v18);
      v44 = 0;
      __asm { vspltisw128 v127, 0 }
      v45 = (float)((float)((float)v38 * (float)20.0) + (float)v18);
      _R31 = v39 + 22;
      __asm
      {
        lvlx128   v126, r0, r11
        lvlx128   v125, r0, r10
      }
      do
      {
        LODWORD(_R11) = v44;
        v47 = (float)((float)((float)_R11 * (float)0.0050251256) * idMath::TWO_PI);
        *(double *)&v41 = v47;
        v68 = _R11;
        v48 = cos(x: v41);
        v49 = (float)*(double *)&v48;
        *(double *)&v48 = v47;
        v41 = sin(x: v48);
        __asm { vmr128    v63, v127 }
        LODWORD(_R11) = _R31 - 22;
        _R9 = &v61;
        v62 = (float)v49 * (float)v32;
        _R8 = &v62;
        __asm
        {
          vmr128    v62, v127
          vcmpequw128 v61, v95, v63
        }
        HIDWORD(_R11) = _R31 + 10;
        __asm { vmr128    v60, v127 }
        _R7 = &v61;
        _R6 = &v63;
        __asm { vmr128    v59, v127 }
        ++v44;
        __asm
        {
          vsldoi128 v58, v95, v61, 4
          vcmpequw128 v57, v92, v60
        }
        __asm { vsldoi128 v56, v92, v57, 4 }
        __asm { stvx128   v63, r0, r11 }
        v55 = -(float)((float)*(double *)&v41 * (float)v36);
        __asm
        {
          stvx128   v58, r11, r26
          lvlx128   v55, r0, r9
          lvx128    v63, r0, r27
          lvx128    v13, r0, r29
          lvx128    v0, r0, r28
          lvlx128   v54, r0, r8
          vrlimi128 v62, v54, 8, 0
          vrlimi128 v62, v126, 4, 3
        }
        __asm
        {
          vrlimi128 v62, v55, 2, 2
          vaddfp128 v12, v94, v63
          vmaddfp   v0, v12, v0, v13
          vcfpsxws128 v53, v0, 0
          vpkswss128 v52, v85, v53
          vpkshus128 v0, v84, v52
          stvebx    v0, r31, r20
          stvebx    v0, r31, r21
          stvebx    v0, 0, r31
        }
        *(float *)(_R31 - 18) = v43;
        *(float *)(_R31 - 22) = (float)((float)((float)v49 * (float)v32) * (float)20.0) + (float)v16;
        *(float *)(_R31 - 14) = (float)((float)-(float)((float)*(double *)&v41 * (float)v32) * (float)20.0) + (float)v19;
        v61 = v55;
        v63 = (float)v49 * (float)v36;
        __asm
        {
          stvx128   v60, r0, r10
          stvx128   v56, r10, r26
          lvlx128   v51, r0, r7
          lvx128    v63, r0, r27
          lvx128    v0, r0, r28
          lvx128    v13, r0, r29
          lvlx128   v50, r0, r6
          vrlimi128 v59, v50, 8, 0
          vrlimi128 v59, v125, 4, 3
          vrlimi128 v59, v51, 2, 2
          vaddfp128 v12, v91, v63
          vmaddfp   v0, v12, v0, v13
          vcfpsxws128 v49, v0, 0
          vpkswss128 v48, v81, v49
          vpkshus128 v0, v80, v48
          stvebx    v0, r31, r22
          stvebx    v0, r31, r23
          stvebx    v0, r31, r24
        }
        *(float *)(_R31 + 14) = v45;
        *(float *)(_R31 + 18) = (float)((float)v55 * (float)20.0) + (float)v19;
        *(float *)(_R31 + 10) = (float)((float)((float)v49 * (float)v36) * (float)20.0) + (float)v16;
        _R31 += 64;
      }
      while ( v44 < 200 );
      D3DDevice_EndVertices(pDevice: d3d);
      v11 = ++v60;
      if ( v60 >= 99 )
      {
        GL_State(stateBits: 0x400000000000uLL, forceGlState: v56);
        idParmState::VirtualRollbackParmBlock(this: *v64, localParmBlock: v65, parmBlock: v65);
        break;
      }
    }
  }
  _R0 = -288;
  __asm { lvx128    v125, r1, r0 }
  _R0 = -272;
  __asm { lvx128    v126, r1, r0 }
  _R0 = -256;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// ?RenderDebugTools_NonPortable@idRender@@AAAXXZ
// EA  : 0x829710D0
// RVA : 0x009710D0
// PDB : w:\tech5\engine\renderer\render_tools_d3d_360.cpp
// ========================================================================

void __fastcall idRender::RenderDebugTools_NonPortable(idRender *this)
{
  unsigned int v2; // r7
  unsigned __int64 v3; // r6

  idRender::ShowTestCubeImage(this);
  idParmState::VirtualEvaluateParmBlock(
    this: renderThreadParmState,
    localParmBlock: &tr.progColorOnly->parmBlock,
    parmBlock: &tr.progColorOnly->parmBlock);
  idDeclRenderProg::BindForImmediate(this: tr.progColorOnly, a2: 0, extraState: v3, a4: v2);
  idRender::ShowDebugLines(this);
  idRender::ShowDebugPolygons(this);
  idRender::ShowDebugText(this);
  idParmState::VirtualRollbackParmBlock(
    this: renderThreadParmState,
    localParmBlock: &tr.progColorOnly->parmBlock,
    parmBlock: &tr.progColorOnly->parmBlock);
}

