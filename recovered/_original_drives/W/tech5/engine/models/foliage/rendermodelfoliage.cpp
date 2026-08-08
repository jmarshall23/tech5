
// ========================================================================
// ??1idRenderModelFoliage@@MAA@XZ
// EA  : 0x827D9818
// RVA : 0x007D9818
// PDB : w:\tech5\engine\models\foliage\rendermodelfoliage.cpp
// ========================================================================

void __fastcall idRenderModelFoliage::~idRenderModelFoliage(idRenderModelFoliage *this)
{
  this->__vftable = (idRenderModelFoliage_vtbl *)&idRenderModelFoliage::`vftable';
  idMem::Free(this: &mem, ptr: this->foliageGatherParms, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->foliageGenParms, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: (void *)this->viewData, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->foliageIndices, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->influenceSphereIndices, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->subTreeFoliageCounts, align: ALIGN_16);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$229850
// EA  : 0x827D98B4
// RVA : 0x007D98B4
// PDB : w:\tech5\engine\models\foliage\rendermodelfoliage.cpp
// ========================================================================

void _unwind_229850()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 112 + 132));
}


// ========================================================================
// FoliageGatherJob
// EA  : 0x827D98E0
// RVA : 0x007D98E0
// PDB : w:\tech5\engine\models\foliage\rendermodelfoliage.cpp
// ========================================================================

void __fastcall FoliageGatherJob(const deferredFoliageGatherParms_t *parms, int a2, __int64 a3)
{
  int v3; // [sp+54h] [-Ch] BYREF

  HIDWORD(a3) = &v3;
  v3 = 0;
  GatherFoliageIndicesForSubTree(parms, numInfluenceSphereIndices: a3);
}


// ========================================================================
// ??0idRenderModelFoliage@@QAA@XZ
// EA  : 0x827D9920
// RVA : 0x007D9920
// PDB : w:\tech5\engine\models\foliage\rendermodelfoliage.cpp
// ========================================================================

idRenderModelFoliage *__fastcall idRenderModelFoliage::idRenderModelFoliage(idRenderModelFoliage *this)
{
  idRenderModel::idRenderModel(this);
  *((_BYTE *)&this->g + 105) |= 0xC4u;
  this->__vftable = (idRenderModelFoliage_vtbl *)&idRenderModelFoliage::`vftable';
  this->foliageBSP = nullptr;
  this->foliageGatherParms = (deferredFoliageGatherParms_t *)idMem::AllocWithLocation(
                                                               this: &mem,
                                                               location: "w:\\tech5\\engine\\models\\foliage\\RenderModelFoliage.cp"
                                                               "p(52) : TAG_FOLIAGE",
                                                               size: 0x2000u,
                                                               tag: TAG_FOLIAGE,
                                                               zeroBuffer: false,
                                                               align: ALIGN_16,
                                                               heap: HEAP_DEFAULTHEAP);
  this->foliageGenParms = (deferredFoliageGenParms_t *)idMem::AllocWithLocation(
                                                         this: &mem,
                                                         location: "w:\\tech5\\engine\\models\\foliage\\RenderModelFoliage.cpp(53) : TAG_FOLIAGE",
                                                         size: 0x28000u,
                                                         tag: TAG_FOLIAGE,
                                                         zeroBuffer: false,
                                                         align: ALIGN_16,
                                                         heap: HEAP_DEFAULTHEAP);
  this->viewData = (foliageRenderView_t *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\engine\\models\\foliage\\RenderModelFoliage.cpp(54) : TAG_FOLIAGE",
                                            size: 0x90u,
                                            tag: TAG_FOLIAGE,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
  this->foliageIndices = (foliageIndex_t *)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\engine\\models\\foliage\\RenderModelFoliage.cpp(55) : TAG_FOLIAGE",
                                             size: 0x20E00u,
                                             tag: TAG_FOLIAGE,
                                             zeroBuffer: false,
                                             align: ALIGN_16,
                                             heap: HEAP_DEFAULTHEAP);
  this->influenceSphereIndices = (__int16 *)idMem::AllocWithLocation(
                                              this: &mem,
                                              location: "w:\\tech5\\engine\\models\\foliage\\RenderModelFoliage.cpp(56) : TAG_FOLIAGE",
                                              size: 0x10700u,
                                              tag: TAG_FOLIAGE,
                                              zeroBuffer: false,
                                              align: ALIGN_16,
                                              heap: HEAP_DEFAULTHEAP);
  this->subTreeFoliageCounts = (foliageSubTreeStats_t *)idMem::AllocWithLocation(
                                                          this: &mem,
                                                          location: "w:\\tech5\\engine\\models\\foliage\\RenderModelFoliage.cpp(57) : TAG_FOLIAGE",
                                                          size: 0x800u,
                                                          tag: TAG_FOLIAGE,
                                                          zeroBuffer: false,
                                                          align: ALIGN_16,
                                                          heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// __unwind$230286
// EA  : 0x827D9A6C
// RVA : 0x007D9A6C
// PDB : w:\tech5\engine\models\foliage\rendermodelfoliage.cpp
// ========================================================================

void _unwind_230286()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 112 + 132));
}


