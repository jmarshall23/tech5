
// ========================================================================
// ??1idRenderModelTransparency@@MAA@XZ
// EA  : 0x8288B870
// RVA : 0x0088B870
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __fastcall idRenderModelTransparency::~idRenderModelTransparency(idRenderModelTransparency *this)
{
  this->__vftable = (idRenderModelTransparency_vtbl *)&idRenderModelTransparency::`vftable';
  idMem::Free(this: &mem, ptr: this->sortParms, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->sortResult, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->influenceSpheres[0], align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->influenceSpheres[1], align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->visibleInfluenceSpheres, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->influenceSphereCullParms, align: ALIGN_16);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$229870
// EA  : 0x8288B90C
// RVA : 0x0088B90C
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void _unwind_229870()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 112 + 132));
}


// ========================================================================
// ?AllocateQuadSegment@idRenderModelTransparency@@SA_NHAAPAVidTransparencyVert@@AAPAMAAPAH_N@Z
// EA  : 0x8288B938
// RVA : 0x0088B938
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

int __fastcall idRenderModelTransparency::AllocateQuadSegment(
        const int numQuads,
        idTransparencyVert **verts,
        float **quadDepths,
        int **quadsUsed,
        bool hasEmissivePass)
{
  if ( (idRenderModelTransparency::numVertsAllocated >> 2) + numQuads >= MAX_TRANSPARENCY_QUADS
    || idRenderModelTransparency::numSegmentAllocations >= 1023 )
  {
    return 0;
  }
  idRenderModelTransparency::segmentInfo[idRenderModelTransparency::numSegmentAllocations].quadsAllocated = numQuads;
  idRenderModelTransparency::segmentInfo[idRenderModelTransparency::numSegmentAllocations].segmentOffset = idRenderModelTransparency::numVertsAllocated >> 2;
  idRenderModelTransparency::segmentInfo[idRenderModelTransparency::numSegmentAllocations].emissivePass = hasEmissivePass;
  *verts = &idRenderModelTransparency::mappedVerts[idRenderModelTransparency::numVertsAllocated];
  *quadDepths = &idRenderModelTransparency::currentQuadDepths[idRenderModelTransparency::numVertsAllocated >> 2];
  *quadsUsed = &idRenderModelTransparency::segmentInfo[idRenderModelTransparency::numSegmentAllocations++].quadsUsed;
  idRenderModelTransparency::numVertsAllocated += 4 * numQuads;
  return 1;
}


// ========================================================================
// ?AllocateUnsortedQuadSegment@idRenderModelTransparency@@SA_NHAAPAVidTransparencyVert@@AAH1@Z
// EA  : 0x8288BA30
// RVA : 0x0088BA30
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

int __fastcall idRenderModelTransparency::AllocateUnsortedQuadSegment(
        const int numQuads,
        idTransparencyVert **verts,
        int *indexOffset,
        int *vertCount)
{
  if ( (idRenderModelTransparency::numVertsAllocatedUnsorted >> 2) + numQuads >= 4096 )
    return 0;
  *verts = &idRenderModelTransparency::mappedVertsUnsorted[idRenderModelTransparency::numVertsAllocatedUnsorted];
  *indexOffset = 6 * (idRenderModelTransparency::numVertsAllocatedUnsorted >> 2);
  *vertCount = 4 * numQuads;
  idRenderModelTransparency::numVertsAllocatedUnsorted += 4 * numQuads;
  return 1;
}


// ========================================================================
// TransparencySortJob
// EA  : 0x8288BA98
// RVA : 0x0088BA98
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __fastcall TransparencySortJob(
        const transSortParms_t *parms,
        int a2,
        __int64 a3,
        unsigned __int8 *a4,
        int a5,
        unsigned __int64 a6)
{
  TransparencySortQuads(parms, a2, a3, emissiveQuads: a4, a5, a6);
  TransparencyTriIndGen(parms, quadOffset: 0);
  TransparencyEmissiveTriIndGen(parms, quadOffset: 0);
}


// ========================================================================
// ?ClearInfluenceSpheres@idRenderModelTransparency@@QAAXXZ
// EA  : 0x8288BAE0
// RVA : 0x0088BAE0
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __fastcall idRenderModelTransparency::ClearInfluenceSpheres(idRenderModelTransparency *this)
{
  this->numInfluenceSpheres[this->currentSphereIndex] = 0;
}


// ========================================================================
// ?Shutdown@idRenderModelTransparency@@SAXXZ
// EA  : 0x8288BAF8
// RVA : 0x0088BAF8
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

static void __fastcall idRenderModelTransparency::Shutdown()
{
  idPixelUnpackBuffer *v0; // r3
  idIndexBuffer *v1; // r3
  idIndexBuffer *v2; // r3
  int i; // r31
  idPixelUnpackBuffer *v4; // r3
  idVertexBuffer *v5; // r31

  if ( !idLib::headless )
  {
    if ( idRenderModelTransparency::mappedVerts != nullptr )
    {
      v0 = (idPixelUnpackBuffer *)&idRenderModelTransparency::vertexBuffer[idRenderModelTransparency::mappedBufferIndex];
      if ( v0->size < 0 )
        idVertexBuffer::UnmapBuffer(this: v0);
    }
    if ( idRenderModelTransparency::mappedIndices != nullptr )
    {
      v1 = &idRenderModelTransparency::indexBuffer[idRenderModelTransparency::mappedBufferIndex];
      if ( v1->size < 0 )
        idIndexBuffer::UnmapBuffer(this: v1);
    }
    if ( idRenderModelTransparency::mappedIndices2 != nullptr )
    {
      v2 = &idRenderModelTransparency::indexBuffer2[idRenderModelTransparency::mappedBufferIndex];
      if ( v2->size < 0 )
        idIndexBuffer::UnmapBuffer(this: v2);
    }
    for ( i = 0; i < 3; ++i )
    {
      idVertexBuffer::FreeBufferObject(this: &idRenderModelTransparency::vertexBuffer[i]);
      idIndexBuffer::FreeBufferObject(this: &idRenderModelTransparency::indexBuffer[i]);
      idIndexBuffer::FreeBufferObject(this: &idRenderModelTransparency::indexBuffer2[i]);
    }
    if ( idRenderModelTransparency::mappedVertsUnsorted != nullptr )
    {
      v4 = (idPixelUnpackBuffer *)&idRenderModelTransparency::vertexBufferUnsorted[idRenderModelTransparency::mappedBufferIndex];
      if ( v4->size < 0 )
        idVertexBuffer::UnmapBuffer(this: v4);
    }
    v5 = idRenderModelTransparency::vertexBufferUnsorted;
    do
      idVertexBuffer::FreeBufferObject(this: v5++);
    while ( (int)v5 < (int)&idRenderModelTransparency::indexBufferUnsorted );
    idIndexBuffer::FreeBufferObject(this: &idRenderModelTransparency::indexBufferUnsorted);
  }
  if ( idRenderModelTransparency::currentQuadDepths != nullptr )
    idMem::Free(this: &mem, ptr: idRenderModelTransparency::currentQuadDepths, align: ALIGN_16);
  if ( idRenderModelTransparency::currentEmissiveQuads != nullptr )
    idMem::Free(this: &mem, ptr: idRenderModelTransparency::currentEmissiveQuads, align: ALIGN_16);
  if ( idRenderModelTransparency::segmentInfo != nullptr )
    idMem::Free(this: &mem, ptr: idRenderModelTransparency::segmentInfo, align: ALIGN_16);
  if ( idRenderModelTransparency::binVerts != nullptr )
    idMem::Free(this: &mem, ptr: idRenderModelTransparency::binVerts, align: ALIGN_16);
  if ( idRenderModelTransparency::binIndices != nullptr )
    idMem::Free(this: &mem, ptr: idRenderModelTransparency::binIndices, align: ALIGN_16);
  idRenderModelTransparency::currentQuadDepths = nullptr;
  idRenderModelTransparency::currentEmissiveQuads = nullptr;
  idRenderModelTransparency::segmentInfo = nullptr;
  idRenderModelTransparency::binVerts = nullptr;
  idRenderModelTransparency::binIndices = nullptr;
}


// ========================================================================
// ??0idRenderModelTransparency@@QAA@XZ
// EA  : 0x8288BD10
// RVA : 0x0088BD10
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

idRenderModelTransparency *__fastcall idRenderModelTransparency::idRenderModelTransparency(
        idRenderModelTransparency *this)
{
  idTriangles *v2; // r3
  idTriangles *v3; // r28
  idTriangles *v4; // r3
  idTriangles *v5; // r28
  __int64 v7; // [sp+8h] [-108h]
  __int64 v8; // [sp+8h] [-108h]
  __int64 v9; // [sp+10h] [-100h]
  __int64 v10; // [sp+10h] [-100h]
  __int64 v11; // [sp+18h] [-F8h]
  __int64 v12; // [sp+18h] [-F8h]
  __int64 v13; // [sp+20h] [-F0h]
  __int64 v14; // [sp+20h] [-F0h]
  __int64 v15; // [sp+28h] [-E8h]
  __int64 v16; // [sp+28h] [-E8h]
  __int64 v17; // [sp+30h] [-E0h]
  __int64 v18; // [sp+30h] [-E0h]
  __int64 v19; // [sp+38h] [-D8h]
  __int64 v20; // [sp+38h] [-D8h]
  __int64 v21; // [sp+40h] [-D0h]
  __int64 v22; // [sp+40h] [-D0h]
  __int64 v23; // [sp+48h] [-C8h]
  __int64 v24; // [sp+48h] [-C8h]
  __int64 v25; // [sp+50h] [-C0h]
  __int64 v26; // [sp+50h] [-C0h]
  __int64 v27; // [sp+A0h] [-70h]
  __int64 v28; // [sp+A0h] [-70h]

  idRenderModel::idRenderModel(this);
  *((_BYTE *)&this->g + 105) |= 0xC4u;
  this->__vftable = (idRenderModelTransparency_vtbl *)&idRenderModelTransparency::`vftable';
  v2 = (idTriangles *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x84u,
                        tag: TAG_TRIANGLES,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idTriangles::idTriangles(this: v2);
  else
    v3 = nullptr;
  v3->bounds.b[0].z = -99999.0;
  v3->bounds.b[0].y = -99999.0;
  v3->bounds.b[0].x = -99999.0;
  v3->bounds.b[1].z = 99999.0;
  v3->bounds.b[1].y = 99999.0;
  v3->bounds.b[1].x = 99999.0;
  idVertexBuffer::Reference(this: &v3->vertexBuffer, other: &idRenderModelTransparency::vertexBuffer[2]);
  idIndexBuffer::Reference(this: &v3->indexBuffer, other: &idRenderModelTransparency::indexBuffer[2]);
  v3->vertexMask = 3167;
  *((float *)&v27 + 1) = 0.0;
  *(float *)&v27 = 0.0;
  idRenderModel::AddSurface(
    this,
    surf: nullptr,
    a3: __SPAIR64__((unsigned int)v3, 0),
    a4: COERCE_UNSIGNED_INT(0.0),
    a5: v27,
    a6: v7,
    a7: v9,
    a8: v11,
    a9: v13,
    a10: v15,
    a11: v17,
    a12: v19,
    a13: v21,
    a14: v23,
    a15: v25);
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
  idVertexBuffer::Reference(this: &v5->vertexBuffer, other: &idRenderModelTransparency::vertexBuffer[2]);
  idIndexBuffer::Reference(this: &v5->indexBuffer, other: &idRenderModelTransparency::indexBuffer2[2]);
  v5->vertexMask = 3167;
  *((float *)&v28 + 1) = 0.0;
  *(float *)&v28 = 0.0;
  idRenderModel::AddSurface(
    this,
    surf: nullptr,
    a3: __SPAIR64__((unsigned int)v5, 0),
    a4: COERCE_UNSIGNED_INT(0.0),
    a5: v28,
    a6: v8,
    a7: v10,
    a8: v12,
    a9: v14,
    a10: v16,
    a11: v18,
    a12: v20,
    a13: v22,
    a14: v24,
    a15: v26);
  this->sortParms = (transSortParms_t *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\engine\\models\\transparency\\RenderModelTransparency.cpp(244) : TAG_TRANSPARENCY",
                                          size: 0x30u,
                                          tag: TAG_TRANSPARENCY,
                                          zeroBuffer: true,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
  this->sortResult = (transSortResult_t *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\engine\\models\\transparency\\RenderModelTransparency.cpp(245) : "
                                            "TAG_TRANSPARENCY",
                                            size: 0x10u,
                                            tag: TAG_TRANSPARENCY,
                                            zeroBuffer: true,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
  this->influenceSpheres[0] = (influenceSphere_t *)idMem::AllocWithLocation(
                                                     this: &mem,
                                                     location: "w:\\tech5\\engine\\models\\transparency\\RenderModelTransparency.cp"
                                                     "p(248) : TAG_TRANSPARENCY",
                                                     size: 0x6000u,
                                                     tag: TAG_TRANSPARENCY,
                                                     zeroBuffer: false,
                                                     align: ALIGN_16,
                                                     heap: HEAP_DEFAULTHEAP);
  this->influenceSpheres[1] = (influenceSphere_t *)idMem::AllocWithLocation(
                                                     this: &mem,
                                                     location: "w:\\tech5\\engine\\models\\transparency\\RenderModelTransparency.cp"
                                                     "p(249) : TAG_TRANSPARENCY",
                                                     size: 0x6000u,
                                                     tag: TAG_TRANSPARENCY,
                                                     zeroBuffer: false,
                                                     align: ALIGN_16,
                                                     heap: HEAP_DEFAULTHEAP);
  this->visibleInfluenceSpheres = (visibleInfluenceSpheres_t *)idMem::AllocWithLocation(
                                                                 this: &mem,
                                                                 location: "w:\\tech5\\engine\\models\\transparency\\RenderModelTra"
                                                                 "nsparency.cpp(250) : TAG_TRANSPARENCY",
                                                                 size: 0x1810u,
                                                                 tag: TAG_TRANSPARENCY,
                                                                 zeroBuffer: true,
                                                                 align: ALIGN_16,
                                                                 heap: HEAP_DEFAULTHEAP);
  this->influenceSphereCullParms = (influenceSphereCullParms_t *)idMem::AllocWithLocation(
                                                                   this: &mem,
                                                                   location: "w:\\tech5\\engine\\models\\transparency\\RenderModelT"
                                                                   "ransparency.cpp(251) : TAG_TRANSPARENCY",
                                                                   size: 0x4Cu,
                                                                   tag: TAG_TRANSPARENCY,
                                                                   zeroBuffer: true,
                                                                   align: ALIGN_16,
                                                                   heap: HEAP_DEFAULTHEAP);
  this->numInfluenceSpheres[0] = 0;
  this->numInfluenceSpheres[1] = 0;
  this->currentSphereIndex = 0;
  return this;
}


// ========================================================================
// __unwind$230204_0
// EA  : 0x8288C054
// RVA : 0x0088C054
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void _unwind_230204_0()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 272 + 292));
}


