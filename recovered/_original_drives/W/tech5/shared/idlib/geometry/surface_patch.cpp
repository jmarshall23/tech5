
// ========================================================================
// ?ProjectPointOntoVector@idSurface_Patch@@AAAXABVidVec3@@00AAV2@@Z
// EA  : 0x82F21A08
// RVA : 0x00F21A08
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.cpp
// ========================================================================

void __fastcall idSurface_Patch::ProjectPointOntoVector(
        idSurface_Patch *this,
        const idVec3 *point,
        const idVec3 *vStart,
        const idVec3 *vEnd,
        idVec3 *vProj)
{
  double v5; // fp9
  double v6; // fp6
  double y; // fp4
  double z; // fp11
  double v11; // fp7
  double v12; // fp13
  double v13; // fp8
  double v14; // fp7
  double v15; // fp0
  double v16; // fp13
  double v17; // fp12
  double v18; // fp7

  v5 = (float)(vEnd->y - vStart->y);
  v6 = (float)(vEnd->z - vStart->z);
  y = vStart->y;
  z = vStart->z;
  _FP8 = (float)((float)((float)((float)(vEnd->x - vStart->x) * (float)(vEnd->x - vStart->x))
                       + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f8, f8, f7, f13 }
  v11 = __frsqrte(_FP8);
  v12 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                      * (float)((float)((float)((float)(vEnd->x - vStart->x) * (float)(vEnd->x - vStart->x)) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                              * (float)0.5))
                                                                              * (float)v11)
                                                                      - (float)1.5)
                                                      * (float)v11)
                                              * (float)((float)((float)((float)(vEnd->x - vStart->x)
                                                                      * (float)(vEnd->x - vStart->x))
                                                              + (float)((float)((float)v6 * (float)v6)
                                                                      + (float)((float)v5 * (float)v5)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v11
                                                                              * (float)((float)((float)((float)(vEnd->x - vStart->x) * (float)(vEnd->x - vStart->x))
                                                                                              + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                      * (float)0.5))
                                                                      * (float)v11)
                                                              - (float)1.5)
                                              * (float)v11))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v11
                                                      * (float)((float)((float)((float)(vEnd->x - vStart->x)
                                                                              * (float)(vEnd->x - vStart->x))
                                                                      + (float)((float)((float)v6 * (float)v6)
                                                                              + (float)((float)v5 * (float)v5)))
                                                              * (float)0.5))
                                              * (float)v11)
                                      - (float)1.5)
                      * (float)v11));
  v13 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)((float)(vEnd->x - vStart->x) * (float)(vEnd->x - vStart->x)) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5)) * (float)v11) - (float)1.5)
                                                                                      * (float)v11)
                                                                              * (float)((float)((float)((float)(vEnd->x - vStart->x) * (float)(vEnd->x - vStart->x))
                                                                                              + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)((float)(vEnd->x - vStart->x) * (float)(vEnd->x - vStart->x)) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5)) * (float)v11)
                                                                                              - (float)1.5)
                                                                              * (float)v11))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v11
                                                                                      * (float)((float)((float)((float)(vEnd->x - vStart->x) * (float)(vEnd->x - vStart->x)) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                              * (float)0.5))
                                                                              * (float)v11)
                                                                      - (float)1.5)
                                                      * (float)v11))
                                      * (float)((float)((float)((float)(vEnd->x - vStart->x)
                                                              * (float)(vEnd->x - vStart->x))
                                                      + (float)((float)((float)v6 * (float)v6)
                                                              + (float)((float)v5 * (float)v5)))
                                              * (float)0.5))
                              * (float)v12)
                      - (float)1.5);
  v14 = (float)((float)v13
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                              * (float)((float)((float)((float)(vEnd->x - vStart->x) * (float)(vEnd->x - vStart->x)) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5))
                                                                                      * (float)v11)
                                                                              - (float)1.5)
                                                              * (float)v11)
                                                      * (float)((float)((float)((float)(vEnd->x - vStart->x)
                                                                              * (float)(vEnd->x - vStart->x))
                                                                      + (float)((float)((float)v6 * (float)v6)
                                                                              + (float)((float)v5 * (float)v5)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v11
                                                                                      * (float)((float)((float)((float)(vEnd->x - vStart->x) * (float)(vEnd->x - vStart->x)) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                              * (float)0.5))
                                                                              * (float)v11)
                                                                      - (float)1.5)
                                                      * (float)v11))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v11
                                                              * (float)((float)((float)((float)(vEnd->x - vStart->x)
                                                                                      * (float)(vEnd->x - vStart->x))
                                                                              + (float)((float)((float)v6 * (float)v6)
                                                                                      + (float)((float)v5 * (float)v5)))
                                                                      * (float)0.5))
                                                      * (float)v11)
                                              - (float)1.5)
                              * (float)v11)));
  v15 = (float)((float)(vEnd->y - vStart->y) * (float)v14);
  v16 = (float)((float)(vEnd->z - vStart->z) * (float)v14);
  v17 = (float)((float)(vEnd->x - vStart->x) * (float)v14);
  v18 = (float)((float)((float)(point->x - vStart->x) * (float)((float)(vEnd->x - vStart->x) * (float)v14))
              + (float)((float)((float)((float)(vEnd->z - vStart->z) * (float)v14) * (float)(point->z - vStart->z))
                      + (float)((float)((float)(vEnd->y - vStart->y) * (float)v14) * (float)(point->y - vStart->y))));
  vProj->x = vStart->x + (float)((float)v18 * (float)v17);
  vProj->y = (float)((float)v15 * (float)v18) + (float)y;
  vProj->z = (float)z + (float)((float)v16 * (float)v18);
}


// ========================================================================
// ?RemoveLinearColumnsRows@idSurface_Patch@@AAAXXZ
// EA  : 0x82F21AE8
// RVA : 0x00F21AE8
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.cpp
// ========================================================================

void __fastcall idSurface_Patch::RemoveLinearColumnsRows(idSurface_Patch *this)
{
  int i; // r27
  int height; // r28
  double v3; // fp31
  int v4; // r8
  int maxWidth; // r31
  idDrawVert *list; // r30
  int v7; // r8
  float *v8; // r4
  int v9; // r8
  int j; // r10
  int v11; // r7
  idDrawVert *v12; // r11
  int v13; // r28
  double v14; // fp11
  int width; // r29
  double v16; // fp12
  int v17; // r8
  int v18; // r6
  idDrawVert *v19; // r7
  float *p_x; // r9
  float *v21; // r10
  float *v22; // r11
  double v23; // fp8
  double v24; // fp5
  double v27; // fp31
  double v28; // fp31
  double v29; // fp31
  double v30; // fp31
  double v31; // fp1
  double v32; // fp0
  double v33; // fp9
  double v34; // fp0
  int v35; // r7
  int k; // r8
  int v37; // r6
  idDrawVert *v38; // r11
  idDrawVert *v39; // r10
  idVec3 v40; // [sp+50h] [-80h] BYREF

  for ( i = 1; i < this->width - 1; ++i )
  {
    height = this->height;
    v3 = 0.0;
    v4 = 0;
    if ( height > 0 )
    {
      maxWidth = this->maxWidth;
      list = this->verts.list;
      do
      {
        idSurface_Patch::ProjectPointOntoVector(
          this,
          point: &list[maxWidth * v4 + i].xyz,
          vStart: &list[maxWidth * v4 - 1 + i].xyz,
          vEnd: &list[maxWidth * v4 + 1 + i].xyz,
          vProj: &v40);
        if ( (float)((float)((float)(*v8 - v40.x) * (float)(*v8 - v40.x))
                   + (float)((float)((float)(v8[2] - v40.z) * (float)(v8[2] - v40.z))
                           + (float)((float)(v8[1] - v40.y) * (float)(v8[1] - v40.y)))) > v3 )
          v3 = (float)((float)((float)(*v8 - v40.x) * (float)(*v8 - v40.x))
                     + (float)((float)((float)(v8[2] - v40.z) * (float)(v8[2] - v40.z))
                             + (float)((float)(v8[1] - v40.y) * (float)(v8[1] - v40.y))));
        v4 = v7 + 1;
      }
      while ( v4 < height );
      if ( v3 >= 0.040000003 )
        continue;
    }
    v9 = 0;
    --this->width;
    if ( height > 0 )
    {
      do
      {
        for ( j = i; j < this->width; v12->color[3] = v12[1].color[3] )
        {
          v11 = this->maxWidth * v9 + j++;
          v12 = &this->verts.list[v11];
          v12->xyz.x = v12[1].xyz.x;
          v12->xyz.y = v12[1].xyz.y;
          v12->xyz.z = v12[1].xyz.z;
          v12->st.x = v12[1].st.x;
          v12->st.y = v12[1].st.y;
          v12->normal[0] = v12[1].normal[0];
          v12->normal[1] = v12[1].normal[1];
          v12->normal[2] = v12[1].normal[2];
          v12->normal[3] = v12[1].normal[3];
          v12->tangent[0] = v12[1].tangent[0];
          v12->tangent[1] = v12[1].tangent[1];
          v12->tangent[2] = v12[1].tangent[2];
          v12->tangent[3] = v12[1].tangent[3];
          v12->color[0] = v12[1].color[0];
          v12->color[1] = v12[1].color[1];
          v12->color[2] = v12[1].color[2];
        }
        ++v9;
      }
      while ( v9 < this->height );
    }
    --i;
  }
  v13 = 1;
  if ( this->height - 1 > 1 )
  {
    v14 = idMath::FLT_SMALLEST_NON_DENORMAL;
    do
    {
      width = this->width;
      v16 = 0.0;
      v17 = 0;
      if ( width <= 0 )
        goto LABEL_22;
      v18 = this->maxWidth;
      v19 = this->verts.list;
      do
      {
        p_x = &v19[(v13 + 1) * v18 + v17].xyz.x;
        v21 = &v19[(v13 - 1) * v18 + v17].xyz.x;
        v22 = &v19[v18 * v13 + v17].xyz.x;
        v23 = (float)(p_x[1] - v21[1]);
        v24 = (float)(p_x[2] - v21[2]);
        _FP26 = (float)((float)((float)((float)(*p_x - *v21) * (float)(*p_x - *v21))
                              + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23)))
                      - (float)v14);
        __asm { fsel      f31, f26, f31, f11 }
        v27 = __frsqrte(_FP31);
        v28 = (float)((float)-(float)((float)((float)((float)v27
                                                    * (float)((float)((float)((float)(*p_x - *v21) * (float)(*p_x - *v21))
                                                                    + (float)((float)((float)v24 * (float)v24)
                                                                            + (float)((float)v23 * (float)v23)))
                                                            * (float)0.5))
                                            * (float)v27)
                                    - (float)1.5)
                    * (float)v27);
        v29 = (float)((float)-(float)((float)((float)((float)v28
                                                    * (float)((float)((float)((float)(*p_x - *v21) * (float)(*p_x - *v21))
                                                                    + (float)((float)((float)v24 * (float)v24)
                                                                            + (float)((float)v23 * (float)v23)))
                                                            * (float)0.5))
                                            * (float)v28)
                                    - (float)1.5)
                    * (float)v28);
        v30 = (float)((float)-(float)((float)((float)((float)v29
                                                    * (float)((float)((float)((float)(*p_x - *v21) * (float)(*p_x - *v21))
                                                                    + (float)((float)((float)v24 * (float)v24)
                                                                            + (float)((float)v23 * (float)v23)))
                                                            * (float)0.5))
                                            * (float)v29)
                                    - (float)1.5)
                    * (float)v29);
        v31 = (float)(v22[1]
                    - (float)(v21[1]
                            + (float)((float)((float)(p_x[1] - v21[1]) * (float)v30)
                                    * (float)((float)((float)(*v22 - *v21) * (float)((float)(*p_x - *v21) * (float)v30))
                                            + (float)((float)((float)((float)(p_x[2] - v21[2]) * (float)v30)
                                                            * (float)(v22[2] - v21[2]))
                                                    + (float)((float)((float)(p_x[1] - v21[1]) * (float)v30)
                                                            * (float)(v22[1] - v21[1])))))));
        v32 = (float)(v22[2]
                    - (float)((float)((float)((float)(p_x[2] - v21[2]) * (float)v30)
                                    * (float)((float)((float)(*v22 - *v21) * (float)((float)(*p_x - *v21) * (float)v30))
                                            + (float)((float)((float)((float)(p_x[2] - v21[2]) * (float)v30)
                                                            * (float)(v22[2] - v21[2]))
                                                    + (float)((float)((float)(p_x[1] - v21[1]) * (float)v30)
                                                            * (float)(v22[1] - v21[1])))))
                            + v21[2]));
        v33 = (float)(*v22
                    - (float)(*v21
                            + (float)((float)((float)((float)(*v22 - *v21) * (float)((float)(*p_x - *v21) * (float)v30))
                                            + (float)((float)((float)((float)(p_x[2] - v21[2]) * (float)v30)
                                                            * (float)(v22[2] - v21[2]))
                                                    + (float)((float)((float)(p_x[1] - v21[1]) * (float)v30)
                                                            * (float)(v22[1] - v21[1]))))
                                    * (float)((float)(*p_x - *v21) * (float)v30))));
        v34 = (float)((float)((float)v33 * (float)v33)
                    + (float)((float)((float)v32 * (float)v32) + (float)((float)v31 * (float)v31)));
        if ( v34 > v16 )
          v16 = v34;
        ++v17;
      }
      while ( v17 < width );
      if ( v16 < 0.040000003 )
      {
LABEL_22:
        v35 = 0;
        --this->height;
        if ( width > 0 )
        {
          do
          {
            for ( k = v13; k < this->height; ++k )
            {
              v37 = this->maxWidth;
              v38 = &this->verts.list[(k + 1) * v37 + v35];
              v39 = &this->verts.list[v37 * k + v35];
              v39->xyz.x = v38->xyz.x;
              v39->xyz.y = v38->xyz.y;
              v39->xyz.z = v38->xyz.z;
              v39->st.x = v38->st.x;
              v39->st.y = v38->st.y;
              v39->normal[0] = v38->normal[0];
              v39->normal[1] = v38->normal[1];
              v39->normal[2] = v38->normal[2];
              v39->normal[3] = v38->normal[3];
              v39->tangent[0] = v38->tangent[0];
              v39->tangent[1] = v38->tangent[1];
              v39->tangent[2] = v38->tangent[2];
              v39->tangent[3] = v38->tangent[3];
              v39->color[0] = v38->color[0];
              v39->color[1] = v38->color[1];
              v39->color[2] = v38->color[2];
              v39->color[3] = v38->color[3];
            }
            ++v35;
          }
          while ( v35 < this->width );
        }
        v14 = idMath::FLT_SMALLEST_NON_DENORMAL;
        --v13;
      }
      ++v13;
    }
    while ( v13 < this->height - 1 );
  }
}


// ========================================================================
// ?GenerateNormals@idSurface_Patch@@AAAXXZ
// EA  : 0x82F21F60
// RVA : 0x00F21F60
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.cpp
// ========================================================================

