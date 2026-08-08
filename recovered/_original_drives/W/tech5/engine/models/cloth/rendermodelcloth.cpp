
// ========================================================================
// ?Save@idRenderModelCloth@@UBAXPAVidFile@@@Z
// EA  : 0x827AF750
// RVA : 0x007AF750
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void __fastcall idRenderModelCloth::Save(idRenderModelCloth *this, idFile *fp)
{
  idFile_vtbl *v4; // r10
  const idDeclCloth *clothSystem; // r11
  idFile_vtbl *v6; // r8
  int v7; // r28
  int v8; // r27
  idRenderModelCloth::clothAttachInfo_t *v9; // r29
  idFile_vtbl *v10; // r8
  int v11; // r11
  bool v12[4]; // [sp+50h] [-40h] BYREF
  int num; // [sp+54h] [-3Ch] BYREF
  int v14; // [sp+58h] [-38h] BYREF

  idRenderModel::Save(this, fp);
  v4 = fp->__vftable;
  v12[0] = this->clothSystem != nullptr;
  v4->Write(this: fp, a2: v12, a3: 1u);
  clothSystem = this->clothSystem;
  if ( clothSystem != nullptr )
    idFile::WriteString(this: fp, string: clothSystem->name.str);
  fp->Write(this: fp, a2: &this->clothType, a3: 4u);
  v6 = fp->__vftable;
  num = this->attachPoints.num;
  v6->Write(this: fp, a2: &num, a3: 4u);
  v7 = 0;
  if ( this->attachPoints.num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = &this->attachPoints.list[v8];
      fp->Write(this: fp, a2: v9, a3: 12u);
      fp->Write(this: fp, a2: &v9->clothAnchorType, a3: 4u);
      fp->Write(this: fp, a2: &v9->row, a3: 4u);
      fp->Write(this: fp, a2: &v9->col, a3: 4u);
      ++v7;
      ++v8;
    }
    while ( v7 < this->attachPoints.num );
  }
  fp->Write(this: fp, a2: &this->width, a3: 4u);
  fp->Write(this: fp, a2: &this->height, a3: 4u);
  fp->Write(this: fp, a2: &this->vSpacing, a3: 4u);
  fp->Write(this: fp, a2: &this->hSpacing, a3: 4u);
  v10 = fp->__vftable;
  v14 = this->collisionSpheres.num;
  v10->Write(this: fp, a2: &v14, a3: 4u);
  v11 = this->collisionSpheres.num;
  if ( v11 > 0 )
    fp->Write(this: fp, a2: this->collisionSpheres.list, a3: 16 * v11);
}


