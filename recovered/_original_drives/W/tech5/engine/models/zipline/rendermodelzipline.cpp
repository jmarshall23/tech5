
// ========================================================================
// ??1idRenderModelZipline@@MAA@XZ
// EA  : 0x82892AB0
// RVA : 0x00892AB0
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void __fastcall idRenderModelZipline::~idRenderModelZipline(idRenderModelZipline *this)
{
  idPixelUnpackBuffer *v2; // r3
  int v3; // r28
  idIndexBuffer *indexBuffer; // r29

  this->__vftable = (idRenderModelZipline_vtbl *)&idRenderModelZipline::`vftable';
  idMem::Free(this: &mem, ptr: this->sweptPoints, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->sourceSpline[0], align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->sourceSpline[1], align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->parms, align: ALIGN_16);
  v2 = (idPixelUnpackBuffer *)&this->vertexBuffer[this->currentBuffer];
  if ( v2->size < 0 )
  {
    idVertexBuffer::UnmapBuffer(this: v2);
    idIndexBuffer::UnmapBuffer(this: &this->indexBuffer[this->currentBuffer]);
  }
  v3 = 3;
  indexBuffer = this->indexBuffer;
  do
  {
    idVertexBuffer::FreeBufferObject(this: (idVertexBuffer *)&indexBuffer[-3]);
    idIndexBuffer::FreeBufferObject(this: indexBuffer);
    --v3;
    ++indexBuffer;
  }
  while ( v3 != 0 );
  `eh vector destructor iterator'(
    ptr: this->indexBuffer,
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idIndexBuffer::~idIndexBuffer);
  `eh vector destructor iterator'(
    ptr: this->vertexBuffer,
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$221989
// EA  : 0x82892BBC
// RVA : 0x00892BBC
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void _unwind_221989()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$221990_0
// EA  : 0x82892BE4
// RVA : 0x00892BE4
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void _unwind_221990_0()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 2092),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$221991_0
// EA  : 0x82892C20
// RVA : 0x00892C20
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void _unwind_221991_0()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 2140),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idIndexBuffer::~idIndexBuffer);
}


// ========================================================================
// ??0idRenderModelZipline@@QAA@XZ
// EA  : 0x82892CC8
// RVA : 0x00892CC8
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

idRenderModelZipline *__fastcall idRenderModelZipline::idRenderModelZipline(idRenderModelZipline *this)
{
  __int64 v1; // r29
  char v3; // r7
  idNonUniformBSpline<idVec3> *v4; // r3
  idNonUniformBSpline<idVec3> *v5; // r11
  float *v6; // r3

  idRenderModel::idRenderModel(this);
  LODWORD(v1) = 0;
  this->__vftable = (idRenderModelZipline_vtbl *)&idRenderModelZipline::`vftable';
  this->splineTessellationDistance = 30;
  this->cableDiameter = 1.0;
  this->cableSubdivisions = 5;
  this->time = 0.0;
  this->fractionBeforeLerp = 0.5;
  this->material = nullptr;
  this->splineMaxSubdivisions = 2;
  this->downDirection = false;
  this->dirty = 2;
  *(_QWORD *)this->sourceSpline = v1;
  this->currentSourceSpline = 0;
  this->currentBuffer = 0;
  `eh vector constructor iterator'(
    ptr: this->vertexBuffer,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  `eh vector constructor iterator'(
    ptr: this->indexBuffer,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idIndexBuffer::~idIndexBuffer);
  v3 = *((_BYTE *)&this->g + 105);
  this->numVertices = 0;
  this->numIndices = 0;
  *((_BYTE *)&this->g + 105) = v3 | 0xC0;
  this->sweptPoints = (sweptPoint_t *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                        size: 0x1C0u,
                                        tag: TAG_NEW,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
  v4 = (idNonUniformBSpline<idVec3> *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                        size: 0x2010u,
                                        tag: TAG_NEW,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
  {
    v4->closeTime = 0.0;
    v4->numKnots = 0;
    v4->boundaryType = 0;
    v5 = v4;
    v4->order = 4;
  }
  else
  {
    v5 = nullptr;
  }
  this->sourceSpline[0] = v5;
  v6 = (float *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                  size: 0x2010u,
                  tag: TAG_NEW,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
  {
    v6[2048] = 0.0;
    v6[2050] = 0.0;
    v6[2049] = 0.0;
    LODWORD(v1) = v6;
    *((_DWORD *)v6 + 2051) = 4;
  }
  this->sourceSpline[1] = (idNonUniformBSpline<idVec3> *)v1;
  this->parms = (zipLineGenParms_t *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                       size: 0x3Cu,
                                       tag: TAG_NEW,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// __unwind$222877
// EA  : 0x82892EA0
// RVA : 0x00892EA0
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void _unwind_222877()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$222878
// EA  : 0x82892EC8
// RVA : 0x00892EC8
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void _unwind_222878()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 160 + 180) + 2092),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$222879_0
// EA  : 0x82892F04
// RVA : 0x00892F04
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void _unwind_222879_0()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 160 + 180) + 2140),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idIndexBuffer::~idIndexBuffer);
}