void __fastcall idSurface_Patch::GenerateNormals(idSurface_Patch *this)
{
  int width; // r6
  int height; // r8
  int *p_width; // r14
  idDrawVert *list; // r11
  idDrawVert *v6; // r10
  idDrawVert *v7; // r9
  int v8; // r4
  double v9; // fp0
  double v10; // fp12
  double v11; // fp13
  idDrawVert *v12; // r10
  double v13; // fp8
  double v14; // fp11
  double v15; // fp10
  double v17; // fp13
  double v20; // fp1
  double v21; // fp7
  double v22; // fp2
  double v23; // fp12
  int v24; // r9
  int v25; // r6
  int v26; // r7
  bool v27; // cr58
  int v28; // r8
  int v29; // r9
  int v33; // r10
  int v39; // r24
  int v40; // r6
  int v41; // r9
  int v42; // r7
  int v43; // r5
  float *v44; // r10
  float *v45; // r8
  double v46; // fp8
  double v47; // fp4
  double v48; // fp1
  float *v49; // r10
  float *v50; // r8
  double v51; // fp8
  double v52; // fp4
  double v53; // fp1
  double v54; // fp11
  double v55; // fp10
  double v56; // fp8
  float *v57; // r10
  double v58; // fp6
  double v59; // fp3
  double v60; // fp1
  double v61; // fp11
  double v62; // fp10
  double v63; // fp8
  idDrawVert *v64; // r10
  double v65; // fp6
  double v66; // fp3
  double v67; // fp1
  bool v68; // cr58
  int v69; // r7
  int v70; // r8
  float *v71; // r10
  float *p_x; // r9
  double v73; // fp8
  double v74; // fp4
  double v75; // fp1
  int v76; // r31
  char v77; // r15
  int v78; // r7
  int v79; // r5
  int v80; // r4
  int v81; // r8
  float *v82; // r10
  float *v83; // r9
  double v84; // fp6
  double v85; // fp1
  double v86; // fp3
  double v87; // fp8
  double v88; // fp4
  double v89; // fp1
  int v90; // r6
  idDrawVert *v91; // r10
  float *v92; // r9
  double v93; // fp8
  double v94; // fp4
  double v95; // fp1
  float *v96; // r9
  double v97; // fp6
  double v98; // fp1
  double v99; // fp3
  bool v100; // cr58
  int v101; // r8
  float *v102; // r9
  double v103; // fp6
  double v104; // fp1
  double v105; // fp3
  int v106; // r27
  int v107; // r4
  int v108; // r8
  float *v109; // r6
  idDrawVert *v110; // r26
  double x; // fp8
  double y; // fp7
  double z; // fp6
  double v114; // fp11
  double v115; // fp10
  int v116; // r9
  int v117; // r11
  int v118; // r10
  double v119; // fp11
  double v120; // fp4
  double v123; // fp3
  double v124; // fp12
  double v125; // fp1
  double v126; // fp3
  double v127; // fp1
  double v128; // fp11
  double v129; // fp10
  double v130; // fp10
  double v131; // fp11
  int v132; // r7
  double v133; // fp12
  float *i; // r10
  double v135; // fp7
  double v136; // fp6
  double v137; // fp4
  double v140; // fp8
  double v141; // fp2
  double v142; // fp2
  char v143; // [sp+0h] [-140h]
  int v144; // [sp+4h] [-13Ch]
  float v145; // [sp+8h] [-138h] BYREF
  float v146; // [sp+Ch] [-134h] BYREF
  float v147[9]; // [sp+10h] [-130h] BYREF
  char v148; // [sp+34h] [-10Ch] BYREF
  char v149; // [sp+38h] [-108h] BYREF

  width = this->width;
  height = this->height;
  p_width = &this->width;
  list = this->verts.list;
  v6 = &this->verts.list[width];
  v7 = &this->verts.list[height * width];
  v8 = (height - 1) * width;
  v9 = (float)(v6[-1].xyz.y - this->verts.list->xyz.y);
  v10 = (float)(v6[-1].xyz.z - this->verts.list->xyz.z);
  v11 = (float)(v6[-1].xyz.x - this->verts.list->xyz.x);
  v13 = (float)((float)((float)(v7[-1].xyz.y - this->verts.list->xyz.y) * (float)(v6[-1].xyz.x - this->verts.list->xyz.x))
              - (float)((float)(v6[-1].xyz.y - this->verts.list->xyz.y) * (float)(v7[-1].xyz.x - this->verts.list->xyz.x)));
  v14 = (float)((float)((float)(v7[-1].xyz.z - this->verts.list->xyz.z) * (float)(v6[-1].xyz.y - this->verts.list->xyz.y))
              - (float)((float)(v7[-1].xyz.y - this->verts.list->xyz.y) * (float)(v6[-1].xyz.z - this->verts.list->xyz.z)));
  v15 = (float)((float)((float)(v6[-1].xyz.z - this->verts.list->xyz.z) * (float)(v7[-1].xyz.x - this->verts.list->xyz.x))
              - (float)((float)(v7[-1].xyz.z - this->verts.list->xyz.z) * (float)(v6[-1].xyz.x - this->verts.list->xyz.x)));
  v12 = &this->verts.list[v8];
  if ( (float)((float)((float)v15 * (float)v15)
             + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) == 0.0 )
  {
    v13 = (float)((float)((float)(this->verts.list[v8].xyz.y - this->verts.list->xyz.y) * (float)v11)
                - (float)((float)v9 * (float)(this->verts.list[v8].xyz.x - this->verts.list->xyz.x)));
    v14 = (float)((float)((float)(v12->xyz.z - this->verts.list->xyz.z) * (float)v9)
                - (float)((float)(this->verts.list[v8].xyz.y - this->verts.list->xyz.y) * (float)v10));
    v15 = (float)((float)((float)v10 * (float)(this->verts.list[v8].xyz.x - this->verts.list->xyz.x))
                - (float)((float)(v12->xyz.z - this->verts.list->xyz.z) * (float)v11));
    if ( (float)((float)((float)v15 * (float)v15)
               + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) == 0.0 )
    {
      v14 = (float)((float)((float)(v12->xyz.z - this->verts.list->xyz.z)
                          * (float)(v7[-1].xyz.y - this->verts.list->xyz.y))
                  - (float)((float)(this->verts.list[v8].xyz.y - this->verts.list->xyz.y)
                          * (float)(v7[-1].xyz.z - this->verts.list->xyz.z)));
      v15 = (float)((float)((float)(v7[-1].xyz.z - this->verts.list->xyz.z)
                          * (float)(this->verts.list[v8].xyz.x - this->verts.list->xyz.x))
                  - (float)((float)(v12->xyz.z - this->verts.list->xyz.z)
                          * (float)(v7[-1].xyz.x - this->verts.list->xyz.x)));
      v13 = (float)((float)((float)(this->verts.list[v8].xyz.y - this->verts.list->xyz.y)
                          * (float)(v7[-1].xyz.x - this->verts.list->xyz.x))
                  - (float)((float)(v7[-1].xyz.y - this->verts.list->xyz.y)
                          * (float)(this->verts.list[v8].xyz.x - this->verts.list->xyz.x)));
    }
  }
  _R16 = 1;
  v17 = idMath::FLT_SMALLEST_NON_DENORMAL;
  _FP4 = (float)((float)((float)((float)v15 * (float)v15)
                       + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f4, f6, f13 }
  v20 = __frsqrte(_FP2);
  v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                      * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)))
                                                                                              * (float)0.5))
                                                                              * (float)v20)
                                                                      - (float)1.5)
                                                      * (float)v20)
                                              * (float)((float)((float)((float)v15 * (float)v15)
                                                              + (float)((float)((float)v14 * (float)v14)
                                                                      + (float)((float)v13 * (float)v13)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v20
                                                                              * (float)((float)((float)((float)v15 * (float)v15)
                                                                                              + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)))
                                                                                      * (float)0.5))
                                                                      * (float)v20)
                                                              - (float)1.5)
                                              * (float)v20))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v20
                                                      * (float)((float)((float)((float)v15 * (float)v15)
                                                                      + (float)((float)((float)v14 * (float)v14)
                                                                              + (float)((float)v13 * (float)v13)))
                                                              * (float)0.5))
                                              * (float)v20)
                                      - (float)1.5)
                      * (float)v20));
  v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                              * (float)v20)
                                                                                      * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                      * (float)v20))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v20
                                                                                              * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5))
                                                                                      * (float)v20)
                                                                              - (float)1.5)
                                                              * (float)v20))
                                              * (float)((float)((float)((float)v15 * (float)v15)
                                                              + (float)((float)((float)v14 * (float)v14)
                                                                      + (float)((float)v13 * (float)v13)))
                                                      * (float)0.5))
                                      * (float)v21)
                              - (float)1.5)
              * (float)v21);
  v23 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v20) - (float)1.5) * (float)v20)
                                                                                              * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                              * (float)v20))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5))
                                                                                              * (float)v20)
                                                                                      - (float)1.5)
                                                                      * (float)v20))
                                                      * (float)((float)((float)((float)v15 * (float)v15)
                                                                      + (float)((float)((float)v14 * (float)v14)
                                                                              + (float)((float)v13 * (float)v13)))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21)
              * (float)v14);
  v145 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                               * (float)v20)
                                                                                       * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)))
                                                                                               * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                       * (float)v20))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v20
                                                                                               * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5))
                                                                                       * (float)v20)
                                                                               - (float)1.5)
                                                               * (float)v20))
                                               * (float)((float)((float)((float)v15 * (float)v15)
                                                               + (float)((float)((float)v14 * (float)v14)
                                                                       + (float)((float)v13 * (float)v13)))
                                                       * (float)0.5))
                                       * (float)v21)
                               - (float)1.5)
               * (float)v21)
       * (float)v14;
  v146 = (float)v15
       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                               * (float)v20)
                                                                                       * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)))
                                                                                               * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                       * (float)v20))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v20
                                                                                               * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5))
                                                                                       * (float)v20)
                                                                               - (float)1.5)
                                                               * (float)v20))
                                               * (float)((float)((float)((float)v15 * (float)v15)
                                                               + (float)((float)((float)v14 * (float)v14)
                                                                       + (float)((float)v13 * (float)v13)))
                                                       * (float)0.5))
                                       * (float)v21)
                               - (float)1.5)
               * (float)v21);
  v147[0] = (float)v13
          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                                  * (float)v20)
                                                                                          * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)))
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                          * (float)v20))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v20
                                                                                                  * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5))
                                                                                          * (float)v20)
                                                                                  - (float)1.5)
                                                                  * (float)v20))
                                                  * (float)((float)((float)((float)v15 * (float)v15)
                                                                  + (float)((float)((float)v14 * (float)v14)
                                                                          + (float)((float)v13 * (float)v13)))
                                                          * (float)0.5))
                                          * (float)v21)
                                  - (float)1.5)
                  * (float)v21);
  if ( (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v20) - (float)1.5) * (float)v20)
                                                                                             * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5))
                                                                                     * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                             * (float)v20))
                                                                             - (float)1.5)
                                                             * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) * (float)0.5))
                                                                                             * (float)v20)
                                                                                     - (float)1.5)
                                                                     * (float)v20))
                                                     * (float)((float)((float)((float)v15 * (float)v15)
                                                                     + (float)((float)((float)v14 * (float)v14)
                                                                             + (float)((float)v13 * (float)v13)))
                                                             * (float)0.5))
                                             * (float)v21)
                                     - (float)1.5)
                     * (float)v21)
             * (float)((float)((float)v15 * (float)v15)
                     + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)))) == 0.0 )
    goto LABEL_27;
  v24 = 1;
  v25 = this->height * *p_width;
  if ( v25 > 1 )
  {
    if ( v25 - 1 < 4 )
    {
LABEL_13:
      v27 = v24 == v25;
      if ( v24 >= v25 )
        goto LABEL_22;
      v28 = v24;
      do
      {
        if ( __fabs((float)((float)((float)(list[v28].xyz.x * (float)v23)
                                  + (float)((float)(list[v28].xyz.z * (float)((float)v13 * (float)v22))
                                          + (float)(list[v28].xyz.y * (float)((float)v15 * (float)v22))))
                          - (float)((float)(list->xyz.x * (float)v23)
                                  + (float)((float)(list->xyz.z * (float)((float)v13 * (float)v22))
                                          + (float)(list->xyz.y * (float)((float)v15 * (float)v22)))))) > 0.1 )
          break;
        ++v24;
        ++v28;
      }
      while ( v24 < v25 );
    }
    else
    {
      v26 = 1;
      while ( __fabs((float)((float)((float)(list[v26].xyz.x * (float)v23)
                                   + (float)((float)(list[v26].xyz.z * (float)((float)v13 * (float)v22))
                                           + (float)(list[v26].xyz.y * (float)((float)v15 * (float)v22))))
                           - (float)((float)(list->xyz.x * (float)v23)
                                   + (float)((float)(list->xyz.z * (float)((float)v13 * (float)v22))
                                           + (float)(list->xyz.y * (float)((float)v15 * (float)v22)))))) <= 0.1 )
      {
        if ( __fabs((float)((float)((float)(list[v26 + 1].xyz.x * (float)v23)
                                  + (float)((float)(list[v26 + 1].xyz.z * (float)((float)v13 * (float)v22))
                                          + (float)(list[v26 + 1].xyz.y * (float)((float)v15 * (float)v22))))
                          - (float)((float)(list->xyz.x * (float)v23)
                                  + (float)((float)(list->xyz.z * (float)((float)v13 * (float)v22))
                                          + (float)(list->xyz.y * (float)((float)v15 * (float)v22)))))) > 0.1 )
        {
          ++v24;
          break;
        }
        if ( __fabs((float)((float)((float)(list[v26 + 2].xyz.x * (float)v23)
                                  + (float)((float)(list[v26 + 2].xyz.z * (float)((float)v13 * (float)v22))
                                          + (float)(list[v26 + 2].xyz.y * (float)((float)v15 * (float)v22))))
                          - (float)((float)(list->xyz.x * (float)v23)
                                  + (float)((float)(list->xyz.z * (float)((float)v13 * (float)v22))
                                          + (float)(list->xyz.y * (float)((float)v15 * (float)v22)))))) > 0.1 )
        {
          v24 += 2;
          break;
        }
        if ( __fabs((float)((float)((float)(list[v26 + 3].xyz.x * (float)v23)
                                  + (float)((float)(list[v26 + 3].xyz.z * (float)((float)v13 * (float)v22))
                                          + (float)(list[v26 + 3].xyz.y * (float)((float)v15 * (float)v22))))
                          - (float)((float)(list->xyz.x * (float)v23)
                                  + (float)((float)(list->xyz.z * (float)((float)v13 * (float)v22))
                                          + (float)(list->xyz.y * (float)((float)v15 * (float)v22)))))) > 0.1 )
        {
          v24 += 3;
          break;
        }
        v24 += 4;
        v26 += 4;
        if ( v24 >= v25 - 3 )
          goto LABEL_13;
      }
    }
  }
  v27 = v24 == v25;
LABEL_22:
  if ( v27 )
  {
    v29 = 0;
    if ( v25 > 0 )
    {
      _R11 = &v145;
      __asm { vspltisw128 v63, 0 }
      _R8 = &v146;
      _R7 = v147;
      v33 = 0;
      __asm { lvlx128   v62, r0, r11 }
      __asm
      {
        vrlimi128 v63, v62, 8, 0
        lvlx128   v61, r0, r8
        lvlx128   v60, r0, r7
      }
      _R5 = 2;
      _R8 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
      __asm { vor128    v62, v95, v63 }
      _R7 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
      _R6 = &_vmx_3f8000003f8000003f8000003f800000;
      __asm
      {
        vrlimi128 v62, v61, 4, 3
        vrlimi128 v62, v60, 2, 2
      }
      do
      {
        __asm { lvx128    v63, r0, r6 }
        __asm
        {
          vaddfp128 v12, v94, v63
          lvx128    v0, r0, r7
          lvx128    v13, r0, r8
        }
        ++v29;
        _R11 = this->verts.list[v33++].normal;
        __asm
        {
          vmaddfp   v0, v12, v0, v13
          vcfpsxws128 v59, v0, 0
          vpkswss128 v58, v91, v59
          vpkshus128 v0, v90, v58
          stvebx    v0, 0, r11
          stvebx    v0, r11, r16
          stvebx    v0, r11, r5
        }
      }
      while ( v29 < this->height * *p_width );
    }
    return;
  }
LABEL_27:
  v39 = this->height;
  v143 = 0;
  v40 = 0;
  if ( v39 < 4 )
  {
LABEL_34:
    v68 = v40 == v39;
    if ( v40 >= v39 )
      goto LABEL_43;
    v69 = *p_width;
    v70 = 32 * (v40 + 1);
    do
    {
      v71 = (float *)((char *)&list->xyz.x + v69 * v70);
      p_x = &list[v69 * v40].xyz.x;
      v73 = (float)(p_x[1] - *(v71 - 7));
      v74 = (float)(p_x[2] - *(v71 - 6));
      v75 = (float)(*p_x - *(v71 - 8));
      if ( (float)((float)((float)v75 * (float)v75)
                 + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73))) > 1.0 )
        break;
      ++v40;
      v70 += 32;
    }
    while ( v40 < v39 );
  }
  else
  {
    v41 = *p_width;
    v42 = 2;
    v43 = 32;
    while ( 1 )
    {
      v44 = (float *)((char *)&list->xyz.x + v41 * v43);
      v45 = &list[v41 * v40].xyz.x;
      v46 = (float)(v45[1] - *(v44 - 7));
      v47 = (float)(v45[2] - *(v44 - 6));
      v48 = (float)(*v45 - *(v44 - 8));
      if ( (float)((float)((float)v48 * (float)v48)
                 + (float)((float)((float)v47 * (float)v47) + (float)((float)v46 * (float)v46))) > 1.0 )
        break;
      v49 = &list[v41 * v42].xyz.x;
      v50 = &list[(v42 - 1) * v41].xyz.x;
      v51 = (float)(v50[1] - *(v49 - 7));
      v52 = (float)(v50[2] - *(v49 - 6));
      v53 = (float)(*v50 - *(v49 - 8));
      if ( (float)((float)((float)v53 * (float)v53)
                 + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) > 1.0 )
      {
        ++v40;
        break;
      }
      v54 = v49[1];
      v55 = v49[2];
      v56 = *v49;
      v57 = &list[(v42 + 1) * v41].xyz.x;
      v58 = (float)((float)v54 - *(v57 - 7));
      v59 = (float)((float)v55 - *(v57 - 6));
      v60 = (float)((float)v56 - *(v57 - 8));
      if ( (float)((float)((float)v60 * (float)v60)
                 + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58))) > 1.0 )
      {
        v40 += 2;
        break;
      }
      v61 = v57[1];
      v62 = v57[2];
      v63 = *v57;
      v64 = &list[(v42 + 2) * v41];
      v65 = (float)((float)v61 - v64[-1].xyz.y);
      v66 = (float)((float)v62 - v64[-1].xyz.z);
      v67 = (float)((float)v63 - v64[-1].xyz.x);
      if ( (float)((float)((float)v67 * (float)v67)
                 + (float)((float)((float)v66 * (float)v66) + (float)((float)v65 * (float)v65))) > 1.0 )
      {
        v40 += 3;
        break;
      }
      v40 += 4;
      v43 += 128;
      v42 += 4;
      if ( v40 >= v39 - 3 )
        goto LABEL_34;
    }
  }
  v68 = v40 == v39;
