
// ========================================================================
// ??1idAnimator_Channel@@UAA@XZ
// EA  : 0x826DE740
// RVA : 0x006DE740
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

void __fastcall idAnimator_Channel::~idAnimator_Channel(idAnimator_Channel *this)
{
  this->mergeBranch = nullptr;
  this->__vftable = (idAnimator_Channel_vtbl *)&idAnimator_Channel::`vftable';
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// ?InternalGetMergeBranch@idAnimator_Channel@@MBAPBVidMD6Branch@@XZ
// EA  : 0x826DE758
// RVA : 0x006DE758
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

const char *__fastcall idAnimator_Channel::InternalGetMergeBranch(idDeclEntityDef *this)
{
  return this->className.str;
}


// ========================================================================
// ??0idAnimator_Channel@@QAA@XZ
// EA  : 0x826DE7B8
// RVA : 0x006DE7B8
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

idAnimator_Channel *__fastcall idAnimator_Channel::idAnimator_Channel(idAnimator_Channel *this)
{
  char v3; // r8

  idAnimator_Base::idAnimator_Base(this);
  this->mergeBranch = nullptr;
  this->__vftable = (idAnimator_Channel_vtbl *)&idAnimator_Channel::`vftable';
  this->random.seed = 0;
  v3 = *((_BYTE *)this + 94);
  this->numFreeLeaves = 0;
  this->numFreeBranches = 0;
  this->blendOutDurationMS = 0;
  *((_BYTE *)this + 94) = v3 & 0x3F;
  this->leaves[0] = nullptr;
  this->leaves[1] = nullptr;
  this->leaves[2] = nullptr;
  this->branches[0] = nullptr;
  this->branches[1] = nullptr;
  this->freeLeaves[0] = nullptr;
  this->freeLeaves[1] = nullptr;
  this->freeLeaves[2] = nullptr;
  this->freeBranches[0] = nullptr;
  this->freeBranches[1] = nullptr;
  this->random.seed = 0;
  return this;
}


// ========================================================================
// ?InternalInit@idAnimator_Channel@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826DE8B8
// RVA : 0x006DE8B8
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

int __fastcall idAnimator_Channel::InternalInit(idAnimator_Channel *this, const idAnimatorParms_Base *parms)
{
  idMD6BlockAlloc *p_md6Allocator; // r30
  bool *p_initialized; // r28
  int i; // r29
  idMD6LeafPlay *v6; // r3
  idMD6LeafPlay **v7; // r28
  int j; // r29
  idMD6Branch *v9; // r3

  p_md6Allocator = &parms->animStack->md6Allocator;
  this->mergeBranch = (idMD6Branch *)p_md6Allocator->Alloc(this: p_md6Allocator, a2: NODE_BRANCH);
  p_initialized = &this->initialized;
  for ( i = 3; i != 0; --i )
  {
    v6 = (idMD6LeafPlay *)p_md6Allocator->Alloc(this: p_md6Allocator, a2: NODE_LEAF_PLAY);
    p_initialized += 4;
    *(_DWORD *)p_initialized = v6;
    this->freeLeaves[this->numFreeLeaves++] = v6;
  }
  v7 = &this->leaves[2];
  for ( j = 2; j != 0; --j )
  {
    v9 = (idMD6Branch *)p_md6Allocator->Alloc(this: p_md6Allocator, a2: NODE_BRANCH);
    *++v7 = (idMD6LeafPlay *)v9;
    this->freeBranches[this->numFreeBranches++] = v9;
  }
  this->mergeBranch->left = nullptr;
  this->mergeBranch->right = nullptr;
  return 1;
}


// ========================================================================
// ?InternalShutdown@idAnimator_Channel@@MAAXPAVidAnimStack@@@Z
// EA  : 0x826DE9B8
// RVA : 0x006DE9B8
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

void __fastcall idAnimator_Channel::InternalShutdown(idAnimator_Channel *this, idAnimStack *animStack)
{
  idMD6BlockAlloc *p_md6Allocator; // r30
  idMD6LeafPlay **leaves; // r31
  int i; // r29
  idMD6Branch **branches; // r31
  int j; // r29

  p_md6Allocator = &animStack->md6Allocator;
  if ( this->mergeBranch != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
    this->mergeBranch = nullptr;
  }
  leaves = this->leaves;
  for ( i = 3; i != 0; --i )
  {
    if ( *leaves != nullptr )
    {
      ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
      *leaves = nullptr;
    }
    ++leaves;
  }
  branches = this->branches;
  for ( j = 2; j != 0; --j )
  {
    if ( *branches != nullptr )
    {
      ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
      *branches = nullptr;
    }
    ++branches;
  }
  this->numFreeLeaves = 0;
  this->numFreeBranches = 0;
}


// ========================================================================
// ?ClearAnimator@idAnimator_Channel@@QAAXXZ
// EA  : 0x826DEA78
// RVA : 0x006DEA78
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

void __fastcall idAnimator_Channel::ClearAnimator(idAnimator_Channel *this)
{
  idAnimator_Channel_vtbl *v1; // r10
  int v2; // [sp+50h] [-10h] BYREF

  v1 = this->__vftable;
  v2 = 0;
  v1->InternalEnd(this, a2: nullptr, a3: 0, a4: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&v2);
}


