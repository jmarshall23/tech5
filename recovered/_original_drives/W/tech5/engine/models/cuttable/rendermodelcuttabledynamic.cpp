
// ========================================================================
// ??1idRenderModelCuttableDynamic@@UAA@XZ
// EA  : 0x827C70E0
// RVA : 0x007C70E0
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttabledynamic.cpp
// ========================================================================

void __fastcall idRenderModelCuttableDynamic::~idRenderModelCuttableDynamic(idRenderModelCuttableDynamic *this)
{
  this->__vftable = (idRenderModelCuttableDynamic_vtbl *)&idRenderModelCuttableDynamic::`vftable';
  idRenderModel::FreeSurfaces(this);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$219500_0
// EA  : 0x827C7130
// RVA : 0x007C7130
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttabledynamic.cpp
// ========================================================================

void _unwind_219500_0()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idRenderModelCuttableDynamic@@QAA@XZ
// EA  : 0x827C7160
// RVA : 0x007C7160
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttabledynamic.cpp
// ========================================================================

idRenderModelCuttableDynamic *__fastcall idRenderModelCuttableDynamic::idRenderModelCuttableDynamic(
        idRenderModelCuttableDynamic *this)
{
  idTriangles *v2; // r3
  idTriangles *v3; // r28
  idIndexBuffer *v4; // r3
  idVertexBuffer *v5; // r3

  idRenderModel::idRenderModel(this);
  this->__vftable = (idRenderModelCuttableDynamic_vtbl *)&idRenderModelCuttableDynamic::`vftable';
  idRenderModel::FreeSurfaces(this);
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
  idVertexBuffer::AllocBufferObject(
    this: &v3->vertexBuffer,
    data: nullptr,
    allocSize: 4096,
    vertexMask: 31,
    allocUsage: BU_DYNAMIC);
  idIndexBuffer::AllocBufferObject(this: &v3->indexBuffer, data: nullptr, allocSize: 768, allocUsage: BU_DYNAMIC);
  v4 = (idIndexBuffer *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x10u,
                          tag: TAG_RENDERMODEL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = (idVertexBuffer *)idIndexBuffer::idIndexBuffer(this: v4);
  else
    v5 = nullptr;
  idVertexBuffer::AllocBufferObject(this: v5, data: nullptr, allocSize: 1024, vertexMask: 9216, allocUsage: BU_DYNAMIC);
  idRenderModel::AddSurface(this: nullptr, surf: nullptr);
  idRenderModel::AddSurface(this, surf: nullptr);
  idRenderModel::FinishSurfaces(this);
  return this;
}


// ========================================================================
// __unwind$219773
// EA  : 0x827C7334
// RVA : 0x007C7334
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttabledynamic.cpp
// ========================================================================

void _unwind_219773()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 304 + 324));
}


// ========================================================================
// __unwind$219774
// EA  : 0x827C735C
// RVA : 0x007C735C
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttabledynamic.cpp
// ========================================================================

void _unwind_219774()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 304 + 96), tag: TAG_TRIANGLES);
}


// ========================================================================
// __unwind$219775
// EA  : 0x827C7388
// RVA : 0x007C7388
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttabledynamic.cpp
// ========================================================================

void _unwind_219775()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 304 + 96), tag: TAG_RENDERMODEL);
}


// ========================================================================
// ?UploadRenderGeometry@idRenderModelCuttableDynamic@@AAAXPBVidMaterial@@ABV?$idList@VidDrawVert@@$04@@ABV?$idList@G$04@@@Z
// EA  : 0x827C7418
// RVA : 0x007C7418
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttabledynamic.cpp
// ========================================================================

