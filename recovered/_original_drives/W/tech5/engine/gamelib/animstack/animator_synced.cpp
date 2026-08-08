
// ========================================================================
// ?InternalGetMergeBranch@idAnimator_TrackerBase@@MBAPBVidMD6Branch@@XZ
// EA  : 0x826EB678
// RVA : 0x006EB678
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

XGRAPHICS::_SC_STATE_CACHE *__fastcall idAnimator_TrackerBase::InternalGetMergeBranch(_DWORD *hSSMDev)
{
  return (XGRAPHICS::_SC_STATE_CACHE *)hSSMDev[25];
}


// ========================================================================
// ?InternalInit@idAnimator_Synced@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826EB680
// RVA : 0x006EB680
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

int __fastcall idAnimator_Synced::InternalInit(idAnimator_Synced *this, const idAnimatorParms_Base *parms)
{
  idMD6BlockAlloc *p_md6Allocator; // r31
  bool *p_initialized; // r29
  int i; // r30
  idMD6LeafPlay **v6; // r29
  int j; // r30

  p_md6Allocator = &parms->animStack->md6Allocator;
  this->mergeBranch = (idMD6Branch *)p_md6Allocator->Alloc(this: p_md6Allocator, a2: NODE_BRANCH);
  p_initialized = &this->initialized;
  for ( i = 8; i != 0; --i )
  {
    p_initialized += 4;
    *(_DWORD *)p_initialized = p_md6Allocator->Alloc(this: p_md6Allocator, a2: NODE_LEAF_PLAY);
  }
  v6 = &this->leaves[7];
  for ( j = 7; j != 0; --j )
    *++v6 = (idMD6LeafPlay *)p_md6Allocator->Alloc(this: p_md6Allocator, a2: NODE_BRANCH);
  return 1;
}


// ========================================================================
// ?InternalShutdown@idAnimator_Synced@@MAAXPAVidAnimStack@@@Z
// EA  : 0x826EB718
// RVA : 0x006EB718
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

void __fastcall idAnimator_Synced::InternalShutdown(idAnimator_Synced *this, idAnimStack *animStack)
{
  idMD6BlockAlloc *p_md6Allocator; // r30
  idMD6LeafPlay **leaves; // r31
  int i; // r28
  idMD6Branch **branches; // r31
  int j; // r29

  p_md6Allocator = &animStack->md6Allocator;
  if ( this->mergeBranch != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
    this->mergeBranch = nullptr;
  }
  leaves = this->leaves;
  for ( i = 8; i != 0; --i )
  {
    if ( *leaves != nullptr )
    {
      ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
      *leaves = nullptr;
    }
    ++leaves;
  }
  branches = this->branches;
  for ( j = 7; j != 0; --j )
  {
    if ( *branches != nullptr )
    {
      ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
      *branches = nullptr;
    }
    ++branches;
  }
}


// ========================================================================
// ?InternalIsContributing@idAnimator_Synced@@MBA_NXZ
// EA  : 0x826EB7D0
// RVA : 0x006EB7D0
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

unsigned int __fastcall idAnimator_Synced::InternalIsContributing(idAnimator_Synced *this)
{
  return (-this->anims.num & (unsigned int)~this->anims.num) >> 31;
}


// ========================================================================
// ??1idAnimator_Synced@@UAA@XZ
// EA  : 0x826EB7F0
// RVA : 0x006EB7F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