// ========================================================================
// ?BuildClothModel@idRenderModelCloth@@AAAXXZ
// EA  : 0x827AF958
// RVA : 0x007AF958
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRenderModelCloth::BuildClothModel(idRenderModelCloth *this)
{
  idClothSim *clothSimulation; // r11
  int width; // r27
  double hSpacing; // fp31
  int height; // r23
  double vSpacing; // fp30
  int v7; // r22
  unsigned int v8; // r20
  idTriangles *v9; // r30
  int v10; // r28
  idVertexBuffer *vertexBuffer; // r29
  unsigned __int16 *buffer; // r26
  int v13; // r8
  int v14; // ctr
  __int16 v15; // r6
  int v16; // r9
  unsigned __int16 *v17; // r11
  unsigned __int16 v18; // r4
  unsigned __int16 v19; // r3
  unsigned __int16 v20; // r10
  int v21; // r11
  int v22; // r10
  int v23; // ctr
  int v24; // r7
  unsigned __int16 *v25; // r8
  int v26; // r9
  int v27; // r8
  __int16 v28; // r6
  unsigned __int16 *v29; // r10
  unsigned __int16 v30; // r28
  unsigned __int16 v31; // r25
  unsigned __int16 *v32; // r8
  idVertexBuffer *v33; // r28
  int i; // r25
  __int64 v35; // r6 OVERLAPPED
  int v36; // r4 OVERLAPPED
  char *v37; // r3
  int v38; // r8
  int v39; // r9
  int v40; // r10
  int v41; // ctr
  __int64 v42; // r6 OVERLAPPED
  int v43; // r7
  double v44; // fp0
  double v45; // fp12
  int v46; // r7
  float *v47; // r11
  __int64 v48; // r10 OVERLAPPED
  int v49; // r7
  double v50; // fp13
  double v51; // fp10
  int v52; // r8
  double v53; // fp0
  double v54; // fp12
  int v55; // r11
  idTriangles *v56; // r3
  idBounds *v57; // r3
  __int64 v58; // r9
  float *clothBoundsFromJob; // r11
  float *p_clothBounds; // r11
  float *v63; // r11
  float *clothBounds; // r10
  idRenderModel *material; // [sp+80h] [-130h]
  idTempArray<unsigned short> v66[2]; // [sp+D0h] [-E0h] BYREF
  idTriangles v67; // [sp+E0h] [-D0h] BYREF

  if ( this->clothSystem != nullptr )
  {
    if ( this->clothSimulation != nullptr )
    {
      if ( this->clothParms == nullptr )
        this->clothParms = (clothParms_t *)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\engine\\models\\cloth\\RenderModelCloth.cpp(292) : TAG_CLOTH",
                                             size: 0xACu,
                                             tag: TAG_CLOTH,
                                             zeroBuffer: false,
                                             align: ALIGN_16,
                                             heap: HEAP_DEFAULTHEAP);
      if ( this->clothBounds == nullptr )
        this->clothBounds = (idBounds *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\engine\\models\\cloth\\RenderModelCloth.cpp(296) : TAG_CLOTH",
                                          size: 0x18u,
                                          tag: TAG_CLOTH,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
      clothSimulation = this->clothSimulation;
      width = clothSimulation->width;
      hSpacing = clothSimulation->hSpacing;
      height = clothSimulation->height;
      vSpacing = clothSimulation->vSpacing;
      if ( width <= 1 || height <= 1 || hSpacing < 0.001 || vSpacing < 0.001 )
      {
        idLib::Warning(fmt: "idRenderModelCloth::BuildClothModel() - bad width, height, hSpacing, or vSpacing");
      }
      else
      {
        v7 = height - 1;
        if ( this->rect )
        {
          this->numVerts = width * height;
          v8 = 6 * (width - 1) * v7;
        }
        else
        {
          this->numVerts = height * height;
          v8 = (6 * height - 6) * v7;
        }
        this->FreeSurfaces(this);
        v9 = nullptr;
        this->deferredVerts = nullptr;
        v10 = 3;
        vertexBuffer = this->vertexBuffer;
        do
        {
          if ( vertexBuffer->size < 0 )
            idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)vertexBuffer);
          idVertexBuffer::FreeBufferObject(this: vertexBuffer);
          --v10;
          ++vertexBuffer;
        }
        while ( v10 != 0 );
        idIndexBuffer::FreeBufferObject(this: &this->indexBuffer);
        idTempArray<unsigned short>::idTempArray<unsigned short>(this: v66, num: v8);
        buffer = v66[0].buffer;
        if ( this->rect )
        {
          v13 = 0;
          v14 = height - 1;
          v15 = 0;
          do
          {
            v16 = 0;
            v17 = &buffer[v13 - 1];
            do
            {
              v18 = v15 + v16 + 1;
              v17[1] = v15 + v16;
              v19 = v15 + v16 + width;
              v17[2] = v18;
              v20 = width + 1 + v15 + v16++;
              v17[3] = v19;
              v13 += 6;
              v17[4] = v18;
              v17[5] = v20;
              v17 += 6;
              *v17 = v19;
            }
            while ( v16 < width - 1 );
            v15 += width;
            --v14;
          }
          while ( v14 != 0 );
        }
        else
        {
          v21 = 0;
          v22 = 0;
          v23 = height - 1;
          v24 = 1;
          do
          {
            v25 = &buffer[v22];
            *v25 = v21;
            v25[1] = v24 + v21;
            v26 = v22 + 3;
            buffer[v22 + 2] = v24 + v21 + 1;
            v27 = 0;
            if ( v24 - 1 > 0 )
            {
              v28 = v24 + 2;
              v29 = &buffer[v26 - 1];
              do
              {
                v30 = v21;
                v29[1] = v21;
                v31 = v28 + v21;
                v29[2] = v24 + 1 + v21;
                v29[3] = v28 + v21++;
                ++v27;
                v29[4] = v21;
                v26 += 6;
                v29[5] = v30;
                v29 += 6;
                *v29 = v31;
              }
              while ( v27 < v24 - 1 );
            }
            v24 += 2;
            v32 = &buffer[v26];
            *v32 = v21;
            v32[1] = v24 + v21 - 1;
            v22 = v26 + 3;
            buffer[v26 + 2] = v24 + v21++;
            --v23;
          }
          while ( v23 != 0 );
        }
        idIndexBuffer::AllocBufferObject(
          this: &this->indexBuffer,
          data: buffer,
          allocSize: 2 * v8,
          allocUsage: BU_DYNAMIC);
        v33 = this->vertexBuffer;
        for ( i = 3; i != 0; --i )
        {
          idVertexBuffer::AllocBufferObject(
            this: v33,
            data: nullptr,
            allocSize: 32 * this->numVerts,
            vertexMask: 31,
            allocUsage: BU_DYNAMIC);
          v37 = (char *)idVertexBuffer::MapBuffer(this: v33, mapType: BM_WRITE);
          if ( this->rect )
          {
            v38 = 0;
            v39 = 0;
            do
            {
              v40 = 0;
              v41 = width;
              HIDWORD(v42) = height - 1;
              LODWORD(v42) = width - 1;
              v66[1] = (idTempArray<unsigned short>)v42;
              v43 = v38;
              v44 = (float)((float)*(__int64 *)((char *)&v42 - 4) * (float)vSpacing);
              v45 = (float)((float)((float)*(__int64 *)((char *)&v42 - 4) * (float)vSpacing)
                          / (float)((float)*(__int64 *)(&v36 - 1) * (float)vSpacing));
              do
              {
                v46 = v40;
                v47 = (float *)&v37[32 * v39 + 32 * v40++];
                v47[1] = v44;
                v47[2] = 0.0;
                *v47 = (float)*(__int64 *)((char *)&v42 - 4) * (float)hSpacing;
                v47[3] = v45;
                *((_BYTE *)v47 + 31) = -1;
                *((_BYTE *)v47 + 30) = -1;
                *((_BYTE *)v47 + 29) = -1;
                *((_BYTE *)v47 + 28) = -1;
                v47[4] = (float)((float)1.0 / (float)((float)v42 * (float)hSpacing))
                       * (float)((float)*(__int64 *)((char *)&v42 - 4) * (float)hSpacing);
                --v41;
              }
              while ( v41 != 0 );
              ++v38;
              v39 += width;
            }
            while ( v38 < height );
          }
          else
          {
            v48 = (unsigned int)(width - 1);
            v49 = 0;
            v50 = (double)(unsigned int)v48;
            v51 = (float)((float)((float)v50 * (float)hSpacing) * (float)0.5);
            v52 = 1;
            do
            {
              *(__int64 *)((char *)&v48 - 4) = (unsigned int)v49;
              v53 = v51;
              v54 = (double)(unsigned int)v49;
              if ( v52 > 0 )
              {
                v55 = (int)&v37[32 * HIDWORD(v48) - 4];
                do
                {
                  LODWORD(v48) = v48 + 1;
                  *(float *)(v55 + 4) = v53;
                  *(float *)(v55 + 8) = (float)v54 * (float)vSpacing;
                  *(float *)(v55 + 12) = 128.0;
                  *(_BYTE *)(v55 + 35) = -1;
                  *(float *)(v55 + 20) = (float)((float)1.0 / (float)((float)v50 * (float)hSpacing)) * (float)v53;
                  *(_BYTE *)(v55 + 34) = -1;
                  LODWORD(v35) = height - 1;
                  *(float *)(v55 + 16) = (float)((float)v54 * (float)vSpacing) / (float)((float)v35 * (float)vSpacing);
                  *(_BYTE *)(v55 + 33) = -1;
                  ++HIDWORD(v48);
                  v53 = (float)((float)v53 + (float)hSpacing);
                  v55 += 32;
                  *(_BYTE *)v55 = -1;
                }
                while ( (int)v48 < v52 );
              }
              ++v49;
              v51 = (float)((float)v51 - (float)hSpacing);
              v52 += 2;
            }
            while ( v49 < height );
          }
          idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)v33++);
        }
        material = (idRenderModel *)this->clothSystem->material;
        v56 = (idTriangles *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x84u,
                               tag: TAG_TRIANGLES,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
        if ( v56 != nullptr )
          v9 = idTriangles::idTriangles(this: v56);
        v9->numVerts = this->numVerts;
        v9->numIndexes = v8;
        idVertexBuffer::Reference(this: &v9->vertexBuffer, other: this->vertexBuffer);
        idIndexBuffer::Reference(this: &v9->indexBuffer, other: &this->indexBuffer);
        idRenderModel::AddSurface(this: material, surf: nullptr);
        v57 = idTriangles::BoundsFromVertScan(this: &v67, result: &v9->bounds);
        LODWORD(v58) = width;
        v9->bounds = *v57;
        HIDWORD(v58) = &v57->b[1];
        _FP13 = (float)((float)((float)v58 * (float)hSpacing)
                      - (float)((float)__SPAIR64__(width, height) * (float)vSpacing));
        __asm { fsel      f12, f13, f0, f2 }
        v9->bounds.b[0].x = v9->bounds.b[0].x - (float)_FP12;
        v9->bounds.b[0].y = v9->bounds.b[0].y - (float)_FP12;
        v9->bounds.b[0].z = v9->bounds.b[0].z - (float)_FP12;
        v9->bounds.b[1].x = v9->bounds.b[1].x + (float)_FP12;
        v9->bounds.b[1].y = v9->bounds.b[1].y + (float)_FP12;
        v9->bounds.b[1].z = (float)_FP12 + v9->bounds.b[1].z;
        idRenderModel::FinishSurfaces(this);
        clothBoundsFromJob = (float *)this->clothSimulation->clothBoundsFromJob;
        *clothBoundsFromJob = v9->bounds.b[0].x;
        clothBoundsFromJob[1] = v9->bounds.b[0].y;
        clothBoundsFromJob[2] = v9->bounds.b[0].z;
        clothBoundsFromJob[3] = v9->bounds.b[1].x;
        clothBoundsFromJob[4] = v9->bounds.b[1].y;
        clothBoundsFromJob[5] = v9->bounds.b[1].z;
        p_clothBounds = (float *)&this->clothSimulation->clothBounds;
        *p_clothBounds = v9->bounds.b[0].x;
        p_clothBounds[1] = v9->bounds.b[0].y;
        p_clothBounds[2] = v9->bounds.b[0].z;
        p_clothBounds[3] = v9->bounds.b[1].x;
        p_clothBounds[4] = v9->bounds.b[1].y;
        p_clothBounds[5] = v9->bounds.b[1].z;
        v63 = (float *)&this->clothSimulation->clothBounds;
        clothBounds = (float *)this->clothBounds;
        *clothBounds = *v63;
        clothBounds[1] = v63[1];
        clothBounds[2] = v63[2];
        clothBounds[3] = v63[3];
        clothBounds[4] = v63[4];
        clothBounds[5] = v63[5];
        if ( buffer != nullptr )
          idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
      }
    }
    else
    {
      idLib::Warning(fmt: "idRenderModelCloth::BuildClothModel() - clothSimulation is NULL");
    }
  }
  else
  {
    idLib::Warning(fmt: "idRenderModelCloth::BuildClothModel() - clothSystem is NULL");
  }
}