void __fastcall idRenderModelCuttableDynamic::UploadRenderGeometry(
        idRenderModelCuttableDynamic *this,
        const idMaterial *material,
        const idList<idDrawVert,5> *vertices,
        const idList<unsigned short,5> *indices)
{
  idRenderModelSurface *list; // r11
  idRenderModelSurface *v9; // r30
  idTriangles *geometry; // r11
  idPixelUnpackBuffer *p_vertexBuffer; // r26
  idIndexBuffer *p_indexBuffer; // r25
  float *v13; // r29
  void *v14; // r24
  int num; // r9
  int v16; // r10
  float *v23; // r11
  float *v66; // r11
  int v67; // ctr
  float *v74; // r7

  list = this->surfaces.list;
  v9 = list + 1;
  idTriangles::FreeCPUData(this: list[1].geometry);
  v9->material = material;
  if ( material != nullptr )
  {
    geometry = v9->geometry;
    p_vertexBuffer = (idPixelUnpackBuffer *)&geometry->vertexBuffer;
    p_indexBuffer = &geometry->indexBuffer;
    v13 = (float *)idVertexBuffer::MapBuffer(this: &geometry->vertexBuffer, mapType: BM_WRITE_NOSYNC);
    v14 = idIndexBuffer::MapBuffer(this: p_indexBuffer, mapType: BM_WRITE_NOSYNC);
    memcpy(Dst: v13, Src: vertices->list, Size: 32 * vertices->num);
    memcpy(Dst: v14, Src: indices->list, Size: 2 * indices->num);
    num = vertices->num;
    v16 = 0;
    _FP31 = 1.0e30;
    _FP29 = -1.0e30;
    _FP30 = 1.0e30;
    _FP28 = 1.0e30;
    _FP26 = -1.0e30;
    _FP27 = -1.0e30;
    if ( num >= 4 )
    {
      v23 = v13 + 10;
      do
      {
        v16 += 4;
        _FP12 = (float)((float)_FP31 - *(v23 - 10));
        _FP10 = (float)((float)_FP28 - *(v23 - 9));
        _FP9 = (float)((float)_FP30 - *(v23 - 8));
        _FP7 = (float)(*(v23 - 10) - (float)_FP29);
        _FP5 = (float)(*(v23 - 9) - (float)_FP27);
        _FP3 = (float)(*(v23 - 8) - (float)_FP26);
        __asm { fsel      f12, f12, f0, f31 }
        __asm { fsel      f9, f9, f6, f30 }
        __asm { fsel      f10, f10, f8, f28 }
        __asm { fsel      f7, f7, f0, f29 }
        __asm { fsel      f8, f5, f8, f27 }
        __asm { fsel      f3, f3, f6, f26 }
        _FP23 = (float)((float)_FP12 - *(v23 - 2));
        _FP21 = (float)((float)_FP9 - *v23);
        _FP22 = (float)((float)_FP10 - *(v23 - 1));
        _FP20 = (float)(*(v23 - 2) - (float)_FP7);
        _FP2 = (float)(*(v23 - 1) - (float)_FP8);
        _FP1 = (float)(*v23 - (float)_FP3);
        __asm
        {
          fsel      f12, f23, f4, f12
          fsel      f9, f21, f25, f9
          fsel      f10, f22, f13, f10
          fsel      f7, f20, f4, f7
          fsel      f4, f2, f13, f8
          fsel      f3, f1, f25, f3
        }
        _FP2 = (float)((float)_FP12 - v23[6]);
        _FP13 = (float)((float)_FP9 - v23[8]);
        _FP1 = (float)((float)_FP10 - v23[7]);
        _FP11 = (float)(v23[6] - (float)_FP7);
        _FP8 = (float)(v23[7] - (float)_FP4);
        _FP30 = (float)(v23[8] - (float)_FP3);
        __asm
        {
          fsel      f2, f2, f31, f12
          fsel      f13, f13, f5, f9
          fsel      f1, f1, f28, f10
          fsel      f12, f11, f31, f7
          fsel      f11, f8, f28, f4
          fsel      f10, f30, f5, f3
        }
        _FP9 = (float)((float)_FP2 - v23[14]);
        _FP7 = (float)((float)_FP13 - v23[16]);
        _FP8 = (float)((float)_FP1 - v23[15]);
        _FP5 = (float)(v23[14] - (float)_FP12);
        _FP4 = (float)(v23[15] - (float)_FP11);
        _FP3 = (float)(v23[16] - (float)_FP10);
        v23 += 32;
        __asm
        {
          fsel      f31, f9, f6, f2
          fsel      f30, f7, f27, f13
          fsel      f28, f8, f29, f1
          fsel      f29, f5, f6, f12
          fsel      f27, f4, f26, f11
          fsel      f26, f3, f24, f10
        }
      }
      while ( v16 < num - 3 );
    }
    if ( v16 < num )
    {
      v66 = &v13[8 * v16];
      v67 = num - v16;
      do
      {
        _FP6 = (float)((float)_FP28 - v66[1]);
        _FP10 = (float)((float)_FP30 - v66[2]);
        _FP12 = (float)((float)_FP31 - *v66);
        _FP8 = (float)(*v66 - (float)_FP29);
        _FP5 = (float)(v66[1] - (float)_FP27);
        _FP3 = (float)(v66[2] - (float)_FP26);
        v66 += 8;
        __asm
        {
          fsel      f28, f6, f9, f28
          fsel      f30, f10, f13, f30
          fsel      f31, f12, f0, f31
          fsel      f29, f8, f0, f29
          fsel      f27, f5, f9, f27
          fsel      f26, f3, f13, f26
        }
        --v67;
      }
      while ( v67 != 0 );
    }
    idVertexBuffer::UnmapBuffer(this: p_vertexBuffer);
    idIndexBuffer::UnmapBuffer(this: p_indexBuffer);
    v9->geometry->numVerts = vertices->num;
    v9->geometry->numIndexes = indices->num;
    v74 = (float *)v9->geometry;
    *v74 = _FP31;
    v74[1] = _FP28;
    v74[2] = _FP30;
    v74[3] = _FP29;
    v74[4] = _FP27;
    v74[5] = _FP26;
    this->referenceBounds.b[0].x = _FP31;
    this->referenceBounds.b[0].y = _FP28;
    this->referenceBounds.b[0].z = _FP30;
    this->referenceBounds.b[1].x = _FP29;
    this->referenceBounds.b[1].y = _FP27;
    this->referenceBounds.b[1].z = _FP26;
  }
}