// ========================================================================
// __unwind$230205_0
// EA  : 0x8288C07C
// RVA : 0x0088C07C
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void _unwind_230205_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 272 + 96), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$230206_0
// EA  : 0x8288C0A8
// RVA : 0x0088C0A8
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void _unwind_230206_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 272 + 96), tag: TAG_TRIANGLES);
}


// ========================================================================
// ?GenerateVisibleInfluenceSphereList@idRenderModelTransparency@@QAAXPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x8288C138
// RVA : 0x0088C138
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __fastcall idRenderModelTransparency::GenerateVisibleInfluenceSphereList(
        idRenderModelTransparency *this,
        const idRenderView *currentRenderView,
        const idRenderView *nextRenderView,
        idRenderModelUpdateTools *updateTools,
        long double a5)
{
  int v8; // r27
  int v9; // r28
  visibleInfluenceSpheres_t *visibleInfluenceSpheres; // r11
  float *v11; // r29
  double v12; // fp0
  double v13; // fp28
  double v14; // fp0
  double v15; // fp30
  double v16; // fp0
  double v17; // fp31
  idRenderWorldLocal *World; // r3
  double v19; // fp0
  long double v20; // fp2
  long double v21; // fp2
  influenceSphereCullParms_t *influenceSphereCullParms; // r11
  influenceSphereCullParms_t *v23; // r11
  influenceSphereCullParms_t *v24; // r11
  influenceSphereCullParms_t *v25; // r11
  float v26[4]; // [sp+50h] [-A0h] BYREF
  float v27[20]; // [sp+60h] [-90h] BYREF

  if ( r_showVisibleInfluenceSpheres.valueInteger != 0 )
  {
    v8 = 0;
    if ( this->visibleInfluenceSpheres->numSpheres > 0 )
    {
      v9 = 0;
      do
      {
        visibleInfluenceSpheres = this->visibleInfluenceSpheres;
        v11 = (float *)((char *)&visibleInfluenceSpheres->numSpheres + v9 * 24);
        v12 = (float)(visibleInfluenceSpheres->spheres[v9].angle * (float)0.022222223);
        if ( v12 >= 0.0 )
        {
          if ( v12 <= 1.0 )
            v13 = (float)(visibleInfluenceSpheres->spheres[v9].angle * (float)0.022222223);
          else
            v13 = 1.0;
        }
        else
        {
          v13 = 0.0;
        }
        v14 = (float)(visibleInfluenceSpheres->spheres[v9].angle * (float)-0.022222223);
        if ( v14 >= 0.0 )
        {
          if ( v14 <= 1.0 )
            v15 = (float)(visibleInfluenceSpheres->spheres[v9].angle * (float)-0.022222223);
          else
            v15 = 1.0;
        }
        else
        {
          v15 = 0.0;
        }
        v16 = (float)((float)((float)0.5 - (float)v13) - (float)v15);
        if ( v16 >= 0.0 )
        {
          if ( v16 <= 1.0 )
            v17 = (float)((float)((float)0.5 - (float)v13) - (float)v15);
          else
            v17 = 1.0;
        }
        else
        {
          v17 = 0.0;
        }
        World = idRenderModel::GetWorld(this);
        v19 = v11[8];
        v26[0] = v11[4];
        v26[1] = v11[5];
        v26[2] = v11[6];
        v26[3] = v19;
        v27[0] = v13;
        v27[1] = v17;
        v27[2] = v15;
        v27[3] = 1.0;
        World->DebugSphere(this: World, a2: (const idVec4 *)v27, a3: (const idSphere *)v26, a4: 12, a5: 0, a6: false);
        ++v8;
        ++v9;
      }
      while ( v8 < this->visibleInfluenceSpheres->numSpheres );
    }
  }
  if ( r_useInfluenceSpheres.valueInteger != 0 )
  {
    this->influenceSphereCullParms->nearDist = r_znear.valueFloat;
    this->influenceSphereCullParms->farDist = r_foliageBigFadeDistMax.valueFloat;
    *(double *)&a5 = (float)((float)(nextRenderView->r.fov_x * idMath::M_DEG2RAD) * (float)0.5);
    v20 = tan(x: a5);
    this->influenceSphereCullParms->fov.x = *(double *)&v20;
    *(double *)&v20 = (float)((float)(nextRenderView->r.fov_y * idMath::M_DEG2RAD) * (float)0.5);
    v21 = tan(x: v20);
    this->influenceSphereCullParms->fov.y = *(double *)&v21;
    influenceSphereCullParms = this->influenceSphereCullParms;
    influenceSphereCullParms->viewFwd.x = nextRenderView->r.viewaxis.mat[0].x;
    influenceSphereCullParms->viewFwd.y = nextRenderView->r.viewaxis.mat[0].y;
    influenceSphereCullParms->viewFwd.z = nextRenderView->r.viewaxis.mat[0].z;
    v23 = this->influenceSphereCullParms;
    v23->viewLeft.x = nextRenderView->r.viewaxis.mat[1].x;
    v23->viewLeft.y = nextRenderView->r.viewaxis.mat[1].y;
    v23->viewLeft.z = nextRenderView->r.viewaxis.mat[1].z;
    v24 = this->influenceSphereCullParms;
    v24->viewUp.x = nextRenderView->r.viewaxis.mat[2].x;
    v24->viewUp.y = nextRenderView->r.viewaxis.mat[2].y;
    v24->viewUp.z = nextRenderView->r.viewaxis.mat[2].z;
    v25 = this->influenceSphereCullParms;
    v25->viewOrg.x = nextRenderView->r.vieworg.x;
    v25->viewOrg.y = nextRenderView->r.vieworg.y;
    v25->viewOrg.z = nextRenderView->r.vieworg.z;
    this->influenceSphereCullParms->influenceSpheres = this->influenceSpheres[this->currentSphereIndex];
    this->influenceSphereCullParms->numInfluenceSpheres = this->numInfluenceSpheres[this->currentSphereIndex];
    this->influenceSphereCullParms->visibleInfluenceSpheres = this->visibleInfluenceSpheres;
    this->currentSphereIndex ^= 1u;
    if ( r_useInfluenceSphereCullJob.valueInteger == 1 )
      idParallelJobList::AddJob(
        this: updateTools->transparencyJobList,
        function: (void (__fastcall *)(void *))CullInfluenceSpheresForView,
        data: this->influenceSphereCullParms);
    else
      CullInfluenceSpheresForView(parms: this->influenceSphereCullParms);
    idParallelJobList::InsertSyncPoint(this: updateTools->transparencyJobList, syncType: SYNC_SIGNAL);
    idParallelJobList::InsertSyncPoint(this: updateTools->transparencyJobList, syncType: SYNC_SYNCHRONIZE);
  }
  else
  {
    this->visibleInfluenceSpheres->numSpheres = 0;
    this->visibleInfluenceSpheres->numSpheres = 0;
    this->visibleInfluenceSpheres->numSpheres = 0;
    this->visibleInfluenceSpheres->numSpheres = 0;
  }
}