// ========================================================================
// ?SetSpline@idRenderModelZipline@@QAAXPBV?$idCurve_Spline@VidVec3@@@@MM_N@Z
// EA  : 0x82892FA0
// RVA : 0x00892FA0
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void __fastcall idRenderModelZipline::SetSpline(
        idRenderModelZipline *this,
        const idCurve_Spline<idVec3> *spline,
        double time,
        double fractionBeforeLerp,
        const bool downDirection,
        int a6,
        bool a7)
{
  int v7; // r6
  int v8; // r5
  int v15; // r8
  idVec3 *v16; // r9
  idNonUniformBSpline<idVec3> *v17; // r11
  double x; // fp12
  int numKnots; // r10
  double z; // fp0
  float *v21; // r10
  double v28; // fp0
  idRenderModelSurface *list; // r10
  float *geometry; // r8
  float y; // [sp+4h] [-2Ch]

  v7 = 0;
  v8 = 0;
  _FP11 = 1.0e30;
  _FP8 = -1.0e30;
  _FP9 = 1.0e30;
  _FP10 = 1.0e30;
  this->sourceSpline[this->currentSourceSpline]->numKnots = 0;
  _FP6 = -1.0e30;
  _FP7 = -1.0e30;
  if ( spline->values.num > 0 )
  {
    v15 = 0;
    do
    {
      v16 = &spline->values.list[v7];
      v17 = this->sourceSpline[this->currentSourceSpline];
      x = v16->x;
      y = v16->y;
      numKnots = v17->numKnots;
      z = v16->z;
      if ( numKnots < 512 )
      {
        v17->times[numKnots] = spline->times.list[v15];
        v21 = &v17->times[3 * v17->numKnots];
        v21[512] = x;
        v21[513] = y;
        v21[514] = z;
        ++v17->numKnots;
      }
      _FP5 = (float)((float)_FP11 - (float)x);
      _FP4 = (float)((float)_FP10 - y);
      ++v8;
      _FP3 = (float)((float)_FP9 - (float)z);
      ++v7;
      _FP31 = (float)((float)x - (float)_FP8);
      ++v15;
      _FP30 = (float)(y - (float)_FP7);
      _FP29 = (float)((float)z - (float)_FP6);
      __asm
      {
        fsel      f11, f5, f12, f11
        fsel      f10, f4, f13, f10
        fsel      f9, f3, f0, f9
        fsel      f8, f31, f12, f8
        fsel      f7, f30, f13, f7
        fsel      f6, f29, f0, f6
      }
    }
    while ( v8 < spline->values.num );
  }
  this->time = time;
  v28 = 0.2;
  if ( fractionBeforeLerp >= 0.2 )
  {
    v28 = 0.80000001;
    if ( fractionBeforeLerp <= 0.80000001 )
      v28 = fractionBeforeLerp;
  }
  list = this->surfaces.list;
  this->fractionBeforeLerp = v28;
  this->downDirection = a7;
  geometry = (float *)list->geometry;
  *geometry = _FP11;
  geometry[1] = _FP10;
  geometry[2] = _FP9;
  geometry[3] = _FP8;
  geometry[4] = _FP7;
  geometry[5] = _FP6;
  this->referenceBounds.b[0].x = _FP11;
  this->referenceBounds.b[0].y = _FP10;
  this->referenceBounds.b[0].z = _FP9;
  this->referenceBounds.b[1].x = _FP8;
  this->referenceBounds.b[1].y = _FP7;
  this->referenceBounds.b[1].z = _FP6;
  this->dirty = 2;
}


// ========================================================================
// ?UpdateInView@idRenderModelZipline@@EAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x82893150
// RVA : 0x00893150
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

