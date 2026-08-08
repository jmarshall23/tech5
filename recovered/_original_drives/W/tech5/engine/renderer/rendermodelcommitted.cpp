
// ========================================================================
// ?UnlinkAddAlways@idRenderModelCommitted@@QAAXXZ
// EA  : 0x82944C40
// RVA : 0x00944C40
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

void __fastcall idRenderModelCommitted::UnlinkAddAlways(idRenderModelCommitted *this)
{
  idRenderModelCommitted *nextAddAlwaysModel; // r9
  idRenderWorldLocal *world; // r11
  idRenderModelCommitted **p_addAlwaysModels; // r11
  idRenderModelCommitted *v4; // r10

  nextAddAlwaysModel = this->nextAddAlwaysModel;
  if ( nextAddAlwaysModel != this )
  {
    world = this->world;
    if ( world != nullptr )
    {
      p_addAlwaysModels = &world->addAlwaysModels;
      if ( *p_addAlwaysModels != nullptr )
      {
        while ( 1 )
        {
          v4 = *p_addAlwaysModels;
          if ( *p_addAlwaysModels == this )
            break;
          p_addAlwaysModels = &v4->nextAddAlwaysModel;
          if ( v4->nextAddAlwaysModel == nullptr )
          {
            this->nextAddAlwaysModel = this;
            return;
          }
        }
        *p_addAlwaysModels = nextAddAlwaysModel;
      }
      this->nextAddAlwaysModel = this;
    }
  }
}


// ========================================================================
// ?UnlinkDimShadow@idRenderModelCommitted@@QAAXXZ
// EA  : 0x82944CA0
// RVA : 0x00944CA0
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

void __fastcall idRenderModelCommitted::UnlinkDimShadow(idRenderModelCommitted *this)
{
  idRenderModelCommitted *nextDimShadowModel; // r9
  idRenderModelCommitted **p_dimShadowModels; // r11
  idRenderModelCommitted *v3; // r10

  nextDimShadowModel = this->nextDimShadowModel;
  if ( nextDimShadowModel != this )
  {
    p_dimShadowModels = &this->world->dimShadowModels;
    if ( *p_dimShadowModels != nullptr )
    {
      while ( 1 )
      {
        v3 = *p_dimShadowModels;
        if ( *p_dimShadowModels == this )
          break;
        p_dimShadowModels = &v3->nextDimShadowModel;
        if ( v3->nextDimShadowModel == nullptr )
        {
          this->nextDimShadowModel = this;
          return;
        }
      }
      *p_dimShadowModels = nextDimShadowModel;
    }
    this->nextDimShadowModel = this;
  }
}


// ========================================================================
// ?SetFlagsFromSurfaces@idRenderModelCommitted@@QAAXXZ
// EA  : 0x82944CF8
// RVA : 0x00944CF8
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