// ========================================================================
// ?StartFrame@idRenderModelTransparency@@SAXXZ
// EA  : 0x8288C470
// RVA : 0x0088C470
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

static void __fastcall idRenderModelTransparency::StartFrame()
{
  idPixelUnpackBuffer *v0; // r3
  idIndexBuffer *v1; // r3
  idIndexBuffer *v2; // r3
  idPixelUnpackBuffer *v3; // r3
  idTransparencyVert *v4; // r11
  unsigned __int16 *v5; // r3

  idRenderModelTransparency::numVertsAllocated = 0;
  idRenderModelTransparency::numSegmentAllocations = 0;
  idRenderModelTransparency::numVertsAllocatedUnsorted = 0;
  if ( idRenderModelTransparency::mappedVerts != nullptr )
  {
    v0 = (idPixelUnpackBuffer *)&idRenderModelTransparency::vertexBuffer[idRenderModelTransparency::mappedBufferIndex];
    if ( v0->size < 0 )
      idVertexBuffer::UnmapBuffer(this: v0);
  }
  if ( idRenderModelTransparency::mappedIndices != nullptr )
  {
    v1 = &idRenderModelTransparency::indexBuffer[idRenderModelTransparency::mappedBufferIndex];
    if ( v1->size < 0 )
      idIndexBuffer::UnmapBuffer(this: v1);
  }
  if ( idRenderModelTransparency::mappedIndices2 != nullptr )
  {
    v2 = &idRenderModelTransparency::indexBuffer2[idRenderModelTransparency::mappedBufferIndex];
    if ( v2->size < 0 )
      idIndexBuffer::UnmapBuffer(this: v2);
  }
  if ( idRenderModelTransparency::mappedVertsUnsorted != nullptr )
  {
    v3 = (idPixelUnpackBuffer *)&idRenderModelTransparency::vertexBufferUnsorted[idRenderModelTransparency::mappedBufferIndex];
    if ( v3->size < 0 )
      idVertexBuffer::UnmapBuffer(this: v3);
  }
  idRenderModelTransparency::mappedBufferIndex = (idRenderModelTransparency::mappedBufferIndex + 1) % 3;
  if ( r_useTransparencyBinning.valueInteger != 0 )
  {
    v4 = idRenderModelTransparency::binVerts;
    if ( idRenderModelTransparency::binVerts == nullptr )
    {
      v4 = (idTransparencyVert *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\engine\\models\\transparency\\RenderModelTransparency.cpp(472) : TAG_TRANSPARENCY",
                                   size: 32 * MAX_TRANSPARENCY_VERTS,
                                   tag: TAG_TRANSPARENCY,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
      idRenderModelTransparency::binVerts = v4;
    }
    v5 = idRenderModelTransparency::binIndices;
    if ( idRenderModelTransparency::binIndices == nullptr )
    {
      v5 = (unsigned __int16 *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\engine\\models\\transparency\\RenderModelTransparency.cpp(475) : TAG_TRANSPARENCY",
                                 size: 2 * MAX_TRANSPARENCY_INDICES,
                                 tag: TAG_TRANSPARENCY,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
      v4 = idRenderModelTransparency::binVerts;
      idRenderModelTransparency::binIndices = v5;
    }
    idRenderModelTransparency::mappedVerts = v4;
    idRenderModelTransparency::mappedIndices = v5;
  }
  else
  {
    idRenderModelTransparency::mappedVerts = (idTransparencyVert *)idVertexBuffer::MapBuffer(
                                                                     this: &idRenderModelTransparency::vertexBuffer[idRenderModelTransparency::mappedBufferIndex],
                                                                     mapType: BM_WRITE_NOSYNC);
    idRenderModelTransparency::mappedIndices = (unsigned __int16 *)idIndexBuffer::MapBuffer(
                                                                     this: &idRenderModelTransparency::indexBuffer[idRenderModelTransparency::mappedBufferIndex],
                                                                     mapType: BM_WRITE_NOSYNC);
    idRenderModelTransparency::mappedIndices2 = (unsigned __int16 *)idIndexBuffer::MapBuffer(
                                                                      this: &idRenderModelTransparency::indexBuffer2[idRenderModelTransparency::mappedBufferIndex],
                                                                      mapType: BM_WRITE_NOSYNC);
  }
  idRenderModelTransparency::mappedVertsUnsorted = (idTransparencyVert *)idVertexBuffer::MapBuffer(
                                                                           this: &idRenderModelTransparency::vertexBufferUnsorted[idRenderModelTransparency::mappedBufferIndex],
                                                                           mapType: BM_WRITE_NOSYNC);
}


// ========================================================================
// ?AddTransparencySortJob@idRenderModelTransparency@@QAAXPAVidRenderModelUpdateTools@@@Z
// EA  : 0x8288C6C8
// RVA : 0x0088C6C8
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __fastcall idRenderModelTransparency::AddTransparencySortJob(
        idRenderModelTransparency *this,
        idRenderModelUpdateTools *updateTools)
{
  int v4; // r10
  unsigned __int64 v5; // r10
  __int64 v6; // r6
  int v7; // r4
  transSortParms_t *sortParms; // r31

  this->sortParms->collapse = 0;
  this->sortParms->sort = r_useTransparencySort.valueInteger != 0;
  this->sortParms->numSegmentAllocations = idRenderModelTransparency::numSegmentAllocations;
  this->sortParms->segmentInfo = idRenderModelTransparency::segmentInfo;
  this->sortParms->verts = idRenderModelTransparency::mappedVerts;
  this->sortParms->numQuadsToSort = idRenderModelTransparency::numVertsAllocated >> 2;
  v4 = MAX_TRANSPARENCY_INDICES;
  this->sortParms->quadDepths = idRenderModelTransparency::currentQuadDepths;
  this->sortParms->sortResult = this->sortResult;
  this->sortParms->maxIndices = v4;
  this->sortParms->indices = idRenderModelTransparency::mappedIndices;
  this->sortParms->maxIndices2 = 3072;
  this->sortParms->indices2 = idRenderModelTransparency::mappedIndices2;
  memset(Dst: idRenderModelTransparency::currentEmissiveQuads, Val: 0, Size: MAX_TRANSPARENCY_QUADS);
  this->sortParms->emissiveQuads = idRenderModelTransparency::currentEmissiveQuads;
  idParallelJobList::InsertSyncPoint(this: updateTools->transparencyJobList, syncType: SYNC_SIGNAL);
  idParallelJobList::InsertSyncPoint(this: updateTools->transparencyJobList, syncType: SYNC_SYNCHRONIZE);
  if ( r_useTransparencySortJobs.valueInteger == 1 )
  {
    idParallelJobList::AddJob(
      this: updateTools->transparencyJobList,
      function: (void (__fastcall *)(void *))TransparencySortJob,
      data: this->sortParms);
  }
  else
  {
    sortParms = this->sortParms;
    TransparencySortQuads(
      parms: sortParms,
      a2: v7,
      a3: v6,
      emissiveQuads: (unsigned __int8 *)&r_useTransparencySortJobs,
      a5: (int)&r_cuttablemodel_freecpudata.description,
      a6: v5);
    TransparencyTriIndGen(parms: sortParms, quadOffset: 0);
    TransparencyEmissiveTriIndGen(parms: sortParms, quadOffset: 0);
  }
}


// ========================================================================
// ?AddInfluenceSphere@idRenderModelTransparency@@QAAXABVidVec3@@MMM@Z
// EA  : 0x8288C838
// RVA : 0x0088C838
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __fastcall idRenderModelTransparency::AddInfluenceSphere(
        idRenderModelTransparency *this,
        const idVec3 *center,
        double innerRadius,
        double outerRadius,
        double angle)
{
  int currentSphereIndex; // r11
  int v6; // r10
  int v7; // r8
  int v8; // r11
  int v9; // r9
  idVec3 *v10; // r11

  if ( this->numInfluenceSpheres[this->currentSphereIndex] < 1024 )
  {
    currentSphereIndex = this->currentSphereIndex;
    v6 = 4 * (currentSphereIndex + 512);
    v7 = 4 * (currentSphereIndex + 510);
    v8 = *(int *)((char *)&this->__vftable + v6);
    v9 = *(int *)((char *)&this->__vftable + v7);
    *(idRenderModelTransparency_vtbl **)((char *)&this->__vftable + v6) = (idRenderModelTransparency_vtbl *)(v8 + 1);
    v10 = (idVec3 *)(v9 + 24 * v8);
    *v10 = *center;
    v10[1].x = innerRadius;
    v10[1].y = outerRadius;
    v10[1].z = angle;
  }
}


// ========================================================================
// ?Init@idRenderModelTransparency@@SAXXZ
// EA  : 0x8288C9F8
// RVA : 0x0088C9F8
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

static void __fastcall idRenderModelTransparency::Init()
{
  int i; // r30
  unsigned __int8 *v1; // r3
  idVertexBuffer *v2; // r28
  char *v3; // r29
  int v4; // r10
  char *v5; // r11
  int j; // ctr

  for ( i = 0; i < 3; ++i )
  {
    idVertexBuffer::AllocBufferObject(
      this: &idRenderModelTransparency::vertexBuffer[i],
      data: nullptr,
      allocSize: 32 * MAX_TRANSPARENCY_VERTS,
      vertexMask: 3167,
      allocUsage: BU_DYNAMIC);
    idIndexBuffer::AllocBufferObject(
      this: &idRenderModelTransparency::indexBuffer[i],
      data: nullptr,
      allocSize: 2 * MAX_TRANSPARENCY_INDICES,
      allocUsage: BU_DYNAMIC);
    idIndexBuffer::AllocBufferObject(
      this: &idRenderModelTransparency::indexBuffer2[i],
      data: nullptr,
      allocSize: 6144,
      allocUsage: BU_DYNAMIC);
  }
  idRenderModelTransparency::segmentInfo = (transSortSegmentInfo_t *)idMem::AllocWithLocation(
                                                                       this: &mem,
                                                                       location: "w:\\tech5\\engine\\models\\transparency\\RenderMo"
                                                                       "delTransparency.cpp(105) : TAG_TRANSPARENCY",
                                                                       size: 0x4000u,
                                                                       tag: TAG_TRANSPARENCY,
                                                                       zeroBuffer: true,
                                                                       align: ALIGN_16,
                                                                       heap: HEAP_DEFAULTHEAP);
  idRenderModelTransparency::currentQuadDepths = (float *)idMem::AllocWithLocation(
                                                            this: &mem,
                                                            location: "w:\\tech5\\engine\\models\\transparency\\RenderModelTranspar"
                                                            "ency.cpp(106) : TAG_TRANSPARENCY",
                                                            size: 4 * MAX_TRANSPARENCY_QUADS,
                                                            tag: TAG_TRANSPARENCY,
                                                            zeroBuffer: true,
                                                            align: ALIGN_16,
                                                            heap: HEAP_DEFAULTHEAP);
  v1 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\engine\\models\\transparency\\RenderModelTransparency.cpp(107) : TAG_TRANSPARENCY",
                            size: MAX_TRANSPARENCY_QUADS,
                            tag: TAG_TRANSPARENCY,
                            zeroBuffer: true,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  idRenderModelTransparency::mappedVerts = nullptr;
  idRenderModelTransparency::mappedIndices = nullptr;
  idRenderModelTransparency::mappedIndices2 = nullptr;
  idRenderModelTransparency::mappedBufferIndex = 0;
  idRenderModelTransparency::numSegmentAllocations = 0;
  v2 = idRenderModelTransparency::vertexBufferUnsorted;
  idRenderModelTransparency::currentEmissiveQuads = v1;
  idRenderModelTransparency::numVertsAllocated = 0;
  idRenderModelTransparency::binVerts = nullptr;
  idRenderModelTransparency::binIndices = nullptr;
  do
    idVertexBuffer::AllocBufferObject(
      this: v2++,
      data: nullptr,
      allocSize: 0x80000,
      vertexMask: 3167,
      allocUsage: BU_DYNAMIC);
  while ( (int)v2 < (int)&idRenderModelTransparency::indexBufferUnsorted );
  v3 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                 size: 0xC000u,
                 tag: TAG_TEMP,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v4 = 3;
  v5 = v3 - 2;
  for ( j = 4096; j != 0; --j )
  {
    *((_WORD *)v5 + 1) = v4 - 3;
    *((_WORD *)v5 + 2) = v4 - 1;
    *((_WORD *)v5 + 3) = v4;
    *((_WORD *)v5 + 4) = v4 - 3;
    *((_WORD *)v5 + 5) = v4;
    v5 += 12;
    *(_WORD *)v5 = v4 - 2;
    v4 += 4;
  }
  idIndexBuffer::AllocBufferObject(
    this: &idRenderModelTransparency::indexBufferUnsorted,
    data: v3,
    allocSize: 49152,
    allocUsage: BU_DYNAMIC);
  if ( v3 != nullptr )
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
}


// ========================================================================
// __unwind$230815
// EA  : 0x8288CC70
// RVA : 0x0088CC70
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void _unwind_230815()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 160 + 80));
}


