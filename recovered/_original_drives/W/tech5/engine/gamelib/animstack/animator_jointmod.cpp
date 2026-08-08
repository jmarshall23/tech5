
// ========================================================================
// ?InternalInit@idAnimator_JointMod@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826E80F0
// RVA : 0x006E80F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

int __fastcall idAnimator_JointMod::InternalInit(idAnimator_JointMod *this, const idAnimatorParms_Base *parms)
{
  idTreeAnimator *animStack; // r10

  animStack = (idTreeAnimator *)parms[1].animStack;
  if ( animStack == nullptr )
    return 0;
  this->treeAnimator = animStack;
  this->poseToModify = parms[1].name.len;
  return 1;
}


// ========================================================================
// ?PreSerializeInit@idAnimator_JointMod@@UAAXPAVidAnimStack@@PAVidClip@@PAVidGameTimeManager@@@Z
// EA  : 0x826E8128
// RVA : 0x006E8128
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

void __fastcall idAnimator_JointMod::PreSerializeInit(
        idAnimator_JointMod *this,
        idAnimStack *animStack_,
        idClip *clip_,
        idGameTimeManager *gametimeManager)
{
  idTreeAnimator *treeAnimator; // r11
  idTreeAnimator *v7; // r27
  idAnimatorParms_Base v8; // [sp+60h] [-70h] BYREF
  idTreeAnimator *v9; // [sp+98h] [-38h]
  int v10; // [sp+9Ch] [-34h]

  treeAnimator = animStack_->treeAnimator;
  this->serializeProps.animStack = animStack_;
  this->serializeProps.clip = clip_;
  v8.animStack = animStack_;
  this->treeAnimator = treeAnimator;
  this->gametimeManager.gameTimeManager = gametimeManager;
  this->serializeProps.createdThroughSerialization = true;
  v7 = this->treeAnimator;
  idStr::idStr(this: &v8.name, text: "jointmod");
  v9 = v7;
  v8.blendOp = BOP_LERP;
  memset(&v8.originBlend, 0, 12);
  v8.alpha = 1.0;
  v10 = 0;
  idAnimator_Base::Init(this, gametimeManager, parms: &v8);
  idStr::FreeData(this: &v8.name);
}


// ========================================================================
// __unwind$246574
// EA  : 0x826E81C4
// RVA : 0x006E81C4
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

void _unwind_246574()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 208 + 96));
}


// ========================================================================
// ??0idAnimator_JointMod@@QAA@XZ
// EA  : 0x826E8270
// RVA : 0x006E8270
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

idAnimator_JointMod *__fastcall idAnimator_JointMod::idAnimator_JointMod(idAnimator_JointMod *this)
{
  idAnimator_Base::idAnimator_Base(this);
  this->enabled = true;
  this->__vftable = (idAnimator_JointMod_vtbl *)&idAnimator_JointMod::`vftable';
  this->jointIndex.list = nullptr;
  this->jointIndex.granularity = 0;
  this->jointIndex.memTag = 5;
  this->jointIndex.listStatic = 0;
  this->jointIndex.size = 0;
  this->jointIndex.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointIndex);
  this->jointValue.list = nullptr;
  this->jointValue.granularity = 0;
  this->jointValue.memTag = 5;
  this->jointValue.listStatic = 0;
  this->jointValue.size = 0;
  this->jointValue.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointValue);
  this->treeAnimator = nullptr;
  this->poseToModify = 0;
  return this;
}


// ========================================================================
// __unwind$246817
// EA  : 0x826E82FC
// RVA : 0x006E82FC
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

void _unwind_246817()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$246818
// EA  : 0x826E8324
// RVA : 0x006E8324
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

void _unwind_246818()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 44));
}


// ========================================================================
// ??1idAnimator_JointMod@@UAA@XZ
// EA  : 0x826E8360
// RVA : 0x006E8360
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

void __fastcall idAnimator_JointMod::~idAnimator_JointMod(idAnimator_JointMod *this)
{
  this->__vftable = (idAnimator_JointMod_vtbl *)&idAnimator_JointMod::`vftable';
  this->treeAnimator = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointValue);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointIndex);
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// __unwind$246863
// EA  : 0x826E83C4
// RVA : 0x006E83C4
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

void _unwind_246863()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$246864
// EA  : 0x826E83EC
// RVA : 0x006E83EC
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