// ========================================================================
// FoliageGenJob
// EA  : 0x827D9AF8
// RVA : 0x007D9AF8
// PDB : w:\tech5\engine\models\foliage\rendermodelfoliage.cpp
// ========================================================================

void __fastcall FoliageGenJob(const deferredFoliageGenParms_t *parms)
{
  int FoliageOffsetForSubTree; // r3
  const foliageIndex_t *foliageIndices; // r29
  int v4; // r30
  int numVertsAllocated; // r11
  int v6; // r5
  int v7; // r6
  int v8; // [sp+50h] [-30h] BYREF
  int v9; // [sp+54h] [-2Ch] BYREF

  if ( parms->quadsUsed != nullptr )
    *parms->quadsUsed = GetFoliageTotalCount(foliageCountsList: parms->foliageCountsList);
  FoliageOffsetForSubTree = GetFoliageOffsetForSubTree(
                              foliageCountsList: parms->foliageCountsList,
                              subTreeIndex: parms->foliageCountsIndex);
  foliageIndices = parms->foliageIndices;
  v4 = 4 * FoliageOffsetForSubTree;
  GetFoliageOffsetAndCountForJob(
    numJobs: parms->numJobsForIndices,
    jobIndex: parms->jobIndexForIndices,
    totalCount: parms->foliageCountsList[parms->foliageCountsIndex].subTreeFoliageCount,
    jobOffset: &v9,
    jobCount: &v8);
  numVertsAllocated = parms->numVertsAllocated;
  v6 = v8;
  v7 = 4 * v9 + v4;
  if ( v7 >= numVertsAllocated )
    v7 = parms->numVertsAllocated;
  if ( 4 * v8 + v7 > numVertsAllocated )
    v6 = __CFADD__(v8 - (4 * v8 - numVertsAllocated + v7) / 4, 0x80000000)
       ? 0
       : v8 - (4 * v8 - numVertsAllocated + v7) / 4;
  GenFoliageForSubTree(parms, foliageIndices: &foliageIndices[v9], numFoliage: v6, vertexOffset: v7);
}


// ========================================================================
// ?UpdateInView@idRenderModelFoliage@@EAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x827D9BD0
// RVA : 0x007D9BD0
// PDB : w:\tech5\engine\models\foliage\rendermodelfoliage.cpp
// ========================================================================