// ========================================================================
// ?GenerateTransparencyRenderList@idRenderModelTransparency@@QAAXPBVidRenderView@@@Z
// EA  : 0x8288CCA0
// RVA : 0x0088CCA0
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __fastcall idRenderModelTransparency::GenerateTransparencyRenderList(
        idRenderModelTransparency *this,
        const idRenderView *currentView)
{
  transSortResult_t *sortResult; // r10
  int numCollapsedVerts; // r23
  int numBinIndices; // r22
  int numEmissiveQuads; // r27
  transSortResult_t *v8; // r9
  double x; // fp0
  double y; // fp13
  double z; // fp12
  double v12; // fp11
  double v13; // fp10
  double v14; // fp9
  double v15; // fp8
  double v16; // fp7
  double v17; // fp6
  double v18; // fp5
  double v19; // fp4
  double v20; // fp3
  long double v21; // fp2
  long double v22; // fp2
  long double v23; // fp2
  bin_t *buffer; // r18
  node_t *v25; // r19
  idTransparencyVert *v26; // r20
  int *v27; // r30
  idRenderModelSurface *list; // r30
  idTriangles *geometry; // r9
  idRenderModelSurface *v30; // r10
  idTriangles *v31; // r8
  idRenderModelSurface *v32; // r30
  idTempArray<bin_t> v33; // [sp+50h] [-120h] BYREF
  deferredTransparencyBinParms_t v34; // [sp+60h] [-110h] BYREF
  idTempArray<idTransparencyVert> v35; // [sp+D8h] [-98h] BYREF
  idTempArray<int> v36; // [sp+E0h] [-90h] BYREF
  idTempArray<node_t> v37; // [sp+E8h] [-88h] BYREF

  sortResult = this->sortResult;
  numCollapsedVerts = sortResult->numCollapsedVerts;
  numBinIndices = 6 * sortResult->numSortedQuads;
  if ( r_useTransparencyEmissivePass.valueInteger != 0 )
    numEmissiveQuads = this->sortResult->numEmissiveQuads;
  else
    numEmissiveQuads = 0;
  if ( r_useTransparencyBinning.valueInteger != 0
    && idRenderModelTransparency::binVerts != nullptr
    && idRenderModelTransparency::binIndices != nullptr )
  {
    v8 = this->sortResult;
    x = currentView->r.vieworg.x;
    v34.verts = idRenderModelTransparency::binVerts;
    y = currentView->r.vieworg.y;
    z = currentView->r.vieworg.z;
    v12 = currentView->r.viewaxis.mat[0].x;
    v13 = currentView->r.viewaxis.mat[0].y;
    v14 = currentView->r.viewaxis.mat[0].z;
    v34.numBinVerts = v8->numCollapsedVerts;
    v15 = currentView->r.viewaxis.mat[1].x;
    v34.indices = idRenderModelTransparency::binIndices;
    v16 = currentView->r.viewaxis.mat[1].y;
    v17 = currentView->r.viewaxis.mat[1].z;
    v18 = currentView->r.viewaxis.mat[2].x;
    v19 = currentView->r.viewaxis.mat[2].y;
    v20 = currentView->r.viewaxis.mat[2].z;
    v34.numIndices = 6 * v8->numSortedQuads;
    v34.viewOrigin.x = x;
    v34.viewOrigin.y = y;
    v34.viewOrigin.z = z;
    v34.viewAxis.mat[0].x = v12;
    v34.viewAxis.mat[0].y = v13;
    v34.viewAxis.mat[0].z = v14;
    v34.viewAxis.mat[1].x = v15;
    v33.buffer = (bin_t *)&currentView->r.viewaxis.mat[2];
    v34.viewAxis.mat[1].y = v16;
    v34.viewAxis.mat[1].z = v17;
    v34.viewAxis.mat[2].x = v18;
    v34.viewAxis.mat[2].y = v19;
    v34.viewAxis.mat[2].z = v20;
    *((double *)&v21 + 1) = currentView->r.fov_x;
    *(double *)&v21 = (float)((float)(currentView->r.fov_x * idMath::M_DEG2RAD) * (float)0.5);
    v22 = tan(x: v21);
    v34.fovX = *(double *)&v22;
    *(double *)&v22 = (float)((float)(currentView->r.fov_y * idMath::M_DEG2RAD) * (float)0.5);
    v23 = tan(x: v22);
    v34.fovY = *(double *)&v23;
    idTempArray<bin_t>::idTempArray<bin_t>(this: &v33, num: 0x708u);
    buffer = v33.buffer;
    v34.numBins = 0;
    v34.bins = v33.buffer;
    idTempArray<node_t>::idTempArray<node_t>(this: &v37, num: 0x70Cu);
    v25 = v37.buffer;
    v34.numNodes = 0;
    v34.nodes = v37.buffer;
    idTempArray<idTransparencyVert>::idTempArray<idTransparencyVert>(this: &v35, num: MAX_TRANSPARENCY_VERTS);
    v26 = v35.buffer;
    v34.tempBinVerts = v35.buffer;
    idTempArray<int>::idTempArray<int>(this: &v36, num: MAX_TRANSPARENCY_VERTS);
    v27 = v36.buffer;
    v34.vertexRemap = v36.buffer;
    v34.binVerts = (idTransparencyVert *)idVertexBuffer::MapBuffer(
                                           this: &idRenderModelTransparency::vertexBuffer[idRenderModelTransparency::mappedBufferIndex],
                                           mapType: BM_WRITE_NOSYNC);
    v34.numBinVerts = 0;
    v34.maxBinVerts = MAX_TRANSPARENCY_VERTS;
    v34.binIndices = (unsigned __int16 *)idIndexBuffer::MapBuffer(
                                           this: &idRenderModelTransparency::indexBuffer[idRenderModelTransparency::mappedBufferIndex],
                                           mapType: BM_WRITE_NOSYNC);
    v34.numBinIndices = 0;
    v34.maxBinIndices = MAX_TRANSPARENCY_INDICES;
    BinQuads(parms: &v34);
    idIndexBuffer::UnmapBuffer(this: &idRenderModelTransparency::indexBuffer[idRenderModelTransparency::mappedBufferIndex]);
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&idRenderModelTransparency::vertexBuffer[idRenderModelTransparency::mappedBufferIndex]);
    numEmissiveQuads = 0;
    numCollapsedVerts = v34.numBinVerts;
    numBinIndices = v34.numBinIndices;
    if ( v27 != nullptr )
      idMem::Free(this: &mem, ptr: v27, align: ALIGN_16);
    if ( v26 != nullptr )
      idMem::Free(this: &mem, ptr: v26, align: ALIGN_16);
    if ( v25 != nullptr )
      idMem::Free(this: &mem, ptr: v25, align: ALIGN_16);
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  }
  list = this->surfaces.list;
  geometry = list->geometry;
  list->material = (const idMaterial *)mtrTransSort.r;
  geometry->numVerts = numCollapsedVerts;
  list->geometry->numIndexes = numBinIndices;
  idIndexBuffer::Reference(
    this: &list->geometry->indexBuffer,
    other: &idRenderModelTransparency::indexBuffer[idRenderModelTransparency::mappedBufferIndex]);
  idVertexBuffer::Reference(
    this: &list->geometry->vertexBuffer,
    other: &idRenderModelTransparency::vertexBuffer[idRenderModelTransparency::mappedBufferIndex]);
  v30 = this->surfaces.list;
  v31 = v30[1].geometry;
  v32 = v30 + 1;
  v30[1].material = (const idMaterial *)mtrTransSortGlare.r;
  v31->numVerts = 4 * numEmissiveQuads;
  v30[1].geometry->numIndexes = 6 * numEmissiveQuads;
  idIndexBuffer::Reference(
    this: &v30[1].geometry->indexBuffer,
    other: &idRenderModelTransparency::indexBuffer2[idRenderModelTransparency::mappedBufferIndex]);
  idVertexBuffer::Reference(
    this: &v32->geometry->vertexBuffer,
    other: &idRenderModelTransparency::vertexBuffer[idRenderModelTransparency::mappedBufferIndex]);
  if ( r_showTransparencyStats.valueInteger > 0 )
  {
    idLib::Printf(fmt: "Transparency Quads: %d\n", numCollapsedVerts >> 2);
    idLib::Printf(fmt: "Transparency Emissive Quads: %d\n", numEmissiveQuads);
  }
  this->sortResult->numSortedQuads = 0;
  this->sortResult->numCollapsedVerts = 0;
  this->sortResult->numEmissiveQuads = 0;
}


