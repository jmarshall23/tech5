
// ========================================================================
// ?SetupSubTreePtrsFromTreeNodes@@YAXAAUfm_subTreeTreeNodePtrs_t@@PBUfm_subTreeTreeNodes_t@@@Z
// EA  : 0x827D8918
// RVA : 0x007D8918
// PDB : w:\tech5\engine\models\foliage\jobs\foliagegen.cpp
// ========================================================================

void __fastcall SetupSubTreePtrsFromTreeNodes(dm_subTreeDataPtrs_t *subTreePtrs, const dm_subTreeData_t *subTree)
{
  subTreePtrs->detail = (dm_detail_t *)((char *)subTree + subTree->detailOffset);
  subTreePtrs->attributes = (dm_attribute_t *)((char *)subTree + subTree->attributeOffset);
}


// ========================================================================
// ?CalculateFoliageBounds@@YAXQBFMMMMMABVidVec3@@AAVidBounds@@@Z
// EA  : 0x827D8938
// RVA : 0x007D8938
// PDB : w:\tech5\engine\models\foliage\jobs\foliagegen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall CalculateFoliageBounds(
        const __int16 *xyz,
        double uniformSizeScale,
        double quadWidth,
        double quadHeight,
        double widthVariance,
        double heightVariance,
        const idVec3 *upVec,
        idBounds *bounds,
        int a9,
        int a10,
        int a11,
        int a12,
        float *a13)
{
  __int16 v13; // r5
  __int64 v14; // r4
  __int64 v15; // r6 OVERLAPPED
  int v16; // r7

  v13 = xyz[2];
  LODWORD(v14) = xyz[1];
  HIDWORD(v14) = *xyz;
  LODWORD(v15) = v13;
  HIDWORD(v15) = HIDWORD(v14) * v14 * v13;
  v16 = HIDWORD(v14);
  a13[4] = (float)v14;
  a13[3] = (float)*(__int64 *)((char *)&v15 - 4);
  a13[5] = (float)v15;
  *a13 = (float)*(__int64 *)((char *)&v15 - 4);
  a13[1] = a13[4];
  a13[2] = a13[5];
  _FP9 = (float)((float)((float)((float)((float)((float)((float)(COERCE_FLOAT(
                                                                   (1664525 * HIDWORD(v15) - 1117345) & 0x7FFFFF
                                                                 | 0x3F800000)
                                                               * (float)2.0)
                                                       - (float)3.0)
                                               * (float)quadWidth)
                                       * (float)widthVariance)
                               + (float)quadWidth)
                       * (float)uniformSizeScale)
               - (float)((float)((float)((float)((float)((float)(COERCE_FLOAT(
                                                                   (1664525 * HIDWORD(v15) - 1117345) & 0x7FFFFF
                                                                 | 0x3F800000)
                                                               * (float)2.0)
                                                       - (float)3.0)
                                               * (float)quadHeight)
                                       * (float)heightVariance)
                               + (float)quadHeight)
                       * (float)uniformSizeScale));
  __asm { fsel      f8, f9, f11, f0 }
  *a13 = *a13 - (float)((float)_FP8 * (float)0.5);
  a13[1] = a13[1] - (float)((float)_FP8 * (float)0.5);
  a13[3] = (float)((float)_FP8 * (float)0.5) + a13[3];
  a13[4] = a13[4] + (float)((float)_FP8 * (float)0.5);
  if ( *(float *)(a12 + 8) >= 0.0 )
    a13[5] = a13[5]
           + (float)((float)((float)((float)((float)((float)(COERCE_FLOAT(
                                                               (1664525 * HIDWORD(v15) - 1117345) & 0x7FFFFF
                                                             | 0x3F800000)
                                                           * (float)2.0)
                                                   - (float)3.0)
                                           * (float)quadHeight)
                                   * (float)heightVariance)
                           + (float)quadHeight)
                   * (float)uniformSizeScale);
  else
    a13[2] = a13[2]
           - (float)((float)((float)((float)((float)((float)(COERCE_FLOAT(
                                                               (1664525 * HIDWORD(v15) - 1117345) & 0x7FFFFF
                                                             | 0x3F800000)
                                                           * (float)2.0)
                                                   - (float)3.0)
                                           * (float)quadHeight)
                                   * (float)heightVariance)
                           + (float)quadHeight)
                   * (float)uniformSizeScale);
}


// ========================================================================
// ?CalculateFoliageBounds@@YAXPBUfm_foliage_t@@PBUfm_attribute_t@@AAVidBounds@@@Z
// EA  : 0x827D8A80
// RVA : 0x007D8A80
// PDB : w:\tech5\engine\models\foliage\jobs\foliagegen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall CalculateFoliageBounds(const fm_foliage_t *foliage, const fm_attribute_t *attribute, __int64 bounds)
{
  int v3; // r7
  __int64 v4; // r11
  __int64 v5; // fp11
  int widthVariance; // r7
  __int64 v7; // r9
  double v8; // fp2
  __int64 v9; // fp9
  int quadWidth; // r7
  __int64 v11; // [sp+50h] [-20h]
  float v12[4]; // [sp+58h] [-18h] BYREF

  v3 = foliage->upVec[0];
  HIDWORD(v4) = &unk_821C0000;
  LODWORD(v4) = foliage->upVec[1];
  LODWORD(bounds) = foliage->uniformSizeScale;
  v5 = *(__int64 *)((char *)&bounds - 4);
  widthVariance = attribute->widthVariance;
  v7 = __PAIR64__(0x82000000, bounds);
  v8 = (double)v4;
  LODWORD(v4) = attribute->heightVariance;
  v9 = v4;
  LODWORD(v4) = attribute->quadHeight;
  LODWORD(bounds) = foliage->upVec[2];
  v11 = *(__int64 *)((char *)&bounds - 4);
  quadWidth = attribute->quadWidth;
  v12[2] = (float)((float)bounds * (float)0.0078431377) - (float)1.0;
  v12[0] = (float)((float)v5 * (float)0.0078431377) - (float)1.0;
  v12[1] = (float)((float)v8 * (float)0.0078431377) - (float)1.0;
  CalculateFoliageBounds(
    xyz: foliage->xyz,
    uniformSizeScale: (float)((float)v7 * (float)0.0099999998),
    quadWidth: (float)*(__int64 *)((char *)&bounds - 4),
    quadHeight: (float)v4,
    widthVariance: (float)((float)v11 * (float)0.0099999998),
    heightVariance: (float)((float)v9 * (float)0.0099999998),
    upVec: (const idVec3 *)byte_821B0000,
    bounds: (idBounds *)HIDWORD(bounds),
    a9: bounds,
    a10: quadWidth,
    a11: 0x82000000,
    a12: (int)v12,
    a13: (float *)HIDWORD(bounds));
}


