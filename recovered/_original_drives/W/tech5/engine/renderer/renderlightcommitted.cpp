
// ========================================================================
// ?CreateReferences@idRenderLightCommitted@@QAAXXZ
// EA  : 0x82943870
// RVA : 0x00943870
// PDB : w:\tech5\engine\renderer\renderlightcommitted.cpp
// ========================================================================

void __fastcall idRenderLightCommitted::CreateReferences(idRenderLightCommitted *this)
{
  idBounds *p_globalReferenceBounds; // r30
  const idBox *v3; // r3
  double v4; // fp7
  double v5; // fp5
  double y; // fp0
  double v8; // fp7
  double z; // fp2
  double v10; // fp6
  double v11; // fp4
  double v13; // fp13
  double v14; // fp1
  double v15; // fp10
  idVec3 v26[8]; // [sp+50h] [-C0h] BYREF
  idBox v27; // [sp+B0h] [-60h] BYREF

  p_globalReferenceBounds = &this->globalReferenceBounds;
  idRenderLightParms::ComputeLightGlobalReferenceBounds(
    this: &this->r,
    inverseBaseLightProject: &this->inverseBaseLightProject,
    globalReferenceBounds: &this->globalReferenceBounds,
    corners: v26);
  v3 = idBox::idBox(this: &v27, bounds: p_globalReferenceBounds);
  idRenderWorldLocal::PushPolytopeIntoTree(
    this: this->world,
    model: nullptr,
    light: this,
    box: v3,
    points: v26,
    numPoints: 8);
  if ( this->r.maxVisibleRange <= 0.0 )
  {
    this->maxVisibleRange.x = 0.0;
    this->maxVisibleRange.y = 0.0;
    this->maxVisibleRange.z = 0.0;
    this->maxVisibleRange.w = 262144.0;
  }
  else
  {
    v4 = (float)(p_globalReferenceBounds->b[1].y + p_globalReferenceBounds->b[0].y);
    v5 = (float)(p_globalReferenceBounds->b[1].z + p_globalReferenceBounds->b[0].z);
    this->maxVisibleRange.x = (float)(p_globalReferenceBounds->b[1].x + p_globalReferenceBounds->b[0].x) * (float)0.5;
    this->maxVisibleRange.y = (float)v4 * (float)0.5;
    this->maxVisibleRange.z = (float)v5 * (float)0.5;
    this->maxVisibleRange.w = 0.0;
    _FP9 = (float)((float)0.0 - (float)(p_globalReferenceBounds->b[0].x - this->maxVisibleRange.x));
    y = this->maxVisibleRange.y;
    v8 = (float)(p_globalReferenceBounds->b[0].y - this->maxVisibleRange.y);
    z = this->globalReferenceBounds.b[1].z;
    v10 = this->maxVisibleRange.z;
    v11 = (float)(p_globalReferenceBounds->b[0].z - this->maxVisibleRange.z);
    __asm { fsel      f3, f9, f1, f10 }
    v13 = this->globalReferenceBounds.b[1].y;
    v14 = (float)(this->globalReferenceBounds.b[1].x - this->maxVisibleRange.x);
    this->maxVisibleRange.w = _FP3;
    v15 = (float)((float)z - (float)v10);
    _FP11 = (float)((float)_FP3 - (float)v8);
    __asm { fsel      f9, f11, f3, f7 }
    this->maxVisibleRange.w = _FP9;
    _FP8 = (float)((float)_FP9 - (float)v11);
    __asm { fsel      f7, f8, f9, f4 }
    this->maxVisibleRange.w = _FP7;
    _FP6 = (float)((float)_FP7 - (float)v14);
    __asm { fsel      f5, f6, f7, f1 }
    this->maxVisibleRange.w = _FP5;
    _FP4 = (float)((float)_FP5 - (float)((float)v13 - (float)y));
    __asm { fsel      f3, f4, f5, f12 }
    this->maxVisibleRange.w = _FP3;
    _FP2 = (float)((float)_FP3 - (float)v15);
    __asm { fsel      f1, f2, f3, f10 }
    this->maxVisibleRange.w = _FP1;
    this->maxVisibleRange.w = (float)_FP1 + this->r.maxVisibleRange;
  }
}


// ========================================================================
// ??0idRenderLightCommitted@@AAA@XZ
// EA  : 0x82943A00
// RVA : 0x00943A00
// PDB : w:\tech5\engine\renderer\renderlightcommitted.cpp
// ========================================================================

idRenderLightCommitted *__fastcall idRenderLightCommitted::idRenderLightCommitted(idRenderLightCommitted *this)
{
  bool *p_needsReferences; // r10
  idSysMutex *p_viewNoteMutex; // r11
  int i; // ctr

  this->world = nullptr;
  this->index.index = -1;
  idRenderLightParms::idRenderLightParms(this: &this->r);
  idStaticParmBlock<32>::idStaticParmBlock<32>(this: &this->renderParmBlock, threadId: THREAD_RENDERER);
  this->references.list = nullptr;
  this->references.granularity = 0;
  this->references.memTag = 62;
  this->references.listStatic = 0;
  this->references.size = 0;
  this->references.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->references);
  this->needsReferences = false;
  p_needsReferences = &this->needsReferences;
  p_viewNoteMutex = &analysisClient.viewNoteMutex;
  for ( i = 6; i != 0; --i )
  {
    ++p_viewNoteMutex;
    p_needsReferences += 4;
    *(idSysMutex *)p_needsReferences = (idSysMutex)p_viewNoteMutex->handle;
  }
  this->globalLightOrigin.x = 0.0;
  this->globalLightOrigin.y = 0.0;
  this->globalLightOrigin.z = 0.0;
  this->currentColor.x = 0.0;
  this->currentColor.y = 0.0;
  this->currentColor.z = 0.0;
  this->maxVisibleRange.x = 0.0;
  this->maxVisibleRange.y = 0.0;
  this->maxVisibleRange.z = 0.0;
  this->maxVisibleRange.w = 262144.0;
  this->lightMtr = nullptr;
  this->castsShadows = false;
  this->nextOnPostCommitList = this;
  memset(Dst: &this->baseLightProject, Val: 0, Size: sizeof(this->baseLightProject));
  memset(Dst: &this->inverseBaseLightProject, Val: 0, Size: sizeof(this->inverseBaseLightProject));
  return this;
}