void __fastcall idRenderModelCommitted::SetFlagsFromSurfaces(
        idRenderModelCommitted *this,
        int a2,
        int a3,
        int a4,
        idRenderModelSurface *list)
{
  int num; // r10
  int v7; // r8
  int v8; // r9
  idRenderModelSurface *v9; // r11

  num = this->surfaces.num;
  v7 = 0;
  *((_BYTE *)this + 1416) &= 0xC1u;
  if ( num > 0 )
  {
    list = this->surfaces.list;
    v8 = 0;
    do
    {
      v9 = &list[v8];
      if ( &list[v8] != nullptr && v9->material != nullptr )
      {
        if ( v9->material->coverage != MC_INVISIBLE )
          *((_BYTE *)this + 1416) |= 0x10u;
        if ( (*((_BYTE *)v9->material + 72) & 0x80) != 0 )
          *((_BYTE *)this + 1416) |= 8u;
        a3 = *((_BYTE *)v9->material + 72) & 0x10;
        if ( (*((_BYTE *)v9->material + 72) & 0x10) != 0 )
          *((_BYTE *)this + 1416) |= 4u;
        if ( v9->material->pageSource > PAGESOURCE_VMTR )
          *((_BYTE *)this + 1416) |= 2u;
        a4 = *((_BYTE *)v9->material + 72) & 2;
        if ( (*((_BYTE *)v9->material + 72) & 2) != 0 )
          *((_BYTE *)this + 1416) |= 0x20u;
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->surfaces.num );
  }
  if ( (*((_BYTE *)&this->r + 104) & 0x20) != 0
    && ((unsigned __int8 (__fastcall *)(idRenderWorldLocal *, int, int, int, idRenderModelSurface *, int))this->world->IsComboMap)(
         a1: this->world,
         a2,
         a3,
         a4,
         a5: list,
         a6: v7) != 0 )
  {
    *((_BYTE *)this + 1416) &= ~0x20u;
  }
  if ( (*((_BYTE *)this + 1416) & 1) != 0 )
    *((_BYTE *)this + 1416) |= 0x20u;
}


// ========================================================================
// ?CreateReferences@idRenderModelCommitted@@QAAXXZ
// EA  : 0x82944E60
// RVA : 0x00944E60
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

void __fastcall idRenderModelCommitted::CreateReferences(idRenderModelCommitted *this)
{
  idBounds *p_referenceBounds; // r29
  float *p_globalReferenceBounds; // r30
  char *v4; // r10
  float *p_z; // r11
  int i; // ctr
  double v7; // fp7
  double v8; // fp5
  double v9; // fp3
  double v10; // fp1
  double v11; // fp13
  double v12; // fp10
  double v13; // fp6
  double v14; // fp4
  const idBox *v15; // r3
  double v16; // fp7
  double v17; // fp5
  double y; // fp0
  double v20; // fp7
  double z; // fp2
  double v22; // fp6
  double v23; // fp4
  double v25; // fp13
  double v26; // fp1
  double v27; // fp10
  char v38; // [sp+4Ch] [-94h] BYREF
  idMat3 v39; // [sp+50h] [-90h] BYREF
  idBox v40; // [sp+80h] [-60h] BYREF

  p_referenceBounds = &this->referenceBounds;
  p_globalReferenceBounds = (float *)&this->globalReferenceBounds;
  idBounds::FromModelMatrixBounds(
    this: &this->globalReferenceBounds,
    bounds: &this->referenceBounds,
    modelMatrix: &this->modelMatrix);
  v4 = &v38;
  p_z = &this->r.origin.z;
  for ( i = 9; i != 0; --i )
  {
    ++p_z;
    v4 += 4;
    *(float *)v4 = *p_z;
  }
  v7 = (float)(v39.mat[0].y * this->r.scale.x);
  v8 = (float)(v39.mat[0].z * this->r.scale.x);
  v9 = (float)(v39.mat[1].x * this->r.scale.y);
  v10 = (float)(v39.mat[1].y * this->r.scale.y);
  v11 = (float)(v39.mat[1].z * this->r.scale.y);
  v12 = (float)(v39.mat[2].x * this->r.scale.z);
  v13 = (float)(v39.mat[2].y * this->r.scale.z);
  v14 = (float)(v39.mat[2].z * this->r.scale.z);
  v39.mat[0].x = v39.mat[0].x * this->r.scale.x;
  v39.mat[0].y = v7;
  v39.mat[0].z = v8;
  v39.mat[1].x = v9;
  v39.mat[1].y = v10;
  v39.mat[1].z = v11;
  v39.mat[2].x = v12;
  v39.mat[2].y = v13;
  v39.mat[2].z = v14;
  v15 = idBox::idBox(this: &v40, bounds: p_referenceBounds, origin: &this->r.origin, axis: &v39);
  idRenderWorldLocal::PushPolytopeIntoTree(
    this: this->world,
    model: this,
    light: nullptr,
    box: v15,
    points: nullptr,
    numPoints: 0);
  if ( this->r.maxVisibleRange <= 0.0 )
  {
    this->maxVisibleRange.x = 0.0;
    this->maxVisibleRange.y = 0.0;
    this->maxVisibleRange.z = 0.0;
    this->maxVisibleRange.w = 262144.0;
  }
  else
  {
    v16 = (float)(p_globalReferenceBounds[4] + p_globalReferenceBounds[1]);
    v17 = (float)(p_globalReferenceBounds[5] + p_globalReferenceBounds[2]);
    this->maxVisibleRange.x = (float)(p_globalReferenceBounds[3] + *p_globalReferenceBounds) * (float)0.5;
    this->maxVisibleRange.y = (float)v16 * (float)0.5;
    this->maxVisibleRange.z = (float)v17 * (float)0.5;
    this->maxVisibleRange.w = 0.0;
    _FP9 = (float)((float)0.0 - (float)(*p_globalReferenceBounds - this->maxVisibleRange.x));
    y = this->maxVisibleRange.y;
    v20 = (float)(p_globalReferenceBounds[1] - this->maxVisibleRange.y);
    z = this->globalReferenceBounds.b[1].z;
    v22 = this->maxVisibleRange.z;
    v23 = (float)(p_globalReferenceBounds[2] - this->maxVisibleRange.z);
    __asm { fsel      f3, f9, f1, f10 }
    v25 = this->globalReferenceBounds.b[1].y;
    v26 = (float)(this->globalReferenceBounds.b[1].x - this->maxVisibleRange.x);
    this->maxVisibleRange.w = _FP3;
    v27 = (float)((float)z - (float)v22);
    _FP11 = (float)((float)_FP3 - (float)v20);
    __asm { fsel      f9, f11, f3, f7 }
    this->maxVisibleRange.w = _FP9;
    _FP8 = (float)((float)_FP9 - (float)v23);
    __asm { fsel      f7, f8, f9, f4 }
    this->maxVisibleRange.w = _FP7;
    _FP6 = (float)((float)_FP7 - (float)v26);
    __asm { fsel      f5, f6, f7, f1 }
    this->maxVisibleRange.w = _FP5;
    _FP4 = (float)((float)_FP5 - (float)((float)v25 - (float)y));
    __asm { fsel      f3, f4, f5, f12 }
    this->maxVisibleRange.w = _FP3;
    _FP2 = (float)((float)_FP3 - (float)v27);
    __asm { fsel      f1, f2, f3, f10 }
    this->maxVisibleRange.w = _FP1;
    this->maxVisibleRange.w = this->r.maxVisibleRange + (float)_FP1;
  }
}


// ========================================================================
// ?CheckBounds@idRenderModelCommitted@@QBAXXZ
// EA  : 0x82945070
// RVA : 0x00945070
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

void __fastcall idRenderModelCommitted::CheckBounds(idRenderModelCommitted *this)
{
  int num; // r10
  int v3; // r21
  int v10; // r23
  idRenderModelSurface *v11; // r26
  idTriangles *geometry; // r30
  D3DVertexBuffer *verts; // r29
  char v20; // r25
  int i; // r28
  int v22; // r31
  float *v23; // r11
  double v24; // fp0
  int v25; // r9
  float *v26; // r11
  idVec3 *j; // r10
  float v28; // [sp+50h] [-B0h]
  float v29; // [sp+54h] [-ACh]
  float v30; // [sp+58h] [-A8h]
  float v31; // [sp+5Ch] [-A4h] BYREF
  float v32; // [sp+60h] [-A0h]
  float v33; // [sp+64h] [-9Ch]

  num = this->surfaces.num;
  v3 = 0;
  v30 = 1.0e30;
  v29 = 1.0e30;
  _FP29 = 1.0e30;
  v28 = 1.0e30;
  _FP30 = 1.0e30;
  v33 = -1.0e30;
  _FP31 = 1.0e30;
  v32 = v33;
  v31 = v33;
  _FP26 = -1.0e30;
  _FP27 = -1.0e30;
  _FP28 = -1.0e30;
  if ( num <= 0 )
    goto LABEL_22;
  v10 = 0;
  do
  {
    v11 = &this->surfaces.list[v10];
    if ( v11->material != nullptr )
    {
      geometry = v11->geometry;
      if ( geometry != nullptr && v11->material->coverage != MC_INVISIBLE )
      {
        verts = (D3DVertexBuffer *)geometry->verts;
        _FP12 = (float)((float)_FP31 - geometry->bounds.b[0].x);
        _FP10 = (float)((float)_FP30 - geometry->bounds.b[0].y);
        _FP8 = (float)((float)_FP29 - geometry->bounds.b[0].z);
        _FP6 = (float)(geometry->bounds.b[1].x - (float)_FP28);
        _FP4 = (float)(geometry->bounds.b[1].y - (float)_FP27);
        _FP3 = (float)(geometry->bounds.b[1].z - (float)_FP26);
        v20 = 0;
        __asm
        {
          fsel      f31, f12, f0, f31
          fsel      f30, f10, f13, f30
          fsel      f29, f8, f11, f29
          fsel      f28, f6, f9, f28
          fsel      f27, f4, f7, f27
          fsel      f26, f3, f5, f26
        }
        if ( verts == nullptr )
        {
          verts = idVertexBuffer::MapBuffer(this: &geometry->vertexBuffer, mapType: BM_READ);
          if ( verts == nullptr )
            goto LABEL_20;
          v20 = 1;
        }
        for ( i = 0; i < geometry->numVerts; ++i )
        {
          v22 = 0;
          v23 = (float *)geometry;
          while ( 1 )
          {
            v24 = *((float *)&verts[i].Common + v22);
            if ( v24 > (float)(v23[3] + 1.0) || v24 < (float)(*v23 - 1.0) )
              break;
            ++v22;
            ++v23;
            if ( v22 >= 3 )
              goto LABEL_16;
          }
          idLib::Printf(fmt: "bad tri->bounds on %s:%s\n", this->name, v11->material->name.str);
LABEL_16:
          if ( v22 != 3 )
            break;
        }
        if ( v20 != 0 )
          idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&geometry->vertexBuffer);
      }
    }
LABEL_20:
    ++v3;
    ++v10;
  }
  while ( v3 < this->surfaces.num );
  v33 = _FP26;
  v32 = _FP27;
  v31 = _FP28;
  v30 = _FP29;
  v29 = _FP30;
  v28 = _FP31;
LABEL_22:
  v25 = 0;
  v26 = &v31;
  for ( j = &this->referenceBounds.b[1];
        *(v26 - 3) >= (double)(float)(j[-1].x - 1.0) && *v26 <= (double)(float)(j->x + 1.0);
        j = (idVec3 *)((char *)j + 4) )
  {
    ++v25;
    ++v26;
    if ( v25 >= 3 )
      return;
  }
  idLib::Printf(fmt: "activeBounds exceeds referenceBounds on %s\n", this->name);
}