// ========================================================================
// ?GetFoliageOffsetForSubTree@@YAHPBUfoliageSubTreeStats_t@@H@Z
// EA  : 0x827D8B98
// RVA : 0x007D8B98
// PDB : w:\tech5\engine\models\foliage\jobs\foliagegen.cpp
// ========================================================================

int __fastcall GetFoliageOffsetForSubTree(const foliageSubTreeStats_t *foliageCountsList, int subTreeIndex)
{
  int v2; // r9
  int v3; // r8
  int v4; // r11
  const foliageSubTreeStats_t *v5; // r10
  int subTreeFoliageCount; // r6

  v2 = 0;
  v3 = 0;
  v4 = 0;
  if ( subTreeIndex >= 2 )
  {
    v5 = foliageCountsList - 1;
    do
    {
      subTreeFoliageCount = v5[1].subTreeFoliageCount;
      v4 += 2;
      v5 += 2;
      v2 += subTreeFoliageCount;
      v3 += v5->subTreeFoliageCount;
    }
    while ( v4 < subTreeIndex - 1 );
  }
  if ( v4 >= subTreeIndex )
    return v3 + v2;
  else
    return v3 + v2 + foliageCountsList[v4].subTreeFoliageCount;
}


// ========================================================================
// ?GetFoliageTotalCount@@YAHPBUfoliageSubTreeStats_t@@@Z
// EA  : 0x827D8C08
// RVA : 0x007D8C08
// PDB : w:\tech5\engine\models\foliage\jobs\foliagegen.cpp
// ========================================================================

int __fastcall GetFoliageTotalCount(const foliageSubTreeStats_t *foliageCountsList)
{
  int subTreeFoliageCount; // r10
  int result; // r3
  int v4; // r11
  bool v5; // zf

  subTreeFoliageCount = foliageCountsList->subTreeFoliageCount;
  v4 = 0;
  v5 = foliageCountsList->subTreeFoliageCount != -1;
  result = 0;
  if ( v5 )
  {
    do
    {
      ++v4;
      result += subTreeFoliageCount;
      subTreeFoliageCount = foliageCountsList[v4].subTreeFoliageCount;
    }
    while ( subTreeFoliageCount != -1 );
  }
  return result;
}


// ========================================================================
// ?GetFoliageOffsetAndCountForJob@@YAXHHHAAH0@Z
// EA  : 0x827D8C40
// RVA : 0x007D8C40
// PDB : w:\tech5\engine\models\foliage\jobs\foliagegen.cpp
// ========================================================================

void __fastcall GetFoliageOffsetAndCountForJob(
        int numJobs,
        int jobIndex,
        int totalCount,
        int *jobOffset,
        int *jobCount)
{
  int v5; // r8
  int v6; // r11
  int v7; // r5

  v5 = (jobIndex + 1) * totalCount;
  v6 = __ROL4__(jobIndex * totalCount, 1);
  v7 = jobIndex * totalCount / numJobs;
  *jobOffset = v7;
  __twllei(numJobs, 0);
  __twllei(numJobs, 0);
  *jobCount = v5 / numJobs - v7;
  __twlgei(numJobs & ~(v6 - 1), 0xFFFFFFFF);
  __twlgei(numJobs & ~(__ROL4__(v5, 1) - 1), 0xFFFFFFFF);
}