// ========================================================================
// __unwind$230881
// EA  : 0x8288D094
// RVA : 0x0088D094
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void _unwind_230881()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 368 + 80));
}


// ========================================================================
// __unwind$230882
// EA  : 0x8288D0BC
// RVA : 0x0088D0BC
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void _unwind_230882()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 368 + 232));
}


// ========================================================================
// __unwind$230883
// EA  : 0x8288D0E4
// RVA : 0x0088D0E4
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void _unwind_230883()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 368 + 216));
}


// ========================================================================
// __unwind$230884
// EA  : 0x8288D10C
// RVA : 0x0088D10C
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void _unwind_230884()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 368 + 224));
}


// ========================================================================
// `dynamic initializer for 'r_useTransparencySort''
// EA  : 0x83345050
// RVA : 0x01345050
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useTransparencySort__()
{
  idCVar::idCVar(
    this: &r_useTransparencySort,
    name: "r_useTransparencySort",
    value: "1",
    flags: 1,
    description: "0 = do not sort the transparency quads",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useTransparencySort__);
}


// ========================================================================
// `dynamic initializer for 'r_showTransparencyStats''
// EA  : 0x833450A8
// RVA : 0x013450A8
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showTransparencyStats__()
{
  idCVar::idCVar(
    this: &r_showTransparencyStats,
    name: "r_showTransparencyStats",
    value: "0",
    flags: 2,
    description: "1 = print stats",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showTransparencyStats__);
}


