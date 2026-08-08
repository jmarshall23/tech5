
// ========================================================================
// ?EndFrame@idRenderModelEffects@@SAXXZ
// EA  : 0x827EE038
// RVA : 0x007EE038
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

static void __fastcall idRenderModelEffects::EndFrame()
{
  idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&idRenderModelEffects::vertexBuffer[idRenderModelEffects::mappedBufferIndex]);
}


// ========================================================================
// ?CommitSubclass@idRenderModelEffects@@EAA_NXZ
// EA  : 0x827EE058
// RVA : 0x007EE058
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

int __fastcall idRenderModelEffects::CommitSubclass(idRenderModelEffects *this)
{
  int v2; // r9
  int v3; // r8
  int v4; // r7
  int v5; // r6
  int v6; // r5
  int v7; // r4
  int v8; // r31

  v2 = this->latchedParticleRange[1];
  v3 = this->particleRange[0];
  v4 = this->tracerRange[0];
  v5 = this->decalRange[0];
  v6 = this->particleRange[1];
  v7 = this->tracerRange[1];
  v8 = this->decalRange[1];
  this->lastLatchedParticleRange[0] = this->latchedParticleRange[0];
  this->latchedParticleRange[0] = v3;
  this->latchedTracerRange[0] = v4;
  this->latchedDecalRange[0] = v5;
  this->lastLatchedParticleRange[1] = v2;
  this->latchedParticleRange[1] = v6;
  this->latchedTracerRange[1] = v7;
  this->latchedDecalRange[1] = v8;
  this->latchedTime = this->gameTime;
  return 0;
}


// ========================================================================
// ?Shutdown@idRenderModelEffects@@SAXXZ
// EA  : 0x827EE0B8
// RVA : 0x007EE0B8
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

static void __fastcall idRenderModelEffects::Shutdown()
{
  idVertexBuffer *v0; // r31

  if ( !idLib::headless )
  {
    if ( idRenderModelEffects::mappedVerts != nullptr
      && idRenderModelEffects::vertexBuffer[idRenderModelEffects::mappedBufferIndex].size < 0 )
    {
      idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&idRenderModelEffects::vertexBuffer[idRenderModelEffects::mappedBufferIndex]);
    }
    v0 = idRenderModelEffects::vertexBuffer;
    do
      idVertexBuffer::FreeBufferObject(this: v0++);
    while ( (int)v0 < (int)&idRenderModelEffects::indexBuffer );
    idIndexBuffer::FreeBufferObject(this: &idRenderModelEffects::indexBuffer);
  }
}


// ========================================================================
// ?StartFrame@idRenderModelEffects@@SAXXZ
// EA  : 0x827EE158
// RVA : 0x007EE158
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

static void __fastcall idRenderModelEffects::StartFrame()
{
  idPixelUnpackBuffer *v0; // r3

  if ( idRenderModelEffects::mappedVerts != nullptr )
  {
    v0 = (idPixelUnpackBuffer *)&idRenderModelEffects::vertexBuffer[idRenderModelEffects::mappedBufferIndex];
    if ( v0->size < 0 )
      idVertexBuffer::UnmapBuffer(this: v0);
  }
  idRenderModelEffects::mappedBufferIndex = (idRenderModelEffects::mappedBufferIndex + 1) % 2;
  idRenderModelEffects::mappedVerts = (idDrawVert *)idVertexBuffer::MapBuffer(
                                                      this: &idRenderModelEffects::vertexBuffer[idRenderModelEffects::mappedBufferIndex],
                                                      mapType: BM_WRITE_NOSYNC);
  idRenderModelEffects::vertOffset = 0;
  idRenderModelEffects::indexOffset = 0;
}


// ========================================================================
// ?AddDecal@idRenderModelEffects@@QAAXPBVidMaterial@@ABVidDrawVert@@111HHHH@Z
// EA  : 0x827EE1F0
// RVA : 0x007EE1F0
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void __fastcall idRenderModelEffects::AddDecal(
        idRenderModelEffects *this,
        const idMaterial *mat,
        const idDrawVert *v0,
        const idDrawVert *v1,
        const idDrawVert *v2,
        const idDrawVert *v3,
        const idMaterial *startTime,
        const idMaterial *lifeTime,
        const int fadeInEndTime,
        const int fadeOutStartTime,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const idMaterial *a28,
        int a29,
        const idMaterial *a30)
{
  int v34; // r11
  decalParms_t *decals; // r8
  decalVerts_t *decalVerts; // r7
  idDrawVert *v37; // r31
  const idMaterial **v38; // r11
  int i; // r29
  idRenderWorld *World; // r3
  int v41; // r11
  char v42; // r8
  int v43; // r11
  int j; // ctr

  if ( r_skipEffects.valueInteger == 0 )
  {
    v34 = this->decalRange[1];
    if ( v34 - this->latchedDecalRange[0] < 1024 )
    {
      decals = this->decals;
      decalVerts = this->decalVerts;
      this->decalRange[1] = v34 + 1;
      v37 = (idDrawVert *)((char *)decalVerts->verts + ((v34 << 7) & 0x1FF80));
      v38 = &decals->mat + (v34 & 0x3FF) + ((4 * v34) & 0xFFC);
      *v38 = mat;
      v38[1] = startTime;
      v38[2] = lifeTime;
      v38[3] = a28;
      v38[4] = a30;
      idDrawVert::operator=(this: v37, rhs: v0);
      idDrawVert::operator=(this: v37 + 1, rhs: v1);
      idDrawVert::operator=(this: v37 + 2, rhs: v2);
      idDrawVert::operator=(this: v37 + 3, rhs: v3);
      for ( i = 4; i != 0; --i )
      {
        World = idRenderModel::GetWorld(this);
        v41 = (int)(float)(World->ShadowSample(this: World, a2: (const idVec3 *)v37) * (float)255.0);
        if ( v41 >= 0 )
        {
          v42 = -1;
          if ( v41 <= 255 )
            v42 = v41;
        }
        else
        {
          v42 = 0;
        }
        v43 = 0;
        for ( j = 3; j != 0; --j )
          v37->color[v43++] = v42;
        ++v37;
      }
    }
  }
}


// ========================================================================
// ?AddTracer@idRenderModelEffects@@QAAXPBVidMaterial@@ABVidVec3@@11MMM_NMM@Z
// EA  : 0x827EE340
// RVA : 0x007EE340
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void __fastcall idRenderModelEffects::AddTracer(
        idRenderModelEffects *this,
        const idMaterial *mat,
        const idVec3 *origin,
        const idVec3 *dir,
        const idVec3 *maxDist,
        double speed,
        double length,
        double height,
        const bool ensureVisual,
        double fractionInsured,
        double lifeTime,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        char a33)
{
  int v33; // r11
  tracerParms_t *tracers; // r8
  int gameTime; // r31
  idVec3 *v36; // r11
  double v37; // fp8
  double v38; // fp3
  double v39; // fp0
  double v40; // fp13
  double z; // fp0
  double v42; // fp0

  if ( r_skipEffects.valueInteger == 0 )
  {
    v33 = this->tracerRange[1];
    if ( v33 - this->latchedTracerRange[0] < 128 )
    {
      tracers = this->tracers;
      gameTime = this->gameTime;
      this->tracerRange[1] = v33 + 1;
      v36 = (idVec3 *)((char *)tracers + 16 * (v33 & 0x7F) + 16 * ((2 * v33) & 0xFE));
      v36->z = speed;
      LODWORD(v36->x) = gameTime;
      v36[1] = *origin;
      v36[2] = *dir;
      LODWORD(v36[3].z) = mat;
      v36[3].y = height;
      v36[3].x = length;
      v37 = (float)(maxDist->z - origin->z);
      v38 = (float)(maxDist->y - origin->y);
      v39 = __fsqrts((float)((float)((float)v38 * (float)v38)
                           + (float)((float)((float)(maxDist->x - origin->x) * (float)(maxDist->x - origin->x))
                                   + (float)((float)v37 * (float)v37))));
      v40 = (float)-(float)((float)((float)length * (float)0.5) - (float)v39);
      if ( a33 != 0 && v40 < (float)((float)speed * (float)fractionInsured) )
      {
        v36[3].x = (float)((float)((float)v39 * (float)fractionInsured) * (float)2.0)
                 - (float)((float)((float)speed * (float)fractionInsured) * (float)2.0);
        if ( (float)((float)((float)((float)v39 * (float)fractionInsured) * (float)2.0)
                   - (float)((float)((float)speed * (float)fractionInsured) * (float)2.0)) < 0.0 )
        {
          v36[3].x = (float)v39 * (float)0.5;
          v36->z = (float)((float)((float)1.0 / (float)fractionInsured) * (float)v39)
                 - (float)((float)((float)((float)1.0 / (float)fractionInsured) * (float)((float)v39 * (float)0.5))
                         * (float)0.5);
        }
        v40 = (float)((float)fractionInsured * v36->z);
      }
      if ( lifeTime >= 0.0 )
      {
        LODWORD(v36->y) = (int)lifeTime;
      }
      else
      {
        z = v36->z;
        if ( z == 0.0 )
          z = 1500.0;
        v42 = (float)((float)((float)v40 / (float)z) * (float)1000.0);
        if ( v42 > 3000.0 )
          v42 = 3000.0;
        LODWORD(v36->y) = (int)v42;
      }
    }
  }
}


// ========================================================================
// ?Init@idRenderModelEffects@@SAXXZ
// EA  : 0x827EE5E8
// RVA : 0x007EE5E8
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

