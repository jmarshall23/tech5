
// ========================================================================
// ?InternalGetMergeBranch@idAnimator_FaceTracks@@MAAPAVidMD6Branch@@XZ
// EA  : 0x826E1D80
// RVA : 0x006E1D80
// PDB : w:\tech5\engine\gamelib\animstack\animator_facetracks.cpp
// ========================================================================

const idMD6Branch *__fastcall idAnimator_FaceTracks::InternalGetMergeBranch(idAnimator_FaceTracks *this)
{
  return &this->mergeBranch;
}


// ========================================================================
// ?InternalGetEndBranch@idAnimator_FaceTracks@@MAAPAVidMD6Branch@@XZ
// EA  : 0x826E1D88
// RVA : 0x006E1D88
// PDB : w:\tech5\engine\gamelib\animstack\animator_facetracks.cpp
// ========================================================================

const idMD6Branch *__fastcall idAnimator_FaceTracks::InternalGetEndBranch(idAnimator_FaceTracks *this)
{
  return this->endBranch;
}


// ========================================================================
// ?HasFaceTracks@idAnimator_FaceTracks@@SA_NPBVidDeclMD6@@@Z
// EA  : 0x826E1D90
// RVA : 0x006E1D90
// PDB : w:\tech5\engine\gamelib\animstack\animator_facetracks.cpp
// ========================================================================

