
// ========================================================================
// ?InternalIsContributing@idAnimator_EndAdditiveChannels@@MBA_NXZ
// EA  : 0x826E12E0
// RVA : 0x006E12E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_endadditivechannels.cpp
// ========================================================================

unsigned int __fastcall idAnimator_EndAdditiveChannels::InternalIsContributing(idAnimator_EndAdditiveChannels *this)
{
  return (-this->numAddedChannels & (unsigned int)~this->numAddedChannels) >> 31;
}


// ========================================================================
// ?SetAnimHandlesAndWeights@idAnimator_EndAdditiveChannels@@QAAXPAVidTreeAnimator@@HPBV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@HPBMH@Z
// EA  : 0x826E12F8
// RVA : 0x006E12F8
// PDB : w:\tech5\engine\gamelib\animstack\animator_endadditivechannels.cpp
// ========================================================================

void __fastcall idAnimator_EndAdditiveChannels::SetAnimHandlesAndWeights(
        idAnimator_EndAdditiveChannels *this,
        idTreeAnimator *animator,
        const int curTime,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *handles,
        int numAnims,
        const float *weights,
        const int numWeights)
{
  int v7; // r4
  int v8; // r27
  int v9; // r5
  int v10; // r9
  const float *v11; // r10
  const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v12; // r11
  int v13; // r24
  int v14; // r10
  int v15; // r11
  int v16; // ctr

  this->numCurrentChannels = numAnims;
  v7 = 0;
  if ( numAnims >= 4 )
  {
    v8 = -4 - (_DWORD)handles;
    v9 = 2;
    v10 = 2;
    v11 = weights + 2;
    v12 = handles + 2;
    v13 = -8 - (_DWORD)weights;
    do
    {
      v7 += 4;
      *(idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)((char *)this->animAlias.list + (unsigned int)v12
                                                                                                 + v8) = v12[-2];
      *(float *)((char *)v11 + v13 + (unsigned int)this->aliasWeights.list) = *(v11 - 2);
      *(idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)((char *)this->animAlias.list
                                                                  + (unsigned int)v12
                                                                  + v8
                                                                  + 2) = v12[-1];
      *(float *)((char *)v11 + v13 + (unsigned int)this->aliasWeights.list + 4) = *(v11 - 1);
      this->animAlias.list[v10] = (idHandle<unsigned short,enum invalidAliasHandle_t,65535>)v12->value;
      this->aliasWeights.list[v9] = *v11;
      v10 += 4;
      *(idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)((char *)this->animAlias.list
                                                                  + 2
                                                                  - (_DWORD)handles
                                                                  + (unsigned int)v12) = v12[1];
      *(float *)((char *)v11 + 4 - (_DWORD)weights + (unsigned int)this->aliasWeights.list) = v11[1];
      v9 += 4;
      v12 += 4;
      v11 += 4;
    }
    while ( v7 < numAnims - 3 );
  }
  if ( v7 < numAnims )
  {
    v14 = v7;
    v15 = v7;
    v16 = numAnims - v7;
    do
    {
      this->animAlias.list[v15] = handles[v15];
      this->aliasWeights.list[v14] = weights[v14];
      ++v15;
      ++v14;
      --v16;
    }
    while ( v16 != 0 );
  }
}


// ========================================================================
// ?InternalGetMergeBranch@idAnimator_EndAdditiveChannels@@MAAPAVidMD6Branch@@XZ
// EA  : 0x826E1408
// RVA : 0x006E1408
// PDB : w:\tech5\engine\gamelib\animstack\animator_endadditivechannels.cpp
// ========================================================================

const idMD6Branch *__fastcall idAnimator_EndAdditiveChannels::InternalGetMergeBranch(
        idAnimator_EndAdditiveChannels *this)
{
  if ( this->numAddedChannels == 1 )
    return this->branches.list;
  else
    return &this->mergeBranch;
}


// ========================================================================
// ?InternalGetEndBranch@idAnimator_EndAdditiveChannels@@MBAPBVidMD6Branch@@XZ
// EA  : 0x826E1428
// RVA : 0x006E1428
// PDB : w:\tech5\engine\gamelib\animstack\animator_endadditivechannels.cpp
// ========================================================================

