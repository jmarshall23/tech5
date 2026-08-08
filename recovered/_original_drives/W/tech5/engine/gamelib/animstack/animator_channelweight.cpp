
// ========================================================================
// ?GetNumContacts@idPhysics_DynamicBase@@UBAHXZ
// EA  : 0x826DFA08
// RVA : 0x006DFA08
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

const idMD6Branch *__fastcall idPhysics_DynamicBase::GetNumContacts(idAnimator_ChannelWeight *this)
{
  return this->mergeBranch;
}


// ========================================================================
// ?InternalShutdown@idAnimator_ChannelWeight@@MAAXPAVidAnimStack@@@Z
// EA  : 0x826DFA10
// RVA : 0x006DFA10
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

void __fastcall idAnimator_ChannelWeight::InternalShutdown(idAnimator_ChannelWeight *this, idAnimStack *stack)
{
  idMD6BlockAlloc *p_md6Allocator; // r30
  int v4; // r27
  int num; // r26
  idAnimator_ChannelWeight::leafAnimation_t *v6; // r31
  unsigned __int16 *list; // r4
  idAnimator_ChannelWeight::leafAnimation_t *v8; // r4

  p_md6Allocator = &stack->md6Allocator;
  if ( this->mergeBranch != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
    this->mergeBranch = nullptr;
  }
  if ( this->baseAnimation.leaf != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
    this->baseAnimation.leaf = nullptr;
  }
  if ( this->leaves.num > 0 )
  {
    v4 = 0;
    num = this->leaves.num;
    do
    {
      v6 = &this->leaves.list[v4];
      if ( v6->leaf != nullptr )
      {
        ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
        v6->leaf = nullptr;
      }
      if ( v6->branch != nullptr )
      {
        ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
        v6->branch = nullptr;
      }
      --num;
      ++v4;
    }
    while ( num != 0 );
  }
  if ( this->userChannelToLeafMap.listStatic == 0 || this->userChannelToLeafMap.listStatic == 2 )
  {
    list = this->userChannelToLeafMap.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->userChannelToLeafMap.list = nullptr;
    this->userChannelToLeafMap.size = 0;
  }
  this->userChannelToLeafMap.num = 0;
  if ( this->leaves.listStatic == 0 || this->leaves.listStatic == 2 )
  {
    v8 = this->leaves.list;
    if ( v8 != nullptr )
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    this->leaves.list = nullptr;
    this->leaves.size = 0;
  }
  this->leaves.num = 0;
}


// ========================================================================
// ?InternalIsContributing@idAnimator_ChannelWeight@@MBA_NXZ
// EA  : 0x826DFB60
// RVA : 0x006DFB60
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

int __fastcall idAnimator_ChannelWeight::InternalIsContributing(idAnimator_ChannelWeight *this)
{
  char v1; // r11
  unsigned __int8 v2; // r11
  bool v3; // zf

  if ( this->controlAnimation == nullptr )
    return 0;
  if ( this->baseAnimation.animation == nullptr
    || this->leaves.num <= 0
    || (v1 = 1, this->userChannelToLeafMap.num <= 0) )
  {
    v1 = 0;
  }
  v3 = v1 != 0;
  v2 = 1;
  if ( !v3 )
    return 0;
  return v2;
}


// ========================================================================
// ??0idAnimator_ChannelWeight@@QAA@XZ
// EA  : 0x826DFC30
// RVA : 0x006DFC30
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