static void __fastcall idRenderModelEffects::Init()
{
  idVertexBuffer *v0; // r30
  void *v1; // r3
  char *v2; // r30
  int v3; // r11
  char *v4; // r10

  v0 = idRenderModelEffects::vertexBuffer;
  do
  {
    idVertexBuffer::AllocBufferObject(
      this: v0,
      data: nullptr,
      allocSize: 0x40000,
      vertexMask: 31,
      allocUsage: BU_DYNAMIC);
    v1 = idVertexBuffer::MapBuffer(this: v0, mapType: BM_WRITE);
    memset(Dst: v1, Val: 0, Size: 0x40000u);
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)v0++);
  }
  while ( (int)v0 < (int)&idRenderModelEffects::indexBuffer );
  v2 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                 size: 0x6000u,
                 tag: TAG_TEMP,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v3 = 3;
  v4 = v2 - 2;
  do
  {
    *((_WORD *)v4 + 1) = v3 - 3;
    *((_WORD *)v4 + 2) = v3 - 1;
    *((_WORD *)v4 + 3) = v3;
    *((_WORD *)v4 + 4) = v3 - 3;
    *((_WORD *)v4 + 5) = v3;
    v4 += 12;
    *(_WORD *)v4 = v3 - 2;
    v3 += 4;
  }
  while ( v3 - 3 < 0x2000 );
  idIndexBuffer::AllocBufferObject(
    this: &idRenderModelEffects::indexBuffer,
    data: v2,
    allocSize: 24576,
    allocUsage: BU_DYNAMIC);
  idRenderModelEffects::mappedVerts = nullptr;
  idRenderModelEffects::mappedBufferIndex = 0;
  idRenderModelEffects::vertOffset = 0;
  idRenderModelEffects::indexOffset = 0;
  if ( v2 != nullptr )
    idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
}


// ========================================================================
// __unwind$230819
// EA  : 0x827EE74C
// RVA : 0x007EE74C
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void _unwind_230819()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 128 + 80));
}


// ========================================================================
// ?SortEffectParticles@idRenderModelEffects@@AAAXXZ
// EA  : 0x827EE778
// RVA : 0x007EE778
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void __fastcall idRenderModelEffects::SortEffectParticles(idRenderModelEffects *this)
{
  int i; // r26
  int numSortedParticleStages; // r30
  int v4; // r27
  effectParticleParms_t *v5; // r4
  const idParticleStage *stage; // r10
  idRenderModelEffects::sortedParticleStage_t *sortedParticleStages; // r11
  int v8; // r28
  int v9; // r11
  int v10; // r29
  int *p_first; // r30
  int v12; // r10
  int v13; // r24
  int *p_num; // r27
  int v15; // r26
  int *v16; // r25
  int v17; // r28
  effectParticleParms_t *v18; // r4
  int v19; // r29
  int *v20; // r30
  int v21; // r10
  int v22; // r8
  int v23; // r9
  idRenderModelEffects::sortedParticleStage_t *v24; // r10
  idRenderModelEffects::sortedParticleStage_t *v25; // r11
  int v26; // r11
  int v27; // r10
  int v28; // r5
  const effectParticleParms_t *v29; // r4
  const idParticleStage *v30; // r3
  effectParticleParms_t v31; // [sp+50h] [-C0h] BYREF

  for ( i = this->lastLatchedParticleRange[1]; i < this->latchedParticleRange[1]; ++i )
  {
    numSortedParticleStages = this->numSortedParticleStages;
    v4 = 0;
    v5 = &this->particles[i & 0xFFF];
    stage = v5->stage;
    if ( numSortedParticleStages > 0 )
    {
      sortedParticleStages = this->sortedParticleStages;
      do
      {
        if ( sortedParticleStages->stage == stage )
          break;
        ++v4;
        ++sortedParticleStages;
      }
      while ( v4 < this->numSortedParticleStages );
    }
    if ( v4 < numSortedParticleStages )
    {
      LOWORD(v8) = i;
      v31 = *v5;
      v9 = numSortedParticleStages - 1;
      if ( numSortedParticleStages - 1 > v4 )
      {
        v10 = v9 - v4;
        p_first = &this->sortedParticleStages[v9 + 1].first;
        do
        {
          effectParticleParms_t::operator=(
            this: &this->particles[v8 & 0xFFF],
            __that: &this->particles[*(p_first - 3) & 0xFFF]);
          --v10;
          v12 = *(p_first - 3) + 1;
          v8 = *(p_first - 3);
          p_first -= 3;
          *p_first = v12;
        }
        while ( v10 != 0 );
      }
      effectParticleParms_t::operator=(this: &this->particles[v8 & 0xFFF], __that: &v31);
      ++this->sortedParticleStages[v4].num;
    }
    else
    {
      if ( numSortedParticleStages >= 1024 )
      {
        idLib::Error(fmt: "MAX_SORTED_PARTICLE_STAGES");
        idRenderModelEffects::EstimateQuadAllocation(stage: v30, particle: v29, renderTime: v28);
        return;
      }
      this->sortedParticleStages[numSortedParticleStages].stage = stage;
      this->sortedParticleStages[this->numSortedParticleStages].first = i;
      this->sortedParticleStages[this->numSortedParticleStages++].num = 1;
    }
  }
  v13 = 0;
  if ( this->numSortedParticleStages > 0 )
  {
    p_num = &this->sortedParticleStages[0].num;
    do
    {
      v15 = 0;
      if ( *p_num > 0 )
      {
        v16 = p_num - 1;
        do
        {
          v17 = v15 + *v16;
          v18 = &this->particles[v17 & 0xFFF];
          if ( this->gameTime - v18->startTime > v18->duration )
          {
            v31 = *v18;
            v19 = v13;
            if ( v13 >= 0 )
            {
              v20 = v16 + 3;
              do
              {
                effectParticleParms_t::operator=(
                  this: &this->particles[v17 & 0xFFF],
                  __that: &this->particles[*(v20 - 3) & 0xFFF]);
                --v19;
                v21 = *(v20 - 3) + 1;
                v17 = *(v20 - 3);
                v20 -= 3;
                *v20 = v21;
              }
              while ( v19 >= 0 );
            }
            effectParticleParms_t::operator=(this: &this->particles[v17 & 0xFFF], __that: &v31);
            --*p_num;
          }
          ++v15;
        }
        while ( v15 < *p_num );
      }
      ++v13;
      p_num += 3;
    }
    while ( v13 < this->numSortedParticleStages );
  }
  v22 = 0;
  v23 = 0;
  if ( this->numSortedParticleStages > 0 )
  {
    v24 = this->sortedParticleStages;
    v25 = this->sortedParticleStages;
    do
    {
      if ( v25->num >= 1 )
      {
        ++v22;
        v24->stage = v25->stage;
        v24->first = v25->first;
        v24->num = v25->num;
        ++v24;
      }
      ++v23;
      ++v25;
    }
    while ( v23 < this->numSortedParticleStages );
  }
  v26 = this->latchedParticleRange[0];
  v27 = this->latchedParticleRange[1];
  this->numSortedParticleStages = v22;
  this->lastLatchedParticleRange[0] = v26;
  this->lastLatchedParticleRange[1] = v27;
}


// ========================================================================
// ?EstimateQuadAllocation@idRenderModelEffects@@CAHPBVidParticleStage@@PBUeffectParticleParms_t@@H@Z
// EA  : 0x827EEA78
// RVA : 0x007EEA78
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