// ========================================================================
// ?ForceFreeLeaf@idAnimator_Channel@@AAAXXZ
// EA  : 0x826DEAB8
// RVA : 0x006DEAB8
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

void __fastcall idAnimator_Channel::ForceFreeLeaf(idAnimator_Channel *this)
{
  idMD6Branch *mergeBranch; // r9
  idMD6Branch *v2; // r7
  idMD6LeafPlay *right; // r8
  int type; // r10
  char v5; // r11
  int v6; // r4

  if ( this->numFreeLeaves <= 0 )
  {
    mergeBranch = this->mergeBranch;
    v2 = nullptr;
    if ( mergeBranch != nullptr )
    {
      right = (idMD6LeafPlay *)mergeBranch->right;
      if ( right != nullptr )
      {
        while ( 1 )
        {
          type = right->type;
          if ( type == 1 || (v5 = 0, type == 2) )
            v5 = 1;
          if ( v5 != 0 )
            break;
          if ( right->type == 0 || type == 3 || type == 4 || type == 5 )
            v5 = 1;
          if ( v5 != 0 )
          {
            v2 = mergeBranch;
            mergeBranch = (idMD6Branch *)right;
          }
          right = (idMD6LeafPlay *)mergeBranch->right;
          if ( right == nullptr )
            return;
        }
        if ( v2 != nullptr )
          v2->right = mergeBranch->left;
        this->freeLeaves[this->numFreeLeaves] = right;
        v6 = this->numFreeBranches + 19;
        ++this->numFreeLeaves;
        *((_DWORD *)&this->__vftable + v6) = mergeBranch;
        ++this->numFreeBranches;
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "%s: No need to free a leaf.", "idAnimator_Channel::ForceFreeLeaf");
  }
}


// ========================================================================
// ?FreeTree@idAnimator_Channel@@AAAXPAVidMD6Node@@@Z
// EA  : 0x826DEBC0
// RVA : 0x006DEBC0
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

void __fastcall idAnimator_Channel::FreeTree(idAnimator_Channel *this, idMD6Branch *node)
{
  int type; // r11
  char v5; // r11
  bool v6; // zf

  if ( node != nullptr )
  {
    type = node->type;
    if ( node->type == 0 || type == 3 || type == 4 || (v6 = type != 5, v5 = 0, !v6) )
      v5 = 1;
    if ( v5 != 0 )
    {
      idAnimator_Channel::FreeTree(this, node: node->left);
      idAnimator_Channel::FreeTree(this, node: node->right);
      this->freeBranches[this->numFreeBranches++] = node;
    }
    else
    {
      this->freeLeaves[this->numFreeLeaves++] = (idMD6LeafPlay *)node;
    }
  }
}


// ========================================================================
// ?GetLastPlayedLeaf@idAnimator_Channel@@QAAPAVidMD6LeafPlay@@XZ
// EA  : 0x826DEC90
// RVA : 0x006DEC90
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

idMD6LeafPlay *__fastcall idAnimator_Channel::GetLastPlayedLeaf(idAnimator_Channel *this)
{
  idMD6Branch *mergeBranch; // r11
  idMD6LeafPlay *result; // r3
  int type; // r11
  char v4; // r11
  bool v5; // zf
  const idMD6Anim *anim; // r11

  mergeBranch = this->mergeBranch;
  if ( mergeBranch != nullptr )
  {
    result = (idMD6LeafPlay *)mergeBranch->right;
    if ( result != nullptr )
    {
      type = result->type;
      if ( type == 2 )
        return result;
      if ( result->type == 0 || type == 3 || type == 4 || (v5 = type != 5, v4 = 0, !v5) )
        v4 = 1;
      if ( v4 != 0 )
      {
        anim = result->anim;
        if ( anim != nullptr )
          return HIBYTE(anim->__vftable) != 2 ? nullptr : (idMD6LeafPlay *)anim;
      }
    }
  }
  return nullptr;
}


// ========================================================================
// ?InternalEnd@idAnimator_Channel@@MAAXPBVidAnimStack@@HV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x826DED18
// RVA : 0x006DED18
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

void __fastcall idAnimator_Channel::InternalEnd(
        idAnimator_Channel *this,
        const idAnimStack *stack,
        const int curTime,
        const idTypesafeNumber<int,enum gameTimeUnique_t> *blendDurationTicks)
{
  idMD6Branch *mergeBranch; // r11
  idAnimator_Channel *v5; // r8
  idMD6Branch *right; // r4

  mergeBranch = this->mergeBranch;
  v5 = this;
  if ( mergeBranch != nullptr && blendDurationTicks->value <= 0 )
  {
    right = (idMD6Branch *)mergeBranch->right;
    if ( right != nullptr )
      idAnimator_Channel::FreeTree(this, node: right);
    v5->mergeBranch->left = nullptr;
    v5->mergeBranch->right = nullptr;
  }
}


// ========================================================================
// ?IsDone@idAnimator_Channel@@QBA_NPBVidAnimStack@@H@Z
// EA  : 0x826DED78
// RVA : 0x006DED78
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

BOOL __fastcall idAnimator_Channel::IsDone(idAnimator_Channel *this, const idAnimStack *stack, int curTime)
{
  idMD6Branch *mergeBranch; // r11
  idMD6Node *right; // r3
  idMD6LeafPlay *v7; // r3

  mergeBranch = this->mergeBranch;
  if ( mergeBranch == nullptr )
    return true;
  right = mergeBranch->right;
  if ( right == nullptr || !idMD6Node::IsValid(this: right) )
    return true;
  v7 = (idMD6LeafPlay *)this->mergeBranch->right;
  return v7->type == 2
      && (_cntlzw(
            idMD6LeafPlay::IsPlaying(
              this: v7,
              gameTime: curTime,
              ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz))
        & 0x20) != 0;
}


// ========================================================================
// ?IsDone@idAnimator_Channel@@QBA_NPBVidAnimStack@@H_N@Z
// EA  : 0x826DEE20
// RVA : 0x006DEE20
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

BOOL __fastcall idAnimator_Channel::IsDone(
        idAnimator_Channel *this,
        const idAnimStack *stack,
        int curTime,
        bool clampIgnoreExtraFrame)
{
  idMD6Branch *mergeBranch; // r11
  idMD6Node *right; // r3
  idMD6LeafPlay *v9; // r3

  mergeBranch = this->mergeBranch;
  if ( mergeBranch == nullptr )
    return true;
  right = mergeBranch->right;
  if ( right == nullptr || !idMD6Node::IsValid(this: right) )
    return true;
  v9 = (idMD6LeafPlay *)this->mergeBranch->right;
  return v9->type == 2
      && (_cntlzw(
            idMD6LeafPlay::IsPlaying(
              this: v9,
              gameTime: curTime,
              ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
              clampIgnoreExtraFrame))
        & 0x20) != 0;
}


// ========================================================================
// ?StartNode@idAnimator_Channel@@AAA_NPAVidTreeAnimator@@PAVidMD6Node@@HW4blendOp_t@idMD6Blend@@W4wrapMode_t@idMD6Leaf@@ABVblendParms_t@@H@Z
// EA  : 0x826DEEC0
// RVA : 0x006DEEC0
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idAnimator_Channel::StartNode(
        idAnimator_Channel *this,
        idTreeAnimator *animator,
        idMD6Node *node,
        const int curTime,
        __int64 wrap,
        blendParms_t *blendParms,
        const int blendOutDurationMS_)
{
  char v9; // r25
  int v10; // r21
  __int16 DurationMS; // r3
  idMD6Branch *mergeBranch; // r11
  __int16 v16; // r24
  __int64 v17; // r5
  __int64 v18; // r8 OVERLAPPED
  bool v19; // r23
  int numFreeBranches; // r11
  __int64 v21; // r10
  int v22; // r31
  __int64 v23; // r6
  char FilterGroup; // r3
  __int64 v25; // r11
  __int16 v26; // r9
  int v27; // [sp+8h] [-10C8h]
  int v28; // [sp+Ch] [-10C4h]
  int v29; // [sp+10h] [-10C0h]
  int v30; // [sp+14h] [-10BCh]
  int v31; // [sp+18h] [-10B8h]
  int v32; // [sp+1Ch] [-10B4h]
  va v33; // [sp+60h] [-1070h] BYREF

  v9 = BYTE3(wrap);
  v10 = wrap;
  if ( this->mergeBranch == nullptr )
    return 0;
  DurationMS = blendParms_t::GetDurationMS(this: blendParms, a2: (int)animator, a3: (int)node, a4: wrap);
  mergeBranch = this->mergeBranch;
  v16 = DurationMS;
  HIDWORD(v17) = mergeBranch->right;
  HIDWORD(v18) = HIDWORD(v17) - 1;
  v19 = HIDWORD(v17) != 0;
  if ( HIDWORD(v17) != 0 )
  {
    if ( DurationMS != 0 )
    {
      numFreeBranches = this->numFreeBranches;
      if ( this->numFreeBranches == 0 )
        return 0;
      LODWORD(v21) = (__int16)(numFreeBranches - 1);
      HIDWORD(v21) = v21 + 19;
      this->numFreeBranches = v21;
      LODWORD(v18) = 4 * (v21 + 19);
      v22 = *(int *)((char *)&this->__vftable + v18);
      if ( v22 == 0 )
        return 0;
      LODWORD(v21) = "_AI_OBSTACLE";
      HIDWORD(v23) = "<unknown>";
      LODWORD(v23) = 2 - numFreeBranches;
      va::va(this: &v33, fmt: "%s%d", a3: v23, a4: v18, a5: v21, a6: v27, a7: v28, a8: v29, a9: v30, a10: v31, a11: v32);
      FilterGroup = idAnimator_Base::GetFilterGroup(this);
      *(_BYTE *)(v22 + 21) = v9;
      *(_BYTE *)(v22 + 20) = FilterGroup;
      HIDWORD(v18) = v16;
      *(_BYTE *)(v22 + 22) = blendParms->parms.originBlend;
      HIDWORD(v17) = this->mergeBranch->right;
      *(float *)(v22 + 28) = 0.0;
      *(_DWORD *)(v22 + 8) = HIDWORD(v17);
      *(float *)(v22 + 24) = 1.0;
      *(_DWORD *)(v22 + 4) = node;
      HIDWORD(v25) = timeManager.gameHz;
      LODWORD(v25) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
      *(float *)(v22 + 32) = (float)v25 / (float)*(__int64 *)((char *)&v18 + 4);
      this->mergeBranch->right = (idMD6Node *)v22;
    }
    else
    {
      idAnimator_Channel::FreeTree(this, node: (idMD6Branch *)HIDWORD(v17));
      this->mergeBranch->right = node;
      this->mergeBranch->currentAlpha = 1.0;
      this->mergeBranch->targetAlpha = 1.0;
      this->mergeBranch->alphaRate = 0.0;
    }
  }
  else
  {
    mergeBranch->right = node;
  }
  this->mergeBranch->targetAlpha = 1.0;
  if ( !v19 )
    this->mergeBranch->currentAlpha = 0.0;
  v26 = v16;
  if ( v16 <= 0 )
  {
    this->mergeBranch->alphaRate = 0.0;
    this->mergeBranch->currentAlpha = 1.0;
  }
  else
  {
    LODWORD(v18) = v16;
    LODWORD(v17) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    this->mergeBranch->alphaRate = (float)((float)__fabs((float)(this->mergeBranch->targetAlpha
                                                               - this->mergeBranch->currentAlpha))
                                         * (float)v17)
                                 / (float)v18;
  }
  if ( v10 != 0 )
  {
    this->blendOutDurationMS = 0;
    return 1;
  }
  else
  {
    if ( blendOutDurationMS_ >= 0 )
      v26 = blendOutDurationMS_;
    this->blendOutDurationMS = v26;
    return 1;
  }
}


// ========================================================================
// ?AllocLeaf@idAnimator_Channel@@AAAPAVidMD6LeafPlay@@XZ
// EA  : 0x826DF128
// RVA : 0x006DF128
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

idMD6LeafPlay *__fastcall idAnimator_Channel::AllocLeaf(idAnimator_Channel *this)
{
  int v3; // r10

  if ( this->numFreeLeaves == 0 && (*((_BYTE *)this + 94) & 0x80) != 0 )
    idAnimator_Channel::ForceFreeLeaf(this);
  if ( this->numFreeLeaves == 0 )
    return nullptr;
  v3 = (__int16)(this->numFreeLeaves - 1);
  this->numFreeLeaves = v3;
  return this->freeLeaves[v3];
}


// ========================================================================
// ?IsAnimPlaying@idAnimator_Channel@@QBA_NPBVidAnimStack@@ABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@H@Z
// EA  : 0x826DF1B8
// RVA : 0x006DF1B8
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

int __fastcall idAnimator_Channel::IsAnimPlaying(
        idAnimator_Channel *this,
        const idAnimStack *stack,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *ah,
        int curTime)
{
  const idMD6Alias *Alias; // r25
  idMD6Branch *mergeBranch; // r11
  idMD6Node *right; // r11
  int v9; // r26
  idMD6LeafPlay **v10; // r27
  idMD6Branch *v11; // r31
  int type; // r11
  char v13; // r11
  bool v14; // zf
  const idMD6Node *left; // r4
  const idMD6Node *v16; // r4
  int num; // r29
  int v18; // r30
  idResource *v19; // r28
  int v20; // r31
  idResource *Existing; // r3
  idMD6Node *v23; // [sp+50h] [-E0h] BYREF

  Alias = idDeclMD6::FindAlias(this: stack->treeAnimator->decl, aliasHandle: ah, includeInherited: true);
  if ( Alias == nullptr )
    return 0;
  mergeBranch = this->mergeBranch;
  if ( mergeBranch == nullptr )
    return 0;
  right = mergeBranch->right;
  if ( right == nullptr )
    return 0;
  v23 = right;
  v9 = 0;
  v10 = (idMD6LeafPlay **)&v23;
  while ( 1 )
  {
    v11 = (idMD6Branch *)*v10;
    type = (*v10)->type;
    if ( (*v10)->type == 0 || type == 3 || type == 4 || (v14 = type != 5, v13 = 0, !v14) )
      v13 = 1;
    if ( v13 != 0 )
    {
      left = v11->left;
      --v9;
      --v10;
      if ( left != nullptr && !idMD6Branch::IsChildBlendedOut(this: v11, child: left) )
      {
        ++v9;
        *++v10 = (idMD6LeafPlay *)v11->left;
      }
      v16 = v11->right;
      if ( v16 != nullptr && !idMD6Branch::IsChildBlendedOut(this: v11, child: v16) )
      {
        ++v9;
        *++v10 = (idMD6LeafPlay *)v11->right;
      }
      goto LABEL_25;
    }
    if ( v11->type == 2 )
      break;
LABEL_25:
    if ( v9 < 0 )
      return 0;
  }
  if ( !idMD6LeafPlay::IsPlaying(
          this: *v10,
          gameTime: curTime,
          ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz)
    || (num = Alias->animRefs.num, v18 = 0, v19 = (idResource *)v11->left, num <= 0) )
  {
LABEL_24:
    --v9;
    --v10;
    goto LABEL_25;
  }
  v20 = 0;
  while ( 1 )
  {
    Existing = idResourceList::FindExisting(
                 this: &idMD6Anim::resourceList,
                 name: (char *)Alias->animRefs.list[v20].str,
                 skipStaleCheck: true);
    if ( Existing != nullptr && v19 == Existing )
      return 1;
    ++v18;
    ++v20;
    if ( v18 >= num )
      goto LABEL_24;
  }
}


// ========================================================================
// ?StartLeaf@idAnimator_Channel@@AAA_NPAVidTreeAnimator@@PBVidMD6Anim@@HMW4blendOp_t@idMD6Blend@@W4wrapMode_t@idMD6Leaf@@ABVblendParms_t@@HPAPAVidMD6LeafPlay@@@Z
// EA  : 0x826DF368
// RVA : 0x006DF368
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

int __fastcall idAnimator_Channel::StartLeaf(
        idAnimator_Channel *this,
        idTreeAnimator *animator,
        const idMD6Anim *anim,
        int curTime,
        double rateScale,
        const idMD6Blend::blendOp_t blendOp,
        unsigned int wrap,
        const blendParms_t *blendParms,
        blendParms_t *blendOutDurationMS_,
        idMD6LeafPlay **leafStarted,
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
        int a29,
        int a30,
        idMD6LeafPlay **a31)
{
  idMD6LeafPlay *v40; // r29
  __int16 v41; // [sp+50h] [-60h] BYREF
  __int16 v42[7]; // [sp+52h] [-5Eh] BYREF

  if ( anim == nullptr )
    return 0;
  v40 = idAnimator_Channel::AllocLeaf(this);
  if ( v40 == nullptr )
    return 0;
  blendParms_t::GetDestFrames(this: blendOutDurationMS_, anim, firstFrame: &v41, duration_: v42);
  idMD6LeafPlay::Init(
    this: v40,
    anim,
    gameTime: curTime,
    ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
    frame: v41,
    rateScale,
    wrapMode: (const idMD6Leaf::wrapMode_t)timeManager.gameHz,
    weightGroup: (const md6WeightGroup_t)blendParms);
  if ( (unsigned __int8)idAnimator_Channel::StartNode(
                          this,
                          animator,
                          node: v40,
                          curTime,
                          wrap: __SPAIR64__(wrap, (unsigned int)blendParms),
                          blendParms: blendOutDurationMS_,
                          blendOutDurationMS_: a29) != 0 )
  {
    if ( a31 != nullptr )
      *a31 = v40;
    return 1;
  }
  else
  {
    this->freeLeaves[this->numFreeLeaves++] = v40;
    return 0;
  }
}


// ========================================================================
// ?PlayAnim@idAnimator_Channel@@QAA_NPBVidAnimStack@@PBVidMD6Anim@@HMABVblendParms_t@@HPAPAVidMD6LeafPlay@@@Z
// EA  : 0x826DF490
// RVA : 0x006DF490
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

int __fastcall idAnimator_Channel::PlayAnim(
        idAnimator_Channel *this,
        const idAnimStack *stack,
        const idMD6Anim *ah,
        int curTime,
        double rateScale,
        const blendParms_t *blendParms,
        blendParms_t *blendOutDurationMS_,
        idMD6LeafPlay **leafStarted,
        idMD6LeafPlay **a9)
{
  idMD6LeafPlay **v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+10h] [-60h]
  int v13; // [sp+14h] [-5Ch]
  int v14; // [sp+18h] [-58h]
  int v15; // [sp+1Ch] [-54h]
  int v16; // [sp+20h] [-50h]
  int v17; // [sp+24h] [-4Ch]
  int v18; // [sp+28h] [-48h]
  int v19; // [sp+2Ch] [-44h]
  int v20; // [sp+30h] [-40h]
  int v21; // [sp+34h] [-3Ch]
  int v22; // [sp+38h] [-38h]
  int v23; // [sp+3Ch] [-34h]
  int v24; // [sp+40h] [-30h]
  int v25; // [sp+44h] [-2Ch]
  int v26; // [sp+48h] [-28h]
  int v27; // [sp+4Ch] [-24h]
  int v28; // [sp+50h] [-20h]
  int v29; // [sp+58h] [-18h]

  return idAnimator_Channel::StartLeaf(
           this,
           animator: stack->treeAnimator,
           anim: ah,
           curTime,
           rateScale,
           blendOp: (const idMD6Blend::blendOp_t)a9,
           wrap: 1u,
           blendParms: nullptr,
           blendOutDurationMS_,
           leafStarted: v10,
           a11: v11,
           a12: v12,
           a13: v13,
           a14: v14,
           a15: v15,
           a16: v16,
           a17: v17,
           a18: v18,
           a19: v19,
           a20: v20,
           a21: v21,
           a22: v22,
           a23: v23,
           a24: v24,
           a25: v25,
           a26: v26,
           a27: v27,
           a28: v28,
           a29: (int)leafStarted,
           a30: v29,
           a31: a9);
}