// ========================================================================
// ?GetLightingPoint@idRenderModelCommitted@@QBA?AVidVec3@@XZ
// EA  : 0x829452D0
// RVA : 0x009452D0
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

idRenderModelCommitted *__fastcall idRenderModelCommitted::GetLightingPoint(
        idRenderModelCommitted *this,
        idVec3 *result)
{
  double v2; // fp0
  double y; // fp8
  double z; // fp12
  double v5; // fp5
  double v6; // fp4
  double v7; // fp9
  double v8; // fp5
  double v9; // fp2
  double v10; // fp1

  if ( (LOBYTE(result[11].z) & 0x40) != 0 )
  {
    v2 = (float)((float)(result[2].z + result[1].z) * (float)0.5);
    if ( (LOBYTE(result[11].z) & 0x20) != 0 )
      v2 = (float)((float)((float)(result[2].z - result[1].z) * (float)0.25)
                 + (float)((float)(result[2].z + result[1].z) * (float)0.5));
    y = result[96].y;
    v5 = (float)((float)(result[96].x * (float)v2)
               + (float)((float)(result[95].y * (float)((float)(result[2].x + result[1].x) * (float)0.5))
                       + (float)(result[95].z * (float)((float)(result[2].y + result[1].y) * (float)0.5))));
    v6 = (float)((float)(result[97].y * (float)v2)
               + (float)((float)(result[96].z * (float)((float)(result[2].x + result[1].x) * (float)0.5))
                       + (float)(result[97].x * (float)((float)(result[2].y + result[1].y) * (float)0.5))));
    z = result[97].z;
    *(float *)&this->name = (float)((float)(result[94].x * (float)((float)(result[2].x + result[1].x) * (float)0.5))
                                  + (float)((float)(result[94].y
                                                  * (float)((float)(result[2].y + result[1].y) * (float)0.5))
                                          + (float)(result[94].z * (float)v2)))
                          + result[95].x;
    *(float *)&this->world = (float)v5 + (float)y;
    *(float *)&this->index.index = (float)v6 + (float)z;
  }
  else
  {
    v7 = result[96].y;
    v8 = result[97].z;
    v9 = (float)((float)(result[96].x * result[93].z)
               + (float)((float)(result[95].y * result[93].x) + (float)(result[95].z * result[93].y)));
    v10 = (float)((float)(result[97].y * result[93].z)
                + (float)((float)(result[96].z * result[93].x) + (float)(result[97].x * result[93].y)));
    *(float *)&this->name = (float)((float)(result[94].x * result[93].x)
                                  + (float)((float)(result[94].y * result[93].y) + (float)(result[94].z * result[93].z)))
                          + result[95].x;
    *(float *)&this->world = (float)v9 + (float)v7;
    *(float *)&this->index.index = (float)v10 + (float)v8;
  }
  return this;
}


