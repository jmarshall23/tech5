
// ========================================================================
// ?SubmitCollisionQueries@idCuttableManager@@QAAXXZ
// EA  : 0x82C1B528
// RVA : 0x00C1B528
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void __fastcall idCuttableManager::SubmitCollisionQueries(idCuttableManager *this)
{
  idEffectPhysicsCuttable::SubmitCollisionQueries(this: &this->effectPhysics);
}


// ========================================================================
// ?Emit@idCuttableManager@@QAAHABUcuttablePhysicsEmitInfo_t@@ABV?$idList@VidDrawVert@@$04@@ABV?$idList@VidVec2@@$04@@ABV?$idList@G$04@@@Z
// EA  : 0x82C1B530
// RVA : 0x00C1B530
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

int __fastcall idCuttableManager::Emit(
        idCuttableManager *this,
        const cuttablePhysicsEmitInfo_t *emitInfo,
        const idList<idDrawVert,5> *vertices,
        const idList<idVec2,5> *st,
        const idList<unsigned short,5> *indices)
{
  return idEffectPhysicsCuttable::Emit(this: &this->effectPhysics, emitInfo, vertices, st, indices);
}


// ========================================================================
// ?ClearCuttable@idCuttableManager@@QAAXH@Z
// EA  : 0x82C1B538
// RVA : 0x00C1B538
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void __fastcall idCuttableManager::ClearCuttable(idCuttableManager *this, int index)
{
  cuttableInfo_t *v2; // r11

  v2 = &this->infoCuttables.list[index];
  v2->renderModel = nullptr;
  v2->physics = nullptr;
  v2->outerContour = nullptr;
  v2->innerContour = nullptr;
}


// ========================================================================
// ?Update@idCuttableManager@@QAAXHH@Z
// EA  : 0x82C1B560
// RVA : 0x00C1B560
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void __fastcall idCuttableManager::Update(idCuttableManager *this, int currentTime, unsigned int gameMsPerFrame)
{
  idEffectPhysicsCuttable *p_effectPhysics; // r31
  __int64 v5; // r8
  int v6; // r6
  int v7; // r4
  idVec3 v8; // [sp+50h] [-30h] BYREF

  p_effectPhysics = &this->effectPhysics;
  idEffectPhysicsCuttable::UpdateSimulation(
    this: &this->effectPhysics,
    origin: (idEffectPhysicsCollision *)&vec3_origin,
    axis: &mat3_identity,
    currentTime,
    gameMsPerFrame);
  v8.x = 1.0;
  v8.y = 1.0;
  v8.z = 1.0;
  idEffectPhysicsCuttable::UpdateModel(this: p_effectPhysics, scale: &v8, currentTime, a4: v6, a5: v5);
  if ( g_cuttableShowPhysics.valueInteger != 0 )
  {
    v7 = -1 - g_cuttableShowPhysics.valueInteger;
    if ( g_cuttableShowPhysics.valueInteger >= 0 )
      v7 = -1;
    idEffectPhysicsCuttable::DrawCollisionModels(this: p_effectPhysics, single: v7);
  }
}


// ========================================================================
// ?Shutdown@idCuttableManager@@QAAXXZ
// EA  : 0x82C1B770
// RVA : 0x00C1B770
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void __fastcall idCuttableManager::Shutdown(idCuttableManager *this)
{
  idList<idVertexBuffer *,5>::DeleteContents(this: &this->vertexBuffers);
  idList<idVertexBuffer *,5>::DeleteContents(this: &this->stBuffers);
  idList<idIndexBuffer *,5>::DeleteContents(this: &this->indexBuffers);
}