int __fastcall idRenderModelEffects::EstimateQuadAllocation(
        const idParticleStage *stage,
        const effectParticleParms_t *particle,
        int renderTime)
{
  __int16 totalParticles; // r11
  int v4; // r9
  signed int v5; // r11
  int v6; // r10
  int numParticles; // r8
  const idStaticParticleModelData *staticData; // r7
  int v9; // r6
  int v10; // r9
  int v11; // r6
  int v12; // r10

  if ( stage->cycleMsec == 0 )
    return 0;
  totalParticles = stage->systemProperties.totalParticles;
  v4 = totalParticles;
  if ( totalParticles == 0 )
    return 0;
  v5 = (int)(float)((float)(stage->systemProperties.spawnBunching * stage->bunchTime) * (float)1000.0);
  v6 = renderTime - (int)(float)(stage->maxParticleLife * (float)1000.0) - particle->startTime;
  if ( v5 != 0 )
  {
    numParticles = particle->numParticles;
    staticData = stage->staticData;
    v9 = v4 * v6 + v5;
    __twllei(v5, 0);
    v10 = __ROL4__(v9, 1);
    v11 = numParticles - (__CFADD__(v9 / v5, 0x80000000) ? 0 : v9 / v5);
    __twlgei(v5 & ~(v10 - 1), 0xFFFFFFFF);
    v12 = __CFADD__(v11, 0x80000000) ? 0 : v11;
    if ( staticData != nullptr )
    {
      return (stage->numStaticVerts * v12) >> 2;
    }
    else if ( stage->orientation.type == POR_TRAIL )
    {
      return (4 * (stage->orientation.numTrails + 1) * v12) >> 2;
    }
    else
    {
      return (4 * v12) >> 2;
    }
  }
  else if ( v6 < 0 )
  {
    if ( stage->staticData != nullptr )
    {
      return (particle->numParticles * stage->numStaticVerts) >> 2;
    }
    else if ( stage->orientation.type == POR_TRAIL )
    {
      return (particle->numParticles * 4 * (stage->orientation.numTrails + 1)) >> 2;
    }
    else
    {
      return (4 * particle->numParticles) >> 2;
    }
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ??0idRenderModelEffects@@QAA@XZ
// EA  : 0x827EEC38
// RVA : 0x007EEC38
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

idRenderModelEffects *__fastcall idRenderModelEffects::idRenderModelEffects(idRenderModelEffects *this)
{
  char v2; // r11
  idTriangles *v3; // r29
  _DWORD *v4; // r3
  int v5; // r11
  int i; // ctr
  float *v7; // r10
  float *v8; // r10
  idTriangles *v9; // r10
  float *v10; // r10
  float *v11; // r10
  float *v12; // r10
  float *v13; // r10
  float *v14; // r10

  idRenderModel::idRenderModel(this);
  this->__vftable = (idRenderModelEffects_vtbl *)&idRenderModelEffects::`vftable';
  `eh vector constructor iterator'(
    ptr: this->deferredStages,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idList<idVehicleKey *,5>::idList<idVehicleKey *,5>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  idRenderModel::SetAxis(this, a: &mat3_identity);
  idRenderModel::FreeSurfaces(this);
  v2 = *((_BYTE *)&this->g + 105);
  v3 = nullptr;
  this->gameTime = 0;
  this->deltaTime = 0;
  this->latchedTime = 0;
  this->particleRange[1] = 0;
  this->particleRange[0] = 0;
  this->tracerRange[1] = 0;
  this->tracerRange[0] = 0;
  this->decalRange[1] = 0;
  this->decalRange[0] = 0;
  this->particleTrailRange[1] = 0;
  this->particleTrailRange[0] = 0;
  this->lastLatchedParticleRange[1] = 0;
  this->lastLatchedParticleRange[0] = 0;
  this->latchedParticleRange[1] = 0;
  this->latchedParticleRange[0] = 0;
  this->latchedTracerRange[1] = 0;
  this->latchedTracerRange[0] = 0;
  this->latchedDecalRange[1] = 0;
  this->latchedDecalRange[0] = 0;
  this->numSortedParticleStages = 0;
  *((_BYTE *)&this->g + 105) = v2 | 0x84;
  this->particles = (effectParticleParms_t *)idMem::AllocWithLocation(
                                               this: &mem,
                                               location: "w:\\tech5\\engine\\models\\particles\\RenderModelEffects.cpp(163) : TAG_EFFECT_PARTICLE",
                                               size: 0x70000u,
                                               tag: TAG_EFFECT_PARTICLE,
                                               zeroBuffer: true,
                                               align: ALIGN_16,
                                               heap: HEAP_DEFAULTHEAP);
  this->tracers = (tracerParms_t *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\engine\\models\\particles\\RenderModelEffects.cpp(164) : TAG_EFFECT_PARTICLE",
                                     size: 0x1800u,
                                     tag: TAG_EFFECT_PARTICLE,
                                     zeroBuffer: true,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  this->decals = (decalParms_t *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\engine\\models\\particles\\RenderModelEffects.cpp(165) : TAG_EFFECT_PARTICLE",
                                   size: 0x5000u,
                                   tag: TAG_EFFECT_PARTICLE,
                                   zeroBuffer: true,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  this->decalVerts = (decalVerts_t *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\engine\\models\\particles\\RenderModelEffects.cpp(166) : TAG_EFFECT_PARTICLE",
                                       size: 0x20000u,
                                       tag: TAG_EFFECT_PARTICLE,
                                       zeroBuffer: true,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
  this->particleTrails = (particleTrailParms_t *)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\engine\\models\\particles\\RenderModelEffects.cpp(167) : T"
                                                   "AG_EFFECT_PARTICLE",
                                                   size: 0x500u,
                                                   tag: TAG_EFFECT_PARTICLE,
                                                   zeroBuffer: true,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
  this->particleRenderView = (particleRenderView_t *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\engine\\models\\particles\\RenderModelEffects.cpp(173)"
                                                       " : TAG_EFFECT_PARTICLE",
                                                       size: 0x40u,
                                                       tag: TAG_EFFECT_PARTICLE,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
  this->particleGenParms = (deferredParticleGenParms_t *)idMem::AllocWithLocation(
                                                           this: &mem,
                                                           location: "w:\\tech5\\engine\\models\\particles\\RenderModelEffects.cpp("
                                                           "174) : TAG_EFFECT_PARTICLE",
                                                           size: 0x40000u,
                                                           tag: TAG_EFFECT_PARTICLE,
                                                           zeroBuffer: false,
                                                           align: ALIGN_16,
                                                           heap: HEAP_DEFAULTHEAP);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)this->deferredStages);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->deferredStages[1]);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->deferredStages[2]);
  v4 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
         size: 0x21004u,
         tag: TAG_EFFECT_PARTICLE,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
  {
    v3 = (idTriangles *)(v4 + 1);
    *v4 = 1024;
    `eh vector constructor iterator'(
      ptr: v4 + 1,
      size: 0x84u,
      count: 1024,
      pCtor: (void (__fastcall *)(void *))idTriangles::idTriangles,
      pDtor: (void (__fastcall *)(void *))idTriangles::~idTriangles);
  }
  this->triangles = v3;
  v5 = 3;
  for ( i = 128; i != 0; --i )
  {
    v7 = (float *)&this->triangles[v5 - 3];
    *v7 = -99999.0;
    v7[2] = -99999.0;
    v7[1] = -99999.0;
    v7[5] = 99999.0;
    v7[4] = 99999.0;
    v7[3] = 99999.0;
    v8 = (float *)&this->triangles[v5 - 3];
    v8[35] = -99999.0;
    v8[34] = -99999.0;
    v8[33] = -99999.0;
    v8[38] = 99999.0;
    v8[37] = 99999.0;
    v8[36] = 99999.0;
    v9 = &this->triangles[v5];
    v9[-1].bounds.b[0].z = -99999.0;
    v9[-1].bounds.b[0].y = -99999.0;
    v9[-1].bounds.b[0].x = -99999.0;
    v9[-1].bounds.b[1].z = 99999.0;
    v9[-1].bounds.b[1].y = 99999.0;
    v9[-1].bounds.b[1].x = 99999.0;
    v10 = (float *)&this->triangles[v5];
    v10[2] = -99999.0;
    v10[1] = -99999.0;
    *v10 = -99999.0;
    v10[5] = 99999.0;
    v10[4] = 99999.0;
    v10[3] = 99999.0;
    v11 = (float *)&this->triangles[v5];
    v11[35] = -99999.0;
    v11[34] = -99999.0;
    v11[33] = -99999.0;
    v11[38] = 99999.0;
    v11[37] = 99999.0;
    v11[36] = 99999.0;
    v12 = (float *)&this->triangles[v5];
    v12[68] = -99999.0;
    v12[67] = -99999.0;
    v12[66] = -99999.0;
    v12[71] = 99999.0;
    v12[70] = 99999.0;
    v12[69] = 99999.0;
    v13 = (float *)&this->triangles[v5];
    v13[101] = -99999.0;
    v13[100] = -99999.0;
    v13[99] = -99999.0;
    v13[104] = 99999.0;
    v13[103] = 99999.0;
    v13[102] = 99999.0;
    v14 = (float *)&this->triangles[v5];
    v14[134] = -99999.0;
    v5 += 8;
    v14[133] = -99999.0;
    v14[132] = -99999.0;
    v14[137] = 99999.0;
    v14[136] = 99999.0;
    v14[135] = 99999.0;
  }
  return this;
}


// ========================================================================
// __unwind$231043_0
// EA  : 0x827EEFCC
// RVA : 0x007EEFCC
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void _unwind_231043_0()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$231044_0
// EA  : 0x827EEFF4
// RVA : 0x007EEFF4
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void _unwind_231044_0()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 14428),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$231045_0
// EA  : 0x827EF030
// RVA : 0x007EF030
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void _unwind_231045_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_EFFECT_PARTICLE);
}


// ========================================================================
// ??1idRenderModelEffects@@MAA@XZ
// EA  : 0x827EF068
// RVA : 0x007EF068
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void __fastcall idRenderModelEffects::~idRenderModelEffects(idRenderModelEffects *this)
{
  idTriangles *triangles; // r3
  bufferUsageType_t *p_usage; // r27

  this->__vftable = (idRenderModelEffects_vtbl *)&idRenderModelEffects::`vftable';
  idMem::Free(this: &mem, ptr: this->particles, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->particleTrails, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->tracers, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->decals, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->decalVerts, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->particleRenderView, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->particleGenParms, align: ALIGN_16);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)this->deferredStages);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->deferredStages[1]);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->deferredStages[2]);
  triangles = this->triangles;
  if ( triangles != nullptr )
  {
    p_usage = &triangles[-1].indexBuffer.usage;
    `eh vector destructor iterator'(
      ptr: triangles,
      size: 0x84u,
      count: triangles[-1].indexBuffer.usage,
      pDtor: (void (__fastcall *)(void *))idTriangles::~idTriangles);
    idMem::Free(this: &mem, ptr: p_usage, align: ALIGN_16);
  }
  `eh vector destructor iterator'(
    ptr: this->deferredStages,
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$231300
// EA  : 0x827EF17C
// RVA : 0x007EF17C
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void _unwind_231300()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$231301
// EA  : 0x827EF1A4
// RVA : 0x007EF1A4
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void _unwind_231301()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 14428),
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// ?AddParticles@idRenderModelEffects@@QAA_NPBVidDeclParticle@@HHMABVidVec3@@ABVidMat3@@1ABI@Z
// EA  : 0x827EF3D8
// RVA : 0x007EF3D8
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