const idMD6Branch *__fastcall idAnimator_EndAdditiveChannels::InternalGetEndBranch(
        idAnimator_EndAdditiveChannels *this)
{
  int numAddedChannels; // r11

  numAddedChannels = this->numAddedChannels;
  if ( numAddedChannels <= 1 )
    return nullptr;
  else
    return &this->branches.list[numAddedChannels - 1];
}


// ========================================================================
// ??0idAnimator_EndAdditiveChannels@@QAA@XZ
// EA  : 0x826E1460
// RVA : 0x006E1460
// PDB : w:\tech5\engine\gamelib\animstack\animator_endadditivechannels.cpp
// ========================================================================

idAnimator_EndAdditiveChannels *__fastcall idAnimator_EndAdditiveChannels::idAnimator_EndAdditiveChannels(
        idAnimator_EndAdditiveChannels *this)
{
  idAnimator_Base::idAnimator_Base(this);
  this->__vftable = (idAnimator_EndAdditiveChannels_vtbl *)&idAnimator_EndAdditiveChannels::`vftable';
  this->leaves.list = nullptr;
  this->leaves.granularity = 0;
  this->leaves.memTag = 5;
  this->leaves.listStatic = 0;
  this->leaves.size = 0;
  this->leaves.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->leaves);
  this->branches.list = nullptr;
  this->branches.granularity = 0;
  this->branches.memTag = 5;
  this->branches.listStatic = 0;
  this->branches.size = 0;
  this->branches.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->branches);
  this->aliasWeights.list = nullptr;
  this->aliasWeights.granularity = 0;
  this->aliasWeights.memTag = 5;
  this->aliasWeights.listStatic = 0;
  this->aliasWeights.size = 0;
  this->aliasWeights.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->aliasWeights);
  this->mergeBranch.type = 0;
  this->mergeBranch.left = nullptr;
  this->mergeBranch.right = nullptr;
  this->mergeBranch.leftTimeOverride = -1;
  this->mergeBranch.rightTimeOverride = -1;
  this->mergeBranch.currentAlpha = 0.0;
  this->mergeBranch.filterGroup = 8;
  this->mergeBranch.targetAlpha = 0.0;
  this->mergeBranch.op = 10;
  this->mergeBranch.alphaRate = 0.0;
  this->mergeBranch.originBlend = 0;
  this->mergeBranch.blendType = BLEND_LINEAR;
  this->animAlias.list = nullptr;
  this->animAlias.granularity = 0;
  this->animAlias.memTag = 5;
  this->animAlias.listStatic = 0;
  this->animAlias.size = 0;
  this->animAlias.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animAlias);
  this->currentExternalAlpha = 0.0;
  this->numAddedChannels = 0;
  this->targetExternalAlpha = 0.0;
  this->numCurrentChannels = 0;
  this->externalAlphaRate = 0.0;
  this->wrapMode = WRAP_REPEAT;
  return this;
}


// ========================================================================
// __unwind$246683
// EA  : 0x826E158C
// RVA : 0x006E158C
// PDB : w:\tech5\engine\gamelib\animstack\animator_endadditivechannels.cpp
// ========================================================================

void _unwind_246683()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$246684
// EA  : 0x826E15B4
// RVA : 0x006E15B4
// PDB : w:\tech5\engine\gamelib\animstack\animator_endadditivechannels.cpp
// ========================================================================

void _unwind_246684()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 40));
}


// ========================================================================
// __unwind$246685
// EA  : 0x826E15E0
// RVA : 0x006E15E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_endadditivechannels.cpp
// ========================================================================

void _unwind_246685()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 56));
}


// ========================================================================
// __unwind$246686
// EA  : 0x826E160C
// RVA : 0x006E160C
// PDB : w:\tech5\engine\gamelib\animstack\animator_endadditivechannels.cpp
// ========================================================================

void _unwind_246686()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 72));
}


// ========================================================================
// ?SetExternalBlend@idAnimator_EndAdditiveChannels@@QAAXMH@Z
// EA  : 0x826E1750
// RVA : 0x006E1750
// PDB : w:\tech5\engine\gamelib\animstack\animator_endadditivechannels.cpp
// ========================================================================

void __fastcall idAnimator_EndAdditiveChannels::SetExternalBlend(
        idAnimator_EndAdditiveChannels *this,
        double blendTarget,
        const int blendMS,
        unsigned int a4,
        __int64 a5)
{
  this->targetExternalAlpha = blendTarget;
  LODWORD(a5) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
  this->externalAlphaRate = (float)a5
                          / (float)__SPAIR64__(
                                     &idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor',
                                     a4);
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_EndAdditiveChannels@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826E17A0
// RVA : 0x006E17A0
// PDB : w:\tech5\engine\gamelib\animstack\animator_endadditivechannels.cpp
// ========================================================================

void __fastcall idAnimator_EndAdditiveChannels::InternalPreBlendTree(
        idAnimator_EndAdditiveChannels *this,
        const idAnimStack *stack,
        int curTime,
        const int ticksPerSec)
{
  idGameTimeManager *gameTimeManager; // r3
  idMD6Branch *v8; // r25
  __int64 v9; // r9
  __int64 v10; // r7
  int PreviousGameMs; // r3
  double targetExternalAlpha; // fp0
  double v13; // fp11
  double v14; // fp13
  int numCurrentChannels; // r11
  float *list; // r10
  int v17; // r23
  int v18; // r26
  int v19; // r27
  float *v20; // r22
  double v21; // fp31
  idMD6Blend::blendOp_t v22; // r28
  idMD6LeafPlay *v23; // r29
  const idMD6Alias *Alias; // r3
  idMD6Leaf::wrapMode_t v25; // r8
  const idMD6Anim *Existing; // r3
  int numAddedChannels; // r11
  idMD6Branch *v28; // r9
  idMD6Branch *v29; // r30
  idMD6Branch *v30; // r11

  gameTimeManager = this->gametimeManager.gameTimeManager;
  this->mergeBranch.left = nullptr;
  v8 = nullptr;
  this->mergeBranch.right = nullptr;
  PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: gameTimeManager, type: GAMETIME_SCALED);
  if ( curTime - PreviousGameMs > 0 )
  {
    LODWORD(v9) = curTime - PreviousGameMs;
    targetExternalAlpha = this->targetExternalAlpha;
    LODWORD(v10) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    v13 = (float)(this->targetExternalAlpha - this->currentExternalAlpha);
    if ( v13 <= 0.0 )
    {
      if ( v13 >= 0.0 )
        goto LABEL_9;
      v14 = (float)-(float)((float)(this->externalAlphaRate * (float)((float)v9 / (float)v10))
                          - this->currentExternalAlpha);
      if ( v14 < (float)(this->targetExternalAlpha + (float)0.000001) )
        goto LABEL_8;
    }
    else
    {
      v14 = (float)((float)(this->externalAlphaRate * (float)((float)v9 / (float)v10)) + this->currentExternalAlpha);
      if ( v14 > (float)(this->targetExternalAlpha - (float)0.000001) )
      {
LABEL_8:
        this->currentExternalAlpha = targetExternalAlpha;
        goto LABEL_9;
      }
    }
    targetExternalAlpha = v14;
    goto LABEL_8;
  }
LABEL_9:
  numCurrentChannels = this->numCurrentChannels;
  list = this->aliasWeights.list;
  this->numAddedChannels = 0;
  if ( numCurrentChannels > 0 )
  {
    v17 = numCurrentChannels;
    v18 = 0;
    v19 = 0;
    v20 = list;
    do
    {
      v21 = *v20;
      if ( v21 > 0.00000011920929 )
      {
        v22 = BOP_ADD_RIGHT;
        v23 = &this->leaves.list[v19];
        if ( v21 < 0.0 )
        {
          v21 = -v21;
          v22 = BOP_SUB_RIGHT;
        }
        Alias = idDeclMD6::FindAlias(
                  this: stack->treeAnimator->decl,
                  aliasHandle: &this->animAlias.list[v18],
                  includeInherited: true);
        if ( Alias != nullptr )
        {
          Existing = (const idMD6Anim *)idResourceList::FindExisting(
                                          this: &idMD6Anim::resourceList,
                                          name: (char *)Alias->animRefs.list->str,
                                          skipStaleCheck: true);
          if ( Existing != nullptr )
          {
            if ( v23->anim != Existing )
              idMD6LeafPlay::Init(
                this: v23,
                anim: Existing,
                gameTime: curTime,
                ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
                frame: 0,
                rateScale: 1.0,
                wrapMode: v25,
                weightGroup: (const md6WeightGroup_t)this->wrapMode);
            numAddedChannels = this->numAddedChannels;
            v28 = this->branches.list;
            this->numAddedChannels = numAddedChannels + 1;
            v29 = &v28[numAddedChannels];
            if ( v8 != nullptr )
              v8->left = v29;
            idMD6Branch::Init(
              this: v29,
              left: nullptr,
              right: v23,
              op: v22,
              originBlend: ORIGINBLEND_BRANCH,
              startAlpha: v21,
              targetAlpha: v21,
              alphaRate: 0.0,
              filterGroup: (const md6WeightGroup_t)(numAddedChannels + 1),
              blendType: (const idMD6Branch::blendType_t)v28);
            v8 = v29;
          }
        }
      }
      --v17;
      ++v20;
      ++v19;
      ++v18;
    }
    while ( v17 != 0 );
  }
  if ( this->numAddedChannels > 1 )
  {
    v30 = this->branches.list;
    this->mergeBranch.targetAlpha = 1.0;
    this->mergeBranch.currentAlpha = 1.0;
    this->mergeBranch.right = v30;
  }
}


// ========================================================================
// ?InternalInit@idAnimator_EndAdditiveChannels@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826E1C60
// RVA : 0x006E1C60
// PDB : w:\tech5\engine\gamelib\animstack\animator_endadditivechannels.cpp
// ========================================================================

int __fastcall idAnimator_EndAdditiveChannels::InternalInit(
        idAnimator_EndAdditiveChannels *this,
        const idAnimatorParms_Base *parms)
{
  idAnimStack *animStack; // r31
  idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,5> *p_animAlias; // r30
  idAnimStack *size; // r11
  idAnimStack *v7; // r31
  int v8; // r11
  idAnimStack *v9; // r31
  int v10; // r11
  idAnimStack *v11; // r31
  int v12; // r11

  animStack = parms[1].animStack;
  p_animAlias = &this->animAlias;
  if ( (int)animStack <= this->animAlias.size
    || idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19>::Resize(
         this: &this->animAlias,
         newsize: (int)parms[1].animStack) )
  {
    size = (idAnimStack *)p_animAlias->size;
    if ( (int)animStack < (int)size )
      size = animStack;
    p_animAlias->num = (int)size;
  }
  v7 = parms[1].animStack;
  if ( (int)v7 <= this->leaves.size
    || (unsigned __int8)idList<idMD6LeafPlay,5>::Resize(this: &this->leaves, newsize: (int)parms[1].animStack) != 0 )
  {
    v8 = this->leaves.size;
    if ( (int)v7 < v8 )
      v8 = (int)v7;
    this->leaves.num = v8;
  }
  v9 = parms[1].animStack;
  if ( (int)v9 <= this->branches.size
    || (unsigned __int8)idList<idMD6Branch,30>::Resize(this: &this->branches, newsize: (int)parms[1].animStack) != 0 )
  {
    v10 = this->branches.size;
    if ( (int)v9 < v10 )
      v10 = (int)v9;
    this->branches.num = v10;
  }
  v11 = parms[1].animStack;
  if ( (int)v11 <= this->aliasWeights.size
    || (unsigned __int8)idList<float,116>::Resize(
                          this: (idList<float,13> *)&this->aliasWeights,
                          newsize: (int)parms[1].animStack) != 0 )
  {
    v12 = this->aliasWeights.size;
    if ( (int)v11 < v12 )
      v12 = (int)v11;
    this->aliasWeights.num = v12;
  }
  return 1;
}