// ========================================================================
// __unwind$231742
// EA  : 0x827B016C
// RVA : 0x007B016C
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void _unwind_231742()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 432 + 208));
}


// ========================================================================
// __unwind$231743
// EA  : 0x827B0194
// RVA : 0x007B0194
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void _unwind_231743()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 432 + 96), tag: TAG_TRIANGLES);
}


// ========================================================================
// ??0idRenderModelCloth@@QAA@PBVidDeclCloth@@@Z
// EA  : 0x827B06F0
// RVA : 0x007B06F0
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

idRenderModelCloth *__fastcall idRenderModelCloth::idRenderModelCloth(
        idRenderModelCloth *this,
        const idDeclCloth *clothSys)
{
  char v4; // r6

  idRenderModel::idRenderModel(this);
  this->clothSimulation = nullptr;
  this->__vftable = (idRenderModelCloth_vtbl *)&idRenderModelCloth::`vftable';
  `eh vector constructor iterator'(
    ptr: this->vertexBuffer,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  idIndexBuffer::idIndexBuffer(this: &this->indexBuffer);
  this->clothSystem = clothSys;
  this->deferredVerts = nullptr;
  this->numVerts = 0;
  this->currentIndex = 0;
  this->clothBounds = nullptr;
  this->clothParms = nullptr;
  this->rect = false;
  this->clothType = CLOTH_INVALID;
  this->attachPoints.list = nullptr;
  this->attachPoints.granularity = 0;
  this->attachPoints.memTag = 5;
  this->attachPoints.listStatic = 0;
  this->attachPoints.size = 0;
  this->attachPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attachPoints);
  this->collisionSpheres.list = nullptr;
  this->collisionSpheres.granularity = 0;
  this->collisionSpheres.memTag = 5;
  this->collisionSpheres.listStatic = 0;
  this->collisionSpheres.size = 0;
  this->collisionSpheres.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->collisionSpheres);
  v4 = *((_BYTE *)&this->g + 105);
  this->width = 0;
  this->height = 0;
  *((_BYTE *)&this->g + 105) = v4 | 0xC0;
  this->vSpacing = 0.0;
  this->hSpacing = 0.0;
  return this;
}


// ========================================================================
// __unwind$232451
// EA  : 0x827B07E0
// RVA : 0x007B07E0
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void _unwind_232451()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$232452
// EA  : 0x827B0808
// RVA : 0x007B0808
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void _unwind_232452()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 2036),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$232453
// EA  : 0x827B0844
// RVA : 0x007B0844
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void _unwind_232453()
{
  int v0; // r12

  idIndexBuffer::~idIndexBuffer(this: (idIndexBuffer *)(*(_DWORD *)(v0 - 128 + 148) + 2084));
}


// ========================================================================
// __unwind$232454
// EA  : 0x827B0870
// RVA : 0x007B0870
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void _unwind_232454()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 2132));
}