int __fastcall idRenderModelEffects::AddParticles(
        idRenderModelEffects *this,
        const idDeclParticle *particle,
        const int systemStartTime,
        const int gameMsPerFrame,
        double diversity,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *velocity,
        float *color,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        unsigned int *a29)
{
  unsigned __int64 v35; // r6
  int v39; // r15
  double v40; // fp27
  idRenderWorld *World; // r3
  int num; // r10
  int v43; // r18
  double z; // fp31
  int v45; // r17
  double y; // fp30
  double x; // fp29
  idParticleStage *v48; // r28
  int cycleMsec; // r11
  int v50; // r20
  __int16 totalParticles; // r10
  signed int v52; // r11
  int gameTime; // r9
  int v54; // r8
  int v55; // r26
  int v56; // r25
  int v57; // r9
  int v58; // r11
  effectParticleParms_t *particles; // r10
  effectParticleParms_t *v60; // r30
  double v61; // fp0
  int v62; // r5
  unsigned __int8 v63; // [sp+50h] [-F0h]
  idPLogScope v64; // [sp+60h] [-E0h] BYREF
  idVec3 v65; // [sp+68h] [-D8h]

  LODWORD(v35) = "idRenderModelEffects::AddParticles";
  HIDWORD(v35) = 1;
  idPLogScope::idPLogScope(this: &v64, pl: &pLog, gMask: v35, label: (const char *)origin);
  if ( r_skipEffects.valueInteger != 0
    || particle == nullptr
    || this->particleRange[1] - this->latchedParticleRange[0] >= 4096 )
  {
    idPLogScope::~idPLogScope(this: &v64);
    return 0;
  }
  else
  {
    v39 = 0;
    v63 = 0;
    v40 = 1.0;
    if ( idRenderModel::GetWorld(this) != nullptr )
    {
      World = idRenderModel::GetWorld(this);
      v40 = ((double (__fastcall *)(idRenderWorld *, const idMat3 *))World->ShadowSample)(a1: World, a2: axis);
    }
    num = particle->stages.num;
    v65 = vec3_origin;
    v43 = (int)(float)((float)diversity * (float)65535.0);
    if ( num > 0 )
    {
      z = v65.z;
      v45 = 0;
      y = v65.y;
      x = v65.x;
      do
      {
        v48 = particle->stages.list[v45];
        cycleMsec = v48->cycleMsec;
        v50 = (int)(float)(1000.0 * v48->maxParticleLife);
        if ( cycleMsec != 0
          && v48->systemProperties.material != nullptr
          && v48->maxParticleLife > 0.0
          && (*((_BYTE *)v48 + 68) & 8) == 0 )
        {
          totalParticles = v48->systemProperties.totalParticles;
          v52 = (int)v48->systemProperties.spawnBunching * cycleMsec;
          gameTime = this->gameTime;
          v54 = gameTime - systemStartTime;
          if ( v52 != 0 )
          {
            v56 = totalParticles * v54 / v52;
            __twllei(v52, 0);
            __twlgei(v52 & ~(__ROL4__(totalParticles * v54, 1) - 1), 0xFFFFFFFF);
            if ( v56 >= totalParticles )
              v56 = totalParticles - 1;
            v57 = v54 - gameMsPerFrame;
            if ( v54 - gameMsPerFrame >= 0 )
            {
              v55 = v57 * totalParticles / v52;
              __twllei(v52, 0);
              __twlgei(v52 & ~(__ROL4__(v57 * totalParticles, 1) - 1), 0xFFFFFFFF);
            }
            else
            {
              v55 = -1;
            }
            goto LABEL_22;
          }
          if ( gameTime == systemStartTime )
          {
            v55 = -1;
            v56 = totalParticles - 1;
LABEL_22:
            if ( v55 < totalParticles )
            {
              if ( v56 < totalParticles - 1 )
                v63 = 1;
              v58 = this->particleRange[1];
              particles = this->particles;
              this->particleRange[1] = v58 + 1;
              v60 = &particles[v58 & 0xFFF];
              v60->stage = v48;
              v60->tables = idDeclParticle::GetTables(this: particle);
              v60->numTables = particle->tables.num;
              v60->diversity = v43;
              v60->origin.x = axis->mat[0].x;
              v60->origin.y = axis->mat[0].y;
              v60->origin.z = axis->mat[0].z;
              v60->velocity.x = *color;
              v60->velocity.y = color[1];
              v60->velocity.z = color[2];
              v60->axis.mat[0].x = velocity->x;
              v60->axis.mat[0].y = velocity->y;
              v60->axis.mat[0].z = velocity->z;
              v60->axis.mat[1].x = velocity[1].x;
              v60->axis.mat[1].y = velocity[1].y;
              v60->axis.mat[1].z = velocity[1].z;
              v60->axis.mat[2].x = velocity[2].x;
              v60->axis.mat[2].y = velocity[2].y;
              v60->axis.mat[2].z = velocity[2].z;
              v60->wind.x = x;
              v60->wind.y = y;
              v60->wind.z = z;
              if ( v48->colorAttributes.useGlobalShadows )
                v61 = v40;
              else
                v61 = 1.0;
              v60->shadow = v61;
              v60->color = *a29;
              v60->numParticles = ((v56 == v55) + ((unsigned int)(v56 - v55) >> 31) - 1) & (v56 - v55);
              v62 = (int)(float)(v48->systemProperties.timeOffset * 1000.0) + systemStartTime;
              v60->duration = v50;
              v60->startTime = v62;
              v60->currTime = this->gameTime;
            }
          }
        }
        ++v39;
        ++v45;
      }
      while ( v39 < particle->stages.num );
    }
    idPLogScope::~idPLogScope(this: &v64);
    return v63;
  }
}


// ========================================================================
// __unwind$231446
// EA  : 0x827EF7C0
// RVA : 0x007EF7C0
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void _unwind_231446()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 96));
}


// ========================================================================
// ?Update@idRenderModelEffects@@QAAXHH@Z
// EA  : 0x827EF7F0
// RVA : 0x007EF7F0
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRenderModelEffects::Update(
        idRenderModelEffects *this,
        int newTime,
        int gameMsPerFrame,
        int a4,
        const char *a5)
{
  unsigned __int64 v8; // r6
  int v9; // r19
  int v10; // r8
  __int64 v11; // r7 OVERLAPPED
  int gameTime; // r10
  particleTrailParms_t *v13; // r30
  int lastTime; // r29
  int endTime; // r25
  int valueInteger; // r26
  __int64 v17; // r10
  double z; // fp0
  unsigned int v19; // r8
  double x; // fp2
  double v21; // fp0
  double v22; // fp13
  int v23; // r11
  int v24; // r7
  effectParticleParms_t *particles; // r9
  int v26; // r8
  int v27; // r10
  int v28; // r6
  tracerParms_t *tracers; // r8
  int v30; // r7
  int v31; // r11
  int *v32; // r10
  int v33; // r6
  decalParms_t *decals; // r8
  int v35; // r7
  const idMaterial **v36; // r10
  int v37; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v39; // r30
  int v40; // r3
  __int64 totalTicks; // r11
  __int64 v42; // r9
  int v43; // [sp+8h] [-108h]
  int v44; // [sp+Ch] [-104h]
  int v45; // [sp+10h] [-100h]
  int v46; // [sp+14h] [-FCh]
  int v47; // [sp+18h] [-F8h]
  int v48; // [sp+1Ch] [-F4h]
  int v49; // [sp+20h] [-F0h]
  int v50; // [sp+24h] [-ECh]
  int v51; // [sp+28h] [-E8h]
  int v52; // [sp+2Ch] [-E4h]
  int v53; // [sp+30h] [-E0h]
  int v54; // [sp+34h] [-DCh]
  int v55; // [sp+38h] [-D8h]
  int v56; // [sp+3Ch] [-D4h]
  int v57; // [sp+40h] [-D0h]
  int v58; // [sp+44h] [-CCh]
  int v59; // [sp+48h] [-C8h]
  int v60; // [sp+4Ch] [-C4h]
  int v61; // [sp+50h] [-C0h]
  unsigned int v62; // [sp+60h] [-B0h] BYREF
  idPLogScope v63[4]; // [sp+68h] [-A8h] BYREF
  idMat3 v64; // [sp+88h] [-88h] BYREF

  LODWORD(v8) = "idRenderModelEffects::Update";
  HIDWORD(v8) = 1;
  idPLogScope::idPLogScope(this: v63, pl: &::pLog, gMask: v8, label: a5);
  v9 = this->particleTrailRange[0];
  v10 = this->particleTrailRange[1];
  LODWORD(v11) = newTime - this->gameTime;
  this->gameTime = newTime;
  this->deltaTime = v11;
  if ( v9 < v10 )
  {
    do
    {
      gameTime = this->gameTime;
      v13 = &this->particleTrails[this->particleTrailRange[0] & 0x1F];
      lastTime = v13->lastTime;
      if ( lastTime <= gameTime )
      {
        endTime = v13->endTime;
        if ( gameTime < endTime )
          endTime = this->gameTime;
        if ( r_particleTrail_timeStep.valueInteger <= 0 )
          valueInteger = 1;
        else
          valueInteger = r_particleTrail_timeStep.valueInteger;
        if ( lastTime <= endTime )
        {
          v62 = -1;
          do
          {
            HIDWORD(v17) = v13->endTime;
            LODWORD(v17) = lastTime;
            z = v13->dir.z;
            __SET_PAIR__(v19, v11, *(_QWORD *)&v13->startTime);
            v63[3] = (idPLogScope)v11;
            v63[1] = (idPLogScope)v17;
            v63[2] = *(idPLogScope *)((char *)&v11 - 4);
            x = v13->startPos.x;
            v22 = (float)((float)((float)z
                                * (float)((float)((float)v17 - (float)*(__int64 *)((char *)&v11 - 4))
                                        / (float)((float)v11 - (float)*(__int64 *)((char *)&v11 - 4))))
                        + v13->startPos.z);
            v21 = (float)(v13->dir.x
                        * (float)((float)((float)v17 - (float)*(__int64 *)((char *)&v11 - 4))
                                / (float)((float)v11 - (float)*(__int64 *)((char *)&v11 - 4))));
            v64.mat[0].y = (float)(v13->dir.y
                                 * (float)((float)((float)v17 - (float)*(__int64 *)((char *)&v11 - 4))
                                         / (float)((float)v11 - (float)*(__int64 *)((char *)&v11 - 4))))
                         + v13->startPos.y;
            v64.mat[0].z = v22;
            v64.mat[0].x = (float)x + (float)v21;
            idRenderModelEffects::AddParticles(
              this,
              particle: v13->decl,
              systemStartTime: lastTime,
              gameMsPerFrame,
              diversity: 0.30000001,
              origin: (const idVec3 *)v11,
              axis: &v64,
              velocity: mat3_identity.mat,
              color: &vec3_origin.x,
              a10: v43,
              a11: v44,
              a12: v45,
              a13: v46,
              a14: v47,
              a15: v48,
              a16: v49,
              a17: v50,
              a18: v51,
              a19: v52,
              a20: v53,
              a21: v54,
              a22: v55,
              a23: v56,
              a24: v57,
              a25: v58,
              a26: v59,
              a27: v60,
              a28: v61,
              a29: &v62);
            lastTime += valueInteger;
            v13->lastTime = lastTime;
          }
          while ( lastTime <= endTime );
        }
        if ( this->gameTime >= v13->endTime )
          ++this->particleTrailRange[0];
      }
      ++v9;
    }
    while ( v9 < this->particleTrailRange[1] );
  }
  v23 = this->particleTrailRange[1] - 32;
  if ( this->particleTrailRange[0] < v23 )
    this->particleTrailRange[0] = v23;
  v24 = this->particleRange[1];
  if ( this->particleRange[0] < v24 )
  {
    particles = this->particles;
    v26 = this->gameTime;
    do
    {
      v27 = this->particleRange[0];
      if ( v26 - particles[v27 & 0xFFF].startTime <= particles[v27 & 0xFFF].duration )
        break;
      this->particleRange[0] = v27 + 1;
    }
    while ( v27 + 1 < this->particleRange[1] );
  }
  if ( this->particleRange[0] < v24 - 4096 )
    this->particleRange[0] = v24 - 4096;
  v28 = this->tracerRange[1];
  if ( this->tracerRange[0] < v28 )
  {
    tracers = this->tracers;
    v30 = this->gameTime;
    do
    {
      v31 = this->tracerRange[0];
      v32 = &tracers->startTime + 4 * (v31 & 0x7F) + 4 * ((2 * v31) & 0xFE);
      if ( v30 - *v32 <= v32[1] )
        break;
      this->tracerRange[0] = v31 + 1;
    }
    while ( v31 + 1 < this->tracerRange[1] );
  }
  if ( this->tracerRange[0] < v28 - 128 )
    this->tracerRange[0] = v28 - 128;
  v33 = this->decalRange[1];
  if ( this->decalRange[0] < v33 )
  {
    decals = this->decals;
    v35 = this->gameTime;
    do
    {
      v36 = &decals->mat + (this->decalRange[0] & 0x3FF) + ((4 * this->decalRange[0]) & 0xFFC);
      if ( v35 - (int)v36[1] <= (int)v36[2] )
        break;
      v37 = this->decalRange[0] + 1;
      this->decalRange[0] = v37;
    }
    while ( v37 < this->decalRange[1] );
  }
  if ( this->decalRange[0] < v33 - 1024 )
    this->decalRange[0] = v33 - 1024;
  idRenderModel::CommitThisFrame(this);
  if ( v63[0].logIndex >= 0 )
  {
    pLog = v63[0].pLog;
    v39 = &v63[0].pLog->logEntries.list[v63[0].logIndex];
    v40 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v39->totalTicks;
    HIDWORD(totalTicks) = v39->parent;
    LODWORD(v42) = v40 - totalTicks;
    v39->totalTicks = v42;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
}


// ========================================================================
// __unwind$231563
// EA  : 0x827EFB70
// RVA : 0x007EFB70
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void _unwind_231563()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 104));
}