// ========================================================================
// `dynamic initializer for 'r_showVisibleInfluenceSpheres''
// EA  : 0x83345100
// RVA : 0x01345100
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showVisibleInfluenceSpheres__()
{
  idCVar::idCVar(
    this: &r_showVisibleInfluenceSpheres,
    name: "r_showVisibleInfluenceSpheres",
    value: "0",
    flags: 1,
    description: "show the visible influence spheres",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showVisibleInfluenceSpheres__);
}


// ========================================================================
// `dynamic initializer for 'r_useInfluenceSpheres''
// EA  : 0x83345158
// RVA : 0x01345158
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useInfluenceSpheres__()
{
  idCVar::idCVar(
    this: &r_useInfluenceSpheres,
    name: "r_useInfluenceSpheres",
    value: "1",
    flags: 1,
    description: "enable influence spheres",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useInfluenceSpheres__);
}


// ========================================================================
// `dynamic initializer for 'r_useTransparencyEmissivePass''
// EA  : 0x833451B0
// RVA : 0x013451B0
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useTransparencyEmissivePass__()
{
  idCVar::idCVar(
    this: &r_useTransparencyEmissivePass,
    name: "r_useTransparencyEmissivePass",
    value: "1",
    flags: 2,
    description: "render quads marked emissive to the emissive pass",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useTransparencyEmissivePass__);
}