// ========================================================================
// ??1idRenderModelCloth@@MAA@XZ
// EA  : 0x827B0950
// RVA : 0x007B0950
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void __fastcall idRenderModelCloth::~idRenderModelCloth(idRenderModelCloth *this)
{
  idClothSim *clothSimulation; // r29
  int v3; // r28
  idVertexBuffer *vertexBuffer; // r29
  idVertexBuffer *v5; // r28
  int i; // r29
  idVec4 *list; // r4
  idRenderModelCloth::clothAttachInfo_t *v8; // r4

  this->__vftable = (idRenderModelCloth_vtbl *)&idRenderModelCloth::`vftable';
  clothSimulation = this->clothSimulation;
  if ( clothSimulation != nullptr )
  {
    idClothSim::~idClothSim(this: this->clothSimulation);
    idMem::Free(this: &mem, ptr: clothSimulation, align: ALIGN_16);
  }
  v3 = 3;
  vertexBuffer = this->vertexBuffer;
  do
  {
    if ( vertexBuffer->size < 0 )
      idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)vertexBuffer);
    --v3;
    ++vertexBuffer;
  }
  while ( v3 != 0 );
  v5 = this->vertexBuffer;
  for ( i = 3; i != 0; --i )
    idVertexBuffer::FreeBufferObject(this: v5++);
  idIndexBuffer::FreeBufferObject(this: &this->indexBuffer);
  idMem::Free(this: &mem, ptr: this->clothBounds, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->clothParms, align: ALIGN_16);
  if ( this->collisionSpheres.listStatic == 0 || this->collisionSpheres.listStatic == 2 )
  {
    list = this->collisionSpheres.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->collisionSpheres.list = nullptr;
    this->collisionSpheres.size = 0;
  }
  this->collisionSpheres.num = 0;
  if ( this->attachPoints.listStatic == 0 || this->attachPoints.listStatic == 2 )
  {
    v8 = this->attachPoints.list;
    if ( v8 != nullptr )
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    this->attachPoints.list = nullptr;
    this->attachPoints.size = 0;
  }
  this->attachPoints.num = 0;
  idIndexBuffer::~idIndexBuffer(this: &this->indexBuffer);
  `eh vector destructor iterator'(
    ptr: this->vertexBuffer,
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$232601_0
// EA  : 0x827B0AC4
// RVA : 0x007B0AC4
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void _unwind_232601_0()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$232602_0
// EA  : 0x827B0AEC
// RVA : 0x007B0AEC
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void _unwind_232602_0()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 2036),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$232603_0
// EA  : 0x827B0B28
// RVA : 0x007B0B28
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void _unwind_232603_0()
{
  int v0; // r12

  idIndexBuffer::~idIndexBuffer(this: (idIndexBuffer *)(*(_DWORD *)(v0 - 144 + 164) + 2084));
}


// ========================================================================
// __unwind$232604_0
// EA  : 0x827B0B54
// RVA : 0x007B0B54
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void _unwind_232604_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2132));
}


// ========================================================================
// __unwind$232605_0
// EA  : 0x827B0B80
// RVA : 0x007B0B80
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void _unwind_232605_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2148));
}


// ========================================================================
// ?CreateClothSim@idRenderModelCloth@@QAAXPBVidDeclCloth@@W4idClothType_t@1@AAV?$idList@UclothAttachInfo_t@idRenderModelCloth@@$04@@AAV?$idList@VidVec4@@$04@@HHMM@Z
// EA  : 0x827B0BB8
// RVA : 0x007B0BB8
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void __fastcall idRenderModelCloth::CreateClothSim(
        idRenderModelCloth *this,
        const idDeclCloth *clothDecl,
        idRenderModelCloth::idClothType_t clothType,
        idList<idRenderModelCloth::clothAttachInfo_t,5> *attachPoints,
        idList<idVec4,5> *collisionSpheres,
        int widthOverride,
        int heightOverride,
        double hSpacingOverride,
        double vSpacingOverride)
{
  bool v18; // r11
  bool v19; // r7
  const idDeclCloth *v20; // r6
  idClothSim *v21; // r3
  idClothSim *v22; // r3
  int v23; // r25
  int v24; // r29
  int v25; // r27
  idRenderModelCloth::clothAttachInfo_t *v26; // r11
  idRenderModelCloth::clothAttachInfo_t::idClothAnchorType_t clothAnchorType; // r10
  int v28; // r28
  int v29; // r29
  idClothSim *clothSimulation; // r3
  double x; // fp0
  idVec3 *v32; // [sp+50h] [-80h]
  idSphere v33; // [sp+60h] [-70h] BYREF

  if ( clothType == CLOTH_INVALID )
    idLib::Error(fmt: "Invalid cloth type");
  this->clothSystem = clothDecl;
  this->clothType = clothType;
  idList<idRenderModelCloth::clothAttachInfo_t,5>::operator=(this: &this->attachPoints, other: attachPoints);
  idList<idVec4,5>::operator=(this: &this->collisionSpheres, other: collisionSpheres);
  this->width = clothDecl->width;
  this->height = clothDecl->height;
  this->hSpacing = clothDecl->hSpacing;
  this->vSpacing = clothDecl->vSpacing;
  if ( widthOverride > 0 )
    this->width = widthOverride;
  if ( heightOverride > 0 )
    this->height = heightOverride;
  if ( hSpacingOverride > 0.0 )
    this->hSpacing = hSpacingOverride;
  if ( vSpacingOverride > 0.0 )
    this->vSpacing = vSpacingOverride;
  if ( clothType == CLOTH_FLAG_TRIANGLE || (v18 = true, clothType == CLOTH_TARP_TRIANGLE) )
    v18 = false;
  this->rect = v18;
  v21 = (idClothSim *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x114u,
                        tag: TAG_CLOTH,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v21 != nullptr )
    v22 = idClothSim::idClothSim(
            this: v21,
            w: this->width,
            h: this->height,
            hGridSpacing: this->hSpacing,
            vGridSpacing: this->vSpacing,
            clothSystem: v20,
            rect: v19,
            a8: clothDecl,
            a9: this->rect);
  else
    v22 = nullptr;
  this->clothSimulation = v22;
  v23 = 0;
  if ( attachPoints->num > 0 )
  {
    v24 = 0;
    while ( 1 )
    {
      v25 = 0;
      v26 = &attachPoints->list[v24];
      clothAnchorType = v26->clothAnchorType;
      if ( clothAnchorType == ANCHOR_CORNER1 )
        break;
      switch ( clothAnchorType )
      {
        case ANCHOR_CORNER2:
          v26->col = 0;
          attachPoints->list[v24].row = this->height - 1;
          v25 = this->clothSimulation->height * this->clothSimulation->height - 1;
          goto LABEL_40;
        case ANCHOR_CORNER3:
          v26->col = this->width - 1;
          attachPoints->list[v24].row = this->height - 1;
          v25 = this->clothSimulation->height * this->clothSimulation->height - this->clothSimulation->width;
          goto LABEL_40;
        case ANCHOR_CORNER4:
          v26->col = this->width - 1;
          attachPoints->list[v24].row = 0;
          goto LABEL_40;
        case ANCHOR_MID1:
          v26->col = 0;
          attachPoints->list[v24].row = this->height / 2;
          goto LABEL_40;
        case ANCHOR_MID2:
          v26->col = this->width / 2;
          attachPoints->list[v24].row = this->height - 1;
          goto LABEL_40;
        case ANCHOR_MID3:
          v26->col = this->width - 1;
          attachPoints->list[v24].row = this->height / 2;
          goto LABEL_40;
        case ANCHOR_MID4:
          v26->col = this->width / 2;
          attachPoints->list[v24].row = 0;
          goto LABEL_40;
        case ANCHOR_CENTER:
          v26->col = this->width / 2;
          attachPoints->list[v24].row = this->height / 2;
          goto LABEL_40;
        default:
          break;
      }
      if ( clothAnchorType != ANCHOR_DEFINED || v26->row <= this->height && v26->col <= this->width )
        goto LABEL_40;
LABEL_43:
      ++v23;
      ++v24;
      if ( v23 >= attachPoints->num )
        goto LABEL_44;
    }
    v26->col = 0;
    attachPoints->list[v24].row = 0;
LABEL_40:
    if ( this->rect )
      v25 = attachPoints->list[v24].row * this->clothSimulation->width + attachPoints->list[v24].col;
    idClothSim::SetAnchor(this: this->clothSimulation, index: v25, tempAnchor: attachPoints->list[v24].tempAnchor);
    idClothSim::SetAnchorPosition(this: this->clothSimulation, index: v25, org: &attachPoints->list[v24].point);
    goto LABEL_43;
  }
LABEL_44:
  v28 = 0;
  if ( collisionSpheres->num > 0 )
  {
    v29 = 0;
    do
    {
      clothSimulation = this->clothSimulation;
      v32 = (idVec3 *)&collisionSpheres->list[v29];
      x = v32[1].x;
      v33.origin = *v32;
      v33.radius = x;
      idClothSim::AddCollisionSphere(this: clothSimulation, collisionSphere: &v33, isAPermanentSphere: true);
      ++v28;
      ++v29;
    }
    while ( v28 < collisionSpheres->num );
  }
  idRenderModelCloth::BuildClothModel(this);
  idRenderModel::CommitThisFrame(this);
}