// ========================================================================
// ?ModelTriangleTrace@idRenderModelCommitted@@QBA_NAAUmodelTrace_t@@ABVidVec3@@1PBVidTraceOpts@@@Z
// EA  : 0x82945428
// RVA : 0x00945428
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

BOOL __fastcall idRenderModelCommitted::ModelTriangleTrace(
        idRenderModelCommitted *this,
        modelTrace_t *trace,
        const idVec3 *localStart,
        const idVec3 *localEnd,
        __int64 traceOpts)
{
  idTraceOpts *v9; // r29
  int v10; // r28
  int v11; // r26
  idRenderModelSurface *v12; // r30
  const idMaterial *material; // r11
  localTrace_t *geometry; // r4
  localTrace_t *v15; // r3
  float fraction; // [sp+60h] [-B0h]
  float x; // [sp+64h] [-ACh]
  float y; // [sp+68h] [-A8h]
  float z; // [sp+6Ch] [-A4h]
  float v21; // [sp+70h] [-A0h]
  float v22; // [sp+74h] [-9Ch]
  float v23; // [sp+78h] [-98h]
  int jointIndex; // [sp+7Ch] [-94h]
  int v25; // [sp+80h] [-90h]
  int v26; // [sp+88h] [-88h]
  idTriangles var80; // [sp+90h] [-80h] BYREF

  v9 = (idTraceOpts *)HIDWORD(traceOpts);
  v10 = 0;
  if ( HIDWORD(traceOpts) == 0 )
  {
    HIDWORD(traceOpts) = &renderLog.indentString[28];
    if ( (_S13_25 & 1) == 0 )
    {
      defaultOps.skipTranslucent = false;
      defaultOps.skipModel = nullptr;
      _S13_25 |= 1u;
      defaultOps.twoSided = false;
      defaultOps.skipInvisible = true;
      defaultOps.skipDynamic = true;
      HIDWORD(traceOpts) = 0;
      defaultOps.radius = 0.0;
    }
    v9 = &defaultOps;
  }
  trace->surf = nullptr;
  v11 = 0;
  for ( trace->tr.fraction = 1.0; v11 < this->surfaces.num; ++v10 )
  {
    v12 = &this->surfaces.list[v10];
    material = v12->material;
    geometry = (localTrace_t *)v12->geometry;
    if ( geometry != nullptr
      && material != nullptr
      && (!v9->skipTranslucent || material->coverage != MC_TRANSLUCENT)
      && (!v9->skipInvisible || material->coverage != MC_INVISIBLE) )
    {
      v15 = idTriangles::TriangleTrace(
              this: &var80,
              result: geometry,
              start: localStart,
              end: localEnd,
              radius: v9->radius,
              twoSided: SBYTE3(traceOpts));
      HIDWORD(traceOpts) = v15->indexes[1];
      jointIndex = v15->jointIndex;
      fraction = v15->fraction;
      x = v15->point.x;
      y = v15->point.y;
      z = v15->point.z;
      v21 = v15->normal.x;
      v22 = v15->normal.y;
      v23 = v15->normal.z;
      v25 = v15->indexes[0];
      v26 = v15->indexes[2];
      if ( fraction < (double)trace->tr.fraction )
      {
        trace->tr.fraction = fraction;
        trace->tr.point.x = x;
        trace->tr.point.y = y;
        trace->tr.point.z = z;
        trace->tr.normal.x = v21;
        trace->tr.normal.y = v22;
        trace->tr.normal.z = v23;
        trace->tr.jointIndex = jointIndex;
        trace->tr.indexes[0] = v25;
        trace->tr.indexes[1] = HIDWORD(traceOpts);
        trace->tr.indexes[2] = v26;
        trace->surf = v12;
      }
    }
    ++v11;
  }
  LODWORD(traceOpts) = (_cntlzw((unsigned int)trace->surf) & 0x20) != 0;
  return (float)traceOpts != 1.0;
}