LABEL_43:
  if ( v68 )
    v143 = 1;
  v76 = *p_width;
  v77 = 0;
  v78 = 0;
  if ( *p_width < 4 )
  {
LABEL_52:
    v100 = v78 == v76;
    if ( v78 >= v76 )
      goto LABEL_61;
    v101 = v78;
    do
    {
      v102 = &list[(v39 - 1) * v76 + v78].xyz.x;
      v103 = (float)(list[v101].xyz.y - v102[1]);
      v104 = (float)(list[v101].xyz.x - *v102);
      v105 = (float)(list[v101].xyz.z - v102[2]);
      if ( (float)((float)((float)v104 * (float)v104)
                 + (float)((float)((float)v105 * (float)v105) + (float)((float)v103 * (float)v103))) > 1.0 )
        break;
      ++v78;
      ++v101;
    }
    while ( v78 < v76 );
  }
  else
  {
    v79 = 0;
    v80 = (v39 - 1) * v76;
    while ( 1 )
    {
      v81 = v80 + v78;
      v82 = &list[v79].xyz.x;
      v83 = &list[v80 + v78].xyz.x;
      v84 = (float)(list[v79].xyz.y - v83[1]);
      v85 = (float)(list[v79].xyz.x - *v83);
      v86 = (float)(list[v79].xyz.z - v83[2]);
      if ( (float)((float)((float)v85 * (float)v85)
                 + (float)((float)((float)v86 * (float)v86) + (float)((float)v84 * (float)v84))) > 1.0 )
        break;
      v87 = (float)(v82[9] - v83[9]);
      v88 = (float)(v82[10] - v83[10]);
      v89 = (float)(v82[8] - v83[8]);
      if ( (float)((float)((float)v89 * (float)v89)
                 + (float)((float)((float)v88 * (float)v88) + (float)((float)v87 * (float)v87))) > 1.0 )
      {
        ++v78;
        break;
      }
      v90 = v79 * 32 + 96;
      v91 = &list[v79 + 3];
      v92 = &list[v81 + 2].xyz.x;
      v93 = (float)(v91[-1].xyz.y - v92[1]);
      v94 = (float)(v91[-1].xyz.z - v92[2]);
      v95 = (float)(v91[-1].xyz.x - *v92);
      if ( (float)((float)((float)v95 * (float)v95)
                 + (float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93))) > 1.0 )
      {
        v78 += 2;
        break;
      }
      v96 = &list[v81 + 3].xyz.x;
      v97 = (float)(*(float *)((char *)&list->xyz.y + v90) - v96[1]);
      v98 = (float)(*(float *)((char *)&list->xyz.x + v90) - *v96);
      v99 = (float)(*(float *)((char *)&list->xyz.z + v90) - v96[2]);
      if ( (float)((float)((float)v98 * (float)v98)
                 + (float)((float)((float)v99 * (float)v99) + (float)((float)v97 * (float)v97))) > 1.0 )
      {
        v78 += 3;
        break;
      }
      v78 += 4;
      v79 += 4;
      if ( v78 >= v76 - 3 )
        goto LABEL_52;
    }
  }
  v100 = v78 == v76;
LABEL_61:
  if ( v100 )
    v77 = 1;
  v106 = 0;
  if ( v76 > 0 )
  {
    do
    {
      if ( v39 > 0 )
      {
        v107 = 0;
        v108 = 0;
        v109 = (float *)&v149;
        v110 = &this->verts.list[v106];
        x = v110->xyz.x;
        y = v110->xyz.y;
        z = v110->xyz.z;
        while ( 1 )
        {
          v114 = vec3_origin.y;
          v115 = vec3_origin.z;
          v116 = 1;
          *(v109 - 2) = vec3_origin.x;
          *(v109 - 1) = v114;
          *v109 = v115;
          *((_BYTE *)&v145 + v107) = 0;
          while ( 1 )
          {
            v117 = neighbors[v108][1] * v116;
            v118 = neighbors[v108][0] * v116 + v106;
            if ( v143 != 0 )
            {
              if ( v118 >= 0 )
              {
                if ( v118 >= (int)allocationCurrent[242] )
                  v118 += 2088566785;
              }
              else
              {
                v118 += (int)&allocationCurrent[241][1] + 3;
              }
            }
            if ( v77 != 0 )
            {
              if ( v117 >= 0 )
              {
                if ( v117 >= v39 )
                  v117 = v117 - v39 + 1;
              }
              else
              {
                v117 = v39 + v117 - 1;
              }
            }
            if ( v118 < 0 || v118 >= (int)allocationCurrent[242] || v117 < 0 || v117 >= v39 )
              goto LABEL_85;
            v117 = 32 * ((_DWORD)allocationCurrent[242] * v117 + v118) + v76;
            v119 = (float)(*(float *)(v117 + 4) - (float)y);
            v120 = (float)(*(float *)(v117 + 8) - (float)z);
            _FP3 = (float)((float)((float)((float)(*(float *)v117 - (float)x) * (float)(*(float *)v117 - (float)x))
                                 + (float)((float)((float)v120 * (float)v120) + (float)((float)v119 * (float)v119)))
                         - (float)v17);
            __asm { fsel      f12, f3, f10, f13 }
            v123 = __frsqrte(_FP12);
            v124 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v123
                                                                                                 * (float)((float)((float)((float)(*(float *)v117 - (float)x) * (float)(*(float *)v117 - (float)x)) + (float)((float)((float)v120 * (float)v120) + (float)((float)v119 * (float)v119))) * (float)0.5))
                                                                                         * (float)v123)
                                                                                 - (float)1.5)
                                                                 * (float)v123)
                                                         * (float)((float)((float)((float)(*(float *)v117 - (float)x)
                                                                                 * (float)(*(float *)v117 - (float)x))
                                                                         + (float)((float)((float)v120 * (float)v120)
                                                                                 + (float)((float)v119 * (float)v119)))
                                                                 * (float)0.5))
                                                 * (float)((float)-(float)((float)((float)((float)v123
                                                                                         * (float)((float)((float)((float)(*(float *)v117 - (float)x) * (float)(*(float *)v117 - (float)x)) + (float)((float)((float)v120 * (float)v120) + (float)((float)v119 * (float)v119)))
                                                                                                 * (float)0.5))
                                                                                 * (float)v123)
                                                                         - (float)1.5)
                                                         * (float)v123))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v123
                                                                 * (float)((float)((float)((float)(*(float *)v117
                                                                                                 - (float)x)
                                                                                         * (float)(*(float *)v117
                                                                                                 - (float)x))
                                                                                 + (float)((float)((float)v120
                                                                                                 * (float)v120)
                                                                                         + (float)((float)v119
                                                                                                 * (float)v119)))
                                                                         * (float)0.5))
                                                         * (float)v123)
                                                 - (float)1.5)
                                 * (float)v123));
            v125 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)(*(float *)v117 - (float)x) * (float)(*(float *)v117 - (float)x)) + (float)((float)((float)v120 * (float)v120) + (float)((float)v119 * (float)v119))) * (float)0.5)) * (float)v123) - (float)1.5)
                                                                                                 * (float)v123)
                                                                                         * (float)((float)((float)((float)(*(float *)v117 - (float)x) * (float)(*(float *)v117 - (float)x)) + (float)((float)((float)v120 * (float)v120) + (float)((float)v119 * (float)v119)))
                                                                                                 * (float)0.5))
                                                                                 * (float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)(*(float *)v117 - (float)x) * (float)(*(float *)v117 - (float)x)) + (float)((float)((float)v120 * (float)v120) + (float)((float)v119 * (float)v119))) * (float)0.5)) * (float)v123) - (float)1.5)
                                                                                         * (float)v123))
                                                                         - (float)1.5)
                                                         * (float)((float)-(float)((float)((float)((float)v123
                                                                                                 * (float)((float)((float)((float)(*(float *)v117 - (float)x) * (float)(*(float *)v117 - (float)x)) + (float)((float)((float)v120 * (float)v120) + (float)((float)v119 * (float)v119))) * (float)0.5))
                                                                                         * (float)v123)
                                                                                 - (float)1.5)
                                                                 * (float)v123))
                                                 * (float)((float)((float)((float)(*(float *)v117 - (float)x)
                                                                         * (float)(*(float *)v117 - (float)x))
                                                                 + (float)((float)((float)v120 * (float)v120)
                                                                         + (float)((float)v119 * (float)v119)))
                                                         * (float)0.5))
                                         * (float)v124)
                                 - (float)1.5);
            v126 = (float)((float)v125
                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v123 * (float)((float)((float)((float)(*(float *)v117 - (float)x) * (float)(*(float *)v117 - (float)x)) + (float)((float)((float)v120 * (float)v120) + (float)((float)v119 * (float)v119))) * (float)0.5))
                                                                                                 * (float)v123)
                                                                                         - (float)1.5)
                                                                         * (float)v123)
                                                                 * (float)((float)((float)((float)(*(float *)v117
                                                                                                 - (float)x)
                                                                                         * (float)(*(float *)v117
                                                                                                 - (float)x))
                                                                                 + (float)((float)((float)v120
                                                                                                 * (float)v120)
                                                                                         + (float)((float)v119
                                                                                                 * (float)v119)))
                                                                         * (float)0.5))
                                                         * (float)((float)-(float)((float)((float)((float)v123
                                                                                                 * (float)((float)((float)((float)(*(float *)v117 - (float)x) * (float)(*(float *)v117 - (float)x)) + (float)((float)((float)v120 * (float)v120) + (float)((float)v119 * (float)v119))) * (float)0.5))
                                                                                         * (float)v123)
                                                                                 - (float)1.5)
                                                                 * (float)v123))
                                                 - (float)1.5)
                                 * (float)((float)-(float)((float)((float)((float)v123
                                                                         * (float)((float)((float)((float)(*(float *)v117 - (float)x)
                                                                                                 * (float)(*(float *)v117 - (float)x))
                                                                                         + (float)((float)((float)v120 * (float)v120)
                                                                                                 + (float)((float)v119 * (float)v119)))
                                                                                 * (float)0.5))
                                                                 * (float)v123)
                                                         - (float)1.5)
                                         * (float)v123)));
            v127 = (float)((float)v126
                         * (float)((float)((float)(*(float *)v117 - (float)x) * (float)(*(float *)v117 - (float)x))
                                 + (float)((float)((float)v120 * (float)v120) + (float)((float)v119 * (float)v119))));
            v128 = (float)((float)(*(float *)(v117 + 4) - (float)y) * (float)v126);
            v129 = (float)((float)(*(float *)(v117 + 8) - (float)z) * (float)v126);
            if ( v127 != 0.0 )
              break;
            if ( ++v116 > 3 )
              goto LABEL_85;
          }
          *(v109 - 2) = (float)(*(float *)v117 - (float)x) * (float)v126;
          *((_BYTE *)&v145 + v107) = 1;
          *(v109 - 1) = v128;
          *v109 = v129;
LABEL_85:
          ++v108;
          ++v107;
          v109 += 3;
          if ( v108 >= 8 )
          {
            v130 = 0.0;
            v131 = 0.0;
            v132 = 1;
            v133 = 0.0;
            for ( i = (float *)&v148; ; i += 3 )
            {
              if ( *((_BYTE *)&v144 + v132 + 3) != 0 && *((_BYTE *)&v145 + (v132 & 7)) != 0 )
              {
                v117 = (int)&v147[3 * v117 + 8];
                v135 = (float)((float)(*(i - 1) * *(float *)(v117 + 8)) - (float)(i[1] * *(float *)v117));
                v136 = (float)((float)(*i * *(float *)v117) - (float)(*(i - 1) * *(float *)(v117 + 4)));
                v137 = (float)((float)(i[1] * *(float *)(v117 + 4)) - (float)(*i * *(float *)(v117 + 8)));
                _FP8 = (float)((float)((float)((float)v137 * (float)v137)
                                     + (float)((float)((float)v136 * (float)v136) + (float)((float)v135 * (float)v135)))
                             - (float)v17);
                __asm { fsel      f2, f8, f1, f13 }
                v140 = __frsqrte(_FP2);
                v141 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v140 * (float)((float)((float)((float)v137 * (float)v137) + (float)((float)((float)v136 * (float)v136) + (float)((float)v135 * (float)v135))) * (float)0.5))
                                                                                             * (float)v140)
                                                                                     - (float)1.5)
                                                                     * (float)v140)
                                                             * (float)((float)((float)((float)v137 * (float)v137)
                                                                             + (float)((float)((float)v136 * (float)v136)
                                                                                     + (float)((float)v135 * (float)v135)))
                                                                     * (float)0.5))
                                                     * (float)((float)-(float)((float)((float)((float)v140
                                                                                             * (float)((float)((float)((float)v137 * (float)v137) + (float)((float)((float)v136 * (float)v136) + (float)((float)v135 * (float)v135))) * (float)0.5))
                                                                                     * (float)v140)
                                                                             - (float)1.5)
                                                             * (float)v140))
                                             - (float)1.5)
                             * (float)((float)-(float)((float)((float)((float)v140
                                                                     * (float)((float)((float)((float)v137 * (float)v137)
                                                                                     + (float)((float)((float)v136 * (float)v136)
                                                                                             + (float)((float)v135 * (float)v135)))
                                                                             * (float)0.5))
                                                             * (float)v140)
                                                     - (float)1.5)
                                     * (float)v140));
                v142 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v140 * (float)((float)((float)((float)v137 * (float)v137) + (float)((float)((float)v136 * (float)v136) + (float)((float)v135 * (float)v135))) * (float)0.5)) * (float)v140) - (float)1.5) * (float)v140) * (float)((float)((float)((float)v137 * (float)v137) + (float)((float)((float)v136 * (float)v136) + (float)((float)v135 * (float)v135))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v140 * (float)((float)((float)((float)v137 * (float)v137) + (float)((float)((float)v136 * (float)v136) + (float)((float)v135 * (float)v135))) * (float)0.5)) * (float)v140) - (float)1.5) * (float)v140))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v140 * (float)((float)((float)((float)v137 * (float)v137) + (float)((float)((float)v136 * (float)v136) + (float)((float)v135 * (float)v135))) * (float)0.5)) * (float)v140)
                                                                                             - (float)1.5)
                                                                             * (float)v140))
                                                             * (float)((float)((float)((float)v137 * (float)v137)
                                                                             + (float)((float)((float)v136 * (float)v136)
                                                                                     + (float)((float)v135 * (float)v135)))
                                                                     * (float)0.5))
                                                     * (float)v141)
                                             - (float)1.5)
                             * (float)v141);
                if ( (float)((float)v142
                           * (float)((float)((float)v137 * (float)v137)
                                   + (float)((float)((float)v136 * (float)v136) + (float)((float)v135 * (float)v135)))) != 0.0 )
                {
                  v133 = (float)((float)v133
                               + (float)((float)v142
                                       * (float)((float)(i[1] * *(float *)(v117 + 4))
                                               - (float)(*i * *(float *)(v117 + 8)))));
                  v131 = (float)((float)v131
                               + (float)((float)((float)(*(i - 1) * *(float *)(v117 + 8))
                                               - (float)(i[1] * *(float *)v117))
                                       * (float)v142));
                  v130 = (float)((float)v130
                               + (float)((float)((float)(*i * *(float *)v117) - (float)(*(i - 1) * *(float *)(v117 + 4)))
                                       * (float)v142));
                }
              }
              ++v132;
            }
          }
        }
      }
      ++v106;
    }
    while ( v106 < *p_width );
  }
}


// ========================================================================
// ?SampleSinglePatchPoint@idSurface_Patch@@ABAXQAY02$$CBVidDrawVert@@MMPAV2@@Z
// EA  : 0x82F22B18
// RVA : 0x00F22B18
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.cpp
// ========================================================================