// ========================================================================
// $LN145
// EA  : 0x827B0FD0
// RVA : 0x007B0FD0
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void _LN145()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 208 + 80), tag: TAG_CLOTH);
}


// ========================================================================
// ?Load@idRenderModelCloth@@UAA_NPAVidFile@@@Z
// EA  : 0x827B1210
// RVA : 0x007B1210
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

int __fastcall idRenderModelCloth::Load(idRenderModelCloth *this, idFile *fp)
{
  idFile_vtbl *v4; // r11
  const idDeclCloth *v6; // r3
  int v7; // r26
  char v8; // [sp+60h] [-A0h] BYREF
  int v9[3]; // [sp+64h] [-9Ch] BYREF
  idRenderModelCloth::clothAttachInfo_t v10; // [sp+70h] [-90h] BYREF
  idStr v11[3]; // [sp+90h] [-70h] BYREF

  if ( !idRenderModel::Load(this, fp) )
    return 0;
  v4 = fp->__vftable;
  v8 = 0;
  if ( v4->Read(this: fp, a2: &v8, a3: 1u) == 0 )
    return 0;
  if ( v8 != 0 )
  {
    v11[0].len = 0;
    v11[0].baseBuffer[0] = 0;
    v11[0].allocedAndFlag = 20;
    v11[0].data = v11[0].baseBuffer;
    if ( idFile::ReadString(this: fp, string: v11) == 0 )
    {
      idStr::FreeData(this: v11);
      return 0;
    }
    if ( v11[0].data != nullptr )
      v6 = (const idDeclCloth *)idDeclInfo::FindWithInheritance(
                                  this: &idDeclCloth::resourceList,
                                  name: v11[0].data,
                                  makeDefault: true);
    else
      v6 = nullptr;
    this->clothSystem = v6;
    idStr::FreeData(this: v11);
  }
  if ( fp->Read(this: fp, a2: &this->clothType, a3: 4u) == 0 || fp->Read(this: fp, a2: v9, a3: 4u) == 0 )
    return 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attachPoints);
  v7 = 0;
  if ( v9[0] > 0 )
  {
    do
    {
      v10.clothAnchorType = ANCHOR_DEFINED;
      memset(&v10.row, 0, 9);
      v10.point = vec3_origin;
      if ( fp->Read(this: fp, a2: &v10, a3: 12u) == 0
        || fp->Read(this: fp, a2: &v10.clothAnchorType, a3: 4u) == 0
        || fp->Read(this: fp, a2: &v10.row, a3: 4u) == 0
        || fp->Read(this: fp, a2: &v10.col, a3: 4u) == 0 )
      {
        return 0;
      }
      idList<idRenderModelCloth::clothAttachInfo_t,5>::Append(this: &this->attachPoints, obj: &v10);
    }
    while ( ++v7 < v9[0] );
  }
  fp->Read(this: fp, a2: &this->width, a3: 4u);
  fp->Read(this: fp, a2: &this->height, a3: 4u);
  fp->Read(this: fp, a2: &this->vSpacing, a3: 4u);
  fp->Read(this: fp, a2: &this->hSpacing, a3: 4u);
  if ( fp->Read(this: fp, a2: v9, a3: 4u) == 0 )
    return 0;
  if ( v9[0] > 0 )
  {
    idList<idSphere,5>::SetNum(this: &this->collisionSpheres, newNum: v9[0]);
    if ( fp->Read(this: fp, a2: this->collisionSpheres.list, a3: 16 * v9[0]) == 0 )
      return 0;
  }
  idRenderModelCloth::CreateClothSim(
    this,
    clothDecl: this->clothSystem,
    clothType: this->clothType,
    attachPoints: &this->attachPoints,
    collisionSpheres: &this->collisionSpheres,
    widthOverride: 0,
    heightOverride: 0,
    hSpacingOverride: 0.0,
    vSpacingOverride: 0.0);
  return 1;
}