// ========================================================================
// ?CycleAnim@idAnimator_Channel@@QAA_NPBVidAnimStack@@PBVidMD6Anim@@HMABVblendParms_t@@PAPAVidMD6LeafPlay@@@Z
// EA  : 0x826DF4D0
// RVA : 0x006DF4D0
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

int __fastcall idAnimator_Channel::CycleAnim(
        idAnimator_Channel *this,
        const idAnimStack *stack,
        const idMD6Anim *ah,
        int curTime,
        double rateScale,
        __int64 leafStarted,
        idMD6LeafPlay **a7)
{
  idTreeAnimator *treeAnimator; // r26
  blendParms_t *v12; // r28
  __int16 DurationMS; // r3
  idMD6Blend::blendOp_t v15; // r7
  idMD6LeafPlay **v17; // [sp+8h] [-98h]
  int v18; // [sp+Ch] [-94h]
  int v19; // [sp+10h] [-90h]
  int v20; // [sp+14h] [-8Ch]
  int v21; // [sp+18h] [-88h]
  int v22; // [sp+1Ch] [-84h]
  int v23; // [sp+20h] [-80h]
  int v24; // [sp+24h] [-7Ch]
  int v25; // [sp+28h] [-78h]
  int v26; // [sp+2Ch] [-74h]
  int v27; // [sp+30h] [-70h]
  int v28; // [sp+34h] [-6Ch]
  int v29; // [sp+38h] [-68h]
  int v30; // [sp+3Ch] [-64h]
  int v31; // [sp+40h] [-60h]
  int v32; // [sp+44h] [-5Ch]
  int v33; // [sp+48h] [-58h]
  int v34; // [sp+4Ch] [-54h]
  int v35; // [sp+50h] [-50h]
  int v36; // [sp+58h] [-48h]

  treeAnimator = stack->treeAnimator;
  v12 = (blendParms_t *)leafStarted;
  DurationMS = blendParms_t::GetDurationMS(
                 this: (blendParms_t *)leafStarted,
                 a2: (int)stack,
                 a3: (int)ah,
                 a4: leafStarted);
  return idAnimator_Channel::StartLeaf(
           this,
           animator: treeAnimator,
           anim: ah,
           curTime,
           rateScale,
           blendOp: v15,
           wrap: 1u,
           blendParms: (const blendParms_t *)1,
           blendOutDurationMS_: v12,
           leafStarted: v17,
           a11: v18,
           a12: v19,
           a13: v20,
           a14: v21,
           a15: v22,
           a16: v23,
           a17: v24,
           a18: v25,
           a19: v26,
           a20: v27,
           a21: v28,
           a22: v29,
           a23: v30,
           a24: v31,
           a25: v32,
           a26: v33,
           a27: v34,
           a28: v35,
           a29: DurationMS,
           a30: v36,
           a31: a7);
}