void __fastcall idSurface_Patch::SampleSinglePatchPoint(
        idSurface_Patch *this,
        const idDrawVert (*ctrl)[3],
        double u,
        double v,
        idDrawVert *out,
        int a6,
        __int64 a7)
{
  const idDrawVert *v8; // r29
  idVec2 *p_st; // r30
  float *v11; // r27
  float *p_y; // r31
  int v13; // r28
  const idVec3 *Normal; // r3
  double x; // fp28
  double y; // fp27
  double z; // fp26
  __int64 v18; // r8
  int v19; // r5
  const idVec3 *v20; // r3
  double v21; // fp25
  double v22; // fp24
  double v23; // fp23
  __int64 v24; // r8
  int v25; // r5
  const idVec3 *v26; // r3
  double v28; // fp3
  double v29; // fp1
  double v30; // fp0
  double v31; // fp24
  double v32; // fp9
  double v33; // fp11
  double v34; // fp8
  double v35; // fp7
  double v36; // fp6
  double v37; // fp4
  double v38; // fp10
  double v39; // fp7
  double v40; // fp8
  double v41; // fp5
  double v42; // fp0
  double v43; // fp8
  double v44; // fp12
  double v45; // fp7
  double v46; // fp9
  double v47; // fp13
  double v48; // fp11
  double v49; // fp23
  double v50; // fp3
  double v51; // fp5
  double v52; // fp2
  double v53; // fp31
  double v54; // fp28
  double v55; // fp1
  double v56; // fp10
  double v57; // fp4
  double v58; // fp9
  double v59; // fp7
  double v62; // fp1
  double v63; // fp1
  idDrawVert v73; // [sp+60h] [-150h] BYREF
  float v74; // [sp+80h] [-130h]
  float v75; // [sp+84h] [-12Ch]
  float v76; // [sp+88h] [-128h]
  float v77; // [sp+8Ch] [-124h]
  float v78; // [sp+90h] [-120h]
  float v79; // [sp+94h] [-11Ch]
  float v80; // [sp+98h] [-118h]
  float v81; // [sp+9Ch] [-114h]
  float v82; // [sp+A0h] [-110h]
  float v83; // [sp+A4h] [-10Ch]
  float v84; // [sp+A8h] [-108h]
  float v85; // [sp+ACh] [-104h]
  float v86; // [sp+B0h] [-100h]
  float v87; // [sp+B4h] [-FCh]
  float v88; // [sp+B8h] [-F8h]
  float v89; // [sp+BCh] [-F4h]
  float v90; // [sp+C0h] [-F0h]
  float v91; // [sp+C4h] [-ECh]
  float v92; // [sp+C8h] [-E8h]
  float v93; // [sp+CCh] [-E4h]
  idDrawVert v94[5]; // [sp+D0h] [-E0h] BYREF

  v8 = &(*ctrl)[6];
  p_st = &v73.st;
  v11 = (float *)HIDWORD(a7);
  p_y = &(*ctrl)[5].st.y;
  v13 = 3;
  do
  {
    Normal = idDrawVert::GetNormal(this: (idDrawVert *)&v94[0].st.y, result: &v8[-6].xyz, a3: (int)out, a4: a7);
    x = Normal->x;
    y = Normal->y;
    z = Normal->z;
    v20 = idDrawVert::GetNormal(this: v94, result: &v8[-3].xyz, a3: v19, a4: v18);
    v21 = v20->x;
    v22 = v20->y;
    v23 = v20->z;
    v26 = idDrawVert::GetNormal(this: &v73, result: &v8->xyz, a3: v25, a4: v24);
    v28 = *(p_y - 43);
    v29 = *(p_y - 42);
    v30 = *(p_y - 41);
    v32 = (float)-(float)((float)((float)y * (float)2.0) - (float)((float)v22 * (float)2.0));
    v31 = (float)((float)((float)y - (float)((float)v22 * (float)2.0)) + v26->y);
    v33 = (float)((float)((float)((float)((float)x - (float)((float)v21 * (float)2.0)) + v26->x) * (float)u)
                - (float)((float)((float)x * (float)2.0) - (float)((float)v21 * (float)2.0)));
    v34 = (float)((float)((float)((float)((float)z - (float)((float)v23 * (float)2.0)) + v26->z) * (float)u)
                - (float)((float)((float)z * (float)2.0) - (float)((float)v23 * (float)2.0)));
    v35 = (float)((float)((float)((float)(*(p_y - 43) - (float)(*(p_y - 19) * (float)2.0)) + p_y[5]) * (float)u)
                - (float)((float)(*(p_y - 43) * (float)2.0) - (float)(*(p_y - 19) * (float)2.0)));
    v36 = (float)((float)((float)((float)(*(p_y - 42) - (float)(*(p_y - 18) * (float)2.0)) + p_y[6]) * (float)u)
                - (float)((float)(*(p_y - 42) * (float)2.0) - (float)(*(p_y - 18) * (float)2.0)));
    v37 = (float)((float)((float)((float)(*(p_y - 41) - (float)(*(p_y - 17) * (float)2.0)) + p_y[7]) * (float)u)
                - (float)((float)(*(p_y - 41) * (float)2.0) - (float)(*(p_y - 17) * (float)2.0)));
    p_st->y = (float)((float)((float)((float)((float)(*(p_y - 44) - (float)(*(p_y - 20) * (float)2.0)) + p_y[4])
                                    * (float)u)
                            - (float)((float)(*(p_y - 44) * (float)2.0) - (float)(*(p_y - 20) * (float)2.0)))
                    * (float)u)
            + *(p_y - 44);
    p_st[2].x = (float)((float)v33 * (float)u) + (float)x;
    p_st[3].x = (float)((float)v34 * (float)u) + (float)z;
    p_st[2].y = (float)((float)((float)((float)v31 * (float)u) + (float)v32) * (float)u) + (float)y;
    v38 = (float)((float)((float)v35 * (float)u) + (float)v28);
    v39 = *(p_y - 16);
    p_st[1].x = v38;
    p_st[1].y = (float)((float)v36 * (float)u) + (float)v29;
    v40 = (float)((float)((float)v37 * (float)u) + (float)v30);
    v41 = *(p_y - 40);
    p_y += 8;
    v42 = *p_y;
    --v13;
    p_st[3].y = v40;
    ++v8;
    p_st += 4;
    p_st->x = (float)((float)((float)((float)((float)((float)v41 - (float)((float)v39 * (float)2.0)) + (float)v42)
                                    * (float)u)
                            - (float)((float)((float)v41 * (float)2.0) - (float)((float)v39 * (float)2.0)))
                    * (float)u)
            + (float)v41;
  }
  while ( v13 != 0 );
  v43 = v76;
  v44 = *(float *)v73.tangent;
  v45 = v77;
  v46 = v75;
  v47 = *(float *)v73.normal;
  v48 = *(float *)v73.color;
  v49 = (float)((float)(v77 - (float)(v85 * (float)2.0)) + v93);
  v50 = (float)-(float)((float)(v77 * (float)2.0) - (float)(v85 * (float)2.0));
  v51 = (float)((float)((float)((float)(v76 - (float)(v84 * (float)2.0)) + v92) * (float)v)
              - (float)((float)(v76 * (float)2.0) - (float)(v84 * (float)2.0)));
  v52 = (float)((float)((float)((float)(*(float *)v73.tangent - (float)(v80 * (float)2.0)) + v88) * (float)v)
              - (float)((float)(*(float *)v73.tangent * (float)2.0) - (float)(v80 * (float)2.0)));
  v54 = (float)((float)(*(float *)v73.color - (float)(v81 * (float)2.0)) + v89);
  v55 = (float)((float)((float)((float)(v75 - (float)(v83 * (float)2.0)) + v91) * (float)v)
              - (float)((float)(v75 * (float)2.0) - (float)(v83 * (float)2.0)));
  v56 = (float)((float)((float)((float)((float)((float)(v74 - (float)(v82 * (float)2.0)) + v90) * (float)v)
                              - (float)((float)(v74 * (float)2.0) - (float)(v82 * (float)2.0)))
                      * (float)v)
              + v74);
  v57 = (float)((float)((float)((float)(*(float *)v73.normal - (float)(v79 * (float)2.0)) + v87) * (float)v)
              - (float)((float)(*(float *)v73.normal * (float)2.0) - (float)(v79 * (float)2.0)));
  v53 = (float)-(float)((float)(*(float *)v73.color * (float)2.0) - (float)(v81 * (float)2.0));
  *v11 = (float)((float)((float)((float)((float)(v73.st.y - (float)(v78 * (float)2.0)) + v86) * (float)v)
                       - (float)((float)(v73.st.y * (float)2.0) - (float)(v78 * (float)2.0)))
               * (float)v)
       + v73.st.y;
  v11[3] = (float)((float)v51 * (float)v) + (float)v43;
  v11[2] = (float)((float)v52 * (float)v) + (float)v44;
  v58 = (float)((float)((float)v55 * (float)v) + (float)v46);
  v11[1] = (float)((float)v57 * (float)v) + (float)v47;
  v11[4] = (float)((float)((float)((float)v49 * (float)v) + (float)v50) * (float)v) + (float)v45;
  v59 = (float)((float)((float)((float)((float)v54 * (float)v) + (float)v53) * (float)v) + (float)v48);
  _FP4 = (float)((float)((float)((float)v59 * (float)v59)
                       + (float)((float)((float)v58 * (float)v58) + (float)((float)v56 * (float)v56)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f4, f5, f13 }
  v62 = __frsqrte(_FP2);
  v63 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v62
                                                                                      * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)((float)v58 * (float)v58) + (float)((float)v56 * (float)v56)))
                                                                                              * (float)0.5))
                                                                              * (float)v62)
                                                                      - (float)1.5)
                                                      * (float)v62)
                                              * (float)((float)((float)((float)v59 * (float)v59)
                                                              + (float)((float)((float)v58 * (float)v58)
                                                                      + (float)((float)v56 * (float)v56)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v62
                                                                              * (float)((float)((float)((float)v59 * (float)v59)
                                                                                              + (float)((float)((float)v58 * (float)v58) + (float)((float)v56 * (float)v56)))
                                                                                      * (float)0.5))
                                                                      * (float)v62)
                                                              - (float)1.5)
                                              * (float)v62))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v62
                                                      * (float)((float)((float)((float)v59 * (float)v59)
                                                                      + (float)((float)((float)v58 * (float)v58)
                                                                              + (float)((float)v56 * (float)v56)))
                                                              * (float)0.5))
                                              * (float)v62)
                                      - (float)1.5)
                      * (float)v62));
  v73.xyz.x = (float)((float)-(float)((float)((float)((float)v63
                                                    * (float)((float)((float)((float)v59 * (float)v59)
                                                                    + (float)((float)((float)v58 * (float)v58)
                                                                            + (float)((float)v56 * (float)v56)))
                                                            * (float)0.5))
                                            * (float)v63)
                                    - (float)1.5)
                    * (float)v63)
            * (float)v59;
  v73.xyz.y = (float)v56
            * (float)((float)-(float)((float)((float)((float)v63
                                                    * (float)((float)((float)((float)v59 * (float)v59)
                                                                    + (float)((float)((float)v58 * (float)v58)
                                                                            + (float)((float)v56 * (float)v56)))
                                                            * (float)0.5))
                                            * (float)v63)
                                    - (float)1.5)
                    * (float)v63);
  v73.xyz.z = (float)v58
            * (float)((float)-(float)((float)((float)((float)v63
                                                    * (float)((float)((float)((float)v59 * (float)v59)
                                                                    + (float)((float)((float)v58 * (float)v58)
                                                                            + (float)((float)v56 * (float)v56)))
                                                            * (float)0.5))
                                            * (float)v63)
                                    - (float)1.5)
                    * (float)v63);
  if ( (float)((float)((float)-(float)((float)((float)((float)v63
                                                     * (float)((float)((float)((float)v59 * (float)v59)
                                                                     + (float)((float)((float)v58 * (float)v58)
                                                                             + (float)((float)v56 * (float)v56)))
                                                             * (float)0.5))
                                             * (float)v63)
                                     - (float)1.5)
                     * (float)v63)
             * (float)((float)((float)v59 * (float)v59)
                     + (float)((float)((float)v58 * (float)v58) + (float)((float)v56 * (float)v56)))) > 0.0 )
  {
    _R11 = &v73;
    __asm { vspltisw128 v63, 0 }
    _R10 = &v73.xyz.y;
    _R9 = &v73.xyz.z;
    __asm { lvlx128   v62, r0, r11 }
    _R6 = &_vmx_3f8000003f8000003f8000003f800000;
    __asm
    {
      vrlimi128 v63, v62, 8, 0
      lvlx128   v61, r0, r10
      lvlx128   v60, r0, r9
    }
    _R4 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
    _R3 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
    __asm
    {
      vor128    v59, v95, v63
      lvx128    v63, r0, r6
    }
    _R11 = v11 + 5;
    _R10 = 1;
    __asm { lvx128    v0, r0, r4 }
    _R9 = 2;
    __asm
    {
      vrlimi128 v59, v61, 4, 3
      lvx128    v13, r0, r3
      vrlimi128 v59, v60, 2, 2
      vaddfp128 v12, v91, v63
      vmaddfp   v0, v12, v0, v13
      vcfpsxws128 v58, v0, 0
      vpkswss128 v57, v90, v58
      vpkshus128 v0, v89, v57
      stvebx    v0, 0, r11
      stvebx    v0, r11, r10
      stvebx    v0, r11, r9
    }
  }
}


// ========================================================================
// ?SampleSinglePatch@idSurface_Patch@@ABAXQAY02$$CBVidDrawVert@@HHHHHPAV2@@Z
// EA  : 0x82F22F18
// RVA : 0x00F22F18
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSurface_Patch::SampleSinglePatch(
        idSurface_Patch *this,
        const idDrawVert (*ctrl)[3],
        idDrawVert *baseCol,
        int baseRow,
        __int64 width,
        __int64 outVerts)
{
  int v10; // r26
  int v11; // r25
  int v12; // r29
  int v13; // r20
  signed int i; // r27
  int v15; // r30
  unsigned __int64 v16; // r10 OVERLAPPED
  int v17; // r11
  double v18; // fp11
  int v19; // r31
  double v20; // fp30
  int v21; // r11

  v10 = HIDWORD(width);
  v11 = width;
  v12 = HIDWORD(outVerts);
  v13 = outVerts;
  for ( i = 0; i <= v11; ++i )
  {
    v15 = 0;
    if ( v12 >= 0 )
    {
      v16 = __PAIR64__(i, v12);
      v17 = v11;
      v18 = (double)*(__int64 *)((char *)&width - 4);
      LODWORD(width) = (char *)baseCol + baseRow * v10 + i;
      v19 = 32 * width + v13;
      v20 = (float)((float)v18 / (float)*(__int64 *)((char *)&v16 - 4));
      do
      {
        v21 = v15;
        HIDWORD(width) = v19;
        idSurface_Patch::SampleSinglePatchPoint(
          this,
          ctrl,
          u: v20,
          v: (float)((float)*(__int64 *)((char *)&v16 - 4) / (float)__SPAIR64__(i, v12)),
          out: baseCol,
          a6: baseRow,
          a7: width);
        ++v15;
        v19 += 32 * v10;
      }
      while ( v15 <= v12 );
    }
  }
}


// ========================================================================
// ?PutOnCurve@idSurface_Patch@@AAAXXZ
// EA  : 0x82F23018
// RVA : 0x00F23018
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.cpp
// ========================================================================

void __fastcall idSurface_Patch::PutOnCurve(idSurface_Patch *this)
{
  int width; // r10
  int v3; // r29
  int height; // r11
  int i; // r30
  int j; // r29
  int k; // r30
  idDrawVert *v8; // r4
  const idDrawVert *v9; // r4
  idDrawVert v10; // [sp+50h] [-70h] BYREF
  idDrawVert v11; // [sp+70h] [-50h] BYREF

  width = this->width;
  v3 = 0;
  if ( width > 0 )
  {
    height = this->height;
    do
    {
      for ( i = 1; i < height; i += 2 )
      {
        idDrawVert::LerpAll(
          this: &v11,
          a: &this->verts.list[this->maxWidth * i + v3],
          b: &this->verts.list[(i - 1 + 2) * this->maxWidth + v3],
          f: 0.5);
        idDrawVert::LerpAll(
          this: &v10,
          a: &this->verts.list[this->maxWidth * i + v3],
          b: &this->verts.list[(i - 1) * this->maxWidth + v3],
          f: 0.5);
        idDrawVert::LerpAll(this: &this->verts.list[i * this->maxWidth + v3], a: &v11, b: &v10, f: 0.5);
        height = this->height;
      }
      width = this->width;
      ++v3;
    }
    while ( v3 < width );
  }
  for ( j = 0; j < this->height; ++j )
  {
    for ( k = 1; k < width; k += 2 )
    {
      v8 = &this->verts.list[j * this->maxWidth + k];
      idDrawVert::LerpAll(this: &v11, a: v8, b: v8 + 1, f: 0.5);
      v9 = &this->verts.list[j * this->maxWidth + k];
      idDrawVert::LerpAll(this: &v10, a: v9, b: v9 - 1, f: 0.5);
      idDrawVert::LerpAll(this: &this->verts.list[j * this->maxWidth + k], a: &v11, b: &v10, f: 0.5);
      width = this->width;
    }
  }
}


// ========================================================================
// ?GenerateIndexes@idSurface_Patch@@AAAXXZ
// EA  : 0x82F231D0
// RVA : 0x00F231D0
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.cpp
// ========================================================================