// ========================================================================
// __unwind$232996
// EA  : 0x827B1530
// RVA : 0x007B1530
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void _unwind_232996()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 144));
}


// ========================================================================
// ?SerializeSnapshot@idRenderModelCloth@@UAAXAAVidSerializer@@_N@Z
// EA  : 0x827B1558
// RVA : 0x007B1558
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void __fastcall idRenderModelCloth::SerializeSnapshot(
        idRenderModelCloth *this,
        idSerializer *ser,
        bool serializeParmBlock)
{
  bool v5; // r19
  idBitMsg *msg; // r3
  unsigned int v7; // r10
  idRenderModelCloth::idClothType_t clothType; // r30
  int num; // r30
  idBitMsg *v10; // r3
  unsigned int v11; // r10
  int v12; // r20
  idList<idRenderModelCloth::clothAttachInfo_t,5> *p_attachPoints; // r26
  int size; // r11
  int v15; // r25
  int v16; // r23
  int v17; // r27
  int i; // r24
  int v19; // r30
  idBitMsg *v20; // r28
  float *p_tempAnchor; // r29
  idBitMsg *v22; // r3
  idRenderModelCloth::clothAttachInfo_t *v23; // r30
  idBitMsg *v24; // r3
  idRenderModelCloth::clothAttachInfo_t *v25; // r30
  idRenderModelCloth::clothAttachInfo_t *v26; // r9
  idBitMsg *v27; // r3
  int clothAnchorType; // r30
  idRenderModelCloth::clothAttachInfo_t *v29; // r11
  int Bits; // r30
  idBitMsg *v31; // r3
  unsigned int v32; // r11
  int v33; // r11
  int v34; // r26
  int v35; // r27
  int v36; // r30
  idBitMsg *v37; // r28
  float *p_w; // r29
  idBitMsg *v39; // r3
  idBitMsg *v40; // r3
  idBitMsg *v41; // r3
  idBitMsg *v42; // r3
  idMat3 *p_deferredAxis; // r5
  idRenderModelParms *p_deferredOrigin; // r4
  clothParms_t *clothParms; // r11
  int v46; // r30
  BOOL writing; // r10
  idBitMsg *v48; // r28
  float y; // r8
  float z; // r7
  float *v51; // r29
  idClothSim *clothSimulation; // r11
  double v53; // fp13
  double v54; // fp12
  int v55; // [sp+54h] [-8Ch] BYREF
  float x; // [sp+58h] [-88h]
  float v57; // [sp+5Ch] [-84h]
  float v58; // [sp+60h] [-80h]

  idRenderModel::SerializeSnapshot(this, ser, serializeParmBlock);
  v5 = (_cntlzw((unsigned int)this->clothSystem) & 0x20) != 0;
  idSerializer::Serialize<idDeclCloth>(this: ser, decl: &this->clothSystem);
  msg = ser->msg;
  v7 = _cntlzw(6u);
  clothType = this->clothType;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->clothType, numBits: 32 - v7);
  else
    clothType = idBitMsg::ReadBits(this: msg, numBits: 32 - v7);
  this->clothType = clothType;
  num = this->attachPoints.num;
  v10 = ser->msg;
  v11 = _cntlzw(0x20u);
  v12 = 32 - v11;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v10, value: this->attachPoints.num, numBits: 32 - v11);
  else
    num = idBitMsg::ReadBits(this: v10, numBits: 32 - v11);
  p_attachPoints = &this->attachPoints;
  if ( num <= this->attachPoints.size
    || (unsigned __int8)idList<idRenderModelCloth::clothAttachInfo_t,5>::Resize(this: &this->attachPoints, newsize: num) != 0 )
  {
    size = this->attachPoints.size;
    if ( num < size )
      size = num;
    this->attachPoints.num = size;
  }
  if ( num > 0 )
  {
    v15 = 32 - _cntlzw(0x10u);
    v16 = 32 - _cntlzw(0xBu);
    v17 = 0;
    for ( i = num; i != 0; --i )
    {
      v19 = 3;
      v20 = ser->msg;
      p_tempAnchor = (float *)&p_attachPoints->list[v17 - 1].tempAnchor;
      if ( ser->writing )
      {
        do
        {
          idBitMsg::WriteBits(this: v20, value: COERCE_INT(*++p_tempAnchor), numBits: 32);
          --v19;
        }
        while ( v19 != 0 );
      }
      else
      {
        do
        {
          --v19;
          *(_DWORD *)++p_tempAnchor = idBitMsg::ReadBits(this: v20, numBits: 32);
        }
        while ( v19 != 0 );
      }
      v22 = ser->msg;
      v23 = &p_attachPoints->list[v17];
      if ( ser->writing )
        idBitMsg::WriteBits(this: v22, value: v23->row, numBits: v15);
      else
        v23->row = idBitMsg::ReadBits(this: v22, numBits: v15);
      v24 = ser->msg;
      v25 = &p_attachPoints->list[v17];
      if ( ser->writing )
        idBitMsg::WriteBits(this: v24, value: v25->col, numBits: v15);
      else
        v25->col = idBitMsg::ReadBits(this: v24, numBits: v15);
      v26 = &p_attachPoints->list[v17];
      v27 = ser->msg;
      clothAnchorType = v26->clothAnchorType;
      if ( ser->writing )
        idBitMsg::WriteBits(this: v27, value: v26->clothAnchorType, numBits: v16);
      else
        clothAnchorType = idBitMsg::ReadBits(this: v27, numBits: v16);
      v29 = &p_attachPoints->list[v17++];
      v29->clothAnchorType = clothAnchorType;
    }
  }
  Bits = this->collisionSpheres.num;
  v31 = ser->msg;
  v32 = _cntlzw(0x10u);
  if ( ser->writing )
    idBitMsg::WriteBits(this: v31, value: this->collisionSpheres.num, numBits: 32 - v32);
  else
    Bits = idBitMsg::ReadBits(this: v31, numBits: 32 - v32);
  if ( Bits <= this->collisionSpheres.size
    || (unsigned __int8)idList<idRenderModelChain::splinePoint_t,85>::Resize(
                          this: (idList<idSphere,81> *)&this->collisionSpheres,
                          newsize: Bits) != 0 )
  {
    v33 = this->collisionSpheres.size;
    if ( Bits < v33 )
      v33 = Bits;
    this->collisionSpheres.num = v33;
  }
  v34 = 0;
  if ( this->collisionSpheres.num > 0 )
  {
    v35 = 0;
    do
    {
      v36 = 4;
      v37 = ser->msg;
      p_w = &this->collisionSpheres.list[v35 - 1].w;
      if ( ser->writing )
      {
        do
        {
          idBitMsg::WriteBits(this: v37, value: COERCE_INT(*++p_w), numBits: 32);
          --v36;
        }
        while ( v36 != 0 );
      }
      else
      {
        do
        {
          --v36;
          *(_DWORD *)++p_w = idBitMsg::ReadBits(this: v37, numBits: 32);
        }
        while ( v36 != 0 );
      }
      ++v34;
      ++v35;
    }
    while ( v34 < this->collisionSpheres.num );
  }
  v39 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v39, value: this->width, numBits: v12);
  else
    this->width = idBitMsg::ReadBits(this: v39, numBits: v12);
  v40 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v40, value: this->height, numBits: v12);
  else
    this->height = idBitMsg::ReadBits(this: v40, numBits: v12);
  v41 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v41, value: COERCE_INT(this->hSpacing), numBits: 32);
  else
    LODWORD(this->hSpacing) = idBitMsg::ReadBits(this: v41, numBits: 32);
  v42 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v42, value: COERCE_INT(this->vSpacing), numBits: 32);
  else
    LODWORD(this->vSpacing) = idBitMsg::ReadBits(this: v42, numBits: 32);
  if ( v5 )
  {
    p_deferredAxis = &this->deferredAxis;
    if ( this->useDeferredPosition )
    {
      p_deferredOrigin = (idRenderModelParms *)&this->deferredOrigin;
    }
    else
    {
      p_deferredAxis = &this->g.axis;
      p_deferredOrigin = &this->g;
    }
    idClothSim::SetOriginAxis(
      this: this->clothSimulation,
      newOrigin: &p_deferredOrigin->origin,
      newAxis: p_deferredAxis,
      updateParticles: false);
    this->clothSimulation->windDirection = vec3_origin;
    this->clothSimulation->timeDelta = 0.016000001;
  }
  clothParms = this->clothParms;
  v46 = 3;
  writing = ser->writing;
  v48 = ser->msg;
  y = clothParms->windDirection.y;
  z = clothParms->windDirection.z;
  v51 = (float *)&v55;
  x = clothParms->windDirection.x;
  v57 = y;
  v58 = z;
  if ( writing )
  {
    do
    {
      idBitMsg::WriteBits(this: v48, value: COERCE_INT(*++v51), numBits: 32);
      --v46;
    }
    while ( v46 != 0 );
  }
  else
  {
    do
    {
      --v46;
      *(_DWORD *)++v51 = idBitMsg::ReadBits(this: v48, numBits: 32);
    }
    while ( v46 != 0 );
  }
  if ( !ser->writing )
  {
    clothSimulation = this->clothSimulation;
    v53 = v57;
    v54 = v58;
    clothSimulation->windDirection.x = x;
    clothSimulation->windDirection.y = v53;
    clothSimulation->windDirection.z = v54;
  }
}