// ========================================================================
// __unwind$230163
// EA  : 0x82943B18
// RVA : 0x00943B18
// PDB : w:\tech5\engine\renderer\renderlightcommitted.cpp
// ========================================================================

void _unwind_230163()
{
  int v0; // r12

  idStaticParmBlock<32>::~idStaticParmBlock<32>(this: (idStaticParmBlock<32> *)(*(_DWORD *)(v0 - 128 + 148) + 240));
}


// ========================================================================
// ??1idRenderLightCommitted@@AAA@XZ
// EA  : 0x82943B50
// RVA : 0x00943B50
// PDB : w:\tech5\engine\renderer\renderlightcommitted.cpp
// ========================================================================

void __fastcall idRenderLightCommitted::~idRenderLightCommitted(idRenderLightCommitted *this)
{
  if ( this->world != nullptr )
  {
    this->world->commitLights.ptr[this->index.index >> 8] = false;
    this->world->postCommitLights.ptr[this->index.index >> 8] = false;
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->references);
  idParmBlock::~idParmBlock(this: &this->renderParmBlock);
}


// ========================================================================
// __unwind$230216
// EA  : 0x82943BDC
// RVA : 0x00943BDC
// PDB : w:\tech5\engine\renderer\renderlightcommitted.cpp
// ========================================================================

void _unwind_230216()
{
  int v0; // r12

  idStaticParmBlock<32>::~idStaticParmBlock<32>(this: (idStaticParmBlock<32> *)(*(_DWORD *)(v0 - 112 + 132) + 240));
}


// ========================================================================
// ?FreeReferences@idRenderLightCommitted@@QAAXXZ
// EA  : 0x82943C08
// RVA : 0x00943C08
// PDB : w:\tech5\engine\renderer\renderlightcommitted.cpp
// ========================================================================

void __fastcall idRenderLightCommitted::FreeReferences(idRenderLightCommitted *this)
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
        this: (idList<idMapChangeListener *,5> *)&this->references.list[v4]->drawLightRefs,
        obj: (idMapChangeListener *const *)p_index);
      idList<void *,108>::RemoveFast(
        this: (idList<idMapChangeListener *,5> *)&this->references.list[v4]->approximatedLightRefs,
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
    *(idRenderLightCommitted **)((char *)this->world->linkedRenderLights.list + ((this->index.index >> 6) & 0x3FFFFFC)) = nullptr;
  }
}


// ========================================================================
// ?PostCommit@idRenderLightCommitted@@QAAXXZ
// EA  : 0x82943CD0
// RVA : 0x00943CD0
// PDB : w:\tech5\engine\renderer\renderlightcommitted.cpp
// ========================================================================

void __fastcall idRenderLightCommitted::PostCommit(idRenderLightCommitted *this)
{
  idRenderLightParms *p_r; // r30
  parmValue_t *v3; // r11
  parmValue_t *v4; // r10

  p_r = &this->r;
  idRenderLightParms::ComputeWorldToLightMatrix(
    this: &this->r,
    baseLightProject: &this->baseLightProject,
    inverseBaseLightProject: &this->inverseBaseLightProject);
  idRenderLightParms::ComputeLightGlobalOrigin(this: p_r, globalOrigin: &this->globalLightOrigin);
  idParmState::VirtualEvaluateParmBlock(
    this: renderThreadParmState,
    localParmBlock: &this->renderParmBlock,
    parmBlock: &this->renderParmBlock);
  idParmState::VirtualEvaluateParmBlock(
    this: renderThreadParmState,
    localParmBlock: &this->lightMtr->renderParmBlock,
    parmBlock: &this->lightMtr->renderParmBlock);
  v3 = &renderThreadParmState->values[rp->lightColor->parmIndex];
  v4 = &renderThreadParmState->values[rp->exposure->parmIndex];
  this->currentColor.x = v4->value[0] * v3->value[0];
  this->currentColor.y = v4->value[1] * v3->value[1];
  this->currentColor.z = v4->value[2] * v3->value[2];
  idParmState::VirtualRollbackParmBlock(
    this: renderThreadParmState,
    localParmBlock: &this->lightMtr->renderParmBlock,
    parmBlock: &this->lightMtr->renderParmBlock);
  idParmState::VirtualRollbackParmBlock(
    this: renderThreadParmState,
    localParmBlock: &this->renderParmBlock,
    parmBlock: &this->renderParmBlock);
  if ( this->needsReferences )
  {
    idRenderLightCommitted::FreeReferences(this);
    idRenderLightCommitted::CreateReferences(this);
  }
}