// ========================================================================
// ?IsValid@idRenderModelCuttableDynamic@@QBA_NXZ
// EA  : 0x827C76E8
// RVA : 0x007C76E8
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttabledynamic.cpp
// ========================================================================

int __fastcall idRenderModelCuttableDynamic::IsValid(idRenderModelCuttableDynamic *this)
{
  int num; // r7
  idRenderModelSurface *list; // r8
  int v3; // r9
  int i; // r11
  idRenderModelSurface *v5; // r10

  num = this->surfaces.num;
  if ( num <= 0 )
    return 0;
  list = this->surfaces.list;
  v3 = 0;
  for ( i = 0; ; ++i )
  {
    v5 = &list[i];
    if ( &list[i] != nullptr && v5->geometry != nullptr && v5->material != nullptr )
      break;
    if ( ++v3 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?Upload@idRenderModelCuttableDynamic@@QAAXPBVidMaterial@@0ABV?$idList@VidDrawVert@@$04@@ABV?$idList@VidVec2@@$04@@ABV?$idList@G$04@@@Z
// EA  : 0x827C7740
// RVA : 0x007C7740
// PDB : w:\tech5\engine\models\cuttable\rendermodelcuttabledynamic.cpp
// ========================================================================

void __fastcall idRenderModelCuttableDynamic::Upload(
        idRenderModelCuttableDynamic *this,
        const idMaterial *renderMaterial,
        const idMaterial *depthMaterial,
        const idList<idDrawVert,5> *vertices,
        const idList<idVec2,5> *st,
        const idList<unsigned short,5> *indices)
{
  idRenderModelSurface *list; // r11
  idVertexBuffer *stMap; // r30
  void *v11; // r3

  idRenderModelCuttableDynamic::UploadRenderGeometry(this, material: renderMaterial, vertices, indices);
  list = this->surfaces.list;
  list->material = depthMaterial;
  if ( depthMaterial != nullptr )
  {
    stMap = list->stMap;
    v11 = idVertexBuffer::MapBuffer(this: stMap, mapType: BM_WRITE_NOSYNC);
    memcpy(Dst: v11, Src: st->list, Size: 8 * st->num);
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)stMap);
  }
}