// ========================================================================
// ?StartLeaf@idAnimator_Channel@@AAA_NPAVidTreeAnimator@@ABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@HMW4blendOp_t@idMD6Blend@@W4wrapMode_t@idMD6Leaf@@ABVblendParms_t@@HPAPAVidMD6LeafPlay@@@Z
// EA  : 0x826DF540
// RVA : 0x006DF540
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

int __fastcall idAnimator_Channel::StartLeaf(
        idAnimator_Channel *this,
        idTreeAnimator *animator,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *ah,
        int curTime,
        double rateScale,
        const idMD6Blend::blendOp_t blendOp,
        unsigned int wrap,
        const blendParms_t *blendParms,
        blendParms_t *blendOutDurationMS_,
        idMD6LeafPlay **leafStarted,
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
        int a29,
        int a30,
        idMD6LeafPlay **a31)
{
  const idMD6Alias *Alias; // r30
  int v40; // r3
  const idMD6Anim *Existing; // r3
  idMD6LeafPlay **v42; // [sp+8h] [-A8h]
  int v43; // [sp+Ch] [-A4h]
  int v44; // [sp+10h] [-A0h]
  int v45; // [sp+14h] [-9Ch]
  int v46; // [sp+18h] [-98h]
  int v47; // [sp+1Ch] [-94h]
  int v48; // [sp+20h] [-90h]
  int v49; // [sp+24h] [-8Ch]
  int v50; // [sp+28h] [-88h]
  int v51; // [sp+2Ch] [-84h]
  int v52; // [sp+30h] [-80h]
  int v53; // [sp+34h] [-7Ch]
  int v54; // [sp+38h] [-78h]
  int v55; // [sp+3Ch] [-74h]
  int v56; // [sp+40h] [-70h]
  int v57; // [sp+44h] [-6Ch]
  int v58; // [sp+48h] [-68h]
  int v59; // [sp+4Ch] [-64h]
  int v60; // [sp+50h] [-60h]
  int v61; // [sp+58h] [-58h]

  if ( animator == nullptr )
    return 0;
  Alias = idDeclMD6::FindAlias(this: animator->decl, aliasHandle: ah, includeInherited: true);
  if ( Alias == nullptr )
    return 0;
  v40 = idRandom::RandomInt(this: &this->random, max: Alias->animRefs.num);
  Existing = (const idMD6Anim *)idResourceList::FindExisting(
                                  this: &idMD6Anim::resourceList,
                                  name: (char *)Alias->animRefs.list[v40].str,
                                  skipStaleCheck: false);
  return idAnimator_Channel::StartLeaf(
           this,
           animator,
           anim: Existing,
           curTime,
           rateScale,
           blendOp: (const idMD6Blend::blendOp_t)a31,
           wrap,
           blendParms,
           blendOutDurationMS_,
           leafStarted: v42,
           a11: v43,
           a12: v44,
           a13: v45,
           a14: v46,
           a15: v47,
           a16: v48,
           a17: v49,
           a18: v50,
           a19: v51,
           a20: v52,
           a21: v53,
           a22: v54,
           a23: v55,
           a24: v56,
           a25: v57,
           a26: v58,
           a27: v59,
           a28: v60,
           a29,
           a30: v61,
           a31);
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_Channel@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826DF610
// RVA : 0x006DF610
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

void __fastcall idAnimator_Channel::InternalPreBlendTree(
        idAnimator_Channel *this,
        const idAnimStack *stack,
        int curTime,
        const int ticksPerSec)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idMD6Branch *mergeBranch; // r11
  idMD6Node *right; // r30
  idMD6Branch *v10; // r28
  int type; // r10
  char v12; // r11
  int v13; // r10
  char v14; // r10
  bool v15; // zf
  int v16; // r28
  __int64 v17; // r9
  __int64 v18; // r6
  int v19; // r11
  idMD6Branch *v20; // r10
  double v21; // fp0
  idMD6Branch *v22; // r10
  double v23; // fp13
  idMD6Branch *v24; // r8
  double targetAlpha; // fp11
  double currentAlpha; // fp10
  idMD6Branch *v27; // r11
  idMD6LeafPlay *v28; // r27
  int v29; // r10
  idMD6LeafPlay v30; // [sp+50h] [-70h] BYREF

  RD_EventBegin(name: "idAnimator_Channel::InternalPreBlendTree");
  LODWORD(v6) = "idAnimator_Channel::InternalPreBlendTree";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v30.rateScale, pl: &pLog, gMask: v6, label: v7);
  this->mergeBranch->left = nullptr;
  mergeBranch = this->mergeBranch;
  if ( mergeBranch != nullptr )
  {
    right = mergeBranch->right;
    v10 = this->mergeBranch;
    while ( right != nullptr )
    {
      type = right->type;
      if ( right->type == 0 || type == 3 || type == 4 || (v12 = 0, type == 5) )
        v12 = 1;
      if ( v12 != 0 )
      {
        if ( idMD6Branch::IsBlendFinished(this: (idMD6Branch *)right) || !idAnimator_Base::IsContributing(this) )
        {
          v10->right = *(idMD6Node **)&right[4].type;
          idAnimator_Channel::FreeTree(this, node: *(idMD6Branch **)&right[8].type);
          this->freeBranches[this->numFreeBranches++] = (idMD6Branch *)right;
          break;
        }
        v10 = (idMD6Branch *)right;
        right = *(idMD6Node **)&right[8].type;
      }
      else if ( type == 2 )
      {
        break;
      }
    }
    *(_DWORD *)&v30.weightGroup = this->mergeBranch->right;
    if ( *(_DWORD *)&v30.weightGroup != 0 )
    {
      v13 = (unsigned __int8)**(_BYTE **)&v30.weightGroup;
      if ( **(_BYTE **)&v30.weightGroup == 0 || v13 == 3 || v13 == 4 || (v15 = v13 != 5, v14 = 0, !v15) )
        v14 = 1;
      if ( v14 != 0 )
        v16 = *(_DWORD *)(*(_DWORD *)&v30.weightGroup + 4);
      else
        v16 = *(_DWORD *)&v30.weightGroup;
      if ( *(_BYTE *)(v16 + 9) == 0 )
      {
        idMD6LeafPlay::GetAnimTicks(
          this: &v30,
          result: (idTypesafeNumber<int,enum gameTimeUnique_t> *)v16,
          ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz);
        v19 = *(_DWORD *)(v16 + 12) + *(_DWORD *)&v30.type - curTime;
        if ( v19 > 0 )
        {
          if ( v19 <= this->blendOutDurationMS )
          {
            v22 = this->mergeBranch;
            LODWORD(v17) = *(_DWORD *)(v16 + 12) + *(_DWORD *)&v30.type - curTime;
            *(_QWORD *)&v30.weightGroup = v17;
            v23 = (double)v17;
            v22->targetAlpha = 0.0;
            v24 = this->mergeBranch;
            targetAlpha = v24->targetAlpha;
            LODWORD(v18) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
            currentAlpha = v24->currentAlpha;
            *(_DWORD *)&v30.weightGroup = v24;
            v30.startTime = timeManager.gameTimePerFrame.value * timeManager.gameHz;
            v24->alphaRate = (float)((float)v18 * (float)__fabs((float)((float)targetAlpha - (float)currentAlpha)))
                           / (float)v23;
          }
        }
        else
        {
          this->mergeBranch->alphaRate = 0.0;
          v20 = this->mergeBranch;
          v21 = v20->targetAlpha;
          *(_DWORD *)&v30.weightGroup = v20;
          v20->currentAlpha = v21;
        }
      }
      v27 = this->mergeBranch;
      v28 = (idMD6LeafPlay *)v27->right;
      v29 = v28->type;
      *(_DWORD *)&v30.weightGroup = v28;
      if ( v29 == 2
        && (v27->targetAlpha == 0.0 && v27->currentAlpha == 0.0
         || !idMD6LeafPlay::IsPlaying(
               this: (idMD6LeafPlay *)v16,
               gameTime: curTime,
               ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz)) )
      {
        this->mergeBranch->right = nullptr;
        this->freeLeaves[this->numFreeLeaves++] = v28;
      }
    }
  }
  idPLogScope::~idPLogScope(this: (idPLogScope *)&v30.rateScale);
  RD_EventEnd();
}