void __fastcall idAnimator_Synced::~idAnimator_Synced(idAnimator_Synced *this)
{
  this->__vftable = (idAnimator_Synced_vtbl *)&idAnimator_Synced::`vftable';
  this->mergeBranch = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->alphaValues);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->aliasWeights);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->aliasHandles);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->anims);
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// __unwind$247087
// EA  : 0x826EB864
// RVA : 0x006EB864
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

void _unwind_247087()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$247088
// EA  : 0x826EB88C
// RVA : 0x006EB88C
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

void _unwind_247088()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 104));
}


// ========================================================================
// __unwind$247089
// EA  : 0x826EB8B8
// RVA : 0x006EB8B8
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

void _unwind_247089()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 152));
}


// ========================================================================
// __unwind$247090
// EA  : 0x826EB8E4
// RVA : 0x006EB8E4
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

void _unwind_247090()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 184));
}


// ========================================================================
// ?SetAnimHandle@idAnimator_Synced@@QAAXPAVidTreeAnimator@@HHABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@@Z
// EA  : 0x826EB910
// RVA : 0x006EB910
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

void __fastcall idAnimator_Synced::SetAnimHandle(
        idAnimator_Synced *this,
        idTreeAnimator *animator,
        int curTime,
        const int index,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *ah)
{
  const idMD6Alias *Alias; // r3
  const idMD6Anim **list; // r8
  idMD6LeafPlay *v11; // r3

  this->aliasHandles.list[index] = (idHandle<unsigned short,enum invalidAliasHandle_t,65535>)ah->value;
  Alias = idDeclMD6::FindAlias(this: animator->decl, aliasHandle: ah, includeInherited: true);
  if ( Alias != nullptr )
  {
    this->anims.list[index] = (const idMD6Anim *)idResourceList::FindExisting(
                                                   this: &idMD6Anim::resourceList,
                                                   name: (char *)Alias->animRefs.list->str,
                                                   skipStaleCheck: true);
    list = this->anims.list;
    if ( list[index] != nullptr )
    {
      v11 = this->leaves[index];
      if ( list[index] != v11->anim )
        idMD6LeafPlay::Init(
          this: v11,
          anim: list[index],
          gameTime: curTime,
          ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
          frame: 0,
          rateScale: this->rateScale,
          wrapMode: (const idMD6Leaf::wrapMode_t)timeManager.gameHz,
          weightGroup: (const md6WeightGroup_t)this->wrapMode);
    }
  }
  else
  {
    idLib::Warning(fmt: "bad animation alias, %d", ah->value);
  }
}


// ========================================================================
// ?CalcAlphaValuesFromWeights@idAnimator_Synced@@IAAXXZ
// EA  : 0x826EBA00
// RVA : 0x006EBA00
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

void __fastcall idAnimator_Synced::CalcAlphaValuesFromWeights(idAnimator_Synced *this)
{
  int num; // r11
  idStaticList<float,8> *p_alphaValues; // r29
  int v4; // r31
  int size; // r11
  int v6; // r9
  double v7; // fp11
  int v8; // r11
  float *v9; // r10
  double v10; // fp0

  num = this->aliasWeights.num;
  p_alphaValues = &this->alphaValues;
  v4 = num - 1;
  if ( num - 1 <= this->alphaValues.size
    || (unsigned __int8)idList<float,116>::Resize(this: (idList<float,13> *)&this->alphaValues, newsize: num - 1) != 0 )
  {
    size = p_alphaValues->size;
    if ( v4 < size )
      size = v4;
    p_alphaValues->num = size;
  }
  v6 = 0;
  v7 = 0.0;
  if ( this->alphaValues.num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = &this->aliasWeights.list[v8];
      v7 = (float)(*v9 + (float)v7);
      if ( (float)(v9[1] + (float)v7) == 0.0 )
      {
        p_alphaValues->list[v8] = 0.0;
      }
      else
      {
        v10 = (float)(v9[1] / (float)(v9[1] + (float)v7));
        if ( v10 >= 0.0 )
        {
          if ( v10 > 1.0 )
            v10 = 1.0;
        }
        else
        {
          v10 = 0.0;
        }
        p_alphaValues->list[v8] = v10;
      }
      ++v6;
      ++v8;
    }
    while ( v6 < this->alphaValues.num );
  }
}


// ========================================================================
// ?IsDone@idAnimator_Synced@@QAA_NPBVidAnimStack@@H@Z
// EA  : 0x826EBAF0
// RVA : 0x006EBAF0
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

int __fastcall idAnimator_Synced::IsDone(idAnimator_Synced *this, const idAnimStack *stack, int curTime)
{
  int v5; // r29
  idMD6LeafPlay **i; // r31

  v5 = 0;
  if ( this->aliasHandles.num <= 0 )
    return 1;
  for ( i = this->leaves;
        !idMD6LeafPlay::IsPlaying(
           this: *i,
           gameTime: curTime,
           ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz);
        ++i )
  {
    if ( ++v5 >= this->aliasHandles.num )
      return 1;
  }
  return 0;
}


// ========================================================================
// ??0idAnimator_Synced@@QAA@XZ
// EA  : 0x826EBB70
// RVA : 0x006EBB70
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

idAnimator_Synced *__fastcall idAnimator_Synced::idAnimator_Synced(idAnimator_Synced *this)
{
  int v2; // ctr
  bool *p_initialized; // r11
  idMD6LeafPlay **v4; // r11
  int i; // ctr

  idAnimator_Base::idAnimator_Base(this);
  this->__vftable = (idAnimator_Synced_vtbl *)&idAnimator_Synced::`vftable';
  this->mergeBranch = nullptr;
  this->anims.list = this->anims.staticList;
  this->anims.num = 0;
  this->anims.granularity = 1;
  this->anims.listStatic = 1;
  this->anims.size = 8;
  this->anims.memTag = 5;
  this->aliasHandles.granularity = 1;
  this->aliasHandles.listStatic = 1;
  this->aliasHandles.size = 8;
  this->aliasHandles.num = 0;
  this->aliasHandles.list = this->aliasHandles.staticList;
  v2 = 8;
  this->aliasHandles.memTag = 5;
  this->aliasHandles.staticList[0].value = -1;
  this->aliasHandles.staticList[1].value = -1;
  this->aliasHandles.staticList[2].value = -1;
  this->aliasHandles.staticList[3].value = -1;
  this->aliasHandles.staticList[4].value = -1;
  this->aliasHandles.staticList[5].value = -1;
  this->aliasHandles.staticList[6].value = -1;
  this->aliasHandles.staticList[7].value = -1;
  p_initialized = &this->initialized;
  this->aliasWeights.granularity = 1;
  this->aliasWeights.listStatic = 1;
  this->aliasWeights.size = 8;
  this->aliasWeights.num = 0;
  this->aliasWeights.list = this->aliasWeights.staticList;
  this->aliasWeights.memTag = 5;
  this->alphaValues.granularity = 1;
  this->alphaValues.listStatic = 1;
  this->alphaValues.size = 8;
  this->alphaValues.num = 0;
  this->alphaValues.list = this->alphaValues.staticList;
  this->alphaValues.memTag = 5;
  this->rateScale = 1.0;
  this->wrapMode = WRAP_REPEAT;
  do
  {
    p_initialized += 4;
    *(_DWORD *)p_initialized = 0;
    --v2;
  }
  while ( v2 != 0 );
  v4 = &this->leaves[7];
  for ( i = 7; i != 0; --i )
    *++v4 = nullptr;
  memset(Dst: this->anims.list, Val: 0, Size: 4 * this->anims.size);
  memset(Dst: this->aliasWeights.list, Val: 0, Size: 4 * this->aliasWeights.size);
  memset(Dst: this->alphaValues.list, Val: 0, Size: 4 * this->alphaValues.size);
  return this;
}


