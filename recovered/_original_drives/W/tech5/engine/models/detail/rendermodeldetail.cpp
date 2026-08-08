
// ========================================================================
// ??1idRenderModelDetail@@MAA@XZ
// EA  : 0x827CDBE0
// RVA : 0x007CDBE0
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

void __fastcall idRenderModelDetail::~idRenderModelDetail(idRenderModelDetail *this)
{
  int v2; // r28
  idIndexBuffer *indexBuffers; // r29

  this->__vftable = (idRenderModelDetail_vtbl *)&idRenderModelDetail::`vftable';
  if ( this->deferredVerts != nullptr )
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&this->vertexBuffers[this->currentIndex]);
  if ( this->deferredIndices != nullptr )
    idIndexBuffer::UnmapBuffer(this: &this->indexBuffers[this->currentIndex]);
  v2 = 3;
  indexBuffers = this->indexBuffers;
  do
  {
    idVertexBuffer::FreeBufferObject(this: (idVertexBuffer *)&indexBuffers[-3]);
    idIndexBuffer::FreeBufferObject(this: indexBuffers);
    --v2;
    ++indexBuffers;
  }
  while ( v2 != 0 );
  idMem::Free(this: &mem, ptr: this->detailGatherParms, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->detailGenParms, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: (void *)this->viewData, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->detailIndices, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->subTreeDetailCounts, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->totalsUsed, align: ALIGN_16);
  `eh vector destructor iterator'(
    ptr: this->indexBuffers,
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idIndexBuffer::~idIndexBuffer);
  `eh vector destructor iterator'(
    ptr: this->vertexBuffers,
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$230568
// EA  : 0x827CDD14
// RVA : 0x007CDD14
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

void _unwind_230568()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$230569
// EA  : 0x827CDD3C
// RVA : 0x007CDD3C
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

void _unwind_230569()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 2064),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$230570
// EA  : 0x827CDD78
// RVA : 0x007CDD78
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

void _unwind_230570()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 2112),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idIndexBuffer::~idIndexBuffer);
}


// ========================================================================
// DetailGatherJob
// EA  : 0x827CDDB8
// RVA : 0x007CDDB8
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

void __fastcall DetailGatherJob(__int64 parms)
{
  int v1; // [sp+50h] [-10h] BYREF

  LODWORD(parms) = &v1;
  v1 = 0;
  GatherDetailIndicesForSubTree(numDetailIndices: parms);
}


// ========================================================================
// DetailGenJob
// EA  : 0x827CDDE8
// RVA : 0x007CDDE8
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

void __fastcall DetailGenJob(const deferredDetailGenParms_t *parms)
{
  detailGenTotals_t *totalsUsed; // r4
  int detailCountsIndex; // r4
  const detailSubTreeStats_t *detailCountsList; // r3
  int numVertsAllocated; // r11
  const detailSubTreeStats_t *v6; // r10
  int v7; // [sp+50h] [-30h] BYREF
  int v8[3]; // [sp+54h] [-2Ch] BYREF
  dm_attribute_t v9; // [sp+60h] [-20h] BYREF

  totalsUsed = parms->totalsUsed;
  if ( totalsUsed != nullptr )
    GetDetailTotalCount(detailCountsList: parms->detailCountsList, totalsCount: totalsUsed);
  detailCountsIndex = parms->detailCountsIndex;
  detailCountsList = parms->detailCountsList;
  v7 = 0;
  v8[0] = 0;
  GetDetailOffsetsForSubTree(detailCountsList, subTreeIndex: detailCountsIndex, vertCount: &v7, indexCount: v8);
  numVertsAllocated = parms->numVertsAllocated;
  v6 = &parms->detailCountsList[parms->detailCountsIndex];
  if ( v6->vertCount + v7 <= numVertsAllocated && v6->indexCount + v8[0] <= 6 * numVertsAllocated )
    GenDetailForSubTree(
      parms,
      detailIndices: parms->detailIndices,
      numDetail: v6->subTreeDetailCount,
      vertexBufferOffset: v7,
      indexBufferOffset: v8[0],
      indexOffset: v7,
      totals: &v9);
}


// ========================================================================
// ??0idRenderModelDetail@@QAA@XZ
// EA  : 0x827CDF10
// RVA : 0x007CDF10
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

idRenderModelDetail *__fastcall idRenderModelDetail::idRenderModelDetail(idRenderModelDetail *this)
{
  idVertexBuffer *vertexBuffers; // r28
  int v3; // r27
  idTriangles *v4; // r3
  idTriangles *v5; // r28
  const idMaterial *detailMaterial; // r9
  idRenderModel *v8; // [sp+70h] [-70h]

  idRenderModel::idRenderModel(this);
  this->detailBSP = nullptr;
  this->__vftable = (idRenderModelDetail_vtbl *)&idRenderModelDetail::`vftable';
  vertexBuffers = this->vertexBuffers;
  `eh vector constructor iterator'(
    ptr: this->vertexBuffers,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  `eh vector constructor iterator'(
    ptr: this->indexBuffers,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idIndexBuffer::~idIndexBuffer);
  v3 = 3;
  *((_BYTE *)&this->g + 105) |= 0xC4u;
  do
  {
    idIndexBuffer::AllocBufferObject(
      this: (idIndexBuffer *)&vertexBuffers[3],
      data: nullptr,
      allocSize: 196608,
      allocUsage: BU_DYNAMIC);
    idVertexBuffer::AllocBufferObject(
      this: vertexBuffers,
      data: nullptr,
      allocSize: 0x80000,
      vertexMask: 31,
      allocUsage: BU_DYNAMIC);
    --v3;
    ++vertexBuffers;
  }
  while ( v3 != 0 );
  this->currentIndex = 0;
  this->deferredVerts = nullptr;
  this->deferredIndices = nullptr;
  this->detailMaterial = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                               this: &idMaterial::resourceList,
                                               name: "genericDetailVmtr",
                                               makeDefault: true);
  v4 = (idTriangles *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x84u,
                        tag: TAG_TRIANGLES,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idTriangles::idTriangles(this: v4);
  else
    v5 = nullptr;
  v5->bounds.b[0].z = -99999.0;
  v5->bounds.b[0].y = -99999.0;
  v5->bounds.b[0].x = -99999.0;
  v5->bounds.b[1].z = 99999.0;
  v5->bounds.b[1].y = 99999.0;
  v5->bounds.b[1].x = 99999.0;
  detailMaterial = this->detailMaterial;
  v5->numVerts = 0;
  v5->numIndexes = 0;
  v8 = (idRenderModel *)detailMaterial;
  idVertexBuffer::Reference(this: &v5->vertexBuffer, other: &this->vertexBuffers[2]);
  idIndexBuffer::Reference(this: &v5->indexBuffer, other: &this->indexBuffers[2]);
  idRenderModel::AddSurface(this: v8, surf: nullptr);
  this->detailGatherParms = (deferredDetailGatherParms_t *)idMem::AllocWithLocation(
                                                             this: &mem,
                                                             location: "w:\\tech5\\engine\\models\\detail\\RenderModelDetail.cpp(84) : TAG_DETAIL",
                                                             size: 0x1000u,
                                                             tag: TAG_DETAIL,
                                                             zeroBuffer: false,
                                                             align: ALIGN_16,
                                                             heap: HEAP_DEFAULTHEAP);
  this->detailGenParms = (deferredDetailGenParms_t *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\engine\\models\\detail\\RenderModelDetail.cpp(85) : TAG_DETAIL",
                                                       size: 0x50000u,
                                                       tag: TAG_DETAIL,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
  this->viewData = (detailRenderView_t *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\engine\\models\\detail\\RenderModelDetail.cpp(86) : TAG_DETAIL",
                                           size: 0x90u,
                                           tag: TAG_DETAIL,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
  this->detailIndices = (unsigned __int16 *)idMem::AllocWithLocation(
                                              this: &mem,
                                              location: "w:\\tech5\\engine\\models\\detail\\RenderModelDetail.cpp(87) : TAG_DETAIL",
                                              size: 0x8700u,
                                              tag: TAG_DETAIL,
                                              zeroBuffer: false,
                                              align: ALIGN_16,
                                              heap: HEAP_DEFAULTHEAP);
  this->subTreeDetailCounts = (detailSubTreeStats_t *)idMem::AllocWithLocation(
                                                        this: &mem,
                                                        location: "w:\\tech5\\engine\\models\\detail\\RenderModelDetail.cpp(88) : TAG_DETAIL",
                                                        size: 0x800u,
                                                        tag: TAG_DETAIL,
                                                        zeroBuffer: false,
                                                        align: ALIGN_16,
                                                        heap: HEAP_DEFAULTHEAP);
  this->totalsUsed = (detailGenTotals_t *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\engine\\models\\detail\\RenderModelDetail.cpp(89) : TAG_DETAIL",
                                            size: 0x10u,
                                            tag: TAG_DETAIL,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// __unwind$230952
// EA  : 0x827CE1E8
// RVA : 0x007CE1E8
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

void _unwind_230952()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 224 + 244));
}


// ========================================================================
// __unwind$230953
// EA  : 0x827CE210
// RVA : 0x007CE210
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

void _unwind_230953()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 224 + 244) + 2064),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$230954
// EA  : 0x827CE24C
// RVA : 0x007CE24C
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