// ========================================================================
// __unwind$247780
// EA  : 0x826DF904
// RVA : 0x006DF904
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

void _unwind_247780()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 104));
}


// ========================================================================
// __unwind$247781
// EA  : 0x826DF92C
// RVA : 0x006DF92C
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

void _unwind_247781()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 96));
}


// ========================================================================
// ?PlayAnim@idAnimator_Channel@@QAA_NPBVidAnimStack@@ABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@HMABVblendParms_t@@HPAPAVidMD6LeafPlay@@@Z
// EA  : 0x826DF958
// RVA : 0x006DF958
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

int __fastcall idAnimator_Channel::PlayAnim(
        idAnimator_Channel *this,
        const idAnimStack *stack,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *ah,
        int curTime,
        double rateScale,
        const blendParms_t *blendParms,
        blendParms_t *blendOutDurationMS_,
        idMD6LeafPlay **leafStarted,
        idMD6LeafPlay **a9)
{
  idMD6LeafPlay **v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+10h] [-60h]
  int v13; // [sp+14h] [-5Ch]
  int v14; // [sp+18h] [-58h]
  int v15; // [sp+1Ch] [-54h]
  int v16; // [sp+20h] [-50h]
  int v17; // [sp+24h] [-4Ch]
  int v18; // [sp+28h] [-48h]
  int v19; // [sp+2Ch] [-44h]
  int v20; // [sp+30h] [-40h]
  int v21; // [sp+34h] [-3Ch]
  int v22; // [sp+38h] [-38h]
  int v23; // [sp+3Ch] [-34h]
  int v24; // [sp+40h] [-30h]
  int v25; // [sp+44h] [-2Ch]
  int v26; // [sp+48h] [-28h]
  int v27; // [sp+4Ch] [-24h]
  int v28; // [sp+50h] [-20h]
  int v29; // [sp+58h] [-18h]

  return idAnimator_Channel::StartLeaf(
           this,
           animator: stack->treeAnimator,
           ah,
           curTime,
           rateScale,
           blendOp: (const idMD6Blend::blendOp_t)a9,
           wrap: 1u,
           blendParms: nullptr,
           blendOutDurationMS_,
           leafStarted: v10,
           a11: v11,
           a12: v12,
           a13: v13,
           a14: v14,
           a15: v15,
           a16: v16,
           a17: v17,
           a18: v18,
           a19: v19,
           a20: v20,
           a21: v21,
           a22: v22,
           a23: v23,
           a24: v24,
           a25: v25,
           a26: v26,
           a27: v27,
           a28: v28,
           a29: (int)leafStarted,
           a30: v29,
           a31: a9);
}


