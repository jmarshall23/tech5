
// ========================================================================
// ?FindRibbonEffect@idRibbonModelManager@@AAAHPBVidDeclRibbon@@@Z
// EA  : 0x827176D8
// RVA : 0x007176D8
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.cpp
// ========================================================================

int __fastcall idRibbonModelManager::FindRibbonEffect(idRibbonModelManager *this, const idDeclRibbon *ribbonDecl)
{
  int num; // r9
  int result; // r3
  idRibbonModelManager::ribbonEffects_t *list; // r8
  int i; // r10
  idRibbon *v7; // r11

  num = this->ribbonEffects.num;
  result = 0;
  if ( num <= 0 )
    return -1;
  list = this->ribbonEffects.list;
  for ( i = 0; ; ++i )
  {
    if ( list[i].ribbons.num > 0 )
    {
      v7 = *list[i].ribbons.list;
      if ( v7 != nullptr && v7->ribbonDecl == ribbonDecl )
        break;
    }
    if ( ++result >= num )
      return -1;
  }
  return result;
}


// ========================================================================
// ?StopRibbon@idRibbonManager@@QAAXXZ
// EA  : 0x82717738
// RVA : 0x00717738
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.cpp
// ========================================================================

void __fastcall idRibbonManager::StopRibbon(idRibbonManager *this)
{
  if ( this->ribbon != nullptr )
    this->ribbon->ribbonState = RIBBON_DEACTIVATING;
}


// ========================================================================
// ?UpdateRibbon@idRibbonManager@@QAA_NHABVidVec3@@ABVidMat3@@0ABVidVec4@@0@Z
// EA  : 0x82717750
// RVA : 0x00717750
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.cpp
// ========================================================================

__int32 __fastcall idRibbonManager::UpdateRibbon(
        idRibbonManager *this,
        int time,
        const idVec3 *org,
        const idMat3 *axis,
        const idVec3 *vel,
        const idVec4 *color,
        const idVec3 *translate)
{
  idRibbon *ribbon; // r3
  int v15; // r10
  const idVec3 *v16; // r9
  long double v17; // fp2
  __int64 v18; // r8
  int v19; // r10
  int v20; // r9
  const idVec4 *v22; // [sp+8h] [-88h]
  int v23; // [sp+8h] [-88h]
  int v24; // [sp+Ch] [-84h]
  int v25; // [sp+10h] [-80h]
  int v26; // [sp+14h] [-7Ch]
  int v27; // [sp+18h] [-78h]
  int v28; // [sp+1Ch] [-74h]
  int v29; // [sp+20h] [-70h]
  int v30; // [sp+24h] [-6Ch]
  int v31; // [sp+28h] [-68h]
  const idMat3 *v32; // [sp+2Ch] [-64h]

  ribbon = this->ribbon;
  if ( ribbon == nullptr )
    return 0;
  idRibbon::RemoveOldNodes(this: ribbon, currentTime: time);
  idRibbon::UpdatePosition(
    this: this->ribbon,
    currentTime: time,
    origin: org,
    velocity: __SPAIR64__((unsigned int)vel, (unsigned int)color),
    color: v16,
    a6: v17,
    a7: v15,
    a8: v22);
  HIDWORD(v18) = translate;
  idRibbon::UpdateGeometry(
    this: this->ribbon,
    currentTime: time,
    beamModel: this->beamModel,
    axis,
    translate: v18,
    a6: v20,
    a7: v19,
    a8: v23,
    a9: v24,
    a10: v25,
    a11: v26,
    a12: v27,
    a13: v28,
    a14: v29,
    a15: v30,
    a16: v31,
    a17: v32);
  return this->ribbon->ribbonState
       - 2
       - (this->ribbon->ribbonState
        - 3
        + (this->ribbon->ribbonState == RIBBON_INACTIVE));
}


// ========================================================================
// ?GetNextRibbonEffectModel@idRibbonModelManager@@QAAPAVidRibbon@@PBVidDeclRibbon@@@Z
// EA  : 0x827177E8
// RVA : 0x007177E8
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.cpp
// ========================================================================