int __fastcall idRenderModelFoliage::UpdateInView(
        idRenderModelFoliage *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools,
        long double a5)
{
  unsigned __int64 v5; // r30
  idRenderModelUpdateTools *v7; // r24
  foliageRenderView_t *viewData; // r9
  __int64 v10; // r7
  idImageAtlas *transSortImageAtlas; // r5
  idCVar *v12; // r21
  long double v13; // fp2
  long double v14; // fp2
  int v15; // r11
  float *v16; // r11
  float *v17; // r11
  float *v18; // r11
  float *v19; // r11
  idRenderMatrix *v20; // r5
  idVec3 *v21; // r25
  idColor *v22; // r26
  int v23; // r10
  const fm_model_t *v24; // r15
  __int64 v25; // r18
  int v26; // r29
  const dm_subTreeData_t *data; // r28
  int v28; // r27
  const idColor *v29; // r11
  double v30; // fp9
  double v31; // fp10
  int v32; // r31
  __int128 v33; // r11
  idRenderWorld *World; // r3
  idRenderWorld *v35; // r3
  char *v36; // r9
  _WORD *v37; // r10
  int i; // ctr
  __int128 v39; // r6
  __int128 v40; // r11
  __int64 v41; // fp0
  __int64 v42; // fp10
  idRenderWorld *v43; // r3
  double v44; // fp13
  double v45; // fp12
  double v46; // fp11
  int FoliageSubTreesForView; // r28
  idRenderModelTransparency *transparencyModel; // r10
  signed int v49; // r8
  signed int v50; // r27
  deferredFoliageGatherParms_t *v51; // r31
  int v52; // r25
  int v53; // r23
  int v54; // r24
  int *v55; // r26
  int v56; // r20
  const foliageRenderView_t *v57; // r9
  int v58; // r29
  __int64 v59; // r6
  foliageIndex_t *v60; // r4
  deferredFoliageGenParms_t *v61; // r31
  int v62; // r10
  int v63; // r10
  fm_subTree_t *subTrees; // r11
  const foliageRenderView_t *v65; // r6
  fm_subTree_t *v66; // r11
  int v67; // r28
  int v68; // r6
  int v69; // r5
  double valueFloat; // fp0
  int valueInteger; // [sp+60h] [-1490h]
  int v72; // [sp+64h] [-148Ch]
  const visibleInfluenceSpheres_t *visibleInfluenceSpheres; // [sp+6Ch] [-1484h]
  char v74; // [sp+7Eh] [-1472h] BYREF
  dm_subTreeDataPtrs_t v75; // [sp+80h] [-1470h] BYREF
  __int16 v76; // [sp+88h] [-1468h]
  __int16 v77; // [sp+8Ah] [-1466h]
  __int16 v78; // [sp+8Ch] [-1464h]
  __int64 v79; // [sp+90h] [-1460h]
  dm_subTreeDataPtrs_t v80; // [sp+98h] [-1458h] BYREF
  float v81; // [sp+A0h] [-1450h]
  float v82; // [sp+A4h] [-144Ch]
  float v83; // [sp+A8h] [-1448h]
  float a; // [sp+ACh] [-1444h]
  __int64 v85; // [sp+B0h] [-1440h]
  float v86; // [sp+B8h] [-1438h]
  float v87; // [sp+BCh] [-1434h]
  float v88; // [sp+C0h] [-1430h]
  float v89; // [sp+C4h] [-142Ch]
  idCVar *v90; // [sp+C8h] [-1428h]
  float v91; // [sp+CCh] [-1424h]
  float v92; // [sp+D0h] [-1420h]
  float v93; // [sp+D4h] [-141Ch]
  float v94; // [sp+D8h] [-1418h]
  float v95; // [sp+DCh] [-1414h]
  float v96; // [sp+E0h] [-1410h]
  int *v97; // [sp+E4h] [-140Ch] BYREF
  idColor *v98; // [sp+E8h] [-1408h]
  idTransparencyVert *v99; // [sp+ECh] [-1404h] BYREF
  idVec3 *v100; // [sp+F0h] [-1400h]
  float *v101; // [sp+F4h] [-13FCh] BYREF
  __int64 v102; // [sp+F8h] [-13F8h]
  unsigned __int64 v103; // [sp+100h] [-13F0h]
  float v104; // [sp+120h] [-13D0h]
  float r; // [sp+124h] [-13CCh]
  __int64 v106; // [sp+128h] [-13C8h]
  float b; // [sp+130h] [-13C0h]
  float g; // [sp+134h] [-13BCh]
  idVec3 v109[2]; // [sp+138h] [-13B8h] BYREF
  float v110[4]; // [sp+170h] [-1380h] BYREF
  idBounds v111; // [sp+190h] [-1360h] BYREF
  float v112[4]; // [sp+1B0h] [-1340h] BYREF
  float v113[8]; // [sp+1D0h] [-1320h] BYREF
  idRenderMatrix projectionMatrix; // [sp+1F0h] [-1300h] BYREF
  int v115[128]; // [sp+230h] [-12C0h] BYREF

  LODWORD(v5) = this;
  v7 = updateTools;
  if ( r_skipFoliage.valueInteger != 0 || this->foliageBSP == nullptr )
    return 0;
  viewData = this->viewData;
  LODWORD(v10) = currentView->r.renderTime;
  HIDWORD(v10) = &renderLog.indentString[28];
  v106 = v10;
  transSortImageAtlas = globalImages->transSortImageAtlas;
  v12 = &r_foliageBigFadeDistMax;
  v90 = &r_foliageBigFadeDistMax;
  viewData->time = (float)v10 * (float)0.001;
  this->viewData->atlasWidth = transSortImageAtlas->ATLAS_WIDTH;
  this->viewData->atlasHeight = globalImages->transSortImageAtlas->ATLAS_HEIGHT;
  this->viewData->nearDist = r_znear.valueFloat;
  this->viewData->farDist = r_foliageBigFadeDistMax.valueFloat;
  *(double *)&a5 = (float)((float)(nextView->r.fov_x * idMath::M_DEG2RAD) * (float)0.5);
  v13 = tan(x: a5);
  *(float *)(*(_DWORD *)(v5 + 2044) + 12) = *(double *)&v13;
  *(double *)&v13 = (float)((float)(nextView->r.fov_y * idMath::M_DEG2RAD) * (float)0.5);
  v14 = tan(x: v13);
  v15 = *(_DWORD *)(v5 + 2044);
  LODWORD(v94) = &nextView->r.viewaxis;
  *(float *)(v15 + 16) = *(double *)&v14;
  v16 = *(float **)(v5 + 2044);
  v16[8] = nextView->r.viewaxis.mat[0].x;
  v16[9] = nextView->r.viewaxis.mat[0].y;
  v16[10] = nextView->r.viewaxis.mat[0].z;
  v17 = *(float **)(v5 + 2044);
  v17[11] = nextView->r.viewaxis.mat[1].x;
  v17[12] = nextView->r.viewaxis.mat[1].y;
  v17[13] = nextView->r.viewaxis.mat[1].z;
  v18 = *(float **)(v5 + 2044);
  v18[14] = nextView->r.viewaxis.mat[2].x;
  v18[15] = nextView->r.viewaxis.mat[2].y;
  v18[16] = nextView->r.viewaxis.mat[2].z;
  v19 = *(float **)(v5 + 2044);
  v19[5] = nextView->r.vieworg.x;
  v19[6] = nextView->r.vieworg.y;
  v19[7] = nextView->r.vieworg.z;
  projectionMatrix = nextView->projectionMatrix;
  v20 = (idRenderMatrix *)(*(_DWORD *)(v5 + 2044) + 68);
  projectionMatrix.m[10] = -(float)((float)(r_foliageBigFadeDistMax.valueFloat + r_znear.valueFloat)
                                  / (float)(r_foliageBigFadeDistMax.valueFloat - r_znear.valueFloat));
  projectionMatrix.m[11] = -(float)((float)((float)(r_foliageBigFadeDistMax.valueFloat * r_znear.valueFloat) * (float)2.0)
                                  / (float)(r_foliageBigFadeDistMax.valueFloat - r_znear.valueFloat));
  idRenderMatrix::Multiply(a: &projectionMatrix, b: &nextView->viewMatrix, out: v20);
  HIDWORD(v5) = &r_showFoliageSubTreeNodes;
  v21 = &vec3_origin;
  LODWORD(v92) = &r_showFoliageSubTreeNodes;
  v100 = &vec3_origin;
  v22 = &idColor::colorGreen;
  HIDWORD(v106) = &idColor::colorYellow;
  v98 = &idColor::colorGreen;
  v23 = *(_DWORD *)(v5 + 2032);
  v24 = (const fm_model_t *)(v23 + 36);
  LODWORD(v96) = v23 + 36;
  if ( r_showFoliageSubTreeNodes.valueInteger >= 0
    && r_showFoliageSubTreeNodes.valueInteger < *(_DWORD *)(v23 + 40)
    && idRenderModel::GetWorld(this: (idRenderModel *)v5) != nullptr )
  {
    if ( (_S13_20 & 1) == 0 )
    {
      r = idColor::colorMagenta.r;
      _S13_20 |= 1u;
      colors[1] = idColor::colorRed;
      colors[0] = idColor::colorWhite;
      colors[2] = idColor::colorGreen;
      colors[3] = idColor::colorBlue;
      v80.detail = (dm_detail_t *)LODWORD(idColor::colorBrown.r);
      *(float *)&v85 = idColor::colorLtGrey.r;
      *(float *)&v79 = idColor::colorBrown.g;
      v104 = idColor::colorPink.r;
      g = idColor::colorPink.g;
      b = idColor::colorPink.b;
      v75.detail = (dm_detail_t *)LODWORD(idColor::colorLtGrey.g);
      colors[4] = idColor::colorYellow;
      v95 = idColor::colorOrange.r;
      v87 = idColor::colorOrange.g;
      v91 = idColor::colorOrange.b;
      a = idColor::colorOrange.a;
      v83 = idColor::colorPurple.r;
      *(float *)&v25 = idColor::colorCyan.g;
      v89 = idColor::colorDkGrey.b;
      v81 = idColor::colorCyan.a;
      v88 = idColor::colorOrange.a;
      v24 = (const fm_model_t *)LODWORD(v96);
      v96 = idColor::colorOrange.r;
      v86 = idColor::colorPurple.r;
      LODWORD(v25) = 0;
      v94 = idColor::colorOrange.g;
      v82 = idColor::colorPink.a;
      colors[5] = idColor::colorMagenta;
      colors[8].b = idColor::colorPurple.b;
      v5 = __PAIR64__(LODWORD(v92), (unsigned int)this);
      v102 = v25;
      colors[9] = idColor::colorPink;
      v103 = __PAIR64__(LODWORD(v92), (unsigned int)this);
      v92 = idColor::colorOrange.b;
      colors[6] = idColor::colorCyan;
      colors[7] = idColor::colorOrange;
      v93 = idColor::colorBrown.a;
      v22 = v98;
      v21 = v100;
      v7 = updateTools;
      v12 = v90;
      colors[8].g = idColor::colorPurple.g;
      colors[8].r = idColor::colorPurple.r;
      colors[8].a = idColor::colorPurple.a;
      colors[10] = idColor::colorBrown;
      colors[11] = idColor::colorLtGrey;
      colors[12] = idColor::colorMdGrey;
      colors[13] = idColor::colorDkGrey;
    }
    v26 = *(_DWORD *)(HIDWORD(v5) + 32);
    data = (const dm_subTreeData_t *)v24->subTrees[v26].data;
    SetupSubTreePtrsFromTreeNodes(subTreePtrs: &v75, subTree: data);
    v28 = 0;
    v111.b[0].z = 1.0e30;
    v111.b[0].y = 1.0e30;
    v111.b[0].x = 1.0e30;
    v111.b[1].z = -1.0e30;
    v111.b[1].y = v111.b[1].z;
    v111.b[1].x = v111.b[1].z;
    v29 = &colors[v26 % 14];
    v30 = v29->b;
    v110[0] = v29->r;
    v110[2] = v30;
    v31 = v29->g;
    v110[3] = v29->a;
    v110[1] = v31;
    if ( data->numDetail > 0 )
    {
      v32 = 0;
      do
      {
        HIDWORD(v33) = (unsigned __int16)v75.detail->xyz[v32];
        LODWORD(v33) = v75.detail->xyz[v32 + 2];
        DWORD2(v33) = v75.detail->xyz[v32 + 1];
        DWORD1(v33) = SWORD1(v33);
        v85 = v33;
        v79 = *(_QWORD *)((char *)&v33 + 4);
        v80 = *(dm_subTreeDataPtrs_t *)&v33;
        v109[0].z = (float)(__int64)v33;
        v109[0].x = (float)*(__int64 *)&v33;
        v109[0].y = (float)*(__int64 *)((char *)&v33 + 4);
        idBounds::AddPoint(this: &v111, v: v109);
        World = idRenderModel::GetWorld(this: (idRenderModel *)v5);
        World->DebugPoint(this: World, a2: (const idVec4 *)v110, a3: v109, a4: 0, a5: true);
        ++v28;
        v32 += 8;
      }
      while ( v28 < data->numDetail );
    }
    v35 = idRenderModel::GetWorld(this: (idRenderModel *)v5);
    v35->DebugBounds(this: v35, a2: (const idVec4 *)v110, a3: &v111, a4: v21, a5: 0, a6: false);
  }
  if ( r_showFoliageSubTreeBounds.valueInteger >= 0 && r_showFoliageSubTreeBounds.valueInteger < v24->numSubTrees )
  {
    v36 = &v74;
    v37 = (_WORD *)&v24->subTrees[r_showFoliageSubTreeBounds.valueInteger - 1].data + 1;
    for ( i = 8; i != 0; --i )
    {
      ++v37;
      v36 += 2;
      *(_WORD *)v36 = *v37;
    }
    HIDWORD(v39) = v5;
    DWORD2(v39) = v78;
    LODWORD(v40) = SHIWORD(v75.attributes);
    DWORD1(v40) = HIWORD(v75.detail);
    DWORD1(v39) = LOWORD(v75.detail);
    DWORD2(v40) = v76;
    v41 = *(_QWORD *)((char *)&v39 + 4);
    LODWORD(v39) = SHIWORD(v75.detail);
    v85 = v39;
    v42 = v39;
    DWORD2(v39) = v77;
    DWORD1(v39) = SLOWORD(v75.detail);
    v75 = *(dm_subTreeDataPtrs_t *)((char *)&v40 + 4);
    v80 = *(dm_subTreeDataPtrs_t *)((char *)&v39 + 4);
    v79 = *(_QWORD *)&v39;
    v113[2] = (float)(__int64)v40;
    v113[3] = (float)*(__int64 *)((char *)&v40 + 4);
    v113[0] = (float)v42;
    v113[5] = (float)v41;
    v113[4] = (float)*(__int64 *)((char *)&v39 + 4);
    v113[1] = (float)*(__int64 *)&v39;
    v43 = idRenderModel::GetWorld(this: (idRenderModel *)v5);
    v44 = v22->g;
    v45 = v22->b;
    v46 = v22->a;
    v112[0] = v22->r;
    v112[1] = v44;
    v112[2] = v45;
    v112[3] = v46;
    v43->DebugBounds(this: v43, a2: (const idVec4 *)v112, a3: (const idBounds *)v113, a4: v21, a5: 0, a6: false);
  }
  FoliageSubTreesForView = idFoliageModel::GetFoliageSubTreesForView(
                             model: v24,
                             viewData: *(const foliageRenderView_t **)(v5 + 2044),
                             subTreeNums: v115);
  v72 = FoliageSubTreesForView;
  if ( FoliageSubTreesForView == 0 )
    return 0;
  v99 = nullptr;
  v101 = nullptr;
  v97 = nullptr;
  if ( !idRenderModelTransparency::AllocateQuadSegment(
          numQuads: 4096,
          verts: &v99,
          quadDepths: &v101,
          quadsUsed: &v97,
          hasEmissivePass: false) )
    return 0;
  transparencyModel = v7->transparencyModel;
  v49 = (FoliageSubTreesForView + 3) & 0xFFFFFFFC;
  __twllei(v49, 0);
  v50 = (0x8000 / v49 + 7) & 0xFFFFFFF8;
  visibleInfluenceSpheres = transparencyModel->visibleInfluenceSpheres;
  if ( v50 >= 4096 )
    v50 = 4096;
  memset(Dst: *(void **)(v5 + 2056), Val: -1, Size: 0x800u);
  valueInteger = r_useFoliageGenJobs.valueInteger;
  v51 = *(deferredFoliageGatherParms_t **)(v5 + 2036);
  if ( FoliageSubTreesForView > 0 )
  {
    v52 = 0;
    v53 = 0;
    v54 = 0;
    HIDWORD(v85) = "%d, %d, %d - %.2f";
    v55 = v115;
    v56 = FoliageSubTreesForView;
    do
    {
      v57 = *(const foliageRenderView_t **)(v5 + 2044);
      v58 = (int)&v24->subTrees[*v55];
      v51->subTreeBounds = (const fm_subTreeBounds_t *)v58;
      v51->viewData = v57;
      v51->visibleInfluenceSpheres = visibleInfluenceSpheres;
      v51->subTreeTreeNodes = *(const fm_subTreeTreeNodes_t **)(v58 + 24);
      LODWORD(v59) = *(unsigned __int16 *)(v58 + 18);
      v51->subTreeTreeNodesSize = v59;
      v51->foliageCount = (foliageSubTreeStats_t *)(v52 + *(_DWORD *)(v5 + 2056));
      v60 = (foliageIndex_t *)(v54 + *(_DWORD *)(v5 + 2048));
      v51->maxFoliageIndices = v50;
      v51->foliageIndices = v60;
      v51->influenceSphereIndices = (__int16 *)(v53 + *(_DWORD *)(v5 + 2052));
      v51->maxInfluenceSphereIndices = v50;
      v51->maxFoliageHeight = *(unsigned __int16 *)(v58 + 16);
      v51->foliageStartFadeDist = r_foliageStartFadeDist.valueFloat;
      v51->foliageSmallFadeDistMax = r_foliageSmallFadeDistMax.valueFloat;
      if ( r_showFoliageNodeBounds.valueInteger != 0 )
      {
        HIDWORD(v59) = &v75;
        v75.detail = nullptr;
        GatherFoliageIndicesForSubTree(parms: v51, numInfluenceSphereIndices: v59);
        SetupSubTreePtrsFromTreeNodes(subTreePtrs: &v80, subTree: *(const dm_subTreeData_t **)(v58 + 28));
        FoliageSubTreesForView = v72;
        v12 = v90;
      }
      if ( valueInteger == 1 )
      {
        idParallelJobList::AddJob(
          this: updateTools->transparencyJobList,
          function: (void (__fastcall *)(void *))FoliageGatherJob,
          data: v51);
      }
      else
      {
        HIDWORD(v79) = 0;
        HIDWORD(v59) = &v75;
        v75.detail = nullptr;
        GatherFoliageIndicesForSubTree(parms: v51, numInfluenceSphereIndices: v59);
      }
      --v56;
      v54 += 4 * v50;
      ++v51;
      ++v55;
      v52 += 16;
      v53 += 2 * v50;
    }
    while ( v56 != 0 );
    v7 = updateTools;
  }
  idParallelJobList::InsertSyncPoint(this: v7->transparencyJobList, syncType: SYNC_SIGNAL);
  idParallelJobList::InsertSyncPoint(this: v7->transparencyJobList, syncType: SYNC_SYNCHRONIZE);
  HIDWORD(v5) = 0;
  v61 = *(deferredFoliageGenParms_t **)(v5 + 2040);
  if ( FoliageSubTreesForView > 0 )
  {
    v62 = 0;
    do
    {
      v63 = v115[v62];
      subTrees = v24->subTrees;
      v65 = *(const foliageRenderView_t **)(v5 + 2044);
      v61->visibleInfluenceSpheres = visibleInfluenceSpheres;
      v61->viewData = v65;
      v66 = &subTrees[v63];
      v61->subTreeBounds = &v66->bounds;
      v67 = 1;
      v61->subTreeData = v66->data;
      v61->subTreeDataSize = v66->totalDataSize;
      v68 = 4 * HIDWORD(v5) * v50 + *(_DWORD *)(v5 + 2048);
      v61->maxFoliageIndices = v50;
      v61->foliageIndices = (const foliageIndex_t *)v68;
      v69 = 2 * HIDWORD(v5) * v50 + *(_DWORD *)(v5 + 2052);
      v61->maxInfluenceSphereIndices = v50;
      v61->influenceSphereIndices = (const __int16 *)v69;
      v61->numJobsForIndices = 16;
      v61->jobIndexForIndices = 0;
      v61->foliageCountsList = *(const foliageSubTreeStats_t **)(v5 + 2056);
      v61->foliageCountsIndex = HIDWORD(v5);
      v61->foliageStartFadeDist = r_foliageStartFadeDist.valueFloat;
      v61->foliageSmallFadeDistMax = r_foliageSmallFadeDistMax.valueFloat;
      valueFloat = v12->valueFloat;
      v61->numVertsAllocated = 0x4000;
      v61->foliageBigFadeDistMax = valueFloat;
      v61->verts = v99;
      v61->quadDepths = v101;
      for ( v61->quadsUsed = HIDWORD(v5) != 0 ? nullptr : v97; ; v61->quadsUsed = nullptr )
      {
        if ( valueInteger == 1 )
          idParallelJobList::AddJob(
            this: v7->transparencyJobList,
            function: (void (__fastcall *)(void *))FoliageGenJob,
            data: v61);
        else
          FoliageGenJob(parms: v61);
        ++v61;
        if ( v67 >= 16 )
          break;
        memcpy(Dst: v61, Src: &v61[-1], Size: sizeof(deferredFoliageGenParms_t));
        v61->jobIndexForIndices = v67++;
      }
      v62 = ++HIDWORD(v5);
    }
    while ( SHIDWORD(v5) < v72 );
  }
  return 1;
}