void __fastcall idSurface_Patch::GenerateIndexes(idSurface_Patch *this)
{
  int width; // r10
  idList<int,44> *p_indexes; // r31
  int v4; // r11
  int v5; // r29
  int size; // r11
  int v7; // r6
  int v8; // r5
  int v9; // r11
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r11
  int v14; // r8
  int v15; // r9

  width = this->width;
  p_indexes = &this->indexes;
  v4 = 6 * this->height;
  v5 = (v4 - 6) * (width - 1);
  if ( v5 <= this->indexes.size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->indexes,
                          newsize: (v4 - 6) * (width - 1)) != 0 )
  {
    size = p_indexes->size;
    if ( v5 < size )
      size = v5;
    p_indexes->num = size;
  }
  v7 = 0;
  v8 = 0;
  if ( this->width - 1 > 0 )
  {
    v9 = this->height - 1;
    do
    {
      v10 = 0;
      if ( v9 > 0 )
      {
        v11 = 4 * v7;
        do
        {
          v12 = this->width;
          v7 += 6;
          v13 = v12 * v10++ + v8;
          *(int *)((char *)p_indexes->list + v11) = v13;
          v14 = v12 + v13;
          v15 = v11 + 4;
          *(int *)((char *)p_indexes->list + v15) = v14 + 1;
          v15 += 4;
          *(int *)((char *)p_indexes->list + v15) = v13 + 1;
          v15 += 4;
          *(int *)((char *)p_indexes->list + v15) = v13;
          *(int *)((char *)p_indexes->list + v15 + 4) = v14;
          *(int *)((char *)p_indexes->list + v15 + 8) = v14 + 1;
          v11 = v15 + 12;
          v9 = this->height - 1;
        }
        while ( v10 < v9 );
      }
      ++v8;
    }
    while ( v8 < this->width - 1 );
  }
  idSurface::GenerateEdgeIndexes(this);
}


// ========================================================================
// ?SetSize@idSurface_Patch@@QAAXHH@Z
// EA  : 0x82F23308
// RVA : 0x00F23308
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.cpp
// ========================================================================

void __fastcall idSurface_Patch::SetSize(idSurface_Patch *this, int patchWidth, int patchHeight)
{
  if ( patchWidth < 1 || patchWidth > this->maxWidth )
  {
    idLib::FatalError(fmt: "idSurface_Patch::SetSize: invalid patchWidth");
  }
  else if ( patchHeight < 1 || patchHeight > this->maxHeight )
  {
    idLib::FatalError(fmt: "idSurface_Patch::SetSize: invalid patchHeight");
  }
  else
  {
    this->width = patchWidth;
    this->height = patchHeight;
    idList<idDrawVert,44>::SetNum(this: &this->verts, newNum: patchWidth * patchHeight);
  }
}


// ========================================================================
// ?ResizeExpanded@idSurface_Patch@@AAAXHH@Z
// EA  : 0x82F23358
// RVA : 0x00F23358
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.cpp
// ========================================================================

void __fastcall idSurface_Patch::ResizeExpanded(idSurface_Patch *this, int newHeight, int newWidth)
{
  int maxHeight; // r11
  int v7; // r4
  int v8; // r8
  int v9; // r6
  int maxWidth; // r11
  int v11; // r9
  unsigned int v12; // ctr
  int v13; // r7
  idDrawVert *v14; // r11
  idDrawVert *v15; // r10
  idDrawVert *v16; // r10
  idDrawVert *v17; // r7
  idDrawVert *v18; // r11
  int v19; // r7
  idDrawVert *v20; // r11
  idDrawVert *v21; // r10
  int v22; // r11
  idDrawVert *v23; // r11
  idDrawVert *v24; // r10
  int v25; // ctr
  idDrawVert *v26; // r11
  idDrawVert *v27; // r10

  maxHeight = this->maxHeight;
  if ( newHeight > maxHeight || newWidth > this->maxWidth )
  {
    v7 = newHeight * newWidth;
    if ( newHeight * newWidth > maxHeight * this->maxWidth )
      idList<idDrawVert,44>::SetNum(this: &this->verts, newNum: v7);
    v8 = this->maxHeight - 1;
    if ( v8 >= 0 )
    {
      v9 = v8 * newWidth;
      do
      {
        maxWidth = this->maxWidth;
        v11 = maxWidth - 1;
        if ( maxWidth - 1 >= 0 )
        {
          if ( maxWidth >= 4 )
          {
            v12 = (unsigned int)maxWidth >> 2;
            do
            {
              v13 = v9 + v11;
              v14 = &this->verts.list[v13];
              v15 = &this->verts.list[v8 * this->maxWidth + v11];
              v14->xyz.x = v15->xyz.x;
              v14->xyz.y = v15->xyz.y;
              v14->xyz.z = v15->xyz.z;
              v14->st.x = v15->st.x;
              v14->st.y = v15->st.y;
              v14->normal[0] = v15->normal[0];
              v14->normal[1] = v15->normal[1];
              v14->normal[2] = v15->normal[2];
              v14->normal[3] = v15->normal[3];
              v14->tangent[0] = v15->tangent[0];
              v14->tangent[1] = v15->tangent[1];
              v14->tangent[2] = v15->tangent[2];
              v14->tangent[3] = v15->tangent[3];
              v14->color[0] = v15->color[0];
              v14->color[1] = v15->color[1];
              v14->color[2] = v15->color[2];
              v14->color[3] = v15->color[3];
              v16 = &this->verts.list[v13];
              v17 = &this->verts.list[v8 * this->maxWidth + v11];
              v18 = v16 - 1;
              v18->xyz.x = v17[-1].xyz.x;
              v18->xyz.y = v17[-1].xyz.y;
              v18->xyz.z = v17[-1].xyz.z;
              v18->st.x = v17[-1].st.x;
              v18->st.y = v17[-1].st.y;
              v18->normal[0] = v17[-1].normal[0];
              v18->normal[1] = v17[-1].normal[1];
              v18->normal[2] = v17[-1].normal[2];
              v18->normal[3] = v17[-1].normal[3];
              v18->tangent[0] = v17[-1].tangent[0];
              v18->tangent[1] = v17[-1].tangent[1];
              v18->tangent[2] = v17[-1].tangent[2];
              v18->tangent[3] = v17[-1].tangent[3];
              v18->color[0] = v17[-1].color[0];
              v18->color[1] = v17[-1].color[1];
              v18->color[2] = v17[-1].color[2];
              LOBYTE(v16) = v17[-1].color[3];
              v19 = v9 - 3 + v11;
              v18->color[3] = (unsigned __int8)v16;
              v20 = &this->verts.list[v9 - 2 + v11];
              v21 = &this->verts.list[v8 * this->maxWidth - 2 + v11];
              v20->xyz.x = v21->xyz.x;
              v20->xyz.y = v21->xyz.y;
              v20->xyz.z = v21->xyz.z;
              v20->st.x = v21->st.x;
              v20->st.y = v21->st.y;
              v20->normal[0] = v21->normal[0];
              v20->normal[1] = v21->normal[1];
              v20->normal[2] = v21->normal[2];
              v20->normal[3] = v21->normal[3];
              v20->tangent[0] = v21->tangent[0];
              v20->tangent[1] = v21->tangent[1];
              v20->tangent[2] = v21->tangent[2];
              v20->tangent[3] = v21->tangent[3];
              v20->color[0] = v21->color[0];
              v20->color[1] = v21->color[1];
              v20->color[2] = v21->color[2];
              v20->color[3] = v21->color[3];
              v22 = v8 * this->maxWidth + v11;
              v11 -= 4;
              v24 = &this->verts.list[v22 - 3];
              v23 = &this->verts.list[v19];
              v23->xyz.x = v24->xyz.x;
              v23->xyz.y = v24->xyz.y;
              v23->xyz.z = v24->xyz.z;
              v23->st.x = v24->st.x;
              v23->st.y = v24->st.y;
              v23->normal[0] = v24->normal[0];
              v23->normal[1] = v24->normal[1];
              v23->normal[2] = v24->normal[2];
              v23->normal[3] = v24->normal[3];
              v23->tangent[0] = v24->tangent[0];
              v23->tangent[1] = v24->tangent[1];
              v23->tangent[2] = v24->tangent[2];
              v23->tangent[3] = v24->tangent[3];
              v23->color[0] = v24->color[0];
              v23->color[1] = v24->color[1];
              v23->color[2] = v24->color[2];
              v23->color[3] = v24->color[3];
              --v12;
            }
            while ( v12 != 0 );
          }
          if ( v11 >= 0 )
          {
            v25 = v11 + 1;
            do
            {
              v26 = &this->verts.list[v9 + v11];
              v27 = &this->verts.list[v8 * this->maxWidth + v11--];
              v26->xyz.x = v27->xyz.x;
              v26->xyz.y = v27->xyz.y;
              v26->xyz.z = v27->xyz.z;
              v26->st.x = v27->st.x;
              v26->st.y = v27->st.y;
              v26->normal[0] = v27->normal[0];
              v26->normal[1] = v27->normal[1];
              v26->normal[2] = v27->normal[2];
              v26->normal[3] = v27->normal[3];
              v26->tangent[0] = v27->tangent[0];
              v26->tangent[1] = v27->tangent[1];
              v26->tangent[2] = v27->tangent[2];
              v26->tangent[3] = v27->tangent[3];
              v26->color[0] = v27->color[0];
              v26->color[1] = v27->color[1];
              v26->color[2] = v27->color[2];
              v26->color[3] = v27->color[3];
              --v25;
            }
            while ( v25 != 0 );
          }
        }
        --v8;
        v9 -= newWidth;
      }
      while ( v8 >= 0 );
    }
    this->maxHeight = newHeight;
    this->maxWidth = newWidth;
  }
}


// ========================================================================
// ?Collapse@idSurface_Patch@@AAAXXZ
// EA  : 0x82F23788
// RVA : 0x00F23788
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.cpp
// ========================================================================

void __fastcall idSurface_Patch::Collapse(idSurface_Patch *this)
{
  int maxWidth; // r11
  int width; // r9
  int i; // r8
  int j; // r9
  idDrawVert *v6; // r11
  idDrawVert *v7; // r10
  int height; // r11
  int v9; // r10
  int v10; // r30
  int size; // r11

  if ( !this->expanded )
    idLib::FatalError(fmt: "idSurface_Patch::Collapse: patch not expanded");
  maxWidth = this->maxWidth;
  width = this->width;
  this->expanded = false;
  if ( width != maxWidth )
  {
    for ( i = 0; i < this->height; ++i )
    {
      for ( j = 0; j < this->width; v7->color[3] = v6->color[3] )
      {
        v6 = &this->verts.list[this->maxWidth * i + j];
        v7 = &this->verts.list[this->width * i + j++];
        v7->xyz.x = v6->xyz.x;
        v7->xyz.y = v6->xyz.y;
        v7->xyz.z = v6->xyz.z;
        v7->st.x = v6->st.x;
        v7->st.y = v6->st.y;
        v7->normal[0] = v6->normal[0];
        v7->normal[1] = v6->normal[1];
        v7->normal[2] = v6->normal[2];
        v7->normal[3] = v6->normal[3];
        v7->tangent[0] = v6->tangent[0];
        v7->tangent[1] = v6->tangent[1];
        v7->tangent[2] = v6->tangent[2];
        v7->tangent[3] = v6->tangent[3];
        v7->color[0] = v6->color[0];
        v7->color[1] = v6->color[1];
        v7->color[2] = v6->color[2];
      }
    }
  }
  height = this->height;
  v9 = this->width;
  v10 = height * v9;
  if ( height * v9 <= this->verts.size
    || (unsigned __int8)idList<idDrawVert,44>::Resize(this: &this->verts, newsize: height * v9) != 0 )
  {
    size = this->verts.size;
    if ( v10 < size )
      size = v10;
    this->verts.num = size;
  }
}


// ========================================================================
// ?Expand@idSurface_Patch@@AAAXXZ
// EA  : 0x82F23920
// RVA : 0x00F23920
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.cpp
// ========================================================================

void __fastcall idSurface_Patch::Expand(idSurface_Patch *this)
{
  int maxHeight; // r10
  int maxWidth; // r9
  int i; // r8
  int width; // r11
  int v6; // r9
  unsigned int v7; // ctr
  idDrawVert *v8; // r11
  idDrawVert *v9; // r10
  idDrawVert *v10; // r7
  idDrawVert *v11; // r11
  idDrawVert *v12; // r11
  idDrawVert *v13; // r10
  idDrawVert *v14; // r11
  idDrawVert *v15; // r10
  int v16; // ctr
  idDrawVert *v17; // r11
  idDrawVert *v18; // r10

  if ( this->expanded )
    idLib::FatalError(fmt: "idSurface_Patch::Expand: patch alread expanded");
  maxHeight = this->maxHeight;
  maxWidth = this->maxWidth;
  this->expanded = true;
  idList<idDrawVert,44>::SetNum(this: &this->verts, newNum: maxHeight * maxWidth);
  if ( this->width != this->maxWidth )
  {
    for ( i = this->height - 1; i >= 0; --i )
    {
      width = this->width;
      v6 = width - 1;
      if ( width - 1 >= 0 )
      {
        if ( width >= 4 )
        {
          v7 = (unsigned int)width >> 2;
          do
          {
            v8 = &this->verts.list[i * this->width + v6];
            v9 = &this->verts.list[i * this->maxWidth + v6];
            v9->xyz.x = v8->xyz.x;
            v9->xyz.y = v8->xyz.y;
            v9->xyz.z = v8->xyz.z;
            v9->st.x = v8->st.x;
            v9->st.y = v8->st.y;
            v9->normal[0] = v8->normal[0];
            v9->normal[1] = v8->normal[1];
            v9->normal[2] = v8->normal[2];
            v9->normal[3] = v8->normal[3];
            v9->tangent[0] = v8->tangent[0];
            v9->tangent[1] = v8->tangent[1];
            v9->tangent[2] = v8->tangent[2];
            v9->tangent[3] = v8->tangent[3];
            v9->color[0] = v8->color[0];
            v9->color[1] = v8->color[1];
            v9->color[2] = v8->color[2];
            v9->color[3] = v8->color[3];
            v10 = &this->verts.list[i * this->maxWidth + v6];
            v11 = &this->verts.list[i * this->width - 1 + v6];
            v10[-1].xyz.x = v11->xyz.x;
            v10[-1].xyz.y = v11->xyz.y;
            v10[-1].xyz.z = v11->xyz.z;
            v10[-1].st.x = v11->st.x;
            v10[-1].st.y = v11->st.y;
            v10[-1].normal[0] = v11->normal[0];
            v10[-1].normal[1] = v11->normal[1];
            v10[-1].normal[2] = v11->normal[2];
            v10[-1].normal[3] = v11->normal[3];
            v10[-1].tangent[0] = v11->tangent[0];
            v10[-1].tangent[1] = v11->tangent[1];
            v10[-1].tangent[2] = v11->tangent[2];
            v10[-1].tangent[3] = v11->tangent[3];
            v10[-1].color[0] = v11->color[0];
            v10[-1].color[1] = v11->color[1];
            v10[-1].color[2] = v11->color[2];
            v10[-1].color[3] = v11->color[3];
            v12 = &this->verts.list[i * this->width - 2 + v6];
            v13 = &this->verts.list[i * this->maxWidth - 2 + v6];
            v13->xyz.x = v12->xyz.x;
            v13->xyz.y = v12->xyz.y;
            v13->xyz.z = v12->xyz.z;
            v13->st.x = v12->st.x;
            v13->st.y = v12->st.y;
            v13->normal[0] = v12->normal[0];
            v13->normal[1] = v12->normal[1];
            v13->normal[2] = v12->normal[2];
            v13->normal[3] = v12->normal[3];
            v13->tangent[0] = v12->tangent[0];
            v13->tangent[1] = v12->tangent[1];
            v13->tangent[2] = v12->tangent[2];
            v13->tangent[3] = v12->tangent[3];
            v13->color[0] = v12->color[0];
            v13->color[1] = v12->color[1];
            v13->color[2] = v12->color[2];
            v13->color[3] = v12->color[3];
            v14 = &this->verts.list[i * this->width - 3 + v6];
            v15 = &this->verts.list[i * this->maxWidth - 3 + v6];
            v6 -= 4;
            v15->xyz.x = v14->xyz.x;
            v15->xyz.y = v14->xyz.y;
            v15->xyz.z = v14->xyz.z;
            v15->st.x = v14->st.x;
            v15->st.y = v14->st.y;
            v15->normal[0] = v14->normal[0];
            v15->normal[1] = v14->normal[1];
            v15->normal[2] = v14->normal[2];
            v15->normal[3] = v14->normal[3];
            v15->tangent[0] = v14->tangent[0];
            v15->tangent[1] = v14->tangent[1];
            v15->tangent[2] = v14->tangent[2];
            v15->tangent[3] = v14->tangent[3];
            v15->color[0] = v14->color[0];
            v15->color[1] = v14->color[1];
            v15->color[2] = v14->color[2];
            v15->color[3] = v14->color[3];
            --v7;
          }
          while ( v7 != 0 );
        }
        if ( v6 >= 0 )
        {
          v16 = v6 + 1;
          do
          {
            v17 = &this->verts.list[i * this->width + v6];
            v18 = &this->verts.list[i * this->maxWidth + v6--];
            v18->xyz.x = v17->xyz.x;
            v18->xyz.y = v17->xyz.y;
            v18->xyz.z = v17->xyz.z;
            v18->st.x = v17->st.x;
            v18->st.y = v17->st.y;
            v18->normal[0] = v17->normal[0];
            v18->normal[1] = v17->normal[1];
            v18->normal[2] = v17->normal[2];
            v18->normal[3] = v17->normal[3];
            v18->tangent[0] = v17->tangent[0];
            v18->tangent[1] = v17->tangent[1];
            v18->tangent[2] = v17->tangent[2];
            v18->tangent[3] = v17->tangent[3];
            v18->color[0] = v17->color[0];
            v18->color[1] = v17->color[1];
            v18->color[2] = v17->color[2];
            v18->color[3] = v17->color[3];
            --v16;
          }
          while ( v16 != 0 );
        }
      }
    }
  }
}