// ========================================================================
// ?UpdateModel@idCuttableManager@@QAAXHPAVContour@@0@Z
// EA  : 0x82C1B7B8
// RVA : 0x00C1B7B8
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void __fastcall idCuttableManager::UpdateModel(idCuttableManager *this, int infoHandle, Contour *outer, Contour *inner)
{
  cuttableInfo_t *v4; // r11
  idRenderModelCuttableSurface *renderModel; // r25
  int v9; // r10
  int v10; // r9
  idVertexBuffer **list; // r10
  int v12; // r26
  signed int v13; // r23
  signed int v14; // r24
  int freeBuffer; // r11
  idVertexBuffer *v16; // r30
  int v17; // r11
  idVertexBuffer **v18; // r10
  idVertexBuffer *v19; // r27
  int v20; // r11
  idIndexBuffer **v21; // r10
  idIndexBuffer *v22; // r28
  D3DVertexBuffer *v23; // r3
  D3DVertexBuffer *v24; // r3
  D3DIndexBuffer *v25; // r3
  int v26; // [sp+8h] [-C8h]
  int v27; // [sp+Ch] [-C4h]
  int v28; // [sp+10h] [-C0h]
  int v29; // [sp+14h] [-BCh]
  int v30; // [sp+18h] [-B8h]
  int v31; // [sp+1Ch] [-B4h]
  int v32; // [sp+20h] [-B0h]
  int v33; // [sp+24h] [-ACh]
  int v34; // [sp+28h] [-A8h]
  int v35; // [sp+2Ch] [-A4h]
  int v36; // [sp+30h] [-A0h]
  int v37; // [sp+34h] [-9Ch]
  int v38; // [sp+38h] [-98h]
  idList<unsigned short,5> *v39; // [sp+3Ch] [-94h]
  idList<unsigned short,5> v40; // [sp+50h] [-80h] BYREF
  idList<idDrawVert,44> v41; // [sp+60h] [-70h] BYREF
  idList<idVec2,72> v42[6]; // [sp+70h] [-60h] BYREF

  v4 = &this->infoCuttables.list[infoHandle];
  renderModel = v4->renderModel;
  v4->outerContour = outer;
  v4->innerContour = inner;
  memset(&v41, 0, 14);
  *(_WORD *)&v41.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v41);
  memset(&v40, 0, 14);
  *(_WORD *)&v40.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v40);
  memset(v42, 0, 14);
  v42[0].memTag = 5;
  v42[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v42);
  idRenderModelCuttableSurface::BuildGeometry(
    this: renderModel,
    outer,
    inner,
    vtx: &v41,
    st: v42,
    idx: &v40,
    a7: v10,
    a8: v9,
    a9: v26,
    a10: v27,
    a11: v28,
    a12: v29,
    a13: v30,
    a14: v31,
    a15: v32,
    a16: v33,
    a17: v34,
    a18: v35,
    a19: v36,
    a20: v37,
    a21: v38,
    a22: v39);
  list = this->vertexBuffers.list;
  v12 = 32 * v41.num;
  v13 = 8 * v41.num;
  v14 = 2 * v40.num;
  freeBuffer = this->freeBuffer;
  v16 = list[freeBuffer];
  if ( (v16->size & 0x7FFFFFFF) < 32 * v41.num )
  {
    idVertexBuffer::FreeBufferObject(this: list[freeBuffer]);
    idVertexBuffer::AllocBufferObject(this: v16, data: nullptr, allocSize: v12, vertexMask: 31, allocUsage: BU_DYNAMIC);
  }
  v17 = this->freeBuffer;
  v18 = this->stBuffers.list;
  v19 = v18[v17];
  if ( (v19->size & 0x7FFFFFFF) < v13 )
  {
    idVertexBuffer::FreeBufferObject(this: v18[v17]);
    idVertexBuffer::AllocBufferObject(
      this: v19,
      data: nullptr,
      allocSize: v13,
      vertexMask: 9216,
      allocUsage: BU_DYNAMIC);
  }
  v20 = this->freeBuffer;
  v21 = this->indexBuffers.list;
  v22 = v21[v20];
  if ( (v22->size & 0x7FFFFFFF) < v14 )
  {
    idIndexBuffer::FreeBufferObject(this: v21[v20]);
    idIndexBuffer::AllocBufferObject(this: v22, data: nullptr, allocSize: v14, allocUsage: BU_DYNAMIC);
  }
  v23 = idVertexBuffer::MapBuffer(this: v16, mapType: BM_WRITE_NOSYNC);
  memcpy(Dst: v23, Src: v41.list, Size: v12);
  idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)v16);
  v24 = idVertexBuffer::MapBuffer(this: v19, mapType: BM_WRITE_NOSYNC);
  memcpy(Dst: v24, Src: v42[0].list, Size: v13);
  idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)v19);
  v25 = idIndexBuffer::MapBuffer(this: v22, mapType: BM_WRITE_NOSYNC);
  memcpy(Dst: v25, Src: v40.list, Size: v14);
  idIndexBuffer::UnmapBuffer(this: v22);
  this->freeBuffer = idRenderModelCuttableSurface::UpdateGeometry(
                       this: renderModel,
                       bufferIndex_: this->freeBuffer,
                       vertexBuffer: v16,
                       stBuffer: v19,
                       indexBuffer: v22,
                       numVertices: v41.num,
                       numIndices: v40.num);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v42);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v40);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v41);
}


// ========================================================================
// __unwind$488845_1
// EA  : 0x82C1B9E4
// RVA : 0x00C1B9E4
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_488845_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$488846_1
// EA  : 0x82C1BA0C
// RVA : 0x00C1BA0C
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_488846_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$488847_0
// EA  : 0x82C1BA34
// RVA : 0x00C1BA34
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_488847_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 112));
}