// ========================================================================
// ?BuildFoliageQuad@@YAHPAVidTransparencyVert@@PAMIPBUfm_foliage_t@@PBUfm_attribute_t@@PBUfoliageRenderView_t@@PBUinfluenceSphere_t@@PBFMMM@Z
// EA  : 0x827D8C90
// RVA : 0x007D8C90
// PDB : w:\tech5\engine\models\foliage\jobs\foliagegen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall BuildFoliageQuad(
        idTransparencyVert *verts,
        float *quadDepth,
        unsigned int foliageIndex,
        const fm_foliage_t *foliage,
        const fm_attribute_t *attribute,
        const foliageRenderView_t *viewData,
        const influenceSphere_t *influenceSpheres,
        double foliageStartFadeDist,
        double foliageSmallFadeDistMax,
        double foliageBigFadeDistMax)
{
  __int64 influenceSphereIndices; // r11
  int v11; // r2 OVERLAPPED
  __int16 v15; // r7
  unsigned int v16; // r6 OVERLAPPED
  unsigned int v18; // r4
  int widthVariance; // r3
  __int64 v21; // r9
  __int64 v22; // r29
  unsigned __int16 *v23; // r25
  int quadHeight; // r26
  int quadWidth; // r27
  int v27; // r3
  int v28; // r7
  double v29; // fp7
  double v30; // fp4
  double v31; // fp12
  double v32; // fp10
  double v33; // fp12
  double v34; // fp15
  __int64 v35; // r8 OVERLAPPED
  double v36; // fp14
  double v37; // fp31
  double v38; // fp21
  double v41; // fp0
  double v42; // fp0
  unsigned __int8 v43; // r11
  int v44; // r22
  int v50; // r11
  double v51; // fp11
  double v52; // fp12
  __int64 v53; // r6 OVERLAPPED
  __int64 v54; // r4
  __int64 v55; // r11
  double v56; // fp22
  double v57; // fp19
  double v58; // fp20
  double v59; // fp0
  double v60; // fp16
  double v61; // fp18
  double v62; // fp17
  double v63; // fp31
  double v64; // fp30
  double v65; // fp29
  double v66; // fp28
  double v67; // fp27
  double v68; // fp26
  double v69; // fp1
  double v70; // fp14
  double v71; // fp25
  double v72; // fp29
  double v73; // fp28
  double v74; // fp27
  double v75; // fp24
  float *v76; // r3
  double v77; // fp1
  double z; // fp24
  int v79; // r29
  unsigned __int16 *v80; // r11
  const influenceSphere_t *v81; // r11
  double v82; // fp9
  double angle; // fp11
  double v84; // fp1
  double v85; // fp3
  double v86; // fp5
  double v87; // fp4
  double v90; // fp8
  double v91; // fp11
  double v92; // fp8
  double v93; // fp24
  double v94; // fp23
  double v95; // fp21
  double v96; // fp1
  double v97; // fp12
  double v98; // fp11
  double v99; // fp9
  double v100; // fp10
  double v101; // fp8
  double v102; // fp7
  double v103; // fp6
  double v104; // fp5
  double v105; // fp3
  double v106; // fp4
  double v107; // fp2
  double v108; // fp31
  double v109; // fp29
  double v110; // fp26
  double v111; // fp28
  double v112; // fp27
  double v113; // fp14
  double v114; // fp6
  double v115; // fp5
  double v116; // fp31
  double v117; // fp23
  double v118; // fp24
  double v119; // fp7
  double v120; // fp21
  double v121; // fp0
  int atlasHeight; // r7
  __int64 v123; // r9
  double v124; // fp12
  double v125; // fp13
  double v126; // fp10
  double v127; // fp9
  double v128; // fp11
  double x; // fp25
  double v130; // fp8
  double y; // fp30
  double v132; // fp7
  double v133; // fp6
  double v134; // fp5
  double v135; // fp3
  double v136; // fp4
  long double v137; // fp2
  unsigned __int8 *color; // r31
  int v139; // r30
  long double v140; // fp2
  __int16 v141; // r11
  __int16 v142; // r11
  float v143; // [sp+50h] [-160h]
  float v144; // [sp+58h] [-158h]
  __int64 v145; // [sp+60h] [-150h] BYREF
  __int64 v146; // [sp+68h] [-148h] BYREF
  __int64 v147; // [sp+70h] [-140h]
  __int64 v148; // [sp+78h] [-138h]
  idVec3 v149; // [sp+80h] [-130h]
  float v150; // [sp+90h] [-120h] BYREF
  float v151; // [sp+94h] [-11Ch] BYREF
  float v152; // [sp+98h] [-118h]
  float v153; // [sp+9Ch] [-114h]
  idVec3 v154; // [sp+A0h] [-110h] BYREF
  float v155; // [sp+ACh] [-104h]

  HIDWORD(v22) = foliage;
  LODWORD(influenceSphereIndices) = attribute->heightVariance;
  v18 = foliage->xyz[1];
  _R31 = verts;
  widthVariance = attribute->widthVariance;
  v15 = foliage->xyz[2];
  LODWORD(v22) = foliage->uniformSizeScale;
  v16 = foliage->xyz[0];
  v23 = (unsigned __int16 *)HIDWORD(influenceSphereIndices);
  quadHeight = attribute->quadHeight;
  quadWidth = attribute->quadWidth;
  v148 = *(_QWORD *)(&v11 - 1);
  v27 = 1664525 * v16 * v18 * v15;
  LODWORD(v21) = v15;
  LODWORD(v147) = v22;
  v28 = quadHeight;
  v29 = (float)v148;
  v145 = *(_QWORD *)(&v16 - 1);
  HIDWORD(v21) = v27 - 1117345;
  v30 = (double)v21;
  LODWORD(v35) = quadWidth;
  v146 = v35;
  v31 = (double)*(__int64 *)((char *)&v35 + 4);
  HIDWORD(v35) = v18;
  v32 = (float)*(__int64 *)((char *)&v35 + 4);
  v149.z = v30;
  v149.y = (float)*(__int64 *)((char *)&v35 + 4);
  v33 = (float)v31;
  v34 = (float)((float)(COERCE_FLOAT((v27 - 1117345) & 0x7FFFFF | 0x3F800000) * (float)2.0) - (float)3.0);
  v149.x = (float)__SPAIR64__(v18, v16);
  HIDWORD(v35) = &unk_82200000;
  *(float *)&v147 = (float)(COERCE_FLOAT((v27 - 1117345) & 0x7FFFFF | 0x3F800000) * (float)2.0) - (float)3.0;
  v36 = 0.5;
  v143 = 0.5;
  LODWORD(v148) = v21;
  *(float *)&v148 = 1.0;
  v37 = (float)((float)((float)((float)((float)((float)v29 * (float)0.0099999998) * (float)v146) * *(float *)&v147)
                      + (float)v146)
              * (float)((float)v22 * (float)0.0099999998));
  v38 = (float)((float)((float)((float)((float)((float)influenceSphereIndices * (float)0.0099999998) * (float)v33)
                              * *(float *)&v147)
                      + (float)v33)
              * (float)((float)v22 * (float)0.0099999998));
  _FP6 = (float)((float)((float)((float)((float)((float)((float)v29 * (float)0.0099999998) * (float)v146)
                                       * *(float *)&v147)
                               + (float)v146)
                       * (float)((float)v22 * (float)0.0099999998))
               - (float)((float)((float)((float)((float)((float)influenceSphereIndices * (float)0.0099999998)
                                               * (float)v33)
                                       * *(float *)&v147)
                               + (float)v33)
                       * (float)((float)v22 * (float)0.0099999998)));
  __asm { fsel      f5, f6, f31, f21 }
  if ( (float)((float)_FP5 * (float)0.5) >= 100.0 )
  {
    v41 = foliageBigFadeDistMax;
  }
  else
  {
    HIDWORD(v35) = (1664525 * foliageIndex - 1117345) & 0x7FFFFF;
    v41 = (float)((float)((float)((float)((float)(COERCE_FLOAT(HIDWORD(v35) | 0x3F800000) - (float)1.0)
                                        * (float)(COERCE_FLOAT(HIDWORD(v35) | 0x3F800000) - (float)1.0))
                                * (float)(COERCE_FLOAT(HIDWORD(v35) | 0x3F800000) - (float)1.0))
                        * (float)((float)foliageSmallFadeDistMax - (float)foliageStartFadeDist))
                + (float)foliageStartFadeDist);
    foliageSmallFadeDistMax = (float)-(float)((float)((float)((float)foliageSmallFadeDistMax
                                                            - (float)foliageStartFadeDist)
                                                    * (float)0.25)
                                            - (float)((float)((float)((float)((float)(COERCE_FLOAT(HIDWORD(v35) | 0x3F800000)
                                                                                    - (float)1.0)
                                                                            * (float)(COERCE_FLOAT(HIDWORD(v35) | 0x3F800000)
                                                                                    - (float)1.0))
                                                                    * (float)(COERCE_FLOAT(HIDWORD(v35) | 0x3F800000)
                                                                            - (float)1.0))
                                                            * (float)((float)foliageSmallFadeDistMax
                                                                    - (float)foliageStartFadeDist))
                                                    + (float)foliageStartFadeDist));
  }
  v42 = (float)((float)v41 - (float)foliageSmallFadeDistMax);
  if ( __fabs(v42) >= 1.0 )
  {
    LODWORD(v146) = (int)(float)((float)((float)1.0
                                       - (float)((float)((float)((float)(viewData->viewFwd.x
                                                                       * (float)((float)__SPAIR64__(v18, v16)
                                                                               - viewData->viewOrg.x))
                                                               + (float)((float)(viewData->viewFwd.z
                                                                               * (float)((float)v30 - viewData->viewOrg.z))
                                                                       + (float)(viewData->viewFwd.y
                                                                               * (float)((float)v32 - viewData->viewOrg.y))))
                                                       - (float)foliageSmallFadeDistMax)
                                               / (float)v42))
                               * (float)255.0);
    v43 = v146;
    if ( (int)v146 >= 0 )
    {
      if ( (int)v146 > 255 )
        v43 = -1;
    }
    else
    {
      v43 = 0;
    }
  }
  else
  {
    v43 = -1;
  }
  v44 = v43;
  if ( v43 != 0 )
  {
    v50 = *(unsigned __int8 *)(HIDWORD(v22) + 11);
    v144 = 0.0;
    v51 = __fabs((float)((float)((float)(COERCE_FLOAT((v27 - 1117345) & 0x7FFFFF | 0x3F800000) * (float)2.0) - (float)3.0)
                       * (float)360.0));
    switch ( v50 )
    {
      case 1:
        v52 = 90.0;
        break;
      case 2:
        v52 = 120.0;
        break;
      case 3:
        v52 = 240.0;
        break;
      default:
        v52 = 0.0;
        break;
    }
    LODWORD(v35) = *(unsigned __int8 *)(HIDWORD(v22) + 12);
    LODWORD(v53) = *(unsigned __int8 *)(HIDWORD(v22) + 13);
    LODWORD(v54) = *(unsigned __int8 *)(HIDWORD(v22) + 14);
    *(float *)&v53 = viewData->viewLeft.x;
    *(float *)&v54 = viewData->viewLeft.y;
    v146 = v35;
    LODWORD(v55) = LODWORD(viewData->viewLeft.z);
    HIDWORD(v55) = attribute->shape;
    v150 = *(float *)&v53;
    v151 = *(float *)&v54;
    v152 = *((float *)&v55 + 1);
    v146 = v54;
    v56 = (float)((float)((float)v54 * (float)0.0078431377) - (float)1.0);
    v57 = (float)((float)((float)v53 * (float)0.0078431377) - (float)1.0);
    v58 = (float)((float)((float)v35 * (float)0.0078431377) - (float)1.0);
    if ( HIDWORD(v55) != 0 )
    {
      idMath::SinCos16(
        a: (float)((float)((float)v52 + (float)v51) * idMath::M_DEG2RAD),
        s: (float *)HIDWORD(v54),
        c: &v151,
        a4: &v150);
      v59 = 0.0;
    }
    else
    {
      v59 = v152;
    }
    LODWORD(v55) = attribute->swayMagnitude;
    v60 = (float)((float)v59 * (float)((float)v37 * (float)0.5));
    v152 = (float)v59 * (float)((float)v37 * (float)0.5);
    v61 = (float)(v150 * (float)((float)v37 * (float)0.5));
    v62 = (float)(v151 * (float)((float)v37 * (float)0.5));
    v64 = (float)((float)((float)v58 * (float)v38) - (float)(v150 * (float)((float)v37 * (float)0.5)));
    v65 = (float)((float)((float)v57 * (float)v38) - (float)(v151 * (float)((float)v37 * (float)0.5)));
    v66 = (float)((float)((float)v58 * (float)v38) + (float)(v150 * (float)((float)v37 * (float)0.5)));
    v67 = (float)((float)((float)v57 * (float)v38) + (float)(v151 * (float)((float)v37 * (float)0.5)));
    v68 = (float)((float)((float)v56 * (float)v38) + v152);
    v63 = (float)((float)((float)v56 * (float)v38) - v152);
    if ( (_DWORD)v55 != 0 )
    {
      v69 = (float)((float)(viewData->time * idMath::TWO_PI) * (float)v34);
      v146 = v55;
      v70 = (float)((float)((float)v55 * (float)v38) * (float)0.00050000002);
      idMath::SinCos16(a: v69, s: (float *)HIDWORD(v54), c: (float *)&v145, a4: (float *)&v146);
      v154.z = (float)((float)((float)v57 * (float)v38) * (float)v61)
             - (float)((float)v62 * (float)((float)v58 * (float)v38));
      v154.x = (float)((float)((float)v56 * (float)v38) * (float)v62)
             - (float)((float)((float)v57 * (float)v38) * (float)v60);
      v154.y = (float)((float)v60 * (float)((float)v58 * (float)v38))
             - (float)((float)((float)v56 * (float)v38) * (float)v61);
      v71 = (float)((float)(*(float *)&v145 * (float)v70) + (float)v64);
      v72 = (float)((float)(*(float *)&v146 * (float)v70) + (float)v65);
      v73 = (float)((float)(*(float *)&v145 * (float)v70) + (float)v66);
      v74 = (float)((float)(*(float *)&v146 * (float)v70) + (float)v67);
      idVec3::NormalizeFast(this: &v154);
      v75 = (float)((float)(idMath::Sin16(a: (float)((float)(idMath::TWO_PI * (float)v34) + viewData->time)) * (float)v70)
                  * (float)5.0);
      v77 = idMath::Sin16(a: (float)((float)(idMath::TWO_PI * (float)v34) + (float)(viewData->time * (float)5.0)));
      LODWORD(v53) = LODWORD(v149.z);
      v65 = (float)((float)(v154.y * (float)v75) + (float)v72);
      v63 = (float)((float)(v154.z * (float)v75) + (float)v63);
      v64 = (float)((float)(v154.x * (float)v75) + (float)v71);
      z = v149.z;
      v66 = (float)((float)(v154.x * (float)((float)((float)v77 * (float)v70) * (float)5.0)) + (float)v73);
      v67 = (float)((float)(v154.y * (float)((float)((float)v77 * (float)v70) * (float)5.0)) + (float)v74);
      v68 = (float)((float)(v154.z * (float)((float)((float)v77 * (float)v70) * (float)5.0)) + (float)v68);
      v154 = v149;
      if ( v56 < v144 )
        v154.z = v149.z - (float)v38;
      v36 = v143;
      v79 = 0;
      if ( *v23 < 0x8000u )
      {
        v80 = v23;
        do
        {
          v81 = &influenceSpheres[(__int16)*v80];
          v82 = (float)((float)((float)(v154.x - v81->center.x) * (float)(v154.x - v81->center.x))
                      + (float)((float)((float)(v154.z - v81->center.z) * (float)(v154.z - v81->center.z))
                              + (float)((float)(v154.y - v81->center.y) * (float)(v154.y - v81->center.y))));
          if ( v82 < (float)(v81->outerRadius * v81->outerRadius) )
          {
            angle = v81->angle;
            if ( v82 > (float)(v81->innerRadius * v81->innerRadius) && v81->outerRadius > (double)v81->innerRadius )
              angle = (float)((float)((float)((float)(v81->outerRadius * v81->outerRadius)
                                            - (float)((float)((float)(v154.x - v81->center.x)
                                                            * (float)(v154.x - v81->center.x))
                                                    + (float)((float)((float)(v154.z - v81->center.z)
                                                                    * (float)(v154.z - v81->center.z))
                                                            + (float)((float)(v154.y - v81->center.y)
                                                                    * (float)(v154.y - v81->center.y)))))
                                    / (float)((float)(v81->outerRadius * v81->outerRadius)
                                            - (float)(v81->innerRadius * v81->innerRadius)))
                            * v81->angle);
            v84 = (float)((float)angle * idMath::M_DEG2RAD);
            v85 = (float)((float)((float)(v154.y - v81->center.y) * (float)v56)
                        - (float)((float)(v154.z - v81->center.z) * (float)v57));
            v86 = (float)((float)((float)(v154.z - v81->center.z) * (float)v58)
                        - (float)((float)v56 * (float)(v154.x - v81->center.x)));
            v87 = (float)((float)((float)v57 * (float)(v154.x - v81->center.x))
                        - (float)((float)(v154.y - v81->center.y) * (float)v58));
            _FP11 = (float)((float)((float)((float)v85 * (float)v85)
                                  + (float)((float)((float)v87 * (float)v87) + (float)((float)v86 * (float)v86)))
                          - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f9, f11, f12, f0 }
            v90 = __frsqrte(_FP9);
            v91 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v90
                                                                                                * (float)((float)((float)((float)v85 * (float)v85) + (float)((float)((float)v87 * (float)v87) + (float)((float)v86 * (float)v86))) * (float)v36))
                                                                                        * (float)v90)
                                                                                - (float)1.5)
                                                                * (float)v90)
                                                        * (float)((float)((float)((float)v85 * (float)v85)
                                                                        + (float)((float)((float)v87 * (float)v87)
                                                                                + (float)((float)v86 * (float)v86)))
                                                                * (float)v36))
                                                * (float)((float)-(float)((float)((float)((float)v90
                                                                                        * (float)((float)((float)((float)v85 * (float)v85) + (float)((float)((float)v87 * (float)v87) + (float)((float)v86 * (float)v86)))
                                                                                                * (float)v36))
                                                                                * (float)v90)
                                                                        - (float)1.5)
                                                        * (float)v90))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v90
                                                                * (float)((float)((float)((float)v85 * (float)v85)
                                                                                + (float)((float)((float)v87 * (float)v87)
                                                                                        + (float)((float)v86 * (float)v86)))
                                                                        * (float)v36))
                                                        * (float)v90)
                                                - (float)1.5)
                                * (float)v90));
            v92 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v90 * (float)((float)((float)((float)v85 * (float)v85) + (float)((float)((float)v87 * (float)v87) + (float)((float)v86 * (float)v86))) * (float)v36)) * (float)v90) - (float)1.5) * (float)v90)
                                                                                                * (float)((float)((float)((float)v85 * (float)v85) + (float)((float)((float)v87 * (float)v87) + (float)((float)v86 * (float)v86))) * (float)v36))
                                                                                        * (float)((float)-(float)((float)((float)((float)v90 * (float)((float)((float)((float)v85 * (float)v85) + (float)((float)((float)v87 * (float)v87) + (float)((float)v86 * (float)v86))) * (float)v36)) * (float)v90) - (float)1.5)
                                                                                                * (float)v90))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v90 * (float)((float)((float)((float)v85 * (float)v85) + (float)((float)((float)v87 * (float)v87) + (float)((float)v86 * (float)v86))) * (float)v36))
                                                                                                * (float)v90)
                                                                                        - (float)1.5)
                                                                        * (float)v90))
                                                        * (float)((float)((float)((float)v85 * (float)v85)
                                                                        + (float)((float)((float)v87 * (float)v87)
                                                                                + (float)((float)v86 * (float)v86)))
                                                                * (float)v36))
                                                * (float)v91)
                                        - (float)1.5)
                        * (float)v91);
            v93 = (float)((float)((float)((float)(v154.y - v81->center.y) * (float)v56)
                                - (float)((float)(v154.z - v81->center.z) * (float)v57))
                        * (float)v92);
            v94 = (float)((float)((float)((float)(v154.z - v81->center.z) * (float)v58)
                                - (float)((float)v56 * (float)(v154.x - v81->center.x)))
                        * (float)v92);
            v95 = (float)((float)((float)((float)v57 * (float)(v154.x - v81->center.x))
                                - (float)((float)(v154.y - v81->center.y) * (float)v58))
                        * (float)v92);
            idMath::SinCos16(a: v84, s: v76, c: (float *)&v146, a4: (float *)&v145);
            v96 = (float)((float)v93
                        * (float)((float)((float)v93 * (float)v64)
                                + (float)((float)((float)v95 * (float)v63) + (float)((float)v94 * (float)v65))));
            v97 = (float)((float)v94
                        * (float)((float)((float)v93 * (float)v64)
                                + (float)((float)((float)v95 * (float)v63) + (float)((float)v94 * (float)v65))));
            v98 = (float)((float)v95
                        * (float)((float)((float)v93 * (float)v64)
                                + (float)((float)((float)v95 * (float)v63) + (float)((float)v94 * (float)v65))));
            v99 = (float)((float)v95
                        * (float)((float)((float)v93 * (float)v66)
                                + (float)((float)((float)v95 * (float)v68) + (float)((float)v94 * (float)v67))));
            v100 = (float)((float)v94
                         * (float)((float)((float)v93 * (float)v66)
                                 + (float)((float)((float)v95 * (float)v68) + (float)((float)v94 * (float)v67))));
            v101 = (float)((float)((float)((float)v93 * (float)v66)
                                 + (float)((float)((float)v95 * (float)v68) + (float)((float)v94 * (float)v67)))
                         * (float)v93);
            v102 = (float)((float)v64
                         - (float)((float)v93
                                 * (float)((float)((float)v93 * (float)v64)
                                         + (float)((float)((float)v95 * (float)v63) + (float)((float)v94 * (float)v65)))));
            v103 = (float)((float)v65
                         - (float)((float)v94
                                 * (float)((float)((float)v93 * (float)v64)
                                         + (float)((float)((float)v95 * (float)v63) + (float)((float)v94 * (float)v65)))));
            v104 = (float)((float)v63
                         - (float)((float)v95
                                 * (float)((float)((float)v93 * (float)v64)
                                         + (float)((float)((float)v95 * (float)v63) + (float)((float)v94 * (float)v65)))));
            v105 = (float)((float)v68
                         - (float)((float)v95
                                 * (float)((float)((float)v93 * (float)v66)
                                         + (float)((float)((float)v95 * (float)v68) + (float)((float)v94 * (float)v67)))));
            v106 = (float)((float)v67
                         - (float)((float)v94
                                 * (float)((float)((float)v93 * (float)v66)
                                         + (float)((float)((float)v95 * (float)v68) + (float)((float)v94 * (float)v67)))));
            v107 = (float)((float)v66
                         - (float)((float)((float)((float)v93 * (float)v66)
                                         + (float)((float)((float)v95 * (float)v68) + (float)((float)v94 * (float)v67)))
                                 * (float)v93));
            v108 = (float)((float)v94
                         * (float)((float)v64
                                 - (float)((float)v93
                                         * (float)((float)((float)v93 * (float)v64)
                                                 + (float)((float)((float)v95 * (float)v63)
                                                         + (float)((float)v94 * (float)v65))))));
            v109 = (float)((float)v104 * (float)v93);
            v110 = (float)((float)v103 * *(float *)&v145);
            v111 = (float)((float)v104 * *(float *)&v145);
            v112 = (float)((float)v102 * *(float *)&v145);
            v113 = (float)((float)v94 * (float)v107);
            v115 = (float)((float)((float)v104 * (float)v94) - (float)((float)v103 * (float)v95));
            v114 = (float)((float)((float)v103 * (float)v93) - (float)v108);
            v116 = (float)((float)((float)v105 * (float)v94) - (float)((float)v106 * (float)v95));
            v117 = (float)((float)((float)v95 * (float)v107) - (float)((float)v105 * (float)v93));
            v34 = *(float *)&v147;
            v118 = (float)((float)((float)v106 * (float)v93) - (float)v113);
            v119 = (float)((float)((float)((float)v95 * (float)v102) - (float)v109) * *(float *)&v146);
            v120 = (float)((float)v116 * *(float *)&v146);
            v63 = (float)((float)((float)v111 - (float)((float)v114 * *(float *)&v146)) + (float)v98);
            v64 = (float)((float)((float)v112 - (float)((float)v115 * *(float *)&v146)) + (float)v96);
            v65 = (float)((float)((float)v110 - (float)v119) + (float)v97);
            v60 = v152;
            v36 = v143;
            v66 = (float)((float)((float)((float)v107 * *(float *)&v145) - (float)v120) + (float)v101);
            v67 = (float)((float)((float)((float)v106 * *(float *)&v145) - (float)((float)v117 * *(float *)&v146))
                        + (float)v100);
            v68 = (float)((float)((float)((float)v105 * *(float *)&v145) - (float)((float)v118 * *(float *)&v146))
                        + (float)v99);
            z = v149.z;
          }
          v80 = &v23[++v79];
        }
        while ( *v80 < 0x8000u );
      }
    }
    else
    {
      z = v149.z;
    }
    LODWORD(v123) = viewData->atlasWidth;
    v121 = attribute->sortScaleBias[0];
    atlasHeight = viewData->atlasHeight;
    HIDWORD(v123) = attribute->flipHoriz;
    v124 = (float)((float)8.0 / (float)((float)*(__int64 *)((char *)&v53 - 4) * attribute->sortScaleBias[1]));
    v125 = (float)((float)8.0 / (float)((float)v123 * attribute->sortScaleBias[0]));
    v126 = (float)(*(float *)&v148
                 - (float)((float)8.0 / (float)((float)*(__int64 *)((char *)&v53 - 4) * attribute->sortScaleBias[1])));
    v127 = (float)(*(float *)&v148 - (float)((float)8.0 / (float)((float)v123 * attribute->sortScaleBias[0])));
    v147 = v123;
    v148 = *(__int64 *)((char *)&v53 - 4);
    if ( HIDWORD(v123) != 0 && v34 < v144 )
    {
      v128 = v127;
    }
    else
    {
      v128 = (float)((float)8.0 / (float)((float)v123 * (float)v121));
      v125 = v127;
    }
    x = v149.x;
    v130 = (float)((float)v64 + v149.x);
    y = v149.y;
    v132 = attribute->sortScaleBias[2];
    v133 = (float)((float)v65 + v149.y);
    v134 = attribute->sortScaleBias[1];
    v135 = attribute->sortScaleBias[3];
    v136 = (float)((float)v66 + v149.x);
    _R31->xyz.x = v130;
    _R31->xyz.y = v133;
    _R31->xyz.z = (float)v63 + (float)z;
    _R31[1].xyz.x = v136;
    _R31[1].xyz.y = (float)v67 + (float)y;
    _R31[1].xyz.z = (float)v68 + (float)z;
    _R31[2].xyz.x = (float)x - (float)v61;
    _R31[2].xyz.y = (float)y - (float)v62;
    _R31[2].xyz.z = (float)z - (float)v60;
    *((double *)&v137 + 1) = (float)((float)v61 + (float)x);
    _R31[3].xyz.x = (float)v61 + (float)x;
    _R31[3].xyz.y = (float)v62 + (float)y;
    _R31[3].xyz.z = (float)v60 + (float)z;
    v154.x = (float)((float)v121 * (float)v128) + (float)v132;
    color = _R31[-1].color;
    v154.y = (float)((float)v121 * (float)v125) + (float)v132;
    v139 = 0;
    v154.z = v154.x;
    v155 = v154.y;
    v150 = (float)((float)v134 * (float)v124) + (float)v135;
    v151 = v150;
    v152 = (float)((float)v134 * (float)v126) + (float)v135;
    v153 = v152;
    do
    {
      *(double *)&v137 = (float)((float)((float)(*(float *)((char *)&v154.x + v139) - (float)v36) * (float)65534.0)
                               + (float)v36);
      v140 = floor(x: v137);
      LODWORD(v148) = (int)(float)*(double *)&v140;
      v141 = v148;
      if ( (int)v148 >= -32768 )
      {
        if ( (int)v148 > 0x7FFF )
          v141 = 0x7FFF;
      }
      else
      {
        v141 = 0x8000;
      }
      *((_WORD *)color + 10) = v141;
      *((_WORD *)color + 8) = v141;
      *(double *)&v140 = (float)((float)((float)(*(float *)((char *)&v150 + v139) - (float)v36) * (float)65534.0)
                               + (float)v36);
      v137 = floor(x: v140);
      LODWORD(v148) = (int)(float)*(double *)&v137;
      v142 = v148;
      if ( (int)v148 >= -32768 )
      {
        if ( (int)v148 > 0x7FFF )
          v142 = 0x7FFF;
      }
      else
      {
        v142 = 0x8000;
      }
      *((_DWORD *)color + 6) = 0;
      v139 += 4;
      *((_DWORD *)color + 7) = -16776961;
      *((_WORD *)color + 9) = v142;
      *((_WORD *)color + 11) = v142;
      color += 32;
      *(_DWORD *)color = ((((__ROL4__(*(unsigned __int8 *)(HIDWORD(v22) + 8), 8) | *(unsigned __int8 *)(HIDWORD(v22) + 9)) << 8)
                         | *(unsigned __int8 *)(HIDWORD(v22) + 10)) << 8)
                       | v44;
    }
    while ( v139 < 16 );
    if ( quadDepth != nullptr )
      *quadDepth = (float)(viewData->viewFwd.x * (float)((float)x - viewData->viewOrg.x))
                 + (float)((float)(viewData->viewFwd.z * (float)((float)z - viewData->viewOrg.z))
                         + (float)(viewData->viewFwd.y * (float)((float)y - viewData->viewOrg.y)));
  }
  else
  {
    __asm { vspltisw128 v63, 0 }
    __asm { vor128    v62, v95, v63 }
    _R9 = 16;
    __asm
    {
      vor128    v61, v95, v63
      vor128    v60, v95, v63
      vcmpequw128 v56, v95, v63
      vcmpequw128 v59, v94, v62
      stvx128   v62, r0, r31
      vcmpequw128 v58, v93, v61
      vcmpequw128 v57, v92, v60
      vsldoi128 v52, v95, v56, 4
      vsldoi128 v55, v94, v59, 4
      vsldoi128 v54, v93, v58, 4
      vsldoi128 v53, v92, v57, 4
      stvx128   v55, r31, r11
    }
    _R11 = _R31 + 1;
    __asm
    {
      stvx128   v61, r0, r11
      stvx128   v54, r11, r8
    }
    _R11 = _R31 + 2;
    __asm
    {
      stvx128   v60, r0, r11
      stvx128   v53, r11, r8
    }
    _R11 = _R31 + 3;
    __asm
    {
      stvx128   v63, r0, r11
      stvx128   v52, r11, r8
    }
    if ( quadDepth != nullptr )
    {
      *quadDepth = 0.0;
      return 4;
    }
  }
  return 4;
}