// ========================================================================
// ?InternalEnd@idAnimator_Synced@@MAAXPBVidAnimStack@@HV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x826EBCD0
// RVA : 0x006EBCD0
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

void __fastcall idAnimator_Synced::InternalEnd(
        idAnimator_Synced *this,
        const idAnimStack *stack,
        const int curTime,
        const idTypesafeNumber<int,enum gameTimeUnique_t> *blendDurationTicks)
{
  idMD6Branch *mergeBranch; // r11

  if ( blendDurationTicks->value <= 0 )
  {
    mergeBranch = this->mergeBranch;
    if ( mergeBranch != nullptr )
    {
      mergeBranch->left = nullptr;
      this->mergeBranch->right = nullptr;
    }
    idList<idHandle<unsigned short,enum invalidJointHandle_t,65535>,5>::SetNum(this: &this->aliasHandles, newNum: 0);
    idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->anims, newNum: 0);
    idList<float,5>::SetNum(this: &this->aliasWeights, newNum: 0);
    idList<float,5>::SetNum(this: &this->alphaValues, newNum: 0);
  }
}


// ========================================================================
// ?SetAnimHandlesAndWeights@idAnimator_Synced@@QAAXPAVidTreeAnimator@@HPBV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@HPBMH@Z
// EA  : 0x826EBD58
// RVA : 0x006EBD58
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