// ========================================================================
// ??0idCuttableManager@@QAA@XZ
// EA  : 0x82C1BB28
// RVA : 0x00C1BB28
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

idCuttableManager *__fastcall idCuttableManager::idCuttableManager(idCuttableManager *this)
{
  this->infoCuttables.list = nullptr;
  this->infoCuttables.granularity = 0;
  this->infoCuttables.memTag = 5;
  this->infoCuttables.listStatic = 0;
  this->infoCuttables.size = 0;
  this->infoCuttables.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->nameCuttables.granularity = 0;
  this->nameCuttables.memTag = 5;
  this->nameCuttables.listStatic = 0;
  this->nameCuttables.list = nullptr;
  this->nameCuttables.size = 0;
  this->nameCuttables.num = 0;
  this->vertexBuffers.list = nullptr;
  this->vertexBuffers.granularity = 0;
  this->vertexBuffers.memTag = 5;
  this->vertexBuffers.listStatic = 0;
  this->vertexBuffers.size = 0;
  this->vertexBuffers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vertexBuffers);
  this->stBuffers.list = nullptr;
  this->stBuffers.granularity = 0;
  this->stBuffers.memTag = 5;
  this->stBuffers.listStatic = 0;
  this->stBuffers.size = 0;
  this->stBuffers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stBuffers);
  this->indexBuffers.list = nullptr;
  this->indexBuffers.granularity = 0;
  this->indexBuffers.memTag = 5;
  this->indexBuffers.listStatic = 0;
  this->indexBuffers.size = 0;
  this->indexBuffers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->indexBuffers);
  idEffectPhysicsCuttable::idEffectPhysicsCuttable(this: &this->effectPhysics);
  this->freeBuffer = -1;
  return this;
}


// ========================================================================
// __unwind$489013
// EA  : 0x82C1BC00
// RVA : 0x00C1BC00
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_489013()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489014_0
// EA  : 0x82C1BC28
// RVA : 0x00C1BC28
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_489014_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$489015
// EA  : 0x82C1BC54
// RVA : 0x00C1BC54
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_489015()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 32));
}


// ========================================================================
// __unwind$489016
// EA  : 0x82C1BC80
// RVA : 0x00C1BC80
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_489016()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// __unwind$489017
// EA  : 0x82C1BCAC
// RVA : 0x00C1BCAC
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_489017()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}


// ========================================================================
// ??1idCuttableManager@@QAA@XZ
// EA  : 0x82C1BCE0
// RVA : 0x00C1BCE0
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void __fastcall idCuttableManager::~idCuttableManager(idCuttableManager *this)
{
  idList<idVehicleState *,5> *p_vertexBuffers; // r29
  idStr *list; // r3

  p_vertexBuffers = (idList<idVehicleState *,5> *)&this->vertexBuffers;
  idList<idVertexBuffer *,5>::DeleteContents(this: &this->vertexBuffers);
  idList<idVertexBuffer *,5>::DeleteContents(this: &this->stBuffers);
  idList<idIndexBuffer *,5>::DeleteContents(this: &this->indexBuffers);
  idEffectPhysicsCuttable::~idEffectPhysicsCuttable(this: &this->effectPhysics);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->indexBuffers);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stBuffers);
  idList<idThread *,58>::Clear(this: p_vertexBuffers);
  if ( this->nameCuttables.listStatic == 0 || this->nameCuttables.listStatic == 2 )
  {
    list = this->nameCuttables.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->nameCuttables.size);
    this->nameCuttables.list = nullptr;
    this->nameCuttables.size = 0;
  }
  this->nameCuttables.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$489084
// EA  : 0x82C1BD84
// RVA : 0x00C1BD84
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_489084()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489085
// EA  : 0x82C1BDAC
// RVA : 0x00C1BDAC
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_489085()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$489086
// EA  : 0x82C1BDD8
// RVA : 0x00C1BDD8
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_489086()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 32));
}


// ========================================================================
// __unwind$489087
// EA  : 0x82C1BE04
// RVA : 0x00C1BE04
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_489087()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// __unwind$489088
// EA  : 0x82C1BE30
// RVA : 0x00C1BE30
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_489088()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}


// ========================================================================
// __unwind$489089
// EA  : 0x82C1BE5C
// RVA : 0x00C1BE5C
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_489089()
{
  int v0; // r12

  idEffectPhysicsCuttable::~idEffectPhysicsCuttable(this: (idEffectPhysicsCuttable *)(*(_DWORD *)(v0 - 128 + 148) + 80));
}


// ========================================================================
// ?AllocateBuffer@idCuttableManager@@AAAHXZ
// EA  : 0x82C1C020
// RVA : 0x00C1C020
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