// ========================================================================
// ?GenFoliageForSubTree@@YAHPBUdeferredFoliageGenParms_t@@PBUfoliageIndex_t@@HH@Z
// EA  : 0x827D96F0
// RVA : 0x007D96F0
// PDB : w:\tech5\engine\models\foliage\jobs\foliagegen.cpp
// ========================================================================

int __fastcall GenFoliageForSubTree(
        const deferredFoliageGenParms_t *parms,
        const foliageIndex_t *foliageIndices,
        int numFoliage,
        int vertexOffset)
{
  const fm_subTreeData_t *subTreeData; // r11
  char *v8; // r21
  char *v9; // r20
  float *p_foliageBigFadeDistMax; // r27
  float *p_foliageSmallFadeDistMax; // r26
  float *p_foliageStartFadeDist; // r25
  const visibleInfluenceSpheres_t **p_visibleInfluenceSpheres; // r24
  float **p_quadDepths; // r23
  idTransparencyVert **p_verts; // r22
  int i; // r19
  const fm_foliage_t *v18; // r6
  int v19; // r3
  int v22; // ctr
  idTransparencyVert v27[8]; // [sp+80h] [-100h] BYREF

  subTreeData = parms->subTreeData;
  v8 = (char *)subTreeData + subTreeData->foliageOffset;
  v9 = (char *)subTreeData + subTreeData->attributeOffset;
  if ( numFoliage > 0 )
  {
    p_foliageBigFadeDistMax = &parms->foliageBigFadeDistMax;
    p_foliageSmallFadeDistMax = &parms->foliageSmallFadeDistMax;
    p_foliageStartFadeDist = &parms->foliageStartFadeDist;
    p_visibleInfluenceSpheres = &parms->visibleInfluenceSpheres;
    p_quadDepths = &parms->quadDepths;
    p_verts = &parms->verts;
    for ( i = numFoliage; i != 0; --i )
    {
      v18 = (const fm_foliage_t *)&v8[__ROL4__(foliageIndices->foliageIndex, 4)];
      v19 = BuildFoliageQuad(
              verts: v27,
              quadDepth: &(*p_quadDepths)[vertexOffset / 4],
              foliageIndex: foliageIndices->foliageIndex,
              foliage: v18,
              attribute: (const fm_attribute_t *)&v9[__ROL4__(v18->attribIdx, 5)],
              viewData: parms->viewData,
              influenceSpheres: (*p_visibleInfluenceSpheres)->spheres,
              foliageStartFadeDist: *p_foliageStartFadeDist,
              foliageSmallFadeDistMax: *p_foliageSmallFadeDistMax,
              foliageBigFadeDistMax: *p_foliageBigFadeDistMax);
      _R11 = (int)&(*p_verts)[vertexOffset];
      if ( v19 > 0 )
      {
        v22 = v19;
        _R8 = (char *)v27 - _R11;
        _R10 = (char *)v27[0].st1 - _R11;
        _R9 = 16;
        do
        {
          __asm
          {
            lvx128    v63, r8, r11
            stvx128   v63, r0, r11
            lvx128    v62, r10, r11
            stvx128   v62, r11, r9
          }
          _R11 += 32;
          --v22;
        }
        while ( v22 != 0 );
      }
      vertexOffset += v19;
      ++foliageIndices;
    }
  }
  return numFoliage;
}