void _unwind_230954()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 224 + 244) + 2112),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idIndexBuffer::~idIndexBuffer);
}


// ========================================================================
// __unwind$230955
// EA  : 0x827CE288
// RVA : 0x007CE288
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

void _unwind_230955()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 224 + 96), tag: TAG_TRIANGLES);
}


// ========================================================================
// ?UpdateInView@idRenderModelDetail@@EAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x827CE2B8
// RVA : 0x007CE2B8
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

int __fastcall idRenderModelDetail::UpdateInView(
        idRenderModelDetail *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools)
{
  idRenderModelUpdateTools *v7; // r28
  int v8; // r9
  int v9; // r10
  idRenderModelSurface *v10; // r11
  int v12; // r11
  idPixelUnpackBuffer *v13; // r3
  idIndexBuffer *v14; // r3
  idRenderModelSurface *list; // r27
  idTriangles *geometry; // r10
  int v17; // r11
  __int64 v18; // r4
  long double v19; // fp2
  long double v20; // fp2
  long double v21; // fp2
  detailRenderView_t *viewData; // r11
  detailRenderView_t *v23; // r11
  detailRenderView_t *v24; // r11
  detailRenderView_t *v25; // r11
  dm_model_t *p_detailModelData; // r18
  int DetailSubTreesForView; // r15
  detailSubTreeStats_t *subTreeDetailCounts; // r3
  signed int v29; // r8
  int valueInteger; // r7
  unsigned int v31; // r21
  deferredDetailGatherParms_t *detailGatherParms; // r30
  int v33; // r23
  int v34; // r22
  int *v35; // r24
  int v36; // r17
  detailRenderView_t *v37; // r9
  int v38; // r29
  unsigned __int16 *v39; // r5
  __int64 v40; // r4
  int v41; // r29
  int v42; // r28
  __int64 v43; // r8
  const dm_detail_t *v44; // r3
  idRenderWorld *World; // r3
  __int64 v46; // r4
  int v47; // r29
  int v48; // r24
  deferredDetailGenParms_t *detailGenParms; // r30
  int v50; // r10
  int v51; // r11
  dm_subTree_t *subTrees; // r9
  dm_subTree_t *v53; // r11
  unsigned __int16 *detailIndices; // r11
  detailGenTotals_t *totalsUsed; // r11
  int i; // r28
  int v57; // [sp+50h] [-2E0h] BYREF
  int v58; // [sp+54h] [-2DCh]
  __int64 v59; // [sp+58h] [-2D8h] BYREF
  float v60[4]; // [sp+60h] [-2D0h] BYREF
  idBounds v61; // [sp+70h] [-2C0h] BYREF
  int v62[128]; // [sp+90h] [-2A0h] BYREF

  v7 = updateTools;
  if ( r_skipDetailModels.valueInteger != 0 )
  {
    v8 = 0;
    if ( this->surfaces.num > 0 )
    {
      v9 = 0;
      do
      {
        ++v8;
        v10 = &this->surfaces.list[v9++];
        v10->geometry->numVerts = 0;
        v10->geometry->numIndexes = 0;
        v10->material = nullptr;
      }
      while ( v8 < this->surfaces.num );
    }
    return 0;
  }
  if ( this->detailBSP == nullptr )
    return 0;
  if ( this->deferredVerts != nullptr )
  {
    v12 = 16 * (this->currentIndex + 129);
    v13 = (idPixelUnpackBuffer *)((char *)this + v12);
    if ( *(int *)((char *)&this->__vftable + v12) < 0 )
      idVertexBuffer::UnmapBuffer(this: v13);
  }
  if ( this->deferredIndices != nullptr )
  {
    v14 = &this->indexBuffers[this->currentIndex];
    if ( v14->size < 0 )
      idIndexBuffer::UnmapBuffer(this: v14);
  }
  list = this->surfaces.list;
  geometry = list->geometry;
  list->material = this->detailMaterial;
  geometry->numVerts = this->totalsUsed->totalVerts;
  list->geometry->numIndexes = this->totalsUsed->totalIndices;
  idVertexBuffer::Reference(this: &list->geometry->vertexBuffer, other: &this->vertexBuffers[this->currentIndex]);
  idIndexBuffer::Reference(this: &list->geometry->indexBuffer, other: &this->indexBuffers[this->currentIndex]);
  v17 = (this->currentIndex + 1) % 3;
  this->currentIndex = v17;
  this->deferredVerts = (idDrawVert *)idVertexBuffer::MapBuffer(
                                        this: &this->vertexBuffers[v17],
                                        mapType: BM_WRITE_NOSYNC);
  HIDWORD(v18) = idIndexBuffer::MapBuffer(this: &this->indexBuffers[this->currentIndex], mapType: BM_WRITE_NOSYNC);
  this->deferredIndices = (unsigned __int16 *)HIDWORD(v18);
  LODWORD(v18) = currentView->r.renderTime;
  v59 = v18;
  this->viewData->time = (float)v18 * (float)0.001;
  this->viewData->nearDist = r_znear.valueFloat;
  this->viewData->farDist = r_detailFadeDistMax.valueFloat;
  *(double *)&v19 = (float)((float)(nextView->r.fov_x * idMath::M_DEG2RAD) * (float)0.5);
  v20 = tan(x: v19);
  this->viewData->fov[0] = *(double *)&v20;
  *(double *)&v20 = (float)((float)(nextView->r.fov_y * idMath::M_DEG2RAD) * (float)0.5);
  v21 = tan(x: v20);
  this->viewData->fov[1] = *(double *)&v21;
  viewData = this->viewData;
  viewData->viewOrg.x = nextView->r.vieworg.x;
  viewData->viewOrg.y = nextView->r.vieworg.y;
  viewData->viewOrg.z = nextView->r.vieworg.z;
  v23 = this->viewData;
  v23->viewFwd.x = nextView->r.viewaxis.mat[0].x;
  v23->viewFwd.y = nextView->r.viewaxis.mat[0].y;
  v23->viewFwd.z = nextView->r.viewaxis.mat[0].z;
  v24 = this->viewData;
  v24->viewLeft.x = nextView->r.viewaxis.mat[1].x;
  v24->viewLeft.y = nextView->r.viewaxis.mat[1].y;
  v24->viewLeft.z = nextView->r.viewaxis.mat[1].z;
  v25 = this->viewData;
  v25->viewUp.x = nextView->r.viewaxis.mat[2].x;
  v25->viewUp.y = nextView->r.viewaxis.mat[2].y;
  v25->viewUp.z = nextView->r.viewaxis.mat[2].z;
  idRenderMatrix::Multiply(a: &nextView->projectionMatrix, b: &nextView->viewMatrix, out: &this->viewData->mvpMatrix);
  p_detailModelData = &this->detailBSP->detailModelData;
  DetailSubTreesForView = idDetailModel::GetDetailSubTreesForView(
                            model: p_detailModelData,
                            viewData: this->viewData,
                            subTreeNums: v62);
  if ( DetailSubTreesForView == 0 )
    return 0;
  subTreeDetailCounts = this->subTreeDetailCounts;
  v29 = (DetailSubTreesForView + 3) & 0xFFFFFFFC;
  valueInteger = r_useDetailGenJobs.valueInteger;
  __twllei(v29, 0);
  v31 = (0x4000 / v29 + 7) & 0xFFFFFFF8;
  v58 = valueInteger;
  memset(Dst: subTreeDetailCounts, Val: -1, Size: 0x800u);
  detailGatherParms = this->detailGatherParms;
  if ( DetailSubTreesForView > 0 )
  {
    v33 = 0;
    v34 = 0;
    v35 = v62;
    v36 = DetailSubTreesForView;
    do
    {
      v37 = this->viewData;
      v38 = (int)&p_detailModelData->subTrees[*v35];
      detailGatherParms->subTreeBounds = (const dm_subTreeBounds_t *)v38;
      detailGatherParms->viewData = v37;
      detailGatherParms->subTreeTreeNodes = *(const dm_subTreeTreeNodes_t **)(v38 + 24);
      detailGatherParms->subTreeTreeNodesSize = *(unsigned __int16 *)(v38 + 18);
      detailGatherParms->detailCount = &this->subTreeDetailCounts[v33];
      v39 = &this->detailIndices[v34];
      detailGatherParms->maxDetailIndices = v31;
      detailGatherParms->detailIndices = v39;
      detailGatherParms->maxDetailHeight = *(unsigned __int16 *)(v38 + 16);
      if ( r_showDetailNodeBounds.valueInteger != 0 )
      {
        v57 = 0;
        LODWORD(v40) = &v57;
        HIDWORD(v40) = detailGatherParms;
        GatherDetailIndicesForSubTree(numDetailIndices: v40);
        SetupSubTreePtrsFromTreeNodes(
          subTreePtrs: (dm_subTreeDataPtrs_t *)&v59,
          subTree: *(const dm_subTreeData_t **)(v38 + 28));
        v41 = 0;
        if ( v57 > 0 )
        {
          v42 = 0;
          do
          {
            LODWORD(v43) = HIDWORD(v59);
            HIDWORD(v43) = detailGatherParms->detailIndices[v42];
            v44 = (const dm_detail_t *)(__ROL4__(HIDWORD(v43), 5) + HIDWORD(v59));
            CalculateDetailBounds(
              detail: v44,
              data: *(const idDetailPaletteData **)((char *)idDetailModelData::palette.list
                                            + __ROL4__(*(unsigned __int16 *)(__ROL4__(v44->attribIdx, 5) + v59 + 2), 2)),
              bounds: &v61,
              a4: v43);
            World = idRenderModel::GetWorld(this);
            v60[0] = idColor::colorCyan.r;
            v60[1] = idColor::colorCyan.g;
            v60[2] = idColor::colorCyan.b;
            v60[3] = idColor::colorCyan.a;
            World->DebugBounds(this: World, a2: (const idVec4 *)v60, a3: &v61, a4: &vec3_origin, a5: 0, a6: true);
            ++v41;
            ++v42;
          }
          while ( v41 < v57 );
          v7 = updateTools;
        }
      }
      if ( v58 == 1 )
      {
        idParallelJobList::AddJob(
          this: v7->renderModelJobList,
          function: (void (__fastcall *)(void *))DetailGatherJob,
          data: detailGatherParms);
      }
      else
      {
        v57 = 0;
        LODWORD(v46) = &v57;
        HIDWORD(v46) = detailGatherParms;
        GatherDetailIndicesForSubTree(numDetailIndices: v46);
      }
      --v36;
      ++detailGatherParms;
      ++v35;
      ++v33;
      v34 += v31;
    }
    while ( v36 != 0 );
  }
  idParallelJobList::InsertSyncPoint(this: v7->renderModelJobList, syncType: SYNC_SIGNAL);
  idParallelJobList::InsertSyncPoint(this: v7->renderModelJobList, syncType: SYNC_SYNCHRONIZE);
  v47 = 0;
  v48 = r_detailGenJobsPerSubTree.valueInteger;
  detailGenParms = this->detailGenParms;
  if ( DetailSubTreesForView > 0 )
  {
    v50 = 0;
    do
    {
      v51 = v62[v50];
      subTrees = p_detailModelData->subTrees;
      detailGenParms->viewData = this->viewData;
      v53 = &subTrees[v51];
      detailGenParms->subTreeBounds = &v53->bounds;
      detailGenParms->subTreeData = v53->data;
      detailGenParms->subTreeDataSize = v53->totalDataSize;
      detailIndices = this->detailIndices;
      detailGenParms->maxDetailIndices = v31;
      detailGenParms->numJobsForIndices = v48;
      detailGenParms->jobIndexForIndices = 0;
      detailGenParms->detailIndices = &detailIndices[v47 * v31];
      detailGenParms->detailCountsList = this->subTreeDetailCounts;
      detailGenParms->numVertsAllocated = 0x4000;
      detailGenParms->detailCountsIndex = v47;
      detailGenParms->verts = this->deferredVerts;
      detailGenParms->indices = this->deferredIndices;
      detailGenParms->paletteEntries = idDetailModel::paletteEntries.list;
      detailGenParms->paletteEntriesSize = 8 * idDetailModel::paletteEntries.size;
      detailGenParms->paletteIndices = idDetailModel::paletteIndices.list;
      detailGenParms->paletteIndicesSize = 2 * idDetailModel::paletteIndices.size;
      detailGenParms->paletteVerts = idDetailModel::paletteVerts.list;
      detailGenParms->paletteVertsSize = 10 * idDetailModel::paletteVerts.size;
      if ( v47 != 0 )
        totalsUsed = nullptr;
      else
        totalsUsed = this->totalsUsed;
      detailGenParms->totalsUsed = totalsUsed;
      for ( i = 1; ; ++i )
      {
        if ( v58 == 1 )
          idParallelJobList::AddJob(
            this: updateTools->renderModelJobList,
            function: (void (__fastcall *)(void *))DetailGenJob,
            data: detailGenParms);
        else
          DetailGenJob(parms: detailGenParms);
        ++detailGenParms;
        if ( i >= v48 )
          break;
        memcpy(Dst: detailGenParms, Src: &detailGenParms[-1], Size: sizeof(deferredDetailGenParms_t));
        detailGenParms->jobIndexForIndices = i;
        detailGenParms->totalsUsed = nullptr;
      }
      v50 = ++v47;
    }
    while ( v47 < DetailSubTreesForView );
  }
  return 1;
}