int __fastcall idCuttableManager::AllocateBuffer(idCuttableManager *this)
{
  int num; // r27
  idIndexBuffer *v3; // r3
  idVertexBuffer *v4; // r3
  idIndexBuffer *v5; // r3
  idVertexBuffer *v6; // r3
  idIndexBuffer *v7; // r3
  idIndexBuffer *v8; // r3
  encounterGroupRole_t v10[16]; // [sp+50h] [-40h] BYREF

  num = this->vertexBuffers.num;
  v3 = (idIndexBuffer *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x10u,
                          tag: TAG_RENDERMODEL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v10[0] = (encounterGroupRole_t)v3;
  if ( v3 != nullptr )
    v4 = (idVertexBuffer *)idIndexBuffer::idIndexBuffer(this: v3);
  else
    v4 = nullptr;
  v10[0] = (encounterGroupRole_t)v4;
  idVertexBuffer::AllocBufferObject(this: v4, data: nullptr, allocSize: 0x4000, vertexMask: 31, allocUsage: BU_DYNAMIC);
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->vertexBuffers, obj: v10);
  v5 = (idIndexBuffer *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x10u,
                          tag: TAG_RENDERMODEL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v10[0] = (encounterGroupRole_t)v5;
  if ( v5 != nullptr )
    v6 = (idVertexBuffer *)idIndexBuffer::idIndexBuffer(this: v5);
  else
    v6 = nullptr;
  v10[0] = (encounterGroupRole_t)v6;
  idVertexBuffer::AllocBufferObject(this: v6, data: nullptr, allocSize: 4096, vertexMask: 9216, allocUsage: BU_DYNAMIC);
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->stBuffers, obj: v10);
  v7 = (idIndexBuffer *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x10u,
                          tag: TAG_RENDERMODEL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v10[0] = (encounterGroupRole_t)v7;
  if ( v7 != nullptr )
    v8 = idIndexBuffer::idIndexBuffer(this: v7);
  else
    v8 = nullptr;
  v10[0] = (encounterGroupRole_t)v8;
  idIndexBuffer::AllocBufferObject(this: v8, data: nullptr, allocSize: 3072, allocUsage: BU_DYNAMIC);
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->indexBuffers, obj: v10);
  return num;
}


// ========================================================================
// __unwind$489201
// EA  : 0x82C1C164
// RVA : 0x00C1C164
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_489201()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$489202_0
// EA  : 0x82C1C190
// RVA : 0x00C1C190
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_489202_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// __unwind$489203_0
// EA  : 0x82C1C1BC
// RVA : 0x00C1C1BC
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void _unwind_489203_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_RENDERMODEL);
}


// ========================================================================
// ?Init@idCuttableManager@@QAAXPAVidRenderWorld@@PAVidSoundWorld@@PAVidClip@@@Z
// EA  : 0x82C1C1E8
// RVA : 0x00C1C1E8
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void __fastcall idCuttableManager::Init(
        idCuttableManager *this,
        idRenderWorld *renderWorld,
        idSoundWorld *soundWorld,
        idClip *clip)
{
  idEffectPhysicsCuttable::Init(
    this: &this->effectPhysics,
    renderWorld,
    soundWorld_: soundWorld,
    clip,
    traceModelCache: clip->traceModelCache);
  this->freeBuffer = idCuttableManager::AllocateBuffer(this);
}


// ========================================================================
// ?AllocateCuttable@idCuttableManager@@QAAHABVidStr@@PAVidRenderModelCuttableSurface@@PAVidPhysics@@@Z
// EA  : 0x82C1C230
// RVA : 0x00C1C230
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

int __fastcall idCuttableManager::AllocateCuttable(
        idCuttableManager *this,
        const idStr *name,
        idRenderModelCuttableSurface *renderModel_,
        idPhysics *physics)
{
  int num; // r28
  idPlane v9; // [sp+50h] [-40h] BYREF

  LODWORD(v9.a) = renderModel_;
  LODWORD(v9.b) = physics;
  v9.c = 0.0;
  v9.d = 0.0;
  num = this->infoCuttables.num;
  idList<aas2Cluster_t,37>::Append((idList<idPlane,37> *)this, obj: &v9);
  idList<idStr,5>::Append(this: &this->nameCuttables, obj: name);
  renderModel_->bufferIndex = idCuttableManager::AllocateBuffer(this);
  return num;
}


// ========================================================================
// `dynamic initializer for 'g_cuttableShowPhysics''
// EA  : 0x83375B00
// RVA : 0x01375B00
// PDB : w:\tech5\tungsten\game\entities\cuttablemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_cuttableShowPhysics__()
{
  idCVar::idCVar(
    this: &g_cuttableShowPhysics,
    name: "g_cuttableShowPhysics",
    value: "0",
    flags: 2,
    description: "Debug render physics for loose pieces",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_cuttableShowPhysics__);
}