idAnimator_ChannelWeight *__fastcall idAnimator_ChannelWeight::idAnimator_ChannelWeight(idAnimator_ChannelWeight *this)
{
  idAnimator_Base::idAnimator_Base(this);
  this->__vftable = (idAnimator_ChannelWeight_vtbl *)&idAnimator_ChannelWeight::`vftable';
  this->userChannelToLeafMap.list = nullptr;
  this->userChannelToLeafMap.granularity = 0;
  this->userChannelToLeafMap.memTag = 5;
  this->userChannelToLeafMap.listStatic = 0;
  this->userChannelToLeafMap.size = 0;
  this->userChannelToLeafMap.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->userChannelToLeafMap);
  this->leaves.list = nullptr;
  this->leaves.granularity = 0;
  this->leaves.memTag = 5;
  this->leaves.listStatic = 0;
  this->leaves.size = 0;
  this->leaves.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->leaves);
  this->baseAnimation.animation = nullptr;
  this->baseAnimation.leaf = nullptr;
  this->mergeBranch = nullptr;
  this->controlAnimation = nullptr;
  this->filterGroup = MD6_WEIGHTGROUP_ALL;
  this->entityNumber = 0x1FFF;
  this->lockOwner = nullptr;
  return this;
}


// ========================================================================
// __unwind$247230
// EA  : 0x826DFCD4
// RVA : 0x006DFCD4
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

void _unwind_247230()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$247231
// EA  : 0x826DFCFC
// RVA : 0x006DFCFC
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

void _unwind_247231()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 40));
}


// ========================================================================
// ??1idAnimator_ChannelWeight@@UAA@XZ
// EA  : 0x826DFD30
// RVA : 0x006DFD30
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

void __fastcall idAnimator_ChannelWeight::~idAnimator_ChannelWeight(idAnimator_ChannelWeight *this)
{
  this->__vftable = (idAnimator_ChannelWeight_vtbl *)&idAnimator_ChannelWeight::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->leaves);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->userChannelToLeafMap);
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// __unwind$247302_0
// EA  : 0x826DFD8C
// RVA : 0x006DFD8C
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

void _unwind_247302_0()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$247303_0
// EA  : 0x826DFDB4
// RVA : 0x006DFDB4
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

void _unwind_247303_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// ?SetControlAnimation@idAnimator_ChannelWeight@@QAAXPBVidMD6LeafPlay@@PAX@Z
// EA  : 0x826DFDE0
// RVA : 0x006DFDE0
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

void __fastcall idAnimator_ChannelWeight::SetControlAnimation(
        idAnimator_ChannelWeight *this,
        const idMD6LeafPlay *animation,
        void *lockOwner_)
{
  void *lockOwner; // r11
  char v7; // r11
  bool v8; // zf
  const idMD6Anim *anim; // r11
  idMD6AnimData *animData; // r3
  int v11; // r3

  lockOwner = this->lockOwner;
  if ( lockOwner == nullptr || (v8 = lockOwner != lockOwner_, v7 = 0, !v8) )
    v7 = 1;
  if ( v7 != 0 )
  {
    if ( animation != nullptr )
      anim = animation->anim;
    else
      anim = nullptr;
    if ( anim != nullptr && (animData = anim->animData) != nullptr )
      v11 = idMD6AnimData::NumCompressedUserChannels(this: animData, animMapIndex: 0);
    else
      v11 = 0;
    if ( v11 <= 0 || v11 > this->leaves.num )
    {
      this->controlAnimation = nullptr;
      this->lockOwner = nullptr;
    }
    else
    {
      this->mergeBranch->currentAlpha = 1.0;
      this->mergeBranch->targetAlpha = 1.0;
      this->controlAnimation = animation;
      this->lockOwner = animation == nullptr ? nullptr : lockOwner_;
    }
  }
}


// ========================================================================
// ?InternalInit@idAnimator_ChannelWeight@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826DFF18
// RVA : 0x006DFF18
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

int __fastcall idAnimator_ChannelWeight::InternalInit(
        idAnimator_ChannelWeight *this,
        const idAnimatorParms_Base *parms)
{
  idMD6BlockAlloc *p_md6Allocator; // r18
  idMD6Branch *v5; // r3
  idMD6LeafPause *v7; // r3
  int v8; // r27
  const idDeclMD6 *decl; // r30
  int num; // r29
  idMD6SkelData *data; // r5
  int numUserChannels; // r25
  int i; // r28
  const idMD6Anim *v14; // r29
  unsigned __int16 *v15; // r3
  const idMD6Anim *v16; // r3
  idMD6Leaf::wrapMode_t v17; // r5
  int v18; // r19
  int v19; // r29
  int v20; // r24
  idMD6LeafPause *leaf; // r25
  int v22; // r26
  idMD6LeafPause *v23; // r27
  idMD6Branch *v24; // r28
  __int64 v25; // r10
  __int64 v26; // r8
  idAnimator_ChannelWeight::leafAnimation_t *v27; // r30
  idMD6Leaf::wrapMode_t v28; // r5
  idMD6Branch::blendType_t v29; // r9
  md6WeightGroup_t v30; // r8
  int v31; // [sp+8h] [-10F8h]
  int v32; // [sp+Ch] [-10F4h]
  int v33; // [sp+10h] [-10F0h]
  int v34; // [sp+14h] [-10ECh]
  int v35; // [sp+18h] [-10E8h]
  int v36; // [sp+1Ch] [-10E4h]
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v37; // [sp+60h] [-10A0h] BYREF
  va v38; // [sp+70h] [-1090h] BYREF

  p_md6Allocator = &parms->animStack->md6Allocator;
  v5 = (idMD6Branch *)p_md6Allocator->Alloc(this: p_md6Allocator, a2: NODE_BRANCH);
  this->mergeBranch = v5;
  if ( v5 == nullptr )
    return 0;
  v7 = (idMD6LeafPause *)p_md6Allocator->Alloc(this: p_md6Allocator, a2: NODE_LEAF_PAUSE);
  this->baseAnimation.leaf = v7;
  if ( v7 == nullptr )
    return 0;
  v8 = 0;
  decl = parms->animStack->treeAnimator->decl;
  this->filterGroup = parms->filterGroup;
  num = decl->userChannelToAnimationAliasMap.num;
  data = decl->model->skeleton->data;
  numUserChannels = data->numUserChannels;
  if ( numUserChannels > this->userChannelToLeafMap.size )
    idList<unsigned short,30>::Resize(this: &this->userChannelToLeafMap, newsize: data->numUserChannels);
  if ( num > this->leaves.size )
    idList<idSoundSystemLocal::bufferContext_t,5>::Resize(this: &this->leaves, newsize: num);
  for ( i = 0; i < numUserChannels; ++i )
  {
    v37.value = decl->userChannelToAnimationAliasMap.list[(__int16)i].value;
    v14 = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &v37, load: true);
    v15 = idList<unsigned short,5>::Alloc(this: &this->userChannelToLeafMap);
    if ( v14 != nullptr )
    {
      *v15 = v8++;
      idList<idAnimator_ChannelWeight::leafAnimation_t,5>::Alloc(this: &this->leaves)->animation = v14;
    }
    else
    {
      *v15 = -1;
    }
  }
  this->mergeBranch->op = 4;
  this->mergeBranch->filterGroup = this->filterGroup;
  this->mergeBranch->currentAlpha = 0.0;
  this->mergeBranch->targetAlpha = 0.0;
  v16 = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &decl->baseUserChannelAlias, load: true);
  this->baseAnimation.animation = v16;
  idMD6LeafPause::Init(
    this: this->baseAnimation.leaf,
    anim: v16,
    frame: 0.0,
    wrapMode: v17,
    weightGroup: MD6_WEIGHTGROUP_ALL);
  v18 = 1;
  v19 = 0;
  v20 = this->leaves.num;
  leaf = this->baseAnimation.leaf;
  if ( v20 > 0 )
  {
    v22 = 0;
    while ( 1 )
    {
      v23 = (idMD6LeafPause *)p_md6Allocator->Alloc(this: p_md6Allocator, a2: NODE_LEAF_PAUSE);
      if ( v23 == nullptr )
        break;
      v24 = (idMD6Branch *)p_md6Allocator->Alloc(this: p_md6Allocator, a2: NODE_BRANCH);
      if ( v24 == nullptr )
        break;
      va::va(
        this: &v38,
        fmt: "%s_b%d",
        a3: __SPAIR64__("<unknown>", v19),
        a4: v26,
        a5: v25,
        a6: v31,
        a7: v32,
        a8: v33,
        a9: v34,
        a10: v35,
        a11: v36);
      v27 = &this->leaves.list[v22];
      idMD6LeafPause::Init(this: v23, anim: v27->animation, frame: 0.0, wrapMode: v28, weightGroup: MD6_WEIGHTGROUP_ALL);
      idMD6Branch::Init(
        this: v24,
        left: leaf,
        right: v23,
        op: BOP_ADD_RIGHT,
        originBlend: ORIGINBLEND_BRANCH,
        startAlpha: 0.0,
        targetAlpha: 0.0,
        alphaRate: 0.0,
        filterGroup: v30,
        blendType: v29);
      ++v19;
      v27->leaf = v23;
      leaf = (idMD6LeafPause *)v24;
      v27->branch = v24;
      ++v22;
      if ( v19 >= v20 )
        goto LABEL_20;
    }
    v18 = 0;
  }
LABEL_20:
  this->mergeBranch->right = leaf;
  if ( (_BYTE)v18 == 0 )
    this->InternalShutdown(this, a2: parms->animStack);
  return v18;
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_ChannelWeight@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826E0210
// RVA : 0x006E0210
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

void __fastcall idAnimator_ChannelWeight::InternalPreBlendTree(
        idAnimator_ChannelWeight *this,
        const idAnimStack *stack,
        const int curTime,
        const int ticksPerSec)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  const idMD6Model *model; // r28
  unsigned int v10; // r27
  idGameTimeManager *gameTimeManager; // r3
  int v12; // r12
  float *v13; // r29
  int GameMsPerFrame; // r3
  idMD6LeafPlay *controlAnimation; // r4
  int v16; // r26
  int wrapMode; // r25
  __int64 v18; // r11
  double v19; // fp30
  __int64 v20; // r8
  __int64 v21; // r5
  int v22; // r26
  const idMD6Anim *anim; // r6
  idMD6AnimData *animData; // r11
  double v25; // fp31
  __int64 v26; // r6
  __int64 v27; // r10
  __int64 v28; // r8
  unsigned __int8 v29; // r11
  int v30; // r27
  va *v31; // r3
  int num; // r28
  int v33; // r11
  double v34; // fp1
  __int64 v35; // r10
  va *v36; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v38; // r30
  int v39; // r3
  __int64 totalTicks; // r11
  __int64 v41; // r9
  _DWORD back_chain[2]; // [sp+0h] [-10F0h]
  int v43; // [sp+8h] [-10E8h]
  int v44; // [sp+Ch] [-10E4h]
  int v45; // [sp+10h] [-10E0h]
  int v46; // [sp+14h] [-10DCh]
  int v47; // [sp+18h] [-10D8h]
  int v48; // [sp+1Ch] [-10D4h]
  double v49; // [sp+20h] [-10D0h]
  double v50; // [sp+28h] [-10C8h]
  __int64 v51; // [sp+50h] [-10A0h] BYREF
  idPLogScope v52; // [sp+58h] [-1098h] BYREF
  idMD6LeafPlay v53; // [sp+60h] [-1090h] BYREF
  int v54; // [sp+78h] [-1078h]
  _BYTE v55[20]; // [sp+7Ch] [-1074h] BYREF
  va v56; // [sp+90h] [-1060h] BYREF

  RD_EventBegin(name: "idAnimator_ChannelWeight::InternalPreBlendTree");
  LODWORD(v7) = "idAnimator_ChannelWeight::InternalPreBlendTree";
  HIDWORD(v7) = 2;
  idPLogScope::idPLogScope(this: &v52, pl: &::pLog, gMask: v7, label: v8);
  if ( idAnimator_Base::IsContributing(this) )
  {
    model = stack->treeAnimator->decl->model;
    v10 = (4 * (model->skeleton->data->numUserChannels + 7)) & 0x3FFE0;
    ((void (*)(void))RtlCheckStack12)();
    gameTimeManager = this->gametimeManager.gameTimeManager;
    *(_DWORD *)((char *)back_chain + v12) = back_chain[0];
    v13 = (float *)&v51;
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: gameTimeManager, type: GAMETIME_SCALED);
    controlAnimation = (idMD6LeafPlay *)this->controlAnimation;
    v16 = curTime - GameMsPerFrame;
    wrapMode = controlAnimation->wrapMode;
    idMD6LeafPlay::GetAnimTicks(
      this: (idMD6LeafPlay *)&v53.anim,
      result: (idTypesafeNumber<int,enum gameTimeUnique_t> *)controlAnimation,
      ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz);
    idMD6LeafPlay::GetFrameTicks(
      this: &v53,
      result: (idTypesafeNumber<int,enum gameTimeUnique_t> *)this->controlAnimation,
      gameTime: v16);
    HIDWORD(v18) = *(_DWORD *)&v53.type;
    v19 = 1.0;
    if ( wrapMode != 0 || *(int *)&v53.type < (int)v53.anim )
    {
      LODWORD(v20) = v53.anim;
      HIDWORD(v20) = *(_DWORD *)&v53.type / (int)v53.anim * (int)v53.anim;
      LODWORD(v21) = *(_DWORD *)&v53.type % (int)v53.anim;
      HIDWORD(v18) = __ROL4__(*(_DWORD *)&v53.type, 1);
      HIDWORD(v21) = HIDWORD(v18) - 1;
      v51 = v21;
      __twllei((unsigned int)v53.anim, 0);
      __twlgei((int)v53.anim & ~(HIDWORD(v18) - 1), 0xFFFFFFFF);
      v19 = (float)((float)v21 / (float)v20);
    }
    v22 = 0;
    anim = this->controlAnimation->anim;
    animData = anim->animData;
    HIDWORD(v51) = anim;
    if ( animData != nullptr )
      LODWORD(v18) = animData->numFrames;
    else
      LODWORD(v18) = 0;
    LODWORD(v18) = v18 - 1;
    v51 = v18;
    v25 = (float)((float)v18 * (float)v19);
    idMD6Model::GetUserChannelsForAnimFrame(
      this: model,
      userChannels: (float *)&v51,
      userChannelsSize: v10,
      anim,
      frame: v25);
    LODWORD(v27) = 20;
    v53.rateScale = 0.0;
    HIDWORD(v27) = v55;
    v55[0] = 0;
    v54 = 20;
    *(_DWORD *)&v53.syncGroup = v55;
    LODWORD(v28) = &r_cuttablemodel_freecpudata.description;
    HIDWORD(v28) = &debug_channelWeight;
    if ( debug_channelWeight.valueInteger == -1
      || (LODWORD(v27) = this->entityNumber, v29 = 1, debug_channelWeight.valueInteger != (_DWORD)v27) )
    {
      v29 = 0;
    }
    v30 = v29;
    if ( v29 != 0 )
    {
      v49 = v19;
      v50 = v25;
      v31 = va::va(
              this: &v56,
              fmt: (const char *)HIDWORD(v19),
              a3: *(__int64 *)&v25,
              a4: v28,
              a5: v27,
              a6: v43,
              a7: v44,
              a8: v45,
              a9: v46,
              a10: v47,
              a11: v48,
              v19,
              v25);
      idStr::operator=(this: (idStr *)&v53.rateScale, text: v31);
    }
    if ( this->userChannelToLeafMap.num > 0 )
    {
      num = this->userChannelToLeafMap.num;
      do
      {
        v33 = this->userChannelToLeafMap.list[v22];
        if ( v33 != 0xFFFF )
        {
          HIDWORD(v35) = this->leaves.list;
          v34 = *v13;
          LODWORD(v35) = *(_DWORD *)(12 * v33 + HIDWORD(v35) + 8);
          *(float *)(v35 + 24) = *v13;
          *(float *)(v35 + 28) = v34;
          HIDWORD(v51) = v35;
          if ( v30 != 0 )
          {
            v49 = v34;
            HIDWORD(v26) = LODWORD(v34);
            v36 = va::va(
                    this: &v56,
                    fmt: "%.3f ",
                    a3: v26,
                    a4: v28,
                    a5: v35,
                    a6: v43,
                    a7: v44,
                    a8: v45,
                    a9: v46,
                    a10: v47,
                    a11: v48);
            idStr::Append(this: (idStr *)&v53.rateScale, text: v36);
          }
        }
        --num;
        ++v22;
        ++v13;
      }
      while ( num != 0 );
    }
    if ( v30 != 0 )
    {
      idStr::Append(this: (idStr *)&v53.rateScale, text: ")\n");
      idLib::Printf(fmt: *(const char **)&v53.syncGroup);
    }
    idStr::FreeData(this: (idStr *)&v53.rateScale);
    if ( v52.logIndex >= 0 )
    {
      pLog = v52.pLog;
      v38 = &v52.pLog->logEntries.list[v52.logIndex];
      v39 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v38->totalTicks;
      HIDWORD(totalTicks) = v38->parent;
      LODWORD(v41) = v39 - totalTicks;
      v38->totalTicks = v41;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v52);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$247605
// EA  : 0x826E0554
// RVA : 0x006E0554
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

void _unwind_247605()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4336 + 4240));
}


// ========================================================================
// __unwind$247606
// EA  : 0x826E057C
// RVA : 0x006E057C
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

void _unwind_247606()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4336 + 88));
}


// ========================================================================
// __unwind$247607
// EA  : 0x826E05A4
// RVA : 0x006E05A4
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

void _unwind_247607()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 112));
}


// ========================================================================
// `dynamic initializer for 'debug_channelWeight''
// EA  : 0x8333EF80
// RVA : 0x0133EF80
// PDB : w:\tech5\engine\gamelib\animstack\animator_channelweight.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__debug_channelWeight__()
{
  idCVar::idCVar(
    this: &debug_channelWeight,
    name: "debug_channelWeight",
    value: "-1",
    flags: 2,
    description: "enable Animator_ChannelWeight debug info for the specified entity number",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__debug_channelWeight__);
}