// ========================================================================
// `dynamic initializer for 'r_useDetailGenJobs''
// EA  : 0x83342678
// RVA : 0x01342678
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useDetailGenJobs__()
{
  idCVar::idCVar(
    this: &r_useDetailGenJobs,
    name: "r_useDetailGenJobs",
    value: "1",
    flags: 2,
    description: "0 = off, 1 = threaded",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)byte_821B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useDetailGenJobs__);
}


// ========================================================================
// `dynamic initializer for 'r_detailGenJobsPerSubTree''
// EA  : 0x833426E0
// RVA : 0x013426E0
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_detailGenJobsPerSubTree__()
{
  idCVar::idCVar(
    this: &r_detailGenJobsPerSubTree,
    name: "r_detailGenJobsPerSubTree",
    value: "1",
    flags: 2,
    description: &byte_8200D768,
    valueMin: 1.0,
    valueMax: 32.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)off_82010000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_detailGenJobsPerSubTree__);
}


// ========================================================================
// `dynamic initializer for 'r_showDetailNodeBounds''
// EA  : 0x83342748
// RVA : 0x01342748
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showDetailNodeBounds__()
{
  idCVar::idCVar(
    this: &r_showDetailNodeBounds,
    name: "r_showDetailNodeBounds",
    value: "0",
    flags: 1,
    description: "show the individual detail model bounds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showDetailNodeBounds__);
}


// ========================================================================
// `dynamic initializer for 'register_DetailGatherJob''
// EA  : 0x833427A0
// RVA : 0x013427A0
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_DetailGatherJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_DetailGatherJob,
           function: (void (__fastcall *)(void *))DetailGatherJob,
           name: "DetailGatherJob");
}


// ========================================================================
// `dynamic initializer for 'register_DetailGenJob''
// EA  : 0x833427C0
// RVA : 0x013427C0
// PDB : w:\tech5\engine\models\detail\rendermodeldetail.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_DetailGenJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_DetailGenJob,
           function: (void (__fastcall *)(void *))DetailGenJob,
           name: "DetailGenJob");
}