// ========================================================================
// ?CycleAnim@idAnimator_Channel@@QAA_NPBVidAnimStack@@ABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@HMABVblendParms_t@@PAPAVidMD6LeafPlay@@@Z
// EA  : 0x826DF998
// RVA : 0x006DF998
// PDB : w:\tech5\engine\gamelib\animstack\animator_channel.cpp
// ========================================================================

int __fastcall idAnimator_Channel::CycleAnim(
        idAnimator_Channel *this,
        const idAnimStack *stack,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *ah,
        int curTime,
        double rateScale,
        __int64 leafStarted,
        idMD6LeafPlay **a7)
{
  idTreeAnimator *treeAnimator; // r26
  blendParms_t *v12; // r28
  __int16 DurationMS; // r3
  idMD6Blend::blendOp_t v15; // r7
  idMD6LeafPlay **v17; // [sp+8h] [-98h]
  int v18; // [sp+Ch] [-94h]
  int v19; // [sp+10h] [-90h]
  int v20; // [sp+14h] [-8Ch]
  int v21; // [sp+18h] [-88h]
  int v22; // [sp+1Ch] [-84h]
  int v23; // [sp+20h] [-80h]
  int v24; // [sp+24h] [-7Ch]
  int v25; // [sp+28h] [-78h]
  int v26; // [sp+2Ch] [-74h]
  int v27; // [sp+30h] [-70h]
  int v28; // [sp+34h] [-6Ch]
  int v29; // [sp+38h] [-68h]
  int v30; // [sp+3Ch] [-64h]
  int v31; // [sp+40h] [-60h]
  int v32; // [sp+44h] [-5Ch]
  int v33; // [sp+48h] [-58h]
  int v34; // [sp+4Ch] [-54h]
  int v35; // [sp+50h] [-50h]
  int v36; // [sp+58h] [-48h]

  treeAnimator = stack->treeAnimator;
  v12 = (blendParms_t *)leafStarted;
  DurationMS = blendParms_t::GetDurationMS(
                 this: (blendParms_t *)leafStarted,
                 a2: (int)stack,
                 a3: (int)ah,
                 a4: leafStarted);
  return idAnimator_Channel::StartLeaf(
           this,
           animator: treeAnimator,
           ah,
           curTime,
           rateScale,
           blendOp: v15,
           wrap: 1u,
           blendParms: (const blendParms_t *)1,
           blendOutDurationMS_: v12,
           leafStarted: v17,
           a11: v18,
           a12: v19,
           a13: v20,
           a14: v21,
           a15: v22,
           a16: v23,
           a17: v24,
           a18: v25,
           a19: v26,
           a20: v27,
           a21: v28,
           a22: v29,
           a23: v30,
           a24: v31,
           a25: v32,
           a26: v33,
           a27: v34,
           a28: v35,
           a29: DurationMS,
           a30: v36,
           a31: a7);
}