// ========================================================================
// ??0idRenderModelCommitted@@AAA@XZ
// EA  : 0x82945658
// RVA : 0x00945658
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

idRenderModelCommitted *__fastcall idRenderModelCommitted::idRenderModelCommitted(idRenderModelCommitted *this)
{
  int v1; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  idRenderIndex *p_index; // r10
  float *p_w; // r9
  idSysMutex *v6; // r10
  int v7; // ctr
  double g; // fp0
  double b; // fp13
  double a; // fp12

  this->name = nullptr;
  v1 = 6;
  this->world = nullptr;
  p_viewNoteMutex = &analysisClient.viewNoteMutex;
  p_index = &this->index;
  this->index.index = -1;
  do
  {
    ++p_viewNoteMutex;
    ++p_index;
    p_index->index = (unsigned int)p_viewNoteMutex->handle;
    --v1;
  }
  while ( v1 != 0 );
  idRenderModelParms::idRenderModelParms(this: &this->r);
  idStaticParmBlock<32>::idStaticParmBlock<32>(this: &this->renderParmBlock, threadId: THREAD_RENDERER);
  this->surfaces.list = nullptr;
  this->surfaces.granularity = 0;
  this->surfaces.memTag = 62;
  this->surfaces.listStatic = 0;
  this->surfaces.size = 0;
  this->surfaces.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->surfaces);
  this->references.list = nullptr;
  this->references.granularity = 0;
  this->references.memTag = 62;
  this->references.listStatic = 0;
  this->references.size = 0;
  this->references.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->references);
  this->referenceModel = nullptr;
  this->guiFrameCount = 0;
  p_w = &this->maxVisibleRange.w;
  v6 = &analysisClient.viewNoteMutex;
  this->maxVisibleRange.x = 0.0;
  v7 = 6;
  this->maxVisibleRange.y = 0.0;
  this->maxVisibleRange.z = 0.0;
  this->maxVisibleRange.w = 262144.0;
  do
  {
    ++v6;
    *++p_w = *(float *)&v6->handle;
    --v7;
  }
  while ( v7 != 0 );
  this->localLightingPoint.x = 0.0;
  this->localLightingPoint.y = 0.0;
  this->localLightingPoint.z = 0.0;
  *((_BYTE *)this + 1416) = 4;
  this->name = "<unnamed>";
  this->nextOnPostCommitList = this;
  this->nextAddAlwaysModel = this;
  this->nextDimShadowModel = this;
  memset(Dst: &this->modelMatrix, Val: 0, Size: sizeof(this->modelMatrix));
  memset(Dst: &this->inverseModelMatrix, Val: 0, Size: sizeof(this->inverseModelMatrix));
  memset(Dst: &this->mvpMatrix, Val: 0, Size: sizeof(this->mvpMatrix));
  this->approximateLighting.primeLightDir.w = 0.0;
  this->approximateLighting.primeLightDir.z = 0.0;
  this->approximateLighting.primeLightDir.y = 0.0;
  this->approximateLighting.primeLightDir.x = 0.0;
  this->approximateLighting.primeLightColor.w = 0.0;
  this->approximateLighting.primeLightColor.z = 0.0;
  this->approximateLighting.primeLightColor.y = 0.0;
  this->approximateLighting.primeLightColor.x = 0.0;
  this->approximateLighting.channelLighting[0].x = 0.0;
  this->approximateLighting.channelLighting[0].w = 0.0;
  this->approximateLighting.channelLighting[0].z = 0.0;
  this->approximateLighting.channelLighting[0].y = 0.0;
  this->approximateLighting.channelLighting[1].w = 0.0;
  this->approximateLighting.channelLighting[1].z = 0.0;
  this->approximateLighting.channelLighting[1].y = 0.0;
  this->approximateLighting.channelLighting[1].x = 0.0;
  this->approximateLighting.channelLighting[2].w = 0.0;
  this->approximateLighting.channelLighting[2].z = 0.0;
  this->approximateLighting.channelLighting[2].y = 0.0;
  this->approximateLighting.channelLighting[2].x = 0.0;
  this->approximateLighting.channelLighting[3].w = 0.0;
  this->approximateLighting.channelLighting[3].z = 0.0;
  this->approximateLighting.channelLighting[3].y = 0.0;
  this->approximateLighting.channelLighting[3].x = 0.0;
  this->approximateLighting.channelLighting[4].w = 0.0;
  this->approximateLighting.channelLighting[4].z = 0.0;
  this->approximateLighting.channelLighting[4].y = 0.0;
  this->approximateLighting.channelLighting[4].x = 0.0;
  this->approximateLighting.channelLighting[5].w = 0.0;
  this->approximateLighting.channelLighting[5].z = 0.0;
  this->approximateLighting.channelLighting[5].y = 0.0;
  this->approximateLighting.channelLighting[5].x = 0.0;
  g = idColor::colorBlack.g;
  b = idColor::colorBlack.b;
  a = idColor::colorBlack.a;
  this->highlightColor.x = idColor::colorBlack.r;
  this->highlightColor.y = g;
  this->highlightColor.z = b;
  this->highlightColor.w = a;
  return this;
}


