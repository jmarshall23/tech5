
// ========================================================================
// ?CreateWedge@idPlaytestStorage@@AAAXPAVidTriangles@@AAH1VidVec3@@2M2@Z
// EA  : 0x8267B920
// RVA : 0x0067B920
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::CreateWedge(
        idPlaytestStorage *this,
        idTriangles *tris,
        int *vertexIndex,
        int *indexIndex,
        const idVec3 *loc,
        unsigned int dir,
        double width,
        unsigned int offset,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        float a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        float a37,
        float a38,
        float a39,
        float a40)
{
  double x; // fp10
  double y; // fp11
  double z; // fp12
  double v39; // fp3
  double v40; // fp3
  double v41; // fp13
  double v42; // fp12
  double v43; // fp11
  double v44; // fp13
  double v45; // fp4
  double v46; // fp2
  double v47; // fp3
  char v48; // r11
  idDrawVert *verts; // r11
  float *p_x; // r10
  double v51; // fp26
  double v52; // fp23
  idDrawVert *v53; // r10
  double v54; // fp28
  float *v55; // r10
  double v56; // fp2
  double v57; // fp12
  double v58; // fp11
  idDrawVert *v59; // r10
  float *v60; // r10
  idDrawVert *v61; // r10
  float *v62; // r10
  idDrawVert *v63; // r10
  float *v64; // r10
  idDrawVert *v65; // r11

  tris->indexes[*indexIndex] = *vertexIndex;
  tris->indexes[*indexIndex + 1] = *vertexIndex + 1;
  tris->indexes[*indexIndex + 2] = *vertexIndex + 2;
  tris->indexes[*indexIndex + 3] = *vertexIndex;
  tris->indexes[*indexIndex + 4] = *vertexIndex + 3;
  tris->indexes[*indexIndex + 5] = *(_WORD *)vertexIndex + 4;
  if ( ((dir | offset) & 0x7FFFFFFF) != 0 )
  {
    z = *(float *)&offset;
    y = *(float *)&offset;
    x = *(float *)&dir;
  }
  else
  {
    x = vec3_up.x;
    y = vec3_up.y;
    z = vec3_up.z;
  }
  _FP2 = (float)((float)((float)((float)x * (float)x)
                       + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f2, f3, f9 }
  v39 = __frsqrte(_FP4);
  v40 = (float)((float)-(float)((float)((float)((float)v39
                                              * (float)((float)((float)((float)x * (float)x)
                                                              + (float)((float)((float)z * (float)z)
                                                                      + (float)((float)y * (float)y)))
                                                      * (float)0.5))
                                      * (float)v39)
                              - (float)1.5)
              * (float)v39);
  v41 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v40
                                                                                      * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y)))
                                                                                              * (float)0.5))
                                                                              * (float)v40)
                                                                      - (float)1.5)
                                                      * (float)v40)
                                              * (float)((float)((float)((float)x * (float)x)
                                                              + (float)((float)((float)z * (float)z)
                                                                      + (float)((float)y * (float)y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v40
                                                                              * (float)((float)((float)((float)x * (float)x)
                                                                                              + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y)))
                                                                                      * (float)0.5))
                                                                      * (float)v40)
                                                              - (float)1.5)
                                              * (float)v40))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v40
                                                      * (float)((float)((float)((float)x * (float)x)
                                                                      + (float)((float)((float)z * (float)z)
                                                                              + (float)((float)y * (float)y)))
                                                              * (float)0.5))
                                              * (float)v40)
                                      - (float)1.5)
                      * (float)v40));
  v42 = (float)((float)z
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v40
                                                                                              * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5))
                                                                                      * (float)v40)
                                                                              - (float)1.5)
                                                              * (float)v40)
                                                      * (float)((float)((float)((float)x * (float)x)
                                                                      + (float)((float)((float)z * (float)z)
                                                                              + (float)((float)y * (float)y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v40
                                                                                      * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y)))
                                                                                              * (float)0.5))
                                                                              * (float)v40)
                                                                      - (float)1.5)
                                                      * (float)v40))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v40
                                                              * (float)((float)((float)((float)x * (float)x)
                                                                              + (float)((float)((float)z * (float)z)
                                                                                      + (float)((float)y * (float)y)))
                                                                      * (float)0.5))
                                                      * (float)v40)
                                              - (float)1.5)
                              * (float)v40)));
  v43 = (float)((float)y * (float)v41);
  v44 = (float)((float)v41 * (float)x);
  v45 = (float)((float)((float)v43 * vec3_up.z) - (float)((float)v42 * vec3_up.y));
  v46 = (float)((float)((float)v44 * vec3_up.y) - (float)((float)v43 * vec3_up.x));
  v47 = (float)((float)((float)v42 * vec3_up.x) - (float)((float)v44 * vec3_up.z));
  if ( (COERCE_UNSIGNED_INT(fabs((float)((float)v42 * vec3_up.x) - (float)((float)v44 * vec3_up.z)))
      | COERCE_UNSIGNED_INT(fabs((float)((float)v44 * vec3_up.y) - (float)((float)v43 * vec3_up.x)))
      | COERCE_UNSIGNED_INT(fabs((float)((float)v43 * vec3_up.z) - (float)((float)v42 * vec3_up.y)))) == 0 )
    goto LABEL_10;
  if ( v45 != v44 || v47 != v43 || (v48 = 1, v46 != v42) )
    v48 = 0;
  if ( v48 != 0 )
  {
LABEL_10:
    v45 = (float)((float)((float)v43 * (float)0.0) - (float)v42);
    v47 = (float)((float)((float)v42 * (float)0.0) - (float)((float)v44 * (float)0.0));
    v46 = (float)((float)v44 - (float)((float)v43 * (float)0.0));
  }
  verts = tris->verts;
  p_x = &verts[*vertexIndex].xyz.x;
  v51 = (float)((float)v46 * (float)width);
  v52 = (float)((float)v46 * (float)v44);
  *p_x = (float)(*(float *)&dir + *(float *)&indexIndex) + a38;
  p_x[1] = a39 + (float)(*(float *)&loc + *(float *)&offset);
  p_x[2] = a40 + (float)(*(float *)&loc + *(float *)&offset);
  v53 = &verts[*vertexIndex];
  v54 = (float)((float)((float)v46 * (float)width) + *(float *)&loc);
  v53->st.x = 0.5;
  v53->st.y = 1.0;
  v55 = &verts[*vertexIndex + 1].xyz.x;
  v56 = (float)((float)((float)((float)v46 * (float)v43) - (float)((float)v47 * (float)v42)) * (float)width);
  v57 = (float)((float)((float)((float)v42 * (float)v45) - (float)v52) * (float)width);
  v58 = (float)((float)((float)((float)v47 * (float)v44) - (float)((float)v43 * (float)v45)) * (float)width);
  v55[2] = (float)v54 + a40;
  *v55 = (float)((float)((float)v45 * (float)width) + *(float *)&indexIndex) + a38;
  v55[1] = (float)((float)((float)v47 * (float)width) + *(float *)&loc) + a39;
  v59 = &verts[*vertexIndex];
  v59[1].st.x = 0.0;
  v59[1].st.y = 0.0;
  v60 = &verts[*vertexIndex + 2].xyz.x;
  *v60 = (float)(*(float *)&indexIndex - (float)((float)v45 * (float)width)) + a38;
  v60[1] = (float)(*(float *)&loc - (float)((float)v47 * (float)width)) + a39;
  v60[2] = (float)(*(float *)&loc - (float)v51) + a40;
  v61 = &verts[*vertexIndex];
  v61[2].st.x = 1.0;
  v61[2].st.y = 0.0;
  v62 = &verts[*vertexIndex + 3].xyz.x;
  v62[1] = (float)((float)v57 + *(float *)&loc) + a39;
  *v62 = (float)((float)v56 + *(float *)&indexIndex) + a38;
  v62[2] = (float)((float)v58 + *(float *)&loc) + a40;
  v63 = &verts[*vertexIndex];
  v63[3].st.x = 0.0;
  v63[3].st.y = 0.0;
  v64 = &verts[*vertexIndex + 4].xyz.x;
  v64[2] = (float)(*(float *)&loc - (float)v58) + a40;
  v64[1] = (float)(*(float *)&loc - (float)v57) + a39;
  *v64 = (float)(*(float *)&indexIndex - (float)v56) + a38;
  v65 = &verts[*vertexIndex];
  v65[4].st.x = 1.0;
  v65[4].st.y = 0.0;
  *vertexIndex += 5;
  *indexIndex += 6;
}


// ========================================================================
// ?CreateBlockWedge@idPlaytestStorage@@AAAXPAVidTriangles@@AAH1VidVec3@@2M2@Z
// EA  : 0x8267BD28
// RVA : 0x0067BD28
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::CreateBlockWedge(
        idPlaytestStorage *this,
        idTriangles *tris,
        int *vertexIndex,
        int *indexIndex,
        const idVec3 *loc,
        __int64 offset,
        double width,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        float a15,
        float a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        float a37,
        float a38,
        float a39)
{
  double x; // fp10
  double y; // fp11
  double z; // fp12
  double v38; // fp9
  double v39; // fp9
  double v40; // fp2
  double v41; // fp9
  double v42; // fp6
  double v43; // fp5
  double v44; // fp4
  double v45; // fp13
  double v46; // fp12
  double v47; // fp2
  double v48; // fp3
  double v49; // fp31
  char v50; // r11
  idDrawVert *verts; // r11
  float *p_x; // r10
  idDrawVert *v53; // r10
  float *v54; // r10
  double v55; // fp22
  idDrawVert *v56; // r10
  float *v57; // r10
  idDrawVert *v58; // r10
  double v59; // fp4
  double v60; // fp2
  double v61; // fp3
  float *v62; // r9
  idDrawVert *v63; // r10
  idDrawVert *v64; // r9
  float *v65; // r11
  idDrawVert *v66; // r11
  float *v67; // r11
  idDrawVert *v68; // r11
  float *v69; // r11
  idDrawVert *v70; // r11
  float *v71; // r11
  idDrawVert *v72; // r11
  float v73; // [sp+4h] [-9Ch]
  float v75; // [sp+E8h] [+48h]

  v75 = *((float *)&offset + 1);
  tris->indexes[*indexIndex] = *vertexIndex;
  tris->indexes[*indexIndex + 1] = *vertexIndex + 1;
  tris->indexes[*indexIndex + 2] = *vertexIndex + 2;
  tris->indexes[*indexIndex + 3] = *vertexIndex + 1;
  tris->indexes[*indexIndex + 4] = *vertexIndex + 3;
  tris->indexes[*indexIndex + 5] = *vertexIndex + 2;
  tris->indexes[*indexIndex + 6] = *vertexIndex + 4;
  tris->indexes[*indexIndex + 7] = *vertexIndex + 5;
  tris->indexes[*indexIndex + 8] = *vertexIndex + 6;
  tris->indexes[*indexIndex + 9] = *vertexIndex + 4;
  tris->indexes[*indexIndex + 10] = *vertexIndex + 7;
  tris->indexes[*indexIndex + 11] = *(_WORD *)vertexIndex + 6;
  if ( ((HIDWORD(offset) | (unsigned int)offset) & 0x7FFFFFFF) != 0 )
  {
    z = *((float *)&offset + 1);
    y = *((float *)&offset + 1);
    x = *(float *)&offset;
  }
  else
  {
    x = vec3_up.x;
    y = vec3_up.y;
    z = vec3_up.z;
  }
  _FP5 = (float)((float)((float)((float)y * (float)y)
                       + (float)((float)((float)x * (float)x) + (float)((float)z * (float)z)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f5, f2, f9 }
  v38 = __frsqrte(_FP2);
  v39 = (float)((float)-(float)((float)((float)((float)v38
                                              * (float)((float)((float)((float)y * (float)y)
                                                              + (float)((float)((float)x * (float)x)
                                                                      + (float)((float)z * (float)z)))
                                                      * (float)0.5))
                                      * (float)v38)
                              - (float)1.5)
              * (float)v38);
  v40 = (float)((float)-(float)((float)((float)((float)v39
                                              * (float)((float)((float)((float)y * (float)y)
                                                              + (float)((float)((float)x * (float)x)
                                                                      + (float)((float)z * (float)z)))
                                                      * (float)0.5))
                                      * (float)v39)
                              - (float)1.5)
              * (float)v39);
  v41 = (float)((float)((float)-(float)((float)((float)((float)v39
                                                      * (float)((float)((float)((float)y * (float)y)
                                                                      + (float)((float)((float)x * (float)x)
                                                                              + (float)((float)z * (float)z)))
                                                              * (float)0.5))
                                              * (float)v39)
                                      - (float)1.5)
                      * (float)v39)
              * (float)((float)((float)((float)y * (float)y)
                              + (float)((float)((float)x * (float)x) + (float)((float)z * (float)z)))
                      * (float)0.5));
  v42 = (float)((float)((float)-(float)((float)((float)v41 * (float)v40) - (float)1.5) * (float)v40) * (float)x);
  v43 = (float)((float)z * (float)((float)-(float)((float)((float)v41 * (float)v40) - (float)1.5) * (float)v40));
  v44 = (float)((float)y * (float)((float)-(float)((float)((float)v41 * (float)v40) - (float)1.5) * (float)v40));
  v45 = (float)((float)((float)z * (float)((float)-(float)((float)((float)v41 * (float)v40) - (float)1.5) * (float)v40))
              * vec3_up.y);
  v46 = (float)((float)((float)y * (float)((float)-(float)((float)((float)v41 * (float)v40) - (float)1.5) * (float)v40))
              * vec3_up.x);
  v47 = (float)((float)((float)v43 * vec3_up.x)
              - (float)((float)((float)((float)-(float)((float)((float)v41 * (float)v40) - (float)1.5) * (float)v40)
                              * (float)x)
                      * vec3_up.z));
  v73 = v47;
  v48 = (float)((float)((float)v44 * vec3_up.z) - (float)v45);
  v49 = (float)((float)((float)v42 * vec3_up.y) - (float)v46);
  if ( (LODWORD(v73) & 0x7FFFFFFF
      | COERCE_UNSIGNED_INT(fabs((float)((float)v42 * vec3_up.y) - (float)v46))
      | COERCE_UNSIGNED_INT(fabs((float)((float)v44 * vec3_up.z) - (float)v45))) == 0 )
    goto LABEL_10;
  if ( v48 != v42 || v47 != v44 || (v50 = 1, v49 != v43) )
    v50 = 0;
  if ( v50 != 0 )
  {
LABEL_10:
    v48 = (float)((float)((float)v44 * (float)0.0) - (float)v43);
    v47 = (float)((float)((float)v43 * (float)0.0) - (float)((float)v42 * (float)0.0));
    v49 = (float)((float)v42 - (float)((float)v44 * (float)0.0));
  }
  verts = tris->verts;
  p_x = &verts[*vertexIndex].xyz.x;
  p_x[1] = a38 + (float)(*(float *)&loc + (float)((float)v47 * (float)width));
  *p_x = (float)((float)((float)v48 * (float)width) + *(float *)&indexIndex) + a37;
  p_x[2] = a39 + (float)(*(float *)&loc + (float)((float)v49 * (float)width));
  v53 = &verts[*vertexIndex];
  v53->st.x = 0.0;
  v53->st.y = 0.0;
  v54 = &verts[*vertexIndex + 1].xyz.x;
  v54[1] = *((float *)&offset + 1) + (float)((float)(*(float *)&loc + (float)((float)v47 * (float)width)) + a38);
  v54[2] = *((float *)&offset + 1) + (float)((float)(*(float *)&loc + (float)((float)v49 * (float)width)) + a39);
  *v54 = (float)((float)((float)((float)v48 * (float)width) + *(float *)&indexIndex) + a37) + *(float *)&offset;
  v55 = (float)((float)v44 * (float)v48);
  v56 = &verts[*vertexIndex];
  v56[1].st.x = 0.0;
  v56[1].st.y = 1.0;
  v57 = &verts[*vertexIndex + 2].xyz.x;
  *v57 = (float)(*(float *)&indexIndex - (float)((float)v48 * (float)width)) + a37;
  v57[1] = (float)(*(float *)&loc - (float)((float)v47 * (float)width)) + a38;
  v57[2] = (float)(*(float *)&loc - (float)((float)v49 * (float)width)) + a39;
  v58 = &verts[*vertexIndex];
  v58[2].st.x = 1.0;
  v58[2].st.y = 0.0;
  v59 = (float)((float)((float)v49 * (float)v44) - (float)((float)v47 * (float)v43));
  v62 = &verts[*vertexIndex + 3].xyz.x;
  v63 = verts;
  v62[1] = (float)((float)(*(float *)&loc - (float)((float)v47 * (float)width)) + a38) + *((float *)&offset + 1);
  v60 = (float)((float)((float)v47 * (float)v42) - (float)v55);
  *v62 = (float)((float)(*(float *)&indexIndex - (float)((float)v48 * (float)width)) + a37) + *(float *)&offset;
  v61 = (float)((float)((float)v43 * (float)v48) - (float)((float)v49 * (float)v42));
  v62[2] = (float)((float)(*(float *)&loc - (float)((float)v49 * (float)width)) + a39) + v75;
  v64 = &verts[*vertexIndex];
  v64[3].st.y = 1.0;
  v64[3].st.x = 1.0;
  v65 = &verts[*vertexIndex + 4].xyz.x;
  v65[1] = (float)((float)((float)v61 * (float)width) + *(float *)&loc) + a38;
  *v65 = (float)((float)((float)v59 * (float)width) + *(float *)&indexIndex) + a37;
  v65[2] = (float)((float)((float)v60 * (float)width) + *(float *)&loc) + a39;
  v66 = &v63[*vertexIndex];
  v66[4].st.x = 0.0;
  v66[4].st.y = 0.0;
  v67 = &v63[*vertexIndex + 5].xyz.x;
  *v67 = (float)((float)((float)((float)v59 * (float)width) + *(float *)&indexIndex) + a37) + *(float *)&offset;
  v67[1] = (float)((float)((float)((float)v61 * (float)width) + *(float *)&loc) + a38) + *((float *)&offset + 1);
  v67[2] = (float)((float)((float)((float)v60 * (float)width) + *(float *)&loc) + a39) + v75;
  v68 = &v63[*vertexIndex];
  v68[5].st.y = 1.0;
  v68[5].st.x = 0.0;
  v69 = &v63[*vertexIndex + 6].xyz.x;
  v69[1] = (float)(*(float *)&loc - (float)((float)v61 * (float)width)) + a38;
  *v69 = (float)(*(float *)&indexIndex - (float)((float)v59 * (float)width)) + a37;
  v69[2] = (float)(*(float *)&loc - (float)((float)v60 * (float)width)) + a39;
  v70 = &v63[*vertexIndex];
  v70[6].st.x = 1.0;
  v70[6].st.y = 0.0;
  v71 = &v63[*vertexIndex + 7].xyz.x;
  *v71 = (float)((float)(*(float *)&indexIndex - (float)((float)v59 * (float)width)) + a37) + *(float *)&offset;
  v71[2] = (float)((float)(*(float *)&loc - (float)((float)v60 * (float)width)) + a39) + v75;
  v71[1] = (float)((float)(*(float *)&loc - (float)((float)v61 * (float)width)) + a38) + *((float *)&offset + 1);
  v72 = &v63[*vertexIndex];
  v72[7].st.y = 1.0;
  v72[7].st.x = 1.0;
  *vertexIndex += 8;
  *indexIndex += 12;
}


// ========================================================================
// ?CreateTriangle@idPlaytestStorage@@AAAXPAVidTriangles@@AAH1VidVec3@@2M2@Z
// EA  : 0x8267C2E0
// RVA : 0x0067C2E0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::CreateTriangle(
        idPlaytestStorage *this,
        idTriangles *tris,
        int *vertexIndex,
        int *indexIndex,
        const idVec3 *loc,
        unsigned int dir,
        double width,
        unsigned int offset,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        float a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        float a37,
        float a38,
        float a39,
        float a40)
{
  double x; // fp10
  double y; // fp11
  double z; // fp12
  double v39; // fp9
  double v40; // fp5
  double v41; // fp13
  double v42; // fp11
  double v43; // fp12
  double v44; // fp13
  double v45; // fp5
  double v46; // fp7
  double v47; // fp6
  char v48; // r11
  double v49; // fp11
  idDrawVert *verts; // r11
  float *p_x; // r10
  double v52; // fp6
  double v53; // fp5
  idDrawVert *v54; // r10
  float *v55; // r10
  idDrawVert *v56; // r10
  float *v57; // r10
  idDrawVert *v58; // r11

  tris->indexes[*indexIndex] = *vertexIndex;
  tris->indexes[*indexIndex + 1] = *vertexIndex + 1;
  tris->indexes[*indexIndex + 2] = *(_WORD *)vertexIndex + 2;
  if ( ((dir | offset) & 0x7FFFFFFF) != 0 )
  {
    z = *(float *)&offset;
    y = *(float *)&offset;
    x = *(float *)&dir;
  }
  else
  {
    x = vec3_up.x;
    y = vec3_up.y;
    z = vec3_up.z;
  }
  _FP5 = (float)((float)((float)((float)x * (float)x)
                       + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f5, f2, f9 }
  v39 = __frsqrte(_FP2);
  v40 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v39
                                                                                      * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y)))
                                                                                              * (float)0.5))
                                                                              * (float)v39)
                                                                      - (float)1.5)
                                                      * (float)v39)
                                              * (float)((float)((float)((float)x * (float)x)
                                                              + (float)((float)((float)z * (float)z)
                                                                      + (float)((float)y * (float)y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v39
                                                                              * (float)((float)((float)((float)x * (float)x)
                                                                                              + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y)))
                                                                                      * (float)0.5))
                                                                      * (float)v39)
                                                              - (float)1.5)
                                              * (float)v39))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v39
                                                      * (float)((float)((float)((float)x * (float)x)
                                                                      + (float)((float)((float)z * (float)z)
                                                                              + (float)((float)y * (float)y)))
                                                              * (float)0.5))
                                              * (float)v39)
                                      - (float)1.5)
                      * (float)v39));
  v41 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5)) * (float)v39) - (float)1.5)
                                                                                              * (float)v39)
                                                                                      * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5)) * (float)v39) - (float)1.5)
                                                                                      * (float)v39))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v39
                                                                                              * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5))
                                                                                      * (float)v39)
                                                                              - (float)1.5)
                                                              * (float)v39))
                                              * (float)((float)((float)((float)x * (float)x)
                                                              + (float)((float)((float)z * (float)z)
                                                                      + (float)((float)y * (float)y)))
                                                      * (float)0.5))
                                      * (float)v40)
                              - (float)1.5)
              * (float)v40);
  v42 = (float)((float)y
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5)) * (float)v39) - (float)1.5) * (float)v39)
                                                                                              * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5)) * (float)v39) - (float)1.5)
                                                                                              * (float)v39))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) * (float)0.5))
                                                                                              * (float)v39)
                                                                                      - (float)1.5)
                                                                      * (float)v39))
                                                      * (float)((float)((float)((float)x * (float)x)
                                                                      + (float)((float)((float)z * (float)z)
                                                                              + (float)((float)y * (float)y)))
                                                              * (float)0.5))
                                              * (float)v40)
                                      - (float)1.5)
                      * (float)v40));
  v43 = (float)((float)z * (float)v41);
  v44 = (float)((float)v41 * (float)x);
  v45 = (float)((float)(vec3_up.y * (float)v44) - (float)((float)v42 * vec3_up.x));
  v46 = (float)((float)((float)v42 * vec3_up.z) - (float)((float)v43 * vec3_up.y));
  v47 = (float)((float)((float)v43 * vec3_up.x) - (float)(vec3_up.z * (float)v44));
  if ( (COERCE_UNSIGNED_INT(fabs((float)((float)v43 * vec3_up.x) - (float)(vec3_up.z * (float)v44)))
      | COERCE_UNSIGNED_INT(fabs((float)(vec3_up.y * (float)v44) - (float)((float)v42 * vec3_up.x)))
      | COERCE_UNSIGNED_INT(fabs((float)((float)v42 * vec3_up.z) - (float)((float)v43 * vec3_up.y)))) == 0 )
    goto LABEL_10;
  if ( v46 != v44 || v47 != v42 || (v48 = 1, v45 != v43) )
    v48 = 0;
  if ( v48 != 0 )
  {
LABEL_10:
    v49 = (float)((float)v42 * (float)0.0);
    v46 = (float)((float)v49 - (float)v43);
    v47 = (float)((float)((float)v43 * (float)0.0) - (float)((float)v44 * (float)0.0));
    v45 = (float)((float)v44 - (float)v49);
  }
  verts = tris->verts;
  p_x = &verts[*vertexIndex].xyz.x;
  v52 = (float)((float)v47 * (float)width);
  v53 = (float)((float)v45 * (float)width);
  *p_x = (float)(*(float *)&dir + *(float *)&indexIndex) + a38;
  p_x[2] = a40 + (float)(*(float *)&loc + *(float *)&offset);
  p_x[1] = a39 + (float)(*(float *)&loc + *(float *)&offset);
  v54 = &verts[*vertexIndex];
  v54->st.y = 1.0;
  v54->st.x = 0.5;
  v55 = &verts[*vertexIndex + 1].xyz.x;
  *v55 = (float)((float)((float)v46 * (float)width) + *(float *)&indexIndex) + a38;
  v55[1] = (float)((float)v52 + *(float *)&loc) + a39;
  v55[2] = (float)((float)v53 + *(float *)&loc) + a40;
  v56 = &verts[*vertexIndex];
  v56[1].st.x = 0.0;
  v56[1].st.y = 0.0;
  v57 = &verts[*vertexIndex + 2].xyz.x;
  *v57 = (float)(*(float *)&indexIndex - (float)((float)v46 * (float)width)) + a38;
  v57[1] = (float)(*(float *)&loc - (float)v52) + a39;
  v57[2] = (float)(*(float *)&loc - (float)v53) + a40;
  v58 = &verts[*vertexIndex];
  v58[2].st.x = 1.0;
  v58[2].st.y = 0.0;
  *vertexIndex += 3;
  *indexIndex += 3;
}


// ========================================================================
// ?CreateSpehery@idPlaytestStorage@@AAAXPAVidTriangles@@AAH1VidVec3@@M2@Z
// EA  : 0x8267C5D8
// RVA : 0x0067C5D8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::CreateSpehery(
        idPlaytestStorage *this,
        idTriangles *tris,
        int *vertexIndex,
        int *indexIndex,
        const idVec3 *loc,
        double radius,
        const idVec3 *offset,
        int a8,
        int a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        float a37)
{
  double v30; // fp8
  double v31; // fp9
  idDrawVert *verts; // r10
  float *p_x; // r11
  idDrawVert *v34; // r9
  idDrawVert *v35; // r11
  float *v36; // r9
  idDrawVert *v37; // r10
  float *v38; // r10
  idDrawVert *v39; // r10
  float *v40; // r10
  idDrawVert *v41; // r10
  float *v42; // r10
  idDrawVert *v43; // r10
  float *v44; // r10
  idDrawVert *v45; // r11

  tris->indexes[*indexIndex] = *vertexIndex;
  tris->indexes[*indexIndex + 1] = *vertexIndex + 1;
  tris->indexes[*indexIndex + 2] = *vertexIndex + 2;
  tris->indexes[*indexIndex + 3] = *vertexIndex + 1;
  tris->indexes[*indexIndex + 4] = *vertexIndex + 2;
  tris->indexes[*indexIndex + 5] = *vertexIndex + 3;
  tris->indexes[*indexIndex + 6] = *vertexIndex + 1;
  tris->indexes[*indexIndex + 7] = *vertexIndex + 2;
  tris->indexes[*indexIndex + 8] = *vertexIndex + 5;
  tris->indexes[*indexIndex + 9] = *vertexIndex + 1;
  tris->indexes[*indexIndex + 10] = *vertexIndex + 2;
  v30 = *(float *)&a9;
  v31 = *(float *)&a8;
  tris->indexes[*indexIndex + 11] = *vertexIndex + 4;
  tris->indexes[*indexIndex + 12] = *vertexIndex;
  tris->indexes[*indexIndex + 13] = *vertexIndex + 5;
  tris->indexes[*indexIndex + 14] = *vertexIndex + 3;
  tris->indexes[*indexIndex + 15] = *vertexIndex;
  tris->indexes[*indexIndex + 16] = *vertexIndex + 4;
  tris->indexes[*indexIndex + 17] = *vertexIndex + 3;
  verts = tris->verts;
  p_x = &verts[*vertexIndex].xyz.x;
  p_x[2] = a37 + (float)(*(float *)&loc + (float)radius);
  *p_x = *(float *)&indexIndex + *(float *)&a8;
  p_x[1] = (float)v30 + *(float *)&loc;
  v34 = &verts[*vertexIndex];
  v35 = verts;
  v34->st.x = 0.5;
  v34->st.y = 1.0;
  v36 = &verts[*vertexIndex + 1].xyz.x;
  v36[1] = *(float *)&loc + (float)v30;
  *v36 = (float)((float)-radius + *(float *)&indexIndex) + (float)v31;
  v36[2] = *(float *)&loc + a37;
  v37 = &verts[*vertexIndex];
  v37[1].st.x = 0.0;
  v37[1].st.y = 0.5;
  v38 = &v35[*vertexIndex + 2].xyz.x;
  *v38 = (float)(*(float *)&indexIndex + (float)radius) + (float)v31;
  v38[1] = *(float *)&loc + (float)v30;
  v38[2] = *(float *)&loc + a37;
  v39 = &v35[*vertexIndex];
  v39[2].st.x = 1.0;
  v39[2].st.y = 0.5;
  v40 = &v35[*vertexIndex + 3].xyz.x;
  *v40 = *(float *)&indexIndex + (float)v31;
  v40[1] = *(float *)&loc + (float)v30;
  v40[2] = (float)((float)-radius + *(float *)&loc) + a37;
  v41 = &v35[*vertexIndex];
  v41[3].st.x = 0.5;
  v41[3].st.y = 0.0;
  v42 = &v35[*vertexIndex + 4].xyz.x;
  v42[1] = (float)(*(float *)&loc + (float)radius) + (float)v30;
  *v42 = *(float *)&indexIndex + (float)v31;
  v42[2] = *(float *)&loc + a37;
  v43 = &v35[*vertexIndex];
  v43[4].st.x = 1.0;
  v43[4].st.y = 0.5;
  v44 = &v35[*vertexIndex + 5].xyz.x;
  *v44 = *(float *)&indexIndex + (float)v31;
  v44[1] = (float)((float)-radius + *(float *)&loc) + (float)v30;
  v44[2] = *(float *)&loc + a37;
  v45 = &v35[*vertexIndex];
  v45[5].st.x = 0.0;
  v45[5].st.y = 0.5;
  *vertexIndex += 6;
  *indexIndex += 18;
}


// ========================================================================
// ?CreateTriQuad@idPlaytestStorage@@AAAXPAVidTriangles@@AAH1VidVec3@@M2@Z
// EA  : 0x8267C9D8
// RVA : 0x0067C9D8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::CreateTriQuad(
        idPlaytestStorage *this,
        idTriangles *tris,
        int *vertexIndex,
        int *indexIndex,
        const idVec3 *loc,
        double scale,
        const idVec3 *offset,
        int a8,
        int a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        float a37)
{
  double v30; // fp5
  double v31; // fp12
  double v32; // fp11
  double v33; // fp30
  double v34; // fp29
  double v35; // fp28
  idDrawVert *verts; // r9
  float *p_x; // r11
  idDrawVert *v38; // r8
  idDrawVert *v39; // r11
  idDrawVert *v40; // r10
  float *v41; // r8
  double v42; // fp4
  idDrawVert *v43; // r9
  float *v44; // r9
  idDrawVert *v45; // r9
  float *v46; // r9
  idDrawVert *v47; // r9
  float *v48; // r9
  idDrawVert *v49; // r9
  float *v50; // r9
  idDrawVert *v51; // r9
  float *v52; // r9
  idDrawVert *v53; // r9
  float *v54; // r9
  idDrawVert *v55; // r11
  float *v56; // r11
  idDrawVert *v57; // r11
  float *v58; // r11
  idDrawVert *v59; // r11
  float *v60; // r11
  idDrawVert *v61; // r11
  float *v62; // r11
  idDrawVert *v63; // r11

  v30 = (float)(*(float *)&loc + (float)scale);
  tris->indexes[*indexIndex] = *vertexIndex;
  tris->indexes[*indexIndex + 1] = *vertexIndex + 1;
  tris->indexes[*indexIndex + 2] = *vertexIndex + 2;
  tris->indexes[*indexIndex + 3] = *vertexIndex + 1;
  tris->indexes[*indexIndex + 4] = *vertexIndex + 3;
  tris->indexes[*indexIndex + 5] = *vertexIndex + 2;
  tris->indexes[*indexIndex + 6] = *vertexIndex + 4;
  tris->indexes[*indexIndex + 7] = *vertexIndex + 5;
  tris->indexes[*indexIndex + 8] = *vertexIndex + 6;
  tris->indexes[*indexIndex + 9] = *vertexIndex + 5;
  tris->indexes[*indexIndex + 10] = *vertexIndex + 7;
  v31 = *(float *)&a9;
  tris->indexes[*indexIndex + 11] = *vertexIndex + 6;
  v32 = *(float *)&a8;
  v33 = (float)(*(float *)&loc + (float)-scale);
  v34 = (float)((float)((float)-scale + *(float *)&indexIndex) + *(float *)&a8);
  tris->indexes[*indexIndex + 12] = *vertexIndex + 8;
  v35 = (float)(*(float *)&loc + *(float *)&a9);
  tris->indexes[*indexIndex + 13] = *vertexIndex + 9;
  tris->indexes[*indexIndex + 14] = *vertexIndex + 10;
  tris->indexes[*indexIndex + 15] = *vertexIndex + 9;
  tris->indexes[*indexIndex + 16] = *vertexIndex + 11;
  tris->indexes[*indexIndex + 17] = *vertexIndex + 10;
  verts = tris->verts;
  p_x = &verts[*vertexIndex].xyz.x;
  *p_x = (float)((float)-scale + *(float *)&indexIndex) + (float)v32;
  p_x[1] = *(float *)&a9 + *(float *)&loc;
  p_x[2] = a37 + (float)(*(float *)&loc + (float)scale);
  v38 = &verts[*vertexIndex];
  v39 = verts;
  v38->st.y = 0.0;
  v38->st.x = 0.0;
  v41 = &verts[*vertexIndex + 1].xyz.x;
  v41[1] = *(float *)&loc + *(float *)&a9;
  v41[2] = (float)(*(float *)&loc + (float)scale) + a37;
  *v41 = (float)(*(float *)&indexIndex + (float)scale) + (float)v32;
  v42 = (float)((float)v30 + *(float *)&a9);
  v40 = verts;
  v43 = &verts[*vertexIndex];
  v43[1].st.x = 1.0;
  v43[1].st.y = 0.0;
  v44 = &v40[*vertexIndex + 2].xyz.x;
  v44[1] = v35;
  v44[2] = (float)v33 + a37;
  *v44 = v34;
  v45 = &v40[*vertexIndex];
  v45[2].st.x = 0.0;
  v45[2].st.y = 1.0;
  v46 = &v40[*vertexIndex + 3].xyz.x;
  *v46 = (float)(*(float *)&indexIndex + (float)scale) + (float)v32;
  v46[1] = v35;
  v46[2] = (float)(*(float *)&loc + (float)-scale) + a37;
  v47 = &v40[*vertexIndex];
  v47[3].st.x = 1.0;
  v47[3].st.y = 1.0;
  v48 = &v40[*vertexIndex + 4].xyz.x;
  *v48 = (float)((float)-scale + *(float *)&indexIndex) + (float)v32;
  v48[2] = *(float *)&loc + a37;
  v48[1] = (float)v30 + (float)v31;
  v49 = &v40[*vertexIndex];
  v49[4].st.x = 0.0;
  v49[4].st.y = 0.0;
  v50 = &v40[*vertexIndex + 5].xyz.x;
  *v50 = (float)(*(float *)&indexIndex + (float)scale) + (float)v32;
  v50[1] = v42;
  v50[2] = *(float *)&loc + a37;
  v51 = &v40[*vertexIndex];
  v51[5].st.y = 0.0;
  v51[5].st.x = 1.0;
  v52 = &v40[*vertexIndex + 6].xyz.x;
  *v52 = (float)((float)-scale + *(float *)&indexIndex) + (float)v32;
  v52[1] = (float)v33 + (float)v31;
  v52[2] = *(float *)&loc + a37;
  v53 = &v40[*vertexIndex];
  v53[6].st.x = 0.0;
  v53[6].st.y = 1.0;
  v54 = &v40[*vertexIndex + 7].xyz.x;
  *v54 = (float)(*(float *)&indexIndex + (float)scale) + (float)v32;
  v54[1] = (float)v33 + (float)v31;
  v54[2] = *(float *)&loc + a37;
  v55 = &v39[*vertexIndex];
  v55[7].st.x = 1.0;
  v55[7].st.y = 1.0;
  v56 = &v40[*vertexIndex + 8].xyz.x;
  *v56 = *(float *)&indexIndex + (float)v32;
  v56[1] = (float)v33 + (float)v31;
  v56[2] = (float)v30 + a37;
  v57 = &v40[*vertexIndex];
  v57[8].st.y = 0.0;
  v57[8].st.x = 0.0;
  v58 = &v40[*vertexIndex + 9].xyz.x;
  v58[1] = (float)v30 + (float)v31;
  v58[2] = (float)v30 + a37;
  *v58 = *(float *)&indexIndex + (float)v32;
  v59 = &v40[*vertexIndex];
  v59[9].st.x = 1.0;
  v59[9].st.y = 0.0;
  v60 = &v40[*vertexIndex + 10].xyz.x;
  v60[2] = (float)v33 + a37;
  *v60 = *(float *)&indexIndex + (float)v32;
  v60[1] = (float)v33 + (float)v31;
  v61 = &v40[*vertexIndex];
  v61[10].st.y = 1.0;
  v61[10].st.x = 0.0;
  v62 = &v40[*vertexIndex + 11].xyz.x;
  *v62 = *(float *)&indexIndex + (float)v32;
  v62[1] = (float)v30 + (float)v31;
  v62[2] = (float)v33 + a37;
  v63 = &v40[*vertexIndex];
  v63[11].st.x = 1.0;
  v63[11].st.y = 1.0;
  *vertexIndex += 12;
  *indexIndex += 18;
}


// ========================================================================
// ?CreateReadableTimeString@idPlaytestStorage@@SA?AVidStr@@H@Z
// EA  : 0x8267D290
// RVA : 0x0067D290
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idStr *__fastcall idPlaytestStorage::CreateReadableTimeString(idStr *result, int timeMS)
{
  __int64 v3; // r6
  __int64 v4; // r8
  va *v5; // r3
  int v7; // [sp+8h] [-1058h]
  int v8; // [sp+Ch] [-1054h]
  int v9; // [sp+10h] [-1050h]
  int v10; // [sp+14h] [-104Ch]
  int v11; // [sp+18h] [-1048h]
  int v12; // [sp+1Ch] [-1044h]
  va v13; // [sp+50h] [-1010h] BYREF

  HIDWORD(v3) = timeMS / 60000;
  LODWORD(v4) = 1000;
  HIDWORD(v4) = &unk_821D0000;
  LODWORD(v3) = timeMS % 60000 / 1000;
  v5 = va::va(
         this: &v13,
         fmt: "%02d:%02d",
         a3: v3,
         a4: v4,
         a5: (unsigned int)timeMS,
         a6: v7,
         a7: v8,
         a8: v9,
         a9: v10,
         a10: v11,
         a11: v12);
  idStr::idStr(this: result, text: v5);
  return result;
}


// ========================================================================
// ?PlayerPathNormal_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABV?$idList@VplayerNormalBreadCrumbInfo_t@idPlaytestStorage@@$04@@@Z
// EA  : 0x8267D390
// RVA : 0x0067D390
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idTriangles *__fastcall idPlaytestStorage::PlayerPathNormal_GenerateTriangles(
        idPlaytestStorage *this,
        const idList<idPlaytestStorage::playerNormalBreadCrumbInfo_t,5> *data)
{
  idTriangles *result; // r3
  idTriangles *v5; // r3
  idTriangles *v6; // r30
  int v7; // r11
  int v8; // r9
  idPlaytestStorage::playerNormalBreadCrumbInfo_t *list; // r8
  double v10; // fp8
  double v11; // fp7
  double v12; // fp6
  double v13; // fp5
  double v14; // fp4
  double v15; // fp3
  double v16; // fp2
  double v17; // fp5
  double v18; // fp4
  double v19; // fp3
  double v20; // fp2
  int num; // r4
  int v22; // r28
  float v23; // r26
  __int64 v24; // r25
  int v25; // r27
  idPlaytestStorage::playerNormalBreadCrumbInfo_t *v26; // r11
  __int64 v27; // r7
  double v28; // fp9
  double z; // fp8
  double v30; // fp7
  double v31; // fp6
  idBounds *v32; // r3
  float v33; // [sp+8h] [-E8h]
  float v34; // [sp+8h] [-E8h]
  float v35; // [sp+Ch] [-E4h]
  float v36; // [sp+Ch] [-E4h]
  float v37; // [sp+10h] [-E0h]
  float v38; // [sp+10h] [-E0h]
  float v39; // [sp+14h] [-DCh]
  float v40; // [sp+14h] [-DCh]
  float v41; // [sp+18h] [-D8h]
  float v42; // [sp+18h] [-D8h]
  float v43; // [sp+1Ch] [-D4h]
  float v44; // [sp+1Ch] [-D4h]
  float v45; // [sp+20h] [-D0h]
  float v46; // [sp+20h] [-D0h]
  float v47; // [sp+24h] [-CCh]
  float v48; // [sp+24h] [-CCh]
  float v49; // [sp+28h] [-C8h]
  float v50; // [sp+28h] [-C8h]
  float v51; // [sp+2Ch] [-C4h]
  float v52; // [sp+2Ch] [-C4h]
  float v53; // [sp+30h] [-C0h]
  float v54; // [sp+30h] [-C0h]
  float v55; // [sp+34h] [-BCh]
  float v56; // [sp+34h] [-BCh]
  float v57; // [sp+38h] [-B8h]
  float v58; // [sp+38h] [-B8h]
  float v59; // [sp+3Ch] [-B4h]
  float v60; // [sp+3Ch] [-B4h]
  float v61; // [sp+40h] [-B0h]
  float v62; // [sp+40h] [-B0h]
  float v63; // [sp+44h] [-ACh]
  float v64; // [sp+44h] [-ACh]
  float v65; // [sp+48h] [-A8h]
  float v66; // [sp+48h] [-A8h]
  float v67; // [sp+4Ch] [-A4h]
  float v68; // [sp+4Ch] [-A4h]
  float v69; // [sp+50h] [-A0h]
  float v70; // [sp+50h] [-A0h]
  float v71; // [sp+54h] [-9Ch]
  float v72; // [sp+54h] [-9Ch]
  float v73; // [sp+58h] [-98h]
  float v74; // [sp+5Ch] [-94h]
  int v75[3]; // [sp+74h] [-7Ch] BYREF
  __int64 v76; // [sp+80h] [-70h] BYREF
  float v77; // [sp+88h] [-68h]

  result = nullptr;
  if ( data->num > 0 )
  {
    v5 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x84u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v75[0] = (int)v5;
    if ( v5 != nullptr )
      v6 = idTriangles::idTriangles(this: v5);
    else
      v6 = nullptr;
    v6->numVerts = 6;
    v7 = 1;
    for ( v6->numIndexes = 18; v7 < data->num; v6->numIndexes = v8 )
    {
      ++v7;
      v8 = v6->numIndexes + 6;
      v6->numVerts += 5;
    }
    idTriangles::AllocStaticTriSurfVerts(this: v6, numVerts: v6->numVerts);
    idTriangles::AllocStaticTriSurfIndexes(this: v6, numIndexes: v6->numIndexes);
    list = data->list;
    v75[0] = 0;
    idPlaytestStorage::CreateSpehery(
      this,
      tris: v6,
      vertexIndex: v75,
      indexIndex: (int *)LODWORD(list->loc.x),
      loc: (const idVec3 *)LODWORD(list->loc.y),
      radius: 15.0,
      offset: (const idVec3 *)__ROL4__(LODWORD(vec3_origin.x), 32),
      a8: SLODWORD(vec3_origin.x),
      a9: SLODWORD(vec3_origin.y),
      a10: v16,
      a11: v15,
      a12: v14,
      a13: v13,
      a14: v12,
      a15: v11,
      a16: v10,
      a17: v33,
      a18: v35,
      a19: v37,
      a20: v39,
      a21: v41,
      a22: v43,
      a23: v45,
      a24: v47,
      a25: v49,
      a26: v51,
      a27: v53,
      a28: v55,
      a29: v57,
      a30: v59,
      a31: v61,
      a32: v63,
      a33: v65,
      a34: v67,
      a35: v69,
      a36: v71,
      a37: vec3_origin.z);
    num = data->num;
    v22 = 1;
    v77 = -30.0;
    v76 = *(_QWORD *)&vec3_origin.x;
    if ( num > 1 )
    {
      v23 = v77;
      v24 = v76;
      v25 = 1;
      do
      {
        v26 = &data->list[v25];
        v75[1] = (int)&v26[-1];
        v27 = *(_QWORD *)&v26[-1].loc.x;
        v28 = (float)(v26->loc.y - v26[-1].loc.y);
        *(float *)&v76 = v26->loc.x - v26[-1].loc.x;
        *((float *)&v76 + 1) = v28;
        z = v26->loc.z;
        v30 = v26[-1].loc.z;
        v31 = (float)(v26->loc.z - v26[-1].loc.z);
        v77 = v26->loc.z - v26[-1].loc.z;
        idPlaytestStorage::CreateWedge(
          this: (idPlaytestStorage *)HIDWORD(v24),
          tris: v6,
          vertexIndex: v75,
          indexIndex: (int *)HIDWORD(v27),
          loc: (const idVec3 *)v27,
          dir: HIDWORD(v76),
          width: 2.5,
          offset: v76,
          a9: v20,
          a10: v19,
          a11: v18,
          a12: v17,
          a13: v31,
          a14: v30,
          a15: z,
          a16: v34,
          a17: v36,
          a18: v38,
          a19: v40,
          a20: v42,
          a21: v44,
          a22: v46,
          a23: v48,
          a24: v50,
          a25: v52,
          a26: v54,
          a27: v56,
          a28: v58,
          a29: v60,
          a30: v62,
          a31: v64,
          a32: v66,
          a33: v68,
          a34: v70,
          a35: v72,
          a36: v73,
          a37: v74,
          a38: *(float *)&v24,
          a39: *((float *)&v24 + 1),
          a40: v23);
        ++v22;
        ++v25;
      }
      while ( v22 < data->num );
    }
    v32 = idTriangles::BoundsFromVertScan(this: (idTriangles *)&v76, result: &v6->bounds);
    v75[1] = (int)&v32->b[1];
    v6->bounds = *v32;
    return v6;
  }
  return result;
}


// ========================================================================
// __unwind$237226_0
// EA  : 0x8267D5E8
// RVA : 0x0067D5E8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_237226_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 116), tag: a2);
}


// ========================================================================
// ?AIPathNormal_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABV?$idList@Vai2BreadCrumbInfo_t@idPlaytestStorage@@$04@@_N@Z
// EA  : 0x8267D618
// RVA : 0x0067D618
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idTriangles *__fastcall idPlaytestStorage::AIPathNormal_GenerateTriangles(
        idPlaytestStorage *this,
        const idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5> *data,
        bool doHostile)
{
  idTriangles *v5; // r30
  idTriangles *v7; // r3
  int v8; // r11
  int v9; // r9
  idPlaytestStorage::ai2BreadCrumbInfo_t *list; // r8
  double v11; // fp8
  double v12; // fp7
  double v13; // fp6
  double v14; // fp5
  double v15; // fp4
  double v16; // fp3
  double v17; // fp2
  double v18; // fp5
  double v19; // fp4
  double v20; // fp3
  double v21; // fp2
  int v22; // r28
  int v23; // r27
  idPlaytestStorage::ai2BreadCrumbInfo_t *v24; // r11
  double x; // fp0
  double v26; // fp13
  double z; // fp8
  __int64 v28; // r7
  double v29; // fp7
  double v30; // fp6
  idBounds *v31; // r3
  double v32; // fp12
  float v33; // [sp+8h] [-E8h]
  float v34; // [sp+8h] [-E8h]
  float v35; // [sp+Ch] [-E4h]
  float v36; // [sp+Ch] [-E4h]
  float v37; // [sp+10h] [-E0h]
  float v38; // [sp+10h] [-E0h]
  float v39; // [sp+14h] [-DCh]
  float v40; // [sp+14h] [-DCh]
  float v41; // [sp+18h] [-D8h]
  float v42; // [sp+18h] [-D8h]
  float v43; // [sp+1Ch] [-D4h]
  float v44; // [sp+1Ch] [-D4h]
  float v45; // [sp+20h] [-D0h]
  float v46; // [sp+20h] [-D0h]
  float v47; // [sp+24h] [-CCh]
  float v48; // [sp+24h] [-CCh]
  float v49; // [sp+28h] [-C8h]
  float v50; // [sp+28h] [-C8h]
  float v51; // [sp+2Ch] [-C4h]
  float v52; // [sp+2Ch] [-C4h]
  float v53; // [sp+30h] [-C0h]
  float v54; // [sp+30h] [-C0h]
  float v55; // [sp+34h] [-BCh]
  float v56; // [sp+34h] [-BCh]
  float v57; // [sp+38h] [-B8h]
  float v58; // [sp+38h] [-B8h]
  float v59; // [sp+3Ch] [-B4h]
  float v60; // [sp+3Ch] [-B4h]
  float v61; // [sp+40h] [-B0h]
  float v62; // [sp+40h] [-B0h]
  float v63; // [sp+44h] [-ACh]
  float v64; // [sp+44h] [-ACh]
  float v65; // [sp+48h] [-A8h]
  float v66; // [sp+48h] [-A8h]
  float v67; // [sp+4Ch] [-A4h]
  float v68; // [sp+4Ch] [-A4h]
  float v69; // [sp+50h] [-A0h]
  float v70; // [sp+50h] [-A0h]
  float v71; // [sp+54h] [-9Ch]
  float v72; // [sp+54h] [-9Ch]
  float v73; // [sp+58h] [-98h]
  float v74; // [sp+5Ch] [-94h]
  int v75[3]; // [sp+74h] [-7Ch] BYREF
  float v76; // [sp+80h] [-70h] BYREF
  float v77; // [sp+84h] [-6Ch]
  float v78; // [sp+88h] [-68h]

  v5 = nullptr;
  if ( data->num > 0 )
  {
    if ( data->list->isHostile != doHostile )
      return nullptr;
    v7 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x84u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v75[0] = (int)v7;
    if ( v7 != nullptr )
      v5 = idTriangles::idTriangles(this: v7);
    else
      v5 = nullptr;
    v5->numVerts = 6;
    v8 = 1;
    for ( v5->numIndexes = 18; v8 < data->num; v5->numIndexes = v9 )
    {
      ++v8;
      v9 = v5->numIndexes + 6;
      v5->numVerts += 5;
    }
    idTriangles::AllocStaticTriSurfVerts(this: v5, numVerts: v5->numVerts);
    idTriangles::AllocStaticTriSurfIndexes(this: v5, numIndexes: v5->numIndexes);
    list = data->list;
    v75[0] = 0;
    idPlaytestStorage::CreateSpehery(
      this,
      tris: v5,
      vertexIndex: v75,
      indexIndex: (int *)LODWORD(list->loc.x),
      loc: (const idVec3 *)LODWORD(list->loc.y),
      radius: 15.0,
      offset: (const idVec3 *)__ROL4__(LODWORD(vec3_origin.x), 32),
      a8: SLODWORD(vec3_origin.x),
      a9: SLODWORD(vec3_origin.y),
      a10: v17,
      a11: v16,
      a12: v15,
      a13: v14,
      a14: v13,
      a15: v12,
      a16: v11,
      a17: v33,
      a18: v35,
      a19: v37,
      a20: v39,
      a21: v41,
      a22: v43,
      a23: v45,
      a24: v47,
      a25: v49,
      a26: v51,
      a27: v53,
      a28: v55,
      a29: v57,
      a30: v59,
      a31: v61,
      a32: v63,
      a33: v65,
      a34: v67,
      a35: v69,
      a36: v71,
      a37: vec3_origin.z);
    v22 = 1;
    if ( data->num > 1 )
    {
      v23 = 1;
      do
      {
        v24 = &data->list[v23];
        v75[1] = (int)v24;
        x = v24->loc.x;
        v26 = v24[-1].loc.x;
        v75[1] = (int)&v24[-1];
        v77 = v24->loc.y - v24[-1].loc.y;
        v76 = (float)x - (float)v26;
        z = v24->loc.z;
        v28 = *(_QWORD *)&v24[-1].loc.x;
        v29 = v24[-1].loc.z;
        v30 = (float)(v24->loc.z - v24[-1].loc.z);
        v78 = v24->loc.z - v24[-1].loc.z;
        idPlaytestStorage::CreateWedge(
          this,
          tris: v5,
          vertexIndex: v75,
          indexIndex: (int *)HIDWORD(v28),
          loc: (const idVec3 *)v28,
          dir: LODWORD(v76),
          width: 2.5,
          offset: LODWORD(v77),
          a9: v21,
          a10: v20,
          a11: v19,
          a12: v18,
          a13: v30,
          a14: v29,
          a15: z,
          a16: v34,
          a17: v36,
          a18: v38,
          a19: v40,
          a20: v42,
          a21: v44,
          a22: v46,
          a23: v48,
          a24: v50,
          a25: v52,
          a26: v54,
          a27: v56,
          a28: v58,
          a29: v60,
          a30: v62,
          a31: v64,
          a32: v66,
          a33: v68,
          a34: v70,
          a35: v72,
          a36: v73,
          a37: v74,
          a38: vec3_origin.x,
          a39: vec3_origin.y,
          a40: vec3_origin.z);
        ++v22;
        ++v23;
      }
      while ( v22 < data->num );
    }
    v31 = idTriangles::BoundsFromVertScan(this: (idTriangles *)&v76, result: &v5->bounds);
    v5->bounds.b[0].x = v31->b[0].x;
    v5->bounds.b[0].y = v31->b[0].y;
    v75[1] = (int)&v5->bounds.b[1];
    v32 = v31->b[0].z;
    v75[1] = (int)&v31->b[1];
    v5->bounds.b[0].z = v32;
    v5->bounds.b[1] = v31->b[1];
  }
  return v5;
}


// ========================================================================
// __unwind$237342
// EA  : 0x8267D868
// RVA : 0x0067D868
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_237342(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 116), tag: a2);
}


// ========================================================================
// ?PlayerPathVehicle_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABV?$idList@VplayerVehicleBreadCrumbInfo_t@idPlaytestStorage@@$04@@M@Z
// EA  : 0x8267D898
// RVA : 0x0067D898
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idTriangles *__fastcall idPlaytestStorage::PlayerPathVehicle_GenerateTriangles(
        idPlaytestStorage *this,
        const idList<idPlaytestStorage::playerVehicleBreadCrumbInfo_t,5> *data,
        double scale)
{
  idTriangles *result; // r3
  idTriangles *v7; // r3
  idTriangles *v8; // r30
  int v9; // r11
  int v10; // r9
  idPlaytestStorage::playerVehicleBreadCrumbInfo_t *list; // r8
  double v12; // fp8
  double v13; // fp7
  double v14; // fp6
  double v15; // fp5
  double v16; // fp4
  double v17; // fp3
  double v18; // fp2
  double v19; // fp5
  double v20; // fp4
  double v21; // fp3
  double v22; // fp2
  int v23; // r28
  int v24; // r27
  idPlaytestStorage::playerVehicleBreadCrumbInfo_t *v25; // r11
  double x; // fp0
  double v27; // fp13
  double z; // fp8
  __int64 v29; // r7
  double v30; // fp7
  double v31; // fp6
  idBounds *v32; // r3
  float v33; // [sp+8h] [-E8h]
  float v34; // [sp+8h] [-E8h]
  float v35; // [sp+Ch] [-E4h]
  float v36; // [sp+Ch] [-E4h]
  float v37; // [sp+10h] [-E0h]
  float v38; // [sp+10h] [-E0h]
  float v39; // [sp+14h] [-DCh]
  float v40; // [sp+14h] [-DCh]
  float v41; // [sp+18h] [-D8h]
  float v42; // [sp+18h] [-D8h]
  float v43; // [sp+1Ch] [-D4h]
  float v44; // [sp+1Ch] [-D4h]
  float v45; // [sp+20h] [-D0h]
  float v46; // [sp+20h] [-D0h]
  float v47; // [sp+24h] [-CCh]
  float v48; // [sp+24h] [-CCh]
  float v49; // [sp+28h] [-C8h]
  float v50; // [sp+28h] [-C8h]
  float v51; // [sp+2Ch] [-C4h]
  float v52; // [sp+2Ch] [-C4h]
  float v53; // [sp+30h] [-C0h]
  float v54; // [sp+30h] [-C0h]
  float v55; // [sp+34h] [-BCh]
  float v56; // [sp+34h] [-BCh]
  float v57; // [sp+38h] [-B8h]
  float v58; // [sp+38h] [-B8h]
  float v59; // [sp+3Ch] [-B4h]
  float v60; // [sp+3Ch] [-B4h]
  float v61; // [sp+40h] [-B0h]
  float v62; // [sp+40h] [-B0h]
  float v63; // [sp+44h] [-ACh]
  float v64; // [sp+44h] [-ACh]
  float v65; // [sp+48h] [-A8h]
  float v66; // [sp+48h] [-A8h]
  float v67; // [sp+4Ch] [-A4h]
  float v68; // [sp+4Ch] [-A4h]
  float v69; // [sp+50h] [-A0h]
  float v70; // [sp+50h] [-A0h]
  float v71; // [sp+54h] [-9Ch]
  float v72; // [sp+54h] [-9Ch]
  float v73; // [sp+58h] [-98h]
  float v74; // [sp+5Ch] [-94h]
  int v75[3]; // [sp+74h] [-7Ch] BYREF
  float v76; // [sp+80h] [-70h] BYREF
  float v77; // [sp+84h] [-6Ch]
  float v78; // [sp+88h] [-68h]

  result = nullptr;
  if ( data->num > 0 )
  {
    v7 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x84u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v75[0] = (int)v7;
    if ( v7 != nullptr )
      v8 = idTriangles::idTriangles(this: v7);
    else
      v8 = nullptr;
    v8->numVerts = 6;
    v9 = 1;
    for ( v8->numIndexes = 18; v9 < data->num; v8->numIndexes = v10 )
    {
      ++v9;
      v10 = v8->numIndexes + 6;
      v8->numVerts += 5;
    }
    idTriangles::AllocStaticTriSurfVerts(this: v8, numVerts: v8->numVerts);
    idTriangles::AllocStaticTriSurfIndexes(this: v8, numIndexes: v8->numIndexes);
    list = data->list;
    v75[0] = 0;
    idPlaytestStorage::CreateSpehery(
      this,
      tris: v8,
      vertexIndex: v75,
      indexIndex: (int *)LODWORD(list->loc.x),
      loc: (const idVec3 *)LODWORD(list->loc.y),
      radius: 15.0,
      offset: (const idVec3 *)__ROL4__(LODWORD(vec3_origin.x), 32),
      a8: SLODWORD(vec3_origin.x),
      a9: SLODWORD(vec3_origin.y),
      a10: v18,
      a11: v17,
      a12: v16,
      a13: v15,
      a14: v14,
      a15: v13,
      a16: v12,
      a17: v33,
      a18: v35,
      a19: v37,
      a20: v39,
      a21: v41,
      a22: v43,
      a23: v45,
      a24: v47,
      a25: v49,
      a26: v51,
      a27: v53,
      a28: v55,
      a29: v57,
      a30: v59,
      a31: v61,
      a32: v63,
      a33: v65,
      a34: v67,
      a35: v69,
      a36: v71,
      a37: vec3_origin.z);
    v23 = 1;
    if ( data->num > 1 )
    {
      v24 = 1;
      do
      {
        v25 = &data->list[v24];
        v75[1] = (int)v25;
        x = v25->loc.x;
        v27 = v25[-1].loc.x;
        v75[1] = (int)&v25[-1];
        v77 = v25->loc.y - v25[-1].loc.y;
        v76 = (float)x - (float)v27;
        z = v25->loc.z;
        v29 = *(_QWORD *)&v25[-1].loc.x;
        v30 = v25[-1].loc.z;
        v31 = (float)(v25->loc.z - v25[-1].loc.z);
        v78 = v25->loc.z - v25[-1].loc.z;
        idPlaytestStorage::CreateWedge(
          this,
          tris: v8,
          vertexIndex: v75,
          indexIndex: (int *)HIDWORD(v29),
          loc: (const idVec3 *)v29,
          dir: LODWORD(v76),
          width: scale,
          offset: LODWORD(v77),
          a9: v22,
          a10: v21,
          a11: v20,
          a12: v19,
          a13: v31,
          a14: v30,
          a15: z,
          a16: v34,
          a17: v36,
          a18: v38,
          a19: v40,
          a20: v42,
          a21: v44,
          a22: v46,
          a23: v48,
          a24: v50,
          a25: v52,
          a26: v54,
          a27: v56,
          a28: v58,
          a29: v60,
          a30: v62,
          a31: v64,
          a32: v66,
          a33: v68,
          a34: v70,
          a35: v72,
          a36: v73,
          a37: v74,
          a38: vec3_origin.x,
          a39: vec3_origin.y,
          a40: vec3_origin.z);
        ++v23;
        ++v24;
      }
      while ( v23 < data->num );
    }
    v32 = idTriangles::BoundsFromVertScan(this: (idTriangles *)&v76, result: &v8->bounds);
    v75[1] = (int)&v32->b[1];
    v8->bounds = *v32;
    return v8;
  }
  return result;
}


// ========================================================================
// __unwind$237668
// EA  : 0x8267DACC
// RVA : 0x0067DACC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_237668(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 116), tag: a2);
}


// ========================================================================
// ?PlayerPathMisc_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABV?$idList@VplayerMiscControlBreadCrumbInfo_t@idPlaytestStorage@@$04@@@Z
// EA  : 0x8267DB00
// RVA : 0x0067DB00
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idTriangles *__fastcall idPlaytestStorage::PlayerPathMisc_GenerateTriangles(
        idPlaytestStorage *this,
        const idList<idPlaytestStorage::playerMiscControlBreadCrumbInfo_t,5> *data)
{
  idTriangles *result; // r3
  idTriangles *v5; // r3
  idTriangles *v6; // r30
  int v7; // r11
  int v8; // r9
  idPlaytestStorage::playerMiscControlBreadCrumbInfo_t *list; // r8
  double v10; // fp8
  double v11; // fp7
  double v12; // fp6
  double v13; // fp5
  double v14; // fp4
  double v15; // fp3
  double v16; // fp2
  double v17; // fp5
  double v18; // fp4
  double v19; // fp3
  double v20; // fp2
  int v21; // r28
  int v22; // r27
  idPlaytestStorage::playerMiscControlBreadCrumbInfo_t *v23; // r11
  double x; // fp0
  double v25; // fp13
  double z; // fp8
  __int64 v27; // r7
  double v28; // fp7
  double v29; // fp6
  idBounds *v30; // r3
  float v31; // [sp+8h] [-E8h]
  float v32; // [sp+8h] [-E8h]
  float v33; // [sp+Ch] [-E4h]
  float v34; // [sp+Ch] [-E4h]
  float v35; // [sp+10h] [-E0h]
  float v36; // [sp+10h] [-E0h]
  float v37; // [sp+14h] [-DCh]
  float v38; // [sp+14h] [-DCh]
  float v39; // [sp+18h] [-D8h]
  float v40; // [sp+18h] [-D8h]
  float v41; // [sp+1Ch] [-D4h]
  float v42; // [sp+1Ch] [-D4h]
  float v43; // [sp+20h] [-D0h]
  float v44; // [sp+20h] [-D0h]
  float v45; // [sp+24h] [-CCh]
  float v46; // [sp+24h] [-CCh]
  float v47; // [sp+28h] [-C8h]
  float v48; // [sp+28h] [-C8h]
  float v49; // [sp+2Ch] [-C4h]
  float v50; // [sp+2Ch] [-C4h]
  float v51; // [sp+30h] [-C0h]
  float v52; // [sp+30h] [-C0h]
  float v53; // [sp+34h] [-BCh]
  float v54; // [sp+34h] [-BCh]
  float v55; // [sp+38h] [-B8h]
  float v56; // [sp+38h] [-B8h]
  float v57; // [sp+3Ch] [-B4h]
  float v58; // [sp+3Ch] [-B4h]
  float v59; // [sp+40h] [-B0h]
  float v60; // [sp+40h] [-B0h]
  float v61; // [sp+44h] [-ACh]
  float v62; // [sp+44h] [-ACh]
  float v63; // [sp+48h] [-A8h]
  float v64; // [sp+48h] [-A8h]
  float v65; // [sp+4Ch] [-A4h]
  float v66; // [sp+4Ch] [-A4h]
  float v67; // [sp+50h] [-A0h]
  float v68; // [sp+50h] [-A0h]
  float v69; // [sp+54h] [-9Ch]
  float v70; // [sp+54h] [-9Ch]
  float v71; // [sp+58h] [-98h]
  float v72; // [sp+5Ch] [-94h]
  int v73[3]; // [sp+74h] [-7Ch] BYREF
  float v74; // [sp+80h] [-70h] BYREF
  float v75; // [sp+84h] [-6Ch]
  float v76; // [sp+88h] [-68h]

  result = nullptr;
  if ( data->num > 0 )
  {
    v5 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x84u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v73[0] = (int)v5;
    if ( v5 != nullptr )
      v6 = idTriangles::idTriangles(this: v5);
    else
      v6 = nullptr;
    v6->numVerts = 6;
    v7 = 1;
    for ( v6->numIndexes = 18; v7 < data->num; v6->numIndexes = v8 )
    {
      ++v7;
      v8 = v6->numIndexes + 6;
      v6->numVerts += 5;
    }
    idTriangles::AllocStaticTriSurfVerts(this: v6, numVerts: v6->numVerts);
    idTriangles::AllocStaticTriSurfIndexes(this: v6, numIndexes: v6->numIndexes);
    list = data->list;
    v73[0] = 0;
    idPlaytestStorage::CreateSpehery(
      this,
      tris: v6,
      vertexIndex: v73,
      indexIndex: (int *)LODWORD(list->loc.x),
      loc: (const idVec3 *)LODWORD(list->loc.y),
      radius: 15.0,
      offset: (const idVec3 *)__ROL4__(LODWORD(vec3_origin.x), 32),
      a8: SLODWORD(vec3_origin.x),
      a9: SLODWORD(vec3_origin.y),
      a10: v16,
      a11: v15,
      a12: v14,
      a13: v13,
      a14: v12,
      a15: v11,
      a16: v10,
      a17: v31,
      a18: v33,
      a19: v35,
      a20: v37,
      a21: v39,
      a22: v41,
      a23: v43,
      a24: v45,
      a25: v47,
      a26: v49,
      a27: v51,
      a28: v53,
      a29: v55,
      a30: v57,
      a31: v59,
      a32: v61,
      a33: v63,
      a34: v65,
      a35: v67,
      a36: v69,
      a37: vec3_origin.z);
    v21 = 1;
    if ( data->num > 1 )
    {
      v22 = 1;
      do
      {
        v23 = &data->list[v22];
        v73[1] = (int)v23;
        x = v23->loc.x;
        v25 = v23[-1].loc.x;
        v73[1] = (int)&v23[-1];
        v75 = v23->loc.y - v23[-1].loc.y;
        v74 = (float)x - (float)v25;
        z = v23->loc.z;
        v27 = *(_QWORD *)&v23[-1].loc.x;
        v28 = v23[-1].loc.z;
        v29 = (float)(v23->loc.z - v23[-1].loc.z);
        v76 = v23->loc.z - v23[-1].loc.z;
        idPlaytestStorage::CreateWedge(
          this,
          tris: v6,
          vertexIndex: v73,
          indexIndex: (int *)HIDWORD(v27),
          loc: (const idVec3 *)v27,
          dir: LODWORD(v74),
          width: 2.5,
          offset: LODWORD(v75),
          a9: v20,
          a10: v19,
          a11: v18,
          a12: v17,
          a13: v29,
          a14: v28,
          a15: z,
          a16: v32,
          a17: v34,
          a18: v36,
          a19: v38,
          a20: v40,
          a21: v42,
          a22: v44,
          a23: v46,
          a24: v48,
          a25: v50,
          a26: v52,
          a27: v54,
          a28: v56,
          a29: v58,
          a30: v60,
          a31: v62,
          a32: v64,
          a33: v66,
          a34: v68,
          a35: v70,
          a36: v71,
          a37: v72,
          a38: vec3_origin.x,
          a39: vec3_origin.y,
          a40: vec3_origin.z);
        ++v21;
        ++v22;
      }
      while ( v21 < data->num );
    }
    v30 = idTriangles::BoundsFromVertScan(this: (idTriangles *)&v74, result: &v6->bounds);
    v73[1] = (int)&v30->b[1];
    v6->bounds = *v30;
    return v6;
  }
  return result;
}


// ========================================================================
// __unwind$237560
// EA  : 0x8267DD38
// RVA : 0x0067DD38
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_237560(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 116), tag: a2);
}


// ========================================================================
// ?PlayerPathVehicleBoost_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABV?$idList@VplayerVehicleBreadCrumbInfo_t@idPlaytestStorage@@$04@@M@Z
// EA  : 0x8267DD68
// RVA : 0x0067DD68
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idTriangles *__fastcall idPlaytestStorage::PlayerPathVehicleBoost_GenerateTriangles(
        idPlaytestStorage *this,
        const idList<idPlaytestStorage::playerVehicleBreadCrumbInfo_t,5> *data,
        double scale)
{
  idTriangles *v5; // r30
  idTriangles *v6; // r3
  int v7; // r8
  int v8; // r10
  int v9; // r9
  int numVerts; // r4
  double v11; // fp5
  double v12; // fp4
  double v13; // fp3
  double v14; // fp2
  int num; // r5
  int v16; // r27
  float v17; // r26
  int v18; // r28
  __int64 v19; // r25
  idPlaytestStorage::playerVehicleBreadCrumbInfo_t *v20; // r11
  double v21; // fp9
  double z; // fp8
  double v23; // fp7
  double v24; // fp6
  idBounds *v25; // r3
  double v26; // fp12
  float v28; // [sp+8h] [-E8h]
  float v29; // [sp+Ch] [-E4h]
  float v30; // [sp+10h] [-E0h]
  float v31; // [sp+14h] [-DCh]
  float v32; // [sp+18h] [-D8h]
  float v33; // [sp+1Ch] [-D4h]
  float v34; // [sp+20h] [-D0h]
  float v35; // [sp+24h] [-CCh]
  float v36; // [sp+28h] [-C8h]
  float v37; // [sp+2Ch] [-C4h]
  float v38; // [sp+30h] [-C0h]
  float v39; // [sp+34h] [-BCh]
  float v40; // [sp+38h] [-B8h]
  float v41; // [sp+3Ch] [-B4h]
  float v42; // [sp+40h] [-B0h]
  float v43; // [sp+44h] [-ACh]
  float v44; // [sp+48h] [-A8h]
  float v45; // [sp+4Ch] [-A4h]
  float v46; // [sp+50h] [-A0h]
  float v47; // [sp+54h] [-9Ch]
  float v48; // [sp+58h] [-98h]
  float v49; // [sp+5Ch] [-94h]
  idTriangles *v50; // [sp+74h] [-7Ch] BYREF
  __int64 v51; // [sp+80h] [-70h] BYREF
  float v52; // [sp+88h] [-68h]

  v5 = nullptr;
  if ( data->num <= 1 )
    return v5;
  v6 = (idTriangles *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 0x84u,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v50 = v6;
  if ( v6 != nullptr )
    v5 = idTriangles::idTriangles(this: v6);
  else
    v5 = nullptr;
  v5->numVerts = 0;
  v5->numIndexes = 0;
  v7 = 1;
  if ( data->num > 1 )
  {
    v8 = 1;
    do
    {
      if ( data->list[v8].boost < (double)data->list[v8 - 1].boost )
      {
        v9 = v5->numIndexes + 3;
        v5->numVerts += 3;
        v5->numIndexes = v9;
      }
      ++v7;
      ++v8;
    }
    while ( v7 < data->num );
  }
  numVerts = v5->numVerts;
  if ( numVerts != 0 && v5->numIndexes != 0 )
  {
    idTriangles::AllocStaticTriSurfVerts(this: v5, numVerts);
    idTriangles::AllocStaticTriSurfIndexes(this: v5, numIndexes: v5->numIndexes);
    num = data->num;
    v50 = nullptr;
    v16 = 1;
    v52 = -1.0;
    v51 = *(_QWORD *)&vec3_origin.x;
    if ( num > 1 )
    {
      v17 = v52;
      v18 = 1;
      v19 = v51;
      do
      {
        v20 = &data->list[v18];
        if ( v20->boost < (double)v20[-1].boost )
        {
          v21 = (float)(v20->loc.y - v20[-1].loc.y);
          *(float *)&v51 = v20->loc.x - v20[-1].loc.x;
          *((float *)&v51 + 1) = v21;
          z = v20->loc.z;
          v23 = v20[-1].loc.z;
          v24 = (float)(v20->loc.z - v20[-1].loc.z);
          v52 = v20->loc.z - v20[-1].loc.z;
          idPlaytestStorage::CreateTriangle(
            this: (idPlaytestStorage *)HIDWORD(v19),
            tris: v5,
            vertexIndex: (int *)&v50,
            indexIndex: (int *)LODWORD(v20[-1].loc.x),
            loc: (const idVec3 *)LODWORD(v20[-1].loc.y),
            dir: HIDWORD(v51),
            width: scale,
            offset: v51,
            a9: v14,
            a10: v13,
            a11: v12,
            a12: v11,
            a13: v24,
            a14: v23,
            a15: z,
            a16: v28,
            a17: v29,
            a18: v30,
            a19: v31,
            a20: v32,
            a21: v33,
            a22: v34,
            a23: v35,
            a24: v36,
            a25: v37,
            a26: v38,
            a27: v39,
            a28: v40,
            a29: v41,
            a30: v42,
            a31: v43,
            a32: v44,
            a33: v45,
            a34: v46,
            a35: v47,
            a36: v48,
            a37: v49,
            a38: *(float *)&v19,
            a39: *((float *)&v19 + 1),
            a40: v17);
        }
        ++v16;
        ++v18;
      }
      while ( v16 < data->num );
    }
    v25 = idTriangles::BoundsFromVertScan(this: (idTriangles *)&v51, result: &v5->bounds);
    v5->bounds.b[0].x = v25->b[0].x;
    v5->bounds.b[0].y = v25->b[0].y;
    v50 = (idTriangles *)&v5->bounds.b[1];
    v26 = v25->b[0].z;
    v50 = (idTriangles *)&v25->b[1];
    v5->bounds.b[0].z = v26;
    v5->bounds.b[1] = v25->b[1];
    return v5;
  }
  idTriangles::~idTriangles(this: v5);
  idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
  return nullptr;
}


// ========================================================================
// __unwind$237780
// EA  : 0x8267DFD0
// RVA : 0x0067DFD0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_237780(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 116), tag: a2);
}


// ========================================================================
// ?PlayerViewNormal_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABV?$idList@VplayerNormalBreadCrumbInfo_t@idPlaytestStorage@@$04@@@Z
// EA  : 0x8267E000
// RVA : 0x0067E000
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idTriangles *__fastcall idPlaytestStorage::PlayerViewNormal_GenerateTriangles(
        idPlaytestStorage *this,
        const idList<idPlaytestStorage::playerNormalBreadCrumbInfo_t,5> *data)
{
  int v2; // r28
  idTriangles *result; // r3
  idTriangles *v5; // r3
  idTriangles *v6; // r30
  int i; // r11
  int v8; // r9
  double v9; // fp7
  double v10; // fp6
  double v11; // fp5
  double v12; // fp4
  double v13; // fp3
  double v14; // fp2
  int num; // r5
  __int64 v16; // r7 OVERLAPPED
  float v17; // r26
  __int64 v18; // r25
  int v19; // r27
  idPlaytestStorage::playerNormalBreadCrumbInfo_t *v20; // r11
  int timestamp; // r8
  double v22; // fp0
  double v23; // fp8
  double y; // fp11
  double v25; // fp12
  __int64 v26; // r7
  idBounds *v27; // r3
  float v28; // [sp+8h] [-128h]
  float v29; // [sp+Ch] [-124h]
  float v30; // [sp+10h] [-120h]
  float v31; // [sp+14h] [-11Ch]
  float v32; // [sp+18h] [-118h]
  float v33; // [sp+1Ch] [-114h]
  float v34; // [sp+20h] [-110h]
  float v35; // [sp+24h] [-10Ch]
  float v36; // [sp+28h] [-108h]
  float v37; // [sp+2Ch] [-104h]
  float v38; // [sp+30h] [-100h]
  float v39; // [sp+34h] [-FCh]
  float v40; // [sp+38h] [-F8h]
  float v41; // [sp+3Ch] [-F4h]
  float v42; // [sp+40h] [-F0h]
  float v43; // [sp+44h] [-ECh]
  float v44; // [sp+48h] [-E8h]
  float v45; // [sp+4Ch] [-E4h]
  float v46; // [sp+50h] [-E0h]
  float v47; // [sp+54h] [-DCh]
  float v48; // [sp+58h] [-D8h]
  float v49; // [sp+5Ch] [-D4h]
  int v50; // [sp+70h] [-C0h] BYREF
  int v51[5]; // [sp+74h] [-BCh] BYREF
  __int64 v52; // [sp+88h] [-A8h]
  float v53; // [sp+90h] [-A0h]
  idTriangles v54; // [sp+A0h] [-90h] BYREF

  v2 = 0;
  result = nullptr;
  if ( data->num > 0 )
  {
    v5 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x84u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v51[0] = (int)v5;
    if ( v5 != nullptr )
      v6 = idTriangles::idTriangles(this: v5);
    else
      v6 = nullptr;
    v6->numVerts = 0;
    v6->numIndexes = 0;
    for ( i = 0; i < data->num; v6->numIndexes = v8 )
    {
      ++i;
      v8 = v6->numIndexes + 6;
      v6->numVerts += 5;
    }
    idTriangles::AllocStaticTriSurfVerts(this: v6, numVerts: v6->numVerts);
    idTriangles::AllocStaticTriSurfIndexes(this: v6, numIndexes: v6->numIndexes);
    num = data->num;
    v51[0] = 0;
    v50 = 0;
    *(float *)&v16 = vec3_origin.y;
    v53 = -29.0;
    v52 = *(_QWORD *)&vec3_origin.x;
    if ( num > 0 )
    {
      v17 = v53;
      v18 = v52;
      v19 = 0;
      do
      {
        v20 = &data->list[v19];
        timestamp = v20->timestamp;
        LODWORD(v16) = v20->lastTimeStamp;
        *(_QWORD *)&v51[3] = *(__int64 *)((char *)&v16 - 4);
        v52 = v16;
        v22 = (float)((float)((float)v16 - (float)*(__int64 *)((char *)&v16 - 4)) * (float)0.001);
        if ( v22 >= 1.0 )
        {
          if ( v22 > 5.0 )
            v22 = 5.0;
        }
        else
        {
          v22 = 1.0;
        }
        v23 = (float)(v20->dir.z * (float)10.0);
        y = v20->dir.y;
        v25 = (float)(v20->dir.x * (float)10.0);
        v54.bounds.b[0].z = v20->dir.z * (float)10.0;
        v54.bounds.b[0].x = v25;
        v54.bounds.b[0].y = (float)y * (float)10.0;
        v26 = *(_QWORD *)&v20->loc.x;
        v51[1] = (int)&v20->dir;
        idPlaytestStorage::CreateWedge(
          this: (idPlaytestStorage *)HIDWORD(v18),
          tris: v6,
          vertexIndex: v51,
          indexIndex: &v50,
          loc: (const idVec3 *)v26,
          dir: LODWORD(v54.bounds.b[0].x),
          width: (float)((float)v22 * (float)2.5),
          offset: LODWORD(v54.bounds.b[0].y),
          a9: v14,
          a10: v13,
          a11: v12,
          a12: v11,
          a13: v10,
          a14: v9,
          a15: v23,
          a16: v28,
          a17: v29,
          a18: v30,
          a19: v31,
          a20: v32,
          a21: v33,
          a22: v34,
          a23: v35,
          a24: v36,
          a25: v37,
          a26: v38,
          a27: v39,
          a28: v40,
          a29: v41,
          a30: v42,
          a31: v43,
          a32: v44,
          a33: v45,
          a34: v46,
          a35: v47,
          a36: v48,
          a37: v49,
          a38: *(float *)&v18,
          a39: *((float *)&v18 + 1),
          a40: v17);
        ++v2;
        ++v19;
      }
      while ( v2 < data->num );
    }
    v27 = idTriangles::BoundsFromVertScan(this: &v54, result: &v6->bounds);
    v51[1] = (int)&v27->b[1];
    v6->bounds = *v27;
    return v6;
  }
  return result;
}


// ========================================================================
// __unwind$237896_0
// EA  : 0x8267E27C
// RVA : 0x0067E27C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_237896_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 304 + 116), tag: a2);
}


// ========================================================================
// ?PlayerViewMisc_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABV?$idList@VplayerMiscControlBreadCrumbInfo_t@idPlaytestStorage@@$04@@@Z
// EA  : 0x8267E2B0
// RVA : 0x0067E2B0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idTriangles *__fastcall idPlaytestStorage::PlayerViewMisc_GenerateTriangles(
        idPlaytestStorage *this,
        const idList<idPlaytestStorage::playerMiscControlBreadCrumbInfo_t,5> *data)
{
  int v2; // r28
  idTriangles *result; // r3
  idTriangles *v5; // r3
  idTriangles *v6; // r30
  int i; // r11
  int v8; // r9
  double v9; // fp7
  double v10; // fp6
  double v11; // fp5
  double v12; // fp4
  double v13; // fp3
  double v14; // fp2
  int num; // r5
  __int64 v16; // r7 OVERLAPPED
  float v17; // r26
  __int64 v18; // r25
  int v19; // r27
  idPlaytestStorage::playerMiscControlBreadCrumbInfo_t *v20; // r11
  int timestamp; // r8
  double v22; // fp0
  double v23; // fp8
  double y; // fp11
  double v25; // fp12
  __int64 v26; // r7
  idBounds *v27; // r3
  float v28; // [sp+8h] [-128h]
  float v29; // [sp+Ch] [-124h]
  float v30; // [sp+10h] [-120h]
  float v31; // [sp+14h] [-11Ch]
  float v32; // [sp+18h] [-118h]
  float v33; // [sp+1Ch] [-114h]
  float v34; // [sp+20h] [-110h]
  float v35; // [sp+24h] [-10Ch]
  float v36; // [sp+28h] [-108h]
  float v37; // [sp+2Ch] [-104h]
  float v38; // [sp+30h] [-100h]
  float v39; // [sp+34h] [-FCh]
  float v40; // [sp+38h] [-F8h]
  float v41; // [sp+3Ch] [-F4h]
  float v42; // [sp+40h] [-F0h]
  float v43; // [sp+44h] [-ECh]
  float v44; // [sp+48h] [-E8h]
  float v45; // [sp+4Ch] [-E4h]
  float v46; // [sp+50h] [-E0h]
  float v47; // [sp+54h] [-DCh]
  float v48; // [sp+58h] [-D8h]
  float v49; // [sp+5Ch] [-D4h]
  int v50; // [sp+70h] [-C0h] BYREF
  int v51[5]; // [sp+74h] [-BCh] BYREF
  __int64 v52; // [sp+88h] [-A8h]
  float v53; // [sp+90h] [-A0h]
  idTriangles v54; // [sp+A0h] [-90h] BYREF

  v2 = 0;
  result = nullptr;
  if ( data->num > 0 )
  {
    v5 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x84u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v51[0] = (int)v5;
    if ( v5 != nullptr )
      v6 = idTriangles::idTriangles(this: v5);
    else
      v6 = nullptr;
    v6->numVerts = 0;
    v6->numIndexes = 0;
    for ( i = 0; i < data->num; v6->numIndexes = v8 )
    {
      ++i;
      v8 = v6->numIndexes + 6;
      v6->numVerts += 5;
    }
    idTriangles::AllocStaticTriSurfVerts(this: v6, numVerts: v6->numVerts);
    idTriangles::AllocStaticTriSurfIndexes(this: v6, numIndexes: v6->numIndexes);
    num = data->num;
    v51[0] = 0;
    v50 = 0;
    *(float *)&v16 = vec3_origin.y;
    v53 = 1.0;
    v52 = *(_QWORD *)&vec3_origin.x;
    if ( num > 0 )
    {
      v17 = v53;
      v18 = v52;
      v19 = 0;
      do
      {
        v20 = &data->list[v19];
        timestamp = v20->timestamp;
        LODWORD(v16) = v20->lastTimeStamp;
        *(_QWORD *)&v51[3] = *(__int64 *)((char *)&v16 - 4);
        v52 = v16;
        v22 = (float)((float)((float)v16 - (float)*(__int64 *)((char *)&v16 - 4)) * (float)0.001);
        if ( v22 >= 1.0 )
        {
          if ( v22 > 5.0 )
            v22 = 5.0;
        }
        else
        {
          v22 = 1.0;
        }
        v23 = (float)(v20->dir.z * (float)10.0);
        y = v20->dir.y;
        v25 = (float)(v20->dir.x * (float)10.0);
        v54.bounds.b[0].z = v20->dir.z * (float)10.0;
        v54.bounds.b[0].x = v25;
        v54.bounds.b[0].y = (float)y * (float)10.0;
        v26 = *(_QWORD *)&v20->loc.x;
        v51[1] = (int)&v20->dir;
        idPlaytestStorage::CreateWedge(
          this: (idPlaytestStorage *)HIDWORD(v18),
          tris: v6,
          vertexIndex: v51,
          indexIndex: &v50,
          loc: (const idVec3 *)v26,
          dir: LODWORD(v54.bounds.b[0].x),
          width: (float)((float)v22 * (float)2.5),
          offset: LODWORD(v54.bounds.b[0].y),
          a9: v14,
          a10: v13,
          a11: v12,
          a12: v11,
          a13: v10,
          a14: v9,
          a15: v23,
          a16: v28,
          a17: v29,
          a18: v30,
          a19: v31,
          a20: v32,
          a21: v33,
          a22: v34,
          a23: v35,
          a24: v36,
          a25: v37,
          a26: v38,
          a27: v39,
          a28: v40,
          a29: v41,
          a30: v42,
          a31: v43,
          a32: v44,
          a33: v45,
          a34: v46,
          a35: v47,
          a36: v48,
          a37: v49,
          a38: *(float *)&v18,
          a39: *((float *)&v18 + 1),
          a40: v17);
        ++v2;
        ++v19;
      }
      while ( v2 < data->num );
    }
    v27 = idTriangles::BoundsFromVertScan(this: &v54, result: &v6->bounds);
    v51[1] = (int)&v27->b[1];
    v6->bounds = *v27;
    return v6;
  }
  return result;
}


// ========================================================================
// __unwind$238003
// EA  : 0x8267E524
// RVA : 0x0067E524
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_238003(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 304 + 116), tag: a2);
}


// ========================================================================
// ?AIViewNormal_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABV?$idList@Vai2BreadCrumbInfo_t@idPlaytestStorage@@$04@@@Z
// EA  : 0x8267E558
// RVA : 0x0067E558
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idTriangles *__fastcall idPlaytestStorage::AIViewNormal_GenerateTriangles(
        idPlaytestStorage *this,
        const idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5> *data)
{
  int v2; // r28
  idTriangles *result; // r3
  idTriangles *v5; // r3
  idTriangles *v6; // r30
  int i; // r11
  int v8; // r9
  double v9; // fp7
  double v10; // fp6
  double v11; // fp5
  double v12; // fp4
  double v13; // fp3
  double v14; // fp2
  int num; // r5
  __int64 v16; // r7 OVERLAPPED
  float v17; // r26
  __int64 v18; // r25
  int v19; // r27
  idPlaytestStorage::ai2BreadCrumbInfo_t *v20; // r11
  int timestamp; // r8
  double v22; // fp0
  double v23; // fp8
  double y; // fp11
  double v25; // fp12
  __int64 v26; // r7
  idBounds *v27; // r3
  float v28; // [sp+8h] [-128h]
  float v29; // [sp+Ch] [-124h]
  float v30; // [sp+10h] [-120h]
  float v31; // [sp+14h] [-11Ch]
  float v32; // [sp+18h] [-118h]
  float v33; // [sp+1Ch] [-114h]
  float v34; // [sp+20h] [-110h]
  float v35; // [sp+24h] [-10Ch]
  float v36; // [sp+28h] [-108h]
  float v37; // [sp+2Ch] [-104h]
  float v38; // [sp+30h] [-100h]
  float v39; // [sp+34h] [-FCh]
  float v40; // [sp+38h] [-F8h]
  float v41; // [sp+3Ch] [-F4h]
  float v42; // [sp+40h] [-F0h]
  float v43; // [sp+44h] [-ECh]
  float v44; // [sp+48h] [-E8h]
  float v45; // [sp+4Ch] [-E4h]
  float v46; // [sp+50h] [-E0h]
  float v47; // [sp+54h] [-DCh]
  float v48; // [sp+58h] [-D8h]
  float v49; // [sp+5Ch] [-D4h]
  int v50; // [sp+70h] [-C0h] BYREF
  int v51[5]; // [sp+74h] [-BCh] BYREF
  __int64 v52; // [sp+88h] [-A8h]
  float v53; // [sp+90h] [-A0h]
  idTriangles v54; // [sp+A0h] [-90h] BYREF

  v2 = 0;
  result = nullptr;
  if ( data->num > 0 )
  {
    v5 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x84u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v51[0] = (int)v5;
    if ( v5 != nullptr )
      v6 = idTriangles::idTriangles(this: v5);
    else
      v6 = nullptr;
    v6->numVerts = 0;
    v6->numIndexes = 0;
    for ( i = 0; i < data->num; v6->numIndexes = v8 )
    {
      ++i;
      v8 = v6->numIndexes + 6;
      v6->numVerts += 5;
    }
    idTriangles::AllocStaticTriSurfVerts(this: v6, numVerts: v6->numVerts);
    idTriangles::AllocStaticTriSurfIndexes(this: v6, numIndexes: v6->numIndexes);
    num = data->num;
    v51[0] = 0;
    v50 = 0;
    *(float *)&v16 = vec3_origin.y;
    v53 = 1.0;
    v52 = *(_QWORD *)&vec3_origin.x;
    if ( num > 0 )
    {
      v17 = v53;
      v18 = v52;
      v19 = 0;
      do
      {
        v20 = &data->list[v19];
        timestamp = v20->timestamp;
        LODWORD(v16) = v20->lastTimeStamp;
        *(_QWORD *)&v51[3] = *(__int64 *)((char *)&v16 - 4);
        v52 = v16;
        v22 = (float)((float)((float)v16 - (float)*(__int64 *)((char *)&v16 - 4)) * (float)0.001);
        if ( v22 >= 1.0 )
        {
          if ( v22 > 5.0 )
            v22 = 5.0;
        }
        else
        {
          v22 = 1.0;
        }
        v23 = (float)(v20->dir.z * (float)10.0);
        y = v20->dir.y;
        v25 = (float)(v20->dir.x * (float)10.0);
        v54.bounds.b[0].z = v20->dir.z * (float)10.0;
        v54.bounds.b[0].x = v25;
        v54.bounds.b[0].y = (float)y * (float)10.0;
        v26 = *(_QWORD *)&v20->loc.x;
        v51[1] = (int)&v20->dir;
        idPlaytestStorage::CreateWedge(
          this: (idPlaytestStorage *)HIDWORD(v18),
          tris: v6,
          vertexIndex: v51,
          indexIndex: &v50,
          loc: (const idVec3 *)v26,
          dir: LODWORD(v54.bounds.b[0].x),
          width: (float)((float)v22 * (float)2.5),
          offset: LODWORD(v54.bounds.b[0].y),
          a9: v14,
          a10: v13,
          a11: v12,
          a12: v11,
          a13: v10,
          a14: v9,
          a15: v23,
          a16: v28,
          a17: v29,
          a18: v30,
          a19: v31,
          a20: v32,
          a21: v33,
          a22: v34,
          a23: v35,
          a24: v36,
          a25: v37,
          a26: v38,
          a27: v39,
          a28: v40,
          a29: v41,
          a30: v42,
          a31: v43,
          a32: v44,
          a33: v45,
          a34: v46,
          a35: v47,
          a36: v48,
          a37: v49,
          a38: *(float *)&v18,
          a39: *((float *)&v18 + 1),
          a40: v17);
        ++v2;
        ++v19;
      }
      while ( v2 < data->num );
    }
    v27 = idTriangles::BoundsFromVertScan(this: &v54, result: &v6->bounds);
    v51[1] = (int)&v27->b[1];
    v6->bounds = *v27;
    return v6;
  }
  return result;
}


// ========================================================================
// __unwind$238197
// EA  : 0x8267E7CC
// RVA : 0x0067E7CC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_238197(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 304 + 116), tag: a2);
}


// ========================================================================
// ?AIViewVehicle_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABV?$idList@VaiVehicleBreadCrumbInfo_t@idPlaytestStorage@@$04@@@Z
// EA  : 0x8267E800
// RVA : 0x0067E800
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idTriangles *__fastcall idPlaytestStorage::AIViewVehicle_GenerateTriangles(
        idPlaytestStorage *this,
        const idList<idPlaytestStorage::aiVehicleBreadCrumbInfo_t,5> *data)
{
  int v2; // r28
  idTriangles *result; // r3
  idTriangles *v5; // r3
  idTriangles *v6; // r30
  int i; // r11
  int v8; // r9
  double v9; // fp7
  double v10; // fp6
  double v11; // fp5
  double v12; // fp4
  double v13; // fp3
  double v14; // fp2
  int num; // r5
  __int64 v16; // r7 OVERLAPPED
  float v17; // r26
  __int64 v18; // r25
  int v19; // r27
  idPlaytestStorage::aiVehicleBreadCrumbInfo_t *v20; // r11
  int timestamp; // r8
  double v22; // fp0
  double v23; // fp8
  double y; // fp11
  double v25; // fp12
  __int64 v26; // r7
  idBounds *v27; // r3
  float v28; // [sp+8h] [-128h]
  float v29; // [sp+Ch] [-124h]
  float v30; // [sp+10h] [-120h]
  float v31; // [sp+14h] [-11Ch]
  float v32; // [sp+18h] [-118h]
  float v33; // [sp+1Ch] [-114h]
  float v34; // [sp+20h] [-110h]
  float v35; // [sp+24h] [-10Ch]
  float v36; // [sp+28h] [-108h]
  float v37; // [sp+2Ch] [-104h]
  float v38; // [sp+30h] [-100h]
  float v39; // [sp+34h] [-FCh]
  float v40; // [sp+38h] [-F8h]
  float v41; // [sp+3Ch] [-F4h]
  float v42; // [sp+40h] [-F0h]
  float v43; // [sp+44h] [-ECh]
  float v44; // [sp+48h] [-E8h]
  float v45; // [sp+4Ch] [-E4h]
  float v46; // [sp+50h] [-E0h]
  float v47; // [sp+54h] [-DCh]
  float v48; // [sp+58h] [-D8h]
  float v49; // [sp+5Ch] [-D4h]
  int v50; // [sp+70h] [-C0h] BYREF
  int v51[5]; // [sp+74h] [-BCh] BYREF
  __int64 v52; // [sp+88h] [-A8h]
  float v53; // [sp+90h] [-A0h]
  idTriangles v54; // [sp+A0h] [-90h] BYREF

  v2 = 0;
  result = nullptr;
  if ( data->num > 0 )
  {
    v5 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x84u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v51[0] = (int)v5;
    if ( v5 != nullptr )
      v6 = idTriangles::idTriangles(this: v5);
    else
      v6 = nullptr;
    v6->numVerts = 0;
    v6->numIndexes = 0;
    for ( i = 0; i < data->num; v6->numIndexes = v8 )
    {
      ++i;
      v8 = v6->numIndexes + 6;
      v6->numVerts += 5;
    }
    idTriangles::AllocStaticTriSurfVerts(this: v6, numVerts: v6->numVerts);
    idTriangles::AllocStaticTriSurfIndexes(this: v6, numIndexes: v6->numIndexes);
    num = data->num;
    v51[0] = 0;
    v50 = 0;
    *(float *)&v16 = vec3_origin.y;
    v53 = 1.0;
    v52 = *(_QWORD *)&vec3_origin.x;
    if ( num > 0 )
    {
      v17 = v53;
      v18 = v52;
      v19 = 0;
      do
      {
        v20 = &data->list[v19];
        timestamp = v20->timestamp;
        LODWORD(v16) = v20->lastTimeStamp;
        *(_QWORD *)&v51[3] = *(__int64 *)((char *)&v16 - 4);
        v52 = v16;
        v22 = (float)((float)((float)v16 - (float)*(__int64 *)((char *)&v16 - 4)) * (float)0.001);
        if ( v22 >= 1.0 )
        {
          if ( v22 > 5.0 )
            v22 = 5.0;
        }
        else
        {
          v22 = 1.0;
        }
        v23 = (float)(v20->dir.z * (float)10.0);
        y = v20->dir.y;
        v25 = (float)(v20->dir.x * (float)10.0);
        v54.bounds.b[0].z = v20->dir.z * (float)10.0;
        v54.bounds.b[0].x = v25;
        v54.bounds.b[0].y = (float)y * (float)10.0;
        v26 = *(_QWORD *)&v20->loc.x;
        v51[1] = (int)&v20->dir;
        idPlaytestStorage::CreateWedge(
          this: (idPlaytestStorage *)HIDWORD(v18),
          tris: v6,
          vertexIndex: v51,
          indexIndex: &v50,
          loc: (const idVec3 *)v26,
          dir: LODWORD(v54.bounds.b[0].x),
          width: (float)((float)v22 * (float)2.5),
          offset: LODWORD(v54.bounds.b[0].y),
          a9: v14,
          a10: v13,
          a11: v12,
          a12: v11,
          a13: v10,
          a14: v9,
          a15: v23,
          a16: v28,
          a17: v29,
          a18: v30,
          a19: v31,
          a20: v32,
          a21: v33,
          a22: v34,
          a23: v35,
          a24: v36,
          a25: v37,
          a26: v38,
          a27: v39,
          a28: v40,
          a29: v41,
          a30: v42,
          a31: v43,
          a32: v44,
          a33: v45,
          a34: v46,
          a35: v47,
          a36: v48,
          a37: v49,
          a38: *(float *)&v18,
          a39: *((float *)&v18 + 1),
          a40: v17);
        ++v2;
        ++v19;
      }
      while ( v2 < data->num );
    }
    v27 = idTriangles::BoundsFromVertScan(this: &v54, result: &v6->bounds);
    v51[1] = (int)&v27->b[1];
    v6->bounds = *v27;
    return v6;
  }
  return result;
}


// ========================================================================
// __unwind$238294
// EA  : 0x8267EA74
// RVA : 0x0067EA74
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_238294(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 304 + 116), tag: a2);
}


// ========================================================================
// ?PlayerItem_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABVitemInfo_t@1@MM@Z
// EA  : 0x8267EAA8
// RVA : 0x0067EAA8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idTriangles *__fastcall idPlaytestStorage::PlayerItem_GenerateTriangles(
        idPlaytestStorage *this,
        const idPlaytestStorage::itemInfo_t *itemLog,
        double scale,
        double offset)
{
  idTriangles *v7; // r3
  idTriangles *v8; // r30
  float z; // r8
  __int64 v10; // r7
  double v11; // fp8
  double v12; // fp7
  double v13; // fp6
  double v14; // fp5
  double v15; // fp4
  double v16; // fp3
  double v17; // fp2
  idBounds *v18; // r3
  float v20; // [sp+8h] [-B8h]
  float v21; // [sp+Ch] [-B4h]
  float v22; // [sp+10h] [-B0h]
  float v23; // [sp+14h] [-ACh]
  float v24; // [sp+18h] [-A8h]
  float v25; // [sp+1Ch] [-A4h]
  float v26; // [sp+20h] [-A0h]
  float v27; // [sp+24h] [-9Ch]
  float v28; // [sp+28h] [-98h]
  float v29; // [sp+2Ch] [-94h]
  float v30; // [sp+30h] [-90h]
  float v31; // [sp+34h] [-8Ch]
  float v32; // [sp+38h] [-88h]
  float v33; // [sp+3Ch] [-84h]
  float v34; // [sp+40h] [-80h]
  float v35; // [sp+44h] [-7Ch]
  float v36; // [sp+48h] [-78h]
  float v37; // [sp+4Ch] [-74h]
  float v38; // [sp+50h] [-70h]
  float v39; // [sp+54h] [-6Ch]
  idTriangles *v40; // [sp+64h] [-5Ch] BYREF
  int v41; // [sp+70h] [-50h] BYREF
  int v42; // [sp+74h] [-4Ch]
  float v43; // [sp+78h] [-48h]

  v43 = offset;
  *(float *)&v41 = 0.0;
  *(float *)&v42 = 0.0;
  v7 = (idTriangles *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 0x84u,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v40 = v7;
  if ( v7 != nullptr )
    v8 = idTriangles::idTriangles(this: v7);
  else
    v8 = nullptr;
  v8->numVerts = 12;
  v8->numIndexes = 18;
  idTriangles::AllocStaticTriSurfVerts(this: v8, numVerts: 12);
  idTriangles::AllocStaticTriSurfIndexes(this: v8, numIndexes: v8->numIndexes);
  z = itemLog->loc.z;
  v10 = *(_QWORD *)&itemLog->loc.x;
  v40 = nullptr;
  idPlaytestStorage::CreateTriQuad(
    this,
    tris: v8,
    vertexIndex: (int *)&v40,
    indexIndex: (int *)HIDWORD(v10),
    loc: (const idVec3 *)v10,
    scale,
    offset: (const idVec3 *)__ROL4__(LODWORD(z), 32),
    a8: v41,
    a9: v42,
    a10: v17,
    a11: v16,
    a12: v15,
    a13: v14,
    a14: v13,
    a15: v12,
    a16: v11,
    a17: v20,
    a18: v21,
    a19: v22,
    a20: v23,
    a21: v24,
    a22: v25,
    a23: v26,
    a24: v27,
    a25: v28,
    a26: v29,
    a27: v30,
    a28: v31,
    a29: v32,
    a30: v33,
    a31: v34,
    a32: v35,
    a33: v36,
    a34: v37,
    a35: v38,
    a36: v39,
    a37: *(float *)&v41);
  v18 = idTriangles::BoundsFromVertScan(this: (idTriangles *)&v41, result: &v8->bounds);
  v40 = (idTriangles *)&v18->b[1];
  v8->bounds = *v18;
  return v8;
}


// ========================================================================
// __unwind$238390
// EA  : 0x8267EBE4
// RVA : 0x0067EBE4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_238390(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 192 + 100), tag: a2);
}


// ========================================================================
// ?PlayerUseFocus_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABV?$idList@VuseFocusInfo_t@idPlaytestStorage@@$04@@@Z
// EA  : 0x8267EC18
// RVA : 0x0067EC18
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idTriangles *__fastcall idPlaytestStorage::PlayerUseFocus_GenerateTriangles(
        idPlaytestStorage *this,
        const idList<idPlaytestStorage::useFocusInfo_t,5> *data)
{
  int v2; // r28
  idTriangles *result; // r3
  idTriangles *v6; // r3
  idTriangles *v7; // r30
  int i; // r11
  int v9; // r9
  double v10; // fp8
  double v11; // fp7
  double v12; // fp6
  double v13; // fp5
  double v14; // fp4
  double v15; // fp3
  double v16; // fp2
  int num; // r11
  int v18; // r27
  idPlaytestStorage::useFocusInfo_t *v19; // r11
  float z; // r7
  double v21; // fp11
  idBounds *v22; // r3
  float v23; // [sp+8h] [-E8h]
  float v24; // [sp+Ch] [-E4h]
  float v25; // [sp+10h] [-E0h]
  float v26; // [sp+14h] [-DCh]
  float v27; // [sp+18h] [-D8h]
  float v28; // [sp+1Ch] [-D4h]
  float v29; // [sp+20h] [-D0h]
  float v30; // [sp+24h] [-CCh]
  float v31; // [sp+28h] [-C8h]
  float v32; // [sp+2Ch] [-C4h]
  float v33; // [sp+30h] [-C0h]
  float v34; // [sp+34h] [-BCh]
  float v35; // [sp+38h] [-B8h]
  float v36; // [sp+3Ch] [-B4h]
  float v37; // [sp+40h] [-B0h]
  float v38; // [sp+44h] [-ACh]
  float v39; // [sp+48h] [-A8h]
  float v40; // [sp+4Ch] [-A4h]
  float v41; // [sp+50h] [-A0h]
  float v42; // [sp+54h] [-9Ch]
  float v43; // [sp+58h] [-98h]
  float v44; // [sp+5Ch] [-94h]
  int v45[3]; // [sp+74h] [-7Ch] BYREF
  float v46; // [sp+80h] [-70h] BYREF
  float v47; // [sp+84h] [-6Ch]
  float v48; // [sp+88h] [-68h]

  v2 = 0;
  result = nullptr;
  if ( data->num > 0 )
  {
    v6 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x84u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v45[0] = (int)v6;
    if ( v6 != nullptr )
      v7 = idTriangles::idTriangles(this: v6);
    else
      v7 = nullptr;
    v7->numVerts = 0;
    v7->numIndexes = 0;
    for ( i = 0; i < data->num; v7->numIndexes = v9 )
    {
      ++i;
      v9 = v7->numIndexes + 6;
      v7->numVerts += 5;
    }
    idTriangles::AllocStaticTriSurfVerts(this: v7, numVerts: v7->numVerts);
    idTriangles::AllocStaticTriSurfIndexes(this: v7, numIndexes: v7->numIndexes);
    num = data->num;
    v45[0] = 0;
    if ( num > 0 )
    {
      v18 = 0;
      do
      {
        v19 = &data->list[v18];
        v45[1] = (int)&v19->dir;
        z = v19->loc.z;
        v21 = (float)(v19->dir.y * (float)40.0);
        v46 = v19->dir.x * (float)40.0;
        v47 = v21;
        v48 = v19->dir.z * (float)40.0;
        idPlaytestStorage::CreateWedge(
          this,
          tris: v7,
          vertexIndex: v45,
          indexIndex: (int *)LODWORD(v19->loc.x),
          loc: (const idVec3 *)LODWORD(v19->loc.y),
          dir: __ROL4__(LODWORD(z), 32),
          width: 5.0,
          offset: LODWORD(v47),
          a9: v16,
          a10: v15,
          a11: v14,
          a12: v13,
          a13: v12,
          a14: v11,
          a15: v10,
          a16: v23,
          a17: v24,
          a18: v25,
          a19: v26,
          a20: v27,
          a21: v28,
          a22: v29,
          a23: v30,
          a24: v31,
          a25: v32,
          a26: v33,
          a27: v34,
          a28: v35,
          a29: v36,
          a30: v37,
          a31: v38,
          a32: v39,
          a33: v40,
          a34: v41,
          a35: v42,
          a36: v43,
          a37: v44,
          a38: vec3_origin.x,
          a39: vec3_origin.y,
          a40: vec3_origin.z);
        ++v2;
        ++v18;
      }
      while ( v2 < data->num );
    }
    v22 = idTriangles::BoundsFromVertScan(this: (idTriangles *)&v46, result: &v7->bounds);
    v45[1] = (int)&v22->b[1];
    v7->bounds = *v22;
    return v7;
  }
  return result;
}


// ========================================================================
// __unwind$238458
// EA  : 0x8267EE08
// RVA : 0x0067EE08
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_238458(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 240 + 116), tag: a2);
}


// ========================================================================
// ?PlayerUseQuickItem_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABVquickItemInfo_t@1@MM@Z
// EA  : 0x8267EE38
// RVA : 0x0067EE38
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idTriangles *__fastcall idPlaytestStorage::PlayerUseQuickItem_GenerateTriangles(
        idPlaytestStorage *this,
        const idPlaytestStorage::quickItemInfo_t *quickLog,
        double scale,
        double offset)
{
  idTriangles *v7; // r3
  idTriangles *v8; // r30
  float z; // r8
  __int64 v10; // r7
  double v11; // fp8
  double v12; // fp7
  double v13; // fp6
  double v14; // fp5
  double v15; // fp4
  double v16; // fp3
  double v17; // fp2
  idBounds *v18; // r3
  float v20; // [sp+8h] [-B8h]
  float v21; // [sp+Ch] [-B4h]
  float v22; // [sp+10h] [-B0h]
  float v23; // [sp+14h] [-ACh]
  float v24; // [sp+18h] [-A8h]
  float v25; // [sp+1Ch] [-A4h]
  float v26; // [sp+20h] [-A0h]
  float v27; // [sp+24h] [-9Ch]
  float v28; // [sp+28h] [-98h]
  float v29; // [sp+2Ch] [-94h]
  float v30; // [sp+30h] [-90h]
  float v31; // [sp+34h] [-8Ch]
  float v32; // [sp+38h] [-88h]
  float v33; // [sp+3Ch] [-84h]
  float v34; // [sp+40h] [-80h]
  float v35; // [sp+44h] [-7Ch]
  float v36; // [sp+48h] [-78h]
  float v37; // [sp+4Ch] [-74h]
  float v38; // [sp+50h] [-70h]
  float v39; // [sp+54h] [-6Ch]
  idTriangles *v40; // [sp+64h] [-5Ch] BYREF
  int v41; // [sp+70h] [-50h] BYREF
  int v42; // [sp+74h] [-4Ch]
  float v43; // [sp+78h] [-48h]

  *(float *)&v41 = 0.0;
  *(float *)&v42 = 0.0;
  v43 = (float)offset - (float)25.0;
  v7 = (idTriangles *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 0x84u,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v40 = v7;
  if ( v7 != nullptr )
    v8 = idTriangles::idTriangles(this: v7);
  else
    v8 = nullptr;
  v8->numVerts = 12;
  v8->numIndexes = 18;
  idTriangles::AllocStaticTriSurfVerts(this: v8, numVerts: 12);
  idTriangles::AllocStaticTriSurfIndexes(this: v8, numIndexes: v8->numIndexes);
  z = quickLog->loc.z;
  v10 = *(_QWORD *)&quickLog->loc.x;
  v40 = nullptr;
  idPlaytestStorage::CreateTriQuad(
    this,
    tris: v8,
    vertexIndex: (int *)&v40,
    indexIndex: (int *)HIDWORD(v10),
    loc: (const idVec3 *)v10,
    scale,
    offset: (const idVec3 *)__ROL4__(LODWORD(z), 32),
    a8: v41,
    a9: v42,
    a10: v17,
    a11: v16,
    a12: v15,
    a13: v14,
    a14: v13,
    a15: v12,
    a16: v11,
    a17: v20,
    a18: v21,
    a19: v22,
    a20: v23,
    a21: v24,
    a22: v25,
    a23: v26,
    a24: v27,
    a25: v28,
    a26: v29,
    a27: v30,
    a28: v31,
    a29: v32,
    a30: v33,
    a31: v34,
    a32: v35,
    a33: v36,
    a34: v37,
    a35: v38,
    a36: v39,
    a37: *(float *)&v41);
  v18 = idTriangles::BoundsFromVertScan(this: (idTriangles *)&v41, result: &v8->bounds);
  v40 = (idTriangles *)&v18->b[1];
  v8->bounds = *v18;
  return v8;
}


// ========================================================================
// __unwind$238556
// EA  : 0x8267EF80
// RVA : 0x0067EF80
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_238556(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 192 + 100), tag: a2);
}


// ========================================================================
// ?Death_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABV?$idList@VdeathInfo_t@idPlaytestStorage@@$04@@@Z
// EA  : 0x8267EFB0
// RVA : 0x0067EFB0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idTriangles *__fastcall idPlaytestStorage::Death_GenerateTriangles(
        idPlaytestStorage *this,
        const idList<idPlaytestStorage::deathInfo_t,5> *data)
{
  int v2; // r28
  idTriangles *result; // r3
  idTriangles *v6; // r3
  idTriangles *v7; // r30
  int i; // r11
  int v9; // r9
  double v10; // fp8
  double v11; // fp7
  double v12; // fp6
  double v13; // fp5
  double v14; // fp4
  double v15; // fp3
  double v16; // fp2
  int num; // r11
  int v18; // r27
  idBounds *v19; // r3
  float v20; // [sp+8h] [-D8h]
  float v21; // [sp+Ch] [-D4h]
  float v22; // [sp+10h] [-D0h]
  float v23; // [sp+14h] [-CCh]
  float v24; // [sp+18h] [-C8h]
  float v25; // [sp+1Ch] [-C4h]
  float v26; // [sp+20h] [-C0h]
  float v27; // [sp+24h] [-BCh]
  float v28; // [sp+28h] [-B8h]
  float v29; // [sp+2Ch] [-B4h]
  float v30; // [sp+30h] [-B0h]
  float v31; // [sp+34h] [-ACh]
  float v32; // [sp+38h] [-A8h]
  float v33; // [sp+3Ch] [-A4h]
  float v34; // [sp+40h] [-A0h]
  float v35; // [sp+44h] [-9Ch]
  float v36; // [sp+48h] [-98h]
  float v37; // [sp+4Ch] [-94h]
  float v38; // [sp+50h] [-90h]
  float v39; // [sp+54h] [-8Ch]
  idTriangles *v40; // [sp+64h] [-7Ch] BYREF
  int v41; // [sp+70h] [-70h] BYREF

  v2 = 0;
  result = nullptr;
  if ( data->num > 0 )
  {
    v6 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x84u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v40 = v6;
    if ( v6 != nullptr )
      v7 = idTriangles::idTriangles(this: v6);
    else
      v7 = nullptr;
    v7->numVerts = 0;
    v7->numIndexes = 0;
    for ( i = 0; i < data->num; v7->numIndexes = v9 )
    {
      ++i;
      v9 = v7->numIndexes + 18;
      v7->numVerts += 12;
    }
    idTriangles::AllocStaticTriSurfVerts(this: v7, numVerts: v7->numVerts);
    idTriangles::AllocStaticTriSurfIndexes(this: v7, numIndexes: v7->numIndexes);
    num = data->num;
    v40 = nullptr;
    if ( num > 0 )
    {
      v18 = 0;
      do
      {
        idPlaytestStorage::CreateTriQuad(
          this,
          tris: v7,
          vertexIndex: (int *)&v40,
          indexIndex: (int *)LODWORD(data->list[v18].loc.x),
          loc: (const idVec3 *)LODWORD(data->list[v18].loc.y),
          scale: 20.0,
          offset: (const idVec3 *)__ROL4__(*(_DWORD *)(LODWORD(vec3_origin.x) + 8), 32),
          a8: SLODWORD(vec3_origin.x),
          a9: SLODWORD(vec3_origin.y),
          a10: v16,
          a11: v15,
          a12: v14,
          a13: v13,
          a14: v12,
          a15: v11,
          a16: v10,
          a17: v20,
          a18: v21,
          a19: v22,
          a20: v23,
          a21: v24,
          a22: v25,
          a23: v26,
          a24: v27,
          a25: v28,
          a26: v29,
          a27: v30,
          a28: v31,
          a29: v32,
          a30: v33,
          a31: v34,
          a32: v35,
          a33: v36,
          a34: v37,
          a35: v38,
          a36: v39,
          a37: vec3_origin.z);
        ++v2;
        ++v18;
      }
      while ( v2 < data->num );
    }
    v19 = idTriangles::BoundsFromVertScan(this: (idTriangles *)&v41, result: &v7->bounds);
    v40 = (idTriangles *)&v19->b[1];
    v7->bounds = *v19;
    return v7;
  }
  return result;
}


// ========================================================================
// __unwind$238625_0
// EA  : 0x8267F154
// RVA : 0x0067F154
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_238625_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 224 + 100), tag: a2);
}


// ========================================================================
// ?WeaponFire_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABV?$idList@VweaponFireInfo_t@idPlaytestStorage@@$04@@@Z
// EA  : 0x8267F188
// RVA : 0x0067F188
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idTriangles *__fastcall idPlaytestStorage::WeaponFire_GenerateTriangles(
        idPlaytestStorage *this,
        const idList<idPlaytestStorage::weaponFireInfo_t,5> *data)
{
  int v2; // r28
  idTriangles *result; // r3
  idTriangles *v6; // r3
  idTriangles *v7; // r30
  int i; // r11
  int v9; // r9
  double v10; // fp8
  double v11; // fp7
  double v12; // fp6
  double v13; // fp5
  double v14; // fp4
  double v15; // fp3
  double v16; // fp2
  int num; // r11
  int v18; // r27
  idPlaytestStorage::weaponFireInfo_t *v19; // r11
  float z; // r8
  unsigned int attackerNum; // r10
  double v22; // fp11
  idBounds *v23; // r3
  float v24; // [sp+8h] [-F8h]
  float v25; // [sp+Ch] [-F4h]
  float v26; // [sp+10h] [-F0h]
  float v27; // [sp+14h] [-ECh]
  float v28; // [sp+18h] [-E8h]
  float v29; // [sp+1Ch] [-E4h]
  float v30; // [sp+20h] [-E0h]
  float v31; // [sp+24h] [-DCh]
  float v32; // [sp+28h] [-D8h]
  float v33; // [sp+2Ch] [-D4h]
  float v34; // [sp+30h] [-D0h]
  float v35; // [sp+34h] [-CCh]
  float v36; // [sp+38h] [-C8h]
  float v37; // [sp+3Ch] [-C4h]
  float v38; // [sp+40h] [-C0h]
  float v39; // [sp+44h] [-BCh]
  float v40; // [sp+48h] [-B8h]
  float v41; // [sp+4Ch] [-B4h]
  float v42; // [sp+50h] [-B0h]
  float v43; // [sp+54h] [-ACh]
  float v44; // [sp+58h] [-A8h]
  float v45; // [sp+5Ch] [-A4h]
  int v46[3]; // [sp+74h] [-8Ch] BYREF
  float x; // [sp+80h] [-80h]
  float y; // [sp+84h] [-7Ch]
  float v49; // [sp+88h] [-78h]
  float v50[2]; // [sp+90h] [-70h] BYREF
  float v51; // [sp+98h] [-68h]

  v2 = 0;
  result = nullptr;
  if ( data->num > 0 )
  {
    v6 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x84u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v46[0] = (int)v6;
    if ( v6 != nullptr )
      v7 = idTriangles::idTriangles(this: v6);
    else
      v7 = nullptr;
    v7->numVerts = 0;
    v7->numIndexes = 0;
    for ( i = 0; i < data->num; v7->numIndexes = v9 )
    {
      ++i;
      v9 = v7->numIndexes + 12;
      v7->numVerts += 8;
    }
    idTriangles::AllocStaticTriSurfVerts(this: v7, numVerts: v7->numVerts);
    idTriangles::AllocStaticTriSurfIndexes(this: v7, numIndexes: v7->numIndexes);
    num = data->num;
    v46[0] = 0;
    v18 = 0;
    if ( num > 0 )
    {
      do
      {
        v19 = &data->list[v2];
        z = vec3_origin.z;
        x = vec3_origin.x;
        attackerNum = v19->attackerNum;
        y = vec3_origin.y;
        if ( attackerNum <= 5 )
        {
          v49 = -30.0;
          z = -30.0;
        }
        v22 = (float)(v19->dir.y * (float)15.0);
        v50[0] = v19->dir.x * (float)15.0;
        v50[1] = v22;
        v51 = v19->dir.z * (float)15.0;
        v46[1] = (int)&v19->dir;
        idPlaytestStorage::CreateBlockWedge(
          this,
          tris: v7,
          vertexIndex: v46,
          indexIndex: (int *)LODWORD(v19->start.x),
          loc: (const idVec3 *)LODWORD(v19->start.y),
          offset: __SPAIR64__(LODWORD(x), __ROL4__(LODWORD(v51), 32)),
          width: 2.5,
          a8: v16,
          a9: v15,
          a10: v14,
          a11: v13,
          a12: v12,
          a13: v11,
          a14: v10,
          a15: v24,
          a16: v25,
          a17: v26,
          a18: v27,
          a19: v28,
          a20: v29,
          a21: v30,
          a22: v31,
          a23: v32,
          a24: v33,
          a25: v34,
          a26: v35,
          a27: v36,
          a28: v37,
          a29: v38,
          a30: v39,
          a31: v40,
          a32: v41,
          a33: v42,
          a34: v43,
          a35: v44,
          a36: v45,
          a37: x,
          a38: y,
          a39: z);
        ++v18;
        ++v2;
      }
      while ( v18 < data->num );
    }
    v23 = idTriangles::BoundsFromVertScan(this: (idTriangles *)v50, result: &v7->bounds);
    v46[1] = (int)&v23->b[1];
    v7->bounds = *v23;
    return v7;
  }
  return result;
}


// ========================================================================
// __unwind$238712
// EA  : 0x8267F3B4
// RVA : 0x0067F3B4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_238712(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 256 + 116), tag: a2);
}


// ========================================================================
// ?RadiusDamage_GenerateTriangles@idPlaytestStorage@@AAAPAVidTriangles@@ABV?$idList@VradiusDamageInfo_t@idPlaytestStorage@@$04@@@Z
// EA  : 0x8267F3E8
// RVA : 0x0067F3E8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idTriangles *__fastcall idPlaytestStorage::RadiusDamage_GenerateTriangles(
        idPlaytestStorage *this,
        const idList<idPlaytestStorage::radiusDamageInfo_t,5> *data)
{
  int v2; // r28
  idTriangles *result; // r3
  idTriangles *v6; // r3
  idTriangles *v7; // r30
  int i; // r11
  int v9; // r9
  double v10; // fp8
  double v11; // fp7
  double v12; // fp6
  double v13; // fp5
  double v14; // fp4
  double v15; // fp3
  double v16; // fp2
  int num; // r11
  int v18; // r27
  idBounds *v19; // r3
  float v20; // [sp+8h] [-C8h]
  float v21; // [sp+Ch] [-C4h]
  float v22; // [sp+10h] [-C0h]
  float v23; // [sp+14h] [-BCh]
  float v24; // [sp+18h] [-B8h]
  float v25; // [sp+1Ch] [-B4h]
  float v26; // [sp+20h] [-B0h]
  float v27; // [sp+24h] [-ACh]
  float v28; // [sp+28h] [-A8h]
  float v29; // [sp+2Ch] [-A4h]
  float v30; // [sp+30h] [-A0h]
  float v31; // [sp+34h] [-9Ch]
  float v32; // [sp+38h] [-98h]
  float v33; // [sp+3Ch] [-94h]
  float v34; // [sp+40h] [-90h]
  float v35; // [sp+44h] [-8Ch]
  float v36; // [sp+48h] [-88h]
  float v37; // [sp+4Ch] [-84h]
  float v38; // [sp+50h] [-80h]
  float v39; // [sp+54h] [-7Ch]
  idTriangles *v40; // [sp+64h] [-6Ch] BYREF
  int v41; // [sp+70h] [-60h] BYREF

  v2 = 0;
  result = nullptr;
  if ( data->num > 0 )
  {
    v6 = (idTriangles *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x84u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v40 = v6;
    if ( v6 != nullptr )
      v7 = idTriangles::idTriangles(this: v6);
    else
      v7 = nullptr;
    v7->numVerts = 0;
    v7->numIndexes = 0;
    for ( i = 0; i < data->num; v7->numIndexes = v9 )
    {
      ++i;
      v9 = v7->numIndexes + 18;
      v7->numVerts += 6;
    }
    idTriangles::AllocStaticTriSurfVerts(this: v7, numVerts: v7->numVerts);
    idTriangles::AllocStaticTriSurfIndexes(this: v7, numIndexes: v7->numIndexes);
    num = data->num;
    v40 = nullptr;
    if ( num > 0 )
    {
      v18 = 0;
      do
      {
        idPlaytestStorage::CreateSpehery(
          this,
          tris: v7,
          vertexIndex: (int *)&v40,
          indexIndex: (int *)LODWORD(data->list[v18].loc.x),
          loc: (const idVec3 *)LODWORD(data->list[v18].loc.y),
          radius: data->list[v18].radius,
          offset: (const idVec3 *)__ROL4__(LODWORD(data->list[v18].loc.z), 32),
          a8: SLODWORD(vec3_origin.x),
          a9: SLODWORD(vec3_origin.y),
          a10: v16,
          a11: v15,
          a12: v14,
          a13: v13,
          a14: v12,
          a15: v11,
          a16: v10,
          a17: v20,
          a18: v21,
          a19: v22,
          a20: v23,
          a21: v24,
          a22: v25,
          a23: v26,
          a24: v27,
          a25: v28,
          a26: v29,
          a27: v30,
          a28: v31,
          a29: v32,
          a30: v33,
          a31: v34,
          a32: v35,
          a33: v36,
          a34: v37,
          a35: v38,
          a36: v39,
          a37: vec3_origin.x);
        ++v2;
        ++v18;
      }
      while ( v2 < data->num );
    }
    v19 = idTriangles::BoundsFromVertScan(this: (idTriangles *)&v41, result: &v7->bounds);
    v40 = (idTriangles *)&v19->b[1];
    v7->bounds = *v19;
    return v7;
  }
  return result;
}


// ========================================================================
// __unwind$238810
// EA  : 0x8267F57C
// RVA : 0x0067F57C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall _unwind_238810(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 208 + 100), tag: a2);
}


// ========================================================================
// ?GeneratePlayerPathNormalModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82681170
// RVA : 0x00681170
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GeneratePlayerPathNormalModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  unsigned __int64 v4; // r30
  int v5; // r17
  int v6; // r25
  idPlaytestStorage::playerMainBreadCrumbInfo_t *list; // r11
  int v8; // r23
  int v9; // r26
  idTriangles *Triangles; // r3
  const idMaterial *v11; // r3
  int num; // r10
  int v13; // r29
  int v14; // r28
  idStaticModelSurface v15; // [sp+50h] [-120h] BYREF
  idStaticModelSurface v16; // [sp+A0h] [-D0h] BYREF

  if ( staticModels->num >= 1 )
  {
    LODWORD(v4) = 0;
    v5 = 0;
    if ( this->numPlayers > 0 )
    {
      v6 = 0;
      do
      {
        list = this->playerBreadCrumbs.list;
        v8 = 0;
        if ( this->playerBreadCrumbs.list[v6].normalBreadCrumbs.num > 0 )
        {
          v9 = 0;
          do
          {
            Triangles = idPlaytestStorage::PlayerPathNormal_GenerateTriangles(
                          this,
                          data: &list[v6].normalBreadCrumbs.list[v9].breadCrumbs);
            HIDWORD(v4) = Triangles;
            if ( Triangles != nullptr )
            {
              v16.skinOffsets.x = 0.0;
              v16.material = nullptr;
              v16.skinOffsets.y = 0.0;
              v16.materialNum = 0;
              v16.skinOffsets.z = 0.0;
              v16.extraGLState = v4;
              v16.skinOffsets.w = 0.0;
              v16.geometryIsReference = false;
              v16.referenceMask = 0;
              memset(&v16.binaryModelId, 0, 16);
              v16.skinRemaps.memTag = 5;
              v16.skinRemaps.listStatic = 0;
              memset(&v16.skinRemaps, 0, 14);
              v16.geometry = Triangles;
              v16.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                   this: &idMaterial::resourceList,
                                                   name: "textures/playtest/playerPath",
                                                   makeDefault: true);
              idStaticModel::AddSurface(this: *staticModels->list, surf: &v16);
              v15.skinOffsets.x = 0.0;
              v15.skinOffsets.y = 0.0;
              v15.material = nullptr;
              v15.skinOffsets.z = 0.0;
              v15.materialNum = 0;
              v15.skinOffsets.w = 0.0;
              v15.extraGLState = v4;
              v15.referenceMask = 0;
              memset(&v15.binaryModelId, 0, 16);
              v15.skinRemaps.memTag = 5;
              v15.skinRemaps.listStatic = 0;
              memset(&v15.skinRemaps, 0, 14);
              v15.geometry = (idTriangles *)HIDWORD(v4);
              v15.geometryIsReference = true;
              v11 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                          this: &idMaterial::resourceList,
                                          name: "textures/playtest/playerPath",
                                          makeDefault: true);
              num = staticModels->num;
              v15.material = v11;
              v13 = 1;
              if ( num > 1 )
              {
                v14 = 1;
                do
                {
                  idStaticModel::AddSurface(this: staticModels->list[v14], surf: &v15);
                  ++v13;
                  ++v14;
                }
                while ( v13 < staticModels->num );
              }
              if ( v15.skinRemaps.listStatic == 0 || v15.skinRemaps.listStatic == 2 )
              {
                if ( v15.skinRemaps.list != nullptr )
                  idMem::Free(this: &mem, ptr: v15.skinRemaps.list, align: ALIGN_16);
                v15.skinRemaps.list = nullptr;
                v15.skinRemaps.size = 0;
              }
              v15.skinRemaps.num = 0;
              if ( v16.skinRemaps.listStatic == 0 || v16.skinRemaps.listStatic == 2 )
              {
                if ( v16.skinRemaps.list != nullptr )
                  idMem::Free(this: &mem, ptr: v16.skinRemaps.list, align: ALIGN_16);
                v16.skinRemaps.list = nullptr;
                v16.skinRemaps.size = 0;
              }
              v16.skinRemaps.num = 0;
            }
            list = this->playerBreadCrumbs.list;
            ++v8;
            ++v9;
          }
          while ( v8 < this->playerBreadCrumbs.list[v6].normalBreadCrumbs.num );
        }
        ++v5;
        ++v6;
      }
      while ( v5 < this->numPlayers );
    }
  }
  else
  {
    idLib::Warning(fmt: "GeneratePlayerPathNormalModels empty argument");
  }
}


// ========================================================================
// __unwind$241998
// EA  : 0x826813E4
// RVA : 0x006813E4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_241998()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 368 + 160));
}


// ========================================================================
// __unwind$241999
// EA  : 0x8268140C
// RVA : 0x0068140C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_241999()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 368 + 80));
}


// ========================================================================
// ?GeneratePlayerPathMiscModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82681440
// RVA : 0x00681440
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GeneratePlayerPathMiscModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  unsigned __int64 v4; // r30
  int v5; // r17
  int v6; // r25
  idPlaytestStorage::playerMainBreadCrumbInfo_t *list; // r11
  int v8; // r22
  int v9; // r26
  idTriangles *Triangles; // r3
  skinRemap_t *v11; // r4
  int num; // r9
  int v13; // r28
  int v14; // r29
  idStaticModelSurface v15; // [sp+50h] [-120h] BYREF
  idStaticModelSurface v16; // [sp+A0h] [-D0h] BYREF

  if ( staticModels->num >= 1 )
  {
    LODWORD(v4) = 0;
    v5 = 0;
    if ( this->numPlayers > 0 )
    {
      v6 = 0;
      do
      {
        list = this->playerBreadCrumbs.list;
        v8 = 0;
        if ( this->playerBreadCrumbs.list[v6].miscBreadCrumbs.num > 0 )
        {
          v9 = 0;
          do
          {
            Triangles = idPlaytestStorage::PlayerPathMisc_GenerateTriangles(
                          this,
                          data: &list[v6].miscBreadCrumbs.list[v9].breadCrumbs);
            HIDWORD(v4) = Triangles;
            if ( Triangles != nullptr )
            {
              v15.skinOffsets.x = 0.0;
              v15.material = nullptr;
              v15.skinOffsets.y = 0.0;
              v15.materialNum = 0;
              v15.skinOffsets.z = 0.0;
              v15.extraGLState = v4;
              v15.skinOffsets.w = 0.0;
              v15.geometryIsReference = false;
              v15.referenceMask = 0;
              memset(&v15.binaryModelId, 0, 16);
              v15.skinRemaps.memTag = 5;
              v15.skinRemaps.listStatic = 0;
              memset(&v15.skinRemaps, 0, 14);
              v15.geometry = Triangles;
              v15.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                   this: &idMaterial::resourceList,
                                                   name: "textures/playtest/playerPath_misc",
                                                   makeDefault: true);
              idStaticModel::AddSurface(this: *staticModels->list, surf: &v15);
              v16.skinOffsets.x = 0.0;
              v16.skinOffsets.y = 0.0;
              v11 = nullptr;
              v16.skinOffsets.z = 0.0;
              v16.materialNum = 0;
              v16.skinOffsets.w = 0.0;
              v16.extraGLState = v4;
              v16.referenceMask = 0;
              memset(&v16.binaryModelId, 0, 16);
              v16.skinRemaps.listStatic = 0;
              memset(&v16.skinRemaps, 0, 14);
              v16.skinRemaps.memTag = 5;
              num = staticModels->num;
              v13 = 1;
              v16.geometryIsReference = true;
              v16.geometry = (idTriangles *)HIDWORD(v4);
              v16.material = v15.material;
              if ( num > 1 )
              {
                v14 = 1;
                do
                {
                  idStaticModel::AddSurface(this: staticModels->list[v14], surf: &v16);
                  ++v13;
                  ++v14;
                }
                while ( v13 < staticModels->num );
                v11 = v16.skinRemaps.list;
              }
              if ( v16.skinRemaps.listStatic == 0 || v16.skinRemaps.listStatic == 2 )
              {
                if ( v11 != nullptr )
                  idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
                v16.skinRemaps.list = nullptr;
                v16.skinRemaps.size = 0;
              }
              v16.skinRemaps.num = 0;
              if ( v15.skinRemaps.listStatic == 0 || v15.skinRemaps.listStatic == 2 )
              {
                if ( v15.skinRemaps.list != nullptr )
                  idMem::Free(this: &mem, ptr: v15.skinRemaps.list, align: ALIGN_16);
                v15.skinRemaps.list = nullptr;
                v15.skinRemaps.size = 0;
              }
              v15.skinRemaps.num = 0;
            }
            list = this->playerBreadCrumbs.list;
            ++v8;
            ++v9;
          }
          while ( v8 < this->playerBreadCrumbs.list[v6].miscBreadCrumbs.num );
        }
        ++v5;
        ++v6;
      }
      while ( v5 < this->numPlayers );
    }
  }
  else
  {
    idLib::Warning(fmt: "GeneratePlayerPathMiscModels empty argument");
  }
}


// ========================================================================
// __unwind$242332
// EA  : 0x826816A8
// RVA : 0x006816A8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_242332()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 368 + 80));
}


// ========================================================================
// __unwind$242333
// EA  : 0x826816D0
// RVA : 0x006816D0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_242333()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 368 + 160));
}


// ========================================================================
// ?GeneratePlayerPathVehicleModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82681700
// RVA : 0x00681700
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GeneratePlayerPathVehicleModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  unsigned __int64 v2; // r30
  int v5; // r15
  int v6; // r23
  idPlaytestStorage::playerMainBreadCrumbInfo_t *list; // r11
  int v8; // r20
  int v9; // r26
  idPlaytestStorage::playerMainBreadCrumbInfo_t *v10; // r11
  double v11; // fp1
  idTriangles *Triangles; // r3
  idTriangles *v13; // r28
  idPlaytestStorage::playerMainBreadCrumbInfo_t *v14; // r11
  const char *v15; // r4
  skinRemap_t *v16; // r4
  int num; // r9
  int v18; // r29
  int v19; // r28
  double v20; // fp1
  idPlaytestStorage::playerMainBreadCrumbInfo_t *v21; // r11
  idTriangles *v22; // r3
  skinRemap_t *v23; // r4
  int v24; // r9
  int v25; // r28
  idStaticModelSurface v26; // [sp+60h] [-1F0h] BYREF
  idStaticModelSurface v27; // [sp+B0h] [-1A0h] BYREF
  idStaticModelSurface v28; // [sp+100h] [-150h] BYREF
  idStaticModelSurface v29; // [sp+150h] [-100h] BYREF

  if ( staticModels->num >= 1 )
  {
    LODWORD(v2) = 0;
    v5 = 0;
    if ( this->numPlayers > 0 )
    {
      v6 = 0;
      do
      {
        list = this->playerBreadCrumbs.list;
        v8 = 0;
        if ( this->playerBreadCrumbs.list[v6].vehicleBreadCrumbs.num > 0 )
        {
          v9 = 0;
          do
          {
            v10 = &list[v6];
            v11 = 20.0;
            if ( v10->vehicleBreadCrumbs.list[v9].isRCBomb )
              v11 = 2.5;
            Triangles = idPlaytestStorage::PlayerPathVehicle_GenerateTriangles(
                          this,
                          data: &v10->vehicleBreadCrumbs.list[v9].breadCrumbs,
                          scale: v11);
            v13 = Triangles;
            if ( Triangles != nullptr )
            {
              v26.skinOffsets.x = 0.0;
              v26.material = nullptr;
              v26.skinOffsets.y = 0.0;
              v26.materialNum = 0;
              v26.skinOffsets.z = 0.0;
              v26.extraGLState = v2;
              v26.skinOffsets.w = 0.0;
              v26.geometryIsReference = false;
              v26.referenceMask = 0;
              memset(&v26.binaryModelId, 0, 16);
              v26.skinRemaps.memTag = 5;
              v26.skinRemaps.listStatic = 0;
              memset(&v26.skinRemaps, 0, 14);
              v14 = this->playerBreadCrumbs.list;
              v26.geometry = Triangles;
              if ( v14[v6].vehicleBreadCrumbs.list[v9].isRCBomb )
                v15 = "textures/playtest/playerPath_rcbomb";
              else
                v15 = "textures/playtest/playerPath_vehicle";
              v26.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                   this: &idMaterial::resourceList,
                                                   name: v15,
                                                   makeDefault: true);
              idStaticModel::AddSurface(this: *staticModels->list, surf: &v26);
              v28.skinOffsets.x = 0.0;
              v28.skinOffsets.y = 0.0;
              v16 = nullptr;
              v28.skinOffsets.z = 0.0;
              v28.materialNum = 0;
              v28.skinOffsets.w = 0.0;
              v28.extraGLState = v2;
              v28.referenceMask = 0;
              memset(&v28.binaryModelId, 0, 16);
              v28.skinRemaps.listStatic = 0;
              memset(&v28.skinRemaps, 0, 14);
              v28.skinRemaps.memTag = 5;
              num = staticModels->num;
              v18 = 1;
              v28.geometryIsReference = true;
              v28.geometry = v13;
              v28.material = v26.material;
              if ( num > 1 )
              {
                v19 = 1;
                do
                {
                  idStaticModel::AddSurface(this: staticModels->list[v19], surf: &v28);
                  ++v18;
                  ++v19;
                }
                while ( v18 < staticModels->num );
                v16 = v28.skinRemaps.list;
              }
              if ( v28.skinRemaps.listStatic == 0 || v28.skinRemaps.listStatic == 2 )
              {
                if ( v16 != nullptr )
                  idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
                v28.skinRemaps.list = nullptr;
                v28.skinRemaps.size = 0;
              }
              v28.skinRemaps.num = 0;
              if ( v26.skinRemaps.listStatic == 0 || v26.skinRemaps.listStatic == 2 )
              {
                if ( v26.skinRemaps.list != nullptr )
                  idMem::Free(this: &mem, ptr: v26.skinRemaps.list, align: ALIGN_16);
                v26.skinRemaps.list = nullptr;
                v26.skinRemaps.size = 0;
              }
              v26.skinRemaps.num = 0;
            }
            v20 = 35.0;
            v21 = &this->playerBreadCrumbs.list[v6];
            if ( v21->vehicleBreadCrumbs.list[v9].isRCBomb )
              v20 = 6.0;
            v22 = idPlaytestStorage::PlayerPathVehicleBoost_GenerateTriangles(
                    this,
                    data: &v21->vehicleBreadCrumbs.list[v9].breadCrumbs,
                    scale: v20);
            HIDWORD(v2) = v22;
            if ( v22 != nullptr )
            {
              v27.skinOffsets.x = 0.0;
              v27.material = nullptr;
              v27.skinOffsets.y = 0.0;
              v27.materialNum = 0;
              v27.skinOffsets.z = 0.0;
              v27.extraGLState = v2;
              v27.skinOffsets.w = 0.0;
              v27.geometryIsReference = false;
              v27.referenceMask = 0;
              memset(&v27.binaryModelId, 0, 16);
              v27.skinRemaps.memTag = 5;
              v27.skinRemaps.listStatic = 0;
              memset(&v27.skinRemaps, 0, 14);
              v27.geometry = v22;
              v27.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                   this: &idMaterial::resourceList,
                                                   name: "textures/playtest/vehicleBoost",
                                                   makeDefault: true);
              idStaticModel::AddSurface(this: *staticModels->list, surf: &v27);
              v29.skinOffsets.x = 0.0;
              v29.skinOffsets.y = 0.0;
              v23 = nullptr;
              v29.skinOffsets.z = 0.0;
              v29.materialNum = 0;
              v29.skinOffsets.w = 0.0;
              v29.extraGLState = v2;
              v29.referenceMask = 0;
              memset(&v29.binaryModelId, 0, 16);
              v29.skinRemaps.listStatic = 0;
              memset(&v29.skinRemaps, 0, 14);
              v29.skinRemaps.memTag = 5;
              v24 = staticModels->num;
              v25 = 1;
              v29.geometryIsReference = true;
              v29.geometry = (idTriangles *)HIDWORD(v2);
              v29.material = v27.material;
              if ( v24 > 1 )
              {
                HIDWORD(v2) = 4;
                do
                {
                  idStaticModel::AddSurface(
                    this: *(idStaticModel **)((char *)staticModels->list + HIDWORD(v2)),
                    surf: &v29);
                  ++v25;
                  HIDWORD(v2) += 4;
                }
                while ( v25 < staticModels->num );
                v23 = v29.skinRemaps.list;
              }
              if ( v29.skinRemaps.listStatic == 0 || v29.skinRemaps.listStatic == 2 )
              {
                if ( v23 != nullptr )
                  idMem::Free(this: &mem, ptr: v23, align: ALIGN_16);
                v29.skinRemaps.list = nullptr;
                v29.skinRemaps.size = 0;
              }
              v29.skinRemaps.num = 0;
              if ( v27.skinRemaps.listStatic == 0 || v27.skinRemaps.listStatic == 2 )
              {
                if ( v27.skinRemaps.list != nullptr )
                  idMem::Free(this: &mem, ptr: v27.skinRemaps.list, align: ALIGN_16);
                v27.skinRemaps.list = nullptr;
                v27.skinRemaps.size = 0;
              }
              v27.skinRemaps.num = 0;
            }
            list = this->playerBreadCrumbs.list;
            ++v8;
            ++v9;
          }
          while ( v8 < this->playerBreadCrumbs.list[v6].vehicleBreadCrumbs.num );
        }
        ++v5;
        ++v6;
      }
      while ( v5 < this->numPlayers );
    }
  }
  else
  {
    idLib::Warning(fmt: "GeneratePlayerPathVehicleModels empty argument");
  }
}


// ========================================================================
// __unwind$242653
// EA  : 0x82681BA8
// RVA : 0x00681BA8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_242653()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 592 + 96));
}


// ========================================================================
// __unwind$242654
// EA  : 0x82681BD0
// RVA : 0x00681BD0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_242654()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 592 + 256));
}


// ========================================================================
// __unwind$242655
// EA  : 0x82681BF8
// RVA : 0x00681BF8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_242655()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 592 + 176));
}


// ========================================================================
// __unwind$242656
// EA  : 0x82681C20
// RVA : 0x00681C20
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_242656()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 592 + 336));
}


// ========================================================================
// ?GeneratePlayerViewNormalModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82681C50
// RVA : 0x00681C50
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GeneratePlayerViewNormalModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  unsigned __int64 v4; // r30
  int v5; // r17
  int v6; // r25
  idPlaytestStorage::playerMainBreadCrumbInfo_t *list; // r11
  int v8; // r22
  int v9; // r26
  idTriangles *Triangles; // r3
  skinRemap_t *v11; // r4
  int num; // r9
  int v13; // r28
  int v14; // r29
  idStaticModelSurface v15; // [sp+50h] [-120h] BYREF
  idStaticModelSurface v16; // [sp+A0h] [-D0h] BYREF

  if ( staticModels->num >= 1 )
  {
    LODWORD(v4) = 0;
    v5 = 0;
    if ( this->numPlayers > 0 )
    {
      v6 = 0;
      do
      {
        list = this->playerBreadCrumbs.list;
        v8 = 0;
        if ( this->playerBreadCrumbs.list[v6].normalBreadCrumbs.num > 0 )
        {
          v9 = 0;
          do
          {
            Triangles = idPlaytestStorage::PlayerViewNormal_GenerateTriangles(
                          this,
                          data: &list[v6].normalBreadCrumbs.list[v9].breadCrumbs);
            HIDWORD(v4) = Triangles;
            if ( Triangles != nullptr )
            {
              v15.skinOffsets.x = 0.0;
              v15.material = nullptr;
              v15.skinOffsets.y = 0.0;
              v15.materialNum = 0;
              v15.skinOffsets.z = 0.0;
              v15.extraGLState = v4;
              v15.skinOffsets.w = 0.0;
              v15.geometryIsReference = false;
              v15.referenceMask = 0;
              memset(&v15.binaryModelId, 0, 16);
              v15.skinRemaps.memTag = 5;
              v15.skinRemaps.listStatic = 0;
              memset(&v15.skinRemaps, 0, 14);
              v15.geometry = Triangles;
              v15.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                   this: &idMaterial::resourceList,
                                                   name: "textures/playtest/playerView",
                                                   makeDefault: true);
              idStaticModel::AddSurface(this: *staticModels->list, surf: &v15);
              v16.skinOffsets.x = 0.0;
              v16.skinOffsets.y = 0.0;
              v11 = nullptr;
              v16.skinOffsets.z = 0.0;
              v16.materialNum = 0;
              v16.skinOffsets.w = 0.0;
              v16.extraGLState = v4;
              v16.referenceMask = 0;
              memset(&v16.binaryModelId, 0, 16);
              v16.skinRemaps.listStatic = 0;
              memset(&v16.skinRemaps, 0, 14);
              v16.skinRemaps.memTag = 5;
              num = staticModels->num;
              v13 = 1;
              v16.geometryIsReference = true;
              v16.geometry = (idTriangles *)HIDWORD(v4);
              v16.material = v15.material;
              if ( num > 1 )
              {
                v14 = 1;
                do
                {
                  idStaticModel::AddSurface(this: staticModels->list[v14], surf: &v16);
                  ++v13;
                  ++v14;
                }
                while ( v13 < staticModels->num );
                v11 = v16.skinRemaps.list;
              }
              if ( v16.skinRemaps.listStatic == 0 || v16.skinRemaps.listStatic == 2 )
              {
                if ( v11 != nullptr )
                  idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
                v16.skinRemaps.list = nullptr;
                v16.skinRemaps.size = 0;
              }
              v16.skinRemaps.num = 0;
              if ( v15.skinRemaps.listStatic == 0 || v15.skinRemaps.listStatic == 2 )
              {
                if ( v15.skinRemaps.list != nullptr )
                  idMem::Free(this: &mem, ptr: v15.skinRemaps.list, align: ALIGN_16);
                v15.skinRemaps.list = nullptr;
                v15.skinRemaps.size = 0;
              }
              v15.skinRemaps.num = 0;
            }
            list = this->playerBreadCrumbs.list;
            ++v8;
            ++v9;
          }
          while ( v8 < this->playerBreadCrumbs.list[v6].normalBreadCrumbs.num );
        }
        ++v5;
        ++v6;
      }
      while ( v5 < this->numPlayers );
    }
  }
  else
  {
    idLib::Warning(fmt: "GeneratePlayerViewNormalModels empty argument");
  }
}


// ========================================================================
// __unwind$243301
// EA  : 0x82681EB8
// RVA : 0x00681EB8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_243301()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 368 + 80));
}


// ========================================================================
// __unwind$243302
// EA  : 0x82681EE0
// RVA : 0x00681EE0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_243302()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 368 + 160));
}


// ========================================================================
// ?GeneratePlayerViewMiscModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82681F10
// RVA : 0x00681F10
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GeneratePlayerViewMiscModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  unsigned __int64 v4; // r30
  int v5; // r17
  int v6; // r25
  idPlaytestStorage::playerMainBreadCrumbInfo_t *list; // r11
  int v8; // r22
  int v9; // r26
  idTriangles *Triangles; // r3
  skinRemap_t *v11; // r4
  int num; // r9
  int v13; // r28
  int v14; // r29
  idStaticModelSurface v15; // [sp+50h] [-120h] BYREF
  idStaticModelSurface v16; // [sp+A0h] [-D0h] BYREF

  if ( staticModels->num >= 1 )
  {
    LODWORD(v4) = 0;
    v5 = 0;
    if ( this->numPlayers > 0 )
    {
      v6 = 0;
      do
      {
        list = this->playerBreadCrumbs.list;
        v8 = 0;
        if ( this->playerBreadCrumbs.list[v6].miscBreadCrumbs.num > 0 )
        {
          v9 = 0;
          do
          {
            Triangles = idPlaytestStorage::PlayerViewMisc_GenerateTriangles(
                          this,
                          data: &list[v6].miscBreadCrumbs.list[v9].breadCrumbs);
            HIDWORD(v4) = Triangles;
            if ( Triangles != nullptr )
            {
              v15.skinOffsets.x = 0.0;
              v15.material = nullptr;
              v15.skinOffsets.y = 0.0;
              v15.materialNum = 0;
              v15.skinOffsets.z = 0.0;
              v15.extraGLState = v4;
              v15.skinOffsets.w = 0.0;
              v15.geometryIsReference = false;
              v15.referenceMask = 0;
              memset(&v15.binaryModelId, 0, 16);
              v15.skinRemaps.memTag = 5;
              v15.skinRemaps.listStatic = 0;
              memset(&v15.skinRemaps, 0, 14);
              v15.geometry = Triangles;
              v15.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                   this: &idMaterial::resourceList,
                                                   name: "textures/playtest/playerView",
                                                   makeDefault: true);
              idStaticModel::AddSurface(this: *staticModels->list, surf: &v15);
              v16.skinOffsets.x = 0.0;
              v16.skinOffsets.y = 0.0;
              v11 = nullptr;
              v16.skinOffsets.z = 0.0;
              v16.materialNum = 0;
              v16.skinOffsets.w = 0.0;
              v16.extraGLState = v4;
              v16.referenceMask = 0;
              memset(&v16.binaryModelId, 0, 16);
              v16.skinRemaps.listStatic = 0;
              memset(&v16.skinRemaps, 0, 14);
              v16.skinRemaps.memTag = 5;
              num = staticModels->num;
              v13 = 1;
              v16.geometryIsReference = true;
              v16.geometry = (idTriangles *)HIDWORD(v4);
              v16.material = v15.material;
              if ( num > 1 )
              {
                v14 = 1;
                do
                {
                  idStaticModel::AddSurface(this: staticModels->list[v14], surf: &v16);
                  ++v13;
                  ++v14;
                }
                while ( v13 < staticModels->num );
                v11 = v16.skinRemaps.list;
              }
              if ( v16.skinRemaps.listStatic == 0 || v16.skinRemaps.listStatic == 2 )
              {
                if ( v11 != nullptr )
                  idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
                v16.skinRemaps.list = nullptr;
                v16.skinRemaps.size = 0;
              }
              v16.skinRemaps.num = 0;
              if ( v15.skinRemaps.listStatic == 0 || v15.skinRemaps.listStatic == 2 )
              {
                if ( v15.skinRemaps.list != nullptr )
                  idMem::Free(this: &mem, ptr: v15.skinRemaps.list, align: ALIGN_16);
                v15.skinRemaps.list = nullptr;
                v15.skinRemaps.size = 0;
              }
              v15.skinRemaps.num = 0;
            }
            list = this->playerBreadCrumbs.list;
            ++v8;
            ++v9;
          }
          while ( v8 < this->playerBreadCrumbs.list[v6].miscBreadCrumbs.num );
        }
        ++v5;
        ++v6;
      }
      while ( v5 < this->numPlayers );
    }
  }
  else
  {
    idLib::Warning(fmt: "GeneratePlayerViewMiscModels empty argument");
  }
}


// ========================================================================
// __unwind$243622
// EA  : 0x82682178
// RVA : 0x00682178
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_243622()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 368 + 80));
}


// ========================================================================
// __unwind$243623
// EA  : 0x826821A0
// RVA : 0x006821A0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_243623()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 368 + 160));
}


// ========================================================================
// ?GeneratePlayerViewVehicleModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x826821D0
// RVA : 0x006821D0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GeneratePlayerViewVehicleModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  unsigned __int64 v4; // r30
  int v5; // r17
  int v6; // r25
  idPlaytestStorage::playerMainBreadCrumbInfo_t *list; // r11
  int v8; // r22
  int v9; // r26
  idTriangles *Triangles; // r3
  skinRemap_t *v11; // r4
  int num; // r9
  int v13; // r28
  int v14; // r29
  idStaticModelSurface v15; // [sp+50h] [-120h] BYREF
  idStaticModelSurface v16; // [sp+A0h] [-D0h] BYREF

  if ( staticModels->num >= 1 )
  {
    LODWORD(v4) = 0;
    v5 = 0;
    if ( this->numPlayers > 0 )
    {
      v6 = 0;
      do
      {
        list = this->playerBreadCrumbs.list;
        v8 = 0;
        if ( this->playerBreadCrumbs.list[v6].vehicleBreadCrumbs.num > 0 )
        {
          v9 = 0;
          do
          {
            Triangles = idPlaytestStorage::AIViewVehicle_GenerateTriangles(
                          this,
                          data: (const idList<idPlaytestStorage::aiVehicleBreadCrumbInfo_t,5> *)&list[v6].vehicleBreadCrumbs.list[v9].breadCrumbs);
            HIDWORD(v4) = Triangles;
            if ( Triangles != nullptr )
            {
              v15.skinOffsets.x = 0.0;
              v15.material = nullptr;
              v15.skinOffsets.y = 0.0;
              v15.materialNum = 0;
              v15.skinOffsets.z = 0.0;
              v15.extraGLState = v4;
              v15.skinOffsets.w = 0.0;
              v15.geometryIsReference = false;
              v15.referenceMask = 0;
              memset(&v15.binaryModelId, 0, 16);
              v15.skinRemaps.memTag = 5;
              v15.skinRemaps.listStatic = 0;
              memset(&v15.skinRemaps, 0, 14);
              v15.geometry = Triangles;
              v15.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                   this: &idMaterial::resourceList,
                                                   name: "textures/playtest/playerView",
                                                   makeDefault: true);
              idStaticModel::AddSurface(this: *staticModels->list, surf: &v15);
              v16.skinOffsets.x = 0.0;
              v16.skinOffsets.y = 0.0;
              v11 = nullptr;
              v16.skinOffsets.z = 0.0;
              v16.materialNum = 0;
              v16.skinOffsets.w = 0.0;
              v16.extraGLState = v4;
              v16.referenceMask = 0;
              memset(&v16.binaryModelId, 0, 16);
              v16.skinRemaps.listStatic = 0;
              memset(&v16.skinRemaps, 0, 14);
              v16.skinRemaps.memTag = 5;
              num = staticModels->num;
              v13 = 1;
              v16.geometryIsReference = true;
              v16.geometry = (idTriangles *)HIDWORD(v4);
              v16.material = v15.material;
              if ( num > 1 )
              {
                v14 = 1;
                do
                {
                  idStaticModel::AddSurface(this: staticModels->list[v14], surf: &v16);
                  ++v13;
                  ++v14;
                }
                while ( v13 < staticModels->num );
                v11 = v16.skinRemaps.list;
              }
              if ( v16.skinRemaps.listStatic == 0 || v16.skinRemaps.listStatic == 2 )
              {
                if ( v11 != nullptr )
                  idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
                v16.skinRemaps.list = nullptr;
                v16.skinRemaps.size = 0;
              }
              v16.skinRemaps.num = 0;
              if ( v15.skinRemaps.listStatic == 0 || v15.skinRemaps.listStatic == 2 )
              {
                if ( v15.skinRemaps.list != nullptr )
                  idMem::Free(this: &mem, ptr: v15.skinRemaps.list, align: ALIGN_16);
                v15.skinRemaps.list = nullptr;
                v15.skinRemaps.size = 0;
              }
              v15.skinRemaps.num = 0;
            }
            list = this->playerBreadCrumbs.list;
            ++v8;
            ++v9;
          }
          while ( v8 < this->playerBreadCrumbs.list[v6].vehicleBreadCrumbs.num );
        }
        ++v5;
        ++v6;
      }
      while ( v5 < this->numPlayers );
    }
  }
  else
  {
    idLib::Warning(fmt: "GeneratePlayerViewVehicleModels empty argument");
  }
}


// ========================================================================
// __unwind$243943
// EA  : 0x82682438
// RVA : 0x00682438
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_243943()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 368 + 80));
}


// ========================================================================
// __unwind$243944
// EA  : 0x82682460
// RVA : 0x00682460
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_243944()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 368 + 160));
}


// ========================================================================
// ?GenerateAI2BreadCrumbModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82682490
// RVA : 0x00682490
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GenerateAI2BreadCrumbModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  unsigned __int64 v4; // r30
  int v5; // r14
  int v6; // r15
  int v7; // r16
  idPlaytestStorage::ai2Info_t *v8; // r23
  int v9; // r22
  idTriangles *Triangles; // r3
  skinRemap_t *list; // r4
  int num; // r9
  int v13; // r28
  int v14; // r29
  idTriangles *v15; // r3
  skinRemap_t *v16; // r4
  int v17; // r9
  int v18; // r28
  int v19; // r29
  idTriangles *v20; // r3
  skinRemap_t *v21; // r4
  int v22; // r9
  int v23; // r28
  int v24; // r29
  idStaticModelSurface v25; // [sp+50h] [-280h] BYREF
  idStaticModelSurface v26; // [sp+A0h] [-230h] BYREF
  idStaticModelSurface v27; // [sp+F0h] [-1E0h] BYREF
  idStaticModelSurface v28; // [sp+140h] [-190h] BYREF
  idStaticModelSurface v29; // [sp+190h] [-140h] BYREF
  idStaticModelSurface v30; // [sp+1E0h] [-F0h] BYREF

  if ( staticModels->num >= 1 )
  {
    LODWORD(v4) = 0;
    v5 = 0;
    if ( this->ai2Info.num > 0 )
    {
      v6 = 0;
      do
      {
        v7 = 0;
        v8 = &this->ai2Info.list[v6];
        if ( v8->breadCrumbs.num > 0 )
        {
          v9 = 0;
          do
          {
            Triangles = idPlaytestStorage::AIPathNormal_GenerateTriangles(
                          this,
                          data: &v8->breadCrumbs.list[v9],
                          doHostile: false);
            HIDWORD(v4) = Triangles;
            if ( Triangles != nullptr )
            {
              v27.skinOffsets.x = 0.0;
              v27.material = nullptr;
              v27.skinOffsets.y = 0.0;
              v27.materialNum = 0;
              v27.skinOffsets.z = 0.0;
              v27.extraGLState = v4;
              v27.skinOffsets.w = 0.0;
              v27.geometryIsReference = false;
              v27.referenceMask = 0;
              memset(&v27.binaryModelId, 0, 16);
              v27.skinRemaps.memTag = 5;
              v27.skinRemaps.listStatic = 0;
              memset(&v27.skinRemaps, 0, 14);
              v27.geometry = Triangles;
              v27.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                   this: &idMaterial::resourceList,
                                                   name: "textures/playtest/aiPath_nonHostile",
                                                   makeDefault: true);
              idStaticModel::AddSurface(this: *staticModels->list, surf: &v27);
              v28.skinOffsets.x = 0.0;
              v28.skinOffsets.y = 0.0;
              list = nullptr;
              v28.skinOffsets.z = 0.0;
              v28.materialNum = 0;
              v28.skinOffsets.w = 0.0;
              v28.extraGLState = v4;
              v28.referenceMask = 0;
              memset(&v28.binaryModelId, 0, 16);
              v28.skinRemaps.listStatic = 0;
              memset(&v28.skinRemaps, 0, 14);
              v28.skinRemaps.memTag = 5;
              num = staticModels->num;
              v13 = 1;
              v28.geometryIsReference = true;
              v28.geometry = (idTriangles *)HIDWORD(v4);
              v28.material = v27.material;
              if ( num > 1 )
              {
                v14 = 1;
                do
                {
                  idStaticModel::AddSurface(this: staticModels->list[v14], surf: &v28);
                  ++v13;
                  ++v14;
                }
                while ( v13 < staticModels->num );
                list = v28.skinRemaps.list;
              }
              if ( v28.skinRemaps.listStatic == 0 || v28.skinRemaps.listStatic == 2 )
              {
                if ( list != nullptr )
                  idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
                v28.skinRemaps.list = nullptr;
                v28.skinRemaps.size = 0;
              }
              v28.skinRemaps.num = 0;
              if ( v27.skinRemaps.listStatic == 0 || v27.skinRemaps.listStatic == 2 )
              {
                if ( v27.skinRemaps.list != nullptr )
                  idMem::Free(this: &mem, ptr: v27.skinRemaps.list, align: ALIGN_16);
                v27.skinRemaps.list = nullptr;
                v27.skinRemaps.size = 0;
              }
              v27.skinRemaps.num = 0;
            }
            v15 = idPlaytestStorage::AIPathNormal_GenerateTriangles(
                    this,
                    data: &v8->breadCrumbs.list[v9],
                    doHostile: true);
            HIDWORD(v4) = v15;
            if ( v15 != nullptr )
            {
              v26.skinOffsets.x = 0.0;
              v26.material = nullptr;
              v26.skinOffsets.y = 0.0;
              v26.materialNum = 0;
              v26.skinOffsets.z = 0.0;
              v26.extraGLState = v4;
              v26.skinOffsets.w = 0.0;
              v26.geometryIsReference = false;
              v26.referenceMask = 0;
              memset(&v26.binaryModelId, 0, 16);
              v26.skinRemaps.memTag = 5;
              v26.skinRemaps.listStatic = 0;
              memset(&v26.skinRemaps, 0, 14);
              v26.geometry = v15;
              v26.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                   this: &idMaterial::resourceList,
                                                   name: "textures/playtest/aiPath",
                                                   makeDefault: true);
              idStaticModel::AddSurface(this: *staticModels->list, surf: &v26);
              v29.skinOffsets.x = 0.0;
              v29.skinOffsets.y = 0.0;
              v16 = nullptr;
              v29.skinOffsets.z = 0.0;
              v29.materialNum = 0;
              v29.skinOffsets.w = 0.0;
              v29.extraGLState = v4;
              v29.referenceMask = 0;
              memset(&v29.binaryModelId, 0, 16);
              v29.skinRemaps.listStatic = 0;
              memset(&v29.skinRemaps, 0, 14);
              v29.skinRemaps.memTag = 5;
              v17 = staticModels->num;
              v18 = 1;
              v29.geometryIsReference = true;
              v29.geometry = (idTriangles *)HIDWORD(v4);
              v29.material = v26.material;
              if ( v17 > 1 )
              {
                v19 = 1;
                do
                {
                  idStaticModel::AddSurface(this: staticModels->list[v19], surf: &v29);
                  ++v18;
                  ++v19;
                }
                while ( v18 < staticModels->num );
                v16 = v29.skinRemaps.list;
              }
              if ( v29.skinRemaps.listStatic == 0 || v29.skinRemaps.listStatic == 2 )
              {
                if ( v16 != nullptr )
                  idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
                v29.skinRemaps.list = nullptr;
                v29.skinRemaps.size = 0;
              }
              v29.skinRemaps.num = 0;
              if ( v26.skinRemaps.listStatic == 0 || v26.skinRemaps.listStatic == 2 )
              {
                if ( v26.skinRemaps.list != nullptr )
                  idMem::Free(this: &mem, ptr: v26.skinRemaps.list, align: ALIGN_16);
                v26.skinRemaps.list = nullptr;
                v26.skinRemaps.size = 0;
              }
              v26.skinRemaps.num = 0;
            }
            v20 = idPlaytestStorage::AIViewNormal_GenerateTriangles(this, data: &v8->breadCrumbs.list[v9]);
            HIDWORD(v4) = v20;
            if ( v20 != nullptr )
            {
              v25.skinOffsets.x = 0.0;
              v25.material = nullptr;
              v25.skinOffsets.y = 0.0;
              v25.materialNum = 0;
              v25.skinOffsets.z = 0.0;
              v25.extraGLState = v4;
              v25.skinOffsets.w = 0.0;
              v25.geometryIsReference = false;
              v25.referenceMask = 0;
              memset(&v25.binaryModelId, 0, 16);
              v25.skinRemaps.memTag = 5;
              v25.skinRemaps.listStatic = 0;
              memset(&v25.skinRemaps, 0, 14);
              v25.geometry = v20;
              v25.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                   this: &idMaterial::resourceList,
                                                   name: "textures/playtest/playerView",
                                                   makeDefault: true);
              idStaticModel::AddSurface(this: *staticModels->list, surf: &v25);
              v30.skinOffsets.x = 0.0;
              v21 = nullptr;
              v30.skinOffsets.y = 0.0;
              v30.materialNum = 0;
              v30.skinOffsets.z = 0.0;
              v30.extraGLState = v4;
              v30.skinOffsets.w = 0.0;
              v30.referenceMask = 0;
              memset(&v30.binaryModelId, 0, 16);
              v30.skinRemaps.listStatic = 0;
              memset(&v30.skinRemaps, 0, 14);
              v30.skinRemaps.memTag = 5;
              v22 = staticModels->num;
              v23 = 1;
              v30.geometryIsReference = true;
              v30.geometry = (idTriangles *)HIDWORD(v4);
              v30.material = v25.material;
              if ( v22 > 1 )
              {
                v24 = 1;
                do
                {
                  idStaticModel::AddSurface(this: staticModels->list[v24], surf: &v30);
                  ++v23;
                  ++v24;
                }
                while ( v23 < staticModels->num );
                v21 = v30.skinRemaps.list;
              }
              if ( v30.skinRemaps.listStatic == 0 || v30.skinRemaps.listStatic == 2 )
              {
                if ( v21 != nullptr )
                  idMem::Free(this: &mem, ptr: v21, align: ALIGN_16);
                v30.skinRemaps.list = nullptr;
                v30.skinRemaps.size = 0;
              }
              v30.skinRemaps.num = 0;
              if ( v25.skinRemaps.listStatic == 0 || v25.skinRemaps.listStatic == 2 )
              {
                if ( v25.skinRemaps.list != nullptr )
                  idMem::Free(this: &mem, ptr: v25.skinRemaps.list, align: ALIGN_16);
                v25.skinRemaps.list = nullptr;
                v25.skinRemaps.size = 0;
              }
              v25.skinRemaps.num = 0;
            }
            ++v7;
            ++v9;
          }
          while ( v7 < v8->breadCrumbs.num );
        }
        ++v5;
        ++v6;
      }
      while ( v5 < this->ai2Info.num );
    }
  }
  else
  {
    idLib::Warning(fmt: "GenerateAI2BreadCrumbModels empty argument");
  }
}


// ========================================================================
// __unwind$244264
// EA  : 0x82682A20
// RVA : 0x00682A20
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_244264()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 720 + 240));
}


// ========================================================================
// __unwind$244265
// EA  : 0x82682A48
// RVA : 0x00682A48
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_244265()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 720 + 320));
}


// ========================================================================
// __unwind$244266
// EA  : 0x82682A70
// RVA : 0x00682A70
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_244266()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 720 + 160));
}


// ========================================================================
// __unwind$244267
// EA  : 0x82682A98
// RVA : 0x00682A98
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_244267()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 720 + 400));
}


// ========================================================================
// __unwind$244268
// EA  : 0x82682AC0
// RVA : 0x00682AC0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_244268()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 720 + 80));
}


// ========================================================================
// __unwind$244269
// EA  : 0x82682AE8
// RVA : 0x00682AE8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_244269()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 720 + 480));
}


// ========================================================================
// ?GenerateAIVehicleBreadCrumbModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82682B18
// RVA : 0x00682B18
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GenerateAIVehicleBreadCrumbModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  int v4; // r17
  int v5; // r20
  idPlaytestStorage::aiVehicleInfo_t *v6; // r11
  const idList<idPlaytestStorage::playerVehicleBreadCrumbInfo_t,5> *p_breadCrumbs; // r27
  const char *v8; // r4
  double v9; // fp31
  const idMaterial *v10; // r29
  idTriangles *Triangles; // r30
  int num; // r9
  int v13; // r30
  int v14; // r29
  idTriangles *v15; // r30
  int v16; // r9
  int v17; // r30
  int v18; // r29
  idStaticModelSurface v19; // [sp+50h] [-1D0h] BYREF
  idStaticModelSurface v20; // [sp+A0h] [-180h] BYREF
  idStaticModelSurface v21; // [sp+F0h] [-130h] BYREF
  idStaticModelSurface v22; // [sp+140h] [-E0h] BYREF

  if ( staticModels->num >= 1 )
  {
    v4 = 0;
    if ( this->aiVehicleInfo.num > 0 )
    {
      v5 = 0;
      do
      {
        v6 = &this->aiVehicleInfo.list[v5];
        if ( v6->breadCrumbs.num >= 1 )
        {
          p_breadCrumbs = (const idList<idPlaytestStorage::playerVehicleBreadCrumbInfo_t,5> *)&v6->breadCrumbs;
          if ( v6->breadCrumbs.list->isRCBomb )
          {
            v8 = "textures/playtest/aiPath_rcbomb";
            v9 = 2.5;
          }
          else
          {
            v8 = "textures/playtest/aiPath_vehicle";
            v9 = 20.0;
          }
          v10 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                      this: &idMaterial::resourceList,
                                      name: v8,
                                      makeDefault: true);
          Triangles = idPlaytestStorage::PlayerPathVehicle_GenerateTriangles(this, data: p_breadCrumbs, scale: v9);
          if ( Triangles != nullptr )
          {
            idStaticModelSurface::idStaticModelSurface(this: &v19);
            v19.geometry = Triangles;
            v19.material = v10;
            idStaticModel::AddSurface(this: *staticModels->list, surf: &v19);
            idStaticModelSurface::idStaticModelSurface(this: &v21);
            num = staticModels->num;
            v21.geometry = Triangles;
            v13 = 1;
            v21.geometryIsReference = true;
            v21.material = v19.material;
            if ( num > 1 )
            {
              v14 = 1;
              do
              {
                idStaticModel::AddSurface(this: staticModels->list[v14], surf: &v21);
                ++v13;
                ++v14;
              }
              while ( v13 < staticModels->num );
            }
            if ( v21.skinRemaps.listStatic == 0 || v21.skinRemaps.listStatic == 2 )
            {
              if ( v21.skinRemaps.list != nullptr )
                idMem::Free(this: &mem, ptr: v21.skinRemaps.list, align: ALIGN_16);
              v21.skinRemaps.list = nullptr;
              v21.skinRemaps.size = 0;
            }
            v21.skinRemaps.num = 0;
            if ( v19.skinRemaps.listStatic == 0 || v19.skinRemaps.listStatic == 2 )
            {
              if ( v19.skinRemaps.list != nullptr )
                idMem::Free(this: &mem, ptr: v19.skinRemaps.list, align: ALIGN_16);
              v19.skinRemaps.list = nullptr;
              v19.skinRemaps.size = 0;
            }
            v19.skinRemaps.num = 0;
          }
          v15 = idPlaytestStorage::AIViewVehicle_GenerateTriangles(
                  this,
                  data: (const idList<idPlaytestStorage::aiVehicleBreadCrumbInfo_t,5> *)p_breadCrumbs);
          if ( v15 != nullptr )
          {
            idStaticModelSurface::idStaticModelSurface(this: &v22);
            v22.geometry = v15;
            v22.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                 this: &idMaterial::resourceList,
                                                 name: "textures/playtest/playerView",
                                                 makeDefault: true);
            idStaticModel::AddSurface(this: *staticModels->list, surf: &v22);
            idStaticModelSurface::idStaticModelSurface(this: &v20);
            v16 = staticModels->num;
            v20.geometry = v15;
            v17 = 1;
            v20.geometryIsReference = true;
            v20.material = v22.material;
            if ( v16 > 1 )
            {
              v18 = 1;
              do
              {
                idStaticModel::AddSurface(this: staticModels->list[v18], surf: &v20);
                ++v17;
                ++v18;
              }
              while ( v17 < staticModels->num );
            }
            if ( v20.skinRemaps.listStatic == 0 || v20.skinRemaps.listStatic == 2 )
            {
              if ( v20.skinRemaps.list != nullptr )
                idMem::Free(this: &mem, ptr: v20.skinRemaps.list, align: ALIGN_16);
              v20.skinRemaps.list = nullptr;
              v20.skinRemaps.size = 0;
            }
            v20.skinRemaps.num = 0;
            if ( v22.skinRemaps.listStatic == 0 || v22.skinRemaps.listStatic == 2 )
            {
              if ( v22.skinRemaps.list != nullptr )
                idMem::Free(this: &mem, ptr: v22.skinRemaps.list, align: ALIGN_16);
              v22.skinRemaps.list = nullptr;
              v22.skinRemaps.size = 0;
            }
            v22.skinRemaps.num = 0;
          }
        }
        ++v4;
        ++v5;
      }
      while ( v4 < this->aiVehicleInfo.num );
    }
  }
  else
  {
    idLib::Warning(fmt: "GenerateAIVehicleBreadCrumbModels empty argument");
  }
}


// ========================================================================
// __unwind$245157
// EA  : 0x82682E24
// RVA : 0x00682E24
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_245157()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 544 + 80));
}


// ========================================================================
// __unwind$245158
// EA  : 0x82682E4C
// RVA : 0x00682E4C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_245158()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 544 + 240));
}


// ========================================================================
// __unwind$245159
// EA  : 0x82682E74
// RVA : 0x00682E74
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_245159()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 544 + 320));
}


// ========================================================================
// __unwind$245160
// EA  : 0x82682E9C
// RVA : 0x00682E9C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_245160()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 544 + 160));
}


// ========================================================================
// ?GeneratePlayerItemModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82682ED0
// RVA : 0x00682ED0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GeneratePlayerItemModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  unsigned __int64 v4; // r30
  int v5; // r17
  int i; // r24
  idList<idPlaytestStorage::itemInfo_t,5> *list; // r11
  double v8; // fp31
  int v9; // r26
  int v10; // r25
  char v11; // r11
  idTriangles *Triangles; // r28
  const char *v13; // r4
  const idMaterial *v14; // r3
  skinRemap_t *v15; // r4
  int num; // r9
  int v17; // r29
  int v18; // r28
  idStaticModelSurface v19; // [sp+50h] [-140h] BYREF
  idStaticModelSurface v20; // [sp+A0h] [-F0h] BYREF

  if ( staticModels->num < 1 )
  {
    idLib::Warning(fmt: "GeneratePlayerItemModels empty argument");
    return;
  }
  LODWORD(v4) = 0;
  v5 = 0;
  if ( this->numPlayers > 0 )
  {
    for ( i = 0; ; ++i )
    {
      list = this->playerItemInfo.list;
      v8 = 0.0;
      v9 = 0;
      if ( list[i].num > 0 )
        break;
LABEL_35:
      if ( ++v5 >= this->numPlayers )
        return;
    }
    v10 = 0;
    while ( 1 )
    {
      HIDWORD(v4) = &list[i].list[v10];
      if ( v9 < 1 )
        goto LABEL_14;
      if ( *(float *)(HIDWORD(v4) - 84) != *(float *)HIDWORD(v4)
        || *(float *)(HIDWORD(v4) - 80) != *(float *)(HIDWORD(v4) + 4)
        || (v11 = 1, *(float *)(HIDWORD(v4) - 76) != *(float *)(HIDWORD(v4) + 8)) )
      {
        v11 = 0;
      }
      if ( v11 != 0 )
        v8 = (float)((float)v8 + (float)10.0);
      else
LABEL_14:
        v8 = 0.0;
      Triangles = idPlaytestStorage::PlayerItem_GenerateTriangles(
                    this,
                    itemLog: (const idPlaytestStorage::itemInfo_t *)HIDWORD(v4),
                    scale: 5.0,
                    offset: v8);
      if ( Triangles == nullptr )
        goto LABEL_34;
      if ( *(_DWORD *)(HIDWORD(v4) + 48) != 0 )
      {
        v13 = *(const char **)(HIDWORD(v4) + 52);
        if ( v13 == nullptr )
        {
          v14 = nullptr;
          goto LABEL_19;
        }
      }
      else
      {
        v13 = "textures/playtest/playerItemNoIcon";
      }
      v14 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                  this: &idMaterial::resourceList,
                                  name: v13,
                                  makeDefault: true);
LABEL_19:
      v19.skinOffsets.x = 0.0;
      v19.materialNum = 0;
      v19.skinOffsets.y = 0.0;
      v19.extraGLState = v4;
      v19.skinOffsets.z = 0.0;
      v19.geometryIsReference = false;
      v19.skinOffsets.w = 0.0;
      v19.referenceMask = 0;
      memset(&v19.binaryModelId, 0, 16);
      v19.skinRemaps.memTag = 5;
      v19.skinRemaps.listStatic = 0;
      memset(&v19.skinRemaps, 0, 14);
      v19.geometry = Triangles;
      v19.material = v14;
      idStaticModel::AddSurface(this: *staticModels->list, surf: &v19);
      v20.skinOffsets.x = 0.0;
      v20.skinOffsets.y = 0.0;
      v15 = nullptr;
      v20.skinOffsets.z = 0.0;
      v20.materialNum = 0;
      v20.skinOffsets.w = 0.0;
      v20.extraGLState = v4;
      v20.referenceMask = 0;
      memset(&v20.binaryModelId, 0, 16);
      v20.skinRemaps.listStatic = 0;
      memset(&v20.skinRemaps, 0, 14);
      v20.skinRemaps.memTag = 5;
      num = staticModels->num;
      v17 = 1;
      v20.geometryIsReference = true;
      v20.geometry = Triangles;
      v20.material = v19.material;
      if ( num > 1 )
      {
        v18 = 1;
        do
        {
          idStaticModel::AddSurface(this: staticModels->list[v18], surf: &v20);
          ++v17;
          ++v18;
        }
        while ( v17 < staticModels->num );
        v15 = v20.skinRemaps.list;
      }
      if ( v20.skinRemaps.listStatic == 0 || v20.skinRemaps.listStatic == 2 )
      {
        if ( v15 != nullptr )
          idMem::Free(this: &mem, ptr: v15, align: ALIGN_16);
        v20.skinRemaps.list = nullptr;
        v20.skinRemaps.size = 0;
      }
      v20.skinRemaps.num = 0;
      if ( v19.skinRemaps.listStatic == 0 || v19.skinRemaps.listStatic == 2 )
      {
        if ( v19.skinRemaps.list != nullptr )
          idMem::Free(this: &mem, ptr: v19.skinRemaps.list, align: ALIGN_16);
        v19.skinRemaps.list = nullptr;
        v19.skinRemaps.size = 0;
      }
      v19.skinRemaps.num = 0;
LABEL_34:
      list = this->playerItemInfo.list;
      ++v9;
      ++v10;
      if ( v9 >= list[i].num )
        goto LABEL_35;
    }
  }
}


// ========================================================================
// __unwind$245494
// EA  : 0x826831CC
// RVA : 0x006831CC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_245494()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 400 + 80));
}


// ========================================================================
// __unwind$245495
// EA  : 0x826831F4
// RVA : 0x006831F4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_245495()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 400 + 160));
}


// ========================================================================
// ?GeneratePlayerUseFocusModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82683228
// RVA : 0x00683228
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GeneratePlayerUseFocusModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  int v4; // r21
  int v5; // r26
  idTriangles *Triangles; // r30
  int num; // r9
  int v8; // r30
  int v9; // r29
  idStaticModelSurface v10; // [sp+50h] [-100h] BYREF
  idStaticModelSurface v11[2]; // [sp+A0h] [-B0h] BYREF

  if ( staticModels->num >= 1 )
  {
    v4 = 0;
    if ( this->numPlayers > 0 )
    {
      v5 = 0;
      do
      {
        Triangles = idPlaytestStorage::PlayerUseFocus_GenerateTriangles(this, data: &this->playerUseFocusInfo.list[v5]);
        if ( Triangles != nullptr )
        {
          idStaticModelSurface::idStaticModelSurface(this: v11);
          v11[0].geometry = Triangles;
          v11[0].material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                  this: &idMaterial::resourceList,
                                                  name: "textures/playtest/playerUseFocus",
                                                  makeDefault: true);
          idStaticModel::AddSurface(this: *staticModels->list, surf: v11);
          idStaticModelSurface::idStaticModelSurface(this: &v10);
          num = staticModels->num;
          v10.geometry = Triangles;
          v8 = 1;
          v10.geometryIsReference = true;
          v10.material = v11[0].material;
          if ( num > 1 )
          {
            v9 = 1;
            do
            {
              idStaticModel::AddSurface(this: staticModels->list[v9], surf: &v10);
              ++v8;
              ++v9;
            }
            while ( v8 < staticModels->num );
          }
          if ( v10.skinRemaps.listStatic == 0 || v10.skinRemaps.listStatic == 2 )
          {
            if ( v10.skinRemaps.list != nullptr )
              idMem::Free(this: &mem, ptr: v10.skinRemaps.list, align: ALIGN_16);
            v10.skinRemaps.list = nullptr;
            v10.skinRemaps.size = 0;
          }
          v10.skinRemaps.num = 0;
          if ( v11[0].skinRemaps.listStatic == 0 || v11[0].skinRemaps.listStatic == 2 )
          {
            if ( v11[0].skinRemaps.list != nullptr )
              idMem::Free(this: &mem, ptr: v11[0].skinRemaps.list, align: ALIGN_16);
            v11[0].skinRemaps.list = nullptr;
            v11[0].skinRemaps.size = 0;
          }
          v11[0].skinRemaps.num = 0;
        }
        ++v4;
        ++v5;
      }
      while ( v4 < this->numPlayers );
    }
  }
  else
  {
    idLib::Warning(fmt: "GeneratePlayerUseFocusModels empty argument");
  }
}


// ========================================================================
// __unwind$245876
// EA  : 0x826833B8
// RVA : 0x006833B8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_245876()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 336 + 160));
}


// ========================================================================
// __unwind$245877
// EA  : 0x826833E0
// RVA : 0x006833E0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_245877()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 336 + 80));
}


// ========================================================================
// ?GeneratePlayerUseQuickItemModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82683410
// RVA : 0x00683410
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GeneratePlayerUseQuickItemModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  unsigned __int64 v4; // r30
  int v5; // r17
  int i; // r24
  idList<idPlaytestStorage::quickItemInfo_t,5> *list; // r11
  double v8; // fp31
  int v9; // r26
  int v10; // r25
  char v11; // r11
  idTriangles *Triangles; // r28
  const char *v13; // r4
  const idMaterial *v14; // r3
  skinRemap_t *v15; // r4
  int num; // r9
  int v17; // r29
  int v18; // r28
  idStaticModelSurface v19; // [sp+50h] [-140h] BYREF
  idStaticModelSurface v20; // [sp+A0h] [-F0h] BYREF

  if ( staticModels->num < 1 )
  {
    idLib::Warning(fmt: "GeneratePlayerUseQuickItemModels empty argument");
    return;
  }
  LODWORD(v4) = 0;
  v5 = 0;
  if ( this->numPlayers > 0 )
  {
    for ( i = 0; ; ++i )
    {
      list = this->playerUseQuickItemInfo.list;
      v8 = 0.0;
      v9 = 0;
      if ( list[i].num > 0 )
        break;
LABEL_35:
      if ( ++v5 >= this->numPlayers )
        return;
    }
    v10 = 0;
    while ( 1 )
    {
      HIDWORD(v4) = &list[i].list[v10];
      if ( v9 < 1 )
        goto LABEL_14;
      if ( *(float *)(HIDWORD(v4) - 80) != *(float *)HIDWORD(v4)
        || *(float *)(HIDWORD(v4) - 76) != *(float *)(HIDWORD(v4) + 4)
        || (v11 = 1, *(float *)(HIDWORD(v4) - 72) != *(float *)(HIDWORD(v4) + 8)) )
      {
        v11 = 0;
      }
      if ( v11 != 0 )
        v8 = (float)((float)v8 + (float)10.0);
      else
LABEL_14:
        v8 = 0.0;
      Triangles = idPlaytestStorage::PlayerUseQuickItem_GenerateTriangles(
                    this,
                    quickLog: (const idPlaytestStorage::quickItemInfo_t *)HIDWORD(v4),
                    scale: 5.0,
                    offset: v8);
      if ( Triangles == nullptr )
        goto LABEL_34;
      if ( *(_DWORD *)(HIDWORD(v4) + 44) != 0 )
      {
        v13 = *(const char **)(HIDWORD(v4) + 48);
        if ( v13 == nullptr )
        {
          v14 = nullptr;
          goto LABEL_19;
        }
      }
      else
      {
        v13 = "textures/playtest/playerQuickItemNoIcon";
      }
      v14 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                  this: &idMaterial::resourceList,
                                  name: v13,
                                  makeDefault: true);
LABEL_19:
      v19.skinOffsets.x = 0.0;
      v19.materialNum = 0;
      v19.skinOffsets.y = 0.0;
      v19.extraGLState = v4;
      v19.skinOffsets.z = 0.0;
      v19.geometryIsReference = false;
      v19.skinOffsets.w = 0.0;
      v19.referenceMask = 0;
      memset(&v19.binaryModelId, 0, 16);
      v19.skinRemaps.memTag = 5;
      v19.skinRemaps.listStatic = 0;
      memset(&v19.skinRemaps, 0, 14);
      v19.geometry = Triangles;
      v19.material = v14;
      idStaticModel::AddSurface(this: *staticModels->list, surf: &v19);
      v20.skinOffsets.x = 0.0;
      v20.skinOffsets.y = 0.0;
      v15 = nullptr;
      v20.skinOffsets.z = 0.0;
      v20.materialNum = 0;
      v20.skinOffsets.w = 0.0;
      v20.extraGLState = v4;
      v20.referenceMask = 0;
      memset(&v20.binaryModelId, 0, 16);
      v20.skinRemaps.listStatic = 0;
      memset(&v20.skinRemaps, 0, 14);
      v20.skinRemaps.memTag = 5;
      num = staticModels->num;
      v17 = 1;
      v20.geometryIsReference = true;
      v20.geometry = Triangles;
      v20.material = v19.material;
      if ( num > 1 )
      {
        v18 = 1;
        do
        {
          idStaticModel::AddSurface(this: staticModels->list[v18], surf: &v20);
          ++v17;
          ++v18;
        }
        while ( v17 < staticModels->num );
        v15 = v20.skinRemaps.list;
      }
      if ( v20.skinRemaps.listStatic == 0 || v20.skinRemaps.listStatic == 2 )
      {
        if ( v15 != nullptr )
          idMem::Free(this: &mem, ptr: v15, align: ALIGN_16);
        v20.skinRemaps.list = nullptr;
        v20.skinRemaps.size = 0;
      }
      v20.skinRemaps.num = 0;
      if ( v19.skinRemaps.listStatic == 0 || v19.skinRemaps.listStatic == 2 )
      {
        if ( v19.skinRemaps.list != nullptr )
          idMem::Free(this: &mem, ptr: v19.skinRemaps.list, align: ALIGN_16);
        v19.skinRemaps.list = nullptr;
        v19.skinRemaps.size = 0;
      }
      v19.skinRemaps.num = 0;
LABEL_34:
      list = this->playerUseQuickItemInfo.list;
      ++v9;
      ++v10;
      if ( v9 >= list[i].num )
        goto LABEL_35;
    }
  }
}


// ========================================================================
// __unwind$246055
// EA  : 0x8268370C
// RVA : 0x0068370C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_246055()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 400 + 80));
}


// ========================================================================
// __unwind$246056
// EA  : 0x82683734
// RVA : 0x00683734
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_246056()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 400 + 160));
}


// ========================================================================
// ?GeneratePlayerDeathModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82683768
// RVA : 0x00683768
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GeneratePlayerDeathModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  int i; // r23
  idTriangles *Triangles; // r30
  int num; // r9
  int v7; // r30
  int v8; // r29
  idStaticModelSurface v9; // [sp+50h] [-100h] BYREF
  idStaticModelSurface v10[2]; // [sp+A0h] [-B0h] BYREF

  if ( staticModels->num >= 1 )
  {
    for ( i = 0; i < 6; ++i )
    {
      Triangles = idPlaytestStorage::Death_GenerateTriangles(this, data: &this->playerDeathInfo.list[i]);
      if ( Triangles != nullptr )
      {
        idStaticModelSurface::idStaticModelSurface(this: v10);
        v10[0].geometry = Triangles;
        v10[0].material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                this: &idMaterial::resourceList,
                                                name: "textures/playtest/playerDeath",
                                                makeDefault: true);
        idStaticModel::AddSurface(this: *staticModels->list, surf: v10);
        idStaticModelSurface::idStaticModelSurface(this: &v9);
        num = staticModels->num;
        v9.geometry = Triangles;
        v7 = 1;
        v9.geometryIsReference = true;
        v9.material = v10[0].material;
        if ( num > 1 )
        {
          v8 = 1;
          do
          {
            idStaticModel::AddSurface(this: staticModels->list[v8], surf: &v9);
            ++v7;
            ++v8;
          }
          while ( v7 < staticModels->num );
        }
        if ( v9.skinRemaps.listStatic == 0 || v9.skinRemaps.listStatic == 2 )
        {
          if ( v9.skinRemaps.list != nullptr )
            idMem::Free(this: &mem, ptr: v9.skinRemaps.list, align: ALIGN_16);
          v9.skinRemaps.list = nullptr;
          v9.skinRemaps.size = 0;
        }
        v9.skinRemaps.num = 0;
        if ( v10[0].skinRemaps.listStatic == 0 || v10[0].skinRemaps.listStatic == 2 )
        {
          if ( v10[0].skinRemaps.list != nullptr )
            idMem::Free(this: &mem, ptr: v10[0].skinRemaps.list, align: ALIGN_16);
          v10[0].skinRemaps.list = nullptr;
          v10[0].skinRemaps.size = 0;
        }
        v10[0].skinRemaps.num = 0;
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "GeneratePlayerDeathModels empty argument");
  }
}


// ========================================================================
// __unwind$246435
// EA  : 0x826838E0
// RVA : 0x006838E0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_246435()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 336 + 160));
}


// ========================================================================
// __unwind$246436
// EA  : 0x82683908
// RVA : 0x00683908
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_246436()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 336 + 80));
}


// ========================================================================
// ?GenerateAIDeathModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82683938
// RVA : 0x00683938
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GenerateAIDeathModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  idTriangles *Triangles; // r30
  int num; // r7
  int v5; // r30
  int v6; // r28
  idStaticModelSurface v7; // [sp+50h] [-C0h] BYREF
  idStaticModelSurface v8; // [sp+A0h] [-70h] BYREF

  if ( staticModels->num >= 1 )
  {
    Triangles = idPlaytestStorage::Death_GenerateTriangles(this, data: &this->otherDeathInfo);
    if ( Triangles != nullptr )
    {
      idStaticModelSurface::idStaticModelSurface(this: &v8);
      v8.geometry = Triangles;
      v8.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                          this: &idMaterial::resourceList,
                                          name: "textures/playtest/aiDeath",
                                          makeDefault: true);
      idStaticModel::AddSurface(this: *staticModels->list, surf: &v8);
      idStaticModelSurface::idStaticModelSurface(this: &v7);
      num = staticModels->num;
      v7.geometry = Triangles;
      v5 = 1;
      v7.geometryIsReference = true;
      v7.material = v8.material;
      if ( num > 1 )
      {
        v6 = 1;
        do
        {
          idStaticModel::AddSurface(this: staticModels->list[v6], surf: &v7);
          ++v5;
          ++v6;
        }
        while ( v5 < staticModels->num );
      }
      if ( v7.skinRemaps.listStatic == 0 || v7.skinRemaps.listStatic == 2 )
      {
        if ( v7.skinRemaps.list != nullptr )
          idMem::Free(this: &mem, ptr: v7.skinRemaps.list, align: ALIGN_16);
        v7.skinRemaps.list = nullptr;
        v7.skinRemaps.size = 0;
      }
      v7.skinRemaps.num = 0;
      if ( (v8.skinRemaps.listStatic == 0 || v8.skinRemaps.listStatic == 2) && v8.skinRemaps.list != nullptr )
        idMem::Free(this: &mem, ptr: v8.skinRemaps.list, align: ALIGN_16);
    }
  }
  else
  {
    idLib::Warning(fmt: "GenerateAIDeathModels empty argument");
  }
}


// ========================================================================
// __unwind$246610
// EA  : 0x82683A80
// RVA : 0x00683A80
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_246610()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 272 + 160));
}


// ========================================================================
// __unwind$246611
// EA  : 0x82683AA8
// RVA : 0x00683AA8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_246611()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 272 + 80));
}


// ========================================================================
// ?GeneratePlayerWeaponFireModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82683AD8
// RVA : 0x00683AD8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GeneratePlayerWeaponFireModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  int i; // r23
  idTriangles *Triangles; // r30
  int num; // r9
  int v7; // r30
  int v8; // r29
  idStaticModelSurface v9; // [sp+50h] [-100h] BYREF
  idStaticModelSurface v10[2]; // [sp+A0h] [-B0h] BYREF

  if ( staticModels->num >= 1 )
  {
    for ( i = 0; i < 6; ++i )
    {
      Triangles = idPlaytestStorage::WeaponFire_GenerateTriangles(this, data: &this->playerWeaponFireInfo.list[i]);
      if ( Triangles != nullptr )
      {
        idStaticModelSurface::idStaticModelSurface(this: v10);
        v10[0].geometry = Triangles;
        v10[0].material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                                this: &idMaterial::resourceList,
                                                name: "textures/playtest/playerWeaponFire",
                                                makeDefault: true);
        idStaticModel::AddSurface(this: *staticModels->list, surf: v10);
        idStaticModelSurface::idStaticModelSurface(this: &v9);
        num = staticModels->num;
        v9.geometry = Triangles;
        v7 = 1;
        v9.geometryIsReference = true;
        v9.material = v10[0].material;
        if ( num > 1 )
        {
          v8 = 1;
          do
          {
            idStaticModel::AddSurface(this: staticModels->list[v8], surf: &v9);
            ++v7;
            ++v8;
          }
          while ( v7 < staticModels->num );
        }
        if ( v9.skinRemaps.listStatic == 0 || v9.skinRemaps.listStatic == 2 )
        {
          if ( v9.skinRemaps.list != nullptr )
            idMem::Free(this: &mem, ptr: v9.skinRemaps.list, align: ALIGN_16);
          v9.skinRemaps.list = nullptr;
          v9.skinRemaps.size = 0;
        }
        v9.skinRemaps.num = 0;
        if ( v10[0].skinRemaps.listStatic == 0 || v10[0].skinRemaps.listStatic == 2 )
        {
          if ( v10[0].skinRemaps.list != nullptr )
            idMem::Free(this: &mem, ptr: v10[0].skinRemaps.list, align: ALIGN_16);
          v10[0].skinRemaps.list = nullptr;
          v10[0].skinRemaps.size = 0;
        }
        v10[0].skinRemaps.num = 0;
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "GeneratePlayerWeaponFireModels empty argument");
  }
}


// ========================================================================
// __unwind$246775
// EA  : 0x82683C50
// RVA : 0x00683C50
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_246775()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 336 + 160));
}


// ========================================================================
// __unwind$246776
// EA  : 0x82683C78
// RVA : 0x00683C78
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_246776()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 336 + 80));
}


// ========================================================================
// ?GenerateAIWeaponFireModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82683CA8
// RVA : 0x00683CA8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GenerateAIWeaponFireModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  idTriangles *Triangles; // r30
  int num; // r7
  int v5; // r30
  int v6; // r28
  idStaticModelSurface v7; // [sp+50h] [-C0h] BYREF
  idStaticModelSurface v8; // [sp+A0h] [-70h] BYREF

  if ( staticModels->num >= 1 )
  {
    Triangles = idPlaytestStorage::WeaponFire_GenerateTriangles(this, data: &this->otherWeaponFireInfo);
    if ( Triangles != nullptr )
    {
      idStaticModelSurface::idStaticModelSurface(this: &v8);
      v8.geometry = Triangles;
      v8.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                          this: &idMaterial::resourceList,
                                          name: "textures/playtest/otherWeaponFire",
                                          makeDefault: true);
      idStaticModel::AddSurface(this: *staticModels->list, surf: &v8);
      idStaticModelSurface::idStaticModelSurface(this: &v7);
      num = staticModels->num;
      v7.geometry = Triangles;
      v5 = 1;
      v7.geometryIsReference = true;
      v7.material = v8.material;
      if ( num > 1 )
      {
        v6 = 1;
        do
        {
          idStaticModel::AddSurface(this: staticModels->list[v6], surf: &v7);
          ++v5;
          ++v6;
        }
        while ( v5 < staticModels->num );
      }
      if ( v7.skinRemaps.listStatic == 0 || v7.skinRemaps.listStatic == 2 )
      {
        if ( v7.skinRemaps.list != nullptr )
          idMem::Free(this: &mem, ptr: v7.skinRemaps.list, align: ALIGN_16);
        v7.skinRemaps.list = nullptr;
        v7.skinRemaps.size = 0;
      }
      v7.skinRemaps.num = 0;
      if ( (v8.skinRemaps.listStatic == 0 || v8.skinRemaps.listStatic == 2) && v8.skinRemaps.list != nullptr )
        idMem::Free(this: &mem, ptr: v8.skinRemaps.list, align: ALIGN_16);
    }
  }
  else
  {
    idLib::Warning(fmt: "GenerateAIWeaponFireModels empty argument");
  }
}


// ========================================================================
// __unwind$246948
// EA  : 0x82683DF0
// RVA : 0x00683DF0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_246948()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 272 + 160));
}


// ========================================================================
// __unwind$246949
// EA  : 0x82683E18
// RVA : 0x00683E18
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_246949()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 272 + 80));
}


// ========================================================================
// ?GenerateRadiusDamageModels@idPlaytestStorage@@QAAXABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x82683E48
// RVA : 0x00683E48
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GenerateRadiusDamageModels(
        idPlaytestStorage *this,
        const idList<idStaticModel *,5> *staticModels)
{
  idTriangles *Triangles; // r30
  int num; // r7
  int v5; // r30
  int v6; // r28
  idStaticModelSurface v7; // [sp+50h] [-C0h] BYREF
  idStaticModelSurface v8; // [sp+A0h] [-70h] BYREF

  if ( staticModels->num >= 1 )
  {
    Triangles = idPlaytestStorage::RadiusDamage_GenerateTriangles(this, data: &this->radiusDamageInfo);
    if ( Triangles != nullptr )
    {
      idStaticModelSurface::idStaticModelSurface(this: &v8);
      v8.geometry = Triangles;
      v8.material = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                          this: &idMaterial::resourceList,
                                          name: "textures/playtest/playerWeaponFire",
                                          makeDefault: true);
      idStaticModel::AddSurface(this: *staticModels->list, surf: &v8);
      idStaticModelSurface::idStaticModelSurface(this: &v7);
      num = staticModels->num;
      v7.geometry = Triangles;
      v5 = 1;
      v7.geometryIsReference = true;
      v7.material = v8.material;
      if ( num > 1 )
      {
        v6 = 1;
        do
        {
          idStaticModel::AddSurface(this: staticModels->list[v6], surf: &v7);
          ++v5;
          ++v6;
        }
        while ( v5 < staticModels->num );
      }
      if ( v7.skinRemaps.listStatic == 0 || v7.skinRemaps.listStatic == 2 )
      {
        if ( v7.skinRemaps.list != nullptr )
          idMem::Free(this: &mem, ptr: v7.skinRemaps.list, align: ALIGN_16);
        v7.skinRemaps.list = nullptr;
        v7.skinRemaps.size = 0;
      }
      v7.skinRemaps.num = 0;
      if ( (v8.skinRemaps.listStatic == 0 || v8.skinRemaps.listStatic == 2) && v8.skinRemaps.list != nullptr )
        idMem::Free(this: &mem, ptr: v8.skinRemaps.list, align: ALIGN_16);
    }
  }
  else
  {
    idLib::Warning(fmt: "GenerateRadiusDamageModels empty argument");
  }
}


// ========================================================================
// __unwind$247113
// EA  : 0x82683F90
// RVA : 0x00683F90
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247113()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 272 + 160));
}


// ========================================================================
// __unwind$247114
// EA  : 0x82683FB8
// RVA : 0x00683FB8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247114()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 272 + 80));
}


// ========================================================================
// ?Write_Models@idPlaytestStorage@@QAAXABVidStr@@@Z
// EA  : 0x82683FE8
// RVA : 0x00683FE8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::Write_Models(idPlaytestStorage *this, const idStr *filePath)
{
  idStr *v4; // r26
  size_t len; // r29
  idStr *v6; // r26
  size_t v7; // r29
  idStr *v8; // r26
  size_t v9; // r29
  idStr *v10; // r26
  size_t v11; // r29
  idStr *v12; // r26
  size_t v13; // r29
  idStr *v14; // r26
  size_t v15; // r29
  idStr *v16; // r26
  size_t v17; // r29
  idStr *v18; // r26
  size_t v19; // r29
  idStr *v20; // r26
  size_t v21; // r29
  idStr *v22; // r26
  size_t v23; // r29
  idStr *v24; // r26
  size_t v25; // r29
  idStr *v26; // r26
  size_t v27; // r29
  idStr *v28; // r26
  size_t v29; // r29
  idStr *v30; // r26
  size_t v31; // r29
  idStr *v32; // r26
  size_t v33; // r29
  idStr *v34; // r26
  size_t v35; // r29
  idStr *v36; // r27
  size_t v37; // r29
  encounterGroupRole_t v38[4]; // [sp+50h] [-1E30h] BYREF
  idList<enum encounterGroupRole_t,5> v39; // [sp+60h] [-1E20h] BYREF
  idStr v40; // [sp+70h] [-1E10h] BYREF
  idStr v41; // [sp+90h] [-1DF0h] BYREF
  idStr v42; // [sp+B0h] [-1DD0h] BYREF
  idStr v43; // [sp+D0h] [-1DB0h] BYREF
  idStr v44; // [sp+F0h] [-1D90h] BYREF
  idStr v45; // [sp+110h] [-1D70h] BYREF
  idStr v46; // [sp+130h] [-1D50h] BYREF
  idStr v47; // [sp+150h] [-1D30h] BYREF
  idStr v48; // [sp+170h] [-1D10h] BYREF
  idStr v49; // [sp+190h] [-1CF0h] BYREF
  idStr v50; // [sp+1B0h] [-1CD0h] BYREF
  idStr v51; // [sp+1D0h] [-1CB0h] BYREF
  idStr v52; // [sp+1F0h] [-1C90h] BYREF
  idStr v53; // [sp+210h] [-1C70h] BYREF
  idStr v54; // [sp+230h] [-1C50h] BYREF
  idStr v55; // [sp+250h] [-1C30h] BYREF
  idStr v56; // [sp+270h] [-1C10h] BYREF
  idStr v57; // [sp+290h] [-1BF0h] BYREF
  idStaticModel v58; // [sp+2B0h] [-1BD0h] BYREF
  idStaticModel v59; // [sp+450h] [-1A30h] BYREF
  idStaticModel v60; // [sp+5F0h] [-1890h] BYREF
  idStaticModel v61; // [sp+790h] [-16F0h] BYREF
  idStaticModel v62; // [sp+930h] [-1550h] BYREF
  idStaticModel v63; // [sp+AD0h] [-13B0h] BYREF
  idStaticModel v64; // [sp+C70h] [-1210h] BYREF
  idStaticModel v65; // [sp+E10h] [-1070h] BYREF
  idStaticModel v66; // [sp+FB0h] [-ED0h] BYREF
  idStaticModel v67; // [sp+1150h] [-D30h] BYREF
  idStaticModel v68; // [sp+12F0h] [-B90h] BYREF
  idStaticModel v69; // [sp+1490h] [-9F0h] BYREF
  idStaticModel v70; // [sp+1630h] [-850h] BYREF
  idStaticModel v71; // [sp+17D0h] [-6B0h] BYREF
  idStaticModel v72; // [sp+1970h] [-510h] BYREF
  idStaticModel v73; // [sp+1B10h] [-370h] BYREF
  idStaticModel v74; // [sp+1CB0h] [-1D0h] BYREF

  v40.len = 0;
  v40.allocedAndFlag = 20;
  v40.data = v40.baseBuffer;
  v40.baseBuffer[0] = 0;
  v4 = operator+(result: &v55, a: filePath, b: "_Combined");
  len = v4->len;
  idStr::EnsureAlloced(this: &v40, amount: v4->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v4->data, Size: len);
  v40.data[len] = 0;
  v40.len = len;
  idStr::FreeData(this: &v55);
  idStaticModel::idStaticModel(this: &v58);
  idResource::SetName(this: &v58, _name: v40.data);
  v6 = operator+(result: &v50, a: filePath, b: "_PlayerPath");
  v7 = v6->len;
  idStr::EnsureAlloced(this: &v40, amount: v6->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v6->data, Size: v7);
  v40.data[v7] = 0;
  v40.len = v7;
  idStr::FreeData(this: &v50);
  idStaticModel::idStaticModel(this: &v60);
  idResource::SetName(this: &v60, _name: v40.data);
  v8 = operator+(result: &v44, a: filePath, b: "_PlayerPath_Normal");
  v9 = v8->len;
  idStr::EnsureAlloced(this: &v40, amount: v8->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v8->data, Size: v9);
  v40.data[v9] = 0;
  v40.len = v9;
  idStr::FreeData(this: &v44);
  idStaticModel::idStaticModel(this: &v74);
  idResource::SetName(this: &v74, _name: v40.data);
  v10 = operator+(result: &v54, a: filePath, b: "_PlayerPath_Misc");
  v11 = v10->len;
  idStr::EnsureAlloced(this: &v40, amount: v10->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v10->data, Size: v11);
  v40.data[v11] = 0;
  v40.len = v11;
  idStr::FreeData(this: &v54);
  idStaticModel::idStaticModel(this: &v72);
  idResource::SetName(this: &v72, _name: v40.data);
  v12 = operator+(result: &v46, a: filePath, b: "_PlayerPath_Vehicle");
  v13 = v12->len;
  idStr::EnsureAlloced(this: &v40, amount: v12->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v12->data, Size: v13);
  v40.data[v13] = 0;
  v40.len = v13;
  idStr::FreeData(this: &v46);
  idStaticModel::idStaticModel(this: &v70);
  idResource::SetName(this: &v70, _name: v40.data);
  v14 = operator+(result: &v52, a: filePath, b: "_AIPath");
  v15 = v14->len;
  idStr::EnsureAlloced(this: &v40, amount: v14->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v14->data, Size: v15);
  v40.data[v15] = 0;
  v40.len = v15;
  idStr::FreeData(this: &v52);
  idStaticModel::idStaticModel(this: &v63);
  idResource::SetName(this: &v63, _name: v40.data);
  v16 = operator+(result: &v48, a: filePath, b: "_AIPath_Foot");
  v17 = v16->len;
  idStr::EnsureAlloced(this: &v40, amount: v16->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v16->data, Size: v17);
  v40.data[v17] = 0;
  v40.len = v17;
  idStr::FreeData(this: &v48);
  idStaticModel::idStaticModel(this: &v68);
  idResource::SetName(this: &v68, _name: v40.data);
  v18 = operator+(result: &v56, a: filePath, b: "_AIPath_Vehicle");
  v19 = v18->len;
  idStr::EnsureAlloced(this: &v40, amount: v18->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v18->data, Size: v19);
  v40.data[v19] = 0;
  v40.len = v19;
  idStr::FreeData(this: &v56);
  idStaticModel::idStaticModel(this: &v66);
  idResource::SetName(this: &v66, _name: v40.data);
  v20 = operator+(result: &v42, a: filePath, b: "_PlayerItems");
  v21 = v20->len;
  idStr::EnsureAlloced(this: &v40, amount: v20->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v20->data, Size: v21);
  v40.data[v21] = 0;
  v40.len = v21;
  idStr::FreeData(this: &v42);
  idStaticModel::idStaticModel(this: &v65);
  idResource::SetName(this: &v65, _name: v40.data);
  v22 = operator+(result: &v43, a: filePath, b: "_PlayerUse");
  v23 = v22->len;
  idStr::EnsureAlloced(this: &v40, amount: v22->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v22->data, Size: v23);
  v40.data[v23] = 0;
  v40.len = v23;
  idStr::FreeData(this: &v43);
  idStaticModel::idStaticModel(this: &v62);
  idResource::SetName(this: &v62, _name: v40.data);
  v24 = operator+(result: &v45, a: filePath, b: "_PlayerDeath");
  v25 = v24->len;
  idStr::EnsureAlloced(this: &v40, amount: v24->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v24->data, Size: v25);
  v40.data[v25] = 0;
  v40.len = v25;
  idStr::FreeData(this: &v45);
  idStaticModel::idStaticModel(this: &v69);
  idResource::SetName(this: &v69, _name: v40.data);
  v26 = operator+(result: &v47, a: filePath, b: "_AIDeath");
  v27 = v26->len;
  idStr::EnsureAlloced(this: &v40, amount: v26->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v26->data, Size: v27);
  v40.data[v27] = 0;
  v40.len = v27;
  idStr::FreeData(this: &v47);
  idStaticModel::idStaticModel(this: &v71);
  idResource::SetName(this: &v71, _name: v40.data);
  v28 = operator+(result: &v49, a: filePath, b: "_Death");
  v29 = v28->len;
  idStr::EnsureAlloced(this: &v40, amount: v28->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v28->data, Size: v29);
  v40.data[v29] = 0;
  v40.len = v29;
  idStr::FreeData(this: &v49);
  idStaticModel::idStaticModel(this: &v61);
  idResource::SetName(this: &v61, _name: v40.data);
  v30 = operator+(result: &v51, a: filePath, b: "_PlayerWeaponFire");
  v31 = v30->len;
  idStr::EnsureAlloced(this: &v40, amount: v30->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v30->data, Size: v31);
  v40.data[v31] = 0;
  v40.len = v31;
  idStr::FreeData(this: &v51);
  idStaticModel::idStaticModel(this: &v64);
  idResource::SetName(this: &v64, _name: v40.data);
  v32 = operator+(result: &v53, a: filePath, b: "_OtherWeaponFire");
  v33 = v32->len;
  idStr::EnsureAlloced(this: &v40, amount: v32->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v32->data, Size: v33);
  v40.data[v33] = 0;
  v40.len = v33;
  idStr::FreeData(this: &v53);
  idStaticModel::idStaticModel(this: &v73);
  idResource::SetName(this: &v73, _name: v40.data);
  v34 = operator+(result: &v41, a: filePath, b: "_RadiusDamage");
  v35 = v34->len;
  idStr::EnsureAlloced(this: &v40, amount: v34->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v34->data, Size: v35);
  v40.data[v35] = 0;
  v40.len = v35;
  idStr::FreeData(this: &v41);
  idStaticModel::idStaticModel(this: &v67);
  idResource::SetName(this: &v67, _name: v40.data);
  v36 = operator+(result: &v57, a: filePath, b: "_WeaponFire");
  v37 = v36->len;
  idStr::EnsureAlloced(this: &v40, amount: v36->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v40.data, Src: v36->data, Size: v37);
  v40.data[v37] = 0;
  v40.len = v37;
  idStr::FreeData(this: &v57);
  idStaticModel::idStaticModel(this: &v59);
  idResource::SetName(this: &v59, _name: v40.data);
  memset(&v39, 0, 14);
  *(_WORD *)&v39.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  v38[0] = (encounterGroupRole_t)&v58;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v60;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v74;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  idPlaytestStorage::GeneratePlayerPathNormalModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idPlaytestStorage::GeneratePlayerViewNormalModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  memset(&v39, 0, 14);
  *(_WORD *)&v39.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  v38[0] = (encounterGroupRole_t)&v58;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v60;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v72;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  idPlaytestStorage::GeneratePlayerPathMiscModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idPlaytestStorage::GeneratePlayerViewMiscModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  memset(&v39, 0, 14);
  *(_WORD *)&v39.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  v38[0] = (encounterGroupRole_t)&v58;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v60;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v70;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  idPlaytestStorage::GeneratePlayerPathVehicleModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idPlaytestStorage::GeneratePlayerViewVehicleModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  memset(&v39, 0, 14);
  *(_WORD *)&v39.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  v38[0] = (encounterGroupRole_t)&v58;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v63;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v68;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  idPlaytestStorage::GenerateAI2BreadCrumbModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  memset(&v39, 0, 14);
  *(_WORD *)&v39.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  v38[0] = (encounterGroupRole_t)&v58;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v63;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v66;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  idPlaytestStorage::GenerateAIVehicleBreadCrumbModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  memset(&v39, 0, 14);
  *(_WORD *)&v39.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  v38[0] = (encounterGroupRole_t)&v58;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v65;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  idPlaytestStorage::GeneratePlayerItemModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  memset(&v39, 0, 14);
  *(_WORD *)&v39.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  v38[0] = (encounterGroupRole_t)&v58;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v62;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  idPlaytestStorage::GeneratePlayerUseFocusModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  memset(&v39, 0, 14);
  *(_WORD *)&v39.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  v38[0] = (encounterGroupRole_t)&v58;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v62;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  idPlaytestStorage::GeneratePlayerUseQuickItemModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  memset(&v39, 0, 14);
  *(_WORD *)&v39.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  v38[0] = (encounterGroupRole_t)&v58;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v61;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v69;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  idPlaytestStorage::GeneratePlayerDeathModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  memset(&v39, 0, 14);
  *(_WORD *)&v39.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  v38[0] = (encounterGroupRole_t)&v58;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v61;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v71;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  idPlaytestStorage::GenerateAIDeathModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  memset(&v39, 0, 14);
  *(_WORD *)&v39.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  v38[0] = (encounterGroupRole_t)&v58;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v59;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v64;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  idPlaytestStorage::GeneratePlayerWeaponFireModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  memset(&v39, 0, 14);
  *(_WORD *)&v39.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  v38[0] = (encounterGroupRole_t)&v58;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v59;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v73;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  idPlaytestStorage::GenerateAIWeaponFireModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  memset(&v39, 0, 14);
  *(_WORD *)&v39.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  v38[0] = (encounterGroupRole_t)&v58;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v59;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  v38[0] = (encounterGroupRole_t)&v67;
  idList<idAnimWebBlendTree *,5>::Append(this: &v39, obj: v38);
  idPlaytestStorage::GenerateRadiusDamageModels(this, staticModels: (const idList<idStaticModel *,5> *)&v39);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v39);
  if ( v58.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v58);
  if ( v60.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v60);
  if ( v74.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v74);
  if ( v72.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v72);
  if ( v70.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v70);
  if ( v63.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v63);
  if ( v68.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v68);
  if ( v66.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v66);
  if ( v65.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v65);
  if ( v62.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v62);
  if ( v69.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v69);
  if ( v71.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v71);
  if ( v61.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v61);
  if ( v64.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v64);
  if ( v73.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v73);
  if ( v67.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v67);
  if ( v59.surfaces.num > 0 )
    idStaticModel::WriteStaticModel(this: &v59);
  idStaticModel::~idStaticModel(this: &v59);
  idStaticModel::~idStaticModel(this: &v67);
  idStaticModel::~idStaticModel(this: &v73);
  idStaticModel::~idStaticModel(this: &v64);
  idStaticModel::~idStaticModel(this: &v61);
  idStaticModel::~idStaticModel(this: &v71);
  idStaticModel::~idStaticModel(this: &v69);
  idStaticModel::~idStaticModel(this: &v62);
  idStaticModel::~idStaticModel(this: &v65);
  idStaticModel::~idStaticModel(this: &v66);
  idStaticModel::~idStaticModel(this: &v68);
  idStaticModel::~idStaticModel(this: &v63);
  idStaticModel::~idStaticModel(this: &v70);
  idStaticModel::~idStaticModel(this: &v72);
  idStaticModel::~idStaticModel(this: &v74);
  idStaticModel::~idStaticModel(this: &v60);
  idStaticModel::~idStaticModel(this: &v58);
  idStr::FreeData(this: &v40);
}


// ========================================================================
// __unwind$247298
// EA  : 0x82684E8C
// RVA : 0x00684E8C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247298()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 112));
}


// ========================================================================
// __unwind$247299
// EA  : 0x82684EB4
// RVA : 0x00684EB4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247299()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 592));
}


// ========================================================================
// __unwind$247300
// EA  : 0x82684EDC
// RVA : 0x00684EDC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247300()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 688));
}


// ========================================================================
// __unwind$247301
// EA  : 0x82684F04
// RVA : 0x00684F04
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247301()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 432));
}


// ========================================================================
// __unwind$247302
// EA  : 0x82684F2C
// RVA : 0x00684F2C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247302()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 1520));
}


// ========================================================================
// __unwind$247303
// EA  : 0x82684F54
// RVA : 0x00684F54
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247303()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 240));
}


// ========================================================================
// __unwind$247304
// EA  : 0x82684F7C
// RVA : 0x00684F7C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247304()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 7344));
}


// ========================================================================
// __unwind$247305
// EA  : 0x82684FA4
// RVA : 0x00684FA4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247305()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 560));
}


// ========================================================================
// __unwind$247306
// EA  : 0x82684FCC
// RVA : 0x00684FCC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247306()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 6512));
}


// ========================================================================
// __unwind$247307
// EA  : 0x82684FF4
// RVA : 0x00684FF4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247307()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 304));
}


// ========================================================================
// __unwind$247308
// EA  : 0x8268501C
// RVA : 0x0068501C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247308()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 5680));
}


// ========================================================================
// __unwind$247309
// EA  : 0x82685044
// RVA : 0x00685044
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247309()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 496));
}


// ========================================================================
// __unwind$247310
// EA  : 0x8268506C
// RVA : 0x0068506C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247310()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 2768));
}


// ========================================================================
// __unwind$247311
// EA  : 0x82685094
// RVA : 0x00685094
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247311()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 368));
}


// ========================================================================
// __unwind$247312
// EA  : 0x826850BC
// RVA : 0x006850BC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247312()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 4848));
}


// ========================================================================
// __unwind$247313
// EA  : 0x826850E4
// RVA : 0x006850E4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247313()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 624));
}


// ========================================================================
// __unwind$247314
// EA  : 0x8268510C
// RVA : 0x0068510C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247314()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 4016));
}


// ========================================================================
// __unwind$247315
// EA  : 0x82685134
// RVA : 0x00685134
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247315()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 176));
}


// ========================================================================
// __unwind$247316
// EA  : 0x8268515C
// RVA : 0x0068515C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247316()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 3600));
}


// ========================================================================
// __unwind$247317
// EA  : 0x82685184
// RVA : 0x00685184
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247317()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 208));
}


// ========================================================================
// __unwind$247318
// EA  : 0x826851AC
// RVA : 0x006851AC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247318()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 2352));
}


// ========================================================================
// __unwind$247319
// EA  : 0x826851D4
// RVA : 0x006851D4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247319()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 272));
}


// ========================================================================
// __unwind$247320
// EA  : 0x826851FC
// RVA : 0x006851FC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247320()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 5264));
}


// ========================================================================
// __unwind$247321
// EA  : 0x82685224
// RVA : 0x00685224
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247321()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 336));
}


// ========================================================================
// __unwind$247322
// EA  : 0x8268524C
// RVA : 0x0068524C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247322()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 6096));
}


// ========================================================================
// __unwind$247323
// EA  : 0x82685274
// RVA : 0x00685274
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247323()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 400));
}


// ========================================================================
// __unwind$247324
// EA  : 0x8268529C
// RVA : 0x0068529C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247324()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 1936));
}


// ========================================================================
// __unwind$247325
// EA  : 0x826852C4
// RVA : 0x006852C4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247325()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 464));
}


// ========================================================================
// __unwind$247326
// EA  : 0x826852EC
// RVA : 0x006852EC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247326()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 3184));
}


// ========================================================================
// __unwind$247327
// EA  : 0x82685314
// RVA : 0x00685314
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247327()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 528));
}


// ========================================================================
// __unwind$247328
// EA  : 0x8268533C
// RVA : 0x0068533C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247328()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 6928));
}


// ========================================================================
// __unwind$247329
// EA  : 0x82685364
// RVA : 0x00685364
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247329()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 144));
}


// ========================================================================
// __unwind$247330
// EA  : 0x8268538C
// RVA : 0x0068538C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247330()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 4432));
}


// ========================================================================
// __unwind$247331
// EA  : 0x826853B4
// RVA : 0x006853B4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247331()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 7808 + 656));
}


// ========================================================================
// __unwind$247332
// EA  : 0x826853DC
// RVA : 0x006853DC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247332()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 7808 + 1104));
}


// ========================================================================
// __unwind$247333
// EA  : 0x82685404
// RVA : 0x00685404
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247333()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7808 + 96));
}


// ========================================================================
// __unwind$247334
// EA  : 0x8268542C
// RVA : 0x0068542C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247334()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7808 + 96));
}


// ========================================================================
// __unwind$247335
// EA  : 0x82685454
// RVA : 0x00685454
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247335()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7808 + 96));
}


// ========================================================================
// __unwind$247336
// EA  : 0x8268547C
// RVA : 0x0068547C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247336()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7808 + 96));
}


// ========================================================================
// __unwind$247337
// EA  : 0x826854A4
// RVA : 0x006854A4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247337()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7808 + 96));
}


// ========================================================================
// __unwind$247338
// EA  : 0x826854CC
// RVA : 0x006854CC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247338()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7808 + 96));
}


// ========================================================================
// __unwind$247339
// EA  : 0x826854F4
// RVA : 0x006854F4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247339()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7808 + 96));
}


// ========================================================================
// __unwind$247340
// EA  : 0x8268551C
// RVA : 0x0068551C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247340()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7808 + 96));
}


// ========================================================================
// __unwind$247341
// EA  : 0x82685544
// RVA : 0x00685544
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247341()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7808 + 96));
}


// ========================================================================
// __unwind$247342
// EA  : 0x8268556C
// RVA : 0x0068556C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247342()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7808 + 96));
}


// ========================================================================
// __unwind$247343
// EA  : 0x82685594
// RVA : 0x00685594
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247343()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7808 + 96));
}


// ========================================================================
// __unwind$247344
// EA  : 0x826855BC
// RVA : 0x006855BC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247344()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7808 + 96));
}


// ========================================================================
// __unwind$247345
// EA  : 0x826855E4
// RVA : 0x006855E4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_247345()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7808 + 96));
}


// ========================================================================
// ?GenerateWeaponUseInfo@idPlaytestStorage@@QAAXHAAV?$idList@VweaponUsageReport_t@idPlaytestStorage@@$04@@@Z
// EA  : 0x82685E50
// RVA : 0x00685E50
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPlaytestStorage::GenerateWeaponUseInfo(idPlaytestStorage *this, __int64 weaponList, _BYTE a3[12])
{
  int v3; // r22
  idList<idPlaytestStorage::weaponUsageReport_t,5> *v5; // r30
  int v6; // r11
  __int64 v7; // r10
  int v8; // r26
  int v9; // r21
  int lastTime; // r29
  idPlaytestStorage::equipItemInfo_t *v11; // r10
  int timestamp; // r28
  int v13; // r25
  char v14; // r27
  int v15; // r29
  int v16; // r28
  int len; // r29
  int v18; // r11
  double v19; // fp13
  int v20; // r25
  int v21; // r27
  char v22; // r26
  int v23; // r28
  int v24; // r29
  idPlaytestStorage::weaponFireInfo_t *v25; // r28
  size_t v26; // r29
  idSort_Quick<idPlaytestStorage::weaponUsageReport_t,idPlaytestStorage::idSort_WeaponUsageReport> v27; // [sp+58h] [-118h] BYREF
  idPlaytestStorage::weaponUsageReport_t v28; // [sp+60h] [-110h] BYREF
  idPlaytestStorage::weaponUsageReport_t v29; // [sp+90h] [-E0h] BYREF
  __int64 v30; // [sp+C0h] [-B0h]
  idStr v31; // [sp+D0h] [-A0h] BYREF

  v3 = HIDWORD(weaponList);
  v5 = (idList<idPlaytestStorage::weaponUsageReport_t,5> *)weaponList;
  v7 = (unsigned int)&this->playerEquipItemInfo.list[HIDWORD(weaponList)];
  v6 = *(_DWORD *)(v7 + 4);
  if ( v6 > 0 )
  {
    v8 = 0;
    do
    {
      v9 = HIDWORD(v7) + 1;
      if ( HIDWORD(v7) + 1 < v6 )
        lastTime = *(_DWORD *)(v8 * 80 + *(_DWORD *)v7 + 156);
      else
        lastTime = this->lastTime;
      v11 = &this->playerEquipItemInfo.list[v3].list[v8];
      timestamp = v11->timestamp;
      idStr::idStr(this: &v31, text: &v11->equipedItemName);
      v13 = lastTime - timestamp;
      v14 = 0;
      v15 = 0;
      if ( v5->num > 0 )
      {
        v16 = 0;
        while ( idStr::Cmp(s1: v5->list[v16].weaponName.data, s2: v31.data) != 0 )
        {
          ++v15;
          ++v16;
          if ( v15 >= v5->num )
            goto LABEL_12;
        }
        v14 = 1;
        v5->list[v15].time += v13;
      }
LABEL_12:
      if ( v14 == 0 )
      {
        v29.percentage = 0.0;
        v29.weaponName.allocedAndFlag = 20;
        v29.weaponName.len = 0;
        v29.weaponName.baseBuffer[0] = 0;
        v29.weaponName.data = v29.weaponName.baseBuffer;
        v29.time = 0;
        v29.projectilesSpawned = 0;
        len = v31.len;
        if ( v31.len + 1 > 20 )
          idStr::ReAllocate(this: &v29.weaponName, amount: v31.len + 1, keepold: false);
        memcpy(Dst: v29.weaponName.data, Src: v31.data, Size: len);
        v29.weaponName.data[len] = 0;
        v29.weaponName.len = len;
        v29.time = v13;
        idList<idPlaytestStorage::weaponUsageReport_t,5>::Append(this: v5, obj: &v29);
        idStr::FreeData(this: &v29.weaponName);
      }
      idStr::FreeData(this: &v31);
      HIDWORD(v7) = v9;
      LODWORD(v7) = &this->playerEquipItemInfo.list[v3];
      ++v8;
      v6 = *(_DWORD *)(v7 + 4);
    }
    while ( v9 < v6 );
  }
  LODWORD(v7) = 0;
  if ( v5->num > 0 )
  {
    v18 = 0;
    do
    {
      LODWORD(v7) = v7 + 1;
      *(_DWORD *)&a3[8] = this->lastTime;
      HIDWORD(v7) = &v5->list[v18];
      *(_DWORD *)&a3[4] = *(_DWORD *)&a3[8];
      ++v18;
      v19 = (double)*(__int64 *)a3;
      *(_DWORD *)a3 = *(_DWORD *)(HIDWORD(v7) + 32);
      LODWORD(weaponList) = *(_DWORD *)a3;
      v30 = weaponList;
      *(float *)(HIDWORD(v7) + 36) = (float)weaponList / (float)v19;
      HIDWORD(weaponList) = v5->num;
    }
    while ( (int)v7 < SHIDWORD(weaponList) );
  }
  v20 = 0;
  LODWORD(v7) = this->playerWeaponFireInfo.list[v3].num;
  if ( (int)v7 > 0 )
  {
    v21 = 0;
    do
    {
      v22 = 0;
      v23 = 0;
      if ( v5->num > 0 )
      {
        v24 = 0;
        while ( idStr::Cmp(
                  s1: v5->list[v24].weaponName.data,
                  s2: this->playerWeaponFireInfo.list[v3].list[v21].weaponName.data) != 0 )
        {
          ++v23;
          ++v24;
          if ( v23 >= v5->num )
            goto LABEL_28;
        }
        v22 = 1;
        ++v5->list[v23].projectilesSpawned;
      }
LABEL_28:
      if ( v22 == 0 )
      {
        v28.percentage = 0.0;
        v28.weaponName.allocedAndFlag = 20;
        v28.weaponName.len = 0;
        v28.weaponName.baseBuffer[0] = 0;
        v28.weaponName.data = v28.weaponName.baseBuffer;
        v28.time = 0;
        v28.projectilesSpawned = 0;
        v25 = &this->playerWeaponFireInfo.list[v3].list[v21];
        v26 = v25->weaponName.len;
        if ( v25->weaponName.len + 1 > 20 )
          idStr::ReAllocate(this: &v28.weaponName, amount: v25->weaponName.len + 1, keepold: false);
        memcpy(Dst: v28.weaponName.data, Src: v25->weaponName.data, Size: v26);
        v28.weaponName.data[v26] = 0;
        v28.weaponName.len = v26;
        v28.projectilesSpawned = 1;
        idList<idPlaytestStorage::weaponUsageReport_t,5>::Append(this: v5, obj: &v28);
        idStr::FreeData(this: &v28.weaponName);
      }
      ++v20;
      ++v21;
      LODWORD(v7) = this->playerWeaponFireInfo.list[v3].num;
    }
    while ( v20 < (int)v7 );
  }
  v27.__vftable = (idSort_Quick<idPlaytestStorage::weaponUsageReport_t,idPlaytestStorage::idSort_WeaponUsageReport>_vtbl *)&idPlaytestStorage::idSort_WeaponUsageReport::`vftable';
  if ( v5->list != nullptr )
    idSort_Quick<idPlaytestStorage::weaponUsageReport_t,idPlaytestStorage::idSort_WeaponUsageReport>::Sort(
      this: &v27,
      base: v5->list,
      num: v5->num,
      a4: *(int *)a3,
      a5: *(__int64 *)&a3[4],
      a6: v7);
}


// ========================================================================
// __unwind$249530
// EA  : 0x826861E8
// RVA : 0x006861E8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_249530()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 208));
}


// ========================================================================
// __unwind$249531
// EA  : 0x82686210
// RVA : 0x00686210
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_249531()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 144));
}


// ========================================================================
// __unwind$249532
// EA  : 0x82686238
// RVA : 0x00686238
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_249532()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$249533
// EA  : 0x82686260
// RVA : 0x00686260
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_249533()
{
  int v0; // r12

  idPlaytestStorage::idSort_WeaponUsageReport::~idSort_WeaponUsageReport(this: (idPlaytestStorage::idSort_WeaponUsageReport *)(v0 - 368 + 88));
}


// ========================================================================
// ?GenerateKillInfo@idPlaytestStorage@@QAAXHAAV?$idList@VkillReport_t@idPlaytestStorage@@$04@@@Z
// EA  : 0x82686290
// RVA : 0x00686290
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GenerateKillInfo(
        idPlaytestStorage *this,
        int playerNum,
        idList<idPlaytestStorage::killReport_t,5> *killList,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  int v10; // r21
  int v11; // r27
  char v12; // r25
  int v13; // r28
  int v14; // r30
  idPlaytestStorage::killReport_t *v15; // r11
  idPlaytestStorage::deathInfo_t *v16; // r28
  size_t len; // r30
  idPlaytestStorage::quickItemReport_t *list; // r4
  unsigned int num; // r5
  idSort_Quick<idPlaytestStorage::quickItemReport_t,idPlaytestStorage::idSort_QuickItemReport> v20[4]; // [sp+50h] [-A0h] BYREF
  idGroupState v21[4]; // [sp+60h] [-90h] BYREF

  v10 = 0;
  if ( this->otherDeathInfo.num > 0 )
  {
    v11 = 0;
    do
    {
      LODWORD(a7) = this->otherDeathInfo.list[v11].killerEntityNum;
      if ( (_DWORD)a7 == playerNum )
      {
        v12 = 0;
        v13 = 0;
        if ( killList->num > 0 )
        {
          v14 = 0;
          while ( idStr::Cmp(
                    s1: killList->list[v14].damageName.data,
                    s2: this->otherDeathInfo.list[v11].damageName.data) != 0 )
          {
            ++v13;
            ++v14;
            if ( v13 >= killList->num )
              goto LABEL_10;
          }
          v12 = 1;
          v15 = &killList->list[v13];
          LODWORD(a7) = v15->count + 1;
          v15->count = a7;
        }
LABEL_10:
        if ( v12 == 0 )
        {
          v21[0].groupName.allocedAndFlag = 20;
          v21[0].groupName.len = 0;
          v21[0].groupName.data = v21[0].groupName.baseBuffer;
          v21[0].groupName.baseBuffer[0] = 0;
          v21[0].state = 0;
          v16 = &this->otherDeathInfo.list[v11];
          len = v16->damageName.len;
          if ( (int)(len + 1) > 20 )
            idStr::ReAllocate(this: &v21[0].groupName, amount: len + 1, keepold: false);
          memcpy(Dst: v21[0].groupName.data, Src: v16->damageName.data, Size: len);
          v21[0].groupName.data[len] = 0;
          v21[0].groupName.len = len;
          v21[0].state = 1;
          idList<idPlaytestStorage::killReport_t,5>::Append(this: killList, obj: v21);
          idStr::FreeData(this: &v21[0].groupName);
        }
      }
      ++v10;
      ++v11;
    }
    while ( v10 < this->otherDeathInfo.num );
  }
  v20[0].__vftable = (idSort_Quick<idPlaytestStorage::quickItemReport_t,idPlaytestStorage::idSort_QuickItemReport>_vtbl *)&idPlaytestStorage::idSort_KillReport::`vftable';
  list = (idPlaytestStorage::quickItemReport_t *)killList->list;
  if ( killList->list != nullptr )
  {
    num = killList->num;
    v20[1] = (idSort_Quick<idPlaytestStorage::quickItemReport_t,idPlaytestStorage::idSort_QuickItemReport>)killList->list;
    idSort_Quick<idPlaytestStorage::killReport_t,idPlaytestStorage::idSort_KillReport>::Sort(
      this: v20,
      base: list,
      num,
      a4,
      a5,
      a6,
      a7);
  }
}


// ========================================================================
// __unwind$249899
// EA  : 0x82686428
// RVA : 0x00686428
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_249899()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$249900
// EA  : 0x82686450
// RVA : 0x00686450
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_249900()
{
  int v0; // r12

  idPlaytestStorage::idSort_KillReport::~idSort_KillReport(this: (idPlaytestStorage::idSort_KillReport *)(v0 - 240 + 80));
}


// ========================================================================
// ?GenerateQuickItemInfo@idPlaytestStorage@@QAAXHAAV?$idList@VquickItemReport_t@idPlaytestStorage@@$04@@@Z
// EA  : 0x82686480
// RVA : 0x00686480
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::GenerateQuickItemInfo(
        idPlaytestStorage *this,
        int playerNum,
        idList<idPlaytestStorage::killReport_t,5> *itemList,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  int v7; // r26
  int v10; // r21
  int v11; // r27
  char v12; // r23
  int v13; // r28
  int v14; // r30
  idPlaytestStorage::quickItemInfo_t *v15; // r28
  size_t len; // r30
  idPlaytestStorage::quickItemReport_t *list; // r4
  unsigned int num; // r5
  idSort_Quick<idPlaytestStorage::quickItemReport_t,idPlaytestStorage::idSort_QuickItemReport> v19[4]; // [sp+50h] [-A0h] BYREF
  idGroupState v20[4]; // [sp+60h] [-90h] BYREF

  v7 = playerNum;
  v10 = 0;
  LODWORD(a7) = this->playerUseQuickItemInfo.list[playerNum].num;
  if ( (int)a7 > 0 )
  {
    v11 = 0;
    do
    {
      v12 = 0;
      v13 = 0;
      if ( itemList->num > 0 )
      {
        v14 = 0;
        while ( idStr::Cmp(
                  s1: itemList->list[v14].damageName.data,
                  s2: this->playerUseQuickItemInfo.list[v7].list[v11].quickItemName.data) != 0 )
        {
          ++v13;
          ++v14;
          if ( v13 >= itemList->num )
            goto LABEL_9;
        }
        v12 = 1;
        ++itemList->list[v13].count;
      }
LABEL_9:
      if ( v12 == 0 )
      {
        v20[0].groupName.allocedAndFlag = 20;
        v20[0].groupName.len = 0;
        v20[0].groupName.data = v20[0].groupName.baseBuffer;
        v20[0].groupName.baseBuffer[0] = 0;
        v20[0].state = 0;
        v15 = &this->playerUseQuickItemInfo.list[v7].list[v11];
        len = v15->quickItemName.len;
        if ( (int)(len + 1) > 20 )
          idStr::ReAllocate(this: &v20[0].groupName, amount: len + 1, keepold: false);
        memcpy(Dst: v20[0].groupName.data, Src: v15->quickItemName.data, Size: len);
        v20[0].groupName.data[len] = 0;
        v20[0].groupName.len = len;
        v20[0].state = 1;
        idList<idPlaytestStorage::killReport_t,5>::Append(this: itemList, obj: v20);
        idStr::FreeData(this: &v20[0].groupName);
      }
      ++v10;
      ++v11;
      LODWORD(a7) = this->playerUseQuickItemInfo.list[v7].num;
    }
    while ( v10 < (int)a7 );
  }
  v19[0].__vftable = (idSort_Quick<idPlaytestStorage::quickItemReport_t,idPlaytestStorage::idSort_QuickItemReport>_vtbl *)&idPlaytestStorage::idSort_QuickItemReport::`vftable';
  list = (idPlaytestStorage::quickItemReport_t *)itemList->list;
  if ( itemList->list != nullptr )
  {
    num = itemList->num;
    v19[1] = (idSort_Quick<idPlaytestStorage::quickItemReport_t,idPlaytestStorage::idSort_QuickItemReport>)itemList->list;
    idSort_Quick<idPlaytestStorage::killReport_t,idPlaytestStorage::idSort_KillReport>::Sort(
      this: v19,
      base: list,
      num,
      a4,
      a5,
      a6,
      a7);
  }
}


// ========================================================================
// __unwind$250091_0
// EA  : 0x8268661C
// RVA : 0x0068661C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_250091_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$250092
// EA  : 0x82686644
// RVA : 0x00686644
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_250092()
{
  int v0; // r12

  idPlaytestStorage::idSort_QuickItemReport::~idSort_QuickItemReport(this: (idPlaytestStorage::idSort_QuickItemReport *)(v0 - 240 + 80));
}


// ========================================================================
// ?WritePlayerSummary@idPlaytestStorage@@QAAXPAVidFile_Memory@@@Z
// EA  : 0x826871F0
// RVA : 0x006871F0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::WritePlayerSummary(idPlaytestStorage *this, idFile_Memory *memoryFile)
{
  int v4; // r23
  _BYTE *v5; // r7
  int v6; // r28
  idList<idPlaytestStorage::deathInfo_t,5> *v7; // r11
  __int64 v8; // r6
  int v9; // r29
  idPlaytestStorage::deathInfo_t *list; // r10
  idStr *v11; // r3
  __int64 v12; // r10
  int v13; // r8
  int v14; // r7
  int v15; // r6
  int v16; // r28
  idStr *v17; // r25
  char *v18; // r29
  idStr *ReadableTimeString; // r3
  __int64 v20; // r10
  int v21; // r8
  int v22; // r7
  int v23; // r6
  int num; // r28
  idPlaytestStorage::killReport_t *v25; // r26
  int *p_count; // r29
  int v27; // r6
  int v28; // r5
  __int64 v29; // r28
  int *v30; // r11
  int i; // ctr
  _DWORD *v32; // r29
  int v33; // r6
  int size; // r29
  idStr *v35; // r28
  int v36; // r29
  idStr *p_damageName; // r28
  int v38; // r29
  idStr *v39; // r28
  int v40; // [sp+50h] [-140h]
  int v41; // [sp+58h] [-138h]
  idList<idPlaytestStorage::killReport_t,5> v42; // [sp+60h] [-130h] BYREF
  int v43; // [sp+70h] [-120h] BYREF
  int v44; // [sp+74h] [-11Ch]
  int v45; // [sp+78h] [-118h]
  __int16 v46; // [sp+7Ch] [-114h]
  char v47; // [sp+7Eh] [-112h]
  char v48; // [sp+7Fh] [-111h]
  idList<idPlaytestStorage::killReport_t,5> v49; // [sp+80h] [-110h] BYREF
  const char *v50; // [sp+90h] [-100h]
  const char *v51; // [sp+94h] [-FCh]
  const char *v52; // [sp+98h] [-F8h]
  const char *v53; // [sp+9Ch] [-F4h]
  const char *v54; // [sp+A0h] [-F0h]
  idList<idPlaytestStorage::deathInfo_t,5> *v55; // [sp+A4h] [-ECh]
  idStr v56; // [sp+B0h] [-E0h] BYREF
  idStr v57[6]; // [sp+D0h] [-C0h] BYREF

  v41 = 0;
  if ( this->numPlayers > 0 )
  {
    v40 = 0;
    v52 = "KILLS:\t%d\n";
    v50 = "QUICK ITEM USAGE:\n";
    v51 = "\tTIME: %s\t";
    v4 = 0;
    v54 = "WEAPON USAGE:\t\tFAV: %s\tPERCENTAGE %.2f\n";
    v53 = "DEATHS:\t%d\n";
    do
    {
      if ( this->playerBreadCrumbs.list[v40].normalBreadCrumbs.num != 0 )
      {
        memoryFile->Printf(this: memoryFile, a2: "%s\n", this->fileName.data);
        memoryFile->Printf(this: memoryFile, a2: v53, this->playerDeathInfo.list[v4].num);
        v6 = 0;
        v7 = &this->playerDeathInfo.list[v4];
        LODWORD(v8) = v7->num;
        if ( (int)v8 > 0 )
        {
          v9 = 0;
          do
          {
            list = v7->list;
            v55 = v7;
            v11 = idPlaytestStorage::CreateReadableTimeString(result: &v56, timeMS: list[v9].timestamp);
            memoryFile->Printf(this: memoryFile, a2: "\t%s\t", v11->data);
            idStr::FreeData(this: &v56);
            memoryFile->Printf(
              this: memoryFile,
              a2: "killed by %s ",
              this->playerDeathInfo.list[v4].list[v9].killerName.data);
            memoryFile->Printf(
              this: memoryFile,
              a2: "with %s ",
              this->playerDeathInfo.list[v4].list[v9].damageName.data);
            memoryFile->Printf(this: memoryFile, a2: "\tEND OF GAME\n");
            ++v6;
            ++v9;
            v7 = &this->playerDeathInfo.list[v4];
          }
          while ( v6 < v7->num );
        }
        v46 = 0;
        v48 = 0;
        v47 = 5;
        v43 = 0;
        v45 = 0;
        v44 = 0;
        HIDWORD(v8) = &v43;
        idPlaytestStorage::GenerateWeaponUseInfo(this, weaponList: v8, a3: v5);
        v16 = v44;
        v17 = (idStr *)v43;
        if ( v44 > 0 )
        {
          memoryFile->Printf(
            this: memoryFile,
            a2: v54,
            *(_DWORD *)(v43 + 4),
            COERCE_UNSIGNED_INT64(*(float *)(v43 + 36)));
          v18 = &v17[-2].baseBuffer[12];
          do
          {
            ReadableTimeString = idPlaytestStorage::CreateReadableTimeString(result: v57, timeMS: *((_DWORD *)v18 + 18));
            memoryFile->Printf(this: memoryFile, a2: v51, ReadableTimeString->data);
            idStr::FreeData(this: v57);
            memoryFile->Printf(
              this: memoryFile,
              a2: "PERCENTAGE %.2f\t",
              (unsigned int)COERCE_UNSIGNED_INT64(*((float *)v18 + 19)));
            memoryFile->Printf(this: memoryFile, a2: "SHOTS: %d\t\t", *((_DWORD *)v18 + 20));
            v18 += 44;
            memoryFile->Printf(this: memoryFile, a2: "%s\n", *(_DWORD *)v18);
            --v16;
          }
          while ( v16 != 0 );
        }
        *(_WORD *)&v49.memTag = 1280;
        memset(&v49, 0, 14);
        idPlaytestStorage::GenerateQuickItemInfo(
          this,
          playerNum: v41,
          itemList: &v49,
          a4: v15,
          a5: v14,
          a6: v13,
          a7: v12);
        memoryFile->Printf(this: memoryFile, a2: v50);
        v25 = v49.list;
        num = v49.num;
        if ( v49.num > 0 )
        {
          p_count = &v49.list[-1].count;
          do
          {
            v27 = p_count[2];
            p_count += 9;
            memoryFile->Printf(this: memoryFile, a2: "\t%d\t%s\n", *p_count, v27);
            --num;
          }
          while ( num != 0 );
        }
        *(_WORD *)&v42.memTag = 1280;
        memset(&v42, 0, 14);
        idPlaytestStorage::GenerateKillInfo(this, playerNum: v41, killList: &v42, a4: v23, a5: v22, a6: v21, a7: v20);
        v28 = 0;
        v29 = *(_QWORD *)&v42.list;
        if ( v42.num > 0 )
        {
          v30 = &v42.list[-1].count;
          for ( i = v42.num; i != 0; --i )
          {
            v30 += 9;
            v28 += *v30;
          }
        }
        memoryFile->Printf(this: memoryFile, a2: v52, v28);
        if ( (int)v29 > 0 )
        {
          v32 = (_DWORD *)(HIDWORD(v29) - 4);
          do
          {
            v33 = v32[2];
            v32 += 9;
            memoryFile->Printf(this: memoryFile, a2: "\t%d\t%s\n", *v32, v33);
            LODWORD(v29) = v29 - 1;
          }
          while ( (_DWORD)v29 != 0 );
        }
        if ( v42.listStatic == 0 || v42.listStatic == 2 )
        {
          if ( HIDWORD(v29) != 0 )
          {
            size = v42.size;
            if ( v42.size > 0 )
            {
              v35 = (idStr *)HIDWORD(v29);
              do
              {
                idStr::FreeData(this: v35);
                --size;
                v35 = (idStr *)((char *)v35 + 36);
              }
              while ( size != 0 );
            }
            idMem::Free(this: &mem, ptr: (void *)HIDWORD(v29), align: ALIGN_16);
          }
          v42.list = nullptr;
          v42.size = 0;
        }
        v42.num = 0;
        if ( v49.listStatic == 0 || v49.listStatic == 2 )
        {
          if ( v25 != nullptr )
          {
            v36 = v49.size;
            if ( v49.size > 0 )
            {
              p_damageName = &v25->damageName;
              do
              {
                idStr::FreeData(this: p_damageName);
                --v36;
                p_damageName = (idStr *)((char *)p_damageName + 36);
              }
              while ( v36 != 0 );
            }
            idMem::Free(this: &mem, ptr: v25, align: ALIGN_16);
          }
          v49.list = nullptr;
          v49.size = 0;
        }
        v49.num = 0;
        if ( v48 == 0 || v48 == 2 )
        {
          if ( v17 != nullptr )
          {
            v38 = v45;
            if ( v45 > 0 )
            {
              v39 = v17;
              do
              {
                idStr::FreeData(this: v39);
                --v38;
                v39 = (idStr *)((char *)v39 + 44);
              }
              while ( v38 != 0 );
            }
            idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
          }
          v43 = 0;
          v45 = 0;
        }
        v44 = 0;
      }
      ++v4;
      ++v41;
      ++v40;
    }
    while ( v41 < this->numPlayers );
  }
}


// ========================================================================
// __unwind$251528
// EA  : 0x8268774C
// RVA : 0x0068774C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_251528()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 176));
}


// ========================================================================
// __unwind$251529
// EA  : 0x82687774
// RVA : 0x00687774
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_251529()
{
  int v0; // r12

  idList<idDeclSpecialEvent_Area::jobStinger_t,5>::~idList<idDeclSpecialEvent_Area::jobStinger_t,5>(this: (idList<idDeclPonytail::idPonytailJointInfo,30> *)(v0 - 400 + 112));
}


// ========================================================================
// __unwind$251530
// EA  : 0x8268779C
// RVA : 0x0068779C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_251530()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 208));
}


// ========================================================================
// __unwind$251531
// EA  : 0x826877C4
// RVA : 0x006877C4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_251531()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(v0 - 400 + 128));
}


// ========================================================================
// __unwind$251532
// EA  : 0x826877EC
// RVA : 0x006877EC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_251532()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(v0 - 400 + 96));
}


// ========================================================================
// ?Clear@idPlaytestStorage@@QAAXXZ
// EA  : 0x82689460
// RVA : 0x00689460
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::Clear(idPlaytestStorage *this)
{
  int numPlayers; // r10
  int v3; // r23
  int v4; // r24
  int v5; // r25
  idList<idPlaytestStorage::playerButtonInfo_t,5> *v6; // r31
  idList<idPlaytestStorage::itemInfo_t,5> *v7; // r31
  idList<idPlaytestStorage::useFocusInfo_t,5> *v8; // r31
  idPlaytestStorage::useFocusInfo_t *list; // r27
  int size; // r30
  idStr *p_focusName; // r29
  idList<idPlaytestStorage::quickItemInfo_t,5> *v12; // r31
  idList<idPlaytestStorage::equipItemInfo_t,5> *v13; // r31
  idList<idPlaytestStorage::deathInfo_t,5> *v14; // r31
  idPlaytestStorage::deathInfo_t *v15; // r27
  int v16; // r30
  idPlaytestStorage::deathInfo_t *v17; // r29
  idList<idPlaytestStorage::weaponFireInfo_t,5> *v18; // r31
  idPlaytestStorage::weaponFireInfo_t *v19; // r27
  int v20; // r30
  idPlaytestStorage::weaponFireInfo_t *v21; // r29
  idList<idPlaytestStorage::inventoryInfo_t,5> *v22; // r31
  idPlaytestStorage::playerMainBreadCrumbInfo_t *v23; // r31
  idPlaytestStorage::playerNormalBreadCrumbList_t *v24; // r27
  int v25; // r30
  idPlaytestStorage::playerNormalBreadCrumbList_t *v26; // r29
  idPlaytestStorage::playerMainBreadCrumbInfo_t *v27; // r31
  char *v28; // r3
  idPlaytestStorage::playerMainBreadCrumbInfo_t *v29; // r31
  char *v30; // r3
  idPlaytestStorage::radiusDamageInfo_t *v31; // r29
  int v32; // r31
  idPlaytestStorage::radiusDamageInfo_t *v33; // r30
  idPlaytestStorage::deathInfo_t *v34; // r29
  int v35; // r31
  idPlaytestStorage::deathInfo_t *v36; // r30
  idPlaytestStorage::weaponFireInfo_t *v37; // r29
  int v38; // r31
  idPlaytestStorage::weaponFireInfo_t *v39; // r30
  idPlaytestStorage::ai2Info_t *v40; // r29
  int v41; // r31
  idPlaytestStorage::ai2Info_t *v42; // r30

  numPlayers = this->numPlayers;
  this->lastTime = 0;
  this->beginTime = -1;
  v3 = 0;
  this->offsetTime = 0;
  if ( numPlayers > 0 )
  {
    v4 = 0;
    v5 = 0;
    do
    {
      v6 = &this->playerButtonInfo.list[v5];
      if ( v6->listStatic == 0 || v6->listStatic == 2 )
      {
        if ( v6->list != nullptr )
          idMem::Free(this: &mem, ptr: v6->list, align: ALIGN_16);
        v6->list = nullptr;
        v6->size = 0;
      }
      v6->num = 0;
      v7 = &this->playerItemInfo.list[v5];
      if ( v7->listStatic == 0 || v7->listStatic == 2 )
      {
        if ( v7->list != nullptr )
          idListArrayDelete<idPlaytestStorage::itemInfo_t>(ptr: (char *)v7->list, num: v7->size);
        v7->list = nullptr;
        v7->size = 0;
      }
      v7->num = 0;
      v8 = &this->playerUseFocusInfo.list[v5];
      if ( v8->listStatic == 0 || v8->listStatic == 2 )
      {
        list = v8->list;
        if ( v8->list != nullptr )
        {
          size = v8->size;
          if ( size > 0 )
          {
            p_focusName = &list->focusName;
            do
            {
              idStr::FreeData(this: p_focusName);
              --size;
              p_focusName = (idStr *)((char *)p_focusName + 60);
            }
            while ( size != 0 );
          }
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        }
        v8->list = nullptr;
        v8->size = 0;
      }
      v8->num = 0;
      v12 = &this->playerUseQuickItemInfo.list[v5];
      if ( v12->listStatic == 0 || v12->listStatic == 2 )
      {
        if ( v12->list != nullptr )
          idListArrayDelete<idPlaytestStorage::quickItemInfo_t>(ptr: (char *)v12->list, num: v12->size);
        v12->list = nullptr;
        v12->size = 0;
      }
      v12->num = 0;
      v13 = &this->playerEquipItemInfo.list[v5];
      if ( v13->listStatic == 0 || v13->listStatic == 2 )
      {
        if ( v13->list != nullptr )
          idListArrayDelete<idPlaytestStorage::quickItemInfo_t>(ptr: (char *)v13->list, num: v13->size);
        v13->list = nullptr;
        v13->size = 0;
      }
      v13->num = 0;
      v14 = &this->playerDeathInfo.list[v5];
      if ( v14->listStatic == 0 || v14->listStatic == 2 )
      {
        v15 = v14->list;
        if ( v14->list != nullptr )
        {
          v16 = v14->size;
          if ( v16 > 0 )
          {
            v17 = v14->list;
            do
            {
              idPlaytestStorage::deathInfo_t::~deathInfo_t(this: v17);
              --v16;
              ++v17;
            }
            while ( v16 != 0 );
          }
          idMem::Free(this: &mem, ptr: v15, align: ALIGN_16);
        }
        v14->list = nullptr;
        v14->size = 0;
      }
      v14->num = 0;
      v18 = &this->playerWeaponFireInfo.list[v5];
      if ( v18->listStatic == 0 || v18->listStatic == 2 )
      {
        v19 = v18->list;
        if ( v18->list != nullptr )
        {
          v20 = v18->size;
          if ( v20 > 0 )
          {
            v21 = v18->list;
            do
            {
              idPlaytestStorage::weaponFireInfo_t::~weaponFireInfo_t(this: v21);
              --v20;
              ++v21;
            }
            while ( v20 != 0 );
          }
          idMem::Free(this: &mem, ptr: v19, align: ALIGN_16);
        }
        v18->list = nullptr;
        v18->size = 0;
      }
      v18->num = 0;
      v22 = &this->playerInventoryInfo.list[v5];
      if ( v22->listStatic == 0 || v22->listStatic == 2 )
      {
        if ( v22->list != nullptr )
          idListArrayDelete<idPlaytestStorage::inventoryInfo_t>(ptr: (char *)v22->list, num: v22->size);
        v22->list = nullptr;
        v22->size = 0;
      }
      v22->num = 0;
      v23 = &this->playerBreadCrumbs.list[v4];
      if ( v23->normalBreadCrumbs.listStatic == 0 || v23->normalBreadCrumbs.listStatic == 2 )
      {
        v24 = v23->normalBreadCrumbs.list;
        if ( v24 != nullptr )
        {
          v25 = v23->normalBreadCrumbs.size;
          if ( v25 > 0 )
          {
            v26 = v23->normalBreadCrumbs.list;
            do
            {
              idPlaytestStorage::playerNormalBreadCrumbList_t::~playerNormalBreadCrumbList_t(this: v26);
              --v25;
              ++v26;
            }
            while ( v25 != 0 );
          }
          idMem::Free(this: &mem, ptr: v24, align: ALIGN_16);
        }
        v23->normalBreadCrumbs.list = nullptr;
        v23->normalBreadCrumbs.size = 0;
      }
      v23->normalBreadCrumbs.num = 0;
      v27 = &this->playerBreadCrumbs.list[v4];
      if ( v27->miscBreadCrumbs.listStatic == 0 || v27->miscBreadCrumbs.listStatic == 2 )
      {
        v28 = (char *)v27->miscBreadCrumbs.list;
        if ( v28 != nullptr )
          idListArrayDelete<idPlaytestStorage::playerVehicleBreadCrumbList_t>(ptr: v28, num: v27->miscBreadCrumbs.size);
        v27->miscBreadCrumbs.list = nullptr;
        v27->miscBreadCrumbs.size = 0;
      }
      v27->miscBreadCrumbs.num = 0;
      v29 = &this->playerBreadCrumbs.list[v4];
      if ( v29->vehicleBreadCrumbs.listStatic == 0 || v29->vehicleBreadCrumbs.listStatic == 2 )
      {
        v30 = (char *)v29->vehicleBreadCrumbs.list;
        if ( v30 != nullptr )
          idListArrayDelete<idPlaytestStorage::playerVehicleBreadCrumbList_t>(
            ptr: v30,
            num: v29->vehicleBreadCrumbs.size);
        v29->vehicleBreadCrumbs.list = nullptr;
        v29->vehicleBreadCrumbs.size = 0;
      }
      v29->vehicleBreadCrumbs.num = 0;
      ++v3;
      ++v5;
      this->playerBreadCrumbs.list[v4++].state = PLAYERBREADCRUMBSTATE_NONE;
    }
    while ( v3 < this->numPlayers );
  }
  if ( this->radiusDamageInfo.listStatic == 0 || this->radiusDamageInfo.listStatic == 2 )
  {
    v31 = this->radiusDamageInfo.list;
    if ( v31 != nullptr )
    {
      v32 = this->radiusDamageInfo.size;
      if ( v32 > 0 )
      {
        v33 = this->radiusDamageInfo.list;
        do
        {
          idPlaytestStorage::radiusDamageInfo_t::~radiusDamageInfo_t(this: v33);
          --v32;
          ++v33;
        }
        while ( v32 != 0 );
      }
      idMem::Free(this: &mem, ptr: v31, align: ALIGN_16);
    }
    this->radiusDamageInfo.list = nullptr;
    this->radiusDamageInfo.size = 0;
  }
  this->radiusDamageInfo.num = 0;
  if ( this->otherDeathInfo.listStatic == 0 || this->otherDeathInfo.listStatic == 2 )
  {
    v34 = this->otherDeathInfo.list;
    if ( v34 != nullptr )
    {
      v35 = this->otherDeathInfo.size;
      if ( v35 > 0 )
      {
        v36 = this->otherDeathInfo.list;
        do
        {
          idPlaytestStorage::deathInfo_t::~deathInfo_t(this: v36);
          --v35;
          ++v36;
        }
        while ( v35 != 0 );
      }
      idMem::Free(this: &mem, ptr: v34, align: ALIGN_16);
    }
    this->otherDeathInfo.list = nullptr;
    this->otherDeathInfo.size = 0;
  }
  this->otherDeathInfo.num = 0;
  if ( this->otherWeaponFireInfo.listStatic == 0 || this->otherWeaponFireInfo.listStatic == 2 )
  {
    v37 = this->otherWeaponFireInfo.list;
    if ( v37 != nullptr )
    {
      v38 = this->otherWeaponFireInfo.size;
      if ( v38 > 0 )
      {
        v39 = this->otherWeaponFireInfo.list;
        do
        {
          idPlaytestStorage::weaponFireInfo_t::~weaponFireInfo_t(this: v39);
          --v38;
          ++v39;
        }
        while ( v38 != 0 );
      }
      idMem::Free(this: &mem, ptr: v37, align: ALIGN_16);
    }
    this->otherWeaponFireInfo.list = nullptr;
    this->otherWeaponFireInfo.size = 0;
  }
  this->otherWeaponFireInfo.num = 0;
  if ( this->ai2Info.listStatic == 0 || this->ai2Info.listStatic == 2 )
  {
    v40 = this->ai2Info.list;
    if ( v40 != nullptr )
    {
      v41 = this->ai2Info.size;
      if ( v41 > 0 )
      {
        v42 = this->ai2Info.list;
        do
        {
          idPlaytestStorage::ai2Info_t::~ai2Info_t(this: v42);
          --v41;
          ++v42;
        }
        while ( v41 != 0 );
      }
      idMem::Free(this: &mem, ptr: v40, align: ALIGN_16);
    }
    this->ai2Info.list = nullptr;
    this->ai2Info.size = 0;
  }
  this->ai2Info.num = 0;
}


// ========================================================================
// ?FullClear@idPlaytestStorage@@QAAXXZ
// EA  : 0x82689DB0
// RVA : 0x00689DB0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::FullClear(idPlaytestStorage *this)
{
  char *list; // r3
  char *v3; // r3
  idList<idPlaytestStorage::useFocusInfo_t,5> *v4; // r3
  char *v5; // r3
  char *v6; // r3
  idList<idPlaytestStorage::deathInfo_t,5> *v7; // r3
  idList<idPlaytestStorage::weaponFireInfo_t,5> *v8; // r3
  char *v9; // r3

  idPlaytestStorage::Clear(this);
  this->version = -1;
  this->numPlayers = 0;
  idStr::EnsureAlloced(this: &this->fileName, amount: 1, keepold: true, geometricGrowth: false);
  *this->fileName.data = 0;
  this->fileName.len = 0;
  if ( this->playerButtonInfo.listStatic == 0 || this->playerButtonInfo.listStatic == 2 )
  {
    list = (char *)this->playerButtonInfo.list;
    if ( list != nullptr )
      idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(ptr: list, num: this->playerButtonInfo.size);
    this->playerButtonInfo.list = nullptr;
    this->playerButtonInfo.size = 0;
  }
  this->playerButtonInfo.num = 0;
  if ( this->playerItemInfo.listStatic == 0 || this->playerItemInfo.listStatic == 2 )
  {
    v3 = (char *)this->playerItemInfo.list;
    if ( v3 != nullptr )
      idListArrayDelete<idList<idPlaytestStorage::itemInfo_t,5>>(ptr: v3, num: this->playerItemInfo.size);
    this->playerItemInfo.list = nullptr;
    this->playerItemInfo.size = 0;
  }
  this->playerItemInfo.num = 0;
  if ( this->playerUseFocusInfo.listStatic == 0 || this->playerUseFocusInfo.listStatic == 2 )
  {
    v4 = this->playerUseFocusInfo.list;
    if ( v4 != nullptr )
      idListArrayDelete<idList<idPlaytestStorage::useFocusInfo_t,5>>(ptr: v4, num: this->playerUseFocusInfo.size);
    this->playerUseFocusInfo.list = nullptr;
    this->playerUseFocusInfo.size = 0;
  }
  this->playerUseFocusInfo.num = 0;
  if ( this->playerUseQuickItemInfo.listStatic == 0 || this->playerUseQuickItemInfo.listStatic == 2 )
  {
    v5 = (char *)this->playerUseQuickItemInfo.list;
    if ( v5 != nullptr )
      idListArrayDelete<idList<idPlaytestStorage::quickItemInfo_t,5>>(ptr: v5, num: this->playerUseQuickItemInfo.size);
    this->playerUseQuickItemInfo.list = nullptr;
    this->playerUseQuickItemInfo.size = 0;
  }
  this->playerUseQuickItemInfo.num = 0;
  if ( this->playerEquipItemInfo.listStatic == 0 || this->playerEquipItemInfo.listStatic == 2 )
  {
    v6 = (char *)this->playerEquipItemInfo.list;
    if ( v6 != nullptr )
      idListArrayDelete<idList<idPlaytestStorage::quickItemInfo_t,5>>(ptr: v6, num: this->playerEquipItemInfo.size);
    this->playerEquipItemInfo.list = nullptr;
    this->playerEquipItemInfo.size = 0;
  }
  this->playerEquipItemInfo.num = 0;
  if ( this->playerDeathInfo.listStatic == 0 || this->playerDeathInfo.listStatic == 2 )
  {
    v7 = this->playerDeathInfo.list;
    if ( v7 != nullptr )
      idListArrayDelete<idList<idPlaytestStorage::deathInfo_t,5>>(ptr: &v7->list, num: this->playerDeathInfo.size);
    this->playerDeathInfo.list = nullptr;
    this->playerDeathInfo.size = 0;
  }
  this->playerDeathInfo.num = 0;
  if ( this->playerWeaponFireInfo.listStatic == 0 || this->playerWeaponFireInfo.listStatic == 2 )
  {
    v8 = this->playerWeaponFireInfo.list;
    if ( v8 != nullptr )
      idListArrayDelete<idList<idPlaytestStorage::weaponFireInfo_t,5>>(
        ptr: &v8->list,
        num: this->playerWeaponFireInfo.size);
    this->playerWeaponFireInfo.list = nullptr;
    this->playerWeaponFireInfo.size = 0;
  }
  this->playerWeaponFireInfo.num = 0;
  if ( this->playerInventoryInfo.listStatic == 0 || this->playerInventoryInfo.listStatic == 2 )
  {
    v9 = (char *)this->playerInventoryInfo.list;
    if ( v9 != nullptr )
      idListArrayDelete<idList<idPlaytestStorage::inventoryInfo_t,5>>(ptr: v9, num: this->playerInventoryInfo.size);
    this->playerInventoryInfo.list = nullptr;
    this->playerInventoryInfo.size = 0;
  }
  this->playerInventoryInfo.num = 0;
  if ( this->playerBreadCrumbs.listStatic == 0 || this->playerBreadCrumbs.listStatic == 2 )
  {
    if ( this->playerBreadCrumbs.list != nullptr )
      idListArrayDelete<idPlaytestStorage::playerMainBreadCrumbInfo_t>(
        ptr: this->playerBreadCrumbs.list,
        num: this->playerBreadCrumbs.size);
    this->playerBreadCrumbs.list = nullptr;
    this->playerBreadCrumbs.size = 0;
  }
  this->playerBreadCrumbs.num = 0;
}


// ========================================================================
// ??0idPlaytestStorage@@QAA@XZ
// EA  : 0x8268A168
// RVA : 0x0068A168
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idPlaytestStorage *__fastcall idPlaytestStorage::idPlaytestStorage(idPlaytestStorage *this)
{
  this->playerBreadCrumbs.granularity = 0;
  this->playerBreadCrumbs.memTag = 5;
  this->playerBreadCrumbs.listStatic = 0;
  this->playerBreadCrumbs.list = nullptr;
  this->playerBreadCrumbs.size = 0;
  this->playerBreadCrumbs.num = 0;
  this->playerButtonInfo.granularity = 0;
  this->playerButtonInfo.memTag = 5;
  this->playerButtonInfo.listStatic = 0;
  this->playerButtonInfo.list = nullptr;
  this->playerButtonInfo.size = 0;
  this->playerButtonInfo.num = 0;
  this->playerItemInfo.granularity = 0;
  this->playerItemInfo.memTag = 5;
  this->playerItemInfo.listStatic = 0;
  this->playerItemInfo.list = nullptr;
  this->playerItemInfo.size = 0;
  this->playerItemInfo.num = 0;
  this->playerUseFocusInfo.granularity = 0;
  this->playerUseFocusInfo.memTag = 5;
  this->playerUseFocusInfo.listStatic = 0;
  this->playerUseFocusInfo.list = nullptr;
  this->playerUseFocusInfo.size = 0;
  this->playerUseFocusInfo.num = 0;
  this->playerUseQuickItemInfo.granularity = 0;
  this->playerUseQuickItemInfo.memTag = 5;
  this->playerUseQuickItemInfo.listStatic = 0;
  this->playerUseQuickItemInfo.list = nullptr;
  this->playerUseQuickItemInfo.size = 0;
  this->playerUseQuickItemInfo.num = 0;
  this->playerEquipItemInfo.granularity = 0;
  this->playerEquipItemInfo.memTag = 5;
  this->playerEquipItemInfo.listStatic = 0;
  this->playerEquipItemInfo.list = nullptr;
  this->playerEquipItemInfo.size = 0;
  this->playerEquipItemInfo.num = 0;
  this->playerDeathInfo.granularity = 0;
  this->playerDeathInfo.memTag = 5;
  this->playerDeathInfo.listStatic = 0;
  this->playerDeathInfo.list = nullptr;
  this->playerDeathInfo.size = 0;
  this->playerDeathInfo.num = 0;
  this->playerWeaponFireInfo.granularity = 0;
  this->playerWeaponFireInfo.memTag = 5;
  this->playerWeaponFireInfo.listStatic = 0;
  this->playerWeaponFireInfo.list = nullptr;
  this->playerWeaponFireInfo.size = 0;
  this->playerWeaponFireInfo.num = 0;
  this->playerInventoryInfo.granularity = 0;
  this->playerInventoryInfo.memTag = 5;
  this->playerInventoryInfo.listStatic = 0;
  this->playerInventoryInfo.list = nullptr;
  this->playerInventoryInfo.size = 0;
  this->playerInventoryInfo.num = 0;
  this->radiusDamageInfo.granularity = 0;
  this->radiusDamageInfo.memTag = 5;
  this->radiusDamageInfo.listStatic = 0;
  this->radiusDamageInfo.list = nullptr;
  this->radiusDamageInfo.size = 0;
  this->radiusDamageInfo.num = 0;
  this->otherDeathInfo.granularity = 0;
  this->otherDeathInfo.memTag = 5;
  this->otherDeathInfo.listStatic = 0;
  this->otherDeathInfo.list = nullptr;
  this->otherDeathInfo.size = 0;
  this->otherDeathInfo.num = 0;
  this->otherWeaponFireInfo.granularity = 0;
  this->otherWeaponFireInfo.memTag = 5;
  this->otherWeaponFireInfo.listStatic = 0;
  this->otherWeaponFireInfo.list = nullptr;
  this->otherWeaponFireInfo.size = 0;
  this->otherWeaponFireInfo.num = 0;
  this->ai2Info.granularity = 0;
  this->ai2Info.memTag = 5;
  this->ai2Info.listStatic = 0;
  this->ai2Info.list = nullptr;
  this->ai2Info.size = 0;
  this->ai2Info.num = 0;
  this->aiVehicleInfo.granularity = 0;
  this->aiVehicleInfo.memTag = 5;
  this->aiVehicleInfo.listStatic = 0;
  this->aiVehicleInfo.list = nullptr;
  this->aiVehicleInfo.size = 0;
  this->aiVehicleInfo.num = 0;
  this->buildVersionString.len = 0;
  this->buildVersionString.allocedAndFlag = 20;
  this->buildVersionString.data = this->buildVersionString.baseBuffer;
  this->buildVersionString.baseBuffer[0] = 0;
  this->machineName.allocedAndFlag = 20;
  this->machineName.len = 0;
  this->machineName.data = this->machineName.baseBuffer;
  this->machineName.baseBuffer[0] = 0;
  this->fileName.allocedAndFlag = 20;
  this->fileName.len = 0;
  this->fileName.data = this->fileName.baseBuffer;
  this->fileName.baseBuffer[0] = 0;
  this->playMapName.allocedAndFlag = 20;
  this->playMapName.len = 0;
  this->playMapName.data = this->playMapName.baseBuffer;
  this->playMapName.baseBuffer[0] = 0;
  this->activeLayers.granularity = 0;
  this->activeLayers.memTag = 5;
  this->activeLayers.listStatic = 0;
  this->activeLayers.list = nullptr;
  this->activeLayers.size = 0;
  this->activeLayers.num = 0;
  this->numPlayers = 0;
  this->version = -1;
  this->beginTime = -1;
  this->lastTime = 0;
  this->offsetTime = 0;
  this->buildNumberMajor = -1;
  this->buildNumberMinor = -1;
  return this;
}


// ========================================================================
// __unwind$256457
// EA  : 0x8268A3E4
// RVA : 0x0068A3E4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256457()
{
  int v0; // r12

  idList<idPlaytestStorage::playerMainBreadCrumbInfo_t,5>::Clear(this: *(idList<idPlaytestStorage::playerMainBreadCrumbInfo_t,5> **)(v0 - 32 + 52));
}


// ========================================================================
// __unwind$256458
// EA  : 0x8268A40C
// RVA : 0x0068A40C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256458()
{
  int v0; // r12

  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: (idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> *)(*(_DWORD *)(v0 - 32 + 52) + 16));
}


// ========================================================================
// __unwind$256459
// EA  : 0x8268A438
// RVA : 0x0068A438
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256459()
{
  int v0; // r12

  idList<idList<idPlaytestStorage::itemInfo_t,5>,5>::Clear(this: (idList<idList<idPlaytestStorage::itemInfo_t,5>,5> *)(*(_DWORD *)(v0 - 32 + 52) + 32));
}


// ========================================================================
// __unwind$256460
// EA  : 0x8268A464
// RVA : 0x0068A464
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256460()
{
  int v0; // r12

  idList<idList<idPlaytestStorage::useFocusInfo_t,5>,5>::~idList<idList<idPlaytestStorage::useFocusInfo_t,5>,5>(this: (idList<idList<idPlaytestStorage::useFocusInfo_t,5>,5> *)(*(_DWORD *)(v0 - 32 + 52) + 48));
}


// ========================================================================
// __unwind$256461
// EA  : 0x8268A490
// RVA : 0x0068A490
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256461()
{
  int v0; // r12

  idList<idList<idPlaytestStorage::equipItemInfo_t,5>,5>::~idList<idList<idPlaytestStorage::equipItemInfo_t,5>,5>(this: (idList<idList<idPlaytestStorage::equipItemInfo_t,5>,5> *)(*(_DWORD *)(v0 - 32 + 52) + 64));
}


// ========================================================================
// __unwind$256462
// EA  : 0x8268A4BC
// RVA : 0x0068A4BC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256462()
{
  int v0; // r12

  idList<idList<idPlaytestStorage::equipItemInfo_t,5>,5>::~idList<idList<idPlaytestStorage::equipItemInfo_t,5>,5>(this: (idList<idList<idPlaytestStorage::equipItemInfo_t,5>,5> *)(*(_DWORD *)(v0 - 32 + 52) + 80));
}


// ========================================================================
// __unwind$256463
// EA  : 0x8268A4E8
// RVA : 0x0068A4E8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256463()
{
  int v0; // r12

  idList<idList<idPlaytestStorage::deathInfo_t,5>,5>::~idList<idList<idPlaytestStorage::deathInfo_t,5>,5>(this: (idList<idList<idPlaytestStorage::deathInfo_t,5>,5> *)(*(_DWORD *)(v0 - 32 + 52) + 96));
}


// ========================================================================
// __unwind$256464
// EA  : 0x8268A514
// RVA : 0x0068A514
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256464()
{
  int v0; // r12

  idList<idList<idPlaytestStorage::weaponFireInfo_t,5>,5>::Clear(this: (idList<idList<idPlaytestStorage::weaponFireInfo_t,5>,5> *)(*(_DWORD *)(v0 - 32 + 52) + 112));
}


// ========================================================================
// __unwind$256465
// EA  : 0x8268A540
// RVA : 0x0068A540
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256465()
{
  int v0; // r12

  idList<idList<idPlaytestStorage::inventoryInfo_t,5>,5>::~idList<idList<idPlaytestStorage::inventoryInfo_t,5>,5>(this: (idList<idList<idPlaytestStorage::inventoryInfo_t,5>,5> *)(*(_DWORD *)(v0 - 32 + 52) + 128));
}


// ========================================================================
// __unwind$256466
// EA  : 0x8268A56C
// RVA : 0x0068A56C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256466()
{
  int v0; // r12

  idList<idPlaytestStorage::radiusDamageInfo_t,5>::~idList<idPlaytestStorage::radiusDamageInfo_t,5>(this: (idList<idPlaytestStorage::radiusDamageInfo_t,5> *)(*(_DWORD *)(v0 - 32 + 52) + 144));
}


// ========================================================================
// __unwind$256467
// EA  : 0x8268A598
// RVA : 0x0068A598
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256467()
{
  int v0; // r12

  idList<idPlaytestStorage::deathInfo_t,5>::~idList<idPlaytestStorage::deathInfo_t,5>(this: (idList<idPlaytestStorage::deathInfo_t,5> *)(*(_DWORD *)(v0 - 32 + 52) + 160));
}


// ========================================================================
// __unwind$256468
// EA  : 0x8268A5C4
// RVA : 0x0068A5C4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256468()
{
  int v0; // r12

  idList<idPlaytestStorage::weaponFireInfo_t,5>::Clear(this: (idList<idPlaytestStorage::weaponFireInfo_t,5> *)(*(_DWORD *)(v0 - 32 + 52) + 176));
}


// ========================================================================
// __unwind$256469
// EA  : 0x8268A5F0
// RVA : 0x0068A5F0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256469()
{
  int v0; // r12

  idList<idPlaytestStorage::ai2Info_t,5>::Clear(this: (idList<idPlaytestStorage::ai2Info_t,5> *)(*(_DWORD *)(v0 - 32 + 52)
                                                                                               + 192));
}


// ========================================================================
// __unwind$256470
// EA  : 0x8268A61C
// RVA : 0x0068A61C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256470()
{
  int v0; // r12

  idList<idPlaytestStorage::aiVehicleInfo_t,5>::Clear(this: (idList<idPlaytestStorage::aiVehicleInfo_t,5> *)(*(_DWORD *)(v0 - 32 + 52) + 208));
}


// ========================================================================
// __unwind$256471
// EA  : 0x8268A648
// RVA : 0x0068A648
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256471()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 232));
}


// ========================================================================
// __unwind$256472
// EA  : 0x8268A674
// RVA : 0x0068A674
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256472()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 272));
}


// ========================================================================
// __unwind$256473
// EA  : 0x8268A6A0
// RVA : 0x0068A6A0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256473()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 304));
}


// ========================================================================
// __unwind$256474
// EA  : 0x8268A6CC
// RVA : 0x0068A6CC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256474()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 336));
}


// ========================================================================
// ??1idPlaytestStorage@@QAA@XZ
// EA  : 0x8268A700
// RVA : 0x0068A700
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::~idPlaytestStorage(idPlaytestStorage *this)
{
  idStr *list; // r3
  char *v3; // r3
  idPlaytestStorage::ai2Info_t *v4; // r3
  idPlaytestStorage::weaponFireInfo_t *v5; // r3
  idPlaytestStorage::deathInfo_t *v6; // r3
  idPlaytestStorage::radiusDamageInfo_t *v7; // r3
  char *v8; // r3
  idList<idPlaytestStorage::weaponFireInfo_t,5> *v9; // r3
  idList<idPlaytestStorage::deathInfo_t,5> *v10; // r3
  char *v11; // r3
  char *v12; // r3
  idList<idPlaytestStorage::useFocusInfo_t,5> *v13; // r3
  char *v14; // r3
  char *v15; // r3

  idPlaytestStorage::FullClear(this);
  if ( this->activeLayers.listStatic == 0 || this->activeLayers.listStatic == 2 )
  {
    list = this->activeLayers.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->activeLayers.size);
    this->activeLayers.list = nullptr;
    this->activeLayers.size = 0;
  }
  this->activeLayers.num = 0;
  idStr::FreeData(this: &this->playMapName);
  idStr::FreeData(this: &this->fileName);
  idStr::FreeData(this: &this->machineName);
  idStr::FreeData(this: &this->buildVersionString);
  if ( this->aiVehicleInfo.listStatic == 0 || this->aiVehicleInfo.listStatic == 2 )
  {
    v3 = (char *)this->aiVehicleInfo.list;
    if ( v3 != nullptr )
      idListArrayDelete<idPlaytestStorage::aiVehicleInfo_t>(ptr: v3, num: this->aiVehicleInfo.size);
    this->aiVehicleInfo.list = nullptr;
    this->aiVehicleInfo.size = 0;
  }
  this->aiVehicleInfo.num = 0;
  if ( this->ai2Info.listStatic == 0 || this->ai2Info.listStatic == 2 )
  {
    v4 = this->ai2Info.list;
    if ( v4 != nullptr )
      idListArrayDelete<idPlaytestStorage::ai2Info_t>(ptr: v4, num: this->ai2Info.size);
    this->ai2Info.list = nullptr;
    this->ai2Info.size = 0;
  }
  this->ai2Info.num = 0;
  if ( this->otherWeaponFireInfo.listStatic == 0 || this->otherWeaponFireInfo.listStatic == 2 )
  {
    v5 = this->otherWeaponFireInfo.list;
    if ( v5 != nullptr )
      idListArrayDelete<idPlaytestStorage::weaponFireInfo_t>(ptr: v5, num: this->otherWeaponFireInfo.size);
    this->otherWeaponFireInfo.list = nullptr;
    this->otherWeaponFireInfo.size = 0;
  }
  this->otherWeaponFireInfo.num = 0;
  if ( this->otherDeathInfo.listStatic == 0 || this->otherDeathInfo.listStatic == 2 )
  {
    v6 = this->otherDeathInfo.list;
    if ( v6 != nullptr )
      idListArrayDelete<idPlaytestStorage::deathInfo_t>(ptr: v6, num: this->otherDeathInfo.size);
    this->otherDeathInfo.list = nullptr;
    this->otherDeathInfo.size = 0;
  }
  this->otherDeathInfo.num = 0;
  if ( this->radiusDamageInfo.listStatic == 0 || this->radiusDamageInfo.listStatic == 2 )
  {
    v7 = this->radiusDamageInfo.list;
    if ( v7 != nullptr )
      idListArrayDelete<idPlaytestStorage::radiusDamageInfo_t>(ptr: v7, num: this->radiusDamageInfo.size);
    this->radiusDamageInfo.list = nullptr;
    this->radiusDamageInfo.size = 0;
  }
  this->radiusDamageInfo.num = 0;
  if ( this->playerInventoryInfo.listStatic == 0 || this->playerInventoryInfo.listStatic == 2 )
  {
    v8 = (char *)this->playerInventoryInfo.list;
    if ( v8 != nullptr )
      idListArrayDelete<idList<idPlaytestStorage::inventoryInfo_t,5>>(ptr: v8, num: this->playerInventoryInfo.size);
    this->playerInventoryInfo.list = nullptr;
    this->playerInventoryInfo.size = 0;
  }
  this->playerInventoryInfo.num = 0;
  if ( this->playerWeaponFireInfo.listStatic == 0 || this->playerWeaponFireInfo.listStatic == 2 )
  {
    v9 = this->playerWeaponFireInfo.list;
    if ( v9 != nullptr )
      idListArrayDelete<idList<idPlaytestStorage::weaponFireInfo_t,5>>(
        ptr: &v9->list,
        num: this->playerWeaponFireInfo.size);
    this->playerWeaponFireInfo.list = nullptr;
    this->playerWeaponFireInfo.size = 0;
  }
  this->playerWeaponFireInfo.num = 0;
  if ( this->playerDeathInfo.listStatic == 0 || this->playerDeathInfo.listStatic == 2 )
  {
    v10 = this->playerDeathInfo.list;
    if ( v10 != nullptr )
      idListArrayDelete<idList<idPlaytestStorage::deathInfo_t,5>>(ptr: &v10->list, num: this->playerDeathInfo.size);
    this->playerDeathInfo.list = nullptr;
    this->playerDeathInfo.size = 0;
  }
  this->playerDeathInfo.num = 0;
  if ( this->playerEquipItemInfo.listStatic == 0 || this->playerEquipItemInfo.listStatic == 2 )
  {
    v11 = (char *)this->playerEquipItemInfo.list;
    if ( v11 != nullptr )
      idListArrayDelete<idList<idPlaytestStorage::quickItemInfo_t,5>>(ptr: v11, num: this->playerEquipItemInfo.size);
    this->playerEquipItemInfo.list = nullptr;
    this->playerEquipItemInfo.size = 0;
  }
  this->playerEquipItemInfo.num = 0;
  if ( this->playerUseQuickItemInfo.listStatic == 0 || this->playerUseQuickItemInfo.listStatic == 2 )
  {
    v12 = (char *)this->playerUseQuickItemInfo.list;
    if ( v12 != nullptr )
      idListArrayDelete<idList<idPlaytestStorage::quickItemInfo_t,5>>(ptr: v12, num: this->playerUseQuickItemInfo.size);
    this->playerUseQuickItemInfo.list = nullptr;
    this->playerUseQuickItemInfo.size = 0;
  }
  this->playerUseQuickItemInfo.num = 0;
  if ( this->playerUseFocusInfo.listStatic == 0 || this->playerUseFocusInfo.listStatic == 2 )
  {
    v13 = this->playerUseFocusInfo.list;
    if ( v13 != nullptr )
      idListArrayDelete<idList<idPlaytestStorage::useFocusInfo_t,5>>(ptr: v13, num: this->playerUseFocusInfo.size);
    this->playerUseFocusInfo.list = nullptr;
    this->playerUseFocusInfo.size = 0;
  }
  this->playerUseFocusInfo.num = 0;
  if ( this->playerItemInfo.listStatic == 0 || this->playerItemInfo.listStatic == 2 )
  {
    v14 = (char *)this->playerItemInfo.list;
    if ( v14 != nullptr )
      idListArrayDelete<idList<idPlaytestStorage::itemInfo_t,5>>(ptr: v14, num: this->playerItemInfo.size);
    this->playerItemInfo.list = nullptr;
    this->playerItemInfo.size = 0;
  }
  this->playerItemInfo.num = 0;
  if ( this->playerButtonInfo.listStatic == 0 || this->playerButtonInfo.listStatic == 2 )
  {
    v15 = (char *)this->playerButtonInfo.list;
    if ( v15 != nullptr )
      idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(ptr: v15, num: this->playerButtonInfo.size);
    this->playerButtonInfo.list = nullptr;
    this->playerButtonInfo.size = 0;
  }
  this->playerButtonInfo.num = 0;
  if ( this->playerBreadCrumbs.listStatic == 0 || this->playerBreadCrumbs.listStatic == 2 )
  {
    if ( this->playerBreadCrumbs.list != nullptr )
      idListArrayDelete<idPlaytestStorage::playerMainBreadCrumbInfo_t>(
        ptr: this->playerBreadCrumbs.list,
        num: this->playerBreadCrumbs.size);
    this->playerBreadCrumbs.list = nullptr;
    this->playerBreadCrumbs.size = 0;
  }
  this->playerBreadCrumbs.num = 0;
}


// ========================================================================
// __unwind$256873
// EA  : 0x8268AA54
// RVA : 0x0068AA54
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256873()
{
  int v0; // r12

  idList<idPlaytestStorage::playerMainBreadCrumbInfo_t,5>::Clear(this: *(idList<idPlaytestStorage::playerMainBreadCrumbInfo_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$256874
// EA  : 0x8268AA7C
// RVA : 0x0068AA7C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256874()
{
  int v0; // r12

  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: (idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// __unwind$256875
// EA  : 0x8268AAA8
// RVA : 0x0068AAA8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256875()
{
  int v0; // r12

  idList<idList<idPlaytestStorage::itemInfo_t,5>,5>::Clear(this: (idList<idList<idPlaytestStorage::itemInfo_t,5>,5> *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}


// ========================================================================
// __unwind$256876
// EA  : 0x8268AAD4
// RVA : 0x0068AAD4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256876()
{
  int v0; // r12

  idList<idList<idPlaytestStorage::useFocusInfo_t,5>,5>::~idList<idList<idPlaytestStorage::useFocusInfo_t,5>,5>(this: (idList<idList<idPlaytestStorage::useFocusInfo_t,5>,5> *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// __unwind$256877
// EA  : 0x8268AB00
// RVA : 0x0068AB00
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256877()
{
  int v0; // r12

  idList<idList<idPlaytestStorage::equipItemInfo_t,5>,5>::~idList<idList<idPlaytestStorage::equipItemInfo_t,5>,5>(this: (idList<idList<idPlaytestStorage::equipItemInfo_t,5>,5> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// __unwind$256878
// EA  : 0x8268AB2C
// RVA : 0x0068AB2C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256878()
{
  int v0; // r12

  idList<idList<idPlaytestStorage::equipItemInfo_t,5>,5>::~idList<idList<idPlaytestStorage::equipItemInfo_t,5>,5>(this: (idList<idList<idPlaytestStorage::equipItemInfo_t,5>,5> *)(*(_DWORD *)(v0 - 112 + 132) + 80));
}


// ========================================================================
// __unwind$256879
// EA  : 0x8268AB58
// RVA : 0x0068AB58
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256879()
{
  int v0; // r12

  idList<idList<idPlaytestStorage::deathInfo_t,5>,5>::~idList<idList<idPlaytestStorage::deathInfo_t,5>,5>(this: (idList<idList<idPlaytestStorage::deathInfo_t,5>,5> *)(*(_DWORD *)(v0 - 112 + 132) + 96));
}


// ========================================================================
// __unwind$256880
// EA  : 0x8268AB84
// RVA : 0x0068AB84
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256880()
{
  int v0; // r12

  idList<idList<idPlaytestStorage::weaponFireInfo_t,5>,5>::Clear(this: (idList<idList<idPlaytestStorage::weaponFireInfo_t,5>,5> *)(*(_DWORD *)(v0 - 112 + 132) + 112));
}


// ========================================================================
// __unwind$256881
// EA  : 0x8268ABB0
// RVA : 0x0068ABB0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256881()
{
  int v0; // r12

  idList<idList<idPlaytestStorage::inventoryInfo_t,5>,5>::~idList<idList<idPlaytestStorage::inventoryInfo_t,5>,5>(this: (idList<idList<idPlaytestStorage::inventoryInfo_t,5>,5> *)(*(_DWORD *)(v0 - 112 + 132) + 128));
}


// ========================================================================
// __unwind$256882
// EA  : 0x8268ABDC
// RVA : 0x0068ABDC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256882()
{
  int v0; // r12

  idList<idPlaytestStorage::radiusDamageInfo_t,5>::~idList<idPlaytestStorage::radiusDamageInfo_t,5>(this: (idList<idPlaytestStorage::radiusDamageInfo_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 144));
}


// ========================================================================
// __unwind$256883
// EA  : 0x8268AC08
// RVA : 0x0068AC08
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256883()
{
  int v0; // r12

  idList<idPlaytestStorage::deathInfo_t,5>::~idList<idPlaytestStorage::deathInfo_t,5>(this: (idList<idPlaytestStorage::deathInfo_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 160));
}


// ========================================================================
// __unwind$256884
// EA  : 0x8268AC34
// RVA : 0x0068AC34
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256884()
{
  int v0; // r12

  idList<idPlaytestStorage::weaponFireInfo_t,5>::Clear(this: (idList<idPlaytestStorage::weaponFireInfo_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 176));
}


// ========================================================================
// __unwind$256885
// EA  : 0x8268AC60
// RVA : 0x0068AC60
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256885()
{
  int v0; // r12

  idList<idPlaytestStorage::ai2Info_t,5>::Clear(this: (idList<idPlaytestStorage::ai2Info_t,5> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                               + 192));
}


// ========================================================================
// __unwind$256886
// EA  : 0x8268AC8C
// RVA : 0x0068AC8C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256886()
{
  int v0; // r12

  idList<idPlaytestStorage::aiVehicleInfo_t,5>::Clear(this: (idList<idPlaytestStorage::aiVehicleInfo_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 208));
}


// ========================================================================
// __unwind$256887
// EA  : 0x8268ACB8
// RVA : 0x0068ACB8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256887()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 232));
}


// ========================================================================
// __unwind$256888
// EA  : 0x8268ACE4
// RVA : 0x0068ACE4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256888()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 272));
}


// ========================================================================
// __unwind$256889
// EA  : 0x8268AD10
// RVA : 0x0068AD10
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256889()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 304));
}


// ========================================================================
// __unwind$256890
// EA  : 0x8268AD3C
// RVA : 0x0068AD3C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256890()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 336));
}


// ========================================================================
// __unwind$256891
// EA  : 0x8268AD68
// RVA : 0x0068AD68
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_256891()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 372));
}


// ========================================================================
// ?CreatePlaytestModelFile_ProcessFile@idPlaytestStorage@@CAXVidStr@@@Z
// EA  : 0x8268ADA0
// RVA : 0x0068ADA0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::CreatePlaytestModelFile_ProcessFile(idStr *filename)
{
  bool v2; // r3
  char *data; // r4
  idPlaytestStorage v4; // [sp+50h] [-1B0h] BYREF

  idPlaytestStorage::idPlaytestStorage(this: &v4);
  v2 = idPlaytestStorage::ReadBinaryFile(this: &v4, fileName: filename);
  data = filename->data;
  if ( v2 )
  {
    idLib::Printf(fmt: "creating model for %s\n", data);
    idStr::StripFileExtension(this: filename);
    idPlaytestStorage::Write_Models(this: &v4, filePath: filename);
  }
  else
  {
    idLib::Warning(fmt: "couldn't load file %s", data);
  }
  idPlaytestStorage::~idPlaytestStorage(this: &v4);
  idStr::FreeData(this: filename);
}


// ========================================================================
// __unwind$257912
// EA  : 0x8268AE3C
// RVA : 0x0068AE3C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_257912()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 512 + 532));
}


// ========================================================================
// __unwind$257913
// EA  : 0x8268AE64
// RVA : 0x0068AE64
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_257913()
{
  int v0; // r12

  idPlaytestStorage::~idPlaytestStorage(this: (idPlaytestStorage *)(v0 - 512 + 80));
}


// ========================================================================
// ?CreatePlaytestModelFile_ProcessFolder@idPlaytestStorage@@CAXVidStr@@@Z
// EA  : 0x8268AE98
// RVA : 0x0068AE98
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::CreatePlaytestModelFile_ProcessFolder(idStr *in_foldername)
{
  idStr *FileExtension; // r3
  unsigned int v3; // r30
  idStr *v4; // r3
  idFileList *v5; // r28
  int v6; // r30
  int v7; // r29
  idStr *v8; // r3
  idFileList *v9; // r29
  int v10; // r25
  int v11; // r30
  int len; // r28
  char *v13; // r10
  char *v14; // r9
  char v15; // r11
  idStr v16; // [sp+60h] [-E0h] BYREF
  idStr v17; // [sp+80h] [-C0h] BYREF
  idStr v18; // [sp+A0h] [-A0h] BYREF
  idStr v19[4]; // [sp+C0h] [-80h] BYREF

  FileExtension = idStr::GetFileExtension(this: v19, result: in_foldername);
  v3 = (-FileExtension->len & (unsigned int)~FileExtension->len) >> 31;
  idStr::FreeData(this: v19);
  if ( v3 != 0 )
  {
    v4 = idStr::idStr(this: &v16, text: in_foldername);
    idPlaytestStorage::CreatePlaytestModelFile_ProcessFile(filename: v4);
  }
  else
  {
    idLib::Printf(fmt: "Playtest model file creation: Processing %s\n", in_foldername->data);
    v5 = fileSystem->ListFiles(this: fileSystem, a2: in_foldername->data, a3: "/", a4: 1, a5: 1);
    v6 = 0;
    if ( v5->list.num > 0 )
    {
      v7 = 0;
      do
      {
        idStr::idStr(this: &v18, text: v5->list.list[v7].data);
        v8 = idStr::idStr(this: &v16, text: &v18);
        idPlaytestStorage::CreatePlaytestModelFile_ProcessFolder(in_foldername: v8);
        idStr::FreeData(this: &v18);
        ++v6;
        ++v7;
      }
      while ( v6 < v5->list.num );
    }
    v9 = fileSystem->ListFiles(this: fileSystem, a2: in_foldername->data, a3: ".ptb", a4: 1, a5: 1);
    v10 = 0;
    if ( v9->list.num > 0 )
    {
      v11 = 0;
      do
      {
        idStr::idStr(this: &v17, text: v9->list.list[v11].data);
        len = v17.len;
        v16.data = v16.baseBuffer;
        v16.len = 0;
        v16.baseBuffer[0] = 0;
        v16.allocedAndFlag = 20;
        if ( v17.len + 1 > 20 )
          idStr::ReAllocate(this: &v16, amount: v17.len + 1, keepold: true);
        v13 = v17.data - 1;
        v14 = v16.data - 1;
        do
        {
          v15 = *++v13;
          *++v14 = *v13;
        }
        while ( v15 != 0 );
        v16.len = len;
        idPlaytestStorage::CreatePlaytestModelFile_ProcessFolder(in_foldername: &v16);
        idStr::FreeData(this: &v17);
        ++v10;
        ++v11;
      }
      while ( v10 < v9->list.num );
    }
  }
  idStr::FreeData(this: in_foldername);
}


// ========================================================================
// __unwind$257957
// EA  : 0x8268B0D8
// RVA : 0x0068B0D8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_257957()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 320 + 340));
}


// ========================================================================
// __unwind$257960
// EA  : 0x8268B100
// RVA : 0x0068B100
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_257960()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 160));
}


// ========================================================================
// __unwind$257962
// EA  : 0x8268B128
// RVA : 0x0068B128
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_257962()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// ?Cmd_CreatePlaytestModel_f@idPlaytestStorage@@SAXABVidCmdArgs@@@Z
// EA  : 0x8268B158
// RVA : 0x0068B158
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::Cmd_CreatePlaytestModel_f(const idCmdArgs *args)
{
  const char *v1; // r4
  idStr *v2; // r3
  idStr v3; // [sp+60h] [-60h] BYREF
  idStr v4; // [sp+80h] [-40h] BYREF

  if ( args->argc >= 2 )
  {
    if ( args->argc <= 1 )
      v1 = &byte_8200D768;
    else
      v1 = args->argv[1];
    idStr::idStr(this: &v3, text: v1);
    if ( idStr::Icmp(s1: v3.data, s2: "*") == 0 )
      idStr::operator=(this: &v3, text: "playtest");
    common->SetRefreshOnPrint(this: common, a2: true);
    v2 = idStr::idStr(this: &v4, text: &v3);
    idPlaytestStorage::CreatePlaytestModelFile_ProcessFolder(in_foldername: v2);
    common->SetRefreshOnPrint(this: common, a2: false);
    idStr::FreeData(this: &v3);
  }
  else
  {
    idLib::Printf(fmt: "must give a playtest file name or folder\n");
  }
}


// ========================================================================
// __unwind$258160
// EA  : 0x8268B23C
// RVA : 0x0068B23C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258160()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?CreatePlaytestTextFile_ProcessFile@idPlaytestStorage@@CAXVidStr@@@Z
// EA  : 0x8268B270
// RVA : 0x0068B270
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::CreatePlaytestTextFile_ProcessFile(idStr *filename)
{
  bool BinaryFile; // r3
  char *data; // r4
  idStr *v4; // r29
  size_t len; // r28
  idPlaytestStorage *PlayMapName; // r3
  idList<idStr,5> v7; // [sp+50h] [-210h] BYREF
  idStr v8; // [sp+60h] [-200h] BYREF
  idPlaytestStorage v9; // [sp+80h] [-1E0h] BYREF
  idList<idStr,5> v10; // [sp+214h] [-4Ch] BYREF

  idPlaytestStorage::idPlaytestStorage(this: (idPlaytestStorage *)&v9.playerItemInfo);
  BinaryFile = idPlaytestStorage::ReadBinaryFile(this: (idPlaytestStorage *)&v9.playerItemInfo, fileName: filename);
  data = filename->data;
  if ( BinaryFile )
  {
    idLib::Printf(fmt: "creating text for %s\n", data);
    idStr::StripFileExtension(this: filename);
    v4 = operator+(result: &v8, a: filename, b: ".ptt");
    len = v4->len;
    idStr::EnsureAlloced(this: filename, amount: v4->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: filename->data, Src: v4->data, Size: len);
    filename->data[len] = 0;
    filename->len = len;
    idStr::FreeData(this: &v8);
    *(_WORD *)&v7.memTag = 1280;
    memset(&v7, 0, 14);
    idList<idStr,58>::operator=(this: &v7, other: &v10);
    PlayMapName = idPlaytestStorage::GetPlayMapName(this: &v9, result: (idStr *)&v9.playerItemInfo);
    idPlaytestStorage::WriteTextFile(
      this: (idPlaytestStorage *)&v9.playerItemInfo,
      fileName: filename,
      mapName: (const idStr *)PlayMapName,
      mapLayersSpawned: &v7);
    idStr::FreeData(this: (idStr *)&v9);
    idList<idStr,99>::~idList<idStr,99>(this: &v7);
  }
  else
  {
    idLib::Warning(fmt: "couldn't load file %s", data);
  }
  idPlaytestStorage::~idPlaytestStorage(this: (idPlaytestStorage *)&v9.playerItemInfo);
  idStr::FreeData(this: filename);
}


// ========================================================================
// __unwind$258197
// EA  : 0x8268B398
// RVA : 0x0068B398
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258197()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 608 + 628));
}


// ========================================================================
// __unwind$258198
// EA  : 0x8268B3C0
// RVA : 0x0068B3C0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258198()
{
  int v0; // r12

  idPlaytestStorage::~idPlaytestStorage(this: (idPlaytestStorage *)(v0 - 608 + 160));
}


// ========================================================================
// __unwind$258199
// EA  : 0x8268B3E8
// RVA : 0x0068B3E8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258199()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 96));
}


// ========================================================================
// __unwind$258200
// EA  : 0x8268B410
// RVA : 0x0068B410
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258200()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 608 + 80));
}


// ========================================================================
// __unwind$258201
// EA  : 0x8268B438
// RVA : 0x0068B438
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258201()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 128));
}


// ========================================================================
// ?CreatePlaytestTextFile_ProcessFolder@idPlaytestStorage@@CAXVidStr@@@Z
// EA  : 0x8268B468
// RVA : 0x0068B468
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::CreatePlaytestTextFile_ProcessFolder(idStr *in_foldername)
{
  idStr *FileExtension; // r3
  unsigned int v3; // r30
  idStr *v4; // r3
  idFileList *v5; // r28
  int v6; // r30
  int v7; // r29
  idStr *v8; // r3
  idFileList *v9; // r29
  int v10; // r25
  int v11; // r30
  int len; // r28
  char *v13; // r10
  char *v14; // r9
  char v15; // r11
  idStr v16; // [sp+60h] [-E0h] BYREF
  idStr v17; // [sp+80h] [-C0h] BYREF
  idStr v18; // [sp+A0h] [-A0h] BYREF
  idStr v19[4]; // [sp+C0h] [-80h] BYREF

  FileExtension = idStr::GetFileExtension(this: v19, result: in_foldername);
  v3 = (-FileExtension->len & (unsigned int)~FileExtension->len) >> 31;
  idStr::FreeData(this: v19);
  if ( v3 != 0 )
  {
    v4 = idStr::idStr(this: &v16, text: in_foldername);
    idPlaytestStorage::CreatePlaytestTextFile_ProcessFile(filename: v4);
  }
  else
  {
    idLib::Printf(fmt: "Playtest text file creation: Processing %s\n", in_foldername->data);
    v5 = fileSystem->ListFiles(this: fileSystem, a2: in_foldername->data, a3: "/", a4: 1, a5: 1);
    v6 = 0;
    if ( v5->list.num > 0 )
    {
      v7 = 0;
      do
      {
        idStr::idStr(this: &v18, text: v5->list.list[v7].data);
        v8 = idStr::idStr(this: &v16, text: &v18);
        idPlaytestStorage::CreatePlaytestTextFile_ProcessFolder(in_foldername: v8);
        idStr::FreeData(this: &v18);
        ++v6;
        ++v7;
      }
      while ( v6 < v5->list.num );
    }
    v9 = fileSystem->ListFiles(this: fileSystem, a2: in_foldername->data, a3: ".ptb", a4: 1, a5: 1);
    v10 = 0;
    if ( v9->list.num > 0 )
    {
      v11 = 0;
      do
      {
        idStr::idStr(this: &v17, text: v9->list.list[v11].data);
        len = v17.len;
        v16.data = v16.baseBuffer;
        v16.len = 0;
        v16.baseBuffer[0] = 0;
        v16.allocedAndFlag = 20;
        if ( v17.len + 1 > 20 )
          idStr::ReAllocate(this: &v16, amount: v17.len + 1, keepold: true);
        v13 = v17.data - 1;
        v14 = v16.data - 1;
        do
        {
          v15 = *++v13;
          *++v14 = *v13;
        }
        while ( v15 != 0 );
        v16.len = len;
        idPlaytestStorage::CreatePlaytestTextFile_ProcessFile(filename: &v16);
        idStr::FreeData(this: &v17);
        ++v10;
        ++v11;
      }
      while ( v10 < v9->list.num );
    }
  }
  idStr::FreeData(this: in_foldername);
}


// ========================================================================
// __unwind$258297
// EA  : 0x8268B6A8
// RVA : 0x0068B6A8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258297()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 320 + 340));
}


// ========================================================================
// __unwind$258300
// EA  : 0x8268B6D0
// RVA : 0x0068B6D0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258300()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 160));
}


// ========================================================================
// __unwind$258302
// EA  : 0x8268B6F8
// RVA : 0x0068B6F8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258302()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// ?Cmd_CreatePlaytestTextFile_f@idPlaytestStorage@@SAXABVidCmdArgs@@@Z
// EA  : 0x8268B728
// RVA : 0x0068B728
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::Cmd_CreatePlaytestTextFile_f(const idCmdArgs *args)
{
  const char *v1; // r4
  idStr *v2; // r3
  idStr v3; // [sp+60h] [-60h] BYREF
  idStr v4; // [sp+80h] [-40h] BYREF

  if ( args->argc >= 2 )
  {
    if ( args->argc <= 1 )
      v1 = &byte_8200D768;
    else
      v1 = args->argv[1];
    idStr::idStr(this: &v3, text: v1);
    if ( idStr::Icmp(s1: v3.data, s2: "*") == 0 )
      idStr::operator=(this: &v3, text: "playtest");
    common->SetRefreshOnPrint(this: common, a2: true);
    v2 = idStr::idStr(this: &v4, text: &v3);
    idPlaytestStorage::CreatePlaytestTextFile_ProcessFolder(in_foldername: v2);
    common->SetRefreshOnPrint(this: common, a2: false);
    idStr::FreeData(this: &v3);
  }
  else
  {
    idLib::Printf(fmt: "must give a playtest file name or folder name\n");
  }
}


// ========================================================================
// __unwind$258500
// EA  : 0x8268B80C
// RVA : 0x0068B80C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258500()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?CreatePlaytestPlayerPathComboModel_ProcessFile@idPlaytestStorage@@CAXVidStr@@ABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x8268B840
// RVA : 0x0068B840
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::CreatePlaytestPlayerPathComboModel_ProcessFile(
        idStr *filename,
        const idList<idStaticModel *,5> *staticModels)
{
  bool v4; // r3
  char *data; // r4
  idPlaytestStorage v6; // [sp+50h] [-1B0h] BYREF

  idPlaytestStorage::idPlaytestStorage(this: &v6);
  v4 = idPlaytestStorage::ReadBinaryFile(this: &v6, fileName: filename);
  data = filename->data;
  if ( v4 )
  {
    idLib::Printf(fmt: "creating PlaytestPlayerPathComboModel for %s\n", data);
    idPlaytestStorage::GeneratePlayerPathNormalModels(this: &v6, staticModels);
    idPlaytestStorage::GeneratePlayerPathMiscModels(this: &v6, staticModels);
    idPlaytestStorage::GeneratePlayerPathVehicleModels(this: &v6, staticModels);
  }
  else
  {
    idLib::Warning(fmt: "couldn't load file %s", data);
  }
  idPlaytestStorage::~idPlaytestStorage(this: &v6);
  idStr::FreeData(this: filename);
}


// ========================================================================
// __unwind$258535
// EA  : 0x8268B8D8
// RVA : 0x0068B8D8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258535()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 512 + 532));
}


// ========================================================================
// __unwind$258536
// EA  : 0x8268B900
// RVA : 0x0068B900
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258536()
{
  int v0; // r12

  idPlaytestStorage::~idPlaytestStorage(this: (idPlaytestStorage *)(v0 - 512 + 80));
}


// ========================================================================
// ?CreatePlaytestPlayerPathComboModel_ProcessFolder@idPlaytestStorage@@CAXVidStr@@ABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x8268B930
// RVA : 0x0068B930
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::CreatePlaytestPlayerPathComboModel_ProcessFolder(
        idStr *in_foldername,
        const idList<idStaticModel *,5> *staticModels)
{
  idStr *FileExtension; // r3
  unsigned int v5; // r30
  idStr *v6; // r3
  idFileList *v7; // r28
  int v8; // r30
  int v9; // r29
  idStr *v10; // r3
  idFileList *v11; // r29
  int v12; // r25
  int v13; // r30
  int len; // r28
  char *v15; // r10
  char *v16; // r9
  char v17; // r11
  idStr v18; // [sp+60h] [-E0h] BYREF
  idStr v19; // [sp+80h] [-C0h] BYREF
  idStr v20; // [sp+A0h] [-A0h] BYREF
  idStr v21[4]; // [sp+C0h] [-80h] BYREF

  FileExtension = idStr::GetFileExtension(this: v21, result: in_foldername);
  v5 = (-FileExtension->len & (unsigned int)~FileExtension->len) >> 31;
  idStr::FreeData(this: v21);
  if ( v5 != 0 )
  {
    v6 = idStr::idStr(this: &v18, text: in_foldername);
    idPlaytestStorage::CreatePlaytestPlayerPathComboModel_ProcessFile(filename: v6, staticModels);
  }
  else
  {
    idLib::Printf(fmt: "PlaytestPlayerPathComboModel model file creation: Processing %s\n", in_foldername->data);
    v7 = fileSystem->ListFiles(this: fileSystem, a2: in_foldername->data, a3: "/", a4: 1, a5: 1);
    v8 = 0;
    if ( v7->list.num > 0 )
    {
      v9 = 0;
      do
      {
        idStr::idStr(this: &v20, text: v7->list.list[v9].data);
        v10 = idStr::idStr(this: &v18, text: &v20);
        idPlaytestStorage::CreatePlaytestPlayerPathComboModel_ProcessFolder(in_foldername: v10, staticModels);
        idStr::FreeData(this: &v20);
        ++v8;
        ++v9;
      }
      while ( v8 < v7->list.num );
    }
    v11 = fileSystem->ListFiles(this: fileSystem, a2: in_foldername->data, a3: ".ptb", a4: 1, a5: 1);
    v12 = 0;
    if ( v11->list.num > 0 )
    {
      v13 = 0;
      do
      {
        idStr::idStr(this: &v19, text: v11->list.list[v13].data);
        len = v19.len;
        v18.data = v18.baseBuffer;
        v18.len = 0;
        v18.baseBuffer[0] = 0;
        v18.allocedAndFlag = 20;
        if ( v19.len + 1 > 20 )
          idStr::ReAllocate(this: &v18, amount: v19.len + 1, keepold: true);
        v15 = v19.data - 1;
        v16 = v18.data - 1;
        do
        {
          v17 = *++v15;
          *++v16 = *v15;
        }
        while ( v17 != 0 );
        v18.len = len;
        idPlaytestStorage::CreatePlaytestPlayerPathComboModel_ProcessFolder(in_foldername: &v18, staticModels);
        idStr::FreeData(this: &v19);
        ++v12;
        ++v13;
      }
      while ( v12 < v11->list.num );
    }
  }
  idStr::FreeData(this: in_foldername);
}


// ========================================================================
// __unwind$258581
// EA  : 0x8268BB80
// RVA : 0x0068BB80
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258581()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 320 + 340));
}


// ========================================================================
// __unwind$258584
// EA  : 0x8268BBA8
// RVA : 0x0068BBA8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258584()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 160));
}


// ========================================================================
// __unwind$258586
// EA  : 0x8268BBD0
// RVA : 0x0068BBD0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258586()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// ?CreatePlaytestComboModel_ProcessFile@idPlaytestStorage@@CAXVidStr@@ABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x8268BC00
// RVA : 0x0068BC00
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::CreatePlaytestComboModel_ProcessFile(
        idStr *filename,
        const idList<idStaticModel *,5> *staticModels)
{
  bool v4; // r3
  char *data; // r4
  idPlaytestStorage v6; // [sp+50h] [-1B0h] BYREF

  idPlaytestStorage::idPlaytestStorage(this: &v6);
  v4 = idPlaytestStorage::ReadBinaryFile(this: &v6, fileName: filename);
  data = filename->data;
  if ( v4 )
  {
    idLib::Printf(fmt: "creating ComboModel for %s\n", data);
    idPlaytestStorage::GeneratePlayerPathNormalModels(this: &v6, staticModels);
    idPlaytestStorage::GeneratePlayerViewNormalModels(this: &v6, staticModels);
    idPlaytestStorage::GeneratePlayerPathMiscModels(this: &v6, staticModels);
    idPlaytestStorage::GeneratePlayerViewMiscModels(this: &v6, staticModels);
    idPlaytestStorage::GeneratePlayerPathVehicleModels(this: &v6, staticModels);
    idPlaytestStorage::GeneratePlayerViewVehicleModels(this: &v6, staticModels);
    idPlaytestStorage::GenerateAI2BreadCrumbModels(this: &v6, staticModels);
    idPlaytestStorage::GenerateAIVehicleBreadCrumbModels(this: &v6, staticModels);
    idPlaytestStorage::GeneratePlayerItemModels(this: &v6, staticModels);
    idPlaytestStorage::GeneratePlayerUseFocusModels(this: &v6, staticModels);
    idPlaytestStorage::GeneratePlayerUseQuickItemModels(this: &v6, staticModels);
    idPlaytestStorage::GeneratePlayerDeathModels(this: &v6, staticModels);
    idPlaytestStorage::GenerateAIDeathModels(this: &v6, staticModels);
    idPlaytestStorage::GeneratePlayerWeaponFireModels(this: &v6, staticModels);
    idPlaytestStorage::GenerateAIWeaponFireModels(this: &v6, staticModels);
    idPlaytestStorage::GenerateRadiusDamageModels(this: &v6, staticModels);
  }
  else
  {
    idLib::Warning(fmt: "couldn't load file %s", data);
  }
  idPlaytestStorage::~idPlaytestStorage(this: &v6);
  idStr::FreeData(this: filename);
}


// ========================================================================
// __unwind$258782
// EA  : 0x8268BD34
// RVA : 0x0068BD34
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258782()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 512 + 532));
}


// ========================================================================
// __unwind$258783
// EA  : 0x8268BD5C
// RVA : 0x0068BD5C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258783()
{
  int v0; // r12

  idPlaytestStorage::~idPlaytestStorage(this: (idPlaytestStorage *)(v0 - 512 + 80));
}


// ========================================================================
// ?CreatePlaytestComboModel_ProcessFolder@idPlaytestStorage@@CAXVidStr@@ABV?$idList@PAVidStaticModel@@$04@@@Z
// EA  : 0x8268BD90
// RVA : 0x0068BD90
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::CreatePlaytestComboModel_ProcessFolder(
        idStr *in_foldername,
        const idList<idStaticModel *,5> *staticModels)
{
  idStr *FileExtension; // r3
  unsigned int v5; // r30
  idStr *v6; // r3
  idFileList *v7; // r28
  int v8; // r30
  int v9; // r29
  idStr *v10; // r3
  idFileList *v11; // r29
  int v12; // r25
  int v13; // r30
  int len; // r28
  char *v15; // r10
  char *v16; // r9
  char v17; // r11
  idStr v18; // [sp+60h] [-E0h] BYREF
  idStr v19; // [sp+80h] [-C0h] BYREF
  idStr v20; // [sp+A0h] [-A0h] BYREF
  idStr v21[4]; // [sp+C0h] [-80h] BYREF

  FileExtension = idStr::GetFileExtension(this: v21, result: in_foldername);
  v5 = (-FileExtension->len & (unsigned int)~FileExtension->len) >> 31;
  idStr::FreeData(this: v21);
  if ( v5 != 0 )
  {
    v6 = idStr::idStr(this: &v18, text: in_foldername);
    idPlaytestStorage::CreatePlaytestComboModel_ProcessFile(filename: v6, staticModels);
  }
  else
  {
    idLib::Printf(
      fmt: "CreatePlaytestComboModel_ProcessFolder model file creation: Processing %s\n",
      in_foldername->data);
    v7 = fileSystem->ListFiles(this: fileSystem, a2: in_foldername->data, a3: "/", a4: 1, a5: 1);
    v8 = 0;
    if ( v7->list.num > 0 )
    {
      v9 = 0;
      do
      {
        idStr::idStr(this: &v20, text: v7->list.list[v9].data);
        v10 = idStr::idStr(this: &v18, text: &v20);
        idPlaytestStorage::CreatePlaytestComboModel_ProcessFolder(in_foldername: v10, staticModels);
        idStr::FreeData(this: &v20);
        ++v8;
        ++v9;
      }
      while ( v8 < v7->list.num );
    }
    v11 = fileSystem->ListFiles(this: fileSystem, a2: in_foldername->data, a3: ".ptb", a4: 1, a5: 1);
    v12 = 0;
    if ( v11->list.num > 0 )
    {
      v13 = 0;
      do
      {
        idStr::idStr(this: &v19, text: v11->list.list[v13].data);
        len = v19.len;
        v18.data = v18.baseBuffer;
        v18.len = 0;
        v18.baseBuffer[0] = 0;
        v18.allocedAndFlag = 20;
        if ( v19.len + 1 > 20 )
          idStr::ReAllocate(this: &v18, amount: v19.len + 1, keepold: true);
        v15 = v19.data - 1;
        v16 = v18.data - 1;
        do
        {
          v17 = *++v15;
          *++v16 = *v15;
        }
        while ( v17 != 0 );
        v18.len = len;
        idPlaytestStorage::CreatePlaytestComboModel_ProcessFolder(in_foldername: &v18, staticModels);
        idStr::FreeData(this: &v19);
        ++v12;
        ++v13;
      }
      while ( v12 < v11->list.num );
    }
  }
  idStr::FreeData(this: in_foldername);
}


// ========================================================================
// __unwind$258828
// EA  : 0x8268BFE0
// RVA : 0x0068BFE0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258828()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 320 + 340));
}


// ========================================================================
// __unwind$258831
// EA  : 0x8268C008
// RVA : 0x0068C008
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258831()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 160));
}


// ========================================================================
// __unwind$258833
// EA  : 0x8268C030
// RVA : 0x0068C030
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_258833()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// ?Cmd_CreatePlayerPathComboModel_f@idPlaytestStorage@@SAXABVidCmdArgs@@@Z
// EA  : 0x8268C060
// RVA : 0x0068C060
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::Cmd_CreatePlayerPathComboModel_f(const idCmdArgs *args)
{
  int argc; // r11
  bool v2; // cr56
  const char *v3; // r4
  const idStr *v4; // r3
  idStr *v5; // r28
  size_t len; // r29
  idStr *v7; // r3
  idStaticModel *v8; // [sp+50h] [-2A0h] BYREF
  idList<enum encounterGroupRole_t,5> v9; // [sp+60h] [-290h] BYREF
  idStr v10; // [sp+70h] [-280h] BYREF
  idStr v11; // [sp+90h] [-260h] BYREF
  idStr v12; // [sp+B0h] [-240h] BYREF
  idStr v13; // [sp+D0h] [-220h] BYREF
  idStr v14; // [sp+F0h] [-200h] BYREF
  idStr v15; // [sp+110h] [-1E0h] BYREF
  idStaticModel v16; // [sp+130h] [-1C0h] BYREF

  argc = args->argc;
  v2 = args->argc < 2;
  v8 = (idStaticModel *)args->argc;
  if ( v2 )
  {
    idLib::Printf(fmt: "must give a playtest folder name\n");
  }
  else
  {
    if ( argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    idStr::idStr(this: &v12, text: v3);
    v11.len = 0;
    v11.allocedAndFlag = 20;
    v11.data = v11.baseBuffer;
    v11.baseBuffer[0] = 0;
    idStr::ExtractFileName(this: &v12, dest: &v11);
    idStr::ReplaceChar(this: &v11, oldChar: 47, newChar: 95);
    idStr::ReplaceChar(this: &v11, oldChar: 92, newChar: 95);
    v10.allocedAndFlag = 20;
    v10.data = v10.baseBuffer;
    v10.len = 0;
    v10.baseBuffer[0] = 0;
    v4 = operator+(result: &v13, a: &v12, b: &v11);
    v5 = operator+(result: &v14, a: v4, b: "PlayerPath");
    len = v5->len;
    idStr::EnsureAlloced(this: &v10, amount: v5->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v10.data, Src: v5->data, Size: len);
    v10.data[len] = 0;
    v10.len = len;
    idStr::FreeData(this: &v14);
    idStr::FreeData(this: &v13);
    idStaticModel::idStaticModel(this: &v16);
    idResource::SetName(this: &v16, _name: v10.data);
    common->SetRefreshOnPrint(this: common, a2: true);
    memset(&v9, 0, 14);
    *(_WORD *)&v9.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v9);
    v8 = &v16;
    idList<idAnimWebBlendTree *,5>::Append(this: &v9, obj: (const encounterGroupRole_t *)&v8);
    v7 = idStr::idStr(this: &v15, text: &v12);
    idPlaytestStorage::CreatePlaytestPlayerPathComboModel_ProcessFolder(
      in_foldername: v7,
      staticModels: (const idList<idStaticModel *,5> *)&v9);
    if ( v16.surfaces.num <= 0 )
    {
      idLib::Warning(fmt: "Did not find static model to write for player path");
    }
    else
    {
      idLib::Printf(fmt: "writing file %s\n", v10.data);
      idStaticModel::WriteStaticModel(this: &v16);
    }
    common->SetRefreshOnPrint(this: common, a2: false);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v9);
    idStaticModel::~idStaticModel(this: &v16);
    idStr::FreeData(this: &v10);
    idStr::FreeData(this: &v11);
    idStr::FreeData(this: &v12);
  }
}


// ========================================================================
// __unwind$259034
// EA  : 0x8268C270
// RVA : 0x0068C270
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259034()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 752 + 176));
}


// ========================================================================
// __unwind$259035
// EA  : 0x8268C298
// RVA : 0x0068C298
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259035()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 752 + 144));
}


// ========================================================================
// __unwind$259036
// EA  : 0x8268C2C0
// RVA : 0x0068C2C0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259036()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 752 + 112));
}


// ========================================================================
// __unwind$259037
// EA  : 0x8268C2E8
// RVA : 0x0068C2E8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259037()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 752 + 208));
}


// ========================================================================
// __unwind$259038
// EA  : 0x8268C310
// RVA : 0x0068C310
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259038()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 752 + 240));
}


// ========================================================================
// __unwind$259039
// EA  : 0x8268C338
// RVA : 0x0068C338
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259039()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 752 + 304));
}


// ========================================================================
// __unwind$259040
// EA  : 0x8268C360
// RVA : 0x0068C360
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259040()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 752 + 96));
}


// ========================================================================
// ?Cmd_CreateComboModel_f@idPlaytestStorage@@SAXABVidCmdArgs@@@Z
// EA  : 0x8268C390
// RVA : 0x0068C390
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::Cmd_CreateComboModel_f(const idCmdArgs *args)
{
  int argc; // r11
  bool v2; // cr56
  const char *v3; // r4
  const idStr *v4; // r3
  idStr *v5; // r28
  size_t len; // r29
  idStr *v7; // r3
  idStaticModel *v8; // [sp+50h] [-2A0h] BYREF
  idList<enum encounterGroupRole_t,5> v9; // [sp+60h] [-290h] BYREF
  idStr v10; // [sp+70h] [-280h] BYREF
  idStr v11; // [sp+90h] [-260h] BYREF
  idStr v12; // [sp+B0h] [-240h] BYREF
  idStr v13; // [sp+D0h] [-220h] BYREF
  idStr v14; // [sp+F0h] [-200h] BYREF
  idStr v15; // [sp+110h] [-1E0h] BYREF
  idStaticModel v16; // [sp+130h] [-1C0h] BYREF

  argc = args->argc;
  v2 = args->argc < 2;
  v8 = (idStaticModel *)args->argc;
  if ( v2 )
  {
    idLib::Printf(fmt: "must give a playtest folder name\n");
  }
  else
  {
    if ( argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    idStr::idStr(this: &v12, text: v3);
    v11.len = 0;
    v11.allocedAndFlag = 20;
    v11.data = v11.baseBuffer;
    v11.baseBuffer[0] = 0;
    idStr::ExtractFileName(this: &v12, dest: &v11);
    idStr::ReplaceChar(this: &v11, oldChar: 47, newChar: 95);
    idStr::ReplaceChar(this: &v11, oldChar: 92, newChar: 95);
    v10.allocedAndFlag = 20;
    v10.data = v10.baseBuffer;
    v10.len = 0;
    v10.baseBuffer[0] = 0;
    v4 = operator+(result: &v13, a: &v12, b: &v11);
    v5 = operator+(result: &v14, a: v4, b: "Combo");
    len = v5->len;
    idStr::EnsureAlloced(this: &v10, amount: v5->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v10.data, Src: v5->data, Size: len);
    v10.data[len] = 0;
    v10.len = len;
    idStr::FreeData(this: &v14);
    idStr::FreeData(this: &v13);
    idStaticModel::idStaticModel(this: &v16);
    idResource::SetName(this: &v16, _name: v10.data);
    common->SetRefreshOnPrint(this: common, a2: true);
    memset(&v9, 0, 14);
    *(_WORD *)&v9.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v9);
    v8 = &v16;
    idList<idAnimWebBlendTree *,5>::Append(this: &v9, obj: (const encounterGroupRole_t *)&v8);
    v7 = idStr::idStr(this: &v15, text: &v12);
    idPlaytestStorage::CreatePlaytestComboModel_ProcessFolder(
      in_foldername: v7,
      staticModels: (const idList<idStaticModel *,5> *)&v9);
    if ( v16.surfaces.num <= 0 )
    {
      idLib::Warning(fmt: "Did not find static model to write for combo model");
    }
    else
    {
      idLib::Printf(fmt: "writing file %s\n", v10.data);
      idStaticModel::WriteStaticModel(this: &v16);
    }
    common->SetRefreshOnPrint(this: common, a2: false);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v9);
    idStaticModel::~idStaticModel(this: &v16);
    idStr::FreeData(this: &v10);
    idStr::FreeData(this: &v11);
    idStr::FreeData(this: &v12);
  }
}


// ========================================================================
// __unwind$259202
// EA  : 0x8268C5A0
// RVA : 0x0068C5A0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259202()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 752 + 176));
}


// ========================================================================
// __unwind$259203
// EA  : 0x8268C5C8
// RVA : 0x0068C5C8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259203()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 752 + 144));
}


// ========================================================================
// __unwind$259204
// EA  : 0x8268C5F0
// RVA : 0x0068C5F0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259204()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 752 + 112));
}


// ========================================================================
// __unwind$259205
// EA  : 0x8268C618
// RVA : 0x0068C618
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259205()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 752 + 208));
}


// ========================================================================
// __unwind$259206
// EA  : 0x8268C640
// RVA : 0x0068C640
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259206()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 752 + 240));
}


// ========================================================================
// __unwind$259207
// EA  : 0x8268C668
// RVA : 0x0068C668
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259207()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 752 + 304));
}


// ========================================================================
// __unwind$259208
// EA  : 0x8268C690
// RVA : 0x0068C690
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259208()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 752 + 96));
}


// ========================================================================
// ?ReadStorageFilesToList_ProcessFile@idPlaytestStorage@@CAXVidStr@@PAV?$idList@VidPlaytestStorage@@$04@@@Z
// EA  : 0x8268C960
// RVA : 0x0068C960
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::ReadStorageFilesToList_ProcessFile(
        idStr *filename,
        idList<idPlaytestStorage,5> *storageList)
{
  idPlaytestStorage v4; // [sp+50h] [-1B0h] BYREF

  idPlaytestStorage::idPlaytestStorage(this: &v4);
  if ( idPlaytestStorage::ReadBinaryFile(this: &v4, fileName: filename) )
    idList<idPlaytestStorage,5>::Append(this: storageList, obj: &v4);
  else
    idLib::Warning(fmt: "couldn't load file %s", filename->data);
  idPlaytestStorage::~idPlaytestStorage(this: &v4);
  idStr::FreeData(this: filename);
}


// ========================================================================
// __unwind$259563
// EA  : 0x8268C9D4
// RVA : 0x0068C9D4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259563()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 512 + 532));
}


// ========================================================================
// __unwind$259564
// EA  : 0x8268C9FC
// RVA : 0x0068C9FC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259564()
{
  int v0; // r12

  idPlaytestStorage::~idPlaytestStorage(this: (idPlaytestStorage *)(v0 - 512 + 80));
}


// ========================================================================
// ?ReadStorageFilesToList_ProcessFolder@idPlaytestStorage@@CAXVidStr@@PAV?$idList@VidPlaytestStorage@@$04@@@Z
// EA  : 0x8268CA30
// RVA : 0x0068CA30
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::ReadStorageFilesToList_ProcessFolder(
        idStr *in_foldername,
        idList<idPlaytestStorage,5> *storageList)
{
  idStr *FileExtension; // r3
  unsigned int v5; // r30
  idStr *v6; // r3
  idFileList *v7; // r28
  int v8; // r30
  int v9; // r29
  idStr *v10; // r3
  idFileList *v11; // r29
  int v12; // r25
  int v13; // r30
  int len; // r28
  char *v15; // r10
  char *v16; // r9
  char v17; // r11
  idStr v18; // [sp+60h] [-E0h] BYREF
  idStr v19; // [sp+80h] [-C0h] BYREF
  idStr v20; // [sp+A0h] [-A0h] BYREF
  idStr v21[4]; // [sp+C0h] [-80h] BYREF

  FileExtension = idStr::GetFileExtension(this: v21, result: in_foldername);
  v5 = (-FileExtension->len & (unsigned int)~FileExtension->len) >> 31;
  idStr::FreeData(this: v21);
  if ( v5 != 0 )
  {
    v6 = idStr::idStr(this: &v18, text: in_foldername);
    idPlaytestStorage::ReadStorageFilesToList_ProcessFile(filename: v6, storageList);
  }
  else
  {
    idLib::Printf(fmt: "ReadStorageFilesToList_ProcessFolder: Processing %s\n", in_foldername->data);
    v7 = fileSystem->ListFiles(this: fileSystem, a2: in_foldername->data, a3: "/", a4: 1, a5: 1);
    v8 = 0;
    if ( v7->list.num > 0 )
    {
      v9 = 0;
      do
      {
        idStr::idStr(this: &v20, text: v7->list.list[v9].data);
        v10 = idStr::idStr(this: &v18, text: &v20);
        idPlaytestStorage::ReadStorageFilesToList_ProcessFolder(in_foldername: v10, storageList);
        idStr::FreeData(this: &v20);
        ++v8;
        ++v9;
      }
      while ( v8 < v7->list.num );
    }
    v11 = fileSystem->ListFiles(this: fileSystem, a2: in_foldername->data, a3: ".ptb", a4: 1, a5: 1);
    v12 = 0;
    if ( v11->list.num > 0 )
    {
      v13 = 0;
      do
      {
        idStr::idStr(this: &v19, text: v11->list.list[v13].data);
        len = v19.len;
        v18.data = v18.baseBuffer;
        v18.len = 0;
        v18.baseBuffer[0] = 0;
        v18.allocedAndFlag = 20;
        if ( v19.len + 1 > 20 )
          idStr::ReAllocate(this: &v18, amount: v19.len + 1, keepold: true);
        v15 = v19.data - 1;
        v16 = v18.data - 1;
        do
        {
          v17 = *++v15;
          *++v16 = *v15;
        }
        while ( v17 != 0 );
        v18.len = len;
        idPlaytestStorage::ReadStorageFilesToList_ProcessFolder(in_foldername: &v18, storageList);
        idStr::FreeData(this: &v19);
        ++v12;
        ++v13;
      }
      while ( v12 < v11->list.num );
    }
  }
  idStr::FreeData(this: in_foldername);
}


// ========================================================================
// __unwind$259605
// EA  : 0x8268CC80
// RVA : 0x0068CC80
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259605()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 320 + 340));
}


// ========================================================================
// __unwind$259608
// EA  : 0x8268CCA8
// RVA : 0x0068CCA8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259608()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 160));
}


// ========================================================================
// __unwind$259610
// EA  : 0x8268CCD0
// RVA : 0x0068CCD0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259610()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// ?Cmd_CreateBombBaseData_f@idPlaytestStorage@@SAXABVidCmdArgs@@@Z
// EA  : 0x8268CD00
// RVA : 0x0068CD00
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::Cmd_CreateBombBaseData_f(const idCmdArgs *args)
{
  int argc; // r11
  bool v2; // cr56
  const char *v3; // r4
  const idStr *v4; // r3
  idStr *v5; // r28
  size_t len; // r30
  fsPath_t v7; // r5
  idFile *v8; // r26
  idStr *v9; // r3
  int v10; // r30
  int v11; // r28
  idFile_vtbl *v12; // r30
  char *filePtr; // r28
  unsigned int v14; // r3
  idList<idPlaytestStorage,5> v15; // [sp+50h] [-270h] BYREF
  idStr v16; // [sp+60h] [-260h] BYREF
  idStr v17; // [sp+80h] [-240h] BYREF
  int v18; // [sp+A0h] [-220h]
  idStr v19; // [sp+B0h] [-210h] BYREF
  idStr v20; // [sp+D0h] [-1F0h] BYREF
  idStr v21; // [sp+F0h] [-1D0h] BYREF
  idStr v22; // [sp+110h] [-1B0h] BYREF
  idFile_Memory v23; // [sp+130h] [-190h] BYREF

  argc = args->argc;
  v2 = args->argc < 2;
  v18 = args->argc;
  if ( v2 )
  {
    idLib::Printf(fmt: "must give a playtest folder name\n");
  }
  else
  {
    if ( argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    idStr::idStr(this: &v19, text: v3);
    v17.len = 0;
    v17.allocedAndFlag = 20;
    v17.data = v17.baseBuffer;
    v17.baseBuffer[0] = 0;
    idStr::ExtractFileName(this: &v19, dest: &v17);
    idStr::ReplaceChar(this: &v17, oldChar: 47, newChar: 95);
    idStr::ReplaceChar(this: &v17, oldChar: 92, newChar: 95);
    v16.allocedAndFlag = 20;
    v16.data = v16.baseBuffer;
    v16.len = 0;
    v16.baseBuffer[0] = 0;
    v4 = operator+(result: &v20, a: &v19, b: &v17);
    v5 = operator+(result: &v21, a: v4, b: "RCBombBaseEventData.txt");
    len = v5->len;
    idStr::EnsureAlloced(this: &v16, amount: v5->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v16.data, Src: v5->data, Size: len);
    v16.data[len] = 0;
    v16.len = len;
    idStr::FreeData(this: &v21);
    idStr::FreeData(this: &v20);
    common->SetRefreshOnPrint(this: common, a2: true);
    idFile_Memory::idFile_Memory(this: &v23);
    if ( playtest_save_useSavePath.valueInteger != 0 )
      v7 = FSPATH_SAVE;
    else
      v7 = FSPATH_BASE;
    v8 = fileSystem->OpenFileWrite(this: fileSystem, a2: v16.data, a3: v7);
    if ( v8 != nullptr )
    {
      *(_WORD *)&v15.memTag = 1280;
      memset(&v15, 0, 14);
      v9 = idStr::idStr(this: &v22, text: &v19);
      idPlaytestStorage::ReadStorageFilesToList_ProcessFolder(in_foldername: v9, storageList: &v15);
      idFile::Printf(this: &v23, fmt: "RCBombBase INFORMATION:\n");
      idFile::Printf(this: &v23, fmt: "\nPLAYER DATA\n");
      v10 = 0;
      if ( v15.num > 0 )
      {
        v11 = 0;
        do
        {
          idFile::Printf(this: &v23, fmt: "---\nPLAYER %d\n", v10);
          idPlaytestStorage::WritePlayerSummary(this: &v15.list[v11], memoryFile: &v23);
          ++v10;
          ++v11;
        }
        while ( v10 < v15.num );
      }
      v12 = v8->__vftable;
      filePtr = v23.filePtr;
      v14 = (unsigned __int64)idFile_Memory::Length(this: &v23) >> 32;
      v12->Write(this: v8, a2: filePtr, a3: v14);
      ((void (__fastcall *)(idFile *, int))v8->dtr_idFile)(a1: v8, a2: 1);
      if ( v15.listStatic == 0 || v15.listStatic == 2 )
      {
        if ( v15.list != nullptr )
          idListArrayDelete<idPlaytestStorage>(ptr: v15.list, num: v15.size);
        v15.list = nullptr;
        v15.size = 0;
      }
      v15.num = 0;
    }
    else
    {
      idLib::Warning(fmt: "could not create file %s for writing", v16.data);
    }
    common->SetRefreshOnPrint(this: common, a2: false);
    idFile_Memory::~idFile_Memory(this: &v23);
    idStr::FreeData(this: &v16);
    idStr::FreeData(this: &v17);
    idStr::FreeData(this: &v19);
  }
}


// ========================================================================
// __unwind$259814
// EA  : 0x8268D004
// RVA : 0x0068D004
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259814()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 176));
}


// ========================================================================
// __unwind$259815
// EA  : 0x8268D02C
// RVA : 0x0068D02C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259815()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 128));
}


// ========================================================================
// __unwind$259816
// EA  : 0x8268D054
// RVA : 0x0068D054
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259816()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 96));
}


// ========================================================================
// __unwind$259817
// EA  : 0x8268D07C
// RVA : 0x0068D07C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259817()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 208));
}


// ========================================================================
// __unwind$259818
// EA  : 0x8268D0A4
// RVA : 0x0068D0A4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259818()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 240));
}


// ========================================================================
// __unwind$259819
// EA  : 0x8268D0CC
// RVA : 0x0068D0CC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259819()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 704 + 304));
}


// ========================================================================
// __unwind$259820
// EA  : 0x8268D0F4
// RVA : 0x0068D0F4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_259820()
{
  int v0; // r12

  idList<idPlaytestStorage,5>::~idList<idPlaytestStorage,5>(this: (idList<idPlaytestStorage,5> *)(v0 - 704 + 80));
}


// ========================================================================
// ?Cmd_CreateFindWellspringData_f@idPlaytestStorage@@SAXABVidCmdArgs@@@Z
// EA  : 0x8268D128
// RVA : 0x0068D128
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::Cmd_CreateFindWellspringData_f(const idCmdArgs *args)
{
  int argc; // r11
  bool v2; // cr56
  const char *v3; // r4
  const idStr *v4; // r3
  idStr *v5; // r28
  size_t len; // r30
  fsPath_t v7; // r5
  idFile *v8; // r26
  idStr *v9; // r3
  int v10; // r30
  int v11; // r28
  idFile_vtbl *v12; // r30
  char *filePtr; // r28
  unsigned int v14; // r3
  idList<idPlaytestStorage,5> v15; // [sp+50h] [-270h] BYREF
  idStr v16; // [sp+60h] [-260h] BYREF
  idStr v17; // [sp+80h] [-240h] BYREF
  int v18; // [sp+A0h] [-220h]
  idStr v19; // [sp+B0h] [-210h] BYREF
  idStr v20; // [sp+D0h] [-1F0h] BYREF
  idStr v21; // [sp+F0h] [-1D0h] BYREF
  idStr v22; // [sp+110h] [-1B0h] BYREF
  idFile_Memory v23; // [sp+130h] [-190h] BYREF

  argc = args->argc;
  v2 = args->argc < 2;
  v18 = args->argc;
  if ( v2 )
  {
    idLib::Printf(fmt: "must give a playtest folder name\n");
  }
  else
  {
    if ( argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    idStr::idStr(this: &v19, text: v3);
    v17.len = 0;
    v17.allocedAndFlag = 20;
    v17.data = v17.baseBuffer;
    v17.baseBuffer[0] = 0;
    idStr::ExtractFileName(this: &v19, dest: &v17);
    idStr::ReplaceChar(this: &v17, oldChar: 47, newChar: 95);
    idStr::ReplaceChar(this: &v17, oldChar: 92, newChar: 95);
    v16.allocedAndFlag = 20;
    v16.data = v16.baseBuffer;
    v16.len = 0;
    v16.baseBuffer[0] = 0;
    v4 = operator+(result: &v20, a: &v19, b: &v17);
    v5 = operator+(result: &v21, a: v4, b: "FindWastelandEventData.txt");
    len = v5->len;
    idStr::EnsureAlloced(this: &v16, amount: v5->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v16.data, Src: v5->data, Size: len);
    v16.data[len] = 0;
    v16.len = len;
    idStr::FreeData(this: &v21);
    idStr::FreeData(this: &v20);
    common->SetRefreshOnPrint(this: common, a2: true);
    idFile_Memory::idFile_Memory(this: &v23);
    if ( playtest_save_useSavePath.valueInteger != 0 )
      v7 = FSPATH_SAVE;
    else
      v7 = FSPATH_BASE;
    v8 = fileSystem->OpenFileWrite(this: fileSystem, a2: v16.data, a3: v7);
    if ( v8 != nullptr )
    {
      *(_WORD *)&v15.memTag = 1280;
      memset(&v15, 0, 14);
      v9 = idStr::idStr(this: &v22, text: &v19);
      idPlaytestStorage::ReadStorageFilesToList_ProcessFolder(in_foldername: v9, storageList: &v15);
      idFile::Printf(this: &v23, fmt: "Find Wasteland INFORMATION:\n");
      idFile::Printf(this: &v23, fmt: "\nPLAYER DATA\n");
      v10 = 0;
      if ( v15.num > 0 )
      {
        v11 = 0;
        do
        {
          idFile::Printf(this: &v23, fmt: "---\nPLAYER %d\n", v10);
          idPlaytestStorage::WritePlayerSummary(this: &v15.list[v11], memoryFile: &v23);
          ++v10;
          ++v11;
        }
        while ( v10 < v15.num );
      }
      v12 = v8->__vftable;
      filePtr = v23.filePtr;
      v14 = (unsigned __int64)idFile_Memory::Length(this: &v23) >> 32;
      v12->Write(this: v8, a2: filePtr, a3: v14);
      ((void (__fastcall *)(idFile *, int))v8->dtr_idFile)(a1: v8, a2: 1);
      if ( v15.listStatic == 0 || v15.listStatic == 2 )
      {
        if ( v15.list != nullptr )
          idListArrayDelete<idPlaytestStorage>(ptr: v15.list, num: v15.size);
        v15.list = nullptr;
        v15.size = 0;
      }
      v15.num = 0;
    }
    else
    {
      idLib::Warning(fmt: "could not create file %s for writing", v16.data);
    }
    common->SetRefreshOnPrint(this: common, a2: false);
    idFile_Memory::~idFile_Memory(this: &v23);
    idStr::FreeData(this: &v16);
    idStr::FreeData(this: &v17);
    idStr::FreeData(this: &v19);
  }
}


// ========================================================================
// __unwind$260029
// EA  : 0x8268D42C
// RVA : 0x0068D42C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_260029()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 176));
}


// ========================================================================
// __unwind$260030
// EA  : 0x8268D454
// RVA : 0x0068D454
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_260030()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 128));
}


// ========================================================================
// __unwind$260031
// EA  : 0x8268D47C
// RVA : 0x0068D47C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_260031()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 96));
}


// ========================================================================
// __unwind$260032
// EA  : 0x8268D4A4
// RVA : 0x0068D4A4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_260032()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 208));
}


// ========================================================================
// __unwind$260033
// EA  : 0x8268D4CC
// RVA : 0x0068D4CC
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_260033()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 240));
}


// ========================================================================
// __unwind$260034
// EA  : 0x8268D4F4
// RVA : 0x0068D4F4
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_260034()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 704 + 304));
}


// ========================================================================
// __unwind$260035
// EA  : 0x8268D51C
// RVA : 0x0068D51C
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_260035()
{
  int v0; // r12

  idList<idPlaytestStorage,5>::~idList<idPlaytestStorage,5>(this: (idList<idPlaytestStorage,5> *)(v0 - 704 + 80));
}


// ========================================================================
// ?Cmd_CreateWasteLandRallyData_f@idPlaytestStorage@@SAXABVidCmdArgs@@@Z
// EA  : 0x8268D550
// RVA : 0x0068D550
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::Cmd_CreateWasteLandRallyData_f(const idCmdArgs *args)
{
  int argc; // r11
  bool v2; // cr56
  const char *v3; // r4
  const idStr *v4; // r3
  idStr *v5; // r28
  size_t len; // r29
  fsPath_t v7; // r5
  idFile *v8; // r29
  idStr *v9; // r3
  idFile_vtbl *v10; // r30
  char *filePtr; // r27
  unsigned int v12; // r3
  idList<idPlaytestStorage,5> v13; // [sp+50h] [-260h] BYREF
  idStr v14; // [sp+60h] [-250h] BYREF
  idStr v15; // [sp+80h] [-230h] BYREF
  int v16; // [sp+A0h] [-210h]
  idStr v17; // [sp+B0h] [-200h] BYREF
  idStr v18; // [sp+D0h] [-1E0h] BYREF
  idStr v19; // [sp+F0h] [-1C0h] BYREF
  idStr v20; // [sp+110h] [-1A0h] BYREF
  idFile_Memory v21; // [sp+130h] [-180h] BYREF

  argc = args->argc;
  v2 = args->argc < 2;
  v16 = args->argc;
  if ( v2 )
  {
    idLib::Printf(fmt: "must give a playtest folder name\n");
  }
  else
  {
    if ( argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    idStr::idStr(this: &v17, text: v3);
    v15.len = 0;
    v15.allocedAndFlag = 20;
    v15.data = v15.baseBuffer;
    v15.baseBuffer[0] = 0;
    idStr::ExtractFileName(this: &v17, dest: &v15);
    idStr::ReplaceChar(this: &v15, oldChar: 47, newChar: 95);
    idStr::ReplaceChar(this: &v15, oldChar: 92, newChar: 95);
    v14.allocedAndFlag = 20;
    v14.data = v14.baseBuffer;
    v14.len = 0;
    v14.baseBuffer[0] = 0;
    v4 = operator+(result: &v18, a: &v17, b: &v15);
    v5 = operator+(result: &v19, a: v4, b: "WasteLandRallyEventData.txt");
    len = v5->len;
    idStr::EnsureAlloced(this: &v14, amount: v5->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v14.data, Src: v5->data, Size: len);
    v14.data[len] = 0;
    v14.len = len;
    idStr::FreeData(this: &v19);
    idStr::FreeData(this: &v18);
    common->SetRefreshOnPrint(this: common, a2: true);
    idFile_Memory::idFile_Memory(this: &v21);
    if ( playtest_save_useSavePath.valueInteger != 0 )
      v7 = FSPATH_SAVE;
    else
      v7 = FSPATH_BASE;
    v8 = fileSystem->OpenFileWrite(this: fileSystem, a2: v14.data, a3: v7);
    if ( v8 != nullptr )
    {
      *(_WORD *)&v13.memTag = 1280;
      memset(&v13, 0, 14);
      v9 = idStr::idStr(this: &v20, text: &v17);
      idPlaytestStorage::ReadStorageFilesToList_ProcessFolder(in_foldername: v9, storageList: &v13);
      idFile::Printf(this: &v21, fmt: "Wasteland Rally INFORMATION:\n");
      v10 = v8->__vftable;
      filePtr = v21.filePtr;
      v12 = (unsigned __int64)idFile_Memory::Length(this: &v21) >> 32;
      v10->Write(this: v8, a2: filePtr, a3: v12);
      ((void (__fastcall *)(idFile *, int))v8->dtr_idFile)(a1: v8, a2: 1);
      idList<idPlaytestStorage,5>::~idList<idPlaytestStorage,5>(this: &v13);
    }
    else
    {
      idLib::Warning(fmt: "could not create file %s for writing", v14.data);
    }
    common->SetRefreshOnPrint(this: common, a2: false);
    idFile_Memory::~idFile_Memory(this: &v21);
    idStr::FreeData(this: &v14);
    idStr::FreeData(this: &v15);
    idStr::FreeData(this: &v17);
  }
}


// ========================================================================
// __unwind$260244
// EA  : 0x8268D7C8
// RVA : 0x0068D7C8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_260244()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 688 + 176));
}


// ========================================================================
// __unwind$260245
// EA  : 0x8268D7F0
// RVA : 0x0068D7F0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_260245()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 688 + 128));
}


// ========================================================================
// __unwind$260246
// EA  : 0x8268D818
// RVA : 0x0068D818
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_260246()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 688 + 96));
}


// ========================================================================
// __unwind$260247
// EA  : 0x8268D840
// RVA : 0x0068D840
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_260247()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 688 + 208));
}


// ========================================================================
// __unwind$260248
// EA  : 0x8268D868
// RVA : 0x0068D868
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_260248()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 688 + 240));
}


// ========================================================================
// __unwind$260249
// EA  : 0x8268D890
// RVA : 0x0068D890
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_260249()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 688 + 304));
}


// ========================================================================
// __unwind$260250
// EA  : 0x8268D8B8
// RVA : 0x0068D8B8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void _unwind_260250()
{
  int v0; // r12

  idList<idPlaytestStorage,5>::~idList<idPlaytestStorage,5>(this: (idList<idPlaytestStorage,5> *)(v0 - 688 + 80));
}


// ========================================================================
// ?Cmd_CreateAllProcessedData_f@idPlaytestStorage@@SAXABVidCmdArgs@@@Z
// EA  : 0x8268D8E0
// RVA : 0x0068D8E0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __fastcall idPlaytestStorage::Cmd_CreateAllProcessedData_f(const idCmdArgs *args)
{
  idCmdArgs v1; // [sp+50h] [-930h] BYREF

  common->SetRefreshOnPrint(this: common, a2: true);
  idLib::Warning(fmt: "creating all data from the july 31st playtest, this will take a while...");
  v1.argc = 0;
  idCmdArgs::AppendArg(this: &v1, text: "blah");
  idCmdArgs::AppendArg(this: &v1, text: "*");
  idPlaytestStorage::Cmd_CreatePlaytestTextFile_f(args: &v1);
  idPlaytestStorage::Cmd_CreatePlaytestModel_f(args: &v1);
  v1.argc = 0;
  idCmdArgs::AppendArg(this: &v1, text: "blah");
  idCmdArgs::AppendArg(this: &v1, text: "playtest/FindWellspring/");
  idPlaytestStorage::Cmd_CreateFindWellspringData_f(args: &v1);
  idPlaytestStorage::Cmd_CreatePlayerPathComboModel_f(args: &v1);
  idPlaytestStorage::Cmd_CreateComboModel_f(args: &v1);
  v1.argc = 0;
  idCmdArgs::AppendArg(this: &v1, text: "blah");
  idCmdArgs::AppendArg(this: &v1, text: "playtest/RCBombBase/");
  idPlaytestStorage::Cmd_CreateBombBaseData_f(args: &v1);
  idPlaytestStorage::Cmd_CreatePlayerPathComboModel_f(args: &v1);
  idPlaytestStorage::Cmd_CreateComboModel_f(args: &v1);
  v1.argc = 0;
  idCmdArgs::AppendArg(this: &v1, text: "blah");
  idCmdArgs::AppendArg(this: &v1, text: "playtest/WastelandRally/");
  idPlaytestStorage::Cmd_CreateWasteLandRallyData_f(args: &v1);
  idPlaytestStorage::Cmd_CreatePlayerPathComboModel_f(args: &v1);
  idPlaytestStorage::Cmd_CreateComboModel_f(args: &v1);
  common->SetRefreshOnPrint(this: common, a2: false);
}


// ========================================================================
// `dynamic initializer for 'playtest_save_useSavePath''
// EA  : 0x8333BB80
// RVA : 0x0133BB80
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__playtest_save_useSavePath__()
{
  idCVar::idCVar(
    this: &playtest_save_useSavePath,
    name: "playtest_save_useSavePath",
    value: "1",
    flags: 1,
    description: "if true we save to FSPATH_SAVE else we save to FSPATH_BASE",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__playtest_save_useSavePath__);
}


// ========================================================================
// `dynamic initializer for 'playtest_createModel_f''
// EA  : 0x8333BBD8
// RVA : 0x0133BBD8
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__playtest_createModel_f__()
{
  return idCommandLink::idCommandLink(
           this: &playtest_createModel_f,
           cmdName: "playtest_CreateModel",
           function: idPlaytestStorage::Cmd_CreatePlaytestModel_f,
           description: "loads a playtest binary file and creates the playtest models * does a batch through all",
           argCompletion: idCmdSystem::ArgCompletion_PlayTestFile);
}


// ========================================================================
// `dynamic initializer for 'playtest_createTextFiles_f''
// EA  : 0x8333BC08
// RVA : 0x0133BC08
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__playtest_createTextFiles_f__()
{
  return idCommandLink::idCommandLink(
           this: &playtest_createTextFiles_f,
           cmdName: "playtest_CreateTextFile",
           function: idPlaytestStorage::Cmd_CreatePlaytestTextFile_f,
           description: "loads a playtest binary file and creates the text file * does a batch through all",
           argCompletion: idCmdSystem::ArgCompletion_PlayTestFile);
}


// ========================================================================
// `dynamic initializer for 'playtest_createPlayerPathCombo_f''
// EA  : 0x8333BC38
// RVA : 0x0133BC38
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__playtest_createPlayerPathCombo_f__()
{
  return idCommandLink::idCommandLink(
           this: &playtest_createPlayerPathCombo_f,
           cmdName: "playtest_CreatePlayerPathCombo",
           function: idPlaytestStorage::Cmd_CreatePlayerPathComboModel_f,
           description: "loads a playtest directory and creates the player paths from everything in side that into one model",
           argCompletion: idCmdSystem::ArgCompletion_PlayTestFile);
}


// ========================================================================
// `dynamic initializer for 'playtest_createComboModel_f''
// EA  : 0x8333BC68
// RVA : 0x0133BC68
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__playtest_createComboModel_f__()
{
  return idCommandLink::idCommandLink(
           this: &playtest_createComboModel_f,
           cmdName: "playtest_CreateComboModel",
           function: idPlaytestStorage::Cmd_CreateComboModel_f,
           description: "loads a playtest directory and creates all the models from everything in side that into one model",
           argCompletion: idCmdSystem::ArgCompletion_PlayTestFile);
}


// ========================================================================
// `dynamic initializer for 'playtest_createAllData_f''
// EA  : 0x8333BC98
// RVA : 0x0133BC98
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__playtest_createAllData_f__()
{
  return idCommandLink::idCommandLink(
           this: &playtest_createAllData_f,
           cmdName: "playtest_CreateAllData",
           function: idPlaytestStorage::Cmd_CreateAllProcessedData_f,
           description: "goes through all the playtest data and creates the necessary release data.  helper function for rob",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'playtest_createBombBaseFile_f''
// EA  : 0x8333BCC0
// RVA : 0x0133BCC0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__playtest_createBombBaseFile_f__()
{
  return idCommandLink::idCommandLink(
           this: &playtest_createBombBaseFile_f,
           cmdName: "playtest_CreateBombBaseFile",
           function: idPlaytestStorage::Cmd_CreateBombBaseData_f,
           description: "goes through the passed in directory and creates a text file about the bomb base data",
           argCompletion: idCmdSystem::ArgCompletion_PlayTestFile);
}


// ========================================================================
// `dynamic initializer for 'playtest_createFindWellSpringFile_f''
// EA  : 0x8333BCF0
// RVA : 0x0133BCF0
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__playtest_createFindWellSpringFile_f__()
{
  return idCommandLink::idCommandLink(
           this: &playtest_createFindWellSpringFile_f,
           cmdName: "playtest_CreateFindWellSpringFile",
           function: idPlaytestStorage::Cmd_CreateFindWellspringData_f,
           description: "goes through the passed in directory and creates a text file about the find wellspring data",
           argCompletion: idCmdSystem::ArgCompletion_PlayTestFile);
}


// ========================================================================
// `dynamic initializer for 'playtest_createWasteLandRallyFile_f''
// EA  : 0x8333BD20
// RVA : 0x0133BD20
// PDB : w:\tech5\engine\framework\playteststorage.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__playtest_createWasteLandRallyFile_f__()
{
  return idCommandLink::idCommandLink(
           this: &playtest_createWasteLandRallyFile_f,
           cmdName: "playtest_CreateWasteLandRallyFile",
           function: idPlaytestStorage::Cmd_CreateWasteLandRallyData_f,
           description: "goes through the passed in directory and creates a text file about the wasteland rally data",
           argCompletion: idCmdSystem::ArgCompletion_PlayTestFile);
}