// ========================================================================
// `dynamic initializer for 'r_useTransparencyBinning''
// EA  : 0x83345208
// RVA : 0x01345208
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useTransparencyBinning__()
{
  idCVar::idCVar(
    this: &r_useTransparencyBinning,
    name: "r_useTransparencyBinning",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useTransparencyBinning__);
}


// ========================================================================
// `dynamic initializer for 'r_useTransparencySortJobs''
// EA  : 0x83345260
// RVA : 0x01345260
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useTransparencySortJobs__()
{
  idCVar::idCVar(
    this: &r_useTransparencySortJobs,
    name: "r_useTransparencySortJobs",
    value: "1",
    flags: 2,
    description: "0 = off, 1 = threaded",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)byte_821B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useTransparencySortJobs__);
}


// ========================================================================
// `dynamic initializer for 'r_useInfluenceSphereCullJob''
// EA  : 0x833452C8
// RVA : 0x013452C8
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useInfluenceSphereCullJob__()
{
  idCVar::idCVar(
    this: &r_useInfluenceSphereCullJob,
    name: "r_useInfluenceSphereCullJob",
    value: "1",
    flags: 2,
    description: "0 = off, 1 = threaded",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)byte_821B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useInfluenceSphereCullJob__);
}


// ========================================================================
// `dynamic initializer for 'MAX_TRANSPARENCY_VERTS''
// EA  : 0x83345330
// RVA : 0x01345330
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void _dynamic_initializer_for__MAX_TRANSPARENCY_VERTS__()
{
  MAX_TRANSPARENCY_VERTS = 4 * MAX_TRANSPARENCY_QUADS;
}