void _unwind_246864()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 44));
}


// ========================================================================
// ?ClearJointMods@idAnimator_JointMod@@QAAXXZ
// EA  : 0x826E8768
// RVA : 0x006E8768
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

void __fastcall idAnimator_JointMod::ClearJointMods(idAnimator_JointMod *this)
{
  idList<idIndex<short,enum invalidJointIndex_t>,5> *p_jointIndex; // r30
  idList<idVehicleState *,5> *p_jointValue; // r31

  p_jointIndex = &this->jointIndex;
  if ( this->jointIndex.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointIndex);
  p_jointValue = (idList<idVehicleState *,5> *)&this->jointValue;
  p_jointIndex->num = __CFADD__(-p_jointIndex->size, p_jointIndex->size ^ 0x80000000) ? 0 : p_jointIndex->size;
  if ( p_jointValue->size < 0 )
    idList<idThread *,58>::Clear(this: p_jointValue);
  p_jointValue->num = __CFADD__(-p_jointValue->size, p_jointValue->size ^ 0x80000000) ? 0 : p_jointValue->size;
}


// ========================================================================
// ?InternalPostBlendTree@idAnimator_JointMod@@MAAXPBVidAnimStack@@H@Z
// EA  : 0x826E87F0
// RVA : 0x006E87F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

// attributes: thunk
void __fastcall idAnimator_JointMod::InternalPostBlendTree(
        idAnimator_JointMod *this,
        const idAnimStack *stack,
        const int curTime)
{
  idAnimator_JointMod::ClearJointMods(this);
}


// ========================================================================
// ?SetJointMod@idAnimator_JointMod@@QAAXV?$idIndex@FW4invalidJointIndex_t@@@@ABVidMat3@@@Z
// EA  : 0x826E87F8
// RVA : 0x006E87F8
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

void __fastcall idAnimator_JointMod::SetJointMod(
        idAnimator_JointMod *this,
        idIndex<short,enum invalidJointIndex_t> *index,
        const idMat3 *value,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idIndex<short,enum invalidUserChannelIndex_t> a14)
{
  a14.value = (__int16)index;
  idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
    this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&this->jointIndex,
    obj: &a14);
  idList<idMat3,5>::Append(this: &this->jointValue, obj: value);
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_JointMod@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826E8850
// RVA : 0x006E8850
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

void __fastcall idAnimator_JointMod::InternalPreBlendTree(
        idAnimator_JointMod *this,
        const idAnimStack *stack,
        const int curTime,
        const int ticksPerSec)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int v8; // r27
  int v9; // r28
  int v10; // r29
  idPLog *pLog; // r29
  idPLog::logEntry_t *v12; // r30
  int v13; // r3
  __int64 totalTicks; // r11
  __int64 v15; // r9
  idPLogScope v16; // [sp+58h] [-48h] BYREF

  RD_EventBegin(name: "idAnimator_JointMod::InternalPreBlendTree");
  LODWORD(v6) = "idAnimator_JointMod::InternalPreBlendTree";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v16, pl: &::pLog, gMask: v6, label: v7);
  if ( this->enabled && stack != nullptr && this->treeAnimator != nullptr && this->jointIndex.num > 0 )
  {
    v8 = 0;
    v9 = 0;
    v10 = 0;
    do
    {
      idTreeAnimator::SetJointAxis(
        this: this->treeAnimator,
        pose: this->poseToModify,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointIndex.list[v9].value,
        type: JOINTMOD_MODEL_OVERRIDE,
        axis: &this->jointValue.list[v10]);
      ++v8;
      ++v10;
      ++v9;
    }
    while ( v8 < this->jointIndex.num );
  }
  if ( v16.logIndex >= 0 )
  {
    pLog = v16.pLog;
    v12 = &v16.pLog->logEntries.list[v16.logIndex];
    v13 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v12->totalTicks;
    HIDWORD(totalTicks) = v12->parent;
    LODWORD(v15) = v13 - totalTicks;
    v12->totalTicks = v15;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$247425
// EA  : 0x826E8948
// RVA : 0x006E8948
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

void _unwind_247425()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$247426
// EA  : 0x826E8970
// RVA : 0x006E8970
// PDB : w:\tech5\engine\gamelib\animstack\animator_jointmod.cpp
// ========================================================================

void _unwind_247426()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}