// ========================================================================
// `dynamic initializer for 'r_useFoliageGenJobs''
// EA  : 0x83342D30
// RVA : 0x01342D30
// PDB : w:\tech5\engine\models\foliage\rendermodelfoliage.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useFoliageGenJobs__()
{
  idCVar::idCVar(
    this: &r_useFoliageGenJobs,
    name: "r_useFoliageGenJobs",
    value: "1",
    flags: 2,
    description: "0 = off, 1 = threaded",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)byte_821B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useFoliageGenJobs__);
}


// ========================================================================
// `dynamic initializer for 'r_showFoliageNodeBounds''
// EA  : 0x83342D98
// RVA : 0x01342D98
// PDB : w:\tech5\engine\models\foliage\rendermodelfoliage.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showFoliageNodeBounds__()
{
  idCVar::idCVar(
    this: &r_showFoliageNodeBounds,
    name: "r_showFoliageNodeBounds",
    value: "0",
    flags: 2,
    description: "show the individual foliage bounds - 0 = off, 1 = just the bounds, 2 = bounds + position and size",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showFoliageNodeBounds__);
}


// ========================================================================
// `dynamic initializer for 'r_showFoliageSubTreeNodes''
// EA  : 0x83342DF0
// RVA : 0x01342DF0
// PDB : w:\tech5\engine\models\foliage\rendermodelfoliage.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showFoliageSubTreeNodes__()
{
  idCVar::idCVar(
    this: &r_showFoliageSubTreeNodes,
    name: "r_showFoliageSubTreeNodes",
    value: "-1",
    flags: 2,
    description: "show the nodes of the specified subtree",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showFoliageSubTreeNodes__);
}