int __fastcall idRenderModelZipline::UpdateInView(
        idRenderModelZipline *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools)
{
  int dirty; // r11
  int currentBuffer; // r10
  idPixelUnpackBuffer *v9; // r3
  idTriangles *geometry; // r30
  int v11; // r11
  idDrawVert *v12; // r30
  unsigned __int16 *v13; // r3

  if ( this->surfaces.num == 0 )
    return 0;
  dirty = this->dirty;
  if ( dirty <= 0 )
    return 0;
  currentBuffer = this->currentBuffer;
  this->dirty = dirty - 1;
  v9 = (idPixelUnpackBuffer *)&this->vertexBuffer[currentBuffer];
  if ( v9->size < 0 )
  {
    idVertexBuffer::UnmapBuffer(this: v9);
    idIndexBuffer::UnmapBuffer(this: &this->indexBuffer[this->currentBuffer]);
  }
  geometry = this->surfaces.list->geometry;
  idVertexBuffer::Reference(this: &geometry->vertexBuffer, other: &this->vertexBuffer[this->currentBuffer]);
  idIndexBuffer::Reference(this: &geometry->indexBuffer, other: &this->indexBuffer[this->currentBuffer]);
  geometry->numVerts = this->numVertices;
  geometry->numIndexes = this->numIndices;
  if ( this->sourceSpline[this->currentSourceSpline]->numKnots < 2 )
    return 0;
  v11 = this->currentBuffer + 1;
  this->currentBuffer = v11 % 3;
  v12 = (idDrawVert *)idVertexBuffer::MapBuffer(this: &this->vertexBuffer[v11 % 3], mapType: BM_WRITE_NOSYNC);
  v13 = (unsigned __int16 *)idIndexBuffer::MapBuffer(
                              this: &this->indexBuffer[this->currentBuffer],
                              mapType: BM_WRITE_NOSYNC);
  this->parms->controlSpline = this->sourceSpline[this->currentSourceSpline];
  this->parms->splineTessellationDistance = this->splineTessellationDistance;
  this->parms->splineMaxSubdivisions = this->splineMaxSubdivisions;
  this->parms->cableSubdivisions = this->cableSubdivisions;
  this->parms->cableDiameter = this->cableDiameter;
  this->parms->sweptPoints = this->sweptPoints;
  this->parms->time = this->time;
  this->parms->fractionBeforeLerp = this->fractionBeforeLerp;
  this->parms->downDirection = this->downDirection;
  this->parms->maxVertices = this->cableSubdivisions * this->splineMaxSubdivisions;
  this->parms->maxIndices = 6 * (this->splineMaxSubdivisions - 1) * this->cableSubdivisions;
  this->parms->vertices = v12;
  this->parms->indices = v13;
  this->parms->numVertices = &this->numVertices;
  this->parms->numIndices = &this->numIndices;
  this->currentSourceSpline ^= 1u;
  if ( r_useZiplineGenJobs.valueInteger == 1 )
    idParallelJobList::AddJob(
      this: updateTools->renderModelJobList,
      function: (void (__fastcall *)(void *))GenZipline,
      data: this->parms);
  else
    GenZipline(parms: this->parms);
  return 1;
}


// ========================================================================
// ?Save@idRenderModelZipline@@EBAXPAVidFile@@@Z
// EA  : 0x828933B8
// RVA : 0x008933B8
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void __fastcall idRenderModelZipline::Save(idRenderModelZipline *this, idFile *fp)
{
  idFile_vtbl *v4; // r10
  const idMaterial *material; // r11
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  int v7; // r29
  idNonUniformBSpline<idVec3> *v8; // r11
  int v9; // r27
  int v10; // r28
  double v11; // fp0
  idFile_vtbl *v12; // r11
  unsigned int (__fastcall *v13)(idFile *, const void *, unsigned int); // ctr
  _DWORD *v14; // r11
  int v15; // r9
  int v16; // r8
  bool v17[4]; // [sp+50h] [-50h] BYREF
  int numKnots; // [sp+54h] [-4Ch] BYREF
  float v19[2]; // [sp+58h] [-48h] BYREF
  _DWORD v20[16]; // [sp+60h] [-40h] BYREF

  idRenderModel::Save(this, fp);
  v4 = fp->__vftable;
  v17[0] = this->material != nullptr;
  v4->Write(this: fp, a2: v17, a3: 1u);
  material = this->material;
  if ( material != nullptr )
    idFile::WriteString(this: fp, string: material->name.str);
  fp->Write(this: fp, a2: &this->splineTessellationDistance, a3: 4u);
  fp->Write(this: fp, a2: &this->splineMaxSubdivisions, a3: 4u);
  fp->Write(this: fp, a2: &this->cableDiameter, a3: 4u);
  fp->Write(this: fp, a2: &this->cableSubdivisions, a3: 4u);
  fp->Write(this: fp, a2: &this->time, a3: 4u);
  fp->Write(this: fp, a2: &this->fractionBeforeLerp, a3: 4u);
  fp->Write(this: fp, a2: &this->downDirection, a3: 1u);
  Write = fp->Write;
  numKnots = this->sourceSpline[this->currentSourceSpline]->numKnots;
  Write(this: fp, a2: &numKnots, a3: 4u);
  v7 = 0;
  v8 = this->sourceSpline[this->currentSourceSpline];
  if ( v8->numKnots > 0 )
  {
    v9 = 0;
    v10 = 0;
    do
    {
      v11 = v8->times[v10];
      v12 = fp->__vftable;
      v19[0] = v11;
      v12->Write(this: fp, a2: v19, a3: 4u);
      v13 = fp->Write;
      v14 = (_DWORD *)&this->sourceSpline[this->currentSourceSpline]->times[v9];
      v15 = v14[513];
      v16 = v14[514];
      v20[0] = v14[512];
      v20[1] = v15;
      v20[2] = v16;
      v13(this: fp, a2: v20, a3: 12u);
      ++v7;
      ++v10;
      v9 += 3;
      v8 = this->sourceSpline[this->currentSourceSpline];
    }
    while ( v7 < v8->numKnots );
  }
}