// ========================================================================
// __unwind$232502
// EA  : 0x829458B8
// RVA : 0x009458B8
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

void _unwind_232502()
{
  int v0; // r12

  idStaticParmBlock<32>::~idStaticParmBlock<32>(this: (idStaticParmBlock<32> *)(*(_DWORD *)(v0 - 144 + 164) + 208));
}


// ========================================================================
// __unwind$232503
// EA  : 0x829458E4
// RVA : 0x009458E4
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

void _unwind_232503()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 1024));
}


// ========================================================================
// ??1idRenderModelCommitted@@AAA@XZ
// EA  : 0x82945918
// RVA : 0x00945918
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

void __fastcall idRenderModelCommitted::~idRenderModelCommitted(idRenderModelCommitted *this)
{
  if ( this->world != nullptr )
  {
    this->world->commitModels.ptr[this->index.index >> 8] = false;
    this->world->postCommitModels.ptr[this->index.index >> 8] = false;
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->references);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->surfaces);
  idParmBlock::~idParmBlock(this: &this->renderParmBlock);
}


// ========================================================================
// __unwind$232620
// EA  : 0x829459B0
// RVA : 0x009459B0
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

void _unwind_232620()
{
  int v0; // r12

  idStaticParmBlock<32>::~idStaticParmBlock<32>(this: (idStaticParmBlock<32> *)(*(_DWORD *)(v0 - 112 + 132) + 208));
}