idRibbon *__fastcall idRibbonModelManager::GetNextRibbonEffectModel(
        idRibbonModelManager *this,
        const idDeclRibbon *ribbonDecl)
{
  _DWORD *v2; // r6
  int v3; // r4
  int RibbonEffect; // r3
  idRibbon *result; // r3
  int v6; // r10
  _DWORD *v7; // r11
  int v8; // r9
  int v9; // r11

  RibbonEffect = idRibbonModelManager::FindRibbonEffect(this, ribbonDecl);
  if ( RibbonEffect == -1 )
  {
    idLib::Warning(
      fmt: "idRibbonModelManager::GetNextRibbonEffectModel: Ribbon '%s' not in list",
      *(const char **)(v3 + 8));
    return nullptr;
  }
  else
  {
    v6 = 84 * RibbonEffect;
    v7 = (_DWORD *)(84 * RibbonEffect + *v2);
    v8 = v7[20];
    result = *(idRibbon **)(4 * v8 + *v7);
    v7[20] = v8 + 1;
    v9 = v6 + *v2;
    if ( v8 + 1 >= *(_DWORD *)(v9 + 4) )
      *(_DWORD *)(v9 + 80) = 0;
  }
  return result;
}


// ========================================================================
// ?Shutdown@idRibbonManager@@QAAXXZ
// EA  : 0x82717880
// RVA : 0x00717880
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.cpp
// ========================================================================

void __fastcall idRibbonManager::Shutdown(idRibbonManager *this)
{
  if ( this->ribbon != nullptr )
    this->ribbon->ribbonState = RIBBON_DEACTIVATING;
  this->ribbon = nullptr;
  this->isInitialized = false;
}


// ========================================================================
// ?StartRibbon@idRibbonManager@@QAAXHABVidVec3@@@Z
// EA  : 0x827178A8
// RVA : 0x007178A8
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.cpp
// ========================================================================

void __fastcall idRibbonManager::StartRibbon(idRibbonManager *this, int spawnTime, const idVec3 *spawnOrg)
{
  const idDeclRibbon *ribbonDecl; // r4
  idRibbonModelManager *modelManager; // r3
  idRibbon *NextRibbonEffectModel; // r3

  ribbonDecl = this->ribbonDecl;
  if ( ribbonDecl != nullptr )
  {
    modelManager = this->modelManager;
    if ( modelManager != nullptr )
    {
      NextRibbonEffectModel = idRibbonModelManager::GetNextRibbonEffectModel(this: modelManager, ribbonDecl);
      this->ribbon = NextRibbonEffectModel;
      if ( NextRibbonEffectModel != nullptr )
        idRibbon::StartRibbon(this: NextRibbonEffectModel, spawnTime_: spawnTime, spawnOrg_: spawnOrg);
    }
  }
}


// ========================================================================
// ??1idRibbonManager@@QAA@XZ
// EA  : 0x827179B8
// RVA : 0x007179B8
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.cpp
// ========================================================================

void __fastcall idRibbonManager::~idRibbonManager(idRibbonManager *this)
{
  if ( this->ribbon != nullptr )
    this->ribbon->ribbonState = RIBBON_DEACTIVATING;
  this->isInitialized = false;
  this->ribbon = nullptr;
  this->ribbonDecl = nullptr;
  this->beamModel = nullptr;
  this->modelManager = nullptr;
}


// ========================================================================
// ?Shutdown@idRibbonModelManager@@QAAXXZ
// EA  : 0x82717A50
// RVA : 0x00717A50
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.cpp
// ========================================================================

void __fastcall idRibbonModelManager::Shutdown(idRibbonModelManager *this)
{
  int v2; // r29
  int v3; // r30

  v2 = 0;
  if ( this->ribbonEffects.num > 0 )
  {
    v3 = 0;
    do
    {
      idList<idRibbon *,5>::DeleteContents(this: &this->ribbonEffects.list[v3].ribbons);
      ++v2;
      ++v3;
    }
    while ( v2 < this->ribbonEffects.num );
  }
  if ( this->ribbonEffects.listStatic == 0 || this->ribbonEffects.listStatic == 2 )
  {
    if ( this->ribbonEffects.list != nullptr )
      idListArrayDelete<idRibbonModelManager::ribbonEffects_t>(
        ptr: (char *)this->ribbonEffects.list,
        num: this->ribbonEffects.size);
    this->ribbonEffects.list = nullptr;
    this->ribbonEffects.size = 0;
  }
  this->ribbonEffects.num = 0;
}


// ========================================================================
// ??1idRibbonModelManager@@QAA@XZ
// EA  : 0x82717C60
// RVA : 0x00717C60
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.cpp
// ========================================================================