// ========================================================================
// `dynamic initializer for 'r_showFoliageSubTreeBounds''
// EA  : 0x83342E48
// RVA : 0x01342E48
// PDB : w:\tech5\engine\models\foliage\rendermodelfoliage.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showFoliageSubTreeBounds__()
{
  idCVar::idCVar(
    this: &r_showFoliageSubTreeBounds,
    name: "r_showFoliageSubTreeBounds",
    value: "-1",
    flags: 2,
    description: "show the bounds of the specified subtree",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showFoliageSubTreeBounds__);
}


// ========================================================================
// `dynamic initializer for 'register_FoliageGatherJob''
// EA  : 0x83342EA0
// RVA : 0x01342EA0
// PDB : w:\tech5\engine\models\foliage\rendermodelfoliage.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_FoliageGatherJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_FoliageGatherJob,
           function: (void (__fastcall *)(void *))FoliageGatherJob,
           name: "FoliageGatherJob");
}


// ========================================================================
// `dynamic initializer for 'register_FoliageGenJob''
// EA  : 0x83342EC0
// RVA : 0x01342EC0
// PDB : w:\tech5\engine\models\foliage\rendermodelfoliage.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_FoliageGenJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_FoliageGenJob,
           function: (void (__fastcall *)(void *))FoliageGenJob,
           name: "FoliageGenJob");
}