// ========================================================================
// __unwind$232621
// EA  : 0x829459DC
// RVA : 0x009459DC
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

void _unwind_232621()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1024));
}


// ========================================================================
// ?FreeReferences@idRenderModelCommitted@@QAAXXZ
// EA  : 0x82945A08
// RVA : 0x00945A08
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

void __fastcall idRenderModelCommitted::FreeReferences(idRenderModelCommitted *this)
{
  int v2; // r29
  idRenderIndex *p_index; // r28
  int v4; // r31

  if ( this->references.num > 0 )
  {
    v2 = 0;
    p_index = &this->index;
    v4 = 0;
    do
    {
      idList<void *,108>::RemoveFast(
        this: (idList<idMapChangeListener *,5> *)this->references.list[v4],
        obj: (idMapChangeListener *const *)p_index);
      ++v2;
      ++v4;
    }
    while ( v2 < this->references.num );
    if ( this->references.size < 0 )
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->references);
    this->references.num = __CFADD__(-this->references.size, this->references.size ^ 0x80000000)
                         ? 0
                         : this->references.size;
    *(idRenderModelCommitted **)((char *)this->world->linkedRenderModels.list + ((this->index.index >> 6) & 0x3FFFFFC)) = nullptr;
  }
}


// ========================================================================
// ?PostCommit@idRenderModelCommitted@@QAAXXZ
// EA  : 0x82945AB8
// RVA : 0x00945AB8
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.cpp
// ========================================================================