// ========================================================================
// ?SetupClothJob@idRenderModelCloth@@AAAXPAVidParallelJobList@@PAVidDrawVert@@@Z
// EA  : 0x827B1A40
// RVA : 0x007B1A40
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void __fastcall idRenderModelCloth::SetupClothJob(
        idRenderModelCloth *this,
        idParallelJobList *parallelJobList,
        idDrawVert *vertices)
{
  idClothSim *clothSimulation; // r11
  int currentDeferred; // r7
  int v8; // r30
  clothParms_t *clothParms; // r10
  _DWORD *v10; // r11
  float *v11; // r10
  float *v12; // r11
  const idDeclCloth *clothSystem; // r7
  idClothSim *v14; // r4
  clothParms_t *v15; // r3
  idClothSim *v16; // r4
  __int64 v17; // r8
  clothParms_t *v18; // r6
  idClothSim *v19; // r3
  float *clothBounds; // r11
  float *clothBoundsFromJob; // r10

  clothSimulation = this->clothSimulation;
  if ( clothSimulation->numClothParticles <= 100 )
  {
    currentDeferred = clothSimulation->currentDeferred;
    this->clothParms->type = CLOTH_FLAG;
    v8 = currentDeferred;
    this->clothParms->numIterations = this->clothSimulation->numIterations;
    this->clothSimulation->numIterations = 1;
    idList<idSphere,81>::Append(
      this: &this->clothSimulation->temporaryCollisionSpheres[currentDeferred],
      other: &this->clothSimulation->permanentCollisionSpheres);
    this->clothParms->cloth = this->clothSimulation->cloth;
    this->clothParms->numClothParticles = this->clothSimulation->numClothParticles;
    this->clothParms->springs = this->clothSimulation->springs.list;
    this->clothParms->numSprings = this->clothSimulation->springs.num;
    this->clothParms->collisions = this->clothSimulation->temporaryCollisionSpheres[v8].list;
    this->clothParms->numCollisions = this->clothSimulation->temporaryCollisionSpheres[v8].num;
    clothParms = this->clothParms;
    v10 = (const idDeclCloth **)((char *)&this->clothSimulation->clothDecl + v8 * 16);
    clothParms->collisionPlane.a = (float)v10[61];
    clothParms->collisionPlane.b = (float)v10[62];
    clothParms->collisionPlane.c = (float)v10[63];
    clothParms->collisionPlane.d = (float)v10[64];
    this->clothParms->hasCollisionPlane = ((LODWORD(this->clothSimulation->collisionPlane[v8].c)
                                          | LODWORD(this->clothSimulation->collisionPlane[v8].b)
                                          | LODWORD(this->clothSimulation->collisionPlane[v8].a))
                                         & 0x7FFFFFFF) != 0;
    this->clothParms->collisionFriction = this->clothSimulation->clothDecl->collisionFriction;
    this->clothParms->weaponTraces = this->clothSimulation->weaponTraces[v8].list;
    this->clothParms->numWeaponTraces = this->clothSimulation->weaponTraces[v8].num;
    this->clothParms->vertices = vertices;
    this->clothParms->bounds = this->clothBounds;
    v11 = (float *)this->clothSimulation;
    v12 = (float *)this->clothParms;
    clothSystem = this->clothSystem;
    v12[11] = v11[5];
    v12[12] = v11[6];
    v12[13] = v11[7];
    v12[14] = v11[8];
    v12[15] = v11[9];
    v12[16] = v11[10];
    v12[17] = v11[11];
    v12[18] = v11[12];
    v12[19] = v11[13];
    v12[20] = v11[14];
    v12[21] = v11[15];
    v12[22] = v11[16];
    v12[23] = clothSystem->friction;
    v14 = this->clothSimulation;
    v15 = this->clothParms;
    v15->gravity.x = v14->gravity.x;
    v15->gravity.y = v14->gravity.y;
    v15->gravity.z = v14->gravity.z;
    v15->windDirection.x = v14->windDirection.x;
    v15->windDirection.y = v14->windDirection.y;
    v15->windDirection.z = v14->windDirection.z;
    v15->width = v14->width;
    this->clothParms->height = this->clothSimulation->height;
    this->clothParms->vSpacing = this->clothSimulation->vSpacing;
    v16 = this->clothSimulation;
    this->clothParms->hSpacing = v16->hSpacing;
    HIDWORD(v17) = &clothsim_useJobs;
    this->clothParms->rect = this->clothSimulation->isRect;
    LODWORD(v17) = this->clothSimulation;
    v18 = this->clothParms;
    v18->timeDelta = *(float *)(v17 + 96);
    if ( parallelJobList != nullptr && (clothsim_useJobs.valueInteger == 1 || vertices == nullptr) )
      idParallelJobList::AddJob(
        this: parallelJobList,
        function: (void (__fastcall *)(void *))ClothGenJob,
        data: this->clothParms);
    else
      ClothGenJob(
        clothParms: this->clothParms,
        numClothParticles: (int)v16,
        a3: (int)&r_cuttablemodel_freecpudata.description,
        a4: (int)v18,
        a5: v17);
    v19 = this->clothSimulation;
    clothBounds = (float *)this->clothBounds;
    clothBoundsFromJob = (float *)v19->clothBoundsFromJob;
    *clothBoundsFromJob = *clothBounds;
    clothBoundsFromJob[1] = clothBounds[1];
    clothBoundsFromJob[2] = clothBounds[2];
    clothBoundsFromJob[3] = clothBounds[3];
    clothBoundsFromJob[4] = clothBounds[4];
    clothBoundsFromJob[5] = clothBounds[5];
    idClothSim::Swap(this: v19);
  }
}