void __fastcall idAnimator_Synced::SetAnimHandlesAndWeights(
        idAnimator_Synced *this,
        idTreeAnimator *animator,
        int curTime,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *handles,
        int numAnims,
        float *weights,
        int numWeights)
{
  idStaticList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,8> *p_aliasHandles; // r24
  int size; // r11
  int v16; // r11
  idStaticList<float,8> *p_aliasWeights; // r26
  int v18; // r11
  int v19; // r29
  int v20; // r30
  int v21; // r28

  p_aliasHandles = &this->aliasHandles;
  if ( numAnims <= this->aliasHandles.size
    || idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19>::Resize(
         this: &this->aliasHandles,
         newsize: numAnims) )
  {
    size = p_aliasHandles->size;
    if ( numAnims < size )
      size = numAnims;
    p_aliasHandles->num = size;
  }
  if ( numAnims <= this->anims.size
    || idList<idNavSpline *,5>::Resize(
         this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->anims,
         newsize: numAnims) )
  {
    v16 = this->anims.size;
    if ( numAnims < v16 )
      v16 = numAnims;
    this->anims.num = v16;
  }
  p_aliasWeights = &this->aliasWeights;
  if ( numWeights <= this->aliasWeights.size
    || (unsigned __int8)idList<float,116>::Resize(this: (idList<float,13> *)&this->aliasWeights, newsize: numWeights) != 0 )
  {
    v18 = this->aliasWeights.size;
    if ( numWeights < v18 )
      v18 = numWeights;
    this->aliasWeights.num = v18;
  }
  if ( numAnims == 1 )
  {
    p_aliasHandles->list->value = handles->value;
    idAnimator_Synced::SetAnimHandle(this, animator, curTime, index: 0, ah: handles);
    *p_aliasWeights->list = *weights;
  }
  else if ( numAnims != 0 )
  {
    if ( numAnims > 0 )
    {
      v19 = 0;
      v20 = 0;
      v21 = 0;
      do
      {
        p_aliasHandles->list[v21] = (idHandle<unsigned short,enum invalidAliasHandle_t,65535>)handles->value;
        idAnimator_Synced::SetAnimHandle(this, animator, curTime, index: v19++, ah: handles);
        ++v21;
        ++handles;
        p_aliasWeights->list[v20] = weights[v20];
        ++v20;
      }
      while ( v19 < numAnims );
    }
    idAnimator_Synced::CalcAlphaValuesFromWeights(this);
  }
  else
  {
    idList<float,5>::SetNum(this: &this->aliasWeights, newNum: 0);
    idList<float,5>::SetNum(this: &this->alphaValues, newNum: 0);
  }
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_Synced@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826EBF18
// RVA : 0x006EBF18
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

void __fastcall idAnimator_Synced::InternalPreBlendTree(
        idAnimator_Synced *this,
        const idAnimStack *stack,
        int curTime,
        const int ticksPerSec)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int num; // r11
  idMD6Node *v9; // r24
  int v10; // r21
  int v11; // r25
  int v12; // r26
  idMD6LeafPlay **leaves; // r20
  const idMD6Anim **list; // r11
  idMD6LeafPlay *v15; // r28
  idMD6Branch *v16; // r27
  float *v17; // r29
  idMD6Branch::blendType_t v18; // r9
  md6WeightGroup_t v19; // r8
  idPLog *pLog; // r29
  idPLog::logEntry_t *v21; // r30
  int v22; // r3
  __int64 totalTicks; // r11
  __int64 v24; // r9
  idPLogScope v25[2]; // [sp+68h] [-88h] BYREF

  RD_EventBegin(name: "idAnimator_Synced::InternalPreBlendTree");
  LODWORD(v6) = "idAnimator_Synced::InternalPreBlendTree";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: v25, pl: &::pLog, gMask: v6, label: v7);
  if ( this->mergeBranch != nullptr )
  {
    this->mergeBranch->left = nullptr;
    this->mergeBranch->right = nullptr;
    if ( this->mergeBranch->targetAlpha == 0.0 && idMD6Branch::IsBlendFinished(this: this->mergeBranch) )
    {
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->aliasHandles);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->anims);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->aliasWeights);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->alphaValues);
      idPLogScope::~idPLogScope(this: v25);
    }
    else
    {
      v9 = nullptr;
      v10 = 0;
      num = this->anims.num;
      if ( num > 0 )
      {
        v11 = 0;
        v12 = 0;
        leaves = this->leaves;
        do
        {
          list = this->anims.list;
          v15 = leaves[v12];
          if ( v15->anim != list[v12] )
            idMD6LeafPlay::Init(
              this: leaves[v12],
              anim: list[v12],
              gameTime: curTime,
              ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
              frame: 0,
              rateScale: this->rateScale,
              wrapMode: (const idMD6Leaf::wrapMode_t)timeManager.gameHz,
              weightGroup: (const md6WeightGroup_t)this->wrapMode);
          if ( v9 != nullptr )
          {
            if ( v10 - 1 >= 0 )
            {
              v16 = (idMD6Branch *)leaves[v12 + 7];
              v17 = &this->alphaValues.list[v11];
              idAnimator_Base::GetFilterGroup(this);
              idMD6Branch::Init(
                this: v16,
                left: v9,
                right: v15,
                op: BOP_LERP,
                originBlend: ORIGINBLEND_BRANCH,
                startAlpha: *v17,
                targetAlpha: *v17,
                alphaRate: 0.0,
                filterGroup: v19,
                blendType: v18);
              v9 = v16;
              ++v11;
            }
          }
          else
          {
            v9 = v15;
          }
          ++v10;
          ++v12;
          num = this->anims.num;
        }
        while ( v10 < num );
      }
      if ( num > 0 )
        this->mergeBranch->right = v9;
      if ( v25[0].logIndex >= 0 )
      {
        pLog = v25[0].pLog;
        v21 = &v25[0].pLog->logEntries.list[v25[0].logIndex];
        v22 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        totalTicks = v21->totalTicks;
        HIDWORD(totalTicks) = v21->parent;
        LODWORD(v24) = v22 - totalTicks;
        v21->totalTicks = v24;
        pLog->lastEntry = HIDWORD(totalTicks);
      }
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: v25);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$248072_0
// EA  : 0x826EC12C
// RVA : 0x006EC12C
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

void _unwind_248072_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$248073
// EA  : 0x826EC154
// RVA : 0x006EC154
// PDB : w:\tech5\engine\gamelib\animstack\animator_synced.cpp
// ========================================================================

void _unwind_248073()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 104));
}