void __fastcall idRenderModelCommitted::PostCommit(idRenderModelCommitted *this)
{
  double v2; // fp7
  double v3; // fp6
  idRenderModelCommitted **p_addAlwaysModels; // r10
  idRenderModelCommitted **p_dimShadowModels; // r10
  double x; // fp0

  if ( (*((_BYTE *)this + 1416) & 0x80) == 0 )
  {
    *((_BYTE *)this + 1416) = *((_BYTE *)this + 1416) & 0x7F | 0x80;
    v2 = (float)(this->referenceBounds.b[1].z + this->referenceBounds.b[0].z);
    v3 = (float)(this->referenceBounds.b[1].y + this->referenceBounds.b[0].y);
    this->localLightingPoint.x = (float)(this->referenceBounds.b[1].x + this->referenceBounds.b[0].x) * (float)0.5;
    this->localLightingPoint.z = (float)v2 * (float)0.5;
    this->localLightingPoint.y = (float)v3 * (float)0.5;
    if ( (*((_BYTE *)&this->r + 107) & 0x20) != 0 )
      this->localLightingPoint.z = (float)((float)(this->referenceBounds.b[1].z - this->referenceBounds.b[0].z)
                                         * (float)0.25)
                                 + (float)((float)v2 * (float)0.5);
  }
  if ( (*((_BYTE *)&this->r + 105) & 4) != 0 )
  {
    idRenderModelCommitted::FreeReferences(this);
    idRenderModelCommitted::UnlinkDimShadow(this);
    if ( this->nextAddAlwaysModel == this )
    {
      p_addAlwaysModels = &this->world->addAlwaysModels;
      this->nextAddAlwaysModel = *p_addAlwaysModels;
      *p_addAlwaysModels = this;
    }
    return;
  }
  idRenderModelCommitted::UnlinkAddAlways(this);
  if ( (*((_BYTE *)this + 1416) & 0x40) == 0 )
    return;
  idRenderModelCommitted::FreeReferences(this);
  if ( (unsigned __int8)idBounds::IsZero(this: &this->referenceBounds) != 0
    || this->referenceBounds.b[0].x > (double)this->referenceBounds.b[1].x )
  {
    x = this->r.origin.x;
    this->globalReferenceBounds.b[1].x = this->r.origin.x;
    this->globalReferenceBounds.b[1].y = this->r.origin.y;
    this->globalReferenceBounds.b[1].z = this->r.origin.z;
    this->globalReferenceBounds.b[0].x = x;
    this->globalReferenceBounds.b[0].y = this->globalReferenceBounds.b[1].y;
    this->globalReferenceBounds.b[0].z = this->globalReferenceBounds.b[1].z;
    this->maxVisibleRange.x = 0.0;
    this->maxVisibleRange.y = 0.0;
    this->maxVisibleRange.z = 0.0;
    this->maxVisibleRange.w = 262144.0;
LABEL_15:
    idRenderModelCommitted::UnlinkDimShadow(this);
    return;
  }
  idRenderModelCommitted::CreateReferences(this);
  if ( (*((_BYTE *)&this->r + 104) & 0x20) != 0 || !idRenderModelCommitted::CastsDimShadows(this) )
    goto LABEL_15;
  if ( this->nextDimShadowModel == this )
  {
    p_dimShadowModels = &this->world->dimShadowModels;
    this->nextDimShadowModel = *p_dimShadowModels;
    *p_dimShadowModels = this;
  }
}