// ========================================================================
// ?SubdivideExplicit@idSurface_Patch@@QAAXHH_N0@Z
// EA  : 0x82F23D80
// RVA : 0x00F23D80
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.cpp
// ========================================================================

void __fastcall idSurface_Patch::SubdivideExplicit(
        idSurface_Patch *this,
        unsigned int horzSubdivisions,
        unsigned int vertSubdivisions,
        bool genNormals,
        bool removeLinear)
{
  int v9; // r23
  int v10; // r22
  int v11; // r30
  unsigned int v12; // r5
  char *v13; // r24
  idDrawVert *v14; // r26
  int v15; // r31
  int v16; // r28
  int v17; // r30
  int width; // r7
  idDrawVert *list; // r8
  int v20; // r9
  int v21; // ctr
  _BYTE *v22; // r11
  int v23; // r5
  idDrawVert *v24; // r10
  double v25; // fp0
  unsigned __int8 v26; // r24
  unsigned __int8 v27; // r23
  double y; // fp12
  unsigned __int8 v29; // r22
  double z; // fp11
  unsigned __int8 v31; // r21
  double x; // fp10
  unsigned __int8 v33; // r20
  double v34; // fp9
  unsigned __int8 v35; // r19
  unsigned __int8 v36; // r18
  unsigned __int8 v37; // r17
  unsigned __int8 v38; // r16
  unsigned __int8 v39; // r15
  unsigned __int8 v40; // r14
  float *v41; // r10
  double v42; // fp8
  double v43; // fp7
  double v44; // fp6
  double v45; // fp5
  char v46; // r24
  char v47; // r23
  char v48; // r22
  char v49; // r21
  char v50; // r20
  char v51; // r24
  char v52; // r23
  char v53; // r22
  char v54; // r21
  int v55; // r6
  idDrawVert *v56; // r10
  unsigned __int8 v57; // r24
  unsigned __int8 v58; // r23
  unsigned __int8 v59; // r22
  unsigned __int8 v60; // r21
  unsigned __int8 v61; // r20
  unsigned __int8 v62; // r19
  unsigned __int8 v63; // r18
  int size; // r11
  int v65; // r9
  float *v66; // r11
  int v67; // r3
  float *v68; // r10
  float *v69; // r10
  float *v70; // r10
  float *v71; // r10
  char v72; // r7
  int v73; // r11
  int v74; // ctr
  float *v75; // r10
  char v76; // r3
  idSurface_Patch *v77; // r3
  int v78; // [sp+54h] [-1DCh]
  int v79; // [sp+58h] [-1D8h]
  int v80; // [sp+5Ch] [-1D4h]
  char *v81; // [sp+64h] [-1CCh]
  _BYTE v82[449]; // [sp+6Fh] [-1C1h] BYREF

  v9 = (this->width - 1) / 2 * horzSubdivisions + 1;
  v80 = v9;
  v10 = (this->height - 1) / 2 * vertSubdivisions + 1;
  v11 = v10 * v9;
  v79 = v10;
  v78 = v10 * v9;
  v12 = 32 * v10 * v9;
  if ( (unsigned int)(v10 * v9) > 0x7FFFFFF )
    v12 = -1;
  v13 = (char *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                  size: v12,
                  tag: TAG_NEW,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v81 = v13;
  if ( genNormals )
    idSurface_Patch::GenerateNormals(this);
  v14 = nullptr;
  v15 = 0;
  if ( this->width > 2 )
  {
    do
    {
      v16 = 0;
      if ( this->height > 2 )
      {
        v17 = 2;
        do
        {
          width = this->width;
          list = this->verts.list;
          v20 = 0;
          v21 = 3;
          v22 = v82;
          do
          {
            v23 = 32 * (width * (v17 - 1) + v20 + v15);
            v24 = &list[(v17 - 2) * width + v20 + v15];
            v25 = *(float *)((char *)&list->xyz.x + v23);
            v26 = v24->normal[0];
            v27 = v24->normal[1];
            y = v24->xyz.y;
            v29 = v24->normal[2];
            z = v24->xyz.z;
            v31 = v24->normal[3];
            x = v24->st.x;
            v33 = v24->tangent[0];
            v34 = v24->st.y;
            v35 = v24->tangent[1];
            *(float *)(v22 + 1) = v24->xyz.x;
            v36 = v24->tangent[2];
            *(float *)(v22 + 5) = y;
            v37 = v24->tangent[3];
            *(float *)(v22 + 9) = z;
            v38 = v24->color[0];
            *(float *)(v22 + 13) = x;
            v39 = v24->color[1];
            *(float *)(v22 + 17) = v34;
            v40 = v24->color[2];
            *(float *)(v22 + 33) = v25;
            LOBYTE(v24) = v24->color[3];
            v22[21] = v26;
            v22[22] = v27;
            v22[23] = v29;
            v22[24] = v31;
            v22[32] = (_BYTE)v24;
            v41 = (float *)((char *)&list->xyz.x + v23);
            v42 = *(float *)((char *)&list->xyz.y + v23);
            LOBYTE(v23) = list->normal[v23];
            v22[25] = v33;
            v43 = v41[2];
            v22[26] = v35;
            v44 = v41[3];
            v22[27] = v36;
            v45 = v41[4];
            v22[28] = v37;
            v22[29] = v38;
            v22[30] = v39;
            v22[31] = v40;
            *(float *)(v22 + 37) = v42;
            v46 = *((_BYTE *)v41 + 21);
            *(float *)(v22 + 41) = v43;
            v47 = *((_BYTE *)v41 + 22);
            *(float *)(v22 + 45) = v44;
            v48 = *((_BYTE *)v41 + 23);
            *(float *)(v22 + 49) = v45;
            v49 = *((_BYTE *)v41 + 24);
            v22[53] = v23;
            v50 = *((_BYTE *)v41 + 25);
            v22[54] = v46;
            LOBYTE(v23) = *((_BYTE *)v41 + 26);
            v22[55] = v47;
            v51 = *((_BYTE *)v41 + 27);
            v22[56] = v48;
            v52 = *((_BYTE *)v41 + 28);
            v22[57] = v49;
            v53 = *((_BYTE *)v41 + 29);
            v54 = *((_BYTE *)v41 + 30);
            v22[58] = v50;
            v22[59] = v23;
            v22[60] = v51;
            v22[61] = v52;
            v22[62] = v53;
            LOBYTE(v41) = *((_BYTE *)v41 + 31);
            v22[63] = v54;
            v55 = width * v17 + v20 + v15;
            v22[64] = (_BYTE)v41;
            ++v20;
            v56 = &list[v55];
            LOBYTE(v23) = v56->normal[0];
            *(float *)(v22 + 65) = v56->xyz.x;
            LOBYTE(v55) = v56->normal[1];
            v57 = v56->normal[2];
            *(float *)(v22 + 69) = v56->xyz.y;
            v58 = v56->normal[3];
            v59 = v56->tangent[0];
            *(float *)(v22 + 73) = v56->xyz.z;
            v60 = v56->tangent[1];
            v61 = v56->tangent[2];
            *(float *)(v22 + 77) = v56->st.x;
            v62 = v56->tangent[3];
            v63 = v56->color[0];
            *(float *)(v22 + 81) = v56->st.y;
            v22[85] = v23;
            v22[86] = v55;
            v22[87] = v57;
            v22[88] = v58;
            LOBYTE(v23) = v56->color[1];
            v22[89] = v59;
            LOBYTE(v55) = v56->color[2];
            v22[90] = v60;
            LOBYTE(v56) = v56->color[3];
            v22[91] = v61;
            v22[92] = v62;
            v22[93] = v63;
            v22[94] = v23;
            v22[95] = v55;
            v22 += 96;
            *v22 = (_BYTE)v56;
            --v21;
          }
          while ( v21 != 0 );
          v13 = v81;
          v9 = v80;
          idSurface_Patch::SampleSinglePatch(
            this,
            ctrl: (const idDrawVert (*)[3])&v82[1],
            baseCol: v14,
            baseRow: v16,
            width: __SPAIR64__(v80, horzSubdivisions),
            outVerts: __SPAIR64__(vertSubdivisions, (unsigned int)v81));
          v17 += 2;
          v16 += vertSubdivisions;
        }
        while ( v17 < this->height );
        v11 = v78;
        v10 = v79;
      }
      v15 += 2;
      v14 = (idDrawVert *)((char *)v14 + horzSubdivisions);
    }
    while ( v15 + 2 < this->width );
  }
  if ( v11 <= this->verts.size || (unsigned __int8)idList<idDrawVert,44>::Resize(this: &this->verts, newsize: v11) != 0 )
  {
    size = this->verts.size;
    if ( v11 < size )
      size = v11;
    this->verts.num = size;
  }
  v65 = 0;
  if ( v11 >= 4 )
  {
    v66 = (float *)(v13 + 80);
    v67 = -80 - (_DWORD)v13;
    do
    {
      v68 = (float *)((char *)v66 + v67 + (unsigned int)this->verts.list);
      *v68 = *(v66 - 20);
      v68[1] = *(v66 - 19);
      v68[2] = *(v66 - 18);
      v68[3] = *(v66 - 17);
      v68[4] = *(v66 - 16);
      *((_BYTE *)v68 + 20) = *((_BYTE *)v66 - 60);
      *((_BYTE *)v68 + 21) = *((_BYTE *)v66 - 59);
      *((_BYTE *)v68 + 22) = *((_BYTE *)v66 - 58);
      *((_BYTE *)v68 + 23) = *((_BYTE *)v66 - 57);
      *((_BYTE *)v68 + 24) = *((_BYTE *)v66 - 56);
      *((_BYTE *)v68 + 25) = *((_BYTE *)v66 - 55);
      *((_BYTE *)v68 + 26) = *((_BYTE *)v66 - 54);
      *((_BYTE *)v68 + 27) = *((_BYTE *)v66 - 53);
      *((_BYTE *)v68 + 28) = *((_BYTE *)v66 - 52);
      *((_BYTE *)v68 + 29) = *((_BYTE *)v66 - 51);
      *((_BYTE *)v68 + 30) = *((_BYTE *)v66 - 50);
      *((_BYTE *)v68 + 31) = *((_BYTE *)v66 - 49);
      v69 = (float *)((char *)v66 + v67 + (unsigned int)this->verts.list + 32);
      *v69 = *(v66 - 12);
      v69[1] = *(v66 - 11);
      v69[2] = *(v66 - 10);
      v69[3] = *(v66 - 9);
      v69[4] = *(v66 - 8);
      *((_BYTE *)v69 + 20) = *((_BYTE *)v66 - 28);
      *((_BYTE *)v69 + 21) = *((_BYTE *)v66 - 27);
      *((_BYTE *)v69 + 22) = *((_BYTE *)v66 - 26);
      *((_BYTE *)v69 + 23) = *((_BYTE *)v66 - 25);
      *((_BYTE *)v69 + 24) = *((_BYTE *)v66 - 24);
      *((_BYTE *)v69 + 25) = *((_BYTE *)v66 - 23);
      *((_BYTE *)v69 + 26) = *((_BYTE *)v66 - 22);
      *((_BYTE *)v69 + 27) = *((_BYTE *)v66 - 21);
      *((_BYTE *)v69 + 28) = *((_BYTE *)v66 - 20);
      *((_BYTE *)v69 + 29) = *((_BYTE *)v66 - 19);
      *((_BYTE *)v69 + 30) = *((_BYTE *)v66 - 18);
      *((_BYTE *)v69 + 31) = *((_BYTE *)v66 - 17);
      v70 = (float *)((char *)v66 + (unsigned int)this->verts.list - (_DWORD)v13 - 16);
      *v70 = *(v66 - 4);
      v70[1] = *(v66 - 3);
      v70[2] = *(v66 - 2);
      v65 += 4;
      v70[3] = *(v66 - 1);
      v70[4] = *v66;
      *((_BYTE *)v70 + 20) = *((_BYTE *)v66 + 4);
      *((_BYTE *)v70 + 21) = *((_BYTE *)v66 + 5);
      *((_BYTE *)v70 + 22) = *((_BYTE *)v66 + 6);
      *((_BYTE *)v70 + 23) = *((_BYTE *)v66 + 7);
      *((_BYTE *)v70 + 24) = *((_BYTE *)v66 + 8);
      *((_BYTE *)v70 + 25) = *((_BYTE *)v66 + 9);
      *((_BYTE *)v70 + 26) = *((_BYTE *)v66 + 10);
      *((_BYTE *)v70 + 27) = *((_BYTE *)v66 + 11);
      *((_BYTE *)v70 + 28) = *((_BYTE *)v66 + 12);
      *((_BYTE *)v70 + 29) = *((_BYTE *)v66 + 13);
      *((_BYTE *)v70 + 30) = *((_BYTE *)v66 + 14);
      *((_BYTE *)v70 + 31) = *((_BYTE *)v66 + 15);
      v71 = (float *)((char *)v66 + 16 - (_DWORD)v13 + (unsigned int)this->verts.list);
      *v71 = v66[4];
      v71[1] = v66[5];
      v71[2] = v66[6];
      v71[3] = v66[7];
      v71[4] = v66[8];
      *((_BYTE *)v71 + 20) = *((_BYTE *)v66 + 36);
      *((_BYTE *)v71 + 21) = *((_BYTE *)v66 + 37);
      *((_BYTE *)v71 + 22) = *((_BYTE *)v66 + 38);
      *((_BYTE *)v71 + 23) = *((_BYTE *)v66 + 39);
      *((_BYTE *)v71 + 24) = *((_BYTE *)v66 + 40);
      *((_BYTE *)v71 + 25) = *((_BYTE *)v66 + 41);
      *((_BYTE *)v71 + 26) = *((_BYTE *)v66 + 42);
      *((_BYTE *)v71 + 27) = *((_BYTE *)v66 + 43);
      *((_BYTE *)v71 + 28) = *((_BYTE *)v66 + 44);
      *((_BYTE *)v71 + 29) = *((_BYTE *)v66 + 45);
      *((_BYTE *)v71 + 30) = *((_BYTE *)v66 + 46);
      v72 = *((_BYTE *)v66 + 47);
      v66 += 32;
      *((_BYTE *)v71 + 31) = v72;
    }
    while ( v65 < v11 - 3 );
  }
  if ( v65 < v11 )
  {
    v73 = (int)&v13[32 * v65 + 4];
    v74 = v11 - v65;
    do
    {
      v75 = (float *)((char *)&this->verts.list->xyz.x + v73 + -4 - (_DWORD)v13);
      *v75 = *(float *)(v73 - 4);
      v75[1] = *(float *)v73;
      v75[2] = *(float *)(v73 + 4);
      v75[3] = *(float *)(v73 + 8);
      v75[4] = *(float *)(v73 + 12);
      *((_BYTE *)v75 + 20) = *(_BYTE *)(v73 + 16);
      *((_BYTE *)v75 + 21) = *(_BYTE *)(v73 + 17);
      *((_BYTE *)v75 + 22) = *(_BYTE *)(v73 + 18);
      *((_BYTE *)v75 + 23) = *(_BYTE *)(v73 + 19);
      *((_BYTE *)v75 + 24) = *(_BYTE *)(v73 + 20);
      *((_BYTE *)v75 + 25) = *(_BYTE *)(v73 + 21);
      *((_BYTE *)v75 + 26) = *(_BYTE *)(v73 + 22);
      *((_BYTE *)v75 + 27) = *(_BYTE *)(v73 + 23);
      *((_BYTE *)v75 + 28) = *(_BYTE *)(v73 + 24);
      *((_BYTE *)v75 + 29) = *(_BYTE *)(v73 + 25);
      *((_BYTE *)v75 + 30) = *(_BYTE *)(v73 + 26);
      v76 = *(_BYTE *)(v73 + 27);
      v73 += 32;
      *((_BYTE *)v75 + 31) = v76;
      --v74;
    }
    while ( v74 != 0 );
  }
  idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
  this->maxWidth = v9;
  this->width = v9;
  this->maxHeight = v10;
  this->height = v10;
  this->expanded = false;
  if ( removeLinear )
  {
    idSurface_Patch::Expand(this);
    idSurface_Patch::RemoveLinearColumnsRows(this);
    idSurface_Patch::Collapse(this: v77);
  }
  idSurface_Patch::GenerateIndexes(this);
}


// ========================================================================
// ?Subdivide@idSurface_Patch@@QAAXMMM_N@Z
// EA  : 0x82F244A0
// RVA : 0x00F244A0
// PDB : w:\tech5\shared\idlib\geometry\surface_patch.cpp
// ========================================================================

void __fastcall idSurface_Patch::Subdivide(
        idSurface_Patch *this,
        double maxHorizontalError,
        double maxVerticalError,
        double maxLength,
        bool genNormals,
        int a6,
        int a7,
        char a8)
{
  double v12; // fp26
  int v13; // r29
  int v14; // r28
  int height; // r7
  int v16; // r8
  idDrawVert *list; // r11
  int v18; // r9
  int v19; // r4
  int v20; // r3
  int v21; // r5
  int v22; // r30
  int v23; // r27
  int v24; // r9
  int v25; // r6
  double v26; // fp8
  double v27; // fp11
  double v28; // fp10
  double v29; // fp9
  double v30; // fp0
  double v31; // fp13
  double v32; // fp12
  double v33; // fp8
  idDrawVert *v34; // r10
  double v35; // fp13
  double v36; // fp11
  int maxWidth; // r11
  int v38; // r30
  int v39; // r10
  idDrawVert *v40; // r4
  int v41; // r9
  int v42; // r11
  int v43; // r8
  idDrawVert *v44; // r11
  idDrawVert *v45; // r10
  int v46; // r11
  idDrawVert *v47; // r8
  idDrawVert *v48; // r11
  int v49; // r11
  int v50; // r8
  idDrawVert *v51; // r11
  idDrawVert *v52; // r10
  int v53; // r11
  int v54; // r8
  idDrawVert *v55; // r11
  idDrawVert *v56; // r10
  int v57; // ctr
  int v58; // r11
  int v59; // r8
  idDrawVert *v60; // r11
  idDrawVert *v61; // r10
  double y; // fp13
  unsigned __int8 v63; // r8
  unsigned __int8 v64; // r7
  double z; // fp12
  unsigned __int8 v66; // r6
  double x; // fp11
  unsigned __int8 v68; // r5
  double v69; // fp10
  unsigned __int8 v70; // r4
  double v71; // fp9
  unsigned __int8 v72; // r3
  double v73; // fp8
  unsigned __int8 v74; // r28
  double v75; // fp7
  unsigned __int8 v76; // r27
  double v77; // fp6
  unsigned __int8 v78; // r26
  double v79; // fp5
  unsigned __int8 v80; // r25
  unsigned __int8 v81; // r24
  unsigned __int8 v82; // r9
  unsigned __int8 v83; // r23
  unsigned __int8 v84; // r22
  unsigned __int8 v85; // r21
  unsigned __int8 v86; // r20
  idDrawVert *v87; // r11
  unsigned __int8 v88; // r10
  unsigned __int8 v89; // r19
  unsigned __int8 v90; // r18
  unsigned __int8 v91; // r17
  unsigned __int8 v92; // r16
  unsigned __int8 v93; // r15
  unsigned __int8 v94; // r14
  unsigned __int8 v95; // r7
  idDrawVert *v96; // r11
  double v97; // fp4
  double v98; // fp3
  unsigned __int8 v99; // r5
  double v100; // fp2
  unsigned __int8 v101; // r4
  double v102; // fp1
  unsigned __int8 v103; // r3
  double v104; // fp0
  unsigned __int8 v105; // r9
  unsigned __int8 v106; // r8
  unsigned __int8 v107; // r7
  unsigned __int8 v108; // r6
  unsigned __int8 v109; // r28
  unsigned __int8 v110; // r27
  unsigned __int8 v111; // r26
  unsigned __int8 v112; // r25
  unsigned __int8 v113; // r24
  int v114; // r11
  idDrawVert *v115; // r11
  int v116; // r26
  int v117; // r27
  int v118; // r29
  int width; // r3
  int v120; // r10
  idDrawVert *v121; // r11
  int v122; // r8
  int v123; // r30
  int v124; // r6
  int v125; // r8
  int v126; // r6
  idDrawVert *v127; // r7
  int v128; // r4
  int v129; // r30
  double v130; // fp6
  int v131; // r6
  idDrawVert *v132; // r8
  double v133; // fp0
  double v134; // fp9
  double v135; // fp12
  double v136; // fp10
  double v137; // fp11
  double v138; // fp13
  double v139; // fp8
  idDrawVert *v140; // r9
  double v141; // fp13
  double v142; // fp9
  int maxHeight; // r11
  int v144; // r30
  int v145; // r10
  int v146; // r28
  int v147; // r8
  int v148; // r9
  int v149; // r11
  int v150; // r3
  idDrawVert *v151; // r11
  idDrawVert *v152; // r10
  int v153; // r11
  int v154; // r3
  idDrawVert *v155; // r11
  idDrawVert *v156; // r10
  int v157; // r11
  int v158; // r5
  idDrawVert *v159; // r11
  idDrawVert *v160; // r10
  int v161; // r3
  int v162; // r7
  int v163; // r11
  idDrawVert *v164; // r11
  idDrawVert *v165; // r10
  int v166; // ctr
  int v167; // r11
  int v168; // r6
  idDrawVert *v169; // r11
  idDrawVert *v170; // r10
  double v171; // fp13
  unsigned __int8 v172; // r9
  unsigned __int8 v173; // r8
  double v174; // fp12
  unsigned __int8 v175; // r7
  double v176; // fp11
  unsigned __int8 v177; // r6
  double v178; // fp10
  unsigned __int8 v179; // r5
  double v180; // fp9
  unsigned __int8 v181; // r4
  double v182; // fp8
  unsigned __int8 v183; // r3
  double v184; // fp7
  unsigned __int8 v185; // r28
  double v186; // fp6
  unsigned __int8 v187; // r26
  double v188; // fp5
  unsigned __int8 v189; // r24
  unsigned __int8 v190; // r23
  unsigned __int8 v191; // r25
  unsigned __int8 v192; // r22
  idDrawVert *v193; // r11
  unsigned __int8 v194; // r10
  unsigned __int8 v195; // r21
  unsigned __int8 v196; // r20
  unsigned __int8 v197; // r19
  unsigned __int8 v198; // r18
  unsigned __int8 v199; // r17
  unsigned __int8 v200; // r16
  unsigned __int8 v201; // r15
  unsigned __int8 v202; // r14
  unsigned __int8 v203; // r9
  unsigned __int8 v204; // r8
  idDrawVert *v205; // r11
  double v206; // fp4
  double v207; // fp3
  double v208; // fp2
  unsigned __int8 v209; // r4
  double v210; // fp1
  unsigned __int8 v211; // r3
  unsigned __int8 v212; // r9
  double v213; // fp0
  unsigned __int8 v214; // r8
  unsigned __int8 v215; // r7
  unsigned __int8 v216; // r6
  unsigned __int8 v217; // r5
  unsigned __int8 v218; // r25
  unsigned __int8 v219; // r24
  unsigned __int8 v220; // r23
  unsigned __int8 v221; // r22
  unsigned __int8 v222; // r21
  int v223; // r11
  idDrawVert *v224; // r11
  idSurface_Patch *v225; // r3
  int v226; // [sp+54h] [-15Ch]
  int v227; // [sp+54h] [-15Ch]
  int v228; // [sp+58h] [-158h]
  idDrawVert v229; // [sp+60h] [-150h] BYREF
  idDrawVert v230; // [sp+80h] [-130h] BYREF
  idDrawVert v231[3]; // [sp+A0h] [-110h] BYREF

  if ( a8 != 0 )
    idSurface_Patch::GenerateNormals(this);
  v12 = (float)((float)maxLength * (float)maxLength);
  idSurface_Patch::Expand(this);
  v13 = 0;
  if ( this->width > 2 )
  {
    v14 = 2;
    v226 = 2;
    do
    {
      height = this->height;
      v16 = 0;
      if ( height > 0 )
      {
        list = this->verts.list;
        do
        {
          v18 = this->maxWidth * v16 + v13;
          v19 = 4 * (8 * v18 + 9);
          v20 = 4 * (8 * v18 + 17);
          v21 = 4 * (8 * v18 + 8);
          v22 = 4 * (8 * v18 + 10);
          v23 = 4 * (8 * v18 + 18);
          v25 = 8 * v18 + 2;
          v26 = (float)((float)(*(float *)((char *)&list->xyz.x + v21) * (float)2.0) + list[v18 + 2].xyz.x);
          v27 = (float)(list[v18 + 2].xyz.x - *(float *)((char *)&list->xyz.x + v21));
          v24 = v18;
          v33 = (float)((float)((float)v26 + list[v24].xyz.x) * (float)0.25);
          if ( maxLength > 0.0 )
          {
            v32 = (float)(*(float *)((char *)&list->xyz.x + v22) - *(&list->xyz.x + v25));
            v31 = (float)(*(float *)((char *)&list->xyz.x + v19) - list[v24].xyz.y);
            v30 = (float)(*(float *)((char *)&list->xyz.x + v21) - list[v24].xyz.x);
            if ( (float)((float)((float)v30 * (float)v30)
                       + (float)((float)((float)v31 * (float)v31) + (float)((float)v32 * (float)v32))) > v12 )
              break;
            v28 = (float)(*(float *)((char *)&list->xyz.x + v20) - *(float *)((char *)&list->xyz.x + v19));
            v29 = (float)(*(float *)((char *)&list->xyz.x + v23) - *(float *)((char *)&list->xyz.x + v22));
            if ( (float)((float)((float)v27 * (float)v27)
                       + (float)((float)((float)v28 * (float)v28) + (float)((float)v29 * (float)v29))) > v12 )
              break;
          }
          v34 = &this->verts.list[this->maxWidth * v16 + 1 + v13];
          v35 = (float)(v34->xyz.y
                      - (float)((float)((float)((float)(*(float *)((char *)&list->xyz.x + v19) * (float)2.0)
                                              + *(float *)((char *)&list->xyz.x + v20))
                                      + list[v24].xyz.y)
                              * (float)0.25));
          v36 = (float)(v34->xyz.z
                      - (float)((float)((float)((float)(*(float *)((char *)&list->xyz.x + v22) * (float)2.0)
                                              + *(float *)((char *)&list->xyz.x + v23))
                                      + *(&list->xyz.x + v25))
                              * (float)0.25));
          if ( (float)((float)((float)(v34->xyz.x - (float)v33) * (float)(v34->xyz.x - (float)v33))
                     + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) > (double)(float)((float)maxHorizontalError * (float)maxHorizontalError) )
            break;
          ++v16;
        }
        while ( v16 < this->height );
      }
      if ( v16 != height )
      {
        maxWidth = this->maxWidth;
        if ( this->width + 2 >= maxWidth )
          idSurface_Patch::ResizeExpanded(this, newHeight: this->maxHeight, newWidth: maxWidth + 4);
        v38 = 0;
        v39 = this->height;
        this->width += 2;
        if ( v39 > 0 )
        {
          do
          {
            v40 = &this->verts.list[this->maxWidth * v38 + v13];
            idDrawVert::LerpAll(this: &v229, a: v40, b: v40 + 1, f: 0.5);
            idDrawVert::LerpAll(
              this: &v230,
              a: &this->verts.list[this->maxWidth * v38 + 1 + v13],
              b: &this->verts.list[this->maxWidth * v38 + 2 + v13],
              f: 0.5);
            idDrawVert::LerpAll(this: v231, a: &v229, b: &v230, f: 0.5);
            v41 = this->width - 1;
            if ( v41 > v13 + 3 )
            {
              if ( v41 - (v13 + 3) >= 4 )
              {
                do
                {
                  v42 = this->maxWidth * v38 + v41;
                  v43 = v42 - 2;
                  v44 = &this->verts.list[v42];
                  v45 = &this->verts.list[v43];
                  v44->xyz.x = v45->xyz.x;
                  v44->xyz.y = v45->xyz.y;
                  v44->xyz.z = v45->xyz.z;
                  v44->st.x = v45->st.x;
                  v44->st.y = v45->st.y;
                  v44->normal[0] = v45->normal[0];
                  v44->normal[1] = v45->normal[1];
                  v44->normal[2] = v45->normal[2];
                  v44->normal[3] = v45->normal[3];
                  v44->tangent[0] = v45->tangent[0];
                  v44->tangent[1] = v45->tangent[1];
                  v44->tangent[2] = v45->tangent[2];
                  v44->tangent[3] = v45->tangent[3];
                  v44->color[0] = v45->color[0];
                  v44->color[1] = v45->color[1];
                  v44->color[2] = v45->color[2];
                  v44->color[3] = v45->color[3];
                  v46 = this->maxWidth * v38 + v41;
                  v47 = &this->verts.list[v46];
                  v48 = &this->verts.list[v46 - 3];
                  v47[-1].xyz.x = v48->xyz.x;
                  v47[-1].xyz.y = v48->xyz.y;
                  v47[-1].xyz.z = v48->xyz.z;
                  v47[-1].st.x = v48->st.x;
                  v47[-1].st.y = v48->st.y;
                  v47[-1].normal[0] = v48->normal[0];
                  v47[-1].normal[1] = v48->normal[1];
                  v47[-1].normal[2] = v48->normal[2];
                  v47[-1].normal[3] = v48->normal[3];
                  v47[-1].tangent[0] = v48->tangent[0];
                  v47[-1].tangent[1] = v48->tangent[1];
                  v47[-1].tangent[2] = v48->tangent[2];
                  v47[-1].tangent[3] = v48->tangent[3];
                  v47[-1].color[0] = v48->color[0];
                  v47[-1].color[1] = v48->color[1];
                  v47[-1].color[2] = v48->color[2];
                  v47[-1].color[3] = v48->color[3];
                  v49 = this->maxWidth * v38 + v41;
                  v50 = v49 - 2;
                  v51 = &this->verts.list[v49 - 4];
                  v52 = &this->verts.list[v50];
                  v52->xyz.x = v51->xyz.x;
                  v52->xyz.y = v51->xyz.y;
                  v52->xyz.z = v51->xyz.z;
                  v52->st.x = v51->st.x;
                  v52->st.y = v51->st.y;
                  v52->normal[0] = v51->normal[0];
                  v52->normal[1] = v51->normal[1];
                  v52->normal[2] = v51->normal[2];
                  v52->normal[3] = v51->normal[3];
                  v52->tangent[0] = v51->tangent[0];
                  v52->tangent[1] = v51->tangent[1];
                  v52->tangent[2] = v51->tangent[2];
                  v52->tangent[3] = v51->tangent[3];
                  v52->color[0] = v51->color[0];
                  v52->color[1] = v51->color[1];
                  v52->color[2] = v51->color[2];
                  v52->color[3] = v51->color[3];
                  v53 = this->maxWidth * v38 + v41;
                  v41 -= 4;
                  v54 = v53 - 3;
                  v55 = &this->verts.list[v53 - 5];
                  v56 = &this->verts.list[v54];
                  v56->xyz.x = v55->xyz.x;
                  v56->xyz.y = v55->xyz.y;
                  v56->xyz.z = v55->xyz.z;
                  v56->st.x = v55->st.x;
                  v56->st.y = v55->st.y;
                  v56->normal[0] = v55->normal[0];
                  v56->normal[1] = v55->normal[1];
                  v56->normal[2] = v55->normal[2];
                  v56->normal[3] = v55->normal[3];
                  v56->tangent[0] = v55->tangent[0];
                  v56->tangent[1] = v55->tangent[1];
                  v56->tangent[2] = v55->tangent[2];
                  v56->tangent[3] = v55->tangent[3];
                  v56->color[0] = v55->color[0];
                  v56->color[1] = v55->color[1];
                  v56->color[2] = v55->color[2];
                  v56->color[3] = v55->color[3];
                }
                while ( v41 > v13 + 6 );
              }
              if ( v41 > v13 + 3 )
              {
                v57 = v41 - (v13 + 3);
                do
                {
                  v58 = this->maxWidth * v38 + v41--;
                  v59 = v58 - 2;
                  v60 = &this->verts.list[v58];
                  v61 = &this->verts.list[v59];
                  v60->xyz.x = v61->xyz.x;
                  v60->xyz.y = v61->xyz.y;
                  v60->xyz.z = v61->xyz.z;
                  v60->st.x = v61->st.x;
                  v60->st.y = v61->st.y;
                  v60->normal[0] = v61->normal[0];
                  v60->normal[1] = v61->normal[1];
                  v60->normal[2] = v61->normal[2];
                  v60->normal[3] = v61->normal[3];
                  v60->tangent[0] = v61->tangent[0];
                  v60->tangent[1] = v61->tangent[1];
                  v60->tangent[2] = v61->tangent[2];
                  v60->tangent[3] = v61->tangent[3];
                  v60->color[0] = v61->color[0];
                  v60->color[1] = v61->color[1];
                  v60->color[2] = v61->color[2];
                  v60->color[3] = v61->color[3];
                  --v57;
                }
                while ( v57 != 0 );
              }
            }
            y = v229.xyz.y;
            v63 = v229.normal[3];
            v64 = v229.tangent[1];
            z = v229.xyz.z;
            v66 = v229.tangent[2];
            x = v229.st.x;
            v68 = v229.color[1];
            v69 = v229.st.y;
            v70 = v229.tangent[3];
            v71 = v231[0].xyz.x;
            v72 = v229.color[3];
            v73 = v231[0].xyz.y;
            v74 = v229.normal[1];
            v75 = v231[0].xyz.z;
            v76 = v229.color[2];
            v77 = v231[0].st.x;
            v78 = v229.normal[2];
            v79 = v231[0].st.y;
            v80 = v229.tangent[0];
            v81 = v229.color[0];
            v82 = v229.normal[0];
            v83 = v231[0].normal[0];
            v84 = v231[0].normal[1];
            v85 = v231[0].normal[2];
            v86 = v231[0].normal[3];
            v87 = &this->verts.list[this->maxWidth * v38 + 1 + v13];
            v87->xyz.x = v229.xyz.x;
            v87->xyz.y = y;
            v88 = v231[0].color[2];
            v87->xyz.z = z;
            v89 = v231[0].tangent[0];
            v90 = v231[0].tangent[1];
            v91 = v231[0].tangent[2];
            v87->st.x = x;
            v92 = v231[0].tangent[3];
            v87->st.y = v69;
            v87->normal[3] = v63;
            v87->tangent[1] = v64;
            v87->tangent[2] = v66;
            v87->color[1] = v68;
            v87->tangent[3] = v70;
            v87->color[3] = v72;
            v87->normal[1] = v74;
            v87->color[2] = v76;
            v87->normal[2] = v78;
            v87->tangent[0] = v80;
            v87->color[0] = v81;
            v87->normal[0] = v82;
            v93 = v231[0].color[0];
            v94 = v231[0].color[1];
            v95 = v231[0].color[3];
            v96 = &this->verts.list[this->maxWidth * v38 + 2 + v13];
            v96->xyz.x = v71;
            v96->xyz.y = v73;
            v96->xyz.z = v75;
            v96->st.x = v77;
            v96->st.y = v79;
            v96->normal[0] = v83;
            v96->normal[1] = v84;
            v96->normal[2] = v85;
            v96->normal[3] = v86;
            v96->tangent[0] = v89;
            v96->tangent[1] = v90;
            v96->tangent[2] = v91;
            v96->tangent[3] = v92;
            v96->color[0] = v93;
            v96->color[1] = v94;
            v97 = v230.xyz.x;
            v96->color[3] = v95;
            v98 = v230.xyz.y;
            v99 = v230.normal[1];
            v100 = v230.xyz.z;
            v101 = v230.normal[2];
            v102 = v230.st.x;
            v103 = v230.normal[3];
            v104 = v230.st.y;
            v96->color[2] = v88;
            v105 = v230.tangent[0];
            v106 = v230.tangent[1];
            v107 = v230.tangent[2];
            v108 = v230.tangent[3];
            v109 = v230.color[0];
            v110 = v230.color[1];
            v111 = v230.color[2];
            v112 = v230.color[3];
            v113 = v230.normal[0];
            v114 = this->maxWidth * v38++ + v13;
            v115 = &this->verts.list[v114 + 3];
            v115->xyz.x = v97;
            v115->xyz.y = v98;
            v115->xyz.z = v100;
            v115->st.x = v102;
            v115->st.y = v104;
            v115->normal[1] = v99;
            v115->normal[2] = v101;
            v115->normal[3] = v103;
            v115->tangent[0] = v105;
            v115->tangent[1] = v106;
            v115->tangent[2] = v107;
            v115->tangent[3] = v108;
            v115->color[0] = v109;
            v115->color[1] = v110;
            v115->color[2] = v111;
            v115->color[3] = v112;
            v115->normal[0] = v113;
          }
          while ( v38 < this->height );
          v14 = v226;
        }
        v13 -= 2;
        v14 -= 2;
      }
      v14 += 2;
      v13 += 2;
      v226 = v14;
    }
    while ( v14 < this->width );
  }
  v116 = 0;
  v228 = 0;
  if ( this->height > 2 )
  {
    v117 = 2;
    v118 = 1;
    v227 = 2;
    do
    {
      width = this->width;
      v120 = 0;
      if ( width > 0 )
      {
        v121 = this->verts.list;
        do
        {
          v122 = this->maxWidth;
          v123 = v122 * v116 + v120;
          v124 = v118 * v122 + v120;
          v125 = v117 * v122 + v120;
          v128 = 4 * (8 * v124 + 2);
          v130 = v121[v124].xyz.y;
          v133 = (float)(v121[v124].xyz.x - v121[v123].xyz.x);
          v137 = (float)(v121[v125].xyz.x - v121[v124].xyz.x);
          v139 = (float)((float)((float)((float)(v121[v124].xyz.x * (float)2.0) + v121[v123].xyz.x) + v121[v125].xyz.x)
                       * (float)0.25);
          v126 = v123;
          v127 = &v121[v125];
          v129 = 4 * (v125 * 8 + 2);
          v132 = &v121[v126];
          v131 = v126 * 8 + 2;
          if ( maxLength > 0.0 )
          {
            v135 = (float)(*(float *)((char *)&v121->xyz.x + v128) - *(&v121->xyz.x + v131));
            v138 = (float)((float)v130 - v132->xyz.y);
            if ( (float)((float)((float)v133 * (float)v133)
                       + (float)((float)((float)v138 * (float)v138) + (float)((float)v135 * (float)v135))) > v12 )
              break;
            v136 = (float)(v127->xyz.y - (float)v130);
            v134 = (float)(*(float *)((char *)&v121->xyz.x + v129) - *(float *)((char *)&v121->xyz.x + v128));
            if ( (float)((float)((float)v137 * (float)v137)
                       + (float)((float)((float)v136 * (float)v136) + (float)((float)v134 * (float)v134))) > v12 )
              break;
          }
          v140 = &this->verts.list[this->maxWidth * v118 + v120];
          v141 = (float)(v140->xyz.z
                       - (float)((float)((float)((float)(*(float *)((char *)&v121->xyz.x + v128) * (float)2.0)
                                               + *(float *)((char *)&v121->xyz.x + v129))
                                       + *(&v121->xyz.x + v131))
                               * (float)0.25));
          v142 = (float)(v140->xyz.y
                       - (float)((float)((float)((float)((float)v130 * (float)2.0) + v127->xyz.y) + v132->xyz.y)
                               * (float)0.25));
          if ( (float)((float)((float)v142 * (float)v142)
                     + (float)((float)((float)(v140->xyz.x - (float)v139) * (float)(v140->xyz.x - (float)v139))
                             + (float)((float)v141 * (float)v141))) > (double)(float)((float)maxVerticalError
                                                                                    * (float)maxVerticalError) )
            break;
          ++v120;
        }
        while ( v120 < this->width );
      }
      if ( v120 != width )
      {
        maxHeight = this->maxHeight;
        if ( this->height + 2 >= maxHeight )
          idSurface_Patch::ResizeExpanded(this, newHeight: maxHeight + 4, newWidth: this->maxWidth);
        v144 = 0;
        v145 = this->width;
        this->height += 2;
        if ( v145 > 0 )
        {
          v146 = v116 + 3;
          do
          {
            idDrawVert::LerpAll(
              this: &v229,
              a: &this->verts.list[this->maxWidth * v116 + v144],
              b: &this->verts.list[this->maxWidth * v118 + v144],
              f: 0.5);
            idDrawVert::LerpAll(
              this: &v230,
              a: &this->verts.list[this->maxWidth * v118 + v144],
              b: &this->verts.list[this->maxWidth * v117 + v144],
              f: 0.5);
            idDrawVert::LerpAll(this: v231, a: &v229, b: &v230, f: 0.5);
            v147 = this->height - 1;
            if ( v147 > v146 )
            {
              if ( v147 - v146 >= 4 )
              {
                v148 = this->height - 3;
                do
                {
                  v149 = this->maxWidth;
                  v150 = v149 * v147 + v144;
                  v151 = &this->verts.list[v149 * v148 + v144];
                  v152 = &this->verts.list[v150];
                  v152->xyz.x = v151->xyz.x;
                  v152->xyz.y = v151->xyz.y;
                  v152->xyz.z = v151->xyz.z;
                  v152->st.x = v151->st.x;
                  v152->st.y = v151->st.y;
                  v152->normal[0] = v151->normal[0];
                  v152->normal[1] = v151->normal[1];
                  v152->normal[2] = v151->normal[2];
                  v152->normal[3] = v151->normal[3];
                  v152->tangent[0] = v151->tangent[0];
                  v152->tangent[1] = v151->tangent[1];
                  v152->tangent[2] = v151->tangent[2];
                  v152->tangent[3] = v151->tangent[3];
                  v152->color[0] = v151->color[0];
                  v152->color[1] = v151->color[1];
                  v152->color[2] = v151->color[2];
                  v152->color[3] = v151->color[3];
                  v153 = this->maxWidth;
                  v154 = (v148 - 2 + 3) * v153 + v144;
                  v155 = &this->verts.list[v153 * (v148 - 1) + v144];
                  v156 = &this->verts.list[v154];
                  v156->xyz.x = v155->xyz.x;
                  v156->xyz.y = v155->xyz.y;
                  v156->xyz.z = v155->xyz.z;
                  v156->st.x = v155->st.x;
                  v156->st.y = v155->st.y;
                  v156->normal[0] = v155->normal[0];
                  v156->normal[1] = v155->normal[1];
                  v156->normal[2] = v155->normal[2];
                  v156->normal[3] = v155->normal[3];
                  v156->tangent[0] = v155->tangent[0];
                  v156->tangent[1] = v155->tangent[1];
                  v156->tangent[2] = v155->tangent[2];
                  v147 -= 4;
                  v156->tangent[3] = v155->tangent[3];
                  v156->color[0] = v155->color[0];
                  v156->color[1] = v155->color[1];
                  v156->color[2] = v155->color[2];
                  v156->color[3] = v155->color[3];
                  v157 = this->maxWidth;
                  v158 = v157 * v148 + v144;
                  v159 = &this->verts.list[v157 * (v148 - 2) + v144];
                  v160 = &this->verts.list[v158];
                  v160->xyz.x = v159->xyz.x;
                  v160->xyz.y = v159->xyz.y;
                  v160->xyz.z = v159->xyz.z;
                  v160->st.x = v159->st.x;
                  v160->st.y = v159->st.y;
                  v160->normal[0] = v159->normal[0];
                  v160->normal[1] = v159->normal[1];
                  v160->normal[2] = v159->normal[2];
                  v160->normal[3] = v159->normal[3];
                  v160->tangent[0] = v159->tangent[0];
                  v160->tangent[1] = v159->tangent[1];
                  v160->tangent[2] = v159->tangent[2];
                  v160->tangent[3] = v159->tangent[3];
                  v160->color[0] = v159->color[0];
                  v160->color[1] = v159->color[1];
                  v160->color[2] = v159->color[2];
                  v160->color[3] = v159->color[3];
                  v161 = this->maxWidth;
                  v162 = (v148 - 3) * v161;
                  v163 = v161 * (v148 - 1);
                  v148 -= 4;
                  v165 = &this->verts.list[v163 + v144];
                  v164 = &this->verts.list[v162 + v144];
                  v165->xyz.x = v164->xyz.x;
                  v165->xyz.y = v164->xyz.y;
                  v165->xyz.z = v164->xyz.z;
                  v165->st.x = v164->st.x;
                  v165->st.y = v164->st.y;
                  v165->normal[0] = v164->normal[0];
                  v165->normal[1] = v164->normal[1];
                  v165->normal[2] = v164->normal[2];
                  v165->normal[3] = v164->normal[3];
                  v165->tangent[0] = v164->tangent[0];
                  v165->tangent[1] = v164->tangent[1];
                  v165->tangent[2] = v164->tangent[2];
                  v165->tangent[3] = v164->tangent[3];
                  v165->color[0] = v164->color[0];
                  v165->color[1] = v164->color[1];
                  v165->color[2] = v164->color[2];
                  v165->color[3] = v164->color[3];
                }
                while ( v147 > v146 + 3 );
              }
              if ( v147 > v116 + 3 )
              {
                v166 = v147 - (v116 + 3);
                do
                {
                  v167 = this->maxWidth;
                  v168 = v167 * v147 + v144;
                  v169 = &this->verts.list[(v147 - 2) * v167 + v144];
                  v170 = &this->verts.list[v168];
                  --v147;
                  v170->xyz.x = v169->xyz.x;
                  v170->xyz.y = v169->xyz.y;
                  v170->xyz.z = v169->xyz.z;
                  v170->st.x = v169->st.x;
                  v170->st.y = v169->st.y;
                  v170->normal[0] = v169->normal[0];
                  v170->normal[1] = v169->normal[1];
                  v170->normal[2] = v169->normal[2];
                  v170->normal[3] = v169->normal[3];
                  v170->tangent[0] = v169->tangent[0];
                  v170->tangent[1] = v169->tangent[1];
                  v170->tangent[2] = v169->tangent[2];
                  v170->tangent[3] = v169->tangent[3];
                  v170->color[0] = v169->color[0];
                  v170->color[1] = v169->color[1];
                  v170->color[2] = v169->color[2];
                  v170->color[3] = v169->color[3];
                  --v166;
                }
                while ( v166 != 0 );
              }
            }
            v171 = v229.xyz.y;
            v172 = v229.normal[0];
            v173 = v229.normal[1];
            v174 = v229.xyz.z;
            v175 = v229.normal[2];
            v176 = v229.st.x;
            v177 = v229.tangent[0];
            v178 = v229.st.y;
            v179 = v229.tangent[1];
            v180 = v231[0].xyz.x;
            v181 = v229.tangent[2];
            v182 = v231[0].xyz.y;
            v183 = v229.tangent[3];
            v184 = v231[0].xyz.z;
            v185 = v229.color[0];
            v186 = v231[0].st.x;
            v187 = v229.color[3];
            v188 = v231[0].st.y;
            v189 = v229.normal[3];
            v190 = v229.color[1];
            v191 = v229.color[2];
            v117 = v227;
            v192 = v231[0].normal[1];
            v193 = &this->verts.list[this->maxWidth * v118 + v144];
            v194 = v231[0].color[2];
            v195 = v231[0].normal[2];
            v196 = v231[0].normal[3];
            v197 = v231[0].tangent[0];
            v198 = v231[0].tangent[1];
            v193->xyz.x = v229.xyz.x;
            v193->xyz.y = v171;
            v199 = v231[0].tangent[2];
            v193->xyz.z = v174;
            v200 = v231[0].tangent[3];
            v193->st.x = v176;
            v201 = v231[0].color[0];
            v193->st.y = v178;
            v193->normal[0] = v172;
            v193->normal[1] = v173;
            v193->tangent[0] = v177;
            v193->tangent[1] = v179;
            v193->normal[2] = v175;
            v193->tangent[2] = v181;
            v193->tangent[3] = v183;
            v193->color[0] = v185;
            v193->color[3] = v187;
            v193->normal[3] = v189;
            v193->color[1] = v190;
            v193->color[2] = v191;
            v202 = v231[0].color[1];
            v203 = v231[0].color[3];
            v204 = v231[0].normal[0];
            v205 = &this->verts.list[this->maxWidth * v227 + v144];
            v205->xyz.x = v180;
            v205->xyz.y = v182;
            v205->xyz.z = v184;
            v205->st.x = v186;
            v205->st.y = v188;
            v205->normal[1] = v192;
            v205->normal[2] = v195;
            v205->normal[3] = v196;
            v205->tangent[0] = v197;
            v205->tangent[1] = v198;
            v205->tangent[2] = v199;
            v205->tangent[3] = v200;
            v205->color[0] = v201;
            v205->color[1] = v202;
            v205->color[2] = v194;
            v205->color[3] = v203;
            v206 = v230.xyz.x;
            v205->normal[0] = v204;
            v207 = v230.xyz.y;
            v116 = v228;
            v208 = v230.xyz.z;
            v209 = v230.normal[3];
            v210 = v230.st.x;
            v146 = v228 + 3;
            v211 = v230.tangent[0];
            v212 = v230.tangent[1];
            v213 = v230.st.y;
            v214 = v230.tangent[2];
            v215 = v230.tangent[3];
            v216 = v230.color[0];
            v217 = v230.color[1];
            v218 = v230.color[2];
            v219 = v230.color[3];
            v220 = v230.normal[0];
            v221 = v230.normal[1];
            v222 = v230.normal[2];
            v223 = (v228 + 3) * this->maxWidth + v144++;
            v224 = &this->verts.list[v223];
            v224->xyz.x = v206;
            v224->xyz.y = v207;
            v224->xyz.z = v208;
            v224->st.x = v210;
            v224->st.y = v213;
            v224->normal[3] = v209;
            v224->tangent[0] = v211;
            v224->tangent[1] = v212;
            v224->tangent[2] = v214;
            v224->tangent[3] = v215;
            v224->color[0] = v216;
            v224->color[1] = v217;
            v224->color[2] = v218;
            v224->color[3] = v219;
            v224->normal[0] = v220;
            v224->normal[1] = v221;
            v224->normal[2] = v222;
          }
          while ( v144 < this->width );
        }
        v116 -= 2;
        v118 -= 2;
        v117 -= 2;
      }
      v117 += 2;
      v116 += 2;
      v227 = v117;
      v118 += 2;
      v228 = v116;
    }
    while ( v117 < this->height );
  }
  idSurface_Patch::PutOnCurve(this);
  idSurface_Patch::RemoveLinearColumnsRows(this);
  idSurface_Patch::Collapse(this: v225);
  idSurface_Patch::GenerateIndexes(this);
}