// ========================================================================
// ?UpdateInView@idRenderModelEffects@@EAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x827EFBA0
// RVA : 0x007EFBA0
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idRenderModelEffects::UpdateInView(
        idRenderModelEffects *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools,
        const char *a5)
{
  unsigned __int64 v5; // r22
  float *p_renderTime; // r17
  idRenderModelUpdateTools *v9; // r15
  unsigned __int64 v10; // r6
  idCVar *v12; // r14
  unsigned int LastError; // r3
  float y; // r10
  float z; // r9
  int v17; // r3
  idDrawVert **v18; // r18
  int *v19; // r19
  int *v20; // r16
  int *v21; // r23
  int v22; // r27
  int num; // r25
  double v24; // fp27
  double v25; // fp26
  double v26; // fp25
  int v27; // r7
  char *v28; // r10
  const idMaterial *v29; // r4
  int v30; // r10
  idTriangles *triangles; // r9
  idTriangles *v32; // r28
  int v33; // r29
  __int64 v34; // r6
  int v35; // r8
  int v36; // r26
  char *v37; // r10
  int v38; // r11
  idDrawVert *v39; // r9
  float *p_x; // r11
  char v41; // r9
  __int64 v42; // r8
  double v43; // fp0
  double v44; // fp10
  int v45; // r8
  double v46; // fp9
  float v47; // r7
  double v48; // fp8
  double v49; // fp6
  double v50; // fp3
  double v51; // fp21
  double v52; // fp1
  double v53; // fp20
  double v54; // fp10
  double v55; // fp6
  double v56; // fp4
  double v57; // fp5
  double v58; // fp0
  double v59; // fp1
  double v60; // fp11
  double v61; // fp12
  double v64; // fp13
  double v65; // fp8
  double v66; // fp2
  double v67; // fp1
  double v68; // fp5
  double v69; // fp3
  double v70; // fp2
  double v71; // fp1
  double v72; // fp13
  double v73; // fp9
  double v74; // fp7
  double v75; // fp5
  double v76; // fp6
  double v77; // fp3
  int v78; // r26
  int v79; // r20
  decalParms_t **p_decals; // r24
  decalParms_t *v81; // r8
  int v82; // r7
  const idMaterial *v83; // r3
  int v84; // r10
  idTriangles *v85; // r10
  idTriangles *v86; // r29
  int v87; // r27
  int v88; // r28
  int v89; // r4
  int v90; // r8
  int i; // r25
  __int64 v92; // r11
  int v93; // r10
  idDrawVert *v94; // r9
  char v96; // r10
  int v97; // r9
  double v98; // fp0
  int v99; // r7 OVERLAPPED
  __int64 v100; // r9
  __int64 v101; // r9
  int v103; // ctr
  int v110; // ctr
  int v113; // r11
  int v114; // r28
  int v115; // r26
  const idVertexBuffer *v116; // r25
  int v117; // r27
  char *v118; // r11
  int v119; // r11
  idTriangles *v120; // r10
  int v121; // r9
  int v122; // r8
  const idMaterial *v123; // r7
  int v124; // r19
  idTriangles *v125; // r29
  int v126; // r18
  particleRenderView_t *particleRenderView; // r5
  double v128; // fp12
  particleRenderView_t *v129; // r11
  particleRenderView_t *v130; // r11
  particleRenderView_t *v131; // r11
  int v132; // r27
  int v133; // r29
  int v134; // r12
  int *v135; // r28
  effectParticleParms_t *v136; // r4
  idRenderModelTransparency *transparencyModel; // r9
  char *v138; // r10
  const visibleInfluenceSpheres_t *visibleInfluenceSpheres; // r26
  idList<aas2Edge_t,37> *v140; // r25
  aas2Edge_t *list; // r4
  int v142; // r28
  int v143; // r21
  int v144; // r29
  int *v145; // r10
  int v146; // r6
  int v147; // r3
  effectParticleParms_t *particles; // r8
  int v149; // r9
  unsigned int v150; // r7
  const effectParticleParms_t *v151; // r11
  _DWORD *v152; // r5
  effectParticleParms_t *v153; // r10
  const idParticleStage *stage; // r7
  idTransparencyVert **p_verts; // r4
  deferredParticleGenParms_t *particleGenParms; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v158; // r30
  int v159; // r3
  __int64 totalTicks; // r11
  __int64 v161; // r9
  _DWORD back_chain[19]; // [sp+0h] [-280h]
  int v163; // [sp+4Ch] [-234h] BYREF
  int vertexNum; // [sp+50h] [-230h] BYREF
  int v165; // [sp+54h] [-22Ch]
  __int64 v166; // [sp+58h] [-228h]
  __int64 v167; // [sp+60h] [-220h]
  float v168; // [sp+68h] [-218h]
  aas2Edge_t v169; // [sp+70h] [-210h] BYREF
  idRenderModelSurface v170; // [sp+80h] [-200h] BYREF
  idVertexBuffer *v171; // [sp+B8h] [-1C8h]
  const idIndexBuffer *v172; // [sp+BCh] [-1C4h]
  int valueInteger; // [sp+C0h] [-1C0h]
  idCVar *v174; // [sp+C4h] [-1BCh]
  __int64 v175; // [sp+C8h] [-1B8h]
  __int64 v176; // [sp+D0h] [-1B0h]
  __int64 v177; // [sp+D8h] [-1A8h]
  idDrawVert **v178; // [sp+E0h] [-1A0h]
  int *v179; // [sp+E4h] [-19Ch]
  __int64 v180; // [sp+E8h] [-198h]
  int *v181; // [sp+F0h] [-190h]
  int *v182; // [sp+F4h] [-18Ch]
  idPLogScope v183; // [sp+F8h] [-188h] BYREF
  _BYTE v184[16]; // [sp+100h] [-180h] BYREF
  int v185; // [sp+110h] [-170h] BYREF
  unsigned __int8 v186; // [sp+11Fh] [-161h]
  unsigned __int8 v187; // [sp+13Fh] [-141h]
  unsigned __int8 v188; // [sp+15Fh] [-121h]
  unsigned __int8 v189; // [sp+17Fh] [-101h]

  p_renderTime = (float *)&nextView->g.renderTime;
  v9 = updateTools;
  LODWORD(v10) = "idRenderModelEffects::UpdateInView";
  HIDWORD(v10) = 1;
  idPLogScope::idPLogScope(this: &v183, pl: &::pLog, gMask: v10, label: a5);
  if ( r_skipEffects.valueInteger != 0 )
  {
    idList<idRenderModelSurface,62>::SetNum(this: &this->surfaces, newNum: 0);
    idPLogScope::~idPLogScope(this: &v183);
    return 0;
  }
  v12 = &r_recordEffectParticleTrace;
  LODWORD(v5) = 0;
  v174 = &r_recordEffectParticleTrace;
  valueInteger = r_useParticleGenJobs.valueInteger;
  if ( r_recordEffectParticleTrace.valueInteger != 0 )
  {
    valueInteger = 0;
    LastError = GetLastError();
    idLib::Printf(fmt: "BeginTraceRecording: error %d\n", LastError);
  }
  y = currentView->r.vieworg.y;
  z = currentView->r.vieworg.z;
  *(float *)&v167 = currentView->r.vieworg.x;
  *((float *)&v167 + 1) = y;
  v168 = z;
  idList<idRenderModelSurface,62>::SetNum(this: &this->surfaces, newNum: 0);
  v17 = this->latchedTracerRange[1];
  v18 = &idRenderModelEffects::mappedVerts;
  v19 = &idRenderModelEffects::vertOffset;
  v172 = &idRenderModelEffects::indexBuffer;
  v20 = &idRenderModelEffects::mappedBufferIndex;
  v178 = &idRenderModelEffects::mappedVerts;
  v179 = &idRenderModelEffects::vertOffset;
  v21 = &idRenderModelEffects::indexOffset;
  v181 = &idRenderModelEffects::mappedBufferIndex;
  v171 = idRenderModelEffects::vertexBuffer;
  v182 = &idRenderModelEffects::indexOffset;
  v22 = this->latchedTracerRange[0];
  num = this->surfaces.num;
  if ( v22 < v17 )
  {
    v24 = v168;
    v25 = *((float *)&v167 + 1);
    v26 = *(float *)&v167;
    do
    {
      v27 = num;
      v28 = (char *)this->tracers + 16 * (v22 & 0x7F) + 16 * ((2 * v22) & 0xFE);
      HIDWORD(v166) = this->surfaces.num;
      v29 = *((const idMaterial **)v28 + 11);
      if ( num < SHIDWORD(v166) )
      {
        v30 = num;
        do
        {
          if ( this->surfaces.list[v30].material == v29 )
            break;
          ++v27;
          ++v30;
        }
        while ( v27 < SHIDWORD(v166) );
      }
      if ( v27 == HIDWORD(v166) )
      {
        triangles = this->triangles;
        v170.skinOffsets.x = 0.0;
        v170.skinOffsets.y = 0.0;
        v170.material = v29;
        v170.skinOffsets.z = 0.0;
        v170.materialNum = 0;
        v170.skinOffsets.w = 0.0;
        v170.extraGLState = v5;
        v170.referenceMask = 0;
        memset(&v170.binaryModelId, 0, 16);
        v32 = &triangles[HIDWORD(v166)];
        v170.geometry = v32;
        v170.geometryIsReference = true;
        v33 = 0;
        v32->vertexMask = 31;
        v34 = (unsigned int)v22;
        v35 = *v21;
        v36 = *v21;
        if ( v22 < this->latchedTracerRange[1] )
        {
          do
          {
            v37 = (char *)this->tracers + 16 * (v34 & 0x7F) + 16 * ((2 * v34) & 0xFE);
            if ( *((const idMaterial **)v37 + 11) == v29 )
            {
              v38 = *v19;
              if ( (*v19 >> 2) + 2 >= 2048 )
              {
                p_x = nullptr;
                v41 = 0;
              }
              else
              {
                v39 = *v18;
                *v19 = v38 + 8;
                p_x = &v39[v38].xyz.x;
                *v21 = v35 + 12;
                v41 = 1;
              }
              if ( v41 == 0 )
                break;
              HIDWORD(v42) = *(_DWORD *)v37;
              LODWORD(v42) = this->latchedTime - this->deltaTime - *(_DWORD *)v37;
              v43 = (float)((float)((float)v42 * *((float *)v37 + 2)) * (float)0.001);
              v176 = v42;
              if ( v43 < 0.0 )
                v43 = 0.0;
              v44 = *((float *)v37 + 3);
              v45 = *((int *)v37 + 8);
              v46 = (float)((float)v26 - *((float *)v37 + 3));
              v47 = *((float *)v37 + 7);
              v48 = *((float *)v37 + 6);
              v49 = (float)(*((float *)v37 + 6) * (float)v43);
              v169.vertexNum[0] = *((_DWORD *)v37 + 6);
              v169.flags = v45;
              v50 = *((float *)v37 + 4);
              v51 = (float)((float)(*(float *)v169.vertexNum * (float)((float)v25 - *((float *)v37 + 4)))
                          - (float)(v47 * (float)v46));
              v52 = (float)(*(float *)&v45 * (float)((float)v25 - *((float *)v37 + 4)));
              *(float *)&v169.vertexNum[1] = v47;
              v53 = *((float *)v37 + 10);
              v54 = (float)((float)v44 + (float)v49);
              v55 = (float)(*((float *)v37 + 5) + (float)(*(float *)&v45 * (float)v43));
              v56 = (float)((float)v50 + (float)(v47 * (float)v43));
              v57 = (float)((float)(v47 * (float)((float)v24 - *((float *)v37 + 5))) - (float)v52);
              v59 = (float)((float)(*(float *)&v45 * (float)v46)
                          - (float)(*(float *)v169.vertexNum * (float)((float)v24 - *((float *)v37 + 5))));
              v60 = (float)((float)((float)v50 + (float)(v47 * (float)v43)) + (float)(v47 * *((float *)v37 + 9)));
              v61 = (float)((float)(*((float *)v37 + 5) + (float)(*(float *)&v45 * (float)v43))
                          + (float)(*(float *)&v45 * *((float *)v37 + 9)));
              v58 = (float)((float)v54 + (float)((float)v48 * *((float *)v37 + 9)));
              _FP7 = (float)((float)((float)((float)v59 * (float)v59)
                                   + (float)((float)((float)v57 * (float)v57) + (float)((float)v51 * (float)v51)))
                           - idMath::FLT_SMALLEST_NON_DENORMAL);
              __asm { fsel      f2, f7, f8, f13 }
              v64 = __frsqrte(_FP2);
              v65 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v64
                                                                                                  * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)((float)v57 * (float)v57) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                          * (float)v64)
                                                                                  - (float)1.5)
                                                                  * (float)v64)
                                                          * (float)((float)((float)((float)v59 * (float)v59)
                                                                          + (float)((float)((float)v57 * (float)v57)
                                                                                  + (float)((float)v51 * (float)v51)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v64
                                                                                          * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)((float)v57 * (float)v57) + (float)((float)v51 * (float)v51)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v64)
                                                                          - (float)1.5)
                                                          * (float)v64))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v64
                                                                  * (float)((float)((float)((float)v59 * (float)v59)
                                                                                  + (float)((float)((float)v57
                                                                                                  * (float)v57)
                                                                                          + (float)((float)v51
                                                                                                  * (float)v51)))
                                                                          * (float)0.5))
                                                          * (float)v64)
                                                  - (float)1.5)
                                  * (float)v64));
              v66 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v64 * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)((float)v57 * (float)v57) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v64) - (float)1.5) * (float)v64)
                                                                                                  * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)((float)v57 * (float)v57) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)((float)v57 * (float)v57) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v64) - (float)1.5)
                                                                                                  * (float)v64))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)((float)v57 * (float)v57) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                                  * (float)v64)
                                                                                          - (float)1.5)
                                                                          * (float)v64))
                                                          * (float)((float)((float)((float)v59 * (float)v59)
                                                                          + (float)((float)((float)v57 * (float)v57)
                                                                                  + (float)((float)v51 * (float)v51)))
                                                                  * (float)0.5))
                                                  * (float)v65)
                                          - (float)1.5)
                          * (float)v65);
              v67 = (float)((float)v59
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v64 * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)((float)v57 * (float)v57) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v64) - (float)1.5) * (float)v64) * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)((float)v57 * (float)v57) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)((float)v57 * (float)v57) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v64) - (float)1.5) * (float)v64))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v64 * (float)((float)((float)((float)v59 * (float)v59) + (float)((float)((float)v57 * (float)v57) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v64)
                                                                                                  - (float)1.5)
                                                                                  * (float)v64))
                                                                  * (float)((float)((float)((float)v59 * (float)v59)
                                                                                  + (float)((float)((float)v57
                                                                                                  * (float)v57)
                                                                                          + (float)((float)v51
                                                                                                  * (float)v51)))
                                                                          * (float)0.5))
                                                          * (float)v65)
                                                  - (float)1.5)
                                  * (float)v65));
              v68 = (float)(*((float *)v37 + 10) * (float)((float)v57 * (float)v66));
              v69 = (float)((float)((float)v67 * *((float *)v37 + 10)) * (float)0.5);
              v70 = (float)((float)((float)((float)v51 * (float)v66) * *((float *)v37 + 10)) * (float)0.5);
              v72 = (float)((float)((float)((float)v67 * *((float *)v37 + 10)) * (float)0.5) + (float)v56);
              p_x[1] = (float)((float)((float)v67 * *((float *)v37 + 10)) * (float)0.5) + (float)v56;
              v73 = (float)((float)v70 + (float)v55);
              p_x[2] = (float)v70 + (float)v55;
              v74 = (float)((float)((float)((float)v67 * (float)v53) * (float)0.5) + (float)v60);
              v76 = (float)((float)v55 - (float)v70);
              *p_x = (float)((float)v68 * (float)0.5) + (float)v54;
              p_x[8] = (float)((float)v68 * (float)0.5) + (float)v58;
              HIDWORD(v180) = p_x + 27;
              HIDWORD(v175) = p_x + 35;
              HIDWORD(v177) = p_x + 43;
              HIDWORD(v166) = p_x + 51;
              p_x[9] = (float)((float)((float)v67 * (float)v53) * (float)0.5) + (float)v60;
              v71 = (float)((float)v68 * (float)0.5);
              p_x[10] = (float)v70 + (float)v61;
              p_x[16] = (float)v54 - (float)((float)v68 * (float)0.5);
              v75 = (float)((float)v56 - (float)v69);
              p_x[17] = (float)v56 - (float)v69;
              v77 = (float)((float)v60 - (float)v69);
              p_x[18] = v76;
              p_x[24] = (float)v58 - (float)v71;
              p_x[25] = v77;
              HIDWORD(v5) = p_x + 56;
              p_x[26] = (float)v61 - (float)v70;
              p_x[32] = (float)v58 - (float)v71;
              p_x[33] = v77;
              p_x[34] = (float)v61 - (float)v70;
              p_x[40] = (float)v71 + (float)v58;
              p_x[41] = v74;
              p_x[42] = (float)v70 + (float)v61;
              p_x[48] = (float)v54 - (float)v71;
              p_x[49] = v75;
              p_x[50] = v76;
              p_x[56] = (float)v71 + (float)v54;
              p_x[57] = v72;
              p_x[58] = v73;
              p_x[3] = 0.0;
              v167 = v34;
              p_x[4] = 0.0;
              p_x[11] = 1.0;
              p_x[12] = 0.0;
              p_x[19] = 0.0;
              p_x[20] = 1.0;
              p_x[27] = 1.0;
              v21 = v182;
              p_x[28] = 1.0;
              v20 = v181;
              p_x[35] = 1.0;
              v19 = v179;
              p_x[36] = 1.0;
              v18 = v178;
              p_x[43] = 1.0;
              p_renderTime = (float *)&nextView->g.renderTime;
              p_x[44] = 0.0;
              vertexNum = (int)(p_x + 59);
              p_x[51] = 0.0;
              p_x[52] = 1.0;
              v33 += 12;
              p_x[59] = 0.0;
              p_x[60] = 0.0;
              v35 = *v21;
              v34 = v167;
            }
            LODWORD(v34) = v34 + 1;
          }
          while ( (int)v34 < this->latchedTracerRange[1] );
        }
        v32->numVerts = HIDWORD(v34);
        v32->numIndexes = v33;
        idVertexBuffer::Reference(this: &v32->vertexBuffer, other: &v171[*v20]);
        idIndexBuffer::Reference(this: &v32->indexBuffer, other: v172, refOffset: 2 * v36, refSize: 2 * v33);
        idList<idRenderModelSurface,62>::Append(this: &this->surfaces, obj: &v170);
        v9 = updateTools;
        v12 = v174;
      }
      ++v22;
    }
    while ( v22 < this->latchedTracerRange[1] );
  }
  v78 = this->latchedDecalRange[0];
  HIDWORD(v5) = &this->latchedDecalRange[1];
  v79 = this->surfaces.num;
  if ( v78 < this->latchedDecalRange[1] )
  {
    p_decals = &this->decals;
    do
    {
      v81 = *p_decals;
      v82 = v79;
      vertexNum = this->surfaces.num;
      v83 = *(&v81->mat + (v78 & 0x3FF) + ((4 * v78) & 0xFFC));
      if ( v79 < vertexNum )
      {
        v84 = v79;
        do
        {
          if ( this->surfaces.list[v84].material == v83 )
            break;
          ++v82;
          ++v84;
        }
        while ( v82 < vertexNum );
      }
      if ( v82 == vertexNum )
      {
        v85 = this->triangles;
        v170.skinOffsets.x = 0.0;
        v170.skinOffsets.y = 0.0;
        v170.material = v83;
        v170.skinOffsets.z = 0.0;
        v170.materialNum = 0;
        v170.skinOffsets.w = 0.0;
        v170.extraGLState = v5;
        v170.referenceMask = 0;
        memset(&v170.binaryModelId, 0, 16);
        v86 = &v85[vertexNum];
        v170.geometry = v86;
        v87 = 0;
        v170.geometryIsReference = true;
        v88 = 0;
        v86->vertexMask = 31;
        v89 = v78;
        v90 = *v21;
        for ( i = *v21; v89 < *(_DWORD *)HIDWORD(v5); ++v89 )
        {
          LODWORD(v92) = (char *)*p_decals + 4 * (v89 & 0x3FF) + 4 * ((4 * v89) & 0xFFC);
          if ( *(const idMaterial **)v92 == v83 )
          {
            v93 = *v19;
            if ( (*v19 >> 2) + 1 >= 2048 )
            {
              HIDWORD(_R7) = 0;
              v96 = 0;
            }
            else
            {
              v94 = *v18;
              *v19 = v93 + 4;
              HIDWORD(_R7) = &v94[v93];
              *v21 = v90 + 6;
              v96 = 1;
            }
            if ( v96 == 0 )
              break;
            v97 = *(_DWORD *)(v92 + 4);
            v98 = 0.0;
            v99 = *(_DWORD *)(v92 + 16);
            HIDWORD(v92) = this->latchedTime;
            HIDWORD(v100) = *(_DWORD *)(v92 + 12) + v97;
            LODWORD(v100) = v99 + v97;
            if ( SHIDWORD(v92) >= SHIDWORD(v100) )
            {
              if ( SHIDWORD(v92) > (int)v100 )
              {
                HIDWORD(v92) -= v100;
                HIDWORD(v100) = *(_DWORD *)(v92 + 8);
                LODWORD(_R7) = HIDWORD(v92);
                LODWORD(v92) = HIDWORD(v100) + *(_DWORD *)(v92 + 4);
                v175 = v100;
                v177 = _R7;
                v180 = v92;
                v98 = (float)((float)_R7 / (float)((float)v92 - (float)v100));
                if ( v98 >= 0.0 )
                {
                  if ( v98 > 1.0 )
                    v98 = 1.0;
                }
                else
                {
                  v98 = 0.0;
                }
              }
            }
            else
            {
              LODWORD(v101) = HIDWORD(v100);
              HIDWORD(v101) = *(_DWORD *)(v92 + 4);
              v167 = v101;
              v166 = *(_QWORD *)(&v99 - 1);
              LODWORD(v92) = HIDWORD(v92) - HIDWORD(v101);
              v176 = v92;
              v98 = (float)((float)1.0 - (float)((float)v92 / (float)((float)v101 - (float)*(__int64 *)(&v99 - 1))));
            }
            _R11 = v184;
            v103 = 4;
            _R10 = (char *)&this->decalVerts[v89 & 0x3FF] - v184;
            _R9 = 16;
            _R8 = 16;
            do
            {
              _R7 = &_R11[_R10];
              __asm
              {
                lvx128    v63, r10, r11
                lvx128    v62, r7, r9
                stvx128   v63, r0, r11
                stvx128   v62, r11, r8
              }
              _R11 += 32;
              --v103;
            }
            while ( v103 != 0 );
            LODWORD(_R7) = 16;
            _R10 = (char *)&v185 - HIDWORD(_R7);
            _R8 = -16;
            v110 = 4;
            _R11 = HIDWORD(_R7);
            v165 = (int)(float)((float)((float)1.0 - (float)v98) * (float)255.0);
            v186 = (unsigned __int16)(v186 * (unsigned __int8)v165) >> 8;
            v187 = (unsigned __int16)(v187 * (unsigned __int8)v165) >> 8;
            v188 = (unsigned __int16)(v188 * (unsigned __int8)v165) >> 8;
            v189 = (unsigned __int16)(v189 * (unsigned __int8)v165) >> 8;
            do
            {
              _R9 = &_R10[_R11];
              __asm
              {
                lvx128    v61, r10, r11
                lvx128    v60, r9, r8
                stvx128   v60, r0, r11
                stvx128   v61, r11, r7
              }
              _R11 += 32;
              --v110;
            }
            while ( v110 != 0 );
            v90 = *v21;
            v87 += 4;
            v88 += 6;
          }
        }
        v86->numVerts = v87;
        v86->numIndexes = v88;
        idVertexBuffer::Reference(this: &v86->vertexBuffer, other: &v171[*v20]);
        idIndexBuffer::Reference(this: &v86->indexBuffer, other: v172, refOffset: 2 * i, refSize: 2 * v88);
        idList<idRenderModelSurface,62>::Append(this: &this->surfaces, obj: &v170);
        v9 = updateTools;
        v12 = v174;
      }
      ++v78;
    }
    while ( v78 < *(_DWORD *)HIDWORD(v5) );
  }
  HIDWORD(v5) = &r_cuttablemodel_freecpudata.description;
  v113 = (idRenderModelTransparency::mappedBufferIndex + 2) % 3;
  v114 = this->deferredStages[v113].num;
  if ( v114 > 0 )
  {
    v115 = 16 * v113;
    v116 = &idRenderModelTransparency::vertexBufferUnsorted[v113];
    v117 = 0;
    v118 = (char *)this + 16 * v113;
    do
    {
      v119 = *((_DWORD *)v118 + 3607) + v117;
      v120 = this->triangles;
      v121 = this->surfaces.num;
      v170.skinOffsets.x = 0.0;
      v170.skinOffsets.y = 0.0;
      v170.materialNum = 0;
      v170.skinOffsets.z = 0.0;
      v170.extraGLState = v5;
      v170.skinOffsets.w = 0.0;
      v170.referenceMask = 0;
      v122 = *(_DWORD *)(v119 + 4);
      v123 = *(const idMaterial **)v119;
      v124 = *(_DWORD *)(v119 + 8);
      memset(&v170.binaryModelId, 0, 16);
      v125 = &v120[v121];
      v170.geometry = &v120[v121];
      v170.material = v123;
      v125->vertexMask = 3167;
      v125->numVerts = v122;
      v126 = 6 * (v122 >> 2);
      v170.geometryIsReference = true;
      v125->numIndexes = v126;
      idVertexBuffer::Reference(this: &v120[v121].vertexBuffer, other: v116);
      idIndexBuffer::Reference(
        this: &v125->indexBuffer,
        other: &idRenderModelTransparency::indexBufferUnsorted,
        refOffset: 2 * v124,
        refSize: 2 * v126);
      idList<idRenderModelSurface,62>::Append(this: &this->surfaces, obj: &v170);
      --v114;
      v117 += 12;
      v118 = (char *)this + v115;
    }
    while ( v114 != 0 );
  }
  idRenderModel::CommitSurfaces(this);
  particleRenderView = this->particleRenderView;
  particleRenderView->viewOrg.x = p_renderTime[508];
  vertexNum = (int)(p_renderTime + 511);
  particleRenderView->viewOrg.y = p_renderTime[509];
  vertexNum = (int)(p_renderTime + 514);
  v128 = p_renderTime[510];
  vertexNum = (int)(p_renderTime + 517);
  particleRenderView->viewOrg.z = v128;
  v129 = this->particleRenderView;
  v129->viewFwd.x = p_renderTime[511];
  v129->viewFwd.y = p_renderTime[512];
  v129->viewFwd.z = p_renderTime[513];
  v130 = this->particleRenderView;
  v130->viewLeft.x = p_renderTime[514];
  v130->viewLeft.y = p_renderTime[515];
  v130->viewLeft.z = p_renderTime[516];
  v131 = this->particleRenderView;
  v131->viewUp.x = p_renderTime[517];
  v131->viewUp.y = p_renderTime[518];
  v131->viewUp.z = p_renderTime[519];
  this->particleRenderView->renderTime = this->latchedTime;
  this->particleRenderView->deltaTime = this->deltaTime;
  this->particleRenderView->atlasWidth = globalImages->transSortImageAtlas->ATLAS_WIDTH;
  this->particleRenderView->atlasHeight = globalImages->transSortImageAtlas->ATLAS_HEIGHT;
  idRenderModelEffects::SortEffectParticles(this);
  v132 = this->latchedParticleRange[1] - this->latchedParticleRange[0];
  ((void (*)(void))RtlCheckStack12)();
  v133 = 0;
  *(_DWORD *)((char *)back_chain + v134) = back_chain[0];
  if ( v132 > 0 )
  {
    v135 = &v163;
    do
    {
      v136 = &this->particles[((_WORD)v133++ + (unsigned __int16)this->latchedParticleRange[0]) & 0xFFF];
      *++v135 = idRenderModelEffects::EstimateQuadAllocation(
                  stage: v136->stage,
                  particle: v136,
                  renderTime: this->latchedTime);
    }
    while ( v133 < v132 );
  }
  transparencyModel = v9->transparencyModel;
  v138 = (char *)this + 16 * idRenderModelTransparency::mappedBufferIndex;
  vertexNum = idRenderModelTransparency::mappedBufferIndex;
  visibleInfluenceSpheres = transparencyModel->visibleInfluenceSpheres;
  v140 = (idList<aas2Edge_t,37> *)(v138 + 14428);
  if ( *((int *)v138 + 3609) < 0 )
  {
    if ( v138[14443] == 0 || v138[14443] == 2 )
    {
      list = v140->list;
      if ( v140->list != nullptr )
      {
        vertexNum = (int)v140->list->vertexNum;
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      }
      v140->list = nullptr;
      v140->size = 0;
    }
    v140->num = 0;
  }
  v142 = 0;
  v140->num = __CFADD__(-v140->size, v140->size ^ 0x80000000) ? 0 : v140->size;
  if ( v132 > 0 )
  {
    v143 = valueInteger;
    v144 = 0;
    do
    {
      v145 = &vertexNum + v142;
      if ( *v145 != 0 )
      {
        v146 = this->latchedParticleRange[0];
        v147 = *v145;
        particles = this->particles;
        v149 = v142 + 1;
        v150 = 1;
        v151 = &particles[((_WORD)v142 + (_WORD)v146) & 0xFFF];
        if ( v142 + 1 < v132 )
        {
          v152 = v145 + 1;
          do
          {
            v153 = &particles[((_WORD)v142 + (_WORD)v146 + 1) & 0xFFF];
            if ( v153->stage != v151->stage || v153 == particles )
              break;
            if ( *v152 != 0 )
            {
              if ( (unsigned int)(v147 + *v152) > 0x80 || v150 > 0x91 )
                break;
              ++v150;
              v147 += *v152;
            }
            v142 = v149++;
            ++v152;
          }
          while ( v149 < v132 );
        }
        this->particleGenParms[v144].renderView = this->particleRenderView;
        this->particleGenParms[v144].effectParticleParms = v151;
        this->particleGenParms[v144].modelParticleParms = nullptr;
        this->particleGenParms[v144].stage = v151->stage;
        this->particleGenParms[v144].tables = v151->tables;
        this->particleGenParms[v144].staticVerts = v151->stage->staticVerts;
        this->particleGenParms[v144].numEffectParticleParms = v150;
        this->particleGenParms[v144].numModelParticleParms = 0;
        this->particleGenParms[v144].numTables = v151->numTables;
        this->particleGenParms[v144].staticVertsSize = v151->stage->numStaticVerts;
        this->particleGenParms[v144].deadTime = v151->stage->maxDeadTime;
        this->particleGenParms[v144].visibleInfluenceSpheres = visibleInfluenceSpheres;
        this->particleGenParms[v144].maxVertsToGen = 4 * v147;
        this->particleGenParms[v144].verts = nullptr;
        this->particleGenParms[v144].quadDepth = nullptr;
        this->particleGenParms[v144].quadsUsed = nullptr;
        stage = v151->stage;
        if ( (*((_BYTE *)stage + 68) & 0x40) != 0 )
        {
          if ( r_skipParticles.valueInteger != 3
            && idRenderModelTransparency::AllocateQuadSegment(
                 numQuads: v147,
                 verts: &this->particleGenParms[v144].verts,
                 quadDepths: &this->particleGenParms[v144].quadDepth,
                 quadsUsed: &this->particleGenParms[v144].quadsUsed,
                 hasEmissivePass: (*((_BYTE *)stage + 68) & 0x10) != 0) )
          {
            goto LABEL_84;
          }
        }
        else if ( r_skipParticles.valueInteger != 2 )
        {
          p_verts = &this->particleGenParms[v144].verts;
          v169.vertexNum[0] = (int)v151->stage->systemProperties.material;
          if ( idRenderModelTransparency::AllocateUnsortedQuadSegment(
                 numQuads: v147,
                 verts: p_verts,
                 indexOffset: &v169.flags,
                 vertCount: &v169.vertexNum[1]) )
          {
            idList<idRenderModelEffects::deferredStage_t,5>::Append(this: v140, obj: &v169);
LABEL_84:
            particleGenParms = this->particleGenParms;
            if ( v143 == 1 )
              idParallelJobList::AddJob(
                this: v9->transparencyJobList,
                function: (void (__fastcall *)(void *))ParticleGenJob,
                data: &particleGenParms[v144]);
            else
              ParticleGenJob(parms: &particleGenParms[v144]);
            ++v144;
          }
        }
      }
      ++v142;
    }
    while ( v142 < v132 );
  }
  if ( v12->valueInteger != 0 )
    idCVar::SetBool(this: v12, newValue: false, force: true);
  if ( v183.logIndex >= 0 )
  {
    pLog = v183.pLog;
    v158 = &v183.pLog->logEntries.list[v183.logIndex];
    v159 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v158->totalTicks;
    HIDWORD(totalTicks) = v158->parent;
    LODWORD(v161) = v159 - totalTicks;
    v158->totalTicks = v161;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  return 1;
}