// ========================================================================
// `dynamic initializer for 'MAX_TRANSPARENCY_INDICES''
// EA  : 0x83345348
// RVA : 0x01345348
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void _dynamic_initializer_for__MAX_TRANSPARENCY_INDICES__()
{
  MAX_TRANSPARENCY_INDICES = 6 * MAX_TRANSPARENCY_QUADS;
}


// ========================================================================
// `dynamic initializer for 'mtrTransSort''
// EA  : 0x83345368
// RVA : 0x01345368
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void _dynamic_initializer_for__mtrTransSort__()
{
  mtrTransSort.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &mtrTransSort;
}


// ========================================================================
// `dynamic initializer for 'mtrTransSortGlare''
// EA  : 0x83345388
// RVA : 0x01345388
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void _dynamic_initializer_for__mtrTransSortGlare__()
{
  mtrTransSortGlare.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &mtrTransSortGlare;
}


// ========================================================================
// `dynamic initializer for 'idRenderModelTransparency::vertexBuffer''
// EA  : 0x833453A8
// RVA : 0x013453A8
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelTransparency::vertexBuffer__()
{
  `eh vector constructor iterator'(
    ptr: (char *)idRenderModelTransparency::vertexBuffer,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelTransparency::vertexBuffer__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelTransparency::indexBuffer''
// EA  : 0x833453F8
// RVA : 0x013453F8
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelTransparency::indexBuffer__()
{
  `eh vector constructor iterator'(
    ptr: (char *)idRenderModelTransparency::indexBuffer,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idIndexBuffer::~idIndexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelTransparency::indexBuffer__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelTransparency::indexBuffer2''
// EA  : 0x83345448
// RVA : 0x01345448
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelTransparency::indexBuffer2__()
{
  `eh vector constructor iterator'(
    ptr: (char *)idRenderModelTransparency::indexBuffer2,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idIndexBuffer::~idIndexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelTransparency::indexBuffer2__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelTransparency::vertexBufferUnsorted''
// EA  : 0x83345498
// RVA : 0x01345498
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelTransparency::vertexBufferUnsorted__()
{
  `eh vector constructor iterator'(
    ptr: (char *)idRenderModelTransparency::vertexBufferUnsorted,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelTransparency::vertexBufferUnsorted__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelTransparency::indexBufferUnsorted''
// EA  : 0x833454E8
// RVA : 0x013454E8
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelTransparency::indexBufferUnsorted__()
{
  idIndexBuffer::idIndexBuffer(this: &idRenderModelTransparency::indexBufferUnsorted);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelTransparency::indexBufferUnsorted__);
}


// ========================================================================
// `dynamic initializer for 'register_TransparencySortJob''
// EA  : 0x83345520
// RVA : 0x01345520
// PDB : w:\tech5\engine\models\transparency\rendermodeltransparency.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_TransparencySortJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_TransparencySortJob,
           function: (void (__fastcall *)(void *))TransparencySortJob,
           name: "TransparencySortJob");
}