void __fastcall idRibbonModelManager::~idRibbonModelManager(idRibbonModelManager *this)
{
  idRibbonModelManager::Shutdown(this);
  idStaticList<idRibbonModelManager::ribbonEffects_t,4>::~idStaticList<idRibbonModelManager::ribbonEffects_t,4>(this: &this->ribbonEffects);
}


// ========================================================================
// __unwind$246800
// EA  : 0x82717CA4
// RVA : 0x00717CA4
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.cpp
// ========================================================================

void _unwind_246800()
{
  int v0; // r12

  idStaticList<idRibbonModelManager::ribbonEffects_t,4>::~idStaticList<idRibbonModelManager::ribbonEffects_t,4>(this: *(idStaticList<idRibbonModelManager::ribbonEffects_t,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idRibbonModelManager@@QAA@XZ
// EA  : 0x82717E58
// RVA : 0x00717E58
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.cpp
// ========================================================================

idRibbonModelManager *__fastcall idRibbonModelManager::idRibbonModelManager(idRibbonModelManager *this)
{
  idStaticList<idRibbonModelManager::ribbonEffects_t,4>::idStaticList<idRibbonModelManager::ribbonEffects_t,4>(this: &this->ribbonEffects);
  return this;
}


// ========================================================================
// ?CreateRibbonEffectModelType@idRibbonModelManager@@QAAXPBVidDeclRibbon@@@Z
// EA  : 0x82717F08
// RVA : 0x00717F08
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.cpp
// ========================================================================

void __fastcall idRibbonModelManager::CreateRibbonEffectModelType(
        idRibbonModelManager *this,
        const idDeclRibbon *ribbonDecl)
{
  int RibbonEffect; // r30
  int v5; // r4
  int v6; // r28
  idRibbonModelManager::ribbonEffects_t *v7; // r10
  int size; // r11
  int v9; // r27
  idRibbon *v10; // r3
  idDeclAF_Constraint *v11; // r30

  RibbonEffect = idRibbonModelManager::FindRibbonEffect(this, ribbonDecl);
  if ( RibbonEffect == -1 )
  {
    RibbonEffect = this->ribbonEffects.num;
    if ( RibbonEffect >= this->ribbonEffects.size )
    {
      idLib::Warning(
        fmt: "idRibbonModelManager::CreateRibbonEffectModelType: No more free effect spots, could not add '%s'",
        *(const char **)(v5 + 8));
      return;
    }
    idList<idRibbonModelManager::ribbonEffects_t,5>::Alloc(this: &this->ribbonEffects);
  }
  v6 = RibbonEffect;
  v7 = &this->ribbonEffects.list[RibbonEffect];
  size = v7->ribbons.size;
  if ( v7->ribbons.num < size )
  {
    v9 = 0;
    if ( size > 0 )
    {
      do
      {
        v10 = (idRibbon *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x2454u,
                            tag: TAG_PARTICLE,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
        if ( v10 != nullptr )
          v11 = (idDeclAF_Constraint *)idRibbon::idRibbon(this: v10, decl: ribbonDecl);
        else
          v11 = nullptr;
        if ( v11 != nullptr )
          *idList<unsigned char *,5>::Alloc(this: (idList<idDeclAF_Constraint *,71> *)&this->ribbonEffects.list[v6]) = v11;
        ++v9;
      }
      while ( v9 < this->ribbonEffects.list[v6].ribbons.size );
    }
  }
}


// ========================================================================
// __unwind$246863_0
// EA  : 0x82718018
// RVA : 0x00718018
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.cpp
// ========================================================================

void _unwind_246863_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_PARTICLE);
}


// ========================================================================
// ?Init@idRibbonManager@@QAAXPBVidDeclRibbon@@PAVidRenderModelBeam@@PAVidRibbonModelManager@@@Z
// EA  : 0x82718048
// RVA : 0x00718048
// PDB : w:\tech5\engine\gamelib\effects\ribbonmanager.cpp
// ========================================================================

void __fastcall idRibbonManager::Init(
        idRibbonManager *this,
        const idDeclRibbon *_ribbonDecl,
        idRenderModelBeam *_beamModel,
        idRibbonModelManager *_modelManager)
{
  if ( _ribbonDecl != nullptr && _beamModel != nullptr && _modelManager != nullptr )
  {
    this->ribbonDecl = _ribbonDecl;
    this->beamModel = _beamModel;
    this->modelManager = _modelManager;
    idRibbonModelManager::CreateRibbonEffectModelType(this: _modelManager, ribbonDecl: _ribbonDecl);
    this->isInitialized = true;
  }
}