// ========================================================================
// __unwind$231642
// EA  : 0x827F0B3C
// RVA : 0x007F0B3C
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void _unwind_231642()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 640 + 248));
}


// ========================================================================
// `dynamic initializer for 'r_skipEffects''
// EA  : 0x83343270
// RVA : 0x01343270
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipEffects__()
{
  idCVar::idCVar(
    this: &r_skipEffects,
    name: "r_skipEffects",
    value: "0",
    flags: 1,
    description: "skip effects system",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipEffects__);
}


// ========================================================================
// `dynamic initializer for 'r_particleTrail_timeStep''
// EA  : 0x833432C8
// RVA : 0x013432C8
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_particleTrail_timeStep__()
{
  idCVar::idCVar(
    this: &r_particleTrail_timeStep,
    name: "r_particleTrail_timeStep",
    value: "0",
    flags: 2,
    description: "particle trail time step in MS (non-zero value uses cvar)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_particleTrail_timeStep__);
}


// ========================================================================
// `dynamic initializer for 'r_recordEffectParticleTrace''
// EA  : 0x83343320
// RVA : 0x01343320
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_recordEffectParticleTrace__()
{
  idCVar::idCVar(
    this: &r_recordEffectParticleTrace,
    name: "r_recordEffectParticleTrace",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_recordEffectParticleTrace__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelEffects::vertexBuffer''
// EA  : 0x83343378
// RVA : 0x01343378
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelEffects::vertexBuffer__()
{
  `eh vector constructor iterator'(
    ptr: (char *)idRenderModelEffects::vertexBuffer,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelEffects::vertexBuffer__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelEffects::indexBuffer''
// EA  : 0x833433C8
// RVA : 0x013433C8
// PDB : w:\tech5\engine\models\particles\rendermodeleffects.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelEffects::indexBuffer__()
{
  idIndexBuffer::idIndexBuffer(this: &idRenderModelEffects::indexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelEffects::indexBuffer__);
}