// ========================================================================
// ?UpdateInView@idRenderModelCloth@@EAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x827B1D70
// RVA : 0x007B1D70
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

int __fastcall idRenderModelCloth::UpdateInView(
        idRenderModelCloth *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools)
{
  idPixelUnpackBuffer *v6; // r3
  idTriangles *geometry; // r30
  float *clothBounds; // r6
  float *v9; // r5
  int v10; // r11
  idDrawVert *v11; // r3

  if ( r_skipCloth.valueInteger != 0 || this->clothSimulation == nullptr || this->surfaces.num == 0 )
    return 0;
  if ( this->deferredVerts != nullptr )
  {
    v6 = (idPixelUnpackBuffer *)&this->vertexBuffer[this->currentIndex];
    if ( v6->size < 0 )
      idVertexBuffer::UnmapBuffer(this: v6);
  }
  geometry = this->surfaces.list->geometry;
  idVertexBuffer::Reference(this: &geometry->vertexBuffer, other: &this->vertexBuffer[this->currentIndex]);
  clothBounds = (float *)this->clothBounds;
  geometry->bounds.b[0].x = *clothBounds;
  geometry->bounds.b[0].y = clothBounds[1];
  geometry->bounds.b[0].z = clothBounds[2];
  geometry->bounds.b[1].x = clothBounds[3];
  geometry->bounds.b[1].y = clothBounds[4];
  geometry->bounds.b[1].z = clothBounds[5];
  v9 = (float *)this->clothBounds;
  this->referenceBounds.b[0].x = *v9;
  this->referenceBounds.b[0].y = v9[1];
  this->referenceBounds.b[0].z = v9[2];
  this->referenceBounds.b[1].x = v9[3];
  this->referenceBounds.b[1].y = v9[4];
  this->referenceBounds.b[1].z = v9[5];
  v10 = (this->currentIndex + 1) % 3;
  this->currentIndex = v10;
  v11 = (idDrawVert *)idVertexBuffer::MapBuffer(this: &this->vertexBuffer[v10], mapType: BM_WRITE_NOSYNC);
  this->deferredVerts = v11;
  idRenderModelCloth::SetupClothJob(this, parallelJobList: updateTools->renderModelJobList, vertices: v11);
  return 1;
}


// ========================================================================
// `dynamic initializer for 'clothsim_useJobs''
// EA  : 0x83342238
// RVA : 0x01342238
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__clothsim_useJobs__()
{
  idCVar::idCVar(
    this: &clothsim_useJobs,
    name: "clothsim_useJobs",
    value: "1",
    flags: 2,
    description: "0 = off, 1 = threaded, 2 = SPURS, 3 = SPURS emulation",
    valueMin: 0.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)&unk_82200000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__clothsim_useJobs__);
}


// ========================================================================
// `dynamic initializer for 'r_skipCloth''
// EA  : 0x833422A0
// RVA : 0x013422A0
// PDB : w:\tech5\engine\models\cloth\rendermodelcloth.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipCloth__()
{
  idCVar::idCVar(
    this: &r_skipCloth,
    name: "r_skipCloth",
    value: "0",
    flags: 2,
    description: "1 = skip cloth rendering",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&unk_82200000,
    a9: (int)&loc_827B0000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,1>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipCloth__);
}