const idDeclMD6 *__fastcall idAnimator_FaceTracks::HasFaceTracks(const idDeclMD6 *decl)
{
  _BYTE v1[8]; // [sp+50h] [-10h] BYREF

  if ( decl != nullptr )
    return (const idDeclMD6 *)(animation->FindAliasHandle(
                                 this: v1,
                                 result: animation,
                                 a3: decl,
                                 a4: "facesetup/facesetup")->value != 65535);
  return decl;
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_FaceTracks@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826E1E00
// RVA : 0x006E1E00
// PDB : w:\tech5\engine\gamelib\animstack\animator_facetracks.cpp
// ========================================================================

void __fastcall idAnimator_FaceTracks::InternalPreBlendTree(
        idAnimator_FaceTracks *this,
        const idAnimStack *stack,
        int curTime,
        const int ticksPerSec)
{
  idMD6Branch *endBranch; // r11
  int v7; // r28
  int animModsTime; // r11
  int v9; // r29
  int v10; // r31
  int *list; // r11

  endBranch = this->endBranch;
  v7 = 0;
  if ( endBranch != nullptr )
    endBranch->left = nullptr;
  animModsTime = this->animModsTime;
  if ( animModsTime != -1 )
  {
    if ( curTime > animModsTime )
      this->animModsTime = -1;
    if ( this->leaves.num > 0 )
    {
      v9 = 0;
      v10 = 0;
      do
      {
        list = this->leafAnimModsTime.list;
        if ( curTime > list[v10] )
        {
          list[v10] = -1;
          idMD6LeafPause::SetNumAnimMods(this: &this->leaves.list[v9], n: 0);
        }
        ++v7;
        ++v10;
        ++v9;
      }
      while ( v7 < this->leaves.num );
    }
  }
}


// ========================================================================
// ?AddUserChannelMod@idAnimator_FaceTracks@@QAAXV?$idIndex@FW4invalidUserChannelIndex_t@@@@MH@Z
// EA  : 0x826E1EA0
// RVA : 0x006E1EA0
// PDB : w:\tech5\engine\gamelib\animstack\animator_facetracks.cpp
// ========================================================================

void __fastcall idAnimator_FaceTracks::AddUserChannelMod(
        idAnimator_FaceTracks *this,
        idIndex<short,enum invalidUserChannelIndex_t> *userChannel,
        double value,
        const int curTime,
        int a5,
        __int64 a6)
{
  int animModsTime; // r11
  __int16 v7; // r29
  int num; // r9
  int v10; // r11
  double v11; // fp0
  idMD6LeafPause *list; // r8
  int v13; // r10
  idMD6LeafPause *v14; // r9
  int *v15; // r9
  int v16; // r10
  int v17; // r30
  int v18; // r7
  int v19; // r11
  idMD6LeafPause *v20; // r31
  int v21; // r11

  animModsTime = this->animModsTime;
  v7 = (__int16)userChannel;
  if ( animModsTime <= a5 )
    animModsTime = a5;
  LODWORD(a6) = (__int16)userChannel;
  num = this->leaves.num;
  this->animModsTime = animModsTime;
  v10 = num - 1;
  v11 = (float)a6;
  if ( num - 1 > 0 )
  {
    list = this->leaves.list;
    v13 = v10;
    v14 = &list[v10];
    while ( v14[-1].frame <= v11 )
    {
      --v13;
      --v10;
      v14 = &list[v13];
      if ( v10 <= 0 )
        return;
    }
    if ( v10 != -1 )
    {
      v15 = this->leafAnimModsTime.list;
      v16 = v10;
      v17 = 0;
      v18 = v15[v10];
      v19 = v10;
      v20 = &list[v19];
      if ( v18 == a5 )
        v17 = v20->animMods[0].num;
      v15[v16] = a5;
      idMD6LeafPause::SetNumAnimMods(this: &list[v19], n: v17 + 1);
      v21 = (int)&v20->animMods[v20->currentDeferred & 1].list[v17];
      *(float *)(v21 + 48) = value;
      *(_WORD *)(v21 + 60) = v7;
      *(float *)v21 = 1.0;
      *(_WORD *)(v21 + 62) = 144;
      *(float *)(v21 + 4) = 0.0;
      *(float *)(v21 + 8) = 0.0;
    }
  }
}


// ========================================================================
// ??0idAnimator_FaceTracks@@QAA@XZ
// EA  : 0x826E2030
// RVA : 0x006E2030
// PDB : w:\tech5\engine\gamelib\animstack\animator_facetracks.cpp
// ========================================================================

idAnimator_FaceTracks *__fastcall idAnimator_FaceTracks::idAnimator_FaceTracks(idAnimator_FaceTracks *this)
{
  idAnimator_Base::idAnimator_Base(this);
  this->__vftable = (idAnimator_FaceTracks_vtbl *)&idAnimator_FaceTracks::`vftable';
  this->leaves.granularity = 0;
  this->leaves.memTag = 5;
  this->leaves.listStatic = 0;
  this->leaves.list = nullptr;
  this->leaves.size = 0;
  this->leaves.num = 0;
  this->branches.list = nullptr;
  this->branches.granularity = 0;
  this->branches.memTag = 5;
  this->branches.listStatic = 0;
  this->branches.size = 0;
  this->branches.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->branches);
  this->leafAnimModsTime.list = nullptr;
  this->leafAnimModsTime.granularity = 0;
  this->leafAnimModsTime.memTag = 5;
  this->leafAnimModsTime.listStatic = 0;
  this->leafAnimModsTime.size = 0;
  this->leafAnimModsTime.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->leafAnimModsTime);
  this->mergeBranch.type = 0;
  this->mergeBranch.left = nullptr;
  this->mergeBranch.right = nullptr;
  this->mergeBranch.leftTimeOverride = -1;
  this->mergeBranch.currentAlpha = 0.0;
  this->mergeBranch.rightTimeOverride = -1;
  this->mergeBranch.targetAlpha = 0.0;
  this->mergeBranch.filterGroup = 8;
  this->mergeBranch.alphaRate = 0.0;
  this->mergeBranch.op = 10;
  this->mergeBranch.originBlend = 0;
  this->mergeBranch.blendType = BLEND_LINEAR;
  this->endBranch = nullptr;
  this->faceSetupAnimAlias.value = -1;
  this->animModsTime = -1;
  return this;
}


// ========================================================================
// __unwind$247125
// EA  : 0x826E2130
// RVA : 0x006E2130
// PDB : w:\tech5\engine\gamelib\animstack\animator_facetracks.cpp
// ========================================================================

void _unwind_247125()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$247126
// EA  : 0x826E2158
// RVA : 0x006E2158
// PDB : w:\tech5\engine\gamelib\animstack\animator_facetracks.cpp
// ========================================================================

void _unwind_247126()
{
  int v0; // r12

  idList<idMD6LeafPause,5>::~idList<idMD6LeafPause,5>(this: (idList<idMD6LeafPause,5> *)(*(_DWORD *)(v0 - 128 + 148) + 40));
}


// ========================================================================
// __unwind$247127
// EA  : 0x826E2184
// RVA : 0x006E2184
// PDB : w:\tech5\engine\gamelib\animstack\animator_facetracks.cpp
// ========================================================================

void _unwind_247127()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 56));
}


// ========================================================================
// ?InternalInit@idAnimator_FaceTracks@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826E2440
// RVA : 0x006E2440
// PDB : w:\tech5\engine\gamelib\animstack\animator_facetracks.cpp
// ========================================================================

int __fastcall idAnimator_FaceTracks::InternalInit(idAnimator_FaceTracks *this, const idAnimatorParms_Base *parms)
{
  idTreeAnimator *treeAnimator; // r30
  const idMD6Alias *Alias; // r3
  idResource *Existing; // r3
  const idMD6Anim *v8; // r18
  int trackedMemory; // r29
  idList<idMD6LeafPause,5> *p_leaves; // r19
  int v11; // r16
  idList<idMD6Branch,5> *p_branches; // r22
  idMD6Branch *v13; // r23
  int v14; // r24
  int v15; // r25
  int v16; // r27
  int v17; // r26
  int v18; // r21
  __int64 v19; // r11
  idMD6LeafPause *v20; // r30
  idMD6Branch::blendType_t flags; // r9
  idMD6Branch *v22; // r28
  idMD6Node *list; // r11
  _QWORD v24[2]; // [sp+60h] [-E0h] BYREF
  idStr v25; // [sp+70h] [-D0h] BYREF

  treeAnimator = parms->animStack->treeAnimator;
  if ( treeAnimator == nullptr || treeAnimator->decl->model == nullptr )
    return 0;
  idStr::idStr(this: &v25, text: "facesetup/facesetup");
  ((void (__fastcall *)(_QWORD *))animation->AddStrongAliasRef)(a1: v24);
  this->faceSetupAnimAlias.value = animation->StrongLoadAlias(
                                     this: v24,
                                     result: animation,
                                     a3: treeAnimator->decl,
                                     a4: v25.data)->value;
  Alias = idDeclMD6::FindAlias(
            this: parms->animStack->treeAnimator->decl,
            aliasHandle: &this->faceSetupAnimAlias,
            includeInherited: true);
  if ( Alias == nullptr )
  {
    idStr::FreeData(this: &v25);
    return 0;
  }
  Existing = idResourceList::FindExisting(
               this: &idMD6Anim::resourceList,
               name: (char *)Alias->animRefs.list->str,
               skipStaleCheck: false);
  v8 = (const idMD6Anim *)Existing;
  if ( Existing == nullptr )
  {
    idStr::FreeData(this: &v25);
    return 0;
  }
  trackedMemory = Existing[1].trackedMemory;
  p_leaves = &this->leaves;
  v11 = *(unsigned __int16 *)(trackedMemory + 12);
  idList<idMD6LeafPause,5>::SetNum(this: &this->leaves, newNum: v11);
  p_branches = &this->branches;
  idList<idMD6Branch,5>::SetNum(this: &this->branches, newNum: v11);
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->leafAnimModsTime, newNum: v11);
  v13 = nullptr;
  if ( v11 > 0 )
  {
    v14 = 0;
    v15 = 0;
    v16 = 0;
    v17 = 4 * v11;
    v18 = v11;
    do
    {
      this->leafAnimModsTime.list[v16] = -1;
      HIDWORD(v19) = p_leaves->list;
      v20 = &p_leaves->list[v15];
      LODWORD(v19) = *(unsigned __int16 *)(16
                                         * *(_DWORD *)(v17
                                                     + *(unsigned __int16 *)(trackedMemory + 16)
                                                     + trackedMemory
                                                     - 4)
                                         + trackedMemory
                                         + 34);
      v24[0] = v19;
      idMD6LeafPause::Init(
        this: v20,
        anim: v8,
        frame: (float)v19,
        wrapMode: (const idMD6Leaf::wrapMode_t)v19,
        weightGroup: MD6_WEIGHTGROUP_ALL);
      flags = (unsigned __int16)v20->flags;
      v20->flags = flags | 0x80;
      v22 = &p_branches->list[v14];
      if ( v13 != nullptr )
        v13->left = v22;
      idMD6Branch::Init(
        this: v22,
        left: nullptr,
        right: v20,
        op: BOP_ADD_RIGHT,
        originBlend: ORIGINBLEND_BRANCH,
        startAlpha: 1.0,
        targetAlpha: 1.0,
        alphaRate: 0.0,
        filterGroup: (const md6WeightGroup_t)(flags | 0x80),
        blendType: flags);
      --v18;
      v13 = v22;
      ++v16;
      v17 -= 4;
      ++v15;
      ++v14;
    }
    while ( v18 != 0 );
  }
  this->mergeBranch.targetAlpha = 1.0;
  this->mergeBranch.currentAlpha = 1.0;
  if ( v11 > 1 )
  {
    HIDWORD(v24[0]) = p_branches->list;
    list = (idMD6Node *)HIDWORD(v24[0]);
    this->endBranch = (idMD6Branch *)(40 * v11 + HIDWORD(v24[0]) - 40);
LABEL_17:
    this->mergeBranch.right = list;
    goto LABEL_18;
  }
  if ( v11 > 0 )
  {
    list = p_leaves->list;
    goto LABEL_17;
  }
LABEL_18:
  idStr::FreeData(this: &v25);
  return 1;
}


// ========================================================================
// __unwind$247355
// EA  : 0x826E26CC
// RVA : 0x006E26CC
// PDB : w:\tech5\engine\gamelib\animstack\animator_facetracks.cpp
// ========================================================================

void _unwind_247355()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 112));
}