// ========================================================================
// ?BuildModel@idRenderModelZipline@@QAAXPBVidMaterial@@HHMH@Z
// EA  : 0x828935D8
// RVA : 0x008935D8
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void __fastcall idRenderModelZipline::BuildModel(
        idRenderModelZipline *this,
        const idMaterial *material,
        unsigned int splineTessellationDistance,
        int splineMaxSubdivisions,
        double cableDiameter,
        const int cableSubdivisions,
        int a7)
{
  double v9; // fp0
  int v12; // r11
  double v13; // fp0
  int v14; // r11
  int v15; // r23
  int v16; // r22
  int v17; // r29
  int v18; // r29
  int v19; // r29
  int v20; // r29
  int v21; // r28
  double v22; // fp28
  __int64 v23; // r11
  int v24; // r29
  double v25; // fp26
  double v26; // fp25
  float *CurrentValue; // r3
  sweptPoint_t *v28; // r11
  double v29; // fp3
  double v30; // fp2
  double v32; // fp10
  double v34; // fp7
  double v35; // fp11
  double v36; // fp10
  double v37; // fp7
  idIndexBuffer *indexBuffer; // r29
  int v39; // r28
  idTriangles *v40; // r3
  idTriangles *v41; // r29
  __int64 v42; // [sp+8h] [-1B8h]
  __int64 v43; // [sp+10h] [-1B0h]
  __int64 v44; // [sp+18h] [-1A8h]
  __int64 v45; // [sp+20h] [-1A0h]
  __int64 v46; // [sp+28h] [-198h]
  __int64 v47; // [sp+30h] [-190h]
  __int64 v48; // [sp+38h] [-188h]
  __int64 v49; // [sp+40h] [-180h]
  __int64 v50; // [sp+48h] [-178h]
  __int64 v51; // [sp+50h] [-170h]
  unsigned __int64 v52; // [sp+60h] [-160h] BYREF
  idCurve_NURBS<idVec3> v53; // [sp+68h] [-158h] BYREF
  float v54; // [sp+B0h] [-110h]
  idList<float,116> v55; // [sp+B8h] [-108h] BYREF
  idRenderModel *v56; // [sp+D0h] [-F0h]
  idRenderModelSurface *v57; // [sp+D4h] [-ECh]
  idTriangles *v58; // [sp+E0h] [-E0h]
  char v59; // [sp+E4h] [-DCh]
  char v60; // [sp+E5h] [-DBh]
  unsigned int v61; // [sp+E8h] [-D8h]
  int v62; // [sp+ECh] [-D4h]
  unsigned int v63; // [sp+F0h] [-D0h]
  int v64; // [sp+F4h] [-CCh]
  unsigned int v65; // [sp+F8h] [-C8h]
  float v66; // [sp+FCh] [-C4h]
  __int64 v67; // [sp+100h] [-C0h]
  idCurve_NURBS<idVec3> v68; // [sp+108h] [-B8h] BYREF

  this->material = material;
  v52 = __PAIR64__(0x82000000, splineTessellationDistance);
  v9 = (float)__SPAIR64__(0x82000000, splineTessellationDistance);
  if ( v9 >= 1.0 )
  {
    if ( v9 > 1024.0 )
      v9 = 1024.0;
  }
  else
  {
    v9 = 1.0;
  }
  this->splineTessellationDistance = (int)v9;
  if ( splineMaxSubdivisions >= 2 )
  {
    v12 = 512;
    if ( splineMaxSubdivisions <= 512 )
      v12 = splineMaxSubdivisions;
  }
  else
  {
    v12 = 2;
  }
  this->splineMaxSubdivisions = v12;
  v13 = 0.1;
  if ( cableDiameter >= 0.1 )
  {
    v13 = 128.0;
    if ( cableDiameter <= 128.0 )
      v13 = cableDiameter;
  }
  this->cableDiameter = v13;
  if ( a7 >= 3 )
  {
    v14 = 16;
    if ( a7 <= 16 )
      v14 = a7;
  }
  else
  {
    v14 = 3;
  }
  this->cableSubdivisions = v14;
  v15 = splineMaxSubdivisions * a7;
  v16 = 6 * (splineMaxSubdivisions - 1) * a7;
  idCurve_NURBS<idVec3>::idCurve_NURBS<idVec3>(this: (idCurve_NURBS<idVec3> *)&v53.values.num);
  *(float *)&v53.__vftable = cableDiameter;
  *(float *)&v53.times.list = cableDiameter;
  *(float *)&v53.times.num = 0.0;
  *(float *)&v52 = 0.0;
  v17 = idCurve<idVec3>::IndexForTime(this: (idCurve<idVec1> *)&v53.values.num, time: 0.0);
  idList<float,116>::Insert(this: (idList<float,116> *)&v53.values.size, obj: (float *)&v52, index: v17);
  idList<idVec3,116>::Insert(this: (idList<idVec3,116> *)&v53.boundaryType, obj: (const idVec3 *)&v53, index: v17);
  *(float *)&v52 = 1.0;
  idList<float,116>::Insert(this: &v55, obj: (float *)&v52, index: v17);
  *(float *)&v53.__vftable = cableDiameter;
  *(float *)&v53.times.num = 0.0;
  *(float *)&v53.times.list = -cableDiameter;
  *(float *)&v52 = 100.0;
  v18 = idCurve<idVec3>::IndexForTime(this: (idCurve<idVec1> *)&v53.values.num, time: 100.0);
  idList<float,116>::Insert(this: (idList<float,116> *)&v53.values.size, obj: (float *)&v52, index: v18);
  idList<idVec3,116>::Insert(this: (idList<idVec3,116> *)&v53.boundaryType, obj: (const idVec3 *)&v53, index: v18);
  *(float *)&v52 = 1.0;
  idList<float,116>::Insert(this: &v55, obj: (float *)&v52, index: v18);
  *(float *)&v53.__vftable = -cableDiameter;
  v53.times.list = (float *)v53.__vftable;
  *(float *)&v53.times.num = 0.0;
  *(float *)&v52 = 200.0;
  v19 = idCurve<idVec3>::IndexForTime(this: (idCurve<idVec1> *)&v53.values.num, time: 200.0);
  idList<float,116>::Insert(this: (idList<float,116> *)&v53.values.size, obj: (float *)&v52, index: v19);
  idList<idVec3,116>::Insert(this: (idList<idVec3,116> *)&v53.boundaryType, obj: (const idVec3 *)&v53, index: v19);
  *(float *)&v52 = 1.0;
  idList<float,116>::Insert(this: &v55, obj: (float *)&v52, index: v19);
  *(float *)&v53.__vftable = -cableDiameter;
  *(float *)&v53.times.list = cableDiameter;
  *(float *)&v53.times.num = 0.0;
  *(float *)&v52 = 300.0;
  v20 = idCurve<idVec3>::IndexForTime(this: (idCurve<idVec1> *)&v53.values.num, time: 300.0);
  idList<float,116>::Insert(this: (idList<float,116> *)&v53.values.size, obj: (float *)&v52, index: v20);
  idList<idVec3,116>::Insert(this: (idList<idVec3,116> *)&v53.boundaryType, obj: (const idVec3 *)&v53, index: v20);
  *(float *)&v52 = 1.0;
  idList<float,116>::Insert(this: &v55, obj: (float *)&v52, index: v20);
  v54 = 100.0;
  *(_DWORD *)&v53.weights.granularity = 2;
  HIBYTE(v53.weights.size) = 1;
  v21 = 0;
  v22 = (float)((float)(*(float *)(4 * LODWORD(v53.closeTime) + v53.values.size - 4) - *(float *)v53.values.size)
              + (float)100.0);
  if ( a7 > 0 )
  {
    HIDWORD(v23) = 0x82000000;
    v52 = __PAIR64__(0x82000000, a7);
    v24 = 0;
    do
    {
      LODWORD(v23) = v21;
      v52 = v23;
      v25 = (float)v23;
      v26 = (float)((float)((float)v23 * (float)v22) / (float)__SPAIR64__(0x82000000, a7));
      CurrentValue = (float *)idCurve_NURBS<idAngles>::GetCurrentValue(
                                this: &v53,
                                result: (idCurve_Spline<idVec1> *)&v53.values.num,
                                time: v26);
      v28 = &this->sweptPoints[v24];
      v28->pos.x = *CurrentValue;
      v28->pos.y = CurrentValue[1];
      v28->pos.z = CurrentValue[2];
      ++v21;
      this->sweptPoints[v24].tangent = *idCurve_NURBS<idAngles>::GetCurrentFirstDerivative(
                                          this: &v68,
                                          result: (idVec3 *)&v53.values.num,
                                          time: v26);
      LODWORD(v23) = &this->sweptPoints[v24];
      HIDWORD(v23) = v23 + 12;
      v29 = *(float *)(v23 + 20);
      v30 = *(float *)(v23 + 16);
      _FP11 = (float)((float)((float)(*(float *)(v23 + 20) * *(float *)(v23 + 20))
                            + (float)((float)(*(float *)(v23 + 12) * *(float *)(v23 + 12))
                                    + (float)(*(float *)(v23 + 16) * *(float *)(v23 + 16))))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      v32 = (float)((float)((float)(*(float *)(v23 + 20) * *(float *)(v23 + 20))
                          + (float)((float)(*(float *)(v23 + 12) * *(float *)(v23 + 12))
                                  + (float)(*(float *)(v23 + 16) * *(float *)(v23 + 16))))
                  * (float)0.5);
      __asm { fsel      f9, f11, f12, f0 }
      v34 = __frsqrte(_FP9);
      v35 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v34
                                                                                          * (float)((float)((float)(*(float *)(v23 + 20) * *(float *)(v23 + 20)) + (float)((float)(*(float *)(v23 + 12) * *(float *)(v23 + 12)) + (float)(*(float *)(v23 + 16) * *(float *)(v23 + 16))))
                                                                                                  * (float)0.5))
                                                                                  * (float)v34)
                                                                          - (float)1.5)
                                                          * (float)v34)
                                                  * (float)((float)((float)(*(float *)(v23 + 20) * *(float *)(v23 + 20))
                                                                  + (float)((float)(*(float *)(v23 + 12)
                                                                                  * *(float *)(v23 + 12))
                                                                          + (float)(*(float *)(v23 + 16)
                                                                                  * *(float *)(v23 + 16))))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v34
                                                                                  * (float)((float)((float)(*(float *)(v23 + 20) * *(float *)(v23 + 20))
                                                                                                  + (float)((float)(*(float *)(v23 + 12) * *(float *)(v23 + 12)) + (float)(*(float *)(v23 + 16) * *(float *)(v23 + 16))))
                                                                                          * (float)0.5))
                                                                          * (float)v34)
                                                                  - (float)1.5)
                                                  * (float)v34))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v34
                                                          * (float)((float)((float)(*(float *)(v23 + 20)
                                                                                  * *(float *)(v23 + 20))
                                                                          + (float)((float)(*(float *)(v23 + 12)
                                                                                          * *(float *)(v23 + 12))
                                                                                  + (float)(*(float *)(v23 + 16)
                                                                                          * *(float *)(v23 + 16))))
                                                                  * (float)0.5))
                                                  * (float)v34)
                                          - (float)1.5)
                          * (float)v34));
      v36 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v34
                                                                                                  * (float)((float)((float)(*(float *)(v23 + 20) * *(float *)(v23 + 20)) + (float)((float)(*(float *)(v23 + 12) * *(float *)(v23 + 12)) + (float)(*(float *)(v23 + 16) * *(float *)(v23 + 16)))) * (float)0.5))
                                                                                          * (float)v34)
                                                                                  - (float)1.5)
                                                                  * (float)v34)
                                                          * (float)((float)((float)(*(float *)(v23 + 20)
                                                                                  * *(float *)(v23 + 20))
                                                                          + (float)((float)(*(float *)(v23 + 12)
                                                                                          * *(float *)(v23 + 12))
                                                                                  + (float)(*(float *)(v23 + 16)
                                                                                          * *(float *)(v23 + 16))))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v34
                                                                                          * (float)((float)((float)(*(float *)(v23 + 20) * *(float *)(v23 + 20)) + (float)((float)(*(float *)(v23 + 12) * *(float *)(v23 + 12)) + (float)(*(float *)(v23 + 16) * *(float *)(v23 + 16))))
                                                                                                  * (float)0.5))
                                                                                  * (float)v34)
                                                                          - (float)1.5)
                                                          * (float)v34))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v34
                                                                  * (float)((float)((float)(*(float *)(v23 + 20)
                                                                                          * *(float *)(v23 + 20))
                                                                                  + (float)((float)(*(float *)(v23 + 12)
                                                                                                  * *(float *)(v23 + 12))
                                                                                          + (float)(*(float *)(v23 + 16)
                                                                                                  * *(float *)(v23 + 16))))
                                                                          * (float)0.5))
                                                          * (float)v34)
                                                  - (float)1.5)
                                  * (float)v34))
                  * (float)v32);
      v37 = (float)((float)-(float)((float)((float)v36
                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v34 * (float)((float)((float)(*(float *)(v23 + 20) * *(float *)(v23 + 20)) + (float)((float)(*(float *)(v23 + 12) * *(float *)(v23 + 12)) + (float)(*(float *)(v23 + 16) * *(float *)(v23 + 16)))) * (float)0.5)) * (float)v34) - (float)1.5)
                                                                                          * (float)v34)
                                                                                  * (float)((float)((float)(*(float *)(v23 + 20) * *(float *)(v23 + 20))
                                                                                                  + (float)((float)(*(float *)(v23 + 12) * *(float *)(v23 + 12)) + (float)(*(float *)(v23 + 16) * *(float *)(v23 + 16))))
                                                                                          * (float)0.5))
                                                                          * (float)((float)-(float)((float)((float)((float)v34 * (float)((float)((float)(*(float *)(v23 + 20) * *(float *)(v23 + 20)) + (float)((float)(*(float *)(v23 + 12) * *(float *)(v23 + 12)) + (float)(*(float *)(v23 + 16) * *(float *)(v23 + 16)))) * (float)0.5)) * (float)v34)
                                                                                                  - (float)1.5)
                                                                                  * (float)v34))
                                                                  - (float)1.5)
                                                  * (float)((float)-(float)((float)((float)((float)v34
                                                                                          * (float)((float)((float)(*(float *)(v23 + 20) * *(float *)(v23 + 20)) + (float)((float)(*(float *)(v23 + 12) * *(float *)(v23 + 12)) + (float)(*(float *)(v23 + 16) * *(float *)(v23 + 16))))
                                                                                                  * (float)0.5))
                                                                                  * (float)v34)
                                                                          - (float)1.5)
                                                          * (float)v34)))
                                  - (float)1.5)
                  * (float)v35);
      *(float *)(v23 + 12) = *(float *)(v23 + 12) * (float)v37;
      *(float *)(v23 + 16) = (float)v30 * (float)v37;
      *(float *)(v23 + 20) = (float)v29 * (float)v37;
      this->sweptPoints[v24++].s = (float)v25 / (float)__SPAIR64__(0x82000000, a7);
    }
    while ( v21 < a7 );
  }
  this->FreeSurfaces(this);
  if ( !this->deferredPositionInitialized || !this->useDeferredPosition )
  {
    this->g.origin.x = vec3_origin.x;
    HIDWORD(v52) = &this->g;
    this->g.origin.y = vec3_origin.y;
    this->g.origin.z = vec3_origin.z;
  }
  this->deferredOrigin.x = vec3_origin.x;
  HIDWORD(v52) = &this->deferredOrigin;
  indexBuffer = this->indexBuffer;
  v39 = 3;
  this->deferredOrigin.y = vec3_origin.y;
  this->deferredOrigin.z = vec3_origin.z;
  do
  {
    idVertexBuffer::AllocBufferObject(
      this: (idVertexBuffer *)&indexBuffer[-3],
      data: nullptr,
      allocSize: 32 * v15,
      vertexMask: 31,
      allocUsage: BU_DYNAMIC);
    idIndexBuffer::AllocBufferObject(this: indexBuffer, data: nullptr, allocSize: 2 * v16, allocUsage: BU_DYNAMIC);
    --v39;
    ++indexBuffer;
  }
  while ( v39 != 0 );
  *(float *)&v65 = 0.0;
  v66 = 0.0;
  *(float *)&v67 = 0.0;
  *((float *)&v67 + 1) = 0.0;
  v56 = (idRenderModel *)material;
  v57 = nullptr;
  v59 = 0;
  v60 = 0;
  v61 = 0;
  v62 = 0;
  v63 = 0;
  v64 = 0;
  v40 = (idTriangles *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x84u,
                         tag: TAG_TRIANGLES,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  HIDWORD(v52) = v40;
  if ( v40 != nullptr )
    v41 = idTriangles::idTriangles(this: v40);
  else
    v41 = nullptr;
  v41->bounds.b[1].z = 0.0;
  v41->bounds.b[1].y = 0.0;
  v41->bounds.b[1].x = 0.0;
  v41->bounds.b[0].z = 0.0;
  v58 = v41;
  v41->bounds.b[0].y = 0.0;
  v41->bounds.b[0].x = 0.0;
  v41->numVerts = 0;
  v41->numIndexes = 0;
  idVertexBuffer::Reference(this: &v41->vertexBuffer, other: this->vertexBuffer);
  idIndexBuffer::Reference(this: &v41->indexBuffer, other: this->indexBuffer);
  idRenderModel::AddSurface(
    this: v56,
    surf: v57,
    a3: __SPAIR64__((unsigned int)v58, v61),
    a4: __SPAIR64__(v63, v65),
    a5: v67,
    a6: v42,
    a7: v43,
    a8: v44,
    a9: v45,
    a10: v46,
    a11: v47,
    a12: v48,
    a13: v49,
    a14: v50,
    a15: v51);
  idRenderModel::FinishSurfaces(this);
  this->dirty = 2;
  if ( v55.listStatic == 0 || v55.listStatic == 2 )
  {
    if ( v55.list != nullptr )
      idMem::Free(this: &mem, ptr: v55.list, align: ALIGN_16);
    v55.list = nullptr;
    v55.size = 0;
  }
  v55.num = 0;
  v53.values.num = (int)&idCurve<idVec3>::`vftable';
  if ( LOBYTE(v53.weights.list) == 0 || LOBYTE(v53.weights.list) == 2 )
  {
    if ( v53.boundaryType != 0 )
      idMem::Free(this: &mem, ptr: (void *)v53.boundaryType, align: ALIGN_16);
    v53.boundaryType = 0;
    v53.order = 0;
  }
  v53.closeTime = 0.0;
  if ( (!*(&v53.changed + 3) || *((unsigned __int8 *)&v53.changed + 3) == 2) && v53.values.size != 0 )
    idMem::Free(this: &mem, ptr: (void *)v53.values.size, align: ALIGN_16);
}


// ========================================================================
// __unwind$225402
// EA  : 0x82893C34
// RVA : 0x00893C34
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void _unwind_225402()
{
  int v0; // r12

  idCurve_NURBS<idVec3>::~idCurve_NURBS<idVec3>(this: (idCurve_NURBS<idVec3> *)(v0 - 448 + 128));
}


// ========================================================================
// __unwind$225403
// EA  : 0x82893C5C
// RVA : 0x00893C5C
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void _unwind_225403()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 448 + 96), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$225642
// EA  : 0x82893C88
// RVA : 0x00893C88
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void _unwind_225642()
{
  int v0; // r12

  idCurve_NonUniformBSpline<idVec3>::~idCurve_NonUniformBSpline<idVec3>(this: (idCurve_NonUniformBSpline<idVec3> *)(v0 - 448 + 128));
}


// ========================================================================
// __unwind$225687
// EA  : 0x82893CB0
// RVA : 0x00893CB0
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void _unwind_225687()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 448 + 132));
}


// ========================================================================
// ?Load@idRenderModelZipline@@EAA_NPAVidFile@@@Z
// EA  : 0x82893CE8
// RVA : 0x00893CE8
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

int __fastcall idRenderModelZipline::Load(idRenderModelZipline *this, idFile *fp)
{
  int v4; // r28
  idFile_vtbl *v5; // r11
  const idMaterial *v7; // r3
  int v8; // r7
  const idVec3 *v9; // r4
  _BYTE v10[4]; // [sp+50h] [-90h] BYREF
  int v11; // [sp+54h] [-8Ch] BYREF
  float v12; // [sp+58h] [-88h] BYREF
  float v13[4]; // [sp+60h] [-80h] BYREF
  idStr v14[3]; // [sp+70h] [-70h] BYREF

  if ( (unsigned __int8)idRenderModel::Load(this, fp) == 0 )
    return 0;
  v4 = 0;
  v5 = fp->__vftable;
  v10[0] = 0;
  if ( v5->Read(this: fp, a2: v10, a3: 1u) == 0 )
    return 0;
  if ( v10[0] != 0 )
  {
    v14[0].len = 0;
    v14[0].baseBuffer[0] = 0;
    v14[0].allocedAndFlag = 20;
    v14[0].data = v14[0].baseBuffer;
    if ( idFile::ReadString(this: fp, string: v14) == 0 )
    {
      idStr::FreeData(this: v14);
      return 0;
    }
    if ( v14[0].data != nullptr )
      v7 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                 this: &idMaterial::resourceList,
                                 name: v14[0].data,
                                 makeDefault: true);
    else
      v7 = nullptr;
    this->material = v7;
    idStr::FreeData(this: v14);
  }
  if ( fp->Read(this: fp, a2: &this->splineTessellationDistance, a3: 4u) == 0
    || fp->Read(this: fp, a2: &this->splineMaxSubdivisions, a3: 4u) == 0
    || fp->Read(this: fp, a2: &this->cableDiameter, a3: 4u) == 0
    || fp->Read(this: fp, a2: &this->cableSubdivisions, a3: 4u) == 0
    || fp->Read(this: fp, a2: &this->time, a3: 4u) == 0
    || fp->Read(this: fp, a2: &this->fractionBeforeLerp, a3: 4u) == 0
    || fp->Read(this: fp, a2: &this->downDirection, a3: 1u) == 0
    || fp->Read(this: fp, a2: &v11, a3: 4u) == 0 )
  {
    return 0;
  }
  this->sourceSpline[this->currentSourceSpline]->numKnots = 0;
  if ( v11 > 0 )
  {
    while ( fp->Read(this: fp, a2: &v12, a3: 4u) != 0 && fp->Read(this: fp, a2: v13, a3: 12u) != 0 )
    {
      idNonUniformBSpline<idVec3>::AddValue(
        this: this->sourceSpline[this->currentSourceSpline],
        time: v12,
        value: v9,
        a4: v13);
      if ( ++v4 >= v11 )
        goto LABEL_23;
    }
    return 0;
  }
LABEL_23:
  idRenderModelZipline::BuildModel(
    this,
    material: this->material,
    splineTessellationDistance: this->splineTessellationDistance,
    splineMaxSubdivisions: this->splineMaxSubdivisions,
    cableDiameter: this->cableDiameter,
    cableSubdivisions: v8,
    a7: this->cableSubdivisions);
  idRenderModel::CommitThisFrame(this);
  return 1;
}


// ========================================================================
// __unwind$225988
// EA  : 0x82893FA8
// RVA : 0x00893FA8
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void _unwind_225988()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// `dynamic initializer for 'r_useZiplineGenJobs''
// EA  : 0x83345660
// RVA : 0x01345660
// PDB : w:\tech5\engine\models\zipline\rendermodelzipline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useZiplineGenJobs__()
{
  idCVar::idCVar(
    this: &r_useZiplineGenJobs,
    name: "r_useZiplineGenJobs",
    value: "1",
    flags: 2,
    description: "0 = off, 1 = threaded",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)byte_821B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useZiplineGenJobs__);
}

